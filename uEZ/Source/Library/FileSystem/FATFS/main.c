/*----------------------------------------------------------------------*/
/* FAT file system sample project for FatFs R0.06  (C)ChaN, 2008        */
/*----------------------------------------------------------------------*/


#include <string.h>
#include "LPC24xx.h"
#include "integer.h"
#include "interrupt.h"
#include "comm.h"
#include "monitor.h"
#include "rtc.h"
#include "diskio.h"
#include "ff.h"

#include "ctl_api.h"

#include "usbhost_lpc2468.h"

DWORD acc_size;				/* Work register for fs command */
WORD acc_files, acc_dirs;
FILINFO finfo;

char linebuf[120];			/* Console input buffer */

FATFS fatfs[_DRIVES];		/* File system object for each logical drive */
FIL file1, file2;			/* File objects */
DIR dir;					/* Directory object */
BYTE Buff[16384] __attribute__ ((aligned (4))) ;		/* Working buffer */

volatile UINT Timer;		/* Performance timer (1kHz increment) */



/*---------------------------------------------------------*/
/* 1000Hz timer interrupt generated by TIMER0              */
/*---------------------------------------------------------*/

void Isr_TIMER0 (void)
{
	T0IR = 1;			/* Clear irq flag */

	Timer++;
   MMC_TimerProc();
}



/*---------------------------------------------------------*/
/* User Provided Timer Function for FatFs module           */
/*---------------------------------------------------------*/
/* This is a real time clock service to be called from     */
/* FatFs module. Any valid time must be returned even if   */
/* the system does not support a real time clock.          */
/* This is not required in read-only configuration.        */


DWORD get_fattime ()
{
	RTC rtc;

	rtc_gettime(&rtc);

	return	        ((DWORD)(rtc.year) << 25)
			| ((DWORD)rtc.month << 21)
			| ((DWORD)rtc.mday << 16)
			| ((DWORD)rtc.hour << 11)
			| ((DWORD)rtc.min << 5)
			| ((DWORD)rtc.sec >> 1);
}


/*--------------------------------------------------------------------------*/
/* Monitor                                                                  */
/*--------------------------------------------------------------------------*/

static
FRESULT scan_files (char* path)
{
	DIR dirs;
	FRESULT res;
	BYTE i;


	if ((res = f_opendir(&dirs, path)) == FR_OK) {
		i = strlen(path);
		while (((res = f_readdir(&dirs, &finfo)) == FR_OK) && finfo.fname[0]) {
			if (finfo.fattrib & AM_DIR) {
				acc_dirs++;
				*(path+i) = '/'; strcpy(path+i+1, &finfo.fname[0]);
				res = scan_files(path);
				*(path+i) = '\0';
				if (res != FR_OK) break;
			} else {
				acc_files++;
				acc_size += finfo.fsize;
			}
		}
	}

	return res;
}



static
void put_rc (FRESULT rc)
{
	const char *p;
	static const char str[] =
		"OK\0" "NOT_READY\0" "NO_FILE\0" "FR_NO_PATH\0" "INVALID_NAME\0" "INVALID_DRIVE\0"
		"DENIED\0" "EXIST\0" "RW_ERROR\0" "WRITE_PROTECTED\0" "NOT_ENABLED\0"
		"NO_FILESYSTEM\0" "INVALID_OBJECT\0" "MKFS_ABORTED\0";
	FRESULT i;

	for (p = str, i = 0; i != rc && *p; i++) {
		while(*p++);
	}
	xprintf("rc=%u FR_%s\n", (UINT)rc, p);
}



static
void IoInit (void)
{
#define PLL_N		1UL
#define PLL_M		12UL
#define CCLK_DIV	4   // 288MHz / 4 = 72MHz
#define USBCLK_DIV      6   // 288MHz / 6 = 48MHz

	if ( PLLSTAT & (1 << 25) ) {
		PLLCON = 1;				/* Disconnect PLL output if PLL is in use */
		PLLFEED = 0xAA; PLLFEED = 0x55;
	}
	PLLCON = 0;				/* Disable PLL */
	PLLFEED = 0xAA; PLLFEED = 0x55;
	CLKSRCSEL = 0;			/* Select IRC (4MHz) as the PLL clock source */

   SCS |= 0x20;			/* Enable main OSC */
   while( !(SCS & 0x40) );	/* Wait until main OSC is usable */
   CLKSRCSEL = 0x1;		/* select main OSC, 12MHz, as the PLL clock source */

	PLLCFG = ((PLL_N - 1) << 16) | (PLL_M - 1);	/* Re-configure PLL */
	PLLFEED = 0xAA; PLLFEED = 0x55;
	PLLCON = 1;				/* Enable PLL */
	PLLFEED = 0xAA; PLLFEED = 0x55;

	while ((PLLSTAT & (1 << 26)) == 0);	/* Wait for PLL locked */

	CCLKCFG = CCLK_DIV-1;	/* Select CCLK frequency (divide ratio of hclk) */
   USBCLKCFG = USBCLK_DIV-1;		/* usbclk = 288 MHz/6 = 48 MHz */
   PLLCON = 3;				/* Connect PLL output to the sysclk */
	PLLFEED = 0xAA; PLLFEED = 0x55;

	MAMCR = 0;				/* Configure MAM for 72MHz operation */
	MAMTIM = 3;
	MAMCR = 2;

	PCLKSEL0 = 0x00000000;	/* Initialize peripheral clock to default */
	PCLKSEL1 = 0x00000000;

//	ClearVector();			/* Initialie VIC */

	SCS |= 1;				/* Enable FIO0 and FIO1 */

   FIO1DIR = (1<<26);                      /* Disable Piezo */
	FIO2CLR = (1<<26);

	FIO2DIR = (1<<30);                      /* Heartbeat LED output */
	FIO2CLR = (1<<30);

	/* Initialize Timer0 as 1kHz interval timer */
//	RegisterVector(TIMER0_INT, Isr_TIMER0, PRI_LOWEST, CLASS_IRQ);
   ctl_set_isr(TIMER0_INT, PRI_LOWEST, CTL_ISR_TRIGGER_FIXED, Isr_TIMER0, 0);
   ctl_unmask_isr(TIMER0_INT);

   T0CTCR = 0;
	T0MR0 = 18000 - 1;		/* 18M / 1k = 18000 */
	T0MCR = 0x3;			/* Clear TC and Interrupt on MR0 match */
	T0TCR = 1;

	uart0_init();			/* Initialize UART0 */

//	IrqEnable();			/* Enable Irq */
   ctl_global_interrupts_enable();
}



int main (void)
{
	char *ptr, *ptr2;
	long p1, p2, p3;
	BYTE res, b1;
	WORD w1;
	UINT s1, s2, cnt, blen = sizeof(Buff);
	DWORD ofs = 0, sect = 0;
	FATFS *fs;				/* Pointer to file system object */
	RTC rtc;

   BYTE ActiveDisk = 0;

   USB_INT32S  rc;

	IoInit();
   Host_Init();

	xputs("\nFatFs module test monitor for LPC2468\n");
   xputc('>');
   ptr = linebuf;

	for (;;) {
      if (ConnectedDeviceState == DEVICE_CONNECTED) {
         ConnectedDeviceState = DEVICE_CLEAR;
         xprintf("USB Mass Storage device detected\n");
         rc = Host_EnumDev();       // Enumerate the device connected

         if (rc == OK) {
            xprintf("USB device enumerated\n");
         }
         xputc('>');
      }
      else if (ConnectedDeviceState == DEVICE_DISCONNECTED) {
         ConnectedDeviceState = DEVICE_CLEAR;
         Host_Init();         // FreeDevice();
         xprintf("Device Disconnected\n");
         xputc('>');
      }

		if (get_line(ptr, sizeof(linebuf)) == '\r') {
         switch (*ptr++) {

         case 'm' :
            switch (*ptr++) {
            case 'd' :	/* md <address> [<count>] - Dump memory */
               if (!xatoi(&ptr, &p1)) break;
               if (!xatoi(&ptr, &p2)) p2 = 128;
               for (ptr=(char*)p1; p2 >= 16; ptr += 16, p2 -= 16) {
                  put_dump((BYTE*)ptr, (UINT)ptr, 16);
               }
               if (p2) put_dump((BYTE*)ptr, (UINT)ptr, p2);
               break;
            }
            break;

         case 'd' :
            switch (*ptr++) {
            case 'a' :  /* da [#] - select active disk */
               if (xatoi(&ptr, &p1)) {
                  ActiveDisk = (BYTE)p1;
               }
               ActiveDisk = VerifyActiveDisk(ActiveDisk);
               break;

            case 'd' :	/* dd [<lba>] - Dump secrtor */
               if (!xatoi(&ptr, &p2)) p2 = sect;
               res = disk_read(ActiveDisk, Buff, p2, 1);
//               res = disk_read(ActiveDisk, gUsbXferBuffer, p2, 1);
               if (res) { xprintf("rc=%d\n", (WORD)res); break; }
               sect = p2 + 1;
               xprintf("Sector:%lu\n", p2);
               for (ptr=(char*)Buff, ofs = 0; ofs < 0x200; ptr+=16, ofs+=16) {
//               for (ptr=(char*)gUsbXferBuffer, ofs = 0; ofs < 0x200; ptr+=16, ofs+=16) {
                  put_dump((BYTE*)ptr, ofs, 16);
               }
               break;

            case 'i' :	/* di - Initialize disk */
               xprintf("rc=%d\n", (WORD)disk_initialize(ActiveDisk));
               break;

            case 's' :	/* ds <phy_drv#> - Show disk status */
//            	if (!xatoi(&ptr, &p1)) break;
               if (disk_ioctl(ActiveDisk, GET_SECTOR_COUNT, &p2) == RES_OK)
                  { xprintf("Drive size: %lu sectors\n", p2); }
               if (disk_ioctl(ActiveDisk, GET_SECTOR_SIZE, &w1) == RES_OK)
                  { xprintf("Sector size: %u\n", w1); }
               if (disk_ioctl(ActiveDisk, GET_BLOCK_SIZE, &p2) == RES_OK)
                  { xprintf("Erase block size: %lu sectors\n", p2); }
               if (disk_ioctl(ActiveDisk, MMC_GET_TYPE, &b1) == RES_OK)
                  { xprintf("MMC/SDC type: %u\n", b1); }
               if (disk_ioctl(ActiveDisk, MMC_GET_CSD, Buff) == RES_OK)
                  { xputs("CSD:\n"); put_dump(Buff, 0, 16); }
               if (disk_ioctl(ActiveDisk, MMC_GET_CID, Buff) == RES_OK)
                  { xputs("CID:\n"); put_dump(Buff, 0, 16); }
               if (disk_ioctl(ActiveDisk, MMC_GET_OCR, Buff) == RES_OK)
                  { xputs("OCR:\n"); put_dump(Buff, 0, 4); }
               if (disk_ioctl(ActiveDisk, MMC_GET_SDSTAT, Buff) == RES_OK) {
                  xputs("SD Status:\n");
                  for (s1 = 0; s1 < 64; s1 += 16) put_dump(Buff+s1, s1, 16);
               }
               break;
            }
            break;

         case 'b' :
            switch (*ptr++) {
            case 'd' :	/* bd <addr> - Dump R/W buffer */
               if (!xatoi(&ptr, &p1)) break;
               for (ptr=(char*)&Buff[p1], ofs = p1, cnt = 32; cnt; cnt--, ptr+=16, ofs+=16) {
                  put_dump((BYTE*)ptr, ofs, 16);
               }
               break;

            case 'e' :	/* be <addr> [<data>] ... - Edit R/W buffer */
               if (!xatoi(&ptr, &p1)) break;
               if (xatoi(&ptr, &p2)) {
                  do {
                     Buff[p1++] = (BYTE)p2;
                  } while (xatoi(&ptr, &p2));
                  break;
               }
               for (;;) {
                  xprintf("%04X %02X-", (WORD)(p1), (WORD)Buff[p1]);
                  get_line(linebuf, sizeof(linebuf));
                  ptr = linebuf;
                  if (*ptr == '.') break;
                  if (*ptr < ' ') { p1++; continue; }
                  if (xatoi(&ptr, &p2))
                     Buff[p1++] = (BYTE)p2;
                  else
                     xputs("???\n");
               }
               break;

            case 'r' :	/* br <lba> [<num>] - Read disk into R/W buffer */
               if (!xatoi(&ptr, &p2)) break;
               if (!xatoi(&ptr, &p3)) p3 = 1;
               xprintf("rc=%u\n", (WORD)disk_read(ActiveDisk, Buff, p2, p3));
               break;

            case 'w' :	/* bw <lba> [<num>] - Write R/W buffer into disk */
               if (!xatoi(&ptr, &p2)) break;
               if (!xatoi(&ptr, &p3)) p3 = 1;
               xprintf("rc=%u\n", (WORD)disk_write(ActiveDisk, Buff, p2, p3));
               break;

            case 'f' :	/* bf <val> - Fill working buffer */
               if (!xatoi(&ptr, &p1)) break;
               memset(Buff, (BYTE)p1, sizeof(Buff));
               break;
            }
            break;

         case 'f' :
            switch (*ptr++) {

            case 'i' :	/* fi <log drv#> - Initialize logical drive */
               if (!xatoi(&ptr, &p1)) break;
               put_rc(f_mount((BYTE)p1, &fatfs[p1]));
//               put_rc(f_mount(ActiveDisk, &fatfs[ActiveDisk]));
               break;

            case 's' :	/* fs [<path>] - Show logical drive status */
               res = f_getfree(ptr, (DWORD*)&p2, &fs);
               if (res) { put_rc(res); break; }
               xprintf("FAT type = %u\nBytes/Cluster = %lu\nNumber of FATs = %u\n"
                  "Root DIR entries = %u\nSectors/FAT = %lu\nNumber of clusters = %lu\n"
                  "FAT start (lba) = %lu\nDIR start (lba,cluster) = %lu\nData start (lba) = %lu\n\n",
						(WORD)fs->fs_type, (DWORD)fs->csize * 512, (WORD)fs->n_fats,
						fs->n_rootdir, fs->sects_fat, (DWORD)fs->max_clust - 2,
						fs->fatbase, fs->dirbase, fs->database
               );
               acc_size = acc_files = acc_dirs = 0;
               res = scan_files(ptr);
               if (res) { put_rc(res); break; }
               xprintf("%u files, %lu bytes.\n%u folders.\n"
						"%lu KB total disk space.\n%lu KB available.\n",
						acc_files, acc_size, acc_dirs,
						(fs->max_clust - 2) * (fs->csize / 2), p2 * (fs->csize / 2)
               );
               break;

            case 'l' :	/* fl [<path>] - Directory listing */
               res = f_opendir(&dir, ptr);
               if (res) { put_rc(res); break; }
               p1 = s1 = s2 = 0;
               for(;;) {
                  res = f_readdir(&dir, &finfo);
                  if ((res != FR_OK) || !finfo.fname[0]) break;
                  if (finfo.fattrib & AM_DIR) {
                     s2++;
                  } else {
                     s1++; p1 += finfo.fsize;
                  }
                  xprintf("%c%c%c%c%c %u/%02u/%02u %02u:%02u %9lu  %s\n",
							(finfo.fattrib & AM_DIR) ? 'D' : '-',
							(finfo.fattrib & AM_RDO) ? 'R' : '-',
							(finfo.fattrib & AM_HID) ? 'H' : '-',
							(finfo.fattrib & AM_SYS) ? 'S' : '-',
							(finfo.fattrib & AM_ARC) ? 'A' : '-',
                     (finfo.fdate >> 9) + 1980, (finfo.fdate >> 5) & 15, finfo.fdate & 31,
							(finfo.ftime >> 11), (finfo.ftime >> 5) & 63,
							finfo.fsize, &(finfo.fname[0]));
               }
               xprintf("%4u File(s),%10lu bytes total\n%4u Dir(s)", s1, p1, s2);
               if (f_getfree(ptr, (DWORD*)&p1, &fs) == FR_OK)
                  xprintf(", %10lu bytes free\n", p1 * fs->csize * 512);
               break;

            case 'o' :	/* fo <mode> <file> - Open a file */
               if (!xatoi(&ptr, &p1)) break;
               put_rc(f_open(&file1, ptr, (BYTE)p1));
               break;

            case 'c' :	/* fc - Close a file */
               put_rc(f_close(&file1));
               break;

            case 'e' :	/* fe - Seek file pointer */
               if (!xatoi(&ptr, &p1)) break;
               res = f_lseek(&file1, p1);
               put_rc(res);
               if (res == FR_OK)
                  xprintf("fptr=%lu(0x%lX)\n", file1.fptr, file1.fptr);
               break;

            case 'd' :	/* fd <len> - read and dump file from current fp */
               if (!xatoi(&ptr, &p1)) break;
               ofs = file1.fptr;
               while (p1) {
                  if ((UINT)p1 >= 16) { cnt = 16; p1 -= 16; }
                  else 				{ cnt = p1; p1 = 0; }
                  res = f_read(&file1, Buff, cnt, &cnt);
                  if (res != FR_OK) { put_rc(res); break; }
                  if (!cnt) break;
                  put_dump(Buff, ofs, cnt);
                  ofs += 16;
               }
               break;

            case 'r' :	/* fr <len> - read file */
               if (!xatoi(&ptr, &p1)) break;
               p2 = 0;
               Timer = 0;
               while (p1) {
                  if ((UINT)p1 >= blen) {
                     cnt = blen; p1 -= blen;
                  } else {
                     cnt = p1; p1 = 0;
                  }
                  res = f_read(&file1, Buff, cnt, &s2);
                  if (res != FR_OK) { put_rc(res); break; }
                  p2 += s2;
                  if (cnt != s2) break;
               }
               xprintf("%lu bytes read with %lu kB/sec.\n", p2, p2 / Timer);
               break;

            case 'w' :	/* fw <len> <val> - write file */
               if (!xatoi(&ptr, &p1) || !xatoi(&ptr, &p2)) break;
               memset(Buff, (BYTE)p2, blen);
               p2 = 0;
               Timer = 0;
               while (p1) {
                  if ((UINT)p1 >= blen) {
                     cnt = blen; p1 -= blen;
                  } else {
                     cnt = p1; p1 = 0;
                  }
                  res = f_write(&file1, Buff, cnt, &s2);
                  if (res != FR_OK) { put_rc(res); break; }
                  p2 += s2;
                  if (cnt != s2) break;
               }
               xprintf("%lu bytes written with %lu kB/sec.\n", p2, p2 / Timer);
               break;

            case 'n' :	/* fn <old_name> <new_name> - Change file/dir name */
               while (*ptr == ' ') ptr++;
               ptr2 = strchr(ptr, ' ');
               if (!ptr2) break;
               *ptr2++ = 0;
               while (*ptr2 == ' ') ptr2++;
               put_rc(f_rename(ptr, ptr2));
               break;

            case 'u' :	/* fu <name> - Unlink a file or dir */
               put_rc(f_unlink(ptr));
               break;

            case 'v' :	/* fv - Truncate file */
               put_rc(f_truncate(&file1));
               break;

            case 'k' :	/* fk <name> - Create a directory */
               put_rc(f_mkdir(ptr));
               break;

            case 'a' :	/* fa <atrr> <mask> <name> - Change file/dir attribute */
               if (!xatoi(&ptr, &p1) || !xatoi(&ptr, &p2)) break;
               put_rc(f_chmod(ptr, p1, p2));
               break;

            case 't' :	/* ft <year> <month> <day> <hour> <min> <sec> <name> - Change timestamp */
               if (!xatoi(&ptr, &p1) || !xatoi(&ptr, &p2) || !xatoi(&ptr, &p3)) break;
               finfo.fdate = ((p1 - 1980) << 9) | ((p2 & 15) << 5) | (p3 & 31);
               if (!xatoi(&ptr, &p1) || !xatoi(&ptr, &p2) || !xatoi(&ptr, &p3)) break;
               finfo.ftime = ((p1 & 31) << 11) | ((p1 & 63) << 5) | ((p1 >> 1) & 31);
               put_rc(f_utime(ptr, &finfo));
               break;

            case 'x' : /* fx <src_name> <dst_name> - Copy file */
               while (*ptr == ' ') ptr++;
               ptr2 = strchr(ptr, ' ');
               if (!ptr2) break;
               *ptr2++ = 0;
               while (*ptr2 == ' ') ptr2++;
               xprintf("Opening \"%s\"", ptr);
               res = f_open(&file1, ptr, FA_OPEN_EXISTING | FA_READ);
               xputc('\n');
               if (res) {
                  put_rc(res);
                  break;
               }
               xprintf("Creating \"%s\"", ptr2);
               res = f_open(&file2, ptr2, FA_CREATE_ALWAYS | FA_WRITE);
               xputc('\n');
               if (res) {
                  put_rc(res);
                  f_close(&file1);
                  break;
               }
               xprintf("Copying file...");
               Timer = 0;
               p1 = 0;
               for (;;) {
                  res = f_read(&file1, Buff, blen, &s1);
                  if (res || s1 == 0) break;   /* error or eof */
                  res = f_write(&file2, Buff, s1, &s2);
                  p1 += s2;
                  if (res || s2 < s1) break;   /* error or disk full */
               }
               xprintf("%lu bytes copied with %lu kB/sec.\n", p1, p1 / Timer);
               f_close(&file1);
               f_close(&file2);
               break;
#if _USE_MKFS
            case 'm' :	/* fm <partition rule> <cluster size> - Create file system */
               if (!xatoi(&ptr, &p2) || !xatoi(&ptr, &p3)) break;
               xprintf("The drive %u will be formatted. Are you sure? (Y/n)=", ActiveDisk);
               get_line(ptr, sizeof(linebuf));
               if (*ptr == 'Y')
                  put_rc(f_mkfs(ActiveDisk, (BYTE)p2, (WORD)p3));
               break;
#endif
            case 'z' :	/* fz [<rw size>] - Change R/W length for fr/fw/fx command */
               if (xatoi(&ptr, &p1) && p1 >= 1 && p1 <= sizeof(Buff))
                  blen = p1;
               xprintf("blen=%u\n", blen);
               break;
            }
            break;

         case 't' :	/* t [<year> <mon> <mday> <hour> <min> <sec>] */
            if (xatoi(&ptr, &p1)) {
               rtc.year = (WORD)p1;
               xatoi(&ptr, &p1); rtc.month = (BYTE)p1;
               xatoi(&ptr, &p1); rtc.mday = (BYTE)p1;
               xatoi(&ptr, &p1); rtc.hour = (BYTE)p1;
               xatoi(&ptr, &p1); rtc.min = (BYTE)p1;
               if (!xatoi(&ptr, &p1)) break;
               rtc.sec = (BYTE)p1;
               rtc_settime(&rtc);
            }
            rtc_gettime(&rtc);
            xprintf("%u/%u/%u %02u:%02u:%02u\n", rtc.year, rtc.month, rtc.mday, rtc.hour, rtc.min, rtc.sec);
            break;

         case 'u' : /* usb test commands */
            switch (*ptr++) {

            case 's' :	/* print bulk size */
            xprintf("MS Bulk size %lu\n", MS_BlkSize);
            break;
            }
         break;
         }
         xputc('>');
         ptr = linebuf;
      }
   }
}

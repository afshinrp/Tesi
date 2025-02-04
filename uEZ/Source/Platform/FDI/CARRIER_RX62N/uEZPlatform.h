/*-------------------------------------------------------------------------*
 * File:  uEZPlatform.h
 *-------------------------------------------------------------------------*
 * Description:
 *     Contains definitions for the CARRIER_RX62N platform.
 *-------------------------------------------------------------------------*/
#ifndef UEZPLATFORM_H_
#define UEZPLATFORM_H_

/*--------------------------------------------------------------------------
 * uEZ(R) - Copyright (C) 2007-2012 Future Designs, Inc.
 *--------------------------------------------------------------------------
 * This file is part of the uEZ(R) distribution.  See the included
 * uEZLicense.txt or visit http://www.teamfdi.com/uez for details.
 *
 *    *===============================================================*
 *    |  Future Designs, Inc. can port uEZ(tm) to your own hardware!  |
 *    |             We can get you up and running fast!               |
 *    |      See http://www.teamfdi.com/uez for more details.         |
 *    *===============================================================*
 *
 *-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*
 * Platform Settings:
 *-------------------------------------------------------------------------*/
#define UEZ_PROCESSOR               RENESAS_RX62N
#define RX62N_PACKAGE               RX62N_PACKAGE_BGA176

#define configKERNEL_INTERRUPT_PRIORITY		4

#ifndef UEZ_NUM_HANDLES
#define UEZ_NUM_HANDLES           150 // more than the average number of handles
#endif

#ifndef PROCESSOR_OSCILLATOR_FREQUENCY
#define PROCESSOR_OSCILLATOR_FREQUENCY      96000000   // clocks per second (when using LCD, must be slower)
#endif

#ifndef SDRAM_CLOCK_FREQUENCY
    #define SDRAM_CLOCK_FREQUENCY               (PROCESSOR_OSCILLATOR_FREQUENCY/2)
#endif

#ifndef EMC_CLOCK_FREQUENCY
    #define EMC_CLOCK_FREQUENCY                 (PROCESSOR_OSCILLATOR_FREQUENCY/2)
#endif

#define UEZBSP_SDRAM                        1
#define UEZBSP_SDRAM_SIZE                   (16*1024*1024)
#define UEZBSP_SDRAM_BASE_ADDR              0x08000000

#ifndef UEZ_DEFAULT_AUDIO_LEVEL
    #define UEZ_DEFAULT_AUDIO_LEVEL  255
#endif

#ifndef UEZ_CONSOLE_READ_BUFFER_SIZE
    #define UEZ_CONSOLE_READ_BUFFER_SIZE        128 // bytes
#endif
#ifndef UEZ_CONSOLE_WRITE_BUFFER_SIZE
    #define UEZ_CONSOLE_WRITE_BUFFER_SIZE       128 // bytes
#endif

#ifndef LCD_DISPLAY_BASE_ADDRESS
    #define LCD_DISPLAY_BASE_ADDRESS            0x08000000
#endif

#ifndef FATFS_MAX_MASS_STORAGE_DEVICES
    #define FATFS_MAX_MASS_STORAGE_DEVICES      2
#endif

#define UEZBSP_NOR_FLASH                    UEZ_ENABLE_FLASH
#define UEZBSP_NOR_FLASH_BASE_ADDRESS       0x80000000

//#include "lwipopts.h"

#if (COMPILER_TYPE==IAR)
    #define NOP() __no_operation()
#endif

#define SDRAM_NUM_ROWS      4096
#define SDRAM_REFRESH_TIME  64  // ms

//#define configKERNEL_INTERRUPT_PRIORITY     4

/*-------------------------------------------------------------------------*
 * Types:
 *-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*
 * Prototypes:
 *-------------------------------------------------------------------------*/
TBool UEZGUIIsExpansionBoardConnected(void);
TBool UEZGUIIsLoopbackBoardConnected(void);

void UEZPlatform_LCD_Require(void);
void UEZPlatform_Console_Require(
        TUInt32 aWriteBufferSize,
        TUInt32 aReadBufferSize);
void UEZPlatform_Touchscreen_Require(void);
void UEZPlatform_DataFlash_Require(void);
void UEZPlatform_Speaker_Require(void);
void UEZPlatform_AudioAmp_Require(void);
void UEZPlatform_AudioCodec_Require(void);
void UEZPlatform_SDCard_Drive_Require(TUInt8 aDriveNum);
void UEZPlatform_WiredNetwork0_Require(void);

void UEZPlatform_Accel0_Require(void);
void UEZPlatform_Temp0_Require(void);
void UEZPlatform_RTC_Require(void);

void UEZPlatform_Require(void);
void UEZPlatform_Standard_Require(void);
void UEZPlatform_Full_Require(void);
void UEZPlatform_Minimal_Require(void);

#endif // UEZPLATFORM_SETTINGS_H_
/*-------------------------------------------------------------------------*
 * End of File:  uEZPlatform_Settings.h
 *-------------------------------------------------------------------------*/

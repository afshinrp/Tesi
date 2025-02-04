/*
 *
 * 	Discrete Input		Single bit		Read-Only
	Coils				Single bit		Read-Write
	Input Registers		16-bit word		Read-Only
	Holding Registers	16-bit word		Read-Write
 *
 *
 */


/*
 * The Discrete Inputs represent a single bit (Boolean) which can only be read.
 * In other words, the master can only perform a read action on the discrete inputs.
 * The same holds for the Input Registers.
 * The master can only read the slave’s Input Registers.
 * The difference between the Discrete Inputs and the Input Registers is
 * that the Input Registers represent 16 bits while the Discrete Inputs are only a single bit.
 * The Coils also represent a Boolean data type which can be read and written to by the master.
 * The Holding Registers represent a 16 bit word that can be read and written to.

 *
 */

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "lcd_horizontal.h"
#include "lpc1768.h"



/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbport.h"



extern USHORT   usRegHoldingStart;
extern USHORT   *usRegHoldingBuf[REG_HOLDING_NREGS];

extern USHORT 	usRegCoilStart;
extern UCHAR 	ucRegCoilBuf[REG_COIL_LOCATIONS];


/* ----------------------- Start implementation -----------------------------*/


#define bit_test(var,pos)       ((var) & (1<<(pos)))
#define bit_set(coil,pos)       (coil |= 1 << pos)
#define bit_clear(coil, pos)    (coil &= ~(1 << pos))
#define swap_bits(c)            ((c&1)?128:0)|((c&2)?64:0)|((c&4)?32:0)|((c&8)?16:0 )|((c&16)?8:0)|((c&32)?4:0)|((c&64)?2:0)|((c&128)?1:0)


extern xSemaphoreHandle xSemaphore;

void ModbusTask(void *pvParameters){

//	while(1)
	{
		// See if we can obtain the semaphore.  If the semaphore is not available
		// wait 50 ticks to see if it becomes free.
	//	if( xSemaphoreTake( xSemaphore,  50 ) == pdTRUE )
		{
			( void )eMBPoll(  );

		//	xSemaphoreGive( xSemaphore );
		}
	}

}


eMBErrorCode
eMBRegInputCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs )
{

	return MB_ENOREG;
}

eMBErrorCode
eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, eMBRegisterMode eMode )
{
	{
		eMBErrorCode    eStatus = MB_ENOERR;
		int             iRegIndex;

		if( ( usAddress >= REG_HOLDING_START ) &&
				( usAddress + usNRegs <= REG_HOLDING_START + REG_HOLDING_NREGS ) )
		{
			iRegIndex = ( int )( usAddress - usRegHoldingStart );
			switch ( eMode )
			{
			/* Pass current register values to the protocol stack. */
			case MB_REG_READ:
				while( usNRegs > 0 )
				{
					*pucRegBuffer++ = ( unsigned char )( **(usRegHoldingBuf +iRegIndex) >> 8 );
					*pucRegBuffer++ = ( unsigned char )(**(usRegHoldingBuf +iRegIndex) & 0xFF );
					iRegIndex++;
					usNRegs--;
				}
				break;

				/* Update current register values with new values from the
				 * protocol stack. */
			case MB_REG_WRITE:
				while( usNRegs > 0 )
				{
					 **(usRegHoldingBuf +iRegIndex) = *pucRegBuffer++ << 8;
					 **(usRegHoldingBuf +iRegIndex) |= *pucRegBuffer++;
					iRegIndex++;
					usNRegs--;
				}
			}
		}
		else
		{
			eStatus = MB_ENOREG;
		}
		return eStatus;
	}

	//	return MB_ENOREG;
}


eMBErrorCode
eMBRegCoilsCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils, eMBRegisterMode eMode )
{
	eMBErrorCode eStatus = MB_ENOERR;
	int iNCoils = (int) usNCoils;
	USHORT usBitOffset;

	usAddress--;

	// Check if we have registers mapped at this block
	if ((usAddress >= REG_COIL_START) && (usAddress + usNCoils <= REG_COIL_START
			+ REG_COILS_SIZE))
	{
		usBitOffset = (USHORT) (usAddress - REG_COIL_START);
		switch (eMode)
		{
		// Read current values and pass to protocol stack
		case MB_REG_READ:
			while (iNCoils > 0)
			{
				*pucRegBuffer++ = xMBUtilGetBits( ucRegCoilBuf, usBitOffset,
						( unsigned char )( iNCoils > 8 ? 8 : iNCoils ) );
				iNCoils -= 8;
				usBitOffset += 8;
			}
			break;

			// Update current register values
		case MB_REG_WRITE:
			while (iNCoils > 0)
			{
				xMBUtilSetBits( ucRegCoilBuf, usBitOffset,
						( unsigned char )( iNCoils > 8 ? 8 : iNCoils ),
						*pucRegBuffer++ );
				iNCoils -= 8;
				usBitOffset += 8;
			}
			break;
		}
	}
	else
	{
		eStatus = MB_ENOREG;
	}

	return eStatus;}

eMBErrorCode
eMBRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete )
{
	( void )pucRegBuffer;
	( void )usAddress;
	( void )usNDiscrete;
	return MB_ENOREG;
}

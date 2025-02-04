/*-------------------------------------------------------------------------*
 * File:  GPIO.h
 *-------------------------------------------------------------------------*
 * Description:
 *     
 *-------------------------------------------------------------------------*/
#ifndef GPIO_H_
#define GPIO_H_

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
/**
 *  @file   /Include/Types/GPIO.h
 *  @brief  uEZ GPIO Types
 *
 *  The uEZ GPIO Types
 *
 *  Example:
 *  @code
 *      TODO: Write code here
 *  @endcode
 */
/*-------------------------------------------------------------------------*
 * Includes:
 *-------------------------------------------------------------------------*/
#include <uEZTypes.h>

/*-------------------------------------------------------------------------*
 * Types:
 *-------------------------------------------------------------------------*/
typedef TUInt8 T_uezGPIOPort;
#define UEZ_GPIO_PORT_0         0
#define UEZ_GPIO_PORT_1         1
#define UEZ_GPIO_PORT_2         2
#define UEZ_GPIO_PORT_3         3
#define UEZ_GPIO_PORT_4         4
#define UEZ_GPIO_PORT_5         5
#define UEZ_GPIO_PORT_6         6
#define UEZ_GPIO_PORT_7         7
#define UEZ_GPIO_PORT_8         8
#define UEZ_GPIO_PORT_9         9
#define UEZ_GPIO_PORT_A         10
#define UEZ_GPIO_PORT_B         11
#define UEZ_GPIO_PORT_C         12
#define UEZ_GPIO_PORT_D         13
#define UEZ_GPIO_PORT_E         14
#define UEZ_GPIO_PORT_F         15
#define UEZ_GPIO_PORT_G         16
#define UEZ_GPIO_PORT_H         17
#define UEZ_GPIO_PORT_I         18
#define UEZ_GPIO_PORT_J         19
#define UEZ_GPIO_PORT_K         20
#define UEZ_GPIO_PORT_L         21
#define UEZ_GPIO_PORT_M         22
#define UEZ_GPIO_PORT_N         23
#define UEZ_GPIO_PORT_O         24
#define UEZ_GPIO_PORT_P         25
#define UEZ_GPIO_PORT_Q         26
#define UEZ_GPIO_PORT_R         27
#define UEZ_GPIO_PORT_S         28
#define UEZ_GPIO_PORT_T         29
#define UEZ_GPIO_PORT_U         30
#define UEZ_GPIO_PORT_V         31
#define UEZ_GPIO_PORT_W         32
#define UEZ_GPIO_PORT_X         33
#define UEZ_GPIO_PORT_Y         34
#define UEZ_GPIO_PORT_Z         35
#define UEZ_GPIO_PORT_EXT1      36
#define UEZ_GPIO_PORT_EXT2      37
#define UEZ_GPIO_PORT_EXT3      38
#define UEZ_GPIO_PORT_EXT4      39

typedef TUInt8 T_uezGPIOPin; /**< Pins on a port are 0-31 */
 
typedef TUInt16 T_uezGPIOPortPin; /**< A PortPin is a combination of the 
* T_uezGPIOPort (upper byte) and the T_uezGPIOPin (lower byte).  By making 
* this a simple 16-bit number, it makes it very easy to pass around. */

/*-------------------------------------------------------------------------*
 * Macros:
 *-------------------------------------------------------------------------*/
#define UEZ_GPIO_PORT_PIN(portNum, pinIndex) \
    ((T_uezGPIOPortPin)((portNum<<8) | (pinIndex)))
#define UEZ_GPIO_PORT_FROM_PORT_PIN(portpin) \
    ((T_uezGPIOPort)(portpin>>8))
#define UEZ_GPIO_PIN_FROM_PORT_PIN(portpin) \
    ((T_uezGPIOPin)(portpin & 0xFF))


#define UEZ_GPIO_PORT_NONE      0xFF /**< Special GPIO_NONE means no declared port */
#define GPIO_NONE               UEZ_GPIO_PORT_PIN(UEZ_GPIO_PORT_NONE, 0xFF)

#endif // GPIO_H_
/*-------------------------------------------------------------------------*
 * End of File:  GPIO.h
 *-------------------------------------------------------------------------*/

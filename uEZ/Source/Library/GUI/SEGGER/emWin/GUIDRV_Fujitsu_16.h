/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2012  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.14 - Graphical user interface for embedded applications **
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with a license and should not be re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : GUIDRV_Fujitsu_16.h
Purpose     : Interface definition for GUIDRV_FUJITSU_16 driver
---------------------------END-OF-HEADER------------------------------
*/

#ifndef GUIDRV_FUJITSU_16_H
#define GUIDRV_FUJITSU_16_H

/*********************************************************************
*
*       Display drivers
*/
//
// Addresses
//
extern const GUI_DEVICE_API GUIDRV_Win_API;

extern const GUI_DEVICE_API GUIDRV_Fujitsu_16_API;

//
// Macros to be used in configuration files
//
#if defined(WIN32) && !defined(LCD_SIMCONTROLLER)

  #define GUIDRV_FUJITSU_16    &GUIDRV_Win_API

#else

  #define GUIDRV_FUJITSU_16    &GUIDRV_Fujitsu_16_API

#endif

#endif /* GUIDRV_FUJITSU_16_H */

/*************************** End of file ****************************/

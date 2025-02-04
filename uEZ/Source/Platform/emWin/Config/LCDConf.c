/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2010  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.06 - Graphical user interface for embedded applications **
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with a license and should not be re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : LCDConf.c
Purpose     : Display controller configuration (single layer)
---------------------------END-OF-HEADER------------------------------
*/

#include <uEZProcessor.h>
#include "GUI.h"
#include "GUIDRV_Lin.h"
#include "uEZPlatform.h"
#include <string.h>
#include <Config_Build.h>
#include <uEZPlatformAPI.h>
#include <Source/Library/GUI/FDI/SimpleUI/SimpleUI.h>

/*********************************************************************
*
*       Configuration
*
**********************************************************************
*/

#ifndef   USE_MULTIBUF
  #define USE_MULTIBUF  1
#endif

/*********************************************************************
*
*       Layer configuration (to be modified)
*
**********************************************************************
*/

//
// Physical display size
//
#define XSIZE_PHYS UEZ_LCD_DISPLAY_WIDTH
#define YSIZE_PHYS UEZ_LCD_DISPLAY_HEIGHT

//
// Virtual display size
//
#if USE_MULTIBUF
  #define VXSIZE_PHYS (XSIZE_PHYS)
  #define VYSIZE_PHYS (YSIZE_PHYS * GUI_NUM_VIRTUAL_DISPLAYS)
#endif

//
// Color conversion
//
#if 0
#if ( UEZ_DEFAULT_LCD_CONFIG == LCD_CONFIG_TIANMA_TM043NBH02 || UEZ_DEFAULT_LCD_CONFIG == LCD_CONFIG_SEIKO_70WVW2T || UEZ_DEFAULT_LCD_CONFIG == LCD_CONFIG_OKAYA_VGA_LCDC_3_5|| UEZ_DEFAULT_LCD_CONFIG == LCD_CONFIG_OKAYA_QVGA_3x5_LCDC_3_5 || UEZ_DEFAULT_LCD_CONFIG == LCD_CONFIG_INTELTRONIC_LMIX0560NTN53V1 || UEZ_DEFAULT_LCD_CONFIG == LCD_CONFIG_HITACHI_TX11D06VM2APA || UEZ_DEFAULT_LCD_CONFIG == LCD_CONFIG_SEIKO_43WQW1T)
#define COLOR_CONVERSION  GUICC_M555
#else
#define COLOR_CONVERSION  GUICC_M565
#endif
#else
#define COLOR_CONVERSION  GUI_COLOR_CONVERSION
#endif

//
// Pixel width in bytes
//
#define PIXEL_WIDTH  GUI_PIXEL_WIDTH

//
// Display driver
//
#define DISPLAY_DRIVER  &GUIDRV_Lin_16_API

//
// Video RAM address
//
#define VRAM_ADDR  LCD_DISPLAY_BASE_ADDRESS

/*********************************************************************
*
*       Configuration checking
*
**********************************************************************
*/
#ifndef   VXSIZE_PHYS
  #define VXSIZE_PHYS XSIZE_PHYS
#endif
#ifndef   VYSIZE_PHYS
  #define VYSIZE_PHYS YSIZE_PHYS
#endif
#ifndef   VRAM_ADDR
  #define VRAM_ADDR 0
#endif

#ifndef   XSIZE_PHYS
  #error Physical X size of display is not defined!
#endif
#ifndef   YSIZE_PHYS
  #error Physical Y size of display is not defined!
#endif
#ifndef   COLOR_CONVERSION
  #error Color conversion not defined!
#endif
#ifndef   DISPLAY_DRIVER
  #error No display driver defined!
#endif

/*********************************************************************
*
*       Defines, sfrs and values
*
**********************************************************************
*/

//
// LCDC
//

#ifndef LCDC_BASE_ADDR
#define LCDC_BASE_ADDR  LCD_DISPLAY_BASE_ADDRESS
#endif
//#define LCDC_UPBASE     (*(volatile U32*)(LCDC_BASE_ADDR + 0x10))

/*********************************************************************
*
*       Local code
*
**********************************************************************
*/

/*********************************************************************
*
*       _SetDisplayOrigin()
*/
static void _SetDisplayOrigin(int x, int y) {
  (void)x;
  //
  // Set start address for display data and enable LCD controller
  //
//  LCDC_UPBASE = VRAM_ADDR + (y * XSIZE_PHYS * PIXEL_WIDTH);
  SUICallbackSetLCDBase((void *)(VRAM_ADDR + (y * XSIZE_PHYS * PIXEL_WIDTH)));
}

/*********************************************************************
*
*       _InitController
*
* Function description:
*   Initializes the LCD controller
*
*/
static void _InitController(unsigned LayerIndex) {
  //
  // Set display size and video-RAM address
  //
  LCD_SetSizeEx (XSIZE_PHYS, YSIZE_PHYS, LayerIndex);
  LCD_SetVSizeEx(VXSIZE_PHYS, VYSIZE_PHYS, LayerIndex);
  LCD_SetVRAMAddrEx(LayerIndex, (void*)VRAM_ADDR);
}

#if USE_MULTIBUF

/*********************************************************************
*
*       _CopyBuffer
*
* Function description:
*   Copies the framebuffer for multiple buffering
*
*/
static void _CopyBuffer(int LayerIndex, int IndexSrc, int IndexDst) {
  U32 BufferSize;
  U32 AddrSrc;
  U32 AddrDst;

  //
  // Calculate the size of one frame buffer
  //
  BufferSize = (XSIZE_PHYS * YSIZE_PHYS * PIXEL_WIDTH);
  //
  // Calculate source- and destination address
  //
  AddrSrc    = VRAM_ADDR + (BufferSize * IndexSrc);
  AddrDst    = VRAM_ADDR + (BufferSize * IndexDst);
  memcpy((void *)AddrDst, (void *)AddrSrc, BufferSize);
}

#endif

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/

/*********************************************************************
*
*       LCD_X_Config
*
* Purpose:
*   Called during the initialization process in order to set up the
*   display driver configuration.
*
*/
void LCD_X_Config(void) {
  #if USE_MULTIBUF
    //
    // Initialize multibuffering
    //
    GUI_MULTIBUF_Config(GUI_NUM_VIRTUAL_DISPLAYS);
  #endif
  //
  // Set display driver and color conversion for 1st layer
  //
  GUI_DEVICE_CreateAndLink(DISPLAY_DRIVER, (void *)COLOR_CONVERSION, 0, 0);
  #if USE_MULTIBUF
    //
    // Set custom callback function for copy operation
    //
    LCD_SetDevFunc(0, LCD_DEVFUNC_COPYBUFFER, (void (*)())_CopyBuffer);
  #endif
  //
  // Display driver configuration, required for Lin-driver
  //
  LCD_SetSizeEx    (0, XSIZE_PHYS,   YSIZE_PHYS);
  LCD_SetVSizeEx   (0, VXSIZE_PHYS,  VYSIZE_PHYS);
  LCD_SetVRAMAddrEx(0, (void*)VRAM_ADDR);
  //
  // Set user palette data (only required if no fixed palette is used)
  //
  #if defined(PALETTE)
    LCD_SetLUTEx(0, PALETTE);
  #endif
}

/*********************************************************************
*
*       LCD_X_DisplayDriver
*
* Purpose:
*   This function is called by the display driver for several purposes.
*   To support the according task the routine needs to be adapted to
*   the display controller. Please note that the commands marked with
*   'optional' are not cogently required and should only be adapted if
*   the display controller supports these features.
*
* Parameter:
*   LayerIndex - Index of layer to be configured
*   Cmd        - Please refer to the details in the switch statement below
*   pData      - Pointer to a LCD_X_DATA structure
*
* Return Value:
*   < -1 - Error
*     -1 - Command not handled
*      0 - Ok
*/
int LCD_X_DisplayDriver(unsigned LayerIndex, unsigned Cmd, void * pData) {
  int r;

  (void)LayerIndex;

  switch (Cmd) {
  //
  // Required
  //
  case LCD_X_INITCONTROLLER: {
    //
    // Called during the initialization process in order to set up the
    // display controller and put it into operation. If the display
    // controller is not initialized by any external routine this needs
    // to be adapted by the customer...
    //
    _InitController(0);
    return 0;
  }
  case LCD_X_SETORG: {
    //
    // Required for setting the display origin which is passed in the 'xPos' and 'yPos' element of p
    //
    LCD_X_SETORG_INFO * p;
    p = (LCD_X_SETORG_INFO *)pData;
    _SetDisplayOrigin(p->xPos, p->yPos);
    return 0;
  }
  case LCD_X_SHOWBUFFER: {
    LCD_X_SHOWBUFFER_INFO * p;
    U32 BufferSize;
    U32 Addr;

    p = (LCD_X_SHOWBUFFER_INFO *)pData;
    //
    // Calculate address of the given buffer
    //
    BufferSize = (XSIZE_PHYS * YSIZE_PHYS * PIXEL_WIDTH);
    Addr       = VRAM_ADDR + (BufferSize * p->Index);
    //
    // Make the given buffer visible
    //
//    LCDC_UPBASE = Addr;
      SUICallbackSetLCDBase((void *)Addr);

    //
    // Send a confirmation that the buffer is visible now
    //
    GUI_MULTIBUF_Confirm(p->Index);
    return 0;
  }
  default:
    r = -1;
  }
  return r;
}

/*************************** End of file ****************************/

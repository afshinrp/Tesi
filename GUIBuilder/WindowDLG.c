/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.20                          *
*        Compiled Mar 19 2013, 15:01:00                              *
*        (c) 2013 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0  (GUI_ID_USER + 0x00)
#define ID_ICONVIEW_0  (GUI_ID_USER + 0x02)

#define ID_ICONVIEW_0_IMAGE_0 0x00

// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
/*********************************************************************
*
*       _acImage_0, "Z:\home\enrico\TESI\GUIBuilder\debug_icon.dta", ID_ICONVIEW_0_IMAGE_0
*/
static U8 _acImage_0[5016] = {
  0x42, 0x4D, 0x0A, 0x00, 0x32, 0x00, 0x32, 0x00, 0x64, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xDE, 0x7B, 0xBD, 0x77, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73,
  0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73,
  0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0x9D, 0x73, 0xBD, 0x77, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xDE, 0x7B, 0x3A, 0x63, 0x98, 0x46,
  0x58, 0x36, 0x5B, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32,
  0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7C, 0x32, 0x7B, 0x32, 0x59, 0x32, 0x78, 0x3A, 0xD9, 0x52,
  0x7C, 0x6F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xDE, 0x7B, 0xD8, 0x52, 0x39, 0x2A, 0x3E, 0x22, 0x3F, 0x1E, 0x3F, 0x1E, 0x5F, 0x1E, 0x5F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E,
  0x3F, 0x1E, 0x3F, 0x1E, 0x5F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x5F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x5F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x5F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x5F, 0x1E, 0x5F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E,
  0x5F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x5F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3C, 0x22, 0x79, 0x3E, 0x5A, 0x6B, 0xFF, 0x7F, 0xFF, 0x7F, 0xF9, 0x5A, 0x1A, 0x2A, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E,
  0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E,
  0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3D, 0x1E, 0x9A, 0x3E, 0x9C, 0x73, 0xBD, 0x73, 0x7B, 0x36,
  0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E,
  0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E,
  0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3F, 0x1E, 0x3D, 0x22, 0xFB, 0x56, 0x5C, 0x67, 0x1C, 0x22, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E,
  0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E,
  0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x7A, 0x3A, 0x7F, 0x63, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E,
  0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E,
  0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E, 0x1F, 0x1E,
  0x3B, 0x2E, 0x7F, 0x63, 0x1F, 0x1E, 0x1F, 0x1A, 0xFF, 0x19, 0x1F, 0x1A, 0x1F, 0x1A, 0x1F, 0x1A, 0x1F, 0x1A, 0x1F, 0x1A, 0x1F, 0x1A, 0x1F, 0x1E, 0x1F, 0x1A, 0x1F, 0x1A, 0x1F, 0x1A, 0x1F, 0x1A, 0x1F, 0x1A, 0x1F, 0x1A, 0x1F, 0x1A, 0x1F, 0x1A, 0x1F, 0x1A,
  0x1F, 0x1A, 0x1F, 0x1A, 0xFF, 0x19, 0x1F, 0x1A, 0x1F, 0x1A, 0x1F, 0x1A, 0xFF, 0x19, 0x1F, 0x1A, 0x1F, 0x1A, 0x1F, 0x1E, 0x1F, 0x1A, 0x1F, 0x1E, 0x1F, 0x1A, 0x1F, 0x1A, 0x1F, 0x1A, 0x1F, 0x1E, 0x1F, 0x1A, 0x1F, 0x1A, 0x1F, 0x1A, 0xFF, 0x19, 0xFF, 0x19,
  0x1F, 0x1A, 0x1F, 0x1A, 0x1F, 0x1A, 0xFF, 0x19, 0xFF, 0x19, 0x1F, 0x1E, 0x1F, 0x1A, 0x1F, 0x1A, 0x5F, 0x2A, 0x5F, 0x63, 0x1F, 0x1E, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19,
  0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19,
  0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0x5F, 0x2A, 0x5F, 0x63, 0xFF, 0x1D, 0xFF, 0x19, 0xFF, 0x19,
  0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19,
  0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19,
  0xFF, 0x19, 0xFF, 0x19, 0xFF, 0x19, 0x3F, 0x2A, 0x5F, 0x63, 0xFF, 0x1D, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19,
  0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19,
  0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0xDF, 0x19, 0x3F, 0x2A, 0x5F, 0x63, 0xDF, 0x1D, 0xDF, 0x19, 0xDF, 0x19, 0xFB, 0x25, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E,
  0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E,
  0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2E, 0x1A, 0x2A, 0xDD, 0x1D, 0xDF, 0x19, 0xDF, 0x19, 0x3F, 0x2A, 0x5F, 0x63,
  0xDF, 0x19, 0xBF, 0x19, 0xDC, 0x1D, 0xD8, 0x56, 0x7C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F,
  0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F, 0x9C, 0x6F,
  0x9C, 0x6F, 0x9C, 0x6F, 0x5B, 0x6B, 0x5C, 0x36, 0xBF, 0x19, 0xDF, 0x19, 0x1F, 0x2A, 0x5F, 0x63, 0xDF, 0x19, 0xBF, 0x15, 0xBC, 0x1D, 0x1A, 0x5F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0x5D, 0x36, 0xBF, 0x15, 0xBF, 0x15, 0x1F, 0x26, 0x5F, 0x63, 0xBF, 0x19, 0xBF, 0x15, 0xBC, 0x1D, 0x1A, 0x5F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0x5D, 0x36, 0xBF, 0x15,
  0xBF, 0x15, 0x1F, 0x26, 0x5F, 0x63, 0xBF, 0x19, 0x9F, 0x15, 0xBC, 0x1D, 0x1A, 0x5F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0x5D, 0x36, 0x9F, 0x15, 0x9F, 0x15, 0xFF, 0x25, 0x5F, 0x5F, 0xBF, 0x19, 0x9F, 0x15, 0xBC, 0x1D, 0x1A, 0x5F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0x3D, 0x36, 0x9F, 0x15, 0x9F, 0x15, 0xFF, 0x25, 0x3F, 0x5F, 0x9F, 0x19, 0x9F, 0x15,
  0x9C, 0x1D, 0x1A, 0x5F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xBE, 0x77, 0x3D, 0x36, 0x9F, 0x15, 0x9F, 0x15, 0xDF, 0x25, 0x3F, 0x5F, 0x9F, 0x15, 0x7F, 0x15, 0x9C, 0x1D, 0x1A, 0x5F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBD, 0x77, 0xB5, 0x56, 0x31, 0x46, 0x31, 0x46, 0x31, 0x46, 0x73, 0x4E, 0x9C, 0x73, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0x3D, 0x36, 0x7F, 0x15, 0x7F, 0x15, 0xDF, 0x25, 0x3F, 0x5F, 0x7F, 0x15, 0x7F, 0x11, 0x9C, 0x1D, 0x1A, 0x5F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xDE, 0x7B, 0xD6, 0x5A, 0x4A, 0x29, 0xE7, 0x1C, 0xE7, 0x1C, 0xE7, 0x1C, 0x31, 0x46, 0x9C, 0x73, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0x3D, 0x36, 0x7F, 0x11, 0x7F, 0x11, 0xDF, 0x25,
  0x3F, 0x5F, 0x7F, 0x15, 0x5F, 0x11, 0x7C, 0x19, 0x1A, 0x5F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xDE, 0x7B, 0x94, 0x52, 0x29, 0x25, 0xC6, 0x18, 0xC6, 0x18, 0x08, 0x21, 0x52, 0x4A, 0xBD, 0x77, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0x3D, 0x36, 0x5F, 0x11, 0x5F, 0x11, 0xDF, 0x25, 0x3F, 0x5F, 0x7F, 0x15, 0x5F, 0x11, 0x7C, 0x19, 0x1A, 0x5F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBD, 0x77, 0x73, 0x4E, 0x08, 0x21,
  0xC6, 0x18, 0xC6, 0x18, 0x08, 0x21, 0x94, 0x52, 0xDE, 0x7B, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0x1D, 0x36, 0x5F, 0x11, 0x5F, 0x11, 0xBF, 0x21, 0x3F, 0x5F, 0x5F, 0x15, 0x5F, 0x11, 0x7C, 0x19, 0x1A, 0x5F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBD, 0x77, 0x31, 0x46, 0xE7, 0x1C, 0xC6, 0x18, 0xC6, 0x18, 0x29, 0x25, 0xB5, 0x56, 0xDE, 0x7B, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0x1D, 0x36,
  0x5F, 0x11, 0x5F, 0x11, 0xBF, 0x21, 0x3F, 0x5F, 0x5F, 0x15, 0x3F, 0x11, 0x5C, 0x19, 0x1A, 0x5F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x9C, 0x73, 0x10, 0x42, 0xE7, 0x1C, 0xC6, 0x18, 0xC6, 0x18, 0x4A, 0x29,
  0xF7, 0x5E, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0x1D, 0x32, 0x3F, 0x11, 0x3F, 0x11, 0xBF, 0x21, 0x3F, 0x5F, 0x3F, 0x11, 0x3F, 0x11, 0x5C, 0x19, 0x1A, 0x5F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x7B, 0x6F, 0xCE, 0x39, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0x8C, 0x31, 0x18, 0x63, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0xFD, 0x31, 0x3F, 0x11, 0x3F, 0x11, 0x9F, 0x21, 0x1F, 0x5F, 0x3F, 0x11,
  0x3F, 0x11, 0x5C, 0x19, 0x1A, 0x5F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x39, 0x67, 0x6B, 0x2D, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xAD, 0x35, 0x7B, 0x6F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xBE, 0x77, 0xFD, 0x31, 0x3F, 0x11, 0x3F, 0x11, 0x9F, 0x21, 0x1F, 0x5F, 0x3F, 0x11, 0x1F, 0x0D, 0x3C, 0x19, 0x1A, 0x5F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x5A, 0x6B,
  0x6B, 0x2D, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xAD, 0x35, 0x7B, 0x6F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0xFD, 0x31, 0x1F, 0x0D, 0x1F, 0x0D, 0x9F, 0x21, 0x1F, 0x5F, 0x1F, 0x11, 0x1F, 0x0D, 0x3C, 0x15, 0x1A, 0x5F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x7B, 0x6F, 0xEF, 0x3D, 0xE7, 0x1C, 0xC6, 0x18, 0xC6, 0x18, 0x6B, 0x2D, 0x18, 0x63, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0xFD, 0x31, 0x1F, 0x0D, 0x1F, 0x0D,
  0x7F, 0x1D, 0x1F, 0x5F, 0x1F, 0x11, 0xFF, 0x0C, 0x3C, 0x15, 0x1A, 0x5F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x9C, 0x73, 0x10, 0x42, 0xE7, 0x1C, 0xC6, 0x18, 0xC6, 0x18, 0x4A, 0x29, 0xD6, 0x5A, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xDE, 0x7B, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xDE, 0x7B, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0xDD, 0x31, 0xFF, 0x0C, 0xFF, 0x0C, 0x7F, 0x1D, 0x1F, 0x5F, 0x1F, 0x11, 0xFF, 0x0C, 0x3C, 0x15, 0xFA, 0x5E, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBD, 0x77,
  0x52, 0x4A, 0xE7, 0x1C, 0xC6, 0x18, 0xC6, 0x18, 0x29, 0x25, 0xB5, 0x56, 0xDE, 0x7B, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x9C, 0x73, 0x73, 0x4E, 0xEF, 0x3D, 0xCE, 0x39, 0xCE, 0x39, 0xCE, 0x39, 0xCE, 0x39, 0xCE, 0x39, 0xCE, 0x39, 0xCE, 0x39,
  0xCE, 0x39, 0xEF, 0x3D, 0x73, 0x4E, 0x9C, 0x73, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0xDD, 0x31, 0xFF, 0x0C, 0xFF, 0x0C, 0x7F, 0x1D, 0x1F, 0x5F, 0xFF, 0x10, 0xFF, 0x0C, 0x1C, 0x15,
  0xFA, 0x5E, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xDE, 0x7B, 0x73, 0x4E, 0x08, 0x21, 0xC6, 0x18, 0xC6, 0x18, 0x08, 0x21, 0x73, 0x4E, 0xDE, 0x7B, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xB5, 0x56, 0x08, 0x21,
  0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xE7, 0x1C, 0x73, 0x4E, 0xDE, 0x7B, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77,
  0xDD, 0x31, 0xFF, 0x0C, 0xFF, 0x0C, 0x5F, 0x1D, 0x1F, 0x5F, 0xFF, 0x0C, 0xDF, 0x0C, 0x1C, 0x15, 0xFA, 0x5E, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xDE, 0x7B, 0xB5, 0x56, 0x29, 0x25, 0xC6, 0x18, 0xC6, 0x18, 0xE7, 0x1C, 0x52, 0x4A, 0xBD, 0x77,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xDE, 0x7B, 0x31, 0x46, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0x10, 0x42, 0xDE, 0x7B,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0xDD, 0x31, 0xDF, 0x0C, 0xDF, 0x0C, 0x5F, 0x1D, 0x1F, 0x5F, 0xFF, 0x0C, 0xDF, 0x08, 0x1C, 0x15, 0xFA, 0x5E, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xD6, 0x5A, 0x4A, 0x29, 0xC6, 0x18, 0xC6, 0x18, 0xE7, 0x1C, 0x10, 0x42, 0x9C, 0x73, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xD6, 0x5A, 0x29, 0x25, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18,
  0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0xC6, 0x18, 0x08, 0x21, 0x94, 0x52, 0xDE, 0x7B, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0xDD, 0x2D, 0xDF, 0x08, 0xDF, 0x08, 0x5F, 0x1D, 0x1F, 0x5F,
  0xDF, 0x0C, 0xBF, 0x08, 0xFC, 0x14, 0xFA, 0x5E, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBD, 0x77, 0xB5, 0x56, 0x31, 0x46, 0x31, 0x46, 0x31, 0x46, 0x73, 0x4E, 0x7B, 0x6F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xBD, 0x77, 0xB5, 0x56, 0x31, 0x46, 0x10, 0x42, 0x10, 0x42, 0x10, 0x42, 0x10, 0x42, 0x10, 0x42, 0x10, 0x42, 0x10, 0x42, 0x10, 0x42, 0x31, 0x46, 0xB5, 0x56, 0xBD, 0x77, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0xBD, 0x2D, 0xBF, 0x08, 0xBF, 0x08, 0x3F, 0x1D, 0xFF, 0x5E, 0xDF, 0x0C, 0xBF, 0x08, 0xFC, 0x10, 0xFA, 0x5E, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0xBD, 0x2D, 0xBF, 0x08, 0xBF, 0x08, 0x3F, 0x1D, 0xFF, 0x5E, 0xBF, 0x0C, 0xBF, 0x08, 0xFC, 0x10, 0xFA, 0x5E, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0xBD, 0x2D, 0xBF, 0x08,
  0xBF, 0x08, 0x3F, 0x19, 0xFF, 0x5A, 0xBF, 0x0C, 0x9F, 0x08, 0xDC, 0x10, 0xFA, 0x5E, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0xBD, 0x2D, 0x9F, 0x08, 0x9F, 0x08, 0x1F, 0x19, 0xFF, 0x5A, 0xBF, 0x08, 0x9F, 0x08, 0xDC, 0x10, 0xFA, 0x5E, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0x9D, 0x2D, 0x9F, 0x04, 0x9F, 0x08, 0x1F, 0x19, 0xFF, 0x5A, 0x9F, 0x08, 0x7F, 0x04,
  0xDC, 0x10, 0xFA, 0x5E, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xBE, 0x77, 0x9D, 0x2D, 0x7F, 0x04, 0x7F, 0x04, 0x1F, 0x19, 0xFF, 0x5A, 0x9F, 0x08, 0x7F, 0x04, 0xBC, 0x10, 0xFA, 0x5E, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0x9D, 0x2D, 0x7F, 0x04, 0x7F, 0x04, 0xFF, 0x18, 0xFF, 0x5A, 0x9F, 0x08, 0x7F, 0x04, 0xBC, 0x10, 0xFA, 0x5E, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0x9D, 0x2D, 0x7F, 0x04, 0x7F, 0x04, 0xFF, 0x18,
  0xFF, 0x5A, 0x7F, 0x08, 0x5F, 0x04, 0xBC, 0x10, 0xFA, 0x5E, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBE, 0x77, 0x7D, 0x2D, 0x5F, 0x04, 0x5F, 0x04, 0xFF, 0x18, 0xFF, 0x5A, 0x7F, 0x08, 0x5F, 0x04, 0x9C, 0x0C, 0xD9, 0x56, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xBD, 0x77, 0x5C, 0x29, 0x5F, 0x04, 0x5F, 0x04, 0xFF, 0x18, 0xDF, 0x5A, 0x5F, 0x04, 0x5F, 0x04, 0x5F, 0x04, 0xDA, 0x35,
  0x9C, 0x73, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B,
  0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDE, 0x7B, 0xDA, 0x5A, 0xDC, 0x14,
  0x3F, 0x00, 0x3F, 0x00, 0x1B, 0x21, 0x1D, 0x63, 0x9C, 0x0C, 0x3F, 0x00, 0x3F, 0x00, 0x7C, 0x0C, 0x78, 0x2D, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42,
  0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42,
  0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0x17, 0x42, 0xD8, 0x39, 0x19, 0x1D, 0x3E, 0x04, 0x3F, 0x00, 0x3E, 0x04, 0xB9, 0x35, 0xBD, 0x77, 0x7A, 0x2D, 0x3F, 0x00, 0x3F, 0x00, 0x3F, 0x00, 0x3E, 0x00, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04,
  0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04,
  0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3E, 0x04, 0x3F, 0x00, 0x3F, 0x00, 0x3F, 0x00, 0x9B, 0x10, 0xB9, 0x56, 0xFF, 0x7F, 0xDB, 0x5A,
  0xDB, 0x18, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00,
  0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00,
  0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x3D, 0x04, 0xBA, 0x35, 0x9D, 0x73, 0xFF, 0x7F, 0xDE, 0x7B, 0xBA, 0x56, 0x19, 0x21, 0x5C, 0x08, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00,
  0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00,
  0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x9B, 0x10, 0xD8, 0x39, 0x7B, 0x6F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xDE, 0x7B, 0x3A, 0x67, 0x38, 0x46, 0x99, 0x31, 0x59, 0x29,
  0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29,
  0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0x59, 0x29, 0xB9, 0x35, 0xB9, 0x56, 0x9C, 0x73, 0xFF, 0x7F,
  0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xDE, 0x7B, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77,
  0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77,
  0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xBD, 0x77, 0xDE, 0x7B, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
};

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 320, 240, 0, 0x0, 0 },
  { ICONVIEW_CreateIndirect, "Iconview", ID_ICONVIEW_0, 60, 40, 62, 63, 0, 0x00320032, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/*********************************************************************
*
*       _GetImageById
*/
static const void * _GetImageById(U32 Id, U32 * pSize) {
  switch (Id) {
  case ID_ICONVIEW_0_IMAGE_0:
    *pSize = sizeof(_acImage_0);
    return (const void *)_acImage_0;
  }
  return NULL;
}

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  const void * pData;
  WM_HWIN      hItem;
  U32          FileSize;
  int          NCode;
  int          Id;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'Iconview'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_ICONVIEW_0);
    pData = _GetImageById(ID_ICONVIEW_0_IMAGE_0, &FileSize);
    ICONVIEW_AddStreamedBitmapItem(hItem, pData, "");
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_ICONVIEW_0: // Notifications sent by 'Iconview'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_MOVED_OUT:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_SCROLL_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_SEL_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateWindow
*/
WM_HWIN CreateWindow(void);
WM_HWIN CreateWindow(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/

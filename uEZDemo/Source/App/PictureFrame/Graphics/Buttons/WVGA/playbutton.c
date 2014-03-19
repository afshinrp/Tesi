/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                           www.segger.com                           *
**********************************************************************
*                                                                    *
* C-file generated by                                                *
*                                                                    *
*        Bitmap converter for emWin V5.12.                           *
*        Compiled Jun 29 2011, 15:28:21                              *
*        (C) 1998 - 2010 Segger Microcontroller GmbH & Co. KG        *
*                                                                    *
**********************************************************************
*                                                                    *
* Source file: playbutton                                            *
* Dimensions:  72 * 72                                               *
* NumColors:   3                                                     *
*                                                                    *
**********************************************************************
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

/*   Palette
The following are the entries of the palette table.
Every entry is a 32-bit value (of which 24 bits are actually used)
the lower   8 bits represent the Red component,
the middle  8 bits represent the Green component,
the highest 8 bits (of the 24 bits used) represent the Blue component
as follows:   0xBBGGRR
*/

static GUI_CONST_STORAGE GUI_COLOR Colorsplaybutton[] = {
     0xFFFFFF,0x00FF00,0x808080
};

static GUI_CONST_STORAGE GUI_LOGPALETTE Palplaybutton = {
  3,	/* number of entries */
  1, 	/* Has transparency */
  &Colorsplaybutton[0]
};

static GUI_CONST_STORAGE unsigned char acplaybutton[] = {
  /* RLE: 671 Pixels @ 000,000*/ 254, 0x00, 254, 0x00, 163, 0x00, 
  /* RLE: 006 Pixels @ 023,009*/ 6, 0x01, 
  /* RLE: 066 Pixels @ 029,009*/ 66, 0x00, 
  /* RLE: 006 Pixels @ 023,010*/ 6, 0x01, 
  /* RLE: 066 Pixels @ 029,010*/ 66, 0x00, 
  /* RLE: 009 Pixels @ 023,011*/ 9, 0x01, 
  /* RLE: 063 Pixels @ 032,011*/ 63, 0x00, 
  /* RLE: 009 Pixels @ 023,012*/ 9, 0x01, 
  /* RLE: 063 Pixels @ 032,012*/ 63, 0x00, 
  /* RLE: 009 Pixels @ 023,013*/ 9, 0x01, 
  /* RLE: 063 Pixels @ 032,013*/ 63, 0x00, 
  /* RLE: 011 Pixels @ 023,014*/ 11, 0x01, 
  /* RLE: 061 Pixels @ 034,014*/ 61, 0x00, 
  /* RLE: 011 Pixels @ 023,015*/ 11, 0x01, 
  /* RLE: 061 Pixels @ 034,015*/ 61, 0x00, 
  /* RLE: 013 Pixels @ 023,016*/ 13, 0x01, 
  /* RLE: 059 Pixels @ 036,016*/ 59, 0x00, 
  /* RLE: 013 Pixels @ 023,017*/ 13, 0x01, 
  /* RLE: 059 Pixels @ 036,017*/ 59, 0x00, 
  /* RLE: 015 Pixels @ 023,018*/ 15, 0x01, 
  /* RLE: 057 Pixels @ 038,018*/ 57, 0x00, 
  /* RLE: 015 Pixels @ 023,019*/ 15, 0x01, 
  /* RLE: 057 Pixels @ 038,019*/ 57, 0x00, 
  /* RLE: 018 Pixels @ 023,020*/ 18, 0x01, 
  /* RLE: 054 Pixels @ 041,020*/ 54, 0x00, 
  /* RLE: 018 Pixels @ 023,021*/ 18, 0x01, 
  /* RLE: 054 Pixels @ 041,021*/ 54, 0x00, 
  /* RLE: 018 Pixels @ 023,022*/ 18, 0x01, 
  /* RLE: 054 Pixels @ 041,022*/ 54, 0x00, 
  /* RLE: 020 Pixels @ 023,023*/ 20, 0x01, 
  /* RLE: 052 Pixels @ 043,023*/ 52, 0x00, 
  /* RLE: 020 Pixels @ 023,024*/ 20, 0x01, 
  /* RLE: 052 Pixels @ 043,024*/ 52, 0x00, 
  /* RLE: 022 Pixels @ 023,025*/ 22, 0x01, 
  /* RLE: 050 Pixels @ 045,025*/ 50, 0x00, 
  /* RLE: 022 Pixels @ 023,026*/ 22, 0x01, 
  /* RLE: 050 Pixels @ 045,026*/ 50, 0x00, 
  /* RLE: 024 Pixels @ 023,027*/ 24, 0x01, 
  /* RLE: 048 Pixels @ 047,027*/ 48, 0x00, 
  /* RLE: 024 Pixels @ 023,028*/ 24, 0x01, 
  /* RLE: 048 Pixels @ 047,028*/ 48, 0x00, 
  /* RLE: 027 Pixels @ 023,029*/ 27, 0x01, 
  /* RLE: 045 Pixels @ 050,029*/ 45, 0x00, 
  /* RLE: 027 Pixels @ 023,030*/ 27, 0x01, 
  /* RLE: 045 Pixels @ 050,030*/ 45, 0x00, 
  /* RLE: 027 Pixels @ 023,031*/ 27, 0x01, 
  /* RLE: 045 Pixels @ 050,031*/ 45, 0x00, 
  /* RLE: 029 Pixels @ 023,032*/ 29, 0x01, 
  /* RLE: 043 Pixels @ 052,032*/ 43, 0x00, 
  /* RLE: 029 Pixels @ 023,033*/ 29, 0x01, 
  /* RLE: 043 Pixels @ 052,033*/ 43, 0x00, 
  /* RLE: 031 Pixels @ 023,034*/ 31, 0x01, 
  /* RLE: 041 Pixels @ 054,034*/ 41, 0x00, 
  /* RLE: 031 Pixels @ 023,035*/ 31, 0x01, 
  /* RLE: 041 Pixels @ 054,035*/ 41, 0x00, 
  /* RLE: 031 Pixels @ 023,036*/ 31, 0x01, 
  /* ABS: 002 Pixels @ 054,036*/ 0, 2, 0x02, 0x02, 
  /* RLE: 039 Pixels @ 056,036*/ 39, 0x00, 
  /* RLE: 031 Pixels @ 023,037*/ 31, 0x01, 
  /* ABS: 002 Pixels @ 054,037*/ 0, 2, 0x02, 0x02, 
  /* RLE: 039 Pixels @ 056,037*/ 39, 0x00, 
  /* RLE: 029 Pixels @ 023,038*/ 29, 0x01, 
  /* RLE: 004 Pixels @ 052,038*/ 4, 0x02, 
  /* RLE: 039 Pixels @ 056,038*/ 39, 0x00, 
  /* RLE: 029 Pixels @ 023,039*/ 29, 0x01, 
  /* RLE: 004 Pixels @ 052,039*/ 4, 0x02, 
  /* RLE: 039 Pixels @ 056,039*/ 39, 0x00, 
  /* RLE: 029 Pixels @ 023,040*/ 29, 0x01, 
  /* RLE: 004 Pixels @ 052,040*/ 4, 0x02, 
  /* RLE: 039 Pixels @ 056,040*/ 39, 0x00, 
  /* RLE: 027 Pixels @ 023,041*/ 27, 0x01, 
  /* RLE: 004 Pixels @ 050,041*/ 4, 0x02, 
  /* RLE: 041 Pixels @ 054,041*/ 41, 0x00, 
  /* RLE: 027 Pixels @ 023,042*/ 27, 0x01, 
  /* RLE: 004 Pixels @ 050,042*/ 4, 0x02, 
  /* RLE: 041 Pixels @ 054,042*/ 41, 0x00, 
  /* RLE: 024 Pixels @ 023,043*/ 24, 0x01, 
  /* RLE: 005 Pixels @ 047,043*/ 5, 0x02, 
  /* RLE: 043 Pixels @ 052,043*/ 43, 0x00, 
  /* RLE: 024 Pixels @ 023,044*/ 24, 0x01, 
  /* RLE: 005 Pixels @ 047,044*/ 5, 0x02, 
  /* RLE: 043 Pixels @ 052,044*/ 43, 0x00, 
  /* RLE: 022 Pixels @ 023,045*/ 22, 0x01, 
  /* RLE: 005 Pixels @ 045,045*/ 5, 0x02, 
  /* RLE: 045 Pixels @ 050,045*/ 45, 0x00, 
  /* RLE: 022 Pixels @ 023,046*/ 22, 0x01, 
  /* RLE: 005 Pixels @ 045,046*/ 5, 0x02, 
  /* RLE: 045 Pixels @ 050,046*/ 45, 0x00, 
  /* RLE: 020 Pixels @ 023,047*/ 20, 0x01, 
  /* RLE: 004 Pixels @ 043,047*/ 4, 0x02, 
  /* RLE: 048 Pixels @ 047,047*/ 48, 0x00, 
  /* RLE: 020 Pixels @ 023,048*/ 20, 0x01, 
  /* RLE: 004 Pixels @ 043,048*/ 4, 0x02, 
  /* RLE: 048 Pixels @ 047,048*/ 48, 0x00, 
  /* RLE: 020 Pixels @ 023,049*/ 20, 0x01, 
  /* RLE: 004 Pixels @ 043,049*/ 4, 0x02, 
  /* RLE: 048 Pixels @ 047,049*/ 48, 0x00, 
  /* RLE: 018 Pixels @ 023,050*/ 18, 0x01, 
  /* RLE: 004 Pixels @ 041,050*/ 4, 0x02, 
  /* RLE: 050 Pixels @ 045,050*/ 50, 0x00, 
  /* RLE: 018 Pixels @ 023,051*/ 18, 0x01, 
  /* RLE: 004 Pixels @ 041,051*/ 4, 0x02, 
  /* RLE: 050 Pixels @ 045,051*/ 50, 0x00, 
  /* RLE: 015 Pixels @ 023,052*/ 15, 0x01, 
  /* RLE: 005 Pixels @ 038,052*/ 5, 0x02, 
  /* RLE: 052 Pixels @ 043,052*/ 52, 0x00, 
  /* RLE: 015 Pixels @ 023,053*/ 15, 0x01, 
  /* RLE: 005 Pixels @ 038,053*/ 5, 0x02, 
  /* RLE: 052 Pixels @ 043,053*/ 52, 0x00, 
  /* RLE: 013 Pixels @ 023,054*/ 13, 0x01, 
  /* RLE: 005 Pixels @ 036,054*/ 5, 0x02, 
  /* RLE: 054 Pixels @ 041,054*/ 54, 0x00, 
  /* RLE: 013 Pixels @ 023,055*/ 13, 0x01, 
  /* RLE: 005 Pixels @ 036,055*/ 5, 0x02, 
  /* RLE: 054 Pixels @ 041,055*/ 54, 0x00, 
  /* RLE: 011 Pixels @ 023,056*/ 11, 0x01, 
  /* RLE: 004 Pixels @ 034,056*/ 4, 0x02, 
  /* RLE: 057 Pixels @ 038,056*/ 57, 0x00, 
  /* RLE: 011 Pixels @ 023,057*/ 11, 0x01, 
  /* RLE: 004 Pixels @ 034,057*/ 4, 0x02, 
  /* RLE: 057 Pixels @ 038,057*/ 57, 0x00, 
  /* RLE: 011 Pixels @ 023,058*/ 11, 0x01, 
  /* RLE: 004 Pixels @ 034,058*/ 4, 0x02, 
  /* RLE: 057 Pixels @ 038,058*/ 57, 0x00, 
  /* RLE: 009 Pixels @ 023,059*/ 9, 0x01, 
  /* RLE: 004 Pixels @ 032,059*/ 4, 0x02, 
  /* RLE: 059 Pixels @ 036,059*/ 59, 0x00, 
  /* RLE: 009 Pixels @ 023,060*/ 9, 0x01, 
  /* RLE: 004 Pixels @ 032,060*/ 4, 0x02, 
  /* RLE: 059 Pixels @ 036,060*/ 59, 0x00, 
  /* RLE: 006 Pixels @ 023,061*/ 6, 0x01, 
  /* RLE: 005 Pixels @ 029,061*/ 5, 0x02, 
  /* RLE: 061 Pixels @ 034,061*/ 61, 0x00, 
  /* RLE: 006 Pixels @ 023,062*/ 6, 0x01, 
  /* RLE: 005 Pixels @ 029,062*/ 5, 0x02, 
  /* RLE: 063 Pixels @ 034,062*/ 63, 0x00, 
  /* RLE: 007 Pixels @ 025,063*/ 7, 0x02, 
  /* RLE: 065 Pixels @ 032,063*/ 65, 0x00, 
  /* RLE: 007 Pixels @ 025,064*/ 7, 0x02, 
  /* RLE: 544 Pixels @ 032,064*/ 254, 0x00, 254, 0x00, 36, 0x00, 


  0};  /* 292 bytes for 5184 pixels */

GUI_CONST_STORAGE GUI_BITMAP bmplaybutton = {
  72, /* XSize */
  72, /* YSize */
  72, /* BytesPerLine */
  GUI_COMPRESS_RLE8, /* BitsPerPixel */
  acplaybutton,  /* Pointer to picture data (indices) */
  &Palplaybutton,  /* Pointer to palette */
  GUI_DRAW_RLE8
};

/* *** End of file *** */

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
* Source file: settings_S                                            *
* Dimensions:  43 * 43                                               *
* NumColors:   196                                                   *
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

static GUI_CONST_STORAGE GUI_COLOR Colorssettings_S[] = {
     0xFFFFFF,0x999999,0x4645A9,0x4244C9
    ,0x928677,0x393CBA,0x424399,0x636363
    ,0x595957,0x6F6458,0x87786F,0x040367
    ,0x292797,0x2727AB,0x3134CA,0x3B37DA
    ,0x4B4EF5,0xDAD9D9,0x141468,0x060676
    ,0x221872,0x262667,0x7D7364,0x4645BA
    ,0x443EFC,0x898988,0xB8B9B8,0x8988E6
    ,0xCAC8CA,0x010058,0x252577,0x484877
    ,0x7B7B70,0x292689,0x31338B,0x787893
    ,0x3736ED,0xA8A8A5,0x242454,0x383579
    ,0x7B7B7C,0x161698,0x393A9C,0x4139AF
    ,0x5755A8,0x5656B6,0x3034D9,0x7374E6
    ,0xACA9F7,0x403B38,0x131377,0x6B6363
    ,0x756C65,0x171689,0x222086,0x293187
    ,0x313194,0x393194,0x31319C,0x3939A5
    ,0x2625B7,0x3233B8,0x535389,0x3B37CA
    ,0x4745DA,0xAAA69B,0x918FBA,0x2F2C2F
    ,0x100E43,0x221858,0x454545,0x524A43
    ,0x524E51,0x060288,0x18218C,0x322997
    ,0x293197,0x39319C,0x201EA2,0x3131A5
    ,0x42399F,0x545698,0x727080,0x453FEA
    ,0x5753C9,0x968A86,0x9CA59C,0xB7ADAA
    ,0x504938,0x1A1646,0x141357,0x363247
    ,0x333455,0x312766,0x585343,0x606258
    ,0x484866,0x5A5964,0x696775,0x736B73
    ,0x737370,0x737B7B,0x0D1089,0x0C1094
    ,0x31399C,0x100CA2,0x2931AA,0x2931BB
    ,0x6764A2,0x3329D8,0x3942CA,0x7777CC
    ,0x6466D0,0x7B8484,0x989687,0xAFA6CE
    ,0xF2EFEE,0xF7F7F7,0x050542,0x080D5A
    ,0x100858,0x081078,0x333365,0x2B3175
    ,0x575677,0x635768,0x6B6B63,0x63636B
    ,0x7B7373,0x100686,0x050596,0x312986
    ,0x3B378A,0x313994,0x3D3994,0x161FB3
    ,0x3931A5,0x3931AE,0x3843A8,0x46458A
    ,0x524A94,0x4A52B5,0x6B69B7,0x2629C9
    ,0x4A52CE,0x9CA5A5,0xB5B5AB,0xADACB0
    ,0xC6C6BD,0xE7E7E8,0x080800,0x101010
    ,0x2E291B,0x060626,0x070735,0x242024
    ,0x18214D,0x13086B,0x081063,0x100877
    ,0x182371,0x31257B,0x42395F,0x394263
    ,0x464856,0x635748,0x42527B,0x737B70
    ,0x7B737B,0x897B7E,0x818476,0x3139A5
    ,0x3139AD,0x524A8C,0x4A4B98,0x635A97
    ,0x554AAA,0x524AB5,0x4A48CC,0x635AE7
    ,0x8C9488,0x8C8A97,0x909494,0xA79C96
    ,0xA89CA5,0xB5BBFD,0xD6CECE,0xCED6CB
    ,0xD9DECB,0xD6CED6,0xE7DEDE,0xEBE9DC
    ,0xCAC6F3,0xDEE7EF,0xF7EFF7,0xFFF7F7
};

static GUI_CONST_STORAGE GUI_LOGPALETTE Palsettings_S = {
  196,	/* number of entries */
  1, 	/* Has transparency */
  &Colorssettings_S[0]
};

static GUI_CONST_STORAGE unsigned char acsettings_S[] = {
  /* RLE: 196 Pixels @ 000,000*/ 196, 0x00, 
  /* ABS: 009 Pixels @ 024,004*/ 0, 9, 0x0C, 0x37, 0x1E, 0x38, 0x00, 0x00, 0x00, 0x15, 0x5D, 
  /* RLE: 030 Pixels @ 033,004*/ 30, 0x00, 
  /* ABS: 013 Pixels @ 020,005*/ 0, 13, 0x2A, 0x00, 0x39, 0x22, 0x22, 0x22, 0x39, 0x37, 0x22, 0x38, 0x45, 0x4D, 0x45, 
  /* RLE: 027 Pixels @ 033,005*/ 27, 0x00, 
  /* ABS: 007 Pixels @ 017,006*/ 0, 7, 0x2A, 0x27, 0x21, 0x3A, 0x21, 0x0B, 0x0B, 
  /* RLE: 004 Pixels @ 024,006*/ 4, 0x1D, 
  /* ABS: 007 Pixels @ 028,006*/ 0, 7, 0x0B, 0x0B, 0x1E, 0x22, 0x0C, 0x39, 0x1E, 
  /* RLE: 025 Pixels @ 035,006*/ 25, 0x00, 
  /* ABS: 007 Pixels @ 017,007*/ 0, 7, 0x68, 0x83, 0x3A, 0x4C, 0x32, 0x78, 0x45, 
  /* RLE: 004 Pixels @ 024,007*/ 4, 0x26, 
  /* ABS: 009 Pixels @ 028,007*/ 0, 9, 0x5A, 0x12, 0x32, 0x3A, 0x06, 0x0C, 0x0C, 0x1E, 0x83, 
  /* RLE: 021 Pixels @ 037,007*/ 21, 0x00, 
  /* ABS: 022 Pixels @ 015,008*/ 0, 22, 0xB0, 0x27, 0x6A, 0x37, 0x2A, 0x3A, 0x14, 0x46, 0x43, 0x43, 0x58, 0x58, 0x58, 0x47, 0x47, 0xA2, 0x50, 0x2D, 0x2D, 0x38, 0x21, 0x37, 
  /* RLE: 021 Pixels @ 037,008*/ 21, 0x00, 
  /* ABS: 024 Pixels @ 015,009*/ 0, 24, 0x6F, 0x7B, 0x6A, 0x06, 0x17, 0x4D, 0x48, 0x96, 0x97, 0x9B, 0x46, 0xA4, 0x48, 0x47, 0x31, 0x5E, 0x60, 0x3E, 0x1B, 0x2F, 0x84, 0x21, 0x15, 0x5D, 
  /* RLE: 017 Pixels @ 039,009*/ 17, 0x00, 
  /* ABS: 026 Pixels @ 013,010*/ 0, 26, 0x8E, 0x6F, 0x6D, 0x4C, 0xB3, 0x1F, 0x16, 0xBC, 0x27, 0x33, 0x07, 0x61, 0x61, 0xA8, 0x64, 0x08, 0x08, 0x08, 0x47, 0xA5, 0x08, 0x42, 0xC0, 0x2F, 0x1E, 0xAE, 
  /* RLE: 017 Pixels @ 039,010*/ 17, 0x00, 
  /* ABS: 027 Pixels @ 013,011*/ 0, 27, 0x2C, 0x30, 0x0E, 0x85, 0xAD, 0x0A, 0x74, 0x30, 0x00, 0x7D, 0x07, 0x07, 0x19, 0x48, 0x08, 0x28, 0x07, 0x07, 0x46, 0x5E, 0x5E, 0x48, 0x42, 0x30, 0xA1, 0x05, 0x86, 
  /* RLE: 015 Pixels @ 040,011*/ 15, 0x00, 
  /* ABS: 013 Pixels @ 012,012*/ 0, 13, 0x1F, 0x70, 0x24, 0x3C, 0x2B, 0x09, 0x62, 0x45, 0x00, 0x08, 0x5F, 0x28, 0x75, 
  /* RLE: 004 Pixels @ 025,012*/ 4, 0x00, 
  /* ABS: 011 Pixels @ 029,012*/ 0, 11, 0xBD, 0x07, 0x07, 0x46, 0x31, 0x98, 0x09, 0x33, 0x03, 0x6B, 0x22, 
  /* RLE: 015 Pixels @ 040,012*/ 15, 0x00, 
  /* ABS: 029 Pixels @ 012,013*/ 0, 29, 0x3B, 0x6D, 0x24, 0x7B, 0x5F, 0x07, 0x09, 0x09, 0x34, 0x07, 0x07, 0x19, 0x00, 0x95, 0x00, 0x00, 0x00, 0x75, 0x07, 0x63, 0x7F, 0x00, 0x00, 0x42, 0xC2, 0x02, 0x22, 0x4C, 0x39, 
  /* RLE: 014 Pixels @ 041,013*/ 14, 0x00, 
  /* ABS: 013 Pixels @ 012,014*/ 0, 13, 0x70, 0x10, 0x0E, 0x27, 0x09, 0x7E, 0x09, 0x33, 0x09, 0x52, 0x63, 0x7F, 0x1C, 
  /* RLE: 004 Pixels @ 025,014*/ 4, 0x00, 
  /* ABS: 012 Pixels @ 029,014*/ 0, 12, 0x1A, 0x62, 0x63, 0x33, 0x00, 0x00, 0x00, 0x73, 0x60, 0x4B, 0x4F, 0x85, 
  /* RLE: 014 Pixels @ 041,014*/ 14, 0x00, 
  /* ABS: 021 Pixels @ 012,015*/ 0, 21, 0x40, 0x24, 0x0F, 0x7D, 0x16, 0x34, 0x16, 0x34, 0x09, 0x74, 0x28, 0x20, 0x20, 0x20, 0x08, 0x08, 0x7E, 0xA7, 0x64, 0x65, 0x1C, 
  /* RLE: 004 Pixels @ 033,015*/ 4, 0x00, 
  /* ABS: 004 Pixels @ 037,015*/ 0, 4, 0x33, 0x38, 0x4E, 0x69, 
  /* RLE: 014 Pixels @ 041,015*/ 14, 0x00, 
  /* ABS: 021 Pixels @ 012,016*/ 0, 21, 0x24, 0x2E, 0x05, 0xAF, 0x16, 0x34, 0x16, 0x16, 0x09, 0x00, 0x19, 0x71, 0x28, 0x28, 0x71, 0x19, 0x28, 0x65, 0x19, 0x11, 0xBF, 
  /* RLE: 004 Pixels @ 033,016*/ 4, 0x00, 
  /* ABS: 004 Pixels @ 037,016*/ 0, 4, 0x09, 0x86, 0x0D, 0x49, 
  /* RLE: 014 Pixels @ 041,016*/ 14, 0x00, 
  /* ABS: 021 Pixels @ 012,017*/ 0, 21, 0x40, 0x53, 0x2B, 0x3F, 0x52, 0x20, 0x0A, 0x0A, 0x0A, 0x11, 0x75, 0x42, 0x7C, 0x23, 0x01, 0xB6, 0x23, 0x61, 0x11, 0x00, 0x01, 
  /* RLE: 004 Pixels @ 033,017*/ 4, 0x00, 
  /* ABS: 004 Pixels @ 037,017*/ 0, 4, 0x62, 0x3B, 0x35, 0x87, 
  /* RLE: 014 Pixels @ 041,017*/ 14, 0x00, 
  /* ABS: 021 Pixels @ 012,018*/ 0, 21, 0x54, 0x3C, 0x0D, 0x6B, 0x54, 0x0A, 0x0A, 0x20, 0x20, 0x55, 0x00, 0x73, 0xA3, 0x44, 0x5C, 0x5B, 0x43, 0x08, 0x00, 0x1C, 0x16, 
  /* RLE: 004 Pixels @ 033,018*/ 4, 0x00, 
  /* ABS: 004 Pixels @ 037,018*/ 0, 4, 0x51, 0x4F, 0x13, 0x49, 
  /* RLE: 014 Pixels @ 041,018*/ 14, 0x00, 
  /* ABS: 029 Pixels @ 012,019*/ 0, 29, 0x54, 0x49, 0x87, 0x3B, 0x24, 0x04, 0x0A, 0x20, 0x16, 0x34, 0x00, 0x93, 0x5B, 0x99, 0x5B, 0x80, 0x04, 0x41, 0x00, 0xAA, 0x80, 0x64, 0x00, 0x00, 0x00, 0x05, 0x68, 0x6B, 0x4E, 
  /* RLE: 014 Pixels @ 041,019*/ 14, 0x00, 
  /* ABS: 029 Pixels @ 012,020*/ 0, 29, 0x02, 0x69, 0x0F, 0x50, 0x0F, 0x23, 0x04, 0x01, 0x00, 0x57, 0x11, 0xC3, 0xB7, 0x31, 0x31, 0x04, 0x55, 0x57, 0x1C, 0x0A, 0xA9, 0x0A, 0x04, 0x04, 0x71, 0x3D, 0x68, 0x0D, 0x89, 
  /* RLE: 009 Pixels @ 041,020*/ 9, 0x00, 
  /* ABS: 021 Pixels @ 007,021*/ 0, 21, 0x26, 0x59, 0x00, 0x59, 0x02, 0x00, 0x3D, 0x0E, 0x4A, 0x03, 0x18, 0x10, 0x15, 0x00, 0x00, 0x25, 0x5F, 0x0A, 0x04, 0x19, 0x55, 
  /* RLE: 006 Pixels @ 028,021*/ 6, 0x04, 
  /* ABS: 007 Pixels @ 034,021*/ 0, 7, 0x23, 0x40, 0x2E, 0x4C, 0x3F, 0x81, 0x15, 
  /* RLE: 006 Pixels @ 041,021*/ 6, 0x00, 
  /* ABS: 036 Pixels @ 004,022*/ 0, 36, 0x06, 0x84, 0x00, 0x5C, 0x52, 0xB5, 0x41, 0x56, 0x01, 0x65, 0x27, 0x6D, 0x03, 0x53, 0x18, 0x0F, 0x0F, 0x53, 0x23, 0x23, 0x43, 0x00, 0x31, 0x41, 0x72, 0x55, 0x23, 0x17, 0x0F, 0x6E, 0x05, 0x29, 0x0C, 0x05, 0x81, 
        0x44, 
  /* RLE: 007 Pixels @ 040,022*/ 7, 0x00, 
  /* ABS: 035 Pixels @ 004,023*/ 0, 35, 0x2C, 0x8A, 0x08, 0x72, 0x01, 0x56, 0x01, 0x91, 0x01, 0x41, 0x72, 0x3F, 0x03, 0x53, 0x2E, 0x69, 0x0D, 0x3F, 0x3D, 0x50, 0x2A, 0x27, 0xA0, 0x51, 0x8D, 0xB1, 0x0F, 0x0E, 0x0E, 0x05, 0x05, 0x13, 0x35, 0x0D, 0x13, 
  /* RLE: 008 Pixels @ 039,023*/ 8, 0x00, 
  /* ABS: 035 Pixels @ 004,024*/ 0, 35, 0x2C, 0x02, 0x56, 0x56, 0x25, 0x57, 0x00, 0x00, 0x1A, 0x93, 0x25, 0xA6, 0x03, 0x8F, 0x4E, 0x3C, 0x3C, 0x02, 0x03, 0x6E, 0x03, 0x03, 0x03, 0x0F, 0x0E, 0x3F, 0xAC, 0x02, 0x36, 0x17, 0x03, 0x4A, 0x4A, 0x67, 0x13, 
  /* RLE: 007 Pixels @ 039,024*/ 7, 0x00, 
  /* ABS: 036 Pixels @ 003,025*/ 0, 36, 0x7A, 0x06, 0x06, 0x25, 0xB8, 0x25, 0x74, 0x00, 0x00, 0x00, 0x01, 0x25, 0x52, 0x50, 0x6E, 0x03, 0x03, 0x0F, 0x89, 0x02, 0x06, 0x36, 0x2A, 0x17, 0x4B, 0x06, 0x02, 0x1E, 0x2B, 0x21, 0x8D, 0x0E, 0x0D, 0x4A, 0x79, 
        0x9D, 
  /* RLE: 007 Pixels @ 039,025*/ 7, 0x00, 
  /* ABS: 034 Pixels @ 003,026*/ 0, 34, 0x1B, 0x1F, 0x19, 0x01, 0x1A, 0x00, 0x11, 0x00, 0x00, 0x00, 0x95, 0x01, 0x57, 0x3E, 0x0E, 0x29, 0x4F, 0x3D, 0x38, 0x8A, 0x06, 0x32, 0x2C, 0x06, 0x12, 0x6F, 0x06, 0x06, 0x3D, 0x29, 0x02, 0x66, 0x36, 0x35, 
  /* RLE: 009 Pixels @ 037,026*/ 9, 0x00, 
  /* ABS: 032 Pixels @ 003,027*/ 0, 32, 0x6C, 0x1F, 0x01, 0x01, 0x94, 0x00, 0xBB, 0x00, 0x00, 0x00, 0x11, 0x01, 0x92, 0x6C, 0x03, 0x05, 0x05, 0x05, 0x0C, 0x36, 0x3B, 0x14, 0x2D, 0x21, 0x12, 0x1B, 0x4B, 0x2D, 0x4E, 0x29, 0x4F, 0x77, 
  /* RLE: 009 Pixels @ 035,027*/ 9, 0x00, 
  /* ABS: 008 Pixels @ 001,028*/ 0, 8, 0x15, 0x02, 0xAB, 0x6C, 0xB4, 0x1A, 0x01, 0xBA, 
  /* RLE: 004 Pixels @ 009,028*/ 4, 0x00, 
  /* ABS: 022 Pixels @ 013,028*/ 0, 22, 0x25, 0x1A, 0x41, 0x73, 0x05, 0x0D, 0x29, 0x82, 0x26, 0x0C, 0x06, 0x5A, 0x2D, 0x37, 0x12, 0x2F, 0x12, 0x2D, 0x32, 0x00, 0x12, 0x44, 
  /* RLE: 010 Pixels @ 035,028*/ 10, 0x00, 
  /* ABS: 030 Pixels @ 002,029*/ 0, 30, 0x14, 0x9E, 0x70, 0x01, 0x1C, 0x1A, 0x91, 0x1A, 0x00, 0x00, 0x00, 0x1C, 0x1C, 0x1A, 0x30, 0x2B, 0x49, 0x1D, 0x13, 0x00, 0x0C, 0x5D, 0x00, 0x5C, 0x14, 0x00, 0x2F, 0x77, 0x00, 0x14, 
  /* RLE: 013 Pixels @ 032,029*/ 13, 0x00, 
  /* ABS: 019 Pixels @ 002,030*/ 0, 19, 0x1E, 0x05, 0x88, 0x1B, 0x01, 0x94, 0x11, 0x1C, 0x11, 0x11, 0xBE, 0x92, 0x19, 0xB9, 0xB2, 0x17, 0x90, 0x90, 0x36, 
  /* RLE: 024 Pixels @ 021,030*/ 24, 0x00, 
  /* ABS: 019 Pixels @ 002,031*/ 0, 19, 0x12, 0x67, 0x17, 0x17, 0x30, 0xC1, 0x42, 0x8B, 0x60, 0x1F, 0x14, 0x1B, 0x1B, 0x18, 0x10, 0x0B, 0x13, 0x0B, 0x5A, 
  /* RLE: 025 Pixels @ 021,031*/ 25, 0x00, 
  /* ABS: 018 Pixels @ 003,032*/ 0, 18, 0x0B, 0x40, 0x03, 0x18, 0x2F, 0x30, 0x2F, 0x4D, 0x4D, 0x2C, 0x2C, 0x2B, 0x10, 0x10, 0x9F, 0x1D, 0x1D, 0x44, 
  /* RLE: 025 Pixels @ 021,032*/ 25, 0x00, 
  /* ABS: 018 Pixels @ 003,033*/ 0, 18, 0x78, 0x8F, 0x67, 0x18, 0x10, 0x10, 0x3B, 0x7C, 0x1F, 0x7A, 0x8C, 0x17, 0x24, 0x2E, 0x0D, 0x0B, 0x0B, 0x59, 
  /* RLE: 026 Pixels @ 021,033*/ 26, 0x00, 
  /* ABS: 014 Pixels @ 004,034*/ 0, 14, 0x82, 0x66, 0x24, 0x10, 0x10, 0x66, 0x3E, 0x8B, 0x9A, 0x51, 0x02, 0x2E, 0x05, 0x14, 
  /* RLE: 029 Pixels @ 018,034*/ 29, 0x00, 
  /* ABS: 014 Pixels @ 004,035*/ 0, 14, 0x13, 0x79, 0x40, 0x18, 0x18, 0x29, 0x3E, 0x3E, 0x76, 0x8E, 0x02, 0x0D, 0x02, 0x15, 
  /* RLE: 029 Pixels @ 018,035*/ 29, 0x00, 
  /* ABS: 014 Pixels @ 004,036*/ 0, 14, 0x35, 0x13, 0x0E, 0x2E, 0x18, 0x3C, 0x51, 0x1F, 0x76, 0x1B, 0x6A, 0x21, 0x02, 0x14, 
  /* RLE: 029 Pixels @ 018,036*/ 29, 0x00, 
  /* ABS: 011 Pixels @ 004,037*/ 0, 11, 0x15, 0x00, 0x00, 0x0C, 0x3A, 0x2A, 0x39, 0x32, 0x12, 0x1B, 0x2B, 
  /* RLE: 035 Pixels @ 015,037*/ 35, 0x00, 
  /* ABS: 008 Pixels @ 007,038*/ 0, 8, 0x4B, 0x88, 0x15, 0x9C, 0x35, 0x00, 0x8C, 0x54, 
  /* RLE: 200 Pixels @ 015,038*/ 200, 0x00, 


  0};  /* 1000 bytes for 1849 pixels */

GUI_CONST_STORAGE GUI_BITMAP bmsettings_S = {
  43, /* XSize */
  43, /* YSize */
  43, /* BytesPerLine */
  GUI_COMPRESS_RLE8, /* BitsPerPixel */
  acsettings_S,  /* Pointer to picture data (indices) */
  &Palsettings_S,  /* Pointer to palette */
  GUI_DRAW_RLE8
};

/* *** End of file *** */

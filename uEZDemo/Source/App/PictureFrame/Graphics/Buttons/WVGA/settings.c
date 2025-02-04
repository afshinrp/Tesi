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
* Source file: settings                                              *
* Dimensions:  72 * 72                                               *
* NumColors:   222                                                   *
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

static GUI_CONST_STORAGE GUI_COLOR Colorssettings[] = {
     0xFFFFFF,0x636363,0x999999,0x4244C9
    ,0x393CBA,0xB8B9B8,0x4645A9,0x87786F
    ,0x424399,0x928677,0x595957,0x3B37CA
    ,0x040367,0x4745DA,0x968A86,0x141468
    ,0x2727AB,0x4645BA,0x898988,0x060676
    ,0x221872,0x252577,0x7D7364,0x3134CA
    ,0x4B4EF5,0x262667,0x6F6458,0x292797
    ,0xA8A8A5,0xCAC8CA,0x131377,0x31338B
    ,0x7374E6,0x242454,0x3034D9,0x3736ED
    ,0x453FEA,0x443EFC,0x989687,0x383579
    ,0x756C65,0x7B7B7C,0x171689,0x222086
    ,0x292689,0x3131A5,0x3B37DA,0xAAA69B
    ,0xDAD9D9,0x060288,0x4139AF,0x8988E6
    ,0xADACB0,0x3B378A,0x46458A,0x484877
    ,0x293187,0x313194,0x31319C,0x2625B7
    ,0x3233B8,0x3843A8,0x5755A8,0x100E43
    ,0x737370,0x161698,0x293197,0x201EA2
    ,0x42399F,0x010058,0x141357,0x606258
    ,0x7B7B70,0x5656B6,0x403B38,0x312766
    ,0x454545,0x524A43,0x5A5964,0x696775
    ,0x100CA2,0x1815A9,0x3939A5,0x3139AD
    ,0x2931BB,0x3942CA,0x6466D0,0x918FBA
    ,0x585343,0x322997,0x393A9C,0x787893
    ,0x524AB5,0x909494,0xA79C96,0x9CA5A5
    ,0xF7F7F7,0x2F2C2F,0x100858,0x524E51
    ,0x6B6B6B,0x897B7E,0x0D1089,0x312986
    ,0x3931AE,0x545698,0x6764A2,0x9CA59C
    ,0xB7ADAA,0x504938,0x080D5A,0x221858
    ,0x363247,0x333455,0x333365,0x635748
    ,0x6B6B63,0x100686,0x18218C,0x393194
    ,0x635A97,0x5753C9,0xAFA6CE,0xACA9F7
    ,0xE7E7E8,0x182371,0x2B3175,0x575677
    ,0x3D3994,0x31399C,0x3131AD,0x535389
    ,0x4A4B98,0x7777CC,0x8C8A97,0xB5B5AB
    ,0xCED6CB,0xF2EFEE,0x242546,0x081078
    ,0x6B6363,0x7B7373,0x050596,0x0C1094
    ,0x231A92,0x39319C,0x161FB3,0x2931AA
    ,0x727080,0x6B69B7,0x3329D8,0x7B8484
    ,0xA89CA5,0xC6C6BD,0x1A1646,0x13086B
    ,0x484866,0x42527B,0x736B73,0x737B7B
    ,0x4A528C,0x4A52B5,0x4A48CC,0x4A52CE
    ,0xB5ADB5,0xB5BBFD,0xD6CED6,0xEBE9DC
    ,0x2E291B,0x081063,0x293168,0x394263
    ,0x464856,0x564A67,0x635768,0x63636B
    ,0x6B7368,0x737B70,0x3931A5,0x3129B5
    ,0x554AAA,0x2629C9,0x5252DA,0x8C9488
    ,0xD9DECB,0xCECED6,0xE7DEDE,0xCAC6F3
    ,0xFFF7F7,0x101010,0x060626,0x070735
    ,0x242024,0x050542,0x18214D,0x100877
    ,0x31257B,0x42395F,0x5A636B,0x636B6B
    ,0x818476,0x313994,0x3129A5,0x3139A5
    ,0x524A94,0x5246C6,0xD6CECE,0xDEE7DE
    ,0xDEE7EF,0x080800,0x181818,0x4A5252
    ,0x524A7B,0x6B636B,0x7B737B,0x524A8C
    ,0x4E5AAD,0x635AE7,0xCEBDAD,0xB5BDCE
    ,0xC6BDCE,0xF7EFF7
};

static GUI_CONST_STORAGE GUI_LOGPALETTE Palsettings = {
  222,	/* number of entries */
  1, 	/* Has transparency */
  &Colorssettings[0]
};

static GUI_CONST_STORAGE unsigned char acsettings[] = {
  /* RLE: 545 Pixels @ 000,000*/ 254, 0x00, 254, 0x00, 37, 0x00, 
  /* ABS: 005 Pixels @ 041,007*/ 0, 5, 0x35, 0x00, 0x00, 0x00, 0x44, 
  /* RLE: 004 Pixels @ 046,007*/ 4, 0x00, 
  /* RLE: 001 Pixels @ 050,007*/ 1, 0x7E, 
  /* RLE: 057 Pixels @ 051,007*/ 57, 0x00, 
  /* ABS: 019 Pixels @ 036,008*/ 0, 19, 0xC4, 0x35, 0x00, 0x00, 0x00, 0x1B, 0x38, 0x00, 0x15, 0x39, 0x19, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x19, 0x4B, 
  /* RLE: 050 Pixels @ 055,008*/ 50, 0x00, 
  /* ABS: 006 Pixels @ 033,009*/ 0, 6, 0x5A, 0x00, 0x00, 0x15, 0x77, 0x77, 
  /* RLE: 004 Pixels @ 039,009*/ 4, 0x1F, 
  /* ABS: 012 Pixels @ 043,009*/ 0, 12, 0x39, 0x77, 0x38, 0x1F, 0x1F, 0x39, 0x39, 0x1F, 0x6F, 0x19, 0x91, 0x6F, 
  /* RLE: 050 Pixels @ 055,009*/ 50, 0x00, 
  /* ABS: 026 Pixels @ 033,010*/ 0, 26, 0x38, 0x59, 0x77, 0x67, 0x2C, 0x2C, 0x14, 0x14, 0x1E, 0xA9, 0x0C, 0x13, 0x0C, 0x8B, 0x1E, 0x15, 0x15, 0x2C, 0x42, 0x1F, 0x1F, 0x19, 0x00, 0x7E, 0x35, 0x35, 
  /* RLE: 042 Pixels @ 059,010*/ 42, 0x00, 
  /* ABS: 008 Pixels @ 029,011*/ 0, 8, 0x5A, 0x27, 0x27, 0x2C, 0x3A, 0x38, 0x2C, 0x1E, 
  /* RLE: 004 Pixels @ 037,011*/ 4, 0x0C, 
  /* RLE: 006 Pixels @ 041,011*/ 6, 0x45, 
  /* RLE: 003 Pixels @ 047,011*/ 3, 0x0C, 
  /* ABS: 009 Pixels @ 050,011*/ 0, 9, 0x1E, 0x15, 0x38, 0x1F, 0x1B, 0x42, 0x77, 0x15, 0x15, 
  /* RLE: 042 Pixels @ 059,011*/ 42, 0x00, 
  /* ABS: 033 Pixels @ 029,012*/ 0, 33, 0x81, 0x67, 0x67, 0x3A, 0x42, 0x7D, 0x1E, 0x13, 0x0C, 0x62, 0x6F, 0x6F, 0x21, 0x21, 0x8A, 0x21, 0x21, 0x21, 0x46, 0x0F, 0x0F, 0x0F, 0x1E, 0x2B, 0x3A, 0x08, 0x1F, 0x1B, 0x1B, 0x1B, 0x15, 0x67, 0x35, 
  /* RLE: 039 Pixels @ 062,012*/ 39, 0x00, 
  /* ABS: 033 Pixels @ 029,013*/ 0, 33, 0x81, 0x67, 0x67, 0x3A, 0x42, 0x7D, 0x1E, 0x13, 0x0C, 0x62, 0x6F, 0x6F, 0x21, 0x21, 0x8A, 0x21, 0x21, 0x21, 0x46, 0x0F, 0x0F, 0x0F, 0x1E, 0x2B, 0x3A, 0x08, 0x1F, 0x1B, 0x1B, 0x1B, 0x15, 0x67, 0x35, 
  /* RLE: 035 Pixels @ 062,013*/ 35, 0x00, 
  /* ABS: 021 Pixels @ 025,014*/ 0, 21, 0x4B, 0xB4, 0x27, 0x2D, 0x93, 0x38, 0x38, 0x5A, 0x3A, 0x15, 0x14, 0x4B, 0x70, 0x4C, 0x61, 0x61, 0x61, 0x6D, 0x58, 0x6D, 0x6D, 
  /* RLE: 004 Pixels @ 046,014*/ 4, 0x4D, 
  /* ABS: 012 Pixels @ 050,014*/ 0, 12, 0xAC, 0xC5, 0x27, 0x44, 0x49, 0x56, 0x49, 0x39, 0x39, 0x2C, 0x38, 0x7E, 
  /* RLE: 035 Pixels @ 062,014*/ 35, 0x00, 
  /* ABS: 040 Pixels @ 025,015*/ 0, 40, 0x72, 0x85, 0x7E, 0x2D, 0x93, 0x08, 0x08, 0x11, 0x91, 0x72, 0x63, 0x4D, 0xA8, 0xD1, 0xBD, 0xBD, 0xC0, 0x4C, 0x63, 0xAC, 0x63, 0x63, 0x4D, 0x4A, 0x4A, 0x6D, 0x58, 0x58, 0x9C, 0x83, 0x95, 0x33, 0x20, 0x20, 0x35, 
        0x2C, 0x5A, 0x19, 0x4B, 0x7E, 
  /* RLE: 030 Pixels @ 065,015*/ 30, 0x00, 
  /* ABS: 020 Pixels @ 023,016*/ 0, 20, 0x27, 0xAA, 0x1F, 0x0D, 0x1B, 0x52, 0xA2, 0x3E, 0x3E, 0x27, 0xAD, 0xC8, 0x48, 0x4A, 0xD2, 0x70, 0x0A, 0x0A, 0x47, 0x47, 
  /* RLE: 005 Pixels @ 043,016*/ 5, 0x0A, 
  /* ABS: 017 Pixels @ 048,016*/ 0, 17, 0x4E, 0x4E, 0x63, 0x4A, 0x4D, 0x58, 0x4D, 0x4F, 0x33, 0xA5, 0xA5, 0x33, 0xB2, 0x10, 0x39, 0x80, 0x35, 
  /* RLE: 030 Pixels @ 065,016*/ 30, 0x00, 
  /* ABS: 042 Pixels @ 023,017*/ 0, 42, 0x95, 0x85, 0x39, 0x96, 0x42, 0x11, 0xD9, 0x37, 0x37, 0x16, 0xB8, 0xA4, 0x27, 0x00, 0xD3, 0x8C, 0x01, 0x01, 0x4E, 0x4E, 0xD5, 0xD6, 0x40, 0x01, 0x0A, 0x0A, 0x0A, 0x01, 0x0A, 0x4C, 0x4D, 0x73, 0x6D, 0x0A, 0x57, 
        0x57, 0xBB, 0x20, 0x82, 0x15, 0x84, 0x27, 
  /* RLE: 030 Pixels @ 065,017*/ 30, 0x00, 
  /* ABS: 025 Pixels @ 023,018*/ 0, 25, 0x3E, 0x7B, 0x3D, 0x17, 0xC9, 0x06, 0xD7, 0x07, 0x07, 0x89, 0x7B, 0x00, 0x00, 0x00, 0x74, 0xAE, 0x01, 0x01, 0x01, 0x12, 0x34, 0x63, 0x0A, 0x1C, 0x29, 
  /* RLE: 004 Pixels @ 048,018*/ 4, 0x01, 
  /* ABS: 016 Pixels @ 052,018*/ 0, 16, 0x4E, 0x4C, 0x58, 0x73, 0x58, 0x63, 0x63, 0x57, 0x7B, 0x79, 0xC4, 0x04, 0x2D, 0x38, 0x80, 0x80, 
  /* RLE: 024 Pixels @ 068,018*/ 24, 0x00, 
  /* ABS: 017 Pixels @ 020,019*/ 0, 17, 0x72, 0x08, 0x08, 0xCA, 0x23, 0x54, 0x22, 0x04, 0x7F, 0x58, 0x98, 0x98, 0x7A, 0x00, 0x00, 0x00, 0xB0, 
  /* RLE: 004 Pixels @ 037,019*/ 4, 0x01, 
  /* ABS: 014 Pixels @ 041,019*/ 0, 14, 0x02, 0x60, 0x7C, 0x00, 0x00, 0x89, 0x30, 0x12, 0x12, 0x01, 0x01, 0x64, 0x0A, 0x4C, 
  /* RLE: 004 Pixels @ 055,019*/ 4, 0x73, 
  /* ABS: 009 Pixels @ 059,019*/ 0, 9, 0x4D, 0x57, 0x33, 0x81, 0x54, 0x42, 0x84, 0x36, 0x36, 
  /* RLE: 024 Pixels @ 068,019*/ 24, 0x00, 
  /* ABS: 048 Pixels @ 020,020*/ 0, 48, 0x37, 0x33, 0x33, 0x56, 0x23, 0x3C, 0x3B, 0x32, 0x73, 0x1A, 0x4F, 0x4F, 0x6F, 0x00, 0x00, 0x0A, 0x9E, 0x4F, 0x47, 0x29, 0x29, 0x60, 0x00, 0x30, 0x00, 0x00, 0x60, 0x00, 0xA6, 0xA6, 0x64, 0x01, 0x01, 0x01, 0x4C, 
        0x28, 0x4A, 0xA8, 0xA8, 0x1A, 0x8C, 0x95, 0x03, 0x54, 0x3A, 0x5C, 0x1F, 0x1F, 
  /* RLE: 024 Pixels @ 068,020*/ 24, 0x00, 
  /* ABS: 024 Pixels @ 020,021*/ 0, 24, 0x19, 0x20, 0x20, 0x20, 0x23, 0xB3, 0x15, 0xAD, 0x1A, 0x1A, 0x47, 0x47, 0x58, 0x6D, 0x4C, 0x01, 0x40, 0x74, 0x0A, 0x1C, 0x1C, 0x00, 0x00, 0x30, 
  /* RLE: 006 Pixels @ 044,021*/ 6, 0x00, 
  /* ABS: 019 Pixels @ 050,021*/ 0, 19, 0x12, 0x01, 0x74, 0x01, 0x4E, 0x34, 0x00, 0x00, 0x00, 0xA6, 0x2F, 0x7F, 0xB6, 0x53, 0x2D, 0x22, 0x2D, 0x2D, 0x80, 
  /* RLE: 023 Pixels @ 069,021*/ 23, 0x00, 
  /* ABS: 024 Pixels @ 020,022*/ 0, 24, 0x19, 0x20, 0x20, 0x20, 0x23, 0xB3, 0x15, 0xAD, 0x1A, 0x1A, 0x47, 0x47, 0x58, 0x6D, 0x4C, 0x01, 0x40, 0x74, 0x0A, 0x1C, 0x1C, 0x00, 0x00, 0x30, 
  /* RLE: 006 Pixels @ 044,022*/ 6, 0x00, 
  /* ABS: 019 Pixels @ 050,022*/ 0, 19, 0x12, 0x01, 0x74, 0x01, 0x4E, 0x34, 0x00, 0x00, 0x00, 0xA6, 0x2F, 0x7F, 0xB6, 0x53, 0x2D, 0x22, 0x2D, 0x2D, 0x80, 
  /* RLE: 023 Pixels @ 069,022*/ 23, 0x00, 
  /* ABS: 049 Pixels @ 020,023*/ 0, 49, 0x52, 0x96, 0x96, 0x96, 0x23, 0x0B, 0x7E, 0x47, 0x1A, 0x01, 0x1A, 0x1A, 0x1A, 0x28, 0x8D, 0x01, 0xB0, 0xB0, 0x01, 0x12, 0x12, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x05, 0x00, 0x60, 0x60, 0x29, 0x01, 0x64, 0x9E, 0xAF, 
        0x4A, 0x00, 0x00, 0x00, 0x57, 0xDD, 0x28, 0x06, 0x1F, 0x82, 0x17, 0x42, 0x42, 0x77, 
  /* RLE: 023 Pixels @ 069,023*/ 23, 0x00, 
  /* ABS: 022 Pixels @ 020,024*/ 0, 22, 0x56, 0x2E, 0x2E, 0x18, 0x17, 0x93, 0x27, 0x1A, 0x28, 0x74, 0x1A, 0x1A, 0x8C, 0x1A, 0x26, 0x94, 0x4F, 0x40, 0x9E, 0xAF, 0xAF, 0x1D, 
  /* RLE: 004 Pixels @ 042,024*/ 4, 0x00, 
  /* ABS: 010 Pixels @ 046,024*/ 0, 10, 0x1C, 0x00, 0x05, 0x05, 0x01, 0x4F, 0x4F, 0x9E, 0x8C, 0x4A, 
  /* RLE: 004 Pixels @ 056,024*/ 4, 0x00, 
  /* ABS: 009 Pixels @ 060,024*/ 0, 9, 0x7A, 0x26, 0x9C, 0x59, 0x17, 0x0B, 0x2D, 0x2D, 0xC9, 
  /* RLE: 023 Pixels @ 069,024*/ 23, 0x00, 
  /* ABS: 008 Pixels @ 020,025*/ 0, 8, 0x56, 0x0B, 0x0B, 0x18, 0x04, 0x38, 0xD4, 0x1A, 
  /* RLE: 005 Pixels @ 028,025*/ 5, 0x28, 
  /* ABS: 009 Pixels @ 033,025*/ 0, 9, 0x47, 0x6C, 0x1C, 0x64, 0x40, 0x29, 0x40, 0x40, 0x64, 
  /* RLE: 004 Pixels @ 042,025*/ 4, 0x00, 
  /* ABS: 010 Pixels @ 046,025*/ 0, 10, 0x98, 0x1C, 0x01, 0x01, 0x40, 0x40, 0x94, 0xC7, 0x12, 0x16, 
  /* RLE: 005 Pixels @ 056,025*/ 5, 0x00, 
  /* ABS: 008 Pixels @ 061,025*/ 0, 8, 0x07, 0xAE, 0x3A, 0x0B, 0x17, 0x0B, 0x0B, 0x04, 
  /* RLE: 023 Pixels @ 069,025*/ 23, 0x00, 
  /* ABS: 019 Pixels @ 020,026*/ 0, 19, 0x0D, 0x22, 0x22, 0x23, 0x2E, 0x3A, 0xAE, 0x16, 0x28, 0x28, 0x16, 0x16, 0x28, 0x1A, 0x6C, 0x89, 0x12, 0x29, 0x29, 
  /* RLE: 004 Pixels @ 039,026*/ 4, 0x48, 
  /* ABS: 013 Pixels @ 043,026*/ 0, 13, 0x64, 0x0A, 0x0A, 0x64, 0x74, 0xB1, 0xB1, 0xB1, 0x40, 0x29, 0x9F, 0x1D, 0x8D, 
  /* RLE: 006 Pixels @ 056,026*/ 6, 0x00, 
  /* ABS: 007 Pixels @ 062,026*/ 0, 7, 0x8C, 0x39, 0x3A, 0x04, 0x43, 0x43, 0x50, 
  /* RLE: 023 Pixels @ 069,026*/ 23, 0x00, 
  /* ABS: 036 Pixels @ 020,027*/ 0, 36, 0x23, 0x92, 0x92, 0x22, 0x04, 0x2D, 0x78, 0x16, 0x16, 0x28, 0x16, 0x16, 0x16, 0x1A, 0x2F, 0x00, 0xBA, 0x5D, 0x12, 0x97, 0x97, 0x29, 0x29, 0x65, 0x97, 0x12, 0x29, 0x29, 0x9F, 0x9F, 0x29, 0x12, 0x29, 0x30, 0xA7, 
        0x28, 
  /* RLE: 006 Pixels @ 056,027*/ 6, 0x00, 
  /* ABS: 007 Pixels @ 062,027*/ 0, 7, 0x1A, 0x80, 0x2D, 0x0B, 0x10, 0x10, 0x31, 
  /* RLE: 023 Pixels @ 069,027*/ 23, 0x00, 
  /* ABS: 008 Pixels @ 020,028*/ 0, 8, 0x0D, 0x8E, 0x8E, 0x17, 0x3D, 0x3A, 0x84, 0x8D, 
  /* RLE: 005 Pixels @ 028,028*/ 5, 0x16, 
  /* ABS: 023 Pixels @ 033,028*/ 0, 23, 0x28, 0x26, 0xBC, 0x00, 0x7C, 0x1C, 0x02, 0x02, 0x02, 0x5D, 0x12, 0x12, 0x12, 0xB7, 0x5D, 0x02, 0x02, 0x86, 0x97, 0xB9, 0x00, 0x99, 0x1A, 
  /* RLE: 006 Pixels @ 056,028*/ 6, 0x00, 
  /* ABS: 007 Pixels @ 062,028*/ 0, 7, 0x01, 0x06, 0x82, 0x0B, 0x0B, 0x0B, 0x17, 
  /* RLE: 023 Pixels @ 069,028*/ 23, 0x00, 
  /* ABS: 010 Pixels @ 020,029*/ 0, 10, 0x0D, 0x54, 0x54, 0x24, 0x32, 0x81, 0x0B, 0x94, 0x07, 0x48, 
  /* RLE: 004 Pixels @ 030,029*/ 4, 0x07, 
  /* ABS: 022 Pixels @ 034,029*/ 0, 22, 0x40, 0x30, 0x00, 0x00, 0x60, 0x57, 0x57, 0x7F, 0x5B, 0x02, 0x02, 0x5D, 0x86, 0x5B, 0x4E, 0x4E, 0x4E, 0x30, 0x00, 0x00, 0x02, 0x1A, 
  /* RLE: 006 Pixels @ 056,029*/ 6, 0x00, 
  /* ABS: 007 Pixels @ 062,029*/ 0, 7, 0x4F, 0x52, 0x68, 0x10, 0x2A, 0x2A, 0x92, 
  /* RLE: 023 Pixels @ 069,029*/ 23, 0x00, 
  /* ABS: 008 Pixels @ 020,030*/ 0, 8, 0x79, 0x3B, 0x3B, 0x3B, 0x10, 0x08, 0x54, 0x79, 
  /* RLE: 004 Pixels @ 028,030*/ 4, 0x07, 
  /* ABS: 024 Pixels @ 032,030*/ 0, 24, 0x48, 0x48, 0x07, 0x0E, 0x60, 0x00, 0x00, 0x7A, 0x7A, 0xAB, 0x3F, 0x3F, 0x71, 0x70, 0x61, 0x61, 0x0A, 0x0A, 0x05, 0x00, 0x00, 0x1D, 0x16, 0x16, 
  /* RLE: 006 Pixels @ 056,030*/ 6, 0x00, 
  /* ABS: 007 Pixels @ 062,030*/ 0, 7, 0x69, 0x2D, 0x68, 0x3B, 0x13, 0x13, 0x31, 
  /* RLE: 023 Pixels @ 069,030*/ 23, 0x00, 
  /* ABS: 008 Pixels @ 020,031*/ 0, 8, 0x79, 0x3B, 0x3B, 0x3B, 0x10, 0x08, 0x54, 0x79, 
  /* RLE: 004 Pixels @ 028,031*/ 4, 0x07, 
  /* ABS: 024 Pixels @ 032,031*/ 0, 24, 0x48, 0x48, 0x07, 0x0E, 0x60, 0x00, 0x00, 0x7A, 0x7A, 0xAB, 0x3F, 0x3F, 0x71, 0x70, 0x61, 0x61, 0x0A, 0x0A, 0x05, 0x00, 0x00, 0x1D, 0x16, 0x16, 
  /* RLE: 006 Pixels @ 056,031*/ 6, 0x00, 
  /* ABS: 007 Pixels @ 062,031*/ 0, 7, 0x69, 0x2D, 0x68, 0x3B, 0x13, 0x13, 0x31, 
  /* RLE: 023 Pixels @ 069,031*/ 23, 0x00, 
  /* ABS: 037 Pixels @ 020,032*/ 0, 37, 0x79, 0x50, 0x50, 0x31, 0x92, 0x32, 0x52, 0x23, 0x6A, 0x09, 0x07, 0x07, 0x48, 0x16, 0x16, 0x28, 0x5E, 0x60, 0x00, 0x34, 0x34, 0x70, 0xBE, 0xBE, 0x70, 0x8D, 0x28, 0x09, 0x2F, 0x2F, 0xA7, 0x00, 0x30, 0xC8, 0x8D, 
        0x65, 0x40, 
  /* RLE: 004 Pixels @ 057,032*/ 4, 0x00, 
  /* ABS: 008 Pixels @ 061,032*/ 0, 8, 0x6A, 0x04, 0x81, 0x32, 0x03, 0x54, 0x54, 0x43, 
  /* RLE: 023 Pixels @ 069,032*/ 23, 0x00, 
  /* ABS: 049 Pixels @ 020,033*/ 0, 49, 0x06, 0x51, 0x51, 0x50, 0x2E, 0x03, 0x44, 0x2E, 0x24, 0x5B, 0x09, 0x09, 0x02, 0x00, 0x00, 0x6C, 0x0E, 0x12, 0x30, 0xBC, 0xBC, 0x5E, 0x4A, 0xC0, 0x4A, 0x09, 0x65, 0x0E, 0x6C, 0x6C, 0xA7, 0x1D, 0x07, 0x07, 0x65, 
        0x07, 0x07, 0x09, 0x09, 0x09, 0x97, 0x0D, 0x3C, 0x81, 0x2A, 0x41, 0x10, 0x10, 0x68, 
  /* RLE: 021 Pixels @ 069,033*/ 21, 0x00, 
  /* ABS: 015 Pixels @ 018,034*/ 0, 15, 0x21, 0x00, 0x00, 0x1B, 0x1B, 0x3C, 0x17, 0x41, 0x2B, 0x03, 0x23, 0x24, 0x57, 0x57, 0x26, 
  /* RLE: 004 Pixels @ 033,034*/ 4, 0x00, 
  /* ABS: 032 Pixels @ 037,034*/ 0, 32, 0x2F, 0x65, 0x2F, 0x2F, 0xDA, 0x5E, 0x0E, 0x0E, 0x09, 0x09, 0x0E, 0x5E, 0x5E, 0x26, 0x07, 0x65, 0x65, 0x09, 0x09, 0x65, 0x09, 0x09, 0x29, 0x0D, 0x17, 0x3D, 0x32, 0x8F, 0x13, 0x31, 0x31, 0x2C, 
  /* RLE: 015 Pixels @ 069,034*/ 15, 0x00, 
  /* ABS: 021 Pixels @ 012,035*/ 0, 21, 0x21, 0x21, 0x9A, 0x00, 0x00, 0x9A, 0x06, 0x21, 0x00, 0x39, 0x39, 0x3C, 0x17, 0x31, 0x76, 0x03, 0x23, 0x25, 0x18, 0x18, 0x19, 
  /* RLE: 005 Pixels @ 033,035*/ 5, 0x00, 
  /* ABS: 008 Pixels @ 038,035*/ 0, 8, 0x1C, 0x47, 0x47, 0x07, 0x09, 0x0E, 0x12, 0x0E, 
  /* RLE: 004 Pixels @ 046,035*/ 4, 0x09, 
  /* RLE: 001 Pixels @ 050,035*/ 1, 0x07, 
  /* RLE: 006 Pixels @ 051,035*/ 6, 0x09, 
  /* ABS: 012 Pixels @ 057,035*/ 0, 12, 0x5B, 0x5B, 0x0D, 0x22, 0x53, 0x42, 0x0B, 0x55, 0x8F, 0x75, 0x75, 0x19, 
  /* RLE: 015 Pixels @ 069,035*/ 15, 0x00, 
  /* ABS: 022 Pixels @ 012,036*/ 0, 22, 0x35, 0x35, 0x06, 0x00, 0x00, 0x21, 0xCB, 0x19, 0x00, 0x42, 0x42, 0x2E, 0x0B, 0x43, 0x0B, 0x04, 0x17, 0x2E, 0x25, 0x25, 0x23, 0x67, 
  /* RLE: 009 Pixels @ 034,036*/ 9, 0x00, 
  /* ABS: 002 Pixels @ 043,036*/ 0, 2, 0x4C, 0x5E, 
  /* RLE: 007 Pixels @ 045,036*/ 7, 0x0E, 
  /* ABS: 016 Pixels @ 052,036*/ 0, 16, 0x09, 0x0E, 0x0E, 0x12, 0x6A, 0x0D, 0x0D, 0x23, 0x11, 0x91, 0x0C, 0x41, 0x10, 0xCA, 0x13, 0x13, 
  /* RLE: 016 Pixels @ 068,036*/ 16, 0x00, 
  /* ABS: 024 Pixels @ 012,037*/ 0, 24, 0x4B, 0x4B, 0x35, 0xC5, 0x4C, 0x01, 0x4F, 0x4F, 0xAC, 0x27, 0x27, 0x04, 0x3B, 0x54, 0x17, 0x3C, 0x3C, 0x24, 0x23, 0x23, 0x25, 0x25, 0x03, 0x46, 
  /* RLE: 008 Pixels @ 036,037*/ 8, 0x00, 
  /* ABS: 004 Pixels @ 044,037*/ 0, 4, 0xCE, 0x6C, 0x0E, 0x0E, 
  /* RLE: 004 Pixels @ 048,037*/ 4, 0x26, 
  /* ABS: 016 Pixels @ 052,037*/ 0, 16, 0x0E, 0x0E, 0x6A, 0x11, 0x2E, 0x22, 0x22, 0x55, 0x11, 0x32, 0x8B, 0x31, 0x31, 0x41, 0x46, 0x46, 
  /* RLE: 012 Pixels @ 068,037*/ 12, 0x00, 
  /* ABS: 060 Pixels @ 008,038*/ 0, 60, 0x08, 0x35, 0x00, 0x00, 0x71, 0x71, 0x94, 0x86, 0x02, 0x2F, 0x6B, 0x6B, 0x02, 0x5D, 0x5D, 0x9F, 0x27, 0x82, 0x96, 0x03, 0x03, 0x24, 0x25, 0x25, 0x2E, 0x2E, 0x24, 0x24, 0x68, 0x15, 0x5B, 0x5B, 0x5B, 0x61, 0x00, 
        0x00, 0x4A, 0x2F, 0x26, 0x26, 0x0E, 0x0E, 0x86, 0x5B, 0x6A, 0x11, 0x2E, 0x2E, 0x55, 0x04, 0x04, 0x41, 0x1B, 0x11, 0x04, 0x75, 0x31, 0x2B, 0x3F, 0x3F, 
  /* RLE: 012 Pixels @ 068,038*/ 12, 0x00, 
  /* ABS: 058 Pixels @ 008,039*/ 0, 58, 0x3E, 0x3D, 0x38, 0x0A, 0x26, 0x26, 0x02, 0x6B, 0x5E, 0x02, 0x5F, 0x5F, 0x02, 0x2F, 0x2F, 0x2F, 0x26, 0x37, 0x0B, 0x03, 0x55, 0x24, 0x22, 0x22, 0x50, 0x10, 0x0D, 0x0B, 0x0D, 0x03, 0x3C, 0x44, 0x44, 0x5A, 0x27, 
        0x19, 0x7D, 0x69, 0x49, 0xA1, 0x5C, 0x5C, 0x03, 0x2E, 0x0B, 0x17, 0x17, 0x53, 0x04, 0x04, 0x04, 0x13, 0x2A, 0x51, 0x10, 0x13, 0x0F, 0x3F, 
  /* RLE: 014 Pixels @ 066,039*/ 14, 0x00, 
  /* ABS: 058 Pixels @ 008,040*/ 0, 58, 0x3E, 0x3D, 0x38, 0x0A, 0x26, 0x26, 0x02, 0x6B, 0x5E, 0x02, 0x5F, 0x5F, 0x02, 0x2F, 0x2F, 0x2F, 0x26, 0x37, 0x0B, 0x03, 0x55, 0x24, 0x22, 0x22, 0x50, 0x10, 0x0D, 0x0B, 0x0D, 0x03, 0x3C, 0x44, 0x44, 0x5A, 0x27, 
        0x19, 0x7D, 0x69, 0x49, 0xA1, 0x5C, 0x5C, 0x03, 0x2E, 0x0B, 0x17, 0x17, 0x53, 0x04, 0x04, 0x04, 0x13, 0x2A, 0x51, 0x10, 0x13, 0x0F, 0x3F, 
  /* RLE: 014 Pixels @ 066,040*/ 14, 0x00, 
  /* ABS: 033 Pixels @ 008,041*/ 0, 33, 0x3E, 0x06, 0x9C, 0x6B, 0x6B, 0x6B, 0x1C, 0x6C, 0x02, 0x00, 0x00, 0x05, 0x05, 0x02, 0x02, 0x34, 0x1C, 0x02, 0x9D, 0x03, 0x24, 0xB5, 0x43, 0x43, 0x3B, 0x3B, 0x03, 0x06, 0x76, 0x04, 0x03, 0x55, 0x55, 
  /* RLE: 004 Pixels @ 041,041*/ 4, 0x03, 
  /* ABS: 020 Pixels @ 045,041*/ 0, 20, 0x2E, 0x0B, 0x17, 0x0B, 0x0B, 0x04, 0x53, 0x53, 0x06, 0x2B, 0x76, 0x11, 0x03, 0x03, 0x76, 0x76, 0x50, 0x8F, 0x13, 0x0F, 
  /* RLE: 012 Pixels @ 065,041*/ 12, 0x00, 
  /* ABS: 060 Pixels @ 005,042*/ 0, 60, 0x72, 0x19, 0x21, 0x08, 0x08, 0xB7, 0x1C, 0x98, 0x98, 0x1C, 0x89, 0x7C, 0x00, 0x00, 0xB9, 0x00, 0x88, 0x88, 0x02, 0x1C, 0x87, 0x94, 0x44, 0x24, 0x55, 0x03, 0x03, 0x03, 0x2E, 0x0D, 0x68, 0x1E, 0x5A, 0x06, 0x08, 
        0x08, 0x2B, 0x5A, 0x06, 0x11, 0x59, 0x39, 0x08, 0x06, 0x06, 0x15, 0x15, 0x06, 0x32, 0x2C, 0x2C, 0xA1, 0x17, 0x17, 0x10, 0x76, 0x75, 0x8B, 0x9B, 0x46, 
  /* RLE: 012 Pixels @ 065,042*/ 12, 0x00, 
  /* ABS: 057 Pixels @ 005,043*/ 0, 57, 0x85, 0x52, 0x3D, 0x35, 0xC7, 0x1C, 0x1C, 0x5F, 0x5F, 0x89, 0x00, 0x5D, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x05, 0x02, 0xA4, 0x6B, 0x36, 0x0D, 0x55, 0x3C, 0x3C, 0x82, 0x03, 0x43, 0x42, 0x1E, 0x06, 0xB4, 0x08, 
        0x08, 0x0F, 0x06, 0x84, 0x36, 0x7D, 0x36, 0x3E, 0x08, 0x08, 0x14, 0x1F, 0x85, 0x5C, 0x10, 0x3A, 0x5C, 0x51, 0x51, 0x43, 0x14, 0x9B, 
  /* RLE: 015 Pixels @ 062,043*/ 15, 0x00, 
  /* ABS: 011 Pixels @ 005,044*/ 0, 11, 0x33, 0x95, 0x08, 0x37, 0x12, 0x34, 0x02, 0x05, 0x05, 0x00, 0x30, 
  /* RLE: 007 Pixels @ 016,044*/ 7, 0x00, 
  /* ABS: 039 Pixels @ 023,044*/ 0, 39, 0x7C, 0x02, 0x05, 0x6C, 0x83, 0x0D, 0x17, 0x41, 0x41, 0x2D, 0x3C, 0x66, 0x39, 0x1E, 0x3D, 0x3D, 0x08, 0x08, 0x1E, 0x3E, 0xB4, 0x08, 0x0F, 0x3E, 0x85, 0x08, 0x08, 0x1E, 0x08, 0x33, 0x3C, 0x41, 0x52, 0x06, 0x66, 
        0x66, 0x2B, 0x2A, 0x1E, 
  /* RLE: 015 Pixels @ 062,044*/ 15, 0x00, 
  /* ABS: 011 Pixels @ 005,045*/ 0, 11, 0x6A, 0x20, 0x04, 0x37, 0x02, 0x05, 0x02, 0x99, 0x99, 0x00, 0x88, 
  /* RLE: 007 Pixels @ 016,045*/ 7, 0x00, 
  /* ABS: 007 Pixels @ 023,045*/ 0, 7, 0x30, 0x02, 0x05, 0x87, 0x6A, 0xA2, 0x03, 
  /* RLE: 004 Pixels @ 030,045*/ 4, 0x04, 
  /* ABS: 025 Pixels @ 034,045*/ 0, 25, 0x2A, 0x1B, 0x2A, 0x11, 0x2B, 0x52, 0x52, 0x14, 0x49, 0x5C, 0x2C, 0x0F, 0x49, 0x33, 0x59, 0x59, 0x1E, 0x49, 0x33, 0x43, 0x41, 0x5C, 0x2D, 0x6E, 0x6E, 
  /* RLE: 016 Pixels @ 059,045*/ 16, 0x00, 
  /* ABS: 013 Pixels @ 003,046*/ 0, 13, 0xAA, 0xAA, 0x06, 0x24, 0x2E, 0x7F, 0x26, 0x05, 0x5F, 0x34, 0x34, 0x00, 0x30, 
  /* RLE: 007 Pixels @ 016,046*/ 7, 0x00, 
  /* ABS: 036 Pixels @ 023,046*/ 0, 36, 0x05, 0x34, 0x1D, 0x87, 0x86, 0x11, 0x04, 0x0D, 0x0D, 0xA3, 0x55, 0x43, 0x1F, 0x0F, 0x44, 0x2B, 0x53, 0x53, 0x90, 0x56, 0x3D, 0x90, 0x90, 0x56, 0x20, 0x2B, 0x2B, 0x2A, 0x56, 0x20, 0x2A, 0x3F, 0x36, 0x82, 0x62, 
        0x62, 
  /* RLE: 015 Pixels @ 059,046*/ 15, 0x00, 
  /* ABS: 015 Pixels @ 002,047*/ 0, 15, 0x19, 0x06, 0x06, 0xCB, 0x25, 0x24, 0x6A, 0xB7, 0x05, 0x05, 0x02, 0x02, 0xCE, 0x00, 0x64, 
  /* RLE: 004 Pixels @ 017,047*/ 4, 0x00, 
  /* ABS: 038 Pixels @ 021,047*/ 0, 38, 0xA4, 0xA4, 0x1C, 0x05, 0x88, 0x2F, 0x7A, 0xA1, 0x04, 0x10, 0x10, 0x41, 0x8E, 0x90, 0x21, 0x00, 0xC2, 0x1B, 0x08, 0x08, 0x46, 0x49, 0x3D, 0x38, 0x0F, 0x56, 0x20, 0x0F, 0x0F, 0x00, 0x49, 0x20, 0x1E, 0x00, 0x00, 
        0x0F, 0x3F, 0x3F, 
  /* RLE: 016 Pixels @ 059,047*/ 16, 0x00, 
  /* ABS: 014 Pixels @ 003,048*/ 0, 14, 0x14, 0x14, 0xA9, 0x43, 0x24, 0x56, 0x02, 0x87, 0x1D, 0x05, 0x05, 0x5F, 0x05, 0x29, 
  /* RLE: 004 Pixels @ 017,048*/ 4, 0x00, 
  /* ABS: 033 Pixels @ 021,048*/ 0, 33, 0x34, 0x34, 0x1D, 0x1D, 0x05, 0x05, 0x7B, 0x3D, 0x32, 0x31, 0x31, 0x45, 0x13, 0x62, 0x00, 0x00, 0x8A, 0x1B, 0x4B, 0x4B, 0x00, 0x71, 0x11, 0x14, 0x00, 0x37, 0x20, 0x6E, 0x6E, 0x00, 0x00, 0x3E, 0x14, 
  /* RLE: 021 Pixels @ 054,048*/ 21, 0x00, 
  /* ABS: 014 Pixels @ 003,049*/ 0, 14, 0x14, 0x14, 0xA9, 0x43, 0x24, 0x56, 0x02, 0x87, 0x1D, 0x05, 0x05, 0x5F, 0x05, 0x29, 
  /* RLE: 004 Pixels @ 017,049*/ 4, 0x00, 
  /* ABS: 033 Pixels @ 021,049*/ 0, 33, 0x34, 0x34, 0x1D, 0x1D, 0x05, 0x05, 0x7B, 0x3D, 0x32, 0x31, 0x31, 0x45, 0x13, 0x62, 0x00, 0x00, 0x8A, 0x1B, 0x4B, 0x4B, 0x00, 0x71, 0x11, 0x14, 0x00, 0x37, 0x20, 0x6E, 0x6E, 0x00, 0x00, 0x3E, 0x14, 
  /* RLE: 021 Pixels @ 054,049*/ 21, 0x00, 
  /* ABS: 036 Pixels @ 003,050*/ 0, 36, 0x14, 0x14, 0x9B, 0x2B, 0x0D, 0xCD, 0xDB, 0x02, 0xDC, 0x1D, 0x1D, 0x05, 0x05, 0x1C, 0x12, 0x12, 0x1C, 0x1D, 0x1D, 0x1D, 0x30, 0x1D, 0x5E, 0x7C, 0x85, 0x52, 0xCD, 0x32, 0x32, 0x0F, 0x6E, 0x00, 0x00, 0x00, 0x9A, 
        0x14, 
  /* RLE: 004 Pixels @ 039,050*/ 4, 0x00, 
  /* ABS: 007 Pixels @ 043,050*/ 0, 7, 0x06, 0x62, 0x00, 0x00, 0x84, 0x46, 0x46, 
  /* RLE: 025 Pixels @ 050,050*/ 25, 0x00, 
  /* ABS: 031 Pixels @ 003,051*/ 0, 31, 0x15, 0x15, 0x04, 0xA2, 0x11, 0xB2, 0x33, 0x88, 0x02, 0x99, 0x99, 0x30, 0x1D, 0xB9, 0x30, 0x30, 0xBA, 0xBA, 0xCF, 0xCF, 0x87, 0x12, 0x89, 0xA5, 0xA2, 0x11, 0x11, 0xA3, 0xA3, 0xA3, 0x2B, 
  /* RLE: 041 Pixels @ 034,051*/ 41, 0x00, 
  /* ABS: 031 Pixels @ 003,052*/ 0, 31, 0x44, 0x44, 0x24, 0x0B, 0x3C, 0x3D, 0x03, 0xA5, 0xA7, 0x5D, 0x5D, 0x86, 0x1D, 0xB8, 0x30, 0xB8, 0x88, 0x34, 0xC6, 0xC6, 0xAB, 0xBB, 0xBB, 0x18, 0x24, 0x7D, 0x8B, 0x50, 0x50, 0x41, 0x2C, 
  /* RLE: 041 Pixels @ 034,052*/ 41, 0x00, 
  /* ABS: 031 Pixels @ 003,053*/ 0, 31, 0x0F, 0x0F, 0x8F, 0x31, 0x31, 0x11, 0x11, 0x24, 0x7B, 0xD0, 0xD0, 0x57, 0x36, 0x70, 0x9C, 0x37, 0x8A, 0x14, 0x06, 0x06, 0x33, 0x33, 0x18, 0x25, 0x18, 0x2B, 0x0C, 0x13, 0x13, 0x0C, 0x46, 
  /* RLE: 043 Pixels @ 034,053*/ 43, 0x00, 
  /* ABS: 029 Pixels @ 005,054*/ 0, 29, 0x0C, 0x0C, 0x66, 0x0D, 0x03, 0x18, 0x25, 0x20, 0x20, 0x7B, 0x20, 0x44, 0x91, 0x91, 0x36, 0x3E, 0x49, 0x49, 0x3E, 0x32, 0x0D, 0x18, 0x18, 0x03, 0xC3, 0x45, 0x45, 0x45, 0x3F, 
  /* RLE: 043 Pixels @ 034,054*/ 43, 0x00, 
  /* ABS: 029 Pixels @ 005,055*/ 0, 29, 0x0C, 0x0C, 0x11, 0x18, 0x32, 0xB5, 0x25, 0x25, 0x25, 0x0D, 0xD8, 0x69, 0x36, 0x36, 0xA0, 0xA0, 0x9D, 0x9D, 0x84, 0x11, 0x51, 0x23, 0x18, 0xB6, 0x93, 0x0C, 0x0C, 0x0C, 0x46, 
  /* RLE: 043 Pixels @ 034,055*/ 43, 0x00, 
  /* ABS: 029 Pixels @ 005,056*/ 0, 29, 0x62, 0x90, 0x0D, 0xB5, 0x8F, 0x50, 0x25, 0x18, 0x18, 0x18, 0x52, 0x37, 0x7F, 0x37, 0x9D, 0x72, 0x36, 0x36, 0xCC, 0x11, 0x51, 0x23, 0x22, 0x10, 0x10, 0x0C, 0x0C, 0x0C, 0x9A, 
  /* RLE: 044 Pixels @ 034,056*/ 44, 0x00, 
  /* ABS: 024 Pixels @ 006,057*/ 0, 24, 0x2B, 0x68, 0x8E, 0x66, 0x75, 0x23, 0x18, 0x18, 0x18, 0x66, 0x27, 0x83, 0x36, 0x72, 0xBF, 0x78, 0x78, 0x69, 0x06, 0x51, 0x22, 0x04, 0x2A, 0x14, 
  /* RLE: 048 Pixels @ 030,057*/ 48, 0x00, 
  /* ABS: 024 Pixels @ 006,058*/ 0, 24, 0x2B, 0x68, 0x8E, 0x66, 0x75, 0x23, 0x18, 0x18, 0x18, 0x66, 0x27, 0x83, 0x36, 0x72, 0xBF, 0x78, 0x78, 0x69, 0x06, 0x51, 0x22, 0x04, 0x2A, 0x14, 
  /* RLE: 049 Pixels @ 030,058*/ 49, 0x00, 
  /* ABS: 023 Pixels @ 007,059*/ 0, 23, 0x35, 0x13, 0x8B, 0x1E, 0x0D, 0x25, 0x25, 0x25, 0x41, 0x19, 0x83, 0x83, 0x71, 0xC1, 0x78, 0x78, 0x95, 0x06, 0x92, 0x10, 0x06, 0x2A, 0x19, 
  /* RLE: 049 Pixels @ 030,059*/ 49, 0x00, 
  /* ABS: 023 Pixels @ 007,060*/ 0, 23, 0x27, 0x2A, 0x13, 0x2A, 0x17, 0x22, 0x22, 0x25, 0x3B, 0x0F, 0x69, 0x37, 0x21, 0xC1, 0xA0, 0xA0, 0x33, 0x93, 0x1E, 0x2C, 0x06, 0x1B, 0x14, 
  /* RLE: 050 Pixels @ 030,060*/ 50, 0x00, 
  /* ABS: 017 Pixels @ 008,061*/ 0, 17, 0x59, 0x75, 0x9B, 0x76, 0x10, 0x10, 0x53, 0xB3, 0x2A, 0x11, 0x15, 0x2C, 0xC3, 0x32, 0x32, 0x33, 0x1B, 
  /* RLE: 055 Pixels @ 025,061*/ 55, 0x00, 
  /* ABS: 017 Pixels @ 008,062*/ 0, 17, 0x19, 0x00, 0x00, 0x00, 0x1B, 0x1B, 0x3A, 0x5A, 0x0F, 0x77, 0x1E, 0x59, 0x0F, 0x19, 0x19, 0x33, 0x32, 
  /* RLE: 059 Pixels @ 025,062*/ 59, 0x00, 
  /* ABS: 013 Pixels @ 012,063*/ 0, 13, 0x59, 0x59, 0xB2, 0x19, 0x00, 0xC2, 0x2A, 0x2C, 0x00, 0x00, 0x00, 0xCC, 0x79, 
  /* RLE: 059 Pixels @ 025,063*/ 59, 0x00, 
  /* ABS: 008 Pixels @ 012,064*/ 0, 8, 0x15, 0x15, 0x2C, 0x00, 0x00, 0x00, 0x2C, 0x2B, 
  /* RLE: 556 Pixels @ 020,064*/ 254, 0x00, 254, 0x00, 48, 0x00, 


  0};  /* 2575 bytes for 5184 pixels */

GUI_CONST_STORAGE GUI_BITMAP bmsettings = {
  72, /* XSize */
  72, /* YSize */
  72, /* BytesPerLine */
  GUI_COMPRESS_RLE8, /* BitsPerPixel */
  acsettings,  /* Pointer to picture data (indices) */
  &Palsettings,  /* Pointer to palette */
  GUI_DRAW_RLE8
};

/* *** End of file *** */

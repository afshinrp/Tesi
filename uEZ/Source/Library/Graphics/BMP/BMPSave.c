/*-------------------------------------------------------------------------*
 * File:  BMPSave.c
 *-------------------------------------------------------------------------*
 * Description:
 *     
 *-------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
 * uEZ(R) - Copyright (C) 2007-2010 Future Designs, Inc.
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
 * Includes:
 *-------------------------------------------------------------------------*/
#include <uEZ.h>
#include <uEZFile.h>
#include "BMPSave.h"
#include "BMPTypes.h"

/*-------------------------------------------------------------------------*
 * Constants:
 *-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*
 * Types:
 *-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*
 * Prototypes:
 *-------------------------------------------------------------------------*/
T_uezError BMPSaveScreen(const char *aFilename, T_pixelColor *aPixels)
{
    T_BMP_Header header;
    T_BMP_DIBHeader dib;
    T_uezError error;
    T_uezFile file;
    TUInt32 numWritten;
    TInt32 y;
    TUInt32 x;
    T_pixelColor * p;
    TUInt32 padCount;
    T_pixelColor pixel;
    TUInt8 rgb[3];
    T_pixelColor *p_pixels;
    void *SUICallbackGetLCDBase(void);

    const TUInt32 pixelRasterWidth = (3 * DISPLAY_WIDTH + 3) & (~3);

    p_pixels = aPixels;

    error = UEZFileOpen(aFilename, FILE_FLAG_WRITE, &file);
    if (error)
        return error;

    header.iMagicNumber[0] = 'B';
    header.iMagicNumber[1] = 'M';
    header.iOffsetToPixels = sizeof(header) + sizeof(dib);
    header.iSize = header.iOffsetToPixels + (pixelRasterWidth * DISPLAY_HEIGHT
            * 3);
    header.iUnused1 = 0;
    header.iUnused2 = 0;
    error = UEZFileWrite(file, &header, sizeof(header), &numWritten);
    if (error) {
        UEZFileClose(file);
        return error;
    }

    dib.iDIBHeaderSize = sizeof(dib);
    dib.iBMPWidth = DISPLAY_WIDTH;
    dib.iBMPHeight = DISPLAY_HEIGHT;
    dib.iNumberColorPlanes = 1;
    dib.iBitsPerPlane = 24;
    dib.iPixelArrayCompression = 0; // no compression
    dib.iSizePixelArray = (pixelRasterWidth * DISPLAY_HEIGHT * 3);
    dib.aHorizontalResolution = 2835;
    dib.aVerticalResolution = 2835;
    dib.iPaletteNumColors = 0; // no palette
    dib.iPaletteNumImportant = 0; // all
    error = UEZFileWrite(file, &dib, sizeof(dib), &numWritten);
    if (error) {
        UEZFileClose(file);
        return error;
    }

    for (y = DISPLAY_HEIGHT - 1; y >= 0; y--) {
        // Determine which line we are at
        p = &p_pixels[y * DISPLAY_WIDTH];
        padCount = 0;

        // Output the RGB
        for (x = 0; x < DISPLAY_WIDTH; x++) {
            pixel = p[x];
            rgb[2] = ((pixel >> 11) & 0x1F) << 3;
            rgb[1] = ((pixel >> 5) & 0x3F) << 2;
            rgb[0] = ((pixel >> 0) & 0x1F) << 3;
            error = UEZFileWrite(file, rgb, 3, &numWritten);
            if (error) {
                UEZFileClose(file);
                return error;
            }
            padCount += 3;
        }

        // Pad out the line with zeros
        while (padCount & 3) {
            rgb[0] = 0;
            error = UEZFileWrite(file, rgb, 1, &numWritten);
            if (error) {
                UEZFileClose(file);
                return error;
            }
            padCount++;
        }
    }

    UEZFileClose(file);

    return error;
}

/*-------------------------------------------------------------------------*
 * End of File:  BMPSave.c
 *-------------------------------------------------------------------------*/

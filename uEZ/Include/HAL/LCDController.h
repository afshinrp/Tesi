/*-------------------------------------------------------------------------*
 * File:  LCDController.h
 *-------------------------------------------------------------------------*
 * Description:
 *     LCD Controller HAL interface
 *-------------------------------------------------------------------------*/
#ifndef _HAL_LCD_CONTROLLER_H_
#define _HAL_LCD_CONTROLLER_H_

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
/**
 *  @file   /Include/HAL/LCDController.h
 *  @brief  uEZ LCD Controller HAL Interface
 *
 *  The uEZ LCD Controller HAL Interface
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
#include <uEZLCD.h>
#include <HAL/HAL.h>

/*-------------------------------------------------------------------------*
 * Constants:
 *-------------------------------------------------------------------------*/
#define LCDCONTROLLER_FEATURE_POWER                 (1<<0)
#define LCDCONTROLLER_FEATURE_BACKLIGHT             (1<<1)
#define LCDCONTROLLER_FEATURE_DUAL_PANEL            (1<<2)
#define LCDCONTROLLER_FEATURE_DYNAMIC_BASE_ADDR     (1<<3)
#define LCDCONTROLLER_FEATURE_PALETTE_CONTROL       (1<<4)

/*-------------------------------------------------------------------------*
 * Types:
 *-------------------------------------------------------------------------*/
typedef enum {
    LCD_STANDARD_TFT=0,
    LCD_ADVANCED_TFT,
    LCD_HIGHLY_REFLECTIVE_TFT,
    LCD_4BIT_MONO,
    LCD_8BIT_MONO,
    LCD_COLOR_STN
} T_lcdPanelType;

typedef enum {
	LCD_COLOR_RES_1=0,
	LCD_COLOR_RES_2,
	LCD_COLOR_RES_4,
	LCD_COLOR_RES_8,
	LCD_COLOR_RES_12_444,   /**< uses 16 bits to store 12 levels  0:R4:G4:B4 */
	LCD_COLOR_RES_16_I555,  /**< first bit is intensity bit (1=high/0=low) */
	LCD_COLOR_RES_16_565,
	LCD_COLOR_RES_24,	
} T_lcdColorResolution;

typedef enum {
    LCD_COLOR_ORDER_RGB,
    LCD_COLOR_ORDER_BGR,
} T_lcdColorOrder;

typedef struct {
/**
 * LCD Panel type
 */
    T_lcdPanelType iPanelType;

/**
 * Pixels
 */
    T_lcdColorResolution iColorResolution;

/**
 * Horizontal settings
 */
    TUInt16 iHorizontalBackPorch; 
    TUInt16 iHorizontalFrontPorch; 
    TUInt16 iHorizontalSyncPulseWidth;
    TUInt16 iHorizontalPixelsPerLine;
    
/**
 * Vertical Settings
 */
    TUInt16 iVerticalBackPorch;
    TUInt16 iVerticalFrontPorch;
    TUInt16 iVerticalSyncPulseWidth;
    TUInt16 iVerticalLinesPerPanel;

/**
 * Line end control
 */
    TUInt16 iLineEndDelay; /**< 0 = disabled */

/**
 * Line polarity
 */
    TBool iInvertOutputEnable;
    TBool iInvertPanelClock;
    TBool iInvertHorizontalSync;
    TBool iInvertVerticalSync;

/**
 * Bias
 */
    TUInt16 iACBiasPinFrequency;

/**
 * Misc
 */
    TBool iIsDualPanel;
    TBool iIsBigEndian;
    TBool iIsRightToLeftPixels;
    TBool iIsBottomToTopLines;
    T_lcdColorOrder iColorOrder;
    TUInt32 iBaseAddress;

/**
 * Need dot clock here!
 */
    TUInt32 iDotClockHz;
} T_LCDControllerSettings;

typedef void (*LCDControllerVerticalSync)(void *aCallbackWorkspace);

typedef struct {
    // Common header
    T_halInterface iInterface;

    TUInt32 iFeatures;

    // Functions
    T_uezError (*Configure)(void *aWorkspace, T_LCDControllerSettings *aSettings);
    T_uezError (*On)(void *aWorkspace);
    T_uezError (*Off)(void *aWorkspace);
    T_uezError (*SetBacklightLevel)(void *aWorkspace, TUInt32 aLevel);
    T_uezError (*SetBaseAddr)(void *aWorkspace, TUInt32 aBaseAddress, TBool aSync);
    T_uezError (*SetPaletteColor)(
                    void *aWorkspace,
                    TUInt32 aColorIndex, 
                    TUInt16 aRed, 
                    TUInt16 aGreen, 
                    TUInt16 aBlue);

    // v2.04
    T_uezError (*EnableVerticalSync)(
        void *aWorkspace,
        LCDControllerVerticalSync aCallbackFunc,
        void *aCallbackWorkspace);
    T_uezError (*DisableVerticalSync)(void *aWorkspace);
} HAL_LCDController;

#endif // _HAL_LCD_CONTROLLER_H_

/*-------------------------------------------------------------------------*
 * End of File:  LCDController.h
 *-------------------------------------------------------------------------*/

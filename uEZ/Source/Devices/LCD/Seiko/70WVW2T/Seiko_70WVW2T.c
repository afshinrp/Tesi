/*-------------------------------------------------------------------------*
 * File: Seiko_70WVW2T.c
 
 *-------------------------------------------------------------------------*
 * Description:
 *      HAL implementation of the Seiko 70WVW2T.
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

#include <uEZ.h>
#include <HAL/LCDController.h>
#include <HAL/GPIO.h>
#include "Seiko_70WVW2T.h"

/*---------------------------------------------------------------------------*
 * Constants:
 *---------------------------------------------------------------------------*/
#define RESOLUTION_X        800
#define RESOLUTION_Y        480
#ifndef SEIKO_70WVW2T_DOTCLOCK_HZ
    #define     SEIKO_70WVW2T_DOTCLOCK_HZ       33260000
#endif

/*---------------------------------------------------------------------------*
 * Types:
 *---------------------------------------------------------------------------*/
typedef struct {
    const DEVICE_LCD *iHAL;
    TUInt32 iBaseAddress;
    int aNumOpen;
    TUInt32 iBacklightLevel;
    HAL_LCDController **iLCDController;
    DEVICE_Backlight **iBacklight;
    const T_uezLCDConfiguration *iConfiguration;
    HAL_GPIOPort **iPowerGPIOPort;
	T_uezSemaphore iVSyncSem;
} T_70WVW2TWorkspace;

/*---------------------------------------------------------------------------*
 * Globals:
 *---------------------------------------------------------------------------*/
static T_LCDControllerSettings LCD_70WVW2T_settings ;

static T_LCDControllerSettings LCD_70WVW2T_params16bit = {
    LCD_ADVANCED_TFT,
    LCD_COLOR_RES_16_565,

    10,         /* Horizontal back porch */
    120,          /* Horizontal front porch */
    30,         /* HSYNC pulse width */
    800,        /* Pixels per line */

    7,          /* Vertical back porch */
    35,          /* Vertical front porch */
    3,         /* VSYNC pulse width */
    480,        /* Lines per panel */

    0,          // Line end delay disabled

    EFalse,     /* Do not invert output enable */
    EFalse,     /* Invert panel clock */
    EFalse,     /* Invert HSYNC */
    EFalse,     /* Invert VSYNC */

    0,          /* AC bias frequency (not used) */

    EFalse,     // Not dual panel
    EFalse,     // Little endian (NOT big endian)
    EFalse,     //    Left to Right pixels (NOT right to left)
    EFalse,     // Top to bottom (NOT bottom to top)
    LCD_COLOR_ORDER_BGR,    // BGR order please

    0xA0000000, // Default Base address

    SEIKO_70WVW2T_DOTCLOCK_HZ,    // 33.26 MHz Typical value from datasheet (Min 29.40, Max 42.48)
};

static T_LCDControllerSettings LCD_70WVW2T_paramsI15bit = {
    LCD_ADVANCED_TFT,
    LCD_COLOR_RES_16_I555,

    25, // 28,         /* Horizontal back porch */
    25, // 200,          /* Horizontal front porch */
    150, // 128,         /* HSYNC pulse width */
    800,        /* Pixels per line */

    2, // 5,          /* Vertical back porch */
    2, // 5,          /* Vertical front porch */
    6, // 35,         /* VSYNC pulse width */
    480,        /* Lines per panel */

    0,          // Line end delay disabled

    EFalse,     /* Do not invert output enable */
    EFalse,     /* Invert panel clock */
    EFalse,     /* Invert HSYNC */
    EFalse,     /* Invert VSYNC */

    0,          /* AC bias frequency (not used) */

    EFalse,     // Not dual panel
    EFalse,     // Little endian (NOT big endian)
    EFalse,     //    Left to Right pixels (NOT right to left)
    EFalse,     // Top to bottom (NOT bottom to top)
    LCD_COLOR_ORDER_BGR,    // BGR order please

    0xA0000000, // Default Base address
        
    SEIKO_70WVW2T_DOTCLOCK_HZ,  // Min 29.40 MHz, Typical 33.26, Max 42.48
};

static const T_LCDControllerSettings LCD_70WVW2T_params8bit = {
    LCD_ADVANCED_TFT,
    LCD_COLOR_RES_8,

    10,         /* Horizontal back porch */
    120,          /* Horizontal front porch */
    30,         /* HSYNC pulse width */
    800,        /* Pixels per line */

    7,          /* Vertical back porch */
    35,          /* Vertical front porch */
    3,         /* VSYNC pulse width */
    480,        /* Lines per panel */

    0,          // Line end delay disabled

    EFalse,     /* Do not invert output enable */
    EFalse,     /* Invert panel clock */
    EFalse,     /* Invert HSYNC */
    EFalse,     /* Invert VSYNC */

    0,          /* AC bias frequency (not used) */

    EFalse,     // Not dual panel
    EFalse,     // Little endian (NOT big endian)
    EFalse,     //    Left to Right pixels (NOT right to left)
    EFalse,     // Top to bottom (NOT bottom to top)
    LCD_COLOR_ORDER_BGR,    // BGR order please

    0xA0000000, // Default Base address

    SEIKO_70WVW2T_DOTCLOCK_HZ,    // 33.26 MHz Typical value from datasheet (Min 29.40, Max 42.48)
};

static T_uezLCDConfiguration LCD_70WVW2T_configuration_16Bit = {
    RESOLUTION_X,
    RESOLUTION_Y,
    UEZLCD_COLOR_DEPTH_16_BIT,
    UEZLCD_ORDER_RGB,
    0,
    1,
    RESOLUTION_X*2,
    RESOLUTION_X*2,
    256
};

static T_uezLCDConfiguration LCD_70WVW2T_configuration_I15Bit = {
    RESOLUTION_X,
    RESOLUTION_Y,
    UEZLCD_COLOR_DEPTH_I15_BIT,
    UEZLCD_ORDER_RGB,
    0,
    1,
    RESOLUTION_X*2,
    RESOLUTION_X*2,
    256
};

static T_uezLCDConfiguration LCD_70WVW2T_configuration_8Bit = {
    RESOLUTION_X,
    RESOLUTION_Y,
    UEZLCD_COLOR_DEPTH_8_BIT,
    UEZLCD_ORDER_RGB,
    0,
    1,
    RESOLUTION_X*1,
    RESOLUTION_X*1,
    256
};

/*---------------------------------------------------------------------------*
 * Prototypes:
 *---------------------------------------------------------------------------*/
extern const DEVICE_LCD LCD_SEIKO_70WVW2T_Interface;

/*---------------------------------------------------------------------------*
 * Routine:  LCD_70WVW2T_InitializeWorkspace_16Bit
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup workspace for 70WVW2T LCD.
 * Inputs:
 *      void *aW                    -- Particular workspace
 * Outputs:
 *      T_uezError                   -- Error code
 *---------------------------------------------------------------------------*/
T_uezError LCD_70WVW2T_InitializeWorkspace_16Bit(void *aW)
{
    T_70WVW2TWorkspace *p = (T_70WVW2TWorkspace *)aW;
    p->iBaseAddress = 0xA0000000;
    p->aNumOpen = 0;
    p->iBacklightLevel = 256; // 100%
    p->iConfiguration = &LCD_70WVW2T_configuration_16Bit;
#if UEZ_LCD_POWER_GPIO_PIN
    HALInterfaceFind(UEZ_LCD_POWER_GPIO_PORT, (T_halWorkspace **)&p->iPowerGPIOPort);
#else
    p->iPowerGPIOPort = 0;
#endif

    return UEZSemaphoreCreateBinary(&p->iVSyncSem);
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_70WVW2T_InitializeWorkspace_I15Bit
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup workspace for 70WVW2T LCD.
 * Inputs:
 *      void *aW                    -- Particular workspace
 * Outputs:
 *      T_uezError                   -- Error code
 *---------------------------------------------------------------------------*/
T_uezError LCD_70WVW2T_InitializeWorkspace_I15Bit(void *aW)
{
    T_70WVW2TWorkspace *p = (T_70WVW2TWorkspace *)aW;
    p->iBaseAddress = 0xA0000000;
    p->aNumOpen = 0;
    p->iBacklightLevel = 256; // 100%
    p->iConfiguration = &LCD_70WVW2T_configuration_I15Bit;
#if UEZ_LCD_POWER_GPIO_PIN
    HALInterfaceFind(UEZ_LCD_POWER_GPIO_PORT, (T_halWorkspace **)&p->iPowerGPIOPort);
#else
    p->iPowerGPIOPort = 0;
#endif

    return UEZSemaphoreCreateBinary(&p->iVSyncSem);
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_70WVW2T_InitializeWorkspace_8Bit
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup workspace for 70WVW2T LCD.
 * Inputs:
 *      void *aW                    -- Particular workspace
 * Outputs:
 *      T_uezError                   -- Error code
 *---------------------------------------------------------------------------*/
T_uezError LCD_70WVW2T_InitializeWorkspace_8Bit(void *aW)
{
    T_70WVW2TWorkspace *p = (T_70WVW2TWorkspace *)aW;
    p->iBaseAddress = 0xA0000000;
    p->aNumOpen = 0;
    p->iBacklightLevel = 256; // 100%
    p->iConfiguration = &LCD_70WVW2T_configuration_8Bit;
#if UEZ_LCD_POWER_GPIO_PIN
    HALInterfaceFind(UEZ_LCD_POWER_GPIO_PORT, (T_halWorkspace **)&p->iPowerGPIOPort);
#else
    p->iPowerGPIOPort = 0;
#endif

    return UEZSemaphoreCreateBinary(&p->iVSyncSem);
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_70WVW2T_Open
 *---------------------------------------------------------------------------*
 * Description:
 *      Start the LCD screen.  If this is the first open, initialize the
 *      screen.
 * Inputs:
 *      void *aW                -- Workspace
 * Outputs:
 *      T_uezError               -- If the device is opened, returns
 *                                  UEZ_ERROR_NONE.
 *---------------------------------------------------------------------------*/
T_uezError LCD_70WVW2T_Open(void *aW)
{
    T_70WVW2TWorkspace *p = (T_70WVW2TWorkspace *)aW;
    HAL_LCDController **plcdc;
    p->aNumOpen++;
    if (p->aNumOpen == 1) {
        plcdc = p->iLCDController;

        switch (p->iConfiguration->iColorDepth) {
            case UEZLCD_COLOR_DEPTH_8_BIT:
                LCD_70WVW2T_settings = LCD_70WVW2T_params8bit;
                break;
            default:
            case UEZLCD_COLOR_DEPTH_16_BIT:
                LCD_70WVW2T_settings = LCD_70WVW2T_params16bit;
                break;
            case UEZLCD_COLOR_DEPTH_I15_BIT:
                LCD_70WVW2T_settings = LCD_70WVW2T_paramsI15bit;
                break;
        }
        LCD_70WVW2T_settings.iBaseAddress = p->iBaseAddress;

        return (*plcdc)->Configure(plcdc, &LCD_70WVW2T_settings);
    }

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_70WVW2T_Close
 *---------------------------------------------------------------------------*
 * Description:
 *      End access to the LCD display.
 * Inputs:
 *      void *aW                -- Workspace
 * Outputs:
 *      T_uezError               -- If the device is successfully closed,
 *                                  returns UEZ_ERROR_NONE.
 *---------------------------------------------------------------------------*/
T_uezError LCD_70WVW2T_Close(void *aW)
{
    T_70WVW2TWorkspace *p = (T_70WVW2TWorkspace *)aW;
    p->aNumOpen--;

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_70WVW2T_Configure
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the LCD to use a particular LCD controller.
 * Inputs:
 *      void *aW                -- Workspace
 * Outputs:
 *      T_uezError               -- If the device is successfully configured,
 *                                  returns UEZ_ERROR_NONE.
 *---------------------------------------------------------------------------*/
T_uezError LCD_70WVW2T_Configure(
            void *aW,
            HAL_LCDController **aLCDController,
            TUInt32 aBaseAddress,
            DEVICE_Backlight **aBacklight)
{
    T_70WVW2TWorkspace *p = (T_70WVW2TWorkspace *)aW;
    T_uezError error = UEZ_ERROR_NONE;
    p->iLCDController = aLCDController;
    p->iBaseAddress = aBaseAddress;

    p->iBacklight = aBacklight;

    return error;
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_70WVW2T_GetInfo
 *---------------------------------------------------------------------------*
 * Description:
 *      Get information about the LCD device.
 * Inputs:
 *      void *aW                -- Workspace
 * Outputs:
 *      T_uezError               -- If successful, returns UEZ_ERROR_NONE.
 *---------------------------------------------------------------------------*/
T_uezError LCD_70WVW2T_GetInfo(void *aW, T_uezLCDConfiguration *aConfiguration)
{
    T_70WVW2TWorkspace *p = (T_70WVW2TWorkspace *)aW;

    // Use the setting based on color depth
    *aConfiguration = *p->iConfiguration;

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_70WVW2T_GetFrame
 *---------------------------------------------------------------------------*
 * Description:
 *      Returns a pointer to the frame memory in the LCD display.
 * Inputs:
 *      void *aW                -- Workspace
 *      TUInt32 aFrame          -- Index to frame (0 based)
 *      void **aFrameBuffer     -- Pointer to base address
 * Outputs:
 *      T_uezError               -- If successful, returns UEZ_ERROR_NONE.
 *---------------------------------------------------------------------------*/
T_uezError LCD_70WVW2T_GetFrame(
            void *aW,
            TUInt32 aFrame,
            void **aFrameBuffer)
{
    T_70WVW2TWorkspace *p = (T_70WVW2TWorkspace *)aW;
    *aFrameBuffer = (void *)(p->iBaseAddress + aFrame * RESOLUTION_X * RESOLUTION_Y * 2);

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_70WVW2T_ShowFrame
 *---------------------------------------------------------------------------*
 * Description:
 *      Makes the passed frame the actively viewed frame on the LCD
 *      (if not already).
 * Inputs:
 *      void *aW                -- Workspace
 *      TUInt32 aFrame          -- Index to frame (0 based)
 * Outputs:
 *      T_uezError               -- If successful, returns UEZ_ERROR_NONE.
 *---------------------------------------------------------------------------*/
T_uezError LCD_70WVW2T_ShowFrame(void *aW, TUInt32 aFrame)
{
    T_70WVW2TWorkspace *p = (T_70WVW2TWorkspace *)aW;
    (*p->iLCDController)->SetBaseAddr(
            p->iLCDController,
            p->iBaseAddress + aFrame * RESOLUTION_X * RESOLUTION_Y * 2,
            EFalse);

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_70WVW2T_On
 *---------------------------------------------------------------------------*
 * Description:
 *      Turns on the LCD display.
 * Inputs:
 *      void *aW                -- Workspace
 * Outputs:
 *      T_uezError               -- If successful, returns UEZ_ERROR_NONE.
 *---------------------------------------------------------------------------*/
T_uezError LCD_70WVW2T_On(void *aW)
{
    // Turn back on to the remembered level
    T_70WVW2TWorkspace *p = (T_70WVW2TWorkspace *)aW;
#if UEZ_LCD_POWER_GPIO_PIN
    HAL_GPIOPort **p_gpio = p->iPowerGPIOPort;
#endif
    
#if UEZ_LCD_POWER_GPIO_PIN
    if (p_gpio) {
        (*p_gpio)->SetOutputMode(p_gpio, 1UL<<UEZ_LCD_POWER_GPIO_PIN);
        (*p_gpio)->SetMux(p_gpio, UEZ_LCD_POWER_GPIO_PIN, 0); // set to GPIO
        (*p_gpio)->Clear(p_gpio, 1UL<<UEZ_LCD_POWER_GPIO_PIN);
    }
#endif

    (*p->iLCDController)->On(p->iLCDController);

    UEZTaskDelay(200);//added delay to match timing in datasheet

    if (p->iBacklight)
        (*p->iBacklight)->On(p->iBacklight);

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_70WVW2T_Off
 *---------------------------------------------------------------------------*
 * Description:
 *      Turns off the LCD display.
 * Inputs:
 *      void *aW                -- Workspace
 * Outputs:
 *      T_uezError               -- If successful, returns UEZ_ERROR_NONE.
 *---------------------------------------------------------------------------*/
T_uezError LCD_70WVW2T_Off(void *aW)
{
    // Turn off, but don't remember the level
    T_70WVW2TWorkspace *p = (T_70WVW2TWorkspace *)aW;
#if UEZ_LCD_POWER_GPIO_PIN
    HAL_GPIOPort **p_gpio = p->iPowerGPIOPort;
#endif
    
    //changed order and added delay to match timing diagram in datasheet.
    if (p->iBacklight)
        (*p->iBacklight)->Off(p->iBacklight);
    
    UEZTaskDelay(200);

#if UEZ_LCD_POWER_GPIO_PIN
    if (p_gpio) {
        (*p_gpio)->SetOutputMode(p_gpio, 1UL<<UEZ_LCD_POWER_GPIO_PIN);
        (*p_gpio)->SetMux(p_gpio, UEZ_LCD_POWER_GPIO_PIN, 0); // set to GPIO
        (*p_gpio)->Set(p_gpio, 1UL<<UEZ_LCD_POWER_GPIO_PIN);
    }
#endif
    (*p->iLCDController)->Off(p->iLCDController);    

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_70WVW2T_SetBacklightLevel
 *---------------------------------------------------------------------------*
 * Description:
 *      Turns on or off the backlight.  A value of 0 is off and values of 1
 *      or higher is higher levels of brightness (dependent on the LCD
 *      display).  If a display is on/off only, this value will be 1 or 0
 *      respectively.
 * Inputs:
 *      void *aW                -- Workspace
 *      TUInt32 aLevel          -- Level of backlight
 * Outputs:
 *      T_uezError               -- If successful, returns UEZ_ERROR_NONE.
 *                                  If the backlight intensity level is
 *                                  invalid, returns UEZ_ERROR_OUT_OF_RANGE.
 *                                  Returns UEZ_ERROR_NOT_SUPPORTED if
 *                                  no backlight for LCD.
 *---------------------------------------------------------------------------*/
T_uezError LCD_70WVW2T_SetBacklightLevel(void *aW, TUInt32 aLevel)
{
    T_70WVW2TWorkspace *p = (T_70WVW2TWorkspace *)aW;
    TUInt16 level;

    if (!p->iBacklight)
        return UEZ_ERROR_NOT_SUPPORTED;

    // Limit the backlight level
    if (aLevel > p->iConfiguration->iNumBacklightLevels)
        aLevel = p->iConfiguration->iNumBacklightLevels;

    // Remember this level and use it
    p->iBacklightLevel = aLevel;

    // Scale backlight to be 0 - 0xFFFF
    level = (aLevel * 0xFFFF) / p->iConfiguration->iNumBacklightLevels;

    return (*p->iBacklight)->SetRatio(p->iBacklight, level);
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_70WVW2T_GetBacklightLevel
 *---------------------------------------------------------------------------*
 * Description:
 *      Returns the current backlight level as well as the number of
 *      maximum light levels available.
 * Inputs:
 *      void *aW                -- Workspace
 *      TUInt32 *aLevel          -- Level of backlight returned
 *      TUInt32 *aNumLevels      -- Number of levels maximum
 * Outputs:
 *      T_uezError               -- If successful, returns UEZ_ERROR_NONE.
 *                                  If the backlight intensity level is
 *                                  invalid, returns UEZ_ERROR_OUT_OF_RANGE.
 *                                  Returns UEZ_ERROR_NOT_SUPPORTED if
 *                                  no backlight for LCD.
 *---------------------------------------------------------------------------*/
static T_uezError LCD_70WVW2T_GetBacklightLevel(
        void *aW, 
        TUInt32 *aLevel,
        TUInt32 *aNumLevels)
{
    T_70WVW2TWorkspace *p = (T_70WVW2TWorkspace *)aW;

    if (!p->iBacklight)
        return UEZ_ERROR_NOT_SUPPORTED;

    if (aNumLevels)
        *aNumLevels = p->iConfiguration->iNumBacklightLevels;

    // Remember this level and use it
    *aLevel = p->iBacklightLevel;

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_70WVW2T_SetPaletteColor
 *---------------------------------------------------------------------------*
 * Description:
 *      Change the color of a palette entry given the red, green, blue
 *      component of a particular color index.  The color components are
 *      expressed in full 16-bit values at a higher resolution than
 *      the hardware can usually perform.  The color is down shifted to what
 *      the hardware can handle.
 * Inputs:
 *      void *aW                    -- Workspace
 *      TUInt32 aColorIndex         -- Index to palette entry
 *      TUInt16 aRed                -- Red value
 *      TUInt16 aGreen              -- Green value
 *      TUInt16 aBlue               -- Blue value
 * Outputs:
 *      T_uezError               -- If successful, returns UEZ_ERROR_NONE.
 *                                  If the index is invalid, returns
 *                                  UEZ_ERROR_OUT_OF_RANGE.
 *---------------------------------------------------------------------------*/
T_uezError LCD_70WVW2T_SetPaletteColor(
                    void *aWorkspace,
                    TUInt32 aColorIndex,
                    TUInt16 aRed,
                    TUInt16 aGreen,
                    TUInt16 aBlue)
{
    T_70WVW2TWorkspace *p = (T_70WVW2TWorkspace *)aWorkspace;

    return (*p->iLCDController)->SetPaletteColor(
                p->iLCDController,
                aColorIndex,
                aRed,
                aGreen,
                aBlue);
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_70WVW2T_VerticalSyncCallback
 *---------------------------------------------------------------------------*
 * Description:
 *      This routine is called from within an interrupt when the vertical
 *      sync occurs.  This routines releases any waiting callers on
 *      the semaphore.
 * Inputs:
 *      void *aCallbackWorkspace -- LCD workspace
 *---------------------------------------------------------------------------*/
static void LCD_70WVW2T_VerticalSyncCallback(void *aCallbackWorkspace)
{
    T_70WVW2TWorkspace *p = (T_70WVW2TWorkspace *)aCallbackWorkspace;

    _isr_UEZSemaphoreRelease(p->iVSyncSem);
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_70WVW2T_WaitForVerticalSync
 *---------------------------------------------------------------------------*
 * Description:
 *      Wait for a vertical sync be enabling the vertical sync callback
 *      and waiting on a semaphore.
 * Inputs:
 *      void *aWorkspace -- LCD workspace
 *      TUInt32 aTimeout -- Timeout in ms or UEZ_TIMEOUT_INFINITE
 * Outputs:
 *      T_uezError -- UEZ_ERROR_TIMEOUT or UEZ_ERROR_OK.
 *---------------------------------------------------------------------------*/
static T_uezError LCD_70WVW2T_WaitForVerticalSync(
    void *aWorkspace,
    TUInt32 aTimeout)
{
    T_70WVW2TWorkspace *p = (T_70WVW2TWorkspace *)aWorkspace;
    HAL_LCDController **p_hal = p->iLCDController;

    UEZSemaphoreGrab(p->iVSyncSem, 0);
    (*p_hal)->EnableVerticalSync(p_hal, LCD_70WVW2T_VerticalSyncCallback, p);
    return UEZSemaphoreGrab(p->iVSyncSem, aTimeout);
}

/*---------------------------------------------------------------------------*
 * HAL Interface table:
 *---------------------------------------------------------------------------*/
const DEVICE_LCD LCD_SEIKO_70WVW2T_Interface_16Bit = {
	{
	    // Common interface
	    "LCD:SEIKO_70WVW2T:16Bit",
	    0x0100,
	    LCD_70WVW2T_InitializeWorkspace_16Bit,
	    sizeof(T_70WVW2TWorkspace),
	},
	
    // Functions
    LCD_70WVW2T_Open,
    LCD_70WVW2T_Close,
    LCD_70WVW2T_Configure,
    LCD_70WVW2T_GetInfo,
    LCD_70WVW2T_GetFrame,
    LCD_70WVW2T_ShowFrame,
    LCD_70WVW2T_On,
    LCD_70WVW2T_Off,
    LCD_70WVW2T_SetBacklightLevel,
    LCD_70WVW2T_GetBacklightLevel,
    LCD_70WVW2T_SetPaletteColor,
    // v2.04
    LCD_70WVW2T_WaitForVerticalSync,
};

const DEVICE_LCD LCD_SEIKO_70WVW2T_Interface_I15Bit = {
	{
	    // Common interface
	    "LCD:SEIKO_70WVW2T:I15Bit",
	    0x0100,
	    LCD_70WVW2T_InitializeWorkspace_I15Bit,
	    sizeof(T_70WVW2TWorkspace),
	},
	
    // Functions
    LCD_70WVW2T_Open,
    LCD_70WVW2T_Close,
    LCD_70WVW2T_Configure,
    LCD_70WVW2T_GetInfo,
    LCD_70WVW2T_GetFrame,
    LCD_70WVW2T_ShowFrame,
    LCD_70WVW2T_On,
    LCD_70WVW2T_Off,
    LCD_70WVW2T_SetBacklightLevel,
    LCD_70WVW2T_GetBacklightLevel,
    LCD_70WVW2T_SetPaletteColor,
    // v2.04
    LCD_70WVW2T_WaitForVerticalSync,
};

const DEVICE_LCD LCD_SEIKO_70WVW2T_Interface_8Bit = {
	{
	    // Common interface
	    "LCD:SEIKO_70WVW2T:8Bit",
	    0x0100,
	    LCD_70WVW2T_InitializeWorkspace_8Bit,
	    sizeof(T_70WVW2TWorkspace),
	},
	
    // Functions
    LCD_70WVW2T_Open,
    LCD_70WVW2T_Close,
    LCD_70WVW2T_Configure,
    LCD_70WVW2T_GetInfo,
    LCD_70WVW2T_GetFrame,
    LCD_70WVW2T_ShowFrame,
    LCD_70WVW2T_On,
    LCD_70WVW2T_Off,
    LCD_70WVW2T_SetBacklightLevel,
    LCD_70WVW2T_GetBacklightLevel,
    LCD_70WVW2T_SetPaletteColor,
    // v2.04
    LCD_70WVW2T_WaitForVerticalSync,
};

// List of interfaces
const T_uezDeviceInterface *LCD_SEIKO_70WVW2T_InterfaceArray[] = {
    0,      // 1 bit
    0,      // 2 bit
    0,      // 4 bit
    (T_uezDeviceInterface *)&LCD_SEIKO_70WVW2T_Interface_8Bit,      // 8 bit
    (T_uezDeviceInterface *)&LCD_SEIKO_70WVW2T_Interface_16Bit,      // 16 bit
    (T_uezDeviceInterface *)&LCD_SEIKO_70WVW2T_Interface_I15Bit,      // I15 bit
    0,      // 24 bit
};

/*-------------------------------------------------------------------------*
 * End of File:  Seiko_70WVW2T.c
 *-------------------------------------------------------------------------*/

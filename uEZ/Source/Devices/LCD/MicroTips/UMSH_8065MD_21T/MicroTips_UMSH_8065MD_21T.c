/*-------------------------------------------------------------------------*
 * File:  MicroTips_UMSH_8065MD_21T.c
 *-------------------------------------------------------------------------*
 * Description:
 *      HAL implementation of the Sharp UMSH_8065MD_21T.
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
#include <UEZSPI.h>
#include "MicroTips_UMSH_8065MD_21T.h"
#include <uEZDeviceTable.h>
#include <string.h>
#include <uEZGPIO.h>

/*---------------------------------------------------------------------------*
 * Constants:
 *---------------------------------------------------------------------------*/
#define RESOLUTION_X        320
#define RESOLUTION_Y        240

#define LCD_CLOCK_RATE      7500000


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
    char iSPIBus[5];
    T_uezDevice iSPI;
    T_uezGPIOPortPin iCSGPIOPin;
    T_uezGPIOPortPin iResetPin;
    T_uezSemaphore iVSyncSem;
} T_UMSH_8065MD_21TWorkspace;

typedef struct {
    TUInt8 iReg;
        #define REG_END         0xFF
    TUInt16 iData;
} T_lcdSPICmd;


/*---------------------------------------------------------------------------*
 * Globals:
 *---------------------------------------------------------------------------*/
static T_LCDControllerSettings LCD_UMSH_8065MD_21T_settings;

static const T_LCDControllerSettings LCD_UMSH_8065MD_21T_params16bit = {
    LCD_ADVANCED_TFT,
    LCD_COLOR_RES_16_565,

    68,         /* Horizontal back porch */
    19,         /* Horizontal front porch */
    1,          /* HSYNC pulse width */
    320,        /* Pixels per line */

    18,          /* Vertical back porch */
    4,          /* Vertical front porch */
    1,         /* VSYNC pulse width */
    240,        /* Lines per panel */

    0,          // Line end delay disabled

    ETrue,     /* Do not invert output enable */
    ETrue,      /* Invert panel clock */
    EFalse,      /* Invert HSYNC */
    EFalse,      /* Invert VSYNC */

    0,          /* AC bias frequency (not used) */

    EFalse,     // Not dual panel
    EFalse,     // Little endian (NOT big endian)
    EFalse,     // Left to Right pixels (NOT right to left)
    EFalse,     // Top to bottom (NOT bottom to top)
    LCD_COLOR_ORDER_BGR,    // BGR order please

    0xA0000000, // Default Base address
    LCD_CLOCK_RATE,
};

static const T_LCDControllerSettings LCD_UMSH_8065MD_21T_paramsI15bit = {
    LCD_ADVANCED_TFT,
    LCD_COLOR_RES_16_I555,

    68,         /* Horizontal back porch */
    19,         /* Horizontal front porch */
    1,          /* HSYNC pulse width */
    320,        /* Pixels per line */

    18,          /* Vertical back porch */
    4,          /* Vertical front porch */
    1,         /* VSYNC pulse width */
    240,        /* Lines per panel */

    0,          // Line end delay disabled

    ETrue,     /* Do not invert output enable */
    ETrue,      /* Invert panel clock */
    ETrue,      /* Invert HSYNC */
    ETrue,      /* Invert VSYNC */

    0,          /* AC bias frequency (not used) */

    EFalse,     // Not dual panel
    EFalse,     // Little endian (NOT big endian)
    EFalse,     // Left to Right pixels (NOT right to left)
    EFalse,     // Top to bottom (NOT bottom to top)
    LCD_COLOR_ORDER_BGR,    // BGR order please

    0xA0000000, // Default Base address
    LCD_CLOCK_RATE,
};

static const T_LCDControllerSettings LCD_UMSH_8065MD_21T_params8bit = {
    LCD_ADVANCED_TFT,
    LCD_COLOR_RES_8,

    68,         /* Horizontal back porch */
    19,         /* Horizontal front porch */
    1,          /* HSYNC pulse width */
    320,        /* Pixels per line */

    18,          /* Vertical back porch */
    4,          /* Vertical front porch */
    1,         /* VSYNC pulse width */
    240,        /* Lines per panel */

    0,          // Line end delay disabled

    ETrue,     /* Do not invert output enable */
    ETrue,      /* Invert panel clock */
    ETrue,      /* Invert HSYNC */
    ETrue,      /* Invert VSYNC */

    0,          /* AC bias frequency (not used) */

    EFalse,     // Not dual panel
    EFalse,     // Little endian (NOT big endian)
    EFalse,     // Left to Right pixels (NOT right to left)
    EFalse,     // Top to bottom (NOT bottom to top)
    LCD_COLOR_ORDER_BGR,    // BGR order please

    0xA0000000, // Default Base address
    LCD_CLOCK_RATE,
};

static T_uezLCDConfiguration LCD_UMSH_8065MD_21T_configuration_16Bit = {
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

static T_uezLCDConfiguration LCD_UMSH_8065MD_21T_configuration_I15Bit = {
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

static T_uezLCDConfiguration LCD_UMSH_8065MD_21T_configuration_8Bit = {
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
static const T_lcdSPICmd G_lcdStartup[] = {
  // Panel Driving Control
    { 0x02, 0x0200 }, // Power Control 1
    { 0x03, 0x6364 },
    { 0x04, 0x0440 },
    { 0x0D, 0x3221 },
    { 0x0E, 0x3100 },

    { 0x30, 0x0000 },
    { 0x31, 0x0407 },
    { 0x32, 0x0202 },
    { 0x33, 0x0000 },
    { 0x34, 0x0505 },
    { 0x36, 0x0707 },
    { 0x37, 0x0000 },
    { 0x3A, 0x0904 },
    { 0x3B, 0x0904 },
    { REG_END, 0 }
};

/*---------------------------------------------------------------------------*
 * Prototypes:
 *---------------------------------------------------------------------------*/
extern const DEVICE_LCD LCD_MicroTips_UMSH_8065MD_21T_Interface;

/*---------------------------------------------------------------------------*
 * Routine:  LCD_UMSH_8065MD_21T_InitializeWorkspace_16Bit
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup workspace for UMSH_8065MD_21T LCD.
 * Inputs:
 *      void *aW                    -- Particular workspace
 * Outputs:
 *      T_uezError                   -- Error code
 *---------------------------------------------------------------------------*/
T_uezError LCD_UMSH_8065MD_21T_InitializeWorkspace_16Bit(void *aW)
{
    T_UMSH_8065MD_21TWorkspace *p = (T_UMSH_8065MD_21TWorkspace *)aW;
    p->iBaseAddress = 0xA0000000;
    p->aNumOpen = 0;
    p->iBacklightLevel = 256; // 100%
    p->iConfiguration = &LCD_UMSH_8065MD_21T_configuration_16Bit;
    return UEZSemaphoreCreateBinary(&p->iVSyncSem);
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_UMSH_8065MD_21T_InitializeWorkspace_I15Bit
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup workspace for UMSH_8065MD_21T LCD.
 * Inputs:
 *      void *aW                    -- Particular workspace
 * Outputs:
 *      T_uezError                   -- Error code
 *---------------------------------------------------------------------------*/
T_uezError LCD_UMSH_8065MD_21T_InitializeWorkspace_I15Bit(void *aW)
{
    T_UMSH_8065MD_21TWorkspace *p = (T_UMSH_8065MD_21TWorkspace *)aW;
    p->iBaseAddress = 0xA0000000;
    p->aNumOpen = 0;
    p->iBacklightLevel = 256; // 100%
    p->iConfiguration = &LCD_UMSH_8065MD_21T_configuration_I15Bit;
    return UEZSemaphoreCreateBinary(&p->iVSyncSem);
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_UMSH_8065MD_21T_InitializeWorkspace_8Bit
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup workspace for UMSH_8065MD_21T LCD.
 * Inputs:
 *      void *aW                    -- Particular  workspace
 * Outputs:
 *      T_uezError                   -- Error code
 *---------------------------------------------------------------------------*/
T_uezError LCD_UMSH_8065MD_21T_InitializeWorkspace_8Bit(void *aW)
{
    T_UMSH_8065MD_21TWorkspace *p = (T_UMSH_8065MD_21TWorkspace *)aW;
    p->iBaseAddress = 0xA0000000;
    p->aNumOpen = 0;
    p->iBacklightLevel = 256; // 100%
    p->iConfiguration = &LCD_UMSH_8065MD_21T_configuration_8Bit;
    return UEZSemaphoreCreateBinary(&p->iVSyncSem);
}

static T_uezError SPIWriteCmd(
        T_UMSH_8065MD_21TWorkspace *p,
        const T_lcdSPICmd *aCmd)
{
    SPI_Request r;
    TUInt8 cmd[3];
    TUInt8 data[3];
    T_uezError error = UEZ_ERROR_NONE;

#define LCD_SPI_WRITE       (0<<0)
#define LCD_SPI_READ        (1<<0)
#define LCD_SPI_CMD         (0<<1)
#define LCD_SPI_DATA        (1<<1)
#define LCD_SPI_ID0         (0<<2)
#define LCD_SPI_ID1         (1<<2)

    cmd[0] = 0x70;
    cmd[1] = 0x00;
    cmd[2] = aCmd->iReg;
    r.iNumTransfers = 3;
    r.iBitsPerTransfer = 8;
    r.iRate = 1000; // spec says 12 MHz, but we'll start slow at 1 MHz
    r.iClockOutPolarity = ETrue; // rising edge
    r.iClockOutPhase = ETrue;
    r.iCSGPIOPort = GPIO_TO_HAL_PORT(p->iCSGPIOPin);
    r.iCSGPIOBit = GPIO_TO_PIN_BIT(p->iCSGPIOPin);
    r.iCSPolarity = EFalse;
    r.iDataMISO = data;
    r.iDataMOSI = cmd;
    error = UEZSPITransferPolled(p->iSPI, &r);

    if (!error) {
        data[0] = 0x72;
        data[1] = aCmd->iData>>8;
        data[2] = aCmd->iData & 0xFF;
        r.iDataMOSI = data;
        r.iDataMISO = data;
        error = UEZSPITransferPolled(p->iSPI, &r);
    }

    return error;
}

static T_uezError ISPIWriteCommands(
        T_UMSH_8065MD_21TWorkspace *p,
        const T_lcdSPICmd *aCmd)
{
    T_uezError error = UEZ_ERROR_NONE;
    while (aCmd->iReg != REG_END) {
        error = SPIWriteCmd(p, aCmd);
        if (error)
            break;
        aCmd++;
    }
    return error;
}


/*---------------------------------------------------------------------------*
 * Routine:  ISPIConfigure
 *---------------------------------------------------------------------------*
 * Description:
 *      program lcd with SPI commands
 * Inputs:
 *      void *aW                -- Workspace
 * Outputs:
 *      T_uezError               -- If programming is successful, returns
 *                                  UEZ_ERROR_NONE.
 *---------------------------------------------------------------------------*/
static T_uezError ISPIConfigure(T_UMSH_8065MD_21TWorkspace *p)
{
    T_uezError error = UEZ_ERROR_NONE;
    if(strcmp(p->iSPIBus, "\0") == 0){
        //See LCD_UMSH_8065MD_21T_Create to fix.
        UEZFailureMsg("SPI Bus not Configured");
    }
    error = UEZSPIOpen(p->iSPIBus, &p->iSPI);
    if (!error) {
            if (!error) {
                UEZTaskDelay(1);
                error = ISPIWriteCommands(p, G_lcdStartup);
            }
        UEZSPIClose(p->iSPI);
    }

    return error;
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_UMSH_8065MD_21T_Open
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
static T_uezError LCD_UMSH_8065MD_21T_Open(void *aW)
{
    T_UMSH_8065MD_21TWorkspace *p = (T_UMSH_8065MD_21TWorkspace *)aW;
    HAL_LCDController **plcdc;
    T_uezError error = UEZ_ERROR_NONE;

    p->aNumOpen++;

    if (p->aNumOpen == 1) {
#if 1
        UEZGPIOSet(p->iResetPin);
#else
        UEZGPIOClear(p->iResetPin);
#endif
        plcdc = p->iLCDController;
        if (!error) {
            switch (p->iConfiguration->iColorDepth) {
                case UEZLCD_COLOR_DEPTH_8_BIT:
                    LCD_UMSH_8065MD_21T_settings = LCD_UMSH_8065MD_21T_params8bit;
                    break;
                default:
                case UEZLCD_COLOR_DEPTH_16_BIT:
                    LCD_UMSH_8065MD_21T_settings = LCD_UMSH_8065MD_21T_params16bit;
                    break;
                case UEZLCD_COLOR_DEPTH_I15_BIT:
                    LCD_UMSH_8065MD_21T_settings = LCD_UMSH_8065MD_21T_paramsI15bit;
                    break;
            }
            LCD_UMSH_8065MD_21T_settings.iBaseAddress = p->iBaseAddress;

            // start DOTCLK immediately
            error = (*plcdc)->Configure(plcdc, &LCD_UMSH_8065MD_21T_settings);
            // start HSYNC and VSYNC (same as UEZLCDOn(lcd))
            (*p->iLCDController)->On(p->iLCDController);

            UEZTaskDelay(10);
#if 0
            UEZGPIOClear(p->iResetPin);
#else
            UEZGPIOSet(p->iResetPin);
#endif
            // program registers, configure the LCD over the SPI port
            error = ISPIConfigure(p);

            UEZTaskDelay(10); // delay before turning backlight on, min 10 frame
            (*p->iBacklight)->On(p->iBacklight); // turn backlight on
        }
    }
    return error;
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_UMSH_8065MD_21T_Close
 *---------------------------------------------------------------------------*
 * Description:
 *      End access to the LCD display.
 * Inputs:
 *      void *aW                -- Workspace
 * Outputs:
 *      T_uezError               -- If the device is successfully closed,
 *                                  returns UEZ_ERROR_NONE.
 *---------------------------------------------------------------------------*/
static T_uezError LCD_UMSH_8065MD_21T_Close(void *aW)
{
    T_UMSH_8065MD_21TWorkspace *p = (T_UMSH_8065MD_21TWorkspace *)aW;
    p->aNumOpen--;

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_UMSH_8065MD_21T_Configure
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the LCD to use a particular LCD controller.
 * Inputs:
 *      void *aW                -- Workspace
 * Outputs:
 *      T_uezError               -- If the device is successfully configured,
 *                                  returns UEZ_ERROR_NONE.
 *---------------------------------------------------------------------------*/
T_uezError LCD_UMSH_8065MD_21T_Configure(
            void *aW,
            HAL_LCDController **aLCDController,
            TUInt32 aBaseAddress,
            DEVICE_Backlight **aBacklight)
{
    T_UMSH_8065MD_21TWorkspace *p = (T_UMSH_8065MD_21TWorkspace *)aW;
    T_uezError error = UEZ_ERROR_NONE;

    p->iLCDController = aLCDController;
    p->iBaseAddress = aBaseAddress;
    p->iBacklight = aBacklight;

    return error;
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_UMSH_8065MD_21T_GetInfo
 *---------------------------------------------------------------------------*
 * Description:
 *      Get information about the LCD device.
 * Inputs:
 *      void *aW                -- Workspace
 * Outputs:
 *      T_uezError               -- If successful, returns UEZ_ERROR_NONE.
 *---------------------------------------------------------------------------*/
static T_uezError LCD_UMSH_8065MD_21T_GetInfo(void *aW, T_uezLCDConfiguration *aConfiguration)
{
    T_UMSH_8065MD_21TWorkspace *p = (T_UMSH_8065MD_21TWorkspace *)aW;

    // Use the setting based on color depth
    *aConfiguration = *p->iConfiguration;

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_UMSH_8065MD_21T_GetFrame
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
static T_uezError LCD_UMSH_8065MD_21T_GetFrame(
            void *aW,
            TUInt32 aFrame,
            void **aFrameBuffer)
{
    T_UMSH_8065MD_21TWorkspace *p = (T_UMSH_8065MD_21TWorkspace *)aW;
    *aFrameBuffer = (void *)(p->iBaseAddress + aFrame * RESOLUTION_X * RESOLUTION_Y * 2);

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_UMSH_8065MD_21T_ShowFrame
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
static T_uezError LCD_UMSH_8065MD_21T_ShowFrame(void *aW, TUInt32 aFrame)
{
    T_UMSH_8065MD_21TWorkspace *p = (T_UMSH_8065MD_21TWorkspace *)aW;
    (*p->iLCDController)->SetBaseAddr(
            p->iLCDController,
            p->iBaseAddress + aFrame * RESOLUTION_X * RESOLUTION_Y * 2,
            EFalse);

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_UMSH_8065MD_21T_On
 *---------------------------------------------------------------------------*
 * Description:
 *      Turns on the LCD display.
 * Inputs:
 *      void *aW                -- Workspace
 * Outputs:
 *      T_uezError               -- If successful, returns UEZ_ERROR_NONE.
 *---------------------------------------------------------------------------*/
static T_uezError LCD_UMSH_8065MD_21T_On(void *aW)
{
    // Turn back on to the remembered level
    T_UMSH_8065MD_21TWorkspace *p = (T_UMSH_8065MD_21TWorkspace *)aW;
    (*p->iLCDController)->On(p->iLCDController);

    if (p->iBacklight)
        (*p->iBacklight)->On(p->iBacklight);

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_UMSH_8065MD_21T_Off
 *---------------------------------------------------------------------------*
 * Description:
 *      Turns off the LCD display.
 * Inputs:
 *      void *aW                -- Workspace
 * Outputs:
 *      T_uezError               -- If successful, returns UEZ_ERROR_NONE.
 *---------------------------------------------------------------------------*/
static T_uezError LCD_UMSH_8065MD_21T_Off(void *aW)
{
    // Turn off, but don't remember the level
    T_UMSH_8065MD_21TWorkspace *p = (T_UMSH_8065MD_21TWorkspace *)aW;
    (*p->iLCDController)->Off(p->iLCDController);

    if (p->iBacklight)
        (*p->iBacklight)->Off(p->iBacklight);

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_UMSH_8065MD_21T_SetBacklightLevel
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
static T_uezError LCD_UMSH_8065MD_21T_SetBacklightLevel(void *aW, TUInt32 aLevel)
{
    T_UMSH_8065MD_21TWorkspace *p = (T_UMSH_8065MD_21TWorkspace *)aW;
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
 * Routine:  LCD_UMSH_8065MD_21T_GetBacklightLevel
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
static T_uezError LCD_UMSH_8065MD_21T_GetBacklightLevel(
        void *aW, 
        TUInt32 *aLevel,
        TUInt32 *aNumLevels)
{
    T_UMSH_8065MD_21TWorkspace *p = (T_UMSH_8065MD_21TWorkspace *)aW;

    if (!p->iBacklight)
        return UEZ_ERROR_NOT_SUPPORTED;

    if (aNumLevels)
        *aNumLevels = p->iConfiguration->iNumBacklightLevels;

    // Remember this level and use it
    *aLevel = p->iBacklightLevel;

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_UMSH_8065MD_21T_SetPaletteColor
 *---------------------------------------------------------------------------*
 * Description:
 *      Change the color of a palette entry given the red, green, blue
 *      component of a particular color index.  The color components are
 *      expressed in full 16-bit values at a higher resolution than
 *      the hardware can usually perform.  The color is down shifted to what
 *      the hardware can handle.
 * Inputs:
 *      void *aW                    -- Workspace
 *      TUInt32 aColorIndex         -- Index to palate entry
 *      TUInt16 aRed                -- Red value
 *      TUInt16 aGreen              -- Green value
 *      TUInt16 aBlue               -- Blue value
 * Outputs:
 *      T_uezError               -- If successful, returns UEZ_ERROR_NONE.
 *                                  If the index is invalid, returns
 *                                  UEZ_ERROR_OUT_OF_RANGE.
 *---------------------------------------------------------------------------*/
static T_uezError LCD_UMSH_8065MD_21T_SetPaletteColor(
                    void *aWorkspace,
                    TUInt32 aColorIndex,
                    TUInt16 aRed,
                    TUInt16 aGreen,
                    TUInt16 aBlue)
{
    T_UMSH_8065MD_21TWorkspace *p = (T_UMSH_8065MD_21TWorkspace *)aWorkspace;

    return (*p->iLCDController)->SetPaletteColor(
                p->iLCDController,
                aColorIndex,
                aRed,
                aGreen,
                aBlue);
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_UMSH_8065MD_21T_VerticalSyncCallback
 *---------------------------------------------------------------------------*
 * Description:
 *      This routine is called from within an interrupt when the vertical
 *      sync occurs.  This routines releases any waiting callers on
 *      the semaphore.
 * Inputs:
 *      void *aCallbackWorkspace -- LCD workspace
 *---------------------------------------------------------------------------*/
static void LCD_UMSH_8065MD_21T_VerticalSyncCallback(void *aCallbackWorkspace)
{
    T_UMSH_8065MD_21TWorkspace *p = (T_UMSH_8065MD_21TWorkspace *)aCallbackWorkspace;

    _isr_UEZSemaphoreRelease(p->iVSyncSem);
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_UMSH_8065MD_21T_WaitForVerticalSync
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
static T_uezError LCD_UMSH_8065MD_21T_WaitForVerticalSync(
    void *aWorkspace,
    TUInt32 aTimeout)
{
    T_UMSH_8065MD_21TWorkspace *p = (T_UMSH_8065MD_21TWorkspace *)aWorkspace;
    HAL_LCDController **p_hal = p->iLCDController;

    UEZSemaphoreGrab(p->iVSyncSem, 0);
    (*p_hal)->EnableVerticalSync(p_hal, LCD_UMSH_8065MD_21T_VerticalSyncCallback, p);
    return UEZSemaphoreGrab(p->iVSyncSem, aTimeout);
}

/*---------------------------------------------------------------------------*
 * Routine:  LCD_UMSH_8065MD_21T_WaitForVerticalSync
 *---------------------------------------------------------------------------*
 * Description:
 *      Routine to configure additional hardware requirements.
 * Inputs:
 *      void *aWorkspace -- LCD workspace
 *      const char* -- SPI or SSP bus the LCD on on (ex. "SSP0")
 *
 *---------------------------------------------------------------------------*/
void LCD_UMSH_8065MD_21T_Create(const char *aName,
                            char* aSPIBus,
                            T_uezGPIOPortPin aSPICSPin,
                            T_uezGPIOPortPin aResetPin)
{
    T_UMSH_8065MD_21TWorkspace *p;

    T_uezDevice lcd;
    T_uezDeviceWorkspace *p_lcd;

    UEZDeviceTableFind(aName, &lcd);
    UEZDeviceTableGetWorkspace(lcd, &p_lcd);

    p = (T_UMSH_8065MD_21TWorkspace *)p_lcd;

    strcpy(p->iSPIBus, aSPIBus);
    p->iCSGPIOPin = aSPICSPin;
    p->iResetPin = aResetPin;
}

/*---------------------------------------------------------------------------*
 * HAL Interface table:
 *---------------------------------------------------------------------------*/
const DEVICE_LCD LCD_MicroTips_UMSH_8065MD_21T_Interface_16Bit = {
	{
	    // Common interface
	    "LCD:MicroTips_UMSH_8065MD_21T:16Bit",
	    0x0100,
	    LCD_UMSH_8065MD_21T_InitializeWorkspace_16Bit,
	    sizeof(T_UMSH_8065MD_21TWorkspace),
	},
	
    // Functions
    LCD_UMSH_8065MD_21T_Open,
    LCD_UMSH_8065MD_21T_Close,
    LCD_UMSH_8065MD_21T_Configure,
    LCD_UMSH_8065MD_21T_GetInfo,
    LCD_UMSH_8065MD_21T_GetFrame,
    LCD_UMSH_8065MD_21T_ShowFrame,
    LCD_UMSH_8065MD_21T_On,
    LCD_UMSH_8065MD_21T_Off,
    LCD_UMSH_8065MD_21T_SetBacklightLevel,
    LCD_UMSH_8065MD_21T_GetBacklightLevel,
    LCD_UMSH_8065MD_21T_SetPaletteColor,

    // v2.04
    LCD_UMSH_8065MD_21T_WaitForVerticalSync,
};

const DEVICE_LCD LCD_MicroTips_UMSH_8065MD_21T_Interface_I15Bit = {
	{
	    // Common interface
	    "LCD:MicroTips_UMSH_8065MD_21T:I15Bit",
	    0x0100,
	    LCD_UMSH_8065MD_21T_InitializeWorkspace_I15Bit,
	    sizeof(T_UMSH_8065MD_21TWorkspace),
	},
	
    // Functions
    LCD_UMSH_8065MD_21T_Open,
    LCD_UMSH_8065MD_21T_Close,
    LCD_UMSH_8065MD_21T_Configure,
    LCD_UMSH_8065MD_21T_GetInfo,
    LCD_UMSH_8065MD_21T_GetFrame,
    LCD_UMSH_8065MD_21T_ShowFrame,
    LCD_UMSH_8065MD_21T_On,
    LCD_UMSH_8065MD_21T_Off,
    LCD_UMSH_8065MD_21T_SetBacklightLevel,
    LCD_UMSH_8065MD_21T_GetBacklightLevel,
    LCD_UMSH_8065MD_21T_SetPaletteColor,

    // v2.04
    LCD_UMSH_8065MD_21T_WaitForVerticalSync,
};

const DEVICE_LCD LCD_MicroTips_UMSH_8065MD_21T_Interface_8Bit = {
	{
	    // Common interface
	    "LCD:MicroTips_UMSH_8065MD_21T:8Bit",
	    0x0100,
	    LCD_UMSH_8065MD_21T_InitializeWorkspace_8Bit,
	    sizeof(T_UMSH_8065MD_21TWorkspace),
	},
	
    // Functions
    LCD_UMSH_8065MD_21T_Open,
    LCD_UMSH_8065MD_21T_Close,
    LCD_UMSH_8065MD_21T_Configure,
    LCD_UMSH_8065MD_21T_GetInfo,
    LCD_UMSH_8065MD_21T_GetFrame,
    LCD_UMSH_8065MD_21T_ShowFrame,
    LCD_UMSH_8065MD_21T_On,
    LCD_UMSH_8065MD_21T_Off,
    LCD_UMSH_8065MD_21T_SetBacklightLevel,
    LCD_UMSH_8065MD_21T_GetBacklightLevel,
    LCD_UMSH_8065MD_21T_SetPaletteColor,

    // v2.04
    LCD_UMSH_8065MD_21T_WaitForVerticalSync,
};

// List of interfaces
const T_uezDeviceInterface *LCD_MicroTips_UMSH_8065MD_21T_InterfaceArray[] = {
    0,      // 1 bit
    0,      // 2 bit
    0,      // 4 bit
    (T_uezDeviceInterface *)&LCD_MicroTips_UMSH_8065MD_21T_Interface_8Bit,      // 8 bit
    (T_uezDeviceInterface *)&LCD_MicroTips_UMSH_8065MD_21T_Interface_16Bit,      // 16 bit
    (T_uezDeviceInterface *)&LCD_MicroTips_UMSH_8065MD_21T_Interface_I15Bit,      // I15 bit
    0,      // 24 bit
};

/*-------------------------------------------------------------------------*
 * End of File:  MicroTips_UMSH_8065MD_21T.c
 *-------------------------------------------------------------------------*/

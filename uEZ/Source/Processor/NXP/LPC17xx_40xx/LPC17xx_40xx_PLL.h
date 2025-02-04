/*-------------------------------------------------------------------------*
 * File:  LPC17xx_40xx_PLL.h
 *-------------------------------------------------------------------------*
 * Description:
 *    See Figure 7. Clock Generation for the LPC178x/LPC177x
 *-------------------------------------------------------------------------*/
#ifndef LPC17xx_40xx_PLL_H_
#define LPC17xx_40xx_PLL_H_

/*--------------------------------------------------------------------------
 * uEZ(R) - Copyright (C) 2007-2012 Future Designs, Inc.
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

/*-------------------------------------------------------------------------*
 * Constants:
 *-------------------------------------------------------------------------*/
#define LPC17xx_40xx_IRC_FREQUENCY       12000000 // Hz +/- 1%

/*-------------------------------------------------------------------------*
 * Types:
 *-------------------------------------------------------------------------*/
typedef enum {
    LPC17xx_40xx_CLKSRC_SELECT_INTERNAL_RC = 0,
    LPC17xx_40xx_CLKSRC_SELECT_MAIN_OSCILLATOR = 1
} T_LPC17xx_40xx_ClockSourceSelect;

typedef enum {
    // sysclk
    LPC17xx_40xx_CPU_CLOCK_SELECT_SYSCLK = 0,

    // pll_clk
    LPC17xx_40xx_CPU_CLOCK_SELECT_PLL_CLK = 1,
} T_LPC17xx_40xx_CPUClockSelect;

typedef enum {
    // sysclk
    LPC17xx_40xx_USB_CLOCK_SELECT_SYSCLK = 0,

    // pll_clk
    LPC17xx_40xx_USB_CLOCK_SELECT_PLL_CLK = 1,

    // alt_pll_clk
    LPC17xx_40xx_USB_CLOCK_SELECT_ALT_PLL_CLK = 2,
} T_LPC17xx_40xx_USBClockSelect;

typedef enum {
    LPC17xx_40xx_CLOCK_OUT_SELECT_CPU = 0,
    LPC17xx_40xx_CLOCK_OUT_SELECT_MAIN_OSC = 1,
    LPC17xx_40xx_CLOCK_OUT_SELECT_IRC_OSC = 2,
    LPC17xx_40xx_CLOCK_OUT_SELECT_USB = 3,
    LPC17xx_40xx_CLOCK_OUT_SELECT_RTC = 4,
    LPC17xx_40xx_CLOCK_OUT_SELECT_WATCHDOG = 6,
} T_LPC17xx_40xx_ClockOutSelect;

typedef struct {
        // Input frequencies:
        TUInt32 iOscillatorClockHz;

        // PLL frequencies:
        // PLL0 is the processor frequency:
        TUInt32 iPLL0Frequency;
        // PLL1 is the USB frequency, usually 48 MHz
        TUInt32 iPLL1Frequency;

        // Selectors:
        T_LPC17xx_40xx_ClockSourceSelect iClockSourceSelect;
        T_LPC17xx_40xx_CPUClockSelect iCPUClockSelect;
        T_LPC17xx_40xx_USBClockSelect iUSBClockSelect;

        // Dividers:
        TUInt8 iCPUClockDivider; // 1 to 31
        TUInt8 iPeripheralClockDivider; // 1 to 31
        TUInt8 iEMCClockDivider; // 1 or 2
        TUInt8 iUSBClockDivider;

        // Internal frequencies
        //   pll_clk     = output ClockSourceSelect -> PLL0
        //   sysclk      = output ClockSourceSelect
        //   alt_pll_clk = output ClockSourceSelect -> PLL1
        // Output:
        //   cclk    = output CPUClockSelect / CPUClockDivider
        //   pclk    = output CPUClockSelect / iPeripheralClockDivider
        //   emc_clk = output CPUClockSelect / iEMCClockDivider
        //   usb_clk = output USBClockSelect / iUSBClockDivider

        // CLK OUT selection:
        T_LPC17xx_40xx_ClockOutSelect iClockOutSelect;
        TUInt8 iClockOutDivider; // 1-16
        TBool iClockOutEnable;
} T_LPC17xx_40xx_PLL_Frequencies;

/*-------------------------------------------------------------------------*
 * Globals:
 *-------------------------------------------------------------------------*/
extern TUInt32 G_OscillatorFrequency IN_INTERNAL_RAM;
extern TUInt32 G_ProcessorFrequency IN_INTERNAL_RAM;
extern TUInt32 G_PeripheralFrequency IN_INTERNAL_RAM;
extern TUInt32 G_EMCFrequency IN_INTERNAL_RAM;
extern TUInt32 G_USBFrequency IN_INTERNAL_RAM;

/*-------------------------------------------------------------------------*
 * Prototypes:
 *-------------------------------------------------------------------------*/
void LPC17xx_40xx_PLL_SetFrequencies(const T_LPC17xx_40xx_PLL_Frequencies *aFreq);

#endif // LPC17xx_40xx_PLL_H_
/*-------------------------------------------------------------------------*
 * End of File:  LPC17xx_40xx_PLL.h
 *-------------------------------------------------------------------------*/

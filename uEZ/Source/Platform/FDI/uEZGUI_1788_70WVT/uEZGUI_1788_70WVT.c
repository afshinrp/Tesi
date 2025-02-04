/*-------------------------------------------------------------------------*
 * File:  uEZPlatform.c
 *-------------------------------------------------------------------------*
 * Description:
 *      Bring up the uEZGUI-1788-70WVT
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

#include <Config.h>
#include <stdio.h>
#include <string.h>
#include <uEZ.h>
#include <Device/LCD.h>
#include <HAL/HAL.h>
#include <HAL/GPIO.h>
#include <HAL/EMAC.h>
#include <HAL/Interrupt.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_USBDeviceController.c>
#include <Source/Devices/Accelerometer/Freescale/MMA7455/Freescale_MMA7455.h>
#include <Source/Devices/ADC/Generic/Generic_ADC.h>
#include <Source/Devices/AudioAmp/NXP/TDA8551_T/AudioAmp_TDA8551T.h>
#include <Source/Devices/Backlight/Generic/BacklightPWMControlled/BacklightPWM.h>
#include <Source/Devices/Button/NXP/PCA9551/Button_PCA9551.h>
#include <Source/Devices/CRC/Generic/CRC_Generic.h>
#include <Source/Devices/DAC/Generic/DAC_Generic.h>
#include <Source/Devices/EEPROM/Generic/I2C/EEPROM_Generic_I2C.h>
#include <Source/Devices/EEPROM/Generic/I2C/EEPROM16_Generic_I2C.h>
#include <Source/Devices/EEPROM/NXP/LPC17xx_40xx/EEPROM_NXP_LPC17xx_40xx.h>
#include <Source/Devices/Flash/Spansion/S29GL/Flash_S29GL064N90_16bit.h>
#include <Source/Devices/GPDMA/Generic/Generic_GPDMA.h>
#include <Source/Devices/HID/Generic/HID_Generic.h>
#include <Source/Devices/Flash/NXP/LPC17xx_40xx/LPC17xx_40xx_IAP.h>
#include <Source/Devices/I2C/Generic/Generic_I2C.h>
#include <Source/Devices/I2S/Generic/Generic_I2S.h>
#include <Source/Devices/LED/NXP/PCA9551/LED_NXP_PCA9551.h>
#include <Source/Devices/MassStorage/SDCard/SDCard_MS_driver_SPI.h>
#include <Source/Devices/MassStorage/SDCard/SDCard_MS_driver_MCI.h>
#include <Source/Devices/MassStorage/USB_MS/USB_MS.h>
#include <Source/Devices/Network/lwIP/Network_lwIP.h>
#include <Source/Devices/Network/GainSpan/Network_GainSpan.h>
#include <Source/Devices/PWM/Generic/Generic_PWM.h>
#include <Source/Devices/RTC/Generic/Generic_RTC.h>
#include <Source/Devices/RTC/NXP/PCF8563/RTC_PCF8563.h>
#include <Source/Devices/Serial/Generic/Generic_Serial.h>
#include <Source/Devices/SPI/Generic/Generic_SPI.h>
#include <Source/Devices/Temperature/NXP/LM75A/Temperature_LM75A.h>
#include <Source/Devices/ToneGenerator/Generic/PWM/ToneGenerator_Generic_PWM.h>
#include <Source/Devices/Touchscreen/Generic/FourWireTouchResist/FourWireTouchResist_TS.h>
#include <Source/Devices/USBDevice/NXP/LPC17xx_40xx/LPC17xx_40xx_USBDevice.h>
#include <Source/Devices/USBHost/Generic/Generic_USBHost.h>
#include <Source/Devices/Watchdog/Generic/Watchdog_Generic.h>
#include <Source/Devices/Audio Codec/Wolfson/WM8731/AudioCodec_WM8731.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_RTC.h>
#include <Source/Library/Web/BasicWeb/BasicWEB.h>
#include <Source/Library/FileSystem/FATFS/uEZFileSystem_FATFS.h>
#include <Source/Library/Graphics/SWIM/lpc_swim.h>
#include <Source/Library/Memory/MemoryTest/MemoryTest.h>
#include <Source/Library/StreamIO/StdInOut/StdInOut.h>
#include <Source/Processor/NXP/LPC17xx_40xx/uEZProcessor_LPC17xx_40xx.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_ADCBank.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_CRC.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_DAC.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_EMAC.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_EMC_Static.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_GPDMA.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_GPIO.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_I2C.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_I2S.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_LCDController.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_PWM.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_PLL.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_SDRAM.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_Serial.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_SSP.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_Timer.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_USBDeviceController.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_USBHost.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_Watchdog.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_MCI.h>
#include <uEZAudioAmp.h>
#include <uEZBSP.h>
#include <uEZDevice.h>
#include <uEZDeviceTable.h>
#include <uEZFile.h>
#include <uEZI2C.h>
#include <uEZNetwork.h>
#include <uEZPlatform.h>
#include <uEZProcessor.h>
#include <uEZStream.h>
#include <UEZPlatform.h>
#include <uEZPlatformAPI.h>
#include <uEZAudioMixer.h>

/*---------------------------------------------------------------------------*
 * Constants:
 *---------------------------------------------------------------------------*/
#define NOR_FLASH_BASE_ADDR             0x80000000
#define CONFIG_MEMORY_TEST_ON_SDRAM     0

#ifndef UEZGUI_7_REV2_BOARD_SWAP_TP_LINES
  #define UEZGUI_7_REV2_BOARD_SWAP_TP_LINES           1
#endif

#ifndef UEZGUI_EXP_BRK_OUT
#define UEZGUI_EXP_BRK_OUT              0
#endif

/*---------------------------------------------------------------------------*
 * Globals:
 *---------------------------------------------------------------------------*/
static T_uezDevice G_stdout = 0;
static T_uezDevice G_stdin = 0;
T_uezTask G_mainTask;

/*---------------------------------------------------------------------------*
 * Macros:
 *---------------------------------------------------------------------------*/
#if(COMPILER_TYPE==Keil4)
#define nop()      __nop()
#else
#define nop()     NOP()//asm("nop")
#endif
#define nops5()    nop();nop();nop();nop();nop()
#define nops10()   nops5();nops5()
#define nops50()   nops10();nops10();nops10();nops10();nops10()

/*---------------------------------------------------------------------------*
 * Routine:  UEZBSPDelayMS
 *---------------------------------------------------------------------------*
 * Description:
 *      Use a delay loop to approximate the time to delay.
 *      Should use UEZTaskDelayMS() when in a task instead.
 *---------------------------------------------------------------------------*/
void UEZBSPDelay1US(void)
{
    //Based on Flash Accelerator being on and Flash Access Time set to 6 CPU Cycles
#if ( PROCESSOR_OSCILLATOR_FREQUENCY == 120000000)
    nops50();
    nops50();
    nop();
    nop();
    nop();
    nop();
#elif ( PROCESSOR_OSCILLATOR_FREQUENCY == 72000000)
    nops50();
    nops50();
    nop();
    nop();
    nop();
    nop();
#else
    #error "1 microSecond delay not defined for CPU speed"
#endif
}
void UEZBSPDelayUS(unsigned int aMicroseconds)
{
    while (aMicroseconds--)
        UEZBSPDelay1US();
}

void UEZBSPDelay1MS(void)
{
    TUInt32 i;

    // Approximate delays here
    for (i = 0; i < 1000; i++)
        UEZBSPDelay1US();
}

void UEZBSPDelayMS(unsigned int aMilliseconds)
{
    while (aMilliseconds--) {
        UEZBSPDelay1MS();
    }
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZBSPSDRAMInit
 *---------------------------------------------------------------------------*
 * Description:
 *      Initialize the external SDRAM.
 *---------------------------------------------------------------------------*/
void UEZBSP_RAMInit(void)
{
    static const T_LPC17xx_40xx_SDRAM_Configuration sdramConfig_MT48LC2M32B2P = {
            UEZBSP_SDRAM_BASE_ADDR,
            UEZBSP_SDRAM_SIZE,
            SDRAM_CAS_2,
            SDRAM_CAS_3,
            LPC17xx_40xx_SDRAM_CLKOUT0,
            SDRAM_CLOCK_FREQUENCY,
            64, // ms
            8192, // cycles
            SDRAM_CYCLES(20),
            SDRAM_CYCLES(42),
            SDRAM_CYCLES(70),
            SDRAM_CYCLES(18),
            SDRAM_CLOCKS(4),
            (SDRAM_CYCLES(6) + SDRAM_CLOCKS(1)),
            SDRAM_CYCLES(60),
            SDRAM_CYCLES(60),
            SDRAM_CYCLES(70),
            SDRAM_CYCLES(12),
            SDRAM_CLOCKS(2) };
    LPC17xx_40xx_SDRAM_Init_32BitBus(&sdramConfig_MT48LC2M32B2P);

#if CONFIG_MEMORY_TEST_ON_SDRAM
    MemoryTest(UEZBSP_SDRAM_BASE_ADDR, UEZBSP_SDRAM_SIZE);
#endif
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZBSP_ROMInit
 *---------------------------------------------------------------------------*
 * Description:
 *      Configure the NOR Flash
 *---------------------------------------------------------------------------*/
void UEZBSP_ROMInit(void)
{
#if 1
    const T_LPC17xx_40xx_EMC_Static_Configuration norFlash_M29W128G = {
            UEZBSP_NOR_FLASH_BASE_ADDRESS,
            16*1024*1024,  // stock is 8 Megs, but setup for 16 Megs
            EMC_STATIC_MEMORY_WIDTH_16_BITS,
            EFalse,

            EMC_STATIC_CYCLES(0),
            EMC_STATIC_CYCLES(90),
            EMC_STATIC_CYCLES(25),
            EMC_STATIC_CYCLES(0),
            EMC_STATIC_CYCLES(90),
            1, };
    LPC17xx_40xx_EMC_Static_Init(&norFlash_M29W128G);
#else
    const T_LPC17xx_40xx_EMC_Static_Configuration norSlowFlash_M29W128G = {
        UEZBSP_NOR_FLASH_BASE_ADDRESS,
        EMC_STATIC_MEMORY_WIDTH_16_BITS,
        EFalse,

        0x0F,
        0x0F,
        0x1F,
        0x0F,
        0x1F,
        0x0F,
    };
    LPC17xx_40xx_EMC_Static_Init(&norSlowFlash_M29W128G);
#endif
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZBSP_PLLConfigure
 *---------------------------------------------------------------------------*
 * Description:
 *      Configure the PLL
 *---------------------------------------------------------------------------*/
void UEZBSP_PLLConfigure(void)
{
#if (PROCESSOR_OSCILLATOR_FREQUENCY == 72000000)
    const T_LPC17xx_40xx_PLL_Frequencies freq_CPU72MHz_Peripheral60Mhz_USB48MHz = {
            12000000,

            // Run PLL0 at 120 MHz
            PROCESSOR_OSCILLATOR_FREQUENCY,

            // Run PLL1 at 48 MHz
            48000000,

            // Use the main oscillator of 12 MHz as a source
            LPC17xx_40xx_CLKSRC_SELECT_MAIN_OSCILLATOR,

            // Use PLL0 for the CCLK, PCLK, and EMC Clk source (before dividers)
            LPC17xx_40xx_CPU_CLOCK_SELECT_PLL_CLK,

            // Use PPL1 (alt) for the USB
            LPC17xx_40xx_USB_CLOCK_SELECT_ALT_PLL_CLK,

            // CPU Clock is PLL0 / 1 or 120 MHz / 1 = 120 MHz
            1,

            // PCLK is PLL0 / 2, or 60 MHz
            1,

            // EMC runs at PLL0 / 2, or 60 MHz
            1,

            // USB Clock = PLL1 / 1 (48 MHz / 1)
            1,

            // CLKOUT is on the EMC CLK and at 60 MHz (60 MHz / 1)
            LPC17xx_40xx_CLOCK_OUT_SELECT_CPU,
            1,
            ETrue, };
    
    LPC17xx_40xx_PLL_SetFrequencies(&freq_CPU72MHz_Peripheral60Mhz_USB48MHz);
    
#else // 120000000 MHz  
    
    const T_LPC17xx_40xx_PLL_Frequencies freq_CPU120MHz_Peripheral60Mhz_USB48MHz = {
            12000000,

            // Run PLL0 at 120 MHz
            PROCESSOR_OSCILLATOR_FREQUENCY,

            // Run PLL1 at 48 MHz
            48000000,

            // Use the main oscillator of 12 MHz as a source
            LPC17xx_40xx_CLKSRC_SELECT_MAIN_OSCILLATOR,

            // Use PLL0 for the CCLK, PCLK, and EMC Clk source (before dividers)
            LPC17xx_40xx_CPU_CLOCK_SELECT_PLL_CLK,

            // Use PPL1 (alt) for the USB
            LPC17xx_40xx_USB_CLOCK_SELECT_ALT_PLL_CLK,

            // CPU Clock is PLL0 / 1 or 120 MHz / 1 = 120 MHz
            1,

            // PCLK is PLL0 / 2, or 60 MHz
            2,

            // EMC runs at PLL0 / 2, or 60 MHz
            2,

            // USB Clock = PLL1 / 1 (48 MHz / 1)
            1,

            // CLKOUT is on the EMC CLK and at 60 MHz (60 MHz / 1)
            LPC17xx_40xx_CLOCK_OUT_SELECT_CPU,
            1,
            ETrue, };
    
    LPC17xx_40xx_PLL_SetFrequencies(&freq_CPU120MHz_Peripheral60Mhz_USB48MHz);
    
#endif
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZBSP_InterruptsReset
 *---------------------------------------------------------------------------*
 * Description:
 *      Do the first initialization of the interrupts.
 *---------------------------------------------------------------------------*/
void UEZBSP_InterruptsReset(void)
{
    InterruptsReset();
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZBSP_CPU_PinConfigInit
 *---------------------------------------------------------------------------*
 * Description:
 *      Immediately configure the port pins
 *---------------------------------------------------------------------------*/
void UEZBSP_CPU_PinConfigInit(void)
{
    // Place any pin configuration that MUST be initially here (at power up
    // but before even SDRAM is initialized)
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZBSP_FatalError
 *---------------------------------------------------------------------------*
 * Description:
 *      A fatal error in uEZ will come here last.  We must turn off
 *      interrupts and put the platform in a halted state with a blinking
 *      LED.
 * Inputs:
 *      int aErrorCode -- Blink the LED a number of times equal to
 *          the error code.
 *---------------------------------------------------------------------------*/
void UEZBSP_FatalError(int aErrorCode)
{
    register TUInt32 i;
    register TUInt32 count;
    // Ensure interrupts are turned off
    portDISABLE_INTERRUPTS();

    // Configure status led to be fully in our control
    // Make P1.13 be a GPIO pin
    LPC_GPIO1->PIN &= ~(3 << 3);
    // and an output pin
    LPC_GPIO1->DIR |= (1 << 13);

    // Blink our status led in a pattern, forever
    count = 0;
    while (1) {
        LPC_GPIO1->SET |= (1 << 13); // on
        for (i = 0; i < 15000000; i++)
            nop();
        //__nop();//asm ( "nop" );
        LPC_GPIO1->CLR |= (1 << 13); // off
        for (i = 0; i < 15000000; i++)
            nop();
        //__nop();//asm ( "nop" );
        count++;
        if (count >= aErrorCode) {
            // Long pause
            for (i = 0; i < 80000000; i++)
                nop();
            //__nop();//asm ( "nop" );
            count = 0;
        }
    }
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_I2C0_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the I2C0 device driver
 *---------------------------------------------------------------------------*/
void UEZPlatform_I2C0_Require(void)
{
    DEVICE_CREATE_ONCE();

    // Ensure the I2C0 exists in the HAL level
    LPC17xx_40xx_GPIO5_Require();
    LPC17xx_40xx_I2C0_Require(GPIO_P5_2, GPIO_P5_3);
    I2C_Generic_Create("I2C0", "I2C0", 0);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_I2C1_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the I2C1 device driver
 *---------------------------------------------------------------------------*/
void UEZPlatform_I2C1_Require(void)
{
    DEVICE_CREATE_ONCE();

    // Ensure the I2C0 exists in the HAL level
    LPC17xx_40xx_GPIO2_Require();
    LPC17xx_40xx_I2C1_Require(GPIO_P2_14, GPIO_P2_15);
    I2C_Generic_Create("I2C1", "I2C1", 0);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_I2C2_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the I2C2 device driver.  Usually only used when connecting
 *      to the external header.
 *---------------------------------------------------------------------------*/
void UEZPlatform_I2C2_Require(void)
{
    DEVICE_CREATE_ONCE();

    // Ensure the I2C0 exists in the HAL level
    LPC17xx_40xx_GPIO0_Require();
    LPC17xx_40xx_I2C2_Require(GPIO_P0_10, GPIO_P0_11);
    I2C_Generic_Create("I2C2", "I2C2", 0);

}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_Temp0_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the Temperature0 device driver.
 *---------------------------------------------------------------------------*/
void UEZPlatform_Temp0_Require(void)
{
    DEVICE_CREATE_ONCE();

    UEZPlatform_I2C1_Require();
    Temp_NXP_LM75A_Create("Temp0", "I2C1", 0x92 >> 1);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_Accel0_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the Accelerometer 0 device driver.
 *---------------------------------------------------------------------------*/
void UEZPlatform_Accel0_Require(void)
{
    DEVICE_CREATE_ONCE();

    UEZPlatform_I2C1_Require();
    Accelerometer_Freescale_MMA7455_I2C_Create("Accel0", "I2C1",
            MMA7455_I2C_ADDR);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_GPDMAx_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the General Purpose DMA drivers.
 *---------------------------------------------------------------------------*/
void UEZPlatform_GPDMA0_Require(void)
{
    DEVICE_CREATE_ONCE();

    LPC17xx_40xx_GPDMA0_Require();
    GPDMA_Generic_Create("GPDMA0", "GPDMA0");
}

void UEZPlatform_GPDMA1_Require(void)
{
    DEVICE_CREATE_ONCE();

    LPC17xx_40xx_GPDMA1_Require();
    GPDMA_Generic_Create("GPDMA1", "GPDMA1");
}

void UEZPlatform_GPDMA2_Require(void)
{
    DEVICE_CREATE_ONCE();

    LPC17xx_40xx_GPDMA2_Require();
    GPDMA_Generic_Create("GPDMA2", "GPDMA2");
}

void UEZPlatform_GPDMA3_Require(void)
{
    DEVICE_CREATE_ONCE();

    LPC17xx_40xx_GPDMA3_Require();
    GPDMA_Generic_Create("GPDMA3", "GPDMA3");
}

void UEZPlatform_GPDMA4_Require(void)
{
    DEVICE_CREATE_ONCE();

    LPC17xx_40xx_GPDMA4_Require();
    GPDMA_Generic_Create("GPDMA4", "GPDMA4");
}

void UEZPlatform_GPDMA5_Require(void)
{
    DEVICE_CREATE_ONCE();

    LPC17xx_40xx_GPDMA5_Require();
    GPDMA_Generic_Create("GPDMA5", "GPDMA5");
}

void UEZPlatform_GPDMA6_Require(void)
{
    DEVICE_CREATE_ONCE();

    LPC17xx_40xx_GPDMA6_Require();
    GPDMA_Generic_Create("GPDMA6", "GPDMA6");
}

void UEZPlatform_GPDMA7_Require(void)
{
    DEVICE_CREATE_ONCE();

    LPC17xx_40xx_GPDMA7_Require();
    GPDMA_Generic_Create("GPDMA7", "GPDMA7");
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_Console_FullDuplex_UART_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the console using a full duplex UART.
 * Inputs:
 *      const char *aHALSerialName -- Name of UART serial driver to use
 *      TUInt32 aWriteBufferSize -- Size in bytes of outgoing buffer
 *      TUInt32 aReadBufferSize -- Size in bytes of incoming buffer
 *---------------------------------------------------------------------------*/
void UEZPlatform_Console_FullDuplex_UART_Require(
        const char *aHALSerialName,
        TUInt32 aWriteBufferSize,
        TUInt32 aReadBufferSize)
{
    DEVICE_CREATE_ONCE();
    // NOTE: This require routine does NOT require the HAL driver
    // automatically!
    Serial_Generic_FullDuplex_Stream_Create("Console", aHALSerialName,
            aWriteBufferSize, aReadBufferSize);
    // Set standard output to console
    UEZStreamOpen("Console", &G_stdout);
    G_stdin = G_stdout;
    StdinRedirect(G_stdin);
    StdoutRedirect(G_stdout);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_Console_HalfDuplex_UART_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the console using a half duplex UART.
 * Inputs:
 *      const char *aHALSerialName -- Name of UART serial driver to use
 *      TUInt32 aWriteBufferSize -- Size in bytes of outgoing buffer
 *      TUInt32 aReadBufferSize -- Size in bytes of incoming buffer
 *      T_uezGPIOPortPin aDriveEnablePortPin -- GPIO for drive enable
 *      TBool aDriveEnablePolarity -- ETrue for high true, else EFalse
 *      TUInt32 aDriveEnableReleaseTime -- Milliseconds to wait before
 *          changing drive enable direction.
 *---------------------------------------------------------------------------*/
void UEZPlatform_Console_HalfDuplex_UART_Require(
        const char *aHALSerialName,
        TUInt32 aWriteBufferSize,
        TUInt32 aReadBufferSize,
        T_uezGPIOPortPin aDriveEnablePortPin,
        TBool aDriveEnablePolarity,
        TUInt32 aDriveEnableReleaseTime)
{
    DEVICE_CREATE_ONCE();
    // NOTE: This require routine does NOT require the HAL driver
    // automatically!
    // NOTE: This require routine does NOT require the GPIO driver
    // needed for the GPIO drive enable port pin!
    Serial_Generic_HalfDuplex_Stream_Create("Console", aHALSerialName,
            aWriteBufferSize, aReadBufferSize, aDriveEnablePortPin,
            aDriveEnablePolarity, aDriveEnableReleaseTime);
    // Set standard output to console
    UEZStreamOpen("Console", &G_stdout);
    G_stdin = G_stdout;
    StdinRedirect(G_stdin);
    StdoutRedirect(G_stdout);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_FullDuplex_UART0_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the console using a full duplex UART using UART0.
 * Inputs:
 *      TUInt32 aWriteBufferSize -- Size in bytes of outgoing buffer
 *      TUInt32 aReadBufferSize -- Size in bytes of incoming buffer
 *---------------------------------------------------------------------------*/
void UEZPlatform_FullDuplex_UART0_Require(
        TUInt32 aWriteBufferSize,
        TUInt32 aReadBufferSize)
{
    // UART0 on P0.2/P0.3
    LPC17xx_40xx_GPIO0_Require();
    LPC17xx_40xx_UART0_Require(GPIO_P0_2, GPIO_P0_3);
    Serial_Generic_FullDuplex_Stream_Create("UART0", "UART0",
            aWriteBufferSize, aReadBufferSize);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_UART1_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the raw UART1 driver.  No stream is attached.
 * Inputs:
 *      TUInt32 aWriteBufferSize -- Size in bytes of outgoing buffer
 *      TUInt32 aReadBufferSize -- Size in bytes of incoming buffer
 *---------------------------------------------------------------------------*/
void UEZPlatform_UART1_Require(void)
{
    // UART1 on P0.15/P0.16
    LPC17xx_40xx_GPIO0_Require();
    LPC17xx_40xx_UART1_Require(GPIO_P0_15, GPIO_P0_16, GPIO_NONE, GPIO_NONE,
            GPIO_NONE, GPIO_NONE, GPIO_NONE, GPIO_NONE);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_Console_FullDuplex_UART0_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the console using a full duplex UART using UART0.
 * Inputs:
 *      TUInt32 aWriteBufferSize -- Size in bytes of outgoing buffer
 *      TUInt32 aReadBufferSize -- Size in bytes of incoming buffer
 *---------------------------------------------------------------------------*/
void UEZPlatform_Console_FullDuplex_UART0_Require(
        TUInt32 aWriteBufferSize,
        TUInt32 aReadBufferSize)
{
    // UART0 on P0.2/P0.3
    LPC17xx_40xx_GPIO0_Require();
    LPC17xx_40xx_UART0_Require(GPIO_P0_2, GPIO_P0_3);
    UEZPlatform_Console_FullDuplex_UART_Require("UART0", aWriteBufferSize,
            aReadBufferSize);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_Console_FullDuplex_UART1_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the console using a full duplex UART using UART1.
 * Inputs:
 *      TUInt32 aWriteBufferSize -- Size in bytes of outgoing buffer
 *      TUInt32 aReadBufferSize -- Size in bytes of incoming buffer
 *---------------------------------------------------------------------------*/
void UEZPlatform_Console_FullDuplex_UART1_Require(
        TUInt32 aWriteBufferSize,
        TUInt32 aReadBufferSize)
{
    // UART1 on P0.15/P0.16
    LPC17xx_40xx_GPIO0_Require();
    LPC17xx_40xx_UART1_Require(GPIO_P0_15, GPIO_P0_16, GPIO_NONE, GPIO_NONE,
            GPIO_NONE, GPIO_NONE, GPIO_NONE, GPIO_NONE);
    UEZPlatform_Console_FullDuplex_UART_Require("UART1", aWriteBufferSize,
            aReadBufferSize);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_FullDuplex_UART1_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the console using a full duplex UART using UART1.
 * Inputs:
 *      TUInt32 aWriteBufferSize -- Size in bytes of outgoing buffer
 *      TUInt32 aReadBufferSize -- Size in bytes of incoming buffer
 *---------------------------------------------------------------------------*/
void UEZPlatform_FullDuplex_UART1_Require(
        TUInt32 aWriteBufferSize,
        TUInt32 aReadBufferSize)
{
    // UART1 on P0.15/P0.16
    LPC17xx_40xx_GPIO0_Require();
    LPC17xx_40xx_UART1_Require(GPIO_P0_15, GPIO_P0_16, GPIO_NONE, GPIO_NONE,
            GPIO_NONE, GPIO_NONE, GPIO_NONE, GPIO_NONE);
    Serial_Generic_FullDuplex_Stream_Create("UART1", "UART1",
            aWriteBufferSize, aReadBufferSize);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_Console_FullDuplex_UART2_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the console using a full duplex UART using UART2.
 * Inputs:
 *      TUInt32 aWriteBufferSize -- Size in bytes of outgoing buffer
 *      TUInt32 aReadBufferSize -- Size in bytes of incoming buffer
 *---------------------------------------------------------------------------*/
void UEZPlatform_Console_FullDuplex_UART2_Require(
        TUInt32 aWriteBufferSize,
        TUInt32 aReadBufferSize)
{
    // UART2 on P0.10/P0.11
    LPC17xx_40xx_GPIO0_Require();
    LPC17xx_40xx_UART2_Require(GPIO_P0_10, GPIO_P0_11);
    UEZPlatform_Console_FullDuplex_UART_Require("UART2", aWriteBufferSize,
            aReadBufferSize);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_Console_FullDuplex_UART3_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the console using a full duplex UART using UART3.
 * Inputs:
 *      TUInt32 aWriteBufferSize -- Size in bytes of outgoing buffer
 *      TUInt32 aReadBufferSize -- Size in bytes of incoming buffer
 *---------------------------------------------------------------------------*/
void UEZPlatform_Console_FullDuplex_UART3_Require(
        TUInt32 aWriteBufferSize,
        TUInt32 aReadBufferSize)
{
    // UART3 on P0.0/P0.1
    LPC17xx_40xx_GPIO0_Require();
    LPC17xx_40xx_UART3_Require(GPIO_P0_0, GPIO_P0_1);
    UEZPlatform_Console_FullDuplex_UART_Require("UART3", aWriteBufferSize,
            aReadBufferSize);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_Console_FullDuplex_ISPHeader_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the console to be a full duplex UART on the ISP header
 * Inputs:
 *      TUInt32 aWriteBufferSize -- Size in bytes of outgoing buffer
 *      TUInt32 aReadBufferSize -- Size in bytes of incoming buffer
 *---------------------------------------------------------------------------*/
void UEZPlatform_Console_ISPHeader_Require(
        TUInt32 aWriteBufferSize,
        TUInt32 aReadBufferSize)
{
    // Standard ISP header is on UART0
    UEZPlatform_Console_FullDuplex_UART0_Require(aWriteBufferSize,
            aReadBufferSize);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_Console_Expansion_ISPHeader_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the console to be a full duplex UART on the expansion header
 *      NOTE: On expansion header
 * Inputs:
 *      TUInt32 aWriteBufferSize -- Size in bytes of outgoing buffer
 *      TUInt32 aReadBufferSize -- Size in bytes of incoming buffer
 *---------------------------------------------------------------------------*/
void UEZPlatform_Console_Expansion_Require(
        TUInt32 aWriteBufferSize,
        TUInt32 aReadBufferSize)
{
    // Standard Expansion board serial console is on UART0
    UEZPlatform_Console_FullDuplex_UART0_Require(aWriteBufferSize,
            aReadBufferSize);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_SSP0_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the SSP0 to be a SPI driver
 *---------------------------------------------------------------------------*/
void UEZPlatform_SSP0_Require(void)
{
    DEVICE_CREATE_ONCE();

    // SCK0 is P2.22, MISO0 is P2.26, MOSI0 is P2.27, SSEL0 is not used
    LPC17xx_40xx_GPIO2_Require();
    LPC17xx_40xx_SSP0_Require(GPIO_P2_22, GPIO_P2_26, GPIO_P2_27, GPIO_NONE);

    SPI_Generic_Create("SSP0", "SSP0");
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_SSP1_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the SSP1 to be a SPI driver.
 *      NOTE: On expansion header
 *---------------------------------------------------------------------------*/
void UEZPlatform_SSP1_Require(void)
{
    DEVICE_CREATE_ONCE();

    // SCK1 is P0.7, MISO1 is P0.8, MOSI1 is P0.9, SSEL1 is P0.6
    LPC17xx_40xx_GPIO0_Require();
    LPC17xx_40xx_SSP1_Require(GPIO_P0_7, GPIO_P0_8, GPIO_P0_9, GPIO_P0_6);

    SPI_Generic_Create("SSP1", "SSP1");
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_ADC0_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the ADC0 device driver.
 *---------------------------------------------------------------------------*/
void UEZPlatform_ADC0_Require(void)
{
    DEVICE_CREATE_ONCE();
    LPC17xx_40xx_ADC0_Require();
    ADCBank_Generic_Create("ADC0", "ADC0");
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_ADC0_0_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the ADC0_0 channel on the ADC0 device driver
 *---------------------------------------------------------------------------*/
void UEZPlatform_ADC0_0_Require(void)
{
    DEVICE_CREATE_ONCE();
    LPC17xx_40xx_ADC0_0_Require(GPIO_P0_23);
    UEZPlatform_ADC0_Require();
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_ADC0_1_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the ADC0_1 channel on the ADC0 device driver
 *---------------------------------------------------------------------------*/
void UEZPlatform_ADC0_1_Require(void)
{
    DEVICE_CREATE_ONCE();
    LPC17xx_40xx_ADC0_1_Require(GPIO_P0_24);
    UEZPlatform_ADC0_Require();
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_ADC0_2_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the ADC0_2 channel on the ADC0 device driver
 *---------------------------------------------------------------------------*/
void UEZPlatform_ADC0_2_Require(void)
{
    DEVICE_CREATE_ONCE();
    LPC17xx_40xx_ADC0_2_Require(GPIO_P0_25);
    UEZPlatform_ADC0_Require();
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_ADC0_3_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the ADC0_3 channel on the ADC0 device driver
 *---------------------------------------------------------------------------*/
void UEZPlatform_ADC0_3_Require(void)
{
    DEVICE_CREATE_ONCE();
    LPC17xx_40xx_ADC0_3_Require(GPIO_P0_26);
    UEZPlatform_ADC0_Require();
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_ADC0_4_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the ADC0_4 channel on the ADC0 device driver
 *---------------------------------------------------------------------------*/
void UEZPlatform_ADC0_4_Require(void)
{
    DEVICE_CREATE_ONCE();
    LPC17xx_40xx_ADC0_4_Require(GPIO_P1_30);
    UEZPlatform_ADC0_Require();
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_ADC0_5_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the ADC0_5 channel on the ADC0 device driver
 *---------------------------------------------------------------------------*/
void UEZPlatform_ADC0_5_Require(void)
{
    DEVICE_CREATE_ONCE();
    LPC17xx_40xx_ADC0_5_Require(GPIO_P1_31);
    UEZPlatform_ADC0_Require();
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_ADC0_6_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the ADC0_6 channel on the ADC0 device driver
 *---------------------------------------------------------------------------*/
void UEZPlatform_ADC0_6_Require(void)
{
    DEVICE_CREATE_ONCE();
    LPC17xx_40xx_ADC0_6_Require(GPIO_P0_12);
    UEZPlatform_ADC0_Require();
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_ADC0_7_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the ADC0_7 channel on the ADC0 device driver
 *---------------------------------------------------------------------------*/
void UEZPlatform_ADC0_7_Require(void)
{
    DEVICE_CREATE_ONCE();
    LPC17xx_40xx_ADC0_7_Require(GPIO_P0_13);
    UEZPlatform_ADC0_Require();
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_DAC0_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the DAC0 device driver
 *      NOTE: Goes to P0.26_AD03_AOUT_RD3
 *---------------------------------------------------------------------------*/
void UEZPlatform_DAC0_Require(void)
{
    DEVICE_CREATE_ONCE();
    LPC17xx_40xx_DAC0_Require(GPIO_P0_26);
    DAC_Generic_Create("DAC0", "DAC0");
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_Flash0_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the Flash0 device driver for the external NOR Flash
 *---------------------------------------------------------------------------*/
void UEZPlatform_Flash0_Require(void)
{
    DEVICE_CREATE_ONCE();
    Flash_S29GL064N90_16Bit_Create("Flash0", NOR_FLASH_BASE_ADDR);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_IAP_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the IAP flash device driver for the internal flash
 *---------------------------------------------------------------------------*/
void UEZPlatform_IAP_Require(void)
{
    DEVICE_CREATE_ONCE();
    Flash_NXP_LPC17xx_40xx_Create("IAP");
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_Backlight_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the Backlight device driver for the LCD
 *---------------------------------------------------------------------------*/
void UEZPlatform_Backlight_Require(void)
{
    const T_backlightGenericPWMSettings settings = {
            "PWM0",
            0, // master register
            1, // backlight register (PWM0_1)
            UEZ_LCD_BACKLIGHT_FULL_PERIOD,
            UEZ_LCD_BACKLIGHT_FULL_PWR_ON,
            UEZ_LCD_BACKLIGHT_FULL_PWR_OFF,
            GPIO_NONE,
            EFalse
    };
    DEVICE_CREATE_ONCE();
    LPC17xx_40xx_PWM0_1_Require(GPIO_P1_2);
    LPC17xx_40xx_GPIO4_Require();
    UEZGPIOLock(GPIO_P4_31);
    UEZGPIOOutput(GPIO_P4_31);
    Backlight_Generic_PWMControlled_Create("Backlight", &settings);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_LCD_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the LCD device driver and its backlight
 *---------------------------------------------------------------------------*/
void UEZPlatform_LCD_Require(void)
{
    const T_LPC17xx_40xx_LCDController_Pins pins = {
            GPIO_NONE,  // LCD_PWR -- GPIO controlled       
            GPIO_P2_2,  // LCD_DCLK
            GPIO_P2_4,  // LCD_ENAB_M
            GPIO_NONE,  // LCD_FP
            GPIO_NONE,  // LCD_LE
            GPIO_NONE,  // LCD_LP

            GPIO_NONE,  // LCD_VD0
            GPIO_NONE,  // LCD_VD1
            GPIO_P4_28, // LCD_VD2
            GPIO_P4_29, // LCD_VD3
            GPIO_P2_6,  // LCD_VD4
            GPIO_P2_7,  // LCD_VD5
            GPIO_P2_8,  // LCD_VD6
            GPIO_P2_9,  // LCD_VD7

            GPIO_NONE,  // LCD_VD8
            GPIO_NONE,  // LCD_VD9
            GPIO_P1_20, // LCD_VD10
            GPIO_P1_21, // LCD_VD11
            GPIO_P1_22, // LCD_VD12
            GPIO_P1_23, // LCD_VD13
            GPIO_P1_24, // LCD_VD14
            GPIO_P1_25, // LCD_VD15

            GPIO_NONE,  // LCD_VD16
            GPIO_NONE,  // LCD_VD17
            GPIO_P2_12, // LCD_VD18
            GPIO_P2_13, // LCD_VD19
            GPIO_P1_26, // LCD_VD20
            GPIO_P1_27, // LCD_VD21
            GPIO_P1_28, // LCD_VD22
            GPIO_P1_29, // LCD_VD23

            GPIO_NONE,  // LCD_CLKIN
            
            GPIO_P2_0, // P2.0 is power pin, GPIO controlled
            EFalse, // Active LOW
            250, // 250 ms control
    };
    T_halWorkspace *p_lcdc;
    T_uezDeviceWorkspace *p_lcd;
    T_uezDevice backlight;
    T_uezDeviceWorkspace *p_backlight;
    extern const T_uezDeviceInterface *UEZ_LCD_INTERFACE_ARRAY[];

    DEVICE_CREATE_ONCE();
    LPC17xx_40xx_GPIO1_Require();
    LPC17xx_40xx_GPIO2_Require();
    LPC17xx_40xx_GPIO4_Require();
    LPC17xx_40xx_LCDController_Require(&pins);
    UEZPlatform_Backlight_Require();

    // Need to register LCD device and use existing LCD Controller
    UEZDeviceTableRegister(
            "LCD",
            (T_uezDeviceInterface *)UEZ_LCD_INTERFACE_ARRAY[UEZ_LCD_COLOR_DEPTH],
            0,
            &p_lcd);

    HALInterfaceFind("LCDController", &p_lcdc);
    UEZDeviceTableFind("Backlight", &backlight);
    UEZDeviceTableGetWorkspace(backlight, (T_uezDeviceWorkspace **)&p_backlight);
    ((DEVICE_LCD *)(p_lcd->iInterface))->Configure(
            p_lcd,
            (HAL_LCDController **)p_lcdc,
            LCD_DISPLAY_BASE_ADDRESS,
            (DEVICE_Backlight **)p_backlight);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_Speaker_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the Speaker device driver
 *---------------------------------------------------------------------------*/
void UEZPlatform_Speaker_Require(void)
{
    const T_ToneGenerator_Generic_PWM_Settings settings = {
            "PWM1",
            2, // PWM1[2]
            GPIO_P2_1,
            0, // 0 mux = GPIO
            1, // 1 mux = PWM1_2
    };
    DEVICE_CREATE_ONCE();

    LPC17xx_40xx_PWM1_2_Require(GPIO_P2_1);

    // Speaker is on PWM1[2]
    ToneGenerator_Generic_PWM_Create("Speaker", &settings);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_IRTC_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the internal RTC device driver.  Not compatible with the
 *      external RTC.
 *---------------------------------------------------------------------------*/
void UEZPlatform_IRTC_Require(void)
{
    DEVICE_CREATE_ONCE();

    LPC17xx_40xx_RTC_Require(ETrue);
    RTC_Generic_Create("RTC", "RTC");
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_IRTC_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the external RTC device driver.  Not compatible with the
 *      internal RTC.
 *---------------------------------------------------------------------------*/
void UEZPlatform_ERTC_Require(void)
{
    DEVICE_CREATE_ONCE();

    UEZPlatform_I2C1_Require();
    RTC_PCF8563_Create("RTC", "I2C1");
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_RTC_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the RTC device driver and check it for validity
 *---------------------------------------------------------------------------*/
void UEZPlatform_RTC_Require(void)
{
    T_uezDevice rtcDev;
    DEVICE_RTC **p_rtcDev;
    const T_uezTimeDate resetTD = {
        {   0, 0, 0}, // 12:00 midnight
        {   1, 1, 2009}, // Jan 1, 2009
    };
    T_uezError error;

    // Choose one:
    UEZPlatform_IRTC_Require();
    //UEZPlatform_ERTC_Require();

    // Make sure the RTC has valid data
    printf("Checking RTC ...\n");
    UEZDeviceTableFind("RTC", &rtcDev);
    UEZDeviceTableGetWorkspace(rtcDev, (T_uezDeviceWorkspace **)&p_rtcDev);
    error = (*p_rtcDev)->Validate(p_rtcDev, &resetTD);
    if (error == UEZ_ERROR_INVALID) {
        printf("RTC was invalid, reset to 01/01/2009 12:00:00\n");
    } else if (error != UEZ_ERROR_NONE) {
        printf("RTC error #%d!  Could not check validity!\n", error);
    } else {
        printf("RTC OK\n");
    }

#if 0 // Test code for doing Clock out
    // Make sure the clock out is disabled
    error = (*p_rtcDev)->SetClockOutHz(p_rtcDev, 32768);
    if (error == UEZ_ERROR_NONE) {
        printf("RTC Clock out disabled\n");
    } else {
        printf("RTC Clock out error #%d!\n", error);
    }
#endif
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_EEPROM_I2C_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the external EEPROM over I2C.
 *---------------------------------------------------------------------------*/
void UEZPlatform_EEPROM_I2C_Require(void)
{
    const T_EEPROMConfig eeprom_config = {EEPROM_CONFIG_PCA24S08};

    DEVICE_CREATE_ONCE();
    UEZPlatform_I2C1_Require();
    EEPROM16_Generic_I2C_Create("EEPROM0", "I2C1", 0xA0>>1, &eeprom_config);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_EEPROM_I2C_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the internal EEPROM in the LPC17xx_40xx
 *---------------------------------------------------------------------------*/
void UEZPlatform_EEPROM_LPC17xx_40xx_Require(void)
{
    DEVICE_CREATE_ONCE();
    EEPROM_NXP_LPC17xx_40xx_Create("EEPROM0");
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_EEPROM0_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the default EEPROM0 driver (usually internal LPC17xx_40xx)
 *---------------------------------------------------------------------------*/
void UEZPlatform_EEPROM0_Require(void)
{
    // Pick one of these two for the type of EEPROM
    UEZPlatform_EEPROM_LPC17xx_40xx_Require();
    //UEZPlatform_EEPROM_I2C_Require();
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_Watchdog_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the internal watchdog.
 *---------------------------------------------------------------------------*/
void UEZPlatform_Watchdog_Require(void)
{
    DEVICE_CREATE_ONCE();
    LPC17xx_40xx_Watchdog_Require();
    Watchdog_Generic_Create("Watchdog", "Watchdog");
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_USBHost_PortA_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the USB Host on Port A (expansion board).
 *---------------------------------------------------------------------------*/
void UEZPlatform_USBHost_PortA_Require(void)
{
    const T_LPC17xx_40xx_USBHost_Settings portASettings = {
            GPIO_P0_29,     // USB_D+1          = P0.29_USB1_DP_EINT0
            GPIO_P0_30,     // USB_D-1          = P0.30_USB1_DM_EINT1
            GPIO_NONE,      // USB_CONNECT1n
            GPIO_NONE,      // USB_UP_LED1
            GPIO_NONE,      // USB_INT1n
            GPIO_NONE,      // USB_SCL1
            GPIO_NONE,      // USB_SDA1
            GPIO_NONE,      // USB_TX_E
            GPIO_NONE,      // USB_TX_DP
            GPIO_NONE,      // USB_TX_DM
            GPIO_NONE,      // USB_RCV
            GPIO_NONE,      // USB_RX_DP
            GPIO_NONE,      // USB_RX_DM
            GPIO_NONE,      // USB_LS1
            GPIO_NONE,      // USB_SSPND1
            GPIO_P1_19,     // USB_PPWR1        = USB1H_PPWR
            GPIO_NONE,      // USB_PWRD1        = USB1H_PWRD
            GPIO_NONE,      // USB_OVRCR1       = USB1H_OVC
            GPIO_NONE,      // USB_HSTEN1
    };
    DEVICE_CREATE_ONCE();

    LPC17xx_40xx_USBHost_PortA_Require(&portASettings);
    USBHost_Generic_Create("USBHost", "USBHost:PortA");
    // NOTE: USB1H_PWRD is on GPIO_P4_26 and is manually controlled
    // NOTE: USB1H_OVR  is on GPIO_P4_27 and is manually controlled
    LPC17xx_40xx_GPIO4_Require();
}

TBool UEZPlatform_Host_Port_B_Detect()
{
    TBool IsDevice;
 
    UEZGPIOLock(GPIO_P0_12);
    UEZGPIOSet(GPIO_P0_12); // disable MIC2025
    UEZGPIOOutput(GPIO_P0_12);
    UEZGPIOInput(GPIO_P0_28);
    UEZGPIOSetMux(GPIO_P0_28, 0);

    IsDevice = UEZGPIORead(GPIO_P0_28);

    if(!IsDevice){
        UEZGPIOClear(GPIO_P0_12);// enable MIC2025
    }
    return IsDevice;
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_USBHost_PortB_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the USB Host on Port B.
 *---------------------------------------------------------------------------*/
void UEZPlatform_USBHost_PortB_Require(void)
{
//    GPIO_P1_30,     // USB_VBUS2        = USB2_VBUS
//    GPIO_P0_31,     // USB_D+2          = USB2_DP
//    GPIO_NONE,      // USB_D-2          = USB2_DM (not a port pin)
//    GPIO_P0_14,     // USB_CONNECT2n    = USB2_CON
//    GPIO_P0_13,     // USB_UP_LED2      = P0.13_USB2_UPLED_AD0.7
    const T_LPC17xx_40xx_USBHost_Settings portBSettings = {
            GPIO_P0_31,     // USB_D+2          = P0.29_USB1_DP_EINT0
            GPIO_NONE,       // USB_D-2          = P0.30_USB1_DM_EINT1
            GPIO_P0_14,      // USB_CONNECT2n
            GPIO_P0_13,      // USB_UP_LED2
            GPIO_NONE,      // USB_INT2n
            GPIO_NONE,      // USB_SCL2
            GPIO_NONE,      // USB_SDA2
            GPIO_NONE,      // USB_TX_E
            GPIO_NONE,      // USB_TX_DP
            GPIO_NONE,      // USB_TX_DM
            GPIO_NONE,      // USB_RCV
            GPIO_NONE,      // USB_RX_DP
            GPIO_NONE,      // USB_RX_DM
            GPIO_NONE,      // USB_LS2
            GPIO_NONE,      // USB_SSPND2
            GPIO_NONE,      // USB_PPWR
            GPIO_NONE,      // USB_PWRD2
            GPIO_NONE, // GPIO_P0_27, (cannot go here)     // USB_OVRCR2       = USB2H_OVC
            GPIO_NONE,      // USB_HSTEN2
    };
    DEVICE_CREATE_ONCE();
    LPC17xx_40xx_USBHost_PortB_Require(&portBSettings);
    USBHost_Generic_Create("USBHost", "USBHost:PortB");
    // NOTE: USB1H_PWRD is on GPIO_P4_26 and is manually controlled
    // NOTE: USB1H_OVR  is on GPIO_P4_27 and is manually controlled
    //LPC17xx_40xx_GPIO4_Require();
    // P1.30 needs to be VBUS (USB controlled)
    UEZGPIOSetMux(GPIO_P1_30, 2); // disabled 
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_USBHost_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the USB Host.
 *---------------------------------------------------------------------------*/
void UEZPlatform_USBHost_Require(void)
{
    UEZPlatform_USBHost_PortA_Require();
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_FileSystem_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the File System using FATFS
 *---------------------------------------------------------------------------*/
void UEZPlatform_FileSystem_Require(void)
{
    T_uezDevice dev_fs;

    DEVICE_CREATE_ONCE();

    FileSystem_FATFS_Create("FATFS");
    UEZDeviceTableFind("FATFS", &dev_fs);
    UEZFileSystemInit();
    UEZFileSystemMount(dev_fs, "/");
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_MS0_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the Mass Storage device MS0 using USBHost flash drive.
 *---------------------------------------------------------------------------*/
void UEZPlatform_MS0_Require(void)
{
    DEVICE_CREATE_ONCE();

    MassStorage_USB_Create("MS0", "USBHost");
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_MS1_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the Mass Storage device MS1 using SDCard drive.
 *---------------------------------------------------------------------------*/
void UEZPlatform_MS1_Require(void)
{
    DEVICE_CREATE_ONCE();

    UEZPlatform_SSP0_Require();
    LPC17xx_40xx_GPIO2_Require();
    // MICROSD_CSn = P2.21
    MassStorage_SDCard_Create("MS1", "SSP0", GPIO_P2_21);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_MCI_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the MCI Peripheral
 *---------------------------------------------------------------------------*/
void UEZPlatform_MCI_Require(void)
{
	  const T_LPC17xx_40xx_MCI_Pins pins = {
        GPIO_P1_6, // DAT0
        GPIO_P1_7, // DAT1
        GPIO_P1_11, // DAT2
        GPIO_P1_12, // DAT3
        GPIO_P0_19, // CLK
#if UEZGUI_EXP_BRK_OUT
        GPIO_P0_20,  // CMD
#else
        GPIO_P1_3,
#endif
        GPIO_NONE, // GPIO_P1_3, // Card Detect
        GPIO_P1_5, // Write Protect Detect
    };
    DEVICE_CREATE_ONCE();
    
    UEZPlatform_GPDMA1_Require();
    LPC17xx_40xx_MCI_Require(&pins, "GPDMA1");
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_MS1_MCI_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the Mass Storage device MS1 using high speed SDCard drive.
 *---------------------------------------------------------------------------*/
void UEZPlatform_MS1_MCI_Require(void)
{
    DEVICE_CREATE_ONCE();

    UEZPlatform_MCI_Require();
    UEZPlatform_GPDMA1_Require();
    MassStorage_SDCard_MCI_Create("MS1", "MCI", "GPDMA1");
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_SDCard_MCI_Drive_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the high speed SDCard drive using MS1 on the given drive number
 *---------------------------------------------------------------------------*/
void UEZPlatform_SDCard_MCI_Drive_Require(TUInt8 aDriveNum)
{
    T_uezDevice ms1;
    T_uezDeviceWorkspace *p_ms1;

    DEVICE_CREATE_ONCE();

    UEZPlatform_MS1_MCI_Require();
    UEZPlatform_FileSystem_Require();

    UEZDeviceTableFind("MS1", &ms1);
    UEZDeviceTableGetWorkspace(ms1, (T_uezDeviceWorkspace **)&p_ms1);
    FATFS_RegisterMassStorageDevice(aDriveNum, (DEVICE_MassStorage **)p_ms1);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_USBFlash_Drive_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the USB Flash drive using MS0 on the given drive number
 *---------------------------------------------------------------------------*/
void UEZPlatform_USBFlash_Drive_Require(TUInt8 aDriveNum)
{
    T_uezDevice ms0;
    T_uezDeviceWorkspace *p_ms0;

    DEVICE_CREATE_ONCE();

    // Now put the MS0 in the filesystem using the USB
    UEZPlatform_MS0_Require();
    UEZPlatform_FileSystem_Require();

    UEZDeviceTableFind("MS0", &ms0);
    UEZDeviceTableGetWorkspace(ms0, (T_uezDeviceWorkspace **)&p_ms0);
    FATFS_RegisterMassStorageDevice(aDriveNum, (DEVICE_MassStorage **)p_ms0);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_SDCard_Drive_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the SDCard drive using MS1 on the given drive number
 *---------------------------------------------------------------------------*/
void UEZPlatform_SDCard_Drive_Require(TUInt8 aDriveNum)
{
    T_uezDevice ms1;
    T_uezDeviceWorkspace *p_ms1;

    DEVICE_CREATE_ONCE();

    UEZPlatform_MS1_Require();
    UEZPlatform_FileSystem_Require();

    UEZDeviceTableFind("MS1", &ms1);
    UEZDeviceTableGetWorkspace(ms1, (T_uezDeviceWorkspace **)&p_ms1);
    FATFS_RegisterMassStorageDevice(aDriveNum, (DEVICE_MassStorage **)p_ms1);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_AudioCodec_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      
 *---------------------------------------------------------------------------*/
void UEZPlatform_AudioCodec_Require(void)
{
    T_uezDevice p_ac;
    DEVICE_AudioCodec **ac;

    DEVICE_CREATE_ONCE();

    AudioCodec_WM8731_ADXL345_Create("AudioCodec0", "I2C2");
    UEZDeviceTableFind("AudioCodec0", &p_ac);
    UEZDeviceTableGetWorkspace(p_ac, (T_uezDeviceWorkspace **)&ac);

    (*ac)->UseConfiguration((void*)ac, 0);
}

static T_uezDevice G_Amp;
/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_AudioAmp_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the Audio Amp driver and set the default level
 *---------------------------------------------------------------------------*/
void UEZPlatform_AudioAmp_Require(void)
{
    DEVICE_CREATE_ONCE();

    LPC17xx_40xx_GPIO0_Require();
    // P2.3 = VOL_UD
    // P2.5 = AMP_MODE
    AudioAmp_8551T_Create("AMP0", GPIO_P2_3, GPIO_P2_5, GPIO_NONE, 64);

    UEZAudioAmpOpen("AMP0", &G_Amp);
    UEZAudioAmpSetLevel(G_Amp, UEZ_DEFAULT_AUDIO_LEVEL);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZGUI70WVT_AudioMixerCallback
 *---------------------------------------------------------------------------*
 * Description:
 *
 *---------------------------------------------------------------------------*/
static T_uezError UEZGUI70WVT_AudioMixerCallback(
        T_uezAudioMixerOutput aChangedOutput,
            TBool aMute,
            TUInt8 aLevel)
{
    T_uezError error = UEZ_ERROR_NONE;

    switch(aChangedOutput){
        case  UEZ_AUDIO_MIXER_OUTPUT_ONBOARD_SPEAKER:
            if(G_Amp){
                if(aMute){
                    error = UEZAudioAmpMute(G_Amp);
                } else {
                    error = UEZAudioAmpUnMute(G_Amp);
                }
                error = UEZAudioAmpSetLevel(G_Amp, aLevel);
            }
            break;
        default:
            break;
    }
    return error;
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_AudioMixer_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the Audio Mixer driver and callback function
 *---------------------------------------------------------------------------*/
void UEZPlatform_AudioMixer_Require(void)
{
    DEVICE_CREATE_ONCE();

    UEZPlatform_AudioAmp_Require();
    UEZAudioMixerRegister(UEZ_AUDIO_MIXER_OUTPUT_ONBOARD_SPEAKER, &UEZGUI70WVT_AudioMixerCallback);
    UEZAudioMixerSetLevel(UEZ_AUDIO_MIXER_OUTPUT_ONBOARD_SPEAKER, 255);
    UEZAudioMixerUnmute(UEZ_AUDIO_MIXER_OUTPUT_ONBOARD_SPEAKER);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_CRC0_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the CRC0 drivers for doing CRC calculations
 *---------------------------------------------------------------------------*/
void UEZPlatform_CRC0_Require(void)
{
    DEVICE_CREATE_ONCE();

    LPC17xx_40xx_CRC0_Require();
    CRC_Generic_Create("CRC0", "CRC0");
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_PWM0_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the PWM0 drivers
 *---------------------------------------------------------------------------*/
void UEZPlatform_PWM0_Require(void)
{
    DEVICE_CREATE_ONCE();

   LPC17xx_40xx_PWM0_Require();
   // Current UEZGUI does not use these, but may need one later
   //LPC17xx_40xx_PWM0_1_Require(pin?);
   //LPC17xx_40xx_PWM0_2_Require(pin?);
   //LPC17xx_40xx_PWM0_3_Require(pin?);
   //LPC17xx_40xx_PWM0_4_Require(pin?);
   //LPC17xx_40xx_PWM0_5_Require(pin?);
   //LPC17xx_40xx_PWM0_6_Require(pin?);
   //LPC17xx_40xx_PWM0_CAP0_Require(pin?);
   PWM_Generic_Create("PWM0", "PWM0");
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_PWM1_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the PWM1 driver
 *---------------------------------------------------------------------------*/
void UEZPlatform_PWM1_Require(void)
{
    DEVICE_CREATE_ONCE();

   LPC17xx_40xx_PWM1_Require();
   // Current UEZGUI does not use these, but may need one later
   //LPC17xx_40xx_PWM1_1_Require(pin?);
   //LPC17xx_40xx_PWM1_2_Require(pin?);
   //LPC17xx_40xx_PWM1_3_Require(pin?);
   //LPC17xx_40xx_PWM1_4_Require(pin?);
   //LPC17xx_40xx_PWM1_5_Require(pin?);
   //LPC17xx_40xx_PWM1_6_Require(pin?);
   //LPC17xx_40xx_PWM1_CAP0_Require(pin?);
   //LPC17xx_40xx_PWM1_CAP1_Require(pin?);
   PWM_Generic_Create("PWM1", "PWM1");
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_Touchscreen_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the touchscreen and touch sensitivity for four wire resistive
 *---------------------------------------------------------------------------*/
void UEZPlatform_Touchscreen_Require(void)
{
    T_uezDevice ts;

#if UEZGUI_7_REV2_BOARD_SWAP_TP_LINES
    const TS_FourWireTouchResist_Configuration tsConfig = {
            // XPlus ADC = ADC0.0 / P0.23
            { "ADC0",   0,  GPIO_P0_23,     0,      1 },
            // XMinus GPIO = P2.19
            { GPIO_P2_19 },
            // YPlus ADC = ADC0.1 / P0.24
            { "ADC0",   1,  GPIO_P0_24,     0,      1 },
            // YMinus GPIO = P1.18
            { GPIO_P1_18 },
            // Use IRQs?
            ETrue,
            // Need input buffer disabled when doing A/Ds?
            ETrue,
    };
#else
    const TS_FourWireTouchResist_Configuration tsConfig = {
            // XPlus ADC = ADC0.0 / P0.23
            { "ADC0",   0,  GPIO_P0_23,     0,      1 },
            // XMinus GPIO = P1.18
            { GPIO_P1_18 },
            // YPlus ADC = ADC0.1 / P0.24
            { "ADC0",   1,  GPIO_P0_24,     0,      1 },
            // YMinus GPIO = P2.19
            { GPIO_P2_19 },
            // Use IRQs?
            ETrue,
            // Need input buffer disabled when doing A/Ds?
            ETrue,
    };
#endif

    DEVICE_CREATE_ONCE();

    LPC17xx_40xx_GPIO0_Require();
    LPC17xx_40xx_GPIO1_Require();
    LPC17xx_40xx_GPIO2_Require();
    UEZPlatform_ADC0_0_Require();
    UEZPlatform_ADC0_1_Require();

    Touchscreen_FourWireTouchResist_Create("Touchscreen", &tsConfig);
    UEZDeviceTableFind("Touchscreen", &ts);
    UEZTSSetTouchDetectSensitivity(ts, 0x2000, 0x6000);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_USBDevice_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the USBDevice controller.
 *---------------------------------------------------------------------------*/
void UEZPlatform_USBDevice_Require(void)
{
    const T_LPC17xx_40xx_USBDevice_Settings portBSettings = {
            GPIO_P1_30,     // USB_VBUS2        = USB2_VBUS
            GPIO_P0_31,     // USB_D+2          = USB2_DP
            GPIO_NONE,      // USB_D-2          = USB2_DM (not a port pin)
            GPIO_P0_14,     // USB_CONNECT2n    = USB2_CON
            GPIO_P0_13,     // USB_UP_LED2      = P0.13_USB2_UPLED_AD0.7
    };
    DEVICE_CREATE_ONCE();

    LPC17xx_40xx_USBDevice_PortB_Require(&portBSettings);
    USBDevice_LPC17xx_40xx_Create("USBDevice", "USBDeviceController");
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_EMAC_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the EMAC controller for networking.
 *---------------------------------------------------------------------------*/
void UEZPlatform_EMAC_Require(void)
{
    // This EMAC is RMII (less pins)
    const T_LPC17xx_40xx_EMAC_Settings emacSettings = {
            GPIO_P1_4,      // ENET_TX_ENn      = P1.4_ENET_TXEN
            GPIO_NONE,      // ENET_TX_TXD[3]   = not used for RMII
            GPIO_NONE,      // ENET_TX_TXD[2]   = not used for RMII
            GPIO_P1_1,      // ENET_TX_TXD[1]   = P1.1_ENET_TXD1
            GPIO_P1_0,      // ENET_TX_TXD[0]   = P1.0_ENET_TXD0
            GPIO_NONE,      // ENET_TX_ER       = not used for RMII
            GPIO_NONE,      // ENET_TX_CLK      = not used for RMII
            GPIO_NONE,      // ENET_RX_DV       = not used for RMII
            GPIO_NONE,      // ENET_RXD[3]      = not used for RMII
            GPIO_NONE,      // ENET_RXD[2]      = not used for RMII
            GPIO_P1_10,     // ENET_RXD[1]      = P1.10_ENET_RXD1
            GPIO_P1_9,      // ENET_RXD[0]      = P1.9_ENET_RXD0
            GPIO_P1_14,     // ENET_RX_ER       = P1.14_ENET_RX_ER
            GPIO_P1_15,     // ENET_REFCLK      = P1.15_ENET_REFCLK
            GPIO_NONE,      // ENET_COL         = not used for RMII
            GPIO_P1_8,      // ENET_CRS         = P1.8_ENET_CRSDV
            GPIO_P1_16,     // ENET_MDC         = P1.16_ENET_MDC
            GPIO_P1_17,     // ENET_MDIO        = P1.17_ENET_MDIO
    };
    DEVICE_CREATE_ONCE();

    LPC17xx_40xx_EMAC_RMII_Require(&emacSettings);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_Timer0_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the Timer0 drivers, but don't set any capture sources or
 *      match registers.
 *---------------------------------------------------------------------------*/
void UEZPlatform_Timer0_Require(void)
{
    static const T_LPC17xx_40xx_Timer_Settings settings = {
            GPIO_NONE,      // T0_CAP[0]
            GPIO_NONE,      // T0_CAP[1]
            GPIO_NONE,      // T0_MAT[0]
            GPIO_NONE,      // T0_MAT[1]
            GPIO_NONE,      // T0_MAT[2]
            GPIO_NONE,      // T0_MAT[3]
    };
    DEVICE_CREATE_ONCE();
    LPC17xx_40xx_Timer0_Require(&settings);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_Timer1_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the Timer1 drivers, but don't set any capture sources or
 *      match registers.
 *---------------------------------------------------------------------------*/
void UEZPlatform_Timer1_Require(void)
{
    static const T_LPC17xx_40xx_Timer_Settings settings = {
            GPIO_NONE,      // T0_CAP[0]
            GPIO_NONE,      // T0_CAP[1]
            GPIO_NONE,      // T0_MAT[0]
            GPIO_NONE,      // T0_MAT[1]
            GPIO_NONE,      // T0_MAT[2]
            GPIO_NONE,      // T0_MAT[3]
    };
    DEVICE_CREATE_ONCE();
    LPC17xx_40xx_Timer1_Require(&settings);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_Timer2_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the Timer2 drivers, but don't set any capture sources or
 *      match registers.
 *---------------------------------------------------------------------------*/
void UEZPlatform_Timer2_Require(void)
{
    static const T_LPC17xx_40xx_Timer_Settings settings = {
            GPIO_NONE,      // T0_CAP[0]
            GPIO_NONE,      // T0_CAP[1]
            GPIO_NONE,      // T0_MAT[0]
            GPIO_NONE,      // T0_MAT[1]
            GPIO_NONE,      // T0_MAT[2]
            GPIO_NONE,      // T0_MAT[3]
    };
    DEVICE_CREATE_ONCE();
    LPC17xx_40xx_Timer2_Require(&settings);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_Timer3_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the Timer3 drivers, but don't set any capture sources or
 *      match registers.
 *---------------------------------------------------------------------------*/
void UEZPlatform_Timer3_Require(void)
{
    static const T_LPC17xx_40xx_Timer_Settings settings = {
            GPIO_NONE,      // T0_CAP[0]
            GPIO_NONE,      // T0_CAP[1]
            GPIO_NONE,      // T0_MAT[0]
            GPIO_NONE,      // T0_MAT[1]
            GPIO_NONE,      // T0_MAT[2]
            GPIO_NONE,      // T0_MAT[3]
    };
    DEVICE_CREATE_ONCE();
    LPC17xx_40xx_Timer3_Require(&settings);
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_WiredNetwork0_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the networking for Wired connections.
 *---------------------------------------------------------------------------*/
void UEZPlatform_WiredNetwork0_Require(void)
{
    DEVICE_CREATE_ONCE();

    // Wired network needs an EMAC
    UEZPlatform_EMAC_Require();

    // Create the network driver for talking to lwIP on a wired
    // network.
    Network_lwIP_Create("WiredNetwork0");
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_WirelessNetwork0_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the networking for Wireless connections.
 *---------------------------------------------------------------------------*/
#include <Source/Library/Network/GainSpan/CmdLib/GainSpan_CmdLib.h>
void UEZPlatform_WirelessNetwork0_Require(void)
{
    // These SPI pins work for both the Application Header and the PMOD Header
    // for GainSpan Modules with SPI configured.
    const T_GainSpan_Network_SPISettings spi_settings = {
    // SPI Settings
        "SSP0",// SSP Name
        1000000, // 1 MHz
        // Pins.
        GPIO_P2_23, // GPIO35 -- SPI CS
        GPIO_P2_11, // GPIO80_RTC_IRQ -- WIFI-IRQ
        GPIO_P1_6, // iProgramMode not connected
        GPIO_P1_7, // iSPIMode not connected
        GPIO_P1_5, // iSRSTn not connected (only to RESET_OUT)
        GPIO_P1_11, // Factory restore line
        };

    DEVICE_CREATE_ONCE();

    LPC17xx_40xx_GPIO1_Require();
    LPC17xx_40xx_GPIO2_Require();
    UEZPlatform_SSP0_Require();
    Network_GainSpan_Create("WirelessNetwork0", &spi_settings);
}

void UEZPlatform_WiFiProgramMode(void)
{
    printf("Programming mode ...\n");
    UEZTaskDelay(500);

    RTOS_ENTER_CRITICAL()    ;

    UEZGPIOClear(GPIO_P1_5);        // WIFI_SRSTn
    UEZGPIOSetMux(GPIO_P1_5, 0);
    UEZGPIOOutput(GPIO_P1_5);       // WIFI_SRSTn

    UEZGPIOInput(GPIO_P2_11);       // WIFI IRQ

    UEZGPIOSet(GPIO_P1_6);          // WIFI PROGRAM ON
    UEZGPIOOutput(GPIO_P1_6);       // WIFI PROGRAM ON

    UEZGPIOUnlock(GPIO_P0_2);       // 1788 TX
    UEZGPIOSetMux(GPIO_P0_2, 0);
    UEZGPIOOutput(GPIO_P0_2);

    UEZGPIOUnlock(GPIO_P0_3);       // 1788 RX
    UEZGPIOSetMux(GPIO_P0_3, 0);
    UEZGPIOInput(GPIO_P0_3);

    UEZGPIOUnlock(GPIO_P0_15);      // WIFI TX
    UEZGPIOSetMux(GPIO_P0_15, 0);
    UEZGPIOOutput(GPIO_P0_15);

    UEZGPIOUnlock(GPIO_P0_16);      // WIFI RX
    UEZGPIOSetMux(GPIO_P0_16, 0);
    UEZGPIOInput(GPIO_P0_16);

    UEZTaskDelay(1000);

    UEZGPIOSet(GPIO_P1_5);          // WIFI_SRSTn

    CPUDisableInterrupts();
    while (1) {
        if (LPC_GPIO0->PIN & (1 << 3)) // 1788 RX = GPIO_P0_3
            LPC_GPIO0->SET = (1 << 15); // WIFI TX = GPIO_P0_15
        else
            LPC_GPIO0->CLR = (1 << 15);

        if (LPC_GPIO0->PIN & (1 << 16)) // WIFI RX = GPIO_P0_16
            LPC_GPIO0->SET = (1 << 2);  // 1788 TX = GPIO_P0_2
        else
            LPC_GPIO0->CLR = (1 << 2);  // 1788 TX = GPIO_P0_2
    }
}
/*---------------------------------------------------------------------------*
 * Routine:  UEZPlatform_I2S_Require
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the I2S drivers for talking to the expansion board.
 *---------------------------------------------------------------------------*/
void UEZPlatform_I2S_Require(void)
{
    static const T_LPC17xx_40xx_I2S_Settings settings = {
            GPIO_P0_6,  // I2S_RX_SDA   = P0.6_I2SRX_SDA_SSEL1_MAT2.0
            GPIO_P0_4,  // I2S_RX_SCK   = P0.4_I2SRX_CLK_RD2_CAP2.0
            GPIO_P0_5,  // I2S_RX_WS    = P0.5_I2SRX_WS_TD2_CAP2.1
            GPIO_NONE,  // I2S_RX_MCLK  = not used
            GPIO_P0_9,  // I2S_TX_SDA   = P0.9_I2STX_SDA_MOSI1_MAT2.3
            GPIO_P0_7,  // I2S_TX_SCK   = P0.7_I2STX_CLK_SCK1_MAT2.1
            GPIO_P0_8,  // I2S_TX_WS    = P0.8_I2STX_WS_MISO1_MAT2.2
            GPIO_NONE,  // I2S_TX_MCLK  = not used
    };
    DEVICE_CREATE_ONCE();
    LPC17xx_40xx_I2S_Require(&settings);
    Generic_I2S_Create("I2S", "I2S");
}

/*---------------------------------------------------------------------------*
 * Routine:  uEZPlatformInit
 *---------------------------------------------------------------------------*
 * Description:
 *      Initialize the board with all the proper settings.
 *      Registers all peripherals specific to this board.
 *---------------------------------------------------------------------------*/
void uEZPlatformInit(void)
{
    // Do any initialiation necessary before the RTOS is started
}

void UEZPlatform_Standard_Require(void)
{
    // Setup console immediately
    UEZPlatform_Console_Expansion_Require(UEZ_CONSOLE_WRITE_BUFFER_SIZE,
            UEZ_CONSOLE_READ_BUFFER_SIZE);
	UEZPlatform_FullDuplex_UART1_Require(UEZ_CONSOLE_WRITE_BUFFER_SIZE,
            UEZ_CONSOLE_READ_BUFFER_SIZE);
    UEZPlatform_LCD_Require();

    UEZPlatform_I2C0_Require();
    UEZPlatform_I2C1_Require();
    UEZPlatform_Temp0_Require();
    UEZPlatform_GPDMA0_Require();
    UEZPlatform_GPDMA1_Require();
    UEZPlatform_SSP0_Require();
    UEZPlatform_ADC0_0_Require();
    UEZPlatform_ADC0_1_Require();
    UEZPlatform_ADC0_2_Require();
    UEZPlatform_DAC0_Require();
    UEZPlatform_Flash0_Require();
    UEZPlatform_EEPROM0_Require();

    UEZPlatform_AudioAmp_Require();
    UEZPlatform_Accel0_Require();
    UEZPlatform_RTC_Require();
    UEZPlatform_Touchscreen_Require();
    UEZPlatform_AudioMixer_Require();
    UEZAudioMixerMute(UEZ_AUDIO_MIXER_OUTPUT_MASTER);
    UEZPlatform_Speaker_Require();
    //UEZAudioMixerUnmute(UEZ_AUDIO_MIXER_OUTPUT_MASTER);
}

void UEZPlatform_Full_Require(void)
{
    // Setup console immediately
    UEZPlatform_Console_Expansion_Require(UEZ_CONSOLE_WRITE_BUFFER_SIZE,
            UEZ_CONSOLE_READ_BUFFER_SIZE);
	UEZPlatform_FullDuplex_UART1_Require(UEZ_CONSOLE_WRITE_BUFFER_SIZE,
            UEZ_CONSOLE_READ_BUFFER_SIZE);
    UEZPlatform_LCD_Require();

    LPC17xx_40xx_GPIO0_Require();
    LPC17xx_40xx_GPIO1_Require();
    LPC17xx_40xx_GPIO2_Require();
    LPC17xx_40xx_GPIO3_Require();
    LPC17xx_40xx_GPIO4_Require();
    LPC17xx_40xx_GPIO5_Require();

    UEZPlatform_CRC0_Require();
    UEZPlatform_I2C0_Require();
    UEZPlatform_I2C1_Require();
    UEZPlatform_I2C2_Require();
    UEZPlatform_Temp0_Require();
    UEZPlatform_GPDMA0_Require();
    UEZPlatform_GPDMA1_Require();
    UEZPlatform_GPDMA2_Require();
    UEZPlatform_GPDMA3_Require();
    UEZPlatform_GPDMA4_Require();
    UEZPlatform_GPDMA5_Require();
    UEZPlatform_GPDMA6_Require();
    UEZPlatform_GPDMA7_Require();
    UEZPlatform_Timer0_Require();
    UEZPlatform_Timer1_Require();
    UEZPlatform_Timer2_Require();
    UEZPlatform_Timer3_Require();
    UEZPlatform_SSP0_Require();
    UEZPlatform_ADC0_0_Require();
    UEZPlatform_ADC0_1_Require();
    UEZPlatform_ADC0_2_Require();
    UEZPlatform_DAC0_Require();
    UEZPlatform_Flash0_Require();
    UEZPlatform_Speaker_Require();
    UEZPlatform_EEPROM0_Require();
    UEZPlatform_Watchdog_Require();
    UEZPlatform_SDCard_Drive_Require(1);
    UEZPlatform_USBDevice_Require();
    UEZPlatform_WiredNetwork0_Require();

    UEZPlatform_AudioAmp_Require();
    UEZPlatform_Accel0_Require();
    UEZPlatform_RTC_Require();
    UEZPlatform_Touchscreen_Require();
}

void UEZPlatform_Minimal_Require(void)
{
    // Setup console immediately
    UEZPlatform_Console_Expansion_Require(UEZ_CONSOLE_WRITE_BUFFER_SIZE,
            UEZ_CONSOLE_READ_BUFFER_SIZE);
    UEZPlatform_LCD_Require();
}

/*---------------------------------------------------------------------------*
 * Routine:  UEZGUIIsLoopbackBoardConnected
 *---------------------------------------------------------------------------*
 * Description:
 *      Determines if a loopback board for testing is connected
 * Outputs:
 *      TBool -- ETrue if connected, else EFalse
 *---------------------------------------------------------------------------*/
TBool UEZGUIIsLoopbackBoardConnected(void)
{
    TUInt32 readSet;
    TUInt32 readClear;

    LPC17xx_40xx_GPIO0_Require();

    // Check to see that P0.26 goes high when P0.6 is high
    UEZGPIOSetMux(GPIO_P0_6, 0); // GPIO mode
    UEZGPIOOutput(GPIO_P0_6);
    UEZGPIOSetMux(GPIO_P0_26, 0); // GPIO mode
    UEZGPIOInput(GPIO_P0_26);
    UEZGPIOSet(GPIO_P0_6);
    readSet = UEZGPIORead(GPIO_P0_26);
    UEZGPIOClear(GPIO_P0_6);
    readClear = UEZGPIORead(GPIO_P0_26);
    UEZGPIOInput(GPIO_P0_6);
    UEZGPIOInput(GPIO_P0_26);

    // If the pin wiggled, then the loop back is  in place
    if (readSet && !readClear)
        return ETrue;

    // Otherwise it is not set.
    return EFalse;
}

TUInt16 UEZPlatform_LCDGetHeight(void)
{
    return UEZ_LCD_DISPLAY_HEIGHT;
}
TUInt16 UEZPlatform_LCDGetWidth(void)
{
    return UEZ_LCD_DISPLAY_WIDTH;
}
#include <Source/Library/GUI/FDI/SimpleUI/SimpleUI_Types.h>
TUInt32 UEZPlatform_LCDGetFrame(TUInt16 aFrameNum)
{
    return (TUInt32)FRAME(aFrameNum);
}
TUInt32 UEZPlatform_LCDGetFrameBuffer(void)
{
    return (TUInt32)LCD_FRAME_BUFFER;
}
TUInt32 UEZPlatform_LCDGetFrameSize(void)
{
    return FRAME_SIZE;
}
TUInt32 UEZPlatform_SerialGetDefaultBaud(void)
{
    return SERIAL_PORTS_DEFAULT_BAUD;
}
TUInt32 UEZPlatform_ProcessorGetFrequency(void)
{
    return PROCESSOR_OSCILLATOR_FREQUENCY;
}
TUInt32 UEZPlatform_GetPCLKFrequency(void)
{
#if (PROCESSOR_OSCILLATOR_FREQUENCY == 72000000)
    return 72000000;
#else
    return 60000000;
#endif
}

T_pixelColor SUICallbackRGBConvert(int r, int g, int b)
{
    return RGB(r, g, b);
}
TUInt32 UEZPlatform_GetBaseAddress(void)
{
    return LCD_DISPLAY_BASE_ADDRESS;
}
#if INCLUDE_EMWIN
#include <Source/Library/GUI/SEGGER/emWin/LCD.h>
const void* UEZPlatform_GUIColorConversion(void)
{
    return GUICC_M555;
}
#endif

void SUICallbackSetLCDBase(void *aAddress)
{
    LPC_LCD->UPBASE = (TUInt32)aAddress;
}

void *SUICallbackGetLCDBase(void)
{
    return (void *)(LPC_LCD->UPBASE);
}

void WriteByteInFrameBufferWithAlpha(UNS_32 aAddr, COLOR_T aPixel, T_swimAlpha aAlpha)
{
    static COLOR_T mask = ~((1<<10)|(1<<5)|(1<<0));
    COLOR_T *p = (COLOR_T *)aAddr;

    switch (aAlpha) {
        case SWIM_ALPHA_50:
            *p = (((*p & mask)>>1) + ((aPixel & mask)>>1));
            break;
    }
}

#if (COMPILER_TYPE==Keil4)
__asm void vMainMPUFaultHandler( unsigned long * pulFaultRegisters )
{
    /* Determine which stack was in use when the MPU fault occurred and extract
    the stacked PC. */
    tst lr, #4
    ite eq
    mrseq r0, msp /* The code that generated the exception was using the main stack. */
    mrsne r0, psp /* The code that generated the exception was using the process stack. */
    ldr r0, [r0, #24]   /* Extract the value of the stacked PC. */
    str r0, [sp]    /* Store the value of the stacked PC into ulStacked_pc. */

    /* Inspect ulStacked_pc to locate the offending instruction. */
loopforever
    bl loopforever
}
#else
void vMainMPUFaultHandler( unsigned long * pulFaultRegisters )
{
unsigned long ulStacked_pc = 0UL;

    ( void ) ulStacked_pc;

    /* Determine which stack was in use when the MPU fault occurred and extract
    the stacked PC. */
    __asm
    (
        "   tst lr, #4          \n"
        "   ite eq              \n"
        "   mrseq r0, msp       \n" /* The code that generated the exception was using the main stack. */
        "   mrsne r0, psp       \n" /* The code that generated the exception was using the process stack. */
        "   ldr r0, [r0, #24]   \n" /* Extract the value of the stacked PC. */
        "   str r0, [sp]        \n" /* Store the value of the stacked PC into ulStacked_pc. */
    );

    /* Inspect ulStacked_pc to locate the offending instruction. */
    for( ;; );
}
#endif
/*---------------------------------------------------------------------------*
 * Routine:  main
 *---------------------------------------------------------------------------*
 * Description:
 *      The main() routine in UEZ is only a stub that is used to start
 *      the whole UEZ system.  UEZBSP_Startup() is immediately called.
 * Outputs:
 *      int -- not used, 0
 *---------------------------------------------------------------------------*/
int main(void)
{
    UEZBSP_Startup();
    while (1) {
    } // never should get here
}
/*-------------------------------------------------------------------------*
 * End of File:  uEZPlatform.c
 *-------------------------------------------------------------------------*/

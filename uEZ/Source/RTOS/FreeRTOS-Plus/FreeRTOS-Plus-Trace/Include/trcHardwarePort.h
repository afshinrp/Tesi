/******************************************************************************* 
 * Tracealyzer v2.5.0 Recorder Library
 * Percepio AB, www.percepio.com
 *
 * trcHardwarePort.h
 *
 * Contains together with trcHardwarePort.c all hardware portability issues of 
 * the trace recorder library.
 *
 * Terms of Use
 * This software is copyright Percepio AB. The recorder library is free for
 * use together with Percepio products. You may distribute the recorder library
 * in its original form, including modifications in trcPort.c and trcPort.h
 * given that these modification are clearly marked as your own modifications
 * and documented in the initial comment section of these source files. 
 * This software is the intellectual property of Percepio AB and may not be 
 * sold or in other ways commercially redistributed without explicit written 
 * permission by Percepio AB.
 *
 * Disclaimer 
 * The trace tool and recorder library is being delivered to you AS IS and 
 * Percepio AB makes no warranty as to its use or performance. Percepio AB does 
 * not and cannot warrant the performance or results you may obtain by using the 
 * software or documentation. Percepio AB make no warranties, express or 
 * implied, as to noninfringement of third party rights, merchantability, or 
 * fitness for any particular purpose. In no event will Percepio AB, its 
 * technology partners, or distributors be liable to you for any consequential, 
 * incidental or special damages, including any lost profits or lost savings, 
 * even if a representative of Percepio AB has been advised of the possibility 
 * of such damages, or for any claim by any third party. Some jurisdictions do 
 * not allow the exclusion or limitation of incidental, consequential or special 
 * damages, or the exclusion of implied warranties or limitations on how long an 
 * implied warranty may last, so the above limitations may not apply to you.
 *
 * Copyright Percepio AB, 2013.
 * www.percepio.com
 ******************************************************************************/

#ifndef TRCPORT_H
#define TRCPORT_H

#include "trcKernelPort.h"

/* If Win32 port */
#ifdef WIN32

   #undef _WIN32_WINNT
   #define _WIN32_WINNT 0x0600

   /* Standard includes. */
   #include <stdio.h>
   #include <windows.h>
   #include <direct.h>

/*******************************************************************************
 * The Win32 port by default saves the trace to file and then kills the
 * program when the recorder is stopped, to facilitate quick, simple tests
 * of the recorder.
 ******************************************************************************/
   #define WIN32_PORT_SAVE_WHEN_STOPPED 1
   #define WIN32_PORT_EXIT_WHEN_STOPPED 1

#endif

#define DIRECTION_INCREMENTING 1
#define DIRECTION_DECREMENTING 2

/******************************************************************************
 * Supported ports
 * 
 * PORT_HWIndependent
 * A hardware independent fallback option for event timestamping. Provides low 
 * resolution timestamps based on the OS tick.
 * This may be used on the Win32 port, but may also be used on embedded hardware 
 * platforms. All time durations will be truncated to the OS tick frequency, 
 * typically 1 KHz. This means that a task or ISR that executes in less than 
 * 1 ms get an execution time of zero.
 *
 * PORT_Win32
 * "Accurate" timestamping based on the Windows performance counter for Win32 builds.
 * Note that this gives the host machine time, not the kernel time.
 *
 * Officially supported hardware timer ports:
 * - PORT_Atmel_AT91SAM7
 * - PORT_Atmel_UC3A0
 * - PORT_ARM_CortexM 
 * - PORT_Renesas_RX600
 * - PORT_Microchip_dsPIC_AND_PIC24
 *
 * We also provide several "unofficial" hardware-specific ports. There have 
 * been developed by external contributors, and have not yet been verified 
 * by Percepio AB. Let us know if you have problems getting these to work.
 * 
 * Unofficial hardware specific ports provided are:
 * - PORT_TEXAS_INSTRUMENTS_TMS570
 * - PORT_TEXAS_INSTRUMENTS_MSP430
 * - PORT_MICROCHIP_PIC32
 * - PORT_XILINX_PPC405
 * - PORT_XILINX_PPC440
 * - PORT_XILINX_MICROBLAZE
 * - PORT_NXP_LPC210X
 *
 *****************************************************************************/

#define PORT_NOT_SET                          -1
#define PORT_APPLICATION_DEFINED			  -2

/*** Officially supported hardware timer ports *******************************/
#define PORT_HWIndependent                     0
#define PORT_Win32                             1
#define PORT_Atmel_AT91SAM7                    2
#define PORT_Atmel_UC3A0                       3
#define PORT_ARM_CortexM                       4
#define PORT_Renesas_RX600                     5
#define PORT_Microchip_dsPIC_AND_PIC24         6

/*** Unofficial ports, provided by external developers, not yet verified *****/
#define PORT_TEXAS_INSTRUMENTS_TMS570          7
#define PORT_TEXAS_INSTRUMENTS_MSP430          8
#define PORT_MICROCHIP_PIC32                   9
#define PORT_XILINX_PPC405                    10
#define PORT_XILINX_PPC440                    11
#define PORT_XILINX_MICROBLAZE                12
#define PORT_NXP_LPC210X                      13

#if (SELECTED_PORT == PORT_NOT_SET) 
#error "You need to define SELECTED_PORT here!"
#endif

/*******************************************************************************
 * IRQ_PRIORITY_ORDER
 *
 * Macro which should be defined as an integer of 0 or 1.
 *
 * This should be 0 if lower IRQ priority values implies higher priority 
 * levels, such as on ARM Cortex M. If the opposite scheme is used, i.e., 
 * if higher IRQ priority values means higher priority, this should be 1.
 *
 * This setting is not critical. It is used only to sort and colorize the 
 * interrupts in priority order, in case you record interrupts using
 * the vTraceStoreISRBegin and vTraceStoreISREnd routines.
 *
 * We provide this setting for some hardware architectures below:
 * - ARM Cortex M:       0 (lower IRQ priority values are more significant)
 * - Atmel AT91SAM7x:    1 (higher IRQ priority values are more significant)
 * - Atmel AVR32:        1 (higher IRQ priority values are more significant)
 * - Renesas RX600:      1 (higher IRQ priority values are more significant)
 * - Microchip PIC24:    0 (lower IRQ priority values are more significant)
 * - Microchip dsPIC:    0 (lower IRQ priority values are more significant)
 * - TI TMS570:          0 (lower IRQ priority values are more significant)
 * - Freescale HCS08:    0 (lower IRQ priority values are more significant)
 * - Freescale HCS12:    0 (lower IRQ priority values are more significant)
 * - PowerPC 405:        0 (lower IRQ priority values are more significant)
 * - PowerPC 440:        0 (lower IRQ priority values are more significant)
 * - Freescale ColdFire: 1 (higher IRQ priority values are more significant)
 * - NXP LPC210x:        0 (lower IRQ priority values are more significant)
 * - MicroBlaze:        0  (lower IRQ priority values are more significant)
 *
 * If your chip is not on the above list, and you perhaps know this detail by 
 * heart, please inform us by e-mail to support@percepio.com.
 *
 ******************************************************************************
 *
 * HWTC Macros 
 *
 * These four HWTC macros provides a hardware isolation layer representing a 
 * generic hardware timer/counter used for driving the operating system tick, 
 * such as the SysTick feature of ARM Cortex M3/M4, or the PIT of the Atmel 
 * AT91SAM7X.
 *
 * HWTC_COUNT: The current value of the counter. This is expected to be reset 
 * a each tick interrupt. Thus, when the tick handler starts, the counter has 
 * already wrapped.
 *
 * HWTC_COUNT_DIRECTION: Should be one of:
 * - DIRECTION_INCREMENTING - for hardware timer/counters of incrementing type
 *   such as the PIT on Atmel AT91SAM7X.
 *   When the counter value reach HWTC_PERIOD, it is reset to zero and the
 *   interrupt is signaled.
 * - DIRECTION_DECREMENTING - for hardware timer/counters of decrementing type
 *   such as the SysTick on ARM Cortex M3/M4 chips.
 *   When the counter value reach 0, it is reset to HWTC_PERIOD and the
 *   interrupt is signaled.
 *
 * HWTC_PERIOD: The number of increments or decrements of HWTC_COUNT between
 * two tick interrupts. This should preferably be mapped to the reload
 * register of the hardware timer, to make it more portable between chips in the 
 * same family. The macro should in most cases be (reload register + 1).
 *
 * HWTC_DIVISOR: If the timer frequency is very high, like on the Cortex M chips
 * (where the SysTick runs at the core clock frequency), the "differential 
 * timestamping" used in the recorder will more frequently insert extra XTS 
 * events to store the timestamps, which increases the event buffer usage. 
 * In such cases, to reduce the number of XTS events and thereby get longer 
 * traces, you use HWTC_DIVISOR to scale down the timestamps and frequency.
 * Assuming a OS tick rate of 1 KHz, it is suggested to keep the effective timer
 * frequency below 65 MHz to avoid an excessive amount of XTS events. Thus, a
 * Cortex M chip running at 72 MHZ should use a HWTC_DIVISOR of 2, while a 
 * faster chip require a higher HWTC_DIVISOR value. 
 *
 * The HWTC macros and vTracePortGetTimeStamp is the main porting issue
 * or the trace recorder library. Typically you should not need to change
 * the code of vTracePortGetTimeStamp if using the HWTC macros.
 *
 ******************************************************************************/

#if (SELECTED_PORT == PORT_Win32)
    
    #define HWTC_COUNT_DIRECTION DIRECTION_INCREMENTING
    #define HWTC_COUNT (ulGetRunTimeCounterValue())
    #define HWTC_PERIOD 0
    #define HWTC_DIVISOR 1
    
    #define IRQ_PRIORITY_ORDER 1  // Please update according to your hardware...

#elif (SELECTED_PORT == PORT_HWIndependent)
    
    #define HWTC_COUNT_DIRECTION DIRECTION_INCREMENTING
    #define HWTC_COUNT 0
    #define HWTC_PERIOD 1
    #define HWTC_DIVISOR 1

    #define IRQ_PRIORITY_ORDER 1  // Please update according to your hardware...

#elif (SELECTED_PORT == PORT_Atmel_AT91SAM7)
#error HWTC_PERIOD must point to the reload register! Not verified for this hardware port!

    /* HWTC_PERIOD is hardcoded for AT91SAM7X256-EK Board (48 MHz)
    A more generic solution is to get the period from pxPIT->PITC_PIMR */
    
    #define HWTC_COUNT_DIRECTION DIRECTION_INCREMENTING
    #define HWTC_COUNT (AT91C_BASE_PITC->PITC_PIIR & 0xFFFFF)
    #define HWTC_PERIOD (AT91C_BASE_PITC->PITC_PIMR + 1)
    #define HWTC_DIVISOR 1

    #define IRQ_PRIORITY_ORDER 1  // higher IRQ priority values are more significant

#elif (SELECTED_PORT == PORT_Atmel_UC3A0)
#error HWTC_PERIOD must point to the reload register! Not yet updated for this hardware port!
  
    /* For Atmel AVR32 (AT32UC3A) */
    #define HWTC_COUNT_DIRECTION DIRECTION_INCREMENTING
    #define HWTC_COUNT sysreg_read(AVR32_COUNT)
    #define HWTC_PERIOD
    #define HWTC_DIVISOR 1    

    #define IRQ_PRIORITY_ORDER 1  // higher IRQ priority values are more significant

#elif (SELECTED_PORT == PORT_ARM_CortexM)

    /* For all chips using ARM Cortex M cores */

    #define HWTC_COUNT_DIRECTION DIRECTION_DECREMENTING
    #define HWTC_COUNT (*((uint32_t*)0xE000E018))
    #define HWTC_PERIOD ((*(uint32_t*)0xE000E014) + 1)
    #define HWTC_DIVISOR 2
    
    #define IRQ_PRIORITY_ORDER 0  // lower IRQ priority values are more significant

#elif (SELECTED_PORT == PORT_Renesas_RX600)    

    #include "iodefine.h"

    #define HWTC_COUNT_DIRECTION DIRECTION_INCREMENTING
    #define HWTC_COUNT (CMT0.CMCNT)
    #define HWTC_PERIOD (CMT0.CMCOR + 1)
    #define HWTC_DIVISOR 1

    #define IRQ_PRIORITY_ORDER 1  // higher IRQ priority values are more significant

#elif (SELECTED_PORT == PORT_Microchip_dsPIC_AND_PIC24)

    /* For Microchip PIC24 and dsPIC (16 bit) */

    /* Note: The trace library was originally designed for 32-bit MCUs, and is slower
       than intended on 16-bit MCUs. Storing an event on a PIC24 takes about 70 �s. 
       In comparison, 32-bit MCUs are often 10-20 times faster. If recording overhead 
       becomes a problem on PIC24, use the filters to exclude less interesting tasks 
       or system calls. */

    #define HWTC_COUNT_DIRECTION DIRECTION_INCREMENTING
    #define HWTC_COUNT (TMR1)
    #define HWTC_PERIOD (PR1+1)
    #define HWTC_DIVISOR 1

    #define IRQ_PRIORITY_ORDER 0  // lower IRQ priority values are more significant

#elif (SELECTED_PORT == PORT_NXP_LPC210X)
#error HWTC_PERIOD must point to the reload register! Not yet updated for this hardware port!
    /* UNOFFICIAL PORT - NOT YET VERIFIED BY PERCEPIO */
    
    /* Tested with LPC2106, but should work with most LPC21XX chips. */
      
    #define HWTC_COUNT_DIRECTION DIRECTION_INCREMENTING
    #define HWTC_COUNT  *((uint32_t *)0xE0004008 )
    #define HWTC_PERIOD
    #define HWTC_DIVISOR 1    

    #define IRQ_PRIORITY_ORDER 0  // lower IRQ priority values are more significant

#elif (SELECTED_PORT == PORT_TEXAS_INSTRUMENTS_TMS570)
#error HWTC_PERIOD must point to the reload register! Not verified for this hardware port!
    /* UNOFFICIAL PORT - NOT YET VERIFIED BY PERCEPIO */

    #define RTIFRC0 *((uint32_t *)0xFFFFFC10)
    #define RTICOMP0 *((uint32_t *)0xFFFFFC50)
    #define RTIUDCP0 *((uint32_t *)0xFFFFFC54)
    #define HWTC_COUNT_DIRECTION DIRECTION_INCREMENTING
    #define HWTC_COUNT (RTIFRC0 - (RTICOMP0 - RTIUDCP0))
    #define HWTC_PERIOD (RTIUDCP0)
    #define HWTC_DIVISOR 1

    #define IRQ_PRIORITY_ORDER 0  // lower IRQ priority values are more significant

#elif (SELECTED_PORT == PORT_TEXAS_INSTRUMENTS_MSP430)
#error HWTC_PERIOD must point to the reload register! Not verified for this hardware port!
    /* UNOFFICIAL PORT - NOT YET VERIFIED BY PERCEPIO */

    #define HWTC_COUNT_DIRECTION DIRECTION_INCREMENTING
    #define HWTC_COUNT (TA0R)
    #define HWTC_PERIOD TRACE_CPU_CLOCKS_PER_TICK      
    #define HWTC_DIVISOR 1

    #define IRQ_PRIORITY_ORDER 1  // higher IRQ priority values are more significant

#elif (SELECTED_PORT == PORT_MICROCHIP_PIC32)
    /* UNOFFICIAL PORT - NOT YET VERIFIED BY PERCEPIO */

    #define HWTC_COUNT_DIRECTION DIRECTION_INCREMENTING
    #define HWTC_COUNT (ReadTimer1())     /* Should be available in BSP */
    #define HWTC_PERIOD (ReadPeriod1()+1) /* Should be available in BSP */
    #define HWTC_DIVISOR 1

    #define IRQ_PRIORITY_ORDER 0  // lower IRQ priority values are more significant

#elif (SELECTED_PORT == PORT_XILINX_PPC405)
#error HWTC_PERIOD must point to the reload register! Not verified for this hardware port!
    /* UNOFFICIAL PORT - NOT YET VERIFIED BY PERCEPIO */

    #define HWTC_COUNT_DIRECTION DIRECTION_DECREMENTING
    #define HWTC_COUNT  mfspr( 0x3db)
    #define HWTC_PERIOD
    #define HWTC_DIVISOR 1

    #define IRQ_PRIORITY_ORDER 0  // lower IRQ priority values are more significant

#elif (SELECTED_PORT == PORT_XILINX_PPC440)
#error HWTC_PERIOD must point to the reload register! Not verified for this hardware port!
    /* UNOFFICIAL PORT - NOT YET VERIFIED BY PERCEPIO */

    /* This should work with most PowerPC chips */
    
    #define HWTC_COUNT_DIRECTION DIRECTION_DECREMENTING
    #define HWTC_COUNT  mfspr( 0x016 )
    #define HWTC_PERIOD
    #define HWTC_DIVISOR 1    

    #define IRQ_PRIORITY_ORDER 0  // lower IRQ priority values are more significant
    
#elif (SELECTED_PORT == PORT_XILINX_MICROBLAZE)
#error HWTC_PERIOD must point to the reload register! Not verified for this hardware port!
    /* UNOFFICIAL PORT - NOT YET VERIFIED BY PERCEPIO */

    /* This should work with most Microblaze configurations.
     * It uses the AXI Timer 0 - the tick interrupt source.
     * If an AXI Timer 0 peripheral is available on your hardware platform, no modifications are required.
     */
    #include "xtmrctr_l.h"

    #define HWTC_COUNT_DIRECTION DIRECTION_DECREMENTING
    #define HWTC_COUNT XTmrCtr_GetTimerCounterReg( XPAR_TMRCTR_0_BASEADDR, 0 )
    #define HWTC_PERIOD
    #define HWTC_DIVISOR 16

    #define IRQ_PRIORITY_ORDER 0  // lower IRQ priority values are more significant

#elif (SELECTED_PORT == PORT_APPLICATION_DEFINED)

	#if !( defined (HWTC_COUNT_DIRECTION) && defined (HWTC_COUNT) && defined (HWTC_PERIOD) && defined (HWTC_DIVISOR) && defined (IRQ_PRIORITY_ORDER) )
		#error SELECTED_PORT is PORT_APPLICATION_DEFINED but not all of the necessary constants have been defined.
	#endif


#elif (SELECTED_PORT != PORT_NOT_SET)

    #error "SELECTED_PORT had unsupported value!"
    #define SELECTED_PORT PORT_NOT_SET

#endif

#if (SELECTED_PORT != PORT_NOT_SET)
    
    #ifndef HWTC_COUNT_DIRECTION
    #error "HWTC_COUNT_DIRECTION is not set!"
    #endif 
    
    #ifndef HWTC_COUNT
    #error "HWTC_COUNT is not set!"    
    #endif 
    
    #ifndef HWTC_PERIOD
    #error "HWTC_PERIOD is not set!"
    #endif 
    
    #ifndef HWTC_DIVISOR
    #error "HWTC_DIVISOR is not set!"    
    #endif 
    
    #ifndef IRQ_PRIORITY_ORDER
    #error "IRQ_PRIORITY_ORDER is not set!"
    #elif (IRQ_PRIORITY_ORDER != 0) && (IRQ_PRIORITY_ORDER != 1)
    #error "IRQ_PRIORITY_ORDER has bad value!"
    #endif 
    
    #if (HWTC_DIVISOR < 1)
    #error "HWTC_DIVISOR must be a non-zero positive value!"
    #endif 

#endif
/*******************************************************************************
 * vTraceConsoleMessage
 *
 * A wrapper for your system-specific console "printf" console output function.
 * This needs to be correctly defined to see status reports from the trace 
 * status monitor task (this is defined in trcUser.c).
 ******************************************************************************/         
#if (SELECTED_PORT == PORT_Atmel_AT91SAM7)
/* Port specific includes */
#include "console.h"
#endif

#define vTraceConsoleMessage(x) printf(x)

/*******************************************************************************
 * vTracePortGetTimeStamp
 *
 * Returns the current time based on the HWTC macros which provide a hardware
 * isolation layer towards the hardware timer/counter.
 *
 * The HWTC macros and vTracePortGetTimeStamp is the main porting issue
 * or the trace recorder library. Typically you should not need to change
 * the code of vTracePortGetTimeStamp if using the HWTC macros.
 *
 ******************************************************************************/
void vTracePortGetTimeStamp(uint32_t *puiTimestamp);

/*******************************************************************************
 * vTracePortEnd
 * 
 * This function is called when the recorder is stopped due to full buffer.
 * Mainly intended to show a message in the console.
 * This is used by the Win32 port to store the trace to a file. The file path is
 * set using vTracePortSetFileName.
 ******************************************************************************/
void vTracePortEnd(void);

#endif

/*-------------------------------------------------------------------------*
 * File:  Timer.c
 *-------------------------------------------------------------------------*
 * Description:
 *      HAL implementation of the LPC17xx_40xx Timers Interface.
 * Implementation:
 *      Two Timers are created, Timer0 and Timer1.
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
#include <uEZTypes.h>
#include <uEZErrors.h>
#include <uEZProcessor.h>
#include <HAL/GPIO.h>
#include <HAL/Timer.h>
#include <uEZBSP.h>
#include <Source/Processor/NXP/LPC17xx_40xx/LPC17xx_40xx_Timer.h>
#include <HAL/Interrupt.h>
#include <uEZPlatformAPI.h>

/*---------------------------------------------------------------------------*
 * Types:
 *---------------------------------------------------------------------------*/
typedef struct {
    TVUInt32 iIR; // 0x00
    TVUInt32 iTCR; // 0x04
    TVUInt32 iTC; // 0x08
    TVUInt32 iPR; // 0x0C
    TVUInt32 iPC; // 0x10
    TVUInt32 iMCR; // 0x14
    TVUInt32 iMR[4]; // 0x18, 0x1C, 0x20, 0x24
    TVUInt32 iCCR; // 0x28
    TVUInt32 iCR[4]; // 0x2C, 0x30, 0x34, 0x38
    TVUInt32 iEMR; // 0x3C
    TVUInt32 ireserved1[4]; // 0x40, 0x44, 0x48, 0x4C
    TVUInt32 ireserved2[4]; // 0x50, 0x54, 0x58, 0x5C
    TVUInt32 ireserved3[4]; // 0x60, 0x64, 0x68, 0x6C
    TVUInt32 iCTCR; // 0x70
} T_LPC17xx_40xx_Timer_Registers;

typedef struct {
    TUInt16 iVector;
    TISRFPtr iISR;
    const char *iName;
    TUInt8 iPCONBitIndex;
} T_LPC17xx_40xx_Timer_Info;

typedef struct {
    T_HALTimer_Callback iCallbackFunc;
    void *iCallbackWorkspace;
} T_LPC17xx_40xx_Timer_InterruptCallback;

typedef struct {
    const HAL_Timer *iHAL;
    T_LPC17xx_40xx_Timer_Registers *iReg;
    T_LPC17xx_40xx_Timer_InterruptCallback iCallbacks[4]; // one per match register
    const T_LPC17xx_40xx_Timer_Info *iInfo;
} T_LPC17xx_40xx_Timer_Workspace;

/*---------------------------------------------------------------------------*
 * Prototypes:
 *---------------------------------------------------------------------------*/
static const T_LPC17xx_40xx_Timer_Info G_Timer0_Info;
static const T_LPC17xx_40xx_Timer_Info G_Timer1_Info;
static const T_LPC17xx_40xx_Timer_Info G_Timer2_Info;
static const T_LPC17xx_40xx_Timer_Info G_Timer3_Info;
T_LPC17xx_40xx_Timer_Workspace *G_Timer0_Workspace;
T_LPC17xx_40xx_Timer_Workspace *G_Timer1_Workspace;
T_LPC17xx_40xx_Timer_Workspace *G_Timer2_Workspace;
T_LPC17xx_40xx_Timer_Workspace *G_Timer3_Workspace;
static void ITimerProcessIRQ(T_LPC17xx_40xx_Timer_Workspace *p);

/*---------------------------------------------------------------------------*
 * Routine:  TimerX_ISR
 *---------------------------------------------------------------------------*
 * Description:
 *      Interrupt service routines
 *---------------------------------------------------------------------------*/
IRQ_ROUTINE(Timer0_ISR)
{
    IRQ_START();
    ITimerProcessIRQ(G_Timer0_Workspace);
    IRQ_END()
    ;
}

IRQ_ROUTINE(Timer1_ISR)
{
    IRQ_START();
    ITimerProcessIRQ(G_Timer1_Workspace);
    IRQ_END()
    ;
}

IRQ_ROUTINE(Timer2_ISR)
{
    IRQ_START();
    ITimerProcessIRQ(G_Timer2_Workspace);
    IRQ_END()
    ;
}

IRQ_ROUTINE(Timer3_ISR)
{
    IRQ_START();
    ITimerProcessIRQ(G_Timer3_Workspace);
    IRQ_END()
    ;
}

/*---------------------------------------------------------------------------*
 * Routine:  LPC17xx_40xx_Timer_SetTimerMode
 *---------------------------------------------------------------------------*
 * Description:
 *      Timer is going to start -- chip select enabled for device
 * Inputs:
 *      void *aWorkspace        -- Workspace for Timer
 *      T_Timer_Mode aMode      -- Timer mode of operation
 * Outputs:
 *      T_uezError              -- UEZ_ERROR_NONE if success, else code.
 *---------------------------------------------------------------------------*/
static T_uezError LPC17xx_40xx_Timer_SetTimerMode(
        void *aWorkspace,
        T_Timer_Mode aMode)
{
    T_LPC17xx_40xx_Timer_Workspace *p = (T_LPC17xx_40xx_Timer_Workspace *)aWorkspace;
    T_LPC17xx_40xx_Timer_Registers *r = p->iReg;

    // Setup the mode
    r->iCTCR = (r->iCTCR & ~3) | aMode;

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LPC17xx_40xx_Timer_SetCaptureSource
 *---------------------------------------------------------------------------*
 * Description:
 *      Timer is going to start -- chip select enabled for device
 * Inputs:
 *      void *aWorkspace        -- Workspace for Timer
 *      TUInt32 aSourceIndex    -- Timer capture source (depends on hardware
 *                                   underneath).
 * Outputs:
 *      T_uezError              -- Error code.  UEZ_ERROR_NONE if success.
 *                                  UEZ_ERROR_NOT_FOUND if source index
 *                                  does not exist.
 *---------------------------------------------------------------------------*/
static T_uezError LPC17xx_40xx_Timer_SetCaptureSource(
        void *aWorkspace,
        TUInt32 aSourceIndex)
{
    T_LPC17xx_40xx_Timer_Workspace *p = (T_LPC17xx_40xx_Timer_Workspace *)aWorkspace;
    T_LPC17xx_40xx_Timer_Registers *r = p->iReg;

    if (aSourceIndex > 1)
        return UEZ_ERROR_NOT_FOUND;

    // Setup the source of the capture
    r->iCTCR = (r->iCTCR & ~(3 << 2)) | (aSourceIndex << 2);

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LPC17xx_40xx_Timer_SetMatchRegister
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup one of several timer's match registers and what do on
 *      a match.
 * Outputs:
 *      void *aWorkspace        -- Timer's workspace
 *      TUInt8 aMatchRegister   -- Index to match register (0-3)
 *      TUInt32 aMatchPoint     -- Number of CPU cycles until match
 *      TBool aDoInterrupt      -- ETrue if want an interrupt, else EFalse
 *                                  (NOTE: Interrupts currently not
 *                                  implemented)
 *      TBool aDoCounterReset   -- ETrue if counter for this Timer is
 *                                  to be reset on match.
 *      TBool aDoStop           -- ETrue if counter is to be stopped
 *                                  when match occurs.
 *---------------------------------------------------------------------------*/
static T_uezError LPC17xx_40xx_Timer_SetMatchRegister(
        void *aWorkspace,
        TUInt8 aMatchRegister,
        TUInt32 aMatchPoint,
        TBool aDoInterrupt,
        TBool aDoCounterReset,
        TBool aDoStop)
{
    T_LPC17xx_40xx_Timer_Workspace *p = (T_LPC17xx_40xx_Timer_Workspace *)aWorkspace;
    T_LPC17xx_40xx_Timer_Registers *r = p->iReg;
    const T_LPC17xx_40xx_Timer_Info *p_info = p->iInfo;
    TUInt32 aFlags = 0;

    //Make sure Power to the Timer is turned on
    LPC17xx_40xxPowerOn(1 << p_info->iPCONBitIndex);

    // Determine if legal match register
    if (aMatchRegister >= 4)
        return UEZ_ERROR_ILLEGAL_PARAMETER;

    // Determine what the combined flags are
    if (aDoInterrupt)
        aFlags |= (1 << 0);
    if (aDoCounterReset)
        aFlags |= (1 << 1);
    if (aDoStop)
        aFlags |= (1 << 2);

    // Set the actions on the match
    r->iMCR &= ~(7 << (aMatchRegister * 3));
    r->iMCR |= (aFlags << (aMatchRegister * 3));

    // Change the match register
    r->iMR[aMatchRegister] = aMatchPoint / (PROCESSOR_OSCILLATOR_FREQUENCY
        / PCLK_FREQUENCY);

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LPC17xx_40xx_Timer_SetExternalControl
 *---------------------------------------------------------------------------*
 * Description:
 *      Timer is going to have a single edge output (high until matches, then
 *      low, reset counter goes back to high).
 * Inputs:
 *      void *aWorkspace        -- Timer's workspace
 *      TUInt8 aMatchRegister   -- Point in Fpclk cycles where Timer switches
 * Outputs:
 *      T_uezError              -- UEZ_ERROR_NONE
 *---------------------------------------------------------------------------*/
static T_uezError LPC17xx_40xx_Timer_SetExternalControl(
        void *aWorkspace,
        TUInt8 aMatchRegister,
        T_Timer_ExternalControl aExtControl)
{
    T_LPC17xx_40xx_Timer_Workspace *p = (T_LPC17xx_40xx_Timer_Workspace *)aWorkspace;
    T_LPC17xx_40xx_Timer_Registers *r = p->iReg;

    // Determine if legal match register
    if (aMatchRegister >= 4)
        return UEZ_ERROR_ILLEGAL_PARAMETER;

    // Change the external control
    r->iEMR &= ~(3 << (4 + aMatchRegister * 2));
    r->iEMR |= (aExtControl << (4 + aMatchRegister * 2));

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LPC17xx_40xx_Timer_Reset
 *---------------------------------------------------------------------------*
 * Description:
 *      Reset the timer's counter.
 * Inputs:
 *      void *aWorkspace        -- Timer's workspace
 *---------------------------------------------------------------------------*/
static void LPC17xx_40xx_Timer_Reset(void *aWorkspace)
{
    T_LPC17xx_40xx_Timer_Workspace *p = (T_LPC17xx_40xx_Timer_Workspace *)aWorkspace;
    T_LPC17xx_40xx_Timer_Registers *r = p->iReg;
    int i;

    // Reset the counter
    r->iTCR |= (1 << 1);

    // Small delay to let the timer reset
    for (i = 0; i < 5; i++) {
    }

    // Release the counter
    r->iTCR &= ~(1 << 1);
}

/*---------------------------------------------------------------------------*
 * Routine:  LPC17xx_40xx_Timer_Enable
 *---------------------------------------------------------------------------*
 * Description:
 *      Enable (run) the timer's counter.
 * Inputs:
 *      void *aWorkspace        -- Timer's workspace
 *---------------------------------------------------------------------------*/
static void LPC17xx_40xx_Timer_Enable(void *aWorkspace)
{
    T_LPC17xx_40xx_Timer_Workspace *p = (T_LPC17xx_40xx_Timer_Workspace *)aWorkspace;
    T_LPC17xx_40xx_Timer_Registers *r = p->iReg;

    // Enable the counter
    r->iTCR |= (1 << 0);
}

/*---------------------------------------------------------------------------*
 * Routine:  LPC17xx_40xx_Timer_Disable
 *---------------------------------------------------------------------------*
 * Description:
 *      Disable the timer's counter.
 * Inputs:
 *      void *aWorkspace        -- Timer's workspace
 *---------------------------------------------------------------------------*/
static void LPC17xx_40xx_Timer_Disable(void *aWorkspace)
{
    T_LPC17xx_40xx_Timer_Workspace *p = (T_LPC17xx_40xx_Timer_Workspace *)aWorkspace;
    T_LPC17xx_40xx_Timer_Registers *r = p->iReg;

    // Disable the counter
    r->iTCR &= ~(1 << 0);
}

/*---------------------------------------------------------------------------*
 * Routine:  ITimerProcessIRQ
 *---------------------------------------------------------------------------*
 * Description:
 *      Routine called when IRQ occurs.  Determines which callbacks to
 *      call (if any) and clears the interrupts.
 * Inputs:
 *      T_LPC247x_Timer_Workspace *p -- Timer workspace
 *---------------------------------------------------------------------------*/
static void ITimerProcessIRQ(T_LPC17xx_40xx_Timer_Workspace *p)
{
    // Look at the registers and see which are causing an interrupt
    TUInt8 ir = p->iReg->iIR;
    if (ir & (1 << 0)) {
        // Match register 0
        if (p->iCallbacks[0].iCallbackFunc)
            p->iCallbacks[0].iCallbackFunc(p->iCallbacks[0].iCallbackWorkspace);
    }
    if (ir & (1 << 1)) {
        // Match register 1
        if (p->iCallbacks[1].iCallbackFunc)
            p->iCallbacks[1].iCallbackFunc(p->iCallbacks[1].iCallbackWorkspace);
    }
    if (ir & (1 << 2)) {
        // Match register 2
        if (p->iCallbacks[2].iCallbackFunc)
            p->iCallbacks[2].iCallbackFunc(p->iCallbacks[2].iCallbackWorkspace);
    }
    if (ir & (1 << 3)) {
        // Match register 3
        if (p->iCallbacks[3].iCallbackFunc)
            p->iCallbacks[3].iCallbackFunc(p->iCallbacks[3].iCallbackWorkspace);
    }
    // Clear interrupts called in this pass (if another one came in, we'll get it
    // on the next interrupt).
    p->iReg->iIR = ir;
}

/*---------------------------------------------------------------------------*
 * Routine:  LPC247x_Timer_SetMatchCallback
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup a callback routine for this timer on one of the match
 *      registers.  The callback is called when a match occurs and an
 *      interrupt occurs.  The callback is called from within the ISR.
 * Inputs:
 *      void *aWorkspace -- Timer workspace
 *      TUInt8 aMatchRegister -- Which match register to set callback
 *      T_Timer_Callback aCallbackFunc -- Function to call, or 0 to clear.
 *      void *aCallbackWorkspace -- Workspace to pass to callback
 * Outputs:
 *      T_uezError -- UEZ_ERROR_ILLEGAL_PARAMETER if match register is out
 *          of range.
 *---------------------------------------------------------------------------*/
static T_uezError LPC17xx_40xx_Timer_SetMatchCallback(
        void *aWorkspace,
        TUInt8 aMatchRegister,
        T_HALTimer_Callback aCallbackFunc,
        void *aCallbackWorkspace)
{
    T_LPC17xx_40xx_Timer_Workspace *p = (T_LPC17xx_40xx_Timer_Workspace *)aWorkspace;
    TBool any;
    TUInt8 i;

    // Determine if legal match register
    if (aMatchRegister >= 4)
        return UEZ_ERROR_ILLEGAL_PARAMETER;

    // Set the callback (which can be 0 as well as an address)
    p->iCallbacks[aMatchRegister].iCallbackFunc = aCallbackFunc;
    p->iCallbacks[aMatchRegister].iCallbackWorkspace = aCallbackWorkspace;

    // Check to see if there are any callbacks
    any = EFalse;
    for (i = 0; i < 4; i++) {
        if (p->iCallbacks[i].iCallbackFunc) {
            any = ETrue;
            break;
        }
    }

    // Register or deregister the interrupt
    if (any) {
        // Register if not already registered
        if (!InterruptIsRegistered(p->iInfo->iVector))
            InterruptRegister(p->iInfo->iVector, p->iInfo->iISR,
                    INTERRUPT_PRIORITY_HIGH, p->iInfo->iName);
        InterruptEnable(p->iInfo->iVector);
    } else {
        // No one registered anymore, turn off this callback (but leave registered)
        InterruptDisable(p->iInfo->iVector);
    }
    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  IClear
 *---------------------------------------------------------------------------*
 * Description:
 *      Clear all the callback information for this workspace
 * Inputs:
 *      T_LPC247x_Timer_Workspace *p  -- Particular Timer workspace
 *---------------------------------------------------------------------------*/
static void IClear(T_LPC17xx_40xx_Timer_InterruptCallback aCallbacks[4])
{
    TUInt8 i;
    for (i = 0; i < 4; i++) {
        aCallbacks[i].iCallbackFunc = 0;
        aCallbacks[i].iCallbackWorkspace = 0;
    }
}

/*---------------------------------------------------------------------------*
 * Routine:  LPC17xx_40xx_Timer0_InitializeWorkspace
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the LPC17xx_40xx Timer0 workspace.
 * Inputs:
 *      void *aW                    -- Particular Timer workspace
 * Outputs:
 *      T_uezError                   -- Error code
 *---------------------------------------------------------------------------*/
T_uezError LPC17xx_40xx_Timer0_InitializeWorkspace(void *aWorkspace)
{
    T_LPC17xx_40xx_Timer_Workspace *p = (T_LPC17xx_40xx_Timer_Workspace *)aWorkspace;
    p->iReg = (T_LPC17xx_40xx_Timer_Registers *)LPC_TIM0_BASE;
    p->iInfo = &G_Timer0_Info;
    IClear(p->iCallbacks);

    G_Timer0_Workspace = p;

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LPC17xx_40xx_Timer1_InitializeWorkspace
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the LPC17xx_40xx Timer1 workspace.
 * Inputs:
 *      void *aW                    -- Particular Timer workspace
 * Outputs:
 *      T_uezError                   -- Error code
 *---------------------------------------------------------------------------*/
T_uezError LPC17xx_40xx_Timer1_InitializeWorkspace(void *aWorkspace)
{
    T_LPC17xx_40xx_Timer_Workspace *p = (T_LPC17xx_40xx_Timer_Workspace *)aWorkspace;
    p->iReg = (T_LPC17xx_40xx_Timer_Registers *)LPC_TIM1_BASE;
    p->iInfo = &G_Timer1_Info;
    IClear(p->iCallbacks);

    G_Timer1_Workspace = p;

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LPC17xx_40xx_Timer2_InitializeWorkspace
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the LPC17xx_40xx Timer1 workspace.
 * Inputs:
 *      void *aW                    -- Particular Timer workspace
 * Outputs:
 *      T_uezError                   -- Error code
 *---------------------------------------------------------------------------*/
T_uezError LPC17xx_40xx_Timer2_InitializeWorkspace(void *aWorkspace)
{
    T_LPC17xx_40xx_Timer_Workspace *p = (T_LPC17xx_40xx_Timer_Workspace *)aWorkspace;
    p->iReg = (T_LPC17xx_40xx_Timer_Registers *)LPC_TIM2_BASE;
    p->iInfo = &G_Timer2_Info;
    IClear(p->iCallbacks);

    G_Timer2_Workspace = p;

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LPC17xx_40xx_Timer3_InitializeWorkspace
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup the LPC17xx_40xx Timer1 workspace.
 * Inputs:
 *      void *aW                    -- Particular Timer workspace
 * Outputs:
 *      T_uezError                   -- Error code
 *---------------------------------------------------------------------------*/
T_uezError LPC17xx_40xx_Timer3_InitializeWorkspace(void *aWorkspace)
{
    T_LPC17xx_40xx_Timer_Workspace *p = (T_LPC17xx_40xx_Timer_Workspace *)aWorkspace;
    p->iReg = (T_LPC17xx_40xx_Timer_Registers *)LPC_TIM3_BASE;
    p->iInfo = &G_Timer3_Info;
    IClear(p->iCallbacks);

    G_Timer3_Workspace = p;

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Routine:  LPC17xx_40xx_Timer_SetMatchRegisterFunctions
 *---------------------------------------------------------------------------*
 * Description:
 *      Setup one of several timer's match registers and what to do on
 *      a match.
 * Inputs:
 *      void *aWorkspace        -- Timer's workspace
 *      TUInt8 aMatchRegister   -- Index to match register (0-3)
 *      T_Timer_MatchPointFunction aFunctions -- List of functions to perform
 *          when the timer reaches this match point.
 *      TUInt32 aMatchPoint -- Point at which functions trigger
 * Outputs:
 *      T_uezError -- Returns UEZ_ERROR_ILLEGAL_PARAMETER if match register
 *          does not exist.  Returns UEZ_ERROR_ILLEGAL_OPERATION if a
 *          function in aFunctions is not supported.  Otherwise, returns
 *          UEZ_ERROR_NONE.
 *---------------------------------------------------------------------------*/
static T_uezError LPC17xx_40xx_Timer_SetMatchRegisterFunctions(
        void *aWorkspace,
        TUInt8 aMatchRegister,
        T_Timer_MatchPointFunction aFunctions,
        TUInt32 aMatchPoint)
{
    T_LPC17xx_40xx_Timer_Workspace *p = (T_LPC17xx_40xx_Timer_Workspace *)aWorkspace;
    T_LPC17xx_40xx_Timer_Registers *r = p->iReg;
    TUInt32 aFlags = 0;
    const T_LPC17xx_40xx_Timer_Info *p_info = p->iInfo;

    // Determine if legal match register
    if (aMatchRegister >= 4)
        return UEZ_ERROR_ILLEGAL_PARAMETER;

    //Make sure Power to the Timer is turned on
    LPC17xx_40xxPowerOn(1UL << p_info->iPCONBitIndex);

    if (aFunctions & ~(TIMER_MATCH_POINT_FUNC_INTERRUPT
            | TIMER_MATCH_POINT_FUNC_RESET | TIMER_MATCH_POINT_FUNC_STOP))
        return UEZ_ERROR_ILLEGAL_OPERATION;

    // Determine what the combined flags are
    if (aFunctions & TIMER_MATCH_POINT_FUNC_INTERRUPT)
        aFlags |= (1 << 0);
    if (aFunctions & TIMER_MATCH_POINT_FUNC_RESET)
        aFlags |= (1 << 1);
    if (aFunctions & TIMER_MATCH_POINT_FUNC_STOP)
        aFlags |= (1 << 2);

    // Set the actions on the match
    r->iMCR &= ~(7 << (aMatchRegister * 3));
    r->iMCR |= (aFlags << (aMatchRegister * 3));

    // Change the match register
    r->iMR[aMatchRegister] = aMatchPoint / (PROCESSOR_OSCILLATOR_FREQUENCY
        / PCLK_FREQUENCY);

    return UEZ_ERROR_NONE;
}

/*---------------------------------------------------------------------------*
 * Internal Information tables:
 *---------------------------------------------------------------------------*/
static const T_LPC17xx_40xx_Timer_Info G_Timer0_Info = {
        TIMER0_IRQn,
        (TISRFPtr)Timer0_ISR,
        "Timer0",
        1, };

static const T_LPC17xx_40xx_Timer_Info G_Timer1_Info = {
        TIMER1_IRQn,
        (TISRFPtr)Timer1_ISR,
        "Timer1",
        2, };

static const T_LPC17xx_40xx_Timer_Info G_Timer2_Info = {
        TIMER2_IRQn,
        (TISRFPtr)Timer2_ISR,
        "Timer2",
        22, };

static const T_LPC17xx_40xx_Timer_Info G_Timer3_Info = {
        TIMER3_IRQn,
        (TISRFPtr)Timer3_ISR,
        "Timer3",
        23, };

/*---------------------------------------------------------------------------*
 * HAL Interface table:
 *---------------------------------------------------------------------------*/
const HAL_Timer LPC17xx_40xx_Timer0_Interface = {
    {
    "NXP:LPC17xx_40xx:Timer0",
    0x0100,
    LPC17xx_40xx_Timer0_InitializeWorkspace,
    sizeof(T_LPC17xx_40xx_Timer_Workspace),
    },

    LPC17xx_40xx_Timer_SetTimerMode,
    LPC17xx_40xx_Timer_SetCaptureSource,
    LPC17xx_40xx_Timer_SetMatchRegister,
    LPC17xx_40xx_Timer_SetExternalControl,
    LPC17xx_40xx_Timer_Reset,
    LPC17xx_40xx_Timer_Enable,
    LPC17xx_40xx_Timer_Disable,
    LPC17xx_40xx_Timer_SetMatchCallback,
    LPC17xx_40xx_Timer_SetMatchRegisterFunctions,
};

const HAL_Timer LPC17xx_40xx_Timer1_Interface = {
    {
    "NXP:LPC17xx_40xx:Timer1",
    0x0100,
    LPC17xx_40xx_Timer1_InitializeWorkspace,
    sizeof(T_LPC17xx_40xx_Timer_Workspace),
    },

    LPC17xx_40xx_Timer_SetTimerMode,
    LPC17xx_40xx_Timer_SetCaptureSource,
    LPC17xx_40xx_Timer_SetMatchRegister,
    LPC17xx_40xx_Timer_SetExternalControl,
    LPC17xx_40xx_Timer_Reset,
    LPC17xx_40xx_Timer_Enable,
    LPC17xx_40xx_Timer_Disable,
    LPC17xx_40xx_Timer_SetMatchCallback,
    LPC17xx_40xx_Timer_SetMatchRegisterFunctions,
};

const HAL_Timer LPC17xx_40xx_Timer2_Interface = {
    {
    "NXP:LPC17xx_40xx:Timer2",
    0x0100,
    LPC17xx_40xx_Timer2_InitializeWorkspace,
    sizeof(T_LPC17xx_40xx_Timer_Workspace),
    },

    LPC17xx_40xx_Timer_SetTimerMode,
    LPC17xx_40xx_Timer_SetCaptureSource,
    LPC17xx_40xx_Timer_SetMatchRegister,
    LPC17xx_40xx_Timer_SetExternalControl,
    LPC17xx_40xx_Timer_Reset,
    LPC17xx_40xx_Timer_Enable,
    LPC17xx_40xx_Timer_Disable,
    LPC17xx_40xx_Timer_SetMatchCallback,
    LPC17xx_40xx_Timer_SetMatchRegisterFunctions,
};

const HAL_Timer LPC17xx_40xx_Timer3_Interface = {
    {
    "NXP:LPC17xx_40xx:Timer3",
    0x0100,
    LPC17xx_40xx_Timer3_InitializeWorkspace,
    sizeof(T_LPC17xx_40xx_Timer_Workspace),
    },

    LPC17xx_40xx_Timer_SetTimerMode,
    LPC17xx_40xx_Timer_SetCaptureSource,
    LPC17xx_40xx_Timer_SetMatchRegister,
    LPC17xx_40xx_Timer_SetExternalControl,
    LPC17xx_40xx_Timer_Reset,
    LPC17xx_40xx_Timer_Enable,
    LPC17xx_40xx_Timer_Disable,
    LPC17xx_40xx_Timer_SetMatchCallback,
    LPC17xx_40xx_Timer_SetMatchRegisterFunctions,
};

/*---------------------------------------------------------------------------*
 * Requirement routines:
 *---------------------------------------------------------------------------*/
void LPC17xx_40xx_Timer0_Require(const T_LPC17xx_40xx_Timer_Settings *aSettings)
{
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsCAP0[] = {
            {GPIO_P1_26, IOCON_D_DEFAULT(3)}, // T0_CAP0
            {GPIO_P3_23, IOCON_D_DEFAULT(3)}, // T0_CAP0
    };
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsCAP1[] = {
            {GPIO_P1_27, IOCON_D_DEFAULT(3)}, // T0_CAP1
            {GPIO_P3_24, IOCON_D_DEFAULT(3)}, // T0_CAP1
    };
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsMAT0[] = {
            {GPIO_P1_28, IOCON_D_DEFAULT(3)}, // T0_MAT0
            {GPIO_P3_25, IOCON_D_DEFAULT(3)}, // T0_MAT0
    };
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsMAT1[] = {
            {GPIO_P1_29, IOCON_D_DEFAULT(3)}, // T0_MAT1
            {GPIO_P3_26, IOCON_D_DEFAULT(3)}, // T0_MAT0
    };
    HAL_DEVICE_REQUIRE_ONCE();
    // Register Timer0
    HALInterfaceRegister("Timer0", (T_halInterface *)&LPC17xx_40xx_Timer0_Interface,
            0, 0);
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iCAP[0], pinsCAP0,
            ARRAY_COUNT(pinsCAP0));
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iCAP[1], pinsCAP1,
            ARRAY_COUNT(pinsCAP1));
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iMAT[0], pinsMAT0,
            ARRAY_COUNT(pinsMAT0));
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iMAT[1], pinsMAT1,
            ARRAY_COUNT(pinsMAT1));
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iMAT[2], 0, 0);
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iMAT[3], 0, 0);
}

void LPC17xx_40xx_Timer1_Require(const T_LPC17xx_40xx_Timer_Settings *aSettings)
{
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsCAP0[] = {
            {GPIO_P1_18, IOCON_D_DEFAULT(3)}, // T1_CAP0
            {GPIO_P3_27, IOCON_D_DEFAULT(3)}, // T1_CAP0
    };
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsCAP1[] = {
            {GPIO_P1_19, IOCON_D_DEFAULT(3)}, // T1_CAP1
            {GPIO_P3_28, IOCON_D_DEFAULT(3)}, // T1_CAP1
    };
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsMAT0[] = {
            {GPIO_P1_22, IOCON_D_DEFAULT(3)}, // T1_MAT0
            {GPIO_P3_29, IOCON_D_DEFAULT(3)}, // T1_MAT0
    };
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsMAT1[] = {
            {GPIO_P1_25, IOCON_D_DEFAULT(3)}, // T1_MAT1
            {GPIO_P3_30, IOCON_D_DEFAULT(3)}, // T1_MAT1
    };
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsMAT2[] = {
            {GPIO_P3_31, IOCON_D_DEFAULT(3)}, // T1_MAT2
    };
    HAL_DEVICE_REQUIRE_ONCE();
    // Register Timer1
    HALInterfaceRegister("Timer1", (T_halInterface *)&LPC17xx_40xx_Timer1_Interface,
            0, 0);
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iCAP[0], pinsCAP0,
            ARRAY_COUNT(pinsCAP0));
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iCAP[1], pinsCAP1,
            ARRAY_COUNT(pinsCAP1));
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iMAT[0], pinsMAT0,
            ARRAY_COUNT(pinsMAT0));
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iMAT[1], pinsMAT1,
            ARRAY_COUNT(pinsMAT1));
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iMAT[2], pinsMAT2,
            ARRAY_COUNT(pinsMAT2));
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iMAT[3], 0, 0);
}

void LPC17xx_40xx_Timer2_Require(const T_LPC17xx_40xx_Timer_Settings *aSettings)
{
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsCAP0[] = {
            {GPIO_P0_4,  IOCON_D_DEFAULT(3)}, // T2_CAP0
            {GPIO_P1_14, IOCON_D_DEFAULT(3)}, // T2_CAP0
            {GPIO_P2_6,  IOCON_D_DEFAULT(3)}, // T2_CAP0
            {GPIO_P2_14, IOCON_D_DEFAULT(3)}, // T2_CAP0
    };
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsCAP1[] = {
            {GPIO_P0_5,  IOCON_D_DEFAULT(3)}, // T2_CAP1
            {GPIO_P2_15, IOCON_D_DEFAULT(3)}, // T2_CAP1
    };
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsMAT0[] = {
            {GPIO_P0_6,  IOCON_D_DEFAULT(3)}, // T2_MAT0
            {GPIO_P2_5,  IOCON_D_DEFAULT(3)}, // T2_MAT0
            {GPIO_P4_28, IOCON_D_DEFAULT(3)}, // T2_MAT0
    };
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsMAT1[] = {
            {GPIO_P0_7,  IOCON_W_DEFAULT(3)}, // T2_MAT1
            {GPIO_P2_4,  IOCON_D_DEFAULT(3)}, // T2_MAT1
            {GPIO_P4_29, IOCON_D_DEFAULT(3)}, // T2_MAT1
    };
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsMAT2[] = {
            {GPIO_P0_8,  IOCON_W_DEFAULT(3)}, // T2_MAT2
            {GPIO_P2_3,  IOCON_D_DEFAULT(3)}, // T2_MAT2
            {GPIO_P5_0,  IOCON_D_DEFAULT(3)}, // T2_MAT2
    };
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsMAT3[] = {
            {GPIO_P0_9,  IOCON_W_DEFAULT(3)}, // T2_MAT3
            {GPIO_P2_2,  IOCON_D_DEFAULT(3)}, // T2_MAT3
            {GPIO_P5_1,  IOCON_D_DEFAULT(3)}, // T2_MAT3
    };
    HAL_DEVICE_REQUIRE_ONCE();
    // Register Timer2
    HALInterfaceRegister("Timer2", (T_halInterface *)&LPC17xx_40xx_Timer2_Interface,
            0, 0);
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iCAP[0], pinsCAP0,
            ARRAY_COUNT(pinsCAP0));
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iCAP[1], pinsCAP1,
            ARRAY_COUNT(pinsCAP1));
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iMAT[0], pinsMAT0,
            ARRAY_COUNT(pinsMAT0));
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iMAT[1], pinsMAT1,
            ARRAY_COUNT(pinsMAT1));
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iMAT[2], pinsMAT2,
            ARRAY_COUNT(pinsMAT2));
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iMAT[2], pinsMAT3,
            ARRAY_COUNT(pinsMAT3));
}

void LPC17xx_40xx_Timer3_Require(const T_LPC17xx_40xx_Timer_Settings *aSettings)
{
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsCAP0[] = {
            {GPIO_P1_10, IOCON_D_DEFAULT(3)}, // T3_CAP0
            {GPIO_P2_22, IOCON_D_DEFAULT(3)}, // T3_CAP0
            {GPIO_P0_23, IOCON_W_DEFAULT(3)}, // T3_CAP0
    };
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsCAP1[] = {
            {GPIO_P1_0,  IOCON_D_DEFAULT(3)}, // T3_CAP1
            {GPIO_P2_23, IOCON_D_DEFAULT(3)}, // T3_CAP1
            {GPIO_P0_24, IOCON_W_DEFAULT(3)}, // T3_CAP1
    };
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsMAT0[] = {
            {GPIO_P0_10, IOCON_D_DEFAULT(3)}, // T3_MAT0
            {GPIO_P1_9,  IOCON_D_DEFAULT(3)}, // T3_MAT0
            {GPIO_P2_26, IOCON_D_DEFAULT(3)}, // T3_MAT0
    };
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsMAT1[] = {
            {GPIO_P0_11, IOCON_D_DEFAULT(3)}, // T3_MAT1
            {GPIO_P1_8,  IOCON_D_DEFAULT(3)}, // T3_MAT1
            {GPIO_P2_27, IOCON_D_DEFAULT(3)}, // T3_MAT1
    };
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsMAT2[] = {
            {GPIO_P1_4,  IOCON_D_DEFAULT(3)}, // T3_MAT2
            {GPIO_P2_30, IOCON_D_DEFAULT(3)}, // T3_MAT2
            {GPIO_P5_2,  IOCON_I_DEFAULT(3)}, // T3_MAT2
    };
    static const T_LPC17xx_40xx_IOCON_ConfigList pinsMAT3[] = {
            {GPIO_P1_1,  IOCON_D_DEFAULT(3)}, // T3_MAT3
            {GPIO_P2_31, IOCON_D_DEFAULT(3)}, // T3_MAT3
            {GPIO_P5_4,  IOCON_D_DEFAULT(3)}, // T3_MAT3
    };
    HAL_DEVICE_REQUIRE_ONCE();
    // Register Timer3
    HALInterfaceRegister("Timer3", (T_halInterface *)&LPC17xx_40xx_Timer3_Interface,
            0, 0);
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iCAP[0], pinsCAP0,
            ARRAY_COUNT(pinsCAP0));
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iCAP[1], pinsCAP1,
            ARRAY_COUNT(pinsCAP1));
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iMAT[0], pinsMAT0,
            ARRAY_COUNT(pinsMAT0));
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iMAT[1], pinsMAT1,
            ARRAY_COUNT(pinsMAT1));
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iMAT[2], pinsMAT2,
            ARRAY_COUNT(pinsMAT2));
    LPC17xx_40xx_IOCON_ConfigPinOrNone(aSettings->iMAT[2], pinsMAT3,
            ARRAY_COUNT(pinsMAT3));
}

/*-------------------------------------------------------------------------*
 * End of File:  Timer.c
 *-------------------------------------------------------------------------*/


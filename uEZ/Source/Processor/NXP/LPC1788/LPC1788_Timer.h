/*-------------------------------------------------------------------------*
 * File:  LPC1788_Timer.h
 *-------------------------------------------------------------------------*
 * Description:
 *     
 *-------------------------------------------------------------------------*/
#ifndef LPC1788_TIMER_H_
#define LPC1788_TIMER_H_

/*--------------------------------------------------------------------------
 * uEZ(tm) - Copyright (C) 2007-2011 Future Designs, Inc.
 *--------------------------------------------------------------------------
 * This file is part of the uEZ(tm) distribution.
 *
 * uEZ(tm) is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * uEZ(tm) is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with uEZ(tm); if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * A special exception to the GPL can be applied should you wish to
 * distribute a combined work that includes uEZ(tm), without being obliged
 * to provide the source code for any proprietary components.  See the
 * licensing section of http://www.teamfdi.com/uez for full details of how
 * and when the exception can be applied.
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
#include <HAL/Timer.h>
#include <Types/GPIO.h>

/*-------------------------------------------------------------------------*
 * Constants:
 *-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*
 * Types:
 *-------------------------------------------------------------------------*/
typedef struct {
    T_uezGPIOPortPin iCAP[2];
    T_uezGPIOPortPin iMAT[4];
} T_LPC1788_Timer_Settings;

/*-------------------------------------------------------------------------*
 * Prototypes:
 *-------------------------------------------------------------------------*/
extern const HAL_Timer LPC1788_Timer0_Interface;
extern const HAL_Timer LPC1788_Timer1_Interface;
extern const HAL_Timer LPC1788_Timer2_Interface;
extern const HAL_Timer LPC1788_Timer3_Interface;

void LPC1788_Timer0_Require(const T_LPC1788_Timer_Settings *aSettings);
void LPC1788_Timer1_Require(const T_LPC1788_Timer_Settings *aSettings);
void LPC1788_Timer2_Require(const T_LPC1788_Timer_Settings *aSettings);
void LPC1788_Timer3_Require(const T_LPC1788_Timer_Settings *aSettings);

#endif // LPC1788_TIMER_H_
/*-------------------------------------------------------------------------*
 * End of File:  LPC1788_Timer.h
 *-------------------------------------------------------------------------*/

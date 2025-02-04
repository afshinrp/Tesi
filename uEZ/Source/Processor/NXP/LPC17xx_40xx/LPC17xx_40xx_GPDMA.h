/*-------------------------------------------------------------------------*
 * File:  LPC17xx_40xx_GPDMA.h
 *-------------------------------------------------------------------------*
 * Description:
 *     
 *-------------------------------------------------------------------------*/
#ifndef LPC17xx_40xx_GPDMA_H_
#define LPC17xx_40xx_GPDMA_H_

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
#include <HAL/GPDMA.h>

/*-------------------------------------------------------------------------*
 * Constants:
 *-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*
 * Types:
 *-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*
 * Prototypes:
 *-------------------------------------------------------------------------*/
extern const HAL_GPDMA LPC17xx_40xx_GPDMA_Channel0_Interface;
extern const HAL_GPDMA LPC17xx_40xx_GPDMA_Channel1_Interface;
extern const HAL_GPDMA LPC17xx_40xx_GPDMA_Channel2_Interface;
extern const HAL_GPDMA LPC17xx_40xx_GPDMA_Channel3_Interface;
extern const HAL_GPDMA LPC17xx_40xx_GPDMA_Channel4_Interface;
extern const HAL_GPDMA LPC17xx_40xx_GPDMA_Channel5_Interface;
extern const HAL_GPDMA LPC17xx_40xx_GPDMA_Channel6_Interface;
extern const HAL_GPDMA LPC17xx_40xx_GPDMA_Channel7_Interface;
void LPC17xx_40xx_GPDMA0_Require(void);
void LPC17xx_40xx_GPDMA1_Require(void);
void LPC17xx_40xx_GPDMA2_Require(void);
void LPC17xx_40xx_GPDMA3_Require(void);
void LPC17xx_40xx_GPDMA4_Require(void);
void LPC17xx_40xx_GPDMA5_Require(void);
void LPC17xx_40xx_GPDMA6_Require(void);
void LPC17xx_40xx_GPDMA7_Require(void);

#endif // LPC17xx_40xx_GPDMA_H_
/*-------------------------------------------------------------------------*
 * End of File:  LPC17xx_40xx_GPDMA.h
 *-------------------------------------------------------------------------*/

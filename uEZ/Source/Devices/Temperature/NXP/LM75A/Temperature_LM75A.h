/*-------------------------------------------------------------------------*
 * File:  Temperature_LM75A.h
 *-------------------------------------------------------------------------*
 * Description:
 *     
 *-------------------------------------------------------------------------*/
#ifndef TEMPERATURE_LM75A_H_
#define TEMPERATURE_LM75A_H_

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
#include <Device/Temperature.h>
#include <Device/I2CBus.h>

/*-------------------------------------------------------------------------*
 * Constants:
 *-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*
 * Types:
 *-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*
 * Globals:
 *-------------------------------------------------------------------------*/
extern const DEVICE_Temperature Temperature_NXP_LM75A_Interface;

/*-------------------------------------------------------------------------*
 * Prototypes:
 *-------------------------------------------------------------------------*/
void Temp_NXP_LM75A_Configure(
        void *aWorkspace,
        DEVICE_I2C_BUS **aI2C,
        TUInt8 aI2CAddr);
void Temp_NXP_LM75A_Create(
        const char *aName,
        const char *aI2CBusName,
        TUInt8 aI2CAddr);

#endif // TEMPERATURE_LM75A_H_
/*-------------------------------------------------------------------------*
 * End of File:  Temperature_LM75A.h
 *-------------------------------------------------------------------------*/

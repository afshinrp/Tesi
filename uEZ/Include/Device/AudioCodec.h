/*-------------------------------------------------------------------------*
 * File:  DEVICE_AudioCodec.h
 *-------------------------------------------------------------------------*
 * Description:
 *     uEZ Audio Codec Device
 *-------------------------------------------------------------------------*/
#ifndef _DEVICE_AudioCodec_H_
#define _DEVICE_AudioCodec_H_

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
 *  @file   /Include/Device/ButtonBank.h
 *  @brief  uEZ ButtonBank Device Interface
 *
 *  The uEZ ButtonBank Device Interface
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
#include <uEZDevice.h>

/*-------------------------------------------------------------------------*
 * Types:
 *-------------------------------------------------------------------------*/
 typedef struct {
    // Header
    T_uezDeviceInterface iDevice;

    // Functions
    T_uezError (*UseConfiguration)(void *aWorkspace, TUInt32 aConfiguration);
} DEVICE_AudioCodec;
#endif // _DEVICE_AudioCodec_H_
/*-------------------------------------------------------------------------*
 * End of File:  AudioCodec.h
 *-------------------------------------------------------------------------*/

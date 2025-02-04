/*-------------------------------------------------------------------------*
 * File:  uEZHandles.h
 *-------------------------------------------------------------------------*
 * Description:
 *     List of handles in the system.
 *-------------------------------------------------------------------------*/
#ifndef _UEZ_HANDLES_H_
#define _UEZ_HANDLES_H_

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

/*-------------------------------------------------------------------------*
 * Includes:
 *-------------------------------------------------------------------------*/
#include "uEZTypes.h"

/*-------------------------------------------------------------------------*
 * Constants:
 *-------------------------------------------------------------------------*/
#ifndef UEZ_HANDLES_CHECK
#define UEZ_HANDLES_CHECK       0
#endif

#ifndef UEZ_HANDLES_FAIL_CALLBACK
#define UEZ_HANDLES_FAIL_CALLBACK   0
#endif

#define UEZ_HANDLE_TYPE_MASK      0x000000FF
#define UEZ_HANDLE_FREE           0x00000000
#define UEZ_HANDLE_RESERVED       0x00000001
#define UEZ_HANDLE_ZOMBIE         0x00000002
#define UEZ_HANDLE_TASK           0x00000003
#define UEZ_HANDLE_SEMAPHORE      0x00000004
#define UEZ_HANDLE_QUEUE          0X00000005
#define UEZ_HANDLE_DEVICE         0X00000006

#define UEZ_SEMAPHORE_BINARY      0
#define UEZ_SEMAPHORE_COUNTING    1
#define UEZ_SEMAPHORE_MUTEX       2

#define UEZ_NULL_HANDLE             0

/*-------------------------------------------------------------------------*
 * Types:
 *-------------------------------------------------------------------------*/
typedef struct {
    TUInt32 iTypeAndFlags;
    TUInt32 iData[3];
} T_uezlexHandleStruct;

/*-------------------------------------------------------------------------*
 * Globals:
 *-------------------------------------------------------------------------*/
extern T_uezlexHandleStruct G_handles[UEZ_NUM_HANDLES];

/*-------------------------------------------------------------------------*
 * Prototypes:
 *-------------------------------------------------------------------------*/
void uEZHandleTableInit(void);
T_uezError uEZHandleAlloc(T_uezHandle *aHandle);
T_uezError uEZHandleFree(T_uezHandle aHandle);
T_uezError uEZHandleSet(
    T_uezHandle aHandle, 
    TUInt32 iTypeAndFlags,
    TUInt32 aData1, 
    TUInt32 aData2, 
    TUInt32 aData3);
T_uezError uEZHandleGet(
    T_uezHandle aHandle, 
    TUInt32 *iTypeAndFlags,
    TUInt32 *aData1, 
    TUInt32 *aData2, 
    TUInt32 *aData3);
T_uezError uEZHandleGetFromISR(
    T_uezHandle aHandle, 
    TUInt32 *aTypeAndFlags,
    TUInt32 *aData1, 
    TUInt32 *aData2, 
    TUInt32 *aData3);

#define UEZ_HANDLE_FIND_START 0xFFFFFFFF
T_uezError uEZHandleFindOfType(TUInt32 aType, T_uezHandle *aHandle, TUInt32 *aIndex);
TUInt32 uEZHandleGetType(T_uezHandle aHandle);

#if UEZ_HANDLES_FAIL_CALLBACK
void UEZHandleFailCallback(void);
#endif

void uEZHandlesCheck(void);

#endif // _UEZ_HANDLES_H_
/*-------------------------------------------------------------------------*
 * End of File:  uEZHandles.h
 *-------------------------------------------------------------------------*/

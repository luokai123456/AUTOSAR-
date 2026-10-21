/*
************************************************************************************************************************
*
* File name: Rte.c
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
************************************************************************************************************************
*
* History
*-----------------------------------------------------------------------------------------------------------------------
************************************************************************************************************************
* Version: 3.0
* Author/Date: Gaol/2022.6.14
* Change: New created.
* Cause: New
************************************************************************************************************************
* Version: 4.0
* Author/Date: LanZG/2024.03.18
* Change: Upgrade template.
* Cause: Update
************************************************************************************************************************
*/
#define RTE_CORE

/*
************************************************************************************************************************
*    Includes
************************************************************************************************************************
*/
#include "Os.h"
#include "Rte_Type.h"
#include "Rte_Main.h"
#include "Rte_Cbk.h"
#include "Rte_Hook.h"
#include "SchM_BswM.h"
#include "SchM_CanIf.h"
#include "SchM_CanNm.h"
#include "SchM_CanSM.h"
#include "SchM_CanTp.h"
#include "Com.h"
#include "SchM_Com.h"
#include "SchM_ComM.h"
#include "SchM_Csm.h"
#include "SchM_Dcm.h"
#include "SchM_Dem.h"
#include "SchM_EcuM.h"
#include "SchM_Fee.h"
#include "SchM_FiM.h"
#include "SchM_J1939Tp.h"
#include "SchM_KeyM.h"
#include "SchM_LinIf.h"
#include "SchM_LinSM.h"
#include "SchM_Nm.h"
#include "SchM_NvM.h"
#include "SchM_SecOC.h"
#include "SchM_WdgM.h"
#include "SchM_Xcp.h"
#include "Rte_ComRx_CAN.h"
#include "Rte_ComTx_CAN.h"
#include "Rte_PMS_BswAswRte.h"
#include "Rte_PMS_RollingCounter.h"
#include "Rte_swc_CIL.h"
#include "Rte_swc_COL.h"
#include "Rte_swc_SetSendCANMsg.h"
#include "Rte_swc_VCOP.h"

/*
************************************************************************************************************************
*    Global Variables
************************************************************************************************************************
*/
#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)

#define RTE_START_SEC_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
volatile VAR(uint8, RTE_VAR_INIT) Rte_CoreState[RTE_CORE_COUNT] = {0U};
#define RTE_STOP_SEC_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"

#define RTE_START_SEC_CONST
#include "Rte_MemMap.h"
CONST(uint8, RTE_CONST) Rte_CoreInUseState[RTE_CORE_COUNT] = {RTE_CORE_IN_USE, RTE_CORE_IN_USE, RTE_CORE_IN_USE, RTE_CORE_IN_USE, RTE_CORE_IN_USE, RTE_CORE_IN_USE};
#define RTE_STOP_SEC_CONST
#include "Rte_MemMap.h"

#endif


/*
************************************************************************************************************************
*   API for enable / disable interrupts up to the systemLevel.
************************************************************************************************************************
*/
#define Rte_DisableOSInterrupts() SuspendOSInterrupts()
#define Rte_EnableOSInterrupts() ResumeOSInterrupts()


/*
************************************************************************************************************************
*    Definition of Calibration Parameters
************************************************************************************************************************
*/

#define RTE_START_SEC_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"

VAR(sint32, RTE_VAR_INIT) XcpCalOffset = 0;

#define RTE_STOP_SEC_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    Timer handling. 
************************************************************************************************************************
*/

# define RTE_CONST_MSEC_SYSTEMTIMER_BASE_SYSTEMTIMER_CORE0 (1U)
# define RTE_CONST_MSEC_SYSTEMTIMER_BASE_SYSTEMTIMER_CORE1 (1U)
# define RTE_CONST_MSEC_SYSTEMTIMER_BASE_SYSTEMTIMER_CORE2 (1U)
# define RTE_CONST_MSEC_SYSTEMTIMER_BASE_SYSTEMTIMER_CORE3 (1U)
# define RTE_CONST_MSEC_SYSTEMTIMER_BASE_SYSTEMTIMER_CORE4 (1U)
# define RTE_CONST_MSEC_SYSTEMTIMER_BASE_SYSTEMTIMER_CORE5 (1U)

/*
************************************************************************************************************************
*    NvM-Callback for Rte_SetMirror
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    NvM-Callback for Rte_GetMirror
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    NvM-Callback for Rte_NvMNotifyInitBlock
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    NvM-Callback for Rte_NvMNotifyJobFinished
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Definition of Rte functions
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint16_least num); 
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) RteBuff_PushRelease(P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC(void, RTE_CODE) RteBuff_PopRelease(P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteBuff_PopLock(P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteBuff_PushLock(P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteStack_Push(P2VAR(RteStackBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteStack_Pop(P2VAR(RteStackBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) Rte_MemSet(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, uint8 c, uint32 num);
FUNC(void, RTE_CODE) Rte_MoveFront(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) cPtr, uint32 bufferLength, uint32 moveLength);
FUNC(void, RTE_CODE) Rte_MoveBehind(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) cPtr, uint32 bufferLength, uint32 moveLength);

FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num)
{
  P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) src = source;
  P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dst = destination;
  uint32_least i;
  for (i = 0; i < num; i++)
  {
    dst[i] = src[i];
  }
}

#define RTE_MEMCPY32ALIGN (sizeof(uint32) - 1)

FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num)
{
    #define UNALIGNED(X, Y)     (((uint32)X & (sizeof (uint32) - 1)) | ((uint32)Y & (sizeof (uint32) - 1)))
    #define BIGBLOCKSIZE        (sizeof(uint32) << 2)
    #define LITTLEBLOCKSIZE     (sizeof(uint32))
    #define TOO_SMALL(LEN)      ((LEN) < BIGBLOCKSIZE)
    #define RTE_P2P(_dstPtrType, _ptr)        ((_dstPtrType* )(_ptr))
    uint32 *alignedDst;
    uint32 *alignedSrc;
    uint8* uint8Dst = RTE_P2P(uint8, destination);
    uint8* uint8Src = RTE_P2P(uint8, source);
    if (!TOO_SMALL(num) && !UNALIGNED(source, destination))
    {
        alignedDst = (uint32 *)destination;
        alignedSrc = (uint32 *)source;
        while (num >= BIGBLOCKSIZE)
        {
            *alignedDst++ = *alignedSrc++;
            *alignedDst++ = *alignedSrc++;
            *alignedDst++ = *alignedSrc++;
            *alignedDst++ = *alignedSrc++;
            num -= BIGBLOCKSIZE;
        }
        while (num >= LITTLEBLOCKSIZE)
        {
            *alignedDst++ = *alignedSrc++;
            num -= LITTLEBLOCKSIZE;
        }

        uint8Dst = RTE_P2P(uint8, alignedDst);
        uint8Src = RTE_P2P(uint8, alignedSrc);
    }

    while (num--)
    {
        *uint8Dst++ = *uint8Src++;
    }
}

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint16_least num)
{
  P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = ptr;
  uint16_least i;
  for (i = 0; i < num; i++)
  {
    dst[i] = 0;
  }
}

#define RTE_BYTE_ZERO (0U)

FUNC(void, RTE_CODE) RteBuff_PushRelease
(
    P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr
)
{
    ++cPtr->currCnt;
}
FUNC(void, RTE_CODE) RteBuff_PopRelease
(
    P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr
)
{
    --cPtr->currCnt;
}

FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteBuff_PushLock
(
    P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr
)
{
    void* dataPtr;
    void* retVal;

    if( (cPtr == NULL_PTR) || (cPtr->currCnt == cPtr->maxCnt) )
    {
        /* No space */
        retVal = NULL_PTR;	
    }
    else
    {
        dataPtr = cPtr->head;
        cPtr->head = (char *)cPtr->head + cPtr->dataSize;
        if( cPtr->head == cPtr->bufEnd )
        {
            cPtr->head = cPtr->bufStart;
        }
        retVal = dataPtr;
    }
    return retVal;
}

FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteBuff_PopLock
(
    P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr
)
{
    void *dataPtr = NULL_PTR;
    void* retVal;

    if( ((cPtr==NULL_PTR) || (cPtr->currCnt == RTE_BYTE_ZERO)) == TRUE )
    {
        retVal = NULL_PTR;
    }
    else
    {
        dataPtr = cPtr->tail;
        cPtr->tail = (char *)cPtr->tail + cPtr->dataSize;
        if( cPtr->tail == cPtr->bufEnd )
        {
            cPtr->tail = cPtr->bufStart;
        }
        retVal = dataPtr;
    }
    return retVal;
}

FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteStack_Push
(
    P2VAR(RteStackBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr
)
{
    void* retVal = NULL_PTR;

    if( (NULL_PTR == cPtr) || (cPtr->currCnt == cPtr->maxCnt) )
    {
        /* No space */
        retVal = NULL_PTR;	
    }
    else
    {
        /* Get pointer and add top */
        retVal = cPtr->top;
        cPtr->top = (char *)cPtr->top + cPtr->dataSize;
        ++cPtr->currCnt;
        
        /* Pointer is error */
        if( cPtr->top > cPtr->bufEnd )
        {
            /* Error: roll-back */
            cPtr->top = (char *)cPtr->top - cPtr->dataSize;
            --cPtr->currCnt;
            retVal = NULL_PTR;
        }
    }
    return retVal;
}

FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteStack_Pop
(
    P2VAR(RteStackBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr
)
{
    void* retVal = NULL_PTR;

    if( (NULL_PTR == cPtr) || (RTE_BYTE_ZERO == cPtr->currCnt) )
    {
        /* No data */
        retVal = NULL_PTR;
    }
    else
    {
        /* Subtract top and get pointer */
        cPtr->top = (char *)cPtr->top - cPtr->dataSize;
        --cPtr->currCnt;
        retVal = cPtr->top;
        
        /* Pointer is error */
        if( cPtr->top < cPtr->bufStart )
        {
            /* Error: roll-back */
            cPtr->top = (char *)cPtr->top + cPtr->dataSize;
            ++cPtr->currCnt;
            retVal = NULL_PTR;
        }
    }
    return retVal;
}

#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)

FUNC(void, RTE_CODE) Rte_WaitMasterCoreStart(void)
{
    while(RTE_CORE_STATE_INIT != (uint8)Rte_CoreState[RTE_CORE_MASTER_ID]) {};
}

FUNC(void, RTE_CODE) Rte_WaitMultiCoreSyncStart(void)
{
    uint8 synCoreIdx;
    uint8 allCoreInitOk;
    do
    {
        allCoreInitOk = RTE_CORE_ALL_INIT_OK;
        for(synCoreIdx = 0; synCoreIdx < (uint8)RTE_CORE_COUNT; synCoreIdx++)
        {
            if(RTE_CORE_IN_USE == Rte_CoreInUseState[synCoreIdx] && RTE_CORE_STATE_INIT != Rte_CoreState[synCoreIdx])
            {
                allCoreInitOk = RTE_CORE_NOT_INIT_OK;
            }
        }
    } while(RTE_CORE_ALL_INIT_OK != allCoreInitOk);
}

#endif

FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) Rte_MemSet(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, uint8 c, uint32 num)
{
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dst = destination;
    uint32 i = 0;
    for(i = 0; i < num; ++i)
    {
        dst[i] = c;
    }
    return destination;
}

FUNC(void, RTE_CODE) Rte_MoveFront(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) cPtr, uint32 bufferLength, uint32 moveLength)
{
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dst = cPtr;
    uint32 i = 0;
    uint32 iMoveLength = 0;
    uint8 temp = 0;
    for(; iMoveLength < moveLength; ++iMoveLength)
    {
        temp = dst[0];
        for(i = 0; i < bufferLength - 1; ++i)
        {
            dst[i] = dst[i + 1];
        }
        dst[bufferLength - 1] = temp;
    }
}

FUNC(void, RTE_CODE) Rte_MoveBehind(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) cPtr, uint32 bufferLength, uint32 moveLength)
{
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dst = cPtr;
    uint32 i = 0;
    uint32 iMoveLength = 0;
    uint8 temp = 0;
    for(; iMoveLength < moveLength; ++iMoveLength)
    {
        temp = dst[bufferLength - 1];
        for(i = bufferLength - 1; i > 0 ; --i)
        {
            dst[i] = dst[i - 1];
        }
        dst[0] = temp;
    }
}

/*
************************************************************************************************************************
*    RTE life cycle API. 
************************************************************************************************************************
*/

FUNC(void, RTE_CODE) SchM_Init(void)
{
    uint32 id = GetCoreID();

    if (id == OS_CORE_ID_0)
    {

#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[0] = RTE_CORE_STATE_SCHM_INIT;
#endif
    }
    if (id == OS_CORE_ID_1)
    {

#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[1] = RTE_CORE_STATE_SCHM_INIT;
#endif
    }
    if (id == OS_CORE_ID_2)
    {

#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[2] = RTE_CORE_STATE_SCHM_INIT;
#endif
    }
    if (id == OS_CORE_ID_3)
    {

#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[3] = RTE_CORE_STATE_SCHM_INIT;
#endif
    }
    if (id == OS_CORE_ID_4)
    {

#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[4] = RTE_CORE_STATE_SCHM_INIT;
#endif
    }
    if (id == OS_CORE_ID_5)
    {

#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[5] = RTE_CORE_STATE_SCHM_INIT;
#endif
    }
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void)
{
    uint32 id = GetCoreID();

    if (id == OS_CORE_ID_0)
    {

#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[0] = RTE_CORE_STATE_INIT;
#endif
    }
    if (id == OS_CORE_ID_1)
    {
        //(void)ActivateTask(APP1_TASK_UDS_CORE1_QM);

#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[1] = RTE_CORE_STATE_INIT;
#endif
    }
    if (id == OS_CORE_ID_2)
    {
        (void)ActivateTask(APP1_TASK0_UDS_CORE2_QM);
        (void)ActivateTask(APP1_TASK1_UDS_CORE2_QM);
        (void)ActivateTask(APP1_TASK2_UDS_CORE2_QM);

#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[2] = RTE_CORE_STATE_INIT;
#endif
    }
    if (id == OS_CORE_ID_3)
    {
        //(void)ActivateTask(APP1_TASK_UDS_CORE3_QM);
        //(void)ActivateTask(TASK_100US_CORE3_QM);

        //(void)SetRelAlarm(RTE_AL_TE_APP1_TASK_100US_CORE3_QM_100US, 1, RTE_CONST_MSEC_SYSTEMTIMER_BASE_SYSTEMTIMER_CORE3 * (0.1 * 1000) / 1000);
#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[3] = RTE_CORE_STATE_INIT;
#endif
    }
    if (id == OS_CORE_ID_4)
    {
        //(void)ActivateTask(APP1_TASK_UDS_CORE4_QM);

#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[4] = RTE_CORE_STATE_INIT;
#endif
    }
    if (id == OS_CORE_ID_5)
    {
        //(void)ActivateTask(APP1_TASK_UDS_CORE5_QM);

#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[5] = RTE_CORE_STATE_INIT;
#endif
    }
    return RTE_E_OK;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void)
{
    uint32 id = GetCoreID();

    if (id == OS_CORE_ID_0)
    {
#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[0] = RTE_CORE_STATE_SCHM_INIT;
#endif
    }
    if (id == OS_CORE_ID_1)
    {
#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[1] = RTE_CORE_STATE_SCHM_INIT;
#endif
    }
    if (id == OS_CORE_ID_2)
    {
#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[2] = RTE_CORE_STATE_SCHM_INIT;
#endif
    }
    if (id == OS_CORE_ID_3)
    {
        (void)CancelAlarm(RTE_AL_TE_TASK_100US_CORE3_QM_100US);
#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[3] = RTE_CORE_STATE_SCHM_INIT;
#endif
    }
    if (id == OS_CORE_ID_4)
    {
#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[4] = RTE_CORE_STATE_SCHM_INIT;
#endif
    }
    if (id == OS_CORE_ID_5)
    {
#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[5] = RTE_CORE_STATE_SCHM_INIT;
#endif
    }
    return RTE_E_OK;
}

FUNC(void, RTE_CODE) SchM_Deinit(void)
{
    uint32 id = GetCoreID();

    if (id == OS_CORE_ID_0)
    {
#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[0] = RTE_CORE_STATE_UNINIT;
#endif
    }
    if (id == OS_CORE_ID_1)
    {
#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[1] = RTE_CORE_STATE_UNINIT;
#endif
    }
    if (id == OS_CORE_ID_2)
    {
#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[2] = RTE_CORE_STATE_UNINIT;
#endif
    }
    if (id == OS_CORE_ID_3)
    {
#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[3] = RTE_CORE_STATE_UNINIT;
#endif
    }
    if (id == OS_CORE_ID_4)
    {
#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[4] = RTE_CORE_STATE_UNINIT;
#endif
    }
    if (id == OS_CORE_ID_5)
    {
#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
        Rte_CoreState[5] = RTE_CORE_STATE_UNINIT;
#endif
    }
}

/*
************************************************************************************************************************
*    BSW Modules Exclusive Areas 
************************************************************************************************************************
*/

FUNC(void, RTE_CODE) SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0(void)
{
    SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0(void)
{
    ResumeAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_0(void)
{
    SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_0(void)
{
    ResumeAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Enter_CanNm_CANNM_EXCLUSIVE_AREA_0(void)
{
    SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_CanNm_CANNM_EXCLUSIVE_AREA_0(void)
{
    ResumeAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Enter_CanNm_CANNM_EXCLUSIVE_AREA_1(void)
{
    SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_CanNm_CANNM_EXCLUSIVE_AREA_1(void)
{
    ResumeAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Enter_CanNm_CANNM_EXCLUSIVE_AREA_2(void)
{
    SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_CanNm_CANNM_EXCLUSIVE_AREA_2(void)
{
    ResumeAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Enter_CanNm_CANNM_EXCLUSIVE_AREA_3(void)
{
    SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_CanNm_CANNM_EXCLUSIVE_AREA_3(void)
{
    ResumeAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Enter_CanNm_CANNM_EXCLUSIVE_AREA_4(void)
{
    SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_CanNm_CANNM_EXCLUSIVE_AREA_4(void)
{
    ResumeAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Enter_CanNm_CANNM_EXCLUSIVE_AREA_5(void)
{
    SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_CanNm_CANNM_EXCLUSIVE_AREA_5(void)
{
    ResumeAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Enter_CanNm_CANNM_EXCLUSIVE_AREA_6(void)
{
    SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_CanNm_CANNM_EXCLUSIVE_AREA_6(void)
{
    ResumeAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Enter_Dcm_DCM_EXCLUSIVE_AREA_0(void)
{
    SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dcm_DCM_EXCLUSIVE_AREA_0(void)
{
    ResumeAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Enter_Dem_DEM_EXCLUSIVE_AREA_0(void)
{
    SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dem_DEM_EXCLUSIVE_AREA_0(void)
{
    ResumeAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Enter_FiM_FIM_EXCLUSIVE_AREA_0(void)
{
    SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_FiM_FIM_EXCLUSIVE_AREA_0(void)
{
    ResumeAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Enter_LinSM_LINSM_EXCLUSIVE_AREA_0(void)
{
    SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_LinSM_LINSM_EXCLUSIVE_AREA_0(void)
{
    ResumeAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Enter_Nm_NM_EXCLUSIVE_AREA_0(void)
{
    SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Nm_NM_EXCLUSIVE_AREA_0(void)
{
    ResumeAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Enter_Nm_NM_EXCLUSIVE_AREA_1(void)
{
    SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Nm_NM_EXCLUSIVE_AREA_1(void)
{
    ResumeAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0(void)
{
    SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0(void)
{
    ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) Rte_ComSendSignalProxyPeriodic_OsCore0(void)
{
    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComRx_CAN_BMSH_Status_CheckSum_Rx_BMSH_Status_CheckSum_Rx)
    {
        uint8 phydata_0 = (uint8)Rte_ComRx_CAN_BMSH_Status_CheckSum_Rx_BMSH_Status_CheckSum_Rx;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_STATUS_CHECKSUM_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComRx_CAN_BMSH_Status_CheckSum_Rx_BMSH_Status_CheckSum_Rx = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_ActiveDischgFlt_IPU_ActiveDischgFlt)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_ActiveDischgFlt_IPU_ActiveDischgFlt;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_ACTIVEDISCHGFLT_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_ActiveDischgFlt_IPU_ActiveDischgFlt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_BattFaultLampState_IPU_BattFaultLampState)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_BattFaultLampState_IPU_BattFaultLampState;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD_RMXR12_IPU_BATTFAULTLAMPSTATE_IPU_TRQSPD_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_ComTx_CAN_IPU_BattFaultLampState_IPU_BattFaultLampState;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD__XQC0B_IPU_BATTFAULTLAMPSTATE_IPU_TRQSPD_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_BattFaultLampState_IPU_BattFaultLampState = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_BusUndervolt_IPU_BusUndervolt)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_BusUndervolt_IPU_BusUndervolt;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_BUSUNDERVOLT_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_BusUndervolt_IPU_BusUndervolt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_CANCommFlt_IPU_CANCommFlt)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_CANCommFlt_IPU_CANCommFlt;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_CANCOMMFLT_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_CANCommFlt_IPU_CANCommFlt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_DTC_IPU_DTC)
    {
        uint16 phydata_0 = (uint16)Rte_ComTx_CAN_IPU_DTC_IPU_DTC;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_DTC_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_ComTx_CAN_IPU_DTC_IPU_DTC;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO__XQC0B_IPU_DTC_IPU_MOTORALARMINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_DTC_IPU_DTC = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_DischgState_IPU_DischgState)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_DischgState_IPU_DischgState;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD_RMXR12_IPU_DISCHGSTATE_IPU_TRQSPD_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_ComTx_CAN_IPU_DischgState_IPU_DischgState;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD__XQC0B_IPU_DISCHGSTATE_IPU_TRQSPD_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_DischgState_IPU_DischgState = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_HVBusCur_IPU_HVBusCur)
    {
        uint16 phydata_0 = (uint16)Rte_ComTx_CAN_IPU_HVBusCur_IPU_HVBusCur;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORELEPARA_RMXR12_IPU_HVBUSCUR_IPU_MOTORELEPARA_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_HVBusCur_IPU_HVBusCur = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_HVBusVolt_20_IPU_HVBusVolt_20)
    {
        uint16 phydata_0 = (uint16)Rte_ComTx_CAN_IPU_HVBusVolt_20_IPU_HVBusVolt_20;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_STS_RMXR12_IPU_HVBUSVOLT_IPUSTS_IPU_STS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_HVBusVolt_20_IPU_HVBusVolt_20 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_HVBusVolt_500_IPU_HVBusVolt_500)
    {
        uint16 phydata_0 = (uint16)Rte_ComTx_CAN_IPU_HVBusVolt_500_IPU_HVBusVolt_500;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORELEPARA_RMXR12_IPU_HVBUSVOLT_IPU_MOTORELEPARA_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_HVBusVolt_500_IPU_HVBusVolt_500 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_HardwareCapOverVolt_IPU_HardwareCapOverVolt)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_HardwareCapOverVolt_IPU_HardwareCapOverVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_HARDWARECAPOVERVOLT_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_HardwareCapOverVolt_IPU_HardwareCapOverVolt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IGBTFlt_IPU_IGBTFlt)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_IGBTFlt_IPU_IGBTFlt;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_IGBTFLT_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IGBTFlt_IPU_IGBTFlt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgInvrT_IPU_IsgInvrT)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_IsgInvrT_IPU_IsgInvrT;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TEMPERATURE_RMXR12_IPU_ISGINVRT_IPU_TEMPERATURE_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_ComTx_CAN_IPU_IsgInvrT_IPU_IsgInvrT;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TEMPERATURE__XQC0B_IPU_ISGINVRT_IPU_TEMPERATURE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgInvrT_IPU_IsgInvrT = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgInvrTInvalid_IPU_IsgInvrTInvalid)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_IsgInvrTInvalid_IPU_IsgInvrTInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TEMPERATURE_RMXR12_IPU_ISGINVRTINVALID_IPU_TEMPERATURE_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_ComTx_CAN_IPU_IsgInvrTInvalid_IPU_IsgInvrTInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TEMPERATURE__XQC0B_IPU_ISGINVRTINVALID_IPU_TEMPERATURE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgInvrTInvalid_IPU_IsgInvrTInvalid = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgModSts_IPU_IsgModSts)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_IsgModSts_IPU_IsgModSts;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD_RMXR12_IPU_ISGMODSTS_IPU_TRQSPD_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_ComTx_CAN_IPU_IsgModSts_IPU_IsgModSts;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD_FVS55R_IPU_ISGMODSTS_IPU_TRQSPD_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_ComTx_CAN_IPU_IsgModSts_IPU_IsgModSts;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD__XQC0B_IPU_ISGMODSTS_IPU_TRQSPD_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgModSts_IPU_IsgModSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgModStsInvalid_IPU_IsgModStsInvalid)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_IsgModStsInvalid_IPU_IsgModStsInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD_RMXR12_IPU_ISGMODSTSINVALID_IPU_TRQSPD_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_ComTx_CAN_IPU_IsgModStsInvalid_IPU_IsgModStsInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD__XQC0B_IPU_ISGMODSTSINVALID_IPU_TRQSPD_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgModStsInvalid_IPU_IsgModStsInvalid = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgMotT_IPU_IsgMotT)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_IsgMotT_IPU_IsgMotT;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TEMPERATURE_RMXR12_IPU_ISGMOTT_IPU_TEMPERATURE_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_ComTx_CAN_IPU_IsgMotT_IPU_IsgMotT;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TEMPERATURE__XQC0B_IPU_ISGMOTT_IPU_TEMPERATURE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgMotT_IPU_IsgMotT = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgMotTInvalid_IPU_IsgMotTInvalid)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_IsgMotTInvalid_IPU_IsgMotTInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TEMPERATURE_RMXR12_IPU_ISGMOTTINVALID_IPU_TEMPERATURE_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_ComTx_CAN_IPU_IsgMotTInvalid_IPU_IsgMotTInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TEMPERATURE__XQC0B_IPU_ISGMOTTINVALID_IPU_TEMPERATURE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgMotTInvalid_IPU_IsgMotTInvalid = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgOverTemp_IPU_IsgOverTemp)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_IsgOverTemp_IPU_IsgOverTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TEMPERATURE_RMXR12_IPU_ISGOVERTEMP_IPU_TEMPERATURE_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_ComTx_CAN_IPU_IsgOverTemp_IPU_IsgOverTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TEMPERATURE__XQC0B_IPU_ISGOVERTEMP_IPU_TEMPERATURE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgOverTemp_IPU_IsgOverTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn)
    {
        uint16 phydata_0 = (uint16)Rte_ComTx_CAN_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD_RMXR12_IPU_ISGSPDACTSGN_IPU_TRQSPD_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_ComTx_CAN_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD_FVS55R_IPU_ISGSPDACTSGN_IPU_TRQSPD_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint16 phydata_2 = (uint16)Rte_ComTx_CAN_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD__XQC0B_IPU_ISGSPDACTSGN_IPU_TRQSPD_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD_RMXR12_IPU_ISGSPDACTSGNINVALID_IPU_TRQSPD_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_ComTx_CAN_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD_FVS55R_IPU_ISGSPDACTSGNINVALID_IPU_TRQSPD_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_ComTx_CAN_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD__XQC0B_IPU_ISGSPDACTSGNINVALID_IPU_TRQSPD_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct)
    {
        uint16 phydata_0 = (uint16)Rte_ComTx_CAN_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD_RMXR12_IPU_ISGTQACTISGTQACT_IPU_TRQSPD_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_ComTx_CAN_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD_FVS55R_IPU_ISGTQACTISGTQACT_IPU_TRQSPD_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint16 phydata_2 = (uint16)Rte_ComTx_CAN_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD__XQC0B_IPU_ISGTQACTISGTQACT_IPU_TRQSPD_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgTqActIsgTqActInvalid_IPU_IsgTqActIsgTqActInvalid)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_IsgTqActIsgTqActInvalid_IPU_IsgTqActIsgTqActInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD_RMXR12_IPU_ISGTQACTISGTQACTINVALID_IPU_TRQSPD_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_ComTx_CAN_IPU_IsgTqActIsgTqActInvalid_IPU_IsgTqActIsgTqActInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD_FVS55R_IPU_ISGTQACTISGTQACTINVALID_IPU_TRQSPD_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_ComTx_CAN_IPU_IsgTqActIsgTqActInvalid_IPU_IsgTqActIsgTqActInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD__XQC0B_IPU_ISGTQACTISGTQACTINVALID_IPU_TRQSPD_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgTqActIsgTqActInvalid_IPU_IsgTqActIsgTqActInvalid = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_LV_VotagtFault_IPU_LV_VotagtFault)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_LV_VotagtFault_IPU_LV_VotagtFault;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_LV_VOTAGTFAULT_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_LV_VotagtFault_IPU_LV_VotagtFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MCUMemoryFlt_IPU_MCUMemoryFlt)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_MCUMemoryFlt_IPU_MCUMemoryFlt;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_MCUMEMORYFLT_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MCUMemoryFlt_IPU_MCUMemoryFlt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MCUTempHighAlarm_IPU_MCUTempHighAlarm)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_MCUTempHighAlarm_IPU_MCUTempHighAlarm;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_MCUTEMPHIGHALARM_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MCUTempHighAlarm_IPU_MCUTempHighAlarm = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_MCUTEMPHIGHALARM1_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MCUTempHighFault_IPU_MCUTempHighFault)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_MCUTempHighFault_IPU_MCUTempHighFault;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_MCUTEMPHIGHFAULT_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MCUTempHighFault_IPU_MCUTempHighFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MCUTempSensorErr_IPU_MCUTempSensorErr)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_MCUTempSensorErr_IPU_MCUTempSensorErr;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_MCUTEMPSENSORERR_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MCUTempSensorErr_IPU_MCUTempSensorErr = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorFltLevell1_IPU_MotorFltLevell1)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_MotorFltLevell1_IPU_MotorFltLevell1;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_MOTORFLTLEVELL1_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorFltLevell1_IPU_MotorFltLevell1 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorFltLevell_Invalid_IPU_MotorFltLevell_Invalid)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_MotorFltLevell_Invalid_IPU_MotorFltLevell_Invalid;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_MOTORFLTLEVELL_INVALID_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorFltLevell_Invalid_IPU_MotorFltLevell_Invalid = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorLockRotErr_IPU_MotorLockRotErr)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_MotorLockRotErr_IPU_MotorLockRotErr;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_MOTORLOCKROTERR_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorLockRotErr_IPU_MotorLockRotErr = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorNum_IPU_MotorNum)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_MotorNum_IPU_MotorNum;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TEMPERATURE_RMXR12_IPU_MOTORNUM_IPU_TEMPERATURE_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_ComTx_CAN_IPU_MotorNum_IPU_MotorNum;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TEMPERATURE__XQC0B_IPU_MOTORNUM_IPU_TEMPERATURE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorNum_IPU_MotorNum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorNumSN_IPU_MotorNumSN)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_MotorNumSN_IPU_MotorNumSN;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TEMPERATURE_RMXR12_IPU_MOTORNUMSN_IPU_TEMPERATURE_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_ComTx_CAN_IPU_MotorNumSN_IPU_MotorNumSN;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TEMPERATURE__XQC0B_IPU_MOTORNUMSN_IPU_TEMPERATURE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorNumSN_IPU_MotorNumSN = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_MOTOROVERCURRFLT_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_MOTOROVERSPDFLT_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorSpdHighAlarm_IPU_MotorSpdHighAlarm)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_MotorSpdHighAlarm_IPU_MotorSpdHighAlarm;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_MOTORSPDHIGHALARM_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorSpdHighAlarm_IPU_MotorSpdHighAlarm = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorSts_IPU_MotorSts)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_MotorSts_IPU_MotorSts;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD_RMXR12_IPU_MOTORSTS_IPU_TRQSPD_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_ComTx_CAN_IPU_MotorSts_IPU_MotorSts;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD__XQC0B_IPU_MOTORSTS_IPU_TRQSPD_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorSts_IPU_MotorSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorTempHighAlarm_IPU_MotorTempHighAlarm)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_MotorTempHighAlarm_IPU_MotorTempHighAlarm;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_MOTORTEMPHIGHALARM_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorTempHighAlarm_IPU_MotorTempHighAlarm = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorTempHighFault_IPU_MotorTempHighFault)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_MotorTempHighFault_IPU_MotorTempHighFault;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_MOTORTEMPHIGHFAULT_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorTempHighFault_IPU_MotorTempHighFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorTempHighFault1_IPU_MotorTempHighFault1)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_MotorTempHighFault1_IPU_MotorTempHighFault1;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_MOTORTEMPHIGHFAULT1_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorTempHighFault1_IPU_MotorTempHighFault1 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorTempSensorErr_IPU_MotorTempSensorErr)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_MotorTempSensorErr_IPU_MotorTempSensorErr;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_MOTORTEMPSENSORERR_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorTempSensorErr_IPU_MotorTempSensorErr = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorUCurrSensorFlt_IPU_MotorUCurrSensorFlt)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_MotorUCurrSensorFlt_IPU_MotorUCurrSensorFlt;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_MOTORUCURRSENSORFLT_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorUCurrSensorFlt_IPU_MotorUCurrSensorFlt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_Motor_Phase_Curr_IPU_Motor_Phase_Curr)
    {
        uint16 phydata_0 = (uint16)Rte_ComTx_CAN_IPU_Motor_Phase_Curr_IPU_Motor_Phase_Curr;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TEMPERATURE_RMXR12_IPU_MOTOR_PHASE_CURR_IPU_TEMPERATURE_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_Motor_Phase_Curr_IPU_Motor_Phase_Curr = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_PCOCHW_Fault_IPU_PCOCHW_Fault)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_PCOCHW_Fault_IPU_PCOCHW_Fault;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_PCOCHW_FAULT_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_PCOCHW_Fault_IPU_PCOCHW_Fault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_PCOCSW_Fault_IPU_PCOCSW_Fault)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_PCOCSW_Fault_IPU_PCOCSW_Fault;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_PCOCSW_FAULT_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_PCOCSW_Fault_IPU_PCOCSW_Fault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_PreventSlipFlag_IPU_PreventSlipFlag)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_PreventSlipFlag_IPU_PreventSlipFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_STS_RMXR12_IPU_PREVENTSLIPFLAG_IPU_STS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_PreventSlipFlag_IPU_PreventSlipFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_RotateInverterFlt_IPU_RotateInverterFlt)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_RotateInverterFlt_IPU_RotateInverterFlt;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_ROTATEINVERTERFLT_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_RotateInverterFlt_IPU_RotateInverterFlt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_SelfChkSts_IPU_SelfChkSts)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_SelfChkSts_IPU_SelfChkSts;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD_RMXR12_IPU_SELFCHKSTS_IPU_TRQSPD_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_ComTx_CAN_IPU_SelfChkSts_IPU_SelfChkSts;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD__XQC0B_IPU_SELFCHKSTS_IPU_TRQSPD_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_SelfChkSts_IPU_SelfChkSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_SoftwareCapOverVolt_IPU_SoftwareCapOverVolt)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_SoftwareCapOverVolt_IPU_SoftwareCapOverVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_MOTORALARMINFO_RMXR12_IPU_SOFTWARECAPOVERVOLT_IPU_MOTORALARMINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_SoftwareCapOverVolt_IPU_SoftwareCapOverVolt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_Sts_Checksum_IPU_Sts_Checksum)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_Sts_Checksum_IPU_Sts_Checksum;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_STS_RMXR12_IPU_STS_CHECKSUM_IPU_STS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_Sts_Checksum_IPU_Sts_Checksum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax)
    {
        uint16 phydata_0 = (uint16)Rte_ComTx_CAN_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_STS_RMXR12_IPU_TQAVLISGMAX_IPU_STS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_TqAvlIsgMaxInvalid_IPU_TqAvlIsgMaxInvalid)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_TqAvlIsgMaxInvalid_IPU_TqAvlIsgMaxInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_STS_RMXR12_IPU_TQAVLISGMAXINVALID_IPU_STS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_TqAvlIsgMaxInvalid_IPU_TqAvlIsgMaxInvalid = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin)
    {
        uint16 phydata_0 = (uint16)Rte_ComTx_CAN_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_STS_RMXR12_IPU_TQAVLISGMIN_IPU_STS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_TqAvlIsgMinInvalid_IPU_TqAvlIsgMinInvalid)
    {
        boolean phydata_0 = (boolean)Rte_ComTx_CAN_IPU_TqAvlIsgMinInvalid_IPU_TqAvlIsgMinInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_STS_RMXR12_IPU_TQAVLISGMININVALID_IPU_STS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_TqAvlIsgMinInvalid_IPU_TqAvlIsgMinInvalid = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_TrqSpd_CheckSum_IPU_TrqSpd_CheckSum)
    {
        uint8 phydata_0 = (uint8)Rte_ComTx_CAN_IPU_TrqSpd_CheckSum_IPU_TrqSpd_CheckSum;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD_RMXR12_IPU_TRQSPD_CHECKSUM_IPU_TRQSPD_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_ComTx_CAN_IPU_TrqSpd_CheckSum_IPU_TrqSpd_CheckSum;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD_FVS55R_IPU_TRQSPD_CHECKSUM_IPU_TRQSPD_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_ComTx_CAN_IPU_TrqSpd_CheckSum_IPU_TrqSpd_CheckSum;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD__XQC0B_IPU_TRQSPD_CHECKSUM_IPU_TRQSPD_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_TrqSpd_CheckSum_IPU_TrqSpd_CheckSum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_PMS_BswAswRte_PMS_SWCompileDay_PMS_SWCompileDay)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_BswAswRte_PMS_SWCompileDay_PMS_SWCompileDay;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VERINFO__XQC0B_PMS_SWCOMPILEDAY_PMS_VERINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_PMS_BswAswRte_PMS_SWCompileDay_PMS_SWCompileDay = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_PMS_BswAswRte_PMS_SWCompileMonth_PMS_SWCompileMonth)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_BswAswRte_PMS_SWCompileMonth_PMS_SWCompileMonth;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VERINFO__XQC0B_PMS_SWCOMPILEMONTH_PMS_VERINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_PMS_BswAswRte_PMS_SWCompileMonth_PMS_SWCompileMonth = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_PMS_BswAswRte_PMS_SWCompileYear_PMS_SWCompileYear)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_BswAswRte_PMS_SWCompileYear_PMS_SWCompileYear;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VERINFO__XQC0B_PMS_SWCOMPILEYEAR_PMS_VERINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_PMS_BswAswRte_PMS_SWCompileYear_PMS_SWCompileYear = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_BATTERY_PERFORMANCE__XQC0B_BMSH_BATTERY_PERFORMANCE_ALIVEC_BMSH_BATTERY_PERFORMANCE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMSH_CCM_Req_AliveCounter_BMSH_CCM_Req_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_BMSH_CCM_Req_AliveCounter_BMSH_CCM_Req_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ_RMXR12_BMSH_CCM_REQ_ALIVECOUNTER_BMSH_CCM_REQ_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_PMS_RollingCounter_BMSH_CCM_Req_AliveCounter_BMSH_CCM_Req_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ__XQC0B_BMSH_CCM_REQ_ALIVECOUNTER_BMSH_CCM_REQ_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMSH_CCM_Req_AliveCounter_BMSH_CCM_Req_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMSH_SOP_AliveCounter_BMSH_SOP_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_BMSH_SOP_AliveCounter_BMSH_SOP_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP_RMXR12_BMSH_SOP_ALIVECOUNTER_BMSH_SOP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_PMS_RollingCounter_BMSH_SOP_AliveCounter_BMSH_SOP_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP__XQC0B_BMSH_SOP_ALIVECOUNTER_BMSH_SOP_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMSH_SOP_AliveCounter_BMSH_SOP_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMSH_Status_AliveCounter_BMSH_Status_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_BMSH_Status_AliveCounter_BMSH_Status_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_STATUS_ALIVECOUNTER_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMSH_Status_AliveCounter_BMSH_Status_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURR__XQC0B_BMSH_VOLTCURR_ALIVECOUNTER_BMSH_VOLTCURR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURRENT_RMXR12_BMSH_VOLTCURRENT_ALIVECOUNTER_BMSH_VOLTCURRENT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_PMS_RollingCounter_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURRENT__XQC0B_BMSH_VOLTCURRENT_ALIVECOUNTER_BMSH_VOLTCURRENT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMS_ChgInfo_AliveCounter_BMS_ChgInfo_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_BMS_ChgInfo_AliveCounter_BMS_ChgInfo_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO_RMXR12_BMS_CHGINFO_ALIVECOUNTER_BMS_ACCHGCTRLINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_PMS_RollingCounter_BMS_ChgInfo_AliveCounter_BMS_ChgInfo_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO__XQC0B_BMS_CHGINFO_ALIVECOUNTER_BMS_ACCHGCTRLINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMS_ChgInfo_AliveCounter_BMS_ChgInfo_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMS_RelaySampSwich_AliveCounter_BMS_RelaySampSwich_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_BMS_RelaySampSwich_AliveCounter_BMS_RelaySampSwich_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_RELAYSAMPSWICH_LGFZID_BMS_RELAYSAMPSWICH_ALIVECOUNTER_BMS_RELAYSAMPSWICH_N72_HCM__MATRIX_V1_1_DBC_TX, &phydata_0);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMS_RelaySampSwich_AliveCounter_BMS_RelaySampSwich_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_STS_RMXR12_IPU_STS_ALIVECOUNTER_IPU_STS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD_RMXR12_IPU_TRQSPD_ALIVECOUNTER_IPU_TRQSPD_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_PMS_RollingCounter_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD_FVS55R_IPU_TRQSPD_ALIVECOUNTER_IPU_TRQSPD_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_PMS_RollingCounter_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_TRQSPD__XQC0B_IPU_TRQSPD_ALIVECOUNTER_IPU_TRQSPD_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL1_FVS55R_PMS_CSCONTROL1_ALIVECOUNTER_PMS_CSCONTROL1_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_PMS_RollingCounter_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL1__XQC0B_PMS_CSCONTROL1_ALIVECOUNTER_PMS_CSCONTROL1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2_FVS55R_PMS_CSCONTROL2_ALIVECOUNTER_PMS_CSCONTROL2_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_PMS_RollingCounter_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2__XQC0B_PMS_CSCONTROL2_ALIVECOUNTER_PMS_CSCONTROL2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_Command_AliveCounter_PMS_Command_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_PMS_Command_AliveCounter_PMS_Command_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_COMMAND_RMXR12_PMS_COMMAND_ALIVECOUNTER_PMS_COMMAND_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_PMS_RollingCounter_PMS_Command_AliveCounter_PMS_Command_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_COMMAND__XQC0B_PMS_COMMAND_ALIVECOUNTER_PMS_COMMAND_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_Command_AliveCounter_PMS_Command_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_RMXR12_PMS_CTRL_ALIVECOUNTER_PMS_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_PMS_RollingCounter_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_FVS55R_PMS_CTRL_ALIVECOUNTER_PMS_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_PMS_RollingCounter_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL__XQC0B_PMS_CTRL_ALIVECOUNTER_PMS_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_EPS_SystemSts_AliveCounter_PMS_EPS_SystemSts_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_PMS_EPS_SystemSts_AliveCounter_PMS_EPS_SystemSts_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_EPS_SYSTEMSTS_RMXR12_PMS_EPS_SYSTEMSTS_ALIVECOUNTER_PMS_EPS_SYSTEMSTS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_EPS_SystemSts_AliveCounter_PMS_EPS_SystemSts_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL_FVS55R_PMS_ENGCONTROL_ALIVECOUNTER_PMS_ENGCONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_PMS_RollingCounter_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL__XQC0B_PMS_ENGCONTROL_ALIVECOUNTER_PMS_ENGCONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_RMXR12_PMS_MODECONTROL_ALIVECOUNTER_PMS_MODECONTROL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_PMS_RollingCounter_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_FVS55R_PMS_MODECONTROL_ALIVECOUNTER_PMS_MODECONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_PMS_RollingCounter_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL__XQC0B_PMS_MODECONTROL_ALIVECOUNTER_PMS_MODECONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_RelaySampSwich_AliveCounter_PMS_RelaySampSwich_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_PMS_RelaySampSwich_AliveCounter_PMS_RelaySampSwich_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_RELAYSAMPSWICH_LGFZID_PMS_RELAYSAMPSWICH_ALIVECOUNTER_PMS_RELAYSAMPSWICH_N72_HCM__MATRIX_V1_1_DBC_TX, &phydata_0);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_RelaySampSwich_AliveCounter_PMS_RelaySampSwich_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_StsSwap_AliveCounter_PMS_StsSwap_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_PMS_StsSwap_AliveCounter_PMS_StsSwap_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_STSSWAP_RMXR12_PMS_STSSWAP_ALIVECOUNTER_PMS_STSSWAP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_PMS_RollingCounter_PMS_StsSwap_AliveCounter_PMS_StsSwap_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_STSSWAP__XQC0B_PMS_STSSWAP_ALIVECOUNTER_PMS_STSSWAP_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_StsSwap_AliveCounter_PMS_StsSwap_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL_RMXR12_VCU_BMSH_CTRL_ALIVECOUNTER_PMS_BMSH_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_PMS_RollingCounter_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL_FVS55R_VCU_BMSH_CTRL_ALIVECOUNTER_PMS_BMSH_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_PMS_RollingCounter_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL__XQC0B_VCU_BMSH_CTRL_ALIVECOUNTER_PMS_BMSH_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter)
    {
        uint8 phydata_0 = (uint8)Rte_PMS_RollingCounter_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VEHICLEINFO_RMXR12_VCU_VEHICLEINFO_ALIVECOUNTER_PMS_VEHICLEINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_PMS_RollingCounter_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VEHICLEINFO__XQC0B_VCU_VEHICLEINFO_ALIVECOUNTER_PMS_VEHICLEINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_CIL_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq)
    {
        boolean phydata_0 = (boolean)Rte_swc_CIL_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VEHICLEINFO_RMXR12_VCU_BMSH_FAULTRESETREQ_PMS_VEHICLEINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_CIL_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_CIL_CIL_ChargeModeReq_CIL_ChargeModeReq)
    {
        uint8 phydata_0 = (uint8)Rte_swc_CIL_CIL_ChargeModeReq_CIL_ChargeModeReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VEHICLEINFO_RMXR12_VCU_CHARGEMODEREQ_PMS_VEHICLEINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_CIL_CIL_ChargeModeReq_CIL_ChargeModeReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_12VBatFault_BMSH_12VBatFault)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_12VBatFault_BMSH_12VBatFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_12VBATFAULT_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_12VBatFault_BMSH_12VBatFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_AllowBatTempMax_BMSH_AllowBatTempMax)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_AllowBatTempMax_BMSH_AllowBatTempMax;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_BATCFG_RMXR12_BMSH_ALLOWBATTEMPMAX_BMSH_BATCFG_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_AllowBatTempMax_BMSH_AllowBatTempMax = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_AllowBatTempMin_BMSH_AllowBatTempMin)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_AllowBatTempMin_BMSH_AllowBatTempMin;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_BATCFG_RMXR12_BMSH_ALLOWBATTEMPMIN_BMSH_BATCFG_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_AllowBatTempMin_BMSH_AllowBatTempMin = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_AllowCellVoltMax_BMSH_AllowCellVoltMax)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_AllowCellVoltMax_BMSH_AllowCellVoltMax;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_BATCFG_RMXR12_BMSH_ALLOWCELLVOLTMAX_BMSH_BATCFG_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_AllowCellVoltMax_BMSH_AllowCellVoltMax = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_AllowCellVoltMin_BMSH_AllowCellVoltMin)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_AllowCellVoltMin_BMSH_AllowCellVoltMin;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_BATCFG_RMXR12_BMSH_ALLOWCELLVOLTMIN_BMSH_BATCFG_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_AllowCellVoltMin_BMSH_AllowCellVoltMin = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_AllowPackVoltMax_BMSH_AllowPackVoltMax)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_AllowPackVoltMax_BMSH_AllowPackVoltMax;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_BATCFG_RMXR12_BMSH_ALLOWPACKVOLTMAX_BMSH_BATCFG_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_AllowPackVoltMax_BMSH_AllowPackVoltMax = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_AllowPackVoltMin_BMSH_AllowPackVoltMin)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_AllowPackVoltMin_BMSH_AllowPackVoltMin;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_BATCFG_RMXR12_BMSH_ALLOWPACKVOLTMIN_BMSH_BATCFG_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_AllowPackVoltMin_BMSH_AllowPackVoltMin = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatCurrent_BMSH_BatCurrent)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_BatCurrent_BMSH_BatCurrent;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURRENT_RMXR12_BMSH_BATCURRENT_BMSH_VOLTCURRENT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_COL_BMSH_BatCurrent_BMSH_BatCurrent;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOXINFOR_RMXR12_BMSH_BATCURRENT_BMSH_TBOXINFOR_PMS_EV_CAN_20260427_DBC_TX, &phydata_1);
        uint16 phydata_2 = (uint16)Rte_swc_COL_BMSH_BatCurrent_BMSH_BatCurrent;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURRENT__XQC0B_BMSH_BATCURRENT_BMSH_VOLTCURRENT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        uint16 phydata_3 = (uint16)Rte_swc_COL_BMSH_BatCurrent_BMSH_BatCurrent;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOXINFOR__XQC0B_BMSH_BATCURRENT_BMSH_TBOXINFOR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_3);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatCurrent_BMSH_BatCurrent = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURRENT_RMXR12_BMSH_BATCURRENTVALIDFLAG_BMSH_VOLTCURRENT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURRENT__XQC0B_BMSH_BATCURRENTVALIDFLAG_BMSH_VOLTCURRENT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatMaintReqValidFlag_BMSH_BatMaintReqValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_BatMaintReqValidFlag_BMSH_BatMaintReqValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_USEINFO_RMXR12_BMSH_BATMAINTREQVALIDFLAG_BMSH_USEINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_BatMaintReqValidFlag_BMSH_BatMaintReqValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_USEINFO__XQC0B_BMSH_BATMAINTREQVALIDFLAG_BMSH_USEINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatMaintReqValidFlag_BMSH_BatMaintReqValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatMaintenanceReq_BMSH_BatMaintenanceReq)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_BatMaintenanceReq_BMSH_BatMaintenanceReq;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_USEINFO_RMXR12_BMSH_BATMAINTENANCEREQ_BMSH_USEINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_BatMaintenanceReq_BMSH_BatMaintenanceReq;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_USEINFO__XQC0B_BMSH_BATMAINTENANCEREQ_BMSH_USEINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatMaintenanceReq_BMSH_BatMaintenanceReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatOverSOC_BMSH_BatOverSOC)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_BatOverSOC_BMSH_BatOverSOC;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_BATOVERSOC_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatOverSOC_BMSH_BatOverSOC = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatOverVolt_BMSH_BatOverVolt)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_BatOverVolt_BMSH_BatOverVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_BATOVERVOLT_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatOverVolt_BMSH_BatOverVolt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatRealSOC_BMSH_BatRealSOC)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_BatRealSOC_BMSH_BatRealSOC;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOX_RMXR12_BMSH_BATREALSOC_BMSH_SOX_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_COL_BMSH_BatRealSOC_BMSH_BatRealSOC;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STS__XQC0B_BMSH_BATREALSOC_BMSH_STS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatRealSOC_BMSH_BatRealSOC = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatRealSOCValidFlag_BMSH_BatRealSOCValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_BatRealSOCValidFlag_BMSH_BatRealSOCValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOX_RMXR12_BMSH_BATREALSOCVALIDFLAG_BMSH_SOX_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatRealSOCValidFlag_BMSH_BatRealSOCValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatSOE_BMSH_BatSOE)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_BatSOE_BMSH_BatSOE;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOX_RMXR12_BMSH_BATSOE_BMSH_SOX_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatSOE_BMSH_BatSOE = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatSOEValidFlag_BMSH_BatSOEValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_BatSOEValidFlag_BMSH_BatSOEValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOX_RMXR12_BMSH_BATSOEVALIDFLAG_BMSH_SOX_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatSOEValidFlag_BMSH_BatSOEValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatSOH_BMSH_BatSOH)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_BatSOH_BMSH_BatSOH;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOX_RMXR12_BMSH_BATSOH_BMSH_SOX_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatSOH_BMSH_BatSOH = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatSOHValidFlag_BMSH_BatSOHValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_BatSOHValidFlag_BMSH_BatSOHValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOX_RMXR12_BMSH_BATSOHVALIDFLAG_BMSH_SOX_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatSOHValidFlag_BMSH_BatSOHValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatTempMax_BMSH_BatTempMax)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_BatTempMax_BMSH_BatTempMax;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TEMP_RMXR12_BMSH_BATTEMPMAX_BMSH_TEMP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatTempMax_BMSH_BatTempMax = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatTempMin_BMSH_BatTempMin)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_BatTempMin_BMSH_BatTempMin;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TEMP_RMXR12_BMSH_BATTEMPMIN_BMSH_TEMP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatTempMin_BMSH_BatTempMin = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatUnderSOC_BMSH_BatUnderSOC)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_BatUnderSOC_BMSH_BatUnderSOC;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_BATUNDERSOC_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatUnderSOC_BMSH_BatUnderSOC = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatUnderVolt_BMSH_BatUnderVolt)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_BatUnderVolt_BMSH_BatUnderVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_BATUNDERVOLT_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatUnderVolt_BMSH_BatUnderVolt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatUseableSOC_BMSH_BatUseableSOC)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_BatUseableSOC_BMSH_BatUseableSOC;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOX_RMXR12_BMSH_BATUSEABLESOC_BMSH_SOX_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatUseableSOC_BMSH_BatUseableSOC = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatUseableSOCValidFlag_BMSH_BatUseableSOCValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_BatUseableSOCValidFlag_BMSH_BatUseableSOCValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOX_RMXR12_BMSH_BATUSEABLESOCVALIDFLAG_BMSH_SOX_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatUseableSOCValidFlag_BMSH_BatUseableSOCValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BattPackNum_BMSH_BattPackNum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_BattPackNum_BMSH_BattPackNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO2_RMXR12_BMSH_BATTPACKNUM_BMSH_TBOX_INFO2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BattPackNum_BMSH_BattPackNum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BattSysNum_BMSH_BattSysNum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_BattSysNum_BMSH_BattSysNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO2_RMXR12_BMSH_BATTSYSNUM_BMSH_TBOX_INFO2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BattSysNum_BMSH_BattSysNum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BattTempAvg_BMSH_BattTempAvg)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_BattTempAvg_BMSH_BattTempAvg;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOX_RMXR12_BMSH_BATTTEMPAVG_BMSH_SOX_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BattTempAvg_BMSH_BattTempAvg = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BusVolt_BMSH_BusVolt)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_BusVolt_BMSH_BusVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURRENT_RMXR12_BMSH_BUSVOLT_BMSH_VOLTCURRENT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_COL_BMSH_BusVolt_BMSH_BusVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURRENT__XQC0B_BMSH_BUSVOLT_BMSH_VOLTCURRENT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BusVolt_BMSH_BusVolt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BusVoltValidFlag_BMSH_BusVoltValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_BusVoltValidFlag_BMSH_BusVoltValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURRENT_RMXR12_BMSH_BUSVOLTVALIDFLAG_BMSH_VOLTCURRENT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_BusVoltValidFlag_BMSH_BusVoltValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURRENT__XQC0B_BMSH_BUSVOLTVALIDFLAG_BMSH_VOLTCURRENT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BusVoltValidFlag_BMSH_BusVoltValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_InletTargTmpValidFlag_BMSH_CCM_InletTargTmpValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_CCM_InletTargTmpValidFlag_BMSH_CCM_InletTargTmpValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ_RMXR12_BMSH_CCM_INLETTARGTMPVALIDFLAG_BMSH_CCM_REQ_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_CCM_InletTargTmpValidFlag_BMSH_CCM_InletTargTmpValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ__XQC0B_BMSH_CCM_INLETTARGTMPVALIDFLAG_BMSH_CCM_REQ_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_InletTargTmpValidFlag_BMSH_CCM_InletTargTmpValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ_RMXR12_BMSH_CCM_INLETTARGETTEMP_BMSH_CCM_REQ_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ__XQC0B_BMSH_CCM_INLETTARGETTEMP_BMSH_CCM_REQ_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ_RMXR12_BMSH_CCM_LIQUIDINTEMP_BMSH_CCM_REQ_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ__XQC0B_BMSH_CCM_LIQUIDINTEMP_BMSH_CCM_REQ_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_LiquidInTempValidFlag_BMSH_CCM_LiquidInTempValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_CCM_LiquidInTempValidFlag_BMSH_CCM_LiquidInTempValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ_RMXR12_BMSH_CCM_LIQUIDINTEMPVALIDFLAG_BMSH_CCM_REQ_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_CCM_LiquidInTempValidFlag_BMSH_CCM_LiquidInTempValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ__XQC0B_BMSH_CCM_LIQUIDINTEMPVALIDFLAG_BMSH_CCM_REQ_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_LiquidInTempValidFlag_BMSH_CCM_LiquidInTempValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ_RMXR12_BMSH_CCM_LIQUIDOUTTEMP_BMSH_CCM_REQ_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ__XQC0B_BMSH_CCM_LIQUIDOUTTEMP_BMSH_CCM_REQ_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_LiquidOutTmpValidFlag_BMSH_CCM_LiquidOutTmpValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_CCM_LiquidOutTmpValidFlag_BMSH_CCM_LiquidOutTmpValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ_RMXR12_BMSH_CCM_LIQUIDOUTTMPVALIDFLAG_BMSH_CCM_REQ_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_CCM_LiquidOutTmpValidFlag_BMSH_CCM_LiquidOutTmpValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ__XQC0B_BMSH_CCM_LIQUIDOUTTMPVALIDFLAG_BMSH_CCM_REQ_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_LiquidOutTmpValidFlag_BMSH_CCM_LiquidOutTmpValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ_RMXR12_BMSH_CCM_THERMALMANAGEREQ_BMSH_CCM_REQ_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ__XQC0B_BMSH_CCM_THERMALMANAGEREQ_BMSH_CCM_REQ_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_ThrmlMangReqValidFlag_BMSH_CCM_ThrmlMangReqValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_CCM_ThrmlMangReqValidFlag_BMSH_CCM_ThrmlMangReqValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ_RMXR12_BMSH_CCM_THRMLMANGREQVALIDFLAG_BMSH_CCM_REQ_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_CCM_ThrmlMangReqValidFlag_BMSH_CCM_ThrmlMangReqValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ__XQC0B_BMSH_CCM_THRMLMANGREQVALIDFLAG_BMSH_CCM_REQ_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_ThrmlMangReqValidFlag_BMSH_CCM_ThrmlMangReqValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_CELLDIFFVOLTUNIFORM_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellOverVolt_BMSH_CellOverVolt)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_CellOverVolt_BMSH_CellOverVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_CELLOVERVOLT_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellOverVolt_BMSH_CellOverVolt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellTempUniformity_BMSH_CellTempUniformity)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_CellTempUniformity_BMSH_CellTempUniformity;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_CELLTEMPUNIFORMITY_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellTempUniformity_BMSH_CellTempUniformity = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellUnderVolt_BMSH_CellUnderVolt)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_CellUnderVolt_BMSH_CellUnderVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_CELLUNDERVOLT_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellUnderVolt_BMSH_CellUnderVolt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellVoltMax_BMSH_CellVoltMax)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_CellVoltMax_BMSH_CellVoltMax;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CELLVOLTMAXMIN_RMXR12_BMSH_CELLVOLTMAX_BMSH_CELLVOLTMAXMIN_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellVoltMax_BMSH_CellVoltMax = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellVoltMaxModuleID_BMSH_CellVoltMaxModuleID)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_CellVoltMaxModuleID_BMSH_CellVoltMaxModuleID;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CELLVOLTMAXMIN_RMXR12_BMSH_CELLVOLTMAXMODULEID_BMSH_CELLVOLTMAXMIN_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellVoltMaxModuleID_BMSH_CellVoltMaxModuleID = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellVoltMin_BMSH_CellVoltMin)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_CellVoltMin_BMSH_CellVoltMin;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CELLVOLTMAXMIN_RMXR12_BMSH_CELLVOLTMIN_BMSH_CELLVOLTMAXMIN_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellVoltMin_BMSH_CellVoltMin = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellVoltMinModuleID_BMSH_CellVoltMinModuleID)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_CellVoltMinModuleID_BMSH_CellVoltMinModuleID;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CELLVOLTMAXMIN_RMXR12_BMSH_CELLVOLTMINMODULEID_BMSH_CELLVOLTMAXMIN_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellVoltMinModuleID_BMSH_CellVoltMinModuleID = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_CHGOVERCURRENT_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ChgOverTemp_BMSH_ChgOverTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_ChgOverTemp_BMSH_ChgOverTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_CHGOVERTEMP_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ChgOverTemp_BMSH_ChgOverTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ChgUnderTemp_BMSH_ChgUnderTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_ChgUnderTemp_BMSH_ChgUnderTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_CHGUNDERTEMP_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ChgUnderTemp_BMSH_ChgUnderTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ConnectNegOverTemp_BMSH_ConnectNegOverTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_ConnectNegOverTemp_BMSH_ConnectNegOverTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_CONNECTNEGOVERTEMP_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ConnectNegOverTemp_BMSH_ConnectNegOverTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ConnectPosOverTemp_BMSH_ConnectPosOverTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_ConnectPosOverTemp_BMSH_ConnectPosOverTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_CONNECTPOSOVERTEMP_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ConnectPosOverTemp_BMSH_ConnectPosOverTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CoolType_BMSH_CoolType)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_CoolType_BMSH_CoolType;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ_RMXR12_BMSH_COOLTYPE_BMSH_CCM_REQ_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_CoolType_BMSH_CoolType;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ__XQC0B_BMSH_COOLTYPE_BMSH_CCM_REQ_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CoolType_BMSH_CoolType = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CoolTypeValidFlag_BMSH_CoolTypeValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_CoolTypeValidFlag_BMSH_CoolTypeValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ_RMXR12_BMSH_COOLTYPEVALIDFLAG_BMSH_CCM_REQ_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_CoolTypeValidFlag_BMSH_CoolTypeValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ__XQC0B_BMSH_COOLTYPEVALIDFLAG_BMSH_CCM_REQ_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CoolTypeValidFlag_BMSH_CoolTypeValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChargeProcess_BMSH_DCChargeProcess)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_DCChargeProcess_BMSH_DCChargeProcess;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO_RMXR12_BMSH_DCCHARGEPROCESS_BMSH_STSCHGINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_DCChargeProcess_BMSH_DCChargeProcess;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO__XQC0B_BMSH_DCCHARGEPROCESS_BMSH_STSCHGINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChargeProcess_BMSH_DCChargeProcess = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgCurReq_BMSH_DCChgCurReq)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_DCChgCurReq_BMSH_DCChgCurReq;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO_RMXR12_BMSH_DCCHGCURREQ_BMSH_STSCHGINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_DCChgCurReq_BMSH_DCChgCurReq;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO__XQC0B_BMSH_DCCHGCURREQ_BMSH_STSCHGINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgCurReq_BMSH_DCChgCurReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO_RMXR12_BMSH_DCCHGCURREQRANGEUP_BMSH_STSCHGINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO__XQC0B_BMSH_DCCHGCURREQRANGEUP_BMSH_STSCHGINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgEnder_BMSH_DCChgEnder)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_DCChgEnder_BMSH_DCChgEnder;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO_RMXR12_BMSH_DCCHGENDER_BMSH_STSCHGINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_DCChgEnder_BMSH_DCChgEnder;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO__XQC0B_BMSH_DCCHGENDER_BMSH_STSCHGINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgEnder_BMSH_DCChgEnder = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOX_RMXR12_BMSH_DCCHGNEGRELAYFAULT_BMSH_SOX_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_DCCHGPLUGNOVERTEMP_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_DCCHGPLUGPOVERTEMP_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgPosRelayFault_BMSH_DCChgPosRelayFault)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_DCChgPosRelayFault_BMSH_DCChgPosRelayFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOX_RMXR12_BMSH_DCCHGPOSRELAYFAULT_BMSH_SOX_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgPosRelayFault_BMSH_DCChgPosRelayFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgRelayFault_BMSH_DCChgRelayFault)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_DCChgRelayFault_BMSH_DCChgRelayFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_DCCHGRELAYFAULT_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_DCChgRelayFault_BMSH_DCChgRelayFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT__XQC0B_BMSH_DCCHGRELAYFAULT_BMSH_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgRelayFault_BMSH_DCChgRelayFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CCS_BMSH_DCChgRx_OTime_CCS)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_DCChgRx_OTime_CCS_BMSH_DCChgRx_OTime_CCS;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_DCCHGRX_OTIME_CCS_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CCS_BMSH_DCChgRx_OTime_CCS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CML_BMSH_DCChgRx_OTime_CML)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_DCChgRx_OTime_CML_BMSH_DCChgRx_OTime_CML;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_DCCHGRX_OTIME_CML_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CML_BMSH_DCChgRx_OTime_CML = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CRM00_BMSH_DCChgRx_OTime_CRM00)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_DCChgRx_OTime_CRM00_BMSH_DCChgRx_OTime_CRM00;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_DCCHGRX_OTIME_CRM00_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CRM00_BMSH_DCChgRx_OTime_CRM00 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CRMAA_BMSH_DCChgRx_OTime_CRMAA)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_DCChgRx_OTime_CRMAA_BMSH_DCChgRx_OTime_CRMAA;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_DCCHGRX_OTIME_CRMAA_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CRMAA_BMSH_DCChgRx_OTime_CRMAA = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CSD_BMSH_DCChgRx_OTime_CSD)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_DCChgRx_OTime_CSD_BMSH_DCChgRx_OTime_CSD;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_DCCHGRX_OTIME_CSD_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CSD_BMSH_DCChgRx_OTime_CSD = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgStandVer_BMSH_DCChgStandVer)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_DCChgStandVer_BMSH_DCChgStandVer;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO_RMXR12_BMSH_DCCHGSTANDVER_BMSH_STSCHGINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_DCChgStandVer_BMSH_DCChgStandVer;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO__XQC0B_BMSH_DCCHGSTANDVER_BMSH_STSCHGINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgStandVer_BMSH_DCChgStandVer = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgVoltAllow_BMSH_DCChgVoltAllow)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_DCChgVoltAllow_BMSH_DCChgVoltAllow;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO_RMXR12_BMSH_DCCHGVOLTALLOW_BMSH_STSCHGINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_COL_BMSH_DCChgVoltAllow_BMSH_DCChgVoltAllow;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO__XQC0B_BMSH_DCCHGVOLTALLOW_BMSH_STSCHGINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgVoltAllow_BMSH_DCChgVoltAllow = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgVoltAllowValidFlag_BMSH_DCChgVoltAllowValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_DCChgVoltAllowValidFlag_BMSH_DCChgVoltAllowValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO_RMXR12_BMSH_DCCHGVOLTALLOWVALIDFLAG_BMSH_STSCHGINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_DCChgVoltAllowValidFlag_BMSH_DCChgVoltAllowValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO__XQC0B_BMSH_DCCHGVOLTALLOWVALIDFLAG_BMSH_STSCHGINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgVoltAllowValidFlag_BMSH_DCChgVoltAllowValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCEquipment_DisplayCur_BMSH_DCEquipment_DisplayCur)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_DCEquipment_DisplayCur_BMSH_DCEquipment_DisplayCur;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO_RMXR12_BMSH_DCEQUIPMENT_DISPLAYCUR_BMSH_STSCHGINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_DCEquipment_DisplayCur_BMSH_DCEquipment_DisplayCur;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO__XQC0B_BMSH_DCEQUIPMENT_DISPLAYCUR_BMSH_STSCHGINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCEquipment_DisplayCur_BMSH_DCEquipment_DisplayCur = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCEquipment_DisplayVolt_BMSH_DCEquipment_DisplayVolt)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_DCEquipment_DisplayVolt_BMSH_DCEquipment_DisplayVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO_RMXR12_BMSH_DCEQUIPMENT_DISPLAYVOLT_BMSH_STSCHGINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_COL_BMSH_DCEquipment_DisplayVolt_BMSH_DCEquipment_DisplayVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO__XQC0B_BMSH_DCEQUIPMENT_DISPLAYVOLT_BMSH_STSCHGINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCEquipment_DisplayVolt_BMSH_DCEquipment_DisplayVolt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DC_DisplayCurRangeUP_BMSH_DC_DisplayCurRangeUP)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_DC_DisplayCurRangeUP_BMSH_DC_DisplayCurRangeUP;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO_RMXR12_BMSH_DC_DISPLAYCURRANGEUP_BMSH_STSCHGINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_DC_DisplayCurRangeUP_BMSH_DC_DisplayCurRangeUP;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO__XQC0B_BMSH_DC_DISPLAYCURRANGEUP_BMSH_STSCHGINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DC_DisplayCurRangeUP_BMSH_DC_DisplayCurRangeUP = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DC_DisplayVoltValidFlag_BMSH_DC_DisplayVoltValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_DC_DisplayVoltValidFlag_BMSH_DC_DisplayVoltValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO_RMXR12_BMSH_DC_DISPLAYVOLTVALIDFLAG_BMSH_STSCHGINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_DC_DisplayVoltValidFlag_BMSH_DC_DisplayVoltValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO__XQC0B_BMSH_DC_DISPLAYVOLTVALIDFLAG_BMSH_STSCHGINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DC_DisplayVoltValidFlag_BMSH_DC_DisplayVoltValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DataStorageFault_BMSH_DataStorageFault)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_DataStorageFault_BMSH_DataStorageFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_DATASTORAGEFAULT_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DataStorageFault_BMSH_DataStorageFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DisChgOverCurrent_BMSH_DisChgOverCurrent)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_DisChgOverCurrent_BMSH_DisChgOverCurrent;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_DISCHGOVERCURRENT_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_DisChgOverCurrent_BMSH_DisChgOverCurrent;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT__XQC0B_BMSH_DISCHGOVERCURRENT_BMSH_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DisChgOverCurrent_BMSH_DisChgOverCurrent = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DisChgOverTemp_BMSH_DisChgOverTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_DisChgOverTemp_BMSH_DisChgOverTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_DISCHGOVERTEMP_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DisChgOverTemp_BMSH_DisChgOverTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DisChgUnderTemp_BMSH_DisChgUnderTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_DisChgUnderTemp_BMSH_DisChgUnderTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_DISCHGUNDERTEMP_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DisChgUnderTemp_BMSH_DisChgUnderTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_EVCANComFault_BMSH_EVCANComFault)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_EVCANComFault_BMSH_EVCANComFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_EVCANCOMFAULT_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_EVCANComFault_BMSH_EVCANComFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_EnergyOut_BMSH_EnergyOut)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_EnergyOut_BMSH_EnergyOut;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PWROUT_RMXR12_BMSH_ENERGYOUT_BMSH_PWROUT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_EnergyOut_BMSH_EnergyOut = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_EnergyOutValidFlag_BMSH_EnergyOutValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_EnergyOutValidFlag_BMSH_EnergyOutValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PWROUT_RMXR12_BMSH_ENERGYOUTVALIDFLAG_BMSH_PWROUT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_EnergyOutValidFlag_BMSH_EnergyOutValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ExChgNumOfTimes_BMSH_ExChgNumOfTimes)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_ExChgNumOfTimes_BMSH_ExChgNumOfTimes;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_USEINFO_RMXR12_BMSH_EXCHGNUMOFTIMES_BMSH_USEINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_COL_BMSH_ExChgNumOfTimes_BMSH_ExChgNumOfTimes;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_USEINFO__XQC0B_BMSH_EXCHGNUMOFTIMES_BMSH_USEINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ExChgNumOfTimes_BMSH_ExChgNumOfTimes = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ExChgNumOfTimesValidFlag_BMSH_ExChgNumOfTimesValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_ExChgNumOfTimesValidFlag_BMSH_ExChgNumOfTimesValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_USEINFO_RMXR12_BMSH_EXCHGNUMOFTIMESVALIDFLAG_BMSH_USEINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_ExChgNumOfTimesValidFlag_BMSH_ExChgNumOfTimesValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_USEINFO__XQC0B_BMSH_EXCHGNUMOFTIMESVALIDFLAG_BMSH_USEINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ExChgNumOfTimesValidFlag_BMSH_ExChgNumOfTimesValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FastChgComFault_BMSH_FastChgComFault)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_FastChgComFault_BMSH_FastChgComFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_FASTCHGCOMFAULT_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FastChgComFault_BMSH_FastChgComFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FaultCode_BMSH_FaultCode)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_FaultCode_BMSH_FaultCode;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_FAULTCODE_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_FaultCode_BMSH_FaultCode;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT__XQC0B_BMSH_FAULTCODE_BMSH_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FaultCode_BMSH_FaultCode = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FinishChgTime_BMSH_FinishChgTime)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_FinishChgTime_BMSH_FinishChgTime;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO_RMXR12_BMSH_FINISHCHGTIME_BMSH_STSCHGINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_COL_BMSH_FinishChgTime_BMSH_FinishChgTime;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO__XQC0B_BMSH_FINISHCHGTIME_BMSH_STSCHGINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FinishChgTime_BMSH_FinishChgTime = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FinishChgTimeValidFlag_BMSH_FinishChgTimeValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_FinishChgTimeValidFlag_BMSH_FinishChgTimeValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO_RMXR12_BMSH_FINISHCHGTIMEVALIDFLAG_BMSH_STSCHGINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_FinishChgTimeValidFlag_BMSH_FinishChgTimeValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STSCHGINFO__XQC0B_BMSH_FINISHCHGTIMEVALIDFLAG_BMSH_STSCHGINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FinishChgTimeValidFlag_BMSH_FinishChgTimeValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FireAlarm_BMSH_FireAlarm)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_FireAlarm_BMSH_FireAlarm;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_FIREALARM_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FireAlarm_BMSH_FireAlarm = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FlowRateReq_BMSH_FlowRateReq)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_FlowRateReq_BMSH_FlowRateReq;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ_RMXR12_BMSH_FLOWRATEREQ_BMSH_CCM_REQ_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_FlowRateReq_BMSH_FlowRateReq;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ__XQC0B_BMSH_FLOWRATEREQ_BMSH_CCM_REQ_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FlowRateReq_BMSH_FlowRateReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FlowRateReqValidFlag_BMSH_FlowRateReqValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_FlowRateReqValidFlag_BMSH_FlowRateReqValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ_RMXR12_BMSH_FLOWRATEREQVALIDFLAG_BMSH_CCM_REQ_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_FlowRateReqValidFlag_BMSH_FlowRateReqValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ__XQC0B_BMSH_FLOWRATEREQVALIDFLAG_BMSH_CCM_REQ_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FlowRateReqValidFlag_BMSH_FlowRateReqValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_IntComFault_BMSH_IntComFault)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_IntComFault_BMSH_IntComFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_INTCOMFAULT_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_IntComFault_BMSH_IntComFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_MainNegRelayFault_BMSH_MainNegRelayFault)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_MainNegRelayFault_BMSH_MainNegRelayFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_MAINNEGRELAYFAULT_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_MainNegRelayFault_BMSH_MainNegRelayFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT__XQC0B_BMSH_MAINNEGRELAYFAULT_BMSH_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_MainNegRelayFault_BMSH_MainNegRelayFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_MainPosRelayFault_BMSH_MainPosRelayFault)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_MainPosRelayFault_BMSH_MainPosRelayFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_MAINPOSRELAYFAULT_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_MainPosRelayFault_BMSH_MainPosRelayFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT__XQC0B_BMSH_MAINPOSRELAYFAULT_BMSH_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_MainPosRelayFault_BMSH_MainPosRelayFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode1_BMSH_PackCode1)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_PackCode1_BMSH_PackCode1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE_RMXR12_BMSH_PACKCODE1_BMSH_PACKCODE_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_PackCode1_BMSH_PackCode1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE__XQC0B_BMSH_PACKCODE1_BMSH_PACKCODE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_COL_BMSH_PackCode1_BMSH_PackCode1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE1__XQC0B_BMSH_PACKCODE1_BMSH_PACKCODE1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode1_BMSH_PackCode1 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode1_1_BMSH_PackCode1_1)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_PackCode1_1_BMSH_PackCode1_1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE1_RMXR12_BMSH_PACKCODE1_1_BMSH_PACKCODE1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode1_1_BMSH_PackCode1_1 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode2_BMSH_PackCode2)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_PackCode2_BMSH_PackCode2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE_RMXR12_BMSH_PACKCODE2_BMSH_PACKCODE_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_PackCode2_BMSH_PackCode2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE__XQC0B_BMSH_PACKCODE2_BMSH_PACKCODE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_COL_BMSH_PackCode2_BMSH_PackCode2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE1__XQC0B_BMSH_PACKCODE2_BMSH_PACKCODE1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode2_BMSH_PackCode2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode2_1_BMSH_PackCode2_1)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_PackCode2_1_BMSH_PackCode2_1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE1_RMXR12_BMSH_PACKCODE2_1_BMSH_PACKCODE1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode2_1_BMSH_PackCode2_1 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode3_BMSH_PackCode3)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_PackCode3_BMSH_PackCode3;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE_RMXR12_BMSH_PACKCODE3_BMSH_PACKCODE_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_PackCode3_BMSH_PackCode3;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE__XQC0B_BMSH_PACKCODE3_BMSH_PACKCODE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_COL_BMSH_PackCode3_BMSH_PackCode3;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE1__XQC0B_BMSH_PACKCODE3_BMSH_PACKCODE1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode3_BMSH_PackCode3 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode3_1_BMSH_PackCode3_1)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_PackCode3_1_BMSH_PackCode3_1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE1_RMXR12_BMSH_PACKCODE3_1_BMSH_PACKCODE1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode3_1_BMSH_PackCode3_1 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode4_BMSH_PackCode4)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_PackCode4_BMSH_PackCode4;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE_RMXR12_BMSH_PACKCODE4_BMSH_PACKCODE_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_PackCode4_BMSH_PackCode4;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE__XQC0B_BMSH_PACKCODE4_BMSH_PACKCODE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_COL_BMSH_PackCode4_BMSH_PackCode4;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE1__XQC0B_BMSH_PACKCODE4_BMSH_PACKCODE1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode4_BMSH_PackCode4 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode4_1_BMSH_PackCode4_1)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_PackCode4_1_BMSH_PackCode4_1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE1_RMXR12_BMSH_PACKCODE4_1_BMSH_PACKCODE1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode4_1_BMSH_PackCode4_1 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode5_BMSH_PackCode5)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_PackCode5_BMSH_PackCode5;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE_RMXR12_BMSH_PACKCODE5_BMSH_PACKCODE_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_PackCode5_BMSH_PackCode5;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE__XQC0B_BMSH_PACKCODE5_BMSH_PACKCODE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_COL_BMSH_PackCode5_BMSH_PackCode5;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE1__XQC0B_BMSH_PACKCODE5_BMSH_PACKCODE1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode5_BMSH_PackCode5 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode5_1_BMSH_PackCode5_1)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_PackCode5_1_BMSH_PackCode5_1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE1_RMXR12_BMSH_PACKCODE5_1_BMSH_PACKCODE1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode5_1_BMSH_PackCode5_1 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode6_BMSH_PackCode6)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_PackCode6_BMSH_PackCode6;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE_RMXR12_BMSH_PACKCODE6_BMSH_PACKCODE_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_PackCode6_BMSH_PackCode6;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE__XQC0B_BMSH_PACKCODE6_BMSH_PACKCODE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode6_BMSH_PackCode6 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode7_BMSH_PackCode7)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_PackCode7_BMSH_PackCode7;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE_RMXR12_BMSH_PACKCODE7_BMSH_PACKCODE_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_PackCode7_BMSH_PackCode7;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE__XQC0B_BMSH_PACKCODE7_BMSH_PACKCODE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode7_BMSH_PackCode7 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode_ID_BMSH_PackCode_ID)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_PackCode_ID_BMSH_PackCode_ID;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE_RMXR12_BMSH_PACKCODE_ID_BMSH_PACKCODE_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_PackCode_ID_BMSH_PackCode_ID;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE__XQC0B_BMSH_PACKCODE_ID_BMSH_PACKCODE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode_ID_BMSH_PackCode_ID = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackExtendCd_BMSH_PackExtendCd)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_PackExtendCd_BMSH_PackExtendCd;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_PACKEXTENDCD_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackExtendCd_BMSH_PackExtendCd = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackType_BMSH_PackType)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_PackType_BMSH_PackType;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_PACKTYPE_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackType_BMSH_PackType = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackVolt_BMSH_PackVolt)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_PackVolt_BMSH_PackVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURRENT_RMXR12_BMSH_PACKVOLT_BMSH_VOLTCURRENT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_COL_BMSH_PackVolt_BMSH_PackVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOXINFOR_RMXR12_BMSH_PACKVOLT_BMSH_TBOXINFOR_PMS_EV_CAN_20260427_DBC_TX, &phydata_1);
        uint16 phydata_2 = (uint16)Rte_swc_COL_BMSH_PackVolt_BMSH_PackVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURRENT__XQC0B_BMSH_PACKVOLT_BMSH_VOLTCURRENT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        uint16 phydata_3 = (uint16)Rte_swc_COL_BMSH_PackVolt_BMSH_PackVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOXINFOR__XQC0B_BMSH_PACKVOLT_BMSH_TBOXINFOR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_3);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackVolt_BMSH_PackVolt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURRENT_RMXR12_BMSH_PACKVOLTVALIDFLAG_BMSH_VOLTCURRENT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURRENT__XQC0B_BMSH_PACKVOLTVALIDFLAG_BMSH_VOLTCURRENT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_RecoveryOverCurrent_BMSH_RecoveryOverCurrent)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_RecoveryOverCurrent_BMSH_RecoveryOverCurrent;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_RECOVERYOVERCURRENT_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_RecoveryOverCurrent_BMSH_RecoveryOverCurrent = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_SelfCheckFault_BMSH_SelfCheckFault)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_SelfCheckFault_BMSH_SelfCheckFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_SELFCHECKFAULT_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_SelfCheckFault_BMSH_SelfCheckFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsA_plus_BMSH_StsA_plus)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_StsA_plus_BMSH_StsA_plus;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_STSA_PLUS_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsA_plus_BMSH_StsA_plus = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsCC2_BMSH_StsCC2)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_StsCC2_BMSH_StsCC2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_STSCC2_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsCC2_BMSH_StsCC2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsCellBalance_BMSH_StsCellBalance)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_StsCellBalance_BMSH_StsCellBalance;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_STSCELLBALANCE_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsCellBalance_BMSH_StsCellBalance = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsChgFault_BMSH_StsChgFault)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_StsChgFault_BMSH_StsChgFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_STSCHGFAULT_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsChgFault_BMSH_StsChgFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsDischgFault_BMSH_StsDischgFault)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_StsDischgFault_BMSH_StsDischgFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_STSDISCHGFAULT_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsDischgFault_BMSH_StsDischgFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsInsulation_BMSH_StsInsulation)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_StsInsulation_BMSH_StsInsulation;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_STSINSULATION_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsInsulation_BMSH_StsInsulation = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_STSMAINNEGTIVERELAY_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_STSMAINPOSITIVERELAY_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsMode_BMSH_StsMode)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_StsMode_BMSH_StsMode;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_STSMODE_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsMode_BMSH_StsMode = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsPrecharge_BMSH_StsPrecharge)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_StsPrecharge_BMSH_StsPrecharge;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_STSPRECHARGE_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsPrecharge_BMSH_StsPrecharge = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsWakeUp_BMSH_StsWakeUp)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_StsWakeUp_BMSH_StsWakeUp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_STSWAKEUP_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsWakeUp_BMSH_StsWakeUp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_SubtotalExChgSOE_BMSH_SubtotalExChgSOE)
    {
        uint32 phydata_0 = (uint32)Rte_swc_COL_BMSH_SubtotalExChgSOE_BMSH_SubtotalExChgSOE;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CHGENERGY_RMXR12_BMSH_SUBTOTALEXCHGSOE_BMSH_CHGENERGY_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_SubtotalExChgSOE_BMSH_SubtotalExChgSOE = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_SubtotalRecoveryEng_BMSH_SubtotalRecoveryEng)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_SubtotalRecoveryEng_BMSH_SubtotalRecoveryEng;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_RECOVERYENGINFO_RMXR12_BMSH_SUBTOTALRECOVERYENG_BMSH_RECOVERYENGINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_COL_BMSH_SubtotalRecoveryEng_BMSH_SubtotalRecoveryEng;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_RECOVERYENGINFO__XQC0B_BMSH_SUBTOTALRECOVERYENG_BMSH_RECOVERYENGINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_SubtotalRecoveryEng_BMSH_SubtotalRecoveryEng = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_SupplyVolt_BMSH_SupplyVolt)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_SupplyVolt_BMSH_SupplyVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_ODOMETERINFO_RMXR12_BMSH_SUPPLYVOLT_BMSH_ODOMETERINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_SupplyVolt_BMSH_SupplyVolt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_SwapCntOverTemp_BMSH_SwapCntOverTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_SwapCntOverTemp_BMSH_SwapCntOverTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_SWAPCNTOVERTEMP_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_SwapCntOverTemp_BMSH_SwapCntOverTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatFaultList_BMSH_TBOX_BatFaultList)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_TBOX_BatFaultList_BMSH_TBOX_BatFaultList;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_TBOX_BATFAULTLIST_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatFaultList_BMSH_TBOX_BatFaultList = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatHVILFault_BMSH_TBOX_BatHVILFault)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_TBOX_BatHVILFault_BMSH_TBOX_BatHVILFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_TBOX_BATHVILFAULT_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatHVILFault_BMSH_TBOX_BatHVILFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatIsoAlarm_BMSH_TBOX_BatIsoAlarm)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_TBOX_BatIsoAlarm_BMSH_TBOX_BatIsoAlarm;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_TBOX_BATISOALARM_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatIsoAlarm_BMSH_TBOX_BatIsoAlarm = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT2_RMXR12_BMSH_TBOX_BATISOALARM2_BMSH_TBOX_FAULT2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatLowSOC_BMSH_TBOX_BatLowSOC)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_TBOX_BatLowSOC_BMSH_TBOX_BatLowSOC;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_TBOX_BATLOWSOC_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatLowSOC_BMSH_TBOX_BatLowSOC = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT2_RMXR12_BMSH_TBOX_BATLOWSOC2_BMSH_TBOX_FAULT2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatLowTemp_BMSH_TBOX_BatLowTemp)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_TBOX_BatLowTemp_BMSH_TBOX_BatLowTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_TBOX_BATLOWTEMP_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_TBOX_BatLowTemp_BMSH_TBOX_BatLowTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT__XQC0B_BMSH_TBOX_BATLOWTEMP_BMSH_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatLowTemp_BMSH_TBOX_BatLowTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatModuleSum_BMSH_TBOX_BatModuleSum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_BatModuleSum_BMSH_TBOX_BatModuleSum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO2_RMXR12_BMSH_TBOX_BATMODULESUM_BMSH_TBOX_INFO2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatModuleSum_BMSH_TBOX_BatModuleSum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverCharge_BMSH_TBOX_BatOverCharge)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_TBOX_BatOverCharge_BMSH_TBOX_BatOverCharge;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_TBOX_BATOVERCHARGE_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverCharge_BMSH_TBOX_BatOverCharge = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT2_RMXR12_BMSH_TBOX_BATOVERCHARGE2_BMSH_TBOX_FAULT2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverSOC_BMSH_TBOX_BatOverSOC)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_TBOX_BatOverSOC_BMSH_TBOX_BatOverSOC;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_TBOX_BATOVERSOC_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverSOC_BMSH_TBOX_BatOverSOC = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT2_RMXR12_BMSH_TBOX_BATOVERSOC2_BMSH_TBOX_FAULT2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverTemp_BMSH_TBOX_BatOverTemp)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_TBOX_BatOverTemp_BMSH_TBOX_BatOverTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_TBOX_BATOVERTEMP_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverTemp_BMSH_TBOX_BatOverTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT2_RMXR12_BMSH_TBOX_BATOVERTEMP2_BMSH_TBOX_FAULT2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverVoltage_BMSH_TBOX_BatOverVoltage)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_TBOX_BatOverVoltage_BMSH_TBOX_BatOverVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_TBOX_BATOVERVOLTAGE_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverVoltage_BMSH_TBOX_BatOverVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT2_RMXR12_BMSH_TBOX_BATOVERVOLTAGE2_BMSH_TBOX_FAULT2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatProductDay_BMSH_TBOX_BatProductDay)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_BatProductDay_BMSH_TBOX_BatProductDay;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO1_RMXR12_BMSH_TBOX_BATPRODUCTDAY_BMSH_TBOX_INFO1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_TBOX_BatProductDay_BMSH_TBOX_BatProductDay;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO1__XQC0B_BMSH_TBOX_BATPRODUCTDAY_BMSH_TBOX_INFO1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatProductDay_BMSH_TBOX_BatProductDay = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatProductMonth_BMSH_TBOX_BatProductMonth)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_BatProductMonth_BMSH_TBOX_BatProductMonth;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO1_RMXR12_BMSH_TBOX_BATPRODUCTMONTH_BMSH_TBOX_INFO1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_TBOX_BatProductMonth_BMSH_TBOX_BatProductMonth;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO1__XQC0B_BMSH_TBOX_BATPRODUCTMONTH_BMSH_TBOX_INFO1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatProductMonth_BMSH_TBOX_BatProductMonth = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatProductYear_BMSH_TBOX_BatProductYear)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_BatProductYear_BMSH_TBOX_BatProductYear;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO1_RMXR12_BMSH_TBOX_BATPRODUCTYEAR_BMSH_TBOX_INFO1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_TBOX_BatProductYear_BMSH_TBOX_BatProductYear;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO1__XQC0B_BMSH_TBOX_BATPRODUCTYEAR_BMSH_TBOX_INFO1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatProductYear_BMSH_TBOX_BatProductYear = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatRatedEnergy_BMSH_TBOX_BatRatedEnergy)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_TBOX_BatRatedEnergy_BMSH_TBOX_BatRatedEnergy;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO1_RMXR12_BMSH_TBOX_BATRATEDENERGY_BMSH_TBOX_INFO1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_COL_BMSH_TBOX_BatRatedEnergy_BMSH_TBOX_BatRatedEnergy;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO1__XQC0B_BMSH_TBOX_BATRATEDENERGY_BMSH_TBOX_INFO1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatRatedEnergy_BMSH_TBOX_BatRatedEnergy = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatRatedVolt_BMSH_TBOX_BatRatedVolt)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_TBOX_BatRatedVolt_BMSH_TBOX_BatRatedVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO1_RMXR12_BMSH_TBOX_BATRATEDVOLT_BMSH_TBOX_INFO1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_COL_BMSH_TBOX_BatRatedVolt_BMSH_TBOX_BatRatedVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO1__XQC0B_BMSH_TBOX_BATRATEDVOLT_BMSH_TBOX_INFO1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatRatedVolt_BMSH_TBOX_BatRatedVolt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatSeriesCellsSum_BMSH_TBOX_BatSeriesCellsSum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_BatSeriesCellsSum_BMSH_TBOX_BatSeriesCellsSum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO2_RMXR12_BMSH_TBOX_BATSERIESCELLSSUM_BMSH_TBOX_INFO2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatSeriesCellsSum_BMSH_TBOX_BatSeriesCellsSum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatStoreSysFault_BMSH_TBOX_BatStoreSysFault)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_TBOX_BatStoreSysFault_BMSH_TBOX_BatStoreSysFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_TBOX_BATSTORESYSFAULT_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_TBOX_BatStoreSysFault_BMSH_TBOX_BatStoreSysFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT__XQC0B_BMSH_TBOX_BATSTORESYSFAULT_BMSH_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatStoreSysFault_BMSH_TBOX_BatStoreSysFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO2_RMXR12_BMSH_TBOX_BATTEMPSUM_BMSH_TBOX_INFO2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatTempUniformity_BMSH_TBOX_BatTempUniformity)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_TBOX_BatTempUniformity_BMSH_TBOX_BatTempUniformity;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_TBOX_BATTEMPUNIFORMITY_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatTempUniformity_BMSH_TBOX_BatTempUniformity = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT2_RMXR12_BMSH_TBOX_BATTEMPUNIFORMITY2_BMSH_TBOX_FAULT2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatType_BMSH_TBOX_BatType)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_BatType_BMSH_TBOX_BatType;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO3_RMXR12_BMSH_TBOX_BATTYPE_BMSH_TBOX_INFO3_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_TBOX_BatType_BMSH_TBOX_BatType;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO3__XQC0B_BMSH_TBOX_BATTYPE_BMSH_TBOX_INFO3_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatType_BMSH_TBOX_BatType = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatUnderVoltage_BMSH_TBOX_BatUnderVoltage)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_TBOX_BatUnderVoltage_BMSH_TBOX_BatUnderVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_TBOX_BATUNDERVOLTAGE_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatUnderVoltage_BMSH_TBOX_BatUnderVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT2_RMXR12_BMSH_TBOX_BATUNDERVOLTAGE2_BMSH_TBOX_FAULT2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatUniformity_BMSH_TBOX_BatUniformity)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_TBOX_BatUniformity_BMSH_TBOX_BatUniformity;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_TBOX_BATUNIFORMITY_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatUniformity_BMSH_TBOX_BatUniformity = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT2_RMXR12_BMSH_TBOX_BATUNIFORMITY2_BMSH_TBOX_FAULT2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLVOLT_RMXR12_BMSH_TBOX_CELLA_ID_BMSH_TBOX_CELLVOLT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLVOLT_RMXR12_BMSH_TBOX_CELLA_VOLT_BMSH_TBOX_CELLVOLT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLVOLT_RMXR12_BMSH_TBOX_CELLB_VOLT_BMSH_TBOX_CELLVOLT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLVOLT_RMXR12_BMSH_TBOX_CELLC_ID_BMSH_TBOX_CELLVOLT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLVOLT_RMXR12_BMSH_TBOX_CELLC_VOLT_BMSH_TBOX_CELLVOLT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellOverVoltage_BMSH_TBOX_CellOverVoltage)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_TBOX_CellOverVoltage_BMSH_TBOX_CellOverVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_TBOX_CELLOVERVOLTAGE_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellOverVoltage_BMSH_TBOX_CellOverVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT2_RMXR12_BMSH_TBOX_CELLOVERVOLTAGE2_BMSH_TBOX_FAULT2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellRatedVolt_BMSH_TBOX_CellRatedVolt)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_TBOX_CellRatedVolt_BMSH_TBOX_CellRatedVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO1_RMXR12_BMSH_TBOX_CELLRATEDVOLT_BMSH_TBOX_INFO1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_COL_BMSH_TBOX_CellRatedVolt_BMSH_TBOX_CellRatedVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO1__XQC0B_BMSH_TBOX_CELLRATEDVOLT_BMSH_TBOX_INFO1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellRatedVolt_BMSH_TBOX_CellRatedVolt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellUnderVoltage_BMSH_TBOX_CellUnderVoltage)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_TBOX_CellUnderVoltage_BMSH_TBOX_CellUnderVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_TBOX_CELLUNDERVOLTAGE_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellUnderVoltage_BMSH_TBOX_CellUnderVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT2_RMXR12_BMSH_TBOX_CELLUNDERVOLTAGE2_BMSH_TBOX_FAULT2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CELLVOLTMAXMIN_RMXR12_BMSH_TBOX_CELLVOLTMAXID_BMSH_CELLVOLTMAXMIN_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CELLVOLTMAXMIN_RMXR12_BMSH_TBOX_CELLVOLTMINID_BMSH_CELLVOLTMAXMIN_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO2_RMXR12_BMSH_TBOX_CELLSSUM_BMSH_TBOX_INFO2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT2_RMXR12_BMSH_TBOX_FIREALARM_BMSH_TBOX_FAULT2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_HWVer_BMSH_TBOX_HWVer)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_HWVer_BMSH_TBOX_HWVer;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO3_RMXR12_BMSH_TBOX_HWVER_BMSH_TBOX_INFO3_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_TBOX_HWVer_BMSH_TBOX_HWVer;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO3__XQC0B_BMSH_TBOX_HWVER_BMSH_TBOX_INFO3_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_HWVer_BMSH_TBOX_HWVer = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_HWVer_Test_BMSH_TBOX_HWVer_Test)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_HWVer_Test_BMSH_TBOX_HWVer_Test;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO3_RMXR12_BMSH_TBOX_HWVER_TEST_BMSH_TBOX_INFO3_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_TBOX_HWVer_Test_BMSH_TBOX_HWVer_Test;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO3__XQC0B_BMSH_TBOX_HWVER_TEST_BMSH_TBOX_INFO3_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_HWVer_Test_BMSH_TBOX_HWVer_Test = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_InsulationResistance_BMSH_TBOX_InsulationResistance)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_TBOX_InsulationResistance_BMSH_TBOX_InsulationResistance;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_TBOX_INSULATIONRESISTANCE_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_InsulationResistance_BMSH_TBOX_InsulationResistance = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT2_RMXR12_BMSH_TBOX_INSULATIONRESISTANCE2_BMSH_TBOX_FAULT2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TEMP_RMXR12_BMSH_TBOX_MAXTEMPID_BMSH_TEMP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TEMP_RMXR12_BMSH_TBOX_MINTEMPID_BMSH_TEMP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_SOCHop_BMSH_TBOX_SOCHop)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_TBOX_SOCHop_BMSH_TBOX_SOCHop;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT_RMXR12_BMSH_TBOX_SOCHOP_BMSH_TBOX_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_SOCHop_BMSH_TBOX_SOCHop = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT2_RMXR12_BMSH_TBOX_SOCHOP2_BMSH_TBOX_FAULT2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_SWVer_BMSH_TBOX_SWVer)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_SWVer_BMSH_TBOX_SWVer;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO3_RMXR12_BMSH_TBOX_SWVER_BMSH_TBOX_INFO3_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_TBOX_SWVer_BMSH_TBOX_SWVer;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO3__XQC0B_BMSH_TBOX_SWVER_BMSH_TBOX_INFO3_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_SWVer_BMSH_TBOX_SWVer = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_SWVer_Test_BMSH_TBOX_SWVer_Test)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_SWVer_Test_BMSH_TBOX_SWVer_Test;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO3_RMXR12_BMSH_TBOX_SWVER_TEST_BMSH_TBOX_INFO3_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_TBOX_SWVer_Test_BMSH_TBOX_SWVer_Test;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO3__XQC0B_BMSH_TBOX_SWVER_TEST_BMSH_TBOX_INFO3_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_SWVer_Test_BMSH_TBOX_SWVer_Test = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempA_BMSH_TBOX_TempA)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_TempA_BMSH_TBOX_TempA;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP_RMXR12_BMSH_TBOX_TEMPA_BMSH_TBOX_CELLTEMP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempA_BMSH_TBOX_TempA = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP_RMXR12_BMSH_TBOX_TEMPA_ID_BMSH_TBOX_CELLTEMP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempB_BMSH_TBOX_TempB)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_TempB_BMSH_TBOX_TempB;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP_RMXR12_BMSH_TBOX_TEMPB_BMSH_TBOX_CELLTEMP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempB_BMSH_TBOX_TempB = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempC_BMSH_TBOX_TempC)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_TempC_BMSH_TBOX_TempC;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP_RMXR12_BMSH_TBOX_TEMPC_BMSH_TBOX_CELLTEMP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempC_BMSH_TBOX_TempC = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempD_BMSH_TBOX_TempD)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_TempD_BMSH_TBOX_TempD;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP_RMXR12_BMSH_TBOX_TEMPD_BMSH_TBOX_CELLTEMP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempD_BMSH_TBOX_TempD = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempE_BMSH_TBOX_TempE)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_TempE_BMSH_TBOX_TempE;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP_RMXR12_BMSH_TBOX_TEMPE_BMSH_TBOX_CELLTEMP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempE_BMSH_TBOX_TempE = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempF_BMSH_TBOX_TempF)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_TempF_BMSH_TBOX_TempF;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP_RMXR12_BMSH_TBOX_TEMPF_BMSH_TBOX_CELLTEMP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempF_BMSH_TBOX_TempF = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempF_ID_BMSH_TBOX_TempF_ID)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_TBOX_TempF_ID_BMSH_TBOX_TempF_ID;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP_RMXR12_BMSH_TBOX_TEMPF_ID_BMSH_TBOX_CELLTEMP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempF_ID_BMSH_TBOX_TempF_ID = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TheftFault_BMSH_TBOX_TheftFault)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_TBOX_TheftFault_BMSH_TBOX_TheftFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_INFO2_RMXR12_BMSH_TBOX_THEFTFAULT_BMSH_TBOX_INFO2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TheftFault_BMSH_TBOX_TheftFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalDischgCapacity_BMSH_TotalDischgCapacity)
    {
        uint32 phydata_0 = (uint32)Rte_swc_COL_BMSH_TotalDischgCapacity_BMSH_TotalDischgCapacity;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_DISCHG_EXCHGCAPACITYINFO_RMXR12_BMSH_TOTALDISCHGCAPACITY_BMSH_DISCHG_EXCHGCAPACITYINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalDischgCapacity_BMSH_TotalDischgCapacity = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalDischgEng_BMSH_TotalDischgEng)
    {
        uint32 phydata_0 = (uint32)Rte_swc_COL_BMSH_TotalDischgEng_BMSH_TotalDischgEng;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_DISCHG_EXCHGENGINFO_RMXR12_BMSH_TOTALDISCHGENG_BMSH_DISCHG_EXCHGENGINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint32 phydata_1 = (uint32)Rte_swc_COL_BMSH_TotalDischgEng_BMSH_TotalDischgEng;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_DISCHG_EXCHGENGINFO__XQC0B_BMSH_TOTALDISCHGENG_BMSH_DISCHG_EXCHGENGINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalDischgEng_BMSH_TotalDischgEng = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalExChgCapacity_BMSH_TotalExChgCapacity)
    {
        uint32 phydata_0 = (uint32)Rte_swc_COL_BMSH_TotalExChgCapacity_BMSH_TotalExChgCapacity;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_DISCHG_EXCHGCAPACITYINFO_RMXR12_BMSH_TOTALEXCHGCAPACITY_BMSH_DISCHG_EXCHGCAPACITYINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalExChgCapacity_BMSH_TotalExChgCapacity = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalExChgEng_BMSH_TotalExChgEng)
    {
        uint32 phydata_0 = (uint32)Rte_swc_COL_BMSH_TotalExChgEng_BMSH_TotalExChgEng;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_DISCHG_EXCHGENGINFO_RMXR12_BMSH_TOTALEXCHGENG_BMSH_DISCHG_EXCHGENGINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint32 phydata_1 = (uint32)Rte_swc_COL_BMSH_TotalExChgEng_BMSH_TotalExChgEng;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_DISCHG_EXCHGENGINFO__XQC0B_BMSH_TOTALEXCHGENG_BMSH_DISCHG_EXCHGENGINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalExChgEng_BMSH_TotalExChgEng = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalExChgSOE_BMSH_TotalExChgSOE)
    {
        uint32 phydata_0 = (uint32)Rte_swc_COL_BMSH_TotalExChgSOE_BMSH_TotalExChgSOE;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CHGENERGY_RMXR12_BMSH_TOTALEXCHGSOE_BMSH_CHGENERGY_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalExChgSOE_BMSH_TotalExChgSOE = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalOdometer_BMSH_TotalOdometer)
    {
        uint32 phydata_0 = (uint32)Rte_swc_COL_BMSH_TotalOdometer_BMSH_TotalOdometer;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_ODOMETERINFO_RMXR12_BMSH_TOTALODOMETER_BMSH_ODOMETERINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalOdometer_BMSH_TotalOdometer = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalOdometerValidFlag_BMSH_TotalOdometerValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_TotalOdometerValidFlag_BMSH_TotalOdometerValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_ODOMETERINFO_RMXR12_BMSH_TOTALODOMETERVALIDFLAG_BMSH_ODOMETERINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalOdometerValidFlag_BMSH_TotalOdometerValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalRecoveryCapacity_BMSH_TotalRecoveryCapacity)
    {
        uint32 phydata_0 = (uint32)Rte_swc_COL_BMSH_TotalRecoveryCapacity_BMSH_TotalRecoveryCapacity;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_RECOVERYCAPACITYINFO_RMXR12_BMSH_TOTALRECOVERYCAPACITY_BMSH_RECOVERYCAPACITYINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalRecoveryCapacity_BMSH_TotalRecoveryCapacity = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalRecoveryEng_BMSH_TotalRecoveryEng)
    {
        uint32 phydata_0 = (uint32)Rte_swc_COL_BMSH_TotalRecoveryEng_BMSH_TotalRecoveryEng;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_RECOVERYENGINFO_RMXR12_BMSH_TOTALRECOVERYENG_BMSH_RECOVERYENGINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint32 phydata_1 = (uint32)Rte_swc_COL_BMSH_TotalRecoveryEng_BMSH_TotalRecoveryEng;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_RECOVERYENGINFO__XQC0B_BMSH_TOTALRECOVERYENG_BMSH_RECOVERYENGINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalRecoveryEng_BMSH_TotalRecoveryEng = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TripOdometer_BMSH_TripOdometer)
    {
        uint32 phydata_0 = (uint32)Rte_swc_COL_BMSH_TripOdometer_BMSH_TripOdometer;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_ODOMETERINFO_RMXR12_BMSH_TRIPODOMETER_BMSH_ODOMETERINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TripOdometer_BMSH_TripOdometer = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TripOdometerValidFlag_BMSH_TripOdometerValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_TripOdometerValidFlag_BMSH_TripOdometerValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_ODOMETERINFO_RMXR12_BMSH_TRIPODOMETERVALIDFLAG_BMSH_ODOMETERINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TripOdometerValidFlag_BMSH_TripOdometerValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCUChksumFault_BMSH_VCUChksumFault)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_VCUChksumFault_BMSH_VCUChksumFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_VCUCHKSUMFAULT_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCUChksumFault_BMSH_VCUChksumFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCURollCountFault_BMSH_VCURollCountFault)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_VCURollCountFault_BMSH_VCURollCountFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULT_RMXR12_BMSH_VCUROLLCOUNTFAULT_BMSH_FAULT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCURollCountFault_BMSH_VCURollCountFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP_RMXR12_BMSH_VCU_BATCHGALLOWPWR_BMSH_SOP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP__XQC0B_BMSH_VCU_BATCHGALLOWPWR_BMSH_SOP_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_BatChgContPwr_BMSH_VCU_BatChgContPwr)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_VCU_BatChgContPwr_BMSH_VCU_BatChgContPwr;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP_RMXR12_BMSH_VCU_BATCHGCONTPWR_BMSH_SOP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_VCU_BatChgContPwr_BMSH_VCU_BatChgContPwr;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP__XQC0B_BMSH_VCU_BATCHGCONTPWR_BMSH_SOP_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_BatChgContPwr_BMSH_VCU_BatChgContPwr = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_BatChgPeakPwr_BMSH_VCU_BatChgPeakPwr)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_VCU_BatChgPeakPwr_BMSH_VCU_BatChgPeakPwr;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP_RMXR12_BMSH_VCU_BATCHGPEAKPWR_BMSH_SOP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_VCU_BatChgPeakPwr_BMSH_VCU_BatChgPeakPwr;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP__XQC0B_BMSH_VCU_BATCHGPEAKPWR_BMSH_SOP_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_BatChgPeakPwr_BMSH_VCU_BatChgPeakPwr = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP_RMXR12_BMSH_VCU_BATDISCHGALLOWPWR_BMSH_SOP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP__XQC0B_BMSH_VCU_BATDISCHGALLOWPWR_BMSH_SOP_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_BatDischgContPwr_BMSH_VCU_BatDischgContPwr)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_VCU_BatDischgContPwr_BMSH_VCU_BatDischgContPwr;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP_RMXR12_BMSH_VCU_BATDISCHGCONTPWR_BMSH_SOP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_VCU_BatDischgContPwr_BMSH_VCU_BatDischgContPwr;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP__XQC0B_BMSH_VCU_BATDISCHGCONTPWR_BMSH_SOP_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_BatDischgContPwr_BMSH_VCU_BatDischgContPwr = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_BatDischgPeakPwr_BMSH_VCU_BatDischgPeakPwr)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_VCU_BatDischgPeakPwr_BMSH_VCU_BatDischgPeakPwr;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP_RMXR12_BMSH_VCU_BATDISCHGPEAKPWR_BMSH_SOP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_VCU_BatDischgPeakPwr_BMSH_VCU_BatDischgPeakPwr;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP__XQC0B_BMSH_VCU_BATDISCHGPEAKPWR_BMSH_SOP_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_BatDischgPeakPwr_BMSH_VCU_BatDischgPeakPwr = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_VCU_CHGFAULTREQ_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_ChgSOPRangeUP_BMSH_VCU_ChgSOPRangeUP)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_VCU_ChgSOPRangeUP_BMSH_VCU_ChgSOPRangeUP;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP_RMXR12_BMSH_VCU_CHGSOPRANGEUP_BMSH_SOP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_VCU_ChgSOPRangeUP_BMSH_VCU_ChgSOPRangeUP;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP__XQC0B_BMSH_VCU_CHGSOPRANGEUP_BMSH_SOP_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_ChgSOPRangeUP_BMSH_VCU_ChgSOPRangeUP = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_ChgSOPValidFlag_BMSH_VCU_ChgSOPValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_VCU_ChgSOPValidFlag_BMSH_VCU_ChgSOPValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP_RMXR12_BMSH_VCU_CHGSOPVALIDFLAG_BMSH_SOP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_VCU_ChgSOPValidFlag_BMSH_VCU_ChgSOPValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP__XQC0B_BMSH_VCU_CHGSOPVALIDFLAG_BMSH_SOP_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_ChgSOPValidFlag_BMSH_VCU_ChgSOPValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_Crash_BMSH_VCU_Crash)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_VCU_Crash_BMSH_VCU_Crash;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_VCU_CRASH_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_Crash_BMSH_VCU_Crash = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_DCChgNegTemp_BMSH_VCU_DCChgNegTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_VCU_DCChgNegTemp_BMSH_VCU_DCChgNegTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TEMP_RMXR12_BMSH_VCU_DCCHGNEGTEMP_BMSH_TEMP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_DCChgNegTemp_BMSH_VCU_DCChgNegTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_DCChgPosTemp_BMSH_VCU_DCChgPosTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_VCU_DCChgPosTemp_BMSH_VCU_DCChgPosTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TEMP_RMXR12_BMSH_VCU_DCCHGPOSTEMP_BMSH_TEMP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_DCChgPosTemp_BMSH_VCU_DCChgPosTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP_RMXR12_BMSH_VCU_DISCHGSOPRANGEUP_BMSH_SOP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP__XQC0B_BMSH_VCU_DISCHGSOPRANGEUP_BMSH_SOP_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_DisChgSOPValidFlag_BMSH_VCU_DisChgSOPValidFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMSH_VCU_DisChgSOPValidFlag_BMSH_VCU_DisChgSOPValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP_RMXR12_BMSH_VCU_DISCHGSOPVALIDFLAG_BMSH_SOP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMSH_VCU_DisChgSOPValidFlag_BMSH_VCU_DisChgSOPValidFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOP__XQC0B_BMSH_VCU_DISCHGSOPVALIDFLAG_BMSH_SOP_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_DisChgSOPValidFlag_BMSH_VCU_DisChgSOPValidFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_VCU_DISCHGFAULTREQ_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_StsDCChgPosRelay_BMSH_VCU_StsDCChgPosRelay)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_VCU_StsDCChgPosRelay_BMSH_VCU_StsDCChgPosRelay;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_SOX_RMXR12_BMSH_VCU_STSDCCHGPOSRELAY_BMSH_SOX_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_StsDCChgPosRelay_BMSH_VCU_StsDCChgPosRelay = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_StsDCChgRelay_BMSH_VCU_StsDCChgRelay)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_VCU_StsDCChgRelay_BMSH_VCU_StsDCChgRelay;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_VCU_STSDCCHGRELAY_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_VCU_StsDCChgRelay_BMSH_VCU_StsDCChgRelay;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS__XQC0B_BMSH_VCU_STSDCCHGRELAY_BMSH_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_StsDCChgRelay_BMSH_VCU_StsDCChgRelay = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_VCU_STSMAINHVIL_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS__XQC0B_BMSH_VCU_STSMAINHVIL_BMSH_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_StsPreChgRelay_BMSH_VCU_StsPreChgRelay)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMSH_VCU_StsPreChgRelay_BMSH_VCU_StsPreChgRelay;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STATUS_RMXR12_BMSH_VCU_STSPRECHGRELAY_BMSH_STATUS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_StsPreChgRelay_BMSH_VCU_StsPreChgRelay = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_B2V_ST1_ChgMode_BMS_B2V_ST1_ChgMode)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_B2V_ST1_ChgMode_BMS_B2V_ST1_ChgMode;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO_RMXR12_BMS_B2V_ST1_CHGMODE_BMS_ACCHGCTRLINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_B2V_ST1_ChgMode_BMS_B2V_ST1_ChgMode;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO__XQC0B_BMS_B2V_ST1_CHGMODE_BMS_ACCHGCTRLINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_B2V_ST1_ChgMode_BMS_B2V_ST1_ChgMode = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattCellsNumPN_BMS_BattCellsNumPN)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_BattCellsNumPN_BMS_BattCellsNumPN;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOXINFOR_RMXR12_BMS_BATTCELLSNUMPN_BMSH_TBOXINFOR_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_BattCellsNumPN_BMS_BattCellsNumPN;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOXINFOR__XQC0B_BMS_BATTCELLSNUMPN_BMSH_TBOXINFOR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattCellsNumPN_BMS_BattCellsNumPN = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattPackNumSN_BMS_BattPackNumSN)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_BattPackNumSN_BMS_BattPackNumSN;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOXINFOR_RMXR12_BMS_BATTPACKNUMSN_BMSH_TBOXINFOR_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_BattPackNumSN_BMS_BattPackNumSN;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOXINFOR__XQC0B_BMS_BATTPACKNUMSN_BMSH_TBOXINFOR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattPackNumSN_BMS_BattPackNumSN = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattTemp1_BMS_BattTemp1)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_BattTemp1_BMS_BattTemp1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP1_RMXR12_BMS_BATTTEMP1_BMSH_TBOX_CELLTEMP1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_BattTemp1_BMS_BattTemp1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_CELLTEMPDATA__XQC0B_BMS_BATTTEMP1_BMS_CELLTEMPDATA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_COL_BMS_BattTemp1_BMS_BattTemp1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP1__XQC0B_BMS_BATTTEMP1_BMSH_TBOX_CELLTEMP1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattTemp1_BMS_BattTemp1 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattTemp2_BMS_BattTemp2)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_BattTemp2_BMS_BattTemp2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP1_RMXR12_BMS_BATTTEMP2_BMSH_TBOX_CELLTEMP1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_BattTemp2_BMS_BattTemp2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_CELLTEMPDATA__XQC0B_BMS_BATTTEMP2_BMS_CELLTEMPDATA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_COL_BMS_BattTemp2_BMS_BattTemp2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP1__XQC0B_BMS_BATTTEMP2_BMSH_TBOX_CELLTEMP1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattTemp2_BMS_BattTemp2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattTemp3_BMS_BattTemp3)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_BattTemp3_BMS_BattTemp3;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP1_RMXR12_BMS_BATTTEMP3_BMSH_TBOX_CELLTEMP1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_BattTemp3_BMS_BattTemp3;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_CELLTEMPDATA__XQC0B_BMS_BATTTEMP3_BMS_CELLTEMPDATA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_COL_BMS_BattTemp3_BMS_BattTemp3;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP1__XQC0B_BMS_BATTTEMP3_BMSH_TBOX_CELLTEMP1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattTemp3_BMS_BattTemp3 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattTemp4_BMS_BattTemp4)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_BattTemp4_BMS_BattTemp4;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP1_RMXR12_BMS_BATTTEMP4_BMSH_TBOX_CELLTEMP1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_BattTemp4_BMS_BattTemp4;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_CELLTEMPDATA__XQC0B_BMS_BATTTEMP4_BMS_CELLTEMPDATA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_COL_BMS_BattTemp4_BMS_BattTemp4;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP1__XQC0B_BMS_BATTTEMP4_BMSH_TBOX_CELLTEMP1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattTemp4_BMS_BattTemp4 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattTemp5_BMS_BattTemp5)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_BattTemp5_BMS_BattTemp5;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP1_RMXR12_BMS_BATTTEMP5_BMSH_TBOX_CELLTEMP1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_BattTemp5_BMS_BattTemp5;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_CELLTEMPDATA__XQC0B_BMS_BATTTEMP5_BMS_CELLTEMPDATA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_COL_BMS_BattTemp5_BMS_BattTemp5;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP1__XQC0B_BMS_BATTTEMP5_BMSH_TBOX_CELLTEMP1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattTemp5_BMS_BattTemp5 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattTemp6_BMS_BattTemp6)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_BattTemp6_BMS_BattTemp6;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP1_RMXR12_BMS_BATTTEMP6_BMSH_TBOX_CELLTEMP1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_BattTemp6_BMS_BattTemp6;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_CELLTEMPDATA__XQC0B_BMS_BATTTEMP6_BMS_CELLTEMPDATA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_COL_BMS_BattTemp6_BMS_BattTemp6;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP1__XQC0B_BMS_BATTTEMP6_BMSH_TBOX_CELLTEMP1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattTemp6_BMS_BattTemp6 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CCvalue_BMS_CCvalue)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_CCvalue_BMS_CCvalue;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_INFOR_RMXR12_BMS_CCVALUE_BMS_INFOR_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_CCvalue_BMS_CCvalue;
        Com_SendSignal(COMCONF_COMSIGNAL_OBC_STATUS2__XQC0B_OBC_CCVALUE_OBC_STATUS2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CCvalue_BMS_CCvalue = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CPLine_S2_Ctrl_BMS_CPLine_S2_Ctrl)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMS_CPLine_S2_Ctrl_BMS_CPLine_S2_Ctrl;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_INFOR_RMXR12_BMS_CPLINE_S2_CTRL_BMS_INFOR_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMS_CPLine_S2_Ctrl_BMS_CPLine_S2_Ctrl;
        Com_SendSignal(COMCONF_COMSIGNAL_OBC_CURR__XQC0B_OBC_CPLINE_S2_ST_OBC_CURR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CPLine_S2_Ctrl_BMS_CPLine_S2_Ctrl = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CP_Duty_BMS_CP_Duty)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_CP_Duty_BMS_CP_Duty;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_INFOR_RMXR12_BMS_CP_DUTY_BMS_INFOR_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_CP_Duty_BMS_CP_Duty;
        Com_SendSignal(COMCONF_COMSIGNAL_OBC_STATUS2__XQC0B_OBC_CP_DUTY_OBC_STATUS2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CP_Duty_BMS_CP_Duty = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CP_Vol_BMS_CP_Vol)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_CP_Vol_BMS_CP_Vol;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_INFOR_RMXR12_BMS_CP_VOL_BMS_INFOR_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CP_Vol_BMS_CP_Vol = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CellTempFrameNum_BMS_CellTempFrameNum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_CellTempFrameNum_BMS_CellTempFrameNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP1_RMXR12_BMS_CELLTEMPFRAMENUM_BMSH_TBOX_CELLTEMP1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_CellTempFrameNum_BMS_CellTempFrameNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_CELLTEMPDATA__XQC0B_BMS_CELLTEMPFRAMENUM_BMS_CELLTEMPDATA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_COL_BMS_CellTempFrameNum_BMS_CellTempFrameNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP1__XQC0B_BMS_CELLTEMPFRAMENUM_BMSH_TBOX_CELLTEMP1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CellTempFrameNum_BMS_CellTempFrameNum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CellVoltFrameNum_BMS_CellVoltFrameNum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_CellVoltFrameNum_BMS_CellVoltFrameNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLVOLT1_RMXR12_BMS_CELLVOLTFRAMENUM_BMSH_TBOX_CELLVOLT1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_CellVoltFrameNum_BMS_CellVoltFrameNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_CELLVOLTDATA__XQC0B_BMS_CELLVOLTFRAMENUM_BMS_CELLVOLTDATA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_COL_BMS_CellVoltFrameNum_BMS_CellVoltFrameNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLVOLT1__XQC0B_BMS_CELLVOLTFRAMENUM_BMSH_TBOX_CELLVOLT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CellVoltFrameNum_BMS_CellVoltFrameNum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CellVoltN1_BMS_CellVoltN1)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMS_CellVoltN1_BMS_CellVoltN1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLVOLT1_RMXR12_BMS_CELLVOLTN1_BMSH_TBOX_CELLVOLT1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_COL_BMS_CellVoltN1_BMS_CellVoltN1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_CELLVOLTDATA__XQC0B_BMS_CELLVOLTN1_BMS_CELLVOLTDATA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint16 phydata_2 = (uint16)Rte_swc_COL_BMS_CellVoltN1_BMS_CellVoltN1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLVOLT1__XQC0B_BMS_CELLVOLTN1_BMSH_TBOX_CELLVOLT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CellVoltN1_BMS_CellVoltN1 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CellVoltN2_BMS_CellVoltN2)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMS_CellVoltN2_BMS_CellVoltN2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLVOLT1_RMXR12_BMS_CELLVOLTN2_BMSH_TBOX_CELLVOLT1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_COL_BMS_CellVoltN2_BMS_CellVoltN2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_CELLVOLTDATA__XQC0B_BMS_CELLVOLTN2_BMS_CELLVOLTDATA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint16 phydata_2 = (uint16)Rte_swc_COL_BMS_CellVoltN2_BMS_CellVoltN2;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLVOLT1__XQC0B_BMS_CELLVOLTN2_BMSH_TBOX_CELLVOLT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CellVoltN2_BMS_CellVoltN2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CellVoltN3_BMS_CellVoltN3)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMS_CellVoltN3_BMS_CellVoltN3;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLVOLT1_RMXR12_BMS_CELLVOLTN3_BMSH_TBOX_CELLVOLT1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_COL_BMS_CellVoltN3_BMS_CellVoltN3;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_CELLVOLTDATA__XQC0B_BMS_CELLVOLTN3_BMS_CELLVOLTDATA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint16 phydata_2 = (uint16)Rte_swc_COL_BMS_CellVoltN3_BMS_CellVoltN3;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLVOLT1__XQC0B_BMS_CELLVOLTN3_BMSH_TBOX_CELLVOLT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CellVoltN3_BMS_CellVoltN3 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_ChgCCSts_BMS_ChgCCSts)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_ChgCCSts_BMS_ChgCCSts;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_INFOR_RMXR12_BMS_CHGCCSTS_BMS_INFOR_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_ChgCCSts_BMS_ChgCCSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_ChgStatus_BMS_ChgStatus)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_ChgStatus_BMS_ChgStatus;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO_RMXR12_BMS_CHGSTATUS_BMS_ACCHGCTRLINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_ChgStatus_BMS_ChgStatus;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO__XQC0B_BMS_CHGSTATUS_BMS_ACCHGCTRLINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_ChgStatus_BMS_ChgStatus = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CutOffLVFbToOBC_BMS_CutOffLVFbToOBC)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_CutOffLVFbToOBC_BMS_CutOffLVFbToOBC;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO_RMXR12_BMS_CUTOFFLVFBTOOBC_BMS_ACCHGCTRLINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_CutOffLVFbToOBC_BMS_CutOffLVFbToOBC;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO__XQC0B_BMS_CUTOFFLVFBTOOBC_BMS_ACCHGCTRLINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CutOffLVFbToOBC_BMS_CutOffLVFbToOBC = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_DCChargRelayCtrl_BMS_DCChargRelayCtrl)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_DCChargRelayCtrl_BMS_DCChargRelayCtrl;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO__XQC0B_BMS_DCCHARGRELAYCTRL_BMS_ACCHGCTRLINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_DCChargRelayCtrl_BMS_DCChargRelayCtrl = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_DelayControl_BMS_DelayControl)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMS_DelayControl_BMS_DelayControl;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_INFOR2_RMXR12_BMS_DELAYCONTROL_BMS_INFOR2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMS_DelayControl_BMS_DelayControl;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_INFOR2__XQC0B_BMS_DELAYCONTROL_BMS_INFOR2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_DelayControl_BMS_DelayControl = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_INFOR2_RMXR12_BMS_DELAYDATAUPLDENB_BMS_INFOR2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_INFOR2__XQC0B_BMS_DELAYDATAUPLDENB_BMS_INFOR2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_DischargeCCvalue_BMS_DischargeCCvalue)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_DischargeCCvalue_BMS_DischargeCCvalue;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_INFOR_RMXR12_BMS_DISCHARGECCVALUE_BMS_INFOR_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_DischargeCCvalue_BMS_DischargeCCvalue;
        Com_SendSignal(COMCONF_COMSIGNAL_OBC_STATUS2__XQC0B_OBC_DISCHARGECCVALUE_OBC_STATUS2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_DischargeCCvalue_BMS_DischargeCCvalue = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_ElectroniclockContorREQ_BMS_ElectroniclockContorREQ)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_ElectroniclockContorREQ_BMS_ElectroniclockContorREQ;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO_RMXR12_BMS_ELECTRONICLOCKCONTORREQ_BMS_ACCHGCTRLINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_ElectroniclockContorREQ_BMS_ElectroniclockContorREQ;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO__XQC0B_BMS_ELECTRONICLOCKCONTORREQ_BMS_ACCHGCTRLINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_ElectroniclockContorREQ_BMS_ElectroniclockContorREQ = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_ElectroniclockSts_BMS_ElectroniclockSts)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_ElectroniclockSts_BMS_ElectroniclockSts;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO_RMXR12_BMS_ELECTRONICLOCKSTS_BMS_ACCHGCTRLINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_ElectroniclockSts_BMS_ElectroniclockSts;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO__XQC0B_BMS_ELECTRONICLOCKSTS_BMS_ACCHGCTRLINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_ElectroniclockSts_BMS_ElectroniclockSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_MaxChgCurrent_BMS_MaxChgCurrent)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMS_MaxChgCurrent_BMS_MaxChgCurrent;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO_RMXR12_BMS_MAXCHGCURRENT_BMS_ACCHGCTRLINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_COL_BMS_MaxChgCurrent_BMS_MaxChgCurrent;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO__XQC0B_BMS_MAXCHGCURRENT_BMS_ACCHGCTRLINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_MaxChgCurrent_BMS_MaxChgCurrent = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_MaxChgVoltage_BMS_MaxChgVoltage)
    {
        uint16 phydata_0 = (uint16)Rte_swc_COL_BMS_MaxChgVoltage_BMS_MaxChgVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO_RMXR12_BMS_MAXCHGVOLTAGE_BMS_ACCHGCTRLINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_COL_BMS_MaxChgVoltage_BMS_MaxChgVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO__XQC0B_BMS_MAXCHGVOLTAGE_BMS_ACCHGCTRLINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_MaxChgVoltage_BMS_MaxChgVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_OBCChgContrlCmd_BMS_OBCChgContrlCmd)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_OBCChgContrlCmd_BMS_OBCChgContrlCmd;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO_RMXR12_BMS_OBCCHGCONTRLCMD_BMS_ACCHGCTRLINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_OBCChgContrlCmd_BMS_OBCChgContrlCmd;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO__XQC0B_BMS_OBCCHGCONTRLCMD_BMS_ACCHGCTRLINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_OBCChgContrlCmd_BMS_OBCChgContrlCmd = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_S2STATUS_BMS_S2STATUS)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMS_S2STATUS_BMS_S2STATUS;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_OVERSEASCHGINFO_RMXR12_BMS_S2STATUS_BMS_OVERSEASCHGINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_S2STATUS_BMS_S2STATUS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_SlowChgNegTemp_BMS_SlowChgNegTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_SlowChgNegTemp_BMS_SlowChgNegTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_INFOR_RMXR12_BMS_SLOWCHGNEGTEMP_BMS_INFOR_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_SlowChgNegTemp_BMS_SlowChgNegTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_OBC_STATUS2__XQC0B_OBC_SLOWCHGNEGTEMP_OBC_STATUS2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_SlowChgNegTemp_BMS_SlowChgNegTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_SlowChgPosTemp_BMS_SlowChgPosTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_SlowChgPosTemp_BMS_SlowChgPosTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_INFOR_RMXR12_BMS_SLOWCHGPOSTEMP_BMS_INFOR_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_SlowChgPosTemp_BMS_SlowChgPosTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_OBC_STATUS2__XQC0B_OBC_SLOWCHGPOSTEMP_OBC_STATUS2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_SlowChgPosTemp_BMS_SlowChgPosTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_SysCodeBattPackSN_1_BMS_SysCodeBattPackSN_1)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_SysCodeBattPackSN_1_BMS_SysCodeBattPackSN_1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE1_RMXR12_BMS_SYSCODEBATTPACKSN_1_BMSH_PACKCODE1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_SysCodeBattPackSN_1_BMS_SysCodeBattPackSN_1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE1__XQC0B_BMS_SYSCODEBATTPACKSN_BMSH_PACKCODE1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_SysCodeBattPackSN_1_BMS_SysCodeBattPackSN_1 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_SysCodeFrameNum_1_BMS_SysCodeFrameNum_1)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_SysCodeFrameNum_1_BMS_SysCodeFrameNum_1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE1_RMXR12_BMS_SYSCODEFRAMENUM_1_BMSH_PACKCODE1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_SysCodeFrameNum_1_BMS_SysCodeFrameNum_1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE1__XQC0B_BMS_SYSCODEFRAMENUM_BMSH_PACKCODE1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_SysCodeFrameNum_1_BMS_SysCodeFrameNum_1 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_SysCodeLength_1_BMS_SysCodeLength_1)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_SysCodeLength_1_BMS_SysCodeLength_1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE1_RMXR12_BMS_SYSCODELENGTH_1_BMSH_PACKCODE1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_SysCodeLength_1_BMS_SysCodeLength_1;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_PACKCODE1__XQC0B_BMS_SYSCODELENGTH_BMSH_PACKCODE1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_SysCodeLength_1_BMS_SysCodeLength_1 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_TempCSCNum_BMS_TempCSCNum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_TempCSCNum_BMS_TempCSCNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP1_RMXR12_BMS_TEMPCSCNUM_BMSH_TBOX_CELLTEMP1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_TempCSCNum_BMS_TempCSCNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_CELLTEMPDATA__XQC0B_BMS_TEMPCSCNUM_BMS_CELLTEMPDATA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_COL_BMS_TempCSCNum_BMS_TempCSCNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLTEMP1__XQC0B_BMS_TEMPCSCNUM_BMSH_TBOX_CELLTEMP1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_TempCSCNum_BMS_TempCSCNum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_TempSnsNumPN_BMS_TempSnsNumPN)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_TempSnsNumPN_BMS_TempSnsNumPN;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOXINFOR_RMXR12_BMS_TEMPSNSNUMPN_BMSH_TBOXINFOR_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_TempSnsNumPN_BMS_TempSnsNumPN;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOXINFOR__XQC0B_BMS_TEMPSNSNUMPN_BMSH_TBOXINFOR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_TempSnsNumPN_BMS_TempSnsNumPN = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_VCU_ChrgFullCalRemind_BMS_VCU_ChrgFullCalRemind)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMS_VCU_ChrgFullCalRemind_BMS_VCU_ChrgFullCalRemind;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ_RMXR12_BMS_VCU_CHRGFULLCALREMIND_BMSH_CCM_REQ_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMS_VCU_ChrgFullCalRemind_BMS_VCU_ChrgFullCalRemind;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ__XQC0B_BMS_VCU_CHRGFULLCALREMIND_BMSH_CCM_REQ_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_VCU_ChrgFullCalRemind_BMS_VCU_ChrgFullCalRemind = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_VCU_ChrgModeAct_BMS_VCU_ChrgModeAct)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_VCU_ChrgModeAct_BMS_VCU_ChrgModeAct;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ_RMXR12_BMS_VCU_CHRGMODEACT_BMSH_CCM_REQ_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_VCU_ChrgModeAct_BMS_VCU_ChrgModeAct;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ__XQC0B_BMS_VCU_CHRGMODEACT_BMSH_CCM_REQ_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_VCU_ChrgModeAct_BMS_VCU_ChrgModeAct = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_VCU_ChrgModeCalRemind_BMS_VCU_ChrgModeCalRemind)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMS_VCU_ChrgModeCalRemind_BMS_VCU_ChrgModeCalRemind;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ_RMXR12_BMS_VCU_CHRGMODECALREMIND_BMSH_CCM_REQ_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMS_VCU_ChrgModeCalRemind_BMS_VCU_ChrgModeCalRemind;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ__XQC0B_BMS_VCU_CHRGMODECALREMIND_BMSH_CCM_REQ_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_VCU_ChrgModeCalRemind_BMS_VCU_ChrgModeCalRemind = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_VCU_ChrgModeEn_BMS_VCU_ChrgModeEn)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMS_VCU_ChrgModeEn_BMS_VCU_ChrgModeEn;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ_RMXR12_BMS_VCU_CHRGMODEEN_BMSH_CCM_REQ_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMS_VCU_ChrgModeEn_BMS_VCU_ChrgModeEn;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CCM_REQ__XQC0B_BMS_VCU_CHRGMODEEN_BMSH_CCM_REQ_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_VCU_ChrgModeEn_BMS_VCU_ChrgModeEn = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_VoltCellNum_BMS_VoltCellNum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_BMS_VoltCellNum_BMS_VoltCellNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLVOLT1_RMXR12_BMS_VOLTCELLNUM_BMSH_TBOX_CELLVOLT1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_COL_BMS_VoltCellNum_BMS_VoltCellNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_CELLVOLTDATA__XQC0B_BMS_VOLTCELLNUM_BMS_CELLVOLTDATA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_COL_BMS_VoltCellNum_BMS_VoltCellNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_CELLVOLT1__XQC0B_BMS_VOLTCELLNUM_BMSH_TBOX_CELLVOLT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_VoltCellNum_BMS_VoltCellNum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req)
    {
        boolean phydata_0 = (boolean)Rte_swc_COL_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO_RMXR12_BMS_ZEROPWR_REQ_BMS_ACCHGCTRLINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_COL_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_ACCHGCTRLINFO__XQC0B_BMS_ZEROPWR_REQ_BMS_ACCHGCTRLINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_HvSysSample_DisableIso_DisableIso)
    {
        uint8 phydata_0 = (uint8)Rte_swc_COL_HvSysSample_DisableIso_DisableIso;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_RELAYSAMPSWICH_LGFZID_BMS_INSULATESAMPSWICH_BMS_RELAYSAMPSWICH_N72_HCM__MATRIX_V1_1_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_HvSysSample_DisableIso_DisableIso = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCL_ChargingMode_ChargingMode)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BCL_ChargingMode_ChargingMode;
        Com_SendSignal(COMCONF_COMSIGNAL_BCL_10NGGJ_BCL_CHARGEMODE_BCL_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCL_ChargingMode_ChargingMode = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCL_CurrentDemand_CurrentDemand)
    {
        uint16 phydata_0 = (uint16)Rte_swc_SetSendCANMsg_S_BCL_CurrentDemand_CurrentDemand;
        Com_SendSignal(COMCONF_COMSIGNAL_BCL_10NGGJ_BCL_CURRENTREQUIRE_BCL_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCL_CurrentDemand_CurrentDemand = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCL_VoltageDemand_VoltageDemand)
    {
        uint16 phydata_0 = (uint16)Rte_swc_SetSendCANMsg_S_BCL_VoltageDemand_VoltageDemand;
        Com_SendSignal(COMCONF_COMSIGNAL_BCL_10NGGJ_BCL_VOLLTAGEREQUIRE_BCL_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCL_VoltageDemand_VoltageDemand = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage)
    {
        uint16 phydata_0 = (uint16)Rte_swc_SetSendCANMsg_S_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BCP_10NGGJ_BCP_BATTERYTOTALVOLTAGE_BCP_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent)
    {
        uint16 phydata_0 = (uint16)Rte_swc_SetSendCANMsg_S_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent;
        Com_SendSignal(COMCONF_COMSIGNAL_BCP_10NGGJ_BCP_CHARGECURRENTMAX_BCP_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_MaxPermTemperature_MaxPermTemperature)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BCP_MaxPermTemperature_MaxPermTemperature;
        Com_SendSignal(COMCONF_COMSIGNAL_BCP_10NGGJ_BCP_ALLOWTEMPMAX_BCP_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_MaxPermTemperature_MaxPermTemperature = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage)
    {
        uint16 phydata_0 = (uint16)Rte_swc_SetSendCANMsg_S_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BCP_10NGGJ_BCP_BATTERYCHARGEVOLTAGEMAX_BCP_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery)
    {
        uint16 phydata_0 = (uint16)Rte_swc_SetSendCANMsg_S_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery;
        Com_SendSignal(COMCONF_COMSIGNAL_BCP_10NGGJ_BCP_SOC_BCP_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage)
    {
        uint16 phydata_0 = (uint16)Rte_swc_SetSendCANMsg_S_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BCP_10NGGJ_BCP_ALLOWCHARGEVOLTAGEMAX_BCP_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_TotalNominalEnergy_TotalNominalEnergy)
    {
        uint16 phydata_0 = (uint16)Rte_swc_SetSendCANMsg_S_BCP_TotalNominalEnergy_TotalNominalEnergy;
        Com_SendSignal(COMCONF_COMSIGNAL_BCP_10NGGJ_BCP_BATTERYNOMINALENERGY_BCP_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_TotalNominalEnergy_TotalNominalEnergy = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_CurrentChargeState_CurrentChargeState)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BCS_CurrentChargeState_CurrentChargeState;
        Com_SendSignal(COMCONF_COMSIGNAL_BCS_10NGGJ_BCS_SOC_BCS_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_CurrentChargeState_CurrentChargeState = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime)
    {
        uint16 phydata_0 = (uint16)Rte_swc_SetSendCANMsg_S_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime;
        Com_SendSignal(COMCONF_COMSIGNAL_BCS_10NGGJ_BCS_ESTIMATEDTIMEREMAINING_BCS_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent)
    {
        uint16 phydata_0 = (uint16)Rte_swc_SetSendCANMsg_S_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent;
        Com_SendSignal(COMCONF_COMSIGNAL_BCS_10NGGJ_BCS_CHARGECURRENTMEASURE_BCS_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage)
    {
        uint16 phydata_0 = (uint16)Rte_swc_SetSendCANMsg_S_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BCS_10NGGJ_BCS_CHARGEVOLTAGEMEASURE_BCS_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage)
    {
        uint16 phydata_0 = (uint16)Rte_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BCS_10NGGJ_BCS_BATTERYVOLTMAX_BCS_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup;
        Com_SendSignal(COMCONF_COMSIGNAL_BCS_10NGGJ_BCS_BATTERYVOLTMAXGROUP_BCS_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CCS_Timeout_CCS)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BEM_Timeout_CCS_Timeout_CCS;
        Com_SendSignal(COMCONF_COMSIGNAL_BEM_10NGGJ_BEM_CHARGESTATETIMEOUT_BEM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CCS_Timeout_CCS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized;
        Com_SendSignal(COMCONF_COMSIGNAL_BEM_10NGGJ_BEM_CHARGERIDTIMEOUT0_BEM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized;
        Com_SendSignal(COMCONF_COMSIGNAL_BEM_10NGGJ_BEM_CHARGERIDTIMEOUT1_BEM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CRO_Timeout_CRO)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BEM_Timeout_CRO_Timeout_CRO;
        Com_SendSignal(COMCONF_COMSIGNAL_BEM_10NGGJ_BEM_CHARGEFINISHTIMEOUT_BEM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CRO_Timeout_CRO = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CSD_Timeout_CSD)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BEM_Timeout_CSD_Timeout_CSD;
        Com_SendSignal(COMCONF_COMSIGNAL_BEM_10NGGJ_BEM_CHARGESTATISTICSTIMEOUT_BEM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CSD_Timeout_CSD = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CST_Timeout_CST)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BEM_Timeout_CST_Timeout_CST;
        Com_SendSignal(COMCONF_COMSIGNAL_BEM_10NGGJ_BEM_CHARGEABORTTIMEOUT_BEM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CST_Timeout_CST = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CTS_CML_Timeout_CTS_CML)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BEM_Timeout_CTS_CML_Timeout_CTS_CML;
        Com_SendSignal(COMCONF_COMSIGNAL_BEM_10NGGJ_BEM_TIMESYNCORPOWERTIMEOUT_BEM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CTS_CML_Timeout_CTS_CML = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BHM_MaxChargingVoltage_MaxChargingVoltage)
    {
        uint16 phydata_0 = (uint16)Rte_swc_SetSendCANMsg_S_BHM_MaxChargingVoltage_MaxChargingVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BHM_10NGGJ_BHM_ALLOWCHARGEVOLTAGEMAX_BHM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BHM_MaxChargingVoltage_MaxChargingVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason)
    {
        uint16 phydata_0 = (uint16)Rte_swc_SetSendCANMsg_S_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_FASTCHGSTOPINFO_RMXR12_BMS_BMSSTOPCHGERRREASON_BMS_FASTCHGSTOPINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_FASTCHGSTOPINFO_RMXR12_BMS_BMSSTOPCHGFLTREASON_BMS_FASTCHGSTOPINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_BMSStopChgReason_BMS_BMSStopChgReason)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BMS_BMSStopChgReason_BMS_BMSStopChgReason;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_FASTCHGSTOPINFO_RMXR12_BMS_BMSSTOPCHGREASON_BMS_FASTCHGSTOPINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_BMSStopChgReason_BMS_BMSStopChgReason = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason)
    {
        uint16 phydata_0 = (uint16)Rte_swc_SetSendCANMsg_S_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_FASTCHGSTOPINFO_RMXR12_BMS_CCUSTOPCHGERRREASON_BMS_FASTCHGSTOPINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_FASTCHGSTOPINFO_RMXR12_BMS_CCUSTOPCHGFLTREASON_BMS_FASTCHGSTOPINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_CCUStopChgReason_BMS_CCUStopChgReason)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BMS_CCUStopChgReason_BMS_CCUStopChgReason;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_FASTCHGSTOPINFO_RMXR12_BMS_CCUSTOPCHGREASON_BMS_FASTCHGSTOPINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_CCUStopChgReason_BMS_CCUStopChgReason = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BRM_BatterySystemCapacity_BatterySystemCapacity)
    {
        uint16 phydata_0 = (uint16)Rte_swc_SetSendCANMsg_S_BRM_BatterySystemCapacity_BatterySystemCapacity;
        Com_SendSignal(COMCONF_COMSIGNAL_BRM_10NGGJ_BRM_BATTERYSYSTEMRATEDCAPACITY_BRM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BRM_BatterySystemCapacity_BatterySystemCapacity = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BRM_BatterySystemVoltage_BatterySystemVoltage)
    {
        uint16 phydata_0 = (uint16)Rte_swc_SetSendCANMsg_S_BRM_BatterySystemVoltage_BatterySystemVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BRM_10NGGJ_BRM_BATTERYSYSTEMRATEDVOLTAGE_BRM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BRM_BatterySystemVoltage_BatterySystemVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BRM_BatteryType_BatteryType)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BRM_BatteryType_BatteryType;
        Com_SendSignal(COMCONF_COMSIGNAL_BRM_10NGGJ_BRM_BATTERYTYPE_BRM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BRM_BatteryType_BatteryType = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BRO_BmsReadyForCharging_BmsReadyForCharging)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BRO_BmsReadyForCharging_BmsReadyForCharging;
        Com_SendSignal(COMCONF_COMSIGNAL_BRO_10NGGJ_BRO_BMSCHARGEREADY_BRO_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BRO_BmsReadyForCharging_BmsReadyForCharging = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature;
        Com_SendSignal(COMCONF_COMSIGNAL_BSD_10NGGJ_BSD_BATTERYTEMPMAX_BSD_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage)
    {
        uint16 phydata_0 = (uint16)Rte_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BSD_10NGGJ_BSD_BATTERYVOLTAGEMAX_BSD_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature;
        Com_SendSignal(COMCONF_COMSIGNAL_BSD_10NGGJ_BSD_BATTERYTEMPMIN_BSD_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage)
    {
        uint16 phydata_0 = (uint16)Rte_swc_SetSendCANMsg_S_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BSD_10NGGJ_BSD_BATTERYVOLTAGEMIN_BSD_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC;
        Com_SendSignal(COMCONF_COMSIGNAL_BSD_10NGGJ_BSD_ABORTSOC_BSD_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent;
        Com_SendSignal(COMCONF_COMSIGNAL_BSM_10NGGJ_BSM_BATTERYCURRENTSTATE_BSM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryExcessTemperature_BatteryExcessTemperature)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BSM_BatteryExcessTemperature_BatteryExcessTemperature;
        Com_SendSignal(COMCONF_COMSIGNAL_BSM_10NGGJ_BSM_BATTERYTEMPSTATE_BSM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryExcessTemperature_BatteryExcessTemperature = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryHighestTemp_BatteryHighestTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BSM_BatteryHighestTemp_BatteryHighestTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BSM_10NGGJ_BSM_BATTERYTEMPMAX_BSM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryHighestTemp_BatteryHighestTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo;
        Com_SendSignal(COMCONF_COMSIGNAL_BSM_10NGGJ_BSM_BATTERYTEMPMAXNO_BSM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryInsulationState_BatteryInsulationState)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BSM_BatteryInsulationState_BatteryInsulationState;
        Com_SendSignal(COMCONF_COMSIGNAL_BSM_10NGGJ_BSM_INSULATIONSTATE_BSM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryInsulationState_BatteryInsulationState = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryLowestTemp_BatteryLowestTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BSM_BatteryLowestTemp_BatteryLowestTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BSM_10NGGJ_BSM_BATTERYTEMPMIN_BSM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryLowestTemp_BatteryLowestTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo;
        Com_SendSignal(COMCONF_COMSIGNAL_BSM_10NGGJ_BSM_BATTERYTEMPMINNO_BSM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState;
        Com_SendSignal(COMCONF_COMSIGNAL_BSM_10NGGJ_BSM_BATTERYOUTPUCONNECTORSTATE_BSM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BsmChargingPermissible_BsmChargingPermissible)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BSM_BsmChargingPermissible_BsmChargingPermissible;
        Com_SendSignal(COMCONF_COMSIGNAL_BSM_10NGGJ_BSM_CHARGEENABLE_BSM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BsmChargingPermissible_BsmChargingPermissible = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo;
        Com_SendSignal(COMCONF_COMSIGNAL_BSM_10NGGJ_BSM_BATTERYVOLTAGEMAXNO_BSM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BSM_10NGGJ_BSM_BATTERYVOLTAGESTATE_BSM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState;
        Com_SendSignal(COMCONF_COMSIGNAL_BSM_10NGGJ_BSM_SOC_BSM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend;
        Com_SendSignal(COMCONF_COMSIGNAL_BST_10NGGJ_BST_ABORTMANOPERATE_BST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspCause_SOC_BmsSuspCause_SOC)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BST_BmsSuspCause_SOC_BmsSuspCause_SOC;
        Com_SendSignal(COMCONF_COMSIGNAL_BST_10NGGJ_BST_ABORTACHIVESOC_BST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspCause_SOC_BmsSuspCause_SOC = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BST_10NGGJ_BST_ABORTACHIVESINGLEVOLT_BST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BST_10NGGJ_BST_ABORTACHIVETOTALVOLT_BST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BST_10NGGJ_BST_ABORTERRORVOLTAGE_BST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent;
        Com_SendSignal(COMCONF_COMSIGNAL_BST_10NGGJ_BST_ABORTERRORCURRENT_BST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BST_10NGGJ_BST_ABORTFAULTBATTERYTEMP_BST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BST_10NGGJ_BST_ABORTFAULTBMSTEMP_BST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn;
        Com_SendSignal(COMCONF_COMSIGNAL_BST_10NGGJ_BST_ABORTFAULTCONNECTOR_BST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation;
        Com_SendSignal(COMCONF_COMSIGNAL_BST_10NGGJ_BST_ABORTFAULTINSULATION_BST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults;
        Com_SendSignal(COMCONF_COMSIGNAL_BST_10NGGJ_BST_ABORTFAULTOTHER_BST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BST_10NGGJ_BST_ABORTFAULTCONNECTORTEMP_BST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection;
        Com_SendSignal(COMCONF_COMSIGNAL_BST_10NGGJ_BST_ABORTDET2VOLTEXCEPTION_BST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay)
    {
        uint8 phydata_0 = (uint8)Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay;
        Com_SendSignal(COMCONF_COMSIGNAL_BST_10NGGJ_BST_ABORTHVRELAYFAULT_BST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BmsProtocolVersion_BmsProtocolVersion)
    {
        uint32 phydata_0 = (uint32)Rte_swc_SetSendCANMsg_S_BmsProtocolVersion_BmsProtocolVersion;
        Com_SendSignal(COMCONF_COMSIGNAL_BRM_10NGGJ_BRM_PROTOCOLVERSION_BRM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_TX, &phydata_0);
        Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BmsProtocolVersion_BmsProtocolVersion = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_AC_EWP_Heat_AC_EWP_Heat)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_AC_EWP_Heat_AC_EWP_Heat;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HEWP_T34TDK_AC_EWP_HEAT_PMS_HEWP_VE21_N72_PMS_LIN_LDF_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_AC_EWP_Heat_AC_EWP_Heat;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HEWP__XQC0B_AC_EWP_HEAT_PMS_HEWP_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_AC_EWP_Heat_AC_EWP_Heat = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_AC_EWP_HeatrPwrCnsAllwd_AC_EWP_HeatrPwrCnsAllwd)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_AC_EWP_HeatrPwrCnsAllwd_AC_EWP_HeatrPwrCnsAllwd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HEWP_T34TDK_AC_EWP_HEATRPWRCNSALLWD_PMS_HEWP_VE21_N72_PMS_LIN_LDF_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_AC_EWP_HeatrPwrCnsAllwd_AC_EWP_HeatrPwrCnsAllwd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HEWP__XQC0B_AC_EWP_HEATRPWRCNSALLWD_PMS_HEWP_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_AC_EWP_HeatrPwrCnsAllwd_AC_EWP_HeatrPwrCnsAllwd = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_AC_EWP_Run_AC_EWP_Run)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_AC_EWP_Run_AC_EWP_Run;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HEWP_T34TDK_AC_EWP_RUN_PMS_HEWP_VE21_N72_PMS_LIN_LDF_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_AC_EWP_Run_AC_EWP_Run;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HEWP__XQC0B_AC_EWP_RUN_PMS_HEWP_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_AC_EWP_Run_AC_EWP_Run = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_AC_EWP_SpeedReq_AC_EWP_SpeedReq)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_AC_EWP_SpeedReq_AC_EWP_SpeedReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HEWP_T34TDK_AC_EWP_SPEEDREQ_PMS_HEWP_VE21_N72_PMS_LIN_LDF_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_AC_EWP_SpeedReq_AC_EWP_SpeedReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HEWP__XQC0B_AC_EWP_SPEEDREQ_PMS_HEWP_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_AC_EWP_SpeedReq_AC_EWP_SpeedReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_AC_EWP_Temp_AC_EWP_Temp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_AC_EWP_Temp_AC_EWP_Temp;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HEWP_T34TDK_AC_EWP_TEMP_PMS_HEWP_VE21_N72_PMS_LIN_LDF_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_AC_EWP_Temp_AC_EWP_Temp;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HEWP__XQC0B_AC_EWP_TEMP_PMS_HEWP_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_AC_EWP_Temp_AC_EWP_Temp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_ACChgTimeRemain_BMSH_ACChgTimeRemain)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_BMSH_ACChgTimeRemain_BMSH_ACChgTimeRemain;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_BATTERY_CHGSTATE__XQC0B_BMSH_ACCHGTIMEREMAIN_BMSH_BATTERY_CHGSTATE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_ACChgTimeRemain_BMSH_ACChgTimeRemain = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattCurr_BMSH_BattCurr)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_BMSH_BattCurr_BMSH_BattCurr;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURR__XQC0B_BMSH_BATTCURR_BMSH_VOLTCURR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattCurr_BMSH_BattCurr = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattFaultLampState_BMSH_BattFaultLampState)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_BattFaultLampState_BMSH_BattFaultLampState;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_GENERAL_FVS55R_BMSH_BATTFAULTLAMPSTATE_BMSH_GENERAL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_BMSH_BattFaultLampState_BMSH_BattFaultLampState;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_GENERAL__XQC0B_BMSH_BATTFAULTLAMPSTATE_BMSH_GENERAL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattFaultLampState_BMSH_BattFaultLampState = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_BATTPACKNUM_PMS_BMSH_BATTPACKNUM_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_BATTERY_PERFORMANCE__XQC0B_BMSH_BATTPACKNUM_BMSH_BATTERY_PERFORMANCE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_BATTPACKNUM_PMS_BMSH_BATTPACKNUM_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattRemainEnergy_BMSH_BattRemainEnergy)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_BMSH_BattRemainEnergy_BMSH_BattRemainEnergy;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_BATTERY_PERFORMANCE__XQC0B_BMSH_BATTREMAINENERGY_BMSH_BATTERY_PERFORMANCE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattRemainEnergy_BMSH_BattRemainEnergy = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattSOC_BMSH_BattSOC)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_BMSH_BattSOC_BMSH_BattSOC;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_BATTERY_PERFORMANCE__XQC0B_BMSH_BATTSOC_BMSH_BATTERY_PERFORMANCE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattSOC_BMSH_BattSOC = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattSOH_BMSH_BattSOH)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_BattSOH_BMSH_BattSOH;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURR__XQC0B_BMSH_BATTSOH_BMSH_VOLTCURR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattSOH_BMSH_BattSOH = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_BATTSYSNUM_PMS_BMSH_BATTSYSNUM_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_BATTERY_PERFORMANCE__XQC0B_BMSH_BATTSYSNUM_BMSH_BATTERY_PERFORMANCE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_BATTSYSNUM_PMS_BMSH_BATTSYSNUM_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattTempAvg_PT_BMSH_BattTempAvg_PT)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_BattTempAvg_PT_BMSH_BattTempAvg_PT;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CELLTEMPLIMITVALUE__XQC0B_BMSH_BATTTEMPAVG_BMSH_CELLTEMPLIMITVALUE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattTempAvg_PT_BMSH_BattTempAvg_PT = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattVolt_BMSH_BattVolt)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_BMSH_BattVolt_BMSH_BattVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURR__XQC0B_BMSH_BATTVOLT_BMSH_VOLTCURR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattVolt_BMSH_BattVolt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_CellTemp_Uniformity_BMSH_CellTemp_Uniformity)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_BMSH_CellTemp_Uniformity_BMSH_CellTemp_Uniformity;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULTTOGOVERNMENTBACKENDDA__XQC0B_BMSH_CELLTEMP_UNIFORMITY_BMSH_FAULTTOGOVERNMENTBACKENDDA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_CellTemp_Uniformity_BMSH_CellTemp_Uniformity = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_CellVolt_Uniformity_BMSH_CellVolt_Uniformity)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_CellVolt_Uniformity_BMSH_CellVolt_Uniformity;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STS__XQC0B_BMSH_CELLVOLT_UNIFORMITY_BMSH_STS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_CellVolt_Uniformity_BMSH_CellVolt_Uniformity = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Cell_OverVol_BMSH_Cell_OverVol)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_Cell_OverVol_BMSH_Cell_OverVol;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULTTOGOVERNMENTBACKENDDA__XQC0B_BMSH_CELL_OVERVOL_BMSH_FAULTTOGOVERNMENTBACKENDDA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Cell_OverVol_BMSH_Cell_OverVol = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Cell_TotalNum_BMSH_Cell_TotalNum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_Cell_TotalNum_BMSH_Cell_TotalNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_BATTERY_PERFORMANCE__XQC0B_BMSH_CELL_TOTALNUM_BMSH_BATTERY_PERFORMANCE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Cell_TotalNum_BMSH_Cell_TotalNum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Cell_UnderVol_BMSH_Cell_UnderVol)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_Cell_UnderVol_BMSH_Cell_UnderVol;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULTTOGOVERNMENTBACKENDDA__XQC0B_BMSH_CELL_UNDERVOL_BMSH_FAULTTOGOVERNMENTBACKENDDA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Cell_UnderVol_BMSH_Cell_UnderVol = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_ChargeLEDCtrl_BMSH_ChargeLEDCtrl)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_ChargeLEDCtrl_BMSH_ChargeLEDCtrl;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_OBC_CONTROL__XQC0B_BMSH_CHARGELEDCTRL_BMSH_OBC_CONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_ChargeLEDCtrl_BMSH_ChargeLEDCtrl = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_ChargeToBeFinished_BMSH_ChargeToBeFinished)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_BMSH_ChargeToBeFinished_BMSH_ChargeToBeFinished;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_BATTERY_CHGSTATE__XQC0B_BMSH_CHARGETOBEFINISHED_BMSH_BATTERY_CHGSTATE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_ChargeToBeFinished_BMSH_ChargeToBeFinished = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Charge_Over_Current_BMSH_Charge_Over_Current)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_Charge_Over_Current_BMSH_Charge_Over_Current;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULTTOGOVERNMENTBACKENDDA__XQC0B_BMSH_CHARGE_OVER_CURRENT_BMSH_FAULTTOGOVERNMENTBACKENDDA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Charge_Over_Current_BMSH_Charge_Over_Current = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_ChgTimeRemain_BMSH_ChgTimeRemain)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_BMSH_ChgTimeRemain_BMSH_ChgTimeRemain;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_ENERGYSTATISTICSONCE__XQC0B_BMSH_CHGTIMEREMAIN_BMSH_ENERGYSTATISTICSONCE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_ChgTimeRemain_BMSH_ChgTimeRemain = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_DCChgminusSocketTempSensing_Failure_BMSH_DCChgminusSocketTempSensing_Failure)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_DCChgminusSocketTempSensing_Failure_BMSH_DCChgminusSocketTempSensing_Failure;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STS__XQC0B_BMSH_DCCHGMINUSSOCKETTEMPSENSIN_BMSH_STS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_DCChgminusSocketTempSensing_Failure_BMSH_DCChgminusSocketTempSensing_Failure = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_DCChgplusSocketTempSensing_Failure_BMSH_DCChgplusSocketTempSensing_Failure)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_DCChgplusSocketTempSensing_Failure_BMSH_DCChgplusSocketTempSensing_Failure;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_STS__XQC0B_BMSH_DCCHGPLUSSOCKETTEMPSENSING_BMSH_STS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_DCChgplusSocketTempSensing_Failure_BMSH_DCChgplusSocketTempSensing_Failure = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_FastChgCC2ConntState_BMSH_FastChgCC2ConntState)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_FastChgCC2ConntState_BMSH_FastChgCC2ConntState;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_GENERAL__XQC0B_BMSH_FASTCHGCC2CONNTSTATE_BMSH_GENERAL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_FastChgCC2ConntState_BMSH_FastChgCC2ConntState = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_HVBusVolt_BMSH_HVBusVolt)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_BMSH_HVBusVolt_BMSH_HVBusVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURR__XQC0B_BMSH_HVBUSVOLT_BMSH_VOLTCURR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_HVBusVolt_BMSH_HVBusVolt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_HvBattCooltTReq_BMSH_HvBattCooltTReq)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_HvBattCooltTReq_BMSH_HvBattCooltTReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL_RMXR12_BMSH_HVBATTCOOLTTREQ_PMS_TEMP_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_BMSH_HvBattCooltTReq_BMSH_HvBattCooltTReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL__XQC0B_BMSH_HVBATTCOOLTTREQ_PMS_TEMP_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_HvBattCooltTReq_BMSH_HvBattCooltTReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_HvBattThermMod_BMSH_HvBattThermMod)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_HvBattThermMod_BMSH_HvBattThermMod;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL_RMXR12_BMSH_HVBATTTHERMMOD_PMS_TEMP_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_BMSH_HvBattThermMod_BMSH_HvBattThermMod;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL__XQC0B_BMSH_HVBATTTHERMMOD_PMS_TEMP_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_HvBattThermMod_BMSH_HvBattThermMod = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_HvShutdownReq_BMSH_HvShutdownReq)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_BMSH_HvShutdownReq_BMSH_HvShutdownReq;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURR__XQC0B_BMSH_HVSHUTDOWNREQ_BMSH_VOLTCURR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_HvShutdownReq_BMSH_HvShutdownReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_ICU_BatteryElectricDTE_BMSH_ICU_BatteryElectricDTE)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_BMSH_ICU_BatteryElectricDTE_BMSH_ICU_BatteryElectricDTE;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_BATTERY_PERFORMANCE__XQC0B_BMSH_ICU_BATTERYELECTRICDTE_BMSH_BATTERY_PERFORMANCE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_ICU_BatteryElectricDTE_BMSH_ICU_BatteryElectricDTE = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Inlet_WaterTemp_BMSH_Inlet_WaterTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_Inlet_WaterTemp_BMSH_Inlet_WaterTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL_RMXR12_BMSH_INLET_WATERTEMP_PMS_TEMP_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_BMSH_Inlet_WaterTemp_BMSH_Inlet_WaterTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL__XQC0B_BMSH_INLET_WATERTEMP_PMS_TEMP_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Inlet_WaterTemp_BMSH_Inlet_WaterTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_InsulationRes_BMSH_InsulationRes)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_BMSH_InsulationRes_BMSH_InsulationRes;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULTTOGOVERNMENTBACKENDDA__XQC0B_BMSH_INSULATIONRES_BMSH_FAULTTOGOVERNMENTBACKENDDA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_InsulationRes_BMSH_InsulationRes = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_InsulationRes_Fault_BMSH_InsulationRes_Fault)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_InsulationRes_Fault_BMSH_InsulationRes_Fault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULTTOGOVERNMENTBACKENDDA__XQC0B_BMSH_INSULATIONRES_FAULT_BMSH_FAULTTOGOVERNMENTBACKENDDA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_InsulationRes_Fault_BMSH_InsulationRes_Fault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Low_SOC_BMSH_Low_SOC)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_Low_SOC_BMSH_Low_SOC;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULTTOGOVERNMENTBACKENDDA__XQC0B_BMSH_LOW_SOC_BMSH_FAULTTOGOVERNMENTBACKENDDA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Low_SOC_BMSH_Low_SOC = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Outlet_WaterTemp_BMSH_Outlet_WaterTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_Outlet_WaterTemp_BMSH_Outlet_WaterTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL_RMXR12_BMSH_OUTLET_WATERTEMP_PMS_TEMP_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_BMSH_Outlet_WaterTemp_BMSH_Outlet_WaterTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL__XQC0B_BMSH_OUTLET_WATERTEMP_PMS_TEMP_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Outlet_WaterTemp_BMSH_Outlet_WaterTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Over_SOC_BMSH_Over_SOC)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_Over_SOC_BMSH_Over_SOC;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULTTOGOVERNMENTBACKENDDA__XQC0B_BMSH_OVER_SOC_BMSH_FAULTTOGOVERNMENTBACKENDDA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Over_SOC_BMSH_Over_SOC = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Over_Temperature_BMSH_Over_Temperature)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_Over_Temperature_BMSH_Over_Temperature;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULTTOGOVERNMENTBACKENDDA__XQC0B_BMSH_OVER_TEMPERATURE_BMSH_FAULTTOGOVERNMENTBACKENDDA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Over_Temperature_BMSH_Over_Temperature = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Pack_OverVoltage_BMSH_Pack_OverVoltage)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_Pack_OverVoltage_BMSH_Pack_OverVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULTTOGOVERNMENTBACKENDDA__XQC0B_BMSH_PACK_OVERVOLTAGE_BMSH_FAULTTOGOVERNMENTBACKENDDA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Pack_OverVoltage_BMSH_Pack_OverVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Pack_UnderVoltage_BMSH_Pack_UnderVoltage)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_Pack_UnderVoltage_BMSH_Pack_UnderVoltage;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULTTOGOVERNMENTBACKENDDA__XQC0B_BMSH_PACK_UNDERVOLTAGE_BMSH_FAULTTOGOVERNMENTBACKENDDA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Pack_UnderVoltage_BMSH_Pack_UnderVoltage = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_SOC_Hop_BMSH_SOC_Hop)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_BMSH_SOC_Hop_BMSH_SOC_Hop;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_FAULTTOGOVERNMENTBACKENDDA__XQC0B_BMSH_SOC_HOP_BMSH_FAULTTOGOVERNMENTBACKENDDA_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_SOC_Hop_BMSH_SOC_Hop = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatIsoAlarm2_PT_BMSH_TBOX_BatIsoAlarm2_PT)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_BMSH_TBOX_BatIsoAlarm2_PT_BMSH_TBOX_BatIsoAlarm2_PT;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_BMSH_TBOX_BATISOALARM2_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatIsoAlarm2_PT_BMSH_TBOX_BatIsoAlarm2_PT = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATISOALARM3_PMS_BMSH_TBOX_BATISOALARM3_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_BMSH_TBOX_BATISOALARM3_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATISOALARM3_PMS_BMSH_TBOX_BATISOALARM3_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatLowSOC2_PT_BMSH_TBOX_BatLowSOC2_PT)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_BMSH_TBOX_BatLowSOC2_PT_BMSH_TBOX_BatLowSOC2_PT;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_BMSH_TBOX_BATLOWSOC2_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatLowSOC2_PT_BMSH_TBOX_BatLowSOC2_PT = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATLOWSOC3_PMS_BMSH_TBOX_BATLOWSOC3_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_BMSH_TBOX_BATLOWSOC3_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATLOWSOC3_PMS_BMSH_TBOX_BATLOWSOC3_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverCharge2_PT_BMSH_TBOX_BatOverCharge2_PT)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_BMSH_TBOX_BatOverCharge2_PT_BMSH_TBOX_BatOverCharge2_PT;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_BMSH_TBOX_BATOVERCHARGE2_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverCharge2_PT_BMSH_TBOX_BatOverCharge2_PT = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERCHARGE3_PMS_BMSH_TBOX_BATOVERCHARGE3_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_BMSH_TBOX_BATOVERCHARGE3_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERCHARGE3_PMS_BMSH_TBOX_BATOVERCHARGE3_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverSOC2_PT_BMSH_TBOX_BatOverSOC2_PT)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_BMSH_TBOX_BatOverSOC2_PT_BMSH_TBOX_BatOverSOC2_PT;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_BMSH_TBOX_BATOVERSOC2_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverSOC2_PT_BMSH_TBOX_BatOverSOC2_PT = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERSOC3_PMS_BMSH_TBOX_BATOVERSOC3_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_BMSH_TBOX_BATOVERSOC3_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERSOC3_PMS_BMSH_TBOX_BATOVERSOC3_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverTemp2_PT_BMSH_TBOX_BatOverTemp2_PT)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_BMSH_TBOX_BatOverTemp2_PT_BMSH_TBOX_BatOverTemp2_PT;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_BMSH_TBOX_BATOVERTEMP2_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverTemp2_PT_BMSH_TBOX_BatOverTemp2_PT = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERTEMP3_PMS_BMSH_TBOX_BATOVERTEMP3_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_BMSH_TBOX_BATOVERTEMP3_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERTEMP3_PMS_BMSH_TBOX_BATOVERTEMP3_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverVoltage2_PT_BMSH_TBOX_BatOverVoltage2_PT)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_BMSH_TBOX_BatOverVoltage2_PT_BMSH_TBOX_BatOverVoltage2_PT;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_BMSH_TBOX_BATOVERVOLTAGE2_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverVoltage2_PT_BMSH_TBOX_BatOverVoltage2_PT = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERVOLTAGE3_PMS_BMSH_TBOX_BATOVERVOLTAGE3_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_BMSH_TBOX_BATOVERVOLTAGE3_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERVOLTAGE3_PMS_BMSH_TBOX_BATOVERVOLTAGE3_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatTempUniformity2_PT_BMSH_TBOX_BatTempUniformity2_PT)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_BMSH_TBOX_BatTempUniformity2_PT_BMSH_TBOX_BatTempUniformity2_PT;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_BMSH_TBOX_BATTEMPUNIFORMITY2_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatTempUniformity2_PT_BMSH_TBOX_BatTempUniformity2_PT = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATTEMPUNIFORMITY3_PMS_BMSH_TBOX_BATTEMPUNIFORMITY3_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_BMSH_TBOX_BATTEMPUNIFORMITY3_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATTEMPUNIFORMITY3_PMS_BMSH_TBOX_BATTEMPUNIFORMITY3_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatUnderVoltage2_PT_BMSH_TBOX_BatUnderVoltage2_PT)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_BMSH_TBOX_BatUnderVoltage2_PT_BMSH_TBOX_BatUnderVoltage2_PT;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_BMSH_TBOX_BATUNDERVOLTAGE2_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatUnderVoltage2_PT_BMSH_TBOX_BatUnderVoltage2_PT = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATUNDERVOLTAGE3_PMS_BMSH_TBOX_BATUNDERVOLTAGE3_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_BMSH_TBOX_BATUNDERVOLTAGE3_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATUNDERVOLTAGE3_PMS_BMSH_TBOX_BATUNDERVOLTAGE3_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatUniformity2_PT_BMSH_TBOX_BatUniformity2_PT)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_BMSH_TBOX_BatUniformity2_PT_BMSH_TBOX_BatUniformity2_PT;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_BMSH_TBOX_BATUNIFORMITY2_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatUniformity2_PT_BMSH_TBOX_BatUniformity2_PT = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATUNIFORMITY3_PMS_BMSH_TBOX_BATUNIFORMITY3_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_BMSH_TBOX_BATUNIFORMITY3_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATUNIFORMITY3_PMS_BMSH_TBOX_BATUNIFORMITY3_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_CellOverVoltage2_PT_BMSH_TBOX_CellOverVoltage2_PT)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_BMSH_TBOX_CellOverVoltage2_PT_BMSH_TBOX_CellOverVoltage2_PT;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_BMSH_TBOX_CELLOVERVOLTAGE2_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_CellOverVoltage2_PT_BMSH_TBOX_CellOverVoltage2_PT = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_CELLOVERVOLTAGE3_PMS_BMSH_TBOX_CELLOVERVOLTAGE3_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_BMSH_TBOX_CELLOVERVOLTAGE3_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_CELLOVERVOLTAGE3_PMS_BMSH_TBOX_CELLOVERVOLTAGE3_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_CellUnderVoltage2_PT_BMSH_TBOX_CellUnderVoltage2_PT)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_BMSH_TBOX_CellUnderVoltage2_PT_BMSH_TBOX_CellUnderVoltage2_PT;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_BMSH_TBOX_CELLUNDERVOLTAGE2_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_CellUnderVoltage2_PT_BMSH_TBOX_CellUnderVoltage2_PT = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_CELLUNDERVOLTAGE3_PMS_BMSH_TBOX_CELLUNDERVOLTAGE3_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_BMSH_TBOX_CELLUNDERVOLTAGE3_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_CELLUNDERVOLTAGE3_PMS_BMSH_TBOX_CELLUNDERVOLTAGE3_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_FIREALARM2_PMS_BMSH_TBOX_FIREALARM2_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_BMSH_TBOX_FIREALARM2_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_FIREALARM2_PMS_BMSH_TBOX_FIREALARM2_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_SOCHop2_PT_BMSH_TBOX_SOCHop2_PT)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_BMSH_TBOX_SOCHop2_PT_BMSH_TBOX_SOCHop2_PT;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_BMSH_TBOX_SOCHOP2_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_SOCHop2_PT_BMSH_TBOX_SOCHop2_PT = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_SOCHOP3_PMS_BMSH_TBOX_SOCHOP3_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_BMSH_TBOX_SOCHOP3_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_SOCHOP3_PMS_BMSH_TBOX_SOCHOP3_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TempSensor_MaxTemp_BMSH_TempSensor_MaxTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_TempSensor_MaxTemp_BMSH_TempSensor_MaxTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CELLTEMPLIMITVALUE__XQC0B_BMSH_TEMPSENSOR_MAXTEMP_BMSH_CELLTEMPLIMITVALUE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TempSensor_MaxTemp_BMSH_TempSensor_MaxTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TempSensor_MinTemp_BMSH_TempSensor_MinTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_TempSensor_MinTemp_BMSH_TempSensor_MinTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CELLTEMPLIMITVALUE__XQC0B_BMSH_TEMPSENSOR_MINTEMP_BMSH_CELLTEMPLIMITVALUE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TempSensor_MinTemp_BMSH_TempSensor_MinTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TempSensor_TotalNum_BMSH_TempSensor_TotalNum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_TempSensor_TotalNum_BMSH_TempSensor_TotalNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CELLTEMPLIMITVALUE__XQC0B_BMSH_TEMPSENSOR_TOTALNUM_BMSH_CELLTEMPLIMITVALUE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TempSensor_TotalNum_BMSH_TempSensor_TotalNum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_ThermalOutofControl_BMSH_ThermalOutofControl)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_BMSH_ThermalOutofControl_BMSH_ThermalOutofControl;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_BATTERY_CHGSTATE__XQC0B_BMSH_THERMALOUTOFCONTROL_BMSH_BATTERY_CHGSTATE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_ThermalOutofControl_BMSH_ThermalOutofControl = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Vehicle_HVILSts_PHEV_BMSH_Vehicle_HVILSts_PHEV)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_BMSH_Vehicle_HVILSts_PHEV_BMSH_Vehicle_HVILSts_PHEV;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_GENERAL__XQC0B_BMSH_VEHICLE_HVILSTS_PHEV_BMSH_GENERAL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Vehicle_HVILSts_PHEV_BMSH_Vehicle_HVILSts_PHEV = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_VoltCurr_Checksum_BMSH_VoltCurr_Checksum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_VoltCurr_Checksum_BMSH_VoltCurr_Checksum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURRENT_RMXR12_BMSH_VOLTCURRENT_CHECKSUM_BMSH_VOLTCURRENT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_BMSH_VoltCurr_Checksum_BMSH_VoltCurr_Checksum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURR__XQC0B_BMSH_VOLTCURR_CHECKSUM_BMSH_VOLTCURR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_BMSH_VoltCurr_Checksum_BMSH_VoltCurr_Checksum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_VOLTCURRENT__XQC0B_BMSH_VOLTCURRENT_CHECKSUM_BMSH_VOLTCURRENT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_VoltCurr_Checksum_BMSH_VoltCurr_Checksum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_stMode_BMSH_stMode)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMSH_stMode_BMSH_stMode;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_GENERAL__XQC0B_BMSH_STMODE_BMSH_GENERAL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_stMode_BMSH_stMode = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_BattPackMatchFault_BMS_BattPackMatchFault)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMS_BattPackMatchFault_BMS_BattPackMatchFault;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_TBOX_FAULT2_RMXR12_BMS_BATTPACKMATCHFAULT_BMSH_TBOX_FAULT2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_BMS_BattPackMatchFault_BMS_BattPackMatchFault;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_BMS_BATTPACKMATCHFAULT_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_BattPackMatchFault_BMS_BattPackMatchFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMS_BATTPACKMATCHFAULT1_PMS_BMS_BATTPACKMATCHFAULT1_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_BMS_BATTPACKMATCHFAULT1_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMS_BATTPACKMATCHFAULT1_PMS_BMS_BATTPACKMATCHFAULT1_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_MaxCellVolt_BMS_MaxCellVolt)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_BMS_MaxCellVolt_BMS_MaxCellVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_MIN_MAX_CELLVOLT__XQC0B_BMS_MAXCELLVOLT_BMS_MIN_MAX_CELLVOLT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_MaxCellVolt_BMS_MaxCellVolt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_MaxTemp1SnsNum_BMS_MaxTemp1SnsNum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMS_MaxTemp1SnsNum_BMS_MaxTemp1SnsNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CELLTEMPLIMITVALUE__XQC0B_BMS_MAXTEMP1SNSNUM_BMSH_CELLTEMPLIMITVALUE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_MaxTemp1SnsNum_BMS_MaxTemp1SnsNum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_MaxVoltCellNum_BMS_MaxVoltCellNum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMS_MaxVoltCellNum_BMS_MaxVoltCellNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_MIN_MAX_CELLVOLT__XQC0B_BMS_MAXVOLTCELLNUM_BMS_MIN_MAX_CELLVOLT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_MaxVoltCellNum_BMS_MaxVoltCellNum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_MinCellVolt_BMS_MinCellVolt)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_BMS_MinCellVolt_BMS_MinCellVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_MIN_MAX_CELLVOLT__XQC0B_BMS_MINCELLVOLT_BMS_MIN_MAX_CELLVOLT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_MinCellVolt_BMS_MinCellVolt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_MinVoltCellNum_BMS_MinVoltCellNum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMS_MinVoltCellNum_BMS_MinVoltCellNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMS_MIN_MAX_CELLVOLT__XQC0B_BMS_MINVOLTCELLNUM_BMS_MIN_MAX_CELLVOLT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_MinVoltCellNum_BMS_MinVoltCellNum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_MinxTemp1SnsNum_BMS_MinxTemp1SnsNum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_BMS_MinxTemp1SnsNum_BMS_MinxTemp1SnsNum;
        Com_SendSignal(COMCONF_COMSIGNAL_BMSH_CELLTEMPLIMITVALUE__XQC0B_BMS_MINXTEMP1SNSNUM_BMSH_CELLTEMPLIMITVALUE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_MinxTemp1SnsNum_BMS_MinxTemp1SnsNum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_DrvPfmncRedn_DrvPfmncRedn)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_DrvPfmncRedn_DrvPfmncRedn;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_IPK_STATUS__XQC0B_DRVPFMNCREDN_PMS_IPK_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_DrvPfmncRedn_DrvPfmncRedn = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_EDCP_Flt_EDCP_Flt)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_EDCP_Flt_EDCP_Flt;
        Com_SendSignal(COMCONF_COMSIGNAL_EDCP_STATUS__XQC0B_EDCP_FLT_EDCP_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_EDCP_Flt_EDCP_Flt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_EDCP_PWMFB_EDCP_PWMFB)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_EDCP_PWMFB_EDCP_PWMFB;
        Com_SendSignal(COMCONF_COMSIGNAL_EDCP_STATUS__XQC0B_EDCP_PWMFB_EDCP_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_EDCP_PWMFB_EDCP_PWMFB = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_HBCP_Flt_HBCP_Flt)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_HBCP_Flt_HBCP_Flt;
        Com_SendSignal(COMCONF_COMSIGNAL_HBCP_STATUS__XQC0B_HBCP_FLT_HBCP_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_HBCP_Flt_HBCP_Flt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_HBCP_PWMFB_HBCP_PWMFB)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_HBCP_PWMFB_HBCP_PWMFB;
        Com_SendSignal(COMCONF_COMSIGNAL_HBCP_STATUS__XQC0B_HBCP_PWMFB_HBCP_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_HBCP_PWMFB_HBCP_PWMFB = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPK_IPKTotalOdometer_EV_IPK_IPKTotalOdometer_EV)
    {
        uint32 phydata_0 = (uint32)Rte_swc_VCOP_IPK_IPKTotalOdometer_EV_IPK_IPKTotalOdometer_EV;
        Com_SendSignal(COMCONF_COMSIGNAL_IPK_TOTALODOMETER_RMXR12_IPK_IPKTOTALODOMETER_IPK_TOTALODOMETER_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPK_IPKTotalOdometer_EV_IPK_IPKTotalOdometer_EV = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_HVBusCur_PT_IPU_HVBusCur_PT)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_IPU_HVBusCur_PT_IPU_HVBusCur_PT;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_WARNING__XQC0B_IPU_HVBUSCUR_IPU_WARNING_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_HVBusCur_PT_IPU_HVBusCur_PT = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_HVBusVolt_PT_IPU_HVBusVolt_PT)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_IPU_HVBusVolt_PT_IPU_HVBusVolt_PT;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_WARNING__XQC0B_IPU_HVBUSVOLT_IPU_WARNING_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_HVBusVolt_PT_IPU_HVBusVolt_PT = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_IPUTAlm_IPU_IPUTAlm)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_IPU_IPUTAlm_IPU_IPUTAlm;
        Com_SendSignal(COMCONF_COMSIGNAL_IPU_WARNING__XQC0B_IPU_IPUTALM_IPU_WARNING_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_IPUTAlm_IPU_IPUTAlm = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_MCUTempHighAlarm1_PT_IPU_MCUTempHighAlarm1_PT)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_IPU_MCUTempHighAlarm1_PT_IPU_MCUTempHighAlarm1_PT;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_IPU_MCUTEMPHIGHALARM1_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_MCUTempHighAlarm1_PT_IPU_MCUTempHighAlarm1_PT = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_IPU_MCUTEMPHIGHALARM2_PMS_IPU_MCUTEMPHIGHALARM2_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_IPU_MCUTEMPHIGHALARM2_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_IPU_MCUTEMPHIGHALARM2_PMS_IPU_MCUTEMPHIGHALARM2_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_IPU_MOTOROVERCURRFLT1_PMS_IPU_MOTOROVERCURRFLT1_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_IPU_MOTOROVERCURRFLT1_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_IPU_MOTOROVERCURRFLT1_PMS_IPU_MOTOROVERCURRFLT1_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_IPU_MOTOROVERSPDFLT1_PMS_IPU_MOTOROVERSPDFLT1_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_IPU_MOTOROVERSPDFLT1_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_IPU_MOTOROVERSPDFLT1_PMS_IPU_MOTOROVERSPDFLT1_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_MotorTempHighFault1_PT_IPU_MotorTempHighFault1_PT)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_IPU_MotorTempHighFault1_PT_IPU_MotorTempHighFault1_PT;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_IPU_MOTORTEMPHIGHFAULT1_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_MotorTempHighFault1_PT_IPU_MotorTempHighFault1_PT = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_IPU_MOTORTEMPHIGHFAULT2_PMS_IPU_MOTORTEMPHIGHFAULT2_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_IPU_MOTORTEMPHIGHFAULT2_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_IPU_MOTORTEMPHIGHFAULT2_PMS_IPU_MOTORTEMPHIGHFAULT2_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_CCWFlg_PMS_MHGV_CCWFlg_PMS)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_MHGV_CCWFlg_PMS_MHGV_CCWFlg_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_MHGV_STATUS__XQC0B_MHGV_CCWFLG_MHGV_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_CCWFlg_PMS_MHGV_CCWFlg_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_CurrentPos_PMS_MHGV_CurrentPos_PMS)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_MHGV_CurrentPos_PMS_MHGV_CurrentPos_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_MHGV_STATUS__XQC0B_MHGV_CURRENTPOS_MHGV_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_CurrentPos_PMS_MHGV_CurrentPos_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_InitState_PMS_MHGV_InitState_PMS)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_MHGV_InitState_PMS_MHGV_InitState_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_MHGV_STATUS__XQC0B_MHGV_INITSTATE_MHGV_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_InitState_PMS_MHGV_InitState_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_MotorState_PMS_MHGV_MotorState_PMS)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_MHGV_MotorState_PMS_MHGV_MotorState_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_MHGV_STATUS__XQC0B_MHGV_MOTORSTATE_MHGV_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_MotorState_PMS_MHGV_MotorState_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_OverCurrentFlt_PMS_MHGV_OverCurrentFlt_PMS)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_MHGV_OverCurrentFlt_PMS_MHGV_OverCurrentFlt_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_MHGV_STATUS__XQC0B_MHGV_OVERCURRENTFLT_MHGV_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_OverCurrentFlt_PMS_MHGV_OverCurrentFlt_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_OverTempFlt_PMS_MHGV_OverTempFlt_PMS)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_MHGV_OverTempFlt_PMS_MHGV_OverTempFlt_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_MHGV_STATUS__XQC0B_MHGV_OVERTEMPFLT_MHGV_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_OverTempFlt_PMS_MHGV_OverTempFlt_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_OverVoltageFlt_PMS_MHGV_OverVoltageFlt_PMS)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_MHGV_OverVoltageFlt_PMS_MHGV_OverVoltageFlt_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_MHGV_STATUS__XQC0B_MHGV_OVERVOLTAGEFLT_MHGV_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_OverVoltageFlt_PMS_MHGV_OverVoltageFlt_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_RESP_ERROR_PMS_MHGV_RESP_ERROR_PMS)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_MHGV_RESP_ERROR_PMS_MHGV_RESP_ERROR_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_MHGV_STATUS__XQC0B_MHGV_RESP_ERROR_MHGV_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_RESP_ERROR_PMS_MHGV_RESP_ERROR_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_UnderVoltageFlt_PMS_MHGV_UnderVoltageFlt_PMS)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_MHGV_UnderVoltageFlt_PMS_MHGV_UnderVoltageFlt_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_MHGV_STATUS__XQC0B_MHGV_UNDERVOLTAGEFLT_MHGV_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_UnderVoltageFlt_PMS_MHGV_UnderVoltageFlt_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_ODP_TBOX_DcDcStsAlm_ODP_TBOX_DcDcStsAlm)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_ODP_TBOX_DcDcStsAlm_ODP_TBOX_DcDcStsAlm;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_ODP_TBOX_DCDCSTSALM_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_ODP_TBOX_DcDcStsAlm_ODP_TBOX_DcDcStsAlm = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_ODP_TBOX_DCDCSTSALM1_PMS_ODP_TBOX_DCDCSTSALM1_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_ODP_TBOX_DCDCSTSALM1_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_ODP_TBOX_DCDCSTSALM1_PMS_ODP_TBOX_DCDCSTSALM1_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_ODP_TBOX_TDcDcAlm_ODP_TBOX_TDcDcAlm)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_ODP_TBOX_TDcDcAlm_ODP_TBOX_TDcDcAlm;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_ODP_TBOX_TDCDCALM_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_ODP_TBOX_TDcDcAlm_ODP_TBOX_TDcDcAlm = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_ODP_TBOX_TDCDCALM1_PMS_ODP_TBOX_TDCDCALM1_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_ODP_TBOX_TDCDCALM1_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_ODP_TBOX_TDCDCALM1_PMS_ODP_TBOX_TDCDCALM1_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_0X16A_TimeoutFlag_PMS_0X16A_TimeoutFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_0X16A_TimeoutFlag_PMS_0X16A_TimeoutFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_RMXR12_PMS_0X16A_TIMEOUTFLAG_PMS_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_0X16A_TimeoutFlag_PMS_0X16A_TimeoutFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_FVS55R_PMS_0X16A_TIMEOUTFLAG_PMS_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_0X16A_TimeoutFlag_PMS_0X16A_TimeoutFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL__XQC0B_PMS_0X16A_TIMEOUTFLAG_PMS_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_0X16A_TimeoutFlag_PMS_0X16A_TimeoutFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_32960FLTNUM_PMS_PMS_32960FLTNUM_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_PMS_32960FLTNUM_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_32960FLTNUM_PMS_PMS_32960FLTNUM_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ACC1PosVol_PMS_ACC1PosVol)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_ACC1PosVol_PMS_ACC1PosVol;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR1_RMXR12_PMS_ACC1POSVOL_PMS_HARDINFOR1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_ACC1PosVol_PMS_ACC1PosVol;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR1__XQC0B_PMS_ACC1POSVOL_PMS_HARDINFOR1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ACC1PosVol_PMS_ACC1PosVol = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ACC2PosVol_PMS_ACC2PosVol)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_ACC2PosVol_PMS_ACC2PosVol;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR1_RMXR12_PMS_ACC2POSVOL_PMS_HARDINFOR1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_ACC2PosVol_PMS_ACC2PosVol;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR1__XQC0B_PMS_ACC2POSVOL_PMS_HARDINFOR1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ACC2PosVol_PMS_ACC2PosVol = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ACCMEnable_PMS_ACCMEnable)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_ACCMEnable_PMS_ACCMEnable;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL_RMXR12_PMS_ACCMENABLE_PMS_TEMP_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_ACCMEnable_PMS_ACCMEnable;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL__XQC0B_PMS_ACCMENABLE_PMS_TEMP_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ACCMEnable_PMS_ACCMEnable = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ACC_BeControlled_Status_PMS_ACC_BeControlled_Status)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_ACC_BeControlled_Status_PMS_ACC_BeControlled_Status;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_RMXR12_PMS_ACC_BECONTROLLED_STATUS_PMS_MODECONTROL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_ACC_BeControlled_Status_PMS_ACC_BeControlled_Status;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_FVS55R_PMS_ACC_BECONTROLLED_STATUS_PMS_MODECONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_ACC_BeControlled_Status_PMS_ACC_BeControlled_Status;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL__XQC0B_PMS_ACC_BECONTROLLED_STATUS_PMS_MODECONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ACC_BeControlled_Status_PMS_ACC_BeControlled_Status = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AcceRelayVoltSampSwich_PMS_AcceRelayVoltSampSwich)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_AcceRelayVoltSampSwich_PMS_AcceRelayVoltSampSwich;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_RELAYSAMPSWICH_LGFZID_PMS_ACCERELAYVOLTSAMPSWICH_PMS_RELAYSAMPSWICH_N72_HCM__MATRIX_V1_1_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AcceRelayVoltSampSwich_PMS_AcceRelayVoltSampSwich = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AcceSuppressionSts_PMS_PMS_AcceSuppressionSts_PMS)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_AcceSuppressionSts_PMS_PMS_AcceSuppressionSts_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_INSTRUCT__XQC0B_PMS_ACCESUPPRESSIONSTS_PMS_INSTRUCT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AcceSuppressionSts_PMS_PMS_AcceSuppressionSts_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AccelPedalPosition_PMS_AccelPedalPosition)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_AccelPedalPosition_PMS_AccelPedalPosition;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2_FVS55R_PMS_ACCELPEDALPOSITION_PMS_CSCONTROL2_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_AccelPedalPosition_PMS_AccelPedalPosition;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2__XQC0B_PMS_ACCELPEDALPOSITION_PMS_CSCONTROL2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AccelPedalPosition_PMS_AccelPedalPosition = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AccelPedalPositionInvalid_PMS_AccelPedalPositionInvalid)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_AccelPedalPositionInvalid_PMS_AccelPedalPositionInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2_FVS55R_PMS_ACCELPEDALPOSITIONINVALID_PMS_CSCONTROL2_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_AccelPedalPositionInvalid_PMS_AccelPedalPositionInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2__XQC0B_PMS_ACCELPEDALPOSITIONINVALID_PMS_CSCONTROL2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AccelPedalPositionInvalid_PMS_AccelPedalPositionInvalid = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Acceleration_PMS_Acceleration)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_Acceleration_PMS_Acceleration;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR1_RMXR12_PMS_ACCELERATION_PMS_HARDINFOR1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_Acceleration_PMS_Acceleration;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR1__XQC0B_PMS_ACCELERATION_PMS_HARDINFOR1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Acceleration_PMS_Acceleration = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AccessoryConnStsFb_PMS_AccessoryConnStsFb)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_AccessoryConnStsFb_PMS_AccessoryConnStsFb;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2_RMXR12_PMS_ACCESSORYCONNSTSFB_PMS_HARDINFOR2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_AccessoryConnStsFb_PMS_AccessoryConnStsFb;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2__XQC0B_PMS_ACCESSORYCONNSTSFB_PMS_HARDINFOR2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AccessoryConnStsFb_PMS_AccessoryConnStsFb = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AccessoryCtrlCommand_PMS_AccessoryCtrlCommand)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_AccessoryCtrlCommand_PMS_AccessoryCtrlCommand;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_RMXR12_PMS_ACCESSORYCTRLCOMMAND_PMS_CTRL1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_AccessoryCtrlCommand_PMS_AccessoryCtrlCommand;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_FVS55R_PMS_ACCESSORYCTRLCOMMAND_PMS_CTRL1_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_AccessoryCtrlCommand_PMS_AccessoryCtrlCommand;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1__XQC0B_PMS_ACCESSORYCTRLCOMMAND_PMS_CTRL1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AccessoryCtrlCommand_PMS_AccessoryCtrlCommand = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AccessoryRelayFlt_PMS_AccessoryRelayFlt)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_AccessoryRelayFlt_PMS_AccessoryRelayFlt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2_RMXR12_PMS_ACCESSORYRELAYFLT_PMS_HARDINFOR2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_AccessoryRelayFlt_PMS_AccessoryRelayFlt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2__XQC0B_PMS_ACCESSORYRELAYFLT_PMS_HARDINFOR2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AccessoryRelayFlt_PMS_AccessoryRelayFlt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ActualPTTorque_PMS_ActualPTTorque)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_PMS_ActualPTTorque_PMS_ActualPTTorque;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL_FVS55R_PMS_ACTUALPTTORQUE_PMS_ENGCONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_VCOP_PMS_ActualPTTorque_PMS_ActualPTTorque;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL__XQC0B_PMS_ACTUALPTTORQUE_PMS_ENGCONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ActualPTTorque_PMS_ActualPTTorque = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ActualPTTorqueInvalid_PMS_ActualPTTorqueInvalid)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_ActualPTTorqueInvalid_PMS_ActualPTTorqueInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL_FVS55R_PMS_ACTUALPTTORQUEINVALID_PMS_ENGCONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_ActualPTTorqueInvalid_PMS_ActualPTTorqueInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL__XQC0B_PMS_ACTUALPTTORQUEINVALID_PMS_ENGCONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ActualPTTorqueInvalid_PMS_ActualPTTorqueInvalid = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AppSts_PMS_AppSts)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_AppSts_PMS_AppSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR1_RMXR12_PMS_APPSTS_PMS_HARDINFOR1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_AppSts_PMS_AppSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_LOCKVEHINFOR__XQC0B_PMS_APPSTS_PMS_LOCKVEHINFOR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_AppSts_PMS_AppSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR1__XQC0B_PMS_APPSTS_PMS_HARDINFOR1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AppSts_PMS_AppSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AuthResult_PMS_AuthResult)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_AuthResult_PMS_AuthResult;
//        Com_SendSignal(COMCONF_COMSIGNAL_PMS_AUTH__XQC0B_PMS_AUTHRESULT_PMS_AUTH_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AuthResult_PMS_AuthResult = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AveragePowerConsumption_PMS_AveragePowerConsumption)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_PMS_AveragePowerConsumption_PMS_AveragePowerConsumption;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_INFORCAN__XQC0B_PMS_AVERAGEPOWERCONSUMPTION_PMS_INFORCAN_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AveragePowerConsumption_PMS_AveragePowerConsumption = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BBM1CtrlCmd_PMS_BBM1CtrlCmd)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_BBM1CtrlCmd_PMS_BBM1CtrlCmd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_RMXR12_PMS_BBM1CTRLCMD_PMS_CTRL1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_BBM1CtrlCmd_PMS_BBM1CtrlCmd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_FVS55R_PMS_BBM1CTRLCMD_PMS_CTRL1_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_BBM1CtrlCmd_PMS_BBM1CtrlCmd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1__XQC0B_PMS_BBM1CTRLCMD_PMS_CTRL1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BBM1CtrlCmd_PMS_BBM1CtrlCmd = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BBMAllowEnable_Ctrl_PMS_BBMAllowEnable_Ctrl)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_BBMAllowEnable_Ctrl_PMS_BBMAllowEnable_Ctrl;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6_RMXR12_PMS_BBMALLOWENABLE_CTRL_PMS_HARDINFOR6_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_BBMAllowEnable_Ctrl_PMS_BBMAllowEnable_Ctrl;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6__XQC0B_PMS_BBMALLOWENABLE_CTRL_PMS_HARDINFOR6_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BBMAllowEnable_Ctrl_PMS_BBMAllowEnable_Ctrl = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BBMPowerSupplyEn_Ctrl_PMS_BBMPowerSupplyEn_Ctrl)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_BBMPowerSupplyEn_Ctrl_PMS_BBMPowerSupplyEn_Ctrl;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6_RMXR12_PMS_BBMPOWERSUPPLYEN_CTRL_PMS_HARDINFOR6_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_BBMPowerSupplyEn_Ctrl_PMS_BBMPowerSupplyEn_Ctrl;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6__XQC0B_PMS_BBMPOWERSUPPLYEN_CTRL_PMS_HARDINFOR6_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BBMPowerSupplyEn_Ctrl_PMS_BBMPowerSupplyEn_Ctrl = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BBM_FaultStatus_PMS_BBM_FaultStatus)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_BBM_FaultStatus_PMS_BBM_FaultStatus;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6_RMXR12_PMS_BBM_FAULTSTATUS_PMS_HARDINFOR6_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_BBM_FaultStatus_PMS_BBM_FaultStatus;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6__XQC0B_PMS_BBM_FAULTSTATUS_PMS_HARDINFOR6_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BBM_FaultStatus_PMS_BBM_FaultStatus = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BBM_HVReq_PMS_BBM_HVReq)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_BBM_HVReq_PMS_BBM_HVReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6_RMXR12_PMS_BBM_HVREQ_PMS_HARDINFOR6_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_BBM_HVReq_PMS_BBM_HVReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6__XQC0B_PMS_BBM_HVREQ_PMS_HARDINFOR6_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BBM_HVReq_PMS_BBM_HVReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BBM_WorkSts_PMS_BBM_WorkSts)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_BBM_WorkSts_PMS_BBM_WorkSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6_RMXR12_PMS_BBM_WORKSTS_PMS_HARDINFOR6_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_BBM_WorkSts_PMS_BBM_WorkSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6__XQC0B_PMS_BBM_WORKSTS_PMS_HARDINFOR6_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BBM_WorkSts_PMS_BBM_WorkSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BMSH_BattRemainEnergy_PMS_BMSH_BattRemainEnergy)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_PMS_BMSH_BattRemainEnergy_PMS_BMSH_BattRemainEnergy;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_STS_RMXR12_PMS_BMSH_BATTREMAINENERGY_PMS_BMSH_STS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BMSH_BattRemainEnergy_PMS_BMSH_BattRemainEnergy = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BMSH_BattSOCDisp_PMS_BMSH_BattSOCDisp)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_PMS_BMSH_BattSOCDisp_PMS_BMSH_BattSOCDisp;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_INFO_RMXR12_PMS_BMSH_BATTSOCDISP_PMS_BMSH_INFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BMSH_BattSOCDisp_PMS_BMSH_BattSOCDisp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BMSH_BattSOH_PMS_BMSH_BattSOH)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_PMS_BMSH_BattSOH_PMS_BMSH_BattSOH;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_STS_RMXR12_PMS_BMSH_BATTSOH_PMS_BMSH_STS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BMSH_BattSOH_PMS_BMSH_BattSOH = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BMS_Reignstatus1_PMS_BMS_Reignstatus1)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_BMS_Reignstatus1_PMS_BMS_Reignstatus1;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_RMXR12_PMS_BMS_REIGNSTATUS1_PMS_MODECONTROL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_BMS_Reignstatus1_PMS_BMS_Reignstatus1;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_FVS55R_PMS_BMS_REIGNSTATUS1_PMS_MODECONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_BMS_Reignstatus1_PMS_BMS_Reignstatus1;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL__XQC0B_PMS_BMS_REIGNSTATUS1_PMS_MODECONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BMS_Reignstatus1_PMS_BMS_Reignstatus1 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BMS_Reignstatus2_PMS_BMS_Reignstatus2)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_BMS_Reignstatus2_PMS_BMS_Reignstatus2;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_RMXR12_PMS_BMS_REIGNSTATUS2_PMS_MODECONTROL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_BMS_Reignstatus2_PMS_BMS_Reignstatus2;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_FVS55R_PMS_BMS_REIGNSTATUS2_PMS_MODECONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_BMS_Reignstatus2_PMS_BMS_Reignstatus2;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL__XQC0B_PMS_BMS_REIGNSTATUS2_PMS_MODECONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BMS_Reignstatus2_PMS_BMS_Reignstatus2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BatCoolType_PMS_BatCoolType)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_BatCoolType_PMS_BatCoolType;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_RMXR12_PMS_BATCOOLTYPE_PMS_CTRL1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_BatCoolType_PMS_BatCoolType;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_FVS55R_PMS_BATCOOLTYPE_PMS_CTRL1_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_BatCoolType_PMS_BatCoolType;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1__XQC0B_PMS_BATCOOLTYPE_PMS_CTRL1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BatCoolType_PMS_BatCoolType = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BattPackInCoolTempback_EV_PMS_BattPackInCoolTempback_EV)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_BattPackInCoolTempback_EV_PMS_BattPackInCoolTempback_EV;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR5_RMXR12_PMS_BATTPACKINCOOLTEMPBACK_PMS_HARDINFOR5_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_BattPackInCoolTempback_EV_PMS_BattPackInCoolTempback_EV;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR5__XQC0B_PMS_BATTPACKINCOOLTEMPBACK_PMS_HARDINFOR5_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BattPackInCoolTempback_EV_PMS_BattPackInCoolTempback_EV = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BattPackOutCoolTempback_EV_PMS_BattPackOutCoolTempback_EV)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_BattPackOutCoolTempback_EV_PMS_BattPackOutCoolTempback_EV;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR5_RMXR12_PMS_BATTPACKOUTCOOLTEMPBACK_PMS_HARDINFOR5_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_BattPackOutCoolTempback_EV_PMS_BattPackOutCoolTempback_EV;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR5__XQC0B_PMS_BATTPACKOUTCOOLTEMPBACK_PMS_HARDINFOR5_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BattPackOutCoolTempback_EV_PMS_BattPackOutCoolTempback_EV = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BatteryVol_PMS_BatteryVol)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_BatteryVol_PMS_BatteryVol;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR1_RMXR12_PMS_BATTERYVOL_PMS_HARDINFOR1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_BatteryVol_PMS_BatteryVol;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR1__XQC0B_PMS_BATTERYVOL_PMS_HARDINFOR1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BatteryVol_PMS_BatteryVol = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Brake_LightsRequest_PMS_Brake_LightsRequest)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_Brake_LightsRequest_PMS_Brake_LightsRequest;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_RMXR12_PMS_BRAKE_LIGHTSREQUEST_PMS_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_Brake_LightsRequest_PMS_Brake_LightsRequest;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_FVS55R_PMS_BRAKE_LIGHTSREQUEST_PMS_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_Brake_LightsRequest_PMS_Brake_LightsRequest;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL__XQC0B_PMS_BRAKE_LIGHTSREQUEST_PMS_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Brake_LightsRequest_PMS_Brake_LightsRequest = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BrkSysErr_PMS_BrkSysErr)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_BrkSysErr_PMS_BrkSysErr;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_RMXR12_PMS_BRKSYSERR_PMS_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_BrkSysErr_PMS_BrkSysErr;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_FVS55R_PMS_BRKSYSERR_PMS_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_BrkSysErr_PMS_BrkSysErr;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL__XQC0B_PMS_BRKSYSERR_PMS_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BrkSysErr_PMS_BrkSysErr = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CANBus_RecSta_PMS_CANBus_RecSta)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_CANBus_RecSta_PMS_CANBus_RecSta;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_RMXR12_PMS_CANBUS_RECSTA_PMS_MODECONTROL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_CANBus_RecSta_PMS_CANBus_RecSta;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_FVS55R_PMS_CANBUS_RECSTA_PMS_MODECONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_CANBus_RecSta_PMS_CANBus_RecSta;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL__XQC0B_PMS_CANBUS_RECSTA_PMS_MODECONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CANBus_RecSta_PMS_CANBus_RecSta = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CPSREn_PMS_CPSREn)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_CPSREn_PMS_CPSREn;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6_RMXR12_PMS_CPSREN_PMS_HARDINFOR6_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_CPSREn_PMS_CPSREn;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6__XQC0B_PMS_CPSREN_PMS_HARDINFOR6_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CPSREn_PMS_CPSREn = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CPSRU_PMS_CPSRU)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_CPSRU_PMS_CPSRU;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6_RMXR12_PMS_CPSRU_PMS_HARDINFOR6_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_CPSRU_PMS_CPSRU;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6__XQC0B_PMS_CPSRU_PMS_HARDINFOR6_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CPSRU_PMS_CPSRU = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CSControl1_CheckSum_PMS_CSControl1_CheckSum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_CSControl1_CheckSum_PMS_CSControl1_CheckSum;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL1_FVS55R_PMS_CSCONTROL1_CHECKSUM_PMS_CSCONTROL1_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_CSControl1_CheckSum_PMS_CSControl1_CheckSum;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL1__XQC0B_PMS_CSCONTROL1_CHECKSUM_PMS_CSCONTROL1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CSControl1_CheckSum_PMS_CSControl1_CheckSum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CSControl2_CheckSum_PMS_CSControl2_CheckSum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_CSControl2_CheckSum_PMS_CSControl2_CheckSum;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2_FVS55R_PMS_CSCONTROL2_CHECKSUM_PMS_CSCONTROL2_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_CSControl2_CheckSum_PMS_CSControl2_CheckSum;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2__XQC0B_PMS_CSCONTROL2_CHECKSUM_PMS_CSCONTROL2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CSControl2_CheckSum_PMS_CSControl2_CheckSum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CampModeFb_PMS_CampModeFb)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_CampModeFb_PMS_CampModeFb;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MMI_SWITCHFB__XQC0B_PMS_CAMPMODEFB_PMS_MMI_SWITCHFB_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CampModeFb_PMS_CampModeFb = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CampModeFbFailrReason_PMS_CampModeFbFailrReason)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_CampModeFbFailrReason_PMS_CampModeFbFailrReason;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MMI_SWITCHFB__XQC0B_PMS_CAMPMODEFBFAILRREASON_PMS_MMI_SWITCHFB_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CampModeFbFailrReason_PMS_CampModeFbFailrReason = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ChargPwr_PMS_ChargPwr)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_PMS_ChargPwr_PMS_ChargPwr;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_IPK_STATUS__XQC0B_PMS_CHARGPWR_PMS_IPK_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ChargPwr_PMS_ChargPwr = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ChargWakeupSts_PMS_ChargWakeupSts)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_ChargWakeupSts_PMS_ChargWakeupSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2_RMXR12_PMS_CHARGWAKEUPSTS_PMS_HARDINFOR2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_ChargWakeupSts_PMS_ChargWakeupSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2__XQC0B_PMS_CHARGWAKEUPSTS_PMS_HARDINFOR2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ChargWakeupSts_PMS_ChargWakeupSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ChargeHV_Status_PMS_ChargeHV_Status)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_ChargeHV_Status_PMS_ChargeHV_Status;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_RMXR12_PMS_CHARGEHV_STATUS_PMS_MODECONTROL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_ChargeHV_Status_PMS_ChargeHV_Status;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_FVS55R_PMS_CHARGEHV_STATUS_PMS_MODECONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_ChargeHV_Status_PMS_ChargeHV_Status;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL__XQC0B_PMS_CHARGEHV_STATUS_PMS_MODECONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ChargeHV_Status_PMS_ChargeHV_Status = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ChargeLimitResponse_PMS_ChargeLimitResponse)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_ChargeLimitResponse_PMS_ChargeLimitResponse;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_INFORCAN__XQC0B_PMS_CHARGELIMITRESPONSE_PMS_INFORCAN_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ChargeLimitResponse_PMS_ChargeLimitResponse = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ChargerFault_PMS_ChargerFault)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_ChargerFault_PMS_ChargerFault;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_RMXR12_PMS_CHARGERFAULT_PMS_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_ChargerFault_PMS_ChargerFault;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_FVS55R_PMS_CHARGERFAULT_PMS_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_ChargerFault_PMS_ChargerFault;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL__XQC0B_PMS_CHARGERFAULT_PMS_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ChargerFault_PMS_ChargerFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Command_Checksum_PMS_Command_Checksum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_Command_Checksum_PMS_Command_Checksum;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_COMMAND_RMXR12_PMS_COMMAND_CHECKSUM_PMS_COMMAND_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_Command_Checksum_PMS_Command_Checksum;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_COMMAND__XQC0B_PMS_COMMAND_CHECKSUM_PMS_COMMAND_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Command_Checksum_PMS_Command_Checksum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CoolingFanFaultFB_PMS_CoolingFanFaultFB)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_CoolingFanFaultFB_PMS_CoolingFanFaultFB;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_STATUS__XQC0B_PMS_COOLINGFANFAULTFB_PMS_TEMP_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CoolingFanFaultFB_PMS_CoolingFanFaultFB = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL_RMXR12_PMS_COOLINGFANPWMSPD_PMS_TEMP_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL__XQC0B_PMS_COOLINGFANPWMSPD_PMS_TEMP_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Ctrl_Checksum_PMS_Ctrl_Checksum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_Ctrl_Checksum_PMS_Ctrl_Checksum;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_RMXR12_PMS_CTRL_CHECKSUM_PMS_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_Ctrl_Checksum_PMS_Ctrl_Checksum;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_FVS55R_PMS_CTRL_CHECKSUM_PMS_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_Ctrl_Checksum_PMS_Ctrl_Checksum;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL__XQC0B_PMS_CTRL_CHECKSUM_PMS_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Ctrl_Checksum_PMS_Ctrl_Checksum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CurrentGearPosition_PMS_CurrentGearPosition)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_CurrentGearPosition_PMS_CurrentGearPosition;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_RMXR12_PMS_CURRENTGEARPOSITION_PMS_MODECONTROL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_CurrentGearPosition_PMS_CurrentGearPosition;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_FVS55R_PMS_CURRENTGEARPOSITION_PMS_MODECONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_CurrentGearPosition_PMS_CurrentGearPosition;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL__XQC0B_PMS_CURRENTGEARPOSITION_PMS_MODECONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CurrentGearPosition_PMS_CurrentGearPosition = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_RMXR12_PMS_CURRENTGEARPOSITION_VALID_PMS_MODECONTROL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_FVS55R_PMS_CURRENTGEARPOSITION_VALID_PMS_MODECONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL__XQC0B_PMS_CURRENTGEARPOSITION_VALID_PMS_MODECONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DCDCAwake_HW_PMS_DCDCAwake_HW)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_DCDCAwake_HW_PMS_DCDCAwake_HW;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6_RMXR12_PMS_DCDCAWAKE_HW_PMS_HARDINFOR6_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_DCDCAwake_HW_PMS_DCDCAwake_HW;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6__XQC0B_PMS_DCDCAWAKE_HW_PMS_HARDINFOR6_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DCDCAwake_HW_PMS_DCDCAwake_HW = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL_RMXR12_PMS_DCDCCUTOFFLV_PMS_DCDC_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL__XQC0B_PMS_DCDCCUTOFFLV_PMS_DCDC_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DCDCPwrLmt_PMS_DCDCPwrLmt)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_DCDCPwrLmt_PMS_DCDCPwrLmt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL_RMXR12_PMS_DCDCPWRLMT_PMS_DCDC_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_DCDCPwrLmt_PMS_DCDCPwrLmt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL__XQC0B_PMS_DCDCPWRLMT_PMS_DCDC_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DCDCPwrLmt_PMS_DCDCPwrLmt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DDwaterPump_PWMCtrl_EV_PMS_DDwaterPump_PWMCtrl_EV)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_DDwaterPump_PWMCtrl_EV_PMS_DDwaterPump_PWMCtrl_EV;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6_RMXR12_PMS_DDWATERPUMP_PWMCTRL_PMS_HARDINFOR6_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_DDwaterPump_PWMCtrl_EV_PMS_DDwaterPump_PWMCtrl_EV;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6__XQC0B_PMS_DDWATERPUMP_PWMCTRL_PMS_HARDINFOR6_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DDwaterPump_PWMCtrl_EV_PMS_DDwaterPump_PWMCtrl_EV = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DcDcActvdReq_PMS_DcDcActvdReq)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_DcDcActvdReq_PMS_DcDcActvdReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL_RMXR12_PMS_DCDCACTVDREQ_PMS_DCDC_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_DcDcActvdReq_PMS_DcDcActvdReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL__XQC0B_PMS_DCDCACTVDREQ_PMS_DCDC_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DcDcActvdReq_PMS_DcDcActvdReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DisChrgrSwtSt_PMS_DisChrgrSwtSt)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_DisChrgrSwtSt_PMS_DisChrgrSwtSt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_RMXR12_PMS_DISCHRGRSWTST_PMS_CTRL1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_DisChrgrSwtSt_PMS_DisChrgrSwtSt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_FVS55R_PMS_DISCHRGRSWTST_PMS_CTRL1_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_DisChrgrSwtSt_PMS_DisChrgrSwtSt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1__XQC0B_PMS_DISCHRGRSWTST_PMS_CTRL1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DisChrgrSwtSt_PMS_DisChrgrSwtSt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DischargeEnable_PMS_DischargeEnable)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_DischargeEnable_PMS_DischargeEnable;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL_RMXR12_PMS_DISCHARGEENABLE_PMS_DCDC_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_DischargeEnable_PMS_DischargeEnable;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL__XQC0B_PMS_DISCHARGEENABLE_PMS_DCDC_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DischargeEnable_PMS_DischargeEnable = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DoubleFlashLampOn_PMS_DoubleFlashLampOn)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_DoubleFlashLampOn_PMS_DoubleFlashLampOn;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_RMXR12_PMS_DOUBLEFLASHLAMPON_PMS_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_DoubleFlashLampOn_PMS_DoubleFlashLampOn;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_FVS55R_PMS_DOUBLEFLASHLAMPON_PMS_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_DoubleFlashLampOn_PMS_DoubleFlashLampOn;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL__XQC0B_PMS_DOUBLEFLASHLAMPON_PMS_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DoubleFlashLampOn_PMS_DoubleFlashLampOn = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL_RMXR12_PMS_DRIVECIRCUITTEMP_PMS_TEMP_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL__XQC0B_PMS_DRIVECIRCUITTEMP_PMS_TEMP_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DriveModeInd_PMS_DriveModeInd)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_DriveModeInd_PMS_DriveModeInd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_RMXR12_PMS_DRIVEMODEIND_PMS_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_DriveModeInd_PMS_DriveModeInd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_FVS55R_PMS_DRIVEMODEIND_PMS_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_DriveModeInd_PMS_DriveModeInd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL__XQC0B_PMS_DRIVEMODEIND_PMS_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DriveModeInd_PMS_DriveModeInd = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DriverDemandTorque_PMS_DriverDemandTorque)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_PMS_DriverDemandTorque_PMS_DriverDemandTorque;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL_FVS55R_PMS_DRIVERDEMANDTORQUE_PMS_ENGCONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_VCOP_PMS_DriverDemandTorque_PMS_DriverDemandTorque;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL__XQC0B_PMS_DRIVERDEMANDTORQUE_PMS_ENGCONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DriverDemandTorque_PMS_DriverDemandTorque = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DriverDemandTorqueInvalid_PMS_DriverDemandTorqueInvalid)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_DriverDemandTorqueInvalid_PMS_DriverDemandTorqueInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL_FVS55R_PMS_DRIVERDEMANDTORQUEINVALID_PMS_ENGCONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_DriverDemandTorqueInvalid_PMS_DriverDemandTorqueInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL__XQC0B_PMS_DRIVERDEMANDTORQUEINVALID_PMS_ENGCONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DriverDemandTorqueInvalid_PMS_DriverDemandTorqueInvalid = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DriverGearAbort_PMS_DriverGearAbort)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_DriverGearAbort_PMS_DriverGearAbort;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2_FVS55R_PMS_DRIVERGEARABORT_PMS_CSCONTROL2_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_DriverGearAbort_PMS_DriverGearAbort;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2__XQC0B_PMS_DRIVERGEARABORT_PMS_CSCONTROL2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DriverGearAbort_PMS_DriverGearAbort = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DrivingTakeEleSts_PMS_DrivingTakeEleSts)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_DrivingTakeEleSts_PMS_DrivingTakeEleSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_RMXR12_PMS_DRIVINGTAKEELESTS_PMS_CTRL1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_DrivingTakeEleSts_PMS_DrivingTakeEleSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_FVS55R_PMS_DRIVINGTAKEELESTS_PMS_CTRL1_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_DrivingTakeEleSts_PMS_DrivingTakeEleSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1__XQC0B_PMS_DRIVINGTAKEELESTS_PMS_CTRL1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DrivingTakeEleSts_PMS_DrivingTakeEleSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DrvrGearLvrLockIndcn_PMS_DrvrGearLvrLockIndcn)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_DrvrGearLvrLockIndcn_PMS_DrvrGearLvrLockIndcn;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_IPK_STATUS__XQC0B_PMS_DRVRGEARLVRLOCKINDCN_PMS_IPK_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DrvrGearLvrLockIndcn_PMS_DrvrGearLvrLockIndcn = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EDCPEnable_PMS_EDCPEnable)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_EDCPEnable_PMS_EDCPEnable;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_EDCPCTR_RMXR12_PMS_EDCPENABLE_PMS_EDCPCTR_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_EDCPEnable_PMS_EDCPEnable;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_EDCPCTR__XQC0B_PMS_EDCPENABLE_PMS_EDCPCTR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EDCPEnable_PMS_EDCPEnable = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_EDCPCTR_RMXR12_PMS_EDCPPWMCTRL_PMS_EDCPCTR_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_EDCPCTR__XQC0B_PMS_EDCPPWMCTRL_PMS_EDCPCTR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EDCP_FaultFB_PMS_EDCP_FaultFB)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_EDCP_FaultFB_PMS_EDCP_FaultFB;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR5_RMXR12_PMS_EDCP_FAULTFB_PMS_HARDINFOR5_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_EDCP_FaultFB_PMS_EDCP_FaultFB;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR5__XQC0B_PMS_EDCP_FAULTFB_PMS_HARDINFOR5_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EDCP_FaultFB_PMS_EDCP_FaultFB = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EDCP_PWMCtrl_PMS_EDCP_PWMCtrl)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_EDCP_PWMCtrl_PMS_EDCP_PWMCtrl;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2_RMXR12_PMS_EDCP_PWMCTRL_PMS_HARDINFOR2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_EDCP_PWMCtrl_PMS_EDCP_PWMCtrl;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2__XQC0B_PMS_EDCP_PWMCTRL_PMS_HARDINFOR2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EDCP_PWMCtrl_PMS_EDCP_PWMCtrl = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EPS_SteeringAngleValue_PMS_EPS_SteeringAngleValue)
    {
        sint16 phydata_0 = (sint16)Rte_swc_VCOP_PMS_EPS_SteeringAngleValue_PMS_EPS_SteeringAngleValue;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_EPS_SYSTEMSTS_RMXR12_PMS_EPS_STEERINGANGLEVALUE_PMS_EPS_SYSTEMSTS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EPS_SteeringAngleValue_PMS_EPS_SteeringAngleValue = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EVDTEodometer_PMS_EVDTEodometer)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_PMS_EVDTEodometer_PMS_EVDTEodometer;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_RMXR12_PMS_EVDTEODOMETER_PMS_CTRL1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_VCOP_PMS_EVDTEodometer_PMS_EVDTEodometer;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_FVS55R_PMS_EVDTEODOMETER_PMS_CTRL1_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint16 phydata_2 = (uint16)Rte_swc_VCOP_PMS_EVDTEodometer_PMS_EVDTEodometer;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_INFORCAN__XQC0B_PMS_EVDTEODOMETER_PMS_INFORCAN_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        uint16 phydata_3 = (uint16)Rte_swc_VCOP_PMS_EVDTEodometer_PMS_EVDTEodometer;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1__XQC0B_PMS_EVDTEODOMETER_PMS_CTRL1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_3);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EVDTEodometer_PMS_EVDTEodometer = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EngControl_CheckSum_PMS_EngControl_CheckSum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_EngControl_CheckSum_PMS_EngControl_CheckSum;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL_FVS55R_PMS_ENGCONTROL_CHECKSUM_PMS_ENGCONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_EngControl_CheckSum_PMS_EngControl_CheckSum;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL__XQC0B_PMS_ENGCONTROL_CHECKSUM_PMS_ENGCONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EngControl_CheckSum_PMS_EngControl_CheckSum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_RMXR12_PMS_ENGRECMODE_FB_PMS_CTRL1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_FVS55R_PMS_ENGRECMODE_FB_PMS_CTRL1_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1__XQC0B_PMS_ENGRECMODE_FB_PMS_CTRL1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EngTrqReqSrc_PMS_EngTrqReqSrc)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_EngTrqReqSrc_PMS_EngTrqReqSrc;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL_FVS55R_PMS_ENGTRQREQSRC_PMS_ENGCONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_EngTrqReqSrc_PMS_EngTrqReqSrc;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL__XQC0B_PMS_ENGTRQREQSRC_PMS_ENGCONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EngTrqReqSrc_PMS_EngTrqReqSrc = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ErrCode_PMS_ErrCode)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_PMS_ErrCode_PMS_ErrCode;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ERRCODE__XQC0B_PMS_ERRCODE_PMS_ERRCODE_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ErrCode_PMS_ErrCode = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_FAN_PWMCtrl_PMS_FAN_PWMCtrl)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_FAN_PWMCtrl_PMS_FAN_PWMCtrl;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6_RMXR12_PMS_FAN_PWMCTRL_PMS_HARDINFOR6_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_FAN_PWMCtrl_PMS_FAN_PWMCtrl;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6__XQC0B_PMS_FAN_PWMCTRL_PMS_HARDINFOR6_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_FAN_PWMCtrl_PMS_FAN_PWMCtrl = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Fn1GearRlyDrvStsFb_PMS_Fn1GearRlyDrvStsFb)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_Fn1GearRlyDrvStsFb_PMS_Fn1GearRlyDrvStsFb;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2_RMXR12_PMS_FN1GEARRLYDRVSTSFB_PMS_HARDINFOR2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_Fn1GearRlyDrvStsFb_PMS_Fn1GearRlyDrvStsFb;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2__XQC0B_PMS_FN1GEARRLYDRVSTSFB_PMS_HARDINFOR2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Fn1GearRlyDrvStsFb_PMS_Fn1GearRlyDrvStsFb = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Fn2GearRlyDrvStsFb_PMS_Fn2GearRlyDrvStsFb)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_Fn2GearRlyDrvStsFb_PMS_Fn2GearRlyDrvStsFb;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2_RMXR12_PMS_FN2GEARRLYDRVSTSFB_PMS_HARDINFOR2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_Fn2GearRlyDrvStsFb_PMS_Fn2GearRlyDrvStsFb;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2__XQC0B_PMS_FN2GEARRLYDRVSTSFB_PMS_HARDINFOR2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Fn2GearRlyDrvStsFb_PMS_Fn2GearRlyDrvStsFb = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_COMMAND_RMXR12_PMS_FRNTHEATMODENAD_PMS_COMMAND_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_COMMAND__XQC0B_PMS_FRNTHEATMODENAD_PMS_COMMAND_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_COMMAND_RMXR12_PMS_FRNTHEATPWRALLWD_PMS_COMMAND_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_COMMAND__XQC0B_PMS_FRNTHEATPWRALLWD_PMS_COMMAND_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_FunAnti_DismantleActive_PMS_FunAnti_DismantleActive)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_FunAnti_DismantleActive_PMS_FunAnti_DismantleActive;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_LOCKVEHINFOR__XQC0B_PMS_FUNANTI_DISMANTLEACTIVE_PMS_LOCKVEHINFOR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_FunAnti_DismantleActive_PMS_FunAnti_DismantleActive = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_FunLockVehActive_PMS_FunLockVehActive)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_FunLockVehActive_PMS_FunLockVehActive;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_LOCKVEHINFOR__XQC0B_PMS_FUNLOCKVEHACTIVE_PMS_LOCKVEHINFOR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_FunLockVehActive_PMS_FunLockVehActive = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_GP_Ovrd_PMS_GP_Ovrd)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_GP_Ovrd_PMS_GP_Ovrd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL_FVS55R_PMS_GP_OVRD_PMS_ENGCONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_GP_Ovrd_PMS_GP_Ovrd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL__XQC0B_PMS_GP_OVRD_PMS_ENGCONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_GP_Ovrd_PMS_GP_Ovrd = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_GearOperateErr_PMS_GearOperateErr)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_GearOperateErr_PMS_GearOperateErr;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_RMXR12_PMS_GEAROPERATEERR_PMS_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_GearOperateErr_PMS_GearOperateErr;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_FVS55R_PMS_GEAROPERATEERR_PMS_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_GearOperateErr_PMS_GearOperateErr;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL__XQC0B_PMS_GEAROPERATEERR_PMS_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_GearOperateErr_PMS_GearOperateErr = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Gear_intervene_PMS_Gear_intervene)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_Gear_intervene_PMS_Gear_intervene;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_RMXR12_PMS_GEAR_INTERVENE_PMS_MODECONTROL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_Gear_intervene_PMS_Gear_intervene;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_FVS55R_PMS_GEAR_INTERVENE_PMS_MODECONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_Gear_intervene_PMS_Gear_intervene;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL__XQC0B_PMS_GEAR_INTERVENE_PMS_MODECONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Gear_intervene_PMS_Gear_intervene = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_GrossComVehWeight_PMS_GrossComVehWeight)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_PMS_GrossComVehWeight_PMS_GrossComVehWeight;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CVW__XQC0B_PMS_GROSSCOMVEHWEIGHT_PMS_CVW_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_GrossComVehWeight_PMS_GrossComVehWeight = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HBCPEnable_PMS_HBCPEnable)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_HBCPEnable_PMS_HBCPEnable;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_EDCPCTR_RMXR12_PMS_HBCPENABLE_PMS_EDCPCTR_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_HBCPEnable_PMS_HBCPEnable;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_EDCPCTR__XQC0B_PMS_HBCPENABLE_PMS_EDCPCTR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HBCPEnable_PMS_HBCPEnable = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_EDCPCTR_RMXR12_PMS_HBCPPWMCTRL_PMS_EDCPCTR_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_EDCPCTR__XQC0B_PMS_HBCPPWMCTRL_PMS_EDCPCTR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HBCP_FaultFB_PMS_HBCP_FaultFB)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_HBCP_FaultFB_PMS_HBCP_FaultFB;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR5_RMXR12_PMS_HBCP_FAULTFB_PMS_HARDINFOR5_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_HBCP_FaultFB_PMS_HBCP_FaultFB;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR5__XQC0B_PMS_HBCP_FAULTFB_PMS_HARDINFOR5_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HBCP_FaultFB_PMS_HBCP_FaultFB = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HBCP_PWMCtrl_PMS_HBCP_PWMCtrl)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_HBCP_PWMCtrl_PMS_HBCP_PWMCtrl;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2_RMXR12_PMS_HBCP_PWMCTRL_PMS_HARDINFOR2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_HBCP_PWMCtrl_PMS_HBCP_PWMCtrl;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2__XQC0B_PMS_HBCP_PWMCTRL_PMS_HARDINFOR2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HBCP_PWMCtrl_PMS_HBCP_PWMCtrl = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVIL1Sts_PMS_HVIL1Sts)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_HVIL1Sts_PMS_HVIL1Sts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL_RMXR12_PMS_HVIL1STS_PMS_DCDC_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_HVIL1Sts_PMS_HVIL1Sts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL__XQC0B_PMS_HVIL1STS_PMS_DCDC_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVIL1Sts_PMS_HVIL1Sts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVIL1Sts_UB_PMS_HVIL1Sts_UB)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_HVIL1Sts_UB_PMS_HVIL1Sts_UB;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL_RMXR12_PMS_HVIL1STS_UB_PMS_DCDC_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_HVIL1Sts_UB_PMS_HVIL1Sts_UB;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL__XQC0B_PMS_HVIL1STS_UB_PMS_DCDC_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVIL1Sts_UB_PMS_HVIL1Sts_UB = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVIL2Sts_PMS_HVIL2Sts)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_HVIL2Sts_PMS_HVIL2Sts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL_RMXR12_PMS_HVIL2STS_PMS_DCDC_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_HVIL2Sts_PMS_HVIL2Sts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL__XQC0B_PMS_HVIL2STS_PMS_DCDC_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVIL2Sts_PMS_HVIL2Sts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVIL2Sts_UB_PMS_HVIL2Sts_UB)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_HVIL2Sts_UB_PMS_HVIL2Sts_UB;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL_RMXR12_PMS_HVIL2STS_UB_PMS_DCDC_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_HVIL2Sts_UB_PMS_HVIL2Sts_UB;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL__XQC0B_PMS_HVIL2STS_UB_PMS_DCDC_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVIL2Sts_UB_PMS_HVIL2Sts_UB = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVILSts_PMS_HVILSts)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_HVILSts_PMS_HVILSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL_RMXR12_PMS_HVILSTS_PMS_DCDC_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_HVILSts_PMS_HVILSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL__XQC0B_PMS_HVILSTS_PMS_DCDC_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVILSts_PMS_HVILSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVILSts_UB_PMS_HVILSts_UB)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_HVILSts_UB_PMS_HVILSts_UB;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL_RMXR12_PMS_HVILSTS_UB_PMS_DCDC_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_HVILSts_UB_PMS_HVILSts_UB;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL__XQC0B_PMS_HVILSTS_UB_PMS_DCDC_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVILSts_UB_PMS_HVILSts_UB = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVPRASts_PMS_HVPRASts)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_HVPRASts_PMS_HVPRASts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR1_RMXR12_PMS_HVPRASTS_PMS_HARDINFOR1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_HVPRASts_PMS_HVPRASts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR1__XQC0B_PMS_HVPRASTS_PMS_HARDINFOR1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVPRASts_PMS_HVPRASts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HardwareMajorVer_PMS_HardwareMajorVer)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_HardwareMajorVer_PMS_HardwareMajorVer;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VERINFO__XQC0B_PMS_HARDWAREMAJORVER_PMS_VERINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HardwareMajorVer_PMS_HardwareMajorVer = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HardwareMinorVer_PMS_HardwareMinorVer)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_HardwareMinorVer_PMS_HardwareMinorVer;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VERINFO__XQC0B_PMS_HARDWAREMINORVER_PMS_VERINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HardwareMinorVer_PMS_HardwareMinorVer = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HvCoolgPwrAllwd_PMS_HvCoolgPwrAllwd)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_HvCoolgPwrAllwd_PMS_HvCoolgPwrAllwd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL_RMXR12_PMS_HVCOOLGPWRALLWD_PMS_TEMP_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_HvCoolgPwrAllwd_PMS_HvCoolgPwrAllwd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL__XQC0B_PMS_HVCOOLGPWRALLWD_PMS_TEMP_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HvCoolgPwrAllwd_PMS_HvCoolgPwrAllwd = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HvHeatgPwrAllwd_PMS_HvHeatgPwrAllwd)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_HvHeatgPwrAllwd_PMS_HvHeatgPwrAllwd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL_RMXR12_PMS_HVHEATGPWRALLWD_PMS_TEMP_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_HvHeatgPwrAllwd_PMS_HvHeatgPwrAllwd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL__XQC0B_PMS_HVHEATGPWRALLWD_PMS_TEMP_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HvHeatgPwrAllwd_PMS_HvHeatgPwrAllwd = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer)
    {
        uint32 phydata_0 = (uint32)Rte_swc_VCOP_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TOTALODOMETER1__XQC0B_PMS_IPKTOTALODOMETER_PMS_TOTALODOMETER1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IPK_HandBrakeSts_PMS_IPK_HandBrakeSts)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_IPK_HandBrakeSts_PMS_IPK_HandBrakeSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_IPK_STS_RMXR12_PMS_IPK_HANDBRAKESTS_PMS_IPK_STS_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IPK_HandBrakeSts_PMS_IPK_HandBrakeSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IgnONSts_PMS_IgnONSts)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_IgnONSts_PMS_IgnONSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR1_RMXR12_PMS_IGNONSTS_PMS_HARDINFOR1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_IgnONSts_PMS_IgnONSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR1__XQC0B_PMS_IGNONSTS_PMS_HARDINFOR1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IgnONSts_PMS_IgnONSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IntelligentChargeExitReq_PMS_IntelligentChargeExitReq)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_IntelligentChargeExitReq_PMS_IntelligentChargeExitReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_LOCKVEHINFOR__XQC0B_PMS_INTELLIGENTCHARGEEXITREQ_PMS_LOCKVEHINFOR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IntelligentChargeExitReq_PMS_IntelligentChargeExitReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IntelligentChargeQuit_PMS_IntelligentChargeQuit)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_IntelligentChargeQuit_PMS_IntelligentChargeQuit;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_LOCKVEHINFOR__XQC0B_PMS_INTELLIGENTCHARGEQUIT_PMS_LOCKVEHINFOR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IntelligentChargeQuit_PMS_IntelligentChargeQuit = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IntelligentChargeState_PMS_IntelligentChargeState)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_IntelligentChargeState_PMS_IntelligentChargeState;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_LOCKVEHINFOR__XQC0B_PMS_INTELLIGENTCHARGESTATE_PMS_LOCKVEHINFOR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IntelligentChargeState_PMS_IntelligentChargeState = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_InventorySpdLmtRxSts_PMS_InventorySpdLmtRxSts)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_InventorySpdLmtRxSts_PMS_InventorySpdLmtRxSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_INSTRUCT__XQC0B_PMS_INVENTORYSPDLMTRXSTS_PMS_INSTRUCT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_InventorySpdLmtRxSts_PMS_InventorySpdLmtRxSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_InventorySpdLmtSts_PMS_InventorySpdLmtSts)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_InventorySpdLmtSts_PMS_InventorySpdLmtSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_INSTRUCT__XQC0B_PMS_INVENTORYSPDLMTSTS_PMS_INSTRUCT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_InventorySpdLmtSts_PMS_InventorySpdLmtSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_COMMAND_RMXR12_PMS_ISGACTVDAMPGMODREQ_PMS_COMMAND_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_COMMAND__XQC0B_PMS_ISGACTVDAMPGMODREQ_PMS_COMMAND_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IsgModReq_PMS_IsgModReq)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_IsgModReq_PMS_IsgModReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_COMMAND_RMXR12_PMS_ISGMODREQ_PMS_COMMAND_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_IsgModReq_PMS_IsgModReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_COMMAND__XQC0B_PMS_ISGMODREQ_PMS_COMMAND_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IsgModReq_PMS_IsgModReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IsgTqReq_PMS_IsgTqReq)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_PMS_IsgTqReq_PMS_IsgTqReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_COMMAND_RMXR12_PMS_ISGTQREQ_PMS_COMMAND_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_VCOP_PMS_IsgTqReq_PMS_IsgTqReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_COMMAND__XQC0B_PMS_ISGTQREQ_PMS_COMMAND_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IsgTqReq_PMS_IsgTqReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LTCoolingFanFB_PMS_LTCoolingFanFB)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_LTCoolingFanFB_PMS_LTCoolingFanFB;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_STATUS__XQC0B_PMS_LTCOOLINGFANFB_PMS_TEMP_STATUS_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LTCoolingFanFB_PMS_LTCoolingFanFB = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Life_PMS_Life)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_Life_PMS_Life;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_INSTRUCT__XQC0B_PMS_LIFE_PMS_INSTRUCT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Life_PMS_Life = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LimpHomeSts_PMS_LimpHomeSts)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_LimpHomeSts_PMS_LimpHomeSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL_FVS55R_PMS_LIMPHOMESTS_PMS_ENGCONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_LimpHomeSts_PMS_LimpHomeSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL__XQC0B_PMS_LIMPHOMESTS_PMS_ENGCONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LimpHomeSts_PMS_LimpHomeSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LockLimResult_PMS_LockLimResult)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_LockLimResult_PMS_LockLimResult;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_LOCKVEHINFOR__XQC0B_PMS_LOCKLIMRESULT_PMS_LOCKVEHINFOR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LockLimResult_PMS_LockLimResult = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LockVehExecutedSts_PMS_LockVehExecutedSts)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_LockVehExecutedSts_PMS_LockVehExecutedSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_LOCKVEHINFOR__XQC0B_PMS_LOCKVEHEXECUTEDSTS_PMS_LOCKVEHINFOR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LockVehExecutedSts_PMS_LockVehExecutedSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LockVehPerFlag_PMS_LockVehPerFlag)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_LockVehPerFlag_PMS_LockVehPerFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_INSTRUCT__XQC0B_PMS_LOCKVEHPERFLAG_PMS_INSTRUCT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LockVehPerFlag_PMS_LockVehPerFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LockVehPerRxSts_PMS_LockVehPerRxSts)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_LockVehPerRxSts_PMS_LockVehPerRxSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_INSTRUCT__XQC0B_PMS_LOCKVEHPERRXSTS_PMS_INSTRUCT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LockVehPerRxSts_PMS_LockVehPerRxSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LockVehSts_PMS_LockVehSts)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_LockVehSts_PMS_LockVehSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_LOCKVEHINFOR__XQC0B_PMS_LOCKVEHSTS_PMS_LOCKVEHINFOR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LockVehSts_PMS_LockVehSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LockVehType_PMS_LockVehType)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_LockVehType_PMS_LockVehType;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_LOCKVEHINFOR__XQC0B_PMS_LOCKVEHTYPE_PMS_LOCKVEHINFOR_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LockVehType_PMS_LockVehType = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MCUFlowFeedback_EV_PMS_MCUFlowFeedback_EV)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_MCUFlowFeedback_EV_PMS_MCUFlowFeedback_EV;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_COMMAND_RMXR12_PMS_IPUFLOWFEEDBACK_PMS_COMMAND_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_MCUFlowFeedback_EV_PMS_MCUFlowFeedback_EV;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_COMMAND__XQC0B_PMS_IPUFLOWFEEDBACK_PMS_COMMAND_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MCUFlowFeedback_EV_PMS_MCUFlowFeedback_EV = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MHGV_EnableReq_PMS_MHGV_EnableReq)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_MHGV_EnableReq_PMS_MHGV_EnableReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TWVCOMMAND__XQC0B_PMS_MHGV_ENABLEREQ_PMS_TWVCOMMAND_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MHGV_EnableReq_PMS_MHGV_EnableReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MHGV_PosSet_PMS_MHGV_PosSet)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_MHGV_PosSet_PMS_MHGV_PosSet;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TWVCOMMAND_T34TDK_PMS_MHGV_POSSET_PMS_TWVCOMMAND_VE21_N72_PMS_LIN_LDF_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_MHGV_PosSet_PMS_MHGV_PosSet;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TWVCOMMAND__XQC0B_PMS_MHGV_POSSET_PMS_TWVCOMMAND_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MHGV_PosSet_PMS_MHGV_PosSet = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MHGV_ReqMotorEmgyStop_PMS_MHGV_ReqMotorEmgyStop)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_MHGV_ReqMotorEmgyStop_PMS_MHGV_ReqMotorEmgyStop;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TWVCOMMAND_T34TDK_PMS_MHGV_REQMOTOREMGYSTOP_PMS_TWVCOMMAND_VE21_N72_PMS_LIN_LDF_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_MHGV_ReqMotorEmgyStop_PMS_MHGV_ReqMotorEmgyStop;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TWVCOMMAND__XQC0B_PMS_MHGV_REQMOTOREMGYSTOP_PMS_TWVCOMMAND_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MHGV_ReqMotorEmgyStop_PMS_MHGV_ReqMotorEmgyStop = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MHGV_ReqMotorOptRecovery_PMS_MHGV_ReqMotorOptRecovery)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_MHGV_ReqMotorOptRecovery_PMS_MHGV_ReqMotorOptRecovery;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TWVCOMMAND_T34TDK_PMS_MHGV_REQMOTOROPTRECOVERY_PMS_TWVCOMMAND_VE21_N72_PMS_LIN_LDF_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_MHGV_ReqMotorOptRecovery_PMS_MHGV_ReqMotorOptRecovery;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TWVCOMMAND__XQC0B_PMS_MHGV_REQMOTOROPTRECOVERY_PMS_TWVCOMMAND_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MHGV_ReqMotorOptRecovery_PMS_MHGV_ReqMotorOptRecovery = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MaxPTTorqueAllowed_PMS_MaxPTTorqueAllowed)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_PMS_MaxPTTorqueAllowed_PMS_MaxPTTorqueAllowed;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL1_FVS55R_PMS_MAXPTTORQUEALLOWED_PMS_CSCONTROL1_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_VCOP_PMS_MaxPTTorqueAllowed_PMS_MaxPTTorqueAllowed;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL1__XQC0B_PMS_MAXPTTORQUEALLOWED_PMS_CSCONTROL1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MaxPTTorqueAllowed_PMS_MaxPTTorqueAllowed = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MinPTTorqueAllowed_PMS_MinPTTorqueAllowed)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_PMS_MinPTTorqueAllowed_PMS_MinPTTorqueAllowed;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL1_FVS55R_PMS_MINPTTORQUEALLOWED_PMS_CSCONTROL1_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_VCOP_PMS_MinPTTorqueAllowed_PMS_MinPTTorqueAllowed;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL1__XQC0B_PMS_MINPTTORQUEALLOWED_PMS_CSCONTROL1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MinPTTorqueAllowed_PMS_MinPTTorqueAllowed = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ModeControl_CheckSum_PMS_ModeControl_CheckSum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_ModeControl_CheckSum_PMS_ModeControl_CheckSum;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_RMXR12_PMS_MODECONTROL_CHECKSUM_PMS_MODECONTROL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_ModeControl_CheckSum_PMS_ModeControl_CheckSum;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_FVS55R_PMS_MODECONTROL_CHECKSUM_PMS_MODECONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_ModeControl_CheckSum_PMS_ModeControl_CheckSum;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL__XQC0B_PMS_MODECONTROL_CHECKSUM_PMS_MODECONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ModeControl_CheckSum_PMS_ModeControl_CheckSum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_RMXR12_PMS_MODEGEARDISPLAYSTS_PMS_MODECONTROL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_FVS55R_PMS_MODEGEARDISPLAYSTS_PMS_MODECONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL__XQC0B_PMS_MODEGEARDISPLAYSTS_PMS_MODECONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_OTAINSTRUCSTSREMINDER_PMS_OTAINSTRUCSTSREMINDER);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR1_RMXR12_PMS_OTAINSTRUCSTSREMINDER_PMS_HARDINFOR1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR1__XQC0B_PMS_OTAINSTRUCSTSREMINDER_PMS_HARDINFOR1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_OTAINSTRUCSTSREMINDER_PMS_OTAINSTRUCSTSREMINDER);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_OTAINSTRUCTRXNSTS_PMS_OTAINSTRUCTRXNSTS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR1_RMXR12_PMS_OTAINSTRUCTRXNSTS_PMS_HARDINFOR1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR1__XQC0B_PMS_OTAINSTRUCTRXNSTS_PMS_HARDINFOR1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_OTAINSTRUCTRXNSTS_PMS_OTAINSTRUCTRXNSTS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_OdometerbackupEnable_PMS_OdometerbackupEnable)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_OdometerbackupEnable_PMS_OdometerbackupEnable;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TOTALODOMETER1__XQC0B_PMS_ODOMETERBACKUPENABLE_PMS_TOTALODOMETER1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_OdometerbackupEnable_PMS_OdometerbackupEnable = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PEPSAuth_PMS_PEPSAuth)
    {
        uint64 phydata_0 = (uint64)Rte_swc_VCOP_PMS_PEPSAuth_PMS_PEPSAuth;
//        Com_SendSignal(COMCONF_COMSIGNAL_PMS_PEPSAUTH_RMXR12_PMS_PEPSAUTH_PMS_PEPSAUTH_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint64 phydata_1 = (uint64)Rte_swc_VCOP_PMS_PEPSAuth_PMS_PEPSAuth;
//        Com_SendSignal(COMCONF_COMSIGNAL_PMS_PEPSAUTH__XQC0B_PMS_PEPSAUTH_PMS_PEPSAUTH_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PEPSAuth_PMS_PEPSAuth = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PEPS_0x1E2_TimeoutFlag_PMS_PEPS_0x1E2_TimeoutFlag)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_PEPS_0x1E2_TimeoutFlag_PMS_PEPS_0x1E2_TimeoutFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_PEPS_INFORMATION_RMXR12_PMS_PEPS_0X1E2_TIMEOUTFLAG_PMS_PEPS_INFORMATION_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PEPS_0x1E2_TimeoutFlag_PMS_PEPS_0x1E2_TimeoutFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PEPS_PowerMode_PMS_PEPS_PowerMode)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_PEPS_PowerMode_PMS_PEPS_PowerMode;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_PEPS_INFORMATION_RMXR12_PMS_PEPS_POWERMODE_PMS_PEPS_INFORMATION_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PEPS_PowerMode_PMS_PEPS_PowerMode = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PEPS_PowerModeValidity_PMS_PEPS_PowerModeValidity)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_PEPS_PowerModeValidity_PMS_PEPS_PowerModeValidity;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_PEPS_INFORMATION_RMXR12_PMS_PEPS_POWERMODEVALIDITY_PMS_PEPS_INFORMATION_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PEPS_PowerModeValidity_PMS_PEPS_PowerModeValidity = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTC1ConnStsFb_PMS_PTC1ConnStsFb)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_PTC1ConnStsFb_PMS_PTC1ConnStsFb;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2_RMXR12_PMS_PTC1CONNSTSFB_PMS_HARDINFOR2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_PTC1ConnStsFb_PMS_PTC1ConnStsFb;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2__XQC0B_PMS_PTC1CONNSTSFB_PMS_HARDINFOR2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTC1ConnStsFb_PMS_PTC1ConnStsFb = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTC1RelayFlt_PMS_PTC1RelayFlt)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_PTC1RelayFlt_PMS_PTC1RelayFlt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2_RMXR12_PMS_PTC1RELAYFLT_PMS_HARDINFOR2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_PTC1RelayFlt_PMS_PTC1RelayFlt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2__XQC0B_PMS_PTC1RELAYFLT_PMS_HARDINFOR2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTC1RelayFlt_PMS_PTC1RelayFlt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTC2Enable_PMS_PTC2Enable)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_PTC2Enable_PMS_PTC2Enable;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_RMXR12_PMS_PTC2ENABLE_PMS_CTRL1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_PTC2Enable_PMS_PTC2Enable;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_FVS55R_PMS_PTC2ENABLE_PMS_CTRL1_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_PTC2Enable_PMS_PTC2Enable;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1__XQC0B_PMS_PTC2ENABLE_PMS_CTRL1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTC2Enable_PMS_PTC2Enable = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTC3ConnStsFb_PMS_PTC3ConnStsFb)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_PTC3ConnStsFb_PMS_PTC3ConnStsFb;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2_RMXR12_PMS_PTC3CONNSTSFB_PMS_HARDINFOR2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_PTC3ConnStsFb_PMS_PTC3ConnStsFb;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2__XQC0B_PMS_PTC3CONNSTSFB_PMS_HARDINFOR2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTC3ConnStsFb_PMS_PTC3ConnStsFb = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTC3Enable_PMS_PTC3Enable)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_PTC3Enable_PMS_PTC3Enable;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_RMXR12_PMS_PTC3ENABLE_PMS_CTRL1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_PTC3Enable_PMS_PTC3Enable;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_FVS55R_PMS_PTC3ENABLE_PMS_CTRL1_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_PTC3Enable_PMS_PTC3Enable;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1__XQC0B_PMS_PTC3ENABLE_PMS_CTRL1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTC3Enable_PMS_PTC3Enable = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTC3RelayFlt_PMS_PTC3RelayFlt)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_PTC3RelayFlt_PMS_PTC3RelayFlt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2_RMXR12_PMS_PTC3RELAYFLT_PMS_HARDINFOR2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_PTC3RelayFlt_PMS_PTC3RelayFlt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2__XQC0B_PMS_PTC3RELAYFLT_PMS_HARDINFOR2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTC3RelayFlt_PMS_PTC3RelayFlt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTCEnable_PMS_PTCEnable)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_PTCEnable_PMS_PTCEnable;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL_RMXR12_PMS_PTCENABLE_PMS_TEMP_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_PTCEnable_PMS_PTCEnable;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TEMP_CTRL__XQC0B_PMS_PTCENABLE_PMS_TEMP_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTCEnable_PMS_PTCEnable = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTCRelayVoltSampSwich_PMS_PTCRelayVoltSampSwich)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_PTCRelayVoltSampSwich_PMS_PTCRelayVoltSampSwich;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_RELAYSAMPSWICH_LGFZID_PMS_PTCRELAYVOLTSAMPSWICH_PMS_RELAYSAMPSWICH_N72_HCM__MATRIX_V1_1_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTCRelayVoltSampSwich_PMS_PTCRelayVoltSampSwich = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_INFORCAN__XQC0B_PMS_PTRESIDUEPWRIND_PMS_INFORCAN_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PowerOffCmdRxSts_PMS_PowerOffCmdRxSts)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_PowerOffCmdRxSts_PMS_PowerOffCmdRxSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_INSTRUCT__XQC0B_PMS_POWEROFFCMDRXSTS_PMS_INSTRUCT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PowerOffCmdRxSts_PMS_PowerOffCmdRxSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PowerOffCmdSts_PMS_PowerOffCmdSts)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_PowerOffCmdSts_PMS_PowerOffCmdSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_INSTRUCT__XQC0B_PMS_POWEROFFCMDSTS_PMS_INSTRUCT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PowerOffCmdSts_PMS_PowerOffCmdSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PreAccessoryConnStsFb_PMS_PreAccessoryConnStsFb)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_PreAccessoryConnStsFb_PMS_PreAccessoryConnStsFb;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2_RMXR12_PMS_PREACCESSORYCONNSTSFB_PMS_HARDINFOR2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_PreAccessoryConnStsFb_PMS_PreAccessoryConnStsFb;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2__XQC0B_PMS_PREACCESSORYCONNSTSFB_PMS_HARDINFOR2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PreAccessoryConnStsFb_PMS_PreAccessoryConnStsFb = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PreAccessoryRelayFlt_PMS_PreAccessoryRelayFlt)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_PreAccessoryRelayFlt_PMS_PreAccessoryRelayFlt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2_RMXR12_PMS_PREACCESSORYRELAYFLT_PMS_HARDINFOR2_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_PreAccessoryRelayFlt_PMS_PreAccessoryRelayFlt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR2__XQC0B_PMS_PREACCESSORYRELAYFLT_PMS_HARDINFOR2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PreAccessoryRelayFlt_PMS_PreAccessoryRelayFlt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Real_PedalPosition_PMS_Real_PedalPosition)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_Real_PedalPosition_PMS_Real_PedalPosition;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_RMXR12_PMS_REAL_PEDALPOSITION_PMS_MODECONTROL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_Real_PedalPosition_PMS_Real_PedalPosition;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_FVS55R_PMS_REAL_PEDALPOSITION_PMS_MODECONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_Real_PedalPosition_PMS_Real_PedalPosition;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL__XQC0B_PMS_REAL_PEDALPOSITION_PMS_MODECONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Real_PedalPosition_PMS_Real_PedalPosition = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_RMXR12_PMS_REAL_PEDALPOSITIONINVALID_PMS_MODECONTROL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_FVS55R_PMS_REAL_PEDALPOSITIONINVALID_PMS_MODECONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL__XQC0B_PMS_REAL_PEDALPOSITIONINVALID_PMS_MODECONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegenTarTrqPot_PMS_RegenTarTrqPot)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_PMS_RegenTarTrqPot_PMS_RegenTarTrqPot;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2_FVS55R_PMS_REGENTARTRQPOT_PMS_CSCONTROL2_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_VCOP_PMS_RegenTarTrqPot_PMS_RegenTarTrqPot;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2__XQC0B_PMS_REGENTARTRQPOT_PMS_CSCONTROL2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegenTarTrqPot_PMS_RegenTarTrqPot = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegenTarTrqPotQualifier_PMS_RegenTarTrqPotQualifier)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_RegenTarTrqPotQualifier_PMS_RegenTarTrqPotQualifier;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2_FVS55R_PMS_REGENTARTRQPOTQUALIFIER_PMS_CSCONTROL2_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_RegenTarTrqPotQualifier_PMS_RegenTarTrqPotQualifier;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2__XQC0B_PMS_REGENTARTRQPOTQUALIFIER_PMS_CSCONTROL2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegenTarTrqPotQualifier_PMS_RegenTarTrqPotQualifier = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegenTrqAct_PMS_RegenTrqAct)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_PMS_RegenTrqAct_PMS_RegenTrqAct;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2_FVS55R_PMS_REGENTRQACT_PMS_CSCONTROL2_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_VCOP_PMS_RegenTrqAct_PMS_RegenTrqAct;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2__XQC0B_PMS_REGENTRQACT_PMS_CSCONTROL2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegenTrqAct_PMS_RegenTrqAct = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegenTrqActQualifier_PMS_RegenTrqActQualifier)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_RegenTrqActQualifier_PMS_RegenTrqActQualifier;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2_FVS55R_PMS_REGENTRQACTQUALIFIER_PMS_CSCONTROL2_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_RegenTrqActQualifier_PMS_RegenTrqActQualifier;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2__XQC0B_PMS_REGENTRQACTQUALIFIER_PMS_CSCONTROL2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegenTrqActQualifier_PMS_RegenTrqActQualifier = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegenTrqPot_PMS_RegenTrqPot)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_PMS_RegenTrqPot_PMS_RegenTrqPot;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2_FVS55R_PMS_REGENTRQPOT_PMS_CSCONTROL2_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_VCOP_PMS_RegenTrqPot_PMS_RegenTrqPot;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2__XQC0B_PMS_REGENTRQPOT_PMS_CSCONTROL2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegenTrqPot_PMS_RegenTrqPot = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegenTrqPotQualifier_PMS_RegenTrqPotQualifier)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_RegenTrqPotQualifier_PMS_RegenTrqPotQualifier;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2_FVS55R_PMS_REGENTRQPOTQUALIFIER_PMS_CSCONTROL2_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_RegenTrqPotQualifier_PMS_RegenTrqPotQualifier;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2__XQC0B_PMS_REGENTRQPOTQUALIFIER_PMS_CSCONTROL2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegenTrqPotQualifier_PMS_RegenTrqPotQualifier = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegulationSpeed_PMS_PMS_RegulationSpeed_PMS)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_RegulationSpeed_PMS_PMS_RegulationSpeed_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_RMXR12_PMS_REGULATIONSPEED_PMS_MODECONTROL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_RegulationSpeed_PMS_PMS_RegulationSpeed_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_FVS55R_PMS_REGULATIONSPEED_PMS_MODECONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_RegulationSpeed_PMS_PMS_RegulationSpeed_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL__XQC0B_PMS_REGULATIONSPEED_PMS_MODECONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegulationSpeed_PMS_PMS_RegulationSpeed_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RemChrgCmdFailrPrompt_PMS_RemChrgCmdFailrPrompt)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_RemChrgCmdFailrPrompt_PMS_RemChrgCmdFailrPrompt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_RMXR12_PMS_REMCHRGCMDFAILRPROMPT_PMS_CTRL1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_RemChrgCmdFailrPrompt_PMS_RemChrgCmdFailrPrompt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_FVS55R_PMS_REMCHRGCMDFAILRPROMPT_PMS_CTRL1_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_RemChrgCmdFailrPrompt_PMS_RemChrgCmdFailrPrompt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1__XQC0B_PMS_REMCHRGCMDFAILRPROMPT_PMS_CTRL1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RemChrgCmdFailrPrompt_PMS_RemChrgCmdFailrPrompt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ReqSeed_PMS_ReqSeed)
    {
        uint64 phydata_0 = (uint64)Rte_swc_VCOP_PMS_ReqSeed_PMS_ReqSeed;
//        Com_SendSignal(COMCONF_COMSIGNAL_PMS_AUTH__XQC0B_PMS_REQSEED_PMS_AUTH_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ReqSeed_PMS_ReqSeed = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RespResult_PMS_RespResult)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_RespResult_PMS_RespResult;
//        Com_SendSignal(COMCONF_COMSIGNAL_PMS_AUTH__XQC0B_PMS_RESPRESULT_PMS_AUTH_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RespResult_PMS_RespResult = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_SelfCheckSts_PMS_SelfCheckSts)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_SelfCheckSts_PMS_SelfCheckSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_COMMAND_RMXR12_PMS_SELFCHECKSTS_PMS_COMMAND_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_SelfCheckSts_PMS_SelfCheckSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_COMMAND__XQC0B_PMS_SELFCHECKSTS_PMS_COMMAND_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_SelfCheckSts_PMS_SelfCheckSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_SoftwareMajorVer_PMS_SoftwareMajorVer)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_SoftwareMajorVer_PMS_SoftwareMajorVer;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VERINFO__XQC0B_PMS_SOFTWAREMAJORVER_PMS_VERINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_SoftwareMajorVer_PMS_SoftwareMajorVer = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_SoftwareMinorVer_PMS_SoftwareMinorVer)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_SoftwareMinorVer_PMS_SoftwareMinorVer;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VERINFO__XQC0B_PMS_SOFTWAREMINORVER_PMS_VERINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_SoftwareMinorVer_PMS_SoftwareMinorVer = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_SpdLmtLevel_PMS_SpdLmtLevel)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_SpdLmtLevel_PMS_SpdLmtLevel;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_INSTRUCT__XQC0B_PMS_SPDLMTLEVEL_PMS_INSTRUCT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_SpdLmtLevel_PMS_SpdLmtLevel = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_SpdLmtLevelRxSts_PMS_SpdLmtLevelRxSts)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_SpdLmtLevelRxSts_PMS_SpdLmtLevelRxSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_INSTRUCT__XQC0B_PMS_SPDLMTLEVELRXSTS_PMS_INSTRUCT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_SpdLmtLevelRxSts_PMS_SpdLmtLevelRxSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_StartActive_PMS_StartActive)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_StartActive_PMS_StartActive;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL1_FVS55R_PMS_STARTACTIVE_PMS_CSCONTROL1_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_StartActive_PMS_StartActive;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL1__XQC0B_PMS_STARTACTIVE_PMS_CSCONTROL1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_StartActive_PMS_StartActive = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_StsBrkSwitch1Invalid_PMS_PMS_StsBrkSwitch1Invalid_PMS)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_StsBrkSwitch1Invalid_PMS_PMS_StsBrkSwitch1Invalid_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_STSEPT_RMXR12_PMS_STSBRKSWITCH1INVALID_PMS_STSEPT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_StsBrkSwitch1Invalid_PMS_PMS_StsBrkSwitch1Invalid_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_STSEPT_FVS55R_PMS_STSBRKSWITCH1INVALID_PMS_STSEPT_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_StsBrkSwitch1Invalid_PMS_PMS_StsBrkSwitch1Invalid_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_STSEPT__XQC0B_PMS_STSBRKSWITCH1INVALID_PMS_STSEPT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_StsBrkSwitch1Invalid_PMS_PMS_StsBrkSwitch1Invalid_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_StsBrkSwitch1_PMS_PMS_StsBrkSwitch1_PMS)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_StsBrkSwitch1_PMS_PMS_StsBrkSwitch1_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_STSEPT_RMXR12_PMS_STSBRKSWITCH1_PMS_STSEPT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_StsBrkSwitch1_PMS_PMS_StsBrkSwitch1_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_STSEPT_FVS55R_PMS_STSBRKSWITCH1_PMS_STSEPT_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_StsBrkSwitch1_PMS_PMS_StsBrkSwitch1_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_STSEPT__XQC0B_PMS_STSBRKSWITCH1_PMS_STSEPT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_StsBrkSwitch1_PMS_PMS_StsBrkSwitch1_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_StsSwap_PMS_StsSwap)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_StsSwap_PMS_StsSwap;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_STSSWAP_RMXR12_PMS_STSSWAP_PMS_STSSWAP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_StsSwap_PMS_StsSwap;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VEHICLEINFO_RMXR12_VCU_EVCAN_STSSWAP_PMS_VEHICLEINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_StsSwap_PMS_StsSwap;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_STSSWAP__XQC0B_PMS_STSSWAP_PMS_STSSWAP_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_StsSwap_PMS_StsSwap = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_SwapAuthRelease_EV_PMS_SwapAuthRelease_EV)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_SwapAuthRelease_EV_PMS_SwapAuthRelease_EV;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_STSSWAP_RMXR12_PMS_STSBATLOCKSENSOR_PMS_STSSWAP_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_SwapAuthRelease_EV_PMS_SwapAuthRelease_EV;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_STSSWAP__XQC0B_PMS_STSBATLOCKSENSOR_PMS_STSSWAP_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_SwapAuthRelease_EV_PMS_SwapAuthRelease_EV = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TBOX_BrkSysErr_PMS_TBOX_BrkSysErr)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_TBOX_BrkSysErr_PMS_TBOX_BrkSysErr;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_PMS_TBOX_BRKSYSERR_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TBOX_BrkSysErr_PMS_TBOX_BrkSysErr = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_TBOX_BRKSYSERR1_PMS_PMS_TBOX_BRKSYSERR1_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_PMS_TBOX_BRKSYSERR1_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_TBOX_BRKSYSERR1_PMS_PMS_TBOX_BRKSYSERR1_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TBOX_HVILSts_PMS_TBOX_HVILSts)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_TBOX_HVILSts_PMS_TBOX_HVILSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_PMS_TBOX_HVILSTS_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TBOX_HVILSts_PMS_TBOX_HVILSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS)
    {
        (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_TBOX_HVILSTS1_PMS_PMS_TBOX_HVILSTS1_PMS);
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_PMS_TBOX_HVILSTS1_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
        (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_TBOX_HVILSTS1_PMS_PMS_TBOX_HVILSTS1_PMS);
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TBOX_LifeSts_PMS_TBOX_LifeSts)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_TBOX_LifeSts_PMS_TBOX_LifeSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_INSTRUCT__XQC0B_PMS_TBOX_LIFESTS_PMS_INSTRUCT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TBOX_LifeSts_PMS_TBOX_LifeSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TakeEleSwtIndReq_PMS_TakeEleSwtIndReq)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_TakeEleSwtIndReq_PMS_TakeEleSwtIndReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_RMXR12_PMS_TAKEELESWTINDREQ_PMS_CTRL1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_TakeEleSwtIndReq_PMS_TakeEleSwtIndReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_FVS55R_PMS_TAKEELESWTINDREQ_PMS_CTRL1_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_TakeEleSwtIndReq_PMS_TakeEleSwtIndReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1__XQC0B_PMS_TAKEELESWTINDREQ_PMS_CTRL1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TakeEleSwtIndReq_PMS_TakeEleSwtIndReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Torque_Ovrd_Active_PMS_Torque_Ovrd_Active)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_Torque_Ovrd_Active_PMS_Torque_Ovrd_Active;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_RMXR12_PMS_TORQUE_OVRD_ACTIVE_PMS_MODECONTROL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_Torque_Ovrd_Active_PMS_Torque_Ovrd_Active;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_FVS55R_PMS_TORQUE_OVRD_ACTIVE_PMS_MODECONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_Torque_Ovrd_Active_PMS_Torque_Ovrd_Active;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL__XQC0B_PMS_TORQUE_OVRD_ACTIVE_PMS_MODECONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Torque_Ovrd_Active_PMS_Torque_Ovrd_Active = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Torque_Ovrd_Type_PMS_Torque_Ovrd_Type)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_Torque_Ovrd_Type_PMS_Torque_Ovrd_Type;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_RMXR12_PMS_TORQUE_OVRD_TYPE_PMS_MODECONTROL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_Torque_Ovrd_Type_PMS_Torque_Ovrd_Type;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL_FVS55R_PMS_TORQUE_OVRD_TYPE_PMS_MODECONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_Torque_Ovrd_Type_PMS_Torque_Ovrd_Type;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MODECONTROL__XQC0B_PMS_TORQUE_OVRD_TYPE_PMS_MODECONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Torque_Ovrd_Type_PMS_Torque_Ovrd_Type = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TurtleLampOn_PMS_TurtleLampOn)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_TurtleLampOn_PMS_TurtleLampOn;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_RMXR12_PMS_TURTLELAMPON_PMS_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_TurtleLampOn_PMS_TurtleLampOn;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_FVS55R_PMS_TURTLELAMPON_PMS_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_TurtleLampOn_PMS_TurtleLampOn;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL__XQC0B_PMS_TURTLELAMPON_PMS_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TurtleLampOn_PMS_TurtleLampOn = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TurtleLampOn2_PMS_TurtleLampOn2)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_TurtleLampOn2_PMS_TurtleLampOn2;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2_FVS55R_PMS_TURTLELAMPON2_PMS_CSCONTROL2_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_TurtleLampOn2_PMS_TurtleLampOn2;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2__XQC0B_PMS_TURTLELAMPON2_PMS_CSCONTROL2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TurtleLampOn2_PMS_TurtleLampOn2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_V2XDchaSwtFb1_PMS_V2XDchaSwtFb1)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_V2XDchaSwtFb1_PMS_V2XDchaSwtFb1;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_MMI_SWITCHFB__XQC0B_PMS_V2XDCHASWTFB1_PMS_MMI_SWITCHFB_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_V2XDchaSwtFb1_PMS_V2XDchaSwtFb1 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode1_8_15_S_PMS_VINCode1_8_15_S)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_VINCode1_8_15_S_PMS_VINCode1_8_15_S;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VIN_RMXR12_PMS_VINCODE1_8_15_S_PMS_VIN_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_VINCode1_8_15_S_PMS_VINCode1_8_15_S;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VIN__XQC0B_PMS_VINCODE1_8_15_S_PMS_VIN_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode1_8_15_S_PMS_VINCode1_8_15_S = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode2_9_16_S_PMS_VINCode2_9_16_S)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_VINCode2_9_16_S_PMS_VINCode2_9_16_S;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VIN_RMXR12_PMS_VINCODE2_9_16_S_PMS_VIN_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_VINCode2_9_16_S_PMS_VINCode2_9_16_S;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VIN__XQC0B_PMS_VINCODE2_9_16_S_PMS_VIN_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode2_9_16_S_PMS_VINCode2_9_16_S = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode3_10_17_S_PMS_VINCode3_10_17_S)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_VINCode3_10_17_S_PMS_VINCode3_10_17_S;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VIN_RMXR12_PMS_VINCODE3_10_17_S_PMS_VIN_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_VINCode3_10_17_S_PMS_VINCode3_10_17_S;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VIN__XQC0B_PMS_VINCODE3_10_17_S_PMS_VIN_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode3_10_17_S_PMS_VINCode3_10_17_S = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode4_11_S_PMS_VINCode4_11_S)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_VINCode4_11_S_PMS_VINCode4_11_S;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VIN_RMXR12_PMS_VINCODE4_11_S_PMS_VIN_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_VINCode4_11_S_PMS_VINCode4_11_S;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VIN__XQC0B_PMS_VINCODE4_11_S_PMS_VIN_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode4_11_S_PMS_VINCode4_11_S = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode5_12_S_PMS_VINCode5_12_S)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_VINCode5_12_S_PMS_VINCode5_12_S;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VIN_RMXR12_PMS_VINCODE5_12_S_PMS_VIN_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_VINCode5_12_S_PMS_VINCode5_12_S;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VIN__XQC0B_PMS_VINCODE5_12_S_PMS_VIN_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode5_12_S_PMS_VINCode5_12_S = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode6_13_S_PMS_VINCode6_13_S)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_VINCode6_13_S_PMS_VINCode6_13_S;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VIN_RMXR12_PMS_VINCODE6_13_S_PMS_VIN_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_VINCode6_13_S_PMS_VINCode6_13_S;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VIN__XQC0B_PMS_VINCODE6_13_S_PMS_VIN_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode6_13_S_PMS_VINCode6_13_S = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode7_14_S_PMS_VINCode7_14_S)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_VINCode7_14_S_PMS_VINCode7_14_S;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VIN_RMXR12_PMS_VINCODE7_14_S_PMS_VIN_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_VINCode7_14_S_PMS_VINCode7_14_S;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VIN__XQC0B_PMS_VINCODE7_14_S_PMS_VIN_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode7_14_S_PMS_VINCode7_14_S = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINMessageNum_S_PMS_VINMessageNum_S)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_VINMessageNum_S_PMS_VINMessageNum_S;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VIN_RMXR12_PMS_VINMESSAGENUM_S_PMS_VIN_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_VINMessageNum_S_PMS_VINMessageNum_S;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VIN__XQC0B_PMS_VINMESSAGENUM_S_PMS_VIN_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINMessageNum_S_PMS_VINMessageNum_S = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VacuumPressure_PMS_VacuumPressure)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_PMS_VacuumPressure_PMS_VacuumPressure;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL_FVS55R_PMS_VACUUMPRESSURE_PMS_ENGCONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_VCOP_PMS_VacuumPressure_PMS_VacuumPressure;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL__XQC0B_PMS_VACUUMPRESSURE_PMS_ENGCONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VacuumPressure_PMS_VacuumPressure = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VacuumPumpCmd_PMS_VacuumPumpCmd)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_VacuumPumpCmd_PMS_VacuumPumpCmd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6_RMXR12_PMS_VACUUMPUMPCMD_PMS_HARDINFOR6_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_VacuumPumpCmd_PMS_VacuumPumpCmd;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6__XQC0B_PMS_VACUUMPUMPCMD_PMS_HARDINFOR6_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VacuumPumpCmd_PMS_VacuumPumpCmd = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VacuumPump_FB_PMS_VacuumPump_FB)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_VacuumPump_FB_PMS_VacuumPump_FB;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6_RMXR12_PMS_VACUUMPUMP_FB_PMS_HARDINFOR6_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_VacuumPump_FB_PMS_VacuumPump_FB;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6__XQC0B_PMS_VACUUMPUMP_FB_PMS_HARDINFOR6_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VacuumPump_FB_PMS_VacuumPump_FB = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VacuumSystemsta_PMS_VacuumSystemsta)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_VacuumSystemsta_PMS_VacuumSystemsta;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL_FVS55R_PMS_VACUUMSYSTEMSTA_PMS_ENGCONTROL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_VacuumSystemsta_PMS_VacuumSystemsta;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_ENGCONTROL__XQC0B_PMS_VACUUMSYSTEMSTA_PMS_ENGCONTROL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VacuumSystemsta_PMS_VacuumSystemsta = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VehicleSpeed_PMS_VehicleSpeed)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_PMS_VehicleSpeed_PMS_VehicleSpeed;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_STSEPT_RMXR12_PMS_VEHICLESPEED_PMS_STSEPT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_VCOP_PMS_VehicleSpeed_PMS_VehicleSpeed;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6_RMXR12_PMS_VEHICLESPEED_PMS_HARDINFOR6_PMS_EV_CAN_20260427_DBC_TX, &phydata_1);
        uint16 phydata_2 = (uint16)Rte_swc_VCOP_PMS_VehicleSpeed_PMS_VehicleSpeed;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_STSEPT_FVS55R_PMS_VEHICLESPEED_PMS_STSEPT_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_2);
        uint16 phydata_3 = (uint16)Rte_swc_VCOP_PMS_VehicleSpeed_PMS_VehicleSpeed;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_STSEPT__XQC0B_PMS_VEHICLESPEED_PMS_STSEPT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_3);
        uint16 phydata_4 = (uint16)Rte_swc_VCOP_PMS_VehicleSpeed_PMS_VehicleSpeed;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6__XQC0B_PMS_VEHICLESPEED_PMS_HARDINFOR6_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_4);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VehicleSpeed_PMS_VehicleSpeed = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_STSEPT_RMXR12_PMS_VEHICLESPEEDINVALID_PMS_STSEPT_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6_RMXR12_PMS_VEHICLESPEEDINVALID_PMS_HARDINFOR6_PMS_EV_CAN_20260427_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_STSEPT_FVS55R_PMS_VEHICLESPEEDINVALID_PMS_STSEPT_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_2);
        boolean phydata_3 = (boolean)Rte_swc_VCOP_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_STSEPT__XQC0B_PMS_VEHICLESPEEDINVALID_PMS_STSEPT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_3);
        boolean phydata_4 = (boolean)Rte_swc_VCOP_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_HARDINFOR6__XQC0B_PMS_VEHICLESPEEDINVALID_PMS_HARDINFOR6_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_4);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VehicleSysErrorLevel_PMS_VehicleSysErrorLevel)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_VehicleSysErrorLevel_PMS_VehicleSysErrorLevel;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_RMXR12_PMS_VEHICLESYSERRORLEVEL_PMS_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_VehicleSysErrorLevel_PMS_VehicleSysErrorLevel;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_FVS55R_PMS_VEHICLESYSERRORLEVEL_PMS_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_VehicleSysErrorLevel_PMS_VehicleSysErrorLevel;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL__XQC0B_PMS_VEHICLESYSERRORLEVEL_PMS_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VehicleSysErrorLevel_PMS_VehicleSysErrorLevel = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VehicleSysErrorLevelG_PMS_VehicleSysErrorLevelG)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_VehicleSysErrorLevelG_PMS_VehicleSysErrorLevelG;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT__XQC0B_PMS_VEHICLESYSERRORLEVELG_PMS_TBOX_FAULT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VehicleSysErrorLevelG_PMS_VehicleSysErrorLevelG = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VehicleSysErrorLevelG1_PMS_PMS_VehicleSysErrorLevelG1_PMS)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_VehicleSysErrorLevelG1_PMS_PMS_VehicleSysErrorLevelG1_PMS;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_TBOX_FAULT1__XQC0B_PMS_VEHICLESYSERRORLEVELG1_PMS_TBOX_FAULT1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VehicleSysErrorLevelG1_PMS_PMS_VehicleSysErrorLevelG1_PMS = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VersionConversionFlag_PMS_VersionConversionFlag)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_VersionConversionFlag_PMS_VersionConversionFlag;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_INSTRUCT__XQC0B_PMS_VERSIONCONVERSIONFLAG_PMS_INSTRUCT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VersionConversionFlag_PMS_VersionConversionFlag = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VersionConversionRxSts_PMS_VersionConversionRxSts)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_VersionConversionRxSts_PMS_VersionConversionRxSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_INSTRUCT__XQC0B_PMS_VERSIONCONVERSIONRXSTS_PMS_INSTRUCT_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VersionConversionRxSts_PMS_VersionConversionRxSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_RMXR12_PMS_ZEROPWR_FB_PMS_CTRL1_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1_FVS55R_PMS_ZEROPWR_FB_PMS_CTRL1_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL1__XQC0B_PMS_ZEROPWR_FB_PMS_CTRL1_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ePTFault_PMS_ePTFault)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_ePTFault_PMS_ePTFault;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_RMXR12_PMS_EPTFAULT_PMS_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_ePTFault_PMS_ePTFault;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_FVS55R_PMS_EPTFAULT_PMS_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_ePTFault_PMS_ePTFault;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL__XQC0B_PMS_EPTFAULT_PMS_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ePTFault_PMS_ePTFault = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ePTFault2_PMS_ePTFault2)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_ePTFault2_PMS_ePTFault2;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2_FVS55R_PMS_EPTFAULT2_PMS_CSCONTROL2_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_ePTFault2_PMS_ePTFault2;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CSCONTROL2__XQC0B_PMS_EPTFAULT2_PMS_CSCONTROL2_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ePTFault2_PMS_ePTFault2 = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ePTModeActual_PMS_ePTModeActual)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_ePTModeActual_PMS_ePTModeActual;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_RMXR12_PMS_EPTMODEACTUAL_PMS_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_ePTModeActual_PMS_ePTModeActual;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_FVS55R_PMS_EPTMODEACTUAL_PMS_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_ePTModeActual_PMS_ePTModeActual;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL__XQC0B_PMS_EPTMODEACTUAL_PMS_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ePTModeActual_PMS_ePTModeActual = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ePTModeSelect_PMS_ePTModeSelect)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_ePTModeSelect_PMS_ePTModeSelect;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_RMXR12_PMS_EPTMODESELECT_PMS_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_ePTModeSelect_PMS_ePTModeSelect;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_FVS55R_PMS_EPTMODESELECT_PMS_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_ePTModeSelect_PMS_ePTModeSelect;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL__XQC0B_PMS_EPTMODESELECT_PMS_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ePTModeSelect_PMS_ePTModeSelect = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ePTReady_PMS_ePTReady)
    {
        boolean phydata_0 = (boolean)Rte_swc_VCOP_PMS_ePTReady_PMS_ePTReady;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_RMXR12_PMS_EPTREADY_PMS_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        boolean phydata_1 = (boolean)Rte_swc_VCOP_PMS_ePTReady_PMS_ePTReady;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_FVS55R_PMS_EPTREADY_PMS_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        boolean phydata_2 = (boolean)Rte_swc_VCOP_PMS_ePTReady_PMS_ePTReady;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL__XQC0B_PMS_EPTREADY_PMS_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ePTReady_PMS_ePTReady = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ePTReleaseSig_PMS_ePTReleaseSig)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_PMS_ePTReleaseSig_PMS_ePTReleaseSig;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_RMXR12_PMS_EPTRELEASESIG_PMS_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_PMS_ePTReleaseSig_PMS_ePTReleaseSig;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL_FVS55R_PMS_EPTRELEASESIG_PMS_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_PMS_ePTReleaseSig_PMS_ePTReleaseSig;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_CTRL__XQC0B_PMS_EPTRELEASESIG_PMS_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ePTReleaseSig_PMS_ePTReleaseSig = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_TBOX_ChrgSoftSwCtrlst_EV_TBOX_ChrgSoftSwCtrlst_EV)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_TBOX_ChrgSoftSwCtrlst_EV_TBOX_ChrgSoftSwCtrlst_EV;
        Com_SendSignal(COMCONF_COMSIGNAL_TBOX_REMCON_RMXR12_TBOX_CHRGSOFTSWCTRLST_TBOX_REMCON_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_TBOX_ChrgSoftSwCtrlst_EV_TBOX_ChrgSoftSwCtrlst_EV = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_TBOX_ReservationChrgnSts_EV_TBOX_ReservationChrgnSts_EV)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_TBOX_ReservationChrgnSts_EV_TBOX_ReservationChrgnSts_EV;
        Com_SendSignal(COMCONF_COMSIGNAL_TBOX_REMCON_RMXR12_TBOX_RESERVATIONCHRGNSTS_TBOX_REMCON_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_TBOX_ReservationChrgnSts_EV_TBOX_ReservationChrgnSts_EV = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_ActInputVolt_VCU_ActInputVolt)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_VCU_ActInputVolt_VCU_ActInputVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL_RMXR12_VCU_ACTINPUTVOLT_PMS_BMSH_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_VCOP_VCU_ActInputVolt_VCU_ActInputVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL_FVS55R_VCU_ACTINPUTVOLT_PMS_BMSH_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint16 phydata_2 = (uint16)Rte_swc_VCOP_VCU_ActInputVolt_VCU_ActInputVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL__XQC0B_VCU_ACTINPUTVOLT_PMS_BMSH_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_ActInputVolt_VCU_ActInputVolt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VEHICLEINFO_RMXR12_VCU_BMSH_ALLOWCHGCURRENTMAX_PMS_VEHICLEINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VEHICLEINFO__XQC0B_VCU_BMSH_ALLOWCHGCURRENTMAX_PMS_VEHICLEINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_BMSH_Ctrl_CheckSum_VCU_BMSH_Ctrl_CheckSum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_VCU_BMSH_Ctrl_CheckSum_VCU_BMSH_Ctrl_CheckSum;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL_RMXR12_VCU_BMSH_CTRL_CHECKSUM_PMS_BMSH_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_VCU_BMSH_Ctrl_CheckSum_VCU_BMSH_Ctrl_CheckSum;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL_FVS55R_VCU_BMSH_CTRL_CHECKSUM_PMS_BMSH_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_VCU_BMSH_Ctrl_CheckSum_VCU_BMSH_Ctrl_CheckSum;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL__XQC0B_VCU_BMSH_CTRL_CHECKSUM_PMS_BMSH_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_BMSH_Ctrl_CheckSum_VCU_BMSH_Ctrl_CheckSum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_BMSH_DCChgRelayVolt_VCU_BMSH_DCChgRelayVolt)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_VCU_BMSH_DCChgRelayVolt_VCU_BMSH_DCChgRelayVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL_RMXR12_VCU_BMSH_DCCHGRELAYVOLT_PMS_BMSH_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_VCU_BMSH_DCChgRelayVolt_VCU_BMSH_DCChgRelayVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL_FVS55R_VCU_BMSH_DCCHGRELAYVOLT_PMS_BMSH_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_VCU_BMSH_DCChgRelayVolt_VCU_BMSH_DCChgRelayVolt;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL__XQC0B_VCU_BMSH_DCCHGRELAYVOLT_PMS_BMSH_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_BMSH_DCChgRelayVolt_VCU_BMSH_DCChgRelayVolt = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL_RMXR12_VCU_BMSH_INLET_WATERTEMP_PMS_DCDC_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL__XQC0B_VCU_BMSH_INLET_WATERTEMP_PMS_DCDC_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL_RMXR12_VCU_BMSH_OUTLET_WATERTEMP_PMS_DCDC_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_DCDC_CTRL__XQC0B_VCU_BMSH_OUTLET_WATERTEMP_PMS_DCDC_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL_RMXR12_VCU_BMSH_STSMODEREQ_PMS_BMSH_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL_FVS55R_VCU_BMSH_STSMODEREQ_PMS_BMSH_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL__XQC0B_VCU_BMSH_STSMODEREQ_PMS_BMSH_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_ChargeDepthReq_VCU_ChargeDepthReq)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_VCU_ChargeDepthReq_VCU_ChargeDepthReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VEHICLEINFO_RMXR12_VCU_CHARGEDEPTHREQ_PMS_VEHICLEINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_VCU_ChargeDepthReq_VCU_ChargeDepthReq;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VEHICLEINFO__XQC0B_VCU_CHARGEDEPTHREQ_PMS_VEHICLEINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_ChargeDepthReq_VCU_ChargeDepthReq = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_CrashOutputSts_VCU_CrashOutputSts)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_VCU_CrashOutputSts_VCU_CrashOutputSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL_RMXR12_VCU_CRASHOUTPUTSTS_PMS_BMSH_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_VCU_CrashOutputSts_VCU_CrashOutputSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL_FVS55R_VCU_CRASHOUTPUTSTS_PMS_BMSH_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_VCU_CrashOutputSts_VCU_CrashOutputSts;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL__XQC0B_VCU_CRASHOUTPUTSTS_PMS_BMSH_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_CrashOutputSts_VCU_CrashOutputSts = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_DCInputCurrent_VCU_DCInputCurrent)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_VCU_DCInputCurrent_VCU_DCInputCurrent;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VEHICLEINFO_RMXR12_VCU_DCINPUTCURRENT_PMS_VEHICLEINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_VCU_DCInputCurrent_VCU_DCInputCurrent;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VEHICLEINFO__XQC0B_VCU_DCINPUTCURRENT_PMS_VEHICLEINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_DCInputCurrent_VCU_DCInputCurrent = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_Odometerbackup_VCU_Odometerbackup)
    {
        uint16 phydata_0 = (uint16)Rte_swc_VCOP_VCU_Odometerbackup_VCU_Odometerbackup;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VEHICLEINFO_RMXR12_VCU_ODOMETERBACKUP_PMS_VEHICLEINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint16 phydata_1 = (uint16)Rte_swc_VCOP_VCU_Odometerbackup_VCU_Odometerbackup;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VEHICLEINFO__XQC0B_VCU_ODOMETERBACKUP_PMS_VEHICLEINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_Odometerbackup_VCU_Odometerbackup = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL_RMXR12_VCU_PMS_APPOWERACTUAL_PMS_BMSH_CTRL_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL_FVS55R_VCU_PMS_APPOWERACTUAL_PMS_BMSH_CTRL_N72__PMS_C_CAN_20260425_DBC_TX, &phydata_1);
        uint8 phydata_2 = (uint8)Rte_swc_VCOP_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_BMSH_CTRL__XQC0B_VCU_PMS_APPOWERACTUAL_PMS_BMSH_CTRL_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_2);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

    if( RTE_COM_SENDSIGNALPROXY_SEND == Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_VehicleInfo_CheckSum_VCU_VehicleInfo_CheckSum)
    {
        uint8 phydata_0 = (uint8)Rte_swc_VCOP_VCU_VehicleInfo_CheckSum_VCU_VehicleInfo_CheckSum;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VEHICLEINFO_RMXR12_VCU_VEHICLEINFO_CHECKSUM_PMS_VEHICLEINFO_PMS_EV_CAN_20260427_DBC_TX, &phydata_0);
        uint8 phydata_1 = (uint8)Rte_swc_VCOP_VCU_VehicleInfo_CheckSum_VCU_VehicleInfo_CheckSum;
        Com_SendSignal(COMCONF_COMSIGNAL_PMS_VEHICLEINFO__XQC0B_VCU_VEHICLEINFO_CHECKSUM_PMS_VEHICLEINFO_N72__PMS_PT_CANFD_20260425_DBC_TX, &phydata_1);
        Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_VehicleInfo_CheckSum_VCU_VehicleInfo_CheckSum = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
    }

}


#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    COM Callbacks Function definition for Rx Update Notification
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) Rte_COMCbk_ACCM1_ActPower_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_AC_STATUS_SE_ACCM__XQC0B_ACCM1_ACTPOWER_AC_STATUS_SE_ACCM_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_ACCM1_ActPower_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_ACU_CrashOutputSts_ACU_ChimeTelltaleReq_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_ACU_CHIMETELLTALEREQ_FVS55R_ACU_CRASHOUTPUTSTS_ACU_CHIMETELLTALEREQ_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_ACU_CrashOutputSts_ACU_ChimeTelltaleReq_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_AC_ACCM_ActPower_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_AC_STATUS_INFO__XQC0B_AC_ACCM_ACTPOWER_AC_STATUS_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_AC_ACCM_ActPower_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_AC_ACCM_Status_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_AC_STATUS_INFO__XQC0B_AC_ACCM_STATUS_AC_STATUS_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_AC_ACCM_Status_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_AC_AmbientTemperatureInvalid_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_AC_STATUS_INFO__XQC0B_AC_AMBIENTTEMPERATUREINVALID_AC_STATUS_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_AC_AmbientTemperatureInvalid_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_AC_AmbientTemperature_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_AC_STATUS_INFO__XQC0B_AC_AMBIENTTEMPERATURE_AC_STATUS_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_AC_AmbientTemperature_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_AC_CabinThermalReq_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_AC_STATUS_INFO__XQC0B_AC_CABINTHERMALREQ_AC_STATUS_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_AC_CabinThermalReq_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_AC_CoolingFanPWMSpd_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_AC_STATUS_INFO__XQC0B_AC_COOLINGFANPWMSPD_AC_STATUS_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_AC_CoolingFanPWMSpd_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_AC_IPTC_ActPower_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_AC_STATUS_INFO__XQC0B_AC_IPTC_ACTPOWER_AC_STATUS_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_AC_IPTC_ActPower_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_AC_IPTC_WorkSts_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_AC_STATUS_INFO__XQC0B_AC_IPTC_WORKSTS_AC_STATUS_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_AC_IPTC_WorkSts_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_AC_PTC_ActPower_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_AC_STATUS_SE_ACCM__XQC0B_AC_PTC_ACTPOWER_AC_STATUS_SE_ACCM_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_AC_PTC_ActPower_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_AC_PTC_ActPwr_Rear_AC_Status_Info1_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_AC_STATUS_INFO1__XQC0B_AC_PTC_ACTPWR_REAR_AC_STATUS_INFO1_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_AC_PTC_ActPwr_Rear_AC_Status_Info1_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_AC_PTC_WorkSts_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_AC_STATUS_SE_ACCM__XQC0B_AC_PTC_WORKSTS_AC_STATUS_SE_ACCM_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_AC_PTC_WorkSts_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_AC_PTC_WorkSts_Rear_AC_Status_Info1_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_AC_STATUS_INFO1__XQC0B_AC_PTC_WORKSTS_REAR_AC_STATUS_INFO1_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_AC_PTC_WorkSts_Rear_AC_Status_Info1_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_BBM_FaultStatus_BBM_StsFB_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_BBM_STSFB__XQC0B_BBM_FAULTSTATUS_BBM_STSFB_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_BBM_FaultStatus_BBM_StsFB_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_BBM_WorkSts_BBM_StsFB_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_BBM_STSFB__XQC0B_BBM_WORKSTS_BBM_STSFB_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_BBM_WorkSts_BBM_StsFB_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_BCM_ATWS_St_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_BCM_STATEUPDATE__XQC0B_BCM_ATWS_ST_BCM_STATEUPDATE_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_BCM_ATWS_St_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_BCM_DoorLockStatusDrv_BCM_LDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_BCM_LDOORWINDOWSTATE__XQC0B_BCM_DOORLOCKSTATUSDRV_BCM_LDOORWINDOWSTATE_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_BCM_DoorLockStatusDrv_BCM_LDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_BCM_DoorLockStatusPass_BCM_RDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_BCM_RDOORWINDOWSTATE__XQC0B_BCM_DOORLOCKSTATUSPASS_BCM_RDOORWINDOWSTATE_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_BCM_DoorLockStatusPass_BCM_RDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_BCM_DrvSeatbeltBuckleInvalid_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_BCM_STATEUPDATE__XQC0B_BCM_DRVSEATBELTBUCKLEINVALID_BCM_STATEUPDATE_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_BCM_DrvSeatbeltBuckleInvalid_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_BCM_DrvSeatbeltBucklestatus_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_BCM_STATEUPDATE__XQC0B_BCM_DRVSEATBELTBUCKLESTATUS_BCM_STATEUPDATE_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_BCM_DrvSeatbeltBucklestatus_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_BCM_FrontLeftDoorAjarStatus_BCM_LDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_BCM_LDOORWINDOWSTATE__XQC0B_BCM_FRONTLEFTDOORAJARSTATUS_BCM_LDOORWINDOWSTATE_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_BCM_FrontLeftDoorAjarStatus_BCM_LDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_BCM_FrontRightDoorAjarStatus_BCM_RDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_BCM_RDOORWINDOWSTATE__XQC0B_BCM_FRONTRIGHTDOORAJARSTATUS_BCM_RDOORWINDOWSTATE_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_BCM_FrontRightDoorAjarStatus_BCM_RDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_BCM_IntelligentChargeCommand_BCM_ACCinfor_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_BCM_ACCINFOR__XQC0B_BCM_INTELLIGENTCHARGECOMMAND_BCM_ACCINFOR_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_BCM_IntelligentChargeCommand_BCM_ACCinfor_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_BCM_Odometerbackup_BCM_SunroofState_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_BCM_SUNROOFSTATE__XQC0B_BCM_ODOMETERBACKUP_BCM_SUNROOFSTATE_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_BCM_Odometerbackup_BCM_SunroofState_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CCS_ChargeAllow_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CCS_10NGGJ_CCS_CHARGEALLOW_CCS_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CCS_ChargeAllow_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CCS_ChargeTotalTime_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CCS_10NGGJ_CCS_CHARGETOTALTIME_CCS_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CCS_ChargeTotalTime_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CCS_OutputCurrent_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CCS_10NGGJ_CCS_OUTPUTCURRENT_CCS_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CCS_OutputCurrent_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CCS_OutputVoltage_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CCS_10NGGJ_CCS_OUTPUTVOLTAGE_CCS_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CCS_OutputVoltage_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CEM_BMSAbortChargeTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CEM_10NGGJ_CEM_BMSABORTCHARGETIMEOUT_CEM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CEM_BMSAbortChargeTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CEM_BMSChargeStatisticsTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CEM_10NGGJ_CEM_BMSCHARGESTATISTICSTIMEOUT_CEM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CEM_BMSChargeStatisticsTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CEM_BMSFinishChargeTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CEM_10NGGJ_CEM_BMSFINISHCHARGETIMEOUT_CEM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CEM_BMSFinishChargeTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CEM_BMSIdentifyTimout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CEM_10NGGJ_CEM_BMSIDENTIFYTIMOUT_CEM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CEM_BMSIdentifyTimout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CEM_BatteryChargeRequireTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CEM_10NGGJ_CEM_BATTERYCHARGEREQUIRETIMEOUT_CEM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CEM_BatteryChargeRequireTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CEM_BatteryParameterTimout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CEM_10NGGJ_CEM_BATTERYPARAMETERTIMOUT_CEM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CEM_BatteryParameterTimout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CEM_BatteryStateTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CEM_10NGGJ_CEM_BATTERYSTATETIMEOUT_CEM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CEM_BatteryStateTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CHM_ProtocolVersion_CHM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CHM_10NGGJ_CHM_PROTOCOLVERSION_CHM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CHM_ProtocolVersion_CHM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CML_OutpuVoltageMax_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CML_10NGGJ_CML_OUTPUVOLTAGEMAX_CML_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CML_OutpuVoltageMax_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CML_OutputCurrentMax_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CML_10NGGJ_CML_OUTPUTCURRENTMAX_CML_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CML_OutputCurrentMax_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CML_OutputCurrentMin_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CML_10NGGJ_CML_OUTPUTCURRENTMIN_CML_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CML_OutputCurrentMin_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CML_OutputVoltageMin_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CML_10NGGJ_CML_OUTPUTVOLTAGEMIN_CML_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CML_OutputVoltageMin_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CRM_RecognitionResult_CRM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CRM_10NGGJ_CRM_RECOGNITIONRESULT_CRM_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CRM_RecognitionResult_CRM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CRO_ChargerReady_CRO_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CRO_10NGGJ_CRO_CHARGERREADY_CRO_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CRO_ChargerReady_CRO_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CSD_OutputEnerge_CSD_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CSD_10NGGJ_CSD_OUTPUTENERGE_CSD_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CSD_OutputEnerge_CSD_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CSM_CampModeSwtInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CSM_SWITCHSTS__XQC0B_CSM_CAMPMODESWTINVALID_CSM_SWITCHSTS_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_CSM_CampModeSwtInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CSM_CampModeSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CSM_SWITCHSTS__XQC0B_CSM_CAMPMODESWT_CSM_SWITCHSTS_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_CSM_CampModeSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CSM_DriveModeReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CSM_SWITCHSTS__XQC0B_CSM_DRIVEMODEREQINVALID_CSM_SWITCHSTS_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_CSM_DriveModeReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CSM_DriveModeReq_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CSM_SWITCHSTS__XQC0B_CSM_DRIVEMODEREQ_CSM_SWITCHSTS_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_CSM_DriveModeReq_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CSM_EngRec_ReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CSM_SWITCHSTS__XQC0B_CSM_ENGREC_REQINVALID_CSM_SWITCHSTS_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_CSM_EngRec_ReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CSM_EngRec_Req_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CSM_SWITCHSTS__XQC0B_CSM_ENGREC_REQ_CSM_SWITCHSTS_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_CSM_EngRec_Req_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CSM_TakeEleSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CSM_SWITCHSTS__XQC0B_CSM_TAKEELESWT_CSM_SWITCHSTS_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_CSM_TakeEleSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CSM_TakeEleSwt_ReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CSM_SWITCHSTS__XQC0B_CSM_TAKEELESWT_REQINVALID_CSM_SWITCHSTS_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_CSM_TakeEleSwt_ReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CSM_V2XDchaSwtInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CSM_SWITCHSTS__XQC0B_CSM_V2XDCHASWTINVALID_CSM_SWITCHSTS_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_CSM_V2XDchaSwtInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CSM_V2XDchaSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CSM_SWITCHSTS__XQC0B_CSM_V2XDCHASWT_CSM_SWITCHSTS_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_CSM_V2XDchaSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortAchiveCondition_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CST_10NGGJ_CST_ABORTACHIVECONDITION_CST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CST_AbortAchiveCondition_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortByFault_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CST_10NGGJ_CST_ABORTBYFAULT_CST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CST_AbortByFault_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortByUser_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CST_10NGGJ_CST_ABORTBYUSER_CST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CST_AbortByUser_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortErrorCurrent_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CST_10NGGJ_CST_ABORTERRORCURRENT_CST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CST_AbortErrorCurrent_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortErrorVoltage_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CST_10NGGJ_CST_ABORTERRORVOLTAGE_CST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CST_AbortErrorVoltage_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortFaultChargerInnerTemp_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CST_10NGGJ_CST_ABORTFAULTCHARGERINNERTEMP_CST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CST_AbortFaultChargerInnerTemp_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortFaultChargerStop_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CST_10NGGJ_CST_ABORTFAULTCHARGERSTOP_CST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CST_AbortFaultChargerStop_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortFaultChargerTemp_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CST_10NGGJ_CST_ABORTFAULTCHARGERTEMP_CST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CST_AbortFaultChargerTemp_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortFaultConnetor_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CST_10NGGJ_CST_ABORTFAULTCONNETOR_CST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CST_AbortFaultConnetor_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortFaultEnergeTransmit_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CST_10NGGJ_CST_ABORTFAULTENERGETRANSMIT_CST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CST_AbortFaultEnergeTransmit_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortFaultOther_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_CST_10NGGJ_CST_ABORTFAULTOTHER_CST_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_DBC_RX, &Rte_ComBuffer_CST_AbortFaultOther_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_AccessoryConnStsFb_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_DCDC_FAULTINFO_RMXR12_DCDC_ACCESSORYCONNSTSFB_DCDC_FAULTINFO_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_DCDC_AccessoryConnStsFb_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_CANComFault_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_DCDC_FAULTINFO_RMXR12_DCDC_CANCOMFAULT_DCDC_FAULTINFO_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_DCDC_CANComFault_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_CutOffLVFb_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_DCDC_LV_INFO_RMXR12_DCDC_CUTOFFLVFB_DCDC_LV_INFO_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_DCDC_CutOffLVFb_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_FaultLevel1_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_DCDC_FAULTINFO_RMXR12_DCDC_FAULTLEVEL1_DCDC_FAULTINFO_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_DCDC_FaultLevel1_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_IDCDCActHiside1_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_DCDC_HV_INFO_RMXR12_DCDC_IDCDCACTHISIDE1_DCDC_HV_INFO_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_DCDC_IDCDCActHiside1_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_IDcDcActLoSide_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_DCDC_LV_INFO_RMXR12_DCDC_IDCDCACTLOSIDE_DCDC_LV_INFO_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_DCDC_IDcDcActLoSide_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_OutOverCurr_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_DCDC_FAULTINFO_RMXR12_DCDC_OUTOVERCURR_DCDC_FAULTINFO_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_DCDC_OutOverCurr_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_OutOverVolt_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_DCDC_FAULTINFO_RMXR12_DCDC_OUTOVERVOLT_DCDC_FAULTINFO_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_DCDC_OutOverVolt_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_PTCConnStsFb_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_DCDC_FAULTINFO_RMXR12_DCDC_PTCCONNSTSFB_DCDC_FAULTINFO_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_DCDC_PTCConnStsFb_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_Relay_Volt_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_DCDC_HV_INFO_RMXR12_DCDC_RELAY_VOLT_DCDC_HV_INFO_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_DCDC_Relay_Volt_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_SelfChkSts_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_DCDC_LV_INFO_RMXR12_DCDC_SELFCHKSTS_DCDC_LV_INFO_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_DCDC_SelfChkSts_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_TDcDc_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_DCDC_LV_INFO_RMXR12_DCDC_TDCDC_DCDC_LV_INFO_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_DCDC_TDcDc_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_UDCDCActHiside_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_DCDC_HV_INFO_RMXR12_DCDC_UDCDCACTHISIDE_DCDC_HV_INFO_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_DCDC_UDCDCActHiside_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_UDcDcActLoSide_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_DCDC_LV_INFO_RMXR12_DCDC_UDCDCACTLOSIDE_DCDC_LV_INFO_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_DCDC_UDcDcActLoSide_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_DcDcActvd_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_DCDC_LV_INFO_RMXR12_DCDCACTVD_DCDC_LV_INFO_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_DcDcActvd_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_DcDcStsAlm_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_DCDC_LV_INFO_RMXR12_DCDCSTSALM_DCDC_LV_INFO_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_DcDcStsAlm_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EGSM_LeverPosition_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EGSM_STATUS_RMXR12_EGSM_LEVERPOSITION_EGSM_STATUS_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_EGSM_LeverPosition_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EGSM_ParkReq_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EGSM_STATUS_RMXR12_EGSM_PARKREQ_EGSM_STATUS_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_EGSM_ParkReq_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EGSM_ShiftleverFailSt_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EGSM_STATUS_RMXR12_EGSM_SHIFTLEVERFAILST_EGSM_STATUS_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_EGSM_ShiftleverFailSt_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_ABSActive_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_STATUS_FVS55R_EHB_ABSACTIVE_EHB_STATUS_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_ABSActive_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_ABSFailed_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_STATUS_FVS55R_EHB_ABSFAILED_EHB_STATUS_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_ABSFailed_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_AEB_active_EHB_DA_MESSAGE_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_DA_MESSAGE_FVS55R_EHB_AEB_ACTIVE_EHB_DA_MESSAGE_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_AEB_active_EHB_DA_MESSAGE_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_AVHStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_STATUS_FVS55R_EHB_AVHSTATUS_EHB_STATUS_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_AVHStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_BrkSysErrFault_EHB_DriverRemind_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_DRIVERREMIND_FVS55R_EHB_BRKSYSERRFAULT_EHB_DRIVERREMIND_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_BrkSysErrFault_EHB_DriverRemind_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_DTC_Active_EHB_DA_MESSAGE_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_DA_MESSAGE_FVS55R_EHB_DTC_ACTIVE_EHB_DA_MESSAGE_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_DTC_Active_EHB_DA_MESSAGE_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_EPBErrorStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_STATUS_FVS55R_EHB_EPBERRORSTATUS_EHB_STATUS_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_EPBErrorStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_EPBStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_STATUS_FVS55R_EHB_EPBSTATUS_EHB_STATUS_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_EPBStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_EPB_DynamicApplystatus_EHB_DriverRemind_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_DRIVERREMIND_FVS55R_EHB_EPB_DYNAMICAPPLYSTATUS_EHB_DRIVERREMIND_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_EPB_DynamicApplystatus_EHB_DriverRemind_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_FLWheelDirection_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_FRONTWHEELSPEEDSKPH_FVS55R_EHB_FLWHEELDIRECTION_EHB_FRONTWHEELSPEEDSKPH_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_FLWheelDirection_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_FLWheelSpeedInvalid_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_FRONTWHEELSPEEDSKPH_FVS55R_EHB_FLWHEELSPEEDINVALID_EHB_FRONTWHEELSPEEDSKPH_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_FLWheelSpeedInvalid_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_FLWheelSpeedKPH_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_FRONTWHEELSPEEDSKPH_FVS55R_EHB_FLWHEELSPEEDKPH_EHB_FRONTWHEELSPEEDSKPH_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_FLWheelSpeedKPH_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_FRWheelDirection_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_FRONTWHEELSPEEDSKPH_FVS55R_EHB_FRWHEELDIRECTION_EHB_FRONTWHEELSPEEDSKPH_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_FRWheelDirection_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_FRWheelSpeedInvalid_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_FRONTWHEELSPEEDSKPH_FVS55R_EHB_FRWHEELSPEEDINVALID_EHB_FRONTWHEELSPEEDSKPH_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_FRWheelSpeedInvalid_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_FRWheelSpeedKPH_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_FRONTWHEELSPEEDSKPH_FVS55R_EHB_FRWHEELSPEEDKPH_EHB_FRONTWHEELSPEEDSKPH_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_FRWheelSpeedKPH_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_HHCActive_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_STATUS_FVS55R_EHB_HHCACTIVE_EHB_STATUS_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_HHCActive_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_ISA_PTTrqDecReqActive_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_ISAREQUEST_FVS55R_EHB_ISA_PTTRQDECREQACTIVE_EHB_ISAREQUEST_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_ISA_PTTrqDecReqActive_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_ISA_PTTrqDecReq_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_ISAREQUEST_FVS55R_EHB_ISA_PTTRQDECREQ_EHB_ISAREQUEST_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_ISA_PTTrqDecReq_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_ISA_Status_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_ISAREQUEST_FVS55R_EHB_ISA_STATUS_EHB_ISAREQUEST_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_ISA_Status_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_MbRegenTargetWheelSts_EHB_Regen_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_REGEN_FVS55R_EHB_MBREGENTARGETWHEELSTS_EHB_REGEN_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_MbRegenTargetWheelSts_EHB_Regen_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_MbRegenTargetWheel_EHB_Regen_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_REGEN_FVS55R_EHB_MBREGENTARGETWHEEL_EHB_REGEN_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_MbRegenTargetWheel_EHB_Regen_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_PTTrqDecReqActive_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_PTTORQUEREQUEST_FVS55R_EHB_PTTRQDECREQACTIVE_EHB_PTTORQUEREQUEST_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_PTTrqDecReqActive_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_PTTrqDecReq_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_PTTORQUEREQUEST_FVS55R_EHB_PTTRQDECREQ_EHB_PTTORQUEREQUEST_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_PTTrqDecReq_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_PTTrqIncReqActive_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_PTTORQUEREQUEST_FVS55R_EHB_PTTRQINCREQACTIVE_EHB_PTTORQUEREQUEST_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_PTTrqIncReqActive_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_PTTrqIncReq_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_PTTORQUEREQUEST_FVS55R_EHB_PTTRQINCREQ_EHB_PTTORQUEREQUEST_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_PTTrqIncReq_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_RLWheelDirection_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_REARWHEELSPEEDSKPH_FVS55R_EHB_RLWHEELDIRECTION_EHB_REARWHEELSPEEDSKPH_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_RLWheelDirection_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_RLWheelSpeedInvalid_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_REARWHEELSPEEDSKPH_FVS55R_EHB_RLWHEELSPEEDINVALID_EHB_REARWHEELSPEEDSKPH_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_RLWheelSpeedInvalid_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_RLWheelSpeedKPH_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_REARWHEELSPEEDSKPH_FVS55R_EHB_RLWHEELSPEEDKPH_EHB_REARWHEELSPEEDSKPH_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_RLWheelSpeedKPH_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_RRWheelDirection_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_REARWHEELSPEEDSKPH_FVS55R_EHB_RRWHEELDIRECTION_EHB_REARWHEELSPEEDSKPH_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_RRWheelDirection_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_RRWheelSpeedInvalid_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_REARWHEELSPEEDSKPH_FVS55R_EHB_RRWHEELSPEEDINVALID_EHB_REARWHEELSPEEDSKPH_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_RRWheelSpeedInvalid_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_RRWheelSpeedKPH_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_REARWHEELSPEEDSKPH_FVS55R_EHB_RRWHEELSPEEDKPH_EHB_REARWHEELSPEEDSKPH_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_RRWheelSpeedKPH_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_VLC_Active_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_VLC_TORQUEREQUEST_FVS55R_EHB_VLC_ACTIVE_EHB_VLC_TORQUEREQUEST_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_VLC_Active_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_VLC_Available_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_VLC_TORQUEREQUEST_FVS55R_EHB_VLC_AVAILABLE_EHB_VLC_TORQUEREQUEST_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_VLC_Available_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_VLC_CDD_active_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_VLC_TORQUEREQUEST_FVS55R_EHB_VLC_CDD_ACTIVE_EHB_VLC_TORQUEREQUEST_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_VLC_CDD_active_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_VLC_PTTrqReqActive_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_VLC_TORQUEREQUEST_FVS55R_EHB_VLC_PTTRQREQACTIVE_EHB_VLC_TORQUEREQUEST_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_VLC_PTTrqReqActive_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_VLC_PTTrqReq_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_VLC_TORQUEREQUEST_FVS55R_EHB_VLC_PTTRQREQ_EHB_VLC_TORQUEREQUEST_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_VLC_PTTrqReq_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_VehicleSpeedInvalid_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_STATUS_FVS55R_EHB_VEHICLESPEEDINVALID_EHB_STATUS_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_VehicleSpeedInvalid_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_VehicleSpeed_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_EHB_STATUS_FVS55R_EHB_VEHICLESPEED_EHB_STATUS_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_EHB_VehicleSpeed_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EWP_HeatPower_HEWP_1_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_HEWP_1_T34TDK_EWP_HEATPOWER_HEWP_1_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_EWP_HeatPower_HEWP_1_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_EWP_OutputTemp_HEWP_1_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_HEWP_1_T34TDK_EWP_OUTPUTTEMP_HEWP_1_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_EWP_OutputTemp_HEWP_1_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_FWFV_CCWFlg_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_FWFV_STATUS_T34TDK_FWFV_CCWFLG_FWFV_STATUS_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_FWFV_CCWFlg_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_FWFV_CurrentPos_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_FWFV_STATUS_T34TDK_FWFV_CURRENTPOS_FWFV_STATUS_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_FWFV_CurrentPos_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_FWFV_InitState_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_FWFV_STATUS_T34TDK_FWFV_INITSTATE_FWFV_STATUS_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_FWFV_InitState_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_FWFV_MotorState_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_FWFV_STATUS_T34TDK_FWFV_MOTORSTATE_FWFV_STATUS_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_FWFV_MotorState_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_FWFV_OverCurrentFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_FWFV_STATUS_T34TDK_FWFV_OVERCURRENTFLT_FWFV_STATUS_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_FWFV_OverCurrentFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_FWFV_OverTempFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_FWFV_STATUS_T34TDK_FWFV_OVERTEMPFLT_FWFV_STATUS_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_FWFV_OverTempFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_FWFV_OverVoltageFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_FWFV_STATUS_T34TDK_FWFV_OVERVOLTAGEFLT_FWFV_STATUS_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_FWFV_OverVoltageFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_FWFV_RESP_ERROR_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_FWFV_STATUS_T34TDK_FWFV_RESP_ERROR_FWFV_STATUS_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_FWFV_RESP_ERROR_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_FWFV_UnderVoltageFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_FWFV_STATUS_T34TDK_FWFV_UNDERVOLTAGEFLT_FWFV_STATUS_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_FWFV_UnderVoltageFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_HCM_AcceRelayVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_STATUS_LGFZID_HCM_ACCERELAYVOLTVALIDSTAT_HCM_STATUS_N72_HCM__MATRIX_V1_1_DBC_RX, &Rte_ComBuffer_HCM_AcceRelayVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_HCM_AcceRelayVolt_HCM_Other2RelayValue_N72_HCM__Matrix_V1_1_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_OTHER2RELAYVALUE_LGFZID_HCM_ACCERELAYVOLT_HCM_OTHER2RELAYVALUE_N72_HCM__MATRIX_V1_1_DBC_RX, &Rte_ComBuffer_HCM_AcceRelayVolt_HCM_Other2RelayValue_N72_HCM__Matrix_V1_1_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_HCM_FastChgBackVolt_HCM_OtherRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_OTHERRELAYVALUE_LGFZID_HCM_FASTCHGBACKVOLT_HCM_OTHERRELAYVALUE_N72_HCM__MATRIX_V1_1_DBC_RX, &Rte_ComBuffer_HCM_FastChgBackVolt_HCM_OtherRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_HCM_InsulateCounter_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_INSULATEAVALUE_LGFZID_HCM_INSULATECOUNTER_HCM_INSULATEAVALUE_N72_HCM__MATRIX_V1_1_DBC_RX, &Rte_ComBuffer_HCM_InsulateCounter_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_HCM_MainNegBackVolt_HCM_OtherRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_OTHERRELAYVALUE_LGFZID_HCM_MAINNEGBACKVOLT_HCM_OTHERRELAYVALUE_N72_HCM__MATRIX_V1_1_DBC_RX, &Rte_ComBuffer_HCM_MainNegBackVolt_HCM_OtherRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_HCM_MainPosBackVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_STATUS_LGFZID_HCM_MAINPOSBACKVOLTVALIDSTAT_HCM_STATUS_N72_HCM__MATRIX_V1_1_DBC_RX, &Rte_ComBuffer_HCM_MainPosBackVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_HCM_MainPosBackVolt_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_MAINRELAYVALUE_LGFZID_HCM_MAINPOSBACKVOLT_HCM_MAINRELAYVALUE_N72_HCM__MATRIX_V1_1_DBC_RX, &Rte_ComBuffer_HCM_MainPosBackVolt_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_HCM_MainPosFrtVolt_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_MAINRELAYVALUE_LGFZID_HCM_MAINPOSFRTVOLT_HCM_MAINRELAYVALUE_N72_HCM__MATRIX_V1_1_DBC_RX, &Rte_ComBuffer_HCM_MainPosFrtVolt_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_HCM_NegInsulateVal_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_INSULATEAVALUE_LGFZID_HCM_NEGINSULATEVAL_HCM_INSULATEAVALUE_N72_HCM__MATRIX_V1_1_DBC_RX, &Rte_ComBuffer_HCM_NegInsulateVal_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_HCM_PTCRelayVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_STATUS_LGFZID_HCM_PTCRELAYVOLTVALIDSTAT_HCM_STATUS_N72_HCM__MATRIX_V1_1_DBC_RX, &Rte_ComBuffer_HCM_PTCRelayVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_HCM_PTCRelayVolt_HCM_Other2RelayValue_N72_HCM__Matrix_V1_1_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_OTHER2RELAYVALUE_LGFZID_HCM_PTCRELAYVOLT_HCM_OTHER2RELAYVALUE_N72_HCM__MATRIX_V1_1_DBC_RX, &Rte_ComBuffer_HCM_PTCRelayVolt_HCM_Other2RelayValue_N72_HCM__Matrix_V1_1_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_HCM_PosInsulateVal_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_INSULATEAVALUE_LGFZID_HCM_POSINSULATEVAL_HCM_INSULATEAVALUE_N72_HCM__MATRIX_V1_1_DBC_RX, &Rte_ComBuffer_HCM_PosInsulateVal_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_HCM_ShuntTemp_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_STATUS_LGFZID_HCM_SHUNTTEMP_HCM_STATUS_N72_HCM__MATRIX_V1_1_DBC_RX, &Rte_ComBuffer_HCM_ShuntTemp_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_HCM_TotalCurr_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_MAINRELAYVALUE_LGFZID_HCM_TOTALCURR_HCM_MAINRELAYVALUE_N72_HCM__MATRIX_V1_1_DBC_RX, &Rte_ComBuffer_HCM_TotalCurr_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_IPK_AllowChgSoftSwCtrlSt_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_IPK_INFOR_FVS55R_IPK_ALLOWCHGSOFTSWCTRLST_IPK_INFOR_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_IPK_AllowChgSoftSwCtrlSt_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_IPK_ChrgSoftSwCtrlSt_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_IPK_INFOR_FVS55R_IPK_CHRGSOFTSWCTRLST_IPK_INFOR_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_IPK_ChrgSoftSwCtrlSt_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_IPK_Day_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_IPK_DATETIME_INFO__XQC0B_IPK_DAY_IPK_DATETIME_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_IPK_Day_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_IPK_EngRecMode_Req_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_IPK_INFOR_FVS55R_IPK_ENGRECMODE_REQ_IPK_INFOR_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_IPK_EngRecMode_Req_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_IPK_Hour_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_IPK_DATETIME_INFO__XQC0B_IPK_HOUR_IPK_DATETIME_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_IPK_Hour_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_IPK_IPKTotalOdometer_IPK_TotalOdometer_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_IPK_TOTALODOMETER__XQC0B_IPK_IPKTOTALODOMETER_IPK_TOTALODOMETER_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_IPK_IPKTotalOdometer_IPK_TotalOdometer_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_IPK_Minute_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_IPK_DATETIME_INFO__XQC0B_IPK_MINUTE_IPK_DATETIME_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_IPK_Minute_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_IPK_Month_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_IPK_DATETIME_INFO__XQC0B_IPK_MONTH_IPK_DATETIME_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_IPK_Month_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_IPK_Odometerbackup_IPK_TotalOdometer_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_IPK_TOTALODOMETER__XQC0B_IPK_ODOMETERBACKUP_IPK_TOTALODOMETER_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_IPK_Odometerbackup_IPK_TotalOdometer_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_IPK_Second_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_IPK_DATETIME_INFO__XQC0B_IPK_SECOND_IPK_DATETIME_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_IPK_Second_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_IPK_Year_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_IPK_DATETIME_INFO__XQC0B_IPK_YEAR_IPK_DATETIME_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_IPK_Year_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_MHGV_CCWFlg_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_MHGV_STATUS_T34TDK_MHGV_CCWFLG_MHGV_STATUS_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_MHGV_CCWFlg_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_MHGV_CurrentPos_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_MHGV_STATUS_T34TDK_MHGV_CURRENTPOS_MHGV_STATUS_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_MHGV_CurrentPos_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_MHGV_InitState_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_MHGV_STATUS_T34TDK_MHGV_INITSTATE_MHGV_STATUS_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_MHGV_InitState_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_MHGV_MotorState_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_MHGV_STATUS_T34TDK_MHGV_MOTORSTATE_MHGV_STATUS_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_MHGV_MotorState_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_MHGV_OverCurrentFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_MHGV_STATUS_T34TDK_MHGV_OVERCURRENTFLT_MHGV_STATUS_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_MHGV_OverCurrentFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_MHGV_OverTempFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_MHGV_STATUS_T34TDK_MHGV_OVERTEMPFLT_MHGV_STATUS_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_MHGV_OverTempFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_MHGV_OverVoltageFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_MHGV_STATUS_T34TDK_MHGV_OVERVOLTAGEFLT_MHGV_STATUS_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_MHGV_OverVoltageFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_MHGV_RESP_ERROR_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_MHGV_STATUS_T34TDK_MHGV_RESP_ERROR_MHGV_STATUS_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_MHGV_RESP_ERROR_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_MHGV_UnderVoltageFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_MHGV_STATUS_T34TDK_MHGV_UNDERVOLTAGEFLT_MHGV_STATUS_VE21_N72_PMS_LIN_LDF_RX, &Rte_ComBuffer_MHGV_UnderVoltageFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_MMI_LocalBookChrgnTarVal_MMI_SOCSet_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_MMI_SOCSET__XQC0B_MMI_LOCALBOOKCHRGNTARVAL_MMI_SOCSET_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_MMI_LocalBookChrgnTarVal_MMI_SOCSet_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_MMI_RestSwitch_MMI_HVSM_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_MMI_HVSM_COMMAND__XQC0B_MMI_RESTSWITCH_MMI_HVSM_COMMAND_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_MMI_RestSwitch_MMI_HVSM_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_OBC_CCvalue_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_OBC_STATUS2_RMXR12_OBC_CCVALUE_OBC_STATUS2_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_OBC_CCvalue_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_OBC_ChgCCSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_OBC_FAILMODE_RMXR12_OBC_CHGCCSTS_OBC_FAILMODE_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_OBC_ChgCCSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_OBC_ChrgrSt_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_OBC_STS_RMXR12_OBC_CHRGRST_OBC_STS_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_OBC_ChrgrSt_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_OBC_DischargeCCvalue_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_OBC_STATUS2_RMXR12_OBC_DISCHARGECCVALUE_OBC_STATUS2_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_OBC_DischargeCCvalue_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_OBC_Elock_Stmode_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_OBC_STS_RMXR12_OBC_ELOCK_STMODE_OBC_STS_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_OBC_Elock_Stmode_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_OBC_LockLoopSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_OBC_FAILMODE_RMXR12_OBC_LOCKLOOPSTS_OBC_FAILMODE_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_OBC_LockLoopSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_OBC_OnBdCCline_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_OBC_STS_RMXR12_OBC_ONBDCCLINE_OBC_STS_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_OBC_OnBdCCline_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_OBC_OnBdCPline_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_OBC_STS_RMXR12_OBC_ONBDCPLINE_OBC_STS_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_OBC_OnBdCPline_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_OBC_OnBdChrgrT_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_OBC_STS_RMXR12_OBC_ONBDCHRGRT_OBC_STS_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_OBC_OnBdChrgrT_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_OBC_OnBdDisChrgrCCline_OBC_Curr_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_OBC_CURR_RMXR12_OBC_ONBDDISCHRGRCCLINE_OBC_CURR_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_OBC_OnBdDisChrgrCCline_OBC_Curr_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_OBC_OnBdOuptI_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_OBC_STS_RMXR12_OBC_ONBDOUPTI_OBC_STS_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_OBC_OnBdOuptI_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_OBC_OnBdOuptU_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_OBC_STS_RMXR12_OBC_ONBDOUPTU_OBC_STS_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_OBC_OnBdOuptU_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_OBC_PwrEgyMgrAvl_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_OBC_STATUS2_RMXR12_OBC_PWREGYMGRAVL_OBC_STATUS2_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_OBC_PwrEgyMgrAvl_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_OBC_SelfCheSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_OBC_FAILMODE_RMXR12_OBC_SELFCHESTS_OBC_FAILMODE_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_OBC_SelfCheSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_OBC_uInAct_OBC_Curr_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_OBC_CURR_RMXR12_OBC_UINACT_OBC_CURR_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_OBC_uInAct_OBC_Curr_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_ODP_DCDC_TDcDcAlm_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_DCDC_LV_INFO_RMXR12_ODP_DCDC_TDCDCALM_DCDC_LV_INFO_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_ODP_DCDC_TDcDcAlm_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_PDC_Brake_Flag_PDC_Status_Info_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_PDC_STATUS_INFO_FVS55R_PDC_BRAKE_FLAG_PDC_STATUS_INFO_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_PDC_Brake_Flag_PDC_Status_Info_N72__PMS_C_CAN_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_PEPS_PowerModeValidity_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_PEPS_MESSAGE_STS__XQC0B_PEPS_POWERMODEVALIDITY_PEPS_MESSAGE_STS_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_PEPS_PowerModeValidity_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_PEPS_PowerMode_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_PEPS_MESSAGE_STS__XQC0B_PEPS_POWERMODE_PEPS_MESSAGE_STS_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_PEPS_PowerMode_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_PEPS_RKECommand_PEPS_KeyReminder_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_PEPS_KEYREMINDER__XQC0B_PEPS_RKECOMMAND_PEPS_KEYREMINDER_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_PEPS_RKECommand_PEPS_KeyReminder_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_PEPS_RemoteControlSt_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_PEPS_MESSAGE_STS__XQC0B_PEPS_REMOTECONTROLST_PEPS_MESSAGE_STS_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_PEPS_RemoteControlSt_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_RFR_ConnectionStatus_Station_Status_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_STATION_STATUS_RMXR12_RFR_CONNECTIONSTATUS_STATION_STATUS_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_RFR_ConnectionStatus_Station_Status_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_RFR_Seed_RFR_Seed_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_RFR_SEED_RMXR12_RFR_SEED_RFR_SEED_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_RFR_Seed_RFR_Seed_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_RFR_SwapBatCode_RFR_SwapBatCode_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_RFR_SWAPBATCODE_RMXR12_RFR_SWAPBATCODE_RFR_SWAPBATCODE_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_RFR_SwapBatCode_RFR_SwapBatCode_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_Station_CarLocationConfirm_Station_Status_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_STATION_STATUS_RMXR12_STATION_CARLOCATIONCONFIRM_STATION_STATUS_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_Station_CarLocationConfirm_Station_Status_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_Station_CarStation_Station_Status_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_STATION_STATUS_RMXR12_STATION_CARSTATION_STATION_STATUS_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_Station_CarStation_Station_Status_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_Station_SwapBatRequest_Station_Status_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_STATION_STATUS_RMXR12_STATION_SWAPBATREQUEST_STATION_STATUS_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_Station_SwapBatRequest_Station_Status_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_Station_Swapingproceeding_Station_Status_PMS_EV_CAN_20260427_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_STATION_STATUS_RMXR12_STATION_SWAPINGPROCEEDING_STATION_STATUS_PMS_EV_CAN_20260427_DBC_RX, &Rte_ComBuffer_Station_Swapingproceeding_Station_Status_PMS_EV_CAN_20260427_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_AllowChgCurrentMax_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_CHGLIMIT_COMMAND__XQC0B_TBOX_ALLOWCHGCURRENTMAX_TBOX_CHGLIMIT_COMMAND_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_AllowChgCurrentMax_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_ChargeDepth_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_CHGLIMIT_COMMAND__XQC0B_TBOX_CHARGEDEPTH_TBOX_CHGLIMIT_COMMAND_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_ChargeDepth_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_ChargeLimitSwitch_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_CHGLIMIT_COMMAND__XQC0B_TBOX_CHARGELIMITSWITCH_TBOX_CHGLIMIT_COMMAND_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_ChargeLimitSwitch_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_ChrgSoftSwCtrlSt_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_REMCON__XQC0B_TBOX_CHRGSOFTSWCTRLST_TBOX_REMCON_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_ChrgSoftSwCtrlSt_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_Day_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_DATETIME_INFO__XQC0B_TBOX_DAY_TBOX_DATETIME_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_Day_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_Elevation_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_REMCON__XQC0B_TBOX_ELEVATION_TBOX_REMCON_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_Elevation_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_FunAnti_DismantleActive_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_LOCKVEHCTRL__XQC0B_TBOX_FUNANTI_DISMANTLEACTIVE_TBOX_LOCKVEHCTRL_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_FunAnti_DismantleActive_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_FunLockVehActive_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_LOCKVEHCTRL__XQC0B_TBOX_FUNLOCKVEHACTIVE_TBOX_LOCKVEHCTRL_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_FunLockVehActive_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_Hour_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_DATETIME_INFO__XQC0B_TBOX_HOUR_TBOX_DATETIME_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_Hour_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_InventorySpdLmtReq_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_INSTRUCT__XQC0B_TBOX_INVENTORYSPDLMTREQ_TBOX_INSTRUCT_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_InventorySpdLmtReq_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_Life_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_INSTRUCT__XQC0B_TBOX_LIFE_TBOX_INSTRUCT_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_Life_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_LockLimSet_TBOX_VCULockResp_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_VCULOCKRESP__XQC0B_TBOX_LOCKLIMSET_TBOX_VCULOCKRESP_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_LockLimSet_TBOX_VCULockResp_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_LockVehCtrl_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_LOCKVEHCTRL__XQC0B_TBOX_LOCKVEHCTRL_TBOX_LOCKVEHCTRL_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_LockVehCtrl_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_LockVehPerFlag_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_INSTRUCT__XQC0B_TBOX_LOCKVEHPERFLAG_TBOX_INSTRUCT_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_LockVehPerFlag_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_LockVehType_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_LOCKVEHCTRL__XQC0B_TBOX_LOCKVEHTYPE_TBOX_LOCKVEHCTRL_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_LockVehType_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_Minute_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_DATETIME_INFO__XQC0B_TBOX_MINUTE_TBOX_DATETIME_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_Minute_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_Month_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_DATETIME_INFO__XQC0B_TBOX_MONTH_TBOX_DATETIME_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_Month_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_PowerOffCmd_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_INSTRUCT__XQC0B_TBOX_POWEROFFCMD_TBOX_INSTRUCT_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_PowerOffCmd_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_PriorityFullSwitchSts_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_REMCON__XQC0B_TBOX_PRIORITYFULLSWITCHSTS_TBOX_REMCON_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_PriorityFullSwitchSts_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_PriorityFullSwitchSts_UB_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_REMCON__XQC0B_TBOX_PRIORITYFULLSWITCHSTS_UB_TBOX_REMCON_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_PriorityFullSwitchSts_UB_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_ReservationChrgnSts_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_REMCON__XQC0B_TBOX_RESERVATIONCHRGNSTS_TBOX_REMCON_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_ReservationChrgnSts_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_Second_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_DATETIME_INFO__XQC0B_TBOX_SECOND_TBOX_DATETIME_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_Second_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_SpdLmtLevelReq_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_INSTRUCT__XQC0B_TBOX_SPDLMTLEVELREQ_TBOX_INSTRUCT_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_SpdLmtLevelReq_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_VersionConversionFlag_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_INSTRUCT__XQC0B_TBOX_VERSIONCONVERSIONFLAG_TBOX_INSTRUCT_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_VersionConversionFlag_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_Year_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_TBOX_DATETIME_INFO__XQC0B_TBOX_YEAR_TBOX_DATETIME_INFO_N72__PMS_PT_CANFD_20260425_DBC_RX, &Rte_ComBuffer_TBOX_Year_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx);
}

FUNC(void, RTE_CODE) Rte_COMCbk_YRS_LongitAcce_YRS2_N72__PMS_C_CAN_20260425_dbc_Rx(void)
{
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_YRS2_FVS55R_YRS_LONGITACCE_YRS2_N72__PMS_C_CAN_20260425_DBC_RX, &Rte_ComBuffer_YRS_LongitAcce_YRS2_N72__PMS_C_CAN_20260425_dbc_Rx);
}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    COM Callbacks Function definition for Rx Timeout Notification
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    COM Callbacks Function definition for Map Service
************************************************************************************************************************
*/

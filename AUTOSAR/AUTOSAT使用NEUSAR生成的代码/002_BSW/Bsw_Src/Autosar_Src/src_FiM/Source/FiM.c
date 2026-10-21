/*
********************************************************************************
*
* File name: FiM.c
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: Sunpengfei/2018.07.10
* Change: New Create.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: yaoxingjia/2019.09.14
* Change: Modify logic and add standard interfaces.
* Cause: Maintenance and Addition.
********************************************************************************
* Version: 1.2
* Author/Date: Liuziyang/2019.11.13
* Change: The format of code and comment.
* Cause: Modify the code according to the coding specification.
********************************************************************************
* Version: 1.3
* Author/Date: Liuziyang/2020.1.10
* Change: Modify the function return result.
* Cause: Bugfix
********************************************************************************
* Version: 3.0
* Author/Date: Liuziyang/2020.03.26
* Change: 1.Optimizing the FOR loop and data structure;
*         2.Add active polling function;
* Cause: Optimization, bugfix and Update to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date: Liuziyang/2020.05.16
* Change: Change the NULL_POINT to NULL_PTR.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: Liuziyang/2020.05.19
* Change: Modify file format.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: Liuziyang/2020.07.14
* Change: The function FiM_SetFunctionAvailable internal logic error.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: Liuziyang/2020.08.03
* Change: Modify the function suppression permission according to the document
*         (SWS_Fim_00065).
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: Liuziyang/2020.08.18
* Change: Modify the problem of compiling when the configuration is empty.
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: Liuziyang/2020.09.11
* Change: Modify the initialization variable judgment logic.
* Cause: Bugfix
********************************************************************************
* Version: 3.7
* Author/Date: liuziyang/2020.09.15
* Change: Add function of MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: liuziyang/2020.09.17
* Change: Modify the initial development error detection value in the main
*         function process.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: liuziyang/2020.09.17
* Change: Modify FiM_DemInit, FiM_TriggerMode and FiM_Init function logic.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: liuziyang/2020.09.19
* Change: Modify the code format to autosar standard
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date : liuziyang/2020.09.28
* Change: Modify the internal flow processing logic of the module.
* Cause: Bugfix
********************************************************************************
* Version: 3.12
* Author/Date : liuziyang/2020.10.15
* Change: Modify questions above QAC-4.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: LiuZY/2020.11.03
* Change: Modify the incorrectly defined part of the code format.
* Cause: Optimization
********************************************************************************
* Version: 3.14
* Author/Date: LiuZY/2020.11.14
* Change: Modify the code review record.
* Cause: Optimization
********************************************************************************
* Version: 3.15
* Author/Date: LiuZY/2020.12.05
* Change: Eliminate compilation warnings in modules.
* Cause: Optimization
********************************************************************************
* Version: 3.16
* Author/Date: LiuZY/2020.12.10
* Change: Modify the counter type to uint16.
* Cause: Optimization
********************************************************************************
* Version: 3.17
* Author/Date: LiuZY/2020.12.23
* Change: Modify the EventId type to uint16.
* Cause: Optimization
********************************************************************************
* Version: 3.18
* Author/Date: LiuZY/2020.03.10
* Change: Modify the EventId type to uint16 for FiM_PollingMode.
* Cause: Optimization
********************************************************************************
* Version: 3.19
* Author/Date: XieYN/2021.04.12
* Change: Delete the if condition of the FiM_DemTriggerOnUdsEventStatus function
*         for modCode.
* Cause: Optimization
********************************************************************************
* Version: 3.20
* Author/Date: LiuZY/2021.05.01
* Change: FiM adapts to the new version of DEM.
* Cause: Bugfix
********************************************************************************
* Version: 3.21
* Author/Date: XieYN/2021.05.21
* Change: Add initialization judgment in FiM_Init.
* Cause: Bugfix
********************************************************************************
* Version: 3.22
* Author/Date: XieYN/2021.06.8
* Change: Stub FiM_DemTriggerOnComponentStatus.
* Cause: Bugfix
********************************************************************************
* Version: 3.23
* Author/Date: XieYN/2021.06.30
* Change: Add annotation in FiM_DemTriggerOnComponentStatus.
*         Add parentheses at both ends of the first if judgment "||" condition
*         of FiM_Init.
* Cause: Optimization
********************************************************************************
* Version: 3.24
* Author/Date: XieYN/2021.06.30
* Change: Modify code specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.25
* Author/Date: XieYN/2021.08.12
* Change: Modify code specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.26
* Author/Date: XieYN/2022.01.18
* Change: Add modCode judgement in FiM_DemTriggerOnUdsEventStatus, FiM_PollingMode
*         and FiM_CalculateUdsFidStates.
* Cause: Bugfix
********************************************************************************
* Version: 3.27
* Author/Date: MengY/2022.10.25
* Change: Modify the names of the Macro according to the document.
* Cause: Bugfix
********************************************************************************
* Version: 3.28
* Author/Date: MengY/2022.11.25
* Change: Add code about the function of postbuild.
* Cause: Optimization
********************************************************************************
* Version: 3.29
* Author/Date: MengY/2023.01.12
* Change: Modify fid index and event index from uint8 to uint16.
* Cause: Bugfix
********************************************************************************
* Version: 3.30
* Author/Date: MengY/2023.05.11
* Change: Only check valid eventId in function FiM_DemTriggerOnUdsEventStatus.
* Cause: Bugfix
********************************************************************************
* Version: 3.31
* Author/Date: FanHT/2023.08.03
* Change: Duo to clear DEM_CFG_TRIGGERFIMREPORT warning.
*         Move include "Dem.h" to "FiM.h".
* Cause: Update
********************************************************************************
* Version: 3.32
* Author/Date: ChenQJ/2023.12.26
* Change: Re-design the data structure and code logic for performance
*         optimization.
* Cause: Optimization
********************************************************************************
* Version: 3.33
* Author/Date: ChenQJ/2024.01.17
* Change: 1. Fix QAC, polyspace and compile warning.
*         2. Modify FiM_DemTriggerOnEventStatus() for Dem.
* Cause: Optimization
********************************************************************************
* Version: 3.34
* Author/Date: ChenQJ/2024.01.29
* Change: Do not compile FiM_DemTriggerOnEventStatus() when
*         FiMEventUpdateTriggeredByDem is not enabled.
* Cause: Optimization
********************************************************************************
* Version: 3.35
* Author/Date: ChenQJ/2024.03.11
* Change: 1. Change the ptrclass of P2CONST to FIM_APPL_DATA.
*         2. Remove no use space from the end of each rows.
* Cause: Optimization.
********************************************************************************
* Version: 3.36
* Author/Date: TianG/2024.05.10
* Change: Modify format of comment.
* Cause: Optimization
********************************************************************************
* Version: 3.37
* Author/Date: TianG/2024.06.28
* Change: Modify copyright.
* Cause: Optimization
********************************************************************************
* Version: 3.38
* Author/Date: TianG/2024.09.13
* Change: Modify FiM_START_SEC_CODE to FIM_START_SEC_CODE.
* Cause: Bugfix
********************************************************************************
* Version: 3.39
* Author/Date: TianG/2025.03.25
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 3.40
* Author/Date: TianSL/2025.06.12
* Change: Add the polyspace deviation suppression comment.
* Cause: Optimization
********************************************************************************
*/
/*
********************************************************************************
*    Include
********************************************************************************
*/
#include "FiM.h"
#include "Rte_FiM.h"
#include "SchM_FiM.h"
#include "NeuLib.h"
#include "NeuLib_Def.h"

#if( FIM_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif  /* FIM_DEV_ERROR_DETECT == STD_ON */

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
#if( FIM_DEV_ERROR_DETECT == STD_ON )
/* Development Error Detection. */
#define FiM_ReportDevError(SID, ERROR)	((void)Det_ReportError(FIM_MODULE_ID, FIM_INSTANCE_ID, (SID), (ERROR)))
#else
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define FiM_ReportDevError(SID, ERROR)
#endif  /* FIM_DEV_ERROR_DETECT == STD_ON */

/*
********************************************************************************
*    Local Types
********************************************************************************
*/
/* Inhibition mode table type. */
typedef struct
{
    Dem_EventStatusExtendedType Mask;
    Dem_EventStatusExtendedType Pattern;
} FiM_InhibitionModeType;

/*
********************************************************************************
*    Local Variables
********************************************************************************
*/
#define FIM_START_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "FiM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if( FIM_SUPPORT_AVAILABLE == STD_ON )
/* A bitmap for FID available status. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_FiM_UsedNonSharedVariable" */
static VAR(uint8, FIM_VAR_NO_INIT) FiM_FIDAvailable[FIM_FIDAVAILABLE_BITMAP_SIZE];
#endif  /* FIM_SUPPORT_AVAILABLE == STD_ON */

#define FIM_STOP_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "FiM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


#define FIM_START_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "FiM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* Inhibition counter of each FID. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_FiM_UsedNonSharedVariable" */
static VAR(uint8, FIM_VAR_INIT) FiM_FIDInhCnt[FIM_MAX_FID_NUM] = {NEULIB_CNT_0};

/* FiM initialization status. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_FiM_UsedNonSharedVariable" */
static VAR(uint8, FIM_VAR_INIT) FiM_InitializationStatus = FIM_UNINITIALIZED;

#if( FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF )
/* The last polling index in event table(Only use in polling mode). */
static VAR(uint16, FIM_VAR_INIT) FiM_LastPollingIndex = NEULIB_CNT_0;

/* Last event status. */
static VAR(Dem_UdsStatusByteType, FIM_VAR_INIT) FiM_LastEventStatus[FIM_EVENT_NUM] = {NEULIB_CNT_0};
#endif  /* FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF */

#define FIM_STOP_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "FiM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
#define FIM_START_SEC_CONST
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "FiM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* FiM inhibition mode table. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_FiM_UsedNonSharedVariable" */
static CONST(FiM_InhibitionModeType, FIM_CONST) Fim_InhibitionModeTable[FIM_INHCODE_NUMBER] =
{
    {   /* FIM_LAST_FAILED */
        FIM_LAST_FAILED_MASK,
        FIM_LAST_FAILED_PATTERN,
    },
    {   /* FIM_NOT_TESTED */
        FIM_NOT_TESTED_MASK,
        FIM_NOT_TESTED_PATTERN,
    },
    {   /* FIM_TESTED */
        FIM_TESTED_MASK,
        FIM_TESTED_PATTERN,
    },
    {   /* FIM_TESTED_AND_FAILED */
        FIM_TESTED_AND_FAILED_MASK,
        FIM_TESTED_AND_FAILED_PATTERN,
    }
};

#define FIM_STOP_SEC_CONST
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "FiM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/

#define FIM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "FiM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
#if( FIM_SUPPORT_AVAILABLE == STD_ON )
/*
********************************************************************************
* Function Name: FiM_SetBitmapPosValue
*
* Explanation:   Set bit value of indicated position in bitmap.
* (Synchronous)
*
* param:         bitmapIdx(in) - The position of bit in bitmap.
*                bitmapPtr(in) - The bitmap pointer.
*
* retval:        None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, FIM_CODE) FiM_SetBitmapPosValue
(
    uint16 bitmapIdx,
    P2VAR(uint8, AUTOMATIC, FIM_APPL_DATA) bitmapPtr
)
{
    uint16 bytePos;
    uint8 bitPos;

    /* Calculate byte and bit position of bitmapIdx. */
    bytePos = bitmapIdx >> NEULIB_SHIFT_3;
    bitPos = (uint8)(bitmapIdx & NEULIB_CNT_7);

    /* Set the bit in bitmap. */
    bitmapPtr[bytePos] |= (uint8)(NEULIB_CNT_1 << bitPos);
}
#endif  /* FIM_SUPPORT_AVAILABLE == STD_ON */

#if( FIM_SUPPORT_AVAILABLE == STD_ON )
/*
********************************************************************************
* Function Name: FiM_ClrBitmapPosValue
*
* Explanation:   Clear bit value of indicated position in bitmap.
* (Synchronous)
*
* param:         bitmapIdx(in) - The position of bit in bitmap.
*                bitmapPtr(in) - The bitmap pointer.
*
* retval:        None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, FIM_CODE) FiM_ClrBitmapPosValue
(
    uint16 bitmapIdx,
    P2VAR(uint8, AUTOMATIC, FIM_APPL_DATA) bitmapPtr
)
{
    uint16 bytePos;
    uint8 bitPos;

    /* Calculate byte and bit position of bitmapIdx. */
    bytePos = bitmapIdx >> NEULIB_SHIFT_3;
    bitPos = (uint8)(bitmapIdx & NEULIB_CNT_7);

    /* Clear the bit in bitmap. */
    bitmapPtr[bytePos] &= (uint8)(~(uint8)(NEULIB_CNT_1 << bitPos));
}

/*
********************************************************************************
* Function Name: FiM_GetBitmapPosValue
*
* Explanation:   Get bit value of indicated position in bitmap.
* (Synchronous)
*
* param:         bitmapIdx(in) - The position of bit in bitmap.
*                logChMsgStatus(in) - The bitmap pointer.
*
* retval:        0 - Bit is clear.
*                Others - Bit is set.
********************************************************************************
*/
LOCAL_INLINE FUNC(uint8, FIM_CODE) FiM_GetBitmapPosValue
(
    uint16 bitmapIdx,
    P2CONST(uint8, AUTOMATIC, FIM_APPL_DATA) bitmapPtr
)
{
    uint16 bytePos;
    uint8 bitPos;
    uint8 retVal;

    bytePos = bitmapIdx >> NEULIB_SHIFT_3;
    bitPos = (uint8)(bitmapIdx & NEULIB_CNT_7);
    retVal = bitmapPtr[bytePos] & (uint8)(NEULIB_CNT_1 << bitPos);

    return retVal;
}
#endif  /* FIM_SUPPORT_AVAILABLE == STD_ON */

#if( FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_ON )
/*
********************************************************************************
* Function Name: Dlt_GetBitmapPosValue
*
* Explanation:   Get the index of eventId in event table via binary search.
* (Synchronous)
*
* param:         eventId(in) - Event ID to be searched.
*
* retval:        .
********************************************************************************
*/
static FUNC(Std_ReturnType, FIM_CODE) FiM_BinarySearchEventId
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_FiM_RuleD4.5" */
    Dem_EventIdType eventId,
    P2VAR(uint16, AUTOMATIC, FIM_APPL_DATA) eventIdx
)
{
    sint32 head;
    sint32 tail;
    sint32 middle;
    Std_ReturnType retval = E_NOT_OK;

    /* Set the head and tail value. */
    head = (sint32)FIM_SIGN_VALUE_0;
    tail = (sint32)FIM_EVENT_NUM - (sint32)FIM_SIGN_VALUE_1;

    while( head <= tail )
    {
        /* Calculate middle value. */
        middle = (sint32)(head + tail) / ((sint32)FIM_SIGN_VALUE_2);

        if( eventId < FiM_EventTable[middle].eventId )
        {
            /* Use middle value as tail and continue searching. */
            tail = middle - (sint32)FIM_SIGN_VALUE_1;
        }
        else if( eventId > FiM_EventTable[middle].eventId )
        {
            /* Use middle value as head and continue searching. */
            head = middle + (sint32)FIM_SIGN_VALUE_1;
        }
        else
        {
            /* Already got the index of Event ID. */
            *eventIdx = (uint16)middle;
            retval = E_OK;
            break;
        }
    }

    return retval;
}
#endif  /* FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_ON */

/*
********************************************************************************
* Function Name: FiM_DetermineInhibitionStatusChange
*
* Explanation: Determine the inhibition status change is increment or decrement.
*
* param: evStatusOld: The old event status.
*        evStatusNew: The new event status.
*        inhCode: Inhibition code.
*
* retval: FIM_FID_DEC: Decrement.
*         FIM_FID_INC: Increment.
********************************************************************************
*/
LOCAL_INLINE FUNC(uint8, FIM_CODE) FiM_DetermineInhibitionStatusChange
(
    Dem_EventStatusExtendedType evStatusOld,
    Dem_EventStatusExtendedType evStatusNew,
    uint8 inhCode
)
{
    uint8 retVal = FIM_FID_NOCHANGE;
    uint8 eventStatusOld;
    uint8 eventStatusNew;

    eventStatusOld = evStatusOld & Fim_InhibitionModeTable[inhCode].Mask;
    eventStatusNew = evStatusNew & Fim_InhibitionModeTable[inhCode].Mask;
    if( eventStatusOld != eventStatusNew )
    {
        /* The old status is not inhibit. */
        if( Fim_InhibitionModeTable[inhCode].Pattern != eventStatusOld )
        {
            /* The new status is inhibit. */
            if( Fim_InhibitionModeTable[inhCode].Pattern == eventStatusNew )
            {
                /* Event status change from un-inhibit to inhibit, increase FID inhibition counter. */
                retVal = FIM_FID_INC;
            }
        }
        /* The old status is inhibit. */
        else
        {
            /* The new status is not inhibit. */
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if( Fim_InhibitionModeTable[inhCode].Pattern != eventStatusNew )
            {
                /* Event status change from inhibit to un-inhibit, decrease FID inhibition counter. */
                retVal = FIM_FID_DEC;
            }
        }
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: FiM_CheckAssociatedFIDOfEvent
*
* Explanation:   Check all associated FID of event.
*
* param:         eventIdx(in) - Index in event table.
*
* retval:        None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, FIM_CODE) FiM_CheckAssociatedFIDOfEvent
(
    uint16 eventIdx,
    Dem_EventStatusExtendedType evStatusOld,
    Dem_EventStatusExtendedType evStatusNew
)
{
    uint16 fidIdx;
    FiM_FunctionIdType fidVal;
    uint8 fidCntMode;

    for( fidIdx = NEULIB_IDX_0; fidIdx < FiM_EventTable[eventIdx].tableLength; fidIdx++ )
    {
        fidCntMode = FiM_DetermineInhibitionStatusChange(evStatusOld, evStatusNew,
                                                        /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_FiM_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_FiM_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_FiM_IDP" */
                                                         FiM_EventTable[eventIdx].maskTableRef[fidIdx]);

        if( FIM_FID_INC == fidCntMode )
        {
            /* Get current associated FID value. */
            /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_FiM_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_FiM_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_FiM_IDP" */
            fidVal = FiM_EventTable[eventIdx].FIDTableRef[fidIdx];

            /* Enter exclusive area. */
            SchM_Enter_FiM_FIM_EXCLUSIVE_AREA_0();

            /* Increase inhibition counter. */
            FiM_FIDInhCnt[fidVal]++;

            /* Exit exclusive area. */
            SchM_Exit_FiM_FIM_EXCLUSIVE_AREA_0();
        }
        else if( FIM_FID_DEC == fidCntMode )
        {
            /* Get current associated FID value. */
            /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_FiM_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_FiM_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_FiM_IDP" */
            fidVal = FiM_EventTable[eventIdx].FIDTableRef[fidIdx];

            /* Enter exclusive area. */
            SchM_Enter_FiM_FIM_EXCLUSIVE_AREA_0();

            /* Decrease inhibition counter if current value is larger than 0. */
            if( NEULIB_CNT_0 < FiM_FIDInhCnt[fidVal] )
            {
                /* Decrease inhibition counter. */
                FiM_FIDInhCnt[fidVal]--;
            }

            /* Exit exclusive area. */
            SchM_Exit_FiM_FIM_EXCLUSIVE_AREA_0();
        }
        else
        {
            /* Do nothing if status is FIM_FID_NOCHANGE. */
        }

#if( FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF )
        /* Mark down the newest event status. */
        FiM_LastEventStatus[eventIdx] = evStatusNew;
#endif  /* FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF */
    }
}

#if( FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF )
/*
********************************************************************************
* Function Name: FiM_EventPollingProcessor
*
* Explanation:   Handler for polling events.
*
* param:         None
*
* retval:        None
********************************************************************************
*/
static FUNC(void, FIM_CODE) FiM_EventPollingProcessor(void)
{
    uint16 pollingNum;
    uint16 curIndex;
    Dem_UdsStatusByteType eventStatus;
    Std_ReturnType retval;

    if( FIM_INITIALIZED != FiM_InitializationStatus )
    {
        FiM_ReportDevError(FIM_SID_MAINFUNCTION, FIM_E_UNINIT);
    }
    else
    {
#if( FIM_POLLING_EVENT_NUM_PER_PERIOD == FIM_POLL_ALL_EVENT )
        /* Poll all event per period. */
        pollingNum = FIM_EVENT_NUM;
#else
#if( FIM_POLLING_EVENT_NUM_PER_PERIOD < FIM_EVENT_NUM )
        /* Poll a part of event per period. */
        pollingNum = FIM_POLLING_EVENT_NUM_PER_PERIOD;
#else
        /* Poll all event per period. */
        pollingNum = FIM_EVENT_NUM;
#endif
#endif  /* FIM_POLLING_EVENT_NUM_PER_PERIOD == FIM_POLL_ALL_EVENT */

        curIndex = NEULIB_CNT_0;
        while( curIndex < pollingNum )
        {
            /* Get event status from Dem. */
            retval = Dem_GetEventStatus(FiM_EventTable[FiM_LastPollingIndex].eventId, &eventStatus);

            if( E_OK == retval )
            {
                /* Check all associated FID of this event. */
                FiM_CheckAssociatedFIDOfEvent(FiM_LastPollingIndex, FiM_LastEventStatus[FiM_LastPollingIndex],
                                              eventStatus);
            }

            /* Point to next index. */
            curIndex++;
            FiM_LastPollingIndex = (FiM_LastPollingIndex + NEULIB_CNT_1) % FIM_EVENT_NUM;
        }
    }
}
#endif  /* FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF */

/*
********************************************************************************
*    Global Functions
********************************************************************************
*/
/*
********************************************************************************
* Function Name: FiM_Init
*
* Explanation: This service initializes the FiM.
* (Synchronous)
*
* param: FiMConfigPtr(in) - Initialization data structure.
*
* retval: None
********************************************************************************
*/
FUNC(void, FIM_CODE) FiM_Init
(
    P2CONST(FiM_ConfigType, AUTOMATIC, FIM_APPL_CONST) FiMConfigPtr
)
{
#if( FIM_SUPPORT_AVAILABLE == STD_ON )
    /* Set all FID available. */
    NeuLib_memset(FiM_FIDAvailable, FIM_FF_VALUE, FIM_FIDAVAILABLE_BITMAP_SIZE);

    /* Set FID0 to unavailable. */
    FiM_ClrBitmapPosValue(NEULIB_CNT_0, FiM_FIDAvailable);
#endif  /* FIM_SUPPORT_AVAILABLE == STD_ON */

    /* Wait for finally initialization FiM_DemInit(). */
    FiM_InitializationStatus = FIM_PREINITIALIZED;

    FIM_DUMMY_STATEMENT(FiMConfigPtr);
}

/*
********************************************************************************
* Function Name: FiM_DemInit
*
* Explanation: This service re-initializes the FIM.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, FIM_CODE) FiM_DemInit(void)
{
    uint16 eventIdx;
    uint16 fidIdx;
    FiM_FunctionIdType fidVal;
    uint8 inhCode;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_FiM_RuleD4.5" */
    Dem_UdsStatusByteType eventStatus;
    Std_ReturnType retval;

    /* Check whether FiM is pre-initialized by FiM_Init(). */
    if( FIM_PREINITIALIZED != FiM_InitializationStatus )
    {
        FiM_ReportDevError(FIM_SID_DEMINIT, FIM_E_INIT_FAILED);
    }
    else
    {
        /* Check all event status. */
        for( eventIdx = NEULIB_CNT_0; eventIdx < FIM_EVENT_NUM; eventIdx++ )
        {
            /* Get event status from Dem. */
            retval = Dem_GetEventStatus(FiM_EventTable[eventIdx].eventId, &eventStatus);

            if( E_OK == retval )
            {
                /* Check inhibit status of all associated FID. */
                for( fidIdx = NEULIB_IDX_0; fidIdx < FiM_EventTable[eventIdx].tableLength; fidIdx++ )
                {
                    /* Get current associated FID value and mask. */
                    /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_FiM_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_FiM_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_FiM_IDP" */
                    fidVal = FiM_EventTable[eventIdx].FIDTableRef[fidIdx];
                    /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_FiM_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_FiM_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_FiM_IDP" */
                    inhCode = FiM_EventTable[eventIdx].maskTableRef[fidIdx];

                    /* The event status is inhibit. */
                    if( (eventStatus & Fim_InhibitionModeTable[inhCode].Mask) ==
                        Fim_InhibitionModeTable[inhCode].Pattern )
                    {
                        /* Increase inhibition counter. */
                        FiM_FIDInhCnt[fidVal]++;
                    }
                }

#if( FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF )
                /* Mark down the newest event status. */
                FiM_LastEventStatus[eventIdx] = eventStatus;
#endif  /* FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF */
            }
        }

        /* FiM is fully initialized. */
        FiM_InitializationStatus = FIM_INITIALIZED;
    }
}

/*
********************************************************************************
* Function Name: FiM_GetFunctionPermission
*
* Explanation: This service reports the permission state to the functionality.
* (Synchronous)
*
* param: FID(in): Identification of a functionality by assigned FID. The
*                 FunctionId is configured in the FiM.
*        Permission(out): TRUE - FID has permission to run.
*                         FALSE - FID has no permission to run, i.e. shall not
*                                 be executed.
*
* retval: E_OK - The request is accepted.
*         E_NOT_OK - The request is not accepted, ie. initialization of FiM not
*                    completed.
********************************************************************************
*/
FUNC(Std_ReturnType, FIM_CODE) FiM_GetFunctionPermission
(
    FiM_FunctionIdType FID,
    P2VAR(boolean, AUTOMATIC, FIM_APPL_DATA) Permission
)
{
    uint8 fidInhCnt;
    Std_ReturnType retval = E_OK;

    /* Check module initialization status. */
    if( FIM_INITIALIZED != FiM_InitializationStatus )
    {
        retval = E_NOT_OK;
        /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_FiM_RuleD4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_FiM_TAINTED_PTR" */
        *Permission = FALSE;
        FiM_ReportDevError(FIM_SID_GETFUNCTIONPERMISSION, FIM_E_UNINIT);
    }
    /* Check whether FID is out of range.  */
    else if( (FIM_MAX_FID_NUM <= FID) || (NEULIB_CNT_0 == FID) )
    {
        retval = E_NOT_OK;
        /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_FiM_RuleD4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_FiM_TAINTED_PTR" */
        *Permission = FALSE;
        FiM_ReportDevError(FIM_SID_GETFUNCTIONPERMISSION, FIM_E_FID_OUT_OF_RANGE);
    }
    /* Check whether pointer is NULL. */
    else if( NULL_PTR == Permission )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        retval = E_NOT_OK;
        FiM_ReportDevError(FIM_SID_GETFUNCTIONPERMISSION, FIM_E_PARAM_POINTER);
    }
    else
    {
#if( FIM_SUPPORT_AVAILABLE == STD_ON )
        /* Check FID available status. */
        if( NEULIB_CNT_0 == FiM_GetBitmapPosValue(FID, FiM_FIDAvailable) )
        {
            /* FID is not available. */
            retval = E_NOT_OK;
            /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_FiM_RuleD4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_FiM_TAINTED_PTR" */
            *Permission = FALSE;
        }
        else
#endif  /* FIM_SUPPORT_AVAILABLE == STD_ON */
        {
            /* Get inhibition counter. */
            fidInhCnt = FiM_FIDInhCnt[FID];

            /* Check inhibition counter. */
            if( NEULIB_CNT_0 < fidInhCnt )
            {
                /* More than one associated event is in inhibit state, FID is inhibitted. */
                /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_FiM_RuleD4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_FiM_TAINTED_PTR" */
                *Permission = FALSE;
            }
            else
            {
                /* No associated event is in inhibit state, FID is allowed. */
                /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_FiM_RuleD4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_FiM_TAINTED_PTR" */
                *Permission = TRUE;
            }
        }
    }

    return retval;
}

#if( FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_ON )
/*
********************************************************************************
* Function Name: FiM_DemTriggerOnEventStatus
*
* Explanation: This service is provided by the Dem in order to call FiM upon
*              status changes.
* (Synchronous)
*
* param: EventId(in) - Identification of an Event by assigned event number. The
*                      Event Number is configured in the Dem.
*        EventStatusByteOld(in) - Extended event status before change.
*        EventStatusByteNew(in) - Detected / reported of event status.
*
* retval: None
********************************************************************************
*/
FUNC(void, FIM_CODE) FiM_DemTriggerOnEventStatus
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_FiM_RuleD4.5" */
    Dem_EventIdType EventId,
    Dem_UdsStatusByteType EventStatusByteOld,
    Dem_UdsStatusByteType EventStatusByteNew
)
{
    uint16 eventIdx;
    Std_ReturnType retval;

    if( FIM_INITIALIZED != FiM_InitializationStatus )
    {
        FiM_ReportDevError(FIM_SID_DEMTRIGGERONEVENTSTATUS, FIM_E_UNINIT);
    }
    else
    {
        /* Search event in event table. */
        retval = FiM_BinarySearchEventId(EventId, &eventIdx);

        if( E_OK == retval )
        {
            /* Check all associated FID of this event. */
            FiM_CheckAssociatedFIDOfEvent(eventIdx, EventStatusByteOld, EventStatusByteNew);
        }
        else
        {
            /* EventId is out of range. */
            FiM_ReportDevError(FIM_SID_DEMTRIGGERONEVENTSTATUS, FIM_E_EVENTID_OUT_OF_RANGE);
        }
    }
}

/*
********************************************************************************
* Function Name: FiM_DemTriggerOnComponentStatus
*
* Explanation:   Triggers on changes of the component failed status.
* (Synchronous)
*
* param:         ComponentId(in) - Identification of a DemComponent.
*                ComponentFailedStatus(in) - New FAILED status of the component.
*
* retval:        None
********************************************************************************
*/
FUNC(void, FIM_CODE) FiM_DemTriggerOnComponentStatus
(
    Dem_ComponentIdType ComponentId,
    boolean ComponentFailedStatus
)
{
    /* This function is to be realized. */
    FIM_DUMMY_STATEMENT(ComponentId);
    FIM_DUMMY_STATEMENT(ComponentFailedStatus);
}
#endif  /* FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_ON */

#if( FIM_SUPPORT_AVAILABLE == STD_ON )
/*
********************************************************************************
* Function Name: FiM_SetFunctionAvailable
*
* Explanation: This service sets the availability of a function. The function is
*              only available if FiMAvailabilitySupport is configured as True.
* (Synchronous)
*
* param:         FID(in) - Identification of a functionality by assigned FID.
*                Availability(in) -The permission of the requested FID.
*
* retval:        E_OK: The Request is accepted.
*                E_NOT_OK: Request is not accepted(e.g. invalid FID is given).
********************************************************************************
*/
FUNC(Std_ReturnType, FIM_CODE) FiM_SetFunctionAvailable
(
    FiM_FunctionIdType FID,
    boolean Availability
)
{
    Std_ReturnType retval = E_OK;

    if( FIM_INITIALIZED != FiM_InitializationStatus )
    {
        retval = E_NOT_OK;
        FiM_ReportDevError(FIM_SID_SETFUNCTIONAVAILABLE, FIM_E_UNINIT);
    }
    else if( (FIM_MAX_FID_NUM <= FID) || (NEULIB_CNT_0 == FID) )
    {
        retval = E_NOT_OK;
        FiM_ReportDevError(FIM_SID_SETFUNCTIONAVAILABLE, FIM_E_FID_OUT_OF_RANGE);
    }
    else
    {
        if( FALSE == Availability )
        {
            FiM_ClrBitmapPosValue(FID, FiM_FIDAvailable);
        }
        else
        {
            FiM_SetBitmapPosValue(FID, FiM_FIDAvailable);
        }
    }

    return retval;
}
#endif  /* FIM_SUPPORT_AVAILABLE == STD_ON */

/*
********************************************************************************
* Function Name: FiM_MainFunction
*
* Explanation:   Scheduled function for FiM polling mode.
* (Synchronous)
*
* param:         None
*
* retval:        None
********************************************************************************
*/
FUNC(void, FIM_CODE) FiM_MainFunction(void)
{
#if( FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF )
    FiM_EventPollingProcessor();
#endif  /* FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF */
}

#if( FIM_VERSION_INFO_API == STD_ON )
/*
********************************************************************************
* Function Name: FiM_GetVersionInfo
*
* Explanation:   This service returns the version information of this module.
* (Synchronous)
*
* param: versioninfo(in) - Pointer to where to store the version information of
*                          this module.
*
* retval: None
********************************************************************************
*/
FUNC(void, FIM_CODE) FiM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, FIM_APPL_DATA) versioninfo
)
{
    if( NULL_PTR == versioninfo )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Pointer parameter is NULL. */
        FiM_ReportDevError(FIM_SID_GETVERSIONINFO, FIM_E_PARAM_POINTER);
    }
    else
    {
        /* Set the version information. */
        /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_FiM_RuleD4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_FiM_TAINTED_PTR" */
        versioninfo->moduleID = FIM_MODULE_ID;
        versioninfo->vendorID = FIM_VENDOR_ID;
        versioninfo->sw_major_version = FIM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = FIM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = FIM_SW_PATCH_VERSION;
    }
}
#endif  /* FIM_VERSION_INFO_API == STD_ON */

#define FIM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "FiM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


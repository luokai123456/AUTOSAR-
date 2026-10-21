/*
********************************************************************************
*
* File name: BswM.c
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: yong.zhang/2018.12.13
* Change: New created
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: yong.zhang/2019.06.10
* Change: Modify QAC Check Warning.
* Cause: Revision
********************************************************************************
* Version: 3.0
* Author/Date: yong.zhang/2020.03.27
* Change: Nothing
* Cause: Update to V3.0
********************************************************************************
* Version: 3.1
* Author/Date: yong.zhang/2020.04.26
* Change: Adapt Sd function
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: yong.zhang/2020.04.26
* Change: 1.Complete BswM/BswMGeneral. 2.Change code style.
* Cause: Update
*********************************************************************************
* Version: 3.3
* Author/Date: yong.zhang/2020.05.19
* Change: 1.Restructure BswM code for Readability.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: yong.zhang/2020.05.19
* Change: 1.Add BswM_EcuM_CurrentWakeup.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: yong.zhang/2020.05.19
* Change: 1.Add BswM_EthSM_CurrentState.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: yong.zhang/2020.07.07
* Change: 1.Fix bug and check parameter.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: yong.zhang/2020.07.07
* Change: 1.Add macro to control code.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: yong.zhang/2020.07.08
* Change: 1.Fix bug NEUSCCORE-374.
*         2.Add BswM_Sd_ClientServiceCurrentState,
*           BswM_Sd_ConsumedEventGroupCurrentState,
*           BswM_Sd_EventHandlerCurrentState
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: yong.zhang/2020.07.09
* Change: SWS_BswM_00129, the BswM shall execute the Com_IpduGroupControl
*         commands at the end of its processing of the BswM main function.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: fangtao/2020.09.15
* Change: Modify the function name according to the AUTOSAR specification, add
*         MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: fangtao/2020.11.2
* Change: add macro to protect timer.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: FangT/2020.11.04
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.14
* Author/Date: FangT/2021.06.21
* Change: Modify the macro position in the Sd module Api.
* Cause: Optimization
********************************************************************************
* Version: 3.15
* Author/Date: FangT/2021.06.30
* Change: Modify code specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.16
* Author/Date: FangT/2021.08.02
* Change: BswM_DecreaseTimer function declaration adds macro switch.
* Cause: Optimization
********************************************************************************
* Version: 3.17
* Author/Date: FangT/2021.08.09
* Change: Modify the userHandle variable compilation warning is not used.
* Cause: Optimization
********************************************************************************
* Version: 3.18
* Author/Date: FangT/2021.08.11
* Change: Improve the BswM_EcuM_CurrentWakeup API function.
* Cause: Optimization
********************************************************************************
* Version: 3.19
* Author/Date: FangT/2021.08.17
* Change: Modify the code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.20
* Author/Date: FangT/2021.08.25
* Change: Added BswM_Dcm_CommunicationMode_CurrentState and
*         BswM_EcuM_CurrentState functions.
* Cause: Optimization
********************************************************************************
* Version: 3.21
* Author/Date: FangT/2021.09.01
* Change: Eliminate compilation warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.22
* Author/Date: FangT/2021.09.07
* Change: 1.EcuMWakeUp and Dcm state initialization are added
*         to the BswM initialization function.
*         2.Modify the wake-up source ID comparison method.
* Cause: Optimization
********************************************************************************
* Version: 3.22
* Author/Date: FangT/2021.10.15
* Change: 1.ComMPNC adds immediate arbitration.
*         2.The header file Bswm_Dcm.h is changed to Dcm.h.
* Cause: Optimization
********************************************************************************
* Version: 3.23
* Author/Date: FangT/2021.10.27
* Change: The header file Dcm.h is changed to BswM_Dcm.h.
* Cause: Optimization
********************************************************************************
* Version: 3.24
* Author/Date: FangT/2021.10.28
* Change: Modify the code header file specification.
* Cause: Optimization
********************************************************************************
* Version: 3.25
* Author/Date: FangT/2021.10.29
* Change: Modify coding style.
* Cause: Optimization
********************************************************************************
* Version: 3.26
* Author/Date: FangT/2021.11.1
* Change: Modify coding style.
* Cause: Optimization
********************************************************************************
* Version: 3.27
* Author/Date: FangT/2021.11.3
* Change: Add FrSM related functions.
* Cause: Optimization
********************************************************************************
* Version: 3.28
* Author/Date: FangT/2021.12.29
* Change: Meet AutoSAR requirements [SWS_BswM_00150].
* Cause: Optimization
********************************************************************************
* Version: 3.29
* Author/Date: HeHao/2022.06.16
* Change: Add a COMM_DUMMY_STATEMENT() call for wakeupSource in function
*         BswM_EcuM_CurrentWakeup to avoid compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.30
* Author/Date: HeHao/2022.06.20
* Change: Merge from Branch_21Q2
* Cause: Optimization
********************************************************************************
* Version: 3.31
* Author/Date: FangT/2022.09.05
* Change: Add the function of LinSM.
* Cause: Optimization
********************************************************************************
* Version: 3.32
* Author/Date: FangT/2022.09.09
* Change: BswM_LinSM_CurrentState modify judgment mode range error.
* Cause: Optimization
********************************************************************************
* Version: 3.33
* Author/Date: FangT/2022.09.22
* Change: Add multi-core capability.
* Cause: Optimization
********************************************************************************
* Version: 3.34
* Author/Date: FangT/2022.09.26
* Change: Added macro switch to interface BswM_CanSM_CurrentState.
* Cause: Optimization
********************************************************************************
* Version: 3.35
* Author/Date: FangT/2022.11.17
* Change: Resolve initialization problems.
* Cause: Optimization
********************************************************************************
* Version: 3.36
* Author/Date: FangT/2023.01.12
* Change: 1.Modify Pnc and Sd errors.
*         2.Clear compilation warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.37
* Author/Date: HeHao/2023.08.01
* Change: Clear compiler warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.38
* Author/Date: HeHao/2023.11.02
* Change: 1.Merge J1939 branch.
*         2.Clear compiler warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.39
* Author/Date: HeHao/2023.12.04
* Change: 1. Store root partition id for multi-partition enabled BswM use-case,
*            meanwhile delete BswM_CurrentPartIdx because it's no longer needed.
*         2. Modify generic mode request API to allow accepting mode requests
*            that're launched from the root partition of the requested BswM
*            instance while the requested BswM instance is being initialized.
*         3. Include LinTp header file.
* Cause: Bugfix
********************************************************************************
* Version: 3.40
* Author/Date: HeHao/2023.12.06
* Change: 1. Store root application id for multi-partition enabled BswM use-case:
*            Root application id is used when root parition has no BswM instance.
*         2. Modify generic mode request API to allow accepting mode requests
*            that're launched from the root partition(which has no BswM instance)
*            of the requested BswM instance while the requested BswM instance is
*            being initialized.
* Cause: Bugfix
********************************************************************************
* Version: 3.41
* Author/Date: HeHao/2023.12.25
* Change: 1. Bugfix for CCOREDBUG-4250:
*            Add BswM_MemCmp, BswM_MemCpy, BswM_MemSet for memory operations,
*            Call BswM_SwcModeRequestDataInit if necessary.
* Cause: Bugfix
********************************************************************************
* Version: 3.42
* Author/Date: HeHao/2023.12.25
* Change: 1. Clear QAC warnings for:
*            BswM_MemCmp, BswM_MemCpy, BswM_MemSet function.
*         2. Update process of single-partition use-case BswM when dealing with
*            BswMSwcModeRequest data initialization.
* Cause: Optimization
********************************************************************************
* Version: 3.43
* Author/Date: HeHao/2024.03.11
* Change: 1. Change P2CONST's ptrclass from XXX_APPL_CONST to XXX_APPL_DATA.
* Cause: Optimization
********************************************************************************
* Version: 3.44
* Author/Date: HeHao/2024.04.02
* Change: 1. Change P2CONST's ptrclass.
*         2. Modify comments.
* Cause: Optimization
*************************************** *****************************************
* Version: 3.45
* Author/Date: LuQ/2024.07.26
* Change: 1. Add MemMap segment definition.
*         2. Modify the variables used to determine the state of the semaphore.
* Cause: Bugfix
********************************************************************************
* Version: 3.46
* Author/Date: LuQ/2024.08.28
* Change: Modify MemMap segment definition.
* Cause: Bugfix
********************************************************************************
* Version: 3.47
* Author/Date: LuQ/2025.03.27
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 3.48
* Author/Date: LuQ/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.49
* Author/Date: LuQ/2025.06.23
* Change: 1. Modify MemMap segment definition.
*         2. Modify the polyspace deviation suppression comment.
* Cause: Bugfix
********************************************************************************
* Version: 3.50
* Author/Date: LuQ/2025.06.24
* Change: Modify the macro name of the EcuM_ShutdownTargetType.
* Cause: Bugfix
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "BswM.h"
#include "Os.h"

#if( BSWM_DEVERRORDETECT == STD_ON )
#include "Det.h"
#endif

#if( BSWM_DCMENABLED == STD_ON )
#include "BswM_Dcm.h"
#endif

#if( BSWM_NVMENABLED == STD_ON )
#include "NvM.h"
#endif

#if( BSWM_COMMENABLED == STD_ON )
#include "ComM.h"
#include "BswM_ComM.h"
#endif

#if( BSWM_CANSMENABLED == STD_ON )
#include "CanSM_BswM.h"
#include "BswM_CanSM.h"
#endif

#if( BSWM_WDGMENABLED == STD_ON )
#include "BswM_WdgM.h"
#endif

#if( BSWM_ECUMENABLED == STD_ON )
#include "BswM_EcuM.h"
#endif

#if( BSWM_ETHSMENABLED == STD_ON )
#include "EthSM.h"
#include "BswM_EthSM.h"
#endif

#if( BSWM_SDENABLED == STD_ON )
#include "Sd.h"
#endif

#if( BSWM_FRSMENABLED == STD_ON )
#include "BswM_FrSM.h"
#endif

#if( BSWM_LINSMENABLED == STD_ON )
#include "LinSM.h"
#include "BswM_LinSM.h"
#endif

#if( BSWM_LINTPENABLED == STD_ON )
#include "LinTp.h"
#include "BswM_linTp.h"
#endif

#if( BSWM_NMENABLED == STD_ON )
#include "Nm.h"
#endif

#if( BSWM_J1939NMENABLED == STD_ON )
#include "J1939Nm.h"
#endif

#if( BSWM_SWCMODEREQUEST_DATA_INIT == STD_ON )
/* Include NeuLib for memcpy, memcmp, etc. */
#include "NeuLib.h"
#endif


/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
#define BSWM_REQUEST_SEMAPHORE_UNLOCKED   (0U)
#define BSWM_REQUEST_SEMAPHORE_LOCKED     (1U)

/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro"  PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define BswM_EnterCriticalArea_0()        SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0()
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro"  PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define BswM_LeaveCriticalArea_0()        SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0()

/* BswM code running status */
#define BSWM_INITPROCESSING               (0U)
#define BSWM_PERIODPROCESSING             (1U)
/*
********************************************************************************
*    Local Types
********************************************************************************
*/
/*
********************************************************************************
*    Local Variables
********************************************************************************
*/
/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
#define BSWM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap  */
static FUNC(void, BSWM_CODE) BswM_ProcessQueuedRequests
(
    uint8 partitionIdx,
    uint8 partitionId
);
LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_ReleaseQueue
(
    uint8 partitionIdx,
    uint8 partitionId
);
LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_ExecuteActionLists
(
    uint8 executionLevel,
    uint8 partitionId
);
#if( BSWM_SIZE_DEFERRED_RULE > BSWM_ZERO )
LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_ExecuteDeferredRules(uint8 partitionId);
#endif

#if( BSWM_SIZE_TIMER > BSWM_ZERO )
LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_DecreaseTimer(uint8 partitionId);
#endif

#if( BSWM_MULTIPARTITION == STD_ON )
static FUNC(void, BSWM_CODE) BswM_GetPartitionIdByAppl
(
    P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA) partitionIdx,
    P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA) partitionId
);

static FUNC(Std_ReturnType, BSWM_CODE) BswM_GetPartitionIdByCoreId
(
    P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA) loopIdx,
    P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA) partitionIdx,
    P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA) partitionId
);
#endif

#define BSWM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap  */

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define BSWM_START_SEC_GLOBAL_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap  */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_BswM_NonSharedVar" PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_BswM_8.7" */
VAR(uint8, BSWM_VAR_NO_INIT)BswM_QueueSemaphore[BSWM_BSWMCONFIG_SIZE];  /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_BswM_NonSharedVar" PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_BswM_8.7" */
VAR(boolean, BSWM_VAR_NO_INIT)BswM_QueueWritten[BSWM_BSWMCONFIG_SIZE];  /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */

#if( BSWM_MULTIPARTITION == STD_ON )
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_BswM_NonSharedVar" */
VAR(BswM_ProcessingState_st, BSWM_VAR_NO_INIT)BswM_ProcessingState[BSWM_BSWMCONFIG_SIZE];  /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
#endif
#define BSWM_STOP_SEC_GLOBAL_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap  */

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define BSWM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap  */
/*
********************************************************************************
* Function Name: BswM_ReleaseQueue
*
* Explanation: Service for Release Queue.
*
* param: partitionIdx:Internal partition index.
*        partitionId: Partition index.
*
* retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_ReleaseQueue
(
    uint8 partitionIdx,
    uint8 partitionId
)
{
    uint8 queueIndex;
    /* Handle mode request queue */
    for( queueIndex = BSWM_ZERO; queueIndex < BSWM_SIZE_IMMEDIATE_USER; queueIndex++ )
    {
#if( BSWM_MULTIPARTITION == STD_ON )
        if( BswM_ModeRequestQueue[queueIndex].PartitionId == partitionId )
#endif
        {
            /* If mode request processed, set mode request idle. */
            if( BSWM_REQUEST_PROCESSED == BswM_ModeRequestQueue[queueIndex].RequestMode )
            {
                BswM_ModeRequestQueue[queueIndex].RequestMode = BSWM_REQUEST_IDLE;
            }
            else if( BSWM_REQUEST_PENDING == BswM_ModeRequestQueue[queueIndex].RequestMode )
            {
                /* If mode request pending, then set mode request queue, continue handle mode request */
                BswM_QueueWritten[partitionIdx] = TRUE;
                BswM_ModeRequestQueue[queueIndex].RequestMode = BSWM_REQUEST_QUEUED;
            }
            else
            {
                /* Do nothing */
            }
        }
    }
#if( BSWM_MULTIPARTITION == STD_OFF )
    BSWM_DUMMY_STATEMENT(partitionId);
#endif

}

/*
********************************************************************************
* Function Name: BswM_ProcessQueuedRequests
*
* Explanation: Service for Processing Queued requests.
*
* param: partitionIdx:Internal partition index.
*        partitionId: Partition index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, BSWM_CODE) BswM_ProcessQueuedRequests
(
    uint8 partitionIdx,
    uint8 partitionId
)
{
    /* Local variables. */
    uint8 immediateUserIndex;
    uint8 ruleIndex;
    uint8 actionListIndex;
    boolean executeActionLists = TRUE;
    uint8 queueState = BSWM_REQUEST_IDLE;

    while( (executeActionLists == TRUE) && (BswM_QueueWritten[partitionIdx] == TRUE) )
    {
        /* set queue write false */
        BswM_QueueWritten[partitionIdx] = FALSE;
        executeActionLists = FALSE;

        /* Handle immediate user. */
        for( immediateUserIndex = BSWM_ZERO; immediateUserIndex < BSWM_SIZE_IMMEDIATE_USER; immediateUserIndex++ )
        {
            /* If immediate user has queued, then find the corresponding rules of
               this user , and arbitration the rules. */
            if( (BSWM_REQUEST_QUEUED == BswM_ModeRequestQueue[immediateUserIndex].RequestMode)
#if( BSWM_MULTIPARTITION == STD_ON )
                &&(BswM_ModeRequestQueue[immediateUserIndex].PartitionId == partitionId)
#endif
            )
            {
                for( ruleIndex = BswM_ImmediateUser[immediateUserIndex].RulesIndStartIdx;
                        ruleIndex <= BswM_ImmediateUser[immediateUserIndex].RulesIndEndIdx; ruleIndex++ )
                {
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.1"  PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_BswM_18.1"  Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_BswM_OutBoundArray" */
                    actionListIndex = BswM_Rules[(BswM_RulesInd[ruleIndex])].FctPtrOfRules();

                    /* If have action to handle and action queue is idle, then pending this action in queue. */
                    if( (actionListIndex < BSWM_SIZE_ACTIONLIST) &&
                        (BswM_ActionListQueue[actionListIndex].ActionListState == BSWM_ACTIONLIST_IDLE) )
                    {
                        queueState = BSWM_REQUEST_PROCESSED;
                        BswM_ActionListQueue[actionListIndex].ActionListState = BSWM_ACTIONLIST_PENDING;
                    }
                }
                /* If any action has pending in action_list queue, then
                   set corresponding mode request queue processed. */
                if( queueState == BSWM_REQUEST_PROCESSED )
                {
                    BswM_ModeRequestQueue[immediateUserIndex].RequestMode = BSWM_REQUEST_PROCESSED;
                    queueState = BSWM_REQUEST_QUEUE_RELEASE;
                    executeActionLists = TRUE;
                }
                else
                {
                    /* No pending action in action_list, set mode request queue idle. */
                    BswM_ModeRequestQueue[immediateUserIndex].RequestMode = BSWM_REQUEST_IDLE;
                }
            }
        }

        if( TRUE == executeActionLists )
        {
            /* Have pending action in action_list, then handle this action. */
            BswM_ExecuteActionLists(BSWM_ACTIONLIST_PENDING, partitionId);
        }
    }

    if( BSWM_REQUEST_QUEUE_RELEASE == queueState )
    {
        /* Release queue. */
        BswM_ReleaseQueue(partitionIdx, partitionId);
    }
}

/*
********************************************************************************
* Function Name: BswM_ImmediateModeRequest
*
* Explanation: Service for Immediate Mode Request operation of BswM.
*
* param: start: Start Value Of Immediate User Index.
*        end: End Value Of Immediate User Index.
*        partitionIdx: Internal partition index.
*        partitionId: Partition index.
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_BswM_8.7" */
FUNC(void, BSWM_CODE) BswM_ImmediateModeRequest  /* PRQA S 1505 */ /* NSCA_QAC_Common_Rule8.7 */
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 start,
    uint8 end,
    uint8 partitionIdx,
    uint8 partitionId
)
{
    /* Local variables. */
    uint8 localSemaphore;
    uint8 immediateUserIndex;

    /* Judge user id range valid, and bswm init. */
    if( (BSWM_SIZE_IMMEDIATE_USER >= end) &&
        (TRUE == BswM_Initialized[partitionIdx].Initialized) )
    {
        localSemaphore = BswM_QueueSemaphore[partitionIdx];

        /* if semaphore unlocked, then lock the semaphore. */
        if( BSWM_REQUEST_SEMAPHORE_UNLOCKED == localSemaphore )
        {
            BswM_QueueSemaphore[partitionIdx] = BSWM_REQUEST_SEMAPHORE_LOCKED;
        }

        /* Handle immediate user */
        for( immediateUserIndex = start; immediateUserIndex < end; immediateUserIndex++ )
        {
            /* If corresponding mode request queue of immediate
               user is idle, then set this mode request queued. */
            if( (BSWM_REQUEST_IDLE == BswM_ModeRequestQueue[immediateUserIndex].RequestMode)
#if( BSWM_MULTIPARTITION == STD_ON )
                &&(BswM_ModeRequestQueue[immediateUserIndex].PartitionId == partitionId)
#endif
              )
            {
                /* Set queue written true */
                BswM_QueueWritten[partitionIdx] = TRUE;
                BswM_ModeRequestQueue[immediateUserIndex].RequestMode = BSWM_REQUEST_QUEUED;
            }
            else if( (BSWM_REQUEST_PROCESSED == BswM_ModeRequestQueue[immediateUserIndex].RequestMode )
#if( BSWM_MULTIPARTITION == STD_ON )
                     &&(BswM_ModeRequestQueue[immediateUserIndex].PartitionId == partitionId)
#endif
            )
            {
                /* If corresponding mode request of this immediate user
                   has been processed, then pending this mode request. */
                BswM_ModeRequestQueue[immediateUserIndex].RequestMode = BSWM_REQUEST_PENDING;
            }
            else
            {
                /* Mode is already queued. That means that there is a former mode
                  change on this mode port which has not been processed yet. */
            }
        }

        if( BSWM_REQUEST_SEMAPHORE_UNLOCKED == localSemaphore )
        {
            /* Immediately process other pending immediate requests. */
            BswM_ProcessQueuedRequests(partitionIdx, partitionId);
            /* Unlock semaphore after processing of the queue. */
            BswM_QueueSemaphore[partitionIdx] = BSWM_REQUEST_SEMAPHORE_UNLOCKED;
        }
    }
}

/*
********************************************************************************
* Function Name: BswM_DecreaseTimer
*
* Explanation: Service for Expiring All Configured Timers.
*
* param: partitionIdx: Partition index.
*
* retval: None
********************************************************************************
*/
#if( BSWM_SIZE_TIMER > BSWM_ZERO )
LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_DecreaseTimer(uint8 partitionId)
{
    /* Local variables. */
    uint8 timerIndex = BSWM_ZERO;
    /* Decrease all timer, if timer value is zero, set timer state expired. */
    for( timerIndex = BSWM_ZERO; timerIndex < BSWM_SIZE_TIMER; timerIndex++ )
    {
        if( (BswM_TimerState[timerIndex].Timevalue > BSWM_ZERO)
            &&(BswM_TimerState[timerIndex].Timestate == BSWM_TIMER_STARTED)
#if( BSWM_MULTIPARTITION == STD_ON )
            &&(BswM_TimerState[timerIndex].PartitionId == partitionId)
#endif
         )
        {
            BswM_TimerState[timerIndex].Timevalue--;
            if( BswM_TimerState[timerIndex].Timevalue == BSWM_ZERO )
            {
                BswM_TimerState[timerIndex].Timestate = BSWM_TIMER_EXPIRED;
            }
        }
    }
#if( BSWM_MULTIPARTITION != STD_ON )
    BSWM_DUMMY_STATEMENT(partitionId);
#endif
}
#endif

/*
********************************************************************************
* Function Name: BswM_ExecuteActionLists
*
* Explanation: Service for Executing Action Lists.
*
* param: executionLevel: executionLevel of action list which shall be executed.
*           partitionId: Partition index.
*
* retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_ExecuteActionLists
(
    uint8 executionLevel,
    uint8 partitionId
)
{
    /* Local variables. */
    uint8 actionListIndex;

    /* Handle action list, if action is executinLevel, then handle the action. */
    for( actionListIndex = BSWM_ZERO; actionListIndex < BSWM_SIZE_ACTIONLIST; actionListIndex++ )
    {
        if( (BswM_ActionListQueue[actionListIndex].ActionListState == executionLevel)
#if( BSWM_MULTIPARTITION == STD_ON )
            &&(BswM_ActionListQueue[actionListIndex].PartitionId == partitionId)
#endif
          )
        {
            BswM_ActionListQueue[actionListIndex].ActionListState = BSWM_ACTIONLIST_BLOCKED;
            (void)BswM_ActionLists[actionListIndex].FctPtrOfActionLists();
            BswM_ActionListQueue[actionListIndex].ActionListState = BSWM_ACTIONLIST_IDLE;
        }
    }
#if( BSWM_MULTIPARTITION == STD_OFF )
    BSWM_DUMMY_STATEMENT(partitionId);
#endif
}

#if( BSWM_SIZE_DEFERRED_RULE > BSWM_ZERO )
/*
********************************************************************************
* Function Name: BswM_ExecuteDeferredRules
*
* Explanation: Service for Executing Deferred Rules.
*
* param: PartitionIdx:Partition index.
*
* retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_ExecuteDeferredRules(uint8 partitionId)
{
    /* Local variables. */
    uint8 ruleIndex;
    uint8 actionListIndex;
    uint8 deferredRuleIdx;
    boolean executeActionLists = FALSE;

    /* Handle deferred rules. */
    for( ruleIndex = BSWM_ZERO; ruleIndex < BSWM_SIZE_DEFERRED_RULE; ruleIndex++ )
    {
#if( BSWM_MULTIPARTITION == STD_ON )
        if( BswM_DeferredRules[ruleIndex].PartitionId == partitionId )
#endif
        {
            deferredRuleIdx = BswM_DeferredRules[ruleIndex].RulesIdxOfDeferredRules;
            actionListIndex = BswM_Rules[deferredRuleIdx].FctPtrOfRules();

            /* If the result of arbitration is id of action, then execute the action */
            if( (actionListIndex < BSWM_SIZE_ACTIONLIST) &&
                (BSWM_ACTIONLIST_IDLE == BswM_ActionListQueue[actionListIndex].ActionListState) )
            {
                executeActionLists = TRUE;
                BswM_ActionListQueue[actionListIndex].ActionListState = BSWM_ACTIONLIST_PENDING;
            }
        }
    }
    /* Have action to execute. */
    if( TRUE == executeActionLists )
    {
        BswM_ExecuteActionLists(BSWM_ACTIONLIST_PENDING, partitionId);
    }
}
#endif

#if( BSWM_MULTIPARTITION == STD_ON )
/*
********************************************************************************
* Function Name: BswM_GetPartitionIdByAppl
*
* Explanation: Get the corresponding PartitionID through ApplicationID.
*
* param: partitionIdx: Internal partition index.
*        partitionId: Partition index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, BSWM_CODE) BswM_GetPartitionIdByAppl
(
    P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA) partitionIdx,
    P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA) partitionId
)
{
    uint8 cfgIdx;
    uint8 applIdx;

    ApplicationType applicationId = GetCurrentApplicationID();

    /* loop for all BswM instances. */
    for( cfgIdx = BSWM_ZERO; cfgIdx < BSWM_BSWMCONFIG_SIZE; cfgIdx++ )
    {
        for( applIdx = BSWM_ZERO; applIdx < BswM_ApplMapping[cfgIdx].ApplNum; applIdx++ )
        {
            /* PolySpace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_BswM_10.4" */
            if( BswM_ApplMapping[cfgIdx].ApplId[applIdx] == applicationId )  /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
            {
                /* get partition id by applicationId. */
                *partitionId = BswM_ApplMapping[cfgIdx].PartitionId;
                break;
            }
        }
        if( applIdx < BswM_ApplMapping[cfgIdx].ApplNum )
        {
            /* if partition id is found, break the loop. */
            break;
        }
    }
    if( cfgIdx < BSWM_BSWMCONFIG_SIZE )
    {
        /* loop for all BswM instances. */
        for( cfgIdx = BSWM_ZERO; cfgIdx < BSWM_BSWMCONFIG_SIZE; cfgIdx++ )
        {
            if( *partitionId == BswM_Initialized[cfgIdx].PartitionId )
            {
                /* get partition cfg index by partition id. */
                *partitionIdx = cfgIdx;
                break;
            }
        }
    }
    else
    {
        /* partition not found. */
        *partitionId = BSWM_INVALID_VALUE;
    }
}
/*
********************************************************************************
* Function Name: BswM_GetPartitionIdByCoreId
*
* Explanation: Get the corresponding PartitionID through CoreID.
*
* param: loopIdx: Query the starting position of CoreIdMapping.
*        partitionIdx: Internal partition index.
*        partitionId: Partition index.
*
* retval: None
********************************************************************************
*/
static FUNC(Std_ReturnType, BSWM_CODE) BswM_GetPartitionIdByCoreId
(
    P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA) loopIdx,
    P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA) partitionIdx,
    P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA) partitionId
)
{
    /* PolySpace +1 MISRA-C3:5.8 [Justified:Unset] "NSCA_Polyspace_BswM_5.8" */
    uint8 index;
    Std_ReturnType retVal = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    CoreIdType coreId = GetCoreID();

    /* ----- Implementation ----------------------------------------------- */
    for( index = *loopIdx; index < BSWM_COREIDMAPPING_SIZE; index++ )
    {
        if( coreId == BswM_CoreIdMapping[index].CoreId )
        {
            *partitionId = BswM_CoreIdMapping[index].PartitionId;
            break;
        }
    }
    if( index < BSWM_COREIDMAPPING_SIZE )
    {
        *loopIdx = index;
        for( index = BSWM_ZERO; index < BSWM_BSWMCONFIG_SIZE; index++ )
        {
            if( *partitionId == BswM_Initialized[index].PartitionId )
            {
                *partitionIdx = index;
                break;
            }
        }
        retVal = E_OK;
    }
    return retVal;
}
#endif

#if( BSWM_SWCMODEREQUEST_DATA_INIT == STD_ON )
/*
********************************************************************************
* Function Name: BswM_MemCmp
*
* Explanation: To compare the values in the two given addresses.
*
* param: dstPtr: Dest Ptr.
*        srcPtr: Source Ptr.
*        size: Byte Counter.
* retval: BSWM_EQUAL: Values in the two given addresses are the same.
*         BSWM_NOT_EQUAL: Values in the two given addresses are different.
********************************************************************************
*/
FUNC(uint8, BSWM_CODE) BswM_MemCmp
(
    P2CONST(void, AUTOMATIC, BSWM_APPL_DATA) dstPtr,
    P2CONST(void, AUTOMATIC, BSWM_APPL_DATA) srcPtr,
    uint32 size
)
{
    uint8 isEqual;
    boolean retValue;

    retValue = NeuLib_memcmp(dstPtr, srcPtr, size);

    if( TRUE == retValue )
    {
        isEqual = BSWM_EQUAL;
    }
    else
    {
        isEqual = BSWM_NOT_EQUAL;
    }

    return isEqual;
}

/*
********************************************************************************
* Function Name: BswM_MemCpy
*
* Explanation: BswM Memcpy Function: copy data from srcPtr to dstPtr.
*
* param: dstPtr: Dest Ptr.
*        srcPtr: Source Ptr.
*        size: Byte Counter.
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE) BswM_MemCpy
(
    P2VAR(void, AUTOMATIC, BSWM_APPL_DATA) dstPtr,
    P2CONST(void, AUTOMATIC, BSWM_APPL_DATA) srcPtr,
    uint32 size
)
{
    NeuLib_memcpy(dstPtr, srcPtr, size);

    return;
}

/*
********************************************************************************
* Function Name: BswM_MemSet
*
* Explanation: To initial the [dstPtr] with [value].
*
* param: destPtr: The destination of the data.
*        value: Data value.
*        size: The length of the data
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE) BswM_MemSet
(
    P2VAR(void, AUTOMATIC, BSWM_APPL_DATA) dstPtr,
    uint8 value,
    uint32 size
)
{

    NeuLib_memset(dstPtr, value, size);

    return;
}
#endif  /* (BSWM_SWCMODEREQUEST_DATA_INIT == STD_ON ) */

/*
********************************************************************************
* Function Name: BswM_Init
*
* Explanation: Service for resetting all internal variables.
*
* param: ConfigPtr: Component configuration structure.
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE) BswM_Init  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_APPL_CONST)ConfigPtr
)
{
    /* Local variables. */
    uint8 idx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;
    uint8 rootApplicationId = BSWM_ZERO;

#if( BSWM_MULTIPARTITION == STD_ON )
    uint8 loopIdx = BSWM_ZERO;  /* Index for retriving BswM instances within a core. */

    /* A root partition is the partition where BswM_Init is called from.
       (BswM_Init is called by EcuM_StartupTwo which is called by an InitTask).
       All BswM instances within this core are spawned by BswM_Init so they
       share a same root partition id. */
    uint8 rootPartitionIdx = BSWM_ZERO;  /* Only used for API call. */
    uint8 rootPartitionId = BSWM_ZERO;   /* Root partition id. */

    /* To determine from which partition the BswM Init is called.
       It's called root partition for all BswM instances on this core. */
    BswM_GetPartitionIdByAppl(&rootPartitionIdx, &rootPartitionId);
    BSWM_DUMMY_STATEMENT(rootPartitionIdx);  /* Unused variable. */
    /* It is possible that the root partition has no BswM instance,
       so we need to store the root application id. */
    rootApplicationId = (uint8)GetCurrentApplicationID();

    /* Start of loop for all BswM instances on this core. */
    while( E_OK == BswM_GetPartitionIdByCoreId(&loopIdx, &partitionIdx, &partitionId) )
    {
        /* Each time a call of BswM_GetPartitionIdByCoreId function,
        a BswM instance on this core is obtained if E_OK is returned. */
        loopIdx++;

        /* Current partition is in BSWM_INITPROCESSING. */
        BswM_ProcessingState[partitionIdx].ProcessingState = BSWM_INITPROCESSING;

        /* Set own partition's id (configured by the PC tool). */
        BswM_ProcessingState[partitionIdx].PartitionId = partitionId;

        /* Store from which partition the BswM instance is initialized. */
        BswM_ProcessingState[partitionIdx].RootPartitionId = rootPartitionId;

        /* Store from which application the BswM instance is initialized. */
        BswM_ProcessingState[partitionIdx].RootApplicationId = rootApplicationId;
#endif
        if( TRUE == BswM_Initialized[partitionIdx].Initialized )
        {
            errorId = BSWM_E_ALREADY_INITIALIZED;
        }
        else
        {
#if( BSWM_SWCMODEREQUEST_DATA_INIT == STD_ON )
#if( BSWM_MULTIPARTITION == STD_ON )
            /* Get the partition id of multi-partition BswM use-case. */
            BswM_SwcModeRequestDataInit(partitionId);
#else
            /* Get the correct partition id of single-partition BswM use-case. */
            BswM_SwcModeRequestDataInit(BswM_Initialized[partitionIdx].PartitionId);
#endif
#endif  /* BSWM_SWCMODEREQUEST_DATA_INIT == STD_ON */
            /* Lock semaphore during initialization to queue incoming mode requests. */
            BswM_QueueSemaphore[partitionIdx] = BSWM_REQUEST_SEMAPHORE_LOCKED;
            BswM_QueueWritten[partitionIdx] = FALSE;
#if( BSWM_SIZE_ACTIONLIST > BSWM_ZERO )
            /* set action list queue idle. */
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_ACTIONLIST; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_ActionListQueue[idx].PartitionId == partitionId )
#endif
                {
                    BswM_ActionListQueue[idx].ActionListState = BSWM_ACTIONLIST_IDLE;
                }
            }
#endif

#if( BSWM_SIZE_CANSM_CHANNEL > BSWM_ZERO )
            /* set cansm channel state no_communication. */
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_CANSM_CHANNEL; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_CanSMChannelMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_CanSMChannelState[idx] = BswM_CanSMChannelMapping[idx].InitValue;
                }
            }
#endif

#if( BSWM_SIZE_CANSMICOM_CHANNEL > BSWM_ZERO )
            /* set cansm channel state no_communication. */
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_CANSMICOM_CHANNEL; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_CanSMIcomChannelMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_CanSMIcomChannelState[idx] = BswM_CanSMIcomChannelMapping[idx].InitValue;
                }
            }
#endif


#if( BSWM_SIZE_COMM_CHANNEL > BSWM_ZERO )
            /* set comm channel state no_communication. */
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_COMM_CHANNEL; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_ComMChannelMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_ComMChannelState[idx] = BswM_ComMChannelMapping[idx].InitValue;
                }
            }
#endif

#if( BSWM_SIZE_GENERIC > BSWM_ZERO )
            /* set generic state by configuration. */
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_GENERIC; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_GenericMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_GenericState[idx] = BswM_GenericMapping[idx].InitValue;
                }
            }
#endif

#if( BSWM_SIZE_NVM_JOB > BSWM_ZERO )
            /* set nvm job state ok. */
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_NVM_JOB; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if(BswM_NvMJobMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_NvMJobState[idx] = BswM_NvMJobMapping[idx].InitValue;
                }
            }
#endif

#if( BSWM_SIZE_TIMER > BSWM_ZERO )
            /* set timer state and value. */
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_TIMER; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_TimerState[idx].PartitionId == partitionId )
#endif
                {
                    BswM_TimerState[idx].Timestate = BSWM_TIMER_STOPPED;
                    BswM_TimerState[idx].Timevalue = BSWM_ZERO;
                }
            }
#endif

#if( BSWM_SIZE_IMMEDIATE_USER > BSWM_ZERO )
            /* set mode request queue. */
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_IMMEDIATE_USER; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_ModeRequestQueue[idx].PartitionId == partitionId )
#endif
                {
                    BswM_ModeRequestQueue[idx].RequestMode = BSWM_REQUEST_IDLE;
                }
            }
#endif

            /* Set EcuM channel state */
#if( BSWM_SIZE_ECUM_CHANNEL > BSWM_ZERO )
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_ECUM_CHANNEL; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_EcuMChannelMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_EcuMChannelState[idx] = BswM_EcuMChannelMapping[idx].InitValue;
                }
            }
#endif
            /* Set EcuM WakeUp state */
#if( BSWM_SIZE_ECUM_WAKEUP > BSWM_ZERO )
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_ECUM_WAKEUP; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_EcuMWakeUpMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_EcuMWakeupState[idx] = BswM_EcuMWakeUpMapping[idx].InitValue;
                }
            }
#endif
            /* Set EthSM channel state */
#if( BSWM_SIZE_ETHSM_CHANNEL > BSWM_ZERO )
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_ETHSM_CHANNEL; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_EthSMChannelMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_EthSMChannelState[idx] = BswM_EthSMChannelMapping[idx].InitValue;
                }
            }
#endif
            /* Set EthSM channel state */
#if( BSWM_SIZE_COMMPNC_CHANNEL > BSWM_ZERO )
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_COMMPNC_CHANNEL; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_ComMPncChannelMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_ComMPncChannelState[idx] = BswM_ComMPncChannelMapping[idx].InitValue;
                }
            }
#endif

#if( BSWM_SIZE_DCM_CHANNEL > BSWM_ZERO )
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_DCM_CHANNEL; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_DcmChannelMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_DcmChannelState[idx] = BswM_DcmChannelMapping[idx].InitValue;
                }
            }
#endif

#if( BSWM_SIZE_FRSM > BSWM_ZERO )
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_FRSM; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_FrSMMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_FrSMState[idx] = BswM_FrSMMapping[idx].InitValue;
                }
            }
#endif

#if( BSWM_SIZE_LINSMSCHEDULE > BSWM_ZERO )
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_LINSMSCHEDULE; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_LinSMScheduleMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_LinSMScheduleState[idx] = BswM_LinSMScheduleMapping[idx].InitValue;
                }
            }
#endif

#if( BSWM_SIZE_LINSM_CHANNEL > BSWM_ZERO )
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_LINSM_CHANNEL; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_LinSMChannelMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_LinSMChannelState[idx] = BswM_LinSMChannelMapping[idx].InitValue;
                }
            }
#endif

#if( BSWM_SIZE_CANSMICOM_CHANNEL > BSWM_ZERO )
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_CANSMICOM_CHANNEL; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_CanSMIcomChannelMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_CanSMIcomChannelState[idx] = BswM_CanSMIcomChannelMapping[idx].InitValue;
                }
            }
#endif

#if( BSWM_SIZE_LINTP_CHANNEL > BSWM_ZERO )
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_LINTP_CHANNEL; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_LinTpChannelMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_LinTpChannelState[idx] = BswM_LinTpChannelMapping[idx].InitValue;
                }
            }
#endif

#if( BSWM_SIZE_NVM_BLOCK > BSWM_ZERO )
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_NVM_BLOCK; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_NvMBlockMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_NvMBlockState[idx] = BswM_NvMBlockMapping[idx].InitValue;
                }
            }
#endif

#if( BSWM_SIZE_SDCLIENTSERVICE > BSWM_ZERO )
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_SDCLIENTSERVICE; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_SdClientServiceMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_SdClientServiceState[idx] = BswM_SdClientServiceMapping[idx].InitValue;
                }
            }
#endif

#if( BSWM_SIZE_CONSUMEDEVENTGROUP > BSWM_ZERO )
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_CONSUMEDEVENTGROUP; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_SdConsumedEventGroupMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_SdConsumedEventGroupState[idx] = BswM_SdConsumedEventGroupMapping[idx].InitValue;
                }
            }
#endif

#if( BSWM_SIZE_EVENTHANDLER > BSWM_ZERO )
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_EVENTHANDLER; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_SdEventHandlerMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_SdEventHandlerState[idx] = BswM_SdEventHandlerMapping[idx].InitValue;
                }
            }
#endif

#if( BSWM_SIZE_J1939DCM_CHANNEL > BSWM_ZERO )
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_J1939DCM_CHANNEL; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_J1939DcmChannelMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_J1939DcmChannelState[idx] = BswM_J1939DcmChannelMapping[idx].InitValue;
                }
            }
#endif

#if( BSWM_SIZE_J1939NM_CHANNEL > BSWM_ZERO )
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_J1939NM_CHANNEL; idx++ )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_J1939NmChannelMapping[idx].PartitionId == partitionId )
#endif
                {
                    BswM_J1939NmChannelState[idx] = BswM_J1939NmChannelMapping[idx].InitValue;
                }
            }
#endif
            /* BswM state variables are initialized.
               Arbitration requests can be accepted now. */
            BswM_Initialized[partitionIdx].Initialized = TRUE;

            /* set immediate user queueWritten->true, modeRequesetQueue->request_queued (only ESH_State). */
            for( idx = BSWM_ZERO; idx < BSWM_SIZE_IMMEDIATE_USER; idx++ )
            {
                /* Mode request when init, only ESH_State */
                if( BSWM_TWO == (BswM_ImmediateUser[(idx)].MaskedBits & BSWM_TWO) )
                {
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Common_Unreachable " */
                    BswM_QueueWritten[partitionIdx] = TRUE;               /* BswM_QueueWritten */
#if( BSWM_MULTIPARTITION == STD_ON )
                    if( BswM_ModeRequestQueue[idx].PartitionId == partitionId )
#endif
                    {
                        BswM_ModeRequestQueue[idx].RequestMode = BSWM_REQUEST_QUEUED;    /* BswM_ModeRequestQueue */
                    }
                }
            }

            /* Arbitrate mode requests which shall be arbitrated on initialization or
                occurred during the execution of the initiating action lists. */
            BswM_ProcessQueuedRequests(partitionIdx, partitionId);

            /* Unlock the semaphore. */
            BswM_QueueSemaphore[partitionIdx] = BSWM_REQUEST_SEMAPHORE_UNLOCKED;        /* only one semaphore */
        }
        /* End of current partition's BswM initialization and on-init arbitration requests process. */

#if( BSWM_MULTIPARTITION == STD_ON )
        /* BswM instance is fully operational, all initial arbitration processed. */
        BswM_ProcessingState[partitionIdx].ProcessingState = BSWM_PERIODPROCESSING;
    }
    /* End of loop for all BswM instances on this core. */
#endif

    /* Dev error report. */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BSWM_INIT_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif

    BSWM_DUMMY_STATEMENT(ConfigPtr);  /* Unused parameter. */
}

/*
********************************************************************************
* Function Name: BswM_Deinit
*
* Explanation: Service for Deinitializes the BSW Mode Manager.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE) BswM_Deinit(void)  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    /* Local variables. */
    uint8 queueIndex;
    uint8 partitionIdx = BSWM_ZERO;

#if( BSWM_MULTIPARTITION == STD_ON )
    uint8 loopIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;

    while( E_OK == BswM_GetPartitionIdByCoreId(&loopIdx, &partitionIdx, &partitionId) )
    {
        loopIdx++;
#endif

        /* Deinit bswm moudle. */
        BswM_Initialized[partitionIdx].Initialized = FALSE;

        /* Set every mode request idle. */
        for( queueIndex = BSWM_ZERO; queueIndex < BSWM_SIZE_IMMEDIATE_USER; queueIndex++ )
        {
#if( BSWM_MULTIPARTITION == STD_ON )
            if( BswM_ModeRequestQueue[queueIndex].PartitionId == partitionId )
#endif
            {
                BswM_ModeRequestQueue[queueIndex].RequestMode = BSWM_REQUEST_IDLE;
            }
        }
#if( BSWM_MULTIPARTITION == STD_ON )
    }
#endif
}

/*
********************************************************************************
* Function Name: BswM_RequestMode
*
* Explanation: Generic function call to request mod
*
* param: requesting_user: The user that requests the mode.
*        requested_mode: The requested mode.
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE) BswM_RequestMode  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    BswM_UserType requesting_user,
    BswM_ModeType requested_mode
)
{
    /* Local variables. */
    uint8 userHandle = BSWM_ZERO;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;

    /* Start of Multi-Partition BswM use-case mode request process. */
#if( BSWM_MULTIPARTITION == STD_ON )
    /* Requested BswM instance handles. */
    uint8 requestedPartitionId = BSWM_ZERO;
    uint8 requestedPartitionIdx = BSWM_ZERO;

    /* Requester's partition id and index. */
    uint8 requesterPartitionId = BSWM_ZERO;
    uint8 requesterPartitionIdx = BSWM_ZERO;
    uint8 requesterAppId = BSWM_ZERO;

    /* Determine from which application this mode request is launched. */
    requesterAppId = (uint8)GetCurrentApplicationID();

    /* Determine from which partition this mode request is launched. */
    BswM_GetPartitionIdByAppl(&requesterPartitionIdx, &requesterPartitionId);

    /* Get the requested partition id by requesting_user. (configured partition id). */
    for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_GENERIC; userHandle++ )
    {
        /* Match requesting_user with ExternalId. */
        if( BswM_GenericMapping[userHandle].ExternalId == requesting_user )
        {
            /* The requested partition id is found. */
            requestedPartitionId = BswM_GenericMapping[userHandle].PartitionId;

            /* Get the requested partition's configuration index. */
            requestedPartitionIdx = BswM_GenericMapping[userHandle].PartitionIdx;

            break;  /* break the loop since the object has been found. */
        }
    }
    /* If userHandle equals to BSWM_SIZE_GENERIC means no match. */
    if( BSWM_SIZE_GENERIC == userHandle )
    {
        /* Can not find the BswM instance of the requested partition,
           illegal requesting_user. */
        errorId = BSWM_E_REQ_USER_OUT_OF_RANGE;
    }
    else
    {
        /* Check if the requested BswM instance has been initialized. */
        if( BswM_Initialized[requestedPartitionIdx].Initialized != TRUE )
        {
            /* The requested partition has not been initialized,
               mode request shall not be accepted. */
            errorId = BSWM_E_NO_INIT;
        }
    }

    /* No error occurs, check the origin of the mode request. */
    if( BSWM_E_NO_ERROR == errorId )
    {
        /* Check if the requester's partition is the same as
           the requested partition(pre-configured). */
        if( (requesterPartitionId != BSWM_INVALID_VALUE)
            && (requesterPartitionId == requestedPartitionId) )
        {
            /* A mode request originated from the same partition as the
               requested BswM instance is always acceptable. */
            partitionIdx = requesterPartitionIdx;
            partitionId = requesterPartitionId;
        }
        else
        {
            /* A mode request launched from a foreign partition can be accepted ONLY if:
                (1) the requested BswM instance is running in BSWM_INITPROCESSING mode. And,
                (2) the requester partition is the root partition of the requested BswM instance.
               other wise, this is an illegal mode request from upper layer, reject it. */
            if( BSWM_INITPROCESSING == BswM_ProcessingState[requestedPartitionIdx].ProcessingState )
            {
                /* The requester's partition(application) is the root partition(application). */
                if( requesterAppId == BswM_ProcessingState[requestedPartitionIdx].RootApplicationId )
                {
                    /* It means the mode request is a result of an arbitration (which is an BswMAction)
                       during the initializing of the requested BswM instance (i.e. during BswM_Init).
                       Hence, set the correct parameters (requested BswM instance) for further processing.
                    */
                    partitionIdx = requestedPartitionIdx;
                    partitionId = requestedPartitionId;
                }
                else
                {
                    /* [illegal scenario] Wrong requesting_user:
                       The mode request was launched from a partition which is not
                       the root partition of the requested BswM instance. */
                    errorId = BSWM_E_REQ_USER_OUT_OF_RANGE;
                }
            }
            else
            {
                /* [illegal scenario] Wrong requesting_user:
                   The mode request was launched from a foreign partition when the requested
                   BswM instance is running in BSWM_PERIODPROCESSING mode. */
                errorId = BSWM_E_REQ_USER_OUT_OF_RANGE;
            }
        }
    }

    /* No error occurs, handle the mode request. */
    if( BSWM_E_NO_ERROR == errorId )
    {
        /* Set Generic state. */
        BswM_GenericState[userHandle] = requested_mode;

        /* Handle immediate mode request. */
        BswM_ImmediateModeRequest(BswM_GenericMapping[userHandle].ImmediateUserStartIdx,
                                  BswM_GenericMapping[userHandle].ImmediateUserEndIdx,
                                  partitionIdx,
                                  partitionId);
    }
    /* End of Multi-Partition BswM mode request. */
#else  /* ( BSWM_MULTIPARTITION != STD_ON ) */
    /* Start of Single-Partition BswM use-case mode request process. */
    errorId = BSWM_E_REQ_USER_OUT_OF_RANGE;  /* Set default error id. */

    /* Judge BswM module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        /* BswM has not been initialized. */
        errorId = BSWM_E_NO_INIT;
    }
    else
    {
        /* Handle Generic mode request state. */
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_GENERIC; userHandle++ )
        {
            if( BswM_GenericMapping[userHandle].ExternalId == requesting_user )
            {
                /* Set Generic state. */
                BswM_GenericState[userHandle] = requested_mode;
                /* Handle immediate mode request. */
                BswM_ImmediateModeRequest(BswM_GenericMapping[userHandle].ImmediateUserStartIdx,
                                          BswM_GenericMapping[userHandle].ImmediateUserEndIdx,
                                          partitionIdx,
                                          partitionId);
                errorId = BSWM_E_NO_ERROR;
                break;
            }
        }
    }
    /* End of Single-Partition BswM mode request. */
#endif

    /* Dev error report. */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        /* Report to DET if error occurred. */
        (void)BswM_ReportDevError(BSWM_REQUESTMODE_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);  /* Unused variable. */
#endif

}

#if( BSWM_COMMENABLED == STD_ON )
/*
********************************************************************************
* Function Name: BswM_ComM_CurrentMode
*
* Explanation: Function called by ComM to indicate the current
*              communication mode of a ComM channel.
*
* param: Network: The ComM communication channel that the indicated state
*                 corresponds to.
*        RequestedMode: The current state of the ComM communication channel.
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE) BswM_ComM_CurrentMode  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    NetworkHandleType Network,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    ComM_ModeType RequestedMode
)
{
    /* Local variables. */
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 userHandle = BSWM_ZERO;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;
#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        errorId = BSWM_E_NO_INIT;
    }
    /* SWS_BswM_00091 */
    else if( RequestedMode > COMM_FULL_COMMUNICATION )
    {
        errorId = BSWM_E_REQ_MODE_OUT_OF_RANGE;
    }
    else
    {

#if( BSWM_SIZE_COMM_CHANNEL > BSWM_ZERO )
        /* Set comm current mode. */
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_COMM_CHANNEL; userHandle++ )
        {
            if( BswM_ComMChannelMapping[userHandle].ExternalId == Network )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_ComMChannelMapping[userHandle].PartitionId == partitionId )
#endif
                {
                    BswM_ComMChannelState[userHandle] = RequestedMode;
                    /* Handle immediate mode request. */
                    BswM_ImmediateModeRequest(BswM_ComMChannelMapping[userHandle].ImmediateUserStartIdx,
                                              BswM_ComMChannelMapping[userHandle].ImmediateUserEndIdx,
                                              partitionIdx,
                                              partitionId);
                    break;
                }
            }
        }
#else
        BSWM_DUMMY_STATEMENT(userHandle);
#endif

    }
    /* Dev error report. */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BSWM_COMM_CURRENTMODE_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif

}
#endif

#if( BSWM_ETHSMENABLED == STD_ON )
/*
********************************************************************************
* Function Name: BswM_EthSM_CurrentState
*
* Explanation: Function called by EthSM to indicate its current state.
*
* param: Network: The Ethernet channel that the indicated state corresponds to.
*       CurrentState: The current state of the Ethernet channel.
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE) BswM_EthSM_CurrentState  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    NetworkHandleType Network,
    EthSM_NetworkModeStateType CurrentState
)
{
    /* Local variables. */
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 userHandle = BSWM_ZERO;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;

#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        errorId = BSWM_E_NO_INIT;
    }
    /* SWS_BswM_00097 */
    /* PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_BswM_14.3" */
    else if( CurrentState > ETHSM_STATE_WAIT_OFFLINE )
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Common_Unreachable " */
    {
        errorId = BSWM_E_REQ_MODE_OUT_OF_RANGE;
    }
    else
    {

#if( BSWM_SIZE_ETHSM_CHANNEL > BSWM_ZERO )
        /* Set ethsm current mode. */
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_ETHSM_CHANNEL; userHandle++ )
        {
            if( BswM_EthSMChannelMapping[userHandle].ExternalId == Network )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_EthSMChannelMapping[userHandle].PartitionId == partitionId )
#endif
                {
                    BswM_EthSMChannelState[userHandle] = (uint8)CurrentState;
                    /* Handle immediate mode request. */
                    BswM_ImmediateModeRequest(BswM_EthSMChannelMapping[userHandle].ImmediateUserStartIdx,
                                              BswM_EthSMChannelMapping[userHandle].ImmediateUserEndIdx,
                                              partitionIdx,
                                              partitionId);

                    break;
                }
            }
        }
#else
        BSWM_DUMMY_STATEMENT(userHandle);
        BSWM_DUMMY_STATEMENT(Network);
#endif

    }
    /* Dev error report. */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BSWM_ETHSM_CURRENTSTATE_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif

}

#endif

#if( BSWM_COMMENABLED == STD_ON )
/*
********************************************************************************
* Function Name: BswM_ComM_CurrentPNCMode
*
* Explanation: Function called by ComM to indicate the current mode of the PNC.
*
* param: PNC: The handle of the PNC for which the current state is reported.
*        CurrentPncMode: The current mode of the PNC.
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE)BswM_ComM_CurrentPNCMode  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    PNCHandleType PNC,
    ComM_PncModeType CurrentPncMode
)
{
    /* Local variables. */
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 userHandle = BSWM_ZERO;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;
#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        errorId = BSWM_E_NO_INIT;
    }
    /* PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_BswM_14.3" */
    else if( CurrentPncMode > COMM_PNC_FULL_COMMUNICATION )
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Common_Unreachable " */
    {
        errorId = BSWM_E_REQ_MODE_OUT_OF_RANGE;
    }
    else
    {

#if( BSWM_SIZE_COMMPNC_CHANNEL > BSWM_ZERO )
        /* Set ComM currentPnc mode. */
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_COMMPNC_CHANNEL; userHandle++ )
        {
            if( BswM_ComMPncChannelMapping[userHandle].ExternalId == PNC )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_ComMPncChannelMapping[userHandle].PartitionId == partitionId )
#endif
                {
                    BswM_ComMPncChannelState[userHandle] = (uint8)CurrentPncMode;
                    /* Handle immediate mode request. */
                    BswM_ImmediateModeRequest(BswM_ComMPncChannelMapping[userHandle].ImmediateUserStartIdx,
                                              BswM_ComMPncChannelMapping[userHandle].ImmediateUserEndIdx,
                                              partitionIdx,
                                              partitionId);
                    break;
                }
            }
        }
#else
        BSWM_DUMMY_STATEMENT(userHandle);
        BSWM_DUMMY_STATEMENT(PNC);
        BSWM_DUMMY_STATEMENT(partitionId);
#endif

    }
    /* Dev error report. */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BSWM_COMM_PNC_CURRENTMODE_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif

    return;
}
#endif

#if( BSWM_DCMENABLED == STD_ON )
/*
********************************************************************************
* Function Name: BswM_Dcm_ApplicationUpdated
*
* Explanation: This function is called by the DCM in order to report an updated
*              application.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE) BswM_Dcm_ApplicationUpdated(void)  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    /* Local variables */
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 errorId = BSWM_E_NO_ERROR;

    BSWM_DUMMY_STATEMENT(errorId);
    return;
}

/*
********************************************************************************
* Function Name: BswM_Dcm_CommunicationMode_CurrentState
*
* Explanation: Function called by DCM to inform the BswM about the current state
*           of the communication mode.
*
* param: Network:The communication channel that the diagnostic mode corresponds to.
*        RequestedMode:The requested diagnostic communication mode.
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE)BswM_Dcm_CommunicationMode_CurrentState  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    NetworkHandleType Network,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    Dcm_CommunicationModeType RequestedMode
)
{
    /* Local variables. */
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 userHandle = BSWM_ZERO;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;
#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        errorId = BSWM_E_NO_INIT;
    }
    /* SWS_BswM_00095 */
    else if( RequestedMode > DCM_DISABLE_RX_TX_NORM_NM )
    {
        errorId = BSWM_E_REQ_MODE_OUT_OF_RANGE;
    }
    else
    {

#if( BSWM_SIZE_DCM_CHANNEL > BSWM_ZERO )
        /* Set Dcm current state. */
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_DCM_CHANNEL; userHandle++ )
        {

            if( BswM_DcmChannelMapping[userHandle].ExternalId == Network )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_DcmChannelMapping[userHandle].PartitionId == partitionId )
#endif
                {
                    BswM_DcmChannelState[userHandle] = (uint8)RequestedMode;

                    /* Handle immediate mode request. */
                    BswM_ImmediateModeRequest(BswM_DcmChannelMapping[userHandle].ImmediateUserStartIdx,
                                              BswM_DcmChannelMapping[userHandle].ImmediateUserEndIdx,
                                              partitionIdx,
                                              partitionId);

                    break;
                }
            }
        }
#else
        BSWM_DUMMY_STATEMENT(userHandle);
        BSWM_DUMMY_STATEMENT(Network);
#endif

    }
    /* Dev error report. */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BSWM_DCM_COMMUNICATION_STATE_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif

    return;
}
#endif

#if( BSWM_CANSMICOMENABLED == STD_ON )
/*
********************************************************************************
* Function Name: BswM_CanSM_CurrentIcomConfiguration
*
* Explanation: Function to inform BswM about the switch of Icom Configuration.
*
* param: Network: The CAN channel the requested state corresponds to.
*        ActiveConfiguration: The configuration Id of the Icom configuration.
*        Error: ICOM_SWITCH_E_OK: No Error.
*               ICOM_SWITCH_E_FAILED: Switch to requested Configuration failed.
*               Severe Error.
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE) BswM_CanSM_CurrentIcomConfiguration
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    NetworkHandleType Network,
    IcomConfigIdType ActiveConfiguration,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    IcomSwitch_ErrorType Error
)
{
    /* Local variables. */
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 userHandle = BSWM_ZERO;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;

#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        errorId = BSWM_E_NO_INIT;
    }
    else
    {
#if( BSWM_SIZE_CANSMICOM_CHANNEL > BSWM_ZERO )
        /* Set CanSmIcom current state. */
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_CANSMICOM_CHANNEL; userHandle++ )
        {

            if( (BswM_CanSMIcomChannelMapping[userHandle].ExternalId == Network)&&
                (BswM_CanSMIcomChannelMapping[userHandle].ErrorType == Error) )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_CanSMIcomChannelMapping[userHandle].PartitionId == partitionId )
#endif
                {
                    BswM_CanSMIcomChannelState[userHandle] = (uint8)ActiveConfiguration;

                    /* Handle immediate mode request. */
                    BswM_ImmediateModeRequest(BswM_CanSMIcomChannelMapping[userHandle].ImmediateUserStartIdx,
                                              BswM_CanSMIcomChannelMapping[userHandle].ImmediateUserEndIdx,
                                              partitionIdx,
                                              partitionId);
                    break;
                }
            }
        }
#else
        BSWM_DUMMY_STATEMENT(userHandle);
        BSWM_DUMMY_STATEMENT(Network);
        BSWM_DUMMY_STATEMENT(ActiveConfiguration);
        BSWM_DUMMY_STATEMENT(Error);
#endif
    }
        /* Dev error report. */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BswM_CANSM_CURRENTICOMCONFIGURATION_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif
}
#endif

#if( BSWM_CANSMENABLED == STD_ON )
/*
********************************************************************************
* Function Name: BswM_CanSM_CurrentState
*
* Explanation: Function called by CanSM to indicate its current state.
*
* param: Network: The communication channel that the diagnostic mode corresponds to.
*        CurrentState: The current state of the CAN channel.
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE)BswM_CanSM_CurrentState  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    NetworkHandleType Network,
    CanSM_BswMRequestModeType CurrentState
)
{
    /* Local variables. */
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 userHandle = BSWM_ZERO;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;

#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        errorId = BSWM_E_NO_INIT;
    }
    /* SWS_BswM_00095 */
    /* PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_BswM_14.3" */
    else if( CurrentState > CANSM_BSWM_CHANGE_BAUDRATE )
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Common_Unreachable " */
    {
        errorId = BSWM_E_REQ_MODE_OUT_OF_RANGE;
    }
    else
    {

#if( BSWM_SIZE_CANSM_CHANNEL > BSWM_ZERO )
        /* Set CanSm current state. */
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_CANSM_CHANNEL; userHandle++ )
        {

            if( BswM_CanSMChannelMapping[userHandle].ExternalId == Network )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_CanSMChannelMapping[userHandle].PartitionId == partitionId )
#endif
                {
                    BswM_CanSMChannelState[userHandle] = (uint8)CurrentState;

                    /* Handle immediate mode request. */
                    BswM_ImmediateModeRequest(BswM_CanSMChannelMapping[userHandle].ImmediateUserStartIdx,
                                              BswM_CanSMChannelMapping[userHandle].ImmediateUserEndIdx,
                                              partitionIdx,
                                              partitionId);
                    break;
                }
            }
        }
#else
        BSWM_DUMMY_STATEMENT(userHandle);
        BSWM_DUMMY_STATEMENT(Network);
#endif

    }
    /* Dev error report. */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BSWM_CANSM_CURRENTSTATE_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif

}
#endif

#if( BSWM_NVMENABLED == STD_ON )
/*
********************************************************************************
* Function Name: BswM_NvM_CurrentJobMode
*
* Explanation: Function called by NvM to inform the BswM about the current
*              state of a multi block job.
*
* param: ServiceId: Indicates whether the callback refers to multi block services.
*        CurrentJobMode: Current state of the multi block job indicated by
*                        parameter ServiceId.
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE)BswM_NvM_CurrentJobMode  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 ServiceId,
    NvM_RequestResultType CurrentJobMode
)
{
    /* Local variables. */
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 userHandle = BSWM_ZERO;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;

#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        errorId = BSWM_E_NO_INIT;
    }
    /* SWS_BswM_00154 */
    else if( (CurrentJobMode != NVM_REQ_OK) && (CurrentJobMode != NVM_REQ_PENDING)
        && (CurrentJobMode != NVM_REQ_NOT_OK) && (CurrentJobMode != NVM_REQ_CANCELED) )
    {
        errorId = BSWM_E_REQ_MODE_OUT_OF_RANGE;
    }
    else
    {

#if( BSWM_SIZE_NVM_JOB > BSWM_ZERO )
        /* Set Nvm current job mode. */
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_NVM_JOB; userHandle++ )
        {
            if( BswM_NvMJobMapping[userHandle].ExternalId == ServiceId )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_NvMJobMapping[userHandle].PartitionId == partitionId )
#endif
                {
                    BswM_NvMJobState[userHandle] = (uint8)CurrentJobMode;

                    /* Handle immediate mode request. */
                    BswM_ImmediateModeRequest(BswM_NvMJobMapping[userHandle].ImmediateUserStartIdx,
                                              BswM_NvMJobMapping[userHandle].ImmediateUserEndIdx,
                                              partitionIdx,
                                              partitionId);
                    break;
                }
            }
        }
#else
        BSWM_DUMMY_STATEMENT(userHandle);
        BSWM_DUMMY_STATEMENT(ServiceId);
        BSWM_DUMMY_STATEMENT(partitionId);
#endif

    }
    /* Dev error report */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BSWM_NVM_CURRENTJOBMODE_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif

}

/*
********************************************************************************
* Function Name: BswM_NvM_CurrentBlockMode
*
* Explanation:Function called by NvM to indicate the current block mode of an
*             NvM block.
*
* param: Block: The Block that the new NvM Mode corresponds to.
*        CurrentBlockMode: The current block mode of the NvM block.
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE)BswM_NvM_CurrentBlockMode  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    NvM_BlockIdType Block,
    NvM_RequestResultType CurrentBlockMode
)
{
    /* Local variables. */
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 userHandle = BSWM_ZERO;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;

#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        errorId = BSWM_E_NO_INIT;
    }
    /* SWS_BswM_00154 */
    else if( CurrentBlockMode > NVM_REQ_RESTORED_FROM_ROM )
    {
        errorId = BSWM_E_REQ_MODE_OUT_OF_RANGE;
    }
    else
    {

#if( BSWM_SIZE_NVM_BLOCK > BSWM_ZERO )
        /* Set Nvm current job mode. */
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_NVM_BLOCK; userHandle++ )
        {
            if( BswM_NvMBlockMapping[userHandle].ExternalId == Block )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_NvMBlockMapping[userHandle].PartitionId == GetCurrentApplicationID() )
#endif
                {
                    BswM_NvMBlockState[userHandle] = (uint8)CurrentBlockMode;

                    /* Handle immediate mode request. */
                    BswM_ImmediateModeRequest(BswM_NvMBlockMapping[userHandle].ImmediateUserStartIdx,
                                              BswM_NvMBlockMapping[userHandle].ImmediateUserEndIdx,
                                              partitionIdx,
                                              partitionId);
                    break;
                }
            }
        }
#else
        BSWM_DUMMY_STATEMENT(userHandle);
        BSWM_DUMMY_STATEMENT(Block);
        BSWM_DUMMY_STATEMENT(partitionId);
#endif

    }
    /* Dev error report */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BSWM_NVM_CURRENTBLOCKMODE_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif

}
#endif

#if( BSWM_WDGMENABLED == STD_ON )
/*
********************************************************************************
* Function Name: BswM_WdgM_RequestPartitionReset
*
* Explanation: Function called by WdgM to request a partition reset.
*
* param: Application: The identifier of an OS-Application.
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE)BswM_WdgM_RequestPartitionReset(ApplicationType Application)
{
    /* To be implment */
    BSWM_DUMMY_STATEMENT(Application);

    return;
}
#endif

#if( BSWM_VERSIONINFOAPI == STD_ON )
/*
********************************************************************************
* Function Name: BswM_GetVersionInfo
*
* Explanation: Service to get the version information of the BswM module.
*              (Synchronous)
*
* param: versioninfo: Pointer to where to store the version information of
*                     this module.
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE) BswM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, BSWM_APPL_DATA)versioninfo
)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 errorId = BSWM_E_NO_ERROR;

    if( NULL_PTR == versioninfo )    /* Pointer parameter is Null. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Common_Unreachable " */
    {
        errorId = BSWM_E_NULL_POINTER;
    }
    if( BSWM_E_NO_ERROR == errorId )    /* Pointer parameter is not Null. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Common_Unreachable " */
    {
        versioninfo->vendorID = BSWM_VENDOR_ID;
        versioninfo->moduleID = BSWM_MODULE_ID;
        versioninfo->sw_major_version = BSWM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = BSWM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = BSWM_SW_PATCH_VERSION;
    }

#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )    /* Error detected. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Common_Unreachable " */
    {
        (void)BswM_ReportDevError(BSWM_GETVERSIONINFO_ID, errorId);    /* Report ErrorId to Det. */
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif

}
#endif

#if( BSWM_SDENABLED == STD_ON )
/*
********************************************************************************
* Function Name: BswM_Sd_ClientServiceCurrentState
*
* Explanation: Function called by Service Discovery to indicate current state
*              of the Client Service (available/down).(Synchronous&Reentrant)
*
* param: SdClientServiceHandleId: HandleId to identify the ClientService.
*        CurrentClientState: Current state of the ClientService.
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.4 [Justified:Unset] "NSCA_Polyspace_BswM_8.4" */
FUNC(void, BSWM_CODE) BswM_Sd_ClientServiceCurrentState
(
    uint16 SdClientServiceHandleId,
    Sd_ClientServiceCurrentStateType CurrentClientState
)
{
    /* Local variables. */
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 userHandle = BSWM_ZERO;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;

#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        errorId = BSWM_E_NO_INIT;
    }
    /* SWS_BswM_00206 */
    else if( (CurrentClientState != SD_CLIENT_SERVICE_DOWN) && (CurrentClientState != SD_CLIENT_SERVICE_AVAILABLE) )
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Common_Unreachable " */
    {
        errorId = BSWM_E_REQ_MODE_OUT_OF_RANGE;
    }
    else
    {
        /* Set Sd client service current state. */
#if( BSWM_SIZE_SDCLIENTSERVICE > BSWM_ZERO )
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_SDCLIENTSERVICE; userHandle++ )
        {
            if( BswM_SdClientServiceMapping[userHandle].ExternalId == SdClientServiceHandleId )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_SdClientServiceMapping[userHandle].PartitionId == partitionId )
#endif
                {
                    BswM_SdClientServiceState[userHandle] = CurrentClientState;

                    /* Handle immediate mode request. */
                    BswM_ImmediateModeRequest(BswM_SdClientServiceMapping[userHandle].ImmediateUserStartIdx,
                                              BswM_SdClientServiceMapping[userHandle].ImmediateUserEndIdx,
                                              partitionIdx,
                                              partitionId);
                    break;
                }
            }
        }
#else
        BSWM_DUMMY_STATEMENT(userHandle);
        BSWM_DUMMY_STATEMENT(SdClientServiceHandleId);
#endif

    }
    /* Dev error report. */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BSWM_SD_CLIENTSERVICE_CURRENT_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif

    return;
}

/*
********************************************************************************
* Function Name: BswM_Sd_ConsumedEventGroupCurrentState
*
* Explanation: Function called by Service Discovery to indicate current status
*              of the Consumed Eventgroup (available/down).(Synchronous&Reentrant)
*
* param: SdConsumedEventGroupHandleId: HandleId to identify the Consumed Eventgroup.
*        ConsumedEventGroupState: Status of the Consumed Eventgroup.
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.4 [Justified:Unset] "NSCA_Polyspace_BswM_8.4" */
FUNC(void, BSWM_CODE) BswM_Sd_ConsumedEventGroupCurrentState
(
    uint16 SdConsumedEventGroupHandleId,
    Sd_ConsumedEventGroupCurrentStateType ConsumedEventGroupState
)
{
    /* Local variables. */
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 userHandle = BSWM_ZERO;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;

#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        errorId = BSWM_E_NO_INIT;
    }
    /* SWS_BswM_00209 */
    /* PolySpace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_BswM_10.4" */
    else if( (ConsumedEventGroupState != SD_CLIENT_SERVICE_DOWN) &&
    (ConsumedEventGroupState != SD_CLIENT_SERVICE_AVAILABLE) )
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Common_Unreachable " */
    {
        errorId = BSWM_E_REQ_MODE_OUT_OF_RANGE;
    }
    else
    {
        /* Set Sd Consumedevent current state. */
#if( BSWM_SIZE_CONSUMEDEVENTGROUP > BSWM_ZERO )
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_CONSUMEDEVENTGROUP; userHandle++ )
        {
            if( BswM_SdConsumedEventGroupMapping[userHandle].ExternalId == SdConsumedEventGroupHandleId )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_SdConsumedEventGroupMapping[userHandle].PartitionId == partitionId )
#endif
                {
                    BswM_SdConsumedEventGroupState[userHandle] = ConsumedEventGroupState;

                    /* Handle immediate mode request. */
                    BswM_ImmediateModeRequest(BswM_SdConsumedEventGroupMapping[userHandle].ImmediateUserStartIdx,
                                              BswM_SdConsumedEventGroupMapping[userHandle].ImmediateUserEndIdx,
                                              partitionIdx,
                                              partitionId);
                    break;
                }
            }
        }
#else
        BSWM_DUMMY_STATEMENT(userHandle);
        BSWM_DUMMY_STATEMENT(SdConsumedEventGroupHandleId);
#endif

    }
    /* Dev error report. */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BSWM_SD_CONSUMEDEVENTGROUP_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif

    return;
}

/*
********************************************************************************
* Function Name: BswM_Sd_EventHandlerCurrentState
*
* Explanation: Function called by Service Discovery to indicate current status
*              of the EventHandler (requested/released).(Synchronous&Reentrant)
*
* param: SdEventHandlerHandleId: HandleId to identify the EventHandler.
*        EventHandlerStatus: Status of the EventHandler.
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.4 [Justified:Unset] "NSCA_Polyspace_BswM_8.4" */
FUNC(void, BSWM_CODE) BswM_Sd_EventHandlerCurrentState
(
    uint16 SdEventHandlerHandleId,
    Sd_EventHandlerCurrentStateType EventHandlerStatus
)
{
    /* Local variables. */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 userHandle = BSWM_ZERO;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;

#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        errorId = BSWM_E_NO_INIT;
    }
    /* SWS_BswM_00212 */
    else if( (EventHandlerStatus != SD_EVENT_HANDLER_RELEASED) &&
             (EventHandlerStatus != SD_EVENT_HANDLER_REQUESTED) )
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Common_Unreachable " */
    {
        errorId = BSWM_E_REQ_MODE_OUT_OF_RANGE;
    }
    else
    {

#if( BSWM_SIZE_EVENTHANDLER > BSWM_ZERO )
        /* Set Sd EventHandler current state. */
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_EVENTHANDLER; userHandle++ )
        {
            if( BswM_SdEventHandlerMapping[userHandle].ExternalId == SdEventHandlerHandleId )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_SdEventHandlerMapping[userHandle].PartitionId == partitionId )
#endif
                {
                    BswM_SdEventHandlerState[userHandle] = EventHandlerStatus;

                    /* Handle immediate mode request. */
                    BswM_ImmediateModeRequest(BswM_SdEventHandlerMapping[userHandle].ImmediateUserStartIdx,
                                              BswM_SdEventHandlerMapping[userHandle].ImmediateUserEndIdx,
                                              partitionIdx,
                                              partitionId);
                    break;
                }
            }
        }
#else
        BSWM_DUMMY_STATEMENT(userHandle);
        BSWM_DUMMY_STATEMENT(SdEventHandlerHandleId);
        BSWM_DUMMY_STATEMENT(partitionId);
#endif

    }
    /* Dev error report. */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BSWM_SD_EVENTHANDLER_CURRENT_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif

    return;
}
#endif

#if( BSWM_ECUMENABLED == STD_ON )
/*
********************************************************************************
* Function Name: BswM_EcuM_CurrentState
*
* Explanation: Function called by EcuM to indicate the current ECU Operation
*              Mode.(Synchronous&Reentrant)
*
* param: CurrentState: The requested ECU Operation Mode.
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.4 [Justified:Unset] "NSCA_Polyspace_BswM_8.4" */
FUNC(void, BSWM_CODE) BswM_EcuM_CurrentState(EcuM_StateType CurrentState)  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    /* Local variables. */
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 userHandle = BSWM_ZERO;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;

#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        errorId = BSWM_E_NO_INIT;
    }
    /* SWS_BswM_00103 */
    else if( (CurrentState != ECUM_SHUTDOWN_TARGET_SLEEP) && (CurrentState != ECUM_SHUTDOWN_TARGET_RESET) &&
             (CurrentState != ECUM_SHUTDOWN_TARGET_OFF) )
    {
        errorId = BSWM_E_REQ_MODE_OUT_OF_RANGE;
    }
    else
    {

#if( BSWM_SIZE_ECUM_CHANNEL > BSWM_ZERO )
        /* Set EcuM current mode. */
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_ECUM_CHANNEL; userHandle++ )
        {
#if( BSWM_MULTIPARTITION == STD_ON )
            if( BswM_EcuMChannelMapping[userHandle].PartitionId == partitionId )
#endif
            {
                BswM_EcuMChannelState[userHandle] = CurrentState;
                BswM_ImmediateModeRequest(BswM_EcuMChannelMapping[userHandle].ImmediateUserStartIdx,
                                          BswM_EcuMChannelMapping[userHandle].ImmediateUserEndIdx,
                                          partitionIdx,
                                          partitionId);
            }
        }
#else
        BSWM_DUMMY_STATEMENT(userHandle);
        BSWM_DUMMY_STATEMENT(partitionId);
#endif

    }
    /* Dev error report. */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BSWM_ECUM_CURRENTSTATE_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif

}

/*
********************************************************************************
* Function Name: BswM_EcuM_CurrentWakeup
*
* Explanation: Function called by EcuM to indicate the current state of a
*              wakeup source.(Synchronous&Reentrant)
*
* param: source: Wakeup source(s) that changed state.
*        state: The new state of the wakeup source(s).
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE)BswM_EcuM_CurrentWakeup  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    EcuM_WakeupSourceType source,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    EcuM_WakeupStatusType state
)
{
    /* Local variables. */
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 userHandle = BSWM_ZERO;
    uint32 wakeupSource = BSWM_ONE;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;

#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        errorId = BSWM_E_NO_INIT;
    }
    /* SWS_BswM_00133 */
    else if( (state != ECUM_WKSTATUS_NONE) &&
             (state != ECUM_WKSTATUS_PENDING) &&
             (state != ECUM_WKSTATUS_VALIDATED) &&
             (state != ECUM_WKSTATUS_EXPIRED) &&
             (state != ECUM_WKSTATUS_ENABLED) )
    {
        errorId = BSWM_E_REQ_MODE_OUT_OF_RANGE;
    }
    else
    {

#if( BSWM_SIZE_ECUM_WAKEUP > BSWM_ZERO )
        /* Set EcuM WakeUp current mode. */
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_ECUM_WAKEUP; userHandle++ )
        {
            if( (wakeupSource << BswM_EcuMWakeUpMapping[userHandle].ExternalId) == source )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_EcuMWakeUpMapping[userHandle].PartitionId == partitionId )
#endif
                {
                    BswM_EcuMWakeupState[userHandle] = state;
                    /* Handle immediate mode request. */
                    BswM_ImmediateModeRequest(BswM_EcuMWakeUpMapping[userHandle].ImmediateUserStartIdx,
                                              BswM_EcuMWakeUpMapping[userHandle].ImmediateUserEndIdx,
                                              partitionIdx,
                                              partitionId);
                    break;
                }
            }
        }
#else
        BSWM_DUMMY_STATEMENT(userHandle);
        BSWM_DUMMY_STATEMENT(wakeupSource);
        BSWM_DUMMY_STATEMENT(source);
#endif

    }
    /* Dev error report. */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BSWM_ECUM_CURRENTWAKEUP_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif

}
#endif

#if( BSWM_FRSMENABLED == STD_ON )
/*
********************************************************************************
* Function Name: BswM_FrSM_CurrentState
*
* Explanation: Function called by FrSM to indicate its current state.
*
* param: Network: The FlexRay cluster that the indicated state corresponds to.
*        CurrentState:The corrent state of the FlexRay cluster.
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE) BswM_FrSM_CurrentState
(
    NetworkHandleType Network,
    FrSM_BswM_StateType CurrentState
)
{
    /* Local variables. */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 userHandle = BSWM_ZERO;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;

#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        errorId = BSWM_E_NO_INIT;
    }
    /* SWS_BswM_00103 */
    else if( FRSM_LOW_NUMBER_OF_COLDSTARTERS_ECU_PASSIVE < CurrentState )
    {
        errorId = BSWM_E_REQ_MODE_OUT_OF_RANGE;
    }
    else
    {

#if( BSWM_SIZE_FRSM > BSWM_ZERO )
        /* Set FrSM current mode. */
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_FRSM; userHandle++ )
        {
            if( BswM_FrSMMapping[userHandle].ExternalId == Network )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_FrSMMapping[userHandle].PartitionId == partitionId )
#endif
                {
                    BswM_FrSMState[userHandle] = CurrentState;
                    BswM_ImmediateModeRequest(BswM_FrSMMapping[userHandle].ImmediateUserStartIdx,
                                              BswM_FrSMMapping[userHandle].ImmediateUserEndIdx,
                                              partitionIdx,
                                              partitionId);
                }
            }
        }
#else
        BSWM_DUMMY_STATEMENT(userHandle);
        BSWM_DUMMY_STATEMENT(Network);
#endif

    }
    /* Dev error report. */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BSWM_FRSM_CURRENTSTATE_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif

}
#endif

#if( BSWM_LINSMENABLED == STD_ON )
/*
********************************************************************************
* Function Name: BswM_LinSM_CurrentSchedule
*
* Explanation: Function called by LinSM to indicate the currently active schedule
*              table for a specific LIN channel.
*
* param: Network: The LIN channel that the schedule table switch have occurred on.
*        CurrentSchedule: The currently active schedule table of the LIN channel.
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE) BswM_LinSM_CurrentSchedule  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    NetworkHandleType Network,
    LinIf_SchHandleType CurrentSchedule
)
{
    /* Local variables. */
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 userHandle = BSWM_ZERO;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;

#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        errorId = BSWM_E_NO_INIT;
    }
    else
    {

#if( BSWM_SIZE_LINSMSCHEDULE > BSWM_ZERO )
        /* Set LinSM current mode. */
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_LINSMSCHEDULE; userHandle++ )
        {
            if( BswM_LinSMScheduleMapping[userHandle].ExternalId == Network )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_LinSMScheduleMapping[userHandle].PartitionId == partitionId )
#endif
                {
                    BswM_LinSMScheduleState[userHandle] = CurrentSchedule;
                    BswM_ImmediateModeRequest(BswM_LinSMScheduleMapping[userHandle].ImmediateUserStartIdx,
                                              BswM_LinSMScheduleMapping[userHandle].ImmediateUserEndIdx,
                                              partitionIdx,
                                              partitionId);
                }
            }
        }
#else
        BSWM_DUMMY_STATEMENT(userHandle);
        BSWM_DUMMY_STATEMENT(Network);
        BSWM_DUMMY_STATEMENT(CurrentSchedule);
#endif

    }
    /* Dev error report. */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BSWM_LINSM_CURRENTSCHEDULE_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif

}

/*
********************************************************************************
* Function Name: BswM_LinSM_CurrentState
*
* Explanation: Function called by LinSM to indicate its current state.
*
* param: Network: The LIN channel that the indicated state corresponds to.
*        CurrentState: The current state of the LIN channel.
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE) BswM_LinSM_CurrentState  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    NetworkHandleType Network,
    LinSM_ModeType CurrentState
)
{
    /* Local variables. */
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 userHandle = BSWM_ZERO;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;

#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        errorId = BSWM_E_NO_INIT;
    }
    else if( (CurrentState != LINSM_FULL_COM) &&
             (CurrentState != LINSM_NO_COM) )
    {
        errorId = BSWM_E_REQ_MODE_OUT_OF_RANGE;
    }
    else
    {

#if( BSWM_SIZE_LINSM_CHANNEL > BSWM_ZERO )
        /* Set LinSM current mode. */
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_LINSM_CHANNEL; userHandle++ )
        {
            if( BswM_LinSMChannelMapping[userHandle].ExternalId == Network )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_LinSMChannelMapping[userHandle].PartitionId == partitionId )
#endif
                {
                    BswM_LinSMChannelState[userHandle] = CurrentState;
                    BswM_ImmediateModeRequest(BswM_LinSMChannelMapping[userHandle].ImmediateUserStartIdx,
                                              BswM_LinSMChannelMapping[userHandle].ImmediateUserEndIdx,
                                              partitionIdx,
                                              partitionId);
                }
            }
        }
#else
        BSWM_DUMMY_STATEMENT(userHandle);
        BSWM_DUMMY_STATEMENT(Network);
#endif

    }
    /* Dev error report. */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BSWM_LINSM_CURRENTSTATE_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif

}

#endif

#if( BSWM_LINTPENABLED == STD_ON )
/*
********************************************************************************
* Function Name: BswM_LinTp_RequestMode
*
* Explanation: Function called by LinSM to indicate its current state.
*
* param: Network: The LIN channel that the LinTp mode request relates to.
*        LinTpRequestedMode: The requested LIN TP mode.
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE) BswM_LinTp_RequestMode  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    NetworkHandleType Network,
    LinTp_Mode LinTpRequestedMode
)
{
    /* Local variables. */
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 userHandle = BSWM_ZERO;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;

#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        errorId = BSWM_E_NO_INIT;
    }
    else if( (LinTpRequestedMode != LINTP_APPLICATIVE_SCHEDULE) &&
             (LinTpRequestedMode != LINTP_DIAG_REQUEST)&&
             (LinTpRequestedMode != LINTP_DIAG_RESPONSE) )
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Common_Unreachable " */
    {
        errorId = BSWM_E_REQ_MODE_OUT_OF_RANGE;
    }
    else
    {

#if( BSWM_SIZE_LINTP_CHANNEL > BSWM_ZERO )
        /* Set LinSM current mode. */
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_LINTP_CHANNEL; userHandle++ )
        {
            if( BswM_LinTpChannelMapping[userHandle].ExternalId == Network )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_LinTpChannelMapping[userHandle].PartitionId == partitionId )
#endif
                {
                    BswM_LinTpChannelState[userHandle] = (uint8)LinTpRequestedMode;
                    BswM_ImmediateModeRequest(BswM_LinTpChannelMapping[userHandle].ImmediateUserStartIdx,
                                              BswM_LinTpChannelMapping[userHandle].ImmediateUserEndIdx,
                                              partitionIdx,
                                              partitionId);
                }
            }
        }
#else
        BSWM_DUMMY_STATEMENT(userHandle);
        BSWM_DUMMY_STATEMENT(Network);
#endif

    }
    /* Dev error report. */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BSWM_LINTP_REQUESTMODE_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif

}

#endif

#if( BSWM_J1939DCMENABLED == STD_ON )
/*
********************************************************************************
* Function Name: BswM_J1939DcmBroadcastStatus
*
* Explanation: This API tells the BswM the desired communication status of the
*              available networks.
*
* param: NetworkMask: Mask containing one bit for each available network.
*                     1: Network enabled.
*                     0: Network disabled.
*
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE) BswM_J1939DcmBroadcastStatus
(
    uint16 NetworkMask
)
{
    /* Local variables. */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 userHandle = BSWM_ZERO;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;

#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        errorId = BSWM_E_NO_INIT;
    }
    else
    {

#if( BSWM_SIZE_J1939DCM_CHANNEL > BSWM_ZERO )
        /* Set J1939Dcm current mode. */
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_J1939DCM_CHANNEL; userHandle++ )
        {
#if( BSWM_MULTIPARTITION == STD_ON )
            if( BswM_J1939DcmChannelMapping[userHandle].PartitionId == partitionId )
#endif
            {
                BswM_J1939DcmChannelState[userHandle] = NetworkMask;
                BswM_ImmediateModeRequest(BswM_J1939DcmChannelMapping[userHandle].ImmediateUserStartIdx,
                                          BswM_J1939DcmChannelMapping[userHandle].ImmediateUserEndIdx,
                                          partitionIdx,
                                          partitionId);
            }
        }
#else
        BSWM_DUMMY_STATEMENT(userHandle);
#endif

    }
    /* Dev error report. */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BSWM_J1939DCM_BROADCASTSTATUS_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif

}
#endif

#if( BSWM_J1939NMENABLED == STD_ON )
/*
********************************************************************************
* Function Name: BswM_J1939Nm_StateChangeNotification
*
* Explanation: Notification of current J1939Nm state after state changes.
*
* param: Network: Identification of the J1939 channel.
*        Node: Identification of the J1939 node.
*        NmState: Current (new) state of the J1939 node.
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE) BswM_J1939Nm_StateChangeNotification
(
    NetworkHandleType Network,
    uint8 Node,
    Nm_StateType NmState
)
{
    /* Local variables. */
    uint8 errorId = BSWM_E_NO_ERROR;
    uint8 userHandle = BSWM_ZERO;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;

#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( BswM_Initialized[partitionIdx].Initialized != TRUE )
    {
        errorId = BSWM_E_NO_INIT;
    }
    else
    {
#if( BSWM_SIZE_J1939NM_CHANNEL > BSWM_ZERO )
        /* Set J1939Nm current state. */
        for( userHandle = BSWM_ZERO; userHandle < BSWM_SIZE_J1939NM_CHANNEL; userHandle++ )
        {

            if( (BswM_J1939NmChannelMapping[userHandle].ExternalId == Network) &&
                (BswM_J1939NmChannelMapping[userHandle].NodeId == Node) )
            {
#if( BSWM_MULTIPARTITION == STD_ON )
                if( BswM_J1939NmChannelMapping[userHandle].PartitionId == partitionId )
#endif
                {
                    BswM_J1939NmChannelState[userHandle] = NmState;

                    /* Handle immediate mode request. */
                    BswM_ImmediateModeRequest(BswM_J1939NmChannelMapping[userHandle].ImmediateUserStartIdx,
                                              BswM_J1939NmChannelMapping[userHandle].ImmediateUserEndIdx,
                                              partitionIdx,
                                              partitionId);
                    break;
                }
            }
        }
#else
        BSWM_DUMMY_STATEMENT(userHandle);
#endif
    }
        /* Dev error report. */
#if( BSWM_DEVERRORDETECT == STD_ON )
    if( errorId != BSWM_E_NO_ERROR )
    {
        (void)BswM_ReportDevError(BSWM_J1939NM_STATE_ID, errorId);
    }
#else
    BSWM_DUMMY_STATEMENT(errorId);
#endif
}
#endif

/*
********************************************************************************
* Function Name: BswM_MainFunction
*
* Explanation: Service for performing the processing of the BswM jobs.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, BSWM_CODE) BswM_MainFunction(void)  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    /* Local variables. */
    uint8 localSemaphore;
    uint8 partitionIdx = BSWM_ZERO;
    uint8 partitionId = BSWM_ZERO;
#if( BSWM_MULTIPARTITION == STD_ON )
    BswM_GetPartitionIdByAppl(&partitionIdx, &partitionId);
#endif

    /* Judge bswm module init. */
    if( TRUE == BswM_Initialized[partitionIdx].Initialized )
    {
        localSemaphore = BswM_QueueSemaphore[partitionIdx];    /* only one semaphore, BswM_QueueSemaphore */

        /* If semaphore is unlocked, then lock the semaphore. */
        if( BSWM_REQUEST_SEMAPHORE_UNLOCKED == localSemaphore )
        {
            BswM_QueueSemaphore[partitionIdx] = BSWM_REQUEST_SEMAPHORE_LOCKED;    /* BswM_QueueSemaphore */

            /* Process pending immediate requests if semaphore was unlocked. */
            BswM_ProcessQueuedRequests(partitionIdx, partitionId);
        }

#if( BSWM_SIZE_TIMER > BSWM_ZERO )
        /* Decrease all configured timers. */
        BswM_DecreaseTimer(partitionId);
#endif

#if( BSWM_SIZE_DEFERRED_RULE > BSWM_ZERO )
        /* Arbitrate and execute all rules which have at least one
           deferred port (BswM_ExecuteDeferredRules). */
        BswM_ExecuteDeferredRules(partitionId);
#endif
        if( BSWM_REQUEST_SEMAPHORE_UNLOCKED == localSemaphore )
        {
            /* Immediately process other pending immediate requests. */
            BswM_ProcessQueuedRequests(partitionIdx, partitionId);
            /* Unlock semaphore AFTER processing of the queue. */
            BswM_QueueSemaphore[partitionIdx] = BSWM_REQUEST_SEMAPHORE_UNLOCKED;
        }

#if( BSWM_SWCMODEREQUESTUPDATE_FUNC == STD_ON )
        BswM_SwcModeRequestUpdateFunc(partitionId);
#endif

#if( BSWM_MODENOTIFICATION_FUNC == STD_ON )
        BswM_ModeNotificationFunc(partitionId);
#endif

#if( BSWM_IPDU_GROUP_CONTROL == STD_ON )
        BswM_ExecuteIpduGroupControl();    /* SWS_BswM_00129 */
#endif

    }
}

#define BSWM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap  */


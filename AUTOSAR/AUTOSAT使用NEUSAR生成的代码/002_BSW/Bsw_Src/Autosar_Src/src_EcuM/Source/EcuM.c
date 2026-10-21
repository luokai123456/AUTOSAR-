/*
********************************************************************************
*
* File name: EcuM.c
*
* Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: yong.zhang/2019.11.26
* Change: New created.
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: yong.zhang/2020.03.27
* Change: 1.Add function EcuM_GetVersionInfo.
* Cause: Update to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date: yong.zhang/2020.03.31
* Change: 1.Delete magic number. 2.QAC modify. 3.delete check timeout.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: yong.zhang/2020.05.18
* Change: 1.Delete SchM_Deinit.2.Add EcuM_McuSetMode.3.Add BswM_EcuM_CurrentWakeup.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: yong.zhang/2020.05.19
* Change: 1.Add EcuM_GoHalt handle.2.Add EcuM_GoPoll.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: yong.zhang/2020.07.20
* Change: 1.Bug fix:NEUSCCORE-378,NEUSCCORE-379,NEUSCCORE-380,NEUSCCORE-381,NEUSCCORE-382.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: yong.zhang/2020.08.25
* Change: 1.EcuM_PendingWakeups shuld be set to wakeup source.
* Cause: BugFix
********************************************************************************
* Version: 3.5
* Author/Date: fangtao/2020.09.15
* Change: Modify the function name according to the AUTOSAR specification, add
*         MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: guoziyang/2020.11.18
* Change: Modify compilation warning.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: guoziyang/2021.6.30
* Change: Modify code according to Autosar specification.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: guoziyang/2021.6.30
* Change: Add Conditional compile switch. (before EcuM_GoHalt)
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: guoziyang/2021.6.30
* Change: Supplement the function of EcuM_GoHalt and EcuM_GoPoll.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: guoziyang/2021.6.30
* Change: Supplement the function of EcuM_Init.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: guoziyang/2021.6.30
* Change: Change position of comChannelRef in EcuM_ValidateWakeupEvent.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: guoziyang/2021.8.8
* Change: Add verification timeout in EcuM_SetWakeupEvent.
* Cause: Bugfix
********************************************************************************
* Version: 3.13
* Author/Date: guoziyang/2021.8.12
* Change: Impose restrictions on EcuM_Shutdown.
* Cause: Bugfix
********************************************************************************
* Version: 3.14
* Author/Date: GuoZY/2021.8.16
* Change: Modify code according to Autosar specification.
* Cause: Optimization
********************************************************************************
* Version: 3.15
* Author/Date: GuoZY/2021.8.20
* Change: Add conditional compilation.
* Cause: Optimization
********************************************************************************
* Version: 3.16
* Author/Date: GuoZY/2021.9.1
* Change: Modify compilation warning.
* Cause: Optimization
********************************************************************************
* Version: 3.17
* Author/Date: GuoZY/2021.12.10
* Change: Add conditional compilation for Mcu.h.
* Cause: Optimization
********************************************************************************
* Version: 3.18
* Author/Date: GuoZY/2021.12.10
* Change: Delete Mcu.h.
* Cause: Optimization
********************************************************************************
* Version: 3.19
* Author/Date: GuoZY/2021.12.13
* Change: Optimize Os header file inclusion.
* Cause: Optimization
********************************************************************************
* Version: 3.20
* Author/Date: GuoZY/2022.1.21
* Change: Delete erroId in function EcuM_GoHalt.
* Cause: Bugfix
********************************************************************************
* Version: 3.21
* Author/Date: GuoZY/2022.5.5
* Change: Delete DisableAllInterrupts() in function EcuM_GoHalt and EcuM_GoPoll.
* Cause: Bugfix
********************************************************************************
* Version: 3.22
* Author/Date: HeHao/2022.06.16
* Change: 1. Add a compile switch for variable EcuM_EnabledWakeups.
*         2. Add compile switches for errorID and loopIndex in function EcuM_GoDown
*         to avoid compile warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.23
* Author/Date: HeHao/2022.06.20
* Change: Merge from Branch_21Q2.
* Cause: Optimization
********************************************************************************
* Version: 3.24
* Author/Date: WangXG/2022.09.22
* Change: Append ECUM supports processing that supports multi-core synchronization.
* Cause: Optimization
********************************************************************************
* Version: 3.25
* Author/Date: WangXG/2022.09.26
* Change: Modify a compile switch for variable EcuM_EnabledWakeups.
* Cause: Optimization
********************************************************************************
* Version: 3.26
* Author/Date: WangXG/2022.10.19
* Change: Use the macro switch to determine whether the header file "ComM.h" is included.
* Cause: Optimization
********************************************************************************
* Version: 3.27
* Author/Date: WangXG/2022.11.3
* Change: 1. Adjust GetResource call location.
          2. delete poll sequence.
* Cause: bugfix
********************************************************************************
* Version: 3.28
* Author/Date: WangXG/2022.11.9
* Change: Append Type Definition.
* Cause: bugfix
********************************************************************************
* Version: 3.29
* Author/Date: WangXG/2022.11.18
* Change: Modify static code analysis warning.
* Cause: static code analysis.
********************************************************************************
* Version: 3.30
* Author/Date: WangXG/2022.12.26
* Change: Append precompiled macro.
* Cause: update
********************************************************************************
* Version: 3.31
* Author/Date: WangXG/2022.12.29
* Change: Append precompiled macro.
* Cause: update
********************************************************************************
* Version: 3.32
* Author/Date: HeHao/2023.06.22
* Change: Fix some variables/macros that do not compliance with the code style
*         regulations.
* Cause: Optimization
********************************************************************************
* Version: 3.33
* Author/Date: HeHao/2023.07.10
* Change: Fix compiler error.
* Cause: Optimization
********************************************************************************
* Version: 3.34
* Author/Date: HeHao/2023.09.05
* Change: 1. Support shutdown target ECUM_SHUTDOWN_TARGET_RESET in EcuM_GoDown.
*         2. Minor changes on coding style.
* Cause: Bugfix
********************************************************************************
* Version: 3.35
* Author/Date: HeHao/2023.09.27
* Change: 1. Clear compiler warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.36
* Author/Date: HeHao/2023.10.25
* Change: 1. Clear compiler warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.37
* Author/Date: HeHao/2023.12.25
* Change: Bugfix for CCOREDBUG-4212 and CCOREDBUG-4236:
*         1. Change wakeup status indication to BswM to one bit a time because
*         BswM can only accept one wakeup source within each mode request call.
*         Impact on: EcuM_GoSleepSequence, EcuM_GoHalt, EcuM_ClearWakeupEvent.
*         2. Add coreId reference for wakeup source configurations so that each
*         EcuM instance can process its own wakeup sources validation timeout.
*         Impact on: EcuM_MainFunction.
*         3. Fix internal wakeup source status variables inconsistency problem:
*         Keep EcuM_ValidatedWakeups, EcuM_ExpiredWakeups and EcuM_PendingWakeups
*         status updated: The same wakeup source bit should only be set in one
*         of the status variables and the correspond bit in other two variables
*         should be cleared accordingly.
*         Impact on: EcuM_SetWakeupEvent, EcuM_ValidateWakeupEvent,
*         EcuM_ClearWakeupEvent, EcuM_MainFunction.
*         4. Stop validation timer in EcuM_ValidatedWakeups due to
*         SWS_EcuM_02710.
* Cause: Bugfix
********************************************************************************
* Version: 3.38
* Author/Date: HeHao/2024.01.15
* Change: Update for PB-202:
*         1. Call SchM_Deinit() in OffPreOS Sequence.
*         2. Check pending wakeup events before shutdown the OS.
*         3. Add some comments.
* Cause: Optimization
********************************************************************************
* Version: 3.39
* Author/Date: HeHao/2024.02.20
* Change: Bugfix for CCOREDBUG-4364:
*         1. Change some cross-core accessible variables which are used for
*            Master Core - Slave Core signalling to volatile.
*         2. Add a new function EcuM_LocalVariablesInit to initialize variables
*            that're placed in the NO_INIT memory section.
*         3. Remove calling of EcuM_ClearEvent in the EcuM_GoDown of the master
*            EcuM routine to prevent the race condition from happening that may
*            lead to repeatedly EcuM_GoDown process of the slave EcuM instances.
*         4. Add some comments.
* Cause: Bugfix
********************************************************************************
* Version: 3.40
* Author/Date: HeHao/2024.02.27
* Change: Bugfix for CCOREDBUG-4364:
*         Remove code to clear EcuM_PendingWakeups in EcuM_LocalVariablesInit.
* Cause: Bugfix
********************************************************************************
* Version: 3.41
* Author/Date: HeHao/2024.03.11
* Change: 1. Clear compiler warnings.
*         2. Modify comments.
* Cause: Optimization
********************************************************************************
* Version: 3.42
* Author/Date: HeHao/2024.04.02
* Change: Modify comments.
* Cause: Optimization
********************************************************************************
* Version: 3.43
* Author/Date: TianL/2024.05.15
* Change: 1. Add a MemMap paragraph definition to the function declaration.
*         2. Modify coding specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.44
* Author/Date: TianL/2024.8.5
* Change: 1. Modify EcuM shutdown process，master core shutdown should after slave
*            core shutdown.
*         2. Modify copyright.
* Cause: Optimization
********************************************************************************
* Version: 3.45
* Author/Date: TianL/2024.8.30
* Change: Modify the conditions of waiting for slave core shutdown in EcuM_GoDown.
* Cause: Bugfix
********************************************************************************
* Version: 3.46
* Author/Date: TianL/2024.9.19
* Change: Modify the MemMap of the global variable.
* Cause: Bugfix
********************************************************************************
* Version: 3.47
* Author/Date: TianL/2024.9.30
* Change: Modify the MemMap of the global variable.
* Cause: Bugfix
********************************************************************************
* Version: 3.48
* Author/Date: TianL/2024.10.11
* Change: Modify the MemMap of the global variable.
* Cause: Bugfix
********************************************************************************
* Version: 3.49
* Author/Date: TianL/2025.3.7
* Change: Allow Slave Core to Notify Master Core ShutDown in EcuM_GoDown.
* Cause: Optimization
********************************************************************************
* Version: 3.50
* Author/Date: TianL/2025.3.27
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 3.51
* Author/Date: TianL/2025.6.16
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.52
* Author/Date: TianL/2025.6.23
* Change: Modify the MemMap of the global variable.
* Cause: Bugfix
********************************************************************************
* Version: 3.53
* Author/Date: TianL/2025.6.24
* Change: Modify the macro name of the EcuM_ShutdownTargetType.
* Cause: Bugfix
********************************************************************************
* Version: 3.54
* Author/Date: TianL/2025.7.17
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "EcuM.h"
#include "BswM.h"
#include "EcuM_Cbk.h"
#include "BswM_EcuM.h"
#include "WdgM.h"

#if( ECUM_WAKEUP_SOURCE_LIST > ECUM_ZERO )
#include "ComM.h"
#endif  /* ECUM_WAKEUP_SOURCE_LIST > ECUM_ZERO */
#include "Rte_Main.h"   /* for deinit SchM */

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/* Development Error Detection */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define ECUM_REPORT_DEV_ERROR(SID, ERROR)     \
        ((void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, (SID), (ERROR)))

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
#define ECUM_START_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static VAR(uint8, ECUM_VAR_INIT) EcuM_ModuleState = ECUM_MOUDLE_STATE_UINIT;

#define ECUM_STOP_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#define ECUM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

static FUNC(void, ECUM_CODE) EcuM_LocalVariablesInit(void);
#if( ECUM_WAKEUP_SOURCE_LIST > ECUM_ZERO )
static FUNC(uint8, ECUM_CODE) EcuM_GetShiftCount(EcuM_WakeupSourceType wakeupSource);
#endif  /* ECUM_WAKEUP_SOURCE_LIST > ECUM_ZERO */
static FUNC(void, ECUM_CODE) EcuM_IndicateWakeupStatusToBswM
(
    EcuM_WakeupSourceType wakeupSources,
    EcuM_WakeupStatusType wakeupStatus
);

#define ECUM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define ECUM_START_SEC_GLOBAL_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static VAR(EcuM_StateType, ECUM_VAR_NO_INIT) EcuM_CurrentShutdownTarget;
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static VAR(EcuM_StateType, ECUM_VAR_NO_INIT) EcuM_LastShutdownTarget;
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static VAR(uint8, ECUM_VAR_NO_INIT) EcuM_CurrentShutdownMode;
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static VAR(uint8, ECUM_VAR_NO_INIT) EcuM_LastShutdownMode;
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static VAR(EcuM_ShutdownCauseType, ECUM_VAR_NO_INIT) EcuM_ShutdownCause;
#if( ( ECUM_SLEEP_MODE_COUNT > ECUM_ZERO ) && (ECUM_NORMAL_MCU_MODEREF != ECUM_FF) )
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static VAR(EcuM_WakeupSourceType, ECUM_VAR_NO_INIT) EcuM_EnabledWakeups;
#endif  /* ( ECUM_SLEEP_MODE_COUNT > ECUM_ZERO ) && (ECUM_NORMAL_MCU_MODEREF != ECUM_FF) */

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
VAR(EcuM_WakeupSourceType, ECUM_VAR_NO_INIT) EcuM_PendingCheckWakeups;
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UnusedVariable" polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
VAR(EcuM_WakeupSourceType, ECUM_VAR_NO_INIT) EcuM_ClearedPendingWakeups;
/* Internal pending, validated and expired bit variables. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
VAR(EcuM_WakeupSourceType, ECUM_VAR_NO_INIT) EcuM_ValidatedWakeups;
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
VAR(EcuM_WakeupSourceType, ECUM_VAR_NO_INIT) EcuM_ExpiredWakeups;
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
VAR(EcuM_WakeupSourceType, ECUM_VAR_NO_INIT) EcuM_PendingWakeups;
#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
VAR(uint8, ECUM_VAR_NO_INIT) EcuM_AllCoreSyncSignal;
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
VAR(uint16, ECUM_VAR_NO_INIT) EcuM_AllCoreSyncGodownCaller;
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
VAR(uint8, ECUM_VAR_NO_INIT) EcuM_SyncEventTbl[ECUM_ALLCORE_SYNC_MAX];
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */

#define ECUM_STOP_SEC_GLOBAL_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define ECUM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
* Function Name: EcuM_LocalVariablesInit
*
* Explanation: Initialize local variables to their default values. This function
*              shall only be called by the master core in a multi-core platform.
*
* param: none.
*
* retval: none.
********************************************************************************
*/
static FUNC(void, ECUM_CODE) EcuM_LocalVariablesInit(void)
{
    /* Comments:
       1. The following variables shall not be intialized with default values:
       EcuM_CurrentShutdownTarget, EcuM_LastShutdownTarget,
       EcuM_CurrentShutdownMode, EcuM_LastShutdownMode, EcuM_ShutdownCause.
       2. The following variables are TBD, for now they're not cleared:
       EcuM_PendingCheckWakeups, EcuM_ClearedPendingWakeups, EcuM_EnabledWakeups,
       EcuM_PendingWakeups.
       3. Clear internal validated and expired events variables. */
    EcuM_ValidatedWakeups = (EcuM_WakeupSourceType)ECUM_ZERO;
    EcuM_ExpiredWakeups = (EcuM_WakeupSourceType)ECUM_ZERO;

#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
    /* Clear Master Core - Slave Core signalling variables. */
    EcuM_AllCoreSyncSignal = ECUM_ZERO;     /* No go down or go halt request. */
    EcuM_AllCoreSyncGodownCaller = ECUM_ZERO;  /* Set default go down caller. */
    EcuM_SyncEventTbl[ECUM_ALLCORESHUTDOWN_EVENT] = ECUM_ZERO;  /* No event. */
    EcuM_SyncEventTbl[ECUM_ALLCORESLEEP_EVENT] = ECUM_ZERO;     /* No event. */
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */

    return;
}

#if( ECUM_WAKEUP_SOURCE_LIST > ECUM_ZERO )
/*
********************************************************************************
* Function Name: EcuM_GetShiftCount
*
* Explanation: Get shift count of wakeup sources
*
* param: wakeupSource: The wakeup source(s) defined in the wakeupSource bitfield
*
* retval: uint8: The shift count of wakeup sources
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(uint8, ECUM_CODE) EcuM_GetShiftCount(EcuM_WakeupSourceType wakeupSource)
{
    uint8 retVal = ECUM_ZERO;

    /* polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
    wakeupSource = wakeupSource - (EcuM_WakeupSourceType) ECUM_ONE;
    while( (wakeupSource & ECUM_ONE) != ECUM_ZERO )
    {
        retVal++;
        /* Shift the offset in single steps till the Offset and wakeupSource are equal */
        /* polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
        wakeupSource >>= ECUM_ONE;
    }
    /* Returns the Index of the wakeup source */
    return retVal;
}
#endif  /* ECUM_WAKEUP_SOURCE_LIST > ECUM_ZERO */

/*
********************************************************************************
* Function Name: EcuM_IndicateWakeupStatusToBswM
*
* Explanation: This function tests each bit of wakeupSources that're set,
*              and indicate wakeupStatus to BswM one bit(a wakeup source) a time.
*
* param: wakeupSource: The wakeup source(s) defined in the wakeupSource bitfield.
*        wakeupStatus: Wakeup sources's status that's indicated to BswM.
*
* retval: none.
********************************************************************************
*/
static FUNC(void, ECUM_CODE) EcuM_IndicateWakeupStatusToBswM
(
    EcuM_WakeupSourceType wakeupSources,
    EcuM_WakeupStatusType wakeupStatus
)
{
    uint8 index = ECUM_ZERO;
    EcuM_WakeupSourceType testBit = ECUM_ONE;  /* Start from bit 0. */

    /* Check for all bits of [wakeupSources] that are set and notify BswM
       one by one. */
    for( index = ECUM_ZERO; index < ECUM_WAKEUP_SOURCE_LIST; index++ )
    {
        /* Test if the corresponding bit in wakeupSources is set. */
        if( (wakeupSources & testBit) == testBit )
        {
            /* Indicate BswM with only one bit set at a time. */
            BswM_EcuM_CurrentWakeup(testBit, wakeupStatus);
        }

        /* Move left for masking next bit. */
        testBit = testBit << ECUM_ONE;
    }

    return;
}

/*
********************************************************************************
* Function Name: EcuM_GoDown
*
* Explanation: Instructs the ECU State Manager module to perform a power off or
*          a reset depending on the selected shutdown target.(Synchronous & Reentrant)
*
* param: caller: Module ID of the calling module. Only special modules are allowed
*                to call this function.
*
* retval: E_NOT_OK: The shutdown request was not accepted.
*         E_OK: This cannot occur because if the request was accepted,this call will not return.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoDown(uint16 caller)
{
#if( ECUM_GODOWN_ALLOWED_USER > ECUM_ZERO )
    uint8 loopIndex = ECUM_ZERO;
#endif  /* ECUM_GODOWN_ALLOWED_USER > ECUM_ZERO */

#if( ECUM_GODOWN_ALLOWED_USER > ECUM_ZERO )
#if( ECUM_DEV_ERROR_REPORT == STD_ON )
    uint8 errorID = ECUM_E_NO_ERROR;
#endif  /* ECUM_DEV_ERROR_REPORT == STD_ON */
#endif  /* ECUM_GODOWN_ALLOWED_USER > ECUM_ZERO */

    /* Used to read out the pending wakeup event before shutdown. */
    EcuM_WakeupSourceType pendingWakeupEvents = ECUM_ZERO;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_EcuM_UNMODIFIED_VAR_NOT_CONST" */
    Std_ReturnType retVal = E_NOT_OK;

#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    CoreIdType CoreID;
    CoreID = GetCoreID();

    /* polyspace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.4" */
    if( ECUM_CORE_ID_MASTER == (uint8)CoreID )  /* PRQA S 1881 */ /* NSCA_QAC_ComM_Rule10.4 */
    {
        /* Check if master core has finished process GoDown request. */
        if( E_OK != EcuM_GetEvent(ECUM_ALLCORESHUTDOWN_EVENT, CoreID) )
        {
            /* Multi-core use-case:
               notify slave core to shutdown and wait until they're ready. */
            ECUM_NOTIFY_SLAVE_SHUTDOWN();
            EcuM_AllCoreSyncGodownCaller = caller;
            /* Mark master core is ready to shutdown. */
            EcuM_SetEvent(ECUM_ALLCORESHUTDOWN_EVENT, CoreID);
        }
        else
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */
        {
            /* Master Core continues, check: Parameter validation. */
#if( ECUM_GODOWN_ALLOWED_USER > ECUM_ZERO )
            for( ; loopIndex < ECUM_GODOWN_ALLOWED_USER; loopIndex++ )
            {
                if( EcuM_GoDownAllowedUser[loopIndex] == caller )
                {
                    retVal = E_OK;
                    break;
                }
            }
            /* Not find this user. */
            if( retVal != E_OK )
            {
#if( ECUM_DEV_ERROR_REPORT == STD_ON )
                errorID = ECUM_E_INVALID_PAR;
#endif  /* ECUM_DEV_ERROR_REPORT == STD_ON */
            }
            else
            {
#else  /* ECUM_GODOWN_ALLOWED_USER > ECUM_ZERO */
                /* ECUM_GODOWN_ALLOWED_USER is 0, in-param caller is not used. */
                ECUM_DUMMY_STATEMENT(caller);
#endif  /* ECUM_GODOWN_ALLOWED_USER > ECUM_ZERO */
#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
                if( E_OK == EcuM_WaitEvent(ECUM_ALLCORESHUTDOWN_EVENT) )
                {
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */
                    /* The following steps refer to:
                    Multi-core:  Figure 24 - Master Core OffPreOS Sequence.
                    Single-core: Figure 9 - OffPreOS Sequence. */
                    EcuM_OnGoOffOne();  /* Invokes EcuM_OnGoOffOne on entry to the OffPreOS Sequence. */
                    /* De-init BSW Mode Manager. */
                    BswM_Deinit();
                    /* De-init Schedule Manager. */
                    SchM_Deinit();  /* SchM_Deinit shall be called before shut down of BSW. */

                    /* Check for pending wakeup events. */
                    pendingWakeupEvents = EcuM_GetPendingWakeupEvents();
                    /* Integration note: The clearing of wakeup sources shall take place
                    during ECU shutdown prior to the call of Dem_Shutdown() and
                    NvM_WriteAll(). This can be achieved by configuring BswMRules in
                    the BswM module containing BswMActions of type BswMUserCallout
                    with their BswMUserCalloutFunction parameter set to
                    "EcuM_ClearWakeupEvent(<sources>)". */
                    if( ECUM_ZERO != pendingWakeupEvents )
                    {
                        /* SWS_EcuM_03021 Set RESET as shutdown target, if wakeup events are pending.
                        Default reset mode of EcuMDefaultResetModeRef will be used. */
                        (void)EcuM_SelectShutdownTarget(ECUM_SHUTDOWN_TARGET_RESET, ECUM_DEFAULT_RESET_MODEREF);
                    }
                    /* Shutdown OS. */
                    if( (ECUM_SHUTDOWN_TARGET_OFF == EcuM_CurrentShutdownTarget) ||
                        (ECUM_SHUTDOWN_TARGET_RESET == EcuM_CurrentShutdownTarget) )
                    {
                        /* Single-core use-case:
                        Call ShutdownAllCores without waiting for slave cores. */
                        EcuM_ShutdownOS(E_OK);
                    }
#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
                }
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */
#if( ECUM_GODOWN_ALLOWED_USER > ECUM_ZERO )
            }
#endif  /* ECUM_GODOWN_ALLOWED_USER > ECUM_ZERO */
        }
#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
    }  /* (CoreID == ECUM_CORE_ID_MASTER) */
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */

#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
    else
    {
        /* Slave core process GoDown. */
        if( E_NOT_OK == EcuM_GetEvent(ECUM_ALLCORESHUTDOWN_EVENT, CoreID) )
        {
            /* Refer to Figure 26 - Slave Core OffPreOS Sequence */
            EcuM_OnGoOffOne();  /* Invokes callout. */
            /* De-init BSW Mode Manager. */
            BswM_Deinit();
            /* De-init Schedule Manager. */
            SchM_Deinit();
            /* SetEvent to notify master core. */
            EcuM_SetEvent(ECUM_ALLCORESHUTDOWN_EVENT, CoreID);
#if( ECUM_8BIT_INVALID_VALUE != ECUM_SLAVE_CORE_NOTIFY_SHUTDOWN )
            if( (ECUM_SHUTDOWN_TARGET_OFF == EcuM_CurrentShutdownTarget) ||
                (ECUM_SHUTDOWN_TARGET_RESET == EcuM_CurrentShutdownTarget) )
            {
                /* Allow Slave Core Notify Master Core ShutDown. */
                if( ECUM_SLAVE_CORE_NOTIFY_SHUTDOWN == (uint8)CoreID )
                {
                    EcuM_AllCoreSyncGodownCaller = caller;//修复从核无法下电的问题
                    /* Notify Master Core ShutDown. */
                    ECUM_NOTIFY_SLAVE_SHUTDOWN();
                }
            }
#endif
        }
        else
        {
            /* Do nothing but notify master core. */
            EcuM_SetEvent(ECUM_ALLCORESHUTDOWN_EVENT, CoreID);
        }
    }
#endif  /* ( ECUM_NUMBER_OF_CORES > ECUM_ONE ) */

    /* Report error to Det. */
#if( ECUM_GODOWN_ALLOWED_USER > ECUM_ZERO )
#if( ECUM_DEV_ERROR_REPORT == STD_ON )
    if( errorID != ECUM_E_NO_ERROR )
    {
        EcuM_Det_ReportError(ECUM_SID_GO_DOWN, errorID);
    }
#endif  /* ECUM_DEV_ERROR_REPORT == STD_ON */
#endif  /* ECUM_GODOWN_ALLOWED_USER > ECUM_ZERO */

    return retVal;
}

#if( (ECUM_SLEEP_MODE_COUNT > ECUM_ZERO) && (ECUM_NORMAL_MCU_MODEREF != ECUM_FF) )
/*
********************************************************************************
* Function Name: EcuM_GoSleepSequence
*
* Explanation: In the GoSleep sequence the ECU Manager module configures hardware for the
*              upcoming sleep phase and sets the ECU up for the next wakeup event.
*
* param: SleepType : sleep type.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, ECUM_CODE) EcuM_GoSleepSequence(uint8 SleepType)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    CoreIdType CoreID;
    CoreID = GetCoreID();

    EcuM_EnabledWakeups = Ecum_SleepMode[EcuM_CurrentShutdownMode].wakeupSourceMask;

    /* Indicate enabled wakeup sources status to BswM, note BswM can only accept
       one wake source a time. EcuM_IndicateWakeupStatusToBswM will test each bit
       of EcuM_EnabledWakeups and send one set bit a time to BswM. */
    EcuM_IndicateWakeupStatusToBswM(EcuM_EnabledWakeups, ECUM_WKSTATUS_ENABLED);

    /* SWS_EcuM_02389 */
    EcuM_EnableWakeupSources(EcuM_EnabledWakeups);

#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
    /* polyspace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.4" */
    if( ECUM_CORE_ID_MASTER == (uint8)CoreID )  /* PRQA S 1881 */ /* NSCA_QAC_ComM_Rule10.4 */
    {
        if( ECUM_ALLCORE_GOHALT == SleepType )
        {
            ECUM_NOTIFY_SLAVE_GOHALT();
            EcuM_SetEvent(ECUM_ALLCORESLEEP_EVENT, CoreID);
        }
        else
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            /* Do nothing. */
        }
    }
    else  /* Slave handle */
    {
        EcuM_SetEvent(ECUM_ALLCORESLEEP_EVENT, CoreID);
    }
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */
}
/*
********************************************************************************
* Function Name: EcuM_GoHalt
*
* Explanation: Instructs the ECU State Manager module to go into a sleep mode where the
*              microcontroller is halted, depending on the selected shutdown target.
*              (Synchronous & Reentrant)
*
* param: None
*
* retval: E_NOT_OK: The request was not accepted, e.g. due to a wrong shutdown target.
*         E_OK: If the call successfully returns, the ECU has left the sleep again.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoHalt(void)
{
    Std_ReturnType retVal = E_NOT_OK;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    CoreIdType CoreID;
    CoreID = GetCoreID();
    /* Check current shutdown target, only in sleep, can invoke this function. */
    if( ECUM_SHUTDOWN_TARGET_SLEEP == EcuM_CurrentShutdownTarget )
    {
        /* [SWS_EcuM_02863] The ECU Manager module shall invoke the EcuM_GenerateRamHash. */
#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
        if( E_NOT_OK == EcuM_GetEvent(ECUM_ALLCORESLEEP_EVENT, CoreID) )
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */
        {
            EcuM_GenerateRamHash();
            EcuM_GoSleepSequence(ECUM_ALLCORE_GOHALT);
            /* set LastShutdownTarget and LastShutdownMode. */
#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
            /* polyspace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.4" */
            if( ECUM_CORE_ID_MASTER == (uint8)CoreID )  /* PRQA S 1881 */ /* NSCA_QAC_ComM_Rule10.4 */
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */
            {
                EcuM_LastShutdownTarget = EcuM_CurrentShutdownTarget;
                EcuM_LastShutdownMode = EcuM_CurrentShutdownMode;
                if( ECUM_WKSOURCE_NONE == EcuM_PendingWakeups )
                {
                    EcuM_ValidatedWakeups = ECUM_WKSOURCE_NONE;
                }
            }
        }
        /* else means this core has already finished GoSleepSequence. */

#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
        /* All cores are ready to go halt. */
        if( E_OK == EcuM_WaitEvent(ECUM_ALLCORESLEEP_EVENT) )
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */
        {
            while( ECUM_WKSOURCE_NONE == ( (EcuM_PendingWakeups | EcuM_PendingCheckWakeups) | EcuM_ValidatedWakeups ) )
            {
                /* Halt task scheduling on this core. */
                /* polyspace +1 MISRA-C3:10.5 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.5" polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                (void)GetResource((ResourceType)EcuM_GetResourceInCore(CoreID));  /* PRQA S 4424, 4342 */ /* NSCA_QAC_EcuM_Rule10.3, NSCA_QAC_EcuM_Rule10.5 */
                DisableAllInterrupts();

                retVal = E_OK;

                /* polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_EcuM_Rule14.3" polyspace +1 DEFECT:USELESS_IF [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                if( ECUM_FF != Ecum_SleepMode[EcuM_CurrentShutdownMode].sleepModeMcuModeRef )
                {
                    /* Set the McuMode for the current sleep phase. */
                    /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                    EcuM_McuSetMode(Ecum_SleepMode[EcuM_CurrentShutdownMode].sleepModeMcuModeRef);  /* PRQA S 4442 */ /* NSCA_QAC_EcuM_Rule10.3 */
                }
            }

            /* The following is SWS_EcuM_02963 WakeupRestart sequence. */
            EnableAllInterrupts();

            /* polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_EcuM_Rule14.3" polyspace +1 DEFECT:USELESS_IF [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if ( ECUM_ZERO == EcuM_CheckRamHash() )
            {
                /* The hash verification function is not implemented */
                /* To do EcuM_ErrorHook()*/
            }

#if( ECUM_VALIDATION_TIMEOUT == STD_ON )
            if( ECUM_ZERO == EcuM_ValidatedWakeups )
            {
                /* There could be multiple bits set in EcuM_PendingWakeups. */
                EcuM_IndicateWakeupStatusToBswM(EcuM_PendingWakeups, ECUM_WKSTATUS_PENDING);
            }
            else
            {
                /* There could be multiple bits set in EcuM_ValidatedWakeups. */
                EcuM_IndicateWakeupStatusToBswM(EcuM_ValidatedWakeups, ECUM_WKSTATUS_VALIDATED);
            }
#endif  /* ECUM_VALIDATION_TIMEOUT == STD_ON */
            EcuM_DisableWakeupSources(EcuM_EnabledWakeups);

            /* Set the McuMode to the normal mode.*/
#if( ECUM_NORMAL_MCU_MODEREF != ECUM_INVALID )
            /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
            EcuM_McuSetMode(ECUM_NORMAL_MCU_MODEREF);  /* PRQA S 1297 */ /* NSCA_QAC_EcuM_Rule10.3 */
#endif  /* ECUM_NORMAL_MCU_MODEREF != ECUM_INVALID */

#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
            /* polyspace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.4" */
            if( ECUM_CORE_ID_MASTER == (uint8)CoreID )  /* PRQA S 1881 */ /* NSCA_QAC_EcuM_Rule10.4 */
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */
            {
                /* Initialize drivers that need restarting. */
                EcuM_AL_DriverRestart(&EcuM_Config);  /* on the "master" EcuM only. */
            }

            /* Unlock the scheduler to continue task scheduling. */
            /* polyspace +1 MISRA-C3:10.5 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.5" polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
            (void)ReleaseResource((ResourceType)EcuM_GetResourceInCore(CoreID));  /* PRQA S 4424, 4342 */ /* NSCA_QAC_EcuM_Rule10.3, NSCA_QAC_EcuM_Rule10.5 */

#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
            EcuM_ClearEvent(ECUM_ALLCORESLEEP_EVENT);
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */
            /* End of WakeupRestart sequence. The ECU Manager module will have
               a list of pending wakeup events to be validated in EcuM_MainFunction. */
        }
        /* else keep waiting until all cores are ready to go halt. */
    }
    else
    {
        retVal = E_NOT_OK;
    }
    return retVal;
}

/*
********************************************************************************
* Function Name: EcuM_GoPoll
*
* Explanation: Instructs the ECU State Manager module to go into a polling sleep mode
*              depending on the selected shutdown target.(Synchronous & Reentrant)
*
* param: None
*
* retval: E_NOT_OK: The request was not accepted, e.g. due to a wrong shutdown target.
*         E_OK: If the call successfully returns, the ECU has left the sleep again.
********************************************************************************
*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoPoll(void)
{
    /* not support */
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_EcuM_UNMODIFIED_VAR_NOT_CONST" */
    Std_ReturnType retval = E_OK;
    return retval;
}
#endif  /* (ECUM_SLEEP_MODE_COUNT > ECUM_ZERO) && (ECUM_NORMAL_MCU_MODEREF != ECUM_FF) */

/*
********************************************************************************
* Function Name: EcuM_Init
*
* Explanation: Initializes the ECU state manager and carries out the startup procedure.
*             The function will never return (it calls StartOS)(Synchronous & Reentrant)
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, ECUM_CODE) EcuM_Init(void)
{
#if( ECUM_RESET_REASON_REF == STD_ON )
    Mcu_ResetType mcuResetType;
#endif  /* ECUM_RESET_REASON_REF == STD_ON */

#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_EcuM_UNMODIFIED_VAR_NOT_CONST" polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    CoreIdType coreID = GetCoreID();
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */

    uint32 loopIndex = ECUM_ZERO;

#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
    /* polyspace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.4" */
    if( ECUM_CORE_ID_MASTER == (uint8)coreID )  /* PRQA S 1881 */ /* NSCA_QAC_EcuM_Rule10.4 */
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */
    {
        /* Initialize local variables to their default values. */
        EcuM_LocalVariablesInit();
        /* Set the interrupts on ECUs with programmable interrupts. */
        EcuM_AL_SetProgrammableInterrupts();
        /* Initialize BSW modules that do not use post-build configuration parameters. */
        EcuM_AL_DriverInitZero();
        /* return a pointer to a fully initialized EcuM_ConfigType structure. */
#if( ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON )
        EcuM_DeterminePbConfiguration();
#endif  /* ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON*/

        /* The callout may not only contain driver initialization but any kind of pre-OS, low level initialization code. */
        EcuM_AL_DriverInitOne(&EcuM_Config);

#if( ECUM_RESET_REASON_REF == STD_ON )
        /* Get reset reason. */
        mcuResetType = Mcu_GetResetReason();

        for( loopIndex = ECUM_ZERO; loopIndex < ECUM_WAKEUP_SOURCE_LIST; loopIndex++ )
        {
            if( EcuM_WakeupSourceList[loopIndex].resetReasonRef == mcuResetType )
            {
                /* Set this wakeup source as a validated wakeup event. */
                EcuM_ValidatedWakeups |= (EcuM_WakeupSourceType)(ECUM_ONE << loopIndex);
                break;
            }
        }
#else  /* ECUM_RESET_REASON_REF == STD_ON */
        EcuM_ValidatedWakeups |= ECUM_WKSOURCE_RESET;
#endif  /* ECUM_RESET_REASON_REF == STD_ON */

#if( ECUM_WAKEUP_SOURCE_LIST > ECUM_ZERO )
        /* Init EcuM_ValidationTimeoutArray. */
        for( loopIndex = ECUM_ZERO; loopIndex < ECUM_WAKEUP_SOURCE_LIST; loopIndex++ )
        {
            EcuM_ValidationTimeoutArray[loopIndex] = ECUM_ZERO;
        }
#endif  /* ECUM_WAKEUP_SOURCE_LIST > ECUM_ZERO */
        /* Select default shutdown target. */
        EcuM_CurrentShutdownTarget = (EcuM_StateType)ECUM_DEFAULT_SHUTDOWN_TARGET;
        /* polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_EcuM_Rule14.3" polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
        if( ECUM_SHUTDOWN_TARGET_SLEEP == EcuM_CurrentShutdownTarget )
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            EcuM_CurrentShutdownMode = ECUM_DEFAULT_SLEEP_MODEREF;
        }
        /* polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_EcuM_Rule14.3" polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
        else if( ECUM_SHUTDOWN_TARGET_RESET == EcuM_CurrentShutdownTarget )
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            EcuM_CurrentShutdownMode = ECUM_DEFAULT_RESET_MODEREF;
        }
        else
        {
            EcuM_CurrentShutdownMode = ECUM_ZERO;
        }
        /* If Loop Detection is enabled, this callout is called on every startup. */
#if( ECUM_RESETLOOP_DETECTION == STD_ON )
        {
            (void)EcuM_LoopDetection();
        }
#endif  /* ECUM_RESETLOOP_DETECTION == STD_ON */
        /* Set Module State. */
        EcuM_ModuleState = ECUM_MODULE_STATE_INIT;
    }
#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
    else
    {
        EcuM_AL_DriverInitZero();
#if( ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON )
        EcuM_DeterminePbConfiguration();
#endif  /* ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON */
        EcuM_AL_DriverInitOne(&EcuM_Config);
    }
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */
    /* Start OS */
    EcuM_StartOS(OSDEFAULTAPPMODE);

    ECUM_DUMMY_STATEMENT(loopIndex);  /* Avoid compiler warnings. */

    return;
}

/*
********************************************************************************
* Function Name: EcuM_StartupTwo
*
* Explanation: This function implements the STARTUP II state.(Synchronous & Non-Reentrant)
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, ECUM_CODE) EcuM_StartupTwo(void)
{

#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
    /* polyspace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.4" */
    if ( ECUM_CORE_ID_MASTER == (uint8)GetCoreID() )  /* PRQA S 1881 */ /* NSCA_QAC_EcuM_Rule10.4 */
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */
    {
        /* Master core Handle */
        /* SchM_Start() */
        BswM_Init(NULL_PTR);
        /* SchM_Init(NULL_PTR); */
        /* SchM_StartTiming(NULL_PTR) */
    }
#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
    else
    {
        /* Slave core Handle */
        /* SchM_Start() */
        BswM_Init(NULL_PTR);
        /* SchM_Init(NULL_PTR); */
        /* SchM_StartTiming(NULL_PTR) */
    }
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */
    WdgM_Init(NULL_PTR);
}

/*
********************************************************************************
* Function Name: EcuM_Shutdown
*
* Explanation: Typically called from the shutdown hook, this function takes over
*              execution control and will carry out GO OFF II activities.
*              (Synchronous & Reentrant)
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, ECUM_CODE) EcuM_Shutdown(void)
{
    uint8 errorID = ECUM_E_NO_ERROR;

#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
    /* polyspace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.4" */
    if ( ECUM_CORE_ID_MASTER == (uint8)GetCoreID() )  /* PRQA S 1881 */ /* NSCA_QAC_EcuM_Rule10.4 */
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */
    {
        /* Save the last shutdown target and shutdown mode. */
        EcuM_LastShutdownTarget = EcuM_CurrentShutdownTarget;
        EcuM_LastShutdownMode = EcuM_CurrentShutdownMode;
        /* Execute user defined code before shutdown. */
        EcuM_OnGoOffTwo();
        switch( EcuM_CurrentShutdownTarget )
        {
            case ECUM_SHUTDOWN_TARGET_OFF:
                /* Call EcuM_AL_SwitchOff in case of shutdown Target ECUM_SHUTDOWN_TARGET_OFF. */
                EcuM_AL_SwitchOff();
                break;
            case ECUM_SHUTDOWN_TARGET_RESET:
                /* Call EcuM_AL_Reset in case of shutdown Target ECUM_SHUTDOWN_TARGET_RESET. */
                EcuM_AL_Reset(EcuM_CurrentShutdownMode);
                break;
            default:
                /* Parameter out of range. */
                errorID = ECUM_E_STATE_PAR_OUT_OF_RANGE;
                break;
        }
    }
#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
    else
    {
        EcuM_OnGoOffTwo();
    }
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */
    /* Report error to Det. */
#if( ECUM_DEV_ERROR_REPORT == STD_ON )
    if( errorID != ECUM_E_NO_ERROR )
    {
        EcuM_Det_ReportError(ECUM_SID_SHUTDOWN, errorID);
    }
#else
    ECUM_DUMMY_STATEMENT(errorID);
#endif  /* ECUM_DEV_ERROR_REPORT == STD_ON */
}

/*
********************************************************************************
* Function Name: EcuM_SetWakeupEvent
*
* Explanation: Sets the wakeup event.(Synchronous & Non-Reentrant, Non-Interruptible)
*
* param: sources: Value to be set.
*
* retval: None
********************************************************************************
*/
FUNC(void, ECUM_CODE) EcuM_SetWakeupEvent(EcuM_WakeupSourceType sources)
{
    /* Note: Only one wakeup source(one bit) should be set in in-param sources. */
#if( ECUM_WAKEUP_SOURCE_LIST > ECUM_ZERO )
    uint8 errorID = ECUM_E_NO_ERROR;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_EcuM_UNMODIFIED_VAR_NOT_CONST" */
    uint8 Shiftcount = EcuM_GetShiftCount(sources);

    /* [SWS_EcuM_02867] If DET is turned on and the sources parameter is unknown. */
    /* polyspace +1 DEFECT:BITWISE_ARITH_MIX [Justified:Unset] "NSCA_Polyspace_EcuM_BITWISE_ARITH_MIX" */
    if( ((EcuM_WakeupSourceType)ECUM_ZERO != (sources & (sources - (EcuM_WakeupSourceType)ECUM_ONE) ))
            || (Shiftcount >= ECUM_WAKEUP_SOURCE_LIST))
    {
        errorID = ECUM_E_UNKNOWN_WAKEUP_SOURCE;
    }
    else
    {
        /* If the validation protocol is configured. */
        /* polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_EcuM_Rule14.3" polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
        if( EcuM_WakeupSourceList[Shiftcount].validationTimeout != ECUM_ZERO )
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            /* Set the current source to the pending check wakeup bit mask. */
            EcuM_PendingWakeups |= sources;  /* SWS_EcuM_02709 is fulfilled by mainfunction. */
            /* Clear the corresponding bit in EcuM_ValidatedWakeups and
               EcuM_ExpiredWakeups to maintain wakeup source status consistency. */
            EcuM_ValidatedWakeups &= ~sources;
            EcuM_ExpiredWakeups &= ~sources;

            /* Pending wakeups will be checked in EcuM_Mainfunction,
               and as per SWS_EcuM_02712 : do not restart the wakeup validation
               timeout timer for the same wakeup source. */

            /* Indicate pending wakeup source to BswM as per
               Figure 16 - Wakeup Source States */
            /* Note only one set bit should be passed to BswM. */
            BswM_EcuM_CurrentWakeup(sources, ECUM_WKSTATUS_PENDING);
        }
        else
        {
            /* SWS_EcuM_02566 If the validation protocol is not configured,
               then a call to EcuM_SetWakeupEvent shall also imply a call to
               EcuM_ValidateWakeupEvent */
            EcuM_ValidateWakeupEvent(sources);
        }
    }

    /* Report error to Det. */
#if( ECUM_DEV_ERROR_REPORT == STD_ON )
    if( errorID != ECUM_E_NO_ERROR )
    {
        EcuM_Det_ReportError(ECUM_SID_SET_WAKEUP_EVENT, errorID);
    }
#else
    ECUM_DUMMY_STATEMENT(errorID);
#endif  /* ECUM_DEV_ERROR_REPORT == STD_ON */

#else
    ECUM_DUMMY_STATEMENT(sources);
#endif  /* ECUM_WAKEUP_SOURCE_LIST > ECUM_ZERO */

    return;
}

/*
********************************************************************************
* Function Name: EcuM_ValidateWakeupEvent
*
* Explanation: After wakeup, the ECU State Manager will stop the process during the WAKEUP
*              VALIDATION state/sequence to wait for validation of the wakeup event.This API
*              service is used to indicate to the ECU Manager module that the wakeup events
*              indicated in the sources parameter have been validated.(Synchronous & Reentrant)
*
* param: sources: Events that have been validated
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, ECUM_CODE) EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType sources)
{
    /* Notice: Only one wakeup source(one bit) should be set in parameter sources. */
#if( ECUM_WAKEUP_SOURCE_LIST > ECUM_ZERO )
    uint8 errorID = ECUM_E_NO_ERROR;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_EcuM_UNMODIFIED_VAR_NOT_CONST" */
    uint8 Shiftcount = EcuM_GetShiftCount(sources);

    /* [SWS_EcuM_02868] If DET is turned on and the sources parameter is unknown. */
    /* polyspace +1 DEFECT:BITWISE_ARITH_MIX [Justified:Unset] "NSCA_Polyspace_EcuM_BITWISE_ARITH_MIX" */
    if( ((EcuM_WakeupSourceType)ECUM_ZERO != (sources & (sources - (EcuM_WakeupSourceType)ECUM_ONE) ))
            || (Shiftcount >= ECUM_WAKEUP_SOURCE_LIST))
    {
        errorID = ECUM_E_UNKNOWN_WAKEUP_SOURCE;
    }
    else
    {
        /* Set the wakeup sources as validated wakeup sources */
        EcuM_ValidatedWakeups |= (EcuM_WakeupSourceType)(sources);

        /* Clear the corresponding bit in EcuM_PendingWakeups and EcuM_ExpiredWakeups
           to maintain wakeup source status consistency. */
        EcuM_PendingWakeups &= ~sources;
        EcuM_ExpiredWakeups &= ~sources;

        /* SWS_EcuM_02710 Stop validation timer: EcuM_ValidationTimeoutArray. */
        EcuM_ValidationTimeoutArray[Shiftcount] = ECUM_ZERO;

        /* [SWS_EcuM_04079] EcuMValidateWakeupEvent shall invoke BswM_EcuM_CurrentWakeup with its sources parameter
            and state value ECUM_WKSTATUS_VALIDATED. */
        /* Only one set bit should be passed to BswM. */
        BswM_EcuM_CurrentWakeup(sources, ECUM_WKSTATUS_VALIDATED);

        /* If wakeup source belong to ComM channel, set this wakeup source as validated wakeup source. */
        if(EcuM_WakeupSourceList[Shiftcount].comChannelRef != ECUM_FF )
        {
            /* [SWS_EcuM_02645]  invoke ComM_EcuM_WakeUpIndication for each wakeup event. */
#if( ECUM_WAKEUP_SOURCE_LIST > ECUM_ZERO )
            ComM_EcuM_WakeUpIndication(EcuM_WakeupSourceList[Shiftcount].comChannelRef);
#endif  /* ECUM_WAKEUP_SOURCE_LIST > ECUM_ZERO */
        }
    }
    /* Report error to Det. */
#if( ECUM_DEV_ERROR_REPORT == STD_ON )
    if( errorID != ECUM_E_NO_ERROR )
    {
        EcuM_Det_ReportError(ECUM_SID_VALIDATE_WAKEUP_EVENT, errorID);
    }
#else
        ECUM_DUMMY_STATEMENT(errorID);
#endif  /* ECUM_DEV_ERROR_REPORT == STD_ON */

#else   /* ECUM_WAKEUP_SOURCE_LIST > ECUM_ZERO */
    ECUM_DUMMY_STATEMENT(sources);
#endif  /* ECUM_WAKEUP_SOURCE_LIST > ECUM_ZERO */

}

/*
********************************************************************************
* Function Name: EcuM_SelectShutdownTarget
*
* Explanation: EcuM_SelectShutdownTarget selects the shutdown target.
*              EcuM_SelectShutdownTarget is part of the ECU Manager Module port interface.
*              (Synchronous & Reentrant).
*
* param: shutdownTarget: The selected shutdown target
*        shutdownMode: The identfier of a sleep mode(ECUM_SHUTDOWN_TARGET_SLEEP or ECUM_SHUTDOWN_TARGET_RESET)
*
* retval: E_OK: The new shutdown target was set
*         E_NOT_OK: The new shutdown target was not set
********************************************************************************
*/
/* polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownTarget
(
    EcuM_ShutdownTargetType shutdownTarget,
    EcuM_ShutdownModeType shutdownMode
)
{
    uint8 errorID = ECUM_E_NO_ERROR;
    Std_ReturnType retVal = E_OK;

    /* Parameter validate. */
    if( (shutdownTarget != ECUM_SHUTDOWN_TARGET_SLEEP) && (shutdownTarget != ECUM_SHUTDOWN_TARGET_RESET)
                                            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                                            && (shutdownTarget != ECUM_SHUTDOWN_TARGET_OFF) )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorID = ECUM_E_STATE_PAR_OUT_OF_RANGE;
        retVal = E_NOT_OK;
    }

#if( ECUM_SLEEP_MODE_COUNT > ECUM_ZERO )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    else if( (ECUM_SHUTDOWN_TARGET_SLEEP == shutdownTarget) && (shutdownMode > ECUM_SLEEP_MODE_COUNT) )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorID = ECUM_E_STATE_PAR_OUT_OF_RANGE;
        retVal = E_NOT_OK;
    }
#endif  /* ECUM_SLEEP_MODE_COUNT > ECUM_ZERO */

#if( ECUM_RESET_MODE_COUNT > ECUM_ZERO )
    else if( (ECUM_SHUTDOWN_TARGET_RESET == shutdownTarget) && (shutdownMode > ECUM_RESET_MODE_COUNT) )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorID = ECUM_E_STATE_PAR_OUT_OF_RANGE;
        retVal = E_NOT_OK;
    }
#endif  /* ECUM_RESET_MODE_COUNT > ECUM_ZERO */

    else
    {
        /* Function implementation. */
        /* Set current shutdown target. */
        EcuM_CurrentShutdownTarget = shutdownTarget;
        /* Set current shutdown mode. */
        if( ECUM_SHUTDOWN_TARGET_OFF == shutdownTarget )
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            EcuM_CurrentShutdownMode = ECUM_ZERO;
        }
        else
        {
            /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
            EcuM_CurrentShutdownMode = shutdownMode;  /* PRQA S 4461 */ /* NSCA_QAC_EcuM_Rule10.3 */
        }
        retVal = E_OK;
    }

    /* Report error to Det. */
#if( ECUM_DEV_ERROR_REPORT == STD_ON )
    if( errorID != ECUM_E_NO_ERROR )
    {
        EcuM_Det_ReportError(ECUM_SID_SELECT_SHUTDOWN_TARGET, errorID);
    }
#else
        ECUM_DUMMY_STATEMENT(errorID);
#endif  /* ECUM_DEV_ERROR_REPORT == STD_ON */

    return retVal;
}

/*
********************************************************************************
* Function Name: EcuM_GetShutdownTarget
*
* Explanation: EcuM_GetShutdownTarget returns the currently selected shutdown target as set
*              by EcuM_SelectShutdownTarget.(Synchronous & Reentrant)
*
* param: shutdownTarget : ECUM_SHUTDOWN_TARGET_SLEEP or  ECUM_SHUTDOWN_TARGET_RESET or ECUM_SHUTDOWN_TARGET_OFF
*        shutdownMode : If the out parameter "shutdownTarget" is ECUM_SHUTDOWN_TARGET_SLEEP,
*                           sleepMode tells which of the configured sleep modes was
*                           actually chosen. If "shutdownTarget" is ECUM_SHUTDOWN_TARGET_RESET,
*                           sleepMode tells which of the configured reset modes was actually
*                           chosen.
*
* retval: E_OK: The service has succeeded
*         E_NOT_OK: The service has failed, e.g. due to NULL pointer being passed
********************************************************************************
*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetShutdownTarget
(
    P2VAR(EcuM_ShutdownTargetType, AUTOMATIC, ECUM_APPL_DATA) shutdownTarget,
    P2VAR(EcuM_ShutdownModeType, AUTOMATIC, ECUM_APPL_DATA) shutdownMode
)
{
    uint8 errorID = ECUM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;

    /* Parameter validation. */
    if( (NULL_PTR == shutdownTarget) || (NULL_PTR == shutdownMode) )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorID = ECUM_E_NULL_POINTER;
    }
    else
    {
        /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_EcuM_Dir4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_EcuM_TAINTED_PTR" */
        *shutdownTarget = EcuM_CurrentShutdownTarget;
        /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_EcuM_Dir4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_EcuM_TAINTED_PTR" */
        *shutdownMode = EcuM_CurrentShutdownMode;
        retVal = E_OK;
    }

    /* Report error to Det. */
#if( ECUM_DEV_ERROR_REPORT == STD_ON )
    if( errorID != ECUM_E_NO_ERROR )
    {
        EcuM_Det_ReportError(ECUM_SID_GET_SHUTDOWN_TARGET, errorID);
    }
#else
    ECUM_DUMMY_STATEMENT(errorID);
#endif  /* ECUM_DEV_ERROR_REPORT == STD_ON */

    return retVal;
}

/*
********************************************************************************
* Function Name: EcuM_GetLastShutdownTarget
*
* Explanation: EcuM_GetLastShutdownTarget returns the shutdown target of the previous
*               shutdown process.(Synchronous & Reentrant)
*
* param:    shutdownTarget : ECUM_SHUTDOWN_TARGET_SLEEP or  ECUM_SHUTDOWN_TARGET_RESET or ECUM_SHUTDOWN_TARGET_OFF
*           shutdownMode : If the out parameter "shutdownTarget" is ECUM_SHUTDOWN_TARGET_SLEEP,
*                           sleepMode tells which of the configured sleep modes was
*                           actually chosen. If "shutdownTarget" is ECUM_SHUTDOWN_TARGET_RESET,
*                           sleepMode tells which of the configured reset modes was actually
*                           chosen.
*
* retval: E_OK: The service has succeeded
*         E_NOT_OK: The service has failed, e.g. due to NULL pointer being passed
********************************************************************************
*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetLastShutdownTarget
(
    P2VAR(EcuM_ShutdownTargetType, AUTOMATIC, ECUM_APPL_DATA) shutdownTarget,
    P2VAR(EcuM_ShutdownModeType, AUTOMATIC, ECUM_APPL_DATA) shutdownMode
)
{
    uint8 errorID = ECUM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;

    /* Parameter validation. */
    if( (NULL_PTR == shutdownTarget) || (NULL_PTR == shutdownMode) )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorID = ECUM_E_NULL_POINTER;
    }
    else
    {
        /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_EcuM_Dir4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_EcuM_TAINTED_PTR" */
        *shutdownTarget = EcuM_LastShutdownTarget;
        /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_EcuM_Dir4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_EcuM_TAINTED_PTR" */
        *shutdownMode = (EcuM_ShutdownModeType)EcuM_LastShutdownMode;
        retVal = E_OK;
    }

    /* Report error to Det. */
#if( ECUM_DEV_ERROR_REPORT == STD_ON )
    if( errorID != ECUM_E_NO_ERROR )
    {
        EcuM_Det_ReportError(ECUM_SID_GET_LAST_SHUTDOWN_TARGET, errorID);
    }
#else
    ECUM_DUMMY_STATEMENT(errorID);
#endif  /* ECUM_DEV_ERROR_REPORT == STD_ON */

    return retVal;
}

/*
********************************************************************************
* Function Name: EcuM_SelectShutdownCause
*
* Explanation: Selects the cause for a shutdown.(Synchronous & Reentrant)
*
* param: target: The selected shutdown cause
*
* retval: E_OK: The new shutdown cause was set
*         E_NOT_OK: The new shutdown cause was not set
********************************************************************************
*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownCause
(
    EcuM_ShutdownCauseType target
)
{
    uint8 errorID = ECUM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;

    /* Parameter validation. */
#if( ECUM_SHUTDOWN_CAUSE_COUNT > ECUM_ZERO )
    if( target < ECUM_SHUTDOWN_CAUSE_COUNT )
    {
        EcuM_ShutdownCause = target;
        retVal = E_OK;
    }
    else
    {
        /* Invalid parameter. */
        errorID = ECUM_E_INVALID_PAR;
    }
#endif  /* ECUM_SHUTDOWN_CAUSE_COUNT > ECUM_ZERO */

    /* Report error to Det. */
#if( ECUM_DEV_ERROR_REPORT == STD_ON )
    if( errorID != ECUM_E_NO_ERROR )
    {
        EcuM_Det_ReportError(ECUM_SID_SELECT_SHUTDOWN_CAUSE, errorID);
    }
#else
    ECUM_DUMMY_STATEMENT(errorID);
#endif  /* ECUM_DEV_ERROR_REPORT == STD_ON */

    return retVal;
}

/*
********************************************************************************
* Function Name: EcuM_GetShutdownCause
*
* Explanation: Returns the selected shutdown cause as set by EcuM_SelectShutdownCause.
*              (Synchronous & Reentrant)
*
* param: shutdownCause: The selected cause of the next shutdown.
*
* retval: E_OK: The new shutdown cause was set
*         E_NOT_OK: The new shutdown cause was not set
********************************************************************************
*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetShutdownCause
(
    P2VAR(EcuM_ShutdownCauseType, AUTOMATIC, ECUM_APPL_DATA) shutdownCause
)
{
    uint8 errorID = ECUM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;

#if( ECUM_SHUTDOWN_CAUSE_COUNT > ECUM_ZERO )
    /* Parameter validation. */
    if( NULL_PTR == shutdownCause )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorID = ECUM_E_NULL_POINTER;
    }
    else
    {
        /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_EcuM_Dir4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_EcuM_TAINTED_PTR" */
        *shutdownCause = EcuM_ShutdownCause;
        retVal = E_OK;
    }
#else
    ECUM_DUMMY_STATEMENT(EcuM_ShutdownCause);
#endif  /* ECUM_SHUTDOWN_CAUSE_COUNT > ECUM_ZERO */

    /* Report error to Det. */
#if( ECUM_DEV_ERROR_REPORT == STD_ON )
    if( errorID != ECUM_E_NO_ERROR )
    {
        EcuM_Det_ReportError(ECUM_SID_GET_SHUTDOWN_CAUSE, errorID);
    }
#else
    ECUM_DUMMY_STATEMENT(errorID);
#endif  /* ECUM_DEV_ERROR_REPORT == STD_ON */

    return retVal;
}

/*
********************************************************************************
* Function Name: EcuM_GetPendingWakeupEvents
*
* Explanation: Gets pending wakeup events.(Synchronous & Non-Reentrant, Non-Interruptible)
*
* param: None
*
* retval: EcuM_WakeupSourceType: All wakeup events
********************************************************************************
*/
/* polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetPendingWakeupEvents(void)
{
    uint8 errorID = ECUM_E_NO_ERROR;
    EcuM_WakeupSourceType retval = ECUM_WKSOURCE_NONE;

    /* Check if the module is initialized. */
    if( EcuM_ModuleState != ECUM_MODULE_STATE_INIT )
    {
        errorID = ECUM_E_UNINIT;
    }
    else
    {
        /* Set pending wakeup events. */
        retval = EcuM_PendingWakeups;
    }

    /* Report error to Det. */
#if( ECUM_DEV_ERROR_REPORT == STD_ON )
    if( errorID != ECUM_E_NO_ERROR )
    {
        EcuM_Det_ReportError(ECUM_SID_GET_PENDING_WAKEUP_EVENTS, errorID);
    }
#else
    ECUM_DUMMY_STATEMENT(errorID);
#endif  /* ECUM_DEV_ERROR_REPORT == STD_ON */

    return retval;
}

/*
********************************************************************************
* Function Name: EcuM_ClearWakeupEvent
*
* Explanation: Clears wakeup events.(Synchronous & Non-Reentrant, Non-Interruptible)
*
* param: sources:Events to be cleared.
*
* retval: None
********************************************************************************
*/
FUNC(void, ECUM_CODE) EcuM_ClearWakeupEvent(EcuM_WakeupSourceType sources)
{
    /* SWS_EcuM_02683, EcuM_ClearWakeupEvent clears all pending events passed as
       a bit set in the sources parameter. This function should clear internal
       pending, validated and expired events variables. */
    EcuM_ValidatedWakeups &= (EcuM_WakeupSourceType)(~sources);
    /* Clear pending wakeup source. */
    EcuM_PendingWakeups &= (EcuM_WakeupSourceType)(~sources);
    /* Clear expired wakeup source. */
    EcuM_ExpiredWakeups &= (EcuM_WakeupSourceType)(~sources);

    /* Indicate BswM wakeup sources that're cleared.
       Note BswM can only accept one wake source a time.
       EcuM_IndicateWakeupStatusToBswM will test each bit of sources and
       send one set bit a time to BswM. */
    EcuM_IndicateWakeupStatusToBswM(sources, ECUM_WKSTATUS_NONE);
}

/*
********************************************************************************
* Function Name: EcuM_GetValidatedWakeupEvents
*
* Explanation: Gets validated wakeup events.(Synchronous & Non-Reentrant, Non-Interruptible)
*
* param: None
*
* retval: EcuM_WakeupSourceType: All wakeup events
********************************************************************************
*/
FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetValidatedWakeupEvents(void)
{
    EcuM_WakeupSourceType retVal = ECUM_WKSOURCE_NONE;

    /* Set validated wakeup source. */
    retVal = EcuM_ValidatedWakeups;

    return retVal;
}

#if( ECUM_VALIDATION_TIMEOUT == STD_ON )
/*
********************************************************************************
* Function Name: EcuM_GetExpiredWakeupEvents
*
* Explanation: Gets expired wakeup events.(Synchronous & Non-Reentrant, Non-Interruptible)
*
* param: None
*
* retval: EcuM_WakeupSourceType: All wakeup events: Returns all events that have been
*                               set and for which validation has failed.
********************************************************************************
*/
FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetExpiredWakeupEvents(void)
{
    EcuM_WakeupSourceType retVal = ECUM_WKSOURCE_NONE;

    /* Set expired wakeup source */
    retVal = EcuM_ExpiredWakeups;

    return retVal;
}
#endif  /* ECUM_VALIDATION_TIMEOUT == STD_ON */

#if( ECUM_VERSIONINFO_API == STD_ON )
/*
********************************************************************************
* Function Name: EcuM_GetVersionInfo
*
* Explanation: Returns the version information of this module.
*
* param: versioninfo: Pointer to where to store the version information of this module.
*
* retval: None
********************************************************************************
*/
FUNC(void, ECUM_CODE) EcuM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, ECUM_APPL_DATA) versioninfo
)
{
    /* Local Variables. */
    uint8 errorId = ECUM_E_NO_ERROR;

    /* Check module init. */
    if( ECUM_MODULE_STATE_INIT != EcuM_ModuleState )
    {
        errorId = ECUM_E_UNINIT;
    }
    else if( NULL_PTR == versioninfo )    /*  Check that module is initialized. */
    {
        errorId = ECUM_E_NULL_POINTER;
    }
    else
    {
        /*  Return vendor ID, module ID and version data. */
        versioninfo->vendorID = (uint16)ECUM_VENDOR_ID;
        versioninfo->moduleID = (uint8)ECUM_MODULE_ID;
        versioninfo->sw_major_version = (uint8)ECUM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)ECUM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)ECUM_SW_PATCH_VERSION;
    }

    /* Dev error report. */
#if( ECUM_DEV_ERROR_REPORT == STD_ON )
    if( errorId != ECUM_E_NO_ERROR )
    {
        (void)ECUM_REPORT_DEV_ERROR(ECUM_SID_GET_VERSION_INFO, errorId);
    }
#else
    ECUM_DUMMY_STATEMENT(errorId);
#endif  /* ECUM_DEV_ERROR_REPORT == STD_ON */

}
#endif  /* ECUM_VERSIONINFO_API == STD_ON */

/*
********************************************************************************
* Function Name: EcuM_GetResourceInCore
*
* Explanation: Get each Core's own resources
*
* param: CoreID
*
* retval: Resource
********************************************************************************
*/
/* polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
FUNC(EcuM_ResourceType, ECUM_CODE) EcuM_GetResourceInCore(EcuM_CoreIDType CoreID)
{
    EcuM_CoreIDType LoopCoreIndex;
    EcuM_ResourceType Resource = ECUM_INVALID;
    for( LoopCoreIndex = ECUM_ZERO; LoopCoreIndex < ECUM_NUMBER_OF_CORES; LoopCoreIndex++ )
    {
        if( CoreID == EcuM_ConfigParaData[LoopCoreIndex].CoreID )
        {
            Resource = EcuM_ConfigParaData[LoopCoreIndex].ResourceID;
        }
    }
    return Resource;
}

#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
/*
********************************************************************************
* Function Name: EcuM_WaitEvent
*
* Explanation: Wait slave core finised Event handle
*
* param: EventID: The ID corresponding to the event
*
* retval: E_OK : The slave core set event finish
*         E_NOT_OK :The slave core hav't set event
********************************************************************************
*/
/* polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, ECUM_CODE) EcuM_WaitEvent(EcuM_EventType EventID)
{
    uint8 Coreindex;
    uint8 Ret = E_NOT_OK;
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( EventID < ECUM_ALLCORE_SYNC_MAX )
    {
        /* Wait all core finised Event. */
        for( Coreindex = ECUM_ZERO ; Coreindex < ECUM_NUMBER_OF_CORES ; Coreindex++ )
        {
            if( ((EcuM_SyncEventTbl[EventID] >> Coreindex) & (ECUM_ONE)) != ECUM_ONE )
            {
                /* This bit is not set means the core is not ready. */
                break;
            }
        }
        if( ECUM_NUMBER_OF_CORES == Coreindex )
        {
            Ret = E_OK;
        }
    }
    return Ret;
}

/*
********************************************************************************
* Function Name: EcuM_GetEvent
*
* Explanation: Get the core event
*
* param: EventID: The ID corresponding to the event
*        CoreId_Pra: Core ID
*
* retval: E_OK : The core set event finish
*         E_NOT_OK :The core hav't set event
********************************************************************************
*/
/* polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, ECUM_CODE) EcuM_GetEvent(EcuM_EventType EventID, CoreIdType CoreId_Pra)
{
    uint8 Ret = E_NOT_OK ;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 Mask;
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( EventID < ECUM_ALLCORE_SYNC_MAX )
    {
        /* Test if the bit is set. */
        Mask = EcuM_SyncEventTbl[EventID] & (uint8)((uint8)ECUM_ONE << (uint8)CoreId_Pra);

        if( Mask > ECUM_ZERO )
        {
            /* Bit is set. */
            Ret = E_OK;
        }
    }
    return Ret;
}

/*
********************************************************************************
* Function Name: EcuM_SetEvent
*
* Explanation: The Slave core notify master core finish handle
*
* param: EventID: The ID corresponding to the event
*        CoreId_Pra: Core ID
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, ECUM_CODE) EcuM_SetEvent
(
    EcuM_EventType EventID, 
    CoreIdType CoreId_Pra
)
{
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( EventID < ECUM_ALLCORE_SYNC_MAX )
    {
        EcuM_SyncEventTbl[EventID] |= (uint8)((uint8)ECUM_ONE << (uint8)CoreId_Pra);
    }
}

/*
********************************************************************************
* Function Name: EcuM_ClearEvent
*
* Explanation: EventID: The ID corresponding to the event.
*
* param: EventID: The ID corresponding to the event.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, ECUM_CODE)EcuM_ClearEvent(EcuM_EventType EventID)
{
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( EventID < ECUM_ALLCORE_SYNC_MAX )
    {
        EcuM_SyncEventTbl[EventID] = ECUM_ZERO;
    }
}
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */

/*
********************************************************************************
* Function Name: EcuM_MainFunction
*
* Explanation: The purpose of this service is to implement all activities of the
*              ECU State Manager while the OS is up and running.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, ECUM_CODE) EcuM_MainFunction(void)
{

#if( ECUM_WAKEUP_SOURCE_LIST > ECUM_ZERO )
    uint8 loopIndex = ECUM_ZERO;
    EcuM_WakeupSourceType WakeupSrc = ECUM_NUMBER_32;  /* start from bit 5. */
#endif  /* ECUM_WAKEUP_SOURCE_LIST > ECUM_ZERO */

#if( (ECUM_NUMBER_OF_CORES > ECUM_ONE) && (ECUM_VALIDATION_TIMEOUT == STD_ON) )
    EcuM_CoreIDType coreId;

    coreId = (EcuM_CoreIDType)GetCoreID();
#endif  /* (ECUM_NUMBER_OF_CORES > ECUM_ONE) && (ECUM_VALIDATION_TIMEOUT == STD_ON) */

#if( ECUM_WAKEUP_SOURCE_LIST > ECUM_ZERO )
    /* To check if wakeup sources have woken up and to initiate wakeup validation,
       if necessary. As per SWS_EcuM_02625, wakeup sources 4-0 should never be
       invoked for validation. So the loop starts from wakeup source 5. */
    for( loopIndex = ECUM_NUMBER_5; loopIndex < ECUM_WAKEUP_SOURCE_LIST; loopIndex++ )
    {
#if( ECUM_VALIDATION_TIMEOUT == STD_ON )

#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
        /* Process wakeup source that is related to this core only. */
        if( EcuM_WakeupSourceList[loopIndex].coreId == coreId )
        {
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */
            /* Check if there are wakeup sources need to be validate. */
            if( (WakeupSrc & EcuM_PendingWakeups) != ECUM_ZERO )
            {
                /* Wakeup validation has already started. */
                if( EcuM_ValidationTimeoutArray[loopIndex] > ECUM_ZERO )
                {
                    /* Decrement wakeup sources timeout value. */
                    EcuM_ValidationTimeoutArray[loopIndex] -= ECUM_MAINFUNCTION_PERIOD;
                    /* Execute callout code to initiate a wakeup validation for this source. */
                    EcuM_CheckValidation(WakeupSrc);
                    /* Not timeout and wakeup source is not validated. */
                    if( ECUM_ZERO == EcuM_ValidationTimeoutArray[loopIndex] )
                    {
                        /* Set this wakeup source as expired. */
                        EcuM_ExpiredWakeups |= WakeupSrc;

                        /* Clear the corresponding bit in EcuM_PendingWakeups
                           and EcuM_ValidatedWakeups to maintain status consistency. */
                        EcuM_PendingWakeups &= ~WakeupSrc;
                        EcuM_ValidatedWakeups &= ~WakeupSrc;

                        /* Report this source as an expired source to the BswM. */
                        BswM_EcuM_CurrentWakeup(WakeupSrc, ECUM_WKSTATUS_EXPIRED);
                        /* stop the given wakeup source(s) after unsuccessful wakeup validation. */
                        EcuM_StopWakeupSources(WakeupSrc);
                    }
                }
                /* wakeup source is not started yet. */
                else
                {
                    /* Set the configured timeout for the current source. */
                    EcuM_ValidationTimeoutArray[loopIndex] = EcuM_WakeupSourceList[loopIndex].validationTimeout;
                    /* Execute callout code to start the wakeup validation. */
                    EcuM_StartWakeupSources(WakeupSrc);
                    /* Execute callout code to start the check validation. */
                    EcuM_CheckValidation(WakeupSrc);
                }
            }  /* end of check for pending bit */
#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
        } /* end of check for coreId. */
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */

#endif  /* ECUM_VALIDATION_TIMEOUT == STD_ON */
        /* Left shift one. */
        WakeupSrc <<= ECUM_ONE;
    }  /* end of loop for all wakeup sources. */

#endif  /* ECUM_WAKEUP_SOURCE_LIST > ECUM_ZERO */

#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
    switch(EcuM_AllCoreSyncSignal)
    {
        case ECUM_ALLCORE_GODOWN:
            (void)EcuM_GoDown(EcuM_AllCoreSyncGodownCaller);
        break;
#if( (ECUM_SLEEP_MODE_COUNT > ECUM_ZERO) && (ECUM_NORMAL_MCU_MODEREF != ECUM_FF) )
        case ECUM_ALLCORE_GOHALT:
            (void)EcuM_GoHalt();
        break;
#endif  /* (ECUM_SLEEP_MODE_COUNT > ECUM_ZERO) && (ECUM_NORMAL_MCU_MODEREF != ECUM_FF) */
        default:
            /* Do nothing. */
        break;
    }
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */

}

#define ECUM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*
*  File name: Os_SchdTb.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.23
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2022.11.21
* Change: Change OS_VAR_NOINIT to OS_VAR_NO_INIT.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: JiangGL/2022.11.23
* Change: Added Os_ SchdTb_ AppTerminateSchdTb interface is used to end ShcTb;
*         Fix the problem that the end schedule may cause exceptions;
*         Fix the problem of inaccurate scheduling node time in the end scheduling
*         table.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: JiangGL/2022.11.25
* Change: Resolve compilation warnings.
*         Fix the problem that the end schedule may cause exceptions
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: JiangGL/2023.01.09
* Change: AUTONICEPS-67,AUTONICEPS-61.Fix the problem that the schedule cannot
*         end normally when it ends immediately after the second start.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.1.29
* Change: Resolve the CallErrorHook privilege level problem.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2023.2.14
* Change: Annotation optimization.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: LiG/2023.2.15
* Change: Add macro switch.
* Cause: Bugfix
********************************************************************************
* Version: 3.8
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: LiG/2023.5.26
* Change: Optimize the usage of macros.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: JiangGL/2023.5.23
* Change: Fixed a problem where some chips or compilers may cause system runaway
*         due to schdTbCfg->dyn->currentExp being empty when the scheduling
*         table is forced to terminate before calling the first node.
* Cause: Bugfix
********************************************************************************
* Version: 3.11
* Author/Date: JiangGL/2023.5.24
* Change: Fixed the issue where a circular table, as a from table, cannot loop
*         after calling NextScheduleTable and then calling StartScheduleTableRel/
*         StartScheduleTableAbs after the table ends.
* Cause: Bugfix
********************************************************************************
* Version: 3.12
* Author/Date: JiangGL/2023.5.25
* Change: Resolve the issue of loop tables not stopping properly after using
*         NextScheduleTable to link to a loop table for a single time.
* Cause: Bugfix
********************************************************************************
* Version: 3.13
* Author/Date: LiG/2023.5.26
* Change: Unable to successfully use StopScheduleTable cross core.
* Cause: Bugfix
********************************************************************************
* Version: 3.14
* Author/Date: LiG/2023.05.26
* Change: Resolve compilation warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.15
* Author/Date: LiG/2023.5.27
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.16
* Author/Date: LiG/2023.6.9
* Change: No assignment issues during startup.Scheduling Table Deviation
*         Movement Problem.Scheduling Table Delete Node Problem.
* Cause: Bugfix
********************************************************************************
* Version: 3.17
* Author/Date: LiG/2023.10.1
* Change: Resolve compilation warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.18
* Author/Date: LiG/2023.10.24
* Change: Resolve the issue of invalid enumeration precompilation.
* Cause: Bugfix
********************************************************************************
* Version: 3.19
* Author/Date: LiG/2023.11.1
* Change: Resolve the issue of invalid enumeration precompilation.
*         StopScheduleTable interface.
* Cause: Bugfix
********************************************************************************
* Version: 3.20
* Author/Date: JiangGL/2024.1.11
* Change: 1. Fix the bug where the scheduling degree input parameter cannot
*         exceed 1/2 of the maximum value of the corresponding Counter.
*         2. Fix the issue of implicit synchronization scheduling tables taking
*         the synchronization range of the previous expiration point during
*         synchronization.
* Cause: Bugfix
********************************************************************************
* Version: 3.21
* Author/Date: JiangGL/2024.1.25
* Change: 1. Fix the issue where the Next pointer of the table was not reset
*         after stopping the scheduling table, resulting in the table not running
*          properly after restarting.
*         2. Fix the issue where the next expiration point of HRT was not
*         correctly set after immediately stopping the scheduling table/Alram
*         driven by HRT.
* Cause: Bugfix
********************************************************************************
* Version: 3.22
* Author/Date: LiG/2024.5.6
* Change: 1. Modify one of the error return values of the
*            Os_SchdTb_TargetStartScheduleTableRel function to set the value to
*            E_OS_STATE.
* Cause: Bugfix
********************************************************************************
* Version: 3.23
* Author/Date: LiG/2024.5.6
* Change: 1. Modify one of the error return values of the
*            Os_SchdTb_TargetStopScheduleTable function to set the value to
*            E_OS_NOFUNC.
*         2. Change variable checking to uint64 type to prevent judgment errors
*            caused by data flipping.
* Cause: Bugfix
********************************************************************************
* Version: 3.24
* Author/Date: LiG/2024.5.6
* Change: When an error occurs in a cross core interface call, the output
*         parameter data is changed.
* Cause: Bugfix
********************************************************************************
* Version: 3.25
* Author/Date: LiG/2024.5.20
* Change: Modify one of the error return values of the
*            Os_SchdTb_TargetStartScheduleTableRel function to set the value to
*            E_OS_STATE.
* Cause: Bugfix
********************************************************************************
* Version: 3.26
* Author/Date: LiG/2024.5.21
* Change: Modify the error detection position of the Os_SchdTb_StartTimeTableRel.
* Cause: Bugfix
********************************************************************************
* Version: 3.27
* Author/Date: LiuZB/2025.02.20
* Change: Optimize space size.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_SchdTb.h"
#include "Os_App.h"
#include "Os_MultiCore.h"
#include "Os_Core.h"
#include "Os_Platform_Lcfg.h"
#include "Os_Task.h"
#include "Os_Counter.h"
#include "Os_Event.h"
#include "Os_SysCall.h"
#include "Os_SchdTb_Lcfg.h"
#include "Os_Orti.h"
#include "Os.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/* Divisor of sync duration. */
#define OS_SCHDTB_HALFDIV                    (2U)
/* Get the schedule table static configuration by id. */
#define OS_SCHDTB_GETCFG(schdTbId)           (Os_SchdTbCfgData[schdTbId])
/* Get the core id to which the schedule table belongs through
   the schedule table static configuration. */
#define OS_SCHDTB_GETCOREID(schdTbCfg)       ((schdTbCfg)->coreId)
/* Get half of the sync duration. */
#define OS_SCHDTB_GETHALFDURATION(schdTbCfg) ((schdTbCfg)->duration / OS_SCHDTB_HALFDIV)

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
#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
#if( OS_CFG_SCHDTBSYNC_ENABLE == STD_ON )
static FUNC(Os_TickType, OS_CODE) Os_SchdTb_SyncParam
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg,
    P2CONST(Os_SchdTbExpCfgType, AUTOMATIC, OS_APPL_CONST) currentSchdTbExp
);
#endif

static FUNC(void, OS_CODE) Os_SchdTb_ExpWorkFunc
(
    P2CONST(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_CONST) expListNode
);

static FUNC(Os_StatusType, OS_CODE) Os_SchdTb_StartRelSimp
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg,
    TickType offset
);

static FUNC(Os_StatusType, OS_CODE) Os_SchdTb_StartAbsSimp
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg,
    TickType start
);

static FUNC(void, OS_CODE) Os_SchdTb_StopScheduleTableSimp
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg
);

static FUNC(void, OS_CODE) Os_SchdTb_StartSyncSimp
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg
);

static FUNC(void, OS_CODE) Os_SchdTb_InitSimp
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg
);

static FUNC(void, OS_CODE) Os_SchdTb_NextScheduleTableSimp
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg_From,
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg_To
);

#if( OS_CFG_SCHDTBSYNC_ENABLE == STD_ON )
static FUNC(void, OS_CODE) Os_SchdTb_UpdateSyncState
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg
);
#endif

#if( OS_CFG_SCHDTBSYNC_ENABLE == STD_ON )
static FUNC(Os_StatusType, OS_CODE) Os_SchdTb_SyncScheduleTableSimp
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg,
    TickType syncValue
);
#endif

static FUNC(void, OS_CODE) Os_SchdTb_GetStatusSimp
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg,
    ScheduleTableStatusRefType scheduleStatus
);
#endif /* OS_CFG_SCHDTB_ENABLE  == STD_ON */

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

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*
********************************************************************************
* Function Name: Os_SchdTb_StartRelSimp
*
* Explanation: Internal function to start the relative schedule table.
*
* Param: schdTbCfg: Reference to the schedule table configuration.
*        offset: Relative value in ticks.
*
* Retval: E_OS_OK: No error.
********************************************************************************
*/
#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
static FUNC(Os_StatusType, OS_CODE) Os_SchdTb_StartRelSimp
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg,
    TickType offset
)
{
    Os_StatusType ret;
    Os_CntExpListNodeCfgType* initExpNode;

    initExpNode = &schdTbCfg->initExp->expNode;
    initExpNode->workParam.schdTbParam = schdTbCfg->initExp->schdTbParam;
    /* Insert expiry point into counter. */
    ret = Os_Counter_InsertExpPoint(schdTbCfg->counter,initExpNode,
                                    (schdTbCfg->initOffset + offset));
    if ( E_OS_OK == ret )
    {
        /* Assign a value to the node currently being scheduled by the system. */
        schdTbCfg->dyn->currentExp = schdTbCfg->initExp;
        schdTbCfg->dyn->state = SCHEDULETABLE_RUNNING;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_SchdTb_StartAbsSimp
*
* Explanation: Internal function to start the absolute schedule table.
*
* Param: schdTbCfg: Reference to the schedule table configuration.
*        start: Absolute counter tick value at which the schedule table is started.
*
* Retval: E_OS_OK: No error.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_SchdTb_StartAbsSimp
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg,
    TickType start
)
{
    Os_StatusType ret;
    Os_CntExpListNodeCfgType* initExpNode;
    initExpNode = &schdTbCfg->initExp->expNode;
    initExpNode->workParam.schdTbParam = schdTbCfg->initExp->schdTbParam;
    ret = Os_Counter_InsertAbsExpPoint(schdTbCfg->counter,
                                       initExpNode,
                                       (schdTbCfg->initOffset + start));
    if ( E_OS_OK == ret )
    {
        /* Assign a value to the node currently being scheduled by the system. */
        schdTbCfg->dyn->currentExp = schdTbCfg->initExp;
        schdTbCfg->dyn->state = SCHEDULETABLE_RUNNING;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_SchdTb_StopScheduleTableSimp
*
* Explanation: Internal function to stop the schedule table.
*
* Param: schdTbCfg: Reference to the schedule table configuration.
*
* Retval: E_OS_OK: No error.
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SchdTb_StopScheduleTableSimp
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg
)
{
    const Os_SchdTbCfgType* prevSchdTbCfg;
    const Os_SchdTbCfgType* nextSchdTbCfg;
    Os_CntExpListNodeCfgType* expListNode = NULL_PTR;
    Os_StatusType ret;

    switch( schdTbCfg->dyn->state )
    {
        case SCHEDULETABLE_NEXT:
            prevSchdTbCfg = schdTbCfg->dyn->previous;
            /* Obtain the expiration point that is about to be deleted. */
            expListNode = (Os_CntExpListNodeCfgType*)(&(prevSchdTbCfg->dyn->currentExp->nextExp->expNode));
            prevSchdTbCfg->dyn->state = SCHEDULETABLE_STOPPED;
            break;
        case SCHEDULETABLE_RUNNING:
        case SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS:
            /* Obtain the next triggered expiration point in the scheduling table. */
            expListNode = (Os_CntExpListNodeCfgType*)(&schdTbCfg->dyn->currentExp->nextExp->expNode);
            /* Determine if the next triggered expiration point in the scheduling table is valid. */
            if( NULL_PTR == expListNode )
            {
                /* Obtain the initialization expiration point of the scheduling table. */
                expListNode = (Os_CntExpListNodeCfgType*)(schdTbCfg->initExp);
            }
            /* Determine if the target expiration point that needs to be deleted is valid. */
            if( NULL_PTR != expListNode )
            {
                /* Attempt to find the target expiration point that needs to be deleted in the
                   scheduling queue of Counter. */
                ret = Os_Counter_ExpPointFind(schdTbCfg->counter, expListNode);
                /* Unable to find target expiration point. */
                if( E_OS_NODATA == ret )
                {
                    /* Obtain the expiration point of the currently running schedule table. */
                    expListNode = (Os_CntExpListNodeCfgType*)(schdTbCfg->dyn->currentExp);
                }
            }
            schdTbCfg->dyn->state = SCHEDULETABLE_STOPPED;
            break;
        case SCHEDULETABLE_WAITING:
        case SCHEDULETABLE_STOPPED:
            schdTbCfg->dyn->state = SCHEDULETABLE_STOPPED;
            break;
        default:
            Os_FatalError();
            break;
    }

    /* Determine if the target expiration point that needs to be deleted is valid. */
    if( NULL_PTR != expListNode )
    {
#if( OS_HRT_ENABLE == STD_ON )
        /* Determine Counter Type. */
        if( OS_COUNTER_HRT == schdTbCfg->counter->counterType )
        {
            Os_CntExpListNodeCfgType* CurrentExpListNode;

            /* Obtain the expiration point that Counter is about to trigger. */
            (void)Os_Counter_GetCurretExpList(schdTbCfg->counter, &CurrentExpListNode);
            /* Delete target expiration point. */
            (void)Os_Counter_ExpPointDel(schdTbCfg->counter, expListNode);
            /* Determine whether the target expiration point that needs to be deleted
               is consistent with the expiration point that is about to be triggered. */
            if( expListNode == CurrentExpListNode )
            {
                Os_TickType lastValue;
                Os_TickType nowValue;
                Os_TickType startValue;
                Os_TickType targetCompare;
                const Os_CounterHrtCfgType* cntCfg = (const Os_CounterHrtCfgType*)(schdTbCfg->counter);

                nowValue = Os_Arch_Mach_HrtTimerGetValue(cntCfg->HwConfig);
                targetCompare = CurrentExpListNode->expTimestamp.timebase;
                /* Obtain the Counter value from the previous Compare setting in advance. */
                lastValue = cntCfg->counterDyn->lastValue;
                if( OS_COUNTER_TICKSUB(schdTbCfg->counter, nowValue, lastValue) >=
                    OS_COUNTER_TICKSUB(schdTbCfg->counter, targetCompare, lastValue) )
                {
                    startValue = targetCompare;
                    /* Clear interrupt flag. */
                    Os_Arch_Mach_HrtClearInterrupt(cntCfg->HwConfig);
                }
                else
                {
                    startValue = nowValue;
                }

                /* Get hrt timer last compare value. */
                Os_Counter_SetNextPoint(schdTbCfg->counter, startValue);
            }
        }
        else
        {
#endif /* OS_HRT_ENABLE == STD_ON */
            /* Delete target expiration point. */
            (void)Os_Counter_ExpPointDel(schdTbCfg->counter, expListNode);
#if( OS_HRT_ENABLE == STD_ON )
        }
#endif /* OS_HRT_ENABLE == STD_ON */
    }

    schdTbCfg->dyn->currentExp = NULL_PTR;

    if( NULL_PTR != schdTbCfg->dyn->next )
    {
        nextSchdTbCfg = schdTbCfg->dyn->next;
        nextSchdTbCfg->dyn->state = SCHEDULETABLE_STOPPED;
    }

    /* Determine the type of scheduling table that needs to be stopped. */
    if( OS_SCHDTB_CYCLE_MODE == schdTbCfg->cycleType )
    {
        /* Set the next node of the scheduling table to the table itself. */
        schdTbCfg->dyn->next = schdTbCfg;
    }
    else
    {
        /* Set the next node of the scheduling table to NULL_PTR. */
        schdTbCfg->dyn->next = NULL_PTR;
    }
}

/*
********************************************************************************
* Function Name: Os_SchdTb_StartSyncSimp
*
* Explanation: Internal function to start an explicitly synchronized schedule
*              table synchronously.
*
* Param: schdTbCfg: Reference to the schedule table configuration.
*
* Retval: E_OS_OK: No error.
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SchdTb_StartSyncSimp
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg
)
{
    schdTbCfg->dyn->currentExp = schdTbCfg->initExp;
    schdTbCfg->dyn->state = SCHEDULETABLE_WAITING;
}

/*
********************************************************************************
* Function Name: Os_SchdTb_InitSimp
*
* Explanation: Internal function to init the schedule table object.
*
* Param: schdTbCfg: Reference to the schedule table configuration.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SchdTb_InitSimp
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg
)
{
    Os_SchdTbDynType* schdTbDyn;

    if( NULL_PTR != schdTbCfg )
    {
        schdTbDyn = schdTbCfg->dyn;
        schdTbDyn->state = SCHEDULETABLE_STOPPED;
        schdTbDyn->currentExp = NULL_PTR;
        schdTbDyn->schdTbId = schdTbCfg->schdTbId;

        if( OS_SCHDTB_CYCLE_MODE == schdTbCfg->cycleType )
        {
            schdTbDyn->next = schdTbCfg;
        }
        else
        {
            schdTbDyn->next = NULL_PTR;
        }
        schdTbDyn->previous = NULL_PTR;

#if( OS_CFG_SCHDTBSYNC_ENABLE == STD_ON )
        if( OS_SCHDTB_EXPLICIT_KIND == schdTbCfg->schdTbKind )
        {
            schdTbDyn->deviation = 0U;
            schdTbDyn->driveCtrTimeStamp = 0U;
            schdTbDyn->SyncState = OS_SCHTSYNCSTATUS_NOT_PROVIDED;
        }
#endif
    }
}

/*
********************************************************************************
* Function Name: Os_SchdTb_NextScheduleTableSimp
*
* Explanation: Internal function to switch the processing from one schedule table
*               to another schedule table.
*
* Param: ScheduleTableID_From: Currently processed schedule table.
*        ScheduleTableID_To: Schedule table that provides its series of expiry points.
*
* Retval: E_OS_OK: No error.
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SchdTb_NextScheduleTableSimp
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg_From,
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg_To
)
{
    Os_SchdTbDynType* schdTbDyn_From = schdTbCfg_From->dyn;
    Os_SchdTbDynType* schdTbDyn_To   = schdTbCfg_To->dyn;

    if( (schdTbDyn_From->next != NULL_PTR) && (schdTbDyn_From->next != schdTbCfg_From) )
    {
        schdTbDyn_From->next->dyn->state = SCHEDULETABLE_STOPPED;
    }
    Os_SchdTb_InitSimp(schdTbCfg_To);
    schdTbDyn_To->state = SCHEDULETABLE_NEXT;
    schdTbDyn_From->next = schdTbCfg_To;
    schdTbDyn_To->previous = schdTbCfg_From;
}

#if( OS_CFG_SCHDTBSYNC_ENABLE == STD_ON )
/*
********************************************************************************
* Function Name: Os_SchdTb_UpdateSyncState
*
* Explanation: Internal function to update schedule table sync state.
*
* Param: schdTbCfg: Reference to the schedule table configuration.
*
* Retval: E_OS_OK: No error.
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SchdTb_UpdateSyncState
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg
)
{
    Os_SchdTbDynType* schdTbDyn = schdTbCfg->dyn;

    if( OS_SCHTSYNCSTATUS_NOT_PROVIDED != schdTbDyn->SyncState )
    {
         if( (schdTbDyn->deviation <= schdTbCfg->precision)
             || ((Os_TickType)(-((sint32)(schdTbDyn->deviation))) <= schdTbCfg->precision) )
        {
            if( SCHEDULETABLE_RUNNING == schdTbDyn->state )
            {
                schdTbDyn->state = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
                schdTbDyn->SyncState = OS_SCHTSYNCSTATUS_SYNC;
            }
        }
        else
        {
            if( SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS == schdTbDyn->state )
            {
                schdTbDyn->state = SCHEDULETABLE_RUNNING;
                schdTbDyn->SyncState = OS_SCHTSYNCSTATUS_ASYNC;
            }
        }
    }
}
#endif

#if( OS_CFG_SCHDTBSYNC_ENABLE == STD_ON )
/*
********************************************************************************
* Function Name: Os_SchdTb_SyncScheduleTableSimp
*
* Explanation: Internal function to provide the schedule table with a synchronization
*              count and start synchronization.
*
* Param: schdTbCfg: Reference to the schedule table configuration.
*        syncValue: The current value of the synchronization counter.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_VALUE: The syncValue is out of range.
*         E_OS_STATE: The state of schedule table <ScheduleTableID> is equal
*                     to SCHEDULETABLE_STOPPEDt.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_SchdTb_SyncScheduleTableSimp
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg,
    TickType syncValue
)
{
    Os_StatusType ret = E_OS_OK;
    Os_TickType offset;
    Os_TickType currentCtrValue;
    Os_TickType diffCtrValue;
    Os_TickType expectedSyncTime;
    Os_TickType tempDeviation;
    Os_CntExpListNodeCfgType* initExpNode;
    Os_SchdTbDynType* schdTbDyn = schdTbCfg->dyn;

    if( syncValue > (schdTbCfg->duration - OS_SCHDTB_FLIPDEV) )
    {
        ret = E_OS_VALUE;
    }
    else
    {
        if( SCHEDULETABLE_WAITING == schdTbDyn->state )
        {
            initExpNode = &schdTbCfg->initExp->expNode;
            initExpNode->workParam.schdTbParam = schdTbCfg->initExp->schdTbParam;
            offset = (schdTbCfg->duration - syncValue) + schdTbCfg->initOffset;
            /* Insert expiry point into counter. */
            ret = Os_Counter_InsertExpPoint(schdTbCfg->counter, initExpNode, offset);
            if( E_OS_OK == ret )
            {
                schdTbDyn->driveCtrTimeStamp = Os_Counter_GetCntValue(schdTbCfg->counter);
                schdTbDyn->deviation = 0U;
                schdTbDyn->state = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
            }
        }
        else
        {
            if( NULL_PTR != schdTbDyn->currentExp )
            {
                currentCtrValue = Os_Counter_GetCntValue(schdTbCfg->counter);
                /* Get the time difference from the last expiry point of the driven timer. */
                diffCtrValue = OS_COUNTER_TICKSUB(schdTbCfg->counter, currentCtrValue, schdTbDyn->driveCtrTimeStamp);
                diffCtrValue = diffCtrValue % schdTbCfg->duration;
                /* Get the expected synchronization time. */
                expectedSyncTime = (schdTbDyn->currentExp->expSyncTimeStamp + diffCtrValue) % schdTbCfg->duration;

                if( expectedSyncTime >= syncValue )
                {
                    tempDeviation = expectedSyncTime - syncValue;
                    if( tempDeviation > OS_SCHDTB_GETHALFDURATION(schdTbCfg))
                    {
                        tempDeviation = tempDeviation - schdTbCfg->duration;
                    }
                }
                else
                {
                    tempDeviation = syncValue - expectedSyncTime;
                    if( tempDeviation > OS_SCHDTB_GETHALFDURATION(schdTbCfg))
                    {
                        tempDeviation = schdTbCfg->duration - tempDeviation;
                    }
                    else
                    {
                        tempDeviation = (~tempDeviation + OS_SCHDTB_FLIPDEV);
                    }
                }
                /* Get sync offset may be positive or negative. */
                schdTbDyn->deviation = tempDeviation;
                /* Update SyncState status to OS_ SCHTSYNCSTATUS_ SYNC indicates
                   that synchronization has occurred */
                schdTbDyn->SyncState = OS_SCHTSYNCSTATUS_SYNC;
                Os_SchdTb_UpdateSyncState(schdTbCfg);
            }
        }
    }

    return ret;
}
#endif

#if( OS_CFG_SCHDTBSYNC_ENABLE == STD_ON )
/*
********************************************************************************
* Function Name: Os_SchdTb_SyncParam
*
* Explanation: Internal function to update schedule table sync parameter.
*
* Param: schdTbCfg: Reference to the schedule table configuration.
*        currentSchdTbExp: Current expiry point.
*
* Retval: E_OS_OK: No error.
********************************************************************************
*/
static FUNC(Os_TickType, OS_CODE) Os_SchdTb_SyncParam
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg,
    P2CONST(Os_SchdTbExpCfgType, AUTOMATIC, OS_APPL_CONST) currentSchdTbExp
)
{
    Os_TickType syscOffset;
    Os_SchdTbDynType* schdTbDyn = schdTbCfg->dyn;
    Os_TickType shortenDeviation;

    schdTbDyn->driveCtrTimeStamp = Os_Counter_GetCntValue(schdTbCfg->counter);
    Os_SchdTb_UpdateSyncState(schdTbCfg);
    /* Judgment deviation is positive. */
    if( schdTbDyn->deviation <= OS_COUNTER_GET_HALF_MAXVALUE(schdTbCfg->counter) )
    {
        if( schdTbDyn->deviation > currentSchdTbExp->maxLengthenDeviation )
        {
            syscOffset = currentSchdTbExp->maxLengthenDeviation;
        }
        else
        {
            syscOffset = schdTbDyn->deviation;
        }
    }
    else
    {
        shortenDeviation = OS_SCHDTB_MAXSHORTEN_DEVIATION_CONVERT(currentSchdTbExp->maxShortenDeviation);
        if( (schdTbDyn->deviation < shortenDeviation) || (shortenDeviation == 0U) )
        {
            syscOffset = shortenDeviation;
        }
        else
        {
            syscOffset = schdTbDyn->deviation;
        }
    }
    schdTbDyn->deviation -= syscOffset;

    return syscOffset;
}
#endif

/*
********************************************************************************
* Function Name: Os_SchdTb_GetStatusSimp
*
* Explanation: Internal function to get the state of a schedule table.
*
* Param: schdTbCfg: Reference to the schedule table configuration.
*
* Retval: E_OS_OK: No error.
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SchdTb_GetStatusSimp
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg,
    ScheduleTableStatusRefType scheduleStatus
)
{
    if( OS_SCHDTB_IMPLICIT_KIND == schdTbCfg->schdTbKind )
    {
        if( SCHEDULETABLE_RUNNING == schdTbCfg->dyn->state )
        {
            *scheduleStatus = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
        }
        else
        {
            *scheduleStatus  = schdTbCfg->dyn->state;
        }
    }
    else
    {
        *scheduleStatus  = schdTbCfg->dyn->state;
    }
}

/*
********************************************************************************
* Function Name: Os_SchdTb_Init
*
* Explanation: Initialize the schedule table object.
*
* Param: schdTbCfg: Reference to the schedule table configuration.
*        appMode: The mode of the application to which the alarm belongs.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_SchdTb_Init
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg,
    AppModeType appMode
)
{
    if( NULL_PTR != schdTbCfg )
    {
        /* Init the schedule table. */
        Os_SchdTb_InitSimp(schdTbCfg);

        /* Perform self-starting operation. */
        if( (schdTbCfg->appMode & appMode) != 0U )
        {
            switch( schdTbCfg->autoStartMode )
            {
                case OS_SCHDTB_ABS_START:
                    (void)Os_SchdTb_StartAbsSimp(schdTbCfg, schdTbCfg->autoStartTime);
                    break;
                case OS_SCHDTB_REL_START:
                    (void)Os_SchdTb_StartRelSimp(schdTbCfg, schdTbCfg->autoStartTime);
                    break;
                case OS_SCHDTB_SYNC_START:
                    (void)Os_SchdTb_StartSyncSimp(schdTbCfg);
                    break;
                default:
                    Os_FatalError();
                    break;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Os_SchdTb_AppTerminateSchdTb
*
* Explanation: Terminate the SchdTb.
*
* Param: schdTbCfg: Reference to an SchdTb.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_SchdTb_AppTerminateSchdTb
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg
)
{
     if( schdTbCfg != NULL_PTR )
     {
        /* Determine whether the scheduling table is in SCHEDULETABLE_STOPPED status. */
        if( SCHEDULETABLE_STOPPED != schdTbCfg->dyn->state )
        {
            Os_SchdTb_StopScheduleTableSimp(schdTbCfg);
        }
     }
}

/*
********************************************************************************
* Function Name: Os_SchdTb_StartScheduleTableRel
*
* Explanation: Uses to start the relative schedule table.
*
* Param: scheduleTableID: Reference to the schedule table configuration.
*        offset: Relative value in ticks.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_VALUE: Offset is greater than (OsCounterMaxAllowedValue -
*                     InitialOffset)or is equal to 0.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                          disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.- Given
*                      schedule table's owner application is not accessible.
*         E_OS_CORE: Core is not available.
*         E_OS_STATE: Schedule table was already started.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_SchdTb_StartScheduleTableRel
(
    ScheduleTableType scheduleTableID,
    TickType offset
)
{
    Os_StatusType ret;
    CoreIdType coreId;
    const Os_SchdTbCfgType* schdTbCfg;
    Os_Arch_IntState intState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_StartScheduleTableRel);
    /* Get logic core id */
    coreId = Os_Core_GetLogicId();

#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    if( scheduleTableID >= OS_SCHTID_COUNT )
    {
        ret = E_OS_ID;
    }
    else
#endif
    if( OS_CORE_MASK_INTERRUPT(coreId) ) /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_STARTRELSCHTB_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        /* Get alarm configuration data. */
        schdTbCfg = OS_SCHDTB_GETCFG(scheduleTableID);
        if( OS_APPMATCH(schdTbCfg->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission. */
        {
            ret = E_OS_ACCESS;
        }
        else if( OS_COUNTER_CHECKINVALIDVALUE(schdTbCfg->counter, ((uint64)(schdTbCfg->initOffset) + (uint64)offset), offset) )
        {
            ret = E_OS_VALUE;
        }
        else
        {
#if( OS_CFG_MULTI_CORE == STD_ON )
            if( coreId == OS_SCHDTB_GETCOREID(schdTbCfg) )
#endif
            {
                if( OS_APP_STATEOFF(schdTbCfg->ownerAppId) ) /* If the application is not accessible. */
                {
                    ret = E_OS_ACCESS;
                }
                else if( OS_SCHDTB_IMPLICIT_KIND == schdTbCfg->schdTbKind )
                {
                    ret = E_OS_ID;
                }
                else if( 0U == offset )
                {
                    ret = E_OS_VALUE;
                }
                else if( SCHEDULETABLE_STOPPED != schdTbCfg->dyn->state )
                {
                    ret = E_OS_STATE;
                }
                else
                {
                    /* Disable interrupt. */
                    Os_Arch_IntDisable(&intState);
                    ret = Os_SchdTb_StartRelSimp(schdTbCfg, offset);
                    /* Enable interrupt. */
                    Os_Arch_IntEnable(intState);
                }
            }
#if( OS_CFG_MULTI_CORE == STD_ON )
            else
            {
                /* Set absolute alarm of target core. */
                Os_MultiCoreServeParamType parameter;
                parameter.Os_StartSchdTbRel.scheduleTableID = scheduleTableID;
                parameter.Os_StartSchdTbRel.offset = offset;
                /* Execute multi-core calling function. */
                ret = Os_MultiCore_Trigger(TRUE, coreId, OS_SCHDTB_GETCOREID(schdTbCfg),
                                           Os_MCServe_StartSchdTbRel_ID, &parameter);
            }
#endif
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_StartScheduleTableRel);

    return Os_Hook_CallErrorHook(OSServiceId_StartScheduleTableRel, ret);
}

/*
********************************************************************************
* Function Name: Os_SchdTb_StartScheduleTableAbs
*
* Explanation: Uses to start the absolute schedule table.
*
* Param: scheduleTableID: Reference to the schedule table configuration.
*        start: Absolute counter tick value at which the schedule table is started.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_VALUE: Start is greater than OsCounterMaxAllowedValue.
*         E_OS_STATE: Schedule table was already started.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.- Given schedule
*                      table's owner application is not accessible.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_SchdTb_StartScheduleTableAbs
(
    ScheduleTableType scheduleTableID,
    TickType start
)
{
    Os_StatusType ret;
    CoreIdType coreId;
    const Os_SchdTbCfgType* schdTbCfg;
    Os_Arch_IntState intState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_StartScheduleTableAbs);
    /* Get logic core id */
    coreId = Os_Core_GetLogicId();

#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    if( scheduleTableID >= OS_SCHTID_COUNT )
    {
        ret = E_OS_ID;
    }
    else
#endif
    if( OS_CORE_MASK_INTERRUPT(coreId) ) /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_STARTABSSCHTB_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        /* Get alarm configuration data. */
        schdTbCfg = OS_SCHDTB_GETCFG(scheduleTableID);
        if( OS_APPMATCH(schdTbCfg->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission. */
        {
            ret = E_OS_ACCESS;
        }
        else
        {
#if( OS_CFG_MULTI_CORE == STD_ON )
            if( coreId == OS_SCHDTB_GETCOREID(schdTbCfg) )
#endif
            {
                if( OS_APP_STATEOFF(schdTbCfg->ownerAppId) ) /* If the application is not accessible. */
                {
                    ret = E_OS_ACCESS;
                }
                else if( OS_COUNTER_CHECKINVALIDVALUE(schdTbCfg->counter, schdTbCfg->initExp->nextExpOffset, start) )
                {
                    ret = E_OS_VALUE;
                }
                else if( SCHEDULETABLE_STOPPED != schdTbCfg->dyn->state )
                {
                    ret = E_OS_STATE;
                }
                else
                {
                    /* Disable interrupt. */
                    Os_Arch_IntDisable(&intState);
                    ret = Os_SchdTb_StartAbsSimp(schdTbCfg, start);
                    /* Enable interrupt. */
                    Os_Arch_IntEnable(intState);
                }
            }
#if( OS_CFG_MULTI_CORE == STD_ON )
            else
            {
                /* Set absolute alarm of target core. */
                Os_MultiCoreServeParamType parameter;
                parameter.Os_StartSchdTbAbs.scheduleTableID = scheduleTableID;
                parameter.Os_StartSchdTbAbs.start = start;
                /* Execute multi-core calling function. */
                ret = Os_MultiCore_Trigger(TRUE, coreId, OS_SCHDTB_GETCOREID(schdTbCfg),
                                           Os_MCServe_StartSchdTbAbs_ID, &parameter);
            }
#endif
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_StartScheduleTableAbs);

    return Os_Hook_CallErrorHook(OSServiceId_StartScheduleTableAbs, ret);
}

/*
********************************************************************************
* Function Name: Os_SchdTb_StopScheduleTable
*
* Explanation: Uses to stop the  schedule table.
*
* Param: scheduleTableID: Reference to the schedule table configuration.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.- Given schedule
*                      table's owner application is not accessible.
*         E_OS_CORE: Core is not available.
*         E_OS_NOFUNC: The schedule table was already stopped.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_SchdTb_StopScheduleTable(ScheduleTableType scheduleTableID)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    const Os_SchdTbCfgType* schdTbCfg;
    Os_Arch_IntState intState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_StopScheduleTable);
    /* Get logic core id */
    coreId = Os_Core_GetLogicId();

#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    if( scheduleTableID >= OS_SCHTID_COUNT )
    {
        ret = E_OS_ID;
    }
    else
#endif
    if( OS_CORE_MASK_INTERRUPT(coreId) ) /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_STOPSCHTB_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        /* Get alarm configuration data. */
        schdTbCfg = OS_SCHDTB_GETCFG(scheduleTableID);
        if( OS_APPMATCH(schdTbCfg->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission. */
        {
            ret = E_OS_ACCESS;
        }
        else
        {

#if( OS_CFG_MULTI_CORE == STD_ON )
            if( coreId == OS_SCHDTB_GETCOREID(schdTbCfg) )
#endif
            {
                if( OS_APP_STATEOFF(schdTbCfg->ownerAppId) ) /* If the application is not accessible. */
                {
                    ret = E_OS_ACCESS;
                }
                else if( SCHEDULETABLE_STOPPED == schdTbCfg->dyn->state )
                {
                    /* if Schedule table was already stopped,return E_OS_NOFUNC. */
                    ret = E_OS_NOFUNC;
                }
                else
                {
                    /* Disable interrupt */
                    Os_Arch_IntDisable(&intState);
                    Os_SchdTb_StopScheduleTableSimp(schdTbCfg);
                    /* Enable interrupt */
                    Os_Arch_IntEnable(intState);
                }
            }
#if( OS_CFG_MULTI_CORE == STD_ON )
            else
            {
                /* Set absolute alarm of target core. */
                Os_MultiCoreServeParamType parameter;
                parameter.Os_StopSchdTb.scheduleTableID = scheduleTableID;
                /* Execute multi-core calling function. */
                ret = Os_MultiCore_Trigger(TRUE, coreId, OS_SCHDTB_GETCOREID(schdTbCfg),
                                           Os_MCServe_StopSchdTb_ID, &parameter);
            }
#endif
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_StopScheduleTable);

    return Os_Hook_CallErrorHook(OSServiceId_StopScheduleTable, ret);
}

/*
********************************************************************************
* Function Name: Os_SchdTb_NextScheduleTable
*
* Explanation: Uses to switch the processing from one schedule table to another
*              schedule table.
*
* Param: scheduleTableID_From: Currently processed schedule table.
*        scheduleTableID_To: Schedule table that provides its series of expiry points.
*
* Retval: E_OS_OK: No error.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_ID: ScheduleTableID_From or ScheduleTableID_To not valid
*         E_OS_NOFUNC: ScheduleTableID_From not started.
*         E_OS_STATE: ScheduleTableID_To is started or next.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.- Given schedule
*                      table's owner application is not accessible.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_SchdTb_NextScheduleTable
(
    ScheduleTableType scheduleTableID_From,
    ScheduleTableType scheduleTableID_To
)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    const Os_SchdTbCfgType* schdTbCfg_From;
    const Os_SchdTbCfgType* schdTbCfg_To;
    Os_Arch_IntState intState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_NextScheduleTable);
    /* Get logic core id */
    coreId = Os_Core_GetLogicId();

#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    if( scheduleTableID_From >= OS_SCHTID_COUNT )
    {
        ret = E_OS_ID;
    }
    else if( scheduleTableID_To >= OS_SCHTID_COUNT )
    {
        ret = E_OS_ID;
    }
    else
#endif
    if( OS_CORE_MASK_INTERRUPT(coreId) ) /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_NEXTSCHTB_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        /* Get alarm configuration data.*/
        schdTbCfg_From = OS_SCHDTB_GETCFG(scheduleTableID_From);
        schdTbCfg_To   = OS_SCHDTB_GETCFG(scheduleTableID_To);

        if( OS_APPMATCH(schdTbCfg_From->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission. */
        {
            ret = E_OS_ACCESS;
        }
        else if( OS_APPMATCH(schdTbCfg_To->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission. */
        {
            ret = E_OS_ACCESS;
        }
        else if( schdTbCfg_From->counter != schdTbCfg_To->counter )
        {
            ret = E_OS_ID;
        }
        else if( schdTbCfg_From->schdTbKind != schdTbCfg_To->schdTbKind )
        {
            ret = E_OS_ID;
        }
        else
        {

#if( OS_CFG_MULTI_CORE == STD_ON )
            if( coreId == OS_SCHDTB_GETCOREID(schdTbCfg_From) )
#endif
            {
                if( OS_APP_STATEOFF(schdTbCfg_From->ownerAppId) ) /* If the application is not accessible. */
                {
                    ret = E_OS_ACCESS;
                }
                else if( OS_APP_STATEOFF(schdTbCfg_To->ownerAppId) ) /* If the application is not accessible. */
                {
                    ret = E_OS_ACCESS;
                }
                else if( (SCHEDULETABLE_STOPPED == schdTbCfg_From->dyn->state) || (SCHEDULETABLE_NEXT == schdTbCfg_From->dyn->state) )
                {
                    ret = E_OS_NOFUNC;
                }
                else if( SCHEDULETABLE_STOPPED != schdTbCfg_To->dyn->state )
                {
                    ret = E_OS_STATE;
                }
                else
                {
                    /* Disable interrupt. */
                    Os_Arch_IntDisable(&intState);
                    Os_SchdTb_NextScheduleTableSimp(schdTbCfg_From, schdTbCfg_To);
                    /* Enable interrupt. */
                    Os_Arch_IntEnable(intState);
                }
            }

#if( OS_CFG_MULTI_CORE == STD_ON )
            else
            {
                /* Set absolute alarm of target core. */
                Os_MultiCoreServeParamType parameter;
                parameter.Os_NextSchdTb.scheduleTableID_From = scheduleTableID_From;
                parameter.Os_NextSchdTb.scheduleTableID_To = scheduleTableID_To;
                /* Execute multi-core calling function. */
                ret = Os_MultiCore_Trigger(TRUE, coreId, OS_SCHDTB_GETCOREID(schdTbCfg_From),
                                           Os_MCServe_NextSchdTb_ID, &parameter);
            }
#endif
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_NextScheduleTable);

    return Os_Hook_CallErrorHook(OSServiceId_NextScheduleTable, ret);
}

/*
********************************************************************************
* Function Name: Os_SchdTb_StartScheduleTableSynchron
*
* Explanation: Uses to start an explicitly synchronized schedule table synchronously.
*
* Param: scheduleTableID: Reference to the schedule table configuration.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_STATE: Schedule table was already started.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.- Given schedule
*                      table's owner application is not accessible.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_SchdTb_StartScheduleTableSynchron(ScheduleTableType scheduleTableID)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    const Os_SchdTbCfgType* schdTbCfg;
    Os_Arch_IntState intState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_StartScheduleTableSynchron);
    /* Get logic core id */
    coreId = Os_Core_GetLogicId();

#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    if( scheduleTableID >= OS_SCHTID_COUNT )
    {
        ret = E_OS_ID;
    }
    else
#endif
    if( OS_CORE_MASK_INTERRUPT(coreId) ) /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_STARTSCHTBSYN_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        /* Get alarm configuration data. */
        schdTbCfg = OS_SCHDTB_GETCFG(scheduleTableID);
        /* Disable interrupt */
        Os_Arch_IntDisable(&intState);
        if( OS_APP_STATEOFF( schdTbCfg->ownerAppId ) )
        {
            ret = E_OS_ACCESS;
        }
        else if( OS_APPMATCH(schdTbCfg->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission. */
        {
            ret = E_OS_ACCESS;
        }
        else if( coreId != OS_SCHDTB_GETCOREID(schdTbCfg) )
        {
            ret = E_OS_CORE;
        }
        else if( OS_SCHDTB_EXPLICIT_KIND != schdTbCfg->schdTbKind )
        {
            ret = E_OS_ID;
        }
        else if( SCHEDULETABLE_STOPPED != schdTbCfg->dyn->state )
        {
            ret = E_OS_STATE;
        }
        else
        {
            Os_SchdTb_InitSimp(schdTbCfg);
            schdTbCfg->dyn->currentExp = schdTbCfg->initExp;
            schdTbCfg->dyn->state = SCHEDULETABLE_WAITING;
        }
        /* Enable interrupt. */
        Os_Arch_IntEnable(intState);
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_StartScheduleTableSynchron);

    return Os_Hook_CallErrorHook(OSServiceId_StartScheduleTableSynchron, ret);
}

/*
********************************************************************************
* Function Name: Os_SchdTb_SyncScheduleTable
*
* Explanation: Uses to provide the schedule table with a synchronization count
*              and start synchronization.
*
* Param: scheduleTableID: Reference to the schedule table configuration.
*        syncValue: The current value of the synchronization counter.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_CORE: Core is not available.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_VALUE: The syncValue is out of range.
*         E_OS_STATE: The state of schedule table <scheduleTableID> is equal
*                     to SCHEDULETABLE_STOPPEDt.
*         E_OS_ACCESS: Caller's access rights are not sufficient.- Given schedule
*                      table's owner application is not accessible.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_SchdTb_SyncScheduleTable
(
    ScheduleTableType scheduleTableID,
    TickType syncValue
)
{
    Os_StatusType ret = E_OS_OK;

    CoreIdType coreId;
    const Os_SchdTbCfgType* schdTbCfg;
    Os_Arch_IntState intState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_SyncScheduleTable);
    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();

#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    if( scheduleTableID >= OS_SCHTID_COUNT )
    {
        ret = E_OS_ID;
    }
    else
#endif
    if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_STARTSCHTBSYN_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        /* Get alarm configuration data. */
        schdTbCfg = OS_SCHDTB_GETCFG(scheduleTableID);

        /* Disable interrupt. */
        Os_Arch_IntDisable(&intState);
        if( OS_APP_STATEOFF( schdTbCfg->ownerAppId ) )
        {
            ret = E_OS_ACCESS;
        }
        else if( OS_APPMATCH(schdTbCfg->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission. */
        {
            ret = E_OS_ACCESS;
        }
        else if( coreId != OS_SCHDTB_GETCOREID(schdTbCfg) )
        {
            ret = E_OS_CORE;
        }
        else if( OS_SCHDTB_EXPLICIT_KIND != schdTbCfg->schdTbKind )
        {
            ret = E_OS_ID;
        }
        else if( SCHEDULETABLE_STOPPED == schdTbCfg->dyn->state )
        {
            ret = E_OS_STATE;
        }
        else if( SCHEDULETABLE_NEXT == schdTbCfg->dyn->state )
        {
            ret = E_OS_STATE;
        }
#if( OS_CFG_SCHDTBSYNC_ENABLE == STD_ON )
        else if( syncValue >= schdTbCfg->duration )
        {
            ret = E_OS_VALUE;
        }
        else
        {
            ret = Os_SchdTb_SyncScheduleTableSimp(schdTbCfg, syncValue);
        }
#else
        else
        {
            ret = E_OS_OK;
        }

        OS_DUMMY_STATEMENT(syncValue);
#endif

        /* Enable interrupt. */
        Os_Arch_IntEnable(intState);
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_SyncScheduleTable);

    return Os_Hook_CallErrorHook(OSServiceId_SyncScheduleTable, ret);
}

/*
********************************************************************************
* Function Name: Os_SchdTb_SetScheduleTableAsync
*
* Explanation: Uses to stop synchronization of a schedule table.
*
* Param: scheduleTableID: Reference to the schedule table configuration.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_STATE: Current state of ScheduleTableID is SCHEDULETABLE_STOPPED,
*                     SCHEDULETABLE_NEXT or SCHEDULETABLE_WAITING.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.- Given schedule
*                      table's owner application is not accessible.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_SchdTb_SetScheduleTableAsync(ScheduleTableType scheduleTableID)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    const Os_SchdTbCfgType* schdTbCfg;
    Os_Arch_IntState intState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_SetScheduleTableAsync);
    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();

#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    if( scheduleTableID >= OS_SCHTID_COUNT )
    {
        ret = E_OS_ID;
    }
    else
#endif
    if( OS_CORE_MASK_INTERRUPT(coreId) ) /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_SETSCHTBASYN_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        /* Get alarm configuration data. */
        schdTbCfg = OS_SCHDTB_GETCFG(scheduleTableID);
        /* Disable interrupt. */
        Os_Arch_IntDisable(&intState);
        if( OS_APP_STATEOFF( schdTbCfg->ownerAppId ) )
        {
            ret = E_OS_ACCESS;
        }
        else if( OS_APPMATCH(schdTbCfg->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission. */
        {
            ret = E_OS_ACCESS;
        }
        else if( coreId != OS_SCHDTB_GETCOREID(schdTbCfg) )
        {
            ret = E_OS_CORE;
        }
        else if( OS_SCHDTB_EXPLICIT_KIND != schdTbCfg->schdTbKind )
        {
           ret = E_OS_ID;
        }
        else if( SCHEDULETABLE_STOPPED == schdTbCfg->dyn->state )
        {
            ret = E_OS_STATE;
        }
        else if( SCHEDULETABLE_NEXT == schdTbCfg->dyn->state )
        {
            ret = E_OS_STATE;
        }
        else if( SCHEDULETABLE_WAITING == schdTbCfg->dyn->state )
        {
            ret = E_OS_STATE;
        }
        else
        {
            if( SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS == schdTbCfg->dyn->state )
            {
                schdTbCfg->dyn->state = SCHEDULETABLE_RUNNING;
#if( OS_CFG_SCHDTBSYNC_ENABLE == STD_ON )
                schdTbCfg->dyn->SyncState = OS_SCHTSYNCSTATUS_NOT_PROVIDED;
#endif
                ret = E_OS_OK;
            }
        }
        /* Enable interrupt. */
        Os_Arch_IntEnable(intState);
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_SetScheduleTableAsync);

    return Os_Hook_CallErrorHook(OSServiceId_SetScheduleTableAsync, ret);
}

/*
********************************************************************************
* Function Name: Os_SchdTb_GetScheduleTableStatus
*
* Explanation: Uses to get the state of a schedule table.
*
* Param: scheduleTableID: Reference to the schedule table configuration.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      - Given schedule table's owner application is not accessible.
*         E_OS_PARAM_POINTER: ScheduleStatus is a pointer to null.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_SchdTb_GetScheduleTableStatus
(
    ScheduleTableType scheduleTableID,
    ScheduleTableStatusRefType scheduleStatus
)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    const Os_SchdTbCfgType* schdTbCfg;
    Os_Arch_IntState intState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_GetScheduleTableStatus);
    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();

#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    if( scheduleTableID >= OS_SCHTID_COUNT )
    {
        ret = E_OS_ID;
    }
    else
#endif
    if( OS_CORE_MASK_INTERRUPT(coreId) ) /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_GETSCHTBSTATUS_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else if( NULL_PTR == scheduleStatus )
    {
        ret = E_OS_PARAM_POINTER;
    }
    else
    {
        /* Get alarm configuration data. */
        schdTbCfg = OS_SCHDTB_GETCFG(scheduleTableID);
        if( OS_APPMATCH(schdTbCfg->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission */
        {
            ret = E_OS_ACCESS;
        }
        else
        {
#if( OS_CFG_MULTI_CORE == STD_ON )
            if( coreId == OS_SCHDTB_GETCOREID(schdTbCfg) )
#endif
            {
                if( OS_APP_STATEOFF(schdTbCfg->ownerAppId) ) /* If the application is not accessible. */
                {
                    ret = E_OS_ACCESS;
                }
                else
                {
                    /* Disable interrupt. */
                    Os_Arch_IntDisable(&intState);
                    Os_SchdTb_GetStatusSimp(schdTbCfg, scheduleStatus);
                    /* Enable interrupt. */
                    Os_Arch_IntEnable(intState);
                }
            }
#if( OS_CFG_MULTI_CORE == STD_ON )
            else
            {
                /* Set absolute alarm of target core. */
                Os_MultiCoreServeParamType parameter;
                parameter.Os_GetSchdTbStatus.scheduleTableID = scheduleTableID;
                /* Execute multi-core calling function. */
                ret = Os_MultiCore_Trigger(TRUE, coreId, OS_SCHDTB_GETCOREID(schdTbCfg),
                                           Os_MCServe_GetSchdTbStatus_ID, &parameter);
                if( E_OS_OK == ret )
                {
                    *scheduleStatus = parameter.Os_GetSchdTbStatus.scheduleStatus;
                }
            }
#endif
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_GetScheduleTableStatus);

    return Os_Hook_CallErrorHook(OSServiceId_GetScheduleTableStatus, ret);
}

#if( OS_CFG_MULTI_CORE == STD_ON )
/*
********************************************************************************
* Function Name: Os_SchdTb_TargetStartScheduleTableRel
*
* Explanation: Multicore function to start the relative schedule table.
*
* Param: scheduleTableID: Reference to the schedule table configuration.
*        offset: Relative value in ticks.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_VALUE: Offset is greater than (OsCounterMaxAllowedValue - InitialOffset)
*                    or is equal to 0.
*         E_OS_STATE: Schedule table was already started.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      - Given schedule table's owner application is not accessible.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_SchdTb_TargetStartScheduleTableRel
(
    ScheduleTableType scheduleTableID,
    TickType offset
)
{
    Os_StatusType ret;
    CoreIdType coreId;
    const Os_SchdTbCfgType* schdTbCfg;

#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    if( scheduleTableID >= OS_SCHTID_COUNT )
    {
        ret = E_OS_ID;
    }
    else
#endif
    {
        /* Get alarm configuration data. */
        schdTbCfg = OS_SCHDTB_GETCFG(scheduleTableID);
        /* Get logic core id */
        coreId = Os_Core_GetLogicId();
        if( coreId == OS_SCHDTB_GETCOREID(schdTbCfg) )
        {
            if( OS_APP_STATEOFF(schdTbCfg->ownerAppId) ) /* If the application is not accessible. */
            {
                ret = E_OS_ACCESS;
            }
            else if( OS_SCHDTB_IMPLICIT_KIND == schdTbCfg->schdTbKind )
            {
                ret = E_OS_ID;
            }
            else if( 0U == offset )
            {
                ret = E_OS_VALUE;
            }
            else if( OS_COUNTER_CHECKINVALIDVALUE(schdTbCfg->counter, schdTbCfg->initExp->nextExpOffset, offset) )
            {
                ret = E_OS_VALUE;
            }
            else if( SCHEDULETABLE_STOPPED != schdTbCfg->dyn->state )
            {
                ret = E_OS_STATE;
            }
            else
            {
                ret = Os_SchdTb_StartRelSimp(schdTbCfg, offset);
            }
        }
        else
        {
            ret = E_OS_CORE;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_SchdTb_TargetStartScheduleTableAbs
*
* Explanation: Multicore function to start the absolute schedule table.
*
* Param: scheduleTableID: Reference to the schedule table configuration.
*        start: Absolute counter tick value at which the schedule table is started.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_STATE: Schedule table was already started.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      - Given schedule table's owner application is not accessible.
*         E_OS_VALUE: Offset is bigger than (OsCounterMaxAllowedValue - InitialOffset)
*                     or is equal to zero
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_SchdTb_TargetStartScheduleTableAbs
(
    ScheduleTableType scheduleTableID,
    TickType start
)
{
    Os_StatusType ret;
    CoreIdType coreId;
    const Os_SchdTbCfgType* schdTbCfg;

#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    if( scheduleTableID >= OS_SCHTID_COUNT )
    {
        ret = E_OS_ID;
    }
    else
#endif
    {
        /* Get alarm configuration data. */
        schdTbCfg = OS_SCHDTB_GETCFG(scheduleTableID);
        /* Get logic core id. */
        coreId = Os_Core_GetLogicId();

        if( coreId == OS_SCHDTB_GETCOREID(schdTbCfg) )
        {
            if( OS_APP_STATEOFF(schdTbCfg->ownerAppId) ) /* If the application is not accessible. */
            {
                ret = E_OS_ACCESS;
            }
            else if( OS_COUNTER_CHECKINVALIDVALUE(schdTbCfg->counter, schdTbCfg->initExp->nextExpOffset, start) )
            {
                ret = E_OS_VALUE;
            }
            else if( SCHEDULETABLE_STOPPED != schdTbCfg->dyn->state )
            {
                ret = E_OS_STATE;
            }
            else
            {
                ret = Os_SchdTb_StartAbsSimp(schdTbCfg, start);
            }
        }
        else
        {
            ret = E_OS_CORE;
        }

    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_SchdTb_TargetStopScheduleTable
*
* Explanation: Multicore function to stop the schedule table.
*
* Param: scheduleTableID: Reference to the schedule table configuration.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_STATE: Schedule table was already stopped.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      - Given schedule table's owner application is not accessible.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_SchdTb_TargetStopScheduleTable(ScheduleTableType scheduleTableID)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    const Os_SchdTbCfgType* schdTbCfg;

#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    if( scheduleTableID >= OS_SCHTID_COUNT )
    {
        ret = E_OS_ID;
    }
    else
#endif
    {
        /* Get alarm configuration data. */
        schdTbCfg = OS_SCHDTB_GETCFG(scheduleTableID);
        /* Get logic core id */
        coreId = Os_Core_GetLogicId();

        if( coreId == OS_SCHDTB_GETCOREID(schdTbCfg) )
        {
            if( OS_APP_STATEOFF(schdTbCfg->ownerAppId) ) /* If the application is not accessible. */
            {
                ret = E_OS_ACCESS;
            }
            else if( SCHEDULETABLE_STOPPED == schdTbCfg->dyn->state )
            {
                ret = E_OS_NOFUNC;
            }
            else
            {
                Os_SchdTb_StopScheduleTableSimp(schdTbCfg);
            }
        }
        else
        {
            ret = E_OS_ID;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_SchdTb_TargetNextScheduleTable
*
* Explanation: Multicore function to switch the processing from one schedule table
*               to another schedule table.
*
* Param: ScheduleTableID_From: Currently processed schedule table.
*        ScheduleTableID_To: Schedule table that provides its series of expiry points.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID_From or ScheduleTableID_To not valid
*         E_OS_NOFUNC: ScheduleTableID_From not started.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      - Given schedule table's owner application is not accessible.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_SchdTb_TargetNextScheduleTable
(
    ScheduleTableType scheduleTableID_From,
    ScheduleTableType scheduleTableID_To
)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    const Os_SchdTbCfgType* schdTbCfg_From;
    const Os_SchdTbCfgType* schdTbCfg_To;

#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    if( scheduleTableID_From >= OS_SCHTID_COUNT )
    {
        ret = E_OS_ID;
    }
    else if( scheduleTableID_To >= OS_SCHTID_COUNT )
    {
        ret = E_OS_ID;
    }
    else
#endif
    {
        /* Get alarm configuration data. */
        schdTbCfg_From = OS_SCHDTB_GETCFG(scheduleTableID_From);
        schdTbCfg_To   = OS_SCHDTB_GETCFG(scheduleTableID_To);
        /* Get logic core id */
        coreId = Os_Core_GetLogicId();
        if( coreId == OS_SCHDTB_GETCOREID(schdTbCfg_From) )
        {
            if( OS_APP_STATEOFF(schdTbCfg_From->ownerAppId) ) /* If the application is not accessible. */
            {
                ret = E_OS_ACCESS;
            }
            else if( OS_APP_STATEOFF(schdTbCfg_To->ownerAppId) ) /* If the application is not accessible. */
            {
                ret = E_OS_ACCESS;
            }
            else if( SCHEDULETABLE_STOPPED != schdTbCfg_From->dyn->state )
            {
                ret = E_OS_NOFUNC;
            }
            else if( SCHEDULETABLE_STOPPED != schdTbCfg_To->dyn->state )
            {
                ret = E_OS_NOFUNC;
            }
            else if( schdTbCfg_From->dyn->state == SCHEDULETABLE_NEXT )
            {
                ret = E_OS_NOFUNC;
            }
            else
            {
                Os_SchdTb_NextScheduleTableSimp(schdTbCfg_From, schdTbCfg_To);
            }
        }
        else
        {
            ret = E_OS_ID;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_SchdTb_TargetGetScheduleTableStatus
*
* Explanation: Multicore function to get the state of a schedule table.
*
* Param: scheduleTableID: Reference to the schedule table configuration.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      - Given schedule table's owner application is not accessible.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_SchdTb_TargetGetScheduleTableStatus
(
    ScheduleTableType scheduleTableID,
    ScheduleTableStatusRefType scheduleStatus
)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    const Os_SchdTbCfgType* schdTbCfg;
#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    if( scheduleTableID >= OS_SCHTID_COUNT )
    {
        ret = E_OS_ID;
    }
    else
#endif
    {
        /* Get alarm configuration data. */
        schdTbCfg = OS_SCHDTB_GETCFG(scheduleTableID);
        /* Get logic core id. */
        coreId = Os_Core_GetLogicId();
        if( coreId == OS_SCHDTB_GETCOREID(schdTbCfg) )
        {
            if( OS_APP_STATEOFF(schdTbCfg->ownerAppId) ) /* If the application is not accessible. */
            {
                ret = E_OS_ACCESS;
            }
            else
            {
                Os_SchdTb_GetStatusSimp(schdTbCfg, scheduleStatus);
            }
        }
        else
        {
            ret = E_OS_CORE;
        }
    }

    return ret;
}
#endif /* OS_CFG_MULTI_CORE == STD_ON */

/*
********************************************************************************
* Function Name: Os_SchdTb_ExpWorkFunc
*
* Explanation: Schedule expiration point handler function.
*
* Param: expListNode: Schedule table expiry point.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SchdTb_ExpWorkFunc
(
    P2CONST(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_CONST) expListNode
)
{
    Os_StatusType ret;
#if( OS_CFG_MULTI_CORE == STD_ON )
    CoreIdType coreId;
#endif
    Os_ObjIdxType taskIdx;
#if( OS_CFG_EVENT_ENABLE == STD_ON )
    Os_ObjIdxType evenIdx;
#endif/* OS_CFG_EVENT_ENABLE == STD_ON */
    const Os_TaskCfgType* taskCfg;

    for( taskIdx = 0U; taskIdx < expListNode->workParam.schdTbParam->taskCnt; taskIdx++ )
    {
        taskCfg = OS_TASK_GETCFG(expListNode->workParam.schdTbParam->taskId[taskIdx]);
#if( OS_CFG_MULTI_CORE == STD_ON )
        /* Get logic core id. */
        coreId = Os_Core_GetLogicId();
         /* If the activate task is the same core. */
        if( coreId == OS_TASK_GETCOREID(taskCfg) )
#endif
        {
            /* Activate the configured task. */
            ret = Os_Task_ActivateTaskSimp(taskCfg);
        }

#if( OS_CFG_MULTI_CORE == STD_ON )
        else
        {
            Os_MultiCoreServeParamType parameter;
            parameter.Os_ActivateTask.taskId = expListNode->workParam.schdTbParam->taskId[taskIdx];
            /* Execute multi-core calling function. */
            ret = Os_MultiCore_Trigger(FALSE, coreId, OS_TASK_GETCOREID(taskCfg),
                                       Os_MCServe_ActivateTask_ID, &parameter);
        }
#endif
        (void)Os_Hook_CallErrorHook(OSServiceId_ActivateTask, ret);
    }
#if( OS_CFG_EVENT_ENABLE == STD_ON )
    for( evenIdx = 0U; evenIdx < expListNode->workParam.schdTbParam->eventCnt; evenIdx++ )
    {
        taskCfg = OS_TASK_GETCFG(expListNode->workParam.schdTbParam->event[evenIdx].taskId);
#if( OS_CFG_MULTI_CORE == STD_ON )
        /* Get logic core id. */
        coreId = Os_Core_GetLogicId();
        /* If the activate task is the same core. */
        if( coreId == OS_TASK_GETCOREID(taskCfg) )
#endif
        {
            ret = Os_Event_SetEventSimp(taskCfg, expListNode->workParam.schdTbParam->event[evenIdx].eventMask);
            if( E_OS_OK == ret )
            {
                ret = Os_Task_SetEventTaskSimp(taskCfg);
            }
        }
#if( OS_CFG_MULTI_CORE == STD_ON )
        else
        {
            Os_MultiCoreServeParamType parameter;
            parameter.Os_SetEvent.taskId = expListNode->workParam.schdTbParam->event[evenIdx].taskId;
            parameter.Os_SetEvent.mask = expListNode->workParam.schdTbParam->event[evenIdx].eventMask;
            /* Execute multi-core calling function. */
            ret = Os_MultiCore_Trigger(FALSE, coreId, OS_TASK_GETCOREID(taskCfg),
                                       Os_MCServe_SetEvent_ID, &parameter);
        }
#endif
        (void)Os_Hook_CallErrorHook(OSServiceId_SetEvent, ret);
    }
#endif/* OS_CFG_EVENT_ENABLE == STD_ON */
}

/*
********************************************************************************
* Function Name: Os_SchdTb_ActStandardExe
*
* Explanation: Execute standard schedule table action.
*
* Param: expListNode: Schedule table expiry point.
*
* Retval: setNextPointFlag: Next expiry point flag.
********************************************************************************
*/
FUNC(uint8, OS_CODE) Os_SchdTb_ActStandardExe
(
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) expListNode
)
{
    Os_CntExpListNodeCfgType* nextExpNode;
    Os_SchdTbExpCfgType* currentSchdTbExp;
    uint8 setNextPointFlag = OS_COUNTER_NOTSET_POINT;

    Os_ParamCheck(NULL_PTR != expListNode);
    currentSchdTbExp = (Os_SchdTbExpCfgType*)expListNode;
    Os_ParamCheck(NULL_PTR != currentSchdTbExp->nextExp);

    /* Schedule expiration point handler function. */
    Os_SchdTb_ExpWorkFunc(expListNode);

    currentSchdTbExp->schdTbDyn->currentExp = currentSchdTbExp;
    nextExpNode = &currentSchdTbExp->nextExp->expNode;
    nextExpNode->workParam.schdTbParam = currentSchdTbExp->nextExp->schdTbParam;
    /* Insert expiry point into counter. */
    Os_Counter_SetExpPoint(currentSchdTbExp->counter,
                           expListNode->expTimestamp.timebase,
                           currentSchdTbExp->nextExpOffset,
                           nextExpNode);
    setNextPointFlag = OS_COUNTER_SET_POINT;

    return setNextPointFlag;
}

/*
********************************************************************************
* Function Name: Os_SchdTb_ActSyncExe
*
* Explanation: Execute synchronous schedule table action.
*
* Param: expListNode: Schedule table expiry point.
*
* Retval: setNextPointFlag: Next expiry point flag.
********************************************************************************
*/
FUNC(uint8, OS_CODE) Os_SchdTb_ActSyncExe
(
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) expListNode
)
{
    uint8 setNextPointFlag = OS_COUNTER_NOTSET_POINT;

#if( OS_CFG_SCHDTBSYNC_ENABLE == STD_ON )
    Os_TickType syscOffset;
    Os_TickType nextOffset;
    const Os_SchdTbCfgType* schdTbCfg;
    Os_CntExpListNodeCfgType* nextExpNode;
    Os_ParamCheck(NULL_PTR != expListNode);
    Os_SchdTbExpCfgType* currentSchdTbExp = (Os_SchdTbExpCfgType*)expListNode;
    Os_ParamCheck(NULL_PTR != currentSchdTbExp->nextExp);

    /* Schedule expiration point handler function. */
    Os_SchdTb_ExpWorkFunc(expListNode);

    schdTbCfg = OS_SCHDTB_GETCFG(currentSchdTbExp->schdTbDyn->schdTbId);
    currentSchdTbExp->schdTbDyn->currentExp = currentSchdTbExp;
    nextExpNode = &currentSchdTbExp->nextExp->expNode;
    nextExpNode->workParam.schdTbParam = currentSchdTbExp->nextExp->schdTbParam;
    syscOffset = Os_SchdTb_SyncParam(schdTbCfg, currentSchdTbExp->nextExp);
    nextOffset = currentSchdTbExp->nextExpOffset + syscOffset;
    /* Insert expiry point into counter. */
    Os_Counter_SetExpPoint(currentSchdTbExp->counter,
                           expListNode->expTimestamp.timebase,
                           nextOffset,
                           nextExpNode);
    setNextPointFlag = OS_COUNTER_SET_POINT;
#else
    OS_DUMMY_STATEMENT(expListNode);
#endif

    return setNextPointFlag;
}

/*
********************************************************************************
* Function Name: Os_SchdTb_ActCyclicExe
*
* Explanation: Execute cyclic schedule table action.
*
* Param: expListNode: Schedule table expiry point.
*
* Retval: setNextPointFlag: Next expiry point flag.
********************************************************************************
*/
FUNC(uint8, OS_CODE) Os_SchdTb_ActCyclicExe
(
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) expListNode
)
{
    Os_TickType nextExpOffset;
    Os_CntExpListNodeCfgType* nextInitExpNode;
    Os_SchdTbExpCfgType* currentSchdTbExp;
    Os_SchdTbDynType* currentSchdTbDyn;
    const Os_SchdTbCfgType* currentSchdCfg;
    Os_SchdTbDynType* nextSchdTbDyn;
    const Os_SchdTbCfgType* nextSchdCfg;
    uint8 setNextPointFlag = OS_COUNTER_NOTSET_POINT;

    Os_ParamCheck(NULL_PTR != expListNode);

    /* Schedule expiration point handler function. */
    Os_SchdTb_ExpWorkFunc(expListNode);

    currentSchdTbExp = (Os_SchdTbExpCfgType*)expListNode;
    currentSchdCfg = OS_SCHDTB_GETCFG(currentSchdTbExp->schdTbDyn->schdTbId);
    currentSchdTbDyn = currentSchdCfg->dyn;
    currentSchdTbDyn->currentExp = currentSchdTbExp;

    Os_ParamCheck(NULL_PTR != currentSchdCfg);
    Os_ParamCheck(NULL_PTR != currentSchdTbDyn->next);

    if( currentSchdCfg != currentSchdTbDyn->next )
    {
        nextSchdCfg = currentSchdTbDyn->next;
        currentSchdTbDyn->state = SCHEDULETABLE_STOPPED;
        Os_SchdTb_InitSimp(nextSchdCfg);
        nextSchdTbDyn = nextSchdCfg->dyn;
        nextExpOffset = currentSchdTbExp->nextExpOffset + nextSchdCfg->initOffset;

        nextSchdTbDyn->state = SCHEDULETABLE_RUNNING;
        /* After the loop table ends, it needs to link the next pointer to its own table. */
        currentSchdCfg->dyn->next = currentSchdCfg;
    }
    else
    {
        nextSchdCfg = currentSchdCfg;

#if( OS_CFG_SCHDTBSYNC_ENABLE == STD_ON )
        Os_TickType syscOffset = 0U;
        if( OS_SCHDTB_EXPLICIT_KIND == nextSchdCfg->schdTbKind )
        {
            syscOffset = Os_SchdTb_SyncParam(nextSchdCfg, nextSchdCfg->initExp);
        }
        nextExpOffset = currentSchdTbExp->nextExpOffset + nextSchdCfg->initOffset + syscOffset;
#else
        nextExpOffset = currentSchdTbExp->nextExpOffset + nextSchdCfg->initOffset;
#endif

    }

    nextInitExpNode = &nextSchdCfg->initExp->expNode;
    nextInitExpNode->workParam.schdTbParam = nextSchdCfg->initExp->schdTbParam;
    /* Insert expiry point into counter. */
    Os_Counter_SetExpPoint(nextSchdCfg->counter,
                           expListNode->expTimestamp.timebase,
                           nextExpOffset,
                           nextInitExpNode);
    setNextPointFlag = OS_COUNTER_SET_POINT;

    return setNextPointFlag;
}

/*
********************************************************************************
* Function Name: Os_SchdTb_ActSingleExe
*
* Explanation: Execute single schedule table action.
*
* Param: expListNode: Schedule table expiry point.
*
* Retval: setNextPointFlag: Next expiry point flag.
********************************************************************************
*/
FUNC(uint8, OS_CODE) Os_SchdTb_ActSingleExe
(
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) expListNode
)
{
    Os_SchdTbDynType* currentSchdTbDyn;
    const Os_SchdTbExpCfgType* currentSchdTbExp;
    uint8 setNextPointFlag;

    Os_ParamCheck(NULL_PTR != expListNode);

    /* Schedule expiration point handler function. */
    Os_SchdTb_ExpWorkFunc(expListNode);

    currentSchdTbExp = (const Os_SchdTbExpCfgType*)expListNode;
    currentSchdTbDyn = currentSchdTbExp->schdTbDyn;
    if( NULL_PTR != currentSchdTbDyn->next )
    {
        setNextPointFlag = Os_SchdTb_ActCyclicExe(expListNode);
        /* After the single table ends, it needs to link the next pointer NULL_PTR. */
        currentSchdTbDyn->next = NULL_PTR;
    }
    else
    {
        currentSchdTbDyn->state = SCHEDULETABLE_STOPPED;
        Os_Counter_SetNextPoint (currentSchdTbExp->counter, expListNode->expTimestamp.timebase);
        setNextPointFlag = OS_COUNTER_SET_POINT;
    }

    return setNextPointFlag;
}

/*
********************************************************************************
* Function Name: StartScheduleTableRel
*
* Explanation: Standard API function, Uses to start the relative schedule table.
*
* Param: ScheduleTableID: Reference to the schedule table configuration.
*        Offset: Relative value in ticks.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_VALUE: Offset is greater than (OsCounterMaxAllowedValue - InitialOffset)
*                    or is equal to 0.
*         E_OS_STATE: Schedule table was already started.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      - Given schedule table's owner application is not accessibl
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) StartScheduleTableRel
(
    ScheduleTableType ScheduleTableID,
    TickType Offset
)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;

    sysCallParam.Os_StartScheduleTableRel.scheduleTableID = ScheduleTableID;
    sysCallParam.Os_StartScheduleTableRel.offset = Offset;
    Os_SysCall(Os_Syscall_StartScheduleTableRel_ID, &sysCallParam);
    ret = sysCallParam.Os_StartScheduleTableRel.retVal;
#else
    ret = Os_SchdTb_StartScheduleTableRel(ScheduleTableID, Offset);
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: StartScheduleTableAbs
*
* Explanation: Standard API function, Uses to start the absolute schedule table.
*
* Param: ScheduleTableID: Reference to the schedule table configuration.
*        Start: Absolute counter tick value at which the schedule table is started.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_VALUE: Start is greater than OsCounterMaxAllowedValue.
*         E_OS_STATE: Schedule table was already started.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      - Given schedule table's owner application is not accessible.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) StartScheduleTableAbs
(
    ScheduleTableType ScheduleTableID,
    TickType Start
)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;

    sysCallParam.Os_StartScheduleTableAbs.scheduleTableID = ScheduleTableID;
    sysCallParam.Os_StartScheduleTableAbs.start = Start;
    Os_SysCall(Os_Syscall_StartScheduleTableAbs_ID, &sysCallParam);
    ret = sysCallParam.Os_StartScheduleTableAbs.retVal;
#else
    ret = Os_SchdTb_StartScheduleTableAbs(ScheduleTableID, Start);
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: StopScheduleTable
*
* Explanation: Standard API function, Uses to stop the  schedule table.
*
* Param: ScheduleTableID: Reference to the schedule table configuration.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      - Given schedule table's owner application is not accessible.
*         E_OS_CORE: Core is not available.
*         E_OS_NOFUNC: The schedule table was already stopped.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) StopScheduleTable(ScheduleTableType ScheduleTableID)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;

    sysCallParam.Os_StopScheduleTable.scheduleTableID = ScheduleTableID;
    Os_SysCall(Os_Syscall_StopScheduleTable_ID, &sysCallParam);
    ret = sysCallParam.Os_StopScheduleTable.retVal;
#else
    ret = Os_SchdTb_StopScheduleTable(ScheduleTableID);
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: NextScheduleTable
*
* Explanation: Standard API function, Uses to switch the processing from one
*              schedule table to another schedule table.
*
* Param: ScheduleTableID_From: Currently processed schedule table.
*        ScheduleTableID_To: Schedule table that provides its series of expiry points.
*
* Retval: E_OS_OK: No error.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_ID: ScheduleTableID_From or ScheduleTableID_To not valid
*         E_OS_NOFUNC: ScheduleTableID_From not started.
*         E_OS_STATE: ScheduleTableID_To is started or next.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      - Given schedule table's owner application is not accessible.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) NextScheduleTable
(
    ScheduleTableType ScheduleTableID_From,
    ScheduleTableType ScheduleTableID_To
)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;

    sysCallParam.Os_NextScheduleTable.scheduleTableID_From = ScheduleTableID_From;
    sysCallParam.Os_NextScheduleTable.scheduleTableID_To = ScheduleTableID_To;
    Os_SysCall(Os_Syscall_NextScheduleTable_ID, &sysCallParam);
    ret = sysCallParam.Os_NextScheduleTable.retVal;
#else
    ret = Os_SchdTb_NextScheduleTable(ScheduleTableID_From, ScheduleTableID_To);
#endif

    return ret;
}

#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
/*
********************************************************************************
* Function Name: StartScheduleTableSynchron
*
* Explanation: Standard API function, Uses to start an explicitly synchronized
*              schedule table synchronously.
*
* Param: ScheduleTableID: Reference to the schedule table configuration.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_STATE: Schedule table was already started.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      - Given schedule table's owner application is not accessible.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) StartScheduleTableSynchron(ScheduleTableType ScheduleTableID)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;

    sysCallParam.Os_StartScheduleTableSynchron.scheduleTableID = ScheduleTableID;
    Os_SysCall(Os_Syscall_StartScheduleTableSynchron_ID, &sysCallParam);
    ret = sysCallParam.Os_StartScheduleTableSynchron.retVal;
#else
    ret = Os_SchdTb_StartScheduleTableSynchron(ScheduleTableID);
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: SyncScheduleTable
*
* Explanation: Standard API function, Uses to provide the schedule table with
*              a synchronization count and start synchronization.
*
* Param: ScheduleTableID: Reference to the schedule table configuration.
*        Value: The current value of the synchronization counter.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_CORE: Core is not available.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_VALUE: The syncValue is out of range.
*         E_OS_STATE: The state of schedule table <scheduleTableID> is equal
*                     to SCHEDULETABLE_STOPPEDt.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      - Given schedule table's owner application is not accessible.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) SyncScheduleTable(ScheduleTableType ScheduleTableID, TickType Value)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;

    sysCallParam.Os_SyncScheduleTable.scheduleTableID = ScheduleTableID;
    sysCallParam.Os_SyncScheduleTable.value = Value;
    Os_SysCall(Os_Syscall_SyncScheduleTable_ID, &sysCallParam);
    ret = sysCallParam.Os_SyncScheduleTable.retVal;
#else
    ret = Os_SchdTb_SyncScheduleTable(ScheduleTableID, Value);
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: SetScheduleTableAsync
*
* Explanation: Standard API function, Uses to stop synchronization of a schedule table.
*
* Param: ScheduleTableID: Reference to the schedule table configuration.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_STATE: Current state of ScheduleTableID is SCHEDULETABLE_STOPPED,
*                     SCHEDULETABLE_NEXT or SCHEDULETABLE_WAITING.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      - Given schedule table's owner application is not accessible.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) SetScheduleTableAsync(ScheduleTableType ScheduleTableID)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;

    sysCallParam.Os_SetScheduleTableAsync.scheduleTableID = ScheduleTableID;
    Os_SysCall(Os_Syscall_SetScheduleTableAsync_ID, &sysCallParam);
    ret = sysCallParam.Os_SetScheduleTableAsync.retVal;
#else
    ret = Os_SchdTb_SetScheduleTableAsync(ScheduleTableID);
#endif

    return ret;
}
#endif /* ( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) ) */

/*
********************************************************************************
* Function Name: GetScheduleTableStatus
*
* Explanation: Standard API function, Uses to get the state of a schedule table.
*
* Param: ScheduleTableID: Reference to the schedule table configuration.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      - Given schedule table's owner application is not accessible.
*         E_OS_PARAM_POINTER: ScheduleStatus is a pointer to null.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) GetScheduleTableStatus
(
    ScheduleTableType ScheduleTableID,
    ScheduleTableStatusRefType ScheduleStatus
)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;

    sysCallParam.Os_GetScheduleTableStatus.scheduleTableID = ScheduleTableID;
    sysCallParam.Os_GetScheduleTableStatus.scheduleStatus = ScheduleStatus;
    Os_SysCall(Os_Syscall_GetScheduleTableStatus_ID, &sysCallParam);
    ret = sysCallParam.Os_GetScheduleTableStatus.retVal;
#else
    ret = Os_SchdTb_GetScheduleTableStatus(ScheduleTableID, ScheduleStatus);
#endif

    return ret;
}
#endif /* OS_CFG_SCHDTB_ENABLE == STD_ON */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

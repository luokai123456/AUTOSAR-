/*
********************************************************************************
*
*  File name: Os_Monitor.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: lixing/2022.08.30
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: liG/2023.02.6
* Change: Adapt to the refactor OS.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: liG/2023.04.14
* Change: Using valid macros.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: LiuJJ/2023.04.26
* Change: Solve ISR RunTime and RunTime_Max calculate error.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: LiuJJ/2023.05.05
* Change: Solve ISR interrupted RunTime calculate error.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: LiuJJ/2023.05.05
* Change: Macro written backwards.
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2023.05.05
* Change: Variable position adjustment.
* Cause: Bugfix
********************************************************************************
* Version: 3.7
* Author/Date: LiG/2023.6.8
* Change: Resolve timer flipping issue.
* Cause: Bugfix
********************************************************************************
* Version: 3.8
* Author/Date: LiG/2023.6.8
* Change: Multicore problem.
* Cause: Bugfix
********************************************************************************
* Version: 3.9
* Author/Date: LiG/2023.6.9
* Change: Coding specification.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: LiG/2023.6.9
* Change: Compiler Warning.
* Cause: Optimize
********************************************************************************
* Version: 3.11
* Author/Date: LiG/2023.10.24
* Change: Add monitor module SC3 interface.
* Cause: Bugfix
********************************************************************************
* Version: 3.12
* Author/Date: LiG/2023.10.24
* Change: Add header file.
* Cause: Bugfix
********************************************************************************
* Version: 3.13
* Author/Date: ZhangY/2023.10.07
* Change: E_OK change to E_OS_OK.
* Cause: Optimization
********************************************************************************
* Version: 3.14
* Author/Date: LiG/2023.3.15
* Change: Obtain TaskID using Os internal interface.
* Cause: Bugfix
********************************************************************************
* Version: 3.15
* Author/Date: LiG/2023.3.15
* Change: 1.Modify the issue of displaying maximum runtime values.
*         2.Modifying InitTask to not display runtime issues.
*         3.The modification task was interrupted and the running time displayed
*         incorrectly.
*         4.Add Task Run Deviation Function.
*         5.Remove redundant code.
* Cause: Bugfix
********************************************************************************
* Version: 3.16
* Author/Date: LiG/2024.4.7
* Change: Modifying static code check issues.
* Cause: Optimize
********************************************************************************
* Version: 3.17
* Author/Date: LiG/2024.5.22
* Change: Modify the assignment of initialization flags.
* Cause: Bugfix
********************************************************************************
* Version: 3.18
* Author/Date: LiuZB/2025.2.21
* Change: Compiler Warning.
* Cause: Optimize
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Monitor_Cfg.h"
#include "Os_Monitor.h"
#include "Os_Task_Types.h"
#include "Os_Counter.h"
#include "Os_SysCall.h"
#include "Os_SysCall_Types.h"
#include "Os_Core.h"
#if( OS_MONITOR_ENABLE == STD_ON )

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
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
/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define OS_START_SEC_GLOBAL_NOCACHE_VAR
#include "Os_MemMap.h"
static VAR(uint32, OS_VAR_INIT) RunTime_Max_init;
static VAR(boolean, OS_VAR_INIT) Os_Monitor_Init_status;
static VAR(TaskType, OS_VAR_INIT) Os_Monitor_CoreRunTask[OS_COREID_COUNT];
static VAR(ISRType, OS_VAR_INIT) Isr_Queue[OS_MONITOR_ISR_NEST_NUM][OS_COREID_COUNT];
static VAR(uint8, OS_VAR_INIT) Os_Monitor_IsrInterruptFlag[OS_COREID_COUNT];
static VAR(uint32, OS_VAR_INIT)  Pre_IsrQnum[OS_COREID_COUNT];
static VAR(boolean, OS_VAR_INIT) Os_Monitor_Cat2Interrupttotask[OS_COREID_COUNT];
VAR(ISRType, OS_VAR_INIT) Os_Monitor_CoreRunIsr[OS_COREID_COUNT];
VAR(boolean, OS_VAR_INIT) Os_Monitor_TaskTerminateFlag[OS_TASKID_COUNT];
VAR(Os_Monitor_CoreCpuloadType_st, OS_VAR_INIT) Os_Monitor_CpuLoadkPara[OS_COREID_COUNT];
VAR(Os_Monitor_TaskStackType_st, OS_VAR_INIT) Os_Monitor_TaskStackPara[OS_TASKID_COUNT];
VAR(Os_Monitor_IsrStackType_st, OS_VAR_INIT) Os_Monitor_IsrStackPara[OS_ISRID_COUNT];
#define OS_STOP_SEC_GLOBAL_NOCACHE_VAR
#include "Os_MemMap.h"

#define OS_START_SEC_GLOBAL_NOCACHE_INITVAR
#include "Os_MemMap.h"
static VAR(ISRType, OS_VAR_INIT) Last_isrId = INVALID_ISR;
#define OS_STOP_SEC_GLOBAL_NOCACHE_INITVAR
#include "Os_MemMap.h"

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*
*******************************************************************************
* Function Name: Os_Monitor_init
*
* Explanation: Get task configuration information and initialization structure.
*
* Param: None
*
* Retval: None
*******************************************************************************
*/
FUNC(void, OS_CODE) Os_Monitor_init(void)
{
    Os_TaskDynType *taskDyn = NULL_PTR;
    uint8 taskIndex = 0U;
    uint8 coreIndex = 0U;
    uint8 isrIndex = 0U;

    for( coreIndex = 0U; coreIndex < (uint8)OS_COREID_COUNT; coreIndex++ )
    {
        for( isrIndex = 0U; isrIndex < (uint8)OS_MONITOR_ISR_NEST_NUM; isrIndex++ )
        {
            Isr_Queue[isrIndex][coreIndex] = INVALID_ISR;
        }
    }
    for( taskIndex = 0U; taskIndex < (uint8)OS_TASKID_COUNT; taskIndex++ )
    {
        Os_Monitor_TaskStackPara[taskIndex].RunTime_Max = 0U;
        Os_Monitor_TaskStackPara[taskIndex].TimeFrame = 0U;
        Os_Monitor_TaskStackPara[taskIndex].TimeFrameMax = 0U;
        Os_Monitor_TaskStackPara[taskIndex].TimeFrameMin = MONITOR_MAX_VALUE;
        Os_Monitor_TaskStackPara[taskIndex].TaskId = Os_TaskCfgData[taskIndex]->taskId;
        Os_Monitor_TaskStackPara[taskIndex].HomePriority = Os_TaskCfgData[taskIndex]->cfgPrio;

        taskDyn = (Os_TaskDynType *)Os_TaskCfgData[taskIndex]->taskDyn;
        Os_Monitor_TaskStackPara[taskIndex].Priority = taskDyn->currentPrio;
    }
    for( coreIndex = 0U; coreIndex < (uint8)OS_COREID_COUNT; coreIndex++ )
    {
        Os_Monitor_CpuLoadkPara[coreIndex].CoreStartRunTime = (uint32)Os_Counter_GetCntValue(Os_CounterCfgData[Os_Monitor_CoreUseCounterIndex[coreIndex]]);
        Os_Monitor_TaskStackPara[Os_Monitor_CoreidleTaskMapping[coreIndex]].StartResumesTime = Os_Monitor_CpuLoadkPara[coreIndex].CoreStartRunTime;
        Os_Monitor_TaskStackPara[Os_Monitor_CoreidleTaskMapping[coreIndex]].TimeSum = 0U;
        if( (uint8)Os_Monitor_CoreRunTask[coreIndex] != 0U )
        {
            Os_Monitor_TaskStackPara[Os_Monitor_CoreRunTask[coreIndex]].StartResumesTime = Os_Monitor_CpuLoadkPara[coreIndex].CoreStartRunTime;
        }
    }
    for( isrIndex = 0U; isrIndex < (uint8)OS_ISRID_COUNT; isrIndex++ )
    {
        Os_Monitor_IsrStackPara[isrIndex].RunTime_Max = 0U;
        Os_Monitor_IsrStackPara[isrIndex].Id = Os_IsrCfgData[isrIndex]->isrId;
        Os_Monitor_IsrStackPara[isrIndex].Source.level = Os_IsrCfgData[isrIndex]->source->level;
        Os_Monitor_IsrStackPara[isrIndex].Source.number = Os_IsrCfgData[isrIndex]->source->number;
    }
    Os_Monitor_Init_status = TRUE;
    RunTime_Max_init = MONITOR_FLAGVALUE;
}

/*
*******************************************************************************
* Function Name: Os_Monitor_GetCpuLoad
*
* Explanation: Used for load calculation.
*
* Param: None
*
* Retval: None
*******************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Monitor_GetCpuLoad(void)
{
    uint32 currentTimeData = MONITOR_VALUE_ZERO;
    uint32 useTime = MONITOR_VALUE_ZERO;
    uint8 coreIndex = MONITOR_VALUE_ZERO;
    uint8 taskIndex = MONITOR_VALUE_ZERO;
    uint8 isrIndex = MONITOR_VALUE_ZERO;

    for( coreIndex = 0U; coreIndex < (uint8)OS_COREID_COUNT; coreIndex++ )
    {
        currentTimeData = (uint32)Os_Counter_GetCntValue(Os_CounterCfgData[Os_Monitor_CoreUseCounterIndex[coreIndex]]);
        useTime = currentTimeData - (uint32)Os_Monitor_CpuLoadkPara[coreIndex].CoreStartRunTime;

        Os_Monitor_CpuLoadkPara[coreIndex].Cpuload =((float32)(useTime - Os_Monitor_TaskStackPara[Os_Monitor_CoreidleTaskMapping[coreIndex]].TimeSum)/(useTime))*MONITOR_COUNTDATA;

        Os_Monitor_CpuLoadkPara[coreIndex].CoreStartRunTime = currentTimeData;
        Os_Monitor_TaskStackPara[Os_Monitor_CoreidleTaskMapping[coreIndex]].TimeSum = MONITOR_VALUE_ZERO;
    }
    for( taskIndex = 0U; taskIndex < (uint8)OS_TASKID_COUNT; taskIndex++ )
    {
        Os_Monitor_TaskStackPara[taskIndex].CpuLoad = ((float32)(Os_Monitor_TaskStackPara[taskIndex].TimeSum)/(useTime))*MONITOR_COUNTDATA;
        Os_Monitor_TaskStackPara[taskIndex].TimeSum = MONITOR_VALUE_ZERO;
        Os_Monitor_TaskStackPara[taskIndex].TimeSum_last = MONITOR_VALUE_ZERO;
    }
    for( isrIndex = 0U; isrIndex < (uint8)OS_ISRID_COUNT; isrIndex++ )
    {
        Os_Monitor_IsrStackPara[isrIndex].CpuLoad = ((float32)(Os_Monitor_IsrStackPara[isrIndex].TimeSum)/(useTime))*MONITOR_COUNTDATA;
        Os_Monitor_IsrStackPara[isrIndex].TimeSum = MONITOR_VALUE_ZERO;
        Os_Monitor_IsrStackPara[isrIndex].TimeSum_last = MONITOR_VALUE_ZERO;
        Os_Monitor_IsrStackPara[isrIndex].RunTime[0] = MONITOR_VALUE_ZERO;
        Os_Monitor_IsrStackPara[isrIndex].RunTime[1] = MONITOR_VALUE_ZERO;
    }
}

/*
*******************************************************************************
* Function Name: Os_Monitor_MainFunction
*
* Explanation: Module main function,count average execution time, stack, cpu load.
*
* Param: None
*
* Retval: None
*******************************************************************************
*/
FUNC(void, OS_CODE) Os_Monitor_MainFunction(void)
{
    Os_Monitor_GetCpuLoad ();
}

/*
*******************************************************************************
* Function Name: Os_Monitor_TaskRecordTime
*
* Explanation: Standard task time record.
*
* Param: TaskID: task id,CoreId:core id,TicksCount:This execution time.
*
* Retval: None
*******************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Monitor_TaskRecordTime
(
    TaskType taskID
)
{
    uint32 recordTime = Os_Monitor_TaskStackPara[taskID].TimeSum - Os_Monitor_TaskStackPara[taskID].TimeSum_last;

    Os_Monitor_TaskStackPara[taskID].TimeSum_last = Os_Monitor_TaskStackPara[taskID].TimeSum;

    if( Os_Monitor_TaskStackPara[taskID].RunTimenum < OS_MONITOR_BUFFSIZE )
    {
        Os_Monitor_TaskStackPara[taskID].RunTime[Os_Monitor_TaskStackPara[taskID].RunTimenum] = recordTime;
        Os_Monitor_TaskStackPara[taskID].TimeSum = MONITOR_VALUE_ZERO;
        Os_Monitor_TaskStackPara[taskID].RunTimenum++;
    }
    else
    {
        Os_Monitor_TaskStackPara[taskID].RunTime[OS_MONITOR_BUFFSIZE-MONITOR_BLANKBUFF] += recordTime;
    }

    if( (RunTime_Max_init == MONITOR_FLAGVALUE) &&
        (Os_Monitor_TaskStackPara[taskID].RunTime_Max < recordTime) &&
        (recordTime < MONITOR_LIMIT) )
    {
        Os_Monitor_TaskStackPara[taskID].RunTime_Max = recordTime;
    }
}

/*
*******************************************************************************
* Function Name: Os_Monitor_CounterSub
*
* Explanation: Calculate the difference between two times.
*
* Param: Counter: Counter's configuration.
*        Value: Current value.
*        Sub: Last value.
*
* Retval: None
*******************************************************************************
*/
static FUNC(Os_TickType, OS_CODE) Os_Monitor_CounterSub
(
    P2CONST(Os_CounterBaseCfgType, AUTOMATIC, OS_CONST) counter,
    Os_TickType value,
    Os_TickType sub
)
{
    Os_TickType result;

    /* Perform the operation */
    result = value - sub;

    /* Perform modulo. */
    if( value < sub )
    {
        result += (counter->maxAllowValue + 1U);
    }

    return result;
}

/*
*******************************************************************************
* Function Name: Os_Monitor_StartTimeDeal
*
* Explanation: Processing task start time.
*
* Param: None
*
* Retval: None
*******************************************************************************
*/
FUNC(void, OS_CODE) Os_Monitor_StartTimeDeal(void)
{
    TaskType taskID = INVALID_TASK;
    CoreIdType coreId = OS_CORE_ID_MASTER;
    uint32 ticksCount = MONITOR_VALUE_ZERO;
    uint32 currentTick = MONITOR_VALUE_ZERO;

    coreId = Os_Core_GetLogicId();
    taskID = (TaskType)OS_CORE_GETCURRENTTASKID(coreId);
    if( TRUE == Os_Monitor_Init_status )
    {
        if( MONITOR_FLAGVALUE == Os_Monitor_IsrInterruptFlag[coreId] )
        {
            currentTick = (uint32)Os_Counter_GetCntValue(Os_CounterCfgData[Os_Monitor_CoreUseCounterIndex[coreId]]);
            ticksCount = (uint32)Os_Monitor_CounterSub(Os_CounterCfgData[Os_Monitor_CoreUseCounterIndex[coreId]], currentTick,
                    Os_Monitor_TaskStackPara[Os_Monitor_CoreRunTask[coreId]].StartResumesTime);

            Os_Monitor_TaskStackPara[Os_Monitor_CoreRunTask[coreId]].TimeSum += ticksCount;
        }
        else
        {
            if( MONITOR_VALUE_ZERO == Os_Monitor_IsrInterruptFlag[coreId] )
            {
                Os_Monitor_CoreRunTask[coreId] = (TaskType) taskID;
                currentTick = (uint32)Os_Counter_GetCntValue(Os_CounterCfgData[Os_Monitor_CoreUseCounterIndex[coreId]]);
                Os_Monitor_TaskStackPara[taskID].StartResumesTime = currentTick;
                if( TRUE == Os_Monitor_TaskTerminateFlag[taskID])
                {
                    Os_Monitor_TaskStackPara[taskID].RunTime[0U] = 0U;
                    Os_Monitor_TaskStackPara[taskID].TimeFrame = currentTick - Os_Monitor_TaskStackPara[taskID].EndTime;
                    if( Os_Monitor_TaskStackPara[taskID].TimeFrame > Os_Monitor_TaskStackPara[taskID].TimeFrameMax )
                    {
                        Os_Monitor_TaskStackPara[taskID].TimeFrameMax = Os_Monitor_TaskStackPara[taskID].TimeFrame;
                    }
                    if( Os_Monitor_TaskStackPara[taskID].TimeFrame < Os_Monitor_TaskStackPara[taskID].TimeFrameMin )
                    {
                        Os_Monitor_TaskStackPara[taskID].TimeFrameMin = Os_Monitor_TaskStackPara[taskID].TimeFrame;
                    }
                }
            }
        }
    }
    else
    {
        if( MONITOR_VALUE_ZERO == Os_Monitor_IsrInterruptFlag[coreId] )
        {
            Os_Monitor_CoreRunTask[coreId] = (TaskType)taskID;
        }
    }
}

/*
*******************************************************************************
* Function Name: Os_Monitor_EndTimeDeal
*
* Explanation: Processing task end time.
*
* Param: None
*
* Retval: None
*******************************************************************************
*/
FUNC(void, OS_CODE) Os_Monitor_EndTimeDeal(void)
{
    TaskType taskID = INVALID_TASK;
    CoreIdType coreId = OS_CORE_ID_MASTER;
    uint32 ticksCount = MONITOR_VALUE_ZERO;
    uint32 currentTick = MONITOR_VALUE_ZERO;
    if( TRUE == Os_Monitor_Init_status )
    {
        coreId = Os_Core_GetLogicId();

        taskID = Os_Monitor_CoreRunTask[coreId];
        if( FALSE == Os_Monitor_Cat2Interrupttotask[coreId] )
        {
            if( 0U != Os_Monitor_TaskStackPara[taskID].StartResumesTime )
            {
                currentTick = (uint32)Os_Counter_GetCntValue(Os_CounterCfgData[Os_Monitor_CoreUseCounterIndex[coreId]]);
                ticksCount = (uint32)Os_Monitor_CounterSub(Os_CounterCfgData[Os_Monitor_CoreUseCounterIndex[coreId]], currentTick, Os_Monitor_TaskStackPara[taskID].StartResumesTime);

                Os_Monitor_TaskStackPara[Os_Monitor_CoreRunTask[coreId]].TimeSum += ticksCount;
                Os_Monitor_TaskRecordTime(taskID);
                if( TRUE == Os_Monitor_TaskTerminateFlag[taskID])
                {
                    Os_Monitor_TaskStackPara[taskID].EndTime = currentTick;
                }
            }
        }
        else
        {
            Os_Monitor_Cat2Interrupttotask[coreId] = FALSE;
        }
    }
}

/*
*******************************************************************************
* Function Name: Os_Monitor_IsrRecordTime
*
* Explanation: Record isrcat2 execution time.
*
* Param: IsrId: isrcat2 id.
*             TicksCount: execution time.
*             CoreId: core id.
*             IsrFinished: Finish flag.
* Retval: None
*******************************************************************************
*/
FUNC(void, OS_CODE) Os_Monitor_IsrRecordTime(ISRType IsrId, uint32 TicksCount, CoreIdType CoreId, uint32 IsrFinished)
{
    uint32 recordTime = TicksCount;

    Os_Monitor_IsrStackPara[IsrId].TimeSum += TicksCount;
    /* Record whole runtime. */
    if ( MONITOR_ISR_FINISHED == IsrFinished )
    {
        Os_Monitor_IsrStackPara[IsrId].RunTime[MONITOR_ISR_UNFINISHED] = recordTime + Os_Monitor_IsrStackPara[IsrId].RunTime[MONITOR_ISR_FINISHED];
        Os_Monitor_IsrStackPara[IsrId].RunTime[MONITOR_ISR_FINISHED] = MONITOR_VALUE_ZERO;
        Os_Monitor_CoreRunIsr[CoreId] = INVALID_ISR;
    }
    /* Record interrupted runtime. */
    else
    {
        Os_Monitor_IsrStackPara[IsrId].RunTime[MONITOR_ISR_FINISHED] += recordTime;
        Os_Monitor_CoreRunIsr[CoreId] = INVALID_ISR;
    }
    if( (RunTime_Max_init == MONITOR_FLAGVALUE) &&
        (Os_Monitor_IsrStackPara[IsrId].RunTime_Max < Os_Monitor_IsrStackPara[IsrId].RunTime[MONITOR_ISR_UNFINISHED]) &&
        (Os_Monitor_IsrStackPara[IsrId].RunTime[MONITOR_ISR_UNFINISHED] < MONITOR_ISR_LIMIT) &&
        (IsrFinished == MONITOR_FLAGVALUE))
    {
        Os_Monitor_IsrStackPara[IsrId].RunTime_Max = Os_Monitor_IsrStackPara[IsrId].RunTime[MONITOR_ISR_UNFINISHED];
    }
}

/*
*******************************************************************************
* Function Name: Os_Monitor_IsrEntry
*
* Explanation: Record isrcat2 execution time.
*
* Param: CoreId: core id.
*        isrCfg: Reference to an isr.
* Retval: None
*******************************************************************************
*/
FUNC(void, OS_CODE) Os_Monitor_IsrEntry
(
    CoreIdType coreId,
    P2CONST(Os_IsrCfgType, AUTOMATIC, OS_APPL_CONST) isrCfg
)
{
    uint32 ticksCurrent = OS_ZERO_VALUE;
    uint32 useTicksCount = OS_ZERO_VALUE;

    Pre_IsrQnum[coreId] = Os_Monitor_IsrInterruptFlag[coreId];
    Isr_Queue[Os_Monitor_IsrInterruptFlag[coreId]][coreId] = isrCfg->isrId;
    Os_Monitor_IsrInterruptFlag[coreId] = Os_Monitor_IsrInterruptFlag[coreId] + MONITOR_FLAGVALUE;

    /* Only one isr. */
    if( Os_Monitor_IsrInterruptFlag[coreId] == MONITOR_FLAGVALUE )
    {
        ticksCurrent = Os_Counter_GetCntValue(Os_CounterCfgData[Os_Monitor_CoreUseCounterIndex[coreId]]);
        Os_Monitor_IsrStackPara[isrCfg->isrId].StartResumesTime = ticksCurrent;
    }
    /* Isr nest occured. */
    else
    {
        /* record current StartTime. */
        ticksCurrent = Os_Counter_GetCntValue(Os_CounterCfgData[Os_Monitor_CoreUseCounterIndex[coreId]]);
        Os_Monitor_IsrStackPara[isrCfg->isrId].StartResumesTime = ticksCurrent;

        /* record last UseTime. */
        Pre_IsrQnum[coreId] = Pre_IsrQnum[coreId] - MONITOR_ISRNEST;
        Last_isrId = Isr_Queue[Pre_IsrQnum[coreId]][coreId];
        useTicksCount = Os_Monitor_CounterSub(Os_CounterCfgData[Os_Monitor_CoreUseCounterIndex[coreId]], ticksCurrent,
                                          Os_Monitor_IsrStackPara[Last_isrId].StartResumesTime);
        Os_Monitor_IsrRecordTime(Last_isrId, useTicksCount, coreId, MONITOR_ISR_UNFINISHED);

    }

}

/*
*******************************************************************************
* Function Name: Os_Monitor_IsrExit
*
* Explanation: Record isrcat2 execution time.
*
* Param: CoreId: core id.
*             isrCfg: Reference to an isr.
* Retval: None
*******************************************************************************
*/
FUNC(void, OS_CODE) Os_Monitor_IsrExit
(
    CoreIdType coreId,
    P2CONST(Os_IsrCfgType, AUTOMATIC, OS_APPL_CONST) isrCfg
)
{
    uint32 ticksCurrent = OS_ZERO_VALUE;
    uint32 useTicksCount = OS_ZERO_VALUE;

    Pre_IsrQnum[coreId] = Os_Monitor_IsrInterruptFlag[coreId];

    Os_Monitor_CoreRunIsr[coreId] = isrCfg->isrId;
    /* only one isr. */
    if( Os_Monitor_IsrInterruptFlag[coreId] == MONITOR_FLAGVALUE )
    {

        ticksCurrent = Os_Counter_GetCntValue(Os_CounterCfgData[Os_Monitor_CoreUseCounterIndex[coreId]]);
        useTicksCount = Os_Monitor_CounterSub(Os_CounterCfgData[Os_Monitor_CoreUseCounterIndex[coreId]], ticksCurrent,
                                              Os_Monitor_IsrStackPara[Os_Monitor_CoreRunIsr[coreId]].StartResumesTime);

        Os_Monitor_IsrRecordTime(isrCfg->isrId, useTicksCount, coreId, MONITOR_ISR_FINISHED);

    }
    else
    {
        /* for current isr */
        ticksCurrent = Os_Counter_GetCntValue(Os_CounterCfgData[Os_Monitor_CoreUseCounterIndex[coreId]]);
        useTicksCount = Os_Monitor_CounterSub(Os_CounterCfgData[Os_Monitor_CoreUseCounterIndex[coreId]], ticksCurrent,
                                              Os_Monitor_IsrStackPara[Os_Monitor_CoreRunIsr[coreId]].StartResumesTime);

        Os_Monitor_IsrRecordTime(isrCfg->isrId, useTicksCount, coreId, MONITOR_ISR_FINISHED);

        /* for last isr. */
        /* get current isr Qnum */
        Pre_IsrQnum[coreId] = Pre_IsrQnum[coreId] - MONITOR_ISRNEST;
        /* get last isr Qnum */
        Pre_IsrQnum[coreId] = Pre_IsrQnum[coreId] - MONITOR_ISRNEST;
        Last_isrId = Isr_Queue[Pre_IsrQnum[coreId]][coreId];
        Os_Monitor_IsrStackPara[Last_isrId].StartResumesTime = ticksCurrent;
    }
    /* Exit from current ISR. */
    Os_Monitor_IsrInterruptFlag[coreId] = Os_Monitor_IsrInterruptFlag[coreId] - MONITOR_FLAGVALUE;
}

/*
*******************************************************************************
* Function Name: MonitorInit
*
* Explanation: Get task configuration information and initialization structure.
*
* Param: None
*
* Retval: None
*******************************************************************************
*/
FUNC(void, OS_CODE) MonitorInit(void)
{
    Os_Monitor_init();
}

/*
*******************************************************************************
* Function Name: MonitorMainFunction
*
* Explanation: Module main function,count average execution time, stack, cpu load.
*
* Param: None
*
* Retval: None
*******************************************************************************
*/
FUNC(void, OS_CODE) MonitorMainFunction(void)
{
#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    Os_SysCall(Os_Syscall_Monitor_ID, &sysCallParam);
#else
    Os_Monitor_MainFunction();
#endif
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif

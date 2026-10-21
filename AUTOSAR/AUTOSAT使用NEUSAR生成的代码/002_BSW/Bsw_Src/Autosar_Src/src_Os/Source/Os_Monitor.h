/*
********************************************************************************
*
*  File name: Os_Monitor.h
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
* Author/Date: LiuJJ/2023.05.05
* Change: Solve ISR interrupted RunTime calculate error.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: LiuJJ/2023.05.05
* Change: Macro written backwards.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2023.06.08
* Change: Coding specification.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.6.9
* Change: Coding specification.
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2023.6.9
* Change: Increase the maximum nesting level of interrupts.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: LiG/2024.2.29
* Change: To remove numerical macros, a meaningful macro was added.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: LiG/2023.3.15
* Change: Add the parameters and macros required for the deviation function of
*         Task operation.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: LiG/2024.4.10
* Change: Modifying static code check issues.
* Cause: Optimization
********************************************************************************
*/
#ifndef OS_MONITOR_H_
#define OS_MONITOR_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Monitor_Cfg.h"
#include "Os_Types.h"
#include "Os_Task_Types.h"
#include "Os_Isr_Types.h"
#include "Os_Arch_Types.h"
#include "Compiler.h"
#include "Os.h"

#if( OS_MONITOR_ENABLE == STD_ON )
/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define STACKSIZECOMPENSATE      (4U)
#define MONITOR_VALUE_ZERO       (0U)
#define MONITOR_STACK_OVER       (1U)
#define MONITOR_FLAGVALUE        (1U)
#define MONITOR_BLANKBUFF        (1U)
#define MONITOR_COUNTDATA        (1000U)
#define MONITOR_MAX_VALUE        (0xFFFFFFFFU)
#define MONITOR_LIMIT            (0x00FFFFF0U)
#define MONITOR_ISR_LIMIT        (0x0000FFFFU)
#define MONITOR_ISR_UNFINISHED   (0U)
#define MONITOR_ISR_FINISHED     (1U)
#define OS_MONITOR_ISR_BUFFSIZE  (2U)
#define OS_MONITOR_ISR_NEST_NUM  (16U)
#define MONITOR_ISRNEST          (1U)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef struct
{
    TaskType TaskId;
    Os_TaskPrioType HomePriority;
    uint32 StartResumesTime;
    uint32 EndTime;
    uint32 TimeSum;
    uint32 TimeSum_last;
    float32 CpuLoad;
    uint32 TimeFrame;
    uint32 TimeFrameMax;
    uint32 TimeFrameMin;
    uint32 RunTime_Max;
    uint32 RunTime[OS_MONITOR_BUFFSIZE];
    uint8  RunTimenum;
    Os_TaskPrioType Priority;

}Os_Monitor_TaskStackType_st;

typedef struct
{
    ISRType Id;
    Os_Arch_IsrSourceType Source;
    uint32 StartResumesTime;
    uint32 EndTime;
    uint32 TimeSum;
    uint32 TimeSum_last;
    float32 CpuLoad;
    uint32 RunTime_Max;
    uint32 RunTime[OS_MONITOR_ISR_BUFFSIZE];
    uint8  RunTimenum;

}Os_Monitor_IsrStackType_st;

typedef struct
{
    uint32 CoreStartRunTime;
    float32 Cpuload;
}Os_Monitor_CoreCpuloadType_st;

typedef struct
{
    TaskType TaskId;
    uint8    SubTimeNumber;

}Os_Monitor_ExtendTaskSubTimeType_st;

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
extern VAR(Os_Monitor_CoreCpuloadType_st, OS_VAR_INIT) Os_Monitor_CpuLoadkPara[OS_COREID_COUNT];
extern VAR(Os_Monitor_TaskStackType_st, OS_VAR_INIT)  Os_Monitor_TaskStackPara[OS_TASKID_COUNT];
extern VAR(Os_Monitor_IsrStackType_st, OS_VAR_INIT) Os_Monitor_IsrStackPara[OS_ISRID_COUNT];

extern VAR(ISRType, OS_VAR_INIT) Os_Monitor_CoreRunIsr[OS_COREID_COUNT];
extern VAR(boolean, OS_VAR_INIT)  Os_Monitor_TaskTerminateFlag[OS_TASKID_COUNT];
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
extern CONST(TaskType, OS_CONST) Os_Monitor_CoreidleTaskMapping[OS_COREID_COUNT];
#if(OS_MONITOR_EXTENDTASKCOUNT > 0)
extern CONST(Os_Monitor_ExtendTaskSubTimeType_st, OS_CONST) Os_Monitor_ExtendTaskSubTimeNumber[OS_MONITOR_EXTENDTASKCOUNT];
#endif
extern CONST(CounterType, OS_CONST) Os_Monitor_CoreUseCounterIndex[OS_COREID_COUNT];

/*
********************************************************************************
*    Global Functions
********************************************************************************
*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
extern FUNC(void, OS_CODE) Os_Monitor_init(void);
extern FUNC(void, OS_CODE) Os_Monitor_MainFunction(void);
extern FUNC(void, OS_CODE) Os_Monitor_ExtendTaskTimeDeal(uint8 SnippetFlag);
extern FUNC(void, OS_CODE) Os_Monitor_StartTimeDeal(void);
extern FUNC(void, OS_CODE) Os_Monitor_EndTimeDeal(void);
extern FUNC(void, OS_CODE) Os_Monitor_IsrRecordTime(ISRType IsrId, uint32 TicksCount, CoreIdType CoreId,uint32 IsrFinished);
extern FUNC(void, OS_CODE) Os_Monitor_IsrEntry
(
    CoreIdType coreId,
    P2CONST(Os_IsrCfgType, AUTOMATIC, OS_APPL_CONST) isrCfg
);
extern FUNC(void, OS_CODE) Os_Monitor_IsrExit
(
    CoreIdType coreId,
    P2CONST(Os_IsrCfgType, AUTOMATIC, OS_APPL_CONST) isrCfg
);
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif
#endif

/*
********************************************************************************
*
*  File name: Os_Scheduler_Types.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.24
* Change: New create.
* Cause: New
********************************************************************************
*/
#ifndef OS_SCHEDULER_TYPES_H_
#define OS_SCHEDULER_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_BitMap.h"
#include "Os_Types.h"
#include "Os_Types_Cfg.h"
#include "Os_Task_Types.h"
#include "Os_TaskQueue.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* Function pointer data type for call isr callabck. */
typedef P2FUNC(void, OS_CODE, Os_TaskQueInitCbkType )(void);

typedef struct
{
    /* Allow schedule flag. */
    boolean allowSchedule;
    /* The priority of the next scheduled task. */
    Os_TaskPrioType nextPriority;
    /* The next task to be scheduled. */
    Os_TaskDynType* nextTask;
    /* The priority of the task being scheduled. */
    Os_TaskPrioType currentPriority;
    /* The task being scheduled. */
    Os_TaskDynType* currentTask;
} Os_SchedulerDynType;

typedef struct
{
    /* Associated bitmap configuration. */
    const Os_BitMapCfgType bitMap;
    /* The scheduler dynamic configuration. */
    Os_SchedulerDynType* schdDyn;
    /* The task queue array header. */
    Os_TaskQueRefType* taskQueues;
    /* The task queue array number. */
    Os_TaskPrioType queuesNumber;
    /* Task queue init callback. */
    Os_TaskQueInitCbkType taskQueInit;
} Os_SchedulerCfgType;

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
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* OS_SCHEDULER_TYPES_H_ */

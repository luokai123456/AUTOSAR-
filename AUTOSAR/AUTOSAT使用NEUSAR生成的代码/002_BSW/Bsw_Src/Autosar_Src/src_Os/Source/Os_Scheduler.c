/*
********************************************************************************
*
*  File name: Os_Scheduler.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.20
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2022.11.15
* Change: Modify scheduling related functions.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2022.11.21
* Change: Change OS_VAR_NOINIT to OS_VAR_NO_INIT.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2022.1.6
* Change: Change Os_Schedler_DecreasePriority(),Reschedule only when the
*         judgment conditions are met.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2022.1.28
* Change: Os_CntLeadZerosTbl This has no segment descriptor.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.1.29
* Change: Resolve the CallErrorHook privilege level problem.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: LiG/2023.5.27
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: ZhangY/2024.01.10
* Change: Modify Os_Schedler_NeedSchedle.
* Cause: Bugfix
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Scheduler.h"
#include "Os_Platform_Lcfg.h"
#include "Os_Task.h"
#include "Os_App.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/* Get the next task from the scheduler. */
#define OS_SCHEDULER_GETNEXTTASK(schdCfg)          ((schdCfg)->schdDyn->nextTask)
/* Get the current task from the scheduler. */
#define OS_SCHEDULER_GETCURRENTTASK(schdCfg)       ((schdCfg)->schdDyn->currentTask)
/* Get the next scheduled task priority from the scheduler. */
#define OS_SCHEDULER_GETNEXTPRIO(schdCfg)          ((schdCfg)->schdDyn->nextPriority)
/* Get the currently scheduled task priority from the scheduler. */
#define OS_SCHEDULER_GETCURRENTPRIO(schdCfg)       ((schdCfg)->schdDyn->currentPriority)
/* Get the task queue from the scheduler. */
#define OS_SCHEDULER_GETQUEUENUM(schdCfg)          ((schdCfg)->queuesNumber)
/* Get bitmap from scheduler. */
#define OS_SCHEDULER_GETBITMAP(schdCfg)            (&(schdCfg)->bitMap)
/* Set the next task to the scheduler. */
#define OS_SCHEDULER_SETNEXTTASK(schdCfg, task)    ((schdCfg)->schdDyn->nextTask = (task))
/* Set the current task to the scheduler. */
#define OS_SCHEDULER_SETCURRENTTASK(schdCfg, task) ((schdCfg)->schdDyn->currentTask = (task))
/* set the next task priority to the scheduler. */
#define OS_SCHEDULER_SETNEXTPRIO(schdCfg, prio)    ((schdCfg)->schdDyn->nextPriority = (prio))
/* set the current task priority to the scheduler. */
#define OS_SCHEDULER_SETCURRENTPRIO(schdCfg, prio) ((schdCfg)->schdDyn->currentPriority = (prio))
/* Task switching in the scheduler. */
#define OS_SCHEDULER_TASKEXCHANGE(schdCfg)         (scheduler->schdDyn->currentTask = (schdCfg)->schdDyn->nextTask)
/* Task priority switching is in the scheduler. */
#define OS_SCHEDULER_PRIOEXCHANGE(schdCfg)         (scheduler->schdDyn->currentPriority = (schdCfg)->schdDyn->nextPriority)

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
LOCAL_INLINE FUNC_P2VAR(Os_TaskQueType, OS_APPL_DATA, OS_CODE) Os_Scheduler_GetQueueByPrio
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler,
    Os_TaskPrioType taskPrio
);
LOCAL_INLINE FUNC(void, OS_CODE) Os_Schedler_SchedleInternal
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler
);

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define OS_START_SEC_CONST
#include "Os_MemMap.h"

#if( OS_CFG_COUNT_LEAD_ZEROS_HARDWARE == STD_OFF )
CONST(uint8, OS_CONST) Os_CntLeadZerosTbl[256U] = {
    8U,  7U,  6U,  6U,  5U,  5U,  5U,  5U,  4U,  4U,  4U,  4U,  4U,  4U,  4U,  4U,  /* 0x00 to 0x0F. */
    3U,  3U,  3U,  3U,  3U,  3U,  3U,  3U,  3U,  3U,  3U,  3U,  3U,  3U,  3U,  3U,  /* 0x10 to 0x1F. */
    2U,  2U,  2U,  2U,  2U,  2U,  2U,  2U,  2U,  2U,  2U,  2U,  2U,  2U,  2U,  2U,  /* 0x20 to 0x2F. */
    2U,  2U,  2U,  2U,  2U,  2U,  2U,  2U,  2U,  2U,  2U,  2U,  2U,  2U,  2U,  2U,  /* 0x30 to 0x3F. */
    1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  /* 0x40 to 0x4F. */
    1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  /* 0x50 to 0x5F. */
    1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  /* 0x60 to 0x6F. */
    1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  1U,  /* 0x70 to 0x7F. */
    0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  /* 0x80 to 0x8F. */
    0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  /* 0x90 to 0x9F. */
    0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  /* 0xA0 to 0xAF. */
    0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  /* 0xB0 to 0xBF. */
    0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  /* 0xC0 to 0xCF. */
    0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  /* 0xD0 to 0xDF. */
    0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  /* 0xE0 to 0xEF. */
    0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U,  0U   /* 0xF0 to 0xFF. */
};
#endif /* OS_ARCH_COUNT_LEADING_ZEROS_HARDWARE == STD_ON */

#define OS_STOP_SEC_CONST
#include "Os_MemMap.h"

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*
********************************************************************************
* Function Name: Os_Scheduler_GetQueueByPrio
*
* Explanation: Internal function to get scheduler task quene by priority.
*
* Param: scheduler: Reference to an scheduler.
*        taskPrio: task priority.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC_P2VAR(Os_TaskQueType, OS_APPL_DATA, OS_CODE) Os_Scheduler_GetQueueByPrio
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler,
    Os_TaskPrioType taskPrio
)
{
    /* Check whether the task priority parameter is out of range. */
    Os_ParamCheck(scheduler != NULL_PTR);
    Os_ParamCheck(taskPrio < OS_SCHEDULER_GETQUEUENUM(scheduler));

    return scheduler->taskQueues[taskPrio];
}

/*
********************************************************************************
* Function Name: Os_Schedler_SchedleInternal
*
* Explanation: Internal function to execute scheduling.
*
* Param: scheduler: Reference to an scheduler.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Schedler_SchedleInternal
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler
)
{
    Os_TaskDynType* nextTask;
    Os_TaskPrioType nextPriority;

    /* Determine whether scheduling is currently allowed. */
    if( TRUE == OS_SCHEDULER_GETSCHEDULERSTATE(scheduler) )
    {
        /* Execute a schedule. */
        nextPriority = Os_BitMap_CountLeadZeros(OS_SCHEDULER_GETBITMAP(scheduler));
        nextTask = Os_TaskQue_Get(Os_Scheduler_GetQueueByPrio(scheduler, nextPriority));

        OS_SCHEDULER_SETNEXTPRIO(scheduler, nextPriority);
        OS_SCHEDULER_SETNEXTTASK(scheduler, nextTask);
    }
}

/*
********************************************************************************
* Function Name: Os_Schedler_Init
*
* Explanation: Uses to init schedler.
*
* Param: scheduler: Reference to an scheduler.
*        idleTask: Idle task.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Schedler_Init
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler,
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_APPL_CONST) idleTask
)
{
   if( (scheduler != NULL_PTR) && (idleTask != NULL_PTR) )
   {
        /* Bitmap initialization. */
        Os_BitMap_Init(OS_SCHEDULER_GETBITMAP(scheduler));
        /* Scheduler dynamic configration initialization. */
        OS_SCHEDULER_DISABLESCHEDULER(scheduler);
        OS_SCHEDULER_SETNEXTTASK(scheduler, OS_TASK_GETDYN(idleTask));
        OS_SCHEDULER_SETNEXTPRIO(scheduler, OS_TASK_GETCFGPRIO(idleTask));
        OS_SCHEDULER_SETCURRENTTASK(scheduler, OS_TASK_GETDYN(idleTask));
        OS_SCHEDULER_SETCURRENTPRIO(scheduler, OS_TASK_GETCFGPRIO(idleTask));

        /* Task queue initialization. */
        scheduler->taskQueInit();
   }
}

/*
********************************************************************************
* Function Name: Os_Schedler_InsertTask
*
* Explanation: Used to insert tasks into the scheduler.
*
* Param: scheduler: Reference to an scheduler.
*        taskDyn: task.
*
* Retval: E_OS_OK: No error.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_Schedler_InsertTask
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler,
    P2VAR(Os_TaskDynType, AUTOMATIC, OS_APPL_DATA) taskDyn
)
{
    StatusType ret = E_OS_OK;
    Os_TaskPrioType taskPrio;
    const Os_TaskCfgType* taskCfg;
    Os_TaskQueType* taskQueue;

    if( (scheduler != NULL_PTR) && (taskDyn != NULL_PTR) )
    {
        taskCfg = OS_TASK_GETCFGBYDYN(taskDyn);
        taskPrio = OS_TASK_GETCFGPRIO(taskCfg);

        /* Get task queue. */
        taskQueue = Os_Scheduler_GetQueueByPrio(scheduler, taskPrio);
        /* Task enqueue */
        Os_TaskQue_Push(taskQueue, taskDyn);
        Os_BitMap_Set(OS_SCHEDULER_GETBITMAP(scheduler), taskPrio);

        if( taskPrio < OS_SCHEDULER_GETNEXTPRIO(scheduler) )
        {
            OS_SCHEDULER_SETNEXTPRIO(scheduler, taskPrio);
            OS_SCHEDULER_SETNEXTTASK(scheduler, taskDyn);
        }
    }
    else
    {
        ret = E_OS_PARAM_POINTER;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Schedler_DeleteTask
*
* Explanation: Used to delete tasks from the scheduler.
*
* Param: scheduler: Reference to an scheduler.
*        taskDyn: task.
*
* Retval: E_OS_OK: No error.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_Schedler_DeleteTask
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler,
    P2CONST(Os_TaskDynType, AUTOMATIC, OS_APPL_CONST) taskDyn
)
{
    Os_TaskPrioType taskPrio;
    Os_TaskPrioType taskRunPrio;
    const Os_TaskCfgType* taskCfg;
    StatusType ret = E_OS_OK;
    Os_TaskQueType* taskQueue;

    if( (scheduler != NULL_PTR) && (taskDyn != NULL_PTR) )
    {
        taskCfg = OS_TASK_GETCFGBYDYN(taskDyn);
        taskPrio = OS_TASK_GETCFGPRIO(taskCfg);
        taskRunPrio = OS_TASK_GETRUNPRIO(taskDyn);
        taskQueue = Os_Scheduler_GetQueueByPrio(scheduler, taskPrio);
        /* Task dequeue.*/
        (void)Os_TaskQue_Pop(taskQueue);
        /* If the queue is empty, bitmap clear. */
        if( TRUE == Os_TaskQue_IsEmpty(taskQueue) )
        {
            Os_BitMap_Clear(OS_SCHEDULER_GETBITMAP(scheduler), taskPrio);
        }

        if( taskRunPrio != taskPrio )
        {
            taskQueue = Os_Scheduler_GetQueueByPrio(scheduler, taskRunPrio);
            (void)Os_TaskQue_Pop(taskQueue);
            if( TRUE == Os_TaskQue_IsEmpty(taskQueue) )
            {
                Os_BitMap_Clear(OS_SCHEDULER_GETBITMAP(scheduler), taskRunPrio);
            }
        }
    }
    else
    {
        ret = E_OS_PARAM_POINTER;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Schedler_DeleteTaskAll
*
* Explanation: Used to delete all tasks from the scheduler task queue.
*
* Param: scheduler: Reference to an scheduler.
*        taskDyn: task.
*
* Retval: E_OS_OK: No error.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_Schedler_DeleteTaskAll
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler,
    P2CONST(Os_TaskDynType, AUTOMATIC, OS_APPL_CONST) taskDyn
)
{
    Os_TaskPrioType taskPrio;
    Os_TaskPrioType taskRunPrio;
    Os_TaskQueType* taskQueue;
    const Os_TaskCfgType* taskCfg;
    StatusType ret = E_OS_OK;

    if( (scheduler != NULL_PTR) && (taskDyn != NULL_PTR) )
    {
        taskCfg = OS_TASK_GETCFGBYDYN(taskDyn);
        taskPrio = OS_TASK_GETCFGPRIO(taskCfg);
        taskRunPrio = OS_TASK_GETRUNPRIO(taskDyn);
        /* Remove this task from the entire queue. */
        if( taskPrio != taskRunPrio )
        {
            taskQueue = Os_Scheduler_GetQueueByPrio(scheduler, taskRunPrio);
            Os_TaskQue_Del(taskQueue, taskDyn);
            if( TRUE == Os_TaskQue_IsEmpty(taskQueue) )
            {
                Os_BitMap_Clear(OS_SCHEDULER_GETBITMAP(scheduler),
                                OS_SCHEDULER_GETCURRENTPRIO(scheduler));
            }
        }

        taskQueue = Os_Scheduler_GetQueueByPrio(scheduler, taskPrio);
        Os_TaskQue_Del(taskQueue, taskDyn);
        if( TRUE == Os_TaskQue_IsEmpty(taskQueue) )
        {
            Os_BitMap_Clear(OS_SCHEDULER_GETBITMAP(scheduler), taskPrio);
        }
    }
    else
    {
        ret = E_OS_PARAM_POINTER;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Schedler_Schedle
*
* Explanation: Used to execute scheduling.
*
* Param: scheduler: Reference to an scheduler.
*
* Retval: Next task.
********************************************************************************
*/
FUNC_P2VAR(Os_TaskDynType, OS_APPL_DATA, OS_CODE) Os_Schedler_Schedle
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler
)
{
    Os_TaskDynType* nextTask;
    Os_TaskPrioType nextPriority;

    Os_ParamCheck(scheduler != NULL_PTR);

    /* Determine whether scheduling is currently allowed. */
    if( FALSE == OS_SCHEDULER_GETSCHEDULERSTATE(scheduler) )
    {
        nextTask = OS_SCHEDULER_GETCURRENTTASK(scheduler);
    }
    else
    {
        /* Execute a schedule. */
        nextPriority = Os_BitMap_CountLeadZeros(OS_SCHEDULER_GETBITMAP(scheduler));
        nextTask = Os_TaskQue_Get(Os_Scheduler_GetQueueByPrio(scheduler, nextPriority));

        OS_SCHEDULER_SETNEXTPRIO(scheduler, nextPriority);
        OS_SCHEDULER_SETNEXTTASK(scheduler, nextTask);
        OS_SCHEDULER_TASKEXCHANGE(scheduler);
        OS_SCHEDULER_PRIOEXCHANGE(scheduler);
    }

    return nextTask;
}

/*
********************************************************************************
* Function Name: Os_Schedler_IncreasePriority
*
* Explanation: Used to increase the priority of tasks running in the scheduler.
*
* Param: scheduler: Reference to an scheduler.
*        leve: Priority leve.
*
* Retval: E_OS_OK: No error.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_Schedler_IncreasePriority
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler,
    Os_TaskPrioType level
)
{
    StatusType ret = E_OS_OK;
    Os_TaskDynType* currentTask;
    Os_TaskQueType* taskQueue;
    /* Check level is valid. */
    if( (scheduler != NULL_PTR) && (level < OS_SCHEDULER_GETCURRENTPRIO(scheduler)) )
    {
        currentTask = OS_SCHEDULER_GETCURRENTTASK(scheduler);
        /* Insert the current Task at the new priority. */
        taskQueue = Os_Scheduler_GetQueueByPrio(scheduler, level);
        Os_TaskQue_PushF (taskQueue, currentTask);
        OS_SCHEDULER_SETCURRENTPRIO(scheduler, level);
        OS_TASK_SETRUNPRIO(currentTask, level);
        Os_BitMap_Set(OS_SCHEDULER_GETBITMAP(scheduler), level);
    }
    else
    {
        ret = E_OS_PARAM_POINTER;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Schedler_DecreasePriority
*
* Explanation: Used to decrease the priority of tasks running in the scheduler.
*
* Param: scheduler: Reference to an scheduler.
*        leve: Priority leve.
*
* Retval: E_OS_OK: No error.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_Schedler_DecreasePriority
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler,
    Os_TaskPrioType level
)
{
    StatusType ret = E_OS_OK;
    Os_TaskDynType* currentTask;
    Os_TaskQueType* taskQueue;
    Os_TaskPrioType curretPriority;
    /* Check level is valid. */
    if( (scheduler != NULL_PTR) && (OS_SCHEDULER_GETCURRENTPRIO(scheduler) < level) )
    {
        currentTask = OS_SCHEDULER_GETCURRENTTASK(scheduler);
        curretPriority = OS_SCHEDULER_GETCURRENTPRIO(scheduler);
        /* Insert the current Task at the new priority. */
        taskQueue = Os_Scheduler_GetQueueByPrio(scheduler, curretPriority);
        (void)Os_TaskQue_Pop(taskQueue);
        if( TRUE == Os_TaskQue_IsEmpty(taskQueue) )
        {
            Os_BitMap_Clear(OS_SCHEDULER_GETBITMAP(scheduler),
                            OS_SCHEDULER_GETCURRENTPRIO(scheduler));
        }
        OS_SCHEDULER_SETCURRENTPRIO(scheduler, level);
        OS_TASK_SETRUNPRIO(currentTask, level);
        (void)Os_Schedler_SchedleInternal(scheduler);
    }
    else
    {
        ret = E_OS_PARAM_POINTER;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Schedler_NeedSchedle
*
* Explanation: Determine if scheduling is required.
*
* Param: scheduler: Reference to an scheduler.
*
* Retval: FALSE: No scheduling required.
*         TRUE: Need to be scheduled.
********************************************************************************
*/
FUNC(boolean, OS_CODE) Os_Schedler_NeedSchedle
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler
)
{
    boolean ret = FALSE;

     Os_TaskDynType* currentTask = OS_SCHEDULER_GETCURRENTTASK(scheduler);
    if( (OS_TASK_CHECKTASKISFULLTYPE(currentTask) && (currentTask != OS_SCHEDULER_GETNEXTTASK(scheduler))) || (SUSPENDED == currentTask->state) 
    || ((READY == currentTask->state) && (APPLICATION_RESTARTING == OS_APP_GETSTATE(OS_APP_GETCFG(currentTask->currentAppId)))) )
    {
        ret = TRUE;
    }
    /* Set enable shcedle flag.*/
    return ret;
}
/*
********************************************************************************
* Function Name: Os_Schedler_Schedule
*
* Explanation: This function is not yet implemented
*
* Param: None
*
* Retval: TRUE: Always return TRUE
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_Schedler_Schedule(void)
{
    StatusType ret = E_OS_OK;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_Schedule);

    OS_ORTI_API_MONITOR_EXIT(OSServiceId_Schedule);

    return Os_Hook_CallErrorHook(OSServiceId_Schedule, ret);
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

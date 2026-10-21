/*
********************************************************************************
*
*  File name: Os_Task.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.17
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2022.11.15
* Change: Increase judgment on the status of extended tasks.
* Cause: Bugfix.
********************************************************************************
* Version: 3.2
* Author/Date: ZhangY/2022.11.18
* Change: Fix the bug of repeated execution of extended tasks.
* Cause: Bugfix.
********************************************************************************
* Version: 3.3
* Author/Date: JiangGL/2022.11.24
* Change: Fix the bug of repeated execution of extended tasks.
* Cause: Bugfix.
********************************************************************************
* Version: 3.4
* Author/Date: WangJP/2022.12.10
* Change: Modification of coding standard.
* Cause: Optimize
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2023.3.28
* Change: Os_Task_WrongReturn function adds a self scheduling function.
* Cause: Bugfix
********************************************************************************
* Version: 3.7
* Author/Date: LiG/2023.4.4
* Change: Resolve compilation warnings.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: LiG/2023.10.3
* Change: Add ControlIdleHook related macro definition.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
*/
#ifndef OS_TASK_H_
#define OS_TASK_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Task_Types.h"
#include "Os_Types_Cfg.h"
#include "Os_Types.h"
#include "Os_Arch_Context.h"
#include "Os_Platform_Lcfg.h"
#include "Os_Scheduler.h"
#include "Os_Core.h"
#include "Os_Arch_Lcfg.h"
#include "Os_TmProtection.h"
#include "Os_Orti.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Determine the resource is release. */
#define OS_TASK_MASK_RESOURCE(taskCfg)            (NULL_PTR != (taskCfg)->taskDyn->resListHead.nextNode)
/* Determine the spinlock is release. */
#define OS_TASK_MASK_SPINLOCK(taskCfg)            (NULL_PTR != (taskCfg)->taskDyn->spinListHead.nextNode)
/* If task id in the range. */
#define OS_TASK_ISINVAILD(taskId)                 ((taskId) >= INVALID_TASK)
/* Get the task static configuration. */
#define OS_TASK_GETCFG(taskId)                    (Os_TaskCfgData[taskId])
/* Get the task static configuration by dynamic configuration. */
#define OS_TASK_GETCFGBYDYN(taskDyn)              (Os_TaskCfgData[(taskDyn)->taskId])
/* Get the task dynamic configuration. */
#define OS_TASK_GETDYN(taskCfg)                   ((taskCfg)->taskDyn)
/* Get task status. */
#define OS_TASK_GETTASKSTATE(taskCfg)             ((taskCfg)->taskDyn->state)
/* Get the application id to which the task belongs through
   the task static configuration. */
#define OS_TASK_GETAPPID(taskCfg)                 ((taskCfg)->ownerAppId)
/* Get task priority. */
#define OS_TASK_GETCFGPRIO(taskCfg)               ((taskCfg)->cfgPrio)
/* Get task running priority. */
#define OS_TASK_GETRUNPRIO(taskDyn)               ((taskDyn)->currentPrio)
/* Get the core id to which the task belongs through
   the task static configuration. */
#define OS_TASK_GETCOREID(taskCfg)                ((taskCfg)->coreId)
/* Determine that the task is a standard task. */
#define OS_TASK_ISBASIC(taskCfg)                  (OS_TASK_BT == (taskCfg)->taskType)
/* Get extended task waiting events. */
#define OS_TASK_GETEVENTWAIT(taskCfg)             ((taskCfg)->taskDyn->eventDyn.Waiting)
/* Get extended task triggered events. */
#define OS_TASK_GETEVENTTRIGGER(taskCfg)          ((taskCfg)->taskDyn->eventDyn.Triggered)
/* Set extended task waiting events. */
#define OS_TASK_SETEVENTWAIT(taskCfg, wait)       ((taskCfg)->taskDyn->eventDyn.Waiting = (wait))
/* Set extended task triggered events. */
#define OS_TASK_SETEVENTTRIGGER(taskCfg, trigger) ((taskCfg)->taskDyn->eventDyn.Triggered = (trigger))
/* Set task running priority. */
#define OS_TASK_SETRUNPRIO(taskDyn, prio)         ((taskDyn)->currentPrio = (prio))
/* Get the resource list head associated with the task. */
#define OS_TASK_GETRESLISTHEAD(taskDyn)           (&((taskDyn)->resListHead))
/* Get the spinlock list head associated with the task. */
#define OS_TASK_GETSPINLISTHEAD(taskDyn)          (&((taskDyn)->spinListHead))
/* Determine that the task supports preemption. */
#define OS_TASK_CHECKTASKISFULLTYPE(taskDyn)      ((taskDyn)->schdType == OS_TASK_FULL)
/* Get the context of the task. */
#define OS_TASK_GETCONTEXT(taskDyn)               ((taskDyn)->context)
/* Get the context configuration of the task. */
#define OS_TASK_GETCONTEXTCFG(taskDyn)            (Os_TaskCfgData[(taskDyn)->taskId]->contextCfg)
/* Get the id of the task. */
#define OS_TASK_GETTASKID(taskDyn)                ((taskDyn)->taskId)
/* Get the stack start address of the task configuration. */
#define OS_TASK_GETSTACKSTARTADDR(taskCfg)        ((taskCfg)->contextCfg->stackStartAddr)
/* Get the stack end address of the task configuration. */
#define OS_TASK_GETSTACKENDADDR(taskCfg)          ((taskCfg)->contextCfg->stackEndAddr)
/* Check the given task is in suspended. */
#define OS_TASK_CHECKISSUSPENDED(taskCfg)         (SUSPENDED == (taskCfg)->taskDyn->state)
/* Get task running appid. */
#define OS_TASK_GETCURRENTAPPID(taskCfg)          ((taskCfg)->taskDyn->currentAppId)
/* Set task running appid. */
#define OS_TASK_SETCURRENTAPPID(taskCfg, appid)   ((taskCfg)->taskDyn->currentAppId = (appid))
/* Process idlemode hooks. */
#define OS_CONTROLIDLEHOOK(idleMode, coreId) do{ if(Os_CoreCfgData[coreId]->controlIdleHook != NULL_PTR)      \
                                    {Os_CoreCfgData[coreId]->controlIdleHook(idleMode);}                      \
                                    }while(0)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
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
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*
********************************************************************************
* Function Name: Os_Task_ActivateTaskSimp
*
* Explanation: Internal function to activate task.
*
* Param: task: Reference to an task.
*
* Retval: E_OS_OK: No error.
*         E_OS_LIMIT: Maximum task activations reached.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
********************************************************************************
*/
LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_Task_ActivateTaskSimp
(
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_APPL_CONST) taskCfg
)
{
    Os_StatusType ret = E_OS_OK;

    if( taskCfg != NULL_PTR )
    {
        /* If the activation is out range. */
        if( 0U == taskCfg->taskDyn->activationsCnt )
        {
            ret = E_OS_LIMIT;
        }
        else
        {
#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
            if( OS_CORE_CHECKTPISENABLE(taskCfg->coreId) )
            {
                /* Arrive timming protection. */
                (void)Os_Tp_CheckFrameInterval(taskCfg->tpCfg);
            }
#endif
            if( SUSPENDED == taskCfg->taskDyn->state )
            {
                /* Set task state to READY. */
                taskCfg->taskDyn->state = READY;
            }
            /* Decrease activation counter. */
            taskCfg->taskDyn->activationsCnt--;
            /* Insert tasks into the scheduler. */
            ret = Os_Schedler_InsertTask(OS_CORE_GETSCHEDULER(taskCfg->coreId), taskCfg->taskDyn);
        }
    }
    else
    {
        ret = E_OS_PARAM_POINTER;
    }

#if( (OS_CFG_ORTI_ENABLE == STD_ON) && (OS_CFG_ORTI_HOOK_ENABLE == STD_ON) )
    /* Call orti hook. */
    Os_Orit_TaskState_Trigger(taskCfg->coreId, taskCfg->taskId, OS_ORTI_TASK_ACTIVATE_TRIGGER);
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Task_SetEventTaskSimp
*
* Explanation: Internal function to set event.
*
* Param: task: Reference to an task.
*
* Retval: E_OS_OK: No error.
*         E_OS_STATE: Invalid state does not allow set event.
********************************************************************************
*/
LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_Task_SetEventTaskSimp
(
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_APPL_CONST) taskCfg
)
{
    Os_StatusType ret = E_OS_OK;

    if( taskCfg->taskType == OS_TASK_ET )
    {
#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
        if( (OS_CORE_CHECKTPISENABLE(taskCfg->coreId)) && (WAITING == taskCfg->taskDyn->state) )
        {
            /* Arrive timming protection. */
            (void)Os_Tp_CheckFrameInterval(taskCfg->tpCfg);
        }
#endif
        if( WAITING == taskCfg->taskDyn->state )
        {
            /* Set task state to READY. */
            taskCfg->taskDyn->state = READY;
            /* Delete the task from the scheduler. */
            ret = Os_Schedler_InsertTask(OS_CORE_GETSCHEDULER(taskCfg->coreId), taskCfg->taskDyn);
        }
    }
    else
    {
        ret = E_OS_STATE;
    }

#if( (OS_CFG_ORTI_ENABLE == STD_ON) && (OS_CFG_ORTI_HOOK_ENABLE == STD_ON) )
    /* Call orti hook. */
    Os_Orit_TaskState_Trigger(taskCfg->coreId, taskCfg->taskId, OS_ORTI_TASK_SETEVENT_TRIGGER);
#endif

    return ret;
}

extern FUNC(void, OS_CODE) Os_Task_Init
(
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_APPL_CONST) taskCfg,
    AppModeType appMode
);
extern FUNC(void, OS_CODE)  Os_Task_SetNextTaskData
(
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_APPL_CONST) nextCfg
);
extern FUNC(Os_StatusType, OS_CODE) Os_Task_TaskSwitch
(
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_APPL_CONST) currentCfg,
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_APPL_CONST) nextCfg
);
#if( OS_ARCH != ARCH_CONTEXT_M )
FUNC(Os_StatusType, OS_CODE) Os_Task_TaskSwitch_ForIsr
(
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_APPL_CONST) currentCfg,
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_APPL_CONST) nextCfg
);
#endif
extern FUNC(void, OS_CODE) Os_Task_StartFirst(CoreIdType coreId);
extern FUNC(void, OS_CODE) Os_Task_WrongReturn(void);
extern FUNC(void, OS_CODE) Os_Task_AppTerminateTask
(
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_APPL_CONST) taskCfg
);
extern FUNC(void, OS_CODE) Os_Task_AppTerminateTaskSwitch(ApplicationType appId);
extern FUNC(Os_StatusType, OS_CODE) Os_Task_WaitEvent
(
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_APPL_CONST) taskCfg
);
extern FUNC(Os_StatusType, OS_CODE) Os_Task_SetEvent
(
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_APPL_CONST) taskCfg
);
extern FUNC(Os_StatusType, OS_CODE) Os_Task_ActivateTask(TaskType taskId);
extern FUNC(Os_StatusType, OS_CODE) Os_Task_TerminateTask(void);
extern FUNC(Os_StatusType, OS_CODE) Os_Task_ChainTask(TaskType taskId);
extern FUNC(Os_StatusType, OS_CODE) Os_Task_GetTaskID(TaskRefType taskId);
extern FUNC(Os_StatusType, OS_CODE) Os_Task_GetTaskState
(
    TaskType taskId,
    TaskStateRefType state
);
extern FUNC(void, OS_CODE) Os_SysCallTaskWrongReturn(void);
#if( OS_CFG_MULTI_CORE == STD_ON )
extern FUNC(Os_StatusType, OS_CODE) Os_TargetActivateTask(TaskType taskId);
extern FUNC(Os_StatusType, OS_CODE) Os_TargetGetTaskState
(
    TaskType taskId,
    TaskStateRefType state
);
#endif /* OS_CFG_MULTI_CORE */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_TASK_H_ */

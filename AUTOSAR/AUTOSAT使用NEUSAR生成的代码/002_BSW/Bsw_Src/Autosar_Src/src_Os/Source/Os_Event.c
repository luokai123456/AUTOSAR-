/*
********************************************************************************
*
*  File name: Os_Event.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: YAOXJ/2021.11.22
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: YAOXJ/2021.12.31
* Change: Optimized coding specification.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: JiangGL/2022.11.24
* Change: Fix the bug of repeated execution of extended tasks.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: WangJP/2022.12.10
* Change: Modification of coding standard.
* Cause: Optimize
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2023.1.29
* Change: Resolve the CallErrorHook privilege level problem.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2023.4.5
* Change: Solved the issue of early activation of extended tasks.
* Cause: Bugfix
********************************************************************************
* Version: 3.7
* Author/Date: LiG/2023.5.26
* Change: The issue of unsuccessful modification of SetEvent cross core settings.
* Cause: Bugfix
********************************************************************************
* Version: 3.8
* Author/Date: LiG/2023.5.26
* Change: Optimize Errorhook calls for SetEvent interface.
* Cause: Optimize
********************************************************************************
* Version: 3.9
* Author/Date: JiangGL/2023.5.23
* Change: Fixed an error in extending the task, which caused the task to
*         mistakenly trigger an execution time protection due to the event
*         activation cycle being shorter than the task execution cycle.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: LiG/2023.5.27
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: LiG/2023.6.12
* Change: Resolving SetEvent error issues.
* Cause: Bugfix
********************************************************************************
* Version: 3.12
* Author/Date: ZhangY/2023.10.07
* Change: 1. Modify incorrect return value in API description in many functions.
*         2. Modify Os_Event_WaitEvent for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: LiG/2024.05.22
* Change: Add Spinlock macro switch.
* Cause: Optimization
********************************************************************************
* Version: 3.14
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
#include "Os_Cfg.h"
#include "Os_Event.h"
#include "Os_SysCall.h"
#include "Os_MultiCore.h"
#include "Os_Hook.h"
#include "Os_TmProtection.h"
#include "Os_Orti.h"
#include "Os.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/* Event trigger initial value. */
#define OS_EVENT_TRIGGER_INIT           (0U)

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
#if(  OS_CFG_EVENT_ENABLE == STD_ON  )
LOCAL_INLINE FUNC(void, OS_CODE) Os_Event_GetEventSimp
(
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_APPL_CONST) task,
    EventMaskRefType mask
);
#endif /* OS_CFG_EVENT_ENABLE == STD_ON */

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
#if(  OS_CFG_EVENT_ENABLE == STD_ON  )
/*
********************************************************************************
* Function Name: Os_Event_GetEventSimp
*
* Explanation: Internal function  uses to get event.
*
* Param: task: Reference to an task.
*        mask: Mask of the events to be set.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Event_GetEventSimp
(
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_APPL_CONST) task,
    EventMaskRefType mask
)
{
    (*mask) = OS_TASK_GETEVENTTRIGGER(task);
}

/*
********************************************************************************
* Function Name: Os_Event_SetEvent
*
* Explanation: Uses to set event.
*
* Param: taskId: Reference to the task for which one or several events are to be set.
*        mask: Mask of the events to be set.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid taskId.
*         E_OS_STATE: Application is not in correct state to perform the requested
*                     operation or task is suspended.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Event_SetEvent(TaskType taskId, EventMaskType mask)
{
    Os_StatusType ret;
    CoreIdType coreId;
    const Os_TaskCfgType* taskCfg;
    Os_Arch_IntState intState;
    EventMaskType eventWaiting;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_SetEvent);
    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();

    if( OS_TASK_ISINVAILD(taskId) ) /* If task id in the range. */
    {
        ret = E_OS_ID;
    }
    else if( OS_CORE_MASK_INTERRUPT(coreId) ) /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_SETEVENT_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        /* Get task configuration data. */
        taskCfg = OS_TASK_GETCFG(taskId);
        if( OS_APPMATCH(taskCfg->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission. */
        {
            ret = E_OS_ACCESS;
        }
        else
        {
#if( OS_CFG_MULTI_CORE == STD_ON )
            /* If the set event task is the same core. */
            if( coreId == OS_TASK_GETCOREID(taskCfg) )
#endif
            {

                if( OS_TASK_ISBASIC(taskCfg) ) /* If task is basic. */
                {
                    ret = E_OS_ACCESS;
                }
                else if( OS_APP_STATEOFF(taskCfg->ownerAppId) ) /* If the application is not accessible. */
                {
                    ret = E_OS_ACCESS;
                }
                else if( OS_TASK_CHECKISSUSPENDED(taskCfg) ) /* If task is suspended. */
                {
                    ret = E_OS_STATE;
                }
                else
                {
                    /* Disable interrupt. */
                    Os_Arch_IntDisable(&intState);
                    eventWaiting = OS_TASK_GETEVENTWAIT(taskCfg);

                    /* Set event trigger. */
                    ret = Os_Event_SetEventSimp(taskCfg, mask);

                    if( E_OS_OK == ret )
                    {
                        if( (WAITING == OS_TASK_GETTASKSTATE(taskCfg)) && (0U != (eventWaiting & mask)) )
                        {
                            ret = Os_Task_SetEvent(taskCfg);
                        }
                    }
                    /* Enable interrupt. */
                    Os_Arch_IntEnable(intState);
                }
            }

#if( OS_CFG_MULTI_CORE == STD_ON )
            else
            {
                /* Set event of target core. */
                Os_MultiCoreServeParamType parameter;
                parameter.Os_SetEvent.taskId = taskId;
                parameter.Os_SetEvent.mask = mask;
                /* Execute multi-core calling function. */
                ret = Os_MultiCore_Trigger(TRUE, coreId, OS_TASK_GETCOREID(taskCfg),
                                            Os_MCServe_SetEvent_ID, &parameter);
            }
#endif
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_SetEvent);

    return Os_Hook_CallErrorHook(OSServiceId_SetEvent, ret);
}

/*
********************************************************************************
* Function Name: Os_Event_ClearEvent
*
* Explanation: Uses to clear event.
*
* Param: mask: Mask of the events to clear.
*
* Retval: E_OS_OK: No error.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Event_ClearEvent(EventMaskType mask)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    const Os_TaskCfgType* taskCfg;
    Os_Arch_IntState intState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_ClearEvent);
    /* Get logic core id */
    coreId = Os_Core_GetLogicId();

    if( OS_CORE_MASK_INTERRUPT(coreId) ) /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_CLEAREVENT_ACCESS) ) /* If the api is not accessible */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        /* Get task configuration data. */
        taskCfg = OS_TASK_GETCFG(OS_CORE_GETCURRENTTASKID(coreId));

        if( OS_TASK_ISBASIC(taskCfg) ) /* If task is basic. */
        {
            ret = E_OS_ACCESS;
        }
        else
        {
            /* Disable interrupt. */
            Os_Arch_IntDisable(&intState);

            OS_TASK_GETEVENTTRIGGER(taskCfg) &= (~mask);

            /* Enable interrupt. */
            Os_Arch_IntEnable(intState);
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_ClearEvent);

    return Os_Hook_CallErrorHook(OSServiceId_ClearEvent, ret);
}

/*
********************************************************************************
* Function Name: Os_Event_GetEvent
*
* Explanation: Uses to get event.
*
* Param: taskId: Reference to the task for which one or several events are to be set.
*        mask: Mask of the events to get.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid taskId.
*         E_OS_STATE: Application is not in correct state to perform the requested
*                     operation or task is suspended.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Event_GetEvent(TaskType taskId, EventMaskRefType mask)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    const Os_TaskCfgType* taskCfg;
    Os_Arch_IntState intState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_GetEvent);
    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();

    if( OS_TASK_ISINVAILD(taskId) ) /* If task id in the range. */
    {
        ret = E_OS_ID;
    }
    else if( OS_CORE_MASK_INTERRUPT(coreId) ) /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( NULL_PTR == mask ) /* If mask is null. */
    {
        ret = E_OS_PARAM_POINTER;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_GETEVENT_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        /* Get task configuration data. */
        taskCfg = OS_TASK_GETCFG(taskId);

        if( OS_APPMATCH(taskCfg->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission. */
        {
            ret = E_OS_ACCESS;
        }
        else if( OS_TASK_ISBASIC(taskCfg) ) /* If task is basic. */
        {
            ret = E_OS_ACCESS;
        }
        else if( OS_APP_STATEOFF(taskCfg->ownerAppId) ) /* If the application is not accessible. */
        {
            ret = E_OS_ACCESS;
        }
        else if( OS_TASK_CHECKISSUSPENDED(taskCfg) ) /* If task is suspended. */
        {
            ret = E_OS_STATE;
        }
        else
        {
            /* Disable interrupt. */
            Os_Arch_IntDisable(&intState);
            /* Get event trigger mask. */
            Os_Event_GetEventSimp(taskCfg, mask);
            /* Enable interrupt. */
            Os_Arch_IntEnable(intState);
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_GetEvent);

    return Os_Hook_CallErrorHook(OSServiceId_GetEvent, ret);
}

/*
********************************************************************************
* Function Name: Os_Event_WaitEvent
*
* Explanation: Uses to wait event.
*
* Param: mask: Mask of the events to wait.
*
* Retval: E_OS_OK: No error.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_SPINLOCK: TASK has occupied a spinlock.
*         E_OS_RESOURCE: TASK has occupied a resources.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Event_WaitEvent(EventMaskType mask)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    const Os_TaskCfgType* taskCfg;
    EventMaskType wait;
    EventMaskType trigger;
    EventMaskType waitTrigger;
    Os_Arch_IntState intState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_WaitEvent);
    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();

    if( OS_CORE_MASK_INTERRUPT(coreId) ) /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_WAITEVENT_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        /* Get task configuration data. */
        taskCfg = OS_TASK_GETCFG(OS_CORE_GETCURRENTTASKID(coreId));

        if( OS_APPMATCH(taskCfg->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission. */
        {
            ret = E_OS_ACCESS;
        }
        else if( OS_TASK_MASK_RESOURCE(taskCfg) ) /* If the resource is release. */
        {
            ret = E_OS_RESOURCE;
        }
#if( OS_CFG_SPINLOCK_ENABLE == STD_ON )
        else if( OS_TASK_MASK_SPINLOCK(taskCfg) ) /* If the spinlock is release. */
        {
            ret = E_OS_SPINLOCK;
        }
#endif /* OS_CFG_SPINLOCK_ENABLE == STD_ON */
        else if( OS_TASK_ISBASIC(taskCfg) ) /* If task is basic. */
        {
            ret = E_OS_ACCESS;
        }
        else
        {
            /* Disable interrupt. */
            Os_Arch_IntDisable(&intState);
            /* Set event waiting is mask. */
            OS_TASK_SETEVENTWAIT(taskCfg, mask);
            wait = OS_TASK_GETEVENTWAIT(taskCfg);
            trigger = OS_TASK_GETEVENTTRIGGER(taskCfg);
            waitTrigger = (wait & trigger);

            if( OS_EVENT_TRIGGER_INIT != waitTrigger )
            {
#if ( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
                if( OS_CORE_CHECKTPISENABLE(taskCfg->coreId) )
                {
                    /* Timing protection check frame interval. */
                    (void)Os_Tp_CheckFrameInterval(taskCfg->tpCfg);
                    /* Reset current budget. */
                    Os_Tp_ResetCurrentBudget(taskCfg->tpCfg, coreId);
                    /* Satrt next time protection budget. */
                    Os_Tp_StartNextBudget(taskCfg->tpCfg, coreId);
                }
#endif
            }
            else
            {
                ret = Os_Task_WaitEvent(taskCfg);
            }
            /* Enable interrupt. */
            Os_Arch_IntEnable(intState);
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_WaitEvent);

    return Os_Hook_CallErrorHook(OSServiceId_WaitEvent, ret);
}

#if( OS_CFG_MULTI_CORE == STD_ON )
/*
********************************************************************************
* Function Name: Os_TargetSetEvent
*
* Explanation: Multicore function to set event.
*
* Param: taskId: Reference to the task for which one or several events are to be set.
*        mask: Mask of the events to be set.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid taskId.
*         E_OS_CORE: Core is not available.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*         E_OS_STATE: Invalid state does not allow set event.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_TargetSetEvent(TaskType taskId, EventMaskType mask)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    const Os_TaskCfgType* taskCfg;
    EventMaskType eventWaiting;

    if( OS_TASK_ISINVAILD(taskId) ) /* If task id in the range. */
    {
        ret = E_OS_ID;
    }
    else
    {
        /* Get task configuration data. */
        taskCfg = OS_TASK_GETCFG(taskId);
        /* Get logic core id. */
        coreId = Os_Core_GetLogicId();
        /* If the activate task is the same core. */
        if( coreId == OS_TASK_GETCOREID(taskCfg) )
        {
            if( OS_TASK_ISBASIC(taskCfg) ) /* If task is basic. */
            {
                ret = E_OS_ACCESS;
            }
            else if( OS_APP_STATEOFF(taskCfg->ownerAppId) ) /* If the application is not accessible. */
            {
                ret = E_OS_ACCESS;
            }
            else if( OS_TASK_CHECKISSUSPENDED(taskCfg) ) /* If task is suspended. */
            {
                ret = E_OS_STATE;
            }
            else
            {
                eventWaiting = OS_TASK_GETEVENTWAIT(taskCfg);
                if( 0U != (eventWaiting & mask) )
                {
                    /* Set event trigger. */
                    ret = Os_Event_SetEventSimp(taskCfg, mask);

                    if( E_OS_OK == ret )
                    {
                        if( WAITING == OS_TASK_GETTASKSTATE(taskCfg) )
                        {
                            ret = Os_Task_SetEvent(taskCfg);
                        }
                    }
                }
            }
        }
        else
        {
            ret = E_OS_CORE;
        }
    }

    return ret;
}
#endif

/*
********************************************************************************
* Function Name: SetEvent
*
* Explanation: Standard API function, uses to set event.
*
* Param: TaskID: Reference to the task for which one or several events are to be set.
*        Mask: Mask of the events to be set.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid taskId.
*         E_OS_STATE: Application is not in correct state to perform the requested
*                     operation or task is suspended.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) SetEvent(TaskType TaskID, EventMaskType Mask)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_SetEvent.taskId = TaskID;
    sysCallParam.Os_SetEvent.mask = Mask;
    Os_SysCall(Os_Syscall_SetEvent_ID, &sysCallParam);
    ret = sysCallParam.Os_SetEvent.retVal;
#else
    ret = Os_Event_SetEvent(TaskID, Mask);
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: ClearEvent
*
* Explanation: Standard API function, uses to clear event.
*
* Param: Mask: Mask of the events to be set.
*
* Retval: E_OS_OK: No error.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) ClearEvent(EventMaskType Mask)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_ClearEvent.mask = Mask;
    Os_SysCall(Os_Syscall_ClearEvent_ID, &sysCallParam);
    ret = sysCallParam.Os_ClearEvent.retVal;
#else
    ret = Os_Event_ClearEvent(Mask);
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: GetEvent
*
* Explanation: Standard API function, uses to get event.
*
* Param: TaskID: Reference to the task for which one or several events are to be set.
*        Mask: Mask of the events to be set.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid TaskID.
*         E_OS_STATE: Application is not in correct state to perform the requested
*                     operation or task is suspended.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) GetEvent(TaskType TaskID, EventMaskRefType Mask)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_GetEvent.taskId = TaskID;
    sysCallParam.Os_GetEvent.mask = Mask;
    Os_SysCall(Os_Syscall_GetEvent_ID, &sysCallParam);
    ret = sysCallParam.Os_GetEvent.retVal;
#else
    ret = Os_Event_GetEvent(TaskID, Mask);
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: WaitEvent
*
* Explanation: Standard API function, uses to wait event.
*
* Param: Mask: Mask of the events to be set.
*
* Retval: E_OS_OK: No error.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*         E_OS_SPINLOCK: TASK has occupied a spinlock.
*         E_OS_RESOURCE: TASK has occupied a resources.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) WaitEvent(EventMaskType Mask)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_WaitEvent.mask = Mask;
    Os_SysCall(Os_Syscall_WaitEvent_ID, &sysCallParam);
    ret = sysCallParam.Os_WaitEvent.retVal;
#else
    ret = Os_Event_WaitEvent(Mask);
#endif

    return ret;
}
#endif /* OS_CFG_EVENT_ENABLE == STD_ON */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

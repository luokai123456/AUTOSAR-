/*
********************************************************************************
*
*  File name: Os_Alarm.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.14
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2022.11.21
* Change: Change OS_VAR_NOINIT to OS_VAR_NO_INIT.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.1.29
* Change: Resolve the CallErrorHook privilege level problem.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2023.5.27
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: JiangGL/2023.6.9
* Change: Solve the issue of setting expiration points for error reporting.
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: ZhangY/2023.10.07
* Change: Modify incorrect return value in API description in many functions.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: ZhangY/2023.12.06
* Change: 1. Modify incorrect return value in API description in many functions.
*         2. Modify Os_Alarm_GetAlarm and Os_Alarm_GetAlarmBase to fix bug of
*            getting wrong alarm tickvalue in cross core situation.
* Cause: Bugfix
********************************************************************************
* Version: 3.8
* Author/Date: LiG/2023.3.15
* Change: Remove the Alarm status judgment from the Os_Alarm_IntGetAlarmBase
*         interface.
* Cause: Bugfix
********************************************************************************
* Version: 3.9
* Author/Date: LiG/2024.5.6
* Change: When an error occurs in a cross core interface call, the output
*         parameter data is changed.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
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
#include "Os_Alarm.h"
#include "Os_Core.h"
#include "Os_Task.h"
#include "Os_Isr.h"
#include "Os_App.h"
#include "Os_Event.h"
#include "Os_SysCall.h"
#include "Os_MultiCore.h"
#include "Os_Hook.h"
#include "Os_Orti.h"
#include "Os.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/* Get the alarm static configuration. */
#define OS_ALARM_GETCFG(alarmId)        (Os_AlarmCfgData[alarmId])
/* Get the core id to which the alarm belongs throughthe alarm static
   configuration. */
#define OS_ALARM_GETCOREID(alarmCfg)    ((alarmCfg)->coreId)
/* Get the counter configuration to which the alarm belongs throughthe alarm
   dynamic configuration. */
#define OS_ALARM_GETCNTCFG(alarmDyn)    ((alarmDyn)->counter)

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
LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_Alarm_IntGetAlarm
(
    P2CONST(Os_AlarmDynType, AUTOMATIC, OS_APPL_CONST) alarmDyn,
    TickRefType tick
);
LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_Alarm_IntGetAlarmBase
(
    P2CONST(Os_AlarmDynType, AUTOMATIC, OS_APPL_CONST) alarmDyn,
    AlarmBaseRefType info
);
LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_Alarm_IntSetRelAlarm
(
    P2VAR(Os_AlarmDynType, AUTOMATIC, OS_APPL_DATA) alarmDyn,
    Os_TickType increment,
    Os_TickType cycle
);
LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_Alarm_IntSetAbsAlarm
(
    P2VAR(Os_AlarmDynType, AUTOMATIC, OS_APPL_DATA) alarmDyn,
    Os_TickType start,
    Os_TickType cycle
);
LOCAL_INLINE FUNC(void, OS_CODE) Os_Alarm_IntCancel
(
    P2VAR(Os_AlarmDynType, AUTOMATIC, OS_APPL_DATA) alarmDyn
);

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
* Function Name: Os_Alarm_IntGetAlarm
*
* Explanation: Internal function to get the relative value in ticks before the
*              alarm expires.
*
* Param: alarmDyn: Reference to an alarm.
*        tick: Relative value in ticks before the alarm expires.
*
* Retval: E_OS_OK: No error.
*         E_OS_NOFUNC: Alarm is off.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
********************************************************************************
*/
LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_Alarm_IntGetAlarm
(
    P2CONST(Os_AlarmDynType, AUTOMATIC, OS_APPL_CONST) alarmDyn,
    TickRefType tick
)
{
    Os_StatusType ret = E_OS_OK;

    if( alarmDyn != NULL_PTR )
    {
        /* If the alarm is off. */
        if( OS_ALARM_OFF == alarmDyn->state )
        {
            ret = E_OS_NOFUNC;
        }
        else
        {
            /* Get the relative value in ticks. */
            ret = Os_Counter_GetExpTick(OS_ALARM_GETCNTCFG(alarmDyn), &alarmDyn->expNode, tick);
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Alarm_IntGetAlarmBase
*
* Explanation: Internal function to get the alarm base characteristics.
*
* Param: alarmDyn: Reference to an alarm.
*        info: Reference to structure with constants of the alarm base.
*
* Retval: E_OS_OK: No error.
*         E_OS_NOFUNC: Alarm is off.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
********************************************************************************
*/
LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_Alarm_IntGetAlarmBase
(
    P2CONST(Os_AlarmDynType, AUTOMATIC, OS_APPL_CONST) alarmDyn,
    AlarmBaseRefType info
)
{
    Os_StatusType ret = E_OS_OK;

    if( alarmDyn != NULL_PTR )
    {
        /* Get the counter base information. */
        ret = Os_Counter_GetBase(alarmDyn->counter, info);
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Alarm_IntSetRelAlarm
*
* Explanation: Internal function to activate the relative alarm.
*
* Param: alarmDyn: Reference to an alarm.
*        increment: Relative value in ticks.
*        cycle: Cycle value in case of cyclic alarm. In case of single alarms,
*               cycle shall be zero.
*
* Retval: E_OS_OK: No error.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
********************************************************************************
*/
LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_Alarm_IntSetRelAlarm
(
    P2VAR(Os_AlarmDynType, AUTOMATIC, OS_APPL_DATA) alarmDyn,
    Os_TickType increment,
    Os_TickType cycle
)
{
    Os_StatusType ret;

    if( alarmDyn != NULL_PTR )
    {
        /* Set alarm sate. */
        alarmDyn->state = OS_ALARM_SET;
        /* Set alarm cycle. */
        alarmDyn->cycle = cycle;
        /* Insert expiry point into counter. */
        ret = Os_Counter_InsertExpPoint(alarmDyn->counter, &alarmDyn->expNode, increment);
    }
    else
    {
        ret = E_OS_PARAM_POINTER;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Alarm_IntSetAbsAlarm
*
* Explanation: Internal function to activate the absolute alarm.
*
* Param: alarmDyn: Reference to an alarm.
*        start: Absolute value in ticks.
*        cycle: Cycle value in case of cyclic alarm. In case of single alarms,
*               cycle shall be zero.
*
* Retval: E_OS_OK: No error.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
********************************************************************************
*/
LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_Alarm_IntSetAbsAlarm
(
    P2VAR(Os_AlarmDynType, AUTOMATIC, OS_APPL_DATA) alarmDyn,
    Os_TickType start,
    Os_TickType cycle
)
{
    Os_StatusType ret;

    if( alarmDyn != NULL_PTR )
    {
        /* Set alarm sate. */
        alarmDyn->state = OS_ALARM_SET;
        /* Set alarm cycle. */
        alarmDyn->cycle = cycle;
        /* Insert the absolute expiration point into the counter. */
        ret = Os_Counter_InsertAbsExpPoint(alarmDyn->counter, &alarmDyn->expNode, start);
    }
    else
    {
        ret = E_OS_PARAM_POINTER;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Alarm_IntCancel
*
* Explanation:  Internal function to cancel the alarm.
*
* Param: alarmDyn: Reference to an alarm.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Alarm_IntCancel
(
    P2VAR(Os_AlarmDynType, AUTOMATIC, OS_APPL_DATA) alarmDyn
)
{
    Os_CntExpListNodeCfgType* expListNode;

    if( alarmDyn != NULL_PTR )
    {
        /* Set alarm sate to OFF. */
        alarmDyn->state = OS_ALARM_OFF;
        /* Clear alarm cycle. */
        alarmDyn->cycle = OS_ALARM_INIT;
        /* Delete expiration point. */
        expListNode = &(alarmDyn->expNode);
        /* Determine if the target expiration point that needs to be deleted is valid. */
        if( NULL_PTR != expListNode )
        {
#if( OS_HRT_ENABLE == STD_ON )
            /* Determine Counter Type. */
            if( OS_COUNTER_HRT == alarmDyn->counter->counterType )
            {
                Os_CntExpListNodeCfgType* CurrentExpListNode;

                /* Obtain the expiration point that Counter is about to trigger. */
                (void)Os_Counter_GetCurretExpList(alarmDyn->counter, &CurrentExpListNode);
                /* Delete target expiration point. */
                (void)Os_Counter_ExpPointDel(alarmDyn->counter, expListNode);
                /* Determine whether the target expiration point that needs to be deleted
                   is consistent with the expiration point that is about to be triggered. */
                if( expListNode == CurrentExpListNode )
                {
                    Os_TickType lastValue;
                    Os_TickType nowValue;
                    Os_TickType startValue;
                    Os_TickType targetCompare;
                    const Os_CounterHrtCfgType* cntCfg = (const Os_CounterHrtCfgType*)(alarmDyn->counter);

                    nowValue = Os_Arch_Mach_HrtTimerGetValue(cntCfg->HwConfig);
                    targetCompare = CurrentExpListNode->expTimestamp.timebase;
                    /* Obtain the Counter value from the previous Compare setting in advance. */
                    lastValue = cntCfg->counterDyn->lastValue;
                    if( OS_COUNTER_TICKSUB(alarmDyn->counter, nowValue, lastValue) >=
                    OS_COUNTER_TICKSUB(alarmDyn->counter, targetCompare, lastValue) )
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
                    Os_Counter_SetNextPoint(alarmDyn->counter, startValue);
                }
            }
            else
            {
#endif /* OS_HRT_ENABLE == STD_ON */
                (void)Os_Counter_ExpPointDel(alarmDyn->counter, expListNode);
#if( OS_HRT_ENABLE == STD_ON )
            }
#endif /* OS_HRT_ENABLE == STD_ON */
        }

    }
}
/*
********************************************************************************
* Function Name: Os_Alarm_ActSetEvent
*
* Explanation: Alarm trigger set event action.
*
* Param: expListNode: Alarm expiry point.
*
* Retval: setNextPointFlag: Next expiry point flag.
********************************************************************************
*/
#if( OS_CFG_EVENT_ENABLE == STD_ON )
FUNC(uint8, OS_CODE) Os_Alarm_ActSetEvent
(
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) expListNode
)
{
#if( OS_CFG_MULTI_CORE == STD_ON )
    CoreIdType coreId;
#endif
    Os_StatusType ret;
    Os_AlarmDynType* AlarmDyn;
    const Os_CounterBaseCfgType* counterBaseCfg;
    const Os_TaskCfgType* taskCfg;
    uint8 setNextPointFlag = OS_COUNTER_NOTSET_POINT;

    if( expListNode != NULL_PTR )
    {
        AlarmDyn = (Os_AlarmDynType*)expListNode;
        counterBaseCfg = AlarmDyn->counter;
        taskCfg = OS_TASK_GETCFG(expListNode->workParam.eventParam.taskId);

        if( OS_APP_STATEOFF(taskCfg->ownerAppId) )   /* If the application is not accessible. */
        {
            ret = E_OS_ACCESS;
        }
        else if( OS_TASK_CHECKISSUSPENDED(taskCfg) ) /* If task is suspended. */
        {
            ret = E_OS_STATE;
        }
        else
        {
            /* Set the next expiration point. */
            if( AlarmDyn->cycle != OS_ALARM_INIT )
            {
                Os_Counter_SetExpPoint(counterBaseCfg,
                                       expListNode->expTimestamp.timebase,
                                       AlarmDyn->cycle,
                                       expListNode);
                setNextPointFlag = OS_COUNTER_SET_POINT;
            }
            else
            {
                AlarmDyn->state = OS_ALARM_OFF;
            }
#if( OS_CFG_MULTI_CORE == STD_ON )
            /* Get logic core id. */
            coreId = Os_Core_GetLogicId();
            /* If the activate task is the same core. */
            if( coreId == OS_TASK_GETCOREID(taskCfg) )
#endif
            {
                ret = Os_Event_SetEventSimp(taskCfg, expListNode->workParam.eventParam.eventMask);
                if( E_OS_OK == ret )
                {
                    ret = Os_Task_SetEventTaskSimp(taskCfg);
                }
            }
#if( OS_CFG_MULTI_CORE == STD_ON )
            else
            {
                Os_MultiCoreServeParamType parameter;

                parameter.Os_SetEvent.taskId = expListNode->workParam.eventParam.taskId;
                parameter.Os_SetEvent.mask = expListNode->workParam.eventParam.eventMask;
                /* Execute multi-core calling function. */
                ret = Os_MultiCore_Trigger(FALSE, coreId, OS_TASK_GETCOREID(taskCfg),
                                           Os_MCServe_AlarmSetEvent_ID, &parameter);
            }
#endif
        }
    }
    else
    {
        ret = E_OS_PARAM_POINTER;
    }

    (void)Os_Hook_CallErrorHook(OSServiceId_SetEvent, ret);

    return setNextPointFlag;
}
#endif /* OS_CFG_EVENT_ENABLE == STD_ON */

/*
********************************************************************************
* Function Name: Os_Alarm_ActActivateTask
*
* Explanation: Alarm trigger activate task action.
*
* Param: expListNode: Alarm expiry point.
*
* Retval: setNextPointFlag: Next expiry point flag.
********************************************************************************
*/
FUNC(uint8, OS_CODE) Os_Alarm_ActActivateTask
(
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) expListNode
)
{
#if( OS_CFG_MULTI_CORE == STD_ON )
    CoreIdType coreId;
#endif
    Os_StatusType ret;
    Os_AlarmDynType* AlarmDyn;
    const Os_CounterBaseCfgType* counterBaseCfg;
    const Os_TaskCfgType* taskCfg;
    uint8 setNextPointFlag = OS_COUNTER_NOTSET_POINT;

    if( expListNode != NULL_PTR )
    {
        AlarmDyn = (Os_AlarmDynType*)expListNode;
        counterBaseCfg = OS_ALARM_GETCNTCFG(AlarmDyn);
        taskCfg = OS_TASK_GETCFG(expListNode->workParam.taskId);

        if( OS_APP_STATEOFF(taskCfg->ownerAppId) ) /* If the application is not accessible. */
        {
            ret = E_OS_ACCESS;
        }
        else
        {
            /* Set the next expiration point. */
            if( AlarmDyn->cycle != OS_ALARM_INIT )
            {
                Os_Counter_SetExpPoint(counterBaseCfg, expListNode->expTimestamp.timebase,
                                       AlarmDyn->cycle, expListNode);
                setNextPointFlag = OS_COUNTER_SET_POINT;
            }
            else
            {
                AlarmDyn->state = OS_ALARM_OFF;
            }
#if( OS_CFG_MULTI_CORE == STD_ON )
            /* Get logic core id. */
            coreId = Os_Core_GetLogicId();
            /* If the activate task is the same core. */
            if( coreId == OS_TASK_GETCOREID(taskCfg) )
#endif
            {
                /* Activate the configured task */
                ret = Os_Task_ActivateTaskSimp(taskCfg);
            }
#if( OS_CFG_MULTI_CORE == STD_ON )
            else
            {
                Os_MultiCoreServeParamType parameter;
                parameter.Os_ActivateTask.taskId = expListNode->workParam.eventParam.taskId;
                /* Execute multi-core calling function. */
                ret = Os_MultiCore_Trigger(FALSE, coreId, OS_TASK_GETCOREID(taskCfg),
                                           Os_MCServe_AlarmActivateTask_ID, &parameter);
            }
#endif
        }
    }
    else
    {
        ret = E_OS_PARAM_POINTER;
    }

    (void)Os_Hook_CallErrorHook(OSServiceId_ActivateTask, ret);

    return setNextPointFlag;
}

/*
********************************************************************************
* Function Name: Os_Alarm_ActIcrmCnt
*
* Explanation: Alarm trigger increment counter action.
*
* Param: expListNode: Alarm expiry point.
*
* Retval: setNextPointFlag: Next expiry point flag.
********************************************************************************
*/
FUNC(uint8, OS_CODE) Os_Alarm_ActIcrmCnt
(
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) expListNode
)
{
    Os_AlarmDynType* AlarmDyn;
    const Os_CounterBaseCfgType* counterBaseCfg;
    uint8 setNextPointFlag = OS_COUNTER_NOTSET_POINT;

    if( expListNode != NULL_PTR )
    {
        AlarmDyn = (Os_AlarmDynType*)expListNode;
        counterBaseCfg = OS_ALARM_GETCNTCFG(AlarmDyn);
        /* Increments a software counter. */
        (void)Os_Counter_IcrmCnt(counterBaseCfg, OS_COUNTER_GETDYN(counterBaseCfg, const Os_CounterSwCfgType*));
    }

    return setNextPointFlag;
}

/*
********************************************************************************
* Function Name: Os_Alarm_ActCallback
*
* Explanation:  Alarm trigger call callback action.
*
* Param: expListNode: Alarm expiry point.
*
* Retval: None
********************************************************************************
*/
FUNC(uint8, OS_CODE) Os_Alarm_ActCallback
(
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) expListNode
)
{
    Os_ProcType procType;
    CoreIdType coreId;
    Os_AlarmDynType* alarmDyn;
    const Os_AlarmCfgType* alarmCfg;
    uint8 setNextPointFlag = OS_COUNTER_NOTSET_POINT;

    if( expListNode != NULL_PTR )
    {
        /* Get alarm running data. */
        alarmDyn = (Os_AlarmDynType*)expListNode;
        /* Get alarm configuration data. */
        alarmCfg = OS_ALARM_GETCFG(alarmDyn->alarmId);
        /* Get logic core id. */
        coreId = Os_Core_GetLogicId();
        /* Save the current processor execution type. */
        procType = OS_CORE_GETPROTYPE(coreId);
        /* Set the current processor execution type to alarm.*/
        OS_CORE_SETPROTYPE(coreId, OS_ALARM_TYPE_MASK);
        /* Call back function. */
        alarmCfg->alarm_CallBack();
        /* Restore the current processor execution type. */
        OS_CORE_SETPROTYPE(coreId, procType);
    }

    return setNextPointFlag;
}

/*
********************************************************************************
* Function Name: Os_Alarm_Init
*
* Explanation: Initialize the alarm object.
*
* Param: alarmCfg: Reference to the alarm configuration.
*        appMode: The mode of the application to which the alarm belongs.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Alarm_Init
(
    P2CONST(Os_AlarmCfgType, AUTOMATIC, OS_APPL_CONST) alarmCfg,
    AppModeType appMode
)
{
    Os_AlarmDynType* alarmDyn;

    if( NULL_PTR != alarmCfg )
    {
        /* Get alarm running data. */
        alarmDyn = alarmCfg->alarmDyn;
        /* Set alarm sate to OFF. */
        alarmDyn->state = OS_ALARM_OFF;
        /* Clear alarm cycle. */
        alarmDyn->cycle = OS_ALARM_INIT;
        /* Set counter configuration. */
        alarmDyn->counter = alarmCfg->counter;
        /* Set alarm index. */
        alarmDyn->alarmId = alarmCfg->alarmId;
        /* Set expiration point information. */
        alarmDyn->expNode.expTimestamp.timebase = OS_ALARM_INIT;
        alarmDyn->expNode.expKind = alarmCfg->cntExpKind;
        alarmDyn->expNode.workParam = alarmCfg->workParam;
        /* If the alarm is autostart. */
        if( (alarmCfg->appMode & appMode) != 0U )
        {
            /* Set alarm sate to SET. */
            alarmDyn->state = OS_ALARM_SET;
            /* Set alarm cycle. */
            alarmDyn->cycle = alarmCfg->autoCycle;
            /* If the alarm is absolute. */
            if( OS_ALARM_ABS == alarmCfg->alarmMode )
            {
                /* Set the absolute expiration point to the counter. */
                (void)Os_Counter_InsertAbsExpPoint(alarmDyn->counter, &alarmDyn->expNode, alarmCfg->alarmTime);
            }
            else
            {
                /* Insert expiry point into counter. */
                (void)Os_Counter_InsertExpPoint(alarmDyn->counter, &alarmDyn->expNode, alarmCfg->alarmTime);
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Os_Alarm_AppTerminateAlarm
*
* Explanation: Terminate the alarm.
*
* Param: alarmCfg: Reference to an alarm.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Alarm_AppTerminateAlarm
(
    P2CONST(Os_AlarmCfgType, AUTOMATIC, OS_APPL_CONST) alarmCfg
)
{
    Os_AlarmDynType* alarmDyn;

    /* If the pointer is empty. */
    if( alarmCfg != NULL_PTR )
    {
        /* Get alarm running data. */
        alarmDyn = alarmCfg->alarmDyn;
        Os_Alarm_IntCancel(alarmDyn);
    }
}

/*
********************************************************************************
* Function Name: Os_Alarm_GetAlarm
*
* Explanation: Get the relative value in ticks before the alarm expires.
*
* Param: alarmId: Reference to the alarm index.
*        tick: Relative value in ticks before the alarm expires.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid AlarmID.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_CORE: Core is not available.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      Given alarm's owner application is not accessible.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Alarm_GetAlarm
(
    AlarmType alarmId,
    TickRefType tick
)
{
    Os_StatusType ret;
    CoreIdType coreId;
    Os_AlarmDynType* alarmDyn;
    const Os_AlarmCfgType* alarmCfg;
    Os_Arch_IntState intState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_GetAlarm);
    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();

    if( NULL_PTR == tick )
    {
        ret = E_OS_PARAM_POINTER;
    }
    else if( alarmId >= OS_ALARMID_COUNT )
    {
        ret = E_OS_ID;
    }
    else if( OS_CORE_MASK_INTERRUPT(coreId) ) /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_GETALARM_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        /* Get alarm configuration data. */
        alarmCfg = OS_ALARM_GETCFG(alarmId);
        if( OS_APPMATCH(alarmCfg->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission. */
        {
            ret = E_OS_ACCESS;
        }
        else
        {
#if( OS_CFG_MULTI_CORE == STD_ON )
            if( coreId == OS_ALARM_GETCOREID(alarmCfg) )
#endif
            {
                if( OS_APP_STATEOFF(alarmCfg->ownerAppId) ) /* If the application is not accessible. */
                {
                    ret = E_OS_ACCESS;
                }
                else
                {
                    /* Get alarm running data. */
                    alarmDyn = alarmCfg->alarmDyn;
                    /* Disable interrupt. */
                    Os_Arch_IntDisable(&intState);
                    ret = Os_Alarm_IntGetAlarm(alarmDyn, tick);
                    /* Enable interrupt. */
                    Os_Arch_IntEnable(intState);
                }
            }
#if( OS_CFG_MULTI_CORE == STD_ON )
            else
            {
                /* Get alarm of target core. */
                Os_MultiCoreServeParamType parameter;

                parameter.Os_GetAlarm.alarmId = alarmId;
                /* Execute multi-core calling function. */
                ret = Os_MultiCore_Trigger(TRUE, coreId, OS_ALARM_GETCOREID(alarmCfg),
                                           Os_MCServe_GetAlarm_ID, &parameter);
                if( E_OS_OK == ret )
                {
                    *tick = parameter.Os_GetAlarm.tick;
                }
            }
#endif
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_GetAlarm);

    return Os_Hook_CallErrorHook(OSServiceId_GetAlarm, ret);
}

/*
********************************************************************************
* Function Name: Os_Alarm_GetAlarmBase
*
* Explanation: Get the alarm base characteristics.
*
* Param: alarmId: Reference to the alarm index.
*        info: Reference to structure with constants of the alarm base.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid AlarmID.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_STATE: Application is not in correct state to perform the requested operation.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      Given alarm's owner application is not accessible.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Alarm_GetAlarmBase
(
    AlarmType alarmId,
    AlarmBaseRefType info
)
{
    Os_StatusType ret;
    CoreIdType coreId;
    Os_AlarmDynType* alarmDyn;
    const Os_AlarmCfgType* alarmCfg;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_GetAlarmBase);
    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();

    if( NULL_PTR == info )
    {
        ret = E_OS_PARAM_POINTER;
    }
    else if( alarmId >= OS_ALARMID_COUNT )
    {
        ret = E_OS_ID;
    }
    else if( OS_CORE_MASK_INTERRUPT(coreId) ) /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_GETALARMBASE_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        /* Get alarm configuration data. */
        alarmCfg = OS_ALARM_GETCFG(alarmId);
        if( OS_APPMATCH(alarmCfg->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission. */
        {
            ret = E_OS_ACCESS;
        }
        else
        {

#if( OS_CFG_MULTI_CORE == STD_ON )
            if( coreId == OS_ALARM_GETCOREID(alarmCfg) )
#endif
            {
                if( OS_APP_STATEOFF(alarmCfg->ownerAppId) ) /* If the application is not accessible. */
                {
                    ret = E_OS_ACCESS;
                }
                else
                {
                    /* Get alarm running data. */
                    alarmDyn = alarmCfg->alarmDyn;
                    ret = Os_Alarm_IntGetAlarmBase(alarmDyn, info);
                }
            }
#if( OS_CFG_MULTI_CORE == STD_ON )
            else
            {
                /* Get alarm base of target core. */
                Os_MultiCoreServeParamType parameter;

                parameter.Os_GetAlarmBase.alarmId = alarmId;
                /* Execute multi-core calling function. */
                ret = Os_MultiCore_Trigger(TRUE, coreId, OS_ALARM_GETCOREID(alarmCfg),
                                           Os_MCServe_GetAlarmBase_ID, &parameter);
                if( E_OS_OK == ret )
                {
                    *info = parameter.Os_GetAlarmBase.info;
                }
            }
#endif
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_GetAlarmBase);

    return Os_Hook_CallErrorHook(OSServiceId_GetAlarmBase, ret);
}

/*
********************************************************************************
* Function Name: Os_Alarm_SetRelAlarm
*
* Explanation: Uses to activate the relative alarm.
*
* Param: alarmId: Reference to the alarm index.
*        Increment: Relative value in ticks.
*        Cycle: The alarm cycle. In case of single alarms, cycle shall be zero.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid AlarmID.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_STATE: Application is not in correct state to perform the requested operation.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt disable/enable pair.
*         E_OS_VALUE: Value of <increment> outside of the admissible limits (lower
*                     than zero or greater than maxallowedvalue),Value of <cycle>
*                     unequal to 0 and outside of the admissible counter limits
*                     (less than mincycle or greater than maxallowedvalue).
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      Given alarm's owner application is not accessible.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Alarm_SetRelAlarm(
    AlarmType alarmId,
    Os_TickType increment,
    Os_TickType cycle
)
{
    Os_StatusType ret;
    CoreIdType coreId;
    Os_AlarmDynType* alarmDyn;
    const Os_AlarmCfgType* alarmCfg;
    Os_Arch_IntState intState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_SetRelAlarm);
    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();

    if( alarmId >= OS_ALARMID_COUNT )
    {
        ret = E_OS_ID;
    }
    else if( OS_CORE_MASK_INTERRUPT(coreId) ) /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_SETRELALARM_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        /* Get alarm configuration data. */
        alarmCfg = OS_ALARM_GETCFG(alarmId);
        if( OS_APPMATCH(alarmCfg->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission. */
        {
            ret = E_OS_ACCESS;
        }
        else
        {
#if( OS_CFG_MULTI_CORE == STD_ON )
            if( coreId == OS_ALARM_GETCOREID(alarmCfg) )
#endif
            {
                if( OS_APP_STATEOFF(alarmCfg->ownerAppId) ) /* If the application is not accessible. */
                {
                    ret = E_OS_ACCESS;
                }
                else if( OS_ALARM_SET == alarmCfg->alarmDyn->state )
                {
                    ret = E_OS_STATE;
                }
                else if( 0U == increment )
                {
                    ret = E_OS_VALUE;
                }
                else if( OS_COUNTER_CHECKINVALIDVALUE(alarmCfg->counter, increment, cycle) )
                {
                    ret = E_OS_VALUE;
                }
                else
                {
                    /* Get alarm running data. */
                    alarmDyn = alarmCfg->alarmDyn;
                    /* Disable interrupt. */
                    Os_Arch_IntDisable(&intState);
                    ret = Os_Alarm_IntSetRelAlarm(alarmDyn, increment, cycle);
                    /* Enable interrupt. */
                    Os_Arch_IntEnable(intState);
                }
            }
#if( OS_CFG_MULTI_CORE == STD_ON )
            else
            {
                /* Set relative alarm of target core. */
                Os_MultiCoreServeParamType parameter;

                parameter.Os_SetRelAlarm.alarmId = alarmId;
                parameter.Os_SetRelAlarm.increment = increment;
                parameter.Os_SetRelAlarm.cycle =cycle;
                /* Execute multi-core calling function. */
                ret = Os_MultiCore_Trigger(TRUE, coreId, OS_ALARM_GETCOREID(alarmCfg),
                                           Os_MCServe_SetRelAlarm_ID, &parameter);
            }
#endif
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_SetRelAlarm);

    return Os_Hook_CallErrorHook(OSServiceId_SetRelAlarm, ret);
}

/*
********************************************************************************
* Function Name: Os_Alarm_SetAbsAlarm
*
* Explanation: Uses to activate the absolute alarm.
*
* Param: alarmId: Reference to the alarm index.
*        start: Absolute alarm value.
*        cycle: The alarm cycle. In case of single alarms, cycle shall be zero.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid AlarmID.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_STATE: Application is not in correct state to perform the requested operation.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt disable/enable pair.
*         E_OS_VALUE: Value of <start> outside of the admissible counter limit
*                     (less than zero or greater than maxallowedvalue),
*                     Value of <cycle> unequal to 0 and outside of the admissible
*                     counter limits (less than mincycle or greater than maxallowedvalue).
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      Given alarm's owner application is not accessible.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Alarm_SetAbsAlarm
(
    AlarmType alarmId,
    Os_TickType start,
    Os_TickType cycle
)
{
    Os_StatusType ret;
    CoreIdType coreId;
    Os_AlarmDynType* alarmDyn;
    const Os_AlarmCfgType* alarmCfg;
    Os_Arch_IntState intState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_SetAbsAlarm);
    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();

    if( alarmId >= OS_ALARMID_COUNT )
    {
        ret = E_OS_ID;
    }
    else if( OS_CORE_MASK_INTERRUPT(coreId) ) /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_SETABSALARM_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        /* Get alarm configuration data. */
        alarmCfg = OS_ALARM_GETCFG(alarmId);
        if( OS_APPMATCH(alarmCfg->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission. */
        {
            ret = E_OS_ACCESS;
        }
        else
        {
#if( OS_CFG_MULTI_CORE == STD_ON )
            if( coreId == OS_ALARM_GETCOREID(alarmCfg) )
#endif
            {
                if( OS_APP_STATEOFF(alarmCfg->ownerAppId) ) /* If the application is not accessible. */
                {
                    ret = E_OS_ACCESS;
                }
                else if( OS_ALARM_SET == alarmCfg->alarmDyn->state )
                {
                    ret = E_OS_STATE;
                }
                else if( OS_COUNTER_CHECKINVALIDVALUE(alarmCfg->counter, start, cycle) )
                {
                    ret = E_OS_VALUE;
                }
                else
                {
                    /* Get alarm running data. */
                    alarmDyn = alarmCfg->alarmDyn;
                    /* Disable interrupt. */
                    Os_Arch_IntDisable(&intState);
                    ret = Os_Alarm_IntSetAbsAlarm(alarmDyn, start, cycle);
                    /* Enable interrupt. */
                    Os_Arch_IntEnable(intState);
                }
            }
#if( OS_CFG_MULTI_CORE == STD_ON )
            else
            {
                /* Set absolute alarm of target core. */
                Os_MultiCoreServeParamType parameter;

                parameter.Os_SetAbsAlarm.alarmId = alarmId;
                parameter.Os_SetAbsAlarm.start = start;
                parameter.Os_SetAbsAlarm.cycle =cycle;
                /* Execute multi-core calling function. */
                ret = Os_MultiCore_Trigger(TRUE, coreId, OS_ALARM_GETCOREID(alarmCfg),
                                           Os_MCServe_SetAbsAlarm_ID, &parameter);
            }
#endif
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_SetAbsAlarm);

    return Os_Hook_CallErrorHook(OSServiceId_SetAbsAlarm, ret);
}

/*
********************************************************************************
* Function Name: Os_Alarm_CancelAlarm
*
* Explanation: Uses to cancel the alarm.
*
* Param: alarmId: Reference to the alarm index.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid AlarmID.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_NOFUNC: Alarm is off.
*         E_OS_STATE: Application is not in correct state to perform the requested operation.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      Given alarm's owner application is not accessible.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Alarm_CancelAlarm(AlarmType alarmId)
{
    Os_StatusType ret = E_OS_OK;

    CoreIdType coreId;
    Os_AlarmDynType* alarmDyn;
    const Os_AlarmCfgType* alarmCfg;
    Os_Arch_IntState intState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_CancelAlarm);
    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();

    if( alarmId >= OS_ALARMID_COUNT )
    {
        ret = E_OS_ID;
    }
    else if( OS_CORE_MASK_INTERRUPT(coreId) ) /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_CANCELALARM_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        /* Get alarm configuration data. */
        alarmCfg = OS_ALARM_GETCFG(alarmId);
        if( OS_APPMATCH(alarmCfg->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission. */
        {
            ret = E_OS_ACCESS;
        }
        else
        {
#if( OS_CFG_MULTI_CORE == STD_ON )
            if( coreId == OS_ALARM_GETCOREID(alarmCfg) )
#endif
            {
                if( OS_APP_STATEOFF(alarmCfg->ownerAppId) ) /* If the application is not accessible. */
                {
                    ret = E_OS_ACCESS;
                }
                else if( OS_ALARM_SET != alarmCfg->alarmDyn->state )
                {
                    ret = E_OS_NOFUNC;
                }
                else
                {
                    /* Get alarm running data. */
                    alarmDyn = alarmCfg->alarmDyn;
                    /* Disable interrupt. */
                    Os_Arch_IntDisable(&intState);
                    Os_Alarm_IntCancel(alarmDyn);
                    /* Enable interrupt. */
                    Os_Arch_IntEnable(intState);
                }
            }
#if( OS_CFG_MULTI_CORE == STD_ON )
            else
            {
                /* Cancel alarm of target core. */
                Os_MultiCoreServeParamType parameter;
                parameter.Os_CancelAlarm.alarmId = alarmId;
                /* Execute multi-core calling function. */
                ret = Os_MultiCore_Trigger(TRUE, coreId, OS_ALARM_GETCOREID(alarmCfg),
                                     Os_MCServe_CancelAlarm_ID, &parameter);
            }
#endif
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_CancelAlarm);

    return Os_Hook_CallErrorHook(OSServiceId_CancelAlarm, ret);
}

#if( OS_CFG_MULTI_CORE == STD_ON )
/*
********************************************************************************
* Function Name: Os_Alarm_TargetGetAlarm
*
* Explanation: Multicore function to get the relative value in ticks before the
*              alarm expires.
*
* Param: alarmId: Reference to the alarm index.
*        tick: Relative value in ticks before the alarm expires.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid AlarmID.
*         E_OS_CORE: Core is not available.
*         E_OS_STATE: Application is not in correct state to perform the requested
*                     operation.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Alarm_TargetGetAlarm
(
    AlarmType alarmId,
    TickRefType tick
)
{
    Os_StatusType ret;
    CoreIdType coreId;
    Os_AlarmDynType* alarmDyn;
    const Os_AlarmCfgType* alarmCfg;

    if( alarmId >= OS_ALARMID_COUNT )
    {
        ret = E_OS_ID;
    }
    else
    {
        /* Get alarm configuration data. */
        alarmCfg = OS_ALARM_GETCFG(alarmId);
        /* Get logic core id. */
        coreId = Os_Core_GetLogicId();
        if( coreId == OS_ALARM_GETCOREID(alarmCfg) )
        {
            /* If the application is not accessible. */
            if( OS_APP_STATEOFF(alarmCfg->ownerAppId) )
            {
                ret = E_OS_ACCESS;
            }
            else
            {
                /* Get alarm running data. */
                alarmDyn = alarmCfg->alarmDyn;
                ret = Os_Alarm_IntGetAlarm(alarmDyn, tick);
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
* Function Name: Os_Alarm_TargetGetAlarmBase
*
* Explanation: Multicore function to get the alarm base characteristics.
*
* Param: alarmId: Reference to the alarm index.
*        info: Reference to structure with constants of the alarm base.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid AlarmID.
*         E_OS_CORE: Core is not available.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      Given alarm's owner application is not accessible.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Alarm_TargetGetAlarmBase
(
    AlarmType alarmId,
    AlarmBaseRefType info
)
{
    Os_StatusType ret;
    CoreIdType coreId;
    Os_AlarmDynType* alarmDyn;
    const Os_AlarmCfgType* alarmCfg;

    if( alarmId >= OS_ALARMID_COUNT )
    {
        ret = E_OS_ID;
    }
    else
    {
        /* Get alarm configuration data. */
        alarmCfg = OS_ALARM_GETCFG(alarmId);
        /* Get logic core id. */
        coreId = Os_Core_GetLogicId();
        if( coreId == OS_ALARM_GETCOREID(alarmCfg) )
        {
            if( OS_APP_STATEOFF(alarmCfg->ownerAppId) ) /* If the application is not accessible. */
            {
                ret = E_OS_ACCESS;
            }
            else
            {
                /* Get alarm running data. */
                alarmDyn = alarmCfg->alarmDyn;
                ret = Os_Alarm_IntGetAlarmBase(alarmDyn, info);
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
* Function Name: Os_Alarm_TargetSetRelAlarm
*
* Explanation: Multicore function to activate the relative alarm.
*
* Param: alarmId: Reference to the alarm index.
*        increment: Relative value in ticks.
*        cycle: Cycle value in case of cyclic alarm. In case of single alarms,
*               cycle shall be zero.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid AlarmID.
*         E_OS_CORE: Core is not available.
*         E_OS_STATE: Application is not in correct state to perform the requested
*                     operation.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      Given alarm's owner application is not accessible.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Alarm_TargetSetRelAlarm(
    AlarmType alarmId,
    Os_TickType increment,
    Os_TickType cycle
)
{
    Os_StatusType ret;

    CoreIdType coreId;
    Os_AlarmDynType* alarmDyn;
    const Os_AlarmCfgType* alarmCfg;

    if( alarmId >= OS_ALARMID_COUNT )
    {
        ret = E_OS_ID;
    }
    else
    {
        /* Get alarm configuration data. */
        alarmCfg = OS_ALARM_GETCFG(alarmId);
        /* Get logic core id. */
        coreId = Os_Core_GetLogicId();
        if( coreId == OS_ALARM_GETCOREID(alarmCfg) )
        {
            if( OS_APP_STATEOFF(alarmCfg->ownerAppId) ) /* If the application is not accessible. */
            {
                ret = E_OS_ACCESS;
            }
            else if( OS_ALARM_SET == alarmCfg->alarmDyn->state )
            {
                ret = E_OS_STATE;
            }
            else if( 0U == increment )
            {
                ret = E_OS_VALUE;
            }
            else if( OS_COUNTER_CHECKINVALIDVALUE(alarmCfg->counter, increment, cycle) )
            {
                ret = E_OS_VALUE;
            }
            else
            {
                /* Get alarm running data. */
                alarmDyn = alarmCfg->alarmDyn;
                ret = Os_Alarm_IntSetRelAlarm(alarmDyn, increment, cycle);
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
* Function Name: Os_Alarm_TargetSetAbsAlarm
*
* Explanation: Multicore function to activate the absolute alarm.
*
* Param: alarmId: Reference to the alarm index.
*        start: Absolute value in ticks.
*        cycle: Cycle value in case of cyclic alarm. In case of single alarms,
*               cycle shall be zero.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid AlarmID.
*         E_OS_CORE: Core is not available.
*         E_OS_STATE: Application is not in correct state to perform the requested
*                     operation.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      Given alarm's owner application is not accessible.
*         E_OS_VALUE: Value of <increment> outside of the admissible limits
*                    (lower than zero or greater than maxallowedvalue),
*                     Value of <cycle> unequal to 0 and outside of the admissible
*                     counter limits (less than mincycle or greater than maxallowedvalue).
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Alarm_TargetSetAbsAlarm
(
    AlarmType alarmId,
    Os_TickType start,
    Os_TickType cycle
)
{
    Os_StatusType ret;
    CoreIdType coreId;
    Os_AlarmDynType* alarmDyn;
    const Os_AlarmCfgType* alarmCfg;

    if( alarmId >= OS_ALARMID_COUNT )
    {
        ret = E_OS_ID;
    }
    else
    {
        /* Get alarm configuration data. */
        alarmCfg = OS_ALARM_GETCFG(alarmId);
        /* Get logic core id */
        coreId = Os_Core_GetLogicId();
        if( coreId == OS_ALARM_GETCOREID(alarmCfg) )
        {
            if( OS_APP_STATEOFF(alarmCfg->ownerAppId) ) /* If the application is not accessible. */
            {
                ret = E_OS_ACCESS;
            }
            else if( OS_ALARM_SET == alarmCfg->alarmDyn->state )
            {
                ret = E_OS_STATE;
            }
            else if( OS_COUNTER_CHECKINVALIDVALUE(alarmCfg->counter, start, cycle) )
            {
                ret = E_OS_VALUE;
            }
            else
            {
                /* Get alarm running data. */
                alarmDyn = alarmCfg->alarmDyn;
                ret = Os_Alarm_IntSetAbsAlarm(alarmDyn, start, cycle);
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
* Function Name: Os_Alarm_TargetCancelAlarm
*
* Explanation:  Multicore function to cancel the alarm.
*
* Param: alarmId: Reference to the alarm index.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid AlarmID.
*         E_OS_CORE: Core is not available.
*         E_OS_NOFUNC: Alarm is off.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Alarm_TargetCancelAlarm(AlarmType alarmId)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    Os_AlarmDynType* alarmDyn;
    const Os_AlarmCfgType* alarmCfg;

    if( alarmId >= OS_ALARMID_COUNT )
    {
        ret = E_OS_ID;
    }
    else
    {
        /* Get alarm configuration data. */
        alarmCfg = OS_ALARM_GETCFG(alarmId);
        /* Get logic core id */
        coreId = Os_Core_GetLogicId();
        if( coreId == OS_ALARM_GETCOREID(alarmCfg) )
        {
            if( OS_APP_STATEOFF(alarmCfg->ownerAppId) ) /* If the application is not accessible. */
            {
                ret = E_OS_ACCESS;
            }
            else if( OS_ALARM_SET != alarmCfg->alarmDyn->state )
            {
                ret = E_OS_NOFUNC;
            }
            else
            {
                /* Get alarm running data. */
                alarmDyn = alarmCfg->alarmDyn;
                Os_Alarm_IntCancel(alarmDyn);
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
* Function Name: Os_Alarm_TargetActActivateTask
*
* Explanation:  Multicore function to trigger activate task action.
*
* Param: taskId:  Reference to the task index.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid taskId.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Alarm_TargetActActivateTask
(
    TaskType taskId
)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    const Os_TaskCfgType* taskCfg;

    if( OS_TASK_ISINVAILD(taskId) )
    {
        ret = E_OS_ID;
    }
    else
    {
        /* Get logic core id. */
        coreId = Os_Core_GetLogicId();
        /* Get task configuration data. */
        taskCfg = OS_TASK_GETCFG(taskId);
         /* If the activate task is the same core. */
        if( coreId == OS_TASK_GETCOREID(taskCfg) )
        {
            /* Activate the configured task. */
            (void)Os_Task_ActivateTaskSimp(taskCfg);
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
* Function Name: Os_Alarm_TargetActSetEvent
*
* Explanation:  Multicore function to trigger set event action.
*
* Param: taskId:  Reference to the task index.
*        mask: Event mask.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid AlarmID.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
#if(  OS_CFG_EVENT_ENABLE == STD_ON  )
FUNC(Os_StatusType, OS_CODE) Os_Alarm_TargetActSetEvent
(
    TaskType taskId, EventMaskType mask
)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    const Os_TaskCfgType* taskCfg;

    if( OS_TASK_ISINVAILD(taskId) )
    {
        ret = E_OS_ID;
    }
    else
    {
        /* Get logic core id. */
        coreId = Os_Core_GetLogicId();
        /* Get task configuration data. */
        taskCfg = OS_TASK_GETCFG(taskId);
         /* If the activate task is the same core. */
        if( coreId == OS_TASK_GETCOREID(taskCfg) )
        {
            (void)Os_Event_SetEventSimp(taskCfg, mask);
            (void)Os_Task_SetEventTaskSimp(taskCfg);
        }
        else
        {
            ret = E_OS_CORE;
        }
    }

    return ret;
}
#endif /* OS_CFG_EVENT_ENABLE == STD_ON */
#endif /* OS_CFG_MULTI_CORE == STD_ON */

/*
********************************************************************************
* Function Name: GetAlarm
*
* Explanation: Standard API function, returns the relative value in ticks before
*              the alarm expires.
*
* Param: AlarmID: Reference to the alarm element.
*        Tick: Relative value in ticks before the alarm expires.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid AlarmID.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
*         E_OS_CORE: Core is not available.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      Given alarm's owner application is not accessible.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) GetAlarm(AlarmType AlarmID, TickRefType Tick)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_GetAlarm.alarmId = AlarmID;
    sysCallParam.Os_GetAlarm.tick = Tick;
    Os_SysCall(Os_Syscall_GetAlarm_ID, &sysCallParam);
    ret = sysCallParam.Os_GetAlarm.retVal;
#else
    ret = Os_Alarm_GetAlarm(AlarmID, Tick);
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: GetAlarmBase
*
* Explanation: Standard API function, Reads the alarm base characteristics.
*
* Param: AlarmID: Reference to the alarm element.
*        Info: Reference to structure with constants of the alarm base.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid AlarmID.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      Given alarm's owner application is not accessible.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_GetAlarmBase.alarmId = AlarmID;
    sysCallParam.Os_GetAlarmBase.info = Info;
    Os_SysCall(Os_Syscall_GetAlarmBase_ID, &sysCallParam);
    ret = sysCallParam.Os_GetAlarmBase.retVal;
#else
    ret = Os_Alarm_GetAlarmBase(AlarmID, Info);
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: SetRelAlarm
*
* Explanation: Standard API function, Uses to activate the relative alarm.
*
* Param: AlarmID: Reference to the alarm element.
*        Increment: Relative value in ticks.
*        Cycle: The alarm cycle. In case of single alarms, cycle shall be zero.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid AlarmID.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_STATE: Application is not in correct state to perform the requested
*                     operation.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_VALUE: Value of <increment> outside of the admissible limits
*                    (lower than zero or greater than maxallowedvalue),
*                     Value of <cycle> unequal to 0 and outside of the admissible
*                     counter limits (less than mincycle or greater than maxallowedvalue).
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      Given alarm's owner application is not accessible.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) SetRelAlarm
(
    AlarmType AlarmID,
    TickType Increment,
    TickType Cycle
)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_SetRelAlarm.alarmId = AlarmID;
    sysCallParam.Os_SetRelAlarm.increment = Increment;
    sysCallParam.Os_SetRelAlarm.cycle = Cycle;
    Os_SysCall(Os_Syscall_SetRelAlarm_ID, &sysCallParam);
    ret = sysCallParam.Os_SetRelAlarm.retVal;
#else
    ret = Os_Alarm_SetRelAlarm(AlarmID, Increment, Cycle);
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: SetAbsAlarm
*
* Explanation:  Standard API function, Uses to activate the absolute alarm.
*
* Param: AlarmID: Reference to the alarm element.
*        Start: Absolute alarm value.
*        Cycle: The alarm cycle. In case of single alarms, cycle shall be zero.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid AlarmID.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_STATE: Application is not in correct state to perform the requested
*                     operation.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_VALUE: Value of <start> outside of the admissible counter limit
*                     (less than zero or greater than maxallowedvalue),
*                     Value of <cycle> unequal to 0 and outside of the admissible
*                     counter limits (less than mincycle or greater than maxallowedvalue).
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      Given alarm's owner application is not accessible.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) SetAbsAlarm
(
    AlarmType AlarmID,
    TickType Start,
    TickType Cycle
)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_SetAbsAlarm.alarmId = AlarmID;
    sysCallParam.Os_SetAbsAlarm.start = Start;
    sysCallParam.Os_SetAbsAlarm.cycle = Cycle;
    Os_SysCall(Os_Syscall_SetAbsAlarm_ID, &sysCallParam);
    ret = sysCallParam.Os_SetAbsAlarm.retVal;
#else
    ret = Os_Alarm_SetAbsAlarm(AlarmID, Start, Cycle);
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: CancelAlarm
*
* Explanation: Standard API function, Uses to cancel the alarm.
*
* Param: AlarmID: Reference to the alarm element.
*
* Retval: E_OS_OK: No error.
*         E_OS_NOFUNC: Alarm is off.
*         E_OS_ID: Invalid AlarmID.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      Given alarm's owner application is not accessible.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) CancelAlarm(AlarmType AlarmID)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_CancelAlarm.alarmId = AlarmID;
    Os_SysCall(Os_Syscall_CancelAlarm_ID, &sysCallParam);
    ret = sysCallParam.Os_CancelAlarm.retVal;
#else
    ret = Os_Alarm_CancelAlarm(AlarmID);
#endif

    return ret;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

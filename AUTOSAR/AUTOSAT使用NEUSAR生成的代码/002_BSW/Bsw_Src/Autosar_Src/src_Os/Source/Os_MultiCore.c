/*
********************************************************************************
*
*  File name: Os_MultiCore.c
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
* Version: 3.1
* Author/Date: LiG/2022.11.21
* Change: Change OS_VAR_NOINIT to OS_VAR_NO_INIT.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: WangJP/2022.12.10
* Change: Modification of coding standard.
* Cause: Optimize
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2022.12.21
* Change: New functions ShutDownAllCore.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: HanCL/2023.1.12
* Change: New functions Os_MCServe_GetCounterValue.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2023.5.26
* Change: Modifying GetCounterValue to cross core without obtaining a value.
* Cause: Bugfix
********************************************************************************
* Version: 3.7
* Author/Date: LiG/2023.05.26
* Change: Resolve compilation warnings.
* Cause: Optimize
********************************************************************************
* Version: 3.8
* Author/Date: LiG/2024.1.5
* Change: Added IocCallback functional related code.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: ZhangY/2023.10.07
* Change: Modify incorrect return value in API description of Os_MCServe_SetEvent.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: JiangGL/2023.12.06
* Change: 1. Modify incorrect return value in API description in many functions.
*         2. Modify the following functions to fix bug of getting wrong value in
*            cross core situation.
*            Os_MCServe_GetTaskState
*            Os_MCServe_GetAlarm
*            Os_MCServe_GetAlarmBase
*            Os_MCServe_GetApplicationState
*            Os_MCServe_GetScheduleTableStatus
*            Os_MCServe_GetTaskStackUsage
*            Os_MCServe_GetIsrStackUsage
*            Os_MCServe_GetCounterValue
* Cause: Bugfix
********************************************************************************
* Version: 3.11
* Author/Date: LiG/2023.3.15
* Change: Add multi-core service overload error reporting function.
* Cause: Bugfix
********************************************************************************
* Version: 3.12
* Author/Date: LiG/2024.4.10
* Change: Modifying static code check issues.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: MiaoLH/2024.8.27
* Change: Add the nocache property variable Os MultiCoreStartRequest.
* Cause: Optimize
********************************************************************************
* Version: 3.14
* Author/Date: LiG/2025.01.02
* Change: Add multi-core synchronization interface.
* Cause: Update
********************************************************************************
* Version: 3.15
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
#include "Os_MultiCore.h"
#include "Os_Arch_Lcfg.h"
#include "Os_Core.h"
#include "Os_App.h"
#include "Os_Alarm.h"
#include "Os_Task.h"
#include "Os_Event.h"
#include "Os_SchdTb.h"
#include "Os_Stack.h"
#include "Os_Counter.h"

#if( OS_CFG_MULTI_CORE == STD_ON )
/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
#define OS_MULTICORE_SHIFTBIT        (1U)
#define OS_MULTICORE_BUFFCNT         ((uint8)OS_COREID_COUNT * ((uint8)OS_COREID_COUNT - (uint8)Os_MULTICORE_VALU_ONE))
#define OS_MULTICORE_GETBUFF(coreId) ((coreId) * ((uint8)OS_COREID_COUNT - (uint8)Os_MULTICORE_VALU_ONE))
#define OS_MULTICOREMATCH(offset)    (uint8)(OS_MULTICORE_SHIFTBIT << (offset))

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
#define OS_START_SEC_GLOBAL_NOCACHE_VAR
#include "Os_MemMap.h"

/* The buffer is used to store multi-core service parameters. */
static VAR(Os_MultiCoreServeType, OS_VAR_NO_INIT) Os_MultiCoreServe[OS_COREID_COUNT];

/* The buffer for passing parameters between multiple cores. */
static VAR(Os_MultiCoreCommType, OS_VAR_NO_INIT) Os_MCServe_ShareMemory[OS_MULTICORE_BUFFCNT];

volatile VAR(uint8, OS_VAR_NO_INIT) Os_MultiCoreSync[OS_COREID_COUNT];

/* Record the core id startup status. */
VAR(uint8, OS_VAR_NO_INIT) Os_MultiCoreStartRequest[OS_COREID_COUNT];

#define OS_STOP_SEC_GLOBAL_NOCACHE_VAR
#include "Os_MemMap.h"

/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
LOCAL_INLINE FUNC(uint8, OS_CODE) Os_MultiCore_GetSendBuff
(
    CoreIdType srcCore,
    CoreIdType desCore
);
LOCAL_INLINE FUNC(void, OS_CODE) Os_MultiCore_ParamMemCyp
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) src,
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) des
);
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_ActivateTask
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_AlarmActivateTask
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(Os_StatusType, OS_CODE)  Os_MCServe_ChainTask
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_GetTaskState
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_GetAlarm
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_GetAlarmBase
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_SetRelAlarm
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_SetAbsAlarm
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_CancelAlarm
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_TerminateApp
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_GetApplicationState
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_ShutdownAllCores
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
#if( OS_CFG_EVENT_ENABLE == STD_ON )
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_SetEvent
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_AlarmSetEvent
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
#endif /* OS_CFG_EVENT_ENABLE == STD_ON */
#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_StartScheduleTableRel
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_StartScheduleTableAbs
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_StopScheduleTable
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_NextScheduleTable
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_GetScheduleTableStatus
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
#endif /* OS_CFG_SCHDTB_ENABLE == STD_ON */
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_GetTaskStackUsage
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_GetIsrStackUsage
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_GetCounterValue
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_CONST) parameter
);
#if( OS_CFG_IOC_ENABLE == STD_ON )
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_IocCallBack
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
#endif /* OS_CFG_IOC_ENABLE == STD_ON */
static FUNC(Os_StatusType, OS_CODE) Os_MultiCoreServer_Write
(
    boolean isSync,
    Os_MCServe_FuncId funcId,
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) param,
    P2VAR(Os_MultiCoreServeType, AUTOMATIC, OS_APPL_DATA) multiCoreServe
);
static FUNC(Os_StatusType, OS_CODE) Os_MultiCoreServer_Read
(
    P2VAR(Os_MultiCoreServeType, AUTOMATIC, OS_APPL_DATA) multiCoreServe,
    P2VAR(Os_MultiCoreCommType, AUTOMATIC, OS_APPL_DATA) multiCoreComm,
    CoreIdType desCore,
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) param
);

/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
#define OS_START_SEC_CONST
#include "Os_MemMap.h"

static CONST(Os_MCServe_Func, OS_CONST) MultiCoreFuncList[Os_MCServe_Func_Counter] =
{
    Os_MCServe_ActivateTask,
    Os_MCServe_AlarmActivateTask,
    Os_MCServe_ChainTask,
    Os_MCServe_GetTaskState,
    Os_MCServe_GetAlarm,
    Os_MCServe_GetAlarmBase,
    Os_MCServe_SetRelAlarm,
    Os_MCServe_SetAbsAlarm,
    Os_MCServe_CancelAlarm,
    Os_MCServe_TerminateApp,
    Os_MCServe_GetApplicationState,
    Os_MCServe_ShutdownAllCores,
#if(  OS_CFG_EVENT_ENABLE == STD_ON  )
    Os_MCServe_SetEvent,
    Os_MCServe_AlarmSetEvent,
#endif /* OS_CFG_EVENT_ENABLE == STD_ON */
#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    Os_MCServe_StartScheduleTableRel,
    Os_MCServe_StartScheduleTableAbs,
    Os_MCServe_StopScheduleTable,
    Os_MCServe_NextScheduleTable,
    Os_MCServe_GetScheduleTableStatus,
#endif /* OS_CFG_SCHDTB_ENABLE == STD_ON */
    Os_MCServe_GetTaskStackUsage,
    Os_MCServe_GetIsrStackUsage,
    Os_MCServe_GetCounterValue,
#if( OS_CFG_IOC_ENABLE == STD_ON )
    Os_MCServe_IocCallBack
#endif /* OS_CFG_IOC_ENABLE == STD_ON */
};

#define OS_STOP_SEC_CONST
#include "Os_MemMap.h"

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
* Function Name: Os_MultiCore_GetSendBuff
*
* Explanation: Get the send buff of the source core.
*
* Param: srcCore: Source core logical index.
*        desCore: Destination core logical index.
*
* Retval: Buff offset.
********************************************************************************
*/
LOCAL_INLINE FUNC(uint8, OS_CODE) Os_MultiCore_GetSendBuff
(
    CoreIdType srcCore,
    CoreIdType desCore
)
{
    uint8 buffOffset;

    buffOffset = (uint8)srcCore;
    /* If source core id is > destination core id. */
    if( srcCore > desCore )
    {
        buffOffset = ((uint8)srcCore - (uint8)Os_MULTICORE_VALU_ONE);
    }

    return buffOffset;
}

/*
********************************************************************************
* Function Name: Os_MultiCore_ParamMemCyp
*
* Explanation: Multi-core service parameter copy.
*
* Param: srcCore: Source core logical index.
*        desCore: Destination core logical index.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_MultiCore_ParamMemCyp
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) src,
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) des
)
{
    if( (src != NULL_PTR) && (des != NULL_PTR) )
    {
        uint8 index;
        uint8* tempSrc = (uint8*)src;
        uint8* tempDes = (uint8*)des;

        for( index = Os_MULTICORE_INIT; index< sizeof(Os_MultiCoreServeParamType); index++ )
        {
            tempDes[index] = tempSrc[index];
        }
    }
}

/*
********************************************************************************
* Function Name: Os_MCServe_ActivateTask
*
* Explanation: Multi-core service to activate a task.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid taskId.
*         E_OS_CORE: Core is not available.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
*         E_OS_LIMIT: Maximum task activations reached.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_ActivateTask
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_TargetActivateTask(parameter->Os_ActivateTask.taskId);

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_AlarmActivateTask
*
* Explanation: Multi-core service to activate a task in alarm.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid taskId.
*         E_OS_CORE: Core is not available.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
*         E_OS_LIMIT: Maximum task activations reached.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_AlarmActivateTask
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_Alarm_TargetActActivateTask(parameter->Os_ActivateTask.taskId);

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_ChainTask
*
* Explanation: Multi-core service to chain task.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE)  Os_MCServe_ChainTask
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret = E_OS_OK;

    OS_IGNORE_PARAM(parameter);

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_GetTaskState
*
* Explanation: Multi-core service to get task state.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid taskId.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_GetTaskState
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_TargetGetTaskState(parameter->Os_GetTaskState.taskId,
        &(parameter->Os_GetTaskState.state));

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_GetAlarm
*
* Explanation: Multi-core service to get the relative value in ticks before the alarm expires.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid taskId.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_GetAlarm
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_Alarm_TargetGetAlarm(parameter->Os_GetAlarm.alarmId,
                                  &(parameter->Os_GetAlarm.tick));

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_GetAlarmBase
*
* Explanation: Multi-core service to get the alarm base characteristics.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid AlarmID.
*         E_OS_CORE: Core is not available.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      Given alarm's owner application is not accessible.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_GetAlarmBase
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_Alarm_TargetGetAlarmBase(parameter->Os_GetAlarmBase.alarmId,
                                      &(parameter->Os_GetAlarmBase.info));

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_SetRelAlarm
*
* Explanation: Multi-core service to activate the relative alarm.
*
* Param: parameter: Multi-core service function call parameters.
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
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_SetRelAlarm
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_Alarm_TargetSetRelAlarm(parameter->Os_SetRelAlarm.alarmId,
                                     parameter->Os_SetRelAlarm.increment,
                                     parameter->Os_SetRelAlarm.cycle);

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_SetAbsAlarm
*
* Explanation: Multi-core service to activate the absolute alarm.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_CORE: Core is not available.
*         E_OS_STATE: Application is not accessible.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_SetAbsAlarm
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_Alarm_TargetSetAbsAlarm(parameter->Os_SetAbsAlarm.alarmId,
                                     parameter->Os_SetAbsAlarm.start,
                                     parameter->Os_SetAbsAlarm.cycle);

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_CancelAlarm
*
* Explanation: Multi-core service to cancel alarm.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_CORE: Core is not available.
*         E_OS_STATE: Application is not accessible.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_CancelAlarm
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_Alarm_TargetCancelAlarm(parameter->Os_CancelAlarm.alarmId);

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_TerminateApp
*
* Explanation: Multi-core service to terminate application.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid App Id.
*         E_OS_CORE: Core is not available.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_TerminateApp
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_App_TragetTerminationApp(parameter->Os_TerminateApplication.appId,
                                      parameter->Os_TerminateApplication.restartOption);

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_GetApplicationState
*
* Explanation: Multi-core service to get application state.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid App Id.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_GetApplicationState
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_App_TragetGetAppState(parameter->Os_GetApplicationState.appId,
                                   &(parameter->Os_GetApplicationState.value));

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_ShutdownAllCores
*
* Explanation: Multi-core service to shutdown all cores.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_ShutdownAllCores
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret = E_OS_OK;

    Os_TargetShutDownAllCore(parameter->Os_ShutdownAllCores.error);

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_SetEvent
*
* Explanation: Multi-core service to set event.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid taskId.
*         E_OS_CORE: Core is not available.
*         E_OS_STATE: Invalid state does not allow set event.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
********************************************************************************
*/
#if( OS_CFG_EVENT_ENABLE == STD_ON )
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_SetEvent
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_TargetSetEvent(parameter->Os_SetEvent.taskId, parameter->Os_SetEvent.mask);

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_AlarmSetEvent
*
* Explanation: Multi-core service to set event in alarm.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_AlarmSetEvent
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_Alarm_TargetActSetEvent(parameter->Os_SetEvent.taskId,
                                     parameter->Os_SetEvent.mask);

    return ret;
}
#endif /* OS_CFG_EVENT_ENABLE == STD_ON */

/*
********************************************************************************
* Function Name: Os_MCServe_StartScheduleTableRel
*
* Explanation: Multi-core service to start the relative schedule table.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_VALUE: Offset is greater than (OsCounterMaxAllowedValue - InitialOffset)
*                    or is equal to 0.
*         E_OS_STATE: Schedule table was already started.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_StartScheduleTableRel
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_SchdTb_TargetStartScheduleTableRel(parameter->Os_StartSchdTbRel.scheduleTableID,
                                                parameter->Os_StartSchdTbRel.offset);

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_StartScheduleTableAbs
*
* Explanation: Multi-core service to start the relative schedule table.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_VALUE: Offset is greater than (OsCounterMaxAllowedValue - InitialOffset)
*                    or is equal to 0.
*         E_OS_STATE: Schedule table was already started.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_StartScheduleTableAbs
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_SchdTb_TargetStartScheduleTableAbs(parameter->Os_StartSchdTbAbs.scheduleTableID,
                                                parameter->Os_StartSchdTbAbs.start);

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_StopScheduleTable
*
* Explanation: Multi-core service to stop the schedule table.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_VALUE: Offset is greater than (OsCounterMaxAllowedValue - InitialOffset)
*                    or is equal to 0.
*         E_OS_STATE: Schedule table was already started.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_StopScheduleTable
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_SchdTb_TargetStopScheduleTable(parameter->Os_StopSchdTb.scheduleTableID);

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_NextScheduleTable
*
* Explanation: Multi-core service to switch the processing from one schedule table
*              to another schedule table.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_NOFUNC: Schedule table was already stopped.
*         E_OS_STATE: ScheduleTableID_To is started or next.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_NextScheduleTable
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_SchdTb_TargetNextScheduleTable(parameter->Os_NextSchdTb.scheduleTableID_From,
                                            parameter->Os_NextSchdTb.scheduleTableID_To);

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_GetScheduleTableStatus
*
* Explanation: Multi-core service to get the state of a schedule table.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: ScheduleTableID not valid.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_GetScheduleTableStatus
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_SchdTb_TargetGetScheduleTableStatus(parameter->Os_GetSchdTbStatus.scheduleTableID,
                                                 &(parameter->Os_GetSchdTbStatus.scheduleStatus));

    return ret;
}
#endif /* OS_CFG_SCHDTB_ENABLE == STD_ON */

/*
********************************************************************************
* Function Name: Os_MCServe_GetTaskStackUsage
*
* Explanation: Multi-core service to get Task stack usage.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid taskId.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_GetTaskStackUsage
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_Stack_TargetGetTaskStackUsage(parameter->Os_GetTaskStackUsage.taskId,
                                           &(parameter->Os_GetTaskStackUsage.taskUsage));

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_GetIsrStackUsage
*
* Explanation: Multi-core service to get Isr stack usage.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid IsrId.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_GetIsrStackUsage
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_Stack_TargetGetIsrStackUsage(parameter->Os_GetIsrStackUsage.isrId,
                                          &(parameter->Os_GetIsrStackUsage.isrUsage));

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_GetCounterValue
*
* Explanation: Multi-core service to read the current count value of a counter.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_GetCounterValue
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_Counter_TargetGetCounterValue(parameter->Os_GetCounterValue.counterId,
                                           &(parameter->Os_GetCounterValue.value));

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MCServe_IocCallBack
*
* Explanation: Multi-core service to call the ioc callback.
*
* Param: parameter: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
********************************************************************************
*/
#if( OS_CFG_IOC_ENABLE == STD_ON )
static FUNC(Os_StatusType, OS_CODE) Os_MCServe_IocCallBack
(
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret = E_OS_OK;
    const Os_IocTxCfgType *iocTxCfg = (parameter->Os_IocCallBack.iocCfg.iocTxCfg);

    iocTxCfg[parameter->Os_IocCallBack.senderId].IocRxCB.callBack();

    return ret;
}
#endif /* OS_CFG_IOC_ENABLE == STD_ON */

/*
********************************************************************************
* Function Name: Os_MultiCoreServer_Write
*
* Explanation: Multi-core service to get Isr stack usage.
*
* Param: isSync: Whether the synchronization flag.
*        funcId: Multicore service function Id.
*        param: Multi-core service function call parameters.
*        multiCoreServe: Multicore service parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_BUFFFULL: The buffer is full.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MultiCoreServer_Write
(
    boolean isSync,
    Os_MCServe_FuncId funcId,
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) param,
    P2VAR(Os_MultiCoreServeType, AUTOMATIC, OS_APPL_DATA) multiCoreServe
)
{
    Os_StatusType ret = E_OS_OK;
    uint8 writeId;
    Os_Arch_IntState intState;

    /* Disable interrupt. */
    Os_Arch_IntDisable(&intState);
    /* Get write idex. */
    writeId = multiCoreServe->writeId;
    /* If the buffer is full. */
    if( Os_MULTICORE_MESSAGE_SIZE == writeId )
    {
        ret = E_OS_BUFFFULL;
    }
    else
    {
        /* Copy parameter to the share buffer. */
        Os_MultiCore_ParamMemCyp(param, &(multiCoreServe->Os_CoreServe[writeId].Os_MultiCoreServeParam));
        /* Set des core id. */
        multiCoreServe->Os_CoreServe[writeId].isSync = isSync;
        /* Set trigger function id. */
        multiCoreServe->Os_CoreServe[writeId].funcId = funcId;
        /* Set active flag. */
        multiCoreServe->Os_CoreServe[writeId].active = TRUE;
        /* Increase write id. */
        multiCoreServe->writeId++;
    }

    /* Enable interrupt. */
    Os_Arch_IntEnable(intState);

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MultiCoreServer_Read
*
* Explanation: Multicore service write operations.
*
* Param: multiCoreServe: Multicore service parameters.
*        multiCoreComm: Multicore service command.
*        desCore: Destination core logical index.
*
* Retval: E_OS_OK: No error.
*         E_OS_BUFFEMPTY: The buffer is empty.
********************************************************************************
*/
static FUNC(Os_StatusType, OS_CODE) Os_MultiCoreServer_Read
(
    P2VAR(Os_MultiCoreServeType, AUTOMATIC, OS_APPL_DATA) multiCoreServe,
    P2VAR(Os_MultiCoreCommType, AUTOMATIC, OS_APPL_DATA) multiCoreComm,
    CoreIdType desCore,
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) param
)
{
    Os_StatusType ret = E_OS_OK;
    boolean breakFlag = FALSE;
    uint8 writeId;
    Os_Arch_IntState intState;
#if( OS_CFG_MULTI_CORE_TIMEOUT == STD_ON )
    const Os_CounterBaseCfgType* counterBaseCfg;
    TickType timeOld, timeNew;
#endif
    /* Disable interrupt. */
    Os_Arch_IntDisable(&intState);
    /* Get write idex. */
    writeId = multiCoreServe->writeId;
    /* If the buffer is empty. */
    if( Os_MULTICORE_INIT == writeId )
    {
        ret = E_OS_BUFFEMPTY;
    }
    else
    {
        writeId--;
    }
    /* Enable interrupt. */
    Os_Arch_IntEnable(intState);
#if( OS_CFG_MULTI_CORE_TIMEOUT == STD_ON )
    /* Get counter configuration data. */
    counterBaseCfg = OS_COUNTER_GETCFG(Os_MultiCfgData.counterId);
    timeOld = Os_Counter_GetCntValue(counterBaseCfg);
#endif
    while( TRUE )
    {
#if( OS_CFG_MULTI_CORE_TIMEOUT == STD_ON )
        /* Get timer value. */
        timeNew = Os_Counter_GetCntValue(counterBaseCfg);
        if((timeNew - timeOld) > Os_MultiCfgData.TimeoutTick)
        {
            /* Decrease write id. */
            multiCoreServe->writeId--;
            /* return timeout error. */
            ret = E_OS_TIMEOUT;
            /* Set break flag. */
            breakFlag = TRUE;
        }
#endif
        /* If the core is processing multi core server. */
        if( FALSE == multiCoreComm->active )
        {
            /* Disable interrupt. */
            Os_Arch_IntDisable(&intState);
            /* If the received request is the sent request. */
            if( FALSE == multiCoreServe->Os_CoreServe[writeId].active )
            {
                /* Decrease write id. */
                multiCoreServe->writeId--;
                /* Copy parameter to the share buffer. */
                Os_MultiCore_ParamMemCyp(&(multiCoreServe->Os_CoreServe[writeId].Os_MultiCoreServeParam), param);
                /* Set return value. */
                ret = multiCoreServe->Os_CoreServe[writeId].retVal;
                /* Set break flag. */
                breakFlag = TRUE;
            }
            else
            {
                /* Set active flag. */
                multiCoreComm->active = TRUE;
                /* Set parameter cache address. */
                multiCoreComm->addr = &(multiCoreServe->Os_CoreServe[writeId]);
                /* Trigger target code. */
                Os_Arch_Trigger_Core(desCore);
                /* If the service is asynchronous. */
                if( FALSE == multiCoreServe->Os_CoreServe[writeId].isSync )
                {
                    /* Decrease write id. */
                    multiCoreServe->writeId--;
                    /* Set break flag. */
                    breakFlag = TRUE;
                }
            }
            /* Enable interrupt. */
            Os_Arch_IntEnable(intState);
        }

        /* Whether to exit the loop. */
        if( TRUE == breakFlag )
        {
            break;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MultiCore_Sync
*
* Explanation: Perform multi-core synchronization.
*
* Param: coreId: Core logical index.
*        syncCounter: How many times to sync.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_MultiCore_Sync
(
    CoreIdType coreId,
    uint8 syncCounter
)
{
    uint8 syncIdx;
    uint8 syncRet;

    do
    {
        Os_MultiCoreSync[coreId] = Os_MultiCoreSync[coreId] | OS_MULTICOREMATCH(syncCounter);
        syncRet = OS_MULTICOREMATCH(syncCounter);
        for( syncIdx = 0U; syncIdx < (uint8)OS_COREID_COUNT; syncIdx++ )
        {
            syncRet &= Os_MultiCoreSync[syncIdx];
        }
    } while( FALSE == syncRet );
}

/*
********************************************************************************
* Function Name: Os_MultiCore_Trigger
*
* Explanation: Multicore service trigger function.
*
* Param: isSync: Whether the synchronization flag.
*        srcCore: Source core logical index.
*        desCore: Destination core logical index.
*        funcId: Multicore service function Id.
*        param: Multi-core service function call parameters.
*
* Retval: E_OS_OK: No error.
*         E_OS_CORE: Core is not available.
*         E_OS_BUFFFULL: The buffer is full.
*         E_OS_BUFFEMPTY: The buffer is empty.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_MultiCore_Trigger
(
    boolean isSync,
    CoreIdType srcCore,
    CoreIdType desCore,
    Os_MCServe_FuncId funcId,
    P2VAR(Os_MultiCoreServeParamType, AUTOMATIC, OS_APPL_DATA) param
)
{
    Os_StatusType ret;
    uint8 buffOffset;
    Os_MultiCoreCommType* multicoreComm;
    Os_MultiCoreServeType* multiCoreServe;

    /* If the core id is out of the range. */
    if( OS_CORE_ISNOTVALID(srcCore) || OS_CORE_ISNOTVALID(desCore) )
    {
        ret = E_OS_CORE;
    }
    else
    {
        /* Get share memory. */
        buffOffset = Os_MultiCore_GetSendBuff(srcCore, desCore);
        multicoreComm = &Os_MCServe_ShareMemory[buffOffset + (uint8)OS_MULTICORE_GETBUFF((uint8)desCore)];
        /* Get core server buffer. */
        multiCoreServe = &Os_MultiCoreServe[(uint8)srcCore];
        ret = Os_MultiCoreServer_Write(isSync, funcId, param, multiCoreServe);

        if( E_OS_OK == ret )
        {
            ret = Os_MultiCoreServer_Read(multiCoreServe, multicoreComm, desCore, param);
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_MultiCoreServer_Handler
*
* Explanation: Multi-core service receive processing function.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
OS_ISR(Os_MultiCoreServer_Handler)
{
    Os_StatusType status;
    uint8 index;
    CoreIdType coreId;
    Os_MCServe_FuncId funcId;
    Os_MultiCoreCommType* multicoreComm;
    Os_CoreServeType* coreServe;
    Os_MCServe_Func func;

    /* Disable interrupt. */
    Os_Arch_IntDisableAll();
    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();
    /* Clear interrupt flag. */
    Os_Arch_ClrMultiInt(coreId);
    /* Get share memory. */
    multicoreComm = &Os_MCServe_ShareMemory[OS_MULTICORE_GETBUFF((uint8)coreId)];

    /* Loop to find the core that generated the trigger request. */
    for( index = Os_MULTICORE_INIT; index < ((uint8)OS_COREID_COUNT - (uint8)Os_MULTICORE_VALU_ONE); index++ )
    {
        /* If the multi-core service is triggered. */
        if( TRUE == multicoreComm[index].active )
        {
            /* Get core server information. */
            coreServe = multicoreComm[index].addr;
            /* Get function id. */
            funcId = coreServe->funcId;
            /* Get multi-core service processing function. */
            func = MultiCoreFuncList[funcId];
            /* Execute multi-core service processing functions. */
            status = func(&(coreServe->Os_MultiCoreServeParam));
            /* Write the return value. */
            coreServe->retVal = status;
            /* Clear active flag. */
            coreServe->active = FALSE;
            multicoreComm[index].active = FALSE;
        }
    }
}

/*
********************************************************************************
* Function Name: Os_Core_Sync
*
* Explanation: Multi core synchronization function.
*
* Param: syncCounter: Synchronous serial number, Can only be 0, 1, 2.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Core_Sync(uint8 syncCounter)
{
    CoreIdType coreId;

    if( syncCounter <= OS_MULTISYNCSECOND )
    {
        /* Get the current logical core id. */
        coreId = Os_Core_GetLogicId();
        /* Multi-core synchronization. */
        Os_MultiCore_Sync(coreId, OS_MULTISYNCFIFTH + syncCounter);
    }
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_CFG_MULTI_CORE == STD_ON */

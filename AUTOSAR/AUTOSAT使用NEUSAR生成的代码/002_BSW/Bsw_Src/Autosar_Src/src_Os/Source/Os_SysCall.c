/*
********************************************************************************
*
*  File name: Os_SysCall.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: BaoWL/2022.01.02
* Change: New created.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2022.11.21
* Change: Change OS_VAR_NOINIT to OS_VAR_NO_INIT.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: HanCL/2023.1.12
* Change: Modify SC1 to support calling APP interface.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.2.14
* Change: Memory protection code optimization and annotation optimization.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.2.15
* Change: Remove useless return values.
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2023.3.28
* Change: Os_Task_WrongReturn function adds a self scheduling function.
* Cause: Bugfix
********************************************************************************
* Version: 3.7
* Author/Date: LiG/2023.4.4
* Change: Remove useless parameters.
* Cause: Bugfix
********************************************************************************
* Version: 3.8
* Author/Date: LiG/2023.10.3
* Change: Add the relevant functions of the EnableInterruptSource
*         DisableInterruptSource and ControlIdle interface and coding
*         specification issues.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: LiG/2023.10.24
* Change: Add monitor module SC3 interface,and modify variables used in the
*         Os_SysCall_DisableInterruptSource interface.
* Cause: bugfix
********************************************************************************
* Version: 3.10
* Author/Date: LiG/2023.10.24
* Change: Add compilation macros for the monitor module.
* Cause: bugfix
********************************************************************************
* Version: 3.11
* Author/Date: LiG/2023.10.24
* Change: Add header file.
* Cause: bugfix
********************************************************************************
* Version: 3.12
* Author/Date: ZhangY/2023.8.7
* Change: Add Os_SysCall_AllowAccess fuction.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: ZhangY/2023.10.07
* Change: Modify Os_SysCall_TaskWrongReturn Os_SysCall_GetTaskStackUsage
*         and Os_SysCall_GetISRStackUsage for QAC.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: ZhangY/2023.10.09
* Change: Modify Os_SysCall_TaskWrongReturn for QAC.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: ZhangY/2024.01.10
* Change: Add conditional compilation for Os_SysCall_Isr_Exit.
* Cause: Bugfix
********************************************************************************
* Version: 3.16
* Author/Date: LiG/2024.3.15
* Change: To prevent optimization, keywords were added to prevent optimization.
* Cause: Bugfix
********************************************************************************
* Version: 3.17
* Author/Date: JiangGL/2024.03.07
* Change: Added the "Os_SysCallHandlerEnableAllInterrupts" interface to adapt to
*         the issue of global interrupts not being able to be closed when exiting
*          a chip with "OS_ARCH_INTMASKLEVE_SUPPORT" authorization interrupt.
* Cause: Bugfix
********************************************************************************
* Version: 3.18
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
#include "Std_Types.h"
#include "Os_SysCall_Types.h"
#include "Os_Spinlock.h"
#include "Os_SchdTb.h"
#include "Os_Isr.h"
#include "Os_Task.h"
#include "Os_Alarm.h"
#include "Os_App.h"
#include "Os_Counter.h"
#include "Os_Arch_Core.h"
#include "Os_Event.h"
#include "Os_Resource.h"
#include "Os_Ioc.h"
#include "Os_Core.h"
#include "Os_Arch_Context.h"
#include "Os_TrustFun.h"
#include "Os_SchdTb.h"
#include "Os_SysCall.h"
#include "Os_Stack.h"
#include "Os_Monitor.h"
#include "Os_Arch_Types.h"

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
*    Local Functions
********************************************************************************
*/
#if( OS_MEMORY_PROTECTION == STD_ON )
static FUNC(void, OS_CODE) Os_SysCall_ActivateTask
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_TerminateTask
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_ChainTask
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_GetTaskID
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_GetTaskState
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_GetAlarm
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_GetAlarmBase
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_SetRelAlarm
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_SetAbsAlarm
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_CancelAlarm
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_TerminateApplication
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_GetApplicationState
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_AllowAccess
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_GetApplicationID
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_GetCurrentApplicationID
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_GetCoreID
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_ShutdownAllCores
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_ShutdownOS
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_IncrementCounter
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_GetCounterValue
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_GetElapsedValue
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
#if( OS_CFG_EVENT_ENABLE == STD_ON )
static FUNC(void, OS_CODE) Os_SysCall_ClearEvent
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_GetEvent
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_SetEvent
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_WaitEvent
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
#endif /* OS_CFG_EVENT_ENABLE == STD_ON */
static FUNC(void, OS_CODE) Os_SysCall_GetISRID
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_DisableAllInterrupts
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static void Os_SysCall_EnableAllInterrupts
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_SuspendAllInterrupts
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_ResumeAllInterrupts
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_SuspendOSInterrupts
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_ResumeOSInterrupts
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
#if( OS_ARCH != ARCH_CONTEXT_M )
static FUNC(void, OS_CODE) Os_SysCall_Isr_Exit
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
#endif
static FUNC(void, OS_CODE) Os_SysCall_TaskWrongReturn
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
#if( OS_CFG_RESOURCE_ENABLE == STD_ON )
static FUNC(void, OS_CODE) Os_SysCall_GetResource
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_ReleaseResource
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
#endif /* OS_CFG_RESOURCE_ENABLE == STD_ON */
#if( OS_CFG_SPINLOCK_ENABLE == STD_ON )
static FUNC(void, OS_CODE) Os_SysCall_GetSpinlock
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_ReleaseSpinlock
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_TryToGetSpinlock
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
#endif /* OS_CFG_SPINLOCK_ENABLE == STD_ON */
#if( OS_CFG_IOC_ENABLE == STD_ON )
static FUNC(void, OS_CODE) Os_SysCall_IocWrite
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_IocRead
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_IocSend
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_IocReceive
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_IocEmptyQueue
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
#endif /* OS_CFG_IOC_ENABLE == STD_ON */
#if( OS_CFG_TRUSTFUN == STD_ON )
static FUNC(void, OS_CODE) Os_SysCall_CallTrustedFunction
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
#endif
#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
static FUNC(void, OS_CODE) Os_SysCall_StartSchTbRel
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_StartSchTbAbs
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_StopScheduleTable
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_NextScheduleTable
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_StartSchTbSync
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_SyncScheduleTable
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_SetSchTbAsync
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_GetSchTbStatus
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
#endif /* OS_CFG_SCHDTB_ENABLE  == STD_ON */
static FUNC(void, OS_CODE) Os_SysCall_GetTaskStackUsage
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_GetISRStackUsage
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_EnableInterruptSource
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
static FUNC(void, OS_CODE) Os_SysCall_DisableInterruptSource
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
#if (OS_IDLEMODE_ENABLE == STD_ON)
static FUNC(void, OS_CODE) Os_SysCall_ControlIdle
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
#endif /* OS_IDLEMODE_ENABLE == STD_ON */
#if( OS_MONITOR_ENABLE == STD_ON )
static FUNC(void, OS_CODE) Os_SysCall_Monitor
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
#endif /* OS_MONITOR_ENABLE == STD_ON */
#endif/* OS_MEMORY_PROTECTION == STD_ON */

/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
#define OS_START_SEC_CONST
#include "Os_MemMap.h"
#if( OS_MEMORY_PROTECTION == STD_ON )
static CONST(Os_SysCall_Func, OS_CONST) Os_SysCallFunc_List[Os_Syscall_Func_Counter] =
{
    Os_SysCall_ActivateTask,
    Os_SysCall_TerminateTask,
    Os_SysCall_ChainTask,
    Os_SysCall_GetTaskID,
    Os_SysCall_GetTaskState,
    Os_SysCall_GetAlarm,
    Os_SysCall_GetAlarmBase,
    Os_SysCall_SetRelAlarm,
    Os_SysCall_SetAbsAlarm,
    Os_SysCall_CancelAlarm,
    Os_SysCall_TerminateApplication,
    Os_SysCall_GetApplicationState,
    Os_SysCall_AllowAccess,
    Os_SysCall_GetApplicationID,
    Os_SysCall_GetCurrentApplicationID,
    Os_SysCall_GetCoreID,
    Os_SysCall_ShutdownAllCores,
    Os_SysCall_ShutdownOS,
    Os_SysCall_IncrementCounter,
    Os_SysCall_GetCounterValue,
    Os_SysCall_GetElapsedValue,
#if( OS_CFG_EVENT_ENABLE == STD_ON )
    Os_SysCall_ClearEvent,
    Os_SysCall_GetEvent,
    Os_SysCall_SetEvent,
    Os_SysCall_WaitEvent,
#endif /* OS_CFG_EVENT_ENABLE == STD_ON */
    Os_SysCall_GetISRID,
    Os_SysCall_DisableAllInterrupts,
    Os_SysCall_EnableAllInterrupts,
    Os_SysCall_SuspendAllInterrupts,
    Os_SysCall_ResumeAllInterrupts,
    Os_SysCall_SuspendOSInterrupts,
    Os_SysCall_ResumeOSInterrupts,
#if( OS_ARCH != ARCH_CONTEXT_M )
    Os_SysCall_Isr_Exit,
#endif
    Os_SysCall_TaskWrongReturn,
#if( OS_CFG_RESOURCE_ENABLE == STD_ON )
    Os_SysCall_GetResource,
    Os_SysCall_ReleaseResource,
#endif /* OS_CFG_RESOURCE_ENABLE == STD_ON */
#if( OS_CFG_SPINLOCK_ENABLE == STD_ON )
    Os_SysCall_GetSpinlock,
    Os_SysCall_ReleaseSpinlock,
    Os_SysCall_TryToGetSpinlock,
#endif /* OS_CFG_SPINLOCK_ENABLE == STD_ON */
#if( OS_CFG_IOC_ENABLE == STD_ON )
    Os_SysCall_IocWrite,
    Os_SysCall_IocRead,
    Os_SysCall_IocSend,
    Os_SysCall_IocReceive,
    Os_SysCall_IocEmptyQueue,
#endif /* OS_CFG_IOC_ENABLE == STD_ON */
#if( OS_CFG_TRUSTFUN == STD_ON )
    Os_SysCall_CallTrustedFunction,
#endif
#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    Os_SysCall_StartSchTbRel,
    Os_SysCall_StartSchTbAbs,
    Os_SysCall_StopScheduleTable,
    Os_SysCall_NextScheduleTable,
    Os_SysCall_StartSchTbSync,
    Os_SysCall_SyncScheduleTable,
    Os_SysCall_SetSchTbAsync,
    Os_SysCall_GetSchTbStatus,
#endif /* OS_CFG_SCHDTB_ENABLE == STD_ON */
    Os_SysCall_GetTaskStackUsage,
    Os_SysCall_GetISRStackUsage,
    Os_SysCall_EnableInterruptSource,
    Os_SysCall_DisableInterruptSource,
#if(OS_IDLEMODE_ENABLE == STD_ON)
    Os_SysCall_ControlIdle,
#endif /* OS_IDLEMODE_ENABLE == STD_ON */
#if( OS_MONITOR_ENABLE == STD_ON )
    Os_SysCall_Monitor
#endif /* OS_MONITOR_ENABLE == STD_ON */
};
#endif/* OS_MEMORY_PROTECTION == STD_ON */
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
* Function Name: Os_SysCall_ActivateTask
*
* Explanation: System call function, see ActivateTask.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
#if( OS_MEMORY_PROTECTION == STD_ON )
static FUNC(void, OS_CODE) Os_SysCall_ActivateTask
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    TaskType taskId;

    taskId = parameter->Os_ActivateTask.taskId;
    ret = Os_Task_ActivateTask(taskId);

    parameter->Os_ActivateTask.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_TerminateTask
*
* Explanation: System call function, see TerminateTask.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_TerminateTask
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_Task_TerminateTask();
    parameter->Os_TerminateTask.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_ChainTask
*
* Explanation: System call function, see ChainTask.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_ChainTask
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    TaskType taskId;

    taskId = parameter->Os_ChainTask.taskId;
    ret = Os_Task_ChainTask(taskId);
    parameter->Os_ChainTask.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_GetTaskID
*
* Explanation: System call function, see GetTaskID.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_GetTaskID
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    TaskRefType taskId;

    taskId = parameter->Os_GetTaskID.taskId;
    ret = Os_Task_GetTaskID(taskId);
    parameter->Os_GetTaskID.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_GetTaskState
*
* Explanation: System call function, see GetTaskState.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_GetTaskState
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    TaskType taskId;
    TaskStateRefType taskStateRef;

    taskId = parameter->Os_GetTaskState.taskId;
    taskStateRef = parameter->Os_GetTaskState.state;
    ret = Os_Task_GetTaskState(taskId, taskStateRef);
    parameter->Os_GetTaskState.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_GetAlarm
*
* Explanation: System call function, see GetAlarm.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_GetAlarm
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    AlarmType alarmId;
    TickRefType tick;

    alarmId = parameter->Os_GetAlarm.alarmId;
    tick = parameter->Os_GetAlarm.tick;
    ret = Os_Alarm_GetAlarm(alarmId, tick);
    parameter->Os_GetAlarm.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_GetAlarmBase
*
* Explanation: System call function, see GetAlarmBase.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_GetAlarmBase
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    AlarmType alarmId;
    AlarmBaseRefType baseRef;

    alarmId = parameter->Os_GetAlarmBase.alarmId;
    baseRef = parameter->Os_GetAlarmBase.info;
    ret = Os_Alarm_GetAlarmBase(alarmId, baseRef);
    parameter->Os_GetAlarmBase.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_SetRelAlarm
*
* Explanation: System call function, see SetRelAlarm.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_SetRelAlarm
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    AlarmType alarmId;
    Os_TickType increment;
    Os_TickType cycle;

    alarmId = parameter->Os_SetRelAlarm.alarmId;
    increment = parameter->Os_SetRelAlarm.increment;
    cycle = parameter->Os_SetRelAlarm.cycle;
    ret = Os_Alarm_SetRelAlarm(alarmId, increment, cycle);
    parameter->Os_SetRelAlarm.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_SetAbsAlarm
*
* Explanation: System call function, see SetAbsAlarm.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_SetAbsAlarm
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    AlarmType alarmId;
    Os_TickType start;
    Os_TickType cycle;

    alarmId = parameter->Os_SetAbsAlarm.alarmId;
    start = parameter->Os_SetAbsAlarm.start;
    cycle = parameter->Os_SetAbsAlarm.cycle;
    ret = Os_Alarm_SetAbsAlarm(alarmId, start, cycle);
    parameter->Os_SetAbsAlarm.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_CancelAlarm
*
* Explanation: System call function, see CancelAlarm.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_CancelAlarm
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    AlarmType alarmId;

    alarmId = parameter->Os_CancelAlarm.alarmId;
    ret = Os_Alarm_CancelAlarm(alarmId);
    parameter->Os_CancelAlarm.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_TerminateApplication
*
* Explanation: System call function, see TerminateApplication.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_TerminateApplication
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    ApplicationType appId;
    RestartType restartOption;

    appId = parameter->Os_TerminateApplication.appId;
    restartOption = parameter->Os_TerminateApplication.restartOption;
    ret = Os_App_TerminationApp(appId, restartOption);
    parameter->Os_TerminateApplication.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_GetApplicationState
*
* Explanation: System call function, see GetApplicationState.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_GetApplicationState
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    ApplicationType appId;
    ApplicationStateRefType value;

    appId = parameter->Os_GetApplicationState.appId;
    value = parameter->Os_GetApplicationState.value;
    ret = Os_App_GetAppState(appId, value);
    parameter->Os_GetApplicationState.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_AllowAccess
*
* Explanation: System call function, see AllowAccess.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_AllowAccess
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;

    ret = Os_App_AllowAccess();
    parameter->Os_AllowAccess.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_GetApplicationID
*
* Explanation: System call function, see GetApplicationID.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_GetApplicationID
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    ApplicationType ret;

    ret = Os_App_GetAppId();
    parameter->Os_GetApplicationID.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_GetCurrentApplicationID
*
* Explanation: System call function, see GetCurrentApplicationID.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_GetCurrentApplicationID
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    ApplicationType ret;

    ret = Os_App_GetCurrentAppId();
    parameter->Os_GetCurrentApplicationID.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_GetCoreID
*
* Explanation: System call function, see GetCoreID.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_GetCoreID
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    CoreIdType ret;

    ret = Os_Core_GetLogicId();
    parameter->Os_GetCoreID.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_ShutdownAllCores
*
* Explanation: System call function, see ShutdownAllCores.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_ShutdownAllCores
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    StatusType error;

    error = parameter->Os_ShutdownAllCores.error;
    Os_Core_ShutdownAllCores(error);
    parameter->Os_ShutdownAllCores.retVal = E_OS_OK;
}

/*
********************************************************************************
* Function Name: Os_SysCall_ShutdownOS
*
* Explanation: System call function, see ShutdownOS.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_ShutdownOS
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    StatusType error;

    error = parameter->Os_ShutdownOS.error;
    Os_Core_ShutdownOs(error);
    parameter->Os_ShutdownOS.retVal = E_OS_OK;
}

/*
********************************************************************************
* Function Name: Os_SysCall_IncrementCounte
*
* Explanation: System call function, see IncrementCounte.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_IncrementCounter
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    CounterType counterId;

    counterId = parameter->Os_IncrementCounter.counterId;
    ret = Os_Counter_IncrementCounter(counterId);
    parameter->Os_IncrementCounter.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_GetCounterValue
*
* Explanation: System call function, see GetCounterValue.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_GetCounterValue
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    CounterType counterId;
    TickRefType value;

    counterId = parameter->Os_GetCounterValue.counterId;
    value = parameter->Os_GetCounterValue.value;
    ret = Os_Counter_GetCounterValue(counterId, value);
    parameter->Os_GetCounterValue.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_GetElapsedValue
*
* Explanation: System call function, see GetElapsedValue.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_GetElapsedValue
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    CounterType counterId;
    TickRefType value;
    TickRefType elapsedValue;

    counterId = parameter->Os_GetElapsedValue.counterId;
    value = parameter->Os_GetElapsedValue.value;
    elapsedValue = parameter->Os_GetElapsedValue.elapsedValue;
    ret = Os_Counter_GetElapsedValue(counterId, value, elapsedValue);
    parameter->Os_GetElapsedValue.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_ClearEvent
*
* Explanation: System call function, see ClearEvent.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
#if( OS_CFG_EVENT_ENABLE == STD_ON )
static FUNC(void, OS_CODE) Os_SysCall_ClearEvent
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    EventMaskType mask;

    mask = parameter->Os_ClearEvent.mask;
    ret = Os_Event_ClearEvent(mask);
    parameter->Os_ClearEvent.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_GetEvent
*
* Explanation: System call function, see GetEvent.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_GetEvent
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    TaskType taskId;
    EventMaskRefType mask;

    taskId = parameter->Os_GetEvent.taskId;
    mask = parameter->Os_GetEvent.mask;
    ret = Os_Event_GetEvent(taskId, mask);
    parameter->Os_GetEvent.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_SetEvent
*
* Explanation: System call function, see SetEvent.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_SetEvent
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    TaskType taskId;
    EventMaskType mask;

    taskId = parameter->Os_SetEvent.taskId;
    mask = parameter->Os_SetEvent.mask;
    ret = Os_Event_SetEvent(taskId, mask);
    parameter->Os_SetEvent.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_WaitEvent
*
* Explanation: System call function, see WaitEvent.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_WaitEvent
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    EventMaskType mask;

    mask = parameter->Os_WaitEvent.mask;
    ret = Os_Event_WaitEvent(mask);
    parameter->Os_WaitEvent.retVal = ret;
}
#endif /* OS_CFG_EVENT_ENABLE == STD_ON */

/*
********************************************************************************
* Function Name: Os_SysCall_GetISRID
*
* Explanation: System call function, see GetISRID.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_GetISRID
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    ISRType ret;

    ret = Os_Isr_GetISRID();
    parameter->Os_GetISRID.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_DisableAllInterrupts
*
* Explanation: System call function, see DisableAllInterrupts.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_DisableAllInterrupts
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    OS_DUMMY_STATEMENT(parameter);
    Os_Core_DisableAllInterrupts();
}

/*
********************************************************************************
* Function Name: Os_SysCall_EnableAllInterrupts
*
* Explanation: System call function, see EnableAllInterrupts.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static void Os_SysCall_EnableAllInterrupts
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    OS_DUMMY_STATEMENT(parameter);
    Os_Core_EnableAllInterrupts();
}

/*
********************************************************************************
* Function Name: Os_SysCall_SuspendAllInterrupts
*
* Explanation: System call function, see SuspendAllInterrupts.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_SuspendAllInterrupts
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    OS_DUMMY_STATEMENT(parameter);
    Os_Core_SuspendAllInterrupts();
}

/*
********************************************************************************
* Function Name: Os_SysCall_ResumeAllInterrupts
*
* Explanation: System call function, see ResumeAllInterrupts.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_ResumeAllInterrupts
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    OS_DUMMY_STATEMENT(parameter);
    Os_Core_ResumeAllInterrupts();
}

/*
********************************************************************************
* Function Name: Os_SysCall_SuspendOSInterrupts
*
* Explanation: System call function, see SuspendOSInterrupts.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_SuspendOSInterrupts
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    OS_DUMMY_STATEMENT(parameter);
    Os_Core_SuspendOSInterrupts();
}

/*
********************************************************************************
* Function Name: Os_SysCall_ResumeOSInterrupts
*
* Explanation: System call function, see ResumeOSInterrupts.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_ResumeOSInterrupts
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    OS_DUMMY_STATEMENT(parameter);
    Os_Core_ResumeOSInterrupts();
}

#if( OS_ARCH != ARCH_CONTEXT_M )
/*
********************************************************************************
* Function Name: Os_SysCall_Isr_Exit
*
* Explanation: System call function, see Isr_Exit.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_Isr_Exit
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    OS_DUMMY_STATEMENT(parameter);
    Os_Isr_Exit();
}
#endif

/*
********************************************************************************
* Function Name: Os_SysCall_TaskWrongReturn
*
* Explanation: System call function, see TaskWrongReturn.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_TaskWrongReturn
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    OS_DUMMY_STATEMENT(parameter);
    Os_Task_WrongReturn();
}

/*
********************************************************************************
* Function Name: Os_SysCall_GetResource
*
* Explanation: System call function, see GetResource.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
#if( OS_CFG_RESOURCE_ENABLE == STD_ON )
static FUNC(void, OS_CODE) Os_SysCall_GetResource
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    ResourceType resId;

    resId = parameter->Os_GetResource.resId;
    ret = Os_Resource_GetResource(resId);
    parameter->Os_GetResource.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_ReleaseResource
*
* Explanation: System call function, see ReleaseResource.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_ReleaseResource
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    ResourceType resId;

    resId = parameter->Os_ReleaseResource.resId;
    ret = Os_Resource_ReleaseResource(resId);
    parameter->Os_ReleaseResource.retVal = ret;
}
#endif /* OS_CFG_RESOURCE_ENABLE == STD_ON */

/*
********************************************************************************
* Function Name: Os_SysCall_GetSpinlock
*
* Explanation: System call function, see GetSpinlock.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
#if( OS_CFG_SPINLOCK_ENABLE == STD_ON )
static FUNC(void, OS_CODE) Os_SysCall_GetSpinlock
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    SpinlockIdType spinlockId;

    spinlockId = parameter->Os_GetSpinlock.spinlockId;
    ret = Os_Spinlock_GetSpinlock(spinlockId);
    parameter->Os_GetSpinlock.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_ReleaseSpinlock
*
* Explanation: System call function, see ReleaseSpinlock.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_ReleaseSpinlock
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    SpinlockIdType spinlockId;

    spinlockId = parameter->Os_ReleaseSpinlock.spinlockId;
    ret = Os_Spinlock_ReleaseSpinlock(spinlockId);
    parameter->Os_ReleaseSpinlock.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_TryToGetSpinlock
*
* Explanation: System call function, see TryToGetSpinlock.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_TryToGetSpinlock
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    SpinlockIdType spinlockId;
    TryToGetSpinlockType* success;

    spinlockId = parameter->Os_TryToGetSpinlock.spinlockId;
    success = parameter->Os_TryToGetSpinlock.success;
    ret = Os_Spinlock_TryToGetSpinlock(spinlockId, success);
    parameter->Os_TryToGetSpinlock.retVal = ret;
}
#endif /* OS_CFG_SPINLOCK_ENABLE == STD_ON */

/*
********************************************************************************
* Function Name: Os_SysCall_IocWrite
*
* Explanation: System call function, see IocWrite.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
#if( OS_CFG_IOC_ENABLE == STD_ON )
static FUNC(void, OS_CODE) Os_SysCall_IocWrite
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    const Os_IocCfgType* iocCfg;
    uint32 senderId;
    const void*const* data;

    iocCfg = parameter->Os_IocWrite.iocCfg;
    senderId = parameter->Os_IocWrite.senderId;
    data = parameter->Os_IocWrite.data;
    ret = (Os_StatusType)Os_Ioc_IntlWrite(iocCfg, senderId, data);
    parameter->Os_IocWrite.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_IocRead
*
* Explanation: System call function, see IocRead.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_IocRead
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    const Os_IocCfgType* iocCfg;
    const void*const* data;

    iocCfg = parameter->Os_IocRead.iocCfg;
    data = parameter->Os_IocRead.data;
    ret = (Os_StatusType)Os_Ioc_IntlRead(iocCfg, data);
    parameter->Os_IocRead.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_IocSend
*
* Explanation: System call function, see IocSend.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_IocSend
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    const Os_IocCfgType* iocCfg;
    uint32 senderId;
    const void*const* data;

    iocCfg = parameter->Os_IocSend.iocCfg;
    senderId = parameter->Os_IocSend.senderId;
    data = parameter->Os_IocSend.data;
    ret = (Os_StatusType)Os_Ioc_IntlSend(iocCfg, senderId, data);
    parameter->Os_IocSend.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_IocReceive
*
* Explanation: System call function, see IocReceive.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_IocReceive
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    const Os_IocCfgType* iocCfg;
    const void*const* data;

    iocCfg = parameter->Os_IocReceive.iocCfg;
    data = parameter->Os_IocReceive.data;
    ret = (Os_StatusType)Os_Ioc_IntlReceive(iocCfg, data);
    parameter->Os_IocReceive.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_IocEmptyQueue
*
* Explanation: System call function, see IocEmptyQueue.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_IocEmptyQueue
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    const Os_IocCfgType* iocCfg;

    iocCfg = parameter->Os_IocEmptyQueue.iocCfg;
    Os_Ioc_ClearQueue(iocCfg);
    parameter->Os_IocEmptyQueue.retVal = E_OS_OK;
}
#endif /* OS_CFG_IOC_ENABLE == STD_ON */

/*
********************************************************************************
* Function Name: Os_SysCall_CallTrustedFunction
*
* Explanation: System call function, see CallTrustedFunction.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
#if( OS_CFG_TRUSTFUN == STD_ON )
static FUNC(void, OS_CODE) Os_SysCall_CallTrustedFunction
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    StatusType ret;
    TrustedFunctionIndexType functionIndex;
    TrustedFunctionParameterRefType functionParams;

    functionIndex = parameter->Os_CallTrustedFunction.functionIndex;
    functionParams = parameter->Os_CallTrustedFunction.functionParams;
    ret = Os_Call_TrustedFunction(functionIndex, functionParams);
    parameter->Os_CallTrustedFunction.retVal = ret;
}
#endif

/*
********************************************************************************
* Function Name: Os_SysCall_StartSchTbRel
*
* Explanation: System call function, see StartScheduleTableRel.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
static FUNC(void, OS_CODE) Os_SysCall_StartSchTbRel
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    StatusType ret;
    ScheduleTableType scheduleTableID;
    TickType offset;

    scheduleTableID = parameter->Os_StartScheduleTableRel.scheduleTableID;
    offset = parameter->Os_StartScheduleTableRel.offset;
    ret = Os_SchdTb_StartScheduleTableRel(scheduleTableID, offset);
    parameter->Os_StartScheduleTableRel.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_StartSchTbAbs
*
* Explanation: System call function, see StartScheduleTableAbs.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_StartSchTbAbs
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    StatusType ret;
    ScheduleTableType scheduleTableID;
    TickType start;

    scheduleTableID = parameter->Os_StartScheduleTableAbs.scheduleTableID;
    start = parameter->Os_StartScheduleTableAbs.start;
    ret = Os_SchdTb_StartScheduleTableAbs(scheduleTableID, start);
    parameter->Os_StartScheduleTableAbs.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_StopScheduleTable
*
* Explanation: System call function, see StopScheduleTable.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_StopScheduleTable
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    StatusType ret;
    ScheduleTableType scheduleTableID;

    scheduleTableID = parameter->Os_StopScheduleTable.scheduleTableID;
    ret = Os_SchdTb_StopScheduleTable(scheduleTableID);
    parameter->Os_StopScheduleTable.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_NextScheduleTable
*
* Explanation: System call function, see NextScheduleTable.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_NextScheduleTable
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    StatusType ret;
    ScheduleTableType scheduleTableID_From;
    ScheduleTableType scheduleTableID_To;

    scheduleTableID_From = parameter->Os_NextScheduleTable.scheduleTableID_From;
    scheduleTableID_To = parameter->Os_NextScheduleTable.scheduleTableID_To;
    ret = Os_SchdTb_NextScheduleTable(scheduleTableID_From, scheduleTableID_To);
    parameter->Os_NextScheduleTable.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_StartSchTbSync
*
* Explanation: System call function, see StartScheduleTableSynchron.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_StartSchTbSync
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    StatusType ret;
    ScheduleTableType scheduleTableID;

    scheduleTableID = parameter->Os_StartScheduleTableSynchron.scheduleTableID;
    ret = Os_SchdTb_StartScheduleTableSynchron(scheduleTableID);
    parameter->Os_StartScheduleTableSynchron.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_SyncScheduleTable
*
* Explanation: System call function, see SyncScheduleTable.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_SyncScheduleTable
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    StatusType ret;
    ScheduleTableType scheduleTableID;
    TickType value;

    scheduleTableID = parameter->Os_SyncScheduleTable.scheduleTableID;
    value = parameter->Os_SyncScheduleTable.value;
    ret = Os_SchdTb_SyncScheduleTable(scheduleTableID, value);
    parameter->Os_SyncScheduleTable.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_SetSchTbAsync
*
* Explanation: System call function, see SetScheduleTableAsync.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_SetSchTbAsync
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    StatusType ret;
    ScheduleTableType scheduleTableID;

    scheduleTableID = parameter->Os_SetScheduleTableAsync.scheduleTableID;
    ret = Os_SchdTb_SetScheduleTableAsync(scheduleTableID);
    parameter->Os_SetScheduleTableAsync.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_GetSchTbStatus
*
* Explanation: System call function, see GetScheduleTableStatus.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_GetSchTbStatus
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    StatusType ret;
    ScheduleTableType scheduleTableID;
    ScheduleTableStatusRefType scheduleStatus;

    scheduleTableID = parameter->Os_GetScheduleTableStatus.scheduleTableID;
    scheduleStatus = parameter->Os_GetScheduleTableStatus.scheduleStatus;

    ret = Os_SchdTb_GetScheduleTableStatus(scheduleTableID, scheduleStatus);

    parameter->Os_GetScheduleTableStatus.retVal = ret;
}
#endif /* OS_CFG_SCHDTB_ENABLE  == STD_ON */

/*
********************************************************************************
* Function Name: Os_SysCall_GetTaskStackUsage
*
* Explanation: System call function, see GetTaskStackUsage.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_GetTaskStackUsage
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    TaskType taskId;
    Os_Stack_Size* taskUsage;

    taskId = parameter->Os_GetTaskStackUsage.taskId;
    taskUsage = parameter->Os_GetTaskStackUsage.taskUsage;
    ret = Os_Stack_GetTaskStackUsage(taskId, taskUsage);
    parameter->Os_GetTaskStackUsage.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_GetISRStackUsage
*
* Explanation: System call function, see GetISRStackUsage.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_GetISRStackUsage
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    Os_StatusType ret;
    ISRType isrId;
    Os_Stack_Size* isrUsage;

    isrId = parameter->Os_GetISRStackUsage.isrId;
    isrUsage = parameter->Os_GetISRStackUsage.isrUsage;
    ret = Os_Stack_GetIsrStackUsage(isrId, isrUsage);
    parameter->Os_GetISRStackUsage.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_EnableInterruptSource
*
* Explanation: System call function, uses to enable an interrupt source.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_EnableInterruptSource
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    ISRType isrId;
    boolean clearPending;
    StatusType ret;

    isrId = parameter->Os_EnableInterruptSource.isrId;
    clearPending = parameter->Os_EnableInterruptSource.clearPending;
    ret = Os_Isr_EnableInterruptSource(isrId, clearPending);
    parameter->Os_EnableInterruptSource.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_DisableInterruptSource
*
* Explanation: System call function, uses to disable an interrupt source.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_SysCall_DisableInterruptSource
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    ISRType isrId;
    StatusType ret;

    isrId = parameter->Os_DisableInterruptSource.isrId;
    ret = Os_Isr_DisableInterruptSource(isrId);
    parameter->Os_DisableInterruptSource.retVal = ret;
}

/*
********************************************************************************
* Function Name: Os_SysCall_ControlIdle
*
* Explanation: System call function, uses to select the idle mode.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
#if (OS_IDLEMODE_ENABLE == STD_ON)
static FUNC(void, OS_CODE) Os_SysCall_ControlIdle
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    CoreIdType coreID;
    IdleModeType idleMode;
    StatusType ret;

    coreID = parameter->Os_ControlIdle.coreID;
    idleMode = parameter->Os_ControlIdle.idleMode;
    ret = Os_Core_ControlIdle(coreID, idleMode);
    parameter->Os_ControlIdle.retVal = ret;
}
#endif /* OS_IDLEMODE_ENABLE == STD_ON */
/*
********************************************************************************
* Function Name: Os_SysCall_Monitor
*
* Explanation: System call function, uses to select the idle mode.
*
* Param: parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
#if( OS_MONITOR_ENABLE == STD_ON )
static FUNC(void, OS_CODE) Os_SysCall_Monitor
(
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    OS_DUMMY_STATEMENT(parameter);
#if( OS_MONITOR_ENABLE == STD_ON )
    Os_Monitor_MainFunction();
#endif
}
#endif /* OS_MONITOR_ENABLE == STD_ON */

/*
********************************************************************************
* Function Name: Os_SysCall
*
* Explanation: System call interface function.
*
* Param: funcId: Api function id.
*        parameter: System call function parameters.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_SysCall
(
    Os_Syscall_FuncId funcId,
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
)
{
    volatile Os_SysCallType sysCallData;

    sysCallData.funcId = funcId;
    sysCallData.Os_SysCallParam = parameter;
    /* Call the bottom layer to generate system call instructions. */
    Os_Arch_SysCall(&sysCallData);
}
#endif/* OS_MEMORY_PROTECTION == STD_ON */

/*
********************************************************************************
* Function Name: Os_SysCallHandler
*
* Explanation: System call interrupt service function.
*
* Param: sysCallData: System call data.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_SysCallHandler
(
    P2VAR(Os_SysCallType, AUTOMATIC, OS_APPL_DATA) sysCallData
)
{
#if( OS_MEMORY_PROTECTION == STD_ON )
    uint32 funcId;
    Os_SysCall_Func func;
    /* Get function id. */
    funcId = (uint32)sysCallData->funcId;
    /* If the function id is in the range. */
    if( funcId < (uint32)Os_Syscall_Func_Counter )
    {
        /* Get system function. */
        func = Os_SysCallFunc_List[funcId];
        func(sysCallData->Os_SysCallParam);
    }
#endif /* OS_MEMORY_PROTECTION == STD_ON */
}
#if( OS_MEMORY_PROTECTION == STD_ON )
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_OFF )
/*
********************************************************************************
* Function Name: Os_SysCallHandlerEnableAllInterrupts
*
* Explanation: Check if the syscall interrupt is possible to enable global interrupts.
*
* Param: sysCallData: System call data.
*
* Retval: TRUE: It is possible to enable global interrupt.
*         FALSE: Will not initiate global interrupts proactively.
********************************************************************************
*/
FUNC(boolean, OS_CODE) Os_SysCallHandlerEnableAllInterrupts
(
    P2VAR(Os_SysCallType, AUTOMATIC, OS_APPL_DATA) sysCallData
)
{
    boolean ret = FALSE;
    uint32 funcId;

    /* Get function id. */
    funcId = (uint32)sysCallData->funcId;
    if( (funcId == Os_Syscall_EnableAllInterrupts_ID) ||
        (funcId == Os_Syscall_ResumeAllInterrupts_ID) ||
        (funcId == Os_Syscall_ResumeOsInterrupts_ID) ||
        (funcId == Os_Syscall_ReleaseResource_ID) )
    {
        ret = TRUE;
    }

    return ret;
}
#endif /* OS_ARCH_INTMASKLEVE_SUPPORT == STD_OFF */
#endif /* OS_MEMORY_PROTECTION == STD_ON */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

/*
********************************************************************************
*
*  File name: Os_SysCall_Types.h
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
* Author/Date: HanCL/2023.1.12
* Change: Modify SC1 to support calling APP interface.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.2.14
* Change: Format adjustment and adding return value members.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2023.10.3
* Change: Add the relevant functions of the EnableInterruptSource
*         DisableInterruptSource and ControlIdle's member variables.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.10.8
* Change: Resolve compilation issues.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2023.10.24
* Change: Add monitor module SC3 interface service ID.
* Cause: Bugfix
********************************************************************************
* Version: 3.7
* Author/Date: ZhangY/2024.01.10
* Change: Add conditional compilation for Os_SysCall_Isr_Exit.
* Cause: Bugfix
********************************************************************************
* Version: 3.28
* Author/Date: LiuZB/2025.02.20
* Change: Optimize space size.
* Cause: Update
********************************************************************************
*/
#ifndef OS_SYSCALL_TYPES_H_
#define OS_SYSCALL_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Types_Cfg.h"
#include "Os_Types.h"
#include "Os_Ioc_Types.h"
#include "Os_Cfg.h"
#include "Os_Arch_Mach.h"
#include "Os_Monitor_Cfg.h"

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
typedef enum
{
    Os_Syscall_ActivateTask_ID = 0U,
    Os_Syscall_TerminateTask_ID,
    Os_Syscall_ChainTask_ID,
    Os_Syscall_GetTaskId_ID,
    Os_Syscall_GetTaskState_ID,
    Os_Syscall_GetAlarm_ID,
    Os_Syscall_GetAlarmBase_ID,
    Os_Syscall_SetRelAlarm_ID,
    Os_Syscall_SetAbsAlarm_ID,
    Os_Syscall_CancelAlarm_ID,
    Os_Syscall_TerminateApplication_ID,
    Os_Syscall_GetApplicationState_ID,
    Os_Syscall_AllowAccess_ID,
    Os_Syscall_GetApplicationId_ID,
    Os_Syscall_GetCurrentApplicationId_ID,
    Os_Syscall_GetCoreId_ID,
    Os_Syscall_ShutdownAllCores_ID,
    Os_Syscall_ShutdownOs_ID,
    Os_Syscall_IncrementCounter_ID,
    Os_Syscall_GetCounterValue_ID,
    Os_Syscall_GetElapsedValue_ID,
#if( OS_CFG_EVENT_ENABLE == STD_ON )
    Os_Syscall_ClearEvent_ID,
    Os_Syscall_GetEvent_ID,
    Os_Syscall_SetEvent_ID,
    Os_Syscall_WaitEvent_ID,
#endif /* OS_CFG_EVENT_ENABLE == STD_ON */
    Os_Syscall_GetIsrId_ID,
    Os_Syscall_DisableAllInterrupts_ID,
    Os_Syscall_EnableAllInterrupts_ID,
    Os_Syscall_SuspendAllInterrupts_ID,
    Os_Syscall_ResumeAllInterrupts_ID,
    Os_Syscall_SuspendOsInterrupts_ID,
    Os_Syscall_ResumeOsInterrupts_ID,
#if( OS_ARCH != ARCH_CONTEXT_M )
    Os_Syscall_Isr_Exit_ID,
#endif
    Os_Syscall_Task_Wrongreturn_ID,
#if( OS_CFG_RESOURCE_ENABLE == STD_ON )
    Os_Syscall_GetResource_ID,
    Os_Syscall_ReleaseResource_ID,
#endif /* OS_CFG_RESOURCE_ENABLE == STD_ON */
#if( OS_CFG_SPINLOCK_ENABLE == STD_ON )
    Os_Syscall_GetSpinlock_ID,
    Os_Syscall_ReleaseSpinlock_ID,
    Os_Syscall_TryToGetSpinlock_ID,
#endif /* OS_CFG_SPINLOCK_ENABLE == STD_ON */
#if( OS_CFG_IOC_ENABLE == STD_ON )
    Os_Syscall_IocWrite_ID,
    Os_Syscall_IocRead_ID,
    Os_Syscall_IocSend_ID,
    Os_Syscall_IocReceive_ID,
    Os_Syscall_IocEmptyQueue_ID,
#endif /* OS_CFG_IOC_ENABLE == STD_ON */
#if( OS_CFG_TRUSTFUN == STD_ON )
    Os_Syscall_CallTrustedFunction_ID,
#endif
#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    Os_Syscall_StartScheduleTableRel_ID,
    Os_Syscall_StartScheduleTableAbs_ID,
    Os_Syscall_StopScheduleTable_ID,
    Os_Syscall_NextScheduleTable_ID,
    Os_Syscall_StartScheduleTableSynchron_ID,
    Os_Syscall_SyncScheduleTable_ID,
    Os_Syscall_SetScheduleTableAsync_ID,
    Os_Syscall_GetScheduleTableStatus_ID,
#endif /* OS_CFG_SCHDTB_ENABLE == STD_ON */
    Os_Syscall_GetTaskStackUsage_ID,
    Os_Syscall_GetISRStackUsage_ID,
    Os_Syscall_EnableInterruptSource_ID,
    Os_Syscall_DisableInterruptSource_ID,
#if (OS_IDLEMODE_ENABLE == STD_ON)
    Os_Syscall_ControlIdle_ID,
#endif /* OS_IDLEMODE_ENABLE == STD_ON */
#if( OS_MONITOR_ENABLE == STD_ON )
    Os_Syscall_Monitor_ID,
#endif /* OS_MONITOR_ENABLE == STD_ON */
    Os_Syscall_Func_Counter
} Os_Syscall_FuncId;

typedef union
{
    struct ActivateTask{
        TaskType taskId;
        StatusType retVal;
        } Os_ActivateTask;

    struct TerminateTask{
        StatusType retVal;
        } Os_TerminateTask;

    struct ChainTask{
        TaskType taskId;
        StatusType retVal;
        } Os_ChainTask;

    struct GetTaskID{
        TaskRefType taskId;
        StatusType retVal;
        } Os_GetTaskID;

    struct GetTaskState{
        TaskType taskId;
        TaskStateRefType state;
        StatusType retVal;
        } Os_GetTaskState;

    struct TaskWrongReturn{
        StatusType retVal;
        } Os_TaskWrongReturn;

    struct GetAlarm{
        AlarmType alarmId;
        TickRefType tick;
        StatusType retVal;
        } Os_GetAlarm;

    struct GetAlarmBase{
        AlarmType alarmId;
        AlarmBaseRefType info;
        StatusType retVal;
        } Os_GetAlarmBase;

    struct SetRelAlarm{
        AlarmType alarmId;
        TickType increment;
        TickType cycle;
        StatusType retVal;
        } Os_SetRelAlarm;

    struct SetAbsAlarm{
        AlarmType alarmId;
        TickType start;
        TickType cycle;
        StatusType retVal;
        } Os_SetAbsAlarm;

    struct CancelAlarm{
        AlarmType alarmId;
        StatusType retVal;
        } Os_CancelAlarm;

    struct TerminateApplication{
        ApplicationType appId;
        RestartType restartOption;
        StatusType retVal;
        } Os_TerminateApplication;

    struct GetApplicationState{
        ApplicationType appId;
        ApplicationStateRefType value;
        StatusType retVal;
        } Os_GetApplicationState;

    struct AllowAccess{
        StatusType retVal;
        } Os_AllowAccess;

    struct GetApplicationID{
        ApplicationType retVal;
        } Os_GetApplicationID;

    struct GetCurrentApplicationID{
        ApplicationType retVal;
        } Os_GetCurrentApplicationID;

    struct GetCoreID{
        CoreIdType retVal;
        } Os_GetCoreID;

    struct ShutdownAllCores{
        StatusType error;
        StatusType retVal;
        } Os_ShutdownAllCores;

    struct ShutdownOS{
        StatusType error;
        StatusType retVal;
        } Os_ShutdownOS;

    struct IncrementCounter{
        CounterType counterId;
        StatusType retVal;
        } Os_IncrementCounter;

    struct GetCounterValue{
        CounterType counterId;
        TickRefType value;
        StatusType retVal;
        } Os_GetCounterValue;

    struct GetElapsedValue{
        CounterType counterId;
        TickRefType value;
        TickRefType elapsedValue;
        StatusType retVal;
        } Os_GetElapsedValue;

    struct ClearEvent{
        EventMaskType mask;
        StatusType retVal;
        } Os_ClearEvent;

    struct GetEvent{
        TaskType taskId;
        EventMaskRefType mask;
        StatusType retVal;
        } Os_GetEvent;

    struct SetEvent{
        TaskType taskId;
        EventMaskType mask;
        StatusType retVal;
        } Os_SetEvent;

    struct WaitEvent{
        EventMaskType mask;
        StatusType retVal;
        } Os_WaitEvent;

    struct GetISRID{
        ISRType retVal;
        } Os_GetISRID;

    struct GetResource{
        ResourceType resId;
        StatusType retVal;
        } Os_GetResource;

    struct ReleaseResource{
        ResourceType resId;
        StatusType retVal;
        } Os_ReleaseResource;

    struct GetSpinlock{
        SpinlockIdType spinlockId;
        StatusType retVal;
        } Os_GetSpinlock;

    struct ReleaseSpinlock{
        SpinlockIdType spinlockId;
        StatusType retVal;
        } Os_ReleaseSpinlock;

    struct TryToGetSpinlock{
        SpinlockIdType spinlockId;
        TryToGetSpinlockType* success;
        StatusType retVal;
        } Os_TryToGetSpinlock;

    struct IocWrite{
        const Os_IocCfgType* iocCfg;
        uint32 senderId;
        const void*const* data;
        StatusType retVal;
        } Os_IocWrite;

   struct IocRead{
        const Os_IocCfgType* iocCfg;
        const void*const* data;
        StatusType retVal;
        } Os_IocRead;

   struct IocSend{
        const Os_IocCfgType* iocCfg;
        uint32 senderId;
        const void*const* data;
        StatusType retVal;
        } Os_IocSend;

   struct IocReceive{
        const Os_IocCfgType* iocCfg;
        const void*const* data;
        StatusType retVal;
        } Os_IocReceive;

    struct IocEmptyQueue{
        const Os_IocCfgType* iocCfg;
        StatusType retVal;
        } Os_IocEmptyQueue;

#if( OS_CFG_TRUSTFUN == STD_ON )
    struct CallTrustedFunction{
        TrustedFunctionIndexType functionIndex;
        TrustedFunctionParameterRefType functionParams;
        StatusType retVal;
        } Os_CallTrustedFunction;
#endif
    struct StartScheduleTableRel{
        ScheduleTableType scheduleTableID;
        TickType offset;
        StatusType retVal;
        } Os_StartScheduleTableRel;

    struct StartScheduleTableAbs{
        ScheduleTableType scheduleTableID;
        TickType start;
        StatusType retVal;
        } Os_StartScheduleTableAbs;

    struct StopScheduleTable{
        ScheduleTableType scheduleTableID;
        StatusType retVal;
        } Os_StopScheduleTable;

    struct NextScheduleTable{
        ScheduleTableType scheduleTableID_From;
        ScheduleTableType scheduleTableID_To;
        StatusType retVal;
        } Os_NextScheduleTable;

    struct StartScheduleTableSynchron{
        ScheduleTableType scheduleTableID;
        StatusType retVal;
        } Os_StartScheduleTableSynchron;

    struct SyncScheduleTable{
        ScheduleTableType scheduleTableID;
        TickType value;
        StatusType retVal;
        } Os_SyncScheduleTable;

    struct SetScheduleTableAsync{
        ScheduleTableType scheduleTableID;
        StatusType retVal;
        } Os_SetScheduleTableAsync;

    struct GetScheduleTableStatus{
        ScheduleTableType scheduleTableID;
        TickType value;
        StatusType retVal;
        ScheduleTableStatusRefType scheduleStatus;
        } Os_GetScheduleTableStatus;

    struct GetTaskStackUsage{
        TaskType taskId;
        Os_Stack_Size* taskUsage;
        StatusType retVal;
        } Os_GetTaskStackUsage;

    struct GetISRStackUsage{
        ISRType isrId;
        Os_Stack_Size* isrUsage;
        StatusType retVal;
        } Os_GetISRStackUsage;

    struct EnableInterruptSource{
        ISRType isrId;
        boolean clearPending;
        StatusType retVal;
        } Os_EnableInterruptSource;

    struct DisableInterruptSource{
        ISRType isrId;
        StatusType retVal;
        } Os_DisableInterruptSource;

    struct ControlIdle{
        CoreIdType coreID;
        IdleModeType idleMode;
        StatusType retVal;
        } Os_ControlIdle;
} Os_SysCallParamType;

typedef struct{
    Os_Syscall_FuncId funcId;
    Os_IntLevelType level;
    Os_SysCallParamType* Os_SysCallParam;
} Os_SysCallType;

typedef void (*Os_SysCall_Func)(Os_SysCallParamType* parameter);

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

#endif /* _OS_SYSCALL_TYPES_H_ */


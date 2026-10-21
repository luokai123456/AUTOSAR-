/*
********************************************************************************
*
*  File name: Os.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.16
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2022.11.21
* Change: Change OS_VAR_NOINIT to OS_VAR_NO_INIT.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.2.14
* Change: Notes optimization.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.2.15
* Change: Add macro switch.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.4.3
* Change: Remove the Cpload file.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2023.4.4
* Change: Adapt to ORTI.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: LiG/2023.4.6
* Change: Modify version number.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: LiG/2023.5.5
* Change: Modify version number.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: LiuJJ/2023.5.15
* Change: Modify version number.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: LiG/2023.5.19
* Change: Modify version number.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: LiG/2023.5.27
* Change: Modify version number.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: LiG/2023.6.9
* Change: Modify version number.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: LiG/2023.8.18
* Change: Modify version number.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: LiG/2023.10.3
* Change: Add the relevant functions of the EnableInterruptSource
*         DisableInterruptSource interface and IdleControl interface.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: LiG/2023.10.24
* Change: Modifying coding specifications and upgrading version numbers.
* Cause: Bugfix
********************************************************************************
* Version: 3.16
* Author/Date: LiG/2024.1.11
* Change: Modify version number.
* Cause: Bugfix
********************************************************************************
* Version: 3.17
* Author/Date: LiG/2024.2.20
* Change: Modify version number.
* Cause: Bugfix
********************************************************************************
* Version: 3.18
* Author/Date: LiG/2024.4.10
* Change: Modifying static code check issues.
* Cause: Optimization
********************************************************************************
* Version: 3.19
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date: LiG/2024.5.6
* Change: Modify version number.
* Cause: Bugfix
********************************************************************************
* Version: 3.19
* Author/Date: LiG/2024.5.23
* Change: Modify version number.
* Cause: Bugfix
********************************************************************************
* Version: 3.20
* Author/Date: LiG/2024.6.3
* Change: Modify version number.
* Cause: Bugfix
********************************************************************************
* Version: 3.21
* Author/Date: LiG/2024.6.6
* Change: Modify version number.
* Cause: Bugfix
********************************************************************************
* Version: 3.22
* Author/Date: ZhangY/2024.6.13
* Change: Modify version number.
* Cause: Bugfix
********************************************************************************
* Version: 3.23
* Author/Date: LiG/2024.10.11
* Change: Modify version number.
* Cause: Bugfix
********************************************************************************
* Version: 3.24
* Author/Date: LiG/2024.10.17
* Change: Modify version number.
* Cause: Bugfix
********************************************************************************
* Version: 3.25
* Author/Date: ZhangY/2024.11.20
* Change: Modify version number.
* Cause: Bugfix
********************************************************************************
* Version: 3.26
* Author/Date: LiG/2025.01.02
* Change: Add multi-core synchronization interface and Modify version number.
* Cause: Update
********************************************************************************
* Version: 3.27
* Author/Date: LiuZB/2025.02.20
* Change: Optimize space size.
* Cause: Update
********************************************************************************
* Version: 3.28
* Author/Date: LiuZB/2025.02.26
* Change: Fit for stack of cat1 isr.
* Cause: Update
********************************************************************************
*/
#ifndef OS_H_
#define OS_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Cfg.h"
#include "Os_Types_Cfg.h"
#include "Os_Types.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Lcfg.h"
#include "Os_Monitor.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Vendor and module identification */
#define OS_VENDOR_ID                            (119U)
#define OS_MODULE_ID                            (1U)

/* Component version information */
#define OS_SW_MAJOR_VERSION                     (3U)
#define OS_SW_MINOR_VERSION                     (7U)
#define OS_SW_PATCH_VERSION                     (6U)
#define OS_SW_REVISION_VERSION                  (23U)

/* Autosar version information */
#define OS_AR_RELEASE_MAJOR_VERSION             (4U)
#define OS_AR_RELEASE_MINOR_VERSION             (2U)
#define OS_AR_RELEASE_REVISION_VERSION          (2U)
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
extern FUNC(void, OS_CODE) Os_Init(void);
extern FUNC(void, OS_CODE) StartOS(AppModeType Mode);
extern FUNC(void, OS_CODE) StartCore
(
    CoreIdType CoreID,
    P2VAR(StatusType, AUTOMATIC, OS_APPL_DATA) Status
);
extern FUNC(void, OS_CODE) ShutdownOS(StatusType Error);
extern FUNC(StatusType, OS_CODE) GetAlarm(AlarmType AlarmID, TickRefType Tick);
extern FUNC(StatusType, OS_CODE) SetRelAlarm
(
    AlarmType AlarmID,
    TickType Increment,
    TickType Cycle
);
extern FUNC(StatusType, OS_CODE) SetAbsAlarm
(
    AlarmType AlarmID,
    TickType Start,
    TickType Cycle
);
extern FUNC(StatusType, OS_CODE) CancelAlarm(AlarmType AlarmID);
extern FUNC(StatusType, OS_CODE) GetAlarmBase
(
    AlarmType AlarmID,
    AlarmBaseRefType Info
);
extern FUNC(StatusType, OS_CODE) IncrementCounter(CounterType CounterID);
extern FUNC(StatusType, OS_CODE) GetCounterValue
(
    CounterType CounterID,
    TickRefType Value
);
extern FUNC(StatusType, OS_CODE) GetElapsedValue
(
    CounterType CounterID,
    TickRefType Value,
    TickRefType ElapsedValue
);
extern FUNC(ISRType, OS_CODE) GetISRID(void);
extern FUNC(CoreIdType, OS_CODE) GetCoreID(void);
extern FUNC(void, OS_CODE) StartNonAutosarCore
(
    CoreIdType CoreID,
    P2CONST(StatusType, AUTOMATIC, OS_APPL_CONST) Status
);
extern FUNC(StatusType, OS_CODE) DisableInterruptSource
(
    ISRType isrId
);
extern FUNC(StatusType, OS_CODE) EnableInterruptSource
(
    ISRType isrId,
    boolean clearPending
);
extern FUNC(StatusType, OS_CODE) ClearPendingInterrupt(ISRType ISRID);
extern FUNC(void, OS_CODE) DisableAllInterrupts(void);
extern FUNC(void, OS_CODE) EnableAllInterrupts(void);
extern FUNC(void, OS_CODE) SuspendAllInterrupts(void);
extern FUNC(void, OS_CODE) ResumeAllInterrupts(void);
extern FUNC(void, OS_CODE) SuspendOSInterrupts(void);
extern FUNC(void, OS_CODE) ResumeOSInterrupts(void);
extern FUNC(StatusType, OS_CODE) ActivateTask(TaskType TaskID);
extern FUNC(StatusType, OS_CODE) TerminateTask(void);
extern FUNC(StatusType, OS_CODE) ChainTask(TaskType TaskID);
extern FUNC(StatusType, OS_CODE) Schedule(void);
extern FUNC(StatusType, OS_CODE) GetTaskID(TaskRefType TaskID);
extern FUNC(StatusType, OS_CODE) GetTaskState
(
    TaskType TaskID,
    TaskStateRefType State
);
#if(  OS_CFG_EVENT_ENABLE == STD_ON  )
extern FUNC(StatusType, OS_CODE) SetEvent(TaskType TaskID, EventMaskType Mask);
extern FUNC(StatusType, OS_CODE) ClearEvent(EventMaskType Mask);
extern FUNC(StatusType, OS_CODE) GetEvent(TaskType TaskID, EventMaskRefType Mask);
extern FUNC(StatusType, OS_CODE) WaitEvent(EventMaskType Mask);
#endif /* OS_CFG_EVENT_ENABLE == STD_ON */
#if( OS_CFG_RESOURCE_ENABLE == STD_ON )
extern FUNC(StatusType, OS_CODE) GetResource(ResourceType ResID);
extern FUNC(StatusType, OS_CODE) ReleaseResource(ResourceType ResID);
#endif /* OS_CFG_RESOURCE_ENABLE == STD_ON */
#if( OS_CFG_SPINLOCK_ENABLE == STD_ON )
extern FUNC(StatusType, OS_CODE) GetSpinlock(SpinlockIdType SpinlockId);
extern FUNC(StatusType, OS_CODE) ReleaseSpinlock(SpinlockIdType SpinlockId);
extern FUNC(StatusType, OS_CODE) TryToGetSpinlock
(
    SpinlockIdType SpinlockId,
    P2VAR(TryToGetSpinlockType, AUTOMATIC, OS_APPL_DATA) Success
);
#endif /* OS_CFG_SPINLOCK_ENABLE == STD_ON */

extern FUNC(void, OS_CODE) ShutdownAllCores(StatusType Error);
extern FUNC(StatusType, OS_CODE) CallTrustedFunction
(
    TrustedFunctionIndexType FunctionIndex,
    TrustedFunctionParameterRefType FunctionParams
);
#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
extern FUNC(StatusType, OS_CODE) StartScheduleTableRel
(
    ScheduleTableType ScheduleTableID,
    TickType Offset
);
extern FUNC(StatusType, OS_CODE) StartScheduleTableAbs
(
    ScheduleTableType ScheduleTableID,
    TickType Start
);

#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
extern FUNC(StatusType, OS_CODE) StartScheduleTableSynchron
(
    ScheduleTableType ScheduleTableID
);
extern FUNC(StatusType, OS_CODE) SyncScheduleTable
(
    ScheduleTableType ScheduleTableID,
    TickType Value
);
extern FUNC(StatusType, OS_CODE) SetScheduleTableAsync
(
    ScheduleTableType ScheduleTableID
);
#endif /* ( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) ) */
extern FUNC(StatusType, OS_CODE) GetScheduleTableStatus
(
    ScheduleTableType ScheduleTableID,
    ScheduleTableStatusRefType ScheduleStatus
);
extern FUNC(StatusType, OS_CODE) NextScheduleTable
(
    ScheduleTableType ScheduleTableID_From,
    ScheduleTableType ScheduleTableID_To
);
extern FUNC(StatusType, OS_CODE) StopScheduleTable
(
    ScheduleTableType ScheduleTableID
);
#endif /* OS_CFG_SCHDTB_ENABLE == STD_ON */
extern FUNC(StatusType, OS_CODE) TerminateApplication
(
    ApplicationType Application,
    RestartType RestartOption
);
extern FUNC(ApplicationType, OS_CODE) GetApplicationID(void);
extern FUNC(ApplicationType, OS_CODE) GetCurrentApplicationID(void);
extern FUNC(StatusType, OS_CODE) GetApplicationState
(
    ApplicationType Application,
    ApplicationStateRefType Value
);
extern FUNC(StatusType, OS_CODE) AllowAccess(void);
extern FUNC(uint32, OS_CODE) GetTaskStackUsage(TaskType TaskID);
extern FUNC(uint32, OS_CODE) GetISRStackUsage(ISRType IsrID);
#if (OS_IDLEMODE_ENABLE == STD_ON)
extern FUNC(StatusType, OS_CODE) ControlIdle
(
    CoreIdType CoreID,
    IdleModeType IdleMode
);
#endif
#if( OS_MONITOR_ENABLE == STD_ON )
extern FUNC(void, OS_CODE) MonitorInit(void);
extern FUNC(void, OS_CODE) MonitorMainFunction(void);
#endif /* OS_MONITOR_ENABLE == STD_ON */
#if( OS_CFG_MULTI_CORE == STD_ON )
extern FUNC(void, OS_CODE) Os_Core_Sync(uint8 syncCounter);
#endif /* OS_CFG_MULTI_CORE == STD_ON */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_H_ */

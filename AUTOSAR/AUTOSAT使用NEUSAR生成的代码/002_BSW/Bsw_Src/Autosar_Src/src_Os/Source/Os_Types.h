/*
********************************************************************************
*
*  File name: Os_Types.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.23
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: JiangGL/2021.12.25
* Change: Fix the problem that may cause overflow during time conversion.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.10.3
* Change: Add the relevant macro of the EnableInterruptSource
*         DisableInterruptSource and ControlIdle interface.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2023.10.7
* Change: Add mode enumeration for ControlIdle.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.3.15
* Change: Modify multicore service timeout error macro.
* Cause: Update
********************************************************************************
*/
#ifndef OS_TYPES_H_
#define OS_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types_Cfg.h"
#include "Os_Arch_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define OS_RESOURCE_TYPE_MASK           (0x1000U) /* ProcType is resource mask. */
#define OS_SPINLOCK_TYPE_MASK           (0x800U)  /* ProcType is spinlock mask. */
#define OS_SYS_TYPE_MASK                (0x400U)  /* ProcType is system app mask. */
#define OS_TASK_TYPE_MASK               (0x200U)  /* ProcType is task mask. */
#define OS_ISR_CAT1_TYPE_MASK           (0x100U)  /* ProcType is cat1 isr mask. */
#define OS_ISR_CAT2_TYPE_MASK           (0x080U)  /* ProcType is cat2 isr mask. */
#define OS_ERRHOOK_TYPE_MASK            (0x040U)  /* ProcType is error hook mask. */
#define OS_PRETASKHOOK_TYPE_MASK        (0x020U)  /* ProcType is pretask hook mask. */
#define OS_POSTTASKHOOK_TYPE_MASK       (0x010U)  /* ProcType is posttask hook mask. */
#define OS_STARTUPHOOK_TYPE_MASK        (0x008U)  /* ProcType is startup hook mask. */
#define OS_SHUTDOWNHOOK_TYPE_MASK       (0x004U)  /* ProcType is shutdown hook mask. */
#define OS_ALARM_TYPE_MASK              (0x002U)  /* ProcType is alarm mask. */
#define OS_PROTECTHOOK_TYPE_MASK        (0x001U)  /* ProcType is protection hook mask. */

/* ActivateTask service valid calling context access. */
#define OS_ACTIVETASK_ACCESS            (0x280U)
/* TerminateTask service valid calling context access. */
#define OS_TERMINATETASK_ACCESS         (0x200U)
/* ChainTask service valid calling context access. */
#define OS_CHAINTASK_ACCESS             (0x200U)
/* GetTaskID service valid calling context access. */
#define OS_GETTASKID_ACCESS             (0x2F1U)
/* GetTaskState service valid calling context access. */
#define OS_GETTASKSTATE_ACCESS          (0x2F0U)
/* DisableAllInterrupts service valid calling context access. */
#define OS_DISABLEALL_ACCESS            (0x3FFU)
/* EnableAllInterrupts service valid calling context access. */
#define OS_ENABLEALL_ACCESS             (0x3FFU)
/* SuspendAllInterrupts service valid calling context access. */
#define OS_SUSPENDALL_ACCESS            (0x3FFU)
/* ResumeAllInterrupts service valid calling context access. */
#define OS_RESUMEALL_ACCESS             (0x3FFU)
/* SuspendOSInterrupts service valid calling context access. */
#define OS_SUSPENDOSALL_ACCESS          (0x3FFU)
/* ResumeOSInterrupts service valid calling context access. */
#define OS_RESUMEOSALL_ACCESS           (0x3FFU)
/* GetResource service valid calling context access. */
#define OS_GETRESOURCE_ACCESS           (0x280U)
/* ReleaseResource service valid calling context access. */
#define OS_RELEASERESOURCE_ACCESS       (0x280U)
/* SetEvent service valid calling context access. */
#define OS_SETEVENT_ACCESS              (0x280U)
/* ClearEvent service valid calling context access. */
#define OS_CLEAREVENT_ACCESS            (0x200U)
/* GetEvent service valid calling context access. */
#define OS_GETEVENT_ACCESS              (0x2F0U)
/* WaitEvent service valid calling context access. */
#define OS_WAITEVENT_ACCESS             (0x200U)
/* GetAlarmBase service valid calling context access. */
#define OS_GETALARMBASE_ACCESS          (0x2F0U)
/* GetAlarm service valid calling context access. */
#define OS_GETALARM_ACCESS              (0x2F0U)
/* SetRelAlarm service valid calling context access. */
#define OS_SETRELALARM_ACCESS           (0x280U)
/* SetAbsAlarm service valid calling context access. */
#define OS_SETABSALARM_ACCESS           (0x280U)
/* CancelAlarm service valid calling context access. */
#define OS_CANCELALARM_ACCESS           (0x280U)
/* GetActiveApplicationMode service valid calling context access. */
#define OS_GETACTIVEAPPMODE_ACCESS      (0x2FCU)
/* ShutdownOS service valid calling context access. */
#define OS_SHUTDOWNOS_ACCESS            (0x2C8U)
/* ShutdownAllCores service valid calling context access. */
#define OS_SHUTDOWNALLCORES_ACCESS      (0x2C8U)
/* GetApplicationID service valid calling context access. */
#define OS_GETAPPID_ACCESS              (0x2FDU)
/* AllowAccess service valid calling context access. */
#define OS_ALLOWACCESS_ACCESS           (0x280U)
/* GetISRID service valid calling context access. */
#define OS_GETISRID_ACCESS              (0x2C0U)
/* StartCore service valid calling context access. */
#define OS_STARTCORE_ACCESS             (0x400U)
/* StartScheduleTableRel service valid calling context access. */
#define OS_STARTRELSCHTB_ACCESS         (0x280U)
/* StartScheduleTableAbs service valid calling context access. */
#define OS_STARTABSSCHTB_ACCESS         (0x280U)
/* StopScheduleTable service valid calling context access. */
#define OS_STOPSCHTB_ACCESS             (0x280U)
/* NextScheduleTable service valid calling context access. */
#define OS_NEXTSCHTB_ACCESS             (0x280U)
/* StartScheduleTableSynchron service valid calling context access. */
#define OS_STARTSCHTBSYN_ACCESS         (0x280U)
/* SyncScheduleTable service valid calling context access. */
#define OS_SYNSCHTB_ACCESS              (0x280U)
/* GetScheduleTableStatus service valid calling context access. */
#define OS_GETSCHTBSTATUS_ACCESS        (0x280U)
/* SetScheduleTableAsync service valid calling context access. */
#define OS_SETSCHTBASYN_ACCESS          (0x280U)
/* IncrementCounter service valid calling context access. */
#define OS_INCREMENTCNT_ACCESS          (0x280U)
/* GetCounterValue service valid calling context access. */
#define OS_GETCNTVALUE_ACCESS           (0x280U)
/* GetElapsedValue service valid calling context access. */
#define OS_GETELAPSEDVALUE_ACCESS       (0x280U)
/* TerminateApplication service valid calling context access. */
#define OS_TERMINATEAPP_ACCESS          (0x6C1U)
/* GetApplicationState service valid calling context access. */
#define OS_GETAPPSTATE_ACCESS           (0x2FDU)
/* GetCurrentApplicationID service valid calling context access. */
#define OS_GETCURRENTAPPID_ACCESS       (0x2FDU)
/* GetSpinlock service valid calling context access. */
#define OS_GETSPINLOCK_ACCESS           (0x280U)
/* Release Spinlock service valid calling context access. */
#define OS_RELEASESPINLOCK_ACCESS       (0x280U)
/* TryToGetSpinlock service valid calling context access. */
#define OS_TRYTOGETSPINLOCK_ACCESS      (0x280U)
/* CallTrustedFunction service valid calling context access. */
#define OS_CALLTRUSTEDFUNCTION_ACCESS   (0x280U)
/* ControlIdle service valid calling context access. */
#define OS_CONTROLIDLE_ACCESS           (0x280U)
/* EnableInterruptSource and DisableInterruptSource
 service valid calling context access. */
#define OS_INTERRUPTSOURCE_ACCESS       (0x280U)

/* ----- OSEK ----- (Values are defined) */
#define E_OS_OK                         ((StatusType)0x0U)
/* Illegal access. */
#define E_OS_ACCESS                     ((StatusType)0x01U)
/* Invalid calling context. */
#define E_OS_CALLEVEL                   ((StatusType)0x02U)
/* Invalid OS object Id. */
#define E_OS_ID                         ((StatusType)0x03U)
/* Maximum task activations reached. */
#define E_OS_LIMIT                      ((StatusType)0x04U)
/* OS object is currently not in use. */
#define E_OS_NOFUNC                     ((StatusType)0x05U)
/* Scheduling requested with occupied resource. */
#define E_OS_RESOURCE                   ((StatusType)0x06U)
/* OS object is not in correct state to perform the requested operation. */
#define E_OS_STATE                      ((StatusType)0x07U)
/* Given value is out of the configured range. */
#define E_OS_VALUE                      ((StatusType)0x08U)

/* ----- AUTOSAR OS ----- */
/* Service can not be called. */
#define E_OS_SERVICEID                  ((StatusType)0x09U)
/* An invalid address is given as a parameter to a service. */
#define E_OS_ILLEGAL_ADDRESS            ((StatusType)0x0AU)
/* Tasks terminates without a TerminateTask() or ChainTask() call. */
#define E_OS_MISSINGEND                 ((StatusType)0x0BU)
/* A service of the OS is called inside an interrupt disable/enable pair. */
#define E_OS_DISABLEDINT                ((StatusType)0x0CU)
/* A stack fault detected via stack monitoring by the OS. */
#define E_OS_STACKFAULT                 ((StatusType)0x0DU)
/* A memory access violation occurred. */
#define E_OS_PROTECTION_MEMORY          ((StatusType)0x0EU)
/* A Task/ISR2 exceeds its execution time budget. */
#define E_OS_PROTECTION_TIME            ((StatusType)0x0FU)
/* A Task/ISR2 arrives before its timeframe has expired. */
#define E_OS_PROTECTION_ARRIVAL         ((StatusType)0x10U)
/* A Task/Category 2 ISR blocks for too long. */
#define E_OS_PROTECTION_LOCKED          ((StatusType)0x11U)
/* A trap occurred. */
#define E_OS_PROTECTION_EXCEPTION       ((StatusType)0x12U)
/* Deadlock situation due to interference. */
#define E_OS_INTERFERENCE_DEADLOCK      ((StatusType)0x13U)
/* Potential deadlock due to wrong nesting. */
#define E_OS_NESTING_DEADLOCK           ((StatusType)0x14U)
/* De-scheduling with occupied spinlock. */
#define E_OS_SPINLOCK                   ((StatusType)0x15U)
/* Core is not available. */
#define E_OS_CORE                       ((StatusType)0x16U)
/* A null pointer was given as argument. */
#define E_OS_PARAM_POINTER              ((StatusType)0x17U)
/* A buffer has no data. */
#define E_OS_NODATA                     ((StatusType)0x18U)
/* A buffer is full. */
#define E_OS_BUFFFULL                   ((StatusType)0x19U)
/* A buffer is empty. */
#define E_OS_BUFFEMPTY                  ((StatusType)0x1AU)
/* A resource is locked. */
#define E_OS_RESOURCE_LOCKED            ((StatusType)0x1BU)
/* A error priority. */
#define E_OS_PRIORITY                   ((StatusType)0x1CU)
/* API wrong call. */
#define E_OS_CALL_ERROR                 ((StatusType)0x1DU)

/* This API call is performed on another core with no acknowledgment (yet). */
#define E_OS_TIMEOUT                    ((StatusType)0xFFU)

#define OS_INTERUPT_NOT_DISABLEALL      (0U)
#define OS_INTERUPT_DISABLEALL          (1U)
#define OS_SUPENDINTERRUPTCNT           (255U)
#define OS_ZERO_VALUE                   (0U)
#define OS_NOT_ZERO_VALUE               (!0U)
#define OS_ONE_VALUE                    (1U)
#define OS_TWO_VALUE                    (2U)
#define OS_MEMORY_INVALID               (0U)
#define OS_COUNTER_INVALID              (10U)

#define OS_SC1                          (1U)
#define OS_SC2                          (2U)
#define OS_SC3                          (3U)
#define OS_SC4                          (4U)

#ifndef OS_ISR
#define OS_ISR(name)                    void (name)(void)
#endif

#ifndef ISR
#define ISR(name)                       void (name)(void)
#endif

#ifndef TASK
#define TASK(name)                      void Os_Task_##name(void)
#endif

/* Dummy function. */
#ifndef OS_DUMMY_STATEMENT
#define OS_DUMMY_STATEMENT(v)           (v)=(v)
#endif

#define OS_IGNORE_PARAM(param)          ((void)(param))

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* The os status. */
typedef uint8 Os_StatusType;
/* This data type represents an application mode. */
typedef uint8  AppModeType;
/* Index type to iterate over OS objects during initialization. */
typedef uint16 Os_ObjIdxType;
/* Data type to measure time. */
typedef uint32 Os_TickType;
/* Data type to task priority. */
typedef uint16 Os_TaskPrioType;
/* Data type to task max activation number. */
typedef uint16 Os_ActivationCntType;
/* Data type to processor indexes. */
typedef uint32 Os_ProcIdType;
/* A set of events. */
typedef uint64 EventMaskType;
typedef EventMaskType* EventMaskRefType;
/* param error check type.*/
typedef unsigned int Os_ErrorCheckType;
/* Pointer to task identifier. */
typedef TaskType* TaskRefType;
/* Pointer to os tick */
typedef Os_TickType* TickRefType;
/* This data type represents count values in ticks. */
typedef Os_TickType TickType;
/* Data type to caller identifier. */
typedef uint32 OsCallerId;
/* Error processor type. */
typedef uint16 OsErrorProct;
/* Sync types. */
typedef uint8 Os_SyncType;
/* Proc types. */
typedef uint16 Os_ProcType;
/* Data type to measure physical time. */
typedef float64 PhysicalTimeType;

typedef enum
{
    /* The CPU is assigned to the task. */
    RUNNING,
    /* The task is ready for a transition into the RUNNING state, but waits for allocation of the processor. */
    READY,
    /* The task cannot continue execution because it waits for at least one event. */
    WAITING,
    /* The task is passive and can be activated. */
    SUSPENDED
} TaskStateType;

/* Pointer to task scheduling state. */
typedef TaskStateType* TaskStateRefType;

/* This data type identifies the state of an OS-Application. */
typedef enum
{
    APPLICATION_TERMINATED = 0U, /* The application is terminated and inaccessible. */
    APPLICATION_RESTARTING,     /* The application is in the restart phase and inaccessible. */
    APPLICATION_ACCESSIBLE      /* The application is active and accessible. */
} ApplicationStateType;

/* This data type points to location where a ApplicationStateType can be stored. */
typedef ApplicationStateType* ApplicationStateRefType;

typedef struct
{
    /* Maximum possible allowed count value (for example in ticks or angle degrees). */
    Os_TickType maxallowedvalue;
    /* Number of ticks required to reach a counter-specific (significant) unit. */
    Os_TickType ticksperbase;
    /* Minimum allowed number of ticks for a cyclic alarm (only for systems with Extended Status). */
    Os_TickType mincycle;
} AlarmBaseType;

/* This data type points to the data type TickType. */
typedef AlarmBaseType* AlarmBaseRefType;

/* The core identifier type. */
typedef enum
{
    IDLE_NO_HALT = 0U, /* The core does not perform any specific actions during idle time. */
    IDLE_HALT = 1U,
    OS_IDLEMODE_COUNT = 2U
} IdleModeType;

/* Defines the use of a Restart Task after terminating an OS-Application. */
typedef enum
{
    RESTART,              /* OS-Application shall be restarted. */
    NO_RESTART,           /* OS-Application shall not be restarted. */
} RestartType;

/* This data type points to a structure which holds the arguments for a call to a trusted function. */
typedef void* TrustedFunctionParameterRefType;

/* Indicates if the spinlock has been occupied or not. */
typedef enum
{
    TRYTOGETSPINLOCK_SUCCESS,   /* Spinlock successfully occupied. */
    TRYTOGETSPINLOCK_NOSUCCESS  /* Unable to occupy the spinlock. */
} TryToGetSpinlockType;

/* Represents the identification of OS services. */
typedef enum
{
    /* ---- AUTOSAR OS ----- */
    OSServiceId_GetApplicationID            = 0x00U,  /* GetApplicationID() */
    OSServiceId_GetISRID                    = 0x01U,  /* GetISRID() */
    OSServiceId_CallTrustedFunction         = 0x02U,  /* CallTrustedFunction() */
    OSServiceId_CheckISRMemoryAccess        = 0x03U,  /* CheckISRMemoryAccess() */
    OSServiceId_CheckTaskMemoryAccess       = 0x04U,  /* CheckTaskMemoryAccess() */
    OSServiceId_CheckObjectAccess           = 0x05U,  /* CheckObjectAccess() */
    OSServiceId_CheckObjectOwnership        = 0x06U,  /* CheckObjectOwnership() */
    OSServiceId_StartScheduleTableRel       = 0x07U,  /* StartScheduleTableRel() */
    OSServiceId_StartScheduleTableAbs       = 0x08U,  /* StartScheduleTableAbs() */
    OSServiceId_StopScheduleTable           = 0x09U,  /* StopScheduleTable() */
    OSServiceId_NextScheduleTable           = 0x0aU,  /* NextScheduleTable() */
    OSServiceId_StartScheduleTableSynchron  = 0x0bU,  /* StartScheduleTableSynchron() */
    OSServiceId_SyncScheduleTable           = 0x0cU,  /* SyncScheduleTable() */
    OSServiceId_SetScheduleTableAsync       = 0x0dU,  /* SetScheduleTableAsync() */
    OSServiceId_GetScheduleTableStatus      = 0x0eU,  /* GetScheduleTableStatus() */
    OSServiceId_IncrementCounter            = 0x0fU,  /* IncrementCounter() */
    OSServiceId_GetCounterValue             = 0x10U,  /* GetCounterValue() */
    OSServiceId_GetElapsedValue             = 0x11U,  /* GetElapsedValue() */
    OSServiceId_TerminateApplication        = 0x12U,  /* TerminateApplication() */
    OSServiceId_AllowAccess                 = 0x13U,  /* AllowAccess() */
    OSServiceId_GetApplicationState         = 0x14U,  /* GetApplicationState() */
    OSServiceId_GetNumberOfActivatedCores   = 0x15U,  /* GetNumberOfActivatedCores() */
    OSServiceId_GetCoreID                   = 0x16U,  /* GetCoreID() */
    OSServiceId_StartCore                   = 0x17U,  /* StartCore() */
    OSServiceId_StartNonAutosarCore         = 0x18U,  /* StartNonAutosarCore() */
    OSServiceId_GetSpinlock                 = 0x19U,  /* GetSpinlock() */
    OSServiceId_ReleaseSpinlock             = 0x1aU,  /* ReleaseSpinlock() */
    OSServiceId_TryToGetSpinlock            = 0x1bU,  /* TryToGetSpinlock() */
    OSServiceId_ShutdownAllCores            = 0x1cU,  /* ShutdownAllCores() */
    OSServiceId_ControlIdle                 = 0x1dU,  /* ControlIdle() */
    OSServiceId_IocSend                     = 0x1eU,  /* IocSend() */
    OSServiceId_IocWrite                    = 0x1fU,  /* IocWrite() */
    OSServiceId_IocSendGroup                = 0x20U,  /* IocSendGroup() */
    OSServiceId_IocWriteGroup               = 0x21U,  /* IocWriteGroup() */
    OSServiceId_IocReceive                  = 0x22U,  /* IocReceive() */
    OSServiceId_IocRead                     = 0x23U,  /* IocRead() */
    OSServiceId_IocReceiveGroup             = 0x24U,  /* IocReceiveGroup() */
    OSServiceId_IocReadGroup                = 0x25U,  /* IocReadGroup() */
    OSServiceId_IocEmptyQueue               = 0x26U,  /* IocEmptyQueue() */
    OSServiceId_GetCurrentApplicationID     = 0x27U,  /* GetCurrentApplicationID() */
    OSServiceId_DisableInterruptSource      = 0x30U,  /* DisableInterruptSource() */
    OSServiceId_EnableInterruptSource       = 0x31U,  /* EnableInterruptSource() */

    /* ----- OSEK ----- */
    OSServiceId_StartOS                     = 0xA0U,  /* StartOS() */
    OSServiceId_GetActiveApplicationMode    = 0xA1U,  /* GetActiveApplicationMode() */
    OSServiceId_DisableAllInterrupts        = 0xA2U,  /* DisableAllInterrupts() */
    OSServiceId_EnableAllInterrupts         = 0xA3U,  /* EnableAllInterrupts() */
    OSServiceId_SuspendAllInterrupts        = 0xA4U,  /* SuspendAllInterrupts() */
    OSServiceId_ResumeAllInterrupts         = 0xA5U,  /* ResumeAllInterrupts() */
    OSServiceId_SuspendOSInterrupts         = 0xA6U,  /* SuspendOSInterrupts() */
    OSServiceId_ResumeOSInterrupts          = 0xA7U,  /* ResumeOSInterrupts() */
    OSServiceId_ActivateTask                = 0xA8U,  /* ActivateTask() */
    OSServiceId_TerminateTask               = 0xA9U,  /* TerminateTask() */
    OSServiceId_ChainTask                   = 0xAAU,  /* ChainTask() */
    OSServiceId_GetTaskID                   = 0xABU,  /* GetTaskID() */
    OSServiceId_GetTaskState                = 0xACU,  /* GetTaskState() */
    OSServiceId_Schedule                    = 0xADU,  /* Schedule() */
    OSServiceId_SetEvent                    = 0xAEU,  /* SetEvent() */
    OSServiceId_ClearEvent                  = 0xB0U,  /* ClearEvent() */
    OSServiceId_GetEvent                    = 0xB1U,  /* GetEvent() */
    OSServiceId_WaitEvent                   = 0xB2U,  /* WaitEvent() */
    OSServiceId_GetAlarmBase                = 0xB3U,  /* GetAlarmBase() */
    OSServiceId_GetAlarm                    = 0xB4U,  /* GetAlarm() */
    OSServiceId_SetRelAlarm                 = 0xB5U,  /* SetRelAlarm() */
    OSServiceId_SetAbsAlarm                 = 0xB6U,  /* SetAbsAlarm() */
    OSServiceId_CancelAlarm                 = 0xB7U,  /* CancelAlarm() */
    OSServiceId_GetResource                 = 0xB8U,  /* GetResource() */
    OSServiceId_ReleaseResource             = 0xB9U,  /* ReleaseResource() */
    OSServiceId_GetElapsedCounterValue      = 0xBAU,  /* GetElapsedCounterValue() */
    OSServiceId_ShutdownOs                  = 0xBBU,  /* ShutdownOs() */
    OSServiceId_GetTaskStackUsage           = 0xBCU,  /* Os_GetTaskStackUsage() */
    OSServiceId_GetISRStackUsage            = 0xBDU,  /* Os_GetISRStackUsage() */
    OSServiceId_Os_Isr_Exit                 = 0xBEU,  /* Os_Isr_Exit() */
    OSServiceId_TaskWrongReturn             = 0xBFU,  /* TaskWrongReturn() */

    /* ----- Extensions ----- */
    OSServiceId_COUNT                     = 0xFFU
} OSServiceIdType;

typedef struct
{
    /* Error service id. */
    OSServiceIdType serviceErrorId;

    /* Error status. */
    StatusType error;

    /* Caller id. */
    OsCallerId callerId;

    /* The error occurred specific processor indexes. */
    OsErrorProct ProctId;
} Os_ErrorType;

/* This data type identifies a value which controls further actions of the OS on return from the ProtectionHook(). */
typedef enum
{
    PRO_IGNORE,                     /* The OS shall ignore the error and continue normal operation. */
    PRO_TERMINATETASKISR,           /* The OS shall forcibly terminate the faulty Task/ ISR. */
    PRO_TERMINATEAPPL,              /* The OS shall forcibly terminate the faulty OS-Application. */
    PRO_TERMINATEAPPL_RESTART,      /* The OS shall forcibly terminate the faulty OS-Application and afterwards restart
                                       the OS-Application. */
    PRO_SHUTDOWN,                   /* The OS shall shutdown the OS. */
    OS_PROTECTIONREACTION_COUNT     /* Out of range boundary value. */
} ProtectionReturnType;

typedef enum
{
    SCHEDULETABLE_STOPPED                 = 0U,
    SCHEDULETABLE_NEXT                    = 1U,
    SCHEDULETABLE_WAITING                 = 2U,
    SCHEDULETABLE_RUNNING                 = 3U,
    SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS = 4U
} ScheduleTableStatusType;

/* Reference to a schedule table status type */
typedef ScheduleTableStatusType *ScheduleTableStatusRefType;

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

#endif /* OS_TYPES_H_ */

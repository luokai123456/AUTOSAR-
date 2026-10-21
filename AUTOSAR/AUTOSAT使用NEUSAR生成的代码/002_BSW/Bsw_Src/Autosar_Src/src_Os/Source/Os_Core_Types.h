/*
********************************************************************************
*
*  File name: Os_Core_Types.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.19
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2022.11.15
* Change: coreCfg->coreDyn->context becomes array.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2022.11.15
* Change: Add memory protection related variables.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2023.9.8
* Change: Modify Structure Type.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.10.3
* Change: Add IdleControl function related member variables and coding
*         specification issues.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2023.10.8
* Change: Optimize ControlIdle function.
* Cause: Optimizing
********************************************************************************
* Version: 3.7
* Author/Date: LiG/2023.10.9
* Change: Resolve ControlIdle compilation issues.
* Cause: Optimizing
********************************************************************************
* Version: 3.8
* Author/Date: MiaoLH/2024.8.27
* Change: Removes the coreStartRequest element of the Os CoreDyn struct.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: LiuZB/2025.2.26
* Change: Fit for cat1 isr stack function.
* Cause: Update
********************************************************************************
*/
#ifndef OS_CORE_TYPES_H_
#define OS_CORE_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Cfg.h"
#include "Os_Types.h"
#include "Os_Types_Cfg.h"
#include "Os_Task_Types.h"
#include "Os_Hook_Types.h"
#include "Os_Isr_Types.h"
#include "Os_Scheduler_Types.h"
#include "Os_App_Types.h"
#include "Os_Counter_Types.h"
#include "Os_Alarm_Types.h"
#include "Os_SchdTb_Types.h"
#include "Os_Ioc_Types.h"
#include "Os_Counter_Types.h"
#include "Os_Arch_Types.h"
#include "Os_Resource_Types.h"
#include "Os_Spinlock_Types.h"
#include "Os_TmProtection_Types.h"
#include "Os_Arch_Lcfg.h"
#include "Os_MemProtection_Types.h"
#include "Os_Orti_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define OS_CORESYNC_INVALID      (0x00U)  /* States flag core sync invalid. */
#define OS_CORESYNC_VALID        (0x01U)  /* States flag core sync valid. */

#define OS_CORE_STARTINIT        (0x00U)  /* States flag core init state. */
#define OS_CORE_STARTRUN         (0x01U)  /* States flag core run state. */
#define OS_CORE_STARTSHUTDOWN    (0x02U)  /* States flag core shutdown state. */

#define OS_CORE_STARTREQINVALID  (0x00U)  /* States flag core start request invalid. */
#define OS_CORE_STARTREQVALID    (0x01U)  /* States flag core start request valid. */

#define OS_CORE_INIT             (0x00U)   /* Core initial zero value. */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef uint8 Os_CoreStartStateType;
typedef uint8 Os_CoreStartRequestType;
typedef uint8 Os_CoreSyncStateType;

typedef struct
{
    boolean disableFlag;         /* Interrupt Disable Flag. */
    uint8 suspendCnt;            /* Number of all interrupt nests. */
    uint8 suspendOsCnt;          /* Number of os interrupt nests. */
    Os_IntLevelType saveLevel;   /* All Interrupt mask level. */
    Os_IntLevelType saveOsLevel; /* OS Interrupt mask level. */
}Os_IntApiStateType;

typedef struct
{
    /* Interrupt API state. */
    Os_IntApiStateType intApiState;
    /* Counter for interrupted isr. */
    uint16 intCnts;
#if( OS_CFG_CAT1_ISR_STACK_ENABLE == STD_ON )
    /* Counter for interrupted cat1 isr. */
    uint16 cat1IntCnts;
#endif /* OS_CFG_CAT1_ISR_STACK_ENABLE == STD_ON */
    /* Buffer of interrupted isr. */
    Os_Arch_ContextDynType** intContextBuffs[OS_MAX_INTCNTS];
    Os_Arch_ContextDynType intIsrContextBuffs[OS_MAX_INTCNTS];
#if( OS_CFG_CAT1_ISR_STACK_ENABLE == STD_ON )
    Os_Arch_ContextDynType cat1IntContextBuffs[OS_MAX_CAT1INTCNTS];
#endif /* OS_CFG_CAT1_ISR_STACK_ENABLE == STD_ON */
} Os_CoreIntStateType;

struct Os_CoreDyn
{
    /* The hardware context need saved. */
    Os_Arch_ContextDynType* context;
    /* Allow schedule flag. */
    boolean allowSchedule;
    /* The core start States. */
    Os_CoreStartStateType coreStartState;
#if( OS_CFG_MULTI_CORE == STD_ON )
    /* The core sync States. */
    Os_CoreSyncStateType coreSyncState;
#endif
    /* The current processor indexes. */
    Os_ProcType currentProcType;
    /* Currently running app. */
    ApplicationType AppId;
    /* Currently running task. */
    struct Os_TaskDyn* currentTask;
    /* Currently running isr. */
    struct Os_IsrDyn*  currentIsr;
    /* Interrupt api state . */
    Os_CoreIntStateType* intState;
    Os_PreSpinlockOrderType corePreSpinOrder;
    /* The application mode in which the OS is started. */
    AppModeType coreAppMode;
    /* The core mode during idle time. */
    IdleModeType coreIdleMode;
    /* The core mode during idle time state. */
    boolean coreIdleModeState;
    /* Error Information. */
    Os_ErrorType errorInformation;
#if( (OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
    const Os_MpCfgType* appMpuCfg;
    const Os_MpCfgType* mpuCfg;
#endif
#if( OS_CFG_ORTI_ENABLE == STD_ON )
    /* Orti Information. */
    Os_Orti_CoreCfgType coreOrti;
#endif
};

struct Os_CoreCfg
{
    uint8         corePhyId;           /* The physical core Id. */
    boolean       coreIfAutoStart;
    boolean       coreIfAutoSarOs;
    boolean       coreIfMaster;
    CoreIdType    coreCoreLogicId;     /* The logical core Id. */
    uint32        coreStartAddr;       /* The start address. */
    const struct Os_TaskCfg* idleTask; /* Idle task. */
    const struct Os_TaskCfg* initTask; /* Init task. */
    /* Interrupt api state. */
    Os_CoreIntStateType* intStateCfg;
#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
    /* Core timing protection configuration. */
    const Os_TpBaseCfgType* tpBaseCfg;
#endif
#if( (OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
    /* Core memory protection configuration. */
    const Os_MpCfgType* MemoryProtection;
#endif
    /* Scheduler. */
    const Os_SchedulerCfgType* scheduler;
    /* Config context of the task. */
    const Os_Arch_ContextCfgType* contextCfg;
    /* System application. */
    const struct Os_AppCfg* systemApp;
    const struct Os_AppCfg* const* appRefs;
    Os_ObjIdxType appCnt;      /* Number of apps. */
    const struct Os_TaskCfg* const* taskRefs;
    Os_ObjIdxType taskCnt;     /* Number of tasks. */
    const struct Os_IsrCfg* const* isrRefs;
    Os_ObjIdxType isrCnt;      /* Number of cat2 ISRs. */
    const struct Os_IsrCat1Cfg* const* isrCat1Refs;
    Os_ObjIdxType isrCat1Cnt;  /* Number of cat1 ISRs. */
    const struct Os_CounterBaseCfg* const* counterRefs;
    Os_ObjIdxType counterCnt;  /* Number of counters. */
    const struct Os_AlarmCfg* const* alarmRefs;
    Os_ObjIdxType alarmCnt;  /* Number of Alarms. */
#if( OS_CFG_RESOURCE_ENABLE == STD_ON )
    const Os_ResourceCfgType* const* resourceRefs;
    Os_ObjIdxType resourceCnt;   /* Number of resources. */
#endif
#if( OS_CFG_SCHDTB_ENABLE== STD_ON )
    const Os_SchdTbCfgType* const* schTbRefs;
    Os_ObjIdxType schdTbCount;   /* Number of Schedule tables. */
#endif
#if( OS_CFG_IOC_ENABLE == STD_ON )
    const Os_IocCfgType* iocRefs;
    Os_ObjIdxType iocCnt;        /* Number of ioc. */
#endif
    /* System ProtectionHook. */
    const Os_ProtectionHookType protectionHook;
    const Os_ControlIdleHookType controlIdleHook;
    struct Os_CoreDyn* coreDyn;
    const Os_Arch_IsrSourceType* multiCommIsrSource;
};

struct Os_SystemCfg
{
    /* Number of tasks. */
    const struct Os_IsrCfg** isrRefs;
    Os_ObjIdxType isrCnt;      /* Number of system cat2 ISRs. */
    const struct Os_IsrCat1Cfg** isrCat1Refs;
    Os_ObjIdxType isrCat1Cnt;  /* Number of system cat1 ISRs. */
    const struct Os_CounterBaseCfg** counterRefs;
    Os_ObjIdxType counterCnt;  /* Number of system counters. */
};

typedef struct Os_CoreDyn    Os_CoreDynType;
typedef struct Os_CoreCfg    Os_CoreCfgType;
typedef struct Os_SystemCfg  Os_SystemCfgType;

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

#endif /* OS_CORE_TYPES_H_ */

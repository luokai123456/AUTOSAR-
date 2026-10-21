/*
********************************************************************************
*
*  File name: Os_Core.c
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
* Cause: Optimize
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2022.11.21
* Change: Change OS_VAR_NOINIT to OS_VAR_NO_INIT.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: JiangGL/2022.11.23
* Change: Fix the problem that the ending app cannot terminate the related
*         schedule table.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2022.12.14
* Change: To compile warnings.
* Cause: Optimize
********************************************************************************
* Version: 3.5
* Author/Date: YanG/2022.12.20
* Change: Clear the master kernel synchronous variable, to resolve the problem 
*         of multi-core synchronization failure caused by soft reset.
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: YanG/2022.12.20
* Change: Update the change history of the file.
* Cause: Optimize
********************************************************************************
* Version: 3.7
* Author/Date: LiG/2022.12.21
* Change: New functions ShutDownAllCore.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: YanG/2022.12.28
* Change: Hardware initializetion is moved from StartOs to Os_Init.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: BaoWl/2023.1.10
* Change: After an interrupt is forcibly occupied, it may cause an error in
          restoring the interrupt level.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: LiG/2023.1.29
* Change: Resolve the CallErrorHook privilege level problem.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: LiG/2023.1.30
* Change: Move operations that enable interrupt sources to StartOS.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: JiangGL/2023.2.24
* Change: Fix the problem of system exceptions caused by mixed nesting of 
*         (Os_Core_SuspendOSInterrupts) and (Os_Core_SuspendAllInterrupt).
* Cause: Bugfix
********************************************************************************
* Version: 3.14
* Author/Date: LiG/2023.4.4
* Change: Resolve polyspace errors.
* Cause: Bugfix
********************************************************************************
* Version: 3.15
* Author/Date: LiG/2023.4.6
* Change: Modify coding specifications.
* Cause: Bugfix
********************************************************************************
* Version: 3.16
* Author/Date: LiuJJ/2023.5.15
* Change: Solve multi-core synchronization bug.
* Cause: Bugfix
********************************************************************************
* Version: 3.17
* Author/Date: LiG/2023.5.26
* Change: Optimizing Core ID Determination in StartCore.
* Cause: Optimizing
********************************************************************************
* Version: 3.18
* Author/Date: ZhangY/2023.6.8
* Change: Modifying time protection with only one core and other cores running 
*         dead.
* Cause: Bugfix
********************************************************************************
* Version: 3.19
* Author/Date: ZhangY/2023.6.12
* Change: Modifying time protection with only one core and other cores running 
*         dead.Missing parts.
* Cause: Bugfix
********************************************************************************
* Version: 3.20
* Author/Date: LiG/2023.10.3
* Change: Added Os_Core_ControlIdle Os_Core_ControlIdleSimp function and
*         ControlIdle interface.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: LiG/2023.10.8
* Change: Optimize ControlIdle function.
* Cause: Optimizing
********************************************************************************
* Version: 3.22
* Author/Date: LiG/2023.10.8
* Change: Resolve compilation issues.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: LiG/2023.10.24
* Change: Modify the system service ID and some comments.
* Cause: Bugfix
********************************************************************************
* Version: 3.24
* Author/Date: LiG/2023.11.1
* Change: Modify the return value of the ControlIdle interface,Remove
*         Os_Core_Compilation macros in the ControlIdle interface.
* Cause: Bugfix
********************************************************************************
* Version: 3.25
* Author/Date: LiG/2023.3.15
* Change: The Os_Core_TerminationApp interface cannot close a type of interrupt.
* Cause: Bugfix
********************************************************************************
* Version: 3.26
* Author/Date: LiG/2024.4.10
* Change: Modifying static code check issues.
* Cause: Optimization
********************************************************************************
* Version: 3.27
* Author/Date: MiaoLH/2024.8.27
* Change: Modify the OS_CORE_GETCORESTARTREQ and OS_CORE_SETCORESTARTREQ macros
*         to use the nocache property variable.
* Cause: Bugfix
********************************************************************************
* Version: 3.28
* Author/Date: LiuZB/2025.2.26
* Change: Fit for cat1 isr stack function.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Cfg.h"
#include "Os_Core.h"
#include "Os_Spinlock.h"
#include "Os_Scheduler.h"
#include "Os_Isr.h"
#include "Os_Task.h"
#include "Os_Alarm.h"
#include "Os_App.h"
#include "Os_Hook.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_SysCall.h"
#include "Os_Resource.h"
#include "Os_MultiCore.h"
#include "Os_Ioc.h"
#include "Os_MemProtection.h"
#include "Os_TmProtection.h"
#include "Os_SchdTb.h"
#include "Os_Orti.h"
#include "Os.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/* Get interrupt Api processing status. */
#define OS_CORE_GETINTAPISATE(coreId)               (&(Os_CoreCfgData[coreId]->coreDyn->intState->intApiState))
/* Determine whether it is a system application id. */
#define OS_CORE_GETCORESTARTREQ(coreId)             (Os_MultiCoreStartRequest[coreId])
/* Determine whether it is a system application id. */
#define OS_CORE_SETCORESTARTREQ(coreId, startSte)   ((Os_MultiCoreStartRequest[coreId]) = (startSte))
/* Determine whether it is a system application id. */
#define OS_CORE_GETCORESTARTSTE(coreId)             (Os_CoreCfgData[coreId]->coreDyn->coreStartState)
/* Determine whether it is a system application id. */
#define OS_CORE_SETCORESTARTSTE(coreId, startSte)   (Os_CoreCfgData[coreId]->coreDyn->coreStartState = (startSte))
/* Set application mode. */
#define OS_CORE_SETAPPMODE(coreId, mode)            (Os_CoreCfgData[coreId]->coreDyn->coreAppMode = (mode))

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
LOCAL_INLINE FUNC(void, OS_CODE) Os_Core_IntStateInit
(
    P2CONST(Os_CoreCfgType, AUTOMATIC, OS_APPL_CONST) coreCfg
);
LOCAL_INLINE FUNC(void, OS_CODE) Os_CoreDyn_Init
(
    P2CONST(Os_CoreCfgType, AUTOMATIC, OS_APPL_CONST) coreCfg
);
LOCAL_INLINE FUNC(void, OS_CODE) Os_Core_Init
(
    CoreIdType coreId,
    AppModeType mode
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
* Function Name: Os_Core_IntStateInit
*
* Explanation: Init interrupt api state.
*
* Param: coreCfg: Core configuration.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Core_IntStateInit
(
    P2CONST(Os_CoreCfgType, AUTOMATIC, OS_APPL_CONST) coreCfg
)
{
    /* Init interrupt api state. */
    coreCfg->coreDyn->intState = coreCfg->intStateCfg;
    coreCfg->coreDyn->intState->intCnts = 0U;
#if( OS_CFG_CAT1_ISR_STACK_ENABLE == STD_ON )
    coreCfg->coreDyn->intState->cat1IntCnts = 0U;
#endif /* OS_CFG_CAT1_ISR_STACK_ENABLE == STD_ON */
}

/*
********************************************************************************
* Function Name: Os_CoreDyn_Init
*
* Explanation: Initialize the configuration data of the core.
*
* Param: coreCfg: Core configuration data.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_CoreDyn_Init
(
    P2CONST(Os_CoreCfgType, AUTOMATIC, OS_APPL_CONST) coreCfg
)
{
    /* Initialize the stack. */
    Os_Arch_Context_Stack_Init(coreCfg->contextCfg);
    /* Set context pointer address. */
    coreCfg->coreDyn->context = coreCfg->contextCfg->contextDyn;
    /* Initialize the core context. */
    Os_Arch_Context_Init(coreCfg->coreDyn->context, coreCfg->contextCfg);
    /* Init interrupt api state. */
    Os_Core_IntStateInit(coreCfg);
}

/*
********************************************************************************
* Function Name: Os_Core_Init
*
* Explanation: Core related object initialization.
*
* Param: coreId: Core logical index.
*        mode: Application mode.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Core_Init
(
    CoreIdType coreId,
    AppModeType mode
)
{
    uint16 objectIdx;
    /* Get the current core congfig. */
    const Os_CoreCfgType* coreCfg = OS_CORE_GETCFG(coreId);

    /* Set application mode. */
    OS_CORE_SETAPPMODE(coreId, mode);

#if( (OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
#if( OS_SYSTEM_MPU == STD_ON )
    /*Core mpu initialization.*/
    Os_Mp_MpInit(coreCfg->MemoryProtection);
#endif

#if( OS_CORE_MPU == STD_ON )
    Os_Mp_CoreMpInit(coreCfg->MemoryProtection);
#endif
#endif
    Os_Schedler_Init(coreCfg->scheduler, coreCfg->idleTask);

    /* App initialization. */
    for( objectIdx = 0U; objectIdx < coreCfg->appCnt; objectIdx++ )
    {
        Os_App_Init(coreCfg->appRefs[objectIdx]);
    }
    /* Task initialization. */
    for( objectIdx = 0U; objectIdx < coreCfg->taskCnt; objectIdx++ )
    {
        Os_Task_Init(coreCfg->taskRefs[objectIdx], mode);
    }
    /* Isr initialization. */
    for( objectIdx = 0U; objectIdx < coreCfg->isrCnt; objectIdx++ )
    {
        Os_Isr_Init(coreCfg->isrRefs[objectIdx]);
    }
#if( OS_CFG_CAT1_ISR_STACK_ENABLE == STD_ON )
    /* Cat1 isr initialization. */
    for( objectIdx = 0U; objectIdx < coreCfg->isrCat1Cnt; objectIdx++ )
    {
        Os_Cat1_Isr_Init(coreCfg->isrCat1Refs[objectIdx]);
    }
#endif /* OS_CFG_CAT1_ISR_STACK_ENABLE == STD_ON */
    /* Counter initialization. */
    for( objectIdx = 0U; objectIdx < coreCfg->counterCnt; objectIdx++ )
    {
        Os_Counter_Init(coreCfg->counterRefs[objectIdx]);
    }
    /* Alarm initialization. */
    for( objectIdx = 0U; objectIdx < coreCfg->alarmCnt; objectIdx++ )
    {
        Os_Alarm_Init(coreCfg->alarmRefs[objectIdx], mode);
    }
#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    /* SchedulerTable initialization. */
    for( objectIdx = 0U; objectIdx < coreCfg->schdTbCount; objectIdx++ )
    {
        Os_SchdTb_Init(coreCfg->schTbRefs[objectIdx], mode);
    }
#endif

#if( OS_CFG_RESOURCE_ENABLE == STD_ON )
     /* Resource initialization. */
    for( objectIdx = 0U; objectIdx < coreCfg->resourceCnt; objectIdx++ )
    {
        Os_Resource_Init(coreCfg->resourceRefs[objectIdx]);
    }
#endif

#if( OS_CFG_IOC_ENABLE == STD_ON )
    if( TRUE == coreCfg->coreIfMaster )
    {
        /* Ioc initialization. */
        for( objectIdx = 0U; objectIdx < IOC_CFG_COUNTER; objectIdx++ )
        {
            Os_Ioc_Init(&Os_IocCfg[objectIdx]);
        }
    }
#endif

#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
    if( OS_CORE_CHECKTPISENABLE(coreId) )
    {
        /* Time protection initialization. */
        Os_Tp_BaseInit(coreCfg->tpBaseCfg, coreId);
    }
#endif

#if( OS_CFG_MULTI_CORE == STD_ON )
    OS_CORE_SETCORESTARTSTE(coreId, OS_CORE_STARTINIT);
#endif
}
/*
********************************************************************************
* Function Name: Os_Init
*
* Explanation: Init os.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Init(void)
{
    /* Get the current logical core id. */
    CoreIdType coreId = Os_Core_GetLogicId();
    Os_ParamCheck(coreId < OS_COREID_COUNT);
    /* Get the current core congfig. */
    const Os_CoreCfgType* coreCfg = OS_CORE_GETCFG(coreId);

    Os_ParamCheck(NULL_PTR != coreCfg);

    OS_CORE_SETPROTYPE(coreId, OS_SYS_TYPE_MASK);
    /* Disable the global interrupt. */
    Os_Arch_IntDisableAll();
    /* Core hardware initialization FPU, etc.*/
    Os_Arch_HardwareInit();
    /* Set core configuratuin data. */
    Os_CoreDyn_Init(coreCfg);

#if( OS_CFG_MULTI_CORE == STD_ON )
    if(TRUE == coreCfg -> coreIfMaster)
    {
        /* Clear the master kernel synchronous variable. */
        OS_SETMULTISYNCCOUNTER(coreId, 0U);

        uint8 coreIdIdx;

        for( coreIdIdx = 0U; coreIdIdx < (uint8)OS_COREID_COUNT; coreIdIdx++ )
        {
            /* Multi-core start initialization. */
            OS_CORE_SETCORESTARTSTE(coreIdIdx, OS_CORE_STARTINIT);
            OS_CORE_SETCORESTARTREQ(coreIdIdx, OS_CORE_STARTREQINVALID);
            if( (uint8)OS_CORE_ID_MASTER != coreIdIdx )
            {
                OS_SETMULTISYNCCOUNTER(coreIdIdx, OS_MULTISYNCINIT);
            }
        }
    }
#endif
}

/*
********************************************************************************
* Function Name: StartOS
*
* Explanation: The user can call this system service to start the operating system
*              in a specific mode.
*
* Param: Mode: Application mode.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) StartOS(AppModeType Mode)
{
    uint16 objectIdx;
    const Os_IsrCfgType* isrCfg;
    const Os_IsrCat1CfgType* isrCat1Cfg;
    /* Get the current logical core id. */
    CoreIdType coreId = Os_Core_GetLogicId();
    /* Get the current core congfig. */
    const Os_CoreCfgType* coreCfg = OS_CORE_GETCFG(coreId);
    const Os_SystemCfgType* systemCfg = OS_GETSYSTEMCFG();
    /* Disable global interrupt. */
    Os_Arch_IntDisableAll();
    /* Core initialization. */
    Os_Core_Init(coreId, Mode);

    /* Cat2 nterrupt source initialization. */
    for( objectIdx = 0U; objectIdx < coreCfg->isrCnt; objectIdx++ )
    {
        isrCfg = coreCfg->isrRefs[objectIdx];
        Os_Isr_EnableSource(OS_ISR_GETISRSOURCE(isrCfg));
    }
    /* Cat1 nterrupt source initialization. */
    for( objectIdx = 0U; objectIdx < coreCfg->isrCat1Cnt; objectIdx++ )
    {
        isrCat1Cfg = coreCfg->isrCat1Refs[objectIdx];
        Os_Isr_EnableSource(OS_ISR_GETISRSOURCE(isrCat1Cfg));
    }

    if( TRUE == coreCfg->coreIfMaster )
    {
#if( OS_CFG_SPINLOCK_ENABLE == STD_ON )
        /* Spinlock initialization. */
        for( objectIdx = 0U; objectIdx < (uint16)OS_SPINLOCKID_COUNT; objectIdx++ )
        {
            Os_Spinlock_Init(Os_SpinlockCfgData[objectIdx]);
        }
#endif
        /* System cat1 interrupt source initialization. */
        for( objectIdx = 0U; objectIdx < systemCfg->isrCat1Cnt; objectIdx++ )
        {
            isrCat1Cfg = systemCfg->isrCat1Refs[objectIdx];
            Os_Isr_EnableSource(OS_ISR_GETISRSOURCE(isrCat1Cfg));
        }

        /* Sysytem cat2 interrupt source initialization. */
        for( objectIdx = 0U; objectIdx < systemCfg->isrCnt; objectIdx++ )
        {
            isrCfg = systemCfg->isrRefs[objectIdx];
            Os_Isr_EnableSource(OS_ISR_GETISRSOURCE(isrCfg));
        }
    }

#if( OS_CFG_MULTI_CORE == STD_ON )
    Os_MultiCore_Sync(coreId, OS_MULTISYNCFIRST);
#endif

    /* Call startupHook. */
    Os_Hook_CallStartupHook(coreId);

#if( OS_CFG_MULTI_CORE == STD_ON )
    Os_MultiCore_Sync(coreId, OS_MULTISYNCSECOND);
#endif

    /* Counter initialization. */
    for( objectIdx = 0U; objectIdx < coreCfg->counterCnt; objectIdx++ )
    {
        Os_Counter_Start(coreCfg->counterRefs[objectIdx]);
    }

    if( TRUE == coreCfg->coreIfMaster )
    {
        /* System counter initialization. */
        for( objectIdx = 0U; objectIdx < systemCfg->counterCnt; objectIdx++ )
        {
            Os_Counter_Start(systemCfg->counterRefs[objectIdx]);
        }
    }

    /* The scheduler starts to work. */
    OS_SCHEDULER_ENABLESCHEDULER(coreCfg->scheduler);
    OS_CORE_ALLOWSCH(coreId);

#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
    if( OS_CORE_CHECKTPISENABLE(coreId) )
    {
        Os_Tp_BaseStart(coreCfg->tpBaseCfg);
    }
#endif

#if( OS_CFG_MULTI_CORE == STD_ON )
    Os_MultiCore_Sync(coreId, OS_MULTISYNCTHIRD);
#endif
    /* Begin first init task. */
    Os_Task_StartFirst(coreId);
}

#if( OS_CFG_MULTI_CORE == STD_ON )
/*
********************************************************************************
* Function Name: StartCore
*
* Explanation: It is not supported to call this function after StartOS().
*
* Param: coreId: Core identifier.
*        Status: Return value of the function in extended status:
*
* Retval: E_OS_OK: No Error.
*         E_OS_ID: Core Id is invalid.
*         E_OS_ACCESS: The function was called after starting the OS.
*         E_OS_STATE: The Core is already activated.
********************************************************************************
*/
FUNC(void, OS_CODE) StartCore
(
    CoreIdType CoreID,
    P2VAR(StatusType, AUTOMATIC, OS_APPL_DATA) Status
)
{
    const Os_CoreCfgType* coreCfg;
    if( NULL_PTR == Status )
    {
        Os_FatalError();
    }

    *Status = E_OS_OK;

    if( OS_COREID_COUNT <= CoreID )
    {
        *Status = E_OS_ID;
    }
    else
    {
        /* Get the current core congfig. */
        coreCfg = OS_CORE_GETCFG(CoreID);
        /* Get the current logical core id. */
        CoreIdType currentCoreId = Os_Core_GetLogicId();

        /* If the parameter CoreID refers to a core that was already started by. */
        if( OS_CORE_STARTREQVALID == OS_CORE_GETCORESTARTREQ(CoreID))
        {
            *Status = E_OS_STATE;
        }
        /* If the api is not accessible. */
        else if( OS_CORE_PROCESSTYPEMATCH(currentCoreId, OS_STARTCORE_ACCESS) )
        {
            *Status = E_OS_CALLEVEL;
        }
        /* Calls to the StartCore function after StartOS() shall return with
           E_OS_ACCESS and the core shall not be started. */
        else if( OS_CORE_STARTINIT != OS_CORE_GETCORESTARTSTE(currentCoreId) )
        {
            *Status = E_OS_ACCESS;
        }
        else
        {
            OS_CORE_SETCORESTARTREQ(CoreID, OS_CORE_STARTREQVALID);
            OS_SETMULTISYNCCOUNTER(CoreID, 0U);
            if( FALSE == coreCfg->coreIfAutoStart)
            {
                Os_Arch_StartCore(CoreID, coreCfg->coreStartAddr);
            }
        }
    }
}
#endif  /* OS_CFG_MULTI_CORE == STD_ON */

/*
********************************************************************************
* Function Name: Os_Core_Shutdown
*
* Explanation: Shutdown core related object.
*
* Param: error: error occurred.
*        coreId: Core logical index.
*        sync: whether to perform synchronization.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Core_Shutdown
(
    StatusType error,
    CoreIdType coreId,
    boolean sync
)
{
    Os_ObjIdxType appIdx;
    Os_Arch_IntState intState;
    const Os_CoreCfgType* coreCfg = OS_CORE_GETCFG(coreId);

    /* Disable interrupt. */
    Os_Arch_IntDisable(&intState);

    OS_CORE_SETPROTYPE(coreId, OS_SYS_TYPE_MASK);

    for( appIdx = 0U; appIdx < coreCfg->appCnt; appIdx++ )
    {
        if( !OS_APP_STATEOFF(appIdx) )
        {
            (void)Os_App_IntTerminationApp(coreCfg->appRefs[appIdx], NO_RESTART);
        }
    }

    /* Call shutdown Hook. */
    Os_Hook_CallShutdownHook(coreId, error, sync);
    /* Disable interrupt. */
    Os_Arch_IntDisableAll();
    /* This function not return. */
    while( TRUE )
    {
        Os_Arch_Nop();
    }
}

/*
********************************************************************************
* Function Name: Os_Core_ShutdownOs
*
* Explanation: Shutdown os for ShutdownOS api.
*
* Param: error: error occurred.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Core_ShutdownOs(StatusType error)
{
    CoreIdType coreId;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_ShutdownOs);
    /* Get logic core id */
    coreId = Os_Core_GetLogicId();

    if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_SHUTDOWNOS_ACCESS) )
    {
        (void)Os_Hook_CallErrorHook(OSServiceId_ShutdownOs, E_OS_CALLEVEL);
    }
    else
    {
        /* If the current application is trusted. */
        if( OS_APP_TRUSTED == OS_APPGETTRUSTED(OS_CORE_GETAPPID(coreId)) )
        {
            Os_Core_Shutdown(error, coreId, FALSE);
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_ShutdownOs);
}

/*
********************************************************************************
* Function Name: Os_Core_ShutdownAllCores
*
* Explanation: Shutdown all core for ShutdownAllCores api .
*
* Param: error: error occurred.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Core_ShutdownAllCores(StatusType error)
{
    CoreIdType coreId;
#if( OS_CFG_MULTI_CORE == STD_ON )
    uint32 coreIdx;
#endif

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_ShutdownAllCores);
    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();

    if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_SHUTDOWNALLCORES_ACCESS) )
    {
        (void)Os_Hook_CallErrorHook(OSServiceId_ShutdownAllCores, E_OS_CALLEVEL);
    }
    else
    {
        /* If the current application is trusted. */
        if( OS_APP_TRUSTED == OS_APPGETTRUSTED(OS_CORE_GETAPPID(coreId)) )
        {
            /* Disable interrupt. */
            Os_Arch_IntDisableAll();
#if( OS_CFG_MULTI_CORE == STD_ON )
            for( coreIdx = (uint32)OS_CORE_ID_0; coreIdx < (uint32)OS_COREID_COUNT; coreIdx++ )
            {
                if( coreIdx != (uint32)coreId )
                {
                    /* Get alarm of target core. */
                    Os_MultiCoreServeParamType parameter;
                    parameter.Os_ShutdownAllCores.error = error;
                    /* Execute multi-core calling function. */
                    (void)Os_MultiCore_Trigger(FALSE, coreId, (CoreIdType)coreIdx,
                                               Os_MCServe_ShutdownAllCores_ID, &parameter);
                }
            }
#endif
            Os_Core_Shutdown(error, coreId, TRUE);
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_ShutdownAllCores);
}

/*
********************************************************************************
* Function Name: Os_Core_GetCurrentTask
*
* Explanation: Get the currently running task
*
* Param: None
*
* Retval: Running task.
********************************************************************************
*/
FUNC_P2VAR(Os_TaskDynType, OS_APPL_DATA, OS_CODE) Os_Core_GetCurrentTask(void)
{
    return Os_CoreCfgData[Os_Core_GetLogicId()]->coreDyn->currentTask;
}

/*
********************************************************************************
* Function Name: Os_Core_GetCurrentContext
*
* Explanation: Get the currently context.
*
* Param: None
*
* Retval: Currently context.
********************************************************************************
*/
FUNC_P2VAR(Os_Arch_ContextDynType*, OS_APPL_DATA, OS_CODE) Os_Core_GetCurrentContext(void)
{
    /* Get the current logical core id. */
    CoreIdType coreId = Os_Core_GetLogicId();
    Os_Arch_ContextDynType** currentContext;
    /* If current process is interrupt */
    if( 0U != OS_CORE_GETINTCNTS(coreId) )
    {
        currentContext = (Os_Arch_ContextDynType**)Os_CoreCfgData[coreId]->coreDyn->currentIsr;
    }
    else
    {
        currentContext = (Os_Arch_ContextDynType**)Os_CoreCfgData[coreId]->coreDyn->currentTask;
    }

    return currentContext;
}

/*
********************************************************************************
* Function Name: Os_Core_DisableAllInterrupts
*
* Explanation: Internal function to disable all interrupts for which the hardware
*              supports disabling.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Core_DisableAllInterrupts(void)
{
    Os_StatusType status = E_OS_OK;
    CoreIdType coreId;
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
    Os_IntLevelType currentLevel;
#endif
    Os_IntApiStateType* intApiState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_DisableAllInterrupts);
    /* Get logic core id */
    coreId = Os_Core_GetLogicId();
    intApiState = OS_CORE_GETINTAPISATE(coreId);

    if( TRUE == intApiState->disableFlag ) /* If the DisableAllInterrupts function is called. */
    {
        status = E_OS_CALL_ERROR;
    }
    else if( (intApiState->suspendCnt > OS_CORE_INIT) || (intApiState->suspendOsCnt > OS_CORE_INIT) )
    {     /* If the SuspendAllInterrupts or SuspendOSInterrupts function is called. */
        status = E_OS_CALL_ERROR;
    }
    else
    {
#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
    if( OS_CORE_CHECKTPISENABLE(coreId) )
    {
        const Os_TpCfgType* currentTpCfg;

        if( OS_TASK_TYPE_MASK == OS_CORE_GETPROTYPE(coreId) )
        {
            currentTpCfg = OS_TASK_GETCFG(OS_CORE_GETCURRENTTASKID(coreId))->tpCfg;
            Os_Tp_StartAllIntBudget(currentTpCfg, coreId);
        }
        else if( OS_ISR_CAT2_TYPE_MASK == OS_CORE_GETPROTYPE(coreId) )
        {
            currentTpCfg = OS_ISR_GETCFG(OS_CORE_GETCURRENTISRID(coreId))->tpCfg;
            Os_Tp_StartAllIntBudget(currentTpCfg, coreId);
        }
        else
        {
            /* Do nothing. */
        }
    }
#endif

#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
        /* Get current interrupt mask level. */
        currentLevel = Os_Arch_GetIntMaskLevel();
#endif
        /* Disable all the interrupts. */
        Os_Isr_DisableAllInterrupts();
        /* Set disable flag. */
        intApiState->disableFlag = TRUE;
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
        /* Record the current interrupt mask level. */
        intApiState->saveLevel = currentLevel;
#endif

#if( (OS_CFG_ORTI_ENABLE == STD_ON) && (OS_CFG_ORTI_HOOK_ENABLE == STD_ON) )
        /* Call orti hook. */
        Os_Orit_InterruptState_Trigger(coreId, OS_ORTI_INT_DISABLE_ALL_TRIGGER);
#endif
    }

    OS_ORTI_API_MONITOR_EXIT(OSServiceId_DisableAllInterrupts);
    /* Report error information. */
    (void)Os_Hook_CallErrorHook(OSServiceId_DisableAllInterrupts, status);
}

/*
********************************************************************************
* Function Name: Os_Core_EnableAllInterrupts
*
* Explanation: Internal function to restore the state saved by DisableAllInterrupts.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Core_EnableAllInterrupts(void)
{
    Os_StatusType status = E_OS_OK;
    CoreIdType coreId;
    Os_IntApiStateType* intApiState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_EnableAllInterrupts);
    /* Get logic core id */
    coreId = Os_Core_GetLogicId();
    intApiState = OS_CORE_GETINTAPISATE(coreId);

    if( FALSE == intApiState->disableFlag ) /* If the DisableAllInterrupts function is not called. */
    {
        status = E_OS_CALL_ERROR;
    }
    else if( (intApiState->suspendCnt > OS_CORE_INIT) || (intApiState->suspendOsCnt > OS_CORE_INIT) )
    {       /* If the SuspendAllInterrupts or SuspendOSInterrupts function is called. */
        status = E_OS_CALL_ERROR;
    }
    else
    {
        /* Clear disable flag. */
        intApiState->disableFlag = FALSE;
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
        /* Recover cat1 level interruption. */
        Os_Isr_EnableAllInterrupts(intApiState->saveLevel);
#else
        /* Enable all the interrupts. */
        Os_Isr_EnableAllInterrupts();
#endif

#if( (OS_CFG_ORTI_ENABLE == STD_ON) && (OS_CFG_ORTI_HOOK_ENABLE == STD_ON) )
        /* Call orti hook. */
        Os_Orit_InterruptState_Trigger(coreId, OS_ORTI_INT_ENABLE_ALL_TRIGGER);
#endif

#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
    if( OS_CORE_CHECKTPISENABLE(coreId) )
    {
        const Os_TpCfgType* currentTpCfg;

        if( OS_TASK_TYPE_MASK == OS_CORE_GETPROTYPE(coreId) )
        {
            currentTpCfg = OS_TASK_GETCFG(OS_CORE_GETCURRENTTASKID(coreId))->tpCfg;
            Os_Tp_StopAllIntBudget(currentTpCfg, coreId);
        }
        else if( OS_ISR_CAT2_TYPE_MASK == OS_CORE_GETPROTYPE(coreId) )
        {
            currentTpCfg = OS_ISR_GETCFG(OS_CORE_GETCURRENTISRID(coreId))->tpCfg;
            Os_Tp_StopAllIntBudget(currentTpCfg, coreId);
        }
        else
        {
            /* Do nothing. */
        }
    }
#endif
    }

    OS_ORTI_API_MONITOR_EXIT(OSServiceId_EnableAllInterrupts);
    /* Report error information. */
    (void)Os_Hook_CallErrorHook(OSServiceId_EnableAllInterrupts, status);
}

/*
********************************************************************************
* Function Name: Os_Core_SuspendAllInterrupts
*
* Explanation: Internal function to save the recognition status of all interrupts
*              and disable all interrupts for which the hardware supports disabling.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Core_SuspendAllInterrupts(void)
{
    Os_StatusType status = E_OS_OK;
    CoreIdType coreId;
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
    Os_IntLevelType currentLevel;
#endif
    Os_IntApiStateType* intApiState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_SuspendAllInterrupts);
    /* Get logic core id */
    coreId = Os_Core_GetLogicId();
    intApiState = OS_CORE_GETINTAPISATE(coreId);

    if( TRUE == intApiState->disableFlag ) /* If the DisableAllInterrupts function is called. */
    {
        status = E_OS_CALL_ERROR;
    }
    else if( OS_SUPENDINTERRUPTCNT == intApiState->suspendCnt )
    {      /* If the SuspendAllInterrupts function reach the max counter. */
        status = E_OS_CALL_ERROR;
    }
    else
    {
        /* Function is not nested. */
        if( OS_CORE_INIT == intApiState->suspendCnt )
        {
#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
            if( OS_CORE_CHECKTPISENABLE(coreId) )
            {
                const Os_TpCfgType* currentTpCfg;

                if( OS_TASK_TYPE_MASK == OS_CORE_GETPROTYPE(coreId) )
                {
                    currentTpCfg = OS_TASK_GETCFG(OS_CORE_GETCURRENTTASKID(coreId))->tpCfg;
                    Os_Tp_StartAllIntBudget(currentTpCfg, coreId);
                }
                else if( OS_ISR_CAT2_TYPE_MASK == OS_CORE_GETPROTYPE(coreId) )
                {
                    currentTpCfg = OS_ISR_GETCFG(OS_CORE_GETCURRENTISRID(coreId))->tpCfg;
                    Os_Tp_StartAllIntBudget(currentTpCfg, coreId);
                }
                else
                {
                    /* Do nothing. */
                }
            }

#endif

#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
            /* Get current interrupt mask level. */
            currentLevel = Os_Arch_GetIntMaskLevel();
#endif
            /* Disable all the interrupts. */
            Os_Isr_DisableAllInterrupts();
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
            /* Record the current interrupt mask level. */
            intApiState->saveLevel = currentLevel;
#endif

#if( (OS_CFG_ORTI_ENABLE == STD_ON) && (OS_CFG_ORTI_HOOK_ENABLE == STD_ON) )
            /* Call orti hook. */
            Os_Orit_InterruptState_Trigger(coreId, OS_ORTI_INT_SUSPEND_ALL_TRIGGER);
#endif
        }
        /* Increase the suspend counter. */
        intApiState->suspendCnt++;
    }

    OS_ORTI_API_MONITOR_EXIT(OSServiceId_SuspendAllInterrupts);
    /* Report error information. */
    (void)Os_Hook_CallErrorHook(OSServiceId_SuspendAllInterrupts, status);
}

/*
********************************************************************************
* Function Name: Os_Core_ResumeAllInterrupts
*
* Explanation: Internal function to restore the recognition status of all interrupts
*              saved by the SuspendAllInterrupts service.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Core_ResumeAllInterrupts(void)
{
    Os_StatusType status = E_OS_OK;
    CoreIdType coreId;
    Os_IntApiStateType* intApiState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_ResumeAllInterrupts);
    /* Get logic core id */
    coreId = Os_Core_GetLogicId();
    intApiState = OS_CORE_GETINTAPISATE(coreId);

    if( TRUE == intApiState->disableFlag ) /* If the DisableAllInterrupts function is called. */
    {
        status = E_OS_CALL_ERROR;
    }
    else if( OS_CORE_INIT == intApiState->suspendCnt )  /* If the SuspendAllInterrupts is never called. */
    {
        status = E_OS_CALL_ERROR;
    }
    else
    {
        /* Decrease the suspend counter. */
        intApiState->suspendCnt--;
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
        /* Function is not nested. */
        if( OS_CORE_INIT == intApiState->suspendCnt )
        {
            /* Restore the interrupt mask level that was interrupted. */
            Os_Isr_EnableAllInterrupts(intApiState->saveLevel);
#else
        if( (OS_CORE_INIT == intApiState->suspendOsCnt) && (OS_CORE_INIT == intApiState->suspendCnt) )
        {
            /* Enable all the interrupts. */
            Os_Isr_EnableAllInterrupts();
#endif

#if( (OS_CFG_ORTI_ENABLE == STD_ON) && (OS_CFG_ORTI_HOOK_ENABLE == STD_ON) )
            /* Call orti hook. */
            Os_Orit_InterruptState_Trigger(coreId, OS_ORTI_INT_RESUME_ALL_TRIGGER);
#endif

#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
            if( OS_CORE_CHECKTPISENABLE(coreId) )
            {
                const Os_TpCfgType* currentTpCfg;

                if( OS_TASK_TYPE_MASK == OS_CORE_GETPROTYPE(coreId) )
                {
                    currentTpCfg = OS_TASK_GETCFG(OS_CORE_GETCURRENTTASKID(coreId))->tpCfg;
                    Os_Tp_StopAllIntBudget(currentTpCfg, coreId);
                }
                else if( OS_ISR_CAT2_TYPE_MASK == OS_CORE_GETPROTYPE(coreId) )
                {
                    currentTpCfg = OS_ISR_GETCFG(OS_CORE_GETCURRENTISRID(coreId))->tpCfg;
                    Os_Tp_StopAllIntBudget(currentTpCfg, coreId);
                }
                else
                {
                    /* Do nothing. */
                }
            }
#endif
        }
    }

    OS_ORTI_API_MONITOR_EXIT(OSServiceId_ResumeAllInterrupts);
    /* Report error information. */
    (void)Os_Hook_CallErrorHook(OSServiceId_ResumeAllInterrupts, status);
}

/*
********************************************************************************
* Function Name: Os_Core_SuspendOSInterrupts
*
* Explanation: Internal function to save the recognition status of interrupts of
*              category 2 and disable the recognition of these interrupts.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Core_SuspendOSInterrupts(void)
{
    Os_StatusType status = E_OS_OK;
    CoreIdType coreId;
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
    Os_IntLevelType currentLevel;
#endif
    Os_IntApiStateType* intApiState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_SuspendOSInterrupts);
    /* Get logic core id */
    coreId = Os_Core_GetLogicId();
    intApiState = OS_CORE_GETINTAPISATE(coreId);

    if( TRUE == intApiState->disableFlag ) /* If the DisableAllInterrupts function is called. */
    {
        status = E_OS_CALL_ERROR;
    }
    else if( OS_SUPENDINTERRUPTCNT == intApiState->suspendOsCnt )
    {        /* If the SuspendAllInterrupts function reach the max counter. */
        status = E_OS_CALL_ERROR;
    }
    else
    {
         /* Function is not nested. */
        if( OS_CORE_INIT == intApiState->suspendOsCnt )
        {
#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
            if( OS_CORE_CHECKTPISENABLE(coreId) )
            {
                const Os_TpCfgType* currentTpCfg;

                if( OS_TASK_TYPE_MASK == OS_CORE_GETPROTYPE(coreId) )
                {
                    currentTpCfg = OS_TASK_GETCFG(OS_CORE_GETCURRENTTASKID(coreId))->tpCfg;
                    Os_Tp_StartOsIntBudget(currentTpCfg, coreId);
                }
                else if( OS_ISR_CAT2_TYPE_MASK == OS_CORE_GETPROTYPE(coreId) )
                {
                    currentTpCfg = OS_ISR_GETCFG(OS_CORE_GETCURRENTISRID(coreId))->tpCfg;
                    Os_Tp_StartOsIntBudget(currentTpCfg, coreId);
                }
                else
                {
                    /* Do nothing. */
                }
            }
#endif

#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
            /* Get current interrupt mask level. */
            currentLevel = Os_Arch_GetIntMaskLevel();
#endif
            /* Disable all the interrupts. */
            Os_Isr_SuspendOSInterrupts();
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
            /* Record the current interrupt mask level. */
            intApiState->saveOsLevel = currentLevel;
#endif

#if( (OS_CFG_ORTI_ENABLE == STD_ON) && (OS_CFG_ORTI_HOOK_ENABLE == STD_ON) )
            /* Call orti hook. */
            Os_Orit_InterruptState_Trigger(coreId, OS_ORTI_INT_SUSPENDOS_ALL_TRIGGER);
#endif
        }
        /* Increase the suspend counter. */
        intApiState->suspendOsCnt++;
    }

    OS_ORTI_API_MONITOR_EXIT(OSServiceId_SuspendOSInterrupts);
    /* Report error information. */
    (void)Os_Hook_CallErrorHook(OSServiceId_SuspendOSInterrupts, status);
}

/*
********************************************************************************
* Function Name: Os_Core_ResumeOSInterrupts
*
* Explanation: Internal function to restore the recognition status of interrupts
*              saved by the SuspendOSInterrupts service.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Core_ResumeOSInterrupts(void)
{
    Os_StatusType status = E_OS_OK;
    CoreIdType coreId;
    Os_IntApiStateType* intApiState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_ResumeOSInterrupts);
    /* Get logic core id */
    coreId = Os_Core_GetLogicId();
    intApiState = OS_CORE_GETINTAPISATE(coreId);

    if( TRUE == intApiState->disableFlag ) /* If the DisableAllInterrupts function is called. */
    {
        status = E_OS_CALL_ERROR;
    }
    else if( OS_CORE_INIT == intApiState->suspendOsCnt )  /* If the SuspendAllInterrupts is never called. */
    {
        status = E_OS_CALL_ERROR;
    }
    else
    {
        /* Decrease the suspend counter. */
        intApiState->suspendOsCnt--;
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
         /* Function is not nested. */
        if( OS_CORE_INIT == intApiState->suspendOsCnt )
        {
            /* Restore the interrupt mask level that was interrupted. */
            Os_Isr_ResumeOSInterrupts(intApiState->saveOsLevel);
#else
        if( (OS_CORE_INIT == intApiState->suspendOsCnt) && (OS_CORE_INIT == intApiState->suspendCnt) )
        {
            /* Enable all the interrupts. */
            Os_Isr_ResumeOSInterrupts();
#endif

#if( (OS_CFG_ORTI_ENABLE == STD_ON) && (OS_CFG_ORTI_HOOK_ENABLE == STD_ON) )
            /* Call orti hook. */
            Os_Orit_InterruptState_Trigger(coreId, OS_ORTI_INT_RESUMEOS_ALL_TRIGGER);
#endif

#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
            if( OS_CORE_CHECKTPISENABLE(coreId) )
            {
                const Os_TpCfgType* currentTpCfg;

                if( OS_TASK_TYPE_MASK == OS_CORE_GETPROTYPE(coreId) )
                {
                    currentTpCfg = OS_TASK_GETCFG(OS_CORE_GETCURRENTTASKID(coreId))->tpCfg;
                    Os_Tp_StopOsIntBudget(currentTpCfg, coreId);
                }
                else if( OS_ISR_CAT2_TYPE_MASK == OS_CORE_GETPROTYPE(coreId) )
                {
                    currentTpCfg = OS_ISR_GETCFG(OS_CORE_GETCURRENTISRID(coreId))->tpCfg;
                    Os_Tp_StopOsIntBudget(currentTpCfg, coreId);
                }
                else
                {
                    /* Do nothing. */
                }
            }
#endif
        }
    }

    OS_ORTI_API_MONITOR_EXIT(OSServiceId_ResumeOSInterrupts);
    /* Report error information. */
    (void)Os_Hook_CallErrorHook(OSServiceId_ResumeOSInterrupts, status);
}

/*
********************************************************************************
* Function Name: Os_Core_CleanInterrupts
*
* Explanation: Internal function to clear interrupt api status.
*
* Param: coreId: Core logical index.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Core_CleanInterrupts(CoreIdType coreId)
{
    Os_IntApiStateType* intApiState;

    intApiState = OS_CORE_GETINTAPISATE(coreId);

#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
    /* Recover cat1 level interruption. */
    Os_Isr_EnableAllInterrupts(intApiState->saveLevel);
#else
    /* Enable all the interrupts. */
    Os_Isr_EnableAllInterrupts();
#endif

    /* Init disable Flag. */
    intApiState->disableFlag = FALSE;
    /* Init number of all interrupt nests. */
    intApiState->suspendCnt = OS_CORE_INIT;
    /* Init number of os interrupt nests. */
    intApiState->suspendOsCnt = OS_CORE_INIT;
    /* Init interrupt mask level. */
    intApiState->saveLevel = OS_CORE_INIT;
}

/*
********************************************************************************
* Function Name: Os_Core_TerminationApp
*
* Explanation: Internal function to restore the recognition status of interrupts
*              saved by the SuspendOSInterrupts service.
*
* Param: coreId: Core logical index.
*        appId: App index.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Core_TerminationApp(CoreIdType coreId, ApplicationType appId)
{
    uint16 objectIdx;
    const Os_IsrCfgType* isrCfg;
    const Os_IsrCat1CfgType* isrCat1Cfg;
    const Os_TaskCfgType* taskCfg;
    const Os_AlarmCfgType* alarmCfg;
#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    const Os_SchdTbCfgType* schdTbCfg;
#endif

    /* Get the current core congfig. */
    const Os_CoreCfgType* coreCfg = OS_CORE_GETCFG(coreId);

    /* Cat2 isr disable. */
    for( objectIdx = 0U; objectIdx < coreCfg->isrCnt; objectIdx++ )
    {
        isrCfg = coreCfg->isrRefs[objectIdx];
        if( appId == OS_ISR_GETAPPID(isrCfg) )
        {
            Os_Isr_AppTerminateIsr(isrCfg);
        }
    }
     /* Cat1 isr disable. */
    for( objectIdx = OS_ZERO_VALUE; objectIdx < coreCfg->isrCat1Cnt; objectIdx++ )
    {
        isrCat1Cfg = coreCfg->isrCat1Refs[objectIdx];
        if( appId == OS_ISR_GETAPPID(isrCat1Cfg) )
        {
            /* Disable interrupt source. */
            Os_Isr_DisableSource(OS_ISR_GETISRSOURCE(isrCat1Cfg));
        }
    }
     /* Terminate tasks. */
    for( objectIdx = 0U; objectIdx < coreCfg->taskCnt; objectIdx++ )
    {
        taskCfg = coreCfg->taskRefs[objectIdx];
        if( appId == OS_TASK_GETAPPID(taskCfg) )
        {
            Os_Task_AppTerminateTask(taskCfg);
        }
    }

    /* Terminate alarms. */
    for( objectIdx = 0U; objectIdx < coreCfg->alarmCnt; objectIdx++ )
    {
        alarmCfg = coreCfg->alarmRefs[objectIdx];
        if( appId == OS_ALARM_GETAPPID(alarmCfg) )
        {
            Os_Alarm_AppTerminateAlarm(alarmCfg);
        }
    }

#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    /* Terminate schedule tables. */
    for( objectIdx = 0U; objectIdx < coreCfg->schdTbCount; objectIdx++ )
    {
        schdTbCfg = coreCfg->schTbRefs[objectIdx];
        if( appId == OS_SCHDTB_GETAPPID(schdTbCfg) )
        {
            Os_SchdTb_AppTerminateSchdTb(schdTbCfg);
        }
    }
#endif
}

/*
********************************************************************************
* Function Name: Os_TargetShutDownAllCore
*
* Explanation: Multicore function to shut down all core.
*
* Param: error: error occurred.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_TargetShutDownAllCore(StatusType error)
{
    CoreIdType coreId;
    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();

    /* Shutdown OS. */
    Os_Core_Shutdown(error, coreId, TRUE);
}

/*
********************************************************************************
* Function Name: Os_Core_ControlIdleSimp
*
* Explanation: Internal function, uses to select the idle mode.
*
* Param: CoreID: selects the core which idle mode is set.
*        IdleMode: the mode which shall be performed during idle time.
*
* Retval: E_OK: No Error.
********************************************************************************
*/
static FUNC(StatusType, OS_CODE) Os_Core_ControlIdleSimp
(
    CoreIdType CoreID,
    IdleModeType IdleMode
)
{
    OS_CORE_SETIDLEMODE(CoreID, IdleMode); /* Set idlemode to core. */
    OS_CORE_SETIDLEMODESTATE(CoreID, TRUE); /* Set idlemode state to core. */

    return E_OS_OK;
}

/*
********************************************************************************
* Function Name: Os_Core_ControlIdle
*
* Explanation: Uses to select the idle mode.
*
* Param: CoreID: selects the core which idle mode is set.
*        IdleMode: the mode which shall be performed during idle time.
*
* Retval: E_OK: No Error.
*         E_OS_ID: Invalid core and/or invalid idleMode.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_Core_ControlIdle
(
    CoreIdType CoreID,
    IdleModeType IdleMode
)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_ControlIdle);
    /* Get the current logical core id. */
    coreId = Os_Core_GetLogicId();

    if( CoreID >= OS_COREID_COUNT ) /* If resource id is out range. */
    {
        ret = E_OS_ID;
    }
    else if( IdleMode >= OS_IDLEMODE_COUNT ) /* If resource id is out range. */
    {
        ret = E_OS_ID;
    }
    else if( OS_CORE_MASK_INTERRUPT(coreId) ) /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_CONTROLIDLE_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        ret = Os_Core_ControlIdleSimp(CoreID, IdleMode);
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_ControlIdle);

    return Os_Hook_CallErrorHook(OSServiceId_ControlIdle, ret);
}

/*
********************************************************************************
* Function Name: DisableAllInterrupts
*
* Explanation: This service disables all interrupts for which the hardware
*              supports disabling.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) DisableAllInterrupts(void)
{
#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    Os_SysCall(Os_Syscall_DisableAllInterrupts_ID, &sysCallParam);
#else
    Os_Core_DisableAllInterrupts();
#endif
}

/*
********************************************************************************
* Function Name: EnableAllInterrupts
*
* Explanation: This service restores the state saved by DisableAllInterrupts.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) EnableAllInterrupts(void)
{
#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    Os_SysCall(Os_Syscall_EnableAllInterrupts_ID, &sysCallParam);
#else
    Os_Core_EnableAllInterrupts();
#endif
}

/*
********************************************************************************
* Function Name: SuspendAllInterrupts
*
* Explanation: This service saves the recognition status of all interrupts and
*              disables all interrupts for which the hardware supports disabling.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) SuspendAllInterrupts(void)
{
#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    Os_SysCall(Os_Syscall_SuspendAllInterrupts_ID, &sysCallParam);
#else
    Os_Core_SuspendAllInterrupts();
#endif
}

/*
********************************************************************************
* Function Name: ResumeAllInterrupts
*
* Explanation: This service restores the recognition status of all interrupts saved
*              by the SuspendAllInterrupts service.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) ResumeAllInterrupts(void)
{
#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    Os_SysCall(Os_Syscall_ResumeAllInterrupts_ID, &sysCallParam);
#else
    Os_Core_ResumeAllInterrupts();
#endif
}

/*
********************************************************************************
* Function Name: SuspendOSInterrupts
*
* Explanation: This service saves the recognition status of interrupts of category
*              2 and disables the recognition of these interrupts.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) SuspendOSInterrupts(void)
{
#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    Os_SysCall(Os_Syscall_SuspendOsInterrupts_ID, &sysCallParam);
#else
    Os_Core_SuspendOSInterrupts();
#endif
}

/*
********************************************************************************
* Function Name: ResumeOSInterrupts
*
* Explanation: This service restores the recognition status of interrupts saved
*              by the SuspendOSInterrupts service.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) ResumeOSInterrupts(void)
{
#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    Os_SysCall(Os_Syscall_ResumeOsInterrupts_ID, &sysCallParam);
#else
    Os_Core_ResumeOSInterrupts();
#endif
}

/*
********************************************************************************
* Function Name: GetCoreID
*
* Explanation: Get core logical index.
*
* Param: None
*
* Retval:  Core logical index.
********************************************************************************
*/
FUNC(CoreIdType, OS_CODE) GetCoreID(void)
{
    CoreIdType coreId;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    Os_SysCall(Os_Syscall_GetCoreId_ID, &sysCallParam);
    coreId = sysCallParam.Os_GetCoreID.retVal;
#else
    coreId = Os_Core_GetLogicId();
#endif

    return coreId;
}

/*
********************************************************************************
* Function Name: StartNonAutosarCore
*
* Explanation: The function starts the core specified by the parameter CoreID.
*              It is allowed to call this function after StartOS().
*
* Param: CoreID: Core logical index.
*        Status: Return value of the function in standard status:
*                E_OS_OK: No Error E_OS_ID: Core Id
*                E_OS_ID: Core Id is invalid.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) StartNonAutosarCore
(
    CoreIdType CoreID,
    P2CONST(StatusType, AUTOMATIC, OS_APPL_CONST) Status
)
{
    OS_DUMMY_STATEMENT(CoreID);
    OS_DUMMY_STATEMENT(Status);
}

/*
********************************************************************************
* Function Name: ShutdownOS
*
* Explanation: The user can call this system service to abort the overall system
*              (e.g. emergency off). The operating system also calls this function
*              internally, if it has reached an undefined internal state and is
*              no longer ready to run.
*
* Param: Error: error occurred.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) ShutdownOS(StatusType Error)
{
#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_ShutdownOS.error = Error;
    Os_SysCall(Os_Syscall_ShutdownOs_ID, &sysCallParam);
#else
    Os_Core_ShutdownOs(Error);
#endif
}

/*
********************************************************************************
* Function Name: ShutdownAllCores
*
* Explanation: After this service the OS on all AUTOSAR cores is shut down.
*              Allowed at TASK level and ISR level and also internally by the OS.
*              The function will never return. The function will force other cores
*              into a shutdown.
*
* Param: Error: error occurred.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) ShutdownAllCores(StatusType Error)
{
#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_ShutdownAllCores.error = Error;
    Os_SysCall(Os_Syscall_ShutdownAllCores_ID, &sysCallParam);
#else
    Os_Core_ShutdownAllCores(Error);
#endif
}

#if (OS_IDLEMODE_ENABLE == STD_ON)
/*
********************************************************************************
* Function Name: ControlIdle
*
* Explanation: Standard API function, uses to select the idle mode.
*
* Param: CoreID: selects the core which idle mode is set.
*        IdleMode: the mode which shall be performed during idle time.
*
* Retval: E_OK: No Error.
*         E_OS_ID: Invalid core and/or invalid idleMode.
*         E_OS_DISABLEDINT: A service of the Os is called inside an interrupt
*                           disable/enable pair.
*         E_OS_CALLEVEL: Called from invalid context.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) ControlIdle
(
    CoreIdType CoreID,
    IdleModeType IdleMode
)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_ControlIdle.coreID = CoreID;
    sysCallParam.Os_ControlIdle.idleMode = IdleMode;
    Os_SysCall(Os_Syscall_ControlIdle_ID, &sysCallParam);
    ret = sysCallParam.Os_ControlIdle.retVal;
#else
    ret = Os_Core_ControlIdle(CoreID, IdleMode);
#endif

    return ret;
}
#endif

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

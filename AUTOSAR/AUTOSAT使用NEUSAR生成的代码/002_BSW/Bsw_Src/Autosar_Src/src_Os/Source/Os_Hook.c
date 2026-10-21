/*
********************************************************************************
*
*  File name: Os_Hook.c
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
* Author/Date: LiG/2022.12.10
* Change: To solve stack overflow, call shutdownos recursively.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: JiangGL/2022.12.10
* Change: Fix the problem that the field type is not restored when you exit
          ProtectionHook.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: LiuJJ/2023.2.7
* Change: To solve stack overflow, call Os_Stack_Measure recursively.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.5.26
* Change: StartupHook and shutdownHook from the kernel will enter twice in a row.
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: JiangGL/2024.2.26
* Change: SFix the issue of calling ProtectionHook when triggering stack overflow
*         in SC1 stage.
* Cause: Bugfix
********************************************************************************
* Version: 3.7
* Author/Date: ZhangY/2023.10.07
* Change: Modify Os_Hook_CallStartupHook and Os_Hook_CallShutdownHook for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: ZhangY/2023.11.14
* Change: Modify Os_HookProtectionLogical, Os_HookProtectionProcess and
*         Os_Hook_CallProtectionHook to meet function safety requirements.
* Cause: Bugfix
********************************************************************************
* Version: 3.9
* Author/Date: ZhangY/2024.01.10
* Change: 1. Add Os_MemProtection.h to include header file.
*         2. Modify Os_HookProtectionLogical for QAC.
*         3. Modify Os_HookProtectionProcess to fix bug of ISR is terminated and
*            will no longer start.
*         4. Add mpu switch in Os_Hook_CallProtectionHook to fix bug of 
*            ProtectionHook have no system mpu access and causing hardfault.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: LiG/2024.03.15
* Change: After coming out of ErrorHook, the current AppId switches back.
* Cause: Bugfix
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Hook.h"
#include "Os_Core.h"
#include "Os_App.h"
#include "Os_Task.h"
#include "Os_Isr.h"
#include "Os_Error.h"
#include "Os_MultiCore.h"
#include "Os_MemProtection.h"

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
*    Local Constants
********************************************************************************
*/
/*
********************************************************************************
*    Local Functions
********************************************************************************
*/

LOCAL_INLINE FUNC(ProtectionReturnType, OS_CODE) Os_HookProtectionLogical
(
    CoreIdType coreId,
    OsCallerId caller,
    StatusType fatalerror,
    ProtectionReturnType protectionHookRet
);

LOCAL_INLINE FUNC(void, OS_CODE) Os_HookProtectionProcess
(
    CoreIdType coreId,
    OsCallerId caller,
    ProtectionReturnType protectionHookRet,
    StatusType error
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
* Function Name: Os_HookProtectionLogical
*
* Explanation: Hook Logical processing.
*
* Param: coreId: Core id.
*        caller: caller: The caller currently handling the error.
*        Fatalerror: The error which caused the call to the protection hook.
*        protectionHookRet: ProtectionHook retrun.
*
* Retval: Protection action.
********************************************************************************
*/
LOCAL_INLINE FUNC(ProtectionReturnType, OS_CODE) Os_HookProtectionLogical
(
    CoreIdType coreId,
    OsCallerId caller,
    StatusType fatalerror,
    ProtectionReturnType protectionHookRet
)
{
    ProtectionReturnType hookRet = PRO_IGNORE;

    /* If the parameter is out of range, enter directly SHUTDOWN. */
    if( OS_PROTECTIONREACTION_COUNT <= protectionHookRet )
    {
        hookRet = PRO_SHUTDOWN;
    }
    /* If returns PRO_SHUTDOWN, enter directly SHUTDOWN. */
    else if( PRO_SHUTDOWN == protectionHookRet )
    {
        hookRet = PRO_SHUTDOWN;
    }
    /* If returns PRO_IGNORE and was called with E_OS_PROTECTION_ARRIVAL the Os shall return
       control to the user application. */
    else if( (PRO_IGNORE == protectionHookRet) && (E_OS_PROTECTION_ARRIVAL == fatalerror) )
    {
        hookRet = PRO_IGNORE;
    }
    /* If called with E_OS_PROTECTION_ARRIVAL the only valid return values are PRO_IGNORE or PRO_SHUTDOWN. */
    else if( (PRO_IGNORE != protectionHookRet) && (E_OS_PROTECTION_ARRIVAL == fatalerror) )
    {
        hookRet = PRO_SHUTDOWN;
    }
    /* If returns PRO_IGNORE and was not called with E_OS_PROTECTION_ARRIVAL then the Operating
       System module shall call ShutdownOS(). */
    else if( (PRO_IGNORE == protectionHookRet) && (E_OS_PROTECTION_ARRIVAL != fatalerror) )
    {
        hookRet = PRO_SHUTDOWN;
    }
    /* Os shall forcibly terminate the faulty Task/Category 2 ISR. */
    else if( PRO_TERMINATETASKISR == protectionHookRet )
    {
        /* If returns PRO_TERMINATETASKISR and no Task or ISR can be associated with the error. */
        if( (OS_ISR_CAT2_TYPE_MASK != caller) && (OS_TASK_TYPE_MASK != caller) )
        {
            /* The running OS-Application is forcibly terminated by the Os. */
            if( (OS_SYS_TYPE_MASK != caller) && (OS_PRETASKHOOK_TYPE_MASK != caller) && (OS_POSTTASKHOOK_TYPE_MASK != caller) )
            {
                hookRet = PRO_TERMINATEAPPL;
            }
            else
            {
                /* If even no OS-Application can be assigned, ShutdownOS() is called. */
                hookRet = PRO_SHUTDOWN;
            }
        }
        else
        {
            /* Forcibly terminate the faulty Task/Category 2 ISR. */
            hookRet = PRO_TERMINATETASKISR;
        }
    }
    else if( PRO_TERMINATEAPPL == protectionHookRet )
    {
        /* If even no OS-Application can be assigned, ShutdownOS() is called. */
        if( (OS_ISR_CAT2_TYPE_MASK != caller) && (OS_TASK_TYPE_MASK != caller) )
        {
            hookRet = PRO_SHUTDOWN;
        }
        else
        {
            /* Forcibly terminate the faulty OS-Application. */
            hookRet = PRO_TERMINATEAPPL;
        }
    }
    else if( PRO_TERMINATEAPPL_RESTART == protectionHookRet )
    {
        /* If even no OS-Application can be assigned, ShutdownOS() is called. */
        if( (OS_ISR_CAT2_TYPE_MASK != caller) && (OS_TASK_TYPE_MASK != caller) )
        {
            hookRet = PRO_SHUTDOWN;
        }
        else
        {
            /* If no OsRestartTask was configured for the faulty OS-Application, ShutdownOS() is called. */
            if( NULL_PTR == OS_APP_GETRESTARTTASK(OS_CORE_GETAPPID(coreId)) )
            {
                hookRet = PRO_SHUTDOWN;
            }
            else
            {
                /* Forcibly terminate the faulty OS-Application and afterwards restart the OS-Application. */
                hookRet = PRO_TERMINATEAPPL_RESTART;
            }
        }
    }
    else
    {
        /* Do nothing. */
    }

    return hookRet;
}

/*
********************************************************************************
* Function Name: Os_HookProtectionProcess
*
* Explanation: Hook detailed processing flow.
*
* Param: coreId: Core id.
*        caller: caller: The caller currently handling the error.
*        protectionHookRet: ProtectionHook retrun.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_HookProtectionProcess
(
    CoreIdType coreId,
    OsCallerId caller,
    ProtectionReturnType protectionHookRet,
    StatusType error
)
{
    const Os_IsrCfgType* isrCfg;
    const Os_TaskCfgType* taskCfg;

    switch( protectionHookRet )
    {
        case PRO_IGNORE:
            /* Code ignore. */
            break;
        case PRO_TERMINATETASKISR:
            if( OS_ISR_CAT2_TYPE_MASK == caller )
            {
                isrCfg = OS_ISR_GETCFG(OS_CORE_GETCURRENTISRID(coreId));
                Os_Isr_TerminateIsr(isrCfg);
            }
            else if( OS_TASK_TYPE_MASK == caller )
            {
                taskCfg = OS_TASK_GETCFG(OS_CORE_GETCURRENTTASKID(coreId));
                Os_Task_AppTerminateTask(taskCfg);
#if( OS_ARCH == ARCH_CONTEXT_M )
                /* Execute a schedule. */
                (void)Os_Schedler_Schedle(OS_CORE_GETSCHEDULER(coreId));
                /* If interrupts is disable. */
                if( OS_CORE_MASK_INTERRUPT(coreId) )
                {
                    Os_Core_CleanInterrupts(coreId);
                }
                Os_Arch_TaskTerminate_ForCortextM();
                /* Enable interrupt. */
                Os_Arch_IntEnable(OS_ZERO_VALUE);
#endif
            }
            else
            {
                Os_FatalError();
            }
            break;
        case PRO_TERMINATEAPPL:
            (void)Os_App_TerminationApp(OS_CORE_GETAPPID(coreId), NO_RESTART);
            break;
        case PRO_TERMINATEAPPL_RESTART:
            (void)Os_App_TerminationApp(OS_CORE_GETAPPID(coreId), RESTART);
            break;
        case PRO_SHUTDOWN:
            Os_Core_Shutdown(error, coreId, FALSE);
            break;
        default:
            Os_FatalError();
            break;
    }
}

/*
********************************************************************************
* Function Name: Os_Hook_CallStartupHook
*
* Explanation: Call startup hook.
*
* Param: core: Reference to the core configuration.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Hook_CallStartupHook
(
    CoreIdType coreId
)
{
    Os_StartupHookType startupHookFunc;
    ApplicationType sysAppId;

    OS_CORE_SETPROTYPE(coreId, OS_STARTUPHOOK_TYPE_MASK);
    /* Call system app startup hook. */
    sysAppId = Os_APPGETAPPID(OS_CORE_GETCORECFGSYSAPP(coreId));
    startupHookFunc = Os_APPGETSTARTUPHOOK(sysAppId);
    if( NULL_PTR != startupHookFunc )
    {
        OS_CORE_SETAPPID(coreId, sysAppId);
        startupHookFunc();
    }

#if( (OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
    {
        Os_ObjIdxType index;
        /* Get the current core congfig. */
        const Os_CoreCfgType* coreCfg = OS_CORE_GETCFG(coreId);

        /* Call application specific startup hooks. */
        for( index = 0U; index < OS_CORE_GETCOREAPPNUMBER(coreCfg); index++ )
        {
            startupHookFunc = Os_APPGETSTARTUPHOOK(OS_CORE_GETCOREAPPLICATIONID(coreId, index));
            if( (NULL_PTR != startupHookFunc) && ((Os_ObjIdxType)OS_CORE_GETCOREAPPLICATIONID(coreId, index) != (Os_ObjIdxType)sysAppId) )
            {
                OS_CORE_SETAPPID(coreId, OS_CORE_GETCOREAPPLICATIONID(coreId, index));
                startupHookFunc();
            }
        }
    }
#endif

    OS_CORE_SETPROTYPE(coreId, OS_SYS_TYPE_MASK);
}

/*
********************************************************************************
* Function Name: Os_Hook_CallShutdownHook
*
* Explanation: Call shutdown hook.
*
* Param: core: Reference to the core configuration.
*        error: Error message.
*        sync: Whether to synchronize.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Hook_CallShutdownHook
(
    CoreIdType coreId,
    StatusType error,
    boolean sync
)
{
    Os_ShutdownHookType shutdownHookFunc;
    ApplicationType sysAppId;

    OS_CORE_SETPROTYPE(coreId, OS_SHUTDOWNHOOK_TYPE_MASK);

    /* Call system app shutdown hook. */
    sysAppId = Os_APPGETAPPID(OS_CORE_GETCORECFGSYSAPP(coreId));

#if( (OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
    {
        Os_ObjIdxType index;
        /* Get the current core congfig. */
        const Os_CoreCfgType* coreCfg = OS_CORE_GETCFG(coreId);

        /* Call application specific shutdown hooks. */
        for( index = 0U; index < OS_CORE_GETCOREAPPNUMBER(coreCfg); index++ )
        {
            shutdownHookFunc = Os_APPGETSHUDOWNHOOK(OS_CORE_GETCOREAPPLICATIONID(coreId, index));
            if( (NULL_PTR != shutdownHookFunc) && ((Os_ObjIdxType)OS_CORE_GETCOREAPPLICATIONID(coreId, index) != (Os_ObjIdxType)sysAppId) )
            {
                OS_CORE_SETAPPID(coreId, OS_CORE_GETCOREAPPLICATIONID(coreId, index));
                shutdownHookFunc(error);
            }
        }
    }
#endif

#if( OS_CFG_MULTI_CORE == STD_ON )
    if( TRUE == sync )
    {
        Os_MultiCore_Sync(coreId, OS_MULTISYNCFOURTH);
    }
#endif
    shutdownHookFunc = Os_APPGETSHUDOWNHOOK(sysAppId);
    if( NULL_PTR != shutdownHookFunc)
    {
        OS_CORE_SETAPPID(coreId, sysAppId);
        shutdownHookFunc(error);
    }

    OS_CORE_SETPROTYPE(coreId, OS_SYS_TYPE_MASK);
}

/*
********************************************************************************
* Function Name: Os_Hook_CallErrorHook
*
* Explanation: Call error hook.
*
* Param: serviceId: Service request identifier.
*        error: Error message.
*
* Retval: None
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_Hook_CallErrorHook
(
    OSServiceIdType serviceId,
    StatusType error
)
{
    CoreIdType coreId;
    OsCallerId caller;
    ApplicationType sysAppId;
    Os_ErrorHookType errorHookFunc;
    Os_Arch_IntState intState;
    ApplicationType currentAppId;

    if( E_OS_OK != error )
    {
        /* Disable interrupt. */
        Os_Arch_IntDisable(&intState);

        /* Get logic core id. */
        coreId = Os_Core_GetLogicId();
        currentAppId = OS_CORE_GETAPPID(coreId);
        caller = OS_CORE_GETPROTYPE(coreId);
        sysAppId = Os_APPGETAPPID(OS_CORE_GETCORECFGSYSAPP(coreId));
        Os_ErrorProcess(coreId, serviceId, error, caller);

        if( OS_ERRHOOK_TYPE_MASK == caller )
        {
            Os_FatalError();
        }
        else
        {
            OS_CORE_SETPROTYPE(coreId, OS_ERRHOOK_TYPE_MASK);
            /* Call system app error hook. */
            errorHookFunc = Os_APPGETSYSERRORHOOK(coreId);
            if( NULL_PTR != errorHookFunc )
            {
                OS_CORE_SETAPPID(coreId, sysAppId);
                errorHookFunc(error);
                OS_CORE_SETAPPID(coreId, currentAppId);
            }

#if( (OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
            /* Call application specific error hooks. */
            errorHookFunc = Os_APPGETERRORHOOK(currentAppId);
            if( (NULL_PTR != errorHookFunc) && (sysAppId != currentAppId) )
            {
                OS_CORE_SETAPPID(coreId, currentAppId);
                errorHookFunc(error);
            }
#endif
            OS_CORE_SETPROTYPE(coreId, (uint16)caller);
        }

#if( OS_ERRORHOOKFINISH == STD_ON )
    {
        Os_ErrorType errorMessage;
        Os_GetErrorInformation(&errorMessage);
        while( TRUE )
        {
            /* Infinite loop. */
        };
    }
#endif
        /* Enable interrupt. */
        Os_Arch_IntEnable(intState);
    }

    return error;
}

/*
********************************************************************************
* Function Name: Os_Hook_CallProtectionHook
*
* Explanation: Call protection hook.
*
* Param: The error which caused the call to the protection hook.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Hook_CallProtectionHook
(
    StatusType error
)
{
    CoreIdType coreId;
    OsCallerId caller;
    ApplicationType sysAppId;
    Os_ProtectionHookType protectionHookFunc = NULL_PTR;
    ProtectionReturnType protectionHookRet;
    Os_Arch_IntState intState;
    Os_ProcType oldProcType;
    ApplicationType currentAppId;

    /* Disable interrupt. */
    Os_Arch_IntDisable(&intState);

    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();
    caller = OS_CORE_GETPROTYPE(coreId);

    if( (OS_ERRHOOK_TYPE_MASK != caller) && (OS_SHUTDOWNHOOK_TYPE_MASK != caller) && (OS_SYS_TYPE_MASK != caller) && (OS_PROTECTHOOK_TYPE_MASK != caller) )
    {
        sysAppId = Os_APPGETAPPID(OS_CORE_GETCORECFGSYSAPP(coreId));

        /* Record related error information. */
        OS_CORE_SETERRORSTATUS(coreId, error);
        OS_CORE_SETERRORCALLER(coreId, caller);
        /* Get the currently context type of the core. */
        oldProcType = OS_CORE_GETPROTYPE(coreId);
        /* Set the protectionhook to be processed currently. */
        OS_CORE_SETPROTYPE(coreId,OS_PROTECTHOOK_TYPE_MASK);
#if( OS_SC1 != OS_CFG_SCALABILITY_CLASS )
        protectionHookFunc = OS_CORE_GETCOREPTOTECTIONHOOK(coreId);
#endif /* OS_SC1 != OS_CFG_SCALABILITY_CLASS */
        if( protectionHookFunc != NULL_PTR )
        {
            /* Get the currently running app id. */
            currentAppId = OS_CORE_GETAPPID(coreId);
            /* Set app id to system. */
            OS_CORE_SETAPPID(coreId, sysAppId);
#if( (OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
            if( E_OS_PROTECTION_MEMORY == error )
            {
                /* Get the current core congfig. */
                const Os_CoreCfgType* coreCfg = OS_CORE_GETCFG(coreId);
                /* Switch to the next application protection range.*/
                (void)Os_Mp_Switch(TRUE, coreCfg->idleTask->appMpCfg);
                /* Switch to the next protection range.*/
                (void)Os_Mp_Switch(FALSE, coreCfg->idleTask->taskMpCfg);
            }
#endif
            protectionHookRet = protectionHookFunc(error);
            /* Set core current app. */
            OS_CORE_SETAPPID(coreId, currentAppId);

            /* Hook Logical processing. */
            protectionHookRet = Os_HookProtectionLogical(coreId, caller, error, protectionHookRet);
            /* Hook detailed processing flow. */
            Os_HookProtectionProcess(coreId, caller, protectionHookRet, error);
        }
        else
        {
            /* If no ProtectionHook() is configured shall call Os_Core_Shutdown(). */
            Os_Core_Shutdown(error, coreId, FALSE);
        }
        /* Set the oldProcType to be processed currently. */
        OS_CORE_SETPROTYPE(coreId, oldProcType);
    }

    /* Enable interrupt. */
    Os_Arch_IntEnable(intState);
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

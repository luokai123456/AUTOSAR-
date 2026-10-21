/*
********************************************************************************
*
*  File name: Os_TrustFun.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: YaoXJ/2021.02.16
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2022.12.15
* Change: For static code checking.
* Cause: Optimize
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.1.29
* Change: Resolve the CallErrorHook privilege level problem.
* Cause: Optimization
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
* Author/Date: LiG/2023.5.27
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: LiG/2024.2.29
* Change: Change comment.
* Cause: Optimization
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_TrustFun.h"
#include "Os_Hook.h"
#include "Os_App.h"
#include "Os_Isr.h"
#include "Os_Task.h"
#include "Os_SysCall.h"
#include "Os_TrustFun_Lcfg.h"
#include "Os_Orti.h"
#include "Os.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/* Get the trusted function static configuration by id. */
#define OS_TRUSTFUN_GETCFG(trustFunId) (Os_TrustedFunctionCfgData[trustFunId])

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
#if( OS_CFG_TRUSTFUN == STD_ON )
static FUNC(void, OS_CODE) Os_CallTrustedFunctionSimp
(
    TrustedFunctionIndexType functionIndex,
    TrustedFunctionParameterRefType functionParams,
    P2CONST(Os_TrustedFunctionCfgType, AUTOMATIC, OS_APPL_CONST) trusFunCfg
);
#endif

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

#if( OS_CFG_TRUSTFUN == STD_ON )
/*
********************************************************************************
* Function Name: Os_CallTrustedFunctionSimp
*
* Explanation: Depends on called function. If called function is synchronous then
*              service is synchronous. May cause rescheduling.
*
* Param: functionIndex: Index of the function to be called.
*        functionParams: Pointer to the parameters for the function - specified
*        by the functionIndex - to be called. If no parameters are provided, a NULL
*        pointer has to be passed.
*        trusFunCfg: CallTrusted function config.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_CallTrustedFunctionSimp
(
    TrustedFunctionIndexType functionIndex,
    TrustedFunctionParameterRefType functionParams,
    P2CONST(Os_TrustedFunctionCfgType, AUTOMATIC, OS_APPL_CONST) trusFunCfg
)
{
    Os_Arch_IntState intState;
    /* Currently running app. */
    ApplicationType currentAppId;
    const Os_IsrCfgType* isrCfg;
    const Os_TaskCfgType* taskCfg;
    /* Get logic core id */
    CoreIdType coreId = Os_Core_GetLogicId();
    Os_ProcType caller = OS_CORE_GETPROTYPE(coreId);

#if( OS_MEMORY_PROTECTION == STD_ON )
    const Os_MpCfgType* currentAppMpCfg = NULL_PTR;
#endif

    /* Disable interrupt. */
    Os_Arch_IntDisable(&intState);

    if( TRUE == OS_APP_GETDELAYTIMING(trusFunCfg->ownerAppId) )
    {
        /* Timing proction delay start. */
    }

    if( OS_ISR_CAT2_TYPE_MASK == caller )
    {
        isrCfg = OS_ISR_GETCFG(OS_CORE_GETCURRENTISRID(coreId));
        currentAppId = OS_ISR_GETCURRENTAPPID(isrCfg);
        OS_ISR_SETCURRENTAPPID(isrCfg, trusFunCfg->ownerAppId);
#if( OS_MEMORY_PROTECTION == STD_ON )
        currentAppMpCfg = isrCfg->appMpCfg;
#endif
    }
    else if( OS_TASK_TYPE_MASK == caller )
    {
        taskCfg = OS_TASK_GETCFG(OS_CORE_GETCURRENTTASKID(coreId));
        currentAppId = OS_TASK_GETCURRENTAPPID(taskCfg);
        OS_TASK_SETCURRENTAPPID(taskCfg, trusFunCfg->ownerAppId);
#if( OS_MEMORY_PROTECTION == STD_ON )
        currentAppMpCfg = taskCfg->appMpCfg;
#endif
    }
    else
    {
        /* Do nothing. */
    }

#if( OS_MEMORY_PROTECTION == STD_ON )
    /* App memory protection switch Resume. */
    (void)Os_Mp_Switch(TRUE, trusFunCfg->appMpCfg);
#endif
    OS_CORE_SETAPPID(coreId, trusFunCfg->ownerAppId);
    /* Enable interrupt. */
    Os_Arch_IntEnable(intState);

    trusFunCfg->TFCallBack(functionIndex, functionParams);

    /* Disable interrupt. */
    Os_Arch_IntDisable(&intState);

    if( OS_ISR_CAT2_TYPE_MASK == caller )
    {
        OS_CORE_SETAPPID(coreId, currentAppId);
        OS_ISR_SETCURRENTAPPID(isrCfg, currentAppId);
    }
    else if( OS_TASK_TYPE_MASK == caller )
    {
        OS_CORE_SETAPPID(coreId, currentAppId);
        OS_TASK_SETCURRENTAPPID(taskCfg, currentAppId);
    }
    else
    {
        /* Do nothing. */
    }

#if( OS_MEMORY_PROTECTION == STD_ON )
    /* App memory protection switch Resume. */
    (void)Os_Mp_Switch(TRUE, currentAppMpCfg);
#endif
    if( OS_APP_GETDELAYTIMING(trusFunCfg->ownerAppId) == TRUE )
    {
        /* Timing proction delay stop. */
    }

    /* Enable interrupt. */
    Os_Arch_IntEnable(intState);
}

/*
********************************************************************************
* Function Name: Os_Call_TrustedFunction
*
* Explanation: Depends on called function. If called function is synchronous then
*              service is synchronous. May cause rescheduling.
*
* Param: functionIndex: Index of the function to be called.
*        functionParams: Pointer to the parameters for the function - specified
*        by the functionIndex - to be called. If no parameters are provided, a NULL
*        pointer has to be passed.
*
* Retval: E_OS_OK: No error.
*         E_OS_SERVICEID: Service can not be called.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_Call_TrustedFunction
(
    TrustedFunctionIndexType functionIndex,
    TrustedFunctionParameterRefType functionParams
)
{
    Os_StatusType ret;
    CoreIdType coreId;
    CoreIdType cfgCoreId;
    const Os_TrustedFunctionCfgType* trusFunCfg;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_CallTrustedFunction);
    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();

    if( NULL_PTR == functionParams )
    {
        ret = E_OS_PARAM_POINTER;
    }
    else if( OS_TRUSTEDFUNCTIONID_COUNT <= functionIndex )
    {
        ret = E_OS_SERVICEID;
    }
    else if( OS_CORE_MASK_INTERRUPT(coreId) ) /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_CALLTRUSTEDFUNCTION_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        trusFunCfg = OS_TRUSTFUN_GETCFG(functionIndex);
        cfgCoreId = OS_APP_GETCOREID(OS_APP_GETCFG(trusFunCfg->ownerAppId));

        if( cfgCoreId != coreId )
        {
            ret = E_OS_ACCESS;
        }
        else
        {
            if( OS_APP_STATEOFF(trusFunCfg->ownerAppId) )
            {
                ret = E_OS_ACCESS;
            }
            else
            {
                Os_CallTrustedFunctionSimp(functionIndex, functionParams, trusFunCfg);
                ret = E_OS_OK;
            }
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_CallTrustedFunction);

    return Os_Hook_CallErrorHook(OSServiceId_CallTrustedFunction, ret);
}
#endif

/*
********************************************************************************
* Function Name: CallTrustedFunction
*
* Explanation: Depends on called function. If called function is synchronous then
*              service is synchronous. May cause rescheduling.
*
* Param: FunctionIndex: Index of the function to be called.
*        FunctionParams: Pointer to the parameters for the function - specified
*        by the FunctionIndex - to be called. If no parameters are provided, a NULL
*        pointer has to be passed.
*
* Retval: E_OS_OK: No error.
*         E_OS_SERVICEID: Service can not be called.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) CallTrustedFunction
(
    TrustedFunctionIndexType FunctionIndex,
    TrustedFunctionParameterRefType FunctionParams
)
{
    StatusType ret;

#if( OS_CFG_TRUSTFUN == STD_ON )
#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_CallTrustedFunction.functionIndex = FunctionIndex;
    sysCallParam.Os_CallTrustedFunction.functionParams = FunctionParams;
    Os_SysCall(Os_Syscall_CallTrustedFunction_ID, &sysCallParam);
    ret = sysCallParam.Os_CallTrustedFunction.retVal;
#else
    ret = Os_Call_TrustedFunction(FunctionIndex, FunctionParams);
#endif
#else
    OS_DUMMY_STATEMENT(FunctionIndex);
    OS_DUMMY_STATEMENT(FunctionParams);

    ret = E_OS_OK;
#endif

    return ret;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

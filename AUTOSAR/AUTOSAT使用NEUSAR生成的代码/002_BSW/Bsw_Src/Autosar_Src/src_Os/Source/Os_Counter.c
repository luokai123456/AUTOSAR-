/*
********************************************************************************
*
*  File name: Os_Counter.c
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
* Author/Date: JiangGL/2022.11.23
* Change: Added Os_Counter_SetNextPoint interface.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: JiangGL/2022.11.25
* Change: Fix calling Os when HRT is not enabled Os_Counter_SetNextPoint
*         compilation error.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: HanCL/2023.1.12
* Change: Modify the GetElapsedValue and GetCounterValue interfaces to add
*         multi-core call functionality.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.1.29
* Change: Resolve the CallErrorHook privilege level problem.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: LiG/2023.5.26
* Change: Modifying GetCounterValue to cross core without obtaining a value.
* Cause: Bugfix
********************************************************************************
* Version: 3.8
* Author/Date: LiG/2023.5.27
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: JiangGL/2023.6.9
* Change: Solve the issue of setting expiration points for error reporting.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: LiG/2023.10.8
* Change: Shared counter direct access registers.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: JiangGL/2024.1.11
* Change: Fix a bug where the time parameter of the object driven by HRT cannot
*         exceed 1/2 of the maximum count value of the HRT.
* Cause: Bugfix
********************************************************************************
* Version: 3.12
* Author/Date: JiangGL/2024.1.25
* Change: 1. Add function achieve for Os_Counter_GetCurretExpList and
*         Os_Counter_ExpPointFind.
*         2. Delete the dependency on cntDyn.value when resetting the expiration
*         point Os_Counter_SetNextPoint.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: ZhangY/2023.10.07
* Change: Modify incorrect return value in API description in many functions.
* Cause: Optimization
********************************************************************************
* Version: 3.14
* Author/Date: ZhangY/2023.12.06
* Change: 1. Remove redundant initialization in Os_Counter_GetElapsedValue.
*         2. Modify Os_Counter_GetCounterValue and Os_Counter_GetElapsedValue,
*            to fix bug of getting wrong value in cross core situation.
* Cause: Bugfix
********************************************************************************
* Version: 3.15
* Author/Date: JiangGL/2024.1.11
* Change: Fix a bug where the time parameter of the object driven by HRT cannot
*         exceed 1/2 of the maximum count value of the HRT.
* Cause: Bugfix
********************************************************************************
* Version: 3.16
* Author/Date: JiangGL/2024.1.25
* Change: 1. Add function achieve for Os_Counter_GetCurretExpList and
*         Os_Counter_ExpPointFind;
*         2. Delete the dependency on cntDyn.value when resetting the expiration
*         point Os_Counter_SetNextPoint;
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: JiangGL/2024.2.27
* Change: Optimizing cross core calls to GetElapsedValue and GetCounterValue may
*         result in inaccurate data retrieval.
* Cause: Optimize
********************************************************************************
* Version: 3.18
* Author/Date: LiG/2024.5.6
* Change: Modify cross core error checking for Os_Counter_GetCounterValue and
*         Os_Counter_GetElapsedValue.
* Cause: Bugfix
********************************************************************************
* Version: 3.19
* Author/Date: LiG/2024.5.30
* Change: The problem of unpaired parentheses caused by adding switches.
* Cause: Bugfix
********************************************************************************
* Version: 3.20
* Author/Date: LiG/2024.10.17
* Change: Modifying coding standards issues.
* Cause: Optimize
********************************************************************************
* Version: 3.21
* Author/Date: ZhangY/2024.11.20
* Change: 1.Modify Os_Counter_SetExpPoint to fix bug of using incorrect queue in
*         condition of starting a ScheduleTable or a Alarm when counter reversal.
*         2.Add Os_Hrt_SetMaxCompare in OS_ISR(OS_HRT) to improve compatibility
*         with previous versions.
* Cause: Bugfix
********************************************************************************
* Version: 3.22
* Author/Date: LiuZB/2025.02.20
* Change: Optimize space size.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: LiuZB/2025.02.26
* Change: 1. Add function OsPitHook to function OS_PIT.
*         2. Add function OsHrtHook to function OS_HRT.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Cfg.h"
#include "Os_Counter.h"
#include "Os_Core.h"
#include "Os_Arch_Mach_Timer.h"
#include "Os_Isr.h"
#include "Os_Alarm.h"
#include "Os_App.h"
#include "Os_SysCall.h"
#include "Os_Hook.h"
#include "Os_SchdTb.h"
#include "Os_Orti.h"
#include "Os_MultiCore.h"
#include "Os.h"

#ifdef VCU_Test_Code_YXP
#include "Interface_Test_IO.h"
#endif

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/* Check that the Counter value is valid. */
#define OS_COUNTER_VALUE_VALID(cntCfg, value) ((value) <= (cntCfg)->maxAllowValue)

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
#define OS_START_SEC_CONST
#include "Os_MemMap.h"

/* List of expiration point work functions. */
static CONST(Os_CntExpWorkFuncType, OS_CONST) Os_CntExpWorkFunc[OS_CNTEXP_WORKFUNCNUM] =
{
    Os_Alarm_ActActivateTask,
#if(  OS_CFG_EVENT_ENABLE == STD_ON  )
    Os_Alarm_ActSetEvent,
#endif /* OS_CFG_EVENT_ENABLE == STD_ON */
    Os_Alarm_ActIcrmCnt,
    Os_Alarm_ActCallback,
#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    Os_SchdTb_ActStandardExe,
    Os_SchdTb_ActSyncExe,
    Os_SchdTb_ActCyclicExe,
    Os_SchdTb_ActSingleExe
#endif /* OS_CFG_SCHDTB_ENABLE == STD_ON */
};

#define OS_STOP_SEC_CONST
#include "Os_MemMap.h"

/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_Counter_WorkFunc
(
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) cntExpList,
    P2VAR(uint8, AUTOMATIC, OS_APPL_DATA) setNextPointFlag
);
LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_Counter_GetQueueData
(
    P2CONST(Os_CntExpListCfgType, AUTOMATIC, OS_APPL_CONST) cntExpList,
    P2VAR(Os_TickType, AUTOMATIC, OS_APPL_DATA) expTimebase
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
* Function Name: Os_Counter_WorkFunc
*
* Explanation: Internal function to call counter work function.
*
* Param: cntExpList: Counter expiry point list.
*
* Retval: E_OS_OK: No error.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
********************************************************************************
*/
LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_Counter_WorkFunc
(
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) cntExpList,
    P2VAR(uint8, AUTOMATIC, OS_APPL_DATA) setNextPointFlag
)
{
    Os_StatusType ret = E_OS_OK;
    Os_CntExpWorkFuncType func;

    if( cntExpList != NULL_PTR )
    {
        func = Os_CntExpWorkFunc[cntExpList->expKind];
        *setNextPointFlag = func(cntExpList);
    }
    else
    {
        ret = E_OS_PARAM_POINTER;
        *setNextPointFlag = OS_COUNTER_NOTSET_POINT;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Counter_GetQueueData
*
* Explanation: Internal function to get queue data.
*
* Param: cntExpList: Counter expiry point list.
*        expTimebase: Expiry point data to get.
*
* Retval: E_OS_OK: No error.
*         E_OS_BUFFEMPTY: Queue is empty.
********************************************************************************
*/
LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_Counter_GetQueueData
(
    P2CONST(Os_CntExpListCfgType, AUTOMATIC, OS_APPL_CONST) cntExpList,
    P2VAR(Os_TickType, AUTOMATIC, OS_APPL_DATA) expTimebase
)
{
    Os_StatusType ret = E_OS_OK;
    uint8 cntExpListCnt;

    /* Get expiration point. */
    cntExpListCnt = cntExpList->cntExplistMux;
    if( OS_PRIQUEUEISNOTEMPTY((cntExpList->cntExpList[cntExpListCnt])) )
    {
        *expTimebase = OS_GETPRIQUEUE_VALUE((cntExpList->cntExpList[cntExpListCnt]));
    }
    else if( OS_PRIQUEUEISNOTEMPTY((cntExpList->cntExpList[(cntExpListCnt + OS_COUNTER_VALUE_ONE) & OS_COUNTER_EXPLISTMAX])) )
    {
        *expTimebase = OS_GETPRIQUEUE_VALUE((cntExpList->cntExpList[(cntExpListCnt + OS_COUNTER_VALUE_ONE) & OS_COUNTER_EXPLISTMAX]));
    }
    else
    {
        ret = E_OS_BUFFEMPTY;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Counter_GetCntValue
*
* Explanation: Internal function to get counter value.
*
* Param: cntBaseCfg: Counter base configuration.
*
* Retval: Tick value.
********************************************************************************
*/
FUNC(Os_TickType, OS_CODE) Os_Counter_GetCntValue
(
    P2CONST(Os_CounterBaseCfgType, AUTOMATIC, OS_APPL_CONST) cntBaseCfg
)
{
    Os_TickType value = OS_COUNTER_INIT;

    if( OS_COUNTER_SW == cntBaseCfg->counterType )/* If the counter is software counter. */
    {
        value = ((Os_CounterSwCfgType*)(cntBaseCfg))->counterDyn->value;
    }
#if( OS_HRT_ENABLE == STD_ON )
     /* If the counter is HRT. */
    else if( OS_COUNTER_HRT == cntBaseCfg->counterType )
    {
        value = Os_Arch_Mach_HrtTimerGetValue(((const Os_CounterHrtCfgType*)cntBaseCfg)->HwConfig);
    }
#endif

#if( OS_PIT_ENABLE == STD_ON )
    else if( OS_COUNTER_PIT == cntBaseCfg->counterType ) /* If the counter is pit. */
    {
        value = ((const Os_CounterPitCfgType*)(cntBaseCfg))->counterDyn->value;
    }
#endif
    else
    {
        /* Nothing to do. */
    }

    return value;
}

/*
********************************************************************************
* Function Name: Os_Counter_IncrementCounter
*
* Explanation: Uses to increments a software counter.
*
* Param: counterId: The Counter to be incremented.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid counterId.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Counter_IncrementCounter(CounterType counterId)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    const Os_CounterBaseCfgType* counterBaseCfg;
    Os_Arch_IntState intState;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_IncrementCounter);
    /* Get logic core id */
    coreId = Os_Core_GetLogicId();

    if( counterId >= OS_COUNTERID_COUNT ) /* If task id in the range. */
    {
        ret = E_OS_ID;
    }
    else if( OS_CORE_MASK_INTERRUPT(coreId) ) /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_INCREMENTCNT_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        /* Get counter configuration data. */
        counterBaseCfg = OS_COUNTER_GETCFG(counterId);

        if( counterBaseCfg->coreId != coreId ) /* If the counter is not the same core. */
        {
            ret = E_OS_CORE;
        }
        else if( OS_APPMATCH(counterBaseCfg->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission. */
        {
            ret = E_OS_ACCESS;
        }
        else if( OS_APP_STATEOFF(counterBaseCfg->ownerAppId) ) /* If the application is not accessible. */
        {
            ret = E_OS_ACCESS;
        }
        else if( counterBaseCfg->counterType != OS_COUNTER_SW ) /* If the counter is not the software counter. */
        {
            ret = E_OS_ID;
        }
        else
        {
            /* Disable interrupt. */
            Os_Arch_IntDisable(&intState);
            (void)Os_Counter_IcrmCnt(counterBaseCfg, OS_COUNTER_GETDYN(counterBaseCfg, const Os_CounterSwCfgType*));
            /* Enable interrupt. */
            Os_Arch_IntEnable(intState);
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_IncrementCounter);

    return Os_Hook_CallErrorHook(OSServiceId_IncrementCounter, ret);
}

/*
********************************************************************************
* Function Name: Os_Counter_GetCounterValue
*
* Explanation: Uses to read the current count value of a counter.
*
* Param: counterId: The Counter to be incremented.
*        value: Contains the current tick value of the counter.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid counterId.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Counter_GetCounterValue(CounterType counterId, TickRefType value)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    const Os_CounterBaseCfgType* counterBaseCfg;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_GetCounterValue);
    /* Get logic core id */
    coreId = Os_Core_GetLogicId();

    if( counterId >= OS_COUNTERID_COUNT ) /* If task id in the range. */
    {
        ret = E_OS_ID;
    }
    else if( NULL_PTR == value )
    {
        ret = E_OS_PARAM_POINTER;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_GETCNTVALUE_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        /* Get counter configuration data. */
        counterBaseCfg = OS_COUNTER_GETCFG(counterId);

        if( OS_APPMATCH(counterBaseCfg->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission */
        {
            ret = E_OS_ACCESS;
        }
        else
        {
#if( OS_CFG_MULTI_CORE == STD_ON )
            if( (counterBaseCfg->coreId == coreId) || (TRUE == counterBaseCfg->share) ) /* If the counter is the same core or the counter is shared. */
#endif /* OS_CFG_MULTI_CORE == STD_ON */
            {
                if( OS_APP_STATEOFF(counterBaseCfg->ownerAppId) ) /* If the application is not accessible. */
                {
                    ret = E_OS_ACCESS;
                }
                else
                {
                    /* Get timer value. */
                    *value = Os_Counter_GetCntValue(counterBaseCfg);
                }
            }
#if( OS_CFG_MULTI_CORE == STD_ON )
            else
            {
                /* Get Counter base of target core. */
                Os_MultiCoreServeParamType parameter;

                parameter.Os_GetCounterValue.counterId = counterId;
                /* Execute multi-core calling function. */
                ret = Os_MultiCore_Trigger(TRUE, coreId, counterBaseCfg->coreId,
                                        Os_MCServe_GetCounterValue_ID, &parameter);
                if( E_OS_OK == ret )
                {
                    *value = parameter.Os_GetCounterValue.value;
                }
            }
#endif /* OS_CFG_MULTI_CORE == STD_ON */
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_GetCounterValue);

    return Os_Hook_CallErrorHook(OSServiceId_GetCounterValue, ret);
}

/*
********************************************************************************
* Function Name: Os_Counter_GetElapsedValue
*
* Explanation: Uses to get the number of ticks between the current tick value and
*              a previously read tick value.
*
* Param: counterId: The Counter to be incremented.
*        value: the previously read tick value of the counter.
*        elapsedValue:the current tick value of the counter.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid counterId.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
*         E_OS_CORE: Core is not available.
*         E_OS_VALUE: The value is greater the the maximum value of counter.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Counter_GetElapsedValue
(
    CounterType counterId,
    TickRefType value,
    TickRefType elapsedValue
)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    Os_TickType localValue;
    const Os_CounterBaseCfgType* counterBaseCfg;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_GetElapsedValue);
    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();

    if( counterId >= OS_COUNTERID_COUNT ) /* If task id in the range. */
    {
        ret = E_OS_ID;
    }
    else if( (NULL_PTR == value) || (NULL_PTR == elapsedValue) )
    {
        ret = E_OS_PARAM_POINTER;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_GETELAPSEDVALUE_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        /* Get counter configuration data. */
        counterBaseCfg = OS_COUNTER_GETCFG(counterId);

        if( OS_APPMATCH(counterBaseCfg->accessingApps, OS_CORE_GETAPPID(coreId)) ) /* If the application does not have permission. */
        {
            ret = E_OS_ACCESS;
        }
        else if( OS_COUNTER_VALUE_VALID(counterBaseCfg, *value) )
        {
#if( OS_CFG_MULTI_CORE == STD_ON )
            if( (counterBaseCfg->coreId == coreId) || (TRUE == counterBaseCfg->share) ) /* If the counter is the same core or the counter is shared. */
#endif /* OS_CFG_MULTI_CORE == STD_ON */
            {
                if( OS_APP_STATEOFF(counterBaseCfg->ownerAppId) ) /* If the application is not accessible. */
                {
                    ret = E_OS_ACCESS;
                }
                else
                {
                    /* Get timer value. */
                    localValue = Os_Counter_GetCntValue(counterBaseCfg);
                    *elapsedValue = OS_COUNTER_TICKSUB(counterBaseCfg, localValue, *value);
                    *value = localValue;
                }
            }
#if( OS_CFG_MULTI_CORE == STD_ON )
            else
            {
                /* Get counter base of target core. */
                Os_MultiCoreServeParamType parameter;

                parameter.Os_GetCounterValue.counterId = counterId;
                /* Execute multi-core calling function. */
                ret = Os_MultiCore_Trigger(TRUE, coreId, counterBaseCfg->coreId,
                                           Os_MCServe_GetCounterValue_ID, &parameter);
                localValue = (Os_TickType)parameter.Os_GetCounterValue.value;
                if( E_OS_OK == ret )
                {
                    *elapsedValue = OS_COUNTER_TICKSUB(counterBaseCfg, localValue, *value);
                    *value = localValue;
                }
            }
#endif /* OS_CFG_MULTI_CORE == STD_ON */
        }
        else
        {
            ret = E_OS_VALUE;
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_GetElapsedValue);

    return Os_Hook_CallErrorHook(OSServiceId_GetElapsedValue, ret);
}

/*
********************************************************************************
* Function Name: Os_Counter_IcrmCnt
*
* Explanation: Increments a software counter, Used to implement alarm action
*              IncrementCounter.
*
* Param: counterBaseCfg: Counter base configuration.
*        counterDyn: Reference to the alarm configuration.
*
* Retval: E_OS_OK: No error.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
*         E_OS_BUFFEMPTY: Queue is empty.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Counter_IcrmCnt
(
    P2CONST(Os_CounterBaseCfgType, AUTOMATIC, OS_APPL_CONST) counterBaseCfg,
    P2VAR(Os_CounterSwDynType, AUTOMATIC, OS_APPL_DATA) counterDyn
)
{
    Os_StatusType ret;
    Os_TickType expTimebase = 0U;
    Os_CntExpListNodeCfgType* expListNode;
    uint8 setNextPointFlag = OS_COUNTER_NOTSET_POINT;

    if( (counterBaseCfg != NULL_PTR) && (counterDyn != NULL_PTR) )
    {
        /* Incremen the value. */
        counterDyn->value++;
        if( counterDyn->value > counterBaseCfg->maxAllowValue )
        {
            counterDyn->value = OS_COUNTER_INIT;
        }

        ret = Os_Counter_GetQueueData(counterBaseCfg->Os_CntExpList, &expTimebase);
        while( (counterDyn->value == expTimebase) && ((ret != E_OS_BUFFEMPTY)) )
        {
            /* Pop the expiration point. */
            (void)Os_Counter_ExpListPop(counterBaseCfg, &expListNode);
            /* Perform expiry action. */
            (void)Os_Counter_WorkFunc(expListNode, &setNextPointFlag);
            ret = Os_Counter_GetQueueData(counterBaseCfg->Os_CntExpList, &expTimebase);
        }
    }
    else
    {
        ret = E_OS_PARAM_POINTER;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Counter_Init
*
* Explanation: Initialize the counter object.
*
* Param: counterId: Reference to the counter id.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Counter_Init
(
    P2CONST(Os_CounterBaseCfgType, AUTOMATIC, OS_APPL_CONST) cntBaseCfg
)
{
    if( NULL_PTR != cntBaseCfg )
    {
        /* If the counter's Os_CntExpList is not NULL. */
        if( NULL_PTR != cntBaseCfg->Os_CntExpList )
        {
            /* Initialize the queue. */
            cntBaseCfg->Os_CntExpList->cntExplistMux = OS_COUNTER_INIT;
            Os_PriQueue_Init(&cntBaseCfg->Os_CntExpList->cntExpList[OS_COUNTER_INIT]);
            Os_PriQueue_Init(&cntBaseCfg->Os_CntExpList->cntExpList[OS_COUNTER_VALUE_ONE]);
        }

        /* If the counter is SW. */
        if( OS_COUNTER_SW == cntBaseCfg->counterType )
        {
            Os_CounterSwDynType* cntDyn;
            /* Get counter running data. */
            cntDyn = OS_COUNTER_GETDYN(cntBaseCfg, const Os_CounterSwCfgType*);
            /* Initialize counter value. */
            cntDyn->value = OS_COUNTER_INIT;
            /* Initialize counter last value. */
            cntDyn->lastValue = OS_COUNTER_INIT;
        }
#if( OS_HRT_ENABLE == STD_ON )
        else if( OS_COUNTER_HRT == cntBaseCfg->counterType )    /* If the counter is HRT. */
        {
            /* Call the driver to initialize the hardware. */
            Os_Arch_Mach_HrtTimerInit(((const Os_CounterHrtCfgType*)cntBaseCfg)->HwConfig);
        }
#endif

#if( OS_PIT_ENABLE == STD_ON )
        else if( OS_COUNTER_PIT == cntBaseCfg->counterType )    /* If the counter is PIT. */
        {
            Os_CounterSwDynType* cntDyn;
            /* Get counter running data. */
            cntDyn = OS_COUNTER_GETDYN(cntBaseCfg, const Os_CounterPitCfgType*);
            /* Initialize counter value. */
            cntDyn->value = OS_COUNTER_INIT;
            /* Initialize counter last value. */
            cntDyn->lastValue = OS_COUNTER_INIT;
            /* Call the driver to initialize the hardware. */
            Os_Arch_Mach_PitTimerInit(((const Os_CounterPitCfgType*)cntBaseCfg)->HwConfig);
        }
#endif
        else
        {
            /* Nothing to do. */
        }
    }
}

/*
********************************************************************************
* Function Name: Os_Counter_Start
*
* Explanation: uses to start counter.
*
* Param: counterId: Reference to the counter id.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Counter_Start
(
    P2CONST(Os_CounterBaseCfgType, AUTOMATIC, OS_APPL_CONST) cntBaseCfg
)
{
    if( NULL_PTR != cntBaseCfg  )
    {
        #ifdef VCU_Test_Code_YXP
        //测试代码
        switch( cntBaseCfg->counterId )
        {
            case SYSTEMTIMER_CORE0:
                Test_SetIO_Status_LS9(1);
                break;

            case SYSTEMTIMER_CORE1:
                Test_SetIO_Status_LS10(1);
                break;

            case SYSTEMTIMER_CORE2:
                // Test_SetIO_Status_LS11(1);
                break;

            case SYSTEMTIMER_CORE3:
                Test_SetIO_Status_LS11(1);
                break;

            case SYSTEMTIMER_CORE4:
                // Test_SetIO_Status_LS12(1);
                break;
            
            case SYSTEMTIMER_CORE5:
                Test_SetIO_Status_LS12(1);
                break;

            default:
                break;
        }
        #endif
        

#if( OS_HRT_ENABLE == STD_ON )
        if( OS_COUNTER_HRT == cntBaseCfg->counterType )
        {
            /* Call the driver to initialize the hardware. */
            Os_Arch_Mach_HrtTimerStart(((const Os_CounterHrtCfgType*)cntBaseCfg)->HwConfig);
        }
        else
#endif

#if( OS_PIT_ENABLE == STD_ON )
        if( OS_COUNTER_PIT == cntBaseCfg->counterType )
        {
            /* Call the driver to initialize the hardware. */
            Os_Arch_Mach_PitTimerStart(((const Os_CounterPitCfgType*)cntBaseCfg)->HwConfig);
        }
        else
#endif
        {
            /* Nothing to do. */
        }
    }
}

#if( OS_HRT_ENABLE == STD_ON )
/*
********************************************************************************
* Function Name: Os_Hrt_SetMaxCompare
*
* Explanation: Set max compare value.
*
* Param: hrtCnt: Time protection counter.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_Hrt_SetMaxCompare
(
    P2CONST(Os_CounterBaseCfgType, AUTOMATIC, OS_APPL_CONST) hrtCnt
)
{
    Os_TickType nowValue;
    Os_TickType compareValue;

    nowValue = Os_Counter_HrtGetCntValue(hrtCnt);
    compareValue = OS_COUNTER_TICKADD(hrtCnt, nowValue, OS_COUNTER_GET_MAXVALUE(hrtCnt));
    Os_Counter_HrtSetCompareValue(hrtCnt, compareValue, nowValue);
}
#endif /* OS_HRT_ENABLE == STD_ON */

/*
********************************************************************************
* Function Name: Os_Counter_SetNextPoint
*
* Explanation: Set next point expiration point node.
*
* Param: counterBase: Reference to the counter expiration point list configuration.
*        start: Calculate the start time of the next expiration point.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Counter_SetNextPoint
(
    P2CONST(Os_CounterBaseCfgType, AUTOMATIC, OS_APPL_CONST) counterBase,
    Os_TickType start
)
{
#if( OS_HRT_ENABLE == STD_ON )
    Os_CntExpListCfgType* cntExpListHead;

    cntExpListHead = counterBase->Os_CntExpList;
    if( OS_COUNTER_HRT == counterBase->counterType )
    {
        Os_StatusType ret;
        boolean setCmp = FALSE;
        Os_TickType expTimebase;
        Os_CounterSwDynType* cntDyn;

        /* Get counter running data. */
        cntDyn = OS_COUNTER_GETDYN(counterBase, const Os_CounterHrtCfgType*);

        ret = Os_Counter_GetQueueData(cntExpListHead, &expTimebase);
        if( ret != E_OS_BUFFEMPTY )
        {
            /* Set new comparison value. */
            cntDyn->value = expTimebase;
            setCmp = TRUE;
        }
        if( TRUE == setCmp )
        {
            Os_Counter_HrtSetCompareValue(counterBase, cntDyn->value, start);
        }
        else
        {
            cntDyn->value = OS_COUNTER_INIT;
            /* There is no next expiration point to set, the maximum Compare value will be set. */
            Os_Hrt_SetMaxCompare(counterBase);
        }
    }
#else
    OS_DUMMY_STATEMENT(counterBase);
#endif /*( OS_HRT_ENABLE == STD_ON )*/
}

/*
********************************************************************************
* Function Name: Os_Counter_SetExpPoint
*
* Explanation: Insert node to the counter expiration point list.
*
* Param: cntExpList: Reference to the counter expiration point list configuration.
*        start: Calculate the start time of the next expiration point.
*        offset: Offset time for the next expiration point.
*        expNode: counter expiration point node.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Counter_SetExpPoint
(
    P2CONST(Os_CounterBaseCfgType, AUTOMATIC, OS_APPL_CONST) counterBase,
    Os_TickType start,
    Os_TickType offset,
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) expListNode
)
{
#if( OS_HRT_ENABLE == STD_ON )
    boolean ifCheak;
#endif
    uint8 cntExpListCnt;
    Os_TickType setExpTimebase;
    Os_CntExpListCfgType* cntExpListHead;

    cntExpListHead = counterBase->Os_CntExpList;
    if( (counterBase->maxAllowValue - start) >= offset )
    {
        cntExpListCnt = cntExpListHead->cntExplistMux;
        setExpTimebase = (start + offset);
#if( OS_HRT_ENABLE == STD_ON )
        ifCheak = TRUE;
#endif
        if( (OS_PRIQUEUEISNOTEMPTY((cntExpListHead->cntExpList[(cntExpListCnt + OS_COUNTER_VALUE_ONE) & OS_COUNTER_EXPLISTMAX])))
            && (cntExpListHead->cntExpList[cntExpListCnt].priQueueUseCounter == OS_PRIQUEUE_INIT) )
        {
            Os_TickType expTimebaseLatest;

            (void)Os_Counter_GetQueueData(cntExpListHead, &expTimebaseLatest);
            if( start < expTimebaseLatest )
            {
                cntExpListCnt = (uint8)((cntExpListHead->cntExplistMux + OS_COUNTER_VALUE_ONE) & OS_COUNTER_EXPLISTMAX);
            }
        }
    }
    else
    {
        cntExpListCnt = (uint8)((cntExpListHead->cntExplistMux + OS_COUNTER_VALUE_ONE) & OS_COUNTER_EXPLISTMAX);
        setExpTimebase = offset - (counterBase->maxAllowValue - start + OS_COUNTER_VALUE_ONE);
#if( OS_HRT_ENABLE == STD_ON )
        ifCheak = FALSE;
#endif
    }
    expListNode->expTimestamp.timebase = setExpTimebase;
    (void)Os_PriQueue_PUSH(&(cntExpListHead->cntExpList[cntExpListCnt]), (Os_PriQueueNodeType*)expListNode);

#if( OS_HRT_ENABLE == STD_ON )
    /* If the counter is HRT. */
    if( OS_COUNTER_HRT == counterBase->counterType )
    {
        Os_StatusType ret;
        boolean setCmp = FALSE;
        Os_TickType expTimebase;
        Os_CounterSwDynType* cntDyn;

        /* Get counter running data. */
        cntDyn = OS_COUNTER_GETDYN(counterBase, const Os_CounterHrtCfgType*);
        /* Check if the compare value is zero. */
        if( OS_COUNTER_INIT == cntDyn->value )
        {
            ret = Os_Counter_GetQueueData(cntExpListHead, &expTimebase);
            if( ret != E_OS_BUFFEMPTY )
            {
                /* Set new comparison value. */
                cntDyn->value = expTimebase;
                setCmp = TRUE;
            }
        }
        else
        {
            /* Whether a new comparison value needs to be calculated. */
            if( (TRUE == ifCheak) && (cntDyn->value > setExpTimebase) )
            {
                /* Set new comparison value. */
                cntDyn->value = setExpTimebase;
                setCmp = TRUE;
            }
        }
        if( TRUE == setCmp )
        {
            Os_Counter_HrtSetCompareValue(counterBase, cntDyn->value, start);
        }
    }
    else /* If the counter is software counter. */
#endif
    {
        /* Nothing to do. */
    }
}

/*
********************************************************************************
* Function Name: Os_Counter_ExpListTopGet
*
* Explanation: Get top node of the counter expiration point list.
*
* Param: cntExpList: Reference to the counter expiration point list configuration.
*
* Retval: E_OS_OK: No error.
*         E_OS_BUFFEMPTY: Queue is empty.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Counter_ExpListPop
(
    P2CONST(Os_CounterBaseCfgType, AUTOMATIC, OS_APPL_CONST) counterBase,
    P2VAR(Os_CntExpListNodeCfgType*, AUTOMATIC, OS_APPL_DATA) expListNode
)
{
    Os_StatusType ret;
    uint8 cntExpListCnt;
    Os_CntExpListCfgType* cntExpListHead;

    cntExpListHead = counterBase->Os_CntExpList;
    cntExpListCnt = cntExpListHead->cntExplistMux;


    ret = Os_PriQueue_POP(&(cntExpListHead->cntExpList[cntExpListCnt]), (Os_PriQueueNodeType**)expListNode);
    /* If the current queue is not empty. */
    if( E_OS_BUFFEMPTY == ret )
    {
        cntExpListHead->cntExplistMux = (uint8)((cntExpListHead->cntExplistMux + OS_COUNTER_VALUE_ONE) & OS_COUNTER_EXPLISTMAX);
        cntExpListCnt = cntExpListHead->cntExplistMux;
        ret = Os_PriQueue_POP(&(cntExpListHead->cntExpList[cntExpListCnt]), (Os_PriQueueNodeType**)expListNode);
    }

#if( OS_HRT_ENABLE == STD_ON )
    /* If the counter is HRT. */
    if( OS_COUNTER_HRT == counterBase->counterType )
    {
        Os_CounterSwDynType* cntDyn;

        /* Get counter running data. */
        cntDyn = OS_COUNTER_GETDYN(counterBase, const Os_CounterHrtCfgType*);
        /* Clear compare value. */
        cntDyn->value = OS_COUNTER_INIT;
    }
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Counter_GetCurretExpList
*
* Explanation: Obtain the expiration point node that is about to be triggered.
*
* Param: cntExpList: Reference to the counter expiration point list configuration.
*        expNode: counter expiration point node.
*
* Retval: E_OS_OK: No error.
*         E_OS_BUFFEMPTY: Queue is empty.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Counter_GetCurretExpList
(
    P2CONST(Os_CounterBaseCfgType, AUTOMATIC, OS_APPL_CONST) counterBase,
    P2VAR(Os_CntExpListNodeCfgType*, AUTOMATIC, OS_APPL_DATA) expListNode
)
{
    Os_StatusType ret = E_OS_OK;
    Os_PriQueueType* priQueue;
    uint8 cntExpListCnt;
    Os_CntExpListCfgType* cntExpListHead;

    cntExpListHead = counterBase->Os_CntExpList;
    cntExpListCnt = cntExpListHead->cntExplistMux;

    /* Get counter priQueue. */
    priQueue = &(cntExpListHead->cntExpList[cntExpListCnt]);
    /* Check if the queue is empty. */
    if( OS_PRIQUEUE_INIT == priQueue->priQueueUseCounter )
    {
        /* Get the other half of the queue. */
        cntExpListCnt = (uint8)((cntExpListCnt + OS_COUNTER_VALUE_ONE) & OS_COUNTER_EXPLISTMAX);
        priQueue = &(cntExpListHead->cntExpList[cntExpListCnt]);
        /* Check if the queue is empty. */
        if( OS_PRIQUEUE_INIT == priQueue->priQueueUseCounter )
        {
            ret = E_OS_BUFFEMPTY;
        }
    }

    if( E_OS_OK == ret )
    {
        /* Obtain the expiration point node that is about to be triggered. */
        *expListNode = (Os_CntExpListNodeCfgType*)(priQueue->priQueueNode[OS_PRIQUEUE_INIT]);
    }
    else
    {
        *expListNode = NULL_PTR;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Counter_ExpPointDel
*
* Explanation: Delete given node of the counter expiration point list.
*
* Param: cntExpList: Reference to the counter expiration point list configuration.
*        expNode: counter expiration point node.
*
* Retval: E_OS_OK: No error.
*         E_OS_NODATA: Queue buffer is empty.
*         E_OS_BUFFEMPTY: Queue buffer is full.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Counter_ExpPointDel
(
    P2CONST(Os_CounterBaseCfgType, AUTOMATIC, OS_APPL_CONST) counterBase,
    P2CONST(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_CONST) expListNode
)
{
    Os_StatusType ret;
    uint8 cntExpListCnt;
    Os_CntExpListCfgType* cntExpListHead;

    cntExpListHead = counterBase->Os_CntExpList;
    cntExpListCnt = cntExpListHead->cntExplistMux;

    ret = Os_PriQueue_Del(&(cntExpListHead->cntExpList[cntExpListCnt]), (Os_PriQueueNodeType*)expListNode);

    if( (E_OS_NODATA == ret) || (E_OS_BUFFEMPTY == ret) )
    {
        cntExpListCnt = (uint8)((cntExpListHead->cntExplistMux + OS_COUNTER_VALUE_ONE) & OS_COUNTER_EXPLISTMAX);
        if( E_OS_NODATA == Os_PriQueue_Del(&(cntExpListHead->cntExpList[cntExpListCnt]),
                                            (Os_PriQueueNodeType*)expListNode))
        {
            ret = E_OS_NODATA;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Counter_ExpPointFind
*
* Explanation: Determine if there is a target node in the queue.
*
* Param: cntExpList: Reference to the counter expiration point list configuration.
*        expNode: counter expiration point node.
*
* Retval: E_OS_OK: No error.
*         E_OS_NODATA: Queue buffer is empty.
*         E_OS_BUFFEMPTY: Queue buffer is full.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Counter_ExpPointFind
(
    P2CONST(Os_CounterBaseCfgType, AUTOMATIC, OS_APPL_CONST) counterBase,
    P2CONST(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_CONST) expListNode
)
{
    Os_StatusType ret;
    uint8 cntExpListCnt;
    Os_CntExpListCfgType* cntExpListHead;

    cntExpListHead = counterBase->Os_CntExpList;
    cntExpListCnt = cntExpListHead->cntExplistMux;

    ret = Os_PriQueue_Find(&(cntExpListHead->cntExpList[cntExpListCnt]), (Os_PriQueueNodeType*)expListNode);

    if( (E_OS_NODATA == ret) || (E_OS_BUFFEMPTY == ret) )
    {
        cntExpListCnt = (uint8)((cntExpListHead->cntExplistMux + OS_COUNTER_VALUE_ONE) & OS_COUNTER_EXPLISTMAX);
        if( E_OS_NODATA == Os_PriQueue_Find(&(cntExpListHead->cntExpList[cntExpListCnt]),
                                            (Os_PriQueueNodeType*)expListNode))
        {
            ret = E_OS_NODATA;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Counter_InsertAbsExpPoint
*
* Explanation: Insert absolute counter expiration point.
*
* Param: cntExpList: Reference to the counter expiration point list configuration.
*        expListNode: counter expiration point node.
*        start: start value.
*
* Retval: E_OS_OK: No error.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Counter_InsertAbsExpPoint
(
    P2CONST(Os_CounterBaseCfgType, AUTOMATIC, OS_APPL_CONST) counterBase,
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) expListNode,
    Os_TickType start
)
{
    Os_StatusType ret = E_OS_OK;
    Os_TickType value;
    Os_TickType diff;

    if( counterBase != NULL_PTR )
    {
        /* Get timer value. */
        value = Os_Counter_GetCntValue(counterBase);
        /* If the start point is not overflows. */
        if( start > value)
        {
            diff = (start - value);
        }
        else
        {
            diff = (start + (counterBase->maxAllowValue - value + OS_COUNTER_VALUE_ONE));
        }
        /* Inser expiry point to priority queue. */
        Os_Counter_SetExpPoint(counterBase, value, diff, expListNode);
    }
    else
    {
        ret = E_OS_PARAM_POINTER;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Counter_InsertExpPoint
*
* Explanation: Uses to insert relative counter expiration point.
*
* Param: cntExpList: Reference to the counter expiration point list configuration.
*        expListNode: counter expiration point node.
*        increment: relative value.
*
* Retval: E_OS_OK: No error.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Counter_InsertExpPoint
(
    P2CONST(Os_CounterBaseCfgType, AUTOMATIC, OS_APPL_CONST) counterBase,
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) expListNode,
    Os_TickType increment
)
{
    Os_StatusType ret = E_OS_OK;
    Os_TickType value;

    if( counterBase != NULL_PTR )
    {
        /* Get timer value. */
        value = Os_Counter_GetCntValue(counterBase);
        /* Inser expiry point to priority queue. */
        Os_Counter_SetExpPoint(counterBase, value, increment, expListNode);
    }
    else
    {
        ret = E_OS_PARAM_POINTER;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Counter_GeBase
*
* Explanation: Uses to get counter bace configuration.
*
* Param: counterBase: Counter base configuration.
*        info: Counter information to get.
*
* Retval: E_OS_OK: No error.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Counter_GetBase
(
    P2CONST(Os_CounterBaseCfgType, AUTOMATIC, OS_APPL_CONST) counterBase,
    AlarmBaseRefType info
)
{
    Os_StatusType ret = E_OS_OK;

    if( (counterBase != NULL_PTR) && (info != NULL_PTR) )
    {
        info->maxallowedvalue = counterBase->maxAllowValue;
        info->mincycle = counterBase->minCycle;
        info->ticksperbase = counterBase->ticksPerBase;
    }
    else
    {
        ret = E_OS_PARAM_POINTER;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Counter_GetExpTick
*
* Explanation: Uses to get expiration point.
*
* Param: cntExpList: Reference to the counter expiration point list configuration.
*        expListNode: counter expiration point node.
*        tick: Expiration point tick.
*
* Retval: E_OS_OK: No error.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Counter_GetExpTick
(
    P2CONST(Os_CounterBaseCfgType, AUTOMATIC, OS_APPL_CONST) counterBase,
    P2CONST(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_CONST) expListNode,
    TickRefType tick
)
{
    Os_StatusType ret = E_OS_OK;
    Os_TickType value;

    if( (counterBase != NULL_PTR) && (tick != NULL_PTR) )
    {
        /* Get timer value. */
        value = Os_Counter_GetCntValue(counterBase);
        /* If the expiration point is not overflows. */
        *tick = (expListNode->expTimestamp.timebase - value);
        if( value > expListNode->expTimestamp.timebase )
        {
            *tick += (counterBase->maxAllowValue + OS_COUNTER_VALUE_ONE);
        }
    }
    else
    {
        ret = E_OS_PARAM_POINTER;
    }

    return ret;
}

#if( OS_CFG_MULTI_CORE == STD_ON )
/*
********************************************************************************
* Function Name: Os_Counter_TargetGetCounterValue
*
* Explanation: Multicore function to read the current count value of a counter.
*
* Param: counterId: The Counter to be incremented.
*        value: Contains the current tick value of the counter.
*
* Retval: E_OS_OK: No error.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Counter_TargetGetCounterValue
(
    CounterType counterId,
    TickRefType value
)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    const Os_CounterBaseCfgType* counterBaseCfg;

    /* Get counter configuration data. */
    counterBaseCfg = OS_COUNTER_GETCFG(counterId);
    /* Get the current logical core id. */
    coreId = Os_Core_GetLogicId();

    if( OS_APP_STATEOFF(counterBaseCfg->ownerAppId) ) /* If the application is not accessible. */
    {
        ret = E_OS_ACCESS;
    }
    else if( coreId != counterBaseCfg->coreId )
    {
        ret = E_OS_CORE;
    }
    else
    {
        /* Get timer value. */
        *value = Os_Counter_GetCntValue(counterBaseCfg);
    }

    return ret;
}
#endif /* OS_CFG_MULTI_CORE == STD_ON */

#if( OS_PIT_ENABLE == STD_ON )
/*
********************************************************************************
* Function Name: OS_PIT
*
* Explanation: PIT counter interrupt handler.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
OS_ISR(OS_PIT)
{
    CoreIdType coreId;
    ISRType isrId;
    CounterType cntId;
    const Os_CounterBaseCfgType* counterBaseCfg;
    Os_Arch_IntState intState;

    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();
    /* Get isr id. */
    isrId = OS_CORE_GETCURRENTISRID(coreId);
    /* If it is a timer interrupter. */
    if( OS_ISR_ISTIMER(isrId) )
    {
        /* Get counter id. */
        cntId = OS_ISR_GETCNTID(isrId);
        counterBaseCfg = OS_COUNTER_GETCFG(cntId);
        Os_Arch_Mach_PitClearInterrupt(((const Os_CounterPitCfgType*)counterBaseCfg)->HwConfig);
        /* Disable interrupt. */
        Os_Arch_IntDisable(&intState);
        (void)Os_Counter_IcrmCnt(counterBaseCfg, OS_COUNTER_GETDYN(counterBaseCfg, const Os_CounterPitCfgType*));
        /* Enable interrupt. */
        Os_Arch_IntEnable(intState);
    }

#ifdef OS_TEST_ENABLE
    OsPitHook();
#endif
}
#endif

#if( OS_HRT_ENABLE == STD_ON )
/*
********************************************************************************
* Function Name: OS_HRT
*
* Explanation: HRT counter interrupt handler.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
OS_ISR(OS_HRT)
{
    CoreIdType coreId;
    ISRType isrId;
    CounterType cntId;
    Os_CntExpListNodeCfgType* expListNode;
    const Os_CounterBaseCfgType* counterBaseCfg;
    Os_Arch_IntState intState;
    Os_StatusType ret;
    uint8 setNextPointFlag = OS_COUNTER_NOTSET_POINT;

    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();
    /* Get isr id. */
    isrId = OS_CORE_GETCURRENTISRID(coreId);
    /* If it is a timer interrupter. */
    if( OS_ISR_ISTIMER(isrId) )
    {
        /* Get counter id. */
        cntId = OS_ISR_GETCNTID(isrId);
        counterBaseCfg = OS_COUNTER_GETCFG(cntId);
#if( OS_ARCH_VIRTUAL_HRT == STD_ON )
        /* Set Hrt max compare value. */
        Os_Hrt_SetMaxCompare(counterBaseCfg);
#endif
        /* Clear Hrt interrupt flag. */
        Os_Arch_Mach_HrtClearInterrupt(((const Os_CounterHrtCfgType*)counterBaseCfg)->HwConfig);
        /* Disable interrupt. */
        Os_Arch_IntDisable(&intState);
        ret = Os_Counter_ExpListPop(counterBaseCfg, &expListNode);
        if( E_OS_BUFFEMPTY != ret )
        {
            (void)Os_Counter_WorkFunc(expListNode, &setNextPointFlag);
        }

        if( OS_COUNTER_NOTSET_POINT == setNextPointFlag )
        {
            /* Get hrt timer last compare value. */
            Os_TickType start = Os_Arch_Mach_HrtTimerGetCompareValue(((const Os_CounterHrtCfgType*)counterBaseCfg)->HwConfig);
            Os_Counter_SetNextPoint(counterBaseCfg, start);
        }
        /* Enable interrupt. */
        Os_Arch_IntEnable(intState);
    }

#ifdef OS_TEST_ENABLE
    OsHrtHook();
#endif
}
#endif

/*
********************************************************************************
* Function Name: IncrementCounter
*
* Explanation: Standard API function, Uese to increments a software counter.
*
* Param: CounterID: Reference to the counter element.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid CounterID.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_CORE: Core is not available.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      Given alarm's owner application is not accessible.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) IncrementCounter(CounterType CounterID)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_IncrementCounter.counterId = CounterID;
    Os_SysCall(Os_Syscall_IncrementCounter_ID, &sysCallParam);
    ret = sysCallParam.Os_IncrementCounter.retVal;
#else
    ret = Os_Counter_IncrementCounter(CounterID);
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: GetCounterValue
*
* Explanation: Standard API function, Get the current count value of a counter
*              (returning either the hardware timer ticks if counter is driven
*              by hardware or the software ticks when user drives counter).
*
* Param: CounterID: Reference to the counter element.
*        Value: The Counter whose tick value is read.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid CounterID.
*         E_OS_CORE: Core is not available.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      Given alarm's owner application is not accessible.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) GetCounterValue
(
    CounterType CounterID,
    TickRefType Value
)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_GetCounterValue.counterId = CounterID;
    sysCallParam.Os_GetCounterValue.value = Value;
    Os_SysCall(Os_Syscall_GetCounterValue_ID, &sysCallParam);
    ret = sysCallParam.Os_GetCounterValue.retVal;
#else
    ret = Os_Counter_GetCounterValue(CounterID, Value);
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: GetElapsedValue
*
* Explanation: Standard API function, Get the number of ticks between the current
*              tick value and a previously read tick value.
*
* Param: CounterID: Reference to the counter element.
*        Value: [in]: The previously read tick value of the counter.
*               [out]: The current tick value of the counter.
*        ElapsedValue: The difference to the previous read value.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid CounterID.
*         E_OS_CORE: Core is not available.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*                      Given alarm's owner application is not accessible.
*         E_OS_VALUE: The value is greater the the maximum value of counter.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) GetElapsedValue
(
    CounterType CounterID,
    TickRefType Value,
    TickRefType ElapsedValue
)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_GetElapsedValue.counterId = CounterID;
    sysCallParam.Os_GetElapsedValue.value = Value;
    sysCallParam.Os_GetElapsedValue.elapsedValue = ElapsedValue;
    Os_SysCall(Os_Syscall_GetElapsedValue_ID, &sysCallParam);
    ret = sysCallParam.Os_GetElapsedValue.retVal;
#else
    ret = Os_Counter_GetElapsedValue(CounterID, Value, ElapsedValue);
#endif

    return ret;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

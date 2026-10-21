/*
********************************************************************************
*
*  File name: Os_Stack.c
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
* Author/Date: LiG/2022.11.21
* Change: Change OS_VAR_NOINIT to OS_VAR_NO_INIT.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.1.29
* Change: Resolve the CallErrorHook privilege level problem.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2023.2.24
* Change: Solve the compilation problem under SC4.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.2.24
* Change: Remove useless return values.
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2023.5.26
* Change: Increase function pointer null detection.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: LiG/2023.05.26
* Change: Resolve compilation warnings.
* Cause: Optimize
********************************************************************************
* Version: 3.8
* Author/Date: ZhangY/2023.08.19
* Change: Modified for QAC.
* Cause: Optimize
********************************************************************************
* Version: 3.9
* Author/Date: ZhangY/2023.10.07
* Change: Modify Os_Stack_GetTaskStackUsage Os_Stack_GetIsrStackUsage
*         Os_Stack_TargetGetTaskStackUsage and Os_Stack_TargetGetIsrStackUsage
*         for QAC.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: ZhangY/2023.12.06
* Change: Modify Os_Stack_GetTaskStackUsage and Os_Stack_GetIsrStackUsage,
*         to fix bug of getting wrong value in cross core situation.
* Cause: Bugfix
********************************************************************************
* Version: 3.11
* Author/Date: LiG/2024.4.10
* Change: Modifying static code check issues.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*   Includes
********************************************************************************
*/
#include "Os_Stack.h"
#include "Os_Arch_Types.h"
#include "Os_Arch_Mach.h"
#include "Os_Task.h"
#include "Os_Isr.h"
#include "Os_MultiCore.h"
#include "Os_SysCall.h"
#include "Os_Hook.h"
#include "Os.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
#define OS_STACK_INIT (0U)  /* Stack initial zero value. */

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
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(Os_Stack_Size, OS_CODE) Os_Stack_GetUsage
(
    P2VAR(Os_Stack_Address, AUTOMATIC, OS_APPL_DATA) startAddr,
    P2VAR(Os_Stack_Address, AUTOMATIC, OS_APPL_DATA) endAddr
);

#define OS_STOP_SEC_CODE
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
* Function Name: Os_Stack_GetUsage
*
* Explanation: Uses to get stack usage.
*
* Param: startAddr: Stack startAddr.
*        endAddr: Stack endAddr.
*
* Retval: stack usage.
********************************************************************************
*/
static FUNC(Os_Stack_Size, OS_CODE) Os_Stack_GetUsage
(
    P2VAR(Os_Stack_Address, AUTOMATIC, OS_APPL_DATA) startAddr,
    P2VAR(Os_Stack_Address, AUTOMATIC, OS_APPL_DATA) endAddr
)
{
    Os_Stack_Size stackSize = 0U;
    Os_Stack_Size cnt = OS_STACK_INIT;
    Os_Stack_Address* topAddr;
    Os_Stack_Address* bottomAddr;

    if( (startAddr != NULL_PTR) && (endAddr != NULL_PTR) )
    {
        topAddr = endAddr;
        bottomAddr = startAddr;
        /* If the stack grows downward. */
        if( startAddr > endAddr )
        {
            stackSize = (Os_Stack_Size)(startAddr - endAddr);
            while( topAddr < bottomAddr )
            {
                if( *topAddr != OS_STACK_RESERVED )
                {
                    break;
                }
                else
                {
                    topAddr++;
                    cnt++;
                }
            }
        }
        else    /* If the stack grows upward. */
        {
            stackSize = (Os_Stack_Size)(startAddr - endAddr);
            while( topAddr > bottomAddr )
            {
                if( *topAddr != OS_STACK_RESERVED )
                {
                    break;
                }
                else
                {
                    topAddr--;
                    cnt++;
                }
            }
        }
        stackSize = (stackSize + OS_STACK_SIZEDEV - cnt) * OS_STACK_TYPE_WIDTH;
    }

    return stackSize;
}

/*
********************************************************************************
* Function Name: Os_Stack_GetTaskStackUsage
*
* Explanation: Uses to get Task stack usage.
*
* Param: taskId: Task reference.
*        taskUsage: Task stack usage.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid taskId.
*         E_OS_CORE: Core is not available.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_Stack_GetTaskStackUsage
(
    TaskType taskId,
    P2VAR(uint32, AUTOMATIC, OS_APPL_DATA) taskUsage
)
{
    Os_StatusType ret = E_OS_OK;

#if( OS_CFG_MULTI_CORE == STD_ON )
    CoreIdType coreId;
#endif
    const Os_TaskCfgType* taskCfg;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_GetTaskStackUsage);
    if( taskId >= OS_TASKID_COUNT ) /* If task id is out range. */
    {
        ret = E_OS_ID;
    }
    else if( NULL_PTR == taskUsage )
    {
        ret = E_OS_PARAM_POINTER;
    }
    else
    {
        /* Get task configuration data. */
        taskCfg = OS_TASK_GETCFG(taskId);
#if( OS_CFG_MULTI_CORE == STD_ON )
        /* Get logic core id. */
        coreId = Os_Core_GetLogicId();
        /* If the activate task is the same core. */
        if( coreId == OS_TASK_GETCOREID(taskCfg) )
#endif
        {
            *taskUsage = Os_Stack_GetUsage(OS_TASK_GETSTACKSTARTADDR(taskCfg), OS_TASK_GETSTACKENDADDR(taskCfg));
        }
#if( OS_CFG_MULTI_CORE == STD_ON )
        else
        {
            Os_MultiCoreServeParamType parameter;
            parameter.Os_GetTaskStackUsage.taskId = taskId;
            /* Execute multi-core calling function. */
            ret = Os_MultiCore_Trigger(TRUE, coreId, OS_TASK_GETCOREID(taskCfg),
                                       Os_MCServe_GetTaskStackUsage_ID, &parameter);
            *taskUsage = parameter.Os_GetTaskStackUsage.taskUsage;
        }
#endif
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_GetTaskStackUsage);
    return Os_Hook_CallErrorHook(OSServiceId_GetTaskStackUsage, ret);
}

/*
********************************************************************************
* Function Name: Os_Stack_GetIsrStackUsage
*
* Explanation: Uses to get Isr stack usage.
*
* Param: isrId: Isr reference.
*        isrUsage: Isr stack usage.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid IsrID.
*         E_OS_CORE: Core is not available.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) Os_Stack_GetIsrStackUsage
(
    ISRType isrId,
    P2VAR(uint32, AUTOMATIC, OS_APPL_DATA) isrUsage
)
{
    Os_StatusType ret = E_OS_OK;

#if( OS_CFG_MULTI_CORE == STD_ON )
    CoreIdType coreId;
#endif
    const Os_IsrCfgType* isrCfg;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_GetISRStackUsage);
    if( isrId >= OS_ISRID_COUNT ) /* If task id is out range. */
    {
        ret = E_OS_ID;
    }
    else if( NULL_PTR == isrUsage )
    {
        ret = E_OS_PARAM_POINTER;
    }
    else
    {
        /* Get task configuration data. */
        isrCfg = OS_ISR_GETCFG(isrId);
#if( OS_CFG_MULTI_CORE == STD_ON )
        /* Get logic core id. */
        coreId = Os_Core_GetLogicId();
        /* If the activate task is the same core. */
        if( coreId == OS_ISR_GETCOREID(isrCfg) )
#endif
        {
            *isrUsage = Os_Stack_GetUsage(OS_ISR_GETSTACKSTARTADDR(isrCfg), OS_TASK_GETSTACKENDADDR(isrCfg));
        }

#if( OS_CFG_MULTI_CORE == STD_ON )
        else
        {
            Os_MultiCoreServeParamType parameter;
            parameter.Os_GetIsrStackUsage.isrId = isrId;
            /* Execute multi-core calling function. */
            ret = Os_MultiCore_Trigger(TRUE, coreId, OS_ISR_GETCOREID(isrCfg),
                                       Os_MCServe_GetIsrStackUsage_ID, &parameter);
            *isrUsage = parameter.Os_GetIsrStackUsage.isrUsage;
        }
#endif
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_GetISRStackUsage);
    return Os_Hook_CallErrorHook(OSServiceId_GetISRStackUsage, ret);
}

/*
********************************************************************************
* Function Name: Os_Stack_Init
*
* Explanation: Stack initialization.
*
* Param: startAddr: Stack startAddr.
*        endAddr: Stack endAddr.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Stack_Init
(
    P2VAR(Os_Stack_Address, AUTOMATIC, OS_APPL_DATA) startAddr,
    P2VAR(Os_Stack_Address, AUTOMATIC, OS_APPL_DATA) endAddr
)
{
    Os_Stack_Address* topAddr;
    Os_Stack_Address* bottomAddr;

    if( (startAddr != NULL_PTR) && (endAddr != NULL_PTR) )
    {
        /* If the stack grows downward. */
        if( startAddr > endAddr )
        {
            topAddr = startAddr;
            bottomAddr = endAddr;
        }
        else   /* If the stack grows upward. */
        {
            topAddr = endAddr;
            bottomAddr = startAddr;
        }

        while( topAddr >= bottomAddr )
        {
            *bottomAddr = OS_STACK_RESERVED;
            bottomAddr++;
        }
    }
}

#if( OS_STACK_OVERFLOW_CHECK == STD_ON )
/*
********************************************************************************
* Function Name: Os_Stack_Measure
*
* Explanation: Uses to stack measure.
*
* Param: startAddr: Stack endAddr.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Stack_Measure
(
    P2CONST(Os_Stack_Address, AUTOMATIC, OS_APPL_CONST) endAddr
)
{
    if( endAddr != NULL_PTR )
    {
        if( OS_STACK_RESERVED != *endAddr )
        {
            Os_Hook_CallProtectionHook(E_OS_STACKFAULT);
        }
    }
}
#endif

#if( OS_CFG_MULTI_CORE == STD_ON )
/*
********************************************************************************
* Function Name: Os_Stack_TargetGetTaskStackUsage
*
* Explanation: Multicore function to get Task stack usage.
*
* Param: taskId: Task reference.
*        taskUsage: Task stack usage.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid taskId.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Stack_TargetGetTaskStackUsage
(
    TaskType taskId,
    P2VAR(Os_Stack_Size, AUTOMATIC, OS_APPL_DATA) taskUsage
)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    CoreIdType desCoreId;
    const Os_TaskCfgType* taskCfg;

    if( taskId >= OS_TASKID_COUNT ) /* If task id is out range. */
    {
        ret = E_OS_ID;
    }
    else
    {
        /* Get the current logical core id. */
        coreId = Os_Core_GetLogicId();
        /* Get task configuration data. */
        taskCfg = OS_TASK_GETCFG(taskId);
        desCoreId = taskCfg->coreId;
        /* If the activate task is the same core. */
        if( coreId == desCoreId )
        {
            *taskUsage = Os_Stack_GetUsage(OS_TASK_GETSTACKSTARTADDR(taskCfg), OS_TASK_GETSTACKENDADDR(taskCfg));
        }
        else
        {
            ret = E_OS_CORE;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Stack_TargetGetIsrStackUsage
*
* Explanation: Multicore function to get Isr stack usage.
*
* Param: IsrID: Isr reference.
*        isrUsage: Isr stack usage.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid isrId.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Stack_TargetGetIsrStackUsage
(
    ISRType isrId,
    P2VAR(Os_Stack_Size, AUTOMATIC, OS_APPL_DATA) isrUsage
)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    CoreIdType desCoreId;
    const Os_IsrCfgType* isrCfg;

    if( isrId >= OS_ISRID_COUNT ) /* If task id is out range. */
    {
        ret = E_OS_ID;
    }
    else
    {
        /* Get the current logical core id. */
        coreId = Os_Core_GetLogicId();
        /* Get task configuration data. */
        isrCfg = OS_ISR_GETCFG(isrId);
        desCoreId = isrCfg->coreId;
        /* If the activate task is the same core. */
        if( coreId == desCoreId )
        {
            *isrUsage = Os_Stack_GetUsage(OS_ISR_GETSTACKSTARTADDR(isrCfg), OS_ISR_GETSTACKENDADDR(isrCfg));
        }
        else
        {
            ret = E_OS_CORE;
        }
    }

    return ret;
}
#endif /* OS_CFG_MULTI_CORE == STD_ON */

/*
********************************************************************************
* Function Name: GetTaskStackUsage
*
* Explanation: Standard API function, uses to get Task stack usage.
*
* Param: TaskID: Task reference.
*
* Retval: Task stack usage.
********************************************************************************
*/
FUNC(uint32, OS_CODE) GetTaskStackUsage(TaskType TaskID)
{
    uint32 retUsage = 0U;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_GetTaskStackUsage.taskId = TaskID;
    sysCallParam.Os_GetTaskStackUsage.taskUsage = &retUsage;
    Os_SysCall(Os_Syscall_GetTaskStackUsage_ID, &sysCallParam);
#else
    (void)Os_Stack_GetTaskStackUsage(TaskID, &retUsage);
#endif

    return retUsage;
}

/*
********************************************************************************
* Function Name: GetISRStackUsage
*
* Explanation: Standard API function, uses to get Isr stack usage.
*
* Param: IsrID: Isr reference.
*
* Retval: Isr stack usage.
********************************************************************************
*/
FUNC(uint32, OS_CODE) GetISRStackUsage(ISRType IsrID)
{
    uint32 retUsage = 0U;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_GetISRStackUsage.isrId = IsrID;
    sysCallParam.Os_GetISRStackUsage.isrUsage = &retUsage;
    Os_SysCall(Os_Syscall_GetISRStackUsage_ID, &sysCallParam);
#else
    (void)Os_Stack_GetIsrStackUsage(IsrID, &retUsage);
#endif

    return retUsage;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

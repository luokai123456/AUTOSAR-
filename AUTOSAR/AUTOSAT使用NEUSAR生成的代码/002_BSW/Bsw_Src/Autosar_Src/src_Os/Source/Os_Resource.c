/*
********************************************************************************
*
*  File name: Os_Resource.c
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
* Author/Date: LiG/2022.11.25
* Change: The resources of Task and ISR cannot access each other.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2022.12.14
* Change: Time protection judgment type error.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2023.1.29
* Change: Resolve the CallErrorHook privilege level problem.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.5.27
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: ZhangY/2023.6.12
* Change: Modifying time protection with only one core and other cores running 
*         dead.Missing parts.
* Cause: Bugfix
********************************************************************************
* Version: 3.7
* Author/Date: LiG/2023.10.5
* Change: Modify the polyspace and code annotation issues.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: JiangGL/2024.03.07
* Change: Fix the issue of using GetResource in ISR to implement functionality
*         for chips that do not support "OS_ARCH_INTMASKLEVE_SUPPORT".
* Cause: Bugfix
********************************************************************************
* Version: 3.9
* Author/Date: LiG/2024.5.22
* Change: Modify the flag of the initial monitor module to determine the end of
*         the task.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: LiG/2024.5.31
* Change: Modified a return value of the GetResource interface.
* Cause: Bugfix
********************************************************************************
* Version: 3.11
* Author/Date: LiG/2024.10.10
* Change: The issue of compilation failure in the case of SC1 and SC2 when
*         priority based interrupt prohibition is not supported.
* Cause: Bugfix
********************************************************************************
* Version: 3.12
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
#include "Os_Resource.h"
#include "Os_SysCall.h"
#include "Os_Task.h"
#include "Os_Isr.h"
#include "Os_App.h"
#include "Os_Platform_Lcfg.h"
#include "Os_Hook.h"
#include "Os_Orti.h"
#include "Os.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/* Get the resource static configuration by id. */
#define OS_RESOURCE_GETCFG(resourceId)          (Os_ResourceCfgData[resourceId])
/* Get the resource static configuration by dynamic configuration. */
#define OS_RESOURCE_GETCFGBYDYN(resourceDyn)    (Os_ResourceCfgData[(resourceDyn)->rsrcId])
/* Determine if the resource is locked. */
#define OS_RESOURCE_ALREADYLOCKED(resourceCfg)  (OS_RESOURCE_LOCKED == (resourceCfg)->resouceDyn->state)
/* Determine if the resource is unlocked. */
#define OS_RESOURCE_ISUNLOCKED(resourceCfg)     (OS_RESOURCE_RELEASED == (resourceCfg)->resouceDyn->state)
/* Set resource lock status. */
#define OS_RESOURCE_SETLOCKE(resourceCfg)       ((resourceCfg)->resouceDyn->state = OS_RESOURCE_LOCKED)
/* Set resource unlock status. */
#define OS_RESOURCE_RELEASELOCKE(resourceCfg)   ((resourceCfg)->resouceDyn->state = OS_RESOURCE_RELEASED)
/* Determining that the resource is associated with isr */
#define OS_RESOURCE_ISISR(resourceCfg)          (OS_RESOURCE_ISR == (resourceCfg)->rsrcType)
/* Get resource list node. */
#define OS_RESOURCE_GETLIST(resourceDyn)        ((Os_ListNodeType*)(resourceDyn))
/* Force convert resource list node to Os_ResourceDynType. */
#define OS_RESOURCE_LISTTORESOURCEDYN(listNode) ((Os_ResourceDynType*)(listNode))

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
#if( OS_CFG_RESOURCE_ENABLE == STD_ON )
LOCAL_INLINE FUNC(boolean, OS_CODE) Os_Resource_CheckPrioIsHigher
(
    P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_APPL_CONST) resourceCfg,
    CoreIdType coreId
);
LOCAL_INLINE FUNC(boolean, OS_CODE) Os_Resource_CheckReleaseOrder
(
    P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_APPL_CONST) resourceCfg,
    P2VAR(Os_ListNodeType, AUTOMATIC, OS_APPL_DATA) rsrcListHead
);
LOCAL_INLINE FUNC_P2VAR(Os_ListNodeType, OS_APPL_DATA, OS_CODE) Os_Resource_GetCurrentListHead
(
    CoreIdType coreId
);
LOCAL_INLINE FUNC(void, OS_CODE) Os_Resource_IncreaseIsrPrio
(
    P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_APPL_CONST) resourceCfg
);
LOCAL_INLINE FUNC(void, OS_CODE) Os_Resource_IncreaseTaskPrio
(
    P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_APPL_CONST) resourceCfg
);
LOCAL_INLINE FUNC(void, OS_CODE) Os_Resource_RestoreIsrPrio
(
    P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_APPL_CONST) resourceCfg
);
LOCAL_INLINE FUNC(void, OS_CODE) Os_Resource_RestoreTaskPrio
(
    P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_APPL_CONST) resourceCfg
);
LOCAL_INLINE FUNC(void, OS_CODE) Os_Resource_ReleaseResourceSimp
(
    P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_APPL_CONST) resourceCfg
);
LOCAL_INLINE FUNC(void, OS_CODE) Os_Resource_GetResourceSimp
(
    P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_APPL_CONST) resourceCfg
);
#endif /* OS_CFG_RESOURCE_ENABLE == STD_ON */

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
* Function Name: Os_Resource_CheckPrioIsHigher
*
* Explanation: Detect whether the priority of the resource to be acquired is
*              higher than the current one.
*
* Param: resourceCfg: Reference to a resource.
*        coreId: Current core index.
*
* Retval: Is it right or not.
********************************************************************************
*/
#if( OS_CFG_RESOURCE_ENABLE == STD_ON )
LOCAL_INLINE FUNC(boolean, OS_CODE) Os_Resource_CheckPrioIsHigher
(
    P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_APPL_CONST) resourceCfg,
    CoreIdType coreId
)
{
    boolean ret = TRUE;
    Os_TaskDynType* currentTask;
    ISRType currentIsrId;

    if( OS_RESOURCE_ISISR(resourceCfg) )
    {
        if( OS_CORE_CHECKCURRENTINISR(coreId) )
        {
            currentIsrId = OS_CORE_GETCURRENTISRID(coreId);
            /* Check resource isr level is valid. */
            if( TRUE != Os_Arch_IntLevelIsHigher(OS_ISR_GETINTLEVEL(currentIsrId),
                                                 resourceCfg->rsrcParam.isrLevel) )
            {
                ret = FALSE;
            }
        }
    }
    else
    {
        if( OS_CORE_CHECKCURRENTINISR(coreId) )
        {
            ret = FALSE;
        }
        else
        {
            currentTask = OS_CORE_GETCURRENTTASK(coreId);
            /* Check resource task priority is valid. */
            if( resourceCfg->resouceDyn->rsrcParam.taskPrio > OS_TASK_GETRUNPRIO(currentTask) )
            {
                ret = FALSE;
            }
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Resource_CheckReleaseOrder
*
* Explanation: Check whether the release order of resources is correct.
*
* Param: resourceCfg: Reference to a resource.
*        rsrcListHead: Resource list head.
*
* Retval: Is it right or not.
********************************************************************************
*/
LOCAL_INLINE FUNC(boolean, OS_CODE) Os_Resource_CheckReleaseOrder
(
    P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_APPL_CONST) resourceCfg,
    P2VAR(Os_ListNodeType, AUTOMATIC, OS_APPL_DATA) rsrcListHead
)
{
    boolean ret = TRUE;

   /*The list get first node form the head. */
    Os_ResourceDynType* topResource = (Os_ResourceDynType*)Os_List_GetTop(rsrcListHead);
    if( topResource != resourceCfg->resouceDyn )
    {
        ret = FALSE;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Resource_GetCurrentListHead
*
* Explanation: Get current resource list head.
*
* Param: coreId: Current core index.
*
* Retval: Current resource list head.
********************************************************************************
*/
LOCAL_INLINE FUNC_P2VAR(Os_ListNodeType, OS_APPL_DATA, OS_CODE) Os_Resource_GetCurrentListHead
(
    CoreIdType coreId
)
{
    Os_ListNodeType* rsrcListHead;
    Os_TaskDynType* currentTask;
    Os_IsrDynType* currentIsr;

    if( OS_CORE_CHECKCURRENTINISR(coreId) )
    {
        currentIsr = OS_CORE_GETCURRENTISR(coreId);
        rsrcListHead = OS_ISR_GETRESLISTHEAD(currentIsr);
    }
    else
    {
        currentTask = OS_CORE_GETCURRENTTASK(coreId);
        rsrcListHead = OS_TASK_GETRESLISTHEAD(currentTask);
    }

    return rsrcListHead;
}

/*
********************************************************************************
* Function Name: Os_Resource_IncreaseIsrPrio
*
* Explanation: Uses to increase Isr interrupt priority.
*
* Param: resourceCfg: Reference to a resource.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Resource_IncreaseIsrPrio
(
    P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_APPL_CONST) resourceCfg
)
{
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
    Os_IntLevelType currentLevel;
    Os_IntLevelType rsrcIsrLevel;

    currentLevel = Os_Arch_GetIntMaskLevel();
    rsrcIsrLevel = resourceCfg->resouceDyn->rsrcParam.isrLevel;
    /* Check interrupt priority is valid. */
    if( TRUE == Os_Arch_IntLevelIsHigher(currentLevel, rsrcIsrLevel) )
    {
        /* Modify the interrupt priority mask bit. */
        Os_Arch_SetIntMaskLevel(rsrcIsrLevel);
        resourceCfg->resouceDyn->preRsrcParam.isrLevel = currentLevel;
    }
#else
    OS_IGNORE_PARAM(resourceCfg);
    Os_Arch_IntDisableAll();
#endif
}

/*
********************************************************************************
* Function Name: Os_Resource_IncreaseTaskPrio
*
* Explanation: Uses to increase task priority.
*
* Param: resourceCfg: Reference to a resource.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Resource_IncreaseTaskPrio
(
    P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_APPL_CONST) resourceCfg
)
{
    CoreIdType coreId;
    Os_TaskPrioType currentTaskprio;
    Os_TaskPrioType rsrcTaskprio;
    Os_TaskDynType* currentTask;

    /* Get the current logical core id. */
    coreId = Os_Core_GetLogicId();
    rsrcTaskprio = resourceCfg->resouceDyn->rsrcParam.taskPrio;
    currentTask = OS_CORE_GETCURRENTTASK(coreId);
    currentTaskprio = OS_TASK_GETRUNPRIO(currentTask);
    if( rsrcTaskprio <= currentTaskprio )
    {
        /* Increase the scheduling priority of the current task. */
        (void)Os_Schedler_IncreasePriority(OS_CORE_GETSCHEDULER(coreId) ,rsrcTaskprio);
        resourceCfg->resouceDyn->preRsrcParam.taskPrio = currentTaskprio;
    }
}

/*
********************************************************************************
* Function Name: Os_Resource_RestoreIsrPrio
*
* Explanation: Uses to restore Isr interrupt priority.
*
* Param: resourceCfg: Reference to a resource.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Resource_RestoreIsrPrio
(
    P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_APPL_CONST) resourceCfg
)
{
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
    Os_IntLevelType preIntLevel;
    Os_IntLevelType currentLevel;

    currentLevel = Os_Arch_GetIntMaskLevel();
    preIntLevel = resourceCfg->resouceDyn->preRsrcParam.isrLevel;
     /* Check interrupt priority is valid. */
    if( TRUE == Os_Arch_IntLevelIsLower(currentLevel, preIntLevel) )
    {
        /* Modify the interrupt priority mask bit. */
        Os_Arch_SetIntMaskLevel(preIntLevel);
    }
    else
    {
        Os_FatalError();
    }
#else
    OS_IGNORE_PARAM(resourceCfg);
    Os_Arch_IntEnableAll();
#endif
}

/*
********************************************************************************
* Function Name: Os_Resource_RestoreTaskPrio
*
* Explanation: Uses to restore task priority.
*
* Param: resourceCfg: Reference to a resource.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Resource_RestoreTaskPrio
(
    P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_APPL_CONST) resourceCfg
)
{
    CoreIdType coreId;
    Os_TaskPrioType currentTaskprio;
    Os_TaskPrioType preRsrcTaskprio;
    Os_TaskDynType* currentTask;

    /* Get the current logical core id. */
    coreId = Os_Core_GetLogicId();
    currentTask = OS_CORE_GETCURRENTTASK(coreId);
    currentTaskprio = OS_TASK_GETRUNPRIO(currentTask);
    preRsrcTaskprio = resourceCfg->resouceDyn->preRsrcParam.taskPrio;
    if( currentTaskprio <= preRsrcTaskprio )
    {
        /* Decrease the scheduling priority of the current task. */
        (void)Os_Schedler_DecreasePriority(OS_CORE_GETSCHEDULER(coreId), preRsrcTaskprio);
    }
    else
    {
        Os_FatalError();
    }
}

/*
********************************************************************************
* Function Name: Os_Resource_ReleaseResourceSimp
*
* Explanation: Internal function, uses to release resource.
*
* Param: resourceCfg: Reference to a resource.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Resource_ReleaseResourceSimp
(
    P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_APPL_CONST) resourceCfg
)
{
    if( NULL_PTR != resourceCfg )
    {
        /* Resource lock. */
        OS_RESOURCE_RELEASELOCKE(resourceCfg);

        if( FALSE == OS_RESOURCE_ISISR(resourceCfg) )
        {
            Os_Resource_RestoreTaskPrio(resourceCfg);
        }
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
        else
        {
            Os_Resource_RestoreIsrPrio(resourceCfg);
        }
#endif /* OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON */
    }
}

/*
********************************************************************************
* Function Name: Os_Resource_GetResourceSimp
*
* Explanation: Internal function, uses to get resource.
*
* Param: resourceCfg: Reference to a resource.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Resource_GetResourceSimp
(
    P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_APPL_CONST) resourceCfg
)
{
    /* Set lock. */
    OS_RESOURCE_SETLOCKE(resourceCfg);

    if( FALSE == OS_RESOURCE_ISISR(resourceCfg) )
    {
        Os_Resource_IncreaseTaskPrio(resourceCfg);
    }
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
    else
    {
        Os_Resource_IncreaseIsrPrio(resourceCfg);
    }
#endif /* OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON */
}

/*
********************************************************************************
* Function Name: Os_Resource_Init
*
* Explanation: Uses to init a resource.
*
* Param: resourceCfg: Reference to a resource.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Resource_Init
(
    P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_APPL_CONST) resourceCfg
)
{
    Os_ResourceDynType* resourceDyn;

    /* Check the resourceCfg is not NULL_PTR. */
    Os_ParamCheck(NULL_PTR != resourceCfg);
    resourceDyn = resourceCfg->resouceDyn;
    resourceDyn->state = OS_RESOURCE_RELEASED;
    resourceDyn->rsrcId = resourceCfg->rsrcId;
    resourceDyn->rsrcParam = resourceCfg->rsrcParam;
    Os_List_Init(OS_RESOURCE_GETLIST(resourceDyn));
}

/*
********************************************************************************
* Function Name: Os_Resource_GetResource
*
* Explanation: Uses to get a resource.
*
* Param: resId: Reference to an  resource.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid spinlockID.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_RESOURCE_LOCKED: A resource is locked.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*         E_OS_CORE: Core is not available.
*         E_OS_PRIORITY: The resource priority is lower than the priority of the
*                        call.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Resource_GetResource(ResourceType resId)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    Os_ListNodeType* rsrcListHead;
    const Os_ResourceCfgType* resourceCfg;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_GetResource);
    /* Get the current logical core id. */
    coreId = Os_Core_GetLogicId();

    if( resId >= OS_RESOURCEID_COUNT ) /* If resource id is out range. */
    {
        ret = E_OS_ID;
    }
    else if( OS_CORE_MASK_INTERRUPT(coreId) )   /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_GETRESOURCE_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        resourceCfg = OS_RESOURCE_GETCFG(resId);
        if( coreId != resourceCfg->coreId )
        {
            ret = E_OS_CORE;
        }
        else if( OS_RESOURCE_ALREADYLOCKED(resourceCfg) )
        {
            ret = E_OS_ACCESS;
        }
        else if( OS_APPMATCH(resourceCfg->accessingApps, OS_CORE_GETAPPID(coreId)) )
        {
            ret = E_OS_ACCESS;
        }
        else if( (OS_ISR_CAT2_TYPE_MASK == OS_CORE_GETPROTYPE(coreId)) &&
                 (!OS_RESOURCE_ISISR(resourceCfg)) )
        {
            ret = E_OS_ACCESS;
        }
        else if( (OS_ISR_CAT2_TYPE_MASK != OS_CORE_GETPROTYPE(coreId)) &&
                 (OS_RESOURCE_ISISR(resourceCfg)) )
        {
            ret = E_OS_ACCESS;
        }
        else if( FALSE == Os_Resource_CheckPrioIsHigher(resourceCfg, coreId) )
        {
            ret = E_OS_ACCESS;
        }
        else
        {
            /* Disable interrupt. */
            Os_Arch_IntDisableAll();
#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
            if( OS_CORE_CHECKTPISENABLE(coreId) )
            {
                if( OS_CORE_CHECKCURRENTINTASK(coreId) )
                {
                    const Os_TpCfgType* currentTpCfg;

                    if( OS_TASK_TYPE_MASK == OS_CORE_GETPROTYPE(coreId) )
                    {
                        currentTpCfg = OS_TASK_GETCFG(OS_CORE_GETCURRENTTASKID(coreId))->tpCfg;
                        Os_Tp_StartResBudget(currentTpCfg, resourceCfg->rsrcId, coreId);
                    }
                    else if( OS_ISR_CAT2_TYPE_MASK == OS_CORE_GETPROTYPE(coreId) )
                    {
                        currentTpCfg = OS_ISR_GETCFG(OS_CORE_GETCURRENTISRID(coreId))->tpCfg;
                        Os_Tp_StartResBudget(currentTpCfg, resourceCfg->rsrcId, coreId);
                    }
                    else
                    {
                        /* Do nothing. */
                    }
                }
            }
#endif
            /* Get the list head of current task or isr. */
            rsrcListHead = Os_Resource_GetCurrentListHead(coreId);
            Os_Resource_GetResourceSimp(resourceCfg);
            Os_List_Push(rsrcListHead, &resourceCfg->resouceDyn->rsrcListNode);

#if( (OS_CFG_ORTI_ENABLE == STD_ON) && (OS_CFG_ORTI_HOOK_ENABLE == STD_ON) )
            /* Call orti hook. */
            Os_Orit_ResourceState_Trigger(coreId, resId, OS_ORTI_RES_GET_TRIGGER);
#endif
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
            /* Enable interrupt. */
            Os_Arch_IntEnableAll();
#elif( OS_MEMORY_PROTECTION == STD_OFF )
            if( FALSE == Os_Isr_GetInterruptStatus() )
            {
                /* Enable interrupt. */
                Os_Arch_IntEnableAll();
            }
#endif
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_GetResource);

    return Os_Hook_CallErrorHook(OSServiceId_GetResource, ret);
}

/*
********************************************************************************
* Function Name: Os_Resource_ReleaseResource
*
* Explanation: Uses to release a resource.
*
* Param: resId: Reference to a resource.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid spinlockID.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_NOFUNC: Resource release sequence error.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Resource_ReleaseResource(ResourceType resId)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;
    Os_ListNodeType* rsrcListHead;
    Os_TaskDynType* nextDyn;
    const Os_ResourceCfgType* resourceCfg;
    const Os_TaskCfgType* currentTaskCfg;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_ReleaseResource);
    /* Get the current logical core id. */
    coreId = Os_Core_GetLogicId();

    if( resId >= OS_RESOURCEID_COUNT ) /* If resource id is out range. */
    {
        ret = E_OS_ID;
    }
    else if( OS_CORE_MASK_INTERRUPT(coreId) )   /* If interrupts is disable. */
    {
        ret = E_OS_DISABLEDINT;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_RELEASERESOURCE_ACCESS) ) /* If the api is not accessible */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        resourceCfg = OS_RESOURCE_GETCFG(resId);
        /* Get the list head of current task or isr. */
        rsrcListHead = Os_Resource_GetCurrentListHead(coreId);
        if( coreId != resourceCfg->coreId )
        {
            ret = E_OS_CORE;
        }
        else if( OS_APPMATCH(resourceCfg->accessingApps, OS_CORE_GETAPPID(coreId)) )
        {
            ret = E_OS_ACCESS;
        }
        else if( (OS_ISR_CAT2_TYPE_MASK == OS_CORE_GETPROTYPE(coreId)) &&
                 (!OS_RESOURCE_ISISR(resourceCfg)) )
        {
            ret = E_OS_ACCESS;
        }
        else if( (OS_ISR_CAT2_TYPE_MASK != OS_CORE_GETPROTYPE(coreId)) &&
                 (OS_RESOURCE_ISISR(resourceCfg)) )
        {
            ret = E_OS_ACCESS;
        }
        else if( OS_RESOURCE_ISUNLOCKED(resourceCfg) )
        {
            ret = E_OS_NOFUNC;
        }
        else if( FALSE == Os_Resource_CheckReleaseOrder(resourceCfg, rsrcListHead) )
        {
            ret = E_OS_NOFUNC;
        }
        else
        {
            /* Disable interrupt. */
            Os_Arch_IntDisableAll();
            Os_Resource_ReleaseResourceSimp(resourceCfg);
            (void)Os_List_Pop(rsrcListHead);

            if( OS_CORE_CHECKCURRENTINTASK(coreId) )
            {
                /* Get current task config. */
                currentTaskCfg = OS_TASK_GETCFG(OS_CORE_GETCURRENTTASKID(coreId));
                if( TRUE == Os_Schedler_NeedSchedle(OS_CORE_GETSCHEDULER(coreId)) )
                {
                    /* Execute a schedule. */
                    nextDyn = Os_Schedler_Schedle(OS_CORE_GETSCHEDULER(coreId));
#if( OS_MONITOR_ENABLE == STD_ON )
                    Os_Monitor_TaskTerminateFlag[OS_CORE_GETCURRENTTASKID(coreId)] = FALSE;
#endif
                    ret = Os_Task_TaskSwitch(currentTaskCfg, OS_TASK_GETCFG(nextDyn->taskId));
                }
            }

#if( (OS_CFG_ORTI_ENABLE == STD_ON) && (OS_CFG_ORTI_HOOK_ENABLE == STD_ON) )
            /* Call orti hook. */
            Os_Orit_ResourceState_Trigger(coreId, resId, OS_ORTI_RES_RELEASE_TRIGGER);
#endif
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
            /* Enable interrupt. */
            Os_Arch_IntEnableAll();
#elif( OS_MEMORY_PROTECTION == STD_OFF )
            if( FALSE == Os_Isr_GetInterruptStatus() )
            {
                /* Enable interrupt. */
                Os_Arch_IntEnableAll();
            }
#endif

#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
            if( OS_CORE_CHECKTPISENABLE(coreId) )
            {
                const Os_TpCfgType* currentTpCfg;
                if( OS_TASK_TYPE_MASK == OS_CORE_GETPROTYPE(coreId) )
                {
                    currentTpCfg = OS_TASK_GETCFG(OS_CORE_GETCURRENTTASKID(coreId))->tpCfg;
                    Os_Tp_StopResBudget(currentTpCfg, resourceCfg->rsrcId, coreId);
                }
                else if( OS_ISR_CAT2_TYPE_MASK == OS_CORE_GETPROTYPE(coreId) )
                {
                    currentTpCfg = OS_ISR_GETCFG(OS_CORE_GETCURRENTISRID(coreId))->tpCfg;
                    Os_Tp_StopResBudget(currentTpCfg, resourceCfg->rsrcId, coreId);
                }
                else
                {
                    /* Do nothing. */
                }
            }
#endif
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_ReleaseResource);

    return Os_Hook_CallErrorHook(OSServiceId_ReleaseResource, ret);
}

/*
********************************************************************************
* Function Name: Os_Resource_ForceReleaseAll
*
* Explanation: Uses to  force release a resource.
*
* Param: rsrcListHead: resource list head.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Resource_ForceReleaseAll
(
    P2VAR(Os_ListNodeType, AUTOMATIC, OS_APPL_DATA) rsrcListHead
)
{
    Os_ListNodeType* rsrcListTopNode;
    const Os_ResourceCfgType* resourceCfg;
    Os_Arch_IntState intState;

#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
    CoreIdType coreId;
    const Os_TpCfgType* currentTpCfg;
#endif

    /* Cyclic release resource. */
    while( TRUE != Os_List_IsEmpty(rsrcListHead) )
    {
        /* Disable interrupt. */
        Os_Arch_IntDisable(&intState);
        rsrcListTopNode = Os_List_GetTop(rsrcListHead);
        resourceCfg = OS_RESOURCE_GETCFGBYDYN(OS_RESOURCE_LISTTORESOURCEDYN(rsrcListTopNode));

        Os_Resource_ReleaseResourceSimp(resourceCfg);
        (void)Os_List_Pop(rsrcListHead);
        /* Enable interrupt. */
        Os_Arch_IntEnable(intState);

#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
        coreId = Os_Core_GetLogicId();
        if( OS_CORE_CHECKTPISENABLE(coreId) )
        {
            if( OS_TASK_TYPE_MASK == OS_CORE_GETPROTYPE(coreId) )
            {
                currentTpCfg = OS_TASK_GETCFG(OS_CORE_GETCURRENTTASKID(coreId))->tpCfg;
                Os_Tp_StopResBudget(currentTpCfg, resourceCfg->rsrcId, coreId);
            }
            else if( OS_ISR_CAT2_TYPE_MASK == OS_CORE_GETPROTYPE(coreId) )
            {
                currentTpCfg = OS_ISR_GETCFG(OS_CORE_GETCURRENTISRID(coreId))->tpCfg;
                Os_Tp_StopResBudget(currentTpCfg, resourceCfg->rsrcId, coreId);
            }
            else
            {
                /* Do nothing. */
            }
        }
#endif
    }
}

/*
********************************************************************************
* Function Name: GetResource
*
* Explanation: Standard API function, uses to get a resource.
*
* Param: ResID: Reference to an  resource.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid spinlockID.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_RESOURCE_LOCKED: A resource is locked.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*         E_OS_CORE: Core is not available.
*         E_OS_PRIORITY: The resource priority is lower than the priority of the
*                        call.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) GetResource(ResourceType ResID)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_GetResource.resId = ResID;
    Os_SysCall(Os_Syscall_GetResource_ID, &sysCallParam);
    ret = sysCallParam.Os_GetResource.retVal;
#else
    ret = Os_Resource_GetResource(ResID);
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: ReleaseResource
*
* Explanation: Standard API function, uses to release a resource.
*
* Param: ResID: Reference to a resource.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid spinlockID.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_DISABLEDINT: A service of the OS is called inside an interrupt
*                           disable/enable pair.
*         E_OS_NOFUNC: Resource release sequence error.
*         E_OS_ACCESS: Caller's access rights are not sufficient.
*         E_OS_CORE: Core is not available.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) ReleaseResource(ResourceType ResID)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_ReleaseResource.resId = ResID;
    Os_SysCall(Os_Syscall_ReleaseResource_ID, &sysCallParam);
    ret = sysCallParam.Os_ReleaseResource.retVal;
#else
    ret = Os_Resource_ReleaseResource(ResID);
#endif

    return ret;
}
#endif /* OS_CFG_RESOURCE_ENABLE == STD_ON */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

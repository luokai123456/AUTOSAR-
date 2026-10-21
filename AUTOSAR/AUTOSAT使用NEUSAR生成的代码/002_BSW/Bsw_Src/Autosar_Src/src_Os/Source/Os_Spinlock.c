/*
********************************************************************************
*
*  File name: Os_Spinlock.c
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
* Change: The spinlock fetches the node incorrectly.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: WangJP/2022.12.10
* Change: Modification of coding standard.
* Cause: Optimize
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2022.12.14
* Change: To compile warnings.
* Cause: Optimize
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2023.1.29
* Change: Resolve the CallErrorHook privilege level problem.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2023.5.26
* Change: Increase function pointer null detection.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: LiG/2023.5.27
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: LiG/2023.10.5
* Change: Modify the polyspace and code annotation issues.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: ZhangY/2023.10.09
* Change: Modify incorrect return value in API description in many functions.
* Cause: Optimization
********************************************************************************
* Version: 3.10
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
#include "Std_Types.h"
#include "Os_Spinlock.h"
#include "Os_SysCall.h"
#include "Os_Hook.h"
#include "Os_Cfg.h"
#include "Os_Orti.h"
#include "Os.h"
#include "Os_Arch_Types.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/* The spinlock set the current core occurred. */
#define OS_SPINLOCK_SETOCCURREDCORE(spinlockDyn, coreId)   ((spinlockDyn)->occurredCoreId[coreId] = (coreId))
/* The spinlock clear the current core occurred. */
#define OS_SPINLOCK_CLEAROCCURREDCORE(spinlockDyn, coreId) ((spinlockDyn)->occurredCoreId[coreId] = OS_SPINLOCK_INVALIDCORE)
/* Get the spinlock static configuration by id. */
#define OS_SPINLOCK_GETCFG(spinlockId)                     (Os_SpinlockCfgData[spinlockId])
/* Get the spinlock id by dynamic configuration. */
#define OS_SPINLCOK_GETCFGBYDYN(spinlockDyn)               (Os_SpinlockCfgData[(spinlockDyn)->spinId])
/* Get spinlock list node. */
#define OS_SPINLOCK_GETLIST(spinlockDyn)                   ((Os_ListNodeType*)(spinlockDyn))
/* Determine if the current spinlock is unlocked. */
#define OS_SPINLOCK_ISUNLOCKED(spinlockCfg)                (OS_SPINLOCK_UNLOCK == (spinlockCfg)->spinDyn->spinlock)
/* Force convert spinlock list node to Os_SpinlockDynType. */
#define OS_SPINLOCK_LISTTSPINLOCKDYN(listNode)             ((Os_SpinlockDynType*)(listNode))

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
#if( OS_CFG_SPINLOCK_ENABLE == STD_ON )
LOCAL_INLINE FUNC(boolean, OS_CODE) Os_Spinlock_CheckOccurredInLocal
(
    P2CONST(Os_SpinlockCfgType, AUTOMATIC, OS_APPL_CONST) spinlockCfg,
    CoreIdType coreId
);
#if( OS_CFG_SPINLOCKNEST_ENABLE == STD_ON )
LOCAL_INLINE FUNC(boolean, OS_CODE) Os_Spinlock_CheckErrorOrder
(
    P2CONST(Os_SpinlockCfgType, AUTOMATIC, OS_APPL_CONST) spinlockCfg,
    CoreIdType coreId
);
#endif
#if( OS_CFG_SPINLOCKNEST_ENABLE == STD_OFF )
LOCAL_INLINE FUNC(boolean, OS_CODE) Os_Spinlock_CheckNest
(
    CoreIdType coreId
);
#endif
LOCAL_INLINE FUNC_P2VAR(Os_ListNodeType, OS_APPL_DATA, OS_CODE) Os_Spinlock_GetCurrentListHead
(
    CoreIdType coreId
);
LOCAL_INLINE FUNC(boolean, OS_CODE) Os_Spinlock_CheckReleaseOrder
(
    P2CONST(Os_SpinlockCfgType, AUTOMATIC, OS_APPL_CONST) spinlockCfg,
    P2VAR(Os_ListNodeType, AUTOMATIC, OS_APPL_DATA) spinListHead
);
LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_Spinlock_ProcessingGetSpinlockMethod
(
    P2CONST(Os_SpinlockCfgType, AUTOMATIC, OS_APPL_CONST) spinlockCfg,
    CoreIdType coreId
);
LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_Spinlock_ProcessingReleaseSpinlockMethod
(
    P2CONST(Os_SpinlockCfgType, AUTOMATIC, OS_APPL_CONST) spinlockCfg,
    CoreIdType coreId
);
LOCAL_INLINE FUNC(void, OS_CODE) Os_Spinlock_GetSpinlockSimp
(
    P2CONST(Os_SpinlockCfgType, AUTOMATIC, OS_APPL_CONST) spinlockCfg,
    P2VAR(Os_ListNodeType, AUTOMATIC, OS_APPL_DATA) spinListHead
);
LOCAL_INLINE FUNC(Os_SpinlockType, OS_CODE)  Os_Spinlock_TryToGetSpinlockSimp
(
    P2CONST(Os_SpinlockCfgType, AUTOMATIC, OS_APPL_CONST) spinlockCfg,
    P2VAR(Os_ListNodeType, AUTOMATIC, OS_APPL_DATA) spinListHead
);
LOCAL_INLINE FUNC(void, OS_CODE) Os_Spinlock_ReleaseSpinlockSimp
(
    P2CONST(Os_SpinlockCfgType, AUTOMATIC, OS_APPL_CONST) spinlockCfg,
    P2VAR(Os_ListNodeType, AUTOMATIC, OS_APPL_DATA) spinListHead
);
#endif /* OS_CFG_SPINLOCK_ENABLE == STD_ON */

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
#if( OS_CFG_SPINLOCK_ENABLE == STD_ON )
/*
********************************************************************************
* Function Name: Os_Spinlock_CheckOccurredInLocal
*
* Explanation: Check if this core has get the spinlock.
*
* Param: spinlockCfg: Reference to an spinlock.
*        coreId: Current core index.
*
* Retval: Is it right or not.
********************************************************************************
*/
LOCAL_INLINE FUNC(boolean, OS_CODE) Os_Spinlock_CheckOccurredInLocal
(
    P2CONST(Os_SpinlockCfgType, AUTOMATIC, OS_APPL_CONST) spinlockCfg,
    CoreIdType coreId
)
{
    return ((coreId == (CoreIdType)spinlockCfg->spinDyn->occurredCoreId[coreId]) ? TRUE : FALSE);
}

#if( OS_CFG_SPINLOCKNEST_ENABLE == STD_ON )
/*
********************************************************************************
* Function Name: Os_Spinlock_CheckErrorOrder
*
* Explanation: Check for nested order errors.
*
* Param: spinlockCfg: Reference to an spinlock.
*        coreId: Current core index.
*
* Retval: Is it right or not.
********************************************************************************
*/
LOCAL_INLINE FUNC(boolean, OS_CODE) Os_Spinlock_CheckErrorOrder
(
    P2CONST(Os_SpinlockCfgType, AUTOMATIC, OS_APPL_CONST) spinlockCfg,
    CoreIdType coreId
)
{
    boolean ret = TRUE;
    uint8 nestNum = OS_CORE_GETSPINLOCKNESTNUM(coreId);

    if( nestNum > 0U )
    {
        if( nestNum > OS_CFG_SPINLOCKMAXNESTNUM )
        {
            Os_FatalError();
        }

        if( OS_CORE_GETSPINLOCKNESTNUM(coreId) >= spinlockCfg->spinDyn->order )
        {
            ret = FALSE;
        }
    }

    return ret;
}
#endif
#if( OS_CFG_SPINLOCKNEST_ENABLE == STD_OFF )
/*
********************************************************************************
* Function Name: Os_Spinlock_CheckNest
*
* Explanation: Detect if nesting occurs.
*
* Param: coreId: Current core index.
*
* Retval: Is it right or not.
********************************************************************************
*/
LOCAL_INLINE FUNC(boolean, OS_CODE) Os_Spinlock_CheckNest
(
    CoreIdType coreId
)
{
    return ((OS_CORE_GETSPINLOCKNESTNUM(coreId) > 0U) ? TRUE : FALSE);
}
#endif
/*
********************************************************************************
* Function Name: Os_Spinlock_GetCurrentListHead
*
* Explanation: Get current spinlock list head.
*
* Param: coreId: Current core index.
*
* Retval: Current spinlock list head.
********************************************************************************
*/
LOCAL_INLINE FUNC_P2VAR(Os_ListNodeType, OS_APPL_DATA, OS_CODE) Os_Spinlock_GetCurrentListHead
(
    CoreIdType coreId
)
{
    Os_ListNodeType* spinListHead;
    Os_TaskDynType* currentTask;
    Os_IsrDynType* currentIsr;

    if( OS_CORE_CHECKCURRENTINISR(coreId) )
    {
        currentIsr = OS_CORE_GETCURRENTISR(coreId);
        spinListHead = OS_ISR_GETSPINLISTHEAD(currentIsr);
    }
    else
    {
        currentTask = OS_CORE_GETCURRENTTASK(coreId);
        spinListHead = OS_TASK_GETSPINLISTHEAD(currentTask);
    }

    return spinListHead;
}

/*
********************************************************************************
* Function Name: Os_Spinlock_CheckReleaseOrder
*
* Explanation: Check whether the spinlock release sequence is correct.
*
* Param: spinlockCfg: Reference to an spinlock.
*        spinListHead: Spinlock list head.
*
* Retval: Is it right or not.
********************************************************************************
*/
LOCAL_INLINE FUNC(boolean, OS_CODE) Os_Spinlock_CheckReleaseOrder
(
    P2CONST(Os_SpinlockCfgType, AUTOMATIC, OS_APPL_CONST) spinlockCfg,
    P2VAR(Os_ListNodeType, AUTOMATIC, OS_APPL_DATA) spinListHead
)
{
    boolean ret = TRUE;

   /*The list get first node form the head. */
    Os_SpinlockDynType* topSpinlock = (Os_SpinlockDynType*)Os_List_GetTop(spinListHead);
    if( topSpinlock != spinlockCfg->spinDyn )
    {
        ret = FALSE;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Spinlock_ProcessingGetSpinlockMethod
*
* Explanation: Spinlock processing get method.
*
* Param: spinlockCfg: Reference to an spinlock.
*        coreId: Current core index.
*
* Retval: E_OS_OK: No error.
*         E_OS_VALUE: Error method.
********************************************************************************
*/
LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_Spinlock_ProcessingGetSpinlockMethod
(
    P2CONST(Os_SpinlockCfgType, AUTOMATIC, OS_APPL_CONST) spinlockCfg,
    CoreIdType coreId
)
{
    Os_StatusType ret = E_OS_OK;

    switch( spinlockCfg->spinMethod )
    {
        case OS_SPINLOCK_LOCK_ALL_INTERRUPTS:
            Os_Core_SuspendAllInterrupts();
            break;
        case OS_SPINLOCK_LOCK_CAT2_INTERRUPTS:
            Os_Core_SuspendOSInterrupts();
            break;
        case OS_SPINLOCK_LOCK_WITH_RES_SCHEDULER:
            OS_SCHEDULER_DISABLESCHEDULER(OS_CORE_GETSCHEDULER(coreId));
            break;
        case OS_SPINLOCK_LOCK_NOTHING:
            /* Do nothing. */
            break;
        default:
            ret = E_OS_VALUE;
            break;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Spinlock_ProcessingReleaseSpinlockMethod
*
* Explanation: Spinlock processing release method.
*
* Param: spinlockCfg: Reference to an spinlock.
*        coreId: Current core index.
*
* Retval: E_OS_OK: No error.
*         E_OS_VALUE: Error method.
********************************************************************************
*/
LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_Spinlock_ProcessingReleaseSpinlockMethod
(
    P2CONST(Os_SpinlockCfgType, AUTOMATIC, OS_APPL_CONST) spinlockCfg,
    CoreIdType coreId
)
{
    Os_StatusType ret = E_OS_OK;

    switch( spinlockCfg->spinMethod )
    {
        case OS_SPINLOCK_LOCK_ALL_INTERRUPTS:
            Os_Core_ResumeAllInterrupts();
            break;
        case OS_SPINLOCK_LOCK_CAT2_INTERRUPTS:
            Os_Core_ResumeOSInterrupts();
            break;
        case OS_SPINLOCK_LOCK_WITH_RES_SCHEDULER:
            OS_SCHEDULER_ENABLESCHEDULER(OS_CORE_GETSCHEDULER(coreId));
            break;
        case OS_SPINLOCK_LOCK_NOTHING:
            /* Do nothing. */
            break;
    default:
            ret = E_OS_VALUE;
        break;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Spinlock_GetSpinlockSimp
*
* Explanation: Uses to get a spinlock.
*
* Param: spinlockCfg: Reference to an spinlock.
*        spinListHead: Spinlock list head.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Spinlock_GetSpinlockSimp
(
    P2CONST(Os_SpinlockCfgType, AUTOMATIC, OS_APPL_CONST) spinlockCfg,
    P2VAR(Os_ListNodeType, AUTOMATIC, OS_APPL_DATA) spinListHead
)
{
    Os_SpinlockType result;

    if( NULL_PTR != spinlockCfg )
    {
        do
        {
            /* Try to get the lock. */
            result = Os_Arch_SpinTryLock(&(spinlockCfg->spinDyn->spinlock));
        } while( OS_SPINLOCK_UNLOCK == result );
        Os_List_Push(spinListHead, &spinlockCfg->spinDyn->spinListNode);
    }
}

/*
********************************************************************************
* Function Name: Os_Spinlock_TryToGetSpinlockSimp
*
* Explanation: Uses to try get a spinlock.
*
* Param: spinlockCfg: Reference to an spinlock.
*        spinListHead: Spinlock list head.
*
* Retval: OS_SPINLOCK_UNLOCK: Spinlock unlock.
*         OS_SPINLOCK_LOCK: Spinlock lock.
********************************************************************************
*/
LOCAL_INLINE FUNC(Os_SpinlockType, OS_CODE)  Os_Spinlock_TryToGetSpinlockSimp
(
    P2CONST(Os_SpinlockCfgType, AUTOMATIC, OS_APPL_CONST) spinlockCfg,
    P2VAR(Os_ListNodeType, AUTOMATIC, OS_APPL_DATA) spinListHead
)
{
    Os_SpinlockType result;
    /* Try to get the lock. */
    result = Os_Arch_SpinTryLock(&(spinlockCfg->spinDyn->spinlock));
    if( OS_SPINLOCK_LOCK == result )
    {
        Os_List_Push(spinListHead, &spinlockCfg->spinDyn->spinListNode);
    }

    return result;
}

/*
********************************************************************************
* Function Name: Os_Spinlock_ReleaseSpinlockSimp
*
* Explanation: Uses to release a spinlock.
*
* Param: spinlockCfg: Reference to an spinlock.
*        spinListHead: Spinlock list head.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Spinlock_ReleaseSpinlockSimp
(
    P2CONST(Os_SpinlockCfgType, AUTOMATIC, OS_APPL_CONST) spinlockCfg,
    P2VAR(Os_ListNodeType, AUTOMATIC, OS_APPL_DATA) spinListHead
)
{
    if( NULL_PTR != spinlockCfg )
    {
        Os_Arch_SpinUnlock(&(spinlockCfg->spinDyn->spinlock));
        (void)Os_List_Pop(spinListHead);
    }
}

/*
********************************************************************************
* Function Name: Os_Spinlock_ReleaseSpinlockSimp
*
* Explanation: Uses to init a spinlock.
*
* Param: spinlockCfg: Reference to an spinlock.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Spinlock_Init
(
    P2CONST(Os_SpinlockCfgType, AUTOMATIC, OS_APPL_CONST) spinlockCfg
)
{
    uint16 objectIdx;

    Os_SpinlockDynType* spinlockDyn;
    /* Check the spinlockCfg is not NULL_PTR. */
    Os_ParamCheck(NULL_PTR != spinlockCfg);

    spinlockDyn = spinlockCfg->spinDyn;
    spinlockDyn->spinlock = OS_SPINLOCK_UNLOCK;
    spinlockDyn->spinId = spinlockCfg->spinId;
    spinlockDyn->order = spinlockCfg->order;
    for( objectIdx = 0U; objectIdx < (uint16)OS_COREID_COUNT; objectIdx++ )
    {
        OS_SPINLOCK_CLEAROCCURREDCORE(spinlockDyn, objectIdx);
    }
    Os_List_Init(OS_SPINLOCK_GETLIST(spinlockDyn));
}

/*
********************************************************************************
* Function Name: Os_Spinlock_IntlGetSpinlock
*
* Explanation: Internal function, uses to get a spinlock.
*
* Param: spinlockId: Reference to an spinlock.
*        coreId: Current core index.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Spinlock_IntlGetSpinlock(SpinlockIdType spinlockId, CoreIdType coreId)
{
    Os_ListNodeType* spinListHead;
    const Os_SpinlockCfgType* spinlockCfg;

    /* Get configure data. */
    spinlockCfg = OS_SPINLOCK_GETCFG(spinlockId);
    /* Get the list head of current task or isr. */
    spinListHead = Os_Spinlock_GetCurrentListHead(coreId);
    Os_Spinlock_GetSpinlockSimp(spinlockCfg, spinListHead);
}

/*
********************************************************************************
* Function Name: Os_Spinlock_IntlReleaseSpinlock
*
* Explanation: Internal function, uses to release a spinlock.
*
* Param: spinlockCfg: Reference to an spinlock.
*        coreId: Current core index.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Spinlock_IntlReleaseSpinlock(SpinlockIdType spinlockId, CoreIdType coreId)
{
    Os_ListNodeType* spinListHead;
    const Os_SpinlockCfgType* spinlockCfg;

    /* Get configure data. */
    spinlockCfg = OS_SPINLOCK_GETCFG(spinlockId);
    /* Get the list head of current task or isr. */
    spinListHead = Os_Spinlock_GetCurrentListHead(coreId);
    Os_Spinlock_ReleaseSpinlockSimp(spinlockCfg, spinListHead);
}

/*
********************************************************************************
* Function Name: Os_Spinlock_GetSpinlock
*
* Explanation: Uses to get a spinlock.
*
* Param: spinlockId: Reference to an spinlock.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid spinlockID.
*         E_OS_INTERFERENCE_DEADLOCK: A TASK tries to occupy the spinlock while
*                                     the lock is already occupied by a TASK on
*                                     the same core. This would cause a deadlock.
*         E_OS_ACCESS: The spinlock cannot be accessed.
*         E_OS_NESTING_DEADLOCK: A TASK tries to occupy a spinlock while holding
*                                a different spinlock in a way that may cause a
*                                deadlock.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_VALUE: Error method.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Spinlock_GetSpinlock(SpinlockIdType spinlockId)
{
    Os_StatusType ret;
    CoreIdType coreId;
    Os_ListNodeType* spinListHead;
    const Os_SpinlockCfgType* spinlockCfg;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_GetSpinlock);
    /* Get the current logical core id. */
    coreId = Os_Core_GetLogicId();

    if( spinlockId >= OS_SPINLOCKID_COUNT ) /* If resource id is out range. */
    {
        ret = E_OS_ID;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_GETSPINLOCK_ACCESS) ) /* If the api is not accessible. */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        spinlockCfg = OS_SPINLOCK_GETCFG(spinlockId);
        if( OS_APPMATCH(spinlockCfg->accessingApps, OS_CORE_GETAPPID(coreId)) )
        {
            ret = E_OS_ACCESS;
        }
        else if( TRUE == Os_Spinlock_CheckOccurredInLocal(spinlockCfg, coreId) )
        {
            ret = E_OS_INTERFERENCE_DEADLOCK;
        }
#if( OS_CFG_SPINLOCKNEST_ENABLE == STD_ON )
        else if( TRUE != Os_Spinlock_CheckErrorOrder(spinlockCfg, coreId) )
        {
            ret = E_OS_NESTING_DEADLOCK;
        }
#else
        else if( TRUE == Os_Spinlock_CheckNest(coreId) )
        {
            ret = E_OS_NESTING_DEADLOCK;
        }
#endif
        else
        {
            ret = Os_Spinlock_ProcessingGetSpinlockMethod(spinlockCfg, coreId);
#if( OS_CFG_SPINLOCKNEST_ENABLE == STD_ON )
            OS_CORE_SETSPINLOCKORDER(coreId, spinlockCfg->spinDyn->order);
#endif
            OS_CORE_INCREASESPINLOCKNESTNUM(coreId);
            OS_SPINLOCK_SETOCCURREDCORE(spinlockCfg->spinDyn, coreId);
            /* Get the list head of current task or isr. */
            spinListHead = Os_Spinlock_GetCurrentListHead(coreId);
            Os_Spinlock_GetSpinlockSimp(spinlockCfg, spinListHead);

#if( (OS_CFG_ORTI_ENABLE == STD_ON) && (OS_CFG_ORTI_HOOK_ENABLE == STD_ON) )
            /* Call orti hook. */
            Os_Orit_SpinlockState_Trigger(coreId, spinlockId, OS_ORTI_SPIN_GET_TRIGGER);
#endif
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_GetSpinlock);

    return Os_Hook_CallErrorHook(OSServiceId_GetSpinlock, ret);
}

/*
********************************************************************************
* Function Name: Os_Spinlock_ReleaseSpinlock
*
* Explanation: Uses to release a spinlock.
*
* Param: spinlockId: Reference to an spinlock.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid spinlockID.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_STATE: The Spinlock is not occupied by the TASK.
*         E_OS_ACCESS: he Spinlock cannot be accessed.
*         E_OS_NOFUNC: Attempt to release a spinlock while another spinlock has
*                      to be released before.
*         E_OS_VALUE: Error method.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Spinlock_ReleaseSpinlock(SpinlockIdType spinlockId)
{
    Os_StatusType ret;
    CoreIdType coreId;
    Os_ListNodeType* spinListHead;
    const Os_SpinlockCfgType* spinlockCfg;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_GetSpinlock);
    /* Get the current logical core id. */
    coreId = Os_Core_GetLogicId();

    if( spinlockId >= OS_SPINLOCKID_COUNT ) /* If resource id is out range. */
    {
        ret = E_OS_ID;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_RELEASESPINLOCK_ACCESS) ) /* If the api is not accessible */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        spinlockCfg = OS_SPINLOCK_GETCFG(spinlockId);
        /* Get the list head of current task or isr. */
        spinListHead = Os_Spinlock_GetCurrentListHead(coreId);
        if( OS_APPMATCH(spinlockCfg->accessingApps, OS_CORE_GETAPPID(coreId)) )
        {
            ret = E_OS_ACCESS;
        }
        else if( OS_SPINLOCK_ISUNLOCKED(spinlockCfg) )
        {
            ret = E_OS_STATE;
        }
        else if( FALSE == Os_Spinlock_CheckReleaseOrder(spinlockCfg, spinListHead) )
        {
            ret = E_OS_STATE;
        }
        else
        {
            Os_Spinlock_ReleaseSpinlockSimp(spinlockCfg, spinListHead);
            OS_SPINLOCK_CLEAROCCURREDCORE(spinlockCfg->spinDyn, coreId);
            OS_CORE_DECREASESPINLOCKNESTNUM(coreId);
            ret = Os_Spinlock_ProcessingReleaseSpinlockMethod(spinlockCfg, coreId);
#if( (OS_CFG_ORTI_ENABLE == STD_ON) && (OS_CFG_ORTI_HOOK_ENABLE == STD_ON) )
            /* Call orti hook. */
            Os_Orit_SpinlockState_Trigger(coreId, spinlockId, OS_ORTI_SPIN_RELEASE_TRIGGER);
#endif
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_GetSpinlock);

    return Os_Hook_CallErrorHook(OSServiceId_ReleaseSpinlock, ret);
}

/*
********************************************************************************
* Function Name: Os_Spinlock_TryToGetSpinlock
*
* Explanation: Uses to try get a spinlock.
*
* Param: spinlockId: Reference to an spinlock.
*        success: Lock state.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid spinlockID.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_INTERFERENCE_DEADLOCK: A TASK tries to occupy the spinlock while
*                                     the lock is already occupied by a TASK on
*                                     the same core. This would cause a deadlock.
*         E_OS_ACCESS: The spinlock cannot be accessed.
*         E_OS_NESTING_DEADLOCK: A TASK tries to occupy a spinlock while holding
*                                a differentspinlock in a way that may cause a
*                                deadlock.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
*         E_OS_VALUE: Error method.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_Spinlock_TryToGetSpinlock
(
    SpinlockIdType spinlockId,
    P2VAR(TryToGetSpinlockType, AUTOMATIC, OS_APPL_DATA) success
)
{
    Os_StatusType ret;
    CoreIdType coreId;
    Os_ListNodeType* spinListHead;
    const Os_SpinlockCfgType* spinlockCfg;

    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_GetSpinlock);
    /* Get the current logical core id. */
    coreId = Os_Core_GetLogicId();

    if( spinlockId >= OS_SPINLOCKID_COUNT ) /* If resource id is out range. */
    {
        ret = E_OS_ID;
    }
    else if( NULL_PTR == success )
    {
        ret = E_OS_PARAM_POINTER;
    }
    else if( OS_CORE_PROCESSTYPEMATCH(coreId, OS_TRYTOGETSPINLOCK_ACCESS) ) /* If the api is not accessible */
    {
        ret = E_OS_CALLEVEL;
    }
    else
    {
        spinlockCfg = OS_SPINLOCK_GETCFG(spinlockId);
        if( OS_APPMATCH(spinlockCfg->accessingApps, OS_CORE_GETAPPID(coreId)) )
        {
            ret = E_OS_ACCESS;
        }
        else if( TRUE == Os_Spinlock_CheckOccurredInLocal(spinlockCfg, coreId) )
        {
            ret = E_OS_INTERFERENCE_DEADLOCK;
        }
#if( OS_CFG_SPINLOCKNEST_ENABLE == STD_ON )
        else if( TRUE != Os_Spinlock_CheckErrorOrder(spinlockCfg, coreId) )
        {
            ret = E_OS_NESTING_DEADLOCK;
        }
#else
        else if( TRUE == Os_Spinlock_CheckNest(coreId) )
        {
            ret = E_OS_NESTING_DEADLOCK;
        }
#endif
        else
        {
            /* Get the list head of current task or isr. */
            spinListHead = Os_Spinlock_GetCurrentListHead(coreId);
#if( OS_CFG_SPINLOCKNEST_ENABLE == STD_ON )
            OS_CORE_SETSPINLOCKORDER(coreId, spinlockCfg->spinDyn->order);
#endif
            OS_CORE_INCREASESPINLOCKNESTNUM(coreId);
            OS_SPINLOCK_SETOCCURREDCORE(spinlockCfg->spinDyn, coreId);
            ret = Os_Spinlock_ProcessingGetSpinlockMethod(spinlockCfg, coreId);

            if( OS_SPINLOCK_LOCK == Os_Spinlock_TryToGetSpinlockSimp(spinlockCfg, spinListHead) )
            {
                *success = TRYTOGETSPINLOCK_SUCCESS;
#if( (OS_CFG_ORTI_ENABLE == STD_ON) && (OS_CFG_ORTI_HOOK_ENABLE == STD_ON) )
                /* Call orti hook. */
                Os_Orit_SpinlockState_Trigger(coreId, spinlockId, OS_ORTI_SPIN_GET_TRIGGER);
#endif
            }
            else
            {
                ret = Os_Spinlock_ProcessingReleaseSpinlockMethod(spinlockCfg, coreId);
                OS_SPINLOCK_CLEAROCCURREDCORE(spinlockCfg->spinDyn, coreId);
                OS_CORE_DECREASESPINLOCKNESTNUM(coreId);
                *success = TRYTOGETSPINLOCK_NOSUCCESS;
            }
        }
    }
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_GetSpinlock);

    return Os_Hook_CallErrorHook(OSServiceId_TryToGetSpinlock, ret);
}

/*
********************************************************************************
* Function Name: Os_Spinlock_ForceReleaseAll
*
* Explanation: Uses to force release a spinlock.
*
* Param: spinListHead: spinlock head.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Spinlock_ForceReleaseAll
(
    P2VAR(Os_ListNodeType, AUTOMATIC, OS_APPL_DATA) spinListHead
)
{
    Os_ListNodeType* spinListTopNode;
    const Os_SpinlockCfgType* spinlockCfg;

    /* Get the current logical core id. */
    CoreIdType coreId = Os_Core_GetLogicId();
    /* Cyclic release spinlock. */
    while( TRUE != Os_List_IsEmpty(spinListHead) )
    {
        spinListTopNode = Os_List_GetTop(spinListHead);
        spinlockCfg = OS_SPINLCOK_GETCFGBYDYN(OS_SPINLOCK_LISTTSPINLOCKDYN(spinListTopNode));
        Os_Spinlock_ReleaseSpinlockSimp(spinlockCfg, spinListHead);
        if( NULL_PTR != spinlockCfg )
        {
            (void)Os_Spinlock_ProcessingReleaseSpinlockMethod(spinlockCfg, coreId);
            OS_SPINLOCK_CLEAROCCURREDCORE(spinlockCfg->spinDyn, coreId);
        }
        OS_CORE_DECREASESPINLOCKNESTNUM(coreId);
    }
}

/*
********************************************************************************
* Function Name: GetSpinlock
*
* Explanation: Standard API function, uses to get a spinlock.
*
* Param: SpinlockId: Reference to an spinlock.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid spinlockID.
*         E_OS_INTERFERENCE_DEADLOCK: A TASK tries to occupy the spinlock while
*                                     the lock is already occupied by a TASK on
*                                     the same core. This would cause a deadlock.
*         E_OS_ACCESS: The spinlock cannot be accessed.
*         E_OS_NESTING_DEADLOCK: A TASK tries to occupy a spinlock while holding
*                                a differentspinlock in a way that may cause a
*                                deadlock.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_VALUE: Error method.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) GetSpinlock(SpinlockIdType SpinlockId)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_GetSpinlock.spinlockId = SpinlockId;
    Os_SysCall(Os_Syscall_GetSpinlock_ID, &sysCallParam);
    ret = sysCallParam.Os_GetSpinlock.retVal;
#else
    ret = Os_Spinlock_GetSpinlock(SpinlockId);
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: ReleaseSpinlock
*
* Explanation: Standard API function, uses to release a spinlock.
*
* Param: SpinlockId: Reference to an spinlock.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid spinlockID.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_STATE: The Spinlock is not occupied by the TASK.
*         E_OS_ACCESS: he Spinlock cannot be accessed.
*         E_OS_NOFUNC: Attempt to release a spinlock while another spinlock has
*                      to be released before.
*         E_OS_VALUE: Error method.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) ReleaseSpinlock(SpinlockIdType SpinlockId)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_ReleaseSpinlock.spinlockId = SpinlockId;
    Os_SysCall(Os_Syscall_ReleaseSpinlock_ID, &sysCallParam);
    ret = sysCallParam.Os_ReleaseSpinlock.retVal;
#else
    ret = Os_Spinlock_ReleaseSpinlock(SpinlockId);
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: TryToGetSpinlock
*
* Explanation: Standard API function, uses to try get a spinlock.
*
* Param: SpinlockId: Reference to an spinlock.
*        Success: Lock state.
*
* Retval: E_OS_OK: No error.
*         E_OS_ID: Invalid spinlockID.
*         E_OS_CALLEVEL: Called from invalid context.
*         E_OS_INTERFERENCE_DEADLOCK: A TASK tries to occupy the spinlock while
*                                     the lock is already occupied by a TASK on
*                                     the same core. This would cause a deadlock.
*         E_OS_ACCESS: The spinlock cannot be accessed.
*         E_OS_NESTING_DEADLOCK: A TASK tries to occupy a spinlock while holding
*                                a differentspinlock in a way that may cause a
*                                deadlock.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
*         E_OS_VALUE: Error method.
********************************************************************************
*/
FUNC(StatusType, OS_CODE) TryToGetSpinlock
(
    SpinlockIdType SpinlockId,
    P2VAR(TryToGetSpinlockType, AUTOMATIC, OS_APPL_DATA) Success
)
{
    StatusType ret;

#if( OS_MEMORY_PROTECTION == STD_ON )
    Os_SysCallParamType sysCallParam;
    sysCallParam.Os_TryToGetSpinlock.spinlockId = SpinlockId;
    sysCallParam.Os_TryToGetSpinlock.success = Success;
    Os_SysCall(Os_Syscall_TryToGetSpinlock_ID, &sysCallParam);
    ret = sysCallParam.Os_TryToGetSpinlock.retVal;
#else
    ret = Os_Spinlock_TryToGetSpinlock(SpinlockId, Success);
#endif

    return ret;
}
#endif /* OS_CFG_SPINLOCK_ENABLE == STD_ON */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

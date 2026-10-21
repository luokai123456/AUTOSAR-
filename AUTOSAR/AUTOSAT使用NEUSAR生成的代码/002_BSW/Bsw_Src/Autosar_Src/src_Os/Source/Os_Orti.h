/*
********************************************************************************
*
*  File name: Os_Orti.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2022.04.06
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: WangJP/2022.12.10
* Change: Modification of coding standard.
* Cause: Optimize
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.2.14
* Change: INLINE to LOCAL_INLINE.
* Cause: Optimize
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
*/
#ifndef OS_ORTI_H_
#define OS_ORTI_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Orti_Types.h"
#include "Os_Platform_Lcfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#if( (OS_CFG_ORTI_ENABLE == STD_ON) && (OS_CFG_ORTI_API_MONITOR_ENABLE == STD_ON) )
/* Orti API monitor entry. */
#define OS_ORTI_API_MONITOR_ENTRY(serviceId)  \
(Os_CoreCfgData[Os_Core_GetLogicId()]->coreDyn->coreOrti.ortiApiId = \
(Os_OrtiApiIdType)((Os_OrtiApiIdType)serviceId | OS_ORTI_API_ENTRY_FLAG))
/* Orti API monitor exit. */
#define OS_ORTI_API_MONITOR_EXIT(serviceId)   \
(Os_CoreCfgData[Os_Core_GetLogicId()]->coreDyn->coreOrti.ortiApiId = ((Os_OrtiApiIdType)serviceId))
#else
#define OS_ORTI_API_MONITOR_ENTRY(ortiApiId)
#define OS_ORTI_API_MONITOR_EXIT(ortiApiId)
#endif

#if( (OS_CFG_ORTI_ENABLE == STD_ON) && (OS_CFG_ORTI_HOOK_ENABLE == STD_ON) )
#define OS_ORTI_SETPROTYPE(coreId, type)            (Os_CoreCfgData[coreId]->coreDyn->coreOrti.currentProcType = type)
#define OS_ORTI_SETISRSTATE(isrId, state)           (Os_IsrCfgData[isrId]->isrDyn->ortiIsrState = state)
#define OS_ORTI_SETCURRENTTASK(coreId, taskId)      (Os_CoreCfgData[coreId]->coreDyn->coreOrti.currentTask = taskId)
#define OS_ORTI_SETCURRENTISR(coreId, isrId)        (Os_CoreCfgData[coreId]->coreDyn->coreOrti.currentIsr = isrId)
#define OS_ORTI_SETCURRENTRES(coreId, resId)        (Os_CoreCfgData[coreId]->coreDyn->coreOrti.currentRes = resId)
#define OS_ORTI_SETCURRENTSPIN(coreId, spinId)      (Os_CoreCfgData[coreId]->coreDyn->coreOrti.currentSpin = spinId)
#define OS_ORTI_SETTRIGGERREASON(coreId, triggerId) (Os_CoreCfgData[coreId]->coreDyn->coreOrti.triggerId = triggerId)
#define OS_ORTI_SETAPISERVICEID(coreId, ortiApiId)  (Os_CoreCfgData[coreId]->coreDyn->coreOrt.ortiApiId = ortiApiId)
#endif

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

#if( (OS_CFG_ORTI_ENABLE == STD_ON) && (OS_CFG_ORTI_HOOK_ENABLE == STD_ON) )
/*
********************************************************************************
* Function Name: Os_Orit_IsrState_Trigger
*
* Explanation: Orit monitors isr state changes triggered.
*
* Param: coreId: Core logical index.
*        isrId: Cat2 isr index.
*        IsrState: Isr status with orti.
*        trigReason: Trigger reason.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Orit_IsrState_Trigger
(
    CoreIdType coreId,
    ISRType isrId,
    Os_OrtiIsrStateType IsrState,
    Os_OrtiTriggerReasonType trigReason
)
{
    OS_ORTI_SETPROTYPE(coreId, OS_ISR_CAT2_TYPE_MASK);
    OS_ORTI_SETCURRENTISR(coreId, isrId);
    OS_ORTI_SETISRSTATE(coreId, IsrState);
    OS_ORTI_SETTRIGGERREASON(coreId, trigReason);
    Os_Orti_ProcStateHook(trigReason, (Os_ProcType)isrId, coreId);
}

/*
********************************************************************************
* Function Name: Os_Orit_TaskState_Trigger
*
* Explanation: Orit monitors task state changes triggered.
*
* Param: coreId: Core logical index.
*        taskId: Task index.
*        trigReason: Trigger reason.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Orit_TaskState_Trigger
(
    CoreIdType coreId,
    TaskType taskId,
    Os_OrtiTriggerReasonType trigReason
)
{
    OS_ORTI_SETPROTYPE(coreId, OS_TASK_TYPE_MASK);
    OS_ORTI_SETCURRENTTASK(coreId, taskId);
    OS_ORTI_SETTRIGGERREASON(coreId, trigReason);
    Os_Orti_ProcStateHook(trigReason, (Os_ProcType)taskId, coreId);
}

/*
********************************************************************************
* Function Name: Os_Orit_ResourceState_Trigger
*
* Explanation: Orit monitors resource state changes triggered.
*
* Param: coreId: Core logical index.
*        resId: Resource index.
*        trigReason: Trigger reason.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Orit_ResourceState_Trigger
(
    CoreIdType coreId,
    ResourceType resId,
    Os_OrtiTriggerReasonType trigReason
)
{
    OS_ORTI_SETPROTYPE(coreId, OS_TASK_TYPE_MASK);
    OS_ORTI_SETCURRENTRES(coreId, resId);
    OS_ORTI_SETTRIGGERREASON(coreId, trigReason);
    Os_Orti_ProcStateHook(trigReason, (Os_ProcType)resId, coreId);
}

/*
********************************************************************************
* Function Name: Os_Orit_SpinlockState_Trigger
*
* Explanation: Orit monitors spinlock state changes triggered.
*
* Param: coreId: Core logical index.
*        spinId: Spinlock index.
*        trigReason: Trigger reason.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Orit_SpinlockState_Trigger
(
    CoreIdType coreId,
    SpinlockIdType spinId,
    Os_OrtiTriggerReasonType trigReason
)
{
    OS_ORTI_SETPROTYPE(coreId, OS_TASK_TYPE_MASK);
    OS_ORTI_SETCURRENTSPIN(coreId, spinId);
    OS_ORTI_SETTRIGGERREASON(coreId, trigReason);
    Os_Orti_ProcStateHook(trigReason, (Os_ProcType)spinId, coreId);
}

/*
********************************************************************************
* Function Name: Os_Orit_InterruptState_Trigger
*
* Explanation: Orit monitors interrupt state changes triggered.
*
* Param: coreId: Core logical index.
*        trigReason: Trigger reason.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Orit_InterruptState_Trigger
(
    CoreIdType coreId,
    Os_OrtiTriggerReasonType trigReason
)
{
    OS_ORTI_SETTRIGGERREASON(coreId, trigReason);
    Os_Orti_InterruptStateHook(trigReason, coreId);
}
#endif

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_ORTI_H_ */


/*
********************************************************************************
*
*  File name: Os_Core.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.22
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2022.11.21
* Change: Change OS_VAR_NOINIT to OS_VAR_NO_INIT.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: WangJP/2022.12.10
* Change: Modification of coding standard.
* Cause: Optimize
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2022.12.21
* Change: New functions ShutDownAllCore.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2023.1.29
* Change: Resolve the CallErrorHook privilege level problem.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.2.14
* Change: Add memory protection related macros.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: LiG/2023.2.23
* Change: Compile macro error.
* Cause: Bugfix
********************************************************************************
* Version: 3.8
* Author/Date: LiG/2023.10.3
* Change: Add IdleControl function related macros and coding specification issues.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: LiG/2023.10.8
* Change: Optimize ControlIdle function.
* Cause: Optimizing
********************************************************************************
* Version: 3.10
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
*/
#ifndef OS_CORE_H_
#define OS_CORE_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Core_Types.h"
#include "Os_Counter.h"
#include "Os_Arch_Core.h"
#include "Os_Arch_Kernal_Lcfg.h"
#include "Os_Platform_Lcfg.h"
#include "Os_Arch_Lcfg.h"
#include "Os_Orti.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Isr context storage offset. */
#define OS_CORE_ISRCONTEXTOFFSET                          (1U)
/* Spinlock nest offset. */
#define OS_CORE_SPINLOCKNESTOFFSET                        (1U)
/* Determine whether it is a system application id. */
#define OS_IFSYSAPP(coreId, appId)                        (Os_CoreCfgData[coreId]->systemApp->AppId == (appId))
/* Determine whether interrupts is disable. */
#define OS_CORE_MASK_INTERRUPT(coreId)                    ((Os_CoreCfgData[coreId]->coreDyn->intState->intApiState.suspendCnt != 0U) || \
                                                          (TRUE == Os_CoreCfgData[coreId]->coreDyn->intState->intApiState.disableFlag) || \
                                                          (Os_CoreCfgData[coreId]->coreDyn->intState->intApiState.suspendOsCnt != 0U))
/* Determine whether the api is not accessible. */
#define OS_CORE_PROCESSTYPEMATCH(coreId, mask)            ((Os_CoreCfgData[coreId]->coreDyn->currentProcType & (mask)) == 0U)
/* Determine whether the app is valid. */
#define OS_CORE_APPISVALID(coreId)                        (Os_CoreCfgData[coreId]->coreDyn->AppId == INVALID_OSAPPLICATION)
/* Get the currently running app id of the core. */
#define OS_CORE_GETAPPID(coreId)                          (Os_CoreCfgData[coreId]->coreDyn->AppId)
/* Set the currently running app id of the core. */
#define OS_CORE_SETAPPID(coreId, appId)                   (Os_CoreCfgData[coreId]->coreDyn->AppId = (appId))
/* Get the core static configuration through core id. */
#define OS_CORE_GETCFG(coreId)                            (Os_CoreCfgData[coreId])
/* Get the core dynamic configuration through core id. */
#define OS_CORE_GETDYN(coreId)                            (Os_CoreCfgData[coreId]->coreDyn)
/* Get the currently context type of the core. */
#define OS_CORE_GETPROTYPE(coreId)                        (Os_CoreCfgData[coreId]->coreDyn->currentProcType)
/* Determine whether the current context is cat2 isr. */
#define OS_CORE_CHECKCURRENTINISR(coreId)                 (OS_ISR_CAT2_TYPE_MASK == Os_CoreCfgData[coreId]->coreDyn->currentProcType)
/* Determine whether the current context is task. */
#define OS_CORE_CHECKCURRENTINTASK(coreId)                (OS_TASK_TYPE_MASK == Os_CoreCfgData[coreId]->coreDyn->currentProcType)
/* Set the currently context type of the core. */
#define OS_CORE_SETPROTYPE(coreId, type)                  (Os_CoreCfgData[coreId]->coreDyn->currentProcType = (type))
/* Set the currently context type of the core. */
#define OS_CORE_ALLOWSCH(coreId)                          (Os_CoreCfgData[coreId]->coreDyn->allowSchedule = TRUE)
/* Determine whether to disable scheduling. */
#define OS_CORE_DISABLESCH(coreId)                        (Os_CoreCfgData[coreId]->coreDyn->allowSchedule = FALSE)
/* Get scheduler allowSchedule flags. */
#define OS_CORE_GETALLOWSCH(coreId)                       (Os_CoreCfgData[coreId]->coreDyn->allowSchedule)
/* Get scheduler configuration by owning core. */
#define OS_CORE_GETSCHEDULER(coreId)                      (Os_CoreCfgData[coreId]->scheduler)
/* Get the currently running task of the core. */
#define OS_CORE_GETCURRENTTASK(coreId)                    (Os_CoreCfgData[coreId]->coreDyn->currentTask)
/* Get the current core's next task to run. */
#define OS_CORE_GETNEXTTASK(coreId)                       (Os_CoreCfgData[coreId]->scheduler->schdDyn->nextTask)
/* Get the currently running task id of the core. */
#define OS_CORE_GETCURRENTTASKID(coreId)                  (Os_CoreCfgData[coreId]->coreDyn->currentTask->taskId)
/* Get the currently running cat2 isr of the core. */
#define OS_CORE_GETCURRENTISR(coreId)                     (Os_CoreCfgData[coreId]->coreDyn->currentIsr)
/* Get the currently running cat2 isr id of the core. */
#define OS_CORE_GETCURRENTISRID(coreId)                   (Os_CoreCfgData[coreId]->coreDyn->currentIsr->isrId)
/* Set the currently running task of the core. */
#define OS_CORE_SETCURRTASK(coreId, task)                 (Os_CoreCfgData[coreId]->coreDyn->currentTask = (task))
/* Set the currently running isr of the core. */
#define OS_CORE_SETCURRISR(coreId, isr)                   (Os_CoreCfgData[coreId]->coreDyn->currentIsr = (isr))
/* Get the current interrupt nesting number. */
#define OS_CORE_GETINTCNTS(coreId)                        (Os_CoreCfgData[coreId]->coreDyn->intState->intCnts)
/* Get the error information of the current core. */
#define OS_CORE_GETERRORDATA(coreId)                      (Os_CoreCfgData[coreId]->coreDyn->errorInformation)
/* Get the service id of the execution error. */
#define OS_CORE_GETERRORSERVICEID(coreId)                 (Os_CoreCfgData[coreId]->coreDyn->errorInformation.serviceErrorId)
/* Set the service id of the execution error. */
#define OS_CORE_SETERRORSERVICEID(coreId, serviceId)      (Os_CoreCfgData[coreId]->coreDyn->errorInformation.serviceErrorId = (serviceId))
/* Set the error id of the error information. */
#define OS_CORE_SETERRORSTATUS(coreId, error)             (Os_CoreCfgData[coreId]->coreDyn->errorInformation.error = (error))
/* Set the caller id of the error information. */
#define OS_CORE_SETERRORCALLER(coreId, caller)            (Os_CoreCfgData[coreId]->coreDyn->errorInformation.callerId = (caller))
/* Set the processor id of the error information. */
#define OS_CORE_SETERRORPROCTID(coreId, Proct)            (Os_CoreCfgData[coreId]->coreDyn->errorInformation.ProctId = (Proct))
/* Get the app static configuration through core id. */
#define OS_CORE_GETCORECFGSYSAPP(coreId)                  (Os_CoreCfgData[coreId]->systemApp)
/* Get the protection hook through core id. */
#define OS_CORE_GETCOREPTOTECTIONHOOK(coreId)             (Os_CoreCfgData[coreId]->protectionHook)
/* Get the number of applications configured by owning core. */
#define OS_CORE_GETCOREAPPCOUNTER(coreId)                 (Os_CoreCfgData[coreId]->appCnt)
/* Determine core id is invalid. */
#define OS_CORE_ISNOTVALID(coreId)                        ((coreId) >= OS_COREID_COUNT)
/* Determine core is master core. */
#define OS_CORE_ISMASTER(coreId)                          (Os_CoreCfgData[coreId]->coreIfMaster == OS_CORE_ID_MASTER)
/* Get the number of applications configured by core static configuration. */
#define OS_CORE_GETCOREAPPNUMBER(coreCfg)                 ((coreCfg)->appCnt)
/* Get the applications id by applications reference index. */
#define OS_CORE_GETCOREAPPLICATIONID(coreId, index)       (Os_CoreCfgData[coreId]->appRefs[index]->AppId)
/* Get spinlock nesting count. */
#define OS_CORE_GETSPINLOCKNESTNUM(coreId)                (Os_CoreCfgData[coreId]->coreDyn->corePreSpinOrder.nestNum)
/* Spinlock nesting count plus 1. */
#define OS_CORE_INCREASESPINLOCKNESTNUM(coreId)           (Os_CoreCfgData[coreId]->coreDyn->corePreSpinOrder.nestNum++)
/* Spinlock nesting count minus 1. */
#define OS_CORE_DECREASESPINLOCKNESTNUM(coreId)           (Os_CoreCfgData[coreId]->coreDyn->corePreSpinOrder.nestNum--)
/* Get spinlock lock order. */
#define OS_CORE_GETSPINLOCKORDER(coreId) (Os_CoreCfgData[coreId]->coreDyn->corePreSpinOrder.order[Os_CoreCfgData[coreId]->coreDyn->corePreSpinOrder.nestNum - OS_CORE_SPINLOCKNESTOFFSET])
/* Set spinlock lock order. */
#define OS_CORE_SETSPINLOCKORDER(coreId, setOrder) \
    (Os_CoreCfgData[coreId]->coreDyn->corePreSpinOrder.order[Os_CoreCfgData[coreId]->coreDyn->corePreSpinOrder.nestNum] = (setOrder))
/* Get system configuration. */
#define OS_GETSYSTEMCFG()  (&Os_SystemCfgData)
/* Get multi-core service trigger interrupt source. */
#define OS_CORE_GETMULTICOMMISRSOURCE(coreId)             (Os_CoreCfgData[coreId]->multiCommIsrSource)
/* Set idle mode. */
#define OS_CORE_SETIDLEMODE(coreId, mode)                 (Os_CoreCfgData[coreId]->coreDyn->coreIdleMode = (mode))
#define OS_CORE_SETIDLEMODESTATE(coreId, state)           (Os_CoreCfgData[coreId]->coreDyn->coreIdleModeState = (state))
/* Get idle mode. */
#define OS_CORE_GETIDLEMODE(coreId)                       (Os_CoreCfgData[coreId]->coreDyn->coreIdleMode)
#define OS_CORE_GETIDLEMODESTATE(coreId)                  (Os_CoreCfgData[coreId]->coreDyn->coreIdleModeState)
/* Get idle task. */
#define OS_CORE_GETIDLETASK(coreId)                       (Os_CoreCfgData[coreId]->idleTask)

#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
/* Switch Mask for time protection. */
#define OS_CORE_CHECKTPMASK                               (1U)
/* Get the time protection budget that the current core is monitoring. */
#define OS_CORE_GETTPCURRENTBUDGET(coreId)                (Os_CoreCfgData[coreId]->tpBaseCfg->dyn->tp_CurrentBudget)
/* Set the time protection budget that the current core is monitoring. */
#define OS_CORE_SETTPCURRENTBUDGET(coreId, currentBudget) (Os_CoreCfgData[coreId]->tpBaseCfg->dyn->tp_CurrentBudget = (currentBudget))
/* Determine whether the current core time protection is enabled. */
#define OS_CORE_CHECKTPISENABLE(coreId)                   ((OS_CFG_TP_ENABLE & ((uint32)OS_CORE_CHECKTPMASK << (uint32)(coreId))) != 0U)
#endif
#if( (OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
/* Get current application mpu configuration data. */
#define OS_CORE_GETCURRAPPMPUCFG(coreId)                  (Os_CoreCfgData[coreId]->coreDyn->appMpuCfg)
/* Get current mpu configuration data. */
#define OS_CORE_GETCURRMPUCFG(coreId)                     (Os_CoreCfgData[coreId]->coreDyn->mpuCfg)
/* Set current application mpu configuration data. */
#define OS_CORE_SETCURRAPPMPUCFG(coreId, setMpuCfg)       (Os_CoreCfgData[coreId]->coreDyn->appMpuCfg = (setMpuCfg))
/* Get current mpu configuration data. */
#define OS_CORE_SETCURRMPUCFG(coreId, setMpuCfg)          (Os_CoreCfgData[coreId]->coreDyn->mpuCfg = (setMpuCfg))
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
/*
********************************************************************************
* Function Name: Os_Core_GetLogicId
*
* Explanation: Get the current core logic id.
*
* Param: None
*
* Retval: Core logical id.
********************************************************************************
*/
LOCAL_INLINE FUNC(CoreIdType, OS_CODE) Os_Core_GetLogicId(void)
{
    OS_ORTI_API_MONITOR_ENTRY(OSServiceId_GetCoreID);
#if( OS_CFG_MULTI_CORE == STD_ON )
    uint32  corePhysicId = Os_Arch_GetCoreId();
    Os_ParamCheck(corePhysicId < OS_ARCH_PHYSICAL_CORE_NUM);
    OS_ORTI_API_MONITOR_EXIT(OSServiceId_GetCoreID);

    return Os_Arch_CoreMappingTable[corePhysicId];
#else
    return (CoreIdType)0U;
#endif
}

/*
********************************************************************************
* Function Name: Os_Core_IsrBuffPush
*
* Explanation: Push interrupted context buff.
*
* Param: coreId: Core logical index.
*        context: Interrupted context.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Core_IsrBuffPush
(
    CoreIdType coreId,
    P2VAR(Os_Arch_ContextDynType*, AUTOMATIC, OS_APPL_DATA) context
)
{
    /* Get the current core dyn. */
    Os_CoreDynType* coreDyn = OS_CORE_GETDYN(coreId);

    /* Check buff is full. */
    Os_ParamCheck(coreDyn->intState->intCnts < (uint16)OS_MAX_INTCNTS);

    coreDyn->intState->intContextBuffs[coreDyn->intState->intCnts] = context;
    coreDyn->intState->intCnts++;
}

/*
********************************************************************************
* Function Name: Os_Core_IsrBuffPop
*
* Explanation: Pop interrupted context buff.
*
* Param: coreId: Core logical index.
*
* Retval: Interrupted context.
********************************************************************************
*/
LOCAL_INLINE FUNC_P2VAR(Os_Arch_ContextDynType*, OS_APPL_DATA, OS_CODE) Os_Core_IsrBuffPop(CoreIdType coreId)
{
    /* Get the current core dyn. */
    Os_CoreDynType* coreDyn = OS_CORE_GETDYN(coreId);
    /* Check buff is empty. */
    Os_ParamCheck( coreDyn->intState->intCnts > 0U);

    coreDyn->intState->intCnts--;

    return coreDyn->intState->intContextBuffs[coreDyn->intState->intCnts];
}

/*
********************************************************************************
* Function Name: Os_Core_IsrGetIsrBuff
*
* Explanation: Get the interrupted context.
*
* Param: coreId: Core logical index.
*
* Retval: Interrupted context.
********************************************************************************
*/
LOCAL_INLINE FUNC_P2VAR(Os_Arch_ContextDynType, OS_APPL_DATA, OS_CODE) Os_Core_IsrGetIsrBuff(CoreIdType coreId)
{
    /* Get the current core dyn. */
    Os_CoreDynType* coreDyn = OS_CORE_GETDYN(coreId);
    /* Check buff is empty. */
    Os_ParamCheck( coreDyn->intState->intCnts > 0U);

    return &(coreDyn->intState->intIsrContextBuffs[coreDyn->intState->intCnts - OS_CORE_ISRCONTEXTOFFSET]);
}

extern FUNC(void, OS_CODE) Os_Core_Shutdown
(
    StatusType error,
    CoreIdType coreId,
    boolean sync
);
extern FUNC(void, OS_CODE) Os_Core_ShutdownOs(StatusType error);
extern FUNC(void, OS_CODE) Os_Core_ShutdownAllCores(StatusType error);
extern FUNC_P2VAR(Os_Arch_ContextDynType*, OS_APPL_DATA, OS_CODE) Os_Core_GetCurrentContext(void);
extern FUNC_P2VAR(Os_TaskDynType, OS_APPL_DATA, OS_CODE) Os_Core_GetCurrentTask(void);
extern FUNC(void, OS_CODE) Os_Core_TerminationApp(CoreIdType coreId, ApplicationType appId);
extern FUNC(void, OS_CODE) Os_Core_DisableAllInterrupts(void);
extern FUNC(void, OS_CODE) Os_Core_EnableAllInterrupts(void);
extern FUNC(void, OS_CODE) Os_Core_SuspendAllInterrupts(void);
extern FUNC(void, OS_CODE) Os_Core_ResumeAllInterrupts(void);
extern FUNC(void, OS_CODE) Os_Core_SuspendOSInterrupts(void);
extern FUNC(void, OS_CODE) Os_Core_ResumeOSInterrupts(void);
extern FUNC(void, OS_CODE) Os_Core_CleanInterrupts(CoreIdType coreId);
extern FUNC(void, OS_CODE) Os_TargetShutDownAllCore(StatusType error);
extern FUNC(StatusType, OS_CODE) Os_Core_ControlIdle
(
    CoreIdType CoreID,
    IdleModeType IdleMode
);

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_CORE_H_ */


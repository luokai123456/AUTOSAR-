/*
********************************************************************************
*
*  File name: Os_Task_Types.h
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
*/
#ifndef OS_TASK_TYPES_H_
#define OS_TASK_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types.h"
#include "Os_Event_Types.h"
#include "Os_Hook_Types.h"
#include "Os_Arch_Context_Types.h"
#include "Os_List.h"
#include "Os_Cfg.h"
#include "Os_MemProtection_Types.h"
#include "Os_TmProtection_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define OS_TASK_BT   (0x00U)    /* Basic task type. */
#define OS_TASK_ET   (0x01U)    /* Extended task type. */

#define OS_TASK_FULL (0x00U)    /* Task is preemptable. */
#define OS_TASK_NON  (0x01U)    /* Task is not preemptable. */

#define OS_TASK_INIT (0U)       /* Task initial zero value. */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef uint8 Os_TaskKindType;
typedef uint8 Os_TaskSchdType;

struct Os_TaskDyn
{
    /* The hardware context need saved. */
    Os_Arch_ContextDynType* context;
    /* List head of resource. */
    Os_ListNodeType resListHead;
    /* List head of spinlock. */
    Os_ListNodeType spinListHead;
    /* Dynamic config of the event. */
    Os_EventDynType eventDyn;
    /* Current scheduling state. */
    TaskStateType state;
    /* Current scheduling priority. */
    Os_TaskPrioType currentPrio;
    /* Currently running app. */
    ApplicationType currentAppId;
    /* Counts how many times a task may be activated. */
    Os_ActivationCntType activationsCnt;
    /* The Id for this task. */
    TaskType taskId;
    /* The schedule type of the task. */
    Os_TaskSchdType schdType;
};

struct Os_TaskCfg
{
    /* Config context of the task. */
    const Os_Arch_ContextCfgType* contextCfg;
    /* Owner application. */
    ApplicationType ownerAppId;
#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
    /* Timing protection configuration of the task. */
    const Os_TpCfgType* tpCfg;
#endif
#if( (OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
    /* Current application memory protection settings. */
    const Os_MpCfgType* appMpCfg;
    /* Current task memory protection settings. */
    const Os_MpCfgType* taskMpCfg;
#endif
    /* Dynamic config of the task. */
    struct Os_TaskDyn* taskDyn;
    /* The configured priority of the task. */
    Os_TaskPrioType cfgPrio;
    /* The schedule type of the task. */
    Os_TaskSchdType schdType;
    /* The maximum number of multiple activation. */
    Os_ActivationCntType maxActivations;
    /* Hook to be called before task is started. May be NULL_PTR. */
    Os_PreTaskHookType preTaskHook;
    /* Hook to be called before task is resumed. May be NULL_PTR. */
    Os_PostTaskHookType postTaskHook;
    /* Reference to applications which access this object. */
    uint32 accessingApps;
    /* The Id for this task. */
    TaskType taskId;
    /* The core id. */
    CoreIdType coreId;
    /* The task is basic or extended. */
    Os_TaskKindType taskType;
    /* Autostart mode. */
    AppModeType appMode;
};

typedef struct Os_TaskDyn Os_TaskDynType;
typedef struct Os_TaskCfg Os_TaskCfgType;
typedef Os_TaskCfgType* Os_TaskCfgRefType;
typedef Os_TaskDynType* Os_TaskDynRefType;

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

#endif /* OS_TASK_TYPES_H_ */

/*
********************************************************************************
*
*  File name: Os_Orti_Types.h
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
*/
#ifndef OS_ORTI_TYPES_H_
#define OS_ORTI_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define OS_ORTI_ISR_INIT                  (0U)
#define OS_ORTI_ISR_START                 (1U)
#define OS_ORTI_ISR_END                   (2U)

#define OS_ORTI_ISR_INIT_TRIGGER          (1U)
#define OS_ORTI_TASK_INIT_TRIGGER         (2U)
#define OS_ORTI_TASK_STARTFIRST_TRIGGER   (3U)
#define OS_ORTI_TASK_ACTIVATE_TRIGGER     (4U)
#define OS_ORTI_TASK_SETEVENT_TRIGGER     (5U)
#define OS_ORTI_TASK_TERMINATED_TRIGGER   (6U)
#define OS_ORTI_TASK_SWITCH_TRIGGER       (7U)
#define OS_ORTI_ISR_ENTRY_TRIGGER         (8U)
#define OS_ORTI_RES_GET_TRIGGER           (9U)
#define OS_ORTI_RES_RELEASE_TRIGGER       (10U)
#define OS_ORTI_SPIN_GET_TRIGGER          (11U)
#define OS_ORTI_SPIN_RELEASE_TRIGGER      (12U)
#define OS_ORTI_INT_DISABLE_ALL_TRIGGER   (13U)
#define OS_ORTI_INT_ENABLE_ALL_TRIGGER    (14U)
#define OS_ORTI_INT_SUSPEND_ALL_TRIGGER   (16U)
#define OS_ORTI_INT_RESUME_ALL_TRIGGER    (17U)
#define OS_ORTI_INT_SUSPENDOS_ALL_TRIGGER (18U)
#define OS_ORTI_INT_RESUMEOS_ALL_TRIGGER  (19U)

#define OS_ORTI_API_ENTRY_FLAG            ((uint16)0x8000U)
#define OS_ORTI_PROC_ISR_FLAG             ((uint32)0x80000000U)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef uint16 Os_OrtiApiIdType;
typedef uint8  Os_OrtiIsrStateType;
typedef uint8  Os_OrtiTriggerReasonType;

struct Os_Orti_CoreCfg
{
    Os_ProcType currentProcType;
    TaskType currentTask;
    ISRType  currentIsr;
    ResourceType currentRes;
    SpinlockIdType currentSpin;
    Os_OrtiTriggerReasonType trigReason;
    Os_OrtiApiIdType ortiApiId;
};

typedef struct Os_Orti_CoreCfg Os_Orti_CoreCfgType;

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

#endif /* OS_ORTI_TYPES_H_ */

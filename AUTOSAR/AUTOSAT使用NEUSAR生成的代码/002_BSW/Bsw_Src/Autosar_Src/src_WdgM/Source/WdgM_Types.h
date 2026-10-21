/*
********************************************************************************
*
*  File name: WdgM_Types.h
*
*  Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : WangCong/2019.04.12
* Change: New
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : WangCong/2019.08.24
* Change: Add Types:
*         WdgM_ExLogicalVariableType
*         Change Types:
*         WdgM_ExternalLogicalSupervisionType
* Cause:  Types Define Modification
********************************************************************************
* Version: 3.0
* Author/Date : Baowanglong/2020.03.27
* Change: Only version update to V3.0.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date : Baowanglong/2020.05.25
* Change: Modify the file according to the code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date : WuZB/2020.12.01
* Change: Modify WdgM_ExternalLogicalSupervisionType to WdgM_ExLogicalSupervisionType.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date : WuZB/2021.10.28
* Change: Modify "WdgIf_Types.h" to "WdgIf.h".
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date : WuZB/2022.01.04
* Change: Modify "WDGM_E_NO_INIT" to "WDGM_E_UNINIT".
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date : WangXG/2022.09.22
* Change: Added WdgM support for multi-core functionality
* Cause: Corresponding new functions.
********************************************************************************
* Version: 3.6
* Author/Date : WangXG/2022.10.25
* Change: Remove Debugtype
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date : WangXG/2023.03.03
* Change: Modify WdgM_ TriggerType structure appends TriggerCoreRefID member
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date : XuYH/2023.08.07
* Change: Delete AUTOSAR define
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date : LiuY/2024.03.18
* Change: 1. Add local status parameters of supervised entity in "WdgM_ModeStructType".
*         2. Delete "MULTI_CORE_SUPPORTED" and "MULTI_CORE_UNSUPPORTED".
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date : LiuY/2024.06.12
* Change: 1. Add macro definitions of "WDGM_AUTOSAR422" and "WDGM_AUTOSAR440".
* Cause: Bugfix
********************************************************************************
* Version: 3.11
* Author/Date: LiuY/2024.08.02
* Change: Update copyright information.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: LiuY/2025.02.27
* Change: Add notification function member in WdgM_ModeStructType and WdgM_SEGType.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: LiuY/2025.03.07
* Change: Add macro definitions and struct members for multi-core synchronous
*         monitoring mechanism.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: Chixp/2025.03.26
* Change: Fix the QAC warning.
* Cause: Optimization
********************************************************************************
* Version: 3.15
* Author/Date: Chixp/2025.06.05
* Change: Fix the polyspace warning and add the polyspace deviation suppression
*         comment.
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: Chixp/2025.06.16
* Change: Delete macro definitions related to WdgM_LocalStatusType and WdgM_GlobalStatusType.
* Cause: Optimization
********************************************************************************
*/
#ifndef WDGM_TYPES_H_
#define WDGM_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "WdgIf.h"
#include "BswM_WdgM.h"
#include "Rte_WdgM.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define WDGM_VALUE_ZERO                 (0U)
#define WDGM_VALUE_ONE                  (1U)
#define WDGM_VALUE_TWO                  (2U)

#define WDGM_ALL_SPV_DISABLE            (0x00U)
#define WDGM_ALIVE_SPV_ENABLE           (0x01U)      /* Bit 0 */
#define WDGM_DEADLINE_SPV_ENABLE        (0x02U)      /* Bit 1 */
#define WDGM_LOGICAL_SPV_ENABLE         (0x04U)      /* Bit 2 */
#define WDGM_EXLOGICAL_SPV_ENABLE       (0x08U)      /* Bit 3 */

/* Alive Statuses. */
#define WDGM_AlLIVE_CORRECT             (0U)
#define WDGM_AlLIVE_INCORRECT_NOEX      (1U)
#define WDGM_AlLIVE_INCORRECT_EX        (2U)

/* DeadLine Statuses. */
#define WDGM_DEADLINE_CORRECT           (0U)
#define WDGM_DEADLINE_INCORRECT         (1U)

/* Logical Statuses. */
#define WDGM_LOGICAL_CORRECT            (0U)
#define WDGM_LOGICAL_INCORRECT          (1U)

/* INIT Statuses. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define WDGM_INIT_FALSE                 (0U)
#define WDGM_INIT_TRUE                  (1U)

#define WDGM_FIRSTEXPSEID_INVALID       (0xFFFFU)

/* Development Errors. */
#define WDGM_E_NO_ERR                   (0x00U)

/*Error codes. */
#define WDGM_E_UNINIT                   (0x10U) /* Error code: API service called if WdgM uninitialized. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define WDGM_E_PARAM_CONFIG             (0x11U) /* Error code: API service WdgM_Init() called with wrong parameter. */
#define WDGM_E_PARAM_MODE               (0x12U) /* Error code: API service WdgM_SetMode() called with wrong parameter. */
#define WDGM_E_PARAM_SEID               (0x13U) /* Error code: API service WdgM_Init() called and no supervised entity is configured. */
                                                /* Error code: API service called with wrong supervised entity id. */
#define WDGM_E_INV_POINTER              (0x14U) /* Error code: API service called with NULL_PTR as parameter. */
#define WDGM_E_DISABLE_NOT_ALLOWED      (0x15U) /* Error code: API service WdgM_Init() called and a trigger mode is erroneously configured to be OFF and OFF mode is not allowed. */
#define WDGM_E_CPID                     (0x16U) /* Error code: API service WdgM_Init() called and on checkpoint is configured in a supervised entity. */
                                                /* Error code: API service WdgM_CheckpointReached() called with wrong checkpoint id. */
#define WDGM_E_DEPRECATED               (0x17U) /* Error code: Not used. */

#define WDGM_E_SEDEACTIVATED            (0x19U) /* Error code: API service used with a checkpoint of a Supervised Entity that is deactivated inthe current Watchdog Manager mode. */

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define WDGM_E_SUPERVISION              (0x28U) /* Error code: Supervision has failed and a watchdog reset will occur. */
#define WDGM_E_SET_MODE                 (0x29U) /* Error code: Watchdog drivers mode switch has failed. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define WDGM_E_IMPROPER_CALLER          (0x2AU) /* Error code: Defensive behavior checks have detected an improper caller. */
#define WDGM_E_GETELAPSEDVALUE_OS_ID    (0x2BU) /* Error code: API GetElapsedValue: E_OS_ID (only in EXTENDED status): The CounterID was not valid. */
#define WDGM_E_GETELAPSEDVALUE_OS_VALUE (0x2CU) /* Error code: API GetElapsedValue: E_OS_VALUE (only in EXTENDED status): The given Value was not valid. */
#define WDGM_E_GETELAPSEDVALUE_OS_EXCEPTION     (0x2DU) /* Error code: API GetElapsedValue:Not Define. */
#define WDGM_E_MODULE_CONFIG             (0x30U) /* WdgM module configuration error. */

/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_WdgM_Rule17.8" */
#define WDGM_DUMMY_STATEMENT(v) (v)=(v)

#define WDGM_INSTANCE_ID_DET             (0U)

#define WDGM_SERVICEID_INIT                 (0x00U)
#define WDGM_SERVICEID_DEINIT               (0x01U)
#define WDGM_SERVICEID_GETVERSIONINFO       (0x02U)
#define WDGM_SERVICEID_SETMODE              (0x03U)
#define WDGM_SERVICEID_GETMODE              (0x0BU)
#define WDGM_SERVICEID_CHECKPOINTREACHED    (0x0EU)
#define WDGM_SERVICEID_UPDATEALIVECOUNTER   (0x04U)
#define WDGM_SERVICEID_GETLOCALSTATUS       (0x0CU)
#define WDGM_SERVICEID_GETGLOBALSTATUS      (0x0DU)
#define WDGM_SERVICEID_PERFORMRESET         (0x0FU)
#define WDGM_SERVICEID_GETFIRSTEXPIREDSEID  (0x10U)
#define WDGM_SERVICEID_MAINFUNCTION         (0x08U)

#define WDGM_AUTOSAR422                     (0x00U)
#define WDGM_AUTOSAR440                     (0x01U)

/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define WDGM_STATECOMBINER_CONFNOTRIGGER    (0x00U)
#define WDGM_STATECOMBINER_MASTERTRIGGER    (0x01U)
#define WDGM_STATECOMBINER_SLAVETRIGGER     (0x02U)

#define WDGM_STATECOMBINER_CHECKLMT         (0xFFFFU)

#define WDGM_STATECOMBINER_WDGIFENMODE      ((uint8)((uint8)0x01U << (uint8)WDGIF_SLOW_MODE) | \
                                             (uint8)((uint8)0x01U << (uint8)WDGIF_FAST_MODE))
#define WDGM_STATECOMBINER_WDGIFALLMODE     ((uint8)((uint8)0x01U << (uint8)WDGIF_SLOW_MODE) | \
                                             (uint8)((uint8)0x01U << (uint8)WDGIF_FAST_MODE) | \
                                             (uint8)((uint8)0x01U << (uint8)WDGIF_OFF_MODE))
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* NEUSAR define. */
typedef uint32 WdgM_TimeBaseTickType;

typedef uint32 WdgM_MainFuncPeriodType; /* LSB:ms */

typedef uint16 WdgM_SupervisedCycCntType;

typedef boolean WdgM_BooleanUpdateBitType;

typedef boolean WdgM_BooleanFirstExpFlagType;

/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef uint16 WdgM_AliveCntType;

typedef uint16 WdgM_AliveSupervisionNumType;

typedef uint32 WdgM_SENumType;

typedef uint16 WdgM_DeadLineSupervisionNumType;

typedef uint16 WdgM_LogicalSupervisionNumType;

typedef uint16 WdgM_ExternalTransitionNumType;

typedef uint16 WdgM_ExternalCPInitialNumType;

typedef uint16 WdgM_ExternalCPFinalNumType;

/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef uint16 WdgM_InternalTransitionNumType;

typedef uint16 WdgM_LocalStatusParamsNumType;

typedef uint8 WdgM_TriggerNumType;

typedef uint16 WdgM_ExternalLogicalSupervisionNumType;

typedef uint8 WdgM_SupervisedEntityEnableType;

typedef uint8 WdgM_FailedAliveSupvRefCycTolType;

typedef uint8 WdgM_InitFlagType;

typedef uint8 WdgM_AliveSpvStatusType;

typedef uint8 WdgM_DeadLineSpvStatusType;

typedef uint8 WdgM_LogicalSpvStatusType;

typedef uint16 WdgM_ExpiredSupervisionCycCntType;

typedef uint16 WdgM_TriggerConditionValueType;

typedef uint8 WdgM_TriggerWatchdogRefType;

/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef uint16 WdgM_CallerIdType;

typedef uint16 WdgM_CheckpointNumType;

typedef uint32 WdgM_CoreIdType;

typedef uint16 WdgM_CountType;

typedef uint16 WdgM_CoreNumType;

typedef uint16 WdgM_StateCombinerCntType;

typedef uint8 WdgM_StateCombinerTriggerAssignType;

typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.8" */
{
    uint8 ConfigTypeRef;
} WdgM_ConfigType;  /* NEUSAR not used. */

typedef struct
{
    WdgM_SupervisedEntityIdType LogicalSEId;
    WdgM_CheckpointIdType LogicalCPId;
} WdgM_CheckpointRefType;

typedef struct
{
    WdgM_CheckpointRefType CheckpointIdRef; /* Ref to Cfg: WdgMAliveSupervisionCheckpointRef. */
    WdgM_SupervisedCycCntType ExpectedAliveIndications; /* Ref to Cfg: WdgMExpectedAliveIndications. */
    WdgM_SupervisedCycCntType MinMargin;    /* Ref to Cfg: WdgMMinMargin. */
    WdgM_SupervisedCycCntType MaxMargin;    /* Ref to Cfg: WdgMMaxMargin. */
    WdgM_SupervisedCycCntType SupervisionRefCyc;    /* Ref to Cfg: WdgMSupervisionReferenceCycle. */
    WdgM_FailedAliveSupvRefCycTolType FailedAliveSupvRefCycTol; /* Ref to Cfg: WdgMFailedAliveSupervisionRefCycleTol. */
} WdgM_AliveSupervisionType;

typedef struct
{
    WdgM_CheckpointRefType DeadlineStartRef;    /* Ref to Cfg: WdgMDeadlineStartRef. */
    WdgM_CheckpointRefType DeadlineStopRef; /* Ref to Cfg: WdgMDeadlineStopRef. */
    WdgM_TimeBaseTickType DeadlineMin;  /* Ref to Cfg: WdgMDeadlineMin. */
    WdgM_TimeBaseTickType DeadlineMax;  /* Ref to Cfg: WdgMDeadlineMax. */
} WdgM_DeadLineSupervisionType;

typedef struct
{
    WdgM_CheckpointRefType ExternalTransitionDestRef;   /* Ref to Cfg: WdgMExternalTransitionDestRef. */
    WdgM_CheckpointRefType ExternalTransitionSourceRef; /* Ref to Cfg: WdgMExternalTransitionSourceRef. */
} WdgM_ExternalTransitionType;

typedef struct
{
    WdgM_CheckpointRefType ExCurrentCheckpointRef;        /* for Logical Supervision */ /* [SWS_WdgM_00295]. */
    WdgM_CheckpointRefType ExPreviousCheckpointRef;       /* for Logical Supervision */ /* [SWS_WdgM_00246]. */
    boolean ExLogicalActiveFlag;
} WdgM_ExLogicalVariableType;

typedef struct
{
    WdgM_ExternalCPFinalNumType ExternalCPFinalNum;
    WdgM_ExternalCPInitialNumType ExternalCPInitialNum;
    WdgM_CheckpointRefType* ExternalCheckpointFinalRef; /* Ref to Cfg: WdgMExternalCheckpointFinalRef. */
    WdgM_CheckpointRefType* ExternalCheckpointInitialRef;   /* Ref to Cfg: WdgMExternalCheckpointInitialRef. */
    WdgM_ExternalTransitionNumType ExternalTransitionNum;
    WdgM_ExternalTransitionType* ExternalTransitionCfg;  /* Ref to Cfg: WdgMExternalTransition. */
    WdgM_ExLogicalVariableType* ExLogicalVariable;
} WdgM_ExLogicalSupervisionType;

typedef struct
{
    WdgM_CoreIdType TriggerCoreRefID;
    WdgM_TriggerConditionValueType TriggerConditionValue;   /* Ref to Cfg: WdgMTriggerConditionValue. */
    WdgIf_ModeType WatchdogMode;    /* Ref to Cfg: WdgMWatchdogMode. */
    WdgM_TriggerWatchdogRefType DeviceIndex;    /* Ref to Cfg:WdgMTriggerWatchdogRef. */
    WdgM_StateCombinerCntType StateCombinerCheckWnd;    /* Ref to Cfg:WdgMStateCombinerCheckWindow. */
    WdgM_StateCombinerCntType StateCombinerMaxDelta;    /* Ref to Cfg:WdgMStateCombinerMaxDelta. */
    WdgM_StateCombinerCntType StateCombinerMinDelta;    /* Ref to Cfg:WdgMStateCombinerMinDelta. */
    Std_ReturnType (*WdgM_StateCombineNotification)(WdgM_TriggerWatchdogRefType DeviceIndex, WdgM_TriggerConditionValueType* Timeout, uint16 StateCombinerErr); /* State combine notification callout. */
} WdgM_TriggerType;

typedef struct
{
    WdgM_ExpiredSupervisionCycCntType ExpiredSupervisionCycCnt; /* Ref to Cfg: WdgMExpiredSupervisionCycleTol. */
    WdgM_ModeType ModeId;   /* Ref to Cfg: WdgMModeId. */
    WdgM_MainFuncPeriodType MainFuncPeriod; /* Ref to Cfg: WdgMSupervisionCycle. */
    WdgM_AliveSupervisionNumType  AliveSupervisionNum;
    WdgM_AliveSupervisionType* AliveSupervisionCfg; /* Ref to Cfg: WdgMAliveSupervision. */
    WdgM_DeadLineSupervisionNumType DeadLineSupervisionNum;
    WdgM_DeadLineSupervisionType* DeadLineSupervisionCfg;   /* Ref to Cfg: WdgMDeadlineSupervision. */
    WdgM_ExternalLogicalSupervisionNumType ExternalLogicalSupervisionNum;
    WdgM_ExLogicalSupervisionType* ExternalLogicalSupervisionCfg; /* Ref to Cfg: WdgExternalLogicalSupervision. */
    WdgM_LocalStatusParamsNumType LocalStatusSupervisedEntityNum;
    WdgM_SupervisedEntityIdType* LocalStatusSupervisedEntityCfg; /* Ref to Cfg: WdgExternalLogicalSupervision. */
    WdgM_TriggerNumType TriggerNum;
    WdgM_TriggerType* Trigger;  /* Ref to Cfg:WdgMTrigger. */
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    void (*WdgM_GlobalStatusChangeNotification)(WdgM_GlobalStatusType Status); /* Global status change notification callout. */
    WdgM_StateCombinerCntType StateCombinerStartUpSync;  /* Ref to Cfg:WdgMStateCombinerStartUpSync. */
    WdgM_TriggerNumType StateCombinerMasterTriggerID;  /* Ref to Cfg:WdgMStateCombinerMasterTrigger. */
    WdgM_StateCombinerTriggerAssignType* StateCombinerTriggerAssign;  /* Ref to Cfg:WdgMStateCombinerMasterTrigger and WdgMStateCombinerSlaveTriggers. */
} WdgM_ModeStructType;

typedef struct
{
    WdgM_LocalStatusType  LocalStatus;
    WdgM_SupervisedEntityEnableType SupervisedEntityEnable;

    WdgM_AliveSpvStatusType AliveSpvStatus;
    WdgM_DeadLineSpvStatusType DeadLineSpvStatus;
    WdgM_LogicalSpvStatusType LogicalSpvStatus;

    WdgM_SupervisedCycCntType AliveIndicationCnt;             /* for Alive Supervision. */
    WdgM_SupervisedCycCntType AliveSupervisionCycCnt;         /* for Alive Supervision. */
    WdgM_SupervisedCycCntType AliveFailedCnt;                 /* for Alive Supervision. */

    WdgM_BooleanUpdateBitType LogicalActiveFlag;          /* [SWS_WdgM_00271] */
    WdgM_CheckpointIdType CurrentCheckpointId;        /* for Logical Supervision. */ /* [SWS_WdgM_00295] */
    WdgM_CheckpointIdType PreviousCheckpointId;       /* for Logical Supervision. */ /* [SWS_WdgM_00246] */

    WdgM_TimeBaseTickType ElapsedTick;                /* for DeadLine Supervision. */
    WdgM_TimeBaseTickType PreviousTick;               /* for DeadLine Supervision. */

    WdgM_AliveSupervisionNumType  AliveSupervisionNum;
    WdgM_DeadLineSupervisionNumType DeadLineSupervisionNum;
    WdgM_AliveSupervisionType*  AliveSupervisionCfg;
    WdgM_DeadLineSupervisionType* DeadLineSupervisionCfg;
} WdgM_SEVariableType;

typedef struct
{
    WdgM_CheckpointIdType transitionSource; /* Ref to Cfg: WdgMInternalTransitionSourceRef. */
    WdgM_CheckpointIdType transitionIdDest; /* Ref to Cfg: WdgMInternalTransitionDestRef. */
} WdgM_InternalTransitionType;

typedef struct
{
    WdgM_SupervisedEntityIdType SupervisedEntityId; /* Ref to Cfg:WdgMSupervisedEntityId. */
    CounterType OsCounterID;  /* Ref to Cfg: WdgMOSCounter. */
    WdgM_BooleanUpdateBitType OsApplicationRestartEnable; /* WdgMOsApplicationRef. */
    ApplicationType EcucPartitionRef;   /* Ref to Cfg:WdgMEcucPartitionRef. */
    WdgM_CheckpointIdType CheckpointIdNum;  /* Ref to Cfg:WdgMCheckpoint. */
    WdgM_CheckpointIdType InternalCheckpointInitial;    /* Ref to Cfg: WdgMInternalCheckpointInitialRef. */
    WdgM_CheckpointNumType InternalCheckpointFinalNum;  /* Ref to Cfg: WdgMInternallCheckpointFinalRef. */
    WdgM_CheckpointIdType* InternalCheckpointFinalArray;
    WdgM_LogicalSupervisionNumType LogicalSupervisionNum;
    WdgM_InternalTransitionType* LogicalSupervisionCfg; /* Ref to Cfg: WdgMInternalTransition. */

    WdgM_SEVariableType*   SEVariable;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    void (*WdgM_LocalStatusChangeNotification)(WdgM_LocalStatusType Status);  /* Local status change notification callout. */
} WdgM_SEGType;


typedef struct
{
    WdgM_InitFlagType InitFlag;
    WdgM_GlobalStatusType GlobalStatus;
    WdgM_BooleanFirstExpFlagType FirstExpFlag;
    WdgM_SupervisedEntityIdType FirstExpSEId;
    WdgM_SupervisedEntityIdType InverseFirstExpSEId;
    WdgM_ExpiredSupervisionCycCntType ExpiredSupervisionCycCnt;
    WdgM_ExpiredSupervisionCycCntType ExpiredSupervisionCycCntCfg; /* Ref to Cfg: WdgMExpiredSupervisionCycleTol. */
    const WdgM_ModeStructType* CurrentModePtr;
    const WdgM_ModeStructType* SetModePtr;
    WdgM_BooleanUpdateBitType setModeFlag;
    WdgM_BooleanUpdateBitType PerformResetFlag;
} WdgM_SEGlobalInfoType;

typedef struct
{
    WdgM_CountType WdgM_LocalStatusOKCnt;
    WdgM_CountType WdgM_LocalStatusDeactivatedCnt;
    WdgM_CountType WdgM_localStatusFailedCnt;
    WdgM_CountType WdgM_LocalStatusExpiredCnt;
} WdgM_LocalStatusCnt;


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

#endif /* WDGM_TYPES_H_ */

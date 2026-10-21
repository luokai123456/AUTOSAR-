/*
********************************************************************************
*
* File name: EcuM.h
*
* Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 2.0
* Author/Date: yong.zhang/2019.11.26
* Change: New created
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: yong.zhang/2020.06.08
* Change: Add release software number
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: fangtao/2020.09.15
* Change: Modify the function name according to the AUTOSAR specification, add
*         MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: guoziyang/2020.11.18
* Change: Modify compilation warning
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: GuoZY/2021.4.12
* Change: Update version number to 3.2.0.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: GuoZY/2021.6.30
* Change: Add macro ECUM_WKSTATUS_ENABLED.
* Cause: Add
********************************************************************************
* Version: 3.6
* Author/Date: GuoZY/2021.6.30
* Change: Modify code according to Autosar specification.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: GuoZY/2021.8.16
* Change: Modify code according to Autosar specification.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: GuoZY/2021.10.20
* Change: Update version number to 3.3.0.
* Cause: Update
********************************************************************************
*  Version: 3.9
*  Author/Date: GuoZY/2021.11.01
*  Change: Update software version to 3.3.1.
*  Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: GuoZY/2021.12.10
* Change: Add Mcu.h.
* Cause: Optimization
********************************************************************************
*  Version: 3.11
*  Author/Date: GuoZY/2021.12.23
*  Change: Update software version to 3.3.2.
*  Cause: Update
********************************************************************************
*  Version: 3.12
*  Author/Date: GuoZY/2022.05.05
*  Change: Add macro definition ECUM_INVALID.
*  Cause: Update
********************************************************************************
*  Version: 3.13
*  Author/Date: HeHao/2022.06.16
*  Change: Update software version to 3.3.3.
*  Cause: Update
********************************************************************************
*  Version: 3.14
*  Author/Date: HeHao/2022.06.20
*  Change: 1. Merge from Branch_21Q2.
*          2. Update software version to 3.3.4.
*  Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: WangXG/2022.09.22
* Change: 1. Append ECUM supports processing that supports multi-core synchronization.
*         2. Update software version to 3.3.5.
* Cause: Optimization
********************************************************************************
* Version: 3.16
* Author/Date: WangXG/2022.09.29
* Change: Remove the macro definition.
* Cause: Optimization
********************************************************************************
* Version: 3.17
* Author/Date: WangXG/2022.11.04
* Change: elete poll sequence.
* Cause: bugfix
********************************************************************************
* Version: 3.18
* Author/Date: WangXG/2022.12.26
* Change: 1.Append precompiled macro.
*         2.Update software version to 3.3.6.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: WangXG/2022.12.29
* Change: 1.Append precompiled macro.
*         2.Update software version to 3.3.7.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: ChengL/2023.05.17
* Change: Update software version to 3.7.0.
* Cause: Optimization
********************************************************************************
* Version: 3.24
* Author/Date: WangXG/2023.05.26
* Change: Update software version to 3.7.0.0.
* Cause: Optimization
********************************************************************************
* Version: 3.25
* Author/Date: HeHao/2023.06.22
* Change: Fix types/macros that do not compliance with code style regulations.
*         Update software version to 3.8.0.1.
* Cause: Optimization
********************************************************************************
* Version: 3.26
* Author/Date: HeHao/2023.07.10
* Change: Fix types/macros that do not compliance with code style regulations.
*         Update software version to 3.8.0.2.
* Cause: Optimization
********************************************************************************
* Version: 3.27
* Author/Date: HeHao/2023.08.01
* Change: Clear compiler warning for redefinition.
*         Update software version to 3.8.0.3.
* Cause: Optimization
********************************************************************************
* Version: 3.28
* Author/Date: HeHao/2023.09.05
* Change: Minor changes on coding style.
*         Update software version to 3.8.0.4.
* Cause: Optimization
********************************************************************************
* Version: 3.29
* Author/Date: HeHao/2023.09.27
* Change: Update software version to 3.9.0.1.
* Cause: Optimization
********************************************************************************
* Version: 3.30
* Author/Date: HeHao/2023.10.25
* Change: Update software version to 3.9.0.2.
* Cause: Optimization
********************************************************************************
* Version: 3.31
* Author/Date: HeHao/2023.12.25
* Change: Update software version to 3.9.0.3.
* Cause: Update
********************************************************************************
* Version: 3.32
* Author/Date: HeHao/2024.01.15
* Change: Update software version to 3.10.0.1.
* Cause: Update
********************************************************************************
* Version: 3.33
* Author/Date: HeHao/2024.02.20
* Change: 1. Update software version to 3.10.0.2.
*         2. Correct misspellings in comments.
* Cause: Update
********************************************************************************
* Version: 3.34
* Author/Date: HeHao/2024.03.11
* Change: 1. Update software version to 3.10.0.3.
* Cause: Update
********************************************************************************
* Version: 3.35
* Author/Date: HeHao/2024.04.02
* Change: 1. Modify comments.
*         2. Update software version to 3.10.0.4.
* Cause: Update
********************************************************************************
* Version: 3.36
* Author/Date: TianL/2024.5.15
* Change: 1. Add a MemMap paragraph definition to the function declaration.
*         2. Modify the MemMap Memory Section of uninitialized variables.
*         3. Modify coding specifications.
*         4. Update software version to 3.11.0.5.
* Cause: Update
********************************************************************************
* Version: 3.37
* Author/Date: TianL/2024.8.5
* Change: 1. Modify copyright.
*         2. Update software version to 3.11.0.6.
* Cause: Update
********************************************************************************
* Version: 3.38
* Author/Date: TianL/2024.8.30
* Change: Update software version to 3.11.0.7.
* Cause: Update
********************************************************************************
* Version: 3.39
* Author/Date: TianL/2024.9.19
* Change: 1.Modify the MemMap of the global variable.
*         2.Update software version to 3.11.0.8.
* Cause: Update
********************************************************************************
* Version: 3.40
* Author/Date: TianL/2024.9.30
* Change: 1.Modify the MemMap of the global variable.
*         2.Update software version to 3.11.0.9.
* Cause: Update
********************************************************************************
* Version: 3.41
* Author/Date: TianL/2024.10.11
* Change: 1.Modify the MemMap of the global variable.
*         2.Update software version to 3.11.0.10.
* Cause: Update
********************************************************************************
* Version: 3.42
* Author/Date: TianL/2025.3.7
* Change: Update software version to 3.13.0.11.
* Cause: Update
********************************************************************************
* Version: 3.43
* Author/Date: TianL/2025.3.27
* Change: Update software version to 3.13.0.12.
* Cause: Update
********************************************************************************
* Version: 3.44
* Author/Date: TianL/2025.6.16
* Change: 1.Add the polyspace deviation suppression comment.
*         2.Update software version to 3.14.0.13.
* Cause: Update
********************************************************************************
* Version: 3.45
* Author/Date: TianL/2025.6.23
* Change: Update software version to 3.14.0.14.
* Cause: Update
********************************************************************************
* Version: 3.46
* Author/Date: TianL/2025.6.24
* Change: Remove redundant macro definitions.
* Cause: Update
********************************************************************************
* Version: 3.47
* Author/Date: TianL/2025.7.17
* Change: Update software version to 3.15.0.15.
* Cause: Update
********************************************************************************
*/
#ifndef ECUM_H_
#define ECUM_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "EcuM_Cfg.h"
#include "Std_Types.h"


#if( ECUM_NORMAL_MCU_MODEREF != ECUM_FF )
#include "Mcu.h"
#endif  /* ECUM_NORMAL_MCU_MODEREF != ECUM_FF */

#if( ECUM_DEV_ERROR_REPORT == STD_ON )
#include "Det.h"
#endif  /* ECUM_DEV_ERROR_REPORT == STD_ON */

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* Vender ID and Module ID. */
#define ECUM_VENDOR_ID                              (119U)
#define ECUM_MODULE_ID                              (10U)
#define ECUM_INSTANCE_ID                            (0U)

/* Component version information. */
#define ECUM_SW_MAJOR_VERSION                       (3U)
#define ECUM_SW_MINOR_VERSION                       (15U)
#define ECUM_SW_PATCH_VERSION                       (0U)
#define ECUM_SW_REVISION_VERSION                    (15U)

#define ECUM_AR_RELEASE_MAJOR_VERSION               (4U)
#define ECUM_AR_RELEASE_MINOR_VERSION               (2U)
#define ECUM_AR_RELEASE_REVISION_VERSION            (2U)

/* EcuM module state. */
#define ECUM_MOUDLE_STATE_UINIT                     (0U)
#define ECUM_MODULE_STATE_INIT                      (1U)

/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
#define ECUM_DUMMY_STATEMENT(v)                     ((v) = (v))
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define EcuM_Det_ReportError(SID, ERROR) ((void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, (SID), (ERROR)))
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define EcuM_EnterCriticalArea() SuspendAllInterrupts()     /* Suspend interrupts. */
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define EcuM_LeaveCriticalArea() ResumeAllInterrupts()      /* Resume interrupts. */

/* [SWS_EcuM_04032]:Development Error ID. */
#define ECUM_E_NO_ERROR                             (0U)
#define ECUM_E_UNINIT                               (1U)   /* A service was called prior to initialization. */
#define ECUM_E_SERVICE_DISABLED                     (2U)   /* A function was called which was disabled by configuration. */
#define ECUM_E_NULL_POINTER                         (3U)   /* A invalid pointer was passed as an argument. */
#define ECUM_E_INVALID_PAR                          (4U)   /* A parameter was invalid (unspecific). */
#define ECUM_E_STATE_PAR_OUT_OF_RANGE               (5U)   /* A state, passed as an argument to a service, was out of range. */
#define ECUM_E_UNKNOWN_WAKEUP_SOURCE                (6U)   /* An unknown wakeup source was passed as a parameter to an API. */
#define ECUM_E_INIT_FAILED                          (7U)   /* The initialization failed. */
/* [SWS_EcuM_04032]:Runtime Errors. */
#define ECUM_E_RAM_CHECK_FAILED                     (8U)   /* The RAM check during wakeup failed. */
#define ECUM_E_CONFIGURATION_DATA_INCONSISTENT      (9U)   /* Postbuild configuration data is inconsistent. */

/* EcuM Function Service ID. */
#define ECUM_SID_GET_VERSION_INFO                                    (0x00U)
#define ECUM_SID_INIT                                                (0x01U)
#define ECUM_SID_SHUTDOWN                                            (0x02U)
#define ECUM_SID_REQUEST_RUN                                         (0x03U)
#define ECUM_SID_RELEASE_RUN                                         (0x04U)
#define ECUM_SID_KILL_ALL_RUN_REQUESTS                               (0x05U)
#define ECUM_SID_SELECT_SHUTDOWN_TARGET                              (0x06U)
#define ECUM_SID_GET_STATE                                           (0x07U)
#define ECUM_SID_GET_LAST_SHUTDOWN_TARGET                            (0x08U)
#define ECUM_SID_GET_SHUTDOWN_TARGET                                 (0x09U)
#define ECUM_SID_REQUEST_POST_RUN                                    (0x0aU)
#define ECUM_SID_RELEASE_POST_RUN                                    (0x0bU)
#define ECUM_SID_SET_WAKEUP_EVENT                                    (0x0CU)
#define ECUM_SID_GET_PENDING_WAKEUP_EVENTS                           (0x0DU)
#define ECUM_SID_SELECT_BOOT_TARGET                                  (0x12U)
#define ECUM_SID_GET_BOOT_TARGET                                     (0x13U)
#define ECUM_SID_VALIDATE_WAKEUP_EVENT                               (0x14U)
#define ECUM_SID_GET_VALIDATED_WAKEUP_EVENTS                         (0x15U)
#define ECUM_SID_CLEAR_WAKEUP_EVENT                                  (0x16U)
#define ECUM_SID_MAIN_FUNCTION                                       (0x18U)
#define ECUM_SID_GET_EXPIRED_WAKEUP_EVENTS                           (0x19U)
#define ECUM_SID_STARTUP_TWO                                         (0x1AU)
#define ECUM_SID_SELECT_SHUTDOWN_CAUSE                               (0x1BU)
#define ECUM_SID_GET_SHUTDOWN_CAUSE                                  (0x1CU)
#define ECUM_SID_GET_MOST_RECENT_SHUTDOWN                            (0x1DU)
#define ECUM_SID_GET_NEXT_RECENT_SHUTDOWN                            (0x1EU)
#define ECUM_SID_GO_DOWN                                             (0x1FU)
#define ECUM_SID_GO_HALT                                             (0x20U)
#define ECUM_SID_GO_POLL                                             (0x21U)
#define ECUM_SID_SET_REL_WAKEUP_ALARM                                (0x22U)
#define ECUM_SID_SET_ABS_WAKEUP_ALARM                                (0x23U)
#define ECUM_SID_ABORT_WAKEUP_ALARM                                  (0x24U)
#define ECUM_SID_GET_CURRENT_TIME                                    (0x25U)
#define ECUM_SID_GET_WAKEUP_TIME                                     (0x26U)
#define ECUM_SID_SET_CLOCK                                           (0x27U)
#define ECUM_SID_START_CHECK_WAKEUP                                  (0x28U)
#define ECUM_SID_END_CHECK_WAKEUP                                    (0x29U)
#define ECUM_SID_SET_STATE                                           (0x2BU)

/* Range of EcuM_WakeupStatusType. */
#define ECUM_WKSTATUS_NONE                                           (0u)
#define ECUM_WKSTATUS_PENDING                                        (1u)
#define ECUM_WKSTATUS_VALIDATED                                      (2u)
#define ECUM_WKSTATUS_EXPIRED                                        (3u)
#define ECUM_WKSTATUS_ENABLED                                        (6u)

/* Multi core used. */
#define ECUM_ALLCORE_GODOWN                                          (1U)
#define ECUM_ALLCORE_GOHALT                                          (2U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define ECUM_NOTIFY_SLAVE_SHUTDOWN()                                 (EcuM_AllCoreSyncSignal = ECUM_ALLCORE_GODOWN)
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define ECUM_NOTIFY_SLAVE_GOHALT()                                   (EcuM_AllCoreSyncSignal = ECUM_ALLCORE_GOHALT)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef enum
{
    ECUM_ALLCORESHUTDOWN_EVENT = 0,
    ECUM_ALLCORESLEEP_EVENT,
    ECUM_ALLCORE_SYNC_MAX
} EcuM_EventType;

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define ECUM_START_SEC_GLOBAL_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"

extern VAR(EcuM_WakeupSourceType, ECUM_VAR_NO_INIT) EcuM_PendingCheckWakeups;
extern VAR(EcuM_WakeupSourceType, ECUM_VAR_NO_INIT) EcuM_ClearedPendingWakeups;
/* Internal pending, validated and expired bit variables. */
extern VAR(EcuM_WakeupSourceType, ECUM_VAR_NO_INIT) EcuM_ValidatedWakeups;
extern VAR(EcuM_WakeupSourceType, ECUM_VAR_NO_INIT) EcuM_ExpiredWakeups;
extern VAR(EcuM_WakeupSourceType, ECUM_VAR_NO_INIT) EcuM_PendingWakeups;
#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
extern VAR(uint8, ECUM_VAR_NO_INIT) EcuM_AllCoreSyncSignal;
extern VAR(uint16, ECUM_VAR_NO_INIT) EcuM_AllCoreSyncGodownCaller;
extern VAR(uint8, ECUM_VAR_NO_INIT) EcuM_SyncEventTbl[ECUM_ALLCORE_SYNC_MAX];
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */

#define ECUM_STOP_SEC_GLOBAL_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define ECUM_START_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"

extern CONST(EcuM_ConfigType, ECUM_CONFIG_DATA) EcuM_Config;

#define ECUM_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"

/*
********************************************************************************
*    Global Functions
********************************************************************************
*/
#define ECUM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"

extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoDown(uint16 caller);
#if( (ECUM_SLEEP_MODE_COUNT > ECUM_ZERO) && (ECUM_NORMAL_MCU_MODEREF != ECUM_FF) )
extern FUNC(void, ECUM_CODE) EcuM_GoSleepSequence(uint8 SleepType);
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoHalt(void);
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoPoll(void);
#endif  /* (ECUM_SLEEP_MODE_COUNT > ECUM_ZERO) && (ECUM_NORMAL_MCU_MODEREF != ECUM_FF) */
extern FUNC(void, ECUM_CODE) EcuM_Init(void);
extern FUNC(void, ECUM_CODE) EcuM_StartupTwo(void);
extern FUNC(void, ECUM_CODE) EcuM_Shutdown(void);
extern FUNC(void, ECUM_CODE) EcuM_SetWakeupEvent(EcuM_WakeupSourceType sources);
extern FUNC(void, ECUM_CODE) EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType sources);
#if( ECUM_NUMBER_OF_CORES > ECUM_ONE )
extern FUNC(uint8, ECUM_CODE) EcuM_GetEvent(EcuM_EventType EventID, CoreIdType CoreId_Pra);
extern FUNC(uint8, ECUM_CODE) EcuM_WaitEvent(EcuM_EventType EventID);
extern FUNC(void, ECUM_CODE) EcuM_SetEvent(EcuM_EventType EventID, CoreIdType CoreId_Pra);
extern FUNC(void, ECUM_CODE) EcuM_ClearEvent(EcuM_EventType EventID);
#endif  /* ECUM_NUMBER_OF_CORES > ECUM_ONE */
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
extern FUNC(EcuM_ResourceType, ECUM_CODE) EcuM_GetResourceInCore(EcuM_CoreIDType CoreID);
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownTarget
(
    EcuM_ShutdownTargetType shutdownTarget,
    EcuM_ShutdownModeType shutdownMode
);
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetShutdownTarget
(
    P2VAR(EcuM_ShutdownTargetType, AUTOMATIC, ECUM_APPL_DATA) shutdownTarget,
    P2VAR(EcuM_ShutdownModeType, AUTOMATIC, ECUM_APPL_DATA) shutdownMode
);
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetLastShutdownTarget
(
    P2VAR(EcuM_ShutdownTargetType, AUTOMATIC, ECUM_APPL_DATA) shutdownTarget,
    P2VAR(EcuM_ShutdownModeType, AUTOMATIC, ECUM_APPL_DATA) shutdownMode
);
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownCause
(
    EcuM_ShutdownCauseType target
);
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetShutdownCause
(
    P2VAR(EcuM_ShutdownCauseType, AUTOMATIC, ECUM_APPL_DATA) shutdownCause
);
extern FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetPendingWakeupEvents(void);
extern FUNC(void, ECUM_CODE) EcuM_ClearWakeupEvent(EcuM_WakeupSourceType sources);
extern FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetValidatedWakeupEvents(void);
#if( ECUM_VALIDATION_TIMEOUT == STD_ON )
extern FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetExpiredWakeupEvents(void);
#endif  /* ECUM_VALIDATION_TIMEOUT == STD_ON */
#if( ECUM_VERSIONINFO_API == STD_ON )
extern FUNC(void, ECUM_CODE) EcuM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, ECUM_APPL_DATA) versioninfo
);
#endif  /* ECUM_VERSIONINFO_API == STD_ON */
extern FUNC(void, ECUM_CODE) EcuM_MainFunction(void);

#define ECUM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"

#endif  /* ECUM_H_ */


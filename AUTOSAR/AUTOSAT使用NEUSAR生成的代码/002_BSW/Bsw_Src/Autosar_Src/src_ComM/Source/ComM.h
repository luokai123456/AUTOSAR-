/*
********************************************************************************
*
* File name: ComM.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: TanLixiang/2018.07.14
* Change: New
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: Jia_feng/2020.06.08
* Change: Add autosar release version.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: FangT/2020.10.28
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: JiaF/2021.4.10
* Change: 1. Add macro judgment of COMM_MODELIMITATION and COMM_PNCSUPPORT.
*         2. Delete some unused error ids.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: JiaF/2021.4.12
* Change: Update software version to 3.2.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: JiaF/2021.9.1
* Change: Modify the code specification.
* Cause: Modify
********************************************************************************
* Version: 3.5
* Author/Date: JiaF/2021.10.20
* Change: Update software version to 3.3.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: JiaF/2021.11.01
* Change: Update software version to 3.3.1.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: HeHao/2022.06.16
* Change: Update software version to 3.3.2.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: HeHao/2022.06.20
* Change: Update software version to 3.3.3.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: CuiYS/2023.05.26
* Change: Add REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: HeHao/2023.07.13
* Change: 1. Add a dummy API(ComM_BusSM_BusSleepMode) for compatibility.
*         2. Update software version to 3.8.0.1.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: HeHao/2023.08.01
* Change: 1. Add service ID for ComM_BusSM_BusSleepMode.
*         2. Update software version to 3.8.0.2.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: HeHao/2023.08.07
* Change: 1. Change service ID for ComM_BusSM_BusSleepMode from 0x34 to 0x70.
*         2. Update software version to 3.8.0.3.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: HeHao/2023.10.30
* Change: 1. Update software version to 3.9.0.1.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: HeHao/2024.01.15
* Change: 1. Update software version to 3.10.0.1.
*         2. Comments and code style optimization.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: HeHao/2024.02.20
* Change: 1. Update software version to 3.10.0.2.
*         2. Delete a redundant function declaration(ComM_Nm_RestartIndication).
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: HeHao/2024.03.11
* Change: 1. Update software version to 3.10.0.3.
*         2. Change P2CONST's ptrclass from XXX_APPL_CONST to XXX_APPL_DATA.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: HeHao/2024.04.02
* Change: 1. Update software version to 3.10.0.4.
*         2. Change P2CONST's ptrclass.
*         3. Modify comments.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date: TianL/2024.05.15
* Change: 1. Add a MemMap paragraph definition to the function declaration.
*         2. Modify the MemMap Memory Section of uninitialized variables.
*         3. Modify coding specifications.
*         4. Update software version to 3.11.0.5.
* Cause: Update
********************************************************************************
* Version: 3.19
* Author/Date: TianL/2024.8.5
* Change: 1. Modify copyright.
*         2. Update software version to 3.11.0.6.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date: TianL/2024.8.30
* Change: Update software version to 3.11.0.7.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: TianL/2024.9.19
* Change: 1.Modify the macro switch declared by the ComM_PncProcessRxSignalEra 
*         function.
*         2.Update software version to 3.11.0.8.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: TianL/2024.12.4
* Change: Update software version to 3.12.0.9.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: TianL/2024.12.16
* Change: Update software version to 3.12.0.10.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: TianL/2025.1.21
* Change: Update software version to 3.13.0.11.
* Cause: Update
********************************************************************************
* Version: 3.24
* Author/Date: TianL/2025.2.21
* Change: Update software version to 3.13.0.12.
* Cause: Update
********************************************************************************
* Version: 3.25
* Author/Date: TianL/2025.3.27
* Change: 1.Remove redundant function declarations.
*         2.Update software version to 3.13.0.13.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date: TianL/2025.6.16
* Change: 1.Add the polyspace deviation suppression comment.
*         2.Update software version to 3.14.0.14.
* Cause: Update
********************************************************************************
* Version: 3.27
* Author/Date: TianL/2025.6.23
* Change: Update software version to 3.14.0.15.
* Cause: Update
********************************************************************************
* Version: 3.28
* Author/Date: TianL/2025.7.15
* Change: Update software version to 3.15.0.16.
* Cause: Update
********************************************************************************
*/
#ifndef COMM_H_
#define COMM_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "ComStack_Types.h"
#include "ComM_Nm.h"
#include "ComM_Cfg.h"
#include "ComM_Types.h"
#include "ComM_Lcfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Module identification. */
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define COMM_VENDOR_ID                              (119U)
#define COMM_MODULE_ID                              (12U)
#define COMM_SW_MAJOR_VERSION                       (3U)
#define COMM_SW_MINOR_VERSION                       (15U)
#define COMM_SW_PATCH_VERSION                       (0U)
#define COMM_SW_REVISION_VERSION                    (16U)

#define COMM_AR_RELEASE_MAJOR_VERSION               (4U)
#define COMM_AR_RELEASE_MINOR_VERSION               (2U)
#define COMM_AR_RELEASE_REVISION_VERSION            (2U)

#define COMM_INSTANCE_ID_DET                        (0U)

/* API service IDs.*/
#define COMM_SID_INIT                               (0x01U)  /*!< Service ID: ComM_Init() */
#define COMM_SID_DEINIT                             (0x02U)  /*!< Service ID: ComM_DeInit() */
#define COMM_SID_GETSTATUS                          (0x03U)  /*!< Service ID: ComM_GetStatus() */
#define COMM_SID_GETSTATE                           (0x34U)  /*!< Service ID: ComM_GetState() */
#define COMM_SID_GETINHIBITIONSTATUS                (0x04U)  /*!< Service ID: ComM_GetInhibitionStatus() */
#define COMM_SID_REQUESTCOMMODE                     (0x05U)  /*!< Service ID: ComM_RequestComMode() */
#define COMM_SID_GETMAXCOMMODE                      (0x06U)  /*!< Service ID: ComM_GetMaxComMode() */
#define COMM_SID_GETREQUESTEDCOMMODE                (0x07U)  /*!< Service ID: ComM_GetRequestedComMode() */
#define COMM_SID_GETCURRENTCOMMODE                  (0x08U)  /*!< Service ID: ComM_GetCurrentComMode() */
#define COMM_SID_PREVENTWAKEUP                      (0x09U)  /*!< Service ID: ComM_PreventWakeUp() */
#define COMM_SID_LIMITCHANNELTONOCOMMODE            (0x0BU)  /*!< Service ID: ComM_LimitChannelToNoComMode() */
#define COMM_SID_LIMITECUTONOCOMMODE                (0x0CU)  /*!< Service ID: ComM_LimitECUToNoComMode() */
#define COMM_SID_READINHIBITCOUNTER                 (0x0DU)  /*!< Service ID: ComM_ReadInhibitCounter() */
#define COMM_SID_RESETINHIBITCOUNTER                (0x0EU)  /*!< Service ID: ComM_ResetInhibitCounter() */
#define COMM_SID_SETECUGROUPCLASSIFICATION          (0x0FU)  /*!< Service ID: ComM_SetECUGroupClassification() */
#define COMM_SID_GETVERSIONINFO                     (0x10U)  /*!< Service ID: ComM_GetVersionInfo() */
#define COMM_SID_MAINFUNCTION                       (0x60U)  /*!< Service ID: ComM_MainFunction() */
#define COMM_SID_COMMUNICATIONALLOWED               (0x35U)  /*!< Service ID: ComM_CommunicationAllowed() */
#define COMM_SID_LIMITPNCTOCHANNELROUTING           (0x36U)  /*!< Service ID: ComM_LimitPncToChannelRouting() */
#define COMM_SID_GETDCMREQUESTSTATUS                (0x37U)  /*!< Service ID: ComM_GetDcmRequestStatus() */
#define COMM_SID_GETMINFULLCOMMODETIMERSTATUS       (0x38U)  /*!< Service ID: ComM_GetMinFullComModeTimerStatus() */

/* Callback function service IDs. */
#define COMM_SID_CBK_NM_NETWORKSTARTINDICATION      (0x15U)  /*!< Service ID: ComM_Nm_NetworkStartIndication() */
#define COMM_SID_CBK_NM_NETWORKMODE                 (0x18U)  /*!< Service ID: ComM_Nm_NetworkMode() */
#define COMM_SID_CBK_NM_PREPAREBUSSLEEPMODE         (0x19U)  /*!< Service ID: ComM_Nm_PrepareBusSleepMode() */
#define COMM_SID_CBK_NM_BUSSLEEPMODE                (0x1AU)  /*!< Service ID: ComM_Nm_BusSleepMode() */
#define COMM_SID_CBK_NM_RESTARTINDICATION           (0x1BU)  /*!< Service ID: ComM_Nm_RestartIndication() */
#define COMM_SID_CBK_NM_STATECHANGENOTIFICATION     (0x1CU)  /*!< Service ID: ComM_Nm_StateChangeNotification() */
#define COMM_SID_CBK_DCM_ACTIVEDIAGNOSTIC           (0x1FU)  /*!< Service ID: ComM_DCM_ActiveDiagnostic() */
#define COMM_SID_CBK_DCM_INACTIVEDIAGNOSTIC         (0x20U)  /*!< Service ID: ComM_DCM_InactiveDiagnostic() */
#define COMM_SID_CBK_ECUM_WAKEUPINDICATION          (0x2AU)  /*!< Service ID: ComM_EcuM_WakeUpIndication() */
#define COMM_SID_CBK_ECUM_PNCWAKEUPINDICATION       (0x2BU)  /*!< Service ID: ComM_EcuM_PNCWakeUpIndication() */
#define COMM_SID_CBK_BUSSMMODEINDICATION            (0x33U)  /*!< Service ID: ComM_BusSM_ModeIndication() */
#define COMM_SID_CBK_BUSSM_BUSSLEEPMODE             (0x70U)  /*!< Service ID: ComM_BusSM_BusSleepMode() */

/* Bit mask to set the Prevent Wake-up status */
#define COMM_WAKEUP_INHIBITION_MASK                 (uint8)0x01U
/* Bit mask to clear the Prevent Wake-up status */
#define COMM_WAKEUP_INHIBITION_CLEAR_MASK           (uint8)0xfeU
/* Bit mask to set the Mode Limitation status */
#define COMM_MODE_LIMITATION_MASK                   (uint8)0x02U
/* Bit mask to clear the Mode Limitation status */
#define COMM_MODE_LIMITATION_CLEAR_MASK             (uint8)0xfdU

#define COMM_E_MODE_LIMITATION                      (Std_ReturnType)(2U)  /*!< Mode is limited and cannot be requested by a ComM User */
#define COMM_INHIBITCNT_MAX                         0xFFFFU

#define COMM_ZERO                                   0U
#define COMM_ONE                                    1U
#define COMM_INIT_ONE                               1U   /* Init value is 1 */
#define COMM_INIT_TWO                               2U   /* Init value is 2 */
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

#define COMM_E_OK                                   0x00U
#define COMM_E_NOT_OK                               0x01U

#ifndef COMM_DUMMY_STATEMENT
/* polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define COMM_DUMMY_STATEMENT(v)                     (v)=(v)
#endif  /* COMM_DUMMY_STATEMENT */

/* Error codes. */
#define COMM_E_NO_ERROR                             (0x00U) /* Used to check if no error occurred - use a value unequal to any error code */
#define COMM_E_NOT_INITED                           (0x01U) /* Error code: API service used without module initialization */
#define COMM_E_WRONG_PARAMETERS                     (0x02U) /* Error code: API service used with wrong parameters */
#define COMM_E_PARAM_POINTER                        (0x03U) /* Error code: API Service used with a null pointer */
#define COMM_E_INIT_FAILED                          (0x04U) /* Error code: Initialization failed */
/* Used to initialize and check the user request bit field. */
#define COMM_NO_REQUESTS                            (0x00U)

/* Send PNC signals on channels with Gateway Type ACTIVE */
#define COMM_SIG_SEND_ACTIVE                        (uint8)(0u)
/* Send PNC signals on channels with Gateway Type PASSIVE */
#define COMM_SIG_SEND_PASSIVE                       (uint8)(1u)
/* Send PNC signals on all channels */
#define COMM_SIG_SEND_ALL                           (uint8)(2u)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_ComM_Rule2.4" polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.8" */
typedef struct sComM_PCConfigType
{
  VAR(uint8, TYPEDEF) ComM_PCConfigNeverUsed;
} ComM_ConfigType;

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
#define COMM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"

/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
extern FUNC(void, COMM_CODE) ComM_Init
(
    P2CONST(ComM_ConfigType, AUTOMATIC, COMM_APPL_CONST) ConfigPtr
);
extern FUNC(void, COMM_CODE) ComM_DeInit(void);
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetStatus
(
    P2VAR(ComM_InitStatusType, AUTOMATIC, COMM_APPL_DATA) Status
);
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetState
(
    NetworkHandleType Channel,
    P2VAR(ComM_StateType, AUTOMATIC, COMM_APPL_DATA) State
);
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetInhibitionStatus
(
    NetworkHandleType Channel,
    P2VAR(ComM_InhibitionStatusType, AUTOMATIC, COMM_APPL_DATA) Status
);
extern FUNC(Std_ReturnType, COMM_CODE) ComM_RequestComMode
(
    ComM_UserHandleType User,
    ComM_ModeType ComMode
);
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetMaxComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
);
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetRequestedComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
);
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetCurrentComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
);
extern FUNC(Std_ReturnType, COMM_CODE) ComM_PreventWakeUp
(
    NetworkHandleType Channel,
    boolean Status
);
extern FUNC(Std_ReturnType, COMM_CODE) ComM_LimitChannelToNoComMode
(
    NetworkHandleType Channel,
    boolean Status
);
extern FUNC(Std_ReturnType, COMM_CODE) ComM_LimitECUToNoComMode
(
    boolean Status
);

#if( COMM_MODELIMITATION == STD_ON )
extern FUNC(Std_ReturnType, COMM_CODE) ComM_ReadInhibitCounter
(
    P2VAR(uint16, AUTOMATIC, COMM_APPL_DATA) CounterValue
);
extern FUNC(Std_ReturnType, COMM_CODE) ComM_ResetInhibitCounter(void);
#endif  /* COMM_MODELIMITATION == STD_ON */

extern FUNC(Std_ReturnType, COMM_CODE) ComM_SetECUGroupClassification
(
    ComM_InhibitionStatusType Status
);
extern FUNC(void, COMM_CODE) ComM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, COMM_APPL_DATA) versioninfo
);
extern FUNC(void, COMM_CODE) ComM_EcuM_WakeUpIndication
(
    NetworkHandleType Channel
);
extern FUNC(void, COMM_CODE) ComM_CommunicationAllowed
(
    NetworkHandleType Channel,
    boolean Allowed
);
extern FUNC(void, COMM_CODE) ComM_BusSM_BusSleepMode
(
    NetworkHandleType Channel
);
extern FUNC(void, COMM_CODE) ComM_MainFunction
(
    NetworkHandleType Channel
);

#if( COMM_PNCSUPPORT == STD_ON )
 /* These functions are used by ComM_Lcfg.c */
extern FUNC(void, COMM_CODE) ComM_PncProcessRxSignalEira
(
    uint8 InternalSignalId,
    P2CONST(uint8, AUTOMATIC, COMM_APPL_DATA) SignalDataRx
);
#if( COMM_PNCGATEWAYENABLED == STD_ON )
extern FUNC(void, COMM_CODE) ComM_PncProcessRxSignalEra
(
    ComM_SizeOfPncSignalType InternalSignalId,
    P2CONST(uint8, AUTOMATIC, COMM_APPL_DATA) SignalDataRx
);
#endif  /* COMM_PNCGATEWAYENABLED == STD_ON */
#endif  /* COMM_PNCSUPPORT == STD_ON */

#define COMM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"

#endif  /* COMM_H_ */


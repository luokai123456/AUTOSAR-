/*
********************************************************************************
*
* File name: ComM.c
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
* Change: Neusar
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: TanLixiang/2019.04.29
* Change: Modify
* Cause:
* (1)Add PNC function.
* (2)Add Det function.
* (3)Add Inhibit function.
********************************************************************************
* Version: 1.2
* Author/Date: TanLixiang/2019.05.05
* Change: Modify
* Cause:
* (1)Add comment.
********************************************************************************
* Version: 2.0
* Author/Date: zhangyong/2020.01.17
* Change: Optimize all configuration item.
* Cause: Optimization
********************************************************************************
* Version: 2.1
* Author/Date: zhangyong/2020.01.19
* Change: Change code style.
* Cause: Optimization
********************************************************************************
* Version: 3.0
* Author/Date: zhangyong/2020.03.27
* Change: Nothing
* Cause: Update to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date: jia_feng/2020.04.27
* Change: Modify COMM_DEV_ERROR_DETECT to COMM_DEVERRORDETECT.
*         Add judgement of COMM_VERSIONINFOAPI.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: jia_feng/2020.05.15
* Change: Delete codes from ComM_CalculateHighestComMode.
* Cause: Modify bugs.
********************************************************************************
* Version: 3.3
* Author/Date: jia_feng/2020.06.19
* Change: Repair PNC function.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: jia_feng/2020.06.19
* Change: ComM_ComAllowed initialized to true for demand.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: jia_feng/2020.06.25
* Change: Modify QAC Check Warning,modify pnc bug in ComM_TF_SiCom_NoCom.
* Cause: Revision and Optimization.
********************************************************************************
* Version: 3.6
* Author/Date: jia_feng/2020.06.28
* Change: Take ComM_TransitionTable out of the function ComM_ChannelStateTransition.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: jia_feng/2020.08.11
* Change: Add COMM_DCM_MODE_INDICATION for the call of Dcm_ComM_XXXModeEntered.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: jia_feng/2020.08.18
* Change: Add COMM_DCM_MODE_INDICATION for Dcm_Cbk.h.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: jia_feng/2020.08.28
* Change: Modify JIRA bugs.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: jia_feng/2020.09.25
* Change: Modify call of Nm service on COMM_NONE_NMTYPEOFCHANNEL,
*         instead of COMM_PASSIVE_NMTYPEOFCHANNEL.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: jia_feng/2020.09.29
* Change: Modify static function declaration.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: fang_tao/2020.10.28
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: JiaF/2020.11.23
* Change: Modify compile warning on IAR.
* Cause: Optimization
********************************************************************************
* Version: 3.14
* Author/Date: JiaF/2020.12.3
* Change: Modify Nm_PassiveStartUp to call repeatedly.
* Cause: Optimization
********************************************************************************
* Version: 3.15
* Author/Date: JiaF/2020.3.3
* Change: Modify the use of LightTimeout timers when COMM_LIGHT_NMTYPEOFCHANNEL.
* Cause: Optimization
********************************************************************************
* Version: 3.16
* Author/Date: JiaF/2020.4.10
* Change: Modify the use of error id(COMM_E_PARAM_POINTER and COMM_E_INIT_FAILED),
*         add the judge of ComMNmVariant in ComM_DCM_ActiveDiagnostic, add
*         judge of COMM_MODELIMITATION for ComM_ReadInhibitCounter and
*         ComM_ResetInhibitCounter.
* Cause: Optimization
********************************************************************************
* Version: 3.17
* Author/Date: JiaF/2020.4.19
* Change: Modify size of ComM_UserReqFullCom.
* Cause: Optimization
********************************************************************************
* Version: 3.18
* Author/Date: JiaF/2020.6.28
* Change: Remove the extra semicolon in ComM_CalculateHighestComMode.
* Cause: Optimization
********************************************************************************
* Version: 3.19
* Author/Date: JiaF/2020.7.14
* Change: 1.Remove redundant lighttimer judgment in ComM_ChannelStateTransition.
*         2.Remove redundant HighestComModeReq assignment in else{}.
* Cause: Optimization
********************************************************************************
* Version: 3.20
* Author/Date: JiaF/2020.9.1
* Change: Increase macro switch control in ComM_EcuM_WakeUpIndication and
*         ComM_ProcessPassiveWakeUp for compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.21
* Author/Date: JiaF/2020.12.10
* Change: Add FrSM support, isolate Nm module.
* Cause: Optimization
********************************************************************************
* Version: 3.22
* Author/Date: JiaF/2020.12.29
* Change: Check QAC, modify pre-compile macro about BUSSM.
* Cause: Optimization
********************************************************************************
* Version: 3.23
* Author/Date: JiaF/2022.1.26
* Change: Add PNC Gateway with Era.
* Cause: Optimization
********************************************************************************
* Version: 3.23
* Author/Date: JiaF/2022.1.27
* Change: Modify precompiled macro of ComM_PncProcessRxSignalEra to
*         COMM_PNCGATEWAYENABLED .
* Cause: Optimization
********************************************************************************
* Version: 3.24
* Author/Date: HeHao/2022.06.20
* Change: 1. Add a COMM_DUMMY_STATEMENT() call for pncIndex in function
*         ComM_EcuM_WakeUpIndication and function ComM_ProcessPassiveWakeUp
*         to avoid compile warnings.
*         2. Merged from Branch 21Q2.
* Cause: Optimization
********************************************************************************
* Version: 3.25
* Author/Date: CuiYH/2023.05.23
* Change: Delete company name from resume.
* Cause: Optimization
********************************************************************************
* Version: 3.26
* Author/Date: HeHao/2023.07.13
* Change: Add a dummy API(ComM_BusSM_BusSleepMode) for compatibility.
* Cause: Optimization
********************************************************************************
* Version: 3.27
* Author/Date: HeHao/2023.08.01
* Change: Support ComMNMVariant LINSLAVE (AUTOSAR R4.4.0).
* Cause: Optimization
********************************************************************************
* Version: 3.28
* Author/Date: HeHao/2023.10.30
* Change: Clear compiler warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.29
* Author/Date: HeHao/2024.01.15
* Change: Optimization for D-55 and PC-356:
*         1. Change ComM_TransitionTable and ComM_TransitionFctTable variables
*         from COMM_VAR_INIT to COMM_CONST.
*         2. Add COMM_DCM_REQUEST_ENABLED to enable or disable Dcm request:
*         In case of COMM_DCM_REQUEST_ENABLED is STD_OFF:
*         (1) Local variable ComM_DcmRequestActive is not declared, and
*         (2) Calling of ComM_DCM_ActiveDiagnostic, ComM_DCM_InactiveDiagnostic
*             has no effect on ComM.
*         3. Comments and code style optimization.
* Cause: Optimization
********************************************************************************
* Version: 3.30
* Author/Date: HeHao/2024.02.20
* Change: 1. Bugfix for CCOREDBUG-4400: Modify ComM_PncProcessRxSignalEra func.
*            This function is to get all related signals of a certain PNC.
*            To get the correct signals, the following steps has to be done:
*            (1) Get the PNC's index and use it as the index of ComM_PncPb which
*                holds the start and end index of the ComM_PncSignalInd array.
*            (2) Use the items of ComM_PncSignalInd array(from start to end) to
*                index the ComM_PncSignal array. Each indexed item of the
*                ComM_PncSignal array is a signal object of the given PNC.
*         2. Comments and code style optimization.
* Cause: Bugfix
********************************************************************************
* Version: 3.31
* Author/Date: HeHao/2024.03.11
* Change: 1. Change P2CONST's ptrclass from XXX_APPL_CONST to XXX_APPL_DATA.
* Cause: Optimization
********************************************************************************
* Version: 3.32
* Author/Date: HeHao/2024.04.02
* Change: 1. Modify P2CONST's ptrclass.
*         2. Modify comments.
* Cause: Optimization
********************************************************************************
* Version: 3.33
* Author/Date: TianL/2024.05.15
* Change: 1. Add a MemMap paragraph definition to the function declaration.
*         2. Modify coding specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.34
* Author/Date: TianL/2024.8.5
* Change: Modify copyright.
* Cause: Update
********************************************************************************
* Version: 3.35
* Author/Date: TianL/2024.8.30
* Change: Optimize the request mode transition in the ComM_ChannelStateTransition.
* Cause: Optimization
********************************************************************************
* Version: 3.36
* Author/Date: TianL/2024.9.20
* Change: Add the call to ComM_IndicateDcmChannelState in ComM_TF_NoCom_FullReadySleep.
* Cause: Bugfix
********************************************************************************
* Version: 3.37
* Author/Date: TianL/2024.12.4
* Change: Change the index of the array ComM_UserReqPncFullCom in the function
*         ComM_TF_SiCom_NoCom.
* Cause: Bugfix
********************************************************************************
* Version: 3.38
* Author/Date: TianL/2024.12.16
* Change: Add the macro switch for using BswM_ComM_CurrentPNCMode and BswM_ComM_CurrentMode.
* Cause: Bugfix
********************************************************************************
* Version: 3.39
* Author/Date: TianL/2025.1.21
* Change: 1. Remove Set pnc request to default value in the function ComM_TF_SiCom_NoCom.
*         2. Add Nm_NetworkRelease() in the function ComM_TF_NoCom_FullReadySleep.
* Cause: Bugfix
********************************************************************************
* Version: 3.40
* Author/Date: TianL/2025.2.21
* Change: Change the location of the defined PncIndex variable in
*         ComM_EcuM_WakeUpIndication() and ComM_ProcessPassiveWakeUp().
* Cause: Bugfix
********************************************************************************
* Version: 3.41
* Author/Date: TianL/2025.2.27
* Change: Remove calling of Nm_PassiveStartUp in ComM_EcuM_WakeUpIndication function.
* Cause: Bugfix
********************************************************************************
* Version: 3.42
* Author/Date: TianL/2025.3.3
* Change: Modify ComM_Nm_NetworkMode function, as per SWS_ComM_00296 it should call
*         ComM_TF_SiCom_FullReadySleep instead of ComM_TF_NoCom_FullReadySleep.
* Cause: Bugfix
********************************************************************************
* Version: 3.43
* Author/Date: TianL/2025.3.3
* Change: Modify the sleep sequence of ComMNmVariant = LIGHT channel. When
*         ComMNmLightTimeout expires, the channel shall be switched directly to
*         NoCom without entering SiCom.
* Cause: Bugfix
********************************************************************************
* Version: 3.44
* Author/Date: TianL/2025.3.27
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Bugfix
********************************************************************************
* Version: 3.45
* Author/Date: TianL/2025.6.16
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.46
* Author/Date: TianL/2025.6.23
* Change: Remove the function of releasing the network of the Lin channel in the
*         ComM_TF_NoCom_FullReadySleep function.
* Cause: Bugfix
********************************************************************************
* Version: 3.47
* Author/Date: TianL/2025.6.23
* Change: Modify the notification error that occurs after state transition in the
*         ComM_PncStateTransition function.
* Cause: Bugfix
********************************************************************************
* Version: 3.48
* Author/Date: TianL/2025.6.24
* Change: Modify the mode request in the ComM_Nm_NetworkMode function.
* Cause: Bugfix
********************************************************************************
* Version: 3.49
* Author/Date: TianL/2025.7.15
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Bugfix
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComM.h"

#if( COMM_BUSNM_EXSIT_ENABLED == STD_ON )
#include "Nm.h"
#endif  /* COMM_BUSNM_EXSIT_ENABLED == STD_ON */

#if( COMM_BUSTYPE_CAN_ENABLED == STD_ON )
#include "CanSM.h"
#endif  /* COMM_BUSTYPE_CAN_ENABLED == STD_ON */

#if( COMM_BUSTYPE_ETH_ENABLED == STD_ON )
#include "EthSM.h"
#endif  /* COMM_BUSTYPE_ETH_ENABLED == STD_ON */

#if( COMM_BUSTYPE_LIN_ENABLED == STD_ON )
#include "LinSM.h"
#endif  /* COMM_BUSTYPE_LIN_ENABLED == STD_ON */

#if( COMM_BUSTYPE_FR_ENABLED == STD_ON )
#include "FrSM.h"
#endif  /* COMM_BUSTYPE_FR_ENABLED == STD_ON */

#include "ComM_Cfg.h"
#include "SchM_ComM.h"

#if( COMM_DEVERRORDETECT == STD_ON )
#include "Det.h"
#endif  /* COMM_DEVERRORDETECT == STD_ON */

#if( COMM_DCM_MODE_INDICATION == STD_ON )
#include "Dcm_Cbk.h"
#endif  /* COMM_DCM_MODE_INDICATION == STD_ON */

#include "BswM_ComM.h"
#include "ComM_BusSM.h"
#include "ComM_Dcm.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/*
********************************************************************************
*    Local Types
********************************************************************************
*/
/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
#define COMM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"

static FUNC(uint8, COMM_CODE) ComM_CalculateHighestComMode
(
    NetworkHandleType Channel,
    P2VAR(uint8, AUTOMATIC, COMM_APPL_DATA) acpInternalRequest
);
static FUNC(void, COMM_CODE) ComM_RequestBusSMMode
(
    NetworkHandleType Channel,
    ComM_ModeType ComM_Mode
);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_TF_No_Transition(NetworkHandleType Channel);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_TF_No_Action(NetworkHandleType Channel);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_TF_NetReq_ReadyS(NetworkHandleType Channel);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_TF_Full_SiCom(NetworkHandleType Channel);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_TF_SiCom_NoCom(NetworkHandleType Channel);
static FUNC(void, COMM_CODE) ComM_TF_SiCom_FullReadySleep(NetworkHandleType Channel);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_TF_NoCom_NetReq(NetworkHandleType Channel);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_TF_NoCom_FullReadySleep(NetworkHandleType Channel);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_TF_ReadyS_NetReq(NetworkHandleType Channel);
static FUNC(void, COMM_CODE) ComM_TF_ReadyS_NoCom(NetworkHandleType Channel);
static FUNC(void, COMM_CODE) ComM_ChannelStateTransition
(
    NetworkHandleType Channel,
    uint8 HighestComModeReq
);
static FUNC(void, COMM_CODE) ComM_ChannelHandleTimers
(
    NetworkHandleType Channel,
    uint8 InternalRequest
);
static FUNC(uint8, COMM_CODE) ComM_IsUserRequestingChannel(NetworkHandleType Channel);
static FUNC(Std_ReturnType, COMM_CODE) ComM_GetCurrentBusSMMode
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    NetworkHandleType Channel,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_ProcessPassiveWakeUp(NetworkHandleType channel);

#if( COMM_PNCSUPPORT == STD_ON )
static FUNC(uint8, COMM_CODE) ComM_PncInFullComWakesUpTheChannel
(
    NetworkHandleType Channel, uint8 HighestRequest
);
static FUNC(uint8, COMM_CODE) ComM_CalculateHighestPNComMode(uint8 PncIndex);
static FUNC(void, COMM_CODE) ComM_PncClearBitInSignal
(
    ComM_SizeOfPncSignalType InternalSignalId,
    ComM_PncIterType InternalPncId
);
static FUNC(void, COMM_CODE) ComM_PncStateTransition
(
    uint8 ComM_CurrentPnc,
    uint8 HighestComModeReq
);
static FUNC(void, COMM_CODE) ComM_PncModeArbitration(NetworkHandleType Channel);
static FUNC(void, COMM_CODE) ComM_HandlePncPrepareSleepTimer(void);
static FUNC(void, COMM_CODE) ComM_PncInit(void);
static FUNC(void, COMM_CODE) ComM_PncSetBitInSignal
(
    ComM_SizeOfPncSignalType InternalSignalId,
    ComM_PncIterType InternalPncId
);
#endif  /* COMM_PNCSUPPORT == STD_ON */

#if( COMM_PNCPASSIVEGWSUPPORT == STD_ON )
static FUNC(boolean, COMM_CODE) ComM_PncIsOnlySystemUserRequesting(ComM_PncIterType pncIndex,uint32 byteIndex);
static FUNC(boolean, COMM_CODE) ComM_PncIsEraReceivedOnActiveChannel(ComM_PncIterType pncIndex);
#endif  /* COMM_PNCPASSIVEGWSUPPORT == STD_ON */

#if( COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL == STD_ON )
static FUNC(void, COMM_CODE) ComM_PncModeSendSignal
(
    ComM_PncIterType PncHandle,
    boolean activeState,
    uint8 sigType
);
#endif  /* COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL == STD_ON */

#if( ((COMM_MODELIMITATION == STD_ON) || (COMM_WAKEUPINHIBITIONENABLED == STD_ON)) )
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(boolean, COMM_CODE) ComM_ChannelIsLimited(NetworkHandleType channel);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(boolean, COMM_CODE) ComM_NoComLimitationActive(NetworkHandleType channel);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(boolean, COMM_CODE) ComM_PreventWakeUpActive(NetworkHandleType channel);
#endif  /* ((COMM_MODELIMITATION == STD_ON) || (COMM_WAKEUPINHIBITIONENABLED == STD_ON)) */

static FUNC(void, COMM_CODE) ComM_IndicateDcmChannelState
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    NetworkHandleType Channel,
    ComM_ModeType ComMode
);
static FUNC(void, COMM_CODE) ComM_Det_ErrorReport(uint8 ApiId, uint8 ErrorId);

#define COMM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Local Variables
********************************************************************************
*/
#define COMM_START_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static VAR(ComM_InitStatusType, COMM_VAR_INIT) ComM_InitStatus = COMM_UNINIT;  /* Initial state. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static VAR(uint8, COMM_VAR_INIT) ComM_ActiveComMode[COMM_ACTIVE_CHANNEL] = {COMM_NO_COM_NO_PENDING_REQUEST};  /* Current state of a channel. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static VAR(uint8, COMM_VAR_INIT) ComM_BusComModeReq[COMM_ACTIVE_CHANNEL] = {COMM_NO_COM_NO_PENDING_REQUEST};  /* State requested externally (bus). */

#if( COMM_PNCSUPPORT == STD_ON )
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
static VAR(uint8, COMM_VAR_INIT) ComM_ActivePncComMode[COMM_PNC_SIZE] = {COMM_PNC_NO_COMMUNICATION};  /* Pnc current state of a channel. */  /* PRQA S 4424 */ /* NSCA_QAC_ComM_Rule10.3 */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
static VAR(uint8, COMM_VAR_INIT) ComM_BusPncComModeReq[COMM_PNC_SIZE] = {COMM_PNC_NO_COMMUNICATION};  /* Pnc state requested externally (bus). */  /* PRQA S 4424 */ /* NSCA_QAC_ComM_Rule10.3 */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static VAR(uint16, COMM_VAR_INIT) ComM_PncPSleepTimer[COMM_PNC_SIZE] = {COMM_ZERO};  /* PNC mode timer. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static VAR(uint8, COMM_VAR_INIT) ComM_PncSignalValues[COMM_SIZE_OF_SIGNAL_VALUES] = {COMM_ZERO};  /* PNC signal value. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static VAR(uint8, COMM_VAR_INIT) ComM_UserReqPncFullCom[COMM_SIZE_OF_USER_PNC_REQ_FULL_COM] = {COMM_NO_REQUESTS};  /* PNC user request state. */
#endif  /* COMM_PNCSUPPORT == STD_ON */

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static VAR(uint16, COMM_VAR_INIT) ComM_MinFullComModeTimer[COMM_ACTIVE_CHANNEL] = {COMM_ZERO};  /* Full to ready sleep mode timer. */
#if( COMM_DCM_REQUEST_ENABLED == STD_ON )
/*static*/ VAR(uint8, COMM_VAR_INIT) ComM_DcmRequestActive[COMM_ACTIVE_CHANNEL] = {FALSE};  /* Dcm request state. */
#endif  /* COMM_DCM_REQUEST_ENABLED == STD_ON */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static VAR(uint8, COMM_VAR_INIT) ComM_UserReqFullCom[COMM_SIZE_OF_USER_REQ_FULL_COM + COMM_ONE] = {COMM_NO_REQUESTS}; /* User request state. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static VAR(uint32, COMM_VAR_INIT) ComM_LightTimer[COMM_ACTIVE_CHANNEL] = {COMM_ZERO};  /* Ready sleep to sleep mode timer. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static VAR(uint8, COMM_VAR_INIT) ComM_ComAllowed[COMM_ACTIVE_CHANNEL] = {FALSE};  /* Communication allowed status of a channel. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static VAR(ComM_InhibitionType, COMM_VAR_INIT) ComM_Inhibition = {COMM_ZERO};  /* Status of mode limitation (inhibition). */

#define COMM_STOP_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define COMM_START_SEC_CONST
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* ComM state machine. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static CONST(uint8, COMM_CONST) ComM_TransitionTable[COMM_MAX_NUMBER_OF_STATES][COMM_MAX_NUMBER_OF_STATES] =  /* PRQA S 3218 */ /* NSCA_QAC_ComM_Rule8.9*/
{
  {
    COMM_MAX_NUMBER_OF_STATES,   COMM_NO_COM_NO_PENDING_REQUEST,  COMM_FULL_COM_READY_SLEEP, COMM_SILENT_COM,                 COMM_NO_COM_NO_PENDING_REQUEST  /* COMM_NO_COM_NO_PENDING_REQUEST */
  },
  {
    COMM_NO_COM_REQUEST_PENDING, COMM_MAX_NUMBER_OF_STATES,       COMM_MAX_NUMBER_OF_STATES, COMM_MAX_NUMBER_OF_STATES,       COMM_MAX_NUMBER_OF_STATES       /* COMM_NO_COM_REQUEST_PENDING */
  },
  {
    COMM_NO_COM_REQUEST_PENDING, COMM_FULL_COM_NETWORK_REQUESTED, COMM_MAX_NUMBER_OF_STATES, COMM_FULL_COM_NETWORK_REQUESTED, COMM_FULL_COM_NETWORK_REQUESTED /* COMM_FULL_COM_NETWORK_REQUESTED */
  },
  {
    COMM_NO_COM_REQUEST_PENDING, COMM_FULL_COM_READY_SLEEP,       COMM_FULL_COM_READY_SLEEP, COMM_MAX_NUMBER_OF_STATES,       COMM_FULL_COM_READY_SLEEP       /* COMM_FULL_COM_READY_SLEEP */
  },
  {
    COMM_MAX_NUMBER_OF_STATES,   COMM_MAX_NUMBER_OF_STATES,       COMM_FULL_COM_READY_SLEEP, COMM_SILENT_COM,                 COMM_MAX_NUMBER_OF_STATES       /* COMM_SILENT_COM */
  }
};

/* ComM state machine process. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
static CONST(ComM_TransitionFunctionType, COMM_CONST) ComM_TransitionFctTable[COMM_MAX_NUMBER_OF_STATES][COMM_MAX_NUMBER_OF_STATES] =  /* PRQA S 3218 */ /* NSCA_QAC_ComM_Rule8.9*/
{
  {
    ComM_TF_No_Transition, ComM_TF_No_Action,            ComM_TF_NetReq_ReadyS, ComM_TF_Full_SiCom,    ComM_TF_SiCom_NoCom           /* COMM_NO_COM_NO_PENDING_REQUEST */
  },
  {
    ComM_TF_No_Action,     ComM_TF_No_Transition,        ComM_TF_No_Transition, ComM_TF_No_Transition, ComM_TF_No_Transition         /* COMM_NO_COM_REQUEST_PENDING */
  },
  {
    ComM_TF_No_Action,     ComM_TF_NoCom_NetReq,         ComM_TF_No_Transition, ComM_TF_ReadyS_NetReq, ComM_TF_NoCom_NetReq          /* COMM_FULL_COM_NETWORK_REQUESTED */
  },
  {
    ComM_TF_No_Action,     ComM_TF_NoCom_FullReadySleep, ComM_TF_NetReq_ReadyS, ComM_TF_No_Transition, ComM_TF_NoCom_FullReadySleep  /* COMM_FULL_COM_READY_SLEEP */
  },
  {
    ComM_TF_No_Transition, ComM_TF_No_Transition,        ComM_TF_NetReq_ReadyS, ComM_TF_Full_SiCom,    ComM_TF_No_Transition         /* COMM_SILENT_COM */
  }
};

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define COMM_STOP_SEC_CONST
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#define COMM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
* Function Name: ComM_Det_ErrorReport
*
* Explanation: Function to report Error to Det.
*
* param: ApiId: Unique Api ID of ComM manager service.
*       ErrorId: Det Error ID of ComM manager.
*
* retval: None
********************************************************************************
*/
static void ComM_Det_ErrorReport(uint8 ApiId, uint8 ErrorId)
{
#if( COMM_DEVERRORDETECT == STD_ON )
    if( ErrorId != COMM_E_NO_ERROR )  /* Error detected. */
    {
        (void)Det_ReportError(COMM_MODULE_ID, COMM_INSTANCE_ID_DET, ApiId, ErrorId);  /* Report Error to Det. */
    }
#else
    {
        COMM_DUMMY_STATEMENT(ApiId);
        COMM_DUMMY_STATEMENT(ErrorId);
    }
#endif  /* COMM_DEVERRORDETECT == STD_ON */
}

#if( STD_ON == COMM_VERSIONINFOAPI )
/*
********************************************************************************
* Function Name: ComM_GetVersionInfo
*
* Explanation: This function returns the published information.
*
* param: versioninfo: version info.
*
* retval: None
********************************************************************************
*/
FUNC(void, COMM_CODE) ComM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, COMM_APPL_DATA) versioninfo
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( NULL_PTR == versioninfo )  /* Check point. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
       errorId = COMM_E_PARAM_POINTER;
    }
    else  /* Set version info. */
    {
       /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_ComM_TAINTED_PTR" */
       versioninfo->moduleID = COMM_MODULE_ID;
       versioninfo->vendorID = COMM_VENDOR_ID;
       versioninfo->sw_major_version = COMM_SW_MAJOR_VERSION;
       versioninfo->sw_minor_version = COMM_SW_MINOR_VERSION;
       versioninfo->sw_patch_version = COMM_SW_PATCH_VERSION;
    }

    ComM_Det_ErrorReport(COMM_SID_GETVERSIONINFO, errorId);  /* Det report. */
}
#endif  /* STD_ON == COMM_VERSIONINFOAPI */

/*
********************************************************************************
* Function Name: ComM_GetStatus
*
* Explanation: Returns the initialization status of the AUTOSAR Communication
*              Manager.(Synchronous & Non Reentrant)
*
* param: Status: COMM_UNINIT: The ComM is not initialized or not usable.
*        COMM_INIT: The ComM is initialized and usable.
*
* retval: lResult: E_OK: Successfully return of initialization status.
*             E_NOT_OK: Return of initialization status failed.
********************************************************************************
*/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetStatus
(
    P2VAR(ComM_InitStatusType, AUTOMATIC, COMM_APPL_DATA) Status
)
{
    Std_ReturnType lResult = COMM_E_NOT_OK;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( NULL_PTR == Status )  /* Check point. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = COMM_E_PARAM_POINTER;
    }
    else  /* Set init state. */
    {
        lResult = COMM_E_OK;
        /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_ComM_TAINTED_PTR" */
        *Status = ComM_InitStatus;
    }

    ComM_Det_ErrorReport(COMM_SID_GETSTATUS, errorId);  /* Det report. */

    return lResult;
}

/*
********************************************************************************
* Function Name: ComM_EcuM_WakeUpIndication
*
* Explanation: Notification of a wake up on the corresponding channel.
*              (Synchronous & Reentrant)
*
* param: Channel: Channel id.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
FUNC(void, COMM_CODE) ComM_EcuM_WakeUpIndication(NetworkHandleType Channel)
{

#if( COMM_SYNCHRONOUSWAKEUP == STD_ON )
    uint8 ComM_ChannelIndex;

#if( COMM_PNCSUPPORT == STD_ON )
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 PncIndex;
#endif  /* COMM_PNCSUPPORT == STD_ON */

#endif  /* COMM_SYNCHRONOUSWAKEUP == STD_ON */



    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( ComM_InitStatus != COMM_INIT )  /* Check initial state. */
    {
        errorId = COMM_E_NOT_INITED;
    }
    else if( Channel >= COMM_ACTIVE_CHANNEL )  /* Check channel id. */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
    }
    else
    {

#if( COMM_SYNCHRONOUSWAKEUP == STD_ON )
        /* SWS_ComM_00694: Wake up of one channel shall lead to a wake up of all channels. */
        for( ComM_ChannelIndex = COMM_ZERO; ComM_ChannelIndex < COMM_ACTIVE_CHANNEL; ComM_ChannelIndex++ )
        {
            if( COMM_ZERO == (ComM_ActiveComMode[ComM_ChannelIndex] & COMM_FULL_COMMUNICATION) )
            {
                /* Set wakeup default comm state. */
                ComM_BusComModeReq[ComM_ChannelIndex] = ComM_Channel[ComM_ChannelIndex].WakeupStateOfChannel;
            }
        }

#if( COMM_PNCSUPPORT == STD_ON )
        for( PncIndex = COMM_ZERO; PncIndex < COMM_PNC_SIZE; PncIndex++ )
        {
            if( ((uint8)COMM_PNC_NO_COMMUNICATION == ComM_ActivePncComMode[PncIndex]) && ((uint8)COMM_PNC_NO_COMMUNICATION == ComM_BusPncComModeReq[PncIndex]) )
            {
                /* SWS_ComM_00931 Set wakeup default pnc state. */
                ComM_BusPncComModeReq[PncIndex] = (uint8)COMM_PNC_PREPARE_SLEEP;
            }
        }
#endif  /* COMM_PNCSUPPORT == STD_ON */

#else  /* COMM_SYNCHRONOUSWAKEUP != STD_ON */
        if( COMM_ZERO == (ComM_ActiveComMode[Channel] & COMM_FULL_COMMUNICATION) )
        {
            /* SWS_ComM_00893 Set wakeup default comm state. */
            ComM_BusComModeReq[Channel] = ComM_Channel[Channel].WakeupStateOfChannel;
        }

#endif  /* COMM_SYNCHRONOUSWAKEUP == STD_ON */

    }
    ComM_Det_ErrorReport(COMM_SID_CBK_ECUM_WAKEUPINDICATION, errorId);  /* Det report. */
}

/*
********************************************************************************
* Function Name:   ComM_GetState
*
* Explanation: Return current state, including sub-state, of the ComM channel
*              state machine.(Synchronous & Non Reentrant)
*
* param: Channel: The Network Channel for the requested state of ComM state machine.
*        State: State of the ComM channel state machine.
*
* retval: E_OK: Successfully return current state of ComM state machine.
*         E_NOT_OK: Return of current state of ComM state machine failed.
********************************************************************************
*/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetState(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    NetworkHandleType Channel,
    P2VAR(ComM_StateType, AUTOMATIC, COMM_APPL_DATA) State
)
{
    uint8 lResult = COMM_E_OK;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( ComM_InitStatus != COMM_INIT )  /* Check initial state. */
    {
        errorId = COMM_E_NOT_INITED;
        lResult = COMM_E_NOT_OK;
    }
    else if( Channel >= COMM_ACTIVE_CHANNEL )  /* Check channel id. */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
        lResult = COMM_E_NOT_OK;
    }
    else if( NULL_PTR == State )  /* Check point. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = COMM_E_PARAM_POINTER;
        lResult = COMM_E_NOT_OK;
    }
    else  /* Set active state. */
    {
        /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_ComM_TAINTED_PTR" */
        *State = ComM_ActiveComMode[Channel];
    }

    ComM_Det_ErrorReport(COMM_SID_GETSTATE, errorId);  /* Det report. */

    return lResult;
}

#if( COMM_PNCSUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: ComM_PncInit
*
* Explanation: Pnc initial function.
*
* param: void
*
* retval: None
********************************************************************************
*/
static FUNC(void, COMM_CODE) ComM_PncInit(void)
{
    uint8 UserReqPncFullIndex;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 PncIndex;
    uint8 PncSignalValueIndex;

    for( UserReqPncFullIndex = COMM_ZERO; UserReqPncFullIndex < COMM_PNC_SIZE; UserReqPncFullIndex++ )
    {
        ComM_UserReqPncFullCom[UserReqPncFullIndex] = COMM_NO_REQUESTS;   /* Set pnc request to default value */
    }

    for( PncIndex = COMM_ZERO; PncIndex < COMM_PNC_SIZE; PncIndex++ )  /* Set pnc state to default value. */
    {
        ComM_PncPSleepTimer[PncIndex] = COMM_ZERO;
        ComM_ActivePncComMode[PncIndex] = (uint8)COMM_PNC_NO_COMMUNICATION;
        ComM_BusPncComModeReq[PncIndex] = (uint8)COMM_PNC_NO_COMMUNICATION;
    }

    /* Clear stored signal values (EIRA_RX, ERA_RX, EIRA_TX) */
    for( PncSignalValueIndex = COMM_ZERO; PncSignalValueIndex < COMM_SIZE_OF_SIGNAL_VALUES; PncSignalValueIndex++ )
    {
        ComM_PncSignalValues[PncSignalValueIndex] = COMM_ZERO;
    }
}
#endif  /* COMM_PNCSUPPORT == STD_ON */

/*
********************************************************************************
* Function Name: ComM_IsUserRequestingChannel
*
* Explanation: Get user request of the given channel.
*
* param: Channel: Channel id.
*
* retval: TRUE: There're user(s) requests on this channel.
*         FALSE: There's no user request on this channel.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(uint8, COMM_CODE) ComM_IsUserRequestingChannel(NetworkHandleType Channel)
{
    uint8 UserReqFullComIndex;
    uint8 lResult = FALSE;

    /* ComM_ChannelPb holds start and end index of ComM_UserReqFullCom array,
       item of ComM_UserReqFullCom holds the requests from ComMUsers that are
       referenced by ComMUserChannel of the given ComMChannel. */
    for( UserReqFullComIndex = ComM_ChannelPb[Channel].UserReqFullComStartIdxOfChannelPb;
            UserReqFullComIndex < ComM_ChannelPb[Channel].UserReqFullComEndIdxOfChannelPb; UserReqFullComIndex++ )
    {
        if( ComM_UserReqFullCom[UserReqFullComIndex] != COMM_NO_REQUESTS )  /* Check user request. */
        {
            lResult = TRUE;
        }
    }

    return lResult;
}

#if( COMM_PNCSUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: ComM_PncInFullComWakesUpTheChannel
*
* Explanation: Get Pnc request state.
*
* param: Channel: Channel id.
*       HighestRequest: Channel high request.
*
* retval: Channel request which is calculated.
********************************************************************************
*/
static FUNC(uint8, COMM_CODE) ComM_PncInFullComWakesUpTheChannel
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    NetworkHandleType Channel,
    uint8 HighestRequest
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 PncIndex;
    uint8 PncPbIndIter;

    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( COMM_NO_COM_NO_PENDING_REQUEST == HighestRequest )
    {
        for( PncPbIndIter = ComM_ChannelPb[Channel].PncPbIndStartIdxOfChannelPb;
            PncPbIndIter < ComM_ChannelPb[Channel].PncPbIndEndIdxOfChannelPb; PncPbIndIter++ )
        {
            PncIndex = ComM_PncPbInd[PncPbIndIter];
            if( ComM_ActivePncComMode[PncIndex] != (uint8)COMM_PNC_NO_COMMUNICATION )  /* Check Pnc state. */
            {
                /* polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_ComM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.1" */
                HighestRequest = COMM_FULL_COM_READY_SLEEP;
                break;
            }
        }
    }

    return HighestRequest;
}
#endif  /* COMM_PNCSUPPORT == STD_ON */

/*
********************************************************************************
* Function Name: ComM_CalculateHighestComMode
*
* Explanation: Calculate channel highest request.
*
* param: Channel: Channel id.
*        acpInternalRequest: TRUE: Update full-mode timer.
*                            FALSE: No update full-mode timer.
*
* retval: Channel request which is calculated.
********************************************************************************
*/
static FUNC(uint8, COMM_CODE) ComM_CalculateHighestComMode
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    NetworkHandleType Channel,
    P2VAR(uint8, AUTOMATIC, COMM_APPL_DATA) acpInternalRequest
)
{
    uint8 HighestRequest = COMM_NO_COM_NO_PENDING_REQUEST;

    *acpInternalRequest = FALSE;

#if( (COMM_MODELIMITATION == STD_ON) || (COMM_WAKEUPINHIBITIONENABLED == STD_ON) )
    if( FALSE == ComM_ChannelIsLimited(Channel) )  /* Check inhibit. */
#endif  /* (COMM_MODELIMITATION == STD_ON) || (COMM_WAKEUPINHIBITIONENABLED == STD_ON) */
    {
        if( (uint8)TRUE == ComM_IsUserRequestingChannel(Channel) )  /* Check user request. */
        {
            /* ComMUser is requesting this channel. */
            HighestRequest = COMM_FULL_COM_NETWORK_REQUESTED;
            *acpInternalRequest = TRUE;
        }
    }

    if( (uint8)FALSE == *acpInternalRequest )
    {
#if( COMM_DCM_REQUEST_ENABLED == STD_ON )
        /* In case of COMM_DCM_REQUEST_ENABLED is STD_OFF,
           Dcm request state shall have no effect on ComM. */
        if( (uint8)TRUE == ComM_DcmRequestActive[Channel] )  /* Dcm request channel. */
        {
            /* DCM is requesting this channel. */
            HighestRequest = COMM_FULL_COM_NETWORK_REQUESTED;
            *acpInternalRequest = TRUE;
        }
#endif  /* COMM_DCM_REQUEST_ENABLED == STD_ON */

        /* polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule14.3" polyspace +1 DEFECT:USELESS_IF [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if( (uint8)FALSE == *acpInternalRequest )
        {
#if( COMM_PNCSUPPORT == STD_ON )
            if( ComM_ChannelPb[Channel].PncPbIndStartIdxOfChannelPb != COMM_NO_PNCPBINDSTARTIDXOFCHANNELPB )
            {
                HighestRequest = ComM_PncInFullComWakesUpTheChannel(Channel, HighestRequest);  /* Check pnc request. */
                if( COMM_NO_COM_NO_PENDING_REQUEST != HighestRequest )
                {
                    *acpInternalRequest = TRUE;
                }
            }
#endif  /* COMM_PNCSUPPORT == STD_ON */

            if( (COMM_NO_COM_NO_PENDING_REQUEST == HighestRequest) || (COMM_FULL_COM_NETWORK_REQUESTED == ComM_BusComModeReq[Channel]) )
            {
                /* 1. No user and no DCM request, or
                   2. ComM_BusComModeReq is the highest COMM_FULL_COM_NETWORK_REQUESTED.
                   e.g. Passive wakeup scenario, communication requested by remote ECU. */
                HighestRequest = ComM_BusComModeReq[Channel];  /* Check bus com mode. */
            }
        }
    }

    return HighestRequest;
}

/*
********************************************************************************
* Function Name: ComM_RequestBusSMMode
*
* Explanation: ComM request CanSm state.
*
* param: Channel: Channel id.
*        ComM_Mode: ComM mode state.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COMM_CODE) ComM_RequestBusSMMode
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    NetworkHandleType Channel,
    ComM_ModeType ComM_Mode
)
{
    /* polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_ComM_OBAI" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_ComM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.1" */
    switch(ComM_Channel[Channel].BusTypeOfChannel)
    {

#if( COMM_BUSTYPE_CAN_ENABLED == STD_ON )
        case COMM_BUS_TYPE_CAN:
            (void)CanSM_RequestComMode(Channel, ComM_Mode);
            break;
#endif  /* COMM_BUSTYPE_CAN_ENABLED == STD_ON */

#if( COMM_BUSTYPE_FR_ENABLED == STD_ON )
        case COMM_BUS_TYPE_FR:
            (void)FrSM_RequestComMode(Channel, ComM_Mode);
            break;
#endif  /* COMM_BUSTYPE_FR_ENABLED == STD_ON */

#if( COMM_BUSTYPE_LIN_ENABLED == STD_ON )
        case COMM_BUS_TYPE_LIN:
            (void)LinSM_RequestComMode(Channel, ComM_Mode);
            break;
#endif  /* COMM_BUSTYPE_LIN_ENABLED == STD_ON */

#if( COMM_BUSTYPE_ETH_ENABLED == STD_ON )
        case COMM_BUS_TYPE_ETH:
            (void)EthSM_RequestComMode(Channel, ComM_Mode);
            break;
#endif  /* COMM_BUSTYPE_ETH_ENABLED == STD_ON */
        /* polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        default:
            /* Do nothing. */
            break;
    }
}

/*
********************************************************************************
* Function Name: ComM_TF_No_Transition
*
* Explanation: No transition.
*
* param: Channel: Channel id.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_TF_No_Transition(NetworkHandleType Channel)
{
    COMM_DUMMY_STATEMENT(Channel);
}

/*
********************************************************************************
* Function Name: ComM_TF_No_Action
*
* Explanation: No action.
*
* param: Channel: Channel id.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_TF_No_Action(NetworkHandleType Channel)
{
    COMM_DUMMY_STATEMENT(Channel);
}

/*
********************************************************************************
* Function Name: ComM_TF_NetReq_ReadyS
*
* Explanation: Translate to ready sleep state.
*
* param: Channel: Channel id.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_TF_NetReq_ReadyS(NetworkHandleType Channel)
{
    /* polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_ComM_OBAI" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_ComM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.1" */
    if( COMM_LIGHT_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant )
    {
        ComM_LightTimer[Channel] = ComM_Channel[Channel].ComMNmLightTimeout;
    }
    else if( COMM_LINSLAVE_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant )
    {
        /* Reason: No user request ComM_RequestComMode(COMM_FULL) for LINSLAVE.
           Action: 1. ComMChannel state change to COMM_FULL_COM_READY_SLEEP, And
                   2. Request COMM_NO_COMMUNICATION to LinSM.
           Note: LinSM will store the request from ComM without further action.
                 LinSM will notify ComM by calling ComM_BusSM_BusSleepMode when
                 LinSM_GotoSleepIndication is called by LinIf.
                 ComM can be changed to NetReq if User or DCM request full com.
        */
        ComM_RequestBusSMMode(Channel, COMM_NO_COMMUNICATION);
    }
#if( (COMM_BUSNM_EXSIT_ENABLED == STD_ON) && (COMM_BUSNM_EXIST_FULL_VARIANT == STD_ON) )
    else if( COMM_FULL_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant )
    {
        (void)Nm_NetworkRelease(Channel);
    }
    else
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Do nothing. */
    }
#endif  /* (COMM_BUSNM_EXSIT_ENABLED == STD_ON) && (COMM_BUSNM_EXIST_FULL_VARIANT == STD_ON) */
}

/*
********************************************************************************
* Function Name: ComM_TF_Full_SiCom
*
* Explanation: Translate to silent state.
*
* param: Channel: Channel id.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_TF_Full_SiCom(NetworkHandleType Channel)
{
    if( COMM_FULL_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant )  /* The NM channel. */
    {
        /* SWS_ComM_00071 : switch off the transmission capability and keep
           reception capability on by requesting the corresponding Com mode from
           the Bus State Manager. */
        ComM_RequestBusSMMode(Channel, COMM_SILENT_COMMUNICATION);
    }
    ComM_IndicateDcmChannelState(Channel, COMM_SILENT_COMMUNICATION);  /* Indicate silent state to Dcm */
}

/*
********************************************************************************
* Function Name: ComM_TF_SiCom_NoCom
*
* Explanation: Translate to no communicate state.
*
* param: Channel: Channel id.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_TF_SiCom_NoCom(NetworkHandleType Channel)
{
    uint8 UserReqFullComIndex;

    ComM_ActiveComMode[Channel] = COMM_NO_COM_NO_PENDING_REQUEST;  /* Set no communication. */
    ComM_RequestBusSMMode(Channel, COMM_NO_COMMUNICATION);  /* Indicate no communication to CanSm. */

    for( UserReqFullComIndex = ComM_ChannelPb[Channel].UserReqFullComStartIdxOfChannelPb;
         UserReqFullComIndex < ComM_ChannelPb[Channel].UserReqFullComEndIdxOfChannelPb; UserReqFullComIndex++ )
    {
        ComM_UserReqFullCom[UserReqFullComIndex] = COMM_NO_REQUESTS;  /* Set no user request. */
    }

    ComM_IndicateDcmChannelState(Channel, COMM_NO_COMMUNICATION);  /* Indicate no communicate state to Dcm. */
}

/*
************************************************************************************************************************
* Function Name: ComM_TF_SiCom_FullReadySleep
*
* Explanation: ComM channel state machine transition: COMM_SILENT_COMMUNICATION to COMM_FULL_COM_READY_SLEEP sub-state,
*              due to the Network Manager module indicates ComM_Nm_NetworkMode (SWS_ComM_00296).
*
* Param: Channel: Channel id.
*
* Retval: None
************************************************************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_TF_SiCom_FullReadySleep(NetworkHandleType Channel)
{
    /* SWS_ComM_00133: On entering sub-state COMM_FULL_COM_READY_SLEEP and configuration parameter ComMNmVariant=FULL,
       the ComM module shall request Nm_NetworkRelease().
    */
#if( (COMM_BUSNM_EXSIT_ENABLED == STD_ON) && (COMM_BUSNM_EXIST_FULL_VARIANT == STD_ON) )
    if( COMM_FULL_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant )
    {
        (void)Nm_NetworkRelease(Channel);
    }
#endif

    /* SWS_ComM_00069: On entering state COMM_FULL_COMMUNICATION the ComM channel state machine shall switch on the
       transmission and reception capability. */
    if( (COMM_FULL_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant)
        || (COMM_PASSIVE_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant) )  /* Check NM channel. */
    {
        /* Indicate BusSM. */
        ComM_RequestBusSMMode(Channel, COMM_FULL_COMMUNICATION);
        /* Indicate full communicate state to Dcm. */
        ComM_IndicateDcmChannelState(Channel, COMM_FULL_COMMUNICATION);
    }

    return;
}

/*
********************************************************************************
* Function Name: ComM_TF_NoCom_NetReq
*
* Explanation: Translate to full communicate state.
*
* param: Channel: Channel id.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_TF_NoCom_NetReq(NetworkHandleType Channel)
{
    /* Indicate channel state to BusSM. */
    ComM_RequestBusSMMode(Channel, COMM_FULL_COMMUNICATION);

    switch(ComM_Channel[Channel].ComMNmVariant)
    {
        /* polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        case COMM_NONE_NMTYPEOFCHANNEL:  /* NM state is none. */
            if( COMM_ZERO < ComM_Channel[Channel].ComMMainFunctionPeriod ) /* Set full com timer. */
            {
                ComM_MinFullComModeTimer[Channel] = (COMM_TMINFULLCOMMODEDURATION/ComM_Channel[Channel].ComMMainFunctionPeriod) + COMM_ONE;
            }
            else
            {
                ComM_MinFullComModeTimer[Channel] = COMM_ONE;
            }
            ComM_BusComModeReq[Channel] = COMM_FULL_COM_NETWORK_REQUESTED;  /* Set bus com mode. */
            ComM_IndicateDcmChannelState(Channel, COMM_FULL_COMMUNICATION);  /* Indicate full communicate state to Dcm. */
            break;

        case COMM_LIGHT_NMTYPEOFCHANNEL:
            /* polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule14.3" polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
            if( COMM_ZERO < ComM_Channel[Channel].ComMMainFunctionPeriod ) /* Set full com timer. */
            {
                ComM_MinFullComModeTimer[Channel] = (COMM_TMINFULLCOMMODEDURATION/ComM_Channel[Channel].ComMMainFunctionPeriod) + COMM_ONE;
            /* polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            }
            else
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                ComM_MinFullComModeTimer[Channel] = COMM_ONE;
            }
            ComM_IndicateDcmChannelState(Channel, COMM_FULL_COMMUNICATION);  /* Indicate full communicate state to Dcm. */
            break;

        case COMM_LINSLAVE_NMTYPEOFCHANNEL:
            /* SWS_ComM_01017: If no user request fullcomm,
            BusCom request will be the HighestRequest, hence the following code
            will make the state machine switching to COMM_FULL_COM_READY_SLEEP. */
            ComM_BusComModeReq[Channel] = COMM_FULL_COM_READY_SLEEP;
            /* Indicate full communicate state to Dcm. */
            ComM_IndicateDcmChannelState(Channel, COMM_FULL_COMMUNICATION);
            break;

#if( (COMM_BUSNM_EXSIT_ENABLED == STD_ON) && (COMM_BUSNM_EXIST_FULL_VARIANT == STD_ON) )
        case COMM_FULL_NMTYPEOFCHANNEL:
            ComM_IndicateDcmChannelState(Channel, COMM_FULL_COMMUNICATION);  /* Indicate full communicate state to Dcm. */
            (void)Nm_NetworkRequest(Channel);  /* Indicate NM. */
            break;
#endif  /* (COMM_BUSNM_EXSIT_ENABLED == STD_ON) && (COMM_BUSNM_EXIST_FULL_VARIANT == STD_ON) */

        /* polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        default:
            /* Do nothing. */
            break;
    }
}

/*
********************************************************************************
* Function Name: ComM_TF_NoCom_FullReadySleep
*
* Explanation: Pending or silent translate to ready sleep state.
*
* param: Channel: Channel id.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_TF_NoCom_FullReadySleep(NetworkHandleType Channel)
{
    /* Check NM channel. */
    /* polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_ComM_OBAI" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_ComM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.1" */
    if( (COMM_FULL_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant)
        || (COMM_PASSIVE_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant) )
    {
        /* Indicate CanSM. */
        ComM_RequestBusSMMode(Channel, COMM_FULL_COMMUNICATION);
        /* Indicate full communicate state to Dcm. */
        ComM_IndicateDcmChannelState(Channel, COMM_FULL_COMMUNICATION);

#if( COMM_BUSNM_EXSIT_ENABLED == STD_ON )

#if( COMM_BUSNM_EXIST_FULL_VARIANT == STD_ON )
    if ( COMM_BUS_TYPE_LIN != ComM_Channel[Channel].BusTypeOfChannel )
    {
        (void)Nm_NetworkRelease(Channel);  /* Release Network. */
    }
#endif  /* COMM_BUSNM_EXIST_FULL_VARIANT == STD_ON */

        (void)Nm_PassiveStartUp(Channel);  /* Indicate Nm. */
#endif  /* COMM_BUSNM_EXSIT_ENABLED == STD_ON */
    }
    else if( COMM_LINSLAVE_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant )
    {
        /* Reason: Passively wakeup initiated by EcuM.
           Action: Request COMM_FULL_COMMUNICATION from LinSM only to start the
                   wakeup process of LinIf.
                   temp Channel state = 2 COMM_FULL_COM_NETWORK_REQUESTED
        */
        ComM_RequestBusSMMode(Channel, COMM_FULL_COMMUNICATION);

        /* Reason: Passively wakeup and No user request full com.
           Action: Request COMM_NO_COMMUNICATION from LinSM.
                   Active Channel state = 3 (COMM_FULL_COM_READY_SLEEP).
                   BusComModeReq = 3 (COMM_FULL_COM_READY_SLEEP).
           Note: 1.LinSM stores the request from ComM without further action.
                 2.ComM will change to NetReq if ComMUser or Dcm requests
                   full com. (action ReadyS_NetReq will be executed).
                 3.ComM will change to NO COM if LinSM indicates bus sleep
                   event by calling ComM_BusSM_BusSleepMode.
        */
        ComM_RequestBusSMMode(Channel, COMM_NO_COMMUNICATION);
    }
    else
    {
        /* Do nothing. */
    }
}

/*
********************************************************************************
* Function Name: ComM_TF_ReadyS_NetReq
*
* Explanation: Ready sleep translate to full state.
*
* param: Channel: Channel id.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_TF_ReadyS_NetReq(NetworkHandleType Channel)
{

    /* polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_ComM_OBAI" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_ComM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.1" */
    if( (COMM_NONE_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant) ||
              (COMM_LIGHT_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant) )
    {
        /* polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule14.3" polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
        if( COMM_ZERO < ComM_Channel[Channel].ComMMainFunctionPeriod ) /* Set full com timer. */
        {
            ComM_MinFullComModeTimer[Channel] = (COMM_TMINFULLCOMMODEDURATION/ComM_Channel[Channel].ComMMainFunctionPeriod) + COMM_ONE;
        /* polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        }
        else
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            ComM_MinFullComModeTimer[Channel] = COMM_ONE;
        }
    }
    else if( COMM_LINSLAVE_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant )
    {
        /* Reason : ComM_RequestComMode(<user>, COMM_FULL_COMMUNICATION)
                    or Dcm ActiveDiagnostic.
           Action : ComMChannel state change to COMM_FULL_COM_NETWORK_REQUESTED,
                    and Request COMM_FULL_COMMUNICATION to LinSM. */
        ComM_RequestBusSMMode(Channel, COMM_FULL_COMMUNICATION);
    }
#if( (COMM_BUSNM_EXSIT_ENABLED == STD_ON) && (COMM_BUSNM_EXIST_FULL_VARIANT == STD_ON) )
    else if( COMM_FULL_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant )  /* Check channel with Nm. */
    {
        (void)Nm_NetworkRequest(Channel);  /* Indicate Nm. */
    }
    else
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Nothing */
    }
#endif  /* (COMM_BUSNM_EXSIT_ENABLED == STD_ON) && (COMM_BUSNM_EXIST_FULL_VARIANT == STD_ON) */

    ComM_IndicateDcmChannelState(Channel, COMM_FULL_COMMUNICATION);  /* Indicate full communicate state to Dcm. */
}

/*
************************************************************************************************************************
* Function Name: ComM_TF_ReadyS_NoCom
*
* Explanation: ComM channel state machine transition: COMM_FULL_COM_READY_SLEEP to COMM_NO_COMMUNICATION,
*              due to ComMLightTimeout timer has expired for a ComMNmVariant = LIGHT channel.
*
* Param: Channel: Channel id.
*
* Retval: None
************************************************************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_TF_ReadyS_NoCom(NetworkHandleType Channel)
{
    uint8 UserReqFullComIndex = COMM_ZERO;

#if( COMM_PNCSUPPORT == STD_ON )
    ComM_PncIterType UserReqPncFullIndex = COMM_ZERO;
#endif

    ComM_ActiveComMode[Channel] = COMM_NO_COM_NO_PENDING_REQUEST;  /* Set to no communication. */
    ComM_BusComModeReq[Channel] = COMM_NO_COM_NO_PENDING_REQUEST;  /* Set to no communication. */

    for( UserReqFullComIndex = ComM_ChannelPb[Channel].UserReqFullComStartIdxOfChannelPb;
         UserReqFullComIndex < ComM_ChannelPb[Channel].UserReqFullComEndIdxOfChannelPb; UserReqFullComIndex++ )
    {
        ComM_UserReqFullCom[UserReqFullComIndex] = COMM_NO_REQUESTS;  /* Set no user request. */
    }

#if( COMM_PNCSUPPORT == STD_ON )
    for( UserReqPncFullIndex = ComM_ChannelPb[Channel].PncPbIndStartIdxOfChannelPb;
         UserReqPncFullIndex < ComM_ChannelPb[Channel].PncPbIndEndIdxOfChannelPb; UserReqPncFullIndex++ )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Re-use the variable. It's actually the index of the ComM_UserReqPncFullCom array. */
        UserReqFullComIndex = ComM_PncPbInd[UserReqPncFullIndex];
        ComM_UserReqPncFullCom[UserReqFullComIndex] = COMM_NO_REQUESTS;   /* Set pnc request to default value */
    }
#endif

    ComM_RequestBusSMMode( Channel, COMM_NO_COMMUNICATION );  /* Indicate no communication to BusSM. */
    ComM_IndicateDcmChannelState(Channel, COMM_NO_COMMUNICATION);  /* Indicate no communicate state to Dcm. */
}

/*
********************************************************************************
* Function Name: ComM_ChannelStateTransition
*
* Explanation: ComM state transition.
*
* param: Channel: Channel id.
*        HighestComModeReq: request mode.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_ChannelStateTransition(NetworkHandleType Channel, uint8 HighestComModeReq)
{
    uint8 CalComModeReq;  /* next state */
    do
    {
        if( (COMM_ZERO == ComM_MinFullComModeTimer[Channel]) || (COMM_FULL_COM_NETWORK_REQUESTED != ComM_ActiveComMode[Channel]) )  /* Check timer. */
        {
            CalComModeReq = ComM_TransitionTable[HighestComModeReq][ComM_ActiveComMode[Channel]];
            if( (ComM_ActiveComMode[Channel] < COMM_MAX_NUMBER_OF_STATES) && (CalComModeReq < COMM_MAX_NUMBER_OF_STATES) )
            {
                if( (COMM_NO_COM_REQUEST_PENDING == ComM_ActiveComMode[Channel]) && (CalComModeReq > COMM_NO_COM_REQUEST_PENDING) )
                {
                    /* If the channel is in COMM_NO_COM_REQUEST_PENDING state and there is a pending request to start communication,
                       check the Communication Allowed flag. If Communication Allowed is FALSE, stay in COMM_NO_COM_REQUEST_PENDING state
                       and try again in the next task if request is still pending. */
                    if( (uint8)FALSE == ComM_ComAllowed[Channel] )
                    {
                        /* Because communication is not allowed, here make the HighestComModeReq
                           equals to ComM_ActiveComMode so that the ComM_TransitionFctTable()
                           will not be executed and the channel state stays in
                           COMM_NO_COM_REQUEST_PENDING no matter what the HighestComModeReq is. */
                        /* polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                        HighestComModeReq = ComM_ActiveComMode[Channel];
                    }
                }

                if( HighestComModeReq != ComM_ActiveComMode[Channel] )
                {
                    ComM_TransitionFctTable[CalComModeReq][ComM_ActiveComMode[Channel]](Channel);  /* State translation. */
                    ComM_ActiveComMode[Channel] = CalComModeReq;  /* Set active com mode. */
                }
            }
        }
    /* Complete the request mode transition */
    }while((HighestComModeReq == COMM_FULL_COM_NETWORK_REQUESTED) && (ComM_ActiveComMode[Channel] == COMM_NO_COM_REQUEST_PENDING));

    return;
}

/*
********************************************************************************
* Function Name: ComM_ChannelHandleTimers
*
* Explanation: ComM channel timer handling.
*
* param: Channel: Channel id.
*        InternalRequest: Request mode.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COMM_CODE) ComM_ChannelHandleTimers
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    NetworkHandleType Channel,
    uint8 InternalRequest
)
{

    if( (COMM_LIGHT_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant) ||
            (COMM_NONE_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant) )
    {
        if( ComM_MinFullComModeTimer[Channel] > COMM_ZERO )  /* Full com mode timer. */
        {
            ComM_MinFullComModeTimer[Channel]--;
            if( COMM_ZERO == ComM_MinFullComModeTimer[Channel] )  /* Timer expired, translate to ready sleep mode. */
            {
                ComM_BusComModeReq[Channel] = COMM_FULL_COM_READY_SLEEP;
            }
        }
    }

    if( COMM_LIGHT_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant )
    {
        if( ComM_LightTimer[Channel] > COMM_ZERO )  /* Reay sleep mode timer. */
        {
            ComM_LightTimer[Channel]--;
            if( (uint8)TRUE == InternalRequest )  /* Update timer. */
            {
                ComM_LightTimer[Channel] = COMM_ZERO;
            }

            if( COMM_ZERO == ComM_LightTimer[Channel] )  /* Timer expired, translate to no communication mode. */
            {
                /* SWS_ComM_00610 */
                if( COMM_FULL_COM_READY_SLEEP == ComM_ActiveComMode[Channel] )
                {
                    /* Set bus mode to no communication. */
                    ComM_TF_ReadyS_NoCom(Channel);
                }
            }
        }
    }
    return;
}

#if( COMM_PNCSUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: ComM_HandlePncPrepareSleepTimer
*
* Explanation: ComM pnc channel timer handling.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, COMM_CODE) ComM_HandlePncPrepareSleepTimer(void)
{
    /* For each PNC check the PNC Prepare Sleep Timer. If the timer is started, decrement it. If the timer is expired
       and PNC is not requested, set the bus requested mode to COMM_PNC_NO_COMMUNICATION to allow PNC to enter COMM_PNC_NO_COMMUNICATION. */
    uint8 PsncIndex;

    for( PsncIndex = COMM_ZERO; PsncIndex < COMM_PNC_SIZE; PsncIndex++ )
    {
        if( ComM_PncPSleepTimer[PsncIndex] > COMM_ZERO ) /* PNC state is always COMM_PNC_PREPARE_SLEEP in this case, no need to check it. */
        {
            ComM_PncPSleepTimer[PsncIndex]--;
            if( ((uint8)COMM_PNC_PREPARE_SLEEP == ComM_BusPncComModeReq[PsncIndex]) && (COMM_ZERO == ComM_PncPSleepTimer[PsncIndex]) )
            {
                ComM_BusPncComModeReq[PsncIndex] = (uint8)COMM_PNC_NO_COMMUNICATION;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: ComM_CalculateHighestPNComMode
*
* Explanation: ComM calculate highest pnc com mode.
*
* param: PncIndex: Pnc Index.
*
* retval: HighestRequest: Calculated PNC request mode.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(uint8, COMM_CODE) ComM_CalculateHighestPNComMode(uint8 PncIndex)
{
    uint8 PncPbIndIter;  /* Index of ComM_UserReqPncFullCom. */
    uint8 HighestRequest = (uint8)COMM_PNC_NO_COMMUNICATION;
#if( (COMM_MODELIMITATION == STD_ON) || (COMM_WAKEUPINHIBITIONENABLED == STD_ON) )
    uint8 pncChMappingIndex = COMM_ZERO;
#endif  /* (COMM_MODELIMITATION == STD_ON) || (COMM_WAKEUPINHIBITIONENABLED == STD_ON) */

    /* Loop to find all user requests(stored in ComM_UserReqPncFullCom) of this PNC. */
    for( PncPbIndIter = ComM_PncPb[PncIndex].UserReqPncFullComStartIdxOfPncPb;
         PncPbIndIter < ComM_PncPb[PncIndex].UserReqPncFullComEndIdxOfPncPb; PncPbIndIter++ )
    {
        if( ComM_UserReqPncFullCom[PncPbIndIter] != COMM_NO_REQUESTS )  /* Check pnc request. */
        {
            /* There're user(s) and/or system user requesting this PNC. */
#if( COMM_PNCPASSIVEGWSUPPORT == STD_ON )
            /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
            HighestRequest = COMM_PNC_REQUESTED_PASSIVE;
            if( FALSE == ComM_PncIsOnlySystemUserRequesting(PncIndex, PncPbIndIter) ) /* Check system user request. */
#endif  /* COMM_PNCPASSIVEGWSUPPORT == STD_ON */
            {
                /* This PNC is still requested. */
                /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                HighestRequest = COMM_PNC_REQUESTED;  /* PRQA S 4424 */ /* NSCA_QAC_ComM_Rule10.3*/
                break;
            }
        }
    }

    /*  If Passive Gw Type is supported and PNC activation is received via ERA from an Active channel,
        set the requested mode to COMM_PNC_REQUESTED. */
#if( COMM_PNCPASSIVEGWSUPPORT == STD_ON )
    /* polyspace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.4"*/
    if( COMM_PNC_REQUESTED_PASSIVE == HighestRequest )
    {
        if( TRUE == ComM_PncIsEraReceivedOnActiveChannel(PncIndex) ) /* Check active channel. */
        {
            /* This PNC is requested externally via ERA RX on an active channel. */
            /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
            HighestRequest = COMM_PNC_REQUESTED;
        }
    }
#endif  /* COMM_PNCPASSIVEGWSUPPORT == STD_ON */

#if( (COMM_MODELIMITATION == STD_ON) || (COMM_WAKEUPINHIBITIONENABLED == STD_ON) )
    for( pncChMappingIndex = ComM_PncPb[PncIndex].PncChannelMappingStartIdxOfPncPb;
         pncChMappingIndex < ComM_PncPb[PncIndex].PncChannelMappingEndIdxOfPncPb; pncChMappingIndex++ )
    {
        if( (uint8)TRUE == ComM_ChannelIsLimited(ComM_GetPncChannelMapping(pncChMappingIndex)) )  /* Check inhibit. */
        {
            HighestRequest = (uint8)COMM_PNC_NO_COMMUNICATION;
            break;
        }
    }
#endif  /* (COMM_MODELIMITATION == STD_ON) || (COMM_WAKEUPINHIBITIONENABLED == STD_ON) */

    if( ComM_BusPncComModeReq[PncIndex] > HighestRequest )
    {
        HighestRequest = ComM_BusPncComModeReq[PncIndex];
    }
    else if( (ComM_PncPSleepTimer[PncIndex] > COMM_ZERO) && (HighestRequest <= (uint8)COMM_PNC_PREPARE_SLEEP) )
    {
        /* If HighestRequest is COMM_PNC_NO_COMMUNICATION
           AND ComMPncPrepareSleepTimer is started but not expired yet,
           HighestRequest shall be COMM_PNC_PREPARE_SLEEP. */
        HighestRequest = (uint8)COMM_PNC_PREPARE_SLEEP;
    }
    else
    {
        /* Do nothing. */
    }

    return HighestRequest;
}

/*
********************************************************************************
* Function Name: ComM_PncStateTransition
*
* Explanation: ComM pnc state translation.
*
* param: ComM_CurrentPnc: the given PNC index.
*        HighestComModeReq: Calculated state.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COMM_CODE) ComM_PncStateTransition
(
    uint8 ComM_CurrentPnc,
    uint8 HighestComModeReq
)
{
    if( (ComM_PncPSleepTimer[ComM_CurrentPnc] > COMM_ZERO) && (HighestComModeReq <= (uint8)COMM_PNC_PREPARE_SLEEP) )
    {
        /* If HighestComModeReq is COMM_PNC_NO_COMMUNICATION
           BUT ComMPncPrepareSleepTimer of this PNC has not expired,
           Then force HighestComModeReq to COMM_PNC_PREPARE_SLEEP so that
           the PNC state can stay in PREPARE_SLEEP until the timer expires. */
        /* polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
        HighestComModeReq = (uint8)COMM_PNC_PREPARE_SLEEP;
    }

    /* Do state transition only when requested PNC state dose not equal to the
       current PNC state. */
    if( HighestComModeReq != ComM_ActivePncComMode[ComM_CurrentPnc] )
    {
        switch(ComM_ActivePncComMode[ComM_CurrentPnc])
        {
             /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
             case COMM_PNC_NO_COMMUNICATION:   /* Current PNC state. */  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3*/
                switch(HighestComModeReq)
                {
                    /* COMM_PNC_NO_COMMUNICATION -> COMM_PNC_REQUESTED */
                    /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                    case COMM_PNC_REQUESTED:  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3*/
                        ComM_ActivePncComMode[ComM_CurrentPnc] = (uint8)COMM_PNC_REQUESTED;
#if( COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL == STD_ON )
                        /* Send signal so that BusNM can fetch it and NM message could carry PNC bits. */
                        ComM_PncModeSendSignal(ComM_CurrentPnc, TRUE, COMM_SIG_SEND_ALL);  /* Send signal of pnc mode. */
#endif  /* COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL == STD_ON */
                        /* Indicate current PNC mode to BswM. */
#if( COMM_BSWMENABLED == STD_ON )
                        BswM_ComM_CurrentPNCMode(ComM_Pnc[ComM_CurrentPnc].PncIdOfPnc, COMM_PNC_REQUESTED);
#endif  /* COMM_BSWMENABLED == STD_ON */
                        break;

                    /* COMM_PNC_NO_COMMUNICATION -> COMM_PNC_READY_SLEEP */
                    /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                    case COMM_PNC_READY_SLEEP:  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3*/
                        ComM_ActivePncComMode[ComM_CurrentPnc] = (uint8)COMM_PNC_READY_SLEEP;
#if( COMM_BSWMENABLED == STD_ON )
                        BswM_ComM_CurrentPNCMode(ComM_Pnc[ComM_CurrentPnc].PncIdOfPnc, COMM_PNC_READY_SLEEP);
#endif  /* COMM_BSWMENABLED == STD_ON */
                        break;

                    /* COMM_PNC_NO_COMMUNICATION -> COMM_PNC_PREPARE_SLEEP */
                    /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                    case COMM_PNC_PREPARE_SLEEP:  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3*/
                        ComM_ActivePncComMode[ComM_CurrentPnc] = (uint8)COMM_PNC_PREPARE_SLEEP;
                        /* SWS_ComM_00952 Start ComMPncPrepareSleepTimer. */
                        ComM_PncPSleepTimer[ComM_CurrentPnc] = COMM_PNC_PS_TIMER;
#if( COMM_BSWMENABLED == STD_ON )
                        BswM_ComM_CurrentPNCMode(ComM_Pnc[ComM_CurrentPnc].PncIdOfPnc, COMM_PNC_PREPARE_SLEEP);
#endif  /* COMM_BSWMENABLED == STD_ON */
                        break;

#if( COMM_PNCPASSIVEGWSUPPORT == STD_ON )
                    /* COMM_PNC_NO_COMMUNICATION -> COMM_PNC_REQUESTED_PASSIVE */
                    /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                    case COMM_PNC_REQUESTED_PASSIVE:  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3*/
                        /* Send PNC requested signal only to active channels. */
                        ComM_PncModeSendSignal(ComM_CurrentPnc, TRUE, COMM_SIG_SEND_ACTIVE);  /* Send signal of pnc mode. */
                        /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                        ComM_ActivePncComMode[ComM_CurrentPnc] = COMM_PNC_REQUESTED_PASSIVE;  /* Set pnc mode. */
#if( COMM_BSWMENABLED == STD_ON )
                        BswM_ComM_CurrentPNCMode(ComM_Pnc[ComM_CurrentPnc].PncIdOfPnc, COMM_PNC_REQUESTED);  /* Indicate BswM of pnc mode. */
#endif  /* COMM_BSWMENABLED == STD_ON */
                        break;
#endif  /* COMM_PNCPASSIVEGWSUPPORT == STD_ON */
                    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    default:
                        /* Do nothing. */
                        break;
                }

                break;
             /* End of handling from COMM_PNC_NO_COMMUNICATION to new state. */

             /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
             case COMM_PNC_PREPARE_SLEEP:  /* Current PNC state. */  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3*/
                switch(HighestComModeReq)
                {
                    /* COMM_PNC_PREPARE_SLEEP -> COMM_PNC_REQUESTED */
                    /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                    case COMM_PNC_REQUESTED:  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3*/
#if( COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL == STD_ON )
                        /* Send signal to all channels of this PNC. */
                        ComM_PncModeSendSignal(ComM_CurrentPnc, TRUE, COMM_SIG_SEND_ALL);
#endif  /* COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL == STD_ON */
                        ComM_PncPSleepTimer[ComM_CurrentPnc] =  COMM_ZERO;
                        ComM_ActivePncComMode[ComM_CurrentPnc] = (uint8)COMM_PNC_REQUESTED;
#if( COMM_BSWMENABLED == STD_ON )
                        BswM_ComM_CurrentPNCMode(ComM_Pnc[ComM_CurrentPnc].PncIdOfPnc, COMM_PNC_REQUESTED);
#endif  /* COMM_BSWMENABLED == STD_ON */
                        break;

#if( COMM_PNCPASSIVEGWSUPPORT == STD_ON )
                        /* COMM_PNC_PREPARE_SLEEP -> COMM_PNC_REQUESTED_PASSIVE */
                    /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                    case COMM_PNC_REQUESTED_PASSIVE:  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3*/
                        /* PNC is requested externally, route request to active channels of this PNC only. */
                        ComM_PncModeSendSignal(ComM_CurrentPnc, TRUE, COMM_SIG_SEND_ACTIVE);  /* Send signal of pnc mode. */
                        /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                        ComM_ActivePncComMode[ComM_CurrentPnc] = COMM_PNC_REQUESTED_PASSIVE; /* SBSW_COMM_PNC_CSL02 */
#if( COMM_BSWMENABLED == STD_ON )
                        BswM_ComM_CurrentPNCMode(ComM_Pnc[ComM_CurrentPnc].PncIdOfPnc, COMM_PNC_REQUESTED);  /* Indicate BswM of pnc mode. */
#endif  /* COMM_BSWMENABLED == STD_ON */
                        break;
#endif  /* COMM_PNCPASSIVEGWSUPPORT == STD_ON */

                    /* COMM_PNC_PREPARE_SLEEP -> COMM_PNC_READY_SLEEP */
                    /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                    case COMM_PNC_READY_SLEEP:  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3*/
                        ComM_PncPSleepTimer[ComM_CurrentPnc] = COMM_ZERO;
                        ComM_ActivePncComMode[ComM_CurrentPnc] = (uint8)COMM_PNC_READY_SLEEP;
#if( COMM_BSWMENABLED == STD_ON )
                        BswM_ComM_CurrentPNCMode(ComM_Pnc[ComM_CurrentPnc].PncIdOfPnc, COMM_PNC_READY_SLEEP);
#endif  /* COMM_BSWMENABLED == STD_ON */
                        break;

                    /* COMM_PNC_PREPARE_SLEEP -> COMM_PNC_NO_COMMUNICATION */
                    /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                    case COMM_PNC_NO_COMMUNICATION:  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3*/
                        ComM_PncPSleepTimer[ComM_CurrentPnc] = COMM_ZERO;
                        ComM_ActivePncComMode[ComM_CurrentPnc] = (uint8)COMM_PNC_NO_COMMUNICATION;
#if( COMM_BSWMENABLED == STD_ON )
                        BswM_ComM_CurrentPNCMode(ComM_Pnc[ComM_CurrentPnc].PncIdOfPnc, COMM_PNC_NO_COMMUNICATION);
#endif  /* COMM_BSWMENABLED == STD_ON */
                        break;

                    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    default:
                        /* Do nothing. */
                        break;
                }
                /* Leave COMM_PNC_PREPARE_SLEEP shall stop the ComMPncPrepareSleepTimer. */
                ComM_PncPSleepTimer[ComM_CurrentPnc] = COMM_ZERO;  /* Stop pnc prepare sleep timer. */

#if( COMM_SYNCHRONOUSWAKEUP == STD_ON )
                /* polyspace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.4" */
                if( COMM_PNC_PREPARE_SLEEP == ComM_BusPncComModeReq[ComM_CurrentPnc] )
                {
                    /* Synchronous wakeup is processed, so clear the request. */
                    /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                    ComM_BusPncComModeReq[ComM_CurrentPnc] = COMM_PNC_NO_COMMUNICATION;  /* Set pnc requested mode. */
                }
#endif  /* COMM_SYNCHRONOUSWAKEUP == STD_ON */
                break;
             /* End of handling from COMM_PNC_PREPARE_SLEEP to new state. */

             /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
             case COMM_PNC_READY_SLEEP:  /* Current PNC state. */  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3*/
                switch(HighestComModeReq)
                {
                    /* COMM_PNC_READY_SLEEP -> COMM_PNC_REQUESTED */
                    /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                    case COMM_PNC_REQUESTED:  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3*/
#if( COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL == STD_ON )
                        /* Send signal to all channels of this PNC. */
                        ComM_PncModeSendSignal(ComM_CurrentPnc, TRUE, COMM_SIG_SEND_ALL);  /* Send signal of pnc mode. */
#endif  /* COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL == STD_ON */

                        ComM_ActivePncComMode[ComM_CurrentPnc] = (uint8)COMM_PNC_REQUESTED;
#if( COMM_BSWMENABLED == STD_ON )
                        BswM_ComM_CurrentPNCMode(ComM_Pnc[ComM_CurrentPnc].PncIdOfPnc, COMM_PNC_REQUESTED);
#endif  /* COMM_BSWMENABLED == STD_ON */
                        break;

#if( COMM_PNCPASSIVEGWSUPPORT == STD_ON )
                    /* COMM_PNC_READY_SLEEP -> COMM_PNC_REQUESTED_PASSIVE */
                    /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                    case COMM_PNC_REQUESTED_PASSIVE:  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3*/
                        /* Route PNC request to active channels only. */
                        ComM_PncModeSendSignal(ComM_CurrentPnc, TRUE, COMM_SIG_SEND_ACTIVE);  /* Send signal of pnc mode. */
                        /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                        ComM_ActivePncComMode[ComM_CurrentPnc] = COMM_PNC_REQUESTED_PASSIVE;  /* Set pnc mode. */
#if( COMM_BSWMENABLED == STD_ON )
                        BswM_ComM_CurrentPNCMode(ComM_Pnc[ComM_CurrentPnc].PncIdOfPnc, COMM_PNC_REQUESTED);  /* Indicate BswM of pnc mode. */
#endif  /* COMM_BSWMENABLED == STD_ON */
                        break;
#endif  /* COMM_PNCPASSIVEGWSUPPORT == STD_ON */
                    /* COMM_PNC_READY_SLEEP -> COMM_PNC_NO_COMMUNICATION */
                    /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                    case COMM_PNC_NO_COMMUNICATION:  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3*/
                        ComM_ActivePncComMode[ComM_CurrentPnc] = (uint8)COMM_PNC_PREPARE_SLEEP;
                        /* SWS_ComM_00952 Start ComMPncPrepareSleepTimer. */
                        ComM_PncPSleepTimer[ComM_CurrentPnc] = COMM_PNC_PS_TIMER;
#if( COMM_BSWMENABLED == STD_ON )
                        BswM_ComM_CurrentPNCMode(ComM_Pnc[ComM_CurrentPnc].PncIdOfPnc, COMM_PNC_PREPARE_SLEEP);
#endif  /* COMM_BSWMENABLED == STD_ON */
                        break;

                    default:
                        /* Do nothing. */
                        break;
                }
                break;
             /* End of handling from COMM_PNC_READY_SLEEP to new state. */

             /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
             case COMM_PNC_REQUESTED:  /* Current PNC state. */  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3*/
#if( COMM_PNCPASSIVEGWSUPPORT == STD_ON )
                /* polyspace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.4" */
                if( COMM_PNC_REQUESTED_PASSIVE == HighestComModeReq )
                {
                    /* Route PNC request to passive channels only. */
                    ComM_PncModeSendSignal(ComM_CurrentPnc, FALSE, COMM_SIG_SEND_PASSIVE);  /* Send signal of pnc mode. */
                    /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                    ComM_ActivePncComMode[ComM_CurrentPnc] = COMM_PNC_REQUESTED_PASSIVE;  /* Set pnc mode. */
                }
                else
#endif  /* COMM_PNCPASSIVEGWSUPPORT == STD_ON */
                {
                    /* COMM_PNC_REQUESTED -> COMM_PNC_READY_SLEEP */
#if( COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL == STD_ON )
                    /* Send signal to all channels of this PNC. */
                    ComM_PncModeSendSignal(ComM_CurrentPnc, FALSE, COMM_SIG_SEND_ALL);  /* Send signal of pnc mode. */
#endif  /* COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL == STD_ON */
                    ComM_ActivePncComMode[ComM_CurrentPnc] = (uint8)COMM_PNC_READY_SLEEP;
#if( COMM_BSWMENABLED == STD_ON )
                    BswM_ComM_CurrentPNCMode(ComM_Pnc[ComM_CurrentPnc].PncIdOfPnc, COMM_PNC_READY_SLEEP);
#endif  /* COMM_BSWMENABLED == STD_ON */
                }
                break;
             /* End of handling from COMM_PNC_REQUESTED to new state. */

#if( COMM_PNCPASSIVEGWSUPPORT == STD_ON )
             /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
             case COMM_PNC_REQUESTED_PASSIVE:  /* Current PNC state. */  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3*/
                switch ( HighestComModeReq )
                {
                    /* COMM_PNC_REQUESTED_PASSIVE -> COMM_PNC_REQUESTED */
                    /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                    case COMM_PNC_REQUESTED:  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3*/
                        /* Route PNC request to passive channels only. */
                        ComM_PncModeSendSignal(ComM_CurrentPnc, TRUE, COMM_SIG_SEND_PASSIVE);  /* Send signal of pnc mode. */
                        /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                        ComM_ActivePncComMode[ComM_CurrentPnc] = COMM_PNC_REQUESTED_PASSIVE;  /* Set pnc mode. */
                        break;

                    /* COMM_PNC_REQUESTED_PASSIVE -> COMM_PNC_REQUESTED -> COMM_PNC_READY_SLEEP  */
                    default:
                        /* Route PNC request to active channels only. */
                        ComM_PncModeSendSignal(ComM_CurrentPnc, FALSE, COMM_SIG_SEND_ACTIVE);  /* Send signal of pnc mode. */
                        /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
                        ComM_ActivePncComMode[ComM_CurrentPnc] = COMM_PNC_REQUESTED;  /* Set pnc mode. */
#if( COMM_BSWMENABLED == STD_ON )
                        BswM_ComM_CurrentPNCMode(ComM_Pnc[ComM_CurrentPnc].PncIdOfPnc, COMM_PNC_REQUESTED);  /* Indicate BswM of pnc mode. */
#endif  /* COMM_BSWMENABLED == STD_ON */
                        break;
                }
                break;
             /* End of handling from COMM_PNC_REQUESTED_PASSIVE to new state. */
#endif  /* COMM_PNCPASSIVEGWSUPPORT == STD_ON */

             /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
             default:
                /* Do nothing. */
                break;
        }
        /* End of switch(ComM_ActivePncComMode[ComM_CurrentPnc]). */
    }
    /* End of judge HighestComModeReq != ComM_ActivePncComMode[ComM_CurrentPnc]. */
}

/*
********************************************************************************
* Function Name: ComM_PncModeArbitration
*
* Explanation: ComM pnc state translation per channel.
*
* param: Channel: Channel id.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_PncModeArbitration(NetworkHandleType Channel)
{
    uint8 PncChIndex;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 PncIndex;
    uint8 HighestComModeReq = (uint8)COMM_PNC_NO_COMMUNICATION;

#if( COMM_PNCACTIVECOORD == STD_ON )
    /* COMM_PNCACTIVECOORD = STD_ON is not supported yet. */
    uint8 pncChIndex = COMM_ZERO;
    boolean coordChInFull = TRUE;
#endif  /* COMM_PNCACTIVECOORD == STD_ON */
    /* Loop for all related PNC on this Channel. */
    for( PncChIndex = ComM_ChannelPb[Channel].PncPbIndStartIdxOfChannelPb;
       PncChIndex < ComM_ChannelPb[Channel].PncPbIndEndIdxOfChannelPb; PncChIndex++ )
    {
        /* Get the index of PNC that're running over this Channel. */
        PncIndex = ComM_PncPbInd[PncChIndex];

#if( COMM_PNCACTIVECOORD == STD_ON )
        /* COMM_PNCACTIVECOORD = STD_ON is not supported. */
        for( pncChIndex = ComM_PncPb[PncIndex].PncChannelMappingStartIdxOfPncPb;
             pncChIndex < ComM_PncPb[PncIndex].PncChannelMappingEndIdxOfPncPb;
             pncChIndex++ )
        {   /* Check if the active mode is COMM_FULL_COMMUNICATION */
            if( COMM_ZERO == (ComM_ActiveComMode[ComM_PncChannelMapping[pncChIndex]] & COMM_FULL_COMMUNICATION) )
            {
                coordChInFull= FALSE;
            }
        }

        if( TRUE == coordChInFull )
#endif  /* COMM_PNCACTIVECOORD == STD_ON */

        {
            /* Calculate pnc com mode. */
            HighestComModeReq = ComM_CalculateHighestPNComMode(PncIndex);
        }

        /* Do PNC state transition if the highest request does not equal to
           the current PNC state. */
        if( HighestComModeReq != ComM_ActivePncComMode[PncIndex] )
        {
            ComM_PncStateTransition(PncIndex, HighestComModeReq);  /* ComM pnc state transition. */
        }
    }
}

#if( COMM_PNCPASSIVEGWSUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: ComM_PncIsOnlySystemUserRequesting
*
* Explanation: Check if only system user request the pnc.
*
* param: pncIndex: PNC Index.
*        byteIndex: UserReqPncFullCom Index.
*
* retval: TRUE: The system user is the only ComMUser who's requesting the PNC.
*         FALSE: 1. The PNC is not a coordinated PNC, or
*                2. There're ComMUser(s) requesting the given PNC, or
*                3. The given byteIndex of ComM_UserReqPncFullCom does not
*                   contain the system user's request.
********************************************************************************
*/
static FUNC(boolean, COMM_CODE) ComM_PncIsOnlySystemUserRequesting
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    VAR(ComM_PncIterType, AUTOMATIC) pncIndex,
    VAR(uint32, AUTOMATIC) byteIndex
)
{
    boolean retValue = FALSE;
    uint8 sysUserByteMaskIndex = COMM_ZERO;

    /* If a PNC overlays multiple channels, then it's a coordinated PNC. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( TRUE == ComM_Pnc[pncIndex].CoordinatedOfPnc )
    {
        /* Get this PNC's system user: ComM_Pnc[pncIndex].SystemUserOfPnc, then
           use it to get the index of ComM_UserPncByteMask, finally use the indexed
           item of ComM_UserPncByteMask to index the ComM_UserReqPncFullCom.
           In ComM_UserPncByteMask contains this PNC's system user request status. */
        sysUserByteMaskIndex = ComM_User[ComM_Pnc[pncIndex].SystemUserOfPnc].UserPncByteMaskStartIdxOfUser;

        /* byteIndex is the index of ComM_UserReqPncFullCom which is being checked:
           Check if this byte is the system user's byte. */
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if( byteIndex == ComM_UserPncByteMask[sysUserByteMaskIndex].UserReqPncFullComIdxOfUserPncByteMask )
        {
            /* Check the system user's request status. */
            if( (COMM_NO_REQUESTS == (ComM_UserReqPncFullCom[byteIndex] & ComM_GetClearMaskOfUserPncByteMask(sysUserByteMaskIndex))) )
            {
                /* Other bits in ComM_UserReqPncFullCom are 0 which means
                   no user request on this PNC other than the system user's. */
                retValue = TRUE;
            }
        }
    }

    return retValue;
}

/*
********************************************************************************
* Function Name: ComM_PncIsEraReceivedOnActiveChannel
*
* Explanation: Check if a given PNC is requested via ERA RX on an active channel.
*
* param: pncIndex: PNC Index.
*
* retval: TRUE: If at least one PNC request is received via ERA RX on a channel
*               with GW type ACTIVE.
*         FALSE: Otherwise return FALSE.
********************************************************************************
*/
static FUNC(boolean, COMM_CODE) ComM_PncIsEraReceivedOnActiveChannel
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    VAR(ComM_PncIterType, AUTOMATIC) pncIndex
)
{
    uint8 pncSignalIndIter;
    uint8 pncSignalInd;
    boolean retValue = FALSE;  /* By default, assuming no PNC request on active channel. */

    /* Return TRUE if at least one PNC request is received via ERA on a channel
       with GW type ACTIVE. Otherwise return FALSE. */
    for (pncSignalIndIter = ComM_PncPb[pncIndex].PncSignalIndStartIdxOfPncPb;
         pncSignalIndIter < ComM_PncPb[pncIndex].PncSignalIndEndIdxOfPncPb;
         pncSignalIndIter++)
    {
        pncSignalInd = ComM_GetPncSignalInd(pncSignalIndIter);
        /* Check only ERA RX signal which stands for external request on the PNC. */
        if( COMM_ERA_RX_TYPEOFPNCSIGNAL == ComM_PncSignal[pncSignalInd].TypeOfPncSignal )
        {
            /* Check ERA RX signal received on the active channel and the PNC bit is set. */
            if( (COMM_GATEWAY_TYPE_ACTIVE == ComM_Channel[ComM_PncSignal[pncSignalInd].ChannelIdxOfPncSignal].ComMPncGatewayType ) &&
                /* polyspace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.4" */
                (TRUE == ComM_IsSignalPncBitSet(pncSignalInd, pncIndex)) )
            {
                retValue = TRUE;
                break;
            }
        }
    }

    return retValue;
}
#endif  /* COMM_PNCPASSIVEGWSUPPORT == STD_ON */

#endif  /* COMM_PNCSUPPORT == STD_ON */

#if( (COMM_MODELIMITATION == STD_ON) || (COMM_WAKEUPINHIBITIONENABLED == STD_ON) )
/*
********************************************************************************
* Function Name: ComM_ChannelIsLimited
*
* Explanation: Check ComM channel limit state.
*
* param: channel: Channel id.
*
* retval: TRUE: Mode Limitation or Prevent Wake-up is active on the channel.
*         FALSE: Mode Limitation or Prevent Wake-up is inactive on the channel.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(boolean, COMM_CODE) ComM_ChannelIsLimited(NetworkHandleType channel)
{
    boolean lResult = FALSE;

    /* Return TRUE if Mode Limitation or Prevent Wake-up is active on the channel.
       Otherwise return FALSE. */
    if(
#if( COMM_MODELIMITATION == STD_ON )
    ((uint8)TRUE == ComM_NoComLimitationActive(channel))  /* No com limit active. */
#if( COMM_WAKEUPINHIBITIONENABLED == STD_ON )
    ||
#endif  /* COMM_WAKEUPINHIBITIONENABLED == STD_ON */
#endif  /* COMM_MODELIMITATION == STD_ON */
#if( COMM_WAKEUPINHIBITIONENABLED == STD_ON )
    ((uint8)TRUE == ComM_PreventWakeUpActive(channel))  /* Prevent wake up active. */
#endif  /* COMM_WAKEUPINHIBITIONENABLED == STD_ON */
    )
    {
        lResult = TRUE;
    }

    return lResult;
}

/*
********************************************************************************
* Function Name: ComM_NoComLimitationActive
*
* Explanation: Check no com limit active.
*
* param: channel: Channel id.
*
* retval: TRUE: NoCom limitation is active.
*         FALSE: NoCom limitation is inactive.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(boolean, COMM_CODE) ComM_NoComLimitationActive(NetworkHandleType channel)
{
    boolean lResult = FALSE;

    /* Check group classification. */
    if( COMM_MODE_LIMITATION_MASK == (ComM_Inhibition.ComM_ECUGroupClassification & COMM_MODE_LIMITATION_MASK) )
    {
        /* Check mode limitation mask. */
        if( COMM_MODE_LIMITATION_MASK == (ComM_Inhibition.ComM_InhibitionStatus[channel] & COMM_MODE_LIMITATION_MASK) )
        {
            lResult = TRUE;
        }
    }

    return lResult;
}

/*
********************************************************************************
* Function Name: ComM_PreventWakeUpActive
*
* Explanation: Check prevent wake up active.
*
* param: channel: Channel id.
*
* retval: TRUE: PreventWakeUp is active.
*         FALSE: PreventWakeUp is inactive.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(boolean, COMM_CODE) ComM_PreventWakeUpActive(NetworkHandleType channel)
{
    boolean lResult = FALSE;

  /* Return TRUE if Prevent Wake-up
   *     1) is allowed by ECU Group Classification and
   *     2) is active on the channel and
   *     3) the channel is not in FULL_COM mode.
   */
    if( COMM_WAKEUP_INHIBITION_MASK == (ComM_Inhibition.ComM_ECUGroupClassification & COMM_WAKEUP_INHIBITION_MASK) )
    {
        /* check if prevent wake up is active. */
        if( COMM_WAKEUP_INHIBITION_MASK == (ComM_Inhibition.ComM_InhibitionStatus[channel] & COMM_WAKEUP_INHIBITION_MASK) )
        {
            if( COMM_ZERO == (ComM_ActiveComMode[channel] & COMM_FULL_COMMUNICATION) )
            {
                /* The inhibition shall not get active in FULL_COM mode. */
                lResult = TRUE;
            }
        }
    }

    return lResult;
}
#endif  /* (COMM_MODELIMITATION == STD_ON) || (COMM_WAKEUPINHIBITIONENABLED == STD_ON) */

/*
********************************************************************************
* Function Name:   ComM_RequestComMode
*
* Explanation: Requesting of a Communication Mode by a user.(Synchronous & Reentrant)
*
* param: User: Handle of the user who requests a mode.
*        ComMode: COMM_FULL_COMMUNICATION   COMM_NO_COMMUNICATION.
*
* retval: E_OK: Successfully changed to the new mode.
*         E_NOT_OK: Changing to the new mode failed.
*         COMM_E_MODE_LIMITATION: Mode can not be granted because of mode inhibition.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, COMM_CODE) ComM_RequestComMode
(
    ComM_UserHandleType User,
    ComM_ModeType ComMode
)
{
    uint8 IByteMaskIndex;
    uint8 UserReqFullCom;
    Std_ReturnType lResult;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( ComM_InitStatus != COMM_INIT )  /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
        lResult = COMM_E_NOT_OK;
    }
    else if( User >= COMM_USER_SIZE )  /* Check user id. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
        lResult = COMM_E_NOT_OK;
    }
    else if( (ComMode != COMM_NO_COMMUNICATION) && (ComMode != COMM_FULL_COMMUNICATION) )  /* Check parameter. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
        lResult = COMM_E_NOT_OK;
    }
    else
    {
        lResult = COMM_E_OK;
        if( COMM_NO_COMMUNICATION == ComMode )  /* ComM mode is no comunication. */
        {
            for( IByteMaskIndex = ComM_User[User].UserByteMaskStartIdxOfUser;
                IByteMaskIndex < ComM_User[User].UserByteMaskEndIdxOfUser; IByteMaskIndex++ )  /* Clear user request. */
            {
                UserReqFullCom = ComM_UserReqFullCom[ComM_UserByteMask[IByteMaskIndex].UserReqFullComIdxOfUserByteMask]
                    & ComM_UserByteMask[IByteMaskIndex].ClearMaskOfUserByteMask;

                ComM_UserReqFullCom[ComM_UserByteMask[IByteMaskIndex].UserReqFullComIdxOfUserByteMask] = UserReqFullCom;
            }

#if( COMM_PNCSUPPORT == STD_ON )
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if( (uint8)TRUE == ComM_User[User].PncUserOfUser )  /* Check pnc user. */
            {
                for( IByteMaskIndex = ComM_User[User].UserPncByteMaskStartIdxOfUser;
                IByteMaskIndex < ComM_User[User].UserPncByteMaskEndIdxOfUser; IByteMaskIndex++ )  /* Clear pnc user request. */
                {
                    UserReqFullCom = ComM_UserReqPncFullCom[ComM_UserPncByteMask[IByteMaskIndex].UserReqPncFullComIdxOfUserPncByteMask]
                        & ComM_GetClearMaskOfUserPncByteMask(IByteMaskIndex);

                    ComM_UserReqPncFullCom[ComM_UserPncByteMask[IByteMaskIndex].UserReqPncFullComIdxOfUserPncByteMask] = UserReqFullCom;
                }
            }
#endif  /* COMM_PNCSUPPORT == STD_ON */
        }
        else  /* ComM mode is full comunication. */
        {
            for( IByteMaskIndex = ComM_User[User].UserByteMaskStartIdxOfUser;
                        IByteMaskIndex < ComM_User[User].UserByteMaskEndIdxOfUser; IByteMaskIndex++ )
            {
                UserReqFullCom = (ComM_UserReqFullCom[ComM_UserByteMask[IByteMaskIndex].UserReqFullComIdxOfUserByteMask]
                    | ComM_UserByteMask[IByteMaskIndex].SetMaskOfUserByteMask);
                /* Set Full Com request bits into ComM_UserReqFullCom. */
                ComM_UserReqFullCom[ComM_UserByteMask[IByteMaskIndex].UserReqFullComIdxOfUserByteMask] = UserReqFullCom;
#if( (COMM_MODELIMITATION == STD_ON) || (COMM_WAKEUPINHIBITIONENABLED == STD_ON) )
                if( (uint8)TRUE == ComM_ChannelIsLimited(ComM_UserByteMask[IByteMaskIndex].ChannelOfUserByteMask) )  /* Check channel limit. */
                {
                    lResult = COMM_E_MODE_LIMITATION;
                }
#endif  /* (COMM_MODELIMITATION == STD_ON) || (COMM_WAKEUPINHIBITIONENABLED == STD_ON) */
            }

#if( COMM_PNCSUPPORT == STD_ON )
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if( (uint8)TRUE == ComM_User[User].PncUserOfUser )  /* Check pnc request. */
            {
              for( IByteMaskIndex = ComM_User[User].UserPncByteMaskStartIdxOfUser;
                    IByteMaskIndex < ComM_User[User].UserPncByteMaskEndIdxOfUser; IByteMaskIndex++ )
              {
                UserReqFullCom = (ComM_UserReqPncFullCom[ComM_UserPncByteMask[IByteMaskIndex].UserReqPncFullComIdxOfUserPncByteMask]
                    | ComM_GetSetMaskOfUserPncByteMask(IByteMaskIndex));
                ComM_UserReqPncFullCom[ComM_UserPncByteMask[IByteMaskIndex].UserReqPncFullComIdxOfUserPncByteMask] = UserReqFullCom;
              }
            }
#endif  /* COMM_PNCSUPPORT == STD_ON */
        }

#if( (COMM_MODELIMITATION == STD_ON) || (COMM_WAKEUPINHIBITIONENABLED == STD_ON) )
        if( COMM_E_MODE_LIMITATION == lResult )
        {
            if( ComM_Inhibition.ComM_InhibitCnt < COMM_INHIBITCNT_MAX )  /* Updata inhibit counter. */
            {
                ComM_Inhibition.ComM_InhibitCnt++;
            }
        }
#endif  /* (COMM_MODELIMITATION == STD_ON) || (COMM_WAKEUPINHIBITIONENABLED == STD_ON) */

    }

    ComM_Det_ErrorReport(COMM_SID_REQUESTCOMMODE, errorId);  /* Det report. */

    return lResult;
}

/*
********************************************************************************
* Function Name: ComM_CommunicationAllowed
*
* Explanation: EcuM or BswM shall indicate to ComM when communication is allowed.(Synchronous & Non Reentrant)
*
* param: Channel: Channel id.
*        Allowed: TRUE: Communication is allowed.
*                 FALSE: Communication is not allowed.
*
* retval: None
********************************************************************************
*/
FUNC(void, COMM_CODE) ComM_CommunicationAllowed
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    NetworkHandleType Channel,
    boolean Allowed
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( ComM_InitStatus != COMM_INIT )  /* Check init state.*/
    {
        errorId = COMM_E_NOT_INITED;
    }
    else if( Channel >= COMM_ACTIVE_CHANNEL )  /* Check channel id. */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
    }
    else
    {
        ComM_ComAllowed[Channel] = Allowed;  /* Set allowed state. */
    }

    ComM_Det_ErrorReport(COMM_SID_COMMUNICATIONALLOWED, errorId);  /* Det report. */
}

/*
********************************************************************************
* Function Name: ComM_MainFunction
*
* Explanation: This function shall perform the processing of the AUTOSAR ComM activities that
*            are not directly initiated by the calls e.g. from the RTE. There shall be one
*            dedicated Main Function for each channel of ComM.
*
* param: Channel: Channel id.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
FUNC(void, COMM_CODE) ComM_MainFunction(NetworkHandleType Channel)
{
    uint8 HighestComModeReq;
    uint8 InternalRequest;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( ComM_InitStatus != COMM_INIT )  /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
    }
    else if( Channel >= COMM_ACTIVE_CHANNEL )  /* Check channel id. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
    }
    else
    {
        /* Initial value of InternalRequest is irrelevant.
           If InternalRequest exists, ComM_LightTimer will be cleared. */
        HighestComModeReq = ComM_CalculateHighestComMode(Channel, &InternalRequest);  /*Calculate highest request mode. */
        ComM_ChannelStateTransition(Channel, HighestComModeReq);  /* ComM channel state transition. */
        ComM_ChannelHandleTimers(Channel, InternalRequest);  /* Timer process. */

#if( COMM_PNCSUPPORT == STD_ON )
        if( COMM_ZERO == Channel )
        {
            ComM_HandlePncPrepareSleepTimer();  /* Pnc timer process,calculate timeout only in channel 0. */
        }
        ComM_PncModeArbitration(Channel);  /* Pnc state transition. */
#endif  /* COMM_PNCSUPPORT == STD_ON */
    }
    ComM_Det_ErrorReport(COMM_SID_MAINFUNCTION, errorId);  /* Det report. */
}

/*
********************************************************************************
* Function Name:   ComM_Init
*
* Explanation: Initializes the AUTOSAR Communication Manager and restarts the internal state
*            machines.(Synchronous& Non Reentrant)
*
* param: ConfigPtr: Pointer to post-build configuration data.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
FUNC(void, COMM_CODE) ComM_Init
(
    P2CONST(ComM_ConfigType, AUTOMATIC, COMM_APPL_CONST) ConfigPtr
)
{
    uint8 ComM_ChannelIndex;
    uint8 ComM_ByteIndex;

    COMM_DUMMY_STATEMENT(ConfigPtr);

    if( COMM_INIT == ComM_InitStatus )  /* Check reinit state. */
    {
        ComM_Det_ErrorReport(COMM_SID_INIT, COMM_E_INIT_FAILED);
    }
    else
    {
        ComM_Inhibition.ComM_ECUGroupClassification = COMM_ECUGROUPCLASSIFICATION;  /* Set inhibit default value. */
        ComM_Inhibition.ComM_InhibitCnt = COMM_ZERO;

        /* Clear request and timer. */
        for( ComM_ChannelIndex = COMM_ZERO; ComM_ChannelIndex < COMM_ACTIVE_CHANNEL; ComM_ChannelIndex++ )
        {
            ComM_BusComModeReq[ComM_ChannelIndex] = COMM_NO_COM_NO_PENDING_REQUEST;
            ComM_ActiveComMode[ComM_ChannelIndex] = COMM_NO_COM_NO_PENDING_REQUEST;
            ComM_MinFullComModeTimer[ComM_ChannelIndex] =  COMM_ZERO;
            ComM_LightTimer[ComM_ChannelIndex] = COMM_ZERO;
            ComM_ComAllowed[ComM_ChannelIndex] = FALSE;
#if( COMM_DCM_REQUEST_ENABLED == STD_ON )
            /* If COMM_DCM_REQUEST_ENABLED is STD_OFF,
               ComM_DcmRequestActive is not declared. */
            ComM_DcmRequestActive[ComM_ChannelIndex] = FALSE;
#endif  /* COMM_DCM_REQUEST_ENABLED == STD_ON */
            ComM_Inhibition.ComM_InhibitionStatus[ComM_ChannelIndex] = COMM_ZERO;
            /* polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule14.3" polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
            if( TRUE == ComM_Channel[ComM_ChannelIndex].ComMNoWakeup )
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                ComM_Inhibition.ComM_InhibitionStatus[ComM_ChannelIndex] |= COMM_WAKEUP_INHIBITION_MASK;
            }
            /* polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule14.3" polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
            if( TRUE == ComM_Channel[ComM_ChannelIndex].ComMNoCom )
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                ComM_Inhibition.ComM_InhibitionStatus[ComM_ChannelIndex] |= COMM_MODE_LIMITATION_MASK;
            }
        }
        /* Clear bus request. */
        for( ComM_ByteIndex = COMM_ZERO; ComM_ByteIndex < COMM_SIZE_OF_USER_REQ_FULL_COM; ComM_ByteIndex++ )
        {
            ComM_UserReqFullCom[ComM_ByteIndex] = COMM_NO_REQUESTS;
        }
        /* Pnc init. */
#if( COMM_PNCSUPPORT == STD_ON )
        ComM_PncInit();
#endif  /* COMM_PNCSUPPORT == STD_ON */
        ComM_InitStatus = COMM_INIT;  /* Init completed. */
    }

    return;
}

#if( COMM_PNCSUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: ComM_PncClearBitInSignal
*
* Explanation: Clear Pnc bit signal.
*
* param: InternalSignalId: Rx or Tx index.
*        InternalPncId: Pnc signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COMM_CODE) ComM_PncClearBitInSignal
(
    ComM_SizeOfPncSignalType InternalSignalId,
    ComM_PncIterType InternalPncId
)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_ComM_UNMODIFIED_VAR_NOT_CONST" */
    uint8 signalByteIndex = ComM_PncSignal[InternalSignalId].PncSignalValuesStartIdxOfPncSignal + ComM_PncPb[InternalPncId].SignalByteIndexOfPncPb;  /* Index of the signal buffer. */
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_ComM_UNMODIFIED_VAR_NOT_CONST" */
    uint8 signalByte = ComM_PncSignalValues[signalByteIndex] & ComM_Pnc[InternalPncId].ClearMaskOfPnc;  /* Get signal value. */

    /* polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule14.3" polyspace +1 DEFECT:USELESS_IF [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( signalByteIndex < COMM_SIZE_OF_SIGNAL_VALUES )
    {
        ComM_PncSignalValues[signalByteIndex] = signalByte;  /* Clear signal buffer. */
    }
}

/*
********************************************************************************
* Function Name: ComM_PncSetBitInSignal
*
* Explanation: Set Pnc bit signal.
*
* param: InternalSignalId: Rx or Tx index.
*        InternalPncId: Pnc signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COMM_CODE) ComM_PncSetBitInSignal
(
    ComM_SizeOfPncSignalType InternalSignalId,
    ComM_PncIterType InternalPncId
)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_ComM_UNMODIFIED_VAR_NOT_CONST" */
    uint8 signalByteIndex = ComM_PncSignal[InternalSignalId].PncSignalValuesStartIdxOfPncSignal + ComM_PncPb[InternalPncId].SignalByteIndexOfPncPb;  /* Index of the signal buffer. */
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_ComM_UNMODIFIED_VAR_NOT_CONST" */
    uint8 signalByte = ComM_PncSignalValues[signalByteIndex] | ComM_Pnc[InternalPncId].SetMaskOfPnc;  /* Get signal value. */

    /* polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule14.3" polyspace +1 DEFECT:USELESS_IF [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( signalByteIndex < COMM_SIZE_OF_SIGNAL_VALUES )
    {
        ComM_PncSignalValues[signalByteIndex] = signalByte;   /* Set signal buffer. */
    }
}

/*
********************************************************************************
* Function Name: ComM_PncProcessRxSignalEira
*
* Explanation: Pnc process rx signal of Eira.
*
* param: InternalSignalId: Rx or Tx index.
*        SignalDataRx: Rx signal data.
*
* retval: None
********************************************************************************
*/
FUNC(void, COMM_CODE) ComM_PncProcessRxSignalEira
(
    uint8 InternalSignalId,
    P2CONST(uint8, AUTOMATIC, COMM_APPL_DATA) SignalDataRx
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    ComM_SizeOfPncType pncIndex;
    uint8 SigValuesArb;
    uint8 signalIndex;

    for( pncIndex = COMM_ZERO; pncIndex < COMM_PNC_SIZE; pncIndex++ )
    {
        if( (SignalDataRx[ComM_PncPb[pncIndex].SignalByteIndexOfPncPb] & ComM_Pnc[pncIndex].SetMaskOfPnc) != COMM_ZERO )
        {
            /* If a PNC is requested via EIRA RX, set the target state to COMM_PNC_READY_SLEEP. */
            ComM_BusPncComModeReq[pncIndex] = (uint8)COMM_PNC_READY_SLEEP;
            ComM_PncSetBitInSignal(InternalSignalId, pncIndex);
        }
        else
        {
            /* Clear pnc state. */
            ComM_PncClearBitInSignal(InternalSignalId, pncIndex);
            SigValuesArb = COMM_ZERO;
            for( signalIndex = COMM_ZERO; signalIndex < COMM_SIGNAL_NUM; signalIndex++ )
            {
                if( COMM_EIRA_RX_TYPEOFPNCSIGNAL == ComM_PncSignal[signalIndex].TypeOfPncSignal )
                {
                    SigValuesArb |= ComM_PncSignalValues[ComM_PncSignal[signalIndex].PncSignalValuesStartIdxOfPncSignal + ComM_PncPb[pncIndex].SignalByteIndexOfPncPb];
                }
            }

            if( COMM_ZERO == (SigValuesArb & ComM_Pnc[pncIndex].SetMaskOfPnc) )
            {
                ComM_BusPncComModeReq[pncIndex] = (uint8)COMM_PNC_NO_COMMUNICATION;
            }
        }
    }
}

#if( COMM_PNCGATEWAYENABLED == STD_ON )
/*
********************************************************************************
* Function Name: ComM_PncProcessRxSignalEra
*
* Explanation: Pnc process rx signal of Era:
*              (1) If a PNC bit is set in the ERA RX signal, then request full
*              com mode by using the system user of this PNC.
*              (2) If a PNC bit is cleared in the ERA RX signal, then check all
*              ERA RX signals from each channel of this PNC, release of the PNC
*              should only be done when all the ERA RX PNC bits all cleared.
*              Otherwise the PNC is still requested externally from at least
*              one ComM channel.
*
* param: InternalSignalId: Index used to locate the item of ComM_PncSignal.
*        SignalDataRx: Rx signal data.
*
* retval: None
********************************************************************************
*/
FUNC(void, COMM_CODE) ComM_PncProcessRxSignalEra
(
    ComM_SizeOfPncSignalType InternalSignalId,
    P2CONST(uint8, AUTOMATIC, COMM_APPL_DATA) SignalDataRx
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    ComM_SizeOfPncType pncIndex = COMM_ZERO;  /* Used to loop for all ComM_Pnc. */
    uint8  sigValuesArb = COMM_ZERO;    /* Aggregated external request of a PNC. */
    uint8  signalIndex = COMM_ZERO;         /* Index of ComM_PncSignal array. */
    uint8  signalMappingIndex = COMM_ZERO;  /* Index of ComM_PncSignalInd array. */

    /* A received ERA RX signal can affects all PNCs, so loop for all. */
    for( pncIndex = COMM_ZERO; pncIndex < COMM_PNC_SIZE; pncIndex++ )
    {
        /* Check if it's a coordinated PNC (which has more than one channel). */
        if( TRUE == ComM_Pnc[pncIndex].CoordinatedOfPnc )
        {
            /* Check the bit which represents this PNC on the received signal. */
            if( (SignalDataRx[ComM_PncPb[pncIndex].SignalByteIndexOfPncPb] & ComM_Pnc[pncIndex].SetMaskOfPnc) != COMM_ZERO )
            {
                /* Set the ComM internal PNC signal buffer: ComM_PncSignalValues. */
                ComM_PncSetBitInSignal(InternalSignalId, pncIndex);
                /* If a PNC is requested via ERA RX, set the target state to COMM_FULL_COMMUNICATION. */
                (void)ComM_RequestComMode(ComM_Pnc[pncIndex].SystemUserOfPnc, COMM_FULL_COMMUNICATION);
            }
            else
            {
                /* Clear the internal PNC signal buffer: ComM_PncSignalValues. */
                ComM_PncClearBitInSignal(InternalSignalId, pncIndex);

                /* Aggregation of all external requests. */
                sigValuesArb = COMM_ZERO;
                /* Loop for all relevant signals of this PNC.
                   Note: A PNC gateway has one EIRA RX and several ERA RX signals. */
                for( signalMappingIndex = ComM_PncPb[pncIndex].PncSignalIndStartIdxOfPncPb ;
                     signalMappingIndex < ComM_PncPb[pncIndex].PncSignalIndEndIdxOfPncPb; signalMappingIndex++ )
                {
                    /* Get the index of ComM_PncSignal of this PNC. */
                    signalIndex = ComM_GetPncSignalInd(signalMappingIndex);

                    /* Get the ComM_PncSignal entity and check if this signal is
                       an ERA RX signal. */
                    if( COMM_ERA_RX_TYPEOFPNCSIGNAL == ComM_PncSignal[signalIndex].TypeOfPncSignal )
                    {
                        /* Aggregate all ERA RX signals of this PNC, and arbitrate
                           if at least one signal bit (on several ERA RX signals)
                           which represents this PNC is set, if so this PNC is
                           still requested. */
                        sigValuesArb |= ComM_PncSignalValues[ComM_PncSignal[signalIndex].PncSignalValuesStartIdxOfPncSignal + ComM_PncPb[pncIndex].SignalByteIndexOfPncPb];
                    }
                }

                /* Arbitrate if this PNC is still requested by at least one ERA RX signal bit. */
                if( COMM_ZERO == (sigValuesArb & ComM_Pnc[pncIndex].SetMaskOfPnc) )
                {
                    /* No external request exists.
                       Release the FULL COM request of the PNC's virtual system user. */
                    (void)ComM_RequestComMode(ComM_Pnc[pncIndex].SystemUserOfPnc, COMM_NO_COMMUNICATION);
                    /* Comment: If the bit for a PNC is equal to zero in all ERAn,
                       no other node than the PNC gateway is requesting the PNC. */
                }
            }
        }
    }
}
#endif  /* COMM_PNCGATEWAYENABLED == STD_ON */

#if( COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL == STD_ON )
/*
********************************************************************************
* Function Name: ComM_PncModeSendSignal
*
* Explanation: Pnc send signal.
*
* param: PncHandle: Pnc id.
*        activeState: TRUE: Set bit(PNC is requested).
*                     FALSE: Clear bit(PNC is not requested).
*        sigType: COMM_SIG_SEND_ACTIVE, COMM_SIG_SEND_PASSIVE, COMM_SIG_SEND_ALL
*
* retval: None
********************************************************************************
*/
static FUNC(void, COMM_CODE) ComM_PncModeSendSignal
(
    ComM_PncIterType PncHandle,
    boolean activeState,
    uint8 sigType
)
{
    uint8 signalMappingIndex = COMM_ZERO;
    ComM_SizeOfPncSignalType signalIndex = COMM_ZERO;

#if( COMM_PNCPASSIVEGWSUPPORT != STD_ON )
    COMM_DUMMY_STATEMENT(sigType);
#endif  /* COMM_PNCPASSIVEGWSUPPORT != STD_ON */

    for( signalMappingIndex = ComM_PncPb[PncHandle].PncSignalIndStartIdxOfPncPb;
         signalMappingIndex < ComM_PncPb[PncHandle].PncSignalIndEndIdxOfPncPb; signalMappingIndex++ )
    {
        /* Get the index of ComM_PncSignal of this PNC. */
        signalIndex = ComM_GetPncSignalInd(signalMappingIndex);

#if( COMM_EXISTS_ERA_RX_TYPEOFPNCSIGNAL == STD_ON )
        if( COMM_EIRA_TX_TYPEOFPNCSIGNAL == ComM_PncSignal[signalIndex].TypeOfPncSignal )
#endif  /* COMM_EXISTS_ERA_RX_TYPEOFPNCSIGNAL == STD_ON */
        {

#if( COMM_PNCPASSIVEGWSUPPORT == STD_ON )
            /* polyspace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.4" */
            if( (sigType == ComM_Channel[ComM_PncSignal[signalIndex].ChannelIdxOfPncSignal].ComMPncGatewayType) || (COMM_SIG_SEND_ALL == sigType) )
#endif  /* COMM_PNCPASSIVEGWSUPPORT == STD_ON */
            {
                if( (boolean)TRUE == activeState )  /* Set bit. */
                {
                    ComM_PncSetBitInSignal(signalIndex, PncHandle);
                    ComM_ExecuteComSendSignal(signalIndex, &ComM_PncSignalValues[ComM_PncSignal[signalIndex].PncSignalValuesStartIdxOfPncSignal]);
                }
                else  /* Set clear bit. */
                {
                    ComM_PncClearBitInSignal(signalIndex, PncHandle);
                    ComM_ExecuteComSendSignal(signalIndex, &ComM_PncSignalValues[ComM_PncSignal[signalIndex].PncSignalValuesStartIdxOfPncSignal]);
                }

                if( (boolean)TRUE == activeState )
                {
                    /* polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule14.3" polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
                    if( TRUE == ComM_Channel[ComM_PncSignal[signalIndex].ChannelIdxOfPncSignal].ComMPncNmRequest )
                    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    {
                        /* If this parameter equals true then every time a FULL Communication is requested due to a change
                           in the PNC state machine to PNC_REQUESTED Nm shall be called using the API Nm_NetworkRequest. */
                        (void)Nm_NetworkRequest(ComM_PncSignal[signalIndex].ChannelIdxOfPncSignal);  /* SWS_ComM_00980 */
                    }
                }
            }
        }
    }
}
#endif  /* COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL == STD_ON */
#endif  /* COMM_PNCSUPPORT == STD_ON */

/*
********************************************************************************
* Function Name:   ComM_Nm_NetworkMode
*
* Explanation:   Notification that the network management has entered Network Mode.(Asynchronous & Reentrant)
*
* param:         Channel: Channel id.
*
* retval:        None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
FUNC(void, COMM_CODE) ComM_Nm_NetworkMode(NetworkHandleType Channel)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( ComM_InitStatus != COMM_INIT )  /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
    }
    else if( Channel >= COMM_ACTIVE_CHANNEL )  /* Check channel id. */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
    }
    else
    {
        /* SWS_ComM_00296 */
        if( (COMM_SILENT_COM == ComM_ActiveComMode[Channel]) && (COMM_SILENT_COM == ComM_BusComModeReq[Channel]) )  /* Channel state is silent. */
        {
            ComM_ActiveComMode[Channel] = COMM_FULL_COM_READY_SLEEP;  /* Set active comm mode. */
            ComM_TF_SiCom_FullReadySleep(Channel);  /* Request FULLCOM on BusSM. */
        }

        ComM_BusComModeReq[Channel] = COMM_FULL_COM_READY_SLEEP;  /* Set bus comm mode. */
    }

    ComM_Det_ErrorReport(COMM_SID_CBK_NM_NETWORKMODE, errorId);  /* Det report. */
}

/*
********************************************************************************
* Function Name: ComM_Nm_PrepareBusSleepMode
*
* Explanation: Notification that the network management has entered Prepare Bus-Sleep Mode.(Asynchronous & Reentrant)
*
* param: Channel: Channel id.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
FUNC(void, COMM_CODE) ComM_Nm_PrepareBusSleepMode(NetworkHandleType Channel)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( ComM_InitStatus != COMM_INIT )          /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
    }
    else if( Channel >= COMM_ACTIVE_CHANNEL )   /* Check channel id. */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
    }
    else
    {
        /* SWS_ComM_00826 the ComM state machine shall switch to silent com. */
        ComM_BusComModeReq[Channel] = COMM_SILENT_COM;  /* Set bus comm mode to silent. */
        ComM_TF_Full_SiCom(Channel);                    /* Silent process. */
        ComM_ActiveComMode[Channel] = COMM_SILENT_COM;  /* Set active comm mode to silent. */
    }

    ComM_Det_ErrorReport(COMM_SID_CBK_NM_PREPAREBUSSLEEPMODE, errorId);  /* Det report. */
}

/*
********************************************************************************
* Function Name: ComM_Nm_BusSleepMode
*
* Explanation: Notification that the network management has entered Bus-Sleep Mode.(Asynchronous & Reentrant)
*
* param: Channel: Channel id.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
FUNC(void, COMM_CODE) ComM_Nm_BusSleepMode(NetworkHandleType Channel)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( ComM_InitStatus != COMM_INIT )  /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
    }
    else if( Channel >= COMM_ACTIVE_CHANNEL )   /* Check channel id. */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
    }
    else
    {
        ComM_BusComModeReq[Channel] = COMM_NO_COM_NO_PENDING_REQUEST;

        if( COMM_FULL_COM_NETWORK_REQUESTED == ComM_ActiveComMode[Channel] )
        {
          /* ComM_Nm_BusSleepMode() is called in context of Nm_NetworkRelease() while ComM performs the state transition COMM_FULL_COM_NETWORK_REQUESTED to COMM_FULL_COM_READY_SLEEP.
           *     Do nothing here and perform the transition to NoCom in the next ComM_MainFunction(). */
        }
        else
        {
            /* ComM_Nm_BusSleepMode() is called from the main function of a Nm module, this is the normal case. ComM shall perform the transition to NoCom immediately. */
            ComM_TF_SiCom_NoCom(Channel);  /* SWS_ComM_00637 */
        }
    }

    ComM_Det_ErrorReport(COMM_SID_CBK_NM_BUSSLEEPMODE, errorId);  /* Det report */
}

/*
********************************************************************************
* Function Name: ComM_Nm_RestartIndication
*
* Explanation: If NmIf has started to shut down the coordinated busses, AND not all
*            coordinated busses have indicated bus sleep state, AND on at least on one of
*            the coordinated busses NM is restarted, THEN the NM Interface shall call the
*            callback function ComM_Nm_RestartIndication with the nmNetworkHandle of the
*            channels which have already indicated bus sleep state.(Asynchronous & Reentrant)
*
* param: Channel: Channel id.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
FUNC(void, COMM_CODE) ComM_Nm_RestartIndication(NetworkHandleType Channel)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( ComM_InitStatus != COMM_INIT )  /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
    }
    else if( Channel >= COMM_ACTIVE_CHANNEL )  /* Check channel id. */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
    }
    else
    {
        ComM_ProcessPassiveWakeUp(Channel);  /* Passive wake up. */
    }

    ComM_Det_ErrorReport(COMM_SID_CBK_NM_RESTARTINDICATION, errorId);  /* Det report. */
}

/*
********************************************************************************
* Function Name: ComM_GetCurrentComMode
*
* Explanation: Function to query the current Communication Mode. ComM shall use the
*              corresponding interfaces of the Bus State Managers to get the current
*              Communication Mode of the network.(Asynchronous & Reentrant)
*
* param: User: Handle of the user who requests a mode.
*        ComMode: current comm mode.
*
* retval: E_OK: Successfully returned Communication Mode from Bus State Manager.
*         E_NOT_OK: Return of Communication Mode from Bus State Manager failed.
********************************************************************************
*/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetCurrentComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
    uint8 IByteMaskIndex;
    uint8 CanSmComMode;
    Std_ReturnType lCansmResult;
    Std_ReturnType lResult;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( ComM_InitStatus != COMM_INIT )  /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
        lResult = COMM_E_NOT_OK;
    }
    else if( User >= COMM_USER_SIZE )  /* Check user id. */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
        lResult = COMM_E_NOT_OK;
    }
    else if( NULL_PTR == ComMode )  /* Check point. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = COMM_E_PARAM_POINTER;
        lResult = COMM_E_NOT_OK;
    }
    else
    {
        /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_ComM_TAINTED_PTR" */
        *ComMode = COMM_FULL_COMMUNICATION;

        for( IByteMaskIndex = ComM_User[User].UserByteMaskStartIdxOfUser;
                    /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.14" polyspace +1 DEFECT:TAINTED_LOOP_BOUNDARY [Justified:Unset] "NSCA_Polyspace_ComM_TAINTED_LOOP_BOUNDARY" */
                    IByteMaskIndex < ComM_User[User].UserByteMaskEndIdxOfUser; IByteMaskIndex++ )
        {
            lCansmResult = ComM_GetCurrentBusSMMode(ComM_UserByteMask[IByteMaskIndex].ChannelOfUserByteMask, &CanSmComMode);  /* Get current bus sm mode. */
            if( ((uint8)E_OK == lCansmResult) && (CanSmComMode < *ComMode) )
            {
                *ComMode = CanSmComMode;
            }
        }

        /* Todo: return value of BusSM is ignored. */
        lResult = COMM_E_OK;
    }

    ComM_Det_ErrorReport(COMM_SID_GETCURRENTCOMMODE, errorId);  /* Det report. */

    return lResult;
}

/*
********************************************************************************
* Function Name: ComM_GetCurrentBusSMMode
*
* Explanation: Function to query the current Communication Mode.
*
* param: Channel: Channel id.
*        ComMode: Current comm mode.
*
* retval: E_OK: Successfully returned Communication Mode from Bus State Manager.
*         E_NOT_OK: Return of Communication Mode from Bus State Manager failed.
********************************************************************************
*/
static Std_ReturnType ComM_GetCurrentBusSMMode
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    NetworkHandleType Channel,
    ComM_ModeType *ComMode
)
{
    Std_ReturnType lResult = E_NOT_OK;

    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( NULL_PTR != ComMode )  /* Check point. */
    {
        switch(ComM_Channel[Channel].BusTypeOfChannel)
        {

#if( COMM_BUSTYPE_CAN_ENABLED == STD_ON )
            case COMM_BUS_TYPE_CAN:
                lResult = CanSM_GetCurrentComMode(Channel, ComMode);
                break;
#endif  /* COMM_BUSTYPE_CAN_ENABLED == STD_ON */

#if( COMM_BUSTYPE_FR_ENABLED == STD_ON )
            case COMM_BUS_TYPE_FR:
                lResult = FrSM_GetCurrentComMode(Channel, ComMode);
                break;
#endif  /* COMM_BUSTYPE_FR_ENABLED == STD_ON */

#if( COMM_BUSTYPE_LIN_ENABLED == STD_ON )
            case COMM_BUS_TYPE_LIN:
                lResult = LinSM_GetCurrentComMode(Channel, ComMode);
                break;
#endif  /* COMM_BUSTYPE_LIN_ENABLED == STD_ON */

#if( COMM_BUSTYPE_ETH_ENABLED == STD_ON )
            case COMM_BUS_TYPE_ETH:
                lResult = EthSM_GetCurrentComMode(Channel, ComMode);
                break;
#endif  /* COMM_BUSTYPE_ETH_ENABLED == STD_ON */

            /* polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            default:
                /* Do nothing. */
                break;
        }
    }

    return lResult;
}

/*
********************************************************************************
* Function Name: ComM_ProcessPassiveWakeUp
*
* Explanation: NM indicate wakeup to ComM.
*
* param: Channel: Channel id
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
static FUNC(void, COMM_CODE) ComM_ProcessPassiveWakeUp(NetworkHandleType channel)
{

#if( COMM_SYNCHRONOUSWAKEUP == STD_ON )
    NetworkHandleType ChannelIdx;

#if( COMM_PNCSUPPORT == STD_ON )
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 pncIndex;
#endif  /* COMM_PNCSUPPORT == STD_ON */

#endif  /* COMM_SYNCHRONOUSWAKEUP == STD_ON */

#if( COMM_SYNCHRONOUSWAKEUP == STD_ON )
    COMM_DUMMY_STATEMENT(channel);
    for( ChannelIdx = COMM_ZERO; ChannelIdx < COMM_ACTIVE_CHANNEL; ChannelIdx++ )  /* Set default wakeup state. */
    {
        if( COMM_ZERO == (ComM_ActiveComMode[ChannelIdx] & COMM_FULL_COMMUNICATION) )
        {
            ComM_BusComModeReq[ChannelIdx] = ComM_Channel[ChannelIdx].WakeupStateOfChannel;
        }
        /* else if ComM_ActiveComMode(current channel state) is COMM_FULL_COM_NETWORK_REQUESTED
           or COMM_FULL_COM_READY_SLEEP, do nothing because the channel has
           already entered COMM_FULL_COMMUNICATION state. */
    }

#if( COMM_PNCSUPPORT == STD_ON )
    for( pncIndex = COMM_ZERO; pncIndex < COMM_PNC_SIZE; pncIndex++ )  /* Set pnc state to prepare sleep mode. */
    {
        if( ((uint8)COMM_PNC_NO_COMMUNICATION == ComM_ActivePncComMode[pncIndex])
                    && ((uint8)COMM_PNC_NO_COMMUNICATION == ComM_BusPncComModeReq[pncIndex]) )
        {
            ComM_BusPncComModeReq[pncIndex] = (uint8)COMM_PNC_PREPARE_SLEEP;
        }
    }
#endif  /* COMM_PNCSUPPORT == STD_ON */

#else  /* COMM_SYNCHRONOUSWAKEUP == STD_ON */
    if( COMM_ZERO == (ComM_ActiveComMode[channel] & COMM_FULL_COMMUNICATION) )
    {
        ComM_BusComModeReq[channel] = ComM_Channel[channel].WakeupStateOfChannel;
    }

#endif  /* COMM_SYNCHRONOUSWAKEUP == STD_ON */
}

/*
********************************************************************************
* Function Name: ComM_Nm_NetworkStartIndication
*
* Explanation: Indication that a NM-message has been received in the Bus Sleep Mode,
*              what indicates that some nodes in the network have already entered
*              the Network Mode.(Asynchronous & Reentrant)
*
* param: Channel: Channel id
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
FUNC(void, COMM_CODE) ComM_Nm_NetworkStartIndication(NetworkHandleType Channel)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( ComM_InitStatus != COMM_INIT )  /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
    }
    else if( Channel >= COMM_ACTIVE_CHANNEL )  /* Check channel id. */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
    }
    else
    {
        ComM_ProcessPassiveWakeUp(Channel);  /* Process passive wake up. */
    }
    ComM_Det_ErrorReport(COMM_SID_CBK_NM_NETWORKSTARTINDICATION, errorId);  /* Det report. */
}

/*
********************************************************************************
* Function Name: ComM_BusSM_ModeIndication
*
* Explanation: Indication of the actual bus mode by the corresponding Bus State Manager.
*            ComM shall propagate the indicated state to the users with means of the RTE and BswM.
*
* param: Channel: Channel id
*        ComMode: ComM mode
*
* retval: None
********************************************************************************
*/
FUNC(void, COMM_CODE) ComM_BusSM_ModeIndication
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    NetworkHandleType Channel,
    P2CONST(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( ComM_InitStatus != COMM_INIT )  /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
    }
    else if( Channel >= COMM_ACTIVE_CHANNEL )  /* Check channel id. */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
    }
    else if( NULL_PTR == ComMode )  /* Check point. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = COMM_E_PARAM_POINTER;
    }
    /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_ComM_TAINTED_PTR" */
    else if( *ComMode > COMM_FULL_COMMUNICATION )  /* Check paremeter. */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
    }
    else
    {
#if( COMM_BSWMENABLED == STD_ON )
        BswM_ComM_CurrentMode(Channel, *ComMode);  /* Report to BSWM. */
#endif  /* COMM_BSWMENABLED == STD_ON */
    }

    ComM_Det_ErrorReport(COMM_SID_CBK_BUSSMMODEINDICATION, errorId);  /* Det report. */
}

/*
********************************************************************************
* Function Name: ComM_BusSM_BusSleepMode
*
* Explanation: Notification of the corresponding Bus State Manager that the
*              actual bus mode is Bus-Sleep.
*
* param: Channel: Channel id
*
* retval: None
********************************************************************************
*/
FUNC(void, COMM_CODE) ComM_BusSM_BusSleepMode
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    NetworkHandleType Channel
)
{
    /* SWS_ComM_91000 */
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( COMM_INIT != ComM_InitStatus )  /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
    }
    else if( Channel >= COMM_ACTIVE_CHANNEL )   /* Check channel id. */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
    }
    else if( COMM_LINSLAVE_NMTYPEOFCHANNEL != ComM_Channel[Channel].ComMNmVariant )
    {
        errorId = COMM_E_WRONG_PARAMETERS;
    }
    else
    {
        /* Set bus mode to no communication. */
        ComM_BusComModeReq[Channel] = COMM_NO_COM_NO_PENDING_REQUEST;

        /* SWS_ComM_01018: The ComM channel state machine shall switch to state
        COMM_NO_COMMUNICATION. */
        ComM_TF_SiCom_NoCom(Channel);
    }

    /* Det report */
    ComM_Det_ErrorReport(COMM_SID_CBK_BUSSM_BUSSLEEPMODE, errorId);
}

/*
********************************************************************************
* Function Name: ComM_DeInit
*
* Explanation: This API de-initializes the AUTOSAR Communication Manager.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, COMM_CODE) ComM_DeInit(void)
{
    ComM_InitStatus = COMM_UNINIT;
}

/*
********************************************************************************
* Function Name: ComM_GetInhibitionStatus
*
* Explanation: Returns the inhibition status of a ComM channel.(Synchronous & Non Reentrant)
*
* param: Channel: Channel id.
*        Status: inhibit state: 0x01: WakeupInhibitionActive.
*                               0x02: LimitedToNoCom.
*
* retval: E_OK: Successfully returned Inhibition Status.
*         E_NOT_OK: Return of Inhibition Status failed.
********************************************************************************
*/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetInhibitionStatus
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    NetworkHandleType Channel,
    P2VAR(ComM_InhibitionStatusType, AUTOMATIC, COMM_APPL_DATA) Status
)
{
    Std_ReturnType lResult;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( ComM_InitStatus != COMM_INIT )  /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
        lResult = E_NOT_OK;
    }
    else if( NULL_PTR == Status )  /* Check point. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = COMM_E_PARAM_POINTER;
        lResult = E_NOT_OK;
    }
    else if( Channel >= COMM_ACTIVE_CHANNEL )  /* Check channel id. */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
        lResult = E_NOT_OK;
    }
    else
    {
        /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_ComM_TAINTED_PTR" */
        *Status = ComM_Inhibition.ComM_InhibitionStatus[Channel];  /* Get inhibit. */
        lResult = E_OK;
    }

    ComM_Det_ErrorReport(COMM_SID_GETINHIBITIONSTATUS, errorId);  /* Det report. */

    return lResult;
}

/*
********************************************************************************
* Function Name: ComM_GetMaxComMode
*
* Explanation: Function to query the maximum allowed Communication Mode of the
*              corresponding user.(Synchronous & Reentrant)
*
* param: User: Handle of the user who requests a mode.
*        ComMode: Comm mode.
*
* retval: E_OK: Successfully returned maximum allowed Communication Mode.
*         E_NOT_OK: Return of maximum allowed Communication Mode failed.
********************************************************************************
*/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetMaxComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
    Std_ReturnType lResult;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;
#if( (COMM_MODELIMITATION == STD_ON) || (COMM_WAKEUPINHIBITIONENABLED == STD_ON) )
    uint8 IByteMaskIndex = COMM_ZERO;
#endif  /* (COMM_MODELIMITATION == STD_ON) || (COMM_WAKEUPINHIBITIONENABLED == STD_ON) */

    if( ComM_InitStatus != COMM_INIT )  /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
        lResult = E_NOT_OK;
    }
    else if( NULL_PTR == ComMode )  /* Check point. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = COMM_E_PARAM_POINTER;
        lResult = E_NOT_OK;
    }
    else if( User >= COMM_USER_SIZE )  /* Check user id. */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
        lResult = E_NOT_OK;
    }
    else
    {
        /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_ComM_TAINTED_PTR" */
        *ComMode = (ComM_ModeType)COMM_FULL_COMMUNICATION;
#if( (COMM_MODELIMITATION == STD_ON) || (COMM_WAKEUPINHIBITIONENABLED == STD_ON) )
        for( IByteMaskIndex = ComM_User[User].UserByteMaskStartIdxOfUser;
                /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.14" polyspace +1 DEFECT:TAINTED_LOOP_BOUNDARY [Justified:Unset] "NSCA_Polyspace_ComM_TAINTED_LOOP_BOUNDARY" */    
                IByteMaskIndex < ComM_User[User].UserByteMaskEndIdxOfUser; IByteMaskIndex++ )
        {
            if( TRUE == ComM_ChannelIsLimited(ComM_UserByteMask[IByteMaskIndex].ChannelOfUserByteMask) )  /* Check limit. */
            {
                *ComMode = COMM_NO_COMMUNICATION;
            }
        }
#endif  /* (COMM_MODELIMITATION == STD_ON) || (COMM_WAKEUPINHIBITIONENABLED == STD_ON) */
        lResult = E_OK;
    }

    ComM_Det_ErrorReport(COMM_SID_GETMAXCOMMODE, errorId);  /* Det report. */

    return lResult;
}

/*
********************************************************************************
* Function Name: ComM_PreventWakeUp
*
* Explanation: Changes the inhibition status COMM_NO_WAKEUP for the corresponding channel.
*
* param: Channel: Channel id.
*        Status: FALSE: Wake up inhibition is switched off.
*                TRUE: Wake up inhibition is switched on.
*
* retval: E_OK: Successfully changed wake up status for the channel.
*         E_NOT_OK: Changed of wake up status for the channel failed.
********************************************************************************
*/
FUNC(Std_ReturnType, COMM_CODE) ComM_PreventWakeUp
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    NetworkHandleType Channel,
    boolean Status
)
{
    Std_ReturnType lResult;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( ComM_InitStatus != COMM_INIT )  /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
        lResult = E_NOT_OK;
    }
    else if( Channel >= COMM_ACTIVE_CHANNEL )  /* Check channel id. */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
        lResult = E_NOT_OK;
    }
    else
    {
#if( COMM_WAKEUPINHIBITIONENABLED == STD_ON )
        if( TRUE == Status )
        {
            if( COMM_WAKEUP_INHIBITION_MASK == (ComM_Inhibition.ComM_ECUGroupClassification & COMM_WAKEUP_INHIBITION_MASK) )  /* Check group classification. */
            {
                ComM_Inhibition.ComM_InhibitionStatus[Channel] |= COMM_WAKEUP_INHIBITION_MASK;  /* Set inhibit status. */
                lResult = E_OK;
            }
            else
            {
                lResult = E_NOT_OK;
            }
        }
        else
        {
            ComM_Inhibition.ComM_InhibitionStatus[Channel] &= COMM_WAKEUP_INHIBITION_CLEAR_MASK;  /* Clear inhibit status. */
            lResult = E_OK;
        }
#else  /* COMM_WAKEUPINHIBITIONENABLED == STD_ON */
        COMM_DUMMY_STATEMENT(Status);
        lResult = E_NOT_OK;
#endif  /* COMM_WAKEUPINHIBITIONENABLED == STD_ON */
    }

    ComM_Det_ErrorReport(COMM_SID_PREVENTWAKEUP, errorId);  /* Det report. */

    return lResult;
}

/*
********************************************************************************
* Function Name:   ComM_LimitChannelToNoComMode
*
* Explanation:   Changes the inhibition status COMM_NO_WAKEUP for the
*                            corresponding channel.(Synchronous & Non Reentrant)
*
* param: Channel: Channel id.
*        Status: FALSE: Limit ECU to COMM_NO_COMMUNICATION disabled.
*               TRUE: Limit ECU to COMM_NO_COMMUNICATION enabled.
*
* retval: E_OK: Successfully changed inhibition status for the channel.
*         E_NOT_OK: Changed of inhibition status for the channel failed.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
FUNC(Std_ReturnType, COMM_CODE) ComM_LimitChannelToNoComMode
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    NetworkHandleType Channel, boolean Status
)
{
    Std_ReturnType lResult = E_NOT_OK;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( ComM_InitStatus != COMM_INIT )  /* Check init state. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = COMM_E_NOT_INITED;
        lResult = E_NOT_OK;
    }
    else if( Channel >= COMM_ACTIVE_CHANNEL )  /* Check channel id. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
        lResult = E_NOT_OK;
    }
    else
    {
#if( COMM_MODELIMITATION == STD_ON )
        if( TRUE == Status )
        {
            if( (COMM_FULL_COM_NETWORK_REQUESTED == ComM_ActiveComMode[Channel]) &&
                ((ComM_Inhibition.ComM_ECUGroupClassification & COMM_MODE_LIMITATION_MASK) == COMM_MODE_LIMITATION_MASK ) )  /* Set inhibit. */
            {
                ComM_Inhibition.ComM_InhibitionStatus[Channel] |= COMM_MODE_LIMITATION_MASK;
                lResult = E_OK;
            }
        }
        else
        {
            ComM_Inhibition.ComM_InhibitionStatus[Channel] &= COMM_MODE_LIMITATION_CLEAR_MASK;  /* Clear inhibit. */
            lResult = E_OK;
        }
#else  /* COMM_MODELIMITATION == STD_ON */
        COMM_DUMMY_STATEMENT(Status);
#endif  /* COMM_MODELIMITATION == STD_ON */

    }

    ComM_Det_ErrorReport(COMM_SID_LIMITCHANNELTONOCOMMODE, errorId);  /* Det report. */

    return lResult;
}

/*
********************************************************************************
* Function Name: ComM_LimitECUToNoComMode
*
* Explanation: Changes the inhibition status for the ECU (=all channels) for changing from
*            COMM_NO_COMMUNICATION to a higher Communication Mode(Synchronous & Non Reentrant)
*
* param: Status:FALSE: Limit ECU to COMM_NO_COMMUNICATION disabled.
*               TRUE: Limit ECU to COMM_NO_COMMUNICATION enabled.
*
* retval: E_OK: Successfully changed inhibition status for the ECU.
*         E_NOT_OK: Changed of inhibition status for the ECU failed.
********************************************************************************
*/
FUNC(Std_ReturnType, COMM_CODE) ComM_LimitECUToNoComMode(boolean Status)
{
    Std_ReturnType lResult;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;
#if( COMM_MODELIMITATION == STD_ON )
    NetworkHandleType ComM_ChannelIndex;
#endif  /* COMM_MODELIMITATION == STD_ON */

    if( ComM_InitStatus != COMM_INIT )  /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
        lResult = E_NOT_OK;
    }
    else
    {
#if( COMM_MODELIMITATION == STD_ON )
        lResult = E_OK;
        for( ComM_ChannelIndex = COMM_ZERO; ComM_ChannelIndex < COMM_ACTIVE_CHANNEL; ComM_ChannelIndex++ )  /* Set inhibit status per channel. */
        {
            if( ComM_LimitChannelToNoComMode(ComM_ChannelIndex, Status) != E_OK )
            {
                lResult = E_NOT_OK;
            }
        }
#else  /* COMM_MODELIMITATION == STD_ON */
        COMM_DUMMY_STATEMENT(Status);
        lResult = E_NOT_OK;
#endif  /* COMM_MODELIMITATION == STD_ON */
    }

    ComM_Det_ErrorReport(COMM_SID_LIMITECUTONOCOMMODE, errorId);  /* Det report. */

    return lResult;
}

#if( COMM_MODELIMITATION == STD_ON )
/*
********************************************************************************
* Function Name: ComM_ReadInhibitCounter
*
* Explanation: This function returns the amount of rejected COMM_FULL_COMMUNICATION
*                        user requests(Synchronous & Non Reentrant)
*
* param: CounterValue: Amount of rejected COMM_FULL_COMMUNICATION user requests.
*
* retval: E_OK: Successfully returned Inhibition Counter
*         E_NOT_OK: Return of Inhibition Counter failed
********************************************************************************
*/
FUNC(Std_ReturnType, COMM_CODE) ComM_ReadInhibitCounter
(
    P2VAR(uint16, AUTOMATIC, COMM_APPL_DATA) CounterValue
)
{
    Std_ReturnType lResult;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( ComM_InitStatus != COMM_INIT )  /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
        lResult = E_NOT_OK;
    }
    else if( NULL_PTR == CounterValue )  /* Check point. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = COMM_E_PARAM_POINTER;
        lResult = E_NOT_OK;
    }
    else
    {
        /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_ComM_TAINTED_PTR" */
        *CounterValue = ComM_Inhibition.ComM_InhibitCnt;  /* Set inhibit counter. */
        lResult = E_OK;
    }

    ComM_Det_ErrorReport(COMM_SID_READINHIBITCOUNTER, errorId);  /* Det report. */

    return lResult;
}

/*
********************************************************************************
* Function Name: ComM_ResetInhibitCounter
*
* Explanation: This function resets the Inhibited COMM_FULL_COMMUNICATION request
*              Counter.(Synchronous & Non Reentrant)
*
* param: None
*
* retval: E_OK: Successfully reset of Inhibit COMM_FULL_COMMUNICATION Counter.
*         E_NOT_OK: Reset of Inhibit COMM_FULL_COMMUNICATION Counter failed.
********************************************************************************
*/
FUNC(Std_ReturnType, COMM_CODE) ComM_ResetInhibitCounter(void)
{
    Std_ReturnType lResult;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( ComM_InitStatus != COMM_INIT )  /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
        lResult = E_NOT_OK;
    }
    else
    {
        ComM_Inhibition.ComM_InhibitCnt = COMM_ZERO;  /* Set default inhibit counter. */
        lResult = E_OK;
    }

    ComM_Det_ErrorReport(COMM_SID_RESETINHIBITCOUNTER, errorId);  /* Det report. */

    return lResult;
}
#endif /* COMM_MODELIMITATION == STD_ON */

/*
********************************************************************************
* Function Name: ComM_GetRequestedComMode
*
* Explanation: Function to query the currently requested Communication Mode of
*              the corresponding user.(Synchronous & Reentrant)
*
* param: User: Handle of the user who requests a mode.
*        ComMode: Name of the requested mode.
*
* retval: E_OK: Successfully returned requested Communication Mode.
*         E_NOT_OK: Return of requested Communication Mode failed.
********************************************************************************
*/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetRequestedComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
    Std_ReturnType lResult;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;
    uint8 IByteMaskIndex;

    if( ComM_InitStatus != COMM_INIT )  /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
        lResult = E_NOT_OK;
    }
    else if( NULL_PTR == ComMode )  /* Check point. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = COMM_E_PARAM_POINTER;
        lResult = E_NOT_OK;
    }
    else if( User >= COMM_USER_SIZE )  /* Check user id. */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
        lResult = E_NOT_OK;
    }
    else
    {
        for( IByteMaskIndex = ComM_User[User].UserByteMaskStartIdxOfUser;
                /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.14" polyspace +1 DEFECT:TAINTED_LOOP_BOUNDARY [Justified:Unset] "NSCA_Polyspace_ComM_TAINTED_LOOP_BOUNDARY" */    
                IByteMaskIndex < ComM_User[User].UserByteMaskEndIdxOfUser; IByteMaskIndex++ )
        {
            if( (ComM_UserReqFullCom[ComM_UserByteMask[IByteMaskIndex].UserReqFullComIdxOfUserByteMask]
                            & ComM_UserByteMask[IByteMaskIndex].SetMaskOfUserByteMask) != COMM_NO_REQUESTS )
            {
                /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_ComM_TAINTED_PTR" */
                *ComMode = COMM_FULL_COMMUNICATION;  /* Full communication. */
            }
            else
            {
                /* polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.14" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_ComM_TAINTED_PTR" */
                *ComMode = COMM_NO_COMMUNICATION;  /* No communication. */
                break;
            }
        }
        lResult = E_OK;
    }

    ComM_Det_ErrorReport(COMM_SID_GETREQUESTEDCOMMODE, errorId);  /* Det report. */

    return lResult;
}

/*
********************************************************************************
* Function Name: ComM_DCM_ActiveDiagnostic
*
* Explanation: Indication of active diagnostic by the DCM.
*
* param: Channel: Channel needed for Diagnostic communication.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
FUNC(void, COMM_CODE) ComM_DCM_ActiveDiagnostic(NetworkHandleType Channel)
{
#if( COMM_DCM_REQUEST_ENABLED == STD_ON )
    uint8 errorId = COMM_E_NO_ERROR;
    uint8 Channel_LO = 0;

    if( ComM_InitStatus != COMM_INIT )  /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
    }
    else if( Channel >= COMM_ACTIVE_CHANNEL )  /* Check channel id. */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
    }
    else
    {
        // if( (COMM_NONE_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant) ||
        //     (COMM_LIGHT_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant) ||
        //     (COMM_FULL_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant) ||
        //     (COMM_LINSLAVE_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant) )
        // {
        //     ComM_DcmRequestActive[Channel] = TRUE;  /* Set Dcm request. */
        // }

        #if ( CANNM_BOTH_WAKEUP_AND_SLEEP_SUPPORTED == STD_ON )
        //同睡同醒
        for(uint8 NmChannel_LO = 0; NmChannel_LO < CanNm_GetSizeOfChannelConfig(); NmChannel_LO++)
        {
            Channel_LO = CanNm_GetChannelId(NmChannel_LO);
            if( (COMM_NONE_NMTYPEOFCHANNEL == ComM_Channel[Channel_LO].ComMNmVariant) ||
                (COMM_LIGHT_NMTYPEOFCHANNEL == ComM_Channel[Channel_LO].ComMNmVariant) ||
                (COMM_FULL_NMTYPEOFCHANNEL == ComM_Channel[Channel_LO].ComMNmVariant) ||
                (COMM_LINSLAVE_NMTYPEOFCHANNEL == ComM_Channel[Channel_LO].ComMNmVariant) )
            {
                /* 增加: 当NM处于休眠相关状态时, 不允许诊断唤醒 */
                if( COMM_FULL_COM_NETWORK_REQUESTED == ComM_ActiveComMode[Channel_LO] || COMM_FULL_COM_READY_SLEEP == ComM_ActiveComMode[Channel_LO] )
                {
                    ComM_DcmRequestActive[Channel_LO] = TRUE;  /* Set Dcm request. */
                }
            }
        }
        #else
        if( (COMM_NONE_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant) ||
            (COMM_LIGHT_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant) ||
            (COMM_FULL_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant) ||
            (COMM_LINSLAVE_NMTYPEOFCHANNEL == ComM_Channel[Channel].ComMNmVariant) )
        {
            ComM_DcmRequestActive[Channel] = TRUE;  /* Set Dcm request. */
        }
        #endif

    }

    ComM_Det_ErrorReport(COMM_SID_CBK_DCM_ACTIVEDIAGNOSTIC, errorId);  /* Det report. */
#else  /* COMM_DCM_REQUEST_ENABLED == STD_ON */
    /* In case of COMM_DCM_REQUEST_ENABLED is STD_OFF,
       Calling this API has no effect. */
    COMM_DUMMY_STATEMENT(Channel);
#endif  /* COMM_DCM_REQUEST_ENABLED == STD_ON */
}

/*
********************************************************************************
* Function Name: ComM_DCM_InactiveDiagnostic
*
* Explanation: Indication of inactive diagnostic by the DCM.
*
* param: Channel: Channel needed for Diagnostic communication
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
FUNC(void, COMM_CODE) ComM_DCM_InactiveDiagnostic(NetworkHandleType Channel)
{
#if( COMM_DCM_REQUEST_ENABLED == STD_ON )
    uint8 errorId = COMM_E_NO_ERROR;
    uint8 Channel_LO = 0;

    if( ComM_InitStatus != COMM_INIT )  /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
    }
    else if( Channel >= COMM_ACTIVE_CHANNEL )  /* Check channel id. */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
    }
    else
    {
        // ComM_DcmRequestActive[Channel] = FALSE;  /* Clear Dcm request. */

        #if ( CANNM_BOTH_WAKEUP_AND_SLEEP_SUPPORTED == STD_ON )
        //同睡同醒
        for(uint8 NmChannel_LO = 0; NmChannel_LO < CanNm_GetSizeOfChannelConfig(); NmChannel_LO++)
        {
            Channel_LO = CanNm_GetChannelId(NmChannel_LO);
            ComM_DcmRequestActive[Channel_LO] = FALSE;  /* Clear Dcm request. */
        }
        #else
        ComM_DcmRequestActive[Channel] = FALSE;  /* Clear Dcm request. */
        #endif
    }

    ComM_Det_ErrorReport(COMM_SID_CBK_DCM_INACTIVEDIAGNOSTIC, errorId);  /* Det report. */
#else  /* COMM_DCM_REQUEST_ENABLED == STD_ON */
    /* In case of COMM_DCM_REQUEST_ENABLED is STD_OFF,
       Calling this API has no effect. */
    COMM_DUMMY_STATEMENT(Channel);
#endif  /* COMM_DCM_REQUEST_ENABLED == STD_ON */
}

/*
********************************************************************************
* Function Name: ComM_SetECUGroupClassification
*
* Explanation: Changes the ECU Group Classification status.
*
* param: Status: Inhibit state.
*             0x01: WakeupInhibitionActive.
*             0x02: LimitedToNoCom.
*
* retval: E_OK: Successfully change the ECU Group Classification Status.
*         E_NOT_OK: Change of the ECU Group Classification Status failed.
********************************************************************************
*/
FUNC(Std_ReturnType, COMM_CODE) ComM_SetECUGroupClassification
(
    ComM_InhibitionStatusType Status
)
{
    Std_ReturnType lResult;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 errorId = COMM_E_NO_ERROR;

    if( ComM_InitStatus != COMM_INIT )  /* Check init state. */
    {
        errorId = COMM_E_NOT_INITED;
        lResult = E_NOT_OK;
    }
    else if( Status > (COMM_WAKEUP_INHIBITION_MASK | COMM_MODE_LIMITATION_MASK) )  /* Check paremeter. */
    {
        errorId = COMM_E_WRONG_PARAMETERS;
        lResult = E_NOT_OK;
    }
    else
    {
        ComM_Inhibition.ComM_ECUGroupClassification = Status;  /* Set group classification. */
        lResult = E_OK;
    }

    ComM_Det_ErrorReport(COMM_SID_SETECUGROUPCLASSIFICATION, errorId);  /* Det report. */

    return lResult;
}

/*
********************************************************************************
* Function Name: ComM_IndicateDcmChannelState
*
* Explanation: Indicate channel state to Dcm if COMM_DCM_MODE_INDICATION is ON.
*
* param: Channel: Channel id.
*        ComMode: Comm mode.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COMM_CODE) ComM_IndicateDcmChannelState
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    NetworkHandleType Channel,
    ComM_ModeType ComMode
)
{

#if( COMM_DCM_MODE_INDICATION == STD_ON )
    if( COMM_FULL_COMMUNICATION == ComMode )  /* Full communication. */
    {
        Dcm_ComM_FullComModeEntered(Channel);
    }
    else if( COMM_SILENT_COMMUNICATION == ComMode )  /* Silent communication. */
    {
        Dcm_ComM_SilentComModeEntered(Channel);
    }
    else if( COMM_NO_COMMUNICATION == ComMode )  /* No communication. */
    {
        Dcm_ComM_NoComModeEntered(Channel);
    }
    else
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Do nothing. */
    }
#else  /* COMM_DCM_MODE_INDICATION == STD_ON */
    COMM_DUMMY_STATEMENT(Channel);
    COMM_DUMMY_STATEMENT(ComMode);
#endif  /* COMM_DCM_MODE_INDICATION == STD_ON */

    return;
}

#define COMM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


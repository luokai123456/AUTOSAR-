/*
********************************************************************************
*
* File name: CanSM.c
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangCong/2018.07.21
* Change: New
* Cause: New
********************************************************************************
* Version: 2.0
* Author/Date: WangCong/2019.05.29
* Change: modify format
* Cause: updata to V2.0
********************************************************************************
* Version: 2.1
* Author/Date: WangCong/2019.10.12
* Change: modify code format
* Cause: Unified format
********************************************************************************
* Version: 2.2
* Author/Date: WangCong/2019.10.15
* Change: 1.Add configurable function User_GetBusOffDelay.
*         2.Use User_GetBusOffDelay to notify the user BusOff status.
*           0: BusOff recovery end.
*           Others: BusOff Begin
* Cause: Add configurable function and realize the Note of BusOff status.
********************************************************************************
* Version: 3.0
* Author/Date: WangCong/2020.01.19
* Change: Synchronizing code with the DF project(Debugging completed).
* Cause: update to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date: WangCong/2020.03.16
* Change: Change the macro CANIF_E_NO_ERR to CANSM_E_NO_ERR.
* Cause: bugfix
********************************************************************************
* Version: 3.2
* Author/Date: WangCong/2020.03.25
* Change: 1.Modify header file reference.
*         2.Fix the type mismatch problem.
* Cause: Clear QAC warning
********************************************************************************
* Version: 3.3
* Author/Date: WangCong/2020.03.30
* Change: Add comment.
* Cause: Code Walkthrough
********************************************************************************
* Version: 3.4
* Author/Date: WangCong/2020.05.12
* Change: Modify the code specification.
* Cause: Optimize
********************************************************************************
* Version: 3.5
* Author/Date: lizhiheng/2020.07.01
* Change: 1.Modify the code specification.
*         2.Add a judgment on the return value of the function.
* Cause: Optimize
********************************************************************************
* Version: 3.6
* Author/Date: WangC/2020.09.30
* Change: Add the function of CallBack and Change BSP.
* Cause: Optimize
********************************************************************************
* Version: 3.7
* Author/Date: WangC/2020.10.23
* Change: Modify the function name according to the AUTOSAR specification, add
*         MemMap.
* Cause: Optimize
********************************************************************************
* Version: 3.8
* Author/Date: WangC/2020.10.26
* Change: Modify the code according to QAC.
* Cause: Clear QAC warning.
********************************************************************************
* Version: 3.9
* Author/Date: WangC/2020.10.30
* Change: Add precompile for CanTrcv.
* Cause: Optimize
********************************************************************************
* Version: 3.10
* Author/Date: WangC/2020.11.22
* Change: 1.Add function of ensure busoff recovery by timeout.
*         2.Modify the timing of report error to Dem.
*         3.Modify the condition of FullCom state to adapt different Mcal.
* Cause: Optimize and add Function.
********************************************************************************
* Version: 3.11
* Author/Date: WangC/2020.12.02
* Change: Clear the Compiler warnings
* Cause: Optimize
********************************************************************************
* Version: 3.12
* Author/Date: WangC/2021.1.28
* Change: Change sub state of CANSM_BSM_WUVALIDATION in function of
*         CanSM_Bsm_PRE_NOCOM and CanSM_Bsm_NOCOM.
* Cause: Optimize
********************************************************************************
* Version: 3.13
* Author/Date: LiuHJ/2021.2.24
* Change: Add mode request timeout in sub state of CANSM_BSM_WUVALIDATION and
*         CANSM_BSM_S_FULLCOM according to AutoSar4.4
* Cause: Optimize
********************************************************************************
* Version: 3.14
* Author/Date: LiuHJ/2021.5.28
* Change: Add Interface to provide internal bus-off recovery level.
* Cause: Customized requirements
********************************************************************************
* Version: 3.15
* Author/Date: LiuHJ/2021.7.15
* Change: Modify the name of function/macros/service ID which are used to provide
*         internal bus-off recovery level.
* Cause: Optimize
********************************************************************************
* Version: 3.16
* Author/Date: LiuHJ/2021.9.1
* Change: Clear the Compiler warnings.
* Cause: Optimize
********************************************************************************
* Version: 3.17
* Author/Date: ChengWB/2022.8.29
* Change: Delete the state of PRE_FULLCOM.
* Cause: Bugifx
********************************************************************************
* Version: 3.18
* Author/Date: XieYN/2022.10.19
* Change: Merge the addition of the sub state machine PRE_NOCOM from Q3.
* Cause: Add Function.
********************************************************************************
* Version: 3.19
* Author/Date: XieYN/2022.11.7
* Change: 1. Delete the secondary assignment of ManagerNetworkPtr in CanSM_Init.
*         2. Add the assignments of Trg_ClearWUF_Indication and Trg_CheckWF_Indication
*            in CanSM_Init.
*         3. Modify CANSM_S_PNC_TRCV_STANDBY to CANSM_S_PNC_PN_TRCV_STANDBY in
*            CanSM_S_PNC_PN_TRCV_NORMAL.
* Cause: Add Function.
********************************************************************************
* Version: 3.20
* Author/Date: LiX/2023.3.31
* Change: Add the user-defined Callout function after the PDU mode is set to ONLINE.
* Cause: Customized requirements
********************************************************************************
* Version: 3.21
* Author/Date: LiX/2023.5.15
* Change: Add the sub-state machine PRE_FULLCOM.
* Cause: Add Function.
********************************************************************************
* Version: 3.22
* Author/Date: TianG/2023.8.10
* Change: Clear warning.
* Cause: Optimization
********************************************************************************
* Version: 3.23
* Author/Date: TianL/2023.11.27
* Change: Add a else when BusOff fails to set PDU mode to CANIF_ONLINE mode, 
*         reset the CAN controller state to CANIF_CS_STARTED state.
* Cause: Bugifx
********************************************************************************
* Version: 3.24
* Author/Date: TianL/2024.1.11
* Change: When BusOff resumes, ComM_BusSM_ModeIndication is called to set ComMode
*         to COMM_FULL_COMMUNICATION.
* Cause: Update
********************************************************************************
* Version: 3.25
* Author/Date: TianL/2024.1.12
* Change: Modify ControllerId to ComMNetworkHandle in ComM_BusSM_ModeIndication.
* Cause: Bugfix
********************************************************************************
* Version: 3.26
* Author/Date: TianL/2024.1.30
* Change: 1.Add the maximum number of repetitions function in PRE_NOCOM state,
*           PRE_FULLCOM state and CHANGE_BAUDRATE state.
*         2.Add the sub-state CanSM_S_CHANGE_BR_STOP_CC_WAIT in CanSM_Bsm_ChangeBR.
* Cause: Bugfix
********************************************************************************
* Version: 3.27
* Author/Date: TianL/2024.2.1
* Change: Modify an issue which the baudrate can only be set once.
* Cause: Bugfix
********************************************************************************
* Version: 3.28
* Author/Date: TianL/2024.3.20
* Change: 1.Add the sub-state machine SILENTCOM_BOR.
*         2.Add SILENTCOM to SILENTCOM_BOR in CanSM_Bsm_SILENTCOM.
* Cause: Update
********************************************************************************
* Version: 3.29
* Author/Date: TianL/2024.4.1
* Change: Modify the sub state machine jump order of CHANGE_BAUDRATE state.
* Cause: Bugfix
********************************************************************************
* Version: 3.30
* Author/Date: TianL/2024.5.15
* Change: 1. Add a MemMap paragraph definition to the function declaration.
*         2. Modify coding specifications.
* Cause: Optimize
********************************************************************************
* Version: 3.31
* Author/Date: TianL/2024.8.5
* Change: 1. Modify sub state machine transitions in all state machines.
*         2. Modify copyright information.
* Cause: Optimize
********************************************************************************
* Version: 3.32
* Author/Date: TianL/2024.8.30
* Change: Modify CanSM state machine transitions in CanSM_Bsm_Process.
* Cause: Optimize
********************************************************************************
* Version: 3.33
* Author/Date: TianL/2024.9.14
* Change: Add the sub-state machine TX_TIMEOUT_EXCEPTION of FULLCOM.
* Cause: Optimize
********************************************************************************
* Version: 3.34
* Author/Date: TianL/2024.9.23
* Change: Fix compile warning.
* Cause: Optimize
********************************************************************************
* Version: 3.35
* Author/Date: TianL/2024.9.25
* Change: Modify the logic of busoff status polling.
* Cause: Optimize
********************************************************************************
* Version: 3.36
* Author/Date: TianL/2024.12.16
* Change: Add the macro switch for using BswM_CanSM_CurrentState.
* Cause: Bugfix
********************************************************************************
* Version: 3.37
* Author/Date: TianL/2025.2.24
* Change: Change where to call BswM_CanSM_CurrentState and ComM_BusSM_ModeIndication
*         when BusOff recovers.
* Cause: Bugfix
********************************************************************************
* Version: 3.38
* Author/Date: TianL/2025.3.27
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Bugfix
********************************************************************************
* Version: 3.39
* Author/Date: TianL/2025.6.8
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.40
* Author/Date: TianL/2025.8.1
* Change: Add the initialization operation for BusOffDTC.
* Cause: Bugfix
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "CanSM.h"

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
*    Local Variables
********************************************************************************
*/
#define CANSM_START_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanSM_MemMap.h"

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanSM_UsedNonSharedVariable" */
static VAR(CanSM_StateType, CANSM_VAR_INIT) CanSM_InitFlag = CANSM_UNINITED; /* Trigger: CanSM_Init */
#if( CANSM_REPORT_DEM_ENABLE == STD_ON )
static VAR(boolean, CANSM_VAR_INIT) CanSM_BusOffDTCReported = FALSE;
#endif  /* CANSM_REPORT_DEM_ENABLE == STD_ON */

#define CANSM_STOP_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define CANSM_START_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanSM_UsedNonSharedVariable" */
static VAR(CanSM_BsmChnType, CANSM_VAR_NO_INIT) CanSM_BsmChn[CANSM_MANAGER_NW_NUM];

#define CANSM_STOP_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#define CANSM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

static FUNC(void, CANSM_CODE) CanSM_Bsm_Process
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_Bsm_NOT_INITIALIZED
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_Bsm_PRE_NOCOM
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_Bsm_WUVALIDATION
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_Bsm_PRE_FULLCOM
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_Bsm_FULLCOM
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);

#if( CANSM_SET_BAUDRATE_API == STD_ON )
static FUNC(void, CANSM_CODE) CanSM_Bsm_ChangeBR
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
#endif  /* CANSM_SET_BAUDRATE_API == STD_ON */

static FUNC(void, CANSM_CODE) CanSM_Bsm_SILENTCOM
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_Bsm_SILENTCOM_BOR
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_Bsm_SILENTCOM_BOR_RESTART
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_Bsm_SILENTCOM_BOR_RESTART_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);  /* PRQA S 779 */ /* NSCA_QAC_Common_IdentifierLength */
static FUNC(void, CANSM_CODE) CanSM_Bsm_NOCOM
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_FULLCOM_BUS_OFF_CHECK
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_FULLCOM_RESTART_CC
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_FULLCOM_RESTART_CC_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_FULLCOM_TX_OFF
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_FULLCOM_TX_TIMEOUT_EXCEPTION
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_WU_TRCV_NORMAL
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_WU_TRCV_NORMAL_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_WU_CC_STOPPED
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_WU_CC_STOPPED_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_WU_CC_STARTED
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_WU_CC_STARTED_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_WU_WAIT_LEAVE
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);

#if( CANSM_SET_BAUDRATE_API == STD_ON )
static FUNC(void, CANSM_CODE) CanSM_S_CHANGE_BR_STOP_CC
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_CHANGE_BR_STOP_CC_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_CHANGE_BR_SYNC
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_CHANGE_BR_START_CC
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_CHANGE_BR_START_CC_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
#endif  /* CANSM_SET_BAUDRATE_API == STD_ON */

static FUNC(void, CANSM_CODE) CanSM_Det_ErrorReport
(
    uint8 ApiId,
    uint8 errorId
);
static FUNC(Std_ReturnType, CANSM_CODE) CanSM_SearchIdxByNetWork
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
    NetworkHandleType network,
    P2VAR(uint8, AUTOMATIC, CANSM_APPL_DATA) IndexPtr
);
static FUNC(Std_ReturnType, CANSM_CODE) CanSM_SearchIdxByControllerId
(
    uint8 ControllerId,
    P2VAR(uint8, AUTOMATIC, CANSM_APPL_DATA) IndexPtr
);
static FUNC(Std_ReturnType, CANSM_CODE) CanSM_SearchIdxByTransceiverId
(
    uint8 TransceiverId,
    P2VAR(uint8, AUTOMATIC, CANSM_APPL_DATA) IndexPtr
);
static FUNC(void, CANSM_CODE) CanSM_Bsm_PreNoCom_SubState_Init
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
#if( CANSM_CANTRCV_PN_SUPPORT == STD_ON )
static FUNC(void, CANSM_CODE) CanSM_Bsm_DeinitPnSupported
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_CLEAR_WUF
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_CLEAR_WUF_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_CC_STOPPED
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_CC_STOPPED_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_TRCV_NORMAL
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_TRCV_NORMAL_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_TRCV_STANDBY
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_TRCV_STANDBY_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_CC_SLEEP
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_CC_SLEEP_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_CHECK_WFLAG_IN_CC_SLEEP
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_CHECK_WUF_IN_CC_SLEEP_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_CHECK_WFLAG_IN_NOT_CC_SLEEP
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_CHECK_WUF_IN_NOT_CC_SLEEP_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
#endif  /* CANSM_CANTRCV_PN_SUPPORT == STD_ON */
static FUNC(void, CANSM_CODE) CanSM_Bsm_DeinitPnNotSupported
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_CC_STOPPED
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_CC_STOPPED_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_CC_SLEEP
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_CC_SLEEP_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_TRCV_NORMAL
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_TRCV_NORMAL_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_TRCV_STANDBY
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_TRCV_STANDBY_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_PNC_Exit
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_TRCV_NORMAL
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_TRCV_NORMAL_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_CC_STOPPED
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_CC_STOPPED_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_CC_STARTED
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_CC_STARTED_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_TX_TIMEOUT_EXCEPTION_S_CC_STOPPED
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);
static FUNC(void, CANSM_CODE) CanSM_S_TX_TIMEOUT_EXCEPTION_S_CC_STOPPED_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);  /* PRQA S 779 */ /* NSCA_QAC_Common_IdentifierLength */
static FUNC(void, CANSM_CODE) CanSM_S_TX_TIMEOUT_EXCEPTION_S_CC_STARTED
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);  /* PRQA S 779 */ /* NSCA_QAC_Common_IdentifierLength */
static FUNC(void, CANSM_CODE) CanSM_S_TX_TIMEOUT_EXCEPTION_S_CC_STARTED_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
);  /* PRQA S 779 */ /* NSCA_QAC_Common_IdentifierLength */

#define CANSM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#define CANSM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
* Function Name: CanSM_Init
*
* Explanation: This service initializes the CanSM module.
*              (Synchronous)
*
* param: ConfigPtr: Pointer to init structure for the post build parameters of the CanSM.
*
* retval: None
********************************************************************************
*/
FUNC(void, CANSM_CODE) CanSM_Init
(
    P2CONST(CanSM_ConfigType, AUTOMATIC, CANSM_APPL_CONST) ConfigPtr
)
{
    uint8 index;

    CANSM_DUMMY_STATEMENT(ConfigPtr);
    for( index = CANSM_VALUE_ZERO; index < CANSM_MANAGER_NW_NUM; index++ )
    {
        /* Initialize the variables related to state machine of the CanSM module. */
        CanSM_BsmChn[index].ManagerNetworkPtr = &CanSM_ManagerNetworkCfg[index];
        CanSM_BsmChn[index].BsmSta = CANSM_BSM_S_PRE_NOCOM;
        CanSM_Bsm_PreNoCom_SubState_Init(&CanSM_BsmChn[index]);
        CanSM_BsmChn[index].BsmTrg_WAKEUP_SOURCE = CANSM_T_START_WAKEUP_SOURCE;
        CanSM_BsmChn[index].BsmTrg_MODE_REQUEST = COMM_NO_COMMUNICATION;
        CanSM_BsmChn[index].BsmTrg_BUS_OFF = CANSM_T_NOT_BUS_OFF;
        CanSM_BsmChn[index].Bsm_E_CanIfMode = CANIF_OFFLINE;
        CanSM_BsmChn[index].BsmTrg_ControllerMode = CANSM_T_CC_NO_INDICATED;
        CanSM_BsmChn[index].BsmTrg_TransceiverMode = CANSM_T_TRCV_NO_IDC;
        CanSM_BsmChn[index].BsmTrg_TxTimeout = CANSM_T_NOT_TXTIMEOUT;
        CanSM_BsmChn[index].Trg_ClearWUF_Indication = CANSM_T_CLEAR_WUF_NO_IDC;
        CanSM_BsmChn[index].Trg_CheckWF_Indication = CANSM_T_CHECK_WFLAG_NO_IDC;
        CanSM_BsmChn[index].Bsm_TaskCycCnt_BUSOFF = CANSM_VALUE_ZERO;
        CanSM_BsmChn[index].Bsm_RecCnt_BUS_OFF = CANSM_VALUE_ZERO;
        CanSM_BsmChn[index].changeBRId = CANSM_NO_CHANGE_BR_REQ;
        CanSM_BsmChn[index].changeBRIdRequest = CANSM_T_NOT_CHANGE_BR_REQUEST;
#if( CANSM_REPORT_DEM_ENABLE == STD_ON )
        CanSM_BusOffDTCReported = FALSE;
#endif  /* CANSM_REPORT_DEM_ENABLE == STD_ON */
        /* Sub Bsm not Init. */
    }

    /* Successful initialization. */
    CanSM_InitFlag = CANSM_INITED;

}

/*
********************************************************************************
* Function Name: CanSM_RequestComMode
*
* Explanation: This service shall change the communication mode of a CAN
*              network to the requested one.
*              (Asynchronous)
*
* param: network: Handle of destined communication network for request.
*        ComM_Mode: Requested communication mode.
*
* retval: E_OK: Service accepted.
*         E_NOT_OK: Service denied.
********************************************************************************
*/
FUNC(Std_ReturnType, CANSM_CODE) CanSM_RequestComMode
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
    NetworkHandleType network,
    ComM_ModeType ComM_Mode
)
{
    uint8 errorId = CANSM_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;
    uint8 index = CANSM_VALUE_ZERO;

    /* Checking for development errors. */
    if( CANSM_INITED != CanSM_InitFlag )
    {
        errorId = CANSM_E_UNINIT;
    }
    else if( E_NOT_OK == CanSM_SearchIdxByNetWork(network, &index) )
    {
        errorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
    else if( ComM_Mode > COMM_FULL_COMMUNICATION )
    {
        errorId = CANSM_E_INVALID_COMM_REQUEST;
    }
    else
    {
        /* Buffer the ComM mode request. */
        CanSM_BsmChn[index].BsmTrg_MODE_REQUEST = ComM_Mode;
        stdRet = E_OK;
    }
    CanSM_Det_ErrorReport(CANSM_SERVICEID_REQUESTCOMMODE, errorId);

    return stdRet;
}

/*
********************************************************************************
* Function Name: CanSM_GetCurrentComMode
*
* Explanation: This service shall put out the current communication mode of a
*              CAN network.
*              (Synchronous)
*
* param: network: Network handle, whose current communication mode shall be put out.
*        ComM_ModePtr: Pointer, where to put out the current communication mode.
*
* retval: E_OK: Service accepted.
*         E_NOT_OK: Service denied.
********************************************************************************
*/
FUNC(Std_ReturnType, CANSM_CODE) CanSM_GetCurrentComMode
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
    NetworkHandleType network,
    P2VAR(ComM_ModeType, AUTOMATIC, CANSM_APPL_DATA) ComM_ModePtr
)
{
    uint8 errorId = CANSM_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;
    uint8 index = CANSM_VALUE_ZERO;

    /* Checking for development errors. */
    if( CANSM_INITED != CanSM_InitFlag )
    {
        errorId = CANSM_E_UNINIT;
    }
    else if( E_NOT_OK == CanSM_SearchIdxByNetWork(network, &index) )
    {
        errorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
    else if( NULL_PTR == ComM_ModePtr )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CANSM_E_PARAM_POINTER;
    }
    else
    {
        /* Evaluate the ComM mode according to state machine of the CanSM module. */
        if( CANSM_BSM_S_FULLCOM == CanSM_BsmChn[index].BsmSta )
        {
            /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanSM_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.14" */
            *ComM_ModePtr = COMM_FULL_COMMUNICATION;
        }
        else if( CANSM_BSM_S_SILENTCOM == CanSM_BsmChn[index].BsmSta )
        {
            /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanSM_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.14" */
            *ComM_ModePtr = COMM_SILENT_COMMUNICATION;
        }
        else if( CANSM_BSM_S_SILENTCOM_BOR == CanSM_BsmChn[index].BsmSta )
        {
            /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanSM_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.14" */
            *ComM_ModePtr = COMM_SILENT_COMMUNICATION;
        }
        else
        {
            /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanSM_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.14" */
            *ComM_ModePtr = COMM_NO_COMMUNICATION;
        }
        stdRet = E_OK;
    }

    CanSM_Det_ErrorReport(CANSM_SERVICEID_GETCURCOMMODE, errorId);

    return stdRet;
}

/*
********************************************************************************
* Function Name: CanSM_StartWakeupSource
*
* Explanation: This function shall be called by EcuM when a wakeup source shall
*              be started.
*              (Synchronous)
*
* param: network: Affected CAN network.
*
* retval: E_OK: Request accepted.
*         E_NOT_OK: Request denied.
********************************************************************************
*/
FUNC(Std_ReturnType, CANSM_CODE) CanSM_StartWakeupSource
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
    NetworkHandleType network
)
{
    uint8 errorId = CANSM_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;
    uint8 index = CANSM_VALUE_ZERO;

    /* Checking for development errors. */
    if( CANSM_INITED != CanSM_InitFlag )
    {
        errorId = CANSM_E_UNINIT;
    }
    else if( E_NOT_OK == CanSM_SearchIdxByNetWork(network, &index) )
    {
        errorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
    else
    {
        /* Set the trigger of starting wake up source. */
        CanSM_BsmChn[index].BsmTrg_WAKEUP_SOURCE = CANSM_T_START_WAKEUP_SOURCE;
        stdRet= E_OK;
    }

    CanSM_Det_ErrorReport(CANSM_SERVICEID_STARTWKUPSOURCE, errorId);

    return stdRet;
}

/*
********************************************************************************
* Function Name: CanSM_StopWakeupSource
*
* Explanation: This function shall be called by EcuM when a wakeup source shall
*              be stopped.
*              (Synchronous)
*
* param: network: Affected CAN network.
*
* retval: E_OK: Request accepted.
*         E_NOT_OK: Request denied.
********************************************************************************
*/
FUNC(Std_ReturnType, CANSM_CODE) CanSM_StopWakeupSource
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
    NetworkHandleType network
)
{
    uint8 errorId = CANSM_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;
    uint8 index = CANSM_VALUE_ZERO;

    /* Checking for development errors. */
    if( CANSM_INITED != CanSM_InitFlag )
    {
        errorId = CANSM_E_UNINIT;
    }
    else if( E_NOT_OK == CanSM_SearchIdxByNetWork(network, &index) )
    {
        errorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
    else
    {
        /* Set the trigger of stopped wake up source. */
        CanSM_BsmChn[index].BsmTrg_WAKEUP_SOURCE = CANSM_T_STOP_WAKEUP_SOURCE;
        stdRet= E_OK;
    }

    CanSM_Det_ErrorReport(CANSM_SERVICEID_STOPWKUPSOURCE, errorId);

    return stdRet;
}

/*
********************************************************************************
* Function Name: CanSM_GetVersionInfo
*
* Explanation: This service puts out the version information of this module
*              (module ID, vendor ID, vendor specific version numbers related to
*              BSW00407).
*              (Synchronous)
*
* param: VersionInfo: Pointer to where to store the version information of this module.
*
* retval: None
********************************************************************************
*/
#if( CANSM_VERSION_INFO_API == STD_ON )
FUNC(void, CANSM_CODE) CanSM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CANSM_APPL_DATA) VersionInfo
)
{
    uint8 errorId = CANSM_E_NO_ERR;

    /* Checking for development errors. */
    if( NULL_PTR == VersionInfo )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CANSM_E_PARAM_POINTER;
    }
    else
    {
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanSM_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.14" */
        VersionInfo->vendorID = CANSM_VENDOR_ID;
        VersionInfo->moduleID = CANSM_MODULE_ID;
        VersionInfo->sw_major_version = CANSM_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = CANSM_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = CANSM_SW_PATCH_VERSION;
    }

    CanSM_Det_ErrorReport(CANSM_SERVICEID_GETVERSIONINFO, errorId);
}
#endif  /* CANSM_VERSION_INFO_API == STD_ON */
/*
********************************************************************************
* Function Name: CanSM_SetBaudrate
*
* Explanation: This service shall start an asynchronous process to change the
*              baud rate for the configured CAN controllers of a certain CAN network.
*              Depending on necessary baud rate modifications the controllers might
*              have to reset.
*              (Synchronous)
*
* param: Network: Handle of the addressed CAN network for the baud rate change.
*        BaudRateConfigID: references a baud rate configuration by ID
*                          (see CanControllerBaudRateConfigID).
*
* retval: E_OK: Service request accepted, setting of (new) baudrate started.
*         E_NOT_OK: Service request not accepted.
********************************************************************************
*/
#if( CANSM_SET_BAUDRATE_API == STD_ON )
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
FUNC(Std_ReturnType, CANSM_CODE) CanSM_SetBaudrate(NetworkHandleType Network, uint16 BaudRateConfigID)
{
    uint8 errorId = CANSM_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;
    uint8 index = CANSM_VALUE_ZERO;

    /* Checking for development errors. */
    if( CANSM_INITED != CanSM_InitFlag )
    {
        errorId = CANSM_E_UNINIT;
    }
    else if( E_NOT_OK == CanSM_SearchIdxByNetWork(Network, &index) )
    {
        errorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
    else if( CANSM_BSM_S_FULLCOM != CanSM_BsmChn[index].BsmSta )
    {
        /* Deny its request,if the requested CAN network is not in COMM_FULL_COMMUNICATION. */
    }
    else
    {
        /* polyspace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule10.4" */
        if( (CANSM_NO_CHANGE_BR_REQ == CanSM_BsmChn[index].changeBRId)
            || (BaudRateConfigID != CanSM_BsmChn[index].changeBRId) )
        {
            /* Set the trigger of setting baudrate. */
            CanSM_BsmChn[index].changeBRId = BaudRateConfigID;
            CanSM_BsmChn[index].changeBRIdRequest = CANSM_T_CHANGE_BR_REQUEST;
            stdRet = E_OK;
        }
    }
    CanSM_Det_ErrorReport(CANSM_SERVICEID_SETBAUDRATE, errorId);
    return stdRet;
}
#endif  /* CANSM_SET_BAUDRATE_API == STD_ON */

/*
********************************************************************************
* Function Name: CanSM_SetIcomConfiguration
*
* Explanation: This service shall change the Icom Configuration of a CAN network to the
*              requested one.
*              (Asynchronous)
*
* param: Network: Handle of destined communication network for request.
*        ConfigurationId: Requested Configuration.
*
* retval: E_OK: Request accepted.
*         E_NOT_OK: Request denied.
********************************************************************************
*/
FUNC(Std_ReturnType, CANSM_CODE) CanSM_SetIcomConfiguration
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
    NetworkHandleType Network,
    IcomConfigIdType ConfigurationId
)
{
    uint8 errorId = CANSM_E_NO_ERR;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanSM_UNMODIFIED_VAR_NOT_CONST" */
    Std_ReturnType stdRet = E_NOT_OK;
    uint8 index = CANSM_VALUE_ZERO;

    /* Checking for development errors. */
    if( CANSM_INITED != CanSM_InitFlag )
    {
        errorId = CANSM_E_UNINIT;
    }
    else if( E_NOT_OK == CanSM_SearchIdxByNetWork(Network, &index) )
    {
        errorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
    else
    {
        /* Set Icom Configuration by calling the API CanIf_SetIcomConfiguration. */
#ifdef CANSM_NOTUSED
        stdRet = CanIf_SetIcomConfiguration(CanSM_BsmChn[index].ManagerNetworkPtr->ControllerId, ConfigurationId);
#endif  /* CANSM_NOTUSED */
        CANSM_DUMMY_STATEMENT(ConfigurationId);
    }

    CanSM_Det_ErrorReport(CANSM_SERVICEID_SETICOMCFG, errorId);

    return stdRet;
}

#if( CANSM_TXOFFLINE_ACT_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: CanSM_SetEcuPassive
*
* Explanation: This function can be used to set all CanSM channels of the ECU to
*              a receive only mode. This mode will be kept either until it is
*              set back, or the ECU is reset.
*              (Synchronous)
*
* param: CanSM_Passive: TRUE: set all CanSM channels to passive, i.e. receive only.
*                       FALSE: set all CanSM channels back to non-passive.
*
* retval: E_OK: Request accepted.
*         E_NOT_OK: Request not accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, CANSM_CODE) CanSM_SetEcuPassive
(
    boolean CanSM_Passive
)
{
    uint8 errorId = CANSM_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;
    Std_ReturnType canIf_stdRet;
    uint8 managerNWcnt;
    CanIf_PduModeType pduMode[CANSM_MANAGER_NW_NUM] = {CANIF_OFFLINE};

    /* Checking for development errors. */
    if( CANSM_INITED != CanSM_InitFlag )
    {
        errorId = CANSM_E_UNINIT;
    }
    else if( TRUE == CanSM_Passive )
    {
        /* If the network is CANIF_ONLINE, change the status to CANIF_TX_OFFLINE_ACTIVE. */
        for( managerNWcnt = CANSM_VALUE_ZERO; managerNWcnt < CANSM_MANAGER_NW_NUM; managerNWcnt++ )
        {
            canIf_stdRet = CanIf_GetPduMode(managerNWcnt, &pduMode[managerNWcnt]);
            if( E_OK == canIf_stdRet )
            {
                if( CANIF_ONLINE == pduMode[managerNWcnt] )
                {
                    /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" polyspace +1 DEFECT:USELESS_WRITE [Justified:Unset] "NSCA_Polyspace_CanSM_USELESS_WRITE" */
                    canIf_stdRet = CanIf_SetPduMode(managerNWcnt, CANIF_TX_OFFLINE_ACTIVE);
                }
            }
        }
        stdRet = E_OK;
    }
    else
    {
        /* If the network is CANIF_TX_OFFLINE_ACTIVE, change the status to CANIF_ONLINE. */
        for( managerNWcnt = CANSM_VALUE_ZERO; managerNWcnt < CANSM_MANAGER_NW_NUM; managerNWcnt++ )
        {
            canIf_stdRet = CanIf_GetPduMode(managerNWcnt, &pduMode[managerNWcnt]);
            if( E_OK == canIf_stdRet )
            {
                if( CANIF_TX_OFFLINE_ACTIVE == pduMode[managerNWcnt] )
                {
                    /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" polyspace +1 DEFECT:USELESS_WRITE [Justified:Unset] "NSCA_Polyspace_CanSM_USELESS_WRITE" */
                    canIf_stdRet = CanIf_SetPduMode(managerNWcnt, CANIF_ONLINE);
                }
            }
        }
        stdRet = E_OK;
    }

    CanSM_Det_ErrorReport(CANSM_SERVICEID_SETECUPASSIVE, errorId);

    return stdRet;
}
#endif  /* CANSM_TXOFFLINE_ACT_SUPPORT == STD_ON */

/*
********************************************************************************
* Function Name: CanSM_ControllerBusOff
*
* Explanation: This callback function notifies the CanSM about a bus-off event
*              on a certain CAN controller, which needs to be considered with
*              the specified bus-off recovery handling for the impacted CAN network.
*              (Synchronous)
*
* param: ControllerId: CAN controller, which detected a bus-off event.
*
* retval: None
********************************************************************************
*/
FUNC(void, CANSM_CODE) CanSM_ControllerBusOff
(
    uint8 ControllerId
)
{
    uint8 errorId = CANSM_E_NO_ERR;
    uint8 index = CANSM_VALUE_ZERO;

    /* Checking for development errors. */
    if( CANSM_INITED != CanSM_InitFlag )
    {
        errorId = CANSM_E_UNINIT;
    }
    else if( E_NOT_OK == CanSM_SearchIdxByControllerId(ControllerId, &index) )
    {
        errorId = CANSM_E_PARAM_CONTROLLER;
    }

#ifdef CANSM_OSEKNM_ENABLE
    else if( D_OSEK_CAN_CONTROLLERID == ControllerId )
    {
        /* 1 means busoff */
        OsekNM_HandleDStatus(D_OSEK_CAN_BUSOFF);
        /* 0 means wakeup */
    }
#endif  /* CANSM_OSEKNM_ENABLE */

    else
    {
        /* Set the trigger of bus off status. */
        CanSM_BsmChn[index].BsmTrg_BUS_OFF = CANSM_T_BUS_OFF;
        /* Set the trigger of indication of CAN controller mode. */
        CanSM_BsmChn[index].BsmTrg_ControllerMode = CANSM_T_CC_STOPPED_INDICATED;
    }

    CanSM_Det_ErrorReport(CANSM_SERVICEID_CTRLBUSOFF, errorId);
}

/*
********************************************************************************
* Function Name: CanSM_ControllerModeIndication
*
* Explanation: This callback shall notify the CanSM module about a CAN controller mode
*              change.
*              (Synchronous)
*
* param: ControllerId: CAN controller, whose mode has changed.
*        ControllerMode: Notified CAN controller mode.
*
* retval: None
********************************************************************************
*/
FUNC(void, CANSM_CODE) CanSM_ControllerModeIndication
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
)
{
    uint8 errorId = CANSM_E_NO_ERR;
    uint8 index = CANSM_VALUE_ZERO;

    /* Checking for development errors. */
    if( CANSM_INITED != CanSM_InitFlag )
    {
        errorId = CANSM_E_UNINIT;
    }
    else if( E_NOT_OK == CanSM_SearchIdxByControllerId(ControllerId, &index) )
    {
        errorId = CANSM_E_PARAM_CONTROLLER;
    }
    else
    {
        /* Evaluate the indication of CAN controller mode according to the CanIf_ControllerModeType. */
        if( CANIF_CS_STARTED == ControllerMode )
        {
            CanSM_BsmChn[index].BsmTrg_ControllerMode = CANSM_T_CC_STARTED_INDICATED;
        }
        else if( CANIF_CS_STOPPED == ControllerMode )
        {
            CanSM_BsmChn[index].BsmTrg_ControllerMode = CANSM_T_CC_STOPPED_INDICATED;
        }
        else if( CANIF_CS_SLEEP == ControllerMode )
        {
            CanSM_BsmChn[index].BsmTrg_ControllerMode = CANSM_T_CC_SLEEP_INDICATED;
        }
        else
        {
            CanSM_BsmChn[index].BsmTrg_ControllerMode = CANSM_T_CC_NO_INDICATED;
        }
    }
    CanSM_Det_ErrorReport(CANSM_SERVICEID_CTRLMODEINDC, errorId);
}

/*
********************************************************************************
* Function Name: CanSM_TransceiverModeIndication
*
* Explanation: This callback shall notify the CanSM module about a CAN transceiver mode
*              change.
*              (Synchronous)
*
* param: TransceiverId: CAN transceiver, whose mode has changed.
*        TransceiverMode: Notified CAN transceiver mode.
*
* retval: None
********************************************************************************
*/
FUNC(void, CANSM_CODE) CanSM_TransceiverModeIndication
(
    uint8 TransceiverId,
    CanTrcv_TrcvModeType TransceiverMode
)
{
    uint8 errorId = CANSM_E_NO_ERR;
    uint8 index = CANSM_VALUE_ZERO;

    /* Checking for development errors. */
    if( CANSM_INITED != CanSM_InitFlag )
    {
        errorId = CANSM_E_UNINIT;
    }
    else if( E_NOT_OK == CanSM_SearchIdxByTransceiverId(TransceiverId, &index) )
    {
        errorId = CANSM_E_PARAM_TRANSCEIVER;
    }
    /* Make sure that this network configure the transceiver. */
    else if( TRUE == CanSM_BsmChn[index].ManagerNetworkPtr->TransceiverEnable )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Set indication status according to transceiver mode. */
        if( CANTRCV_TRCVMODE_NORMAL == TransceiverMode )
        {
            CanSM_BsmChn[index].BsmTrg_TransceiverMode = CANSM_T_TRCV_NORMAL_IDC;
        }
        else if( CANTRCV_TRCVMODE_SLEEP == TransceiverMode )
        {
            CanSM_BsmChn[index].BsmTrg_TransceiverMode = CANSM_T_TRCV_SLEEP_IDC;
        }
        else
        {
            CanSM_BsmChn[index].BsmTrg_TransceiverMode = CANSM_T_TRCV_STANDBY_IDC;
        }
    }
    else
    {
        /* Do nothing. */
    }

    CanSM_Det_ErrorReport(CANSM_SERVICEID_TRCVMODEINDC, errorId);
}

/*
********************************************************************************
* Function Name: CanSM_TxTimeoutException
*
* Explanation: This function shall notify the CanSM module, that the CanNm has
*              detected for the affected partial CAN network a tx timeout exception,
*              which shall be recovered within the respective network state machine
*              of the CanSM module.
*              (Synchronous)
*
* param: Channel: Affected CAN network.
*
* retval: None
********************************************************************************
*/
FUNC(void, CANSM_CODE) CanSM_TxTimeoutException
(
    NetworkHandleType Channel
)
{
    uint8 errorId = CANSM_E_NO_ERR;
    uint8 index = CANSM_VALUE_ZERO;

    /* Checking for development errors. */
    if( CANSM_INITED != CanSM_InitFlag )
    {
        errorId = CANSM_E_UNINIT;
    }
    else if( E_NOT_OK == CanSM_SearchIdxByNetWork(Channel, &index) )
    {
        errorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
    else
    {
        /* Set the trigger of CANSM_T_TXTIMEOUT. */
        CanSM_BsmChn[index].BsmTrg_TxTimeout = CANSM_T_TXTIMEOUT;
    }

    CanSM_Det_ErrorReport(CANSM_SERVICEID_TXTIMEOUTEXC, errorId);
}

/*
********************************************************************************
* Function Name: CanSM_ClearTrcvWufFlagIndication
*
* Explanation: This callback function shall indicate the CanIf_ClearTrcvWufFlag
*              API process end for the notified CAN Transceiver.
*              (Synchronous)
*
* param: Transceiver: Requested Transceiver.
*
* retval: None
********************************************************************************
*/
FUNC(void, CANSM_CODE) CanSM_ClearTrcvWufFlagIndication
(
    uint8 Transceiver
)
{
    /* This function is not implemented in the current version. */
    uint8 errorId = CANSM_E_NO_ERR;
    uint8 index = CANSM_VALUE_ZERO;

    /* Checking for development errors. */
    if( CANSM_INITED != CanSM_InitFlag )
    {
        errorId = CANSM_E_UNINIT;
    }
    else if( E_NOT_OK == CanSM_SearchIdxByTransceiverId(Transceiver, &index) )
    {
        errorId = CANSM_E_PARAM_TRANSCEIVER;
    }
    else if( TRUE == CanSM_BsmChn[index].ManagerNetworkPtr->TransceiverEnable )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* SWS_CanSM_00440 */
        CanSM_BsmChn[index].Trg_ClearWUF_Indication = CANSM_T_CLEAR_WUF_INDICATED;
    }
    else
    {
        /* Do notting. */
    }

    CanSM_Det_ErrorReport(CANSM_SERVICEID_CLEARTRCVWUFLAGINDC, errorId);
}

/*
********************************************************************************
* Function Name: CanSM_CheckTransceiverWakeFlagIndication
*
* Explanation: This callback function indicates the CheckTransceiverWakeFlag
*              API process end for the notified CAN Transceiver.
*              (Synchronous)
*
* param: Transceiver: Requested Transceiver.
*
* retval: None
********************************************************************************
*/
FUNC(void, CANSM_CODE) CanSM_CheckTransceiverWakeFlagIndication
(
    uint8 Transceiver
)
{
    /* This function is not implemented in the current version. */
    uint8 errorId = CANSM_E_NO_ERR;
    uint8 index = CANSM_VALUE_ZERO;

    /* Checking for development errors. */
    if( CANSM_INITED != CanSM_InitFlag )
    {
        errorId = CANSM_E_UNINIT;
    }
    else if( E_NOT_OK == CanSM_SearchIdxByTransceiverId(Transceiver, &index) )
    {
        errorId = CANSM_E_PARAM_TRANSCEIVER;
    }
    else if( TRUE == CanSM_BsmChn[index].ManagerNetworkPtr->TransceiverEnable )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* SWS_CanSM_00460 */
        CanSM_BsmChn[index].Trg_CheckWF_Indication = CANSM_T_CHECK_WFLAG_INDICATED;
    }
    else
    {
        /* Do nothing. */
    }

    CanSM_Det_ErrorReport(CANSM_SERVICEID_CLECKTRCVWKFLAGINDC, errorId);
}

/*
********************************************************************************
* Function Name: CanSM_ConfirmPnAvailability
*
* Explanation: This callback function indicates that the transceiver is running in PN
*              communication mode.
*              (Synchronous)
*
* param: TransceiverId: CAN transceiver, which was checked for PN availability.
*
* retval: None
********************************************************************************
*/
FUNC(void, CANSM_CODE) CanSM_ConfirmPnAvailability
(
    uint8 TransceiverId
)
{
    /* This function is not implemented in the current version. */
    uint8 errorId = CANSM_E_NO_ERR;
    uint8 index = CANSM_VALUE_ZERO;

    /* Checking for development errors */
    if( CANSM_INITED != CanSM_InitFlag )
    {
        errorId = CANSM_E_UNINIT;
    }
    else if( E_NOT_OK == CanSM_SearchIdxByTransceiverId(TransceiverId, &index) )
    {
        errorId = CANSM_E_PARAM_TRANSCEIVER;
    }
    else if( TRUE == CanSM_BsmChn[index].ManagerNetworkPtr->TransceiverEnable )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
#ifdef CANSM_NOTUSED
        CanNm_ConfirmPnAvailability(TransceiverId);
#endif  /* CANSM_NOTUSED */
    }
    else
    {
        /* Do nothing. */
    }

    CanSM_Det_ErrorReport(CANSM_SERVICEID_CFMPNAVAILABLILITY, errorId);
}

/*
********************************************************************************
* Function Name: CanSM_CurrentIcomConfiguration
*
* Explanation: This service shall inform about the change of the Icom Configuration
*              of a CAN network.
*              (Synchronous)
*
* param: ControllerId: CAN Controller Id, whose configuration has changed.
*        ConfigurationId: Changed Configuration Id.
*        Error: ICOM_SWITCH_E_OK: No Error.
*               ICOM_SWITCH_E_FAILED: Switch to requested Configuration failed.
*               Severe Error.
*
* retval: None
********************************************************************************
*/
FUNC(void, CANSM_CODE) CanSM_CurrentIcomConfiguration
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId,
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
    IcomSwitch_ErrorType Error
)
{
    /* This function is not implemented in the current version. */
    uint8 errorId = CANSM_E_NO_ERR;
    uint8 index = CANSM_VALUE_ZERO;

    /* Checking for development errors. */
    if( CANSM_INITED != CanSM_InitFlag )
    {
        errorId = CANSM_E_UNINIT;
    }
    else if( E_NOT_OK == CanSM_SearchIdxByControllerId(ControllerId, &index) )
    {
        errorId = CANSM_E_PARAM_CONTROLLER;
    }
    else
    {
#ifdef CANSM_NOTUSED
        BswM_CanSM_CurrentIcomConfiguration(ControllerId, ConfigurationId, Error);
#endif  /* CANSM_NOTUSED */
        CANSM_DUMMY_STATEMENT(ControllerId);
        CANSM_DUMMY_STATEMENT(ConfigurationId);
        CANSM_DUMMY_STATEMENT(Error);
    }

    CanSM_Det_ErrorReport(CANSM_SERVICEID_CURICOMCFG, errorId);
}

/*
********************************************************************************
* Function Name: CanSM_MainFunction
*
* Explanation: Scheduled function of the CanSM.
*              (Synchronous)
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, CANSM_CODE) CanSM_MainFunction
(
    void
)
{
    uint8 errorId = CANSM_E_NO_ERR;
    uint8 index;
    Std_ReturnType stdRet;

    /* Checking for development errors. */
    if( CANSM_INITED != CanSM_InitFlag )
    {
        errorId = CANSM_E_UNINIT;
    }
    else
    {
        /* Do state machine processing according to network status. */
        for( index = CANSM_VALUE_ZERO; index < CANSM_MANAGER_NW_NUM; index++ )
        {

#ifdef CANSM_OSEKNM_ENABLE
            /* Every network but the network of OsekNm. */
            if( D_OSEK_CAN_CONTROLLERID != CanSM_BsmChn[index].ManagerNetworkPtr->ControllerId )
            {
                stdRet = CanIf_GetPduMode(CanSM_BsmChn[index].ManagerNetworkPtr->ControllerId,&CanSM_BsmChn[index].Bsm_E_CanIfMode);
                if( E_OK == stdRet )
                {
                    CanSM_Bsm_Process(&CanSM_BsmChn[index]);
                }
            }
#else   /* CANSM_OSEKNM_ENABLE */
            stdRet = CanIf_GetPduMode(CanSM_BsmChn[index].ManagerNetworkPtr->ControllerId,&CanSM_BsmChn[index].Bsm_E_CanIfMode);
            if( E_OK == stdRet )
            {
                CanSM_Bsm_Process(&CanSM_BsmChn[index]);
            }
#endif  /* CANSM_OSEKNM_ENABLE */

        }
    }

    CanSM_Det_ErrorReport(CANSM_SERVICEID_MAINFUNCTION, errorId);
}

/*
********************************************************************************
* Function Name: CanSM_Bsm_Process
*
* Explanation: CanSM module State Machine Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_Bsm_Process
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* Define current CanSM state. */
    CanSM_BsmStaType cansmState = CANSM_BSM_S_NOT_INITIALIZED;
    do
    {
        /* Get current CanSM state. */
        cansmState = bsmSta->BsmSta;
        /* State machine of CanSM main process. */
        switch( bsmSta->BsmSta )
        {
            case CANSM_BSM_S_NOT_INITIALIZED:
                CanSM_Bsm_NOT_INITIALIZED(bsmSta);
                break;
            case CANSM_BSM_S_PRE_NOCOM:
                CanSM_Bsm_PRE_NOCOM(bsmSta);
                break;
            case CANSM_BSM_WUVALIDATION:
                CanSM_Bsm_WUVALIDATION(bsmSta);
                break;
            case CANSM_BSM_S_PRE_FULLCOM:
                CanSM_Bsm_PRE_FULLCOM(bsmSta);
                break;
            case CANSM_BSM_S_FULLCOM:
                CanSM_Bsm_FULLCOM(bsmSta);
                break;
            case CANSM_BSM_S_SILENTCOM:
                CanSM_Bsm_SILENTCOM(bsmSta);
                break;
            case CANSM_BSM_S_SILENTCOM_BOR:
                CanSM_Bsm_SILENTCOM_BOR(bsmSta);
                break;

#if( CANSM_SET_BAUDRATE_API == STD_ON )
            case CANSM_BSM_S_CHANGE_BAUDRATE:
                CanSM_Bsm_ChangeBR(bsmSta);
                break;
#endif  /* CANSM_SET_BAUDRATE_API == STD_ON */
            case CANSM_BSM_S_NOCOM:
                CanSM_Bsm_NOCOM(bsmSta);
                break;
            default:
                bsmSta->BsmSta = CANSM_BSM_S_NOT_INITIALIZED; /* NOT_INITIALIZED. */
                break;
        }
    /* Handle all state machine jumps. */
    }while( cansmState != bsmSta->BsmSta );
}

/*
********************************************************************************
* Function Name: CanSM_Bsm_NOT_INITIALIZED
*
* Explanation: NOT_INITIALIZED of CanSM module State Machine Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_Bsm_NOT_INITIALIZED
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* Evaluate the trigger and condition for state of NOT_INITIALIZED and Do the next move. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( CANSM_INITED == CanSM_InitFlag )
    {
        bsmSta->BsmSta = CANSM_BSM_S_PRE_NOCOM;
        CanSM_Bsm_PreNoCom_SubState_Init(bsmSta);
    }
}

/*
********************************************************************************
* Function Name: CanSM_Bsm_PRE_NOCOM
*
* Explanation: PRE_NOCOM of CanSM module State Machine Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_Bsm_PRE_NOCOM
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
#if( CANSM_CANTRCV_PN_SUPPORT == STD_ON )
    if( TRUE == bsmSta->ManagerNetworkPtr->trcvPnEnable )
    {
        /* SWS_CanSM_00437 */
        CanSM_Bsm_DeinitPnSupported(bsmSta);
    }
    else
#endif  /* CANSM_CANTRCV_PN_SUPPORT == STD_ON */
    {
        /* SWS_CanSM_00436 */
        CanSM_Bsm_DeinitPnNotSupported(bsmSta);
    }
}

/*
********************************************************************************
* Function Name: CanSM_Bsm_WUVALIDATION
*
* Explanation: WUVALIDATION of CanSM module State Machine Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_Bsm_WUVALIDATION
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* Define current sub state. */
    CanSM_Bsm_Sub_WUType subState = bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION;
    do
    {
        /* Get current substate machine. */
        subState = bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION;
        /* Sub state machine of CanSM_WUVALIDATION. */
        /* polyspace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule16.1" */
        switch( bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION )
        {
            case CANSM_S_WU_TRCV_NORMAL:
                CanSM_S_WU_TRCV_NORMAL(bsmSta);
                break;
            case CANSM_S_WU_TRCV_NORMAL_WAIT:
                CanSM_S_WU_TRCV_NORMAL_WAIT(bsmSta);
                break;
            case CANSM_S_WU_CC_STOPPED:
                CanSM_S_WU_CC_STOPPED(bsmSta);
                break;
            case CANSM_S_WU_CC_STOPPED_WAIT:
                CanSM_S_WU_CC_STOPPED_WAIT(bsmSta);
                break;
            case CANSM_S_WU_CC_STARTED:
                CanSM_S_WU_CC_STARTED(bsmSta);
                break;
            case CANSM_S_WU_CC_STARTED_WAIT:
                CanSM_S_WU_CC_STARTED_WAIT(bsmSta);
                break;
            case CANSM_S_WU_WAIT_LEAVE:
                CanSM_S_WU_WAIT_LEAVE(bsmSta);
                break;
            /* polyspace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule16.4" */
            default:
                break;
        }
    /* Handle all substate machine jumps. */
    }while( subState != bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION );
}

/*
********************************************************************************
* Function Name: CanSM_Bsm_PRE_FULLCOM
*
* Explanation: WUVALIDATION of CanSM module state machine processing.
*              (Synchronous)
*
* param: bsmSta: One channel of CanSM state machine struct pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_Bsm_PRE_FULLCOM
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* Define current sub state. */
    CanSM_Bsm_Sub_PREFULLCOMType subState = bsmSta->BsmSub.BsmSta_Sub_PRE_FULLCOM;
    do
    {
        /* Get current substate machine. */
        subState = bsmSta->BsmSub.BsmSta_Sub_PRE_FULLCOM;
        /* Sub state machine of CanSM_PRE_FULLCOM. */
        /* polyspace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule16.1" */
        switch( bsmSta->BsmSub.BsmSta_Sub_PRE_FULLCOM )
        {
            case CANSM_S_TRCV_NORMAL:
                CanSM_S_TRCV_NORMAL (bsmSta);
                break;
            case CANSM_S_TRCV_NORMAL_WAIT:
                CanSM_S_TRCV_NORMAL_WAIT(bsmSta);
                break;
            case CANSM_S_CC_STOPPED:
                CanSM_S_CC_STOPPED(bsmSta);
                break;
            case CANSM_S_CC_STOPPED_WAIT:
                CanSM_S_CC_STOPPED_WAIT(bsmSta);
                break;
            case CANSM_S_CC_STARTED:
                CanSM_S_CC_STARTED(bsmSta);
                break;
            case CANSM_S_CC_STARTED_WAIT:
                CanSM_S_CC_STARTED_WAIT(bsmSta);
                break;
            /* polyspace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule16.4" */
            default:
                break;
        }
    /* Handle all substate machine jumps. */
    }while( subState != bsmSta->BsmSub.BsmSta_Sub_PRE_FULLCOM );
}

/*
********************************************************************************
* Function Name: CanSM_Bsm_FULLCOM
*
* Explanation: FULLCOM of CanSM module State Machine Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_Bsm_FULLCOM
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    uint8 comM_ModeTypeBuf;
    /* Define current sub state. */
    CanSM_Bsm_Sub_FULLCOMType subState = bsmSta->BsmSub.BsmSta_Sub_FULLCOM;

    /* Evaluate the trigger and condition for state of FULLCOM and Do the next move. */
    if( COMM_SILENT_COMMUNICATION == bsmSta->BsmTrg_MODE_REQUEST )
    {
        bsmSta->BsmSta = CANSM_BSM_S_SILENTCOM;
        bsmSta->Bsm_TaskCycCnt_BUSOFF = CANSM_VALUE_ZERO;
        bsmSta->Bsm_RecCnt_BUS_OFF = CANSM_VALUE_ZERO;
        comM_ModeTypeBuf = COMM_SILENT_COMMUNICATION;
        /* Called CanIf to set the PDU mode. */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        (void)CanIf_SetPduMode(bsmSta->ManagerNetworkPtr->ControllerId, CANIF_TX_OFFLINE);
        /* ComM CBK Func. */
        ComM_BusSM_ModeIndication(bsmSta->ManagerNetworkPtr->ComMNetworkHandle, &comM_ModeTypeBuf);
#if( CANSM_BSWMENABLED == STD_ON )
        BswM_CanSM_CurrentState(bsmSta->ManagerNetworkPtr->ComMNetworkHandle,CANSM_BSWM_SILENT_COMMUNICATION);
#endif  /* CANSM_BSWMENABLED == STD_ON */
    }
    else if( COMM_NO_COMMUNICATION == bsmSta->BsmTrg_MODE_REQUEST )
    {
        bsmSta->BsmSta = CANSM_BSM_S_PRE_NOCOM;
        CanSM_Bsm_PreNoCom_SubState_Init(bsmSta);
        bsmSta->Bsm_TaskCycCnt_BUSOFF = CANSM_VALUE_ZERO;
        bsmSta->Bsm_RecCnt_BUS_OFF = CANSM_VALUE_ZERO;
        comM_ModeTypeBuf = COMM_NO_COMMUNICATION;
        /* Called CanIf to set the PDU mode. */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        (void)CanIf_SetPduMode(bsmSta->ManagerNetworkPtr->ControllerId, CANIF_TX_OFFLINE);
        /* ComM CBK Func. */
        ComM_BusSM_ModeIndication(bsmSta->ManagerNetworkPtr->ComMNetworkHandle, &comM_ModeTypeBuf);
#if( CANSM_BSWMENABLED == STD_ON )
        BswM_CanSM_CurrentState(bsmSta->ManagerNetworkPtr->ComMNetworkHandle,CANSM_BSWM_NO_COMMUNICATION);
#endif  /* CANSM_BSWMENABLED == STD_ON */
    }

#if( CANSM_SET_BAUDRATE_API == STD_ON )
    else if( (CANSM_T_CHANGE_BR_REQUEST == bsmSta->changeBRIdRequest) 
          && (CANSM_T_BUS_OFF != bsmSta->BsmTrg_BUS_OFF) )
    {
        bsmSta->BsmSta = CANSM_BSM_S_CHANGE_BAUDRATE;
        bsmSta->BsmSub.BsmSta_Sub_CHANGE_BAUDRATE = CANSM_S_CBR_SYNC;
#if( CANSM_BSWMENABLED == STD_ON )
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        BswM_CanSM_CurrentState(bsmSta->ManagerNetworkPtr->ComMNetworkHandle,CANSM_BSWM_CHANGE_BAUDRATE);
#endif  /* CANSM_BSWMENABLED == STD_ON */
    }
#endif  /* CANSM_SET_BAUDRATE_API == STD_ON */

    else
    {
        do
        {
#if( CANSM_REPORT_DEM_ENABLE == STD_ON )
            if( (CANSM_VALUE_ZERO != bsmSta->ManagerNetworkPtr->EventId_BUS_OFF)
                && (FALSE == CanSM_BusOffDTCReported) )
            {
                /* Set the BusOff DTC status to PASSED. */
                Dem_ReportErrorStatus(bsmSta->ManagerNetworkPtr->EventId_BUS_OFF, DEM_EVENT_STATUS_PASSED);
                CanSM_BusOffDTCReported = TRUE;
            }
#endif  /* CANSM_REPORT_DEM_ENABLE == STD_ON */
            /* Get current substate machine. */
            subState = bsmSta->BsmSub.BsmSta_Sub_FULLCOM;
            /* Sub state machine of CanSM_FULLCOM. */
            /* polyspace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule16.1" */
            switch( bsmSta->BsmSub.BsmSta_Sub_FULLCOM )
            {
                case CANSM_S_BUS_OFF_CHECK:
                    CanSM_S_FULLCOM_BUS_OFF_CHECK(bsmSta);
                    break;
                case CANSM_S_RESTART_CC:
                    CanSM_S_FULLCOM_RESTART_CC(bsmSta);
                    break;
                case CANSM_S_RESTART_CC_WAIT:
                    CanSM_S_FULLCOM_RESTART_CC_WAIT(bsmSta);
                    break;
                case CANSM_S_TX_OFF:
                    CanSM_S_FULLCOM_TX_OFF(bsmSta);
                    break;
                case CANSM_S_TX_TIMEOUT_EXCEPTION:
                    CanSM_S_FULLCOM_TX_TIMEOUT_EXCEPTION(bsmSta);
                    break;
                /* polyspace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule16.4" */
                default:
                    break;
            }
        /* Handle all substate machine jumps. */
        }while( subState != bsmSta->BsmSub.BsmSta_Sub_FULLCOM );
        /* Counter for bus off status. */
        if( CANSM_T_BUS_OFF == bsmSta->BsmTrg_BUS_OFF )
        {
            bsmSta->Bsm_TaskCycCnt_BUSOFF++;
        }
        if( CANSM_VALUE_ZERO < bsmSta->Bsm_RecEnsureCnt_BUS_OFF )
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            bsmSta->Bsm_RecEnsureCnt_BUS_OFF--;
        }
    }
}

#if( CANSM_SET_BAUDRATE_API == STD_ON )
/*
********************************************************************************
* Function Name: CanSM_Bsm_ChangeBR
*
* Explanation: WUVALIDATION of CanSM module State Machine Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_Bsm_ChangeBR
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* Define current sub state. */
    CanSM_Bsm_Sub_CHANGEBRType subState = bsmSta->BsmSub.BsmSta_Sub_CHANGE_BAUDRATE;
    do
    {
        /* Get current substate machine. */
        subState = bsmSta->BsmSub.BsmSta_Sub_CHANGE_BAUDRATE;
        /* Sub state machine of CanSM_ChangeBR. */
        /* polyspace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule16.1" */
        switch( bsmSta->BsmSub.BsmSta_Sub_CHANGE_BAUDRATE )
        {
            case CANSM_S_CBR_STOP_CC:
                CanSM_S_CHANGE_BR_STOP_CC(bsmSta);
                break;
            case CANSM_S_CBR_STOP_CC_WAIT:
                CanSM_S_CHANGE_BR_STOP_CC_WAIT(bsmSta);
                break;
            case CANSM_S_CBR_SYNC:
                CanSM_S_CHANGE_BR_SYNC(bsmSta);
                break;
            case CANSM_S_CBR_START_CC:
                CanSM_S_CHANGE_BR_START_CC(bsmSta);
                break;
            case CANSM_S_CBR_START_CC_WAIT:
                CanSM_S_CHANGE_BR_START_CC_WAIT(bsmSta);
                break;
            /* polyspace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule16.4" */
            default:
                break;
        }
    /* Handle all substate machine jumps. */
    }while(subState != bsmSta->BsmSub.BsmSta_Sub_CHANGE_BAUDRATE);
}
#endif  /* CANSM_SET_BAUDRATE_API == STD_ON */

/*
********************************************************************************
* Function Name: CanSM_Bsm_SILENTCOM
*
* Explanation: SILENTCOM of CanSM module State Machine Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_Bsm_SILENTCOM
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    uint8 comM_ModeTypeBuf;

    /* Evaluate the trigger and condition for state of SILENTCOM and Do the next move. */
    if( CANSM_T_BUS_OFF == bsmSta->BsmTrg_BUS_OFF )
    {
        /* The BsmSta state jumps: SILENTCOM --> SILENTCOM_BOR */
        bsmSta->BsmSta = CANSM_BSM_S_SILENTCOM_BOR;
        /* Set the Sub_SILENTCOM_BOR state --> SILENTCOM_BOR_RESTART */
        bsmSta->BsmSub.BsmSta_Sub_SILENTCOM_BOR = CANSM_S_SILENTCOM_BOR_RESTART;
    }
    else if( COMM_FULL_COMMUNICATION == bsmSta->BsmTrg_MODE_REQUEST )
    {
        bsmSta->BsmSta = CANSM_BSM_S_FULLCOM;
        bsmSta->BsmSub.BsmSta_Sub_FULLCOM = CANSM_S_BUS_OFF_CHECK;
        comM_ModeTypeBuf = COMM_FULL_COMMUNICATION;
        /* Called CanIf to set the PDU mode. */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        (void)CanIf_SetPduMode(bsmSta->ManagerNetworkPtr->ControllerId, CANIF_ONLINE);
        /* ComM CBK Func. */
        ComM_BusSM_ModeIndication(bsmSta->ManagerNetworkPtr->ComMNetworkHandle,&comM_ModeTypeBuf);
#if( CANSM_BSWMENABLED == STD_ON )
        BswM_CanSM_CurrentState(bsmSta->ManagerNetworkPtr->ComMNetworkHandle,CANSM_BSWM_FULL_COMMUNICATION);
#endif  /* CANSM_BSWMENABLED == STD_ON */
    }
    else if( COMM_NO_COMMUNICATION == bsmSta->BsmTrg_MODE_REQUEST )
    {
        bsmSta->BsmSta = CANSM_BSM_S_PRE_NOCOM;
        CanSM_Bsm_PreNoCom_SubState_Init(bsmSta);
        comM_ModeTypeBuf = COMM_NO_COMMUNICATION;
        /* Called CanIf to set the PDU mode. */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        (void)CanIf_SetPduMode(bsmSta->ManagerNetworkPtr->ControllerId, CANIF_TX_OFFLINE);
        /* ComM CBK Func. */
        ComM_BusSM_ModeIndication(bsmSta->ManagerNetworkPtr->ComMNetworkHandle,&comM_ModeTypeBuf);
#if( CANSM_BSWMENABLED == STD_ON )
        BswM_CanSM_CurrentState(bsmSta->ManagerNetworkPtr->ComMNetworkHandle,CANSM_BSWM_NO_COMMUNICATION);
#endif  /* CANSM_BSWMENABLED == STD_ON */
    }
    else
    {
        /* Do nothing. */
    }
}

/*
********************************************************************************
* Function Name: CanSM_Bsm_SILENTCOM_BOR
*
* Explanation: SILENTCOM_BOR of CanSM module State Machine Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_Bsm_SILENTCOM_BOR
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* Define current sub state. */
    CanSM_Bsm_Sub_SILENTCOMBORType subState = bsmSta->BsmSub.BsmSta_Sub_SILENTCOM_BOR;
    do
    {
        /* Get current substate machine. */
        subState = bsmSta->BsmSub.BsmSta_Sub_SILENTCOM_BOR;
        /* Sub state machine of CanSM_SILENTCOM_BOR. */
        /* polyspace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule16.1" */
        switch( bsmSta->BsmSub.BsmSta_Sub_SILENTCOM_BOR )
        {
            /* SILENTCOM_BOR --> SILENTCOM_BOR_RESTART */
            case CANSM_S_SILENTCOM_BOR_RESTART:
                CanSM_Bsm_SILENTCOM_BOR_RESTART(bsmSta);
                break;
            /* SILENTCOM_BOR --> SILENTCOM_BOR_RESTART_WAIT */
            case CANSM_S_SILENTCOM_BOR_RESTART_WAIT:
                CanSM_Bsm_SILENTCOM_BOR_RESTART_WAIT(bsmSta);
                break;
            /* polyspace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule16.4" */
            default:
                break;
        }
    /* Handle all substate machine jumps. */
    }while( subState != bsmSta->BsmSub.BsmSta_Sub_SILENTCOM_BOR );
}

/*
********************************************************************************
* Function Name: CanSM_Bsm_NOCOM
*
* Explanation: NOCOM of CanSM module State Machine Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_Bsm_NOCOM
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* Evaluate the trigger and condition for state of NOCOM and Do the next move. */
    if( CANSM_T_START_WAKEUP_SOURCE == bsmSta->BsmTrg_WAKEUP_SOURCE )
    {
        bsmSta->BsmSta = CANSM_BSM_WUVALIDATION;
        bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION = CANSM_S_WU_TRCV_NORMAL;
    }
    else if( COMM_FULL_COMMUNICATION == bsmSta->BsmTrg_MODE_REQUEST )
    {
        bsmSta->BsmSta = CANSM_BSM_S_PRE_FULLCOM;
        bsmSta->BsmSub.BsmSta_Sub_PRE_FULLCOM = CANSM_S_TRCV_NORMAL;
    }
    else
    {
        /* Do Nothing. */
    }
}

/*
********************************************************************************
* Function Name: CanSM_Bsm_SILENTCOM_BOR_RESTART
*
* Explanation: RESTART of CanSM module Sub State Machine SILENTCOM_BOR Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_Bsm_SILENTCOM_BOR_RESTART
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    Std_ReturnType stdRet;

    /* Evaluate the trigger and condition for sub state of SILENTCOM_BOR_RESTART and Do the next move. */
    if( CANSM_T_CC_STARTED_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {
        /* The BsmSta state jumps: SILENTCOM_BOR_RESTART --> SILENTCOM */
        bsmSta->BsmSta = CANSM_BSM_S_SILENTCOM;
        bsmSta->BsmTrg_BUS_OFF = CANSM_T_NOT_BUS_OFF;
        /* The timer of mode requests turn off. */
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        /* SWS_CANSM_00604 */
        stdRet = CanIf_SetControllerMode(
            /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
            bsmSta->ManagerNetworkPtr->ControllerId, CANIF_CS_STARTED);
        /* SWS_CANSM_00603 */
        if( E_OK == stdRet )
        {
            /* The Sub_SILENTCOM_BOR state jumps: SILENTCOM_BOR_RESTART --> SILENTCOM_BOR_RESTART_WAIT */
            bsmSta->BsmSub.BsmSta_Sub_SILENTCOM_BOR = CANSM_S_SILENTCOM_BOR_RESTART_WAIT;
            /* The timer of mode requests turn on. */
            bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
        }
        else
        {
            /* Count of repeat the API of the CanIf */
            bsmSta->repeatCount++;
            /* SWS_CANSM_00523 */
            if( CANSM_MODE_REQ_REPETITION_MAX < bsmSta->repeatCount )
            {
                /* The BsmSta state jumps: CANSM_BSM_S_SILENTCOM_BOR --> CANSM_BSM_S_PRE_NOCOM */
                bsmSta->BsmSta = CANSM_BSM_S_PRE_NOCOM;
                /* Clear repeat count */
                bsmSta->repeatCount = CANSM_VALUE_ZERO;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_Bsm_SILENTCOM_BOR_RESTART_WAIT
*
* Explanation: RESTART_WAIT of CanSM module Sub State Machine SILENTCOM_BOR Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_Bsm_SILENTCOM_BOR_RESTART_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* Evaluate the trigger and condition for sub state of SILENTCOM_BOR_RESTART_WAIT and Do the next move. */
    if( CANSM_T_CC_STARTED_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {
        /* The BsmSta state jumps: SILENTCOM_BOR_RESTART_WAIT --> SILENTCOM */
        bsmSta->BsmSta = CANSM_BSM_S_SILENTCOM;
        bsmSta->BsmTrg_BUS_OFF = CANSM_T_NOT_BUS_OFF;
        /* The timer of mode requests turn off. */
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        /* Clear repeat count. */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        /* The timer of mode requests is not expired. */
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        else  /* The timer of mode requests is expired. */
        {
            /* The Sub_SILENTCOM_BOR state jumps: SILENTCOM_BOR_RESTART_WAIT --> SILENTCOM_BOR_RESTAR */
            bsmSta->BsmSub.BsmSta_Sub_SILENTCOM_BOR = CANSM_S_SILENTCOM_BOR_RESTART;
            /* The timer of mode requests turn off. */
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_FULLCOM_BUS_OFF_CHECK
*
* Explanation: BUS_OFF_CHECK of CanSM module Sub State Machine FULLCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_FULLCOM_BUS_OFF_CHECK
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanSM_UNMODIFIED_VAR_NOT_CONST" */
    uint8 comM_ModeTypeBuf = COMM_SILENT_COMMUNICATION;
#ifdef CANSM_GET_BUSOFF_DELAY_FUNCTION
    boolean busOffFlag = FALSE;
#endif  /* CANSM_GET_BUSOFF_DELAY_FUNCTION */

    /* T_BUS_OFF */
    if( CANSM_T_BUS_OFF == bsmSta->BsmTrg_BUS_OFF )
    {
        comM_ModeTypeBuf = COMM_SILENT_COMMUNICATION;
        bsmSta->Bsm_RecCnt_BUS_OFF++;
        /* SWS_CanSM_00508 */
#if( CANSM_BSWMENABLED == STD_ON )
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        BswM_CanSM_CurrentState(bsmSta->ManagerNetworkPtr->ComMNetworkHandle, CANSM_BSWM_BUS_OFF);
#endif  /* CANSM_BSWMENABLED == STD_ON */
        /* Add for SWS_CanSM_00521 */
        ComM_BusSM_ModeIndication(bsmSta->ManagerNetworkPtr->ComMNetworkHandle, &comM_ModeTypeBuf);

#ifdef CANSM_GET_BUSOFF_DELAY_FUNCTION  /* User_GetBusOffDelay Configurable Interfaces */
        if( bsmSta->ManagerNetworkPtr->EnableBusOffDelay == TRUE )
        {
            busOffFlag = TRUE;
            CANSM_GET_BUSOFF_DELAY_FUNCTION(bsmSta->ManagerNetworkPtr->ComMNetworkHandle, (uint8*)&(busOffFlag));
        }
#endif  /* CANSM_GET_BUSOFF_DELAY_FUNCTION */

#if( CANSM_REPORT_DEM_ENABLE == STD_ON )
        if( CANSM_VALUE_ZERO != bsmSta->ManagerNetworkPtr->EventId_BUS_OFF )
        {
            /* SWS_CanSM_00522 */
            Dem_ReportErrorStatus(bsmSta->ManagerNetworkPtr->EventId_BUS_OFF, DEM_EVENT_STATUS_PREFAILED);
        }
#endif  /* CANSM_REPORT_DEM_ENABLE == STD_ON */

        /* The Sub_FULLCOM state jumps: BUS_OFF_CHECK --> RESTART_CC */
        bsmSta->BsmSub.BsmSta_Sub_FULLCOM = CANSM_S_RESTART_CC;

    }

#if( CANSM_BORTXCFMPOLLING_SUPPORT == STD_ON )
    /* SWS_CanSM_00497 */
    /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
    else if( (TRUE == bsmSta->ManagerNetworkPtr->BorTxCfmPolling ) &&
             (CANIF_TX_RX_NOTIFICATION == CanIf_GetTxConfirmationState(bsmSta->ManagerNetworkPtr->ControllerId)) )
    {
        if( CANSM_VALUE_ZERO != bsmSta->Bsm_RecCnt_BUS_OFF )
        {
#ifdef CANSM_GET_BUSOFF_DELAY_FUNCTION  /* User_GetBusOffDelay Configurable Interfaces. */
            if( bsmSta->ManagerNetworkPtr->EnableBusOffDelay == TRUE )
            {
                CANSM_GET_BUSOFF_DELAY_FUNCTION(bsmSta->ManagerNetworkPtr->ComMNetworkHandle, (uint8*)&(busOffFlag));
            }
#endif  /* CANSM_GET_BUSOFF_DELAY_FUNCTION */

#if( CANSM_REPORT_DEM_ENABLE == STD_ON )
            if( CANSM_VALUE_ZERO != bsmSta->ManagerNetworkPtr->EventId_BUS_OFF )
            {
                /* SWS_CanSM_00498 */
                Dem_ReportErrorStatus(bsmSta->ManagerNetworkPtr->EventId_BUS_OFF, DEM_EVENT_STATUS_PASSED);
            }
#endif  /* CANSM_REPORT_DEM_ENABLE == STD_ON */

            bsmSta->Bsm_RecCnt_BUS_OFF = CANSM_VALUE_ZERO;
            bsmSta->Bsm_TaskCycCnt_BUSOFF = CANSM_VALUE_ZERO;
        }
		/* SWS_CanSM_00584 */
        else if( CANSM_T_TXTIMEOUT == bsmSta->BsmTrg_TxTimeout )
        {
		    /* The Sub_FULLCOM state jumps: BUS_OFF_CHECK --> TX_TIMEOUT_EXCEPTION. */
            bsmSta->BsmSub.BsmSta_Sub_FULLCOM = CANSM_S_TX_TIMEOUT_EXCEPTION;
			/* Init sub state of CANSM_S_TX_TIMEOUT_EXCEPTION. */
            bsmSta->BsmSub.BsmSta_Sub_TXTIMEOUTEXCEPTION = CANSM_TX_TIMEOUT_EXCEPTION_S_CC_STOPPED;
        }
        else
        {
            /* Do nothing. */
        }
    }
#endif  /* CANSM_BORTXCFMPOLLING_SUPPORT == STD_ON */
    /* SWS_CanSM_00496 */
    else if( (CANSM_VALUE_ZERO != bsmSta->ManagerNetworkPtr->borTimeTxEnsured) &&
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
             (CANSM_VALUE_ZERO == bsmSta->Bsm_RecEnsureCnt_BUS_OFF) )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        if( CANSM_VALUE_ZERO != bsmSta->Bsm_RecCnt_BUS_OFF )
        {
#ifdef CANSM_GET_BUSOFF_DELAY_FUNCTION  /* User_GetBusOffDelay Configurable Interfaces. */
            if( bsmSta->ManagerNetworkPtr->EnableBusOffDelay == TRUE )
            {
                CANSM_GET_BUSOFF_DELAY_FUNCTION(bsmSta->ManagerNetworkPtr->ComMNetworkHandle, (uint8*)&(busOffFlag));
            }
#endif  /* CANSM_GET_BUSOFF_DELAY_FUNCTION */

#if( CANSM_REPORT_DEM_ENABLE == STD_ON )
            if( CANSM_VALUE_ZERO != bsmSta->ManagerNetworkPtr->EventId_BUS_OFF )
            {
                /* SWS_CanSM_00498 */
                Dem_ReportErrorStatus(bsmSta->ManagerNetworkPtr->EventId_BUS_OFF, DEM_EVENT_STATUS_PASSED);
            }
#endif  /* CANSM_REPORT_DEM_ENABLE == STD_ON */

            bsmSta->Bsm_RecCnt_BUS_OFF = CANSM_VALUE_ZERO;
            bsmSta->Bsm_TaskCycCnt_BUSOFF = CANSM_VALUE_ZERO;
        }
		/* SWS_CanSM_00584 */
        else if( CANSM_T_TXTIMEOUT == bsmSta->BsmTrg_TxTimeout )
        {
            /* The Sub_FULLCOM state jumps: BUS_OFF_CHECK --> TX_TIMEOUT_EXCEPTION. */
            bsmSta->BsmSub.BsmSta_Sub_FULLCOM = CANSM_S_TX_TIMEOUT_EXCEPTION;
            /* Init sub state of CANSM_S_TX_TIMEOUT_EXCEPTION. */
            bsmSta->BsmSub.BsmSta_Sub_TXTIMEOUTEXCEPTION = CANSM_TX_TIMEOUT_EXCEPTION_S_CC_STOPPED;
        }
        else
        {
            /* Do nothing. */
        }
    }
    else
    {
        /* Do nothing. */
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_FULLCOM_RESTART_CC
*
* Explanation: RESTART_CC of CanSM module Sub State Machine FULLCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_FULLCOM_RESTART_CC
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* Evaluate the trigger and condition for sub state of RESTART_CC and Do the next move. */
    if( CANSM_T_CC_STARTED_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {
        /* The Sub_FULLCOM state jumps: RESTART_CC --> TX_OFF */
        bsmSta->BsmSub.BsmSta_Sub_FULLCOM = CANSM_S_TX_OFF;
    }
    else
    {
        /* SWS_CanSM_00509 */
        /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanSM_UNMODIFIED_VAR_NOT_CONST" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        Std_ReturnType stdRet = CanIf_SetControllerMode(bsmSta->ManagerNetworkPtr->ControllerId, CANIF_CS_STARTED);
        /* SWS_CanSM_00510 */
        if( E_OK == stdRet )
        {
            /* The Sub_FULLCOM state jumps: RESTART_CC --> RESTART_CC_WAIT */
            bsmSta->BsmSub.BsmSta_Sub_FULLCOM = CANSM_S_RESTART_CC_WAIT;
            /* The timer of mode requests turn on. */
            bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_FULLCOM_RESTART_CC_WAIT
*
* Explanation: RESTART_CC_WAIT of CanSM module Sub State Machine FULLCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_FULLCOM_RESTART_CC_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_CC_STARTED_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {
        /* The Sub_FULLCOM state jumps: RESTART_CC_WAIT --> TX_OFF */
        bsmSta->BsmSub.BsmSta_Sub_FULLCOM = CANSM_S_TX_OFF;
        /* The timer of mode requests turn off. */
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
    }
    else
    {
        /* The timer of mode requests is not expired. */
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        else  /* The timer of mode requests is expired. */
        {
            /* The Sub_FULLCOM state jumps: RESTART_CC_WAIT --> RESTART_CC */
            bsmSta->BsmSub.BsmSta_Sub_FULLCOM = CANSM_S_RESTART_CC;
            /* The timer of mode requests turn off. */
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_FULLCOM_TX_OFF
*
* Explanation: TX_OFF of CanSM module Sub State Machine FULLCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_FULLCOM_TX_OFF
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    Std_ReturnType canSM_RetVol;
    uint8 comM_ModeTypeBuf;

    /* Evaluate the trigger and condition for sub state of TX_OFF and Do the next move. */
    /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
    if( bsmSta->Bsm_RecCnt_BUS_OFF > bsmSta->ManagerNetworkPtr->BorCounterL1ToL2 )
    {
        if( bsmSta->Bsm_TaskCycCnt_BUSOFF >= bsmSta->ManagerNetworkPtr->BorTimeL2 )
        {
            canSM_RetVol = CanIf_SetPduMode(bsmSta->ManagerNetworkPtr->ControllerId, CANIF_ONLINE);
            if( E_OK == canSM_RetVol )
            {
                comM_ModeTypeBuf = COMM_FULL_COMMUNICATION;
                bsmSta->Bsm_TaskCycCnt_BUSOFF = CANSM_VALUE_ZERO;
                bsmSta->Bsm_RecCnt_BUS_OFF = (uint16)bsmSta->ManagerNetworkPtr->BorCounterL1ToL2 + (uint16)CANSM_VALUE_ONE;
                bsmSta->BsmTrg_BUS_OFF = CANSM_T_NOT_BUS_OFF;
                bsmSta->BsmSub.BsmSta_Sub_FULLCOM = CANSM_S_BUS_OFF_CHECK;
                bsmSta->Bsm_RecEnsureCnt_BUS_OFF = bsmSta->ManagerNetworkPtr->borTimeTxEnsured;
#if( CANSM_BSWMENABLED == STD_ON )
                BswM_CanSM_CurrentState(bsmSta->ManagerNetworkPtr->ComMNetworkHandle, CANSM_BSWM_FULL_COMMUNICATION);
#endif  /* CANSM_BSWMENABLED == STD_ON */
                ComM_BusSM_ModeIndication(bsmSta->ManagerNetworkPtr->ComMNetworkHandle, &comM_ModeTypeBuf);
            }
            else
            {
                bsmSta->BsmSub.BsmSta_Sub_FULLCOM = CANSM_S_RESTART_CC;
                bsmSta->Bsm_TaskCycCnt_BUSOFF = bsmSta->ManagerNetworkPtr->BorTimeL2;
            }
        }
    }
    else
    {
        if( bsmSta->Bsm_TaskCycCnt_BUSOFF >= bsmSta->ManagerNetworkPtr->BorTimeL1 )
        {
            canSM_RetVol = CanIf_SetPduMode(bsmSta->ManagerNetworkPtr->ControllerId, CANIF_ONLINE);
            if( E_OK == canSM_RetVol )
            {
                comM_ModeTypeBuf = COMM_FULL_COMMUNICATION;
                bsmSta->Bsm_TaskCycCnt_BUSOFF = CANSM_VALUE_ZERO;
                bsmSta->BsmTrg_BUS_OFF = CANSM_T_NOT_BUS_OFF;
                bsmSta->BsmSub.BsmSta_Sub_FULLCOM = CANSM_S_BUS_OFF_CHECK;
                bsmSta->Bsm_RecEnsureCnt_BUS_OFF = bsmSta->ManagerNetworkPtr->borTimeTxEnsured;
#if( CANSM_BSWMENABLED == STD_ON )
                BswM_CanSM_CurrentState(bsmSta->ManagerNetworkPtr->ComMNetworkHandle, CANSM_BSWM_FULL_COMMUNICATION);
#endif  /* CANSM_BSWMENABLED == STD_ON */
                ComM_BusSM_ModeIndication(bsmSta->ManagerNetworkPtr->ComMNetworkHandle, &comM_ModeTypeBuf);

#ifdef CANSM_BUSOFF_OPTIMIZATION_FUNCTION  /* User_BusOffOptimization Configurable Interface */
                CANSM_BUSOFF_OPTIMIZATION_FUNCTION(bsmSta->ManagerNetworkPtr->ComMNetworkHandle);
#endif  /* CANSM_BUSOFF_OPTIMIZATION_FUNCTION */

            }
            else
            {
                bsmSta->BsmSub.BsmSta_Sub_FULLCOM = CANSM_S_RESTART_CC;
                bsmSta->Bsm_TaskCycCnt_BUSOFF = bsmSta->ManagerNetworkPtr->BorTimeL1;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_FULLCOM_TX_TIMEOUT_EXCEPTION
*
* Explanation: TX_TIMEOUT_EXCEPTION of CanSM module Sub State Machine FULLCOM 
*              Processing.(Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_FULLCOM_TX_TIMEOUT_EXCEPTION
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* Define current sub state. */
    CanSM_Bsm_Sub_TXTIMEOUTEXCEPTIONtype subState = bsmSta->BsmSub.BsmSta_Sub_TXTIMEOUTEXCEPTION;
    do
    {
        /* Get current substate machine. */
        subState = bsmSta->BsmSub.BsmSta_Sub_TXTIMEOUTEXCEPTION;
        /* Sub state machine of CanSM_WUVALIDATION. */
        /* polyspace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule16.1" */
        switch( bsmSta->BsmSub.BsmSta_Sub_TXTIMEOUTEXCEPTION )
        {
            /* S_CC_STOPPED */
            case CANSM_TX_TIMEOUT_EXCEPTION_S_CC_STOPPED:
                CanSM_S_TX_TIMEOUT_EXCEPTION_S_CC_STOPPED(bsmSta);
                break;
            /* S_CC_STOPPED_WAIT */
            case CANSM_TX_TIMEOUT_EXCEPTION_S_CC_STOPPED_WAIT:
                CanSM_S_TX_TIMEOUT_EXCEPTION_S_CC_STOPPED_WAIT(bsmSta);
                break;
            /* S_CC_STARTED */
            case CANSM_TX_TIMEOUT_EXCEPTION_S_CC_STARTED:
                CanSM_S_TX_TIMEOUT_EXCEPTION_S_CC_STARTED(bsmSta);
                break;
            /* S_CC_STARTED_WAIT */
            case CANSM_TX_TIMEOUT_EXCEPTION_S_CC_STARTED_WAIT:
                CanSM_S_TX_TIMEOUT_EXCEPTION_S_CC_STARTED_WAIT(bsmSta);
                break;
            /* polyspace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule16.4" */
            default:
                break;
        }
    /* Handle all substate machine jumps. */
    }while( subState != bsmSta->BsmSub.BsmSta_Sub_TXTIMEOUTEXCEPTION );
}

/*
********************************************************************************
* Function Name: CanSM_S_WU_TRCV_NORMAL
*
* Explanation: TRCV_NORMAL of CanSM module Sub State Machine WU Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_WU_TRCV_NORMAL
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
#if( CANSM_CANTRCV_SUPPORT == STD_ON )
    CanTrcv_TrcvModeType canTrcvMode = CANTRCV_TRCVMODE_STANDBY;
    /* SWS_CanSM_00623 */
    if( TRUE == bsmSta->ManagerNetworkPtr->TransceiverEnable )
    {
        if( (CANSM_T_TRCV_NORMAL_IDC == bsmSta->BsmTrg_TransceiverMode) ||
            ( (E_OK == CanIf_GetTrcvMode(&canTrcvMode, bsmSta->ManagerNetworkPtr->TransceiverId)) &&  /* PRQA S 3415 */ /* NSCA_QAC_CanSM_Rule13.5 */
              (CANTRCV_TRCVMODE_NORMAL == canTrcvMode) ) )
        {
            /* The Sub_WUVALIDATION state jumps: TRCV_NORMAL --> CC_STOPPED */
            bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION = CANSM_S_WU_CC_STOPPED;
        }
        else
        {
            Std_ReturnType stdRet = CanIf_SetTrcvMode(bsmSta->ManagerNetworkPtr->TransceiverId,
                                                      CANTRCV_TRCVMODE_NORMAL);
            /* SWS_CanSM_00624 */
            if( E_OK == stdRet )
            {
                /* The Sub_WUVALIDATION state jumps: TRCV_NORMAL --> TRCV_NORMAL_WAIT */
                bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION = CANSM_S_WU_TRCV_NORMAL_WAIT;
                /* SWS_CanSM_00626, The timer of mode requests turn on. */
                bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
            }
        }
    }
    else
    {
        bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION = CANSM_S_WU_CC_STOPPED;
    }
#else   /* CANSM_CANTRCV_SUPPORT == STD_ON */
    bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION = CANSM_S_WU_CC_STOPPED;
#endif  /* CANSM_CANTRCV_SUPPORT == STD_ON */
}

/*
********************************************************************************
* Function Name: CanSM_S_WU_TRCV_NORMAL_WAIT
*
* Explanation: TRCV_NORMAL_WAIT of CanSM module Sub State Machine WU Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_WU_TRCV_NORMAL_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* Evaluate the trigger and condition for sub state of NORMAL_WAIT and Do the next move. */
    if( CANSM_T_TRCV_NORMAL_IDC == bsmSta->BsmTrg_TransceiverMode )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* The Sub_WUVALIDATION state jumps: TRCV_NORMAL_WAIT --> CC_STOPPED */
        bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION = CANSM_S_WU_CC_STOPPED;
        /* The timer of mode requests turn off. */
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
    }
    else
    {
        /* The timer of mode requests is not expired. */
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        else  /* The timer of mode requests is expired. */
        {
            /* The Sub_WUVALIDATION state jumps: TRCV_NORMAL_WAIT --> TRCV_NORMAL */
            bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION = CANSM_S_WU_TRCV_NORMAL;
            /* The timer of mode requests turn off. */
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }
}

/*
********************************************************************************
* Function Name: CANSM_S_WU_CC_STOPPED
*
* Explanation: CC_STOPPED of CanSM module Sub State Machine WU Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_WU_CC_STOPPED
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_CC_STOPPED_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {
        /* The Sub_WUVALIDATION state jumps: CC_STOPPED --> CC_STARTED */
        bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION = CANSM_S_WU_CC_STARTED;
    }
    else
    {
        /* SWS_CanSM_00627 */
        /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanSM_UNMODIFIED_VAR_NOT_CONST" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        Std_ReturnType stdRet = CanIf_SetControllerMode(bsmSta->ManagerNetworkPtr->ControllerId,
                                                        CANIF_CS_STOPPED);
        /* SWS_CanSM_00628 */
        if( E_OK == stdRet )
        {
            /* The Sub_WUVALIDATION state jumps: CC_STOPPED --> CC_STOPPED_WAIT */
            bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION = CANSM_S_WU_CC_STOPPED_WAIT;
            /* SWS_CanSM_00630, The timer of mode requests turn on. */
            bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_WU_CC_STOPPED_WAIT
*
* Explanation: CC_STOPPED_WAIT of CanSM module Sub State Machine WU Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_WU_CC_STOPPED_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_CC_STOPPED_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {
        /* The Sub_WUVALIDATION state jumps: CC_STOPPED_WAIT --> CC_STARTED */
        bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION = CANSM_S_WU_CC_STARTED;
        /* The timer of mode requests turn off. */
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
    }
    else
    {
        /* The timer of mode requests is not expired. */
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        else  /* The timer of mode requests is expired. */
        {
            /* The Sub_WUVALIDATION state jumps: CC_STOPPED_WAIT --> CC_STOPPED */
            bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION = CANSM_S_WU_CC_STOPPED;
            /* The timer of mode requests turn off. */
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_WU_CC_STARTED
*
* Explanation: CC_STARTED of CanSM module Sub State Machine WU Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_WU_CC_STARTED
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_CC_STARTED_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {
        /* The Sub_WUVALIDATION state jumps: CC_STARTED --> WAIT_LEAVE */
        bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION = CANSM_S_WU_WAIT_LEAVE;
    }
    else
    {
        /* SWS_CanSM_00631 */
        /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanSM_UNMODIFIED_VAR_NOT_CONST" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        Std_ReturnType stdRet = CanIf_SetControllerMode(bsmSta->ManagerNetworkPtr->ControllerId,
                                                        CANIF_CS_STARTED);
        /* SWS_CanSM_00632 */
        if( E_OK == stdRet )
        {
            /* The Sub_WUVALIDATION state jumps: CC_STARTED --> STARTED_WAIT */
            bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION = CANSM_S_WU_CC_STARTED_WAIT;
            /* SWS_CanSM_00634, The timer of mode requests turn on. */
            bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_WU_CC_STARTED_WAIT
*
* Explanation: CC_STARTED_WAIT of CanSM module Sub State Machine WU Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_WU_CC_STARTED_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* Evaluate the trigger and condition for sub state of CC_STARTED_WAIT and Do the next move. */
    if( CANSM_T_CC_STARTED_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {
        /* The Sub_WUVALIDATION state jumps: CC_STARTED_WAIT --> WAIT_LEAVE */
        bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION = CANSM_S_WU_WAIT_LEAVE;
        /* The timer of mode requests turn off. */
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
    }
    else
    {
        /* The timer of mode requests is not expired. */
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        else  /* The timer of mode requests is expired. */
        {
            /* The Sub_WUVALIDATION state jumps: CC_STARTED_WAIT --> CC_STARTED */
            bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION = CANSM_S_WU_CC_STARTED;
            /* The timer of mode requests turn off. */
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_WU_WAIT_LEAVE
*
* Explanation: WAIT_LEAVE of CanSM module Sub State Machine WU Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_WU_WAIT_LEAVE
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    Std_ReturnType stdRet = CANSM_VALUE_ZERO;
    uint8 comM_ModeTypeBuf = CANSM_VALUE_ZERO;

    CANSM_DUMMY_STATEMENT(stdRet);
    CANSM_DUMMY_STATEMENT(comM_ModeTypeBuf);
    /* Evaluate the trigger and condition for sub state of WAIT_LEAVE and Do the next move. */
    if( CANSM_T_STOP_WAKEUP_SOURCE == bsmSta->BsmTrg_WAKEUP_SOURCE )
    {
        bsmSta->BsmSta = CANSM_BSM_S_PRE_NOCOM;
        CanSM_Bsm_PreNoCom_SubState_Init(bsmSta);
    }
    else if( COMM_FULL_COMMUNICATION == bsmSta->BsmTrg_MODE_REQUEST )
    {
        bsmSta->BsmSta = CANSM_BSM_S_PRE_FULLCOM;
        bsmSta->BsmSub.BsmSta_Sub_PRE_FULLCOM = CANSM_S_TRCV_NORMAL;
    }
    else
    {
        /* Do Nothing. */
    }
}

#if( CANSM_SET_BAUDRATE_API == STD_ON )
/*
********************************************************************************
* Function Name: CanSM_S_CHANGE_BR_STOP_CC
*
* Explanation: STOP_CC of CanSM module Sub State Machine FULLCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_CHANGE_BR_STOP_CC
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    Std_ReturnType stdRet = E_NOT_OK;

    /* SWS_CanSM_00526 */
    if( CANSM_T_CC_STOPPED_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {
        /* The BsmSta_Sub_CHANGE_BAUDRATE state jumps: CANSM_S_CBR_STOP_CC --> CANSM_S_CBR_START_CC */
        bsmSta->BsmSub.BsmSta_Sub_CHANGE_BAUDRATE = CANSM_S_CBR_START_CC;
        /* Clear repeat count. */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        /* Evaluate the trigger and condition for sub state of STOP_CC and Do the next move. */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        (void)CanIf_SetPduMode(bsmSta->ManagerNetworkPtr->ControllerId, CANIF_TX_OFFLINE);
        /* SWS_CanSM_00524 */
        stdRet = CanIf_SetControllerMode(bsmSta->ManagerNetworkPtr->ControllerId,CANIF_CS_STOPPED);
        /* SWS_CanSM_00523 */
        if( E_OK == stdRet )
        {
            /* The BsmSta_Sub_CHANGE_BAUDRATE state jumps: CANSM_S_CBR_STOP_CC --> CANSM_S_CBR_STOP_CC_WAIT */
            bsmSta->BsmSub.BsmSta_Sub_CHANGE_BAUDRATE = CANSM_S_CBR_STOP_CC_WAIT;
            /* SWS_CanSM_00630, The timer of mode requests turn on. */
            bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
        }
        else 
        {
            /* Count of repeat the API of the CanIf. */
            bsmSta->repeatCount++;
            /* SWS_CanSM_00536 */
            if( CANSM_MODE_REQ_REPETITION_MAX < bsmSta->repeatCount ) 
            {
                /* The BsmSta state jumps: CANSM_BSM_S_CHANGE_BAUDRATE --> CANSM_BSM_S_PRE_NOCOM */
                bsmSta->BsmSta = CANSM_BSM_S_PRE_NOCOM;
                /* Clear repeat count. */
                bsmSta->repeatCount = CANSM_VALUE_ZERO;
                /* Clear Baudrate modification request. */
                bsmSta->changeBRId = CANSM_NO_CHANGE_BR_REQ;
                /* Clear Baudrate modification request. */
                bsmSta->changeBRIdRequest = CANSM_T_NOT_CHANGE_BR_REQUEST;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_CHANGE_BR_STOP_CC_WAIT
*
* Explanation: STOP_CC_WAIT of CanSM module Sub State Machine FULLCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_CHANGE_BR_STOP_CC_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_CC_STOPPED_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {
        /* The Sub_WUVALIDATION state jumps: CC_STOPPED_WAIT --> CANSM_S_CBR_START_CC */
        bsmSta->BsmSub.BsmSta_Sub_CHANGE_BAUDRATE = CANSM_S_CBR_START_CC;
        /* The timer of mode requests turn off. */
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        /* Clear repeat count. */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        /* The timer of mode requests is not expired. */
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        else  /* The timer of mode requests is expired. */
        {
            /* The Sub_WUVALIDATION state jumps: CC_STOPPED_WAIT --> CANSM_S_CBR_STOP_CC */
            bsmSta->BsmSub.BsmSta_Sub_CHANGE_BAUDRATE = CANSM_S_CBR_STOP_CC;
            /* The timer of mode requests turn off. */
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_CHANGE_BR_SYNC
*
* Explanation: SYNC of CanSM module Sub State Machine FULLCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_CHANGE_BR_SYNC
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    Std_ReturnType stdRet = E_NOT_OK;

    /* Called CanIf to set the Baudrate. */
    /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
    stdRet = CanIf_SetBaudrate(bsmSta->ManagerNetworkPtr->ControllerId, bsmSta->changeBRId);
    if( E_OK == stdRet )
    {
        /* The BsmSta state jumps: CANSM_BSM_S_CHANGE_BAUDRATE --> CANSM_BSM_S_FULLCOM */
        bsmSta->BsmSta = CANSM_BSM_S_FULLCOM;
        /* Set the Sub_FULLCOM state --> CANSM_S_BUS_OFF_CHECK */
        bsmSta->BsmSub.BsmSta_Sub_FULLCOM = CANSM_S_BUS_OFF_CHECK;
        /* Clear Baudrate modification request. */
        bsmSta->changeBRIdRequest = CANSM_T_NOT_CHANGE_BR_REQUEST;
    }
    else
    {
        /* The BsmSta_Sub_CHANGE_BAUDRATE state jumps: CANSM_S_CBR_SYNC --> CANSM_S_CBR_STOP_CC */
        bsmSta->BsmSub.BsmSta_Sub_CHANGE_BAUDRATE = CANSM_S_CBR_STOP_CC;
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_CHANGE_BR_START_CC
*
* Explanation: START_CC of CanSM module Sub State Machine FULLCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_CHANGE_BR_START_CC
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    Std_ReturnType stdRet = E_NOT_OK;
    uint8 comM_ModeTypeBuf = CANSM_VALUE_ZERO;

    /* SWS_CanSM_00534 */
    if( (CANSM_T_CC_STARTED_INDICATED == bsmSta->BsmTrg_ControllerMode) )
    {
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;

        /* Change the state of CanSM main state machine to FULLCOM. */
        comM_ModeTypeBuf = COMM_FULL_COMMUNICATION;
        /* Evaluate the trigger and condition for sub state of START_CC and Do the next move. */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        stdRet = CanIf_SetPduMode(bsmSta->ManagerNetworkPtr->ControllerId, CANIF_ONLINE);
        if( E_OK == stdRet )
        {
            /* The BsmSta state jumps: CANSM_BSM_S_CHANGE_BAUDRATE --> CANSM_BSM_S_FULLCOM */
            bsmSta->BsmSta = CANSM_BSM_S_FULLCOM;
            /* Set the Sub_FULLCOM state --> CANSM_S_BUS_OFF_CHECK */
            bsmSta->BsmSub.BsmSta_Sub_FULLCOM = CANSM_S_BUS_OFF_CHECK;
            /* Clear Baudrate modification request. */
            bsmSta->changeBRIdRequest = CANSM_T_NOT_CHANGE_BR_REQUEST;
            /* ComM CBK Func. */
            ComM_BusSM_ModeIndication(bsmSta->ManagerNetworkPtr->ComMNetworkHandle, &comM_ModeTypeBuf);
#if( CANSM_BSWMENABLED == STD_ON )
            BswM_CanSM_CurrentState(bsmSta->ManagerNetworkPtr->ComMNetworkHandle,CANSM_BSWM_FULL_COMMUNICATION);
#endif  /* CANSM_BSWMENABLED == STD_ON */
        }
    }
    else
    {
        /* Called CanIf to set the Baudrate. */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        stdRet = CanIf_SetBaudrate(bsmSta->ManagerNetworkPtr->ControllerId, bsmSta->changeBRId);
        /* Failure determination. */
        if( E_NOT_OK == stdRet )
        {
            /* Clear Baudrate modification request. */
            bsmSta->changeBRId = CANSM_NO_CHANGE_BR_REQ;
        }
        /* SWS_CanSM_00532 */
        stdRet = CanIf_SetControllerMode(bsmSta->ManagerNetworkPtr->ControllerId, CANIF_CS_STARTED);
        /* SWS_CanSM_00533] */
        if( E_OK == stdRet )
        {
            /* The BsmSta_Sub_CHANGE_BAUDRATE state jumps: CANSM_S_CBR_START_CC --> CANSM_S_CBR_START_CC_WAIT */
            bsmSta->BsmSub.BsmSta_Sub_CHANGE_BAUDRATE = CANSM_S_CBR_START_CC_WAIT;
            /* The timer of mode requests turn on. */
            bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
        }
        else
        {
            /* Count of repeat the API of the CanIf. */
            bsmSta->repeatCount++;
            /* SWS_CanSM_00536 */
            if( CANSM_MODE_REQ_REPETITION_MAX < bsmSta->repeatCount ) 
            {
                /* The BsmSta state jumps: CANSM_BSM_S_CHANGE_BAUDRATE --> CANSM_BSM_S_PRE_NOCOM */
                bsmSta->BsmSta = CANSM_BSM_S_PRE_NOCOM;
                /* Clear repeat count. */
                bsmSta->repeatCount = CANSM_VALUE_ZERO;
                /* Clear Baudrate modification request. */
                bsmSta->changeBRIdRequest = CANSM_T_NOT_CHANGE_BR_REQUEST;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_CHANGE_BR_START_CC_WAIT
*
* Explanation: START_CC_WAIT of CanSM module Sub State Machine FULLCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_CHANGE_BR_START_CC_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    Std_ReturnType stdRet = E_NOT_OK;
    uint8 comM_ModeTypeBuf = CANSM_VALUE_ZERO;

    /* Evaluate the trigger and condition for sub state of START_CC_WAIT and Do the next move. */
    if( CANSM_T_CC_STARTED_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {
        /* Clear repeat count. */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
        /* The timer of mode requests turn off. */
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        /* Change the state of CanSM main state machine to FULLCOM. */
        comM_ModeTypeBuf = COMM_FULL_COMMUNICATION;
        /* Evaluate the trigger and condition for sub state of START_CC_WAIT and Do the next move. */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        stdRet = CanIf_SetPduMode(bsmSta->ManagerNetworkPtr->ControllerId, CANIF_ONLINE);
        if( E_OK == stdRet )
        {
            /* The BsmSta state jumps: CANSM_BSM_S_CHANGE_BAUDRATE --> CANSM_BSM_S_FULLCOM */
            bsmSta->BsmSta = CANSM_BSM_S_FULLCOM;
            /* Set the Sub_FULLCOM state --> CANSM_S_BUS_OFF_CHECK */
            bsmSta->BsmSub.BsmSta_Sub_FULLCOM = CANSM_S_BUS_OFF_CHECK;
            /* Clear Baudrate modification request. */
            bsmSta->changeBRIdRequest = CANSM_T_NOT_CHANGE_BR_REQUEST;
            /* ComM CBK Func. */
            ComM_BusSM_ModeIndication(bsmSta->ManagerNetworkPtr->ComMNetworkHandle, &comM_ModeTypeBuf);
#if( CANSM_BSWMENABLED == STD_ON )
            BswM_CanSM_CurrentState(bsmSta->ManagerNetworkPtr->ComMNetworkHandle,CANSM_BSWM_FULL_COMMUNICATION);
#endif  /* CANSM_BSWMENABLED == STD_ON */
        }
    }
    else
    {
        /* The timer of mode requests is not expired. */
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        else /* SWS_CanSM_00527 */
        {
            /* The Sub_WUVALIDATION state jumps: CC_START_WAIT --> CANSM_S_CBR_START_CC */
            bsmSta->BsmSub.BsmSta_Sub_CHANGE_BAUDRATE = CANSM_S_CBR_START_CC;
            /* The timer of mode requests turn off. */
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }
}
#endif  /* CANSM_SET_BAUDRATE_API == STD_ON */

/*
********************************************************************************
* Function Name: CanSM_S_TX_TIMEOUT_EXCEPTION_S_CC_STOPPED
*
* Explanation: S_CC_STOPPED of CanSM module Sub State Machine TX_TIMEOUT_EXCEPTION
*              Processing.(Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_TX_TIMEOUT_EXCEPTION_S_CC_STOPPED
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
    CanIf_ControllerModeType controllerMode = CANIF_CS_UNINIT;
    Std_ReturnType stdRet;

    CANSM_DUMMY_STATEMENT(controllerMode);
    /* SWS_CanSM_00579 */
    if( (CANSM_T_CC_STOPPED_INDICATED == bsmSta->BsmTrg_ControllerMode) )
    {
        /* The Sub_TX_TIMEOUT_EXCEPTION state jumps: CC_STOPPED --> CC_STARTED */
        bsmSta->BsmSub.BsmSta_Sub_TXTIMEOUTEXCEPTION = CANSM_TX_TIMEOUT_EXCEPTION_S_CC_STARTED;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        /* Set CAN controller mode state to CANIF_CS_STARTED. */
        stdRet = CanIf_SetControllerMode(
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        bsmSta->ManagerNetworkPtr->ControllerId, CANIF_CS_STOPPED);
        /* SWS_CanSM_00577 */
        if( E_OK == stdRet )
        {
            /* The Sub_TX_TIMEOUT_EXCEPTION state jumps: CC_STOPPED --> CC_STOPPED_WAIT */
            bsmSta->BsmSub.BsmSta_Sub_TXTIMEOUTEXCEPTION = CANSM_TX_TIMEOUT_EXCEPTION_S_CC_STOPPED_WAIT;
            /* The timer of mode requests turn on. */
            bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
        }
        else
        {
            /* Count of repeat the API of the CanIf */
            bsmSta->repeatCount++;
            /* SWS_CANSM_00575 */
            if( CANSM_MODE_REQ_REPETITION_MAX < bsmSta->repeatCount )
            {
                /* The BsmSta state jumps: CANSM_BSM_S_FULLCOM --> CANSM_BSM_S_PRE_NOCOM */
                bsmSta->BsmSta = CANSM_BSM_S_PRE_NOCOM;
                /* Clear repeat count */
                bsmSta->repeatCount = CANSM_VALUE_ZERO;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_TX_TIMEOUT_EXCEPTION_S_CC_STOPPED_WAIT
*
* Explanation: S_CC_STOPPED_WAIT of CanSM module Sub State Machine TX_TIMEOUT_EXCEPTION
*              Processing.(Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_TX_TIMEOUT_EXCEPTION_S_CC_STOPPED_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* SWS_CanSM_00579 */
    if( CANSM_T_CC_STOPPED_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {
        /* The Sub_TX_TIMEOUT_EXCEPTION state jumps: CC_STOPPED_WAIT --> CC_STARTED */
        bsmSta->BsmSub.BsmSta_Sub_TXTIMEOUTEXCEPTION = CANSM_TX_TIMEOUT_EXCEPTION_S_CC_STARTED;
        /* The timer of mode requests turn off. */
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    /* SWS_CanSM_00576 */
    else
    {
        /* The timer of mode requests is not expired. */
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        /* The timer of mode requests is expired. */
        else
        {
            /* The Sub_TX_TIMEOUT_EXCEPTION state jumps: CC_STOPPED_WAIT --> CC_STOPPED */
            bsmSta->BsmSub.BsmSta_Sub_TXTIMEOUTEXCEPTION = CANSM_TX_TIMEOUT_EXCEPTION_S_CC_STOPPED;
            /* The timer of mode requests turn off. */
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_TX_TIMEOUT_EXCEPTION_S_CC_STARTED
*
* Explanation: S_CC_STARTED of CanSM module Sub State Machine TX_TIMEOUT_EXCEPTION
*              Processing.(Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_TX_TIMEOUT_EXCEPTION_S_CC_STARTED
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
    CanIf_ControllerModeType controllerMode = CANIF_CS_UNINIT;
    Std_ReturnType stdRet;

    CANSM_DUMMY_STATEMENT(controllerMode);
    /* Check ControllerMode is STARTED. */
    if( (CANSM_T_CC_STARTED_INDICATED == bsmSta->BsmTrg_ControllerMode) )
    {
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;

        /* Set pdumode state to CANIF_ONLINE */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        stdRet = CanIf_SetPduMode(bsmSta->ManagerNetworkPtr->ControllerId, CANIF_ONLINE);
        if( E_OK == stdRet)
        {
            /* The Sub_FULLCOM state jumps: CANSM_S_TX_TIMEOUT_EXCEPTION --> CANSM_S_BUS_OFF_CHECK */
            bsmSta->BsmSub.BsmSta_Sub_FULLCOM = CANSM_S_BUS_OFF_CHECK;
            /* Clean BsmTrg_TxTimeout. */
            bsmSta->BsmTrg_TxTimeout = CANSM_T_NOT_TXTIMEOUT;
        }
    }
    else
    {
        /* Set CAN controller mode state to CANIF_CS_STARTED. */
        stdRet = CanIf_SetControllerMode(
            /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
            bsmSta->ManagerNetworkPtr->ControllerId, CANIF_CS_STARTED);
        /* SWS_CanSM_00581 */
        if( E_OK == stdRet )
        {
            /* The Sub_TX_TIMEOUT_EXCEPTION state jumps: STARTED --> STARTED_WAIT */
            bsmSta->BsmSub.BsmSta_Sub_TXTIMEOUTEXCEPTION = CANSM_TX_TIMEOUT_EXCEPTION_S_CC_STARTED_WAIT;
            /* The timer of mode requests turn on. */
            bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
        }
        else
        {
            /* Count of repeat the API of the CanIf */
            bsmSta->repeatCount++;
            /* SWS_CANSM_00575 */
            if( CANSM_MODE_REQ_REPETITION_MAX < bsmSta->repeatCount )
            {
                /* The BsmSta state jumps: CANSM_BSM_S_FULLCOM --> CANSM_BSM_S_PRE_NOCOM */
                bsmSta->BsmSta = CANSM_BSM_S_PRE_NOCOM;
                /* Clear repeat count */
                bsmSta->repeatCount = CANSM_VALUE_ZERO;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_TX_TIMEOUT_EXCEPTION_S_CC_STARTED_WAIT
*
* Explanation: STARTED_CC_WAIT of CanSM module Sub State Machine TX_TIMEOUT_EXCEPTION
*              Processing.(Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_TX_TIMEOUT_EXCEPTION_S_CC_STARTED_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
    CanIf_ControllerModeType controllerMode = CANIF_CS_UNINIT;
    Std_ReturnType stdRet;

    CANSM_DUMMY_STATEMENT(controllerMode);
    /* SWS_CanSM_00580 */
    if( (CANSM_T_CC_STARTED_INDICATED == bsmSta->BsmTrg_ControllerMode) )
    {
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;

        /* Set CAN pdumode state to CANIF_ONLINE. */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        stdRet = CanIf_SetPduMode(bsmSta->ManagerNetworkPtr->ControllerId, CANIF_ONLINE);
        if( E_OK == stdRet)
        {
            /* The Sub_FULLCOM state jumps: CANSM_S_TX_TIMEOUT_EXCEPTION --> CANSM_S_BUS_OFF_CHECK */
            bsmSta->BsmSub.BsmSta_Sub_FULLCOM = CANSM_S_BUS_OFF_CHECK;
            /* Clean BsmTrg_TxTimeout. */
            bsmSta->BsmTrg_TxTimeout = CANSM_T_NOT_TXTIMEOUT;
            /* The timer of mode requests turn off. */
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }
    /* SWS_CanSM_00576 */
    else
    {
        /* The timer of mode requests is not expired. */
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        /* The timer of mode requests is expired. */
        else
        {
            /* The state machine jumps: CC_STARTED_WAIT --> CC_STARTED */
            bsmSta->BsmSub.BsmSta_Sub_TXTIMEOUTEXCEPTION = CANSM_TX_TIMEOUT_EXCEPTION_S_CC_STARTED;
            /* The timer of mode requests turn off. */
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_Det_ErrorReport
*
* Explanation: Report error to Det Module.
*              (Synchronous)
*
* param: ApiId: the service Id of CanSM.
*        errorId: Error Id defined in CanIf_Types.h.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_Det_ErrorReport
(
    uint8 ApiId,
    uint8 errorId
)
{
#if( CANSM_DEV_ERROR_DETECT == STD_ON )
    if( errorId != CANSM_E_NO_ERR )     /* Error detected. */
    {
        /* Report Error to Det. */
        (void)Det_ReportError(CANSM_MODULE_ID, CANSM_INSTANCE_ID_DET, ApiId, errorId);
    }
#else
    {
        CANSM_DUMMY_STATEMENT(ApiId);
        CANSM_DUMMY_STATEMENT(errorId);
    }
#endif  /* CANSM_DEV_ERROR_DETECT == STD_ON */
}

/*
********************************************************************************
* Function Name: CanSM_SearchIdxByNetWork
*
* Explanation: Search Idx By NetWork Id.
*              (Synchronous)
*
* param: network: Affected CAN network.
*        IndexPtr: Index buf.
*
* retval: errorId
********************************************************************************
*/
static FUNC(Std_ReturnType, CANSM_CODE) CanSM_SearchIdxByNetWork
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
    NetworkHandleType network,
    P2VAR(uint8, AUTOMATIC, CANSM_APPL_DATA) IndexPtr
)
{
    Std_ReturnType stdRet = E_NOT_OK;
    uint8 index;

    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( NULL_PTR != IndexPtr )
    {
        /* Search the network index by ComMNetworkHandle. */
        for( index = CANSM_VALUE_ZERO; index < CANSM_MANAGER_NW_NUM; index++ )
        {
            if( network == CanSM_BsmChn[index].ManagerNetworkPtr->ComMNetworkHandle )
            {
                *IndexPtr = index;
                stdRet = E_OK;
                break;
            }
        }
    }

    return stdRet;
}

/*
********************************************************************************
* Function Name: CanSM_SearchIdxByNetWork
*
* Explanation: Search Idx By Controller Id.
*              (Synchronous)
*
* param: ControllerId: Controller Id.
*        IndexPtr: Index buf.
*
* retval: errorId
********************************************************************************
*/
static FUNC(Std_ReturnType, CANSM_CODE) CanSM_SearchIdxByControllerId
(
    uint8 ControllerId,
    P2VAR(uint8, AUTOMATIC, CANSM_APPL_DATA) IndexPtr
)
{
    Std_ReturnType stdRet = E_NOT_OK;
    uint8 index;

    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( NULL_PTR != IndexPtr )   /* Check NULL_PTR. */
    {
        /* Search the network index by ControllerId. */
        for( index = CANSM_VALUE_ZERO; index < CANSM_MANAGER_NW_NUM; index++ )
        {
            if( ControllerId == CanSM_BsmChn[index].ManagerNetworkPtr->ControllerId )
            {
                *IndexPtr = index;
                stdRet = E_OK;
                break;
            }
        }
    }

    return stdRet;
}

/*
********************************************************************************
* Function Name: CanSM_SearchIdxByTransceiverId
*
* Explanation: Search Idx By Transceiver Id.
*              (Synchronous)
*
* param: TransceiverId: Transceiver Id.
*        IndexPtr: Index buf.
*
* retval: errorId
********************************************************************************
*/
static FUNC(Std_ReturnType, CANSM_CODE) CanSM_SearchIdxByTransceiverId
(
    uint8 TransceiverId,
    P2VAR(uint8, AUTOMATIC, CANSM_APPL_DATA) IndexPtr
)
{
    Std_ReturnType stdRet = E_NOT_OK;
    uint8 index;

    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( NULL_PTR != IndexPtr )  /* Check NULL_PTR. */
    {
        /* Search the network index by TransceiverId. */
        for( index = CANSM_VALUE_ZERO; index < CANSM_MANAGER_NW_NUM; index++ )
        {
            if( TransceiverId == CanSM_BsmChn[index].ManagerNetworkPtr->TransceiverId )
            {
                *IndexPtr = index;
                stdRet = E_OK;
                break;
            }
        }
    }

    return stdRet;
}

/*
********************************************************************************
* Function Name: CanSM_GetBusOffRecoveryLevel
*
* Explanation: Provide internal bus-off recovery level.
*              (Synchronous)
*
* param: network: Index of the Network Channel.
*        busOffRecoveryLevelPtr[out]: Point to the bus-off recovery level.
*
* retval: E_OK: Service accepted.
*         E_NOT_OK: Service rejected.
********************************************************************************
*/
FUNC(Std_ReturnType, CANSM_CODE) CanSM_GetBusOffRecoveryLevel
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
    NetworkHandleType network,
    P2VAR(CanSM_BusOffRecoveryLevelType, AUTOMATIC, CANSM_APPL_DATA) busOffRecoveryLevelPtr
)
{
    uint8 errorId = CANSM_E_NO_ERR;
    uint8 index = CANSM_VALUE_ZERO;
    Std_ReturnType stdRet = E_NOT_OK;

    if( CANSM_INITED != CanSM_InitFlag )
    {
        errorId = CANSM_E_UNINIT;
    }
    else if( E_NOT_OK == CanSM_SearchIdxByNetWork(network, &index) )
    {
        errorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
    else if( NULL_PTR == busOffRecoveryLevelPtr )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CANSM_E_PARAM_POINTER;
    }
    else
    {
        if( CANSM_VALUE_ZERO == CanSM_BsmChn[index].Bsm_RecCnt_BUS_OFF )
        {
            /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanSM_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.14" */
            *busOffRecoveryLevelPtr = CANSM_NO_BUSOFF;
        }
        else if( CanSM_BsmChn[index].Bsm_RecCnt_BUS_OFF <= CanSM_ManagerNetworkCfg[index].BorCounterL1ToL2 )
        {
            /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanSM_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.14" */
            *busOffRecoveryLevelPtr = CANSM_BUSOFFRECOVERY_LEVEL1;
        }
        else
        {
            /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanSM_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.14" */
            *busOffRecoveryLevelPtr = CANSM_BUSOFFRECOVERY_LEVEL2;
        }
        stdRet = E_OK;
    }

    CanSM_Det_ErrorReport(CANSM_SERVICEID_GETBORLEVEL, errorId);

    return stdRet;
}

#ifdef CANSM_OSEKNM_ENABLE
/* Start */
/*
********************************************************************************
* Function Name: D_Init
*
* Explanation: Initialize CAN controller.
*              (Synchronous)
*
* param: initParam: status.
*
* retval: None
********************************************************************************
*/
FUNC(void, CANSM_CODE) D_Init
(
    D_Init_ParameterType initParam
)
{
    Std_ReturnType stdRet = E_NOT_OK;

    if( D_Init_BusInit == initParam )
    {
        stdRet = CanIf_SetControllerMode(D_OSEK_CAN_CONTROLLERID, CANIF_CS_STARTED);
    }
    else if( D_Init_BusShutDown == initParam )
    {
        stdRet = CanIf_SetControllerMode(D_OSEK_CAN_CONTROLLERID, CANIF_CS_STOPPED);
    }
    else if( D_Init_BusRestart == initParam )
    {
        stdRet = CanIf_SetControllerMode(D_OSEK_CAN_CONTROLLERID, CANIF_CS_STARTED);
    }
    else if( D_Init_BusSleep == initParam )
    {
        stdRet = CanIf_SetControllerMode(D_OSEK_CAN_CONTROLLERID, CANIF_CS_SLEEP);
    }
    else if( D_Init_BusAwake == initParam )
    {
        stdRet = CanIf_SetControllerMode(D_OSEK_CAN_CONTROLLERID, CANIF_CS_STARTED);
    }
    else
    {
        /* Do nothing. */
    }
}

/*
********************************************************************************
* Function Name: D_Online
*
* Explanation: Start CAN controller.
*              (Synchronous)
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, CANSM_CODE) D_Online
(
    void
)
{
    Std_ReturnType stdRet = E_NOT_OK;

    stdRet = CanIf_SetPduMode(D_OSEK_CAN_CONTROLLERID, CANIF_ONLINE);
}

/*
********************************************************************************
* Function Name: D_Offline
*
* Explanation: Stop CAN controller.
*              (Synchronous)
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, CANSM_CODE) D_Offline
(
    void
)
{
    Std_ReturnType stdRet = E_NOT_OK;

    stdRet = CanIf_SetPduMode(D_OSEK_CAN_CONTROLLERID, CANIF_OFFLINE);
}
/* End */
#endif  /* CANSM_OSEKNM_ENABLE */

/*
********************************************************************************
* Function Name: CanSM_Bsm_PreNoCom_SubState_Init
*
* Explanation: PRE_NOCOM of CanSM module sub-state initialization.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_Bsm_PreNoCom_SubState_Init
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
#if( CANSM_CANTRCV_PN_SUPPORT == STD_ON )
    if( TRUE == bsmSta->ManagerNetworkPtr->trcvPnEnable )
    {
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_CLEAR_WUF;
        bsmSta->Trg_ClearWUF_Indication = CANSM_T_CLEAR_WUF_NO_IDC;
        bsmSta->Trg_CheckWF_Indication = CANSM_T_CHECK_WFLAG_NO_IDC;
    }
    else
#endif  /* CANSM_CANTRCV_PN_SUPPORT == STD_ON */
    {
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_CC_STOPPED;
    }
}

#if( CANSM_CANTRCV_PN_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: CanSM_Bsm_DeinitPnSupported
*
* Explanation: PRE_NOCOM of CanSM module sub-state: deinit if Pn-Supported.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_Bsm_DeinitPnSupported
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* Define current sub state. */
    CanSM_Bsm_Sub_PRENOCOMType subState = bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM;
    do
    {
        /* Get current substate machine. */
        subState = bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM;
        /* Sub state machine of CanSM_PRE_NOCOM. */
        switch( bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM )
        {
            case CANSM_S_PNC_PN_CLEAR_WUF:
                CanSM_S_PNC_PN_CLEAR_WUF(bsmSta);
                break;
            case CANSM_S_PNC_PN_CLEAR_WUF_WAIT:
                CanSM_S_PNC_PN_CLEAR_WUF_WAIT(bsmSta);
                break;
            case CANSM_S_PNC_PN_CC_STOPPED:
                CanSM_S_PNC_PN_CC_STOPPED(bsmSta);
                break;
            case CANSM_S_PNC_PN_CC_STOPPED_WAIT:
                CanSM_S_PNC_PN_CC_STOPPED_WAIT(bsmSta);
                break;
            case CANSM_S_PNC_PN_TRCV_NORMAL:
                CanSM_S_PNC_PN_TRCV_NORMAL(bsmSta);
                break;
            case CANSM_S_PNC_PN_TRCV_NORMAL_WAIT:
                CanSM_S_PNC_PN_TRCV_NORMAL_WAIT(bsmSta);
                break;
            case CANSM_S_PNC_PN_TRCV_STANDBY:
                CanSM_S_PNC_PN_TRCV_STANDBY(bsmSta);
                break;
            case CANSM_S_PNC_PN_TRCV_STANDBY_WAIT:
                CanSM_S_PNC_PN_TRCV_STANDBY_WAIT(bsmSta);
                break;
            case CANSM_S_PNC_PN_CC_SLEEP:
                CanSM_S_PNC_PN_CC_SLEEP(bsmSta);
                break;
            case CANSM_S_PNC_PN_CC_SLEEP_WAIT:
                CanSM_S_PNC_PN_CC_SLEEP_WAIT(bsmSta);
                break;
            case CANSM_S_PNC_CHECK_WFLAG_IN_CC_SLEEP:
                CanSM_S_PNC_CHECK_WFLAG_IN_CC_SLEEP(bsmSta);
                break;
            case CANSM_S_PNC_CHECK_WUF_IN_CC_SLEEP_WAIT:
                CanSM_S_PNC_CHECK_WUF_IN_CC_SLEEP_WAIT(bsmSta);
                break;
            case CANSM_S_PNC_CHECK_WFLAG_IN_NOT_CC_SLEEP:
                CanSM_S_PNC_CHECK_WFLAG_IN_NOT_CC_SLEEP(bsmSta);
                break;
            case CANSM_S_PNC_CHECK_WUF_IN_NOT_CC_SLEEP_WAIT:
                CanSM_S_PNC_CHECK_WUF_IN_NOT_CC_SLEEP_WAIT(bsmSta);
                break;
            default:
                /* do nothing */
                break;
        }
    /* Handle all substate machine jumps. */
    }while( subState != bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM );

}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_PN_CLEAR_WUF
*
* Explanation: PN_CLEAR_WUF of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_CLEAR_WUF
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_CLEAR_WUF_INDICATED == bsmSta->Trg_ClearWUF_Indication )
    {
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_CC_STOPPED;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        /* SWS_CanSM_00438 */
        Std_ReturnType stdRet = CanIf_ClearTrcvWufFlag(bsmSta->ManagerNetworkPtr->TransceiverId);
        /* SWS_CanSM_00439 */
        if( E_OK == stdRet )
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_CLEAR_WUF_WAIT;
            bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
        }
        else
        {
            /* Count of repeat the API of the CanIf */
            bsmSta->repeatCount++;
            /* SWS_CanSM_00463 */
            if( CANSM_MODE_REQ_REPETITION_MAX < bsmSta->repeatCount )
            {
                /* The BsmSta_Sub_PRE_NOCOM state jumps: CANSM_S_PNC_PN_CC_STOPPED --> CANSM_S_PNC_PN_CLEAR_WUF */
                bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_CLEAR_WUF;
                /* Clear repeat count */
                bsmSta->repeatCount = CANSM_VALUE_ZERO;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_PN_CLEAR_WUF_WAIT
*
* Explanation: PN_CLEAR_WUF_WAIT of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_CLEAR_WUF_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_CLEAR_WUF_INDICATED == bsmSta->Trg_ClearWUF_Indication )
    {
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_CC_STOPPED;
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        else /* SWS_CanSM_00443 */
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_CLEAR_WUF;
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_PN_CC_STOPPED
*
* Explanation: PN_CC_STOPPED of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_CC_STOPPED
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_CC_STOPPED_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_TRCV_NORMAL;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        /* SWS_CanSM_00441 */
        Std_ReturnType stdRet = CanIf_SetControllerMode(bsmSta->ManagerNetworkPtr->ControllerId,
                                                        CANIF_CS_STOPPED);
        /* SWS_CanSM_00442 */
        if( E_OK == stdRet )
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_CC_STOPPED_WAIT;
            /* SWS_CanSM_00445 */
            bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
        }
        else
        {
            /* Count of repeat the API of the CanIf */
            bsmSta->repeatCount++;
            /* SWS_CanSM_00463 */
            if( CANSM_MODE_REQ_REPETITION_MAX < bsmSta->repeatCount )
            {
                /* The BsmSta_Sub_PRE_NOCOM state jumps: CANSM_S_PNC_PN_CC_STOPPED --> CANSM_S_PNC_PN_CLEAR_WUF */
                bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_CLEAR_WUF;
                /* Clear repeat count */
                bsmSta->repeatCount = CANSM_VALUE_ZERO;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_PN_CC_STOPPED_WAIT
*
* Explanation: PN_CC_STOPPED_WAIT of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_CC_STOPPED_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_CC_STOPPED_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_TRCV_NORMAL;
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        else
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_CC_STOPPED;
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_PN_TRCV_NORMAL
*
* Explanation: PN_TRCV_NORMAL of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_TRCV_NORMAL
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    CanTrcv_TrcvModeType canTrcvMode;
    if( (CANSM_T_TRCV_NORMAL_IDC == bsmSta->BsmTrg_TransceiverMode) ||
        ( (E_OK == CanIf_GetTrcvMode(&canTrcvMode, bsmSta->ManagerNetworkPtr->TransceiverId)) &&  /* PRQA S 3415 */ /* NSCA_QAC_CanSM_Rule13.5 */
          (CANTRCV_TRCVMODE_NORMAL == canTrcvMode) ) )
    {
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_TRCV_STANDBY;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        /* SWS_CanSM_00446 */
        Std_ReturnType stdRet = CanIf_SetTrcvMode(bsmSta->ManagerNetworkPtr->TransceiverId,
                                                  CANTRCV_TRCVMODE_NORMAL);
        /* SWS_CanSM_00447 */
        if( E_OK == stdRet )
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_TRCV_NORMAL_WAIT;
            /* SWS_CanSM_00449 */
            bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
        }
        else
        {
            /* Count of repeat the API of the CanIf */
            bsmSta->repeatCount++;
            /* SWS_CanSM_00463 */
            if( CANSM_MODE_REQ_REPETITION_MAX < bsmSta->repeatCount )
            {
                /* The BsmSta_Sub_PRE_NOCOM state jumps: CANSM_S_PNC_PN_TRCV_NORMAL --> CANSM_S_PNC_PN_CLEAR_WUF */
                bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_CLEAR_WUF;
                /* Clear repeat count */
                bsmSta->repeatCount = CANSM_VALUE_ZERO;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_PN_TRCV_NORMAL_WAIT
*
* Explanation: PN_TRCV_NORMAL_WAIT of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_TRCV_NORMAL_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_TRCV_NORMAL_IDC == bsmSta->BsmTrg_TransceiverMode )
    {
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_TRCV_STANDBY;
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        else
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_TRCV_NORMAL;
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }

}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_PN_TRCV_STANDBY
*
* Explanation: PN_TRCV_STANDBY of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_TRCV_STANDBY
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    CanTrcv_TrcvModeType canTrcvMode;
    if( (CANSM_T_TRCV_STANDBY_IDC == bsmSta->BsmTrg_TransceiverMode) ||
        ( (E_OK == CanIf_GetTrcvMode(&canTrcvMode, bsmSta->ManagerNetworkPtr->TransceiverId)) &&  /* PRQA S 3415 */ /* NSCA_QAC_CanSM_Rule13.5 */
          (CANTRCV_TRCVMODE_STANDBY == canTrcvMode) ) )
    {
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_CC_SLEEP;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        /* SWS_CanSM_00450 */
        Std_ReturnType stdRet = CanIf_SetTrcvMode(bsmSta->ManagerNetworkPtr->TransceiverId,
                                                  CANTRCV_TRCVMODE_STANDBY);
        /* SWS_CanSM_00451 */
        if( E_OK == stdRet )
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_TRCV_STANDBY_WAIT;
            bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
        }
        else
        {
            /* Count of repeat the API of the CanIf */
            bsmSta->repeatCount++;
            /* SWS_CanSM_00463 */
            if( CANSM_MODE_REQ_REPETITION_MAX < bsmSta->repeatCount )
            {
                /* The BsmSta_Sub_PRE_NOCOM state jumps: CANSM_S_PNC_PN_TRCV_STANDBY --> CANSM_S_PNC_PN_CLEAR_WUF */
                bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_CLEAR_WUF;
                /* Clear repeat count */
                bsmSta->repeatCount = CANSM_VALUE_ZERO;
            }
        }
    }

}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_PN_TRCV_STANDBY_WAIT
*
* Explanation: PN_TRCV_STANDBY_WAIT of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_TRCV_STANDBY_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_TRCV_STANDBY_IDC == bsmSta->BsmTrg_TransceiverMode )
    {
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_CC_SLEEP;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        else /* SWS_CanSM_00454 */
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_TRCV_STANDBY;
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }

}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_PN_CC_SLEEP
*
* Explanation: PN_CC_SLEEP of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_CC_SLEEP
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_CC_SLEEP_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_CHECK_WFLAG_IN_CC_SLEEP;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        /* SWS_CanSM_00453 */
        Std_ReturnType stdRet = CanIf_SetControllerMode(bsmSta->ManagerNetworkPtr->ControllerId,
                                                        CANIF_CS_SLEEP);
        /* SWS_CanSM_00455 */
        if( E_OK == stdRet )
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_CC_SLEEP_WAIT;
            bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
        }
        else
        {
            /* Count of repeat the API of the CanIf */
            bsmSta->repeatCount++;
            /* SWS_CanSM_00463 */
            if( CANSM_MODE_REQ_REPETITION_MAX < bsmSta->repeatCount )
            {
                /* The BsmSta_Sub_PRE_NOCOM state jumps: CANSM_S_PNC_CC_SLEEP --> CANSM_S_PNC_PN_CLEAR_WUF */
                bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_CLEAR_WUF;
                /* Clear repeat count */
                bsmSta->repeatCount = CANSM_VALUE_ZERO;
            }
        }
    }

}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_PN_CC_SLEEP_WAIT
*
* Explanation: PN_CC_SLEEP_WAIT of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_PNC_PN_CC_SLEEP_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_CC_SLEEP_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_CHECK_WFLAG_IN_CC_SLEEP;
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        else /* SWS_CanSM_00457 */
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_CHECK_WFLAG_IN_NOT_CC_SLEEP;
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }

}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_CHECK_WFLAG_IN_CC_SLEEP
*
* Explanation: CHECK_WUF_IN_CC_SLEEP of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_PNC_CHECK_WFLAG_IN_CC_SLEEP
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_CHECK_WFLAG_INDICATED == bsmSta->Trg_CheckWF_Indication )
    {
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
        CanSM_S_PNC_Exit(bsmSta);
    }
    else
    {
        /* SWS_CanSM_00458 */
        Std_ReturnType stdRet = CanIf_CheckTrcvWakeFlag(bsmSta->ManagerNetworkPtr->TransceiverId);
        /* SWS_CanSM_00459 */
        if( E_OK == stdRet )
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_CHECK_WUF_IN_CC_SLEEP_WAIT;
            bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
        }
        else
        {
            /* Count of repeat the API of the CanIf */
            bsmSta->repeatCount++;
            /* SWS_CanSM_00463 */
            if( CANSM_MODE_REQ_REPETITION_MAX < bsmSta->repeatCount )
            {
                /* The BsmSta_Sub_PRE_NOCOM state jumps: CANSM_S_PNC_CHECK_WFLAG_IN_CC_SLEEP --> CANSM_S_PNC_PN_CLEAR_WUF */
                bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_CLEAR_WUF;
                /* Clear repeat count */
                bsmSta->repeatCount = CANSM_VALUE_ZERO;
            }
        }
    }

}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_CHECK_WUF_IN_CC_SLEEP_WAIT
*
* Explanation: CHECK_WUF_IN_CC_SLEEP_WAIT of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_PNC_CHECK_WUF_IN_CC_SLEEP_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_CHECK_WFLAG_INDICATED == bsmSta->Trg_CheckWF_Indication )
    {
        CanSM_S_PNC_Exit(bsmSta);
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        else /* SWS_CanSM_00461 */
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_CHECK_WFLAG_IN_CC_SLEEP;
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }

}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_CHECK_WFLAG_IN_NOT_CC_SLEEP
*
* Explanation: CHECK_WUF_IN_NOT_CC_SLEEP of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_PNC_CHECK_WFLAG_IN_NOT_CC_SLEEP
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_CHECK_WFLAG_INDICATED == bsmSta->Trg_CheckWF_Indication )
    {
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_CLEAR_WUF;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        /* SWS_CanSM_00462 */
        Std_ReturnType stdRet = CanIf_CheckTrcvWakeFlag(bsmSta->ManagerNetworkPtr->TransceiverId);
        if( E_OK == stdRet )
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_CHECK_WUF_IN_NOT_CC_SLEEP_WAIT;
            bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
        }
        else
        {
            /* Count of repeat the API of the CanIf */
            bsmSta->repeatCount++;
            /* SWS_CanSM_00463 */
            if( CANSM_MODE_REQ_REPETITION_MAX < bsmSta->repeatCount )
            {
                /* The BsmSta_Sub_PRE_NOCOM state jumps: CANSM_S_PNC_CHECK_WFLAG_IN_NOT_CC_SLEEP --> CANSM_S_PNC_PN_CLEAR_WUF */
                bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_CLEAR_WUF;
                /* Clear repeat count */
                bsmSta->repeatCount = CANSM_VALUE_ZERO;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_CHECK_WUF_IN_NOT_CC_SLEEP_WAIT
*
* Explanation: CHECK_WUF_IN_NOT_CC_SLEEP_WAIT of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_PNC_CHECK_WUF_IN_NOT_CC_SLEEP_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_CHECK_WFLAG_INDICATED == bsmSta->Trg_CheckWF_Indication )
    {
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_PN_CLEAR_WUF;
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        else
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_CHECK_WFLAG_IN_NOT_CC_SLEEP;
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }

}

#endif  /* CANSM_CANTRCV_PN_SUPPORT == STD_ON */

/*
********************************************************************************
* Function Name: CanSM_Bsm_DeinitPnNotSupported
*
* Explanation: PRE_NOCOM of CanSM module sub-state: deinit if Pn-not-Supported.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_Bsm_DeinitPnNotSupported
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* Define current sub state. */
    CanSM_Bsm_Sub_PRENOCOMType subState = bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM;
    do
    {
        /* Get current substate machine. */
        subState = bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM;
        /* Sub state machine of CanSM_PRE_NOCOM. */
        switch( bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM )
        {
            case CANSM_S_PNC_CC_STOPPED:
                CanSM_S_PNC_CC_STOPPED(bsmSta);
                break;
            case CANSM_S_PNC_CC_STOPPED_WAIT:
                CanSM_S_PNC_CC_STOPPED_WAIT(bsmSta);
                break;
            case CANSM_S_PNC_CC_SLEEP:
                CanSM_S_PNC_CC_SLEEP(bsmSta);
                break;
            case CANSM_S_PNC_CC_SLEEP_WAIT:
                CanSM_S_PNC_CC_SLEEP_WAIT(bsmSta);
                break;
            case CANSM_S_PNC_TRCV_NORMAL:
                CanSM_S_PNC_TRCV_NORMAL(bsmSta);
                break;
            case CANSM_S_PNC_TRCV_NORMAL_WAIT:
                CanSM_S_PNC_TRCV_NORMAL_WAIT(bsmSta);
                break;
            case CANSM_S_PNC_TRCV_STANDBY:
                CanSM_S_PNC_TRCV_STANDBY(bsmSta);
                break;
            case CANSM_S_PNC_TRCV_STANDBY_WAIT:
                CanSM_S_PNC_TRCV_STANDBY_WAIT(bsmSta);
                break;
            default:
                /* do nothing */
                break;
        }
    /* Handle all substate machine jumps. */
    }while( subState != bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM );

}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_CC_STOPPED
*
* Explanation: CC_STOPPED of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_PNC_CC_STOPPED
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_CC_STOPPED_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {

#if( CANSM_PRENOCOM_SPCLHANDL_NOSLEEP == STD_ON )
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_TRCV_NORMAL;
#else
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_CC_SLEEP;
#endif  /* CANSM_PRENOCOM_SPCLHANDL_NOSLEEP == STD_ON */
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;

    }
    else
    {
        /* SWS_CanSM_00464 */
        /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanSM_UNMODIFIED_VAR_NOT_CONST" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        Std_ReturnType stdRet = CanIf_SetControllerMode(bsmSta->ManagerNetworkPtr->ControllerId,
                                                        CANIF_CS_STOPPED);
        /* SWS_CanSM_00465 */
        if( E_OK == stdRet )
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_CC_STOPPED_WAIT;
            /* SWS_CanSM_00467 */
            bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
        }
        else
        {
            /* Count of repeat the API of the CanIf */
            bsmSta->repeatCount++;
            /* SWS_CanSM_00480 */
            if( CANSM_MODE_REQ_REPETITION_MAX < bsmSta->repeatCount )
            {
                /* The BsmSta_Sub_PRE_NOCOM state jumps: CANSM_S_PNC_TRCV_STANDBY --> CANSM_S_PNC_CC_STOPPED */
                bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_CC_STOPPED;
                /* Clear repeat count */
                bsmSta->repeatCount = CANSM_VALUE_ZERO;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_CC_STOPPED_WAIT
*
* Explanation: CC_STOPPED_WAIT of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_PNC_CC_STOPPED_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_CC_STOPPED_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {

#if( CANSM_PRENOCOM_SPCLHANDL_NOSLEEP == STD_ON )
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_TRCV_NORMAL;
#else
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_CC_SLEEP;
#endif  /* CANSM_PRENOCOM_SPCLHANDL_NOSLEEP == STD_ON */

        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;

    }
    else
    {
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        else
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_CC_STOPPED;
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }

}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_CC_SLEEP
*
* Explanation: CC_SLEEP of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_PNC_CC_SLEEP
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_CC_SLEEP_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_TRCV_NORMAL;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        /* SWS_CanSM_00468 */
        /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanSM_UNMODIFIED_VAR_NOT_CONST" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        Std_ReturnType stdRet = CanIf_SetControllerMode(bsmSta->ManagerNetworkPtr->ControllerId,
                                                        CANIF_CS_SLEEP);
        /* SWS_CanSM_00469 */
        if( E_OK == stdRet )
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_CC_SLEEP_WAIT;
            bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
        }
        else
        {
            /* Count of repeat the API of the CanIf */
            bsmSta->repeatCount++;
            /* SWS_CanSM_00480 */
            if( CANSM_MODE_REQ_REPETITION_MAX < bsmSta->repeatCount )
            {
                /* The BsmSta_Sub_PRE_NOCOM state jumps: CANSM_S_PNC_CC_SLEEP --> CANSM_S_PNC_CC_STOPPED */
                bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_CC_STOPPED;
                /* Clear repeat count */
                bsmSta->repeatCount = CANSM_VALUE_ZERO;
            }
        }
    }

}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_CC_SLEEP_WAIT
*
* Explanation: CC_SLEEP_WAIT of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_PNC_CC_SLEEP_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_CC_SLEEP_INDICATED == bsmSta->BsmTrg_ControllerMode )
    {
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_TRCV_NORMAL;
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        else /* SWS_CanSM_00471 */
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_CC_SLEEP;
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }

}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_TRCV_NORMAL
*
* Explanation: TRCV_NORMAL of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_PNC_TRCV_NORMAL
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
#if( CANSM_CANTRCV_SUPPORT == STD_ON )
    if( TRUE == bsmSta->ManagerNetworkPtr->TransceiverEnable )
    {
        CanTrcv_TrcvModeType canTrcvMode;
        if( (CANSM_T_TRCV_NORMAL_IDC == bsmSta->BsmTrg_TransceiverMode) ||
            ( (E_OK == CanIf_GetTrcvMode(&canTrcvMode, bsmSta->ManagerNetworkPtr->TransceiverId)) &&  /* PRQA S 3415 */ /* NSCA_QAC_CanSM_Rule13.5 */
              (CANTRCV_TRCVMODE_NORMAL == canTrcvMode) ) )
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_TRCV_STANDBY;
            /* Clear repeat count */
            bsmSta->repeatCount = CANSM_VALUE_ZERO;
        }
        else
        {
            /* SWS_CanSM_00472 */
            Std_ReturnType stdRet = CanIf_SetTrcvMode(bsmSta->ManagerNetworkPtr->TransceiverId,
                                                      CANTRCV_TRCVMODE_NORMAL);
            /* SWS_CanSM_00473 */
            if( E_OK == stdRet )
            {
                bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_TRCV_NORMAL_WAIT;
                bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
            }
            else
            {
                /* Count of repeat the API of the CanIf */
                bsmSta->repeatCount++;
                /* SWS_CanSM_00480 */
                if( CANSM_MODE_REQ_REPETITION_MAX < bsmSta->repeatCount )
                {
                    /* The BsmSta_Sub_PRE_NOCOM state jumps: CANSM_S_PNC_TRCV_NORMAL --> CANSM_S_PNC_CC_STOPPED */
                    bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_CC_STOPPED;
                    /* Clear repeat count */
                    bsmSta->repeatCount = CANSM_VALUE_ZERO;
                }
            }
        }
    }
    else
    {
        /* SWS_CanSM_00556 */
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_TRCV_STANDBY;
    }
#else  /* CANSM_CANTRCV_SUPPORT == STD_ON */
    /* SWS_CanSM_00556 */
    bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_TRCV_STANDBY;
#endif  /* CANSM_CANTRCV_SUPPORT == STD_ON */

}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_TRCV_NORMAL_WAIT
*
* Explanation: TRCV_NORMAL_WAIT of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_PNC_TRCV_NORMAL_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_TRCV_NORMAL_IDC == bsmSta->BsmTrg_TransceiverMode )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_TRCV_STANDBY;
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        else /* SWS_CanSM_00475 */
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_TRCV_NORMAL;
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }

}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_TRCV_STANDBY
*
* Explanation: TRCV_STANDBY of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_PNC_TRCV_STANDBY
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
#if( CANSM_CANTRCV_SUPPORT == STD_ON )
    if( TRUE == bsmSta->ManagerNetworkPtr->TransceiverEnable )
    {
        CanTrcv_TrcvModeType canTrcvMode;
        if( (CANSM_T_TRCV_STANDBY_IDC == bsmSta->BsmTrg_TransceiverMode) ||
            ( (E_OK == CanIf_GetTrcvMode(&canTrcvMode, bsmSta->ManagerNetworkPtr->TransceiverId)) &&  /* PRQA S 3415 */ /* NSCA_QAC_CanSM_Rule13.5 */
              (CANTRCV_TRCVMODE_STANDBY == canTrcvMode) ) )
        {
            /* Clear repeat count */
            bsmSta->repeatCount = CANSM_VALUE_ZERO;
            CanSM_S_PNC_Exit(bsmSta);
        }
        else
        {
            /* SWS_CanSM_00476 */
            Std_ReturnType stdRet = CanIf_SetTrcvMode(bsmSta->ManagerNetworkPtr->TransceiverId,
                                                      CANTRCV_TRCVMODE_STANDBY);
            /* SWS_CanSM_00477 */
            if( E_OK == stdRet )
            {
                bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_TRCV_STANDBY_WAIT;
                bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
            }
            else
            {
                /* Count of repeat the API of the CanIf */
                bsmSta->repeatCount++;
                /* SWS_CanSM_00480 */
                if( CANSM_MODE_REQ_REPETITION_MAX < bsmSta->repeatCount )
                {
                    /* The BsmSta_Sub_PRE_NOCOM state jumps: CANSM_S_PNC_TRCV_STANDBY --> CANSM_S_PNC_CC_STOPPED */
                    bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_CC_STOPPED;
                    /* Clear repeat count */
                    bsmSta->repeatCount = CANSM_VALUE_ZERO;
                }
            }
        }
    }
    else
    {
        /* SWS_CanSM_00557 */
        CanSM_S_PNC_Exit(bsmSta);
    }
#else  /* CANSM_CANTRCV_SUPPORT == STD_ON */
    /* SWS_CanSM_00557 */
    CanSM_S_PNC_Exit(bsmSta);
#endif  /* CANSM_CANTRCV_SUPPORT == STD_ON */

}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_TRCV_STANDBY_WAIT
*
* Explanation: TRCV_STANDBY_WAIT of CanSM Sub State Machine PRE_NOCOM Processing.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_PNC_TRCV_STANDBY_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    if( CANSM_T_TRCV_STANDBY_IDC == bsmSta->BsmTrg_TransceiverMode )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
        CanSM_S_PNC_Exit(bsmSta);
    }
    else
    {
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        else /* SWS_CanSM_00479 */
        {
            bsmSta->BsmSub.BsmSta_Sub_PRE_NOCOM = CANSM_S_PNC_TRCV_STANDBY;
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }

}

/*
********************************************************************************
* Function Name: CanSM_S_PNC_Exit
*
* Explanation: Exit Processing of CanSM Sub State Machine PRE_NOCOM.
*              (Synchronous)
*
* param: bsmSta: One Channel of CanSM State Machine Struct Pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANSM_CODE) CanSM_S_PNC_Exit
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{

    if( CANSM_T_START_WAKEUP_SOURCE == bsmSta->BsmTrg_WAKEUP_SOURCE )
    {
        bsmSta->BsmSta = CANSM_BSM_WUVALIDATION;
        bsmSta->BsmSub.BsmSta_Sub_WUVALIDATION = CANSM_S_WU_TRCV_NORMAL;
    }
    else
    {
        /* SWS_CanSM_00430 */
        bsmSta->BsmSta = CANSM_BSM_S_NOCOM;
        /* SWS_CanSM_00651 */
        if( COMM_NO_COMMUNICATION == bsmSta->BsmTrg_MODE_REQUEST)
        {
            /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanSM_UNMODIFIED_VAR_NOT_CONST" */
            uint8 comM_ModeTypeBuf = COMM_NO_COMMUNICATION;
            /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
            ComM_BusSM_ModeIndication(bsmSta->ManagerNetworkPtr->ComMNetworkHandle, &comM_ModeTypeBuf);
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_TRCV_NORMAL
*
* Explanation: WUVALIDATION of CanSM module state machine processing.
*              (Synchronous)
*
* param: bsmSta: One channel of CanSM state machine struct pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_TRCV_NORMAL
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
#if( CANSM_CANTRCV_SUPPORT == STD_ON )
    CanTrcv_TrcvModeType canTrcvMode;
    Std_ReturnType stdRet;
    /* SWS_CANSM_00485 */
    if( TRUE == bsmSta->ManagerNetworkPtr->TransceiverEnable )
    {
        if( (CANSM_T_TRCV_NORMAL_IDC == bsmSta->BsmTrg_TransceiverMode) ||
            ((E_OK == CanIf_GetTrcvMode(&canTrcvMode, bsmSta->ManagerNetworkPtr->TransceiverId))  /* PRQA S 3415 */ /* NSCA_QAC_CanSM_Rule13.5 */
            && (CANTRCV_TRCVMODE_NORMAL == canTrcvMode)) )
        {
            /* The Sub_PRE_FULLCOM state jumps: TRCV_NORMAL --> CC_STOPPED */
            bsmSta->BsmSub.BsmSta_Sub_PRE_FULLCOM = CANSM_S_CC_STOPPED;
            /* Clear repeat count */
            bsmSta->repeatCount = CANSM_VALUE_ZERO;
        }
        else
        {
            /* SWS_CANSM_00483 */
            stdRet = CanIf_SetTrcvMode(
            bsmSta->ManagerNetworkPtr->TransceiverId, CANTRCV_TRCVMODE_NORMAL);
            /* SWS_CANSM_00484 */
            if ( E_OK == stdRet )
            {
                /* The Sub_PRE_FULLCOM state jumps: TRCV_NORMAL --> TRCV_NORMAL_WAIT */
                bsmSta->BsmSub.BsmSta_Sub_PRE_FULLCOM = CANSM_S_TRCV_NORMAL_WAIT;
                /* The timer of mode requests turn on. */
                bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
            }
            else
            {
                /* Count of repeat the API of the CanIf */
                bsmSta->repeatCount++;
                /* SWS_CANSM_00495 */
                if( CANSM_MODE_REQ_REPETITION_MAX < bsmSta->repeatCount )
                {
                    /* The BsmSta state jumps: CANSM_BSM_S_PRE_FULLCOM --> CANSM_BSM_S_PRE_NOCOM */
                    bsmSta->BsmSta = CANSM_BSM_S_PRE_NOCOM;
                    /* Clear repeat count */
                    bsmSta->repeatCount = CANSM_VALUE_ZERO;
                }
            }
        }
    }
    /* SWS_CANSM_00558 */
    else
    {
        bsmSta->BsmSub.BsmSta_Sub_PRE_FULLCOM = CANSM_S_CC_STOPPED;
    }
/* SWS_CANSM_00558 */
#else   /* CANSM_CANTRCV_SUPPORT == STD_ON */
    bsmSta->BsmSub.BsmSta_Sub_PRE_FULLCOM = CANSM_S_CC_STOPPED;
#endif  /* CANSM_CANTRCV_SUPPORT == STD_ON */
}

/*
********************************************************************************
* Function Name: CanSM_S_TRCV_NORMAL_WAIT
*
* Explanation: WUVALIDATION of CanSM module state machine processing.
*              (Synchronous)
*
* param: bsmSta: One channel of CanSM state machine struct pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_TRCV_NORMAL_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    CanTrcv_TrcvModeType canTrcvMode = CANTRCV_TRCVMODE_NORMAL;

    CANSM_DUMMY_STATEMENT(canTrcvMode);
    /* SWS_CANSM_00485 */
    if( (CANSM_T_TRCV_NORMAL_IDC == bsmSta->BsmTrg_TransceiverMode) )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* The Sub_PRE_FULLCOM state jumps: TRCV_NORMAL --> CC_STOPPED */
        bsmSta->BsmSub.BsmSta_Sub_PRE_FULLCOM = CANSM_S_CC_STOPPED;
        /* The timer of mode requests turn off. */
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    /* SWS_CANSM_00486 */
    else
    {
        /* The timer of mode requests is not expired. */
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        /* The timer of mode requests is expired. */
        else
        {
            /* The Sub_PRE_FULLCOM state jumps: TRCV_NORMAL_WAIT --> TRCV_NORMAL */
            bsmSta->BsmSub.BsmSta_Sub_PRE_FULLCOM = CANSM_S_TRCV_NORMAL;
            /* The timer of mode requests turn off. */
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_CC_STOPPED
*
* Explanation: WUVALIDATION of CanSM module state machine processing.
*              (Synchronous)
*
* param: bsmSta: One channel of CanSM state machine struct pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_CC_STOPPED
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
    CanIf_ControllerModeType controllerMode = CANIF_CS_UNINIT;
    Std_ReturnType stdRet;

    CANSM_DUMMY_STATEMENT(controllerMode);
    /* SWS_CANSM_00489 */
    if( (CANSM_T_CC_STOPPED_INDICATED == bsmSta->BsmTrg_ControllerMode) )
    {
        /* The Sub_PRE_FULLCOM state jumps: CC_STOPPED --> CC_STARTED */
        bsmSta->BsmSub.BsmSta_Sub_PRE_FULLCOM = CANSM_S_CC_STARTED;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    else
    {
        /* SWS_CANSM_00487 */
        stdRet = CanIf_SetControllerMode(
        /*  polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        bsmSta->ManagerNetworkPtr->ControllerId, CANIF_CS_STOPPED);
        /* SWS_CANSM_00488 */
        if( E_OK == stdRet )
        {
            /* The Sub_PRE_FULLCOM state jumps: CC_STOPPED --> CC_STOPPED_WAIT */
            bsmSta->BsmSub.BsmSta_Sub_PRE_FULLCOM = CANSM_S_CC_STOPPED_WAIT;
            /* The timer of mode requests turn on. */
            bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
        }
        else
        {
            /* Count of repeat the API of the CanIf */
            bsmSta->repeatCount++;
            /* SWS_CANSM_00495 */
            if( CANSM_MODE_REQ_REPETITION_MAX < bsmSta->repeatCount )
            {
                /* The BsmSta state jumps: CANSM_BSM_S_PRE_FULLCOM --> CANSM_BSM_S_PRE_NOCOM */
                bsmSta->BsmSta = CANSM_BSM_S_PRE_NOCOM;
                /* Clear repeat count */
                bsmSta->repeatCount = CANSM_VALUE_ZERO;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_CC_STOPPED_WAIT
*
* Explanation: WUVALIDATION of CanSM module state machine processing.
*              (Synchronous)
*
* param: bsmSta: One channel of CanSM state machine struct pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_CC_STOPPED_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
    CanIf_ControllerModeType controllerMode;
    /* SWS_CANSM_00489 */
    if( (CANSM_T_CC_STOPPED_INDICATED == bsmSta->BsmTrg_ControllerMode) ||
    /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        ((E_OK == CanIf_GetControllerMode(bsmSta->ManagerNetworkPtr->ControllerId,
        &controllerMode)) && (CANIF_CS_STOPPED == controllerMode)) )  /* PRQA S 3415 */ /* NSCA_QAC_CanSM_Rule13.5 */
    {
        /* The Sub_PRE_FULLCOM state jumps: CC_STOPPED_WAIT --> CC_STARTED */
        bsmSta->BsmSub.BsmSta_Sub_PRE_FULLCOM = CANSM_S_CC_STARTED;
        /* The timer of mode requests turn off. */
        bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;
    }
    /* SWS_CANSM_00490 */
    else
    {
        /* The timer of mode requests is not expired. */
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        /* The timer of mode requests is expired. */
        else
        {
            /* The Sub_PRE_FULLCOM state jumps: CC_STOPPED_WAIT --> CC_STOPPED */
            bsmSta->BsmSub.BsmSta_Sub_PRE_FULLCOM = CANSM_S_CC_STOPPED;
            /* The timer of mode requests turn off. */
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_CC_STARTED
*
* Explanation: WUVALIDATION of CanSM module state machine processing.
*              (Synchronous)
*
* param: bsmSta: One channel of CanSM state machine struct pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_CC_STARTED
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
    CanIf_ControllerModeType controllerMode = CANIF_CS_UNINIT;
    Std_ReturnType stdRet;
    uint8 comM_ModeTypeBuf;

    CANSM_DUMMY_STATEMENT(controllerMode);
    /* SWS_CANSM_00493 */
    if( (CANSM_T_CC_STARTED_INDICATED == bsmSta->BsmTrg_ControllerMode) )
    {
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;

        /* The state machine jumps: CANSM_BSM_S_PRE_FULLCOM --> CANSM_BSM_S_FULLCOM */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        stdRet = CanIf_SetPduMode(bsmSta->ManagerNetworkPtr->ControllerId, CANIF_ONLINE);
        if( E_OK == stdRet)
        {
            bsmSta->BsmSta = CANSM_BSM_S_FULLCOM;
            bsmSta->BsmSub.BsmSta_Sub_FULLCOM = CANSM_S_BUS_OFF_CHECK;
            /* ComM CBK Func. */
            comM_ModeTypeBuf = COMM_FULL_COMMUNICATION;
            ComM_BusSM_ModeIndication(bsmSta->ManagerNetworkPtr->ComMNetworkHandle, &comM_ModeTypeBuf);
#if( CANSM_BSWMENABLED == STD_ON )
            BswM_CanSM_CurrentState(bsmSta->ManagerNetworkPtr->ComMNetworkHandle, CANSM_BSWM_FULL_COMMUNICATION);
#endif  /* CANSM_BSWMENABLED == STD_ON */
        }
    }
    else
    {
        /* SWS_CANSM_00491 */
        stdRet = CanIf_SetControllerMode(
            /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
            bsmSta->ManagerNetworkPtr->ControllerId, CANIF_CS_STARTED);
        /* SWS_CANSM_00492 */
        if( E_OK == stdRet )
        {
            /* The Sub_PRE_FULLCOM state jumps: CC_STARTED --> STARTED_WAIT */
            bsmSta->BsmSub.BsmSta_Sub_PRE_FULLCOM = CANSM_S_CC_STARTED_WAIT;
            /* The timer of mode requests turn on. */
            bsmSta->modeRequestTimeout = CANSM_MODE_REQ_REPETITION_TIME;
        }
        else
        {
            /* Count of repeat the API of the CanIf */
            bsmSta->repeatCount++;
            /* SWS_CANSM_00495 */
            if( CANSM_MODE_REQ_REPETITION_MAX < bsmSta->repeatCount )
            {
                /* The BsmSta state jumps: CANSM_BSM_S_PRE_FULLCOM --> CANSM_BSM_S_PRE_NOCOM */
                bsmSta->BsmSta = CANSM_BSM_S_PRE_NOCOM;
                /* Clear repeat count */
                bsmSta->repeatCount = CANSM_VALUE_ZERO;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: CanSM_S_CC_STARTED_WAIT
*
* Explanation: WUVALIDATION of CanSM module state machine processing.
*              (Synchronous)
*
* param: bsmSta: One channel of CanSM state machine struct pointer.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
static FUNC(void, CANSM_CODE) CanSM_S_CC_STARTED_WAIT
(
    P2VAR(CanSM_BsmChnType, AUTOMATIC, CANSM_APPL_DATA) bsmSta
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
    CanIf_ControllerModeType controllerMode = CANIF_CS_UNINIT;
    Std_ReturnType stdRet;
    uint8 comM_ModeTypeBuf;

    CANSM_DUMMY_STATEMENT(controllerMode);
    /* SWS_CANSM_00493 */
    if( (CANSM_T_CC_STARTED_INDICATED == bsmSta->BsmTrg_ControllerMode) )
    {
        /* Clear repeat count */
        bsmSta->repeatCount = CANSM_VALUE_ZERO;

        /* The state machine jumps: CANSM_BSM_S_PRE_FULLCOM --> CANSM_BSM_S_FULLCOM */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanSM_PointerOutBounds" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule18.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.1" */
        stdRet = CanIf_SetPduMode(bsmSta->ManagerNetworkPtr->ControllerId, CANIF_ONLINE);
        if( E_OK == stdRet)
        {
            bsmSta->BsmSta = CANSM_BSM_S_FULLCOM;
            bsmSta->BsmSub.BsmSta_Sub_FULLCOM = CANSM_S_BUS_OFF_CHECK;
            /* ComM CBK Func. */
            comM_ModeTypeBuf = COMM_FULL_COMMUNICATION;
            ComM_BusSM_ModeIndication(bsmSta->ManagerNetworkPtr->ComMNetworkHandle, &comM_ModeTypeBuf);
#if( CANSM_BSWMENABLED == STD_ON )
            BswM_CanSM_CurrentState(bsmSta->ManagerNetworkPtr->ComMNetworkHandle, CANSM_BSWM_FULL_COMMUNICATION);
#endif  /* CANSM_BSWMENABLED == STD_ON */
        }
    }
    /* SWS_CANSM_00494 */
    else
    {
        /* The timer of mode requests is not expired. */
        if( bsmSta->modeRequestTimeout > CANSM_MAINFUNC_PERIOD )
        {
            bsmSta->modeRequestTimeout -= CANSM_MAINFUNC_PERIOD;
        }
        /* The timer of mode requests is expired. */
        else
        {
            /* The Sub_PRE_FULLCOM state jumps: CC_STARTED_WAIT --> CC_STARTED */
            bsmSta->BsmSub.BsmSta_Sub_PRE_FULLCOM = CANSM_S_CC_STARTED;
            /* The timer of mode requests turn off. */
            bsmSta->modeRequestTimeout = CANSM_VALUE_ZERO;
        }
    }
}

#define CANSM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


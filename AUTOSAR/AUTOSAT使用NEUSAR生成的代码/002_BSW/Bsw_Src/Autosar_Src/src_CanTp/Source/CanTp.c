/*
********************************************************************************
*
* File name: CanTp.c
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: TanLX/2018.12.10
* Change: New
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: TanLX/2019.04.15
* Change:
* (1) Delete invalid function.
* (2) Modify the prefix of the function and global variable.
* (3) Add det function.
* (4) Add autosar api.
* (5) Add comment.
* Cause: Modify
********************************************************************************
* Version: 1.2
* Author/Date: TongQ/2019.09.26
* Change: Modify QAC Check Warning.
* Cause: Optimization
********************************************************************************
* Version: 1.3
* Author/Date: TanLX/2019.10.12
* Change: Modify MIRSA-C code.
* Cause: Modify
********************************************************************************
* Version: 1.4
* Author/Date: songQW/2019.11.11
* Change: Add the TxPduId configurationinto to the CanTpRxSdu.
* Cause: update
********************************************************************************
* Version: 1.5
* Author/Date: LiuZY/2019.11.19
* Change: The format of code and comment.
* Cause: Modify the code according to the coding specification.
********************************************************************************
* Version: 1.6
* Author/Date: TanLX/2019.12.13
* Change: Checking out initial state before main function runs. Bug:NEUSCCORE-194.
* Cause: Modify logical error.
********************************************************************************
* Version: 1.7
* Author/Date: TanLX/2019.12.13
* Change: Delete invalid function "CanTp_TxIsIdle". Bug:NEUSCCORE-96.
* Cause: Checking out code according to Autosar article.
********************************************************************************
* Version: 1.8
* Author/Date: SongQW/2019.12.23
* Change: Modify the communication method with PduR and Dcm.
* Cause: Bugfix
********************************************************************************
* Version: 1.9
* Author/Date: SongQW/2019.12.23
* Change: Modify the communication method with Dcm.
* Cause: When receive a FC then cantp should get a tx pduId instead of rx pduId.
********************************************************************************
* Version: 1.10
* Author/Date: SongQW/2020.02.28
* Change: Add the CanTp_MemCmp function.
* Cause: Compare scenes.
********************************************************************************
* Version: 3.0
* Author/Date: SongQW/2020.03.25
* Change: Modify the function declaration and the type matching.
* Cause: Clear QAC warning and update to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date: SongQW/2020.03.30
* Change: Add comment.
* Cause: Coding specifications.
********************************************************************************
* Version: 3.2
* Author/Date: SongQW/2020.05.15
* Change: Modify the coding specification.
* Cause: Optimize
********************************************************************************
* Version: 3.3
* Author/Date: SongQW/2020.06.02
* Change: Modify SN number when received CF.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: SongQW/2020.07.15
* Change: (1) N_Ar is not timed out, ECU should respond to the message.
*         (2) N_Br is not timed out, the ECU should respond to the message.
*         (3) N_Cr is timeout, ECU should not respond to the CF sent by the tester.
*         (4) Send multiple FC.CTS to make the ECU enter to flow control and wait,
*             and the N_Bs time is reset, exit FC.CTS, then send FC, and the ECU
*             should respond to the valid flow control frame afterwards.
*         (5) FC_DLC<8byte, ECU should not send respond message.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: LiuZY/2020.08.22
* Change: Modify the error trigger parameter of the CanTp_Shutdown function.
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: ZhuCHY/2020.09.16
* Change: Add function of MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: ZhuCHY/2020.09.18
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: ZhuCHY/2020.09.29
* Change: Modify the FC response error.
* Cause: Bugfix
********************************************************************************
* Version: 3.9
* Author/Date: SongQW/2020.10.16
* Change: 1. Modify the code according to QAC.
*         2. Modify variables conform to AUTOSAR style.
*         3. Modify the macro definition to start with CANTP.
* Cause: MISRA-C:2018
********************************************************************************
* Version: 3.10
* Author/Date: SongQW/2020.10.16
* Change: 1. Modify CanTp_MemCpy function.
*         2. Modify CanTp_MemSet function.
*         3. Modify CanTp_MemCmp function.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: liuZY/2020.10.26
* Change: Modify the code specification format
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: LiuZY/2020.11.02
* Change: Modify the code format according to the code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: LiuZY/2020.11.03
* Change: Modify the interface declaration position according to the document.
* Cause: Optimization
********************************************************************************
* Version: 3.14
* Author/Date: LiuZY/2020.11.03
* Change: Modify the incorrectly defined part of the code format.
* Cause: Optimization
********************************************************************************
* Version: 3.15
* Author/Date: SongQW/2020.11.09
* Change: Modify the code according to QAC.
* Cause: MISRA-C:2018.
********************************************************************************
* Version: 3.16
* Author/Date: SongQW/2020.11.26
* Change: Modify the checking condition function of CanIf_Transmit.
* Cause: Bugfix
********************************************************************************
* Version: 3.17
* Author/Date: SongQW/2020.11.26
* Change: Cancel the length copy In CF process.
* Cause: Bugfix
********************************************************************************
* Version: 3.18
* Author/Date: SongQW/2020.12.4
* Change: Remove compilation warning.
* Cause: Bugfix
********************************************************************************
* Version: 3.19
* Author/Date: SongQW/2020.12.6
* Change: Modify the data length of CANFD message.
* Cause: Bugfix
********************************************************************************
* Version: 3.20
* Author/Date: SongQW/2020.12.22
* Change: Change CanTp_MemCpy and CanTp_MemSet function, operating the array
*         from uint32 to uint8.
* Cause: Bugfix
********************************************************************************
* Version: 3.21
* Author/Date: SongQW/2020.1.9
* Change: Modify the loop termination condition.
* Cause: Bugfix
********************************************************************************
* Version: 3.22
* Author/Date: ZhuCY/2021.4.13
* Change: Support CanTpOff: The transmit N-PDU does not use padding for SF, CF
*                           and the last CF.
* Cause: Bugfix
********************************************************************************
* Version: 3.23
* Author/Date: SongQW/2021.5.18
* Change: The sdu length of the first frame is not initialized for CANFD.
* Cause: Bugfix
********************************************************************************
* Version: 3.24
* Author/Date: SongQW/2021.6.7
* Change: When receiving CF, 3E 80 can't interrupt receiving CF.
* Cause: Bugfix
********************************************************************************
* Version: 3.25
* Author/Date: SongQW/2021.6.22
* Change: 3E 80 can't interrupt current state and restart the s3 timer.
* Cause: Bugfix
********************************************************************************
* Version: 3.26
* Author/Date: SongQW/2021.6.30
* Change: Calculate the block size for CANFD message different from CAN2.0.
* Cause: Bugfix
********************************************************************************
* Version: 3.27
* Author/Date: SongQW/2021.7.12
* Change: 1.3E 80 can't interrupt current state and restart the s3 timer, change
*           the function called from "Dcm_TmrMgrStartTimer" to
*           "Dcm_TmrMgrResetTimer".
*         2. Supports the reception of CAN2.0 and CANFD messages at the same
*            time.
* Cause: Bugfix
********************************************************************************
* Version: 3.28
* Author/Date: SongQW/2021.07.14
* Change: 1. Support the function of the CanTp data message length is greater
*         than 4095.
*         2. Block size of the FC is defined by configuration.
*         3. The type of the "bsCounter" change from uint8 to uint32.
* Cause: Bugfix
********************************************************************************
* Version: 3.29
* Author/Date: SongQW/2021.08.31
* Change: When cantp channels are not configued, the following array number should
*         be "CANTP_CHANNEL_NUM + 1U", which include array "CanTp_CanRxBuffer",
*         "CanTp_CanTxBuffer", "CanTp_RxState", "CanTp_TxState" and
*         "CanTp_TxSemaphore".
* Cause: Optimization
********************************************************************************
* Version: 3.30
* Author/Date: SongQW/2021.9.22
* Change: 1. Adjust the order of local variables, sorted by the type.
*         2. Channel status comparison judgment using the "CANTP_TXSTATE_IDLE".
*         3. Two-dimensional array remove the address character for the first
*            parameter in "CanTp_MemSet" function used in the "CanTp_Init"
*            function.
* Cause: Optimization
********************************************************************************
* Version: 3.31
* Author/Date: SongQW/2021.10.18
* Change: Re-update the tx pduId.
* Cause: Optimization
********************************************************************************
* Version: 3.32
* Author/Date: ZhuCY/2021.12.17
* Change: The transport/network layer transmits the SingleFrame/FirstFrame to
*         the data link layer and starts the N_As timer.
* Cause: Bugfix
********************************************************************************
* Version: 3.33
* Author/Date: SongQW/2022.01.26
* Change: FF_DL is 0 should not be replied in CAN2.0 mode .
* Cause: Bugfix
********************************************************************************
* Version: 3.34
* Author/Date: SongQW/2022.05.01
* Change: Adapt to the gateway mode.
* Cause: Optimization
********************************************************************************
* Version: 3.35
* Author/Date: ZhuCY/2022.06.17
* Change: Modify compile warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.36
* Author/Date: ZhuCY/2022.06.29
* Change: Modify the initial value of variable availableDataPtr in function
*         CanTp_Transmit_WithOutData.
* Cause: Bugfix
********************************************************************************
* Version: 3.37
* Author/Date: ZhuCY/2022.07.11
* Change: Modify the initial value of variable availableDataPtr in function
*         CanTp_CopyCFTxData.
* Cause: Bugfix
********************************************************************************
* Version: 3.38
* Author/Date: WuHW/2022.12.27
* Change: 1.Modify "3E 80 reset s3timer" to only support function addressing.
*         2.the length of first frame must be 8.
* Cause: Bugfix
********************************************************************************
* Version: 3.39
* Author/Date: WuHW/2023.03.01
* Change: Change the logic of the judgment about completion of the receive.
* Cause: Bugfix
********************************************************************************
* Version: 3.40
* Author/Date: SongQW/2023.05.04
* Change: Modify the "CanTp_TxInit" function about cleaning the flag for continue
*         to send data.
* Cause: Optimization
********************************************************************************
* Version: 3.41
* Author/Date: WuHW/2023.05.25
* Change: To initialize the local variable retry,which according to
*         CCOREDBUG-3057.
* Cause: Bugfix
********************************************************************************
* Version: 3.42
* Author/Date: TianG/2023.6.28
* Change: Increased the determination of continuous frame DLC length.
* Cause: Optimization
********************************************************************************
* Version: 3.43
* Author/Date: TianG/2023.7.24
* Change: CanFD handled of differernt DLC length.
* Cause: Optimization.
********************************************************************************
* Version: 3.44
* Author/Date: TianG/2023.9.19
* Change: Add Can Rx SF DLC Check.
* Cause: Optimization
********************************************************************************
* Version: 3.45
* Author/Date: TianG/2023.10.8
* Change: Modifying compile Warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.46
* Author/Date: YanCL/2024.3.19
* Change: Modify the P2CONST incorrect labels.
* Cause: Optimization
********************************************************************************
* Version: 3.47
* Author/Date: YanCL/2024.4.2
* Change: 1. Modify the P2CONST incorrect labels.
*         2. Modify the annotation.
* Cause: Optimization
********************************************************************************
* Version: 3.48
* Author/Date: YanCL/2024.7.3
* Change: 1.Add Memmap segment definition.
*         2.Update copyright information.
* Cause: Update
********************************************************************************
* Version: 3.49
* Author/Date: YanCL/2024.7.16
* Change: When the CAN FD diagnostic data length is greater than 8, the determination
*         of the valid DLC needs to comply with the ISO 15765-2:2016 standard.
* Cause: Bugfix
********************************************************************************
* Version: 3.50
* Author/Date: YanCL/2024.8.7
* Change: After being interrupted by new single or multiple frame requests during
*         CAN multi frame reception, it cannot be routed to LIN.
* Cause: Bugfix
********************************************************************************
* Version: 3.51
* Author/Date: YanCL/2024.8.28
* Change: Modify the calculation method for TxStmin in the
*         CanTp_GetTxStminFromStminValue function.
* Cause: Bugfix
********************************************************************************
* Version: 3.52
* Author/Date: YanCL/2024.8.30
* Change: Implement calling the CanTp_Transmit_TithOutData interface to send
*         data when CanTpTxInfoPtr ->SduDataStr is not empty.
* Cause: Update
********************************************************************************
* Version: 3.53
* Author/Date: YanCL/2024.9.27
* Change: Modify stmin calculation: When the stmin of the flow control frame
*         is less than CANTP_MAIN_PERIOD, the interval time between consecutive
*         frames is set to one cycle.
* Cause: Update
********************************************************************************
* Version: 3.54
* Author/Date: YanCL/2024.10.22
* Change: Delete Dcm_Cbk.h header file containing.
* Cause: Update
********************************************************************************
* Version: 3.55
* Author/Date: YanCL/2025.01.06
* Change: Initialize CanTp rx status by channel instead of all channels.
* Cause: Update
********************************************************************************
* Version: 3.56
* Author/Date: YanCL/2025.02.08
* Change: Function CanTp_TxApplTxConfirmation parameter error modification.
* Cause: Update
********************************************************************************
* Version: 3.57
* Author/Date: YanCL/2025.02.27
* Change: Resolve the issue of inability to forward function addressing 3E 80.
* Cause: Update
********************************************************************************
* Version: 3.58
* Author/Date: YanCL/2025.03.10
* Change: Configure the tool to select whether to correct the Tx CF Stmin time.
* Cause: Update
********************************************************************************
* Version: 3.59
* Author/Date: YanCL/2025.03.12
* Change: Fix the error access issue in the CanTpTxNSdu_st structure where the
*         CanTp_TransmitToCanIf_p member is concerned.
* Cause: Update
********************************************************************************
* Version: 3.60
* Author/Date: YanCL/2025.03.26
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.61
* Author/Date: YanCL/2025.05.15
* Change: When Stmin is equal to 0, send CF in the confirmation transmission.
* Cause: Update
********************************************************************************
* Version: 3.62
* Author/Date: YanCL/2025.06.03
* Change: Modify the CanTp_GetFFPCInfo function to not send FC when TX_DL is 8
*         and the FF_DL value is less than 8.
* Cause: Update
********************************************************************************
* Version: 3.63
* Author/Date: YanCL/2025.06.04
* Change: Modify the issue of incomplete initialization of CanTp_TxState in the
*         CanTp_init function.
* Cause: Update
********************************************************************************
* Version: 3.64
* Author/Date: YanCL/2025.06.06
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.65
* Author/Date: YanCL/2025.06.23
* Change: #include "CanTp_MemMap.h" add suppression comments.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "CanTp.h"
#include "CanIf.h"
#include "PduR_CanTp.h"
#include "CanTp_Lcfg.h"
#include "CanTp_Cbk.h"
#include "CanTp_Cfg.h"

#if( CANTP_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif

#include "SchM_CanTp.h"

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
#define CANTP_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"

static FUNC(void, CANTP_CODE) CanTp_CanIfRxIndication
(
    PduIdType rxPduId,
    PduInfoType pduInfoPtr
);
static FUNC(void, CANTP_CODE) CanTp_RxStateTask(void);
static FUNC(void, CANTP_CODE) CanTp_RxInit(uint8 chnId, uint8 notifyCode);
static FUNC(void, CANTP_CODE) CanTp_RxInitState(uint8 chnId);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
static FUNC(void, CANTP_CODE) CanTp_TxInit(PduIdType txPduId, uint8 notifyCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
static FUNC(void, CANTP_CODE) CanTp_TxCFTxConfirmation(PduIdType txPduId);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
static FUNC(void, CANTP_CODE) CanTp_TxStateTask(PduIdType txPduId, boolean withData);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
static FUNC(void, CANTP_CODE) CanTp_TxStateTask_CAN20(PduIdType txPduId, boolean withData);

#if( STD_ON == CANTP_CANFD_SUPPORT )
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
static FUNC(void, CANTP_CODE) CanTp_TxStateTask_CANFD(PduIdType txPduId, boolean withData);
#endif

/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
static FUNC(void, CANTP_CODE) CanTp_TxApplTxConfirmation(PduIdType txPduId, uint8 result);
static FUNC(void, CANTP_CODE) CanTp_Det_ErrorReport(uint8 apiId, uint8 errorId);
static FUNC(uint8, CANTP_CODE) CanTp_GetTxStminFromStminValue(uint8 stMinValue);

extern boolean Can_DiagVltgCondFlg;//luokai

static FUNC(uint8, CANTP_CODE) CanTp_RxSFDLCCheck
(
    uint8 CanTpRxPaddingActivation,
    uint8 rxDataLen,
    uint8 rxDlcLen
);
static FUNC(uint8, CANTP_CODE) CanTp_DLCCheckByDiffProtocol
(
    uint8 CanTpRxPaddingActivation,
    uint8 rxDataLen,
    uint8 rxDlcLen
);

static FUNC(uint8, CANTP_CODE) CanTp_GetFFPCIInfo
(
    uint8 rxDataLen,
    uint8 rxDlcLen,
    P2CONST(uint8, AUTOMATIC, CANTP_APPL_DATA) srcPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_APPL_DATA) offSet,
    P2VAR(PduLengthType, AUTOMATIC, CANTP_APPL_DATA) dataLen
);
static FUNC(void, CANTP_CODE) CanTp_MemSet
(
    P2VAR(void, AUTOMATIC, CANTP_APPL_DATA) destPtr,
    uint8 val,
    uint16 cnt
);
static FUNC(void, CANTP_CODE) CanTp_MemCpy
(
    P2VAR(uint8, AUTOMATIC, CANTP_APPL_DATA) destPtr,
    P2CONST(uint8, AUTOMATIC, CANTP_APPL_CONST) srcPtr,
    uint16 cnt
);
static FUNC(void, CANTP_CODE) CanTp_MainFunctionRx(void);
static FUNC(void, CANTP_CODE) CanTp_MainFunctionTx(void);
static FUNC(Std_ReturnType, CANTP_CODE) CanTp_Check_TransmitData
(
    PduIdType CanTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) CanTpTxInfoPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_APPL_DATA) ErrorId
);
static FUNC(Std_ReturnType, CANTP_CODE) CanTp_Transmit_WithData
(
    PduIdType CanTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) CanTpTxInfoPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_APPL_DATA) ErrorId
);
static FUNC(Std_ReturnType, CANTP_CODE) CanTp_Transmit_WithOutData
(
    PduIdType CanTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) CanTpTxInfoPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_APPL_DATA) ErrorId
);
static FUNC(void, CANTP_CODE) CanTp_CopyCFTxData
(
    uint8 chnId
);
static FUNC(uint8, CANTP_CODE) CanTp_CanIfRxSFTesterOnline
(
    uint8 chnId,
    PduIdType rxPduId,
    P2CONST(CanTpRxNSdu_st, AUTOMATIC, CANTP_APPL_DATA) rxSduPtr
);

#define CANTP_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define CANTP_START_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* TP receive data buffer. */
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanTp_NonSharedVar" */
VAR(uint8, CANTP_VAR_INIT) CanTp_CanRxBuffer[CANTP_CHANNEL_NUM + 1U][CANTP_REVDATALEN] = {{CANTP_ZERO}};  /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
/* TP send data buffer. */
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanTp_NonSharedVar" */
VAR(uint8, CANTP_VAR_INIT) CanTp_CanTxBuffer[CANTP_CHANNEL_NUM + 1U][CANTP_REVDATALEN] = {{CANTP_ZERO}};  /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanTp_NonSharedVar" */
static VAR(uint8, CANTP_VAR_INIT) CanTp_CanTxCopyBuffer[CANTP_CHANNEL_NUM + 1U][CANTP_REVDATALEN] = {{CANTP_ZERO}};
/* TP receive struct. */
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanTp_NonSharedVar" */
VAR(CanTp_RxStateType_st, CANTP_VAR_INIT) CanTp_RxState[CANTP_CHANNEL_NUM + 1U] =  /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
/* Polyspace +1 MISRA-C3:9.3 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule9.3" */
{{CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, NULL_PTR, CANTP_ZERO}};  /* PRQA S 0686 */ /* NSCA_QAC_CanTp_Rule9.3 */
/* TP send struct. */
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanTp_NonSharedVar" */
VAR(CanTp_TxStateType_st, CANTP_VAR_INIT) CanTp_TxState[CANTP_CHANNEL_NUM + 1U] =  /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
/* Polyspace +1 MISRA-C3:9.3 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule9.3" */
{{CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, CANTP_ZERO, NULL_PTR}};  /* PRQA S 0686 */ /* NSCA_QAC_CanTp_Rule9.3 */
/* TP initial flag. */
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanTp_NonSharedVar" */
VAR(CanTp_InitStatusType, CANTP_VAR_INIT) CanTp_InitState = CANTP_STATUS_NOT_INITIALIZED;  /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */

#define CANTP_STOP_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define CANTP_START_SEC_VAR_NO_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* The direction of operation,include send or receive. */
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanTp_NonSharedVar" */
VAR(uint8, CANTP_VAR_NO_INIT) CanTp_TxSemaphore[CANTP_CHANNEL_NUM + 1U];  /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */

#define CANTP_STOP_SEC_VAR_NO_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/

#define CANTP_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
* Function Name: CanTp_Det_ErrorReport
*
* Explanation: Function to report Error to Det.
*
* param: apiId: Unique Api ID of CANTP manager service.
*        errorId: Det Error ID of CANTP manager.
*
* retval: None
********************************************************************************
*/
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
static FUNC(void, CANTP_CODE) CanTp_Det_ErrorReport(uint8 apiId, uint8 errorId)
{

#if ( CANTP_DEV_ERROR_DETECT == STD_ON )
    if( errorId != CANTP_E_NO_ERROR ) /* Error detected. */
    {
        /* Report Error to Det. */
        (void)Det_ReportError(CANTP_MODULE_ID, CANTP_INSTANCE_ID_DET, apiId, errorId);
    }
#else
    {
        CANTP_DUMMY_STATEMENT(apiId); /* Dummy. */
        CANTP_DUMMY_STATEMENT(errorId);
    }
#endif

    return;
}

#if ( CANTP_VERSION_INFO_API == STD_ON )
/*
********************************************************************************
* Function Name: CanTp_GetVersionInfo
*
* Explanation: This function returns the version information of the CanTp module.
*
* param: versionInfo: Indicator as to where to store the version information of this module.
*
* retval: None
********************************************************************************
*/
FUNC(void, CANTP_CODE) CanTp_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CANTP_APPL_DATA) versionInfo
)
{
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
    uint8 errorId = CANTP_E_NO_ERROR;

    if( NULL_PTR == versionInfo ) /* Check parameter is null pointer. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CANTP_E_PARAM_POINTER;
    }
    else /* Set version info. */
    {
        /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.14" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanTp_TAINTED_PTR" */
        versionInfo->moduleID = CANTP_MODULE_ID;
        versionInfo->vendorID = CANTP_VENDOR_ID;
        versionInfo->sw_major_version = CANTP_SW_MAJOR_VERSION;
        versionInfo->sw_minor_version = CANTP_SW_MINOR_VERSION;
        versionInfo->sw_patch_version = CANTP_SW_PATCH_VERSION;
    }

    CanTp_Det_ErrorReport(CANTP_SID_GETVERSIONINFO, errorId);  /* Report det error. */

    return;
}
#endif

/*
********************************************************************************
* Function Name: CanTp_MemCpy
*
* Explanation: Copy value of the data.
*
* param: destPtr: Destination data.
*        srcPtr: Source data.
*        cnt: The length of the data.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANTP_CODE) CanTp_MemCpy
(
    P2VAR(uint8, AUTOMATIC, CANTP_APPL_DATA) destPtr,
    P2CONST(uint8, AUTOMATIC, CANTP_APPL_CONST) srcPtr,
    uint16 cnt
)
{
    /* Check the parameter. */
    if( (NULL_PTR != destPtr) && (NULL_PTR != srcPtr) && (CANTP_ZERO != cnt) )
    {
        while( cnt > CANTP_ZERO ) /* Check the number of the cycle. */
        {
            /* Polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
            cnt--; /* Subduction. */
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanTp_IDP" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_CanTp_NIV" */
            destPtr[cnt] = srcPtr[cnt]; /* Copy data. */
        }
    }
}

/*
********************************************************************************
* Function Name: CanTp_GetFFPCIInfo
*
* Explanation: To get the data length and the offset.
*
* param: rxDataLen: Data length.
*        rxDlcLen:Can Dlc length.
*        srcPtr: Data buffer.
*        offSet: Data offset.
*        dataLen: The length of the first frame.
*
* retval: E_OK: The length of the first frame is valid.
*         E_NOT_OK: The length of the first frame is invalid.
********************************************************************************
*/
static FUNC(uint8, CANTP_CODE) CanTp_GetFFPCIInfo
(
    uint8 rxDataLen,
    uint8 rxDlcLen,
    P2CONST(uint8, AUTOMATIC, CANTP_APPL_DATA) srcPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_APPL_DATA) offSet,
    P2VAR(PduLengthType, AUTOMATIC, CANTP_APPL_DATA) dataLen
)
{
    uint8 retVal = E_OK;
    PduLengthType ffDataLen = CANTP_ZERO;
    ffDataLen = CanTp_Make16Bit(srcPtr[CANTP_ZERO], srcPtr[CANTP_BYTE_ONE]);
    ffDataLen &= CANTP_FRAME_FFMASK;

    /* Bits3-0 of the BYTE0 is 0. */
    if( CANTP_ZERO == ffDataLen )
    {
        if( CANTP_LEN_CANFDDLC64 == rxDataLen )
        {
            /* Get the data length when the FF_DL > 4095. */
            ffDataLen = CanTp_Make32Bit(srcPtr[CANTP_BYTE_TWO], srcPtr[CANTP_BYTE_THREE],
                        srcPtr[CANTP_BYTE_FOUR], srcPtr[CANTP_BYTE_FIVE]);
            /* The data length <= 4095 is invalid.  */
            if( CANTP_FFDATALENGTH >= ffDataLen )
            {
                retVal = E_NOT_OK;
            }
            else
            {
                *dataLen = ffDataLen;
                *offSet = CANTP_BYTE_SIX; /* The offset is 6 when the FF_DL > 4095. */
            }
        }
        else
        {
            retVal = E_NOT_OK;
        }
    }
    else
    {
        /* Handling CAN FF. */
        if( CANTP_STANDARD_FRAME_LENGTH == rxDataLen )
        {
            /* Data length of the FF <= 7 is invalid. */
            if( rxDlcLen >= (ffDataLen + CANTP_BYTE_ONE) )
            {
                retVal = E_NOT_OK;
            }
            else
            {
                *dataLen = ffDataLen;
                *offSet = CANTP_BYTE_TWO; /* The offset is 2 when the FF_DL <= 4095. */
            }
        }
        /* Handling CANFD FF. */
        else if( CANTP_LEN_CANFDDLC64 == rxDataLen )
        {
            if( rxDlcLen > CANTP_LEN_CANFDDLC8 )
            {
                /* Data length of the FF <= rxDlcLen-2 is invalid. */
                if( rxDlcLen >= ( ffDataLen + CANTP_BYTE_TWO ) )
                {
                    retVal = E_NOT_OK;
                }
                else
                {
                    *dataLen = ffDataLen;
                    *offSet = CANTP_BYTE_TWO; /* The offset is 2 when the FF_DL <= 4095. */
                }
            }
            else if( rxDlcLen == CANTP_LEN_CANFDDLC8 )
            {
                /* Data length of the FF <= 7 is invalid. */
                if( rxDlcLen >= (ffDataLen + CANTP_BYTE_ONE) )
                {
                    retVal = E_NOT_OK;
                }
                else
                {
                    *dataLen = ffDataLen;
                    *offSet = CANTP_BYTE_TWO; /* The offset is 2 when the FF_DL <= 4095. */
                }
            }
            else
            /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                retVal = E_NOT_OK;
            }
        }
        else
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            retVal = E_NOT_OK;
        }
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: CanTp_RxSFDLCCheck
*
* Explanation: Check the length of Rx SF DLC.
*
* param: CanTpRxPaddingActivation: the receive frame uses padding or not.
*        rxDataLen: Data length.
*        rxDlcLen:Can Dlc length.
*
* retval: E_OK: The length of DLC is valid.
*         E_NOT_OK: The length of DLC is invalid.
********************************************************************************
*/
static FUNC(uint8, CANTP_CODE) CanTp_RxSFDLCCheck
(
    uint8 CanTpRxPaddingActivation,
    uint8 rxDataLen,
    uint8 rxDlcLen
)
{
    uint8 retVal = E_OK;

/* CANTP_GENERAL_VERSION */
#if( (CANTP_GENERAL_VERSION == CANTP_ISO15765_2_2011) || (CANTP_GENERAL_VERSION == CANTP_ISO15765_2_2016) )
    retVal = CanTp_DLCCheckByDiffProtocol(CanTpRxPaddingActivation, rxDataLen, rxDlcLen);
#else
    if( (uint8)CANTP_ON == CanTpRxPaddingActivation ) /* the receive frame uses padding */
    {
        if( CANTP_STANDARD_FRAME_LENGTH < rxDlcLen )
        {
            if( (CANTP_SF_MAX_LEN_CANFD < rxDataLen) || /* "dataLen > 62" is invalid. */
                (CANTP_SF_MIN_LEN == rxDataLen) ||  /* "dataLen = 0" is invalid. */
                ( (rxDataLen + CANTP_INIT_TWO) > rxDlcLen ) ) /* (dataLen+offset) > DLC is invalid. */
            {
                retVal = E_NOT_OK;
            }
        }
        else
        {
            if( (CANTP_SF_MAX_LEN < rxDataLen) ||  /* "dataLen > 8" is invalid. */
                (CANTP_SF_MIN_LEN == rxDataLen) ||  /* "dataLen == 0" is invalid. */
                ((rxDataLen + CANTP_INIT_ONE) > rxDlcLen ) )  /* (dataLen+offset) > DLC is invalid. */
            {
                retVal = E_NOT_OK;
            }
        }
    }
    else
    {
        retVal = CanTp_DLCCheckByDiffProtocol(CanTpRxPaddingActivation, rxDataLen, rxDlcLen);
    }

#endif  /* (CANTP_GENERAL_VERSION == CANTP_ISO15765_2_2011) || (CANTP_GENERAL_VERSION == CANTP_ISO15765_2_2016) */

    return retVal;
}

/*
********************************************************************************
* Function Name: CanTp_DLCCheckByDiffProtocol
*
* Explanation: Check Rx SF DLC length by diffrent protocol.
*
* param: CanTpRxPaddingActivation :the receive frame uses padding or not.
*        rxDataLen: Data length.
*        rxDlcLen:Can Dlc length.
*
* retval: E_OK: The length of DLC is valid.
*         E_NOT_OK: The length of DLC is invalid.
********************************************************************************
*/
static FUNC(uint8, CANTP_CODE) CanTp_DLCCheckByDiffProtocol(uint8 CanTpRxPaddingActivation,uint8 rxDataLen,uint8 rxDlcLen)
{
    uint8 retVal = E_OK;

    CANTP_DUMMY_STATEMENT(CanTpRxPaddingActivation);

    if( CANTP_LEN_CANFDDLC64 == rxDlcLen )
    {
        /* 47 <= SF_DL <= 62  is E_OK */
        if( ((CANTP_LEN_CANFDDLC48 - CANTP_INIT_ONE ) > rxDataLen) || ((CANTP_LEN_CANFDDLC64 - CANTP_INIT_TWO) < rxDataLen) )
        {
            /* SF_DL < 47 Or SF_DL > 62  is E_NOT_OK */
            retVal = E_NOT_OK;
        }
    }
    else if( CANTP_LEN_CANFDDLC48 == rxDlcLen )
    {
        /* 31 <= SF_DL <= 46 is E_OK*/
        if( ((CANTP_LEN_CANFDDLC32 - CANTP_INIT_ONE) > rxDataLen) || ((CANTP_LEN_CANFDDLC48 - CANTP_INIT_TWO) < rxDataLen) )
        {
            /* SF_DL < 31 Or SF_DL > 46  is E_NOT_OK */
            retVal = E_NOT_OK;
        }
    }
    else if( CANTP_LEN_CANFDDLC32 == rxDlcLen )
    {
        /* 23 <= SF_DL <= 30 is E_OK */
        if( ((CANTP_LEN_CANFDDLC24 - CANTP_INIT_ONE) > rxDataLen) || ((CANTP_LEN_CANFDDLC32 - CANTP_INIT_TWO) < rxDataLen) )
        {
            /* SF_DL < 23 Or SF_DL > 30  is E_NOT_OK */
            retVal = E_NOT_OK;
        }
    }
    else if( CANTP_LEN_CANFDDLC24 == rxDlcLen )
    {
        /* 19 <= SF_DL <= 22 is E_OK */
        if( ((CANTP_LEN_CANFDDLC20 - CANTP_INIT_ONE) > rxDataLen) || ((CANTP_LEN_CANFDDLC24 - CANTP_INIT_TWO) < rxDataLen) )
        {
            /* SF_DL < 19 Or SF_DL > 22  is E_NOT_OK */
            retVal = E_NOT_OK;
        }
    }
    else if( CANTP_LEN_CANFDDLC20 == rxDlcLen )
    {
        /* 15 <= SF_DL <= 18 is E_OK*/
        if( ((CANTP_LEN_CANFDDLC16 - CANTP_INIT_ONE) > rxDataLen) || ((CANTP_LEN_CANFDDLC20 - CANTP_INIT_TWO) < rxDataLen) )
        {
            /* SF_DL < 15 Or SF_DL > 18  is E_NOT_OK */
            retVal = E_NOT_OK;
        }
    }
    else if( CANTP_LEN_CANFDDLC16 == rxDlcLen )
    {
        /* 11 <= SF_DL <= 14 is E_OK*/
        if( ((CANTP_LEN_CANFDDLC12 - CANTP_INIT_ONE) > rxDataLen) || ((CANTP_LEN_CANFDDLC16 - CANTP_INIT_TWO) < rxDataLen) )
        {
            /* SF_DL < 11 Or SF_DL > 14  is E_NOT_OK */
            retVal = E_NOT_OK;
        }
    }
    else if( CANTP_LEN_CANFDDLC12 == rxDlcLen )
    {
        /* 8 <= SF_DL <= 10 is E_OK*/
        if( ((CANTP_LEN_CANFDDLC8) > rxDataLen) || ((CANTP_LEN_CANFDDLC12 - CANTP_INIT_TWO) < rxDataLen) )
        {
            /* SF_DL < 8 Or SF_DL > 10  is E_NOT_OK */
            retVal = E_NOT_OK;
        }
    }

#if( (CANTP_GENERAL_VERSION == CANTP_ISO15765_2_2011) || (CANTP_GENERAL_VERSION == CANTP_ISO15765_2_2016) )
    else if( (CANTP_ON == CanTpRxPaddingActivation) && (CANTP_INIT_ONE < rxDlcLen) )
    {
        /* SF_DL == Can_DLC - 1 is E_OK*/
        if( rxDataLen > ( rxDlcLen - CANTP_INIT_ONE ) )
        {
            /* SF_DL > Can_DLC - 1 is E_NOT_OK*/
            retVal = E_NOT_OK;
        }
    }
#endif  /* (CANTP_GENERAL_VERSION == CANTP_ISO15765_2_2011) || (CANTP_GENERAL_VERSION == CANTP_ISO15765_2_2016) */

    else if(
#if( (CANTP_GENERAL_VERSION == CANTP_ISO15765_2_2011) || (CANTP_GENERAL_VERSION == CANTP_ISO15765_2_2016) )

        (CANTP_OFF == CanTpRxPaddingActivation) &&
#endif  /* (CANTP_GENERAL_VERSION == CANTP_ISO15765_2_2011) || (CANTP_GENERAL_VERSION == CANTP_ISO15765_2_2016) */
        (CANTP_INIT_TWO < rxDlcLen ))
    {
        /* SF_DL == Can_DLC - 1 is E_OK*/
        if( rxDataLen != ( rxDlcLen - CANTP_INIT_ONE ) )
        {
            /* SF_DL != Can_DLC - 1 is E_NOT_OK*/
            retVal = E_NOT_OK;
        }
    }
    else
    {
        retVal = E_NOT_OK;
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: CanTp_MemSet
*
* Explanation: To initial the data.
*
* param: destPtr: The destination of the data.
*        val: Data value.
*        cnt: The length of the data
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANTP_CODE) CanTp_MemSet
(
    P2VAR(void, AUTOMATIC, CANTP_APPL_DATA) destPtr,
    uint8 val,
    uint16 cnt
)
{
    /* Polyspace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanTp_UNMODIFIED_VAR_NOT_CONST" */
    uint8 *beginPtr = (uint8*)destPtr;  /* PRQA S 0316 */ /* NSCA_QAC_CanTp_Rule11.5 */
    uint16 dataIndex = CANTP_ZERO;

    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( (NULL_PTR != destPtr) && (CANTP_ZERO != cnt) ) /* Check the parameter. */
    {
        for( ; dataIndex != cnt; dataIndex++ ) /* Check the number of the cycle. */
        {
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.4 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule18.4" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanTp_IDP" */
            *(beginPtr + dataIndex) = val; /* Set data. */  /* PRQA S 0488 */ /* NSCA_QAC_CanTp_Rule18.4 */
        }
    }
}

/*
************************************************************************************************************************
* Function Name: CanTp_CanIfRxSFTesterOnline
*
* Explanation: TP handle 3E service.
*
* Param: chnId: Channel Id.
*        rxPduId: Current receiving pdu index.
*        rxSduPtr: PDU data information.
*
* Retval: breakFlag: TRUE: 3E 80 received.
*                    FALSE: 3E 80 is not received.
************************************************************************************************************************
*/
static FUNC(uint8, CANTP_CODE) CanTp_CanIfRxSFTesterOnline
(
    uint8 chnId,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
    PduIdType rxPduId,
    P2CONST(CanTpRxNSdu_st, AUTOMATIC, CANTP_APPL_DATA) rxSduPtr
)
{
    boolean breakFlag = FALSE;
    BufReq_ReturnType chkResult;
    PduLengthType bufferSizePtr;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
    PduInfoType info;

    /* When waiting for CF, the PDU data is 3E 80, new request is not supported.*/
    if( (CANTP_INIT_TWO == CanTp_CanRxBuffer[chnId][CANTP_ZERO]) &&
        (CANTP_SERVICEID_3E == CanTp_CanRxBuffer[chnId][CANTP_INIT_ONE]) &&
        (CANTP_SUBSERVICEID_80 == CanTp_CanRxBuffer[chnId][CANTP_INIT_TWO]) &&
        ((uint8)CANTP_FUNCTIONAL == rxSduPtr->CanTpRxTaType) )
    {
        info.SduDataPtr = &CanTp_CanRxBuffer[chnId][CANTP_INIT_ONE];
        info.SduLength = CANTP_BYTE_TWO;
        chkResult = PduR_CanTpStartOfReception(CanTpRxSdu[rxPduId].PduRRxPduId,
                                    (const PduInfoType*)&info, CANTP_BYTE_TWO, (PduLengthType*)&bufferSizePtr);  /* Notify upper layer. */

        if( BUFREQ_OK == chkResult )
        {
            /* Confirm upper layer. */
            (void)PduR_CanTpRxIndication(CanTpRxSdu[rxPduId].PduRRxPduId, E_OK);
        }

        breakFlag = TRUE;
    }

    return breakFlag;
}

/*
********************************************************************************
* Function Name: CanTp_CanIfRxIndication
*
* Explanation: TP receive function.
*
* param: PduIdType rxPduId: PDU Id.
*        PduInfoType pduInfoPtr: PDU data information.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANTP_CODE) CanTp_CanIfRxIndication
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
    PduIdType rxPduId,
    PduInfoType pduInfoPtr
)
{
    boolean breakFlag = FALSE;
    uint8 lastCf = CANTP_NO_LASTCF;
    uint8 chnId;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
    uint8 offSet = CANTP_ZERO;
    BufReq_ReturnType chkResult;
    uint8 retVal = E_OK;
    uint16 timer;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
    PduIdType txPduId;
    PduLengthType dataLen = CANTP_ZERO;
    PduLengthType bufferSizePtr;
    uint32 totalBlock = CANTP_ZERO;
    CanTpRxNSdu_st *rxSduPtr;
    CanTpRxNSdu_st *rxFuncSduPtr;
    CanTpTxNSdu_st *txFuncSduPtr;
    PduInfoType pdurInfo;

    rxSduPtr = &CanTpRxSdu[rxPduId];
    /* Get current channel index. */
    chnId = rxSduPtr->CanTpChnId;
    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_CanTp_OBAI" */
    txPduId = CanTp_TxState[chnId].txPduId;
    if( CANTP_TXSTATE_IDLE == CanTp_TxState[chnId].channelState )
    {
       txPduId = rxSduPtr->CanTpTxPduId;
    }

    if( (PduIdType)CANTP_TXSDU_NUM > txPduId )
    {
        /* Check the type of the message. */
        switch( CanTp_CanRxBuffer[chnId][CANTP_ZERO] & CANTP_FRAME_HMASK )
        {
            /* Received FirstFrame. */
            case CANTP_FF:
                /* Only support physical addressing. */
                if( (uint8)CANTP_PHYSICAL != rxSduPtr->CanTpRxTaType )
                {
                    break;
                }

                /* When TP send data, new request is not supported. */
                if( CanTp_TxState[chnId].channelState != CANTP_TXSTATE_IDLE )
                {
                    break;
                }

                CanTp_RxState[chnId].rxPduId = rxPduId;  /* Set the PDU id. */

                /* To check the TP state is not idle. */
                if( CanTp_RxState[chnId].channelState != CANTP_RXSTATE_IDLE )
                {
                    /* Set TP state is idle. */
                    CanTp_RxState[chnId].channelState = CANTP_RXSTATE_IDLE;
                    /* Initial the data of the timer. */
                    CanTp_RxState[chnId].timer = CANTP_ZERO;
                    /* Release the resource of the TP. */
                    (void)PduR_CanTpRxIndication(CanTpRxSdu[rxPduId].PduRRxPduId, E_NOT_OK);
                }

                /* The data received is CANFD message. */
                if( CANTP_LEN_CANFDDLC64 == rxSduPtr->CanTpRxDataLen )
                {
                    /* DLC must be 8,16,20,24,32,48 or 64. */
                    if( (CANTP_LEN_CANFDDLC8 != pduInfoPtr.SduLength)
                     && (CANTP_LEN_CANFDDLC12 != pduInfoPtr.SduLength)
                     && (CANTP_LEN_CANFDDLC16 != pduInfoPtr.SduLength)
                     && (CANTP_LEN_CANFDDLC20 != pduInfoPtr.SduLength)
                     && (CANTP_LEN_CANFDDLC24 != pduInfoPtr.SduLength)
                     && (CANTP_LEN_CANFDDLC32 != pduInfoPtr.SduLength)
                     && (CANTP_LEN_CANFDDLC48 != pduInfoPtr.SduLength)
                     && (CANTP_LEN_CANFDDLC64 != pduInfoPtr.SduLength) )
                    {
                        break;
                    }
                } /* The data received is CAN2.0 message. */
                else if( CANTP_STANDARD_FRAME_LENGTH == rxSduPtr->CanTpRxDataLen )
                {
                    /* The DLC of FF for CAN2.0 != 8 is invalid. */
                    if( CANTP_STANDARD_FRAME_LENGTH != pduInfoPtr.SduLength )
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
                /* Get the dataLen and the offset of the first frame by the data length. */
                retVal = CanTp_GetFFPCIInfo(rxSduPtr->CanTpRxDataLen, (uint8)pduInfoPtr.SduLength, CanTp_CanRxBuffer[chnId], &offSet, &dataLen);
                /* To judge the valid of the length. */
                if( retVal != E_OK )
                {
                    break;
                }

                CanTp_RxState[chnId].dataLen = dataLen;
                CanTp_TxState[chnId].rxPduId = rxPduId;
                CanTp_TxState[chnId].txPduId = txPduId;
                /* To notify Dcm, the reception data. */
                chkResult = PduR_CanTpStartOfReception(CanTpRxSdu[rxPduId].PduRRxPduId,
                                    NULL_PTR, dataLen, (PduLengthType*)&bufferSizePtr);
                if( BUFREQ_E_NOT_OK == chkResult )
                {
                    /* Release the resource of the TP. */
                    CanTp_RxInit(chnId, (uint8)chkResult);
                    break;
                }
                /* To response the overflow of the buffer. */
                else if( BUFREQ_E_OVFL == chkResult )
                {
                    /* To set the queue message. */
                    CanTp_RxState[chnId].queued++;
                    /* To response the overflow of the buffer. */
                    CanTp_RxState[chnId].channelState = CANTP_RXSTATE_WAITFORFCOVERCONFISR;
                    timer = (uint16)(rxSduPtr->CanTpNar / (uint16)CANTP_MAIN_PERIOD);
                    if( CANTP_ZERO == timer )
                    {
                        timer = CANTP_INIT_ONE;
                    }

                    /* To set the timer. */
                    CanTp_RxState[chnId].timer = timer;
                    break;
                }
                else
                {
                    /* Do nothing. */
                }
                /* To set the type of the frame. */
                CanTp_RxState[chnId].frameType = CANTP_CANRX_FF;
                CanTp_RxState[chnId].canRxffDlc = pduInfoPtr.SduLength;
                /* To set STmin. */
                CanTp_RxState[chnId].stmin = (uint8)(rxSduPtr->CanTpSTmin);

                /* To calculate the BS for data length is longer than 8(except 8). */
                /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                if( CANTP_INIT_ONE < pduInfoPtr.SduLength )
                {
                    if( CANTP_ZERO != ((dataLen - (pduInfoPtr.SduLength - offSet)) % (pduInfoPtr.SduLength - CANTP_INIT_ONE)))
                    {
                        totalBlock += (uint32)CANTP_INIT_ONE;
                    }
                    totalBlock += (uint32)((dataLen - (pduInfoPtr.SduLength - offSet)) / (pduInfoPtr.SduLength - CANTP_INIT_ONE));
                }
                CanTp_RxState[chnId].bsCounter
                    = (totalBlock > rxSduPtr->CanTpBs) ? rxSduPtr->CanTpBs : totalBlock;
                timer =(uint16)(rxSduPtr->CanTpNbr / (uint16)CANTP_MAIN_PERIOD);

                if( CANTP_ZERO == timer )
                {
                    timer = CANTP_INIT_ONE;
                }

                /* To set the timer. */
                CanTp_RxState[chnId].timer = timer;
                /* To set the WFT counter. */
                CanTp_RxState[chnId].wftCounter = rxSduPtr->CanTpRxWftMax;
                /* To set the WFT current counter. */
                CanTp_RxState[chnId].wftCurCounter = CANTP_ZERO;
                /* To set the queue message. */
                CanTp_RxState[chnId].queued++;
                /* To set the state of the channel. */
                CanTp_RxState[chnId].channelState = CANTP_RXSTATE_WAITFORFCCONFISR;
                /* Wait for a CF with first SN. */
                CanTp_RxState[chnId].expectedSN = CANTP_SNFIRSTCF;
                /* Set the PDU data. */
                pdurInfo.SduDataPtr = &CanTp_CanRxBuffer[chnId][offSet];
                /* Set the length of the PDU data according to the current pdulength. */
                pdurInfo.SduLength = pduInfoPtr.SduLength - offSet;
                /* Copy data to Dcm buffer. */
                chkResult = PduR_CanTpCopyRxData(CanTpRxSdu[rxPduId].PduRRxPduId, &pdurInfo, (PduLengthType*)&bufferSizePtr);

                if( BUFREQ_OK != chkResult )  /* Fail of the operation. */
                {
                    /* Release the resource of the TP. */
                    CanTp_RxInit(chnId, (uint8)chkResult);
                    break;
                }
                CanTp_RxState[chnId].dataLen -= pdurInfo.SduLength;
                break;

            /* Received SingleFrame */
            case CANTP_SF:
                /* When the PDU data is handled, new request is not supported.*/
                if( CanTp_TxState[chnId].channelState != CANTP_TXSTATE_IDLE )
                {
                    break;
                }

                /* When waiting for CF, the PDU data is 3E 80, new request is not supported.*/
                breakFlag = CanTp_CanIfRxSFTesterOnline(chnId, rxPduId, rxSduPtr);
                if( FALSE == breakFlag )
                {
                    CanTp_RxState[chnId].rxPduId = rxPduId;  /* Set the PDU id. */

                    /* To check the TP state is not idle. */
                    if( CanTp_RxState[chnId].channelState != CANTP_RXSTATE_IDLE )
                    {
                        CanTp_RxState[chnId].channelState = CANTP_RXSTATE_IDLE;  /* Set TP state is idle. */
                        CanTp_RxState[chnId].timer = CANTP_ZERO;  /* Initial the data of the timer. */
                        (void)PduR_CanTpRxIndication(CanTpRxSdu[rxPduId].PduRRxPduId, E_NOT_OK);  /* Release the resource of the TP. */
                    }
                    /* The length of the message. */
                    dataLen = (uint32)((uint32)CanTp_CanRxBuffer[chnId][CANTP_ZERO] & (uint32)CANTP_FRAME_LMASK);

                    /* The CAN_DLC of SF > 8. */
                    if( CANTP_STANDARD_FRAME_LENGTH < pduInfoPtr.SduLength )
                    {
                        /* Bits3-0 of the byte0 must be 0 for the SF. */
                        if( CANTP_ZERO == dataLen )
                        {
                            /* Get the data length of the SF(lowByte of the Byte0 + Byte1). */
                            dataLen = CanTp_CanRxBuffer[chnId][CANTP_INIT_ONE];
                            /* Check the valid of the length. */
                            if( E_NOT_OK == CanTp_RxSFDLCCheck(rxSduPtr->CanTpRxPaddingActivation, (uint8)dataLen, (uint8)pduInfoPtr.SduLength) )
                            {
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    else/* The CAN_DLC of SF <= 8. */
                    {
                        if( E_NOT_OK == CanTp_RxSFDLCCheck(rxSduPtr->CanTpRxPaddingActivation, (uint8)dataLen, (uint8)pduInfoPtr.SduLength) )
                        {
                            break;
                        }
                    }

                    CanTp_TxState[chnId].rxPduId = rxPduId;
                    CanTp_TxState[chnId].txPduId = txPduId;
                    chkResult = PduR_CanTpStartOfReception(CanTpRxSdu[rxPduId].PduRRxPduId,
                        NULL_PTR, dataLen, (PduLengthType*)&bufferSizePtr);  /* To notify Dcm, the reception data. */
                    if( BUFREQ_OK != chkResult )
                    {
                        CanTp_RxInit(chnId, (uint8)chkResult);  /* Release the resource of the TP. */
                        break;
                    }

                    CanTp_RxState[chnId].frameType = CANTP_CANRX_SF;  /* To set the type of the frame. */
                    CanTp_RxState[chnId].canRxffDlc = CANTP_ZERO;
                    /* To set the state of the channel. */
                    CanTp_RxState[chnId].channelState = CANTP_RXSTATE_USEDFORAPPL;
                    timer = (uint16)rxSduPtr->CanTpNcr / (uint16)CANTP_MAIN_PERIOD;
                    if( CANTP_ZERO == timer )
                    {
                        timer = CANTP_INIT_ONE;
                    }

                    CanTp_RxState[chnId].timer = timer;  /* To set the timer. */
                    CanTp_RxState[chnId].queued = CANTP_ZERO;  /* To set the queue message. */

                    /* CAN_DLC > 8. */
                    if( CANTP_STANDARD_FRAME_LENGTH < pduInfoPtr.SduLength )
                    {
                        pdurInfo.SduDataPtr = &CanTp_CanRxBuffer[chnId][CANTP_SF_OFFSET_CANFD];  /* Set the PDU data for CANFD message. */
                    }
                    else /* CAN_DLC <= 8. */
                    {
                        pdurInfo.SduDataPtr = &CanTp_CanRxBuffer[chnId][CANTP_SF_OFFSET];  /* Set the PDU data for can2.0 standard message. */
                    }

                    pdurInfo.SduLength = dataLen;  /* Set the length of the PDU data. */

                    /* Copy data to Dcm buffer. */
                    chkResult = PduR_CanTpCopyRxData(CanTpRxSdu[rxPduId].PduRRxPduId, &pdurInfo, (PduLengthType*)&bufferSizePtr);
                    if( BUFREQ_OK != chkResult )  /* Fail of the operation. */
                    {
                        CanTp_RxInit(chnId, (uint8)chkResult);  /* Release the resource of the TP. */
                        break;
                    }


                    CanTp_RxInit(chnId, (uint8)NTFRSLT_OK);  /* To notify the done of the receive data to Dcm. */

                }

                break;

            /* Received consecutive frame */
            case CANTP_CF:
                /* CF received before Tx confirmation of FC; treat FC as confirmed and release semaphore. */
                if( (CANTP_RXSTATE_WAITFORFCCONFISR == CanTp_RxState[chnId].channelState)
                    && (CANTP_ZERO == CanTp_RxState[chnId].queued) )
                {
                    CanTp_TxSemaphore[chnId] = (uint8)CANTP_RX;
                    CanTp_TxConfirmation(CanTp_TxState[chnId].txPduId);  /* mark FC as confirmed. */
                }

                /* To check the state is wait for CF. */
                if( CANTP_RXSTATE_WAITCF == CanTp_RxState[chnId].channelState )
                {
                    /* The addr type is consistent. */
                    if( CanTp_RxState[chnId].rxPduId != rxSduPtr->CanTpRxPduId )
                    {
                        break;
                    }

                    CanTp_RxState[chnId].frameType = CANTP_CANRX_CF;  /* Set the frame type. */

                    if( (CanTp_CanRxBuffer[chnId][CANTP_ZERO] & CANTP_FRAME_LMASK)
                        != CanTp_RxState[chnId].expectedSN )  /* Wrong SN. */
                    {
                        CanTp_RxInit(chnId, (uint8)NTFRSLT_E_NOT_OK);
                        break;
                    }

                    /* To obtain the actual length of the PDU data. */
                    dataLen = pduInfoPtr.SduLength - CANTP_INIT_ONE;

                    if( CanTp_RxState[chnId].dataLen > dataLen )
                    {
                        CanTp_RxState[chnId].dataLen -= dataLen;
                    }
                    else
                    {
                        dataLen = CanTp_RxState[chnId].dataLen;
                        CanTp_RxState[chnId].dataLen = CANTP_ZERO;
                    }
                    /* To obtain the data of the PDU. */
                    pdurInfo.SduDataPtr = &CanTp_CanRxBuffer[chnId][CANTP_CF_OFFSET];
                    pdurInfo.SduLength = dataLen;  /* To obtain the length of the PDU. */
                    /* Copy data to Dcm buffer. */
                    chkResult = PduR_CanTpCopyRxData(CanTpRxSdu[rxPduId].PduRRxPduId, &pdurInfo, (PduLengthType*)&bufferSizePtr);
                    if( BUFREQ_OK != chkResult )
                    {
                        CanTp_RxInit(chnId, (uint8)chkResult);
                        break;
                    }

                    if( (CANTP_MF_MIN_LEN >= (pdurInfo.SduLength + CanTp_RxState[chnId].dataLen)) && (CANTP_ZERO != CanTp_RxState[chnId].dataLen) )
                    {
                        CanTp_RxInit(chnId, (uint8)NTFRSLT_E_NOT_OK); /* Release the resource of the TP. */
                        break;
                    }

                    if( CANTP_ZERO == CanTp_RxState[chnId].dataLen )  /* To check the completion of the data. */
                    {
                        lastCf = CANTP_LASTCF;
                    }

                    if( (uint8)CANTP_LASTCF == lastCf )  /* The completion of the receiving data. */
                    {
                        /* Set the type of the channel. */
                        if( pduInfoPtr.SduLength > CanTp_RxState[chnId].canRxffDlc )
                        {
                            /* Do nothing. */
                        }
                        else
                        {
                            CanTp_RxState[chnId].channelState = CANTP_RXSTATE_USEDFORAPPL;
                            CanTp_RxInit(chnId, (uint8)NTFRSLT_OK);  /* To notify Dcm. */
                        }
                        CanTp_RxState[chnId].canRxffDlc = CANTP_ZERO;
                        break;
                    }
                    else
                    {
                        if( pduInfoPtr.SduLength != CanTp_RxState[chnId].canRxffDlc )
                        {
                            break;
                        }
                        /* Reception incomplete, calculate next expected SN. */
                        CanTp_RxState[chnId].expectedSN
                          = (uint8)((CanTp_RxState[chnId].expectedSN + CANTP_INIT_ONE) & CANTP_LOW_OFFSET);

                        if( CANTP_ZERO < CanTp_RxState[chnId].bsCounter )  /* The BS in not equal to zero. */
                        {
                            CanTp_RxState[chnId].bsCounter--;   /*Decrease. */
                            /* When the BS equals to zero. */
                            if( CANTP_ZERO == CanTp_RxState[chnId].bsCounter )
                            {
                                totalBlock = CANTP_ZERO;

                                /* To calculate the BS. */
                                if( CANTP_INIT_ONE < pduInfoPtr.SduLength )
                                {
                                    if( CANTP_ZERO != (CanTp_RxState[chnId].dataLen % (pduInfoPtr.SduLength - CANTP_INIT_ONE) ))
                                    {
                                        totalBlock = CANTP_INIT_ONE;
                                    }
                                    totalBlock += (uint32)(CanTp_RxState[chnId].dataLen / (pduInfoPtr.SduLength - CANTP_INIT_ONE));  /* To calculate the BS. */
                                }
                                /* To calculate the BS. */
                                CanTp_RxState[chnId].bsCounter
                                  = (totalBlock > rxSduPtr->CanTpBs) ? rxSduPtr->CanTpBs : totalBlock;
                                timer = (uint16)(rxSduPtr->CanTpNbr / (uint16)CANTP_MAIN_PERIOD);

                                if( CANTP_ZERO == timer )
                                {
                                    timer = CANTP_INIT_ONE;
                                }

                                /* To set the timer. */
                                CanTp_RxState[chnId].timer = timer;
                                /* To set the WFT counter. */
                                CanTp_RxState[chnId].wftCounter = rxSduPtr->CanTpRxWftMax;
                                /* To set the WFT current counter. */
                                CanTp_RxState[chnId].wftCurCounter = CANTP_ZERO;
                                CanTp_RxState[chnId].queued++; /* To set the queue message. */
                                /* To set the state of the channel. */
                                CanTp_RxState[chnId].channelState = CANTP_RXSTATE_WAITFORFCCONFISR;
                            }
                        }

                        /* Reload timeout if only waiting for next CF (enough buffer, no FC necessary). */
                        if( CANTP_RXSTATE_WAITCF == CanTp_RxState[chnId].channelState )
                        {
                            timer = (uint16)rxSduPtr->CanTpNcr / (uint16)CANTP_MAIN_PERIOD;
                            if( CANTP_ZERO == timer )
                            {
                                timer = CANTP_INIT_ONE;
                            }

                            CanTp_RxState[chnId].timer = timer;
                        }
                    }
                }
                break;

            /* Received flow control frame */
            case CANTP_FC:
                if( CANTP_ZERO != CanTp_TxState[chnId].queued )  /* Unexpected FC: Ignore. */
                {
                    break;
                }

                /* Only support the phy addr. */
                if( (uint8)CANTP_PHYSICAL != rxSduPtr->CanTpRxTaType )
                {
                    break;
                }

                /* Initial the value of the PDU id. */
                if( rxSduPtr->CanTpRxPduId != CanTp_TxState[chnId].rxPduId )
                {
                    CanTp_TxState[chnId].rxPduId = rxSduPtr->CanTpRxPduId;
                    CanTp_TxState[chnId].txPduId = txPduId;
                }
                 /* Get rx sdu data. */
                rxFuncSduPtr = &CanTpRxSdu[CanTp_TxState[chnId].rxPduId];
                /* Polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule14.3" Polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
                if( NULL_PTR == rxFuncSduPtr )
                /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    break;
                }

                /* If the requestion is func addr,but the type of FC is phy addr,then ignore the message. */
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanTp_IDP" */
                if( ((uint8)CANTP_FUNCTIONAL == rxFuncSduPtr->CanTpRxTaType )
                    && (rxSduPtr->CanTpRxPduId == rxPduId))
                {
                    break;
                }

                txFuncSduPtr = &CanTpTxSdu[CanTp_TxState[chnId].txPduId];  /* Get tx sdu data. */
                /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule14.3" Polyspace +1 DEFECT:USELESS_IF [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
                if( NULL_PTR != txFuncSduPtr )
                {
                    /* If the length of the PDU data less then TP_FC_MIN_DATA_LEN, then ignore the message. */
                    if( CANTP_FC_MIN_DATA_LEN > pduInfoPtr.SduLength )
                    {
                        break;
                    }

                    /* FC received before Tx confirmation of FF; treat FF as confirmed and release semaphore. */
                    if( (CanTp_TxState[chnId].channelState == CANTP_TXSTATE_WAITFORSFORFFCONFISR)
                        && (CanTp_TxState[chnId].frameType == CANTP_CANRX_FF) )
                    {
                        CanTp_TxSemaphore[chnId] = (uint8)CANTP_TX;
                        CanTp_TxConfirmation(CanTp_TxState[chnId].txPduId);  /* mark FF as Tx-confirmed. */
                    }
                    /* FC received before Tx confirmation of last CF in block; treat CF as confirmed and release semaphore. */
                    else if( (CanTp_TxState[chnId].channelState == CANTP_TXSTATE_WAITFORCFCONFISR)
                        && (CANTP_INIT_ONE == CanTp_TxState[chnId].bsCounter) )
                    {
                        CanTp_TxCFTxConfirmation(CanTp_TxState[chnId].txPduId); /* Mark CF as Tx-Confirmed. */
                    }
                    else
                    {
                        /* Do nothing. */
                    }

                    /* If the type of the channel equals to waitFC. */
                    if( CANTP_TXSTATE_WAITFC == CanTp_TxState[chnId].channelState )
                    {
                        switch(CanTp_CanRxBuffer[chnId][CANTP_ZERO] & CANTP_FRAME_LMASK)  /* Swith state. */
                        {
                            case CANTP_FS_CTS:   /* CTS */
                                /* To obtain BS. */
                                CanTp_TxState[chnId].bsCounter = CanTp_CanRxBuffer[chnId][CANTP_INIT_ONE];
                                /* To obtain STMIN. */
                                CanTp_TxState[chnId].stmin = CanTp_CanRxBuffer[chnId][CANTP_INIT_TWO];
                                /* Prepare sending of next CF. */
                                CanTp_TxState[chnId].frameType  = CANTP_CANRX_CF;
                                /* To calculate the STMin. */
                                CanTp_TxState[chnId].timerStmin
                                    = CanTp_GetTxStminFromStminValue(CanTp_TxState[chnId].stmin);

                                /* If the STMin equals to zero. */
#if ( CANTP_STMIN_ZERO_CF_IN_TXCONFIRM == STD_ON )
                                if( (uint8)CANTP_ZERO == CanTp_TxState[chnId].stmin )
#else
                                if( (uint8)CANTP_ZERO == CanTp_TxState[chnId].timerStmin )
#endif  /* CANTP_STMIN_ZERO_CF_IN_TXCONFIRM == STD_ON */
                                /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                                {
                                    if( FALSE == CanTp_TxState[chnId].copyType )
                                    {
                                        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanTp_IDP" */
                                        timer = (uint16)txFuncSduPtr->CanTpNas / (uint16)CANTP_MAIN_PERIOD;
                                        if( (uint16)CANTP_ZERO == timer )
                                        {
                                            timer = CANTP_INIT_ONE;
                                        }

                                        CanTp_TxState[chnId].timer = timer;  /* Set the timer. */
                                        /* Set the type of the channel. */
                                        CanTp_TxState[chnId].channelState = CANTP_TXSTATE_WAITFORCFCONFISR;
                                        CanTp_TxState[chnId].queued++;  /* Set FC transmission request. */
                                        CanTp_TxStateTask(CanTp_TxState[chnId].txPduId, TRUE);  /* Send the data. */
                                    }
                                    else
                                    {
                                        CanTp_CopyCFTxData(chnId);
                                    }
                                }
                                else
                                {
                                    CanTp_TxState[chnId].timer = CANTP_INIT_ONE;  /* Set the timer. */
                                    /* Set the STMin. */
                                    CanTp_TxState[chnId].timerStmin = CANTP_INIT_ONE;
                                    /* Set the type of the channel. */
                                    CanTp_TxState[chnId].channelState = CANTP_TXSTATE_WAITFORTPTXCF;
                                }
                                break;

                            case CANTP_FS_WAIT:
                                if( CanTp_RxState[chnId].wftCurCounter >= CanTp_RxState[chnId].wftCounter )
                                {
                                    CanTp_TxInit(CanTp_TxState[chnId].txPduId, CANTP_NOTIFY_NOT_OK);
                                }
                                else
                                {
                                    CanTp_RxState[chnId].wftCurCounter++;
                                    /* WaitFrame received, restart timer. */
                                    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanTp_IDP" */
                                    timer = (uint16)txFuncSduPtr->CanTpNbs / (uint16)CANTP_MAIN_PERIOD;
                                    if( CANTP_ZERO == timer )
                                    {
                                        timer = CANTP_INIT_ONE;
                                    }
                                    CanTp_TxState[chnId].timer = timer;
                                }
                                break;

                            case CANTP_FS_OVFLW:
                                /* Buffer overflow. */
                                CanTp_TxInit(CanTp_TxState[chnId].txPduId, CANTP_NOTIFY_NOT_OK);
                                break;

                            default:
                                /* Default */
                                CanTp_TxInit(CanTp_TxState[chnId].txPduId, CANTP_NOTIFY_NOT_OK);
                                break;
                        }
                    }
                }
                break;

            default:
                /* Do Nothing. */
                break;
        }
    }

    return;
}

/*
********************************************************************************
* Function Name: CanTp_MainFunctionRx
*
* Explanation: TP RX Main Function,which handles the reveived data.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANTP_CODE) CanTp_MainFunctionRx(void)
{
    uint8 chnId;
    CanTp_RxStateType_st *tpRxState;

    for( chnId = CANTP_ZERO; chnId < (uint8)CANTP_CHANNEL_NUM; chnId++ )
    {
        if( CANTP_ZERO != CanTp_RxState[chnId].timer )  /* If the timer equals to zero. */
        {
            tpRxState = &CanTp_RxState[chnId];  /* Get rx data. */
            if( CANTP_ZERO != tpRxState->queued )
            {
                CanTp_RxStateTask();
            }
            else
            {
                tpRxState->timer--;
                if( CANTP_ZERO == tpRxState->timer )  /* Timer is zero. */
                {
                    switch( tpRxState->channelState )
                    {
                        case CANTP_RXSTATE_WAITCF:  /* CF timeout. */
                        {
                            CanTp_RxInit(chnId, NTFRSLT_E_NOT_OK);
                            break;
                        }

                        case CANTP_RXSTATE_WAITFORFCCONFISR:  /* FC confirmation timeout. */
                        {
                            CanTp_RxInit(chnId, NTFRSLT_E_NOT_OK);
                            break;
                        }

                        case CANTP_RXSTATE_WAITFORFCOVERCONFISR:
                        {
                            CanTp_RxInit(chnId, NTFRSLT_E_NOT_OK);
                            break;
                        }

                        default:
                            /* Do Nothing. */
                            break;
                    }
                }
            }
        }
    }
    return;
}

/*
********************************************************************************
* Function Name: CanTp_MainFunctionTx
*
* Explanation: TP TX Main Function,which handles the send data.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANTP_CODE) CanTp_MainFunctionTx(void)
{
    uint8 chnId;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
    uint8 errorId = CANTP_E_NO_ERROR;
    uint16 timer;
    CanTp_TxStateType_st *tpTxStatePtr;
    CanTpTxNSdu_st *txFuncSduPtr;
    PduInfoType canTpTxInfo;

    for( chnId = CANTP_ZERO; chnId < (uint8)CANTP_CHANNEL_NUM; chnId++ )
    {
        if( CANTP_ZERO != CanTp_TxState[chnId].timer )  /* Timer is zero. */
        {
            tpTxStatePtr = &CanTp_TxState[chnId];
            txFuncSduPtr = &CanTpTxSdu[tpTxStatePtr->txPduId];  /* Get tx sdu data. */
            /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule14.3" Polyspace +1 DEFECT:USELESS_IF [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
            if( NULL_PTR != txFuncSduPtr )
            {
                tpTxStatePtr->timer--;  /* Decrease. */
                if( CANTP_ZERO < tpTxStatePtr->timerStmin )
                {
                    (tpTxStatePtr->timerStmin)--;
                }

                if( CANTP_ZERO == tpTxStatePtr->timer )  /* Timeout. */
                {
                    switch( tpTxStatePtr->channelState )
                    {
                        case CANTP_TXSTATE_WAITFC:  /* Wait FC. */
                            CanTp_TxInit(tpTxStatePtr->txPduId, CANTP_NOTIFY_NOT_OK);
                            break;

                        case CANTP_TXSTATE_WAITFORTPTXCF:   /* Wait tx confirmation. */
#if ( CANTP_STMIN_ZERO_CF_IN_TXCONFIRM == STD_ON )
                            if( CANTP_ZERO != tpTxStatePtr->stmin )
#endif  /* CANTP_STMIN_ZERO_CF_IN_TXCONFIRM == STD_ON */
                            {
                                if( FALSE == CanTp_TxState[chnId].copyType )
                                {
                                    /* Set N_As timeout. */
                                    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanTp_IDP" */
                                    timer = (uint16)txFuncSduPtr->CanTpNas / (uint16)CANTP_MAIN_PERIOD;
                                    if( CANTP_ZERO == timer )
                                    {
                                        timer = CANTP_INIT_ONE;
                                    }
                                    tpTxStatePtr->timer = timer;
                                    /* Set the status to CANTP_TXSTATE_WAITFORCFCONFISR. */
                                    tpTxStatePtr->channelState = CANTP_TXSTATE_WAITFORCFCONFISR;
                                    tpTxStatePtr->queued++;
                                    /* Try first transmission right now. */
                                    CanTp_TxStateTask(tpTxStatePtr->txPduId, TRUE);
                                }
                                else
                                {
                                    CanTp_CopyCFTxData(chnId);
                                }
                            }
                            break;

                        /* Timeout of the TxConfirmation of a SF, FF or CF. */
                        case CANTP_TXSTATE_WAITFORSFORFFCONFISR:
                        case CANTP_TXSTATE_WAITFORCFCONFISR:
                            CanTp_TxInit(tpTxStatePtr->txPduId, CANTP_NOTIFY_NOT_OK);
                            break;

                        default:
                            if( TRUE == CanTp_TxState[chnId].copyType )
                            {
                                canTpTxInfo.SduLength = tpTxStatePtr->dataLength;
                                canTpTxInfo.SduDataPtr = NULL_PTR;
                                (void)CanTp_Transmit_WithOutData(tpTxStatePtr->txPduId, &canTpTxInfo, &errorId);
                            }
                            break;
                    }
                }
                else
                {
                    CanTp_TxStateTask(tpTxStatePtr->txPduId, TRUE);  /* No timeout. */
                }
            }
        }
    }
    return;
}

/*
********************************************************************************
* Function Name: CanTp_RxStateTask
*
* Explanation: TP RX Function,which handles the received data.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANTP_CODE) CanTp_RxStateTask(void)
{
    boolean transmitFC = TRUE;
    uint8 bufferIndex;
    uint8 chnId;
    CanTpTxNSdu_st *txFuncSduPtr;
    CanTp_RxStateType_st *tpRxState;
    PduInfoType pdurInfo;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
    PduIdType txPduId;

    for( chnId = CANTP_ZERO; chnId < (uint8)CANTP_CHANNEL_NUM; chnId++ )
    {
        if( CANTP_ZERO != CanTp_RxState[chnId].queued )  /* Check queued task. */
        {
            tpRxState = &CanTp_RxState[chnId];
            /* Get tx pdu id by the rx pdu. */
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_CanTp_OBAI" */
            txPduId = CanTpRxSdu[tpRxState->rxPduId].CanTpTxPduId;

            txFuncSduPtr = &CanTpTxSdu[txPduId];  /* Get tx sdu data. */
            /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule14.3" Polyspace +1 DEFECT:USELESS_IF [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
            if( NULL_PTR != txFuncSduPtr )
            {
                /* Set pattern value. */
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanTp_IDP" */
                for( bufferIndex = CANTP_ZERO; bufferIndex < txFuncSduPtr->CanTpTxDataLen; bufferIndex++ )
                {
                    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_CanTp_OBAI" */
                    CanTp_CanTxBuffer[chnId][bufferIndex] = CANTP_PADDING_PATTERN;
                }

                switch( tpRxState->channelState )
                {
                    case CANTP_RXSTATE_WAITFORFCCONFISR:  /* Send normal FC. */
                        CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE] = CANTP_FC;
                        CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_BS] = CanTpRxSdu[tpRxState->rxPduId].CanTpBs;
                        break;
                    case CANTP_RXSTATE_WAITFORFCOVERCONFISR:  /* Send overflow FC. */
                        CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE] = CANTP_FC | CANTP_FS_OVFLW;
                        CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_BS] = CanTpRxSdu[tpRxState->rxPduId].CanTpBs;
                        break;
                    default:
                        transmitFC = FALSE;
                        break;
                }

                if( (boolean)TRUE == transmitFC )    /* Send FC. */
                {
                    CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_STMIN] = tpRxState->stmin;
                    pdurInfo.SduDataPtr = CanTp_CanTxBuffer[chnId];

                    if( (uint8)CANTP_ON == txFuncSduPtr->CanTpTxPaddingActivation )
                    {
                        pdurInfo.SduLength = CANTP_LEN_CANFDDLC8;
                    }
                    else
                    {
                        pdurInfo.SduLength = CANTP_LEN_FC;
                    }

                    CanTp_TxSemaphore[chnId] = (uint8)CANTP_RX;
                    tpRxState->queued  = CANTP_ZERO;
                    (void)CanTpTxSdu[txPduId].CanTp_TransmitToCanIf_p(txFuncSduPtr->CanIfTxPduId, &pdurInfo);
                }

            }
        }
    }
    return;
}

/*
********************************************************************************
* Function Name: CanTp_RxInit
*
* Explanation: TP confirm Dcm and release rx resource.
*
* param: chnId: Channel id.
*        notifyCode: 0: silent;1: confirm Dcm.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANTP_CODE) CanTp_RxInit(uint8 chnId, uint8 notifyCode)
{
    PduIdType rxSduId;

    /* Check channel state and notification. */
    if( CanTp_RxState[chnId].channelState != CANTP_RXSTATE_IDLE )
    {
        /* Get rx sdu id. */
        if( (PduIdType)CANTP_RXSDU_NUM > CanTp_RxState[chnId].rxPduId )
        {
            rxSduId = CanTpRxSdu[CanTp_RxState[chnId].rxPduId].PduRRxPduId;
            /* Confirm DCM. */
            (void)PduR_CanTpRxIndication(rxSduId, notifyCode);
            CanTp_MemSet((&CanTp_CanRxBuffer[chnId]), CANTP_ZERO, sizeof(CanTp_CanRxBuffer[chnId]));
        }
    }

    CanTp_RxInitState(chnId);  /* Release resource. */

    return;
}

/*
********************************************************************************
* Function Name: CanTp_RxInitState
*
* Explanation: TP init data.
*
* param: chnId: Channel id.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANTP_CODE) CanTp_RxInitState(uint8 chnId)
{
    /* Release resource. */
    CanTp_MemSet(&CanTp_RxState[chnId], CANTP_ZERO, sizeof(CanTp_RxStateType_st));
    CanTp_RxState[chnId].frameType = CANTP_CANINVALIDFRAME;

}

/*
********************************************************************************
* Function Name: CanTp_TxConfirmation
*
* Explanation: TP tx confirmation callback.
*
* param: TxPduId: pdu id.
*
* retval: None
********************************************************************************
*/
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
FUNC(void, CANTP_CODE) CanTp_TxConfirmation(PduIdType TxPduId)
{
    uint8 lErrorId  = CANTP_E_NO_ERROR;
    uint8 chnId;
    uint16 timer;
    CanTpTxNSdu_st *txFuncSduPtr;
    CanTpTxNSdu_st *txSduPtr;
    CanTpRxNSdu_st *rxSduPtr;
    CanTp_RxStateType_st *tpRxState;

#if ( CANTP_STMIN_ZERO_CF_IN_TXCONFIRM == STD_ON )
    CanTp_TxStateType_st *tpTxStatePtr;
#endif  /* CANTP_STMIN_ZERO_CF_IN_TXCONFIRM == STD_ON */

    /* Check Tp initial state. */
    if( CanTp_InitState != (uint8)CANTP_STATUS_INITIALIZED )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        lErrorId = CANTP_E_UNINIT;
    }
    else if ( (PduIdType)CANTP_TXSDU_NUM <= TxPduId)
    {
        lErrorId = CANTP_E_INVALID_TX_ID;
    }
    else
    {
        txSduPtr = &CanTpTxSdu[TxPduId];
        chnId = txSduPtr->CanTpChnId;

        /* TX-channel */
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_CanTp_OBAI" */
        if( (uint8)CANTP_TX == CanTp_TxSemaphore[chnId] )
        {
            txFuncSduPtr = &CanTpTxSdu[TxPduId];  /* Get tx sdu data. */
            switch( CanTp_TxState[chnId].channelState )
            {
                case CANTP_TXSTATE_WAITFORSFORFFCONFISR:
                    if( CANTP_CANRX_SF == CanTp_TxState[chnId].frameType )  /* SF was TxConfirmed. */
                    {
                        CanTp_TxInit(TxPduId, CANTP_NOTIFY);
                    }
                    else
                    {
                        /* FF was TxConfirmed. */
                        timer = (uint16)txFuncSduPtr->CanTpNbs / (uint16)CANTP_MAIN_PERIOD;
                        if( CANTP_ZERO == timer )
                        {
                            timer = CANTP_INIT_ONE;
                        }
                        CanTp_TxState[chnId].timer = timer;
                        CanTp_TxState[chnId].channelState = CANTP_TXSTATE_WAITFC;
                    }
                    break;

                case CANTP_TXSTATE_WAITFORCFCONFISR:  /* CF was TxConfirmed. */
                    CanTp_TxCFTxConfirmation(TxPduId);
                    break;

                default:
                    lErrorId = CANTP_E_INVALID_TX_STATE;
                    break;
            }

            CanTp_TxSemaphore[chnId] = (uint8)CANTP_IDLE;  /* Initial default value. */

#if ( CANTP_STMIN_ZERO_CF_IN_TXCONFIRM == STD_ON )
            tpTxStatePtr = &CanTp_TxState[chnId];
            /* Determine the conditions for sending CF. */
            if( (CANTP_ZERO == tpTxStatePtr->stmin) &&
                (CANTP_TXSTATE_WAITFORTPTXCF == CanTp_TxState[chnId].channelState) )
            {
                if( FALSE == CanTp_TxState[chnId].copyType )
                {
                    /* Set N_As timeout. */
                    timer = (uint16)txFuncSduPtr->CanTpNas / (uint16)CANTP_MAIN_PERIOD;
                    if( CANTP_ZERO == timer )
                    {
                        timer = CANTP_INIT_ONE;
                    }
                    tpTxStatePtr->timer = timer;
                    /* Set the status to CANTP_TXSTATE_WAITFORCFCONFISR. */
                    tpTxStatePtr->channelState = CANTP_TXSTATE_WAITFORCFCONFISR;
                    tpTxStatePtr->queued++;
                    /* Try first transmission right now. */
                    CanTp_TxStateTask(tpTxStatePtr->txPduId, TRUE);
                }
                else
                {
                    CanTp_CopyCFTxData(chnId);
                }
            }
#endif  /* CANTP_STMIN_ZERO_CF_IN_TXCONFIRM == STD_ON */

        }
        /* RX-channel */
        else if( (uint8)CANTP_RX == CanTp_TxSemaphore[chnId] )
        {
            tpRxState = &CanTp_RxState[chnId];
            rxSduPtr = &CanTpRxSdu[tpRxState->rxPduId];  /* Get rx sdu data. */
            /* Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule14.3" Polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
            if( NULL_PTR != rxSduPtr )
            {
                switch( CanTp_RxState[chnId].channelState )
                {
                    case CANTP_RXSTATE_WAITFORFCCONFISR:  /* Wait for next CF, reset SN. */
                        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanTp_IDP" */
                        timer = (uint16)rxSduPtr->CanTpNcr / (uint16)CANTP_MAIN_PERIOD;
                        if( CANTP_ZERO == timer )
                        {
                            timer = CANTP_INIT_ONE;
                        }
                        CanTp_RxState[chnId].timer = timer;
                        CanTp_RxState[chnId].channelState = CANTP_RXSTATE_WAITCF;
                        break;

                    case CANTP_RXSTATE_WAITFORFCOVERCONFISR:  /* Stop receiving frames on this tpChannel. */
                        CanTp_RxInit(chnId, NTFRSLT_E_NOT_OK);
                        break;

                    default:
                        lErrorId = CANTP_E_INVALID_TX_STATE;
                        break;
                }
            /* Polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            }
            else
            /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                lErrorId = CANTP_E_INVALID_RX_ID;
            }

            CanTp_TxSemaphore[chnId] = (uint8)CANTP_IDLE;  /* Initial default value. */
        }
        else
        {
            /* Nothing to do */
        }
    }

    CanTp_Det_ErrorReport(CANTP_SID_TXCONFIRMATION, lErrorId);  /* Report det error */

    return;
}

/*
********************************************************************************
* Function Name: CanTp_TxInit
*
* Explanation: TP indicate confirmation to DCM and release sent resource.
*
* param: txPduId: pdu id.
*        notifyCode: 0: silent; 1: indicate tx ok; 2: indicate tx not_ok.
*
* retval: None
********************************************************************************
*/
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
static FUNC(void, CANTP_CODE) CanTp_TxInit(PduIdType txPduId, uint8 notifyCode)
{
    uint8 chnId;

    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_CanTp_OBAI" */
    chnId = CanTpTxSdu[txPduId].CanTpChnId;

    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_CanTp_OBAI" */
    if( (CanTp_TxState[chnId].channelState != CANTP_TXSTATE_IDLE) && (CANTP_NOTIFY == notifyCode) )
    {
        CanTp_TxInitState(chnId);  /* Release resource. */
        CanTp_TxApplTxConfirmation(txPduId, NTFRSLT_OK);
        CanTp_MemSet((&CanTp_CanTxBuffer[chnId]), CANTP_ZERO, sizeof(CanTp_CanTxBuffer[chnId]));
    }
    else if( (CanTp_TxState[chnId].channelState != CANTP_TXSTATE_IDLE) && (CANTP_NOTIFY_NOT_OK == notifyCode) )
    {
        CanTp_TxInitState(chnId);  /* Release resource. */
        CanTp_TxApplTxConfirmation(txPduId, NTFRSLT_E_NOT_OK);
        CanTp_MemSet((&CanTp_CanTxBuffer[chnId]), CANTP_ZERO, sizeof(CanTp_CanTxBuffer[chnId]));
    }
    else
    {
        CanTp_TxInitState(chnId);  /* Release resource. */
    }

    return;
}

/*
********************************************************************************
* Function Name: CanTp_TxInitState
*
* Explanation: TP release sent resource.
*
* param: None
*
* retval: None
********************************************************************************
*/
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule8.7" */
FUNC(void, CANTP_CODE) CanTp_TxInitState(uint8 chnId)  /* PRQA S 1505 */ /* NSCA_QAC_Common_Rule8.7 */
{
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
    PduIdType rxPduId;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
    PduIdType txPduId;

    /*Release resource*/
    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_CanTp_OBAI" */
    rxPduId = CanTp_TxState[chnId].rxPduId;
    txPduId = CanTp_TxState[chnId].txPduId;

    CanTp_MemSet(&CanTp_TxState[chnId], CANTP_ZERO, sizeof(CanTp_TxStateType_st));
    CanTp_TxState[chnId].frameType = CANTP_CANINVALIDFRAME;
    CanTp_TxState[chnId].rxPduId = rxPduId;
    CanTp_TxState[chnId].txPduId = txPduId;

    return;
}

/*
********************************************************************************
* Function Name: CanTp_TxCFTxConfirmation
*
* Explanation: TP CF was Confirmed.
*
* param: txPduId: pdu id.
*
* retval: None
********************************************************************************
*/
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
static FUNC(void, CANTP_CODE) CanTp_TxCFTxConfirmation(PduIdType txPduId)
{
    uint8 chnId;
    uint16 timer;
    CanTpTxNSdu_st *txFuncSduPtr;

    /* Get tx sdu data. */
    txFuncSduPtr = &CanTpTxSdu[txPduId];  /* Get tx sdu data. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule14.3" Polyspace +1 DEFECT:USELESS_IF [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
    if( NULL_PTR != txFuncSduPtr )
    {
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanTp_IDP" */
        chnId = txFuncSduPtr->CanTpChnId;
        /* Data transmission is not completed. */
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_CanTp_OBAI" */
        if( CanTp_TxState[chnId].totalDataLength < CanTp_TxState[chnId].dataLength )
        {
            CanTp_TxState[chnId].seqNumber += CANTP_INIT_ONE;

            if( CanTp_TxState[chnId].seqNumber > CANTP_MAX_SIN )
            {
                CanTp_TxState[chnId].seqNumber = CANTP_ZERO;
            }

            CanTp_TxState[chnId].timerStmin
                = CanTp_GetTxStminFromStminValue(CanTp_TxState[chnId].stmin);

            if( CANTP_ZERO != CanTp_TxState[chnId].bsCounter )  /* BS is not equal to zero. */
            {
                CanTp_TxState[chnId].bsCounter--;

                /* Block finished - Wait for FC. */
                if( CANTP_ZERO == CanTp_TxState[chnId].bsCounter )
                {
                    timer = (uint16)txFuncSduPtr->CanTpNbs / (uint16)CANTP_MAIN_PERIOD;

                    if( CANTP_ZERO == timer )
                    {
                        timer = CANTP_INIT_ONE;
                    }

                    CanTp_TxState[chnId].timer = timer;
                    CanTp_TxState[chnId].channelState = CANTP_TXSTATE_WAITFC;
                }
                else  /* Still CFs in the block left: Proceed with Txn of next CF. */
                {
                    CanTp_TxState[chnId].timer
                        = CanTp_GetTxStminFromStminValue(CanTp_TxState[chnId].stmin);
                    CanTp_TxState[chnId].channelState = CANTP_TXSTATE_WAITFORTPTXCF;
                }
            }
            else
            {
                /* Tx without blocks, BlocksizeCounter == 0. */
                /* Transmit next CF. */
                CanTp_TxState[chnId].timer
                  = CanTp_GetTxStminFromStminValue(CanTp_TxState[chnId].stmin);
                CanTp_TxState[chnId].channelState = CANTP_TXSTATE_WAITFORTPTXCF;
            }
        }
        else
        {
            CanTp_TxInit(txPduId, CANTP_NOTIFY);  /* Complete. */
        }
    }

    return;
}

/*
********************************************************************************
* Function Name: CanTp_GetTxStminFromStminValue
*
* Explanation: TP calculate Stmin.
*
* param: stMinValue: Received Stmin.
*
* retval: stminValue: Calculated Stmin.
********************************************************************************
*/
static FUNC(uint8, CANTP_CODE) CanTp_GetTxStminFromStminValue(uint8 stMinValue)
{
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
    uint8 stminValue;

    if( CANTP_ZERO != (stMinValue & CANTP_STMIN_PARA_HIGH) )
    {
        /* 100microsec * (tpSTminValue - 0xF0). */
        if( (CANTP_STMIN_MICROSEC_MIN <= stMinValue)
            && (CANTP_STMIN_MICROSEC_MAX >= stMinValue) )
        {
            /* Valid value but in the range of microseconds => 1 taskcycle. */
            stminValue = CANTP_INIT_ONE;
        }
        else
        {
            /* Invalid value. */
            stminValue = (uint8)(((uint8)CANTP_STMIN_MILLISEC_MAX
                + (uint8)CANTP_MAIN_PERIOD - (uint8)CANTP_INIT_ONE) / (uint8)CANTP_MAIN_PERIOD );
        }
    }
    else
    {
        /* Milliseconds. */
        if( stMinValue < CANTP_MAIN_PERIOD )
        {
            /* At once. */
            stminValue = CANTP_INIT_ONE;
        }
        else
        {
            /* Later. */
            if( CANTP_ZERO != (uint8)(stMinValue % (uint8)CANTP_MAIN_PERIOD) )
            {
                /* Calculate the number of cycles and add one. */
                stminValue = (uint8)((uint8)(stMinValue / (uint8)CANTP_MAIN_PERIOD) + (uint8)CANTP_INIT_ONE);
            }
            else
            {

#if( CANTP_TX_CF_STMIN_TIMECORRECTION_ENABLE == STD_ON )
                /* Enable time correction, calculate the number of cycles and add one. */
                stminValue = (uint8)((uint8)(stMinValue / (uint8)CANTP_MAIN_PERIOD) + (uint8)CANTP_INIT_ONE);
#else
                /* Turn off time correction and calculate the number of cycles. */
                stminValue = (uint8)(stMinValue / (uint8)CANTP_MAIN_PERIOD);
#endif  /* CANTP_TX_CF_STMIN_TIMECORRECTION_ENABLE == STD_ON */

            }
        }
    }

    return stminValue;
}

/*
********************************************************************************
* Function Name: CanTp_TxStateTask
*
* Explanation: TP send data function.
*
* param: txPduId: PDU Id.
*        withData: Whether to use the data. TRUE: With data, FALSE: Without data.
*
* retval: STminValue
********************************************************************************
*/
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
static FUNC(void, CANTP_CODE) CanTp_TxStateTask(PduIdType txPduId, boolean withData)
{
    CanTpTxNSdu_st* txSduPtr;

    txSduPtr = &CanTpTxSdu[txPduId];

    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanTp_IDP" */
    if( (uint8)CANTP_CAN20 == txSduPtr->CanType )
    {
        CanTp_TxStateTask_CAN20(txPduId, withData);
    }

#if( STD_ON == CANTP_CANFD_SUPPORT )
    else
    {
        CanTp_TxStateTask_CANFD(txPduId, withData);
    }
#endif

}

/*
********************************************************************************
* Function Name: CanTp_TxStateTask_CAN20
*
* Explanation: TP send data function.
*
* param: txPduId: PDU Id.
*        withData: Whether to use the data. TRUE: With data, FALSE: Without data.
*
* retval: STminValue
********************************************************************************
*/
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
static FUNC(void, CANTP_CODE) CanTp_TxStateTask_CAN20(PduIdType txPduId, boolean withData)
{
    uint8 frameType;
    uint8 dataOffset = CANTP_ZERO;
    uint8 sendSduLength = CANTP_ZERO;
    uint8 dataIndex;
    uint8 chnId;
    PduInfoType pdurInfo;
    CanTpRxNSdu_st* rxSduPtr;
    CanTpTxNSdu_st* txSduPtr;

    txSduPtr = &CanTpTxSdu[txPduId];
    chnId = txSduPtr->CanTpChnId;

    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_CanTp_OBAI" */
    if( (CANTP_CANRX_CF == CanTp_TxState[chnId].frameType)
        && (CANTP_ZERO < CanTp_TxState[chnId].timerStmin)
        && (CANTP_ZERO < CanTp_TxState[chnId].stmin) )
    {
        /* wait for STmin expiry if no burst mode is selected. */
    }
    else if( CANTP_ZERO != CanTp_TxState[chnId].queued )
    {
        /* Enough data available (either enough for 1 frame or end of transfer). */
        switch( CanTp_TxState[chnId].frameType )
        {
            case CANTP_CANRX_SF:
                /*TpAssembleSF */
                dataOffset  = CANTP_SF_OFFSET;
                frameType = CANTP_CANRX_SF;

                CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE] = CANTP_SF;
                CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE]
                     |= (uint8)((CanTp_TxState[chnId].dataLength) & CANTP_FRAME_LMASK);

                if( (CanTp_TxState[chnId].dataLength
                    - CanTp_TxState[chnId].totalDataLength) > (uint16)CANTP_SF_MAX_LEN )
                {
                    frameType = CANTP_CANINVALIDFRAME;
                }
                else
                {
                    sendSduLength = (uint8)(CanTp_TxState[chnId].dataLength
                        - CanTp_TxState[chnId].totalDataLength);
                    for( dataIndex = sendSduLength + CANTP_INIT_ONE;
                         /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.14" Polyspace +1 DEFECT:TAINTED_SIGN_CHANGE [Justified:Unset] "NSCA_Polyspace_CanTp_TAINTED_SIGN_CHANGE" */
                         dataIndex <= CANTP_SF_MAX_LEN; dataIndex++ )
                    {
                        CanTp_CanTxBuffer[chnId][dataIndex] = CANTP_PADDING_PATTERN;
                    }
                }
                break;

            case CANTP_CANRX_FF:
                /* TpAssembleFF */
                dataOffset  = CANTP_FF_OFFSET;
                frameType = CANTP_CANRX_FF;

                CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE] = CANTP_FF;
                CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE]
                    |= (uint8)(CanTp_GetHiByte(CanTp_TxState[chnId].dataLength) & CANTP_FRAME_LMASK);
                CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE + CANTP_INIT_ONE]
                    = (uint8)(CanTp_TxState[chnId].dataLength);

                if( (CanTp_TxState[chnId].dataLength
                    - CanTp_TxState[chnId].totalDataLength) <= (uint16)CANTP_SF_MAX_LEN )
                {
                    frameType = CANTP_CANINVALIDFRAME;
                }
                else
                {
                    sendSduLength = CANTP_FF_DATA_LEN;
                    CanTp_TxState[chnId].seqNumber = CANTP_INIT_ONE; /* Set SN to initial starting number. */
                    CanTp_TxState[chnId].bsCounter = CANTP_ZERO;
                    CanTp_TxState[chnId].totalDataLength = CANTP_ZERO;

                    rxSduPtr = &CanTpRxSdu[CanTp_TxState[chnId].rxPduId]; /* Get rx sdu data. */
                    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule14.3" Polyspace +1 DEFECT:USELESS_IF [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
                    if( NULL_PTR != rxSduPtr )
                    {
                        /* To set the WFT counter. */
                        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanTp_IDP" */
                        CanTp_RxState[chnId].wftCounter = rxSduPtr->CanTpRxWftMax;
                    }
                }
                break;

            case CANTP_CANRX_CF:
                /*AssembleCF */
                dataOffset  = CANTP_CF_OFFSET;

                CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE] = CANTP_CF;
                CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE]
                    |= (uint8)(CanTp_TxState[chnId].seqNumber);

                frameType = CANTP_CANRX_CF;

                if( (CanTp_TxState[chnId].dataLength
                    - CanTp_TxState[chnId].totalDataLength) >= (uint16)CANTP_MF_MIN_LEN )
                {
                    /* Next CF. */
                    sendSduLength = CANTP_MF_MIN_LEN;
                }
                else
                {
                    /* Last CF. */
                    sendSduLength = (uint8)(CanTp_TxState[chnId].dataLength
                        - CanTp_TxState[chnId].totalDataLength);
                    for( dataIndex = sendSduLength + CANTP_INIT_ONE;
                                                /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.14" Polyspace +1 DEFECT:TAINTED_SIGN_CHANGE [Justified:Unset] "NSCA_Polyspace_CanTp_TAINTED_SIGN_CHANGE" */
                                                dataIndex <= CANTP_MF_MIN_LEN; dataIndex++ )
                    {
                        CanTp_CanTxBuffer[chnId][dataIndex] = CANTP_PADDING_PATTERN;
                    }
                }
                break;

            default:
                frameType = CANTP_CANINVALIDFRAME;
                break;
        }

        if( frameType != CANTP_CANINVALIDFRAME )  /* Send frame data. */
        {
            if( TRUE == withData )
            {
                /* Polyspace +1 MISRA-C3:18.4 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule18.4" */
                CanTp_MemCpy(CanTp_CanTxBuffer[chnId] + dataOffset,  /* PRQA S 0488 */ /* NSCA_QAC_CanTp_Rule18.4 */
                    CanTp_TxState[chnId].dataBufferPtr
                    /* Polyspace +1 MISRA-C3:18.4 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule18.4" */
                    + CanTp_TxState[chnId].totalDataLength, sendSduLength);  /* PRQA S 0488 */ /* NSCA_QAC_CanTp_Rule18.4 */
            }
            else
            {
                /* Polyspace +1 MISRA-C3:18.4 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule18.4" */
                CanTp_MemCpy(CanTp_CanTxBuffer[chnId] + dataOffset,  /* PRQA S 0488 */ /* NSCA_QAC_CanTp_Rule18.4 */
                    CanTp_TxState[chnId].dataBufferPtr, sendSduLength);  /* PRQA S 0488 */ /* NSCA_QAC_CanTp_Rule18.4 */
            }
            CanTp_TxState[chnId].totalDataLength += sendSduLength;

            if( (uint8)CANTP_ON == CanTpTxSdu[txPduId].CanTpTxPaddingActivation )
            {
                sendSduLength = CANTP_SF_MAX_LEN + CANTP_INIT_ONE;
            }
            else
            {
                sendSduLength += dataOffset;
            }

            pdurInfo.SduDataPtr = &CanTp_CanTxBuffer[chnId][CANTP_ZERO];
            pdurInfo.SduLength = sendSduLength;
            CanTp_TxSemaphore[chnId] = (uint8)CANTP_TX;
            CanTp_TxState[chnId].queued  = CANTP_ZERO;
            CanTp_TxState[chnId].txPduId = txPduId;
            /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if( NULL_PTR != CanTpTxSdu[txPduId].CanTp_TransmitToCanIf_p )
            {
                (void)CanTpTxSdu[txPduId].CanTp_TransmitToCanIf_p(txSduPtr->CanIfTxPduId, &pdurInfo);
            }
        }
    }
    else
    {
        /* Do nothing. */
    }

    return;
}

#if( STD_ON == CANTP_CANFD_SUPPORT )
/*
********************************************************************************
* Function Name: CanTp_TxStateTask_CANFD
*
* Explanation: TP send data function.
*
* param: txPduId: PDU Id.
*        withData: Whether to use the data. TRUE: With data, FALSE: Without data.
*
* retval: STminValue
********************************************************************************
*/
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
static FUNC(void, CANTP_CODE) CanTp_TxStateTask_CANFD(PduIdType txPduId, boolean withData)
{
    uint8 frameType;
    uint8 dataOffset = CANTP_ZERO;
    uint8 dataIndex;
    uint8 chnId;
    PduInfoType pdurInfo;
    uint8 sendSduLength = CANTP_ZERO;
    uint16 curLength = CANTP_ZERO;
    uint16 pduLength = CANTP_ZERO;
    CanTpRxNSdu_st* rxSduPtr;
    CanTpTxNSdu_st* txSduPtr;

    txSduPtr = &CanTpTxSdu[txPduId];
    chnId = txSduPtr->CanTpChnId;

    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_CanTp_OBAI" */
    if( (CANTP_CANRX_CF == CanTp_TxState[chnId].frameType)
        && (CANTP_ZERO < CanTp_TxState[chnId].timerStmin)
        && (CANTP_ZERO < CanTp_TxState[chnId].stmin) )
    {
        /* wait for STmin expiry if no burst mode is selected. */
    }
    else if( CANTP_ZERO != CanTp_TxState[chnId].queued )
    {
        /* Enough data available (either enough for 1 frame or end of transfer). */
        switch( CanTp_TxState[chnId].frameType )
        {
            case CANTP_CANRX_SF:
                if( CANTP_STANDARD_FRAME_LENGTH > CanTp_TxState[chnId].dataLength )
                {
                    curLength = CanTp_TxState[chnId].dataLength + CANTP_SF_OFFSET;

                }
                else
                {
                    curLength = CanTp_TxState[chnId].dataLength + CANTP_SF_OFFSET_CANFD;
                }

                if( curLength <= CANTP_STANDARD_FRAME_LENGTH )
                {
                    pduLength = CANTP_STANDARD_FRAME_LENGTH;
                    dataOffset  = CANTP_SF_OFFSET;

                    CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE] = CANTP_SF;
                    CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE]
                     |= (uint8)((CanTp_TxState[chnId].dataLength) & CANTP_FRAME_LMASK);
                }
                else if( curLength <= CANTP_LEN_CANFDDLC24 )
                {
                    pduLength = (uint8)(((uint8)(curLength - CANTP_INIT_ONE) & CANTP_INIT_0XFC) + CANTP_INIT_FOUR);
                    dataOffset  = CANTP_SF_OFFSET_CANFD;

                    CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE] = CANTP_SF;
                    CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE_CANFD]
                     = (uint8)(CanTp_TxState[chnId].dataLength);
                }
                else if( curLength <= CANTP_LEN_CANFDDLC64 )
                {
                    pduLength = (uint8)(((uint8)(curLength - CANTP_INIT_ONE) & CANTP_INIT_0XF0) + CANTP_INIT_0X10);
                    dataOffset  = CANTP_SF_OFFSET_CANFD;

                    CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE] = CANTP_SF;
                    CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE_CANFD]
                     = (uint8)(CanTp_TxState[chnId].dataLength);
                }
                else
                {
                }

                /*TpAssembleSF */
                frameType = CANTP_CANRX_SF;
                if( CANTP_LEN_CANFDDLC8 == txSduPtr->CanTpTxDataLen )
                {
                    if( (CanTp_TxState[chnId].dataLength- CanTp_TxState[chnId].totalDataLength) 
                        >((uint16)txSduPtr->CanTpTxDataLen - CANTP_INIT_ONE) )
                    {
                        frameType = CANTP_CANINVALIDFRAME;
                    }
                    else
                    {
                        sendSduLength = (uint8)(CanTp_TxState[chnId].dataLength - CanTp_TxState[chnId].totalDataLength);

                        for( dataIndex = sendSduLength + dataOffset;
                             dataIndex < pduLength; dataIndex++ )
                        {
                            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_CanTp_OBAI" */
                            CanTp_CanTxBuffer[chnId][dataIndex] = CANTP_PADDING_PATTERN;
                        }
                    }
                }
                else if( ( CANTP_LEN_CANFDDLC12 == txSduPtr->CanTpTxDataLen )
                       ||( CANTP_LEN_CANFDDLC16 == txSduPtr->CanTpTxDataLen )
                       ||( CANTP_LEN_CANFDDLC20 == txSduPtr->CanTpTxDataLen )
                       ||( CANTP_LEN_CANFDDLC24 == txSduPtr->CanTpTxDataLen )
                       ||( CANTP_LEN_CANFDDLC32 == txSduPtr->CanTpTxDataLen )
                       ||( CANTP_LEN_CANFDDLC48 == txSduPtr->CanTpTxDataLen )
                       ||( CANTP_LEN_CANFDDLC64 == txSduPtr->CanTpTxDataLen ))
                {
                    if( (CanTp_TxState[chnId].dataLength - CanTp_TxState[chnId].totalDataLength) 
                        > ((uint16)txSduPtr->CanTpTxDataLen - CANTP_INIT_TWO) )
                    {
                        frameType = CANTP_CANINVALIDFRAME;
                    }
                    else
                    {
                        sendSduLength = (uint8)(CanTp_TxState[chnId].dataLength - CanTp_TxState[chnId].totalDataLength);

                        for( dataIndex = sendSduLength + dataOffset;
                             dataIndex < pduLength; dataIndex++ )
                        {
                            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_CanTp_OBAI" */
                            CanTp_CanTxBuffer[chnId][dataIndex] = CANTP_PADDING_PATTERN;
                        }
                    }
                }
                else
                {
                    frameType = CANTP_CANINVALIDFRAME;
                }
                break;

            case CANTP_CANRX_FF:
                /* TpAssembleFF */
                frameType = CANTP_CANRX_FF;
                if( CANTP_FFDATALENGTH >= (CanTp_TxState[chnId].dataLength - CanTp_TxState[chnId].totalDataLength) )
                {
                    dataOffset  = CANTP_FF_OFFSET_CANFD;
                    CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE] = CANTP_FF;
                    CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE]
                        |= (uint8)(CanTp_GetHiByte(CanTp_TxState[chnId].dataLength) & CANTP_FRAME_LMASK);
                    CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE + CANTP_INIT_ONE]
                        = (uint8)(CanTp_TxState[chnId].dataLength);
                }
                else
                {
                    dataOffset  = CANTP_BYTE_SIX;
                    CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE] = CANTP_FF;
                    CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE + CANTP_BYTE_ONE] = CANTP_ZERO;
                    CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE + CANTP_BYTE_TWO]
                        = CanTp_GetHiHiByte(CanTp_TxState[chnId].dataLength);
                    CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE + CANTP_BYTE_THREE]
                        = CanTp_GetHiLoByte(CanTp_TxState[chnId].dataLength);
                    CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE + CANTP_BYTE_FOUR]
                        = CanTp_GetLoHiByte(CanTp_TxState[chnId].dataLength);
                    CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE + CANTP_BYTE_FIVE]
                        = CanTp_GetLoLoByte(CanTp_TxState[chnId].dataLength);
                }
                if(( CANTP_LEN_CANFDDLC8 == txSduPtr->CanTpTxDataLen )
                  ||( CANTP_LEN_CANFDDLC12 == txSduPtr->CanTpTxDataLen )
                  ||( CANTP_LEN_CANFDDLC16 == txSduPtr->CanTpTxDataLen )
                  ||( CANTP_LEN_CANFDDLC20 == txSduPtr->CanTpTxDataLen )
                  ||( CANTP_LEN_CANFDDLC24 == txSduPtr->CanTpTxDataLen )
                  ||( CANTP_LEN_CANFDDLC32 == txSduPtr->CanTpTxDataLen )
                  ||( CANTP_LEN_CANFDDLC48 == txSduPtr->CanTpTxDataLen )
                  ||( CANTP_LEN_CANFDDLC64 == txSduPtr->CanTpTxDataLen ))
                {
                    if( (CanTp_TxState[chnId].dataLength - CanTp_TxState[chnId].totalDataLength) 
                        <= ((uint16)txSduPtr->CanTpTxDataLen - CANTP_INIT_TWO))
                    {
                        frameType = CANTP_CANINVALIDFRAME;
                    }
                    else
                    {
                        pduLength = txSduPtr->CanTpTxDataLen;
                        if(CANTP_FFDATALENGTH >= (CanTp_TxState[chnId].dataLength - CanTp_TxState[chnId].totalDataLength))
                        {
                            sendSduLength = txSduPtr->CanTpTxDataLen - CANTP_INIT_TWO;
                        }
                        else
                        {
                            sendSduLength = txSduPtr->CanTpTxDataLen - CANTP_BYTE_SIX;
                        }
                        curLength = txSduPtr->CanTpTxDataLen;
                        CanTp_TxState[chnId].seqNumber = CANTP_INIT_ONE; /* Set SN to initial starting number. */
                        CanTp_TxState[chnId].bsCounter = CANTP_ZERO;
                        CanTp_TxState[chnId].totalDataLength = CANTP_ZERO;

                        rxSduPtr = &CanTpRxSdu[CanTp_TxState[chnId].rxPduId]; /* Get rx sdu data. */
                        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule14.3" Polyspace +1 DEFECT:USELESS_IF [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
                        if( NULL_PTR != rxSduPtr )
                        {
                            /* To set the WFT counter. */
                            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanTp_IDP" */
                            CanTp_RxState[chnId].wftCounter = rxSduPtr->CanTpRxWftMax;
                        }
                    }
                }
                else
                {
                    frameType = CANTP_CANINVALIDFRAME;
                }
                break;

            case CANTP_CANRX_CF:
                /*AssembleCF */
                dataOffset  = CANTP_CF_OFFSET;

                CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE]  = CANTP_CF;
                CanTp_CanTxBuffer[chnId][CANTP_FMTOFFSET_FRAMETYPE]
                    |= (uint8)(CanTp_TxState[chnId].seqNumber);

                frameType = CANTP_CANRX_CF;
                if( (CanTp_TxState[chnId].dataLength - CanTp_TxState[chnId].totalDataLength) 
                    >= ( (uint16)txSduPtr->CanTpTxDataLen - CANTP_INIT_ONE) )
                {
                    /* Next CF. */
                    sendSduLength = txSduPtr->CanTpTxDataLen - CANTP_INIT_ONE;
                }
                else
                {
                    /* Last CF. */
                    sendSduLength = (uint8)(CanTp_TxState[chnId].dataLength
                        - CanTp_TxState[chnId].totalDataLength);

                }
                curLength = (uint16)sendSduLength + CANTP_CF_OFFSET_CANFD;
                if( curLength <= CANTP_STANDARD_FRAME_LENGTH )
                {
                    pduLength = CANTP_STANDARD_FRAME_LENGTH;
                    dataOffset  = CANTP_CF_OFFSET;
                }
                else if( curLength <= CANTP_LEN_CANFDDLC24 )
                {
                    pduLength = (uint8)(((uint8)(curLength - CANTP_INIT_ONE) & CANTP_INIT_0XFC) + CANTP_INIT_FOUR);
                    dataOffset  = CANTP_CF_OFFSET;
                }
                else if( curLength <= CANTP_LEN_CANFDDLC64 )
                {
                    pduLength = (uint8)(((uint8)(curLength - CANTP_INIT_ONE) & CANTP_INIT_0XF0) + CANTP_INIT_0X10);
                    dataOffset  = CANTP_CF_OFFSET;
                }
                else
                {
                }

                for( dataIndex = sendSduLength + CANTP_INIT_ONE; dataIndex < pduLength; dataIndex++ )
                {
                    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_CanTp_OBAI" */
                    CanTp_CanTxBuffer[chnId][dataIndex] = CANTP_PADDING_PATTERN;
                }
                break;

            default:
                frameType = CANTP_CANINVALIDFRAME;
                break;
        }

        if( frameType != CANTP_CANINVALIDFRAME )  /* Send frame data. */
        {
            if( TRUE == withData )
            {
                /* Polyspace +1 MISRA-C3:18.4 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule18.4" */
                CanTp_MemCpy(CanTp_CanTxBuffer[chnId] + dataOffset,  /* PRQA S 0488 */ /* NSCA_QAC_CanTp_Rule18.4 */
                /* Polyspace +1 MISRA-C3:18.4 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule18.4" */
                    CanTp_TxState[chnId].dataBufferPtr + CanTp_TxState[chnId].totalDataLength, sendSduLength);  /* PRQA S 0488 */ /* NSCA_QAC_CanTp_Rule18.4 */
            }
            else
            {
                /* Polyspace +1 MISRA-C3:18.4 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule18.4" */
                CanTp_MemCpy(CanTp_CanTxBuffer[chnId] + dataOffset, CanTp_TxState[chnId].dataBufferPtr, sendSduLength);  /* PRQA S 0488 */ /* NSCA_QAC_CanTp_Rule18.4 */
            }
            CanTp_TxState[chnId].totalDataLength += sendSduLength;

            if( (uint8)CANTP_ON == CanTpTxSdu[txPduId].CanTpTxPaddingActivation )
            {
                sendSduLength = (uint8)pduLength;
            }
            else
            {
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 DEFECT:UINT_CONV_OVFL [Justified:Unset] "NSCA_Polyspace_CanTp_UINT_CONV_OVFL" */
                sendSduLength = (uint8)curLength;
            }

            pdurInfo.SduDataPtr = &CanTp_CanTxBuffer[chnId][CANTP_ZERO];
            pdurInfo.SduLength = sendSduLength;
            CanTp_TxSemaphore[chnId] = (uint8)CANTP_TX;
            CanTp_TxState[chnId].queued  = CANTP_ZERO;
            CanTp_TxState[chnId].txPduId = txPduId;
            /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if( NULL_PTR != CanTpTxSdu[txPduId].CanTp_TransmitToCanIf_p )
            {
                (void)CanTpTxSdu[txPduId].CanTp_TransmitToCanIf_p(txSduPtr->CanIfTxPduId, &pdurInfo);
            }

        }
    }
    else
    {
        /* Do nothing. */
    }

    return;
}
#endif

/*
********************************************************************************
* Function Name: CanTp_Check_TransmitData
*
* Explanation: Check the validation of the transmited value.
*
* param: CanTpTxSduId: Tx sdu id.
*        CanTpTxInfoPtr: Data buffer.
*        ErrorId: Error status.
*
* retval: E_OK: The transmited data is valid.
*         E_NOT_OK: The transmited data is invalid.
********************************************************************************
*/
static FUNC(Std_ReturnType, CANTP_CODE) CanTp_Check_TransmitData
(
    PduIdType CanTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) CanTpTxInfoPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_APPL_DATA) ErrorId
)
{
    Std_ReturnType lReturnValue = E_OK;

    if( NULL_PTR == ErrorId )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        lReturnValue = E_NOT_OK;
    }
    else if( (PduIdType)CANTP_TXSDU_NUM <= CanTpTxSduId )
    {
        *ErrorId = CANTP_E_INVALID_TX_ID;
        lReturnValue = E_NOT_OK;
    }
    else if( (NULL_PTR == CanTpTxInfoPtr) ||
        (CANTP_ZERO == CanTpTxInfoPtr->SduLength) )
    {
        *ErrorId = CANTP_E_PARAM_POINTER;
        lReturnValue = E_NOT_OK;
    }
    else
    {
        /* Do nothing. */
    }

    return lReturnValue;
}

/*
********************************************************************************
* Function Name: CanTp_Transmit_WithData
*
* Explanation: Transmit the data, which contains data in call-function CanTp_Transmit.
*
* param: CanTpTxSduId: Tx sdu id.
*        CanTpTxInfoPtr: Data buffer.
*        ErrorId: Error status.
*
* retval: E_OK: The transmited data is valid.
*         E_NOT_OK: The transmited data is invalid.
********************************************************************************
*/
static FUNC(Std_ReturnType, CANTP_CODE) CanTp_Transmit_WithData  /* PRQA S 3219 */ /* NSCA_QAC_Common_Unreachable */
(
    PduIdType CanTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) CanTpTxInfoPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_APPL_DATA) ErrorId
)
{
    Std_ReturnType lReturnValue = E_OK;
    uint8 chnId;
    uint8 frameType;
    uint16 timer;
    CanTpTxNSdu_st *txFuncSduPtr;
    CanTp_TxStateType_st* tpTxStatePtr;

    lReturnValue = CanTp_Check_TransmitData(CanTpTxSduId, CanTpTxInfoPtr, ErrorId);
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( E_OK == lReturnValue )
    {
        txFuncSduPtr = &CanTpTxSdu[CanTpTxSduId];  /* Get tx sdu data. */
        /* Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule14.3" Polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
        if( NULL_PTR != txFuncSduPtr )
        {
            chnId = txFuncSduPtr->CanTpChnId;
            tpTxStatePtr = &CanTp_TxState[chnId];

            /* Check channel state. */
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanTp_IDP" */
            if( tpTxStatePtr->channelState != CANTP_TXSTATE_IDLE )
            {
                *ErrorId = CANTP_E_INVALID_TX_STATE;
                lReturnValue = E_NOT_OK;
            }
            else
            {
                /* Wait for Tx Isr confirmation of FF or SF. */
                tpTxStatePtr->channelState = CANTP_TXSTATE_WAITFORSFORFFCONFISR;
                tpTxStatePtr->dataBufferPtr = CanTpTxInfoPtr->SduDataPtr;

                if( (uint8)CANTP_CANFD == txFuncSduPtr->CanType )
                {
                    if( CANTP_LEN_CANFDDLC8 == txFuncSduPtr->CanTpTxDataLen )
                    {
                        if( txFuncSduPtr->CanTpTxDataLen >= (CanTpTxInfoPtr->SduLength + CANTP_INIT_ONE) )
                        {
                            /* Single frame sufficient. */
                            frameType = CANTP_CANRX_SF;
                        }
                        else
                        {
                            /* Multi frame necessary. */
                            frameType = CANTP_CANRX_FF;
                        }
                    }
                    else if( (CANTP_LEN_CANFDDLC12 == txFuncSduPtr->CanTpTxDataLen)
                           ||(CANTP_LEN_CANFDDLC16 == txFuncSduPtr->CanTpTxDataLen)
                           ||(CANTP_LEN_CANFDDLC20 == txFuncSduPtr->CanTpTxDataLen)
                           ||(CANTP_LEN_CANFDDLC24 == txFuncSduPtr->CanTpTxDataLen)
                           ||(CANTP_LEN_CANFDDLC32 == txFuncSduPtr->CanTpTxDataLen)
                           ||(CANTP_LEN_CANFDDLC48 == txFuncSduPtr->CanTpTxDataLen)
                           ||(CANTP_LEN_CANFDDLC64 == txFuncSduPtr->CanTpTxDataLen))
                    {
                        if( txFuncSduPtr->CanTpTxDataLen >= (CanTpTxInfoPtr->SduLength + CANTP_INIT_TWO) )
                        {
                            /* Single frame sufficient. */
                            frameType = CANTP_CANRX_SF;
                        }
                        else
                        {
                            /* Multi frame necessary. */
                            frameType = CANTP_CANRX_FF;
                        }
                    }
                    else
                    {
                        frameType = CANTP_CANINVALIDFRAME;
                    }
                }
                else
                {
                    if( CanTpTxInfoPtr->SduLength <= CANTP_SF_MAX_LEN )
                    {
                        /* Single frame sufficient. */
                        frameType = CANTP_CANRX_SF;
                    }
                    else
                    {
                        /* Multi frame necessary. */
                        frameType = CANTP_CANRX_FF;
                    }
                }
                if( CANTP_CANINVALIDFRAME != frameType )
                {
                    tpTxStatePtr->totalDataLength = CANTP_ZERO;  /* Copy data. */
                    tpTxStatePtr->dataLength = (uint16)CanTpTxInfoPtr->SduLength;
                    tpTxStatePtr->frameType = frameType;
                    timer = (uint16)txFuncSduPtr->CanTpNas / (uint16)CANTP_MAIN_PERIOD;

                    if( CANTP_ZERO == timer )
                    {
                        timer = CANTP_INIT_ONE;
                    }
                    tpTxStatePtr->timer = timer;
                    tpTxStatePtr->queued++;

                    CanTp_TxStateTask(CanTpTxSduId, TRUE);  /* Send data. */

                    lReturnValue = E_OK;
                }
                else
                {
                    lReturnValue = E_NOT_OK;
                }

            }
        /* Polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        }
        else
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            *ErrorId = CANTP_E_PARAM_POINTER;
            lReturnValue = E_NOT_OK;
        }
    }

    return lReturnValue;
}

/*
********************************************************************************
* Function Name: CanTp_Transmit_WithOutData
*
* Explanation: Transmit the data, which do not contain data in call-function CanTp_Transmit.
*
* param: CanTpTxSduId: Tx sdu id.
*        CanTpTxInfoPtr: Data buffer.
*        ErrorId: Error status.
*
* retval: E_OK: The transmited data is valid.
*         E_NOT_OK: The transmited data is invalid.
********************************************************************************
*/
static FUNC(Std_ReturnType, CANTP_CODE) CanTp_Transmit_WithOutData
(
    PduIdType CanTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) CanTpTxInfoPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_APPL_DATA) ErrorId
)
{
    Std_ReturnType lReturnValue = E_OK;
    uint8 chnId;
    uint8 frameType;
    BufReq_ReturnType chkResult;
    uint16 timer;
    CanTpTxNSdu_st *txFuncSduPtr;
    CanTp_TxStateType_st* tpTxStatePtr;
    PduLengthType availableDataPtr = CANTP_ZERO;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
    PduInfoType info;
    RetryInfoType retry = {TP_CONFPENDING,CANTP_ZERO};

    lReturnValue = CanTp_Check_TransmitData(CanTpTxSduId, CanTpTxInfoPtr, ErrorId);
    if( E_OK == lReturnValue )
    {
        txFuncSduPtr = &CanTpTxSdu[CanTpTxSduId];  /* Get tx sdu data. */
        /* Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule14.3" Polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
        if( NULL_PTR != txFuncSduPtr )
        {
            chnId = txFuncSduPtr->CanTpChnId;
            tpTxStatePtr = &CanTp_TxState[chnId];

            /* Check channel state. */
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanTp_IDP" */
            if( tpTxStatePtr->channelState != CANTP_TXSTATE_IDLE )
            {
                *ErrorId = CANTP_E_INVALID_TX_STATE;
                lReturnValue = E_NOT_OK;
            }
            else
            {
                if( (uint8)CANTP_CANFD == txFuncSduPtr->CanType )
                {
                    if( CANTP_LEN_CANFDDLC8 == txFuncSduPtr->CanTpTxDataLen )
                    {
                        if( txFuncSduPtr->CanTpTxDataLen >= (CanTpTxInfoPtr->SduLength + CANTP_INIT_ONE) )
                        {
                            /* Single frame sufficient. */
                            frameType = CANTP_CANRX_SF;
                            info.SduLength = CanTpTxInfoPtr->SduLength;
                        }
                        else
                        {
                            /* Multi frame necessary. */
                            frameType = CANTP_CANRX_FF;
                            info.SduLength = (PduLengthType)txFuncSduPtr->CanTpTxDataLen - CANTP_INIT_ONE;
                        }
                    }
                    else if( (CANTP_LEN_CANFDDLC12 == txFuncSduPtr->CanTpTxDataLen)
                           ||(CANTP_LEN_CANFDDLC16 == txFuncSduPtr->CanTpTxDataLen)
                           ||(CANTP_LEN_CANFDDLC20 == txFuncSduPtr->CanTpTxDataLen)
                           ||(CANTP_LEN_CANFDDLC24 == txFuncSduPtr->CanTpTxDataLen)
                           ||(CANTP_LEN_CANFDDLC32 == txFuncSduPtr->CanTpTxDataLen)
                           ||(CANTP_LEN_CANFDDLC48 == txFuncSduPtr->CanTpTxDataLen)
                           ||(CANTP_LEN_CANFDDLC64 == txFuncSduPtr->CanTpTxDataLen))
                    {
                        if( txFuncSduPtr->CanTpTxDataLen >= (CanTpTxInfoPtr->SduLength + CANTP_INIT_TWO) )
                        {
                            /* Single frame sufficient. */
                            frameType = CANTP_CANRX_SF;
                            info.SduLength = CanTpTxInfoPtr->SduLength;
                        }
                        else
                        {
                            /* Multi frame necessary. */
                            frameType = CANTP_CANRX_FF;
                            info.SduLength = (PduLengthType)txFuncSduPtr->CanTpTxDataLen - CANTP_INIT_TWO;
                        }
                    }
                    else
                    {
                        frameType = CANTP_CANINVALIDFRAME;
                    }
                }
                else
                {
                    if( CanTpTxInfoPtr->SduLength <= CANTP_SF_MAX_LEN )
                    {
                        /* Single frame sufficient. */
                        frameType = CANTP_CANRX_SF;
                        info.SduLength = CanTpTxInfoPtr->SduLength;
                    }
                    else
                    {
                        /* Multi frame necessary. */
                        frameType = CANTP_CANRX_FF;
                        info.SduLength = CANTP_FF_DATA_LEN;
                    }
                }
                if( CANTP_CANINVALIDFRAME != frameType )
                {
                    info.SduDataPtr = CanTp_CanTxCopyBuffer[chnId];
                    /* Polyspace +1 DEFECT:PADDING_INFO_LEAK [Justified:Unset] "NSCA_Polyspace_CanTp_PADDING_INFO_LEAK" */
                    chkResult = PduR_CanTpCopyTxData(txFuncSduPtr->PduRTxPduId, &info, &retry, &availableDataPtr);
                    if( BUFREQ_OK == chkResult )
                    {
                        /* Wait for Tx Isr confirmation of FF or SF. */
                        tpTxStatePtr->channelState = CANTP_TXSTATE_WAITFORSFORFFCONFISR;
                        CanTp_TxState[chnId].dataBufferPtr = CanTp_CanTxCopyBuffer[chnId];
                        tpTxStatePtr->totalDataLength = CANTP_ZERO;  /* Copy data. */
                        tpTxStatePtr->dataLength = (uint16)CanTpTxInfoPtr->SduLength;
                        tpTxStatePtr->frameType = frameType;
                        timer = (uint16)txFuncSduPtr->CanTpNas / (uint16)CANTP_MAIN_PERIOD;

                        if( CANTP_ZERO == timer )
                        {
                            timer = CANTP_INIT_ONE;
                        }
                        tpTxStatePtr->timer = timer;
                        tpTxStatePtr->queued++;
                        CanTp_TxState[chnId].copyType = TRUE;

                        CanTp_TxStateTask(CanTpTxSduId, FALSE);  /* Send data. */

                        lReturnValue = E_OK;
                    }
                    else if( BUFREQ_E_BUSY == chkResult )
                    {
                        CanTp_TxState[chnId].timer = CANTP_INIT_ONE;  /* Set the timer. */
                        CanTp_TxState[chnId].copyType = TRUE;
                        lReturnValue = E_OK;
                    }
                    else
                    {
                        lReturnValue = E_NOT_OK;
                    }
                }
                else
                {
                    lReturnValue = E_NOT_OK;
                }
            }
        /* Polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        }
        else
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            *ErrorId = CANTP_E_PARAM_POINTER;
            lReturnValue = E_NOT_OK;
        }
    }

    return lReturnValue;
}

/*
********************************************************************************
* Function Name: CanTp_CopyCFTxData
*
* Explanation: Copy CF Tx data in MainFunction.
*
* param: chnId: channel id.
*
* retval: void
********************************************************************************
*/
static FUNC(void, CANTP_CODE) CanTp_CopyCFTxData
(
    uint8 chnId
)
{
    BufReq_ReturnType chkResult;
    uint16 timer;
    CanTpTxNSdu_st *txFuncSduPtr;
    CanTp_TxStateType_st* tpTxStatePtr;
    PduLengthType availableDataPtr = CANTP_ZERO;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
    PduInfoType info;
    RetryInfoType retry = {TP_CONFPENDING,CANTP_ZERO};

    tpTxStatePtr = &CanTp_TxState[chnId];
    txFuncSduPtr = &CanTpTxSdu[tpTxStatePtr->txPduId];
    info.SduLength = (PduLengthType)CanTp_TxState[chnId].dataLength - (PduLengthType)CanTp_TxState[chnId].totalDataLength;

    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanTp_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanTp_IDP" */
    if( (uint8)CANTP_CANFD == txFuncSduPtr->CanType )
    {
        if( (CANTP_LEN_CANFDDLC8 == txFuncSduPtr->CanTpTxDataLen)
          ||(CANTP_LEN_CANFDDLC12 == txFuncSduPtr->CanTpTxDataLen)
          ||(CANTP_LEN_CANFDDLC16 == txFuncSduPtr->CanTpTxDataLen)
          ||(CANTP_LEN_CANFDDLC20 == txFuncSduPtr->CanTpTxDataLen)
          ||(CANTP_LEN_CANFDDLC24 == txFuncSduPtr->CanTpTxDataLen)
          ||(CANTP_LEN_CANFDDLC32 == txFuncSduPtr->CanTpTxDataLen)
          ||(CANTP_LEN_CANFDDLC48 == txFuncSduPtr->CanTpTxDataLen)
          ||(CANTP_LEN_CANFDDLC64 == txFuncSduPtr->CanTpTxDataLen))
        {
            if( (CanTp_TxState[chnId].dataLength- CanTp_TxState[chnId].totalDataLength) 
                >= (uint16)( (uint16)txFuncSduPtr->CanTpTxDataLen - CANTP_INIT_ONE) )
            {
                /* Next CF. */
                info.SduLength = (PduLengthType)txFuncSduPtr->CanTpTxDataLen - CANTP_INIT_ONE;
            }
        }
        else
        {
            /* Nothing to do. */
        }
    }
    else
    {
        if( (CanTp_TxState[chnId].dataLength
                    - CanTp_TxState[chnId].totalDataLength) >= (uint16)CANTP_MF_MIN_LEN )
        {
            /* Next CF. */
            info.SduLength = CANTP_MF_MIN_LEN;
        }
    }

    info.SduDataPtr = CanTp_CanTxCopyBuffer[chnId];
    /* Polyspace +1 DEFECT:PADDING_INFO_LEAK [Justified:Unset] "NSCA_Polyspace_CanTp_PADDING_INFO_LEAK" */
    chkResult = PduR_CanTpCopyTxData(txFuncSduPtr->PduRTxPduId, &info, &retry, &availableDataPtr);
    if( BUFREQ_OK == chkResult )
    {
        /* Wait for Tx Isr confirmation of FF or SF. */
        tpTxStatePtr->channelState = CANTP_TXSTATE_WAITFORCFCONFISR;
        CanTp_TxState[chnId].dataBufferPtr = CanTp_CanTxCopyBuffer[chnId];

        timer = (uint16)txFuncSduPtr->CanTpNas / (uint16)CANTP_MAIN_PERIOD;
        if( CANTP_ZERO == timer )
        {
            timer = CANTP_INIT_ONE;
        }
        tpTxStatePtr->timer = timer;
        tpTxStatePtr->queued++;

        CanTp_TxStateTask(tpTxStatePtr->txPduId, FALSE);  /* Send data. */
    }
    else if( BUFREQ_E_BUSY == chkResult )
    {
        CanTp_TxState[chnId].timer = CANTP_INIT_ONE;  /* Set the timer. */
    }
    else
    {
        /* Nothing to do. */
    }

    return;
}

/*
********************************************************************************
* Function Name: CanTp_Transmit
*
* Explanation: This service is used to request the transfer of segmented data.
*
* param: CanTpTxSduId: This parameter contains the unique CanTp module identifier of the CAN.
*                      N-SDU to be transmitted.
*        CanTpTxInfoPtr: SPDU info.
*
* retval: E_OK:The request can be started successfully.
*         E_NOT_OK: The request cannot be started.
********************************************************************************
*/
FUNC(Std_ReturnType, CANTP_CODE) CanTp_Transmit
(
    PduIdType CanTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) CanTpTxInfoPtr
)
{
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
    uint8 ErrorId = CANTP_E_NO_ERROR;
    Std_ReturnType lReturnValue = E_OK;

    if( (PduIdType)CANTP_TXSDU_NUM <= CanTpTxSduId )
    {
        ErrorId = CANTP_E_INVALID_TX_ID;
        lReturnValue = E_NOT_OK;
    }
    /* Check initial state. */
    else if( (uint8)CANTP_STATUS_INITIALIZED != CanTp_InitState )
    {
        ErrorId = CANTP_E_UNINIT;
        lReturnValue = E_NOT_OK;
    }
    /* Check point. */
    else if( (NULL_PTR == CanTpTxInfoPtr) ||
        /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.14" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanTp_TAINTED_PTR" */
        (CANTP_ZERO == CanTpTxInfoPtr->SduLength) )
    {
        ErrorId = CANTP_E_PARAM_POINTER;
        lReturnValue = E_NOT_OK;
    }
    else
    {
#if(CANTP_TRANSMIT_WITHOUTDATA == STD_ON)
        /* Indirectly obtaining data through PduR_CanTpCopyTxData. */
        lReturnValue = CanTp_Transmit_WithOutData(CanTpTxSduId, CanTpTxInfoPtr, &ErrorId);
#else
        if( NULL_PTR != CanTpTxInfoPtr->SduDataPtr )
        {
            lReturnValue = CanTp_Transmit_WithData(CanTpTxSduId, CanTpTxInfoPtr, &ErrorId);
        }

        else
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            lReturnValue = CanTp_Transmit_WithOutData(CanTpTxSduId, CanTpTxInfoPtr, &ErrorId);
        }
#endif  /* CANTP_TRANSMIT_WITHOUTDATA == STD_ON */
    }

    CanTp_Det_ErrorReport(CANTP_SID_TRANSMIT, ErrorId);  /* Det report. */

    return lReturnValue;
}

/*
********************************************************************************
* Function Name: CanTp_CancelTransmit
*
* Explanation: This service primitive is used to cancel the transfer of a pending CAN N-SDU.
*              When the function returns, no transmission is in progress anymore with the given
*              N-SDU identifier.
*
* param: CanTpTxSduId: This parameter contains the unique CanTp module identifier of the N-SDU
*                     to be cancelled for transmission.
*
* retval: E_OK: Cancellation request of the specified N-SDU is accepted.
*         E_NOT_OK: Cancellation request is rejected.
********************************************************************************
*/
FUNC(Std_ReturnType, CANTP_CODE) CanTp_CancelTransmit(PduIdType CanTpTxSduId)   /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    uint8 chnId;
    uint8 lErrorId = CANTP_E_NO_ERROR;
    Std_ReturnType lResult;

    if( CanTp_InitState != (uint8)CANTP_STATUS_INITIALIZED )  /* Check initial state. */
    {
        lErrorId = CANTP_E_UNINIT;
        lResult = E_NOT_OK;
    }
    else
    {
        if( (PduIdType)CANTP_TXSDU_NUM <= CanTpTxSduId )
        {
            lErrorId = CANTP_E_INVALID_TX_ID;
            lResult = E_NOT_OK;
        }
        else
        {
            chnId = CanTpTxSdu[CanTpTxSduId].CanTpChnId;
            CanTp_TxInitState(chnId);  /* Release tx resource. */
            lResult = E_OK;
        }
    }
    CanTp_Det_ErrorReport(CANTP_SID_CANCELTRANSMIT, lErrorId);  /* Det report. */

    return lResult;
}

/*
********************************************************************************
* Function Name: CanTp_CancelReceive
*
* Explanation: This service is used to cancel the reception of an ongoing N-SDU.
*
* param: CanTpRxSduId: This service is used to cancel the reception of an ongoing N-SDU.
*
* retval: E_OK: Cancellation request of the specified N-SDU is accepted.
*         E_NOT_OK: Cancellation request is rejected.
********************************************************************************
*/
FUNC(Std_ReturnType, CANTP_CODE) CanTp_CancelReceive(PduIdType CanTpRxSduId)   /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    Std_ReturnType lResult;
    uint8 lErrorId = CANTP_E_NO_ERROR;

    if( CanTp_InitState != (uint8)CANTP_STATUS_INITIALIZED )  /* Check initial state. */
    {
        lErrorId = CANTP_E_UNINIT;
        lResult = E_NOT_OK;
    }
    else
    {
        if( (PduIdType)CANTP_RXSDU_NUM <= CanTpRxSduId )
        {
            lErrorId = CANTP_E_INVALID_RX_ID;
            lResult = E_NOT_OK;
        }
        else
        {
            CanTp_RxInitState(CanTpRxSdu[CanTpRxSduId].CanTpChnId);  /* Release rx resource. */
            lResult = E_OK;
        }
    }

    CanTp_Det_ErrorReport(CANTP_SID_CANCELRECEIVE, lErrorId);  /* Det report. */

    return lResult;

}

#if ( CANTP_ENABLE_CHANGE_PARAM == STD_ON )
/*
********************************************************************************
* Function Name: CanTp_ChangeParameter
*
* Explanation: This service is used to request the change of reception parameters BS and STmin
*              for a specified N-SDU.
*
* param: id: Identifier of the received N-SDU on which the reception parameter has to be changed.
*        parameter: Specify the parameter to which the value has to be changed (BS or STmin).
*        value: The new value of the parameter.
*
* retval: E_OK: request is accepted.
*         E_NOT_OK: request is not accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, CANTP_CODE) CanTp_ChangeParameter
(
    PduIdType id,
    VAR(TPParameterType, AUTOMATIC) parameter,
    uint16 value
)
{
    Std_ReturnType lResult;
    uint8 lErrorId = CANTP_E_NO_ERROR;

    /* Check initial state. */
    if( CanTp_InitState != (uint8)CANTP_STATUS_INITIALIZED )
    {
        lErrorId = CANTP_E_UNINIT;
        lResult = E_NOT_OK;
    }
    else if( id >= (PduIdType)CANTP_RXSDU_NUM )  /* Check pdu id. */
    {
        lErrorId = CANTP_E_INVALID_RX_ID;
        lResult = E_NOT_OK;
    }
    else if( (parameter != TP_STMIN) && (parameter != TP_BS) )  /* Check parameter. */
    {
        lErrorId = CANTP_E_PARAM_ID;
        lResult = E_NOT_OK;
    }
    else
    {
        if( TP_STMIN == parameter )  /* Stmin process. */
        {
            if ( ((value > CANTP_STMIN_MILLISEC_MAX)
                && (value < CANTP_STMIN_MICROSEC_MIN))
                || (value > CANTP_STMIN_MICROSEC_MAX) )
            {
                lErrorId = CANTP_E_PARAM_ID;
                lResult = E_NOT_OK;
            }
            else
            {
                CanTpRxSdu[id].CanTpSTmin = value;
                lResult = E_OK;
            }
        }
        /* BS process. */
        else
        {
            CanTpRxSdu[id].CanTpBs = (uint8)value;
            lResult = E_OK;
        }
    }

    CanTp_Det_ErrorReport(CANTP_SID_CHANGEPARAMETER, lErrorId);  /* Det report. */

    return lResult;
}
#endif /* CANTP_ENABLE_CHANGE_PARAM == STD_ON */

#if ( CANTP_ENABLE_READ_PARAM == STD_ON )
/*
********************************************************************************
* Function Name: CanTp_ReadParameter
*
* Explanation: This service is used to read the current value of reception parameters BS and
*                    STmin for a specified N-SDU.
*
* param: id:Identifier of the received N-SDU on which the reception parameter are read.
*        parameter: Specify the parameter to which the value has to be read (BS orSTmin).
*        value:Pointer where the parameter value will be provided.
*
* retval: E_OK: request is accepted.
*         E_NOT_OK: request is not accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, CANTP_CODE) CanTp_ReadParameter
(
    PduIdType id,
    TPParameterType parameter,
    P2VAR(uint16, AUTOMATIC, CANTP_APPL_DATA) value
)
{
    Std_ReturnType lResult;
    uint8 lErrorId = CANTP_E_NO_ERROR;

    if( CanTp_InitState != (uint8)CANTP_STATUS_INITIALIZED )  /* Check initial state. */
    {
        lErrorId = CANTP_E_UNINIT;
        lResult = E_NOT_OK;
    }
    else if( id >= (PduIdType)CANTP_RXSDU_NUM )  /* Check pdu id. */
    {
        lErrorId = CANTP_E_INVALID_RX_ID;
        lResult = E_NOT_OK;
    }
    else if( (parameter != TP_STMIN) && (parameter != TP_BS) )  /* Check parameter. */
    {
        lErrorId = CANTP_E_PARAM_ID;
        lResult = E_NOT_OK;
    }
    else if( NULL_PTR == value )  /* Check point. */
    {
        lErrorId = CANTP_E_PARAM_POINTER;
        lResult = E_NOT_OK;
    }
    else
    {
        if ( TP_STMIN == parameter )  /* Stmin process. */
        {
            *value = (uint16)CanTpRxSdu[id].CanTpSTmin;
        }
        else  /* BS process. */
        {
            *value = CanTpRxSdu[id].CanTpBs;
        }
        lResult = E_OK;
    }

    CanTp_Det_ErrorReport(CANTP_SID_READPARAMETER, lErrorId);  /* Det report. */

    return lResult;
}
#endif /* CANTP_ENABLE_READ_PARAM == STD_ON */

/*
********************************************************************************
* Function Name: CanTp_Init
*
* Explanation: This function initializes the CanTp module.
*
* param: CfgPtr: Pointer to the CanTp post-build configuration data.
*
* retval: None
********************************************************************************
*/
FUNC(void, CANTP_CODE) CanTp_Init
(
    P2CONST(CanTp_ConfigType, AUTOMATIC, CANTP_APPL_CONST) CfgPtr
)
{
    uint8 chnId;
    uint8 lErrorId = CANTP_E_NO_ERROR;

    CANTP_DUMMY_STATEMENT(CfgPtr);

    if( (uint8)CANTP_STATUS_INITIALIZED == CanTp_InitState )  /* Check init state. */
    {
        lErrorId = CANTP_E_INIT_FAILED;
    }
    else
    {
        for( chnId = CANTP_ZERO; chnId < (uint8)CANTP_CHANNEL_NUM; chnId++ )
        {
            CanTp_TxInitState(chnId);  /* Initial tx resource. */
            CanTp_RxInit(chnId, NTFRSLT_E_NOT_OK);  /* Initial rx resource. */

            CanTp_RxState[chnId].dataBufferPtr = NULL_PTR;
            CanTp_TxState[chnId].dataBufferPtr = NULL_PTR;
            /* Clear rx buffer. */
            CanTp_MemSet(CanTp_CanRxBuffer[chnId], CANTP_ZERO, sizeof(CanTp_CanRxBuffer[chnId]));
            /* Clear tx buffer. */
            CanTp_MemSet(CanTp_CanTxBuffer[chnId], CANTP_ZERO, sizeof(CanTp_CanTxBuffer[chnId]));
            CanTp_TxSemaphore[chnId] = (uint8)CANTP_IDLE;
        }

        CanTp_InitState = CANTP_STATUS_INITIALIZED;
    }

    CanTp_Det_ErrorReport(CANTP_SID_INIT, lErrorId);  /* Det report. */

    return;
}

/*
********************************************************************************
* Function Name: CanTp_TxApplTxConfirmation
*
* Explanation: TP indicate confirmation to Dcm.
*
* param: PduIdType txPduId: PDU Id.
*        result: 0: indicate tx ok; 1: indicate tx not_ok.
*
* retval: None
********************************************************************************
*/
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
static FUNC(void, CANTP_CODE) CanTp_TxApplTxConfirmation(PduIdType txPduId, uint8 result)
{
    PduIdType pduIdToPdur;

    /* Get tx PduId. */
    if( (PduIdType)CANTP_TXSDU_NUM > txPduId )
    {
        pduIdToPdur = CanTpTxSdu[txPduId].PduRTxPduId;
        (void)PduR_CanTpTxConfirmation(pduIdToPdur, result);  /* Indicate Dcm. */
    }

    return;
}

/*
********************************************************************************
* Function Name: CanTp_RxIndication
*
* Explanation: Indication of a received I-PDU from a lower layer communication interface module.
*
* param: PduIdType RxPduId: ID of the received I-PDU
         const PduInfoType* PduInfoPtr: Contains the length (SduLength) of the
                            received I-PDU and a pointer to a buffer (SduDataPtr) containing the I-PDU.
*
* retval: None
********************************************************************************
*/
FUNC(void, CANTP_CODE) CanTp_RxIndication
(
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr
)
{
    uint8 lErrorId = CANTP_E_NO_ERROR;
    uint8 chnId;
    CanTpRxNSdu_st *rxSduPtr;

    if( CanTp_InitState != (uint8)CANTP_STATUS_INITIALIZED )  /* Check initial state. */
    {
        lErrorId = CANTP_E_UNINIT;
    }
    else if( NULL_PTR == PduInfoPtr )  /* Check point. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        lErrorId = CANTP_E_PARAM_POINTER;
    }
    else if( (PduIdType)CANTP_RXSDU_NUM <= RxPduId )
    {
        lErrorId = CANTP_E_INVALID_RX_ID;
    }
#if( CANTP_COMMUNICATION_USER_RULE_SUPPORT == STD_ON )
    //UDS报文自定义发送规则保护
    else if(E_NOT_OK == UDS_Communication_User_Rule())
    {
        return ;
    }
#endif
    else
    {
        rxSduPtr = &CanTpRxSdu[RxPduId];
        chnId = rxSduPtr->CanTpChnId;

        CanTp_MemCpy(&CanTp_CanRxBuffer[chnId][CANTP_ZERO],
            /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.14" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanTp_TAINTED_PTR" */
            PduInfoPtr->SduDataPtr, (uint16)PduInfoPtr->SduLength);
        CanTp_CanIfRxIndication(RxPduId, *PduInfoPtr);  /* Indicate. */

    }

    CanTp_Det_ErrorReport(CANTP_SID_RXINDICATION, lErrorId);  /* Det report. */

    return;
}

/*
********************************************************************************
* Function Name: CanTp_MainFunction
*
* Explanation: The main function for scheduling the CAN TP.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, CANTP_CODE) CanTp_MainFunction(void)
{
    if( (uint8)CANTP_STATUS_INITIALIZED == CanTp_InitState )
    {
        CanTp_MainFunctionRx();  /* Rx main function. */
        CanTp_MainFunctionTx();  /* Tx main function. */
    }
}


/*
********************************************************************************
* Function Name: CanTp_Shutdown
*
* Explanation: This function is called to shutdown the CanTp module.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, CANTP_CODE) CanTp_Shutdown(void)  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    uint8  lErrorId = CANTP_E_NO_ERROR;
    uint8 chnId;

    /* Check initial state. */
    if( CanTp_InitState != (uint8)CANTP_STATUS_INITIALIZED )
    {
        lErrorId = CANTP_E_UNINIT;
    }
    else
    {
        for( chnId = CANTP_ZERO; chnId < (uint8)CANTP_CHANNEL_NUM; chnId++ )
        {
            CanTp_RxInit(chnId, NTFRSLT_E_NOT_OK);  /* Release the resource of the TP. */
        }

        CanTp_InitState = CANTP_STATUS_SHUTDOWN;  /* Set cantp state. */

    }

    CanTp_Det_ErrorReport(CANTP_SID_SHUTDOWN, lErrorId);  /* Det report. */

    return;
}

#define CANTP_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

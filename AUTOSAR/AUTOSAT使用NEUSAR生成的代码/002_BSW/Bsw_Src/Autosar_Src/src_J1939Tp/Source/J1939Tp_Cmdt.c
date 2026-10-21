/*
********************************************************************************
*
* File name: 1939Tp_Cmdt.c
*
* Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: yong.zhang/2019.3.18
* Change: New created.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: yong.zhang/2019.05.10
* Change: Valide TxSduId, ensure not overstep array boundary.
* Cause: Optimization
********************************************************************************
* Version: 1.2
* Author/Date: li.zhiheng/2020.01.09
* Change: Modify PduR_J1939TpTxConfirmation,PduR_J1939TpCopyTxData parameter.
* Cause: Update
********************************************************************************
*  Version: 1.3
*  Author/Date: li.zhiheng/2020.03.26
*  Change: Modify the code according to QAC.
*  Cause: Update
********************************************************************************
* Version: 3.0
* Author/Date: li.zhiheng/2020.03.30
* Change: Nothing
* Cause: Update to 3.0.
********************************************************************************
* Version: 3.1
* Author/Date: li.zhiheng/2020.05.20
* Change: Modification code specification.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: li.zhiheng/2020.09.25
* Change: Modify the autosar coding style.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: li.zhiheng/2020.09.26
* Change: Add code related to MEMAP.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: li.zhiheng/2020.10.15
* Change: 1.Modify coding standards.
*         2.Modify QAC warning.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: LiZH/2020.11.04
* Change: Delete the function declaration contained in MemMap.h.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: LiZH/2021.04.27
* Change: Add retry process.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: LiZH/2021.05.25
* Change: 1.Add Meta process.
*         2.Delete check TxInfoPtr NULL in J1939Tp_Transmit.
*         3.Delete J1939Tp_GetTxSduIdx, J1939Tp_GetRxSduIdx invalid function.
*         4.Modifty J1939Tp_ChangeParameter,J1939Tp_CancelReceive,J1939Tp_CancelTransmit det errorid.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: LiZH/2021.05.25
* Change: Modify the scope of Channel index.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: LiZH/2021.05.31
* Change: Modify J1939Tp_CmdtRxIndication_GetTxSduIdx, J1939Tp_CmdtRxIndication_GetRxSduIdx
*         find SduIdx.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: LiZH/2021.05.31
* Change: Modify J1939Tp_CmdtRxIndication_GetTxSduIdx, J1939Tp_CmdtRxIndication_GetRxSduIdx
*         find SduIdx.
* Cause: Bugfix
********************************************************************************
* Version: 3.11
* Author/Date: LiZH/2021.06.02
* Change: Modify SQXCCORE-29 J1939Tp_CmdtTransmit judge packet error.
* Cause: Bugfix
********************************************************************************
* Version: 3.12
* Author/Date: LiZH/2021.06.15
* Change: 1.Modify SQXCCORE-57 J1939Tp_CmdtRxIndication_GetTxSduIdx sa/da error.
*         2.Modify SQXCCORE-60 J1939Tp_CmdtTxConfirmation packet count error.
*         3.Modify SQXCCORE-58 J1939Tp_CmdtRxIndication_RtsGetSduIdx sa/da error.
* Cause: Bugfix
********************************************************************************
* Version: 3.13
* Author/Date: LiZH/2021.06.17
* Change: 1.Modify TPDT packet++ check.
* Cause: Bugfix
********************************************************************************
* Version: 3.14
* Author/Date: LiZH/2021.07.28
* Change: Modify the polyspace problem.
* Cause: Bugfix
********************************************************************************
* Version: 3.15
* Author/Date: LiZH/2021.8.16
* Change: Modification code specification.
* Cause: Optimize
********************************************************************************
* Version: 3.16
* Author/Date: LiZH/2021.9.02
* Change: Modified pointer error in J1939Tp_StartOfReception_CmdtProcess.
* Cause: Bugfix
********************************************************************************
* Version: 3.17
* Author/Date: TongXY/2022.06.16
* Change: Modified CCOREDBUG-718.
*         1.Add NextBlock updata in J1939Tp_CmdtRxIndication_ReceiveTpCmCts function,
*           when tx retry process.
*         2.Change the continuous receipt of RTS in J1939Tp_CmdtRxIndication_RtsGetSduIdx.
* Cause: Bugfix
********************************************************************************
* Version: 3.18
* Author/Date: TongXY/2022.12.26
* Change: Modified Address error in J1939Tp_CmdtRxIndication_GetTxSduIdx.
* Cause: Bugfix
********************************************************************************
* Version: 3.19
* Author/Date: TongXY/2023.3.9
* Change: 1.Added the functions of retransmission and dynamic length packet sending.
*         2.Modify compilation warning.
*         3.Modified qac warning.
*         4.Fix coding specification problems.
* Cause: Optimization
********************************************************************************
* Version: 3.20
* Author/Date: TongXY/2023.3.27
* Change: 1.Modify the conditions for entering data length error processing in
*           the J1939Tp_CmdtInternalRxIndication_ReceiveTpCmRts function.
* Cause: Optimization
********************************************************************************
* Version: 3.21
* Author/Date: TongXY/2023.5.9
* Change: Change the length of addrInfo.SduLength in the
*         J1939Tp_CmdtInternalRxIndication_ReceiveTpCmRts to J1939TP_ZERO.
* Cause: Bugfix
********************************************************************************
* Version: 3.22
* Author/Date: TongXY/2023.05.24
* Change: 1.Memmap macro value to all uppercase.
*         2.To see if they are equal, we put the constant on the left.
* Cause: Optimization
********************************************************************************
* Version: 3.23
* Author/Date: LiuY/2023.08.17
* Change: Fix compilation warning.
* Cause: Optimization
********************************************************************************
* Version: 3.24
* Author/Date: YanCL/2023.11.28
* Change: Modify the NSdu status error setting in  
*         J1939Tp_CmdtInternalTransmitTpAbortTx function & 
*         J1939Tp_CmdtInternalTransmitTpCmEOMAck function.
* Cause: Bugfix
********************************************************************************
* Version: 3.25
* Author/Date: YanCL/2024.3.19
* Change: Modify the P2CONST incorrect labels.
* Cause: Optimization
********************************************************************************
* Version: 3.26
* Author/Date: YanCL/2024.4.2
* Change: 1.Modify the P2CONST incorrect labels.
*         2.Modify the annotation.
* Cause: Optimization
********************************************************************************
* Version: 3.27
* Author/Date: YanCL/2024.5.23
* Change: 1.Implement J1939Tp module to send TP.DT messages according to the
*           configured time in CMDT mode.
*         2.Adjusting the parameter positions of function declarations.
* Cause: Update
********************************************************************************
* Version: 3.28
* Author/Date: YanCL/2024.6.25
* Change: 1.Add Memmap segment definition.
*         2.Add copyright information.
* Cause: Update
********************************************************************************
* Version: 3.29
* Author/Date: YanCL/2025.03.26
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.30
* Author/Date: YanCL/2025.06.06
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.31
* Author/Date: YanCL/2025.06.23
* Change: #include "J1939Tp_MemMap.h" add suppression comments.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Include
********************************************************************************
*/
#include "J1939Tp_Cfg.h"
#include "J1939Tp.h"
#include "J1939Tp_Int.h"
#include "J1939Tp_Cmdt.h"
#include "PduR_J1939Tp.h"
#include "CanIf.h"

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
#define J1939TP_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"

static FUNC(void, J1939TP_CODE) J1939Tp_CmdtInternalTransmitTpCmRts(PduIdType sduIdx);
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtInternalTransmitTpAbortTx(PduIdType sduIdx);
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtInternalTransmitTpAbortRx(PduIdType sduIdx);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtInternalTransmitTpDt(PduIdType sduIdx);
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtInternalTransmitTpCmCts(PduIdType sduIdx);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtInternalTransmitTpCmEOMAck(PduIdType sduIdx);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtRxIndication_ReceiveTpCmEomack(PduIdType sduIdx);
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtRxIndication_ReceiveTpAbortTx(PduIdType sduIdx);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtInternalRxIndication_ReceiveTpCmRts
(
    PduIdType sduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    uint8 sa,
    uint8 da,
    uint16 size,
    J1939Tp_RxSduStateType* rxSduState
);
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtRxIndication_ReceiveTpCmCts
(
    PduIdType sduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtInternalRxIndication_ReceiveTpDt
(
    uint16 sduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    J1939Tp_RxSduStateType* rxSduState
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtRxIndication_ReceiveTpAbortRx
(
    uint16 sduIdx,
    J1939Tp_RxSduStateType* rxSduState
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtRxMain_ToProcess(PduIdType sduIdx);
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtTxMain_ToProcess(PduIdType sduIdx);
static FUNC(BufReq_ReturnType, J1939TP_CODE) J1939Tp_CopyTxData_CmdtProcesss
(
    PduIdType sduIdx,
    PduInfoType pdu
);
static FUNC(void, J1939TP_CODE)J1939Tp_Retry_InCMDT_Transmission
(
    uint16 sduIdx,
    uint8 retrySequence,
    uint32 pgn
);
static FUNC(BufReq_ReturnType, J1939TP_CODE) J1939Tp_StartOfReception_CmdtProcess
(
    PduIdType sduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    uint32 size,
    J1939Tp_RxSduStateType* rxSduState
);
static FUNC(boolean, J1939TP_CODE)J1939Tp_CmdtChkTxSduScope(PduIdType sduIdx);
static FUNC(boolean, J1939TP_CODE)J1939Tp_CmdtChkTxPduScope(PduIdType PduIdx);
static FUNC(uint16, J1939TP_CODE) J1939Tp_CmdtRxIndication_RtsGetSduIdx
(
    uint8 sa,
    uint8 da,
    uint32 pgn
);
static FUNC(uint16, J1939TP_CODE) J1939Tp_CmdtRxIndication_GetRxSduIdx
(
    uint8 sa,
    uint8 da,
    uint32 pgn
);
static FUNC(uint16, J1939TP_CODE) J1939Tp_CmdtRxIndication_GetTxSduIdx
(
    uint8 sa,
    uint8 da,
    uint32 pgn
);

#define J1939TP_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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

#define J1939TP_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
* Function Name: J1939Tp_CmdtChkTxSduScope
*
* Explanation: Check SduIdx size.
*
* param: sduIdx: ID of the send SDU.
* retval: flag:
********************************************************************************
*/
static FUNC(boolean, J1939TP_CODE)J1939Tp_CmdtChkTxSduScope
(
    PduIdType sduIdx
)
{
    boolean flag = FALSE;
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( sduIdx < J1939TP_TXNSDU_NUMBER )
    {
        flag = TRUE;
    }

    return flag;
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtChkTxPduScope
*
* Explanation: Check PduIdx size.
*
* param: PduIdx: ID of the send PDU.
* retval: flag:
********************************************************************************
*/
static FUNC(boolean, J1939TP_CODE)J1939Tp_CmdtChkTxPduScope
(
    PduIdType PduIdx
)
{
    boolean flag = FALSE;
    if( PduIdx < J1939TP_TXPDU_NUM )
    {
        flag = TRUE;
    }

    return flag;
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtInternalTransmitTpCmRts
*
* Explanation: Internal process transmit tpcm rts.
*
* param: sduIdx: ID of the send SDU.
*
* retval: void
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtInternalTransmitTpCmRts
(
    PduIdType sduIdx
)
{
    boolean flag = FALSE;
    boolean checksduIdxflag = FALSE;
    boolean checkpduIdxflag = FALSE;
    Std_ReturnType result;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 txChannelIdx = J1939Tp_TxSduInfo[sduIdx].txSduOfChannelIdx;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Dir4.5" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 pduIdx = J1939Tp_TxChannel[txChannelIdx].txCmNPduIdx;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint32 pgn = J1939Tp_TxSduInfo[sduIdx].txPgPgn;
    J1939Tp_TxPduStateType* pduState = NULL_PTR;
    J1939Tp_TxSduStateType* txSduState = NULL_PTR;
    uint8 data[J1939TP_NPDU_LENGTH] = {J1939TP_ZERO};
    PduInfoType pdu;

    checksduIdxflag = J1939Tp_CmdtChkTxSduScope(sduIdx);
    checkpduIdxflag = J1939Tp_CmdtChkTxPduScope(pduIdx);

    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( (TRUE == checksduIdxflag) && (TRUE == checkpduIdxflag) )
    {
        pduState = &J1939Tp_TxPduState[pduIdx];
        txSduState = &J1939Tp_TxSduState[sduIdx];
        flag = TRUE;
    }

    /* Not locked. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( TRUE == flag )
    {
        if( FALSE == pduState->Locked )
        {
            pduState->CurrentNSduType = J1939TP_NSDU_CMDT_TX;
            pduState->CurrentNSduId = sduIdx;
            pduState->ConfTimeout = J1939Tp_GetTxConfTimeout();

            /* Lock pdu state. */
            pduState->Locked = TRUE;

            /* Set data. */
            data[J1939TP_TPCM_CB] = (uint8)J1939TP_CB_RTS;
            data[J1939TP_TPCM_TMS_LO] = J1939Tp_Make_TMS_LO(txSduState->Size);
            data[J1939TP_TPCM_TMS_HI] = J1939Tp_Make_TMS_HI(txSduState->Size);
            data[J1939TP_TPCM_TNOP] = txSduState->Packets;
            data[J1939TP_TPCM_MNOP] = txSduState->MaxBlock;
            data[J1939TP_TPCM_PGN_LO] = J1939Tp_Make_PGN_LO(pgn);
            data[J1939TP_TPCM_PGN_MD] = J1939Tp_Make_PGN_MD(pgn);
            data[J1939TP_TPCM_PGN_HI] = J1939Tp_Make_PGN_HI(pgn);
            data[J1939TP_NPDU_SA_POS] = txSduState->Sender;
            data[J1939TP_NPDU_DA_POS] = txSduState->Receiver;
            data[J1939TP_NPDU_PRI_POS] = txSduState->Priority;

            pdu.SduDataPtr = data;
            pdu.SduLength = J1939TP_NPDU_LENGTH;

            /* State updtat to J1939TP_STATE_CMDT_RTS_CONF. */
            txSduState->State = J1939TP_STATE_CMDT_RTS_CONF;

            /* Call canif send rts. */
            result = CanIf_Transmit(J1939Tp_TxPdu[pduIdx].PduIdOfTxPdu, &pdu);
            if( result != E_OK )  /* Transmit faild. */
            {
                pduState->Locked = FALSE;
                txSduState->State = J1939TP_STATE_CMDT_RTS;
            }
        }
        else
        {
            txSduState->State = J1939TP_STATE_CMDT_RTS;
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtInternalTransmitTpAbortTx
*
* Explanation: Internal process transmit tpcm abort.
*
* param: sduIdx: ID of the send SDU.
*
* retval: void
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtInternalTransmitTpAbortTx
(
    PduIdType sduIdx
)
{
    boolean flag = FALSE;
    boolean checksduIdxflag = FALSE;
    boolean checkpduIdxflag = FALSE;
    Std_ReturnType result;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 channelIdx = J1939Tp_TxSduInfo[sduIdx].txSduOfChannelIdx;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Dir4.5" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 pduIdx = J1939Tp_TxChannel[channelIdx].txCmNPduIdx;
    uint32 pgn;
    J1939Tp_TxPduStateType* pduState = NULL_PTR;
    J1939Tp_TxSduStateType* txSduState = NULL_PTR;
    uint8 data[J1939TP_NPDU_LENGTH] = {J1939TP_ZERO};
    PduInfoType pdu;

    checksduIdxflag = J1939Tp_CmdtChkTxSduScope(sduIdx);
    checkpduIdxflag = J1939Tp_CmdtChkTxPduScope(pduIdx);

    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( (TRUE == checksduIdxflag) && (TRUE == checkpduIdxflag) )
    {
        pduState = &J1939Tp_TxPduState[pduIdx];
        txSduState = &J1939Tp_TxSduState[sduIdx];
        flag = TRUE;
    }

    /* Pdu state not locked. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( TRUE == flag )
    {
        if( FALSE == pduState->Locked )
        {
            pduState->CurrentNSduType = J1939TP_NSDU_CMDT_TX;
            pduState->CurrentNSduId = sduIdx;
            pduState->ConfTimeout = J1939Tp_GetTxConfTimeout();

            pduState->Locked = TRUE;
            /* Get pgn. */
            pgn = J1939Tp_TxSduInfo[sduIdx].txPgPgn;
            /* Set data. */
            data[J1939TP_TPCM_CB] = (uint8)J1939TP_CB_ABORT;
            data[J1939TP_TPCM_CAR] = (uint8) txSduState->AbortReason;
            data[J1939TP_TPCM_RES3] = J1939TP_SNA_VALUE;
            data[J1939TP_TPCM_RES4] = J1939TP_SNA_VALUE;
            data[J1939TP_TPCM_RES5] = J1939TP_SNA_VALUE;
            data[J1939TP_TPCM_PGN_LO] = J1939Tp_Make_PGN_LO(pgn);
            data[J1939TP_TPCM_PGN_MD] = J1939Tp_Make_PGN_MD(pgn);
            data[J1939TP_TPCM_PGN_HI] = J1939Tp_Make_PGN_HI(pgn);
            data[J1939TP_NPDU_SA_POS] = txSduState->Sender;
            data[J1939TP_NPDU_DA_POS] = txSduState->Receiver;
            data[J1939TP_NPDU_PRI_POS] = txSduState->Priority;

            pdu.SduDataPtr = data;
            pdu.SduLength = J1939TP_NPDU_LENGTH;
            /* Set sdu state abort confirm. */
            txSduState->State = J1939TP_STATE_CMDT_ABORT_CONF;
            /* Call canif send abort. */
            result = CanIf_Transmit(J1939Tp_TxPdu[pduIdx].PduIdOfTxPdu, &pdu);
            if( result != E_OK )
            {
                /* Release lock. */
                pduState->Locked = FALSE;
                /* Set sdu state cmdt abort. */
                txSduState->State = J1939TP_STATE_CMDT_ABORT;
            }
        }
        else
        {
            /* Set txsdu state. */
            txSduState->State = J1939TP_STATE_CMDT_ABORT;
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtInternalTransmitTpDt
*
* Explanation: Internal process transmit tpcm tpdt.
*
* param: sduIdx: ID of the send SDU.
*
* retval: void
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtInternalTransmitTpDt
(
    PduIdType sduIdx
)
{
    boolean flag = FALSE;
    boolean checksduIdxflag = FALSE;
    boolean checkpduIdxflag = FALSE;
    BufReq_ReturnType tpResult;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 channelIdx = J1939Tp_TxSduInfo[sduIdx].txSduOfChannelIdx;
    Std_ReturnType result;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Dir4.5" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    PduIdType pduIdx = J1939Tp_TxChannel[channelIdx].txDtNPduIdx;
    uint8 data[J1939TP_NPDU_LENGTH] = {J1939TP_ZERO};
    PduInfoType pdu;
    J1939Tp_TxSduStateType* txSduState = NULL_PTR;
    J1939Tp_TxPduStateType* pduState = NULL_PTR;

    checksduIdxflag = J1939Tp_CmdtChkTxSduScope(sduIdx);
    checkpduIdxflag = J1939Tp_CmdtChkTxPduScope(pduIdx);

    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( (TRUE == checksduIdxflag) && (TRUE == checkpduIdxflag) )
    {
        pduState = &J1939Tp_TxPduState[pduIdx];
        txSduState = &J1939Tp_TxSduState[sduIdx];
        flag = TRUE;
    }

    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( TRUE == flag )
    {
        if( FALSE == pduState->Locked )
        {
            pduState->CurrentNSduType = J1939TP_NSDU_CMDT_TX;
            pduState->CurrentNSduId = sduIdx;
            pduState->ConfTimeout = J1939Tp_GetTxConfTimeout();
            /* protected against concurrent access to the same TP.DT N-PDU */
            pduState->Locked = TRUE;

            pdu.SduDataPtr = &data[J1939TP_TPDT_DATA];
            pdu.SduLength = J1939TP_TPDT_DATA_SIZE;

            if( txSduState->Sequence == txSduState->Packets )
            {
                pdu.SduLength
                 = ((txSduState->Size) - (((txSduState->Sequence) - (uint32)J1939TP_ONE) * (uint32)J1939TP_TPDT_DATA_SIZE));
            }

            tpResult = J1939Tp_CopyTxData_CmdtProcesss(sduIdx, pdu);

            if( BUFREQ_OK == tpResult )
            {
                uint8 pos;
                data[J1939TP_TPDT_SEQ] = txSduState->Sequence;

                /* Not defined bit, set 1. */
                for( pos = J1939TP_TPDT_DATA + (uint8) pdu.SduLength; pos < J1939TP_FRAME_LENGTH; pos++ )
                {
                    data[pos] = J1939TP_SNA_VALUE;
                }

                data[J1939TP_NPDU_SA_POS] = txSduState->Sender;
                data[J1939TP_NPDU_DA_POS] = txSduState->Receiver;
                data[J1939TP_NPDU_PRI_POS] = txSduState->Priority;

                pdu.SduDataPtr = data;
                pdu.SduLength = J1939TP_NPDU_LENGTH;

                /* Set tx sdu state cmdt.data confirm. */
                txSduState->State = J1939TP_STATE_CMDT_DATA_CONF;
                /* Call canif send tpdt. */
                result = CanIf_Transmit(J1939Tp_TxPdu[pduIdx].PduIdOfTxPdu, &pdu);
                if( result != E_OK )
                {
                    /* Release lock. */
                    pduState->Locked = FALSE;
                    /* Set sdu state cmdt data. */
                    txSduState->State = J1939TP_STATE_CMDT_DATA;
                }
            }
            else
            {
                pduState->Locked = FALSE;
                if( BUFREQ_E_BUSY == tpResult )
                {
                    /* SWS_J1939Tp_00228. */
                    txSduState->State = J1939TP_STATE_CMDT_DATA;
                }
                else
                {
                    txSduState->AbortReason = J1939TP_CAR_RESOURCES;
                    /* The J1939Tp module shall abort the transmission session. SWS_J1939Tp_00048 */
                    J1939Tp_CmdtInternalTransmitTpAbortTx(sduIdx);
                }
            }
        }
        else
        {
            /* Set sdu state cmdt data. */
            txSduState->State = J1939TP_STATE_CMDT_DATA;
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_CopyTxData_CmdtProcesss
*
* Explanation: Internal process copytx data.
*
* param: sduIdx: ID of the send SDU.
*
* retval: void
********************************************************************************
*/
static FUNC(BufReq_ReturnType, J1939TP_CODE) J1939Tp_CopyTxData_CmdtProcesss
(
    PduIdType sduIdx,
    PduInfoType pdu
)
{
    BufReq_ReturnType tpResult;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 channelIdx = J1939Tp_TxSduInfo[sduIdx].txSduOfChannelIdx;
    J1939Tp_TxSduStateType* txSduState = &J1939Tp_TxSduState[sduIdx];

    /* If J1939TpTxRetrySupport is disabled, the parameter retry shall allways be set to the NULL_PTR. */
    /* Polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule14.3" Polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
    if( TRUE == J1939Tp_TxChannel[channelIdx].txRetrySupport ) /* SWS_J1939Tp_00218 */
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        RetryInfoType retryInfo;

        if( J1939TP_NEED_RETRY == txSduState->RetryState )
        {
            retryInfo.TpDataState = TP_DATARETRY;
            retryInfo.TxTpDataCnt = txSduState->ByteOffset;
            txSduState->RetryState = J1939TP_DONT_RETRY;
        }
        else
        {
            /* SWS_J1939Tp_00217 */
            if( J1939TP_ONE == txSduState->Sequence )
            {
                retryInfo.TpDataState = TP_DATACONF;
                retryInfo.TxTpDataCnt = J1939TP_ZERO;
            }
            else
            {
                retryInfo.TpDataState = TP_CONFPENDING;
                retryInfo.TxTpDataCnt = J1939TP_ZERO;
            }
        }
        tpResult = PduR_J1939TpCopyTxData((J1939Tp_TxSduInfo[sduIdx].txNSduIdx),
                                           /* Polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                                           (const PduInfoType*)&pdu,
                                           &retryInfo,
                                           (uint32*)&txSduState->DataSize);
    }
    else
    {   /* [SWS_J1939Tp_00218 */
        tpResult = PduR_J1939TpCopyTxData((J1939Tp_TxSduInfo[sduIdx].txNSduIdx),
                                           /* Polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                                           (const PduInfoType*)&pdu,
                                           NULL_PTR,
                                           (uint32*)&txSduState->DataSize);
    }

    return tpResult;

}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtTxMain
*
* Explanation: This functions process receive tpcm ack
*
* param: sduIdx: ID of the received I-PDU.
*
* retval: void
********************************************************************************
*/
FUNC(void, J1939TP_CODE) J1939Tp_CmdtTxMain
(
    PduIdType sduIdx
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    J1939Tp_TxSduStateType* txSduState = &J1939Tp_TxSduState[sduIdx];

    /* TP.DT sending time count in CMDT mode. */
    if( J1939TP_TPDT_COUNT != txSduState->TpDtCount )
    {
        txSduState->TpDtCount--;
    }

    if( TRUE == txSduState->Aborted )
    {
        if( (J1939TP_STATE_CMDT_RTS == txSduState->State) || (J1939TP_STATE_CMDT_CTS == txSduState->State) ||
            (J1939TP_STATE_CMDT_CTSWAIT == txSduState->State) || (J1939TP_STATE_CMDT_ABORT == txSduState->State) ||
            (J1939TP_STATE_CMDT_DATA == txSduState->State))
        {
            /* protected against concurrent Tx abort and concurrent reception of TP.ConnAbort */
            txSduState->State = J1939TP_STATE_FINISH;

            PduR_J1939TpTxConfirmation(J1939Tp_TxSduInfo[sduIdx].txNSduIdx, E_NOT_OK);

            /* no protection required - transition from uninterruptible state */
            txSduState->State = J1939TP_STATE_IDLE;
        }
    }
    /* Sdu timeout. */
    else if( J1939TP_ZERO == txSduState->TimeOut )
    {
        J1939Tp_CmdtTxMain_ToProcess(sduIdx);
    }
    else
    {
        --txSduState->TimeOut;

        switch( txSduState->State )
        {
            case J1939TP_STATE_CMDT_RTS:
                /* Retry send TP.CM_RTS.  */
                txSduState->State = J1939TP_STATE_CMDT_RTS_BUSY;

                J1939Tp_CmdtInternalTransmitTpCmRts(sduIdx);
                break;
            case J1939TP_STATE_CMDT_ABORT:
                txSduState->State = J1939TP_STATE_CMDT_ABORT_BUSY;
                /* Send abort. */
                J1939Tp_CmdtInternalTransmitTpAbortTx(sduIdx);
                break;
            case J1939TP_STATE_CMDT_DATA:
#if( J1939TP_DTTIME_TX_ENABLED == STD_ON )
                /* Message sequence and transmission time judgment. */
                if( (txSduState->Sequence <= txSduState->Packets) && (J1939TP_TPDT_COUNT == txSduState->TpDtCount) )
                {
                    /* Set Tr timeout time. */
                    txSduState->TimeOut = J1939Tp_GetTime_Tr();
                    /* Set the status to J1939TP_STATE_CMDT_DATA_BUSY. */
                    txSduState->State = J1939TP_STATE_CMDT_DATA_BUSY;
                    /* Send TP.DT. */
                    J1939Tp_CmdtInternalTransmitTpDt(sduIdx);
                }
#else
                txSduState->State = J1939TP_STATE_CMDT_DATA_BUSY;
                /* Send tpdt. */
                J1939Tp_CmdtInternalTransmitTpDt(sduIdx);
#endif  /* J1939TP_DTTIME_TX_ENABLED == STD_ON */
                break;
            default:
              /* Do Nothing. */
              break;
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtTransmit
*
* Explanation: This functions sends cmdt message
*
* param: sduIdx:   ID of the send SDU.
*           info :  Contains the length (SduLength) of the received I-PDU and a
*                   pointer to a buffer (SduDataPtr) containing the I-PDU.
*
* retval: Std_ReturnType
********************************************************************************
*/
#if (J1939TP_CMDT_TX_ENABLED == STD_ON)
FUNC(Std_ReturnType, J1939TP_CODE) J1939Tp_CmdtTransmit
(
    PduIdType sduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    uint8 sa,
    uint8 da,
    uint8 pri
)
{
    BufReq_ReturnType tpResult;
    Std_ReturnType result = E_NOT_OK;
#if( J1939TP_DTTIME_TX_ENABLED == STD_ON )
    PduIdType sduIdxLocal;
    uint8 parallelResult = E_OK;
#endif  /* J1939TP_DTTIME_TX_ENABLED == STD_ON */
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 txChannelIdx = J1939Tp_TxSduInfo[sduIdx].txSduOfChannelIdx;
    J1939Tp_TxSduStateType* txSduState = &J1939Tp_TxSduState[sduIdx];
    PduInfoType txInfo;

#if( J1939TP_DTTIME_TX_ENABLED == STD_ON )
    /* [SWS_J1939Tp_00120] Ensure that handling all N-SDU parallel connections does not interfere with the use of TP. */
    for( sduIdxLocal = J1939TP_IDX_ZERO; sduIdxLocal < J1939TP_TXNSDU_NUMBER; sduIdxLocal++ )
    {
        txSduState = &J1939Tp_TxSduState[sduIdxLocal];
        /* N-Sdu is currently being processed in the current channel, ignoring other N-Sdu. */
        if( (J1939Tp_TxSduInfo[sduIdxLocal].txSduOfChannelIdx == txChannelIdx)&&
            (J1939TP_STATE_IDLE != txSduState->State)&&
            (J1939Tp_TxChannel[txChannelIdx].txDa == da)&&
            (J1939Tp_TxChannel[txChannelIdx].txSa == sa) )
        {
            parallelResult = E_NOT_OK;
            break;
        }
    }
    txSduState = &J1939Tp_TxSduState[sduIdx];
    if( E_OK == parallelResult )
#else
    if( J1939TP_STATE_IDLE == txSduState->State )
#endif  /* J1939TP_DTTIME_TX_ENABLED == STD_ON */
    {
        uint8 packetUesd;

        /* TCM_RTS process. */
        txSduState->State = J1939TP_STATE_CMDT_RTS_BUSY;
        txSduState->Aborted = FALSE;
        txSduState->Size = info->SduLength;

        /* SWS_J1939Tp_00165 */
        /* Polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule14.3" Polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
        if( TRUE == J1939Tp_TxChannel[txChannelIdx].txDynamicBlockCalculation )
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            txInfo.SduLength = J1939TP_ZERO;
            txInfo.SduDataPtr = info->SduDataPtr;
            tpResult = PduR_J1939TpCopyTxData(J1939Tp_TxSduInfo[sduIdx].txNSduIdx,
                                              (const PduInfoType*)&txInfo,
                                              NULL_PTR,
                                              (uint32*)&txSduState->DataSize);
            if( BUFREQ_OK == tpResult )
            {
                /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
                uint8 cfgMaxPacket = J1939Tp_TxChannel[txChannelIdx].txMaxPacketsPerBlock;

                if( J1939TP_MAXPACKETPERBLOCK_NOUSED != cfgMaxPacket )
                {
                    /* SWS_J1939Tp_00207. use smaller. */
                    if( cfgMaxPacket < (J1939Tp_Get_Packets(txSduState->DataSize)) )
                    {
                        packetUesd = cfgMaxPacket;
                    }
                    else
                    {
                        packetUesd = (J1939Tp_Get_Packets(txSduState->DataSize));
                    }
                }
                /* SWS_J1939Tp_00208 */
                else
                {
                    packetUesd = (J1939Tp_Get_Packets(txSduState->DataSize));
                }
            }
            else
            {
                packetUesd = (J1939Tp_Get_Packets(txSduState->Size));
            }
        }
        /* SWS_J1939Tp_00209 */
        else
        {
            /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
            uint8 cfgMaxPacket = J1939Tp_TxChannel[txChannelIdx].txMaxPacketsPerBlock;

            /* Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule14.3" Polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
            if( J1939TP_MAXPACKETPERBLOCK_NOUSED != cfgMaxPacket )
            {
                packetUesd = cfgMaxPacket;
            /* Polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            }
            else
            /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                packetUesd = (J1939Tp_Get_Packets(txSduState->Size));
            }
        }

        /* Set sdu state. */
        txSduState->Packets = J1939Tp_Get_Packets(txSduState->Size);
        txSduState->MaxBlock = packetUesd;
        txSduState->Sender = sa;
        txSduState->Receiver = da;
        txSduState->Priority = pri;
        txSduState->Sequence = J1939TP_ONE;

        /* Timeout occurred on transmitter or receiver side while trying to send the next TP.DT or TP.CM frame. */
        txSduState->TimeOut = J1939Tp_GetTime_Tr();

        /* Sent TP.CM_RTS. */
        J1939Tp_CmdtInternalTransmitTpCmRts(sduIdx);
        result = E_OK;
    }

    return result;
}
#endif

/*
********************************************************************************
* Function Name: J1939Tp_CmdtRxMain
*
* Explanation: Main function of the J1939Tp_CmdtRxMain.
*              It is called by J1939Tp_MainFunction.
*
* param: sduIdx: ID of the received I-PDU.
*
* retval: None
********************************************************************************
*/
FUNC(void, J1939TP_CODE) J1939Tp_CmdtRxMain
(
    PduIdType sduIdx
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    J1939Tp_RxSduStateType* rxSduState = &J1939Tp_RxSduState[sduIdx];

    if( TRUE == rxSduState->Aborted )
    {
        if( (J1939TP_STATE_CMDT_CTS == rxSduState->State) || (J1939TP_STATE_CMDT_CTSWAIT == rxSduState->State) ||
            (J1939TP_STATE_CMDT_EOMACK == rxSduState->State) || (J1939TP_STATE_CMDT_ABORT == rxSduState->State) ||
            (J1939TP_STATE_CMDT_DATA_FIRST == rxSduState->State) || (J1939TP_STATE_CMDT_DATA == rxSduState->State) ||
            (J1939TP_STATE_CMDT_CTSRETRY == rxSduState->State) )
        {
            PduR_J1939TpRxIndication(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, E_NOT_OK);

            /* No protection required - transition from uninterruptible state. */
            rxSduState->State = J1939TP_STATE_IDLE;
        }
        else
        {
            /* Do nothing. */
        }
    }
    else if( J1939TP_ZERO == rxSduState->TimeOut )
    {   /* Rx sdu timeout process. */
        J1939Tp_CmdtRxMain_ToProcess(sduIdx);
    }
    else
    {
        --rxSduState->TimeOut;

        switch( rxSduState->State )
        {
            case J1939TP_STATE_CMDT_CTS:
                /* Protected against concurrent Tx abort and concurrent reception of TP.ConnAbort message */
                rxSduState->State = J1939TP_STATE_CMDT_CTS_BUSY;

                J1939Tp_CmdtInternalTransmitTpCmCts(sduIdx);
                break;

            case J1939TP_STATE_CMDT_CTSWAIT:
                /* Protected against concurrent Tx abort and concurrent reception of TP.ConnAbort message */
                rxSduState->State = J1939TP_STATE_CMDT_CTSWAIT_BUSY;

                J1939Tp_CmdtInternalTransmitTpCmCts(sduIdx);
                break;

            case J1939TP_STATE_CMDT_EOMACK:
                /* Protected against concurrent Tx abort and concurrent reception of TP.ConnAbort message */
                rxSduState->State = J1939TP_STATE_CMDT_EOMACK_BUSY;

                J1939Tp_CmdtInternalTransmitTpCmEOMAck(sduIdx);
                break;

            case J1939TP_STATE_CMDT_ABORT:
                /* Protected against concurrent Tx abort and concurrent reception of TP.ConnAbort message */
                rxSduState->State = J1939TP_STATE_CMDT_ABORT_BUSY;

                J1939Tp_CmdtInternalTransmitTpAbortRx(sduIdx);
                break;

            case J1939TP_STATE_CMDT_CTSRETRY:
                rxSduState->State = J1939TP_STATE_CMDT_CTSRETRY_BUSY;

                J1939Tp_Retry_InCMDT_Transmission(sduIdx, rxSduState->Sequence, J1939Tp_RxSduInfo[sduIdx].rxPgPgn);
                break;
            default:
               /* Do Nothing. */
               break;
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtRxMain_ToProcess
*
* Explanation: CMDT rx timeout process.
*
*
* param: sduIdx: ID of the received I-PDU.
*
* retval: None
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtRxMain_ToProcess
(
    PduIdType sduIdx
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    J1939Tp_RxSduStateType* rxSduState = &J1939Tp_RxSduState[sduIdx];
    uint8 errorId = J1939TP_E_NO_ERROR;

    /* Polyspace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_J1939Tp_SwitchFormat" */
    switch( rxSduState->State )
    {
        case J1939TP_STATE_CMDT_CTS:
        case J1939TP_STATE_CMDT_EOMACK:
        case J1939TP_STATE_CMDT_ABORT:
        case J1939TP_STATE_CMDT_CTSRETRY:
          /* Timeout occurred on transmitter or receiver side while trying to send the next TP.DT or TP.CM frame. */
          errorId = J1939TP_E_TIMEOUT_TR;
          break;
        case J1939TP_STATE_CMDT_CTSWAIT:
          /* Timeout occurred on receiver side while trying to send the next TP.CM/CTS frame after a TP.CM/CTS(0) frame. */
          errorId = J1939TP_E_TIMEOUT_TH;
          break;
        case J1939TP_STATE_CMDT_DATA_FIRST:
          /* Timeout occurred on receiver side after transmission of a TP.CM/CTS frame. */
          errorId = J1939TP_E_TIMEOUT_T2;
          break;
        case J1939TP_STATE_CMDT_DATA:
          /* Timeout occurred on receiver side after reception of an intermediate TP.DT frame of a block. */
          errorId = J1939TP_E_TIMEOUT_T1;
          break;
        default:
          /* Do Nothing. */
          break;
    }

    J1939Tp_ReportRuntimeError(J1939TP_SID_MAINFUNCTION, errorId);

    if( J1939TP_STATE_CMDT_ABORT == rxSduState->State )
    {
        /* Notifty PduR rx E_NOT_OK. */
        PduR_J1939TpRxIndication(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, E_NOT_OK);

        rxSduState->State = J1939TP_STATE_IDLE;
    }
    else if( (J1939TP_STATE_CMDT_CTS == rxSduState->State) || (J1939TP_STATE_CMDT_CTSWAIT == rxSduState->State) ||
             (J1939TP_STATE_CMDT_DATA_FIRST == rxSduState->State) || (J1939TP_STATE_CMDT_DATA == rxSduState->State) ||
             (J1939TP_STATE_CMDT_EOMACK == rxSduState->State) || (J1939TP_STATE_CMDT_CTSRETRY == rxSduState->State) )
    {
        rxSduState->RetryState = J1939TP_DONT_RETRY;

        rxSduState->AbortReason = J1939TP_CAR_TIMEOUT;
        rxSduState->TimeOut = J1939Tp_GetTime_Tr();
        /* Protected against concurrent Tx abort and concurrent reception of TP.ConnAbort or TP.DT message */
        rxSduState->State = J1939TP_STATE_CMDT_ABORT_BUSY;
        J1939Tp_CmdtInternalTransmitTpAbortRx(sduIdx);
    }
    else
    {
        /* Do nothing. */
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtTxMain_ToProcess
*
* Explanation: CMDT tx timeout process.
*
* param: sduIdx: ID of the received I-PDU.
*
* retval: None
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtTxMain_ToProcess
(
    PduIdType sduIdx
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    J1939Tp_TxSduStateType* txSduState = &J1939Tp_TxSduState[sduIdx];

#if (J1939TP_RUNTIME_ERROR_REPORT == STD_ON)
    uint8 errorId = J1939TP_E_NO_ERROR;

    switch( txSduState->State )
    {
        case J1939TP_STATE_CMDT_CTS:
            errorId = J1939TP_E_TIMEOUT_T3;
            break;
        case J1939TP_STATE_CMDT_CTSWAIT:
            errorId = J1939TP_E_TIMEOUT_T4;
            break;
        case J1939TP_STATE_CMDT_RTS:
        case J1939TP_STATE_CMDT_ABORT:
        case J1939TP_STATE_CMDT_DATA:
            errorId = J1939TP_E_TIMEOUT_TR;
            break;
        default:
            break;
    }

    J1939Tp_ReportRuntimeError(J1939TP_SID_MAINFUNCTION, errorId);

    J1939TP_DUMMY_STATEMENT(errorId);
#endif

    if( (J1939TP_STATE_CMDT_RTS == txSduState->State) ||
        (J1939TP_STATE_CMDT_ABORT == txSduState->State) )
    {
        PduR_J1939TpTxConfirmation(J1939Tp_TxSduInfo[sduIdx].txNSduIdx, E_NOT_OK);

        /* Abort transmit. */
        txSduState->State = J1939TP_STATE_IDLE;
    }
    else if( (J1939TP_STATE_CMDT_CTS == txSduState->State) ||
             (J1939TP_STATE_CMDT_CTSWAIT == txSduState->State) ||
             (J1939TP_STATE_CMDT_DATA == txSduState->State) )
    {
        txSduState->RetryState = J1939TP_DONT_RETRY;

        txSduState->AbortReason = J1939TP_CAR_TIMEOUT;
        txSduState->TimeOut = J1939Tp_GetTime_Tr();
        /* Protected against concurrent Tx abort and concurrent reception of TP.ConnAbort */
        txSduState->State = J1939TP_STATE_CMDT_ABORT_BUSY;
        J1939Tp_CmdtInternalTransmitTpAbortTx(sduIdx);
    }
    else
    {
        /* Do nothing. */
    }
}
/*
********************************************************************************
* Function Name: J1939Tp_CmdtInternalTransmitTpAbortRx
*
* Explanation: This functions Transmit Abort rx.
*
* param: sduIdx: ID of the Rx SDU.
*
* retval: None
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtInternalTransmitTpAbortRx
(
    PduIdType sduIdx
)
{
    boolean flag = FALSE;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 channelIdx = J1939Tp_RxSduInfo[sduIdx].rxSduOfChannelIdx;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Dir4.5"  Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    PduIdType pduIdx = J1939Tp_RxChannel[channelIdx].txConfitmIdx;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint32 pgn = J1939Tp_RxSduInfo[sduIdx].rxPgPgn;
    uint8 data[J1939TP_NPDU_LENGTH];
    PduInfoType pdu;
    Std_ReturnType result;

    J1939Tp_TxPduStateType* pduState = NULL_PTR;
    J1939Tp_RxSduStateType* rxSduState = NULL_PTR;

    if( (TRUE == J1939Tp_CmdtChkTxPduScope(pduIdx)) &&
        (sduIdx < J1939TP_RXNSDU_NUMBER) )
    {
        pduState = &J1939Tp_TxPduState[pduIdx];
        rxSduState = &J1939Tp_RxSduState[sduIdx];
        flag = TRUE;
    }

     if( TRUE == flag )
    {
        if( FALSE == pduState->Locked )
        {
            pduState->CurrentNSduType = J1939TP_NSDU_CMDT_RX;
            pduState->CurrentNSduId = sduIdx;
            pduState->ConfTimeout = J1939Tp_GetTxConfTimeout();
            /* protected against concurrent access to the same TP.CM N-PDU */
            pduState->Locked = TRUE;

            data[J1939TP_TPCM_CB] = (uint8)J1939TP_CB_ABORT;
            data[J1939TP_TPCM_CAR] = (uint8) rxSduState->AbortReason;
            data[J1939TP_TPCM_RES3] = J1939TP_SNA_VALUE;
            data[J1939TP_TPCM_RES4] = J1939TP_SNA_VALUE;
            data[J1939TP_TPCM_RES5] = J1939TP_SNA_VALUE;
            data[J1939TP_TPCM_PGN_LO] = J1939Tp_Make_PGN_LO(pgn);
            data[J1939TP_TPCM_PGN_MD] = J1939Tp_Make_PGN_MD(pgn);
            data[J1939TP_TPCM_PGN_HI] = J1939Tp_Make_PGN_HI(pgn);
            data[J1939TP_NPDU_SA_POS] = rxSduState->Receiver;
            data[J1939TP_NPDU_DA_POS] = rxSduState->Sender;
            data[J1939TP_NPDU_PRI_POS] = rxSduState->Priority;

            pdu.SduDataPtr = data;
            pdu.SduLength = J1939TP_NPDU_LENGTH;

            /* No protection required - transition from uninterruptible state */
            rxSduState->State = J1939TP_STATE_CMDT_ABORT_CONF;
            result = CanIf_Transmit(J1939Tp_GetPduIdOfTxPdu(pduIdx), &pdu);
            if( result != E_OK )
            {
                /* No protection required - no further actions related to the locked state */
                pduState->Locked = FALSE;

                /* Protected against late Tx confirmation */
                rxSduState->State = J1939TP_STATE_CMDT_ABORT;
            }
        }
        else
        {
            /* No protection required - transition from uninterruptible state */
            rxSduState->State = J1939TP_STATE_CMDT_ABORT;
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtInternalTransmitTpCmCts
*
* Explanation: This functions Transmit TpCm Cts.
*
* param: sduIdx: ID of the Rx SDU.
*
* retval: None
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtInternalTransmitTpCmCts
(
    PduIdType sduIdx
)
{
    boolean flag = FALSE;
    BufReq_ReturnType tpResult = BUFREQ_OK;
    Std_ReturnType result;

    uint8 maxblock = J1939TP_ZERO;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 channelIdx = J1939Tp_RxSduInfo[sduIdx].rxSduOfChannelIdx;

    uint16 blocksize = J1939TP_ZERO;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Dir4.5" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 pduIdx = J1939Tp_RxChannel[channelIdx].txConfitmIdx;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint32 pgn = J1939Tp_RxSduInfo[sduIdx].rxPgPgn;

    PduInfoType pdu;
    uint8 data[J1939TP_NPDU_LENGTH] = {J1939TP_ZERO};

    J1939Tp_TxPduStateType* pduState = NULL_PTR;
    J1939Tp_RxSduStateType* rxSduState = NULL_PTR;

    if( (TRUE == J1939Tp_CmdtChkTxPduScope(pduIdx)) &&
        (sduIdx < J1939TP_RXNSDU_NUMBER) )
    {
        pduState = &J1939Tp_TxPduState[pduIdx];
        rxSduState = &J1939Tp_RxSduState[sduIdx];
        flag = TRUE;
    }

    if( TRUE == flag )
    {
         uint8 block =J1939Tp_Get_Packets(rxSduState->BufSize);

        if( FALSE == pduState->Locked )
        {
            pduState->CurrentNSduType = J1939TP_NSDU_CMDT_RX;
            pduState->CurrentNSduId = sduIdx;
            pduState->ConfTimeout = J1939Tp_GetTxConfTimeout();

            /* Protected against concurrent access to the same TP.CM N-PDU. */
            pduState->Locked = TRUE;

            maxblock = ((uint8)rxSduState->Packets) - rxSduState->Sequence;
            if( block > maxblock )
            {
                block = maxblock;
            }

            if( block == maxblock ) /* last block */
            {
                blocksize = (uint16)(rxSduState->Size - ((uint32)(rxSduState->Sequence) * J1939TP_TPDT_DATA_SIZE));
            }
            else
            {
                blocksize = (uint16)block * J1939TP_TPDT_DATA_SIZE;
            }

            if( (rxSduState->BufSize < blocksize) || (J1939TP_ZERO == rxSduState->BufSize) )
            {
                pdu.SduLength = J1939TP_ZERO;
                pdu.SduDataPtr = NULL_PTR;

                tpResult = PduR_J1939TpCopyRxData(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, &pdu, (uint32*)&rxSduState->BufSize);

            }

            if( BUFREQ_OK == tpResult )
            {
                if( (rxSduState->BufSize >= blocksize) || (rxSduState->TimeOut >= J1939TP_ONE) )
                {

                    if( (rxSduState->BufSize >= blocksize) && (rxSduState->BufSize != J1939TP_ZERO) )
                    {
                        rxSduState->NextBlock = rxSduState->Sequence + block;
                        data[J1939TP_TPCM_NOP] = block;
                        data[J1939TP_TPCM_NPN] = rxSduState->Sequence + J1939TP_ONE;
                    }
                    else
                    {
                        data[J1939TP_TPCM_NOP] = J1939TP_CTS_WAIT;
                        data[J1939TP_TPCM_NPN] = J1939TP_SNA_VALUE;
                    }

                    data[J1939TP_TPCM_CB] = (uint8)J1939TP_CB_CTS;
                    data[J1939TP_TPCM_RES4] = J1939TP_SNA_VALUE;
                    data[J1939TP_TPCM_RES5] = J1939TP_SNA_VALUE;
                    data[J1939TP_TPCM_PGN_LO] = J1939Tp_Make_PGN_LO(pgn);
                    data[J1939TP_TPCM_PGN_MD] = J1939Tp_Make_PGN_MD(pgn);
                    data[J1939TP_TPCM_PGN_HI] = J1939Tp_Make_PGN_HI(pgn);
                    data[J1939TP_NPDU_SA_POS] = rxSduState->Receiver;
                    data[J1939TP_NPDU_DA_POS] = rxSduState->Sender;
                    data[J1939TP_NPDU_PRI_POS] = rxSduState->Priority;

                    pdu.SduDataPtr = data;
                    pdu.SduLength = J1939TP_NPDU_LENGTH;

                    if( (rxSduState->BufSize >= blocksize) && (rxSduState->BufSize != J1939TP_ZERO) )
                    {
                        /* No protection required - transition from uninterruptible state. */
                        rxSduState->State = J1939TP_STATE_CMDT_CTS_CONF;
                    }
                    else
                    {
                        /* No protection required - transition from uninterruptible state. */
                        rxSduState->State = J1939TP_STATE_CMDT_CTSWAIT_CONF;
                    }

                    result = CanIf_Transmit(J1939Tp_GetPduIdOfTxPdu(pduIdx), &pdu);

                    if( result != E_OK )
                    {
                        if( J1939TP_STATE_CMDT_CTSWAIT_CONF == rxSduState->State )
                        {
                            /* No protection required - no further actions related to the locked state. */
                            pduState->Locked = FALSE;

                            /* protected against late Tx confirmation */
                            rxSduState->State = J1939TP_STATE_CMDT_CTSWAIT;
                        }
                        /* J1939TP_STATE_CMDT_CTS_CONF == rxSduState->State */
                        else
                        {
                            /* No protection required - no further actions related to the locked state. */
                            pduState->Locked = FALSE;

                            /* Protected against late Tx confirmation. */
                            rxSduState->State = J1939TP_STATE_CMDT_CTS;
                        }
                    }
                }
                else
                {
                    /* No protection required - no further actions related to the locked state. */
                    pduState->Locked = FALSE;

                    if( J1939TP_STATE_CMDT_CTSWAIT_BUSY == rxSduState->State )
                    {
                        /* no protection required - transition from uninterruptible state. */
                        rxSduState->State = J1939TP_STATE_CMDT_CTSWAIT;
                    }
                    else
                    {
                        /* no protection required - transition from uninterruptible state. */
                        rxSduState->State = J1939TP_STATE_CMDT_CTS;
                    }
                }
            }
            else
            {
                /* The J1939Tp module shall abort the reception.  SWS_J1939Tp_00040 */
                pduState->Locked = FALSE;
                rxSduState->AbortReason = J1939TP_CAR_RESOURCES;
                rxSduState->TimeOut = J1939Tp_GetTime_Tr();
                /* No protection required - transition from uninterruptible state. */
                rxSduState->State = J1939TP_STATE_CMDT_ABORT_BUSY;

                J1939Tp_CmdtInternalTransmitTpAbortRx(sduIdx);

            }
        }
        else
        {
            if( J1939TP_STATE_CMDT_CTSWAIT_BUSY == rxSduState->State )
            {
                /* No protection required - transition from uninterruptible state. */
                rxSduState->State = J1939TP_STATE_CMDT_CTSWAIT;
            }
            else
            {
                /* No protection required - transition from uninterruptible state. */
                rxSduState->State = J1939TP_STATE_CMDT_CTS;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtInternalTransmitTpCmEOMAck
*
* Explanation: This functions Transmit TpCm EOMAck.
*
* param: sduIdx: ID of the Rx SDU.
*
* retval: None
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtInternalTransmitTpCmEOMAck
(
    PduIdType sduIdx
)
{
    boolean flag = FALSE;
    PduInfoType pdu;
    Std_ReturnType result;

    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 channelIdx = J1939Tp_RxSduInfo[sduIdx].rxSduOfChannelIdx;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 txPduIdx = J1939Tp_RxChannel[channelIdx].txConfitmIdx;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint32 pgn = J1939Tp_RxSduInfo[sduIdx].rxPgPgn;
    uint8 data[J1939TP_NPDU_LENGTH];

    J1939Tp_TxPduStateType* pduState = NULL_PTR;
    J1939Tp_RxSduStateType* rxSduState = NULL_PTR;

    if( (TRUE == J1939Tp_CmdtChkTxPduScope(txPduIdx)) &&
        (sduIdx < J1939TP_RXNSDU_NUMBER) )
    {
        pduState = &J1939Tp_TxPduState[txPduIdx];
        rxSduState = &J1939Tp_RxSduState[sduIdx];
        flag = TRUE;
    }

    if( TRUE == flag )
    {
        if( FALSE == pduState->Locked )
        {
            pduState->CurrentNSduType = J1939TP_NSDU_CMDT_RX;
            pduState->CurrentNSduId = sduIdx;
            pduState->ConfTimeout = J1939Tp_GetTxConfTimeout();
            pduState->Locked = TRUE;

            {
                data[J1939TP_TPCM_CB] = (uint8)J1939TP_CB_EOMACK;
                data[J1939TP_TPCM_TMS_LO] = J1939Tp_Make_TMS_LO(rxSduState->Size);
                data[J1939TP_TPCM_TMS_HI] = J1939Tp_Make_TMS_HI(rxSduState->Size);
                data[J1939TP_TPCM_TNOP] = (uint8) rxSduState->Packets;
                data[J1939TP_TPCM_RES5] = J1939TP_SNA_VALUE;
                data[J1939TP_TPCM_PGN_LO] = J1939Tp_Make_PGN_LO(pgn);
                data[J1939TP_TPCM_PGN_MD] = J1939Tp_Make_PGN_MD(pgn);
                data[J1939TP_TPCM_PGN_HI] = J1939Tp_Make_PGN_HI(pgn);
                data[J1939TP_NPDU_SA_POS] = rxSduState->Receiver;
                data[J1939TP_NPDU_DA_POS] = rxSduState->Sender;
                data[J1939TP_NPDU_PRI_POS] = rxSduState->Priority;

                pdu.SduDataPtr = data;
                pdu.SduLength = J1939TP_NPDU_LENGTH;

                /* No protection required - transition from uninterruptible state */
                rxSduState->State = J1939TP_STATE_CMDT_EOMACK_CONF;
                result = CanIf_Transmit(J1939Tp_TxPdu[txPduIdx].PduIdOfTxPdu, &pdu);

                if( result != E_OK )
                {
                    /* No protection required - no further actions related to the locked state */
                    pduState->Locked = FALSE;

                    /* Protected against late Tx confirmation. */
                    rxSduState->State = J1939TP_STATE_CMDT_EOMACK;
                }
            }
        }
        else
        {
            /* No protection required - transition from uninterruptible state */
            rxSduState->State = J1939TP_STATE_CMDT_EOMACK;
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtInternalRxIndication_ReceiveTpCmEomack
*
* Explanation: This functions process receive tpcm ack
*
* param: sduIdx: ID of the received I-PDU.
*
* retval: None
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtRxIndication_ReceiveTpCmEomack
(
    PduIdType sduIdx
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    J1939Tp_TxSduStateType* txSduState = &J1939Tp_TxSduState[sduIdx];

    if((J1939TP_STATE_CMDT_CTS == txSduState->State)
        || (J1939TP_STATE_CMDT_CTSWAIT == txSduState->State))
    {
        /* To notify that the N-SDU transfer is successfully processed. SWS_J1939Tp_00119. */
        PduR_J1939TpTxConfirmation((J1939Tp_TxSduInfo[sduIdx].txNSduIdx), E_OK);

        /* Set state idle. */
        txSduState->State = J1939TP_STATE_IDLE;
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtInternalRxIndication_ReceiveTpAbortTx
*
* Explanation: This functions process receive tpcm ack.
*
* param: sduIdx: ID of the received I-PDU.
*
* retval: None
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtRxIndication_ReceiveTpAbortTx
(
    PduIdType sduIdx
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    J1939Tp_TxSduStateType* txSduState = &J1939Tp_TxSduState[sduIdx];

    /* Tx confirm not ok. */
    PduR_J1939TpTxConfirmation((J1939Tp_TxSduInfo[sduIdx].txNSduIdx), E_NOT_OK);
    /* Set state idle. */
    txSduState->State = J1939TP_STATE_IDLE;
    txSduState->RetryState = J1939TP_DONT_RETRY;
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtInternalRxIndication_ReceiveTpCmRts
*
* Explanation: This functions Receive TpCm Rts.
*
* param: sduIdx: ID of the Rx SDU.
*        info: Contains the length (SduLength) of the received I-PDU and a pointer
*              to a buffer (SduDataPtr) containing the I-PDU.
*        sa: source address.
*        da: destination address.
*        rxSduState: rx sdu state.
* retval: None
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtInternalRxIndication_ReceiveTpCmRts
(
    PduIdType sduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    uint8 sa,
    uint8 da,
    uint16 size,
    J1939Tp_RxSduStateType* rxSduState
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint8 packets = (uint8) J1939Tp_Get_Packets(size);
    PduInfoType addrInfo;
    BufReq_ReturnType tpResult;

    if( size > J1939Tp_RxSduInfo[sduIdx].SduLength )
    {
        /* Error Size. */
        rxSduState->State = J1939TP_STATE_IDLE;
    }
    else
    {
        rxSduState->Size = size;
        rxSduState->Packets = packets;
        rxSduState->Sender = sa;
        rxSduState->Receiver = da;
        rxSduState->Priority = J1939Tp_MDL_Get_PRI(info->SduDataPtr[J1939TP_NPDU_PRI_POS]);

        addrInfo.SduLength = J1939TP_ZERO;
        addrInfo.SduDataPtr = &(info->SduDataPtr[J1939TP_NPDU_MDL_POS]);

        tpResult = J1939Tp_StartOfReception_CmdtProcess(sduIdx,
                                                        &addrInfo,
                                                        (PduLengthType) size,
                                                        rxSduState);

                                       /* SWS_J1939Tp_00040 */
        if( (BUFREQ_OK == tpResult) /*&& (rxSduState->BufSize >= pduLength ) */)
        {
            rxSduState->Sequence = J1939TP_ZERO;
            rxSduState->TimeOut = J1939Tp_GetTime_Tr();

            J1939Tp_CmdtInternalTransmitTpCmCts(sduIdx);
        }
        else
        {
            rxSduState->AbortReason = J1939TP_CAR_CONNECTION;
            rxSduState->TimeOut = J1939Tp_GetTime_Tr();
            /* The J1939Tp module shall abort the reception. SWS_J1939Tp_00040 */
            J1939Tp_CmdtInternalTransmitTpAbortRx(sduIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtInternalRxIndication_ReceiveTpCmRts
*
* Explanation: This functions Receive TpCm Rts.
*
* param: sduIdx: ID of the Rx SDU.
*        info: Contains the length (SduLength) of the received I-PDU and a pointer
*              to a buffer (SduDataPtr) containing the I-PDU.
*        rxSduState: rx sdu state.
* retval: None
********************************************************************************
*/
static FUNC(BufReq_ReturnType, J1939TP_CODE) J1939Tp_StartOfReception_CmdtProcess
(
    PduIdType sduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    uint32 size,
    J1939Tp_RxSduStateType* rxSduState
)
{
    BufReq_ReturnType tpResult;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 channelIdx = J1939Tp_RxSduInfo[sduIdx].rxSduOfChannelIdx;

    tpResult = PduR_J1939TpStartOfReception(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx,
                                            info,
                                            (PduLengthType) size,
                                            (uint32*)&rxSduState->BufSize);

    /* SWS_J1939Tp_00213 */
    /* Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule14.3" Polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
    if( FALSE == J1939Tp_RxChannel[channelIdx].rxDynamicBlockCalculation )
    {
        /* Use J1939TpRxPacketsPerBlock to calculate the number of packets. */
        rxSduState->BufSize = (uint32)J1939Tp_RxChannel[channelIdx].rxPacketsPerBlock * J1939TP_TPDT_DATA_SIZE;
    /* Polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    }
    /* SWS_J1939Tp_00210 */
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    else if( J1939TP_MAXPACKETPERBLOCK_NOUSED != J1939Tp_RxChannel[channelIdx].rxPacketsPerBlock )
    {
        /* Use the lower value. */
        if( (J1939Tp_Get_Packets(rxSduState->BufSize)) > J1939Tp_RxChannel[channelIdx].rxPacketsPerBlock )
        {
            rxSduState->BufSize = (uint32)J1939Tp_RxChannel[channelIdx].rxPacketsPerBlock * J1939TP_TPDT_DATA_SIZE;
        }
    }
    /* SWS_J1939Tp_00211. Use the value returned by PduR_J1939TpStartOfReception. */
    else
    {
        /* Do nothing. */
    }

    return tpResult;
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtInternalRxIndication_ReceiveTpCmCts
*
* Explanation: This functions process receive tpcm cts
*
* param: sduIdx: ID of the received I-PDU.
*                info : Contains the length (SduLength) of the received I-PDU and
*                       a pointer to a buffer (SduDataPtr) containing the I-PDU.
* retval: None
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtRxIndication_ReceiveTpCmCts
(
    PduIdType sduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info
)
{
    uint8 maxblock = J1939TP_ZERO;
    uint8 block = J1939TP_ZERO;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 channelIdx = J1939Tp_TxSduInfo[sduIdx].txSduOfChannelIdx;

    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    J1939Tp_TxSduStateType* txSduState = &J1939Tp_TxSduState[sduIdx];

    if( (J1939TP_STATE_CMDT_CTS == txSduState->State)
        || (J1939TP_STATE_CMDT_CTSWAIT == txSduState->State) )
    {
        /* Set sdu state cts busy. */
        txSduState->State = J1939TP_STATE_CMDT_CTS_BUSY;

        /* Number of data can be send. */
        block = info->SduDataPtr[J1939TP_TPCM_NOP];

        if( J1939TP_CTS_WAIT == block )
        {   /* Timeout occurred on transmitter side after reception of a TP.CM/CTS(0) frame. */
            txSduState->TimeOut = J1939Tp_GetTime_T4();         /* SAE J1939-21 define this time is 1050ms. */
            /* Set sdu state cts wait. */
            txSduState->State = J1939TP_STATE_CMDT_CTSWAIT;
        }
        else
        {
            /* Number of data will be send equal sequence. */
            if( info->SduDataPtr[J1939TP_TPCM_NPN] == txSduState->Sequence )
            {
                maxblock = (txSduState->Packets) - (txSduState->Sequence - J1939TP_ONE);

                if( block > maxblock )
                {
                    block = maxblock;
                }

                txSduState->NextBlock = txSduState->Sequence + block;

                /* Tpdt timeout 200ms. */
                txSduState->TimeOut = J1939Tp_GetTime_Tr();     /* SAE J1939-21 define this time is 200ms. */

                /* Sent tpdt. */
#if( J1939TP_DTTIME_TX_ENABLED == STD_ON )
                    /* Set the status to J1939TP_STATE_CMDT_DATA. */
                    txSduState->State = J1939TP_STATE_CMDT_DATA;
                    /* Set TP.DT sending time. */
                    txSduState->TpDtCount = J1939Tp_GetTxDtTime();
#else
                    txSduState->State = J1939TP_STATE_CMDT_DATA_BUSY;
                    J1939Tp_CmdtInternalTransmitTpDt(sduIdx);
#endif  /* J1939TP_DTTIME_TX_ENABLED == STD_ON */

            }
            else
            {
                /* SWS_J1939Tp_00194 */
                /* Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule14.3" Polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
                if( FALSE == J1939Tp_TxChannel[channelIdx].txRetrySupport )
                {
                    /* Abort with reason SNA (no reason specified for TP.CTS requesting a sequence number that cannot be delivered). */
                    txSduState->AbortReason = J1939TP_CAR_OTHER;
                    txSduState->TimeOut = J1939Tp_GetTime_Tr();     /* SAE J1939-21 define this time is 200ms. */

                    /* SWS_J1939Tp_00223. */
                    J1939Tp_CmdtInternalTransmitTpAbortTx(sduIdx);
                /* Polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                }
                /* SWS_J1939Tp_00194 */
                else
                /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    /* Tpdt timeout 200ms.  */
                    txSduState->TimeOut = J1939Tp_GetTime_Tr();     /* SAE J1939-21 define this time is 200ms. */
                    if( txSduState->Sequence > txSduState->Packets )
                    {
                        txSduState->ByteOffset = (((uint32)(info->SduDataPtr[J1939TP_TPCM_NOP]) - J1939TP_ONE) * J1939TP_TPDT_DATA_SIZE) +
                            (txSduState->Size - (((uint32)(txSduState->Sequence) - J1939TP_TWO) * (uint32)J1939TP_TPDT_DATA_SIZE));
                    }
                    else
                    {
                        txSduState->ByteOffset = (uint32)((uint32)(info->SduDataPtr[J1939TP_TPCM_NOP]) * J1939TP_TPDT_DATA_SIZE);
                    }
                    txSduState->Sequence = info->SduDataPtr[J1939TP_TPCM_NPN];
                    txSduState->RetryState = J1939TP_NEED_RETRY;
                    /* Sent last correct tpdt. */
#if( J1939TP_DTTIME_TX_ENABLED == STD_ON )
                    /* Set the status to J1939TP_STATE_CMDT_DATA. */
                    txSduState->State = J1939TP_STATE_CMDT_DATA;
                    /* Set TP.DT sending time. */
                    txSduState->TpDtCount = J1939Tp_GetTxDtTime();
#else
                    txSduState->State = J1939TP_STATE_CMDT_DATA_BUSY;
                    J1939Tp_CmdtInternalTransmitTpDt(sduIdx);
#endif  /* J1939TP_DTTIME_TX_ENABLED == STD_ON */
                }
            }
        }
    }
    else
    {   /* SWS_J1939Tp_00224 */
        if( (J1939TP_STATE_CMDT_DATA == txSduState->State) &&
            (FALSE == J1939Tp_TxChannel[channelIdx].txRetrySupport)
        )
        {
            /* Set sdu state cts busy. */
            txSduState->State = J1939TP_STATE_CMDT_CTS_BUSY;

            /* Abort with reason 4 (CTS messages received when data transfer is in progress). */
            txSduState->AbortReason = J1939TP_CAR_UNTIMELY_CTS;
            txSduState->TimeOut = J1939Tp_GetTime_Tr();         /* SAE J1939-21 define this time is 200ms. */

            /* Send abort. */
            J1939Tp_CmdtInternalTransmitTpAbortTx(sduIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtRxIndication
*
* Explanation: This functions sends the Rx indication.
*
* param: pduIdx: ID of the received I-PDU.
*        info: Contains the length (SduLength) of the received I-PDU and a pointer
*              to a buffer (SduDataPtr) containing the I-PDU.
*        sa: source address.
*        da: destination address.
* retval: None
********************************************************************************
*/
FUNC(void, J1939TP_CODE) J1939Tp_CmdtRxIndication
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Dir4.5" */
    PduIdType pduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    uint8 pduType,
    uint8 sa,
    uint8 da
)
{
    if( J1939TP_NPDU_LENGTH == info->SduLength )
    {
        uint16 sduIdx;
        if( J1939TP_BROADCAST_ADDRESS == da )
        {
            J1939Tp_ReportRuntimeError(J1939TP_SID_RXINDICATION, J1939TP_E_INVALID_PGN);
        }
        else
        {
            /* Polyspace +1 MISRA-C3:10.5 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
            J1939Tp_ControlByteType cb = (J1939Tp_ControlByteType)info->SduDataPtr[J1939TP_TPCM_CB];  /* PRQA S 4342 */ /* NSCA_QAC_J1939Tp_Rule10.5 */

            /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
            uint32 pgn = J1939Tp_Get_PGN(info->SduDataPtr[J1939TP_TPCM_PGN_LO],
                                         info->SduDataPtr[J1939TP_TPCM_PGN_MD],
                                         info->SduDataPtr[J1939TP_TPCM_PGN_HI]);

            /* Judge Pdu type. */
            if( J1939TP_TPCM_PDUTYPEOFTXPDU == pduType )
            {
                if( !J1939Tp_PGN_Valid(pgn) )
                {
                    J1939Tp_ReportRuntimeError(J1939TP_SID_RXINDICATION, J1939TP_E_INVALID_PGN);
                }
                else
                {
                    switch( cb )
                    {
                        case J1939TP_CB_RTS:
                        {
                            /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
                            uint16 size = J1939Tp_Get_TMS(info->SduDataPtr[J1939TP_TPCM_TMS_LO],
                                                          info->SduDataPtr[J1939TP_TPCM_TMS_HI]);
                            J1939Tp_RxSduStateType* rxSduState;

                            if( size > J1939TP_MAX_LENGTH )
                            {
                                J1939Tp_ReportRuntimeError(J1939TP_SID_RXINDICATION, J1939TP_E_INVALID_TMS);
                            }
                            else
                            {
                                sduIdx = J1939Tp_CmdtRxIndication_RtsGetSduIdx(sa, da, pgn);
                                if( J1939TP_FINDSDUIDX_ERROR != sduIdx )
                                {
                                    rxSduState = &J1939Tp_RxSduState[sduIdx];
                                    J1939Tp_CmdtInternalRxIndication_ReceiveTpCmRts(sduIdx, info, sa, da, size, rxSduState);
                                }
                            }
                        }
                           break;
                        case J1939TP_CB_CTS:
                        {
                            sduIdx = J1939Tp_CmdtRxIndication_GetTxSduIdx(sa, da, pgn);
                            if( J1939TP_FINDSDUIDX_ERROR != sduIdx )
                            {
                                J1939Tp_CmdtRxIndication_ReceiveTpCmCts(sduIdx, info);
                            }
                        }
                            break;
                        case J1939TP_CB_EOMACK:
                        {
                            sduIdx = J1939Tp_CmdtRxIndication_GetTxSduIdx(sa, da, pgn);
                            if( J1939TP_FINDSDUIDX_ERROR != sduIdx )
                            {
                                J1939Tp_CmdtRxIndication_ReceiveTpCmEomack(sduIdx);
                            }
                        }
                            break;
                        case J1939TP_CB_ABORT:
                        {
                            sduIdx = J1939Tp_CmdtRxIndication_GetTxSduIdx(sa, da, pgn);
                            if( J1939TP_FINDSDUIDX_ERROR != sduIdx )
                            {
                                J1939Tp_CmdtRxIndication_ReceiveTpAbortTx(sduIdx);
                            }
                            else
                            {
                                sduIdx = J1939Tp_CmdtRxIndication_GetRxSduIdx(sa, da, pgn);
                                if( J1939TP_FINDSDUIDX_ERROR != sduIdx )
                                {
                                    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
                                    J1939Tp_RxSduStateType* rxSduState = &J1939Tp_RxSduState[sduIdx];
                                    J1939Tp_CmdtRxIndication_ReceiveTpAbortRx(sduIdx, rxSduState);
                                }
                            }
                        }
                            break;
                        default:
                            /* Do Nothing. */
                            break;
                    }
                }
            }
            else
            /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                J1939Tp_RxSduStateType* rxSduState;
                sduIdx = J1939Tp_CmdtRxIndication_GetRxSduIdx(sa, da, pgn);
                if( J1939TP_FINDSDUIDX_ERROR != sduIdx )
                {
                    rxSduState = &J1939Tp_RxSduState[sduIdx];
                    J1939Tp_CmdtInternalRxIndication_ReceiveTpDt(sduIdx, info, rxSduState);
                }
            }
        }
    }
    J1939TP_DUMMY_STATEMENT(pduIdx);
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtRxIndication_GetTxSduIdx
*
* Explanation: Get tx sdu idx.
*
* param: channelIdx: Tx channel index.
*        pgn: Tx sdu pgn.
* retval: netWork: Find sduIdx.
********************************************************************************
*/
static FUNC(uint16, J1939TP_CODE) J1939Tp_CmdtRxIndication_GetTxSduIdx
(
    uint8 sa,
    uint8 da,
    uint32 pgn
)
{
    boolean flag = FALSE;
    uint16 channelIdx;
    uint16 netWork = J1939TP_FINDSDUIDX_ERROR;
    uint16 sduIdx = J1939TP_FINDSDUIDX_ERROR;
    J1939Tp_TxSduStateType* pduState = NULL_PTR;

    for( channelIdx = J1939TP_ZERO; channelIdx < J1939TP_TXCHANNEL_NUMBER; channelIdx++  )
    {
        /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
        uint16 sduStartIdx = J1939Tp_TxChannel[channelIdx].startOfTxSduIdx;
        /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
        uint16 sduEndIdx = J1939Tp_TxChannel[channelIdx].endOfTxSduIdx;
        for( sduIdx = sduStartIdx; sduIdx < sduEndIdx; sduIdx++ )
        {
            pduState = &J1939Tp_TxSduState[sduIdx];

            if( (((uint32)(pduState->State) & (uint32)J1939TP_STATEMASK_CMDT) != (uint32)J1939TP_STATE_IDLE) &&
                (pduState->Receiver == sa) &&
                (pduState->Sender == da) )
            {
                if( pgn == J1939Tp_TxSduInfo[sduIdx].txPgPgn )
                {
                    flag = TRUE;
                    break;
                }
            }
        }

        if( TRUE == flag )
        {
            netWork = sduIdx;
            break;
        }
    }

    return netWork;
}


/*
********************************************************************************
* Function Name: J1939Tp_CmdtRxIndication_GetRxSduIdx
*
* Explanation: Get rx sdu idx.
*
* param: channelIdx: Rx channel index.
*        pgn: Rx sdu pgn.
* retval: netWork: Find sduIdx.
********************************************************************************
*/
static FUNC(uint16, J1939TP_CODE) J1939Tp_CmdtRxIndication_GetRxSduIdx
(
    uint8 sa,
    uint8 da,
    uint32 pgn
)
{
    boolean findSduIdxFlag = FALSE;
    uint16 rxChannelIdx;
    uint16 sduIdx = J1939TP_FINDSDUIDX_ERROR;
    uint16 netWork = J1939TP_FINDSDUIDX_ERROR;

    J1939TP_DUMMY_STATEMENT(pgn);
    for( rxChannelIdx = J1939TP_ZERO; rxChannelIdx < J1939TP_RXCHANNEL_NUMBER; rxChannelIdx++ )
    {
        /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
        uint16 sduStartIdx = J1939Tp_RxChannel[rxChannelIdx].startOfRxSduIdx;
        /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
        uint16 sduEndIdx = J1939Tp_RxChannel[rxChannelIdx].endOfRxSduIdx;

        J1939Tp_RxSduStateType* rxSduState = NULL_PTR;

        for( sduIdx = sduStartIdx; sduIdx < sduEndIdx; sduIdx++ )
        {
            rxSduState = &J1939Tp_RxSduState[sduIdx];
            if( (((uint32)((rxSduState)->State) & (uint32)J1939TP_STATEMASK_CMDT) != (uint32)J1939TP_STATE_IDLE) &&
                ((rxSduState)->Sender == sa) &&
                ((rxSduState)->Receiver == da) )
            {
                findSduIdxFlag = TRUE;
                break;
            }
        }

        if( TRUE == findSduIdxFlag )
        {
            netWork = sduIdx;
            break;
        }
    }

    return netWork;
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtRxIndication_RtsGetSduIdx
*
* Explanation: Find rx sduIdx in cmdt process.
*
* param: sa: Source address (SA) of this channel.
*        da: Destination address (DA) of this channel.
*        pgn: PGN of the referenced N-SDUs.
* retval: sduIdx: J1939TP_FINDSDUIDX_ERROR: Find faild.
*                  other: RxsduIndex.
********************************************************************************
*/
static FUNC(uint16, J1939TP_CODE) J1939Tp_CmdtRxIndication_RtsGetSduIdx
(
    uint8 sa,
    uint8 da,
    uint32 pgn
)
{
    boolean findSduIdxFlag = FALSE;
    uint16 channelIdx;
    uint16 sduIdx = J1939TP_FINDSDUIDX_ERROR;
    uint16 netWork = J1939TP_FINDSDUIDX_ERROR;

    J1939Tp_RxSduStateType* rxSduState;

    for( channelIdx = J1939TP_ZERO; channelIdx < J1939TP_RXCHANNEL_NUMBER; channelIdx++ )
    {
        if( J1939TP_PROTOCOL_BAM != J1939Tp_RxChannel[channelIdx].rxProtocolType )
        {
            /* SWS_J1939Tp_00173 */
          if(((sa == J1939Tp_RxChannel[channelIdx].rxSa) && (J1939TP_NO_ADDRESS_CONFIGURED > J1939Tp_RxChannel[channelIdx].rxSa)) || /* Have metadata , configured; no metadata ,configured */
            ((J1939TP_NO_ADDRESS_CONFIGURED >= sa) && (J1939TP_NO_ADDRESS_CONFIGURED == J1939Tp_RxChannel[channelIdx].rxSa))) /* Have metadata,no config ; no metadata ,no config */
            {
              if( ((da == J1939Tp_RxChannel[channelIdx].rxDa) && (J1939TP_NO_ADDRESS_CONFIGURED > J1939Tp_RxChannel[channelIdx].rxDa)) || /* Have metadata , configured ;no metadata ,configured */
                ((J1939TP_NO_ADDRESS_CONFIGURED >= da) && (J1939TP_NO_ADDRESS_CONFIGURED == J1939Tp_RxChannel[channelIdx].rxDa) ) ) /* Have metadata ,no config ; no metadata ,no config */
                {
                    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
                    uint16 sduStartIdx = J1939Tp_RxChannel[channelIdx].startOfRxSduIdx;
                    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
                    uint16 sduEndIdx = J1939Tp_RxChannel[channelIdx].endOfRxSduIdx;
                    for( sduIdx = sduStartIdx; sduIdx < sduEndIdx; sduIdx++ )
                    {
                        rxSduState = &J1939Tp_RxSduState[sduIdx];
                        if( (((uint32)((rxSduState)->State)) & (uint32)J1939TP_STATEMASK_CMDT) != (uint32)J1939TP_STATE_IDLE )
                        {
                            rxSduState->State = J1939TP_STATE_IDLE;
                            PduR_J1939TpRxIndication(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, E_NOT_OK);
                        }
                        else
                        {
                            rxSduState->Aborted = TRUE;
                        }

                        if( (FALSE == findSduIdxFlag) && (pgn == J1939Tp_RxSduInfo[sduIdx].rxPgPgn) )
                        {
                             findSduIdxFlag = TRUE;
                             rxSduState->Aborted = FALSE;
                             netWork = sduIdx;
                        }
                    }
                }
            }
        }
    }

    return netWork;
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtInternalRxIndication_ReceiveTpAbortRx
*
* Explanation: CMDT recived abort.
*
* param: sduIdx: ID of the Rx SDU.
*        rxSduState: rx sdu state.
*
* retval: None
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtRxIndication_ReceiveTpAbortRx
(
    uint16 sduIdx,
    J1939Tp_RxSduStateType* rxSduState
)
{
    if( (J1939TP_STATE_CMDT_CTS == rxSduState->State) || (J1939TP_STATE_CMDT_CTSWAIT == rxSduState->State) ||
        (J1939TP_STATE_CMDT_DATA_FIRST == rxSduState->State) || (J1939TP_STATE_CMDT_DATA == rxSduState->State) ||
        (J1939TP_STATE_CMDT_EOMACK == rxSduState->State) || (J1939TP_STATE_CMDT_ABORT == rxSduState->State) ||
        (J1939TP_STATE_CMDT_CTSRETRY == rxSduState->State) )
    {
        rxSduState->RetryState = J1939TP_DONT_RETRY;

        rxSduState->State = J1939TP_STATE_FINISH;
        PduR_J1939TpRxIndication(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, E_NOT_OK);
        /* No protection required - transition from uninterruptible state */
        rxSduState->State = J1939TP_STATE_IDLE;
    }
    else
    {
        rxSduState->Aborted = TRUE;
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtInternalRxIndication_ReceiveTpDt
*
* Explanation: This functions Receive TpDt.
*
* param: sduIdx: ID of the Rx SDU.
*        info: Contains the length (SduLength) of the received I-PDU and a pointer
*              to a buffer (SduDataPtr) containing the I-PDU.
*        rxSduState: rx sdu state.
*
* retval: None
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_CmdtInternalRxIndication_ReceiveTpDt
(
    uint16 sduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    J1939Tp_RxSduStateType* rxSduState
)
{
    BufReq_ReturnType tpResult;
    PduInfoType pdu = {NULL_PTR, J1939TP_ZERO};
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 channelIdx = J1939Tp_RxSduInfo[sduIdx].rxSduOfChannelIdx;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Dir4.5" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 pduIdx = J1939Tp_RxChannel[channelIdx].txConfitmIdx;
    J1939Tp_TxPduStateType* pduState = NULL_PTR;

    if( TRUE == J1939Tp_CmdtChkTxPduScope(pduIdx) )
    {
        pduState = &J1939Tp_TxPduState[pduIdx];
    }

    if( (J1939TP_STATE_CMDT_DATA_FIRST == rxSduState->State) ||
        (J1939TP_STATE_CMDT_DATA == rxSduState->State) )
    {
        rxSduState->State = J1939TP_STATE_CMDT_DATA_BUSY;

        if( TRUE == rxSduState->Aborted )
        {
            rxSduState->State = J1939TP_STATE_FINISH;

            /* InSession is active before the current state is reached */
            PduR_J1939TpRxIndication(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, E_NOT_OK);

            /* no protection required - transition from uninterruptible state */
            rxSduState->State = J1939TP_STATE_IDLE;
        }
        else
        {
            rxSduState->Sequence++;

            if( J1939TP_DONT_RETRY == rxSduState->RetryState )
            {
                if( rxSduState->Sequence == info->SduDataPtr[J1939TP_TPDT_SEQ] )
                {
                    pdu.SduDataPtr = &info->SduDataPtr[J1939TP_TPDT_DATA];
                    pdu.SduLength = J1939TP_TPDT_DATA_SIZE;

                    if( rxSduState->Sequence == rxSduState->Packets )
                    {
                        pdu.SduLength = (PduLengthType) ((rxSduState->Size) - (((uint32)(rxSduState->Sequence) - J1939TP_ONE) * J1939TP_TPDT_DATA_SIZE));
                    }

                    tpResult = PduR_J1939TpCopyRxData(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, &pdu, (uint32*)&rxSduState->BufSize);

                    if( BUFREQ_OK == tpResult )
                    {
                        if( rxSduState->Sequence == rxSduState->Packets )
                        {
                            rxSduState->TimeOut = J1939Tp_GetTime_Tr();

                            J1939Tp_CmdtInternalTransmitTpCmEOMAck(sduIdx);
                        }
                        else if( rxSduState->Sequence == rxSduState->NextBlock )
                        {
                            rxSduState->TimeOut = J1939Tp_GetTime_Tr();

                            J1939Tp_CmdtInternalTransmitTpCmCts(sduIdx);
                        }
                        else
                        {
                            rxSduState->TimeOut = J1939Tp_GetTime_T1();
                            /* no protection required - transition from uninterruptible state */
                            rxSduState->State = J1939TP_STATE_CMDT_DATA;
                        }
                    }
                    else
                    {   /* The J1939Tp module shall abort the reception.  SWS_J1939Tp_00040 */
                        if( NULL_PTR != pduState )
                        {
                            pduState->Locked = FALSE;
                            rxSduState->AbortReason = J1939TP_CAR_RESOURCES;
                            rxSduState->TimeOut = J1939Tp_GetTime_Tr();
                            /* No protection required - transition from uninterruptible state. */
                            rxSduState->State = J1939TP_STATE_CMDT_ABORT_BUSY;

                            J1939Tp_CmdtInternalTransmitTpAbortRx(sduIdx);
                        }
                    }
                }
                else
                {
                    rxSduState->RetryState = J1939TP_NEED_RETRY;
                    rxSduState->PacketOffset = rxSduState->NextBlock - rxSduState->Sequence + J1939TP_ONE;
                }
            }
            if( J1939TP_NEED_RETRY == rxSduState->RetryState )
            {
                /* Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule14.3" Polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
                if( FALSE == J1939Tp_RxChannel[channelIdx].rxRetrySupport )
                {
                    rxSduState->RetryState = J1939TP_DONT_RETRY;
                    /* Abort the reception session. */
                    rxSduState->AbortReason = J1939TP_CAR_OTHER;
                    rxSduState->TimeOut = J1939Tp_GetTime_Tr(); /*!< \trace SPEC-2167340 */
                    J1939Tp_CmdtInternalTransmitTpAbortRx(sduIdx);
                /* Polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                }
                else
                {
                    if( (info->SduDataPtr[J1939TP_TPDT_SEQ] == rxSduState->NextBlock) ||
                        (rxSduState->Sequence == rxSduState->NextBlock) )
                    {
                        rxSduState->RetryState = J1939TP_DONT_RETRY;
                        rxSduState->Sequence = rxSduState->NextBlock - rxSduState->PacketOffset;
                        J1939Tp_Retry_InCMDT_Transmission(sduIdx, rxSduState->Sequence, J1939Tp_RxSduInfo[sduIdx].rxPgPgn);
                    }
                    else
                    {
                        rxSduState->TimeOut = J1939Tp_GetTime_T1();
                        /* no protection required - transition from uninterruptible state */
                        rxSduState->State = J1939TP_STATE_CMDT_DATA;
                    }
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_Retry_InCMDT_Transmission
*
* Explanation: This functions Receive TpDt retry tx.
*
* param: sduIdx: ID of the Rx SDU.
*        block:
*
* retval: None
********************************************************************************
*/
static FUNC(void, J1939TP_CODE)J1939Tp_Retry_InCMDT_Transmission
(
    uint16 sduIdx,
    uint8 retrySequence,
    uint32 pgn
)
{
    boolean flag = FALSE;
    Std_ReturnType result;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 channelIdx = J1939Tp_RxSduInfo[sduIdx].rxSduOfChannelIdx;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Dir4.5" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 pduIdx = J1939Tp_RxChannel[channelIdx].txConfitmIdx;
    PduInfoType pdu;
    uint8 data[J1939TP_NPDU_LENGTH] = {J1939TP_ZERO};
    J1939Tp_TxPduStateType* pduState = NULL_PTR;
    J1939Tp_RxSduStateType* rxSduState = NULL_PTR;

    if( (TRUE == J1939Tp_CmdtChkTxPduScope(pduIdx)) &&
        (sduIdx < J1939TP_RXNSDU_NUMBER) )
    {
        pduState = &J1939Tp_TxPduState[pduIdx];
        rxSduState = &J1939Tp_RxSduState[sduIdx];
        flag = TRUE;
    }

    if( TRUE == flag )
    {
        if( FALSE == pduState->Locked )
        {
            pduState->CurrentNSduType = J1939TP_NSDU_CMDT_RX;
            pduState->CurrentNSduId = sduIdx;
            pduState->ConfTimeout = J1939Tp_GetTxConfTimeout();
            pduState->Locked = TRUE;

            data[J1939TP_TPCM_NOP] = rxSduState->PacketOffset;
            data[J1939TP_TPCM_NPN] = retrySequence + J1939TP_ONE;
            data[J1939TP_TPCM_CB] = (uint8)J1939TP_CB_CTS;
            data[J1939TP_TPCM_RES4] = J1939TP_SNA_VALUE;
            data[J1939TP_TPCM_RES5] = J1939TP_SNA_VALUE;
            data[J1939TP_TPCM_PGN_LO] = J1939Tp_Make_PGN_LO(pgn);
            data[J1939TP_TPCM_PGN_MD] = J1939Tp_Make_PGN_MD(pgn);
            data[J1939TP_TPCM_PGN_HI] = J1939Tp_Make_PGN_HI(pgn);
            data[J1939TP_NPDU_SA_POS] = rxSduState->Receiver;
            data[J1939TP_NPDU_DA_POS] = rxSduState->Sender;
            data[J1939TP_NPDU_PRI_POS] = rxSduState->Priority;

            pdu.SduDataPtr = data;
            pdu.SduLength = J1939TP_NPDU_LENGTH;
            rxSduState->State = J1939TP_STATE_CMDT_CTSRETRY_CONF;
            result = CanIf_Transmit(J1939Tp_GetPduIdOfTxPdu(pduIdx), &pdu);

            if( result != E_OK )
            {
                pduState->Locked = FALSE;
                rxSduState->State = J1939TP_STATE_CMDT_CTSRETRY;
            }
        }
        else
        {
            rxSduState->State = J1939TP_STATE_CMDT_CTSRETRY;
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_CmdtTxConfirmation
*
* Explanation: This functions process tx confirmation.
*
* param: sduIdx: ID of the send SDU.
*        pduType: pdu type.
*        sduType: sdu type.
* retval: None
********************************************************************************
*/
FUNC(void, J1939TP_CODE) J1939Tp_CmdtTxConfirmation
(
    PduIdType sduIdx,
    uint8 pduType,
    J1939Tp_NSduType sduType
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    J1939Tp_TxSduStateType* txSduState = &J1939Tp_TxSduState[sduIdx];

    if( J1939TP_NSDU_CMDT_TX == sduType )
    {
        if( J1939TP_TPCM_PDUTYPEOFTXPDU == pduType )
        {
            switch( txSduState->State )
            {
                case J1939TP_STATE_CMDT_RTS_CONF:
                    txSduState->TimeOut = J1939Tp_GetTime_T3();
                    /* protected against concurrent transmission failure and early Tx confirmation timeout */
                    txSduState->State = J1939TP_STATE_CMDT_CTS;
                    break;

                case J1939TP_STATE_CMDT_ABORT_CONF:
                    /* protected against concurrent transmission failure and early Tx confirmation timeout */
                    txSduState->State = J1939TP_STATE_FINISH;

                    PduR_J1939TpTxConfirmation(J1939Tp_TxSduInfo[sduIdx].txNSduIdx, E_NOT_OK);

                    /* no protection required - transition from uninterruptible state */
                    txSduState->State = J1939TP_STATE_IDLE;
                    break;

                default:
                    /* Do Nothing. */
                    break;
            }
        }
        else /* pduType == J1939TP_TPDT_PDUTYPEOFTXPDU */
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            if( J1939TP_STATE_CMDT_DATA_CONF == txSduState->State )
            {
                txSduState->Sequence++;
                /* Set TP.DT sending time. */
                txSduState->TpDtCount = J1939Tp_GetTxDtTime();

                if (txSduState->Sequence == txSduState->NextBlock)
                {
                    txSduState->TimeOut = J1939Tp_GetTime_T3();
                    txSduState->State = J1939TP_STATE_CMDT_CTS;
                }
                else
                {
#if( J1939TP_DTTIME_TX_ENABLED == STD_ON )
                    /* Set the status to J1939TP_STATE_CMDT_DATA. */
                    txSduState->State = J1939TP_STATE_CMDT_DATA;
#else
                    if( txSduState->Sequence <= txSduState->Packets )
                    {
                        txSduState->TimeOut = J1939Tp_GetTime_Tr();
                        txSduState->State = J1939TP_STATE_CMDT_DATA_BUSY;

                        J1939Tp_CmdtInternalTransmitTpDt(sduIdx);
                    }
#endif  /* J1939TP_DTTIME_TX_ENABLED == STD_ON */
                }
            }
        }
    }
    else
    {
        /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
        J1939Tp_RxSduStateType* rxSduState = &J1939Tp_RxSduState[sduIdx];

        /* Polyspace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_J1939Tp_SwitchFormat" */
        switch( rxSduState->State )
        {
            case J1939TP_STATE_CMDT_CTSWAIT_CONF:
                rxSduState->TimeOut = J1939Tp_GetTime_Th();
                /* protected against concurrent transmission failure and early Tx confirmation timeout */
                rxSduState->State = J1939TP_STATE_CMDT_CTSWAIT;
                break;

            case J1939TP_STATE_CMDT_CTS_CONF:
            case J1939TP_STATE_CMDT_CTSRETRY_CONF:
                rxSduState->TimeOut = J1939Tp_GetTime_T2();
                /* protected against concurrent transmission failure and early Tx confirmation timeout */
                rxSduState->State = J1939TP_STATE_CMDT_DATA_FIRST;
                break;

            case J1939TP_STATE_CMDT_EOMACK_CONF:
                /* protected against early Tx confirmation timeout */
                rxSduState->State = J1939TP_STATE_FINISH;
                PduR_J1939TpRxIndication(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, E_OK);

                /* no protection required - transition from uninterruptible state */
                rxSduState->State = J1939TP_STATE_IDLE;
                break;

            case J1939TP_STATE_CMDT_ABORT_CONF:
                /* protected against concurrent transmission failure and early Tx confirmation timeout */
                rxSduState->State = J1939TP_STATE_FINISH;

                PduR_J1939TpRxIndication(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, E_NOT_OK);

                /* no protection required - transition from uninterruptible state */
                rxSduState->State = J1939TP_STATE_IDLE;
                break;

            default:
                /* Do Nothing. */
                break;
        }
    }
}

#define J1939TP_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

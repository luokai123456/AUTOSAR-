/*
********************************************************************************
*
* File name: 1939Tp_Direct.c
*
* Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: li.zhiheng/2019.11.06
* Change: New created.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: li.zhiheng/2021.04.27
* Change: Add direct rx sdu state.
* Cause: Update
********************************************************************************
* Version: 1.2
* Author/Date: li.zhiheng/2021.04.27
* Change: Modifty J1939Tp_DirectRxIndication state Idle process.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: li.zhiheng/2021.05.25
* Change: 1.Disables SA/DA in J1939TP_DirectTransmit function.
*          2.Updata to 3.1.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: LiZH/2021.05.25
* Change: Modify the scope of Channel index.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: LiZH/2021.05.31
* Change: Modify J1939TP_DirectrxIndication function to evaluate SA and DA instead of PGN.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: LiZH/2021.05.31
* Change: Modifty J1939Tp_Direct_GetRxSduIdx, add PGN check.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: LiZH/2021.06.02
* Change: J1939Tp_Direct_GetRxSduIdx pointer add () .
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: LiZH/2021.06.15
* Change: Cancel the sa, da judgment.
* Cause: Bugfix
********************************************************************************
* Version: 3.7
* Author/Date: Li.ZH/2021.8.16
* Change: Modification code specification.
* Cause: Optimize
********************************************************************************
* Version: 3.8
* Author/Date: TongXY/2023.3.14
* Change: 1.Modify compilation warning.
*         2.Modified qac warning.
*         3.Fix coding specification problems.
*         4.Modifty J1939Tp_DirectRxIndication.
*         5.Modifty J1939Tp_DirectInternalTransmitTpDirect.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: TongXY/2023.05.24
* Change: 1.Memmap macro value to all uppercase.
*         2.To see if they are equal, we put the constant on the left.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: YanCL/2024.3.19
* Change: Modify the P2CONST incorrect labels.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: YanCL/2024.4.2
* Change: 1.Modify the P2CONST incorrect labels.
*         2.Modify the annotation.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: YanCL/2024.5.23
* Change: Adjusting the parameter positions of function declarations.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: YanCL/2024.6.25
* Change: 1.Add Memmap segment definition.
*         2.Add copyright information.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: YanCL/2025.03.26
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: YanCL/2025.06.06
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.16
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
#include "J1939Tp_Direct.h"
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

#if (J1939TP_DIRECT_TX_ENABLED == STD_ON)
static FUNC(boolean, J1939TP_CODE)J1939Tp_DirectChkTxSduScope(PduIdType sduIdx);
static FUNC(void, J1939TP_CODE)J1939Tp_DirectInternalTransmitTpDirect(PduIdType sduIdx);
#endif  /* J1939TP_DIRECT_RX_ENABLED == STD_ON */

#if (J1939TP_DIRECT_RX_ENABLED == STD_ON)
static FUNC(void, J1939TP_CODE) J1939Tp_DirectInternalRxIndication_ReceiveTpDirect
(
    uint16 sduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    PduLengthType pduLen,
    uint8 sa,
    uint8 da
);
static FUNC(uint16, J1939TP_CODE) J1939Tp_Direct_GetRxSduIdx
(
    uint8 sa,
    uint8 da,
    PduIdType pduIdx
);
#endif  /* J1939TP_DIRECT_RX_ENABLED == STD_ON */

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

#if (J1939TP_DIRECT_TX_ENABLED == STD_ON)
/*
********************************************************************************
* Function Name: J1939Tp_DirectChkTxSduScope
*
* Explanation: Check SduIdx size.
*
* param: sduIdx: ID of the send SDU.
* retval: flag: True: Searching sucess.
*               FLASE: Searching faild.
********************************************************************************
*/
static FUNC(boolean, J1939TP_CODE)J1939Tp_DirectChkTxSduScope
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
* Function Name: J1939Tp_DirectChkTxPduScope
*
* Explanation: Check PduIdx size.
*
* param: PduIdx: ID of the send PDU.
* retval: flag: True: Searching sucess.
*               FLASE: Searching faild.
********************************************************************************
*/
static FUNC(boolean, J1939TP_CODE)J1939Tp_DirectChkTxPduScope
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Dir4.5" */
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
* Function Name: J1939Tp_DirectTransmit
*
* Explanation: This functions sends direct message.
*
* param: sduIdx: ID of the send SDU.
*        info: Contains the length (SduLength) of the received I-PDU and
*              a pointer to a buffer (SduDataPtr) containing the I-PDU.
*
* retval: Std_ReturnType: E_OK: Transmit sucess.
*                         E_NOT_OK: Transmit faild.
********************************************************************************
*/
FUNC(Std_ReturnType, J1939TP_CODE) J1939Tp_DirectTransmit
(
    PduIdType sduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    uint8 sa,
    uint8 da,
    uint8 pri
)
{
    Std_ReturnType result = E_NOT_OK;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    J1939Tp_TxSduStateType* txSduState = &J1939Tp_TxSduState[sduIdx];

    if( J1939TP_STATE_IDLE == txSduState->State )
    {
        txSduState->State = J1939TP_STATE_DIRECT_BUSY;

        /* Set value. */
        txSduState->Size = info->SduLength;
        txSduState->Sender = sa;
        txSduState->Receiver = da;
        txSduState->Priority = pri;
        txSduState->TimeOut = J1939Tp_GetTime_Tr();

        J1939Tp_DirectInternalTransmitTpDirect(sduIdx);

        result = E_OK;
    }

    return result;
}

/*
********************************************************************************
* Function Name: J1939Tp_DirectInternalTransmitTpDirect
*
* Explanation: This functions sends direct message.
*
* param: sduIdx: ID of the send SDU.
*
* retval: None
********************************************************************************
*/
static FUNC(void, J1939TP_CODE)J1939Tp_DirectInternalTransmitTpDirect
(
    PduIdType sduIdx
)
{
    boolean flag = FALSE;
    boolean checksduIdxflag = FALSE;
    boolean checkpduIdxflag = FALSE;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Dir4.5" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 pduIdx = J1939Tp_TxSduInfo[sduIdx].txDirectPduIdxOfTxPdu;
    J1939Tp_TxPduStateType* pduState = NULL_PTR;
    J1939Tp_TxSduStateType* txSduState = NULL_PTR;

    checksduIdxflag = J1939Tp_DirectChkTxSduScope(sduIdx);
    checkpduIdxflag = J1939Tp_DirectChkTxPduScope(pduIdx);

    /* Check PduIdx, SduIdx scope. */
    if( (TRUE == checksduIdxflag) && (TRUE == checkpduIdxflag) )
    {
        pduState = &J1939Tp_TxPduState[pduIdx];
        txSduState = &J1939Tp_TxSduState[sduIdx];
        flag = TRUE;
    }

    if( (TRUE == flag) && (FALSE == pduState->Locked) )
    {
        pduState->CurrentNSduType = J1939TP_NSDU_DIRECT;
        pduState->CurrentNSduId = sduIdx;
        pduState->ConfTimeout = J1939Tp_GetTxConfTimeout();
        pduState->Locked = TRUE;

        {
            uint8 data[J1939TP_NPDU_LENGTH];
            PduInfoType pdu;
            BufReq_ReturnType tpResult;

            pdu.SduDataPtr = data;
            pdu.SduLength = (PduLengthType) txSduState->Size;

            tpResult = PduR_J1939TpCopyTxData(J1939Tp_TxSduInfo[sduIdx].txNSduIdx,
                                              (const PduInfoType*)&pdu,
                                              NULL_PTR,
                                              (uint32*)&txSduState->DataSize);
            if( BUFREQ_OK == tpResult )
            {
                Std_ReturnType result;
                uint8 pos;
                /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
                uint32 pgn = J1939Tp_TxSduInfo[sduIdx].txPgPgn;

                for( pos = (uint8)(txSduState->Size); pos < J1939TP_FRAME_LENGTH; pos++ )
                {
                    data[pos] = J1939TP_SNA_VALUE;
                }

                data[J1939TP_NPDU_SA_POS] = txSduState->Sender;

                if( J1939Tp_PGN_IsPDU2(pgn) )
                /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    data[J1939TP_NPDU_GE_POS] = J1939Tp_PGN_GetPDUS(pgn);
                }
                else
                {
                    data[J1939TP_NPDU_DA_POS] = txSduState->Receiver;
                }
                /* data[J1939TP_NPDU_PDUF_POS] = (uint8) J1939Tp_PGN_GetPDUF(pgn); */
                data[J1939TP_NPDU_DP_POS] = (uint8) J1939Tp_PGN_GetDP(pgn) | txSduState->Priority;

                pdu.SduLength = J1939TP_NPDU_LENGTH;

                /* No protection required - all exits from pending and busy state are in the scope of the calling functions */
                txSduState->State = J1939TP_STATE_DIRECT_CONF;
                result = CanIf_Transmit(J1939Tp_GetPduIdOfTxPdu(pduIdx), &pdu);
                if( result != E_OK )
                {
                    /* No protection required - no further actions related to the locked state */
                    pduState->Locked = FALSE;

                    /* Protected against late Tx confirmation */
                    txSduState->State = J1939TP_STATE_DIRECT;
                }
            }
            else
            {
                /* No protection required - no further actions related to the locked state */
                pduState->Locked = FALSE;

                if( BUFREQ_E_BUSY == tpResult )
                {
                    /* No protection required - all exits from pending and busy state are in the scope of the calling functions */
                    txSduState->State = J1939TP_STATE_DIRECT;
                }
                else
                {
                    /* No protection required - all exits from pending and busy state are in the scope of the calling functions */
                    txSduState->State = J1939TP_STATE_FINISH;

                    PduR_J1939TpTxConfirmation(J1939Tp_TxSduInfo[sduIdx].txNSduIdx, E_NOT_OK);

                    /* No protection required - transition from uninterruptible state */
                    txSduState->State = J1939TP_STATE_IDLE;
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_DirectTxConfirmation
*
* Explanation: This functions process tx confirmation.
*
* param: sduIdx: ID of the send SDU.
*        pduType: pdu type.
*
* retval: None
********************************************************************************
*/
FUNC(void, J1939TP_CODE) J1939Tp_DirectTxConfirmation
(
    PduIdType sduIdx
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    J1939Tp_TxSduStateType* txSduState = &J1939Tp_TxSduState[sduIdx];

    if( J1939TP_STATE_DIRECT_CONF == txSduState->State )
    {
        txSduState->State = J1939TP_STATE_FINISH;

        /* Transmit sucess. */
        PduR_J1939TpTxConfirmation(J1939Tp_TxSduInfo[sduIdx].txNSduIdx, E_OK);

        txSduState->State = J1939TP_STATE_IDLE;
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_DirectTxMain
*
* Explanation: Tx direct mainfunction process.
*
* param: sduIdx: ID of the send SDU.
*
* retval: None
********************************************************************************
*/
FUNC(void, J1939TP_CODE) J1939Tp_DirectTxMain
(
    PduIdType sduIdx
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    J1939Tp_TxSduStateType* txSduState = &J1939Tp_TxSduState[sduIdx];

    if( J1939TP_STATE_DIRECT == txSduState->State )
    {
        if( J1939TP_ZERO == txSduState->TimeOut )
        {
            txSduState->State = J1939TP_STATE_FINISH;

            J1939Tp_ReportRuntimeError(J1939TP_SID_MAINFUNCTION, J1939TP_E_TIMEOUT_TR);

            PduR_J1939TpTxConfirmation(J1939Tp_TxSduInfo[sduIdx].txNSduIdx, E_NOT_OK);

            txSduState->State = J1939TP_STATE_IDLE;
        }
        else
        {
            --txSduState->TimeOut;

            J1939Tp_DirectInternalTransmitTpDirect(sduIdx);
        }
    }
}

#endif  /* J1939TP_DIRECT_TX_ENABLED == STD_ON */

/*
********************************************************************************
* Function Name: J1939Tp_DirectRxIndication
*
* Explanation: This functions sends the Rx indication.
*
* param: pduIdx: ID of the received I-PDU.
*        info: Contains the length (SduLength) of the received I-PDU and a pointer
*              to a buffer (SduDataPtr) containing the I-PDU.
*        sa: source address.
*
* retval: None
********************************************************************************
*/
#if (J1939TP_DIRECT_RX_ENABLED == STD_ON)
FUNC(void, J1939TP_CODE) J1939Tp_DirectRxIndication
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Dir4.5" */
    PduIdType pduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    uint8 sa
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint8 pduLen = (uint8)(info->SduLength) - J1939TP_MDL_SIZE;
    uint8 da = info->SduDataPtr[pduLen + J1939TP_MDL_DA_POS];
    uint16 sduIdx;

    sduIdx = J1939Tp_Direct_GetRxSduIdx(sa, da, pduIdx);
    if( J1939TP_FINDSDUIDX_ERROR != sduIdx )
    {
        if( J1939Tp_PGN_IsPDU2(J1939Tp_RxSduInfo[sduIdx].rxPgPgn) )
        {
            da = J1939TP_BROADCAST_ADDRESS;
        }

        if( (da) == J1939TP_NULL_ADDRESS )
        {
            J1939Tp_ReportRuntimeError(J1939TP_SID_RXINDICATION, J1939TP_E_INVALID_DA);
        }
        else
        {
            /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
            J1939Tp_RxSduStateType* rxSduState = &J1939Tp_RxSduState[sduIdx];

            if( J1939TP_STATE_IDLE == rxSduState->State )
            {
                rxSduState->State = J1939TP_STATE_DIRECT_BUSY;

                J1939Tp_DirectInternalRxIndication_ReceiveTpDirect(sduIdx, info, pduLen, sa, da);

                rxSduState->State = J1939TP_STATE_IDLE;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_Direct_GetRxSduIdx
*
* Explanation: Find rx sduIdx in Bam process.
*
* param: sa: source address.
*        da: destination address.
* retval: sduIdx:  J1939TP_FINDSDUIDX_ERROR: Find faild.
*                  other: RxsduIndex.
********************************************************************************
*/
static FUNC(uint16, J1939TP_CODE) J1939Tp_Direct_GetRxSduIdx
(
    uint8 sa,
    uint8 da,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Dir4.5" */
    PduIdType pduIdx
)
{
    uint16 network = J1939TP_FINDSDUIDX_ERROR;
    uint16 sduIdx = J1939TP_FINDSDUIDX_ERROR;

    J1939TP_DUMMY_STATEMENT(sa);
    J1939TP_DUMMY_STATEMENT(da);

    J1939Tp_RxSduStateType* rxSduState;

    for( sduIdx = J1939TP_ZERO; sduIdx < J1939TP_RXNSDU_NUMBER; sduIdx++ )
    {
        rxSduState = &J1939Tp_RxSduState[sduIdx];

        if( (J1939Tp_RxSduInfo[sduIdx].rxDirectPduIdxOfTxPdu == pduIdx) &&
            ((uint32)J1939TP_STATE_IDLE == ((uint32)(rxSduState->State) & (uint32)J1939TP_STATE_DIRECT)) )
        {
            /* Find sucess. */
            network = sduIdx;
            break;
        }
    }

    return network;
}

/*
********************************************************************************
* Function Name: J1939Tp_DirectInternalRxIndication_ReceiveTpDirect
*
* Explanation: Recieve Proces in direct.
*
* param: sduIdx: ID of the rx SDU.
*        info: Contains the length (SduLength) of the received I-PDU and a pointer
*              to a buffer (SduDataPtr) containing the I-PDU.
*        pduLen: Pdu length.
*        sa: source address.
*        da: destination address.
* retval: None
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_DirectInternalRxIndication_ReceiveTpDirect
(
    uint16 sduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    PduLengthType pduLen,
    uint8 sa,
    uint8 da
)
{
    uint8 metaData[J1939TP_MDL_SIZE] = {J1939TP_ZERO};
    BufReq_ReturnType tpResult;
    PduInfoType addrInfo;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Dir4.5" */
    PduLengthType bufSize;

    addrInfo.SduLength = J1939Tp_RxSduInfo[sduIdx].metaDataLength;
    addrInfo.SduDataPtr = metaData;

    metaData[J1939TP_MDL_SA_POS] = sa;
    metaData[J1939TP_MDL_DA_POS] = da;
    metaData[J1939TP_MDL_PDUF_POS] = J1939TP_SNA_VALUE;
    metaData[J1939TP_MDL_PRI_POS] = J1939Tp_MDL_Get_PRI(info->SduDataPtr[pduLen + J1939TP_MDL_PRI_POS]);

    tpResult = PduR_J1939TpStartOfReception(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, &addrInfo, pduLen, &bufSize);
    if( BUFREQ_OK == tpResult )
    {
        Std_ReturnType result = E_NOT_OK;

        if( bufSize >= pduLen )
        {
            PduInfoType pdu;

            pdu.SduDataPtr = info->SduDataPtr;
            pdu.SduLength = pduLen;

            tpResult = PduR_J1939TpCopyRxData(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, &pdu, &bufSize);
            if( BUFREQ_OK == tpResult )
            {
                result = E_OK;
            }
        }

        PduR_J1939TpRxIndication(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, result);
    }
}

#endif  /* J1939TP_DIRECT_RX_ENABLED == STD_ON */

#define J1939TP_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

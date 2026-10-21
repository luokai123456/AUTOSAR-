/*
********************************************************************************
*
* File name: 1939Tp_Bam.c
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
* Change: Cancel J1939Tp_ReportRuntimeError process in J1939Tp_BamRxIndication.
* Cause: Update
********************************************************************************
* Version: 1.2
* Author/Date: li.zhiheng/2021.05.10
* Change: 1.Modifty add length check.
*         2.Delete test code.
* Cause: Update
********************************************************************************
* Version: 1.3
* Author/Date: li.zhiheng/2021.05.25
* Change: 1.Modifty find sdu index.
*         2.Cancel the judgment of the J1939Tp_BamTransmit sa/da.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: LiZH/2021.05.25
* Change: Modify the scope of Channel index.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: LiZH/2021.05.31
* Change: Modify J1939Tp_BamGetRxSduIdx_TPCM, J1939Tp_BamGetRxSduIdx_TPDT find SduIdx.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: LiZH/2021.05.31
* Change: Add J1939Tp_BamGetRxSduIdx_TPCM check sa.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: LiZH/2021.06.15
* Change: Modifty sduIdx find mode.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: Li.ZH/2021.8.16
* Change: Modification code specification.
* Cause: Optimize
********************************************************************************
* Version: 3.6
* Author/Date: TongXY/2023.3.14
* Change: 1.Modify compilation warning.
*         2.Modified qac warning.
*         3.Fix coding specification problems.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: TongXY/2023.05.24
* Change: 1.Memmap macro value to all uppercase.
*         2.To see if they are equal, we put the constant on the left.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: YanCL/2024.3.19
* Change: Modify the P2CONST incorrect labels.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: YanCL/2024.4.2
* Change: 1. Modify the P2CONST incorrect labels.
*         2. Modify the annotation.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: YanCL/2024.5.23
* Change: 1.Implement J1939Tp module to send TP.DT messages according to the
*           configured time in BAM mode.
*         2.Adjusting the parameter positions of function declarations.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: YanCL/2024.6.25
* Change: 1.Add Memmap segment definition.
*         2.Add copyright information.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: YanCL/2025.03.26
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: YanCL/2025.06.06
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.14
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
#include "J1939Tp_Bam.h"
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

#if (J1939TP_BAM_TX_ENABLED == STD_ON)
static FUNC(boolean, J1939TP_CODE)J1939Tp_BamChkTxSduScope(PduIdType sduIdx);
static FUNC(boolean, J1939TP_CODE)J1939Tp_BamChkTxPduScope(PduIdType PduIdx);
static FUNC(void, J1939TP_CODE) J1939Tp_BamInternalTransmitTpDt(PduIdType sduIdx);
static FUNC(void, J1939TP_CODE) J1939Tp_BamInternalTransmitTpCmBam(PduIdType sduIdx);
#endif  /* J1939TP_BAM_TX_ENABLED == STD_ON */

#if (J1939TP_BAM_RX_ENABLED == STD_ON)
static FUNC(void, J1939TP_CODE) J1939Tp_BamInternalRxIndication_ReceiveTpCmBam
(
    uint16 sduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    uint8 sa,
    uint16 size,
    J1939Tp_RxSduStateType* rxSduState
);
static FUNC(void, J1939TP_CODE) J1939Tp_BamInternalRxIndication_ReceiveTpDt
(
    PduIdType sduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    J1939Tp_RxSduStateType* rxSduState
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */
static FUNC(uint16, J1939TP_CODE) J1939Tp_BamGetRxSduIdx_TPDT(uint8 sa);
static FUNC(uint16, J1939TP_CODE) J1939Tp_BamGetRxSduIdx_TPCM(uint8 sa, uint32 pgn);
#endif  /* J1939TP_BAM_RX_ENABLED == STD_ON */

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

#if (J1939TP_BAM_TX_ENABLED == STD_ON)
/*
********************************************************************************
* Function Name: J1939Tp_BamChkTxSduScope
*
* Explanation: Check SduIdx size.
*
* param: sduIdx: ID of the send SDU.
* retval: flag: TRUE: Search sucess.
*               FALSE: Search faild.
********************************************************************************
*/
static FUNC(boolean, J1939TP_CODE)J1939Tp_BamChkTxSduScope
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
* Function Name: J1939Tp_BamChkTxPduScope
*
* Explanation: Check PduIdx size.
*
* param: PduIdx: ID of the send PDU.
* retval: flag: TRUE: Search sucess.
*               FALSE: Search faild.
********************************************************************************
*/
static FUNC(boolean, J1939TP_CODE)J1939Tp_BamChkTxPduScope
(
    PduIdType PduIdx
)
{
    boolean flag = FALSE;
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( PduIdx < J1939TP_TXPDU_NUM )
    {
        flag = TRUE;
    }

    return flag;
}

/*
********************************************************************************
* Function Name: J1939Tp_BamTxMain
*
* Explanation: Internal process transmit.
*
* param: sduIdx: ID of the send SDU.
*
* retval: None
********************************************************************************
*/
FUNC(void, J1939TP_CODE) J1939Tp_BamTxMain
(
    PduIdType sduIdx
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    J1939Tp_TxSduStateType* txSduState = &J1939Tp_TxSduState[sduIdx];

    if( J1939TP_ZERO == txSduState->TimeOut )  /* Timeout process. */
    {
        J1939Tp_ReportRuntimeError(J1939TP_SID_MAINFUNCTION, J1939TP_E_TIMEOUT_TR);

        if( (J1939TP_STATE_BAM_BAM == txSduState->State)
            || (J1939TP_STATE_BAM_DATA == txSduState->State) )
        {
            /* No protection required - all exits from BAM and data states are in the scope of this function */
            txSduState->State = J1939TP_STATE_FINISH;

            PduR_J1939TpTxConfirmation(J1939Tp_TxSduInfo[sduIdx].txNSduIdx, E_NOT_OK);

            /* No protection required - transition from uninterruptible state */
            txSduState->State = J1939TP_STATE_IDLE;
        }
    }
    else
    {
        --txSduState->TimeOut;

        switch( txSduState->State )
        {
            case J1939TP_STATE_BAM_BAM:
            {
                J1939Tp_BamInternalTransmitTpCmBam(sduIdx);

                break;
            }
            case J1939TP_STATE_BAM_DATA:
            {
                /* TP.DT transmission condition judgment. */
#if( J1939TP_DTTIME_TX_ENABLED == STD_ON )
                if( txSduState->TimeOut <= (J1939Tp_GetTime_Tr() - J1939Tp_GetTxDtTime()) )
#else
                if( txSduState->TimeOut <= (J1939Tp_GetTime_Tr() - J1939Tp_GetTime_Bam()) )
#endif  /* J1939TP_DTTIME_TX_ENABLED == STD_ON */
                {
                    J1939Tp_BamInternalTransmitTpDt(sduIdx);
                }

                break;
            }
            default:
                /* Do Nothing. */
                break;
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_BamTransmit
*
* Explanation: This functions sends bam message.
*
* param: sduIdx: ID of the send SDU.
*        info: Contains the length (SduLength) of the received I-PDU and
*              a pointer to a buffer (SduDataPtr) containing the I-PDU.
*
* retval: Std_ReturnType
********************************************************************************
*/
FUNC(Std_ReturnType, J1939TP_CODE) J1939Tp_BamTransmit
(
    PduIdType sduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    uint8 sa,
    uint8 pri
)
{
    Std_ReturnType result = E_NOT_OK;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    J1939Tp_TxSduStateType* txSduState = &J1939Tp_TxSduState[sduIdx];
#if( J1939TP_DTTIME_TX_ENABLED == STD_ON )
    PduIdType sduIdxLocal;
    uint8 parallelResult = E_OK;
#endif  /* J1939TP_DTTIME_TX_ENABLED == STD_ON */

    if( info->SduLength > J1939TP_MAX_LENGTH )
    {
        J1939Tp_ReportDevError(J1939TP_SID_TRANSMIT, J1939TP_E_INVALID_LENGTH);
    }
    else
    {
#if( J1939TP_DTTIME_TX_ENABLED == STD_ON )
        /* [SWS_J1939Tp_00120] Ensure that handling all N-SDU parallel connections does not interfere with the use of TP. */
        for( sduIdxLocal = J1939TP_IDX_ZERO; sduIdxLocal < J1939TP_TXNSDU_NUMBER; sduIdxLocal++ )
        {
            txSduState = &J1939Tp_TxSduState[sduIdxLocal];
            /* N-Sdu is currently being processed in the current channel, ignoring other N-Sdu. */
            if( (J1939Tp_TxSduInfo[sduIdxLocal].txSduOfChannelIdx == J1939Tp_TxSduInfo[sduIdx].txSduOfChannelIdx)&&
                (J1939TP_STATE_IDLE != txSduState->State)&&
                (J1939Tp_TxChannel[J1939Tp_TxSduInfo[sduIdx].txSduOfChannelIdx].txSa == sa) )
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
            /* Protected against a reentrant call for the same N-SDU */
            txSduState->State = J1939TP_STATE_BAM_BAM_BUSY;

            txSduState->Size = info->SduLength;
            txSduState->Packets = J1939Tp_Get_Packets(info->SduLength);
            txSduState->Sender = sa;
            txSduState->Receiver = J1939TP_BROADCAST_ADDRESS;
            txSduState->Priority = pri;
            txSduState->Sequence = J1939TP_ONE;
            txSduState->TimeOut = J1939Tp_GetTime_Tr();
            /* No protection required - transition from uninterruptible state */
            txSduState->State = J1939TP_STATE_BAM_BAM;

            result = E_OK;
        }
    }

    return result;
}

/*
********************************************************************************
* Function Name: J1939Tp_BamTxConfirmation
*
* Explanation: This functions process tx confirmation.
*
* param: sduIdx: ID of the send SDU.
*        pduType: pdu type.
*
* retval: None
********************************************************************************
*/
FUNC(void, J1939TP_CODE) J1939Tp_BamTxConfirmation
(
    PduIdType sduIdx,
    uint8 pduType
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    J1939Tp_TxSduStateType * txSduState = &J1939Tp_TxSduState[sduIdx];

    if( J1939TP_TPCM_PDUTYPEOFTXPDU == pduType )
    {
        if( J1939TP_STATE_BAM_BAM_CONF == txSduState->State )
        {
            /* Advance state to send first TP.DT frame */
            txSduState->TimeOut = J1939Tp_GetTime_Tr();
            /* Protected against concurrent transmission failure and early Tx confirmation timeout */
            txSduState->State = J1939TP_STATE_BAM_DATA;
        }
    }
    else /* pduType == J1939TP_TPDT_PDUTYPEOFTXPDU */
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        if( J1939TP_STATE_BAM_DATA_CONF == txSduState->State )
        {
            if( txSduState->Sequence == txSduState->Packets )
            {
                txSduState->State = J1939TP_STATE_FINISH;

                PduR_J1939TpTxConfirmation(J1939Tp_TxSduInfo[sduIdx].txNSduIdx, E_OK);

                /* No protection required - transition from uninterruptible state */
                txSduState->State = J1939TP_STATE_IDLE;
            }
            else
            {
                txSduState->Sequence++;
                txSduState->TimeOut = J1939Tp_GetTime_Tr();

                txSduState->State = J1939TP_STATE_BAM_DATA;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_BamInternalTransmitTpDt
*
* Explanation: Internal process transmit tpcm tpdt.
*
* param: sduIdx: ID of the send SDU.
*
* retval: None
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_BamInternalTransmitTpDt
(
    PduIdType sduIdx
)
{
    boolean flag = FALSE;
    boolean checksduIdxflag = FALSE;
    boolean checkpduIdxflag = FALSE;
    Std_ReturnType result;
    BufReq_ReturnType tpResult;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 channelIdx = J1939Tp_TxSduInfo[sduIdx].txSduOfChannelIdx;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_J1939T_Dir4.5" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 pduIdx = J1939Tp_TxChannel[channelIdx].txDtNPduIdx;
    PduInfoType pdu;
    J1939Tp_TxPduStateType* pduState = NULL_PTR;
    J1939Tp_TxSduStateType* txSduState = NULL_PTR;
    uint8 data[J1939TP_NPDU_LENGTH] = {J1939TP_ZERO};

    checksduIdxflag = J1939Tp_BamChkTxSduScope(sduIdx);
    checkpduIdxflag = J1939Tp_BamChkTxPduScope(pduIdx);

    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( (TRUE == checksduIdxflag) && (TRUE == checkpduIdxflag) )
    {
        pduState = &J1939Tp_TxPduState[pduIdx];
        txSduState = &J1939Tp_TxSduState[sduIdx];
        flag = TRUE;
    }

    if( (TRUE == flag) && (FALSE == pduState->Locked) )
    {
        pduState->CurrentNSduType = J1939TP_NSDU_BAM;
        pduState->CurrentNSduId = sduIdx;
        pduState->ConfTimeout = J1939Tp_GetTxConfTimeout();
        /* Set Locked falg. */
        pduState->Locked = TRUE;

        pdu.SduDataPtr = &data[J1939TP_TPDT_DATA];
        pdu.SduLength = J1939TP_TPDT_DATA_SIZE;

        if( txSduState->Sequence == txSduState->Packets )
        {
            pdu.SduLength
              = (PduLengthType) ((txSduState->Size) - (((uint32)(txSduState->Sequence) - J1939TP_ONE) * J1939TP_TPDT_DATA_SIZE));
        }

        tpResult = PduR_J1939TpCopyTxData(J1939Tp_TxSduInfo[sduIdx].txNSduIdx,
                                         (const PduInfoType*)&pdu,
                                         NULL_PTR, (uint32*)&txSduState->DataSize);

        if( BUFREQ_OK == tpResult )
        {
            uint8 pos;
            data[J1939TP_TPDT_SEQ] = txSduState->Sequence;

            for( pos = J1939TP_TPDT_DATA + (uint8) pdu.SduLength ; pos < J1939TP_FRAME_LENGTH ; pos++ )
            {
                data[pos] = J1939TP_SNA_VALUE;
            }

            data[J1939TP_NPDU_SA_POS] = txSduState->Sender;
            data[J1939TP_NPDU_DA_POS] = J1939TP_BROADCAST_ADDRESS;
            data[J1939TP_NPDU_PRI_POS] = txSduState->Priority;

            pdu.SduDataPtr = data;
            pdu.SduLength = J1939TP_NPDU_LENGTH;

            /* No protection required - all exits from data state are in the scope of the Tx main function */
            txSduState->State = J1939TP_STATE_BAM_DATA_CONF;

            result = CanIf_Transmit(J1939Tp_GetPduIdOfTxPdu(pduIdx), &pdu);

            if( result != E_OK )
            {
                /* no protection required - no further actions related to the locked state */
                pduState->Locked = FALSE;

                /* protected against late Tx confirmation */
                txSduState->State = J1939TP_STATE_BAM_DATA;
            }
        }
        else
        {
            /* no protection required - no further actions related to the locked state */
            pduState->Locked = FALSE;

            if( tpResult != BUFREQ_E_BUSY )
            {
                /* no protection required - all exits from data state are in the scope of the Tx main function */
                txSduState->State = J1939TP_STATE_FINISH;

                PduR_J1939TpTxConfirmation(J1939Tp_TxSduInfo[sduIdx].txNSduIdx, E_NOT_OK);

                /* no protection required - transition from uninterruptible state */
                txSduState->State = J1939TP_STATE_IDLE;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_BamInternalTransmitTpCmBam
*
* Explanation: This functions Transmit TpCm Bam.
*
* param: sduIdx: ID of the Rx SDU.
*
* retval: None
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_BamInternalTransmitTpCmBam
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
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_J1939T_Dir4.5" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 pduIdx = J1939Tp_TxChannel[channelIdx].txCmNPduIdx;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint32 pgn = J1939Tp_TxSduInfo[sduIdx].txPgPgn;
    uint8 data[J1939TP_NPDU_LENGTH] = {J1939TP_ZERO};
    PduInfoType pdu;
    J1939Tp_TxPduStateType* pduState = NULL_PTR;
    J1939Tp_TxSduStateType* txSduState = NULL_PTR;

    checksduIdxflag = J1939Tp_BamChkTxSduScope(sduIdx);
    checkpduIdxflag = J1939Tp_BamChkTxPduScope(pduIdx);

    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( (TRUE == checksduIdxflag) && (TRUE == checkpduIdxflag) )
    {
        pduState = &J1939Tp_TxPduState[pduIdx];
        txSduState = &J1939Tp_TxSduState[sduIdx];
        flag = TRUE;
    }

    if( (TRUE == flag) && (FALSE == pduState->Locked) )
    {
        pduState->CurrentNSduType = J1939TP_NSDU_BAM;
        pduState->CurrentNSduId = sduIdx;
        pduState->ConfTimeout = J1939Tp_GetTxConfTimeout();

        /* Protected against concurrent access to the same TP.CM N-PDU */
        pduState->Locked = TRUE;

        data[J1939TP_TPCM_CB] = (uint8)J1939TP_CB_BAM;
        data[J1939TP_TPCM_TMS_LO] = J1939Tp_Make_TMS_LO(txSduState->Size);
        data[J1939TP_TPCM_TMS_HI] = J1939Tp_Make_TMS_HI(txSduState->Size);
        data[J1939TP_TPCM_TNOP] = (uint8) txSduState->Packets;
        data[J1939TP_TPCM_RES5] = J1939TP_SNA_VALUE;
        data[J1939TP_TPCM_PGN_LO] = J1939Tp_Make_PGN_LO(pgn);
        data[J1939TP_TPCM_PGN_MD] = J1939Tp_Make_PGN_MD(pgn);
        data[J1939TP_TPCM_PGN_HI] = J1939Tp_Make_PGN_HI(pgn);
        data[J1939TP_NPDU_SA_POS] = txSduState->Sender;
        data[J1939TP_NPDU_DA_POS] = J1939TP_BROADCAST_ADDRESS;
        data[J1939TP_NPDU_PRI_POS] = txSduState->Priority;

        pdu.SduDataPtr = data;
        pdu.SduLength = J1939TP_NPDU_LENGTH;

        /* No protection required - all exits from BAM state are in the scope of the Tx main function */
        txSduState->State = J1939TP_STATE_BAM_BAM_CONF;
        result = CanIf_Transmit(J1939Tp_GetPduIdOfTxPdu(pduIdx), &pdu);
        if ( E_OK != result )
        {
            /* No protection required - no further actions related to the locked state */
            pduState->Locked = FALSE;

            /* Protected against late Tx confirmation */
            txSduState->State = J1939TP_STATE_BAM_BAM;
        }
    }
    else
    {
        /* Do nothing. */
    }
}

#endif  /* J1939TP_BAM_TX_ENABLED == STD_ON */

#if (J1939TP_BAM_RX_ENABLED == STD_ON)
/*
********************************************************************************
* Function Name: J1939Tp_BamRxMain
*
* Explanation: Rx Bam mainfunction process.
*
* param: sduIdx: ID of the send SDU.
*
* retval: None
********************************************************************************
*/
FUNC(void, J1939TP_CODE) J1939Tp_BamRxMain
(
    PduIdType sduIdx
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    J1939Tp_RxSduStateType* rxSduState = &J1939Tp_RxSduState[sduIdx];

    if( TRUE == rxSduState->Aborted )
    {
        if( J1939TP_STATE_BAM_DATA == rxSduState->State )
        {
            rxSduState->State = J1939TP_STATE_FINISH;

            PduR_J1939TpRxIndication(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, E_NOT_OK);

            rxSduState->State = J1939TP_STATE_IDLE;
        }
    }
    else if( J1939TP_ZERO == rxSduState->TimeOut )
    {
        J1939Tp_ReportRuntimeError(J1939TP_SID_MAINFUNCTION, J1939TP_E_TIMEOUT_T1);

        if( J1939TP_STATE_BAM_DATA == rxSduState->State )
        {
            rxSduState->State = J1939TP_STATE_FINISH;

            PduR_J1939TpRxIndication(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, E_NOT_OK);

            rxSduState->State = J1939TP_STATE_IDLE;
        }
    }
    else
    {
        --rxSduState->TimeOut;
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_BamRxIndication
*
* Explanation: This functions sends the Rx indication.
*
* param: pduIdx: ID of the received I-PDU.
*        info: Contains the length (SduLength) of the received I-PDU and a pointer
*              to a buffer (SduDataPtr) containing the I-PDU.
*        pduType: TPCM or TPDT.
*        sa: source address.
*        da: destination address.
*
* retval: None
********************************************************************************
*/
FUNC(void, J1939TP_CODE) J1939Tp_BamRxIndication
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Dir4.5" */
    PduIdType pduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    uint8 pduType,
    uint8 sa,
    uint8 da
)
{
    uint16 sduIdx = J1939TP_ZERO;
    uint16 size = J1939TP_ZERO;
    uint32 pgn = J1939TP_ZERO;
    J1939Tp_RxSduStateType* rxSduState = NULL_PTR;

    J1939TP_DUMMY_STATEMENT(pduIdx);
    J1939TP_DUMMY_STATEMENT(da);

    if( J1939TP_NPDU_LENGTH == info->SduLength )
    {
        pgn = J1939Tp_Get_PGN(info->SduDataPtr[J1939TP_TPCM_PGN_LO],
                                info->SduDataPtr[J1939TP_TPCM_PGN_MD],
                                info->SduDataPtr[J1939TP_TPCM_PGN_HI]);

        if( J1939TP_TPCM_PDUTYPEOFTXPDU == pduType )
        {
            if( (uint8)J1939TP_CB_BAM == info->SduDataPtr[J1939TP_TPCM_CB] )
            {
                if( !J1939Tp_PGN_Valid(pgn) )
                {
                    J1939Tp_ReportRuntimeError(J1939TP_SID_RXINDICATION, J1939TP_E_INVALID_PGN);
                }
                else
                {
                    size = J1939Tp_Get_TMS(info->SduDataPtr[J1939TP_TPCM_TMS_LO],
                                            info->SduDataPtr[J1939TP_TPCM_TMS_HI]);

                    if( size > J1939TP_MAX_LENGTH )
                    {
                        J1939Tp_ReportRuntimeError(J1939TP_SID_RXINDICATION, J1939TP_E_INVALID_TMS);
                    }
                    else
                    {
                        sduIdx = J1939Tp_BamGetRxSduIdx_TPCM(sa, pgn);
                        if( J1939TP_FINDSDUIDX_ERROR != sduIdx )
                        {
                            rxSduState = &J1939Tp_RxSduState[sduIdx];
                            J1939Tp_BamInternalRxIndication_ReceiveTpCmBam(sduIdx, info, sa, size, rxSduState);
                        }
                    }
                }
            }
        }
        else /* if (pduType == J1939TP_TPDT_PDUTYPEOFRXPDU) */
        {
            sduIdx = J1939Tp_BamGetRxSduIdx_TPDT(sa);
            if( J1939TP_FINDSDUIDX_ERROR != sduIdx )
            {
                rxSduState = &J1939Tp_RxSduState[sduIdx];
                J1939Tp_BamInternalRxIndication_ReceiveTpDt(sduIdx, info, rxSduState);
            }
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_BamGetRxSduIdx_TPCM
*
* Explanation: Find rx sduIdx in Bam process.
*
* param: sa: source address.
* retval: sduIdx:  J1939TP_FINDSDUIDX_ERROR: Find faild.
*                  other: RxsduIndex.
********************************************************************************
*/
static FUNC(uint16, J1939TP_CODE) J1939Tp_BamGetRxSduIdx_TPCM
(
    uint8 sa,
    uint32 pgn
)
{
    boolean findFlag = FALSE;
    uint16 channelIdx;
    uint16 sduIdx = J1939TP_FINDSDUIDX_ERROR;
    uint16 netWork = J1939TP_FINDSDUIDX_ERROR;

    J1939Tp_RxSduStateType* rxSduState;

    for( channelIdx = J1939TP_ZERO; channelIdx < J1939TP_RXCHANNEL_NUMBER; channelIdx++ )
    {
        if( J1939TP_PROTOCOL_CMDT != J1939Tp_RxChannel[channelIdx].rxProtocolType )
        {
            /* SWS_J1939Tp_00173 */
          /* Have metadata , configured . no metadata ,configured */
          if(((sa == J1939Tp_RxChannel[channelIdx].rxSa) && (J1939TP_NO_ADDRESS_CONFIGURED > J1939Tp_RxChannel[channelIdx].rxSa)) ||
            /* Have metadata,no config. No metadata ,no config */
            ((J1939TP_NO_ADDRESS_CONFIGURED >= sa) && (J1939TP_NO_ADDRESS_CONFIGURED == J1939Tp_RxChannel[channelIdx].rxSa)) )

            {
                /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
                uint16 sduStartIdx = J1939Tp_RxChannel[channelIdx].startOfRxSduIdx;
                /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
                uint16 sduEndIdx = J1939Tp_RxChannel[channelIdx].endOfRxSduIdx;
                for( sduIdx = sduStartIdx; sduIdx < sduEndIdx; sduIdx++ )
                {
                    rxSduState = &J1939Tp_RxSduState[sduIdx];
                    if( (((uint32)((rxSduState)->State) & (uint32)J1939TP_STATEMASK_BAM) != (uint32)J1939TP_STATE_IDLE) &&
                        ((rxSduState)->Sender == sa) )
                    {
                        if( J1939TP_STATE_BAM_DATA == rxSduState->State )
                        {
                            rxSduState->State = J1939TP_STATE_IDLE;
                        }
                        else
                        {
                            rxSduState->Aborted = TRUE;
                        }
                    }

                    if( (FALSE == findFlag) && (pgn == J1939Tp_RxSduInfo[sduIdx].rxPgPgn) )
                    {
                        findFlag = TRUE;

                        if( J1939TP_STATE_IDLE == rxSduState->State )
                        {
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
* Function Name: J1939Tp_BamGetRxSduIdx_TPDT
*
* Explanation: Find rx sduIdx in Bam process.
*
* param: sa: source address.
* retval: sduIdx:  J1939TP_FINDSDUIDX_ERROR: Find faild.
*                  other: RxsduIndex.
********************************************************************************
*/
static FUNC(uint16, J1939TP_CODE) J1939Tp_BamGetRxSduIdx_TPDT
(
    uint8 sa
)
{
    uint16 network = J1939TP_FINDSDUIDX_ERROR;
    uint16 sduIdx = J1939TP_FINDSDUIDX_ERROR;
    J1939Tp_RxSduStateType* rxSduState;

    for( sduIdx = J1939TP_ZERO; sduIdx < J1939TP_RXNSDU_NUMBER; sduIdx++ )
    {
        rxSduState = &J1939Tp_RxSduState[sduIdx];

        if( (((uint32)((rxSduState)->State) & (uint32)J1939TP_STATEMASK_BAM) != (uint32)J1939TP_STATE_IDLE) &&
             ((rxSduState)->Sender == sa) )
        {
            network = sduIdx;
            /* Find sucess. */
            break;
        }
    }

    return network;
}

/*
********************************************************************************
* Function Name: J1939Tp_BamInternalRxIndication_ReceiveTpDt
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
static FUNC(void, J1939TP_CODE) J1939Tp_BamInternalRxIndication_ReceiveTpDt
(
    PduIdType sduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    J1939Tp_RxSduStateType* rxSduState
)
{
    BufReq_ReturnType tpResult;
    PduInfoType pdu = {NULL_PTR, J1939TP_ZERO};

    if( J1939TP_STATE_BAM_DATA == rxSduState->State )
    {
        /* Protected against concurrent timeout and concurrent reception of TP.CM message */
        rxSduState->State = J1939TP_STATE_BAM_DATA_BUSY;

        if( TRUE == rxSduState->Aborted )
        {
            /* No protection required - transition from uninterruptible state */
            rxSduState->State = J1939TP_STATE_FINISH;

            PduR_J1939TpRxIndication(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, E_NOT_OK);

            /* No protection required - transition from uninterruptible state */
            rxSduState->State = J1939TP_STATE_IDLE;
        }
        else
        {
            rxSduState->Sequence++;

            if( rxSduState->Sequence == info->SduDataPtr[J1939TP_TPDT_SEQ] )
            {
                pdu.SduDataPtr = &info->SduDataPtr[J1939TP_TPDT_DATA];
                pdu.SduLength = J1939TP_TPDT_DATA_SIZE;

                if( rxSduState->Sequence == rxSduState->Packets )
                {
                    pdu.SduLength
                      = (PduLengthType)((rxSduState->Size) - (((uint32)(rxSduState->Sequence) - J1939TP_ONE) * J1939TP_TPDT_DATA_SIZE));
                }

                tpResult = PduR_J1939TpCopyRxData(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, &pdu, (uint32*)&rxSduState->BufSize);

                if( tpResult == BUFREQ_OK )
                {
                    if( rxSduState->Sequence == rxSduState->Packets )
                    {
                        /* No protection required - transition from uninterruptible state */
                        rxSduState->State = J1939TP_STATE_FINISH;

                        PduR_J1939TpRxIndication(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, E_OK);

                        /* No protection required - transition from uninterruptible state */
                        rxSduState->State = J1939TP_STATE_IDLE;
                    }
                    else
                    {
                        rxSduState->TimeOut = J1939Tp_GetTime_T1(); /*!< \trace SPEC-2167345 */
                        /* No protection required - transition from uninterruptible state */
                        rxSduState->State = J1939TP_STATE_BAM_DATA;
                    }
                }
                else
                {
                    /* No protection required - transition from uninterruptible state */
                    rxSduState->State = J1939TP_STATE_FINISH;

                    PduR_J1939TpRxIndication(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, E_NOT_OK);

                    /* No protection required - transition from uninterruptible state */
                    rxSduState->State = J1939TP_STATE_IDLE;
                }
            }
            else
            {
                /* No protection required - transition from uninterruptible state */
                rxSduState->State = J1939TP_STATE_FINISH;

                J1939Tp_ReportRuntimeError(J1939TP_SID_RXINDICATION, J1939TP_E_INVALID_SN);

                PduR_J1939TpRxIndication(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, E_NOT_OK);

                /* No protection required - transition from uninterruptible state */
                rxSduState->State = J1939TP_STATE_IDLE;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_BamInternalRxIndication_ReceiveTpCmBam
*
* Explanation: This functions Receive TpCm Bam.
*
* param: sduIdx: ID of the Rx SDU.
*        info: Contains the length (SduLength) of the received I-PDU and a pointer
*              to a buffer (SduDataPtr) containing the I-PDU.
*        sa: source address.
*        size: sdu size.
*        rxSduState: rx sdu state.
* retval: None
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_BamInternalRxIndication_ReceiveTpCmBam
(
    uint16 sduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    uint8 sa,
    uint16 size,
    J1939Tp_RxSduStateType* rxSduState
)
{
    BufReq_ReturnType tpResult;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint8 packets = (uint8)J1939Tp_Get_Packets(size);
    PduInfoType addrInfo;

    addrInfo.SduLength = J1939Tp_RxSduInfo[sduIdx].metaDataLength;
    addrInfo.SduDataPtr = &(info->SduDataPtr[J1939TP_NPDU_MDL_POS]);

    tpResult = PduR_J1939TpStartOfReception(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx,
                                            &addrInfo,
                                            (PduLengthType) size,
                                            (uint32*)&rxSduState->BufSize);
    if( BUFREQ_OK == tpResult )
    {

        /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
        uint16 pduLength =
          J1939Tp_Get_TMS(info->SduDataPtr[J1939TP_TPCM_TMS_LO], info->SduDataPtr[J1939TP_TPCM_TMS_HI]);

        if( rxSduState->BufSize >= pduLength )
        {
            rxSduState->Size = size;
            rxSduState->Packets = packets;
            rxSduState->Sender = sa;
            rxSduState->Receiver = J1939TP_BROADCAST_ADDRESS;
            rxSduState->Sequence = J1939TP_ZERO;

            rxSduState->TimeOut = J1939Tp_GetTime_T1();
            /* No protection required - transition from uninterruptible state. */
            rxSduState->State = J1939TP_STATE_BAM_DATA;
        }
        else
        {   /* SWS_J1939Tp_00040, Abort recive. */
            rxSduState->State = J1939TP_STATE_IDLE;
        }
    }
    else
    {
        /* No protection required - transition from uninterruptible state. */
        rxSduState->State = J1939TP_STATE_IDLE;
    }
}
#endif  /* J1939TP_BAM_RX_ENABLED == STD_ON */

#define J1939TP_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

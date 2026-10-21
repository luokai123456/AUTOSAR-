/*
********************************************************************************
*
* File name: J1939Tp.c
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
* Change: New created
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: yong.zhang/2019.06.11
* Change: Modify QAC Check Warning.
* Cause: Revision
********************************************************************************
* Version: 1.2
* Author/Date: li.zhiheng/2020.01.09
* Change: Modify PduR_J1939TpTxConfirmation parameter.
* Cause: Update
********************************************************************************
* Version: 1.3
* Author/Date: li.zhiheng/2020.03.26
* Change: Modify the code according to QAC.
* Cause: Update
********************************************************************************
* Version: 3.0
* Author/Date: li.zhiheng/2020.03.30
* Change: 1.Add notes.
*         2.Perform a QAC check and correct any errors that occur.
* Cause: Clear QAC warning.
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
* Author/Date: LiZH/2020.11.02
* Change: Modify the mapmap to contain the processing of the initialization variable.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: LiZH/2020.11.04
* Change: Delete the function declaration contained in MemMap.h.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: LiZH/2020.11.04
* Change: Optimized coding specification.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: LiZH/2021.04.27
* Change: 1.Add Rx sdu init.
*         2.Add J1939Tp_CancelReceive, J1939Tp_CancelTransmit parameter check.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: LiZH/2021.05.10
* Change: 1.Modifty J1939TP_PROTOCOL_CMDT, J1939TP_PROTOCOL_BAM name.
*         2.Modifty J1939Tp_RxIndication_Process functiom process sequence.
*         3.J1939Tp_CancelReceive, J1939Tp_CancelTransmit set state to Idle.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: LiZH/2021.05.11
* Change: 1.Add rx indication direct type check.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: LiZH/2021.05.25
* Change: 1.Add J1939Tp_TxTransmit_NoMetaData,J1939Tp_TxTransmit_WithMetaData function in J1939Tp_InternalTransmit.
*         2.Cancel TxInfoPtr check null in J1939Tp_Transmit.
*         3.Modifty J1939Tp_ChangeParameter, J1939Tp_CancelReceive, J1939Tp_CancelTransmit
*           errorId J1939TP_E_INVALID_PDU_SDU_ID.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: LiZH/2021.05.25
* Change: Modify the scope of Channel index.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: LiZH/2021.05.29
* Change: Modify check RxPduId rang in J1939Tp_RxIndication.
* Cause: Bugfix
********************************************************************************
* Version: 3.14
* Author/Date: LiZH/2021.06.02
* Change: Modify J1939Tp_TxTransmit_NoMetaData no cfg da process.
* Cause: Bugfix
********************************************************************************
* Version: 3.15
* Author/Date: LiZH/2021.06.28
* Change: Add find sduindx mode according to PduR.
* Cause: Bugfix
********************************************************************************
* Version: 3.16
* Author/Date: Li.ZH/2021.8.16
* Change: Modification code specification.
* Cause: Optimize
********************************************************************************
* Version: 3.17
* Author/Date: TongXY/2022.10.28
* Change: Modify the range of local variable 'length' in J1939Tp_TxTransmit_NoMetaData.
* Cause: Bugfix
********************************************************************************
* Version: 3.18
* Author/Date: TongXY/2022.10.31
* Change: Add macro switch for J1939Tp_DirectTransmit.
* Cause: Bugfix
********************************************************************************
* Version: 3.19
* Author/Date: TongXY/2023.3.14
* Change: 1.Added the functions of retransmission and dynamic length packet sending.
*         2.Modify compilation warning.
*         3.Modified qac warning.
*         4.Fix coding specification problems.
* Cause: Optimization
********************************************************************************
* Version: 3.20
* Author/Date: TongXY/2023.4.13
* Change: Fixed inclusion range of precompiled macro J1939TP_CANCELLATION_SUPPORT.
* Cause: Bugfix
********************************************************************************
* Version: 3.21
* Author/Date: TongXY/2023.05.24
* Change: 1.Memmap macro value to all uppercase.
*         2.To see if they are equal, we put the constant on the left.
* Cause: Optimization
********************************************************************************
* Version: 3.22
* Author/Date: YanCL/2024.3.19
* Change: Modify the P2CONST incorrect labels.
* Cause: Optimization
********************************************************************************
* Version: 3.23
* Author/Date: YanCL/2024.4.2
* Change: 1.Modify the P2CONST incorrect labels.
*         2.Modify the annotation.
* Cause: Optimization
********************************************************************************
* Version: 3.24
* Author/Date: YanCL/2024.5.24
* Change: 1.Initialize the TpDtCount member in the J1939Tp_TxSduStateType structure.
*         2.Adjusting the parameter positions of function declarations.
* Cause: Update
********************************************************************************
* Version: 3.25
* Author/Date: YanCL/2024.6.25
* Change: 1.Add copyright information.
*         2.Add Memmap segment definition.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date: YanCL/2024.10.11
* Change: Modify the functions memclass of J1939Tp_ReportDevError() and
*         J939Tp_ReportRuntimeError().
* Cause: Update
********************************************************************************
* Version: 3.27
* Author/Date: YanCL/2025.03.26
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.28
* Author/Date: YanCL/2025.06.06
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.29
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
#include "J1939Tp.h"
#include "J1939Tp_Cbk.h"
#include "J1939Tp_Int.h"

#if (J1939TP_CMDT_ENABLED == STD_ON)
#include "J1939Tp_Cmdt.h"
#endif

#if (J1939TP_BAM_ENABLED == STD_ON)
#include "J1939Tp_Bam.h"
#endif

#if (J1939TP_DIRECT_ENABLED == STD_ON)
#include "J1939Tp_Direct.h"
#endif

#include "PduR_J1939Tp.h"  /* SWS_J1939Tp_00015 */
#include "CanIf.h"         /* SWS_J1939Tp_00172 */

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/* The J1939Tp module shall have two global states, J1939TP_ON and J1939TP_OFF. */
#define J1939TP_OFF                             (0U)
#define J1939TP_ON                              (1U)

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
#define J1939TP_START_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"

/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_J1939Tp_NonSharedVar" */
static VAR(uint8, J1939TP_VAR_INIT) J1939Tp_ModuleInitState = J1939TP_OFF;

#define J1939TP_STOP_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

static FUNC(void, J1939TP_CODE) J1939Tp_InternalMain_TxPdu(void);
static FUNC(void, J1939TP_CODE) J1939Tp_InternalMain_TxSdu(void);
static FUNC(Std_ReturnType, J1939TP_CODE) J1939Tp_InternalTransmit
(
    PduIdType txSduId,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) pduInfoPtr
);
static FUNC(void, J1939TP_CODE) J1939Tp_InternalMain_RxSdu(void);
static FUNC(void, J1939TP_CODE) J1939Tp_RxIndication_Process
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) PduInfoPtr
);
static FUNC(void, J1939TP_CODE) J1939Tp_TxConfirmation_Process
(
    PduIdType TxPduId,
    PduIdType sduIdx,
    J1939Tp_NSduType sduType
);
static FUNC(Std_ReturnType, J1939TP_CODE) J1939Tp_TxTransmit_WithMetaData
(
    PduIdType txSduId,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) pduInfoPtr
);
static FUNC(Std_ReturnType, J1939TP_CODE) J1939Tp_TxTransmit_NoMetaData
(
    PduIdType txSduId,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) pduInfoPtr
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
* Function Name: J1939Tp_ReportDevError
*
* Explanation: Report error to Det Module.
*
* param: apiId: The Api Id of J1939Tp.
*        errorId: Error Id defined in J1939Tp.h.
*
* retval: None
********************************************************************************
*/
FUNC(void, J1939TP_CODE) J1939Tp_ReportDevError(uint8 apiId, uint8 errorId)  /* PRQA S 1505 */ /* NSCA_QAC_Common_Rule8.7 */
{

#if( J1939TP_DEV_ERROR_REPORT == STD_ON )
    if( J1939TP_E_NO_ERROR != errorId )
    {
        (void)Det_ReportError(J1939TP_MODULE_ID, J1939TP_INSTANCE_ID_DET, apiId, errorId);
    }
#else
    {
        J1939TP_DUMMY_STATEMENT(apiId);
        J1939TP_DUMMY_STATEMENT(errorId);
    }
#endif
}

/*
********************************************************************************
* Function Name: J1939Tp_ReportRuntimeError
*
* Explanation: Report error to Det Module.
*
* param: apiId: The Api Id of J1939Tp.
*        errorId: Error Id defined in J1939Tp.h.
*
* retval: None
********************************************************************************
*/
FUNC(void, J1939TP_CODE) J1939Tp_ReportRuntimeError(uint8 apiId, uint8 errorId)  /* PRQA S 1505 */ /* NSCA_QAC_Common_Rule8.7 */
{

#if( J1939TP_RUNTIME_ERROR_REPORT == STD_ON )
    if( J1939TP_E_NO_ERROR != errorId )
    {
        (void)Det_ReportRuntimeError(J1939TP_MODULE_ID, J1939TP_INSTANCE_ID_DET, apiId, errorId);
    }
#else
    {
        J1939TP_DUMMY_STATEMENT(apiId);
        J1939TP_DUMMY_STATEMENT(errorId);
    }
#endif
}

/*
********************************************************************************
* Function Name: J1939Tp_InternalMain_TxPdu
*
* Explanation: Internal process main tx pdu.
*
* param: void
* retval: void
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_InternalMain_TxPdu
(
    void
)
{
    uint8 txPduIdx;
    PduIdType sduIdx;
    J1939Tp_TxPduStateType* pduState = NULL_PTR;
    J1939Tp_RxSduStateType* rxSduState = NULL_PTR;
    J1939Tp_TxSduStateType* txSduState = NULL_PTR;

    for( txPduIdx = J1939TP_ZERO; txPduIdx < J1939TP_TXPDU_NUM; txPduIdx++ )
    {
        pduState = &J1939Tp_TxPduState[txPduIdx];

        /* Pdu locked. */
        if( (boolean)TRUE == pduState->Locked )
        {
            --pduState->ConfTimeout;

            /* Timeout. */
            if( J1939TP_ZERO == pduState->ConfTimeout )
            {
                sduIdx = pduState->CurrentNSduId;
                /* Lock pdu state. */
                pduState->Locked = FALSE;

                /* Pdu type. */
                /* Polyspace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule16.1" */
                switch( pduState->CurrentNSduType )
                {
                    case J1939TP_NSDU_CMDT_RX:
                        rxSduState = &J1939Tp_RxSduState[sduIdx];
                        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_J1939Tp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_J1939Tp_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_J1939Tp_OBAI" */
                        PduR_J1939TpRxIndication(J1939Tp_RxSduInfo[sduIdx].rxNSduIdx, E_NOT_OK);
                        rxSduState->State = J1939TP_STATE_IDLE;

                        break;
                    case J1939TP_NSDU_BAM:
                    case J1939TP_NSDU_DIRECT:
                    case J1939TP_NSDU_CMDT_TX:
                        txSduState = &J1939Tp_TxSduState[sduIdx];
                        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_J1939Tp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_J1939Tp_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_J1939Tp_OBAI" */
                        PduR_J1939TpTxConfirmation((J1939Tp_TxSduInfo[sduIdx].txNSduIdx), E_NOT_OK);
                        txSduState->State = J1939TP_STATE_IDLE;

                        break;
                    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    default:
                        /* Do Nothing. */
                        break;
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_InternalMain_TxSdu
*
* Explanation: Internal process main tx sdu.
*
* param: void
* retval: void
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_InternalMain_TxSdu
(
    void
)
{
    uint8 txSduIdx;
    J1939Tp_TxSduStateType* txSduState = NULL_PTR;

    for( txSduIdx = J1939TP_ZERO; txSduIdx < J1939TP_TXNSDU_NUMBER; txSduIdx++ )
    {
        txSduState = &J1939Tp_TxSduState[txSduIdx];

#if (J1939TP_CMDT_TX_ENABLED == STD_ON)
        /* In CMDT state and not in confirm state */
        if( (((uint32)(txSduState->State) & (uint32)J1939TP_STATEMASK_CMDT) != (uint32)J1939TP_STATE_IDLE) &&
            ((uint32)J1939TP_STATE_IDLE == ((uint32)(txSduState->State) & (uint32)J1939TP_STATEMASK_CONF)) )
        {
            J1939Tp_CmdtTxMain(txSduIdx);
        }
#endif  /* J1939TP_CMDT_TX_ENABLED == STD_ON */

#if (J1939TP_BAM_TX_ENABLED == STD_ON)
        /* In BAM state and not in confirm state */
        if( (((uint32)(txSduState->State) & (uint32)J1939TP_STATEMASK_BAM) != (uint32)J1939TP_STATE_IDLE) &&
            ((uint32)J1939TP_STATE_IDLE == ((uint32)(txSduState->State) & (uint32)J1939TP_STATEMASK_CONF)) )
        {
            J1939Tp_BamTxMain(txSduIdx);
        }
#endif  /* J1939TP_BAM_TX_ENABLED == STD_ON */

#if (J1939TP_DIRECT_TX_ENABLED == STD_ON)
        if( (((uint32)(txSduState->State) & (uint32)J1939TP_STATEMASK_DIRECT) != (uint32)J1939TP_STATE_IDLE) &&
            ((uint32)J1939TP_STATE_IDLE == ((uint32)(txSduState->State) & (uint32)J1939TP_STATEMASK_CONF)))
        {
            J1939Tp_DirectTxMain(txSduIdx);
        }
#endif  /* J1939TP_DIRECT_TX_ENABLED == STD_ON */
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_InternalTransmit
*
* Explanation: Internal transmit sdu.
*
* param: txSduId:  ID of the send SDU.
*        PduInfoPtr: Contains the length (SduLength) of the received I-PDU
*                    and a pointer to a buffer (SduDataPtr) containing the I-PDU.
* retval: Std_ReturnType
********************************************************************************
*/
static FUNC(Std_ReturnType, J1939TP_CODE) J1939Tp_InternalTransmit
(
    PduIdType txSduId,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) pduInfoPtr
)
{
    Std_ReturnType result = E_NOT_OK;

    /* No Cfg metaData. */
    if( NULL_PTR == pduInfoPtr->SduDataPtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        result = J1939Tp_TxTransmit_NoMetaData(txSduId, pduInfoPtr);
    }
    /* Cfg metaData. */
    else
    {
        result = J1939Tp_TxTransmit_WithMetaData(txSduId, pduInfoPtr);
    }

    return result;
}

/*
********************************************************************************
* Function Name: J1939Tp_TxTransmit_NoMetaData
*
* Explanation: Internal transmit sdu no metedata.
*
* param: txSduId:  ID of the send SDU.
*        PduInfoPtr: Contains the length (SduLength) of the received I-PDU
*                    and a pointer to a buffer (SduDataPtr) containing the I-PDU.
* retval: Std_ReturnType
********************************************************************************
*/
static FUNC(Std_ReturnType, J1939TP_CODE) J1939Tp_TxTransmit_NoMetaData
(
    PduIdType txSduId,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) pduInfoPtr
)
{
    uint8 sa = J1939TP_NO_ADDRESS_CONFIGURED;
    uint8 da = J1939TP_NO_ADDRESS_CONFIGURED;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint8 pri = J1939TP_DEFAULT_PRIORITY;
    Std_ReturnType result = E_NOT_OK;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 channelIdx = J1939Tp_TxSduInfo[txSduId].txSduOfChannelIdx;

    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint8 dataBuffer[J1939TP_FF] = {J1939TP_ZERO};
    PduInfoType pduInfo;
    pduInfo.SduDataPtr = dataBuffer;
    pduInfo.SduLength = pduInfoPtr->SduLength;

    /* Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule14.3" Polyspace +1 DEFECT:USELESS_IF [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
    if( J1939TP_NO_ADDRESS_CONFIGURED != J1939Tp_TxChannel[channelIdx].txSa )
    {
        sa = J1939Tp_TxChannel[channelIdx].txSa;
    }
    /* Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule14.3" Polyspace +1 DEFECT:USELESS_IF [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
    if( J1939TP_NO_ADDRESS_CONFIGURED != J1939Tp_TxChannel[channelIdx].txDa )
    {
        da = J1939Tp_TxChannel[channelIdx].txDa;
    }

    if( J1939TP_PROTOCOL_BAM == J1939Tp_TxChannel[channelIdx].txProtocolType )
    {
        da = J1939TP_BROADCAST_ADDRESS;
    }

    /* If the length is less than 8, the length is treated as direct transmission. */
    if( pduInfo.SduLength <= J1939T_8BYTE_LENGTH )
    {
#if (J1939TP_DIRECT_TX_ENABLED == STD_ON)
        result = J1939Tp_DirectTransmit(txSduId, (const PduInfoType*)&pduInfo, sa, da, pri);
#endif  /* J1939TP_DIRECT_TX_ENABLED == STD_ON */
    }
    else
    {   /* SWS_J1939Tp_00039 */
        if( J1939TP_BROADCAST_ADDRESS != da )
        {
#if (J1939TP_CMDT_TX_ENABLED == STD_ON)
            result = J1939Tp_CmdtTransmit(txSduId, (const PduInfoType*)&pduInfo, sa, da, pri);
#endif  /* J1939TP_CMDT_TX_ENABLED == STD_ON */
        }
        else
        {
#if (J1939TP_BAM_TX_ENABLED == STD_ON)
            result = J1939Tp_BamTransmit(txSduId, (const PduInfoType*)&pduInfo, sa, pri);
#endif  /* J1939TP_BAM_TX_ENABLED == STD_ON */
        }
    }

    return result;
}

/*
********************************************************************************
* Function Name: J1939Tp_TxTransmit_WithMetaData
*
* Explanation: Internal transmit sdu with metedata.
*
* param: txSduId:  ID of the send SDU.
*        PduInfoPtr: Contains the length (SduLength) of the received I-PDU
*                    and a pointer to a buffer (SduDataPtr) containing the I-PDU.
* retval: Std_ReturnType
********************************************************************************
*/
static FUNC(Std_ReturnType, J1939TP_CODE) J1939Tp_TxTransmit_WithMetaData
(
    PduIdType txSduId,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) pduInfoPtr
)
{
    uint8 sa = J1939TP_NO_ADDRESS_CONFIGURED;
    uint8 da = J1939TP_NO_ADDRESS_CONFIGURED;
    uint8 pri = J1939TP_DEFAULT_PRIORITY;
    Std_ReturnType result = E_NOT_OK;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
    uint16 channelIdx = J1939Tp_TxSduInfo[txSduId].txSduOfChannelIdx;

    /* Check length. */
    if( pduInfoPtr->SduLength > J1939TP_MAX_LENGTH )
    {
        J1939Tp_ReportDevError(J1939TP_SID_TRANSMIT, J1939TP_E_INVALID_LENGTH);
    }
    else
    {
        /* SWS_J1939Tp_00039 */
        /* Get Sa. */
        /* Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule14.3" Polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
        if( J1939TP_NO_ADDRESS_CONFIGURED != J1939Tp_TxChannel[channelIdx].txSa )
        {
            sa = J1939Tp_TxChannel[channelIdx].txSa;
        /* Polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        }
        else
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {   /* Config Last one byte. */
            if( J1939Tp_TxSduInfo[txSduId].metaDataLength >= J1939TP_ONE )
            {
                sa = pduInfoPtr->SduDataPtr[J1939TP_MDL_SA_POS];
            }
        }

        /* Get Da. */
        /* Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule14.3" Polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
        if( J1939TP_NO_ADDRESS_CONFIGURED != J1939Tp_TxChannel[channelIdx].txDa )
        {
            da = J1939Tp_TxChannel[channelIdx].txDa;
        /* Polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        }
        else
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            if( J1939Tp_TxSduInfo[txSduId].metaDataLength >= J1939TP_TWO )
            {
                da = pduInfoPtr->SduDataPtr[J1939TP_MDL_DA_POS];
            }
        }

        /* Get Pri. */
        /* Polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule14.3" Polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
        if( J1939TP_FOUR == J1939Tp_TxSduInfo[txSduId].metaDataLength )
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            pri = J1939Tp_MDL_Get_PRI(pduInfoPtr->SduDataPtr[J1939TP_MDL_PRI_POS]);
        }

        /* If the length is less than 8, the length is treated as direct transmission. */
        if( pduInfoPtr->SduLength <= J1939T_8BYTE_LENGTH )
        {
#if (J1939TP_DIRECT_TX_ENABLED == STD_ON)
            result = J1939Tp_DirectTransmit(txSduId, pduInfoPtr, sa, da, pri);
#endif  /* J1939TP_DIRECT_TX_ENABLED == STD_ON */
        }
        else
        {
            /* If the transport protocol is not configured, it shall be chosen based on
               the actual DA: BAM when DA is 0xFF, CMDT otherwise. */
            /* Polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule14.3" Polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
            if( J1939TP_PROTOCOL_NONE == J1939Tp_TxChannel[channelIdx].txProtocolType )
            /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                if( J1939TP_BROADCAST_ADDRESS == da )
                {
#if (J1939TP_BAM_TX_ENABLED == STD_ON)
                    result = J1939Tp_BamTransmit(txSduId, pduInfoPtr, sa, pri);
#endif  /* J1939TP_BAM_TX_ENABLED == STD_ON */
                }
                else
                {
#if (J1939TP_CMDT_TX_ENABLED == STD_ON)
                    result = J1939Tp_CmdtTransmit(txSduId, pduInfoPtr, sa, da, pri);
#endif  /* J1939TP_CMDT_TX_ENABLED == STD_ON */
                }
            }
            else  /* Config channel transmission type. */
            {
                /* CMDT process. */
                if( J1939TP_PROTOCOL_CMDT == J1939Tp_TxChannel[channelIdx].txProtocolType )
                {
#if (J1939TP_CMDT_TX_ENABLED == STD_ON)
                     result = J1939Tp_CmdtTransmit(txSduId, pduInfoPtr, sa, da, pri);
#endif  /* J1939TP_CMDT_TX_ENABLED == STD_ON */

                }
                /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                else if( J1939TP_PROTOCOL_BAM == J1939Tp_TxChannel[channelIdx].txProtocolType )
                {
#if (J1939TP_BAM_TX_ENABLED == STD_ON)
                     result = J1939Tp_BamTransmit(txSduId, pduInfoPtr, sa, pri);
#endif  /* J1939TP_BAM_TX_ENABLED == STD_ON */
                }
                else
                {
                     /* Do nothing. */
                }
            }
        }
    }

    return result;
}

/*
********************************************************************************
* Function Name: J1939Tp_TxConfirmation
*
* Explanation: The lower layer communication interface module confirms the
*              transmission of an IPDU.
*
* param: TxPduId: Pointer to configuration data structure.
*        sduIdx: id of sdu.
*        sduType: sdu type.
* retval: void
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_TxConfirmation_Process
(
    PduIdType TxPduId,
    PduIdType sduIdx,
    J1939Tp_NSduType sduType
)
{
    switch( (J1939Tp_TxPdu[TxPduId].PduTypeOfTxPdu) )
    {
        case J1939TP_TPCM_PDUTYPEOFTXPDU:
        {
#if (J1939TP_CMDT_TX_ENABLED == STD_ON) /* CMDT_TX */
            if( J1939TP_NSDU_CMDT_TX == sduType )
            {
                /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
                J1939Tp_TxSduStateType* txSduState = &J1939Tp_TxSduState[sduIdx];

                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_J1939Tp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_J1939Tp_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_J1939Tp_IDP" */
                if( ((uint32)(txSduState->State) & (uint32)J1939TP_STATEMASK_CMDT) != (uint32)J1939TP_STATE_IDLE )
                {
                    J1939Tp_CmdtTxConfirmation(sduIdx, J1939TP_TPCM_PDUTYPEOFTXPDU, sduType);
                }
            }
#endif  /* J1939TP_CMDT_TX_ENABLED == STD_ON */

#if (J1939TP_BAM_TX_ENABLED == STD_ON) /* BAM */
            if( J1939TP_NSDU_BAM == sduType )
            {
                /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
                J1939Tp_TxSduStateType* txSduState = &J1939Tp_TxSduState[sduIdx];

                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_J1939Tp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_J1939Tp_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_J1939Tp_IDP" */
                if( ((uint32)(txSduState->State) & (uint32)J1939TP_STATEMASK_BAM) != (uint32)J1939TP_STATE_IDLE )
                {
                    J1939Tp_BamTxConfirmation(sduIdx, J1939TP_TPCM_PDUTYPEOFTXPDU);
                }
            }
#endif  /* J1939TP_BAM_TX_ENABLED == STD_ON */

#if (J1939TP_CMDT_RX_ENABLED == STD_ON) /* CMDT_RX */
            if( J1939TP_NSDU_CMDT_RX == sduType )
            {
                /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
                J1939Tp_RxSduStateType* rxSduState = &J1939Tp_RxSduState[sduIdx];

                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_J1939Tp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_J1939Tp_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_J1939Tp_IDP" */
                if( ((uint32)(rxSduState->State) & (uint32)J1939TP_STATEMASK_CMDT) != (uint32)J1939TP_STATE_IDLE )
                {
                    J1939Tp_CmdtTxConfirmation(sduIdx, J1939TP_TPCM_PDUTYPEOFTXPDU, sduType);
                }
            }
#endif  /* J1939TP_CMDT_RX_ENABLED == STD_ON */

            break;
        }
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        case J1939TP_TPDT_PDUTYPEOFTXPDU:
        {
#if (J1939TP_BAM_TX_ENABLED == STD_ON) /* BAM */
            if( J1939TP_NSDU_BAM == sduType )
            {
                /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
                J1939Tp_TxSduStateType* txSduState = &J1939Tp_TxSduState[sduIdx];

                if( ((uint32)(txSduState->State) & (uint32)J1939TP_STATEMASK_BAM) != (uint32)J1939TP_STATE_IDLE )
                {
                    J1939Tp_BamTxConfirmation(sduIdx, J1939TP_TPDT_PDUTYPEOFTXPDU);
                }
            }

#endif  /* J1939TP_CMDT_TX_ENABLED == STD_ON */

#if (J1939TP_CMDT_TX_ENABLED == STD_ON)  /* CMDT. */
            if( J1939TP_NSDU_CMDT_TX == sduType )
            {
                /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
                J1939Tp_TxSduStateType* txSduState = &J1939Tp_TxSduState[sduIdx];

                if( ((uint32)(txSduState->State) & (uint32)J1939TP_STATEMASK_CMDT) != (uint32)J1939TP_STATE_IDLE )
                {
                    J1939Tp_CmdtTxConfirmation(sduIdx, J1939TP_TPDT_PDUTYPEOFTXPDU, sduType);
                }
            }
#endif  /* J1939TP_CMDT_TX_ENABLED == STD_ON */

            break;
        }
#if (J1939TP_DIRECT_TX_ENABLED == STD_ON)
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        case J1939TP_DIRECT_PDUTYPEOFTXPDU:
        {
            /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
            J1939Tp_TxSduStateType* txSduState = &J1939Tp_TxSduState[sduIdx];

            if( ((uint32)(txSduState->State) & (uint32)J1939TP_STATEMASK_DIRECT) != (uint32)J1939TP_STATE_IDLE )
            {
                J1939Tp_DirectTxConfirmation(sduIdx);
            }
            break;
        }
#endif  /* J1939TP_DIRECT_TX_ENABLED == STD_ON */
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        default:
            /* Do Nothing. */
            break;
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_Init
*
* Explanation: This function initializes the J1939Tp module.
*
* param: ConfigPtr: Pointer to configuration data structure.
*
* retval: void
********************************************************************************
*/
FUNC(void, J1939TP_CODE) J1939Tp_Init   /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    P2CONST(J1939Tp_ConfigType, AUTOMATIC, J1939TP_APPL_CONST) ConfigPtr
)
{
    uint8 errorId = J1939TP_E_NO_ERROR;

    uint8 txPduStateIdx;
    uint8 txSduIdx;
    uint8 rxSduIdx;
    J1939Tp_TxPduStateType* pduState = NULL_PTR;
    J1939Tp_TxSduStateType* txSduState = NULL_PTR;
    J1939Tp_RxSduStateType* rxSduState = NULL_PTR;

    /* Dymmy parameterL */
    J1939TP_DUMMY_STATEMENT(ConfigPtr);

    /* Judge j1939 module init. */
    if( J1939TP_ON == J1939Tp_ModuleInitState )
    {
        errorId = J1939TP_E_REINIT;
    }
    else
    {
        /* Init txpdu state. */
        for( txPduStateIdx = J1939TP_ZERO; txPduStateIdx < J1939TP_TXPDU_NUM; txPduStateIdx++ )
        {
            pduState = &J1939Tp_TxPduState[txPduStateIdx];
            pduState->Locked = FALSE;
        }

        /* Init txSdu state. */
        for( txSduIdx = J1939TP_ZERO; txSduIdx < J1939TP_TXNSDU_NUMBER; txSduIdx++ )
        {
            txSduState = &J1939Tp_TxSduState[txSduIdx];
            txSduState->State = J1939TP_STATE_IDLE;
            txSduState->RetryState = J1939TP_DONT_RETRY;
            txSduState->TpDtCount = J1939TP_TPDT_COUNT;
        }

        /* Init rxsdu state. */
        for( rxSduIdx = J1939TP_ZERO; rxSduIdx < J1939TP_RXNSDU_NUMBER; rxSduIdx++ )
        {
            rxSduState = &J1939Tp_RxSduState[rxSduIdx];
            rxSduState->State = J1939TP_STATE_IDLE;
            rxSduState->RetryState = J1939TP_DONT_RETRY;
        }

        /* Set module init. */
        J1939Tp_ModuleInitState = J1939TP_ON;
    }

    /* Dev error report. */
    if( errorId != J1939TP_E_NO_ERROR )
    {
        J1939Tp_ReportDevError(J1939TP_SID_INIT, errorId);
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_Shutdown
*
* Explanation: This function is used to shutdown the J1939Tp module.
*
* param: void
* retval: void
********************************************************************************
*/
FUNC(void, J1939TP_CODE) J1939Tp_Shutdown(void)  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    uint8 errorId = J1939TP_E_NO_ERROR;
    if( J1939TP_OFF == J1939Tp_ModuleInitState )
    {
        errorId = J1939TP_E_UNINIT;
    }
    else
    {
        J1939Tp_ModuleInitState = J1939TP_OFF;  /* SWS_J1939Tp_00094 */
    }

    /* Dev error report. */
    if( errorId != J1939TP_E_NO_ERROR )
    {
        J1939Tp_ReportDevError(J1939TP_SID_SHUTDOWN, errorId);
    }

}

#if(J1939TP_VERSION_INFO_API == STD_ON)
/*
********************************************************************************
* Function Name: J1939Tp_GetVersionInfo
*
* Explanation: Returns the version information of J1939Tp.
*
* param: VersionInfo: Pointer to the location where the version information
*                        of J1939Tp shall be stored.
* retval: void
********************************************************************************
*/
FUNC(void, J1939TP_CODE) J1939Tp_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, J1939TP_APPL_DATA) VersionInfo
)
{
    uint8 errorId = J1939TP_E_NO_ERROR;

    /* Judge null ptr. */
    if( NULL_PTR == VersionInfo )
    {
        errorId = J1939TP_E_PARAM_POINTER;
    }
    else
    {
        /* Get version. */
        VersionInfo->vendorID = J1939TP_VENDOR_ID;
        VersionInfo->moduleID = J1939TP_MODULE_ID;
        VersionInfo->sw_major_version = J1939TP_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = J1939TP_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = J1939TP_SW_PATCH_VERSION;
    }

    /* Dev error report. */
    if( errorId != J1939TP_E_NO_ERROR )
    {
        J1939Tp_ReportDevError(J1939TP_SID_GETVERSIONINFO, errorId);
    }
}
#endif  /* J1939TP_VERSION_INFO_API == STD_ON */

/*
********************************************************************************
* Function Name: J1939Tp_MainFunction
*
* Explanation: Main function of the J1939Tp. Used for scheduling purposes and
*              timeout supervision.
*
* param: void
* retval: void
********************************************************************************
*/
FUNC(void, J1939TP_CODE) J1939Tp_MainFunction(void)
{

    uint8 errorId = J1939TP_E_NO_ERROR;
    /* Judge module init. */
    if( J1939TP_OFF == J1939Tp_ModuleInitState )
    {
        errorId = J1939TP_E_UNINIT;
    }
    else
    {
        /* Send pdu, when tx timeout. */
        J1939Tp_InternalMain_TxPdu();
        /* Send sdu. */
        J1939Tp_InternalMain_TxSdu();
        /* Receive sdu. */
        J1939Tp_InternalMain_RxSdu();
    }

    /* Dev error report. */
    if( errorId != J1939TP_E_NO_ERROR )
    {
        J1939Tp_ReportDevError(J1939TP_SID_MAINFUNCTION, errorId);
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_Transmit
*
* Explanation: This service function is used to request the transfer of a J1939Tp N-SDU.
*
* param: TxSduId: ID of the J1939Tp N-SDU to be transmitted. The available
*                    IDs are configured via J1939TpTxNSduId.
*        TxInfoPtr:  Pointer to structure with length and content of the J1939Tp NSDU
*                    that shall be transmitted. The content of this structure is only
*                    used to transfer addressing information and priority of N-SDUs with
*                    MetaData, and shall be NULL otherwise.
* retval: E_OK: The request has been accepted.
*         E_NOT_OK: The request failed.
********************************************************************************
*/
FUNC(Std_ReturnType, J1939TP_CODE) J1939Tp_Transmit
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Dir4.5" */
    PduIdType TxSduId,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) TxInfoPtr
)
{
    Std_ReturnType result = E_NOT_OK;
    uint8 errorId = J1939TP_E_NO_ERROR;
    boolean flag = FALSE;
    PduIdType network;

    if( J1939TP_OFF == J1939Tp_ModuleInitState )
    {
        errorId = J1939TP_E_UNINIT;
    }
    else if( (NULL_PTR == TxInfoPtr) ||
        /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Dir4.14" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_J1939Tp_TAINTED_PTR" */
        (J1939TP_ZERO == TxInfoPtr->SduLength) )
    {
        errorId = J1939TP_E_PARAM_POINTER;
    }
    else
    {
        for( network = J1939TP_ZERO; network < J1939TP_TXNSDU_NUMBER; network++ )
        {
            if( J1939Tp_TxSduInfo[network].txNSduIdx == TxSduId )
            {
                flag = TRUE;
                break;
            }
        }

        if( TRUE == flag )
        {
            /* Internal transmit. */
            result = J1939Tp_InternalTransmit(network, TxInfoPtr);
        }
        else
        {
            errorId = J1939TP_E_INVALID_PDU_SDU_ID;
        }
    }

    /* Dev error report. */
    if( errorId != J1939TP_E_NO_ERROR )
    {
        J1939Tp_ReportDevError(J1939TP_SID_TRANSMIT, errorId);
    }

    return result;
}

/*
********************************************************************************
* Function Name: J1939Tp_RxIndication
*
* Explanation: Indication of a received I-PDU from a lower layer communication interface module.
*
* param: RxPduId: ID of the received I-PDU.
*        PduInfoPtr: Contains the length (SduLength) of the received I-PDU
*                    and a pointer to a buffer (SduDataPtr) containing the I-PDU.
* retval: void
********************************************************************************
*/
FUNC(void, J1939TP_CODE) J1939Tp_RxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) PduInfoPtr
)
{
    uint8 errorId = J1939TP_E_NO_ERROR;
    uint16 network;
    boolean flag = FALSE;

    /* Judge module init. */
    if( J1939TP_OFF == J1939Tp_ModuleInitState )
    {
        errorId = J1939TP_E_UNINIT;
    }
    /* Juge null ptr. */
    else if( NULL_PTR == PduInfoPtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = J1939TP_E_PARAM_POINTER;
    }
    /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Dir4.14" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_J1939Tp_TAINTED_PTR" */
    else if( NULL_PTR == PduInfoPtr->SduDataPtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = J1939TP_E_PARAM_POINTER;
    }
    else
    {
        for( network = J1939TP_ZERO; network < J1939TP_RXPDU_NUM; network++ )
        {
           if( J1939Tp_RxPdu[network].PduIdOfRxPdu == RxPduId )
           {
               flag = TRUE;
               J1939Tp_RxIndication_Process(network, PduInfoPtr);
               break;
           }
        }

        if( TRUE != flag )
        {
            errorId = J1939TP_E_INVALID_PDU_SDU_ID;
        }
    }
    /* Dev error report. */
    if( errorId != J1939TP_E_NO_ERROR )
    {
        J1939Tp_ReportDevError(J1939TP_SID_RXINDICATION, errorId);
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_RxIndication_Process
*
* Explanation: J1939Tp_RxIndication process.
*
* param: RxPduId: ID of the received I-PDU.
*        PduInfoPtr: Contains the length (SduLength) of the received I-PDU
*                    and a pointer to a buffer (SduDataPtr) containing the I-PDU.
* retval: void
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_RxIndication_Process
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) PduInfoPtr
)
{
    if( PduInfoPtr->SduLength > J1939TP_MDL_SIZE )
    {
        /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
        PduLengthType pduLen = PduInfoPtr->SduLength - J1939TP_MDL_SIZE;

        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_J1939Tp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_J1939Tp_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_J1939Tp_IDP" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
        uint8 sa = PduInfoPtr->SduDataPtr[pduLen + J1939TP_MDL_SA_POS];
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_J1939Tp_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_J1939Tp_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_J1939Tp_IDP" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
        uint8 da = PduInfoPtr->SduDataPtr[pduLen + J1939TP_MDL_DA_POS];

        if( (J1939TP_NULL_ADDRESS == sa) || (J1939TP_BROADCAST_ADDRESS == sa) )
        {   /* Error sa. */
            J1939Tp_ReportRuntimeError(J1939TP_SID_RXINDICATION, J1939TP_E_INVALID_SA);
        }
        else
        {
            /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
            uint8 pduType = J1939Tp_RxPdu[RxPduId].PduTypeOfRxPdu;
            /* Polyspace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule16.1" */
            switch( pduType )
            {
                case J1939TP_TPCM_PDUTYPEOFTXPDU:
                case J1939TP_TPDT_PDUTYPEOFTXPDU:
                {

#if (J1939TP_BAM_RX_ENABLED == STD_ON)
                    if( J1939TP_PROTOCOL_BAM == J1939Tp_RxPdu[RxPduId].PduFormatOfRxPdu )
                    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    {
                        if(J1939TP_BROADCAST_ADDRESS == da )
                        {
                            J1939Tp_BamRxIndication(RxPduId, PduInfoPtr, pduType, sa, da);
                        }
                    }
#endif  /* J1939TP_BAM_RX_ENABLED == STD_ON */

#if (J1939TP_CMDT_ENABLED == STD_ON)
                    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    if( J1939TP_PROTOCOL_CMDT == J1939Tp_RxPdu[RxPduId].PduFormatOfRxPdu )
                    {
                        J1939Tp_CmdtRxIndication(RxPduId, PduInfoPtr, pduType, sa, da);
                    }
#endif  /* J1939TP_CMDT_ENABLED == STD_ON) */

                    /* No config J1939TpRxProtocolType. */
                    /* Polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule14.3" Polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
                    if( J1939TP_PROTOCOL_NONE == J1939Tp_RxPdu[RxPduId].PduFormatOfRxPdu )
                    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    {
                        if( J1939TP_BROADCAST_ADDRESS == da )
                        {
#if (J1939TP_BAM_RX_ENABLED == STD_ON)
                            J1939Tp_BamRxIndication(RxPduId, PduInfoPtr, pduType, sa, da);
#endif  /* J1939TP_BAM_RX_ENABLED == STD_ON */
                        }
                        else
                        {
#if (J1939TP_CMDT_ENABLED == STD_ON)
                            J1939Tp_CmdtRxIndication(RxPduId, PduInfoPtr, pduType, sa, da);
#endif  /* J1939TP_CMDT_ENABLED == STD_ON */
                        }
                    }
                }
                    break;
                /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                case J1939TP_DIRECT_PDUTYPEOFTXPDU:
                {
#if (J1939TP_DIRECT_RX_ENABLED == STD_ON)
                    J1939Tp_DirectRxIndication(RxPduId, PduInfoPtr, sa);
#endif  /* J1939TP_DIRECT_RX_ENABLED == STD_ON */
                }
                    break;
                /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                default:
                    /* Do Nothing. */
                    break;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_TxConfirmation
*
* Explanation: The lower layer communication interface module confirms the
*              transmission of an IPDU.
*
* param: TxPduId: ID of the I-PDU that has been transmitted.
* retval: void
********************************************************************************
*/
FUNC(void, J1939TP_CODE) J1939Tp_TxConfirmation
(
    PduIdType TxPduId
)
{
    uint8 errorId = J1939TP_E_NO_ERROR;
    PduIdType pduIdx;
    J1939Tp_TxPduStateType* pduState = NULL_PTR;

    /* Judge module init. */
    if( J1939TP_OFF == J1939Tp_ModuleInitState )
    {
        errorId = J1939TP_E_UNINIT;
    }
    else
    {
        for( pduIdx = J1939TP_ZERO; pduIdx < J1939TP_TXPDU_NUM; pduIdx++ )
        {
            if( TxPduId == J1939Tp_TxPdu[pduIdx].PduIdOfTxPdu )
            {
                pduState = &J1939Tp_TxPduState[pduIdx];
                break;
            }
        }

        if( NULL_PTR != pduState )
        {
            if( TRUE == pduState->Locked )
            {
                /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
                PduIdType sduIdx = pduState->CurrentNSduId;
                /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_J1939Tp_UNMODIFIED_VAR_NOT_CONST" */
                J1939Tp_NSduType sduType = pduState->CurrentNSduType;

                /* Protected against concurrent Tx confirmation timeout. */
                pduState->Locked = FALSE;

                J1939Tp_TxConfirmation_Process(pduIdx, sduIdx, sduType);
            }
        }
        else  /* TxPduId invalid. */
        {
            errorId = J1939TP_E_INVALID_PDU_SDU_ID;
        }
    }

    /* Dev error report. */
    if( errorId != J1939TP_E_NO_ERROR )
    {
        J1939Tp_ReportDevError(J1939TP_SID_TXCONFIRMATION, errorId);
    }
}

/*
********************************************************************************
* Function Name: J1939Tp_ChangeParameter
*
* Explanation: This service function is used to cancel the receive of a J1939Tp NSDU.
*
* param: RxSduId: ID of the N-SDU for which parameters should be changed.
*                 The available IDs are configured via J1939TpRxNSduId.
*        Parameter: ID of parameter that should be changed.
*        Value: New value for changed parameter.
* retval: E_OK: The request has been accepted.
*         E_NOT_OK: The request failed. This happens when the provided parameter does not exist.
********************************************************************************
*/
FUNC(Std_ReturnType, J1939TP_CODE) J1939Tp_ChangeParameter  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    PduIdType RxSduId,
    TPParameterType parameter,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Dir4.5" */
    uint16 value
)
{
    Std_ReturnType result = E_NOT_OK;

    uint8 errorId = J1939TP_E_NO_ERROR;
    /* Judge module init. */
    if( J1939TP_OFF == J1939Tp_ModuleInitState )
    {
        errorId = J1939TP_E_UNINIT;
    }
    /* if the SduId is invalid */
    else if( RxSduId > J1939TP_RXNSDU_NUMBER )
    {
        errorId = J1939TP_E_INVALID_PDU_SDU_ID;
    }
    /* If the Parameter is not TP_BS. */
    else if( parameter != TP_BS )
    {
        errorId = J1939TP_E_INVALID_CHANGE_PARAM;
    }
    /* If the Value is larger than 255. */
    else if( (J1939TP_ZERO == value) || (J1939TP_FF < value)  )
    {
        errorId = J1939TP_E_INVALID_CHANGE_VALUE;
    }
    else
    {
        /* J1939Tp_ChangeParameter shall return E_NOT_OK if the SduId is invalid,
        if the Parameter is not TP_BS, or if the Value is larger than 255. */
        result = E_OK;
    }

    /* Dev error report. */
    if( errorId != J1939TP_E_NO_ERROR )
    {
        J1939Tp_ReportDevError(J1939TP_SID_CHANGEPARAMETER, errorId);
    }

    /* Dummy statement. */
    J1939TP_DUMMY_STATEMENT(RxSduId);
    J1939TP_DUMMY_STATEMENT(parameter);
    J1939TP_DUMMY_STATEMENT(value);

    return result;
}

/*
********************************************************************************
* Function Name: J1939Tp_CancelReceive
*
* Explanation: This service function is used to cancel the receive of a J1939Tp NSDU.
*
* param: RxSduId: ID of the J1939Tp N-SDU to be canceled. The available IDs are
*                    configured via J1939TpRxNSduId.
*
* retval: E_OK: The request has been accepted.
*         E_NOT_OK: The request failed. This happens when the provided I-PDU does
*                   not refer to an N-SDU that is currently received.
********************************************************************************
*/
#if( J1939TP_CANCELLATION_SUPPORT == STD_ON )
FUNC(Std_ReturnType, J1939TP_CODE) J1939Tp_CancelReceive
(
    PduIdType RxSduId
)
{
    boolean flag = FALSE;
    uint8 errorId = J1939TP_E_NO_ERROR;

    Std_ReturnType rtnValue = E_NOT_OK;
    uint16 channelIdx;
    PduIdType network;

    for( network = J1939TP_ZERO; network < J1939TP_RXNSDU_NUMBER; network++ )
    {
        if( J1939Tp_RxSduInfo[network].rxNSduIdx == RxSduId )
        {
            flag = TRUE;
            break;
        }
    }

    if( TRUE == flag )
    {
        if( J1939TP_OFF == J1939Tp_ModuleInitState )  /* No inited. */
        {
            errorId = J1939TP_E_UNINIT;
        }        /* Currently not active. */
        else if( (J1939TP_STATE_IDLE == J1939Tp_RxSduState[network].State) ||
                 /* Direct frame is received. */
              (J1939TP_STATE_DIRECT_BUSY == J1939Tp_RxSduState[network].State) ||
                 /* TP.CM_EOMAck frame has already been sent during CMDT reception. */
              (J1939TP_STATE_CMDT_EOMACK_CONF == J1939Tp_RxSduState[network].State)
              /* BAM last tpdt check not realize. */
        )
        {
            errorId = J1939TP_E_INVALID_PARAM;
        }
        else
        {
             /* Get channel index. */
            channelIdx = J1939Tp_RxSduInfo[network].rxSduOfChannelIdx;

            /* Enable receive cancellation using the API J1939Tp_CancelReceive() for this channel.  */
            if( TRUE == J1939Tp_RxChannel[channelIdx].rxCancellationSupport ) /* ECUC_J1939Tp_00186 */
            {
                J1939Tp_RxSduState[network].State = J1939TP_STATE_IDLE;
                rtnValue = E_OK;
                /* The J1939Tp module shall abort the reception. SWS_J1939Tp_00040 */
            }
        }
    }
    else
    {
        errorId = J1939TP_E_INVALID_PDU_SDU_ID;
    }

    /* Dev error report. */
    if( errorId != J1939TP_E_NO_ERROR )
    {
        J1939Tp_ReportDevError(J1939TP_SID_CANCELRECEIVE, errorId);
    }

  return rtnValue;
}

/*
********************************************************************************
* Function Name: J1939Tp_CancelTransmit
*
* Explanation: This service function is used to cancel the ongoing transmission of a J1939Tp NSDU.
*
* param: TxSduId: ID of the J1939Tp N-SDU to be canceled. The available IDs are
*                    configured via J1939TpTxNSduId.
*
* retval: E_OK: The request has been accepted.
*         E_NOT_OK: The request failed. This happens when the provided N-SDU is currently not transmitted.
********************************************************************************
*/
FUNC(Std_ReturnType, J1939TP_CODE) J1939Tp_CancelTransmit
(
    PduIdType TxSduId
)
{
    boolean flag = FALSE;
    uint8 errorId = J1939TP_E_NO_ERROR;

    Std_ReturnType rtnValue = E_NOT_OK;
    uint16 channelIdx;
    PduIdType network;

    for( network = J1939TP_ZERO; network < J1939TP_TXNSDU_NUMBER; network++ )
    {
        if( J1939Tp_TxSduInfo[network].txNSduIdx == TxSduId )
        {
            flag = TRUE;
            break;
        }
    }

    if( TRUE == flag )
    {

        /* Judge module init. */
        if( J1939TP_OFF == J1939Tp_ModuleInitState )
        {
            errorId = J1939TP_E_UNINIT;
        }         /* Currently not active. */
        else if( (J1939TP_STATE_IDLE == J1939Tp_TxSduState[network].State) ||
                 /* Direct frame is received. */
                 (J1939TP_STATE_DIRECT_BUSY == J1939Tp_TxSduState[network].State) ||
                 /* TP.CM_EOMAck frame has already been sent during CMDT reception. */
                 (J1939TP_STATE_CMDT_EOMACK_CONF == J1939Tp_TxSduState[network].State)
                 /* BAM last tpdt check not realize. */
        )
        {
            errorId = J1939TP_E_INVALID_PARAM;
        }
        else
        {
            /* Get channel index. */
            channelIdx = J1939Tp_TxSduInfo[network].txSduOfChannelIdx;

            /* Enable transmit cancellation using the API J1939Tp_CancelTransmit() for this channel.    */
            if( TRUE == J1939Tp_TxChannel[channelIdx].txCancellationSupport ) /* ECUC_J1939Tp_00059 */
            {
                J1939Tp_TxSduState[network].State = J1939TP_STATE_IDLE;
                rtnValue = E_OK;
            }
        }
    }
    else
    {
        errorId = J1939TP_E_INVALID_PDU_SDU_ID;
    }

    /* Dev error report */
    if( errorId != J1939TP_E_NO_ERROR )
    {
        J1939Tp_ReportDevError(J1939TP_SID_CANCELTRANSMIT, errorId);
    }

    return rtnValue;
}
#endif
/*
********************************************************************************
* Function Name: J1939Tp_InternalMain_RxSdu
*
* Explanation: This service function is used to cancel the ongoing transmission of a J1939Tp NSDU.
*
* param: TxSduId: ID of the J1939Tp N-SDU to be canceled. The available IDs are
*                    configured via J1939TpTxNSduId.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, J1939TP_CODE) J1939Tp_InternalMain_RxSdu
(
    void
)
{
    uint16 rxSduIdx;

    J1939Tp_RxSduStateType* rxSduState = NULL_PTR;

    for( rxSduIdx = J1939TP_ZERO; rxSduIdx < J1939TP_RXNSDU_NUMBER; rxSduIdx++ )
    {
        rxSduState = &J1939Tp_RxSduState[rxSduIdx];

#if (J1939TP_CMDT_RX_ENABLED == STD_ON)
        /* CMDT process. */
        if( (((uint32)(rxSduState->State) & (uint32)J1939TP_STATEMASK_CMDT) != (uint32)J1939TP_STATE_IDLE) &&
            ((uint32)J1939TP_STATE_IDLE == ((uint32)(rxSduState->State) & (uint32)J1939TP_STATEMASK_CONF)) )
        {
            J1939Tp_CmdtRxMain(rxSduIdx);
        }
#endif  /* J1939TP_CMDT_RX_ENABLED == STD_ON */

#if (J1939TP_BAM_RX_ENABLED == STD_ON)
        /* BAM process. */
        if( (((uint32)(rxSduState->State) & (uint32)J1939TP_STATEMASK_BAM) != (uint32)J1939TP_STATE_IDLE) &&
          ((uint32)J1939TP_STATE_IDLE == ((uint32)(rxSduState->State) & (uint32)J1939TP_STATEMASK_CONF)) )
        {
            J1939Tp_BamRxMain(rxSduIdx);
        }
#endif /* J1939TP_BAM_RX_ENABLED == STD_ON */
    }

    J1939TP_DUMMY_STATEMENT(rxSduState);
}

#define J1939TP_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

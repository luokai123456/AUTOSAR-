/*
********************************************************************************
*
*  File name: PduR_Router.h
*
*  Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: LuQ/2024.05.20
* Change: New create.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: LuQ/2024.05.20
* Change: Add Memmap segment definition.
* Cause: Optimization
********************************************************************************
*/
#ifndef PDUR_ROUT_
#define PDUR_ROUT_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "PduR_Types.h"
	
#include "CanIf.h"
#include "CanIf_Cbk.h"
	
#include "CanNm.h"
#include "CanNm_Cbk.h"
	
#include "CanTp.h"
#include "CanTp_Cbk.h"
	
#include "Com.h"
#include "Com_Cbk.h"
	
#include "Dcm.h"
#include "Dcm_Cbk.h"
	
#include "J1939Tp.h"
#include "J1939Tp_Cbk.h"
	
#include "LinIf.h"
#include "LinIf_Cbk.h"
	
#include "LinTp.h"
#include "LinTp_Cbk.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
	
#define PDUR_MODULE_ID_CANIF_IF	(PDUR_MODULE_IS_IF | (uint16)0)
#define PDUR_MODULE_ID_LINTP_TP	(PDUR_MODULE_IS_TP | (uint16)1)
#define PDUR_MODULE_ID_COM_UP	(PDUR_MODULE_IS_UP | (uint16)2)
#define PDUR_MODULE_ID_LINIF_IF	(PDUR_MODULE_IS_IF | (uint16)3)
#define PDUR_MODULE_ID_CANTP_TP	(PDUR_MODULE_IS_TP | (uint16)4)
#define PDUR_MODULE_ID_J1939TP_TP	(PDUR_MODULE_IS_TP | (uint16)5)
#define PDUR_MODULE_ID_DCM_UP	(PDUR_MODULE_IS_UP | (uint16)6)
#define PDUR_MODULE_ID_CANNM_IF	(PDUR_MODULE_IS_IF | (uint16)7)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
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
#if (defined PDUR_ROUTER_FUN)
#define PDUR_START_SEC_CODE
/* MISRA C:2012 Rule-20.1 */
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* Polyspace-begin RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
/* Polyspace-begin RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
/* Polyspace-begin RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */ 
/* PolySpace-begin MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-begin MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */
/*
********************************************************************************
* Function Name: PduR_Route_LoTransmit
*
* Explanation: Requests transmission of an I-PDU.
*
* param: dstPduPtr -> Pointers to routing information.
*        pduInfoPtr -> Pointer to the transmission of the pdu data.
*
* retval: E_OK -> transmit success.
*        E_NOT_OK -> transmit failed.
********************************************************************************
*/
PDUR_LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_Route_LoTransmit
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) pduInfoPtr
)
{
    Std_ReturnType retVal;
    /* Routing dstPduPtr */
    switch (PDUR_MODULE(dstPduPtr))
    {
	
	case PDUR_MODULE_ID_CANIF_IF:
		retVal = CanIf_Transmit(dstPduPtr->PduRDestPduHandleId, pduInfoPtr);
		break;
	case PDUR_MODULE_ID_LINTP_TP:
		retVal = LinTp_Transmit(dstPduPtr->PduRDestPduHandleId, pduInfoPtr);
		break;
	case PDUR_MODULE_ID_LINIF_IF:
		retVal = LinIf_Transmit(dstPduPtr->PduRDestPduHandleId, pduInfoPtr);
		break;
	case PDUR_MODULE_ID_CANTP_TP:
		retVal = CanTp_Transmit(dstPduPtr->PduRDestPduHandleId, pduInfoPtr);
		break;
	case PDUR_MODULE_ID_J1939TP_TP:
		retVal = J1939Tp_Transmit(dstPduPtr->PduRDestPduHandleId, pduInfoPtr);
		break;
	case PDUR_MODULE_ID_CANNM_IF:
		retVal = CanNm_Transmit(dstPduPtr->PduRDestPduHandleId, pduInfoPtr);
		break;
    case PDUR_DEST_ID_END:
        retVal = PDUR_E_NOT_OK;
        PDUR_UNUSED(pduInfoPtr);
        break;
    default:
        retVal = PDUR_E_NOT_OK;
        break;
    }

    return retVal;
}
/* PolySpace-end MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-end MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */

/* PolySpace-begin MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-begin MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */
/*
********************************************************************************
* Function Name: PduR_Route_LoCancelTransmit
*
* Explanation: Requests cancellation of an ongoing transmission of an I-PDU in
*              a lower layer communication interface or transport protocol module.
*
* param: dstPduPtr -> Pointers to routing information.
*
* retval: E_OK -> transmit success.
*         E_NOT_OK -> transmit failed.
*
* Req: SWS_PduR_00721 SWS_PduR_00722 SWS_PduR_00723 SWS_PduR_00724.
********************************************************************************
*/
PDUR_LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_Route_LoCancelTransmit
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr
)
{
    Std_ReturnType retVal;
    /* Routing dstPduPtr */
    switch (PDUR_MODULE(dstPduPtr))
    {
	
    case PDUR_DEST_ID_END:
        retVal = PDUR_E_NOT_OK;
        break;
    default:
        retVal = PDUR_E_NOT_OK;
        break;
    }
    return retVal;
}
/* PolySpace-end MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-end MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */

/* PolySpace-begin MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-begin MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */
/*
********************************************************************************
* Function Name: PduR_Route_LoCancelReceive
*
* Explanation: Requests cancellation of an ongoing reception of an I-PDU in a
*              lower layer transport protocol module.
*
* param: srcPduPtr -> Pointers to routing information.
*
* retval: E_OK -> transmit success.
*         E_NOT_OK -> transmit failed.
********************************************************************************
*/
PDUR_LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_Route_LoCancelReceive
(
    P2CONST(PduRSrcPdu_Type, AUTOMATIC, PDUR_APPL_CONST) srcPduPtr
)
{
    Std_ReturnType retVal;
    /* Routing dstPduPtr */
    switch (PDUR_MODULE(srcPduPtr))
    {
	
    case PDUR_DEST_ID_END:
        retVal = PDUR_E_NOT_OK;
        break;
    default:
        retVal = PDUR_E_NOT_OK;
        break;
    }
    return retVal;
}
/* PolySpace-end MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-end MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */

/* PolySpace-begin MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-begin MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */
/*
********************************************************************************
* Function Name: PduR_Route_LoTpChangeParameter
*
* Explanation: Request to change a specific transport protocol parameter (e.g. block size).
*
* param: srcPduPtr -> Pointers to routing information.
*        parameter -> The parameter that shall change.
*        value -> The new value of the parameter.
*
* retval: E_OK -> transmit success.
*         E_NOT_OK -> transmit failed.
********************************************************************************
*/
PDUR_LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_Route_LoTpChangeParameter
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    TPParameterType parameter,
    uint16 value
)
{
    Std_ReturnType retVal;
    /* Routing srcPduPtr */
    switch (PDUR_MODULE(dstPduPtr))
    {
	
    case PDUR_DEST_ID_END:
        PDUR_UNUSED(parameter);
        PDUR_UNUSED(value);
        retVal = PDUR_E_NOT_OK;
        break;
    default:
        retVal = PDUR_E_NOT_OK;
        break;
    }
    return retVal;
}
/* PolySpace-end MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-end MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */

/* PolySpace-begin MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-begin MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */
/*
********************************************************************************
* Function Name: PduR_Route_UpTpStartOfReception
*
* Explanation: This function is called at the start of receiving an N-SDU.
*
* param: dstPduPtr -> Pointers to routing information.
*        pduInfoPtr -> Pointer to a PduInfoType structure containing the payload
*                      data (without protocol information) and payload length of
*                      the first frame or single frame of a transport protocol
*                      I-PDU reception.
*        TpSduLength -> Total length of the N-SDU to be received.
*        bufferSizePtr(out) -> Available receive buffer in the receiving module.
*
* retval: BUFREQ_OK: Connection has been accepted.
*         BUFREQ_E_NOT_OK: Connection has been rejected.
*         BUFREQ_E_OVFL: No buffer of the required length can be provided.
********************************************************************************
*/
PDUR_LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Route_UpTpStartOfReception
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfoPtr,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType retVal;

    switch (PDUR_MODULE(dstPduPtr))
    {
        /* Req SWS_PduR_00549 */
	
	case PDUR_MODULE_ID_COM_UP:
		retVal = Com_StartOfReception(dstPduPtr->PduRDestPduHandleId, pduInfoPtr, TpSduLength, bufferSizePtr);
		break;
	case PDUR_MODULE_ID_DCM_UP:
		retVal = Dcm_StartOfReception(dstPduPtr->PduRDestPduHandleId, pduInfoPtr, TpSduLength, bufferSizePtr);
		break;
    case PDUR_DEST_ID_END:
        PDUR_UNUSED(pduInfoPtr);
        PDUR_UNUSED(TpSduLength);
        PDUR_UNUSED(bufferSizePtr);
        retVal = BUFREQ_E_NOT_OK;
        break;
    default:
        retVal = BUFREQ_E_NOT_OK;
        break;
    }
    return retVal;
}
/* PolySpace-end MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-end MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */

/* PolySpace-begin MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-begin MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */
/*
********************************************************************************
* Function Name: PduR_Route_UpTpCopyRxData
*
* Explanation: This function is called at the start of receiving an N-SDU.
*
* param: dstPduPtr -> Pointers to routing information.
*        pduInfoPtr -> Provides the source buffer (SduDataPtr) and the number of
*                      bytes to be copied (SduLength)
*        bufferSizePtr(out) -> Available receive buffer after data has been copied.
*
* retval: BUFREQ_OK: Connection has been accepted.
*         BUFREQ_E_NOT_OK: Connection has been rejected.
*         BUFREQ_E_OVFL: No buffer of the required length can be provided.
********************************************************************************
*/
PDUR_LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Route_UpTpCopyRxData
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) pduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType retVal;

    switch (PDUR_MODULE(dstPduPtr))
    {
        /* Req SWS_PduR_00428 */
	
	case PDUR_MODULE_ID_COM_UP:
		retVal = Com_CopyRxData(dstPduPtr->PduRDestPduHandleId, pduInfoPtr, bufferSizePtr);
		break;
	case PDUR_MODULE_ID_DCM_UP:
		retVal = Dcm_CopyRxData(dstPduPtr->PduRDestPduHandleId, pduInfoPtr, bufferSizePtr);
		break;
    case PDUR_DEST_ID_END:
        PDUR_UNUSED(pduInfoPtr);
        PDUR_UNUSED(bufferSizePtr);
        retVal = BUFREQ_E_NOT_OK;
        break;
    default:
        retVal = BUFREQ_E_NOT_OK;
        break;
    }
    return retVal;
}
/* PolySpace-end MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-end MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */

/* PolySpace-begin MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-begin MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */
/*
********************************************************************************
* Function Name: PduR_Route_UpTpCopyTxData
*
* Explanation: This function is called at the start of receiving an N-SDU.
*
* param: srcPduPtr -> Pointers to routing information.
*        pduInfoPtr -> Provides the source buffer (SduDataPtr) and the number of
*                      bytes to be copied (SduLength)
*        retry -> This parameter is used to acknowledge transmitted data or to
*                 retransmit data after transmission problems.
*        availableDataPtr(out) -> Indicates the remaining number of bytes that
*                          are available in the upper layer module's Tx buffer.
*
* retval: BUFREQ_OK: Connection has been accepted.
*         BUFREQ_E_NOT_OK: Connection has been rejected.
*         BUFREQ_E_OVFL: No buffer of the required length can be provided.
********************************************************************************
*/
PDUR_LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Route_UpTpCopyTxData
(
    P2CONST(PduRSrcPdu_Type, AUTOMATIC, PDUR_APPL_CONST) srcPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) pduInfoPtr,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
    BufReq_ReturnType retVal;

    switch (PDUR_MODULE(srcPduPtr))
    {
        /* Req SWS_PduR_00428 SWS_PduR_00429 */
	
	case PDUR_MODULE_ID_COM_UP:
		retVal = Com_CopyTxData(srcPduPtr->PduRSourcePduHandleId, pduInfoPtr, retry, availableDataPtr);
		break;
	case PDUR_MODULE_ID_DCM_UP:
		retVal = Dcm_CopyTxData(srcPduPtr->PduRSourcePduHandleId, pduInfoPtr, retry, availableDataPtr);
		break;
    case PDUR_DEST_ID_END:
        PDUR_UNUSED(retry);
        PDUR_UNUSED(pduInfoPtr);
        PDUR_UNUSED(availableDataPtr);
        retVal = BUFREQ_E_NOT_OK;
        break;
    default:
        retVal = BUFREQ_E_NOT_OK;
        break;
    }
    return retVal;
}
/* PolySpace-end MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-end MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */

/* PolySpace-begin MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-begin MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */
/* PolySpace-begin MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_PduR_16.1" */
/* PolySpace-begin MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_PduR_16.4" */
/*
********************************************************************************
* Function Name: PduR_Route_UpTpRxIndication
*
* Explanation: This function is called at the start of receiving an N-SDU.
*
* param: dstPduPtr -> Pointers to routing information.
*        result -> Result of the reception.
*
* retval: None.
********************************************************************************
*/
PDUR_LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Route_UpTpRxIndication
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    Std_ReturnType result
)
{
    switch (PDUR_MODULE(dstPduPtr))
    {
        /* Req SWS_PduR_00428 SWS_PduR_00429 */
	
	case PDUR_MODULE_ID_COM_UP:
		Com_TpRxIndication(dstPduPtr->PduRDestPduHandleId, result);
		break;
	case PDUR_MODULE_ID_DCM_UP:
		Dcm_TpRxIndication(dstPduPtr->PduRDestPduHandleId, result);
		break;
    case PDUR_DEST_ID_END:
        PDUR_UNUSED(result);
        break;
    default:
        break;
    }
}
/* PolySpace-end MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-end MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */
/* PolySpace-end MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_PduR_16.1" */
/* PolySpace-end MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_PduR_16.4" */

/* PolySpace-begin MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-begin MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */
/* PolySpace-begin MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_PduR_16.1" */
/* PolySpace-begin MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_PduR_16.4" */
/*
********************************************************************************
* Function Name: PduR_Route_UpTpTxConfirmation
*
* Explanation: The lower layer communication interface module confirms the
*              transmission of an IPDU.
*
* param: srcPduPtr -> A pointer to a routing path.
*        result -> Result of the transmission of the I-PDU.
*
* retval: None.
********************************************************************************
*/
PDUR_LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Route_UpTpTxConfirmation
(
    P2CONST(PduRSrcPdu_Type, AUTOMATIC, PDUR_APPL_CONST) srcPduPtr,
    Std_ReturnType result
)
{
    switch (PDUR_MODULE(srcPduPtr))
    {
	
	case PDUR_MODULE_ID_COM_UP:
		Com_TpTxConfirmation(srcPduPtr->PduRSourcePduHandleId, result);  /* PRQA S 4461 */ /* NSCA_QAC_PduR_Rule10.3 */
		break;
	case PDUR_MODULE_ID_DCM_UP:
		Dcm_TpTxConfirmation(srcPduPtr->PduRSourcePduHandleId, result);  /* PRQA S 4461 */ /* NSCA_QAC_PduR_Rule10.3 */
		break;
    case PDUR_DEST_ID_END:
        PDUR_UNUSED(result);
        break;
    default:
        break;
    }
}
/* PolySpace-end MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-end MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */
/* PolySpace-end MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_PduR_16.1" */
/* PolySpace-end MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_PduR_16.4" */

/* PolySpace-begin MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-begin MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */
/* PolySpace-begin MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_PduR_16.1" */
/* PolySpace-begin MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_PduR_16.4" */
/*
********************************************************************************
* Function Name: PduR_Route_UpRxIndication
*
* Explanation: Indication of a received I-PDU from a lower layer communication
*              interface module.
*
* param: dstPduPtr -> Pointers to routing information.
*        pduInfoPtr -> Pointer to the transmission of the pdu data.
*
* retval: None.
*
* Req: SWS_PduR_00164
********************************************************************************
*/
PDUR_LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Route_UpRxIndication
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) pduInfoPtr
)
{
    switch (PDUR_MODULE(dstPduPtr))
    {
        /* Req SWS_PduR_00164 */
	
	case PDUR_MODULE_ID_COM_UP:
		Com_RxIndication(dstPduPtr->PduRDestPduHandleId, pduInfoPtr);
		break;
    case PDUR_DEST_ID_END:
        PDUR_UNUSED(pduInfoPtr);
        break;
    default:
        break;
    }
}
/* PolySpace-end MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-end MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */
/* PolySpace-end MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_PduR_16.1" */
/* PolySpace-end MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_PduR_16.4" */

/* PolySpace-begin MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-begin MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */
/* PolySpace-begin MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_PduR_16.1" */
/* PolySpace-begin MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_PduR_16.4" */
/*
********************************************************************************
* Function Name: PduR_Route_UpTxConfirmation
*
* Explanation: The lower layer communication interface module confirms the transmission of an IPDU.
*
* param: srcPduPtr -> A pointer to a routing path.
*
* retval: None.
********************************************************************************
*/
PDUR_LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Route_UpTxConfirmation
(
    P2CONST(PduRSrcPdu_Type, AUTOMATIC, PDUR_APPL_CONST) srcPduPtr
)
{
    switch (PDUR_MODULE(srcPduPtr))
    {
        /* Req SWS_PduR_00627 */
	
	case PDUR_MODULE_ID_COM_UP:
		Com_TxConfirmation(srcPduPtr->PduRSourcePduHandleId);
		break;
    case PDUR_DEST_ID_END:
        break;
    default:
        break;
    }
}
/* PolySpace-end MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-end MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */
/* PolySpace-end MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_PduR_16.1" */
/* PolySpace-end MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_PduR_16.4" */

/* PolySpace-begin MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-begin MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */
/* PolySpace-begin MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_PduR_16.1" */
/* PolySpace-begin MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_PduR_16.4" */
/*
********************************************************************************
* Function Name: PduR_Route_UpTriggerTransmit
*
* Explanation: Trigger transport routing interface.
*
* param: route -> A pointer to a routing path.
*        pduInfoPtr -> Pointer to the transmission of the pdu data.
*
* retval: E_OK -> success.
*         E_NOT_OK -> no source or no complete.
********************************************************************************
*/
PDUR_LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_Route_UpTriggerTransmit
(
    P2CONST(PduRSrcPdu_Type, AUTOMATIC, PDUR_APPL_CONST) srcPduPtr,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfoPtr
)
{
    Std_ReturnType retVal;
    switch (PDUR_MODULE(srcPduPtr))
    {
	
	case PDUR_MODULE_ID_COM_UP:
		retVal = Com_TriggerTransmit(srcPduPtr->PduRSourcePduHandleId, pduInfoPtr);
		break;
    case PDUR_DEST_ID_END:
        PDUR_UNUSED(pduInfoPtr);
        retVal = PDUR_E_NOT_OK;
        break;
    default:
        retVal = PDUR_E_NOT_OK;
        break;
    }
    return retVal;
}
/* PolySpace-end MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.1" */
/* PolySpace-end MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_PduR_18.1" */
/* PolySpace-end MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_PduR_16.1" */
/* PolySpace-end MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_PduR_16.4" */

/* Polyspace-end RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
/* Polyspace-end RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
/* Polyspace-end RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */ 

#define PDUR_STOP_SEC_CODE
/* MISRA C:2012 Rule-20.1 */
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#endif /* #if (defined PDUR_ROUTER_FUN) */

#endif /* #define PDUR_ROUT_ */


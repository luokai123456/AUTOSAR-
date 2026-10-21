/*
********************************************************************************
*
*  File name:   CanXcp.c
*
*  Copyright    Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: Sunpengfei/2018.07.10
* Change: New created
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: yong.zhang/2020.07.02
* Change: Add release software number
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: fangtao/2020.08.11
* Change: Modify the sending function according to configuration requirements.
* Cause: Bugfix.
********************************************************************************
* Version: 3.2
* Author/Date: fangtao/2020.08.21
* Change: Added det function.
* Cause: Bugfix.
********************************************************************************
* Version: 3.3
* Author/Date: fangtao/2020.09.15
* Change: Modify the function name according to the AUTOSAR specification, add
*         MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: FangT/2021.03.03
* Change: Add checksum and Multi pudid functions.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: FangT/2021.06.30
* Change: Modify code specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date : FangT/2021.08.18
* Change: Modify the code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date : FangT/2021.08.31
* Change: Eliminate compilation warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date : FangT/2021.10.29
* Change: Modify coding style.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date : FangT/2021.11.1
* Change: Modify coding style.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date : FangT/2021.11.11
* Change: Modify the problem of converting u8 to u32.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date : FangT/2022.03.16
* Change: 1.Change the send length to uint32 type.
* Cause: Optimization
********************************************************************************
* Version: 3.23
* Author/Date : ShiRong/2022.06.16
* Change: Clear compile warnings.
* Cause: Optimization
*******************************************************************************
* Version: 3.24
* Author/Date : ShiRong/2022.09.16
* Change: Add XcpOnCANFD function.
* Cause: Update
*******************************************************************************
* Version: 3.25
* Author/Date : ShiRong/2023.02.02
* Change: Add multi-pair PDU function.
* Cause: Update
*******************************************************************************
* Version: 3.26
* Author/Date : ShiRong/2023.03.09
* Change: 1.Fix the bug of calibration long scale quantitative data receiving error.
*         2.Modify the data processing of STIM function.
* Cause: Bug
*******************************************************************************
* Version: 3.27
* Author/Date : ShiRong/2023.03.14
* Change: 1.Fix the bug of sending confirmation.
* Cause: BugFix
*******************************************************************************
* Version: 3.28
* Author/Date : ShiRong/2023.05.06
* Change: Add Block Transfer Mode.
* Cause: Update.
*******************************************************************************
* Version: 3.29
* Author/Date : ShiRong/2023.08.02
* Change: Add sending confirmation timeout judgment function.
* Cause: Update.
*******************************************************************************
* Version: 3.30
* Author/Date : ShiRong/2023.08.17
* Change: The sending confirmation time affects the block transmission function.
* Cause: BugFix.
*******************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Xcp.h"
#include "CanXcp.h"
#include "Xcp_Swc.h"
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
#define XCP_START_SEC_VAR_NO_INIT
#include "Xcp_MemMap.h"

static VAR(CanXcpFrame_st, XCP_VAR_INIT) CanXcpFrameAry[XCPBLOCK_SIZE];

#define XCP_STOP_SEC_VAR_NO_INIT
#include "Xcp_MemMap.h"

#define XCP_START_SEC_VAR_INIT
#include "Xcp_MemMap.h"

static VAR(uint8, XCP_VAR_INIT) CanXcpFrameIndex = XCP_ZERO;
static VAR(uint8, XCP_VAR_INIT) CanXcpFrameCount = XCP_ZERO;
static VAR(uint8, XCP_VAR_INIT) CanXcpFrameHeader = XCP_ONE;
static VAR(boolean, XCP_VAR_INIT) Xcp_ModuleState = FALSE;
static VAR(uint8, XCP_VAR_INIT) CanXcp_Id = XCP_ZERO;

#define XCP_STOP_SEC_VAR_INIT
#include "Xcp_MemMap.h"

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
#define XCP_START_SEC_CODE
#include "Xcp_MemMap.h"

/*
********************************************************************************
* Function Name: CanXcp_Init
*
* Explanation: CANXCP initialization.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, XCP_CODE) CanXcp_Init(void)
{
    CanXcpFrameIndex = XCP_ZERO;
    XCP_gstCAN_msgvar_rx.msgmode = XCP_ONE;
    XCP_gstCAN_msgvar_tx.msgmode = XCP_ONE;
    Xcp_ModuleState = TRUE;
}

/*
********************************************************************************
* Function Name: CanXcp_MainFunction
*
* Explanation: Called by XCP_main,Get Can messages and execute commands.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, XCP_CODE) CanXcp_MainFunction(void)
{
    uint8 avcDlc;
    uint32 avlId;
    uint32 acaMsg[XCP_64 / XCP_FOUR];
    /* Get received msg */
    if( E_OK == CanXcp_GetRxMsg(&avcDlc, &avlId, &acaMsg[XCP_ZERO]) )
    {
        /* Handle command */
        Xcp_Command((uint32*) &acaMsg[XCP_ZERO]);
    }
}

/*
********************************************************************************
* Function Name: CanXcp_GetRxMsg
*
* Explanation: Get CAN messages.
*
* param: avcpDlc : ID of the received message.
*        avlpId : Length of the received message.
*
* retval: E_OK: XCP_WriteMta success.
*         E_NOT_OK: XCP_WriteMta not success.
********************************************************************************
*/
FUNC(uint8, XCP_CODE) CanXcp_GetRxMsg
(
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) avcpDlc,
    P2VAR(uint32, AUTOMATIC, XCP_APPL_DATA) avlpId,
    P2VAR(uint32, AUTOMATIC, XCP_APPL_DATA) avlpData
)
{
    Std_ReturnType retValue = E_NOT_OK;
    uint8 index = XCP_ZERO;
    uint8 msgLen = XCP_ZERO;
    uint8 msgLenFourtimes = XCP_ZERO;
    uint8 msgLenSurplus = XCP_ZERO;

    /* Send confirmation timing */
    XcpCommandTimeCounter++;
    if( XCP_ZERO == CanXcpFrameCount )
    {
        XcpCommandTimeCounter = XCP_ZERO;
		//manual_code_whz start
        if(TRUE != CanXcpGetStatus)
        {
            CanXcpGetStatus = TRUE;
        }
		// manual_code_whz end
        retValue = E_NOT_OK;
    }
    else if( TRUE != CanXcpGetStatus )
    {
        /* Send confirmation timeout */
        if( TRANSMITTIMEOUT < XcpCommandTimeCounter )
        {
            Xcp_MemClr((uint8*)&CanXcpFrameAry, XCPBLOCK_SIZE * sizeof(CanXcpFrame_st));
            CanXcpGetStatus = TRUE;
            CanXcpFrameIndex = XCP_ZERO;
            CanXcpFrameCount = XCP_ZERO;
            CanXcpFrameHeader = XCP_ONE;
        }
        retValue = E_NOT_OK;
    }
    else
    {
        XcpCommandTimeCounter = XCP_ZERO;
        *avlpId = CanXcpFrameAry[CanXcpFrameHeader].ID;
        *avcpDlc = CanXcpFrameAry[CanXcpFrameHeader].length;
        if( XCP_EIGHT >= CanXcpFrameAry[CanXcpFrameHeader].length )
        {
            msgLen = XCP_EIGHT;
        }
        else
        {
            msgLen = CanXcpFrameAry[CanXcpFrameHeader].length;
        }
        msgLenFourtimes = msgLen / XCP_FOUR;
        msgLenSurplus = msgLen % XCP_FOUR;
        if( XCP_ZERO != msgLenSurplus )
        {
            msgLenFourtimes++;
        }

#if( CPU_BYTE_ORDER == LOW_BYTE_FIRST )
		for( index = XCP_ZERO; index < msgLenFourtimes; index++ )
		{
	        avlpData[index] = CanXcpFrameAry[CanXcpFrameHeader].data[XCP_THREE + index * XCP_FOUR];
	        avlpData[index] = (avlpData[index] << XCP_EIGHT) + CanXcpFrameAry[CanXcpFrameHeader].data[XCP_TWO + index * XCP_FOUR];
	        avlpData[index] = (avlpData[index] << XCP_EIGHT) + CanXcpFrameAry[CanXcpFrameHeader].data[XCP_ONE + index * XCP_FOUR];
	        avlpData[index] = (avlpData[index] << XCP_EIGHT) + CanXcpFrameAry[CanXcpFrameHeader].data[XCP_ZERO + index * XCP_FOUR];
		}

#else
		for( index = XCP_ZERO; index < msgLenFourtimes; index++ )
		{
	        avlpData[index] = CanXcpFrameAry[CanXcpFrameHeader].data[XCP_ZERO + index * XCP_FOUR];
	        avlpData[index] = (avlpData[index] << XCP_EIGHT) + CanXcpFrameAry[CanXcpFrameHeader].data[XCP_ONE + index * XCP_FOUR];
	        avlpData[index] = (avlpData[index] << XCP_EIGHT) + CanXcpFrameAry[CanXcpFrameHeader].data[XCP_TWO + index * XCP_FOUR];
	        avlpData[index] = (avlpData[index] << XCP_EIGHT) + CanXcpFrameAry[CanXcpFrameHeader].data[XCP_THREE + index * XCP_FOUR];
		}

#endif
        /* Clear receive flag */
        CanXcpGetStatus = FALSE;
        CanXcpFrameCount--;
        if( CanXcpFrameHeader == (XCPBLOCK_SIZE - XCP_ONE) )
        {
            CanXcpFrameHeader = XCP_ZERO;
        }
        else
        {
            CanXcpFrameHeader++;
        }

        retValue = E_OK;
    }
    return retValue;
}

/*
********************************************************************************
* Function Name: Xcp_CanIfRxIndication
*
* Explanation: Canif receive indicate.
*
* param: CanCanXcpRxPduId : ID of the received CAN_PDU.
*        PduInfoPtr : PduInfoType_structure.
*
* retval: None
********************************************************************************
*/

FUNC(void, XCP_CODE) Xcp_CanIfRxIndication
(
    PduIdType CanCanXcpRxPduId,
    P2CONST(PduInfoType, AUTOMATIC, XCP_APPL_CONST) PduInfoPtr
)
{
    uint8 errorId = XCP_E_NO_ERROR;
    uint8 index = XCP_ZERO;
    CanXcp_Id = XCP_ZERO;

    uint8* Xcp_Stim_Date = (uint8*) PduInfoPtr->SduDataPtr;
    uint32 xcp_Stim_DateLen = PduInfoPtr->SduLength;

    if( Xcp_ModuleState != TRUE )
    {
        errorId = XCP_E_NOT_INITIALIZED;
    }
    else if( PduInfoPtr == NULL_PTR )
    {
        errorId = XCP_E_PARAM_POINTER;
    }
    else if( XCP_RXPDU_LIST != XCP_ZERO )
    {
        for( index = XCP_ZERO; index < XCP_RXPDU_LIST; index++ )
        {
            if( CanCanXcpRxPduId == Xcp_RxPdu[index].XcpRxPduRef )
            {
                CanXcp_Id = index;
                errorId = XCP_E_NO_ERROR;
                break;
            }
            else
            {
                errorId = XCP_E_INVALID_PDUID;
            }
        }
        if( XCP_E_INVALID_PDUID != errorId )
        {
                    /* Check Msg ID */
            if( (*Xcp_Stim_Date) <= PID_STIM_END )
            {
                Xcp_StimDate(Xcp_Stim_Date, xcp_Stim_DateLen);
            }
            else
            {
                Xcp_MemCpy8(CanXcp_RxPduInfo[XCP_ZERO].data, PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength);

                if( CanXcpFrameIndex == (XCPBLOCK_SIZE - XCP_ONE) )
                {
                    CanXcpFrameIndex = XCP_ZERO;
                }
                else
                {
                    CanXcpFrameIndex++;
                }
                CanXcpFrameAry[CanXcpFrameIndex].ID = XCP_gstCAN_msgvar_rx.Id;
                CanXcpFrameAry[CanXcpFrameIndex].length = PduInfoPtr->SduLength;
                for( index = XCP_ZERO; index < PduInfoPtr->SduLength; ++index )
                {
                    CanXcpFrameAry[CanXcpFrameIndex].data[index] = XCP_gcaCAN_Msg_CRO[index];
                }
                /* Set Receive count */
                CanXcpFrameCount++;
            }
        }
    }
    Xcp_Det_ErrorReport(XCP_SID_RXINDICATION, errorId);

}

/*
********************************************************************************
* Function Name: Xcp_CanIfTxConfirmation
*
* Explanation: canif send completion prompt indicate.
*
* param: CanTxPduId : PduID of the transmitted data.
*
* retval: None
********************************************************************************
*/
FUNC(void, XCP_CODE) Xcp_CanIfTxConfirmation(PduIdType CanTxPduId)
{
    uint8 errorId = XCP_E_NO_ERROR;

#if( MULTIPDUIDSUPPORT == STD_ON )
    uint8 index;
#endif
    if( TRUE != Xcp_ModuleState )
    {
        errorId = XCP_E_NOT_INITIALIZED;
    }
    else
    {

#if( MULTIPDUIDSUPPORT == STD_ON )
        for(index = XCP_ZERO; index <= XCP_EVENT_CHANNEL_NUM ; index++)
        {
            if( CanTxPduId == CanXcp_TxPduInfo[index].pduID ) /* Check Msg ID */
            {
                Xcp_SendCallBack(index);
                break;
            }
        }
#else
        if( CanTxPduId == CanXcp_TxPduInfo[CanXcp_Id].pduID ) /* Check Msg ID */
        {
            Xcp_SendCallBack();
        }
#endif

#if( STD_ON != XCP_BLOCK_UPLOAD )
        CanXcpGetStatus = TRUE;
#endif

    }
    Xcp_Det_ErrorReport(XCP_SID_TXCONFIRMATION, errorId);
}

/*
********************************************************************************
* Function Name: CanXcp_Send
*
* Explanation: xcp messages are sent over the can bus.
*
* param: len : Data frame length.
*        msg : The address to send the message.
*
* retval: None
********************************************************************************
*/
#if( MULTIPDUIDSUPPORT == STD_ON )
FUNC(void, XCP_CODE) CanXcp_Send(uint8 pduid, uint32 len, P2CONST(uint8, AUTOMATIC, XCP_APPL_CONST) msg)
{
    uint8 acIndex = XCP_ZERO;
    const uint8 *src = NULL_PTR;
    uint8 *dst = NULL_PTR;
    PduInfoType CanIfTxInfoPtr = {NULL_PTR, XCP_ZERO};
    uint8 acaData[XCP_EIGHT] = {XCP_ZERO};

    CanIfTxInfoPtr.SduLength = len;
    CanIfTxInfoPtr.SduDataPtr = acaData;
    src = msg;
    dst = XCP_gcaCAN_Msg_DTO;

    for( acIndex = XCP_ZERO; acIndex < len; acIndex++ )
    {
        *dst = *src;

        CanIfTxInfoPtr.SduDataPtr[acIndex] = *src;
        dst++;
        src++;
    }

    /* call CanDriver Interface */
    (void)CanIf_Transmit(Xcp_TxPdu[pduid].XcpTxPduRef, &CanIfTxInfoPtr);
}
#else
FUNC(void, XCP_CODE) CanXcp_Send(uint32 len, P2CONST(uint8, AUTOMATIC, XCP_APPL_CONST) msg)
{
    uint8 acIndex = XCP_ZERO;
    const uint8 *src = NULL_PTR;
    uint8 *dst = NULL_PTR;
    PduInfoType CanIfTxInfoPtr = {NULL_PTR, XCP_ZERO};
    uint8 acaData[XCP_64] = {XCP_ZERO};

    CanIfTxInfoPtr.SduLength = len;
    CanIfTxInfoPtr.SduDataPtr = acaData;
    src = msg;
    dst = XCP_gcaCAN_Msg_DTO;

    for( acIndex = XCP_ZERO; acIndex < len; acIndex++ )
    {
        *dst = *src;
        CanIfTxInfoPtr.SduDataPtr[acIndex] = *src;
        dst++;
        src++;
    }
    /* call CanDriver Interface */
    (void)XcpCAN_TxMessage(&(CanIfTxInfoPtr.SduDataPtr[0]), len);
}
#endif

#define XCP_STOP_SEC_CODE
#include "Xcp_MemMap.h"


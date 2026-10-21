/* PRQA S 0380, 1006, 3432, 2053, 3008, 3006, 1258 EOF */ 
/* PRQA S 0491, 2844, 3604 EOF */   /* CWE */
/**************************************************************************** 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : CAN
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    Can_AutoSar_Wrapper.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Can MCAL driver.
*
*   @addtogroup Can
*   @{
*/
/*PRQA S 1599,1954,1756,1594 EOF*/
#ifdef __cplusplus
extern "C"{
#endif

#include "Can_AutoSar_Wrapper.h"
#include "Can_HAL_Wrapper.h"
#include "Can_Cfg.h"
#include "CanIf_Cbk.h"
#include "SchM_Can.h"
#include "Det.h"
#include "Xcp_Swc.h"
#ifdef CAN_TIMEOUT_USE_OS
    #include "Os.h"
#endif

#define CAN_ATS_WRA_C_VENDOR_ID                     176
#define CAN_ATS_WRA_C_AR_REL_MAJOR_VER              4
#define CAN_ATS_WRA_C_AR_REL_MINOR_VER              4
#define CAN_ATS_WRA_C_AR_REL_REV_VER                0
#define CAN_ATS_WRA_C_SW_MAJOR_VER                  3
#define CAN_ATS_WRA_C_SW_MINOR_VER                  0
#define CAN_ATS_WRA_C_SW_PATCH_VER                  0

#if (CAN_CFG_H_VENDOR_ID != CAN_ATS_WRA_C_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_ATS_WRA_C_VENDOR_ID "
#endif
#if (CAN_CFG_H_AR_REL_MAJOR_VER != CAN_ATS_WRA_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_ATS_WRA_C_AR_REL_MAJOR_VER "
#endif
#if (CAN_CFG_H_AR_REL_MINOR_VER != CAN_ATS_WRA_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_ATS_WRA_C_AR_REL_MINOR_VER "
#endif
#if (CAN_CFG_H_AR_REL_REV_VER != CAN_ATS_WRA_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_ATS_WRA_C_AR_REL_REV_VER "
#endif
#if (CAN_CFG_H_SW_MAJOR_VER != CAN_ATS_WRA_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_ATS_WRA_C_SW_MAJOR_VER "
#endif
#if (CAN_CFG_H_SW_MINOR_VER != CAN_ATS_WRA_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_ATS_WRA_C_SW_MINOR_VER "
#endif
#if (CAN_CFG_H_SW_PATCH_VER != CAN_ATS_WRA_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_ATS_WRA_C_SW_PATCH_VER "
#endif

#define CAN_START_SEC_VAR_INIT
#include "Can_MemMap.h"
static VAR(uint32, CAN_VAR) s_txObjectMbState[CAN_OBJECT_COUNT] = {0U};
#define CAN_STOP_SEC_VAR_INIT
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_INIT
#include "Can_MemMap.h"
/* Indicate whether each mailbox has been selected. If the selection process for a mailbox is currently underway,
    the software status bit corresponding to that mailbox cannot be cleared. */
VAR(uint32, CAN_VAR) s_txHardwareMbIsSelected[CAN_CONTROLLER_COUNT] = {0U};/*PRQA S 3408*/
#define CAN_STOP_SEC_VAR_INIT
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_INIT
#include "Can_MemMap.h"
static VAR(Can_ControllerInfo, CAN_VAR) s_sCan_ControllerInfo[CAN_CONTROLLER_COUNT] = {
    {
        .txMbInfo[0] = {0U},/*PRQA S 0691*/ 
        .txMbState = 0U
    } 
};
#define CAN_STOP_SEC_VAR_INIT
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_INIT
#include "Can_MemMap.h"
static VAR(uint8, CAN_VAR) s_u8Can_gInterDisableCnt[CAN_CONTROLLER_COUNT] = {0U};
#define CAN_STOP_SEC_VAR_INIT
#include "Can_MemMap.h"

#ifdef CanLPduReceiveCalloutFunction
extern FUNC(Std_ReturnType, CAN_CODE) CanLPduReceiveCalloutFunction \
( \
    VAR(uint8, AUTOMATIC) u8Can_Hrh, \
    VAR(Can_IdType, AUTOMATIC) u32Can_CanId, \
    VAR(uint8, AUTOMATIC) u8Can_Dlc, \
    P2CONST(uint8, AUTOMATIC, CAN_APPL_CONST) u8Can_SduPtr \
);
#endif

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_AutoSar_CheckDataLength \
(   P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) pCan_PduInfo, \
    P2CONST(mcan_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_TempHwObj, \
	VAR(uint32, AUTOMATIC) u32Can_ControllerId
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
#if (CAN_MULTICORE_ENABLED == STD_ON)
CAN_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_AutoSar_CheckMulticoreConfig \
(   VAR(uint32, AUTOMATIC) u32Can_CoreId, \
	VAR(uint32, AUTOMATIC) u32Can_ControllerId
);
#endif
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_AutoSar_HandleTriggerTransmit \
(   P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) pCan_PduInfo, \
    VAR(uint32, AUTOMATIC) u32Can_ControllerId, \
    P2CONST(mcan_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_TempHwObj, \
    VAR(uint32, AUTOMATIC) u32Can_MbTempIdex
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_Wrapper_SetStopMode \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) Can_Wrapper_SetMbStatus \
( \
    VAR(uint32, AUTOMATIC) u32Can_Controller, \
    VAR(uint32, AUTOMATIC) u32Can_MbIndex, \
    VAR(Can_MBStateType, AUTOMATIC) u8Can_Status \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_AutoSar_CheckDataLength \
(   P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) pCan_PduInfo, \
    P2CONST(mcan_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_TempHwObj, \
	VAR(uint32, AUTOMATIC) u32Can_ControllerId) 
{
    VAR(Std_ReturnType, AUTOMATIC) u8Can_ret = (Std_ReturnType)E_OK;
    if (((pCan_PduInfo->length > 64U) \
        || (pCan_PduInfo->length > pCan_TempHwObj->mbPayloadLength)) /* polyspace RTE:NIV,IDP */
        || ((pCan_PduInfo->length > 8U) \
        && ((Can_Wrapper_IsFDEnabled(((uint8)u32Can_ControllerId)) == 0U) \
                                        || ((pCan_PduInfo->id & MCAN_FD_ID_DESCRIPTOR) == 0U))))
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_WRITE, CAN_E_PARAM_DATA_LENGTH);
#endif
        u8Can_ret = E_NOT_OK;
    }
    return u8Can_ret;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
#if (CAN_MULTICORE_ENABLED == STD_ON)
CAN_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_AutoSar_CheckMulticoreConfig \
(   VAR(uint32, AUTOMATIC) u32Can_CoreId, \
    VAR(uint32, AUTOMATIC) u32Can_ControllerId) 
{
    VAR(Std_ReturnType, AUTOMATIC) u8Can_ret = (Std_ReturnType)E_OK;
    if (u32Can_CoreId != g_pCan_CurConfig->coreMap[u32Can_ControllerId].CoreId) /* polyspace RTE:IDP,NIV */
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_WRITE, CAN_E_PARAM_CONFIG);
#endif
        u8Can_ret = E_NOT_OK;
    }
    return u8Can_ret;
}
#endif
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_AutoSar_HandleTriggerTransmit \
(   P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) pCan_PduInfo, \
    VAR(uint32, AUTOMATIC) u32Can_ControllerId, \
    P2CONST(mcan_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_TempHwObj, \
    VAR(uint32, AUTOMATIC) u32Can_MbTempIdex) 
{
    VAR(Std_ReturnType, AUTOMATIC) u8Can_ret;
#if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
    VAR(PduInfoType, AUTOMATIC) sCan_TxPduInfo = {NULL_PTR, 0U};
    #if (STD_ON == CAN_FD_MODE_ENABLE)
        VAR(uint8, AUTOMATIC) u8Can_TxSduData[64] = {0U};
    #else
        VAR(uint8, AUTOMATIC) u8Can_TxSduData[8] = {0U};
    #endif
    VAR(Can_PduType, AUTOMATIC) Can_TriggerPdu = {0U};
#endif

#if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
    /*
        [SWS_Can_00504] If the trigger transmit API is enabled for the hardware object, 
        Can_Write() shall interpret a null pointer as SDU (Can_PduType.Can_SduPtrType = 
        NULL) as request for using the trigger transmit interface. If so and the hardware 
        object is free, Can_Write() shall call CanIf_TriggerTransmit() with the maximum size 
        of the message buffer to acquire the PDU’s data.
    */
    if (pCan_PduInfo->sdu == NULL_PTR)
    {
        SchM_Enter_Can_EXCLUSIVE_AREA_03();
        sCan_TxPduInfo.SduDataPtr = u8Can_TxSduData;
        sCan_TxPduInfo.SduLength = pCan_PduInfo->length;
        SchM_Exit_Can_EXCLUSIVE_AREA_03();
        u8Can_ret = CanIf_TriggerTransmit(pCan_PduInfo->swPduHandle, &sCan_TxPduInfo);
        /*
            [SWS_Can_00506] Can_Write() shall return E_NOT_OK if the trigger transmit API 
            (CanIf_TriggerTransmit()) returns E_NOT_OK.
        */
        if ((Std_ReturnType)E_OK == u8Can_ret)
        {
            SchM_Enter_Can_EXCLUSIVE_AREA_04();
            Can_TriggerPdu.swPduHandle = pCan_PduInfo->swPduHandle;
            Can_TriggerPdu.length = (uint8)(sCan_TxPduInfo.SduLength);
            Can_TriggerPdu.id = pCan_PduInfo->id;
            Can_TriggerPdu.sdu = sCan_TxPduInfo.SduDataPtr;
            SchM_Exit_Can_EXCLUSIVE_AREA_04();
            u8Can_ret = Can_Wrapper_Write \
                        ( \
                            (uint8)u32Can_ControllerId, \
                            &Can_TriggerPdu, \
                            (uint8)(u32Can_MbTempIdex), \
                            pCan_TempHwObj->CanFdPaddingValue \
                        );
        }
        else
        {
            SchM_Enter_Can_EXCLUSIVE_AREA_05();
            Can_Wrapper_SetMbStatus(u32Can_ControllerId, u32Can_MbTempIdex, MB_IDLE);
            SchM_Exit_Can_EXCLUSIVE_AREA_05();
        }
    }
    else
    {
#endif  
        u8Can_ret = Can_Wrapper_Write \
                    ( \
                        (uint8)u32Can_ControllerId, \
                        pCan_PduInfo, \
                        (uint8)(u32Can_MbTempIdex), \
                        pCan_TempHwObj->CanFdPaddingValue /* polyspace RTE:NIV,IDP */
                    );
#if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
    }
#endif
    if ((Std_ReturnType)E_OK != u8Can_ret)
    {
        /*
            [SWS_Can_00214] The function Can_Write shall return CAN_BUSY if a 
            preemptive call of Can_Write has been issued, that could not be handled reentrant 
            (i.e. a call with the same HTH).
        */
        u8Can_ret = CAN_BUSY;
    }

    return u8Can_ret;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
static int ppc_ctz(int cnt, int data) {
    __asm__ volatile (
        "cntlzw %0, %1"  
        : "=r" (cnt)     
        : "r" (data)     
        :                
    );
    (void)data;
    return cnt;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(bool, CAN_CODE) Can_Wrapper_mbStatusIsIdle \
( \
    VAR(uint32, AUTOMATIC) u32Can_Controller, \
    VAR(uint32, AUTOMATIC) u32Can_MbIndex \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) Can_Wrapper_SetMbStatus \
( \
    VAR(uint32, AUTOMATIC) u32Can_Controller, \
    VAR(uint32, AUTOMATIC) u32Can_MbIndex, \
    VAR(Can_MBStateType, AUTOMATIC) u8Can_Status \
)
{
    VAR(uint32, AUTOMATIC) u32Can_ObjectIndex = 0U;
    VAR(uint32, AUTOMATIC) u32Can_MbFlag = 0U;

    u32Can_ObjectIndex = g_pCan_CurConfig->hwObjectConfig[u32Can_Controller].txObjectConfig[u32Can_MbIndex].CanObjectId;/* polyspace RTE:NIV,NIP,IDP */
    u32Can_MbFlag = MY_BIT_GET(g_pCan_CurConfig->hthMap[u32Can_ObjectIndex].mbBitmap, u32Can_MbIndex);/* polyspace RTE:OBAI,SHF,IDP *//* polyspace RTE:NIV */
    if (MB_IDLE == u8Can_Status)
    {
        MY_BIT_SET(s_sCan_ControllerInfo[u32Can_Controller].txMbState, u32Can_MbIndex);
        if (u32Can_MbFlag > (uint32)0U)
        {
            MY_BIT_SET(s_txObjectMbState[u32Can_ObjectIndex], u32Can_MbIndex); /* polyspace RTE:OBAI */
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        MY_BIT_CLR(s_sCan_ControllerInfo[u32Can_Controller].txMbState, u32Can_MbIndex);
        if (u32Can_MbFlag > (uint32)0U)
        {
            MY_BIT_CLR(s_txObjectMbState[u32Can_ObjectIndex], u32Can_MbIndex);/* polyspace RTE:OBAI */
        }
        else
        {
            /* do nothing */
        }
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(bool, CAN_CODE) Can_Wrapper_mbStatusIsIdle \
( \
    VAR(uint32, AUTOMATIC) u32Can_Controller, \
    VAR(uint32, AUTOMATIC) u32Can_MbIndex \
)
{
    VAR(bool, AUTOMATIC) bCan_isIdle = FALSE;
    VAR(uint32, AUTOMATIC) u32Can_MbFlag = MY_BIT_GET(s_sCan_ControllerInfo[u32Can_Controller].txMbState, u32Can_MbIndex);/* polyspace RTE:OBAI,SHF */
    if (u32Can_MbFlag  == MY_BIT_MASK(u32Can_MbIndex))
    {
        bCan_isIdle = TRUE;
    }
    else
    {
        bCan_isIdle = FALSE;
    }
    return bCan_isIdle;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(PduLengthType, CAN_CODE) MCAN_Wrapper_ConvertDLCToDataLength \
( \
    VAR(uint16, AUTOMATIC) u16Can_Dlc \
)
{
    VAR(PduLengthType, AUTOMATIC) u32Can_DataLen = 0U;

    if (u16Can_Dlc <= 8U)
    {
        u32Can_DataLen = (PduLengthType)u16Can_Dlc;
    }
    else 
    {
        switch (u16Can_Dlc)
        {
        case 9U:  
        {
            u32Can_DataLen = 12U;
            break;
        }
        case 10U:
        {
            u32Can_DataLen = 16U;
            break;
        }
        case 11U:
        {
            u32Can_DataLen = 20U;
            break;
        }
        case 12U:
        {
            u32Can_DataLen = 24U;
            break;
        }
        case 13U:
        {
            u32Can_DataLen = 32U;
            break;
        }
        case 14U:
        {
            u32Can_DataLen = 48U;
            break;
        }
        case 15U:
        {
            u32Can_DataLen = 64U;
            break;
        }
        default:
        {
            u32Can_DataLen = 0U;
            break;
        }
        }
    }

    return u32Can_DataLen;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
#include "Can_Device_Prv.h"
extern void Bt_RxIndexJudge(Can_HwType* sCan_Mailbox, PduInfoType* sCan_PduInfo);
extern void Com_CanSm_CANReceiveInf_callBack(uint8 Can_valNodeId, uint32 Can_valMsgId);
extern void can_NM_USERDATA_FILL_CALLBACK(uint8 Can_valNodeId, uint32 Can_valMsgId);

#ifdef VCU_Test_Code_LLH
extern void Test_Function_SnapshotData(uint32 CanID, uint8 *receive_data,uint8 receive_length);
#endif
FUNC(void, CAN_CODE) MCAN_RxNotifiy \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerIdx, \
    VAR(uint32, AUTOMATIC) u32Can_CanObjectId, \
    P2CONST(can_msg_struct, CAN_VAR, CAN_APPL_DATA) pCan_MsgInfo \
)
{
    VAR(Can_HwType, AUTOMATIC) sCan_Mailbox = {0U};
    VAR(PduInfoType, AUTOMATIC) sCan_PduInfo = {0U};

    sCan_Mailbox.Hoh = (Can_HwHandleType)u32Can_CanObjectId;
    sCan_Mailbox.ControllerId = u8Can_ControllerIdx;
    /*
        [SWS_Can_00501] CanDrv shall indicate whether the received message is a 
        conventional CAN frame or a CAN FD frame as described in Can_IdType.
    */
    if (pCan_MsgInfo->fdf == TRUE)
    {
        sCan_Mailbox.CanId = (pCan_MsgInfo->id | MCAN_FD_ID_DESCRIPTOR);
    }
    else
    {
        sCan_Mailbox.CanId = pCan_MsgInfo->id;
    }

    if (pCan_MsgInfo->idtype == EXTENDED_ID)
    {
        sCan_Mailbox.CanId |= MCAN_MSG_ID_EXT_MASK;
    }
    sCan_PduInfo.SduLength = MCAN_Wrapper_ConvertDLCToDataLength(pCan_MsgInfo->dlc);
    sCan_PduInfo.SduDataPtr = (uint8*)(uint32)pCan_MsgInfo->data;
    /*
        [SWS_Can_00279] On L-PDU reception, the Can module shall call the RX 
        indication callback function CanIf_RxIndication with ID, Hoh, abstract CanIf 
        ControllerId in parameter Mailbox, and the Data Length and pointer to the L-SDU 
        buffer in parameter PduInfoPtr.
        [SWS_Can_00396] The RX-interrupt service routine of the corresponding HW 
        resource or the function Can_MainFunction_Read in case of polling mode shall call 
        the callback function CanIf_RxIndication.
    */
    if(sCan_Mailbox.CanId == 0x7F0)
    {
        XcpCAN_RxMessage(sCan_PduInfo.SduDataPtr,sCan_PduInfo.SduLength);
    }
#ifdef VCU_Test_Code_LLH
    if(((pCan_MsgInfo->id )>0x200)&&((pCan_MsgInfo->id ) < 0x3FF))
    {
        Test_Function_SnapshotData(pCan_MsgInfo->id ,sCan_PduInfo.SduDataPtr,sCan_PduInfo.SduLength);
    }
#endif
#ifdef CanLPduReceiveCalloutFunction
    if (E_OK == CanLPduReceiveCalloutFunction
                (
                    (uint8)u32Can_CanObjectId,
                    sCan_Mailbox.CanId,
                    (uint8)sCan_PduInfo.SduLength,
                    sCan_PduInfo.SduDataPtr
                )
        )
    {
#endif
        SetActive(&CD_valDevice_Mp.ctrl[u8Can_ControllerIdx].state, 1);
        Com_CanSm_CANReceiveInf_callBack(u8Can_ControllerIdx, sCan_Mailbox.CanId);
        can_NM_USERDATA_FILL_CALLBACK(u8Can_ControllerIdx, sCan_Mailbox.CanId);
        #ifdef CAN_TEST_CFG_H_
        Bt_RxIndexJudge(&sCan_Mailbox, &sCan_PduInfo);
        #endif
        CanIf_RxIndication(&sCan_Mailbox, &sCan_PduInfo);
#ifdef CanLPduReceiveCalloutFunction
    }
#endif
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) Can_Rx_CallBack_Pro(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    (void)u8Can_ControllerId;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) Can_Tx_CallBack_Pro(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    VAR(uint8, AUTOMATIC) u8Can_MbIndex = 0U;
    VAR(uint8, AUTOMATIC) u8Can_MbIndexSoftw = 0U;
    P2VAR(Can_MBInfoType, AUTOMATIC, CAN_APPL_DATA) pCan_MsgInfo = NULL_PTR;
    VAR(uint32, AUTOMATIC) u8Can_TempTXBTO = 0U;
    VAR(uint32, AUTOMATIC) u32count = 0U;

    pCan_MsgInfo = s_sCan_ControllerInfo[u8Can_ControllerId].txMbInfo;
    u8Can_TempTXBTO = Can_Wrapper_Get_TXBTO(u8Can_ControllerId);
    while((u8Can_TempTXBTO != 0U) &&(u32count < MCAN_TX_BUFFER_MAX))
    {
        u8Can_MbIndex = (uint8)ppc_ctz((int)u8Can_MbIndex, (int)u8Can_TempTXBTO);/* polyspace RTE:OVFL */
        MY_BIT_CLR(u8Can_TempTXBTO, u8Can_MbIndex);
        {
            u8Can_MbIndexSoftw = (uint8)((MCAN_TX_BUFFER_MAX - 1U) - u8Can_MbIndex);
            SchM_Enter_Can_EXCLUSIVE_AREA_16();
            if ((Can_Wrapper_mbStatusIsIdle((uint32)u8Can_ControllerId, (uint32)u8Can_MbIndexSoftw) == (bool)FALSE) &&\
                (MY_BIT_GET(s_txHardwareMbIsSelected[u8Can_ControllerId], (uint32)u8Can_MbIndexSoftw) == 0U))
            {
                Can_Wrapper_SetMbStatus(u8Can_ControllerId, u8Can_MbIndexSoftw, MB_IDLE);
                SchM_Exit_Can_EXCLUSIVE_AREA_16();
                CanIf_TxConfirmation(pCan_MsgInfo[u8Can_MbIndexSoftw].canIfPduId);
            }
            else
            {
                SchM_Exit_Can_EXCLUSIVE_AREA_16();
            }
        }
        u32count++;
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) Can_BusOff_CallBack_Pro(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    (void)Can_Wrapper_SetStopMode(u8Can_ControllerId);
    CanIf_ControllerBusOff(u8Can_ControllerId);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_InitStatus(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    s_u8Can_gInterDisableCnt[u8Can_ControllerId] = 0U;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_InitController(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Can_ret = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, CAN_VAR) u32Can_TimeOutDuration;
    VAR(uint32, AUTOMATIC) u8Can_TempIndex = 0U;
#ifdef CAN_TIMEOUT_USE_OS
    VAR(float32, AUTOMATIC) f32Can_TempTimeOut;

    f32Can_TempTimeOut = (float32)(CAN_TIMEOUT_DURATION / (float32)CAN_TIMEOUT_COUNTER_TICK2NS());
    if ((f32Can_TempTimeOut - (float32)((uint32)f32Can_TempTimeOut)) > (float32)0)
    {
        u32Can_TimeOutDuration = (uint32)f32Can_TempTimeOut + 1U;
    }
    else
    {
        u32Can_TimeOutDuration = (uint32)f32Can_TempTimeOut;
    }
#else
    u32Can_TimeOutDuration = CAN_TIMEOUT_DURATION;
#endif
    Can_Wrapper_SetTimeOut(u32Can_TimeOutDuration);
    u8Can_ret = Can_Wrapper_InitController(u8Can_ControllerId);
    Can_Wrapper_InitCallback(&Can_Rx_CallBack_Pro, &Can_Tx_CallBack_Pro, &Can_BusOff_CallBack_Pro, 
                            g_pCan_CurConfig->controllerConfig[u8Can_ControllerId].ErrorNotification,/* polyspace RTE:NIP,IDP */
                            g_pCan_CurConfig->controllerConfig[u8Can_ControllerId].MRAFNotification);/* polyspace RTE:NIP */
    
    s_sCan_ControllerInfo[u8Can_ControllerId].txMbState = 0U;
    s_txHardwareMbIsSelected[u8Can_ControllerId] = 0U;
    SchM_Enter_Can_EXCLUSIVE_AREA_00();
    for (u8Can_TempIndex = 0U; u8Can_TempIndex < CAN_OBJECT_COUNT; u8Can_TempIndex++)
    {
        // SchM_Enter_Can_EXCLUSIVE_AREA_10();
        s_txObjectMbState[u8Can_TempIndex] = g_pCan_CurConfig->hthMap[u8Can_TempIndex].mbBitmap;/* polyspace RTE:NIV,IDP */
        s_sCan_ControllerInfo[u8Can_ControllerId].txMbState |= s_txObjectMbState[u8Can_TempIndex];
        // SchM_Exit_Can_EXCLUSIVE_AREA_10();
    }
    for (u8Can_TempIndex = 0U; u8Can_TempIndex < MCAN_TX_BUFFER_MAX; u8Can_TempIndex++)
    {
        // SchM_Enter_Can_EXCLUSIVE_AREA_00();
        s_sCan_ControllerInfo[u8Can_ControllerId].txMbInfo[u8Can_TempIndex].canIfPduId = 0U;
        // SchM_Exit_Can_EXCLUSIVE_AREA_00();
    }
    SchM_Exit_Can_EXCLUSIVE_AREA_00();//只执行一次放到for循环外
  
    if (u8Can_ret == (Std_ReturnType)E_OK)
    {
        /*
            [SWS_Can_00259] The function Can_Init shall set all CAN controllers in the state STOPPED.
        */
        g_eCan_ControllerState[u8Can_ControllerId] = CAN_CS_STOPPED;
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_DeInitController(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    VAR(uint32, AUTOMATIC) u8Can_TempIndex = 0U;

    if ((Can_Wrapper_isSleep(u8Can_ControllerId)) == TRUE)
    {
        Can_Wrapper_exitSleep(u8Can_ControllerId);
    }
    Can_Wrapper_DeInitController(u8Can_ControllerId);

    s_sCan_ControllerInfo[u8Can_ControllerId].txMbState = 0U;
    s_txHardwareMbIsSelected[u8Can_ControllerId] = 0U;
    SchM_Enter_Can_EXCLUSIVE_AREA_11();
    for (u8Can_TempIndex = 0U; u8Can_TempIndex < CAN_OBJECT_COUNT; u8Can_TempIndex++)
    {
        // SchM_Enter_Can_EXCLUSIVE_AREA_11();
        s_txObjectMbState[u8Can_TempIndex] = g_pCan_CurConfig->hthMap[u8Can_TempIndex].mbBitmap;/* polyspace RTE:NIV,IDP */
        s_sCan_ControllerInfo[u8Can_ControllerId].txMbState |= s_txObjectMbState[u8Can_TempIndex];
        // SchM_Exit_Can_EXCLUSIVE_AREA_11();
    }
    for (u8Can_TempIndex = 0U; u8Can_TempIndex < MCAN_TX_BUFFER_MAX; u8Can_TempIndex++)
    {
        // SchM_Enter_Can_EXCLUSIVE_AREA_23();
        s_sCan_ControllerInfo[u8Can_ControllerId].txMbInfo[u8Can_TempIndex].canIfPduId = 0U;
        // SchM_Exit_Can_EXCLUSIVE_AREA_23();
    }
    SchM_Exit_Can_EXCLUSIVE_AREA_11();//只执行一次放到for循环外
  
    s_u8Can_gInterDisableCnt[u8Can_ControllerId] = 0U;
    g_eCan_ControllerState[u8Can_ControllerId] = CAN_CS_UNINIT;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_Wrapper_SetStartMode \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Can_ret = (Std_ReturnType)E_NOT_OK;
    if (CAN_CS_STOPPED != g_eCan_ControllerState[u8Can_Controller])
    {
        /*
            [SWS_Can_00409] When the function Can_SetControllerMode
            (CAN_CS_STARTED) is entered and the CAN controller is not in state STOPPED it 
            shall detect a invalid state transition
        */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_CONTROLLER_MODE, CAN_E_TRANSITION);
#endif
    }
    else 
    {
        /* SWS_Can_00384 */
        /*
            [SWS_Can_00261] The function Can_SetControllerMode(CAN_CS_STARTED)
            shall set the hardware registers in a way that makes the CAN controller participating 
            on the network.
            [SWS_Can_00196] The function Can_SetControllerMode shall enable interrupts 
            that are needed in the new state.
        */
        Can_AutoSar_Wrapper_InitController(u8Can_Controller);
        Can_Wrapper_RsetInit(u8Can_Controller);
        /*
            [SWS_Can_00425] Enabling of CAN interrupts shall not be executed, when CAN 
            interrupts have been disabled by function Can_DisableControllerInterrupts.
            [SWS_Can_00426] Disabling of CAN interrupts shall not be executed, when CAN 
            interrupts have been disabled by function Can_DisableControllerInterrupts.
        */
        if (s_u8Can_gInterDisableCnt[u8Can_Controller] == 0U)
        {
            Can_Wrapper_DisableInterrupts(u8Can_Controller);
            Can_Wrapper_EnableInterrupts(u8Can_Controller);
        }

        u8Can_ret = (Std_ReturnType)E_OK;
    }
    return u8Can_ret;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_Wrapper_SetSleepMode \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Can_ret = (Std_ReturnType)E_NOT_OK;
    /*
        [SWS_Can_00405]  This logical sleep mode shall left only, if function
        Can_SetControllerMode(CAN_CS_STOPPED) is called.
        [SWS_Can_00411]  When the function Can_SetControllerMode(CAN_CS_SLEEP)
        is entered and the CAN controller is neither in state STOPPED nor in state SLEEP, it 
        shall detect a invalid state transition
    */
    if (CAN_CS_STARTED == g_eCan_ControllerState[u8Can_Controller])
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_CONTROLLER_MODE, CAN_E_TRANSITION);
#endif
    }
    else 
    {
        if (CAN_CS_SLEEP == g_eCan_ControllerState[u8Can_Controller])
        {
            u8Can_ret = (Std_ReturnType)E_OK;
        }
        else
        {
            /*
                [SWS_Can_00404] The CAN hardware shall remain in state STOPPED, while the 
                logical SLEEP state is active
                [SWS_Can_00265] The function Can_SetControllerMode(CAN_CS_SLEEP) shall 
                set the controller into sleep mode.
                [SWS_Can_00290] If the CAN HW does not support a sleep mode, the function 
                Can_SetControllerMode(CAN_CS_SLEEP) shall set the CAN controller to the logical sleep mode.
            */
            u8Can_ret = Can_Wrapper_EnterSleep(u8Can_Controller);
        }
    }
    return u8Can_ret;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_Wrapper_SetStopMode \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Can_ret = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u8Can_TempIndex = 0U;

    if (CAN_CS_STOPPED == g_eCan_ControllerState[u8Can_Controller])
    {
        u8Can_ret = (Std_ReturnType)E_OK;
    }
    else 
    {
        if (CAN_CS_STARTED == g_eCan_ControllerState[u8Can_Controller])
        {
            /*
                [SWS_Can_00263] The function Can_SetControllerMode(CAN_CS_STOPPED)
                shall set the bits inside the CAN hardware such that the CAN controller stops 
                participating on the network.
                [SWS_Can_00282]  The function Can_SetControllerMode(CAN_CS_STOPPED)
                shall cancel pending messages.
            */
            Can_Wrapper_DeInitController(u8Can_Controller);
            s_sCan_ControllerInfo[u8Can_Controller].txMbState = 0U;
            s_txHardwareMbIsSelected[u8Can_Controller] = 0U;
            SchM_Enter_Can_EXCLUSIVE_AREA_25();
            for (u8Can_TempIndex = 0U; u8Can_TempIndex < CAN_OBJECT_COUNT; u8Can_TempIndex++)
            {
                // SchM_Enter_Can_EXCLUSIVE_AREA_25();
                s_txObjectMbState[u8Can_TempIndex] = g_pCan_CurConfig->hthMap[u8Can_TempIndex].mbBitmap;/* polyspace RTE:NIV,IDP */
                s_sCan_ControllerInfo[u8Can_Controller].txMbState |= s_txObjectMbState[u8Can_TempIndex];
                // SchM_Exit_Can_EXCLUSIVE_AREA_25();
            }
            for (u8Can_TempIndex = 0U; u8Can_TempIndex < MCAN_TX_BUFFER_MAX; u8Can_TempIndex++)
            {
                // SchM_Enter_Can_EXCLUSIVE_AREA_01();
                s_sCan_ControllerInfo[u8Can_Controller].txMbInfo[u8Can_TempIndex].canIfPduId = 0U;
                // SchM_Exit_Can_EXCLUSIVE_AREA_01();
            }
            SchM_Exit_Can_EXCLUSIVE_AREA_25();//只执行一次放到for循环外
   
            g_eCan_ControllerState[u8Can_Controller] = CAN_CS_STOPPED;
            u8Can_ret = (Std_ReturnType)E_OK;
        }
        else if (CAN_CS_SLEEP == g_eCan_ControllerState[u8Can_Controller])
        {
            /*
                [SWS_Can_00267]  If the CAN HW does not support a sleep mode, the transition
                from SLEEP to STOPPED shall return from the logical sleep mode, but have no 
                effect to the CAN controller state (as the controller is already in stopped state)
            */
            if ((Can_Wrapper_isSleep(u8Can_Controller)) == TRUE)
            {
                Can_Wrapper_exitSleep(u8Can_Controller);
            }
            Can_Wrapper_DeInitController(u8Can_Controller);
            s_sCan_ControllerInfo[u8Can_Controller].txMbState = 0U;
            s_txHardwareMbIsSelected[u8Can_Controller] = 0U;
            SchM_Enter_Can_EXCLUSIVE_AREA_24();
            for (u8Can_TempIndex = 0U; u8Can_TempIndex < CAN_OBJECT_COUNT; u8Can_TempIndex++)
            {
                // SchM_Enter_Can_EXCLUSIVE_AREA_24();
                s_txObjectMbState[u8Can_TempIndex] = g_pCan_CurConfig->hthMap[u8Can_TempIndex].mbBitmap;/* polyspace RTE:NIV,IDP */
                s_sCan_ControllerInfo[u8Can_Controller].txMbState |= s_txObjectMbState[u8Can_TempIndex];
                // SchM_Exit_Can_EXCLUSIVE_AREA_24();
            }
            for (u8Can_TempIndex = 0U; u8Can_TempIndex < MCAN_TX_BUFFER_MAX; u8Can_TempIndex++)
            {
                // SchM_Enter_Can_EXCLUSIVE_AREA_02();
                s_sCan_ControllerInfo[u8Can_Controller].txMbInfo[u8Can_TempIndex].canIfPduId = 0U;
                // SchM_Exit_Can_EXCLUSIVE_AREA_02();
            }
            SchM_Exit_Can_EXCLUSIVE_AREA_24();//只执行一次放到for循环外
       
            g_eCan_ControllerState[u8Can_Controller] = CAN_CS_STOPPED;
            u8Can_ret = (Std_ReturnType)E_OK;
        }
        else
        {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError \
            ( \
                (uint16)CAN_MODULE_ID, \
                (uint8)CAN_INSTANCE, \
                CAN_SID_SET_CONTROLLER_MODE, \
                CAN_E_TRANSITION \
            );
#endif
        }
    }
    return u8Can_ret;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_AutoSar_Wrapper_SetControllerMode \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller, \
    VAR(Can_ControllerStateType, AUTOMATIC) eCan_Transition \
)
{
    /*
        [SWS_Can_00200] If development error detection for the Can module is enabled: if 
        an invalid transition has been requested, the function Can_SetControllerMode shall 
        raise the error CAN_E_TRANSITION and return E_NOT_OK.
    */
    VAR(Std_ReturnType, AUTOMATIC) u8Can_ret = (Std_ReturnType)E_NOT_OK;

    switch (eCan_Transition)
    {
    case CAN_CS_STARTED: 
    {
        /*
            [SWS_Can_00384]  Each time the CAN controller state machine is triggered with
            the state transition value CAN_CS_STARTED, the function Can_SetControllerMode
            shall re-initialize the CAN controller with the same controller configuration set 
            previously used by functions Can_SetBaudrate or Can_Init
        */
        if ((Std_ReturnType)E_OK == Can_Wrapper_SetStartMode(u8Can_Controller))
        {
            g_eCan_ControllerState[u8Can_Controller] = CAN_CS_STARTED;
            CanIf_ControllerModeIndication(u8Can_Controller, CAN_CS_STARTED);
            u8Can_ret = (Std_ReturnType)E_OK;
        }
        break;
    }
    case CAN_CS_SLEEP: 
    {
        if ((Std_ReturnType)E_OK == Can_Wrapper_SetSleepMode(u8Can_Controller))
        {
            /*
                [SWS_Can_00257] When the CAN hardware supports sleep mode and is triggered 
                to transition into SLEEP state, the Can module shall set the controller to the SLEEP 
                state from which the hardware can be woken over CAN Bus.
                [SWS_Can_00258] When the CAN hardware does not support sleep mode and is 
                triggered to transition into SLEEP state, the Can module shall emulate a logical 
                SLEEP state from which it returns only, when it is triggered by software to transition 
                into STOPPED state.
            */
            g_eCan_ControllerState[u8Can_Controller] = CAN_CS_SLEEP;
            CanIf_ControllerModeIndication(u8Can_Controller, CAN_CS_SLEEP);
            u8Can_ret = (Std_ReturnType)E_OK;
        }
        break;
    }
    case CAN_CS_STOPPED: 
    {
        if ((Std_ReturnType)E_OK == Can_Wrapper_SetStopMode(u8Can_Controller))
        {
            CanIf_ControllerModeIndication(u8Can_Controller, CAN_CS_STOPPED);
            u8Can_ret = (Std_ReturnType)E_OK;
        }
        break;
    }
    default:
    {
        /* do nothing */
        break;
    }
    }

    return u8Can_ret;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_DisableInterrupts(VAR(uint8, AUTOMATIC) u8Can_Controller)
{
    /*
        [SWS_Can_00426] Disabling of CAN interrupts shall not be executed, when CAN 
        interrupts have been disabled by function Can_DisableControllerInterrupts.
    */
    SchM_Enter_Can_EXCLUSIVE_AREA_12();
    s_u8Can_gInterDisableCnt[u8Can_Controller]++;
    if (1U == s_u8Can_gInterDisableCnt[u8Can_Controller])
    {
        SchM_Exit_Can_EXCLUSIVE_AREA_12();
        /*
            [SWS_Can_00049] The function Can_DisableControllerInterrupts shall access the 
            CAN controller registers to disable all interrupts for that CAN controller only, if 
            interrupts for that CAN Controller are enabled.
        */
        Can_Wrapper_DisableInterrupts(u8Can_Controller);
    }
    else
    {
        SchM_Exit_Can_EXCLUSIVE_AREA_12();
    }
    /*
        [SWS_Can_00202] When Can_DisableControllerInterrupts has been called several 
        times, Can_EnableControllerInterrupts must be called as many times before the 
        interrupts are re-enabled.
    */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_EnableInterrupts(VAR(uint8, AUTOMATIC) u8Can_Controller)
{
    if (s_u8Can_gInterDisableCnt[u8Can_Controller] > 0U)
    {
        /*
            [SWS_Can_00208] The function Can_EnableControllerInterrupts shall perform no 
            action when Can_DisableControllerInterrupts has not been called before.
        */
        SchM_Enter_Can_EXCLUSIVE_AREA_14();
        s_u8Can_gInterDisableCnt[u8Can_Controller]--;
        if (s_u8Can_gInterDisableCnt[u8Can_Controller] == 0U)
        {
            Can_Wrapper_EnableInterrupts(u8Can_Controller);
            SchM_Exit_Can_EXCLUSIVE_AREA_14();
        }
        else
        {
            SchM_Exit_Can_EXCLUSIVE_AREA_14();
        }
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(Can_ErrorStateType, CAN_CODE) Can_AutoSar_Wrapper_GetErrorState \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
)
{
    VAR(Can_ErrorStateType, AUTOMATIC)  eCan_CtrlErrState = CAN_ERRORSTATE_BUSOFF;
    if ((Can_Wrapper_IsBusOff(u8Can_Controller)) == TRUE)
    {
        eCan_CtrlErrState = CAN_ERRORSTATE_BUSOFF;
    }
    else if ((Can_Wrapper_IsErrorActive(u8Can_Controller)) == TRUE)
    {
        eCan_CtrlErrState = CAN_ERRORSTATE_ACTIVE;
    }
    else 
    {
        eCan_CtrlErrState = CAN_ERRORSTATE_PASSIVE;
    }
    return eCan_CtrlErrState;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(Can_ControllerStateType, CAN_CODE) Can_AutoSar_Wrapper_GetMode \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
)
{
    VAR(Can_ControllerStateType, AUTOMATIC) eCan_Data = CAN_CS_UNINIT;
    if (u8Can_Controller < CAN_CONTROLLER_COUNT)
    {
        eCan_Data = g_eCan_ControllerState[u8Can_Controller];
    }
    else
    {
        /* do nothing */
    }
    return eCan_Data;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_AutoSar_Wrapper_GetRxErrorCounter \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
)
{
    return Can_Wrapper_GetRxErrorCounter(u8Can_Controller);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_AutoSar_Wrapper_GetTxErrorCounter(VAR(uint8, AUTOMATIC) u8Can_Controller)
{
    return Can_Wrapper_GetTxErrorCounter(u8Can_Controller);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_AutoSar_Wrapper_Write \
( \
    VAR(Can_HwHandleType, AUTOMATIC) u16Can_Hth, \
    P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) pCan_PduInfo \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Can_ret = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Can_MbTempIdex = 0U;
    VAR(uint32, AUTOMATIC) u32Can_ControllerId = 0U;
    VAR(MCANModId, AUTOMATIC) eCan_Instance = MCAN_MOD_BUTT;
    P2VAR(Can_MBInfoType, AUTOMATIC, CAN_APPL_DATA) pCan_MbInfo = NULL_PTR;
    P2CONST(mcan_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_TempHwObj = NULL_PTR;
#if (CAN_MULTICORE_ENABLED == STD_ON)
    VAR(uint32, AUTOMATIC) u32Can_CoreId = 0U;

    u32Can_CoreId = Can_GetCoreID();    /*get coreid*/
#endif

    u32Can_ControllerId = (uint32)g_pCan_CurConfig->hthMap[u16Can_Hth].controllerId;/* polyspace RTE:IDP *//* polyspace RTE:NIV */
    /*
        [SWS_Can_00277] The Can module shall allow that the functionality "Multiplexed 
        Transmission" is statically configurable (ON | OFF) at pre-compile time.
        [SWS_Can_00402]
        [SWS_Can_00403] The Can module shall support multiplexed transmission for 
        devices, which send L-PDUs in order of L-PDU priority.
    */
    u32Can_MbTempIdex = (uint32)ppc_ctz((int)u32Can_MbTempIdex, (int)s_txObjectMbState[u16Can_Hth]);/* polyspace RTE:OVFL */
    eCan_Instance = g_pCan_CurConfig->controllerConfig[u32Can_ControllerId].controllerId;/* polyspace RTE:IDP *//* polyspace RTE:NIV */
    pCan_MbInfo = s_sCan_ControllerInfo[u32Can_ControllerId].txMbInfo;
    if (u32Can_MbTempIdex < MCAN_TX_BUFFER_MAX)
    {
        pCan_TempHwObj = &g_pCan_CurConfig->hwObjectConfig[u32Can_ControllerId].txObjectConfig[u32Can_MbTempIdex];/* polyspace RTE:NIP,IDP */
        /*
            [SWS_Can_00218] The function Can_Write shall return E_NOT_OK and if 
            development error detection for the CAN module is enabled shall raise the error 
            CAN_E_PARAM_DATA_LENGTH
            [SWS_Can_00486] The CAN Frame has to be sent according to the two most
            significant bits of Can_PduType->id. The CAN FD frame bit is only evaluated if
            CAN Controller is in CAN FD mode (valid CanControllerFdBaudrateConfig).
        */
        if (Can_AutoSar_CheckDataLength(pCan_PduInfo, pCan_TempHwObj, u32Can_ControllerId) != E_OK) 
        {

        }
#if (CAN_MULTICORE_ENABLED == STD_ON)
        else if (Can_AutoSar_CheckMulticoreConfig(u32Can_CoreId, u32Can_ControllerId) != E_OK) 
        {

        }
#endif
		else
		{
            SchM_Enter_Can_EXCLUSIVE_AREA_16();
            if ((Can_Wrapper_mbStatusIsIdle(u32Can_ControllerId, u32Can_MbTempIdex) == TRUE) && (Can_LLD_TxIsReqPending(eCan_Instance, (uint8)u32Can_MbTempIdex) != TRUE))/* polyspace RTE:IDP */
            {
                Can_Wrapper_SetMbStatus(u32Can_ControllerId, u32Can_MbTempIdex, MB_BUSY);
                /* mailbox is selected, TX intr cannot clear MbStatus */
                MY_BIT_SET(s_txHardwareMbIsSelected[u32Can_ControllerId], u32Can_MbTempIdex);
                SchM_Exit_Can_EXCLUSIVE_AREA_16();
                pCan_MbInfo[u32Can_MbTempIdex].canIfPduId = pCan_PduInfo->swPduHandle;/* polyspace RTE:IDP */

                u8Can_ret = Can_AutoSar_HandleTriggerTransmit(pCan_PduInfo, u32Can_ControllerId, pCan_TempHwObj, u32Can_MbTempIdex);
			}
			else if ((Can_Wrapper_mbStatusIsIdle(u32Can_ControllerId, u32Can_MbTempIdex) == FALSE) \
                    && (Can_LLD_TxIsReqPending(eCan_Instance, (uint8)u32Can_MbTempIdex) != TRUE))
            {
                Can_Wrapper_SetMbStatus(u32Can_ControllerId, u32Can_MbTempIdex, MB_IDLE);
                SchM_Exit_Can_EXCLUSIVE_AREA_16();
                u8Can_ret = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                SchM_Exit_Can_EXCLUSIVE_AREA_16();
                u8Can_ret = CAN_BUSY;
            }
        }
    }
    else
    {
        u8Can_ret = CAN_BUSY;
    }
    return u8Can_ret;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_TxPolling(VAR(uint8, AUTOMATIC) u8Can_Controller, VAR(uint32, AUTOMATIC) u32Can_HwObjectIdex)
{
    P2CONST(mcan_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_HwObject = NULL_PTR;
    P2VAR(Can_MBInfoType, AUTOMATIC, CAN_APPL_DATA) pCan_MbInfo = NULL_PTR;
#if (CAN_MULTICORE_ENABLED == STD_ON)
    VAR(uint32, AUTOMATIC) u32Can_CoreId = 0U;

    u32Can_CoreId = Can_GetCoreID();    /*get coreid*/
#endif
    pCan_HwObject = &g_pCan_CurConfig->hwObjectConfig[u8Can_Controller].txObjectConfig[u32Can_HwObjectIdex];/* polyspace RTE:IDP *//* polyspace RTE:NIP */
#if (CAN_MULTICORE_ENABLED == STD_ON)
    if (u32Can_CoreId == g_pCan_CurConfig->coreMap[u8Can_Controller].CoreId)/* polyspace RTE:IDP,NIV */
    {
#endif
        pCan_MbInfo = s_sCan_ControllerInfo[u8Can_Controller].txMbInfo;
        if ((pCan_HwObject->isPolling == 1U) && (pCan_HwObject->CanObjectType == TRANSMIT)) /* polyspace RTE:IDP *//* polyspace RTE:NIV */
        {
            if (TRUE == Can_Wrapper_TxOccurred(u8Can_Controller, pCan_HwObject->mbIdex))/* polyspace RTE:NIV */
            {
                /*
                    [SWS_Can_00276] The function Can_Write shall store the swPduHandle that is 
                    given inside the parameter PduInfo until the Can module calls the 
                    CanIf_TxConfirmation for this request where the swPduHandle is given as parameter.
                    [SWS_Can_00016] The Can module shall call CanIf_TxConfirmation to indicate a 
                    successful transmission. It shall either called by the TX-interrupt service routine of 
                    the corresponding HW resource or inside the Can_MainFunction_Write in case of 
                    polling mode.
                */
                SchM_Enter_Can_EXCLUSIVE_AREA_19();
                if ((Can_Wrapper_mbStatusIsIdle(u8Can_Controller, pCan_HwObject->mbIdex) == FALSE) &&\
                    (MY_BIT_GET(s_txHardwareMbIsSelected[u8Can_Controller], (uint32)pCan_HwObject->mbIdex) == 0U))/* polyspace RTE:IDP */
                {
                    Can_Wrapper_SetMbStatus(u8Can_Controller, pCan_HwObject->mbIdex, MB_IDLE);
                    SchM_Exit_Can_EXCLUSIVE_AREA_19();
                    CanIf_TxConfirmation(pCan_MbInfo[pCan_HwObject->mbIdex].canIfPduId);
                }
                else
                {
                    SchM_Exit_Can_EXCLUSIVE_AREA_19();
                }
            }
        }
#if (CAN_MULTICORE_ENABLED == STD_ON)
    }
#endif
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_TxPollingMul \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller, \
    VAR(uint32, AUTOMATIC) u32Can_HwObjectIdex, \
    VAR(uint8, AUTOMATIC) u8Can_PeriodIdx \
)
{
    P2CONST(mcan_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_HwObject = NULL_PTR;
    P2VAR(Can_MBInfoType, AUTOMATIC, CAN_APPL_DATA) pCan_MbInfo = NULL_PTR;
#if (CAN_MULTICORE_ENABLED == STD_ON)
    VAR(uint32, AUTOMATIC) u32Can_CoreId = 0U;

    u32Can_CoreId = Can_GetCoreID();    /*get coreid*/
#endif
    pCan_HwObject = &g_pCan_CurConfig->hwObjectConfig[u8Can_Controller].txObjectConfig[u32Can_HwObjectIdex];/* polyspace RTE:IDP *//* polyspace RTE:NIP */
#if (CAN_MULTICORE_ENABLED == STD_ON)
    if (u32Can_CoreId == g_pCan_CurConfig->coreMap[u8Can_Controller].CoreId)/* polyspace RTE:IDP,NIV */
    {
#endif
        pCan_MbInfo = s_sCan_ControllerInfo[u8Can_Controller].txMbInfo;
        if ((pCan_HwObject->isPolling == 1U) && (pCan_HwObject->CanObjectType == TRANSMIT) /* polyspace RTE:IDP *//* polyspace RTE:NIV */
            && (u8Can_PeriodIdx == pCan_HwObject->PeriodIndex))/* polyspace RTE:NIV */
        {
            if (TRUE == Can_Wrapper_TxOccurred(u8Can_Controller, pCan_HwObject->mbIdex))/* polyspace RTE:NIV */
            {
                /*
                    [SWS_Can_00276] The function Can_Write shall store the swPduHandle that is 
                    given inside the parameter PduInfo until the Can module calls the 
                    CanIf_TxConfirmation for this request where the swPduHandle is given as parameter.
                    [SWS_Can_00016] The Can module shall call CanIf_TxConfirmation to indicate a 
                    successful transmission. It shall either called by the TX-interrupt service routine of 
                    the corresponding HW resource or inside the Can_MainFunction_Write in case of 
                    polling mode.
                */
                SchM_Enter_Can_EXCLUSIVE_AREA_17();
                if ((Can_Wrapper_mbStatusIsIdle(u8Can_Controller, pCan_HwObject->mbIdex) == FALSE) &&\
                    (MY_BIT_GET(s_txHardwareMbIsSelected[u8Can_Controller], (uint32)pCan_HwObject->mbIdex) == 0U))/* polyspace RTE:IDP */
                {
                    Can_Wrapper_SetMbStatus(u8Can_Controller, pCan_HwObject->mbIdex, MB_IDLE);
                    SchM_Exit_Can_EXCLUSIVE_AREA_17();
                    CanIf_TxConfirmation(pCan_MbInfo[pCan_HwObject->mbIdex].canIfPduId);
                }
                else
                {
                    SchM_Exit_Can_EXCLUSIVE_AREA_17();
                }
            }
        }
#if (CAN_MULTICORE_ENABLED == STD_ON)
    }
#endif
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_RxPolling(VAR(uint8, AUTOMATIC) u8Can_ControllerIdx)
{
    VAR(uint32, AUTOMATIC) u32Can_HwObjectIdex = 0U;
    VAR(uint8, AUTOMATIC) u8Can_IsDataLost = 0U;
    P2CONST(mcan_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_HwObject = NULL_PTR;
    for (u32Can_HwObjectIdex = 0; u32Can_HwObjectIdex < g_pCan_CurConfig->hwObjectConfig[u8Can_ControllerIdx].rxObjCount; u32Can_HwObjectIdex++)/* polyspace RTE:NIV,IDP */
    {
        pCan_HwObject = &g_pCan_CurConfig->hwObjectConfig[u8Can_ControllerIdx].rxObjectConfig[u32Can_HwObjectIdex];/* polyspace RTE:NIP,IDP */
        if ((pCan_HwObject->isPolling == 1U) /* polyspace RTE:IDP *//* polyspace RTE:NIV */
            && (pCan_HwObject->CanObjectType == RECEIVE) /* polyspace RTE:NIV */
            && (u8Can_ControllerIdx == pCan_HwObject->CanControllerId))/* polyspace RTE:NIV */
        {
            if (pCan_HwObject->mbIdex == MCAN_STORE_RX_FIFO0)/* polyspace RTE:NIV */
            {
                u8Can_IsDataLost = Can_Wrapper_IsDataLost(u8Can_ControllerIdx, 0U);
                if (u8Can_IsDataLost == 1U)
                {
                    (void)Det_ReportRuntimeError \
                    ( \
                        (uint16)CAN_MODULE_ID, \
                        (uint8)CAN_INSTANCE, \
                        (uint8)CAN_SID_MAIN_FUNCTION_READ, \
                        (uint8)CAN_E_DATALOST \
                    );
                }
                (void)Can_Wrapper_RxRecFifoMsg(u8Can_ControllerIdx, 0U);
            }
            else if (pCan_HwObject->mbIdex == MCAN_STORE_RX_FIFO1)
            {
                u8Can_IsDataLost = Can_Wrapper_IsDataLost(u8Can_ControllerIdx, 1U);
                if (u8Can_IsDataLost == 1U)
                {
                    (void)Det_ReportRuntimeError \
                    ( \
                        (uint16)CAN_MODULE_ID, \
                        (uint8)CAN_INSTANCE, \
                        (uint8)CAN_SID_MAIN_FUNCTION_READ, \
                        (uint8)CAN_E_DATALOST \
                    );
                }
                (void)Can_Wrapper_RxRecFifoMsg(u8Can_ControllerIdx, 1U);
            }
            else
            {
                (void)Can_Wrapper_RxDedicatedBufferProcessNewMsg(u8Can_ControllerIdx);
            }
        }
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_RxPollingMul \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerIdx, \
    VAR(uint8, AUTOMATIC) u8Can_PeriodIdx \
)
{
    VAR(uint32, AUTOMATIC) u32Can_HwObjectIdex = 0U;
    VAR(uint8, AUTOMATIC) u8Can_IsDataLost = 0U;
    P2CONST(mcan_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_HwObject = NULL_PTR;

    for (u32Can_HwObjectIdex = 0; u32Can_HwObjectIdex < g_pCan_CurConfig->hwObjectConfig[u8Can_ControllerIdx].rxObjCount; u32Can_HwObjectIdex++)/* polyspace RTE:IDP *//* polyspace RTE:NIV */
    {
        pCan_HwObject = &g_pCan_CurConfig->hwObjectConfig[u8Can_ControllerIdx].rxObjectConfig[u32Can_HwObjectIdex];/* polyspace RTE:NIP,IDP */

        if ((pCan_HwObject->isPolling == 1U) /* polyspace RTE:IDP *//* polyspace RTE:NIV */
                && (pCan_HwObject->CanObjectType == RECEIVE) /* polyspace RTE:NIV */
                && (u8Can_ControllerIdx == pCan_HwObject->CanControllerId) /* polyspace RTE:NIV */
                && (u8Can_PeriodIdx == pCan_HwObject->PeriodIndex))/* polyspace RTE:NIV */
        {
            if (pCan_HwObject->mbIdex == MCAN_STORE_RX_FIFO0)/* polyspace RTE:NIV */
            {
                u8Can_IsDataLost = Can_Wrapper_IsDataLost(u8Can_ControllerIdx, 0U);
                if (u8Can_IsDataLost == 1U)
                {
                    (void)Det_ReportRuntimeError \
                    ( \
                        (uint16)CAN_MODULE_ID, \
                        (uint8)CAN_INSTANCE, \
                        (uint8)CAN_SID_MAIN_FUNCTION_READ, \
                        (uint8)CAN_E_DATALOST \
                    );
                }
                (void)Can_Wrapper_RxRecFifoMsg(u8Can_ControllerIdx, 0U);
            }
            else if (pCan_HwObject->mbIdex == MCAN_STORE_RX_FIFO1)
            {
                u8Can_IsDataLost = Can_Wrapper_IsDataLost(u8Can_ControllerIdx, 1U);
                if (u8Can_IsDataLost == 1U)
                {
                    (void)Det_ReportRuntimeError \
                    ( \
                        (uint16)CAN_MODULE_ID, \
                        (uint8)CAN_INSTANCE, \
                        (uint8)CAN_SID_MAIN_FUNCTION_READ, \
                        (uint8)CAN_E_DATALOST \
                    );
                }
                (void)Can_Wrapper_RxRecFifoMsg(u8Can_ControllerIdx, 1U);
            }
            else
            {
                (void)Can_Wrapper_RxDedicatedBufferProcessNewMsg(u8Can_ControllerIdx);
            }
        }
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_BusOffPolling(VAR(uint8, AUTOMATIC) u8Can_Controller)
{
    if ((Can_Wrapper_IsBusOff(u8Can_Controller)) == TRUE)
    {
        /*
            [SWS_Can_00272] After bus-off detection, the CAN controller shall transition to the 
            state STOPPED and the Can module shall ensure that the CAN controller doesn’t 
            participate on the network anymore.
            [SWS_Can_00273] After bus-off detection, the Can module shall cancel still 
            pending messages.
            [SWS_Can_00274] The Can module shall disable or suppress automatic bus-off recovery.
        */
        (void)Can_Wrapper_SetStopMode(u8Can_Controller);
        /* 
            [SWS_Can_00020] The CanIf module is notified with the function CanIf_ControllerBusOff after 
            STOPPED state is reached referring to the corresponding CAN controller with 
            the abstract CanIf ControllerId
        */
        CanIf_ControllerBusOff(u8Can_Controller);
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_WakeUpPolling(VAR(uint8, AUTOMATIC) u8Can_Controller)
{
    if ((Can_Wrapper_isSleep(u8Can_Controller)) == TRUE)
    {
        SchM_Enter_Can_EXCLUSIVE_AREA_22();
        Can_Wrapper_exitSleep(u8Can_Controller);
        g_eCan_ControllerState[u8Can_Controller] = CAN_CS_STOPPED;
        SchM_Exit_Can_EXCLUSIVE_AREA_22();
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_ControllerModePolling \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
)
{
    VAR(boolean, AUTOMATIC) bCan_Temp1 = FALSE;
    VAR(boolean, AUTOMATIC) bCan_Temp2 = FALSE;

    if (CAN_CS_SLEEP != g_eCan_ControllerState[u8Can_Controller])
    { 
        /*
            [SWS_Can_00370] The function Can_Mainfunction_Mode shall poll a flag of the 
            CAN status register until the flag signals that the change takes effect and notify the 
            upper layer with function CanIf_ControllerModeIndication about a successful state 
            transition referring to the corresponding CAN controller with the abstract CanIf ControllerId.
        */
        bCan_Temp1 = (boolean)((CAN_CS_STARTED == g_eCan_ControllerState[u8Can_Controller]) ? TRUE : FALSE);
        bCan_Temp2 = (boolean)((CAN_CS_STOPPED == g_eCan_ControllerState[u8Can_Controller]) ? TRUE : FALSE);
        if ((Can_Wrapper_isInitState(u8Can_Controller) == TRUE) && (bCan_Temp1 == TRUE))
        {
            g_eCan_ControllerState[u8Can_Controller] = CAN_CS_STOPPED;
            /*
                [SWS_Can_00373]  The function Can_Mainfunction_Mode shall call the function
                CanIf_ControllerModeIndication to notify the upper layer about a successful state 
                transition of the corresponding CAN controller referred by abstract CanIf ControllerId, 
                in case the state transition was triggered by function Can_SetControllerMode.
            */
            CanIf_ControllerModeIndication(u8Can_Controller, CAN_CS_STOPPED);
        }
        else if ((Can_Wrapper_isInitState(u8Can_Controller) != TRUE) && (bCan_Temp2 == TRUE))
        {
            g_eCan_ControllerState[u8Can_Controller] = CAN_CS_STARTED;
            CanIf_ControllerModeIndication(u8Can_Controller, CAN_CS_STARTED);
        }
        else
        {
            /* nothing */
        }
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

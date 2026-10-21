/* PRQA S 0380, 1006, 3432, 2995 EOF */
/* PRQA S 0491, 2844, 3604, 4404 EOF */   /* CWE */
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
*   @file    Can_176_CanFD.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CanFD MCAL driver.
*
*   @addtogroup CanFD
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Can_176_CanFD_AutoSar_Wrapper.h"
#include "Can_176_CanFD_LLDriver.h"
#include "Can_176_CanFD_HAL_Wrapper.h"
#include "CanIf_Cbk.h"
#include "Det.h"
#include "SchM_Can_176_CanFD.h"

#ifdef RESOURCE_SUPPORT_CANFD_IP

#define CAN_176_CANFD_ATS_WRA_C_VENDOR_ID                     176
#define CAN_176_CANFD_ATS_WRA_C_AR_REL_MAJOR_VER              4
#define CAN_176_CANFD_ATS_WRA_C_AR_REL_MINOR_VER              4
#define CAN_176_CANFD_ATS_WRA_C_AR_REL_REV_VER                0
#define CAN_176_CANFD_ATS_WRA_C_SW_MAJOR_VER                  3
#define CAN_176_CANFD_ATS_WRA_C_SW_MINOR_VER                  0
#define CAN_176_CANFD_ATS_WRA_C_SW_PATCH_VER                  0

#if (CAN_176_CANFD_CFG_H_VENDOR_ID != CAN_176_CANFD_ATS_WRA_C_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_176_CANFD_ATS_WRA_C_VENDOR_ID "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_MAJOR_VER != CAN_176_CANFD_ATS_WRA_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_ATS_WRA_C_AR_REL_MAJOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_MINOR_VER != CAN_176_CANFD_ATS_WRA_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_ATS_WRA_C_AR_REL_MINOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_REV_VER != CAN_176_CANFD_ATS_WRA_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_ATS_WRA_C_AR_REL_REV_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_MAJOR_VER != CAN_176_CANFD_ATS_WRA_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_ATS_WRA_C_SW_MAJOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_MINOR_VER != CAN_176_CANFD_ATS_WRA_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_ATS_WRA_C_SW_MINOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_PATCH_VER != CAN_176_CANFD_ATS_WRA_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_ATS_WRA_C_SW_PATCH_VER "
#endif


#define CAN_176_CANFD_START_SEC_VAR_NO_INIT
#include "Can_176_CanFD_MemMap.h"
static VAR(CanFd_ControllerInfo, CAN_VAR) s_sCanFd_ControllerInfo[CAN_176_CANFD_CONTROLLER_COUNT] ; /*PRQA S 0686*/
#define CAN_176_CANFD_STOP_SEC_VAR_NO_INIT
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_VAR_INIT
#include "Can_176_CanFD_MemMap.h"
static VAR(uint8, CAN_VAR) s_u8CanFd_gInterDisableCnt[CAN_176_CANFD_CONTROLLER_COUNT] = {0U};
#define CAN_176_CANFD_STOP_SEC_VAR_INIT
#include "Can_176_CanFD_MemMap.h"

extern VAR(uint16, AUTOMATIC) g_u16CanFd_CurBaudRateId[CAN_176_CANFD_CONTROLLER_COUNT];

#ifdef Can_176_CanFD_LPduReceiveCalloutFunction
extern FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_LPduReceiveCalloutFunction \
( \
    VAR(uint8, AUTOMATIC) u8Can_Hrh, \
    VAR(Can_IdType, AUTOMATIC) u32Can_CanId, \
    VAR(uint8, AUTOMATIC) u8Can_Dlc, \
    P2CONST(uint8, AUTOMATIC, CAN_APPL_CONST) u8Can_SduPtr \
);
#endif

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFd_AutoSar_CheckDataLength \
(   P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) pCan_PduInfo, \
    P2CONST(CanFd_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_TempHwObj
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFd_AutoSar_CheckMulticoreConfig \
(   VAR(uint32, AUTOMATIC) u32CanFd_CoreId, \
    P2CONST(CanFd_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_TempHwObj) ;
#endif
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFd_AutoSar_HandleTriggerTransmit \
( 
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config, \
    P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) pCan_PduInfo, \
    P2VAR(CanFd_MBInfoType, AUTOMATIC, CAN_APPL_DATA) pCan_MbInfo, \
    P2CONST(CanFd_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_TempHwObj, \
    VAR(uint8, AUTOMATIC) u8Can_TempIdex
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(void, CAN_CODE) Can_176_CanFd_AutoSar_Wrapper_IsBufferMatching( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerIdx, \
    VAR(uint8, AUTOMATIC) u8Can_PeriodIdx, \
    P2VAR(CANFDRxMsg, AUTOMATIC, CAN_APPL_DATA) rx_msg
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_Wrapper_SetStopMode \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFd_AutoSar_CheckDataLength \
(   P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) pCan_PduInfo, \
    P2CONST(CanFd_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_TempHwObj) 
{
    VAR(Std_ReturnType, AUTOMATIC) u8Can_ret = (Std_ReturnType)E_OK;
    if (((pCan_PduInfo->length > 64U) \
                || (pCan_PduInfo->length > pCan_TempHwObj->mbPayloadLength)) \
                || ((pCan_PduInfo->length > 8U) \
                && ((pCan_PduInfo->id & CANFD_FD_ID_DESCRIPTOR) == 0U)))
    {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CAN_176_CANFD_MODULE_ID, 
                                (uint8)CAN_176_CANFD_INSTANCE, 
                                CAN_176_CANFD_SID_WRITE,
                                CAN_176_CANFD_E_PARAM_DATA_LENGTH);
#endif
        u8Can_ret = E_NOT_OK;
    }
    return u8Can_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFd_AutoSar_CheckMulticoreConfig \
(   VAR(uint32, AUTOMATIC) u32CanFd_CoreId, \
    P2CONST(CanFd_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_TempHwObj) 
{
    VAR(Std_ReturnType, AUTOMATIC) u8Can_ret = (Std_ReturnType)E_OK;

    if (u32CanFd_CoreId != g_pCanFd_CurConfig->CanFdCoreMap[pCan_TempHwObj->CanControllerId].CoreId)/* polyspace RTE:IDP */
    {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_176_CANFD_MODULE_ID, 
                            (uint8)CAN_176_CANFD_INSTANCE, 
                            CAN_176_CANFD_SID_WRITE,
                            CAN_176_CANFD_E_PARAM_CONFIG);
        u8Can_ret = E_NOT_OK;
#endif
    }
    return u8Can_ret;
}
#endif
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFd_AutoSar_HandleTriggerTransmit \
(   
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config, \
    P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) pCan_PduInfo, \
    P2VAR(CanFd_MBInfoType, AUTOMATIC, CAN_APPL_DATA) pCan_MbInfo, \
    P2CONST(CanFd_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_TempHwObj, \
    VAR(uint8, AUTOMATIC) u8Can_TempIdex
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Can_ret = (Std_ReturnType)E_NOT_OK;
#if (CAN_176_CANFD_TRIGGER_TRANSMIT_EN == STD_OFF)
    (void)pCan_MbInfo;
#endif
#if (CAN_176_CANFD_TRIGGER_TRANSMIT_EN == STD_ON)
    VAR(PduInfoType, AUTOMATIC) sCan_TxPduInfo = {NULL_PTR, 0U};
    #if (STD_ON == CAN_176_CANFD_FD_MODE_ENABLE)
        VAR(uint8, AUTOMATIC) u8Can_TxSduData[64] = {0U};
    #else
        VAR(uint8, AUTOMATIC) u8Can_TxSduData[8] = {0U};
    #endif
    VAR(Can_PduType, AUTOMATIC) Can_TriggerPdu = {0U};
#endif
    
#if (CAN_176_CANFD_TRIGGER_TRANSMIT_EN == STD_ON)
    /*
        [SWS_Can_00504] If the trigger transmit API is enabled for the hardware object, 
        Can_Write() shall interpret a null pointer as SDU (Can_PduType.Can_SduPtrType = 
        NULL) as request for using the trigger transmit interface. If so and the hardware 
        object is free, Can_Write() shall call CanIf_TriggerTransmit() with the maximum size 
        of the message buffer to acquire the PDU’s data.
    */
    if (pCan_PduInfo->sdu == NULL_PTR)
    {
        SchM_Enter_Can_176_CanFD_EXCLUSIVE_AREA_03();
        sCan_TxPduInfo.SduDataPtr = u8Can_TxSduData;
        sCan_TxPduInfo.SduLength = pCan_PduInfo->length;
        SchM_Exit_Can_176_CanFD_EXCLUSIVE_AREA_03();
        u8Can_ret = CanIf_TriggerTransmit(pCan_PduInfo->swPduHandle, &sCan_TxPduInfo);
        /*
            [SWS_Can_00506] Can_Write() shall return E_NOT_OK if the trigger transmit API 
            (CanIf_TriggerTransmit()) returns E_NOT_OK.
        */
        if ((Std_ReturnType)E_OK == u8Can_ret)
        {
            SchM_Enter_Can_176_CanFD_EXCLUSIVE_AREA_04();
            Can_TriggerPdu.swPduHandle = pCan_PduInfo->swPduHandle;
            Can_TriggerPdu.length = (uint8)(sCan_TxPduInfo.SduLength);
            Can_TriggerPdu.id = pCan_PduInfo->id;
            Can_TriggerPdu.sdu = sCan_TxPduInfo.SduDataPtr;
            SchM_Exit_Can_176_CanFD_EXCLUSIVE_AREA_04();
            u8Can_ret = Can_176_CanFD_Wrapper_Write \
                        ( \
                        u8Can_TempIdex, \
                        &Can_TriggerPdu, \
                        pCan_TempHwObj->mbType, \
                        pCan_TempHwObj->CanFdPaddingValue, \
                        pCan_Config->phy_para[g_u16CanFd_CurBaudRateId[pCan_TempHwObj->CanControllerId]].brs_ena
                        );
        } 
        else 
        {
            SchM_Enter_Can_176_CanFD_EXCLUSIVE_AREA_05();
            pCan_MbInfo->txMbState = MB_176_CANFD_IDLE;
            SchM_Exit_Can_176_CanFD_EXCLUSIVE_AREA_05();
        }
    } 
    else 
    {
#endif  
        u8Can_ret = Can_176_CanFD_Wrapper_Write \
                    ( \
                        u8Can_TempIdex, \
                        pCan_PduInfo, \
                        pCan_TempHwObj->mbType, \
                        pCan_TempHwObj->CanFdPaddingValue, \
                        pCan_Config->phy_para[g_u16CanFd_CurBaudRateId[pCan_TempHwObj->CanControllerId]].brs_ena /* polyspace RTE:OBAI */
                    );
#if (CAN_176_CANFD_TRIGGER_TRANSMIT_EN == STD_ON)
    }
#endif
        
    return u8Can_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(void, CAN_CODE) Can_176_CanFD_RxNotifiy \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerIdx, \
    VAR(uint32, AUTOMATIC) u32Can_CanObjectId, \
    P2CONST(CANFDRxMsg, CAN_VAR, CAN_APPL_DATA) pCan_MsgInfo \
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
    if (pCan_MsgInfo->is_fd_format_flag == 1U)
    {
        sCan_Mailbox.CanId = (pCan_MsgInfo->id | CANFD_FD_ID_DESCRIPTOR);
    }
    else
    {
        sCan_Mailbox.CanId = pCan_MsgInfo->id;
    }

    if (pCan_MsgInfo->is_extern == 1U)
    {
        sCan_Mailbox.CanId |= CANFD_MSG_ID_EXT_MASK;
    }
    sCan_PduInfo.SduLength = pCan_MsgInfo->data_len;
    sCan_PduInfo.SduDataPtr = (uint8*)(uint32)pCan_MsgInfo->data.byte;
    /*
        [SWS_Can_00279] On L-PDU reception, the Can module shall call the RX 
        indication callback function CanIf_RxIndication with ID, Hoh, abstract CanIf 
        ControllerId in parameter Mailbox, and the Data Length and pointer to the L-SDU 
        buffer in parameter PduInfoPtr.
        [SWS_Can_00396] The RX-interrupt service routine of the corresponding HW 
        resource or the function Can_MainFunction_Read in case of polling mode shall call 
        the callback function CanIf_RxIndication.
    */
#ifdef Can_176_CanFD_LPduReceiveCalloutFunction
    if ((uint8)E_OK == Can_176_CanFD_LPduReceiveCalloutFunction
                (
                    (uint8)u32Can_CanObjectId,
                    sCan_Mailbox.CanId,
                    (uint8)sCan_PduInfo.SduLength,
                    sCan_PduInfo.SduDataPtr
                )
        )
    {
#endif
        CanIf_RxIndication(&sCan_Mailbox, &sCan_PduInfo);
#ifdef Can_176_CanFD_LPduReceiveCalloutFunction
    }
#endif
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(void, CAN_CODE) Can_176_CanFD_Rx_CallBack_Pro \
( \
    VAR(CANFDModId, AUTOMATIC) u8Can_ControllerId, \
    P2VAR(CANFDRxMsg, AUTOMATIC, CAN_APPL_DATA) rx_msg \
)
{
    VAR(uint8, AUTOMATIC) u8Can_HwObjectIdex = 0U;
    VAR(boolean, AUTOMATIC) bCan_IsBuffer = FALSE;
    P2CONST(CanFd_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_HwObject = NULL_PTR;

    for (u8Can_HwObjectIdex = 0; u8Can_HwObjectIdex < g_pCanFd_CurConfig->CanFdHwObjCount; u8Can_HwObjectIdex++)/* polyspace RTE:IDP */
    {
        pCan_HwObject = &g_pCanFd_CurConfig->CanFdHwObjectConfig[u8Can_HwObjectIdex];
        if ((pCan_HwObject->CanObjectType == CANFD_RECEIVE) && (pCan_HwObject->CanControllerId == (uint32)u8Can_ControllerId))
        {
            if ((pCan_HwObject->filterCode & (~pCan_HwObject->filterMask)) == (rx_msg->id & (~pCan_HwObject->filterMask)))
            {
                bCan_IsBuffer = TRUE;
                break;
            }
        }
    }
    if (bCan_IsBuffer == TRUE)
    {
        Can_176_CanFD_RxNotifiy((uint8)u8Can_ControllerId, pCan_HwObject->CanObjectId, rx_msg);
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(void, CAN_CODE) Can_176_CanFD_Tx_CallBack_Pro \
( \
    VAR(CANFDModId, AUTOMATIC) u8Can_ControllerId, \
    CANFDTransBufType buf_idx \
)
{
    if (CANFD_TRANS_BUF_TYPE_PRIMARY == buf_idx)
    {
        if (s_sCanFd_ControllerInfo[u8Can_ControllerId].txMbInfo_Primary.txMbState == MB_176_CANFD_BUSY)
        {
            s_sCanFd_ControllerInfo[u8Can_ControllerId].txMbInfo_Primary.txMbState = MB_176_CANFD_IDLE;
            CanIf_TxConfirmation(s_sCanFd_ControllerInfo[u8Can_ControllerId].txMbInfo_Primary.canIfPduId);
        }
    }
    else if (CANFD_TRANS_BUF_TYPE_SECONDARY == buf_idx)
    {
        CanIf_TxConfirmation(s_sCanFd_ControllerInfo[u8Can_ControllerId].txMbInfo_Secondary.canIfPduId);
    }
    else
    {
        // do nothing
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(void, CAN_CODE) Can_176_CanFD_BusOff_CallBack_Pro \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
)
{
    (void)Can_176_CanFD_Wrapper_SetStopMode(u8Can_ControllerId);
    CanIf_ControllerBusOff(u8Can_ControllerId);
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_InitController \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint16, CAN_VAR) u8Can_BaudRateId \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Can_ret = (Std_ReturnType)E_NOT_OK;
    VAR(CANFDIntrCallback, AUTOMATIC) pCanfd_Callback;

    u8Can_ret = Can_176_CanFD_Wrapper_InitController(u8Can_ControllerId, u8Can_BaudRateId);
    pCanfd_Callback.error = g_pCanFd_CurConfig->CanFdControllerConfig[u8Can_ControllerId].ErrorNotification;
    pCanfd_Callback.busoff = &Can_176_CanFD_BusOff_CallBack_Pro;
    pCanfd_Callback.rx_received = &Can_176_CanFD_Rx_CallBack_Pro;
    pCanfd_Callback.tx_transferred = &Can_176_CanFD_Tx_CallBack_Pro;
    Can_176_CanFD_Wrapper_InitCallback(u8Can_ControllerId, &pCanfd_Callback);
    SchM_Enter_Can_176_CanFD_EXCLUSIVE_AREA_00();
    s_sCanFd_ControllerInfo[u8Can_ControllerId].txMbInfo_Primary.txMbState = MB_176_CANFD_IDLE;
    s_sCanFd_ControllerInfo[u8Can_ControllerId].txMbInfo_Primary.canIfPduId = 0U;
    s_sCanFd_ControllerInfo[u8Can_ControllerId].txMbInfo_Secondary.txMbState = MB_176_CANFD_IDLE;
    s_sCanFd_ControllerInfo[u8Can_ControllerId].txMbInfo_Secondary.canIfPduId = 0U;
    s_u8CanFd_gInterDisableCnt[u8Can_ControllerId] = 0U;
    SchM_Exit_Can_176_CanFD_EXCLUSIVE_AREA_00();
    if (u8Can_ret == (Std_ReturnType)E_OK)
    {
        /*
            [SWS_Can_00259] The function Can_Init shall set all CAN controllers in the state STOPPED.
        */
        g_eCanFd_ControllerState[u8Can_ControllerId] = CAN_CS_STOPPED;
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_DeInitController \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
)
{
    if ((Can_176_CanFD_Wrapper_isSleep(u8Can_ControllerId)) == TRUE)
    {
        Can_176_CanFD_Wrapper_exitSleep(u8Can_ControllerId);
    }
    Can_176_CanFD_Wrapper_DeInitController(u8Can_ControllerId);

    SchM_Enter_Can_176_CanFD_EXCLUSIVE_AREA_23();
    s_sCanFd_ControllerInfo[u8Can_ControllerId].txMbInfo_Primary.txMbState = MB_176_CANFD_IDLE;
    s_sCanFd_ControllerInfo[u8Can_ControllerId].txMbInfo_Primary.canIfPduId = 0U;
    s_sCanFd_ControllerInfo[u8Can_ControllerId].txMbInfo_Secondary.txMbState = MB_176_CANFD_IDLE;
    s_sCanFd_ControllerInfo[u8Can_ControllerId].txMbInfo_Secondary.canIfPduId = 0U;
    s_u8CanFd_gInterDisableCnt[u8Can_ControllerId] = 0U;
    SchM_Exit_Can_176_CanFD_EXCLUSIVE_AREA_23();
    g_eCanFd_ControllerState[u8Can_ControllerId] = CAN_CS_UNINIT;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_Wrapper_SetStartMode \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Can_ret = (Std_ReturnType)E_NOT_OK;
    if (CAN_CS_STOPPED != g_eCanFd_ControllerState[u8Can_Controller])
    {
        /*
            [SWS_Can_00409] When the function Can_SetControllerMode
            (CAN_CS_STARTED) is entered and the CAN controller is not in state STOPPED it 
            shall detect a invalid state transition
        */
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_176_CANFD_MODULE_ID, 
                                (uint8)CAN_176_CANFD_INSTANCE, 
                                CAN_176_CANFD_SID_SET_CONTROLLER_MODE, 
                                CAN_176_CANFD_E_TRANSITION);
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
        Can_176_CanFD_AutoSar_Wrapper_InitController(u8Can_Controller,  g_u16CanFd_CurBaudRateId[u8Can_Controller]);
        /*
            [SWS_Can_00425] Enabling of CAN interrupts shall not be executed, when CAN 
            interrupts have been disabled by function Can_DisableControllerInterrupts.
            [SWS_Can_00426] Disabling of CAN interrupts shall not be executed, when CAN 
            interrupts have been disabled by function Can_DisableControllerInterrupts.
        */
        if (s_u8CanFd_gInterDisableCnt[u8Can_Controller] == 0U)
        {
            Can_176_CanFD_Wrapper_DisableInterrupts(u8Can_Controller);
            Can_176_CanFD_Wrapper_EnableInterrupts(u8Can_Controller);
        }

        u8Can_ret = (Std_ReturnType)E_OK; 
    }
    return u8Can_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_Wrapper_SetSleepMode \
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
    if (CAN_CS_STARTED == g_eCanFd_ControllerState[u8Can_Controller])
    {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_176_CANFD_MODULE_ID, 
                            (uint8)CAN_176_CANFD_INSTANCE, 
                            CAN_176_CANFD_SID_SET_CONTROLLER_MODE, 
                            CAN_176_CANFD_E_TRANSITION);
#endif
    } 
    else 
    {
        if (CAN_CS_SLEEP == g_eCanFd_ControllerState[u8Can_Controller])
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
            u8Can_ret = Can_176_CanFD_Wrapper_EnterSleep(u8Can_Controller);
        }
    }
    return u8Can_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_Wrapper_SetStopMode \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Can_ret = (Std_ReturnType)E_NOT_OK;

    if (CAN_CS_STOPPED == g_eCanFd_ControllerState[u8Can_Controller])
    {
        u8Can_ret = (Std_ReturnType)E_OK;
    } 
    else 
    {
        if (CAN_CS_STARTED == g_eCanFd_ControllerState[u8Can_Controller])
        {
            /*
                [SWS_Can_00263] The function Can_SetControllerMode(CAN_CS_STOPPED)
                shall set the bits inside the CAN hardware such that the CAN controller stops 
                participating on the network.
                [SWS_Can_00282]  The function Can_SetControllerMode(CAN_CS_STOPPED)
                shall cancel pending messages.
            */
            Can_176_CanFD_Wrapper_DeInitController(u8Can_Controller);
            SchM_Enter_Can_176_CanFD_EXCLUSIVE_AREA_01();
            s_sCanFd_ControllerInfo[u8Can_Controller].txMbInfo_Primary.txMbState = MB_176_CANFD_IDLE;
            s_sCanFd_ControllerInfo[u8Can_Controller].txMbInfo_Primary.canIfPduId = 0U;
            s_sCanFd_ControllerInfo[u8Can_Controller].txMbInfo_Secondary.txMbState = MB_176_CANFD_IDLE;
            s_sCanFd_ControllerInfo[u8Can_Controller].txMbInfo_Secondary.canIfPduId = 0U;
            g_eCanFd_ControllerState[u8Can_Controller] = CAN_CS_STOPPED;
            SchM_Exit_Can_176_CanFD_EXCLUSIVE_AREA_01();
            u8Can_ret = (Std_ReturnType)E_OK;
        } 
        else if (CAN_CS_SLEEP == g_eCanFd_ControllerState[u8Can_Controller])
        {
            /*
                [SWS_Can_00267]  If the CAN HW does not support a sleep mode, the transition
                from SLEEP to STOPPED shall return from the logical sleep mode, but have no 
                effect to the CAN controller state (as the controller is already in stopped state)
            */
            if ((Can_176_CanFD_Wrapper_isSleep(u8Can_Controller)) == TRUE)
            {
                Can_176_CanFD_Wrapper_exitSleep(u8Can_Controller);
            }
            Can_176_CanFD_Wrapper_DeInitController(u8Can_Controller);
            SchM_Enter_Can_176_CanFD_EXCLUSIVE_AREA_02();
            s_sCanFd_ControllerInfo[u8Can_Controller].txMbInfo_Primary.txMbState = MB_176_CANFD_IDLE;
            s_sCanFd_ControllerInfo[u8Can_Controller].txMbInfo_Primary.canIfPduId = 0U;
            s_sCanFd_ControllerInfo[u8Can_Controller].txMbInfo_Secondary.txMbState = MB_176_CANFD_IDLE;
            s_sCanFd_ControllerInfo[u8Can_Controller].txMbInfo_Secondary.canIfPduId = 0U;
            g_eCanFd_ControllerState[u8Can_Controller] = CAN_CS_STOPPED;
            SchM_Exit_Can_176_CanFD_EXCLUSIVE_AREA_02();
            u8Can_ret = (Std_ReturnType)E_OK;
        } 
        else 
        {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError \
            ( \
                (uint16)CAN_176_CANFD_MODULE_ID, \
                (uint8)CAN_176_CANFD_INSTANCE, \
                CAN_176_CANFD_SID_SET_CONTROLLER_MODE, \
                CAN_176_CANFD_E_TRANSITION \
            );
#endif
        }
    }
    return u8Can_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_SetControllerMode \
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
        if ((Std_ReturnType)E_OK == Can_176_CanFD_Wrapper_SetStartMode(u8Can_Controller))
        {
            g_eCanFd_ControllerState[u8Can_Controller] = CAN_CS_STARTED;
            CanIf_ControllerModeIndication(u8Can_Controller, CAN_CS_STARTED);
            u8Can_ret = (Std_ReturnType)E_OK;
        }
        break;
    }
    case CAN_CS_SLEEP: 
    {
        if ((Std_ReturnType)E_OK == Can_176_CanFD_Wrapper_SetSleepMode(u8Can_Controller))
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
            g_eCanFd_ControllerState[u8Can_Controller] = CAN_CS_SLEEP;
            CanIf_ControllerModeIndication(u8Can_Controller, CAN_CS_SLEEP);
            u8Can_ret = (Std_ReturnType)E_OK;
        }
        break;
    }
    case CAN_CS_STOPPED: 
    {
        if ((Std_ReturnType)E_OK == Can_176_CanFD_Wrapper_SetStopMode(u8Can_Controller))
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
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_DisableInterrupts \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
)
{
    /*
        [SWS_Can_00426] Disabling of CAN interrupts shall not be executed, when CAN 
        interrupts have been disabled by function Can_DisableControllerInterrupts.
    */
    SchM_Enter_Can_176_CanFD_EXCLUSIVE_AREA_12();
    if (0U == s_u8CanFd_gInterDisableCnt[u8Can_Controller])
    {
        /*
            [SWS_Can_00049] The function Can_DisableControllerInterrupts shall access the 
            CAN controller registers to disable all interrupts for that CAN controller only, if 
            interrupts for that CAN Controller are enabled.
        */
        Can_176_CanFD_Wrapper_DisableInterrupts(u8Can_Controller);
    }
    SchM_Exit_Can_176_CanFD_EXCLUSIVE_AREA_12();
    /*
        [SWS_Can_00202] When Can_DisableControllerInterrupts has been called several 
        times, Can_EnableControllerInterrupts must be called as many times before the 
        interrupts are re-enabled.
    */
    s_u8CanFd_gInterDisableCnt[u8Can_Controller]++;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_EnableInterrupts \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
)
{
    if (s_u8CanFd_gInterDisableCnt[u8Can_Controller] > 0U)
    {
        /*
            [SWS_Can_00208] The function Can_EnableControllerInterrupts shall perform no 
            action when Can_DisableControllerInterrupts has not been called before.
        */
        SchM_Enter_Can_176_CanFD_EXCLUSIVE_AREA_14();
        s_u8CanFd_gInterDisableCnt[u8Can_Controller]--;
        if (s_u8CanFd_gInterDisableCnt[u8Can_Controller] == 0U)
        {
            Can_176_CanFD_Wrapper_EnableInterrupts(u8Can_Controller);
        }
        SchM_Exit_Can_176_CanFD_EXCLUSIVE_AREA_14();
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Can_ErrorStateType, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_GetErrorState \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
)
{
    VAR(Can_ErrorStateType, AUTOMATIC)  eCan_CtrlErrState = CAN_ERRORSTATE_BUSOFF;
    if ((Can_176_CanFD_Wrapper_IsBusOff(u8Can_Controller)) == TRUE)
    {
        eCan_CtrlErrState = CAN_ERRORSTATE_BUSOFF;
    } 
    else if ((Can_176_CanFD_Wrapper_IsErrorActive(u8Can_Controller)) == TRUE)
    {
        eCan_CtrlErrState = CAN_ERRORSTATE_ACTIVE;
    } 
    else 
    {
        eCan_CtrlErrState = CAN_ERRORSTATE_PASSIVE;
    }
    return eCan_CtrlErrState;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Can_ControllerStateType, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_GetMode \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
)
{
    VAR(Can_ControllerStateType, AUTOMATIC) eCan_Data = CAN_CS_UNINIT;
    if (u8Can_Controller < CAN_176_CANFD_CONTROLLER_COUNT)
    {
        eCan_Data = g_eCanFd_ControllerState[u8Can_Controller];
    }
    else
    {
        /* do nothing */
    }
    return eCan_Data;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint8, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_GetRxErrorCounter \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
)
{
    return Can_176_CanFD_Wrapper_GetRxErrorCounter(u8Can_Controller);
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint8, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_GetTxErrorCounter \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
)
{
    return Can_176_CanFD_Wrapper_GetTxErrorCounter(u8Can_Controller);
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_Write \
( \
    VAR(Can_HwHandleType, AUTOMATIC) u16Can_Hth, \
    P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) pCan_PduInfo \
)
{
    DEV_ASSERT(g_pCanFd_CurConfig != NULL_PTR);
    DEV_ASSERT(s_sCanFd_ControllerInfo != NULL_PTR);

    VAR(Std_ReturnType, AUTOMATIC) u8Can_ret = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, AUTOMATIC) u8Can_TempIdex = 0U;
    VAR(uint8, AUTOMATIC) u8Can_isIdel = 0U;
    P2VAR(CanFd_MBInfoType, AUTOMATIC, CAN_APPL_DATA) pCan_MbInfo = NULL_PTR;
    P2CONST(CanFd_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_TempHwObj = NULL_PTR;
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
#endif

    for (u8Can_TempIdex = 0; u8Can_TempIdex < CAN_176_CANFD_MB_COUNT; u8Can_TempIdex++)
    {
        pCan_TempHwObj = &g_pCanFd_CurConfig->CanFdHwObjectConfig[u8Can_TempIdex];/* polyspace RTE:IDP */
        pCan_Config = &g_pCanFd_CurConfig->CanFdControllerConfig[pCan_TempHwObj->CanControllerId];
        if ((u16Can_Hth == pCan_TempHwObj->CanObjectId) \
            && (pCan_TempHwObj->CanObjectType == CANFD_TRANSMIT))
        {
            /*
                [SWS_Can_00218] The function Can_Write shall return E_NOT_OK and if 
                development error detection for the CAN module is enabled shall raise the error 
                CAN_E_PARAM_DATA_LENGTH
                [SWS_Can_00486] The CAN Frame has to be sent according to the two most
                significant bits of Can_PduType->id. The CAN FD frame bit is only evaluated if
                CAN Controller is in CAN FD mode (valid CanControllerFdBaudrateConfig).
            */
            if ((Std_ReturnType)E_OK != Can_176_CanFd_AutoSar_CheckDataLength(pCan_PduInfo, pCan_TempHwObj))
            {
                    break;
            }
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            if((Std_ReturnType)E_OK != Can_176_CanFd_AutoSar_CheckMulticoreConfig(u32CanFd_CoreId, pCan_TempHwObj))
            {
                break;
            }
#endif
            else
            {
                if (pCan_TempHwObj->mbType == CANFD_TRANS_BUF_TYPE_PRIMARY)
                {
                    pCan_MbInfo = &s_sCanFd_ControllerInfo[pCan_TempHwObj->CanControllerId].txMbInfo_Primary;
                    if (pCan_MbInfo->txMbState == MB_176_CANFD_IDLE)/* polyspace RTE:IDP */
                    {
                        u8Can_isIdel = 1U;
                        pCan_MbInfo->txMbState = MB_176_CANFD_BUSY;
                    }
                }
                else
                {
                    pCan_MbInfo = &s_sCanFd_ControllerInfo[pCan_TempHwObj->CanControllerId].txMbInfo_Secondary;
                    u8Can_isIdel = 1U;
                }
                if (u8Can_isIdel == 1U)
                {
                    pCan_MbInfo->canIfPduId = pCan_PduInfo->swPduHandle;/* polyspace RTE:IDP */
                    u8Can_ret = (Std_ReturnType)Can_176_CanFd_AutoSar_HandleTriggerTransmit ( pCan_Config, pCan_PduInfo, \
                                    pCan_MbInfo, pCan_TempHwObj, u8Can_TempIdex );
                    if ((Std_ReturnType)E_OK != u8Can_ret)
                    {
                        /*
                            [SWS_Can_00214] The function Can_Write shall return CAN_BUSY if a 
                            preemptive call of Can_Write has been issued, that could not be handled reentrant 
                            (i.e. a call with the same HTH).
                        */
                        u8Can_ret = CAN_BUSY;
                    }
                    break;
                } 
                else 
                {
                    u8Can_ret = CAN_BUSY;
                }
            }
        }
    }
    return u8Can_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_TxPolling \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerIdx \
)
{
    DEV_ASSERT(g_pCanFd_CurConfig != NULL_PTR);

    P2VAR(CanFd_MBInfoType, AUTOMATIC, CAN_APPL_DATA) pCan_MbInfo_Pr = NULL_PTR;
    P2VAR(CanFd_MBInfoType, AUTOMATIC, CAN_APPL_DATA) pCan_MbInfo_Se = NULL_PTR;

#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/

    if (u32CanFd_CoreId == g_pCanFd_CurConfig->CanFdCoreMap[u8Can_ControllerIdx].CoreId)/* polyspace RTE:IDP */
    {
#endif
    pCan_MbInfo_Pr = &s_sCanFd_ControllerInfo[u8Can_ControllerIdx].txMbInfo_Primary;
    pCan_MbInfo_Se = &s_sCanFd_ControllerInfo[u8Can_ControllerIdx].txMbInfo_Secondary;
    /*
        [SWS_Can_00276] The function Can_Write shall store the swPduHandle that is 
        given inside the parameter PduInfo until the Can module calls the 
        CanIf_TxConfirmation for this request where the swPduHandle is given as parameter.
        [SWS_Can_00016] The Can module shall call CanIf_TxConfirmation to indicate a 
        successful transmission. It shall either called by the TX-interrupt service routine of 
        the corresponding HW resource or inside the Can_MainFunction_Write in case of 
        polling mode.
    */
    SchM_Enter_Can_176_CanFD_EXCLUSIVE_AREA_19();
    if ((pCan_MbInfo_Pr->txMbState == MB_176_CANFD_BUSY)
    && (FALSE == Can_176_CanFD_Wrapper_IsTransmitBusy(u8Can_ControllerIdx, CANFD_TRANS_BUF_TYPE_PRIMARY)))
    {
        CanIf_TxConfirmation(pCan_MbInfo_Pr->canIfPduId);
        pCan_MbInfo_Pr->txMbState = MB_176_CANFD_IDLE;
    }

    if (FALSE == Can_176_CanFD_Wrapper_IsTransmitBusy(u8Can_ControllerIdx, CANFD_TRANS_BUF_TYPE_SECONDARY))
    {
        CanIf_TxConfirmation(pCan_MbInfo_Se->canIfPduId);
        pCan_MbInfo_Se->txMbState = MB_176_CANFD_IDLE;
    }
    SchM_Exit_Can_176_CanFD_EXCLUSIVE_AREA_19();
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
    }
#endif
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_TxPollingMul \
( \
    VAR(uint8, AUTOMATIC) u8Can_HwObjectIdex, \
    VAR(uint8, AUTOMATIC) u8Can_PeriodIdx \
)
{
    VAR(uint8, AUTOMATIC) u8Can_ControllerId = 0U;
    P2CONST(CanFd_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_HwObject = NULL_PTR;
    P2VAR(CanFd_MBInfoType, AUTOMATIC, CAN_APPL_DATA) pCan_MbInfo = NULL_PTR;
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
#endif
    pCan_HwObject = &g_pCanFd_CurConfig->CanFdHwObjectConfig[u8Can_HwObjectIdex];
    u8Can_ControllerId = (uint8)(pCan_HwObject->CanControllerId);
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
    if (u32CanFd_CoreId == g_pCanFd_CurConfig->CanFdCoreMap[u8Can_ControllerId].CoreId)
    {
#endif
    if (pCan_HwObject->mbType == CANFD_TRANS_BUF_TYPE_PRIMARY)
    {
        pCan_MbInfo = &s_sCanFd_ControllerInfo[u8Can_ControllerId].txMbInfo_Primary;
    }
    else
    {
        pCan_MbInfo = &s_sCanFd_ControllerInfo[u8Can_ControllerId].txMbInfo_Secondary;
    }
    if ((pCan_HwObject->isPolling == 1U) && (pCan_HwObject->CanObjectType == CANFD_TRANSMIT)
        && (u8Can_PeriodIdx == pCan_HwObject->PeriodIndex))
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
        SchM_Enter_Can_176_CanFD_EXCLUSIVE_AREA_17();
        if (pCan_HwObject->mbType == CANFD_TRANS_BUF_TYPE_PRIMARY)
        {
            if (pCan_MbInfo->txMbState == MB_176_CANFD_BUSY)/* polyspace RTE:IDP */
            {
                CanIf_TxConfirmation(pCan_MbInfo->canIfPduId);
                pCan_MbInfo->txMbState = MB_176_CANFD_IDLE;
            }
        }
        else
        {
            CanIf_TxConfirmation(pCan_MbInfo->canIfPduId);/* polyspace RTE:IDP */
            pCan_MbInfo->txMbState = MB_176_CANFD_IDLE;
        }
        SchM_Exit_Can_176_CanFD_EXCLUSIVE_AREA_17();
    }
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
    }
#endif
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_RxPolling \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerIdx \
)
{
    VAR(uint8, AUTOMATIC) u8Can_HwObjectIdex = 0U;
    VAR(uint8, AUTOMATIC) u8Can_IsDataLost = 0U;
    VAR(boolean, AUTOMATIC) bCan_IsBuffer = FALSE;
    VAR(CANFDRxMsg, AUTOMATIC) rx_msg;
    VAR(uint32, AUTOMATIC) canfd_ret = CANFD_OK;
    VAR(uint32, AUTOMATIC) Can_Timeout = 0U;

    P2CONST(CanFd_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_HwObject = NULL_PTR;
    u8Can_IsDataLost = Can_176_CanFD_Wrapper_IsDataLost(u8Can_ControllerIdx);
    if (u8Can_IsDataLost == 1U)
    {
        (void)Det_ReportRuntimeError \
        ( \
            (uint16)CAN_176_CANFD_MODULE_ID, \
            (uint8)CAN_176_CANFD_INSTANCE, \
            (uint8)CAN_176_CANFD_SID_MAIN_FUNCTION_READ, \
            (uint8)CAN_176_CANFD_E_DATALOST \
        );
    }
    while ((CANFD_ERROR_NO_MSG_RECEIVED != canfd_ret) && (Can_Timeout < DEFAULT_TIMEOUT))
    {
        canfd_ret = Canfd_176_CanFd_Wrapper_Recv_Msg(u8Can_ControllerIdx, &rx_msg);
        if (canfd_ret == CANFD_OK)
        {
            for (u8Can_HwObjectIdex = 0; u8Can_HwObjectIdex < g_pCanFd_CurConfig->CanFdHwObjCount; u8Can_HwObjectIdex++)
            {
                pCan_HwObject = &g_pCanFd_CurConfig->CanFdHwObjectConfig[u8Can_HwObjectIdex];
                if ((pCan_HwObject->CanObjectType == CANFD_RECEIVE) && (pCan_HwObject->CanControllerId == u8Can_ControllerIdx))
                {
                    if ((pCan_HwObject->filterCode & (~pCan_HwObject->filterMask)) == (rx_msg.id & (~pCan_HwObject->filterMask)))
                    {
                        bCan_IsBuffer = TRUE;
                        break;
                    }
                }
            }
            if (bCan_IsBuffer == TRUE)
            {
                Can_176_CanFD_RxNotifiy(u8Can_ControllerIdx, pCan_HwObject->CanObjectId, &rx_msg);
            }
        }
        Can_Timeout++;
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(void, CAN_CODE) Can_176_CanFd_AutoSar_Wrapper_IsBufferMatching( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerIdx, \
    VAR(uint8, AUTOMATIC) u8Can_PeriodIdx, \
    P2VAR(CANFDRxMsg, AUTOMATIC, CAN_APPL_DATA) rx_msg
)
{
    VAR(uint8, AUTOMATIC) u8Can_HwObjectIdex = 0U;
    P2CONST(CanFd_hwObject, AUTOMATIC, CAN_APPL_DATA) pCan_HwObject = NULL_PTR;
    VAR(boolean, AUTOMATIC) bCan_IsBuffer = FALSE;
    for (u8Can_HwObjectIdex = 0; u8Can_HwObjectIdex < g_pCanFd_CurConfig->CanFdHwObjCount; u8Can_HwObjectIdex++)
    {
        pCan_HwObject = &g_pCanFd_CurConfig->CanFdHwObjectConfig[u8Can_HwObjectIdex];
        if ((pCan_HwObject->CanObjectType == CANFD_RECEIVE) && (pCan_HwObject->CanControllerId == u8Can_ControllerIdx) \
                && (u8Can_PeriodIdx == pCan_HwObject->PeriodIndex))
        {
            if ((pCan_HwObject->filterCode & (~pCan_HwObject->filterMask)) \
                    == (rx_msg->id & (~pCan_HwObject->filterMask)))
            {
                bCan_IsBuffer = TRUE;
                break;
            }
        }
    }
    if (bCan_IsBuffer == TRUE)
    {
        Can_176_CanFD_RxNotifiy(u8Can_ControllerIdx, pCan_HwObject->CanObjectId, rx_msg);
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_RxPollingMul \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerIdx, \
    VAR(uint8, AUTOMATIC) u8Can_PeriodIdx \
)
{
    VAR(uint8, AUTOMATIC) u8Can_IsDataLost = 0U;
    VAR(CANFDRxMsg, AUTOMATIC) rx_msg;
    VAR(uint32, AUTOMATIC) canfd_ret = CANFD_OK;
    VAR(uint32, AUTOMATIC) Can_Timeout = 0U;

    u8Can_IsDataLost = Can_176_CanFD_Wrapper_IsDataLost(u8Can_ControllerIdx);
    if (u8Can_IsDataLost == 1U)
    {
        (void)Det_ReportRuntimeError \
        ( \
            (uint16)CAN_176_CANFD_MODULE_ID, \
            (uint8)CAN_176_CANFD_INSTANCE, \
            (uint8)CAN_176_CANFD_SID_MAIN_FUNCTION_READ, \
            (uint8)CAN_176_CANFD_E_DATALOST \
        );
    }
    while ((CANFD_ERROR_NO_MSG_RECEIVED != canfd_ret) && (Can_Timeout < DEFAULT_TIMEOUT))
    {
        canfd_ret = Canfd_176_CanFd_Wrapper_Recv_Msg(u8Can_ControllerIdx, &rx_msg);
        if (canfd_ret == CANFD_OK)
        {
            Can_176_CanFd_AutoSar_Wrapper_IsBufferMatching(u8Can_ControllerIdx, u8Can_PeriodIdx, &rx_msg);
        }
        Can_Timeout++;
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_BusOffPolling \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
)
{
    if ((Can_176_CanFD_Wrapper_IsBusOff(u8Can_Controller)) == TRUE)
    {
        /*
            [SWS_Can_00272] After bus-off detection, the CAN controller shall transition to the 
            state STOPPED and the Can module shall ensure that the CAN controller doesn’t 
            participate on the network anymore.
            [SWS_Can_00273] After bus-off detection, the Can module shall cancel still 
            pending messages.
            [SWS_Can_00274] The Can module shall disable or suppress automatic bus-off recovery.
        */
        (void)Can_176_CanFD_Wrapper_SetStopMode(u8Can_Controller);
        /* 
            [SWS_Can_00020] The CanIf module is notified with the function CanIf_ControllerBusOff after 
            STOPPED state is reached referring to the corresponding CAN controller with 
            the abstract CanIf ControllerId
        */
        CanIf_ControllerBusOff(u8Can_Controller);
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_WakeUpPolling \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
)
{
    if ((Can_176_CanFD_Wrapper_isSleep(u8Can_Controller)) == TRUE)
    {
        SchM_Enter_Can_176_CanFD_EXCLUSIVE_AREA_22();
        Can_176_CanFD_Wrapper_exitSleep(u8Can_Controller);
        g_eCanFd_ControllerState[u8Can_Controller] = CAN_CS_STOPPED;
        SchM_Exit_Can_176_CanFD_EXCLUSIVE_AREA_22();
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_ControllerModePolling \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
)
{
    VAR(boolean, AUTOMATIC) bCan_Temp1 = FALSE;
    VAR(boolean, AUTOMATIC) bCan_Temp2 = FALSE;

    if (CAN_CS_SLEEP != g_eCanFd_ControllerState[u8Can_Controller])
    {
        /*
            [SWS_Can_00370] The function Can_Mainfunction_Mode shall poll a flag of the 
            CAN status register until the flag signals that the change takes effect and notify the 
            upper layer with function CanIf_ControllerModeIndication about a successful state 
            transition referring to the corresponding CAN controller with the abstract CanIf ControllerId.
        */
        bCan_Temp1 = (boolean)((CAN_CS_STARTED == g_eCanFd_ControllerState[u8Can_Controller]) ? TRUE : FALSE);
        bCan_Temp2 = (boolean)((CAN_CS_STOPPED == g_eCanFd_ControllerState[u8Can_Controller]) ? TRUE : FALSE);
        if ((Can_176_CanFD_Wrapper_isInitState(u8Can_Controller) == TRUE) && ((bCan_Temp1) == TRUE))
        {
            g_eCanFd_ControllerState[u8Can_Controller] = CAN_CS_STOPPED;
            /*
                [SWS_Can_00373]  The function Can_Mainfunction_Mode shall call the function
                CanIf_ControllerModeIndication to notify the upper layer about a successful state 
                transition of the corresponding CAN controller referred by abstract CanIf ControllerId, 
                in case the state transition was triggered by function Can_SetControllerMode.
            */
            CanIf_ControllerModeIndication(u8Can_Controller, CAN_CS_STOPPED);
        } 
        else if ((Can_176_CanFD_Wrapper_isInitState(u8Can_Controller) != TRUE) && ((bCan_Temp2) == TRUE))
        {
            g_eCanFd_ControllerState[u8Can_Controller] = CAN_CS_STARTED;
            CanIf_ControllerModeIndication(u8Can_Controller, CAN_CS_STARTED);
        }
        else
        {
            /* nothing */
        }
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#endif /* RESOURCE_SUPPORT_CANFD_IP */

#ifdef __cplusplus
}
#endif

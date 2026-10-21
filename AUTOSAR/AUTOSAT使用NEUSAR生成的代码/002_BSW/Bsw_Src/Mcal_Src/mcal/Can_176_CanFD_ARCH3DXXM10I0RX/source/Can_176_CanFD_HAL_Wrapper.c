/* PRQA S 0380, 1006, 3432 EOF */
/* PRQA S 0491, 2844, 0686, 3604 EOF */   /* CWE */
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

#include "Can_176_CanFD_HAL_Wrapper.h"
#include "Can_176_CanFD_LLDriver.h"
#include "status.h"
#include "SchM_Can_176_CanFD.h"

#ifdef RESOURCE_SUPPORT_CANFD_IP

#define CAN_176_CANFD_HAL_WRA_C_VENDOR_ID                     176
#define CAN_176_CANFD_HAL_WRA_C_AR_REL_MAJOR_VER              4
#define CAN_176_CANFD_HAL_WRA_C_AR_REL_MINOR_VER              4
#define CAN_176_CANFD_HAL_WRA_C_AR_REL_REV_VER                0
#define CAN_176_CANFD_HAL_WRA_C_SW_MAJOR_VER                  3
#define CAN_176_CANFD_HAL_WRA_C_SW_MINOR_VER                  0
#define CAN_176_CANFD_HAL_WRA_C_SW_PATCH_VER                  0

#if (CAN_176_CANFD_CFG_H_VENDOR_ID != CAN_176_CANFD_HAL_WRA_C_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_176_CANFD_HAL_WRA_C_VENDOR_ID "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_MAJOR_VER != CAN_176_CANFD_HAL_WRA_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_HAL_WRA_C_AR_REL_MAJOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_MINOR_VER != CAN_176_CANFD_HAL_WRA_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_HAL_WRA_C_AR_REL_MINOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_REV_VER != CAN_176_CANFD_HAL_WRA_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_HAL_WRA_C_AR_REL_REV_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_MAJOR_VER != CAN_176_CANFD_HAL_WRA_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_HAL_WRA_C_SW_MAJOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_MINOR_VER != CAN_176_CANFD_HAL_WRA_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_HAL_WRA_C_SW_MINOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_PATCH_VER != CAN_176_CANFD_HAL_WRA_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_HAL_WRA_C_SW_PATCH_VER "
#endif

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(uint16, CAN_CODE) CANFD_Wrapper_ConvertDataLengthCode \
( \
    VAR(uint8, AUTOMATIC) u8Can_MbDataLength \
)
{
    VAR(uint16, AUTOMATIC) u16Can_LengthCode = (uint16)0U;
    /*
        [SWS_Can_00502] If PduInfo->SduLength does not match possible DLC values 
        CanDrv shall use the next higher valid DLC for transmission with initialization of 
        unused bytes to the value of the corresponding CanFdPaddingValue.
    */
    VAR(uint8, AUTOMATIC) u8Can_Tmp = (uint8)0U;
    u8Can_Tmp = (uint8)((u8Can_MbDataLength + (uint8)3) / (uint8)4);
    switch (u8Can_Tmp)
    {
    case 0U:
    case 1U:
    case 2U:
    {
        u16Can_LengthCode = (uint16)u8Can_MbDataLength;
        break;
    }
    case 3U:
    {
        u16Can_LengthCode = ((uint16)9U);
        break;
    }
    case 4U:
    {
        u16Can_LengthCode = ((uint16)10U);
        break;
    }
    case 5U:
    {
        u16Can_LengthCode = ((uint16)11U);
        break;
    }
    case 6U:
    {
        u16Can_LengthCode = ((uint16)12U);
        break;
    }
    case 7U:
    case 8U:
    {
        u16Can_LengthCode = ((uint16)13U);
        break;
    }
    case 9U:
    case 10U:
    case 11U:
    case 12U:
    {
        u16Can_LengthCode = ((uint16)14U);
        break;
    }
    default:
    {
        u16Can_LengthCode = ((uint16)15U);
        break;
    }
    }
    
    return u16Can_LengthCode;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(uint32, CAN_CODE) CANFD_Wrapper_ConvertDLCToLength \
( \
    VAR(uint16, AUTOMATIC) u16Can_LengthCode \
)
{
    VAR(uint32, AUTOMATIC) u32Can_Length = 0U;

    if (u16Can_LengthCode <= (uint16)8U)
    {
        u32Can_Length = (uint32)u16Can_LengthCode;
    } 
    else 
    {
        switch (u16Can_LengthCode)
        {
        case 9U:
        {
            u32Can_Length = 12U;
            break;
        }
        case 10U:
        {
            u32Can_Length = 16U;
            break;
        }
        case 11U:
        {
            u32Can_Length = 20U;
            break;
        }
        case 12U:
        {
            u32Can_Length = 24U;
            break;
        }
        case 13U:
        {
            u32Can_Length = 32U;
            break;
        }
        case 14U:
        {
            u32Can_Length = 48U;
            break;
        }
        case 15U:
        {
            u32Can_Length = 64U;
            break;
        }
        default:
        {
            /* nothing */
            break;
        }
        }
    }
    
    return u32Can_Length;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_Wrapper_InitController \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint16, CAN_VAR) u8Can_BaudRateId \
)
{
    VAR(status_t, AUTOMATIC) eCan_Status = STATUS_ERROR;
    VAR(Std_ReturnType, AUTOMATIC) u8Can_Ret = (Std_ReturnType)E_NOT_OK;
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    /*
        [SWS_Can_00021] The desired CAN controller configuration can be selected with 
        the parameter Config.
    */
    pCan_Config = (&g_pCanFd_CurConfig->CanFdControllerConfig[u8Can_ControllerId]);/* polyspace RTE:IDP */

    eCan_Status = Canfd_LLD_Init(pCan_Config->controllerId, pCan_Config, u8Can_BaudRateId);

    if (eCan_Status == STATUS_SUCCESS)
    {
        u8Can_Ret = (Std_ReturnType)E_OK;
    }
    return u8Can_Ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_Wrapper_DeInitController \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
)
{
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCanFd_CurConfig->CanFdControllerConfig[u8Can_ControllerId]);/* polyspace RTE:IDP */
    (void)Canfd_LLD_DeInit(pCan_Config->controllerId);
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_Wrapper_EnterSleep \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
)
{
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCanFd_CurConfig->CanFdControllerConfig[u8Can_ControllerId]);/* polyspace RTE:IDP */
    Canfd_LLD_Sleep(pCan_Config->controllerId);

    return (Std_ReturnType)E_OK;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_Wrapper_DisableInterrupts \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
)
{
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCanFd_CurConfig->CanFdControllerConfig[u8Can_ControllerId]);
    Canfd_LLD_InterDisableAllSignals(pCan_Config->controllerId);
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_Wrapper_EnableInterrupts \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
)
{
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCanFd_CurConfig->CanFdControllerConfig[u8Can_ControllerId]);
    Canfd_LLD_InterruptInit(pCan_Config->controllerId, pCan_Config->interconfig);
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(boolean, CAN_CODE) Can_176_CanFD_Wrapper_IsBusOff \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
)
{
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCanFd_CurConfig->CanFdControllerConfig[u8Can_ControllerId]);
    return Canfd_LLD_IsBusOff(pCan_Config->controllerId);
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(boolean, CAN_CODE) Can_176_CanFD_Wrapper_IsErrorActive \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
)
{
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCanFd_CurConfig->CanFdControllerConfig[u8Can_ControllerId]);
    return Canfd_LLD_IsErrorActive(pCan_Config->controllerId);
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint8, CAN_CODE) Can_176_CanFD_Wrapper_GetRxErrorCounter \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
)
{
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCanFd_CurConfig->CanFdControllerConfig[u8Can_ControllerId]);
    
    return Canfd_LLD_Get_Error_Counter(pCan_Config->controllerId)->rx_cnt;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint8, CAN_CODE) Can_176_CanFD_Wrapper_GetTxErrorCounter \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
)
{
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCanFd_CurConfig->CanFdControllerConfig[u8Can_ControllerId]);
    return Canfd_LLD_Get_Error_Counter(pCan_Config->controllerId)->tx_cnt;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_Wrapper_InitCallback \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    CANFDIntrCallback* callback \
)
{
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCanFd_CurConfig->CanFdControllerConfig[u8Can_ControllerId]);
    Canfd_LLD_Init_Intr(pCan_Config->controllerId, callback);
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_Wrapper_Write \
( \
    VAR(uint8, AUTOMATIC) u8Can_Index, \
    P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) pCan_PduInfo, \
    VAR(CANFDTransBufType, AUTOMATIC) u8Can_Type, \
    VAR(uint8, AUTOMATIC) u8Can_PaddingValue, \
    VAR(boolean, AUTOMATIC) u8Can_BitRateSwitch \
)
{
    VAR(uint32, AUTOMATIC) u32Can_RetVal = 0U;
    VAR(Std_ReturnType, AUTOMATIC) u8Can_Ret = (Std_ReturnType)E_NOT_OK;
    VAR(CANFDTxMsg, AUTOMATIC) s_sCan_Tx_Msg = {0U};
    VAR(uint8, AUTOMATIC) u8Can_ControllerId = 0U;
    VAR(uint8, AUTOMATIC) u8Can_TempIdex = 0U;
    VAR(uint8, AUTOMATIC) u8Can_Dlc = 0U;
    VAR(uint32, AUTOMATIC) u32Can_TempMsgId = 0U;
    VAR(uint32, AUTOMATIC) msg_id;
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    u32Can_TempMsgId = pCan_PduInfo->id;

    u8Can_ControllerId = (uint8)(g_pCanFd_CurConfig->CanFdHwObjectConfig[u8Can_Index].CanControllerId);

    pCan_Config = (&g_pCanFd_CurConfig->CanFdControllerConfig[u8Can_ControllerId]);

    /*
        [SWS_Can_00237] The Can module shall not transmit messages triggered by 
        remote transmission requests.
    */
    s_sCan_Tx_Msg.is_remote = FALSE;/* polyspace RTE:OBAI */
    s_sCan_Tx_Msg.trans_buf = u8Can_Type;

    if (((u32Can_TempMsgId & CANFD_FD_ID_DESCRIPTOR) == CANFD_FD_ID_DESCRIPTOR)
         && (TRUE == u8Can_BitRateSwitch))
    {
        s_sCan_Tx_Msg.is_bit_rate_switch = TRUE;
    } 
    else 
    {
        s_sCan_Tx_Msg.is_bit_rate_switch = FALSE;
    }

    if ((u32Can_TempMsgId & CANFD_FD_ID_DESCRIPTOR) == CANFD_FD_ID_DESCRIPTOR)
    {
        s_sCan_Tx_Msg.is_fd_format_flag = TRUE;
    } 
    else 
    {
        s_sCan_Tx_Msg.is_fd_format_flag = FALSE;
    }

    if (CANFD_MSG_ID_EXT_MASK == (u32Can_TempMsgId & CANFD_MSG_ID_EXT_MASK))
    {
        s_sCan_Tx_Msg.is_extern = TRUE;
        u32Can_TempMsgId &= CANFD_TX_BUFFER_EXT_ID_MASK;
    } 
    else 
    {
        s_sCan_Tx_Msg.is_extern = FALSE;
        /* PRQA S 2922 EOF */
        u32Can_TempMsgId = ((u32Can_TempMsgId << CANFD_TX_BUFFER_STD_ID_SHIFT) \
                            & CANFD_TX_BUFFER_STD_ID_MASK) >> CANFD_TX_BUFFER_STD_ID_SHIFT;
    }

    s_sCan_Tx_Msg.id = u32Can_TempMsgId;

    u8Can_Dlc = (uint8)CANFD_Wrapper_ConvertDataLengthCode(pCan_PduInfo->length);
    s_sCan_Tx_Msg.data_len = (uint8)CANFD_Wrapper_ConvertDLCToLength((uint16)u8Can_Dlc);
    SchM_Enter_Can_176_CanFD_EXCLUSIVE_AREA_20();
    for (u8Can_TempIdex = 0; u8Can_TempIdex < pCan_PduInfo->length; u8Can_TempIdex++)
    {
        s_sCan_Tx_Msg.data.byte[u8Can_TempIdex] = pCan_PduInfo->sdu[u8Can_TempIdex]; /* polyspace RTE:OBAI */
    }
    SchM_Exit_Can_176_CanFD_EXCLUSIVE_AREA_20();
    if (s_sCan_Tx_Msg.data_len > pCan_PduInfo->length)
    {
        SchM_Enter_Can_176_CanFD_EXCLUSIVE_AREA_21();
        for (; u8Can_TempIdex < s_sCan_Tx_Msg.data_len; u8Can_TempIdex++)
        {
            s_sCan_Tx_Msg.data.byte[u8Can_TempIdex] = u8Can_PaddingValue;/* polyspace RTE:OBAI */
        }
        SchM_Exit_Can_176_CanFD_EXCLUSIVE_AREA_21();
    }
    u32Can_RetVal = Canfd_LLD_Send_Msg(pCan_Config->controllerId, &s_sCan_Tx_Msg, &msg_id); /* PRQA S 2934 */

    if (CANFD_OK == u32Can_RetVal)
    {
        u8Can_Ret = (Std_ReturnType)E_OK;
    } 
    else 
    {
        u8Can_Ret = CAN_BUSY;
    }

    return u8Can_Ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint8, CAN_CODE) Can_176_CanFD_Wrapper_IsDataLost \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
)
{
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCanFd_CurConfig->CanFdControllerConfig[u8Can_ControllerId]);
    return BOOLTOUINT(Canfd_LLD_IsDataLost(pCan_Config->controllerId));
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(boolean, CAN_CODE) Can_176_CanFD_Wrapper_isInitState(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCanFd_CurConfig->CanFdControllerConfig[u8Can_ControllerId]);
    return Canfd_LLD_isInitState(pCan_Config->controllerId);
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(boolean, CAN_CODE) Can_176_CanFD_Wrapper_isSleep(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCanFd_CurConfig->CanFdControllerConfig[u8Can_ControllerId]);/* polyspace RTE:IDP */
    return Canfd_LLD_isSleep(pCan_Config->controllerId);
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_Wrapper_exitSleep(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCanFd_CurConfig->CanFdControllerConfig[u8Can_ControllerId]);
    Canfd_LLD_Wakeup(pCan_Config->controllerId);
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint32, CAN_CODE) Can_176_CanFD_Wrapper_IsTransmitBusy
(
    VAR(uint32,AUTOMATIC) u8Can_ControllerId,
    VAR(CANFDTransBufType,AUTOMATIC) type
)
{
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCanFd_CurConfig->CanFdControllerConfig[u8Can_ControllerId]);
    return Can_LLD_Can_IsTransmitBusy((uint32)pCan_Config->controllerId, type);
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint32, CAN_CODE) Canfd_176_CanFd_Wrapper_Recv_Msg \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    P2VAR(CANFDRxMsg, AUTOMATIC, CAN_APPL_DATA) rx_msg \
)
{
    P2CONST(CANFDConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCanFd_CurConfig->CanFdControllerConfig[u8Can_ControllerId]);
    return Canfd_LLD_Recv_Msg(pCan_Config->controllerId, rx_msg);
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#endif /* RESOURCE_SUPPORT_CANFD_IP */

#ifdef __cplusplus
}
#endif

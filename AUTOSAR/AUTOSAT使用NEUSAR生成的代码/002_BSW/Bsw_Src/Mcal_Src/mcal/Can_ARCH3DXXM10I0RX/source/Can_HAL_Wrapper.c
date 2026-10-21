/* PRQA S 0380, 1006, 2922, 3432, 0310, 2985, 0488, 0751, 3305 EOF */
/* PRQA S 0491, 2844, 2934, 3408, 0686, 3604 EOF */   /* CWE */
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
*   @file    Can_HAL_Wrapper.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Can MCAL driver.
*
*   @addtogroup Can
*   @{
*/
#ifdef __cplusplus
extern "C"{
#endif

#include "Can_HAL_Wrapper.h"
#include "Can_LLDriver.h"
#include "Det.h"
#include "CanIf_Cbk.h"
#include "SchM_Can.h"
#include "derivative.h"

#define CAN_HAL_WRA_C_VENDOR_ID                     176
#define CAN_HAL_WRA_C_AR_REL_MAJOR_VER              4
#define CAN_HAL_WRA_C_AR_REL_MINOR_VER              4
#define CAN_HAL_WRA_C_AR_REL_REV_VER                0
#define CAN_HAL_WRA_C_SW_MAJOR_VER                  3
#define CAN_HAL_WRA_C_SW_MINOR_VER                  0
#define CAN_HAL_WRA_C_SW_PATCH_VER                  0

#if (CAN_CFG_H_VENDOR_ID != CAN_HAL_WRA_C_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_HAL_WRA_C_VENDOR_ID "
#endif
#if (CAN_CFG_H_AR_REL_MAJOR_VER != CAN_HAL_WRA_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_HAL_WRA_C_AR_REL_MAJOR_VER "
#endif
#if (CAN_CFG_H_AR_REL_MINOR_VER != CAN_HAL_WRA_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_HAL_WRA_C_AR_REL_MINOR_VER "
#endif
#if (CAN_CFG_H_AR_REL_REV_VER != CAN_HAL_WRA_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_HAL_WRA_C_AR_REL_REV_VER "
#endif
#if (CAN_CFG_H_SW_MAJOR_VER != CAN_HAL_WRA_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_HAL_WRA_C_SW_MAJOR_VER "
#endif
#if (CAN_CFG_H_SW_MINOR_VER != CAN_HAL_WRA_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_HAL_WRA_C_SW_MINOR_VER "
#endif
#if (CAN_CFG_H_SW_PATCH_VER != CAN_HAL_WRA_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_HAL_WRA_C_SW_PATCH_VER "
#endif

extern VAR(uint16, AUTOMATIC) g_u16Can_CurBaudRateId[CAN_CONTROLLER_COUNT];
extern CONSTP2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) g_mcanBase[MCAN_INSTANCE_COUNT];
#if defined(RESOURCE_SUPPORT_MCAN_DMU)
extern VAR(mcan_dmu_intr_callback, CAN_VAR) g_dmu_intr_callback[MCAN_INSTANCE_COUNT];
#endif

#define CAN_START_SEC_VAR_INIT
#include "Can_MemMap.h"
static VAR(rxCallBack_Type, AUTOMATIC) s_pRxCallback_pro = NULL_PTR;
#define CAN_STOP_SEC_VAR_INIT
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_INIT
#include "Can_MemMap.h"
static VAR(txCallBack_Type, AUTOMATIC) s_pTxCallback_pro = NULL_PTR;
#define CAN_STOP_SEC_VAR_INIT
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_INIT
#include "Can_MemMap.h"
static VAR(busoffCallBack_Type, AUTOMATIC) s_pBusOffxCallback_pro = NULL_PTR;
#define CAN_STOP_SEC_VAR_INIT
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_INIT
#include "Can_MemMap.h"
static VAR(errorCallBack_Type, AUTOMATIC) s_pErrorCallback_pro = NULL_PTR;
#define CAN_STOP_SEC_VAR_INIT
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_INIT
#include "Can_MemMap.h"
static VAR(mrafCallBack_Type, AUTOMATIC) s_pMRAFCallback_pro = NULL_PTR;
#define CAN_STOP_SEC_VAR_INIT
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_INIT
#include "Can_MemMap.h"
VAR(Controller_mapping, AUTOMATIC) s_sInsToCtrlMap[MCAN_MOD_BUTT] =
{
    {MCAN_MOD_ID_1,  0},
    {MCAN_MOD_ID_2,  0},
    {MCAN_MOD_ID_3,  0},
    {MCAN_MOD_ID_4,  0},
    {MCAN_MOD_ID_5,  0},
    {MCAN_MOD_ID_6,  0},
    {MCAN_MOD_ID_7,  0},
    {MCAN_MOD_ID_8,  0},
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_9
    {MCAN_MOD_ID_9,  0},
    {MCAN_MOD_ID_10, 0},
    {MCAN_MOD_ID_11, 0},
    {MCAN_MOD_ID_12, 0},
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_9 */
	
};
#define CAN_STOP_SEC_VAR_INIT
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) MCAN_ProcessIrq_Id1 \
(
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint32, AUTOMATIC) IR_REG_VAULE
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) MCAN_ProcessIrq_Id2 \
(
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint32, AUTOMATIC) IR_REG_VAULE
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) MCAN_ProcessIrq_Id3 \
(
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint32, AUTOMATIC) IR_REG_VAULE
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) MCAN_ProcessIrq_Id4 \
(
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint32, AUTOMATIC) IR_REG_VAULE
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint16, CAN_CODE) MCAN_Wrapper_ConvertDataLengthCode \
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
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint32, CAN_CODE) MCAN_Wrapper_ConvertDLCToLength \
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
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_Wrapper_InitController(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    VAR(status_t, AUTOMATIC) eCan_Status = STATUS_ERROR;
    VAR(Std_ReturnType, AUTOMATIC) u8Can_Ret = (Std_ReturnType)E_NOT_OK;
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    /*
        [SWS_Can_00021] The desired CAN controller configuration can be selected with 
        the parameter Config.
    */
    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]);/* polyspace RTE:IDP */

    eCan_Status = Can_LLD_Init(u8Can_ControllerId, pCan_Config->controllerId, pCan_Config);/* polyspace RTE:NIV,IDP */

    s_sInsToCtrlMap[pCan_Config->controllerId].controllerId = u8Can_ControllerId;/* polyspace RTE:OBAI *//* polyspace RTE:NIV */
    if (eCan_Status == STATUS_SUCCESS)
    {
        u8Can_Ret = (Std_ReturnType)E_OK;
    }
    return u8Can_Ret;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_Wrapper_DeInitController(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]);/* polyspace RTE:IDP */
    Can_LLD_Deint(pCan_Config->controllerId);/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_Wrapper_EnterSleep(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]);/* polyspace RTE:IDP */
    Can_LLD_EnterSleepStatus(pCan_Config->controllerId);/* polyspace RTE:NIV,IDP */

    return (Std_ReturnType)E_OK;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_Wrapper_DisableInterrupts(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]); /* polyspace RTE:IDP */
    Can_LLD_InterDisableAllSignals(pCan_Config->controllerId);/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_Wrapper_EnableInterrupts(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]); /* polyspace RTE:IDP */
    Can_LLD_InterruptInit(pCan_Config->controllerId, pCan_Config->interconfig); /* polyspace RTE:NIV,NIP,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_Wrapper_IsBusOff(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]);/* polyspace RTE:IDP */
    return Can_LLD_IsBusOff(pCan_Config->controllerId);/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_Wrapper_IsErrorActive(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]);
    return Can_LLD_IsErrorActive(pCan_Config->controllerId);/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_Wrapper_GetRxErrorCounter(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]);/* polyspace RTE:IDP */
    return Can_LLD_GetRxErrorCounter(pCan_Config->controllerId);/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_Wrapper_GetTxErrorCounter(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]);/* polyspace RTE:IDP */
    return Can_LLD_GetTxErrorCounter(pCan_Config->controllerId);/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_Wrapper_Write \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) pCan_PduInfo, \
    VAR(uint8, AUTOMATIC) u8Can_MBId, \
    VAR(uint8, AUTOMATIC) u8Can_PaddingValue \
)
{
    DEV_ASSERT(u8Can_ControllerId < CAN_CONTROLLER_COUNT);

    VAR(Std_ReturnType, AUTOMATIC) u8Can_Ret = (Std_ReturnType)E_NOT_OK;
    VAR(can_msg_struct, AUTOMATIC) sCan_Tx_Msg = {0U};
    VAR(uint8, AUTOMATIC) u8Can_TempIdex = 0U;
    VAR(uint32, AUTOMATIC) u32Can_TempMsgId = 0U;
    VAR(uint32, AUTOMATIC) u32Can_TempMsgLen = 0U;
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    u32Can_TempMsgId = pCan_PduInfo->id;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]);

    sCan_Tx_Msg.direction = TX_DIR;/* polyspace RTE:OBAI */
    sCan_Tx_Msg.esi = FALSE;
    /*
        [SWS_Can_00237] The Can module shall not transmit messages triggered by 
        remote transmission requests.
    */
    sCan_Tx_Msg.remote = FALSE;

    if ((TRUE == pCan_Config->timingconfig[g_u16Can_CurBaudRateId[u8Can_ControllerId]].brs_ena) /* polyspace RTE:NIV,IDP,OBAI,NIP */
            && ((u32Can_TempMsgId & MCAN_FD_ID_DESCRIPTOR) == MCAN_FD_ID_DESCRIPTOR))
    {
        sCan_Tx_Msg.brs = TRUE;
    }
    else
    {
        sCan_Tx_Msg.brs = FALSE;
    }

    if ((TRUE == pCan_Config->timingconfig[g_u16Can_CurBaudRateId[u8Can_ControllerId]].fd_ena) /* polyspace RTE:OBAI *//* polyspace RTE:NIV */
            && ((u32Can_TempMsgId & MCAN_FD_ID_DESCRIPTOR) == MCAN_FD_ID_DESCRIPTOR))
    {
        sCan_Tx_Msg.fdf = TRUE;
    }
    else
    {
        sCan_Tx_Msg.fdf = FALSE;
    }

    if (MCAN_MSG_ID_EXT_MASK == (u32Can_TempMsgId & MCAN_MSG_ID_EXT_MASK))
    {
        sCan_Tx_Msg.idtype = EXTENDED_ID;
        u32Can_TempMsgId &= MCAN_TX_BUFFER_EXT_ID_MASK;
    }
    else
    {
        sCan_Tx_Msg.idtype = STANDARD_ID;
        u32Can_TempMsgId = ((u32Can_TempMsgId << MCAN_TX_BUFFER_STD_ID_SHIFT) \
                            & MCAN_TX_BUFFER_STD_ID_MASK) >> MCAN_TX_BUFFER_STD_ID_SHIFT;
    }

    sCan_Tx_Msg.id = u32Can_TempMsgId;
    sCan_Tx_Msg.mm = 0x1U;
    sCan_Tx_Msg.efc = FALSE;

    sCan_Tx_Msg.dlc = MCAN_Wrapper_ConvertDataLengthCode(pCan_PduInfo->length);
    u32Can_TempMsgLen = MCAN_Wrapper_ConvertDLCToLength(sCan_Tx_Msg.dlc);
    SchM_Enter_Can_EXCLUSIVE_AREA_20();
    for (u8Can_TempIdex = 0; u8Can_TempIdex < pCan_PduInfo->length; u8Can_TempIdex++)
    {
        sCan_Tx_Msg.data[u8Can_TempIdex] = pCan_PduInfo->sdu[u8Can_TempIdex];/* polyspace RTE:OBAI */
    }
    SchM_Exit_Can_EXCLUSIVE_AREA_20();
    if (u32Can_TempMsgLen > pCan_PduInfo->length)
    {
        SchM_Enter_Can_EXCLUSIVE_AREA_21();
        for (; u8Can_TempIdex < u32Can_TempMsgLen; u8Can_TempIdex++)
        {
            sCan_Tx_Msg.data[u8Can_TempIdex] = u8Can_PaddingValue;
        }
        SchM_Exit_Can_EXCLUSIVE_AREA_21();
    }

    (void)Can_LLD_TxSendDedicatedMsg(pCan_Config->controllerId, &sCan_Tx_Msg, u8Can_MBId);/* polyspace RTE:NIV */
    u8Can_Ret = (Std_ReturnType)E_OK;

    return u8Can_Ret;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_Wrapper_IsFDEnabled(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]);
    return Can_LLD_IsFDEnabled(pCan_Config->controllerId);/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_Wrapper_TxOccurred \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint32, AUTOMATIC) u32Can_Tx_Buf_Index \
)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]);
    return Can_LLD_TxTranOccured(pCan_Config->controllerId, u32Can_Tx_Buf_Index);/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint32, CAN_CODE) Can_Wrapper_RxRecFifoMsg \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint32, AUTOMATIC) u32Can_Rx_Fifo_Number \
)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]);
    return Can_LLD_RxRecFifoMsg(pCan_Config->controllerId, u32Can_Rx_Fifo_Number); /* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_Wrapper_IsDataLost \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint32, AUTOMATIC) u32Can_Rx_Fifo_Number \
)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]);
    return Can_LLD_IsDataLost(pCan_Config->controllerId, u32Can_Rx_Fifo_Number); /* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint32, CAN_CODE) Can_Wrapper_RxDedicatedBufferProcessNewMsg \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]);
    return Can_LLD_RxDedicateBufProcNewMsg(pCan_Config->controllerId);  /* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_Wrapper_isInitState(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]); /* polyspace RTE:IDP */
    return Can_LLD_isInitState(pCan_Config->controllerId);/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_Wrapper_isSleep(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]); /* polyspace RTE:IDP */
    return Can_LLD_isSleep(pCan_Config->controllerId);/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_Wrapper_exitSleep(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]);
    Can_LLD_WakeUp(pCan_Config->controllerId);/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_Wrapper_InitCallback \
( \
    VAR(rxCallBack_Type, AUTOMATIC) rxCallback, \
    VAR(txCallBack_Type, AUTOMATIC) txCallback, \
    VAR(busoffCallBack_Type, AUTOMATIC) busOffCallback, \
    CONST(errorCallBack_Type, AUTOMATIC) errorCallback, \
    CONST(mrafCallBack_Type, AUTOMATIC) mrafCallback \
)
{
    s_pRxCallback_pro = rxCallback;
    s_pTxCallback_pro = txCallback;
    s_pBusOffxCallback_pro = busOffCallback;
    s_pErrorCallback_pro = errorCallback;
    s_pMRAFCallback_pro = mrafCallback;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_Wrapper_SetTimeOut(VAR(uint32, CAN_VAR) u32Can_TimeOutDuration)
{
    Can_LLD_SetTimeOut(u32Can_TimeOutDuration);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_Wrapper_RsetInit(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]);
    Can_LLD_RsetInit(pCan_Config->controllerId); /* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_Wrapper_isTxInterruptMb \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint32, AUTOMATIC) u32Can_Tx_Buf_Index \
)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]); /* polyspace RTE:IDP */
    return Can_LLD_isTxInterruptMb(pCan_Config->controllerId, u32Can_Tx_Buf_Index); /* polyspace RTE:NIV *//* polyspace RTE:IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/*
    [SWS_Can_00033] The Can module shall implement the interrupt service routines 
    for all CAN Hardware Unit interrupts that are needed.
    [SWS_Can_00419] The Can module shall disable all unused interrupts in the CAN controller.
    [SWS_Can_00420] The Can module shall reset the interrupt flag at the end of the 
    ISR (if not done automatically by hardware).
*/
CAN_INLINE FUNC(void, CAN_CODE) MCAN_ProcessIrq_Id1 \
(
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint32, AUTOMATIC) IR_REG_VAULE
)
{
    if((IR_REG_VAULE & MCAN_IR_RF0N_MASK) != 0U)
    {
        (void)Can_LLD_RxRecFifoMsg(eCan_Instance, 0U);

        if ((u8Can_ControllerId < CAN_CONTROLLER_COUNT) && (NULL_PTR != s_pRxCallback_pro))/* polyspace RTE:IDP */
        {
            s_pRxCallback_pro(u8Can_ControllerId);
        }
    }

    if((IR_REG_VAULE & MCAN_IR_RF0W_MASK) != 0U)
    {
        (void)Can_LLD_RxRecFifoMsg(eCan_Instance, 0U);

        if ((u8Can_ControllerId < CAN_CONTROLLER_COUNT) && (NULL_PTR != s_pRxCallback_pro))
        {
            s_pRxCallback_pro(u8Can_ControllerId);
        }
    }

    if((IR_REG_VAULE & MCAN_IR_RF0F_MASK) != 0U)
    {
        if (u8Can_ControllerId < CAN_CONTROLLER_COUNT)
        {
            (void)Det_ReportRuntimeError \
            ( \
                (uint16)CAN_MODULE_ID, \
                (uint8)CAN_INSTANCE, \
                (uint8)CAN_SID_MAIN_FUNCTION_READ, \
                (uint8)CAN_E_DATALOST \
            );
        }
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) MCAN_ProcessIrq_Id2 \
(
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint32, AUTOMATIC) IR_REG_VAULE
)
{
    if((IR_REG_VAULE & MCAN_IR_RF0L_MASK) != 0U)
    {
        if (u8Can_ControllerId < CAN_CONTROLLER_COUNT)
        {
            (void)Det_ReportRuntimeError \
            ( \
                (uint16)CAN_MODULE_ID, \
                (uint8)CAN_INSTANCE, \
                (uint8)CAN_SID_MAIN_FUNCTION_READ, \
                (uint8)CAN_E_DATALOST \
            );
        }
    }

    if((IR_REG_VAULE & MCAN_IR_RF1N_MASK) != 0U)
    {
        (void)Can_LLD_RxRecFifoMsg(eCan_Instance, 1U);

        if ((u8Can_ControllerId < CAN_CONTROLLER_COUNT) && (NULL_PTR != s_pRxCallback_pro))
        {
            s_pRxCallback_pro(u8Can_ControllerId);
        }
    }

    if((IR_REG_VAULE & MCAN_IR_RF1W_MASK) != 0U)
    {
        (void)Can_LLD_RxRecFifoMsg(eCan_Instance, 1U);

        if ((u8Can_ControllerId < CAN_CONTROLLER_COUNT) && (NULL_PTR != s_pRxCallback_pro))
        {
            s_pRxCallback_pro(u8Can_ControllerId);
        }
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) MCAN_ProcessIrq_Id3 \
(
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint32, AUTOMATIC) IR_REG_VAULE
)
{
    if((IR_REG_VAULE & MCAN_IR_RF1F_MASK) != 0U)
    {
        if (u8Can_ControllerId < CAN_CONTROLLER_COUNT)
        {
            (void)Det_ReportRuntimeError \
            ( \
                (uint16)CAN_MODULE_ID, \
                (uint8)CAN_INSTANCE, \
                (uint8)CAN_SID_MAIN_FUNCTION_READ, \
                (uint8)CAN_E_DATALOST \
            );
        }
    }

    if((IR_REG_VAULE & MCAN_IR_RF1L_MASK) != 0U)
    {
        if (u8Can_ControllerId < CAN_CONTROLLER_COUNT)
        {
            (void)Det_ReportRuntimeError \
            ( \
                (uint16)CAN_MODULE_ID, \
                (uint8)CAN_INSTANCE, \
                (uint8)CAN_SID_MAIN_FUNCTION_READ, \
                (uint8)CAN_E_DATALOST \
            );
        }
    }

    if((IR_REG_VAULE & MCAN_IR_TC_MASK) != 0U)
    {
        if ((u8Can_ControllerId < CAN_CONTROLLER_COUNT) && (NULL_PTR != s_pTxCallback_pro))
        {
            s_pTxCallback_pro(u8Can_ControllerId);
        }
    }

    if((IR_REG_VAULE & MCAN_IR_DRX_MASK) != 0U)
    {
        (void)Can_LLD_RxDedicateBufProcNewMsg(eCan_Instance);
        if ((u8Can_ControllerId < CAN_CONTROLLER_COUNT) && (NULL_PTR != s_pRxCallback_pro))
        {
            s_pRxCallback_pro(u8Can_ControllerId);
		}
	}
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) MCAN_ProcessIrq0(VAR(MCANModId, AUTOMATIC) eCan_Instance)
{
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base = g_mcanBase[eCan_Instance];
    VAR(uint8, AUTOMATIC) u8Can_ControllerId = 0U;
    VAR(uint32, AUTOMATIC) IR_REG_VAULE = ((base->IR.R) & (~(base->ILS.R)));/* polyspace RTE:NIV,IDP */

    base->IR.R = IR_REG_VAULE;
    u8Can_ControllerId = s_sInsToCtrlMap[eCan_Instance].controllerId;
	MCAN_ProcessIrq_Id1(eCan_Instance, u8Can_ControllerId, IR_REG_VAULE);
    MCAN_ProcessIrq_Id2(eCan_Instance, u8Can_ControllerId, IR_REG_VAULE);
    MCAN_ProcessIrq_Id3(eCan_Instance, u8Can_ControllerId, IR_REG_VAULE);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) MCAN_ProcessIrq_Id4 \
(
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint32, AUTOMATIC) IR_REG_VAULE
)
{
	if((IR_REG_VAULE & MCAN_IR_PEA_MASK) != 0U)
    {
        if ((u8Can_ControllerId < CAN_CONTROLLER_COUNT) && (NULL_PTR != s_pErrorCallback_pro))
        {
            s_pErrorCallback_pro(u8Can_ControllerId);/* polyspace RTE:COR */
        }
    }

    if((IR_REG_VAULE & MCAN_IR_PED_MASK) != 0U)
    {
        if ((u8Can_ControllerId < CAN_CONTROLLER_COUNT) && (NULL_PTR != s_pErrorCallback_pro))
        {
            s_pErrorCallback_pro(u8Can_ControllerId);/* polyspace RTE:COR */
        }
    }

    if((IR_REG_VAULE & MCAN_IR_ARA_MASK) != 0U)
    {
        if ((u8Can_ControllerId < CAN_CONTROLLER_COUNT) && (NULL_PTR != s_pErrorCallback_pro))
        {
            s_pErrorCallback_pro(u8Can_ControllerId);/* polyspace RTE:COR */
        }
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/*
    [SWS_Can_00033] The Can module shall implement the interrupt service routines 
    for all CAN Hardware Unit interrupts that are needed.
    [SWS_Can_00419] The Can module shall disable all unused interrupts in the CAN controller.
    [SWS_Can_00420] The Can module shall reset the interrupt flag at the end of the 
    ISR (if not done automatically by hardware).
*/
FUNC(void, CAN_CODE) MCAN_ProcessIrq1(VAR(MCANModId, AUTOMATIC) eCan_Instance)
{
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base = g_mcanBase[eCan_Instance];
    VAR(uint8, AUTOMATIC) u8Can_ControllerId = 0U;

    VAR(uint32, AUTOMATIC) IR_REG_VAULE = ((base->IR.R) & (base->ILS.R));/* polyspace RTE:NIV,IDP */
    VAR(uint32, AUTOMATIC) PSR_REG_VAULE = base->PSR.R;/* polyspace RTE:NIV */

    base->IR.R = IR_REG_VAULE;
    u8Can_ControllerId = s_sInsToCtrlMap[eCan_Instance].controllerId;

    if((IR_REG_VAULE & MCAN_IR_MRAF_MASK) != 0U)
    {
        if ((u8Can_ControllerId < CAN_CONTROLLER_COUNT) && (NULL_PTR != s_pMRAFCallback_pro))
        {
            s_pMRAFCallback_pro(u8Can_ControllerId);/* polyspace RTE:COR */
        }
    }

    if((IR_REG_VAULE & MCAN_IR_BO_MASK) != 0U)
    {
        if ((PSR_REG_VAULE & MCAN_PSR_BO_MASK) != 0U)
        {
            if ((u8Can_ControllerId < CAN_CONTROLLER_COUNT) && (NULL_PTR != s_pBusOffxCallback_pro))
            {
                s_pBusOffxCallback_pro(u8Can_ControllerId);
            }
        }
    }
    MCAN_ProcessIrq_Id4(u8Can_ControllerId, IR_REG_VAULE);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#if defined(RESOURCE_SUPPORT_MCAN_DMU)
#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_DMU_IntrCallback(VAR(MCANModId, AUTOMATIC) instance)
{
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base = g_mcanBase[instance];/* polyspace RTE:OBAI */
    VAR(uint32_t, AUTOMATIC) DMUIR_REG_VAULE = (base->DMUIR.R) & (base->DMUIE.R);/* polyspace RTE:NIV */
    base->DMUIR.R = DMUIR_REG_VAULE;
    if ((DMUIR_REG_VAULE & M_CAN_DMUIR_TXEE_MASK) != 0U)
    {
        if(g_dmu_intr_callback[instance].tx_fifo_dmu_transfered != NULL)
        {
            g_dmu_intr_callback[instance].tx_fifo_dmu_transfered(instance);/* polyspace RTE:COR */
        }
    }
    if ((DMUIR_REG_VAULE & M_CAN_DMUIR_RX0ED_MASK) != 0U)
    {
        MCAN_GetDmaForRxFIFO(instance, 0U);
        if(g_dmu_intr_callback[instance].rx_fifo_0_dmu_received != NULL)
        {
            g_dmu_intr_callback[instance].rx_fifo_0_dmu_received(instance);/* polyspace RTE:COR */
        }
    }
    if ((DMUIR_REG_VAULE & M_CAN_DMUIR_RX1ED_MASK) != 0U)
    {
        MCAN_GetDmaForRxFIFO(instance, 1U);
        if(g_dmu_intr_callback[instance].rx_fifo_1_dmu_received != NULL)
        {
            g_dmu_intr_callback[instance].rx_fifo_1_dmu_received(instance);/* polyspace RTE:COR */
        }
    }
    if ((DMUIR_REG_VAULE & M_CAN_DMUIR_TXEED_MASK) != 0U)
    {
        if(g_dmu_intr_callback[instance].tx_event_dmu_handler != NULL)
        {
            g_dmu_intr_callback[instance].tx_event_dmu_handler(instance);/* polyspace RTE:COR */
        }
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_Wrapper_Dmu_Write(VAR(uint8, AUTOMATIC) dmuIndex, VAR(uint8, AUTOMATIC) ControllerId, P2VAR(Can_PduType, AUTOMATIC, CAN_APPL_DATA) PduInfo)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;
    VAR(uint32, AUTOMATIC) u32Can_TempMsgId = 0U;
    P2VAR(can_txmsg_struct, AUTOMATIC,CAN_APPL_DATA) pCan_TxMsg = NULL_PTR;
    VAR(uint32, AUTOMATIC) u32Can_word = 0U;
    VAR(uint32, AUTOMATIC) curr_payload_word = 0U;
    VAR(uint32, AUTOMATIC) payload_bytes_to_write = 0U;
    
    u32Can_TempMsgId = PduInfo->id;
    pCan_Config = (&g_pCan_CurConfig->controllerConfig[ControllerId]);/* polyspace RTE:IDP */
    pCan_TxMsg = (can_txmsg_struct*)pCan_Config->mcandmaconfig->txfifo_dma_config->SrcPtr;/* polyspace RTE:IDP,NIP */

    if ((TRUE == pCan_Config->timingconfig[g_u16Can_CurBaudRateId[ControllerId]].brs_ena) /* polyspace RTE:NIV,IDP,OBAI,NIP */
            && ((u32Can_TempMsgId & MCAN_FD_ID_DESCRIPTOR) == MCAN_FD_ID_DESCRIPTOR))
    {
        pCan_TxMsg[dmuIndex].TxWord1.B.BRS = 1U;/* polyspace RTE:IDP */
    }
    else
    {
        pCan_TxMsg[dmuIndex].TxWord1.B.BRS = 0U;/* polyspace RTE:IDP */
    }

    if ((TRUE == pCan_Config->timingconfig[g_u16Can_CurBaudRateId[ControllerId]].fd_ena) /* polyspace RTE:OBAI,IDP,NIV,NIP,OVFL */
            && ((u32Can_TempMsgId & MCAN_FD_ID_DESCRIPTOR) == MCAN_FD_ID_DESCRIPTOR))
    {
        pCan_TxMsg[dmuIndex].TxWord1.B.FDF = 1U;/* polyspace RTE:IDP */
    }
    else
    {
        pCan_TxMsg[dmuIndex].TxWord1.B.FDF = 0U;/* polyspace RTE:IDP */
    }
    if (MCAN_MSG_ID_EXT_MASK == (u32Can_TempMsgId & MCAN_MSG_ID_EXT_MASK))
    {
        pCan_TxMsg[dmuIndex].TxWord0.B.XTD = 1U;/* polyspace RTE:IDP */
        u32Can_TempMsgId &= MCAN_TX_BUFFER_EXT_ID_MASK;
        pCan_TxMsg[dmuIndex].TxWord0.B.ID = (u32Can_TempMsgId << MCAN_TX_BUFFER_EXT_ID_SHIFT);/* polyspace RTE:IDP */
    }
    else
    {
        pCan_TxMsg[dmuIndex].TxWord0.B.XTD = 0U;/* polyspace RTE:IDP */
        u32Can_TempMsgId = ((u32Can_TempMsgId << MCAN_TX_BUFFER_STD_ID_SHIFT) \
                            & MCAN_TX_BUFFER_STD_ID_MASK) >> MCAN_TX_BUFFER_STD_ID_SHIFT;
        pCan_TxMsg[dmuIndex].TxWord0.B.ID = (u32Can_TempMsgId << MCAN_TX_BUFFER_STD_ID_SHIFT);/* polyspace RTE:IDP */
    }
    pCan_TxMsg[dmuIndex].TxWord1.B.DLC = MCAN_Wrapper_ConvertDataLengthCode(PduInfo->length);
    pCan_TxMsg[dmuIndex].TxWord0.B.ESI = 0U;
    pCan_TxMsg[dmuIndex].TxWord1.B.EFC = 0U;

    payload_bytes_to_write = PduInfo->length;
    while(payload_bytes_to_write > 0U)
    {
        u32Can_word = (((uint32)PduInfo->sdu[(curr_payload_word<<2U)]) \
                    +((uint32)PduInfo->sdu[(curr_payload_word<<2U)+1U] <<  8U) \
                    +((uint32)PduInfo->sdu[(curr_payload_word<<2U)+2U] << 16U) \
                    +((uint32)PduInfo->sdu[(curr_payload_word<<2U)+3U] << 24U));
        SchM_Enter_Can_EXCLUSIVE_AREA_09();
        *(uint32 *)(((uint8 *)&pCan_TxMsg[dmuIndex].TxDataWord0.R) + (curr_payload_word *4U)) = u32Can_word;/* polyspace RTE:IDP */
        SchM_Exit_Can_EXCLUSIVE_AREA_09();
        curr_payload_word++;

        if (payload_bytes_to_write >= 4U)
        {
            payload_bytes_to_write = (payload_bytes_to_write - 4U);
        }
        else
        {
            payload_bytes_to_write = 0U;
        }
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"
#endif /* RESOURCE_SUPPORT_MCAN_DMU */

#ifdef __cplusplus
}
#endif

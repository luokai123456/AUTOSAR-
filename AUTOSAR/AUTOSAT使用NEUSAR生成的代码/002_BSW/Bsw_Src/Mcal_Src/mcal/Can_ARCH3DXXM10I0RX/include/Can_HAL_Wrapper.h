/**************************************************************************** 
* 
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
*   @file    Can_HAL_Wrapper.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Can MCAL driver.
*
*   @addtogroup Can
*   @{
*/

#ifndef CAN_HAL_WRAPPER_H
#define CAN_HAL_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"
#include "Can.h"

#define CAN_HAL_WRA_H_VENDOR_ID                     176
#define CAN_HAL_WRA_H_AR_REL_MAJOR_VER              4
#define CAN_HAL_WRA_H_AR_REL_MINOR_VER              4
#define CAN_HAL_WRA_H_AR_REL_REV_VER                0
#define CAN_HAL_WRA_H_SW_MAJOR_VER                  3
#define CAN_HAL_WRA_H_SW_MINOR_VER                  0
#define CAN_HAL_WRA_H_SW_PATCH_VER                  0

#if (CAN_CFG_H_VENDOR_ID != CAN_HAL_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_HAL_WRA_H_VENDOR_ID "
#endif
#if (CAN_CFG_H_AR_REL_MAJOR_VER != CAN_HAL_WRA_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_HAL_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (CAN_CFG_H_AR_REL_MINOR_VER != CAN_HAL_WRA_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_HAL_WRA_H_AR_REL_MINOR_VER "
#endif
#if (CAN_CFG_H_AR_REL_REV_VER != CAN_HAL_WRA_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_HAL_WRA_H_AR_REL_REV_VER "
#endif
#if (CAN_CFG_H_SW_MAJOR_VER != CAN_HAL_WRA_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_HAL_WRA_H_SW_MAJOR_VER "
#endif
#if (CAN_CFG_H_SW_MINOR_VER != CAN_HAL_WRA_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_HAL_WRA_H_SW_MINOR_VER "
#endif
#if (CAN_CFG_H_SW_PATCH_VER != CAN_HAL_WRA_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_HAL_WRA_H_SW_PATCH_VER "
#endif

typedef P2FUNC(void, CAN_CODE, rxCallBack_Type)(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
typedef P2FUNC(void, CAN_CODE, txCallBack_Type)(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
typedef P2FUNC(void, CAN_CODE, busoffCallBack_Type)(VAR(uint8, AUTOMATIC) u8Can_ControllerId);

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_Wrapper_InitController(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_Wrapper_DeInitController(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_Wrapper_EnterSleep(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_Wrapper_DisableInterrupts(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_Wrapper_IsBusOff(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_Wrapper_IsErrorActive(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_Wrapper_GetTxErrorCounter(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_Wrapper_GetRxErrorCounter(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
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
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_Wrapper_IsFDEnabled(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_Wrapper_TxOccurred \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint32, AUTOMATIC) u32Can_Tx_Buf_Index \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint32, CAN_CODE) Can_Wrapper_Get_TXBTO \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId
)
{
    P2CONST(CANConfig, CAN_VAR, CAN_APPL_DATA) pCan_Config = NULL_PTR;

    pCan_Config = (&g_pCan_CurConfig->controllerConfig[u8Can_ControllerId]); /* polyspace RTE:IDP */
    return Can_LLD_GetTXBTO(pCan_Config->controllerId); /* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint32, CAN_CODE) Can_Wrapper_RxRecFifoMsg \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint32, AUTOMATIC) u32Can_Rx_Fifo_Number \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_Wrapper_IsDataLost \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint32, AUTOMATIC) u32Can_Rx_Fifo_Number \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint32, CAN_CODE) Can_Wrapper_RxDedicatedBufferProcessNewMsg \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_Wrapper_isInitState(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_Wrapper_isSleep(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_Wrapper_exitSleep(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
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
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_Wrapper_EnableInterrupts(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_Wrapper_SetTimeOut(VAR(uint32, AUTOMATIC) u32Can_TimeOutDuration);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_Wrapper_RsetInit(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) MCAN_ProcessIrq0(VAR(MCANModId, AUTOMATIC) eCan_Instance);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) MCAN_ProcessIrq1(VAR(MCANModId, AUTOMATIC) eCan_Instance);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_Wrapper_isTxInterruptMb \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint32, AUTOMATIC) u32Can_Tx_Buf_Index \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#if defined(RESOURCE_SUPPORT_MCAN_DMU)
#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_Wrapper_Dmu_Write(VAR(uint8, AUTOMATIC) dmuIndex, VAR(uint8, AUTOMATIC) ControllerId, P2VAR(Can_PduType, AUTOMATIC, CAN_APPL_DATA) PduInfo);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"
#endif /* RESOURCE_SUPPORT_MCAN_DMU */

#ifdef __cplusplus
}
#endif

#endif

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
*   @file    Can_176_CanFD_HAL_Wrapper.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CanFd MCAL driver.
*
*   @addtogroup CanFd
*   @{
*/

#ifndef CAN_176_CANFD_HAL_WRAPPER_H
#define CAN_176_CANFD_HAL_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Can_176_CanFD.h"

#ifdef RESOURCE_SUPPORT_CANFD_IP

#define CAN_176_CANFD_HAL_WRA_H_VENDOR_ID                     176
#define CAN_176_CANFD_HAL_WRA_H_AR_REL_MAJOR_VER              4
#define CAN_176_CANFD_HAL_WRA_H_AR_REL_MINOR_VER              4
#define CAN_176_CANFD_HAL_WRA_H_AR_REL_REV_VER                0
#define CAN_176_CANFD_HAL_WRA_H_SW_MAJOR_VER                  3
#define CAN_176_CANFD_HAL_WRA_H_SW_MINOR_VER                  0
#define CAN_176_CANFD_HAL_WRA_H_SW_PATCH_VER                  0

#if (CAN_176_CANFD_CFG_H_VENDOR_ID != CAN_176_CANFD_HAL_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_176_CANFD_HAL_WRA_H_VENDOR_ID "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_MAJOR_VER != CAN_176_CANFD_HAL_WRA_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_HAL_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_MINOR_VER != CAN_176_CANFD_HAL_WRA_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_HAL_WRA_H_AR_REL_MINOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_REV_VER != CAN_176_CANFD_HAL_WRA_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_HAL_WRA_H_AR_REL_REV_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_MAJOR_VER != CAN_176_CANFD_HAL_WRA_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_HAL_WRA_H_SW_MAJOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_MINOR_VER != CAN_176_CANFD_HAL_WRA_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_HAL_WRA_H_SW_MINOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_PATCH_VER != CAN_176_CANFD_HAL_WRA_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_HAL_WRA_H_SW_PATCH_VER "
#endif

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_Wrapper_InitController \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint16, CAN_VAR) u8Can_BaudRateId \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_Wrapper_DeInitController \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_Wrapper_EnterSleep \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_Wrapper_DisableInterrupts \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(boolean, CAN_CODE) Can_176_CanFD_Wrapper_IsBusOff(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(boolean, CAN_CODE) Can_176_CanFD_Wrapper_IsErrorActive \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint8, CAN_CODE) Can_176_CanFD_Wrapper_GetTxErrorCounter \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint8, CAN_CODE) Can_176_CanFD_Wrapper_GetRxErrorCounter \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
);
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
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint8, CAN_CODE) Can_176_CanFD_Wrapper_IsDataLost \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(boolean, CAN_CODE) Can_176_CanFD_Wrapper_isInitState \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(boolean, CAN_CODE) Can_176_CanFD_Wrapper_isSleep(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_Wrapper_exitSleep(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_Wrapper_InitCallback \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    CANFDIntrCallback* callback \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_Wrapper_EnableInterrupts \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint32, CAN_CODE) Can_176_CanFD_Wrapper_IsTransmitBusy
(
    VAR(uint32,AUTOMATIC) u8Can_ControllerId,
    VAR(CANFDTransBufType,AUTOMATIC) type
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint32, CAN_CODE) Canfd_176_CanFd_Wrapper_Recv_Msg \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    P2VAR(CANFDRxMsg, AUTOMATIC, CAN_APPL_DATA) rx_msg \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#endif /* RESOURCE_SUPPORT_CANFD_IP */

#ifdef __cplusplus
}
#endif

#endif /* CAN_176_CANFD_HAL_WRAPPER_H */

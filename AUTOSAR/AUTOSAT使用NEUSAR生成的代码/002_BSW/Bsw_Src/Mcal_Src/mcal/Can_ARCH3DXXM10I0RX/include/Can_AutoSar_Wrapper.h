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
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    Can_AutoSar_Wrapper.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Can MCAL driver.
*
*   @addtogroup Can
*   @{
*/

#ifndef CAN_AUTOSAR_WRAPPER_H
#define CAN_AUTOSAR_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"
#include "Can_GeneralTypes.h"
#include "Can_Cfg.h"
#include "Can.h"

#define CAN_ATS_WRA_H_VENDOR_ID                     176
#define CAN_ATS_WRA_H_AR_REL_MAJOR_VER              4
#define CAN_ATS_WRA_H_AR_REL_MINOR_VER              4
#define CAN_ATS_WRA_H_AR_REL_REV_VER                0
#define CAN_ATS_WRA_H_SW_MAJOR_VER                  3
#define CAN_ATS_WRA_H_SW_MINOR_VER                  0
#define CAN_ATS_WRA_H_SW_PATCH_VER                  0

#if (CAN_CFG_H_VENDOR_ID != CAN_ATS_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_ATS_WRA_H_VENDOR_ID "
#endif
#if (CAN_CFG_H_AR_REL_MAJOR_VER != CAN_ATS_WRA_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_ATS_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (CAN_CFG_H_AR_REL_MINOR_VER != CAN_ATS_WRA_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_ATS_WRA_H_AR_REL_MINOR_VER "
#endif
#if (CAN_CFG_H_AR_REL_REV_VER != CAN_ATS_WRA_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_ATS_WRA_H_AR_REL_REV_VER "
#endif
#if (CAN_CFG_H_SW_MAJOR_VER != CAN_ATS_WRA_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_ATS_WRA_H_SW_MAJOR_VER "
#endif
#if (CAN_CFG_H_SW_MINOR_VER != CAN_ATS_WRA_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_ATS_WRA_H_SW_MINOR_VER "
#endif
#if (CAN_CFG_H_SW_PATCH_VER != CAN_ATS_WRA_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_ATS_WRA_H_SW_PATCH_VER "
#endif

#define MCAN_TX_BUFFER_MAX 32U

typedef enum {
    MB_IDLE = 0U,
    MB_BUSY = 1U
} Can_MBStateType;

typedef struct {
    PduIdType           canIfPduId;
} Can_MBInfoType;

typedef struct {
    Can_MBInfoType txMbInfo[MCAN_TX_BUFFER_MAX];
    uint32         txMbState;
} Can_ControllerInfo;

extern volatile VAR(Can_ControllerStateType, CAN_VAR) g_eCan_ControllerState[CAN_CONTROLLER_COUNT];

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) MCAN_RxNotifiy \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerIdx, \
    VAR(uint32, AUTOMATIC) u32Can_CanObjectId, \
    P2CONST(can_msg_struct, CAN_VAR, CAN_APPL_DATA) pCan_MsgInfo \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_InitStatus(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_InitController(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_DeInitController(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_AutoSar_Wrapper_SetControllerMode \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller, \
    VAR(Can_ControllerStateType, AUTOMATIC) eCan_Transition \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_DisableInterrupts(VAR(uint8, AUTOMATIC) u8Can_Controller);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_EnableInterrupts(VAR(uint8, AUTOMATIC) u8Can_Controller);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(Can_ErrorStateType, CAN_CODE) Can_AutoSar_Wrapper_GetErrorState \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(Can_ControllerStateType, CAN_CODE) Can_AutoSar_Wrapper_GetMode \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_AutoSar_Wrapper_GetRxErrorCounter(VAR(uint8, AUTOMATIC) u8Can_Controller);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_AutoSar_Wrapper_GetTxErrorCounter(VAR(uint8, AUTOMATIC) u8Can_Controller);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_AutoSar_Wrapper_Write \
( \
    VAR(Can_HwHandleType, AUTOMATIC) u16Can_Hth, \
    P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) pCan_PduInfo \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_TxPolling(VAR(uint8, AUTOMATIC) u8Can_Controller, VAR(uint32, AUTOMATIC) u32Can_HwObjectIdex);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_RxPolling(VAR(uint8, AUTOMATIC) u8Can_ControllerIdx);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_BusOffPolling(VAR(uint8, AUTOMATIC) u8Can_Controller);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_WakeUpPolling(VAR(uint8, AUTOMATIC) u8Can_Controller);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_ControllerModePolling \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_RxPollingMul \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerIdx, \
    VAR(uint8, AUTOMATIC) u8Can_PeriodIdx \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_AutoSar_Wrapper_TxPollingMul \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller, \
    VAR(uint32, AUTOMATIC) u32Can_HwObjectIdex, \
    VAR(uint8, AUTOMATIC) u8Can_PeriodIdx \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif

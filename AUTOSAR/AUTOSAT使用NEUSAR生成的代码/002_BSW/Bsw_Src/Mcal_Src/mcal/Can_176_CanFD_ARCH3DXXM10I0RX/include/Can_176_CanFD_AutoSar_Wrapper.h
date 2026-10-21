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
*   @file    Can_176_CanFD_AutoSar_Wrapper.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CanFd MCAL driver.
*
*   @addtogroup CanFd
*   @{
*/
/* PRQA S 0779 EOF */
#ifndef CAN_176_CANFD_AUTOSAR_WRAPPER_H
#define CAN_176_CANFD_AUTOSAR_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Can_176_CanFD.h"

#ifdef RESOURCE_SUPPORT_CANFD_IP

#define CAN_176_CANFD_ATS_WRA_H_VENDOR_ID                     176
#define CAN_176_CANFD_ATS_WRA_H_AR_REL_MAJOR_VER              4
#define CAN_176_CANFD_ATS_WRA_H_AR_REL_MINOR_VER              4
#define CAN_176_CANFD_ATS_WRA_H_AR_REL_REV_VER                0
#define CAN_176_CANFD_ATS_WRA_H_SW_MAJOR_VER                  3
#define CAN_176_CANFD_ATS_WRA_H_SW_MINOR_VER                  0
#define CAN_176_CANFD_ATS_WRA_H_SW_PATCH_VER                  0

#if (CAN_176_CANFD_CFG_H_VENDOR_ID != CAN_176_CANFD_ATS_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_176_CANFD_ATS_WRA_H_VENDOR_ID "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_MAJOR_VER != CAN_176_CANFD_ATS_WRA_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_ATS_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_MINOR_VER != CAN_176_CANFD_ATS_WRA_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_ATS_WRA_H_AR_REL_MINOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_REV_VER != CAN_176_CANFD_ATS_WRA_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_ATS_WRA_H_AR_REL_REV_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_MAJOR_VER != CAN_176_CANFD_ATS_WRA_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_ATS_WRA_H_SW_MAJOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_MINOR_VER != CAN_176_CANFD_ATS_WRA_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_ATS_WRA_H_SW_MINOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_PATCH_VER != CAN_176_CANFD_ATS_WRA_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_ATS_WRA_H_SW_PATCH_VER "
#endif

typedef enum {
    MB_176_CANFD_IDLE = 0U,
    MB_176_CANFD_BUSY = 1U
} CanFd_MBStateType;

typedef struct {
    VAR(PduIdType, AUTOMATIC)         canIfPduId;
    VAR(CanFd_MBStateType, AUTOMATIC) txMbState;
} CanFd_MBInfoType;

typedef struct {
    VAR(CanFd_MBInfoType, AUTOMATIC) txMbInfo_Primary;
    VAR(CanFd_MBInfoType, AUTOMATIC) txMbInfo_Secondary;
} CanFd_ControllerInfo;

extern volatile VAR(Can_ControllerStateType, CAN_VAR) g_eCanFd_ControllerState[CAN_176_CANFD_CONTROLLER_COUNT];

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_InitController \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(uint16, CAN_VAR) u8Can_BaudRateId \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"


#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_DeInitController \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"


#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_SetControllerMode \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller, \
    VAR(Can_ControllerStateType, AUTOMATIC) eCan_Transition \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_DisableInterrupts \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_EnableInterrupts \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Can_ErrorStateType, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_GetErrorState \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Can_ControllerStateType, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_GetMode \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint8, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_GetRxErrorCounter \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint8, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_GetTxErrorCounter \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_Write \
( \
    VAR(Can_HwHandleType, AUTOMATIC) u16Can_Hth, \
    P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) pCan_PduInfo \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_TxPolling \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerIdx \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_RxPolling \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerIdx \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_BusOffPolling \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_WakeUpPolling \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_ControllerModePolling \
( \
    VAR(uint8, AUTOMATIC) u8Can_Controller \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_RxPollingMul \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerIdx, \
    VAR(uint8, AUTOMATIC) u8Can_PeriodIdx \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_AutoSar_Wrapper_TxPollingMul \
( \
    VAR(uint8, AUTOMATIC) u8Can_HwObjectIdex, \
    VAR(uint8, AUTOMATIC) u8Can_PeriodIdx \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#endif /* RESOURCE_SUPPORT_CANFD_IP */

#ifdef __cplusplus
}
#endif

#endif /* CAN_176_CANFD_AUTOSAR_WRAPPER_H */

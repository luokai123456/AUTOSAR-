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
*   @file    Can_176_CanFD_LLDriver.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CanFd MCAL driver.
*
*   @addtogroup CanFd
*   @{
*/
#ifndef CAN_176_CANFD_LLDRIVER_H
#define CAN_176_CANFD_LLDRIVER_H
/*PRQA S 0635,1534,3630 EOF*/
#include "compiler_api.h"
#include "derivative.h"
#include "status.h"
#include "Can_GeneralTypes.h"
#include "ComStack_Types.h"
#include "Mcal.h"
#include "Can_176_CanFD.h"

#ifdef RESOURCE_SUPPORT_CANFD_IP

#define CAN_176_CANFD_LLD_H_VENDOR_ID                     176
#define CAN_176_CANFD_LLD_H_AR_REL_MAJOR_VER              4
#define CAN_176_CANFD_LLD_H_AR_REL_MINOR_VER              4
#define CAN_176_CANFD_LLD_H_AR_REL_REV_VER                0
#define CAN_176_CANFD_LLD_H_SW_MAJOR_VER                  3
#define CAN_176_CANFD_LLD_H_SW_MINOR_VER                  0
#define CAN_176_CANFD_LLD_H_SW_PATCH_VER                  0

#if (CAN_176_CANFD_CFG_H_VENDOR_ID != CAN_176_CANFD_LLD_H_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_176_CANFD_LLD_H_VENDOR_ID "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_MAJOR_VER != CAN_176_CANFD_LLD_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_LLD_H_AR_REL_MAJOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_MINOR_VER != CAN_176_CANFD_LLD_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_LLD_H_AR_REL_MINOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_REV_VER != CAN_176_CANFD_LLD_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_LLD_H_AR_REL_REV_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_MAJOR_VER != CAN_176_CANFD_LLD_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_LLD_H_SW_MAJOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_MINOR_VER != CAN_176_CANFD_LLD_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_LLD_H_SW_MINOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_PATCH_VER != CAN_176_CANFD_LLD_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_LLD_H_SW_PATCH_VER "
#endif

#ifndef ENABLE
#define ENABLE 1
#endif
#ifndef DISABLE
#define DISABLE 0
#endif

#define CANFD_MOD_ID_1_INT_NUM      431U
#define CANFD_MOD_ID_1_INT_PRI      4U
#define CANFD_MOD_ID_9_INT_NUM      224U
#define CANFD_MOD_ID_9_INT_PRI      4U

/* CANFD interface error code */
#define CANFD_OK                    0U
#define CANFD_ERROR_INVALID_PARA    1U
#define CANFD_ERROR_INVALID_STATE   2U/*PRQA S 1534*/
#define CANFD_ERROR_TRANS_BUF_BUSY  3U
#define CANFD_ERROR_NO_MSG_RECEIVED 4U
#define CANFD_ERROR_ABORT_MSG_TRANS 5U

typedef volatile CAN_FD_TypeDef CANFDReg;

/* CANFD LLC frame flag */
typedef union {
    struct {
        VAR(uint8, AUTOMATIC) resv2:2;
        VAR(uint8, AUTOMATIC) sec:1;
        VAR(uint8, AUTOMATIC) rmf:1;
        VAR(uint8, AUTOMATIC) resv1:1;
        VAR(uint8, AUTOMATIC) brs:1;
        VAR(uint8, AUTOMATIC) fdf:1;
        VAR(uint8, AUTOMATIC) ide:1;
    } B;
    VAR(uint8, AUTOMATIC) R;
} FrameFlagl;


typedef struct {
    struct {
        VAR(uint8, AUTOMATIC) resv3:3;
        VAR(uint8, AUTOMATIC) lbf:1;
        VAR(uint8, AUTOMATIC) esi:1;
        VAR(uint8, AUTOMATIC) koer:3;
    } B;
    VAR(uint8, AUTOMATIC) R;
} FrameFlagh;

/* CANFD TX message */
typedef struct {
    VAR(uint32, AUTOMATIC) id;
    union {
        VAR(uint8, AUTOMATIC)  byte[64];
        VAR(uint32, AUTOMATIC) word[16];
    } data;
    VAR(uint8, AUTOMATIC) data_len;
    VAR(uint8, AUTOMATIC) is_extern;
    VAR(uint8, AUTOMATIC) is_remote;
    VAR(uint8, AUTOMATIC) is_fd_format_flag;
    VAR(uint8, AUTOMATIC) is_bit_rate_switch;
    VAR(uint8, AUTOMATIC) is_error_happened;
    VAR(CANFDTransBufType, AUTOMATIC) trans_buf;
} CANFDTxMsg;

/* CANFD error statistics */
typedef struct {
    VAR(uint8, AUTOMATIC) rx_cnt;
    VAR(uint8, AUTOMATIC) tx_cnt;
} CANFDErrorCnt;

typedef union {
    VAR(uint32, AUTOMATIC) id;
    struct {
        VAR(uint32, AUTOMATIC) is_valid : 1; /* PRQA S 0632 # useful */
        VAR(uint32, AUTOMATIC) msg_cnt : 31; /* PRQA S 0632 # useful */
    } attr;
} CanfdTransBufMsgId;

typedef struct {
    VAR(uint32, AUTOMATIC) cur_msg;
} CanfdTransBufState;

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Canfd_LLD_Intr_Callback(VAR(CANFDModId, AUTOMATIC) canfd_id); /* PRQA S 0554, declaration */
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(status_t, CAN_CODE) Canfd_LLD_Init \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    P2CONST(CANFDConfig, AUTOMATIC, CAN_APPL_CONST) config, \
    VAR(uint16, CAN_VAR) u8Can_BaudRateId \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint32, CAN_CODE) Canfd_LLD_DeInit(VAR(CANFDModId, AUTOMATIC) canfd_id);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint32, CAN_CODE) Canfd_LLD_Send_Msg \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    P2CONST(CANFDTxMsg, AUTOMATIC, CAN_APPL_CONST) tx_msg, \
    P2VAR(uint32, AUTOMATIC, CAN_APPL_DATA) msg_idx \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint8, CAN_CODE) Canfd_LLD_Is_Msg_Transferred \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    VAR(uint32, AUTOMATIC) msg_idx \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint8, CAN_CODE) Canfd_LLD_Abort_Msg_Transfer \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    VAR(uint32, AUTOMATIC) msg_idx \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint32, CAN_CODE) Canfd_LLD_Recv_Msg \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    P2VAR(CANFDRxMsg, AUTOMATIC, CAN_APPL_DATA) rx_msg \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Canfd_LLD_Sleep(VAR(CANFDModId, AUTOMATIC) canfd_id);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Canfd_LLD_Wakeup(VAR(CANFDModId, AUTOMATIC) canfd_id);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(const CANFDErrorCnt *, CAN_CODE) Canfd_LLD_Get_Error_Counter(VAR(CANFDModId, AUTOMATIC) canfd_id);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Canfd_LLD_InterDisableAllSignals(VAR(CANFDModId, AUTOMATIC) canfd_id);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Canfd_LLD_InterruptInit \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    CONST(uint32, CAN_CONST) interconfig \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(boolean, CAN_CODE) Canfd_LLD_IsBusOff(VAR(CANFDModId, AUTOMATIC) canfd_id);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(boolean, CAN_CODE) Canfd_LLD_IsErrorActive(VAR(CANFDModId, AUTOMATIC) canfd_id);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(boolean, CAN_CODE) Canfd_LLD_IsDataLost(VAR(CANFDModId, AUTOMATIC) canfd_id);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(boolean, CAN_CODE) Canfd_LLD_isInitState(VAR(CANFDModId, AUTOMATIC) canfd_id);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(boolean, CAN_CODE) Canfd_LLD_isSleep(VAR(CANFDModId, AUTOMATIC) canfd_id);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Canfd_LLD_Init_Intr \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    P2CONST(CANFDIntrCallback, AUTOMATIC, CAN_APPL_CONST) callback \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint32, CAN_CODE) Can_LLD_Can_IsTransmitBusy
(
    VAR(uint32,AUTOMATIC)eCanfd_176CANx,
    VAR(CANFDTransBufType,AUTOMATIC) type
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#endif /* RESOURCE_SUPPORT_CANFD_IP */

#endif /* CAN_176_CANFD_LLDRIVER_H */

/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : eDma
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
*   @file    eDma.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eDma MCAL driver.
*
*   @addtogroup eDma
*   @{
*/

#ifndef EDMA_H
#define EDMA_H

#ifdef __cplusplus
extern "C"{
#endif

#include "ComStack_Types.h"
#include "eDma_Cfg.h"
#include "Mcal.h"
#include "eDma_LLDriver.h"

#define EDMA_H_VENDOR_ID                     176
#define EDMA_H_AR_REL_MAJOR_VER              4
#define EDMA_H_AR_REL_MINOR_VER              4
#define EDMA_H_AR_REL_REV_VER                0
#define EDMA_H_SW_MAJOR_VER                  3
#define EDMA_H_SW_MINOR_VER                  0
#define EDMA_H_SW_PATCH_VER                  0
#define EDMA_MODULE_ID                       255

#if (EDMA_CFG_H_VENDOR_ID != EDMA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : EDMA_H_VENDOR_ID "
#endif
#if (EDMA_CFG_H_AR_REL_MAJOR_VER != EDMA_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_H_AR_REL_MAJOR_VER "
#endif
#if (EDMA_CFG_H_AR_REL_MINOR_VER != EDMA_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_H_AR_REL_MINOR_VER "
#endif
#if (EDMA_CFG_H_AR_REL_REV_VER != EDMA_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : EDMA_H_AR_REL_REV_VER "
#endif
#if (EDMA_CFG_H_SW_MAJOR_VER != EDMA_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_H_SW_MAJOR_VER "
#endif
#if (EDMA_CFG_H_SW_MINOR_VER != EDMA_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_H_SW_MINOR_VER "
#endif
#if (EDMA_CFG_H_SW_PATCH_VER != EDMA_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : EDMA_H_SW_PATCH_VER "
#endif

#define EDMA_CORE_NUM                      MCAL_CORE_NUM

#define EDMA_E_PARAM_POINTER               ((uint8)0x01U)
#define EDMA_E_PARAM_HANDLE                ((uint8)0x02U)
#define EDMA_E_PARAM_DATA_LENGTH           ((uint8)0x03U)
#define EDMA_E_PARAM_CONTROLLER            ((uint8)0x04U)
#define EDMA_E_UNINIT                      ((uint8)0x05U)
#define EDMA_E_TRANSITION                  ((uint8)0x06U)
#define EDMA_E_INIT_FAILED                 ((uint8)0x09U)
#define EDMA_E_INVALID_CONTROLLER          ((uint8)0x0AU)

#define EDMA_SID_INIT                      ((uint8)0x00U)
#define EDMA_SID_GET_VERSION_INFO          ((uint8)0x01U)
#define EDMA_SID_SETUP_CALLBACK            ((uint8)0x02U)
#define EDMA_SID_CLEAR_INT_STATUS          ((uint8)0x03U)
#define EDMA_SID_SW_REQUEST_TRIGGEREN      ((uint8)0x04U)
#define EDMA_SID_SET_CHN_SOURCE_CONFIG     ((uint8)0x05U)
#define EDMA_SID_CHANNEL_INIT              ((uint8)0x06U)
#define EDMA_SID_CLEAR_SWTCD_STRUCT        ((uint8)0x07U)
#define EDMA_SID_SET_SINGLE_TRF_CONFIG     ((uint8)0x08U)
#define EDMA_SID_SET_MULTI_TRF_CONFIG      ((uint8)0x09U)
#define EDMA_SID_SET_LOOP_TRF_CONFIG       ((uint8)0x0AU)
#define EDMA_SID_COPY_CONFIG_TO_SWTCD      ((uint8)0x0BU)
#define EDMA_SID_SET_SCT_GTH_TRF_CONFIG    ((uint8)0x0CU)
#define EDMA_SID_SET_CHANNEL_REQUEST       ((uint8)0x0DU)
#define EDMA_SID_CLEAR_CHANNEL_REQUEST     ((uint8)0x0EU)
#define EDMA_SID_CLEAR_HW_TCD              ((uint8)0x0FU)
#define EDMA_SID_SET_CHN_SRC_ADDR          ((uint8)0x10U)
#define EDMA_SID_SET_CHN_SRC_ADDR_OFF      ((uint8)0x11U)
#define EDMA_SID_SET_CHN_SRC_ADD_RD_TRF    ((uint8)0x12U)
#define EDMA_SID_SET_CHN_SRC_AD_LST_ADJ    ((uint8)0x13U)
#define EDMA_SID_SET_CHN_DST_AD_LST_ADJ    ((uint8)0x14U)
#define EDMA_SID_SET_CHN_DEST_ADDR         ((uint8)0x15U)
#define EDMA_SID_SET_CHN_DEST_ADDR_OFF     ((uint8)0x16U)
#define EDMA_SID_SET_CHN_DST_ADD_WR_TRF    ((uint8)0x17U)
#define EDMA_SID_SET_CHN_MINOR_LP_TRFBT    ((uint8)0x18U)
#define EDMA_SID_SET_CHN_MAJOR_LP_ITER     ((uint8)0x19U)
#define EDMA_SID_GET_CHN_REMAINING_ITER    ((uint8)0x1AU)
#define EDMA_SID_SET_CHN_SCT_GTH_LK_MOD    ((uint8)0x1BU)
#define EDMA_SID_SET_CHN_DIS_REQ_ON_TRF    ((uint8)0x1CU)
#define EDMA_SID_SET_INTERRUPT_CONFIG      ((uint8)0x1DU)
#define EDMA_SID_CNCEL_EXCUTING_CHN_TRF    ((uint8)0x1EU)
#define EDMA_SID_WAIT_CHN_TRANSFER_DONE    ((uint8)0x1FU)
#define EDMA_SID_GET_CHN_CONFIG_STATUS     ((uint8)0x20U)
#define EDMA_SID_ERROR_IRQ_HANDLER         ((uint8)0x21U)
#define EDMA_SID_SET_ERR_CALLBACK          ((uint8)0x22U)
#define EDMA_SID_GET_ERR_STATUS            ((uint8)0x23U)
#define EDMA_SID_CLEAR_ERR_STATUS          ((uint8)0x24U)

typedef struct
{
    P2CONST(eDMAModuleConfigType, EDMA_CONST, EDMA_APPL_CONST)  pEdma_DeviceConfig;
    CONSTP2VAR(eDMAChnStateType, EDMA_CONST, EDMA_APPL_CONST) pEdma_ChStateArray[EDMA_CONFIG_CHANNELS_COUNT];
    CONSTP2CONST(eDMAChanConfigType, EDMA_CONST, EDMA_APPL_CONST) pEdma_ChanelConfig[EDMA_CONFIG_CHANNELS_COUNT];
    CONST(uint32, EDMA_CONST) u32Edma_ChanelCnt;
    CONSTP2CONST(eDMAChPriorityCfg, EDMA_CONST, EDMA_APPL_CONST) pEdma_ChPriorityCfgs;
} EDma_ConfigType;

#if (EDMA_PRECOMPILE_SUPPORT == STD_OFF)
EDMA_PB_CONFIG_DECLARATION
#else
extern CONST(EDma_ConfigType, EDMA_CONST) EDma_Config;
#endif

#if (EDMA_VERSION_INFO_API == STD_ON)
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, EDMA_APPL_DATA) versioninfo);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#endif
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(Std_ReturnType, EDMA_CODE) EDMA_SetUpCallback \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMACallbackType, AUTOMATIC) callback, \
    P2VAR(void, AUTOMATIC, EDMA_APPL_DATA) parameter \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(Std_ReturnType, EDMA_CODE) EDMA_SetErrCallback \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMACallbackType, AUTOMATIC) callback, \
    P2VAR(void, AUTOMATIC, EDMA_APPL_DATA) parameter \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_ClearIntStatus(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_SwRequestTriggerEn(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(Std_ReturnType, EDMA_CODE) EDMA_SetChannelSourceConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) request, \
    VAR(boolean, AUTOMATIC) triggerEn \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(Std_ReturnType, EDMA_CODE) EDMA_ChannelInit \
( \
    P2VAR(eDMAChnStateType, AUTOMATIC, EDMA_APPL_DATA) eedma_channelState, \
    P2CONST(eDMAChanConfigType, EDMA_CONST,EDMA_APPL_DATA) eedma_channelConfig \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Init(P2CONST(EDma_ConfigType, EDMA_CONST, EDMA_APPL_CONST) peDmaConfig);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_ClearSwTCDStruct(P2VAR(eDMASwTcdType, AUTOMATIC,EDMA_APPL_DATA) swtcd);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(Std_ReturnType, EDMA_CODE) EDMA_SetSingleTransferConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMATransferType, AUTOMATIC) type, \
    VAR(uint32, AUTOMATIC) srcAddr, \
    VAR(uint32, AUTOMATIC) destAddr, \
    VAR(eDMATransferSizeType, AUTOMATIC) transferSize, \
    VAR(uint32, AUTOMATIC) dataBufferSize \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(Std_ReturnType, EDMA_CODE) EDMA_SetMultiTransferConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMATransferType, AUTOMATIC) type, \
    VAR(uint32, AUTOMATIC) srcAddr, \
    VAR(uint32, AUTOMATIC) destAddr, \
    VAR(eDMATransferSizeType, AUTOMATIC) transferSize, \
    VAR(uint32, AUTOMATIC) blockSize, \
    VAR(uint32, AUTOMATIC) blockCount, \
    VAR(boolean, AUTOMATIC) disableReqOnCompletion \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(Std_ReturnType, EDMA_CODE) EDMA_SetLoopTransferConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    P2CONST(eDMATransferConfigType, EDMA_CONST,EDMA_APPL_DATA)transferConfig \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_CopyConfigToSwTCD \
( \
    P2CONST(eDMATransferConfigType, EDMA_CONST,EDMA_APPL_DATA)config, \
    P2VAR(eDMASwTcdType, AUTOMATIC, EDMA_APPL_DATA) stcd \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(Std_ReturnType, EDMA_CODE) EDMA_SetScatterGatherTransferConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    P2CONST(eDMASwTcdType, EDMA_CONST,EDMA_APPL_DATA)stcd, \
    VAR(eDMATransferSizeType, AUTOMATIC) transferSize, \
    VAR(uint32, AUTOMATIC) bytesOnEachRequest, \
    P2CONST(eDMAScatterGatherListType, EDMA_CONST,EDMA_APPL_DATA) srcList, \
    P2CONST(eDMAScatterGatherListType, EDMA_CONST,EDMA_APPL_DATA) destList, \
    VAR(uint8, AUTOMATIC) tcdCount \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(Std_ReturnType, EDMA_CODE) EDMA_SetChannelRequest(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(Std_ReturnType, EDMA_CODE) EDMA_ClearChannelRequest(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_ClearHwTCD(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_SetChnSrcAddr \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) address \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_SetChnSrcAddrOffset \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(sint16, AUTOMATIC) offset \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_SetChnSrcAddrReadTransferSize \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMATransferSizeType, AUTOMATIC) size \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_SetChnSrcAddrLastAdjustment \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(sint32, AUTOMATIC) adjust \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_SetChnDestAddrLastAdjustment \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(sint32, AUTOMATIC) adjust \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_SetChnDestAddr \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) address \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_SetChnDestAddrOffset \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(sint16, AUTOMATIC) offset \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_SetChnDestdrWriteTransferSize \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMATransferSizeType, AUTOMATIC) size \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_SetChnMinorLpTransferByte \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) nbytes \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_SetChnMajorLpIterationCount \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) majorLoopCount \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(uint32, EDMA_CODE) EDMA_GetChnRemainingIterationsCount \
( \
    VAR(uint8, AUTOMATIC) mappedChannel \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_SetChnScatterGatherLinkMode \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) nextTCDAddr \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_SetChnDisRequestsOnTransferComplete \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(boolean, AUTOMATIC) disable \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_SetInterruptConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMAChannelInterruptType, AUTOMATIC) intSrc, \
    VAR(boolean, AUTOMATIC) enable \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_CancelExcutingChnTransfer(VAR(boolean, AUTOMATIC) error);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_WaitChnTransferDone(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(Std_ReturnType, EDMA_CODE) EDMA_GetChnConfigStatus(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_ErrorIRQHandler(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(eDMAChnStatusType, EDMA_CODE) EDMA_GetErrStatus(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_ClearErrStatus(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#ifdef __cplusplus
}
#endif
#endif

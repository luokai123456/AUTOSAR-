/**************************************************************************** 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : MCL
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
*   @file    eDma_LLDriver.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eDma MCAL driver.
*
*   @addtogroup eDma
*   @{
*/
/* PRQA S 3432,2844,2985,4342,0498,0751,0492,0491,2755 EOF */

#ifdef __cplusplus
extern "C"{
#endif

#include "eDma_LLDriver.h"/* PRQA S 0380 */

#define EDMA_LLD_C_VENDOR_ID                     176
#define EDMA_LLD_C_AR_REL_MAJOR_VER              4
#define EDMA_LLD_C_AR_REL_MINOR_VER              4
#define EDMA_LLD_C_AR_REL_REV_VER                0
#define EDMA_LLD_C_SW_MAJOR_VER                  3
#define EDMA_LLD_C_SW_MINOR_VER                  0
#define EDMA_LLD_C_SW_PATCH_VER                  0

#if (EDMA_CFG_H_VENDOR_ID != EDMA_LLD_C_VENDOR_ID)
    #error " NON-MATCHED DATA : EDMA_LLD_C_VENDOR_ID "
#endif
#if (EDMA_CFG_H_AR_REL_MAJOR_VER != EDMA_LLD_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_LLD_C_AR_REL_MAJOR_VER "
#endif
#if (EDMA_CFG_H_AR_REL_MINOR_VER != EDMA_LLD_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_LLD_C_AR_REL_MINOR_VER "
#endif
#if (EDMA_CFG_H_AR_REL_REV_VER != EDMA_LLD_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : EDMA_LLD_C_AR_REL_REV_VER "
#endif
#if (EDMA_CFG_H_SW_MAJOR_VER != EDMA_LLD_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_LLD_C_SW_MAJOR_VER "
#endif
#if (EDMA_CFG_H_SW_MINOR_VER != EDMA_LLD_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_LLD_C_SW_MINOR_VER "
#endif
#if (EDMA_CFG_H_SW_PATCH_VER != EDMA_LLD_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : EDMA_LLD_C_SW_PATCH_VER "
#endif

#define EDMA_START_SEC_CONFIG_DATA
#include "eDma_MemMap.h"
static CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) s_edmabaseAddr[EDMA_INSTANCE_COUNT] \
        = DMA_BASE_PTRS;
#define EDMA_STOP_SEC_CONFIG_DATA
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CONFIG_DATA
#include "eDma_MemMap.h"
static CONSTP2VAR(DMAMUX_Type, EDMA_CONST, EDMA_APPL_CONST) s_dmaMuxbaseAddr[DMAMUX_INSTANCE_COUNT] \
        = DMAMUX_BASE_PTRS;
#define EDMA_STOP_SEC_CONFIG_DATA
#include "eDma_MemMap.h"

#define EDMA_START_SEC_VAR_SHARED_INIT
#include "eDma_MemMap.h"
P2VAR(edma_state_t, AUTOMATIC, EDMA_APPL_DATA) s_mapEdmaState = NULL_PTR;
#define EDMA_STOP_SEC_VAR_SHARED_INIT
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_ClearStructPtr \
( \
    P2VAR(uint8, AUTOMATIC, EDMA_APPL_DATA) sructPtr, \
    volatile VAR(uint32, AUTOMATIC) size \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDDeInit \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_Init \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_CancelExecChnTransfer \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_CnlExecChnTrfWithError \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_EnDisHaltOnError \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(boolean, AUTOMATIC) haltOnError \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_SetChnPri \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(eDMAChannelPriorityType, AUTOMATIC) priority, \
    VAR(boolean, AUTOMATIC) ecp, \
    VAR(boolean, AUTOMATIC) dpa \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_MasterIdReplication \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) emi \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_SetChnArbitrationMode \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(eDMASelArbitrationModeType, AUTOMATIC) channelArbitration \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(eDMASelArbitrationModeType, EDMA_CODE) EDMA_HW_GetChnArbitrationMode \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_EnDisChnErrorInt \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) enable \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_GetChnErrorIntFlag \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    P2VAR(eDMAErrorRegisterType, AUTOMATIC, EDMA_APPL_DATA) errReg \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_ClearChnErrorIntFlag \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_EnDisChnDmaReq \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) enable \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_WaitChnTransferDoneFlag \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_ClearChnTransferDoneFlg \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_SetChnTrigStart \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_ClearChnIntFlag \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_HW_ConfGrpPri \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    P2CONST(eDMAModuleConfigType, EDMA_CONST, EDMA_APPL_CONST) userConfig \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_HW_SetGrpArbitrationMode \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(eDMASelArbitrationModeType, AUTOMATIC) groupArbitration \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(eDMASelArbitrationModeType, EDMA_CODE) EDMA_HW_GetGrpArbitrationMode \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_EnDisMinorLoopMapping \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(boolean, AUTOMATIC) enable \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDDeInit \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_HW_TCDSetBusBindwidth \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint8, AUTOMATIC) cycles \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_TCDSetSrcAddr \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) address \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_TCDSetSrcAddrOffset \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(sint16, AUTOMATIC) offset \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetTransferAttribute \
(
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(eDMAModuloType, AUTOMATIC) srcModulo, \
    VAR(eDMAModuloType, AUTOMATIC) destModulo, \
    VAR(eDMATransferSizeType, AUTOMATIC) srcTransferSize, \
    VAR(eDMATransferSizeType, AUTOMATIC) destTransferSize \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetSrcDataTrfSize \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(eDMATransferSizeType, AUTOMATIC) size \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetDestDataTrfSize \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(eDMATransferSizeType, AUTOMATIC) size \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetMinorByteCount \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) nbytes \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDEnDisSrcMinorLoopOff \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) enable \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDEnDisDstMinorLoopOff \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) enable \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetMinorLoopOffset \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(sint32, AUTOMATIC) offset \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_TCDSetSrcLastAdjust \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(sint32, AUTOMATIC) size \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_TCDSetDestAddr \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) address \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_TCDSetDestAddrOffset \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(sint16, AUTOMATIC) offset \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_TCDSetDestLastAdjust \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(sint32, AUTOMATIC) adjust \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_TCDSetScatterGatherLink \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) nextTCDAddr \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetScatterGatherCmd \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) enable \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetChannelMajorLink \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) majorLinkChannel, \
    VAR(boolean, AUTOMATIC) enable \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetDisDmaReqAftTCD \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) disable \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetMajorHalfCompInt \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) enable \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetMajorCompIntCmd \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) enable \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetChannelMinorLink \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) linkChannel, \
    VAR(boolean, AUTOMATIC) enable \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetMajorCount \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) count \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(uint32, EDMA_CODE) EDMA_HW_TCDGetCurrentMajorCount \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_PushConfigToReg \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    P2CONST(eDMATransferConfigType, EDMA_CONST, EDMA_APPL_CONST) tcd \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) DMAMUX_HW_Init \
( \
    VAR(DMAMUXInstanceNumType, AUTOMATIC) instance \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) DMAMUX_HW_SetChannelCmd \
( \
    VAR(DMAMUXInstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) enable \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) DMAMUX_HW_SetChannelTrigger \
( \
    VAR(DMAMUXInstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) enable \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) DMAMUX_HW_SetChannelSource \
( \
    VAR(DMAMUXInstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint8, AUTOMATIC) source \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_HW_ReleaseChannel(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_Init(VAR(eDMAIstanceNumType, AUTOMATIC) instance)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint8, AUTOMATIC) idx;
    VAR(uint32, AUTOMATIC) tempValue;

    tempValue = baseAddr->CR.R;     /* polyspace RTE:NIV */ 
    tempValue &= ~(DMA_CR_CLM_MASK);
    tempValue &= ~(DMA_CR_CX_MASK);
    tempValue &= ~(DMA_CR_ECX_MASK);
    tempValue &= ~(DMA_CR_EDBG_MASK);
    tempValue &= ~(DMA_CR_EMLM_MASK);
    tempValue &= ~(DMA_CR_ERCA_MASK);
    baseAddr->CR.R = tempValue;

    baseAddr->ERQH.R = 0U;
    baseAddr->ERQL.R = 0U;
    baseAddr->EEIH.R = 0U;
    baseAddr->EEIL.R = 0U;

    baseAddr->INTH.R = 0U;
    baseAddr->INTL.R = 0U;

    baseAddr->ERRH.R = 0xFFFFFFFFU;
    baseAddr->ERRL.R = 0xFFFFFFFFU;

    for (idx = 0U; idx < MODULES_EDMA_CHANNELS; idx++)
    {
        EDMA_HW_TCDDeInit(instance, idx);
    }
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_CancelExecChnTransfer \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint32, AUTOMATIC) tempValue;
    VAR(uint32, AUTOMATIC) eDma_Timeout = 0U;

    tempValue = baseAddr->CR.R;     /* polyspace RTE:NIV */
    tempValue &= ~(DMA_CR_CX_MASK);
    tempValue |= DMA_CR_CX(1UL);
    baseAddr->CR.R = tempValue;
    while (((baseAddr->CR.R & DMA_CR_CX_MASK) != 0UL) && (eDma_Timeout < DEFAULT_TIMEOUT))
    {
        eDma_Timeout++;
    }
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_CnlExecChnTrfWithError \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint32, AUTOMATIC) tempValue;
    VAR(uint32, AUTOMATIC) eDma_Timeout = 0U;
    tempValue = baseAddr->CR.R;     /* polyspace RTE:NIV */
    tempValue &= ~(DMA_CR_ECX_MASK);
    tempValue |= DMA_CR_ECX(1UL);
    baseAddr->CR.R = tempValue;
    while (((baseAddr->CR.R & DMA_CR_ECX_MASK) != 0UL) && (eDma_Timeout < DEFAULT_TIMEOUT))
    {
        eDma_Timeout++;
    }
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_EnDisHaltOnError \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(boolean, AUTOMATIC) haltOnError \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint32, AUTOMATIC) tempValue;

    tempValue = baseAddr->CR.R;     /* polyspace RTE:NIV */
    tempValue &= ~(DMA_CR_HOE_MASK);
    tempValue |= DMA_CR_HOE((haltOnError == TRUE) ? 1UL : 0UL); /* PRQA S 2985 */
    baseAddr->CR.R = tempValue;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_SetChnPri \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(eDMAChannelPriorityType, AUTOMATIC) priority, \
    VAR(boolean, AUTOMATIC) ecp, \
    VAR(boolean, AUTOMATIC) dpa \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];  /* polyspace RTE:OBAI */
    VAR(uint8, AUTOMATIC) tempValue;
    VAR(uint8, AUTOMATIC) index = (uint8)EDMA_CHN_TO_DCHPRI_INDEX(channel);
    VAR(uint8, AUTOMATIC) temp = DMA_DCHPRI_CHPRI((uint8)priority);
    VAR(uint8, AUTOMATIC) temp_ecp = DMA_DCHPRI_ECP((uint32)ecp);
    VAR(uint8, AUTOMATIC) temp_dpa = DMA_DCHPRI_DPA((uint32)dpa);

    tempValue = baseAddr->DCHPRI[index].R;      /* polyspace RTE:NIV */
    tempValue &= (uint8)~(DMA_DCHPRI_CHPRI_MASK);
    tempValue &= (uint8)~(DMA_DCHPRI_ECP_MASK);
    tempValue &= (uint8)~(DMA_DCHPRI_DPA_MASK);
    tempValue |= temp; /* PRQA S 2985 */
    tempValue |= temp_ecp; /* PRQA S 2985 */
    tempValue |= temp_dpa; /* PRQA S 2985 */
    baseAddr->DCHPRI[index].R = tempValue;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_MasterIdReplication \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) emi \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint8, AUTOMATIC) index = (uint8)EDMA_CHN_TO_DCHPRI_INDEX(channel);

    baseAddr->DCHMID[index].B.EMI = (uint8)emi;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_SetChnArbitrationMode \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(eDMASelArbitrationModeType, AUTOMATIC) channelArbitration \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint32, AUTOMATIC) tempValue;

    tempValue = baseAddr->CR.R;     /* polyspace RTE:NIV */
    tempValue &= ~(DMA_CR_ERCA_MASK);
    tempValue |= DMA_CR_ERCA(channelArbitration);
    baseAddr->CR.R = tempValue;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(eDMASelArbitrationModeType, EDMA_CODE) EDMA_HW_GetChnArbitrationMode \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance \
)
{
    CONSTP2CONST(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(eDMASelArbitrationModeType, AUTOMATIC) retVal;

    if ((baseAddr->CR.R & DMA_CR_ERCA_MASK) != 0U)  /* polyspace RTE:NIV */
    {
        retVal = EDMA_ARBITRATION_MODE_ROUND_ROBIN;
    }
    else
    {
        retVal = EDMA_ARBITRATION_MODE_FIXED_PRIORITY;
    }

    return retVal;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_EnDisChnErrorInt \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];/* polyspace RTE:OBAI */

    if (enable == TRUE)
    {
        baseAddr->SEEI.R = channel;
    }
    else
    {
        baseAddr->CEEI.R = channel;
    }
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_GetChnErrorIntFlag \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    P2VAR(eDMAErrorRegisterType, AUTOMATIC, EDMA_APPL_DATA) errReg \
)
{
    CONSTP2CONST(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];

    errReg->errh = (uint32)baseAddr->ERRH.R;    /* polyspace RTE:NIV */
    errReg->errl = (uint32)baseAddr->ERRL.R;    /* polyspace RTE:NIV */
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_ClearChnErrorIntFlag \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];

    baseAddr->CERR.R = (uint8)channel;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_EnDisChnDmaReq \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];   /* polyspace RTE:OBAI */

    if (enable == TRUE)
    {
        baseAddr->SERQ.R = channel;
    }
    else
    {
        baseAddr->CERQ.R = channel;
    }
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_WaitChnTransferDoneFlag \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
)
{
    CONSTP2CONST(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint32, AUTOMATIC) eDma_Timeout = 0U;

    while ((baseAddr->TCD[channel].CSR.B.DONE != 1U) && (eDma_Timeout < DEFAULT_TIMEOUT))     /* polyspace RTE:NIV */
    {
        eDma_Timeout++;
    }
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_ClearChnTransferDoneFlg \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];

    baseAddr->CDNE.R = (uint8)channel;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_SetChnTrigStart \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];

    baseAddr->SSRT.R = (uint8)channel;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_ClearChnIntFlag \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];

    baseAddr->CINT.R = (uint8)channel;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_HW_ConfGrpPri \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    P2CONST(eDMAModuleConfigType, EDMA_CONST, EDMA_APPL_CONST) userConfig \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint32, AUTOMATIC) tempValue = baseAddr->CR.R;      /* polyspace RTE:NIV */
    VAR(uint32, AUTOMATIC) mask = 0UL;

    mask = DMA_CR_GRP0PRI_MASK | DMA_CR_GRP1PRI_MASK | DMA_CR_GRP2PRI_MASK | DMA_CR_GRP3PRI_MASK;
    tempValue &= ~mask;
    tempValue |= DMA_CR_GRP0PRI(userConfig->prioGroup0);
    tempValue |= DMA_CR_GRP1PRI(userConfig->prioGroup1);
    tempValue |= DMA_CR_GRP2PRI(userConfig->prioGroup2);
    tempValue |= DMA_CR_GRP3PRI(userConfig->prioGroup3);

    baseAddr->CR.R = tempValue;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_HW_SetGrpArbitrationMode \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(eDMASelArbitrationModeType, AUTOMATIC) groupArbitration \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint32, AUTOMATIC) tempValue;

    tempValue = baseAddr->CR.R;     /* polyspace RTE:NIV */
    tempValue &= ~(DMA_CR_ERGA_MASK);
    tempValue |= DMA_CR_ERGA(groupArbitration);
    baseAddr->CR.R = tempValue;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(eDMASelArbitrationModeType, EDMA_CODE) EDMA_HW_GetGrpArbitrationMode \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance \
)
{
    CONSTP2CONST(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(eDMASelArbitrationModeType, AUTOMATIC) retVal;

    if ((baseAddr->CR.R & DMA_CR_ERGA_MASK) != 0U)      /* polyspace RTE:NIV */
    {
        retVal = EDMA_ARBITRATION_MODE_ROUND_ROBIN;
    }
    else
    {
        retVal = EDMA_ARBITRATION_MODE_FIXED_PRIORITY;
    }

    return retVal;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_EnDisMinorLoopMapping \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];/* polyspace RTE:OBAI */
    VAR(uint32, AUTOMATIC) tempValue;

    tempValue = baseAddr->CR.R;     /* polyspace RTE:NIV */
    tempValue &= ~(DMA_CR_EMLM_MASK);
    tempValue |= DMA_CR_EMLM((enable == TRUE) ? 1UL : 0UL); /* PRQA S 2985 */
    baseAddr->CR.R = tempValue;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDDeInit \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];/* polyspace RTE:OBAI */

    baseAddr->TCD[channel].NBYTES.MLNO.R = 0U;
    baseAddr->TCD[channel].SADDR.R = 0U;
    baseAddr->TCD[channel].SOFF.R = 0;
    baseAddr->TCD[channel].ATTR.R = 0U;
    baseAddr->TCD[channel].SLAST.R = 0;
    baseAddr->TCD[channel].DADDR.R = 0U;
    baseAddr->TCD[channel].DOFF.R = 0;
    baseAddr->TCD[channel].CITER.ELINKNO.R = 0U;
    baseAddr->TCD[channel].DLASTSGA.R = 0;
    baseAddr->TCD[channel].CSR.R = 0U;
    baseAddr->TCD[channel].BITER.ELINKNO.R = 0U;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_HW_TCDSetBusBindwidth \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint8, AUTOMATIC) cycles \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint16, AUTOMATIC)  tempValue;

    tempValue = baseAddr->TCD[channel].CSR.R;   /* polyspace RTE:OBAI,NIV */
    tempValue &= (uint16)~(DMA_TCD_CSR_BWC_MASK);
    tempValue |= (uint16)DMA_TCD_CSR_BWC(cycles); /* PRQA S 2985 */
    baseAddr->TCD[channel].CSR.R = tempValue;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_TCDSetSrcAddr \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) address \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];

    baseAddr->TCD[channel].SADDR.R = address;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_TCDSetSrcAddrOffset \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(sint16, AUTOMATIC) offset \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];

    baseAddr->TCD[channel].SOFF.R = (uint16)offset;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetTransferAttribute \
(
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(eDMAModuloType, AUTOMATIC) srcModulo, \
    VAR(eDMAModuloType, AUTOMATIC) destModulo, \
    VAR(eDMATransferSizeType, AUTOMATIC) srcTransferSize, \
    VAR(eDMATransferSizeType, AUTOMATIC) destTransferSize \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint16, AUTOMATIC) tempValue;

    tempValue = (uint16)(DMA_TCD_ATTR_SMOD(srcModulo) | DMA_TCD_ATTR_SSIZE(srcTransferSize)); /* PRQA S 2985 */
    tempValue |= (uint16)(DMA_TCD_ATTR_DMOD(destModulo) | DMA_TCD_ATTR_DSIZE(destTransferSize)); /* PRQA S 2985 */
    baseAddr->TCD[channel].ATTR.R = tempValue;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetSrcDataTrfSize \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(eDMATransferSizeType, AUTOMATIC) size \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint16, AUTOMATIC) tempValue;
    VAR(uint16, AUTOMATIC) temp = DMA_TCD_ATTR_SSIZE(size);

    tempValue = baseAddr->TCD[channel].ATTR.R;      /* polyspace RTE:NIV */
    tempValue &= (uint16)(~(DMA_TCD_ATTR_SSIZE_MASK));
    tempValue |= temp;
    baseAddr->TCD[channel].ATTR.R = tempValue;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetDestDataTrfSize \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(eDMATransferSizeType, AUTOMATIC) size \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint16, AUTOMATIC) tempValue;
    VAR(uint16, AUTOMATIC) temp = DMA_TCD_ATTR_SSIZE(size);

    tempValue = baseAddr->TCD[channel].ATTR.R;      /* polyspace RTE:NIV */
    tempValue &= (uint16)(~((uint16)DMA_TCD_ATTR_DSIZE_MASK));
    tempValue |= temp; /* PRQA S 2985 */
    baseAddr->TCD[channel].ATTR.R = tempValue;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetMinorByteCount \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) nbytes \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];

    if ((baseAddr->CR.R & DMA_CR_EMLM_MASK) != 0UL)     /* polyspace RTE:NIV */
    {
        VAR(uint32, AUTOMATIC) sdmloe = baseAddr->TCD[channel].NBYTES.MLOFFNO.R & (DMA_TCD_NB_MLOFFNO_SMLOE_MASK | DMA_TCD_NB_MLOFFNO_DMLOE_MASK);/* polyspace RTE:NIV */

        if (sdmloe == 0UL)
        {
            baseAddr->TCD[channel].NBYTES.MLOFFNO.R \
                = (nbytes & DMA_TCD_NBYTES_MLOFFNO_NB_MASK);
        }
        else
        {
            VAR(uint32, AUTOMATIC) tempValue;

            tempValue = baseAddr->TCD[channel].NBYTES.MLOFFYES.R;   /* polyspace RTE:NIV */
            tempValue &= ~(DMA_TCD_NB_MLOFFYES_NB_MASK);
            tempValue |= DMA_TCD_NBYTES_MLOFFYES_NBYTES(nbytes); /* PRQA S 2985 */
            baseAddr->TCD[channel].NBYTES.MLOFFYES.R = tempValue;
        }
    }
    else
    {
        baseAddr->TCD[channel].NBYTES.MLNO.R = nbytes;
    }
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDEnDisSrcMinorLoopOff \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];

    if ((baseAddr->CR.R & DMA_CR_EMLM_MASK) != 0UL) /* polyspace RTE:NIV */
    {
        VAR(uint32, AUTOMATIC) tempValue;
        tempValue = baseAddr->TCD[channel].NBYTES.MLOFFYES.R;   /* polyspace RTE:NIV */
        tempValue &= ~(DMA_TCD_NB_MLOFFYES_SMLOE_MASK);
        tempValue |= DMA_TCD_NBYTES_MLOFFYES_SMLOE((enable == TRUE) ? 1UL : 0UL); /* PRQA S 2985 */
        baseAddr->TCD[channel].NBYTES.MLOFFYES.R = tempValue;
    }
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDEnDisDstMinorLoopOff \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];

    if ((baseAddr->CR.R & DMA_CR_EMLM_MASK) != 0UL)     /* polyspace RTE:NIV */
    {
        VAR(uint32, AUTOMATIC) tempValue;
        tempValue = baseAddr->TCD[channel].NBYTES.MLOFFYES.R;   /* polyspace RTE:NIV */
        tempValue &= ~(DMA_TCD_NB_MLOFFYES_DMLOE_MASK);
        tempValue |= DMA_TCD_NBYTES_MLOFFYES_DMLOE((enable == TRUE) ? 1UL : 0UL); /* PRQA S 2985 */
        baseAddr->TCD[channel].NBYTES.MLOFFYES.R = tempValue;
    }
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetMinorLoopOffset \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(sint32, AUTOMATIC) offset \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];

    if ((baseAddr->CR.R & DMA_CR_EMLM_MASK) != 0UL)     /* polyspace RTE:NIV */
    {
        VAR(uint32, AUTOMATIC) sdmloe = baseAddr->TCD[channel].NBYTES.MLOFFNO.R & (DMA_TCD_NB_MLOFFNO_SMLOE_MASK | DMA_TCD_NB_MLOFFNO_DMLOE_MASK);/* polyspace RTE:NIV */

        if (sdmloe != 0UL)
        {
            VAR(uint32, AUTOMATIC) tempValue;
            tempValue = baseAddr->TCD[channel].NBYTES.MLOFFYES.R;       /* polyspace RTE:NIV */
            tempValue &= ~(DMA_TCD_NB_MLOFFYES_MLOFF_MASK);
            tempValue |= DMA_TCD_NBYTES_MLOFFYES_MLOFF(offset);
            baseAddr->TCD[channel].NBYTES.MLOFFYES.R = tempValue;
        }
    }
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_TCDSetSrcLastAdjust \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(sint32, AUTOMATIC) size \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];

    baseAddr->TCD[channel].SLAST.R = (uint32)size;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_TCDSetDestAddr \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) address \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];

    baseAddr->TCD[channel].DADDR.R = address;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_TCDSetDestAddrOffset \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(sint16, AUTOMATIC) offset \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];

    baseAddr->TCD[channel].DOFF.R = (uint16)offset;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_TCDSetDestLastAdjust \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(sint32, AUTOMATIC) adjust \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];

    baseAddr->TCD[channel].DLASTSGA.R = (uint32)adjust;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
EDMA_INLINE FUNC(void, EDMA_CODE) EDMA_HW_TCDSetScatterGatherLink \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) nextTCDAddr \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];

    baseAddr->TCD[channel].DLASTSGA.R = nextTCDAddr;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetScatterGatherCmd \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint16, AUTOMATIC) tempValue;
    VAR(uint16, AUTOMATIC) temp = DMA_TCD_CSR_ESG((enable == TRUE) ? 1U : 0U);/* PRQA S 2985 */

    tempValue = baseAddr->TCD[channel].CSR.R;       /* polyspace RTE:NIV */
    tempValue &= (uint16)~((uint16)DMA_TCD_CSR_ESG_MASK);
    tempValue |= temp; /* PRQA S 2985 */
    baseAddr->TCD[channel].CSR.R = tempValue;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetChannelMajorLink \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) majorLinkChannel, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint16, AUTOMATIC) tempValue;
    VAR(uint16, AUTOMATIC) temp1 = DMA_TCD_CSR_MAJORLINKCH(majorLinkChannel);
    VAR(uint16, AUTOMATIC) temp2 = DMA_TCD_CSR_MAJORELINK((enable == TRUE) ? 1U : 0U);

    tempValue = baseAddr->TCD[channel].CSR.R;   /* polyspace RTE:NIV */
    tempValue &= (uint16)~(DMA_TCD_CSR_MAJORLINKCH_MASK);
    tempValue |= temp1;
    baseAddr->TCD[channel].CSR.R = tempValue;
    tempValue = baseAddr->TCD[channel].CSR.R;   
    tempValue &= (uint16)~((uint16)DMA_TCD_CSR_MAJORELINK_MASK);
    tempValue |= temp2; /* PRQA S 2985 */
    baseAddr->TCD[channel].CSR.R = tempValue;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetDisDmaReqAftTCD \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) disable \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];/* polyspace RTE:OBAI */
    VAR(uint16, AUTOMATIC) tempValue;
    VAR(uint16, AUTOMATIC) temp = DMA_TCD_CSR_DREQ((disable == TRUE) ? 1U : 0U);

    tempValue = baseAddr->TCD[channel].CSR.R;   /* polyspace RTE:NIV */
    tempValue &= (uint16)~((uint16)DMA_TCD_CSR_DREQ_MASK);
    tempValue |= temp; /* PRQA S 2985 */
    baseAddr->TCD[channel].CSR.R = tempValue;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetMajorHalfCompInt \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint16, AUTOMATIC) tempValue;
    VAR(uint16, AUTOMATIC) temp = DMA_TCD_CSR_INTHALF((enable == TRUE) ? 1U : 0U);

    tempValue = baseAddr->TCD[channel].CSR.R;   /* polyspace RTE:NIV */
    tempValue &= (uint16)~((uint16)DMA_TCD_CSR_INTHALF_MASK);
    tempValue |= temp; /* PRQA S 2985 */
    baseAddr->TCD[channel].CSR.R = tempValue;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetMajorCompIntCmd \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint16, AUTOMATIC) tempValue;
    VAR(uint16, AUTOMATIC) temp = DMA_TCD_CSR_INTMAJOR((enable == TRUE) ? 1U : 0U);

    tempValue = baseAddr->TCD[channel].CSR.R;   /* polyspace RTE:NIV */
    tempValue &= (uint16)~((uint16)DMA_TCD_CSR_INTMAJOR_MASK);
    tempValue |= temp; /* PRQA S 2985 */
    baseAddr->TCD[channel].CSR.R = tempValue;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetChannelMinorLink \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) linkChannel, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint16, AUTOMATIC) tempValue = 0U;
    VAR(uint16, AUTOMATIC) temp1 = DMA_TCD_BITER_ELINKYES_LINKCH(linkChannel);
    VAR(uint16, AUTOMATIC) temp2 = DMA_TCD_CITER_ELINKYES_LINKCH(linkChannel);

    if (enable == TRUE)
    {
        tempValue = baseAddr->TCD[channel].BITER.ELINKYES.R;/* polyspace RTE:NIV */
        tempValue &= (uint16)~(DMA_TCD_BTR_ELKYES_ELINK_MASK);
        tempValue |= (uint16)DMA_TCD_BITER_ELINKYES_ELINK(1UL);
        tempValue &= (uint16)~(DMA_TCD_BTR_ELKYES_LINKCH_MASK);
        tempValue |= temp1;
        baseAddr->TCD[channel].BITER.ELINKYES.R = tempValue;
        tempValue = baseAddr->TCD[channel].CITER.ELINKYES.R;    /* polyspace RTE:NIV */
        tempValue &= (uint16)~(DMA_TCD_CTR_ELINKYES_ELK_MASK);
        tempValue |= (uint16)DMA_TCD_CITER_ELINKYES_ELINK(1UL);
        tempValue &= (uint16)~(DMA_TCD_CTR_ELNKYES_LNKCH_MASK);
        tempValue |= temp2;
        baseAddr->TCD[channel].CITER.ELINKYES.R = tempValue;
    }
    else
    {
        tempValue = baseAddr->TCD[channel].BITER.ELINKNO.R;     /* polyspace RTE:NIV */
        tempValue &= (uint16)~(DMA_TCD_BTR_ELKYES_ELINK_MASK);
        tempValue |= (uint16)DMA_TCD_BITER_ELINKYES_ELINK(0U); /* PRQA S 2985 */
        tempValue &= (uint16)~(DMA_TCD_BTR_ELKYES_LINKCH_MASK);
        tempValue |= temp1;
        baseAddr->TCD[channel].BITER.ELINKNO.R = tempValue;
        tempValue = baseAddr->TCD[channel].CITER.ELINKNO.R;     /* polyspace RTE:NIV */
        tempValue &= (uint16)~(DMA_TCD_CTR_ELINKYES_ELK_MASK);
        tempValue |= (uint16)DMA_TCD_CITER_ELINKYES_ELINK(0U); /* PRQA S 2985 */
        tempValue &= (uint16)~(DMA_TCD_CTR_ELNKYES_LNKCH_MASK);
        tempValue |= temp2;
        baseAddr->TCD[channel].CITER.ELINKNO.R = tempValue;
    }
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_TCDSetMajorCount \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) count \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint16, AUTOMATIC) tempValue = 0U;
    VAR(uint16, AUTOMATIC) temp1 = DMA_TCD_BITER_ELINKYES_BITER(count);
    VAR(uint16, AUTOMATIC) temp2 = DMA_TCD_CITER_ELINKYES_CITER(count);
    VAR(uint16, AUTOMATIC) temp3 = DMA_TCD_BITER_ELINKNO_BITER(count);
    VAR(uint16, AUTOMATIC) temp4 = DMA_TCD_CITER_ELINKNO_CITER(count);

    if ((baseAddr->TCD[channel].BITER.ELINKNO.R & DMA_TCD_BITER_ELINKNO_ELK_MASK) != 0U)    /* polyspace RTE:NIV */
    {
        tempValue = baseAddr->TCD[channel].BITER.ELINKYES.R;    /* polyspace RTE:NIV */
        tempValue &= (uint16)~(DMA_TCD_BTR_ELINKYES_BTR_MASK);
        tempValue |= temp1; /* PRQA S 2985 */
        baseAddr->TCD[channel].BITER.ELINKYES.R = tempValue;
        tempValue = baseAddr->TCD[channel].CITER.ELINKYES.R;    /* polyspace RTE:NIV */
        tempValue &= (uint16)~(DMA_TCD_CTR_ELKYES_CITER_MASK);
        tempValue |= temp2; /* PRQA S 2985 */
        baseAddr->TCD[channel].CITER.ELINKYES.R = tempValue;
    }
    else
    {
        tempValue = baseAddr->TCD[channel].BITER.ELINKNO.R;     /* polyspace RTE:NIV */
        tempValue &= (uint16)~(DMA_TCD_BITER_ELINKNO_BTR_MASK);
        tempValue |= temp3; /* PRQA S 2985 */
        baseAddr->TCD[channel].BITER.ELINKNO.R = tempValue;     
        tempValue = baseAddr->TCD[channel].CITER.ELINKNO.R;     /* polyspace RTE:NIV */
        tempValue &= (uint16)~(DMA_TCD_CITER_ELINKNO_CTR_MASK);
        tempValue |= temp4; /* PRQA S 2985 */
        baseAddr->TCD[channel].CITER.ELINKNO.R = tempValue;
    }
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(uint32, EDMA_CODE) EDMA_HW_TCDGetCurrentMajorCount \
( \
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
)
{
    CONSTP2CONST(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint16, AUTOMATIC) result = 0U;

    if ((baseAddr->TCD[channel].BITER.ELINKNO.R & DMA_TCD_BITER_ELINKNO_ELK_MASK) != 0U)    /* polyspace RTE:NIV */
    {
        result = (uint16)((baseAddr->TCD[channel].CITER.ELINKYES.R & DMA_TCD_CTR_ELKYES_CITER_MASK) >> DMA_TCD_CTR_ELKYES_CITER_SHIFT);/* polyspace RTE:NIV */
    }
    else
    {
        result = (uint16)((baseAddr->TCD[channel].CITER.ELINKNO.R & DMA_TCD_CITER_ELINKNO_CTR_MASK) >> DMA_TCD_CITER_ELINKNO_CTR_SHIFT);/* polyspace RTE:NIV */
    }

    return (uint32) result;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_PushConfigToReg \
( \
    VAR(uint8, AUTOMATIC) mappedChannel,
    P2CONST(eDMATransferConfigType, EDMA_CONST, EDMA_APPL_CONST) tcd \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(tcd != NULL);

    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);
    VAR(uint32, AUTOMATIC) dmaMinorLoopLink;
    VAR(uint32, AUTOMATIC) dmaMajorLoopLink;
    VAR(eDMAIstanceNumType, AUTOMATIC) edma_instance; /* PRQA S 4394 */

    if (EDMA_MCH_TO_INSTANCE(mappedChannel) == 0U)
    {
        edma_instance = EDMA_INSTANCE_0;
    }
    else
    {
        edma_instance = EDMA_INSTANCE_1;
    }

    EDMA_HW_TCDDeInit(edma_instance, edma_channel);
    EDMA_HW_TCDSetSrcAddr(edma_instance, edma_channel, tcd->srcAddr);
    EDMA_HW_TCDSetDestAddr(edma_instance, edma_channel, tcd->destAddr);
    EDMA_HW_TCDSetTransferAttribute(edma_instance, edma_channel, tcd->srcAddrModulo, \
            tcd->destAddrModulo, tcd->srcTransDataSize, tcd->destTransDataSize);
    EDMA_HW_TCDSetSrcAddrOffset(edma_instance, edma_channel, tcd->srcAddrOffset);
    EDMA_HW_TCDSetDestAddrOffset(edma_instance, edma_channel, tcd->destAddrOffset);
    EDMA_HW_TCDSetSrcLastAdjust(edma_instance, edma_channel, tcd->srcAddrAdjustLast);

    if (tcd->featureScatterGatherEn == TRUE)
    {
        EDMA_HW_TCDSetScatterGatherCmd(edma_instance, edma_channel, TRUE);
        EDMA_HW_TCDSetScatterGatherLink(edma_instance, edma_channel, \
                tcd->featureScatterGatherNextDescriptor);
    }
    else
    {
        EDMA_HW_TCDSetScatterGatherCmd(edma_instance, edma_channel, FALSE);
        EDMA_HW_TCDSetDestLastAdjust(edma_instance, edma_channel, tcd->destAddrAdjustLast);/* polyspace RTE:NIV */
    }

    EDMA_HW_TCDSetMajorCompIntCmd(edma_instance, edma_channel, tcd->completeIntEn);

    if (tcd->lpTransConfigPtr != NULL)
    {
        dmaMinorLoopLink = (uint32)EDMA_MCH_TO_CH(tcd->lpTransConfigPtr->minorLpLinkChn);/* polyspace RTE:NIV */
        dmaMajorLoopLink = (uint32)EDMA_MCH_TO_CH(tcd->lpTransConfigPtr->majorLpLinkChn);/* polyspace RTE:NIV */
        EDMA_HW_TCDEnDisSrcMinorLoopOff(edma_instance, edma_channel, \
                tcd->lpTransConfigPtr->srcAddrOffsetEn);/* polyspace RTE:NIV */
        EDMA_HW_TCDEnDisDstMinorLoopOff(edma_instance, edma_channel, \
                tcd->lpTransConfigPtr->dstAddrOffsetEn);/* polyspace RTE:NIV */
        EDMA_HW_TCDSetMinorLoopOffset(edma_instance, edma_channel, \
                tcd->lpTransConfigPtr->minorLpOffset);/* polyspace RTE:NIV */
        EDMA_HW_TCDSetMinorByteCount(edma_instance, edma_channel, tcd->minorTransByte);
        EDMA_HW_TCDSetChannelMinorLink(edma_instance, edma_channel, dmaMinorLoopLink, \
                tcd->lpTransConfigPtr->minorLpLinkEn);/* polyspace RTE:NIV */
        EDMA_HW_TCDSetChannelMajorLink(edma_instance, edma_channel, dmaMajorLoopLink, \
                tcd->lpTransConfigPtr->majorLpLinkEn);/* polyspace RTE:NIV */
        EDMA_HW_TCDSetMajorCount(edma_instance, edma_channel, \
                tcd->lpTransConfigPtr->majorLpIterCnt);/* polyspace RTE:NIV */
    }
    else
    {
        EDMA_HW_TCDSetMinorByteCount(edma_instance, edma_channel, tcd->minorTransByte);
    }

    return;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) DMAMUX_HW_Init(VAR(DMAMUXInstanceNumType, AUTOMATIC) instance)
{
    CONSTP2VAR(DMAMUX_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_dmaMuxbaseAddr[instance];
    VAR(uint8, AUTOMATIC) idx;

    for (idx = 0U; idx < DMAMUX_CHANNELS; idx++)
    {
        baseAddr->CHCFG[idx] = 0U;
    }
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) DMAMUX_HW_SetChannelCmd \
( \
    VAR(DMAMUXInstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    CONSTP2VAR(DMAMUX_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_dmaMuxbaseAddr[instance];     /* polyspace RTE:OBAI */
    VAR(uint32, AUTOMATIC) regIndex = DMAMUX_CHN_REG_INDEX(channel);
    VAR(uint8, AUTOMATIC) tempValue = baseAddr->CHCFG[regIndex];        /* polyspace RTE:NIV */
    VAR(uint8, AUTOMATIC) temp = DMAMUX_CHCFG_ENBL((enable == TRUE) ? 1U : 0U);

    tempValue &= (uint8)~(DMAMUX_CHCFG_ENBL_MASK);
    tempValue |= temp;
    baseAddr->CHCFG[regIndex] = tempValue;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) DMAMUX_HW_SetChannelTrigger \
( \
    VAR(DMAMUXInstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    CONSTP2VAR(DMAMUX_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_dmaMuxbaseAddr[instance];
    VAR(uint32, AUTOMATIC) regIndex = DMAMUX_CHN_REG_INDEX(channel);
    VAR(uint8, AUTOMATIC) tempValue;
    VAR(uint8, AUTOMATIC) temp = DMAMUX_CHCFG_TRIG((enable == TRUE) ? 1U : 0U);

    tempValue = baseAddr->CHCFG[regIndex];      /* polyspace RTE:NIV */
    tempValue &= (uint8)~(DMAMUX_CHCFG_TRIG_MASK);
    tempValue |= temp;
    baseAddr->CHCFG[regIndex] = tempValue;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) DMAMUX_HW_SetChannelSource \
( \
    VAR(DMAMUXInstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint8, AUTOMATIC) source \
)
{
    CONSTP2VAR(DMAMUX_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_dmaMuxbaseAddr[instance];
    VAR(uint32, AUTOMATIC) regIndex = DMAMUX_CHN_REG_INDEX(channel);
    VAR(uint8, AUTOMATIC) tempValue;

    tempValue = baseAddr->CHCFG[regIndex];      /* polyspace RTE:NIV */
    tempValue &= (uint8)~(DMAMUX_CHCFG_SOURCE_MASK);
    tempValue |= (uint8)DMAMUX_CHCFG_SOURCE(source); /* PRQA S 2985 */
    baseAddr->CHCFG[regIndex] = tempValue;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetUpCallback \
( \
    VAR(uint8, AUTOMATIC) mappedChannel,
    VAR(eDMACallbackType, AUTOMATIC) callback,
    P2VAR(void, AUTOMATIC, EDMA_APPL_DATA) parameter \
)
{
    DEV_ASSERT(mappedChannel < EDMA_MAPPED_CHANNELS);
    DEV_ASSERT(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    s_mapEdmaState->mapChnState[mappedChannel]->callback = callback;    /* polyspace RTE:OBAI,IDP */
    s_mapEdmaState->mapChnState[mappedChannel]->parameter = parameter;  /* polyspace RTE:IDP */

    return STATUS_SUCCESS;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetErrCallback \
( \
    VAR(uint8, AUTOMATIC) mappedChannel,
    VAR(eDMACallbackType, AUTOMATIC) callback,
    P2VAR(void, AUTOMATIC, EDMA_APPL_DATA) parameter \
)
{
    DEV_ASSERT(mappedChannel < EDMA_MAPPED_CHANNELS);
    DEV_ASSERT(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    s_mapEdmaState->mapChnState[mappedChannel]->errcallback = callback;    /* polyspace RTE:OBAI,IDP */
    s_mapEdmaState->mapChnState[mappedChannel]->errparameter = parameter;  /* polyspace RTE:IDP */

    return STATUS_SUCCESS;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_HW_ReleaseChannel(VAR(uint8, AUTOMATIC) mappedChannel)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_TOTAL_CHANNELS);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_EnDisChnDmaReq((eDMAIstanceNumType)edma_instance, edma_channel, FALSE);

    return;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_HW_ClearIntStatus(VAR(uint8, AUTOMATIC) mappedChannel)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_TOTAL_CHANNELS);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_ClearChnTransferDoneFlg((eDMAIstanceNumType)edma_instance, edma_channel);
    EDMA_HW_ClearChnIntFlag((eDMAIstanceNumType)edma_instance, edma_channel);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
static FUNC(void, EDMA_CODE) EDMA_HW_ClearStructPtr \
( \
    P2VAR(uint8, AUTOMATIC, EDMA_APPL_DATA) sructPtr, \
    volatile VAR(uint32, AUTOMATIC) size \
)
{
    P2VAR(uint8, AUTOMATIC, EDMA_APPL_DATA) s_sructPtr = sructPtr;
    volatile VAR(uint32, AUTOMATIC) s_size = size;

    while (s_size > 0U)
    {
        *s_sructPtr = 0U;   /* polyspace RTE:IDP */
        s_sructPtr++;
        s_size = s_size - 1U;
    }
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SwRequestTriggerEn(VAR(uint8, AUTOMATIC) mappedChannel)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_SetChnTrigStart((eDMAIstanceNumType)edma_instance, edma_channel);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetChannelSourceConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel,
    VAR(uint32, AUTOMATIC) request,
    VAR(boolean, AUTOMATIC) triggerEn \
)
{
    EDMA_DEV_ERR(mappedChannel < (uint32)EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);

#ifdef DMAMUX_AVAILABLE
    VAR(uint8, AUTOMATIC) dmamux_instance = (uint8)DMAMUX_REQ_SRC_TO_INSTANCE(request);
    VAR(uint8, AUTOMATIC) dmamux_request = (uint8)DMAMUX_REQ_SRC_TO_CH(request);
    VAR(uint8, AUTOMATIC) dmamux_channel = (uint8)DMAMUX_DMA_CH_TO_CH(mappedChannel);

    DMAMUX_HW_SetChannelCmd((DMAMUXInstanceNumType)dmamux_instance, dmamux_channel, FALSE);
    DMAMUX_HW_SetChannelSource((DMAMUXInstanceNumType)dmamux_instance, dmamux_channel, \
            dmamux_request);
#ifdef DMAMUX_HAS_TRIG
    DMAMUX_HW_SetChannelTrigger((DMAMUXInstanceNumType)dmamux_instance, dmamux_channel, triggerEn);
#else
    (void)triggerEn;
#endif
    DMAMUX_HW_SetChannelCmd((DMAMUXInstanceNumType)dmamux_instance, dmamux_channel, TRUE);

    return STATUS_SUCCESS;
#else
    (void)mappedChannel;
    (void)request;
    (void)triggerEn;
    return STATUS_UNSUPPORTED;
#endif
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_ChannelInit \
( \
    P2VAR(eDMAChnStateType, AUTOMATIC, EDMA_APPL_DATA) eedma_channelState, \
    P2CONST(eDMAChanConfigType, EDMA_CONST, EDMA_APPL_CONST) eedma_channelConfig \
)
{
    EDMA_DEV_ERR(eedma_channelConfig != NULL);
    EDMA_DEV_ERR(eedma_channelConfig->mappedChnConfig < EDMA_TOTAL_CHANNELS);

    VAR(uint8, AUTOMATIC) edma_instance \
        = (uint8)EDMA_MCH_TO_INSTANCE(eedma_channelConfig->mappedChnConfig);
    VAR(uint8, AUTOMATIC) edma_channel \
        = (uint8)EDMA_MCH_TO_CH(eedma_channelConfig->mappedChnConfig);
    VAR(uint8, AUTOMATIC) mappedChannel = eedma_channelConfig->mappedChnConfig;

    EDMA_HW_ClearStructPtr((uint8 *)eedma_channelState, sizeof(eDMAChnStateType));

    VAR(status_t, AUTOMATIC) retStatus = STATUS_SUCCESS;

    s_mapEdmaState->mapChnState[mappedChannel] = eedma_channelState;    /* polyspace RTE:OBAI,IDP */
    s_mapEdmaState->mapChnState[mappedChannel]->mappedChn = mappedChannel;
    s_mapEdmaState->mapChnState[mappedChannel]->status = EDMA_CHN_STATUS_NORMAL;    /* polyspace RTE:IDP */
    EDMA_HW_EnDisChnErrorInt((eDMAIstanceNumType)edma_instance, edma_channel, \
            eedma_channelConfig->chnErrIntEn);
    retStatus = EDMA_LLD_SetChannelSourceConfig \
                (
                    eedma_channelConfig->mappedChnConfig, \
                    (uint32)eedma_channelConfig->reqSource, \
                    eedma_channelConfig->triggerEn \
                );
    EDMA_HW_TCDDeInit((eDMAIstanceNumType)edma_instance, edma_channel);

    if ((EDMA_HW_GetChnArbitrationMode((eDMAIstanceNumType)edma_instance) \
            == EDMA_ARBITRATION_MODE_FIXED_PRIORITY) \
            && (eedma_channelConfig->chnPrioSet != EDMA_CHN_PRIORITY_DEFALUT))
    {
        EDMA_HW_SetChnPri((eDMAIstanceNumType)edma_instance, edma_channel, \
                eedma_channelConfig->chnPrioSet, eedma_channelConfig->preemptionEn, \
                eedma_channelConfig->preemptAbilityDisable);
    }

    EDMA_HW_MasterIdReplication((eDMAIstanceNumType)edma_instance, edma_channel, \
                                eedma_channelConfig->MasterIdReplicationEn);

    (void) EDMA_LLD_SetUpCallback(eedma_channelConfig->mappedChnConfig, \
            eedma_channelConfig->callback, eedma_channelConfig->callbackParam);

    (void) EDMA_LLD_SetErrCallback(eedma_channelConfig->mappedChnConfig, \
            eedma_channelConfig->errCallback, eedma_channelConfig->errCallbackParam);

    return retStatus;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_ModuleInit \
( \
    P2VAR(edma_state_t, AUTOMATIC, EDMA_APPL_DATA) edmaState, \
    P2CONST(eDMAModuleConfigType, EDMA_CONST, EDMA_APPL_CONST) userConfig, \
    CONSTP2VAR(eDMAChnStateType, EDMA_CONST, EDMA_APPL_CONST) chnStateArray[], \
    CONSTP2CONST(eDMAChanConfigType, EDMA_CONST, EDMA_APPL_CONST) chnConfigArray[], \
    VAR(uint32, AUTOMATIC) chnCount \
)
{
    VAR(uint32, AUTOMATIC) index = 0U;
    VAR(uint8, AUTOMATIC) edma_instance = 0U;
    VAR(status_t, AUTOMATIC) edmaStatus = STATUS_SUCCESS;
    VAR(status_t, AUTOMATIC) chnInitStatus = STATUS_SUCCESS;

    DEV_ASSERT((edmaState != NULL) && (userConfig != NULL));
    DEV_ASSERT(s_mapEdmaState == NULL);

    s_mapEdmaState = edmaState; /* PRQA S 2919 */
    EDMA_HW_ClearStructPtr((uint8 *)s_mapEdmaState, sizeof(edma_state_t));

    for (index = 0U; index < (uint32)EDMA_INSTANCE_COUNT; index++)
    {
        edma_instance = (uint8)index;

        EDMA_HW_Init((eDMAIstanceNumType)edma_instance);
        EDMA_HW_SetChnArbitrationMode((eDMAIstanceNumType)edma_instance, \
                userConfig[index].setChnArbitMode);
        EDMA_HW_ConfGrpPri((eDMAIstanceNumType)edma_instance, \
                &userConfig[index]);
        EDMA_HW_EnDisHaltOnError((eDMAIstanceNumType)edma_instance, userConfig[index].haltOnError);
    }
#ifdef DMAMUX_AVAILABLE
    for (index = 0U; index < DMAMUX_INSTANCE_COUNT; index++)
    {
        DMAMUX_HW_Init((DMAMUXInstanceNumType)index);
    }
#endif
    if ((chnStateArray != NULL) && (chnConfigArray != NULL))
    {
        for (index = 0U; index < chnCount; index++)
        {
            chnInitStatus = EDMA_LLD_ChannelInit(chnStateArray[index], chnConfigArray[index]);  /* polyspace RTE:IDP */

            if (chnInitStatus != STATUS_SUCCESS)
            {
                edmaStatus = chnInitStatus;
            }
        }
    }

    return edmaStatus;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_NoUsedChInit \
( \
    CONSTP2CONST(eDMAChPriorityCfg, EDMA_CONST, EDMA_APPL_CONST) chPriorityCfgs \
)
{
    VAR(uint8, AUTOMATIC) edma_instance = 0U;
    VAR(uint8, AUTOMATIC) edma_channel = 0U;
    VAR(uint32, AUTOMATIC) index = 0U;
    
    for (index = 0U; index < EDMA_TOTAL_CHANNELS; index++)
    {
        if (chPriorityCfgs[index].isUsed == FALSE)  /* polyspace RTE:NIV,IDP */
        {
            edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(chPriorityCfgs[index].channel);     /* polyspace RTE:NIV */
            edma_channel = (uint8)EDMA_MCH_TO_CH(chPriorityCfgs[index].channel);
            EDMA_HW_SetChnPri((eDMAIstanceNumType)edma_instance, edma_channel, \
                chPriorityCfgs[index].chPriority, FALSE, FALSE);        /* polyspace RTE:NIV */
        }
    }
    
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_ClearSwTCDStruct \
( \
    P2VAR(eDMASwTcdType, AUTOMATIC, EDMA_APPL_DATA) swtcd \
)
{
    EDMA_HW_ClearStructPtr((uint8 *)swtcd, sizeof(eDMASwTcdType));
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_IRQHandler(VAR(uint8, AUTOMATIC) mappedChannel)
{
    P2CONST(eDMAChnStateType, EDMA_CONST, EDMA_APPL_CONST) chnState \
        = s_mapEdmaState->mapChnState[mappedChannel];       /* polyspace RTE:IDP */

    EDMA_DEV_ERR(mappedChannel < EDMA_TOTAL_CHANNELS);
    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[edma_instance];

    baseAddr->CDNE.R = (uint8)edma_channel;
    baseAddr->CINT.R = (uint8)edma_channel;

    if (chnState != NULL)
    {
        if (chnState->callback != NULL)     /* polyspace RTE:NIP,IDP */ 
        {
            chnState->callback(chnState->parameter, chnState->status, mappedChannel);   /* polyspace RTE:NIV,NIP,COR */
        }
    }

}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_ErrorIRQHandler(VAR(uint8, AUTOMATIC) mappedChannel)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_TOTAL_CHANNELS);
    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[edma_instance]; /* polyspace RTE:OBAI */

    EDMA_HW_EnDisChnErrorInt((eDMAIstanceNumType)edma_instance, edma_channel, FALSE);

    P2VAR(eDMAChnStateType, AUTOMATIC, EDMA_APPL_DATA) chnState \
        = s_mapEdmaState->mapChnState[mappedChannel];   /* polyspace RTE:IDP */

    baseAddr->CDNE.R = (uint8)edma_channel;
    baseAddr->CINT.R = (uint8)edma_channel;
    
    if (chnState != NULL)
    {
        EDMA_HW_ClearIntStatus(mappedChannel);
        EDMA_HW_ClearChnErrorIntFlag((eDMAIstanceNumType)edma_instance, edma_channel);
        chnState->status = EDMA_LLD_GetErrInfo(edma_channel);   /* polyspace RTE:IDP */
        EDMA_HW_EnDisChnErrorInt((eDMAIstanceNumType)edma_instance, edma_channel, TRUE);
        if (chnState->errcallback != NULL)     /* polyspace RTE:NIP */
        {
            chnState->errcallback(chnState->parameter, chnState->status, mappedChannel);   /* polyspace RTE:NIP,COR,IDP */
        }
    }
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetSglTransferConfig  
( \
    VAR(uint8, AUTOMATIC) mappedChannel, /* PRQA S 2755 */ 
    VAR(eDMATransferType, AUTOMATIC) type, \
    VAR(uint32, AUTOMATIC) srcAddr, \
    VAR(uint32, AUTOMATIC) destAddr, \
    VAR(eDMATransferSizeType, AUTOMATIC) transferSize, \
    VAR(uint32, AUTOMATIC) dataBufferSize \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);
    VAR(uint8, AUTOMATIC) transferOffset = 1U;
    VAR(status_t, AUTOMATIC) retStatus = STATUS_SUCCESS;

    if ((uint8)transferSize < 8U)
    {
        transferOffset = (uint8) (1U << ((uint8)transferSize));
    }

    EDMA_DEV_ERR((srcAddr % transferOffset) == 0U);
    EDMA_DEV_ERR((destAddr % transferOffset) == 0U);

    if ((dataBufferSize % transferOffset) != 0U)
    {
        retStatus = STATUS_ERROR;
    }

    if (retStatus == STATUS_SUCCESS)
    {
        EDMA_HW_TCDDeInit((eDMAIstanceNumType)edma_instance, edma_channel);
        EDMA_HW_EnDisMinorLoopMapping((eDMAIstanceNumType)edma_instance, TRUE);
        EDMA_HW_TCDSetSrcAddr((eDMAIstanceNumType)edma_instance, edma_channel, srcAddr);
        EDMA_HW_TCDSetDestAddr((eDMAIstanceNumType)edma_instance, edma_channel, destAddr);
        EDMA_HW_TCDSetTransferAttribute((eDMAIstanceNumType)edma_instance, edma_channel, \
                EDMA_ADDRESS_MODULO_OFF, EDMA_ADDRESS_MODULO_OFF, transferSize, transferSize);

        switch (type)
        {
        case EDMA_TRANSFER_TYPE_PERIPHTOMEM:
        {
            EDMA_HW_TCDSetSrcAddrOffset((eDMAIstanceNumType)edma_instance, edma_channel, 0);
            EDMA_HW_TCDSetDestAddrOffset((eDMAIstanceNumType)edma_instance, edma_channel, \
                    (sint8) transferOffset);
            break;
        }
        case EDMA_TRANSFER_TYPE_MEMTOPERIPH:
        {
            EDMA_HW_TCDSetSrcAddrOffset((eDMAIstanceNumType)edma_instance, edma_channel, \
                    (sint8) transferOffset);
            EDMA_HW_TCDSetDestAddrOffset((eDMAIstanceNumType)edma_instance, edma_channel, 0);
            break;
        }
        case EDMA_TRANSFER_TYPE_MEMTOMEM:
        {
            EDMA_HW_TCDSetSrcAddrOffset((eDMAIstanceNumType)edma_instance, edma_channel, \
                    (sint8) transferOffset);
            EDMA_HW_TCDSetDestAddrOffset((eDMAIstanceNumType)edma_instance, edma_channel, \
                    (sint8) transferOffset);
            break;
        }
        case EDMA_TRANSFER_TYPE_PERIPHTOPERIPH:
        {
            EDMA_HW_TCDSetSrcAddrOffset((eDMAIstanceNumType)edma_instance, edma_channel, 0);
            EDMA_HW_TCDSetDestAddrOffset((eDMAIstanceNumType)edma_instance, edma_channel, 0);
            break;
        }
        default:
        {
            EDMA_DEV_ERR(FALSE);
            break;
        }
        }

        EDMA_HW_TCDSetMinorByteCount((eDMAIstanceNumType)edma_instance, edma_channel, \
                dataBufferSize);
        EDMA_HW_TCDSetMajorCount((eDMAIstanceNumType)edma_instance, edma_channel, 1U);
        EDMA_HW_TCDSetMajorCompIntCmd((eDMAIstanceNumType)edma_instance, edma_channel, TRUE);
        s_mapEdmaState->mapChnState[mappedChannel]->status = EDMA_CHN_STATUS_NORMAL;    /* polyspace RTE:IDP */
    }

    return retStatus;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetMultiTransferConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMATransferType, AUTOMATIC) type, \
    VAR(uint32, AUTOMATIC) srcAddr, \
    VAR(uint32, AUTOMATIC) destAddr, \
    VAR(eDMATransferSizeType, AUTOMATIC) transferSize, \
    VAR(uint32, AUTOMATIC) blockSize, \
    VAR(uint32, AUTOMATIC) blockCount, \
    VAR(boolean, AUTOMATIC) disableReqOnCompletion \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);
    VAR(status_t, AUTOMATIC) retStatus = STATUS_SUCCESS;

    retStatus = EDMA_LLD_SetSglTransferConfig(mappedChannel, type, srcAddr, destAddr, \
            transferSize, blockSize);

    if (retStatus == STATUS_SUCCESS)
    {
        EDMA_HW_TCDSetMajorCount((eDMAIstanceNumType)edma_instance, edma_channel, blockCount);
        EDMA_HW_TCDSetDisDmaReqAftTCD((eDMAIstanceNumType)edma_instance, \
                edma_channel, disableReqOnCompletion);
    }

    return retStatus;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetLoopTransferConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    P2CONST(eDMATransferConfigType, EDMA_CONST, EDMA_APPL_CONST) transferConfig \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);
    EDMA_DEV_ERR(transferConfig != NULL);
    EDMA_DEV_ERR(transferConfig->lpTransConfigPtr != NULL);

    if((uint32)transferConfig->srcAddrModulo < 32U)
    {
        EDMA_DEV_ERR((transferConfig->srcAddrModulo == EDMA_ADDRESS_MODULO_OFF) \
            || ((transferConfig->srcAddr \
                % (((uint32)1U) << (uint32)transferConfig->srcAddrModulo)) == 0U));
    }

    if((uint32)transferConfig->destAddrModulo < 32U)
    {
        EDMA_DEV_ERR((transferConfig->destAddrModulo == EDMA_ADDRESS_MODULO_OFF) \
            || ((transferConfig->destAddr \
                % (((uint32)1U) << (uint32)transferConfig->destAddrModulo)) == 0U));
    }

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);

    EDMA_HW_EnDisMinorLoopMapping((eDMAIstanceNumType)edma_instance, TRUE);
    EDMA_HW_PushConfigToReg(mappedChannel, transferConfig);
    s_mapEdmaState->mapChnState[mappedChannel]->status = EDMA_CHN_STATUS_NORMAL;    /* polyspace RTE:IDP */

    return STATUS_SUCCESS;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_CopyConfigToSwTCD \
( \
    P2CONST(eDMATransferConfigType, EDMA_CONST, EDMA_APPL_CONST) config,
    P2VAR(eDMASwTcdType, AUTOMATIC, EDMA_APPL_DATA)stcd \
)
{
    if ((config != NULL) && (stcd != NULL))
    {
        EDMA_LLD_ClearSwTCDStruct(stcd);

        stcd->ATTR = (uint16)(DMA_TCD_ATTR_SMOD(config->srcAddrModulo) /* polyspace RTE:IDP */ /* PRQA S 2985 */
                              | DMA_TCD_ATTR_SSIZE(config->srcTransDataSize) /* PRQA S 2985 */ 
                              | DMA_TCD_ATTR_DMOD(config->destAddrModulo) /* PRQA S 2985 */ 
                              | DMA_TCD_ATTR_DSIZE(config->destTransDataSize)); /* PRQA S 2985 */
        stcd->SADDR = config->srcAddr;
        stcd->SOFF = config->srcAddrOffset;
        stcd->NBYTES = config->minorTransByte;
        stcd->SLAST = config->srcAddrAdjustLast;
        stcd->DADDR = config->destAddr;
        stcd->DOFF = config->destAddrOffset;
        stcd->CITER = (uint16) config->lpTransConfigPtr->majorLpIterCnt;    /* polyspace RTE:NIV,IDP */

        if (config->featureScatterGatherEn == TRUE)
        {
            stcd->DLAST_SGA = (sint32) config->featureScatterGatherNextDescriptor;
        }
        else
        {
            stcd->DLAST_SGA = config->destAddrAdjustLast;
        }

        stcd->CSR = (uint16)(((uint32)((config->completeIntEn == TRUE) ? 1U : 0U) \
                      << DMA_TCD_CSR_INTMAJOR_SHIFT) \
                     | ((uint32)((config->featureScatterGatherEn == TRUE) ? 1U : 0U) \
                      << DMA_TCD_CSR_ESG_SHIFT));
        stcd->BITER = (uint16) config->lpTransConfigPtr->majorLpIterCnt;
    }
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetScatterGatherTrfCfg \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    P2CONST(eDMASwTcdType, EDMA_CONST, EDMA_APPL_CONST) stcd, \
    VAR(eDMATransferSizeType, AUTOMATIC) transferSize, \
    VAR(uint32, AUTOMATIC) bytesOnEachRequest, \
    P2CONST(eDMAScatterGatherListType, EDMA_CONST, EDMA_APPL_CONST) srcList, \
    P2CONST(eDMAScatterGatherListType, EDMA_CONST, EDMA_APPL_CONST) destList, \
    VAR(uint8, AUTOMATIC) tcdCount \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);
    EDMA_DEV_ERR((stcd != NULL) && (srcList != NULL) && (destList != NULL));

    VAR(uint8, AUTOMATIC) i = 0U;
    VAR(uint16, AUTOMATIC) transferOffset = 1U;
    VAR(uint32, AUTOMATIC) stcdAlignedAddr = TCD_ADDR_CALC(stcd);
    P2VAR(eDMASwTcdType, AUTOMATIC, EDMA_APPL_DATA) edmaSwTcdAddr \
        = (eDMASwTcdType *)stcdAlignedAddr;
    VAR(eDMALoopTransferConfigType, AUTOMATIC) edmaLoopConfig;
    VAR(eDMATransferConfigType, AUTOMATIC) edmaTransferConfig;
    VAR(status_t, AUTOMATIC) retStatus = STATUS_SUCCESS;

    s_mapEdmaState->mapChnState[mappedChannel]->status = EDMA_CHN_STATUS_NORMAL;    /* polyspace RTE:IDP */

    if((uint16)transferSize < 16U)
    {
        transferOffset = (uint16) (1UL << ((uint16)transferSize));
    }

    if ((bytesOnEachRequest % transferOffset) != 0U)
    {
        retStatus = STATUS_ERROR;
    }

    EDMA_HW_ClearStructPtr((uint8 *)(&edmaTransferConfig), sizeof(eDMATransferConfigType));
    EDMA_HW_ClearStructPtr((uint8 *)(&edmaLoopConfig), sizeof(eDMALoopTransferConfigType));

    edmaTransferConfig.srcAddrAdjustLast = 0;
    edmaTransferConfig.destAddrAdjustLast = 0;
    edmaTransferConfig.srcAddrModulo = EDMA_ADDRESS_MODULO_OFF;
    edmaTransferConfig.destAddrModulo = EDMA_ADDRESS_MODULO_OFF;
    edmaTransferConfig.srcTransDataSize = transferSize;
    edmaTransferConfig.destTransDataSize = transferSize;
    edmaTransferConfig.minorTransByte = bytesOnEachRequest;
    edmaTransferConfig.completeIntEn = TRUE;
    edmaTransferConfig.featureScatterGatherEn = TRUE;
    edmaTransferConfig.lpTransConfigPtr = &edmaLoopConfig;
    edmaTransferConfig.lpTransConfigPtr->srcAddrOffsetEn = FALSE;
    edmaTransferConfig.lpTransConfigPtr->dstAddrOffsetEn = FALSE;
    edmaTransferConfig.lpTransConfigPtr->minorLpLinkEn = FALSE;
    edmaTransferConfig.lpTransConfigPtr->majorLpLinkEn = FALSE;
    edmaTransferConfig.srcAddrOffset = 0;
    edmaTransferConfig.destAddrOffset = 0;

    for (i = 0U; (i < tcdCount) && (retStatus == STATUS_SUCCESS); i++)
    {
        edmaTransferConfig.srcAddr = srcList[i].address;
        edmaTransferConfig.destAddr = destList[i].address;

        if ((srcList[i].length != destList[i].length) || (srcList[i].type != destList[i].type))
        {
            break;
        }
		if (bytesOnEachRequest == 0U)
	        {
	            retStatus = STATUS_ERROR;
		    	return retStatus;
	        }
        edmaTransferConfig.lpTransConfigPtr->majorLpIterCnt = srcList[i].length/bytesOnEachRequest; /* polyspace RTE:ZDV */

        switch (srcList[i].type)
        {
        case EDMA_TRANSFER_TYPE_PERIPHTOMEM:
        {
            edmaTransferConfig.srcAddrOffset = 0;
            edmaTransferConfig.destAddrOffset = (sint16) transferOffset;
            break;
        }
        case EDMA_TRANSFER_TYPE_MEMTOPERIPH:
        {
            edmaTransferConfig.srcAddrOffset = (sint16) transferOffset;
            edmaTransferConfig.destAddrOffset = 0;
            break;
        }
        case EDMA_TRANSFER_TYPE_MEMTOMEM:
        {
            edmaTransferConfig.srcAddrOffset = (sint16) transferOffset;
            edmaTransferConfig.destAddrOffset = (sint16) transferOffset;
            break;
        }
        case EDMA_TRANSFER_TYPE_PERIPHTOPERIPH:
        {
            edmaTransferConfig.srcAddrOffset = 0;
            edmaTransferConfig.destAddrOffset = 0;
            break;
        }
        default:
        {
            EDMA_DEV_ERR(FALSE);
            break;
        }
        }

        if (i == ((uint8)(tcdCount - 1U)))
        {
            edmaTransferConfig.featureScatterGatherNextDescriptor = 0U;
        }
        else
        {
            P2CONST(eDMASwTcdType, EDMA_CONST, EDMA_APPL_CONST) ptNextAddr = &edmaSwTcdAddr[i];
            edmaTransferConfig.featureScatterGatherNextDescriptor = ((uint32) ptNextAddr);
        }

        if (i == 0U)
        {
            EDMA_HW_PushConfigToReg(mappedChannel, &edmaTransferConfig);
        }
        else
        {
            EDMA_LLD_CopyConfigToSwTCD(&edmaTransferConfig, &edmaSwTcdAddr[i - 1U]);
        }
    }

    return retStatus;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetChannelRequest(VAR(uint8, AUTOMATIC) mappedChannel)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_EnDisChnDmaReq((eDMAIstanceNumType)edma_instance, edma_channel, TRUE);

    return STATUS_SUCCESS;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_ClearChannelRequest(VAR(uint8, AUTOMATIC) mappedChannel)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_EnDisChnDmaReq((eDMAIstanceNumType)edma_instance, edma_channel, FALSE);

    return STATUS_SUCCESS;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_ClearHwTCD(VAR(uint8, AUTOMATIC) mappedChannel)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_TCDDeInit((eDMAIstanceNumType)edma_instance, edma_channel);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnSrcAddr \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) address \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_TCDSetSrcAddr((eDMAIstanceNumType)edma_instance, edma_channel, address);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnSrcAddrOffset \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(sint16, AUTOMATIC) offset \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_TCDSetSrcAddrOffset((eDMAIstanceNumType)edma_instance, edma_channel, offset);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnSrcAddrRdTrfSize \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMATransferSizeType, AUTOMATIC) size \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_TCDSetSrcDataTrfSize((eDMAIstanceNumType)edma_instance, edma_channel, size);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnSrcAddrLastAdj \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(sint32, AUTOMATIC) adjust \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_TCDSetSrcLastAdjust((eDMAIstanceNumType)edma_instance, edma_channel, adjust);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnDestAddrLastAdj \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(sint32, AUTOMATIC) adjust \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_TCDSetDestLastAdjust((eDMAIstanceNumType)edma_instance, edma_channel, adjust);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnDestAddr \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) address \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_TCDSetDestAddr((eDMAIstanceNumType)edma_instance, edma_channel, address);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnDestAddrOffset \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(sint16, AUTOMATIC) offset \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_TCDSetDestAddrOffset((eDMAIstanceNumType)edma_instance, edma_channel, offset);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnDestdrWrTrfSize \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMATransferSizeType, AUTOMATIC) size \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_TCDSetDestDataTrfSize((eDMAIstanceNumType)edma_instance, edma_channel, size);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnMinorLpTrfByte \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) nbytes \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);
    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_TCDSetMinorByteCount((eDMAIstanceNumType)edma_instance, edma_channel, nbytes);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnMajorLpIterCount \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) majorLoopCount \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_TCDSetMajorCount((eDMAIstanceNumType)edma_instance, edma_channel, majorLoopCount);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(uint32, EDMA_CODE) EDMA_LLD_GetChnRemainingIterCnt \
( \
    VAR(uint8, AUTOMATIC) mappedChannel \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    VAR(uint32, AUTOMATIC) count \
        = EDMA_HW_TCDGetCurrentMajorCount((eDMAIstanceNumType)edma_instance, edma_channel);

    return count;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnSctGthLinkMode \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) nextTCDAddr \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_TCDSetScatterGatherLink((eDMAIstanceNumType)edma_instance, edma_channel, nextTCDAddr);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnDisReqOnTrfComp \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(boolean, AUTOMATIC) disable \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_TCDSetDisDmaReqAftTCD((eDMAIstanceNumType)edma_instance, \
            edma_channel, disable);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetInterruptConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMAChannelInterruptType, AUTOMATIC) intSrc, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    switch (intSrc)
    {
    case EDMA_CHN_ENABLE_ERROR_INT:
    {
        EDMA_HW_EnDisChnErrorInt((eDMAIstanceNumType)edma_instance, edma_channel, enable);
        break;
    }
    case EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT:
    {
        EDMA_HW_TCDSetMajorHalfCompInt((eDMAIstanceNumType)edma_instance, edma_channel, \
                enable);
        break;
    }
    case EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT:
    {
        EDMA_HW_TCDSetMajorCompIntCmd((eDMAIstanceNumType)edma_instance, edma_channel, \
                enable);
        break;
    }
    default:
    {
        EDMA_DEV_ERR(FALSE);
        break;
    }
    }
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_CancelExcutingChnTrf(VAR(boolean, AUTOMATIC) error)
{
    EDMA_DEV_ERR(s_mapEdmaState != NULL);

    VAR(uint32, AUTOMATIC) edma_instance = 0U;

    for (edma_instance = 0U; edma_instance < (uint32)EDMA_INSTANCE_COUNT; edma_instance++)
    {
        if (error == TRUE)
        {
            EDMA_HW_CnlExecChnTrfWithError((eDMAIstanceNumType)edma_instance);
        }
        else
        {
            EDMA_HW_CancelExecChnTransfer((eDMAIstanceNumType)edma_instance);
        }
    }
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_WaitChnTransferDone(VAR(uint8, AUTOMATIC) mappedChannel)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);

    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_WaitChnTransferDoneFlag((eDMAIstanceNumType)edma_instance, edma_channel);
    EDMA_HW_ClearChnTransferDoneFlg((eDMAIstanceNumType)edma_instance, edma_channel);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(eDMAChnStatusType, EDMA_CODE) EDMA_LLD_GetChnConfigStatus(VAR(uint8, AUTOMATIC) mappedChannel)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);
    EDMA_DEV_ERR(s_mapEdmaState != NULL);
    EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    return s_mapEdmaState->mapChnState[mappedChannel]->status; /* polyspace RTE:NIV,IDP */ /* PRQA S 0404 */
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(boolean, EDMA_CODE) EDMA_LLD_GetMasterID_PAL \
(\
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(boolean, AUTOMATIC) Value;
    VAR(uint8, AUTOMATIC) temp;

    temp = baseAddr->DCHMID[channel].R;     /* polyspace RTE:NIV,OBAI */
    temp &= DMA_DCHMID_PAL_MASK;
    Value = (boolean)(temp >> DMA_DCHMID_PAL_SHIFT);

    return Value;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(uint8, EDMA_CODE) EDMA_LLD_GetMasterID_MID \
(\
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
)
{
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[instance];
    VAR(uint8, AUTOMATIC) Value;
    VAR(uint8, AUTOMATIC) temp;

    temp = baseAddr->DCHMID[channel].R;     /* polyspace RTE:NIV,OBAI */
    temp &= DMA_DCHMID_MID_MASK;
    Value = temp >> DMA_DCHMID_MID_SHIFT;

    return Value;
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(eDMAChnStatusType, EDMA_CODE) EDMA_LLD_GetErrInfo( \
    VAR(uint8, AUTOMATIC) mappedChannel \
)
{
    EDMA_DEV_ERR(mappedChannel < EDMA_MAPPED_CHANNELS);

    VAR(uint32, AUTOMATIC) eDmaErrStatus = 0;
    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    CONSTP2VAR(DMA_Type, EDMA_CONST, EDMA_APPL_CONST) baseAddr = s_edmabaseAddr[edma_instance];
    P2VAR(eDMAChnStateType, AUTOMATIC, EDMA_APPL_DATA) chnState \
        = s_mapEdmaState->mapChnState[mappedChannel];   /* polyspace RTE:IDP */

    eDmaErrStatus = baseAddr->ES.R; /* polyspace RTE:NIV */
	
	if(((eDmaErrStatus >> DMA_ES_UCE_SHIFT) & 0x01U) == 1U)
	{
		chnState->status = EDMA_CHN_STATUS_ERR_UCE; /* polyspace RTE:IDP */
	}
	else if(((eDmaErrStatus >> DMA_ES_ECX_SHIFT) & 0x01U) == 1U)
	{
        chnState->status = EDMA_CHN_STATUS_ERR_ECX; /* polyspace RTE:IDP */
	}
	else if(((eDmaErrStatus >> DMA_ES_GPE_SHIFT) & 0x01U) == 1U)
	{
        chnState->status = EDMA_CHN_STATUS_ERR_GPE; /* polyspace RTE:IDP */
	}
    else if(((eDmaErrStatus >> DMA_ES_CPE_SHIFT) & 0x01U) == 1U)
	{
        chnState->status = EDMA_CHN_STATUS_ERR_CPE; /* polyspace RTE:IDP */
	}
    else if(((eDmaErrStatus >> DMA_ES_SAE_SHIFT) & 0x01U) == 1U)
	{
        chnState->status = EDMA_CHN_STATUS_ERR_SAE; /* polyspace RTE:IDP */
	}
    else if(((eDmaErrStatus >> DMA_ES_SOE_SHIFT) & 0x01U) == 1U)
	{
        chnState->status = EDMA_CHN_STATUS_ERR_SOE; /* polyspace RTE:IDP */
	}
    else if(((eDmaErrStatus >> DMA_ES_DAE_SHIFT) & 0x01U) == 1U)
	{
        chnState->status = EDMA_CHN_STATUS_ERR_DAE; /* polyspace RTE:IDP */
	}
    else if(((eDmaErrStatus >> DMA_ES_DOE_SHIFT) & 0x01U) == 1U)
	{
        chnState->status = EDMA_CHN_STATUS_ERR_DOE; /* polyspace RTE:IDP */
	}
    else if(((eDmaErrStatus >> DMA_ES_NCE_SHIFT) & 0x01U) == 1U)
	{
        chnState->status = EDMA_CHN_STATUS_ERR_NCE; /* polyspace RTE:IDP */
	}
    else if(((eDmaErrStatus >> DMA_ES_SGE_SHIFT) & 0x01U) == 1U)
	{
        chnState->status = EDMA_CHN_STATUS_ERR_SGE; /* polyspace RTE:IDP */
	}
    else if(((eDmaErrStatus >> DMA_ES_SBE_SHIFT) & 0x01U) == 1U)
	{
        chnState->status = EDMA_CHN_STATUS_ERR_SBE; /* polyspace RTE:IDP */
	}
    else if(((eDmaErrStatus >> DMA_ES_DBE_SHIFT) & 0x01U) == 1U)
	{
        chnState->status = EDMA_CHN_STATUS_ERR_DBE; /* polyspace RTE:IDP */
	}
    else 
    {
        /*Nothing todo*/
    }

    return chnState->status; /* polyspace RTE:NIV,IDP */
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_ClearErrStatus \
( \
    VAR(uint8, AUTOMATIC) mappedChannel \
)
{
    VAR(uint8, AUTOMATIC) edma_instance = (uint8)EDMA_MCH_TO_INSTANCE(mappedChannel);
    VAR(uint8, AUTOMATIC) edma_channel = (uint8)EDMA_MCH_TO_CH(mappedChannel);

    EDMA_HW_ClearIntStatus(mappedChannel);
    EDMA_HW_ClearChnErrorIntFlag((eDMAIstanceNumType)edma_instance, edma_channel);

}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#if EDMA_CH0_CH127_ERROR_INT
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch0_Ch127_Error_IRQHandler(void)
{
    VAR(uint8, AUTOMATIC) mappedChannel = 0U;
    VAR(eDMAErrorRegisterType, AUTOMATIC) errStatus;

    EDMA_HW_GetChnErrorIntFlag(EDMA_INSTANCE_0, &errStatus);

    if (0U != (errStatus.errl))
    {
        for (mappedChannel  = 0U; mappedChannel <= 31U; mappedChannel++)
        {
            if ((errStatus.errl & 1U) != 0U)
            {
                (void)EDMA_LLD_ClearChannelRequest(mappedChannel);
                EDMA_LLD_ErrorIRQHandler(mappedChannel);
                (void)EDMA_LLD_SetChannelRequest(mappedChannel);
            }

            errStatus.errl = errStatus.errl >> 1U;
        }
    }

    if (0U != (errStatus.errh))
    {
        for (mappedChannel  = 32U; mappedChannel <= 63U; mappedChannel++)
        {
            if ((errStatus.errh & 1U) != 0U)
            {
                (void)EDMA_LLD_ClearChannelRequest(mappedChannel);
                EDMA_LLD_ErrorIRQHandler(mappedChannel);
                (void)EDMA_LLD_SetChannelRequest(mappedChannel);
            }

            errStatus.errh = errStatus.errh >> 1U;
        }
    }

    errStatus.errl = 0U;
    errStatus.errh = 0U;

    EDMA_HW_GetChnErrorIntFlag(EDMA_INSTANCE_1, &errStatus);

    if (0U != (errStatus.errl))
    {
        for (mappedChannel  = 64U; mappedChannel <= 95U; mappedChannel++)
        {
            if ((errStatus.errl & 1U) != 0U)
            {
                (void)EDMA_LLD_ClearChannelRequest(mappedChannel);
                EDMA_LLD_ErrorIRQHandler(mappedChannel);
                (void)EDMA_LLD_SetChannelRequest(mappedChannel);
            }

            errStatus.errl = errStatus.errl >> 1U;
        }
    }

    if (0U != (errStatus.errh))
    {
        for (mappedChannel  = 96U; mappedChannel <= 127U; mappedChannel++)
        {
            if ((errStatus.errh & 1U) != 0U)
            {
                (void)EDMA_LLD_ClearChannelRequest(mappedChannel);
                EDMA_LLD_ErrorIRQHandler(mappedChannel);
                (void)EDMA_LLD_SetChannelRequest(mappedChannel);
            }

            errStatus.errh = errStatus.errh >> 1U;
        }
    }
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#endif

#ifdef __cplusplus
}
#endif

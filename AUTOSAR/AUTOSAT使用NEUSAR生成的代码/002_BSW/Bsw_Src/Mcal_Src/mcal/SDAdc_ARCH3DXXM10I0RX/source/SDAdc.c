/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     SDAdc.c
* @version  3.0.0
* @date     2024 - 02 - 28
* @brief    Initial version.
*
*****************************************************************************/
/* PRQA S 3604,2844,0704,1880,0492,2053,1258,0380,0686,3432,1006,0491,3226,2983,1759,1599 EOF*/
/* PRQA S 4391, 4399,4521,2834 EOF*/ 
#ifdef __cplusplus
extern "C"{
#endif

#include "SDAdc.h"
#include "SDAdc_LLDriver.h"
#include "eDma.h"
#ifdef RESOURCE_SUPPORT_SDADC_IP

#define SDADC_C_VENDOR_ID                     176
#define SDADC_C_AR_REL_MAJOR_VER              4
#define SDADC_C_AR_REL_MINOR_VER              4
#define SDADC_C_AR_REL_REV_VER                0
#define SDADC_C_SW_MAJOR_VER                  3
#define SDADC_C_SW_MINOR_VER                  0
#define SDADC_C_SW_PATCH_VER                  0

#if (SDADC_CFG_H_VENDOR_ID               != SDADC_C_VENDOR_ID)
    #error " NON-MATCHED DATA : SDADC_C_VENDOR_ID "
#endif
#if (SDADC_CFG_H_AR_REL_MAJOR_VER    != SDADC_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_C_AR_REL_MAJOR_VER "
#endif
#if (SDADC_CFG_H_AR_REL_MINOR_VER    != SDADC_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_C_AR_REL_MINOR_VER "
#endif
#if (SDADC_CFG_H_AR_REL_REV_VER != SDADC_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : SDADC_C_AR_REL_REV_VER "
#endif
#if (SDADC_CFG_H_SW_MAJOR_VER        != SDADC_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_C_SW_MAJOR_VER "
#endif
#if (SDADC_CFG_H_SW_MINOR_VER        != SDADC_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_C_SW_MINOR_VER "
#endif
#if (SDADC_CFG_H_SW_PATCH_VER        != SDADC_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SDADC_C_SW_PATCH_VER "
#endif

#if (STD_ON == SDADC_DEV_ERROR_DETECT)
#include "Det.h"
#endif

#define SDADC_START_SEC_VAR_INIT
#include "SDAdc_MemMap.h"
P2CONST(SdAdc_TotalConfigType, SDADC_CONST, SDADC_APPL_CONST) sdAdc_ConfigPtr[SDADC_CORE_NUM] = {NULL_PTR};
#define SDADC_STOP_SEC_VAR_INIT
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_VAR_INIT
#include "SDAdc_MemMap.h"
static VAR(Sdadc_InitStateType, SDADC_VAR) Sdadc_InitState[SDADC_CORE_NUM] = {SDADC_UNINIT};
#define SDADC_STOP_SEC_VAR_INIT
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_VAR_NO_INIT
#include "SDAdc_MemMap.h"
VAR(Sdadc_ChannelDataType, SDADC_VAR) Sdadc_ChannelData[SDADC_INSTANCE_CDG_NUM][SDADC_CORE_NUM];
#define SDADC_STOP_SEC_VAR_NO_INIT
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CONFIG_DATA
#include "SDAdc_MemMap.h"
CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) Adc_SdadcBase0[SDADC_MAX_INSTANCE] = SDADC_BASE_PTR_ARRAY;
#define SDADC_STOP_SEC_CONFIG_DATA
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_VAR_INIT
#include "SDAdc_MemMap.h"
VAR(Sdadc_ChannelType, SDADC_VAR) SDAdc_gIrqMapping[SDADC_MAX_INSTANCE][SDADC_CORE_NUM] = {{0}};
#define SDADC_STOP_SEC_VAR_INIT
#include "SDAdc_MemMap.h"

#if (STD_ON == SDADC_DEV_ERROR_DETECT)
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) Sdadc_ReportError \
( \
    VAR(uint8, AUTOMATIC) u8Sdadc_ApiId, \
    VAR(uint8, AUTOMATIC) u8Sdadc_ErrorId \
);
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) Sdadc_ReportError \
( \
    VAR(uint8, AUTOMATIC) u8Sdadc_ApiId, \
    VAR(uint8, AUTOMATIC) u8Sdadc_ErrorId \
)
{
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    (void)Det_ReportError((uint16)SDADC_MODULE_ID, (uint8)0U, u8Sdadc_ApiId, u8Sdadc_ErrorId);
#else
    (void)u8Sdadc_ApiId;
    (void)u8Sdadc_ErrorId;
#endif
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#if (SDADC_ENABLE_MULTICORE == STD_ON)
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(uint8, ADC_VAR) Sdadc_CoreVerify(VAR(Sdadc_ChannelType, AUTOMATIC) ChannelId)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    VAR(uint8, AUTOMATIC) CurrentCoreId = (1U << u32Sdadc_ICoreId);
    VAR(uint8, AUTOMATIC) u8Sdadc_Coreflag = 0U; 

    u8Sdadc_Coreflag = (uint32)((CurrentCoreId) & (sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_CoreMapItem[ChannelId].SdAdc_CoreId));
	return u8Sdadc_Coreflag;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"
#endif
#endif


#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(void, SDADC_CODE) Sdadc_Init(CONSTP2CONST(SdAdc_TotalConfigType, SDADC_CONST, SDADC_APPL_CONST) ConfigPtr)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)
    {
        return;
    } 
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_INITED)
    {
        Sdadc_ReportError(SDADC_SID_INIT, (uint8)SDADC_E_ALREADY_INITIALIZED);
    }
#if (SDADC_PRECOMPILE_SUPPORT == STD_ON)
    else if(ConfigPtr != NULL_PTR)
#else
    else if(ConfigPtr == NULL_PTR)
#endif
    {
        Sdadc_ReportError(SDADC_SID_INIT, (uint8)SDADC_E_PARAM_CONFIG);
    }
    else
    {
#endif

#if (SDADC_PRECOMPILE_SUPPORT == STD_ON)
    sdAdc_ConfigPtr[u32Sdadc_ICoreId] = &SdAdc_TotalConfig;
    (void)ConfigPtr;
#else
    sdAdc_ConfigPtr[u32Sdadc_ICoreId] = ConfigPtr;
#endif
        
        for(uint8 u8sdadc_ChIndex = 0U; u8sdadc_ChIndex < SDADC_INSTANCE_CDG_NUM; u8sdadc_ChIndex++)
        {
#if (SDADC_ENABLE_MULTICORE == STD_ON)
            VAR(uint8, AUTOMATIC) CurrentCoreId = SDAdc_GetCoreID();  /*Get Core ID */
            if(((CurrentCoreId) & (sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_CoreMapItem[u8sdadc_ChIndex].SdAdc_CoreId)) != 0U)
            {
#endif
                SDADC_LLD_Init( \
                    sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_InstanceId, /* polyspace RTE:IDP,NIV */
                    sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_Config, /* polyspace RTE:NIP,NIV */
                    (uint16)sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_HwTrigSrc /* polyspace RTE:NIV */
                );
                Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelResBuffer = NULL_PTR;
                Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelStatus = SDADC_IDLE;
                Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NumofValidConRes = (Sdadc_SizeType)0U;
                Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelBufferSize = (Sdadc_SizeType)0U;
#if (SDADC_ENABLE_MULTICORE == STD_ON)
            }
#endif
        }
        Sdadc_InitState[u32Sdadc_ICoreId] = SDADC_INITED;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(void, SDADC_CODE) Sdadc_DeInit(void)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)
    {
        return;
    }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_DEINIT, (uint8)SDADC_E_UNINIT);
    }
    else
    {
#endif
        for(uint8 u8sdadc_ChIndex = 0U; u8sdadc_ChIndex < SDADC_INSTANCE_CDG_NUM; u8sdadc_ChIndex++)
        {
#if (SDADC_ENABLE_MULTICORE == STD_ON)
            VAR(uint8, AUTOMATIC) CurrentCoreId = SDAdc_GetCoreID(); /*Get Core ID*/
            if(((CurrentCoreId) & (sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_CoreMapItem[u8sdadc_ChIndex].SdAdc_CoreId)) != 0U)
            {
#endif
            SDADC_LLD_DeInit(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_InstanceId);    /* polyspace RTE:NIV,IDP */
            Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelResBuffer = NULL_PTR;
            Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelStatus = SDADC_IDLE;
            Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NumofValidConRes = (Sdadc_SizeType)0U;
            Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelBufferSize = (Sdadc_SizeType)0U;
#if (SDADC_ENABLE_MULTICORE == STD_ON)
            }
#endif
        }
        sdAdc_ConfigPtr[u32Sdadc_ICoreId] = NULL_PTR;
        Sdadc_InitState[u32Sdadc_ICoreId] = SDADC_UNINIT;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#ifdef RESOURCE_SUPPORT_GTM_TRIG_SDADC
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, ADC_CODE)GTM_TrigSDADC
( \
    CONST(uint8, ADC_CONST) u8sdAdc_GtmInstance, \
    CONST(uint8, ADC_CONST) u8sdAdc_trigregidx, \
    CONST(uint8, ADC_CONST) u8sdAdc_TrigRegMemberIdx, \
    CONST(uint8, ADC_CONST) u8sdAdc_GTM_ADC_TRIG_OUTSEL\
)
{
    GTM4.GLS[u8sdAdc_GtmInstance].GTMINT.GTMMCR.R &= ~0x40000000UL; /* GTM Module Enable */

    if (u8sdAdc_TrigRegMemberIdx < 8u)  /* TrigRegMemberIdx: 0 ~ 7 */
    {
        GTM4.GLS[u8sdAdc_GtmInstance].DSADC[u8sdAdc_trigregidx].OUTSEL0.R &= ~(uint32_t)(GTM_SDADC_TRIG_OUTSEL_MASK << (u8sdAdc_TrigRegMemberIdx * 4u));/* polyspace RTE:OBAI */
        GTM4.GLS[u8sdAdc_GtmInstance].DSADC[u8sdAdc_trigregidx].OUTSEL0.R |= (uint32_t)((u8sdAdc_GTM_ADC_TRIG_OUTSEL & GTM_SDADC_TRIG_OUTSEL_MASK) << (u8sdAdc_TrigRegMemberIdx * 4u));
    }
    else    /* TrigRegMemberIdx: 8 ~ 11 */
    {
        GTM4.GLS[u8sdAdc_GtmInstance].DSADC[u8sdAdc_trigregidx].OUTSEL1.R &= ~(uint32_t)(GTM_SDADC_TRIG_OUTSEL_MASK << ((u8sdAdc_TrigRegMemberIdx - 8u) * 4u));/* polyspace RTE:OBAI */
        GTM4.GLS[u8sdAdc_GtmInstance].DSADC[u8sdAdc_trigregidx].OUTSEL1.R |= (uint32_t)((u8sdAdc_GTM_ADC_TRIG_OUTSEL & GTM_SDADC_TRIG_OUTSEL_MASK) << ((u8sdAdc_TrigRegMemberIdx - 8u) * 4u));
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"
#endif

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_StartModulation(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId)
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)/* polyspace RTE:NIV,IDP */
    {
        return RetVal = (Std_ReturnType)E_NOT_OK;
    }
#ifdef RESOURCE_SUPPORT_SIUL2_IP
    VAR(uint32, SDADC_VAR) Sdadc_HwTrigSrcAddr[] =
    {
        0x00U,
        0x01U,
        0x02U,
        0x03U,
        0x04U,
        0x05U,
        0x0cU,
        0x0dU,
        0x0eU,
        0x0fU,
        0x10U,
        0x11U,
        0x12U,
        0x13U,
        0x14U,
        0x15U,
        0x16U,
        0x17U,
        0x18U,
        0x19U,
        0x1aU,
        0x1bU,
        0x1cU,
        0x1dU,
        0x1eU,
        0x1fU,
        0x40U,
        0x40U,
        0x40U,
        0x40U,
        0x40U,
        0x40U,
        0x07U,
        0x07U,
        0x60U,
        0x60U,
        0x06U, 
        0x06U,
        0x06U,
        0x20U,
        0x20U,
        0x08U,
        0x09U,
        0x10U,
        0x11U,
        0x12U,
        0x13U,
        0x14U,
        0x15U,   
    };
#endif

#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_START_MODULATION, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= SDADC_INSTANCE_CDG_NUM)
    {
        Sdadc_ReportError(SDADC_SID_START_MODULATION, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_START_MODULATION, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
        if((Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelBufferSize != 0U) || (Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelResBuffer != NULL_PTR))    /* polyspace RTE:OBAI */
        {
            VAR(uint32, SDADC_VAR) WaterMarkerValue = 0U;
            VAR(uint32, SDADC_VAR) major_loop_time, minor_transfer_byte = 0U;
            VAR(Std_ReturnType, SDADC_VAR) DmaRet = (Std_ReturnType)E_NOT_OK;
            CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase0[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId];      /* polyspace RTE:NIV,IDP,OBAI */
            WaterMarkerValue = BasePtr->FCFG.B.FIFOWM;    /* polyspace RTE:NIV,IDP */
            if(Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelBufferSize < (uint16)WaterMarkerValue)
            {
                BasePtr->FCFG.B.FIFOWM = (uint8)Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelBufferSize;
                WaterMarkerValue = BasePtr->FCFG.B.FIFOWM;
            }

            if(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_ConvMethod == SDADC_USE_INTERRUPT)    /* polyspace RTE:NIV,IDP */
            {
                SDAdc_gIrqMapping[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId][u32Sdadc_ICoreId] = ChannelId; /* polyspace RTE:OBAI,NIV*/ 
                Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus = SDADC_BUSY;
            }
            else if(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_ConvMethod == SDADC_USE_DMA)
            {
                minor_transfer_byte = WaterMarkerValue * sizeof(uint32);
                major_loop_time= (uint32)(Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelBufferSize) / WaterMarkerValue;/* polyspace RTE:ZDV */

                VAR(eDMALoopTransferConfigType, SDADC_VAR) sdadcLoopConfig =
                {
                    .dstAddrOffsetEn    = TRUE,
                    .srcAddrOffsetEn    = FALSE,
                    .minorLpOffset      = 0,
                    .minorLpLinkEn      = FALSE,
                    .minorLpLinkChn     = 0U,
                    .majorLpLinkEn      = FALSE,
                    .majorLpLinkChn     = 0U,
                    .majorLpIterCnt     = major_loop_time
                };

                VAR(eDMATransferConfigType, SDADC_VAR) dmaConfigforsdadc =
                {
                    .srcAddr = (uint32)(&BasePtr->FDATA.R), /* Modified by function */
                    .destAddr = (uint32)Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelResBuffer, /* Modified by function */
                    .srcTransDataSize = EDMA_TRANSFER_SIZE_4B,
                    .destTransDataSize = EDMA_TRANSFER_SIZE_4B,
                    .srcAddrOffset = (sint16)0,
                    .destAddrOffset = (sint16)sizeof(uint32),
                    .srcAddrAdjustLast = 0,
                    .destAddrAdjustLast = -((sint32)major_loop_time * (sint32)minor_transfer_byte), /* Modified by function */
                    .srcAddrModulo = EDMA_ADDRESS_MODULO_OFF,
                    .destAddrModulo = EDMA_ADDRESS_MODULO_OFF,
                    .minorTransByte = minor_transfer_byte, /* Modified by function */
                    .featureScatterGatherEn = FALSE,
                    .featureScatterGatherNextDescriptor = 0U,
                    .completeIntEn = TRUE,
                    .lpTransConfigPtr = &sdadcLoopConfig,
                };
                DmaRet = EDMA_SetLoopTransferConfig(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_Config->DmaCfg.DmaCh, &dmaConfigforsdadc);    /* polyspace RTE:NIV,NIP,IDP */
                if(DmaRet == (Std_ReturnType)E_OK)
                {
                    EDMA_SetChnDisRequestsOnTransferComplete \
                    (
                        sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_Config->DmaCfg.DmaCh, /* polyspace RTE:NIV,NIP,IDP */
                        sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_Config->DmaCfg.DreqEn     /* polyspace RTE:NIV */
                    );
                    DmaRet = EDMA_SetChannelRequest(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_Config->DmaCfg.DmaCh);
                    if(DmaRet == (Std_ReturnType)E_OK)
                    {
                        Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NumofValidConRes = Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelBufferSize;
                        Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus = SDADC_RESULT_READY;
                    }
                }
            }
            else
            {
                Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus = SDADC_BUSY;
            }
            
            SDADC_LLD_ModuleEnable(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId); /* polyspace RTE:NIV,IDP */
            if(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_SwOrHw == (uint8)SOFTWARE_TRIG)     /* polyspace RTE:NIV */
            {
                SDADC_LLD_SetSoftTrigger(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId);
            }
            else
            {
#ifdef RESOURCE_SUPPORT_SIUL2_IP
                if(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigRegId == SDADC_TRIGREG_DISABLE) /* polyspace RTE:NIV */
                {
#endif
#ifdef RESOURCE_SUPPORT_GTM_TRIG_SDADC
                    if((sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigSrc >= HWTRIGSEL_GTM_TRIG0_BIT0)/* polyspace RTE:NIV */
                        && (sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigSrc <= HWTRIGSEL_GTM_TRIG3_BIT13))
                    {
                        VAR(uint8, ADC_VAR) u8sdadc_trigregidx = 0U;
                        VAR(uint8, ADC_VAR) u8sdadc_TrigRegMemberIdx = 0U;
                        u8sdadc_trigregidx = (uint8)(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigSrc) / GTM_SDADC_TRIG_MEMBER_NUM;
                        u8sdadc_TrigRegMemberIdx =(uint8)(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigSrc) % GTM_SDADC_TRIG_MEMBER_NUM;
                        GTM_TrigSDADC(0U,u8sdadc_trigregidx,u8sdadc_TrigRegMemberIdx,sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_GtmTrigOutsel);/* polyspace RTE:NIV */
                    }
#endif
#ifdef RESOURCE_SUPPORT_SIUL2_IP
                }
                else
                {
                    switch(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigRegId)
                    {
                        case SDADC_TRIGREG_HW5:
                            SIUL2.ISEL9.B.EETSEL0ADV_A = Sdadc_HwTrigSrcAddr[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigChID];     /* polyspace RTE:NIV,OBAI */
                            break;
                        case SDADC_TRIGREG_HW9:
                            SIUL2.ISEL5.B.CTSEL0_A = Sdadc_HwTrigSrcAddr[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigChID];     /* polyspace RTE:NIV,OBAI */
                            break;
                        case SDADC_TRIGREG_HW11:
                            SIUL2.ISEL5.B.CTSEL1_A = Sdadc_HwTrigSrcAddr[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigChID];     /* polyspace RTE:NIV,OBAI */
                            break;
                        case SDADC_TRIGREG_HW12:
                            SIUL2.ISEL4.B.CTSEL2_A = Sdadc_HwTrigSrcAddr[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigChID];     /* polyspace RTE:NIV,OBAI */
                            break;
                        case SDADC_TRIGREG_HW13:
                            SIUL2.ISEL4.B.CTSEL3_A = Sdadc_HwTrigSrcAddr[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigChID];     /* polyspace RTE:NIV,OBAI */
                            break;
                        case SDADC_TRIGREG_HW14:
                            SIUL2.ISEL4.B.CTSEL4_A = Sdadc_HwTrigSrcAddr[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigChID];     /* polyspace RTE:NIV,OBAI */
                            break;
                        case SDADC_TRIGREG_HW15:
                            SIUL2.ISEL4.B.CTSEL5_A = Sdadc_HwTrigSrcAddr[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigChID];     /* polyspace RTE:NIV,OBAI */
                            break;
                        default:
                            /*Nothing to do*/
                            break;
                    }
                }
#endif               
            }
            RetVal = (Std_ReturnType)E_OK;
        }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_StopModulation(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId)
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)/* polyspace RTE:NIV,IDP */
    {
        return RetVal = (Std_ReturnType)E_NOT_OK;
    }
    
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_STOP_MODULATION, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= SDADC_INSTANCE_CDG_NUM)
    {
        Sdadc_ReportError(SDADC_SID_STOP_MODULATION, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_STOP_MODULATION, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
        CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase0[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId];     /* polyspace RTE:NIV,IDP,OBAI */
        if(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_ConvMethod == SDADC_USE_INTERRUPT)    /* polyspace RTE:NIV */
        {
            SDADC_IECFG_SetFifoWaterMarkerIntEnDis(BasePtr, FALSE);
        }
        SDADC_LLD_ResetFifo(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId);/* polyspace RTE:IDP,NIV */
        SDADC_LLD_ModuleDisable(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId);
        Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus = SDADC_IDLE;    /* polyspace RTE:OBAI */
        SDAdc_gIrqMapping[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId][u32Sdadc_ICoreId] = 0U;/* polyspace RTE:OBAI */
        RetVal = (Std_ReturnType)E_OK;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(Sdadc_SizeType, SDADC_CODE) Sdadc_ReadStreamResults \
(
    CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId, \
    CONSTP2VAR(Sdadc_ResultType, SDADC_CONST, SDADC_APPL_CONST) ResultLinearBufferPtr \
)
{
    VAR(Sdadc_SizeType, SDADC_VAR) u16sdadc_Size = SDADC_READSTREAM_ERROR;
    VAR(Sdadc_SizeType, SDADC_VAR) u16sdadc_BufferCount;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)
    {
        return u16sdadc_Size = SDADC_READSTREAM_ERROR;
    }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_READ_STREAM_RESULTS, (uint8)SDADC_E_UNINIT);
    }
    else if(NULL_PTR == ResultLinearBufferPtr)
    {
        Sdadc_ReportError(SDADC_SID_READ_STREAM_RESULTS, (uint8)SDADC_E_PARAM_POINTER);
    }
    else if(ChannelId >= SDADC_INSTANCE_CDG_NUM)
    {
        Sdadc_ReportError(SDADC_SID_READ_STREAM_RESULTS, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_READ_STREAM_RESULTS, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
        if(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_BufferMode == SDADC_STREAM_LINEAR_BUFFER)    /* polyspace RTE:NIV,IDP */
        {
            if(Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus == SDADC_RESULT_READY)    /* polyspace RTE:OBAI */
            {
                u16sdadc_Size = Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NumofValidConRes;
                Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NumofValidConRes = (Sdadc_SizeType)0U;
                Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus = SDADC_BUSY;
                for(u16sdadc_BufferCount = 0U; u16sdadc_BufferCount < u16sdadc_Size; u16sdadc_BufferCount++)
                {
                    ResultLinearBufferPtr[u16sdadc_BufferCount] = (Sdadc_ResultType)Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelResBuffer[u16sdadc_BufferCount];    /* polyspace RTE:NIV,OVFL,IDP */
                }
            }
        }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
        else
        {
            Sdadc_ReportError(SDADC_SID_READ_STREAM_RESULTS, (uint8)SDADC_E_INV_LINEAR_BUFFER_CONFIG);
        }
    }
#endif
    return u16sdadc_Size;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_ReadResult \
(
    CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId, \
    CONSTP2VAR(Sdadc_ResultType, SDADC_CONST, SDADC_APPL_CONST) ResultPtr \
)
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)
    {
        return RetVal = (Std_ReturnType)E_NOT_OK;
    }
    VAR(uint32, AUTOMATIC) u32Sdadc_Result = 0U;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_READ_RESULT, (uint8)SDADC_E_UNINIT);
    }
    else if(NULL_PTR == ResultPtr)
    {
        Sdadc_ReportError(SDADC_SID_READ_RESULT, (uint8)SDADC_E_PARAM_POINTER);
    }
    else if(ChannelId >= SDADC_INSTANCE_CDG_NUM)
    {
        Sdadc_ReportError(SDADC_SID_READ_RESULT, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_READ_RESULT, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
        if(Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus == SDADC_RESULT_READY)    /* polyspace RTE:OBAI */
		{
        	if(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_BufferMode == SDADC_STREAM_LINEAR_BUFFER)    /* polyspace RTE:NIV,IDP */
			{
                u32Sdadc_Result = (SDADC_LLD_GetFifoData(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId) & 0xFFFFU);    /* polyspace RTE:NIV */
                *ResultPtr = (Sdadc_ResultType)u32Sdadc_Result; /* polyspace RTE:OVFL */
				Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus = SDADC_BUSY;
			}
        	else
        	{
                 *ResultPtr = (Sdadc_ResultType)Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelResBuffer[Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NumofValidConRes];    /* polyspace RTE:NIV,OVFL,IDP*/
        	}
        	RetVal = (Std_ReturnType)E_OK;
        }
      
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(Sdadc_ChannelStatusType, SDADC_CODE) Sdadc_GetStatus(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId)
{
    VAR(Sdadc_ChannelstatusType, SDADC_VAR) RetVal = SDADC_IDLE;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)
    {
        return RetVal = (Std_ReturnType)E_NOT_OK;
    }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_GET_STATUS, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= SDADC_INSTANCE_CDG_NUM)
    {
        Sdadc_ReportError(SDADC_SID_GET_STATUS, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_GET_STATUS, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
        RetVal = Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus;    /* polyspace RTE:OBAI */
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_SetupResultBuffer \
(
    CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId,\
	P2VAR(uint32, SDADC_VAR, SDADC_APPL_CONST) DataBufferPtr, \
    CONST(Sdadc_SizeType, SDADC_CONST) Size \
)
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)
    {
        return RetVal = (Std_ReturnType)E_NOT_OK;
    }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_SETUP_RESULT_BUFFER, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= SDADC_INSTANCE_CDG_NUM)
    {
        Sdadc_ReportError(SDADC_SID_SETUP_RESULT_BUFFER, (uint8)SDADC_E_PARAM_CHANNEL);
    }
    else if(DataBufferPtr == NULL_PTR)
    {
        Sdadc_ReportError(SDADC_SID_SETUP_RESULT_BUFFER, (uint8)SDADC_E_PARAM_POINTER);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_SETUP_RESULT_BUFFER, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
        if(Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus == SDADC_IDLE)    /* polyspace RTE:OBAI */
        {
            if((Size != (Sdadc_SizeType)0U) && (Size <= (Sdadc_SizeType)SDADC_MAX_BUFFER_LENGTH))
            {
                Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelResBuffer = DataBufferPtr;
                Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelBufferSize = Size;
                Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NumofValidConRes = 0x0U;
                RetVal = (Std_ReturnType)E_OK;
            }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
            else
            {
                Sdadc_ReportError(SDADC_SID_SETUP_RESULT_BUFFER, (uint8)SDADC_E_INV_BUFFER_SIZE);
            }
#endif
        }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
        else
        {
            Sdadc_ReportError(SDADC_SID_SETUP_RESULT_BUFFER, (uint8)SDADC_E_UNIDLE);
        }
    }
#endif
    return RetVal;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_StartCarrierSignal(void) //not supported
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)
    {
        return RetVal = (Std_ReturnType)E_NOT_OK;
    }
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_START_CARRIER_SIGNAL, (uint8)SDADC_E_UNINIT);
    }
    else
    {
#endif
        //chip not support
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_StopCarrierSignal(void) //not supported
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)
    {
        return RetVal = (Std_ReturnType)E_NOT_OK;
    }
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_STOP_CARRIER_SIGNAL, (uint8)SDADC_E_UNINIT);
    }
    else
    {
#endif
        //chip not support
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(void, SDADC_CODE) Sdadc_EnableNotifications(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)
    {
        return;
    }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_ENABLE_NOTIFICATIONS, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= SDADC_INSTANCE_CDG_NUM)
    {
        Sdadc_ReportError(SDADC_SID_ENABLE_NOTIFICATIONS, (uint8)SDADC_E_PARAM_CHANNEL);
    }
    else if((sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_NewResultNotify == NULL_PTR)    /* polyspace RTE:NIP,IDP */
        && (sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_BufferFullNotifyPtr == NULL_PTR))    /* polyspace RTE:NIP,IDP */
    {
        Sdadc_ReportError(SDADC_SID_ENABLE_NOTIFICATIONS, (uint8)SDADC_E_NOTIF_CAPABILITY);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_ENABLE_NOTIFICATIONS, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
        Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NotifyStatus = TRUE;    /* polyspace RTE:OBAI */
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(void, SDADC_CODE) Sdadc_DisableNotifications(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)
    {
        return;
    }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_DISABLE_NOTIFICATIONS, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= SDADC_INSTANCE_CDG_NUM)
    {
        Sdadc_ReportError(SDADC_SID_DISABLE_NOTIFICATIONS, (uint8)SDADC_E_PARAM_CHANNEL);
    }
    else if((sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_NewResultNotify == NULL_PTR)    /* polyspace RTE:NIP,IDP */
        && (sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_BufferFullNotifyPtr == NULL_PTR))    /* polyspace RTE:NIP,IDP */
    {
        Sdadc_ReportError(SDADC_SID_DISABLE_NOTIFICATIONS, (uint8)SDADC_E_NOTIF_CAPABILITY);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_DISABLE_NOTIFICATIONS, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
        Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NotifyStatus = FALSE;    /* polyspace RTE:OBAI */
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(Sdadc_TimeStampType, SDADC_CODE) Sdadc_GetTimestamp(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId) //not supported
{
    VAR(Sdadc_TimeStampType, SDADC_VAR) RetVal = 0;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)
    {
        return RetVal = (Sdadc_TimeStampType)E_NOT_OK;
    }
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_GET_TIMESTAMP, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= SDADC_INSTANCE_CDG_NUM)
    {
        Sdadc_ReportError(SDADC_SID_GET_TIMESTAMP, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_GET_TIMESTAMP, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#else
    (void)ChannelId;
#endif
        //chip not support
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_StartCalibration(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId)
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)/* polyspace RTE:NIV,IDP */
    {
        return RetVal = (Std_ReturnType)E_NOT_OK;
    }
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase0[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId];    /* polyspace RTE:NIV,IDP,OBAI */
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_START_CALIBRATION, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= SDADC_INSTANCE_CDG_NUM)
    {
        Sdadc_ReportError(SDADC_SID_START_CALIBRATION, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_START_CALIBRATION, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
    if(Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus == SDADC_IDLE)    /* polyspace RTE:OBAI */
    {
        SDADC_FCFGM_SetCalibEnDis(BasePtr, TRUE);
        RetVal = (Std_ReturnType)E_OK;
    }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(Sdadc_CalibrationStatusType, SDADC_CODE) Sdadc_GetCalibrationStatus(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId) //not supported
{
    VAR(Sdadc_CalibrationStatusType, SDADC_VAR) RetVal = 0U;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)
    {
        return RetVal = (Sdadc_CalibrationStatusType)E_NOT_OK;
    }
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_GET_CALIBRATION_STATUS, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= SDADC_INSTANCE_CDG_NUM)
    {
        Sdadc_ReportError(SDADC_SID_GET_CALIBRATION_STATUS, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_GET_CALIBRATION_STATUS, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#else
    (void)ChannelId;
#endif
    
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_InitCheck(CONSTP2CONST(SdAdc_TotalConfigType, SDADC_CONST, SDADC_APPL_CONST) ConfigPtr)
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)
    {
        return RetVal = (Std_ReturnType)E_NOT_OK;
    }
    if((ConfigPtr == NULL_PTR) || (Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT))
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        RetVal = (Std_ReturnType)E_OK;
    }
    return RetVal;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(void, SDADC_CODE) Sdadc_GetVersionInfo(CONSTP2VAR(Std_VersionInfoType, SDADC_CONST, SDADC_APPL_CONST) versioninfo)
{
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
	VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)
    {
        return;
    }
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_GET_VERSION_INFO, (uint8)SDADC_E_UNINIT);
    }
    else if(versioninfo == NULL_PTR)
    {
        Sdadc_ReportError(SDADC_SID_GET_VERSION_INFO, (uint8)SDADC_E_PARAM_POINTER);
    }
    else
    {
#endif
        versioninfo->moduleID = (uint16)SDADC_MODULE_ID;
        versioninfo->vendorID = (uint16)SDADC_CFG_H_VENDOR_ID;
        versioninfo->sw_major_version = (uint8)SDADC_CFG_H_SW_MAJOR_VER;
        versioninfo->sw_minor_version = (uint8)SDADC_CFG_H_SW_MINOR_VER;
        versioninfo->sw_patch_version = (uint8)SDADC_CFG_H_SW_PATCH_VER;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_RestartDemodulator(CONST(Sdadc_ChannelMaskType, SDADC_CONST) ChannelId) //not supported
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
    (void)ChannelId;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)
    {
        return RetVal = (Std_ReturnType)E_NOT_OK;
    }
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_RESTART_DEMODULATOR, (uint8)SDADC_E_UNINIT);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify((Sdadc_ChannelType)ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_RESTART_DEMODULATOR, SDADC_E_PARAM_ERROR);
    }
#endif /* (SDADC_ENABLE_MULTICORE == STD_ON) */
    else
    {
#endif /* (STD_ON == SDADC_DEV_ERROR_DETECT) */
        RetVal = (Std_ReturnType)E_OK;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(Sdadc_IrmsValueType, SDADC_CODE) Sdadc_GetIrmsValue(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId) //not supported
{
    VAR(Sdadc_IrmsValueType, SDADC_VAR) RetVal = 0;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)
    {
        return RetVal = (Sdadc_IrmsValueType)E_NOT_OK;
    }
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_GET_IRMS_VALUE, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= SDADC_INSTANCE_CDG_NUM)
    {
        Sdadc_ReportError(SDADC_SID_GET_IRMS_VALUE, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_GET_IRMS_VALUE, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#else
    (void)ChannelId;
#endif
    
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_SetGainCorrRegValue \
(
    CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId, \
    CONST(Sdadc_GainCorrType, SDADC_CONST) RegValue \
)
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)/* polyspace RTE:NIV,IDP */
    {
        return RetVal = (Std_ReturnType)E_NOT_OK;
    }
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase0[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId];    /* polyspace RTE:NIV,IDP,OBAI */
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_SET_GAINCORR_REG_VALUE, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= SDADC_INSTANCE_CDG_NUM)
    {
        Sdadc_ReportError(SDADC_SID_SET_GAINCORR_REG_VALUE, (uint8)SDADC_E_PARAM_CHANNEL);
    }
    else if(RegValue > 0x1CU)
    {
        Sdadc_ReportError(SDADC_SID_SET_GAINCORR_REG_VALUE, (uint8)SDADC_E_PARAM_ERROR);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_SET_GAINCORR_REG_VALUE, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
        BasePtr->GAINCORR.B.CICSHIFT = RegValue; /* polyspace RTE:IDP */
        RetVal = (Std_ReturnType)E_OK;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_RestartIntegrator \
( \
    CONST(Sdadc_ChannelMaskType, SDADC_CONST) ChannelId, \
    CONST(Sdadc_DelayType, SDADC_CONST) Delay \
)
{
    VAR(uint32, SDADC_VAR) Instance_index = 0U;
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)/* polyspace RTE:NIV,IDP */
    {
        return RetVal = (Std_ReturnType)E_NOT_OK;
    }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    VAR(uint32, AUTOMATIC) u32Sdadc_Maxinstance = 0U;
    u32Sdadc_Maxinstance = ((uint32)1U << SDADC_MAX_INSTANCE);
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_RESTART_INTEGRATOR, (uint8)SDADC_E_UNINIT);
    }
    else if((ChannelId == 0U) || (ChannelId >= u32Sdadc_Maxinstance))
    {
        Sdadc_ReportError(SDADC_SID_RESTART_INTEGRATOR, (uint8)SDADC_E_PARAM_CHANNEL);
    }
    else
    {
#endif
        for(Instance_index = 0U; Instance_index < 16U; Instance_index++)
        {
            if(((uint32)((uint32)1U << Instance_index) & ChannelId) != 0U)
            {
#if (STD_ON == SDADC_DEV_ERROR_DETECT) && (SDADC_ENABLE_MULTICORE == STD_ON)
                if(Sdadc_CoreVerify((Sdadc_ChannelType)(Instance_index)) == 0U)
                {
                    Sdadc_ReportError(SDADC_SID_RESTART_INTEGRATOR, SDADC_E_PARAM_ERROR);
                }
                else
                {
#endif
                    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase0[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[Instance_index].Sdadc_InstanceId];    /* polyspace RTE:NIV,NIP,IDP,OBAI */
                    SDADC_DICFG_SetIntegratorTriggerMode(BasePtr, 0x0U);
#if (STD_ON == SDADC_DEV_ERROR_DETECT) && (SDADC_ENABLE_MULTICORE == STD_ON)
                }
#endif               
            }
        }
        for(uint32 i = 0; i < Delay; i++){}
        for(Instance_index = 0U; Instance_index < 16U; Instance_index++)
        {
        	if(((uint32)((uint32)1U << Instance_index) & ChannelId) != 0U)
            {
#if (STD_ON == SDADC_DEV_ERROR_DETECT) && (SDADC_ENABLE_MULTICORE == STD_ON)
                if(Sdadc_CoreVerify((Sdadc_ChannelType)(Instance_index)) == 0U)
                {
                    Sdadc_ReportError(SDADC_SID_RESTART_INTEGRATOR, SDADC_E_PARAM_ERROR);
                }
                else
                {
#endif
                    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase0[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[Instance_index].Sdadc_InstanceId];    /* polyspace RTE:NIV,IDP,OBAI */
                    SDADC_DICFG_SetIntegratorTriggerMode(BasePtr, (uint8)(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[Instance_index].Sdadc_Config->Integrator.IntegratorTrigMode));    /* polyspace RTE:NIV,IDP,NIP */
#if (STD_ON == SDADC_DEV_ERROR_DETECT) && (SDADC_ENABLE_MULTICORE == STD_ON)
                }
#endif
            }
        }
        RetVal = (Std_ReturnType)E_OK;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(Sdadc_SdcapValueType, SDADC_CODE) Sdadc_GetSdcapValue(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId) //not supported
{
    VAR(Sdadc_SdcapValueType, SDADC_VAR) RetVal = 0U;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)
    {
        return RetVal = (Sdadc_SdcapValueType)E_NOT_OK;
    }
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_GET_SDCAP_VALUE, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= SDADC_INSTANCE_CDG_NUM)
    {
        Sdadc_ReportError(SDADC_SID_GET_SDCAP_VALUE, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_GET_SDCAP_VALUE, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#else
    (void)ChannelId;
#endif
    
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(void, SDADC_CODE) Sdadc_MainFunction(void)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(u32Sdadc_ICoreId >= SDADC_CORE_NUM)
    {
        return;
    }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_MAIN_FUNCTION, (uint8)SDADC_E_UNINIT);
    }
    else
    {
#endif
        for(uint8 u8sdadc_ChIndex = 0U; u8sdadc_ChIndex < SDADC_INSTANCE_CDG_NUM; u8sdadc_ChIndex++)
        {
            VAR(Sdadc_InstanceType, SDADC_VAR) instance = sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_InstanceId;    /* polyspace RTE:NIV,IDP */
            if(instance >= SDADC_MAX_INSTANCE)
            {
                return;
            }
            VAR(uint32, SDADC_VAR) WaterMarkerValue = 0U;
            CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase0[instance];    /* polyspace RTE:NIV,OBAI */
            if((Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelStatus != SDADC_IDLE) && (sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_ConvMethod == SDADC_USE_POLLING))/* polyspace RTE:NIV */
            {
                if(SDADC_LLD_GetWaterMarkerIntState(instance) == TRUE)
                {
                	WaterMarkerValue = BasePtr->FCFG.B.FIFOWM;    /* polyspace RTE:NIV,IDP */
                	if(Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NumofValidConRes < Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelBufferSize)
                	{
                		for(uint32 i = 0U; i < WaterMarkerValue; i++)
						{
							Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelResBuffer[Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NumofValidConRes] = (SDADC_LLD_GetFifoData(instance) & 0xFFFFU);     /* polyspace RTE:IDP */
							Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NumofValidConRes++;
							if((Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NotifyStatus == TRUE)
															&& (sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_NewResultNotify != NULL_PTR))    /* polyspace RTE:NIP,IDP */
							{
								sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_NewResultNotify(); /* polyspace RTE:COR,NIP,IDP */
							}
						}
                		SDADC_LLD_ClearWaterMarkerIntState(instance);
						if((Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelBufferSize - Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NumofValidConRes) < (uint16)WaterMarkerValue)
						{
							BasePtr->FCFG.B.FIFOWM = (uint8)(Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelBufferSize - Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NumofValidConRes);
						}

						Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelStatus = SDADC_RESULT_READY;
                	}
                	else
                	{
                		if(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_BufferMode != SDADC_STREAM_LINEAR_BUFFER)/* polyspace RTE:NIV,NIP */
						{
							Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NumofValidConRes = 0U;
						}
						else
						{
							if((Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NotifyStatus == TRUE)
								&& (sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_BufferFullNotifyPtr != NULL_PTR))    /* polyspace RTE:NIP */
							{
								sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_BufferFullNotifyPtr(); /* polyspace RTE:COR */
							}
						}
                	}
                }
            }
        }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"
#endif /*RESOURCE_SUPPORT_SDADC_IP*/

#ifdef __cplusplus
}
#endif

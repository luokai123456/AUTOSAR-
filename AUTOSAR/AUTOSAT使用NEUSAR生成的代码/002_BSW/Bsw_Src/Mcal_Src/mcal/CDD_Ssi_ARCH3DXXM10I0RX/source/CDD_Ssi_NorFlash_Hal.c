/* PRQA S 2985, 0380, 0499, 4391, 4397, 4499, 1281, 1841, 4542, 1862, 2986  EOF */
/* PRQA S 2982, 4461, 0488, 2991, 2995, 0489, 0751, 2987, 1258, 4491, 3344, 3604, 0704, 4558 EOF */
/****************************************************************************
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : CDD_Ssi
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
*   @file    CDD_Ssi_NorFlash_Hal.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CDD SSI MCAL driver.
*
*   @addtogroup CDD SSI
*   @{
*/
#include "CDD_Ssi_NorFlash_Hal.h"/*PRQA S 0380*/
#include "common.h"

#define CDD_NORFLASH_WRA_C_VENDOR_ID                     176
#define CDD_NORFLASH_WRA_C_AR_REL_MAJOR_VER              4
#define CDD_NORFLASH_WRA_C_AR_REL_MINOR_VER              4
#define CDD_NORFLASH_WRA_C_AR_REL_REV_VER                0
#define CDD_NORFLASH_WRA_C_SW_MAJOR_VER                  3
#define CDD_NORFLASH_WRA_C_SW_MINOR_VER                  0
#define CDD_NORFLASH_WRA_C_SW_PATCH_VER                  0

#if (CDD_VENDOR_ID_OUTPUT != CDD_NORFLASH_WRA_C_VENDOR_ID)
    #error " NON-MATCHED DATA : CDD_NORFLASH_WRA_C_VENDOR_ID "
#endif
#if (CDD_AR_REL_MAJOR_VER_OUTPUT != CDD_NORFLASH_WRA_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CDD_NORFLASH_WRA_C_AR_REL_MAJOR_VER "
#endif
#if (CDD_AR_REL_MINOR_VER_OUTPUT != CDD_NORFLASH_WRA_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CDD_NORFLASH_WRA_C_AR_REL_MINOR_VER "
#endif
#if (CDD_AR_REL_REVISION_VER_OUTPUT != CDD_NORFLASH_WRA_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CDD_NORFLASH_WRA_C_AR_REL_REV_VER "
#endif
#if (CDD_SW_MAJOR_VERSION_OUTPUT != CDD_NORFLASH_WRA_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CDD_NORFLASH_WRA_C_SW_MAJOR_VER "
#endif
#if (CDD_SW_MINOR_VERSION_OUTPUT != CDD_NORFLASH_WRA_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CDD_NORFLASH_WRA_C_SW_MINOR_VER "
#endif
#if (CDD_SW_PATCH_VERSION_OUTPUT != CDD_NORFLASH_WRA_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CDD_NORFLASH_WRA_C_SW_PATCH_VER "
#endif

#ifdef RESOURCE_SUPPORT_SSI_IP

#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
SSI_HAL_StatusTypeDef SSI_NorFlash_Page_Program(SSI_Type *pssi,uint32_t addr,uint32_t num,const uint8_t *buf,uint32_t timeout)
{
    DRV_SSI_StatusTypeDef tmp_flag;
    SSI_DR_tag tmp_dr;
    uint32_t len = num;

    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_BUSY,SET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    SSI_CS_OUT_LOW;

    pssi->DR.R = (uint32_t)PAGE_PROG_CMD << 24U;
    pssi->DR.R = (uint32_t)((addr>>16U)&0xffU) << 24U;
    pssi->DR.R = (uint32_t)((addr>>8U)&0xffU) << 24U;
    pssi->DR.R = (uint32_t)(addr&0xffU) << 24U;

    while(len > 0U)
    {
        if(pssi->SR.R & SSI_SR_TFNF_MASK)
        {
            pssi->DR.R = (uint32_t)(*buf) << 24U;/* polyspace RTE:IDP */
            buf = buf + 1U;/*PRQA S 1338*/
            len = len -1U;
        }

        if(pssi->SR.R & SSI_SR_RFNE_MASK)
        {
            tmp_dr.R = pssi->DR.R;

        }
    }

    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_BUSY,SET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    SSI_CS_OUT_HIGH;

    tmp_flag = DRV_SSI_Clear_Fifo(pssi,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    tmp_dr.R = 0U;
    (void)tmp_dr.R;

    return SSI_HAL_OK;
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"


#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
SSI_HAL_StatusTypeDef SSI_NorFlash_Read_Data(SSI_Type *pssi,uint32_t addr,uint32_t num,uint8_t *buf,uint32_t timeout)
{
    uint32_t i=0,j=0,TIMEOUT=0;
    volatile uint32_t temp, txnum;
    DRV_SSI_StatusTypeDef tmp_flag;
    txnum = num;

    SSI_CS_OUT_LOW;

    pssi->DR.R = (uint32_t)READ_CMD << 24U;
    pssi->DR.R = (uint32_t)((addr>>16U)&0xffU) << 24U;
    pssi->DR.R = (uint32_t)((addr>>8U)&0xffU) << 24U;
    pssi->DR.R = (uint32_t)(addr&0xffU) << 24U;

    (void)delay(3U);

    TIMEOUT = timeout;

    while(num > 0U)
    {
        if((pssi->SR.R & SSI_SR_TFNF_MASK) && (txnum > 0U))
        {
            pssi->DR.R = (uint32_t)DUMMY_BYTE << 24U;
            txnum--;
        }

        if(pssi->SR.R & SSI_SR_RFNE_MASK)
        {
            /* note: reading 4 bytes(03h + 3 bytes addr) */
            temp = pssi->DR.R;
            temp = (temp & 0xff000000) >> 24U;
            if(j < 4U)
            {
                j++;
            }
            else
            {
                *(buf + i) = temp;/* polyspace RTE:IDP */
                 i++;
                 num--;
                 TIMEOUT = timeout;
            }
        }
        else
        {
            TIMEOUT--;
            if(TIMEOUT == 0U)
            {
                SSI_CS_OUT_HIGH;
                return DrvSSIStatusToHalStatus(DRV_SSI_TIMEOUT);
            }
        }
    }

    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_BUSY,SET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    SSI_CS_OUT_HIGH;
    return SSI_HAL_OK;
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"

/* the Status Register-1&2 can be written using a single ��Write Status Register-1
(01h)�� command */

#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
SSI_HAL_StatusTypeDef SSI_NorFlash_Set_Status1_Status2(SSI_Type *pssi,uint8_t val1,uint8_t val2,uint32_t timeout)
{
    DRV_SSI_StatusTypeDef tmp_flag;

    SSI_CS_OUT_LOW;

    pssi->DR.R =(uint32_t)PROG_STA12_CMD << 24U;
    pssi->DR.R =(uint32_t)val1 << 24U;
    pssi->DR.R =(uint32_t)val2 << 24U;

    (void)delay(3U);
    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_TFE,RESET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }
    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_BUSY,SET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    SSI_CS_OUT_HIGH;

    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_RFNE,SET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    return SSI_HAL_OK;
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"


#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
SSI_HAL_StatusTypeDef SSI_NorFlash_Set_Status(SSI_Type *pssi,uint8_t cmd, uint8_t val,uint32_t timeout)
{
    DRV_SSI_StatusTypeDef tmp_flag;

    SSI_CS_OUT_LOW;

    pssi->DR.R = (uint32_t)cmd << 24U;
    pssi->DR.R = (uint32_t)val << 24U;

    (void)delay(3U);

    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_TFE,RESET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }
    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_BUSY,SET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }
    tmp_flag = DRV_SSI_Clear_Fifo(pssi,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    SSI_CS_OUT_HIGH;
    return SSI_HAL_OK;
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"


#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
SSI_HAL_StatusTypeDef SSI_NorFlash_Read_Status(SSI_Type *pssi, uint8_t cmd, uint8_t *status, uint32_t timeout)
{
    FlagStatusTypeDef flag = RESET;
    DRV_SSI_StatusTypeDef tmp_flag = DRV_SSI_ERROR;
    uint32_t TIMEOUT;
    volatile uint32_t data_reg;
    SSI_DR_tag tmp_dr;

    SSI_CS_OUT_LOW;

    pssi->DR.R = (uint32_t)cmd << 24U;
    pssi->DR.R = (uint32_t)DUMMY_BYTE << 24U;
    (void)delay(3U);

    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_TFE,RESET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_BUSY,SET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    (void)DRV_SSI_GetFlag(pssi,SSI_FLAG_INDEX_RFNE,&flag);
    if(flag != SET)
    {
        SSI_CS_OUT_HIGH;
        return SSI_HAL_ERROR;
    }

    TIMEOUT = timeout;
    do
    {
        tmp_dr.R = pssi->DR.R;

        data_reg = (((uint32_t)tmp_dr.R & 0xffU) << 24U) | (((uint32_t)tmp_dr.R & 0xff00U) << 8U) | \
                   (((uint32_t)tmp_dr.R & 0xff0000U) >> 8U) | (((uint32_t)tmp_dr.R & 0xff000000U) >>24U);
        (void)DRV_SSI_GetFlag(pssi,SSI_FLAG_INDEX_RFNE,&flag);
        TIMEOUT = TIMEOUT - 1U;
        if(TIMEOUT == 0U)
        {
            SSI_CS_OUT_HIGH;
            return SSI_HAL_TIMEOUT;
        }
    }
    while(flag == SET);

    SSI_CS_OUT_HIGH;

    *status = (uint8_t)(data_reg&0xffU);
    return SSI_HAL_OK;
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"


#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
SSI_HAL_StatusTypeDef SSI_NorFlash_Write_Enable(SSI_Type *pssi,uint32_t timeout)
{
    DRV_SSI_StatusTypeDef tmp_flag = DRV_SSI_ERROR;

    SSI_CS_OUT_LOW;

    pssi->DR.R = (uint32_t)WRITE_EN_CMD << 24;
    (void)delay(3U);

    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_TFE,RESET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_BUSY,SET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    SSI_CS_OUT_HIGH;

    tmp_flag = DRV_SSI_Clear_Fifo(pssi,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    return SSI_HAL_OK;
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"


#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
SSI_HAL_StatusTypeDef SSI_Norflash_Erase_Sector(SSI_Type *pssi,uint32_t addr,uint32_t timeout)
{
    DRV_SSI_StatusTypeDef tmp_flag = DRV_SSI_ERROR;

    SSI_CS_OUT_LOW;

    pssi->DR.R = (uint32_t)SECT_ERASE_CMD << 24;
    pssi->DR.R = (uint32_t)((addr>>16U)&0xffU) << 24;
    pssi->DR.R = (uint32_t)((addr>>8U)&0xffU) << 24;
    pssi->DR.R = (uint32_t)(addr&0xffU) << 24;
    (void)delay(3U);

    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_TFE,RESET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_BUSY,SET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    tmp_flag = DRV_SSI_Clear_Fifo(pssi,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    SSI_CS_OUT_HIGH;

    return SSI_HAL_OK;
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"


#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
SSI_HAL_StatusTypeDef SSI_Norflash_Read_ID(SSI_Type *pssi,uint16_t *ID,uint32_t timeout)
{
    DRV_SSI_StatusTypeDef tmp_flag = DRV_SSI_ERROR;
    SSI_DR_tag tmp_dr;
    uint8_t i;

    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_BUSY,SET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    SSI_CS_OUT_LOW;

    pssi->DR.R = (uint32_t)READ_ID_CMD << 24U;
    pssi->DR.R = 0U;
    pssi->DR.R = 0U;
    pssi->DR.R = 0U;
    pssi->DR.R = (uint32_t)DUMMY_BYTE << 24U;
    pssi->DR.R = (uint32_t)DUMMY_BYTE << 24U;

    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_TFE,RESET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_BUSY,SET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    SSI_CS_OUT_HIGH;

    for(i=0U; i<4U; i++)
    {
        tmp_dr.R = pssi->DR.R;
        *ID = (((uint32_t)tmp_dr.R & 0xffU)<< 24U) | (((uint32_t)tmp_dr.R & 0xff00U) << 8U) | \
              (((uint32_t)tmp_dr.R & 0xff0000U) >> 8U) | (((uint32_t)tmp_dr.R & 0xff000000U) >> 24U);
    }

    tmp_dr.R = pssi->DR.R;
    *ID = (((uint32_t)tmp_dr.R & 0xffU)<< 24U) | (((uint32_t)tmp_dr.R & 0xff00U) << 8U) | \
          (((uint32_t)tmp_dr.R & 0xff0000U) >> 8U) | (((uint32_t)tmp_dr.R & 0xff000000U) >> 24U);

    tmp_dr.R = pssi->DR.R;
    *ID |= (((uint32_t)tmp_dr.R & 0xffU)<< 24U) | (((uint32_t)tmp_dr.R & 0xff00U) << 8U) | \
            (((uint32_t)tmp_dr.R & 0xff0000U) >> 8U) | ((((uint32_t)tmp_dr.R & 0xff000000U) >> 24U) << 8U);

    return SSI_HAL_OK;
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"


#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
SSI_HAL_StatusTypeDef SSI_NorFlash_Quad_DMA_Page_Program(SSI_Type *pssi, uint8_t dma_channel, uint32_t addr,uint32_t num,const uint8_t *buf,uint32_t timeout)
{
    DRV_SSI_StatusTypeDef tmp_flag;
    uint32_t reg_val = 0U;

    /* DMA operation begin*/
    eDMATransferConfigType dmaConfig =
    {
        .srcAddr = (uint32_t)buf, /* Modified by function */
        .destAddr = (uint32_t)&pssi->DR.R, /* Modified by function */
        .srcTransDataSize = /*EDMA_TRANSFER_SIZE_4B*/EDMA_TRANSFER_SIZE_1B,
        .destTransDataSize = /*EDMA_TRANSFER_SIZE_4B*/EDMA_TRANSFER_SIZE_1B,
        .srcAddrOffset = (int16_t)1,
        .destAddrOffset = (int16_t)0,
        .srcAddrAdjustLast = 0,
        .destAddrAdjustLast = 0, /* Modified by function */
        .srcAddrModulo = EDMA_ADDRESS_MODULO_OFF,
        .destAddrModulo = EDMA_ADDRESS_MODULO_OFF,
        .minorTransByte = /*16u*/1, /* Modified by function */
        .featureScatterGatherEn = FALSE,
        .featureScatterGatherNextDescriptor = 0u,
        .completeIntEn = FALSE,
        .lpTransConfigPtr = &(eDMALoopTransferConfigType)
        {
            .majorLpIterCnt = num,
            .srcAddrOffsetEn = FALSE,
            .dstAddrOffsetEn = TRUE,
            .minorLpOffset = 0,
            .minorLpLinkEn = FALSE,
            .minorLpLinkChn = 0u,
            .majorLpLinkEn = FALSE,
            .majorLpLinkChn = 0u
        }
    };

    (void)EDMA_LLD_SetLoopTransferConfig(dma_channel, &dmaConfig);
    /* DMA operation end*/

    SSI_CS_OUT_LOW;

    pssi->DR.R = (uint32_t)QUAD_PROG_CMD << 24U;
    pssi->DR.R = (((addr>>24U)&0xffU) << 0U) | (((addr>>16U)&0xffU) << 8U) | \
                 (((addr>>8U)&0xffU) << 16U) | ((addr & 0xffU) << 24U);

    /* DMA operation begin*/
    (void)EDMA_LLD_SetChnDisReqOnTrfComp(dma_channel, TRUE);

    reg_val = pssi->DMATDLR.R;
    reg_val &= ~SSI_DMATDL_MASK;
    reg_val |= SSI_DMATDL_DATAW(2U);
    pssi->DMATDLR.R = reg_val;

    reg_val = pssi->DMACR.R;
    reg_val &= ~SSI_DMACR_TDMAE_MASK;
    reg_val |= SSI_DMACR_TDMAE_DATAW(1U);
    pssi->DMACR.R = reg_val;

    (void)EDMA_LLD_SetChannelRequest(dma_channel);
    EDMA_LLD_WaitChnTransferDone(dma_channel);
    /* DMA operation end*/

    tmp_flag = DRV_SSI_Clear_Fifo(pssi,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_BUSY,SET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    SSI_CS_OUT_HIGH;
    return SSI_HAL_OK;
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"

#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
SSI_HAL_StatusTypeDef SSI_NorFlash_Quad_DMA_Read_Data(SSI_Type *pssi, uint8_t dma_channel, uint32_t addr,uint32_t num,uint8_t *buf,uint32_t timeout)
{
    DRV_SSI_StatusTypeDef tmp_flag;
    uint32_t reg_val = 0U;

    /* DMA operation begin*/
    eDMATransferConfigType dmaConfig =
    {
        .srcAddr = (uint32_t)&pssi->DR.R, /* Modified by function */
        .destAddr = (uint32_t)buf, /* Modified by function */
        .srcTransDataSize = /*EDMA_TRANSFER_SIZE_4B*/EDMA_TRANSFER_SIZE_1B,
        .destTransDataSize = /*EDMA_TRANSFER_SIZE_4B*/EDMA_TRANSFER_SIZE_1B,
        .srcAddrOffset = (int16_t)0,
        .destAddrOffset = (int16_t)1,
        .srcAddrAdjustLast = 0,
        .destAddrAdjustLast = 0, /* Modified by function */
        .srcAddrModulo = EDMA_ADDRESS_MODULO_OFF,
        .destAddrModulo = EDMA_ADDRESS_MODULO_OFF,
        .minorTransByte = /*16u*/1, /* Modified by function */
        .featureScatterGatherEn = FALSE,
        .featureScatterGatherNextDescriptor = 0u,
        .completeIntEn = FALSE,
        .lpTransConfigPtr = &(eDMALoopTransferConfigType)
        {
            .majorLpIterCnt = num,
            .srcAddrOffsetEn = FALSE,
            .dstAddrOffsetEn = TRUE,
            .minorLpOffset = 0,
            .minorLpLinkEn = FALSE,
            .minorLpLinkChn = 0u,
            .majorLpLinkEn = FALSE,
            .majorLpLinkChn = 0u
        }
    };

    (void)EDMA_LLD_SetLoopTransferConfig(dma_channel, &dmaConfig);
    /* DMA operation end*/

    SSI_CS_OUT_LOW;

    pssi->DR.R = (uint32_t)QUAD_READ_CMD << 24U;
    pssi->DR.R = (((addr>>24U)&0xffU) << 0U) | (((addr>>16U)&0xffU) << 8U) | \
                 (((addr>>8U)&0xffU) << 16U) | ((addr & 0xffU) << 24U);
    /* DMA operation begin*/
    (void)delay(300U);
    (void)EDMA_LLD_SetChnDisReqOnTrfComp(dma_channel, TRUE);

    reg_val = pssi->DMACR.R;
    reg_val &= ~SSI_DMACR_RDMAE_MASK;
    reg_val |= SSI_DMACR_RDMAE_DATAW(1U);
    pssi->DMACR.R = reg_val;

    (void)EDMA_LLD_SetChannelRequest(dma_channel);
    EDMA_LLD_WaitChnTransferDone(dma_channel);
    /* DMA operation end*/

    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_TFE,RESET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    SSI_CS_OUT_HIGH;

    return SSI_HAL_OK;
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"


#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
SSI_HAL_StatusTypeDef SSI_NorFlash_Quad_Page_Program(SSI_Type *pssi,uint32_t addr,uint32_t num,const uint8_t *buf,uint32_t timeout)
{
    DRV_SSI_StatusTypeDef tmp_flag;
    uint32_t len = num;
    uint32_t timeout_cnt = 0;

    SSI_CS_OUT_LOW;

    pssi->DR.R = (uint32_t)QUAD_PROG_CMD << 24U;
    pssi->DR.R = (((addr>>24U)&0xffU) << 0U) | (((addr>>16U)&0xffU) << 8U) | \
                 (((addr>>8U)&0xffU) << 16U) | ((addr & 0xffU) << 24U);

    while((len > 0U) && (timeout_cnt< timeout))
    {

        if(pssi->SR.R & SSI_SR_TFNF_MASK)
        {
            pssi->DR.R = ((uint32_t)*buf << 24U);/* polyspace RTE:IDP */
            buf = buf + 1U;/*PRQA S 1338*/
            len = len - 1U;
            timeout_cnt = 0U;
        }

        if(pssi->SR.R & SSI_SR_RFNE_MASK)
        {
            (void)pssi->DR.R;
        }

        timeout_cnt++;
    }

    if(timeout_cnt >= timeout)
    {
        SSI_CS_OUT_HIGH;
        return SSI_HAL_TIMEOUT;
    }

    tmp_flag = DRV_SSI_Clear_Fifo(pssi,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_BUSY,SET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    SSI_CS_OUT_HIGH;
    return SSI_HAL_OK;
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"


#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
SSI_HAL_StatusTypeDef SSI_NorFlash_Quad_Read_Data(SSI_Type *pssi, uint32_t addr,uint32_t num,uint8_t *buf,uint32_t timeout)
{
    DRV_SSI_StatusTypeDef tmp_flag;
    uint32_t i=0U;
    SSI_DR_tag tmp_dr;
    uint32_t len = num;
    uint32_t timeout_cnt = 0;

    SSI_CS_OUT_LOW;

    pssi->DR.R = (uint32_t)QUAD_READ_CMD << 24U;
    pssi->DR.R = (((addr>>24U)&0xffU) << 0U) | (((addr>>16U)&0xffU) << 8U) | \
                 (((addr>>8U)&0xffU) << 16U) | ((addr & 0xffU) << 24U);

    tmp_flag = DRV_SSI_WaitonFlagTimeout(pssi,SSI_FLAG_INDEX_TFE,RESET,timeout);
    if(tmp_flag != DRV_SSI_OK)
    {
        SSI_CS_OUT_HIGH;
        return DrvSSIStatusToHalStatus(tmp_flag);
    }

    while((((len > 0U) && (pssi->SR.R & SSI_SR_BUSY_MASK)) || (pssi->SR.R & SSI_SR_RFNE_MASK))
            && (timeout_cnt < timeout))
    {
        if(pssi->SR.R & SSI_SR_RFNE_MASK)
        {
            tmp_dr.R = pssi->DR.R;
            *(buf+i) = (((uint32_t)tmp_dr.R & 0xffU) << 24U) | (((uint32_t)tmp_dr.R & 0xff00U) << 8U) | (((uint32_t)tmp_dr.R & 0xff0000U) >> 8U) | (((uint32_t)tmp_dr.R & 0xff000000U) >> 24U);/* polyspace RTE:NIV,IDP */
            i = i + 1U;
            len = len - 1U;
            timeout_cnt = 0U;
        }
        timeout_cnt++;
    }

    if(timeout_cnt >= timeout)
    {
        SSI_CS_OUT_HIGH;
        return SSI_HAL_TIMEOUT;
    }

    SSI_CS_OUT_HIGH;

    return SSI_HAL_OK;
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"

#endif  /* RESOURCE_SUPPORT_SSI_IP */

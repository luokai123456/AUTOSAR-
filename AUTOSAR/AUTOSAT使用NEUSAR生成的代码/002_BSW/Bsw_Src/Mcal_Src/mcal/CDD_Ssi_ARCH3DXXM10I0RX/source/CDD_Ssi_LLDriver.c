/* PRQA S 2985, 0380, 0499, 4391, 4397, 4499, 1281, 1841, 4542, 1862, 2986  EOF */
/* PRQA S 2982, 4461, 0488, 2991, 2995, 0489, 0751, 2987, 1258, 4491  EOF */
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
*   @file    CDD_Ssi_LLDriver.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CDD SSI MCAL driver.
*
*   @addtogroup CDD SSI
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "CDD_Ssi_LLDriver.h"
/* PRQA S 1528,3604 EOF */

#define CDD_LLD_WRA_C_VENDOR_ID                     176
#define CDD_LLD_WRA_C_AR_REL_MAJOR_VER              4
#define CDD_LLD_WRA_C_AR_REL_MINOR_VER              4
#define CDD_LLD_WRA_C_AR_REL_REV_VER                0
#define CDD_LLD_WRA_C_SW_MAJOR_VER                  3
#define CDD_LLD_WRA_C_SW_MINOR_VER                  0
#define CDD_LLD_WRA_C_SW_PATCH_VER                  0

#if (CDD_VENDOR_ID_OUTPUT != CDD_LLD_WRA_C_VENDOR_ID)
    #error " NON-MATCHED DATA : CDD_LLD_WRA_C_VENDOR_ID "
#endif
#if (CDD_AR_REL_MAJOR_VER_OUTPUT != CDD_LLD_WRA_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CDD_LLD_WRA_C_AR_REL_MAJOR_VER "
#endif
#if (CDD_AR_REL_MINOR_VER_OUTPUT != CDD_LLD_WRA_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CDD_LLD_WRA_C_AR_REL_MINOR_VER "
#endif
#if (CDD_AR_REL_REVISION_VER_OUTPUT != CDD_LLD_WRA_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CDD_LLD_WRA_C_AR_REL_REV_VER "
#endif
#if (CDD_SW_MAJOR_VERSION_OUTPUT != CDD_LLD_WRA_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CDD_LLD_WRA_C_SW_MAJOR_VER "
#endif
#if (CDD_SW_MINOR_VERSION_OUTPUT != CDD_LLD_WRA_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CDD_LLD_WRA_C_SW_MINOR_VER "
#endif
#if (CDD_SW_PATCH_VERSION_OUTPUT != CDD_LLD_WRA_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CDD_LLD_WRA_C_SW_PATCH_VER "
#endif

#ifdef RESOURCE_SUPPORT_SSI_IP


/*---DRV functions------------------------------------------------*/
#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
DRV_SSI_StatusTypeDef DRV_SSI_GetFlag(SSI_Type const *pssi,SSI_FlagIndexTypeDef FlagIndex,FlagStatusTypeDef *pflag)
{
    if((FlagIndex>= SSI_FLAG_INDEX_BUSY) && (FlagIndex<= SSI_FLAG_INDEX_RFF))
    {
        if(((pssi->SR.R >> 24U)&(uint8_t)FlagIndex) != 0U)
        {
            *pflag = SET;
        }
        else
        {
            *pflag = RESET;
        }
    }
    else
    {
        return(DRV_SSI_ERROR);
    }

    return(DRV_SSI_OK);
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"
/**
  *
  *@param[in]  pssi the pointer point to SSI_Type struct
  *@param[in]  FlagIndex SSI SR status
    *- SSI_FLAG_INDEX_BUSY
    *- SSI_FLAG_INDEX_TFNF
    *- SSI_FLAG_INDEX_TFE
    *- SSI_FLAG_INDEX_RFNE
    *- SSI_FLAG_INDEX_RFF
  *@param[in] status to be set
  *- SET
  *- REST
  @param[in] timeout time to out;
  *@retval  @ref DRV_SSI_StatusTypeDef
  */
#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
DRV_SSI_StatusTypeDef DRV_SSI_WaitonFlagTimeout(const SSI_Type *pssi,
                                            SSI_FlagIndexTypeDef index,
                                            FlagStatusTypeDef status,
                                            uint32_t timeout)
{
    FlagStatusTypeDef tmp_flag = RESET;
    uint32_t TIMEOUT;
    TIMEOUT = timeout;
    while(TIMEOUT > 0U)
    {
        (void)DRV_SSI_GetFlag(pssi,index,&tmp_flag);
        if(tmp_flag!=status)
        {
            break;
        }
        TIMEOUT = TIMEOUT - 1U;
        if(TIMEOUT == 0U)
        {
            return(DRV_SSI_TIMEOUT);
        }
    }
    return DRV_SSI_OK;
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"
/**
  *
  *@param[in]  pssi the pointer point to SSI_Type struct
  @param[in] timeout time to out
  *@retval status @ref DRV_SSI_StatusTypeDef
  */
#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
DRV_SSI_StatusTypeDef DRV_SSI_Clear_Fifo(const SSI_Type *pssi,uint32_t timeout)
{
    FlagStatusTypeDef flag = RESET;
    uint32_t temp = 0U;
    uint32_t TIMEOUT = timeout;

    (void)DRV_SSI_GetFlag(pssi,SSI_FLAG_INDEX_RFNE,&flag);
    while(flag == SET)
    {
        TIMEOUT = TIMEOUT - 1U;
        temp = pssi->DR.R;/*PRQA S 2983 */

        if(TIMEOUT == 0U)
        {
            return DRV_SSI_TIMEOUT;
        }
        (void)DRV_SSI_GetFlag(pssi,SSI_FLAG_INDEX_RFNE,&flag);
    }
    (void)temp;
    return DRV_SSI_OK;
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"

#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
DRV_SSI_StatusTypeDef DRV_SSI_Check_STD_Mode(const SSI_Type *pssi)
{
    uint8_t ctl_dfs, ctl_frf;

    ctl_dfs = ((uint8_t)(pssi->CTRLR0.R >> SSI_CTRLR0_DFS_SHIFT) & (uint8_t)((1U<<SSI_CTRLR0_DFS_WIDTH)-1U));
    ctl_frf = ((uint8_t)(pssi->CTRLR0.R >> SSI_CTRLR0_SPI_FRF_SHIFT) & (uint8_t)((1U<<SSI_CTRLR0_SPI_FRF_WIDTH)-1U));

    if((ctl_dfs != (uint8_t)DFS_08_BIT) || (ctl_frf != (uint8_t)STD_mode))
    {
        return DRV_SSI_ERROR;
    }

    return DRV_SSI_OK;
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"
/**
 *@param[in] pssi the pointer point to SSI_Type struct
 *@return none
 */
#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
void DRV_SSI_En(SSI_Type *pssi)
{
    pssi->SSIENR.R = 0x01000000U;
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"
/**
 *
 *@param[in] pssi the pointer point to SSI_Type struct
 *@return none
 */
#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
void DRV_SSI_Dis(SSI_Type *pssi)
{
    pssi->SSIENR.R = 0x00000000U;
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"

#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
void DRV_SSI_Init(SSI_Type *pssi, const SSI_InitTypeDef *pinit)
{
    /* Disable SSI */
    pssi->SSIENR.R = 0x00000000U;

    pssi->CTRLR0.R = (SSI_CTRLR0_FRF_DATAW(pinit->FRF) | SSI_CTRLR0_DFS_DATAW(pinit->DFS) |     \
                      SSI_CTRLR0_SSTE_DATAW(0U) | SSI_CTRLR0_SSRL_DATAW(0U) |    \
                      SSI_CTRLR0_TMOD_DATAW(pinit->TMOD) | SSI_CTRLR0_SCOPL_DATAW(pinit->SCPOL)| \
                      SSI_CTRLR0_SCPH_DATAW(pinit->SCPH) | SSI_CTRLR0_SPI_FRF_DATAW(pinit->Format) |  \
                      SSI_CTRLR0_CFS_DATAW(0U));

    pssi->CTRLR1.R = SSI_CTRLR1_NDF_H_DATAW(((uint32_t)(pinit->NDF)&0xFF00u) >> 8U) | \
                     SSI_CTRLR1_NDF_L_DATAW((uint32_t)(pinit->NDF)&0xFFu);

    pssi->BAUDR.R = (SSI_BAUDR_SCKDV_H_DATAW(((uint32_t)(pinit->SSI_BaudRatePrescaler)&0xFF00u) >> 8U) | \
                    SSI_BAUDR_SCKDV_L_DATAW((uint32_t)(pinit->SSI_BaudRatePrescaler)&0xFFu));

    pssi->RXSDR.R = (SSI_RXSD_RSD_DATAW(1u)| SSI_RXSD_SE_DATAW(1u));

    pssi->TXFTLR.R = (SSI_TXFTL_TFT_DATAW(pinit->Transfer_start_FIFO_level) | SSI_TXFTL_TXFTHR_DATAW(pinit->Transmit_FIFO_Threshold));

    pssi->RXFTLR.R = SSI_RXFTLR_RFT_DATAW(pinit->Receive_FIFO_Threshold);

    pssi->IMR.R = 0U;

    pssi->SPICTRLR0.R = (SSI_SPICTRLR0_ADDR_L_DATAW(pinit->Address_Length) | SSI_SPICTRLR0_TRANS_TYPE_DATAW(pinit->Trans_Type) | \
                         SSI_SPICTRLR0_WAIT_CYCLES_DATAW(pinit->WAIT_CYCLES) | SSI_SPICTRLR0_INST_L_DATAW(pinit->Instruction_length) | \
                         SSI_SPICTRLR0_CLK_STH_DATAW(pinit->CLK_STRETCH_EN));

    /* Enable SSI */
    pssi->SSIENR.R = 0x01000000U;

    /* SSI1 Trim Value Register */
    *((volatile uint32_t *)(0xffff8054U)) |= ((1U << 15U)|(1U<< 14U));//ssi0_trim set big endian
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"

#define CDD_SSI_START_SEC_CODE
#include "CDD_Ssi_MemMap.h"
SSI_HAL_StatusTypeDef DrvSSIStatusToHalStatus(DRV_SSI_StatusTypeDef DrvStatus)
{
    SSI_HAL_StatusTypeDef ret;
    switch(DrvStatus)
    {
        case DRV_SSI_OK:
            ret = SSI_HAL_OK;
            break;

        case DRV_SSI_ERROR:
            ret = SSI_HAL_ERROR;
            break;

        case DRV_SSI_BUSY:
            ret = SSI_HAL_BUSY;
            break;

        case DRV_SSI_TIMEOUT:
            ret = SSI_HAL_TIMEOUT;
            break;
        default:
            ret = SSI_HAL_ERROR;
            break;
    }
    return ret;
}
#define CDD_SSI_STOP_SEC_CODE
#include "CDD_Ssi_MemMap.h"

#endif  /* RESOURCE_SUPPORT_SSI_IP */
#ifdef __cplusplus
}
#endif

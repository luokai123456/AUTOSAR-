/****************************************************************************
*
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
/* PRQA S 1535 EOF */
/**
*   @file    CDD_Ssi_NorFlash_Driver.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CDD SSI MCAL driver.
*
*   @addtogroup CDD SSI
*   @{
*/
/*PRQA S 1753 EOF*/
#ifndef CDD_SSI_NORFLASH_HAL_H
#define CDD_SSI_NORFLASH_HAL_H

#ifdef __cplusplus
extern "C"{
#endif

#include "CDD_Ssi_LLDriver.h"

#define CDD_NORFLASH_WRA_H_VENDOR_ID                     176
#define CDD_NORFLASH_WRA_H_AR_REL_MAJOR_VER              4
#define CDD_NORFLASH_WRA_H_AR_REL_MINOR_VER              4
#define CDD_NORFLASH_WRA_H_AR_REL_REV_VER                0
#define CDD_NORFLASH_WRA_H_SW_MAJOR_VER                  3
#define CDD_NORFLASH_WRA_H_SW_MINOR_VER                  0
#define CDD_NORFLASH_WRA_H_SW_PATCH_VER                  0

#if (CDD_VENDOR_ID_OUTPUT != CDD_NORFLASH_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : CDD_NORFLASH_WRA_H_VENDOR_ID "
#endif
#if (CDD_AR_REL_MAJOR_VER_OUTPUT != CDD_NORFLASH_WRA_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CDD_NORFLASH_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (CDD_AR_REL_MINOR_VER_OUTPUT != CDD_NORFLASH_WRA_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CDD_NORFLASH_WRA_H_AR_REL_MINOR_VER "
#endif
#if (CDD_AR_REL_REVISION_VER_OUTPUT != CDD_NORFLASH_WRA_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CDD_NORFLASH_WRA_H_AR_REL_REV_VER "
#endif
#if (CDD_SW_MAJOR_VERSION_OUTPUT != CDD_NORFLASH_WRA_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CDD_NORFLASH_WRA_H_SW_MAJOR_VER "
#endif
#if (CDD_SW_MINOR_VERSION_OUTPUT != CDD_NORFLASH_WRA_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CDD_NORFLASH_WRA_H_SW_MINOR_VER "
#endif
#if (CDD_SW_PATCH_VERSION_OUTPUT != CDD_NORFLASH_WRA_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CDD_NORFLASH_WRA_H_SW_PATCH_VER "
#endif

#ifdef RESOURCE_SUPPORT_SSI_IP

/* w25q128 CMD */
#define DUMMY_BYTE              0xa5U
#define READ_ID_CMD             0x90U
#define WRITE_EN_CMD            0x06U
#define SECT_ERASE_CMD          0x20U
#define GET_SAT1_CMD            0x05U
#define READ_CMD                0x03U
#define PAGE_PROG_CMD           0x02U
#define GET_SAT2_CMD            0x35U
#define PROG_STA12_CMD          0x01U
#define PROG_STA2_CMD           0x31U
#define DUAL_READ_CMD           0x3bU
#define QUAD_PROG_CMD           0x32U
#define QUAD_READ_CMD           0x6bU
#define QPI_READ_CMD            0x0bU
#define QPI_ENTER_CMD           0x38U
#define QPI_EXIT_CMD            0xFFU
#define SET_READ_PARA_CMD       0xc0U
#define Reset_EN_CMD            0x66U
#define Reset_CMD               0x99U
#define FAST_READ_QUAD_IO_CMD   0xebU

#define NORFLASH_PAGE_SIZE      0x100U
#define NORFLASH_SECTOR_SIZE    0x1000U

SSI_HAL_StatusTypeDef SSI_NorFlash_Page_Program(SSI_Type *pssi,uint32_t addr,uint32_t num,const uint8_t *buf,uint32_t timeout);
SSI_HAL_StatusTypeDef SSI_NorFlash_Read_Data(SSI_Type *pssi,uint32_t addr,uint32_t num,uint8_t *buf,uint32_t timeout);
SSI_HAL_StatusTypeDef SSI_NorFlash_Set_Status1_Status2(SSI_Type *pssi,uint8_t val1,uint8_t val2,uint32_t timeout);
SSI_HAL_StatusTypeDef SSI_NorFlash_Set_Status(SSI_Type *pssi,uint8_t cmd, uint8_t val,uint32_t timeout);
SSI_HAL_StatusTypeDef SSI_NorFlash_Read_Status(SSI_Type *pssi, uint8_t cmd, uint8_t *status, uint32_t timeout);
SSI_HAL_StatusTypeDef SSI_NorFlash_Write_Enable(SSI_Type *pssi,uint32_t timeout);
SSI_HAL_StatusTypeDef SSI_Norflash_Erase_Sector(SSI_Type *pssi,uint32_t addr,uint32_t timeout);
SSI_HAL_StatusTypeDef SSI_Norflash_Read_ID(SSI_Type *pssi,uint16_t *ID,uint32_t timeout);
SSI_HAL_StatusTypeDef SSI_NorFlash_Quad_DMA_Page_Program(SSI_Type *pssi,uint8_t dma_channel, uint32_t addr,uint32_t num,const uint8_t *buf,uint32_t timeout);
SSI_HAL_StatusTypeDef SSI_NorFlash_Quad_DMA_Read_Data(SSI_Type *pssi, uint8_t dma_channel, uint32_t addr,uint32_t num,uint8_t *buf,uint32_t timeout);
SSI_HAL_StatusTypeDef SSI_NorFlash_Quad_Page_Program(SSI_Type *pssi,uint32_t addr,uint32_t num,const uint8_t *buf,uint32_t timeout);
SSI_HAL_StatusTypeDef SSI_NorFlash_Quad_Read_Data(SSI_Type *pssi, uint32_t addr,uint32_t num,uint8_t *buf,uint32_t timeout);


#endif  /* RESOURCE_SUPPORT_SSI_IP */
#endif /* CDD_SSI_NORFLASH_HAL_H */

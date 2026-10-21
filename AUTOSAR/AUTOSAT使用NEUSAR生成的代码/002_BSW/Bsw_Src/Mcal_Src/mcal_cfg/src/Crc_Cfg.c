/*PRQA S 0380,2053 EOF*/
/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : -
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
*   @file    Crc_Cfg.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CRC MCAL driver.
*
*   @addtogroup CRC
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif
/*PRQA S 1533 EOF*/
/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "Crc_Cfg.h"
#include "eDma_LLDriver.h"
#include "Crc.h"
#define CRC_CFG_C_VENDOR_ID                     176
#define CRC_CFG_C_AR_REL_MAJOR_VER              4
#define CRC_CFG_C_AR_REL_MINOR_VER              4
#define CRC_CFG_C_AR_REL_REV_VER                0
#define CRC_CFG_C_SW_MAJOR_VER                  3
#define CRC_CFG_C_SW_MINOR_VER                  0
#define CRC_CFG_C_SW_PATCH_VER                  0

/**
****************************************************************************************
 * @brief: Version Verify
****************************************************************************************
*/
#if (MCAL_VENDOR_ID != CRC_CFG_C_VENDOR_ID)
    #error " NON-MATCHED DATA : CRC_CFG_C_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != CRC_CFG_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CRC_CFG_C_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != CRC_CFG_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CRC_CFG_C_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != CRC_CFG_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CRC_CFG_C_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != CRC_CFG_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CRC_CFG_C_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != CRC_CFG_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CRC_CFG_C_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != CRC_CFG_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CRC_CFG_C_SW_PATCH_VER "
#endif
void crc_callback(uint32 Result){} //DQ
    
#define CRC_START_SEC_CONFIG_DATA
#include "Crc_MemMap.h"
static CONST(Crc_ConfigGroupType, CRC_CONST)CrcSettingsConfig[2]=
{
    {
        .u8CrcChannel =0U,
        .Calculate = CRC_POLYNOMIAL_16,
        .u8CrcId = CRC0,
        .u8DMAChannel = EDMA_CHN1_NUMBER,
        
        .CRC_Callback =&crc_callback,
    },
    {
        .u8CrcChannel =1U,
        .Calculate = CRC_POLYNOMIAL_16,
        .u8CrcId = CRC0,
        .u8DMAChannel = EDMA_CHN1_NUMBER,
        
        .CRC_Callback =&crc_callback,
    }
};
#define CRC_STOP_SEC_CONFIG_DATA
#include "Crc_MemMap.h"
#define CRC_START_SEC_CONFIG_DATA
#include "Crc_MemMap.h"
CONST(Crc_ConfigType, CRC_CONST) Crc_Config =
{
	.Crc_ConfigGroup = CrcSettingsConfig
};
#define CRC_STOP_SEC_CONFIG_DATA
#include "Crc_MemMap.h"
#ifdef __cplusplus
}
#endif

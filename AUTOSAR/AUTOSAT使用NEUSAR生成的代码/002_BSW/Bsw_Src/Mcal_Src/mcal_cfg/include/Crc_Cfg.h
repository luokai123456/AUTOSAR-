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
*   @file    Crc_Cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CRC MCAL driver.
*
*   @addtogroup CRC
*   @{
*/

#ifndef CRC_CFG_H
#define CRC_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/ 
#include "Mcal.h"

#define CRC_CFG_H_VENDOR_ID                     176
#define CRC_CFG_H_AR_REL_MAJOR_VER              4
#define CRC_CFG_H_AR_REL_MINOR_VER              4
#define CRC_CFG_H_AR_REL_REV_VER                0
#define CRC_CFG_H_SW_MAJOR_VER                  3
#define CRC_CFG_H_SW_MINOR_VER                  0
#define CRC_CFG_H_SW_PATCH_VER                  0

/**
****************************************************************************************
 * @brief: Version Verify
****************************************************************************************
*/
#if (MCAL_VENDOR_ID != CRC_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : CRC_CFG_H_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != CRC_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CRC_CFG_H_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != CRC_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CRC_CFG_H_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != CRC_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CRC_CFG_H_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != CRC_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CRC_CFG_H_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != CRC_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CRC_CFG_H_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != CRC_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CRC_CFG_H_SW_PATCH_VER "
#endif


#define CRC_CONTROLLER    CRC0

#define CRC_CONTROLLER_EXT    CRC1


#define CRC_16ARC_MODE    CRC_16_ARC_TABLE

#define CRC_16_MODE    CRC_16_RUNTIME

#define CRC_32_MODE    CRC_32_RUNTIME

#define CRC_32P4_MODE    CRC_32P4_TABLE

#define CRC_64_MODE    CRC_64_TABLE

#define CRC_8H2F_MODE    CRC_8H2F_RUNTIME

#define CRC_8_MODE    CRC_8_RUNTIME

#define CRC_16ARC_MODE_EXT    CRC_16_ARC_TABLE

#define CRC_16_MODE_EXT    CRC_16_HARDWARE

#define CRC_32_MODE_EXT    CRC_32_HARDWARE

#define CRC_32P4_MODE_EXT    CRC_32P4_TABLE

#define CRC_64_MODE_EXT    CRC_64_TABLE

#define CRC_8H2F_MODE_EXT    CRC_8H2F_TABLE

#define CRC_8_MODE_EXT    CRC_8_HARDWARE

#define CRC_CHANNEL_MAX    2
#ifdef __cplusplus
}
#endif

#endif /* CRC_CFG_H */

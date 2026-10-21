/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : I2C
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
*   @file    CDD_I2c_Irq.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of I2c MCAL driver.
*
*   @addtogroup I2c
*   @{
*/

#ifndef IIC_IRQ_H
#define IIC_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

#include "CDD_I2c_Cfg.h"

#ifdef RESOURCE_SUPPORT_I2C

#define CDD_I2C_CFG_C_VENDOR_ID                     176
#define CDD_I2C_CFG_C_AR_REL_MAJOR_VER              4
#define CDD_I2C_CFG_C_AR_REL_MINOR_VER              4
#define CDD_I2C_CFG_C_AR_REL_REV_VER                0
#define CDD_I2C_CFG_C_SW_MAJOR_VER                  3
#define CDD_I2C_CFG_C_SW_MINOR_VER                  0
#define CDD_I2C_CFG_C_SW_PATCH_VER                  0

#if (MCAL_VENDOR_ID != CDD_I2C_CFG_C_VENDOR_ID)
    #error " NON-MATCHED DATA : CDD_I2C_CFG_C_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != CDD_I2C_CFG_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CDD_I2C_CFG_C_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != CDD_I2C_CFG_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CDD_I2C_CFG_C_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != CDD_I2C_CFG_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CDD_I2C_CFG_C_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != CDD_I2C_CFG_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CDD_I2C_CFG_C_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != CDD_I2C_CFG_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CDD_I2C_CFG_C_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != CDD_I2C_CFG_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CDD_I2C_CFG_C_SW_PATCH_VER "
#endif

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(void, I2C_CODE) I2C_LLD_Module0IRQHandler(void);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(void, I2C_CODE) I2C_LLD_Module1IRQHandler(void);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#endif /* RESOURCE_SUPPORT_I2C */

#ifdef __cplusplus
}
#endif

#endif

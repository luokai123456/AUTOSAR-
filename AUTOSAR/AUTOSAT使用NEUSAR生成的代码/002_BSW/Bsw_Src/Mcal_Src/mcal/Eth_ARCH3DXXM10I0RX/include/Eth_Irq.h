/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : ETH
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
*   @file    Eth_Irq.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Eth MCAL driver.
*
*   @addtogroup Eth
*   @{
*/

#ifndef ETH_IRQ_H
#define ETH_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "derivative.h"
#if (defined(RESOURCE_SUPPORT_ETH_EMAC_IP) || defined(RESOURCE_SUPPORT_ETH_GMAC_IP))
#include "Eth_GeneralTypes.h" 

/**
****************************************************************************************
 * @brief: Eth.h Version
****************************************************************************************
*/
#define ETH_IRQ_H_VENDOR_ID                    176
#define ETH_IRQ_H_AR_REL_MAJOR_VER             4
#define ETH_IRQ_H_AR_REL_MINOR_VER             4
#define ETH_IRQ_H_AR_REL_REV_VER               0
#define ETH_IRQ_H_SW_MAJOR_VER                 3
#define ETH_IRQ_H_SW_MINOR_VER                 0
#define ETH_IRQ_H_SW_PATCH_VER                 0

/**
****************************************************************************************
 * @brief: Version Verify
****************************************************************************************
*/
#if (ETH_CFG_H_VENDOR_ID != ETH_IRQ_H_VENDOR_ID)
    #error " NON-MATCHED DATA : ETH_IRQ_H_VENDOR_ID "
#endif
#if (ETH_CFG_H_AR_REL_MAJOR_VER != ETH_IRQ_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_IRQ_H_AR_REL_MAJOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_MINOR_VER != ETH_IRQ_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_IRQ_H_AR_REL_MINOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_REV_VER != ETH_IRQ_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETH_IRQ_H_AR_REL_REV_VER "
#endif
#if (ETH_CFG_H_SW_MAJOR_VER != ETH_IRQ_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_IRQ_H_SW_MAJOR_VER "
#endif
#if (ETH_CFG_H_SW_MINOR_VER != ETH_IRQ_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_IRQ_H_SW_MINOR_VER "
#endif
#if (ETH_CFG_H_SW_PATCH_VER != ETH_IRQ_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETH_IRQ_H_SW_PATCH_VER "
#endif

#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ISR(ISR_DWMAC_0_TX);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ISR(ISR_DWMAC_0_RX);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */

#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ISR(ISR_GMAC_0_TX);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ISR(ISR_GMAC_0_RX);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */

#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP || RESOURCE_SUPPORT_ETH_GMAC_IP */

#ifdef __cplusplus
}
#endif

#endif /* ETH_IRQ_H */

/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : DSPI
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
*   @file    CDD_DSpi.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Dspi MCAL driver.
*
*   @addtogroup Dspi
*   @{
*/
/* PRQA S 1752 EOF */
#ifndef CDD_DSPI_H
#define CDD_DSPI_H

#ifdef __cplusplus
extern "C"{
#endif

#include "ComStack_Types.h"
#include "CDD_DSpi_Cfg.h"
#include "Mcal.h"
#include "dspi_LLDriver.h"

#define CDD_DSPI_H_VENDOR_ID                     176
#define CDD_DSPI_H_AR_REL_MAJOR_VER              4
#define CDD_DSPI_H_AR_REL_MINOR_VER              4
#define CDD_DSPI_H_AR_REL_REV_VER                0
#define CDD_DSPI_H_SW_MAJOR_VER                  3
#define CDD_DSPI_H_SW_MINOR_VER                  0
#define CDD_DSPI_H_SW_PATCH_VER                  0
#define CDD_DSPI_MODULE_ID                       108

#if (CDD_DSPI_VENDOR_ID_OUTPUT != CDD_DSPI_H_VENDOR_ID)
    #error " NON-MATCHED DATA : CDD_DSPI_H_VENDOR_ID "
#endif
#if (CDD_DSPI_AR_RELEASE_MAJOR_VERSION_OUTPUT != CDD_DSPI_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CDD_DSPI_H_AR_REL_MAJOR_VER "
#endif
#if (CDD_DSPI_AR_RELEASE_MINOR_VERSION_OUTPUT != CDD_DSPI_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CDD_DSPI_H_AR_REL_MINOR_VER "
#endif
#if (CDD_DSPI_AR_RELEASE_REVISION_VERSION_OUTPUT != CDD_DSPI_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CDD_DSPI_H_AR_REL_REV_VER "
#endif
#if (CDD_DSPI_SW_MAJOR_VERSION_OUTPUT != CDD_DSPI_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CDD_DSPI_H_SW_MAJOR_VER "
#endif
#if (CDD_DSPI_SW_MINOR_VERSION_OUTPUT != CDD_DSPI_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CDD_DSPI_H_SW_MINOR_VER "
#endif
#if (CDD_DSPI_SW_PATCH_VERSION_OUTPUT != CDD_DSPI_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CDD_DSPI_H_SW_PATCH_VER "
#endif

#define CDD_DSPI_SID_INIT                ((uint8)0x00U)
#define CDD_DSPI_DSI_SEND                ((uint8)0x01U)
#define CDD_DSPI_DSI_RECEIVE             ((uint8)0x02U)
#define CDD_DSPI_DSI_TSB_SEND            ((uint8)0x03U)
#define CDD_DSPI_DSI_SET_TRGPRD          ((uint8)0x04U)
#define CDD_DSPI_CSI_SEND                ((uint8)0x05U)
#define CDD_DSPI_DSI_PREFILL_ITBC_TX     ((uint8)0x06U)
#define CDD_DSPI_CSI_TSB_TX              ((uint8)0x07U)

#define CDD_DSPI_E_PARAM_POINTER         ((uint8)0x01U)
#define CDD_DSPI_E_PARAM_HANDLE          ((uint8)0x02U)
#define CDD_DSPI_E_PARAM_DATA_LENGTH     ((uint8)0x03U)
#define CDD_DSPI_E_PARAM_CONTROLLER      ((uint8)0x04U)
#define CDD_DSPI_E_UNINIT                ((uint8)0x05U)
#define CDD_DSPI_E_TRANSITION            ((uint8)0x06U)
#define CDD_DSPI_E_PARAM_BAUDRATE        ((uint8)0x07U)
#define CDD_DSPI_E_INIT_FAILED           ((uint8)0x08U)
#define CDD_DSPI_E_INVALID_CONTROLLER    ((uint8)0x0AU)
#define CDD_DSPI_E_PARAM_CONFIG          ((uint8)0x0BU)

#define CDD_DSPI_CORE_NUM   MCAL_CORE_NUM

typedef struct {
    P2CONST(spi_config_t, DSPI_CONST, DSPI_APPL_CONST)      dspiConfig;
#ifdef RESOURCE_SUPPORT_GTM_TO_MSC
#if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
    P2CONST(gtm_msc_set_sel_t, DSPI_CONST, DSPI_APPL_CONST) gtmMSCSetConfig;
#endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
#endif
    P2CONST(mdspi_core_map_t, DSPI_CONST, DSPI_APPL_CONST)  coreMap;
} CDD_DSpi_ConfigType;

#if (CDD_DSPI_PRECOMPILE_SUPPORT == STD_OFF)
CDD_DSPI_PB_CONFIG_DECLARATION
#else
extern CONST(CDD_DSpi_ConfigType, DSPI_VAR) CDD_DSpi_Config;
#endif

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) CDD_DSpi_Init(P2CONST(CDD_DSpi_ConfigType, AUTOMATIC, DSPI_APPL_CONST) Config);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) CDD_DSpi_DSI_Send
(
    VAR(uint8, AUTOMATIC) instance, 
    VAR(uint32, AUTOMATIC) n,  
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) txbuf, 
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) CDD_DSpi_DSI_Receive
(
    VAR(uint8, AUTOMATIC) instance, 
    VAR(uint32, AUTOMATIC) n, 
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) CDD_DSpi_DSI_TSB_Send
(
    VAR(uint8, AUTOMATIC) instance, 
    VAR(uint32, AUTOMATIC) n,  
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) txbuf, 
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) CDD_DSpi_CSI_Send
(
    VAR(uint8, AUTOMATIC) instance, 
    VAR(uint32, AUTOMATIC) spi_n, 
    VAR(uint32, AUTOMATIC) dsi_n, 
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) txbuf, 
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) txbuf1, 
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf, 
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf1
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) CDD_DSpi_SetDsiTRGPRD
(
    VAR(uint8, AUTOMATIC) instance, 
    VAR(uint32, AUTOMATIC) trig_period
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) CDD_DSpi_Cdsi_Prefill_ITBC_Tx
(
    VAR(uint8, AUTOMATIC) instance, 
    VAR(uint32, AUTOMATIC) spi_n, 
    VAR(uint32, AUTOMATIC) dsi_n, 
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) txbuf, 
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) txbuf1, 
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf, 
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf1
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) CDD_DSpi_LLD_CSI_TSB_Tx
(
    VAR(uint8, AUTOMATIC) instance,  
    VAR(uint32, AUTOMATIC) tsbcmd_n, 
    VAR(uint32, AUTOMATIC) tsbdata_n, 
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) tsbcmd, 
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) tsbdata
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#ifdef RESOURCE_SUPPORT_GTM_TO_MSC
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) CDD_DSpi_Start(VAR(uint8, AUTOMATIC) instance);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif

CDD_DSPI_PB_CONFIG_DECLARATION

#ifdef __cplusplus
}
#endif

#endif

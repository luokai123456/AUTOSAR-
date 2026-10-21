/**
*   @file    EcuM_Cbk.h
*   @version 3.0.0
*
*   @brief   AUTOSAR EcuM - module interface
*   @ecumails This file contains functions prototypes and data types of the AUTOSAR EcuM.
*            This file contains sample code only. It is not part of the production code deliverables
*
*   @addtogroup ECUM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : ECUM
*   Dependencies         : -
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : MPC577XM_MCAL_1_0_2_RTM_ASR_REL_4_0_REV_0003_20170922
*
*   (c) Copyright (c) 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017 CCFC.
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef ECUM_CBK_H
#define ECUM_CBK_H

#ifdef __cplusplus
extern "C" {
#endif
/*==============================================INCLUDE FILES=======================================*/
#include "EcuM_Cfg.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ECUM_CBK_VENDOR_ID 176
#define ECUM_CBK_MODULE_ID 10

#define ECUM_CBK_AR_RELEASE_MAJOR_VER       4
#define ECUM_CBK_AR_RELEASE_MINOR_VER       4
#define ECUM_CBK_AR_RELEASE_REVISION        0
#define ECUM_CBK_SW_MAJOR_VERSION           3
#define ECUM_CBK_SW_MINOR_VERSION           0
#define ECUM_CBK_SW_PATCH_VERSION           0

#ifdef MEM_MAP
#include "CompilerDefinition.h"
#ifdef S32DS_C_CCFC30XX
#define ECUM_START_SEC_CONFIG_DATA           __attribute__((section(".mcal_ecum_rodata")))
#define ECUM_STOP_SEC_CONFIG_DATA
#define ECUM_START_SEC_CODE                  __attribute__((section(".mcal_ecum_text")))
#define ECUM_STOP_SEC_CODE
#define ECUM_START_SEC_VAR_NO_INIT           __attribute__((section(".mcal_ecum_bss")))
#define ECUM_STOP_SEC_VAR_NO_INIT
#define ECUM_START_SEC_VAR_INIT              __attribute__((section(".mcal_ecum_data")))
#define ECUM_STOP_SEC_VAR_INIT
#define ECUM_START_SEC_VAR_SHARED_INIT       __attribute__((section(".mcal_ecum_share")))
#define ECUM_STOP_SEC_VAR_SHARED_INIT
#define ECUM_START_SEC_VAR_SHARED_NO_INIT    __attribute__((section(".mcal_ecum_bss_share")))
#define ECUM_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* S32DS_C_CCFC30XX */
#ifdef GHS_C_CCFC30XX
#define PRAGMA(x)                            _Pragma(#x)
#define ECUM_START_SEC_CONFIG_DATA           PRAGMA(ghs section rodata=".mcal_ecum_rodata")
#define ECUM_STOP_SEC_CONFIG_DATA            PRAGMA(ghs section)
#define ECUM_START_SEC_CODE                  PRAGMA(ghs section text=".mcal_ecum_text")
#define ECUM_STOP_SEC_CODE                   PRAGMA(ghs section)
#define ECUM_START_SEC_VAR_NO_INIT           PRAGMA(ghs section bss=".mcal_ecum_bss")
#define ECUM_STOP_SEC_VAR_NO_INIT            PRAGMA(ghs section)
#define ECUM_START_SEC_VAR_INIT              PRAGMA(ghs section data = ".mcal_ecum_data")
#define ECUM_STOP_SEC_VAR_INIT               PRAGMA(ghs section)
#define ECUM_START_SEC_VAR_SHARED_INIT       __attribute__((section(".mcal_ecum_share")))
#define ECUM_STOP_SEC_VAR_SHARED_INIT
#define ECUM_START_SEC_VAR_SHARED_NO_INIT    __attribute__((section(".mcal_ecum_bss_share")))
#define ECUM_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* GHS_C_CCFC30XX */
#ifdef HITECH_C_CCFC30XX
#define PRAGMA(x)                            _Pragma(#x)
#define ECUM_START_SEC_CONFIG_DATA           PRAGMA(section ".mcal_ecum_rodata" a)
#define ECUM_STOP_SEC_CONFIG_DATA            PRAGMA(section)
#define ECUM_START_SEC_CODE                  PRAGMA(section ".mcal_ecum_text" avx)
#define ECUM_STOP_SEC_CODE                   PRAGMA(section)
#define ECUM_START_SEC_VAR_NO_INIT           PRAGMA(section ".mcal_ecum_bss")
#define ECUM_STOP_SEC_VAR_NO_INIT            PRAGMA(section)
#define ECUM_START_SEC_VAR_INIT              PRAGMA(section ".mcal_ecum_data")
#define ECUM_STOP_SEC_VAR_INIT               PRAGMA(section)
#define ECUM_START_SEC_VAR_SHARED_INIT       PRAGMA(section ".mcal_ecum_share")
#define ECUM_STOP_SEC_VAR_SHARED_INIT        PRAGMA(section)
#define ECUM_START_SEC_VAR_SHARED_NO_INIT    PRAGMA(section ".mcal_ecum_bss_share")
#define ECUM_STOP_SEC_VAR_SHARED_NO_INIT     PRAGMA(section)
#endif /* HITECH_C_CCFC30XX */
#else
#define ECUM_START_SEC_CONFIG_DATA
#define ECUM_STOP_SEC_CONFIG_DATA
#define ECUM_START_SEC_CODE
#define ECUM_STOP_SEC_CODE
#define ECUM_START_SEC_VAR_NO_INIT
#define ECUM_STOP_SEC_VAR_NO_INIT
#define ECUM_START_SEC_VAR_INIT
#define ECUM_STOP_SEC_VAR_INIT
#define ECUM_START_SEC_VAR_SHARED_INIT
#define ECUM_STOP_SEC_VAR_SHARED_INIT
#define ECUM_START_SEC_VAR_SHARED_NO_INIT
#define ECUM_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* MEM_MAP */


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

#if (ECUM_CBK_VENDOR_ID != ECUM_CFG_VENDOR_ID)
#error "EcuM_Cbk.h and EcuM_Cfg.h have different vendor ids"
#endif

#if ((ECUM_CBK_AR_RELEASE_MAJOR_VER != ECUM_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ECUM_CBK_AR_RELEASE_MINOR_VER != ECUM_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ECUM_CBK_AR_RELEASE_REVISION != ECUM_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of EcuM_Cbk.h and EcuM_Cfg.h are different"
#endif

#if ((ECUM_CBK_SW_MAJOR_VERSION != ECUM_CFG_SW_MAJOR_VERSION) || \
     (ECUM_CBK_SW_MINOR_VERSION != ECUM_CFG_SW_MINOR_VERSION) || \
     (ECUM_CBK_SW_PATCH_VERSION != ECUM_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of EcuM_Cbk.h and EcuM_Cfg.h are different"
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/


ECUM_START_SEC_CODE
FUNC(void, ECUM_CODE) EcuM_SetWakeupEvent(VAR(EcuM_WakeupSourceType, AUTOMATIC) events);
ECUM_STOP_SEC_CODE

ECUM_START_SEC_CODE
FUNC(void, ECUM_CODE) EcuM_ValidateWakeupEvent(VAR(EcuM_WakeupSourceType, AUTOMATIC) events);
ECUM_STOP_SEC_CODE

ECUM_START_SEC_CODE
FUNC(void, ECUM_CODE) EcuM_CheckWakeup(VAR(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource);
ECUM_STOP_SEC_CODE

#ifdef __cplusplus
}
#endif

#endif /* ECUM_CBK_H */

/** @} */

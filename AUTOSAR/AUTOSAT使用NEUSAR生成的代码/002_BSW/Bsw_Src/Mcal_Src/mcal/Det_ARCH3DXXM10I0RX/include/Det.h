/**
 *   @file    Det.h
 *   @version 3.0.0
 *
 *   @brief   AUTOSAR Det - module interface.
 *   @details This file contains the functions prototypes and data types of the AUTOSAR Det.
 *            This file contains sample code only. It is not part of the production code deliverables
 *
 *   @addtogroup DET_MODULE
 *   @{
 */
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : Det
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : MPC577XM_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20170922
*
*   (c) Copyright (c) 2006-2016 Freescale Semiconductor, Inc.
*       Copyright 2017 CCFC.
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef DET_H
#define DET_H

#ifdef __cplusplus
extern "C"
{
#endif

    /*==================================================================================================
    *                                         INCLUDE FILES
    * 1) system and project includes
    * 2) needed interfaces from external units
    * 3) internal and external interfaces from this unit
    ==================================================================================================*/

    /*==================================================================================================
    *                               SOURCE FILE VERSION INFORMATION
    ==================================================================================================*/
    /**
     * @file           Det.h
     * @requirements   DET001_PI
     */
#define DET_VENDOR_ID                176
#define DET_MODULE_ID                15

#define DET_AR_RELEASE_MAJOR_VERSION 4
#define DET_AR_RELEASE_MINOR_VERSION 4
#define DET_AR_RELEASE_REVISION_VERSION 0
#define DET_SW_MAJOR_VERSION 3
#define DET_SW_MINOR_VERSION 0
#define DET_SW_PATCH_VERSION 0

#ifdef MEM_MAP
#include "CompilerDefinition.h"
#ifdef S32DS_C_CCFC30XX
#define DET_START_SEC_CONFIG_DATA           __attribute__((section(".mcal_det_rodata")))
#define DET_STOP_SEC_CONFIG_DATA
#define DET_START_SEC_CODE                  __attribute__((section(".mcal_det_text")))
#define DET_STOP_SEC_CODE
#define DET_START_SEC_VAR_NO_INIT           __attribute__((section(".mcal_det_bss")))
#define DET_STOP_SEC_VAR_NO_INIT
#define DET_START_SEC_VAR_INIT              __attribute__((section(".mcal_det_data")))
#define DET_STOP_SEC_VAR_INIT
#define DET_START_SEC_VAR_SHARED_INIT       __attribute__((section(".mcal_det_share")))
#define DET_STOP_SEC_VAR_SHARED_INIT
#define DET_START_SEC_VAR_SHARED_NO_INIT    __attribute__((section(".mcal_det_bss_share")))
#define DET_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* S32DS_C_CCFC30XX */
#ifdef GHS_C_CCFC30XX
#define PRAGMA(x)                           _Pragma(#x)
#define DET_START_SEC_CONFIG_DATA           PRAGMA(ghs section rodata=".mcal_det_rodata")
#define DET_STOP_SEC_CONFIG_DATA            PRAGMA(ghs section)
#define DET_START_SEC_CODE                  PRAGMA(ghs section text=".mcal_det_text")
#define DET_STOP_SEC_CODE                   PRAGMA(ghs section)
#define DET_START_SEC_VAR_NO_INIT           PRAGMA(ghs section bss=".mcal_det_bss")
#define DET_STOP_SEC_VAR_NO_INIT            PRAGMA(ghs section)
#define DET_START_SEC_VAR_INIT              PRAGMA(ghs section data = ".mcal_det_data")
#define DET_STOP_SEC_VAR_INIT               PRAGMA(ghs section)
#define DET_START_SEC_VAR_SHARED_INIT       __attribute__((section(".mcal_det_share")))
#define DET_STOP_SEC_VAR_SHARED_INIT
#define DET_START_SEC_VAR_SHARED_NO_INIT    __attribute__((section(".mcal_det_bss_share")))
#define DET_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* GHS_C_CCFC30XX */
#ifdef HITECH_C_CCFC30XX
#define PRAGMA(x)                           _Pragma(#x)
#define DET_START_SEC_CONFIG_DATA           PRAGMA(section ".mcal_det_rodata" a)
#define DET_STOP_SEC_CONFIG_DATA            PRAGMA(section)
#define DET_START_SEC_CODE                  PRAGMA(section ".mcal_det_text" avx)
#define DET_STOP_SEC_CODE                   PRAGMA(section)
#define DET_START_SEC_VAR_NO_INIT           PRAGMA(section ".mcal_det_bss")
#define DET_STOP_SEC_VAR_NO_INIT            PRAGMA(section)
#define DET_START_SEC_VAR_INIT              PRAGMA(section ".mcal_det_data")
#define DET_STOP_SEC_VAR_INIT               PRAGMA(section)
#define DET_START_SEC_VAR_SHARED_INIT       PRAGMA(section ".mcal_det_share")
#define DET_STOP_SEC_VAR_SHARED_INIT        PRAGMA(section)
#define DET_START_SEC_VAR_SHARED_NO_INIT    PRAGMA(section ".mcal_det_bss_share")
#define DET_STOP_SEC_VAR_SHARED_NO_INIT     PRAGMA(section)
#endif /* HITECH_C_CCFC30XX */
#else
#define DET_START_SEC_CONFIG_DATA
#define DET_STOP_SEC_CONFIG_DATA
#define DET_START_SEC_CODE
#define DET_STOP_SEC_CODE
#define DET_START_SEC_VAR_NO_INIT
#define DET_STOP_SEC_VAR_NO_INIT
#define DET_START_SEC_VAR_INIT
#define DET_STOP_SEC_VAR_INIT
#define DET_START_SEC_VAR_SHARED_INIT
#define DET_STOP_SEC_VAR_SHARED_INIT
#define DET_START_SEC_VAR_SHARED_NO_INIT
#define DET_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* MEM_MAP */




/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

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
extern VAR(uint8, DET_VAR) Det_InstanceId; /**< @brief DET instance ID*/
extern VAR(uint8, DET_VAR) Det_ApiId;      /**< @brief DET API ID*/
extern VAR(uint8, DET_VAR) Det_ErrorId;        /**< @brief DET Error ID*/

extern VAR(uint16, DET_VAR) Det_ModuleId; /**< @brief DET module ID*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
DET_START_SEC_CODE
FUNC(void, DET_CODE)Det_Init(void);
DET_STOP_SEC_CODE

DET_START_SEC_CODE
FUNC(Std_ReturnType, DET_CODE)Det_ReportError(VAR(uint16, AUTOMATIC) ModuleId, VAR(uint8, AUTOMATIC) InstanceId, VAR(uint8, AUTOMATIC) ApiId, VAR(uint8, AUTOMATIC) ErrorId);
DET_STOP_SEC_CODE

DET_START_SEC_CODE
FUNC(Std_ReturnType, DET_CODE) Det_ReportRuntimeError(VAR(uint16, AUTOMATIC) ModuleId, VAR(uint8, AUTOMATIC) InstanceId, VAR(uint8, AUTOMATIC) ApiId, VAR(uint8, AUTOMATIC) ErrorId);
DET_STOP_SEC_CODE

DET_START_SEC_CODE
FUNC(Std_ReturnType, DET_CODE) Det_ReportTransientFault(VAR(uint16, AUTOMATIC) ModuleId, VAR(uint8, AUTOMATIC) InstanceId, VAR(uint8, AUTOMATIC) ApiId, VAR(uint8, AUTOMATIC) FaultId);
DET_STOP_SEC_CODE

DET_START_SEC_CODE
FUNC(void, DET_CODE)Det_Start(void);
DET_STOP_SEC_CODE

#ifdef __cplusplus
}
#endif

#endif

/** @} */

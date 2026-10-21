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
*   Autosar Revision     : 
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*  
*****************************************************************************/

/**
*   @file    EthTrcv.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of EthTrcv
*
*   @addtogroup EthTrcv
*   @{
*/
#ifndef ETHTRCV_H
#define ETHTRCV_H
#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section EthTrcv_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section [global] 
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 character significance 
* and case  sensitivity are supported for external identifiers.
* All compilers used support more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. 
* All compilers used support more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros,
* objects and functions shall not be reused. All defines starting with upper
* letter E are reserved for future use inside <error.h> header file.
* All module define options and enumerations are restricted by coding rules
* and must follow format <MSN>_<NAME> where MSN is equal to ETHTRCV.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "derivative.h"
#if (defined(RESOURCE_SUPPORT_ETH_EMAC_IP) || defined(RESOURCE_SUPPORT_ETH_GMAC_IP))
#include "Eth.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ETHTRCV_H_VENDOR_ID                    176
#define ETHTRCV_H_AR_REL_MAJOR_VER             4
#define ETHTRCV_H_AR_REL_MINOR_VER             4
#define ETHTRCV_H_AR_REL_REV_VER               0
#define ETHTRCV_H_SW_MAJOR_VER                 3
#define ETHTRCV_H_SW_MINOR_VER                 0
#define ETHTRCV_H_SW_PATCH_VER                 0
#define ETHTRCV_MODULE_ID                      73

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (ETH_CFG_H_VENDOR_ID != ETHTRCV_H_VENDOR_ID)
    #error " NON-MATCHED DATA : ETHTRCV_H_VENDOR_ID "
#endif
#if (ETH_CFG_H_AR_REL_MAJOR_VER != ETHTRCV_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETHTRCV_H_AR_REL_MAJOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_MINOR_VER != ETHTRCV_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETHTRCV_H_AR_REL_MINOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_REV_VER != ETHTRCV_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETHTRCV_H_AR_REL_REV_VER "
#endif
#if (ETH_CFG_H_SW_MAJOR_VER != ETHTRCV_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETHTRCV_H_SW_MAJOR_VER "
#endif
#if (ETH_CFG_H_SW_MINOR_VER != ETHTRCV_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETHTRCV_H_SW_MINOR_VER "
#endif
#if (ETH_CFG_H_SW_PATCH_VER != ETHTRCV_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETHTRCV_H_SW_PATCH_VER "
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef MEM_MAP
#include "CompilerDefinition.h"
#ifdef S32DS_C_CCFC30XX
#define ETHTRCV_START_SEC_CONFIG_DATA           __attribute__ ((section (".mcal_ethtrcv_rodata")))
#define ETHTRCV_STOP_SEC_CONFIG_DATA
#define ETHTRCV_START_SEC_CODE                  __attribute__ ((section (".mcal_ethtrcv_text")))
#define ETHTRCV_STOP_SEC_CODE
#define ETHTRCV_START_SEC_VAR_NO_INIT           __attribute__ ((section (".mcal_ethtrcv_bss")))
#define ETHTRCV_STOP_SEC_VAR_NO_INIT
#define ETHTRCV_START_SEC_VAR_INIT              __attribute__ ((section (".mcal_ethtrcv_data")))
#define ETHTRCV_STOP_SEC_VAR_INIT
#define ETHTRCV_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".mcal_ethtrcv_share")))
#define ETHTRCV_STOP_SEC_VAR_SHARED_INIT
#define ETHTRCV_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".mcal_ethtrcv_bss_share")))
#define ETHTRCV_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* S32DS_C_CCFC30XX */
#ifdef GHS_C_CCFC30XX
#define PRAGMA(x)                               _Pragma(#x)
#define ETHTRCV_START_SEC_CONFIG_DATA           PRAGMA(ghs section rodata=".mcal_ethtrcv_rodata")
#define ETHTRCV_STOP_SEC_CONFIG_DATA            PRAGMA(ghs section)
#define ETHTRCV_START_SEC_CODE                  PRAGMA(ghs section text=".mcal_ethtrcv_text")
#define ETHTRCV_STOP_SEC_CODE                   PRAGMA(ghs section)
#define ETHTRCV_START_SEC_VAR_NO_INIT           PRAGMA(ghs section bss=".mcal_ethtrcv_bss")
#define ETHTRCV_STOP_SEC_VAR_NO_INIT            PRAGMA(ghs section)
#define ETHTRCV_START_SEC_VAR_INIT              PRAGMA(ghs section data = ".mcal_ethtrcv_data")
#define ETHTRCV_STOP_SEC_VAR_INIT               PRAGMA(ghs section)
#define ETHTRCV_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".mcal_ethtrcv_share")))
#define ETHTRCV_STOP_SEC_VAR_SHARED_INIT
#define ETHTRCV_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".mcal_ethtrcv_bss_share")))
#define ETHTRCV_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* GHS_C_CCFC30XX */
#ifdef HITECH_C_CCFC30XX
#define PRAGMA(x)                               _Pragma(#x)
#define ETHTRCV_START_SEC_CONFIG_DATA           PRAGMA(section ".mcal_ethtrcv_rodata" a)
#define ETHTRCV_STOP_SEC_CONFIG_DATA            PRAGMA(section)
#define ETHTRCV_START_SEC_CODE                  PRAGMA(section ".mcal_ethtrcv_text" avx)
#define ETHTRCV_STOP_SEC_CODE                   PRAGMA(section)
#define ETHTRCV_START_SEC_VAR_NO_INIT           PRAGMA(section ".mcal_ethtrcv_bss")
#define ETHTRCV_STOP_SEC_VAR_NO_INIT            PRAGMA(section)
#define ETHTRCV_START_SEC_VAR_INIT              PRAGMA(section ".mcal_ethtrcv_data")
#define ETHTRCV_STOP_SEC_VAR_INIT               PRAGMA(section)
#define ETHTRCV_START_SEC_VAR_SHARED_INIT       PRAGMA(section ".mcal_ethtrcv_share")
#define ETHTRCV_STOP_SEC_VAR_SHARED_INIT        PRAGMA(section)
#define ETHTRCV_START_SEC_VAR_SHARED_NO_INIT    PRAGMA(section ".mcal_ethtrcv_bss_share")
#define ETHTRCV_STOP_SEC_VAR_SHARED_NO_INIT     PRAGMA(section)
#endif /* HITECH_C_CCFC30XX */
#else
#include "CompilerDefinition.h"
#ifdef S32DS_C_CCFC30XX
#define ETHTRCV_START_SEC_CONFIG_DATA
#define ETHTRCV_STOP_SEC_CONFIG_DATA
#define ETHTRCV_START_SEC_CODE
#define ETHTRCV_STOP_SEC_CODE
#define ETHTRCV_START_SEC_VAR_NO_INIT
#define ETHTRCV_STOP_SEC_VAR_NO_INIT
#define ETHTRCV_START_SEC_VAR_INIT
#define ETHTRCV_STOP_SEC_VAR_INIT
#define ETHTRCV_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".data_share")))
#define ETHTRCV_STOP_SEC_VAR_SHARED_INIT
#define ETHTRCV_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".bss_share")))
#define ETHTRCV_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* S32DS_C_CCFC30XX */
#ifdef GHS_C_CCFC30XX
#define PRAGMA(x)                               _Pragma(#x)
#define ETHTRCV_START_SEC_CONFIG_DATA
#define ETHTRCV_STOP_SEC_CONFIG_DATA
#define ETHTRCV_START_SEC_CODE
#define ETHTRCV_STOP_SEC_CODE
#define ETHTRCV_START_SEC_VAR_NO_INIT
#define ETHTRCV_STOP_SEC_VAR_NO_INIT
#define ETHTRCV_START_SEC_VAR_INIT
#define ETHTRCV_STOP_SEC_VAR_INIT
#define ETHTRCV_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".data_share")))
#define ETHTRCV_STOP_SEC_VAR_SHARED_INIT
#define ETHTRCV_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".bss_share")))
#define ETHTRCV_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* GHS_C_CCFC30XX */
#ifdef HITECH_C_CCFC30XX
#define PRAGMA(x)                               _Pragma(#x)
#define ETHTRCV_START_SEC_CONFIG_DATA           PRAGMA(section ".rodata" a)
#define ETHTRCV_STOP_SEC_CONFIG_DATA            PRAGMA(section)
#define ETHTRCV_START_SEC_CODE                  PRAGMA(section ".text" avx)
#define ETHTRCV_STOP_SEC_CODE                   PRAGMA(section)
#define ETHTRCV_START_SEC_VAR_NO_INIT           PRAGMA(section ".bss")
#define ETHTRCV_STOP_SEC_VAR_NO_INIT            PRAGMA(section)
#define ETHTRCV_START_SEC_VAR_INIT              PRAGMA(section ".data")
#define ETHTRCV_STOP_SEC_VAR_INIT               PRAGMA(section)
#define ETHTRCV_START_SEC_VAR_SHARED_INIT       PRAGMA(section ".data_share")
#define ETHTRCV_STOP_SEC_VAR_SHARED_INIT        PRAGMA(section)
#define ETHTRCV_START_SEC_VAR_SHARED_NO_INIT    PRAGMA(section ".bss_share")
#define ETHTRCV_STOP_SEC_VAR_SHARED_NO_INIT     PRAGMA(section)
#endif /* HITECH_C_CCFC30XX */
#endif /* MEM_MAP */

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
ETHTRCV_START_SEC_CODE
extern FUNC(void, ETHTRCV_CODE)EthTrcv_ReadMiiIndication \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) TrcvIdx, \
    VAR(uint8, AUTOMATIC) RegIdx, \
    VAR(uint16, AUTOMATIC) RegVal \
);
ETHTRCV_STOP_SEC_CODE

ETHTRCV_START_SEC_CODE
extern FUNC(void, ETHTRCV_CODE)EthTrcv_WriteMiiIndication \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) TrcvIdx, \
    VAR(uint8, AUTOMATIC) RegIdx \
);
ETHTRCV_STOP_SEC_CODE

#ifdef __cplusplus
}
#endif                                              

#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP || RESOURCE_SUPPORT_ETH_GMAC_IP */

#endif /* ETHTRCV_H */
/** @} */

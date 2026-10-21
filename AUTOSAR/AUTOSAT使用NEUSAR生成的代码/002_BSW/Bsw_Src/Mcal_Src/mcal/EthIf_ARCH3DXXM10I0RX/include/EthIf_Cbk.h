/**************************************************************************** 
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
*   @file    EthIf_Cbk.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of EthIf.
*
*   @addtogroup EthIf
*   @{
*/
#ifndef ETHIF_CBK_H
  #define ETHIF_CBK_H
#ifdef __cplusplus
extern "C"{
#endif


#include "derivative.h"
#if (defined(RESOURCE_SUPPORT_ETH_EMAC_IP) || defined(RESOURCE_SUPPORT_ETH_GMAC_IP))
#include "Eth_GeneralTypes.h"
#include "Eth_Cfg.h"
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
  /* Common types for all communication modules*/
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETHIF_CBK_H_VENDOR_ID                    176
#define ETHIF_CBK_H_AR_REL_MAJOR_VER             4
#define ETHIF_CBK_H_AR_REL_MINOR_VER             4
#define ETHIF_CBK_H_AR_REL_REV_VER               0
#define ETHIF_CBK_H_SW_MAJOR_VER                 3
#define ETHIF_CBK_H_SW_MINOR_VER                 0
#define ETHIF_CBK_H_SW_PATCH_VER                 0
#define ETHIF_CBK_MODULE_ID                      65


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (ETH_CFG_H_VENDOR_ID != ETHIF_CBK_H_VENDOR_ID)
    #error " NON-MATCHED DATA : ETHIF_CBK_H_VENDOR_ID "
#endif
#if (ETH_CFG_H_AR_REL_MAJOR_VER != ETHIF_CBK_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETHIF_CBK_H_AR_REL_MAJOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_MINOR_VER != ETHIF_CBK_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETHIF_CBK_H_AR_REL_MINOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_REV_VER != ETHIF_CBK_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETHIF_CBK_H_AR_REL_REV_VER "
#endif
#if (ETH_CFG_H_SW_MAJOR_VER != ETHIF_CBK_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETHIF_CBK_H_SW_MAJOR_VER "
#endif
#if (ETH_CFG_H_SW_MINOR_VER != ETHIF_CBK_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETHIF_CBK_H_SW_MINOR_VER "
#endif
#if (ETH_CFG_H_SW_PATCH_VER != ETHIF_CBK_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETHIF_CBK_H_SW_PATCH_VER "
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
#define ETHIF_START_SEC_CONFIG_DATA           __attribute__ ((section (".mcal_ethif_rodata")))
#define ETHIF_STOP_SEC_CONFIG_DATA
#define ETHIF_START_SEC_CODE                  __attribute__ ((section (".mcal_ethif_text")))
#define ETHIF_STOP_SEC_CODE
#define ETHIF_START_SEC_VAR_NO_INIT           __attribute__ ((section (".mcal_ethif_bss")))
#define ETHIF_STOP_SEC_VAR_NO_INIT
#define ETHIF_START_SEC_VAR_INIT              __attribute__ ((section (".mcal_ethif_data")))
#define ETHIF_STOP_SEC_VAR_INIT
#define ETHIF_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".mcal_ethif_share")))
#define ETHIF_STOP_SEC_VAR_SHARED_INIT
#define ETHIF_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".mcal_ethif_bss_share")))
#define ETHIF_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* S32DS_C_CCFC30XX */
#ifdef GHS_C_CCFC30XX
#define PRAGMA(x)                             _Pragma(#x)
#define ETHIF_START_SEC_CONFIG_DATA           PRAGMA(ghs section rodata=".mcal_ethif_rodata")
#define ETHIF_STOP_SEC_CONFIG_DATA            PRAGMA(ghs section)
#define ETHIF_START_SEC_CODE                  PRAGMA(ghs section text=".mcal_ethif_text")
#define ETHIF_STOP_SEC_CODE                   PRAGMA(ghs section)
#define ETHIF_START_SEC_VAR_NO_INIT           PRAGMA(ghs section bss=".mcal_ethif_bss")
#define ETHIF_STOP_SEC_VAR_NO_INIT            PRAGMA(ghs section)
#define ETHIF_START_SEC_VAR_INIT              PRAGMA(ghs section data = ".mcal_ethif_data")
#define ETHIF_STOP_SEC_VAR_INIT               PRAGMA(ghs section)
#define ETHIF_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".mcal_ethif_share")))
#define ETHIF_STOP_SEC_VAR_SHARED_INIT
#define ETHIF_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".mcal_ethif_bss_share")))
#define ETHIF_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* GHS_C_CCFC30XX */
#ifdef HITECH_C_CCFC30XX
#define PRAGMA(x)                             _Pragma(#x)
#define ETHIF_START_SEC_CONFIG_DATA           PRAGMA(section ".mcal_ethif_rodata" a)
#define ETHIF_STOP_SEC_CONFIG_DATA            PRAGMA(section)
#define ETHIF_START_SEC_CODE                  PRAGMA(section ".mcal_ethif_text" avx)
#define ETHIF_STOP_SEC_CODE                   PRAGMA(section)
#define ETHIF_START_SEC_VAR_NO_INIT           PRAGMA(section ".mcal_ethif_bss")
#define ETHIF_STOP_SEC_VAR_NO_INIT            PRAGMA(section)
#define ETHIF_START_SEC_VAR_INIT              PRAGMA(section ".mcal_ethif_data")
#define ETHIF_STOP_SEC_VAR_INIT               PRAGMA(section)
#define ETHIF_START_SEC_VAR_SHARED_INIT       PRAGMA(section ".mcal_ethif_share")
#define ETHIF_STOP_SEC_VAR_SHARED_INIT        PRAGMA(section)
#define ETHIF_START_SEC_VAR_SHARED_NO_INIT    PRAGMA(section ".mcal_ethif_bss_share")
#define ETHIF_STOP_SEC_VAR_SHARED_NO_INIT     PRAGMA(section)
#endif /* HITECH_C_CCFC30XX */
#else
#include "CompilerDefinition.h"
#ifdef S32DS_C_CCFC30XX
#define ETHIF_START_SEC_CONFIG_DATA
#define ETHIF_STOP_SEC_CONFIG_DATA
#define ETHIF_START_SEC_CODE
#define ETHIF_STOP_SEC_CODE
#define ETHIF_START_SEC_VAR_NO_INIT
#define ETHIF_STOP_SEC_VAR_NO_INIT
#define ETHIF_START_SEC_VAR_INIT
#define ETHIF_STOP_SEC_VAR_INIT
#define ETHIF_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".data_share")))
#define ETHIF_STOP_SEC_VAR_SHARED_INIT
#define ETHIF_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".bss_share")))
#define ETHIF_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* S32DS_C_CCFC30XX */
#ifdef GHS_C_CCFC30XX
#define PRAGMA(x)                             _Pragma(#x)
#define ETHIF_START_SEC_CONFIG_DATA
#define ETHIF_STOP_SEC_CONFIG_DATA
#define ETHIF_START_SEC_CODE
#define ETHIF_STOP_SEC_CODE
#define ETHIF_START_SEC_VAR_NO_INIT
#define ETHIF_STOP_SEC_VAR_NO_INIT
#define ETHIF_START_SEC_VAR_INIT
#define ETHIF_STOP_SEC_VAR_INIT
#define ETHIF_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".data_share")))
#define ETHIF_STOP_SEC_VAR_SHARED_INIT
#define ETHIF_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".bss_share")))
#define ETHIF_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* GHS_C_CCFC30XX */
#ifdef HITECH_C_CCFC30XX
#define PRAGMA(x)                             _Pragma(#x)
#define ETHIF_START_SEC_CONFIG_DATA           PRAGMA(section ".rodata" a)
#define ETHIF_STOP_SEC_CONFIG_DATA            PRAGMA(section)
#define ETHIF_START_SEC_CODE                  PRAGMA(section ".text" avx)
#define ETHIF_STOP_SEC_CODE                   PRAGMA(section)
#define ETHIF_START_SEC_VAR_NO_INIT           PRAGMA(section ".bss")
#define ETHIF_STOP_SEC_VAR_NO_INIT            PRAGMA(section)
#define ETHIF_START_SEC_VAR_INIT              PRAGMA(section ".data")
#define ETHIF_STOP_SEC_VAR_INIT               PRAGMA(section)
#define ETHIF_START_SEC_VAR_SHARED_INIT       PRAGMA(section ".data_share")
#define ETHIF_STOP_SEC_VAR_SHARED_INIT        PRAGMA(section)
#define ETHIF_START_SEC_VAR_SHARED_NO_INIT    PRAGMA(section ".bss_share")
#define ETHIF_STOP_SEC_VAR_SHARED_NO_INIT     PRAGMA(section)
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
ETHIF_START_SEC_VAR_NO_INIT
extern volatile VAR(uint32, AUTOMATIC) Eth_TestFlag;
ETHIF_STOP_SEC_VAR_NO_INIT
ETHIF_START_SEC_VAR_NO_INIT
extern volatile VAR(uint32, AUTOMATIC) Eth_TestStopFlag;
ETHIF_STOP_SEC_VAR_NO_INIT
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

ETHIF_START_SEC_CODE
FUNC(void, ETH_CODE) EthIf_RxIndication \
(\
    VAR(uint8, AUTOMATIC) CtrlIdx,\
    VAR(Eth_FrameType, AUTOMATIC) FrameType, \
    VAR(boolean, AUTOMATIC) IsBroadcast, \
    P2CONST(uint8, AUTOMATIC, ETHIF_APPL_CONST) PhysAddrPtr, \
    P2CONST(Eth_DataType, AUTOMATIC, ETHIF_APPL_CONST) DataPtr,\
    VAR(uint16, AUTOMATIC) LenByte \
);
ETHIF_STOP_SEC_CODE

ETHIF_START_SEC_CODE
FUNC(void, ETH_CODE) EthIf_TxConfirmation \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) BufIdx, \
    VAR(Std_ReturnType, AUTOMATIC) Result \
);
ETHIF_STOP_SEC_CODE

ETHIF_START_SEC_CODE
FUNC(void, ETH_CODE) EthIf_CtrlModeIndication \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(Eth_ModeType, AUTOMATIC) CtrlMode \
);
ETHIF_STOP_SEC_CODE

#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP || RESOURCE_SUPPORT_ETH_GMAC_IP */

#ifdef __cplusplus
}
#endif                                              

#endif /* ETHIF_CBK_H */
/** @} */

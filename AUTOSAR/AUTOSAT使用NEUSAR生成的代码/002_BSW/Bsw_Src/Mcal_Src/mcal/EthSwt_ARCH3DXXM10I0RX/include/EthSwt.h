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
*   @file    EthSwt.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of EthSwt
*
*   @addtogroup EthSwt
*   @{
*/

#ifndef ETHSWT_H
#define ETHSWT_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/

#include "derivative.h"
#if (defined(RESOURCE_SUPPORT_ETH_EMAC_IP) || defined(RESOURCE_SUPPORT_ETH_GMAC_IP))
/*Eth.h includes Eth_GeneralTypes.h*/
#include "Eth.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/** @implements EthSwt_Version_define */
#define ETHSWT_H_VENDOR_ID                    176
#define ETHSWT_H_AR_REL_MAJOR_VER             4
#define ETHSWT_H_AR_REL_MINOR_VER             4
#define ETHSWT_H_AR_REL_REV_VER               0
#define ETHSWT_H_SW_MAJOR_VER                 3
#define ETHSWT_H_SW_MINOR_VER                 0
#define ETHSWT_H_SW_PATCH_VER                 0
#define ETHSWT_MODULE_ID                      89

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (ETH_CFG_H_VENDOR_ID != ETHSWT_H_VENDOR_ID)
    #error " NON-MATCHED DATA : ETHSWT_H_VENDOR_ID "
#endif
#if (ETH_CFG_H_AR_REL_MAJOR_VER != ETHSWT_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETHSWT_H_AR_REL_MAJOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_MINOR_VER != ETHSWT_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETHSWT_H_AR_REL_MINOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_REV_VER != ETHSWT_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETHSWT_H_AR_REL_REV_VER "
#endif
#if (ETH_CFG_H_SW_MAJOR_VER != ETHSWT_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETHSWT_H_SW_MAJOR_VER "
#endif
#if (ETH_CFG_H_SW_MINOR_VER != ETHSWT_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETHSWT_H_SW_MINOR_VER "
#endif
#if (ETH_CFG_H_SW_PATCH_VER != ETHSWT_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETHSWT_H_SW_PATCH_VER "
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#ifdef MEM_MAP
#include "CompilerDefinition.h"
#ifdef S32DS_C_CCFC30XX
#define ETHSWT_START_SEC_CONFIG_DATA           __attribute__ ((section (".mcal_ethswt_rodata")))
#define ETHSWT_STOP_SEC_CONFIG_DATA
#define ETHSWT_START_SEC_CODE                  __attribute__ ((section (".mcal_ethswt_text")))
#define ETHSWT_STOP_SEC_CODE
#define ETHSWT_START_SEC_VAR_NO_INIT           __attribute__ ((section (".mcal_ethswt_bss")))
#define ETHSWT_STOP_SEC_VAR_NO_INIT
#define ETHSWT_START_SEC_VAR_INIT              __attribute__ ((section (".mcal_ethswt_data")))
#define ETHSWT_STOP_SEC_VAR_INIT
#define ETHSWT_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".mcal_ethswt_share")))
#define ETHSWT_STOP_SEC_VAR_SHARED_INIT
#define ETHSWT_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".mcal_ethswt_bss_share")))
#define ETHSWT_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* S32DS_C_CCFC30XX */
#ifdef GHS_C_CCFC30XX
#define PRAGMA(x)                              _Pragma(#x)
#define ETHSWT_START_SEC_CONFIG_DATA           PRAGMA(ghs section rodata=".mcal_ethswt_rodata")
#define ETHSWT_STOP_SEC_CONFIG_DATA            PRAGMA(ghs section)
#define ETHSWT_START_SEC_CODE                  PRAGMA(ghs section text=".mcal_ethswt_text")
#define ETHSWT_STOP_SEC_CODE                   PRAGMA(ghs section)
#define ETHSWT_START_SEC_VAR_NO_INIT           PRAGMA(ghs section bss=".mcal_ethswt_bss")
#define ETHSWT_STOP_SEC_VAR_NO_INIT            PRAGMA(ghs section)
#define ETHSWT_START_SEC_VAR_INIT              PRAGMA(ghs section data = ".mcal_ethswt_data")
#define ETHSWT_STOP_SEC_VAR_INIT               PRAGMA(ghs section)
#define ETHSWT_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".mcal_ethswt_share")))
#define ETHSWT_STOP_SEC_VAR_SHARED_INIT
#define ETHSWT_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".mcal_ethswt_bss_share")))
#define ETHSWT_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* GHS_C_CCFC30XX */
#ifdef HITECH_C_CCFC30XX
#define PRAGMA(x)                              _Pragma(#x)
#define ETHSWT_START_SEC_CONFIG_DATA           PRAGMA(section ".mcal_ethswt_rodata" a)
#define ETHSWT_STOP_SEC_CONFIG_DATA            PRAGMA(section)
#define ETHSWT_START_SEC_CODE                  PRAGMA(section ".mcal_ethswt_text" avx)
#define ETHSWT_STOP_SEC_CODE                   PRAGMA(section)
#define ETHSWT_START_SEC_VAR_NO_INIT           PRAGMA(section ".mcal_ethswt_bss")
#define ETHSWT_STOP_SEC_VAR_NO_INIT            PRAGMA(section)
#define ETHSWT_START_SEC_VAR_INIT              PRAGMA(section ".mcal_ethswt_data")
#define ETHSWT_STOP_SEC_VAR_INIT               PRAGMA(section)
#define ETHSWT_START_SEC_VAR_SHARED_INIT       PRAGMA(section ".mcal_ethswt_share")
#define ETHSWT_STOP_SEC_VAR_SHARED_INIT        PRAGMA(section)
#define ETHSWT_START_SEC_VAR_SHARED_NO_INIT    PRAGMA(section ".mcal_ethswt_bss_share")
#define ETHSWT_STOP_SEC_VAR_SHARED_NO_INIT     PRAGMA(section)
#endif /* HITECH_C_CCFC30XX */
#else
#include "CompilerDefinition.h"
#ifdef S32DS_C_CCFC30XX
#define ETHSWT_START_SEC_CONFIG_DATA
#define ETHSWT_STOP_SEC_CONFIG_DATA
#define ETHSWT_START_SEC_CODE
#define ETHSWT_STOP_SEC_CODE
#define ETHSWT_START_SEC_VAR_NO_INIT
#define ETHSWT_STOP_SEC_VAR_NO_INIT
#define ETHSWT_START_SEC_VAR_INIT
#define ETHSWT_STOP_SEC_VAR_INIT
#define ETHSWT_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".data_share")))
#define ETHSWT_STOP_SEC_VAR_SHARED_INIT
#define ETHSWT_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".bss_share")))
#define ETHSWT_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* S32DS_C_CCFC30XX */
#ifdef GHS_C_CCFC30XX
#define PRAGMA(x)                              _Pragma(#x)
#define ETHSWT_START_SEC_CONFIG_DATA
#define ETHSWT_STOP_SEC_CONFIG_DATA
#define ETHSWT_START_SEC_CODE
#define ETHSWT_STOP_SEC_CODE
#define ETHSWT_START_SEC_VAR_NO_INIT
#define ETHSWT_STOP_SEC_VAR_NO_INIT
#define ETHSWT_START_SEC_VAR_INIT
#define ETHSWT_STOP_SEC_VAR_INIT
#define ETHSWT_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".data_share")))
#define ETHSWT_STOP_SEC_VAR_SHARED_INIT
#define ETHSWT_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".bss_share")))
#define ETHSWT_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* GHS_C_CCFC30XX */
#ifdef HITECH_C_CCFC30XX
#define PRAGMA(x)                              _Pragma(#x)
#define ETHSWT_START_SEC_CONFIG_DATA           PRAGMA(section ".rodata" a)
#define ETHSWT_STOP_SEC_CONFIG_DATA            PRAGMA(section)
#define ETHSWT_START_SEC_CODE                  PRAGMA(section ".text" avx)
#define ETHSWT_STOP_SEC_CODE                   PRAGMA(section)
#define ETHSWT_START_SEC_VAR_NO_INIT           PRAGMA(section ".bss")
#define ETHSWT_STOP_SEC_VAR_NO_INIT            PRAGMA(section)
#define ETHSWT_START_SEC_VAR_INIT              PRAGMA(section ".data")
#define ETHSWT_STOP_SEC_VAR_INIT               PRAGMA(section)
#define ETHSWT_START_SEC_VAR_SHARED_INIT       PRAGMA(section ".data_share")
#define ETHSWT_STOP_SEC_VAR_SHARED_INIT        PRAGMA(section)
#define ETHSWT_START_SEC_VAR_SHARED_NO_INIT    PRAGMA(section ".bss_share")
#define ETHSWT_STOP_SEC_VAR_SHARED_NO_INIT     PRAGMA(section)
#endif /* HITECH_C_CCFC30XX */
#endif /* MEM_MAP */
/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
ETHSWT_START_SEC_CODE
extern FUNC(Std_ReturnType, ETHSWT_CODE) EthSwt_EthRxProcessFrame( VAR(uint8, AUTOMATIC) CtrlIdx, 
                                                            VAR(Eth_BufIdxType, AUTOMATIC) BufIdx, 
                                                            P2P2VAR(uint8, AUTOMATIC, ETHSWT_APPL_DATA) DataPtr, 
                                                            P2VAR(uint16, AUTOMATIC, ETHSWT_APPL_DATA) LengthPtr, 
                                                            P2VAR(boolean, AUTOMATIC, ETHSWT_APPL_DATA) IsMgmtFrameOnlyPtr
                                                          );
ETHSWT_STOP_SEC_CODE

ETHSWT_START_SEC_CODE
extern FUNC( Std_ReturnType, ETHSWT_CODE) EthSwt_EthRxFinishedIndication(VAR(uint8, AUTOMATIC) CtrlIdx, VAR(Eth_BufIdxType, AUTOMATIC) BufIdx);
ETHSWT_STOP_SEC_CODE

ETHSWT_START_SEC_CODE
extern FUNC( Std_ReturnType, ETHSWT_CODE) EthSwt_EthTxPrepareFrame( VAR(uint8, AUTOMATIC) CtrlIdx, 
                                                             VAR(Eth_BufIdxType, AUTOMATIC) BufIdx,
                                                             P2P2VAR(uint8, AUTOMATIC, ETHSWT_APPL_DATA) DataPtr, 
                                                             P2VAR(uint16, AUTOMATIC, ETHSWT_APPL_DATA) LengthPtr
                                                           );
ETHSWT_STOP_SEC_CODE

ETHSWT_START_SEC_CODE
extern FUNC( void, ETHSWT_CODE) EthSwt_EthTxAdaptBufferLength(P2VAR(uint16, AUTOMATIC, ETHSWT_APPL_DATA) LengthPtr);
ETHSWT_STOP_SEC_CODE

ETHSWT_START_SEC_CODE
extern FUNC(Std_ReturnType, ETHSWT_CODE) EthSwt_EthTxProcessFrame( VAR(uint8, AUTOMATIC) CtrlIdx, 
                                                             VAR(Eth_BufIdxType, AUTOMATIC) BufIdx, 
                                                             P2P2VAR(uint8, AUTOMATIC, ETHSWT_APPL_DATA) DataPtr, 
                                                             P2VAR(uint16, AUTOMATIC, ETHSWT_APPL_DATA) LengthPtr
                                                           );
ETHSWT_STOP_SEC_CODE

ETHSWT_START_SEC_CODE
extern FUNC( Std_ReturnType, ETHSWT_CODE) EthSwt_EthTxFinishedIndication( VAR(uint8, AUTOMATIC) CtrlIdx, 
                                                                                                   VAR(Eth_BufIdxType, AUTOMATIC) BufIdx
                                                                                                 );
ETHSWT_STOP_SEC_CODE

#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP || RESOURCE_SUPPORT_ETH_GMAC_IP */

#endif /* ETHSWT_H */

/** @} */


/*PRQA S 0380 EOF*/
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
*   @file    EthTrcv.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of EthTrcv
*
*   @addtogroup EthTrcv
*   @{
*/
#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section EthTrcv_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section EthTrcv_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded by
* other preprocessor directives or comments.
* MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR
*
* @section EthTrcv_c_REF_3
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required
* This warning appears when defining functions that will be used by the upper layers.
* The function in the file are APIs and will be used in the application.
*
* @section EthTrcv_c_REF_4
* Violates MISRA 2004 Required Rule 1.2, place reliance on undefined or unspecified behaviour
* The violation appears because pointers are being passed down as parameters to functions.
* It is accepted because the parameter is used in a safe way.
*
* @section EthTrcv_c_REF_5
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function.
* Extern global variables are not declared at block scope to follow the coding guidelines.
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
#include "EthTrcv.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ETHTRCV_C_VENDOR_ID                    176
#define ETHTRCV_C_AR_REL_MAJOR_VER             4
#define ETHTRCV_C_AR_REL_MINOR_VER             4
#define ETHTRCV_C_AR_REL_REV_VER               0
#define ETHTRCV_C_SW_MAJOR_VER                 3
#define ETHTRCV_C_SW_MINOR_VER                 0
#define ETHTRCV_C_SW_PATCH_VER                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (ETH_CFG_H_VENDOR_ID != ETHTRCV_C_VENDOR_ID)
    #error " NON-MATCHED DATA : ETHTRCV_C_VENDOR_ID "
#endif
#if (ETH_CFG_H_AR_REL_MAJOR_VER != ETHTRCV_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETHTRCV_C_AR_REL_MAJOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_MINOR_VER != ETHTRCV_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETHTRCV_C_AR_REL_MINOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_REV_VER != ETHTRCV_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETHTRCV_C_AR_REL_REV_VER "
#endif
#if (ETH_CFG_H_SW_MAJOR_VER != ETHTRCV_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETHTRCV_C_SW_MAJOR_VER "
#endif
#if (ETH_CFG_H_SW_MINOR_VER != ETHTRCV_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETHTRCV_C_SW_MINOR_VER "
#endif
#if (ETH_CFG_H_SW_PATCH_VER != ETHTRCV_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETHTRCV_C_SW_PATCH_VER "
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/**
* @brief          This function handles the received Ethernet frame.
* @details        Function should parse the received frame and pass the gathered
*                 information to the appropriate upper layer module.
* @param[in]      CtrlIdx Index of the controller which read Mii.
* @param[in]      TrcvIdx The Id of transceiver was read Mii
* @param[in]      RegIdx The Id or Address of Register was read
* @param[in]      RegVal The value of register.
*
* @implements EthTrcv_ReadMiiIndication_Activity
*
* @violates @ref EthTrcv_c_REF_3 Violates MISRA 2004 Required Rule 8.10 This is an interrupt handler
*/
ETHTRCV_START_SEC_CODE
FUNC(void, ETHTRCV_CODE)EthTrcv_ReadMiiIndication \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) TrcvIdx, \
    VAR(uint8, AUTOMATIC) RegIdx, \
    VAR(uint16, AUTOMATIC) RegVal \
)
{
    (void)CtrlIdx;
    (void)TrcvIdx;
    (void)RegIdx;
    (void)RegVal;
    /* This is an empty stub function */
}
ETHTRCV_STOP_SEC_CODE
/*================================================================================================*/
/**
* @brief          This function handles the received Ethernet frame.
* @details        Function should parse the received frame and pass the gathered
*                 information to the appropriate upper layer module.
* @param[in]      CtrlIdx Index of the controller which write Mii.
* @param[in]      TrcvIdx The Id of transceiver was write Mii
* @param[in]      RegIdx The Id or Address of Register was write
*
* @implements EthTrcv_WriteMiiIndication_Activity
*
* @violates @ref EthTrcv_c_REF_3 Violates MISRA 2004 Required Rule 8.10 This is an interrupt handler
*/
ETHTRCV_START_SEC_CODE
FUNC(void, ETHTRCV_CODE)EthTrcv_WriteMiiIndication \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) TrcvIdx, \
    VAR(uint8, AUTOMATIC) RegIdx \
)
{
    (void)CtrlIdx;
    (void)TrcvIdx;
    (void)RegIdx;
    /* This is an empty stub function */
}
ETHTRCV_STOP_SEC_CODE

#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP || RESOURCE_SUPPORT_ETH_GMAC_IP */

#ifdef __cplusplus
}
#endif
/** @} */

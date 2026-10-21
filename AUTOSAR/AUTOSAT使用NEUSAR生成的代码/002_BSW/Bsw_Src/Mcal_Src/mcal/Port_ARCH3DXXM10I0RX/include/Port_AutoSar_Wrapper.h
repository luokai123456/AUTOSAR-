/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : PORT
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : -
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    Port_Wrapper.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Port MCAL driver.
*
*   @addtogroup Port
*   @{
*/
/* PRQA S 2053, 0779 EOF */
#ifndef PORT_AUTOSAR_WRAPPER_H
#define PORT_AUTOSAR_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

/* ==============================================INCLUDE FILES======================================= */

#include "Port_LLDriver.h"

/* =====================================SOURCE FILE VERSION INFORMATION============================== */

/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file.
*
*/
#define PORT_H_VENDOR_ID_IPW                    176
#define PORT_H_AR_REL_MAJOR_VER_IPW             4
#define PORT_H_AR_REL_MINOR_VER_IPW             4

#define PORT_H_AR_REL_REV_VER_IPW               0

#define PORT_H_SW_MAJOR_VERSION_IPW             3
#define PORT_H_SW_MINOR_VERSION_IPW             0
#define PORT_H_SW_PATCH_VERSION_IPW             0

/* ============================================FILE VERSION CHECKS=================================== */

#if (PORT_H_VENDOR_ID_IPW != PORT_H_SIUL2_VENDOR_ID)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_VENDOR_ID"
#endif

#if (PORT_H_AR_REL_MAJOR_VER_IPW != PORT_H_SIUL2_AR_REL_MAJOR_VER)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_AR_REL_MAJOR_VER"
#endif

#if (PORT_H_AR_REL_MINOR_VER_IPW != PORT_H_SIUL2_AR_REL_MINOR_VER)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_AR_REL_MINOR_VER"
#endif

#if (PORT_H_AR_REL_REV_VER_IPW != PORT_H_SIUL2_AR_REL_REV_VER)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_AR_REL_REV_VER"
#endif

#if (PORT_H_SW_MAJOR_VERSION_IPW != PORT_H_SIUL2_SW_MAJOR_VERSION)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_SW_MAJOR_VERSION"
#endif

#if (PORT_H_SW_MINOR_VERSION_IPW != PORT_H_SIUL2_SW_MINOR_VERSION)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_SW_MINOR_VERSION"
#endif

#if (PORT_H_SW_PATCH_VERSION_IPW != PORT_H_SIUL2_SW_PATCH_VERSION)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_SW_PATCH_VERSION"
#endif

/* =============================================CONSTANTS============================================ */

/* =========================================DEFINES AND MACROS======================================= */
/**
* @brief  Mapping the platform RefMan IMCR id's to the normal addressing index.
*/
#define IMCR_INDEX_OFFSET_U32          ((uint32)32UL)

#define ONLY_INPUT_INDEX_OFFSET_U8     ((uint8)15U)

#define SIUL2_MODE_BIT_OFFSET_MASK_U8  ((uint8)0x0F)

/**
* @brief  Mapping between low level layer and high level layer for Port_Wrapper_Init function.
*/
#define Port_Wrapper_Init                  (Port_LLD_Init)

#if (STD_ON == PORT_SET_PIN_DIRECTION_API)
/**
* @brief  Mapping between low level layer and high level layer for Port_Wrapper_SetPinDirection.
*/
#if (defined  (RESOURCE_SUPPORT_EIOMUX2))
#define Port_Wrapper_SetPinDirection       (Port_LLD_EIOMUX2_SetPinDirection)
#else
#define Port_Wrapper_SetPinDirection       (Port_LLD_SetPinDirection)
#endif

#endif /* STD_ON == PORT_SET_PIN_DIRECTION_API */

/**
* @brief  Mapping between low level layer and high level layer for Port_Wrapper_UpdataPortDirection function.
*/
#if (defined  (RESOURCE_SUPPORT_EIOMUX2))
#define Port_Wrapper_UpdataPortDir       (Port_LLD_EIOMUX2_RefreshPortDirection)
#else
#define Port_Wrapper_UpdataPortDir  (Port_LLD_RefreshPortDirection)
#endif
/* ==============================================ENUMS=============================================== */


/* =======================================STRUCTURES AND OTHER TYPEDEFS============================== */


/* ====================================GLOBAL VARIABLE DECLARATIONS================================== */


/* ========================================FUNCTION PROTOTYPES======================================= */

/* Allocate defined section for PORT code */


#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* Sets the port pin mode.
*/
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC(Std_ReturnType, PORT_CODE) Port_AutoSar_Wrapper_SetPinMode \
(
    VAR     (Port_PinType,      AUTOMATIC                 ) u32Port_PinIndex, \
    VAR     (Port_PinModeType,  AUTOMATIC                 ) Port_PinMode, \
    P2CONST (Port_ConfigType,   AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#if (defined  (RESOURCE_SUPPORT_EIOMUX))
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC(Std_ReturnType, PORT_CODE) Port_AutoSar_Wrapper_SetPinMode_EIOMUX \
( \
    VAR    (Port_PinType,     AUTOMATIC                 ) u32Port_PinIndex, \
    VAR    (Port_PinModeType, AUTOMATIC                 ) u16Port_PinMode, \
    P2CONST(Port_ConfigType,  AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#elif (defined (RESOURCE_SUPPORT_EIOMUX2))

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC(Std_ReturnType, PORT_CODE) Port_AutoSar_Wrapper_SetPinMode_EIOMUX2 \
( \
    VAR    (Port_PinType,     AUTOMATIC                 ) u32Port_PinIndex, \
    VAR    (Port_PinModeType, AUTOMATIC                 ) u32Port_PinMode, \
    P2CONST(Port_ConfigType,  AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif /* #if (defined  (RESOURCE_SUPPORT_EIOMUX)) */
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */



#ifdef __cplusplus
}
#endif

#endif /*PORT_AUTOSAR_WRAPPER_H*/
/** @} */

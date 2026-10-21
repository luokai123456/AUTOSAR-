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
*   @file    Port.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Port MCAL driver.
*
*   @addtogroup Port
*   @{
*/

#ifndef PORT_H
#define PORT_H

#ifdef __cplusplus
extern "C" {
#endif

/* ==============================================INCLUDE FILES======================================= */

#include "Std_Types.h"
#include "Port_Cfg.h"
#include "Mcal.h"

/* =====================================SOURCE FILE VERSION INFORMATION============================== */

#define PORT_VENDOR_ID                    176
#define PORT_MODULE_ID                    124
#define PORT_AR_RELEASE_MAJOR_VERSION     4
#define PORT_AR_RELEASE_MINOR_VERSION     4

#define PORT_AR_RELEASE_REV_VERSION       0
#define PORT_SW_MAJOR_VERSION             3
#define PORT_SW_MINOR_VERSION             0
#define PORT_SW_PATCH_VERSION             0

/* ============================================FILE VERSION CHECKS=================================== */

#if (PORT_VENDOR_ID != PORT_H_VENDOR_ID_CFG)
    #error "NON-MATCHED DATA : PORT_H_VENDOR_ID_CFG"
#endif

#if (PORT_AR_RELEASE_MAJOR_VERSION != PORT_H_AR_RELEASE_MAJOR_VERSION_CFG)
    #error "NON-MATCHED DATA : PORT_H_AR_RELEASE_MAJOR_VERSION_CFG"
#endif

#if (PORT_AR_RELEASE_MINOR_VERSION != PORT_H_AR_RELEASE_MINOR_VERSION_CFG)
    #error "NON-MATCHED DATA : PORT_H_AR_RELEASE_MINOR_VERSION_CFG"
#endif

#if (PORT_AR_RELEASE_REV_VERSION != PORT_H_AR_RELEASE_REVISION_VERSION_CFG)
    #error "NON-MATCHED DATA : PORT_H_AR_RELEASE_REVISION_VERSION_CFG"
#endif

#if (PORT_SW_MAJOR_VERSION != PORT_H_SW_MAJOR_VERSION_CFG)
    #error "NON-MATCHED DATA : PORT_H_SW_MAJOR_VERSION_CFG"
#endif

#if (PORT_SW_MINOR_VERSION != PORT_H_SW_MINOR_VERSION_CFG)
    #error "NON-MATCHED DATA : PORT_H_SW_MINOR_VERSION_CFG"
#endif

#if (PORT_SW_PATCH_VERSION != PORT_H_SW_PATCH_VERSION_CFG)
    #error "NON-MATCHED DATA : PORT_H_SW_PATCH_VERSION_CFG"
#endif

#define PORT_CORE_NUM                    MCAL_CORE_NUM

/**
* @brief port init state
*/
typedef enum
{
    PORT_UNINIT = 0,        /**< @brief Sets port pin as input. */
    PORT_INIT = 1,           /**< @brief Sets port pin as output. */
} Port_InitStateType;
/* =============================================CONSTANTS============================================ */
/**
* @brief          The PORT module is not properly configured
*
* @api
*/
/** @violates @ref Port_h_REF_3 A project should not contain unused macro declarations. */
#define PORT_E_PARAM_CONFIG                      ((uint8)0xF0)

/* Instance IDs */
/**
* @brief   Instance ID of port driver.
*
*/
#define PORT_INSTANCE_ID                ((uint8)0x0)

/* Service IDs */
/*
* @brief   Service ID of port driver.
*/

/**
* @brief   API service ID for PORT Init function.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
#define PORT_INIT_ID                    ((uint8)0x00)
/**
* @brief   API service ID for PORT set pin direction function.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
#define PORT_SETPINDIRECTION_ID         ((uint8)0x01)
/**
* @brief   API service ID for PORT refresh pin direction function.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
#define PORT_REFRESHPINDIRECTION_ID     ((uint8)0x02)
/**
* @brief   API service ID for PORT get version info function.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
#define PORT_GETVERSIONINFO_ID          ((uint8)0x03)
/**
* @brief   API service ID for PORT set pin mode.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
#define PORT_SETPINMODE_ID              ((uint8)0x04)

/* Errors IDs */
/**
* @brief   Error ID of port driver.
* @details The following errors and exception are detectable by the PORT driver
*          if development error detection is enabled.
*
*/

/**
* @brief   Invalid Port Pin ID requested.
* @details Det Error value, returned by Port_SetPinDirection and Port_PinMode
*          if an wrong PortPin ID is passed.
*
* @implements Port_ErrorCodes_define
* @api
*/
 #define PORT_E_PARAM_PIN                ((uint8)0x0A)
/**
* @brief   Port Pin Direction not configured as changeable.
* @details Det Error value, returned by Port_SetPinDirection
*          if the passed PortPin have unchangeable direction.
*
* @implements Port_ErrorCodes_define
* @api
*/
#define PORT_E_DIRECTION_UNCHANGEABLE   ((uint8)0x0B)
/**
* @brief   API Port_Init() service called with wrong parameter.
* @details Det Error value, returned by Port_Init function
*          if Port_Init is called with wrong parameter.
*
* @implements Port_ErrorCodes_define
* @api
*/
#define PORT_E_INIT_FAILED              ((uint8)0x0C)
/**
* @brief   API Port_SetPinMode() service called when mode is invalid.
* @details Det Error value, returned by Port_SetPinMode function
*          if the passed PortPinMode is invalid.
*
* @implements Port_ErrorCodes_define
* @api
*/
#define PORT_E_PARAM_INVALID_MODE       ((uint8)0x0D)
/**
* @brief   API Port_SetPinMode() service called when mode is unchangeable.
* @details Det Error value, returned by Port_SetPinMode function
*          if the passed PortPin have a unchangeable Mode.
*
* @implements Port_ErrorCodes_define
* @api
*/
#define PORT_E_MODE_UNCHANGEABLE        ((uint8)0x0E)
/**
* @brief   API service called without module initialization.
* @details Det Error value, returned by a function if API service called
*          prior to module initialization.
*
* @implements Port_ErrorCodes_define
* @api
*/
#define PORT_E_UNINIT                   ((uint8)0x0F)
/**
* @brief   API service called with NULL Pointer Parameter.
* @details Det Error value, returned by Port_GetVersionInfo function
*          if API is called with NULL Pointer Parameter.
*
* @implements Port_ErrorCodes_define
* @api
*/
#define PORT_E_PARAM_POINTER            ((uint8)0x10)


/**
* @brief   Code variant
*
*/


/* =========================================DEFINES AND MACROS======================================= */


/* ==============================================ENUMS=============================================== */


/* =======================================STRUCTURES AND OTHER TYPEDEFS============================== */


/* ====================================GLOBAL VARIABLE DECLARATIONS================================== */


/* ========================================FUNCTION PROTOTYPES======================================= */

/* Allocate defined section for PORT code */
/**
* @violates @ref PORT_H_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file
* MemMap.h
*/

/*
* Initializes the Port Driver module.
*/
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC(void, PORT_CODE) Port_Init \
( \
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) ConfigPtr \
);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#if (STD_ON == PORT_SET_PIN_DIRECTION_API)
/*
* Sets the port pin direction.
* Function disabled in the frozen pin configuration.
*/
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC(void, PORT_CODE) Port_SetPinDirection \
( \
    VAR(Port_PinType,           AUTOMATIC) Pin, \
    VAR(Port_PinDirectionType,  AUTOMATIC) Direction \
);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif /* STD_ON == PORT_SET_PIN_DIRECTION_API */

#if (STD_ON == PORT_SET_PIN_MODE_API)
/*
* Sets the port pin mode.
*/
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC(void, PORT_CODE) Port_SetPinMode \
( \
    VAR(Port_PinType,       AUTOMATIC) Pin, \
    VAR(Port_PinModeType,   AUTOMATIC) Mode \
);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif /* STD_ON == PORT_SET_PIN_MODE_API */

#if (PORT_SET_SIUL2_API == STD_ON)
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC (void, PORT_CODE)Port_Siul2_SetExtRequest \
( \
	P2CONST(Port_siul2_request_config, P2CONST, PORT_APPL_DATA) reqConfig \
);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif

#if (STD_ON == PORT_VERSION_INFO_API)
/*
* Returns the version information of this module.
*/
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC (void, PORT_CODE) Port_GetVersionInfo \
( \
    P2VAR(Std_VersionInfoType, AUTOMATIC, PORT_APPL_DATA) versioninfo  /* PRQA S 3432 */
);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif /* STD_ON == PORT_VERSION_INFO_API */

/*
* Refreshes port direction.
*/
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC(void, PORT_CODE) Port_RefreshPortDirection(void);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

extern CONST(Port_ConfigType, PORT_CONST) Port_Config;

/**
* @violates @ref PORT_H_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file
* MemMap.h
*/


#ifdef __cplusplus
}
#endif

#endif /* PORT_H */

/** @} */

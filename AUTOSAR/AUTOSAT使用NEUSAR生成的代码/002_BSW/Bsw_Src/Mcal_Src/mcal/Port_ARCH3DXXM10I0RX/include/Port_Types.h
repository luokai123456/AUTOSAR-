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
*   @file    Port_Types.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Port MCAL driver.
*
*   @addtogroup Port
*   @{
*/

#ifndef PORT_TYPES_H
#define PORT_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

/* ==============================================INCLUDE FILES======================================= */
#include "Port_Register.h"
#include "Platform_Types.h"
#include "Mcal.h"
/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define PORT_H_SIUL2_VENDOR_ID_TYPES                     176
#define PORT_H_SIUL2_AR_REL_MAJ_VER_TY                   4
#define PORT_H_SIUL2_AR_REL_MIN_VER_TY                   4
#define PORT_H_SIUL2_AR_REL_REV_VER_TY                   0
#define PORT_H_SIUL2_SW_MAJOR_VER_TY                     3
#define PORT_H_SIUL2_SW_MINOR_VER_TY                     0
#define PORT_H_SIUL2_SW_PATCH_VER_TY                     0

/* ==================================FILE VERSION CHECKS============================================= */

#if (PORT_H_SIUL2_VENDOR_ID_TYPES != REGESYS_SIUL2_VENDOR_ID)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_VENDOR_ID"
#endif

#if (PORT_H_SIUL2_AR_REL_MAJ_VER_TY != REGESYS_SIUL2_AR_REL_MAJOR_VER)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_AR_REL_MAJOR_VER"
#endif

#if (PORT_H_SIUL2_AR_REL_MIN_VER_TY != REGESYS_SIUL2_AR_REL_MINOR_VER)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_AR_REL_MINOR_VER"
#endif

#if (PORT_H_SIUL2_AR_REL_REV_VER_TY != REGESYS_SIUL2_AR_REL_REV_VER)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_AR_REL_REV_VER"
#endif

#if (PORT_H_SIUL2_SW_MAJOR_VER_TY != REGESYS_SIUL2_SW_MAJOR_VERSION)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_SW_MAJOR_VERSION"
#endif

#if (PORT_H_SIUL2_SW_MINOR_VER_TY != REGESYS_SIUL2_SW_MINOR_VERSION)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_SW_MINOR_VERSION"
#endif

#if (PORT_H_SIUL2_SW_PATCH_VER_TY != REGESYS_SIUL2_SW_PATCH_VERSION)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_SW_PATCH_VERSION"
#endif
/* =============================================CONSTANTS============================================ */

/**
* @brief Possible output status of a port pin.
*/
#define  PORT_PIN_LEVEL_LOW_U8         ((uint8)0)
#define  PORT_PIN_LEVEL_HIGH_U8        ((uint8)1)
#define  PORT_PIN_LEVEL_NOTCHANGED_U8  ((uint8)2)

/* =========================================DEFINES AND MACROS======================================= */


/* ==============================================ENUMS=============================================== */


/* =======================================STRUCTURES AND OTHER TYPEDEFS============================== */

/**
* @brief Data type for the symbolic name of a port pin.
* @details Shall cover all available port pins. The type should be chosen for the specific MCU
*         platform (best performance).
* @implements Port_PinType_typedef
*/
typedef uint32 Port_PinType;

/**
* @brief Possible directions of a port pin.
* @implements Port_PinDirectionType_enumeration
*/
typedef enum
{
    PORT_PIN_IN = 0,        /**< @brief Sets port pin as input. */
    PORT_PIN_OUT = 1,           /**< @brief Sets port pin as output. */
} Port_PinDirectionType;



/*
* @brief Data type for the number, mentioned in platform spec, of a port pin.
*        It is the same with the index of the PCR/MSCR register.
* @details Shall cover all available port pins.
*
*/
typedef uint16 Port_InternalPinIdType;


/**
* @brief   A SIUL2 register value.
* @details A port register shall be written with a 32 bits value (type Port_RegValueType).
*          The type Port_RegValueType shall be used with the function call Port_SetPinMode
*
*/
typedef uint32 Port_RegValueType;



/**
* @brief Data type used for Pad Selection Multiplexed Configuration.
* @details This type should be chosen for the specific MCU platform (best performance).
*
* @api
*/
typedef uint32 Port_Siul2_PadSelConfigType;

/* ====================================GLOBAL VARIABLE DECLARATIONS================================== */


/* ========================================FUNCTION PROTOTYPES======================================= */


#ifdef __cplusplus
}
#endif
/* PORT_TYPES_H */
#endif
/** @} */

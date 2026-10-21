/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : DIO
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : -
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*****************************************************************************/
/**
*   @file    Dio_Types.h
*   @version 3.0.0
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Dio MCAL driver.
*   @addtogroup Dio
*   @{
*/

#ifndef DIO_TYPES_H
#define DIO_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/* ==============================================INCLUDE FILES======================================= */
#include "Mcal.h"

/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define DIO_TYPES_VENDOR_ID                     176
#define DIO_MODULE_ID                           120
#define DIO_TYPES_MAJOR_VERSION                 4
#define DIO_TYPES_MINOR_VERSION                 4
#define DIO_TYPES_patch_VERSION                 0
#define DIO_TYPES_SW_MAJOR_VERSION              3
#define DIO_TYPES_SW_MINOR_VERSION              0
#define DIO_TYPES_SW_PATCH_VERSION              0

/* ====================================FILE VERSION CHECKS======================================= */
#if (DIO_TYPES_VENDOR_ID != MCAL_VENDOR_ID)
    #error " NON-MATCHED DATA : DIO_TYPES_VENDOR_ID "
#endif
#if (DIO_TYPES_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_TYPES_MAJOR_VERSION "
#endif
#if (DIO_TYPES_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_TYPES_MINOR_VERSION "
#endif
#if (DIO_TYPES_patch_VERSION != MCAL_AR_RELEASE_REVISION_VERSION)
    #error " NON-MATCHED DATA : DIO_TYPES_patch_VERSION "
#endif
#if (DIO_TYPES_SW_MAJOR_VERSION != MCAL_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_TYPES_SW_MAJOR_VERSION "
#endif
#if (DIO_TYPES_SW_MINOR_VERSION != MCAL_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_TYPES_SW_MINOR_VERSION "
#endif
#if (DIO_TYPES_SW_PATCH_VERSION != MCAL_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : DIO_TYPES_SW_PATCH_VERSION "
#endif

#define DIO_ERROR_CHECK  (DIO_DEV_ERROR_DETECT)

/* ====================================== CONSTANTS============================================== */
#define DIO_E_PARAM_LEVEL                       ((uint8)0x21)
#define DIO_E_PARAM_POINTER                     ((uint8)0x20)
#define DIO_E_PARAM_INVALID_GROUP_ID            ((uint8)0x1F)
#define DIO_E_PARAM_INVALID_PORT_ID             ((uint8)0x14)
#define DIO_E_PARAM_CONFIG                      ((uint8)0x10)
#define DIO_E_PARAM_INVALID_CHANNEL_ID          ((uint8)0x0A)
#define DIO_INSTANCE_ID                         ((uint8)0x00)
#define DIO_MASKEDWRITEPORT_ID                  ((uint8)0x13)
#define DIO_GETVERSIONINFO_ID                   ((uint8)0x12)
#define DIO_FLIPCHANNEL_ID                      ((uint8)0x11)
#define DIO_WRITECHANNELGROUP_ID                ((uint8)0x05)
#define DIO_READCHANNELGROUP_ID                 ((uint8)0x04)
#define DIO_WRITEPORT_ID                        ((uint8)0x03)
#define DIO_READPORT_ID                         ((uint8)0x02)
#define DIO_WRITECHANNEL_ID                     ((uint8)0x01)
#define DIO_READCHANNEL_ID                      ((uint8)0x00)

typedef uint8 Dio_PortType;
typedef uint16 Dio_ChannelType;
#if defined (RESOURCE_SUPPORT_SIUL2_IP)
typedef uint16 Dio_PortLevelType;
#elif defined (RESOURCE_SUPPORT_SIUL_IP)
typedef uint32 Dio_PortLevelType;
#endif
typedef uint8 Dio_LevelType;

#if defined(RESOURCE_SUPPORT_SIUL2_IP)
typedef struct
{
    VAR(Dio_PortLevelType, AUTOMATIC) mask;  
    VAR(uint8, AUTOMATIC)             offset;    
    VAR(Dio_PortType, AUTOMATIC)      port;      
} Dio_ChannelGroupType;
#elif defined(RESOURCE_SUPPORT_SIUL_IP)
typedef struct
{
    VAR(Dio_PortLevelType, AUTOMATIC) mask;  
    VAR(uint8, AUTOMATIC)             offset;    
    VAR(Dio_PortType, AUTOMATIC)      port;       
    VAR(Dio_PortType, AUTOMATIC)      portgroup;   
} Dio_ChannelGroupType;
#endif

typedef struct
{            
    CONST(uint32, DIO_CONST)  nDioChannelId;                                                           
    CONST(uint32, DIO_CONST) coreid;                                          
} pu32Dio_ChannelToPartitionMap;
typedef struct
{                                                                       
    CONST(uint32, DIO_CONST)  nDioPortId; 
    CONST(uint32, DIO_CONST)  coreid;                                         
} pu32Dio_PortToPartitionMap;
typedef struct
{                                                          
    VAR(uint8, AUTOMATIC) u8NumChannelGroups; 
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) pChannelGroupList;  
    P2CONST(pu32Dio_ChannelToPartitionMap, DIO_CONST, DIO_APPL_CONST) Dio_u32ChannelToPartitionMap;
    P2CONST(pu32Dio_PortToPartitionMap, DIO_CONST, DIO_APPL_CONST) Dio_u32PortToPartitionMap;
} Dio_ConfigType;

#ifdef __cplusplus
}
#endif

#endif

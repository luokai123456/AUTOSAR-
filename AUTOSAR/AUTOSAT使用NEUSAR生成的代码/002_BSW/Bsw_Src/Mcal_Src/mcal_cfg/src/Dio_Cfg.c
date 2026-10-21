/****************************************************************************
 *
 * Copyright (c) 2023  C*Core -   All Rights Reserved
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
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
 *
 *****************************************************************************/

/**
 *   @file    Dio_Cfg.c
 *   @version 3.0.0
 *
 *   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
 *   @details Autosar layer of Dio MCAL driver.
 *
 *   @addtogroup Dio
 *   @{
 */

#ifdef __cplusplus
extern "C"
{
#endif
/*PRQA S 0380,0686,0691 EOF*/
/*==============================================INCLUDE FILES=======================================*/
#include "Dio_Cfg.h"
/*=============================SOURCE FILE VERSION INFORMATION==================================*/
#define DIO_CFG_C_VENDOR_ID 176
#define DIO_CFG_C_MAJOR_VERSION 4
#define DIO_CFG_C_MINOR_VERSION 4
#define DIO_CFG_C_patch_VERSION 0
#define DIO_CFG_C_SW_MAJOR_VERSION 3
#define DIO_CFG_C_SW_MINOR_VERSION 0
#define DIO_CFG_C_SW_PATCH_VERSION 0
/*====================================FILE VERSION CHECKS=======================================*/
#if (DIO_CFG_C_VENDOR_ID != DIO_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : DIO_CFG_C_VENDOR_ID "
#endif
#if (DIO_CFG_C_MAJOR_VERSION != DIO_CFG_H_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_C_MAJOR_VERSION "
#endif
#if (DIO_CFG_C_MINOR_VERSION != DIO_CFG_H_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_C_MINOR_VERSION "
#endif
#if (DIO_CFG_C_patch_VERSION != DIO_CFG_H_patch_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_C_patch_VERSION "
#endif
#if (DIO_CFG_C_SW_MAJOR_VERSION != DIO_CFG_H_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_C_SW_MAJOR_VERSION "
#endif
#if (DIO_CFG_C_SW_MINOR_VERSION != DIO_CFG_H_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_C_SW_MINOR_VERSION "
#endif
#if (DIO_CFG_C_SW_PATCH_VERSION != DIO_CFG_H_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_C_SW_PATCH_VERSION "
#endif
/*=========================================CONSTANTS============================================*/


#define DIO_START_SEC_CONFIG_DATA
#include "Dio_MemMap.h"
CONST(Dio_PortLevelType, DIO_CONST) Dio_ReadAvailablePins[DIO_NUM_PORTS_U16] =
{
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xbfffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xff80UL,
    (Dio_PortLevelType)0x0000UL,
    (Dio_PortLevelType)0x0000UL
};
#define DIO_STOP_SEC_CONFIG_DATA
#include "Dio_MemMap.h"


#define DIO_START_SEC_CONFIG_DATA
#include "Dio_MemMap.h"
CONST(Dio_PortLevelType, DIO_CONST) Dio_WriteAvailablePins[DIO_NUM_PORTS_U16] =
{
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xbfffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0xc07fUL,
    (Dio_PortLevelType)0xffffUL,
    (Dio_PortLevelType)0x8000UL
};
#define DIO_STOP_SEC_CONFIG_DATA
#include "Dio_MemMap.h"






#define DIO_START_SEC_CONFIG_DATA
#include "Dio_MemMap.h"
static CONST(pu32Dio_PortToPartitionMap, DIO_CONST) u32PortToPartitionMap[DIO_NUM_PORTS_U16] =
{
    {
        .nDioPortId = 1,
        .coreid =  1
    },
    {
        .nDioPortId = 3,
        .coreid =  1
    },
    {
        .nDioPortId = 7,
        .coreid =  1
    },
    {
        .nDioPortId = 8,
        .coreid =  1
    },
    {
        .nDioPortId = 11,
        .coreid =  1
    },
    {
        .nDioPortId = 12,
        .coreid =  1
    },
    {
        .nDioPortId = 13,
        .coreid =  1
    },
    {
        .nDioPortId = 10,
        .coreid =  1
    },
    {
        .nDioPortId = 2,
        .coreid =  1
    },
    {
        .nDioPortId = 4,
        .coreid =  1
    },
    {
        .nDioPortId = 5,
        .coreid =  1
    },
    {
        .nDioPortId = 6,
        .coreid =  1
    },
    {
        .nDioPortId = 15,
        .coreid =  1
    },
    {
        .nDioPortId = 16,
        .coreid =  1
    },
    {
        .nDioPortId = 20,
        .coreid =  1
    },
    {
        .nDioPortId = 9,
        .coreid =  1
    },

};
#define DIO_STOP_SEC_CONFIG_DATA
#include "Dio_MemMap.h"

#define DIO_START_SEC_CONFIG_DATA
#include "Dio_MemMap.h"
CONST(Dio_PortType, DIO_CONST) port_index[DIO_NUM_PORTS_U16] =
{
    [1] = 0,    
    [3] = 1,    
    [7] = 2,    
    [8] = 3,    
    [11] = 4,    
    [12] = 5,    
    [13] = 6,    
    [10] = 7,    
    [2] = 8,    
    [4] = 9,    
    [5] = 10,    
    [6] = 11,    
    [15] = 12,    
    [16] = 13,    
    [20] = 14,    
    [9] = 15,    
};
#define DIO_STOP_SEC_CONFIG_DATA
#include "Dio_MemMap.h"

#define DIO_START_SEC_CONFIG_DATA
#include "Dio_MemMap.h"
static CONST(pu32Dio_ChannelToPartitionMap, DIO_CONST) u32ChannelToPartitionMap[DIO_NUM_CHANNELS_U16] =
{                        
        {
            .nDioChannelId = 27,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 31,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 28,
            .coreid =  1
        },                            
        {
            .nDioChannelId = 48,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 49,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 51,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 53,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 57,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 58,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 59,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 60,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 61,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 62,
            .coreid =  1
        },                            
        {
            .nDioChannelId = 114,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 115,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 116,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 118,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 121,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 122,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 123,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 124,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 125,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 126,
            .coreid =  1
        },                            
        {
            .nDioChannelId = 132,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 137,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 139,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 135,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 136,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 138,
            .coreid =  1
        },                            
        {
            .nDioChannelId = 189,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 191,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 176,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 177,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 178,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 179,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 182,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 183,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 190,
            .coreid =  1
        },                            
        {
            .nDioChannelId = 192,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 193,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 195,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 207,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 196,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 197,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 198,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 199,
            .coreid =  1
        },                            
        {
            .nDioChannelId = 209,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 210,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 213,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 214,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 220,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 208,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 211,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 212,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 217,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 218,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 219,
            .coreid =  1
        },                            
        {
            .nDioChannelId = 175,
            .coreid =  1
        },                            
        {
            .nDioChannelId = 33,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 38,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 43,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 47,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 39,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 40,
            .coreid =  1
        },                            
        {
            .nDioChannelId = 68,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 75,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 76,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 77,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 78,
            .coreid =  1
        },                            
        {
            .nDioChannelId = 90,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 92,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 94,
            .coreid =  1
        },                            
        {
            .nDioChannelId = 97,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 101,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 102,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 111,
            .coreid =  1
        },                            
        {
            .nDioChannelId = 244,
            .coreid =  1
        },                                    
        {
            .nDioChannelId = 323,
            .coreid =  1
        },                            
        {
            .nDioChannelId = 145,
            .coreid =  1
        },                    
        {
            .nDioChannelId = 144,
            .coreid =  1
        },    
};
#define DIO_STOP_SEC_CONFIG_DATA
#include "Dio_MemMap.h"

#define DIO_START_SEC_CONFIG_DATA
#include "Dio_MemMap.h"
CONST(Dio_ChannelType, DIO_CONST) channel_index[DIO_NUM_CHANNELS_U16] =
{                        
    [27] = 0,                            
    [31] = 1,                            
    [28] = 2,                                    
    [48] = 3,                            
    [49] = 4,                            
    [51] = 5,                            
    [53] = 6,                            
    [57] = 7,                            
    [58] = 8,                            
    [59] = 9,                            
    [60] = 10,                            
    [61] = 11,                            
    [62] = 12,                                    
    [114] = 13,                            
    [115] = 14,                            
    [116] = 15,                            
    [118] = 16,                            
    [121] = 17,                            
    [122] = 18,                            
    [123] = 19,                            
    [124] = 20,                            
    [125] = 21,                            
    [126] = 22,                                    
    [132] = 23,                            
    [137] = 24,                            
    [139] = 25,                            
    [135] = 26,                            
    [136] = 27,                            
    [138] = 28,                                    
    [189] = 29,                            
    [191] = 30,                            
    [176] = 31,                            
    [177] = 32,                            
    [178] = 33,                            
    [179] = 34,                            
    [182] = 35,                            
    [183] = 36,                            
    [190] = 37,                                    
    [192] = 38,                            
    [193] = 39,                            
    [195] = 40,                            
    [207] = 41,                            
    [196] = 42,                            
    [197] = 43,                            
    [198] = 44,                            
    [199] = 45,                                    
    [209] = 46,                            
    [210] = 47,                            
    [213] = 48,                            
    [214] = 49,                            
    [220] = 50,                            
    [208] = 51,                            
    [211] = 52,                            
    [212] = 53,                            
    [217] = 54,                            
    [218] = 55,                            
    [219] = 56,                                    
    [175] = 57,                                    
    [33] = 58,                            
    [38] = 59,                            
    [43] = 60,                            
    [47] = 61,                            
    [39] = 62,                            
    [40] = 63,                                    
    [68] = 64,                            
    [75] = 65,                            
    [76] = 66,                            
    [77] = 67,                            
    [78] = 68,                                    
    [90] = 69,                            
    [92] = 70,                            
    [94] = 71,                                    
    [97] = 72,                            
    [101] = 73,                            
    [102] = 74,                            
    [111] = 75,                                    
    [244] = 76,                                            
    [323] = 77,                                    
    [145] = 78,                            
    [144] = 79,            
};
#define DIO_STOP_SEC_CONFIG_DATA
#include "Dio_MemMap.h"
#define DIO_START_SEC_CONFIG_DATA
#include "Dio_MemMap.h"
CONST(Dio_ConfigType, DIO_CONST) Dio_ConfigPC=
{
    .u8NumChannelGroups = (uint8)0x0,
    .pChannelGroupList = NULL_PTR,    
    .Dio_u32ChannelToPartitionMap = u32ChannelToPartitionMap,
    .Dio_u32PortToPartitionMap = u32PortToPartitionMap
};
#define DIO_STOP_SEC_CONFIG_DATA
#include "Dio_MemMap.h"
#ifdef __cplusplus
}
#endif

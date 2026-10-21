/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : CAN
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*  
*****************************************************************************/
/* PRQA S 0704, 0380, 1258 EOF */
/**
*   @file    Can_176_CanFD_Cfg.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CanFD MCAL driver.
*
*   @addtogroup CanFD
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

#include "Can_176_CanFD.h"
FUNC(void,CAN_CODE) error_notify(VAR(uint8, AUTOMATIC) u8Can_ControllerId){} //DQ
#ifdef RESOURCE_SUPPORT_CANFD_IP

#define CAN_176_CANFD_CFG_C_VENDOR_ID                     176
#define CAN_176_CANFD_CFG_C_AR_REL_MAJOR_VER              4
#define CAN_176_CANFD_CFG_C_AR_REL_MINOR_VER              4
#define CAN_176_CANFD_CFG_C_AR_REL_REV_VER                0
#define CAN_176_CANFD_CFG_C_SW_MAJOR_VER                  3
#define CAN_176_CANFD_CFG_C_SW_MINOR_VER                  0
#define CAN_176_CANFD_CFG_C_SW_PATCH_VER                  0

#if (MCAL_VENDOR_ID != CAN_176_CANFD_CFG_C_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_C_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != CAN_176_CANFD_CFG_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_C_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != CAN_176_CANFD_CFG_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_C_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != CAN_176_CANFD_CFG_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_C_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != CAN_176_CANFD_CFG_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_C_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != CAN_176_CANFD_CFG_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_C_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != CAN_176_CANFD_CFG_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_C_SW_PATCH_VER "
#endif


extern FUNC(void,CAN_CODE) error_notify(VAR(uint8, AUTOMATIC) u8Can_ControllerId);

#define CAN_176_CANFD_START_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"
static CONST(CanFd_hwObject, CAN_CONST) Canfd_HardWareObjConfigs[CAN_176_CANFD_MB_COUNT] = 
{
    {
        .CanObjectId = 0U,
        .CanControllerId = (uint32)0U,
        .CanIdType = CANFD_STANDARD_ID,
        .mbIdex = 0U,
        .mbPayloadLength = (uint32)64U,
        .mbType = CANFD_TRANS_BUF_TYPE_BUTT,
        .isPolling = 0U,
        .CanObjectType = CANFD_RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterCode = 0x00000101U,
        .filterMask = 0x00000000U,
    },
    {
        .CanObjectId = 1U,
        .CanControllerId = (uint32)0U,
        .CanIdType = CANFD_EXTENDED_ID,
        .mbIdex = 0U,
        .mbPayloadLength = (uint32)64U,
        .mbType = CANFD_TRANS_BUF_TYPE_BUTT,
        .isPolling = 0U,
        .CanObjectType = CANFD_RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterCode = 0x18ff1001U,
        .filterMask = 0x00000000U,
    },
    {
        .CanObjectId = 2U,
        .CanControllerId = (uint32)1U,
        .CanIdType = CANFD_STANDARD_ID,
        .mbIdex = 0U,
        .mbPayloadLength = (uint32)8U,
        .mbType = CANFD_TRANS_BUF_TYPE_BUTT,
        .isPolling = 1U,
        .CanObjectType = CANFD_RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterCode = 0x00000201U,
        .filterMask = 0x00000000U,
    },
    {
        .CanObjectId = 3U,
        .CanControllerId = (uint32)1U,
        .CanIdType = CANFD_EXTENDED_ID,
        .mbIdex = 0U,
        .mbPayloadLength = (uint32)8U,
        .mbType = CANFD_TRANS_BUF_TYPE_BUTT,
        .isPolling = 1U,
        .CanObjectType = CANFD_RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterCode = 0x18ff2001U,
        .filterMask = 0x00000000U,
    },
    {
        .CanObjectId = 4U,
        .CanControllerId = (uint32)0U,
        .CanIdType = CANFD_STD_AND_EXT_ID,
        .mbIdex = 0U,
        .mbPayloadLength = (uint32)64U,
        .mbType = CANFD_TRANS_BUF_TYPE_PRIMARY,
        .isPolling = 0U,
        .CanObjectType = CANFD_TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 5U,
        .CanControllerId = (uint32)0U,
        .CanIdType = CANFD_STD_AND_EXT_ID,
        .mbIdex = 0U,
        .mbPayloadLength = (uint32)64U,
        .mbType = CANFD_TRANS_BUF_TYPE_SECONDARY,
        .isPolling = 0U,
        .CanObjectType = CANFD_TRANSMIT,
        .CanFdPaddingValue = 0xffU,
        .PeriodIndex = 0U,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 6U,
        .CanControllerId = (uint32)1U,
        .CanIdType = CANFD_STD_AND_EXT_ID,
        .mbIdex = 0U,
        .mbPayloadLength = (uint32)8U,
        .mbType = CANFD_TRANS_BUF_TYPE_PRIMARY,
        .isPolling = 1U,
        .CanObjectType = CANFD_TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 7U,
        .CanControllerId = (uint32)1U,
        .CanIdType = CANFD_STD_AND_EXT_ID,
        .mbIdex = 0U,
        .mbPayloadLength = (uint32)8U,
        .mbType = CANFD_TRANS_BUF_TYPE_SECONDARY,
        .isPolling = 1U,
        .CanObjectType = CANFD_TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
};
#define CAN_176_CANFD_STOP_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"
static CONST(CANFDFilter, CAN_CONST) Filter_0[16U] =
{
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 1U,
            .is_bit_rate_switch = 1U,
            .id = 0x00000101U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 1U,
            .is_bit_rate_switch = 1U,
            .id = 0x00000000U,
        },
        .ac_frame = 0U,
        .am_frame = 0xFFFFFFFFU,
        .is_valid = 1U
    },
    {
        .value =
        {
            .is_extern = 1U,
            .is_fd_format_flag = 1U,
            .is_bit_rate_switch = 1U,
            .id = 0x18ff1001U,
        },
        .mask =
        {
            .is_extern = 1U,
            .is_fd_format_flag = 1U,
            .is_bit_rate_switch = 1U,
            .id = 0x00000000U,
        },
        .ac_frame = 0U,
        .am_frame = 0xFFFFFFFFU,
        .is_valid = 1U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
};
#define CAN_176_CANFD_STOP_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"
static CONST(CANFDFilter, CAN_CONST) Filter_1[16U] =
{
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 1U,
            .is_bit_rate_switch = 1U,
            .id = 0x00000201U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 1U,
            .is_bit_rate_switch = 1U,
            .id = 0x00000000U,
        },
        .ac_frame = 0U,
        .am_frame = 0xFFFFFFFFU,
        .is_valid = 1U
    },
    {
        .value =
        {
            .is_extern = 1U,
            .is_fd_format_flag = 1U,
            .is_bit_rate_switch = 1U,
            .id = 0x18ff2001U,
        },
        .mask =
        {
            .is_extern = 1U,
            .is_fd_format_flag = 1U,
            .is_bit_rate_switch = 1U,
            .id = 0x00000000U,
        },
        .ac_frame = 0U,
        .am_frame = 0xFFFFFFFFU,
        .is_valid = 1U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
    {
        .value =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .mask =
        {
            .is_extern = 0U,
            .is_fd_format_flag = 0U,
            .is_bit_rate_switch = 0U,
            .id = 0U,
        },
        .ac_frame = 0U,
        .am_frame = 0U,
        .is_valid = 0U
    },
};
#define CAN_176_CANFD_STOP_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"
static CONST(CANFDFuncSwitch, CAN_CONST) func_switch_0 =
{
    .tdc_en = 0U,
    .inner_loop_back_en = 0U,
    .outer_loop_back_en = 0U,
    .listen_only_en = 0U
};
#define CAN_176_CANFD_STOP_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"
static CONST(CANFDFuncSwitch, CAN_CONST) func_switch_1 =
{
    .tdc_en = 0U,
    .inner_loop_back_en = 0U,
    .outer_loop_back_en = 0U,
    .listen_only_en = 0U
};
#define CAN_176_CANFD_STOP_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"

/*
                            clockFrequency
    rate = -------------------------------------------------
               brp * (prop_seg + phase_seg1) + phase_seg2
*/
#define CAN_176_CANFD_START_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"
static CONST(CANFDPhyPara, CAN_CONST) phy_para_0[6U] =
{
    {
        .use_bus_clk_src = 1U,
        .baudRateConfigId = 0U,
        .preamble_bit_rate =
        {
            .seg1 = 56U,
            .seg2 = 24U,
            .sjw = 1U,
            .ssp = 0U,
            .prescaler = 2U,
        },
        .data_bit_rate =
        {
            .seg1 = 56U,
            .seg2 = 24U,
            .sjw = 1U,
            .ssp = 0U,
            .prescaler = 2U,
        },
        .brs_ena = FALSE,
    },
    {
        .use_bus_clk_src = 1U,
        .baudRateConfigId = 1U,
        .preamble_bit_rate =
        {
            .seg1 = 56U,
            .seg2 = 24U,
            .sjw = 1U,
            .ssp = 0U,
            .prescaler = 1U,
        },
        .data_bit_rate =
        {
            .seg1 = 56U,
            .seg2 = 24U,
            .sjw = 1U,
            .ssp = 0U,
            .prescaler = 1U,
        },
        .brs_ena = FALSE,
    },
    {
        .use_bus_clk_src = 1U,
        .baudRateConfigId = 2U,
        .preamble_bit_rate =
        {
            .seg1 = 32U,
            .seg2 = 8U,
            .sjw = 1U,
            .ssp = 0U,
            .prescaler = 2U,
        },
        .data_bit_rate =
        {
            .seg1 = 16U,
            .seg2 = 4U,
            .sjw = 2U,
            .ssp = 1U,
            .prescaler = 2U,
        },
        .brs_ena = TRUE,
    },
    {
        .use_bus_clk_src = 1U,
        .baudRateConfigId = 3U,
        .preamble_bit_rate =
        {
            .seg1 = 56U,
            .seg2 = 24U,
            .sjw = 1U,
            .ssp = 0U,
            .prescaler = 1U,
        },
        .data_bit_rate =
        {
            .seg1 = 16U,
            .seg2 = 4U,
            .sjw = 2U,
            .ssp = 1U,
            .prescaler = 1U,
        },
        .brs_ena = TRUE,
    },
    {
        .use_bus_clk_src = 1U,
        .baudRateConfigId = 4U,
        .preamble_bit_rate =
        {
            .seg1 = 32U,
            .seg2 = 8U,
            .sjw = 2U,
            .ssp = 0U,
            .prescaler = 1U,
        },
        .data_bit_rate =
        {
            .seg1 = 6U,
            .seg2 = 2U,
            .sjw = 1U,
            .ssp = 0U,
            .prescaler = 1U,
        },
        .brs_ena = TRUE,
    },
    {
        .use_bus_clk_src = 1U,
        .baudRateConfigId = 5U,
        .preamble_bit_rate =
        {
            .seg1 = 32U,
            .seg2 = 8U,
            .sjw = 2U,
            .ssp = 0U,
            .prescaler = 1U,
        },
        .data_bit_rate =
        {
            .seg1 = 32U,
            .seg2 = 8U,
            .sjw = 2U,
            .ssp = 1U,
            .prescaler = 1U,
        },
        .brs_ena = TRUE,
    },
};
#define CAN_176_CANFD_STOP_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"

/*
                            clockFrequency
    rate = -------------------------------------------------
               brp * (prop_seg + phase_seg1) + phase_seg2
*/
#define CAN_176_CANFD_START_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"
static CONST(CANFDPhyPara, CAN_CONST) phy_para_1[2U] =
{
    {
        .use_bus_clk_src = 1U,
        .baudRateConfigId = 0U,
        .preamble_bit_rate =
        {
            .seg1 = 56U,
            .seg2 = 24U,
            .sjw = 1U,
            .ssp = 0U,
            .prescaler = 1U,
        },
        .data_bit_rate =
        {
            .seg1 = 16U,
            .seg2 = 4U,
            .sjw = 2U,
            .ssp = 0U,
            .prescaler = 1U,
        },
        .brs_ena = TRUE,
    },
    {
        .use_bus_clk_src = 1U,
        .baudRateConfigId = 1U,
        .preamble_bit_rate =
        {
            .seg1 = 32U,
            .seg2 = 8U,
            .sjw = 2U,
            .ssp = 0U,
            .prescaler = 2U,
        },
        .data_bit_rate =
        {
            .seg1 = 16U,
            .seg2 = 4U,
            .sjw = 1U,
            .ssp = 1U,
            .prescaler = 2U,
        },
        .brs_ena = TRUE,
    },
};
#define CAN_176_CANFD_STOP_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"
static CONST(CANFDConfig, CAN_CONST) Canfd_ControllerConfigs[CAN_176_CANFD_CONTROLLER_COUNT] = 
{
    {
        .controllerId = CANFD_MOD_ID_1,
        .supportPolling = 1U,
        .defaultBaudRateId = (uint16)0U,
        .baudRateConfigCount = 6U,
        .phy_para = phy_para_0,
        .func_switch = &func_switch_0,
        .filter = Filter_0,
        .ErrorNotification = NULL_PTR,
        .interconfig = 0xfe010000UL,
    },
    {
        .controllerId = CANFD_MOD_ID_9,
        .supportPolling = 1U,
        .defaultBaudRateId = (uint16)0U,
        .baudRateConfigCount = 2U,
        .phy_para = phy_para_1,
        .func_switch = &func_switch_1,
        .filter = Filter_1,
        .ErrorNotification = &error_notify,
        .interconfig = 0x02000000UL,
    },
};
#define CAN_176_CANFD_STOP_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"

#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
#define CAN_176_CANFD_START_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"
static CONST(CanFd_core_map_t, CAN_CONST) Canfd_CoreMap[CAN_176_CANFD_CONTROLLER_COUNT] =
{
    {
        .controllerId = CANFD_MOD_ID_1,
        .CoreId = 0U
    },
    {
        .controllerId = CANFD_MOD_ID_9,
        .CoreId = 0U
    },
};
#define CAN_176_CANFD_STOP_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"
#endif

#define CAN_176_CANFD_START_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"
CONST(Can_176_CanFD_ConfigType, CAN_CONST) Can_176_CanFD_Config =
{
    .CanFdControllerConfig = Canfd_ControllerConfigs,
    .CanFdHwObjectConfig = Canfd_HardWareObjConfigs,
    .CanFdHwObjCount = CAN_176_CANFD_MB_COUNT,
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
    .CanFdCoreMap = Canfd_CoreMap
#endif
};
#define CAN_176_CANFD_STOP_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"

#endif /* RESOURCE_SUPPORT_CANFD_IP */

#ifdef __cplusplus
}
#endif /* __cplusplus */

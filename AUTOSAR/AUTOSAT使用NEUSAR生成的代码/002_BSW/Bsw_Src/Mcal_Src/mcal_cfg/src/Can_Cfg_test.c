/* PRQA S 0704, 0380, 2053, 1258, 0311, 1533 EOF */
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
/**
*   @file    Can_Cfg.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Can MCAL driver.
*
*   @addtogroup Can
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Can.h"

#define CAN_CFG_C_VENDOR_ID                     176
#define CAN_CFG_C_AR_REL_MAJOR_VER              4
#define CAN_CFG_C_AR_REL_MINOR_VER              4
#define CAN_CFG_C_AR_REL_REV_VER                0
#define CAN_CFG_C_SW_MAJOR_VER                  3
#define CAN_CFG_C_SW_MINOR_VER                  0
#define CAN_CFG_C_SW_PATCH_VER                  0

#if (MCAL_VENDOR_ID != CAN_CFG_C_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_CFG_C_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != CAN_CFG_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_C_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != CAN_CFG_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_C_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != CAN_CFG_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_CFG_C_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != CAN_CFG_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_C_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != CAN_CFG_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_C_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != CAN_CFG_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_CFG_C_SW_PATCH_VER "
#endif



#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwFilter, CAN_CONST) Mcan_HwStandardFilters_Controller0[5U] = 
{
    {
        .CanObjectId = 224U,
        .hwFilterIndex = (uint32)0U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 225U,
        .hwFilterIndex = (uint32)1U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 226U,
        .hwFilterIndex = (uint32)2U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 227U,
        .hwFilterIndex = (uint32)3U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 228U,
        .hwFilterIndex = (uint32)4U,
        .filterRestorePos = FIFO_0,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwFilter, CAN_CONST) Mcan_HwExtendedFilters_Controller0[5U] = 
{
    {
        .CanObjectId = 224U,
        .hwFilterIndex = (uint32)0U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 225U,
        .hwFilterIndex = (uint32)1U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 226U,
        .hwFilterIndex = (uint32)2U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 227U,
        .hwFilterIndex = (uint32)3U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 228U,
        .hwFilterIndex = (uint32)4U,
        .filterRestorePos = FIFO_0,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwFilter, CAN_CONST) Mcan_HwStandardFilters_Controller1[6U] = 
{
    {
        .CanObjectId = 288U,
        .hwFilterIndex = (uint32)0U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 289U,
        .hwFilterIndex = (uint32)1U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 290U,
        .hwFilterIndex = (uint32)2U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 291U,
        .hwFilterIndex = (uint32)3U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 292U,
        .hwFilterIndex = (uint32)4U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 293U,
        .hwFilterIndex = (uint32)5U,
        .filterRestorePos = FIFO_0,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwFilter, CAN_CONST) Mcan_HwExtendedFilters_Controller1[6U] = 
{
    {
        .CanObjectId = 288U,
        .hwFilterIndex = (uint32)0U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 289U,
        .hwFilterIndex = (uint32)1U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 290U,
        .hwFilterIndex = (uint32)2U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 291U,
        .hwFilterIndex = (uint32)3U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 292U,
        .hwFilterIndex = (uint32)4U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 293U,
        .hwFilterIndex = (uint32)5U,
        .filterRestorePos = FIFO_0,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwFilter, CAN_CONST) Mcan_HwStandardFilters_Controller2[5U] = 
{
    {
        .CanObjectId = 352U,
        .hwFilterIndex = (uint32)0U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 353U,
        .hwFilterIndex = (uint32)1U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 354U,
        .hwFilterIndex = (uint32)2U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 355U,
        .hwFilterIndex = (uint32)3U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 356U,
        .hwFilterIndex = (uint32)4U,
        .filterRestorePos = FIFO_0,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwFilter, CAN_CONST) Mcan_HwExtendedFilters_Controller2[5U] = 
{
    {
        .CanObjectId = 352U,
        .hwFilterIndex = (uint32)0U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 353U,
        .hwFilterIndex = (uint32)1U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 354U,
        .hwFilterIndex = (uint32)2U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 355U,
        .hwFilterIndex = (uint32)3U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 356U,
        .hwFilterIndex = (uint32)4U,
        .filterRestorePos = FIFO_0,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwFilter, CAN_CONST) Mcan_HwStandardFilters_Controller3[5U] = 
{
    {
        .CanObjectId = 416U,
        .hwFilterIndex = (uint32)0U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 417U,
        .hwFilterIndex = (uint32)1U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 418U,
        .hwFilterIndex = (uint32)2U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 419U,
        .hwFilterIndex = (uint32)3U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 420U,
        .hwFilterIndex = (uint32)4U,
        .filterRestorePos = FIFO_0,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwFilter, CAN_CONST) Mcan_HwExtendedFilters_Controller3[5U] = 
{
    {
        .CanObjectId = 416U,
        .hwFilterIndex = (uint32)0U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 417U,
        .hwFilterIndex = (uint32)1U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 418U,
        .hwFilterIndex = (uint32)2U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 419U,
        .hwFilterIndex = (uint32)3U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 420U,
        .hwFilterIndex = (uint32)4U,
        .filterRestorePos = FIFO_0,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwFilter, CAN_CONST) Mcan_HwStandardFilters_Controller4[5U] = 
{
    {
        .CanObjectId = 480U,
        .hwFilterIndex = (uint32)0U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 481U,
        .hwFilterIndex = (uint32)1U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 482U,
        .hwFilterIndex = (uint32)2U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 483U,
        .hwFilterIndex = (uint32)3U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 484U,
        .hwFilterIndex = (uint32)4U,
        .filterRestorePos = FIFO_0,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwFilter, CAN_CONST) Mcan_HwExtendedFilters_Controller4[5U] = 
{
    {
        .CanObjectId = 480U,
        .hwFilterIndex = (uint32)0U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 481U,
        .hwFilterIndex = (uint32)1U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 482U,
        .hwFilterIndex = (uint32)2U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 483U,
        .hwFilterIndex = (uint32)3U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 484U,
        .hwFilterIndex = (uint32)4U,
        .filterRestorePos = FIFO_0,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwFilter, CAN_CONST) Mcan_HwStandardFilters_Controller5[6U] = 
{
    {
        .CanObjectId = 544U,
        .hwFilterIndex = (uint32)0U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 545U,
        .hwFilterIndex = (uint32)1U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 546U,
        .hwFilterIndex = (uint32)2U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 547U,
        .hwFilterIndex = (uint32)3U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 548U,
        .hwFilterIndex = (uint32)4U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 549U,
        .hwFilterIndex = (uint32)5U,
        .filterRestorePos = FIFO_0,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwFilter, CAN_CONST) Mcan_HwExtendedFilters_Controller5[6U] = 
{
    {
        .CanObjectId = 544U,
        .hwFilterIndex = (uint32)0U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 545U,
        .hwFilterIndex = (uint32)1U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 546U,
        .hwFilterIndex = (uint32)2U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 547U,
        .hwFilterIndex = (uint32)3U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 548U,
        .hwFilterIndex = (uint32)4U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 549U,
        .hwFilterIndex = (uint32)5U,
        .filterRestorePos = FIFO_0,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwFilter, CAN_CONST) Mcan_HwStandardFilters_Controller6[5U] = 
{
    {
        .CanObjectId = 608U,
        .hwFilterIndex = (uint32)0U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 609U,
        .hwFilterIndex = (uint32)1U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 610U,
        .hwFilterIndex = (uint32)2U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 611U,
        .hwFilterIndex = (uint32)3U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 612U,
        .hwFilterIndex = (uint32)4U,
        .filterRestorePos = FIFO_0,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwFilter, CAN_CONST) Mcan_HwExtendedFilters_Controller6[5U] = 
{
    {
        .CanObjectId = 608U,
        .hwFilterIndex = (uint32)0U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 609U,
        .hwFilterIndex = (uint32)1U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 610U,
        .hwFilterIndex = (uint32)2U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 611U,
        .hwFilterIndex = (uint32)3U,
        .filterRestorePos = FIFO_0,
    },
    {
        .CanObjectId = 612U,
        .hwFilterIndex = (uint32)4U,
        .filterRestorePos = FIFO_0,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwObject, CAN_CONST) Mcan_TxObjConfigs_Controller0[32U] = 
{
    {
        .CanObjectId = 0U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 0U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 1U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 1U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 2U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 2U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 3U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 3U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 4U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 4U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 5U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 5U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 6U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 6U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 7U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 7U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 8U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 8U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 9U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 9U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 10U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 10U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 11U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 11U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 12U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 12U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 13U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 13U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 14U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 14U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 15U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 15U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 16U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 16U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 17U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 17U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 18U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 18U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 19U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 19U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 20U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 20U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 21U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 21U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 22U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 22U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 23U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 23U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 24U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 24U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 25U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 25U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 26U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 26U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 27U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 27U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 28U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 28U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 29U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 29U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 30U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 30U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 31U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 31U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
/* The number of elements that belong to CONTROLLERx and are received in the original Mcan_HardWareObjConfigs array */
static CONST(mcan_hwObject, CAN_CONST) Mcan_RxObjConfigs_Controller0[10U] = 
{
    {
        .CanObjectId = 224U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013dU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 224U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013dU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 225U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013eU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 225U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013eU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 226U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013fU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 226U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013fU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 227U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000711U,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 227U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000711U,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 228U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000741U,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 228U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000741U,
        .filterMask = 0x000007ffU,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwObject, CAN_CONST) Mcan_TxObjConfigs_Controller1[32U] = 
{
    {
        .CanObjectId = 32U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 0U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 33U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 1U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 34U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 2U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 35U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 3U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 36U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 4U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 37U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 5U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 38U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 6U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 39U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 7U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 40U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 8U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 41U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 9U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 42U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 10U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 43U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 11U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 44U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 12U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 45U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 13U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 46U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 14U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 47U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 15U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 48U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 16U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 49U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 17U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 50U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 18U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 51U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 19U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 52U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 20U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 53U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 21U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 54U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 22U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 55U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 23U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 56U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 24U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 57U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 25U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 58U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 26U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 59U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 27U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 60U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 28U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 61U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 29U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 62U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 30U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 63U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 31U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
/* The number of elements that belong to CONTROLLERx and are received in the original Mcan_HardWareObjConfigs array */
static CONST(mcan_hwObject, CAN_CONST) Mcan_RxObjConfigs_Controller1[12U] = 
{
    {
        .CanObjectId = 288U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013dU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 288U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013dU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 289U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013eU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 289U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013eU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 290U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013fU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 290U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013fU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 291U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000711U,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 291U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000711U,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 292U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000741U,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 292U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000741U,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 293U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x000007e6U,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 293U,
        .CanControllerId = (uint32)1U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x000007e6U,
        .filterMask = 0x000007ffU,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwObject, CAN_CONST) Mcan_TxObjConfigs_Controller2[32U] = 
{
    {
        .CanObjectId = 64U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 0U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 65U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 1U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 66U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 2U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 67U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 3U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 68U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 4U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 69U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 5U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 70U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 6U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 71U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 7U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 72U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 8U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 73U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 9U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 74U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 10U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 75U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 11U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 76U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 12U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 77U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 13U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 78U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 14U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 79U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 15U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 80U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 16U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 81U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 17U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 82U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 18U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 83U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 19U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 84U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 20U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 85U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 21U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 86U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 22U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 87U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 23U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 88U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 24U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 89U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 25U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 90U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 26U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 91U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 27U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 92U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 28U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 93U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 29U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 94U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 30U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 95U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 31U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
/* The number of elements that belong to CONTROLLERx and are received in the original Mcan_HardWareObjConfigs array */
static CONST(mcan_hwObject, CAN_CONST) Mcan_RxObjConfigs_Controller2[10U] = 
{
    {
        .CanObjectId = 352U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013dU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 352U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013dU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 353U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013eU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 353U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013eU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 354U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013fU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 354U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013fU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 355U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000711U,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 355U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000711U,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 356U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000741U,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 356U,
        .CanControllerId = (uint32)2U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 2U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000741U,
        .filterMask = 0x000007ffU,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwObject, CAN_CONST) Mcan_TxObjConfigs_Controller3[32U] = 
{
    {
        .CanObjectId = 96U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 0U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 97U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 1U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 98U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 2U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 99U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 3U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 100U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 4U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 101U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 5U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 102U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 6U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 103U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 7U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 104U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 8U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 105U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 9U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 106U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 10U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 107U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 11U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 108U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 12U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 109U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 13U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 110U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 14U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 111U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 15U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 112U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 16U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 113U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 17U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 114U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 18U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 115U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 19U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 116U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 20U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 117U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 21U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 118U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 22U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 119U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 23U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 120U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 24U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 121U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 25U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 122U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 26U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 123U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 27U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 124U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 28U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 125U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 29U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 126U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 30U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 127U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 31U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
/* The number of elements that belong to CONTROLLERx and are received in the original Mcan_HardWareObjConfigs array */
static CONST(mcan_hwObject, CAN_CONST) Mcan_RxObjConfigs_Controller3[10U] = 
{
    {
        .CanObjectId = 416U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013dU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 416U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013dU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 417U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013eU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 417U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013eU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 418U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013fU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 418U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013fU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 419U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000711U,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 419U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000711U,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 420U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000741U,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 420U,
        .CanControllerId = (uint32)3U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 3U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000741U,
        .filterMask = 0x000007ffU,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwObject, CAN_CONST) Mcan_TxObjConfigs_Controller4[32U] = 
{
    {
        .CanObjectId = 128U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 0U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 129U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 1U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 130U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 2U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 131U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 3U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 132U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 4U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 133U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 5U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 134U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 6U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 135U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 7U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 136U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 8U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 137U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 9U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 138U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 10U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 139U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 11U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 140U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 12U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 141U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 13U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 142U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 14U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 143U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 15U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 144U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 16U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 145U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 17U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 146U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 18U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 147U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 19U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 148U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 20U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 149U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 21U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 150U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 22U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 151U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 23U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 152U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 24U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 153U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 25U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 154U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 26U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 155U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 27U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 156U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 28U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 157U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 29U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 158U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 30U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 159U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 31U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
/* The number of elements that belong to CONTROLLERx and are received in the original Mcan_HardWareObjConfigs array */
static CONST(mcan_hwObject, CAN_CONST) Mcan_RxObjConfigs_Controller4[10U] = 
{
    {
        .CanObjectId = 480U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013dU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 480U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013dU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 481U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013eU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 481U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013eU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 482U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013fU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 482U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013fU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 483U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000711U,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 483U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000711U,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 484U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000741U,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 484U,
        .CanControllerId = (uint32)4U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 4U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000741U,
        .filterMask = 0x000007ffU,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwObject, CAN_CONST) Mcan_TxObjConfigs_Controller5[32U] = 
{
    {
        .CanObjectId = 160U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 0U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 161U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 1U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 162U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 2U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 163U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 3U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 164U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 4U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 165U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 5U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 166U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 6U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 167U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 7U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 168U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 8U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 169U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 9U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 170U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 10U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 171U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 11U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 172U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 12U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 173U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 13U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 174U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 14U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 175U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 15U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 176U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 16U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 177U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 17U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 178U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 18U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 179U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 19U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 180U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 20U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 181U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 21U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 182U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 22U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 183U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 23U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 184U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 24U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 185U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 25U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 186U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 26U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 187U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 27U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 188U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 28U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 189U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 29U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 190U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 30U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 191U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 31U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
/* The number of elements that belong to CONTROLLERx and are received in the original Mcan_HardWareObjConfigs array */
static CONST(mcan_hwObject, CAN_CONST) Mcan_RxObjConfigs_Controller5[12U] = 
{
    {
        .CanObjectId = 544U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013dU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 544U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013dU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 545U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013eU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 545U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013eU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 546U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013fU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 546U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013fU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 547U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000711U,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 547U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000711U,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 548U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000741U,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 548U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000741U,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 549U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x000007f0U,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 549U,
        .CanControllerId = (uint32)5U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 5U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x000007f0U,
        .filterMask = 0x000007ffU,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_hwObject, CAN_CONST) Mcan_TxObjConfigs_Controller6[32U] = 
{
    {
        .CanObjectId = 192U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 0U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 193U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 1U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 194U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 2U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 195U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 3U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 196U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 4U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 197U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 5U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 198U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 6U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 199U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 7U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 200U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 8U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 201U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 9U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 202U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 10U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 203U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 11U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 204U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 12U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 205U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 13U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 206U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 14U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 207U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 15U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 208U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 16U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 209U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 17U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 210U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 18U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 211U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 19U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 212U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 20U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 213U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 21U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 214U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 22U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 215U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 23U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 216U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 24U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 217U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 25U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 218U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 26U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 219U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 27U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 220U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 28U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 221U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 29U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 222U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 30U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
    {
        .CanObjectId = 223U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = 31U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0U,
        .filterMask = 0x0U,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
/* The number of elements that belong to CONTROLLERx and are received in the original Mcan_HardWareObjConfigs array */
static CONST(mcan_hwObject, CAN_CONST) Mcan_RxObjConfigs_Controller6[10U] = 
{
    {
        .CanObjectId = 608U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013dU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 608U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013dU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 609U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013eU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 609U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013eU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 610U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013fU,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 610U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x0000013fU,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 611U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000711U,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 611U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000711U,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 612U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000741U,
        .filterMask = 0x1fffffffU,
    },
    {
        .CanObjectId = 612U,
        .CanControllerId = (uint32)6U,
        .CanIdType = STD_AND_EXT_ID,
        .mbIdex = MCAN_STORE_RX_FIFO0,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 0U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 6U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000741U,
        .filterMask = 0x000007ffU,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
/*txObjCount and rxObjCount is Mcan_RxObjConfigs_Controller0 and Mcan_TxObjConfigs_Controller0 number of elements*/
static CONST(mcan_hwObject_info, CAN_CONST) Mcan_HardWareObjConfigs[CAN_CONTROLLER_COUNT] = 
{
    {
        .txObjectConfig = Mcan_TxObjConfigs_Controller0,
        .rxObjectConfig = Mcan_RxObjConfigs_Controller0,
        .standardFilterConfig = Mcan_HwStandardFilters_Controller0,
        .extendedFilterConfig = Mcan_HwExtendedFilters_Controller0,
        .txObjCount = 32U,
        .rxObjCount = 10U,
        .standardFilterCount = 5U,
        .extendedFilterCount = 5U
    },
    {
        .txObjectConfig = Mcan_TxObjConfigs_Controller1,
        .rxObjectConfig = Mcan_RxObjConfigs_Controller1,
        .standardFilterConfig = Mcan_HwStandardFilters_Controller1,
        .extendedFilterConfig = Mcan_HwExtendedFilters_Controller1,
        .txObjCount = 32U,
        .rxObjCount = 12U,
        .standardFilterCount = 6U,
        .extendedFilterCount = 6U
    },
    {
        .txObjectConfig = Mcan_TxObjConfigs_Controller2,
        .rxObjectConfig = Mcan_RxObjConfigs_Controller2,
        .standardFilterConfig = Mcan_HwStandardFilters_Controller2,
        .extendedFilterConfig = Mcan_HwExtendedFilters_Controller2,
        .txObjCount = 32U,
        .rxObjCount = 10U,
        .standardFilterCount = 5U,
        .extendedFilterCount = 5U
    },
    {
        .txObjectConfig = Mcan_TxObjConfigs_Controller3,
        .rxObjectConfig = Mcan_RxObjConfigs_Controller3,
        .standardFilterConfig = Mcan_HwStandardFilters_Controller3,
        .extendedFilterConfig = Mcan_HwExtendedFilters_Controller3,
        .txObjCount = 32U,
        .rxObjCount = 10U,
        .standardFilterCount = 5U,
        .extendedFilterCount = 5U
    },
    {
        .txObjectConfig = Mcan_TxObjConfigs_Controller4,
        .rxObjectConfig = Mcan_RxObjConfigs_Controller4,
        .standardFilterConfig = Mcan_HwStandardFilters_Controller4,
        .extendedFilterConfig = Mcan_HwExtendedFilters_Controller4,
        .txObjCount = 32U,
        .rxObjCount = 10U,
        .standardFilterCount = 5U,
        .extendedFilterCount = 5U
    },
    {
        .txObjectConfig = Mcan_TxObjConfigs_Controller5,
        .rxObjectConfig = Mcan_RxObjConfigs_Controller5,
        .standardFilterConfig = Mcan_HwStandardFilters_Controller5,
        .extendedFilterConfig = Mcan_HwExtendedFilters_Controller5,
        .txObjCount = 32U,
        .rxObjCount = 12U,
        .standardFilterCount = 6U,
        .extendedFilterCount = 6U
    },
    {
        .txObjectConfig = Mcan_TxObjConfigs_Controller6,
        .rxObjectConfig = Mcan_RxObjConfigs_Controller6,
        .standardFilterConfig = Mcan_HwStandardFilters_Controller6,
        .extendedFilterConfig = Mcan_HwExtendedFilters_Controller6,
        .txObjCount = 32U,
        .rxObjCount = 10U,
        .standardFilterCount = 5U,
        .extendedFilterCount = 5U
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
/* 
The number of object macros such as CanHardwareObject_201 in Can_Cfg.h includes the received ones. 
Both CanObjectId and hth can be used as indexes. In the receiving case, mbBitmap is 00
*/
static CONST(mcan_hth_map, CAN_CONST) Mcan_ObjMap[CAN_OBJECT_COUNT] = 
{
    {
        .objectId = (uint32)0U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x80000000U,
    },
    {
        .objectId = (uint32)1U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x40000000U,
    },
    {
        .objectId = (uint32)2U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x20000000U,
    },
    {
        .objectId = (uint32)3U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x10000000U,
    },
    {
        .objectId = (uint32)4U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x8000000U,
    },
    {
        .objectId = (uint32)5U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x4000000U,
    },
    {
        .objectId = (uint32)6U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x2000000U,
    },
    {
        .objectId = (uint32)7U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x1000000U,
    },
    {
        .objectId = (uint32)8U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x800000U,
    },
    {
        .objectId = (uint32)9U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x400000U,
    },
    {
        .objectId = (uint32)10U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x200000U,
    },
    {
        .objectId = (uint32)11U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x100000U,
    },
    {
        .objectId = (uint32)12U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x80000U,
    },
    {
        .objectId = (uint32)13U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x40000U,
    },
    {
        .objectId = (uint32)14U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x20000U,
    },
    {
        .objectId = (uint32)15U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x10000U,
    },
    {
        .objectId = (uint32)16U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x8000U,
    },
    {
        .objectId = (uint32)17U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x4000U,
    },
    {
        .objectId = (uint32)18U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x2000U,
    },
    {
        .objectId = (uint32)19U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x1000U,
    },
    {
        .objectId = (uint32)20U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x800U,
    },
    {
        .objectId = (uint32)21U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x400U,
    },
    {
        .objectId = (uint32)22U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x200U,
    },
    {
        .objectId = (uint32)23U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x100U,
    },
    {
        .objectId = (uint32)24U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x80U,
    },
    {
        .objectId = (uint32)25U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x40U,
    },
    {
        .objectId = (uint32)26U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x20U,
    },
    {
        .objectId = (uint32)27U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x10U,
    },
    {
        .objectId = (uint32)28U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x8U,
    },
    {
        .objectId = (uint32)29U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x4U,
    },
    {
        .objectId = (uint32)30U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x2U,
    },
    {
        .objectId = (uint32)31U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0x1U,
    },
    {
        .objectId = (uint32)32U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x80000000U,
    },
    {
        .objectId = (uint32)33U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x40000000U,
    },
    {
        .objectId = (uint32)34U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x20000000U,
    },
    {
        .objectId = (uint32)35U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x10000000U,
    },
    {
        .objectId = (uint32)36U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x8000000U,
    },
    {
        .objectId = (uint32)37U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x4000000U,
    },
    {
        .objectId = (uint32)38U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x2000000U,
    },
    {
        .objectId = (uint32)39U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x1000000U,
    },
    {
        .objectId = (uint32)40U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x800000U,
    },
    {
        .objectId = (uint32)41U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x400000U,
    },
    {
        .objectId = (uint32)42U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x200000U,
    },
    {
        .objectId = (uint32)43U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x100000U,
    },
    {
        .objectId = (uint32)44U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x80000U,
    },
    {
        .objectId = (uint32)45U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x40000U,
    },
    {
        .objectId = (uint32)46U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x20000U,
    },
    {
        .objectId = (uint32)47U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x10000U,
    },
    {
        .objectId = (uint32)48U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x8000U,
    },
    {
        .objectId = (uint32)49U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x4000U,
    },
    {
        .objectId = (uint32)50U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x2000U,
    },
    {
        .objectId = (uint32)51U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x1000U,
    },
    {
        .objectId = (uint32)52U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x800U,
    },
    {
        .objectId = (uint32)53U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x400U,
    },
    {
        .objectId = (uint32)54U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x200U,
    },
    {
        .objectId = (uint32)55U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x100U,
    },
    {
        .objectId = (uint32)56U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x80U,
    },
    {
        .objectId = (uint32)57U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x40U,
    },
    {
        .objectId = (uint32)58U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x20U,
    },
    {
        .objectId = (uint32)59U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x10U,
    },
    {
        .objectId = (uint32)60U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x8U,
    },
    {
        .objectId = (uint32)61U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x4U,
    },
    {
        .objectId = (uint32)62U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x2U,
    },
    {
        .objectId = (uint32)63U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0x1U,
    },
    {
        .objectId = (uint32)64U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x80000000U,
    },
    {
        .objectId = (uint32)65U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x40000000U,
    },
    {
        .objectId = (uint32)66U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x20000000U,
    },
    {
        .objectId = (uint32)67U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x10000000U,
    },
    {
        .objectId = (uint32)68U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x8000000U,
    },
    {
        .objectId = (uint32)69U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x4000000U,
    },
    {
        .objectId = (uint32)70U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x2000000U,
    },
    {
        .objectId = (uint32)71U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x1000000U,
    },
    {
        .objectId = (uint32)72U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x800000U,
    },
    {
        .objectId = (uint32)73U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x400000U,
    },
    {
        .objectId = (uint32)74U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x200000U,
    },
    {
        .objectId = (uint32)75U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x100000U,
    },
    {
        .objectId = (uint32)76U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x80000U,
    },
    {
        .objectId = (uint32)77U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x40000U,
    },
    {
        .objectId = (uint32)78U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x20000U,
    },
    {
        .objectId = (uint32)79U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x10000U,
    },
    {
        .objectId = (uint32)80U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x8000U,
    },
    {
        .objectId = (uint32)81U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x4000U,
    },
    {
        .objectId = (uint32)82U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x2000U,
    },
    {
        .objectId = (uint32)83U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x1000U,
    },
    {
        .objectId = (uint32)84U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x800U,
    },
    {
        .objectId = (uint32)85U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x400U,
    },
    {
        .objectId = (uint32)86U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x200U,
    },
    {
        .objectId = (uint32)87U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x100U,
    },
    {
        .objectId = (uint32)88U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x80U,
    },
    {
        .objectId = (uint32)89U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x40U,
    },
    {
        .objectId = (uint32)90U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x20U,
    },
    {
        .objectId = (uint32)91U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x10U,
    },
    {
        .objectId = (uint32)92U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x8U,
    },
    {
        .objectId = (uint32)93U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x4U,
    },
    {
        .objectId = (uint32)94U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x2U,
    },
    {
        .objectId = (uint32)95U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0x1U,
    },
    {
        .objectId = (uint32)96U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x80000000U,
    },
    {
        .objectId = (uint32)97U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x40000000U,
    },
    {
        .objectId = (uint32)98U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x20000000U,
    },
    {
        .objectId = (uint32)99U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x10000000U,
    },
    {
        .objectId = (uint32)100U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x8000000U,
    },
    {
        .objectId = (uint32)101U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x4000000U,
    },
    {
        .objectId = (uint32)102U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x2000000U,
    },
    {
        .objectId = (uint32)103U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x1000000U,
    },
    {
        .objectId = (uint32)104U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x800000U,
    },
    {
        .objectId = (uint32)105U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x400000U,
    },
    {
        .objectId = (uint32)106U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x200000U,
    },
    {
        .objectId = (uint32)107U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x100000U,
    },
    {
        .objectId = (uint32)108U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x80000U,
    },
    {
        .objectId = (uint32)109U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x40000U,
    },
    {
        .objectId = (uint32)110U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x20000U,
    },
    {
        .objectId = (uint32)111U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x10000U,
    },
    {
        .objectId = (uint32)112U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x8000U,
    },
    {
        .objectId = (uint32)113U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x4000U,
    },
    {
        .objectId = (uint32)114U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x2000U,
    },
    {
        .objectId = (uint32)115U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x1000U,
    },
    {
        .objectId = (uint32)116U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x800U,
    },
    {
        .objectId = (uint32)117U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x400U,
    },
    {
        .objectId = (uint32)118U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x200U,
    },
    {
        .objectId = (uint32)119U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x100U,
    },
    {
        .objectId = (uint32)120U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x80U,
    },
    {
        .objectId = (uint32)121U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x40U,
    },
    {
        .objectId = (uint32)122U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x20U,
    },
    {
        .objectId = (uint32)123U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x10U,
    },
    {
        .objectId = (uint32)124U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x8U,
    },
    {
        .objectId = (uint32)125U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x4U,
    },
    {
        .objectId = (uint32)126U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x2U,
    },
    {
        .objectId = (uint32)127U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0x1U,
    },
    {
        .objectId = (uint32)128U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x80000000U,
    },
    {
        .objectId = (uint32)129U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x40000000U,
    },
    {
        .objectId = (uint32)130U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x20000000U,
    },
    {
        .objectId = (uint32)131U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x10000000U,
    },
    {
        .objectId = (uint32)132U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x8000000U,
    },
    {
        .objectId = (uint32)133U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x4000000U,
    },
    {
        .objectId = (uint32)134U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x2000000U,
    },
    {
        .objectId = (uint32)135U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x1000000U,
    },
    {
        .objectId = (uint32)136U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x800000U,
    },
    {
        .objectId = (uint32)137U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x400000U,
    },
    {
        .objectId = (uint32)138U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x200000U,
    },
    {
        .objectId = (uint32)139U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x100000U,
    },
    {
        .objectId = (uint32)140U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x80000U,
    },
    {
        .objectId = (uint32)141U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x40000U,
    },
    {
        .objectId = (uint32)142U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x20000U,
    },
    {
        .objectId = (uint32)143U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x10000U,
    },
    {
        .objectId = (uint32)144U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x8000U,
    },
    {
        .objectId = (uint32)145U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x4000U,
    },
    {
        .objectId = (uint32)146U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x2000U,
    },
    {
        .objectId = (uint32)147U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x1000U,
    },
    {
        .objectId = (uint32)148U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x800U,
    },
    {
        .objectId = (uint32)149U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x400U,
    },
    {
        .objectId = (uint32)150U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x200U,
    },
    {
        .objectId = (uint32)151U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x100U,
    },
    {
        .objectId = (uint32)152U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x80U,
    },
    {
        .objectId = (uint32)153U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x40U,
    },
    {
        .objectId = (uint32)154U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x20U,
    },
    {
        .objectId = (uint32)155U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x10U,
    },
    {
        .objectId = (uint32)156U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x8U,
    },
    {
        .objectId = (uint32)157U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x4U,
    },
    {
        .objectId = (uint32)158U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x2U,
    },
    {
        .objectId = (uint32)159U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0x1U,
    },
    {
        .objectId = (uint32)160U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x80000000U,
    },
    {
        .objectId = (uint32)161U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x40000000U,
    },
    {
        .objectId = (uint32)162U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x20000000U,
    },
    {
        .objectId = (uint32)163U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x10000000U,
    },
    {
        .objectId = (uint32)164U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x8000000U,
    },
    {
        .objectId = (uint32)165U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x4000000U,
    },
    {
        .objectId = (uint32)166U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x2000000U,
    },
    {
        .objectId = (uint32)167U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x1000000U,
    },
    {
        .objectId = (uint32)168U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x800000U,
    },
    {
        .objectId = (uint32)169U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x400000U,
    },
    {
        .objectId = (uint32)170U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x200000U,
    },
    {
        .objectId = (uint32)171U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x100000U,
    },
    {
        .objectId = (uint32)172U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x80000U,
    },
    {
        .objectId = (uint32)173U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x40000U,
    },
    {
        .objectId = (uint32)174U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x20000U,
    },
    {
        .objectId = (uint32)175U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x10000U,
    },
    {
        .objectId = (uint32)176U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x8000U,
    },
    {
        .objectId = (uint32)177U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x4000U,
    },
    {
        .objectId = (uint32)178U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x2000U,
    },
    {
        .objectId = (uint32)179U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x1000U,
    },
    {
        .objectId = (uint32)180U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x800U,
    },
    {
        .objectId = (uint32)181U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x400U,
    },
    {
        .objectId = (uint32)182U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x200U,
    },
    {
        .objectId = (uint32)183U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x100U,
    },
    {
        .objectId = (uint32)184U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x80U,
    },
    {
        .objectId = (uint32)185U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x40U,
    },
    {
        .objectId = (uint32)186U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x20U,
    },
    {
        .objectId = (uint32)187U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x10U,
    },
    {
        .objectId = (uint32)188U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x8U,
    },
    {
        .objectId = (uint32)189U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x4U,
    },
    {
        .objectId = (uint32)190U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x2U,
    },
    {
        .objectId = (uint32)191U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0x1U,
    },
    {
        .objectId = (uint32)192U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x80000000U,
    },
    {
        .objectId = (uint32)193U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x40000000U,
    },
    {
        .objectId = (uint32)194U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x20000000U,
    },
    {
        .objectId = (uint32)195U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x10000000U,
    },
    {
        .objectId = (uint32)196U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x8000000U,
    },
    {
        .objectId = (uint32)197U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x4000000U,
    },
    {
        .objectId = (uint32)198U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x2000000U,
    },
    {
        .objectId = (uint32)199U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x1000000U,
    },
    {
        .objectId = (uint32)200U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x800000U,
    },
    {
        .objectId = (uint32)201U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x400000U,
    },
    {
        .objectId = (uint32)202U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x200000U,
    },
    {
        .objectId = (uint32)203U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x100000U,
    },
    {
        .objectId = (uint32)204U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x80000U,
    },
    {
        .objectId = (uint32)205U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x40000U,
    },
    {
        .objectId = (uint32)206U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x20000U,
    },
    {
        .objectId = (uint32)207U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x10000U,
    },
    {
        .objectId = (uint32)208U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x8000U,
    },
    {
        .objectId = (uint32)209U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x4000U,
    },
    {
        .objectId = (uint32)210U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x2000U,
    },
    {
        .objectId = (uint32)211U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x1000U,
    },
    {
        .objectId = (uint32)212U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x800U,
    },
    {
        .objectId = (uint32)213U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x400U,
    },
    {
        .objectId = (uint32)214U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x200U,
    },
    {
        .objectId = (uint32)215U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x100U,
    },
    {
        .objectId = (uint32)216U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x80U,
    },
    {
        .objectId = (uint32)217U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x40U,
    },
    {
        .objectId = (uint32)218U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x20U,
    },
    {
        .objectId = (uint32)219U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x10U,
    },
    {
        .objectId = (uint32)220U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x8U,
    },
    {
        .objectId = (uint32)221U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x4U,
    },
    {
        .objectId = (uint32)222U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x2U,
    },
    {
        .objectId = (uint32)223U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0x1U,
    },
    {
        .objectId = (uint32)224U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)225U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)226U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)227U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)228U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)229U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)230U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)231U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)232U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)233U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)234U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)235U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)236U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)237U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)238U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)239U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)240U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)241U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)242U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)243U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)244U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)245U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)246U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)247U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)248U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)249U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)250U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)251U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)252U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)253U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)254U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)255U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)256U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)257U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)258U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)259U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)260U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)261U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)262U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)263U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)264U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)265U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)266U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)267U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)268U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)269U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)270U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)271U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)272U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)273U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)274U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)275U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)276U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)277U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)278U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)279U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)280U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)281U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)282U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)283U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)284U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)285U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)286U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)287U,
        .controllerId = (uint32)0U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)288U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)289U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)290U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)291U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)292U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)293U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)294U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)295U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)296U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)297U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)298U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)299U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)300U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)301U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)302U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)303U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)304U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)305U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)306U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)307U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)308U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)309U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)310U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)311U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)312U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)313U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)314U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)315U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)316U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)317U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)318U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)319U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)320U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)321U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)322U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)323U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)324U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)325U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)326U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)327U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)328U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)329U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)330U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)331U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)332U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)333U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)334U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)335U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)336U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)337U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)338U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)339U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)340U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)341U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)342U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)343U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)344U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)345U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)346U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)347U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)348U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)349U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)350U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)351U,
        .controllerId = (uint32)1U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)352U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)353U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)354U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)355U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)356U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)357U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)358U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)359U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)360U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)361U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)362U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)363U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)364U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)365U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)366U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)367U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)368U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)369U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)370U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)371U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)372U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)373U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)374U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)375U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)376U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)377U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)378U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)379U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)380U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)381U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)382U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)383U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)384U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)385U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)386U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)387U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)388U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)389U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)390U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)391U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)392U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)393U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)394U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)395U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)396U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)397U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)398U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)399U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)400U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)401U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)402U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)403U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)404U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)405U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)406U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)407U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)408U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)409U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)410U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)411U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)412U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)413U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)414U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)415U,
        .controllerId = (uint32)2U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)416U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)417U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)418U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)419U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)420U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)421U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)422U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)423U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)424U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)425U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)426U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)427U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)428U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)429U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)430U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)431U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)432U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)433U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)434U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)435U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)436U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)437U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)438U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)439U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)440U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)441U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)442U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)443U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)444U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)445U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)446U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)447U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)448U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)449U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)450U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)451U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)452U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)453U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)454U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)455U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)456U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)457U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)458U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)459U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)460U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)461U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)462U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)463U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)464U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)465U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)466U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)467U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)468U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)469U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)470U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)471U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)472U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)473U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)474U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)475U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)476U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)477U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)478U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)479U,
        .controllerId = (uint32)3U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)480U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)481U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)482U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)483U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)484U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)485U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)486U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)487U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)488U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)489U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)490U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)491U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)492U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)493U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)494U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)495U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)496U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)497U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)498U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)499U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)500U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)501U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)502U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)503U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)504U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)505U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)506U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)507U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)508U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)509U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)510U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)511U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)512U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)513U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)514U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)515U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)516U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)517U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)518U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)519U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)520U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)521U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)522U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)523U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)524U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)525U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)526U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)527U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)528U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)529U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)530U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)531U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)532U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)533U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)534U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)535U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)536U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)537U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)538U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)539U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)540U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)541U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)542U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)543U,
        .controllerId = (uint32)4U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)544U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)545U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)546U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)547U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)548U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)549U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)550U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)551U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)552U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)553U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)554U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)555U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)556U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)557U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)558U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)559U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)560U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)561U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)562U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)563U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)564U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)565U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)566U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)567U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)568U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)569U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)570U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)571U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)572U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)573U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)574U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)575U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)576U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)577U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)578U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)579U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)580U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)581U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)582U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)583U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)584U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)585U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)586U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)587U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)588U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)589U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)590U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)591U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)592U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)593U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)594U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)595U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)596U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)597U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)598U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)599U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)600U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)601U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)602U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)603U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)604U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)605U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)606U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)607U,
        .controllerId = (uint32)5U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)608U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)609U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)610U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)611U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)612U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)613U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)614U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)615U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)616U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)617U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)618U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)619U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)620U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)621U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)622U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)623U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)624U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)625U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)626U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)627U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)628U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)629U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)630U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)631U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)632U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)633U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)634U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)635U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)636U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)637U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)638U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)639U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)640U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)641U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)642U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)643U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)644U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)645U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)646U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)647U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)648U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)649U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)650U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)651U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)652U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)653U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)654U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)655U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)656U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)657U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)658U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)659U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)660U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)661U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)662U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)663U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)664U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)665U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)666U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)667U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)668U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)669U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)670U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
    {
        .objectId = (uint32)671U,
        .controllerId = (uint32)6U,
        .mbBitmap = 0U,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"


#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(McanControlInfor, CAN_CONST) MCAN_CTRL[12U] =
{
    {
        .CanId = MCAN_MOD_ID_1,
        .IsUsed = TRUE,
        .BaseWord = 0UL,
        .mram_size_words = 1920UL,
    },
    {
        .CanId = MCAN_MOD_ID_2,
        .IsUsed = TRUE,
        .BaseWord = 1920UL,
        .mram_size_words = 1920UL,
    },
    {
        .CanId = MCAN_MOD_ID_3,
        .IsUsed = TRUE,
        .BaseWord = 3840UL,
        .mram_size_words = 1920UL,
    },
    {
        .CanId = MCAN_MOD_ID_4,
        .IsUsed = FALSE,
        .BaseWord = 5760UL,
        .mram_size_words = 0UL,
    },
    {
        .CanId = MCAN_MOD_ID_5,
        .IsUsed = FALSE,
        .BaseWord = 0UL,
        .mram_size_words = 0UL,
    },
    {
        .CanId = MCAN_MOD_ID_6,
        .IsUsed = TRUE,
        .BaseWord = 0UL,
        .mram_size_words = 1920UL,
    },
    {
        .CanId = MCAN_MOD_ID_7,
        .IsUsed = TRUE,
        .BaseWord = 1920UL,
        .mram_size_words = 1920UL,
    },
    {
        .CanId = MCAN_MOD_ID_8,
        .IsUsed = FALSE,
        .BaseWord = 3840UL,
        .mram_size_words = 0UL,
    },
    {
        .CanId = MCAN_MOD_ID_9,
        .IsUsed = TRUE,
        .BaseWord = 0UL,
        .mram_size_words = 1920UL,
    },
    {
        .CanId = MCAN_MOD_ID_10,
        .IsUsed = FALSE,
        .BaseWord = 1920UL,
        .mram_size_words = 0UL,
    },
    {
        .CanId = MCAN_MOD_ID_11,
        .IsUsed = TRUE,
        .BaseWord = 1920UL,
        .mram_size_words = 1920UL,
    },
    {
        .CanId = MCAN_MOD_ID_12,
        .IsUsed = FALSE,
        .BaseWord = 3840UL,
        .mram_size_words = 0UL,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(MCANPartitionConfig, CAN_CONST) MCAN_DATA =
{
    .McanCtrl = (McanControlInfor *)MCAN_CTRL,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

/* 
    The final value set to the register is as follows:
    Register NBTP.NBRP = brp - 1
    Register NBTP.NTSEG1 = (prop_seg + phase_seg1) - 1
    Register NBTP.NTSEG2 = phase_seg2 - 1
                             clockFrequency
    BitRate = ----------------------------------------------------
                brp * (1 + (prop_seg + phase_seg1) + phase_seg2)
*/
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(bt_config_canfd_struct, CAN_CONST) TIMCFG_0[4U] =
{
    {
        .baudRateConfigId = 0U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 4U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 1U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 2U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 2U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 1U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 3U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 1U,
            .prop_seg = 23U,
            .phase_seg1 = 8U,
            .phase_seg2 = 8U,
            .sjw = 8U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

/* 
    The final value set to the register is as follows:
    Register NBTP.NBRP = brp - 1
    Register NBTP.NTSEG1 = (prop_seg + phase_seg1) - 1
    Register NBTP.NTSEG2 = phase_seg2 - 1
                             clockFrequency
    BitRate = ----------------------------------------------------
                brp * (1 + (prop_seg + phase_seg1) + phase_seg2)
*/
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(bt_config_canfd_struct, CAN_CONST) TIMCFG_1[4U] =
{
    {
        .baudRateConfigId = 0U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 4U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 1U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 2U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 2U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 1U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 3U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 1U,
            .prop_seg = 23U,
            .phase_seg1 = 8U,
            .phase_seg2 = 8U,
            .sjw = 8U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

/* 
    The final value set to the register is as follows:
    Register NBTP.NBRP = brp - 1
    Register NBTP.NTSEG1 = (prop_seg + phase_seg1) - 1
    Register NBTP.NTSEG2 = phase_seg2 - 1
                             clockFrequency
    BitRate = ----------------------------------------------------
                brp * (1 + (prop_seg + phase_seg1) + phase_seg2)
*/
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(bt_config_canfd_struct, CAN_CONST) TIMCFG_2[4U] =
{
    {
        .baudRateConfigId = 0U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 4U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 1U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 2U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 2U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 1U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 3U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 1U,
            .prop_seg = 23U,
            .phase_seg1 = 8U,
            .phase_seg2 = 8U,
            .sjw = 8U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

/* 
    The final value set to the register is as follows:
    Register NBTP.NBRP = brp - 1
    Register NBTP.NTSEG1 = (prop_seg + phase_seg1) - 1
    Register NBTP.NTSEG2 = phase_seg2 - 1
                             clockFrequency
    BitRate = ----------------------------------------------------
                brp * (1 + (prop_seg + phase_seg1) + phase_seg2)
*/
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(bt_config_canfd_struct, CAN_CONST) TIMCFG_3[4U] =
{
    {
        .baudRateConfigId = 0U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 4U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 1U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 2U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 2U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 1U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 3U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 1U,
            .prop_seg = 23U,
            .phase_seg1 = 8U,
            .phase_seg2 = 8U,
            .sjw = 8U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

/* 
    The final value set to the register is as follows:
    Register NBTP.NBRP = brp - 1
    Register NBTP.NTSEG1 = (prop_seg + phase_seg1) - 1
    Register NBTP.NTSEG2 = phase_seg2 - 1
                             clockFrequency
    BitRate = ----------------------------------------------------
                brp * (1 + (prop_seg + phase_seg1) + phase_seg2)
*/
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(bt_config_canfd_struct, CAN_CONST) TIMCFG_4[4U] =
{
    {
        .baudRateConfigId = 0U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 4U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 1U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 2U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 2U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 1U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 3U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 1U,
            .prop_seg = 23U,
            .phase_seg1 = 8U,
            .phase_seg2 = 8U,
            .sjw = 8U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

/* 
    The final value set to the register is as follows:
    Register NBTP.NBRP = brp - 1
    Register NBTP.NTSEG1 = (prop_seg + phase_seg1) - 1
    Register NBTP.NTSEG2 = phase_seg2 - 1
                             clockFrequency
    BitRate = ----------------------------------------------------
                brp * (1 + (prop_seg + phase_seg1) + phase_seg2)
*/
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(bt_config_canfd_struct, CAN_CONST) TIMCFG_5[4U] =
{
    {
        .baudRateConfigId = 0U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 4U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 1U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 2U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 2U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 1U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 3U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 1U,
            .prop_seg = 23U,
            .phase_seg1 = 8U,
            .phase_seg2 = 8U,
            .sjw = 8U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

/* 
    The final value set to the register is as follows:
    Register NBTP.NBRP = brp - 1
    Register NBTP.NTSEG1 = (prop_seg + phase_seg1) - 1
    Register NBTP.NTSEG2 = phase_seg2 - 1
                             clockFrequency
    BitRate = ----------------------------------------------------
                brp * (1 + (prop_seg + phase_seg1) + phase_seg2)
*/
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(bt_config_canfd_struct, CAN_CONST) TIMCFG_6[4U] =
{
    {
        .baudRateConfigId = 0U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 4U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 1U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 2U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 2U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 1U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
    {
        .baudRateConfigId = 3U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 1U,
            .prop_seg = 23U,
            .phase_seg1 = 8U,
            .phase_seg2 = 8U,
            .sjw = 8U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 11U,
            .phase_seg1 = 4U,
            .phase_seg2 = 4U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 16U,
        },
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_id_table_t, CAN_CONST) filter_ids_config_0[10U] =
{
    {
        .id1 = 0x0000013dU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013dU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x0000013eU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013eU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x0000013fU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013fU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x00000711U,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x00000711U,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x00000741U,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x00000741U,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_filter_config_t, CAN_CONST) RX_FILTER_CFG_0 =
{
    .filterconfigs = filter_ids_config_0,
    .std_filters = 5U,
    .ext_filters = 5U,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_id_table_t, CAN_CONST) filter_ids_config_1[12U] =
{
    {
        .id1 = 0x0000013dU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013dU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x0000013eU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013eU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x0000013fU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013fU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x00000711U,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x00000711U,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x00000741U,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x00000741U,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x000007e6U,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x000007e6U,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_filter_config_t, CAN_CONST) RX_FILTER_CFG_1 =
{
    .filterconfigs = filter_ids_config_1,
    .std_filters = 6U,
    .ext_filters = 6U,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_id_table_t, CAN_CONST) filter_ids_config_2[10U] =
{
    {
        .id1 = 0x0000013dU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013dU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x0000013eU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013eU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x0000013fU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013fU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x00000711U,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x00000711U,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x00000741U,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x00000741U,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_filter_config_t, CAN_CONST) RX_FILTER_CFG_2 =
{
    .filterconfigs = filter_ids_config_2,
    .std_filters = 5U,
    .ext_filters = 5U,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_id_table_t, CAN_CONST) filter_ids_config_3[10U] =
{
    {
        .id1 = 0x0000013dU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013dU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x0000013eU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013eU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x0000013fU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013fU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x00000711U,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x00000711U,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x00000741U,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x00000741U,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_filter_config_t, CAN_CONST) RX_FILTER_CFG_3 =
{
    .filterconfigs = filter_ids_config_3,
    .std_filters = 5U,
    .ext_filters = 5U,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_id_table_t, CAN_CONST) filter_ids_config_4[10U] =
{
    {
        .id1 = 0x0000013dU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013dU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x0000013eU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013eU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x0000013fU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013fU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x00000711U,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x00000711U,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x00000741U,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x00000741U,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_filter_config_t, CAN_CONST) RX_FILTER_CFG_4 =
{
    .filterconfigs = filter_ids_config_4,
    .std_filters = 5U,
    .ext_filters = 5U,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_id_table_t, CAN_CONST) filter_ids_config_5[12U] =
{
    {
        .id1 = 0x0000013dU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013dU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x0000013eU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013eU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x0000013fU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013fU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x00000711U,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x00000711U,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x00000741U,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x00000741U,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x000007f0U,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x000007f0U,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_filter_config_t, CAN_CONST) RX_FILTER_CFG_5 =
{
    .filterconfigs = filter_ids_config_5,
    .std_filters = 6U,
    .ext_filters = 6U,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_id_table_t, CAN_CONST) filter_ids_config_6[10U] =
{
    {
        .id1 = 0x0000013dU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013dU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x0000013eU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013eU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x0000013fU,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x0000013fU,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x00000711U,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x00000711U,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x00000741U,
        .id2 = 0x1fffffffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = TRUE,
    },
    {
        .id1 = 0x00000741U,
        .id2 = 0x000007ffU,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_FIFO0,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_filter_config_t, CAN_CONST) RX_FILTER_CFG_6 =
{
    .filterconfigs = filter_ids_config_6,
    .std_filters = 5U,
    .ext_filters = 5U,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_fifo_config_t, CAN_CONST) RX_FIFO_CFG_0 =
{
    .rx_fifo_needed = MCAN_RXFIFO_0_ENABLE,
    .modeFIFO = FIFO_MODE_OVERWRITE,
    .fifo_size_elems = 64U,
    .fifo_watermark = 64U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_fifo_config_t, CAN_CONST) RX_FIFO_CFG_1 =
{
    .rx_fifo_needed = MCAN_RXFIFO_0_ENABLE,
    .modeFIFO = FIFO_MODE_OVERWRITE,
    .fifo_size_elems = 64U,
    .fifo_watermark = 64U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_fifo_config_t, CAN_CONST) RX_FIFO_CFG_2 =
{
    .rx_fifo_needed = MCAN_RXFIFO_0_ENABLE,
    .modeFIFO = FIFO_MODE_OVERWRITE,
    .fifo_size_elems = 64U,
    .fifo_watermark = 64U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_fifo_config_t, CAN_CONST) RX_FIFO_CFG_3 =
{
    .rx_fifo_needed = MCAN_RXFIFO_0_ENABLE,
    .modeFIFO = FIFO_MODE_OVERWRITE,
    .fifo_size_elems = 64U,
    .fifo_watermark = 64U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_fifo_config_t, CAN_CONST) RX_FIFO_CFG_4 =
{
    .rx_fifo_needed = MCAN_RXFIFO_0_ENABLE,
    .modeFIFO = FIFO_MODE_OVERWRITE,
    .fifo_size_elems = 64U,
    .fifo_watermark = 64U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_fifo_config_t, CAN_CONST) RX_FIFO_CFG_5 =
{
    .rx_fifo_needed = MCAN_RXFIFO_0_ENABLE,
    .modeFIFO = FIFO_MODE_OVERWRITE,
    .fifo_size_elems = 64U,
    .fifo_watermark = 64U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_fifo_config_t, CAN_CONST) RX_FIFO_CFG_6 =
{
    .rx_fifo_needed = MCAN_RXFIFO_0_ENABLE,
    .modeFIFO = FIFO_MODE_OVERWRITE,
    .fifo_size_elems = 64U,
    .fifo_watermark = 64U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_global_filter_config_t, CAN_CONST) GLOBAL_FILTER_CFG_0 =
{
    .anfe = REJECT_NON_MATCHING_FRAMES,
    .anfs = REJECT_NON_MATCHING_FRAMES,
    .rrfe = TRUE,
    .rrfs = TRUE,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_global_filter_config_t, CAN_CONST) GLOBAL_FILTER_CFG_1 =
{
    .anfe = REJECT_NON_MATCHING_FRAMES,
    .anfs = REJECT_NON_MATCHING_FRAMES,
    .rrfe = TRUE,
    .rrfs = TRUE,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_global_filter_config_t, CAN_CONST) GLOBAL_FILTER_CFG_2 =
{
    .anfe = REJECT_NON_MATCHING_FRAMES,
    .anfs = REJECT_NON_MATCHING_FRAMES,
    .rrfe = TRUE,
    .rrfs = TRUE,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_global_filter_config_t, CAN_CONST) GLOBAL_FILTER_CFG_3 =
{
    .anfe = REJECT_NON_MATCHING_FRAMES,
    .anfs = REJECT_NON_MATCHING_FRAMES,
    .rrfe = TRUE,
    .rrfs = TRUE,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_global_filter_config_t, CAN_CONST) GLOBAL_FILTER_CFG_4 =
{
    .anfe = REJECT_NON_MATCHING_FRAMES,
    .anfs = REJECT_NON_MATCHING_FRAMES,
    .rrfe = TRUE,
    .rrfs = TRUE,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_global_filter_config_t, CAN_CONST) GLOBAL_FILTER_CFG_5 =
{
    .anfe = REJECT_NON_MATCHING_FRAMES,
    .anfs = REJECT_NON_MATCHING_FRAMES,
    .rrfe = TRUE,
    .rrfs = TRUE,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_global_filter_config_t, CAN_CONST) GLOBAL_FILTER_CFG_6 =
{
    .anfe = REJECT_NON_MATCHING_FRAMES,
    .anfs = REJECT_NON_MATCHING_FRAMES,
    .rrfe = TRUE,
    .rrfs = TRUE,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_tx_buffer_config_t, CAN_CONST) TX_BUFFER_CFG_0 =
{
    .FIFO_true_QUEUE_false = TRUE,
    .fifo_queue_size = 0U,
    .ded_buffers_number = 32U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_dedicated_buffers_config_t, CAN_CONST) RX_BUFFER_CFG_0 =
{
    .rx_buffer_size_elems = 0U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_tx_buffer_config_t, CAN_CONST) TX_BUFFER_CFG_1 =
{
    .FIFO_true_QUEUE_false = TRUE,
    .fifo_queue_size = 0U,
    .ded_buffers_number = 32U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_dedicated_buffers_config_t, CAN_CONST) RX_BUFFER_CFG_1 =
{
    .rx_buffer_size_elems = 0U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_tx_buffer_config_t, CAN_CONST) TX_BUFFER_CFG_2 =
{
    .FIFO_true_QUEUE_false = TRUE,
    .fifo_queue_size = 0U,
    .ded_buffers_number = 32U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_dedicated_buffers_config_t, CAN_CONST) RX_BUFFER_CFG_2 =
{
    .rx_buffer_size_elems = 0U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_tx_buffer_config_t, CAN_CONST) TX_BUFFER_CFG_3 =
{
    .FIFO_true_QUEUE_false = TRUE,
    .fifo_queue_size = 0U,
    .ded_buffers_number = 32U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_dedicated_buffers_config_t, CAN_CONST) RX_BUFFER_CFG_3 =
{
    .rx_buffer_size_elems = 0U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_tx_buffer_config_t, CAN_CONST) TX_BUFFER_CFG_4 =
{
    .FIFO_true_QUEUE_false = TRUE,
    .fifo_queue_size = 0U,
    .ded_buffers_number = 32U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_dedicated_buffers_config_t, CAN_CONST) RX_BUFFER_CFG_4 =
{
    .rx_buffer_size_elems = 0U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_tx_buffer_config_t, CAN_CONST) TX_BUFFER_CFG_5 =
{
    .FIFO_true_QUEUE_false = TRUE,
    .fifo_queue_size = 0U,
    .ded_buffers_number = 32U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_dedicated_buffers_config_t, CAN_CONST) RX_BUFFER_CFG_5 =
{
    .rx_buffer_size_elems = 0U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_tx_buffer_config_t, CAN_CONST) TX_BUFFER_CFG_6 =
{
    .FIFO_true_QUEUE_false = TRUE,
    .fifo_queue_size = 0U,
    .ded_buffers_number = 32U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_dedicated_buffers_config_t, CAN_CONST) RX_BUFFER_CFG_6 =
{
    .rx_buffer_size_elems = 0U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_inter_config_t, CAN_CONST) INTER_CFG_0 =
{
    .ir_line0_select = 0x0000060fUL,
    .ir_line1_select = 0x02000000UL,
    .tx_buffer_tran_ir_enable = 0xffffffffUL,
    .tx_buffer_cancel_fin_ir_enable = 0xffffffffUL,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_inter_config_t, CAN_CONST) INTER_CFG_1 =
{
    .ir_line0_select = 0x0000060fUL,
    .ir_line1_select = 0x02000000UL,
    .tx_buffer_tran_ir_enable = 0xffffffffUL,
    .tx_buffer_cancel_fin_ir_enable = 0xffffffffUL,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_inter_config_t, CAN_CONST) INTER_CFG_2 =
{
    .ir_line0_select = 0x0000060fUL,
    .ir_line1_select = 0x02000000UL,
    .tx_buffer_tran_ir_enable = 0xffffffffUL,
    .tx_buffer_cancel_fin_ir_enable = 0xffffffffUL,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_inter_config_t, CAN_CONST) INTER_CFG_3 =
{
    .ir_line0_select = 0x0000060fUL,
    .ir_line1_select = 0x02000000UL,
    .tx_buffer_tran_ir_enable = 0xffffffffUL,
    .tx_buffer_cancel_fin_ir_enable = 0xffffffffUL,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_inter_config_t, CAN_CONST) INTER_CFG_4 =
{
    .ir_line0_select = 0x0000060fUL,
    .ir_line1_select = 0x02000000UL,
    .tx_buffer_tran_ir_enable = 0xffffffffUL,
    .tx_buffer_cancel_fin_ir_enable = 0xffffffffUL,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_inter_config_t, CAN_CONST) INTER_CFG_5 =
{
    .ir_line0_select = 0x0000060fUL,
    .ir_line1_select = 0x02000000UL,
    .tx_buffer_tran_ir_enable = 0xffffffffUL,
    .tx_buffer_cancel_fin_ir_enable = 0xffffffffUL,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_inter_config_t, CAN_CONST) INTER_CFG_6 =
{
    .ir_line0_select = 0x0000060fUL,
    .ir_line1_select = 0x02000000UL,
    .tx_buffer_tran_ir_enable = 0xffffffffUL,
    .tx_buffer_cancel_fin_ir_enable = 0xffffffffUL,
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"


#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
VAR(CANConfig, CAN_CONST) Mcan_ControllerConfigs[CAN_CONTROLLER_COUNT] = 
{
    {
        .controllerId = MCAN_MOD_ID_7,
        .defaultBaudRateId = (uint16)2U,
        .baudRateConfigCount = 4U,
        .data = &MCAN_DATA,
        .timingconfig = TIMCFG_0,
        .globalfilterconfig = &GLOBAL_FILTER_CFG_0,
        #ifdef RX_FILTER_CFG_0
        .filterconfig = RX_FILTER_CFG_0,
        #else
        .filterconfig = &RX_FILTER_CFG_0,
        #endif
        .rxfifoconfig =  &RX_FIFO_CFG_0,
        .txeventconfig = NULL_PTR,
        .txbufferconfig = &TX_BUFFER_CFG_0,
        .rxbufferconfig = &RX_BUFFER_CFG_0,
        .interconfig = &INTER_CFG_0,
        .stampconfig = NULL_PTR,
        .mcanMode = MCAN_NORMAL_MODE,
        .MRAFNotification = NULL_PTR,
        .ErrorNotification = NULL_PTR,
    },
    {
        .controllerId = MCAN_MOD_ID_2,
        .defaultBaudRateId = (uint16)2U,
        .baudRateConfigCount = 4U,
        .data = &MCAN_DATA,
        .timingconfig = TIMCFG_1,
        .globalfilterconfig = &GLOBAL_FILTER_CFG_1,
        #ifdef RX_FILTER_CFG_1
        .filterconfig = RX_FILTER_CFG_1,
        #else
        .filterconfig = &RX_FILTER_CFG_1,
        #endif
        .rxfifoconfig =  &RX_FIFO_CFG_1,
        .txeventconfig = NULL_PTR,
        .txbufferconfig = &TX_BUFFER_CFG_1,
        .rxbufferconfig = &RX_BUFFER_CFG_1,
        .interconfig = &INTER_CFG_1,
        .stampconfig = NULL_PTR,
        .mcanMode = MCAN_NORMAL_MODE,
        .MRAFNotification = NULL_PTR,
        .ErrorNotification = NULL_PTR,
    },
    {
        .controllerId = MCAN_MOD_ID_3,
        .defaultBaudRateId = (uint16)2U,
        .baudRateConfigCount = 4U,
        .data = &MCAN_DATA,
        .timingconfig = TIMCFG_2,
        .globalfilterconfig = &GLOBAL_FILTER_CFG_2,
        #ifdef RX_FILTER_CFG_2
        .filterconfig = RX_FILTER_CFG_2,
        #else
        .filterconfig = &RX_FILTER_CFG_2,
        #endif
        .rxfifoconfig =  &RX_FIFO_CFG_2,
        .txeventconfig = NULL_PTR,
        .txbufferconfig = &TX_BUFFER_CFG_2,
        .rxbufferconfig = &RX_BUFFER_CFG_2,
        .interconfig = &INTER_CFG_2,
        .stampconfig = NULL_PTR,
        .mcanMode = MCAN_NORMAL_MODE,
        .MRAFNotification = NULL_PTR,
        .ErrorNotification = NULL_PTR,
    },
    {
        .controllerId = MCAN_MOD_ID_9,
        .defaultBaudRateId = (uint16)2U,
        .baudRateConfigCount = 4U,
        .data = &MCAN_DATA,
        .timingconfig = TIMCFG_3,
        .globalfilterconfig = &GLOBAL_FILTER_CFG_3,
        #ifdef RX_FILTER_CFG_3
        .filterconfig = RX_FILTER_CFG_3,
        #else
        .filterconfig = &RX_FILTER_CFG_3,
        #endif
        .rxfifoconfig =  &RX_FIFO_CFG_3,
        .txeventconfig = NULL_PTR,
        .txbufferconfig = &TX_BUFFER_CFG_3,
        .rxbufferconfig = &RX_BUFFER_CFG_3,
        .interconfig = &INTER_CFG_3,
        .stampconfig = NULL_PTR,
        .mcanMode = MCAN_NORMAL_MODE,
        .MRAFNotification = NULL_PTR,
        .ErrorNotification = NULL_PTR,
    },
    {
        .controllerId = MCAN_MOD_ID_1,
        .defaultBaudRateId = (uint16)2U,
        .baudRateConfigCount = 4U,
        .data = &MCAN_DATA,
        .timingconfig = TIMCFG_4,
        .globalfilterconfig = &GLOBAL_FILTER_CFG_4,
        #ifdef RX_FILTER_CFG_4
        .filterconfig = RX_FILTER_CFG_4,
        #else
        .filterconfig = &RX_FILTER_CFG_4,
        #endif
        .rxfifoconfig =  &RX_FIFO_CFG_4,
        .txeventconfig = NULL_PTR,
        .txbufferconfig = &TX_BUFFER_CFG_4,
        .rxbufferconfig = &RX_BUFFER_CFG_4,
        .interconfig = &INTER_CFG_4,
        .stampconfig = NULL_PTR,
        .mcanMode = MCAN_NORMAL_MODE,
        .MRAFNotification = NULL_PTR,
        .ErrorNotification = NULL_PTR,
    },
    {
        .controllerId = MCAN_MOD_ID_6,
        .defaultBaudRateId = (uint16)2U,
        .baudRateConfigCount = 4U,
        .data = &MCAN_DATA,
        .timingconfig = TIMCFG_5,
        .globalfilterconfig = &GLOBAL_FILTER_CFG_5,
        #ifdef RX_FILTER_CFG_5
        .filterconfig = RX_FILTER_CFG_5,
        #else
        .filterconfig = &RX_FILTER_CFG_5,
        #endif
        .rxfifoconfig =  &RX_FIFO_CFG_5,
        .txeventconfig = NULL_PTR,
        .txbufferconfig = &TX_BUFFER_CFG_5,
        .rxbufferconfig = &RX_BUFFER_CFG_5,
        .interconfig = &INTER_CFG_5,
        .stampconfig = NULL_PTR,
        .mcanMode = MCAN_NORMAL_MODE,
        .MRAFNotification = NULL_PTR,
        .ErrorNotification = NULL_PTR,
    },
    {
        .controllerId = MCAN_MOD_ID_11,
        .defaultBaudRateId = (uint16)2U,
        .baudRateConfigCount = 4U,
        .data = &MCAN_DATA,
        .timingconfig = TIMCFG_6,
        .globalfilterconfig = &GLOBAL_FILTER_CFG_6,
        #ifdef RX_FILTER_CFG_6
        .filterconfig = RX_FILTER_CFG_6,
        #else
        .filterconfig = &RX_FILTER_CFG_6,
        #endif
        .rxfifoconfig =  &RX_FIFO_CFG_6,
        .txeventconfig = NULL_PTR,
        .txbufferconfig = &TX_BUFFER_CFG_6,
        .rxbufferconfig = &RX_BUFFER_CFG_6,
        .interconfig = &INTER_CFG_6,
        .stampconfig = NULL_PTR,
        .mcanMode = MCAN_NORMAL_MODE,
        .MRAFNotification = NULL_PTR,
        .ErrorNotification = NULL_PTR,
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#if (CAN_MULTICORE_ENABLED == STD_ON)
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
static CONST(mcan_core_map_t, CAN_CONST) Mcan_CoreMap[CAN_CONTROLLER_COUNT] =
{
    {
        .controllerId = MCAN_MOD_ID_7,
        .CoreId = 4U
    },
    {
        .controllerId = MCAN_MOD_ID_2,
        .CoreId = 4U
    },
    {
        .controllerId = MCAN_MOD_ID_3,
        .CoreId = 4U
    },
    {
        .controllerId = MCAN_MOD_ID_9,
        .CoreId = 4U
    },
    {
        .controllerId = MCAN_MOD_ID_1,
        .CoreId = 4U
    },
    {
        .controllerId = MCAN_MOD_ID_6,
        .CoreId = 4U
    },
    {
        .controllerId = MCAN_MOD_ID_11,
        .CoreId = 4U
    },
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"
#endif

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
CONST(Can_ConfigType, CAN_CONST) Can_Config =
{
    .controllerConfig = Mcan_ControllerConfigs,
    .hwObjectConfig = Mcan_HardWareObjConfigs,
    .hthMap = Mcan_ObjMap,
#if (CAN_MULTICORE_ENABLED == STD_ON)
    .coreMap = Mcan_CoreMap
#endif
};
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

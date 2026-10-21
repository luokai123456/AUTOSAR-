/* PRQA S 2053, 0380, 1258, 0704,4342, 1759,1526,1594,1758,1756,3408,4424 EOF */
/**
*   @file Icu_Cfg.c
*   @version 3.0.0
*
*   @brief   AUTOSAR Icu - contains the configuration data of the ICU driver
*   @details Contains the configuration data of the ICU driver
*
*   @addtogroup ICU_MODULE
*   @{
*/
/**************************************************************************** 
* 
* Copyright (c) 2022  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : -
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
*   @file    Icu_Cfg.c 
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/

/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "Icu_Cfg.h"
#include "Icu.h"
#if defined(RESOURCE_SUPPORT_GTM104)
#include "Icu_Gtm104_Tim_LLDrivers.h"
#endif/* defined(RESOURCE_SUPPORT_GTM104) */
#if defined(RESOURCE_SUPPORT_GTM410)
#include "Icu_Gtm410_Tim_LLDrivers.h"
#endif/* defined(RESOURCE_SUPPORT_GTM410) */
#include "Icu_eMIOS_HAL_Wrapper.h"
#include "Icu_eMIOS_Wrapper.h"
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "Icu_eTPU_HAL_Wrapper.h"
#include "Icu_eTPU_Wrapper.h"
#endif /* (defined(RESOURCE_SUPPORT_ETPU)) */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
#include "Icu_Ccu7_HAL_Wrapper.h"
#include "Icu_Ccu7_Wrapper.h"
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
#include "eDMA_LLDriver.h"
#include "EcuM_Cbk.h"
#if (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI))
#include "Icu_Wkpu_LLDrivers.h"
#endif /* (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI)) */


/*=====================================SOURCE FILE VERSION INFORMATION==============================*/

#define ICU_CFG_VENDOR_ID_C                 176

#define ICU_CFG_AR_MAJOR_VER_C              4
#define ICU_CFG_AR_MINOR_VER_C              4
#define ICU_CFG_AR_PATCH_VER_C              0

#define ICU_CFG_SW_MAJOR_VER_C              3
#define ICU_CFG_SW_MINOR_VER_C              0
#define ICU_CFG_SW_PATCH_VER_C              0

/*============================================FILE VERSION CHECKS===================================*/

#if (ICU_CFG_VENDOR_ID_C != ICU_VENDOR_ID_CFG)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_CFG_AR_MAJOR_VER_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION_CFG"
#endif
#if (ICU_CFG_AR_MINOR_VER_C != ICU_AR_RELEASE_MINOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION_CFG"
#endif
#if (ICU_CFG_AR_PATCH_VER_C != ICU_AR_RELEASE_REVISION_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_REVISION_VERSION_CFG"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_CFG_SW_MAJOR_VER_C != ICU_SW_MAJOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VERSION_CFG"
#endif
#if (ICU_CFG_SW_MINOR_VER_C != ICU_SW_MINOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VERSION_CFG"
#endif
#if (ICU_CFG_SW_PATCH_VER_C != ICU_SW_PATCH_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VERSION_CFG"
#endif

/*====================================================================================================
                                   EXTERN CALLBACK FUNCTION
====================================================================================================*/




/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/

/*===================================================================================================
*                                       LOCAL MACROS
====================================================================================================*/

/*===================================================================================================
*                                      LOCAL CONSTANTS
====================================================================================================*/

/*===================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
====================================================================================================*/



/******************************************************************************************/
/************************************* GTM Config *****************************************/
/******************************************************************************************/
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
#define ICU_START_SEC_CONFIG_DATA
#include "Icu_MemMap.h"
static CONST(Icu_ChannelConfig_Type, ICU_CONST) GtmChannelConfig[30] =
{
    {
        .IcuConfig_Instance = 0,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM3,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH0,
		        .IcuConfig_Tim_Selection = Ch_7_H,
		        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 1,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM2,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH4,
		        .IcuConfig_Tim_Selection = Ch_C_H,
		        .IcuConfig_ChannelMode = ICU_MODE_TIMESTAMP,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)TRUE,
        .IcuChannel_DmaChannel = (uint8)EDMA_CHN30_NUMBER,
    },
    {
        .IcuConfig_Instance = 2,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM2,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH6,
		        .IcuConfig_Tim_Selection = Ch_C_H,
		        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 3,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM5,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH2,
		        .IcuConfig_Tim_Selection = Ch_7_H,
		        .IcuConfig_ChannelMode = ICU_MODE_TIMESTAMP,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)TRUE,
        .IcuChannel_DmaChannel = (uint8)EDMA_CHN106_NUMBER,
    },
    {
        .IcuConfig_Instance = 4,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM2,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH7,
		        .IcuConfig_Tim_Selection = Ch_E_H,
		        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 5,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM5,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH1,
		        .IcuConfig_Tim_Selection = Ch_8_H,
		        .IcuConfig_ChannelMode = ICU_MODE_TIMESTAMP,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)TRUE,
        .IcuChannel_DmaChannel = (uint8)EDMA_CHN105_NUMBER,
    },
    {
        .IcuConfig_Instance = 6,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM2,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH5,
		        .IcuConfig_Tim_Selection = Ch_D_H,
		        .IcuConfig_ChannelMode = ICU_MODE_TIMESTAMP,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)TRUE,
        .IcuChannel_DmaChannel = (uint8)EDMA_CHN31_NUMBER,
    },
    {
        .IcuConfig_Instance = 7,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM4,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH2,
		        .IcuConfig_Tim_Selection = Ch_9_H,
		        .IcuConfig_ChannelMode = ICU_MODE_TIMESTAMP,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)TRUE,
        .IcuChannel_DmaChannel = (uint8)EDMA_CHN102_NUMBER,
    },
    {
        .IcuConfig_Instance = 8,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM4,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH4,
		        .IcuConfig_Tim_Selection = Ch_9_H,
		        .IcuConfig_ChannelMode = ICU_MODE_TIMESTAMP,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)TRUE,
        .IcuChannel_DmaChannel = (uint8)EDMA_CHN103_NUMBER,
    },
    {
        .IcuConfig_Instance = 9,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM5,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH4,
		        .IcuConfig_Tim_Selection = Ch_8_H,
		        .IcuConfig_ChannelMode = ICU_MODE_TIMESTAMP,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)TRUE,
        .IcuChannel_DmaChannel = (uint8)EDMA_CHN107_NUMBER,
    },
    {
        .IcuConfig_Instance = 10,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM7,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH0,
		        .IcuConfig_Tim_Selection = Ch_7_H,
		        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 11,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM4,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH5,
		        .IcuConfig_Tim_Selection = Ch_9_H,
		        .IcuConfig_ChannelMode = ICU_MODE_TIMESTAMP,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)TRUE,
        .IcuChannel_DmaChannel = (uint8)EDMA_CHN104_NUMBER,
    },
    {
        .IcuConfig_Instance = 12,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM5,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH5,
		        .IcuConfig_Tim_Selection = Ch_8_H,
		        .IcuConfig_ChannelMode = ICU_MODE_TIMESTAMP,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)TRUE,
        .IcuChannel_DmaChannel = (uint8)EDMA_CHN108_NUMBER,
    },
    {
        .IcuConfig_Instance = 13,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM4,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH1,
		        .IcuConfig_Tim_Selection = Ch_A_H,
		        .IcuConfig_ChannelMode = ICU_MODE_TIMESTAMP,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)TRUE,
        .IcuChannel_DmaChannel = (uint8)EDMA_CHN101_NUMBER,
    },
    {
        .IcuConfig_Instance = 14,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM7,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH5,
		        .IcuConfig_Tim_Selection = Ch_3_H,
		        .IcuConfig_ChannelMode = ICU_MODE_TIMESTAMP,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)TRUE,
        .IcuChannel_DmaChannel = (uint8)EDMA_CHN127_NUMBER,
    },
    {
        .IcuConfig_Instance = 15,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM6,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH1,
		        .IcuConfig_Tim_Selection = Ch_6_H,
		        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 16,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM4,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH0,
		        .IcuConfig_Tim_Selection = Ch_8_H,
		        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 17,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM6,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH3,
		        .IcuConfig_Tim_Selection = Ch_6_H,
		        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 18,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM6,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH2,
		        .IcuConfig_Tim_Selection = Ch_6_H,
		        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 19,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM6,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH5,
		        .IcuConfig_Tim_Selection = Ch_5_H,
		        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 20,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM6,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH4,
		        .IcuConfig_Tim_Selection = Ch_5_H,
		        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 21,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM6,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH6,
		        .IcuConfig_Tim_Selection = Ch_9_H,
		        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 22,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM6,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH0,
		        .IcuConfig_Tim_Selection = Ch_7_H,
		        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 23,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM3,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH2,
		        .IcuConfig_Tim_Selection = Ch_9_H,
		        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 24,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM3,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH3,
		        .IcuConfig_Tim_Selection = Ch_9_H,
		        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 25,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM3,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH4,
		        .IcuConfig_Tim_Selection = Ch_A_H,
		        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 26,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM5,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH0,
		        .IcuConfig_Tim_Selection = Ch_1_H,
		        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 27,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM5,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH7,
		        .IcuConfig_Tim_Selection = Ch_1_H,
		        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 28,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM4,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH6,
		        .IcuConfig_Tim_Selection = Ch_3_H,
		        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 29,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM4,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH7,
		        .IcuConfig_Tim_Selection = Ch_C_H,
		        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = NULL_PTR,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_OverflowNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
};
#define ICU_STOP_SEC_CONFIG_DATA
#include "Icu_MemMap.h"

#define ICU_START_SEC_CONFIG_DATA
#include "Icu_MemMap.h"
static CONST(ICU_Gtm_Config, ICU_CONST) Icu_GtmConfig =
{
    .uChannelCount = 30U,
    .pGtmChannelConfig = GtmChannelConfig
};
#define ICU_STOP_SEC_CONFIG_DATA
#include "Icu_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */










/******************************************************************************************/
/************************************ Hardware Map ****************************************/
/******************************************************************************************/
#define ICU_START_SEC_CONFIG_DATA
#include "Icu_MemMap.h"
static CONST(ICU_HwModule_Type, ICU_CONST) Icu_HwChMap[30] =
{
    ICU_GTM_TIM3,
    ICU_GTM_TIM2,
    ICU_GTM_TIM2,
    ICU_GTM_TIM5,
    ICU_GTM_TIM2,
    ICU_GTM_TIM5,
    ICU_GTM_TIM2,
    ICU_GTM_TIM4,
    ICU_GTM_TIM4,
    ICU_GTM_TIM5,
    ICU_GTM_TIM7,
    ICU_GTM_TIM4,
    ICU_GTM_TIM5,
    ICU_GTM_TIM4,
    ICU_GTM_TIM7,
    ICU_GTM_TIM6,
    ICU_GTM_TIM4,
    ICU_GTM_TIM6,
    ICU_GTM_TIM6,
    ICU_GTM_TIM6,
    ICU_GTM_TIM6,
    ICU_GTM_TIM6,
    ICU_GTM_TIM6,
    ICU_GTM_TIM3,
    ICU_GTM_TIM3,
    ICU_GTM_TIM3,
    ICU_GTM_TIM5,
    ICU_GTM_TIM5,
    ICU_GTM_TIM4,
    ICU_GTM_TIM4,
};
#define ICU_STOP_SEC_CONFIG_DATA
#include "Icu_MemMap.h"


#define ICU_START_SEC_CONFIG_DATA
#include "Icu_MemMap.h"
static CONST(Icu_CoreMapItemType, ICU_CONST) Icu_CoreMap[30] =
{
    {
        .nIcuChannelId=0,
        .nCoreId=1
    },
    {
        .nIcuChannelId=1,
        .nCoreId=1
    },
    {
        .nIcuChannelId=2,
        .nCoreId=1
    },
    {
        .nIcuChannelId=3,
        .nCoreId=1
    },
    {
        .nIcuChannelId=4,
        .nCoreId=1
    },
    {
        .nIcuChannelId=5,
        .nCoreId=1
    },
    {
        .nIcuChannelId=6,
        .nCoreId=1
    },
    {
        .nIcuChannelId=7,
        .nCoreId=1
    },
    {
        .nIcuChannelId=8,
        .nCoreId=1
    },
    {
        .nIcuChannelId=9,
        .nCoreId=1
    },
    {
        .nIcuChannelId=10,
        .nCoreId=1
    },
    {
        .nIcuChannelId=11,
        .nCoreId=1
    },
    {
        .nIcuChannelId=12,
        .nCoreId=1
    },
    {
        .nIcuChannelId=13,
        .nCoreId=1
    },
    {
        .nIcuChannelId=14,
        .nCoreId=1
    },
    {
        .nIcuChannelId=15,
        .nCoreId=1
    },
    {
        .nIcuChannelId=16,
        .nCoreId=1
    },
    {
        .nIcuChannelId=17,
        .nCoreId=1
    },
    {
        .nIcuChannelId=18,
        .nCoreId=1
    },
    {
        .nIcuChannelId=19,
        .nCoreId=1
    },
    {
        .nIcuChannelId=20,
        .nCoreId=1
    },
    {
        .nIcuChannelId=21,
        .nCoreId=1
    },
    {
        .nIcuChannelId=22,
        .nCoreId=1
    },
    {
        .nIcuChannelId=23,
        .nCoreId=1
    },
    {
        .nIcuChannelId=24,
        .nCoreId=1
    },
    {
        .nIcuChannelId=25,
        .nCoreId=1
    },
    {
        .nIcuChannelId=26,
        .nCoreId=1
    },
    {
        .nIcuChannelId=27,
        .nCoreId=1
    },
    {
        .nIcuChannelId=28,
        .nCoreId=1
    },
    {
        .nIcuChannelId=29,
        .nCoreId=1
    },
};
#define ICU_STOP_SEC_CONFIG_DATA
#include "Icu_MemMap.h"

/******************************************************************************************/
/************************************* ICU Config *****************************************/
/******************************************************************************************/

#define ICU_START_SEC_CONFIG_DATA
#include "Icu_MemMap.h"
CONST(Icu_ConfigType, ICU_CONST) Icu_Config =
{
    .Icu_NumChannels    = 30U,
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
    .Icu_GtmConfig      = &Icu_GtmConfig,
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
    .Icu_eMoisConfig    = NULL_PTR,
#if (defined(RESOURCE_SUPPORT_ETPU))
    .Icu_eTpuConfig     = NULL_PTR,
#endif /* (defined(RESOURCE_SUPPORT_ETPU)) */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
    .Icu_Ccu7Config     = NULL_PTR,
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
#if (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI))
    .Icu_WkpuConfig     = NULL_PTR,
#endif /* (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI)) */
    .Icu_HwChMap        = &Icu_HwChMap,
    .Icu_CoreMap        = Icu_CoreMap
};
#define ICU_STOP_SEC_CONFIG_DATA
#include "Icu_MemMap.h"


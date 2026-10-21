/**
*   @file Icu_Cfg.h
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
*   @file    Icu_Cfg.h 
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/

#ifndef ICU_CFG_H
#define ICU_CFG_H

/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif 
#include "Mcal.h"


/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_VENDOR_ID_CFG                       176

#define ICU_AR_RELEASE_MAJOR_VERSION_CFG        4
#define ICU_AR_RELEASE_MINOR_VERSION_CFG        4
#define ICU_AR_RELEASE_REVISION_VERSION_CFG     0

#define ICU_SW_MAJOR_VERSION_CFG                3
#define ICU_SW_MINOR_VERSION_CFG                0
#define ICU_SW_PATCH_VERSION_CFG                0

/*============================================FILE VERSION CHECKS===================================*/

#if (ICU_VENDOR_ID_CFG != MCAL_VENDOR_ID)
#error "NON-MATCHED DATA : MCAL_VENDOR_ID"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : MCAL_AR_MAJOR_VER"
#endif
#if (ICU_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : MCAL_AR_MINOR_VER"
#endif
#if (ICU_AR_RELEASE_REVISION_VERSION_CFG != MCAL_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : MCAL_AR_PATCH_VER"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_SW_MAJOR_VERSION_CFG != MCAL_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : MCAL_SW_MAJOR_VER"
#endif
#if (ICU_SW_MINOR_VERSION_CFG != MCAL_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : MCAL_SW_MINOR_VER"
#endif
#if (ICU_SW_PATCH_VERSION_CFG != MCAL_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : MCAL_SW_PATCH_VER"
#endif

/*===================================================================================================
*                                       LOCAL MACROS
====================================================================================================*/
#define ICU_PRECOMPILE_SUPPORT        (STD_OFF)

#define Icu_Cfg Icu_Config

#define ICU_DEV_ERROR_DETECT                    (STD_ON)
#define ICU_REPORT_WAKEUP_SOURCE                (STD_OFF)

#define ICU_DEINIT_API                          (STD_ON)
#define ICU_SETMODE_API                         (STD_ON)
#define ICU_DISABLEWAKEUP_API                   (STD_ON)
#define ICU_ENABLEWAKEUP_API                    (STD_ON)
#define ICU_CHECKWAKEUP_API                     (STD_ON)
#define ICU_GETINPUTSTATE_API                   (STD_ON)
#define ICU_STARTTIMESTAMP_API                  (STD_ON)
#define ICU_STOPTIMESTAMP_API                   (STD_ON)
#define ICU_GETTIMESTAMPINDEX_API               (STD_ON)
#define ICU_RESETEDGECOUNT_API                  (STD_ON)
#define ICU_ENABLEEDGECOUNT_API                 (STD_ON)
#define ICU_ENABLEEDGEDETECTION_API             (STD_ON)
#define ICU_DISABLEEDGEDETECTION_API            (STD_ON)
#define ICU_DISABLEEDGECOUNT_API                (STD_ON)
#define ICU_GETEDGENUMBERS_API                  (STD_ON)
#define ICU_STARTSIGNALMEASUREMENT_API          (STD_ON)
#define ICU_STOPSIGNALMEASUREMENT_API           (STD_ON)
#define ICU_GETTIMEELAPSED_API                  (STD_ON)
#define ICU_GETDUTYCYCLEVALUES_API              (STD_ON)
#define ICU_GETVERSIONINFO_API                  (STD_ON)
#define ICU_WAKEUP_FUNCTIONALITY_API            (STD_ON)
#define ICU_CAPTURERGISTER_API                  (STD_OFF)

#define ICU_INLINE                         LOCAL_INLINE
#define WKP_PS0                                 0U
#define ICU_WKP_PS0                             0U
#define WKP_PA4                                 1U
#define ICU_WKP_PA4                             1U
#define ICU_NMI_WAKEUP_PIN                          (WKP_PS0)

#define ICU_OVERFLOW_NOTIFICATION_API            (STD_ON)

#define ICU_SIGNALMEASUREMENT_USES_DMA          (STD_OFF)
#define ICU_TIMESTAMP_USES_DMA                  (STD_ON)
#define ICU_MULTI_CORE_SUPPORT                  (STD_ON)   
#define ICU_NONE_ECUM_WAKEUP_SOURCE_REF         (uint32)0U

#define IcuChannel_FCCU_EOUT                            (Icu_IcuChannel_FCCU_EOUT)
#define Icu_IcuChannel_FCCU_EOUT                        ((Icu_ChannelType)0U) 
#define IcuConf_IcuChannel_IcuChannel_FCCU_EOUT         ((Icu_ChannelType)0U) 
#define IcuChannel_PWM_CH1                            (Icu_IcuChannel_PWM_CH1)
#define Icu_IcuChannel_PWM_CH1                        ((Icu_ChannelType)1U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_CH1         ((Icu_ChannelType)1U) 
#define IcuChannel_PWM_CH2                            (Icu_IcuChannel_PWM_CH2)
#define Icu_IcuChannel_PWM_CH2                        ((Icu_ChannelType)2U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_CH2         ((Icu_ChannelType)2U) 
#define IcuChannel_PWM_CH3                            (Icu_IcuChannel_PWM_CH3)
#define Icu_IcuChannel_PWM_CH3                        ((Icu_ChannelType)3U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_CH3         ((Icu_ChannelType)3U) 
#define IcuChannel_PWM_CH4                            (Icu_IcuChannel_PWM_CH4)
#define Icu_IcuChannel_PWM_CH4                        ((Icu_ChannelType)4U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_CH4         ((Icu_ChannelType)4U) 
#define IcuChannel_PWM_CH5                            (Icu_IcuChannel_PWM_CH5)
#define Icu_IcuChannel_PWM_CH5                        ((Icu_ChannelType)5U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_CH5         ((Icu_ChannelType)5U) 
#define IcuChannel_PWM_CH6                            (Icu_IcuChannel_PWM_CH6)
#define Icu_IcuChannel_PWM_CH6                        ((Icu_ChannelType)6U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_CH6         ((Icu_ChannelType)6U) 
#define IcuChannel_PWM_CH7                            (Icu_IcuChannel_PWM_CH7)
#define Icu_IcuChannel_PWM_CH7                        ((Icu_ChannelType)7U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_CH7         ((Icu_ChannelType)7U) 
#define IcuChannel_PWM_OUT_FB1                            (Icu_IcuChannel_PWM_OUT_FB1)
#define Icu_IcuChannel_PWM_OUT_FB1                        ((Icu_ChannelType)8U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_OUT_FB1         ((Icu_ChannelType)8U) 
#define IcuChannel_PWM_OUT_FB2                            (Icu_IcuChannel_PWM_OUT_FB2)
#define Icu_IcuChannel_PWM_OUT_FB2                        ((Icu_ChannelType)9U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_OUT_FB2         ((Icu_ChannelType)9U) 
#define IcuChannel_PWM_OUT_FB3                            (Icu_IcuChannel_PWM_OUT_FB3)
#define Icu_IcuChannel_PWM_OUT_FB3                        ((Icu_ChannelType)10U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_OUT_FB3         ((Icu_ChannelType)10U) 
#define IcuChannel_PWM_OUT_FB4                            (Icu_IcuChannel_PWM_OUT_FB4)
#define Icu_IcuChannel_PWM_OUT_FB4                        ((Icu_ChannelType)11U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_OUT_FB4         ((Icu_ChannelType)11U) 
#define IcuChannel_PWM_OUT_FB5                            (Icu_IcuChannel_PWM_OUT_FB5)
#define Icu_IcuChannel_PWM_OUT_FB5                        ((Icu_ChannelType)12U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_OUT_FB5         ((Icu_ChannelType)12U) 
#define IcuChannel_PWM_OUT_FB6                            (Icu_IcuChannel_PWM_OUT_FB6)
#define Icu_IcuChannel_PWM_OUT_FB6                        ((Icu_ChannelType)13U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_OUT_FB6         ((Icu_ChannelType)13U) 
#define IcuChannel_PWM_OUT_FB10                            (Icu_IcuChannel_PWM_OUT_FB10)
#define Icu_IcuChannel_PWM_OUT_FB10                        ((Icu_ChannelType)14U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_OUT_FB10         ((Icu_ChannelType)14U) 
#define IcuChannel_PWM_UH_FB                            (Icu_IcuChannel_PWM_UH_FB)
#define Icu_IcuChannel_PWM_UH_FB                        ((Icu_ChannelType)15U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_UH_FB         ((Icu_ChannelType)15U) 
#define IcuChannel_PWM_UL_FB                            (Icu_IcuChannel_PWM_UL_FB)
#define Icu_IcuChannel_PWM_UL_FB                        ((Icu_ChannelType)16U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_UL_FB         ((Icu_ChannelType)16U) 
#define IcuChannel_PWM_VH_FB                            (Icu_IcuChannel_PWM_VH_FB)
#define Icu_IcuChannel_PWM_VH_FB                        ((Icu_ChannelType)17U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_VH_FB         ((Icu_ChannelType)17U) 
#define IcuChannel_PWM_VL_FB                            (Icu_IcuChannel_PWM_VL_FB)
#define Icu_IcuChannel_PWM_VL_FB                        ((Icu_ChannelType)18U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_VL_FB         ((Icu_ChannelType)18U) 
#define IcuChannel_PWM_WH_FB                            (Icu_IcuChannel_PWM_WH_FB)
#define Icu_IcuChannel_PWM_WH_FB                        ((Icu_ChannelType)19U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_WH_FB         ((Icu_ChannelType)19U) 
#define IcuChannel_PWM_WL_FB                            (Icu_IcuChannel_PWM_WL_FB)
#define Icu_IcuChannel_PWM_WL_FB                        ((Icu_ChannelType)20U) 
#define IcuConf_IcuChannel_IcuChannel_PWM_WL_FB         ((Icu_ChannelType)20U) 
#define IcuChannel_DI_W_OCP                            (Icu_IcuChannel_DI_W_OCP)
#define Icu_IcuChannel_DI_W_OCP                        ((Icu_ChannelType)21U) 
#define IcuConf_IcuChannel_IcuChannel_DI_W_OCP         ((Icu_ChannelType)21U) 
#define IcuChannel_DI_V_OCP                            (Icu_IcuChannel_DI_V_OCP)
#define Icu_IcuChannel_DI_V_OCP                        ((Icu_ChannelType)22U) 
#define IcuConf_IcuChannel_IcuChannel_DI_V_OCP         ((Icu_ChannelType)22U) 
#define IcuChannel_DI_U_OCP                            (Icu_IcuChannel_DI_U_OCP)
#define Icu_IcuChannel_DI_U_OCP                        ((Icu_ChannelType)23U) 
#define IcuConf_IcuChannel_IcuChannel_DI_U_OCP         ((Icu_ChannelType)23U) 
#define IcuChannel_OVER_DC1                            (Icu_IcuChannel_OVER_DC1)
#define Icu_IcuChannel_OVER_DC1                        ((Icu_ChannelType)24U) 
#define IcuConf_IcuChannel_IcuChannel_OVER_DC1         ((Icu_ChannelType)24U) 
#define IcuChannel_OVER_DC2                            (Icu_IcuChannel_OVER_DC2)
#define Icu_IcuChannel_OVER_DC2                        ((Icu_ChannelType)25U) 
#define IcuConf_IcuChannel_IcuChannel_OVER_DC2         ((Icu_ChannelType)25U) 
#define PWM_CH8                                         (Icu_PWM_CH8)
#define Icu_PWM_CH8                                     ((Icu_ChannelType)26U) 
#define IcuConf_IcuChannel_PWM_CH8                      ((Icu_ChannelType)26U) 
#define PWM_CH9                                         (Icu_PWM_CH9)
#define Icu_PWM_CH9                                     ((Icu_ChannelType)27U) 
#define IcuConf_IcuChannel_PWM_CH9                      ((Icu_ChannelType)27U) 
#define MCU_PWM_OUT_FB11                                (Icu_MCU_PWM_OUT_FB11)
#define Icu_MCU_PWM_OUT_FB11                            ((Icu_ChannelType)28U) 
#define IcuConf_IcuChannel_MCU_PWM_OUT_FB11             ((Icu_ChannelType)28U) 
#define MCU_DI_OCPorOV_TRIGGER                          (Icu_MCU_DI_OCPorOV_TRIGGER)
#define Icu_MCU_DI_OCPorOV_TRIGGER                      ((Icu_ChannelType)29U) 
#define IcuConf_IcuChannel_MCU_DI_OCPorOV_TRIGGER       ((Icu_ChannelType)29U) 

#define ICU_MAX_CHANNEL                         (30U)
#define ICU_MAX_MODULE                          (3U)
#define ICU_INVALID_DMA_CHANNEL                 ((Icu_ChannelType)0xFF)


/* ICU Module Config */
#define ICU_GTM_USED                            (STD_ON)
#define ICU_EMIOS_USED                          (STD_OFF)
#define ICU_ETPU_USED                           (STD_OFF)
#define ICU_CCU7_USED                           (STD_OFF)

/* Config GTM channel num */
#define ICU_GTM_CHANNEL_NUM                     (30U)

/*===================================================================================================
*                                      LOCAL CONSTANTS
====================================================================================================*/

/*===================================================================================================
*                          GLOBAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
====================================================================================================*/
#define ICU_CONFIG_DECLARATION extern CONST(Icu_ConfigType, ICU_CONST) Icu_Config;

#ifdef __cplusplus
}
#endif
#endif /* ICU_CFG_H */


/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC 
*   Peripheral           : ICU
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
*   @file    Icu_AutoSAR_Wrapper.c
*   @version 3.0.0 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/* PRQA S 3432, 0380, 0686, 1006, 3205, 1535, 1756,1594, 2992,1526 EOF */
/* PRQA S 2844, 0491, 2976, 2934, 1259, 2053, 2052,2013, 2996, 2755 EOF */
/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/

#include "Icu_AutoSAR_Wrapper.h"
#include "Icu_Cfg.h"
#include "SchM_Icu.h"

/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_AUTOSAR_WRAPPER_VENDOR_ID_C                  176

#define ICU_AUTOSAR_WRAPPER_MAJOR_VER_C                  4
#define ICU_AUTOSAR_WRAPPER_MINOR_VER_C                  4
#define ICU_AUTOSAR_WRAPPER_REVISION_VER_C               0

#define ICU_AUTOSAR_WRAPPER_SW_MAJOR_VER_C               3
#define ICU_AUTOSAR_WRAPPER_SW_MINOR_VER_C               0
#define ICU_AUTOSAR_WRAPPER_SW_PATCH_VER_C               0

#if (ICU_AUTOSAR_WRAPPER_VENDOR_ID_C != ICU_AUTOSAR_WRAPPER_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_AUTOSAR_WRAPPER_MAJOR_VER_C != ICU_AUTOSAR_WRAPPER_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_AUTOSAR_WRAPPER_MINOR_VER_C != ICU_AUTOSAR_WRAPPER_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_AUTOSAR_WRAPPER_REVISION_VER_C != ICU_AUTOSAR_WRAPPER_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_AUTOSAR_WRAPPER_SW_MAJOR_VER_C != ICU_AUTOSAR_WRAPPER_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_AUTOSAR_WRAPPER_SW_MINOR_VER_C != ICU_AUTOSAR_WRAPPER_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_AUTOSAR_WRAPPER_SW_PATCH_VER_C != ICU_AUTOSAR_WRAPPER_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
typedef struct
{
    volatile unsigned int irqState:1;
    volatile unsigned int irqComplete:1;
} Icu_MultiCoreSyncTypes;
#endif /* ICU_MULTI_CORE_SUPPORT == STD_ON */

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/**
* Check pointer is valid
*/
#define ICU_VALID_PTR(ptr)                  do { \
                                                if (NULL_PTR == (ptr)) \
                                                { \
                                                    return ; \
                                                } \
                                            } while(0)

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
/**
* Stores value of Measurement DMA mode
*/
#define ICU_START_SEC_VAR_SHARED_INIT
#include "Icu_MemMap.h"
static VAR(Icu_MeasurementInfo, AUTOMATIC) gIcu_MeasurementInfo[ICU_CORE_NUM][ICU_MAX_CHANNEL] = {{{{0U},0U,0U}}};
#define ICU_STOP_SEC_VAR_SHARED_INIT
#include "Icu_MemMap.h"

extern VAR(Icu_ChannelInfoType, AUTOMATIC) sIcu_ChannelInfo[ICU_CORE_NUM][ICU_MAX_CHANNEL];
extern P2CONST(Icu_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_CfgPtr[ICU_CORE_NUM];
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_Init \
( \
    P2CONST(Icu_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    ICU_VALID_PTR(sIcu_WrapperConfigPtr);
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
    if (sIcu_WrapperConfigPtr->Icu_GtmConfig != NULL_PTR)
    {
        Icu_Gtm_Wrapper_Init(sIcu_WrapperConfigPtr->Icu_GtmConfig);
    }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
    if (sIcu_WrapperConfigPtr->Icu_eMoisConfig != NULL_PTR)
    {
        Icu_eMios_Wrapper_Init(sIcu_WrapperConfigPtr->Icu_eMoisConfig);
    }
#if (defined(RESOURCE_SUPPORT_ETPU))
    if (sIcu_WrapperConfigPtr->Icu_eTpuConfig != NULL_PTR)
    {
        Icu_eTpu_Wrapper_Init(sIcu_WrapperConfigPtr->Icu_eTpuConfig);
    }
#endif /* (defined(RESOURCE_SUPPORT_ETPU)) */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
    if (sIcu_WrapperConfigPtr->Icu_Ccu7Config != NULL_PTR)
    {
        Icu_Ccu7_Wrapper_Init(sIcu_WrapperConfigPtr->Icu_Ccu7Config);
    }
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
#if (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI))
    if(sIcu_WrapperConfigPtr->Icu_WkpuConfig != NULL_PTR)
    {
        Icu_Wkpu_Wrapper_Init(sIcu_WrapperConfigPtr->Icu_WkpuConfig);
    }
#endif /* (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI)) */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_DEINIT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_DeInit \
( \
    P2CONST(Icu_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    ICU_VALID_PTR(sIcu_WrapperConfigPtr);
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
    if (sIcu_WrapperConfigPtr->Icu_GtmConfig != NULL_PTR)
    {
        Icu_Gtm_Wrapper_DeInit(sIcu_WrapperConfigPtr->Icu_GtmConfig);
    }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
    if (sIcu_WrapperConfigPtr->Icu_eMoisConfig != NULL_PTR)
    {
        Icu_eMios_Wrapper_DeInit(sIcu_WrapperConfigPtr->Icu_eMoisConfig);
    }

#if (defined(RESOURCE_SUPPORT_ETPU))
    if (sIcu_WrapperConfigPtr->Icu_eTpuConfig != NULL_PTR)
    {
        Icu_eTpu_Wrapper_DeInit(sIcu_WrapperConfigPtr->Icu_eTpuConfig);
    }
#endif /* (defined(RESOURCE_SUPPORT_ETPU)) */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
    if (sIcu_WrapperConfigPtr->Icu_Ccu7Config != NULL_PTR)
    {
        Icu_Ccu7_Wrapper_DeInit(sIcu_WrapperConfigPtr->Icu_Ccu7Config);
    }
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
#if (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI))
    if(sIcu_WrapperConfigPtr->Icu_WkpuConfig != NULL_PTR)
    {
        Icu_Wkpu_Wrapper_DeInit(sIcu_WrapperConfigPtr->Icu_WkpuConfig);
    }
#endif /* (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI)) */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_IrqConfig \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr, \
    VAR(boolean, AUTOMATIC) IsEnable
)
{
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;
    ICU_VALID_PTR(sIcu_WrapperConfigPtr);

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
    case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
    case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
    case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
    case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
    case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
    case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
    case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
    case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */
    {
        Icu_Gtm_Wrapper_IrqConfig(u16Icu_Channel, sIcu_WrapperConfigPtr->Icu_GtmConfig, IsEnable);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */

    case ICU_eMIOS_0:
    case ICU_eMIOS_1:
    {
        Icu_eMios_Wrapper_IrqConfig( u16Icu_Channel, sIcu_WrapperConfigPtr->Icu_eMoisConfig, IsEnable);
        break;
    }
#if (defined(RESOURCE_SUPPORT_ETPU))	
    case ICU_eTPU_A:
    case ICU_eTPU_B:
    case ICU_eTPU_C:
    {
        Icu_eTpu_Wrapper_IrqConfig( u16Icu_Channel, sIcu_WrapperConfigPtr->Icu_eTpuConfig, IsEnable);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_ETPU)) */

#if (defined(RESOURCE_SUPPORT_CCU7_IP))
    case ICU_CCU7_INS0:
    case ICU_CCU7_INS1:
    {
        Icu_Ccu7_Wrapper_IrqConfig( u16Icu_Channel, sIcu_WrapperConfigPtr->Icu_Ccu7Config, IsEnable);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
    default:
        /*nothing todo */
        break;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_SetActivationCondition \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    VAR(Icu_ActivationType, AUTOMATIC) eIcu_Activation, \
    VAR(Icu_MeasurementModeType, AUTOMATIC) eIcu_Channelmode,
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;
    ICU_VALID_PTR(sIcu_WrapperConfigPtr);

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))		
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
    case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
    case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
    case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
    case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
    case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
    case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
    case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
    case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */
    {
        Icu_Gtm_Wrapper_SetActivationCondition(u16Icu_Channel, \
            eIcu_Activation, \
            sIcu_WrapperConfigPtr->Icu_GtmConfig);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
    case ICU_eMIOS_0:
    case ICU_eMIOS_1:
    {
        Icu_eMios_Wrapper_SetActivationCondition(u16Icu_Channel, \
            eIcu_Activation, \
            eIcu_Channelmode, \
            sIcu_WrapperConfigPtr->Icu_eMoisConfig);
        break;
    }
#if (defined(RESOURCE_SUPPORT_ETPU))
    case ICU_eTPU_A:
    case ICU_eTPU_B:
    case ICU_eTPU_C:
    {
        Icu_eTpu_Wrapper_SetActivationCondition(u16Icu_Channel, \
            eIcu_Activation, \
            eIcu_Channelmode, \
            sIcu_WrapperConfigPtr->Icu_eTpuConfig);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_ETPU)) */	
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
    case ICU_CCU7_INS0:
    case ICU_CCU7_INS1:
    {
        Icu_Ccu7_Wrapper_SetActivationCondition(u16Icu_Channel, \
            eIcu_Activation, \
            sIcu_WrapperConfigPtr->Icu_Ccu7Config);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
#if (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI))
    case ICU_WKPU:
    {
        Icu_Wkpu_Wrapper_SetActivationCondition( u16Icu_Channel,
                                                 eIcu_Activation, \
                                                 sIcu_WrapperConfigPtr->Icu_WkpuConfig);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI)) */
    default:
        /*nothing todo */
        break;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#if (ICU_STARTTIMESTAMP_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_StartTimestamp \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    VAR(boolean,         AUTOMATIC) bDmaSupport, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;
    ICU_VALID_PTR(sIcu_WrapperConfigPtr);

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:IDP,NIV */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))			
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
    case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
    case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
    case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
    case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
    case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
    case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
    case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
    case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */
    {
        Icu_Gtm_Wrapper_StartTimestamp(u16Icu_Channel, \
            (boolean)bDmaSupport, \
            sIcu_WrapperConfigPtr->Icu_GtmConfig);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
    case ICU_eMIOS_0:
    case ICU_eMIOS_1:
    {
        Icu_eMios_Wrapper_StartTimestamp(u16Icu_Channel, \
            (boolean)bDmaSupport, \
            sIcu_WrapperConfigPtr->Icu_eMoisConfig);
        break;
    }
#if (defined(RESOURCE_SUPPORT_ETPU))
    case ICU_eTPU_A:
    case ICU_eTPU_B:
    case ICU_eTPU_C:
    {
        Icu_eTpu_Wrapper_StartTimestamp(u16Icu_Channel, \
            (boolean)bDmaSupport, \
            sIcu_WrapperConfigPtr->Icu_eTpuConfig);
        break;
    }
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
    case ICU_CCU7_INS0:
    case ICU_CCU7_INS1:
    {
        Icu_Ccu7_Wrapper_StartTimestamp(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_Ccu7Config);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */

    default:
        /*nothing todo */
        break;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_STARTTIMESTAMP_API == STD_ON */

#if (ICU_STOPTIMESTAMP_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_StopTimestamp \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;
    ICU_VALID_PTR(sIcu_WrapperConfigPtr);

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:IDP,NIV */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))		
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
    case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
    case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
    case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
    case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
    case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
    case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
    case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
    case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */
    {
        Icu_Gtm_Wrapper_StopTimestamp(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_GtmConfig);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
    case ICU_eMIOS_0:
    case ICU_eMIOS_1:
    {
        Icu_eMios_Wrapper_StopTimestamp(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_eMoisConfig);
        break;
    }
#if (defined(RESOURCE_SUPPORT_ETPU))
    case ICU_eTPU_A:
    case ICU_eTPU_B:
    case ICU_eTPU_C:
    {
        Icu_eTpu_Wrapper_StopTimestamp(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_eTpuConfig);
        break;
    }
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
    case ICU_CCU7_INS0:
    case ICU_CCU7_INS1:
    {
        Icu_Ccu7_Wrapper_StopTimestamp(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_Ccu7Config);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
    default:
        /*nothing todo */
        break;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_STOPTIMESTAMP_API == STD_ON */

#if (ICU_GETTIMESTAMPINDEX_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_IndexType, ICU_CODE) Icu_Autosar_Wrapper_GetTimestampIndex \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_IndexType, AUTOMATIC) returnVal = (Icu_IndexType)0;
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))		
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
    case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
    case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
    case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
    case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
    case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
    case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
    case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
    case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */	           
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */	
    case ICU_eMIOS_0:
    case ICU_eMIOS_1:
#if (defined(RESOURCE_SUPPORT_ETPU))
    case ICU_eTPU_A:
    case ICU_eTPU_B:
    case ICU_eTPU_C:
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
	case ICU_CCU7_INS0:
    case ICU_CCU7_INS1:
#endif /*  (defined(RESOURCE_SUPPORT_CCU7_IP)) */
    {
        if (NULL_PTR == sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].u32Icu_ChannelBuffer)/* polyspace RTE:OBAI */
        {
            returnVal = 0U;
        }
        else
        {
            returnVal = sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].u32Icu_ChannelBufferIndex;/* polyspace RTE:OBAI */
        }
        break;
    }

    default:
        /*nothing todo */
        break;
    }

    return returnVal;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_GETTIMESTAMPINDEX_API == STD_ON */

#if (ICU_RESETEDGECOUNT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_ResetEdgeCount \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;
    ICU_VALID_PTR(sIcu_WrapperConfigPtr);

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
    case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
    case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
    case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
    case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
    case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
    case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
    case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
    case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */	            
    {
        Icu_Gtm_Wrapper_ResetEdgeCount(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_GtmConfig);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */	

    case ICU_eMIOS_0:
    case ICU_eMIOS_1:
    {
        Icu_eMios_Wrapper_ResetEdgeCount(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_eMoisConfig);
        break;
    }
#if (defined(RESOURCE_SUPPORT_ETPU))
    case ICU_eTPU_A:
    case ICU_eTPU_B:
    case ICU_eTPU_C:
    {
        Icu_eTpu_Wrapper_ResetEdgeCount(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_eTpuConfig);
        break;
    }
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
    default:
        /*nothing todo */
        break;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_RESETEDGECOUNT_API == STD_ON */

#if (ICU_ENABLEEDGECOUNT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_EnableEdgeCount \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;
    ICU_VALID_PTR(sIcu_WrapperConfigPtr);

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))		
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
    case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
    case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
    case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
    case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
    case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
    case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
    case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
    case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */	       
    {
        Icu_Gtm_Wrapper_EnableEdgeCount(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_GtmConfig);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
    case ICU_eMIOS_0:
    case ICU_eMIOS_1:
    {
        Icu_eMios_Wrapper_EnableEdgeCount(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_eMoisConfig);
        break;
    }
#if (defined(RESOURCE_SUPPORT_ETPU))
    case ICU_eTPU_A:
    case ICU_eTPU_B:
    case ICU_eTPU_C:
    {
        Icu_eTpu_Wrapper_EnableEdgeCount(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_eTpuConfig);
        break;
    }
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
    default:
        /*nothing todo */
        break;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_ENABLEEDGECOUNT_API == STD_ON */

#if (ICU_DISABLEEDGECOUNT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_DisableEdgeCount \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;
    ICU_VALID_PTR(sIcu_WrapperConfigPtr);

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))		
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
    case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
    case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
    case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
    case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
    case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
    case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
    case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
    case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */	             
    {
        Icu_Gtm_Wrapper_DisableEdgeCount(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_GtmConfig);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
    case ICU_eMIOS_0:
    case ICU_eMIOS_1:
    {
        Icu_eMios_Wrapper_DisableEdgeCount(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_eMoisConfig);
        break;
    }
#if (defined(RESOURCE_SUPPORT_ETPU))
    case ICU_eTPU_A:
    case ICU_eTPU_B:
    case ICU_eTPU_C:
    {
        Icu_eTpu_Wrapper_DisableEdgeCount(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_eTpuConfig);
        break;
    }
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
    default:
        /*nothing todo */
        break;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_DISABLEEDGECOUNT_API == STD_ON */

#if (ICU_GETEDGENUMBERS_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_EdgeNumberType, ICU_CODE) Icu_Autosar_Wrapper_GetEdgeNumbers \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_EdgeNumberType, AUTOMATIC) returnVal = (Icu_EdgeNumberType)0;
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))		
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
    case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
    case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
    case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
    case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
    case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
    case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
    case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
    case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */	            
    {
        returnVal = (Icu_EdgeNumberType)Icu_Gtm_Wrapper_GetEdgeNumbers(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_GtmConfig);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
    case ICU_eMIOS_0:
    case ICU_eMIOS_1:
    {
        returnVal = (Icu_EdgeNumberType)Icu_eMios_Wrapper_GetEdgeNumbers(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_eMoisConfig);
        break;
    }
#if (defined(RESOURCE_SUPPORT_ETPU))
    case ICU_eTPU_A:
    case ICU_eTPU_B:
    case ICU_eTPU_C:
    {
        returnVal = (Icu_EdgeNumberType)Icu_eTpu_Wrapper_GetEdgeNumbers(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_eTpuConfig);
        break;
    }
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
    default:
        /*nothing todo */
        break;
    }

    return returnVal;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_GETEDGENUMBERS_API == STD_ON */

#if (ICU_ENABLEEDGEDETECTION_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_EnableEdgeDetection \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr, \
    VAR(boolean, AUTOMATIC) IsEnable  \
)
{
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;
    ICU_VALID_PTR(sIcu_WrapperConfigPtr);

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))			
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
    case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
    case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
    case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
    case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
    case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
    case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
    case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
    case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */	            
    {
        Icu_Gtm_Wrapper_EnableEdgeDetection(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_GtmConfig);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
    case ICU_eMIOS_0:
    case ICU_eMIOS_1:
    {
        Icu_eMios_Wrapper_EnableEdgeDetection(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_eMoisConfig);
        break;
    }
#if (defined(RESOURCE_SUPPORT_ETPU))
    case ICU_eTPU_A:
    case ICU_eTPU_B:
    case ICU_eTPU_C:
    {
        Icu_eTpu_Wrapper_EnableEdgeDetection(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_eTpuConfig);
        break;
    }
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
    case ICU_CCU7_INS0:
    case ICU_CCU7_INS1:
    {
        Icu_Ccu7_Wrapper_EnableEdgeDetection(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_Ccu7Config);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
#if (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI))
    case ICU_WKPU:
    {
        Icu_Wkpu_Wrapper_EnableEdgeDetection(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_WkpuConfig);
        
        Icu_Wkpu_Wrapper_IrqConfig( u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_WkpuConfig, TRUE);

        Icu_Wkpu_Wrapper_WakeupConfig( u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_WkpuConfig, IsEnable);
        break;
    }
#endif/* (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI)) */

    default:
        /*nothing todo */
        break;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_ENABLEEDGEDETECTION_API == STD_ON */

#if (ICU_DISABLEEDGEDETECTION_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_DisableEdgeDetection \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr, \
    VAR(boolean, AUTOMATIC) IsEnable   \
)
{
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;
    ICU_VALID_PTR(sIcu_WrapperConfigPtr);

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
    case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
    case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
    case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
    case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
    case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
    case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
    case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
    case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */	            
    {
        Icu_Gtm_Wrapper_DisableEdgeDetection(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_GtmConfig);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
    case ICU_eMIOS_0:
    case ICU_eMIOS_1:
    {
        Icu_eMios_Wrapper_DisableEdgeDetection(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_eMoisConfig);
        break;
    }
#if (defined(RESOURCE_SUPPORT_ETPU))
    case ICU_eTPU_A:
    case ICU_eTPU_B:
    case ICU_eTPU_C:
    {
        Icu_eTpu_Wrapper_DisableEdgeDetection(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_eTpuConfig);
        break;
    }
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
    case ICU_CCU7_INS0:
    case ICU_CCU7_INS1:
    {
        Icu_Ccu7_Wrapper_DisableEdgeDetection(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_Ccu7Config);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
#if (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI))
    case ICU_WKPU:
    {
        Icu_Wkpu_Wrapper_WakeupConfig( u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_WkpuConfig, FALSE);

        Icu_Wkpu_Wrapper_IrqConfig( u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_WkpuConfig, IsEnable);
        break;
    }
#endif/* (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI)) */
    default:
        /*nothing todo */
        break;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_DISABLEEDGEDETECTION_API == STD_ON */

#if (ICU_STARTSIGNALMEASUREMENT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_StartSignalMeasurement \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    VAR(boolean,         AUTOMATIC) bDmaSupport, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;
    ICU_VALID_PTR(sIcu_WrapperConfigPtr);

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
    case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
    case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
    case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
    case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
    case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
    case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
    case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
    case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */	         
    {
        Icu_Gtm_Wrapper_StartSignalMeasurement(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_GtmConfig);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
    case ICU_eMIOS_0:
    case ICU_eMIOS_1:
    {
        Icu_eMios_Wrapper_StartSignalMeasurement(u16Icu_Channel, \
            4, \
            0, \
            bDmaSupport, \
            sIcu_WrapperConfigPtr->Icu_eMoisConfig);
        break;
    }
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
    case ICU_CCU7_INS0:
    case ICU_CCU7_INS1:
    {
        Icu_Ccu7_Wrapper_StartSignalMeasurement(u16Icu_Channel, \
            4, \
            0, \
            sIcu_WrapperConfigPtr->Icu_Ccu7Config);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */	
#if (defined(RESOURCE_SUPPORT_ETPU))
    case ICU_eTPU_A:
    case ICU_eTPU_B:
    case ICU_eTPU_C:
    {
        Icu_eTpu_Wrapper_StartSignalMeasurement(u16Icu_Channel, \
            4, \
            0, \
            bDmaSupport, \
            sIcu_WrapperConfigPtr->Icu_eTpuConfig);
        break;
    }
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
    default:
        /*nothing todo */
        break;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_STARTSIGNALMEASUREMENT_API == STD_ON */

#if (ICU_STOPSIGNALMEASUREMENT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_StopSignalMeasurement \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;
    ICU_VALID_PTR(sIcu_WrapperConfigPtr);

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))		
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
    case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
    case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
    case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
    case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
    case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
    case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
    case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
    case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */	            
    {
        Icu_Gtm_Wrapper_StopSignalMeasurement(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_GtmConfig);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
    case ICU_eMIOS_0:
    case ICU_eMIOS_1:
    {
        Icu_eMios_Wrapper_StopSignalMeasurement(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_eMoisConfig);
        break;
    }
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
    case ICU_CCU7_INS0:
    case ICU_CCU7_INS1:
    {
        Icu_Ccu7_Wrapper_StopSignalMeasurement(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_Ccu7Config);
        break;
    }
#endif /*(defined(RESOURCE_SUPPORT_CCU7_IP))*/	
#if (defined(RESOURCE_SUPPORT_ETPU))
    case ICU_eTPU_A:
    case ICU_eTPU_B:
    case ICU_eTPU_C:
    {
        Icu_eTpu_Wrapper_StopSignalMeasurement(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_eTpuConfig);
        break;
    }
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
    default:
        /*nothing todo */
        break;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_STOPSIGNALMEASUREMENT_API == STD_ON */

#if (ICU_GETTIMEELAPSED_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_ValueType, ICU_CODE) Icu_Autosar_Wrapper_GetTimeElapsed \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_ValueType, AUTOMATIC) returnVal = 0U;
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
    case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
    case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
    case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
    case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
    case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
    case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
    case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
    case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */	             
    {
        returnVal = (Icu_ValueType)Icu_Gtm_Wrapper_GetTimeElapsed(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_GtmConfig);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
    case ICU_eMIOS_0:
    case ICU_eMIOS_1:
    {
        returnVal = (Icu_ValueType)Icu_eMios_Wrapper_GetTimeElapsed(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_eMoisConfig);
        break;
    }
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
    case ICU_CCU7_INS0:
    case ICU_CCU7_INS1:
    {
        returnVal = (Icu_ValueType)Icu_Ccu7_Wrapper_GetTimeElapsed(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_Ccu7Config);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */	
#if (defined(RESOURCE_SUPPORT_ETPU))
    case ICU_eTPU_A:
    case ICU_eTPU_B:
    case ICU_eTPU_C:
    {
        returnVal = (Icu_ValueType)Icu_eTpu_Wrapper_GetTimeElapsed(u16Icu_Channel, \
            sIcu_WrapperConfigPtr->Icu_eTpuConfig);
        break;
    }
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */

    default:
        /*nothing todo */
        break;

    }

    return returnVal;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_GETTIMEELAPSED_API == STD_ON */

#if (ICU_GETDUTYCYCLEVALUES_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_GetDutyCycleValues \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    P2VAR(Icu_DutyCycleType, AUTOMATIC, ICU_APPL_DATA) sIcu_DutyCycleValues, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();
    ICU_VALID_PTR(sIcu_WrapperConfigPtr);

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
    case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
    case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
    case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
    case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
    case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
    case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
    case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
    case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */	
    case ICU_eMIOS_0:
    case ICU_eMIOS_1:
#if (defined(RESOURCE_SUPPORT_ETPU))	
    case ICU_eTPU_A:
    case ICU_eTPU_B:
    case ICU_eTPU_C:
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
	case ICU_CCU7_INS0:
    case ICU_CCU7_INS1:
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */	
    {
        SchM_Enter_Icu_EXCLUSIVE_AREA_02();
        sIcu_DutyCycleValues->PeriodTime = \
                (Icu_ValueType)sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].u32Icu_ChannelPeriod;/* polyspace RTE:OBAI */
        sIcu_DutyCycleValues->ActiveTime = \
                (Icu_ValueType)sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].u32Icu_ChannelActiveTime;/* polyspace RTE:OBAI */
        if((eModule == ICU_eMIOS_0) || (eModule == ICU_eMIOS_1))
        {
            if(sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].sIcu_ChannelConfig.IcuChannel_bDmaSupport == TRUE)
            {
            	VAR(uint32, AUTOMATIC) tempA1;
            	VAR(uint32, AUTOMATIC) tempB1;
            	VAR(uint32, AUTOMATIC) tempA2;
            	VAR(uint32, AUTOMATIC) tempB2;

            	VAR(uint32, AUTOMATIC) firLeadEdge;
            	VAR(uint32, AUTOMATIC) secLeadEdge;
            	VAR(uint32, AUTOMATIC) firTrailEdge;
            	VAR(uint32, AUTOMATIC)secTrailEdge;
            	VAR(uint16, AUTOMATIC) cIter;
            	VAR(uint16, AUTOMATIC)edpolState = 0U;

                P2CONST(struct ICU_eMIOS_ConfigType, ICU_CONST, ICU_APPL_DATA) Icu_eMoisConfig = sIcu_WrapperConfigPtr->Icu_eMoisConfig;
                P2CONST(ICU_eMIOS_ChannelConfig,  ICU_VAR, ICU_APPL_DATA) peMiosChannelConfig = NULL_PTR;

                for(uint16 i=0; i < Icu_eMoisConfig->uChannelCount; i++)/* polyspace RTE:NIV,IDP */
                {
                    if(Icu_eMoisConfig->peMiosChannelConfig[i].IcuConfig_Instance == u16Icu_Channel)/* polyspace RTE:NIV,NIP,IDP */
                    {
                        peMiosChannelConfig = &Icu_eMoisConfig->peMiosChannelConfig[i];
                    }
                }
                if( peMiosChannelConfig != NULL_PTR)
                {
                    (void)EDMA_LLD_ClearChannelRequest(peMiosChannelConfig->IcuChannel_DmaChannel);/* PRQA S 2813 *//* polyspace RTE:NIV,IDP */

                    if(peMiosChannelConfig->IcuChannel_DmaChannel < 64U)
                    {
                        cIter = (uint16)DMA_0_P->TCD[peMiosChannelConfig->IcuChannel_DmaChannel].BITER.ELINKNO.R - DMA_0_P->TCD[peMiosChannelConfig->IcuChannel_DmaChannel].CITER.ELINKNO.R;/* polyspace RTE:NIV */
                    }
                    else
                    {
                        cIter = (uint16)DMA_1_P->TCD[peMiosChannelConfig->IcuChannel_DmaChannel - 64U].BITER.ELINKNO.R - DMA_1_P->TCD[peMiosChannelConfig->IcuChannel_DmaChannel - 64U].CITER.ELINKNO.R;/* polyspace RTE:NIV,OBAI */
                    }

                }
                tempA1 = gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer[0];
                tempB1 = gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer[1];
                tempA2 = gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer[2];
                tempB2 = gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer[3];

                gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer[0] = 0U;
                gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer[1] = 0U;
                gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer[2] = 0U;
                gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer[3] = 0U;

                if( peMiosChannelConfig != NULL_PTR)
                {
                    (void)EDMA_LLD_SetChannelRequest(peMiosChannelConfig->IcuChannel_DmaChannel);/* polyspace RTE:NIV */
                
            
                    if(eModule == ICU_eMIOS_0)
                    {
                        edpolState = EMIOS_0.UC[0].C.B.EDPOL;/* polyspace RTE:NIV */
                    }
                    else
                    {
#if (defined(RESOURCE_SUPPORT_EMIOS1))
                        edpolState = EMIOS_1.UC[0].C.B.EDPOL;/* polyspace RTE:NIV */
#endif /*  (defined(RESOURCE_SUPPORT_EMIOS1)) */
                    }

                /* if peMiosChannelConfig->IcuChannel_DefaultStartEdge != ICU_RISING_EDGE */
                    if(edpolState == 1U)
                    {
                        if((cIter % 2U) == 0U)
                        {
                            firLeadEdge = tempB1;
                            secLeadEdge = tempB2;
                            firTrailEdge = tempA1;
                        }
                        else
                        {
                            firLeadEdge = tempB2;
                            secLeadEdge = tempB1;
                            firTrailEdge = tempA2;
                        }

                        if(firTrailEdge >= firLeadEdge)
                        {
                            sIcu_DutyCycleValues->ActiveTime = firTrailEdge - firLeadEdge;
                        }
                        else
                        {
                            sIcu_DutyCycleValues->ActiveTime = ((0xFFFFFFU + firTrailEdge) - firLeadEdge);
                        }

                        if(secLeadEdge >= firLeadEdge)
                        {
                            sIcu_DutyCycleValues->PeriodTime = secLeadEdge - firLeadEdge;
                        }
                        else
                        {
                            sIcu_DutyCycleValues->PeriodTime = ((0xFFFFFFU + secLeadEdge) - firLeadEdge);
                        }
                    }
                    else
                    {
                        if((cIter % 2U) == 0U)
                        {
                            firTrailEdge = tempB1;
                            secTrailEdge = tempB2;
                            firLeadEdge = tempA1;
                        }
                        else
                        {
                            firTrailEdge = tempB2;
                            secTrailEdge = tempB1;
                            firLeadEdge = tempA2;
                        }
                        if(firLeadEdge >= firTrailEdge)
                        {
                            sIcu_DutyCycleValues->ActiveTime = firLeadEdge - firTrailEdge;
                        }
                        else
                        {
                            sIcu_DutyCycleValues->ActiveTime = (0xFFFFFFU - firTrailEdge) + firLeadEdge ;
                        }
                        if(secTrailEdge >= firTrailEdge)
                        {
                        sIcu_DutyCycleValues->PeriodTime = secTrailEdge - firTrailEdge;
                        }
                        else
                        {
                        sIcu_DutyCycleValues->PeriodTime = (0xFFFFFFU - firTrailEdge) + secTrailEdge;
                        }
                    }
                }

            }
        }
        else
        {
        	/*do nothing*/
        }
        if((eModule == ICU_GTM_TIM0) || (eModule == ICU_GTM_TIM1))
		{
            if(sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].sIcu_ChannelConfig.IcuChannel_bDmaSupport == TRUE)
            {
                sIcu_DutyCycleValues->ActiveTime = gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer[0];
                sIcu_DutyCycleValues->PeriodTime = gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer[1];

                sIcu_DutyCycleValues->ActiveTime = sIcu_DutyCycleValues->ActiveTime & 0x00FFFFFFUL;
                sIcu_DutyCycleValues->PeriodTime = sIcu_DutyCycleValues->PeriodTime & 0x00FFFFFFUL;

                gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer[0] = 0;
                gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer[1] = 0;
            }
		}
		else
		{
			/*do nothing*/
		}
        SchM_Exit_Icu_EXCLUSIVE_AREA_02();
        break;
    }

    default:
        /*nothing todo */
        break;
    }
    sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].u32Icu_ChannelActiveTime = 0UL;/* polyspace RTE:OBAI */
    sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].u32Icu_ChannelPeriod = 0UL;/* polyspace RTE:OBAI */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_GETDUTYCYCLEVALUES_API == STD_ON */

#if (ICU_CHECKWAKEUP_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_CheckWakeup \
( \
    VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource, \
    VAR(Icu_ChannelType, AUTOMATIC)u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;
    ICU_VALID_PTR(sIcu_WrapperConfigPtr);

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:OBAI,NIV,IDP */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))		
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
        case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
        case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
        case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
        case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
        case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
        case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
        case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
        case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */	
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */		
        case ICU_eMIOS_0:
        case ICU_eMIOS_1:
#if (defined(RESOURCE_SUPPORT_ETPU))		
        case ICU_eTPU_A:
        case ICU_eTPU_B:
        case ICU_eTPU_C:
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */		
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
		case ICU_CCU7_INS0:
    	case ICU_CCU7_INS1:
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */		
        {
            if (ICU_CHANNEL_STATE_WKUP == \
                Icu_GetChannelState(u16Icu_Channel,ICU_CHANNEL_STATE_WKUP))
            {
                /*SWS_Icu_00359*/
                (void)EcuM_SetWakeupEvent(WakeupSource);
                Icu_ClearChannelState(u16Icu_Channel,ICU_CHANNEL_STATE_WKUP);
            }
            break;
        }

        default:
            /*nothing todo */
            break;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_CHECKWAKEUP_API == STD_ON */

#if (ICU_GETVERSIONINFO_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_GetVersionInfo \
( \
    P2VAR(Std_VersionInfoType, AUTOMATIC, ICU_APPL_DATA) versioninfo \
)
{
    versioninfo->vendorID = (uint16)ICU_VENDOR_ID_CFG;
    versioninfo->moduleID = (uint8)ICU_MODULE_ID;
    versioninfo->sw_major_version = (uint8)ICU_SW_MAJOR_VERSION_CFG;
    versioninfo->sw_minor_version = (uint8)ICU_SW_MINOR_VERSION_CFG;
    versioninfo->sw_patch_version = (uint8)ICU_SW_PATCH_VERSION_CFG;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_GETVERSIONINFO_API == STD_ON */

#if (ICU_GETINPUTSTATE_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_InputStateType, ICU_CODE) Icu_Autosar_Wrapper_GetInputState \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_InputStateType, ICU_CODE) returnVal = ICU_IDLE;
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
        case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
        case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
        case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
        case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
        case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
        case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
        case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
        case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */	
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */		
        case ICU_eMIOS_0:
        case ICU_eMIOS_1:
#if (defined(RESOURCE_SUPPORT_ETPU))		
        case ICU_eTPU_A:
        case ICU_eTPU_B:
        case ICU_eTPU_C:
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */	
#if (defined(RESOURCE_SUPPORT_CCU7_IP))	
		case ICU_CCU7_INS0:
    	case ICU_CCU7_INS1:
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
#if (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI))		
        case ICU_WKPU:
#endif/* (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI)) */		
        {
            returnVal = sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].u32Icu_ChannelEdgeDetection;/* polyspace RTE:OBAI */
            if (returnVal == ICU_ACTIVE)
            {
                sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].u32Icu_ChannelEdgeDetection = ICU_IDLE;/* polyspace RTE:OBAI */
            }
            break;
        }
        default:
        {
            /*nothing*/
            break;
        }
    }
    return (Icu_InputStateType)returnVal;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_GETINPUTSTATE_API == STD_ON */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_LevelType, ICU_CODE) Icu_Autosar_Wrapper_GetInputLevel \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_LevelType, ICU_CODE) returnVal = ICU_LEVEL_LOW;
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
        case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
        case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
        case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
        case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
        case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
        case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
        case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
        case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */
        {
            returnVal = Icu_Gtm_Wrapper_GetInputLevel(u16Icu_Channel, \
                sIcu_WrapperConfigPtr->Icu_GtmConfig);
            break;
        }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */		
        case ICU_eMIOS_0:
        case ICU_eMIOS_1:
        {
            returnVal = Icu_eMios_Wrapper_GetInputLevel(u16Icu_Channel, \
                sIcu_WrapperConfigPtr->Icu_eMoisConfig);
            break;
        }
#if (defined(RESOURCE_SUPPORT_ETPU))		
        case ICU_eTPU_A:
        case ICU_eTPU_B:
        case ICU_eTPU_C:
        {
            returnVal = Icu_eTpu_Wrapper_GetInputLevel(u16Icu_Channel, \
                sIcu_WrapperConfigPtr->Icu_eTpuConfig);
            break;
        }
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
    case ICU_CCU7_INS0:
    case ICU_CCU7_INS1:
    {
//        returnVal = Icu_Ccu7_Wrapper_GetInputLevel(u16Icu_Channel, sIcu_WrapperConfigPtr->Icu_Ccu7Config);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
        default:
        {
            /*nothing todo */
            break;
        }
    }
    return returnVal;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(boolean, ICU_CODE) Icu_Autosar_Wrapper_GetOverFlow \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(boolean, ICU_CODE) returnVal = (boolean)FALSE;
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
        case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
        case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
        case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
        case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
        case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
        case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
        case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
        case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */
        {
            returnVal = Icu_Gtm_Wrapper_GetOverflow(u16Icu_Channel, \
                sIcu_WrapperConfigPtr->Icu_GtmConfig);
            break;
        }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
        case ICU_eMIOS_0:
        case ICU_eMIOS_1:
        {
            returnVal = Icu_eMios_Wrapper_GetOverflow(u16Icu_Channel, \
                sIcu_WrapperConfigPtr->Icu_eMoisConfig);
            break;
        }
#if (defined(RESOURCE_SUPPORT_ETPU))
        case ICU_eTPU_A:
        case ICU_eTPU_B:
        case ICU_eTPU_C:
        {
            returnVal = Icu_eTpu_Wrapper_GetOverflow(u16Icu_Channel, \
                sIcu_WrapperConfigPtr->Icu_eTpuConfig);
            break;
        }
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
    case ICU_CCU7_INS0:
    case ICU_CCU7_INS1:
    {
//        no support
//        returnVal = Icu_Ccu7_Wrapper_GetOverflow(u16Icu_Channel, sIcu_WrapperConfigPtr->Icu_Ccu7Config);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */

        default:
            /*nothing todo */
            break;
    }

    return returnVal;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#if (ICU_CAPTURERGISTER_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_ValueType, ICU_CODE) Icu_Autosar_Wrapper_GetCaptureRegisterValue \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_ValueType, ICU_CODE) returnVal = (boolean)FALSE;
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
        case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
        case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
        case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
        case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
        case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
        case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
        case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
        case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */	
        {
            returnVal = Icu_Gtm_Wrapper_GetCaptureRegisterValue(u16Icu_Channel, \
                sIcu_WrapperConfigPtr->Icu_GtmConfig);
            break;
        }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
        case ICU_eMIOS_0:
        case ICU_eMIOS_1:
        {
            returnVal = Icu_eMios_Wrapper_GetCaptureRegisterValue(u16Icu_Channel, \
                sIcu_WrapperConfigPtr->Icu_eMoisConfig);
            break;
        }
#if (defined(RESOURCE_SUPPORT_ETPU))
        case ICU_eTPU_A:
        case ICU_eTPU_B:
        case ICU_eTPU_C:
        {
            returnVal = Icu_eTpu_Wrapper_GetCaptureRegisterValue(u16Icu_Channel, \
                sIcu_WrapperConfigPtr->Icu_eTpuConfig);
            break;
        }
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
    case ICU_CCU7_INS0:
    case ICU_CCU7_INS1:
    {
//        returnVal = Icu_Ccu7_Wrapper_GetCaptureRegisterValue(u16Icu_Channel, sIcu_WrapperConfigPtr->Icu_Ccu7Config);
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
        default:
            /*nothing todo */
            break;
    }

    return returnVal;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(EcuM_WakeupSourceType, ICU_CODE) Icu_Autosar_Wrapper_GetWakeupSource \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(EcuM_WakeupSourceType, ICU_CODE) returnVal = 0U;
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
        case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
        case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
        case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
        case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
        case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
        case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
        case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
        case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */	
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */		
        case ICU_eMIOS_0:
        case ICU_eMIOS_1:
#if (defined(RESOURCE_SUPPORT_ETPU))		
        case ICU_eTPU_A:
        case ICU_eTPU_B:
        case ICU_eTPU_C:
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
		case ICU_CCU7_INS0:
    	case ICU_CCU7_INS1:	
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */		
        {
            returnVal = sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].sIcu_ChannelConfig.IcuChannel_WakeupValue;/* polyspace RTE:OBAI */
            break;
        }

        default:
            /*nothing todo */
            break;
    }

    return returnVal;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_REPORT_WAKEUP_SOURCE */

#if (ICU_STARTTIMESTAMP_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_TimestampBufferType, ICU_CODE) Icu_Autosar_Wrapper_GetTimestampBufferType \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_TimestampBufferType, ICU_CODE) returnVal = (Icu_TimestampBufferType)3U;  /* PRQA S 4342 */
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP *//* polyspace RTE:OBAI */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
        case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
        case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
        case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
        case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
        case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
        case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
        case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
        case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */	
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */		
        case ICU_eMIOS_0:
        case ICU_eMIOS_1:
#if (defined(RESOURCE_SUPPORT_ETPU))		
        case ICU_eTPU_A:
        case ICU_eTPU_B:
        case ICU_eTPU_C:
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
		case ICU_CCU7_INS0:
    	case ICU_CCU7_INS1:
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */		
        {
            returnVal = sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].sIcu_ChannelConfig.IcuChannel_TimestampBufferProperty;/* polyspace RTE:OBAI */
            break;
        }

        default:
            /*nothing todo */
            break;
    }

    return returnVal;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_STARTTIMESTAMP_API == STD_ON */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Std_ReturnType, ICU_CODE) Icu_Autosar_Wrapper_StartTimestampDMA \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;
    VAR(Std_ReturnType , AUTOMATIC) returnResult = (Std_ReturnType)E_NOT_OK;
    VAR(eDMATransferConfigType, AUTOMATIC) sIcu_DmaConfig;
    VAR(eDMALoopTransferConfigType, AUTOMATIC) sIcu_LoopTcdCfg;
    VAR(uint32, AUTOMATIC) u32sAddr = 0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP,OBAI */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
        case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
        case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
        case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
        case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
        case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
        case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
        case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
        case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */
        {
            u32sAddr = Icu_Gtm_Wrapper_GetStartAddress(u16Icu_Channel, \
                sIcu_WrapperConfigPtr->Icu_GtmConfig);
            break;
        }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
        case ICU_eMIOS_0:
        case ICU_eMIOS_1:
        {
            u32sAddr = Icu_eMios_Wrapper_GetStartAddress(u16Icu_Channel, \
                sIcu_WrapperConfigPtr->Icu_eMoisConfig);
            break;
        }
#if (defined(RESOURCE_SUPPORT_ETPU))
        case ICU_eTPU_A:
        case ICU_eTPU_B:
        case ICU_eTPU_C:
        {
            u32sAddr = Icu_eTpu_Wrapper_GetStartAddress(u16Icu_Channel, \
                sIcu_WrapperConfigPtr->Icu_eTpuConfig);
            break;
        }
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
        default:
            /*nothing todo */
            break;
    }

    if ((sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].u32Icu_ChannelBufferNotify) == 0U)/* polyspace RTE:OBAI */
    {
        sIcu_LoopTcdCfg.majorLpIterCnt       = sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].u32Icu_ChannelBufferSize;/* polyspace RTE:OBAI */
    }
    else
    {
        sIcu_LoopTcdCfg.majorLpIterCnt       = \
            (sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].u32Icu_ChannelBufferSize > sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].u32Icu_ChannelBufferNotify) ? /* polyspace RTE:OBAI */
            sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].u32Icu_ChannelBufferNotify : sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].u32Icu_ChannelBufferSize;/* polyspace RTE:OBAI */
    }

    sIcu_LoopTcdCfg.srcAddrOffsetEn      = (boolean)FALSE;
    sIcu_LoopTcdCfg.dstAddrOffsetEn      = (boolean)FALSE;
    sIcu_LoopTcdCfg.minorLpOffset        = (sint32)0;
    sIcu_LoopTcdCfg.minorLpLinkEn        = (boolean)FALSE;
    sIcu_LoopTcdCfg.minorLpLinkChn       = (uint8)0U;
    sIcu_LoopTcdCfg.majorLpLinkEn        = (boolean)FALSE;
    sIcu_LoopTcdCfg.majorLpLinkChn       = (uint8)0U;

    sIcu_DmaConfig.srcAddr               = u32sAddr;
    sIcu_DmaConfig.destAddr              = (uint32)sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].u32Icu_ChannelBuffer;
    sIcu_DmaConfig.srcTransDataSize      = EDMA_TRANSFER_SIZE_4B;
    sIcu_DmaConfig.destTransDataSize     = EDMA_TRANSFER_SIZE_4B;
    sIcu_DmaConfig.srcAddrOffset         = (sint16)0;
    sIcu_DmaConfig.destAddrOffset        = (sint16)sizeof(uint32);
    sIcu_DmaConfig.srcAddrAdjustLast     = (sint32)0;
    sIcu_DmaConfig.destAddrAdjustLast    = (sint32)(-(4 * sIcu_LoopTcdCfg.majorLpIterCnt));
    sIcu_DmaConfig.srcAddrModulo         = EDMA_ADDRESS_MODULO_4B;
    sIcu_DmaConfig.destAddrModulo        = EDMA_ADDRESS_MODULO_OFF;
    sIcu_DmaConfig.minorTransByte        = (4UL);
    sIcu_DmaConfig.featureScatterGatherEn= (boolean)FALSE;
    sIcu_DmaConfig.featureScatterGatherNextDescriptor   = 0U;
    sIcu_DmaConfig.completeIntEn         = (boolean)TRUE;
    sIcu_DmaConfig.lpTransConfigPtr      = &sIcu_LoopTcdCfg;

    returnResult = EDMA_SetLoopTransferConfig( \
        sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].sIcu_ChannelConfig.IcuChannel_DmaChannel, \
        &sIcu_DmaConfig);

    return returnResult;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Std_ReturnType, ICU_CODE) Icu_Autosar_Wrapper_StartSignalMeasurementDMA \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(ICU_HwModule_Type, AUTOMATIC) eModule;
    VAR(Std_ReturnType , AUTOMATIC) returnResult = (Std_ReturnType)E_NOT_OK;
    VAR(eDMATransferConfigType, AUTOMATIC) sIcu_DmaConfig;
    VAR(eDMALoopTransferConfigType, AUTOMATIC) sIcu_LoopTcdCfg;
    VAR(uint32, AUTOMATIC) u32sAddr = 0U;
    VAR(uint8, AUTOMATIC) u8Index = (uint8)0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    eModule = (*(sIcu_WrapperConfigPtr->Icu_HwChMap))[u16Icu_Channel];/* polyspace RTE:NIV,IDP,OBAI */
    switch (eModule)
    {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
#if defined(RESOURCE_SUPPORT_GTM_TIM0)
        case ICU_GTM_TIM0:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM0) */
#if defined(RESOURCE_SUPPORT_GTM_TIM1)
        case ICU_GTM_TIM1:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM1) */
#if defined(RESOURCE_SUPPORT_GTM_TIM2)	
        case ICU_GTM_TIM2:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM2) */
#if defined(RESOURCE_SUPPORT_GTM_TIM3)
        case ICU_GTM_TIM3:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM3) */
#if defined(RESOURCE_SUPPORT_GTM_TIM4)
        case ICU_GTM_TIM4:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM4) */
#if defined(RESOURCE_SUPPORT_GTM_TIM5)
        case ICU_GTM_TIM5:
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM5) */
#if defined(RESOURCE_SUPPORT_GTM_TIM6)
        case ICU_GTM_TIM6:   
#endif/* defined(RESOURCE_SUPPORT_GTM_TIM6) */ 
#if defined(RESOURCE_SUPPORT_GTM_TIM7)             
        case ICU_GTM_TIM7:              
#endif/* (defined(RESOURCE_SUPPORT_GTM_TIM7)) */	
        {
            u32sAddr = Icu_Gtm_Wrapper_GetStartAddress(u16Icu_Channel, \
                sIcu_WrapperConfigPtr->Icu_GtmConfig);
            break;
        }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
        case ICU_eMIOS_0:
        case ICU_eMIOS_1:
        {
            u32sAddr = Icu_eMios_Wrapper_GetStartAddress(u16Icu_Channel, \
                sIcu_WrapperConfigPtr->Icu_eMoisConfig);
            break;
        }
#if (defined(RESOURCE_SUPPORT_ETPU))
        case ICU_eTPU_A:
        case ICU_eTPU_B:
        case ICU_eTPU_C:
        {
            u32sAddr = Icu_eTpu_Wrapper_GetStartAddress(u16Icu_Channel, \
                sIcu_WrapperConfigPtr->Icu_eTpuConfig);
            break;
        }
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
        default:
            /*nothing todo */
            break;
    }

    sIcu_LoopTcdCfg.srcAddrOffsetEn      = (boolean)FALSE;
    sIcu_LoopTcdCfg.dstAddrOffsetEn      = (boolean)FALSE;
    sIcu_LoopTcdCfg.minorLpOffset        = (sint32)0;
    sIcu_LoopTcdCfg.minorLpLinkEn        = (boolean)FALSE;
    sIcu_LoopTcdCfg.minorLpLinkChn       = (uint8)0U;
    sIcu_LoopTcdCfg.majorLpLinkEn        = (boolean)FALSE;
    sIcu_LoopTcdCfg.majorLpLinkChn       = (uint8)0U;
    if((eModule == ICU_eMIOS_0)||(eModule == ICU_eMIOS_1))
    {
    	sIcu_LoopTcdCfg.majorLpIterCnt       = 2;
    }else if((eModule == ICU_GTM_TIM0)||(eModule == ICU_GTM_TIM1))
    {
    	sIcu_LoopTcdCfg.majorLpIterCnt       = 1;
    }else
    {

    }

    sIcu_DmaConfig.srcAddr               = u32sAddr;
    sIcu_DmaConfig.destAddr              = (uint32)gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer;
    sIcu_DmaConfig.srcTransDataSize      = EDMA_TRANSFER_SIZE_4B;
    sIcu_DmaConfig.destTransDataSize     = EDMA_TRANSFER_SIZE_4B;
    sIcu_DmaConfig.srcAddrOffset         = (sint16)sizeof(uint32);
    sIcu_DmaConfig.destAddrOffset        = (sint16)sizeof(uint32);
    sIcu_DmaConfig.srcAddrAdjustLast     = (sint32)0;
    if((eModule == ICU_eMIOS_0)||(eModule == ICU_eMIOS_1))
    {
    	sIcu_DmaConfig.destAddrAdjustLast    = (sint32)-16;
    }else if((eModule == ICU_GTM_TIM0)||(eModule == ICU_GTM_TIM1))
    {
    	sIcu_DmaConfig.destAddrAdjustLast    = (sint32)-8;
    }else
    {

    }
    sIcu_DmaConfig.srcAddrModulo         = EDMA_ADDRESS_MODULO_8B;
    sIcu_DmaConfig.destAddrModulo        = EDMA_ADDRESS_MODULO_OFF;
    sIcu_DmaConfig.minorTransByte        = (8UL);
    sIcu_DmaConfig.featureScatterGatherEn= (boolean)FALSE;
    sIcu_DmaConfig.featureScatterGatherNextDescriptor   = 0U;
    sIcu_DmaConfig.completeIntEn         = (boolean)FALSE;
    sIcu_DmaConfig.lpTransConfigPtr      = &sIcu_LoopTcdCfg;

    returnResult = EDMA_SetLoopTransferConfig( \
        sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].sIcu_ChannelConfig.IcuChannel_DmaChannel, /* polyspace RTE:OBAI */
        &sIcu_DmaConfig);

    for(u8Index = (uint8)0U; u8Index < (uint8)ICU_MEASUREMENT_LOOP; u8Index++)
    {
        gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer[u8Index] = 0UL;/* polyspace RTE:OBAI */
    }

    return returnResult;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void,ICU_CODE) Icu_Autosar_Wrapper_TimestampDmaProcess \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel \
)
{
    VAR(uint32,ICU_VAR) u8Icu_CoreId = GetCoreID();
    VAR (uint8, AUTOMATIC) u8DmaChannel =\
            sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].sIcu_ChannelConfig.IcuChannel_DmaChannel;/* polyspace RTE:OBAI */
    VAR (Icu_IndexType, AUTOMATIC) u32CrtIterCount = \
            (uint16)EDMA_GetChnRemainingIterationsCount(u8DmaChannel);
    VAR (uint32, AUTOMATIC) u32NoOfBufferElemToFill = 0U;
    P2VAR(Icu_ChannelInfoType, AUTOMATIC, ICU_CODE) pChannelInfo = &sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel];/* polyspace RTE:OBAI */

    pChannelInfo->u32Icu_ChannelBufferIndex = (Icu_IndexType)(pChannelInfo->u32Icu_ChannelBufferIndex + u32CrtIterCount);
    u32NoOfBufferElemToFill = (uint32)pChannelInfo->u32Icu_ChannelBufferSize - \
        pChannelInfo->u32Icu_ChannelBufferIndex;

    if ((Icu_IndexType)0 != pChannelInfo->u32Icu_ChannelBufferNotify)
    {
        pChannelInfo->u32Icu_ChannelBufferNotifyCount = (Icu_IndexType)(pChannelInfo->u32Icu_ChannelBufferNotifyCount + u32CrtIterCount);
        if (pChannelInfo->u32Icu_ChannelBufferNotifyCount == \
            pChannelInfo->u32Icu_ChannelBufferNotify)
        {
            pChannelInfo->u32Icu_ChannelBufferNotifyCount = 0U;
            /* Call User Notification Function and/or Wakeup Function */
            if (pChannelInfo->sIcu_ChannelConfig.IcuChannel_TimestampNotification != NULL_PTR)
            {
                pChannelInfo->sIcu_ChannelConfig.IcuChannel_TimestampNotification();/* polyspace RTE:COR */
            }
        }
    }

    if (0U == u32NoOfBufferElemToFill)
    {
        if (ICU_CIRCULAR_BUFFER ==  \
            pChannelInfo->sIcu_ChannelConfig.IcuChannel_TimestampBufferProperty \
        )
        {
            /* restart, continue dma */
            pChannelInfo->u32Icu_ChannelBufferIndex = 0U;
            EDMA_SetChnDestAddr(u8DmaChannel, (uint32)pChannelInfo->u32Icu_ChannelBuffer);

            if ((pChannelInfo->u32Icu_ChannelBufferSize > (pChannelInfo->u32Icu_ChannelBufferNotify - pChannelInfo->u32Icu_ChannelBufferNotifyCount)) &&
                ((Icu_IndexType)0 != pChannelInfo->u32Icu_ChannelBufferNotify))
            {
                EDMA_SetChnMajorLpIterationCount(u8DmaChannel, \
                    (uint32)pChannelInfo->u32Icu_ChannelBufferNotify - pChannelInfo->u32Icu_ChannelBufferNotifyCount);
            }
        }
        else
        {
#if (ICU_STOPTIMESTAMP_API == STD_ON)
            Icu_StopTimestamp(u16Icu_Channel);
#endif
            Icu_SetChannelState(u16Icu_Channel, ICU_CHANNEL_STATE_IDLE);
        }
    }
    else
    {
        if (u32CrtIterCount < pChannelInfo->u32Icu_ChannelBufferNotify)
        {
            EDMA_SetChnMajorLpIterationCount(u8DmaChannel, pChannelInfo->u32Icu_ChannelBufferNotify);
        }

        if (u32NoOfBufferElemToFill < pChannelInfo->u32Icu_ChannelBufferNotify)
        {
            EDMA_SetChnMajorLpIterationCount(u8DmaChannel, u32NoOfBufferElemToFill);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void,ICU_CODE) Icu_Autosar_Wrapper_SignalMeasurementDmaProcess \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel \
)
{
    VAR(Icu_ValueType,      AUTOMATIC) BufferValue1;
    VAR(Icu_ValueType,      AUTOMATIC) BufferValue2;
    VAR(Icu_ValueType,      AUTOMATIC) BufferValue3;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();
    VAR(Icu_ActivationType, AUTOMATIC) eActivation = ICU_BOTH_EDGES;
    VAR(uint8,              AUTOMATIC) u8DmaChannel = \
        sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].sIcu_ChannelConfig.IcuChannel_DmaChannel;/* polyspace RTE:OBAI */
    P2VAR(Icu_ChannelInfoType, AUTOMATIC, ICU_CODE) pChannelInfo = &sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel];/* polyspace RTE:OBAI */

    (void)EDMA_ClearChannelRequest(u8DmaChannel);
    sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].u32Icu_ChannelEdgeDetection = ICU_ACTIVE;

    if (1UL == gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aIsSecondInterrupt)/* polyspace RTE:OBAI */
    {
        BufferValue1 = gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aFirstEdgeTimeStamp;
        BufferValue2 = gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer[0];
        BufferValue3 = gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer[1];

        EDMA_SetChnDestAddr(u8DmaChannel, (uint32)gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer);
        (void)EDMA_SetChannelRequest(u8DmaChannel);

        if (BufferValue2 > BufferValue1)
        {
            pChannelInfo->u32Icu_ChannelActiveTime = BufferValue2 - BufferValue1;
        }
        else
        {
            pChannelInfo->u32Icu_ChannelActiveTime = (ICU_CAPTURE_REGISTER_MASK - BufferValue1) + BufferValue2;
        }

        if(BufferValue3 > BufferValue1)
        {
            pChannelInfo->u32Icu_ChannelPeriod = BufferValue3 - BufferValue1;
        }
        else
        {
            pChannelInfo->u32Icu_ChannelPeriod = (ICU_CAPTURE_REGISTER_MASK - BufferValue1) + BufferValue3;
        }

        gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aFirstEdgeTimeStamp = \
            gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer[1];
    }
    else
    {
        gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aIsSecondInterrupt = 1UL;
        gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aFirstEdgeTimeStamp = \
            gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer[0];

        EDMA_SetChnDestAddr(u8DmaChannel, (uint32)gIcu_MeasurementInfo[u8Icu_CoreId][u16Icu_Channel].Icu_aDmaBuffer);
        EDMA_SetChnMajorLpIterationCount(u8DmaChannel, ICU_MEASUREMENT_LOOP);
        (void)EDMA_SetChannelRequest(u8DmaChannel);

        Icu_Autosar_Wrapper_SetActivationCondition(u16Icu_Channel, \
            eActivation, \
            pChannelInfo->sIcu_ChannelConfig.IcuConfig_ChannelMode, \
            sIcu_CfgPtr[u8Icu_CoreId]);
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


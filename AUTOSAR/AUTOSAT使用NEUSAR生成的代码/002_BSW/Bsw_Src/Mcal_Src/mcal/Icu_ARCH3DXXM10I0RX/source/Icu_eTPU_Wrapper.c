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
*   @file    Icu_eTPU_Wrapper.c
*   @version 3.0.0 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/* PRQA S 0380, 1006, 4461, 4491, 4499 EOF */
/* PRQA S 2844, 4342, 0491, 1863 EOF */
/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif
#include "Icu.h"
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "Icu_eTPU_Wrapper.h"
#include "Icu_eTPU_HAL_Wrapper.h"
#include "eDMA.h"

/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_ETPU_WRAPPER_VENDOR_ID_C                   176

#define ICU_ETPU_WRAPPER_MAJOR_VER_C                   4
#define ICU_ETPU_WRAPPER_MINOR_VER_C                   4
#define ICU_ETPU_WRAPPER_REVISION_VER_C                0

#define ICU_ETPU_WRAPPER_SW_MAJOR_VER_C                3
#define ICU_ETPU_WRAPPER_SW_MINOR_VER_C                0
#define ICU_ETPU_WRAPPER_SW_PATCH_VER_C                0

#if (ICU_ETPU_WRAPPER_VENDOR_ID_C != ICU_ETPU_WRAPPER_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_ETPU_WRAPPER_MAJOR_VER_C != ICU_ETPU_WRAPPER_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_ETPU_WRAPPER_MINOR_VER_C != ICU_ETPU_WRAPPER_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_ETPU_WRAPPER_REVISION_VER_C != ICU_ETPU_WRAPPER_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_ETPU_WRAPPER_SW_MAJOR_VER_C != ICU_ETPU_WRAPPER_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_ETPU_WRAPPER_SW_MINOR_VER_C != ICU_ETPU_WRAPPER_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_ETPU_WRAPPER_SW_PATCH_VER_C != ICU_ETPU_WRAPPER_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
/**
* ICU global config parameter
*/
extern P2CONST(Icu_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_CfgPtr[ICU_CORE_NUM];
extern VAR(Icu_ChannelInfoType, AUTOMATIC) sIcu_ChannelInfo[ICU_CORE_NUM][ICU_MAX_CHANNEL];

/**
* eTPU module channel map with Icu channel
*/
#define ICU_START_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"
static VAR(uint16, ICU_VAR) sIcu_eTpu_ChannelMap[ETPU_MODULE_MAX*ETPU_CHANEEL_MAX];
#define ICU_STOP_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_ChannelType, ICU_CODE) Icu_eTpu_Wrapper_GetInstance \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
)
{
    VAR(Icu_ChannelType,    ICU_VAR) nInstance = (Icu_ChannelType)ICU_INVALID_INSTANCE;

#if (ICU_ETPU_CHANNEL_MAP == STD_OFF)
    P2CONST(ICU_eTPU_Config, ICU_VAR,  ICU_APPL_DATA) peTpuConfig = sIcu_CfgPtr[GetCoreID()]->Icu_eTpuConfig;
    P2CONST(ICU_eTPU_ChannelConfig, ICU_VAR,  ICU_APPL_DATA) pChannelConfig = peTpuConfig->peTpuChannelConfig;
    VAR(Icu_ChannelType,    ICU_VAR) nChannel = (Icu_ChannelType)0U;

    for (nChannel = (Icu_ChannelType)0U; nChannel < peTpuConfig->uChannelCount; nChannel++)
    {
        if (u8Module == (uint8)pChannelConfig->IcuConfig_ModuleId &&
            u8Channel == (uint8)pChannelConfig->IcuConfig_ChannelId)
        {
            nInstance = (Icu_ChannelType)pChannelConfig->IcuConfig_Instance;
            break;
        }

        pChannelConfig ++;
    }
#else
    nInstance = sIcu_eTpu_ChannelMap[ETPU_MODU_CHAN_COMBIN(u8Module, u8Channel)];/* polyspace RTE:OBAI */
#endif /* ICU_ETPU_CHANNEL_MAP == STD_OFF */
    return nInstance;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_eTpu_Wrapper_Init \
( \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(eTPU_Channel_Config, AUTOMATIC) sChannelConfig;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)

    VAR(uint8,ICU_VAR) u8Icu_CoreId = GetCoreID();
    VAR(uint32, AUTOMATIC) u32CurrentCoreId = Icu_GetCoreID(); /* polyspace RTE:OVFL,SHF */
    VAR(uint8,  AUTOMATIC) u8CoreIdMask;
    VAR(Icu_IndexType, AUTOMATIC) nInstance;
#endif

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:IDP,NIV */
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;/* polyspace RTE:NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:IDP,NIV */
        u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */

        sChannelConfig.sChannelParam.priority   = (uint8)psChannelConfig[u16ChannelIndex].pIcuConfig_HwConfig->priority;/* polyspace RTE:IDP,NIV,NIP */
        sChannelConfig.sChannelParam.timebase   = (uint8)psChannelConfig[u16ChannelIndex].pIcuConfig_HwConfig->timebase;/* polyspace RTE:NIV */
        sChannelConfig.sChannelParam.edge       = (uint8)psChannelConfig[u16ChannelIndex].IcuChannel_DefaultStartEdge;;/* polyspace RTE:NIV */
        sChannelConfig.sChannelParam.mode       = (uint8)psChannelConfig[u16ChannelIndex].pIcuConfig_HwConfig->mode;/* polyspace RTE:NIV */
        sChannelConfig.bDmaSupport              = psChannelConfig[u16ChannelIndex].IcuChannel_bDmaSupport;/* polyspace RTE:NIV */

#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
        nInstance = psChannelConfig[u16ChannelIndex].IcuConfig_Instance; /* polyspace RTE:NIV */
        u8CoreIdMask= (uint8)u32CurrentCoreId & sIcu_CfgPtr[u8Icu_CoreId]->Icu_CoreMap[nInstance].nCoreId; /* polyspace RTE:OBAI,NIV,IDP */
        if(u8CoreIdMask != 0)
        {
            sIcu_u8Hw2LogicChannelMap[u8Icu_CoreId][nInstance] = ICU_CHN_USED; /* polyspace RTE:OBAI */
#endif /* ICU_MULTI_CORE_SUPPORT == STD_ON */
        eTpu_Channel_Init(u8ModuleId, (uint8)u8IChannelId, &sChannelConfig);
        eTpu_Channel_ConfigInit(u8ModuleId, (uint8)u8IChannelId, &sChannelConfig);
        sIcu_eTpu_ChannelMap[ETPU_MODU_CHAN_COMBIN(u8ModuleId, (uint8)u8IChannelId)] = (uint16)psChannelConfig[u16ChannelIndex].IcuConfig_Instance;/* polyspace RTE:OBAI,NIV */
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
        }
#endif /* ICU_MULTI_CORE_SUPPORT == STD_ON */

        
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_eTpu_Wrapper_DeInit \
( \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CurrentCoreId = Icu_GetCoreID(); /* polyspace RTE:OVFL,SHF */
    VAR(uint8,  AUTOMATIC) u8CoreIdMask;
    VAR(Icu_IndexType, AUTOMATIC) nInstance;
#endif
    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
#if(ICU_MULTI_CORE_SUPPORT == STD_ON)
                nInstance = psChannelConfig[u16ChannelIndex].IcuConfig_Instance; /* polyspace RTE:NIV,IDP */
                u8CoreIdMask= (uint8)u32CurrentCoreId & sIcu_CfgPtr[u32CurrentCoreId >> 1U]->Icu_CoreMap[nInstance].nCoreId; /* polyspace RTE:OBAI,NIV,IDP */
                if(u8CoreIdMask != 0)
                {
                	sIcu_u8Hw2LogicChannelMap[u32CurrentCoreId >> 1U][nInstance] = ICU_CHN_UNUSED; /* polyspace RTE:OBAI */
#endif
        u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV,IDP */
        u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */

        eTpu_Channel_DeInit(u8ModuleId, (uint8)u8IChannelId);
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
                }
#endif /* ICU_MULTI_CORE_SUPPORT == STD_ON */
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eTpu_Wrapper_IrqConfig
(
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr, \
    VAR(boolean,                 AUTOMATIC) IsEnable
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CurrentCoreId = Icu_GetCoreID(); /* polyspace RTE:OVFL,SHF */
    VAR(uint8,  AUTOMATIC) u8CoreIdMask;
    VAR(Icu_IndexType, AUTOMATIC) nInstance;
#endif
    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
#if(ICU_MULTI_CORE_SUPPORT == STD_ON)
                nInstance = psChannelConfig[u16ChannelIndex].IcuConfig_Instance; /* polyspace RTE:NIV,IDP */
                u8CoreIdMask= (uint8)u32CurrentCoreId & sIcu_CfgPtr[u32CurrentCoreId >> 1U]->Icu_CoreMap[nInstance].nCoreId; /* polyspace RTE:OBAI,NIV,IDP */
                if(u8CoreIdMask != 0)
                {
                	if (sIcu_u8Hw2LogicChannelMap[u32CurrentCoreId >> 1U][nInstance] == ICU_CHN_USED) /* polyspace RTE:OBAI */
                	{
#endif
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */

            if (IsEnable == TRUE)
            {
                eTpu_Channel_EnIrq(u8ModuleId, (uint8)u8IChannelId);
            }
            else
            {
                eTpu_Channel_DisIrq(u8ModuleId, (uint8)u8IChannelId);
            }
            break;
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
                	}
                }
#endif /* ICU_MULTI_CORE_SUPPORT == STD_ON */
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eTpu_Wrapper_SetActivationCondition \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    VAR(Icu_ActivationType,              AUTOMATIC) eActivation, \
    VAR(Icu_MeasurementModeType,         AUTOMATIC) eMode, \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
    (void)eMode;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            switch(eActivation)
            {
            case ICU_FALLING_EDGE:
            {
                eTpu_Channel_SetActivationCondition(u8ModuleId, (uint8)u8IChannelId, (eTPU_EdgeTrigModeType)ETPU_IC_FALLING_EDGE);
                break;
            }
            case ICU_RISING_EDGE:
            {
                eTpu_Channel_SetActivationCondition(u8ModuleId, (uint8)u8IChannelId, (eTPU_EdgeTrigModeType)ETPU_IC_RISING_EDGE);
                break;
            }
            case ICU_BOTH_EDGES:
            {
                eTpu_Channel_SetActivationCondition(u8ModuleId, (uint8)u8IChannelId, (eTPU_EdgeTrigModeType)ETPU_IC_ANY_EDGE);
                break;
            }
            default:
                /* do nothing */
                break;
            }
            /* break loop for ... */
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (Icu_InputStateType, ICU_CODE) Icu_eTpu_Wrapper_GetInputState \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
    VAR(Icu_InputStateType, AUTOMATIC) eReturn = ICU_IDLE;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;
            if((boolean)TRUE == eTpu_Channel_GetInputLevel(u8ModuleId, (uint8)u8IChannelId))
            {
                eReturn = ICU_ACTIVE;
            }
            break;
        }
    }

    return eReturn;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eTpu_Wrapper_EnableEdgeDetection \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eTPU_ConfigType,  ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            eTpu_Channel_EnableEdgeDetection(u8ModuleId, (uint8)u8IChannelId);
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eTpu_Wrapper_DisableEdgeDetection \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            eTpu_Channel_DisableEdgeDetection(u8ModuleId, (uint8)u8IChannelId);
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_STARTSIGNALMEASUREMENT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC (uint32, ICU_CODE) Icu_eTpu_Wrapper_GetSignalMeasurement \
( \
    VAR(Icu_SignalMeasurementPropertyType, AUTOMATIC) meas \
)
{
    VAR(uint32, ICU_VAR) u32Return;

    if (ICU_LOW_TIME == meas)
    {
    	u32Return = ETPU_MEAS_TYPE_LOW_TIME;
    }
    else if (ICU_HIGH_TIME == meas)
    {
    	u32Return = ETPU_MEAS_TYPE_HIGH_TIME;
    }
    else if (ICU_PERIOD_TIME == meas)
    {
    	u32Return = ETPU_MEAS_TYPE_PERIOD_TIME;
    }
    else
    {
    	u32Return = ETPU_MEAS_TYPE_DUTY_CYCLE;
    }

    return u32Return;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eTpu_Wrapper_StartSignalMeasurement \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    VAR(uint32,                          AUTOMATIC) u32StartEdge, \
    VAR(uint16,                          AUTOMATIC) u16MeasProperty, \
    VAR(boolean,                         AUTOMATIC) bDmaSupport, \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
    VAR(boolean, AUTOMATIC) bWithoutInterrupt = (boolean)FALSE;
    VAR(eTPU_EdgeTrigModeType,   AUTOMATIC) eActivation;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            bWithoutInterrupt = (boolean)psChannelConfig[u16ChannelIndex].IcuChannel_bSignalMeasureWithoutInterrupt;/* polyspace RTE:NIV */

            if((u32StartEdge != (uint32)ICU_FALLING_EDGE) && (u32StartEdge != (uint32)ICU_RISING_EDGE) && \
                    (u32StartEdge != (uint32)ICU_BOTH_EDGES))
            {
                u32StartEdge = (uint32)psChannelConfig[u16ChannelIndex].IcuChannel_DefaultStartEdge;/* polyspace RTE:NIV */
            }
            if((u16MeasProperty != (uint16)ICU_LOW_TIME) && (u16MeasProperty != (uint16)ICU_HIGH_TIME) && \
                    (u16MeasProperty != (uint16)ICU_PERIOD_TIME) && (u16MeasProperty != (uint16)ICU_DUTY_CYCLE))
            {
                u16MeasProperty = (uint16)Icu_eTpu_Wrapper_GetSignalMeasurement(
                    psChannelConfig[u16ChannelIndex].IcuChannel_SignalMeasurementProperty);/* polyspace RTE:NIV */
            }
            else
            {
                u16MeasProperty =(uint16) Icu_eTpu_Wrapper_GetSignalMeasurement((Icu_SignalMeasurementPropertyType)u16MeasProperty);
            }

            if (u32StartEdge == (uint32)ICU_FALLING_EDGE)
            {
                eActivation = (eTPU_EdgeTrigModeType)ETPU_IC_FALLING_EDGE;
            }
            else if (u32StartEdge == (uint32)ICU_RISING_EDGE)
            {
                eActivation = (eTPU_EdgeTrigModeType)ETPU_IC_RISING_EDGE;
            }
            else
            {
                eActivation = (eTPU_EdgeTrigModeType)ETPU_IC_ANY_EDGE;
            }

            eTpu_Channel_StartSignalMeasurement(u8ModuleId, \
                (uint8)u8IChannelId,       \
                (eTPU_EdgeTrigModeType)eActivation,        \
                (uint16)u16MeasProperty,    \
                bDmaSupport,        \
                bWithoutInterrupt   \
                );
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eTpu_Wrapper_StopSignalMeasurement \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,NIP,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            eTpu_Channel_StopSignalMeasurement(u8ModuleId, (uint8)u8IChannelId);
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_STARTSIGNALMEASUREMENT_API */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (uint32, ICU_CODE) Icu_eTpu_Wrapper_GetStartAddress \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type, AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
    VAR(uint32,          AUTOMATIC) u32ReturnValue = 0U;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            u32ReturnValue = eTpu_Channel_GetStartAddress(u8ModuleId, (uint8)u8IChannelId);
            break;
        }
    }

    return u32ReturnValue;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_STARTTIMESTAMP_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eTpu_Wrapper_StartTimestamp \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    VAR(boolean,                         AUTOMATIC) bDmaSupport, \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,NIP,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            eTpu_Channel_StartTimestamp(u8ModuleId, (uint8)u8IChannelId, bDmaSupport);
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eTpu_Wrapper_StopTimestamp \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,NIP,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            eTpu_Channel_StopTimestamp(u8ModuleId, (uint8)u8IChannelId);
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_STARTTIMESTAMP_API */

#if (ICU_ENABLEEDGECOUNT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eTpu_Wrapper_ResetEdgeCount \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            eTpu_Channel_ResetEdgeCount(u8ModuleId, (uint8)u8IChannelId);
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eTpu_Wrapper_EnableEdgeCount \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            eTpu_Channel_EnableEdgeCount(u8ModuleId, (uint8)u8IChannelId);
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eTpu_Wrapper_DisableEdgeCount \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            eTpu_Channel_DisableEdgeCount(u8ModuleId, (uint8)u8IChannelId);
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (uint32, ICU_CODE) Icu_eTpu_Wrapper_GetEdgeNumbers \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
    VAR(uint32, AUTOMATIC) u32EdgeNumber = 0UL;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            u32EdgeNumber = eTpu_Channel_GetEdgeNumbers(u8ModuleId, (uint8)u8IChannelId);
            break;
        }
    }

    return u32EdgeNumber;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_ENABLEEDGECOUNT_API */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (boolean, ICU_CODE) Icu_eTpu_Wrapper_GetOverflow \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
    VAR(boolean,         AUTOMATIC) bReturnOverflow = (boolean)FALSE;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;/* polyspace RTE:NIV,NIP */
    /* GetCoreID */
    if(sIcu_ChannelInfo[GetCoreID()][nChannel].sIcu_ChannelConfig.IcuConfig_ChannelMode == ICU_MODE_SIGNAL_MEASUREMENT)/* polyspace RTE:OBAI */
    {
        for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
        {
            if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
            {
                u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
                u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
                bReturnOverflow = eTpu_Channel_GetOverflow(u8ModuleId, (uint8)u8IChannelId);
                break;
            }
        }
    }
    return bReturnOverflow;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (Icu_LevelType, ICU_CODE) Icu_eTpu_Wrapper_GetInputLevel \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
    VAR(Icu_LevelType,   AUTOMATIC) eReturnInputLevel = ICU_LEVEL_LOW;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */

            if((boolean)TRUE == eTpu_Channel_GetInputLevel(u8ModuleId, (uint8)u8IChannelId))
            {
                eReturnInputLevel = ICU_LEVEL_HIGH;
            }
            else
            {
                eReturnInputLevel = ICU_LEVEL_LOW;
            }

            break;
        }
    }

    return eReturnInputLevel;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_ValueType, ICU_CODE) Icu_eTpu_Wrapper_GetTimeElapsed \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ValueType, AUTOMATIC) returnValue = 0UL;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            if (psChannelConfig[u16ChannelIndex].IcuChannel_SignalMeasurementProperty == ICU_PERIOD_TIME)/* polyspace RTE:NIV */
            {
                returnValue = sIcu_ChannelInfo[u8Icu_CoreId][nChannel].u32Icu_ChannelPeriod;/* polyspace RTE:OBAI */
                sIcu_ChannelInfo[u8Icu_CoreId][nChannel].u32Icu_ChannelPeriod = 0UL;/* polyspace RTE:OBAI */
            }
            else
            {
                returnValue = sIcu_ChannelInfo[u8Icu_CoreId][nChannel].u32Icu_ChannelActiveTime;/* polyspace RTE:OBAI */
                sIcu_ChannelInfo[u8Icu_CoreId][nChannel].u32Icu_ChannelActiveTime = 0UL;/* polyspace RTE:OBAI */
            }

            Icu_ClearChannelState(nChannel, ICU_CHANNEL_STATE_IDLE);
            break;
        }
    }

    return returnValue;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(EcuM_WakeupSourceType, ICU_CODE) Icu_eTpu_Wrapper_GetWakeupSource \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(EcuM_WakeupSourceType, AUTOMATIC) returnValue = 0xFFFFFUL;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)
        {
            returnValue = psChannelConfig[u16ChannelIndex].IcuChannel_WakeupValue;
            break;
        }
    }

    return returnValue;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_REPORT_WAKEUP_SOURCE */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_TimestampBufferType, ICU_CODE) Icu_eTpu_Wrapper_GetTimestampBufferType \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_TimestampBufferType, AUTOMATIC) returnValue = (Icu_TimestampBufferType)0xFFFFFU;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)
        {
            returnValue = psChannelConfig[u16ChannelIndex].IcuChannel_TimestampBufferProperty;
            break;
        }
    }

    return returnValue;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (Icu_ValueType, ICU_CODE) Icu_eTpu_Wrapper_GetCaptureRegisterValue \
( \
    VAR(Icu_ChannelType,                AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eTPU_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_eTPU_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
    VAR(Icu_ValueType,   AUTOMATIC) ReturnInputLevel = 0UL;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;
    psChannelConfig = sIcu_WrapperConfigPtr->peTpuChannelConfig;

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;

            ReturnInputLevel = eTpu_Channel_GetFinalTime(u8ModuleId, (uint8)u8IChannelId);

            break;
        }
    }

    return ReturnInputLevel;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_ETPU)) */
#ifdef __cplusplus
}
#endif



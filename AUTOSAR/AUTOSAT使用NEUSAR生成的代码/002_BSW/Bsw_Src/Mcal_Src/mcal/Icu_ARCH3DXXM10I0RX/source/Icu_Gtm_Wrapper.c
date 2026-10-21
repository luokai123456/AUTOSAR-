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
/* PRQA S 2053, 2976 EOF */    /* QAC_CWE */
/**
*   @file    Icu_Gtm_Wrapper.c
*   @version 3.0.0 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/* PRQA S 3432, 0380, 1006, 1863, 4499 EOF */
/* PRQA S 2844, 0491, 4342, 0498, 4399, 4391 EOF */
/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif
#include "Icu.h"
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
#include "Icu_Gtm_Wrapper.h"
#include "Icu_Cfg.h"
#include "Gpt_Gtm_LLDriver.h"
#include "Icu_Gtm_HAL_Wrapper.h"

/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_GTM_WRAPPER_VENDOR_ID_C                   176

#define ICU_GTM_WRAPPER_MAJOR_VER_C                   4
#define ICU_GTM_WRAPPER_MINOR_VER_C                   4
#define ICU_GTM_WRAPPER_REVISION_VER_C                0

#define ICU_GTM_WRAPPER_SW_MAJOR_VER_C                3
#define ICU_GTM_WRAPPER_SW_MINOR_VER_C                0
#define ICU_GTM_WRAPPER_SW_PATCH_VER_C                0

#if (ICU_GTM_WRAPPER_VENDOR_ID_C != ICU_GTM_WRAPPER_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_GTM_WRAPPER_MAJOR_VER_C != ICU_GTM_WRAPPER_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_GTM_WRAPPER_MINOR_VER_C != ICU_GTM_WRAPPER_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_GTM_WRAPPER_REVISION_VER_C != ICU_GTM_WRAPPER_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_GTM_WRAPPER_SW_MAJOR_VER_C != ICU_GTM_WRAPPER_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_GTM_WRAPPER_SW_MINOR_VER_C != ICU_GTM_WRAPPER_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_GTM_WRAPPER_SW_PATCH_VER_C != ICU_GTM_WRAPPER_SW_PATCH_VER_H)
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
* GTM module channel map with Icu channel
*/
#define ICU_START_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"
static VAR(uint16, ICU_VAR) sIcu_Gtm_ChannelMap[ICU_CORE_NUM][ICU_GTM_MODULE_MAX*ICU_GTM_CHANNEL_MAX];
#define ICU_STOP_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_ChannelType, ICU_CODE) Icu_Gtm_Wrapper_GetInstance \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
)
{
    VAR(Icu_ChannelType,    ICU_VAR) nInstance = (Icu_ChannelType)ICU_INVALID_INSTANCE;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

#if (ICU_GTM_CHANNEL_MAP == STD_OFF)
    P2CONST(ICU_Gtm_Config, ICU_VAR, ICU_APPL_DATA) pGtmConfig = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig;
    P2CONST(Icu_ChannelConfig_Type, ICU_VAR, ICU_APPL_DATA) pChannelConfig = pGtmConfig->pGtmChannelConfig;
    VAR(Icu_ChannelType,    ICU_VAR) nChannel = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType,    ICU_VAR) nChannelCounter;

    nChannelCounter = pGtmConfig->uChannelCount;

    for (nChannel = (Icu_ChannelType)0U; nChannel < nChannelCounter; nChannel++)
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
    nInstance = sIcu_Gtm_ChannelMap[u8Icu_CoreId][ICU_GTM_MODU_CHAN_COMBIN(u8Module, u8Channel)];/* polyspace RTE:OBAI */
#endif /* (ICU_GTM_CHANNEL_MAP == STD_OFF) */
    return nInstance;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC(Icu_ChannelType, ICU_CODE) Icu_Gtm_Wrapper_GetIndex \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber \
)
{
    P2CONST(ICU_Gtm_Config, ICU_VAR, ICU_APPL_DATA) pGtmConfig = sIcu_CfgPtr[GetCoreID()]->Icu_GtmConfig;/* polyspace RTE:OBAI,IDP */
    P2CONST(Icu_ChannelConfig_Type, ICU_VAR, ICU_APPL_DATA) pChannelConfig = pGtmConfig->pGtmChannelConfig;/* polyspace RTE:NIP,IDP */
    VAR(Icu_ChannelType,    ICU_VAR) nChannel = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType,    ICU_VAR) nIndex = (Icu_ChannelType)ICU_INVALID_INSTANCE;
    VAR(Icu_ChannelType,    ICU_VAR) nChannelCounter;

    nChannelCounter = pGtmConfig->uChannelCount;/* polyspace RTE:NIV */

    for (nChannel = (Icu_ChannelType)0U; nChannel < nChannelCounter; nChannel++)
    {
        if (pChannelConfig->IcuConfig_Instance == (Icu_ChannelType)u16Icu_ChannelNumber)/* polyspace RTE:NIV,IDP */
        {
            nIndex = nChannel;
            break;
        }

        pChannelConfig ++;
    }

    return nIndex;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_Init \
( \
    P2CONST(struct ICU_Gtm_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(Icu_ChannelConfig_Type, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Gtm_Channel_Config, AUTOMATIC) sChannelConfig;
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelIndex = 0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelId = 0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8Icu_ModuleId = 0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Gtm_ChNum = 0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
    VAR(uint8, AUTOMATIC) u32CurrentCoreId = Icu_GetCoreID();/* polyspace RTE:SHF,OVFL */
    VAR(uint8,  AUTOMATIC) u8CoreIdMask;
    VAR(Icu_IndexType, AUTOMATIC) nInstance;
#endif

    u16Icu_Gtm_ChNum = sIcu_WrapperConfigPtr->uChannelCount;
    if (NULL_PTR != sIcu_WrapperConfigPtr->pGtmChannelConfig)/* polyspace RTE:NIP,IDP */
    {
        psChannelConfig = sIcu_WrapperConfigPtr->pGtmChannelConfig;
        for(u8Icu_ChannelIndex = 0;u8Icu_ChannelIndex < u16Icu_Gtm_ChNum;u8Icu_ChannelIndex++)
        {
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
            nInstance = psChannelConfig[u8Icu_ChannelIndex].IcuConfig_Instance;
            u8CoreIdMask= u32CurrentCoreId & sIcu_CfgPtr[u8Icu_CoreId]->Icu_CoreMap[nInstance].nCoreId;/* polyspace RTE:OBAI,NIV,IDP*/
            if(u8CoreIdMask != 0)
            {
                sIcu_u8Hw2LogicChannelMap[u8Icu_CoreId][nInstance] = ICU_CHN_USED;/* polyspace RTE:OBAI */
#endif /* ICU_MULTI_CORE_SUPPORT == STD_ON */

            u8Icu_ModuleId = (Icu_Module_Type)psChannelConfig[u8Icu_ChannelIndex].IcuConfig_ModuleId;
            u8Icu_ChannelId = (Icu_ChannelType)psChannelConfig[u8Icu_ChannelIndex].IcuConfig_ChannelId;
            if (psChannelConfig[u8Icu_ChannelIndex].IcuConfig_ChannelMode == ICU_MODE_SIGNAL_MEASUREMENT)
            {
                sChannelConfig.GPRInput                 = CNT;
                sChannelConfig.timMode                  = TIM_MODE_TPWM;
            }
            else if (psChannelConfig[u8Icu_ChannelIndex].IcuConfig_ChannelMode == ICU_MODE_TIMESTAMP)
            {
                sChannelConfig.GPRInput                 = TBU_TS0;
                sChannelConfig.timMode                  = TIM_MODE_TIEM;
            }
            else
            {
                sChannelConfig.GPRInput                 = CNT;
                sChannelConfig.timMode                  = TIM_MODE_TIEM;
            }
            sChannelConfig.TBU0Input                = (uint8)TBU_TS0_23_0;
            sChannelConfig.clockSource              = (GTM_TIM_CLK_SEL_Type)TIM_CLK_SEL_CMU_CLK0;
            sChannelConfig.fallCounterFilterMode    = TIM_Hold_Counter;
            sChannelConfig.riseCounterFilterMode    = TIM_Hold_Counter;
            sChannelConfig.fallEdgeFilterMode       = TIM_Individual_Glitch;
            sChannelConfig.riseEdgeFilterMode       = TIM_Individual_Glitch;
            sChannelConfig.filterEnable             = (boolean)TRUE;
            sChannelConfig.startEdge                = (GTM_TIM_Edge_Type)psChannelConfig[u8Icu_ChannelIndex].IcuChannel_DefaultStartEdge; /* PRQA S 4322 */
            sChannelConfig.filterParamFallEdge      = 10;
            sChannelConfig.filterParamRiseEdge      = 10;
            sChannelConfig.filterCounterFrequency   = TIM_FLT_CNT_FRQ_CMU_CLK0;
#ifdef RESOURCE_SUPPORT_GTM_TIMINPUTSEL
            (void)GTM_LLD_SetTimsel((GTM_TIM_Type)u8Icu_ModuleId, (GTM_TIM_Channel_Type)u8Icu_ChannelId, (GTM_TIM_Channel_Input_Selection_Type)psChannelConfig[u8Icu_ChannelIndex].IcuConfig_Tim_Selection);
#endif/* RESOURCE_SUPPORT_GTM_TIMINPUTSEL  */
            Icu_Wrapper_Init(u8Icu_ModuleId,u8Icu_ChannelId, &sChannelConfig);
            Icu_Wrapper_ConfigInit(u8Icu_ModuleId,u8Icu_ChannelId, &sChannelConfig);
            sIcu_Gtm_ChannelMap[u8Icu_CoreId][ICU_GTM_MODU_CHAN_COMBIN(u8Icu_ModuleId, (uint8)u8Icu_ChannelId)] = /* polyspace RTE:OBAI */
                (uint16)psChannelConfig[u8Icu_ChannelIndex].IcuConfig_Instance;/* polyspace RTE:OBAI */
        }
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
            }
#endif /* ICU_MULTI_CORE_SUPPORT == STD_ON */

            
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_DeInit \
( \
    P2CONST(struct ICU_Gtm_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(Icu_ChannelConfig_Type, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelIndex = 0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_Channel = 0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelNum;
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelId = 0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8Icu_ModuleId = 0U;
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CurrentCoreId = (uint32)Icu_GetCoreID();/* polyspace RTE:SHF,OVFL */
    VAR(uint8,  AUTOMATIC) u8CoreIdMask;
    VAR(Icu_IndexType, AUTOMATIC) nInstance;
#endif
    u8Icu_ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    if(NULL_PTR != sIcu_WrapperConfigPtr->pGtmChannelConfig)/* polyspace RTE:NIP,IDP */
    {
        psChannelConfig = sIcu_WrapperConfigPtr->pGtmChannelConfig;
        for(u8Icu_Channel = 0; u8Icu_Channel < u8Icu_ChannelNum; u8Icu_Channel++)
        {
#if(ICU_MULTI_CORE_SUPPORT == STD_ON)
                nInstance = psChannelConfig[u8Icu_ChannelIndex].IcuConfig_Instance;/* polyspace RTE:NIV,IDP*/
                u8CoreIdMask= (uint8)u32CurrentCoreId & sIcu_CfgPtr[GetCoreID()]->Icu_CoreMap[nInstance].nCoreId;/* polyspace RTE:OBAI,NIV,IDP*/
                if(u8CoreIdMask != 0U)
                {
                    sIcu_u8Hw2LogicChannelMap[GetCoreID()][nInstance] = ICU_CHN_UNUSED;/* polyspace RTE:OBAI */
#endif
            u8Icu_ChannelIndex = Icu_Gtm_Wrapper_GetIndex(u8Icu_Channel);
            if (u8Icu_ChannelIndex != (Icu_ChannelType)ICU_INVALID_INSTANCE)
            {
                u8Icu_ChannelId = (Icu_ChannelType)psChannelConfig[u8Icu_ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV,IDP */
                u8Icu_ModuleId = (Icu_Module_Type)psChannelConfig[u8Icu_ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
                Icu_Wrapper_DeInit(u8Icu_ModuleId,u8Icu_ChannelId);

            }
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
                }
#endif /* ICU_MULTI_CORE_SUPPORT == STD_ON */
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_IrqConfig \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber,\
    P2CONST(struct ICU_Gtm_ConfigType,   ICU_CONST, ICU_APPL_DATA) Icu_GtmConfig,\
    VAR(boolean, AUTOMATIC) IsEnable
)
{
    P2CONST(Icu_ChannelConfig_Type, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CurrentCoreId = (uint32)Icu_GetCoreID();/* polyspace RTE:SHF,OVFL */
    VAR(uint8,  AUTOMATIC) u8CoreIdMask;
    VAR(Icu_IndexType, AUTOMATIC) nInstance;
#endif

    u16ChannelNum = Icu_GtmConfig->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = Icu_GtmConfig->pGtmChannelConfig;/* polyspace RTE:NIV,NIP,IDP */
    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {

#if(ICU_MULTI_CORE_SUPPORT == STD_ON)
                nInstance = psChannelConfig[u16ChannelIndex].IcuConfig_Instance;/* polyspace RTE:NIV,IDP*/
                u8CoreIdMask= (uint8)u32CurrentCoreId & sIcu_CfgPtr[GetCoreID()]->Icu_CoreMap[nInstance].nCoreId;/* polyspace RTE:OBAI,NIV,IDP*/
                if(u8CoreIdMask != 0U)
                {

                    if (sIcu_u8Hw2LogicChannelMap[GetCoreID()][nInstance] == ICU_CHN_USED)/* polyspace RTE:OBAI */
                    {
#endif

        if (u16Icu_ChannelNumber == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            if(IsEnable == TRUE)
            {
                Icu_Wrapper_EnIrq(u8ModuleId, (uint8)u8IChannelId);
            }
            else
            {
                Icu_Wrapper_DisIrq(u8ModuleId, (uint8)u8IChannelId);
            }
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
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_SetActivationCondition \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    VAR(Icu_ActivationType, AUTOMATIC) eIcu_Activation, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    (void)sIcu_WrapperConfigPtr;
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelIndex = 0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelId = 0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8Icu_ModuleId = 0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    u8Icu_ChannelIndex = Icu_Gtm_Wrapper_GetIndex(u16Icu_ChannelNumber);
    if (u8Icu_ChannelIndex != (Icu_ChannelType)ICU_INVALID_INSTANCE)
    {
        u8Icu_ChannelId = (Icu_ChannelType)sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:OBAI,NIP,IDP,NIV */
        u8Icu_ModuleId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:OBAI,NIV */

        Icu_Wrapper_SetActivationCondition(u8Icu_ModuleId,u8Icu_ChannelId, (GTM_TIM_Edge_Type)eIcu_Activation);  /* PRQA S 4322 */
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_StartTimestamp \
( \
    VAR(Icu_ChannelType,                    AUTOMATIC) u16Icu_ChannelNumber, \
    VAR(boolean,                            AUTOMATIC) bDmaSupport, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelIndex = 0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8Icu_ModuleId = 0U;
    VAR(Icu_ChannelType ,AUTOMATIC) u16Icu_ChannelId = 0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    if (NULL_PTR != sIcu_WrapperConfigPtr->pGtmChannelConfig)/* polyspace RTE:NIP,IDP */
    {
        u8Icu_ChannelIndex = Icu_Gtm_Wrapper_GetIndex(u16Icu_ChannelNumber);
        if (u8Icu_ChannelIndex != (Icu_ChannelType)ICU_INVALID_INSTANCE)
        {
            u8Icu_ModuleId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:OBAI,NIV,NIP,IDP */
            u16Icu_ChannelId = (Icu_ChannelType)sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:OBAI,NIV */
            Icu_Wrapper_StartTimestamp(u8Icu_ModuleId,(uint8)u16Icu_ChannelId, (boolean)bDmaSupport);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_StopTimestamp \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8Icu_ModuleId = (Icu_Module_Type)0U;
    VAR(Icu_ChannelType ,AUTOMATIC) u16Icu_ChannelId = (Icu_ChannelType)0U;
    VAR(GPT_GTM_Status_Type ,AUTOMATIC) eIcu_GTMIsEnable = (GPT_GTM_Status_Type)0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    if (NULL_PTR != sIcu_WrapperConfigPtr->pGtmChannelConfig)/* polyspace RTE:NIP,IDP */
    {
        u8Icu_ChannelIndex = Icu_Gtm_Wrapper_GetIndex(u16Icu_ChannelNumber);
        if (u8Icu_ChannelIndex != (Icu_ChannelType)ICU_INVALID_INSTANCE)
        {
            u8Icu_ModuleId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:OBAI,NIV,NIP,IDP */
            u16Icu_ChannelId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:OBAI,NIV */
            Icu_Wrapper_StopTimestamp(u8Icu_ModuleId,u16Icu_ChannelId,eIcu_GTMIsEnable);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
    
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_IndexType, ICU_CODE) Icu_Gtm_Wrapper_GetTimestampIndex \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel \
)
{
    VAR(Icu_IndexType, AUTOMATIC) u16Icu_TimeStampIndex = 0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();
    if (NULL_PTR == sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].u32Icu_ChannelBuffer)/* polyspace RTE:OBAI */
    {
        u16Icu_TimeStampIndex = 0U;
    }  
    else
    {
        u16Icu_TimeStampIndex = sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].u32Icu_ChannelBufferIndex;/* polyspace RTE:OBAI */
    } 
    return u16Icu_TimeStampIndex;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_ResetEdgeCount \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelIndex = 0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8Icu_ModuleId = 0U;
    VAR(Icu_ChannelType ,AUTOMATIC) u16Icu_ChannelId = 0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();
    VAR(GPT_GTM_Status_Type ,AUTOMATIC) eIcu_GTMIsEnable = GPT_GTM_Enable;

    if (NULL_PTR != sIcu_WrapperConfigPtr->pGtmChannelConfig)/* polyspace RTE:NIP,IDP */
    {
        u8Icu_ChannelIndex = Icu_Gtm_Wrapper_GetIndex(u16Icu_Channel);
        if (u8Icu_ChannelIndex != (Icu_ChannelType)ICU_INVALID_INSTANCE)
        {
            u8Icu_ModuleId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:OBAI,NIV,NIP,IDP */
            u16Icu_ChannelId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:OBAI,NIV */
            sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_Channel].u32Icu_ChannelEdgeNumbers = 0;/* polyspace RTE:OBAI */
            Icu_Wrapper_ResetEdgeCount(u8Icu_ModuleId,u16Icu_ChannelId,eIcu_GTMIsEnable);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_EnableEdgeCount \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelIndex = 0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8Icu_ModuleId = 0U;
    VAR(Icu_ChannelType ,AUTOMATIC) u16Icu_ChannelId = 0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    if (NULL_PTR != sIcu_WrapperConfigPtr->pGtmChannelConfig)/* polyspace RTE:NIP,IDP */
    {
        u8Icu_ChannelIndex = Icu_Gtm_Wrapper_GetIndex(u16Icu_ChannelNumber);
        if (u8Icu_ChannelIndex != (Icu_ChannelType)ICU_INVALID_INSTANCE)
        {
            u8Icu_ModuleId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:OBAI,NIV,NIP,IDP */
            u16Icu_ChannelId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:OBAI,NIV */
            sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_ChannelNumber].u32Icu_ChannelEdgeNumbers = 0;
            Icu_Wrapper_EnableEdgeCount(u8Icu_ModuleId,u16Icu_ChannelId);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_DisableEdgeCount \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelIndex = 0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8Icu_ModuleId = 0U;
    VAR(Icu_ChannelType ,AUTOMATIC) u16Icu_ChannelId = 0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    if (NULL_PTR != sIcu_WrapperConfigPtr->pGtmChannelConfig)/* polyspace RTE:NIP,IDP */
    {
        u8Icu_ChannelIndex = Icu_Gtm_Wrapper_GetIndex(u16Icu_ChannelNumber);
        if (u8Icu_ChannelIndex != (Icu_ChannelType)ICU_INVALID_INSTANCE)
        {
            u8Icu_ModuleId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:OBAI,NIV,NIP,IDP */
            u16Icu_ChannelId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:OBAI,NIV */
            sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_ChannelNumber].u32Icu_ChannelEdgeNumbers = 0;/* polyspace RTE:OBAI */
            Icu_Wrapper_DisableEdgeCount(u8Icu_ModuleId,u16Icu_ChannelId);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_EdgeNumberType, ICU_CODE) Icu_Gtm_Wrapper_GetEdgeNumbers \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelIndex = 0U;
    VAR(Icu_EdgeNumberType, AUTOMATIC) u16Icu_EdgeNumbers = 0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8Icu_ModuleId = 0U;
    VAR(Icu_ChannelType ,AUTOMATIC) u16Icu_ChannelId = 0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    if (NULL_PTR != sIcu_WrapperConfigPtr->pGtmChannelConfig)/* polyspace RTE:NIP,IDP */
    {
        u8Icu_ChannelIndex = Icu_Gtm_Wrapper_GetIndex(u16Icu_Channel);
        if (u8Icu_ChannelIndex != (Icu_ChannelType)ICU_INVALID_INSTANCE)
        {
            u8Icu_ModuleId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:OBAI,NIV,NIP,IDP */
            u16Icu_ChannelId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:OBAI,NIV */
            u16Icu_EdgeNumbers = Icu_Wrapper_GetEdgeNumbers(u8Icu_ModuleId,u16Icu_ChannelId);
        }
    }
    return u16Icu_EdgeNumbers;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_EnableEdgeDetection \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelIndex = 0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8Icu_ModuleId = 0U;
    VAR(Icu_ChannelType ,AUTOMATIC) u16Icu_ChannelId = 0U;
    VAR(GPT_GTM_Status_Type ,AUTOMATIC) eIcu_GTMIsEnable = (GPT_GTM_Status_Type)1U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    if (NULL_PTR != sIcu_WrapperConfigPtr->pGtmChannelConfig)/* polyspace RTE:NIP,IDP */
    {
        u8Icu_ChannelIndex = Icu_Gtm_Wrapper_GetIndex(u16Icu_ChannelNumber);
        if (u8Icu_ChannelIndex != (Icu_ChannelType)ICU_INVALID_INSTANCE)
        {
            u8Icu_ModuleId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:OBAI,NIV,NIP,IDP */
            u16Icu_ChannelId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:OBAI,NIV */
            Icu_Wrapper_EnableEdgeDetection(u8Icu_ModuleId,u16Icu_ChannelId,eIcu_GTMIsEnable);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_DisableEdgeDetection \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelIndex = 0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8Icu_ModuleId = 0U;
    VAR(Icu_ChannelType ,AUTOMATIC) u16Icu_ChannelId = 0U;
    VAR(GPT_GTM_Status_Type ,AUTOMATIC) eIcu_GTMIsEnable = (GPT_GTM_Status_Type)0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    if (NULL_PTR != sIcu_WrapperConfigPtr->pGtmChannelConfig)/* polyspace RTE:NIP,IDP */
    {
        u8Icu_ChannelIndex = Icu_Gtm_Wrapper_GetIndex(u16Icu_ChannelNumber);
        if (u8Icu_ChannelIndex != (Icu_ChannelType)ICU_INVALID_INSTANCE)
        {
            u8Icu_ModuleId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:OBAI,NIV,NIP,IDP */
            u16Icu_ChannelId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:OBAI,NIV */
            Icu_Wrapper_DisableEdgeDetection(u8Icu_ModuleId,u16Icu_ChannelId,eIcu_GTMIsEnable);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC (uint16, ICU_CODE) Icu_Gtm_Wrapper_GetSignalMeasurement
(
    VAR(Icu_SignalMeasurementPropertyType, AUTOMATIC) meas
)
{
    VAR(uint16, ICU_VAR) u16Return;

    if (ICU_LOW_TIME == meas)
    {
        u16Return = (uint16)GTM_TIM_MEAS_TYPE_LOW_TIME;
    }
    else if (ICU_HIGH_TIME == meas)
    {
        u16Return =  (uint16)GTM_TIM_MEAS_TYPE_HIGH_TIME;
    }
    else if (ICU_PERIOD_TIME == meas)
    {
        u16Return =  (uint16)GTM_TIM_MEAS_TYPE_PERIOD_TIME;
    }
    else
    {
        u16Return =  (uint16)GTM_TIM_MEAS_TYPE_DUTY_CYCLE;
    }

    return u16Return;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_StartSignalMeasurement \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelIndex = 0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8Icu_ModuleId = 0U;
    VAR(Icu_ChannelType ,AUTOMATIC) u16Icu_ChannelId = 0U;
    VAR(uint16,          AUTOMATIC) u16MeasProperty;

    Icu_ClearChannelState(u16Icu_ChannelNumber,ICU_CHANNEL_STATE_IDLE);

    if (NULL_PTR != sIcu_WrapperConfigPtr->pGtmChannelConfig)/* polyspace RTE:NIP,IDP */
    {
        u8Icu_ChannelIndex = Icu_Gtm_Wrapper_GetIndex(u16Icu_ChannelNumber);
        if (u8Icu_ChannelIndex != (Icu_ChannelType)ICU_INVALID_INSTANCE)
        {
            u8Icu_ModuleId = sIcu_WrapperConfigPtr->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:OBAI,NIV,IDP */
            u16Icu_ChannelId = sIcu_WrapperConfigPtr->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:OBAI,NIV */

            u16MeasProperty = Icu_Gtm_Wrapper_GetSignalMeasurement( \
                sIcu_WrapperConfigPtr->pGtmChannelConfig[u8Icu_ChannelIndex].IcuChannel_SignalMeasurementProperty);/* polyspace RTE:NIV */

                Icu_Wrapper_StartSignalMeasurement(u8Icu_ChannelIndex, u8Icu_ModuleId, \
                    u16Icu_ChannelId, \
                    u16MeasProperty);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_StopSignalMeasurement \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelIndex = 0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8Icu_ModuleId = 0U;
    VAR(Icu_ChannelType ,AUTOMATIC) u16Icu_ChannelId = 0U;
    VAR(GPT_GTM_Status_Type ,AUTOMATIC) eIcu_GTMIsEnable = (GPT_GTM_Status_Type)0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    if (NULL_PTR != sIcu_WrapperConfigPtr->pGtmChannelConfig)/* polyspace RTE:NIP,IDP */
    {
        u8Icu_ChannelIndex = Icu_Gtm_Wrapper_GetIndex(u16Icu_ChannelNumber);
        if (u8Icu_ChannelIndex != (Icu_ChannelType)ICU_INVALID_INSTANCE)
        {
            u8Icu_ModuleId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:OBAI,NIV,NIP,IDP */
            u16Icu_ChannelId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:OBAI,NIV */
            Icu_Wrapper_StopSignalMeasurement(u8Icu_ModuleId,u16Icu_ChannelId,eIcu_GTMIsEnable);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_ValueType, ICU_CODE) Icu_Gtm_Wrapper_GetTimeElapsed \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelIndex = 0U;
    VAR(Icu_ValueType, AUTOMATIC) u32Icu_TimeElapsed = 0UL;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    if (NULL_PTR != sIcu_WrapperConfigPtr->pGtmChannelConfig)/* polyspace RTE:NIP,IDP */
    {
        u8Icu_ChannelIndex = Icu_Gtm_Wrapper_GetIndex(u16Icu_ChannelNumber);
        if (u8Icu_ChannelIndex != (Icu_ChannelType)ICU_INVALID_INSTANCE)
        {
            if(ICU_PERIOD_TIME == sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuChannel_SignalMeasurementProperty)/* polyspace RTE:OBAI,NIV,NIP,IDP */
            {
                u32Icu_TimeElapsed = sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_ChannelNumber].u32Icu_ChannelPeriod;/* polyspace RTE:OBAI */
                sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_ChannelNumber].u32Icu_ChannelPeriod = 0UL;/* polyspace RTE:OBAI */
                Icu_ClearChannelState(u16Icu_ChannelNumber,ICU_CHANNEL_STATE_IDLE);
            }
            else
            {
                u32Icu_TimeElapsed = sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_ChannelNumber].u32Icu_ChannelActiveTime;/* polyspace RTE:OBAI */
                sIcu_ChannelInfo[u8Icu_CoreId][u16Icu_ChannelNumber].u32Icu_ChannelActiveTime = 0UL;/* polyspace RTE:OBAI */
                Icu_ClearChannelState(u16Icu_ChannelNumber,ICU_CHANNEL_STATE_IDLE);
            }
        }
    }
    return u32Icu_TimeElapsed;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_CheckWakeup \
( \
    VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource, \
    VAR(Icu_ChannelType, AUTOMATIC)u16Icu_ChannelIndex \
)
{
    if ((Std_ReturnType)ICU_CHANNEL_STATE_WKUP == Icu_GetChannelState(u16Icu_ChannelIndex,ICU_CHANNEL_STATE_WKUP))
    {
        /*SWS_Icu_00359*/
        (void)EcuM_SetWakeupEvent(WakeupSource);
        Icu_ClearChannelState(u16Icu_ChannelIndex,ICU_CHANNEL_STATE_WKUP);
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_GetVersionInfo \
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

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_InputStateType, ICU_CODE) Icu_Gtm_Wrapper_GetInputState \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelIndex = 0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8Icu_ModuleId = 0U;
    VAR(Icu_ChannelType ,AUTOMATIC) u16Icu_ChannelId = 0U;
    VAR(Icu_InputStateType, AUTOMATIC) eIcu_InputState = ICU_IDLE;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    if(NULL_PTR != sIcu_WrapperConfigPtr->pGtmChannelConfig)/* polyspace RTE:NIP,IDP */
    {
        u8Icu_ChannelIndex = Icu_Gtm_Wrapper_GetIndex(u16Icu_ChannelNumber);
        if (u8Icu_ChannelIndex != (Icu_ChannelType)ICU_INVALID_INSTANCE)
        {
            u8Icu_ModuleId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:OBAI,NIV,NIP,IDP */
            u16Icu_ChannelId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:OBAI,NIV */
            if(Icu_Wrapper_GetInputState(u8Icu_ModuleId,u16Icu_ChannelId) == (Icu_InputStateType)TRUE)
            {
                eIcu_InputState = ICU_ACTIVE;
            }
        }
    }

    return eIcu_InputState;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32, ICU_CODE) Icu_Gtm_Wrapper_GetStartAddress \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelIndex = 0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8Icu_ModuleId = 0U;
    VAR(Icu_ChannelType ,AUTOMATIC) u16Icu_ChannelId = 0U;
    VAR(uint32,          AUTOMATIC) u32Icu_Result = 0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    if(NULL_PTR != sIcu_WrapperConfigPtr->pGtmChannelConfig)/* polyspace RTE:NIP,IDP */
    {
        u8Icu_ChannelIndex = Icu_Gtm_Wrapper_GetIndex(u16Icu_ChannelNumber);
        if (u8Icu_ChannelIndex != (Icu_ChannelType)ICU_INVALID_INSTANCE)
        {
            u8Icu_ModuleId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:OBAI,NIV,NIP,IDP */
            u16Icu_ChannelId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:OBAI,NIV */

            u32Icu_Result = Icu_Wrapper_GetStartAddress(u8Icu_ModuleId, u16Icu_ChannelId);
        }
    }

    return u32Icu_Result;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(boolean, ICU_CODE) Icu_Gtm_Wrapper_GetOverflow \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    VAR(Icu_ChannelType, AUTOMATIC) u8Icu_ChannelIndex = 0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8Icu_ModuleId = 0U;
    VAR(Icu_ChannelType ,AUTOMATIC) u16Icu_ChannelId = 0U;
    VAR(boolean,         AUTOMATIC) u32Icu_Result = 0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    if(NULL_PTR != sIcu_WrapperConfigPtr->pGtmChannelConfig)/* polyspace RTE:NIP,IDP */
    {
        u8Icu_ChannelIndex = Icu_Gtm_Wrapper_GetIndex(u16Icu_ChannelNumber);
        if (u8Icu_ChannelIndex != (Icu_ChannelType)ICU_INVALID_INSTANCE)
        {
            u8Icu_ModuleId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:OBAI,NIV,NIP,IDP */
            u16Icu_ChannelId = sIcu_CfgPtr[u8Icu_CoreId]->Icu_GtmConfig->pGtmChannelConfig[u8Icu_ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:OBAI,NIV */

            u32Icu_Result = Icu_Wrapper_GetOverFlow(u8Icu_ModuleId, u16Icu_ChannelId);
        }
    }

    return u32Icu_Result;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (Icu_LevelType, ICU_CODE) Icu_Gtm_Wrapper_GetInputLevel \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_Gtm_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(Icu_ChannelConfig_Type, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
    VAR(Icu_LevelType,   AUTOMATIC) eReturnInputLevel = ICU_LEVEL_LOW;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->pGtmChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */

            if((boolean)TRUE == Gtm_Channel_GetInputLevel(u8ModuleId, (uint8)u8IChannelId))
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
FUNC (Icu_ValueType, ICU_CODE) Icu_Gtm_Wrapper_GetCaptureRegisterValue \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_Gtm_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(Icu_ChannelConfig_Type, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
    VAR(Icu_ValueType,   AUTOMATIC) ReturnValue = 0UL;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;
    psChannelConfig = sIcu_WrapperConfigPtr->pGtmChannelConfig;

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;

            ReturnValue = Gtm_Channel_GetGPR0Value(u8ModuleId, (uint8)u8IChannelId);

            break;
        }
    }

    return ReturnValue;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410) */
#ifdef __cplusplus
}
#endif

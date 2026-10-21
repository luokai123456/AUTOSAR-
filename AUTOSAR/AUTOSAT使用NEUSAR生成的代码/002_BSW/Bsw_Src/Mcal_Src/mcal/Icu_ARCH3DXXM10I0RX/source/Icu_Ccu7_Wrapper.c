/* PRQA S 0380, 1006, 0491, 2052, 4322, 4397, 2844 EOF */
/* PRQA S 1258, 3332, 2053, 4342, 2982 EOF */
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
*   @file    Icu_Ccu7_Wrapper.c
*   @version
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif
#include "Icu.h"
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
#include "Icu_Ccu7_Wrapper.h"
#include "Icu_Ccu7_HAL_Wrapper.h"
#include "eDMA.h"

/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_Ccu7_WRAPPER_VENDOR_ID_C                   176

#define ICU_Ccu7_WRAPPER_MAJOR_VER_C                   4
#define ICU_Ccu7_WRAPPER_MINOR_VER_C                   4
#define ICU_Ccu7_WRAPPER_REVISION_VER_C                0

#define ICU_Ccu7_WRAPPER_SW_MAJOR_VER_C                3
#define ICU_Ccu7_WRAPPER_SW_MINOR_VER_C                0
#define ICU_Ccu7_WRAPPER_SW_PATCH_VER_C                0

#if (ICU_Ccu7_WRAPPER_VENDOR_ID_C != ICU_Ccu7_WRAPPER_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_Ccu7_WRAPPER_MAJOR_VER_C != ICU_Ccu7_WRAPPER_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_Ccu7_WRAPPER_MINOR_VER_C != ICU_Ccu7_WRAPPER_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_Ccu7_WRAPPER_REVISION_VER_C != ICU_Ccu7_WRAPPER_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_Ccu7_WRAPPER_SW_MAJOR_VER_C != ICU_Ccu7_WRAPPER_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_Ccu7_WRAPPER_SW_MINOR_VER_C != ICU_Ccu7_WRAPPER_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_Ccu7_WRAPPER_SW_PATCH_VER_C != ICU_Ccu7_WRAPPER_SW_PATCH_VER_H)
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
#define ICU_START_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"
static VAR(uint16, ICU_VAR) sIcu_Ccu7_ChannelMap[ICU_CORE_NUM][ICU_CCU7_INSTANCE_MAX*ICU_CCU7_MODULE_CHANNEL_MAX];
#define ICU_STOP_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_ChannelType, ICU_CODE) Icu_Ccu7_Wrapper_GetInstance \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
)
{
    VAR(Icu_ChannelType,    ICU_VAR) nInstance = (Icu_ChannelType)ICU_INVALID_INSTANCE;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    nInstance = sIcu_Ccu7_ChannelMap[u8Icu_CoreId][ICU_CCU7_MODU_CHAN_COMBIN((u8Module), (u8Channel))];/* polyspace RTE:OBAI */
    return nInstance;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Wrapper_Init \
( \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_Ccu7_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Ccu7_Channel_Config, AUTOMATIC) sChannelConfig;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)

    VAR(uint8,ICU_VAR) u8Icu_CoreId = GetCoreID();
    VAR(uint32, AUTOMATIC) u32CurrentCoreId = Icu_GetCoreID();
    VAR(uint8,  AUTOMATIC) u8CoreIdMask;
    VAR(Icu_IndexType, AUTOMATIC) nInstance;
#endif

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->pCcu7ChannelConfig;/* polyspace RTE:NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIP,NIV,IDP */
        u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIP,NIV */

        sChannelConfig.sChannelParam.TimerPeriodReg     = ICU_CCU7_MAX_T12_TIMER_VAL;
        sChannelConfig.sChannelParam.TimerCntReg        = 0U;
        sChannelConfig.sChannelParam.TimerCtrlReg0      = (uint8)((psChannelConfig[u16ChannelIndex].pIcuConfig_HwConfig->T12PRE << 3)|(psChannelConfig[u16ChannelIndex].pIcuConfig_HwConfig->CTM << 7));/* polyspace RTE:NIP,NIV,IDP */
        sChannelConfig.sChannelParam.PortInSelReg0      = (uint8)psChannelConfig[u16ChannelIndex].pIcuConfig_HwConfig->PinSelection;/* polyspace RTE:OBAI,NIV */
        sChannelConfig.sChannelParam.IntEnReg           = 0U;
        sChannelConfig.sChannelParam.IntNodePointerReg  = (uint8)(psChannelConfig[u16ChannelIndex].pIcuConfig_HwConfig->INPCC7X);/* polyspace RTE:OBAI,NIV */
        sChannelConfig.sChannelParam.TimerModeSelectReg = (uint8)psChannelConfig[u16ChannelIndex].pIcuConfig_HwConfig->TimerModeSelectReg;/* polyspace RTE:OBAI,NIV */
        sChannelConfig.bDmaSupport                      = psChannelConfig[u16ChannelIndex].IcuChannel_bDmaSupport;/* polyspace RTE:OBAI,NIV */

        switch(psChannelConfig[u16ChannelIndex].IcuConfig_ChannelMode)/* polyspace RTE:OBAI,NIV */
          {
            case ICU_MODE_SIGNAL_MEASUREMENT:
              if(ICU_PERIOD_TIME == psChannelConfig[u16ChannelIndex].IcuChannel_SignalMeasurementProperty)/* polyspace RTE:OBAI,NIV */
              {
                if(ICU_RISING_EDGE == psChannelConfig[u16ChannelIndex].IcuChannel_DefaultStartEdge)/* polyspace RTE:OBAI,NIV */
                {
                    sChannelConfig.sChannelParam.TimerModeSelectReg = (uint8)ICU_CCU_CAPTURE_MODE2;
                }
                else
                {
                    sChannelConfig.sChannelParam.TimerModeSelectReg = (uint8)ICU_CCU_CAPTURE_MODE3;
                }
              }
              else
              {
                  sChannelConfig.sChannelParam.TimerModeSelectReg = (uint8)0;
              }
              break;
            case ICU_MODE_TIMESTAMP:
                 sChannelConfig.sChannelParam.TimerModeSelectReg = (uint8)0;
              break;
            default: /* ICU_MODE_SIGNAL_EDGE_DETECT */
                 sChannelConfig.sChannelParam.TimerModeSelectReg = (uint8)ICU_CCU_CAPTURE_MODE1;
              break;
          }

#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
        nInstance = psChannelConfig[u16ChannelIndex].IcuConfig_Instance;
        u8CoreIdMask= (uint8)u32CurrentCoreId & sIcu_CfgPtr[u8Icu_CoreId]->Icu_CoreMap[nInstance].nCoreId;
        if(u8CoreIdMask != 0)
        {
            sIcu_u8Hw2LogicChannelMap[u8Icu_CoreId][nInstance] = ICU_CHN_USED;
#endif /* (ICU_MULTI_CORE_SUPPORT == STD_ON) */
        Icu_Ccu7_Channel_Init(u8ModuleId, (uint8)u8IChannelId, &sChannelConfig);

#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
        }
#endif /* (ICU_MULTI_CORE_SUPPORT == STD_ON) */
        sIcu_Ccu7_ChannelMap[GetCoreID()][ICU_CCU7_MODU_CHAN_COMBIN((u8ModuleId), ((uint8)u8IChannelId))] = (uint16)psChannelConfig[u16ChannelIndex].IcuConfig_Instance;/* polyspace RTE:OBAI,NIV */
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Wrapper_DeInit \
( \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_Ccu7_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CurrentCoreId = Icu_GetCoreID();
    VAR(uint8,  AUTOMATIC) u8CoreIdMask;
    VAR(Icu_IndexType, AUTOMATIC) nInstance;
#endif
    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->pCcu7ChannelConfig;/* polyspace RTE:NIV,IDP,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
#if(ICU_MULTI_CORE_SUPPORT == STD_ON)
                nInstance = psChannelConfig[u16ChannelIndex].IcuConfig_Instance;
                u8CoreIdMask= (uint8)u32CurrentCoreId & sIcu_CfgPtr[u32CurrentCoreId >> 1U]->Icu_CoreMap[nInstance].nCoreId;
                if(u8CoreIdMask != 0)
                {
                    sIcu_u8Hw2LogicChannelMap[u32CurrentCoreId >> 1U][nInstance] = ICU_CHN_UNUSED;
#endif
        u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV,IDP */
        u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV,NIP */

        Icu_Ccu7_Channel_DeInit(u8ModuleId, (uint8)u8IChannelId);
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
                }
#endif /* (ICU_MULTI_CORE_SUPPORT == STD_ON) */

    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_Ccu7_Wrapper_IrqConfig
(
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr, \
    VAR(boolean,                 AUTOMATIC) IsEnable
)
{
    P2CONST(ICU_Ccu7_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
    VAR(Ccu7_Edge_Type ,AUTOMATIC) u8Edge = (Ccu7_Edge_Type)1U;
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CurrentCoreId = Icu_GetCoreID();
    VAR(uint8,  AUTOMATIC) u8CoreIdMask;
    VAR(Icu_IndexType, AUTOMATIC) nInstance;
#endif
    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->pCcu7ChannelConfig;/* polyspace RTE:NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
#if(ICU_MULTI_CORE_SUPPORT == STD_ON)
                nInstance = psChannelConfig[u16ChannelIndex].IcuConfig_Instance;
                u8CoreIdMask= (uint8)u32CurrentCoreId & sIcu_CfgPtr[u32CurrentCoreId >> 1U]->Icu_CoreMap[nInstance].nCoreId;
                if(u8CoreIdMask != 0)
                {
                    if (sIcu_u8Hw2LogicChannelMap[u32CurrentCoreId >> 1U][nInstance] == ICU_CHN_USED)
                    {
#endif
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV,IDP */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV,IDP */
            u8Edge = (Ccu7_Edge_Type)psChannelConfig[u16ChannelIndex].IcuChannel_DefaultStartEdge;/* polyspace RTE:NIV,IDP */

            if (IsEnable == TRUE)
            {
                Icu_Ccu7_Channel_EnIrq(u8ModuleId, (uint8)u8IChannelId, u8Edge);
            }
            else
            {
                Icu_Ccu7_Channel_DisIrq(u8ModuleId, (uint8)u8IChannelId);
            }
            break;
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
                    }
                }
#endif /* (ICU_MULTI_CORE_SUPPORT == STD_ON) */
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_Ccu7_Wrapper_SetActivationCondition \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    VAR(Icu_ActivationType,              AUTOMATIC) eActivation, \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_Ccu7_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->pCcu7ChannelConfig;/* polyspace RTE:NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV,IDP */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV,IDP */

            ICU_CCU7_LLD_ClrCc7xFlag(u8ModuleId, u8IChannelId, ICU_CCU7X_RF);
//            ICU_CCU7_LLD_ClrT12pmFlag(u8ModuleId);
            ICU_CCU7_LLD_SetCmpmodifCC7xR(u8ModuleId, u8IChannelId);

            if(0u != ICU_CCU7_LLD_GetIenCC7xR(u8ModuleId, u8IChannelId))
            {
                switch(eActivation)
                {
                case ICU_FALLING_EDGE:
                {
                    ICU_CCU7_LLD_SetCc7xIntEn(u8ModuleId, u8IChannelId, ICU_CCU7X_F);
                    break;
                }
                case ICU_RISING_EDGE:
                {
                    ICU_CCU7_LLD_SetCc7xIntEn(u8ModuleId, u8IChannelId, ICU_CCU7X_R);
                    break;
                }
                case ICU_BOTH_EDGES:
                {
                    ICU_CCU7_LLD_SetCc7xIntEn(u8ModuleId, u8IChannelId, ICU_CCU7X_RF);
                    break;
                }
                default:
                    /* do nothing */
                    break;
                }
            }

            /* break loop for ... */
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_TIMESTAMP_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_Ccu7_Wrapper_StartTimestamp \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_Ccu7_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->pCcu7ChannelConfig;/* polyspace RTE:NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            Icu_Ccu7_Channel_StartTimestamp(u8ModuleId, (uint8)u8IChannelId, psChannelConfig[u16ChannelIndex].IcuChannel_DefaultStartEdge);/* polyspace RTE:NIV */
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_Ccu7_Wrapper_StopTimestamp \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_Ccu7_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->pCcu7ChannelConfig;/* polyspace RTE:NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            Icu_Ccu7_Channel_StopTimestamp(u8ModuleId, (uint8)u8IChannelId);
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_Ccu7_Wrapper_EnableEdgeDetection \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_Ccu7_ConfigType,  ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_Ccu7_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->pCcu7ChannelConfig;/* polyspace RTE:NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            Icu_Ccu7_Channel_EnableEdgeDetection(u8ModuleId, (uint8)u8IChannelId, psChannelConfig[u16ChannelIndex].IcuChannel_DefaultStartEdge);/* polyspace RTE:NIV */
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (ICU_TIMESTAMP_API == STD_ON) */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_Ccu7_Wrapper_DisableEdgeDetection \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_Ccu7_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->pCcu7ChannelConfig;/* polyspace RTE:NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV,IDP */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV,IDP */
            Icu_Ccu7_Channel_DisableEdgeDetection(u8ModuleId, (uint8)u8IChannelId);
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_Ccu7_Wrapper_StartSignalMeasurement \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    VAR(uint32,                          AUTOMATIC) u32StartEdge, \
    VAR(uint16,                          AUTOMATIC) u16MeasProperty, \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_Ccu7_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
    VAR(Ccu7_Edge_Type,   AUTOMATIC) eActivation;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->pCcu7ChannelConfig;/* polyspace RTE:NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */

            if((u32StartEdge != (uint32)ICU_FALLING_EDGE) && (u32StartEdge != (uint32)ICU_RISING_EDGE) && \
                    (u32StartEdge != (uint32)ICU_BOTH_EDGES))
            {
                u32StartEdge = (uint32)psChannelConfig[u16ChannelIndex].IcuChannel_DefaultStartEdge;/* polyspace RTE:NIV */
            }
            if((u16MeasProperty != (uint16)ICU_LOW_TIME) && (u16MeasProperty != (uint16)ICU_HIGH_TIME) && \
                    (u16MeasProperty != (uint16)ICU_PERIOD_TIME) && (u16MeasProperty != (uint16)ICU_DUTY_CYCLE))
            {
                u16MeasProperty = (uint16)psChannelConfig[u16ChannelIndex].IcuChannel_SignalMeasurementProperty;/* polyspace RTE:NIV */
            }

            if (u32StartEdge == (uint32)ICU_FALLING_EDGE)
            {
                eActivation = (Ccu7_Edge_Type)ICU_CCU7X_F;
            }
            else if (u32StartEdge == (uint32)ICU_RISING_EDGE)
            {
                eActivation = (Ccu7_Edge_Type)ICU_CCU7X_R;
            }
            else
            {
                eActivation = (Ccu7_Edge_Type)ICU_CCU7X_RF;
            }

            Icu_Ccu7_Channel_StartSignalMeasurement(u8ModuleId, \
                (uint8)u8IChannelId,       \
                (Ccu7_Edge_Type)eActivation,        \
                (uint16)u16MeasProperty
                );
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_Ccu7_Wrapper_StopSignalMeasurement \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_Ccu7_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->pCcu7ChannelConfig;/* polyspace RTE:NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            Icu_Ccu7_Channel_StopSignalMeasurement(u8ModuleId, (uint8)u8IChannelId);
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_SIGNAL_MEASUREMENT_API == STD_ON */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_ValueType, ICU_CODE) Icu_Ccu7_Wrapper_GetTimeElapsed \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_Ccu7_ChannelConfig, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ValueType, AUTOMATIC) returnValue = (Icu_ValueType)0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->pCcu7ChannelConfig;/* polyspace RTE:NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            if (psChannelConfig[u16ChannelIndex].IcuChannel_SignalMeasurementProperty == ICU_PERIOD_TIME)/* polyspace RTE:NIV,IDP */
            {
                returnValue = sIcu_ChannelInfo[u8Icu_CoreId][nChannel].u32Icu_ChannelPeriod;/* polyspace RTE:OBAI */
                sIcu_ChannelInfo[u8Icu_CoreId][nChannel].u32Icu_ChannelPeriod = (Icu_ValueType)0U;
            }
            else
            {
                returnValue = sIcu_ChannelInfo[u8Icu_CoreId][nChannel].u32Icu_ChannelActiveTime;/* polyspace RTE:OBAI */
                sIcu_ChannelInfo[u8Icu_CoreId][nChannel].u32Icu_ChannelActiveTime = (Icu_ValueType)0U;
            }

            Icu_ClearChannelState(nChannel, ICU_CHANNEL_STATE_IDLE);
            break;
        }
    }

    return returnValue;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
#ifdef __cplusplus
}
#endif

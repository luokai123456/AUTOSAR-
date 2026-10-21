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
/* PRQA S 2053 EOF */    /* QAC_CWE */
/**
*   @file    Icu_eTPU_HAL_Wrapper.c
*   @version 3.0.0 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/* PRQA S 3432, 0380, 0686, 1006 EOF */
/* PRQA S 2844 EOF */
/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif
#include "Icu_eTPU_HAL_Wrapper.h"
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "eTPU_HAL_Irq.h"
#include "Icu_Irq.h"
#include "SchM_Icu.h"
/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_ETPU_HAL_WRAPPER_VENDOR_ID_C                   176

#define ICU_ETPU_HAL_WRAPPER_MAJOR_VER_C                   4
#define ICU_ETPU_HAL_WRAPPER_MINOR_VER_C                   4
#define ICU_ETPU_HAL_WRAPPER_REVISION_VER_C                0

#define ICU_ETPU_HAL_WRAPPER_SW_MAJOR_VER_C                3
#define ICU_ETPU_HAL_WRAPPER_SW_MINOR_VER_C                0
#define ICU_ETPU_HAL_WRAPPER_SW_PATCH_VER_C                0

#if (ICU_ETPU_HAL_WRAPPER_VENDOR_ID_C != ICU_ETPU_HAL_WRAPPER_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_ETPU_HAL_WRAPPER_MAJOR_VER_C != ICU_ETPU_HAL_WRAPPER_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_ETPU_HAL_WRAPPER_MINOR_VER_C != ICU_ETPU_HAL_WRAPPER_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_ETPU_HAL_WRAPPER_REVISION_VER_C != ICU_ETPU_HAL_WRAPPER_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_ETPU_HAL_WRAPPER_SW_MAJOR_VER_C != ICU_ETPU_HAL_WRAPPER_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_ETPU_HAL_WRAPPER_SW_MINOR_VER_C != ICU_ETPU_HAL_WRAPPER_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_ETPU_HAL_WRAPPER_SW_PATCH_VER_C != ICU_ETPU_HAL_WRAPPER_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ETPU_BUFFER_COUNT                2U
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
typedef struct
{
    VAR(uint8, ICU_VAR) u8Instance;
    VAR(uint8, ICU_VAR) u8Passage;
} eTPU_ModuleInfo;

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ICU_START_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"
static VAR(eTPU_Channel_ConfigData, ICU_VAR) sIcu_eTpu_ChConfig[ICU_CORE_NUM][ETPU_CHANEEL_MAX*ETPU_MODULE_MAX];
#define ICU_STOP_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"

#if (ICU_ENABLEEDGECOUNT_API == STD_ON)
#define ICU_START_SEC_VAR_INIT
#include "Icu_MemMap.h"
static VAR(uint32, ICU_VAR) sIcu_eTpu_EdgeCurrent_Value[ICU_CORE_NUM][ETPU_CHANEEL_MAX*ETPU_MODULE_MAX] = { {0} };
#define ICU_STOP_SEC_VAR_INIT
#include "Icu_MemMap.h"
#endif

#if (ICU_STARTSIGNALMEASUREMENT_API == STD_ON)
#define ICU_START_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"
static VAR(uint8, ICU_VAR) sIcu_eTpu_aInt_Counter[ICU_CORE_NUM][ETPU_CHANEEL_MAX*ETPU_MODULE_MAX];
#define ICU_STOP_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"

#define ICU_START_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"
static VAR(Icu_ValueType, ICU_VAR) sIcu_eTpu_CapturedActivePulseWidth[ICU_CORE_NUM][ETPU_CHANEEL_MAX*ETPU_MODULE_MAX];
#define ICU_STOP_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"

#define ICU_START_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"
static VAR(Icu_ValueType, ICU_VAR) sIcu_eTpu_TimeStart[ICU_CORE_NUM][ETPU_CHANEEL_MAX*ETPU_MODULE_MAX];
#define ICU_STOP_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"
#endif /* ICU_STARTSIGNALMEASUREMENT_API == STD_ON */

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
#if (ICU_ENABLEEDGECOUNT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC(void, ICU_CODE) eTpu_SetEdgeValue
(
    VAR(uint8,          AUTOMATIC) u8Module, \
    VAR(uint8,          AUTOMATIC) u8Channel, \
    VAR(Icu_ValueType,  AUTOMATIC) u32Value \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_STARTSIGNALMEASUREMENT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC(void, ICU_CODE) eTpu_SetIntCounter
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(uint8, AUTOMATIC) u8Value \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC(uint32, ICU_CODE) eTpu_GetIntCounter
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC(void, ICU_CODE) eTpu_SetPulseWidth
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(uint8, AUTOMATIC) u32Value \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC(void, ICU_CODE) eTpu_SetTimeStart
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(uint32, AUTOMATIC) u32Value \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC(uint32, ICU_CODE) eTpu_GetTimeStart
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_STARTSIGNALMEASUREMENT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
static FUNC(void, ICU_CODE) eTpu_Channel_SignalMeasurement \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(boolean, AUTOMATIC) bOverflow \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE boolean eTpu_GetModuleInfo
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel, \
    P2VAR(eTPU_ModuleInfo, AUTOMATIC, ICU_CODE) spInfo \
)
{
    VAR(boolean, ICU_VAR) bRetFlag = (boolean)TRUE;

    if (u8Module == (uint8)eTPU_A)
    {
        spInfo->u8Instance = (uint8)ETPU_INSTANCE_A_B;
        spInfo->u8Passage = ETPU_A_CHANNLE(u8Channel);
    }
    else if (u8Module == (uint8)eTPU_B)
    {
        spInfo->u8Instance = (uint8)ETPU_INSTANCE_A_B;
        spInfo->u8Passage = ETPU_B_CHANNLE(u8Channel);
    }
    else if (u8Module == (uint8)eTPU_C)
    {
        spInfo->u8Instance = (uint8)ETPU_INSTANCE_C;
        spInfo->u8Passage = ETPU_C_CHANNLE(u8Channel);
    }
    else
    {
        bRetFlag = (boolean)FALSE;
    }

    return bRetFlag;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_ENABLEEDGECOUNT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC(void, ICU_CODE) eTpu_SetEdgeValue
(
    VAR(uint8,          AUTOMATIC) u8Module, \
    VAR(uint8,          AUTOMATIC) u8Channel, \
    VAR(Icu_ValueType,  AUTOMATIC) u32Value \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = ETPU_MODU_CHAN_COMBIN(u8Module, u8Channel);

    sIcu_eTpu_EdgeCurrent_Value[GetCoreID()][u8ChannelIdx] = u32Value;/* GetCoreID *//* polyspace RTE:OBAI */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32, ICU_CODE) eTpu_GetEdgeValue
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = ETPU_MODU_CHAN_COMBIN(u8Module, u8Channel);

    return sIcu_eTpu_EdgeCurrent_Value[GetCoreID()][u8ChannelIdx];/* GetCoreID *//* polyspace RTE:OBAI */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_ENABLEEDGECOUNT_API */

#if (ICU_STARTSIGNALMEASUREMENT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC(void, ICU_CODE) eTpu_SetIntCounter
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(uint8, AUTOMATIC) u8Value \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = ETPU_MODU_CHAN_COMBIN(u8Module, u8Channel);

    sIcu_eTpu_aInt_Counter[GetCoreID()][u8ChannelIdx] = u8Value;/* GetCoreID *//* polyspace RTE:OBAI */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC(uint32, ICU_CODE) eTpu_GetIntCounter
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = ETPU_MODU_CHAN_COMBIN(u8Module, u8Channel);

    return sIcu_eTpu_aInt_Counter[GetCoreID()][u8ChannelIdx];/* GetCoreID *//* polyspace RTE:OBAI */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC(void, ICU_CODE) eTpu_SetPulseWidth
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(uint8, AUTOMATIC) u32Value \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = ETPU_MODU_CHAN_COMBIN(u8Module, u8Channel);

    sIcu_eTpu_CapturedActivePulseWidth[GetCoreID()][u8ChannelIdx] = u32Value;/* GetCoreID *//* polyspace RTE:OBAI */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32, ICU_CODE) eTpu_GetPulseWidth
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = ETPU_MODU_CHAN_COMBIN(u8Module, u8Channel);

    return sIcu_eTpu_CapturedActivePulseWidth[GetCoreID()][u8ChannelIdx];/* GetCoreID *//* polyspace RTE:OBAI */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC(void, ICU_CODE) eTpu_SetTimeStart
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(uint32, AUTOMATIC) u32Value \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = ETPU_MODU_CHAN_COMBIN(u8Module, u8Channel);

    sIcu_eTpu_TimeStart[GetCoreID()][u8ChannelIdx] = u32Value;/* GetCoreID *//* polyspace RTE:OBAI */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC(uint32, ICU_CODE) eTpu_GetTimeStart
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = ETPU_MODU_CHAN_COMBIN(u8Module, u8Channel);

    return sIcu_eTpu_TimeStart[GetCoreID()][u8ChannelIdx];/* GetCoreID *//* polyspace RTE:OBAI */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_STARTSIGNALMEASUREMENT_API */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC(void, ICU_CODE) eTpu_SetChConfig
(
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(uint32,     AUTOMATIC) u32Mask, \
    VAR(uint32,     AUTOMATIC) u32Value \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    u8ChannelIdx = ETPU_MODU_CHAN_COMBIN(u8Module, u8Channel);

    switch (u32Mask)
    {
    case ETPU_CONFIG_DATA_INITED:
    {
        sIcu_eTpu_ChConfig[u8Icu_CoreId][u8ChannelIdx].bits.inited = (uint8)u32Value;/* polyspace RTE:OBAI */
        break;
    }
    case ETPU_CONFIG_DATA_MEASMODE:
    {
        sIcu_eTpu_ChConfig[u8Icu_CoreId][u8ChannelIdx].bits.mode = (uint8)u32Value;/* polyspace RTE:OBAI */
        break;
    }
    case ETPU_CONFIG_DATA_OPMODE:
    {
        sIcu_eTpu_ChConfig[u8Icu_CoreId][u8ChannelIdx].bits.opmode = (uint8)u32Value;/* polyspace RTE:OBAI */
        break;
    }
    case ETPU_CONFIG_DATA_DMA:
    {
        sIcu_eTpu_ChConfig[u8Icu_CoreId][u8ChannelIdx].bits.dma = (uint8)u32Value;/* polyspace RTE:OBAI */
        break;
    }
    case ETPU_CONFIG_DATA_PROPERTY:
    {
        sIcu_eTpu_ChConfig[u8Icu_CoreId][u8ChannelIdx].bits.property = (uint8)u32Value;/* polyspace RTE:OBAI */
        break;
    }
    case ETPU_CONFIG_DATA_CLEAR:
    {
        sIcu_eTpu_ChConfig[u8Icu_CoreId][u8ChannelIdx].data = u32Value;/* polyspace RTE:OBAI */
        break;
    }
    default:
        /*nothing*/
        break;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC(uint32, ICU_CODE) eTpu_GetChConfig
(
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(uint32,     AUTOMATIC) u32Mask \
)
{
    VAR(uint32,     AUTOMATIC) u32RetrunValue = (0xFFFFFFFFU);
    VAR(uint8,      AUTOMATIC) u8ChannelIdx = (uint8)0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    u8ChannelIdx = ETPU_MODU_CHAN_COMBIN(u8Module, u8Channel);

    switch (u32Mask)
    {
    case ETPU_CONFIG_DATA_INITED:
    {
        u32RetrunValue = sIcu_eTpu_ChConfig[u8Icu_CoreId][u8ChannelIdx].bits.inited;/* polyspace RTE:OBAI */
        break;
    }
    case ETPU_CONFIG_DATA_MEASMODE:
    {
        u32RetrunValue = sIcu_eTpu_ChConfig[u8Icu_CoreId][u8ChannelIdx].bits.mode;/* polyspace RTE:OBAI */
        break;
    }
    case ETPU_CONFIG_DATA_OPMODE:
    {
        u32RetrunValue = sIcu_eTpu_ChConfig[u8Icu_CoreId][u8ChannelIdx].bits.opmode;/* polyspace RTE:OBAI */
        break;
    }
    case ETPU_CONFIG_DATA_DMA:
    {
        u32RetrunValue = sIcu_eTpu_ChConfig[u8Icu_CoreId][u8ChannelIdx].bits.dma;/* polyspace RTE:OBAI */
        break;
    }
    case ETPU_CONFIG_DATA_PROPERTY:
    {
        u32RetrunValue = sIcu_eTpu_ChConfig[u8Icu_CoreId][u8ChannelIdx].bits.property;/* polyspace RTE:OBAI */
        break;
    }
    default:
        /*nothing*/
        break;
    }

    return u32RetrunValue;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC (void, ICU_CODE) eTpu_Wrapper_Channel_SignalMeasurement
(
    VAR(uint8,          AUTOMATIC) u8Module, \
    VAR(uint8,          AUTOMATIC) u8Channel, \
    VAR(Icu_ValueType,  AUTOMATIC) activePulseWidth, \
    VAR(Icu_ValueType,  AUTOMATIC) period, \
    VAR(boolean,        AUTOMATIC) bOverflow \
)
{
    VAR(Icu_ChannelType, ICU_VAR) Instance = ICU_ATS_eTpu_Wapper_GetInstance(u8Module, u8Channel);

    ICU_SignalMeasurement(Instance, activePulseWidth, period, bOverflow);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC (void, ICU_CODE) eTpu_Wrapper_Channel_ReportWakeupAndOverflow
(
    VAR(uint8,          AUTOMATIC) u8Module, \
    VAR(uint8,          AUTOMATIC) u8Channel, \
    VAR(boolean,        AUTOMATIC) bOverflow \
)
{
    VAR(Icu_ChannelType, ICU_VAR) Instance = ICU_ATS_eTpu_Wapper_GetInstance(u8Module, u8Channel);

    ICU_ReportWakeupAndOverflow(Instance, bOverflow);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC (void, ICU_CODE) eTpu_Wrapper_Channel_ReportEvents
(
    VAR(uint8,          AUTOMATIC) u8Module, \
    VAR(uint8,          AUTOMATIC) u8Channel, \
    VAR(boolean,        AUTOMATIC) bOverflow \
)
{
    VAR(Icu_ChannelType, ICU_VAR) Instance = ICU_ATS_eTpu_Wapper_GetInstance(u8Module, u8Channel);

    ICU_AutoSAR_Wapper_ReportEvents(Instance, bOverflow);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_Init \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel, \
    P2VAR(eTPU_Channel_Config, AUTOMATIC, ICU_CODE) peTpuChannelConfig \
)
{
    VAR(eTPU_ModuleInfo,    AUTOMATIC) sInfo;
    VAR(boolean,            AUTOMATIC) bRetFlag = (boolean)TRUE;
    VAR(sint32,             AUTOMATIC) s32ReturnValue = 0;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        peTpuChannelConfig->sChannelParam.max_count = ETPU_BUFFER_COUNT;
        s32ReturnValue = ETPU_LLD_IC_Init(sInfo.u8Instance, \
            sInfo.u8Passage, \
            &peTpuChannelConfig->sChannelParam);
        if (s32ReturnValue != 0)
        {
            /* etpu ic init failed */
        }

        if (peTpuChannelConfig->bDmaSupport == (boolean)TRUE)
        {
            ETPU_LLD_ChannelDMADisable(sInfo.u8Instance, sInfo.u8Passage);
            ETPU_LLD_ChannelDMAMaskDisable(sInfo.u8Instance, sInfo.u8Passage);
            ETPU_LLD_ClearChannelDMAFlag(sInfo.u8Instance, sInfo.u8Passage);
            ETPU_LLD_ClearChannelDMAOverflowFlag(sInfo.u8Instance, sInfo.u8Passage);
        }
        else
        {
            ETPU_LLD_ChannelInterruptDisable(sInfo.u8Instance, sInfo.u8Passage);
            ETPU_LLD_ChannelIntMaskDisable(sInfo.u8Instance, sInfo.u8Passage);
            ETPU_LLD_ClearChannelInterruptFlag(sInfo.u8Instance, sInfo.u8Passage);
            ETPU_LLD_ClearChannelInterruptOverflowFlag(sInfo.u8Instance, sInfo.u8Passage);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_ConfigInit \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel, \
    P2VAR(eTPU_Channel_Config, AUTOMATIC, ICU_CODE) peTpuChannelConfig \
)
{
    peTpuChannelConfig->sChannelParam.max_count = ETPU_BUFFER_COUNT;
    eTpu_SetChConfig(u8Module, u8Channel, ETPU_CONFIG_DATA_DMA, \
        (peTpuChannelConfig->bDmaSupport != 0U) ? TRUE : FALSE);
    eTpu_SetChConfig(u8Module, u8Channel, ETPU_CONFIG_DATA_INITED, 1U);

}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_DeInit \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(eTPU_ModuleInfo,    AUTOMATIC) sInfo;
    VAR(boolean,            AUTOMATIC) bRetFlag = (boolean)TRUE;
    VAR(boolean,            AUTOMATIC) bDMA = (boolean)FALSE;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        ETPU_LLD_IC_DeInit(sInfo.u8Instance, sInfo.u8Passage);
        ETPU_LLD_ChannelIntMaskDisable(sInfo.u8Instance, sInfo.u8Passage);
        bDMA = ((eTpu_GetChConfig(u8Module, u8Channel, ETPU_CONFIG_DATA_DMA) != 0U)? \
            (boolean)TRUE : (boolean)FALSE);
        if (bDMA == (boolean)TRUE)
        {
            ETPU_LLD_ChannelDMAMaskDisable(sInfo.u8Instance, sInfo.u8Passage);
        }
        eTpu_SetChConfig(u8Module, u8Channel, ETPU_CONFIG_DATA_CLEAR, 0U);
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_DisIrq \
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(eTPU_ModuleInfo,    AUTOMATIC) sInfo;
    VAR(boolean,            AUTOMATIC) bRetFlag = (boolean)TRUE;
    VAR(boolean,            AUTOMATIC) bDMA = (boolean)FALSE;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        /* check interrupt status */
        bDMA = ((eTpu_GetChConfig(u8Module, u8Channel, ETPU_CONFIG_DATA_DMA) != 0U) ? \
            (boolean)TRUE : (boolean)FALSE);
        if (bDMA == (boolean)TRUE)
        {
            ETPU_LLD_ChannelDMAMaskDisable(sInfo.u8Instance, sInfo.u8Passage);
        }

        /* Disable interrupt */
        ETPU_LLD_ChannelIntMaskDisable(sInfo.u8Instance, sInfo.u8Passage);
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_EnIrq \
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(eTPU_ModuleInfo,    AUTOMATIC) sInfo;
    VAR(boolean,            AUTOMATIC) bRetFlag = (boolean)TRUE;
    VAR(boolean,            AUTOMATIC) bDMA = (boolean)FALSE;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        /* check interrupt status */
        bDMA = ((eTpu_GetChConfig(u8Module, u8Channel, ETPU_CONFIG_DATA_DMA) != 0U) ? \
            (boolean)TRUE : (boolean)FALSE);
        if (bDMA == (boolean)TRUE)
        {
            ETPU_LLD_ChannelDMAMaskEnable(sInfo.u8Instance, sInfo.u8Passage);
            ETPU_LLD_ClearChannelDMAFlag(sInfo.u8Instance, sInfo.u8Passage);
            ETPU_LLD_ClearChannelDMAOverflowFlag(sInfo.u8Instance, sInfo.u8Passage);
        }
        /* Clear interrupt status */
        ETPU_LLD_ChannelIntMaskEnable(sInfo.u8Instance, sInfo.u8Passage);
        ETPU_LLD_ClearChannelInterruptFlag(sInfo.u8Instance, sInfo.u8Passage);
        ETPU_LLD_ClearChannelInterruptOverflowFlag(sInfo.u8Instance, sInfo.u8Passage);
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_SetActivationCondition \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    CONST(eTPU_EdgeTrigModeType, AUTOMATIC) eActivation \
)
{
    VAR(eTPU_ModuleInfo,    AUTOMATIC) sInfo;
    VAR(boolean,            AUTOMATIC) bRetFlag = (boolean)TRUE;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);

    SchM_Enter_Icu_EXCLUSIVE_AREA_52();

    if (bRetFlag == (boolean)TRUE)
    {
        switch (eActivation)
        {
        case ETPU_IC_FALLING_EDGE:
        case ETPU_IC_RISING_EDGE:
        case ETPU_IC_ANY_EDGE:
        {
            ETPU_LLD_IC_SetTriggerMode(sInfo.u8Instance, sInfo.u8Passage, eActivation); /* polyspace RTE:NIVL */
            break;
        }
        case ETPU_IC_OPPOSITE:
        {
            ETPU_LLD_IC_SetTriggerMode(sInfo.u8Instance, sInfo.u8Passage, \
                (ETPU_LLD_IC_GetTriggerMode(sInfo.u8Instance, sInfo.u8Passage) == ETPU_IC_FALLING_EDGE) ? ETPU_IC_RISING_EDGE : ETPU_IC_FALLING_EDGE); /* polyspace RTE:NIVL */
            break;
        }
        default:
        {
            /* error Activation mode, do nothing */
            break;
        }
        }
    }

    SchM_Exit_Icu_EXCLUSIVE_AREA_52();
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_EnableEdgeDetection \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint32,             AUTOMATIC) u32ConfigData;
    VAR(eTPU_ModuleInfo,    AUTOMATIC) sInfo;
    VAR(boolean,            AUTOMATIC) bRetFlag = (boolean)TRUE;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        SchM_Enter_Icu_EXCLUSIVE_AREA_53();

        /* Enable interrupt */
        ETPU_LLD_ChannelIntMaskEnable(sInfo.u8Instance, sInfo.u8Passage);
        /* Clear interrupt flags */
        ETPU_LLD_ClearChannelInterruptFlag(sInfo.u8Instance, sInfo.u8Passage);
        ETPU_LLD_ClearChannelInterruptOverflowFlag(sInfo.u8Instance, sInfo.u8Passage);

        /* Set Channel Config */
        u32ConfigData = eTpu_GetChConfig(u8Module, u8Channel, ETPU_CONFIG_DATA_MEASMODE);
        u32ConfigData |= ETPU_MODE_SIGNAL_EDGE_DETECT;
        eTpu_SetChConfig(u8Module, u8Channel, \
            ETPU_CONFIG_DATA_MEASMODE, \
            (uint32)u32ConfigData);

        SchM_Exit_Icu_EXCLUSIVE_AREA_53();
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_DisableEdgeDetection \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint32,             AUTOMATIC) u32ConfigData;
    VAR(eTPU_ModuleInfo,    AUTOMATIC) sInfo;
    VAR(boolean,            AUTOMATIC) bRetFlag = (boolean)TRUE;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        SchM_Enter_Icu_EXCLUSIVE_AREA_54();

        /* Disable interrupt */
        ETPU_LLD_ChannelIntMaskDisable(sInfo.u8Instance, sInfo.u8Passage);

        /* Clear meas mode */
        u32ConfigData = eTpu_GetChConfig(u8Module, u8Channel, ETPU_CONFIG_DATA_MEASMODE);
        u32ConfigData &= ~ETPU_MODE_SIGNAL_EDGE_DETECT;
        eTpu_SetChConfig(u8Module, u8Channel, \
            ETPU_CONFIG_DATA_MEASMODE, \
            (uint32)u32ConfigData);

        SchM_Exit_Icu_EXCLUSIVE_AREA_54();
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_STARTTIMESTAMP_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_StartTimestamp \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(boolean,    AUTOMATIC) bDmaSupport \
)
{
    VAR(uint32,             AUTOMATIC) u32ConfigData;
    VAR(eTPU_ModuleInfo,    AUTOMATIC) sInfo;
    VAR(boolean,            AUTOMATIC) bRetFlag = (boolean)TRUE;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        u32ConfigData = eTpu_GetChConfig(u8Module, u8Channel, ETPU_CONFIG_DATA_MEASMODE);

        SchM_Enter_Icu_EXCLUSIVE_AREA_55();

        if (bDmaSupport == (boolean)TRUE)
        {
            /* Clear interrupt dma flags */
            ETPU_LLD_ClearChannelDMAFlag(sInfo.u8Instance, sInfo.u8Passage); /* polyspace RTE:NIVL */
            ETPU_LLD_ClearChannelDMAOverflowFlag(sInfo.u8Instance, sInfo.u8Passage);

            /* Set meas mode */
            u32ConfigData |= ETPU_MODE_TIMESTAMP_WITH_DMA;
            eTpu_SetChConfig(u8Module, u8Channel, \
                ETPU_CONFIG_DATA_MEASMODE, \
                (uint32)u32ConfigData);

            /* Enable DMA interrupt */
            ETPU_LLD_ChannelDMAMaskEnable(sInfo.u8Instance, sInfo.u8Passage);
        }
        else
        {
            /* Set meas mode */
            u32ConfigData |= ETPU_MODETIMESTAMP_WITHOUT_DMA;
            eTpu_SetChConfig(u8Module, u8Channel, \
                ETPU_CONFIG_DATA_MEASMODE, \
                (uint32)u32ConfigData);
        }

        /* Clear interrupt flags */
        ETPU_LLD_ClearChannelInterruptFlag(sInfo.u8Instance, sInfo.u8Passage); /* polyspace RTE:NIVL */
        ETPU_LLD_ClearChannelInterruptOverflowFlag(sInfo.u8Instance, sInfo.u8Passage);
        /* Enable interrupt */
        ETPU_LLD_ChannelIntMaskEnable(sInfo.u8Instance, sInfo.u8Passage);

        SchM_Exit_Icu_EXCLUSIVE_AREA_55();
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_StopTimestamp \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint32,             AUTOMATIC) u32ConfigData;
    VAR(eTPU_ModuleInfo,    AUTOMATIC) sInfo;
    VAR(boolean,            AUTOMATIC) bRetFlag = (boolean)TRUE;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        SchM_Enter_Icu_EXCLUSIVE_AREA_56();

        /* Disable interrupt */
        ETPU_LLD_ChannelIntMaskDisable(sInfo.u8Instance, sInfo.u8Passage);
        ETPU_LLD_ChannelDMAMaskDisable(sInfo.u8Instance, sInfo.u8Passage);

        /* Clear meas mode */
        u32ConfigData = eTpu_GetChConfig(u8Module, u8Channel, ETPU_CONFIG_DATA_MEASMODE);
        u32ConfigData &= ~(ETPU_MODE_TIMESTAMP_WITH_DMA | ETPU_MODETIMESTAMP_WITHOUT_DMA);
        eTpu_SetChConfig(u8Module, u8Channel, \
            ETPU_CONFIG_DATA_MEASMODE, \
            (uint32)u32ConfigData);

        SchM_Exit_Icu_EXCLUSIVE_AREA_56();
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC(void, ICU_CODE) eTpu_Wrapper_Channel_Timestamp \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(uint8,      AUTOMATIC) u8Capture, \
    P2CONST(uint32, AUTOMATIC, ICU_APPL_CONST) pu32Value, \
    VAR(boolean,    AUTOMATIC) bOverflow \
)
{
    VAR(Icu_ChannelType, ICU_VAR) Instance = ICU_ATS_eTpu_Wapper_GetInstance(u8Module, u8Channel);

    ICU_AutoSAR_Wapper_Timestamp(Instance, u8Capture, pu32Value, bOverflow);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ICU_INLINE FUNC(void, ICU_CODE) eTpu_Channel_Timestamp \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(boolean,    AUTOMATIC) bOverflow \
)
{
    VAR(eTPU_ModuleInfo,    AUTOMATIC) sInfo;
    VAR(boolean,            AUTOMATIC) bRetFlag = (boolean)TRUE;
    VAR(uint8,              AUTOMATIC) u8CapturedWords = (uint8)1;
    VAR(uint32,             AUTOMATIC) u32CapturedVaule;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        u32CapturedVaule = (uint32)ETPU_LLD_IC_Read_Final_Time(sInfo.u8Instance, sInfo.u8Passage);

        eTpu_Wrapper_Channel_Timestamp(u8Module, u8Channel, \
            u8CapturedWords, &u32CapturedVaule, bOverflow);
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (ICU_STARTTIMESTAMP_API == STD_ON) */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32, ICU_CODE) eTpu_Channel_GetStartAddress \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(eTPU_ModuleInfo,    AUTOMATIC) sInfo;
    VAR(boolean,            AUTOMATIC) bRetFlag = (boolean)TRUE;
    VAR(uint32,             AUTOMATIC) u32Address = 0U;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        u32Address = ETPU_LLD_IC_GetCountAddress(sInfo.u8Instance, sInfo.u8Passage);
    }

    return u32Address;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_ENABLEEDGECOUNT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_ResetEdgeCount \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(eTPU_ModuleInfo, AUTOMATIC) sInfo;
    VAR(boolean,    AUTOMATIC) bRetFlag = (boolean)TRUE;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        SchM_Enter_Icu_EXCLUSIVE_AREA_57();

        /* Disable interrupt */
        ETPU_LLD_ChannelIntMaskDisable(sInfo.u8Instance, sInfo.u8Passage);
        /* Reset Counter Register (CNT) */
        ETPU_LLD_IC_SetTransCount(sInfo.u8Instance, sInfo.u8Passage, 0U);
        /* Reset capture value */
        ETPU_LLD_IC_SetFinalTime(sInfo.u8Instance, sInfo.u8Passage, 0U);
        /* Clear interrupt flags */
        ETPU_LLD_ClearChannelInterruptFlag(sInfo.u8Instance, sInfo.u8Passage);
        ETPU_LLD_ClearChannelInterruptOverflowFlag(sInfo.u8Instance, sInfo.u8Passage);

        SchM_Exit_Icu_EXCLUSIVE_AREA_57();
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_EnableEdgeCount \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(eTPU_ModuleInfo,    AUTOMATIC) sInfo;
    VAR(boolean,    AUTOMATIC) bRetFlag = (boolean)TRUE;
    VAR(uint32,     AUTOMATIC) u32ConfigData = 0UL;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        SchM_Enter_Icu_EXCLUSIVE_AREA_58();

        /* Reset capture value */
        ETPU_LLD_IC_SetFinalTime(sInfo.u8Instance, sInfo.u8Passage, 0xFFFFFFU);
        /* Clear interrupt flags */
        ETPU_LLD_ClearChannelInterruptFlag(sInfo.u8Instance, sInfo.u8Passage);
        ETPU_LLD_ClearChannelInterruptOverflowFlag(sInfo.u8Instance, sInfo.u8Passage);

        u32ConfigData = eTpu_GetChConfig(u8Module, u8Channel, ETPU_CONFIG_DATA_MEASMODE);
        u32ConfigData |= ETPU_MODE_EDGE_COUNTER;
        eTpu_SetChConfig(u8Module, u8Channel, \
            ETPU_CONFIG_DATA_MEASMODE, \
            (uint32)u32ConfigData);

        SchM_Exit_Icu_EXCLUSIVE_AREA_58();
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_DisableEdgeCount \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(eTPU_ModuleInfo, AUTOMATIC) sInfo;
    VAR(boolean,    AUTOMATIC) bRetFlag = (boolean)TRUE;
    VAR(uint32,     AUTOMATIC) u32ConfigData = 0UL;
    VAR(uint32,     AUTOMATIC) u32CurrentEdgeValue = 0UL;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        SchM_Enter_Icu_EXCLUSIVE_AREA_59();

        /* Disable interrupt */
        ETPU_LLD_ChannelIntMaskDisable(sInfo.u8Instance, sInfo.u8Passage); /* polyspace RTE:NIVL */
        /* Get counter */
        u32CurrentEdgeValue = (uint32)ETPU_LLD_IC_Read_Trans_Count(sInfo.u8Instance, sInfo.u8Passage);

        eTpu_SetEdgeValue(u8Module, u8Channel, u32CurrentEdgeValue);

        /* Clear meas mode */
        u32ConfigData = eTpu_GetChConfig(u8Module, u8Channel, ETPU_CONFIG_DATA_MEASMODE);
        u32ConfigData &= ~ETPU_MODE_EDGE_COUNTER;
        eTpu_SetChConfig(u8Module, u8Channel, \
                ETPU_CONFIG_DATA_MEASMODE, \
                (uint32)u32ConfigData);

        SchM_Exit_Icu_EXCLUSIVE_AREA_59();
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (uint32, ICU_CODE) eTpu_Channel_GetEdgeNumbers \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(eTPU_ModuleInfo, AUTOMATIC) sInfo;
    VAR(boolean,    AUTOMATIC) bRetFlag = (boolean)TRUE;
    VAR(uint32,     AUTOMATIC) u32CurrentEdgeValue = 0UL;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        /* Get counter */
        u32CurrentEdgeValue = (uint32)ETPU_LLD_IC_Read_Trans_Count(sInfo.u8Instance, sInfo.u8Passage);
    }

    return u32CurrentEdgeValue;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (ICU_ENABLEEDGECOUNT_API == STD_ON) */

#if (ICU_STARTSIGNALMEASUREMENT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_StartSignalMeasurement \
( \
    VAR(uint8,                    AUTOMATIC) u8Module, \
    VAR(uint8,                    AUTOMATIC) u8Channel, \
    VAR(eTPU_EdgeTrigModeType,    AUTOMATIC) eActivation, \
    VAR(uint16,                   AUTOMATIC) nMeasProperty, \
    VAR(boolean,                  AUTOMATIC) bDmaSupport, \
    VAR(boolean,                  AUTOMATIC) bWithoutInterrupt \
)
{
    VAR(uint32,     AUTOMATIC) u32ConfigData = 0UL;
    VAR(eTPU_ModuleInfo, AUTOMATIC) sInfo;
    VAR(boolean,    AUTOMATIC) bRetFlag = (boolean)TRUE;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        /* Reset capture and timestart */
        eTpu_SetPulseWidth(u8Module, u8Channel, (uint8)0U);
        eTpu_SetTimeStart(u8Module, u8Channel, (uint8)0U);
        /* Disable interrupt */
        ETPU_LLD_ChannelIntMaskDisable(sInfo.u8Instance, sInfo.u8Passage); /* polyspace RTE:NIVL */
        /* Clear interrupt flags */
        ETPU_LLD_ClearChannelInterruptFlag(sInfo.u8Instance, sInfo.u8Passage);
        ETPU_LLD_ClearChannelInterruptOverflowFlag(sInfo.u8Instance, sInfo.u8Passage);

        SchM_Enter_Icu_EXCLUSIVE_AREA_60();

        /* Check dma mode */
        if((boolean)TRUE == bDmaSupport)
        {
            /* Clear interrupt dma flags */
            ETPU_LLD_ClearChannelDMAFlag(sInfo.u8Instance, sInfo.u8Passage);
            ETPU_LLD_ClearChannelDMAOverflowFlag(sInfo.u8Instance, sInfo.u8Passage);
            /* Enable DMA */
            ETPU_LLD_ChannelDMAMaskEnable(sInfo.u8Instance, sInfo.u8Passage);
        }

        /* Clear Counter (CNT) */
        ETPU_LLD_IC_SetTransCount(sInfo.u8Instance, sInfo.u8Passage, 0U);

        /* Clear the counter for signal measurement */
        eTpu_SetIntCounter(u8Module, u8Channel, (uint8)0U);
        /* Set max count to 1 for first interrupt */
        ETPU_LLD_IC_SetIterCount(sInfo.u8Instance, sInfo.u8Passage, 1U);
        /* Set trigger edge */
        eTpu_Channel_SetActivationCondition(u8Module, u8Channel, eActivation);

        if ((boolean)TRUE != bWithoutInterrupt)
        {
            /* Enable interrupt */
            ETPU_LLD_ChannelIntMaskEnable(sInfo.u8Instance, sInfo.u8Passage);
        }

        /* Set Channel meas mode */
        u32ConfigData = eTpu_GetChConfig(u8Module, u8Channel, ETPU_CONFIG_DATA_MEASMODE);
        u32ConfigData |= ETPU_MODE_SIGNAL_MEASUREMENT;
        eTpu_SetChConfig(u8Module, u8Channel, \
                ETPU_CONFIG_DATA_MEASMODE, \
                (uint32)u32ConfigData);

        eTpu_SetChConfig(u8Module, u8Channel, \
                ETPU_CONFIG_DATA_PROPERTY, \
                (uint32)nMeasProperty);

        SchM_Exit_Icu_EXCLUSIVE_AREA_60();
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_StopSignalMeasurement \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint32,     AUTOMATIC) u32ConfigData = 0UL;
    VAR(eTPU_ModuleInfo, AUTOMATIC) sInfo;
    VAR(boolean,    AUTOMATIC) bRetFlag = (boolean)TRUE;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        SchM_Enter_Icu_EXCLUSIVE_AREA_61();

        /* Disable interrupt */
        ETPU_LLD_ChannelIntMaskDisable(sInfo.u8Instance, sInfo.u8Passage); /* polyspace RTE:NIVL */

        /* Clear Channel meas mode */
        u32ConfigData = eTpu_GetChConfig(u8Module, u8Channel, ETPU_CONFIG_DATA_MEASMODE);
        u32ConfigData &= ~ETPU_MODE_SIGNAL_MEASUREMENT;
        eTpu_SetChConfig(u8Module, u8Channel, \
                ETPU_CONFIG_DATA_MEASMODE, \
                (uint32)u32ConfigData);

        /* Clear Channel Property */
        eTpu_SetChConfig(u8Module, u8Channel, \
                ETPU_CONFIG_DATA_PROPERTY, \
                0UL);

        SchM_Exit_Icu_EXCLUSIVE_AREA_61();
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
static FUNC(void, ICU_CODE) eTpu_Channel_SignalMeasurement \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(boolean, AUTOMATIC) bOverflow \
)
{
    VAR(eTPU_ModuleInfo, ICU_VAR) sInfo;
    VAR(boolean,    AUTOMATIC) bRetFlag = (boolean)TRUE;
    VAR(uint32,     AUTOMATIC) u32ActivePulseWidth;
    VAR(uint32,     AUTOMATIC) u32Period;
    VAR(uint32,     AUTOMATIC) u32ChannelTempA;
    VAR(uint32,     AUTOMATIC) u32ChannelTempB;
    VAR(uint32,     AUTOMATIC) u32ChannelStartTime;
    VAR(uint32,     AUTOMATIC) u32MeasurementProperty = \
        eTpu_GetChConfig(u8Module, u8Channel, ETPU_CONFIG_DATA_PROPERTY);
    VAR(uint32,      AUTOMATIC) u8IntFlag;
    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);

    if (bRetFlag == (boolean)TRUE)
    {
        u8IntFlag = eTpu_GetIntCounter(u8Module, u8Channel);
        if (u8IntFlag == 0U)
        {
            if ((u32MeasurementProperty == ETPU_MEAS_TYPE_LOW_TIME) || \
                (u32MeasurementProperty == ETPU_MEAS_TYPE_HIGH_TIME))
            {
                /* set to step 1 */
                eTpu_SetIntCounter(u8Module, u8Channel, (uint8)1U);
                eTpu_Channel_SetActivationCondition(u8Module, u8Channel, ETPU_IC_OPPOSITE);
            }
            else
            {
                /* set to step 2 */
                eTpu_SetIntCounter(u8Module, u8Channel, (uint8)2U);
                ETPU_LLD_IC_SetIterCount(sInfo.u8Instance, sInfo.u8Passage, 2U);
                eTpu_Channel_SetActivationCondition(u8Module, u8Channel, ETPU_IC_ANY_EDGE);
            }
            (void)ETPU_LLD_IC_Read_Last_Time(sInfo.u8Instance, sInfo.u8Passage);
            u32ChannelTempB = (uint32)ETPU_LLD_IC_Read_Final_Time(sInfo.u8Instance, sInfo.u8Passage);
            eTpu_SetTimeStart(u8Module, u8Channel, u32ChannelTempB);
        }
        else if (u8IntFlag == 1U)
        {
            u32ChannelStartTime = eTpu_GetTimeStart(u8Module, u8Channel);

            /* step 1 */
            if ((u32MeasurementProperty == ETPU_MEAS_TYPE_LOW_TIME) || \
                (u32MeasurementProperty == ETPU_MEAS_TYPE_HIGH_TIME))
            {
                u32ChannelTempA = (uint32)ETPU_LLD_IC_Read_Final_Time(sInfo.u8Instance, sInfo.u8Passage);
                eTpu_SetIntCounter(u8Module, u8Channel, (uint8)0U);
                u32ActivePulseWidth = ((u32ChannelTempA + ETPU_TIME_COUT_MAX) - u32ChannelStartTime) % ETPU_TIME_COUT_MAX;
                eTpu_Wrapper_Channel_SignalMeasurement(u8Module, \
                            u8Channel, \
                            (Icu_ValueType)u32ActivePulseWidth, \
                            0UL, \
                            bOverflow);
                eTpu_Channel_SetActivationCondition(u8Module, u8Channel, ETPU_IC_OPPOSITE);
            }
            else
            {
            	(void)u32ChannelTempA; /* PRQA S 2961 */
            }
        }
        else if (u8IntFlag == 2U)
        {
            /* step 2 */
            eTpu_Channel_SetActivationCondition(u8Module, u8Channel, ETPU_IC_ANY_EDGE);
            u32ChannelStartTime = eTpu_GetTimeStart(u8Module, u8Channel);
            u32ChannelTempA = (uint32)ETPU_LLD_IC_Read_Last_Time(sInfo.u8Instance, sInfo.u8Passage);
            u32ChannelTempB = (uint32)ETPU_LLD_IC_Read_Final_Time(sInfo.u8Instance, sInfo.u8Passage);

            u32ActivePulseWidth = ((u32ChannelTempA + ETPU_TIME_COUT_MAX) - u32ChannelStartTime) % ETPU_TIME_COUT_MAX;
            u32Period = ((u32ChannelTempB + ETPU_TIME_COUT_MAX) - u32ChannelStartTime) % ETPU_TIME_COUT_MAX;
            eTpu_SetTimeStart(u8Module, u8Channel, u32ChannelTempB);

            if (u32MeasurementProperty == ETPU_MEAS_TYPE_DUTY_CYCLE)
            {
                eTpu_Wrapper_Channel_SignalMeasurement(u8Module, \
                            u8Channel, \
                            (Icu_ValueType)u32ActivePulseWidth, \
                            (Icu_ValueType)u32Period, \
                            bOverflow);
            }
            else if (u32MeasurementProperty == ETPU_MEAS_TYPE_PERIOD_TIME)
            {
                eTpu_Wrapper_Channel_SignalMeasurement(u8Module, \
                            u8Channel, \
                            0UL, \
                            (Icu_ValueType)u32Period, \
                            bOverflow);
            }
            else
            {
                /* do nothing */
                eTpu_SetIntCounter(u8Module, u8Channel, (uint8)0U);
            }
        }
        else
        {
            /* do nothing */
        	(void)u32ChannelTempA;
            eTpu_SetIntCounter(u8Module, u8Channel, (uint8)0U);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif  /* (ICU_STARTSIGNALMEASUREMENT_API == STD_ON) */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (boolean, ICU_CODE) eTpu_Channel_GetInputState \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(eTPU_ModuleInfo, AUTOMATIC) sInfo;
    VAR(boolean, AUTOMATIC) bRetFlag = (boolean)TRUE;
    VAR(boolean, AUTOMATIC) bReturnValue = (boolean)FALSE;
    VAR(uint8,   AUTOMATIC) u8IntEn = (uint8)0U;
    VAR(uint8,   AUTOMATIC) u8IntFlag = (uint8)0U;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        /* Interrupt mode */
        u8IntEn = ETPU_LLD_GetChannelIntMaskStatus(sInfo.u8Instance, sInfo.u8Passage);
        u8IntFlag = ETPU_LLD_GetInterruptFlag(sInfo.u8Instance, sInfo.u8Passage);

        if ((u8IntEn == (uint8)0U) && (u8IntFlag == (uint8)1U))
        {
            bReturnValue = (boolean)TRUE;
        }
    }

    return bReturnValue;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (boolean, ICU_CODE) eTpu_Channel_GetOverflow \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(boolean,            AUTOMATIC) bRetrunValue = (boolean)FALSE;
    VAR(eTPU_ModuleInfo,    AUTOMATIC) sInfo;
    VAR(boolean,            AUTOMATIC) bRetFlag = (boolean)TRUE;
    VAR(uint8,              AUTOMATIC) u8OverFlow = (uint8)0U;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        u8OverFlow = ETPU_LLD_GetInterruptOverflowFlag(sInfo.u8Instance, sInfo.u8Passage);
        bRetrunValue = (u8OverFlow == (uint8)0) ? (boolean)FALSE : (boolean)TRUE;
    }

    return bRetrunValue;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(boolean, ICU_CODE) eTpu_Channel_GetInputLevel \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
)
{
    VAR(eTPU_ModuleInfo,    AUTOMATIC) sInfo;
    VAR(boolean,            AUTOMATIC) bRetFlag = (boolean)TRUE;
    VAR(boolean,            AUTOMATIC) bReturnValue = (boolean)FALSE;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        if (ETPU_LLD_GetChannelInputStatus(sInfo.u8Instance, sInfo.u8Passage) == (uint8)1U)
        {
            bReturnValue = (boolean)TRUE;
        }
    }

    return bReturnValue;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32, ICU_CODE) eTpu_Channel_GetFinalTime \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
)
{
    VAR(eTPU_ModuleInfo,    AUTOMATIC) sInfo;
    VAR(boolean,            AUTOMATIC) bRetFlag = (boolean)TRUE;
    VAR(uint32 ,            AUTOMATIC) u32ReturnValue = 0UL;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        u32ReturnValue = (uint32)ETPU_LLD_IC_Read_Final_Time(sInfo.u8Instance, sInfo.u8Passage);
    }

    return u32ReturnValue;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_ProcessCommonIrq \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
)
{
    VAR(boolean,    AUTOMATIC) bOverflow = (boolean)FALSE;
    VAR(uint32,     AUTOMATIC) U32Inited = 0U;
    VAR(eTPU_ModuleInfo,    AUTOMATIC) sInfo;
    VAR(boolean,    AUTOMATIC) bRetFlag = (boolean)TRUE;
    VAR(uint32,     AUTOMATIC) measMode;

    bRetFlag = eTpu_GetModuleInfo(u8Module, u8Channel, &sInfo);
    if (bRetFlag == (boolean)TRUE)
    {
        U32Inited = eTpu_GetChConfig(u8Module, u8Channel, ETPU_CONFIG_DATA_INITED);
    }

    if (U32Inited == 1U)
    {
        bOverflow = (ETPU_LLD_GetInterruptOverflowFlag(sInfo.u8Instance, sInfo.u8Passage) != 0U) ? (boolean)TRUE : (boolean)FALSE; /* polyspace RTE:NIVL */
        measMode = eTpu_GetChConfig(u8Module, u8Channel, ETPU_CONFIG_DATA_MEASMODE);
        switch (measMode)
        {
        case ETPU_MODE_SIGNAL_EDGE_DETECT:
        {
            eTpu_Wrapper_Channel_ReportEvents(u8Module, u8Channel, bOverflow);
            break;
        }
        case ETPU_MODE_SIGNAL_MEASUREMENT:
        {
#if (ICU_STARTSIGNALMEASUREMENT_API == STD_ON)
            eTpu_Channel_SignalMeasurement(u8Module, u8Channel, bOverflow);
#endif
            break;
        }
        case ETPU_MODETIMESTAMP_WITHOUT_DMA:
        {
            eTpu_Channel_Timestamp(u8Module, u8Channel, bOverflow);
            break;
        }
        case ETPU_MODE_TIMESTAMP_WITH_DMA:
        {
            eTpu_Wrapper_Channel_ReportWakeupAndOverflow(u8Module, u8Channel, bOverflow);
            break;
        }
        case ETPU_MODE_EDGE_COUNTER:
        {
            eTpu_Wrapper_Channel_ReportWakeupAndOverflow(u8Module, u8Channel, (boolean)TRUE);
            break;
        }
        default:
        {
            /* Error meas mode, do nothing */
            break;
        }
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_ETPU)) */
#ifdef __cplusplus
}
#endif


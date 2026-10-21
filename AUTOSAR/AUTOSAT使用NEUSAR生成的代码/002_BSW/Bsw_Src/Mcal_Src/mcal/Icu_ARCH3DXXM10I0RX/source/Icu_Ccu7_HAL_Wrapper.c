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
/* PRQA S 0380,3332,2844,2983,1258,2053,2052,4424,3393,1259 EOF */
/* PRQA S 3401,3432,1006,1840,3395,4397,4342,0570,1843,2016 EOF */
/**
*   @file    Icu_Ccu7_HAL_Wrapper.c
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
#include "Icu_Ccu7_Wrapper.h"
#include "Icu_Ccu7_HAL_Wrapper.h"
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
#include "Ccu7_HAL_Irq.h"
#include "Icu_Irq.h"
#include "SchM_Icu.h"
/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_Ccu7_HAL_WRAPPER_VENDOR_ID_C                   176

#define ICU_Ccu7_HAL_WRAPPER_MAJOR_VER_C                   4
#define ICU_Ccu7_HAL_WRAPPER_MINOR_VER_C                   4
#define ICU_Ccu7_HAL_WRAPPER_REVISION_VER_C                0

#define ICU_Ccu7_HAL_WRAPPER_SW_MAJOR_VER_C                3
#define ICU_Ccu7_HAL_WRAPPER_SW_MINOR_VER_C                0
#define ICU_Ccu7_HAL_WRAPPER_SW_PATCH_VER_C                0

#if (ICU_Ccu7_HAL_WRAPPER_VENDOR_ID_C != ICU_Ccu7_HAL_WRAPPER_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_Ccu7_HAL_WRAPPER_MAJOR_VER_C != ICU_Ccu7_HAL_WRAPPER_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_Ccu7_HAL_WRAPPER_MINOR_VER_C != ICU_Ccu7_HAL_WRAPPER_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_Ccu7_HAL_WRAPPER_REVISION_VER_C != ICU_Ccu7_HAL_WRAPPER_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_Ccu7_HAL_WRAPPER_SW_MAJOR_VER_C != ICU_Ccu7_HAL_WRAPPER_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_Ccu7_HAL_WRAPPER_SW_MINOR_VER_C != ICU_Ccu7_HAL_WRAPPER_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_Ccu7_HAL_WRAPPER_SW_PATCH_VER_C != ICU_Ccu7_HAL_WRAPPER_SW_PATCH_VER_H)
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
#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
#define ICU_START_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"
static VAR(Icu_ValueType, ICU_VAR) sIcu_Ccu7_aInt_Counter[ICU_CORE_NUM][8];
static VAR(Icu_ValueType, ICU_VAR) sIcu_Ccu7_TimeStart[ICU_CORE_NUM][8];
#define ICU_STOP_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"
#endif
#define ICU_START_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"
static VAR(Ccu7_Channel_ConfigData, ICU_VAR) sIcu_Ccu7_ChConfig[ICU_CCU7_INSTANCE_MAX*ICU_CCU7_MODULE_CHANNEL_MAX + 1];
#define ICU_STOP_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"
/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, ICU_CODE) Ccu7_SetChConfig
(
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(uint32,     AUTOMATIC) u32Mask, \
    VAR(uint32,     AUTOMATIC) u32Value \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = ICU_CCU7_MODU_CHAN_COMBIN(u8Module, u8Channel);

    switch (u32Mask)
    {
    case CCU7_CONFIG_DATA_INITED:
    {
        sIcu_Ccu7_ChConfig[u8ChannelIdx].bits.inited = (uint8)u32Value;/* polyspace RTE:OBAI */
        break;
    }
    case CCU7_CONFIG_DATA_MEASMODE:
    {
        sIcu_Ccu7_ChConfig[u8ChannelIdx].bits.mode = (uint8)u32Value;/* polyspace RTE:OBAI */
        break;
    }
    case CCU7_CONFIG_DATA_OPMODE:
    {
        sIcu_Ccu7_ChConfig[u8ChannelIdx].bits.opmode = (uint8)u32Value;/* polyspace RTE:OBAI */
        break;
    }
    case CCU7_CONFIG_DATA_DMA:
    {
        sIcu_Ccu7_ChConfig[u8ChannelIdx].bits.dma = (uint8)u32Value;/* polyspace RTE:OBAI */
        break;
    }
    case CCU7_CONFIG_DATA_PROPERTY:
    {
        sIcu_Ccu7_ChConfig[u8ChannelIdx].bits.property = (uint8)u32Value;/* polyspace RTE:OBAI */
        break;
    }
    case CCU7_CONFIG_DATA_CLEAR:
    {
        sIcu_Ccu7_ChConfig[u8ChannelIdx].data = u32Value;/* polyspace RTE:OBAI */
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
LOCAL_INLINE FUNC(uint32, ICU_CODE) Ccu7_GetChConfig
(
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(uint32,     AUTOMATIC) u32Mask \
)
{
    VAR(uint32,     AUTOMATIC) u32RetrunValue = (0xFFFFFFFFU);
    VAR(uint8,      AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = ICU_CCU7_MODU_CHAN_COMBIN(u8Module, u8Channel);

    switch (u32Mask)
    {
    case CCU7_CONFIG_DATA_INITED:
    {
        u32RetrunValue = sIcu_Ccu7_ChConfig[u8ChannelIdx].bits.inited;
        break;
    }
    case CCU7_CONFIG_DATA_MEASMODE:
    {
        u32RetrunValue = sIcu_Ccu7_ChConfig[u8ChannelIdx].bits.mode;/* polyspace RTE:OBAI */
        break;
    }
    case CCU7_CONFIG_DATA_OPMODE:
    {
        u32RetrunValue = sIcu_Ccu7_ChConfig[u8ChannelIdx].bits.opmode;
        break;
    }
    case CCU7_CONFIG_DATA_DMA:
    {
        u32RetrunValue = sIcu_Ccu7_ChConfig[u8ChannelIdx].bits.dma;
        break;
    }
    case CCU7_CONFIG_DATA_PROPERTY:
    {
        u32RetrunValue = sIcu_Ccu7_ChConfig[u8ChannelIdx].bits.property;
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

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
static FUNC(void, ICU_CODE) Ccu7_SetIntCounter \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(uint8, AUTOMATIC) u8Value \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = ICU_CCU7_MODU_CHAN_COMBIN(u8Module, u8Channel);

    sIcu_Ccu7_aInt_Counter[GetCoreID()][u8ChannelIdx] = u8Value;/* GetCoreID *//* polyspace RTE:OBAI,NIV */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
static FUNC(uint32, ICU_CODE) Ccu7_GetIntCounter \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = ICU_CCU7_MODU_CHAN_COMBIN(u8Module, u8Channel);

    return sIcu_Ccu7_aInt_Counter[GetCoreID()][u8ChannelIdx];/* GetCoreID *//* polyspace RTE:OBAI,NIV */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
static FUNC(void, ICU_CODE) Ccu7_SetTimeStart \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(uint32, AUTOMATIC) u32Value \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = ICU_CCU7_MODU_CHAN_COMBIN(u8Module, u8Channel);

    sIcu_Ccu7_TimeStart[GetCoreID()][u8ChannelIdx] = u32Value;/* GetCoreID *//* polyspace RTE:OBAI,NIV */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
static FUNC(uint32, ICU_CODE) Ccu7_GetTimeStart \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = ICU_CCU7_MODU_CHAN_COMBIN(u8Module, u8Channel);

    return sIcu_Ccu7_TimeStart[GetCoreID()][u8ChannelIdx];/* GetCoreID *//* polyspace RTE:OBAI,NIV */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC (void, ICU_CODE) Icu_Ccu7_Wrapper_Channel_SignalMeasurement \
( \
    VAR(uint8,          AUTOMATIC) u8Module, \
    VAR(uint8,          AUTOMATIC) u8Channel, \
    VAR(Icu_ValueType,  AUTOMATIC) activePulseWidth, \
    VAR(Icu_ValueType,  AUTOMATIC) period, \
    VAR(boolean,        AUTOMATIC) bOverflow \
)
{
    VAR(Icu_ChannelType, ICU_VAR) Instance = Icu_Ccu7_Wrapper_GetInstance(u8Module, u8Channel);

    ICU_SignalMeasurement(Instance, activePulseWidth, period, bOverflow);

}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (ICU_SIGNAL_MEASUREMENT_API == STD_ON) */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_Init \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel, \
    P2VAR(Ccu7_Channel_Config, AUTOMATIC, ICU_CODE) pCcu7ChannelConfig \
)
{
    /* init hardware module */
    if(ICU_CCU7_LLD_GetCLCDISS(u8Module) == 0x1u)
    {
        ICU_CCU7_LLD_SetCLCDISR(u8Module, 0x0u);
    }
    /* enable Timer12 available */
    if(ICU_CCU7_LLD_GetMCFG(u8Module, ICU_Ccu7_TimerId_t12) == 0x0u)
    {
        ICU_CCU7_LLD_SetMCFG(u8Module, ICU_Ccu7_TimerId_t12);
    }
    /* Timer T12 Run Reset */
    ICU_CCU7_LLD_SetTCTR4(u8Module, ICU_CCU7_TCTR4_T12RR_SET_MASK);
    /* Clear the any interrupt status flags */
    ICU_CCU7_LLD_ClrCc7xFlag(u8Module, u8Channel, ICU_CCU7X_RF);
    /* disable interrupt register*/
    ICU_CCU7_LLD_ClrCc7xIntEn(u8Module, u8Channel, ICU_CCU7X_RF);
    /* set INP register*/
    ICU_CCU7_LLD_SetInpCc7x(u8Module, u8Channel, pCcu7ChannelConfig->sChannelParam.IntNodePointerReg);
    /* PISEL */
    ICU_CCU7_LLD_SetPISEL0(u8Module, u8Channel, pCcu7ChannelConfig->sChannelParam.PortInSelReg0);
    /* T12MSEL */
    ICU_CCU7_LLD_SetT12MSEL(u8Module, u8Channel, pCcu7ChannelConfig->sChannelParam.TimerModeSelectReg);
    /* T1xPR register */
    ICU_CCU7_LLD_SetT12CNT(u8Module, pCcu7ChannelConfig->sChannelParam.TimerCntReg);
    /* TCTR0.T12PRE TCTR0.CTM */
    ICU_CCU7_LLD_SetTCTR0(u8Module, pCcu7ChannelConfig->sChannelParam.TimerCtrlReg0);
    ICU_CCU7_LLD_SetTCTR4(u8Module, ICU_CCU7_TCTR4_T12RS_SET_MASK);
    ICU_CCU7_LLD_SetT12PR(u8Module, pCcu7ChannelConfig->sChannelParam.TimerPeriodReg);
    ICU_CCU7_LLD_SetTCTR4(u8Module, ICU_CCU7_TCTR4_T12STR_SET_MASK);

    Ccu7_SetChConfig(u8Module, (uint8)u8Channel, CCU7_CONFIG_DATA_INITED, 1U);
	Ccu7_SetChConfig(u8Module, (uint8)u8Channel, CCU7_CONFIG_DATA_OPMODE, pCcu7ChannelConfig->sChannelParam.TimerModeSelectReg);
	Ccu7_SetChConfig(u8Module, (uint8)u8Channel, CCU7_CONFIG_DATA_DMA, pCcu7ChannelConfig->bDmaSupport);

}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_DeInit \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    /* TCTR0.T12PRE TCTR0.CTM */
    ICU_CCU7_LLD_SetTCTR0(u8Module, 0u);
    /* Clear the any interrupt status flags */
    ICU_CCU7_LLD_ClrCc7xFlag(u8Module, u8Channel, ICU_CCU7X_RF);
//    ICU_CCU7_LLD_ClrT12pmFlag(u8Module);
    /* IEN register*/
    ICU_CCU7_LLD_ClrCc7xIntEn(u8Module, u8Channel, ICU_CCU7X_RF);
//    ICU_CCU7_LLD_ClrT12pmIntEn(u8Module);
    /* INP register*/
    ICU_CCU7_LLD_SetInpT12(u8Module, 2);
    ICU_CCU7_LLD_SetInpCc7x(u8Module, u8Channel, 0);
    /* PISEL */
    ICU_CCU7_LLD_SetPISEL0(u8Module, u8Channel, 0);
    /* T12MSEL */
    ICU_CCU7_LLD_SetT12MSEL(u8Module, u8Channel, 0);
    /* T1xPR register */
    ICU_CCU7_LLD_SetT12PR(u8Module, 0);
    ICU_CCU7_LLD_SetT12CNT(u8Module, 0);
    Ccu7_SetChConfig(u8Module, (uint8)u8Channel, CCU7_CONFIG_DATA_CLEAR, 0U);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_EnIrq \
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(Ccu7_Edge_Type, AUTOMATIC) edge
)
{
    uint8 FlagStatus;
    uint16 Ccu7_Instance;
    Ccu7_Instance = Icu_Ccu7_Wrapper_GetInstance(u8Module, u8Channel);
    FlagStatus = ICU_CCU7_LLD_GetIsCC7xR(u8Module, u8Channel);
    ICU_CCU7_LLD_ClrCc7xFlag(u8Module, u8Channel, ICU_CCU7X_RF);
    ICU_CCU7_LLD_SetCc7xIntEn(u8Module, u8Channel, edge);
    if(FlagStatus == (uint8)edge)
    {
        sIcu_ChannelInfo[GetCoreID()][Ccu7_Instance].u32Icu_ChannelEdgeDetection = ICU_ACTIVE;/* polyspace RTE:OBAI */
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_DisIrq \
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel
)
{
    ICU_CCU7_LLD_ClrCc7xIntEn(u8Module, u8Channel, ICU_CCU7X_RF);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_TIMESTAMP_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_StartTimestamp \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(Icu_ActivationType,      AUTOMATIC) ActiveEdge
)
{
    VAR(Ccu7_Edge_Type, AUTOMATIC) edge;
    VAR(uint32,     AUTOMATIC) u32ConfigData = (uint32)0U;

    if(ActiveEdge == ICU_RISING_EDGE)
    {
        edge = ICU_CCU7X_R;
    }else if(ActiveEdge == ICU_FALLING_EDGE)
    {
        edge = ICU_CCU7X_F;
    }else
    {
        edge = ICU_CCU7X_RF;
    }

    SchM_Enter_Icu_EXCLUSIVE_AREA_55();

    /* Clear interrupt flags */
    ICU_CCU7_LLD_ClrCc7xFlag(u8Module, u8Channel, ICU_CCU7X_RF);

    /* Enable interrupt */
    ICU_CCU7_LLD_SetT12MSEL(u8Module, u8Channel, (uint8)ICU_CCU_CAPTURE_MODE1|(uint8)edge);
    ICU_CCU7_LLD_SetCc7xIntEn(u8Module, u8Channel, edge);
    SchM_Exit_Icu_EXCLUSIVE_AREA_55();
    /* Set Channel meas mode */
    u32ConfigData = Ccu7_GetChConfig(u8Module, u8Channel, (uint32)CCU7_CONFIG_DATA_MEASMODE);
    u32ConfigData |= CCU7_MODETIMESTAMP_WITHOUT_DMA;
    Ccu7_SetChConfig(u8Module, u8Channel, \
            (uint32)CCU7_CONFIG_DATA_MEASMODE, \
            (uint32)u32ConfigData);

}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_StopTimestamp \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint32,             AUTOMATIC) u32ConfigData;

    SchM_Enter_Icu_EXCLUSIVE_AREA_56();

    ICU_CCU7_LLD_SetT12MSEL(u8Module, u8Channel, 0xF);

    /* Clear meas mode */
    u32ConfigData = Ccu7_GetChConfig(u8Module, u8Channel, (uint32)CCU7_CONFIG_DATA_MEASMODE);
    u32ConfigData &= ~CCU7_MODETIMESTAMP_WITHOUT_DMA;
    Ccu7_SetChConfig(u8Module, u8Channel, \
        (uint32)CCU7_CONFIG_DATA_MEASMODE, \
        (uint32)u32ConfigData);

    SchM_Exit_Icu_EXCLUSIVE_AREA_56();
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (ICU_TIMESTAMP_API == STD_ON) */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_EnableEdgeDetection \
( \
        VAR(uint8,      AUTOMATIC) u8Module, \
        VAR(uint8,      AUTOMATIC) u8Channel, \
        VAR(Icu_ActivationType,      AUTOMATIC) ActiveEdge
)
{
    VAR(Ccu7_Edge_Type, AUTOMATIC) edge;
    VAR(uint32,     AUTOMATIC) u32ConfigData = (uint32)0U;

    if(ActiveEdge == ICU_RISING_EDGE)
    {
        edge = ICU_CCU7X_R;
    }else if(ActiveEdge == ICU_FALLING_EDGE)
    {
        edge = ICU_CCU7X_F;
    }else
    {
        edge = ICU_CCU7X_RF;
    }

    SchM_Enter_Icu_EXCLUSIVE_AREA_53();

    /* Clear interrupt flags */
    ICU_CCU7_LLD_ClrCc7xFlag(u8Module, u8Channel, ICU_CCU7X_RF);

    /* Enable interrupt */
    ICU_CCU7_LLD_SetT12MSEL(u8Module, u8Channel, (uint8)ICU_CCU_CAPTURE_MODE1|(uint8)edge);
    ICU_CCU7_LLD_SetCc7xIntEn(u8Module, u8Channel, edge);

    SchM_Exit_Icu_EXCLUSIVE_AREA_53();

    /* Set Channel meas mode */
    u32ConfigData = Ccu7_GetChConfig(u8Module, u8Channel, (uint32)CCU7_CONFIG_DATA_MEASMODE);
    u32ConfigData |= CCU7_MODE_SIGNAL_EDGE_DETECT;
    Ccu7_SetChConfig(u8Module, u8Channel, \
            (uint32)CCU7_CONFIG_DATA_MEASMODE, \
            (uint32)u32ConfigData);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_DisableEdgeDetection \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint32,             AUTOMATIC) u32ConfigData;


    SchM_Enter_Icu_EXCLUSIVE_AREA_54();

    ICU_CCU7_LLD_SetT12MSEL(u8Module, u8Channel, 0xF);

    /* Clear meas mode */
    u32ConfigData = Ccu7_GetChConfig(u8Module, u8Channel, (uint32)CCU7_CONFIG_DATA_MEASMODE);
    u32ConfigData &= ~CCU7_MODE_SIGNAL_EDGE_DETECT;
    Ccu7_SetChConfig(u8Module, u8Channel, \
        (uint32)CCU7_CONFIG_DATA_MEASMODE, \
        (uint32)u32ConfigData);

    SchM_Exit_Icu_EXCLUSIVE_AREA_54();

}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_StartSignalMeasurement \
( \
    VAR(uint8,                    AUTOMATIC) u8Module, \
    VAR(uint8,                    AUTOMATIC) u8Channel, \
    VAR(Ccu7_Edge_Type,           AUTOMATIC) eActivation, \
    VAR(uint16,                   AUTOMATIC) nMeasProperty
)
{
    VAR(uint32,     AUTOMATIC) u32ConfigData = (uint32)0U;
    VAR(Ccu7_Edge_Type,     AUTOMATIC) ccuEdge = (Ccu7_Edge_Type)1U;

    SchM_Enter_Icu_EXCLUSIVE_AREA_60();

    ICU_CCU7_LLD_SetT12MSEL(u8Module, u8Channel, 0x0);

    ICU_CCU7_LLD_ClrCC7xSR(u8Module, u8Channel);

    ICU_CCU7_LLD_SetTimerShadowTransfer(u8Module);

    ICU_CCU7_LLD_ClrCc7xFlag(u8Module, u8Channel, ICU_CCU7X_RF);

    if(nMeasProperty == (uint16)ICU_HIGH_TIME)
    {
        ccuEdge = ICU_CCU7X_F;
    }else if(nMeasProperty == (uint16)ICU_LOW_TIME)
    {
        ccuEdge = ICU_CCU7X_R;
    }else if(nMeasProperty == (uint16)ICU_DUTY_CYCLE)
    {
        ccuEdge = eActivation;
    }else
    {
//        ccuEdge = 0u;
        ccuEdge = eActivation;
    }
    ICU_CCU7_LLD_ClrCc7xIntEn(u8Module, u8Channel, ICU_CCU7X_RF);
    ICU_CCU7_LLD_SetCc7xIntEn(u8Module, u8Channel, ccuEdge);

    if(nMeasProperty == (uint16)ICU_PERIOD_TIME)
    {
        if(eActivation == ICU_CCU7X_F)
        {
            ICU_CCU7_LLD_SetT12MSEL(u8Module, u8Channel, ICU_CCU_CAPTURE_MODE3);
        }else
        {
            ICU_CCU7_LLD_SetT12MSEL(u8Module, u8Channel, ICU_CCU_CAPTURE_MODE2);
        }
    }else
    {
        ICU_CCU7_LLD_SetT12MSEL(u8Module, u8Channel, ICU_CCU_CAPTURE_MODE1);
    }

    /* Set Channel meas mode */
    u32ConfigData = Ccu7_GetChConfig(u8Module, u8Channel, (uint32)CCU7_CONFIG_DATA_MEASMODE);
    u32ConfigData |= CCU7_MODE_SIGNAL_MEASUREMENT;
    Ccu7_SetChConfig(u8Module, u8Channel, \
            (uint32)CCU7_CONFIG_DATA_MEASMODE, \
            (uint32)u32ConfigData);

    Ccu7_SetChConfig(u8Module, u8Channel, \
            (uint32)CCU7_CONFIG_DATA_PROPERTY, \
            (uint32)nMeasProperty);

    SchM_Exit_Icu_EXCLUSIVE_AREA_60();
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_StopSignalMeasurement \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint32,     AUTOMATIC) u32ConfigData = (uint32)0U;

    SchM_Enter_Icu_EXCLUSIVE_AREA_61();

    ICU_CCU7_LLD_ClrCc7xIntEn(u8Module, u8Channel, ICU_CCU7X_RF);
    ICU_CCU7_LLD_SetT12MSEL(u8Module, u8Channel, 0xF);

    /* Clear Channel meas mode */
    u32ConfigData = Ccu7_GetChConfig(u8Module, u8Channel, (uint32)CCU7_CONFIG_DATA_MEASMODE);
    u32ConfigData &= ~CCU7_MODE_SIGNAL_MEASUREMENT;
    Ccu7_SetChConfig(u8Module, u8Channel, \
            (uint32)CCU7_CONFIG_DATA_MEASMODE, \
            (uint32)u32ConfigData);

    /* Clear Channel Property */
    Ccu7_SetChConfig(u8Module, u8Channel, \
            (uint32)CCU7_CONFIG_DATA_PROPERTY, \
            (uint32)0U);

    SchM_Exit_Icu_EXCLUSIVE_AREA_61();
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Ccu7_Channel_SignalMeasurement
(
    VAR(uint8, AUTOMATIC) ModuleId, \
    VAR(uint8, AUTOMATIC) Channel \
)
{
    VAR(Icu_ValueType,      AUTOMATIC) nActivePulseWidth;
    VAR(Icu_ValueType,      AUTOMATIC) nPeriod;
    VAR(uint32,             AUTOMATIC) eMeasProperty;
    VAR(uint32,             AUTOMATIC) Ccu7RRegVal;
    VAR(uint32,             AUTOMATIC) Ccu7SrRegVal;
    VAR(uint32,             AUTOMATIC) CcuDutyRegVal;
    VAR(uint32,             AUTOMATIC) CcuPeriodRegVal;
    VAR(uint32,             AUTOMATIC) CcuPeriodRegValTemp;
    VAR(uint8,             AUTOMATIC) Ccu7Edge;

    eMeasProperty = Ccu7_GetChConfig(ModuleId, Channel, (uint32)CCU7_CONFIG_DATA_PROPERTY);
    Ccu7Edge = ICU_CCU7_LLD_GetIenCC7xR(ModuleId, Channel);
    Ccu7RRegVal = ICU_CCU7_LLD_GetCC7xR(ModuleId, Channel);
    Ccu7SrRegVal = ICU_CCU7_LLD_GetCC7xSR(ModuleId, Channel);

    switch(eMeasProperty)
    {
        case ICU_LOW_TIME:
            if((Ccu7RRegVal != 0) && (Ccu7SrRegVal != 0))
            {
                if(Ccu7SrRegVal < Ccu7RRegVal)
                {
                    nActivePulseWidth = Ccu7RRegVal - Ccu7SrRegVal;
                }else
                {
                    nActivePulseWidth = (uint32)((uint32)ICU_CCU7_MAX_T12_TIMER_VAL - (Ccu7SrRegVal - Ccu7RRegVal) + 1U);
                }
                Icu_Ccu7_Wrapper_Channel_SignalMeasurement(ModuleId, Channel, (Icu_ValueType)nActivePulseWidth, (Icu_ValueType)0, FALSE);
            }
            break;
        case ICU_HIGH_TIME:
            if((Ccu7RRegVal != 0) && (Ccu7SrRegVal != 0))
            {
                if(Ccu7RRegVal < Ccu7SrRegVal)
                {
                    nActivePulseWidth = Ccu7SrRegVal - Ccu7RRegVal;
                }else
                {
                    nActivePulseWidth = (uint32)((uint32)ICU_CCU7_MAX_T12_TIMER_VAL - (Ccu7RRegVal - Ccu7SrRegVal) + 1U);
                }
                Icu_Ccu7_Wrapper_Channel_SignalMeasurement(ModuleId, Channel, (Icu_ValueType)nActivePulseWidth, (Icu_ValueType)0, FALSE);
            }
            break;
        case ICU_DUTY_CYCLE:
            if(Ccu7Edge == (uint8)ICU_CCU7X_R)
            {
                CcuDutyRegVal = Ccu7SrRegVal;
                CcuPeriodRegVal = Ccu7RRegVal;
            }else
            {
                CcuDutyRegVal = Ccu7RRegVal;
                CcuPeriodRegVal = Ccu7SrRegVal;
            }

            if (Ccu7_GetIntCounter(ModuleId, Channel) == (uint32)0U)
            {
                Ccu7_SetTimeStart(ModuleId, Channel, CcuPeriodRegVal);
                Ccu7_SetIntCounter(ModuleId, Channel, (uint8)1U);
                if(Ccu7Edge == (uint8)ICU_CCU7X_RF)
                {
                    if(Ccu7SrRegVal != 0)
                    {
                        Ccu7_SetTimeStart(ModuleId, Channel, Ccu7SrRegVal);
                        ICU_CCU7_LLD_SetCc7xIntEn(ModuleId, Channel, ICU_CCU7X_F);
                    }else
                    {
                        Ccu7_SetTimeStart(ModuleId, Channel, Ccu7RRegVal);
                        ICU_CCU7_LLD_SetCc7xIntEn(ModuleId, Channel, ICU_CCU7X_F);
                    }

                }

            }else
            {
                CcuPeriodRegValTemp = Ccu7_GetTimeStart(ModuleId, Channel);

                if(CcuPeriodRegValTemp < CcuDutyRegVal)
                {
                    nActivePulseWidth = CcuDutyRegVal - CcuPeriodRegValTemp;
                }else
                {
                    nActivePulseWidth = (uint32)((uint32)ICU_CCU7_MAX_T12_TIMER_VAL - (CcuPeriodRegValTemp - CcuDutyRegVal) + 1U);
                }
                if(CcuPeriodRegValTemp < CcuPeriodRegVal)
                {
                    nPeriod = CcuPeriodRegVal - CcuPeriodRegValTemp;
                }else
                {
                    nPeriod = (uint32)((uint32)ICU_CCU7_MAX_T12_TIMER_VAL - (CcuPeriodRegValTemp - CcuPeriodRegVal) + 1U);
                }
                Icu_Ccu7_Wrapper_Channel_SignalMeasurement(ModuleId, Channel, (Icu_ValueType)nActivePulseWidth, (Icu_ValueType)nPeriod, FALSE);
                Ccu7_SetTimeStart(ModuleId, Channel, CcuPeriodRegVal);
            }

            break;
        case ICU_PERIOD_TIME:
            if((Ccu7RRegVal != 0) && (Ccu7SrRegVal != 0))
            {
                if(Ccu7RRegVal < Ccu7SrRegVal)
                {
                    nPeriod = Ccu7SrRegVal - Ccu7RRegVal;
                }else
                {
                    nPeriod = (uint32)((uint32)ICU_CCU7_MAX_T12_TIMER_VAL - (Ccu7RRegVal - Ccu7SrRegVal) + 1U);
                }
                Icu_Ccu7_Wrapper_Channel_SignalMeasurement(ModuleId, Channel, (Icu_ValueType)0, (Icu_ValueType)nPeriod, FALSE);
            }
            break;
        default:
            break;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (ICU_SIGNAL_MEASUREMENT_API == STD_ON) */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Ccu7_Channel_TimeStamp
(
    VAR(uint8, AUTOMATIC) ModuleId, \
    VAR(uint8, AUTOMATIC) Channel \
)
{
    VAR(uint32,                     AUTOMATIC) u32CCU7XSRTemp = \
            ICU_CCU7_LLD_GetCC7xSR(ModuleId, Channel);
    VAR(Icu_ChannelType,            AUTOMATIC) u16Channel = \
        (Icu_ChannelType)Icu_Ccu7_Wrapper_GetInstance(ModuleId, Channel);

    ICU_AutoSAR_Wapper_Timestamp(u16Channel, 1, &u32CCU7XSRTemp, FALSE);
}

LOCAL_INLINE FUNC (void, ICU_CODE) Icu_Ccu7_Wrapper_Channel_ReportEvents
(
    VAR(uint8,          AUTOMATIC) u8Module, \
    VAR(uint8,          AUTOMATIC) u8Channel, \
    VAR(boolean,        AUTOMATIC) bOverflow \
)
{
    VAR(Icu_ChannelType, ICU_VAR) Instance = Icu_Ccu7_Wrapper_GetInstance(u8Module, u8Channel);

    ICU_AutoSAR_Wapper_ReportEvents(Instance, bOverflow);
}

FUNC(void, ICU_CODE) Icu_Ccu7_ProcessInterrupt \
( \
    VAR(Icu_Module_Type,       AUTOMATIC)ModuleId, \
    VAR(Icu_ChannelType,    AUTOMATIC) Channel \
)
{
    VAR(uint32,             AUTOMATIC) eMeasMode;

    ICU_CCU7_LLD_ClrCc7xFlag(ModuleId, Channel, ICU_CCU7X_RF);

    eMeasMode = Ccu7_GetChConfig((uint8)ModuleId, (uint8)Channel, (uint32)CCU7_CONFIG_DATA_MEASMODE);

    switch (eMeasMode)
    {
        case CCU7_MODE_SIGNAL_MEASUREMENT:
        {
#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
            Icu_Ccu7_Channel_SignalMeasurement((uint8)ModuleId, (uint8)Channel);
#endif
            break;
        }
        case CCU7_MODETIMESTAMP_WITHOUT_DMA:
        {
            Icu_Ccu7_Channel_TimeStamp((uint8)ModuleId, (uint8)Channel);
            break;
        }
        case CCU7_MODE_SIGNAL_EDGE_DETECT:
        {
            Icu_Ccu7_Wrapper_Channel_ReportEvents((uint8)ModuleId, (uint8)Channel, (boolean)FALSE);
            break;
        }
        default:
        {
            /* nothing to do */
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
#ifdef __cplusplus
}
#endif

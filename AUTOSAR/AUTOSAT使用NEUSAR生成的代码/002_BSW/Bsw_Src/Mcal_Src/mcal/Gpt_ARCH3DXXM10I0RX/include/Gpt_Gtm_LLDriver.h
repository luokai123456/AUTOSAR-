/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC
*   Peripheral           : Gpt
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
*   @file    Gpt_Gtm_LLDriver.h
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Gpt MCAL driver.
*
*   @addtogroup Gpt
*   @{
*/
/* PRQA S 3432 EOF */

#ifndef GPT_GTM_LLDRIVER_H
#define GPT_GTM_LLDRIVER_H

#ifdef __cplusplus
extern "C"{
#endif

/*==============================================INCLUDE FILES=======================================*/
#include "Std_Types.h"
#include "Gpt_Cfg.h"

#if (defined(RESOURCE_SUPPORT_GTM104) || defined(RESOURCE_SUPPORT_GTM410))
/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define GPT_VENDOR_ID_H                     176
#define GPT_MODULE_ID_H                     100
#define GPT_AR_RELEASE_MAJOR_VERSION        4
#define GPT_AR_RELEASE_MINOR_VERSION        4
#define GPT_AR_PATCH_VER_H                  0
#define GPT_SW_MAJOR_VER_H                  3
#define GPT_SW_MINOR_VER_H                  0
#define GPT_SW_PATCH_VER_H                  0

/*============================================FILE VERSION CHECKS===================================*/

#if (GPT_VENDOR_ID_H != GPT_VENDOR_ID)
#error "NON-MATCHED DATA : GPT_CFG_VENDOR_ID"
#endif

#if (GPT_AR_RELEASE_MAJOR_VERSION != GPT_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_MAJOR_VER"
#endif
#if (GPT_AR_RELEASE_MINOR_VERSION != GPT_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_MINOR_VER"
#endif
#if (GPT_AR_PATCH_VER_H != GPT_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_PATCH_VER"
#endif

#if (GPT_SW_MAJOR_VER_H != GPT_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_MAJOR_VER"
#endif
#if (GPT_SW_MINOR_VER_H != GPT_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_MINOR_VER"
#endif
#if (GPT_SW_PATCH_VER_H != GPT_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_PATCH_VER"
#endif
//#if (defined(RESOURCE_SUPPORT_GTM104) )
typedef volatile struct GTM_TOM_tag st_Gpt_GTM_TOM_tag;
typedef volatile struct GTMINT_tag  st_Gpt_GTMINT_tag;

#define GPT_GTM_TOM_0_BASE_ADDR                          (&GTM_TOM_0)
#define GPT_GTM_TOM_1_BASE_ADDR                          (&GTM_TOM_1)
#define GPT_GTM_TOM_2_BASE_ADDR                          (&GTM_TOM_2)
#define GPT_GTM_TOM_3_BASE_ADDR                          (&GTM_TOM_3)
#define GPT_GTM_TOM_4_BASE_ADDR                          (&GTM_TOM_4)

#define GPT_GTMINT_BASE_ADDR							 (&GTMINT)

//#endif

/*=================================================Constants========================================*/
#define GPT_GTM_MODULE_MAX                      (6U)
#define GPT_GTM_CHANNEL_MAX                     (16U)

#define GTM_MOD_SHIFT                           (5U)
#define GTM_CH_MASK_U8                          (0x1FU)

#define GTM_MODULE_INDEX_U32(ch)                (((ch) >> (uint8)GTM_MOD_SHIFT) & 0x7U)
#define GTM_CHANNEL_INDEX_U32(ch)               ((ch) & GTM_CH_MASK_U8)

#define GTM_TOM_CH_CTRL_CLK_SRC_SHIFT           ((uint32)(12UL))
#define GTM_TOM_RST_SOURCE_CM0_U32              ((uint32)(0UL))
#define GTM_TOM_CH_CTRL_RST_SRC_SHIFT           ((uint32)(20UL))
#define GTM_TOM_CH_CTRL_ONE_SHOT_SHIFT          ((uint32)(26UL))

/* CMU_CLK_EN Register - bitfield mask and shift defines.*/
#define CMU_CLK_EN_ENABLE_CLOCK             ((uint32)(0x2UL))
#define CMU_CLK_EN_DISABLE_CLOCK            ((uint32)(0x1UL))
#define CMU_CLK_EN_EN_FXCLK_OFFSET          ((uint32)(22UL))
#define CMU_CLK_EN_EN_ECLK2_OFFSET          ((uint32)(20UL))
#define CMU_CLK_EN_EN_ECLK1_OFFSET          ((uint32)(18UL))
#define CMU_CLK_EN_EN_ECLK0_OFFSET          ((uint32)(16UL))
#define CMU_CLK_EN_EN_CLK7_OFFSET           ((uint32)(14UL))
#define CMU_CLK_EN_EN_CLK6_OFFSET           ((uint32)(12UL))
#define CMU_CLK_EN_EN_CLK5_OFFSET           ((uint32)(10UL))
#define CMU_CLK_EN_EN_CLK4_OFFSET           ((uint32)(8UL))
#define CMU_CLK_EN_EN_CLK3_OFFSET           ((uint32)(6UL))
#define CMU_CLK_EN_EN_CLK2_OFFSET           ((uint32)(4UL))
#define CMU_CLK_EN_EN_CLK1_OFFSET           ((uint32)(2UL))
#define CMU_CLK_EN_EN_CLK0_OFFSET           ((uint32)(0UL))

/* CMU_CLKx_CTRL Register - bitfield mask and shift defines.*/
#define CMU_CLK_X_CTRL_CLK_CNT_OFFSET       ((uint32)(0x0UL))
#define CMU_CLK_5_CTRL_FLCLK_SEL_ON         ((uint32)(1UL))
#define CMU_CLK_5_CTRL_FLCLK_SEL_OFF        ((uint32)(0UL))
#define CMU_CLK_5_CTRL_FLCLK_SEL_OFFSET     ((uint32)(31UL))
#define CMU_CLK_6_CTRL_SEL_ON               ((uint32)(1UL))
#define CMU_CLK_6_CTRL_SEL_OFF              ((uint32)(0UL))
#define CMU_CLK_6_CTRL_SEL_OFFSET           ((uint32)(24UL))
#define CMU_CLK_7_CTRL_SEL_ON               ((uint32)(1UL))
#define CMU_CLK_7_CTRL_SEL_OFF              ((uint32)(0UL))
#define CMU_CLK_7_CTRL_SEL_OFFSET           ((uint32)(24UL))

/* CMU_FXCLK_CTRL Register - bitfield mask and shift defines.*/
#define CMU_FXCLK_CTRL_FXCLK_SEL_OFFSET     ((uint32)(0UL))

/*TBU CHEN Register - bitfield mask and shift defines.*/
#define TBU_CHEN_ENABLE_CHANNEL             ((uint32)(2UL))
#define TBU_CHEN_DISABLE_CHANNEL            ((uint32)(1UL))

/*TBU_CH0_CTRL Register - bitfield mask and shift defines.*/
#define TBU_CH0_CTRL_LOW_RES                ((uint32)(0UL))
#define TBU_CH0_CTRL_HIGH_RES               ((uint32)(1UL))
#define TBU_CH0_CTRL_LOW_RES_OFFSET         ((uint32)(0UL))
#define TBU_CH0_CTRL_CH_CLK_SRC_OFFSET      ((uint32)(1UL))

/*TBU_CH1_CTRL Register - bitfield mask and shift defines.*/
#define TBU_CH1_CTRL_FORWARD_MODE           ((uint32)(1UL))
#define TBU_CH1_CTRL_FREE_RUNNING_MODE      ((uint32)(0UL))
#define TBU_CH1_CTRL_CH_MODE_OFFSET         ((uint32)(0UL))
#define TBU_CH1_CTRL_CH_CLK_SRC_OFFSET      ((uint32)(1UL))

/* TBU_CH2_CTRL Register - bitfield mask and shift defines.*/
#define TBU_CH2_CTRL_FORWARD_MODE           ((uint32)(1UL))
#define TBU_CH2_CTRL_FREE_RUNNING_MODE      ((uint32)(0UL))
#define TBU_CH2_CTRL_CH_MODE_OFFSET         ((uint32)(0UL))
#define TBU_CH2_CTRL_CH_CLK_SRC_OFFSET      ((uint32)(1UL))

/*============================================DEFINES AND MACROS====================================*/
#define TOM0_CH_NUM    16U
#define TOM1_CH_NUM    16U
#define TOM2_CH_NUM    16U
#define TOM3_CH_NUM    16U
#define TOM4_CH_NUM    16U

#define GTM_INSTANCE_NUM                        5U
#if (defined(RESOURCE_SUPPORT_GTM410))
#define GTM4_TOM_TGC_GLB_CTRL_UPEN_CTRL0_OFF        (16u)
#define GTM4_TOM_TGC_GLB_CTRL_RST_CH0_OFF           (8u)
#define GTM4_TOM_TGC_FUPD_CTRL_RSTCN0_CH0_OFF       (16u)
#define GTM4_TOM_TGC_FUPD_CTRL_FUPD_CTRL0_OFF       (0u)
#define GTM4_TOM_TGC_INT_TRIG_INT_TRIG0_OFF         (0u)
#define GTM4_TOM_TGC_ENDIS_CTRL_ENDIS_CTRL0_OFF     (0u)
#define GTM4_TOM_TGC_ENDIS_STAT_ENDIS_STAT0_OFF     (0u)
#define GTM4_TOM_TGC_OUTEN_CTRL_OUTEN_CTRL0_OFF     (0u)
#define GTM4_TOM_TGC_OUTEN_STAT_OUTEN_STAT0_OFF     (0u)
#endif
/*===================================================ENUMS==========================================*/

typedef enum
{
    GPT_GTM_Disable = 0x0U,
	GPT_GTM_Enable = 0x1U
}GPT_GTM_Status_Type;

typedef enum{
    GTM_IO_TIM0 = 0x0U,
    GTM_IO_TIM1 = 0x1U,
    GTM_IO_TIM2 = 0x2U,
    GTM_IO_TIM3 = 0x3U,
    GTM_IO_TOM0 = 0x4U,
    GTM_IO_TOM1 = 0x5U,
    GTM_IO_TOM2 = 0x6U,
    GTM_IO_ATOM0 = 0x7U,
    GTM_IO_ATOM1 = 0x8U,
    GTM_IO_ATOM2 = 0x9U,
    GTM_IO_ATOM3 = 0x0AU,
    GTM_IO_ATOM4 = 0x0BU
}GTM_IO_Type;

typedef enum{
    GTM_IRQ_MODE_Level = 0x0U,
    GTM_IRQ_MODE_Pulse = 0x1U,
    GTM_IRQ_MODE_PulseNotify = 0x2U,
    GTM_IRQ_MODE_SinglePulse = 0x3U
}GTM_InterruptMode_Type;

typedef enum{
    GTM_TO_MODE_Observe = 0x0U,
    GTM_TO_MODE_Abort = 0x1U
}GTM_AEITimeoutMode_Type;
#if (defined(RESOURCE_SUPPORT_GTM410))
typedef enum{
    GTM_CLS0 = 0U,
    GTM_CLS1 = 1U,
    GTM_CLS2 = 2U,
    GTM_CLS3 = 3U,
    GTM_CLS4 = 4U,
    GTM_CLS5 = 5U,
    GTM_CLS6 = 6U,
    GTM_CLS7 = 7U,
}GTM_CLS_Type;

typedef enum{
    ClsDisable = 0U,
    ClsEnableWithoutDiv =1U,
    ClsEnableWithDiv2 =2U
}GTM_ClsDivStatus_Type;
#endif
typedef enum
{
    GPT_GTM_TOM0 = 0x0U,
    GPT_GTM_TOM1 = 0x1U,
    GPT_GTM_TOM2 = 0x2U,
    GPT_GTM_TOM3 = 0x3U,
    GPT_GTM_TOM4 = 0x4U,
    GPT_GTM_TOM5 = 0x5U
}GPT_GTM_TOM_Type;

typedef enum
{
    GPT_GTM_TOM_CH0 = 0x0U,
    GPT_GTM_TOM_CH1 = 0x1U,
    GPT_GTM_TOM_CH2 = 0x2U,
    GPT_GTM_TOM_CH3 = 0x3U,
    GPT_GTM_TOM_CH4 = 0x4U,
    GPT_GTM_TOM_CH5 = 0x5U,
    GPT_GTM_TOM_CH6 = 0x6U,
    GPT_GTM_TOM_CH7 = 0x7U,
    GPT_GTM_TOM_CH8 = 0x8U,
    GPT_GTM_TOM_CH9 = 0x9U,
    GPT_GTM_TOM_CH10 = 0xAU,
    GPT_GTM_TOM_CH11 = 0xBU,
    GPT_GTM_TOM_CH12 = 0xCU,
    GPT_GTM_TOM_CH13 = 0xDU,
    GPT_GTM_TOM_CH14 = 0xEU,
    GPT_GTM_TOM_CH15 = 0xFU
}GPT_GTM_TOM_Channel_Type;

typedef enum
{
    GPT_GTM_TOM_CLK_SRC_CMU_FXCLK0 = 0x0U,
    GPT_GTM_TOM_CLK_SRC_CMU_FXCLK1 = 0x1U,
    GPT_GTM_TOM_CLK_SRC_CMU_FXCLK2 = 0x2U,
    GPT_GTM_TOM_CLK_SRC_CMU_FXCLK3 = 0x3U,
    GPT_GTM_TOM_CLK_SRC_CMU_FXCLK4 = 0x4U,
    GPT_GTM_TOM_CLK_SRC_NO_CMU_FXCLK = 0x5U
}GPT_GTM_TOM_ClockSource_Type;

typedef enum
{
    GPT_GTM_TOM_IRQ_CCU0TC = 0x0U,
    GPT_GTM_TOM_IRQ_CCU1TC = 0x1U
}GPT_GTM_TOM_Interrupt_Type;

typedef enum
{
    GPT_GTM_TOM_RST_CCU0_CM0 = 0x0U,
    GPT_GTM_TOM_RST_CCU0_TRIG = 0x1U
}GPT_GTM_TOM_CCU0ResetSource_Type;

typedef enum{
    GPT_GTM_CMU_CLK0 = 0x0U,
    GPT_GTM_CMU_CLK1 = 0x1U,
    GPT_GTM_CMU_CLK2 = 0x2U,
    GPT_GTM_CMU_CLK3 = 0x3U,
    GPT_GTM_CMU_CLK4 = 0x4U,
    GPT_GTM_CMU_CLK5 = 0x5U,
    GPT_GTM_CMU_CLK6 = 0x6U,
    GPT_GTM_CMU_CLK7 = 0x7U,
    GPT_GTM_CMU_ECLK0 = 0x8U,
    GPT_GTM_CMU_ECLK1 = 0x9U,
    GPT_GTM_CMU_ECLK2 = 0xAU,
    GPT_GTM_CMU_FXCLK = 0xBU,
}GPT_GTM_CMU_Clock_Type;

typedef enum{
    GPT_CLK_SEL_Clock67 = 0x0U,
    GPT_CLK_SEL_SUB_INC2 = 0x1U
}GPT_GTM_CMU_Clock67Source_Type;

typedef enum{
    CMU_FXCLK_CTRL_CMU_GCLK_EN = 0x0U,
    CMU_FXCLK_CTRL_CMU_CLK0 = 0x1U,
    CMU_FXCLK_CTRL_CMU_CLK1 = 0x2U,
    CMU_FXCLK_CTRL_CMU_CLK2 = 0x3U,
    CMU_FXCLK_CTRL_CMU_CLK3 = 0x4U,
    CMU_FXCLK_CTRL_CMU_CLK4 = 0x5U,
    CMU_FXCLK_CTRL_CMU_CLK5 = 0x6U,
    CMU_FXCLK_CTRL_CMU_CLK6 = 0x7U,
    CMU_FXCLK_CTRL_CMU_CLK7 = 0x8U
}GTM_CMU_FXCLKSource_Type;


typedef enum{
    GPT_GTM_TBU_CHEN_CH0 = 0x0U,
    GPT_GTM_TBU_CHEN_CH1 = 0x1U,
    GPT_GTM_TBU_CHEN_CH2 = 0x2U
}GPT_GTM_TBU_CHEN_Type;


typedef enum{
    TBU_CHX_CTRL_CMU_CLK0 = 0x0U,
    TBU_CHX_CTRL_CMU_CLK1 = 0x1U,
    TBU_CHX_CTRL_CMU_CLK2 = 0x2U,
    TBU_CHX_CTRL_CMU_CLK3 = 0x3U,
    TBU_CHX_CTRL_CMU_CLK4 = 0x4U,
    TBU_CHX_CTRL_CMU_CLK5 = 0x5U,
    TBU_CHX_CTRL_CMU_CLK6 = 0x6U,
    TBU_CHX_CTRL_CMU_CLK7 = 0x7U
}GPT_GTM_TBU_CHX_CLK_SRC_Type;

/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/
typedef void (*GPT_GTM_Callback_Func)(GPT_GTM_Status_Type Gtm_Type, GPT_GTM_TOM_Channel_Type Tom_Channel);

typedef struct
{
    GPT_GTM_CMU_Clock_Type clockId;     	/* GTM CMU Clock ID */
    uint32 clockControlRegister;        	/* GTM CMU Clock Control register */
}GPT_GTM_CMU_ClkConfigType;

typedef struct
{
    uint32 global_clock_numerator;          /* CMU Global Clock Control Numerator */
    uint32 global_clock_denominator;        /* CMU Global Clock Control Denominator */
    uint32 cmu_clk_control_register;        /* CMU clock enable register */
    uint32 cmu_fxclk_sel_register;          /* CMU FXCLK_Sel register */
    uint8 count_of_configured_clocks;       /* number of clocks configured */
    const GPT_GTM_CMU_ClkConfigType     (* clock_configPtr)[];   /* pointer to array of configured clocks */
}GPT_GTM_CMU_LLD_ConfigType;

typedef struct
{
    uint8 tbu_channel0_enable_reg;            /* TBU channel enable register */
    uint8 tbu_channel1_enable_reg;            /* TBU channel enable register */
    uint8 tbu_channel2_enable_reg;            /* TBU channel enable register */
    uint8 tbu_ch0_control_clk_src;            /* TBU channel 0 control register */
    uint8 tbu_ch0_control_low_res;            /* TBU channel 0 control register */
    uint8 tbu_ch1_control_clk_src;            /* TBU channel 1 control register */
    uint8 tbu_ch1_control_ch_mode;            /* TBU channel 1 control register */
    uint8 tbu_ch2_control_clk_src;            /* TBU channel 2 control register */
    uint8 tbu_ch2_control_ch_mode;            /* TBU channel 2 control register */
}GPT_GTM_TBU_LLD_ConfigType;

typedef struct
{
	GPT_GTM_CMU_LLD_ConfigType cmu_configuration;         /* Clock Management Unit submodule configuration*/
	GPT_GTM_TBU_LLD_ConfigType tbu_configuration;         /* Time Base Unit submodule configuration*/
} Gpt_GtmCmuConfigType;

/*==============================================GLOBAL FUNCTIONS====================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(GPT_GTM_TOM_Type, GPT_CODE) Gpt_GTM_LLD_ConvertModuleId(VAR(uint8, AUTOMATIC)u8Module);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(GPT_GTM_TOM_Channel_Type, GPT_CODE) Gpt_Gtm_LLD_ConvertChannelId(VAR(uint8, AUTOMATIC)u8Channel);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) GPT_TOM_LLD_IRQHandler 					\
( 																\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) TOM_ModuleID, 				\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) TOM_ChannelID 		\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTMINT_LLD_IsEnableModule \
(                                                   \
    VAR(GPT_GTM_Status_Type, AUTOMATIC)IsEnable     \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_SelectCCU0ResetSource( \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn,                        \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn,                     \
    VAR(GPT_GTM_TOM_CCU0ResetSource_Type, AUTOMATIC) CCU0ResetSource  \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) Gpt_GTM_TOM_LLD_IsEnableOneShotMode 	\
( 																	\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 						\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 					\
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable 					\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#if (defined(RESOURCE_SUPPORT_GTM410))
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_LLD_IsEnableClsDiv
(
		VAR(GTM_CLS_Type, AUTOMATIC) GTM_CLSn, \
		VAR(GTM_ClsDivStatus_Type, AUTOMATIC_Type) status
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"
#endif
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
VAR(uint32, AUTOMATIC) Gpt_GTM_TOM_LLD_Channel_GetCompareRegister   \
(                                                                   \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn,                      \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn                    \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_SelectClockSource	\
( 																	\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 						\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 					\
    VAR(GPT_GTM_TOM_ClockSource_Type, AUTOMATIC) ClockSource		\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_SetShadowRegister    \
( 																	\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 						\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 					\
    VAR(uint16, AUTOMATIC) SR0, 									\
    VAR(uint16, AUTOMATIC) SR1 										\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_SetCompareRegister   \
( 																	\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 						\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 					\
    VAR(uint16, AUTOMATIC) CM0, 									\
    VAR(uint16, AUTOMATIC) CM1 										\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_SetCounter   \
( 															\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 				\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 			\
    VAR(uint16, AUTOMATIC) CN0 								\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint8, GPT_CODE) GPT_GTM_TOM_LLD_GetInterruptFlag   \
( 														 \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 			 \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn,		 \
    VAR(GPT_GTM_TOM_Interrupt_Type, AUTOMATIC) Interrupt \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_ClearInterruptFlag 	\
( 																	\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 						\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 					\
    VAR(GPT_GTM_TOM_Interrupt_Type, AUTOMATIC) Interrupt 			\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_IsEnableInterrupt  	\
( 																	\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 						\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 					\
    VAR(GPT_GTM_TOM_Interrupt_Type, AUTOMATIC) Interrupt,			\
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable 					\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_IsEnableUpdate   \
( 																\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 					\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 				\
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable 				\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_IsEnableChannel 	\
( 																\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 					\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 				\
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable 				\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_IsEnableOut 	\
( 															\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 				\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 			\
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable 			\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) GPT_GTM_TOM_LLD_GetCounter 	\
( 													\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 		\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn 	\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_CMU_LLD_IsEnableClock \
( 													\
    VAR(GPT_GTM_CMU_Clock_Type, AUTOMATIC) Clock,   \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable    \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#if (defined(RESOURCE_SUPPORT_GTM410))
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
Std_ReturnType GTM_LLD_HresEn(void);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_CMU_LLD_SetGlobalClockNumerator(VAR(uint32, AUTOMATIC) Numerator);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_CMU_LLD_SetGlobalClockDenominator(VAR(uint32, AUTOMATIC) Denominator);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_CMU_LLD_SetClockCount \
(  												 \
    VAR(GPT_GTM_CMU_Clock_Type, AUTOMATIC) Clock,\
    VAR(uint32, AUTOMATIC) Count                 \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_CMU_LLD_SelectFXCLKSource(VAR(GTM_CMU_FXCLKSource_Type, AUTOMATIC) FXCLKSource);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TBU_LLD_IsEnableClock \
(													\
    VAR(GPT_GTM_TBU_CHEN_Type, AUTOMATIC) Clock,    \
    VAR(uint32, AUTOMATIC) IsEnable        			\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TBU_LLD_SetSLK   \
(                                                       \
    VAR(GPT_GTM_TBU_CHEN_Type, AUTOMATIC) Chn,          \
    VAR(uint8, AUTOMATIC) Clksrc \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) GPT_GTM_TBU_LLD_SetCH0_LOWRES \
(                                                  \
    VAR(uint8, AUTOMATIC) IsEnable                 \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TBU_LLD_SetBASE  \
(                                               \
    VAR(GPT_GTM_TBU_CHEN_Type, AUTOMATIC) Chn,  \
    VAR(uint32, AUTOMATIC) Base                 \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TBU_LLD_SetCHMODE  \
(                                                   \
    VAR(GPT_GTM_TBU_CHEN_Type, AUTOMATIC) Chn,      \
    VAR(uint32, AUTOMATIC) Mode                     \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) GPT_GTM_LLD_Reset(void);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#ifdef __cplusplus
}
#endif

#endif// GPT_GTM_LLDRIVER_H
#endif

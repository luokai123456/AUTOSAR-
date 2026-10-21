/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : EMIOS
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
*   @file    eMIOS_LLDriver.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eMIOS MCAL driver.
*
*   @addtogroup eMIOS
*   @{
*/

#ifndef EMIOS_LLDRIVER_H
#define EMIOS_LLDRIVER_H

#include "eMIOS_Cfg.h"
#include "derivative.h"
#include "status.h"
#include "devassert.h"

#define EMIOS_LLD_H_VENDOR_ID                     176
#define EMIOS_LLD_H_AR_REL_MAJOR_VER              4
#define EMIOS_LLD_H_AR_REL_MINOR_VER              4
#define EMIOS_LLD_H_AR_REL_REV_VER                0
#define EMIOS_LLD_H_SW_MAJOR_VER                  3
#define EMIOS_LLD_H_SW_MINOR_VER                  0
#define EMIOS_LLD_H_SW_PATCH_VER                  0
#define EMIOS_MODULE_ID                           250

#if (EMIOS_VENDOR_ID != EMIOS_LLD_H_VENDOR_ID)
    #error " NON-MATCHED DATA : EMIOS_LLD_H_VENDOR_ID "
#endif
#if (EMIOS_AR_REL_MAJOR_VER != EMIOS_LLD_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_H_AR_REL_MAJOR_VER "
#endif
#if (EMIOS_AR_REL_MINOR_VER != EMIOS_LLD_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_H_AR_REL_MINOR_VER "
#endif
#if (EMIOS_AR_REL_REV_VER != EMIOS_LLD_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_H_AR_REL_REV_VER "
#endif
#if (EMIOS_SW_MAJOR_VER != EMIOS_LLD_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_H_SW_MAJOR_VER "
#endif
#if (EMIOS_SW_MINOR_VER != EMIOS_LLD_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_H_SW_MINOR_VER "
#endif
#if (EMIOS_SW_PATCH_VER != EMIOS_LLD_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_H_SW_PATCH_VER "
#endif

typedef struct eMIOS_tag eMIOS_Type;

#define EMIOS_DEV_ERR(x)            DEV_ASSERT(x)

/** Number of instances of the eMIOS module. */
#if (defined (EMIOS_UnUsed_EMIOS1))
#define EMIOS_INSTANCE_MAX                      (1U)
#else
#define EMIOS_INSTANCE_MAX                      (2U)
#endif

#define EMIOS_MODULE_CHANNEL_MAX                (32U)

/* eMIOS - Peripheral instance base addresses */
/** Peripheral eMIOS_0 base address */
#define EMIOS0_BASEADDR                         ((uint32_t)0xFFDEC000UL)
/** Peripheral eMIOS_0 base pointer */
#define EMIOS0_PTR                              ((eMIOS_Type *)EMIOS0_BASEADDR)
/** Peripheral eMIOS_1 base address */
#define EMIOS1_BASEADDR                         ((uint32_t)0xFBF78000UL)
/** Peripheral eMIOS_1 base pointer */
#define EMIOS1_PTR                              ((eMIOS_Type *)EMIOS1_BASEADDR)
/** Array initializer of eMIOS peripheral base addresses */
#define EMIOS_BASE_ADDR_ARRAY                   { EMIOS0_BASEADDR, EMIOS1_BASEADDR }
/** Array initializer of eMIOS peripheral base pointers */
#define EMIOS_BASE_PTR_ARRAY                    { EMIOS0_PTR, EMIOS1_PTR }

/** Interrupt vectors for the eMIOS peripheral type */

#define EMIOS_MCR_GPRE_MAX          (0xFFU)

/* Max/Min counter value (eMIOS CNT register in MC mode - 24 bit) */
#define EMIOS_MC_CNT_MAX            (0xFFFFFFUL)
#define EMIOS_MC_CNT_MIN            (0x00UL)
/* Max/Min counter value (eMIOS CNT register in MCB mode - 24 bit) */
#define EMIOS_MCB_CNT_MAX           (0xFFFFFFUL)
#define EMIOS_MCB_CNT_MIN           (0x01UL)
/* Max/Min counter value (eMIOS CNT register in OPWFMB mode - 24 bit) */
#define EMIOS_OPWFMB_CNT_MAX        (0xFFFFFFUL)
#define EMIOS_OPWFMB_CNT_MIN        (0x01UL)
/* Max/Min counter value (eMIOS CNT register in OPWMCB mode - 24 bit) */
#define EMIOS_OPWMCB_CNT_MAX        (0xFFFFFFUL)
#define EMIOS_OPWMCB_CNT_MIN        (0x00UL)

/* Modulus Counter Buffered MASK */
#define EMIOS_FILTER_MCB_MASK       (0xFCU)
/* Modulus Counter Buffered (Up counter) MASK */
#define EMIOS_MCB_UP_MASK           (0x50U)
/* Modulus Counter Buffered (Up/down counter) MASK */
#define EMIOS_MCB_UPDOWN_MASK       (0x54U)
/* Modulus Counter MASK */
#define EMIOS_FILTER_MC_MASK        (0xFCU)
/* Modulus Counter (Up counter) MASK */
#define EMIOS_MC_UP_MASK            (0x10U)
/* Modulus Counter (Up/down counter) MASK */
#define EMIOS_MC_UPDOWN_MASK        (0x14U)
/* Center Aligned Output Pulse Width Modulation Buffered */
#define EMIOS_OPWMCB_MASK           (0x5CU)
/* Center Aligned Output Pulse Width Modulation Buffered Filter mask */
#define EMIOS_FILTER_OPWMCB_MASK    (0xFCU)

#define GPIO_Mode_Mask              (0x770C00FFU)

#define GPIO_Mode_Out_PP            (0x320C0000U)    

#define GPIO_Mode_IPU               (0x308C0000U)    

#define GPIOM                       (0xC0)

/*******************************************************************************
 * @brief eMIOS instance base address pointer array
 ******************************************************************************/
extern CONSTP2VAR(eMIOS_Type, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_BasePtr[EMIOS_INSTANCE_MAX];

typedef enum
{
    EMIOS_INSTANCE_0,
    EMIOS_INSTANCE_1
} eMIOS_ModuleType;

typedef enum
{
    EMIOS_ETB_DIS_COUNTER_BUSA_TO_UC    = 0U,
    EMIOS_ETB_EN_COUNTER_BUSA_TO_STAC   = 1U
} eMIOS_MCR_ExtTimeBaseType;

typedef enum
{
    EMIOS_OUTPUT_DISABLE_INPUT_0        = 0x00U,
    EMIOS_OUTPUT_DISABLE_INPUT_1        = 0x01U,
    EMIOS_OUTPUT_DISABLE_INPUT_2        = 0x02U,
    EMIOS_OUTPUT_DISABLE_INPUT_3        = 0x03U
} eMIOS_UC_OutputDisSelType;

typedef enum
{
    EMIOS_UC_PRE_CLK_DIV_1              = 0x00U,
    EMIOS_UC_PRE_CLK_DIV_2              = 0x01U,
    EMIOS_UC_PRE_CLK_DIV_3              = 0x02U,
    EMIOS_UC_PRE_CLK_DIV_4              = 0x03U
} eMIOS_UC_PresClkDivType;

typedef enum
{
    EMIOS_C_REQ_INT                     = 0U,
    EMIOS_C_REQ_DMA                     = 1U
} eMIOS_UC_IntDmaType;

typedef enum
{
    EMIOS_INPUT_FILTER_BYPASS           = 0x00U,
    EMIOS_INPUT_FILTER_02               = 0x01U,
    EMIOS_INPUT_FILTER_04               = 0x02U,
    EMIOS_INPUT_FILTER_08               = 0x04U,
    EMIOS_INPUT_FILTER_16               = 0x08U
} eMIOS_UC_InputFilterType;

typedef enum
{
    EMIOS_C_FCK_PRESCALED_CLK           = 0U,
    EMIOS_C_FCK_EMIOS_MODULE_CLK        = 1U
} eMIOS_UC_FilterClkSelType;

typedef enum
{
    EMIOS_COUNTER_BUS_A                 = 0x00U,
    EMIOS_COUNTER_BUS_BCDE              = 0x01U,
    EMIOS_COUNTER_BUS_INTERNAL          = 0x03U
} eMIOS_UC_CounterBusSelType;

typedef enum
{
    EMIOS_TRIG_EDGE_FALLING             = 0x00U,
    EMIOS_TRIG_EDGE_RISING              = 0x01U,
    EMIOS_TRIG_EDGE_BOTH                = 0x02U,
    EMIOS_TRIG_EDGE_OPPOSITE            = 0x03U
} eMIOS_EdgeTrigModeType;

typedef enum
{
    EMIOS_NEGATIVE_PULSE                = 0x00U,
    EMIOS_POSITIVE_PULSE                = 0x01U
} eMIOS_PulsePolarityModeType;

typedef enum
{
    EMIOS_CNT_BUSB_DRIVEN_CHANNEL       = 0U,
    EMIOS_CNT_BUSC_DRIVEN_CHANNEL       = 8U,
    EMIOS_CNT_BUSD_DRIVEN_CHANNEL       = 16U,
    EMIOS_CNT_BUSA_DRIVEN_CHANNEL       = 23U,
    EMIOS_CNT_BUSE_DRIVEN_CHANNEL       = 24U,
    EMIOS_CNT_INTERNAL_DRIVEN_CHANNEL   = 32U,
    EMIOS_CNT_NONE_DRIVEN_CHANNEL       = 0xFFU,
} eMIOS_BusDrivenType;

typedef enum
{
    EMIOS_UC_MODE_GPIO_INPUT                = 0x00U,
    EMIOS_UC_MODE_GPIO_OUTPUT               = 0x01U,
    EMIOS_UC_MODE_SAIC                      = 0x02U,
    EMIOS_UC_MODE_SAOC                      = 0x03U,
    EMIOS_UC_MODE_IPWM                      = 0x04U,
    EMIOS_UC_MODE_IPM                       = 0x05U,
    EMIOS_UC_MODE_DAOC_FLAG_MATCH_B         = 0x06U,
    EMIOS_UC_MODE_DAOC_BOTH_FLAG_MATCH      = 0x07U,
    EMIOS_UC_MODE_PEA_CONTIN                = 0x08U,
    EMIOS_UC_MODE_PEA_SINGLE                = 0x09U,
    EMIOS_UC_MODE_PEC_CONTIN                = 0x0AU,
    EMIOS_UC_MODE_PEC_SINGLE                = 0x0BU,
    EMIOS_UC_MODE_FOR_COUNT_DIRECT_QDEC     = 0x0CU,
    EMIOS_UC_MODE_QDEC_A_B_FOR_PHASE        = 0x0DU,
    EMIOS_UC_MODE_WPTA                      = 0x0EU,
    EMIOS_UC_MODE_MC                        = 0x40U,
    EMIOS_UC_MODE_MCB_INT                   = 0x50U,
    EMIOS_UC_MODE_MCB_EXT                   = 0x51U
} eMIOS_UC_ModeType;

typedef struct
{
    VAR(boolean, ADC_VAR) LowPowerModeEn;
    VAR(boolean, ADC_VAR) FreezeInDebugMode;
    VAR(uint16, ADC_VAR) GlobalPreClkDiv;
    VAR(eMIOS_MCR_ExtTimeBaseType, ADC_VAR) ExternalTimeBaseSel;
    VAR(uint8, ADC_VAR) ServerTimeSlotSel;
} eMIOS_GlobalParamType;

typedef enum
{
    EMIOS_UC_MODE_MC_UP_CNT_CLR_START_INT_CLK       = 0x10U,     /* Modulus Counter (Up counter with clear on match start), internal clock */
    EMIOS_UC_MODE_MC_UP_START_EXT_CLK_CNT_CLR       = 0x11U,     /* Modulus Counter (Up counter with clear on match start), external clock */
    EMIOS_UC_MODE_MC_UP_CNT_CLR_END_INT_CLK         = 0x12U,     /* Modulus Counter (Up counter with clear on match end), internal clock */
    EMIOS_UC_MODE_MC_UP_CNT_EXT_CLR_END_CLK         = 0x13U,     /* Modulus Counter (Up counter with clear on match end), external clock */

    EMIOS_UC_MODE_MC_UPDOWN_CNT_FLAGX1_INT_CLK      = 0x14U,     /* Modulus Counter (Up/Down counter), internal clock */
    MC_UPDOWN_CNT_FLAGX1_EXT_CLK                    = 0x15U,     /* Modulus Counter (Up/Down counter), external clock */
    EMIOS_UC_MODE_MC_FLAGX2_UPDOWN_CNT_INT_CLK      = 0x16U,     /* Modulus Counter (Up/Down counter), internal clock */
    EMIOS_UC_MODE_MC_UPDOWN_FLAGX2_CNT_EXT_CLK      = 0x17U,     /* Modulus Counter (Up/Down counter), external clock */

    EMIOS_UC_MODE_MCB_UP_COUNTER_INT_CLK            = 0x50U,     /* Modulus Counter Buffered (Up counter), using internal clock */
    EMIOS_UC_MODE_MCB_UP_COUNTER_EXT_CLK            = 0x51U,     /* Modulus Counter Buffered (Up counter), using external clock */

    EMIOS_UC_MODE_MCB_UPDOWN_CNT_FLAGX1_INT_CLK     = 0x54U,     /* Modulus Counter Buffered (Up/Down counter), Flags are generated only at A1 match start, Using internal clock */
    EMIOS_UC_MODE_MCB_UPDOWN_FLAGX1_CNT_EXT_CLK     = 0x55U,     /* Modulus Counter Buffered (Up/Down counter), Flags are generated only at A1 match start, Using external clock */
    EMIOS_UC_MODE_MCB_UPDOWN_CNT_INT_CLK_FLAGX2     = 0x56U,     /* Modulus Counter Buffered (Up/Down counter), Flags are generated at A1 match start and cycle boundary, Using internal clock */
    EMIOS_UC_MODE_MCB_UPDOWN_FLAGX2_CNT_EXT_CLK     = 0x57U      /* Modulus Counter Buffered (Up/Down counter), Flags are generated at A1 match start and cycle boundary, Using external clock */
} eMIOS_UC_MC_ModeType;

typedef struct
{
    VAR(eMIOS_UC_MC_ModeType, ADC_VAR) mode;
    VAR(uint32, ADC_VAR) period;
    VAR(uint8, ADC_VAR) divid;
    VAR(eMIOS_UC_InputFilterType, ADC_VAR) filter;
    VAR(eMIOS_EdgeTrigModeType, ADC_VAR) trigger;
} eMIOS_MC_ParamType;

#if (defined (RESOURCE_SUPPORT_SIUL2_IP))
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) GPIO_ConfigIdx(VAR(uint32, AUTOMATIC) u32eMIOS_Idx, VAR(uint32, AUTOMATIC) u32eMIOS_Mode);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"
#endif

/*******************************************************************************/
/****************eMIOS Module Configuration Register (eMIOS_MCR)****************/

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8_t, EMIOS_CODE) eMIOS_MCR_GetGPRE(VAR(uint8, AUTOMATIC) u8eMIOS_Index);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_MCR_SetGPRE(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_GlobalPreDiv);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_MCR_GetSRV(VAR(uint8, AUTOMATIC) u8eMIOS_Index);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_MCR_SetSRV(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ServerTimeSlot);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_MCR_GetGPREN(VAR(uint8, AUTOMATIC) u8eMIOS_Index);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_MCR_SetGPREN(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(boolean, AUTOMATIC) beMIOS_GlobalPreEnDis);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_MCR_GetETB(VAR(uint8, AUTOMATIC) u8eMIOS_Index);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_MCR_SetETB(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(boolean, AUTOMATIC) beMIOS_ExtTimeBase);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_MCR_GetGTBE(VAR(uint8, AUTOMATIC) u8eMIOS_Index);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_MCR_SetGTBE(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(boolean, AUTOMATIC) beMIOS_GlobalTimeBaseEn);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_MCR_GetFRZ(VAR(uint8, AUTOMATIC) u8eMIOS_Index);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_MCR_SetFRZ(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(boolean, AUTOMATIC) beMIOS_FreezeEnDis);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_MCR_GetMDIS(VAR(uint8, AUTOMATIC) u8eMIOS_Index);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_MCR_SetMDIS(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(boolean, AUTOMATIC) beMIOS_ModuleDis);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_GFLAG_GetFLAGn(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_GFLAG_GetAllFLAG(VAR(uint8, AUTOMATIC) u8eMIOS_Index);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_OUDIS_GetChNumOutUPDDis(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_OUDIS_GetAllChOutUPDDis(VAR(uint8, AUTOMATIC) u8eMIOS_Index);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_OUDIS_SetChNumOutUPDDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_OutUpdateDisable_EnDis \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_OUDIS_SetAllChOutUPDDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint32, AUTOMATIC) u32eMIOS_OutUpdateDisableVal \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_UC_An_GetValue(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_UC_An_GetAddress(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_An_SetValue \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_A_value \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_UC_Bn_GetValue(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Bn_SetValue \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_B_value \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_UC_CNTn_GetValue(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_CNTn_SetValue \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_C_value \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_UC_Cn_GetCtrlCfg(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetCtrlCfg \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_C_value \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetMode(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetMode \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ModeSel \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetEDPOL(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetEDPOL \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_EdgePolar \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetEDSEL(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetEDSEL \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_EdgeSel \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"
/******eMIOS_UC_Cn bit fields: BSL**********************************************/

/* @brief Get Control register: Bus Select bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]BusSel: Bus Select bits(2 bits).
 *
 * @note  The BSL[0:1] bits are used to select either one of the counter buses
 *          or the internal counter to be used by the Unified Channel.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetBSL(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetBSL \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_BusSel \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetFORCMB \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_ForceMatchB \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetFORCMA \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_ForceMatchA \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_UC_Cn_GetFEN(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetFEN \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_FlagEN \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetFCK(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetFCK \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_FilterClkSel \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetIF(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetIF \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_InputFilter \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetDMA(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetDMA \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_IntDmaReqSel \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_UC_Cn_GetUCPREN(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetUCPREN \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_ClkPreEnDis \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetUCPRE(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetUCPRE \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ClkPreDiv \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetODISSL(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"
/* @brief Set Control register: Output Disable select bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u8eMIOS_OutDisSel: Output Disable select bits(2 bits)
 *                  0b00: Output Disable Input 0,
 *                  0b01: Output Disable Input 1,
 *                  0b10: Output Disable Input 2,
 *                  0b11: Output Disable Input 3
 *
 * @note  The ODISSL[0:1] bits select one of the four output disable input signals.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetODISSL \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_OutDisSel \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_UC_Cn_GetODIS(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetODIS \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_OutDis \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_UC_Cn_GetFREN(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetFREN \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_FreezeEn \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_UC_Sn_GetFLAG(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Sn_ClearFLAG(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Sn_GetUCOUT(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Sn_GetUCIN(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_UC_Sn_GetOVFL(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Sn_ClearOVFL(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_UC_Sn_GetOVR(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Sn_ClearOVR(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_UC_ALTAn_GetValue(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_ALTAn_SetValue \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_ALTA_Value \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"
/*******************************************************************************
 * API Function declaration.
 *******************************************************************************/
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(status_t, EMIOS_CODE) eMIOS_LLD_MC_Init \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    P2CONST(eMIOS_MC_ParamType, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_ParamPtr \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(status_t, EMIOS_CODE) eMIOS_LLD_MC_SetPeriod \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_Period \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_LLD_MC_GetPeriod \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_LLD_MC_GetInternalCounter \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
/*******************************************************************************
 * API Function declaration.
 *******************************************************************************/
FUNC(boolean, EMIOS_CODE) eMIOS_DevError_Instance(VAR(uint8, AUTOMATIC) u8eMIOS_Index);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_DevError_ChanNum(VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_InitGlobalParam \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    P2CONST(eMIOS_GlobalParamType, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_GlobalParam \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_SetEnDisGlobal \
(\
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(boolean, AUTOMATIC) beMIOS_EnDisGlobal \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetGLOTimebaseEnDis(VAR(uint8, AUTOMATIC) u8eMIOS_Index);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetGLOPrescalerEnDis(VAR(uint8, AUTOMATIC) u8eMIOS_Index);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_SetLowPowerMode \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(boolean, AUTOMATIC) beMIOS_SwitchOnOff \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetLowPowerMode(VAR(uint8, AUTOMATIC) u8eMIOS_Index);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_SetFreezeInDebugMode \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(boolean, AUTOMATIC) beMIOS_FreezeStatus \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetFreezeInDebugMode(VAR(uint8, AUTOMATIC) u8eMIOS_Index);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetFlagSts_Ch \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_SetChOutputUPDEnDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_OutUpdateEnDis \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetChNumOutUpdateDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_SetAllChOutUPDEnDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(boolean, AUTOMATIC) beMIOS_OutUpdateEnDis \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetAllChOutUpdateDis(VAR(uint8, AUTOMATIC) u8eMIOS_Index);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_DeInitChannel \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(status_t, EMIOS_CODE) eMIOS_LLD_UC_SetDebugMode \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_UcFreezeStatus \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_SetChannelClkEnDis \
(\
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_ClkEnDis \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_LLD_UC_GetChannelClkDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_SetDMARequestEn \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(eMIOS_UC_IntDmaType, EMIOS_CODE) eMIOS_LLD_UC_GetDMAModeStatus \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_SetIntcRequestEn \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_SetOutputLevel \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_EdgeSel, \
    VAR(uint8, AUTOMATIC) u8eMIOS_EdgePol \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_LLD_UC_GetInputPinStatus \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_LLD_UC_GetOutputPinStatus \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_ClearFlag \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#endif /* EMIOS_LLDRIVER_H */

/** @} */

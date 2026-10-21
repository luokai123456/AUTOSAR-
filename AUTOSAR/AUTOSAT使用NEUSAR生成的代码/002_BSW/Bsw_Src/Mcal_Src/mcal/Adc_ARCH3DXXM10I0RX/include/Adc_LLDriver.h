/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : Adc
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
*   @file    Adc_LLDriver.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Adc MCAL driver.
*
*   @addtogroup Adc
*   @{
*/

#ifndef ADC_LLDRIVER_H
#define ADC_LLDRIVER_H

#include "eDma_LLDriver.h"
#include "derivative.h"
#include "Adc_Cfg.h"
#include "Adc_Types.h"

#define ADC_LLD_H_VENDOR_ID                     176
#define ADC_LLD_H_AR_REL_MAJOR_VER              4
#define ADC_LLD_H_AR_REL_MINOR_VER              4
#define ADC_LLD_H_AR_REL_REV_VER                0
#define ADC_LLD_H_SW_MAJOR_VER                  3
#define ADC_LLD_H_SW_MINOR_VER                  0
#define ADC_LLD_H_SW_PATCH_VER                  0

#if (ADC_VENDOR_ID               != ADC_LLD_H_VENDOR_ID)
    #error " NON-MATCHED DATA : ADC_LLD_H_VENDOR_ID "
#endif
#if (ADC_AR_REL_MAJOR_VER    != ADC_LLD_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ADC_LLD_H_AR_REL_MAJOR_VER "
#endif
#if (ADC_AR_REL_MINOR_VER    != ADC_LLD_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ADC_LLD_H_AR_REL_MINOR_VER "
#endif
#if (ADC_AR_REL_REV_VER != ADC_LLD_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ADC_LLD_H_AR_REL_REV_VER "
#endif
#if (ADC_SW_MAJOR_VER        != ADC_LLD_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ADC_LLD_H_SW_MAJOR_VER "
#endif
#if (ADC_SW_MINOR_VER        != ADC_LLD_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ADC_LLD_H_SW_MINOR_VER "
#endif
#if (ADC_SW_PATCH_VER        != ADC_LLD_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ADC_LLD_H_SW_PATCH_VER "
#endif

/* PRQA S 3472 EOF */
/* PRQA S 1534 EOF */
/* PRQA S 3630 EOF */
/* PRQA S 0844 EOF */
/*******************************************************************************
 * EQADC module *    OnChip ADC
 *  EQADCx      *       ADC0
 *              *       ADC1
 *******************************************************************************
 *******************************************************************************
 *  EQADC0      *   ADC0(RM hardware resources: AdcUnit0)
 *              *   ADC1(RM hardware resources: AdcUnit1)
 *******************************************************************************
 *  EQADC1      *   ADC0(RM hardware resources: AdcUnit2)
 *              *   ADC1(RM hardware resources: AdcUnit3)
 *******************************************************************************
 *  EQADC2      *   ADC0(RM hardware resources: AdcUnit4)
 *              *   ADC1(RM hardware resources: AdcUnit5)
 *******************************************************************************
 *  EQADC3      *   ADC0(RM hardware resources: AdcUnit6)
 *              *   ADC1(RM hardware resources: AdcUnit7)
 *******************************************************************************
 *  EQADC4      *   ADC0(RM hardware resources: AdcUnit8)
 *              *   ADC1(RM hardware resources: AdcUnit9)
 *******************************************************************************
 *  EQADC5      *   ADC0(RM hardware resources: AdcUnit10)
 *              *   ADC1(RM hardware resources: AdcUnit11)
 *******************************************************************************
 *  EQADC6      *   ADC0(RM hardware resources: AdcUnit12)
 *              *
 *******************************************************************************/

typedef struct EQADC_tag EQADC_TagType;

#define EQADC_DET_SUPPORT           (FALSE)
#define EQADC_DET_ERR(x)            (DEV_ASSERT(x))

#define EQADC_TIMEOUT_COUNT         (ADC_TIMEOUT)

/* @brief Number of EQADC instances */
#define ADC_EQADC_MAX_INSTANCE      (7U)

/* @brief EQADC - Size of Registers Arrays */
#if defined(RESOURCE_SUPPORT_EQADC_FIFO_CNT)
#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_6)
#define EQADC_CFIFO_COUNT           (6U)
#define EQADC_RFIFO_COUNT           (6U)
#define EQADC_CFCR_U32_REG_COUNT    (3U)    /* Two FIFOs share a 32-bit register. */
#define EQADC_IDCR_U32_REG_COUNT    (3U)    /* Two FIFOs share a 32-bit register. */
#define EQADC_CFTCR_U32_REG_COUNT   (3U)    /* Two FIFOs share a 32-bit register. */
#elif (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#define EQADC_CFIFO_COUNT           (8U)
#define EQADC_RFIFO_COUNT           (8U)
#define EQADC_CFCR_U32_REG_COUNT    (4U)    /* Two FIFOs share a 32-bit register. */
#define EQADC_IDCR_U32_REG_COUNT    (4U)    /* Two FIFOs share a 32-bit register. */
#define EQADC_CFTCR_U32_REG_COUNT   (4U)    /* Two FIFOs share a 32-bit register. */
#else
    #error "EQADC FIFO COUNT error!"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_6 */
#else
    #error "EQADC FIFO COUNT is not defined!"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */

#define EQADC_CFIFO_ENTRY_COUNT     (4U)

#if defined(RESOURCE_SUPPORT_EQADC_RFIFO_ENTRY_CNT)
#if (RESOURCE_SUPPORT_EQADC_RFIFO_ENTRY_CNT == RESOURCE_SUPPORT_EQADC_RFIFO_ENTRY_CNT_4)
#define EQADC_RFIFO_ENTRY_COUNT     (4U)
#elif (RESOURCE_SUPPORT_EQADC_RFIFO_ENTRY_CNT == RESOURCE_SUPPORT_EQADC_RFIFO_ENTRY_CNT_8)
#define EQADC_RFIFO_ENTRY_COUNT     (8U)
#else
    #error "EQADC RFIFO ENTRY COUNT error!"
#endif  /* RESOURCE_SUPPORT_EQADC_RFIFO_ENTRY_CNT == RESOURCE_SUPPORT_EQADC_RFIFO_ENTRY_CNT_4 */
#else
    #error "EQADC RFIFO ENTRY COUNT is not defined!"
#endif  /* RESOURCE_SUPPORT_EQADC_RFIFO_ENTRY_CNT */

/* @brief EQADC instance base address */
#define EQADC0_BASEADDR             ((uint32)0xFFE00000UL)
#define EQADC1_BASEADDR             ((uint32)0xFBE08000UL)
#define EQADC2_BASEADDR             ((uint32)0xFFE10000UL)
#define EQADC3_BASEADDR             ((uint32)0xFBE18000UL)
#define EQADC4_BASEADDR             ((uint32)0xFBE20000UL)
#define EQADC5_BASEADDR             ((uint32)0xFFE04000UL)
#define EQADC6_BASEADDR             ((uint32)0xFFE08000UL)

/* @brief EQADC instance base pointer */
#define EQADC0_PTR                  ((EQADC_TagType *) EQADC0_BASEADDR)
#define EQADC1_PTR                  ((EQADC_TagType *) EQADC1_BASEADDR)
#define EQADC2_PTR                  ((EQADC_TagType *) EQADC2_BASEADDR)
#define EQADC3_PTR                  ((EQADC_TagType *) EQADC3_BASEADDR)
#define EQADC4_PTR                  ((EQADC_TagType *) EQADC4_BASEADDR)
#define EQADC5_PTR                  ((EQADC_TagType *) EQADC5_BASEADDR)
#define EQADC6_PTR                  ((EQADC_TagType *) EQADC6_BASEADDR)

/* @brief EQADC instance base address array */
#define EQADC_BASE_ADDR_ARRAY       {EQADC0_BASEADDR, EQADC1_BASEADDR, EQADC2_BASEADDR, EQADC3_BASEADDR, EQADC4_BASEADDR, EQADC5_BASEADDR, EQADC6_BASEADDR}

/* @brief EQADC instance base pointer array */
#define EQADC_BASE_PTR_ARRAY        {EQADC0_PTR, EQADC1_PTR, EQADC2_PTR, EQADC3_PTR, EQADC4_PTR, EQADC5_PTR, EQADC6_PTR}

/* @brief Number of on-chip ADC modules per EQADC instance */
#define EQADC_ADC_NUM               (2U)
#define EQADC_ALT_CONFIG_NUM        (8U)
#define EQADC_NUM_EXT_ALT_CONFIGS   EQADC_ALT_CONFIG_NUM
#ifdef EQADC_ADC_PUDCR_EN
#define EQADC_PULL_UP_DOWN_CFG_NUM  (8U)
#endif  /* EQADC_ADC_PUDCR_EN */
#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
#define EQADC_RED_LINE_CLIENT_NUM   (2U)
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */

/*******************************************************************************
 * @brief EQADC instance number.
 *
 * @note  This chip has five instances of the EQADC module.
 *******************************************************************************/
typedef enum
{
#ifdef RESOURCE_SUPPORT_EQADC_INST0
    EQADC_INSTANCE_0                = 0U,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_INST1
    EQADC_INSTANCE_1                = 1U,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_INST2
    EQADC_INSTANCE_2                = 2U,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_INST3
    EQADC_INSTANCE_3                = 3U,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_INST4
    EQADC_INSTANCE_4                = 4U,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_INST5
    EQADC_INSTANCE_5                = 5U,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_INST6
    EQADC_INSTANCE_6                = 6U
#endif
} EqadcInstanceType;

/*******************************************************************************
 * @brief EQADCx's on-chip ADC number.
 *
 * @note  Each EQADC module: controls two independent analog-to-digital (ADC):
 *          ADC0 and ADC1.
 *******************************************************************************/
typedef enum
{
    EQADC_ADC_0                     = 0U,
    EQADC_ADC_1                     = 1U
} EqadcAdcIdxType;

/*******************************************************************************
 * @brief EQADC ADC hardware unit number
 *******************************************************************************/
#ifdef RESOURCE_SUPPORT_EQADC_INST0
#define EQADC_ADC_UNIT_0            (0U)    /* EQADC_INSTANCE_0 -> EQADC_ADC_0 */
#define EQADC_ADC_UNIT_1            (1U)    /* EQADC_INSTANCE_0 -> EQADC_ADC_1 */
#endif  /* RESOURCE_SUPPORT_EQADC_INST0 */
#ifdef RESOURCE_SUPPORT_EQADC_INST1
#define EQADC_ADC_UNIT_2            (2U)    /* EQADC_INSTANCE_1 -> EQADC_ADC_0 */
#define EQADC_ADC_UNIT_3            (3U)    /* EQADC_INSTANCE_1 -> EQADC_ADC_1 */
#endif  /* RESOURCE_SUPPORT_EQADC_INST1 */
#ifdef RESOURCE_SUPPORT_EQADC_INST2
#define EQADC_ADC_UNIT_4            (4U)    /* EQADC_INSTANCE_2 -> EQADC_ADC_0 */
#define EQADC_ADC_UNIT_5            (5U)    /* EQADC_INSTANCE_2 -> EQADC_ADC_1 */
#endif  /* RESOURCE_SUPPORT_EQADC_INST2 */
#ifdef RESOURCE_SUPPORT_EQADC_INST3
#define EQADC_ADC_UNIT_6            (6U)    /* EQADC_INSTANCE_3 -> EQADC_ADC_0 */
#define EQADC_ADC_UNIT_7            (7U)    /* EQADC_INSTANCE_3 -> EQADC_ADC_1 */
#endif  /* RESOURCE_SUPPORT_EQADC_INST3 */
#ifdef RESOURCE_SUPPORT_EQADC_INST4
#define EQADC_ADC_UNIT_8            (8U)    /* EQADC_INSTANCE_4 -> EQADC_ADC_0 */
#define EQADC_ADC_UNIT_9            (9U)    /* EQADC_INSTANCE_4 -> EQADC_ADC_1 */
#endif  /* RESOURCE_SUPPORT_EQADC_INST4 */
#ifdef RESOURCE_SUPPORT_EQADC_INST5
#define EQADC_ADC_UNIT_10           (10U)   /* EQADC_INSTANCE_5 -> EQADC_ADC_0 */
#define EQADC_ADC_UNIT_11           (11U)   /* EQADC_INSTANCE_5 -> EQADC_ADC_1 */
#endif  /* RESOURCE_SUPPORT_EQADC_INST5 */
#ifdef RESOURCE_SUPPORT_EQADC_INST6
#define EQADC_ADC_UNIT_12           (12U)   /* EQADC_INSTANCE_6 -> EQADC_ADC_0 */
#endif  /* RESOURCE_SUPPORT_EQADC_INST6 */

/*******************************************************************************
 * @brief EQADCx's CFIFO/RFIFO number.
 *
 * @note  Each EQADC module: CFIFO + RFIFO.
 *******************************************************************************/
typedef enum
{
    EQADC_FIFO_0                    = 0U,
    EQADC_FIFO_1                    = 1U,
    EQADC_FIFO_2                    = 2U,
    EQADC_FIFO_3                    = 3U,
    EQADC_FIFO_4                    = 4U,
    EQADC_FIFO_5                    = 5U
#if defined(RESOURCE_SUPPORT_EQADC_FIFO_CNT)
#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
    ,
    EQADC_FIFO_6                    = 6U,
    EQADC_FIFO_7                    = 7U
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8 */
#else
    #error "EQADC FIFO COUNT is not defined!"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */
} EqadcFifoIdxType;

#ifdef RESOURCE_SUPPORT_EQADC_RFIFO_CLK_SWITCH
typedef enum
{
    EQADC_RFIFO_CLK_SWITCH_IPS      = 0U,
    EQADC_RFIFO_CLK_SWITCH_GTM      = 1U,
    EQADC_RFIFO_CLK_SWITCH_ERROR    = 2U
} Eqadc_RFifoClkSwitchType;
#endif  /* RESOURCE_SUPPORT_EQADC_RFIFO_CLK_SWITCH */

typedef enum
{
    EQADC_FISR_NON_COHERENCY        = 0U,
    EQADC_FISR_TRIG_OVERRUN         = 1U,
    EQADC_FISR_PAUSE                = 2U,
    EQADC_FISR_END_OF_QUEUE         = 3U,
    EQADC_FISR_CFIFO_UNDERFLOW      = 4U,
    EQADC_FISR_CFIFO_SINGLE_SCAN    = 5U,
    EQADC_FISR_CFIFO_FILL           = 6U,
    EQADC_FISR_RFIFO_OVERFLOW       = 7U,
    EQADC_FISR_RFIFO_DRAIN          = 8U,
    EQADC_FISR_CFIFO_ENTRY_COUNT    = 9U,
    EQADC_FISR_CFIFO_TRANS_NEXT_PTR = 10U,
    EQADC_FISR_RFIFO_ENTRY_COUNT    = 11U,
    EQADC_FISR_RFIFO_POP_NEXT_PTR   = 12U
} Eqadc_FifoIntStatusType;

typedef enum
{
    EQADC_CFIFO_MODE_DISABLE                        = 0U,   /* CFIFO Operation Mode: Disabled */
    EQADC_CFIFO_MODE_SINGLE_SW_TRIG                 = 1U,   /* CFIFO Operation Mode: Software Trigger, Single Scan */
    EQADC_CFIFO_MODE_SINGLE_LOW_LVL_GATED_EXT_TRIG  = 2U,   /* CFIFO Operation Mode: Low Level Gated External Trigger, Single Scan */
    EQADC_CFIFO_MODE_SINGLE_HIGH_LVL_GATED_EXT_TRIG = 3U,   /* CFIFO Operation Mode: High Level Gated External Trigger, Single Scan */
    EQADC_CFIFO_MODE_SINGLE_FALLING_EDGE_EXT_TRIG   = 4U,   /* CFIFO Operation Mode: Falling Edge External Trigger, Single Scan */
    EQADC_CFIFO_MODE_SINGLE_RISING_EDGE_EXT_TRIG    = 5U,   /* CFIFO Operation Mode: Rising Edge External Trigger, Single Scan */
    EQADC_CFIFO_MODE_SINGLE_BOTH_EDGES_EXT_TRIG     = 6U,   /* CFIFO Operation Mode: Falling or Rising Edge External Trigger, Single Scan */
    EQADC_CFIFO_MODE_CONT_SW_TRIG                   = 9U,   /* CFIFO Operation Mode: Software Trigger, Continuous Scan */
    EQADC_CFIFO_MODE_CONT_LOW_LVL_GATED_EXT_TRIG    = 10U,  /* CFIFO Operation Mode: Low Level Gated External Trigger, Continuous Scan */
    EQADC_CFIFO_MODE_CONT_HIGH_LVL_GATED_EXT_TRIG   = 11U,  /* CFIFO Operation Mode: High Level Gated External Trigger, Continuous Scan */
    EQADC_CFIFO_MODE_CONT_FALLING_EDGE_EXT_TRIG     = 12U,  /* CFIFO Operation Mode: Falling Edge External Trigger, Continuous Scan */
    EQADC_CFIFO_MODE_CONT_RISING_EDGE_EXT_TRIG      = 13U,  /* CFIFO Operation Mode: Rising Edge External Trigger, Continuous Scan */
    EQADC_CFIFO_MODE_CONT_BOTH_EDGES_EXT_TRIG       = 14U   /* CFIFO Operation Mode: Falling or Rising Edge External Trigger, Continuous Scan */
} Eqadc_CfifoModeType;

typedef enum
{
    EQADC_CFIFO0_AMODE_DISABLE                          = 0U,   /* CFIFO0 Advance Trigger Operation Mode: Disabled */
    EQADC_CFIFO0_AMODE_SINGLE_SW_TRIG                   = 1U,   /* CFIFO0 Advance Trigger Operation Mode: Software Trigger, Single Scan */
    EQADC_CFIFO0_AMODE_SINGLE_LOW_LVL_GATED_EXT_TRIG    = 2U,   /* CFIFO0 Advance Trigger Operation Mode: Low Level Gated External Trigger, Single Scan */
    EQADC_CFIFO0_AMODE_SINGLE_HIGH_LVL_GATED_EXT_TRIG   = 3U,   /* CFIFO0 Advance Trigger Operation Mode: High Level Gated External Trigger, Single Scan */
    EQADC_CFIFO0_AMODE_SINGLE_FALLING_EDGE_EXT_TRIG     = 4U,   /* CFIFO0 Advance Trigger Operation Mode: Falling Edge External Trigger, Single Scan */
    EQADC_CFIFO0_AMODE_SINGLE_RISING_EDGE_EXT_TRIG      = 5U,   /* CFIFO0 Advance Trigger Operation Mode: Rising Edge External Trigger, Single Scan */
    EQADC_CFIFO0_AMODE_SINGLE_BOTH_EDGES_EXT_TRIG       = 6U    /* CFIFO0 Advance Trigger Operation Mode: Falling or Rising Edge External Trigger, Single Scan */
} Eqadc_Cfifo0AModeType;

typedef enum
{
    EQADC_FILL_SEL_INT          = 0U,
    EQADC_FILL_SEL_DMA          = 1U,
    EQADC_FILL_NOT_INT          = 2U
} Eqadc_IntDmaFillSelType;

#ifdef RESOURCE_SUPPORT_EQADC_FIFO_DMA_CTRL_SEL
typedef enum
{
    EQADC_FIFO_SEL_DMA_0        = 0U,
    EQADC_FIFO_SEL_DMA_1        = 1U
} Eqadc_FifoDMACtrlSelType;
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_DMA_CTRL_SEL */

#ifdef RESOURCE_SUPPORT_EQADC_CFG_PRECHARGE
typedef enum
{
    EQADC_PRECHARGE_DISABLED    = 0U,
    EQADC_PRECHARGE_CLK_CYCLE_1 = 1U,
    EQADC_PRECHARGE_CLK_CYCLE_2 = 2U,
    EQADC_PRECHARGE_CLK_CYCLE_3 = 3U,
    EQADC_PRECHARGE_CLK_CYCLE_4 = 4U,
    EQADC_PRECHARGE_CLK_CYCLE_5 = 5U,
    EQADC_PRECHARGE_CLK_CYCLE_6 = 6U,
    EQADC_PRECHARGE_CLK_CYCLE_7 = 7U
} Eqadc_PrechargeClkCycleSelType;
#endif  /* RESOURCE_SUPPORT_EQADC_CFG_PRECHARGE */

/*******************************************************************************
 * @brief Time Base Counter Clock Prescaler (ADC_TSCR: TBC_CLK_PS).
 *
 * @note  If TBC_CLK_PS is not set to disabled,
 *          it must not be changed to any other value besides disabled.
 *******************************************************************************/
typedef enum
{
    EQADC_TBC_CLK_PS_DISABLED   = 0U,   /* The time base counter clock prescaler is disabled */
    EQADC_TBC_CLK_PS_DIV_1      = 1U,   /* System clock divide factor: 1 */
    EQADC_TBC_CLK_PS_DIV_2      = 2U,   /* System clock divide factor: 2 */
    EQADC_TBC_CLK_PS_DIV_4      = 3U,   /* System clock divide factor: 4 */
    EQADC_TBC_CLK_PS_DIV_6      = 4U,   /* System clock divide factor: 6 */
    EQADC_TBC_CLK_PS_DIV_8      = 5U,   /* System clock divide factor: 8 */
    EQADC_TBC_CLK_PS_DIV_10     = 6U,   /* System clock divide factor: 10 */
    EQADC_TBC_CLK_PS_DIV_12     = 7U,   /* System clock divide factor: 12 */
    EQADC_TBC_CLK_PS_DIV_16     = 8U,   /* System clock divide factor: 16 */
    EQADC_TBC_CLK_PS_DIV_32     = 9U,   /* System clock divide factor: 32 */
    EQADC_TBC_CLK_PS_DIV_64     = 10U,  /* System clock divide factor: 64 */
    EQADC_TBC_CLK_PS_DIV_128    = 11U,  /* System clock divide factor: 128 */
    EQADC_TBC_CLK_PS_DIV_256    = 12U,  /* System clock divide factor: 256 */
    EQADC_TBC_CLK_PS_DIV_512    = 13U   /* System clock divide factor: 512 */
} Eqadc_TimeBaseCountClkPresType;

/*******************************************************************************
 * @brief Time base Selection for ADC0/1 (ADCx_CR: ADCx_TBSEL).
 *
 * @note  This selection is overridden by the corresponding field ATBSEL in the
 *          ADC_ACRx registers when the alternate conversion command is used.
 *******************************************************************************/
typedef enum
{
    EQADC_TBS_INTERNAL          = 0U,   /* Selects internally generated time base as time stamp */
    EQADC_TBS_STACCCR_SRV1      = 1U,   /* Selects imported time base 1 indicated by SRV1 bit field of EQADC_STACCCR */
    EQADC_TBS_STACCCR_SRV2      = 2U    /* Selects imported time base 2 indicated by SRV2 bit field of EQADC_STACCCR */
} Eqadc_TimeBaseSelType;

/*******************************************************************************
 * @brief Clock Selector for ADC0/1 (ADCx_CR: ADCx_CLK_SEL).
 *
 * @note  The ADC0/1_CLK_SEL bits must only be written when the ADC0/1_EN bit
 *          is negated.
 *        ADC0/1_CLK_SEL can be set during the same write cycle used to set
 *          ADC0/1_EN.
 *******************************************************************************/
typedef enum
{
    EQADC_CLK_SEL_PS_DIV        = 0U    /* Prescaler output clock is selected: EQADC_CLK_PS_DIV_x. */
#ifdef EQADC_ADC_CR_CLK_SEL_EN
    ,
    EQADC_CLK_SEL_MAX_FREQ      = 1U    /* Platform clock is selected: maximum frequency. */
#endif  /* EQADC_ADC_CR_CLK_SEL_EN */
} Eqadc_ClkSelType;

/*******************************************************************************
 * @brief Clock Prescaler Field for ADC0/1 (ADCx_CR: ADCx_CLK_PS).
 *
 * @note  The ADC0/1_CLK_PS bits must only be written when the ADC0/1_EN bit
 *          is negated.
 *        ADC0/1_CLK_PS can be set during the same write cycle used to set
 *          ADC0/1_EN.
 *******************************************************************************/
typedef enum
{
    EQADC_CLK_PS_DIV_2          = 0U,   /* Platform Clock Divide Factor: 2 */
    EQADC_CLK_PS_DIV_4          = 1U,   /* Platform Clock Divide Factor: 4 */
    EQADC_CLK_PS_DIV_6          = 2U,   /* Platform Clock Divide Factor: 6 */
    EQADC_CLK_PS_DIV_8          = 3U,   /* Platform Clock Divide Factor: 8 */
    EQADC_CLK_PS_DIV_10         = 4U,   /* Platform Clock Divide Factor: 10 */
    EQADC_CLK_PS_DIV_12         = 5U,   /* Platform Clock Divide Factor: 12 */
    EQADC_CLK_PS_DIV_14         = 6U,   /* Platform Clock Divide Factor: 14 */
    EQADC_CLK_PS_DIV_16         = 7U,   /* Platform Clock Divide Factor: 16 */
    EQADC_CLK_PS_DIV_18         = 8U,   /* Platform Clock Divide Factor: 18 */
    EQADC_CLK_PS_DIV_20         = 9U,   /* Platform Clock Divide Factor: 20 */
    EQADC_CLK_PS_DIV_22         = 10U,  /* Platform Clock Divide Factor: 22 */
    EQADC_CLK_PS_DIV_24         = 11U,  /* Platform Clock Divide Factor: 24 */
    EQADC_CLK_PS_DIV_26         = 12U,  /* Platform Clock Divide Factor: 26 */
    EQADC_CLK_PS_DIV_28         = 13U,  /* Platform Clock Divide Factor: 28 */
    EQADC_CLK_PS_DIV_30         = 14U,  /* Platform Clock Divide Factor: 30 */
    EQADC_CLK_PS_DIV_32         = 15U,  /* Platform Clock Divide Factor: 32 */
    EQADC_CLK_PS_DIV_34         = 16U,  /* Platform Clock Divide Factor: 34 */
    EQADC_CLK_PS_DIV_36         = 17U,  /* Platform Clock Divide Factor: 36 */
    EQADC_CLK_PS_DIV_38         = 18U,  /* Platform Clock Divide Factor: 38 */
    EQADC_CLK_PS_DIV_40         = 19U,  /* Platform Clock Divide Factor: 40 */
    EQADC_CLK_PS_DIV_42         = 20U,  /* Platform Clock Divide Factor: 42 */
    EQADC_CLK_PS_DIV_44         = 21U,  /* Platform Clock Divide Factor: 44 */
    EQADC_CLK_PS_DIV_46         = 22U,  /* Platform Clock Divide Factor: 46 */
    EQADC_CLK_PS_DIV_48         = 23U,  /* Platform Clock Divide Factor: 48 */
    EQADC_CLK_PS_DIV_50         = 24U,  /* Platform Clock Divide Factor: 50 */
    EQADC_CLK_PS_DIV_52         = 25U,  /* Platform Clock Divide Factor: 52 */
    EQADC_CLK_PS_DIV_54         = 26U,  /* Platform Clock Divide Factor: 54 */
    EQADC_CLK_PS_DIV_56         = 27U,  /* Platform Clock Divide Factor: 56 */
    EQADC_CLK_PS_DIV_58         = 28U,  /* Platform Clock Divide Factor: 58 */
    EQADC_CLK_PS_DIV_60         = 29U,  /* Platform Clock Divide Factor: 60 */
    EQADC_CLK_PS_DIV_62         = 30U,  /* Platform Clock Divide Factor: 62 */
    EQADC_CLK_PS_DIV_64         = 31U   /* Platform Clock Divide Factor: 64 */
} Eqadc_ClkPrescaleType;

typedef enum
{
    EQADC_ALT_CONFIG_DISABLE    = 0x0U,     /* Select Standard Configuration for the conversion command */
    EQADC_ALT_CONFIG_SEL_1      = 0x8U,     /* Select Alternate Configuration 1 for the conversion command */
    EQADC_ALT_CONFIG_SEL_2      = 0x9U,     /* Select Alternate Configuration 2 for the conversion command */
    EQADC_ALT_CONFIG_SEL_3      = 0xAU,     /* Select Alternate Configuration 3 for the conversion command */
    EQADC_ALT_CONFIG_SEL_4      = 0xBU,     /* Select Alternate Configuration 4 for the conversion command */
    EQADC_ALT_CONFIG_SEL_5      = 0xCU,     /* Select Alternate Configuration 5 for the conversion command */
    EQADC_ALT_CONFIG_SEL_6      = 0xDU,     /* Select Alternate Configuration 6 for the conversion command */
    EQADC_ALT_CONFIG_SEL_7      = 0xEU,     /* Select Alternate Configuration 7 for the conversion command */
    EQADC_ALT_CONFIG_SEL_8      = 0xFU      /* Select Alternate Configuration 8 for the conversion command */
} Eqadc_AltConfigSelType;

typedef enum
{
    EQADC_ALT_DEST_RFIFO        = 0x0U,
    EQADC_ALT_DEST_DECFILT_A    = 0x1U,
    EQADC_ALT_DEST_DECFILT_B    = 0x2U,
    EQADC_ALT_DEST_DECFILT_C    = 0x3U,
    EQADC_ALT_DEST_DECFILT_D    = 0x4U,
    EQADC_ALT_DEST_DECFILT_E    = 0x5U,
    EQADC_ALT_DEST_DECFILT_F    = 0x6U,
    EQADC_ALT_DEST_DECFILT_G    = 0x7U,
    EQADC_ALT_DEST_DECFILT_A_E  = 0x8U,
    EQADC_ALT_DEST_DECFILT_B_E  = 0x9U,
    EQADC_ALT_DEST_DECFILT_C_E  = 0xAU,
    EQADC_ALT_DEST_DECFILT_D_E  = 0xBU,
    EQADC_ALT_DEST_DECFILT_A_G  = 0xCU,
    EQADC_ALT_DEST_DECFILT_B_G  = 0xDU,
    EQADC_ALT_DEST_DECFILT_C_G  = 0xEU,
    EQADC_ALT_DEST_DECFILT_D_G  = 0xFU
} Eqadc_AltConfigDestType;

typedef enum
{
    EQADC_RES_SEL_12_BITS       = 0U,
    EQADC_RES_SEL_10_BITS       = 1U,
    EQADC_RES_SEL_8_BITS        = 2U
} Eqadc_ResolutionSelType;

typedef enum
{
    EQADC_PRE_GAIN_X1           = 0U,
    EQADC_PRE_GAIN_X2           = 1U,
    EQADC_PRE_GAIN_X4           = 2U
} Eqadc_PreGainType;

typedef enum
{
    EQADC_CH_PULL_DISABLED      = 0U,
    EQADC_CH_PULL_UP            = 1U,
    EQADC_CH_PULL_DOWN          = 2U,
    EQADC_CH_PULL_UP_DOWN       = 3U
} Eqadc_ChanPullType;

typedef enum
{
    EQADC_PULL_STR_200KOHM      = 1U,
    EQADC_PULL_STR_100KOHM      = 2U,
    EQADC_PULL_STR_5KOHM        = 3U
} Eqadc_PullStrengthType;

#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
#define EQADC_STAC_BUS_CLIENT_1 (0U)
#define EQADC_STAC_BUS_CLIENT_2 (1U)

typedef enum
{
    EQADC_SRV_ETPU_A_TCR_1      = 0U,
    EQADC_SRV_ETPU_B_TCR_1      = 1U,
    EQADC_SRV_ETPU_A_TCR_2      = 2U,
    EQADC_SRV_ETPU_B_TCR_2      = 3U
} Eqadc_RedLineServerDataSlotSelType;

typedef enum
{
    EQADC_REDLINE_BITS_SEL_TBASE_0_15   = 0U,
    EQADC_REDLINE_BITS_SEL_TBASE_1_16   = 1U,
    EQADC_REDLINE_BITS_SEL_TBASE_2_17   = 2U,
    EQADC_REDLINE_BITS_SEL_TBASE_3_18   = 3U,
    EQADC_REDLINE_BITS_SEL_TBASE_4_19   = 4U,
    EQADC_REDLINE_BITS_SEL_TBASE_5_20   = 5U,
    EQADC_REDLINE_BITS_SEL_TBASE_6_21   = 6U,
    EQADC_REDLINE_BITS_SEL_TBASE_7_22   = 7U,
    EQADC_REDLINE_BITS_SEL_TBASE_8_23   = 8U
} Eqadc_RedLineBitsSelType;
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */

typedef enum
{
    EQADC_CFIFO_STATUS_IDLE             = 0U,
    EQADC_CFIFO_STATUS_WAITING_FOR_TRIG = 2U,
    EQADC_CFIFO_STATUS_TRIGGERED        = 3U
} Eqadc_CfifoStatusType;

#ifdef RESOURCE_SUPPORT_EQADC_CMD_OSR
typedef enum
{
    EQADC_OVERSAMPLE_DISABLED           = 0U,
    EQADC_OVERSAMPLE_RATE_4             = 1U,
    EQADC_OVERSAMPLE_RATE_16            = 2U,
    EQADC_OVERSAMPLE_RATE_64            = 3U,
    EQADC_OVERSAMPLE_RATE_256           = 4U
} Eqadc_OverSampleRateSelType;
#endif  /* RESOURCE_SUPPORT_EQADC_CMD_OSR */

typedef enum
{
    EQADC_MSG_TAG_RFIFO0                = 0U,
    EQADC_MSG_TAG_RFIFO1                = 1U,
    EQADC_MSG_TAG_RFIFO2                = 2U,
    EQADC_MSG_TAG_RFIFO3                = 3U,
    EQADC_MSG_TAG_RFIFO4                = 4U,
    EQADC_MSG_TAG_RFIFO5                = 5U,
#if defined(RESOURCE_SUPPORT_EQADC_FIFO_CNT)
#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
    EQADC_MSG_TAG_RFIFO6                = 6U,
    EQADC_MSG_TAG_RFIFO7                = 7U,
#endif /* RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8 */
#else
    #error "EQADC FIFO COUNT is not defined!"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */
    EQADC_MSG_TAG_NULL_MSG              = 8U,
    EQADC_MSG_TAG_RESERVED_0            = 9U,
    EQADC_MSG_TAG_RESERVED_1            = 10U
} Eqadc_RfifoMsgTagType;

#if defined(RESOURCE_SUPPORT_EQADC_CMD_LST)
#if (RESOURCE_SUPPORT_EQADC_CMD_LST == RESOURCE_SUPPORT_EQADC_CMD_LST_2BIT)
typedef enum
{
    EQADC_ADCLK_SAMPLING_CYCLES_2       = 0U,
    EQADC_ADCLK_SAMPLING_CYCLES_8       = 1U,
    EQADC_ADCLK_SAMPLING_CYCLES_64      = 2U,
    EQADC_ADCLK_SAMPLING_CYCLES_128     = 3U
} Eqadc_LongSampTimeType;
#elif (RESOURCE_SUPPORT_EQADC_CMD_LST == RESOURCE_SUPPORT_EQADC_CMD_LST_3BIT)
typedef enum
{
    EQADC_ADCLK_SAMPLING_CYCLES_2       = 0U,
    EQADC_ADCLK_SAMPLING_CYCLES_4       = 1U,
    EQADC_ADCLK_SAMPLING_CYCLES_6       = 2U,
    EQADC_ADCLK_SAMPLING_CYCLES_8       = 3U,
    EQADC_ADCLK_SAMPLING_CYCLES_16      = 4U,
    EQADC_ADCLK_SAMPLING_CYCLES_32      = 5U,
    EQADC_ADCLK_SAMPLING_CYCLES_64      = 6U,
    EQADC_ADCLK_SAMPLING_CYCLES_128     = 7U
} Eqadc_LongSampTimeType;
#else
    #error "Eqadc_LongSampTimeType error!"
#endif  /* RESOURCE_SUPPORT_EQADC_CMD_LST == RESOURCE_SUPPORT_EQADC_CMD_LST_2BIT */
#else
    #error "RESOURCE_SUPPORT_EQADC_CMD_LST  is not defined!"
#endif  /* RESOURCE_SUPPORT_EQADC_CMD_LST */

typedef enum
{
    EQADC_CONFIG_CMD_WRITE              = 0U,
    EQADC_CONFIG_CMD_READ               = 1U
} Eqadc_RwConfigCmdType;

typedef enum
{
    EQADC_ADC_REG_CR         = 0x01U,    /* The address of ADC0/ADC1 Configuration Control Register */
    EQADC_ADC_REG_TSCR       = 0x02U,    /* The address of Time Stamp Control Register */
    EQADC_ADC_REG_TBCR       = 0x03U,    /* The address of Time Base Counter Register */
    EQADC_ADC_REG_GCCR       = 0x04U,    /* The address of ADC0/ADC1 Gain Calibration Constant Register */
    EQADC_ADC_REG_OCCR       = 0x05U,    /* The address of ADC0/ADC1 Offset Calibration Constant Register */
    EQADC_ADC_REG_ACR1       = 0x30U,    /* The address of Alternate Configuration 1 Control Register */
    EQADC_ADC_REG_AGR1       = 0x31U,    /* The address of ADC0/ADC1 Alternate Gain 1 Register */
    EQADC_ADC_REG_AOR1       = 0x32U,    /* The address of ADC0/ADC1 Alternate Offset 1 Register */
    EQADC_ADC_REG_ACR2       = 0x34U,    /* The address of Alternate Configuration 2 Control Register */
    EQADC_ADC_REG_AGR2       = 0x35U,    /* The address of ADC0/ADC1 Alternate Gain 2 Register */
    EQADC_ADC_REG_AOR2       = 0x36U,    /* The address of ADC0/ADC1 Alternate Offset 2 Register */
    EQADC_ADC_REG_ACR3       = 0x38U,    /* The address of Alternate Configuration 3 Control Register */
    EQADC_ADC_REG_ACR4       = 0x3CU,    /* The address of Alternate Configuration 4 Control Register */
    EQADC_ADC_REG_ACR5       = 0x40U,    /* The address of Alternate Configuration 5 Control Register */
    EQADC_ADC_REG_ACR6       = 0x44U,    /* The address of Alternate Configuration 6 Control Register */
    EQADC_ADC_REG_ACR7       = 0x48U,    /* The address of Alternate Configuration 7 Control Register */
    EQADC_ADC_REG_ACR8       = 0x4CU     /* The address of Alternate Configuration 8 Control Register */
#ifdef EQADC_ADC_PUDCR_EN
    ,
    EQADC_ADC_REG_PUDCR0     = 0x70U,    /* The address of Pull Up/Down Control Register 0 */
    EQADC_ADC_REG_PUDCR1     = 0x71U,    /* The address of Pull Up/Down Control Register 1 */
    EQADC_ADC_REG_PUDCR2     = 0x72U,    /* The address of Pull Up/Down Control Register 2 */
    EQADC_ADC_REG_PUDCR3     = 0x73U,    /* The address of Pull Up/Down Control Register 3 */
    EQADC_ADC_REG_PUDCR4     = 0x74U,    /* The address of Pull Up/Down Control Register 4 */
    EQADC_ADC_REG_PUDCR5     = 0x75U,    /* The address of Pull Up/Down Control Register 5 */
    EQADC_ADC_REG_PUDCR6     = 0x76U,    /* The address of Pull Up/Down Control Register 6 */
    EQADC_ADC_REG_PUDCR7     = 0x77U     /* The address of Pull Up/Down Control Register 7 */
#endif  /* EQADC_ADC_PUDCR_EN */
} Eqadc_OnChipAdcRegAddrType;

#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
/* @brief Option to configure the internal connection between GTM and ADC */
#define GTM_ADC_TRIG_MEMBER_NUM         (12U)
/* GTM TRIG ADC Trigger selection(0 ~ 15) */
#define GTM_ADC_TRIG_OUTSEL_NO_TRIG     (0x0U)
#define GTM_ADC_TRIG_OUTSEL_1           (0x1U)
#define GTM_ADC_TRIG_OUTSEL_2           (0x2U)
#define GTM_ADC_TRIG_OUTSEL_3           (0x3U)
#define GTM_ADC_TRIG_OUTSEL_4           (0x4U)
#define GTM_ADC_TRIG_OUTSEL_5           (0x5U)
#define GTM_ADC_TRIG_OUTSEL_6           (0x6U)
#define GTM_ADC_TRIG_OUTSEL_7           (0x7U)
#define GTM_ADC_TRIG_OUTSEL_8           (0x8U)
#define GTM_ADC_TRIG_OUTSEL_9           (0x9U)
#define GTM_ADC_TRIG_OUTSEL_10          (0xAU)
#define GTM_ADC_TRIG_OUTSEL_11          (0xBU)
#define GTM_ADC_TRIG_OUTSEL_12          (0xCU)
#define GTM_ADC_TRIG_OUTSEL_13          (0xDU)
#define GTM_ADC_TRIG_OUTSEL_14          (0xEU)
#define GTM_ADC_TRIG_OUTSEL_15          (0xFU)
#define GTM_ADC_TRIG_OUTSEL_MASK        (0xFU)
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */

/*******************************************************************************
 * @brief Structure for on-chip ADC.
 *
 * @note on-chip ADC0/ADC1
 *******************************************************************************/
typedef struct
{
    /* Index of the on-chip ADC to be configured. */
    VAR(EqadcAdcIdxType, AUTOMATIC) AdcIdx;

    /* External Multiplexer enable/disable for ADC0/1. */
    VAR(boolean, AUTOMATIC) AdcExtMuxEn;

    /* Time base Selection for ADC0/1 */
    VAR(Eqadc_TimeBaseSelType, AUTOMATIC) TimeBaseSel;

    /* Clock Selector for ADC0/1 */
    VAR(Eqadc_ClkSelType, AUTOMATIC) ClkSel;

    /* Clock Prescaler Field for ADC0/1 */
    VAR(Eqadc_ClkPrescaleType, AUTOMATIC) ClkPrescale;

    /* It is a unsigned 15-bit fixed pointed value.
     * The gain calibration constant is an unsigned fixed point number expressed
     *  in the GCC_INT.GCC_FRAC binary format. */
    VAR(uint16, AUTOMATIC) AdcGainCalibConst;

    /* OCC0/1 contains the offset calibration constant used to fine-tune ADC0/1 conversion results.
     * Negative values should be expressed using the two's complement representation. */
    VAR(sint16, AUTOMATIC) AdcOffsetCalibConst;
    VAR(boolean, AUTOMATIC) ImmediateConvCmdEn;

#ifdef RESOURCE_SUPPORT_EQADC_CFG_PRECHARGE
    Eqadc_PrechargeClkCycleSelType PrechargeClkCycleSel;
#endif  /* RESOURCE_SUPPORT_EQADC_CFG_PRECHARGE */
} Eqadc_AdcConfigType;

/*******************************************************************************
 * @brief Structure for CFIFO (Command FIFO).
 *
 * @note
 *******************************************************************************/
typedef struct
{
    VAR(EqadcFifoIdxType, AUTOMATIC) CfifoIdx;
    VAR(Eqadc_CfifoModeType, AUTOMATIC) CfifoMode;
    VAR(Eqadc_IntDmaFillSelType, AUTOMATIC) IntDmaFillSel;
    VAR(uint8, AUTOMATIC) DmaMappedChan;
    VAR(boolean,  AUTOMATIC) DmaChanDisReqOnTransComplete;
    P2VAR(uint32, AUTOMATIC, ADC_APPL_DATA ) SourcePtr;
    VAR(uint32, AUTOMATIC) SourceLen;
    VAR(eDMACallbackType, AUTOMATIC) Callback;
    P2VAR(void, AUTOMATIC, ADC_APPL_DATA ) CallbackParam;
    VAR(uint8, AUTOMATIC) HwTrigSel;  /* SIUL/SIUL2 ISELx */
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
    VAR(uint8, AUTOMATIC) CfifoGtmAdcTrigOutsel;
#endif
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
    VAR(boolean,  AUTOMATIC) CfifoTrigDelayEn;   /* CFIFO Trigger Delay enable */
    VAR(uint32, AUTOMATIC) CfifoTrigDelayVal; /* CFIFO Trigger Delay configuration value */
#endif

    /* CFIFO0 only */
    VAR(boolean, AUTOMATIC) Cfifo0EntryExtensionEn;
    VAR(Eqadc_Cfifo0AModeType, AUTOMATIC) Cfifo0AdvanceMode;
    VAR(uint8, AUTOMATIC) Cfifo0AdvanceTrigSel;   /* SIUL/SIUL2 ISELx */

#ifdef RESOURCE_SUPPORT_EQADC_CFIFO_INJECTION
    boolean CfifoInjectionEn;   /* CFIFO6/CFIFO7 only */
#endif  /* RESOURCE_SUPPORT_EQADC_CFIFO_INJECTION */
} Eqadc_CfifoConfigType;

typedef struct
{
    VAR(EqadcFifoIdxType, AUTOMATIC) RfifoIdx;
    VAR(uint8, AUTOMATIC) ResultDmaMappedChan;
    P2VAR(uint16, AUTOMATIC, ADC_APPL_DATA ) DestPtr;
    VAR(uint32, AUTOMATIC) DestLen;
    VAR(eDMACallbackType, AUTOMATIC) Callback;
    P2VAR(void, AUTOMATIC, ADC_APPL_DATA ) CallbackParam;
    VAR(boolean, AUTOMATIC) EnHalfDestCallback;
} Eqadc_ResultDmaConfigType;

typedef struct
{
    VAR(Eqadc_AltConfigSelType, AUTOMATIC) AltConfigSel;
    VAR(boolean, AUTOMATIC) ResultTransInhibit;
    VAR(Eqadc_AltConfigDestType, AUTOMATIC) AltConvResultDEST;
    VAR(boolean, AUTOMATIC) FMTA_SignEn;
    VAR(Eqadc_ResolutionSelType, AUTOMATIC) AdcResSel;
    VAR(Eqadc_PreGainType, AUTOMATIC) AdcPreGain;
    /* Alternate Configuration 1: Alternate Gain 1(ADC0 and ADC1) + Alternate Offset 1(ADC0 and ADC1),
     * Alternate Configuration 2: Alternate Gain 2(ADC0 and ADC1) + Alternate Offset 2(ADC0 and ADC1) */
    VAR(uint16, AUTOMATIC) AdcAltGain[EQADC_ADC_NUM];
    VAR(uint16, AUTOMATIC) AdcAltOffset[EQADC_ADC_NUM];
} Eqadc_AlternateConfigType;

#ifdef EQADC_ADC_PUDCR_EN
typedef struct
{
    VAR(uint8,  AUTOMATIC) AdcChIdx;
    Eqadc_ChanPullType ChanPull;
    Eqadc_PullStrengthType PullStrength;
} Eqadc_PullUpDownCfgType;
#endif  /* EQADC_ADC_PUDCR_EN */

#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
typedef struct
{
    VAR(uint8, AUTOMATIC) clientIdx;
    VAR(Eqadc_RedLineBitsSelType, AUTOMATIC) TimeBaseBitsSel;
    VAR(Eqadc_RedLineServerDataSlotSelType, AUTOMATIC) SRVnSel;
} Eqadc_RedLineClientConfigType;
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */

typedef struct
{
    VAR(EqadcInstanceType, AUTOMATIC) Eqadc_HwInstId;

    /* Debug mode entry request (EQADC_MCR DBG) */
    VAR(boolean, AUTOMATIC) DebugModeEn;

    /* External Trigger Digital Filter Length (EQADC_ETDFR DFL) */
    VAR(uint8, AUTOMATIC) ExtTrigDigitalFilterLen;

    VAR(Eqadc_TimeBaseCountClkPresType, AUTOMATIC) TimeBasePresDiv;

#ifdef RESOURCE_SUPPORT_EQADC_RFIFO_CLK_SWITCH
    Eqadc_RFifoClkSwitchType ClkSwitchRfifo[EQADC_RFIFO_COUNT];
#endif  /* RESOURCE_SUPPORT_EQADC_RFIFO_CLK_SWITCH */
} EqadcHwInstanceType;

typedef struct
{
    P2VAR(EqadcHwInstanceType, AUTOMATIC, ADC_APPL_DATA ) EqadcHwInst;
    VAR(uint8, AUTOMATIC) AdcConfigNum;
    P2VAR(Eqadc_AdcConfigType, AUTOMATIC, ADC_APPL_DATA ) AdcConfigArray;
    VAR(uint8, AUTOMATIC) CfifoConfigNum;
    P2VAR(Eqadc_CfifoConfigType, AUTOMATIC, ADC_APPL_DATA ) CfifoConfigArray;
    VAR(uint8, AUTOMATIC) ResultDmaConfigNum;
    P2VAR(Eqadc_ResultDmaConfigType, AUTOMATIC, ADC_APPL_DATA ) ResultDmaConfigArray;
    VAR(uint8, AUTOMATIC) AlternateConfigNum;
    P2VAR(Eqadc_AlternateConfigType, AUTOMATIC, ADC_APPL_DATA ) AlternateConfigArray;
#ifdef EQADC_ADC_PUDCR_EN
    VAR(uint8, AUTOMATIC) PullUpDownCfgNum;
    Eqadc_PullUpDownCfgType * PullUpDownCfgArray;
#endif  /* EQADC_ADC_PUDCR_EN */
#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
    VAR(uint8, AUTOMATIC) RedLineClientConfigNum;
    P2VAR(Eqadc_RedLineClientConfigType, AUTOMATIC, ADC_APPL_DATA ) RedLineClientConfigArray;
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */
} Adc_EqadcConfigType;

typedef struct
{
    VAR(boolean, AUTOMATIC) Eoq;
    VAR(boolean, AUTOMATIC) Pause;
    VAR(boolean, AUTOMATIC) RepeatStart;
    VAR(uint8, AUTOMATIC) cBufNum;
    VAR(boolean, AUTOMATIC) CalibConvResEn;
    VAR(EqadcFifoIdxType, AUTOMATIC) RfifoMsgTag;
    VAR(Eqadc_LongSampTimeType, AUTOMATIC) LongSampTime;
    VAR(boolean, AUTOMATIC) TimeStampReq;
    VAR(boolean, AUTOMATIC) FormatSignEn;
    VAR(uint8, AUTOMATIC) ChanNum;
    VAR(Eqadc_AltConfigSelType, AUTOMATIC) AltConfigSel;
    VAR(boolean, AUTOMATIC) FlushOrFMT;
#ifdef RESOURCE_SUPPORT_EQADC_CMD_OSR
    Eqadc_OverSampleRateSelType OverSampleRate;
#endif  /* RESOURCE_SUPPORT_EQADC_CMD_OSR */
} Eqadc_ConvCmdType;

typedef struct
{
    VAR(boolean, AUTOMATIC) Eoq;
    VAR(boolean, AUTOMATIC) Pause;
    VAR(boolean, AUTOMATIC) RepeatStart;
    VAR(uint8, AUTOMATIC) cBufNum;
    VAR(Eqadc_RwConfigCmdType, AUTOMATIC) RwCfgCmdType;
    VAR(uint16, AUTOMATIC) AdcRegValue;
    VAR(Eqadc_OnChipAdcRegAddrType, AUTOMATIC) AdcRegAddr;
    VAR(Eqadc_RfifoMsgTagType, AUTOMATIC) RfifoMsgTag;
} Eqadc_ConfigCmdType;

typedef enum
{
    EQADC_CAL_STANDARD_CONFIG   = EQADC_ALT_CONFIG_DISABLE, /* ADCx_GCCR, ADCx_OCCR */
    EQADC_CAL_ALT_CONFIG_1      = EQADC_ALT_CONFIG_SEL_1,   /* ADCx_AGR1, ADCx_AOR1 */
    EQADC_CAL_ALT_CONFIG_2      = EQADC_ALT_CONFIG_SEL_2    /* ADCx_AGR2, ADCx_AOR2 */
} Eqadc_CalibCfgSelType;

typedef struct
{
    VAR(Eqadc_CalibCfgSelType, AUTOMATIC) CalibCfgSel;
    VAR(EqadcFifoIdxType, AUTOMATIC) CfifoIdx;
    VAR(EqadcFifoIdxType, AUTOMATIC) RfifoIdx;
    VAR(Eqadc_LongSampTimeType, AUTOMATIC) LongSampTime;
    VAR(uint32, AUTOMATIC) TimeoutCal;
    VAR(uint16, AUTOMATIC) GainCalibConst;
    VAR(sint16, AUTOMATIC) OffsetCalibConst;
} Eqadc_CalibConfigInfoType;

typedef struct
{
    VAR(uint8, AUTOMATIC) AdcConfigNum;
    P2VAR(Eqadc_AdcConfigType, AUTOMATIC, ADC_APPL_DATA ) AdcConfigArray;
} Eqadc_AdcConfigTempType;

typedef struct
{
    VAR(uint8, AUTOMATIC) CfifoConfigNum;
    P2VAR(Eqadc_CfifoConfigType, AUTOMATIC, ADC_APPL_DATA ) CfifoConfigArray;
} Eqadc_CfifoConfigTempType;

typedef struct
{
    VAR(uint8, AUTOMATIC) ResultDmaConfigNum;
    P2VAR(Eqadc_ResultDmaConfigType, AUTOMATIC, ADC_APPL_DATA ) ResultDmaConfig;
} Eqadc_ResultDmaConfigTempType;

/* Internal Channel Function Enable */
#define SSCM_VRC33_ENABLE           (*(volatile uint32 *)(0xFFFF8038UL))
#define EQADC_PCT_VREF_EN_MSAK      (0x00000004U)
#define EQADC_TSENS_EN_MSAK         (0x00000008U)

/* EQADC Resolution count */
#define EQADC_RESOLUTION_BIT12      (0x3FFCU)   /* Resolution 12 bits: 0xFFFU << 2U */
#define EQADC_RESOLUTION_BIT10      (0x3FF0U)   /* Resolution 10 bits: 0x3FFU << 4U */
#define EQADC_RESOLUTION_BIT8       (0x3FC0U)   /* Resolution 8 bits:  0xFFU << 6U  */

/* EQADC Reference voltage value (millivolt) */
#if (ADC_VREF_POWER_SUPPLY == ADC_VREF_5V)
#define EQADC_VRH_MVOLT             (5000U)
#define EQADC_PCT50_VREF_MVOLT      (2500U)
#define EQADC_PCT75_VREF_MVOLT      (3750U)
#define EQADC_PCT25_VREF_MVOLT      (1250U)
#define EQADC_PCT75_VREF_CAL_RES    (12285U)    /* CAL_Result(expected), (5V * 75% * 4095(12 bits) / 5V) << 2U */
#define EQADC_PCT25_VREF_CAL_RES    (4095U)     /* CAL_Result(expected), (5V * 25% * 4095(12 bits) / 5V) << 2U */
#elif (ADC_VREF_POWER_SUPPLY == ADC_VREF_3V3)
#define EQADC_VRH_MVOLT             (3300U)
#define EQADC_PCT50_VREF_MVOLT      (1650U)
#define EQADC_PCT75_VREF_MVOLT      (2475U)
#define EQADC_PCT25_VREF_MVOLT      (825U)
#define EQADC_PCT75_VREF_CAL_RES    (12285U)    /* CAL_Result(expected), (3.3V * 75% * 4095(12 bits) / 3.3V) << 2U */
#define EQADC_PCT25_VREF_CAL_RES    (4095U)     /* CAL_Result(expected), (3.3V * 25% * 4095(12 bits) / 3.3V) << 2U */
#else
    #error "ADC_VREF_POWER_SUPPLY error!"
#endif  /* ADC_VREF_POWER_SUPPLY */
#define EQADC_VRL_MVOLT             (0U)
#define EQADC_VDD3V3_MVOLT          (3300U)
#define EQADC_VDD_PMU_MVOLT         (1000U)
#define EQADC_VDD_LV_MVOLT          (1100U)

#define EQADC_ADC_GCC_INT_WIDTH     (1U)
#define EQADC_ADC_GCC_FRAC_WIDTH    (14U)
#define EQADC_ADC_GCC_WIDTH         (EQADC_ADC_GCC_INT_WIDTH + EQADC_ADC_GCC_FRAC_WIDTH)

#define EQADC_ADC_OCC_FORM1         (1U)
#define EQADC_ADC_OCC_FORM2         (2U)
#define EQADC_ADC_OCC_FORM          EQADC_ADC_OCC_FORM1

/*******************************************************************************
 * EQADC On-Chip ADC Read/Write LowLevelDriver switch(For test).
 *******************************************************************************/
#define EQADC_ONCHIPADC_RW_LLD      (TRUE)

#define DEM_EVENTID_DEINIT              (0x0U)
#define DEM_EVENTID_SETADCREGVALUESSE   (0x1U)
#define DEM_EVENTID_GETADCREGVALUESSE   (0x2U)
#define DME_EVENTID_INIT                (0x3U)

#define DEM_EVENT_TIMEOUT   (0x0U)

/*******************************************************************************
 * Function declaration.
 *******************************************************************************/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_Eqadc_LLD_Init(CONST(EqadcInstanceType, ADC_CONST) eAdc_EqadcInst, CONSTP2CONST(Adc_EqadcConfigType, ADC_CONST, ADC_APPL_CONST ) sAdc_ConfigPtr);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(void, ADC_CODE) Adc_Eqadc_LLD_DeInit(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_EQADC_CALIBRATION
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(status_t, ADC_CODE) EQADC_LLD_CalibConvResult(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcAdcIdxType, ADC_CONST) eAdc_AdcIdx, CONSTP2VAR(Eqadc_CalibConfigInfoType, ADC_CONST, ADC_APPL_CONST) pAdc_CalCfgPtr);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_CALIBRATION */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(uint8, ADC_CODE) EQADC_LLD_GetDebugEnDis(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(void, ADC_CODE) EQADC_LLD_SetDebugEnDis(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(boolean, ADC_CONST) bAdc_EnDis);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_EQADC_RFIFO_CLK_SWITCH
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern Eqadc_RFifoClkSwitchType EQADC_LLD_GetRfifoClkSwitch(const EqadcInstanceType instance, const EqadcFifoIdxType RfifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern status_t EQADC_LLD_RfifoClkSwitch(const EqadcInstanceType instance, const EqadcFifoIdxType RfifoIdx, const Eqadc_RFifoClkSwitchType ClkSwitch);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_RFIFO_CLK_SWITCH */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(uint8, ADC_CODE) EQADC_LLD_GetExtTrigDigitalFilterLength(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(void, ADC_CODE) EQADC_LLD_SetExtTrigDigitalFilterLength(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(uint8, ADC_CONST) u8Adc_DigitalFilterLen);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(void, ADC_CODE) EQADC_LLD_SetCQueueConfigCmd(CONSTP2CONST(Eqadc_ConfigCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConfigCmdPtr, CONST(uint8, ADC_CONST) u8Adc_CmdCount, CONSTP2VAR(uint32, ADC_CONST, ADC_APPL_CONST) pAdc_CQueueMemDest);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(void, ADC_CODE) EQADC_LLD_CfifoPushConvCmd(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, CONSTP2CONST(Eqadc_ConvCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConvCmdPtr);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(void, ADC_CODE) EQADC_LLD_SetCQueueConvCmd(CONSTP2CONST(Eqadc_ConvCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConvCmdPtr, CONST(uint16, ADC_CONST) u16Adc_CmdCount, CONST(uint16, ADC_CONST) u16Adc_StreamNumSamp, CONST(uint16, ADC_CONST) u16Adc_DmaSampleNum, CONSTP2VAR(uint32, ADC_CONST, ADC_APPL_CONST) pAdc_CQueueMemDest);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(uint16, ADC_CODE) EQADC_LLD_RfifoPopData(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_RfifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern uint32 EQADC_LLD_RfifoPopData32bit(const EqadcInstanceType instance, const EqadcFifoIdxType RfifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(void, ADC_CODE) EQADC_LLD_SingleScanEn(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(void, ADC_CODE) EQADC_LLD_SingleScanEn_Sync(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(status_t, ADC_CODE) EQADC_LLD_SetCfifoInvalidate(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(Eqadc_CfifoModeType, ADC_CODE) EQADC_LLD_GetCfifoMode(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(status_t, ADC_CODE) EQADC_LLD_SetCfifoMode(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, CONST(Eqadc_CfifoModeType, ADC_CONST) eAdc_CfifoModeTarget);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(uint8, ADC_CODE) EQADC_LLD_GetCfifo0EntryExtEnDis(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(void, ADC_CODE) EQADC_LLD_SetCfifo0EntryExtEnDis(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(boolean, ADC_CONST) bAdc_EnDis);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(Eqadc_Cfifo0AModeType, ADC_CODE) EQADC_LLD_GetCfifo0AdvanceMode(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(status_t, ADC_CODE) EQADC_LLD_SetCfifo0AdvanceMode(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(Eqadc_Cfifo0AModeType, ADC_CONST) eAdc_AdvanceTrigMode);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(void, ADC_CODE) EQADC_LLD_IntEnDis(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_FifoIdx, VAR(uint16, AUTOMATIC) u16Adc_IntMask, VAR(boolean, AUTOMATIC) bAdc_EnDis);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(void, ADC_CODE) EQADC_LLD_ClearFifoIntFlag(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_FifoIdx, VAR(uint32, AUTOMATIC) u32Adc_FifoFlagMask);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(uint16, ADC_CODE) EQADC_LLD_GetCfifoTransferCounter(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(void, ADC_CODE) EQADC_LLD_SetCfifoTransferCounter(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, CONST(uint16, ADC_CONST) u16Adc_TransCount);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(Eqadc_CfifoStatusType, ADC_CODE) EQADC_LLD_GetCFifoStatusSnapshot(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, CONST(EqadcAdcIdxType, ADC_CONST) eAdc_AdcIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(EqadcFifoIdxType, ADC_CODE) EQADC_LLD_GetLastCFifoSnapshot(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcAdcIdxType, ADC_CONST) eAdc_AdcIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(uint16, ADC_CODE) EQADC_LLD_GetTransCountLastCFifoSnapshot(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcAdcIdxType, ADC_CONST) eAdc_AdcIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(void, ADC_CODE) EQADC_LLD_SetCfifoTrigDelay(CONST(EqadcInstanceType, ADC_CONST) eAdc_instance, CONST(EqadcFifoIdxType, ADC_CONST)  eAdc_CfifoIdx, CONST(boolean, ADC_CONST)  eAdc_CfifoTrigDelayEn, CONST(uint32, ADC_CONST) eAdc_CfifoTrigDelayCnt);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */

#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(void, ADC_CODE) EQADC_LLD_SetRedLineClientConfig(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(uint8, ADC_CONST) u8Adc_ClientIdx, CONST(Eqadc_RedLineBitsSelType, ADC_CONST) eAdc_RedLineTbaseBitSel, CONST(Eqadc_RedLineServerDataSlotSelType, ADC_CONST) eAdc_RedLineSlotSel);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(uint32, ADC_CODE) EQADC_LLD_GetCfifoEntryData(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, CONST(uint8, ADC_CONST) u8Adc_EntryIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(uint32, ADC_CODE) EQADC_LLD_GetCfifo0ExtEntryData(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(uint8, ADC_CONST) u8Adc_EntryIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(uint32, ADC_CODE) EQADC_LLD_GetRfifoEntryData(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_RfifoIdx, CONST(uint8, ADC_CONST) u8Adc_EntryIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if EQADC_ONCHIPADC_RW_LLD
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(void, ADC_CODE) EQADC_LLD_SetAdcRegValueSSE(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcAdcIdxType, ADC_CONST) eAdc_AdcIdx, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) eAdc_AdcReg, CONST(uint16, ADC_CONST) u16Adc_AdcRegVal);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern FUNC(uint16, ADC_CODE) EQADC_LLD_GetAdcRegValueSSE(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcAdcIdxType, ADC_CONST) eAdc_AdcIdx, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_RfifoIdx, CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) eAdc_AdcReg);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* EQADC_ONCHIPADC_RW_LLD */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_CFCRxSetInvalidate(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_ISELx_SetCfifoTrig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, CONST(uint8, ADC_CONST) u8Adc_TrigSourceVal);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_CFCRx_SetCfifoxEntryExtEnDis(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, CONST(boolean, ADC_CONST) bAdc_EnDis);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_CFCRx_SetAMode0(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, CONST(uint32, ADC_CONST) u32Adc_Cfifo0AdvanceMode0);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_CFCR_CfifoStreamModeEnDis(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, CONST(boolean, ADC_CONST) bAdc_EnDis);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_ISELx_SetCfifo0AdvanceTrig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_AdvanceTrigVal);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_IDCRx_FifoIntDmaEnDis(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_FifoIdx, CONST(uint16, ADC_CONST) u16Adc_FifoIntDmaMask, CONST(boolean, ADC_CONST) bAdc_EnDis);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_SetCfifoHwTrigSource(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, CONST(uint8, ADC_CONST) eAdc_TrigSourceSel, CONST(uint8, ADC_CONST) eAdc_GTM_ADC_TRIG_OUTSEL);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#else
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_SetCfifoHwTrigSource(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, CONST(uint8, ADC_CONST) eAdc_TrigSourceSel);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(uint32, ADC_CODE) EQADC_LLD_GetFifoIntFlag(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_FifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(uint16, ADC_CODE) EQADC_LLD_GetIntDmaCtrlEn(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_FifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_SetCfifo0AdvanceTrigSource(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(uint8, ADC_CONST) eAdc_AdvTrigSourceSel);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_EQADC_RFIFO_SOFT_RESET
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern status_t EQADC_LLD_RfifoSoftwareReset(const EqadcInstanceType instance, const EqadcFifoIdxType RfifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_RFIFO_SOFT_RESET */

#ifdef RESOURCE_SUPPORT_EQADC_FIFO_DMA_CTRL_SEL
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern void EQADC_LLD_FifoDmaControllerSelect(const EqadcInstanceType instance, const EqadcFifoIdxType CfifoIdx, const EqadcFifoIdxType RfifoIdx, const Eqadc_FifoDMACtrlSelType DMA_Sel);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern void EQADC_LLD_CfifoDmaControllerSelect(const EqadcInstanceType instance, const EqadcFifoIdxType CfifoIdx, const Eqadc_FifoDMACtrlSelType DMA_Sel);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
extern void EQADC_LLD_RfifoDmaControllerSelect(const EqadcInstanceType instance, const EqadcFifoIdxType RfifoIdx, const Eqadc_FifoDMACtrlSelType DMA_Sel);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_DMA_CTRL_SEL */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_CFCRxSetMode(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, CONST(uint32, ADC_CONST) u32Adc_CfifoModeTarget);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Eqadc_CfifoStatusType, ADC_CODE) EQADC_LLD_GetCFifoStatus \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_DmaEnDis(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_FifoIdx, VAR(uint16, AUTOMATIC) u16Adc_DmaMask, VAR(boolean, AUTOMATIC) bAdc_EnDis);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc_SetResultDmaConfig(CONST(EqadcInstanceType, ADC_CONST) eAdc_EqadcInst, P2CONST(Eqadc_ResultDmaConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_ResultDmaConfig);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(status_t, ADC_CODE) EQADC_SetCfifoConfig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONSTP2CONST(Eqadc_CfifoConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_CfifoCfgPtr);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(uint8, ADC_CODE) EQADC_LLD_GetFifoFlagStatus(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_FifoIdx, CONST(Eqadc_FifoIntStatusType, ADC_CONST) eAdc_FifoStatusSel);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc_SetAlternateConfig(CONST(EqadcInstanceType, ADC_CONST) eAdc_EqadcInst, VAR(EqadcFifoIdxType, ADC_VAR) eAdc_Cfifo_x, P2CONST(Eqadc_AlternateConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_AlternateConfig);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc_DeinitAlternateConfig(CONST(EqadcInstanceType, ADC_CONST) eAdc_EqadcInst, VAR(EqadcFifoIdxType, ADC_VAR) eAdc_Cfifo_x);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_InternalFuncEn(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#endif /* ADC_LLDriver_H_ */

/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     eqadc_lld.h
* @version  1.0
* @date     2023 - 01 - 01
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/

#ifndef SAF_EQADC_LLD_H_
#define SAF_EQADC_LLD_H_
#include "derivative.h"
#include "status.h"
#include "edma_lld.h"
#include "siul_lld.h"
#include "siul2_lld.h"

/* PRQA S 0779 EOF */
/* PRQA S 3472 EOF */
/* PRQA S 1534,1535 EOF */
/* PRQA S 2052 EOF */
/* PRQA S 3630 EOF */

/*******************************************************************************
 * SAF_EQADC module *    OnChip ADC
 *  SAF_EQADCx      *       ADC0
 *              *       ADC1
 *******************************************************************************
 *******************************************************************************
 *  SAF_EQADC0      *   ADC0(RM hardware resources: ADC0)
 *              *   ADC1(RM hardware resources: ADC1)
 *******************************************************************************
 *  SAF_EQADC1      *   ADC0(RM hardware resources: ADC2)
 *              *   ADC1(RM hardware resources: ADC3)
 *******************************************************************************
 *  SAF_EQADC2      *   ADC0(RM hardware resources: ADC4)
 *              *   ADC1(RM hardware resources: ADC5)
 *******************************************************************************
 *  SAF_EQADC3      *   ADC0(RM hardware resources: ADC6)
 *              *   ADC1(RM hardware resources: ADC7)
 *******************************************************************************
 *  SAF_EQADC4      *   ADC0(RM hardware resources: ADC8)
 *              *   ADC1(RM hardware resources: ADC9)
 *******************************************************************************/
typedef struct EQADC_tag SAF_EQADC_TagType;

#define SAF_EQADC_DET_SUPPORT           (TRUE)
#define SAF_EQADC_DET_ERR(x)            DEV_ASSERT(x)

#define SAF_EQADC_TIMEOUT_COUNT         (0x001FFFFFU)

/* @brief Number of SAF_EQADC instances */

#define ADC_SAF_EQADC_MAX_INSTANCE      (7U)

/* @brief SAF_EQADC - Size of Registers Arrays */
#define SAF_EQADC_CFIFO_COUNT           (6U)
#define SAF_EQADC_RFIFO_COUNT           (6U)
#define SAF_EQADC_CFIFO_ENTRY_COUNT     (4U)
#define SAF_EQADC_RFIFO_ENTRY_COUNT     (4U)

/* @brief SAF_EQADC instance base address */
#define SAF_EQADC0_BASEADDR             ((uint32_t)0xFFE00000UL)
#define SAF_EQADC1_BASEADDR             ((uint32_t)0xFBE08000UL)
#define SAF_EQADC2_BASEADDR             ((uint32_t)0xFFE10000UL)
#define SAF_EQADC3_BASEADDR             ((uint32_t)0xFBE18000UL)
#define SAF_EQADC4_BASEADDR             ((uint32_t)0xFBE20000UL)
#define SAF_EQADC5_BASEADDR             ((uint32_t)0xFFE04000UL)
#define SAF_EQADC6_BASEADDR             ((uint32_t)0xFFE08000UL)

/* @brief SAF_EQADC instance base pointer */
#define SAF_EQADC0_PTR                  ((SAF_EQADC_TagType *) SAF_EQADC0_BASEADDR)
#define SAF_EQADC1_PTR                  ((SAF_EQADC_TagType *) SAF_EQADC1_BASEADDR)
#define SAF_EQADC2_PTR                  ((SAF_EQADC_TagType *) SAF_EQADC2_BASEADDR)
#define SAF_EQADC3_PTR                  ((SAF_EQADC_TagType *) SAF_EQADC3_BASEADDR)
#define SAF_EQADC4_PTR                  ((SAF_EQADC_TagType *) SAF_EQADC4_BASEADDR)
#define SAF_EQADC5_PTR                  ((SAF_EQADC_TagType *) SAF_EQADC5_BASEADDR)
#define SAF_EQADC6_PTR                  ((SAF_EQADC_TagType *) SAF_EQADC6_BASEADDR)

/* @brief SAF_EQADC instance base address array */
#define SAF_EQADC_BASE_ADDR_ARRAY       {SAF_EQADC0_BASEADDR, SAF_EQADC1_BASEADDR, SAF_EQADC2_BASEADDR, SAF_EQADC3_BASEADDR, SAF_EQADC4_BASEADDR, SAF_EQADC5_BASEADDR, SAF_EQADC6_BASEADDR}

/* @brief SAF_EQADC instance base pointer array */
#define SAF_EQADC_BASE_PTR_ARRAY        {SAF_EQADC0_PTR, SAF_EQADC1_PTR, SAF_EQADC2_PTR, SAF_EQADC3_PTR, SAF_EQADC4_PTR, SAF_EQADC5_PTR, SAF_EQADC6_PTR}

/* @brief Number of on-chip ADC modules per SAF_EQADC instance */
#define SAF_EQADC_ADC_NUM               (2U)
#define SAF_EQADC_ALT_CONFIG_NUM        (14U) //  SEL NUM? TODO
#define SAF_EQADC_NUM_EXT_ALT_CONFIGS   SAF_EQADC_ALT_CONFIG_NUM
#define SAF_EQADC_PULL_UP_DOWN_CFG_NUM  (40U)
#define SAF_EQADC_RED_LINE_CLIENT_NUM   (2U)

/*******************************************************************************
 * EQADC Register Bit Fields
 *******************************************************************************/
/* MCR Bit Fields */
#define SAF_EQADC_MCR_DBG_MASK                       0x3u
#define SAF_EQADC_MCR_DBG_SHIFT                      0u
#define SAF_EQADC_MCR_DBG_WIDTH                      2u
#define SAF_EQADC_MCR_DBG(x)                         (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_MCR_DBG_SHIFT))&SAF_EQADC_MCR_DBG_MASK)
#define SAF_EQADC_MCR_DAM_MASK                       0x20u
#define SAF_EQADC_MCR_DAM_SHIFT                      5u
#define SAF_EQADC_MCR_DAM_WIDTH                      1u
#define SAF_EQADC_MCR_DAM(x)                         (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_MCR_DAM_SHIFT))&SAF_EQADC_MCR_DAM_MASK)
#define SAF_EQADC_MCR_ICEA1_MASK                     0x40u
#define SAF_EQADC_MCR_ICEA1_SHIFT                    6u
#define SAF_EQADC_MCR_ICEA1_WIDTH                    1u
#define SAF_EQADC_MCR_ICEA1(x)                       (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_MCR_ICEA1_SHIFT))&SAF_EQADC_MCR_ICEA1_MASK)
#define SAF_EQADC_MCR_ICEA0_MASK                     0x80u
#define SAF_EQADC_MCR_ICEA0_SHIFT                    7u
#define SAF_EQADC_MCR_ICEA0_WIDTH                    1u
#define SAF_EQADC_MCR_ICEA0(x)                       (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_MCR_ICEA0_SHIFT))&SAF_EQADC_MCR_ICEA0_MASK)
/* ETDFR Bit Fields */
#define SAF_EQADC_ETDFR_DFL_MASK                     0xFu
#define SAF_EQADC_ETDFR_DFL_SHIFT                    0u
#define SAF_EQADC_ETDFR_DFL_WIDTH                    4u
#define SAF_EQADC_ETDFR_DFL(x)                       (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_ETDFR_DFL_SHIFT))&SAF_EQADC_ETDFR_DFL_MASK)
/* CFPR Bit Fields */
#define SAF_EQADC_CFPR_CF_PUSHX_MASK                 0xFFFFFFFFu
#define SAF_EQADC_CFPR_CF_PUSHX_SHIFT                0u
#define SAF_EQADC_CFPR_CF_PUSHX_WIDTH                32u
#define SAF_EQADC_CFPR_CF_PUSHX(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFPR_CF_PUSHX_SHIFT))&SAF_EQADC_CFPR_CF_PUSHX_MASK)
/* RFPR Bit Fields */
#define SAF_EQADC_RFPR_RF_POPX_MASK                  0xFFFFu
#define SAF_EQADC_RFPR_RF_POPX_SHIFT                 0u
#define SAF_EQADC_RFPR_RF_POPX_WIDTH                 16u
#define SAF_EQADC_RFPR_RF_POPX(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_RFPR_RF_POPX_SHIFT))&SAF_EQADC_RFPR_RF_POPX_MASK)
/* CFCR0 Bit Fields */
#define SAF_EQADC_CFCR0_MODE1_MASK                   0xF0u
#define SAF_EQADC_CFCR0_MODE1_SHIFT                  4u
#define SAF_EQADC_CFCR0_MODE1_WIDTH                  4u
#define SAF_EQADC_CFCR0_MODE1(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR0_MODE1_SHIFT))&SAF_EQADC_CFCR0_MODE1_MASK)
#define SAF_EQADC_CFCR0_CFINV1_MASK                  0x200u
#define SAF_EQADC_CFCR0_CFINV1_SHIFT                 9u
#define SAF_EQADC_CFCR0_CFINV1_WIDTH                 1u
#define SAF_EQADC_CFCR0_CFINV1(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR0_CFINV1_SHIFT))&SAF_EQADC_CFCR0_CFINV1_MASK)
#define SAF_EQADC_CFCR0_SSE1_MASK                    0x400u
#define SAF_EQADC_CFCR0_SSE1_SHIFT                   10u
#define SAF_EQADC_CFCR0_SSE1_WIDTH                   1u
#define SAF_EQADC_CFCR0_SSE1(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR0_SSE1_SHIFT))&SAF_EQADC_CFCR0_SSE1_MASK)
#define SAF_EQADC_CFCR0_AMODE0_MASK                  0xF0000u
#define SAF_EQADC_CFCR0_AMODE0_SHIFT                 16u
#define SAF_EQADC_CFCR0_AMODE0_WIDTH                 4u
#define SAF_EQADC_CFCR0_AMODE0(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR0_AMODE0_SHIFT))&SAF_EQADC_CFCR0_AMODE0_MASK)
#define SAF_EQADC_CFCR0_MODE0_MASK                   0xF00000u
#define SAF_EQADC_CFCR0_MODE0_SHIFT                  20u
#define SAF_EQADC_CFCR0_MODE0_WIDTH                  4u
#define SAF_EQADC_CFCR0_MODE0(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR0_MODE0_SHIFT))&SAF_EQADC_CFCR0_MODE0_MASK)
#define SAF_EQADC_CFCR0_CFINV0_MASK                  0x2000000u
#define SAF_EQADC_CFCR0_CFINV0_SHIFT                 25u
#define SAF_EQADC_CFCR0_CFINV0_WIDTH                 1u
#define SAF_EQADC_CFCR0_CFINV0(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR0_CFINV0_SHIFT))&SAF_EQADC_CFCR0_CFINV0_MASK)
#define SAF_EQADC_CFCR0_SSE0_MASK                    (0x4000000u)
#define SAF_EQADC_CFCR0_SSE0_SHIFT                   26u
#define SAF_EQADC_CFCR0_SSE0_WIDTH                   1u
#define SAF_EQADC_CFCR0_SSE0(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR0_SSE0_SHIFT))&SAF_EQADC_CFCR0_SSE0_MASK)
#define SAF_EQADC_CFCR0_STRME0_MASK                  0x8000000u
#define SAF_EQADC_CFCR0_STRME0_SHIFT                 27u
#define SAF_EQADC_CFCR0_STRME0_WIDTH                 1u
#define SAF_EQADC_CFCR0_STRME0(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR0_STRME0_SHIFT))&SAF_EQADC_CFCR0_STRME0_MASK)
#define SAF_EQADC_CFCR0_CFEEE0_MASK                  0x10000000u
#define SAF_EQADC_CFCR0_CFEEE0_SHIFT                 28u
#define SAF_EQADC_CFCR0_CFEEE0_WIDTH                 1u
#define SAF_EQADC_CFCR0_CFEEE0(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR0_CFEEE0_SHIFT))&SAF_EQADC_CFCR0_CFEEE0_MASK)
/* CFCR1 Bit Fields */
#define SAF_EQADC_CFCR1_MODE3_MASK                   0xF0u
#define SAF_EQADC_CFCR1_MODE3_SHIFT                  4u
#define SAF_EQADC_CFCR1_MODE3_WIDTH                  4u
#define SAF_EQADC_CFCR1_MODE3(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR1_MODE3_SHIFT))&SAF_EQADC_CFCR1_MODE3_MASK)
#define SAF_EQADC_CFCR1_CFINV3_MASK                  0x200u
#define SAF_EQADC_CFCR1_CFINV3_SHIFT                 9u
#define SAF_EQADC_CFCR1_CFINV3_WIDTH                 1u
#define SAF_EQADC_CFCR1_CFINV3(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR1_CFINV3_SHIFT))&SAF_EQADC_CFCR1_CFINV3_MASK)
#define SAF_EQADC_CFCR1_SSE3_MASK                    0x400u
#define SAF_EQADC_CFCR1_SSE3_SHIFT                   10u
#define SAF_EQADC_CFCR1_SSE3_WIDTH                   1u
#define SAF_EQADC_CFCR1_SSE3(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR1_SSE3_SHIFT))&SAF_EQADC_CFCR1_SSE3_MASK)
#define SAF_EQADC_CFCR1_MODE2_MASK                   0xF00000u
#define SAF_EQADC_CFCR1_MODE2_SHIFT                  20u
#define SAF_EQADC_CFCR1_MODE2_WIDTH                  4u
#define SAF_EQADC_CFCR1_MODE2(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR1_MODE2_SHIFT))&SAF_EQADC_CFCR1_MODE2_MASK)
#define SAF_EQADC_CFCR1_CFINV2_MASK                  0x2000000u
#define SAF_EQADC_CFCR1_CFINV2_SHIFT                 25u
#define SAF_EQADC_CFCR1_CFINV2_WIDTH                 1u
#define SAF_EQADC_CFCR1_CFINV2(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR1_CFINV2_SHIFT))&SAF_EQADC_CFCR1_CFINV2_MASK)
#define SAF_EQADC_CFCR1_SSE2_MASK                    0x4000000u
#define SAF_EQADC_CFCR1_SSE2_SHIFT                   26u
#define SAF_EQADC_CFCR1_SSE2_WIDTH                   1u
#define SAF_EQADC_CFCR1_SSE2(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR1_SSE2_SHIFT))&SAF_EQADC_CFCR1_SSE2_MASK)
/* CFCR2 Bit Fields */
#define SAF_EQADC_CFCR2_MODE5_MASK                   0xF0u
#define SAF_EQADC_CFCR2_MODE5_SHIFT                  4u
#define SAF_EQADC_CFCR2_MODE5_WIDTH                  4u
#define SAF_EQADC_CFCR2_MODE5(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR2_MODE5_SHIFT))&SAF_EQADC_CFCR2_MODE5_MASK)
#define SAF_EQADC_CFCR2_CFINV5_MASK                  0x200u
#define SAF_EQADC_CFCR2_CFINV5_SHIFT                 9u
#define SAF_EQADC_CFCR2_CFINV5_WIDTH                 1u
#define SAF_EQADC_CFCR2_CFINV5(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR2_CFINV5_SHIFT))&SAF_EQADC_CFCR2_CFINV5_MASK)
#define SAF_EQADC_CFCR2_SSE5_MASK                    0x400u
#define SAF_EQADC_CFCR2_SSE5_SHIFT                   10u
#define SAF_EQADC_CFCR2_SSE5_WIDTH                   1u
#define SAF_EQADC_CFCR2_SSE5(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR2_SSE5_SHIFT))&SAF_EQADC_CFCR2_SSE5_MASK)
#define SAF_EQADC_CFCR2_MODE4_MASK                   0xF00000u
#define SAF_EQADC_CFCR2_MODE4_SHIFT                  20u
#define SAF_EQADC_CFCR2_MODE4_WIDTH                  4u
#define SAF_EQADC_CFCR2_MODE4(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR2_MODE4_SHIFT))&SAF_EQADC_CFCR2_MODE4_MASK)
#define SAF_EQADC_CFCR2_CFINV4_MASK                  0x2000000u
#define SAF_EQADC_CFCR2_CFINV4_SHIFT                 25u
#define SAF_EQADC_CFCR2_CFINV4_WIDTH                 1u
#define SAF_EQADC_CFCR2_CFINV4(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR2_CFINV4_SHIFT))&SAF_EQADC_CFCR2_CFINV4_MASK)
#define SAF_EQADC_CFCR2_SSE4_MASK                    0x4000000u
#define SAF_EQADC_CFCR2_SSE4_SHIFT                   26u
#define SAF_EQADC_CFCR2_SSE4_WIDTH                   1u
#define SAF_EQADC_CFCR2_SSE4(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFCR2_SSE4_SHIFT))&SAF_EQADC_CFCR2_SSE4_MASK)
/* IDCR0 Bit Fields */
#define SAF_EQADC_IDCR0_RFDS1_MASK                   0x1u
#define SAF_EQADC_IDCR0_RFDS1_SHIFT                  0u
#define SAF_EQADC_IDCR0_RFDS1_WIDTH                  1u
#define SAF_EQADC_IDCR0_RFDS1(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_RFDS1_SHIFT))&SAF_EQADC_IDCR0_RFDS1_MASK)
#define SAF_EQADC_IDCR0_RFDE1_MASK                   0x2u
#define SAF_EQADC_IDCR0_RFDE1_SHIFT                  1u
#define SAF_EQADC_IDCR0_RFDE1_WIDTH                  1u
#define SAF_EQADC_IDCR0_RFDE1(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_RFDE1_SHIFT))&SAF_EQADC_IDCR0_RFDE1_MASK)
#define SAF_EQADC_IDCR0_RFOIE1_MASK                  0x8u
#define SAF_EQADC_IDCR0_RFOIE1_SHIFT                 3u
#define SAF_EQADC_IDCR0_RFOIE1_WIDTH                 1u
#define SAF_EQADC_IDCR0_RFOIE1(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_RFOIE1_SHIFT))&SAF_EQADC_IDCR0_RFOIE1_MASK)
#define SAF_EQADC_IDCR0_CFFS1_MASK                   0x100u
#define SAF_EQADC_IDCR0_CFFS1_SHIFT                  8u
#define SAF_EQADC_IDCR0_CFFS1_WIDTH                  1u
#define SAF_EQADC_IDCR0_CFFS1(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_CFFS1_SHIFT))&SAF_EQADC_IDCR0_CFFS1_MASK)
#define SAF_EQADC_IDCR0_CFFE1_MASK                   0x200u
#define SAF_EQADC_IDCR0_CFFE1_SHIFT                  9u
#define SAF_EQADC_IDCR0_CFFE1_WIDTH                  1u
#define SAF_EQADC_IDCR0_CFFE1(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_CFFE1_SHIFT))&SAF_EQADC_IDCR0_CFFE1_MASK)
#define SAF_EQADC_IDCR0_CFUIE1_MASK                  0x800u
#define SAF_EQADC_IDCR0_CFUIE1_SHIFT                 11u
#define SAF_EQADC_IDCR0_CFUIE1_WIDTH                 1u
#define SAF_EQADC_IDCR0_CFUIE1(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_CFUIE1_SHIFT))&SAF_EQADC_IDCR0_CFUIE1_MASK)
#define SAF_EQADC_IDCR0_EOQIE1_MASK                  0x1000u
#define SAF_EQADC_IDCR0_EOQIE1_SHIFT                 12u
#define SAF_EQADC_IDCR0_EOQIE1_WIDTH                 1u
#define SAF_EQADC_IDCR0_EOQIE1(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_EOQIE1_SHIFT))&SAF_EQADC_IDCR0_EOQIE1_MASK)
#define SAF_EQADC_IDCR0_PIE1_MASK                    0x2000u
#define SAF_EQADC_IDCR0_PIE1_SHIFT                   13u
#define SAF_EQADC_IDCR0_PIE1_WIDTH                   1u
#define SAF_EQADC_IDCR0_PIE1(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_PIE1_SHIFT))&SAF_EQADC_IDCR0_PIE1_MASK)
#define SAF_EQADC_IDCR0_TORIE1_MASK                  0x4000u
#define SAF_EQADC_IDCR0_TORIE1_SHIFT                 14u
#define SAF_EQADC_IDCR0_TORIE1_WIDTH                 1u
#define SAF_EQADC_IDCR0_TORIE1(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_TORIE1_SHIFT))&SAF_EQADC_IDCR0_TORIE1_MASK)
#define SAF_EQADC_IDCR0_NCIE1_MASK                   0x8000u
#define SAF_EQADC_IDCR0_NCIE1_SHIFT                  15u
#define SAF_EQADC_IDCR0_NCIE1_WIDTH                  1u
#define SAF_EQADC_IDCR0_NCIE1(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_NCIE1_SHIFT))&SAF_EQADC_IDCR0_NCIE1_MASK)
#define SAF_EQADC_IDCR0_RFDS0_MASK                   0x10000u
#define SAF_EQADC_IDCR0_RFDS0_SHIFT                  16u
#define SAF_EQADC_IDCR0_RFDS0_WIDTH                  1u
#define SAF_EQADC_IDCR0_RFDS0(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_RFDS0_SHIFT))&SAF_EQADC_IDCR0_RFDS0_MASK)
#define SAF_EQADC_IDCR0_RFDE0_MASK                   0x20000u
#define SAF_EQADC_IDCR0_RFDE0_SHIFT                  17u
#define SAF_EQADC_IDCR0_RFDE0_WIDTH                  1u
#define SAF_EQADC_IDCR0_RFDE0(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_RFDE0_SHIFT))&SAF_EQADC_IDCR0_RFDE0_MASK)
#define SAF_EQADC_IDCR0_RFOIE0_MASK                  0x80000u
#define SAF_EQADC_IDCR0_RFOIE0_SHIFT                 19u
#define SAF_EQADC_IDCR0_RFOIE0_WIDTH                 1u
#define SAF_EQADC_IDCR0_RFOIE0(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_RFOIE0_SHIFT))&SAF_EQADC_IDCR0_RFOIE0_MASK)
#define SAF_EQADC_IDCR0_CFFS0_MASK                   0x1000000u
#define SAF_EQADC_IDCR0_CFFS0_SHIFT                  24u
#define SAF_EQADC_IDCR0_CFFS0_WIDTH                  1u
#define SAF_EQADC_IDCR0_CFFS0(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_CFFS0_SHIFT))&SAF_EQADC_IDCR0_CFFS0_MASK)
#define SAF_EQADC_IDCR0_CFFE0_MASK                   0x2000000u
#define SAF_EQADC_IDCR0_CFFE0_SHIFT                  25u
#define SAF_EQADC_IDCR0_CFFE0_WIDTH                  1u
#define SAF_EQADC_IDCR0_CFFE0(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_CFFE0_SHIFT))&SAF_EQADC_IDCR0_CFFE0_MASK)
#define SAF_EQADC_IDCR0_CFUIE0_MASK                  0x8000000u
#define SAF_EQADC_IDCR0_CFUIE0_SHIFT                 27u
#define SAF_EQADC_IDCR0_CFUIE0_WIDTH                 1u
#define SAF_EQADC_IDCR0_CFUIE0(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_CFUIE0_SHIFT))&SAF_EQADC_IDCR0_CFUIE0_MASK)
#define SAF_EQADC_IDCR0_EOQIE0_MASK                  0x10000000u
#define SAF_EQADC_IDCR0_EOQIE0_SHIFT                 28u
#define SAF_EQADC_IDCR0_EOQIE0_WIDTH                 1u
#define SAF_EQADC_IDCR0_EOQIE0(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_EOQIE0_SHIFT))&SAF_EQADC_IDCR0_EOQIE0_MASK)
#define SAF_EQADC_IDCR0_PIE0_MASK                    0x20000000u
#define SAF_EQADC_IDCR0_PIE0_SHIFT                   29u
#define SAF_EQADC_IDCR0_PIE0_WIDTH                   1u
#define SAF_EQADC_IDCR0_PIE0(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_PIE0_SHIFT))&SAF_EQADC_IDCR0_PIE0_MASK)
#define SAF_EQADC_IDCR0_TORIE0_MASK                  0x40000000u
#define SAF_EQADC_IDCR0_TORIE0_SHIFT                 30u
#define SAF_EQADC_IDCR0_TORIE0_WIDTH                 1u
#define SAF_EQADC_IDCR0_TORIE0(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_TORIE0_SHIFT))&SAF_EQADC_IDCR0_TORIE0_MASK)
#define SAF_EQADC_IDCR0_NCIE0_MASK                   0x80000000u
#define SAF_EQADC_IDCR0_NCIE0_SHIFT                  31u
#define SAF_EQADC_IDCR0_NCIE0_WIDTH                  1u
#define SAF_EQADC_IDCR0_NCIE0(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR0_NCIE0_SHIFT))&SAF_EQADC_IDCR0_NCIE0_MASK)
/* IDCR1 Bit Fields */
#define SAF_EQADC_IDCR1_RFDS3_MASK                   0x1u
#define SAF_EQADC_IDCR1_RFDS3_SHIFT                  0u
#define SAF_EQADC_IDCR1_RFDS3_WIDTH                  1u
#define SAF_EQADC_IDCR1_RFDS3(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_RFDS3_SHIFT))&SAF_EQADC_IDCR1_RFDS3_MASK)
#define SAF_EQADC_IDCR1_RFDE3_MASK                   0x2u
#define SAF_EQADC_IDCR1_RFDE3_SHIFT                  1u
#define SAF_EQADC_IDCR1_RFDE3_WIDTH                  1u
#define SAF_EQADC_IDCR1_RFDE3(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_RFDE3_SHIFT))&SAF_EQADC_IDCR1_RFDE3_MASK)
#define SAF_EQADC_IDCR1_RFOIE3_MASK                  0x8u
#define SAF_EQADC_IDCR1_RFOIE3_SHIFT                 3u
#define SAF_EQADC_IDCR1_RFOIE3_WIDTH                 1u
#define SAF_EQADC_IDCR1_RFOIE3(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_RFOIE3_SHIFT))&SAF_EQADC_IDCR1_RFOIE3_MASK)
#define SAF_EQADC_IDCR1_CFFS3_MASK                   0x100u
#define SAF_EQADC_IDCR1_CFFS3_SHIFT                  8u
#define SAF_EQADC_IDCR1_CFFS3_WIDTH                  1u
#define SAF_EQADC_IDCR1_CFFS3(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_CFFS3_SHIFT))&SAF_EQADC_IDCR1_CFFS3_MASK)
#define SAF_EQADC_IDCR1_CFFE3_MASK                   0x200u
#define SAF_EQADC_IDCR1_CFFE3_SHIFT                  9u
#define SAF_EQADC_IDCR1_CFFE3_WIDTH                  1u
#define SAF_EQADC_IDCR1_CFFE3(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_CFFE3_SHIFT))&SAF_EQADC_IDCR1_CFFE3_MASK)
#define SAF_EQADC_IDCR1_CFUIE3_MASK                  0x800u
#define SAF_EQADC_IDCR1_CFUIE3_SHIFT                 11u
#define SAF_EQADC_IDCR1_CFUIE3_WIDTH                 1u
#define SAF_EQADC_IDCR1_CFUIE3(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_CFUIE3_SHIFT))&SAF_EQADC_IDCR1_CFUIE3_MASK)
#define SAF_EQADC_IDCR1_EOQIE3_MASK                  0x1000u
#define SAF_EQADC_IDCR1_EOQIE3_SHIFT                 12u
#define SAF_EQADC_IDCR1_EOQIE3_WIDTH                 1u
#define SAF_EQADC_IDCR1_EOQIE3(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_EOQIE3_SHIFT))&SAF_EQADC_IDCR1_EOQIE3_MASK)
#define SAF_EQADC_IDCR1_PIE3_MASK                    0x2000u
#define SAF_EQADC_IDCR1_PIE3_SHIFT                   13u
#define SAF_EQADC_IDCR1_PIE3_WIDTH                   1u
#define SAF_EQADC_IDCR1_PIE3(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_PIE3_SHIFT))&SAF_EQADC_IDCR1_PIE3_MASK)
#define SAF_EQADC_IDCR1_TORIE3_MASK                  0x4000u
#define SAF_EQADC_IDCR1_TORIE3_SHIFT                 14u
#define SAF_EQADC_IDCR1_TORIE3_WIDTH                 1u
#define SAF_EQADC_IDCR1_TORIE3(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_TORIE3_SHIFT))&SAF_EQADC_IDCR1_TORIE3_MASK)
#define SAF_EQADC_IDCR1_NCIE3_MASK                   0x8000u
#define SAF_EQADC_IDCR1_NCIE3_SHIFT                  15u
#define SAF_EQADC_IDCR1_NCIE3_WIDTH                  1u
#define SAF_EQADC_IDCR1_NCIE3(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_NCIE3_SHIFT))&SAF_EQADC_IDCR1_NCIE3_MASK)
#define SAF_EQADC_IDCR1_RFDS2_MASK                   0x10000u
#define SAF_EQADC_IDCR1_RFDS2_SHIFT                  16u
#define SAF_EQADC_IDCR1_RFDS2_WIDTH                  1u
#define SAF_EQADC_IDCR1_RFDS2(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_RFDS2_SHIFT))&SAF_EQADC_IDCR1_RFDS2_MASK)
#define SAF_EQADC_IDCR1_RFDE2_MASK                   0x20000u
#define SAF_EQADC_IDCR1_RFDE2_SHIFT                  17u
#define SAF_EQADC_IDCR1_RFDE2_WIDTH                  1u
#define SAF_EQADC_IDCR1_RFDE2(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_RFDE2_SHIFT))&SAF_EQADC_IDCR1_RFDE2_MASK)
#define SAF_EQADC_IDCR1_RFOIE2_MASK                  0x80000u
#define SAF_EQADC_IDCR1_RFOIE2_SHIFT                 19u
#define SAF_EQADC_IDCR1_RFOIE2_WIDTH                 1u
#define SAF_EQADC_IDCR1_RFOIE2(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_RFOIE2_SHIFT))&SAF_EQADC_IDCR1_RFOIE2_MASK)
#define SAF_EQADC_IDCR1_CFFS2_MASK                   0x1000000u
#define SAF_EQADC_IDCR1_CFFS2_SHIFT                  24u
#define SAF_EQADC_IDCR1_CFFS2_WIDTH                  1u
#define SAF_EQADC_IDCR1_CFFS2(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_CFFS2_SHIFT))&SAF_EQADC_IDCR1_CFFS2_MASK)
#define SAF_EQADC_IDCR1_CFFE2_MASK                   0x2000000u
#define SAF_EQADC_IDCR1_CFFE2_SHIFT                  25u
#define SAF_EQADC_IDCR1_CFFE2_WIDTH                  1u
#define SAF_EQADC_IDCR1_CFFE2(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_CFFE2_SHIFT))&SAF_EQADC_IDCR1_CFFE2_MASK)
#define SAF_EQADC_IDCR1_CFUIE2_MASK                  0x8000000u
#define SAF_EQADC_IDCR1_CFUIE2_SHIFT                 27u
#define SAF_EQADC_IDCR1_CFUIE2_WIDTH                 1u
#define SAF_EQADC_IDCR1_CFUIE2(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_CFUIE2_SHIFT))&SAF_EQADC_IDCR1_CFUIE2_MASK)
#define SAF_EQADC_IDCR1_EOQIE2_MASK                  0x10000000u
#define SAF_EQADC_IDCR1_EOQIE2_SHIFT                 28u
#define SAF_EQADC_IDCR1_EOQIE2_WIDTH                 1u
#define SAF_EQADC_IDCR1_EOQIE2(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_EOQIE2_SHIFT))&SAF_EQADC_IDCR1_EOQIE2_MASK)
#define SAF_EQADC_IDCR1_PIE2_MASK                    0x20000000u
#define SAF_EQADC_IDCR1_PIE2_SHIFT                   29u
#define SAF_EQADC_IDCR1_PIE2_WIDTH                   1u
#define SAF_EQADC_IDCR1_PIE2(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_PIE2_SHIFT))&SAF_EQADC_IDCR1_PIE2_MASK)
#define SAF_EQADC_IDCR1_TORIE2_MASK                  0x40000000u
#define SAF_EQADC_IDCR1_TORIE2_SHIFT                 30u
#define SAF_EQADC_IDCR1_TORIE2_WIDTH                 1u
#define SAF_EQADC_IDCR1_TORIE2(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_TORIE2_SHIFT))&SAF_EQADC_IDCR1_TORIE2_MASK)
#define SAF_EQADC_IDCR1_NCIE2_MASK                   0x80000000u
#define SAF_EQADC_IDCR1_NCIE2_SHIFT                  31u
#define SAF_EQADC_IDCR1_NCIE2_WIDTH                  1u
#define SAF_EQADC_IDCR1_NCIE2(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR1_NCIE2_SHIFT))&SAF_EQADC_IDCR1_NCIE2_MASK)
/* IDCR2 Bit Fields */
#define SAF_EQADC_IDCR2_RFDS5_MASK                   0x1u
#define SAF_EQADC_IDCR2_RFDS5_SHIFT                  0u
#define SAF_EQADC_IDCR2_RFDS5_WIDTH                  1u
#define SAF_EQADC_IDCR2_RFDS5(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_RFDS5_SHIFT))&SAF_EQADC_IDCR2_RFDS5_MASK)
#define SAF_EQADC_IDCR2_RFDE5_MASK                   0x2u
#define SAF_EQADC_IDCR2_RFDE5_SHIFT                  1u
#define SAF_EQADC_IDCR2_RFDE5_WIDTH                  1u
#define SAF_EQADC_IDCR2_RFDE5(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_RFDE5_SHIFT))&SAF_EQADC_IDCR2_RFDE5_MASK)
#define SAF_EQADC_IDCR2_RFOIE5_MASK                  0x8u
#define SAF_EQADC_IDCR2_RFOIE5_SHIFT                 3u
#define SAF_EQADC_IDCR2_RFOIE5_WIDTH                 1u
#define SAF_EQADC_IDCR2_RFOIE5(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_RFOIE5_SHIFT))&SAF_EQADC_IDCR2_RFOIE5_MASK)
#define SAF_EQADC_IDCR2_CFFS5_MASK                   0x100u
#define SAF_EQADC_IDCR2_CFFS5_SHIFT                  8u
#define SAF_EQADC_IDCR2_CFFS5_WIDTH                  1u
#define SAF_EQADC_IDCR2_CFFS5(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_CFFS5_SHIFT))&SAF_EQADC_IDCR2_CFFS5_MASK)
#define SAF_EQADC_IDCR2_CFFE5_MASK                   0x200u
#define SAF_EQADC_IDCR2_CFFE5_SHIFT                  9u
#define SAF_EQADC_IDCR2_CFFE5_WIDTH                  1u
#define SAF_EQADC_IDCR2_CFFE5(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_CFFE5_SHIFT))&SAF_EQADC_IDCR2_CFFE5_MASK)
#define SAF_EQADC_IDCR2_CFUIE5_MASK                  0x800u
#define SAF_EQADC_IDCR2_CFUIE5_SHIFT                 11u
#define SAF_EQADC_IDCR2_CFUIE5_WIDTH                 1u
#define SAF_EQADC_IDCR2_CFUIE5(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_CFUIE5_SHIFT))&SAF_EQADC_IDCR2_CFUIE5_MASK)
#define SAF_EQADC_IDCR2_EOQIE5_MASK                  0x1000u
#define SAF_EQADC_IDCR2_EOQIE5_SHIFT                 12u
#define SAF_EQADC_IDCR2_EOQIE5_WIDTH                 1u
#define SAF_EQADC_IDCR2_EOQIE5(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_EOQIE5_SHIFT))&SAF_EQADC_IDCR2_EOQIE5_MASK)
#define SAF_EQADC_IDCR2_PIE5_MASK                    0x2000u
#define SAF_EQADC_IDCR2_PIE5_SHIFT                   13u
#define SAF_EQADC_IDCR2_PIE5_WIDTH                   1u
#define SAF_EQADC_IDCR2_PIE5(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_PIE5_SHIFT))&SAF_EQADC_IDCR2_PIE5_MASK)
#define SAF_EQADC_IDCR2_TORIE5_MASK                  0x4000u
#define SAF_EQADC_IDCR2_TORIE5_SHIFT                 14u
#define SAF_EQADC_IDCR2_TORIE5_WIDTH                 1u
#define SAF_EQADC_IDCR2_TORIE5(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_TORIE5_SHIFT))&SAF_EQADC_IDCR2_TORIE5_MASK)
#define SAF_EQADC_IDCR2_NCIE5_MASK                   0x8000u
#define SAF_EQADC_IDCR2_NCIE5_SHIFT                  15u
#define SAF_EQADC_IDCR2_NCIE5_WIDTH                  1u
#define SAF_EQADC_IDCR2_NCIE5(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_NCIE5_SHIFT))&SAF_EQADC_IDCR2_NCIE5_MASK)
#define SAF_EQADC_IDCR2_RFDS4_MASK                   0x10000u
#define SAF_EQADC_IDCR2_RFDS4_SHIFT                  16u
#define SAF_EQADC_IDCR2_RFDS4_WIDTH                  1u
#define SAF_EQADC_IDCR2_RFDS4(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_RFDS4_SHIFT))&SAF_EQADC_IDCR2_RFDS4_MASK)
#define SAF_EQADC_IDCR2_RFDE4_MASK                   0x20000u
#define SAF_EQADC_IDCR2_RFDE4_SHIFT                  17u
#define SAF_EQADC_IDCR2_RFDE4_WIDTH                  1u
#define SAF_EQADC_IDCR2_RFDE4(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_RFDE4_SHIFT))&SAF_EQADC_IDCR2_RFDE4_MASK)
#define SAF_EQADC_IDCR2_RFOIE4_MASK                  0x80000u
#define SAF_EQADC_IDCR2_RFOIE4_SHIFT                 19u
#define SAF_EQADC_IDCR2_RFOIE4_WIDTH                 1u
#define SAF_EQADC_IDCR2_RFOIE4(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_RFOIE4_SHIFT))&SAF_EQADC_IDCR2_RFOIE4_MASK)
#define SAF_EQADC_IDCR2_CFFS4_MASK                   0x1000000u
#define SAF_EQADC_IDCR2_CFFS4_SHIFT                  24u
#define SAF_EQADC_IDCR2_CFFS4_WIDTH                  1u
#define SAF_EQADC_IDCR2_CFFS4(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_CFFS4_SHIFT))&SAF_EQADC_IDCR2_CFFS4_MASK)
#define SAF_EQADC_IDCR2_CFFE4_MASK                   0x2000000u
#define SAF_EQADC_IDCR2_CFFE4_SHIFT                  25u
#define SAF_EQADC_IDCR2_CFFE4_WIDTH                  1u
#define SAF_EQADC_IDCR2_CFFE4(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_CFFE4_SHIFT))&SAF_EQADC_IDCR2_CFFE4_MASK)
#define SAF_EQADC_IDCR2_CFUIE4_MASK                  0x8000000u
#define SAF_EQADC_IDCR2_CFUIE4_SHIFT                 27u
#define SAF_EQADC_IDCR2_CFUIE4_WIDTH                 1u
#define SAF_EQADC_IDCR2_CFUIE4(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_CFUIE4_SHIFT))&SAF_EQADC_IDCR2_CFUIE4_MASK)
#define SAF_EQADC_IDCR2_EOQIE4_MASK                  0x10000000u
#define SAF_EQADC_IDCR2_EOQIE4_SHIFT                 28u
#define SAF_EQADC_IDCR2_EOQIE4_WIDTH                 1u
#define SAF_EQADC_IDCR2_EOQIE4(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_EOQIE4_SHIFT))&SAF_EQADC_IDCR2_EOQIE4_MASK)
#define SAF_EQADC_IDCR2_PIE4_MASK                    0x20000000u
#define SAF_EQADC_IDCR2_PIE4_SHIFT                   29u
#define SAF_EQADC_IDCR2_PIE4_WIDTH                   1u
#define SAF_EQADC_IDCR2_PIE4(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_PIE4_SHIFT))&SAF_EQADC_IDCR2_PIE4_MASK)
#define SAF_EQADC_IDCR2_TORIE4_MASK                  0x40000000u
#define SAF_EQADC_IDCR2_TORIE4_SHIFT                 30u
#define SAF_EQADC_IDCR2_TORIE4_WIDTH                 1u
#define SAF_EQADC_IDCR2_TORIE4(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_TORIE4_SHIFT))&SAF_EQADC_IDCR2_TORIE4_MASK)
#define SAF_EQADC_IDCR2_NCIE4_MASK                   0x80000000u
#define SAF_EQADC_IDCR2_NCIE4_SHIFT                  31u
#define SAF_EQADC_IDCR2_NCIE4_WIDTH                  1u
#define SAF_EQADC_IDCR2_NCIE4(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_IDCR2_NCIE4_SHIFT))&SAF_EQADC_IDCR2_NCIE4_MASK)
/* FISR Bit Fields */
#define SAF_EQADC_FISR_POPNXTPTRX_MASK               0xFu
#define SAF_EQADC_FISR_POPNXTPTRX_SHIFT              0u
#define SAF_EQADC_FISR_POPNXTPTRX_WIDTH              4u
#define SAF_EQADC_FISR_POPNXTPTRX(x)                 (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_FISR_POPNXTPTRX_SHIFT))&SAF_EQADC_FISR_POPNXTPTRX_MASK)
#define SAF_EQADC_FISR_RFCTRX_MASK                   0xF0u
#define SAF_EQADC_FISR_RFCTRX_SHIFT                  4u
#define SAF_EQADC_FISR_RFCTRX_WIDTH                  4u
#define SAF_EQADC_FISR_RFCTRX(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_FISR_RFCTRX_SHIFT))&SAF_EQADC_FISR_RFCTRX_MASK)
#define SAF_EQADC_FISR_TNXTPTRX_MASK                 0xF00u
#define SAF_EQADC_FISR_TNXTPTRX_SHIFT                8u
#define SAF_EQADC_FISR_TNXTPTRX_WIDTH                4u
#define SAF_EQADC_FISR_TNXTPTRX(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_FISR_TNXTPTRX_SHIFT))&SAF_EQADC_FISR_TNXTPTRX_MASK)
#define SAF_EQADC_FISR_CFCTRX_MASK                   0xF000u
#define SAF_EQADC_FISR_CFCTRX_SHIFT                  12u
#define SAF_EQADC_FISR_CFCTRX_WIDTH                  4u
#define SAF_EQADC_FISR_CFCTRX(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_FISR_CFCTRX_SHIFT))&SAF_EQADC_FISR_CFCTRX_MASK)
#define SAF_EQADC_FISR_RFDFX_MASK                    0x20000u
#define SAF_EQADC_FISR_RFDFX_SHIFT                   17u
#define SAF_EQADC_FISR_RFDFX_WIDTH                   1u
#define SAF_EQADC_FISR_RFDFX(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_FISR_RFDFX_SHIFT))&SAF_EQADC_FISR_RFDFX_MASK)
#define SAF_EQADC_FISR_RFOFX_MASK                    0x80000u
#define SAF_EQADC_FISR_RFOFX_SHIFT                   19u
#define SAF_EQADC_FISR_RFOFX_WIDTH                   1u
#define SAF_EQADC_FISR_RFOFX(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_FISR_RFOFX_SHIFT))&SAF_EQADC_FISR_RFOFX_MASK)
#define SAF_EQADC_FISR_CFFFX_MASK                    0x2000000u
#define SAF_EQADC_FISR_CFFFX_SHIFT                   25u
#define SAF_EQADC_FISR_CFFFX_WIDTH                   1u
#define SAF_EQADC_FISR_CFFFX(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_FISR_CFFFX_SHIFT))&SAF_EQADC_FISR_CFFFX_MASK)
#define SAF_EQADC_FISR_SSSX_MASK                     0x4000000u
#define SAF_EQADC_FISR_SSSX_SHIFT                    26u
#define SAF_EQADC_FISR_SSSX_WIDTH                    1u
#define SAF_EQADC_FISR_SSSX(x)                       (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_FISR_SSSX_SHIFT))&SAF_EQADC_FISR_SSSX_MASK)
#define SAF_EQADC_FISR_CFUFX_MASK                    0x8000000u
#define SAF_EQADC_FISR_CFUFX_SHIFT                   27u
#define SAF_EQADC_FISR_CFUFX_WIDTH                   1u
#define SAF_EQADC_FISR_CFUFX(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_FISR_CFUFX_SHIFT))&SAF_EQADC_FISR_CFUFX_MASK)
#define SAF_EQADC_FISR_EOQFX_MASK                    0x10000000u
#define SAF_EQADC_FISR_EOQFX_SHIFT                   28u
#define SAF_EQADC_FISR_EOQFX_WIDTH                   1u
#define SAF_EQADC_FISR_EOQFX(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_FISR_EOQFX_SHIFT))&SAF_EQADC_FISR_EOQFX_MASK)
#define SAF_EQADC_FISR_PFX_MASK                      0x20000000u
#define SAF_EQADC_FISR_PFX_SHIFT                     29u
#define SAF_EQADC_FISR_PFX_WIDTH                     1u
#define SAF_EQADC_FISR_PFX(x)                        (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_FISR_PFX_SHIFT))&SAF_EQADC_FISR_PFX_MASK)
#define SAF_EQADC_FISR_TORFX_MASK                    0x40000000u
#define SAF_EQADC_FISR_TORFX_SHIFT                   30u
#define SAF_EQADC_FISR_TORFX_WIDTH                   1u
#define SAF_EQADC_FISR_TORFX(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_FISR_TORFX_SHIFT))&SAF_EQADC_FISR_TORFX_MASK)
#define SAF_EQADC_FISR_NCFX_MASK                     0x80000000u
#define SAF_EQADC_FISR_NCFX_SHIFT                    31u
#define SAF_EQADC_FISR_NCFX_WIDTH                    1u
#define SAF_EQADC_FISR_NCFX(x)                       (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_FISR_NCFX_SHIFT))&SAF_EQADC_FISR_NCFX_MASK)
/* CFTCR0 Bit Fields */
#define SAF_EQADC_CFTCR0_TC_CF1_MASK                 0x7FFu
#define SAF_EQADC_CFTCR0_TC_CF1_SHIFT                0u
#define SAF_EQADC_CFTCR0_TC_CF1_WIDTH                11u
#define SAF_EQADC_CFTCR0_TC_CF1(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFTCR0_TC_CF1_SHIFT))&SAF_EQADC_CFTCR0_TC_CF1_MASK)
#define SAF_EQADC_CFTCR0_TC_CF0_MASK                 0x7FF0000u
#define SAF_EQADC_CFTCR0_TC_CF0_SHIFT                16u
#define SAF_EQADC_CFTCR0_TC_CF0_WIDTH                11u
#define SAF_EQADC_CFTCR0_TC_CF0(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFTCR0_TC_CF0_SHIFT))&SAF_EQADC_CFTCR0_TC_CF0_MASK)
/* CFTCR1 Bit Fields */
#define SAF_EQADC_CFTCR1_TC_CF3_MASK                 0x7FFu
#define SAF_EQADC_CFTCR1_TC_CF3_SHIFT                0u
#define SAF_EQADC_CFTCR1_TC_CF3_WIDTH                11u
#define SAF_EQADC_CFTCR1_TC_CF3(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFTCR1_TC_CF3_SHIFT))&SAF_EQADC_CFTCR1_TC_CF3_MASK)
#define SAF_EQADC_CFTCR1_TC_CF2_MASK                 0x7FF0000u
#define SAF_EQADC_CFTCR1_TC_CF2_SHIFT                16u
#define SAF_EQADC_CFTCR1_TC_CF2_WIDTH                11u
#define SAF_EQADC_CFTCR1_TC_CF2(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFTCR1_TC_CF2_SHIFT))&SAF_EQADC_CFTCR1_TC_CF2_MASK)
/* CFTCR2 Bit Fields */
#define SAF_EQADC_CFTCR2_TC_CF5_MASK                 0x7FFu
#define SAF_EQADC_CFTCR2_TC_CF5_SHIFT                0u
#define SAF_EQADC_CFTCR2_TC_CF5_WIDTH                11u
#define SAF_EQADC_CFTCR2_TC_CF5(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFTCR2_TC_CF5_SHIFT))&SAF_EQADC_CFTCR2_TC_CF5_MASK)
#define SAF_EQADC_CFTCR2_TC_CF4_MASK                 0x7FF0000u
#define SAF_EQADC_CFTCR2_TC_CF4_SHIFT                16u
#define SAF_EQADC_CFTCR2_TC_CF4_WIDTH                11u
#define SAF_EQADC_CFTCR2_TC_CF4(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFTCR2_TC_CF4_SHIFT))&SAF_EQADC_CFTCR2_TC_CF4_MASK)
/* CFSSR0 Bit Fields */
#define SAF_EQADC_CFSSR0_TC_LCFTCB0_MASK             0x7FFu
#define SAF_EQADC_CFSSR0_TC_LCFTCB0_SHIFT            0u
#define SAF_EQADC_CFSSR0_TC_LCFTCB0_WIDTH            11u
#define SAF_EQADC_CFSSR0_TC_LCFTCB0(x)               (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSSR0_TC_LCFTCB0_SHIFT))&SAF_EQADC_CFSSR0_TC_LCFTCB0_MASK)
#define SAF_EQADC_CFSSR0_LCFTCB0_MASK                0x7800u
#define SAF_EQADC_CFSSR0_LCFTCB0_SHIFT               11u
#define SAF_EQADC_CFSSR0_LCFTCB0_WIDTH               4u
#define SAF_EQADC_CFSSR0_LCFTCB0(x)                  (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSSR0_LCFTCB0_SHIFT))&SAF_EQADC_CFSSR0_LCFTCB0_MASK)
#define SAF_EQADC_CFSSR0_CFS5_TCB0_MASK              0x300000u
#define SAF_EQADC_CFSSR0_CFS5_TCB0_SHIFT             20u
#define SAF_EQADC_CFSSR0_CFS5_TCB0_WIDTH             2u
#define SAF_EQADC_CFSSR0_CFS5_TCB0(x)                (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSSR0_CFS5_TCB0_SHIFT))&SAF_EQADC_CFSSR0_CFS5_TCB0_MASK)
#define SAF_EQADC_CFSSR0_CFS4_TCB0_MASK              0xC00000u
#define SAF_EQADC_CFSSR0_CFS4_TCB0_SHIFT             22u
#define SAF_EQADC_CFSSR0_CFS4_TCB0_WIDTH             2u
#define SAF_EQADC_CFSSR0_CFS4_TCB0(x)                (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSSR0_CFS4_TCB0_SHIFT))&SAF_EQADC_CFSSR0_CFS4_TCB0_MASK)
#define SAF_EQADC_CFSSR0_CFS3_TCB0_MASK              0x3000000u
#define SAF_EQADC_CFSSR0_CFS3_TCB0_SHIFT             24u
#define SAF_EQADC_CFSSR0_CFS3_TCB0_WIDTH             2u
#define SAF_EQADC_CFSSR0_CFS3_TCB0(x)                (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSSR0_CFS3_TCB0_SHIFT))&SAF_EQADC_CFSSR0_CFS3_TCB0_MASK)
#define SAF_EQADC_CFSSR0_CFS2_TCB0_MASK              0xC000000u
#define SAF_EQADC_CFSSR0_CFS2_TCB0_SHIFT             26u
#define SAF_EQADC_CFSSR0_CFS2_TCB0_WIDTH             2u
#define SAF_EQADC_CFSSR0_CFS2_TCB0(x)                (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSSR0_CFS2_TCB0_SHIFT))&SAF_EQADC_CFSSR0_CFS2_TCB0_MASK)
#define SAF_EQADC_CFSSR0_CFS1_TCB0_MASK              0x30000000u
#define SAF_EQADC_CFSSR0_CFS1_TCB0_SHIFT             28u
#define SAF_EQADC_CFSSR0_CFS1_TCB0_WIDTH             2u
#define SAF_EQADC_CFSSR0_CFS1_TCB0(x)                (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSSR0_CFS1_TCB0_SHIFT))&SAF_EQADC_CFSSR0_CFS1_TCB0_MASK)
#define SAF_EQADC_CFSSR0_CFS0_TCB0_MASK              0xC0000000u
#define SAF_EQADC_CFSSR0_CFS0_TCB0_SHIFT             30u
#define SAF_EQADC_CFSSR0_CFS0_TCB0_WIDTH             2u
#define SAF_EQADC_CFSSR0_CFS0_TCB0(x)                (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSSR0_CFS0_TCB0_SHIFT))&SAF_EQADC_CFSSR0_CFS0_TCB0_MASK)
/* CFSSR1 Bit Fields */
#define SAF_EQADC_CFSSR1_TC_LCFTCB1_MASK             0x7FFu
#define SAF_EQADC_CFSSR1_TC_LCFTCB1_SHIFT            0u
#define SAF_EQADC_CFSSR1_TC_LCFTCB1_WIDTH            11u
#define SAF_EQADC_CFSSR1_TC_LCFTCB1(x)               (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSSR1_TC_LCFTCB1_SHIFT))&SAF_EQADC_CFSSR1_TC_LCFTCB1_MASK)
#define SAF_EQADC_CFSSR1_LCFTCB1_MASK                0x7800u
#define SAF_EQADC_CFSSR1_LCFTCB1_SHIFT               11u
#define SAF_EQADC_CFSSR1_LCFTCB1_WIDTH               4u
#define SAF_EQADC_CFSSR1_LCFTCB1(x)                  (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSSR1_LCFTCB1_SHIFT))&SAF_EQADC_CFSSR1_LCFTCB1_MASK)
#define SAF_EQADC_CFSSR1_CFS5_TCB1_MASK              0x300000u
#define SAF_EQADC_CFSSR1_CFS5_TCB1_SHIFT             20u
#define SAF_EQADC_CFSSR1_CFS5_TCB1_WIDTH             2u
#define SAF_EQADC_CFSSR1_CFS5_TCB1(x)                (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSSR1_CFS5_TCB1_SHIFT))&SAF_EQADC_CFSSR1_CFS5_TCB1_MASK)
#define SAF_EQADC_CFSSR1_CFS4_TCB1_MASK              0xC00000u
#define SAF_EQADC_CFSSR1_CFS4_TCB1_SHIFT             22u
#define SAF_EQADC_CFSSR1_CFS4_TCB1_WIDTH             2u
#define SAF_EQADC_CFSSR1_CFS4_TCB1(x)                (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSSR1_CFS4_TCB1_SHIFT))&SAF_EQADC_CFSSR1_CFS4_TCB1_MASK)
#define SAF_EQADC_CFSSR1_CFS3_TCB1_MASK              0x3000000u
#define SAF_EQADC_CFSSR1_CFS3_TCB1_SHIFT             24u
#define SAF_EQADC_CFSSR1_CFS3_TCB1_WIDTH             2u
#define SAF_EQADC_CFSSR1_CFS3_TCB1(x)                (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSSR1_CFS3_TCB1_SHIFT))&SAF_EQADC_CFSSR1_CFS3_TCB1_MASK)
#define SAF_EQADC_CFSSR1_CFS2_TCB1_MASK              0xC000000u
#define SAF_EQADC_CFSSR1_CFS2_TCB1_SHIFT             26u
#define SAF_EQADC_CFSSR1_CFS2_TCB1_WIDTH             2u
#define SAF_EQADC_CFSSR1_CFS2_TCB1(x)                (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSSR1_CFS2_TCB1_SHIFT))&SAF_EQADC_CFSSR1_CFS2_TCB1_MASK)
#define SAF_EQADC_CFSSR1_CFS1_TCB1_MASK              0x30000000u
#define SAF_EQADC_CFSSR1_CFS1_TCB1_SHIFT             28u
#define SAF_EQADC_CFSSR1_CFS1_TCB1_WIDTH             2u
#define SAF_EQADC_CFSSR1_CFS1_TCB1(x)                (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSSR1_CFS1_TCB1_SHIFT))&SAF_EQADC_CFSSR1_CFS1_TCB1_MASK)
#define SAF_EQADC_CFSSR1_CFS0_TCB1_MASK              0xC0000000u
#define SAF_EQADC_CFSSR1_CFS0_TCB1_SHIFT             30u
#define SAF_EQADC_CFSSR1_CFS0_TCB1_WIDTH             2u
#define SAF_EQADC_CFSSR1_CFS0_TCB1(x)                (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSSR1_CFS0_TCB1_SHIFT))&SAF_EQADC_CFSSR1_CFS0_TCB1_MASK)
/* CFSR Bit Fields */
#define SAF_EQADC_CFSR_CFS5_MASK                     0x300000u
#define SAF_EQADC_CFSR_CFS5_SHIFT                    20u
#define SAF_EQADC_CFSR_CFS5_WIDTH                    2u
#define SAF_EQADC_CFSR_CFS5(x)                       (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSR_CFS5_SHIFT))&SAF_EQADC_CFSR_CFS5_MASK)
#define SAF_EQADC_CFSR_CFS4_MASK                     0xC00000u
#define SAF_EQADC_CFSR_CFS4_SHIFT                    22u
#define SAF_EQADC_CFSR_CFS4_WIDTH                    2u
#define SAF_EQADC_CFSR_CFS4(x)                       (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSR_CFS4_SHIFT))&SAF_EQADC_CFSR_CFS4_MASK)
#define SAF_EQADC_CFSR_CFS3_MASK                     0x3000000u
#define SAF_EQADC_CFSR_CFS3_SHIFT                    24u
#define SAF_EQADC_CFSR_CFS3_WIDTH                    2u
#define SAF_EQADC_CFSR_CFS3(x)                       (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSR_CFS3_SHIFT))&SAF_EQADC_CFSR_CFS3_MASK)
#define SAF_EQADC_CFSR_CFS2_MASK                     0xC000000u
#define SAF_EQADC_CFSR_CFS2_SHIFT                    26u
#define SAF_EQADC_CFSR_CFS2_WIDTH                    2u
#define SAF_EQADC_CFSR_CFS2(x)                       (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSR_CFS2_SHIFT))&SAF_EQADC_CFSR_CFS2_MASK)
#define SAF_EQADC_CFSR_CFS1_MASK                     0x30000000u
#define SAF_EQADC_CFSR_CFS1_SHIFT                    28u
#define SAF_EQADC_CFSR_CFS1_WIDTH                    2u
#define SAF_EQADC_CFSR_CFS1(x)                       (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSR_CFS1_SHIFT))&SAF_EQADC_CFSR_CFS1_MASK)
#define SAF_EQADC_CFSR_CFS0_MASK                     0xC0000000u
#define SAF_EQADC_CFSR_CFS0_SHIFT                    30u
#define SAF_EQADC_CFSR_CFS0_WIDTH                    2u
#define SAF_EQADC_CFSR_CFS0(x)                       (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CFSR_CFS0_SHIFT))&SAF_EQADC_CFSR_CFS0_MASK)
/* STACCCR Bit Fields */
#define SAF_EQADC_STACCCR_SRV1_MASK                  0xFu
#define SAF_EQADC_STACCCR_SRV1_SHIFT                 0u
#define SAF_EQADC_STACCCR_SRV1_WIDTH                 4u
#define SAF_EQADC_STACCCR_SRV1(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_STACCCR_SRV1_SHIFT))&SAF_EQADC_STACCCR_SRV1_MASK)
#define SAF_EQADC_STACCCR_STACBS1_MASK               0xF0u
#define SAF_EQADC_STACCCR_STACBS1_SHIFT              4u
#define SAF_EQADC_STACCCR_STACBS1_WIDTH              4u
#define SAF_EQADC_STACCCR_STACBS1(x)                 (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_STACCCR_STACBS1_SHIFT))&SAF_EQADC_STACCCR_STACBS1_MASK)
#define SAF_EQADC_STACCCR_SRV2_MASK                  0xF00u
#define SAF_EQADC_STACCCR_SRV2_SHIFT                 8u
#define SAF_EQADC_STACCCR_SRV2_WIDTH                 4u
#define SAF_EQADC_STACCCR_SRV2(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_STACCCR_SRV2_SHIFT))&SAF_EQADC_STACCCR_SRV2_MASK)
#define SAF_EQADC_STACCCR_STACBS2_MASK               0xF000u
#define SAF_EQADC_STACCCR_STACBS2_SHIFT              12u
#define SAF_EQADC_STACCCR_STACBS2_WIDTH              4u
#define SAF_EQADC_STACCCR_STACBS2(x)                 (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_STACCCR_STACBS2_SHIFT))&SAF_EQADC_STACCCR_STACBS2_MASK)
/* CF0R Bit Fields */
#define SAF_EQADC_CF0R_CFIFO0_DATAW_MASK             0xFFFFFFFFu
#define SAF_EQADC_CF0R_CFIFO0_DATAW_SHIFT            0u
#define SAF_EQADC_CF0R_CFIFO0_DATAW_WIDTH            32u
#define SAF_EQADC_CF0R_CFIFO0_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CF0R_CFIFO0_DATAW_SHIFT))&SAF_EQADC_CF0R_CFIFO0_DATAW_MASK)
/* CF0ER Bit Fields */
#define SAF_EQADC_CF0ER_CFIFO0_EDATAW_MASK           0xFFFFFFFFu
#define SAF_EQADC_CF0ER_CFIFO0_EDATAW_SHIFT          0u
#define SAF_EQADC_CF0ER_CFIFO0_EDATAW_WIDTH          32u
#define SAF_EQADC_CF0ER_CFIFO0_EDATAW(x)             (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CF0ER_CFIFO0_EDATAW_SHIFT))&SAF_EQADC_CF0ER_CFIFO0_EDATAW_MASK)
/* CF1R Bit Fields */
#define SAF_EQADC_CF1R_CFIFO1_DATAW_MASK             0xFFFFFFFFu
#define SAF_EQADC_CF1R_CFIFO1_DATAW_SHIFT            0u
#define SAF_EQADC_CF1R_CFIFO1_DATAW_WIDTH            32u
#define SAF_EQADC_CF1R_CFIFO1_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CF1R_CFIFO1_DATAW_SHIFT))&SAF_EQADC_CF1R_CFIFO1_DATAW_MASK)
/* CF2R Bit Fields */
#define SAF_EQADC_CF2R_CFIFO2_DATAW_MASK             0xFFFFFFFFu
#define SAF_EQADC_CF2R_CFIFO2_DATAW_SHIFT            0u
#define SAF_EQADC_CF2R_CFIFO2_DATAW_WIDTH            32u
#define SAF_EQADC_CF2R_CFIFO2_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CF2R_CFIFO2_DATAW_SHIFT))&SAF_EQADC_CF2R_CFIFO2_DATAW_MASK)
/* CF3R Bit Fields */
#define SAF_EQADC_CF3R_CFIFO3_DATAW_MASK             0xFFFFFFFFu
#define SAF_EQADC_CF3R_CFIFO3_DATAW_SHIFT            0u
#define SAF_EQADC_CF3R_CFIFO3_DATAW_WIDTH            32u
#define SAF_EQADC_CF3R_CFIFO3_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CF3R_CFIFO3_DATAW_SHIFT))&SAF_EQADC_CF3R_CFIFO3_DATAW_MASK)
/* CF4R Bit Fields */
#define SAF_EQADC_CF4R_CFIFO4_DATAW_MASK             0xFFFFFFFFu
#define SAF_EQADC_CF4R_CFIFO4_DATAW_SHIFT            0u
#define SAF_EQADC_CF4R_CFIFO4_DATAW_WIDTH            32u
#define SAF_EQADC_CF4R_CFIFO4_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CF4R_CFIFO4_DATAW_SHIFT))&SAF_EQADC_CF4R_CFIFO4_DATAW_MASK)
/* CF5R Bit Fields */
#define SAF_EQADC_CF5R_CFIFO5_DATAW_MASK             0xFFFFFFFFu
#define SAF_EQADC_CF5R_CFIFO5_DATAW_SHIFT            0u
#define SAF_EQADC_CF5R_CFIFO5_DATAW_WIDTH            32u
#define SAF_EQADC_CF5R_CFIFO5_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_CF5R_CFIFO5_DATAW_SHIFT))&SAF_EQADC_CF5R_CFIFO5_DATAW_MASK)
/* RF0R Bit Fields */
#define SAF_EQADC_RF0R_RFIFO0_DATAW_MASK             0xFFFFu
#define SAF_EQADC_RF0R_RFIFO0_DATAW_SHIFT            0u
#define SAF_EQADC_RF0R_RFIFO0_DATAW_WIDTH            16u
#define SAF_EQADC_RF0R_RFIFO0_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_RF0R_RFIFO0_DATAW_SHIFT))&SAF_EQADC_RF0R_RFIFO0_DATAW_MASK)
/* RF1R Bit Fields */
#define SAF_EQADC_RF1R_RFIFO1_DATAW_MASK             0xFFFFu
#define SAF_EQADC_RF1R_RFIFO1_DATAW_SHIFT            0u
#define SAF_EQADC_RF1R_RFIFO1_DATAW_WIDTH            16u
#define SAF_EQADC_RF1R_RFIFO1_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_RF1R_RFIFO1_DATAW_SHIFT))&SAF_EQADC_RF1R_RFIFO1_DATAW_MASK)
/* RF2R Bit Fields */
#define SAF_EQADC_RF2R_RFIFO2_DATAW_MASK             0xFFFFu
#define SAF_EQADC_RF2R_RFIFO2_DATAW_SHIFT            0u
#define SAF_EQADC_RF2R_RFIFO2_DATAW_WIDTH            16u
#define SAF_EQADC_RF2R_RFIFO2_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_RF2R_RFIFO2_DATAW_SHIFT))&SAF_EQADC_RF2R_RFIFO2_DATAW_MASK)
/* RF3R Bit Fields */
#define SAF_EQADC_RF3R_RFIFO3_DATAW_MASK             0xFFFFu
#define SAF_EQADC_RF3R_RFIFO3_DATAW_SHIFT            0u
#define SAF_EQADC_RF3R_RFIFO3_DATAW_WIDTH            16u
#define SAF_EQADC_RF3R_RFIFO3_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_RF3R_RFIFO3_DATAW_SHIFT))&SAF_EQADC_RF3R_RFIFO3_DATAW_MASK)
/* RF4R Bit Fields */
#define SAF_EQADC_RF4R_RFIFO4_DATAW_MASK             0xFFFFu
#define SAF_EQADC_RF4R_RFIFO4_DATAW_SHIFT            0u
#define SAF_EQADC_RF4R_RFIFO4_DATAW_WIDTH            16u
#define SAF_EQADC_RF4R_RFIFO4_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_RF4R_RFIFO4_DATAW_SHIFT))&SAF_EQADC_RF4R_RFIFO4_DATAW_MASK)
/* RF5R Bit Fields */
#define SAF_EQADC_RF5R_RFIFO5_DATAW_MASK             0xFFFFu
#define SAF_EQADC_RF5R_RFIFO5_DATAW_SHIFT            0u
#define SAF_EQADC_RF5R_RFIFO5_DATAW_WIDTH            16u
#define SAF_EQADC_RF5R_RFIFO5_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_RF5R_RFIFO5_DATAW_SHIFT))&SAF_EQADC_RF5R_RFIFO5_DATAW_MASK)
/* DLY Bit Fields CFTDR */
#define SAF_EQADC_DLY_CFIFO_TRIG_DELAY_EN_MASK       0x80000000u
#define SAF_EQADC_DLY_CFIFO_TRIG_DELAY_EN_SHIFT      31u
#define SAF_EQADC_DLY_CFIFO_TRIG_DELAY_EN_WIDTH      1u
#define SAF_EQADC_DLY_CFIFO_TRIG_DELAY_EN(x)         (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_DLY_CFIFO_TRIG_DELAY_EN_SHIFT))&SAF_EQADC_DLY_CFIFO_TRIG_DELAY_EN_MASK)
#define SAF_EQADC_DLY_CFIFO_TRIG_DELAY_VAL_MASK      0xFFFFFu
#define SAF_EQADC_DLY_CFIFO_TRIG_DELAY_VAL_SHIFT     0u
#define SAF_EQADC_DLY_CFIFO_TRIG_DELAY_VAL_WIDTH     20u
#define SAF_EQADC_DLY_CFIFO_TRIG_DELAY_VAL(x)        (((uint32_t)(((uint32_t)(x))<<SAF_EQADC_DLY_CFIFO_TRIG_DELAY_VAL_SHIFT))&SAF_EQADC_DLY_CFIFO_TRIG_DELAY_VAL_MASK)

/*******************************************************************************
 * EQADC On-Chip ADC Register Bit Fields
 *******************************************************************************/
/*! ADC CR Bit Fields */
#define SAF_EQADC_ADC_CR_CLK_PS_MASK                 0x1Fu
#define SAF_EQADC_ADC_CR_CLK_PS_SHIFT                0u
#define SAF_EQADC_ADC_CR_CLK_PS_WIDTH                5u
#define SAF_EQADC_ADC_CR_CLK_PS(x)                   ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_CR_CLK_PS_SHIFT))&SAF_EQADC_ADC_CR_CLK_PS_MASK))
#ifdef SAF_EQADC_ADC_CR_CLK_SEL_EN
#define SAF_EQADC_ADC_CR_CLK_SEL_MASK                0x20u
#define SAF_EQADC_ADC_CR_CLK_SEL_SHIFT               5u
#define SAF_EQADC_ADC_CR_CLK_SEL_WIDTH               1u
#define SAF_EQADC_ADC_CR_CLK_SEL(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_CR_CLK_SEL_SHIFT))&SAF_EQADC_ADC_CR_CLK_SEL_MASK))
#endif  /* SAF_EQADC_ADC_CR_CLK_SEL_EN */
#define SAF_EQADC_ADC_CR_CLK_DTY_MASK                0x40u
#define SAF_EQADC_ADC_CR_CLK_DTY_SHIFT               6u
#define SAF_EQADC_ADC_CR_CLK_DTY_WIDTH               1u
#define SAF_EQADC_ADC_CR_CLK_DTY(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_CR_CLK_DTY_SHIFT))&SAF_EQADC_ADC_CR_CLK_DTY_MASK))
#define SAF_EQADC_ADC_CR_ODD_PS_MASK                 0x80u
#define SAF_EQADC_ADC_CR_ODD_PS_SHIFT                7u
#define SAF_EQADC_ADC_CR_ODD_PS_WIDTH                1u
#define SAF_EQADC_ADC_CR_ODD_PS(x)                   ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_CR_ODD_PS_SHIFT))&SAF_EQADC_ADC_CR_ODD_PS_MASK))
#define SAF_EQADC_ADC_CR_TBSEL_MASK                  0x300u
#define SAF_EQADC_ADC_CR_TBSEL_SHIFT                 8u
#define SAF_EQADC_ADC_CR_TBSEL_WIDTH                 2u
#define SAF_EQADC_ADC_CR_TBSEL(x)                    ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_CR_TBSEL_SHIFT))&SAF_EQADC_ADC_CR_TBSEL_MASK))
#define SAF_EQADC_ADC_CR_EMUX_MASK                   0x800u
#define SAF_EQADC_ADC_CR_EMUX_SHIFT                  11u
#define SAF_EQADC_ADC_CR_EMUX_WIDTH                  1u
#define SAF_EQADC_ADC_CR_EMUX(x)                     ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_CR_EMUX_SHIFT))&SAF_EQADC_ADC_CR_EMUX_MASK))
#define SAF_EQADC_ADC_CR_EN_MASK                     0x8000u
#define SAF_EQADC_ADC_CR_EN_SHIFT                    15u
#define SAF_EQADC_ADC_CR_EN_WIDTH                    1u
#define SAF_EQADC_ADC_CR_EN(x)                       ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_CR_EN_SHIFT))&SAF_EQADC_ADC_CR_EN_MASK))
/*! ADC TSCR Bit Fields */
#define SAF_EQADC_ADC_TSCR_TBC_CLK_PS_MASK           0xFu
#define SAF_EQADC_ADC_TSCR_TBC_CLK_PS_SHIFT          0u
#define SAF_EQADC_ADC_TSCR_TBC_CLK_PS_WIDTH          4u
#define SAF_EQADC_ADC_TSCR_TBC_CLK_PS(x)             ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_TSCR_TBC_CLK_PS_SHIFT))&SAF_EQADC_ADC_TSCR_TBC_CLK_PS_MASK))
/*! ADC TBCR Bit Fields */
#define SAF_EQADC_ADC_TBCR_TBC_VALUE_MASK            0xFFFFu
#define SAF_EQADC_ADC_TBCR_TBC_VALUE_SHIFT           0u
#define SAF_EQADC_ADC_TBCR_TBC_VALUE_WIDTH           16u
#define SAF_EQADC_ADC_TBCR_TBC_VALUE(x)              ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_TBCR_TBC_VALUE_SHIFT))&SAF_EQADC_ADC_TBCR_TBC_VALUE_MASK))
/*! ADC GCCR Bit Fields */
#define SAF_EQADC_ADC_GCCR_GCC_MASK                  0x7FFFu
#define SAF_EQADC_ADC_GCCR_GCC_SHIFT                 0u
#define SAF_EQADC_ADC_GCCR_GCC_WIDTH                 15u
#define SAF_EQADC_ADC_GCCR_GCC(x)                    ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_GCCR_GCC_SHIFT))&SAF_EQADC_ADC_GCCR_GCC_MASK))
/*! ADC OCCR Bit Fields */
#define SAF_EQADC_ADC_OCCR_OCC_MASK                  0x3FFFu
#define SAF_EQADC_ADC_OCCR_OCC_SHIFT                 0u
#define SAF_EQADC_ADC_OCCR_OCC_WIDTH                 14u
#define SAF_EQADC_ADC_OCCR_OCC(x)                    ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_OCCR_OCC_SHIFT))&SAF_EQADC_ADC_OCCR_OCC_MASK))
/*! ADC ACR Bit Fields */
#define SAF_EQADC_ADC_ACR_PRE_GAIN_MASK              0x3u
#define SAF_EQADC_ADC_ACR_PRE_GAIN_SHIFT             0u
#define SAF_EQADC_ADC_ACR_PRE_GAIN_WIDTH             2u
#define SAF_EQADC_ADC_ACR_PRE_GAIN(x)                ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_ACR_PRE_GAIN_SHIFT))&SAF_EQADC_ADC_ACR_PRE_GAIN_MASK))
#define SAF_EQADC_ADC_ACR_ATBSEL_MASK                0xCu
#define SAF_EQADC_ADC_ACR_ATBSEL_SHIFT               2u
#define SAF_EQADC_ADC_ACR_ATBSEL_WIDTH               2u
#define SAF_EQADC_ADC_ACR_ATBSEL(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_ACR_ATBSEL_SHIFT))&SAF_EQADC_ADC_ACR_ATBSEL_MASK))
#define SAF_EQADC_ADC_ACR_RESSEL_MASK                0xC0u
#define SAF_EQADC_ADC_ACR_RESSEL_SHIFT               6u
#define SAF_EQADC_ADC_ACR_RESSEL_WIDTH               2u
#define SAF_EQADC_ADC_ACR_RESSEL(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_ACR_RESSEL_SHIFT))&SAF_EQADC_ADC_ACR_RESSEL_MASK))
#define SAF_EQADC_ADC_ACR_RPSI_MASK                  0x100u
#define SAF_EQADC_ADC_ACR_RPSI_SHIFT                 8u
#define SAF_EQADC_ADC_ACR_RPSI_WIDTH                 1u
#define SAF_EQADC_ADC_ACR_RPSI(x)                    ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_ACR_RPSI_SHIFT))&SAF_EQADC_ADC_ACR_RPSI_MASK))
#define SAF_EQADC_ADC_ACR_FMTA_MASK                  0x200u
#define SAF_EQADC_ADC_ACR_FMTA_SHIFT                 9u
#define SAF_EQADC_ADC_ACR_FMTA_WIDTH                 1u
#define SAF_EQADC_ADC_ACR_FMTA(x)                    ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_ACR_FMTA_SHIFT))&SAF_EQADC_ADC_ACR_FMTA_MASK))
#define SAF_EQADC_ADC_ACR_DEST_MASK                  0x3C00u
#define SAF_EQADC_ADC_ACR_DEST_SHIFT                 10u
#define SAF_EQADC_ADC_ACR_DEST_WIDTH                 4u
#define SAF_EQADC_ADC_ACR_DEST(x)                    ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_ACR_DEST_SHIFT))&SAF_EQADC_ADC_ACR_DEST_MASK))
#define SAF_EQADC_ADC_ACR_RET_INH_MASK               0x8000u
#define SAF_EQADC_ADC_ACR_RET_INH_SHIFT              15u
#define SAF_EQADC_ADC_ACR_RET_INH_WIDTH              1u
#define SAF_EQADC_ADC_ACR_RET_INH(x)                 ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_ACR_RET_INH_SHIFT))&SAF_EQADC_ADC_ACR_RET_INH_MASK))
/*! ADC AGR Bit Fields */
#define SAF_EQADC_ADC_AGR_ALTGCC_MASK                0x7FFFu
#define SAF_EQADC_ADC_AGR_ALTGCC_SHIFT               0u
#define SAF_EQADC_ADC_AGR_ALTGCC_WIDTH               15u
#define SAF_EQADC_ADC_AGR_ALTGCC(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_AGR_ALTGCC_SHIFT))&SAF_EQADC_ADC_AGR_ALTGCC_MASK))
/*! ADC AOR Bit Fields */
#define SAF_EQADC_ADC_AOR_ALTOCC_MASK                0x3FFFu
#define SAF_EQADC_ADC_AOR_ALTOCC_SHIFT               0u
#define SAF_EQADC_ADC_AOR_ALTOCC_WIDTH               14u
#define SAF_EQADC_ADC_AOR_ALTOCC(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_AOR_ALTOCC_SHIFT))&SAF_EQADC_ADC_AOR_ALTOCC_MASK))
#ifdef SAF_EQADC_ADC_EACR_EN
/*! ADC EACR Bit Fields */
#define SAF_EQADC_ADC_EACR_MESSAGE_TAG2_MASK         0xFu
#define SAF_EQADC_ADC_EACR_MESSAGE_TAG2_SHIFT        0u
#define SAF_EQADC_ADC_EACR_MESSAGE_TAG2_WIDTH        4u
#define SAF_EQADC_ADC_EACR_MESSAGE_TAG2(x)           ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_EACR_MESSAGE_TAG2_SHIFT))&SAF_EQADC_ADC_EACR_MESSAGE_TAG2_MASK))
#define SAF_EQADC_ADC_EACR_TEN2_MASK                 0x10u
#define SAF_EQADC_ADC_EACR_TEN2_SHIFT                4u
#define SAF_EQADC_ADC_EACR_TEN2_WIDTH                1u
#define SAF_EQADC_ADC_EACR_TEN2(x)                   ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_EACR_TEN2_SHIFT))&SAF_EQADC_ADC_EACR_TEN2_MASK))
#define SAF_EQADC_ADC_EACR_FLEN2_MASK                0x80u
#define SAF_EQADC_ADC_EACR_FLEN2_SHIFT               7u
#define SAF_EQADC_ADC_EACR_FLEN2_WIDTH               1u
#define SAF_EQADC_ADC_EACR_FLEN2(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_EACR_FLEN2_SHIFT))&SAF_EQADC_ADC_EACR_FLEN2_MASK))
#define SAF_EQADC_ADC_EACR_RPSI2_MASK                0x100u
#define SAF_EQADC_ADC_EACR_RPSI2_SHIFT               8u
#define SAF_EQADC_ADC_EACR_RPSI2_WIDTH               1u
#define SAF_EQADC_ADC_EACR_RPSI2(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_EACR_RPSI2_SHIFT))&SAF_EQADC_ADC_EACR_RPSI2_MASK))
#define SAF_EQADC_ADC_EACR_FMTA2_MASK                0x200u
#define SAF_EQADC_ADC_EACR_FMTA2_SHIFT               9u
#define SAF_EQADC_ADC_EACR_FMTA2_WIDTH               1u
#define SAF_EQADC_ADC_EACR_FMTA2(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_EACR_FMTA2_SHIFT))&SAF_EQADC_ADC_EACR_FMTA2_MASK))
#define SAF_EQADC_ADC_EACR_DEST2_MASK                0x3C00u
#define SAF_EQADC_ADC_EACR_DEST2_SHIFT               10u
#define SAF_EQADC_ADC_EACR_DEST2_WIDTH               4u
#define SAF_EQADC_ADC_EACR_DEST2(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_EACR_DEST2_SHIFT))&SAF_EQADC_ADC_EACR_DEST2_MASK))
#define SAF_EQADC_ADC_EACR_RET_INH2_MASK             0x8000u
#define SAF_EQADC_ADC_EACR_RET_INH2_SHIFT            15u
#define SAF_EQADC_ADC_EACR_RET_INH2_WIDTH            1u
#define SAF_EQADC_ADC_EACR_RET_INH2(x)               ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_EACR_RET_INH2_SHIFT))&SAF_EQADC_ADC_EACR_RET_INH2_MASK))
#endif  /* SAF_EQADC_ADC_EACR_EN */
#ifdef SAF_EQADC_ADC_PUDCR_EN
/*! ADC PUDCR Bit Fields */
#define SAF_EQADC_ADC_PUDCR_PULL_STR_MASK            0x300u
#define SAF_EQADC_ADC_PUDCR_PULL_STR_SHIFT           8u
#define SAF_EQADC_ADC_PUDCR_PULL_STR_WIDTH           2u
#define SAF_EQADC_ADC_PUDCR_PULL_STR(x)              ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_PUDCR_PULL_STR_SHIFT))&SAF_EQADC_ADC_PUDCR_PULL_STR_MASK))
#define SAF_EQADC_ADC_PUDCR_CH_PULL_MASK             0x3000u
#define SAF_EQADC_ADC_PUDCR_CH_PULL_SHIFT            12u
#define SAF_EQADC_ADC_PUDCR_CH_PULL_WIDTH            2u
#define SAF_EQADC_ADC_PUDCR_CH_PULL(x)               ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_PUDCR_CH_PULL_SHIFT))&SAF_EQADC_ADC_PUDCR_CH_PULL_MASK))
#endif  /* SAF_EQADC_ADC_PUDCR_EN */
/*! ADC STACTBR Bit Fields */
#define SAF_EQADC_ADC_STACTBR_TB_VALUE_MASK          0xFFFFu
#define SAF_EQADC_ADC_STACTBR_TB_VALUE_SHIFT         0u
#define SAF_EQADC_ADC_STACTBR_TB_VALUE_WIDTH         16u
#define SAF_EQADC_ADC_STACTBR_TB_VALUE(x)            ((uint16_t)(((uint16_t)(((uint16_t)(x))<<SAF_EQADC_ADC_STACTBR_TB_VALUE_SHIFT))&SAF_EQADC_ADC_STACTBR_TB_VALUE_MASK))


/*******************************************************************************
 * @brief SAF_EQADC instance number.
 *
 * @note  This chip has five instances of the SAF_EQADC module.
 *******************************************************************************/
typedef enum
{
#ifdef RESOURCE_SUPPORT_EQADC_INST0
    SAF_EQADC_INSTANCE_0                = 0U,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_INST1
    SAF_EQADC_INSTANCE_1                = 1U,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_INST2
    SAF_EQADC_INSTANCE_2                = 2U,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_INST3
    SAF_EQADC_INSTANCE_3                = 3U,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_INST4
    SAF_EQADC_INSTANCE_4                = 4U,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_INST5
    SAF_EQADC_INSTANCE_5                = 5U,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_INST6
    SAF_EQADC_INSTANCE_6                = 6U
#endif
} SafEqadcInstanceType;

/*******************************************************************************
 * @brief SAF_EQADCx's on-chip ADC number.
 *
 * @note  Each SAF_EQADC module: controls two independent analog-to-digital (ADC):
 *          ADC0 and ADC1.
 *******************************************************************************/
typedef enum
{
    SAF_EQADC_ADC_0                     = 0U,
    SAF_EQADC_ADC_1                     = 1U
} SafEqadcAdcIdxType;

/*******************************************************************************
 * @brief EQADC ADC hardware unit number
 *******************************************************************************/
#define SAF_EQADC_ADC_UNIT_0            (0U)    /* SAF_EQADC_INSTANCE_0 -> SAF_EQADC_ADC_0 */
#define SAF_EQADC_ADC_UNIT_1            (1U)    /* SAF_EQADC_INSTANCE_0 -> SAF_EQADC_ADC_1 */
#define SAF_EQADC_ADC_UNIT_2            (2U)    /* SAF_EQADC_INSTANCE_1 -> SAF_EQADC_ADC_0 */
#define SAF_EQADC_ADC_UNIT_3            (3U)    /* SAF_EQADC_INSTANCE_1 -> SAF_EQADC_ADC_1 */
#define SAF_EQADC_ADC_UNIT_4            (4U)    /* SAF_EQADC_INSTANCE_2 -> SAF_EQADC_ADC_0 */
#define SAF_EQADC_ADC_UNIT_5            (5U)    /* SAF_EQADC_INSTANCE_2 -> SAF_EQADC_ADC_1 */
#define SAF_EQADC_ADC_UNIT_6            (6U)    /* SAF_EQADC_INSTANCE_3 -> SAF_EQADC_ADC_0 */
#define SAF_EQADC_ADC_UNIT_7            (7U)    /* SAF_EQADC_INSTANCE_3 -> SAF_EQADC_ADC_1 */
#define SAF_EQADC_ADC_UNIT_8            (8U)    /* SAF_EQADC_INSTANCE_4 -> SAF_EQADC_ADC_0 */
#define SAF_EQADC_ADC_UNIT_9            (9U)    /* SAF_EQADC_INSTANCE_4 -> SAF_EQADC_ADC_1 */
#define SAF_EQADC_ADC_UNIT_10           (10U)   /* SAF_EQADC_INSTANCE_5 -> SAF_EQADC_ADC_0 */
#define SAF_EQADC_ADC_UNIT_11           (11U)   /* SAF_EQADC_INSTANCE_5 -> SAF_EQADC_ADC_1 */
#define SAF_EQADC_ADC_UNIT_12           (12U)   /* SAF_EQADC_INSTANCE_6 -> SAF_EQADC_ADC_0 */

/*******************************************************************************
 * @brief EQADCx's CFIFO/RFIFO number.
 *
 * @note  Each SAF_EQADC module: six CFIFO + six RFIFO.
 *******************************************************************************/
typedef enum
{
    SAF_EQADC_FIFO_0                    = 0U,
    SAF_EQADC_FIFO_1                    = 1U,
    SAF_EQADC_FIFO_2                    = 2U,
    SAF_EQADC_FIFO_3                    = 3U,
    SAF_EQADC_FIFO_4                    = 4U,
    SAF_EQADC_FIFO_5                    = 5U,
} SafEqadcFifoIdxType;

typedef enum
{
    SAF_EQADC_FISR_NON_COHERENCY        = 0U,
    SAF_EQADC_FISR_TRIG_OVERRUN         = 1U,
    SAF_EQADC_FISR_PAUSE                = 2U,
    SAF_EQADC_FISR_END_OF_QUEUE         = 3U,
    SAF_EQADC_FISR_CFIFO_UNDERFLOW      = 4U,
    SAF_EQADC_FISR_CFIFO_SINGLE_SCAN    = 5U,
    SAF_EQADC_FISR_CFIFO_FILL           = 6U,
    SAF_EQADC_FISR_RFIFO_OVERFLOW       = 7U,
    SAF_EQADC_FISR_RFIFO_DRAIN          = 8U,
    SAF_EQADC_FISR_CFIFO_ENTRY_COUNT    = 9U,
    SAF_EQADC_FISR_CFIFO_TRANS_NEXT_PTR = 10U,
    SAF_EQADC_FISR_RFIFO_ENTRY_COUNT    = 11U,
    SAF_EQADC_FISR_RFIFO_POP_NEXT_PTR   = 12U
} SafEqadc_FifoIntStatusType;

/* @brief SAF_EQADC FIFO interrupt & DMA select */
#define SAF_EQADC_IRQ_DMA_REQ_SEL_CFIFO_FILL    (SAF_EQADC_IDCR0_CFFS1_MASK)
#define SAF_EQADC_IRQ_DMA_REQ_SEL_RFIFO_DRAIN   (SAF_EQADC_IDCR0_RFDS1_MASK)

/* @brief SAF_EQADC FIFO interrupt & DMA source */
#define SAF_EQADC_IRQ_EN_NON_COHERENCY          (SAF_EQADC_IDCR0_NCIE1_MASK)   /* Non-Coherency Interrupt Enable */
#define SAF_EQADC_IRQ_EN_TRIGGER_OVERRUN        (SAF_EQADC_IDCR0_TORIE1_MASK)  /* Trigger Overrun Interrupt Enable */
#define SAF_EQADC_IRQ_EN_PAUSE                  (SAF_EQADC_IDCR0_PIE1_MASK)    /* Pause Interrupt Enable */
#define SAF_EQADC_IRQ_EN_END_OF_QUEUE           (SAF_EQADC_IDCR0_EOQIE1_MASK)  /* End of Queue Interrupt Enable */
#define SAF_EQADC_IRQ_EN_CFIFO_UNDERFLOW        (SAF_EQADC_IDCR0_CFUIE1_MASK)  /* CFIFO Underflow Interrupt Enable */
#define SAF_EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL     (SAF_EQADC_IDCR0_CFFE1_MASK)   /* CFIFO Fill Enable */
#define SAF_EQADC_IRQ_EN_RFIFO_OVERFLOW         (SAF_EQADC_IDCR0_RFOIE1_MASK)  /* RFIFO Overflow Interrupt Enable */
#define SAF_EQADC_IRQ_DMA_REQ_EN_RFIFO_DRAIN    (SAF_EQADC_IDCR0_RFDE1_MASK)   /* RFIFO Drain Enable */
#define SAF_EQADC_IRQ_EN_GRP_ALL                (SAF_EQADC_IRQ_EN_NON_COHERENCY | \
                                             SAF_EQADC_IRQ_EN_PAUSE | \
                                             SAF_EQADC_IRQ_EN_END_OF_QUEUE | \
                                             SAF_EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL | \
                                             SAF_EQADC_IRQ_DMA_REQ_EN_RFIFO_DRAIN)  /* No TORIE/CFUIE/RFOIE, for GTM module use */
#define SAF_EQADC_IRQ_EN_ALL                    (SAF_EQADC_IRQ_EN_NON_COHERENCY | \
                                             SAF_EQADC_IRQ_EN_TRIGGER_OVERRUN | \
                                             SAF_EQADC_IRQ_EN_PAUSE | \
                                             SAF_EQADC_IRQ_EN_END_OF_QUEUE | \
                                             SAF_EQADC_IRQ_EN_CFIFO_UNDERFLOW | \
                                             SAF_EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL | \
                                             SAF_EQADC_IRQ_EN_RFIFO_OVERFLOW | \
                                             SAF_EQADC_IRQ_DMA_REQ_EN_RFIFO_DRAIN)
#define SAF_EQADC_DMA_EN_ALL                    (SAF_EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL | SAF_EQADC_IRQ_DMA_REQ_EN_RFIFO_DRAIN)

/* @brief SAF_EQADC FIFO status flags */
#define SAF_EQADC_FIFO_FLAG_NON_COHERENCY       (SAF_EQADC_FISR_NCFX_MASK)
#define SAF_EQADC_FIFO_FLAG_TRIG_OVERRUN        (SAF_EQADC_FISR_TORFX_MASK)
#define SAF_EQADC_FIFO_FLAG_PAUSE               (SAF_EQADC_FISR_PFX_MASK)
#define SAF_EQADC_FIFO_FLAG_END_OF_QUEUE        (SAF_EQADC_FISR_EOQFX_MASK)
#define SAF_EQADC_FIFO_FLAG_CFIFO_UNDERFLOW     (SAF_EQADC_FISR_CFUFX_MASK)
#define SAF_EQADC_FIFO_FLAG_CFIFO_FILL          (SAF_EQADC_FISR_CFFFX_MASK)
#define SAF_EQADC_FIFO_FLAG_RFIFO_OVERFLOW      (SAF_EQADC_FISR_RFOFX_MASK)
#define SAF_EQADC_FIFO_FLAG_RFIFO_DRAIN         (SAF_EQADC_FISR_RFDFX_MASK)
#define SAF_EQADC_FIFO_FLAG_ALL                 (SAF_EQADC_FIFO_FLAG_NON_COHERENCY | \
                                             SAF_EQADC_FIFO_FLAG_TRIG_OVERRUN | \
                                             SAF_EQADC_FIFO_FLAG_PAUSE | \
                                             SAF_EQADC_FIFO_FLAG_END_OF_QUEUE | \
                                             SAF_EQADC_FIFO_FLAG_CFIFO_UNDERFLOW | \
                                             SAF_EQADC_FIFO_FLAG_CFIFO_FILL | \
                                             SAF_EQADC_FIFO_FLAG_RFIFO_OVERFLOW | \
                                             SAF_EQADC_FIFO_FLAG_RFIFO_DRAIN)

typedef enum
{
    SAF_EQADC_CFIFO_MODE_DISABLE                        = 0U,   /* CFIFO Operation Mode: Disabled */
    SAF_EQADC_CFIFO_MODE_SINGLE_SW_TRIG                 = 1U,   /* CFIFO Operation Mode: Software Trigger, Single Scan */
    SAF_EQADC_CFIFO_MODE_SINGLE_LOW_LVL_GATED_EXT_TRIG  = 2U,   /* CFIFO Operation Mode: Low Level Gated External Trigger, Single Scan */
    SAF_EQADC_CFIFO_MODE_SINGLE_HIGH_LVL_GATED_EXT_TRIG = 3U,   /* CFIFO Operation Mode: High Level Gated External Trigger, Single Scan */
    SAF_EQADC_CFIFO_MODE_SINGLE_FALLING_EDGE_EXT_TRIG   = 4U,   /* CFIFO Operation Mode: Falling Edge External Trigger, Single Scan */
    SAF_EQADC_CFIFO_MODE_SINGLE_RISING_EDGE_EXT_TRIG    = 5U,   /* CFIFO Operation Mode: Rising Edge External Trigger, Single Scan */
    SAF_EQADC_CFIFO_MODE_SINGLE_BOTH_EDGES_EXT_TRIG     = 6U,   /* CFIFO Operation Mode: Falling or Rising Edge External Trigger, Single Scan */
    SAF_EQADC_CFIFO_MODE_CONT_SW_TRIG                   = 9U,   /* CFIFO Operation Mode: Software Trigger, Continuous Scan */
    SAF_EQADC_CFIFO_MODE_CONT_LOW_LVL_GATED_EXT_TRIG    = 10U,  /* CFIFO Operation Mode: Low Level Gated External Trigger, Continuous Scan */
    SAF_EQADC_CFIFO_MODE_CONT_HIGH_LVL_GATED_EXT_TRIG   = 11U,  /* CFIFO Operation Mode: High Level Gated External Trigger, Continuous Scan */
    SAF_EQADC_CFIFO_MODE_CONT_FALLING_EDGE_EXT_TRIG     = 12U,  /* CFIFO Operation Mode: Falling Edge External Trigger, Continuous Scan */
    SAF_EQADC_CFIFO_MODE_CONT_RISING_EDGE_EXT_TRIG      = 13U,  /* CFIFO Operation Mode: Rising Edge External Trigger, Continuous Scan */
    SAF_EQADC_CFIFO_MODE_CONT_BOTH_EDGES_EXT_TRIG       = 14U   /* CFIFO Operation Mode: Falling or Rising Edge External Trigger, Continuous Scan */
} SafEqadc_CfifoModeType;

typedef enum
{
    SAF_EQADC_CFIFO0_AMODE_DISABLE                          = 0U,   /* CFIFO0 Advance Trigger Operation Mode: Disabled */
    SAF_EQADC_CFIFO0_AMODE_SINGLE_SW_TRIG                   = 1U,   /* CFIFO0 Advance Trigger Operation Mode: Software Trigger, Single Scan */
    SAF_EQADC_CFIFO0_AMODE_SINGLE_LOW_LVL_GATED_EXT_TRIG    = 2U,   /* CFIFO0 Advance Trigger Operation Mode: Low Level Gated External Trigger, Single Scan */
    SAF_EQADC_CFIFO0_AMODE_SINGLE_HIGH_LVL_GATED_EXT_TRIG   = 3U,   /* CFIFO0 Advance Trigger Operation Mode: High Level Gated External Trigger, Single Scan */
    SAF_EQADC_CFIFO0_AMODE_SINGLE_FALLING_EDGE_EXT_TRIG     = 4U,   /* CFIFO0 Advance Trigger Operation Mode: Falling Edge External Trigger, Single Scan */
    SAF_EQADC_CFIFO0_AMODE_SINGLE_RISING_EDGE_EXT_TRIG      = 5U,   /* CFIFO0 Advance Trigger Operation Mode: Rising Edge External Trigger, Single Scan */
    SAF_EQADC_CFIFO0_AMODE_SINGLE_BOTH_EDGES_EXT_TRIG       = 6U    /* CFIFO0 Advance Trigger Operation Mode: Falling or Rising Edge External Trigger, Single Scan */
} SafEqadc_Cfifo0AModeType;

typedef enum
{
    SAF_EQADC_FILL_SEL_INT          = 0U,
    SAF_EQADC_FILL_SEL_DMA          = 1U
} SafEqadc_IntDmaFillSelType;

/*******************************************************************************
 * @brief Time Base Counter Clock Prescaler (ADC_TSCR: TBC_CLK_PS).
 *
 * @note  If TBC_CLK_PS is not set to disabled,
 *          it must not be changed to any other value besides disabled.
 *******************************************************************************/
typedef enum
{
    SAF_EQADC_TBC_CLK_PS_DISABLED   = 0U,   /* The time base counter clock prescaler is disabled */
    SAF_EQADC_TBC_CLK_PS_DIV_1      = 1U,   /* System clock divide factor: 1 */
    SAF_EQADC_TBC_CLK_PS_DIV_2      = 2U,   /* System clock divide factor: 2 */
    SAF_EQADC_TBC_CLK_PS_DIV_4      = 3U,   /* System clock divide factor: 4 */
    SAF_EQADC_TBC_CLK_PS_DIV_6      = 4U,   /* System clock divide factor: 6 */
    SAF_EQADC_TBC_CLK_PS_DIV_8      = 5U,   /* System clock divide factor: 8 */
    SAF_EQADC_TBC_CLK_PS_DIV_10     = 6U,   /* System clock divide factor: 10 */
    SAF_EQADC_TBC_CLK_PS_DIV_12     = 7U,   /* System clock divide factor: 12 */
    SAF_EQADC_TBC_CLK_PS_DIV_16     = 8U,   /* System clock divide factor: 16 */
    SAF_EQADC_TBC_CLK_PS_DIV_32     = 9U,   /* System clock divide factor: 32 */
    SAF_EQADC_TBC_CLK_PS_DIV_64     = 10U,  /* System clock divide factor: 64 */
    SAF_EQADC_TBC_CLK_PS_DIV_128    = 11U,  /* System clock divide factor: 128 */
    SAF_EQADC_TBC_CLK_PS_DIV_256    = 12U,  /* System clock divide factor: 256 */
    SAF_EQADC_TBC_CLK_PS_DIV_512    = 13U   /* System clock divide factor: 512 */
} SafEqadc_TimeBaseCountClkPresType;

/*******************************************************************************
 * @brief Time base Selection for ADC0/1 (ADCx_CR: ADCx_TBSEL).
 *
 * @note  This selection is overridden by the corresponding field ATBSEL in the
 *          ADC_ACRx registers when the alternate conversion command is used.
 *******************************************************************************/
typedef enum
{
    SAF_EQADC_TBS_INTERNAL          = 0U,   /* Selects internally generated time base as time stamp */
    SAF_EQADC_TBS_STACCCR_SRV1      = 1U,   /* Selects imported time base 1 indicated by SRV1 bit field of SAF_EQADC_STACCCR */
    SAF_EQADC_TBS_STACCCR_SRV2      = 2U    /* Selects imported time base 2 indicated by SRV2 bit field of SAF_EQADC_STACCCR */
} SafEqadc_TimeBaseSelType;

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
    SAF_EQADC_CLK_SEL_PS_DIV        = 0U,   /* Prescaler output clock is selected: SAF_EQADC_CLK_PS_DIV_x. */
    SAF_EQADC_CLK_SEL_MAX_FREQ      = 1U    /* Platform clock is selected: maximum frequency. */
} SafEqadc_ClkSelType;

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
    SAF_EQADC_CLK_PS_DIV_2          = 0U,   /* Platform Clock Divide Factor: 2 */
    SAF_EQADC_CLK_PS_DIV_4          = 1U,   /* Platform Clock Divide Factor: 4 */
    SAF_EQADC_CLK_PS_DIV_6          = 2U,   /* Platform Clock Divide Factor: 6 */
    SAF_EQADC_CLK_PS_DIV_8          = 3U,   /* Platform Clock Divide Factor: 8 */
    SAF_EQADC_CLK_PS_DIV_10         = 4U,   /* Platform Clock Divide Factor: 10 */
    SAF_EQADC_CLK_PS_DIV_12         = 5U,   /* Platform Clock Divide Factor: 12 */
    SAF_EQADC_CLK_PS_DIV_14         = 6U,   /* Platform Clock Divide Factor: 14 */
    SAF_EQADC_CLK_PS_DIV_16         = 7U,   /* Platform Clock Divide Factor: 16 */
    SAF_EQADC_CLK_PS_DIV_18         = 8U,   /* Platform Clock Divide Factor: 18 */
    SAF_EQADC_CLK_PS_DIV_20         = 9U,   /* Platform Clock Divide Factor: 20 */
    SAF_EQADC_CLK_PS_DIV_22         = 10U,  /* Platform Clock Divide Factor: 22 */
    SAF_EQADC_CLK_PS_DIV_24         = 11U,  /* Platform Clock Divide Factor: 24 */
    SAF_EQADC_CLK_PS_DIV_26         = 12U,  /* Platform Clock Divide Factor: 26 */
    SAF_EQADC_CLK_PS_DIV_28         = 13U,  /* Platform Clock Divide Factor: 28 */
    SAF_EQADC_CLK_PS_DIV_30         = 14U,  /* Platform Clock Divide Factor: 30 */
    SAF_EQADC_CLK_PS_DIV_32         = 15U,  /* Platform Clock Divide Factor: 32 */
    SAF_EQADC_CLK_PS_DIV_34         = 16U,  /* Platform Clock Divide Factor: 34 */
    SAF_EQADC_CLK_PS_DIV_36         = 17U,  /* Platform Clock Divide Factor: 36 */
    SAF_EQADC_CLK_PS_DIV_38         = 18U,  /* Platform Clock Divide Factor: 38 */
    SAF_EQADC_CLK_PS_DIV_40         = 19U,  /* Platform Clock Divide Factor: 40 */
    SAF_EQADC_CLK_PS_DIV_42         = 20U,  /* Platform Clock Divide Factor: 42 */
    SAF_EQADC_CLK_PS_DIV_44         = 21U,  /* Platform Clock Divide Factor: 44 */
    SAF_EQADC_CLK_PS_DIV_46         = 22U,  /* Platform Clock Divide Factor: 46 */
    SAF_EQADC_CLK_PS_DIV_48         = 23U,  /* Platform Clock Divide Factor: 48 */
    SAF_EQADC_CLK_PS_DIV_50         = 24U,  /* Platform Clock Divide Factor: 50 */
    SAF_EQADC_CLK_PS_DIV_52         = 25U,  /* Platform Clock Divide Factor: 52 */
    SAF_EQADC_CLK_PS_DIV_54         = 26U,  /* Platform Clock Divide Factor: 54 */
    SAF_EQADC_CLK_PS_DIV_56         = 27U,  /* Platform Clock Divide Factor: 56 */
    SAF_EQADC_CLK_PS_DIV_58         = 28U,  /* Platform Clock Divide Factor: 58 */
    SAF_EQADC_CLK_PS_DIV_60         = 29U,  /* Platform Clock Divide Factor: 60 */
    SAF_EQADC_CLK_PS_DIV_62         = 30U,  /* Platform Clock Divide Factor: 62 */
    SAF_EQADC_CLK_PS_DIV_64         = 31U   /* Platform Clock Divide Factor: 64 */
} SafEqadc_ClkPrescaleType;

typedef enum
{
    SAF_EQADC_ALT_CONFIG_DISABLE    = 0x0U,     /* Select Standard Configuration for the conversion command */
    SAF_EQADC_ALT_CONFIG_SEL_1      = 0x8U,     /* Select Alternate Configuration 1 for the conversion command */
    SAF_EQADC_ALT_CONFIG_SEL_2      = 0x9U,     /* Select Alternate Configuration 2 for the conversion command */
    SAF_EQADC_ALT_CONFIG_SEL_3      = 0xAU,     /* Select Alternate Configuration 3 for the conversion command */
    SAF_EQADC_ALT_CONFIG_SEL_4      = 0xBU,     /* Select Alternate Configuration 4 for the conversion command */
    SAF_EQADC_ALT_CONFIG_SEL_5      = 0xCU,     /* Select Alternate Configuration 5 for the conversion command */
    SAF_EQADC_ALT_CONFIG_SEL_6      = 0xDU,     /* Select Alternate Configuration 6 for the conversion command */
    SAF_EQADC_ALT_CONFIG_SEL_7      = 0xEU,     /* Select Alternate Configuration 7 for the conversion command */
    SAF_EQADC_ALT_CONFIG_SEL_8      = 0xFU,     /* Select Alternate Configuration 8 for the conversion command */
    SAF_EQADC_ALT_CONFIG_SEL_9      = 0x10U,    /* Select Alternate Configuration 9 for the conversion command */
    SAF_EQADC_ALT_CONFIG_SEL_10     = 0x11U,    /* Select Alternate Configuration 10 for the conversion command */
    SAF_EQADC_ALT_CONFIG_SEL_11     = 0x12U,    /* Select Alternate Configuration 11 for the conversion command */
    SAF_EQADC_ALT_CONFIG_SEL_12     = 0x13U,    /* Select Alternate Configuration 12 for the conversion command */
    SAF_EQADC_ALT_CONFIG_SEL_13     = 0x14U,    /* Select Alternate Configuration 13 for the conversion command */
    SAF_EQADC_ALT_CONFIG_SEL_14     = 0x15U     /* Select Alternate Configuration 14 for the conversion command */
} SafEqadc_AltConfigSelType;  //  SEL NUM? TODO

typedef enum
{
    SAF_EQADC_ALT_DEST_RFIFO        = 0x0U,
    SAF_EQADC_ALT_DEST_DECFILT_A    = 0x1U,
    SAF_EQADC_ALT_DEST_DECFILT_B    = 0x2U,
    SAF_EQADC_ALT_DEST_DECFILT_C    = 0x3U,
    SAF_EQADC_ALT_DEST_DECFILT_D    = 0x4U,
    SAF_EQADC_ALT_DEST_DECFILT_E    = 0x5U,
    SAF_EQADC_ALT_DEST_DECFILT_F    = 0x6U,
    SAF_EQADC_ALT_DEST_DECFILT_G    = 0x7U,
    SAF_EQADC_ALT_DEST_DECFILT_A_E  = 0x8U,
    SAF_EQADC_ALT_DEST_DECFILT_B_E  = 0x9U,
    SAF_EQADC_ALT_DEST_DECFILT_C_E  = 0xAU,
    SAF_EQADC_ALT_DEST_DECFILT_D_E  = 0xBU,
    SAF_EQADC_ALT_DEST_DECFILT_A_G  = 0xCU,
    SAF_EQADC_ALT_DEST_DECFILT_B_G  = 0xDU,
    SAF_EQADC_ALT_DEST_DECFILT_C_G  = 0xEU,
    SAF_EQADC_ALT_DEST_DECFILT_D_G  = 0xFU
} SafEqadc_AltConfigDestType;

typedef enum
{
    SAF_EQADC_RES_SEL_12_BITS       = 0U,
    SAF_EQADC_RES_SEL_10_BITS       = 1U,
    SAF_EQADC_RES_SEL_8_BITS        = 2U
} SafEqadc_ResolutionSelType;

typedef enum
{
    SAF_EQADC_PRE_GAIN_X1           = 0U,
    SAF_EQADC_PRE_GAIN_X2           = 1U,
    SAF_EQADC_PRE_GAIN_X4           = 2U
} SafEqadc_PreGainType;

typedef enum
{
    SAF_EQADC_CH_PULL_DISABLED      = 0U,
    SAF_EQADC_CH_PULL_UP            = 1U,
    SAF_EQADC_CH_PULL_DOWN          = 2U,
    SAF_EQADC_CH_PULL_UP_DOWN       = 3U
} SafEqadc_ChanPullType;

typedef enum
{
    SAF_EQADC_PULL_STR_200KOHM      = 1U,
    SAF_EQADC_PULL_STR_100KOHM      = 2U,
    SAF_EQADC_PULL_STR_5KOHM        = 3U
} SafEqadc_PullStrengthType;

#define SAF_EQADC_STAC_BUS_CLIENT_1 (0U)
#define SAF_EQADC_STAC_BUS_CLIENT_2 (1U)

typedef enum
{
    SAF_EQADC_SRV_ETPU_A_TCR_1      = 0U,
    SAF_EQADC_SRV_ETPU_B_TCR_1      = 1U,
    SAF_EQADC_SRV_ETPU_A_TCR_2      = 2U,
    SAF_EQADC_SRV_ETPU_B_TCR_2      = 3U
} SafEqadc_RedLineServerDataSlotSelType;  //  todo

typedef enum
{
    SAF_EQADC_REDLINE_BITS_SEL_TBASE_0_15   = 0U,
    SAF_EQADC_REDLINE_BITS_SEL_TBASE_1_16   = 1U,
    SAF_EQADC_REDLINE_BITS_SEL_TBASE_2_17   = 2U,
    SAF_EQADC_REDLINE_BITS_SEL_TBASE_3_18   = 3U,
    SAF_EQADC_REDLINE_BITS_SEL_TBASE_4_19   = 4U,
    SAF_EQADC_REDLINE_BITS_SEL_TBASE_5_20   = 5U,
    SAF_EQADC_REDLINE_BITS_SEL_TBASE_6_21   = 6U,
    SAF_EQADC_REDLINE_BITS_SEL_TBASE_7_22   = 7U,
    SAF_EQADC_REDLINE_BITS_SEL_TBASE_8_23   = 8U
} SafEqadc_RedLineBitsSelType;

typedef enum
{
    SAF_EQADC_CFIFO_STATUS_IDLE             = 0U,
    SAF_EQADC_CFIFO_STATUS_WAITING_FOR_TRIG = 2U,
    SAF_EQADC_CFIFO_STATUS_TRIGGERED        = 3U
} SafEqadc_CfifoStatusType;

typedef enum
{
    SAF_EQADC_MSG_TAG_RFIFO0                = 0U,
    SAF_EQADC_MSG_TAG_RFIFO1                = 1U,
    SAF_EQADC_MSG_TAG_RFIFO2                = 2U,
    SAF_EQADC_MSG_TAG_RFIFO3                = 3U,
    SAF_EQADC_MSG_TAG_RFIFO4                = 4U,
    SAF_EQADC_MSG_TAG_RFIFO5                = 5U,
    SAF_EQADC_MSG_TAG_NULL_MSG              = 8U,
    SAF_EQADC_MSG_TAG_RESERVED_0            = 9U,
    SAF_EQADC_MSG_TAG_RESERVED_1            = 10U
} SafEqadc_RfifoMsgTagType;

typedef enum
{
    SAF_EQADC_ADCLK_SAMPLING_CYCLES_2       = 0U,
    SAF_EQADC_ADCLK_SAMPLING_CYCLES_8       = 1U,
    SAF_EQADC_ADCLK_SAMPLING_CYCLES_64      = 2U,
    SAF_EQADC_ADCLK_SAMPLING_CYCLES_128     = 3U
} SafEqadc_LongSampTimeType;

typedef enum
{
    SAF_EQADC_CONFIG_CMD_WRITE              = 0U,
    SAF_EQADC_CONFIG_CMD_READ               = 1U
} SafEqadc_RwConfigCmdType;

typedef enum
{
    SAF_EQADC_ADC_REG_CR         = 0x01U,    /* The address of ADC0/ADC1 Configuration Control Register */
    SAF_EQADC_ADC_REG_TSCR       = 0x02U,    /* The address of Time Stamp Control Register */
    SAF_EQADC_ADC_REG_TBCR       = 0x03U,    /* The address of Time Base Counter Register */
    SAF_EQADC_ADC_REG_GCCR       = 0x04U,    /* The address of ADC0/ADC1 Gain Calibration Constant Register */
    SAF_EQADC_ADC_REG_OCCR       = 0x05U,    /* The address of ADC0/ADC1 Offset Calibration Constant Register */
    SAF_EQADC_ADC_REG_ACR1       = 0x30U,    /* The address of Alternate Configuration 1 Control Register */
    SAF_EQADC_ADC_REG_AGR1       = 0x31U,    /* The address of ADC0/ADC1 Alternate Gain 1 Register */
    SAF_EQADC_ADC_REG_AOR1       = 0x32U,    /* The address of ADC0/ADC1 Alternate Offset 1 Register */
    SAF_EQADC_ADC_REG_EACR1      = 0x33U,    /* The address of Extended Alternate Configuration 1 Control Register */
    SAF_EQADC_ADC_REG_ACR2       = 0x34U,    /* The address of Alternate Configuration 2 Control Register */
    SAF_EQADC_ADC_REG_AGR2       = 0x35U,    /* The address of ADC0/ADC1 Alternate Gain 2 Register */
    SAF_EQADC_ADC_REG_AOR2       = 0x36U,    /* The address of ADC0/ADC1 Alternate Offset 2 Register */
    SAF_EQADC_ADC_REG_EACR2      = 0x37U,    /* The address of Extended Alternate Configuration 2 Control Register */
    SAF_EQADC_ADC_REG_ACR3       = 0x38U,    /* The address of Alternate Configuration 3 Control Register */
    SAF_EQADC_ADC_REG_EACR3      = 0x3BU,    /* The address of Extended Alternate Configuration 3 Control Register */
    SAF_EQADC_ADC_REG_ACR4       = 0x3CU,    /* The address of Alternate Configuration 4 Control Register */
    SAF_EQADC_ADC_REG_EACR4      = 0x3FU,    /* The address of AExtended Alternate Configuration 4 Control Register */
    SAF_EQADC_ADC_REG_ACR5       = 0x40U,    /* The address of Alternate Configuration 5 Control Register */
    SAF_EQADC_ADC_REG_EACR5      = 0x43U,    /* The address of Extended Alternate Configuration 5 Control Register */
    SAF_EQADC_ADC_REG_ACR6       = 0x44U,    /* The address of Alternate Configuration 6 Control Register */
    SAF_EQADC_ADC_REG_EACR6      = 0x47U,    /* The address of Extended Alternate Configuration 6 Control Register */
    SAF_EQADC_ADC_REG_ACR7       = 0x48U,    /* The address of Alternate Configuration 7 Control Register */
    SAF_EQADC_ADC_REG_EACR7      = 0x4BU,    /* The address of Extended Alternate Configuration 7 Control Register */
    SAF_EQADC_ADC_REG_ACR8       = 0x4CU,    /* The address of Alternate Configuration 8 Control Register */
    SAF_EQADC_ADC_REG_EACR8      = 0x4FU,    /* The address of Extended Alternate Configuration 8 Control Register */
    SAF_EQADC_ADC_REG_ACR9       = 0x50U,    /* The address of Alternate Configuration 9 Control Register */
    SAF_EQADC_ADC_REG_EACR9      = 0x53U,    /* The address of AExtended Alternate Configuration 9 Control Register */
    SAF_EQADC_ADC_REG_ACR10      = 0x54U,    /* The address of Alternate Configuration 10 Control Register */
    SAF_EQADC_ADC_REG_EACR10     = 0x57U,    /* The address of Extended Alternate Configuration 10 Control Register */
    SAF_EQADC_ADC_REG_ACR11      = 0x58U,    /* The address of Alternate Configuration 11 Control Register */
    SAF_EQADC_ADC_REG_EACR11     = 0x5BU,    /* The address of Extended Alternate Configuration 11 Control Register */
    SAF_EQADC_ADC_REG_ACR12      = 0x5CU,    /* The address of Alternate Configuration 12 Control Register */
    SAF_EQADC_ADC_REG_EACR12     = 0x5FU,    /* The address of Extended Alternate Configuration 12 Control Register */
    SAF_EQADC_ADC_REG_ACR13      = 0x60U,    /* The address of Alternate Configuration 13 Control Register */
    SAF_EQADC_ADC_REG_EACR13     = 0x63U,    /* The address of Extended Alternate Configuration 13 Control Register */
    SAF_EQADC_ADC_REG_ACR14      = 0x64U,    /* The address of Alternate Configuration 14 Control Register */
    SAF_EQADC_ADC_REG_EACR14     = 0x67U,    /* The address of Extended Alternate Configuration 14 Control Register */
    SAF_EQADC_ADC_REG_PUDCR0     = 0x70U,    /* The address of Pull Up/Down Control Register 0 */
    SAF_EQADC_ADC_REG_PUDCR1     = 0x71U,    /* The address of Pull Up/Down Control Register 1 */
    SAF_EQADC_ADC_REG_PUDCR2     = 0x72U,    /* The address of Pull Up/Down Control Register 2 */
    SAF_EQADC_ADC_REG_PUDCR3     = 0x73U,    /* The address of Pull Up/Down Control Register 3 */
    SAF_EQADC_ADC_REG_PUDCR4     = 0x74U,    /* The address of Pull Up/Down Control Register 4 */
    SAF_EQADC_ADC_REG_PUDCR5     = 0x75U,    /* The address of Pull Up/Down Control Register 5 */
    SAF_EQADC_ADC_REG_PUDCR6     = 0x76U,    /* The address of Pull Up/Down Control Register 6 */
    SAF_EQADC_ADC_REG_PUDCR7     = 0x77U,    /* The address of Pull Up/Down Control Register 7 */
    SAF_EQADC_ADC_REG_PUDCR8     = 0x78U,    /* The address of Pull Up/Down Control Register 8 */
    SAF_EQADC_ADC_REG_PUDCR9     = 0x79U,    /* The address of Pull Up/Down Control Register 9 */
    SAF_EQADC_ADC_REG_PUDCR10    = 0x7AU,    /* The address of Pull Up/Down Control Register 10 */
    SAF_EQADC_ADC_REG_PUDCR11    = 0x7BU,    /* The address of Pull Up/Down Control Register 11 */
    SAF_EQADC_ADC_REG_PUDCR12    = 0x7CU,    /* The address of Pull Up/Down Control Register 12 */
    SAF_EQADC_ADC_REG_PUDCR13    = 0x7DU,    /* The address of Pull Up/Down Control Register 13 */
    SAF_EQADC_ADC_REG_PUDCR14    = 0x7EU,    /* The address of Pull Up/Down Control Register 14 */
    SAF_EQADC_ADC_REG_PUDCR15    = 0x7FU,    /* The address of Pull Up/Down Control Register 15 */
    SAF_EQADC_ADC_REG_PUDCR16    = 0x80U,    /* The address of Pull Up/Down Control Register 16 */
    SAF_EQADC_ADC_REG_PUDCR17    = 0x81U,    /* The address of Pull Up/Down Control Register 17 */
    SAF_EQADC_ADC_REG_PUDCR18    = 0x82U,    /* The address of Pull Up/Down Control Register 18 */
    SAF_EQADC_ADC_REG_PUDCR19    = 0x83U,    /* The address of Pull Up/Down Control Register 19 */
    SAF_EQADC_ADC_REG_PUDCR20    = 0x84U,    /* The address of Pull Up/Down Control Register 20 */
    SAF_EQADC_ADC_REG_PUDCR21    = 0x85U,    /* The address of Pull Up/Down Control Register 21 */
    SAF_EQADC_ADC_REG_PUDCR22    = 0x86U,    /* The address of Pull Up/Down Control Register 22 */
    SAF_EQADC_ADC_REG_PUDCR23    = 0x87U,    /* The address of Pull Up/Down Control Register 23 */
    SAF_EQADC_ADC_REG_PUDCR24    = 0x88U,    /* The address of Pull Up/Down Control Register 24 */
    SAF_EQADC_ADC_REG_PUDCR25    = 0x89U,    /* The address of Pull Up/Down Control Register 25 */
    SAF_EQADC_ADC_REG_PUDCR26    = 0x8AU,    /* The address of Pull Up/Down Control Register 26 */
    SAF_EQADC_ADC_REG_PUDCR27    = 0x8BU,    /* The address of Pull Up/Down Control Register 27 */
    SAF_EQADC_ADC_REG_PUDCR28    = 0x8CU,    /* The address of Pull Up/Down Control Register 28 */
    SAF_EQADC_ADC_REG_PUDCR29    = 0x8DU,    /* The address of Pull Up/Down Control Register 29 */
    SAF_EQADC_ADC_REG_PUDCR30    = 0x8EU,    /* The address of Pull Up/Down Control Register 30 */
    SAF_EQADC_ADC_REG_PUDCR31    = 0x8FU,    /* The address of Pull Up/Down Control Register 31 */
    SAF_EQADC_ADC_REG_PUDCR32    = 0x90U,    /* The address of Pull Up/Down Control Register 32 */
    SAF_EQADC_ADC_REG_PUDCR33    = 0x91U,    /* The address of Pull Up/Down Control Register 33 */
    SAF_EQADC_ADC_REG_PUDCR34    = 0x92U,    /* The address of Pull Up/Down Control Register 34 */
    SAF_EQADC_ADC_REG_PUDCR35    = 0x93U,    /* The address of Pull Up/Down Control Register 35 */
    SAF_EQADC_ADC_REG_PUDCR36    = 0x94U,    /* The address of Pull Up/Down Control Register 36 */
    SAF_EQADC_ADC_REG_PUDCR37    = 0x95U,    /* The address of Pull Up/Down Control Register 37 */
    SAF_EQADC_ADC_REG_PUDCR38    = 0x96U,    /* The address of Pull Up/Down Control Register 38 */
    SAF_EQADC_ADC_REG_PUDCR39    = 0x97U,    /* The address of Pull Up/Down Control Register 39 */
    SAF_EQADC_ADC_REG_STACTBR1   = 0xA0U,    /* The address of STAC Bus Time Base 1 Register */
    SAF_EQADC_ADC_REG_STACTBR2   = 0xA1U     /* The address of STAC Bus Time Base 1 Register */
} SafEqadc_OnChipAdcRegAddrType;  //  TODO

/*******************************************************************************
 * @brief SAF_EQADC Command FIFO Trigger Source.
 *
 * @param x: CFIFO number
 *******************************************************************************/
#define SAF_EQADC_TRIG_NULL_VAL                 ((uint8_t)(0U))
#define SAF_EQADC_TRIG_RTI_VAL                  ((uint8_t)(1U))
#define SAF_EQADC_TRIG_PIT0_CH0_VAL             ((uint8_t)(2U))
#define SAF_EQADC_TRIG_PIT0_CH1_VAL             ((uint8_t)(3U))
#define SAF_EQADC_TRIG_PIT1_CH0_VAL             ((uint8_t)(4U))
#define SAF_EQADC_TRIG_PIT1_CH1_VAL             ((uint8_t)(5U))
#define SAF_EQADC_TRIG_ETRIG0_VAL(x)            ((uint8_t)((((uint8_t)(x) % 2U) == 0U) ? 96U : 7U))
#define SAF_EQADC_TRIG_ETRIG1_VAL(x)            ((uint8_t)((((uint8_t)(x) % 2U) == 0U) ? 7U : 96U))
#define SAF_EQADC_TRIG_ETPUA28_VAL              ((uint8_t)(12U))
#define SAF_EQADC_TRIG_ETPUA29_VAL              ((uint8_t)(13U))
#define SAF_EQADC_TRIG_ETPUA30_VAL              ((uint8_t)(14U))
#define SAF_EQADC_TRIG_ETPUA31_VAL              ((uint8_t)(15U))
#define SAF_EQADC_TRIG_ETPUB28_VAL              ((uint8_t)(16U))
#define SAF_EQADC_TRIG_ETPUB29_VAL              ((uint8_t)(17U))
#define SAF_EQADC_TRIG_ETPUB30_VAL              ((uint8_t)(18U))
#define SAF_EQADC_TRIG_ETPUB31_VAL              ((uint8_t)(19U))
#define SAF_EQADC_TRIG_ETPUC28_VAL              ((uint8_t)(20U))
#define SAF_EQADC_TRIG_ETPUC29_VAL              ((uint8_t)(21U))
#define SAF_EQADC_TRIG_ETPUC30_VAL              ((uint8_t)(22U))
#define SAF_EQADC_TRIG_ETPUC31_VAL              ((uint8_t)(23U))
#define SAF_EQADC_TRIG_EMIOS0_CH16_VAL          ((uint8_t)(24U))
#define SAF_EQADC_TRIG_EMIOS0_CH17_VAL          ((uint8_t)(25U))
#define SAF_EQADC_TRIG_EMIOS0_CH18_VAL          ((uint8_t)(26U))
#define SAF_EQADC_TRIG_EMIOS0_CH19_VAL          ((uint8_t)(27U))
#define SAF_EQADC_TRIG_EMIOS0_CH20_VAL          ((uint8_t)(28U))
#define SAF_EQADC_TRIG_EMIOS0_CH21_VAL          ((uint8_t)(29U))
#define SAF_EQADC_TRIG_EMIOS0_CH22_VAL          ((uint8_t)(30U))
#define SAF_EQADC_TRIG_EMIOS0_CH23_VAL          ((uint8_t)(31U))
#define SAF_EQADC_TRIG_ETPUA7_VAL               ((uint8_t)(6U))     /* ETPU trigger CFIFO_1 only */
#define SAF_EQADC_TRIG_ETPUA14_VAL              ((uint8_t)(6U))     /* ETPU trigger CFIFO_2 only */
#define SAF_EQADC_TRIG_ETPUA22_VAL              ((uint8_t)(6U))     /* ETPU trigger CFIFO_3 only */
#define SAF_EQADC_TRIG_ETPUA26_VAL              ((uint8_t)(32U))    /* ETPU trigger CFIFO_5 only */
#define SAF_EQADC_TRIG_ETPUA27_VAL              ((uint8_t)(32U))    /* ETPU trigger CFIFO_4 only */
#define SAF_EQADC_TRIG_EMIOS1_CH2_VAL           ((uint8_t)(64U))    /* eMOIS trigger CFIFO_0 only */
#define SAF_EQADC_TRIG_EMIOS1_CH3_VAL           ((uint8_t)(64U))    /* eMOIS trigger CFIFO_1 only */
#define SAF_EQADC_TRIG_EMIOS1_CH4_VAL           ((uint8_t)(64U))    /* eMOIS trigger CFIFO_5 only */
#define SAF_EQADC_TRIG_EMIOS1_CH5_VAL           ((uint8_t)(64U))    /* eMOIS trigger CFIFO_4 only */
#define SAF_EQADC_TRIG_EMIOS1_CH6_VAL           ((uint8_t)(64U))    /* eMOIS trigger CFIFO_3 only */
#define SAF_EQADC_TRIG_EMIOS1_CH7_VAL           ((uint8_t)(64U))    /* eMOIS trigger CFIFO_2 only */

typedef enum
{
    SAF_EQADC_HW_TRIG_NOT_CONNECTED = 0U,
    SAF_EQADC_HW_TRIG_RTI           = 1U,
    SAF_EQADC_HW_TRIG_PIT0_CH0      = 2U,
    SAF_EQADC_HW_TRIG_PIT0_CH1      = 3U,
    SAF_EQADC_HW_TRIG_PIT1_CH0      = 4U,
    SAF_EQADC_HW_TRIG_PIT1_CH1      = 5U,
    SAF_EQADC_HW_TRIG_ETRIG0        = 6U,
    SAF_EQADC_HW_TRIG_ETRIG1        = 7U,
    SAF_EQADC_HW_TRIG_ETPUA28       = 8U,
    SAF_EQADC_HW_TRIG_ETPUA29       = 9U,
    SAF_EQADC_HW_TRIG_ETPUA30       = 10U,
    SAF_EQADC_HW_TRIG_ETPUA31       = 11U,
    SAF_EQADC_HW_TRIG_ETPUB28       = 12U,
    SAF_EQADC_HW_TRIG_ETPUB29       = 13U,
    SAF_EQADC_HW_TRIG_ETPUB30       = 14U,
    SAF_EQADC_HW_TRIG_ETPUB31       = 15U,
    SAF_EQADC_HW_TRIG_ETPUC28       = 16U,
    SAF_EQADC_HW_TRIG_ETPUC29       = 17U,
    SAF_EQADC_HW_TRIG_ETPUC30       = 18U,
    SAF_EQADC_HW_TRIG_ETPUC31       = 19U,
    SAF_EQADC_HW_TRIG_EMIOS0_CH16   = 20U,
    SAF_EQADC_HW_TRIG_EMIOS0_CH17   = 21U,
    SAF_EQADC_HW_TRIG_EMIOS0_CH18   = 22U,
    SAF_EQADC_HW_TRIG_EMIOS0_CH19   = 23U,
    SAF_EQADC_HW_TRIG_EMIOS0_CH20   = 24U,
    SAF_EQADC_HW_TRIG_EMIOS0_CH21   = 25U,
    SAF_EQADC_HW_TRIG_EMIOS0_CH22   = 26U,
    SAF_EQADC_HW_TRIG_EMIOS0_CH23   = 27U,
    SAF_EQADC_HW_TRIG_ETPUA7        = 28U,  /* ETPU trigger CFIFO_1 only */
    SAF_EQADC_HW_TRIG_ETPUA14       = 29U,  /* ETPU trigger CFIFO_2 only */
    SAF_EQADC_HW_TRIG_ETPUA22       = 30U,  /* ETPU trigger CFIFO_3 only */
    SAF_EQADC_HW_TRIG_ETPUA26       = 31U,  /* ETPU trigger CFIFO_5 only */
    SAF_EQADC_HW_TRIG_ETPUA27       = 32U,  /* ETPU trigger CFIFO_4 only */
    SAF_EQADC_HW_TRIG_EMIOS1_CH2    = 33U,  /* eMOIS trigger CFIFO_0 only */
    SAF_EQADC_HW_TRIG_EMIOS1_CH3    = 34U,  /* eMOIS trigger CFIFO_1 only */
    SAF_EQADC_HW_TRIG_EMIOS1_CH4    = 35U,  /* eMOIS trigger CFIFO_5 only */
    SAF_EQADC_HW_TRIG_EMIOS1_CH5    = 36U,  /* eMOIS trigger CFIFO_4 only */
    SAF_EQADC_HW_TRIG_EMIOS1_CH6    = 37U,  /* eMOIS trigger CFIFO_3 only */
    SAF_EQADC_HW_TRIG_EMIOS1_CH7    = 38U   /* eMOIS trigger CFIFO_2 only */
} SafEqadc_HwTrigSourceSelType;

/*******************************************************************************
 * @brief SAF_EQADC CFIFO0 Advance Trigger Source.
 *******************************************************************************/
#define SAF_EQADC_ATRIG_NULL_VALUE                  ((uint8_t)(0U))
#define SAF_EQADC_ATRIG_RTI_VALUE                   ((uint8_t)(1U))
#define SAF_EQADC_ATRIG_PIT0_CH0_VALUE              ((uint8_t)(2U))
#define SAF_EQADC_ATRIG_PIT0_CH1_VALUE              ((uint8_t)(3U))
#define SAF_EQADC_ATRIG_PIT1_CH0_VALUE              ((uint8_t)(4U))
#define SAF_EQADC_ATRIG_PIT1_CH1_VALUE              ((uint8_t)(5U))
#define SAF_EQADC_ATRIG_ETPUA30_PIT0_CH0_VAL        ((uint8_t)(8U))
#define SAF_EQADC_ATRIG_ETPUA30_PIT0_CH1_VAL        ((uint8_t)(9U))
#define SAF_EQADC_ATRIG_ETPUA28_VAL                 ((uint8_t)(12U))
#define SAF_EQADC_ATRIG_ETPUA29_VAL                 ((uint8_t)(13U))
#define SAF_EQADC_ATRIG_ETPUA30_VAL                 ((uint8_t)(14U))
#define SAF_EQADC_ATRIG_ETPUA31_VAL                 ((uint8_t)(15U))
#define SAF_EQADC_ATRIG_ETPUC28_VAL                 ((uint8_t)(16U))
#define SAF_EQADC_ATRIG_ETPUC29_VAL                 ((uint8_t)(17U))
#define SAF_EQADC_ATRIG_ETPUC30_VAL                 ((uint8_t)(18U))
#define SAF_EQADC_ATRIG_ETPUC31_VAL                 ((uint8_t)(19U))
#define SAF_EQADC_ATRIG_EMIOS1CH2_PIT1CH0_VAL       ((uint8_t)(20U))
#define SAF_EQADC_ATRIG_EMIOS1CH2_PIT1CH1_VAL       ((uint8_t)(21U))
#define SAF_EQADC_ATRIG_EMIOS0_CH23_VAL             ((uint8_t)(31U))

typedef enum
{
    SAF_EQADC_ADVANCE_TRIG_NOT          = 0U,
    SAF_EQADC_ATRIG_RTI                 = 1U,
    SAF_EQADC_ATRIG_PIT0_CH0            = 2U,
    SAF_EQADC_ATRIG_PIT0_CH1            = 3U,
    SAF_EQADC_ATRIG_PIT1_CH0            = 4U,
    SAF_EQADC_ATRIG_PIT1_CH1            = 5U,
    SAF_EQADC_ATRIG_ETPUA30_PIT0_CH0    = 6U,
    SAF_EQADC_ATRIG_ETPUA30_PIT0_CH1    = 7U,
    SAF_EQADC_ATRIG_ETPUA28             = 8U,
    SAF_EQADC_ATRIG_ETPUA29             = 9U,
    SAF_EQADC_ATRIG_ETPUA30             = 10U,
    SAF_EQADC_ATRIG_ETPUA31             = 11U,
    SAF_EQADC_ATRIG_ETPUC28             = 12U,
    SAF_EQADC_ATRIG_ETPUC29             = 13U,
    SAF_EQADC_ATRIG_ETPUC30             = 14U,
    SAF_EQADC_ATRIG_ETPUC31             = 15U,
    SAF_EQADC_ATRIG_EMIOS1_CH2_PIT1_CH0 = 16U,
    SAF_EQADC_ATRIG_EMIOS1_CH2_PIT1_CH1 = 17U,
    SAF_EQADC_ATRIG_EMIOS0_CH23         = 18U
} SafEqadc_AdvanceTrigSourceSelType;

/*******************************************************************************
 * @brief Structure for on-chip ADC.
 *
 * @note on-chip ADC0/ADC1
 *******************************************************************************/
typedef struct
{
    /* Index of the on-chip ADC to be configured. */
    SafEqadcAdcIdxType AdcIdx;

    /* External Multiplexer enable/disable for ADC0/1. */
    boolean AdcExtMuxEn;

    /* Time base Selection for ADC0/1 */
    SafEqadc_TimeBaseSelType TimeBaseSel;

    /* Clock Selector for ADC0/1 */
    SafEqadc_ClkSelType ClkSel;

    /* Clock Prescaler Field for ADC0/1 */
    SafEqadc_ClkPrescaleType ClkPrescale;

    /* It is a unsigned 15-bit fixed pointed value.
     * The gain calibration constant is an unsigned fixed point number expressed
     *  in the GCC_INT.GCC_FRAC binary format. */
    uint16_t AdcGainCalibConst;

    /* OCC0/1 contains the offset calibration constant used to fine-tune ADC0/1 conversion results.
     * Negative values should be expressed using the two's complement representation. */
    int16_t AdcOffsetCalibConst;

    boolean ImmediateConvCmdEn;
} SafEqadc_AdcConfigType;

/*******************************************************************************
 * @brief Structure for CFIFO (Command FIFO).
 *
 * @note
 *******************************************************************************/
typedef struct
{
    SafEqadcFifoIdxType CfifoIdx;
    SafEqadc_CfifoModeType CfifoMode;
    SafEqadc_IntDmaFillSelType IntDmaFillSel;
    uint8_t DmaMappedChan;
    boolean DmaChanDisReqLoop;
    uint32_t * SourcePtr;
    uint32_t SourceLen;
    SafeDMACallbackType Callback;
    void * CallbackParam;
    SafEqadc_HwTrigSourceSelType HwTrigSel;  /* SIUL2_ISEL4~7 */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
    boolean CfifoTrigDelayEn;   /* CFIFO Trigger Delay enable */
    uint32_t CfifoTrigDelayVal; /* CFIFO Trigger Delay configuration value */
#endif

    /* CFIFO0 only */
    boolean Cfifo0EntryExtensionEn;
    SafEqadc_Cfifo0AModeType Cfifo0AdvanceMode;
    SafEqadc_AdvanceTrigSourceSelType Cfifo0AdvanceTrigSel;    /* SIUL2_ISEL9 */
} SafEqadc_CfifoConfigType;

typedef struct
{
    SafEqadcFifoIdxType RfifoIdx;
    uint8_t ResultDmaMappedChan;
    uint16_t * DestPtr;
    uint32_t DestLen;
    SafeDMACallbackType Callback;
    void * CallbackParam;
    boolean EnHalfDestCallback;
} SafEqadc_ResultDmaConfigType;

typedef struct
{
    SafEqadc_AltConfigSelType AltConfigSel;
    boolean ResultTransInhibit;
    SafEqadc_AltConfigDestType AltConvResultDEST;
    boolean FMTA_SignEn;
    SafEqadc_ResolutionSelType AdcResSel;
    SafEqadc_PreGainType AdcPreGain;
    /* Alternate Configuration 1: Alternate Gain 1(ADC0 and ADC1) + Alternate Offset 1(ADC0 and ADC1),
     * Alternate Configuration 2: Alternate Gain 2(ADC0 and ADC1) + Alternate Offset 2(ADC0 and ADC1) */
    uint16_t AdcAltGain[SAF_EQADC_ADC_NUM];
    uint16_t AdcAltOffset[SAF_EQADC_ADC_NUM];
} SafEqadc_AlternateConfigType;

#ifdef SAF_EQADC_ADC_PUDCR_EN
typedef struct
{
    uint8_t AdcChIdx;
    SafEqadc_ChanPullType ChanPull;
    SafEqadc_PullStrengthType PullStrength;
} SafEqadc_PullUpDownCfgType;
#endif  /* SAF_EQADC_ADC_PUDCR_EN */

typedef struct
{
    uint8_t clientIdx;
    SafEqadc_RedLineBitsSelType TimeBaseBitsSel;
    SafEqadc_RedLineServerDataSlotSelType SRVnSel;
} SafEqadc_RedLineClientConfigType;

typedef struct
{
    SafEqadcInstanceType SafEqadc_HwInstId;

    /* Debug mode entry request (SAF_EQADC_MCR DBG) */
    boolean DebugModeEn;

    /* External Trigger Digital Filter Length (SAF_EQADC_ETDFR DFL) */
    uint8_t ExtTrigDigitalFilterLen;

    SafEqadc_TimeBaseCountClkPresType TimeBasePresDiv;
} SafEqadcHwInstanceType;

typedef struct
{
    SafEqadcHwInstanceType *SafEqadcHwInst;
    uint8_t AdcConfigNum;
    SafEqadc_AdcConfigType * AdcConfigArray;
    uint8_t CfifoConfigNum;
    SafEqadc_CfifoConfigType * CfifoConfigArray;
    uint8_t ResultDmaConfigNum;
    SafEqadc_ResultDmaConfigType * ResultDmaConfigArray;
    uint8_t AlternateConfigNum;
    SafEqadc_AlternateConfigType * AlternateConfigArray;
#ifdef SAF_EQADC_ADC_PUDCR_EN
    uint8_t PullUpDownCfgNum;
    SafEqadc_PullUpDownCfgType * PullUpDownCfgArray;
#endif  /* SAF_EQADC_ADC_PUDCR_EN */
    uint8_t RedLineClientConfigNum;
    SafEqadc_RedLineClientConfigType * RedLineClientConfigArray;
} Adc_SafEqadcConfigType;

typedef struct
{
    boolean Eoq;
    boolean Pause;
    boolean RepeatStart;
    uint8_t cBufNum;
    boolean CalibConvResEn;
    SafEqadc_RfifoMsgTagType RfifoMsgTag;
    SafEqadc_LongSampTimeType LongSampTime;
    boolean TimeStampReq;
    boolean FormatSignEn;
    uint8_t ChanNum;
    SafEqadc_AltConfigSelType AltConfigSel;
    boolean FlushOrFMT;
} SafEqadc_ConvCmdType;

typedef struct
{
    boolean Eoq;
    boolean Pause;
    boolean RepeatStart;
    uint8_t cBufNum;
    SafEqadc_RwConfigCmdType RwCfgCmdType;
    uint16_t AdcRegValue;
    SafEqadc_OnChipAdcRegAddrType AdcRegAddr;
    SafEqadc_RfifoMsgTagType RfifoMsgTag;
} SafEqadc_ConfigCmdType;

typedef enum
{
    SAF_EQADC_CAL_STANDARD_CONFIG   = SAF_EQADC_ALT_CONFIG_DISABLE, /* ADCx_GCCR, ADCx_OCCR */
    SAF_EQADC_CAL_ALT_CONFIG_1      = SAF_EQADC_ALT_CONFIG_SEL_1,   /* ADCx_AGR1, ADCx_AOR1 */
    SAF_EQADC_CAL_ALT_CONFIG_2      = SAF_EQADC_ALT_CONFIG_SEL_2    /* ADCx_AGR2, ADCx_AOR2 */
} SafEqadc_CalibCfgSelType;

typedef struct
{
    SafEqadc_CalibCfgSelType CalibCfgSel;
    SafEqadcFifoIdxType CfifoIdx;
    SafEqadcFifoIdxType RfifoIdx;
    SafEqadc_LongSampTimeType LongSampTime;
    uint32_t TimeoutCal;
    uint16_t GainCalibConst;
    int16_t OffsetCalibConst;
} SafEqadc_CalibConfigInfoType;

/* Internal Channel Function Enable */
#define SAF_SSCM_VRC33_ENABLE           (*(vuint32_t *)(0xFFFF8038UL))
#define SAF_EQADC_PCT_VREF_EN_MSAK      (0x00000004U)
#define SAF_EQADC_TSENS_EN_MSAK         (0x00000008U)

/* eTRIG pin */
#define ETRIG0_PAD                  (PA0)
#define ETRIG1_PAD                  (PF2)

/* Multiplexed address signals(MA) pin */
#define MA0_PAD                     (PN4)
#define MA0_PAD_SSS                 (PAD_SSS_13)
#define MA1_PAD                     (PH6)
#define MA1_PAD_SSS                 (PAD_SSS_13)
#define MA2_PAD                     (PM6)
#define MA2_PAD_SSS                 (PAD_SSS_12)

/* Single ended Channel */
#define SAF_EQADC_CH(x)                 (x) /* Channel x:   Single ended conversion */
/* Differential Channel */
#define SAF_EQADC_DAN_CH128             (128U)  /* Channel 128: Differential conversion */
#define SAF_EQADC_DAN_CH129             (129U)  /* Channel 129: Differential conversion */
#define SAF_EQADC_DAN_CH130             (130U)  /* Channel 130: Differential conversion */
#define SAF_EQADC_DAN_CH131             (131U)  /* Channel 131: Differential conversion */
#define SAF_EQADC_DAN_CH132             (132U)  /* Channel 132: Differential conversion */
#define SAF_EQADC_DAN_CH133             (133U)  /* Channel 133: Differential conversion */
#define SAF_EQADC_DAN_CH134             (134U)  /* Channel 134: Differential conversion */
#define SAF_EQADC_DAN_CH135             (135U)  /* Channel 135: Differential conversion */
#define SAF_EQADC_DAN_CH136             (136U)  /* Channel 136: Differential conversion */
#define SAF_EQADC_DAN_CH137             (137U)  /* Channel 137: Differential conversion */
#define SAF_EQADC_DAN_CH138             (138U)  /* Channel 138: Differential conversion */
#define SAF_EQADC_DAN_CH139             (139U)  /* Channel 139: Differential conversion */
#define SAF_EQADC_DAN_CH140             (140U)  /* Channel 140: Differential conversion */
#define SAF_EQADC_DAN_CH141             (141U)  /* Channel 141: Differential conversion */
#define SAF_EQADC_DAN_CH142             (142U)  /* Channel 142: Differential conversion */
#define SAF_EQADC_DAN_CH143             (143U)  /* Channel 143: Differential conversion */
#define SAF_EQADC_DAN_CH144             (144U)  /* Channel 144: Differential conversion */
#define SAF_EQADC_DAN_CH145             (145U)  /* Channel 145: Differential conversion */
#define SAF_EQADC_DAN_CH146             (146U)  /* Channel 146: Differential conversion */
#define SAF_EQADC_DAN_CH147             (147U)  /* Channel 147: Differential conversion */
#define SAF_EQADC_DAN_CH148             (148U)  /* Channel 148: Differential conversion */
#define SAF_EQADC_DAN_CH149             (149U)  /* Channel 149: Differential conversion */
#define SAF_EQADC_DAN_CH150             (150U)  /* Channel 150: Differential conversion */
#define SAF_EQADC_DAN_CH151             (151U)  /* Channel 151: Differential conversion */
#define SAF_EQADC_DAN_CH152             (152U)  /* Channel 152: Differential conversion */
#define SAF_EQADC_DAN_CH153             (153U)  /* Channel 153: Differential conversion */
#define SAF_EQADC_DAN_CH154             (154U)  /* Channel 154: Differential conversion */
#define SAF_EQADC_DAN_CH155             (155U)  /* Channel 155: Differential conversion */
#define SAF_EQADC_DAN_CH156             (156U)  /* Channel 156: Differential conversion */
#define SAF_EQADC_DAN_CH157             (157U)  /* Channel 157: Differential conversion */
#define SAF_EQADC_DAN_CH160             (160U)  /* Channel 160: Differential conversion */
#define SAF_EQADC_DAN_CH161             (161U)  /* Channel 161: Differential conversion */
#define SAF_EQADC_DAN_CH162             (162U)  /* Channel 162: Differential conversion */
#define SAF_EQADC_DAN_CH163             (163U)  /* Channel 163: Differential conversion */
#define SAF_EQADC_DAN_CH164             (164U)  /* Channel 164: Differential conversion */
#define SAF_EQADC_DAN_CH165             (165U)  /* Channel 165: Differential conversion */

#if (defined(CCFC3007PT) || defined(CCFC3008PT))
/* Internal Channel (Only EQADC4_ADC1(ADC9) has.) */
#define SAF_EQADC_CH_VDD_REG2_PMU       (62U)   /* Channel: VDD_REG_2_PMU (1V)      */
#define SAF_EQADC_CH_VDD_REG_PMU        (63U)   /* Channel: VDD_REG_PMU   (1V)      */
#define SAF_EQADC_CH_VDD_HV_PMC         (88U)   /* Channel: VDD_HV_PMC  (3.3V/5V)   */
#define SAF_EQADC_CH_VDD_HV_OSC         (89U)   /* Channel: VDD_HV_OSC  (3.3V/5V)   */
#define SAF_EQADC_CH_VDD_HV_FLA         (90U)   /* Channel: VDD_HV_FLA  (3.3V)      */
#define SAF_EQADC_CH_VDD_HV_IO_FLEX     (91U)   /* Channel: VDD_HV_IO_FLEX(3.3V/5V) */
#define SAF_EQADC_CH_VDD_HV_IO_5V       (92U)   /* Channel: VDD_HV_IO_5V  (5V)      */
#define SAF_EQADC_CH_VDD_HV_IO_MAIN     (93U)   /* Channel: VDD_HV_IO_MAIN(3.3V/5V) */
#define SAF_EQADC_CH_VDD_LV             (95U)   /* Channel: VDD_LV      (1.2V)      */
#define SAF_EQADC_CH_TEMP_SENSOR        (120U)  /* Channel: Temperature Sensor      */
#define SAF_EQADC_CH_VDD_PCT75_VREF     (122U)  /* Channel: 75% VREF                */
#define SAF_EQADC_CH_VDD_PCT50_VREF     (123U)  /* Channel: 50% VREF                */
#define SAF_EQADC_CH_VDD_PCT25_VREF     (124U)  /* Channel: 25% VREF                */
#elif defined(CCFC3007BC)
/* Internal Channel (EQADC0_ADC0/EQADC0_ADC1(ADC0/1) has.) */
#define SAF_EQADC_CH_VDD_REG_PMU        (254U)  /* Channel: VDD_REG_PMU (1V)        */
#define SAF_EQADC_CH_VDD_HV_PMC         (248U)  /* Channel: VDD_HV_PMC  (3.3V/5V)   */
#define SAF_EQADC_CH_VDD_HV_OSC         (249U)  /* Channel: VDD_HV_OSC  (3.3V/5V)   */
#define SAF_EQADC_CH_VDD_HV_FLA         (250U)  /* Channel: VDD_HV_FLA  (3.3V)      */
#define SAF_EQADC_CH_VDD_HV_IO_FLEX     (251U)  /* Channel: VDD_HV_IO_FLEX(3.3V/5V) */
#define SAF_EQADC_CH_VDD_HV_IO_5V       (252U)  /* Channel: VDD_HV_IO_5V  (5V)      */
#define SAF_EQADC_CH_VDD_HV_IO_MAIN     (253U)  /* Channel: VDD_HV_IO_MAIN(3.3V/5V) */
#define SAF_EQADC_CH_VDD_LV             (255U)  /* Channel: VDD_LV      (1.2V)      */
#define SAF_EQADC_CH_TEMP_SENSOR        (247U)  /* Channel: Temperature Sensor      */
#define SAF_EQADC_CH_VDD_PCT75_VREF     (246U)  /* Channel: 75% VREF                */
#define SAF_EQADC_CH_VDD_PCT50_VREF     (245U)  /* Channel: 50% VREF                */
#define SAF_EQADC_CH_VDD_PCT25_VREF     (244U)  /* Channel: 25% VREF                */
#elif defined(CCFC3008PC)
/* Internal Channel (EQADC1_ADC0(ADC2) has.) */
/* The PMU module is replaced on the CCFC3008PC */
#define SAF_EQADC_CH_VDD_HV_OSC         (108U)  /* Channel: VDD_HV_OSC  (3.3V/5V)   */
#define SAF_EQADC_CH_VDD_HV_FLA         (92U)   /* Channel: VDD_HV_FLA  (3.3V)      */
#define SAF_EQADC_CH_VDD_HV_IO_MAIN     (44U)   /* Channel: VDD_HV_IO_MAIN(3.3V/5V) */
#define SAF_EQADC_CH_VDD_LV             (60U)   /* Channel: VDD_LV      (1.2V)      */
#define SAF_EQADC_CH_VDD_LV_ALWAYS_ON   (28U)   /* Channel: VDD_LV      (1.2V)      */
#define SAF_EQADC_CH_TEMP_SENSOR        (11U)   /* Channel: Temperature Sensor      */
#define SAF_EQADC_CH_VDD_PCT75_VREF     (248U)  /* Channel: 75% VREF                */
#define SAF_EQADC_CH_VDD_PCT50_VREF     (240U)  /* Channel: 50% VREF                */
#define SAF_EQADC_CH_VDD_PCT25_VREF     (232U)  /* Channel: 25% VREF                */
#elif defined(CCFC3008PCSN)
/* Internal Channel (EQADC0_ADC1(ADC1) has.) */
#define SAF_EQADC_CH_VDD_HV_STBY        (127U)  /* Channel: VDD_HV_STBY (3.3V/5V)   */
#define SAF_EQADC_CH_VDD_HV_FLA         (111U)  /* Channel: VDD_HV_FLA  (3.3V)      */
#define SAF_EQADC_CH_VDD_HV_PMC         (95U)   /* Channel: VDD_HV_PMC  (3.3V/5V)   */
#define SAF_EQADC_CH_VDD_HV_IO_MAIN     (79U)   /* Channel: VDD_HV_IO_MAIN(3.3V/5V) */
#define SAF_EQADC_CH_VDD_LV             (63U)   /* Channel: VDD_LV      (1.2V)      */
#define SAF_EQADC_CH_TEMP_SENSOR        (7U)    /* Channel: Temperature Sensor      */
#define SAF_EQADC_CH_VDD_PCT75_VREF     (15U)   /* Channel: 75% VREF                */
#define SAF_EQADC_CH_VDD_PCT50_VREF     (31U)   /* Channel: 50% VREF                */
#define SAF_EQADC_CH_VDD_PCT25_VREF     (47U)   /* Channel: 25% VREF                */
#elif (defined(CCFC3010PT) || defined(CCFC3011PT) || defined(CCFC3012PT))
/* Internal Channel (EQADC6_ADC0(ADC12) has.) */
#define SAF_EQADC_CH_VDD_HV_PMC         (88U)   /* Channel: VDD_HV_PMC  (3.3V/5V)   */
#define SAF_EQADC_CH_VDD_HV_OSC         (89U)   /* Channel: VDD_HV_OSC  (3.3V/5V)   */
#define SAF_EQADC_CH_VDD_HV_FLA         (90U)   /* Channel: VDD_HV_FLA  (3.3V)      */
#define SAF_EQADC_CH_VDD_HV_IO_FLEX     (91U)   /* Channel: VDD_HV_IO_FLEX(3.3V/5V) */
#define SAF_EQADC_CH_VDD_HV_IO_MAIN     (93U)   /* Channel: VDD_HV_IO_MAIN(3.3V/5V) */
#define SAF_EQADC_CH_VDD_LV             (95U)   /* Channel: VDD_LV      (1.2V)      */
#define SAF_EQADC_CH_TEMP_SENSOR        (120U)  /* Channel: Temperature Sensor      */
#define SAF_EQADC_CH_VDD_PCT75_VREF     (122U)  /* Channel: 75% VREF                */
#define SAF_EQADC_CH_VDD_PCT50_VREF     (123U)  /* Channel: 50% VREF                */
#define SAF_EQADC_CH_VDD_PCT25_VREF     (124U)  /* Channel: 25% VREF                */
#define SAF_EQADC_CH_VDD_HV_ADV_D       (240U)  /* Channel: SDADC                   */
#define SAF_EQADC_CH_VDD_HV_ADV_DAC     (110U)  /* Channel: DAC                     */
#define SAF_EQADC_CH_VDD_HV_ADV_A       (94U)   /* Channel: ACMP                    */
#define SAF_EQADC_CH_VDD_HV_IO_4NXS     (92U)   /* Channel: -                       */
#else
    #error "No valid CPU defined!"
#endif

/* External Multiplexing Channel */
#if (defined(CCFC3007PT) | defined(CCFC3008PT))
/* Only EQADC4_ADC1(ADC9) has. */
#define SAF_EQADC_EXT0_CH192            (192U)  /* Channel 192: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH193            (193U)  /* Channel 193: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH194            (194U)  /* Channel 194: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH195            (195U)  /* Channel 195: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH196            (196U)  /* Channel 196: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH197            (197U)  /* Channel 197: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH198            (198U)  /* Channel 198: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH199            (199U)  /* Channel 199: External multiplexing 0 */
#define SAF_EQADC_EXT1_CH200            (200U)  /* Channel 200: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH201            (201U)  /* Channel 201: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH202            (202U)  /* Channel 202: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH203            (203U)  /* Channel 203: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH204            (204U)  /* Channel 204: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH205            (205U)  /* Channel 205: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH206            (206U)  /* Channel 206: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH207            (207U)  /* Channel 207: External multiplexing 1 */
#define SAF_EQADC_EXT2_CH208            (208U)  /* Channel 208: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH209            (209U)  /* Channel 209: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH210            (210U)  /* Channel 210: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH211            (211U)  /* Channel 211: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH212            (212U)  /* Channel 212: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH213            (213U)  /* Channel 213: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH214            (214U)  /* Channel 214: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH215            (215U)  /* Channel 215: External multiplexing 2 */
#define SAF_EQADC_EXT3_CH216            (216U)  /* Channel 216: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH217            (217U)  /* Channel 217: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH218            (218U)  /* Channel 218: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH219            (219U)  /* Channel 219: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH220            (220U)  /* Channel 220: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH221            (221U)  /* Channel 221: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH222            (222U)  /* Channel 222: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH223            (223U)  /* Channel 223: External multiplexing 3 */
#elif defined(CCFC3007BC)
/* Of the two ADCs in instance, only one can enable EMUX at a time. */
#define SAF_EQADC_EXT_CH0               (0U)    /* Channel 0  : External multiplexing   */
#define SAF_EQADC_EXT_CH8               (8U)    /* Channel 8  : External multiplexing   */
#define SAF_EQADC_EXT_CH16              (16U)   /* Channel 16 : External multiplexing   */
#define SAF_EQADC_EXT_CH24              (24U)   /* Channel 24 : External multiplexing   */
#define SAF_EQADC_EXT_CH32              (32U)   /* Channel 32 : External multiplexing   */
#define SAF_EQADC_EXT_CH40              (40U)   /* Channel 40 : External multiplexing   */
#define SAF_EQADC_EXT_CH48              (48U)   /* Channel 48 : External multiplexing   */
#define SAF_EQADC_EXT_CH56              (56U)   /* Channel 56 : External multiplexing   */
#define SAF_EQADC_EXT_CH64              (64U)   /* Channel 64 : External multiplexing   */
#define SAF_EQADC_EXT_CH72              (72U)   /* Channel 72 : External multiplexing   */
#define SAF_EQADC_EXT_CH80              (80U)   /* Channel 80 : External multiplexing   */
#define SAF_EQADC_EXT_CH88              (88U)   /* Channel 88 : External multiplexing   */
#define SAF_EQADC_EXT_CH96              (96U)   /* Channel 96 : External multiplexing   */
#define SAF_EQADC_EXT_CH104             (104U)  /* Channel 104: External multiplexing   */
#define SAF_EQADC_EXT_CH112             (112U)  /* Channel 112: External multiplexing   */
#define SAF_EQADC_EXT_CH120             (120U)  /* Channel 120: External multiplexing   */
#define SAF_EQADC_EXT_CH240             (240U)  /* Channel 240: External multiplexing   */
#define SAF_EQADC_EXT_CH241             (241U)  /* Channel 241: External multiplexing   */
#define SAF_EQADC_EXT_CH242             (242U)  /* Channel 242: External multiplexing   */
#define SAF_EQADC_EXT_CH243             (243U)  /* Channel 243: External multiplexing   */
#define SAF_EQADC_EXT0_CH192            (192U)  /* Channel 192: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH193            (193U)  /* Channel 193: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH194            (194U)  /* Channel 194: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH195            (195U)  /* Channel 195: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH196            (196U)  /* Channel 196: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH197            (197U)  /* Channel 197: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH198            (198U)  /* Channel 198: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH199            (199U)  /* Channel 199: External multiplexing 0 */
#define SAF_EQADC_EXT1_CH200            (200U)  /* Channel 200: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH201            (201U)  /* Channel 201: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH202            (202U)  /* Channel 202: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH203            (203U)  /* Channel 203: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH204            (204U)  /* Channel 204: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH205            (205U)  /* Channel 205: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH206            (206U)  /* Channel 206: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH207            (207U)  /* Channel 207: External multiplexing 1 */
#define SAF_EQADC_EXT2_CH208            (208U)  /* Channel 208: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH209            (209U)  /* Channel 209: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH210            (210U)  /* Channel 210: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH211            (211U)  /* Channel 211: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH212            (212U)  /* Channel 212: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH213            (213U)  /* Channel 213: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH214            (214U)  /* Channel 214: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH215            (215U)  /* Channel 215: External multiplexing 2 */
#define SAF_EQADC_EXT3_CH216            (216U)  /* Channel 216: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH217            (217U)  /* Channel 217: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH218            (218U)  /* Channel 218: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH219            (219U)  /* Channel 219: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH220            (220U)  /* Channel 220: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH221            (221U)  /* Channel 221: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH222            (222U)  /* Channel 222: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH223            (223U)  /* Channel 223: External multiplexing 3 */
#define SAF_EQADC_EXT4_CH224            (224U)  /* Channel 224: External multiplexing 4 */
#define SAF_EQADC_EXT4_CH225            (225U)  /* Channel 225: External multiplexing 4 */
#define SAF_EQADC_EXT4_CH226            (226U)  /* Channel 226: External multiplexing 4 */
#define SAF_EQADC_EXT4_CH227            (227U)  /* Channel 227: External multiplexing 4 */
#define SAF_EQADC_EXT4_CH228            (228U)  /* Channel 228: External multiplexing 4 */
#define SAF_EQADC_EXT4_CH229            (229U)  /* Channel 229: External multiplexing 4 */
#define SAF_EQADC_EXT4_CH230            (230U)  /* Channel 230: External multiplexing 4 */
#define SAF_EQADC_EXT4_CH231            (231U)  /* Channel 231: External multiplexing 4 */
#define SAF_EQADC_EXT5_CH232            (232U)  /* Channel 232: External multiplexing 5 */
#define SAF_EQADC_EXT5_CH233            (233U)  /* Channel 233: External multiplexing 5 */
#define SAF_EQADC_EXT5_CH234            (234U)  /* Channel 234: External multiplexing 5 */
#define SAF_EQADC_EXT5_CH235            (235U)  /* Channel 235: External multiplexing 5 */
#define SAF_EQADC_EXT5_CH236            (236U)  /* Channel 236: External multiplexing 5 */
#define SAF_EQADC_EXT5_CH237            (237U)  /* Channel 237: External multiplexing 5 */
#define SAF_EQADC_EXT5_CH238            (238U)  /* Channel 238: External multiplexing 5 */
#define SAF_EQADC_EXT5_CH239            (239U)  /* Channel 239: External multiplexing 5 */
#elif defined(CCFC3008PC)
/* Of the two ADCs in instance, only one can enable EMUX at a time. */
#define SAF_EQADC_EXT_CH12              (12U)   /* Channel 12:  External multiplexing   */
#define SAF_EQADC_EXT_CH76              (76U)   /* Channel 76:  External multiplexing   */
#define SAF_EQADC_EXT_CH124             (124U)  /* Channel 124: External multiplexing   */
#define SAF_EQADC_EXT0_CH192            (192U)  /* Channel 192: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH193            (193U)  /* Channel 193: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH194            (194U)  /* Channel 194: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH195            (195U)  /* Channel 195: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH196            (196U)  /* Channel 196: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH197            (197U)  /* Channel 197: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH198            (198U)  /* Channel 198: External multiplexing 0 */
#define SAF_EQADC_EXT0_CH199            (199U)  /* Channel 199: External multiplexing 0 */
#define SAF_EQADC_EXT1_CH200            (200U)  /* Channel 200: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH201            (201U)  /* Channel 201: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH202            (202U)  /* Channel 202: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH203            (203U)  /* Channel 203: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH204            (204U)  /* Channel 204: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH205            (205U)  /* Channel 205: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH206            (206U)  /* Channel 206: External multiplexing 1 */
#define SAF_EQADC_EXT1_CH207            (207U)  /* Channel 207: External multiplexing 1 */
#define SAF_EQADC_EXT2_CH208            (208U)  /* Channel 208: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH209            (209U)  /* Channel 209: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH210            (210U)  /* Channel 210: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH211            (211U)  /* Channel 211: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH212            (212U)  /* Channel 212: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH213            (213U)  /* Channel 213: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH214            (214U)  /* Channel 214: External multiplexing 2 */
#define SAF_EQADC_EXT2_CH215            (215U)  /* Channel 215: External multiplexing 2 */
#define SAF_EQADC_EXT3_CH216            (216U)  /* Channel 216: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH217            (217U)  /* Channel 217: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH218            (218U)  /* Channel 218: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH219            (219U)  /* Channel 219: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH220            (220U)  /* Channel 220: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH221            (221U)  /* Channel 221: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH222            (222U)  /* Channel 222: External multiplexing 3 */
#define SAF_EQADC_EXT3_CH223            (223U)  /* Channel 223: External multiplexing 3 */
#define SAF_EQADC_EXT4_CH224            (224U)  /* Channel 224: External multiplexing 4 */
#define SAF_EQADC_EXT4_CH225            (225U)  /* Channel 225: External multiplexing 4 */
#define SAF_EQADC_EXT4_CH226            (226U)  /* Channel 226: External multiplexing 4 */
#define SAF_EQADC_EXT4_CH227            (227U)  /* Channel 227: External multiplexing 4 */
#define SAF_EQADC_EXT4_CH228            (228U)  /* Channel 228: External multiplexing 4 */
#define SAF_EQADC_EXT4_CH229            (229U)  /* Channel 229: External multiplexing 4 */
#define SAF_EQADC_EXT4_CH230            (230U)  /* Channel 230: External multiplexing 4 */
#define SAF_EQADC_EXT4_CH231            (231U)  /* Channel 231: External multiplexing 4 */
#elif defined(CCFC3008PCSN)
#define SAF_EQADC_EXT0_CH0              (0U)
#define SAF_EQADC_EXT0_CH16             (16U)
#define SAF_EQADC_EXT0_CH32             (32U)
#define SAF_EQADC_EXT0_CH48             (48U)
#define SAF_EQADC_EXT0_CH64             (64U)
#define SAF_EQADC_EXT0_CH80             (80U)
#define SAF_EQADC_EXT0_CH96             (96U)
#define SAF_EQADC_EXT0_CH112            (112U)
#define SAF_EQADC_EXT1_CH1              (1U)
#define SAF_EQADC_EXT1_CH17             (17U)
#define SAF_EQADC_EXT1_CH33             (33U)
#define SAF_EQADC_EXT1_CH49             (49U)
#define SAF_EQADC_EXT1_CH65             (65U)
#define SAF_EQADC_EXT1_CH81             (81U)
#define SAF_EQADC_EXT1_CH97             (97U)
#define SAF_EQADC_EXT1_CH113            (113U)
#define SAF_EQADC_EXT2_CH2              (2U)
#define SAF_EQADC_EXT2_CH18             (18U)
#define SAF_EQADC_EXT2_CH34             (34U)
#define SAF_EQADC_EXT2_CH50             (50U)
#define SAF_EQADC_EXT2_CH66             (66U)
#define SAF_EQADC_EXT2_CH82             (82U)
#define SAF_EQADC_EXT2_CH98             (98U)
#define SAF_EQADC_EXT2_CH114            (114U)
#define SAF_EQADC_EXT3_CH3              (3U)
#define SAF_EQADC_EXT3_CH19             (19U)
#define SAF_EQADC_EXT3_CH35             (35U)
#define SAF_EQADC_EXT3_CH51             (51U)
#define SAF_EQADC_EXT3_CH67             (67U)
#define SAF_EQADC_EXT3_CH83             (83U)
#define SAF_EQADC_EXT3_CH99             (99U)
#define SAF_EQADC_EXT3_CH115            (115U)
#define SAF_EQADC_EXT4_CH4              (4U)
#define SAF_EQADC_EXT4_CH20             (20U)
#define SAF_EQADC_EXT4_CH36             (36U)
#define SAF_EQADC_EXT4_CH52             (52U)
#define SAF_EQADC_EXT4_CH68             (68U)
#define SAF_EQADC_EXT4_CH84             (84U)
#define SAF_EQADC_EXT4_CH100            (100U)
#define SAF_EQADC_EXT4_CH116            (116U)
#define SAF_EQADC_EXT5_CH5              (5U)
#define SAF_EQADC_EXT5_CH21             (21U)
#define SAF_EQADC_EXT5_CH37             (37U)
#define SAF_EQADC_EXT5_CH53             (53U)
#define SAF_EQADC_EXT5_CH69             (69U)
#define SAF_EQADC_EXT5_CH85             (85U)
#define SAF_EQADC_EXT5_CH101            (101U)
#define SAF_EQADC_EXT5_CH117            (117U)
#define SAF_EQADC_EXT6_CH6              (6U)
#define SAF_EQADC_EXT6_CH22             (22U)
#define SAF_EQADC_EXT6_CH38             (38U)
#define SAF_EQADC_EXT6_CH54             (54U)
#define SAF_EQADC_EXT6_CH70             (70U)
#define SAF_EQADC_EXT6_CH86             (86U)
#define SAF_EQADC_EXT6_CH102            (102U)
#define SAF_EQADC_EXT6_CH118            (118U)
#define SAF_EQADC_EXT7_CH7              (7U)
#define SAF_EQADC_EXT7_CH23             (23U)
#define SAF_EQADC_EXT7_CH39             (39U)
#define SAF_EQADC_EXT7_CH55             (55U)
#define SAF_EQADC_EXT7_CH71             (71U)
#define SAF_EQADC_EXT7_CH87             (87U)
#define SAF_EQADC_EXT7_CH103            (103U)
#define SAF_EQADC_EXT7_CH119            (119U)
#define SAF_EQADC_EXT8_CH8              (8U)
#define SAF_EQADC_EXT8_CH24             (24U)
#define SAF_EQADC_EXT8_CH40             (40U)
#define SAF_EQADC_EXT8_CH56             (56U)
#define SAF_EQADC_EXT8_CH72             (72U)
#define SAF_EQADC_EXT8_CH88             (88U)
#define SAF_EQADC_EXT8_CH104            (104U)
#define SAF_EQADC_EXT8_CH120            (120U)
#define SAF_EQADC_EXT9_CH9              (9U)
#define SAF_EQADC_EXT9_CH25             (25U)
#define SAF_EQADC_EXT9_CH41             (41U)
#define SAF_EQADC_EXT9_CH57             (57U)
#define SAF_EQADC_EXT9_CH73             (73U)
#define SAF_EQADC_EXT9_CH89             (89U)
#define SAF_EQADC_EXT9_CH105            (105U)
#define SAF_EQADC_EXT9_CH121            (121U)
#define SAF_EQADC_EXT10_CH10            (10U)
#define SAF_EQADC_EXT10_CH26            (26U)
#define SAF_EQADC_EXT10_CH42            (42U)
#define SAF_EQADC_EXT10_CH58            (58U)
#define SAF_EQADC_EXT10_CH74            (74U)
#define SAF_EQADC_EXT10_CH90            (90U)
#define SAF_EQADC_EXT10_CH106           (106U)
#define SAF_EQADC_EXT10_CH122           (122U)
#define SAF_EQADC_EXT11_CH11            (11U)
#define SAF_EQADC_EXT11_CH27            (27U)
#define SAF_EQADC_EXT11_CH43            (43U)
#define SAF_EQADC_EXT11_CH59            (59U)
#define SAF_EQADC_EXT11_CH75            (75U)
#define SAF_EQADC_EXT11_CH91            (91U)
#define SAF_EQADC_EXT11_CH107           (107U)
#define SAF_EQADC_EXT11_CH123           (123U)
#define SAF_EQADC_EXT12_CH12            (12U)
#define SAF_EQADC_EXT12_CH28            (28U)
#define SAF_EQADC_EXT12_CH44            (44U)
#define SAF_EQADC_EXT12_CH60            (60U)
#define SAF_EQADC_EXT12_CH76            (76U)
#define SAF_EQADC_EXT12_CH92            (92U)
#define SAF_EQADC_EXT12_CH108           (108U)
#define SAF_EQADC_EXT12_CH124           (124U)
#define SAF_EQADC_EXT13_CH13            (13U)
#define SAF_EQADC_EXT13_CH29            (29U)
#define SAF_EQADC_EXT13_CH45            (45U)
#define SAF_EQADC_EXT13_CH61            (61U)
#define SAF_EQADC_EXT13_CH77            (77U)
#define SAF_EQADC_EXT13_CH93            (93U)
#define SAF_EQADC_EXT13_CH109           (109U)
#define SAF_EQADC_EXT13_CH125           (125U)
#define SAF_EQADC_EXT14_CH14            (14U)
#define SAF_EQADC_EXT14_CH30            (30U)
#define SAF_EQADC_EXT14_CH46            (46U)
#define SAF_EQADC_EXT14_CH62            (62U)
#define SAF_EQADC_EXT14_CH78            (78U)
#define SAF_EQADC_EXT14_CH94            (94U)
#define SAF_EQADC_EXT14_CH110           (110U)
#define SAF_EQADC_EXT14_CH126           (126U)
#define SAF_EQADC_EXT15_CH15            (15U)
#define SAF_EQADC_EXT15_CH31            (31U)
#define SAF_EQADC_EXT15_CH47            (47U)
#define SAF_EQADC_EXT15_CH63            (63U)
#define SAF_EQADC_EXT15_CH79            (79U)
#define SAF_EQADC_EXT15_CH95            (95U)
#define SAF_EQADC_EXT15_CH111           (111U)
#define SAF_EQADC_EXT15_CH127           (127U)
#elif (defined(CCFC3010PT) || defined(CCFC3011PT) || defined(CCFC3012PT))
/* Unsupported EMUX. */
#else
    #error "No valid CPU defined!"
#endif

/* SAF_EQADC Resolution count */
#define SAF_EQADC_RESOLUTION_BIT12      (0x3FFCU)   /* Resolution 12 bits: 0xFFFU << 2U */
#define SAF_EQADC_RESOLUTION_BIT10      (0x3FF0U)   /* Resolution 10 bits: 0x3FFU << 4U */
#define SAF_EQADC_RESOLUTION_BIT8       (0x3FC0U)   /* Resolution 8 bits:  0xFFU << 6U  */

/* SAF_EQADC Reference voltage value (millivolt) */
#define SAF_EQADC_VRH_MVOLT             (5000U)
#define SAF_EQADC_VRL_MVOLT             (0U)
#define SAF_EQADC_PCT50_VREF_MVOLT      (2500U)
#define SAF_EQADC_PCT75_VREF_MVOLT      (3750U)
#define SAF_EQADC_PCT25_VREF_MVOLT      (1250U)
#define SAF_EQADC_VDD3V3_MVOLT          (3300U)
#define SAF_EQADC_VDD_PMU_MVOLT         (1000U)
#define SAF_EQADC_VDD_LV_MVOLT          (1100U)

#define SAF_EQADC_PCT75_VREF_CAL_RES    (12288U)    /* CAL_Result(expected), (5V * 75% * 4096(12 bits) / 5V) << 2U */
#define SAF_EQADC_PCT25_VREF_CAL_RES    (4096U)     /* CAL_Result(expected), (5V * 25% * 4096(12 bits) / 5V) << 2U */

#define SAF_EQADC_ADC_GCC_INT_WIDTH     (1U)
#define SAF_EQADC_ADC_GCC_FRAC_WIDTH    (14U)
#define SAF_EQADC_ADC_GCC_WIDTH         (SAF_EQADC_ADC_GCC_INT_WIDTH + SAF_EQADC_ADC_GCC_FRAC_WIDTH)

#define SAF_EQADC_ADC_OCC_FORM1         (1U)
#define SAF_EQADC_ADC_OCC_FORM2         (2U)
#define SAF_EQADC_ADC_OCC_FORM          SAF_EQADC_ADC_OCC_FORM1

/*******************************************************************************
 * SAF_EQADC On-Chip ADC Read/Write LowLevelDriver switch(For test).
 *******************************************************************************/
#define SAF_EQADC_ONCHIPADC_RW_LLD      (TRUE)

/*******************************************************************************
 * Function declaration.
 *******************************************************************************/
//extern uint8_t SAF_EQADC_DevError_ChanNum(const SafEqadcInstanceType Instance, const SafEqadcAdcIdxType AdcIdx, const uint8_t ChanNum);

extern void Adc_SafEqadc_LLD_Init(const Adc_SafEqadcConfigType * const ConfigPtr);

extern void Adc_SafEqadc_LLD_DeInit(const SafEqadcInstanceType instance);

extern void SAF_EQADC_LLD_InternalFuncEn(void);

extern status_t SAF_EQADC_LLD_CalibConvResult(const SafEqadcInstanceType instance, const SafEqadcAdcIdxType AdcIdx, SafEqadc_CalibConfigInfoType * const CalCfgPtr);

extern uint8_t SAF_EQADC_LLD_GetImmediateConvCmdEnDis(const SafEqadcInstanceType instance, const SafEqadcAdcIdxType AdcIdx);

extern void SAF_EQADC_LLD_SetImmediateConvCmdEnDis(const SafEqadcInstanceType instance, const SafEqadcAdcIdxType AdcIdx, const boolean EnDis);

extern uint8_t SAF_EQADC_LLD_GetDebugEnDis(const SafEqadcInstanceType instance);

extern void SAF_EQADC_LLD_SetDebugEnDis(const SafEqadcInstanceType instance, const boolean EnDis);

extern uint8_t SAF_EQADC_LLD_GetExtTrigDigitalFilterLength(const SafEqadcInstanceType instance);

extern void SAF_EQADC_LLD_SetExtTrigDigitalFilterLength(const SafEqadcInstanceType instance, const uint8_t DigitalFilterLen);

extern void SAF_EQADC_LLD_CfifoPushConfigCmd(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx, const SafEqadc_ConfigCmdType * const ConfigCmdPtr);

extern void SAF_EQADC_LLD_SetCQueueConfigCmd(const SafEqadc_ConfigCmdType * const ConfigCmdPtr, const uint8_t CmdCount, uint32_t * const CQueueMemDest);

extern void SAF_EQADC_LLD_CfifoPushConvCmd(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx, const SafEqadc_ConvCmdType * const ConvCmdPtr);

extern void SAF_EQADC_LLD_SetCQueueConvCmd(const SafEqadc_ConvCmdType * const ConvCmdPtr, const uint8_t CmdCount, uint32_t * const CQueueMemDest);

extern uint16_t SAF_EQADC_LLD_RfifoPopData(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType RfifoIdx);

extern status_t SAF_EQADC_LLD_ClearRfifoAllData(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType RfifoIdx);

extern void SAF_EQADC_LLD_SingleScanEn(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx);

extern void SAF_EQADC_LLD_SingleScanEn_Sync(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx);

extern status_t SAF_EQADC_LLD_SetCfifoInvalidate(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx);

extern SafEqadc_CfifoModeType SAF_EQADC_LLD_GetCfifoMode(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx);

extern status_t SAF_EQADC_LLD_SetCfifoMode(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx, const SafEqadc_CfifoModeType CfifoModeTarget);

extern uint8_t SAF_EQADC_LLD_GetCfifo0EntryExtEnDis(const SafEqadcInstanceType instance);

extern void SAF_EQADC_LLD_SetCfifo0EntryExtEnDis(const SafEqadcInstanceType instance, const boolean EnDis);

extern SafEqadc_Cfifo0AModeType SAF_EQADC_LLD_GetCfifo0AdvanceMode(const SafEqadcInstanceType instance);

extern status_t SAF_EQADC_LLD_SetCfifo0AdvanceMode(const SafEqadcInstanceType instance, const SafEqadc_Cfifo0AModeType AdvanceTrigMode);

extern uint16_t SAF_EQADC_LLD_GetIntDmaCtrlEn(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType FifoIdx);

extern void SAF_EQADC_LLD_IntEnDis(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType FifoIdx, uint16_t IntMask, boolean EnDis);

extern void SAF_EQADC_LLD_DmaEnDis(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType FifoIdx, uint16_t DmaMask, boolean EnDis);

extern uint8_t SAF_EQADC_LLD_GetFifoFlagStatus(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType FifoIdx, const SafEqadc_FifoIntStatusType FifoStatusSel);

extern uint32_t SAF_EQADC_LLD_GetFifoIntFlag(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType FifoIdx);

extern void SAF_EQADC_LLD_ClearFifoIntFlag(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType FifoIdx, uint32_t FifoFlagMask);

extern uint16_t SAF_EQADC_LLD_GetCfifoTransferCounter(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx);

extern void SAF_EQADC_LLD_SetCfifoTransferCounter(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx, const uint16_t TransCount);

extern SafEqadc_CfifoStatusType SAF_EQADC_LLD_GetCFifoStatusSnapshot(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx, const SafEqadcAdcIdxType AdcIdx);

extern SafEqadcFifoIdxType SAF_EQADC_LLD_GetLastCFifoSnapshot(const SafEqadcInstanceType instance, const SafEqadcAdcIdxType AdcIdx);

extern uint16_t SAF_EQADC_LLD_GetTransCountLastCFifoSnapshot(const SafEqadcInstanceType instance, const SafEqadcAdcIdxType AdcIdx);

extern SafEqadc_CfifoStatusType SAF_EQADC_LLD_GetCFifoStatus(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx);

#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
extern void SAF_EQADC_LLD_SetCfifoTrigDelay(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx, const boolean CfifoTrigDelayEn, const uint32_t CfifoTrigDelayCnt);
#endif

extern void SAF_EQADC_LLD_SetRedLineClientConfig(const SafEqadcInstanceType instance, const uint8_t ClientIdx, const SafEqadc_RedLineBitsSelType RedLineTbaseBitSel, const SafEqadc_RedLineServerDataSlotSelType RedLineSlotSel);

extern uint32_t SAF_EQADC_LLD_GetCfifoEntryData(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx, const uint8_t EntryIdx);

extern uint32_t SAF_EQADC_LLD_GetCfifo0ExtEntryData(const SafEqadcInstanceType instance, const uint8_t EntryIdx);

extern uint32_t SAF_EQADC_LLD_GetRfifoEntryData(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType RfifoIdx, const uint8_t EntryIdx);

extern void SAF_EQADC_LLD_SetCfifoHwTrigSource(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx, const SafEqadc_HwTrigSourceSelType TrigSourceSel);
#if defined(RESOURCE_SUPPORT_SIUL_IP)
extern void SAF_EQADC_LLD_SetCfifo0AdvanceTrigSource(const SafEqadcInstanceType instance, const uint8_t AdvTrigSourceSel);
#else
extern void SAF_EQADC_LLD_SetCfifo0AdvanceTrigSource(const SafEqadcInstanceType instance, const SafEqadc_AdvanceTrigSourceSelType AdvTrigSourceSel);
#endif
#if SAF_EQADC_ONCHIPADC_RW_LLD
extern void SAF_EQADC_LLD_SetAdcRegValueSSE(const SafEqadcInstanceType instance, const SafEqadcAdcIdxType AdcIdx, const SafEqadcFifoIdxType CfifoIdx, const SafEqadc_OnChipAdcRegAddrType AdcReg, const uint16_t AdcRegVal);

extern uint16_t SAF_EQADC_LLD_GetAdcRegValueSSE(const SafEqadcInstanceType instance, const SafEqadcAdcIdxType AdcIdx, const SafEqadcFifoIdxType CfifoIdx, const SafEqadcFifoIdxType RfifoIdx, const SafEqadc_OnChipAdcRegAddrType AdcReg);
#endif

#endif /* SAF_EQADC_LLD_H_ */


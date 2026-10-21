/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     eqadc_lld.c
* @version  1.0
* @date     2023 - 01 - 01
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/

#include "eqadc_lld.h"/* PRQA S 0380 */
#include "Saf_MemMap.h"
/* PRQA S 0491,0492,0686 EOF */
/* PRQA S 1503 EOF */
/* PRQA S 2052,2212,2469,2844,2976,2982,2983 EOF */
/* PRQA S 3108,3119, 3332, 3469, 3472 EOF */
/* PRQA S 4342,4397,4434 EOF */

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

/*******************************************************************************
 * SAF_EQADC CFIFO for configuring commands
 *******************************************************************************/
#define SAF_EQADC_CFG_CMD_CFIFO_IDX             (SAF_EQADC_FIFO_0)

/************************************************************************************************
 *                                  SAF_EQADC ADC command format
 ************************************************************************************************
 * Conversion Command Format for the Standard Configuration:
 * 0     1     2     3     4     5     6     7  |  8     9     10    11    12    13    14    15
 * EOQ   PAUSE REP  (RESEDRVE)   EB(0) BN    CAL  (MESSAGE_TAG         )  (LST     )   TSR   FMT
 * 16    17    18    19    20    21    22    23 |  24    25    26    27    28    29    30    31
 * (CHANNEL_NUMBER                             )  (must be 0b00000000                          )
 ************************************************************************************************
 * Conversion Command Format for Alternate Configurations(1 - 8):
 * 0     1     2     3     4     5     6     7  |  8     9     10    11    12    13    14    15
 * EOQ   PAUSE REP  (RESEDRVE)   EB(0) BN    CAL  (MESSAGE_TAG         )  (LST     )   TSR   FFMT
 * 16    17    18    19    20    21    22    23 |  24    25    26    27    28    29    30    31
 * (CHANNEL_NUMBER                             )  (ALT_CONFIG_SEL                              )
 ************************************************************************************************
 * Write Configuration Command Format for On-Chip ADC Operation:
 * 0     1     2     3     4     5     6     7  |  8     9     10    11    12    13    14    15
 * EOQ   PAUSE REP  (RESEDRVE)   EB(0) BN  RW(0)  (ADC_REGISTER HIGH BYTE                      )
 * 16    17    18    19    20    21    22    23 |  24    25    26    27    28    29    30    31
 * (ADC_REGISTER LOW BYTE                      )  (ADC_REG_ADDRESS                             )
 ************************************************************************************************
 * Read Configuration Command Format for On-Chip ADC Operation:
 * 0     1     2     3     4     5     6     7  |  8     9     10    11    12    13    14    15
 * EOQ   PAUSE REP  (RESEDRVE)   EB(0) BN  RW(1)  (MESSAGE_TAG         )  (RESEDRVE            )
 * 16    17    18    19    20    21    22    23 |  24    25    26    27    28    29    30    31
 * (RESEDRVE                                   )  (ADC_REG_ADDRESS                             )
 ************************************************************************************************/

/* Command format: CFIFO Header */
/** EOQ Bit Fields **/
#define SAF_EQADC_ADC_CMD_EOQ_MASK              (0x80000000U)
#define SAF_EQADC_ADC_CMD_EOQ_SHIFT             (31U)
#define SAF_EQADC_ADC_CMD_EOQ(x)                (((uint32_t)(((uint32_t)(x)) << SAF_EQADC_ADC_CMD_EOQ_SHIFT))&SAF_EQADC_ADC_CMD_EOQ_MASK)
/** PAUSE Bit Fields **/
#define SAF_EQADC_ADC_CMD_PAUSE_MASK            (0x40000000U)
#define SAF_EQADC_ADC_CMD_PAUSE_SHIFT           (30U)
#define SAF_EQADC_ADC_CMD_PAUSE(x)              (((uint32_t)(((uint32_t)(x)) << SAF_EQADC_ADC_CMD_PAUSE_SHIFT))&SAF_EQADC_ADC_CMD_PAUSE_MASK)
/** REP Bit Fields **/
#define SAF_EQADC_ADC_CMD_REP_MASK              (0x20000000U)
#define SAF_EQADC_ADC_CMD_REP_SHIFT             (29U)
#define SAF_EQADC_ADC_CMD_REP(x)                (((uint32_t)(((uint32_t)(x)) << SAF_EQADC_ADC_CMD_REP_SHIFT))&SAF_EQADC_ADC_CMD_REP_MASK)
#ifdef RESOURCE_SUPPORT_EQADC_CMD_OSR
#define SAF_EQADC_ADC_CMD_OSR_MASK              (0x1C000000U)
#define SAF_EQADC_ADC_CMD_OSR_SHIFT             (26U)
#define SAF_EQADC_ADC_CMD_OSR(x)                (((uint32_t)(((uint32_t)(x)) << SAF_EQADC_ADC_CMD_OSR_SHIFT))&SAF_EQADC_ADC_CMD_OSR_MASK)
#else
/** EB Bit Fields (External Buffer Bit, must set 0)
define SAF_EQADC_ADC_CMD_EB_MASK               (0x04000000U)
define SAF_EQADC_ADC_CMD_EB_SHIFT              (26U)
**/
#endif  /* RESOURCE_SUPPORT_EQADC_CMD_OSR */
/* Command format: ADC Command */
/** BN Bit Fields **/
#define SAF_EQADC_ADC_CMD_BN_MASK               (0x02000000U)
#define SAF_EQADC_ADC_CMD_BN_SHIFT              (25U)
#define SAF_EQADC_ADC_CMD_BN(x)                 (((uint32_t)(((uint32_t)(x)) << SAF_EQADC_ADC_CMD_BN_SHIFT))&SAF_EQADC_ADC_CMD_BN_MASK)
/** CAL Bit Fields (Conversion command format) **/
#define SAF_EQADC_ADC_CMD_CAL_MASK              (0x01000000U)
#define SAF_EQADC_ADC_CMD_CAL_SHIFT             (24U)
#define SAF_EQADC_ADC_CMD_CAL(x)                (((uint32_t)(((uint32_t)(x)) << SAF_EQADC_ADC_CMD_CAL_SHIFT))&SAF_EQADC_ADC_CMD_CAL_MASK)
#if (RESOURCE_SUPPORT_EQADC_CMD_LST == RESOURCE_SUPPORT_EQADC_CMD_LST_2BIT)
/** MESSAGE_TAG Bit Fields **/
#define SAF_EQADC_ADC_CMD_MESSAGE_TAG_MASK      (0x00F00000U)
#define SAF_EQADC_ADC_CMD_MESSAGE_TAG_SHIFT     (20U)
#define SAF_EQADC_ADC_CMD_MESSAGE_TAG(x)        (((uint32_t)(((uint32_t)(x)) << SAF_EQADC_ADC_CMD_MESSAGE_TAG_SHIFT))&SAF_EQADC_ADC_CMD_MESSAGE_TAG_MASK)
/** LST Bit Fields (Conversion command format) **/
#define SAF_EQADC_ADC_CMD_LST_MASK              (0x000C0000U)
#define SAF_EQADC_ADC_CMD_LST_SHIFT             (18U)
#define SAF_EQADC_ADC_CMD_LST(x)                (((uint32_t)(((uint32_t)(x)) << SAF_EQADC_ADC_CMD_LST_SHIFT))&SAF_EQADC_ADC_CMD_LST_MASK)
#elif (RESOURCE_SUPPORT_EQADC_CMD_LST == RESOURCE_SUPPORT_EQADC_CMD_LST_3BIT)
/** MESSAGE_TAG Bit Fields **/
#define SAF_EQADC_ADC_CMD_MESSAGE_TAG_MASK      (0x00E00000U)
#define SAF_EQADC_ADC_CMD_MESSAGE_TAG_SHIFT     (21U)
#define SAF_EQADC_ADC_CMD_MESSAGE_TAG(x)        (((uint32_t)(((uint32_t)(x)) << SAF_EQADC_ADC_CMD_MESSAGE_TAG_SHIFT))&SAF_EQADC_ADC_CMD_MESSAGE_TAG_MASK)
/** LST Bit Fields (Conversion command format) **/
#define SAF_EQADC_ADC_CMD_LST_MASK              (0x001C0000U)
#define SAF_EQADC_ADC_CMD_LST_SHIFT             (18U)
#define SAF_EQADC_ADC_CMD_LST(x)                (((uint32_t)(((uint32_t)(x)) << SAF_EQADC_ADC_CMD_LST_SHIFT))&SAF_EQADC_ADC_CMD_LST_MASK)
#else
    #error "EQADC_ADC_CMD error!"
#endif  /* RESOURCE_SUPPORT_EQADC_CMD_LST */
/** TSR Bit Fields (Conversion command format) **/
#define SAF_EQADC_ADC_CMD_TSR_MASK              (0x00020000U)
#define SAF_EQADC_ADC_CMD_TSR_SHIFT             (17U)
#define SAF_EQADC_ADC_CMD_TSR(x)                (((uint32_t)(((uint32_t)(x)) << SAF_EQADC_ADC_CMD_TSR_SHIFT))&SAF_EQADC_ADC_CMD_TSR_MASK)
/** FMT Bit Fields (Conversion command format) **/
#define SAF_EQADC_ADC_CMD_FMT_MASK              (0x00010000U)
#define SAF_EQADC_ADC_CMD_FMT_SHIFT             (16U)
#define SAF_EQADC_ADC_CMD_FMT(x)                (((uint32_t)(((uint32_t)(x)) << SAF_EQADC_ADC_CMD_FMT_SHIFT))&SAF_EQADC_ADC_CMD_FMT_MASK)
/** FFMT Bit Fields (Conversion command format) **/
#define SAF_EQADC_ADC_CMD_FFMT_MASK             (0x00010000U)
#define SAF_EQADC_ADC_CMD_FFMT_SHIFT            (16U)
#define SAF_EQADC_ADC_CMD_FFMT(x)               (((uint32_t)(((uint32_t)(x)) << SAF_EQADC_ADC_CMD_FFMT_SHIFT))&SAF_EQADC_ADC_CMD_FFMT_MASK)
/** CHAN_NUM Bit Fields (Conversion command format) **/
#define SAF_EQADC_ADC_CMD_CHAN_NUM_MASK         (0x0000FF00U)
#define SAF_EQADC_ADC_CMD_CHAN_NUM_SHIFT        (8U)
#define SAF_EQADC_ADC_CMD_CHAN_NUM(x)           (((uint32_t)(((uint32_t)(x)) << SAF_EQADC_ADC_CMD_CHAN_NUM_SHIFT))&SAF_EQADC_ADC_CMD_CHAN_NUM_MASK)
/** ALT_CFG_SEL Bit Fields (Conversion command format) **/
#define SAF_EQADC_ADC_CMD_ALT_CFG_SEL_MASK      (0x000000FFU)
#define SAF_EQADC_ADC_CMD_ALT_CFG_SEL_SHIFT     (0U)
#define SAF_EQADC_ADC_CMD_ALT_CFG_SEL(x)        (((uint32_t)(((uint32_t)(x)) << SAF_EQADC_ADC_CMD_ALT_CFG_SEL_SHIFT))&SAF_EQADC_ADC_CMD_ALT_CFG_SEL_MASK)
/** RW Bit Fields (RW Configuration command format) **/
#define SAF_EQADC_ADC_CMD_RW_MASK               (0x01000000U)
#define SAF_EQADC_ADC_CMD_RW_SHIFT              (24U)
#define SAF_EQADC_ADC_CMD_RW(x)                 (((uint32_t)(((uint32_t)(x)) << SAF_EQADC_ADC_CMD_RW_SHIFT))&SAF_EQADC_ADC_CMD_RW_MASK)
/**[REG_HIGH_BYTE + REG_LOW_BYTE] Bit Fields (RW Configuration command format) **/
#define SAF_EQADC_ADC_CMD_REG_HL_BYTE_MASK      (0x00FFFF00U)
#define SAF_EQADC_ADC_CMD_REG_HL_BYTE_SHIFT     (8U)
#define SAF_EQADC_ADC_CMD_REG_HL_BYTE(x)        (((uint32_t)(((uint32_t)(x)) << SAF_EQADC_ADC_CMD_REG_HL_BYTE_SHIFT))&SAF_EQADC_ADC_CMD_REG_HL_BYTE_MASK)
/** REG_ADDR Bit Fields (RW Configuration command format) **/
#define SAF_EQADC_ADC_CMD_REG_ADDR_MASK         (0x000000FFU)
#define SAF_EQADC_ADC_CMD_REG_ADDR_SHIFT        (0U)
#define SAF_EQADC_ADC_CMD_REG_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << SAF_EQADC_ADC_CMD_REG_ADDR_SHIFT))&SAF_EQADC_ADC_CMD_REG_ADDR_MASK)

#define SAF_EQADC_DMA_MAPPED_CHAN_INVALID       (0xFFU)

/* SAF_EQADC Module Configuration Register (SAF_EQADC_MCR) */
SAF_ADC_SEC_CONFIG_DATA
static vuint32_t * const SAF_EQADC_MCR[ADC_SAF_EQADC_MAX_INSTANCE] =
{
    &(SAF_EQADC0_PTR->MCR.R),
    &(SAF_EQADC1_PTR->MCR.R),
    &(SAF_EQADC2_PTR->MCR.R),
    &(SAF_EQADC3_PTR->MCR.R),
    &(SAF_EQADC4_PTR->MCR.R),
#ifdef CCFC3012PT
    &(SAF_EQADC5_PTR->MCR.R),
    &(SAF_EQADC6_PTR->MCR.R),
#endif
};

/* SAF_EQADC External Trigger Digital Filter Register (SAF_EQADC_ETDFR) */
SAF_ADC_SEC_CONFIG_DATA
static vuint32_t * const SAF_EQADC_ETDFR[ADC_SAF_EQADC_MAX_INSTANCE] =
{
    &(SAF_EQADC0_PTR->ETDFR.R),
    &(SAF_EQADC1_PTR->ETDFR.R),
    &(SAF_EQADC2_PTR->ETDFR.R),
    &(SAF_EQADC3_PTR->ETDFR.R),
    &(SAF_EQADC4_PTR->ETDFR.R),
#ifdef CCFC3012PT
    &(SAF_EQADC5_PTR->ETDFR.R),
    &(SAF_EQADC6_PTR->ETDFR.R),
#endif
};

/* SAF_EQADC Command FIFO Push Registers (SAF_EQADC_CFPR) */
SAF_ADC_SEC_CONFIG_DATA
static vuint32_t * const SAF_EQADC_CFPR[ADC_SAF_EQADC_MAX_INSTANCE][SAF_EQADC_CFIFO_COUNT] =
{
    {&(SAF_EQADC0_PTR->CFPR[0U].R), &(SAF_EQADC0_PTR->CFPR[1U].R), &(SAF_EQADC0_PTR->CFPR[2U].R), &(SAF_EQADC0_PTR->CFPR[3U].R), &(SAF_EQADC0_PTR->CFPR[4U].R), &(SAF_EQADC0_PTR->CFPR[5U].R)},
    {&(SAF_EQADC1_PTR->CFPR[0U].R), &(SAF_EQADC1_PTR->CFPR[1U].R), &(SAF_EQADC1_PTR->CFPR[2U].R), &(SAF_EQADC1_PTR->CFPR[3U].R), &(SAF_EQADC1_PTR->CFPR[4U].R), &(SAF_EQADC1_PTR->CFPR[5U].R)},
    {&(SAF_EQADC2_PTR->CFPR[0U].R), &(SAF_EQADC2_PTR->CFPR[1U].R), &(SAF_EQADC2_PTR->CFPR[2U].R), &(SAF_EQADC2_PTR->CFPR[3U].R), &(SAF_EQADC2_PTR->CFPR[4U].R), &(SAF_EQADC2_PTR->CFPR[5U].R)},
    {&(SAF_EQADC3_PTR->CFPR[0U].R), &(SAF_EQADC3_PTR->CFPR[1U].R), &(SAF_EQADC3_PTR->CFPR[2U].R), &(SAF_EQADC3_PTR->CFPR[3U].R), &(SAF_EQADC3_PTR->CFPR[4U].R), &(SAF_EQADC3_PTR->CFPR[5U].R)},
    {&(SAF_EQADC4_PTR->CFPR[0U].R), &(SAF_EQADC4_PTR->CFPR[1U].R), &(SAF_EQADC4_PTR->CFPR[2U].R), &(SAF_EQADC4_PTR->CFPR[3U].R), &(SAF_EQADC4_PTR->CFPR[4U].R), &(SAF_EQADC4_PTR->CFPR[5U].R)},
#ifdef CCFC3012PT
    {&(SAF_EQADC5_PTR->CFPR[0U].R), &(SAF_EQADC5_PTR->CFPR[1U].R), &(SAF_EQADC5_PTR->CFPR[2U].R), &(SAF_EQADC5_PTR->CFPR[3U].R), &(SAF_EQADC5_PTR->CFPR[4U].R), &(SAF_EQADC5_PTR->CFPR[5U].R)},
    {&(SAF_EQADC6_PTR->CFPR[0U].R), &(SAF_EQADC6_PTR->CFPR[1U].R), &(SAF_EQADC6_PTR->CFPR[2U].R), &(SAF_EQADC6_PTR->CFPR[3U].R), &(SAF_EQADC6_PTR->CFPR[4U].R), &(SAF_EQADC6_PTR->CFPR[5U].R)},
#endif
};

/* SAF_EQADC Result FIFO Pop Registers (SAF_EQADC_RFPR) */
SAF_ADC_SEC_CONFIG_DATA
static vuint32_t * const SAF_EQADC_RFPR[ADC_SAF_EQADC_MAX_INSTANCE][SAF_EQADC_RFIFO_COUNT] =
{
    {&(SAF_EQADC0_PTR->RFPR[0U].R), &(SAF_EQADC0_PTR->RFPR[1U].R), &(SAF_EQADC0_PTR->RFPR[2U].R), &(SAF_EQADC0_PTR->RFPR[3U].R), &(SAF_EQADC0_PTR->RFPR[4U].R), &(SAF_EQADC0_PTR->RFPR[5U].R)},
    {&(SAF_EQADC1_PTR->RFPR[0U].R), &(SAF_EQADC1_PTR->RFPR[1U].R), &(SAF_EQADC1_PTR->RFPR[2U].R), &(SAF_EQADC1_PTR->RFPR[3U].R), &(SAF_EQADC1_PTR->RFPR[4U].R), &(SAF_EQADC1_PTR->RFPR[5U].R)},
    {&(SAF_EQADC2_PTR->RFPR[0U].R), &(SAF_EQADC2_PTR->RFPR[1U].R), &(SAF_EQADC2_PTR->RFPR[2U].R), &(SAF_EQADC2_PTR->RFPR[3U].R), &(SAF_EQADC2_PTR->RFPR[4U].R), &(SAF_EQADC2_PTR->RFPR[5U].R)},
    {&(SAF_EQADC3_PTR->RFPR[0U].R), &(SAF_EQADC3_PTR->RFPR[1U].R), &(SAF_EQADC3_PTR->RFPR[2U].R), &(SAF_EQADC3_PTR->RFPR[3U].R), &(SAF_EQADC3_PTR->RFPR[4U].R), &(SAF_EQADC3_PTR->RFPR[5U].R)},
    {&(SAF_EQADC4_PTR->RFPR[0U].R), &(SAF_EQADC4_PTR->RFPR[1U].R), &(SAF_EQADC4_PTR->RFPR[2U].R), &(SAF_EQADC4_PTR->RFPR[3U].R), &(SAF_EQADC4_PTR->RFPR[4U].R), &(SAF_EQADC4_PTR->RFPR[5U].R)},
#ifdef CCFC3012PT
    {&(SAF_EQADC5_PTR->RFPR[0U].R), &(SAF_EQADC5_PTR->RFPR[1U].R), &(SAF_EQADC5_PTR->RFPR[2U].R), &(SAF_EQADC5_PTR->RFPR[3U].R), &(SAF_EQADC5_PTR->RFPR[4U].R), &(SAF_EQADC5_PTR->RFPR[5U].R)},
    {&(SAF_EQADC6_PTR->RFPR[0U].R), &(SAF_EQADC6_PTR->RFPR[1U].R), &(SAF_EQADC6_PTR->RFPR[2U].R), &(SAF_EQADC6_PTR->RFPR[3U].R), &(SAF_EQADC6_PTR->RFPR[4U].R), &(SAF_EQADC6_PTR->RFPR[5U].R)},
#endif
};

/* SAF_EQADC CFIFO Control Registers (SAF_EQADC_CFCR) */
SAF_ADC_SEC_CONFIG_DATA
static vuint32_t * const SAF_EQADC_CFCR[ADC_SAF_EQADC_MAX_INSTANCE][3U] =
{
    {&(SAF_EQADC0_PTR->CFCR0.R), &(SAF_EQADC0_PTR->CFCR1.R), &(SAF_EQADC0_PTR->CFCR2.R)},
    {&(SAF_EQADC1_PTR->CFCR0.R), &(SAF_EQADC1_PTR->CFCR1.R), &(SAF_EQADC1_PTR->CFCR2.R)},
    {&(SAF_EQADC2_PTR->CFCR0.R), &(SAF_EQADC2_PTR->CFCR1.R), &(SAF_EQADC2_PTR->CFCR2.R)},
    {&(SAF_EQADC3_PTR->CFCR0.R), &(SAF_EQADC3_PTR->CFCR1.R), &(SAF_EQADC3_PTR->CFCR2.R)},
    {&(SAF_EQADC4_PTR->CFCR0.R), &(SAF_EQADC4_PTR->CFCR1.R), &(SAF_EQADC4_PTR->CFCR2.R)},
#ifdef CCFC3012PT
    {&(SAF_EQADC5_PTR->CFCR0.R), &(SAF_EQADC5_PTR->CFCR1.R), &(SAF_EQADC5_PTR->CFCR2.R)},
    {&(SAF_EQADC6_PTR->CFCR0.R), &(SAF_EQADC6_PTR->CFCR1.R), &(SAF_EQADC6_PTR->CFCR2.R)},
#endif
};

/* SAF_EQADC Interrupt and DMA Control Registers (SAF_EQADC_IDCR) */
SAF_ADC_SEC_CONFIG_DATA
static vuint32_t * const SAF_EQADC_IDCR[ADC_SAF_EQADC_MAX_INSTANCE][3U] =
{
    {&(SAF_EQADC0_PTR->IDCR0.R), &(SAF_EQADC0_PTR->IDCR1.R), &(SAF_EQADC0_PTR->IDCR2.R)},
    {&(SAF_EQADC1_PTR->IDCR0.R), &(SAF_EQADC1_PTR->IDCR1.R), &(SAF_EQADC1_PTR->IDCR2.R)},
    {&(SAF_EQADC2_PTR->IDCR0.R), &(SAF_EQADC2_PTR->IDCR1.R), &(SAF_EQADC2_PTR->IDCR2.R)},
    {&(SAF_EQADC3_PTR->IDCR0.R), &(SAF_EQADC3_PTR->IDCR1.R), &(SAF_EQADC3_PTR->IDCR2.R)},
    {&(SAF_EQADC4_PTR->IDCR0.R), &(SAF_EQADC4_PTR->IDCR1.R), &(SAF_EQADC4_PTR->IDCR2.R)},
#ifdef CCFC3012PT
    {&(SAF_EQADC5_PTR->IDCR0.R), &(SAF_EQADC5_PTR->IDCR1.R), &(SAF_EQADC5_PTR->IDCR2.R)},
    {&(SAF_EQADC6_PTR->IDCR0.R), &(SAF_EQADC6_PTR->IDCR1.R), &(SAF_EQADC6_PTR->IDCR2.R)},
#endif
};

/* SAF_EQADC CFIFO Transfer Counter Registers (SAF_EQADC_CFTCR) */
SAF_ADC_SEC_CONFIG_DATA
static vuint32_t * const SAF_EQADC_CFTCR[ADC_SAF_EQADC_MAX_INSTANCE][3U] =
{
    {&(SAF_EQADC0_PTR->CFTCR0.R), &(SAF_EQADC0_PTR->CFTCR1.R), &(SAF_EQADC0_PTR->CFTCR2.R)},
    {&(SAF_EQADC1_PTR->CFTCR0.R), &(SAF_EQADC1_PTR->CFTCR1.R), &(SAF_EQADC1_PTR->CFTCR2.R)},
    {&(SAF_EQADC2_PTR->CFTCR0.R), &(SAF_EQADC2_PTR->CFTCR1.R), &(SAF_EQADC2_PTR->CFTCR2.R)},
    {&(SAF_EQADC3_PTR->CFTCR0.R), &(SAF_EQADC3_PTR->CFTCR1.R), &(SAF_EQADC3_PTR->CFTCR2.R)},
    {&(SAF_EQADC4_PTR->CFTCR0.R), &(SAF_EQADC4_PTR->CFTCR1.R), &(SAF_EQADC4_PTR->CFTCR2.R)},
#ifdef CCFC3012PT
    {&(SAF_EQADC5_PTR->CFTCR0.R), &(SAF_EQADC5_PTR->CFTCR1.R), &(SAF_EQADC5_PTR->CFTCR2.R)},
    {&(SAF_EQADC6_PTR->CFTCR0.R), &(SAF_EQADC6_PTR->CFTCR1.R), &(SAF_EQADC6_PTR->CFTCR2.R)},
#endif
};

/* SAF_EQADC CFIFO Status Snapshot Registers (SAF_EQADC_CFSSR) */
SAF_ADC_SEC_CONFIG_DATA
static vuint32_t * const SAF_EQADC_CFSSR[ADC_SAF_EQADC_MAX_INSTANCE][2U] =
{
    {&(SAF_EQADC0_PTR->CFSSR0.R), &(SAF_EQADC0_PTR->CFSSR1.R)},
    {&(SAF_EQADC1_PTR->CFSSR0.R), &(SAF_EQADC1_PTR->CFSSR1.R)},
    {&(SAF_EQADC2_PTR->CFSSR0.R), &(SAF_EQADC2_PTR->CFSSR1.R)},
    {&(SAF_EQADC3_PTR->CFSSR0.R), &(SAF_EQADC3_PTR->CFSSR1.R)},
    {&(SAF_EQADC4_PTR->CFSSR0.R), &(SAF_EQADC4_PTR->CFSSR1.R)},
#ifdef CCFC3012PT
    {&(SAF_EQADC5_PTR->CFSSR0.R), &(SAF_EQADC5_PTR->CFSSR1.R)},
    {&(SAF_EQADC6_PTR->CFSSR0.R), &(SAF_EQADC6_PTR->CFSSR1.R)},
#endif
};
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
///* EQADC CFIFO Trigger Delay Registers (EQADC_DLY) */
//SAF_ADC_SEC_CONFIG_DATA
//static vuint32_t * const EQADC_DLY[ADC_SAF_EQADC_MAX_INSTANCE][SAF_EQADC_CFIFO_COUNT] =
//{
//    {&(SAF_EQADC0_PTR->DLY[0U].R), &(SAF_EQADC0_PTR->DLY[1U].R), &(SAF_EQADC0_PTR->DLY[2U].R), &(SAF_EQADC0_PTR->DLY[3U].R), &(SAF_EQADC0_PTR->DLY[4U].R), &(SAF_EQADC0_PTR->DLY[5U].R)},
//    {&(SAF_EQADC1_PTR->DLY[0U].R), &(SAF_EQADC1_PTR->DLY[1U].R), &(SAF_EQADC1_PTR->DLY[2U].R), &(SAF_EQADC1_PTR->DLY[3U].R), &(SAF_EQADC1_PTR->DLY[4U].R), &(SAF_EQADC1_PTR->DLY[5U].R)},
//    {&(SAF_EQADC2_PTR->DLY[0U].R), &(SAF_EQADC2_PTR->DLY[1U].R), &(SAF_EQADC2_PTR->DLY[2U].R), &(SAF_EQADC2_PTR->DLY[3U].R), &(SAF_EQADC2_PTR->DLY[4U].R), &(SAF_EQADC2_PTR->DLY[5U].R)},
//    {&(SAF_EQADC3_PTR->DLY[0U].R), &(SAF_EQADC3_PTR->DLY[1U].R), &(SAF_EQADC3_PTR->DLY[2U].R), &(SAF_EQADC3_PTR->DLY[3U].R), &(SAF_EQADC3_PTR->DLY[4U].R), &(SAF_EQADC3_PTR->DLY[5U].R)},
//    {&(SAF_EQADC4_PTR->DLY[0U].R), &(SAF_EQADC4_PTR->DLY[1U].R), &(SAF_EQADC4_PTR->DLY[2U].R), &(SAF_EQADC4_PTR->DLY[3U].R), &(SAF_EQADC4_PTR->DLY[4U].R), &(SAF_EQADC4_PTR->DLY[5U].R)},
//#ifdef CCFC3012PT
//	{&(SAF_EQADC5_PTR->DLY[0U].R), &(SAF_EQADC5_PTR->DLY[1U].R), &(SAF_EQADC5_PTR->DLY[2U].R), &(SAF_EQADC5_PTR->DLY[3U].R), &(SAF_EQADC5_PTR->DLY[4U].R), &(SAF_EQADC5_PTR->DLY[5U].R)},
//    {&(SAF_EQADC6_PTR->DLY[0U].R), &(SAF_EQADC6_PTR->DLY[1U].R), &(SAF_EQADC6_PTR->DLY[2U].R), &(SAF_EQADC6_PTR->DLY[3U].R), &(SAF_EQADC6_PTR->DLY[4U].R), &(SAF_EQADC6_PTR->DLY[5U].R)}
//#endif
//};
#endif
/*******************************************************************************
 * @brief SAF_EQADC Module Configuration Register: Get ICEAx (SAF_EQADC_MCR: ICEAx)
 *
 * @param instance: SAF_EQADC instance
 *        AdcIdx: 0, 1 (On-chip ADC0 / ADC1)
 *        [out] FALSE: Disable
 *              TRUE: Enable
 *
 * @note  ICEAn enables the SAF_EQADC to abort on-chip ADCn current conversion
 *          and to start the immediate conversion command from CFIFO0 in the
 *          requested ADCn.
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint8_t SAF_EQADC_MCR_GetICEAxEnDis(const uint8_t instance, const uint8_t AdcIdx)
{
    uint8_t EnDis = FALSE;

    switch (AdcIdx)
    {
        case 0U:
            EnDis = (uint8_t)((*(SAF_EQADC_MCR[instance]) & SAF_EQADC_MCR_ICEA0_MASK) >> SAF_EQADC_MCR_ICEA0_SHIFT);/* polyspace RTE:NIV,IDP */
            break;
        case 1U:
            EnDis = (uint8_t)((*(SAF_EQADC_MCR[instance]) & SAF_EQADC_MCR_ICEA1_MASK) >> SAF_EQADC_MCR_ICEA1_SHIFT);/* polyspace RTE:NIV,IDP */
            break;
        default:
            /* Nothing to do */
            break;
    }

    return EnDis;
}

/*******************************************************************************
 * @brief SAF_EQADC Module Configuration Register: Set ICEAx (SAF_EQADC_MCR: ICEAx)
 *
 * @param instance: SAF_EQADC instance
 *        AdcIdx: 0, 1 (On-chip ADC0 / ADC1)
 *        EnDis: FALSE: Disable
 *               TRUE: Enable
 *
 * @note  ICEAn enables the SAF_EQADC to abort on-chip ADCn current conversion
 *          and to start the immediate conversion command from CFIFO0 in the
 *          requested ADCn.
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_EQADC_MCR_SetICEAxEnDis(const uint8_t instance, const uint8_t AdcIdx, const boolean EnDis)
{
    uint8_t ICEAxEnDis = (AdcIdx << 1U) | EnDis;

    switch (ICEAxEnDis)
    {
        case 0U:
            /* Disable CFIFO0 Immediate Conversion Command (ADC0) */
            *(SAF_EQADC_MCR[instance]) &= ~SAF_EQADC_MCR_ICEA0_MASK;/* polyspace RTE:NIV,IDP */
            break;
        case 1U:
            /* Enable CFIFO0 Immediate Conversion Command (ADC0) */
            *(SAF_EQADC_MCR[instance]) |= SAF_EQADC_MCR_ICEA0_MASK;/* polyspace RTE:NIV,IDP */
            break;
        case 2U:
            /* Disable CFIFO0 Immediate Conversion Command (ADC1) */
            *(SAF_EQADC_MCR[instance]) &= ~SAF_EQADC_MCR_ICEA1_MASK;/* polyspace RTE:NIV,IDP */
            break;
        case 3U:
            /* Enable CFIFO0 Immediate Conversion Command (ADC1) */
            *(SAF_EQADC_MCR[instance]) |= SAF_EQADC_MCR_ICEA1_MASK;/* polyspace RTE:NIV,IDP */
            break;
        default:
            /* Nothing to do */
            break;
    }
}

/*******************************************************************************
 * @brief SAF_EQADC Module Configuration Register: Get Debug enable/disable
 *          (SAF_EQADC_MCR: DBG)
 *
 * @param instance: SAF_EQADC instance
 *        [out] FALSE: Disable
 *              TRUE: Enable
 *
 * @note  The DBG field defines the SAF_EQADC response to a debug mode entry request.
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint8_t SAF_EQADC_MCR_GetDebugEnDis(const uint8_t instance)
{
    return (((*(SAF_EQADC_MCR[instance]) & SAF_EQADC_MCR_DBG_MASK) == 0U) ? FALSE : TRUE);/* polyspace RTE:NIV,IDP */
}

/*******************************************************************************
 * @brief SAF_EQADC Module Configuration Register: Set Debug enable/disable
 *          (SAF_EQADC_MCR: DBG)
 *
 * @param instance: SAF_EQADC instance
 *        EnDis: FALSE: Disable
 *               TRUE: Enable
 *
 * @note  The DBG field defines the SAF_EQADC response to a debug mode entry request.
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_EQADC_MCR_SetDebugEnDis(const uint8_t instance, const boolean EnDis)
{
    if (FALSE == EnDis)
    {
        *(SAF_EQADC_MCR[instance]) &= ~SAF_EQADC_MCR_DBG_MASK;/* polyspace RTE:NIV,IDP */
    }
    else
    {
        *(SAF_EQADC_MCR[instance]) |= SAF_EQADC_MCR_DBG_MASK;/* polyspace RTE:NIV,IDP */
    }
}

SAF_ADC_SEC_CODE
static inline uint8_t SAF_EQADC_ETDFR_GetDFL(const uint8_t instance)
{
    return (uint8_t)(*(SAF_EQADC_ETDFR[instance]) & SAF_EQADC_ETDFR_DFL_MASK);/* polyspace RTE:NIV,IDP */
}

/*******************************************************************************
 * @brief SAF_EQADC External Trigger Digital Filter Register (SAF_EQADC_ETDFR: DFL)
 *
 * @param instance: SAF_EQADC instance
 *        DigiFilterLen: Digital filter length
 *
 * @note  FilterPeriod = (SystemClockPeriod * 2^DFL) + 1(SystemClockPeriod).
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_EQADC_ETDFR_SetDFL(const uint8_t instance, const uint8_t DigiFilterLen)
{
    *(SAF_EQADC_ETDFR[instance]) = ((uint32_t)DigiFilterLen & SAF_EQADC_ETDFR_DFL_MASK); /* polyspace RTE:IDP */
}

/*******************************************************************************
 * @brief SAF_EQADC CFIFO Control Register 0: Get CFEEE0 (SAF_EQADC_CFCR0: CFEEE0)
 *
 * @param instance: SAF_EQADC instance
 *        [out] FALSE: Disable
 *              TRUE: Enable
 *
 * @note  CFIFO0 Entry Number Extension Enable/Disable.
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint8_t SAF_EQADC_CFCR0_GetCfifo0EntryExtEnDis(const uint8_t instance)
{
    return (((*(SAF_EQADC_CFCR[instance][0U]) & SAF_EQADC_CFCR0_CFEEE0_MASK) == 0U) ? FALSE : TRUE);/* polyspace RTE:NIV,IDP */
}

/*******************************************************************************
 * @brief SAF_EQADC CFIFO Control Register 0: Set CFEEE0 (SAF_EQADC_CFCR0: CFEEE0)
 *
 * @param instance: SAF_EQADC instance
 *        EnDis: FALSE: Disable
 *               TRUE: Enable
 *
 * @note  CFIFO0 Entry Number Extension Enable/Disable.
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_EQADC_CFCR0_SetCfifo0EntryExtEnDis(const uint8_t instance, const boolean EnDis)
{
    if (FALSE == EnDis)
    {
        /* CFIFO0 Entry Number Extension Disable */
        *(SAF_EQADC_CFCR[instance][0U]) &= ~SAF_EQADC_CFCR0_CFEEE0_MASK;/* polyspace RTE:NIV,IDP */
    }
    else
    {
        /* CFIFO0 Entry Number Extension Enable */
        *(SAF_EQADC_CFCR[instance][0U]) |= SAF_EQADC_CFCR0_CFEEE0_MASK;/* polyspace RTE:NIV,IDP */
    }
}

/*******************************************************************************
 * @brief SAF_EQADC CFIFO Control Register 0 (SAF_EQADC_CFCR0: STRME0)
 *
 * @param instance: SAF_EQADC instance
 *        EnDis: 0, 1 (Disable, Enable)
 *
 * @note  CFIFO0 Streaming Mode Operation Enable/Disable.
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_EQADC_CFCR0_Cfifo0StreamModeEnDis(const uint8_t instance, const boolean EnDis)
{
    if (0U == EnDis)
    {
        /* CFIFO0 Entry Number Extension Disable */
        *(SAF_EQADC_CFCR[instance][0U]) &= ~SAF_EQADC_CFCR0_STRME0_MASK;/* polyspace RTE:NIV,IDP */
    }
    else
    {
        /* CFIFO0 Entry Number Extension Enable */
        *(SAF_EQADC_CFCR[instance][0U]) |= SAF_EQADC_CFCR0_STRME0_MASK;/* polyspace RTE:NIV,IDP */
    }
}

/*******************************************************************************
 * @brief SAF_EQADC CFIFO Control Register x (SAF_EQADC_CFCRx: SSEy)
 *          (x = 0...2, y = 0...5).
 *
 * @param instance: SAF_EQADC instance
 *        CfifoIdx: CFIFO Index (Index = y)
 *
 * @note  Writing a "1" to SSEx will set the SAF_EQADC_FISR[SSSx] field if the
 *          CFIFO is in single-scan mode. SSEx always is read as "0".
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_EQADC_CFCRxSetSSE(const uint8_t instance, const uint8_t CfifoIdx)
{
    uint8_t CFCRx = CfifoIdx / 2U;  /* SAF_EQADC CFIFO Control Register x */

    if ((CfifoIdx % 2U) == 0U)
    {
        /* SAF_EQADC CfifoIdx: 0/2/4 */
        *(SAF_EQADC_CFCR[instance][CFCRx]) |= SAF_EQADC_CFCR0_SSE0_MASK;/* polyspace RTE:NIV,IDP */
    }
    else
    {
        /* SAF_EQADC CfifoIdx: 1/3/5 */
        *(SAF_EQADC_CFCR[instance][CFCRx]) |= SAF_EQADC_CFCR0_SSE1_MASK;/* polyspace RTE:NIV,IDP */
    }
}

/*******************************************************************************
 * @brief SAF_EQADC CFIFO Control Register x (SAF_EQADC_CFCRx: SSEy)
 *          (x = 0...2, y = 0...5).
 *
 * @param instance: SAF_EQADC instance
 *        CfifoIdx: CFIFO Index (Index = y)(Synchronous: 0 & 1, 2 & 3, 4 & 5)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_EQADC_CFCRxSetSSE_Sync(const uint8_t instance, const uint8_t CfifoIdx)
{
    uint8_t CFCRx = CfifoIdx / 2U;  /* SAF_EQADC CFIFO Control Register x */

    /* SAF_EQADC CfifoIdx synchronous: 0 & 1, 2 & 3, 4 & 5 */
    *(SAF_EQADC_CFCR[instance][CFCRx]) |= (SAF_EQADC_CFCR0_SSE0_MASK | SAF_EQADC_CFCR0_SSE1_MASK);/* polyspace RTE:NIV,IDP */
}

/*********************************************************************************
 * @brief SAF_EQADC CFIFO Control Register x (SAF_EQADC_CFCRx: CFINVy)
 *          (x = 0...2, y = 0...5).
 *
 * @param instance: SAF_EQADC instance
 *        CfifoIdx: CFIFO Index (Index = y)
 *
 * @note  Writing CFINVy only invalidates commands stored in CFIFOx;
 *          previously transferred commands that are waiting for execution,
 *          that is commands stored in the CBuffers, will still be executed,
 *          and results generated by them will be stored in the appropriate RFIFO.
 *        CFINVy must not be written unless the MODEy is configured to disabled,
 *          and CFIFO status is IDLE.
 *********************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_EQADC_CFCRxSetInvalidate(const uint8_t instance, const uint8_t CfifoIdx)
{
    uint8_t CFCRx = CfifoIdx / 2U;  /* SAF_EQADC CFIFO Control Register x */

    if ((CfifoIdx % 2U) == 0U)
    {
        /* SAF_EQADC CfifoIdx: 0/2/4 */
        *(SAF_EQADC_CFCR[instance][CFCRx]) |= SAF_EQADC_CFCR0_CFINV0_MASK;/* polyspace RTE:NIV,IDP */
    }
    else
    {
        /* SAF_EQADC CfifoIdx: 1/3/5 */
        *(SAF_EQADC_CFCR[instance][CFCRx]) |= SAF_EQADC_CFCR0_CFINV1_MASK;/* polyspace RTE:NIV,IDP */
    }
}

/*******************************************************************************
 * @brief SAF_EQADC CFIFO Control Register x (SAF_EQADC_CFCRx: MODEy)
 *          (x = 0...2, y = 0...5).
 *
 * @param instance: SAF_EQADC instance
 *        CfifoIdx: CFIFO Index (Index = y)
 *
 * @param [out]Get the current mode of CFIFO.
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint32_t SAF_EQADC_CFCRxGetMode(const uint8_t instance, const uint8_t CfifoIdx)
{
    uint8_t CFCRx = CfifoIdx / 2U;  /* SAF_EQADC CFIFO Control Register x */
    uint32_t CfifoModeCurrent;

    if ((CfifoIdx % 2U) == 0U)
    {
        /* SAF_EQADC CfifoIdx: 0/2/4 */
        CfifoModeCurrent = (*(SAF_EQADC_CFCR[instance][CFCRx]) & SAF_EQADC_CFCR0_MODE0_MASK) >> SAF_EQADC_CFCR0_MODE0_SHIFT;/* polyspace RTE:NIV,IDP */
    }
    else
    {
        /* SAF_EQADC CfifoIdx: 1/3/5 */
        CfifoModeCurrent = (*(SAF_EQADC_CFCR[instance][CFCRx]) & SAF_EQADC_CFCR0_MODE1_MASK) >> SAF_EQADC_CFCR0_MODE1_SHIFT;/* polyspace RTE:NIV,IDP */
    }

    return CfifoModeCurrent;
}

/*******************************************************************************
 * @brief SAF_EQADC CFIFO Control Register x (SAF_EQADC_CFCRx: MODEy)
 *          (x = 0...2, y = 0...5).
 *
 * @param instance: SAF_EQADC instance
 *        CfifoIdx: CFIFO Index (Index = y)
 *        CfifoModeTarget: Set the target mode for CFIFO
 *
 * @note  If MODEy is not disabled, it must not be changed to any other mode
 *          besides disabled. If MODEy is disabled and the CFIFO status is IDLE,
 *          MODEy can be changed to any other mode.
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_EQADC_CFCRxSetMode(const uint8_t instance, const uint8_t CfifoIdx, const uint32_t CfifoModeTarget)
{
    uint8_t CFCRx = CfifoIdx / 2U;  /* SAF_EQADC CFIFO Control Register x */

    if ((CfifoIdx % 2U) == 0U)
    {
        /* SAF_EQADC CfifoIdx: 0/2/4 */
        *(SAF_EQADC_CFCR[instance][CFCRx]) &= ~SAF_EQADC_CFCR0_MODE0_MASK;/* polyspace RTE:NIV,IDP */
        *(SAF_EQADC_CFCR[instance][CFCRx]) |= SAF_EQADC_CFCR0_MODE0(CfifoModeTarget);/* polyspace RTE:NIV,IDP */
    }
    else
    {
        /* SAF_EQADC CfifoIdx: 1/3/5 */
        *(SAF_EQADC_CFCR[instance][CFCRx]) &= ~SAF_EQADC_CFCR0_MODE1_MASK;/* polyspace RTE:NIV,IDP */
        *(SAF_EQADC_CFCR[instance][CFCRx]) |= SAF_EQADC_CFCR0_MODE1(CfifoModeTarget);/* polyspace RTE:NIV,IDP */
    }
}

SAF_ADC_SEC_CODE
static inline uint32_t SAF_EQADC_CFCR0_GetAMode0(const uint8_t instance)
{
    return ((*(SAF_EQADC_CFCR[instance][0U]) & SAF_EQADC_CFCR0_AMODE0_MASK) >> SAF_EQADC_CFCR0_AMODE0_SHIFT);/* polyspace RTE:NIV,IDP */
}

/*******************************************************************************
 * @brief SAF_EQADC CFIFO Control Register 0 (SAF_EQADC_CFCR0: AMODE0)
 *
 * @param instance: SAF_EQADC instance
 *        Cfifo0AdvanceMode0: Set the advance trigger operation mode for CFIFO0
 *
 * @note  If AMODE0 is not disabled, it must not be changed to any other mode
 *          besides disabled.
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_EQADC_CFCR0_SetAMode0(const uint8_t instance, const uint32_t Cfifo0AdvanceMode0)
{
    *(SAF_EQADC_CFCR[instance][0U]) &= ~SAF_EQADC_CFCR0_AMODE0_MASK;/* polyspace RTE:NIV,IDP */
    *(SAF_EQADC_CFCR[instance][0U]) |= SAF_EQADC_CFCR0_AMODE0(Cfifo0AdvanceMode0);/* polyspace RTE:NIV,IDP */
}

/*******************************************************************************
 * @brief SAF_EQADC Interrupt and DMA Control Registers x (SAF_EQADC_IDCRx)(x = 0...2)
 *
 * @param instance: SAF_EQADC instance
 *        FifoIdx: CFIFO/RFIFO Index (0...5)
 *
 * @param [out] IDCRx result(16 bits)
 *
 * @note  The SAF_EQADC Interrupt Control Registers (SAF_EQADC_IDCR) contain bits to
 *          enable the generation of interrupt or DMA requests when the
 *          corresponding flag bits are set in "SAF_EQADC FIFO
 *          and Interrupt Status Registers (SAF_EQADC_FISR)".
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint16_t SAF_EQADC_IDCRx_GetFifoIntDma(const uint8_t instance, const uint8_t FifoIdx)
{
    uint8_t IDCRx = FifoIdx / 2U;  /* SAF_EQADC Interrupt and DMA Control Registers x */
    uint16_t IDCRxData = 0U;

    if ((FifoIdx % 2U) == 0U)
    {
        /* SAF_EQADC FifoIdx: 0/2/4 */
        IDCRxData = (uint16_t)((*(SAF_EQADC_IDCR[instance][IDCRx]) >> 16U) & 0xFFFFU);/* polyspace RTE:NIV,IDP,OBAI */
    }
    else
    {
        /* SAF_EQADC FifoIdx: 1/3/5 */
        IDCRxData = (uint16_t)(*(SAF_EQADC_IDCR[instance][IDCRx]) & 0xFFFFU);/* polyspace RTE:NIV,IDP,OBAI */
    }

    return IDCRxData;
}

/*******************************************************************************
 * @brief SAF_EQADC Interrupt and DMA Control Registers x (SAF_EQADC_IDCRx)(x = 0...2)
 *
 * @param instance: SAF_EQADC instance
 *        FifoIdx: CFIFO/RFIFO Index (0...5)
 *        FifoIntDmaMask: IDCRx mask(16 bits)
 *        EnDis: 0: Disable, 1: Enable;
 *               0: INT, 1: DMA(FifoIntDmaMask = SAF_EQADC_INT_DMA_SEL_xxx)
 *
 * @note  The SAF_EQADC Interrupt Control Registers (SAF_EQADC_IDCR) contain bits to
 *          enable the generation of interrupt or DMA requests when the
 *          corresponding flag bits are set in "SAF_EQADC FIFO
 *          and Interrupt Status Registers (SAF_EQADC_FISR)".
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_EQADC_IDCRx_FifoIntDmaEnDis(const uint8_t instance, const uint8_t FifoIdx, const uint16_t FifoIntDmaMask, const boolean EnDis)
{
    uint8_t IDCRx = FifoIdx / 2U;  /* SAF_EQADC Interrupt and DMA Control Registers x */
    uint8_t IDCRxEnDis = ((FifoIdx % 2U) << 1U) | EnDis;

    switch (IDCRxEnDis)
    {
        case 0U:
            /* SAF_EQADC FifoIdx: 0/2/4, interrupt and DMA disable. */
            *(SAF_EQADC_IDCR[instance][IDCRx]) &= ~((uint32_t)FifoIntDmaMask << 16U);/* polyspace RTE:NIV,IDP */
            break;
        case 1U:
            /* SAF_EQADC FifoIdx: 0/2/4, interrupt and DMA enable. */
            *(SAF_EQADC_IDCR[instance][IDCRx]) |= ((uint32_t)FifoIntDmaMask << 16U);/* polyspace RTE:NIV,IDP */
            break;
        case 2U:
            /* SAF_EQADC FifoIdx: 1/3/5, interrupt and DMA disable. */
            *(SAF_EQADC_IDCR[instance][IDCRx]) &= ~((uint32_t)FifoIntDmaMask);/* polyspace RTE:NIV,IDP */
            break;
        case 3U:
            /* SAF_EQADC FifoIdx: 1/3/5, interrupt and DMA enable. */
            *(SAF_EQADC_IDCR[instance][IDCRx]) |= (uint32_t)FifoIntDmaMask;/* polyspace RTE:NIV,IDP */
            break;
        default:
            /* Nothing to do */
            break;
    }
}

/*******************************************************************************
 * @brief SAF_EQADC CFIFO Transfer Counter Register x (SAF_EQADC_CFTCR)(x = 0...2)
 *
 * @param instance: SAF_EQADC instance
 *        CfifoIdx: CFIFO Index (0...5)
 *
 * @note  TC_CFx counts the number of commands which have been completely
 *          transferred from CFIFOx.
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint16_t SAF_EQADC_CFTCRx_GetCfifoTransCount(const uint8_t instance, const uint8_t CfifoIdx)
{
    uint8_t CFTCRx = CfifoIdx / 2U; /* SAF_EQADC CFIFO Transfer Counter Register x */
    uint16_t TransCount = 0U;

    if ((CfifoIdx % 2U) == 0U)
    {
        /* SAF_EQADC CfifoIdx: 0/2/4 */
        TransCount = (uint16_t)((*(SAF_EQADC_CFTCR[instance][CFTCRx]) & SAF_EQADC_CFTCR0_TC_CF0_MASK) >> SAF_EQADC_CFTCR0_TC_CF0_SHIFT);/* polyspace RTE:NIV,IDP */
    }
    else
    {
        /* SAF_EQADC CfifoIdx: 1/3/5 */
        TransCount = (uint16_t)(*(SAF_EQADC_CFTCR[instance][CFTCRx]) & SAF_EQADC_CFTCR0_TC_CF1_MASK);/* polyspace RTE:NIV,IDP */
    }

    return TransCount;
}

/*******************************************************************************
 * @brief SAF_EQADC CFIFO Transfer Counter Register x (SAF_EQADC_CFTCR)(x = 0...2)
 *
 * @param instance: SAF_EQADC instance
 *        CfifoIdx: CFIFO Index (0...5)
 *        CfifoTransCount: Transfer Counter for CFIFOx
 *
 * @note  TC_CFx counts the number of commands which have been completely
 *          transferred from CFIFOx.
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_EQADC_CFTCRx_SetCfifoTransCount(const uint8_t instance, const uint8_t CfifoIdx, const uint16_t CfifoTransCount)
{
    uint8_t CFTCRx = CfifoIdx / 2U; /* SAF_EQADC CFIFO Transfer Counter Register x */

    if ((CfifoIdx % 2U) == 0U)
    {
        /* SAF_EQADC CfifoIdx: 0/2/4 */
        *(SAF_EQADC_CFTCR[instance][CFTCRx]) = SAF_EQADC_CFTCR0_TC_CF0(CfifoTransCount); /* polyspace RTE:IDP */
    }
    else
    {
        /* SAF_EQADC CfifoIdx: 1/3/5 */
        *(SAF_EQADC_CFTCR[instance][CFTCRx]) = SAF_EQADC_CFTCR0_TC_CF1(CfifoTransCount);    /* PRQA S 2985 */  /* polyspace RTE:IDP */
    }
}

/*******************************************************************************
 * @brief SAF_EQADC CFIFO Status Snapshot Register x: TCB (SAF_EQADC_CFSSR)(x = 0...1)
 *
 * @param instance: SAF_EQADC instance
 *        CfifoIdx: CFIFO Index (0...5)
 *        AdcIdx: 0, 1 (On-chip ADC0 / ADC1)
 *        [out] CFIFO Status
 *
 * @note  CFIFO Status at Transfer to CBuffer0/1.
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint8_t SAF_EQADC_CFSSRx_GetCfifoStatusAtTCB_Snapshot(const uint8_t instance, const uint8_t CfifoIdx, const uint8_t AdcIdx)
{
    uint32_t u32Tcb = (*(SAF_EQADC_CFSSR[instance][AdcIdx]) >> (SAF_EQADC_CFSSR0_CFS0_TCB0_SHIFT - (SAF_EQADC_CFSSR0_CFS0_TCB0_WIDTH * CfifoIdx))); /* polyspace RTE:IDP */

    uint8_t Tcb = (uint8_t)(u32Tcb & (SAF_EQADC_CFSSR0_CFS0_TCB0_MASK >> SAF_EQADC_CFSSR0_CFS0_TCB0_SHIFT));

    return Tcb;
}

/*******************************************************************************
 * @brief SAF_EQADC CFIFO Status Snapshot Register x: LCFTCB
 *          (SAF_EQADC_CFSSR)(x = 0...1)
 *
 * @param instance: SAF_EQADC instance
 *        AdcIdx: 0, 1 (On-chip ADC0 / ADC1)
 *        [out] CFIFO Index (0...5)
 *
 * @note  Last CFIFO to Transfer to CBuffer0/1.
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint8_t SAF_EQADC_CFSSRx_GetLastCfifoToTCB_Snapshot(const uint8_t instance, const uint8_t AdcIdx)
{
    return (uint8_t)((*(SAF_EQADC_CFSSR[instance][AdcIdx]) & SAF_EQADC_CFSSR0_LCFTCB0_MASK) >> SAF_EQADC_CFSSR0_LCFTCB0_SHIFT); /* polyspace RTE:IDP */
}

/*******************************************************************************
 * @brief SAF_EQADC CFIFO Status Snapshot Register x: TC_LCFTCB
 *          (SAF_EQADC_CFSSR)(x = 0...1)
 *
 * @param instance: SAF_EQADC instance
 *        AdcIdx: 0, 1 (On-chip ADC0 / ADC1)
 *        [out] Transfer Counter
 *
 * @note  Transfer Counter for Last CFIFO to transfer commands to CBuffer0/1.
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint16_t SAF_EQADC_CFSSRx_GetTransCountForLastCfifoToTCB_Snapshot(const uint8_t instance, const uint8_t AdcIdx)
{
    return (uint16_t)((*(SAF_EQADC_CFSSR[instance][AdcIdx]) & SAF_EQADC_CFSSR0_TC_LCFTCB0_MASK) >> SAF_EQADC_CFSSR0_TC_LCFTCB0_SHIFT); /* polyspace RTE:IDP */
}

#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
/*******************************************************************************
 * @brief SAF_EQADC Red Line Client Configuration Register (SAF_EQADC_REDLCCR)
 *
 * @param instance: SAF_EQADC instance
 *        ClientIdx: 0 or 1
 *        RedLineTbaseBitSel: Red Line TimeBase Bits Selection m (m=1,2)
 *        RedLineSlotSel: Red Line Server Data Slot Selector m (m=1,2)
 *
 * @note  TC_CFx counts the number of commands which have been completely
 *          transferred from CFIFOx.
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_EQADC_REDLCCR_SetREDBS_SRVx(const uint8_t instance, const uint8_t ClientIdx, const uint8_t RedLineTbaseBitSel, const uint8_t RedLineSlotSel)
{
    /* SAF_EQADC Red Line Client Configuration Register (SAF_EQADC_REDLCCR) */
	SAF_ADC_SEC_CONFIG_DATA
    static vuint32_t * const SAF_EQADC_REDLCCR[ADC_SAF_EQADC_MAX_INSTANCE] =
    {
        &(SAF_EQADC0_PTR->STACCCR.R),
        &(SAF_EQADC1_PTR->STACCCR.R),
        &(SAF_EQADC2_PTR->STACCCR.R),
        &(SAF_EQADC3_PTR->STACCCR.R),
        &(SAF_EQADC4_PTR->STACCCR.R),
#ifdef CCFC3012PT
        &(SAF_EQADC5_PTR->STACCCR.R),
        &(SAF_EQADC6_PTR->STACCCR.R)
#endif
    };

    switch (ClientIdx)
    {
        case 0U:
            *(SAF_EQADC_REDLCCR[instance]) &= ~(SAF_EQADC_STACCCR_SRV1_MASK | SAF_EQADC_STACCCR_STACBS1_MASK); /* polyspace RTE:NIV,IDP */
            *(SAF_EQADC_REDLCCR[instance]) |= (SAF_EQADC_STACCCR_STACBS1(RedLineTbaseBitSel) | SAF_EQADC_STACCCR_SRV1(RedLineSlotSel)); /* PRQA S 2985 */ /* polyspace RTE:NIV,IDP */
            break;
        case 1U:
            *(SAF_EQADC_REDLCCR[instance]) &= ~(SAF_EQADC_STACCCR_SRV2_MASK | SAF_EQADC_STACCCR_STACBS2_MASK); /* polyspace RTE:NIV,IDP */
            *(SAF_EQADC_REDLCCR[instance]) |= (SAF_EQADC_STACCCR_STACBS2(RedLineTbaseBitSel) | SAF_EQADC_STACCCR_SRV2(RedLineSlotSel));/* polyspace RTE:NIV,IDP */
            break;
        default:
            /* Nothing to do */
            break;
    }
}
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */

SAF_ADC_SEC_CODE
static inline uint32_t SAF_EQADC_CFxRw_GetCfifoData(const uint8_t instance, const uint8_t CfifoIdx, const uint8_t EntryIdx)
{
    /* SAF_EQADC CFIFO Registers (SAF_EQADC_CFxRw) (x = 0, .., 5; w = 0, .., 3) */
	SAF_ADC_SEC_CONFIG_DATA
    static vuint32_t * const SAF_EQADC_CFxRw[ADC_SAF_EQADC_MAX_INSTANCE][SAF_EQADC_CFIFO_COUNT] =
    {
        {&(SAF_EQADC0_PTR->CF0R[0U].R), &(SAF_EQADC0_PTR->CF1R[0U].R), &(SAF_EQADC0_PTR->CF2R[0U].R), &(SAF_EQADC0_PTR->CF3R[0U].R), &(SAF_EQADC0_PTR->CF4R[0U].R), &(SAF_EQADC0_PTR->CF5R[0U].R)},
        {&(SAF_EQADC1_PTR->CF0R[0U].R), &(SAF_EQADC1_PTR->CF1R[0U].R), &(SAF_EQADC1_PTR->CF2R[0U].R), &(SAF_EQADC1_PTR->CF3R[0U].R), &(SAF_EQADC1_PTR->CF4R[0U].R), &(SAF_EQADC1_PTR->CF5R[0U].R)},
        {&(SAF_EQADC2_PTR->CF0R[0U].R), &(SAF_EQADC2_PTR->CF1R[0U].R), &(SAF_EQADC2_PTR->CF2R[0U].R), &(SAF_EQADC2_PTR->CF3R[0U].R), &(SAF_EQADC2_PTR->CF4R[0U].R), &(SAF_EQADC2_PTR->CF5R[0U].R)},
        {&(SAF_EQADC3_PTR->CF0R[0U].R), &(SAF_EQADC3_PTR->CF1R[0U].R), &(SAF_EQADC3_PTR->CF2R[0U].R), &(SAF_EQADC3_PTR->CF3R[0U].R), &(SAF_EQADC3_PTR->CF4R[0U].R), &(SAF_EQADC3_PTR->CF5R[0U].R)},
        {&(SAF_EQADC4_PTR->CF0R[0U].R), &(SAF_EQADC4_PTR->CF1R[0U].R), &(SAF_EQADC4_PTR->CF2R[0U].R), &(SAF_EQADC4_PTR->CF3R[0U].R), &(SAF_EQADC4_PTR->CF4R[0U].R), &(SAF_EQADC4_PTR->CF5R[0U].R)},
#ifdef CCFC3012PT
        {&(SAF_EQADC5_PTR->CF0R[0U].R), &(SAF_EQADC5_PTR->CF1R[0U].R), &(SAF_EQADC5_PTR->CF2R[0U].R), &(SAF_EQADC5_PTR->CF3R[0U].R), &(SAF_EQADC5_PTR->CF4R[0U].R), &(SAF_EQADC5_PTR->CF5R[0U].R)},
        {&(SAF_EQADC6_PTR->CF0R[0U].R), &(SAF_EQADC6_PTR->CF1R[0U].R), &(SAF_EQADC6_PTR->CF2R[0U].R), &(SAF_EQADC6_PTR->CF3R[0U].R), &(SAF_EQADC6_PTR->CF4R[0U].R), &(SAF_EQADC6_PTR->CF5R[0U].R)}
#endif
    };

    return (SAF_EQADC_CFxRw[instance][CfifoIdx][EntryIdx] & SAF_EQADC_CF0R_CFIFO0_DATAW_MASK);/* polyspace RTE:NIV,IDP */
}

SAF_ADC_SEC_CODE
static inline uint16_t SAF_EQADC_RFxRw_GetRfifoData(const uint8_t instance, const uint8_t CfifoIdx, const uint8_t EntryIdx)
{
    /* SAF_EQADC RFIFO Registers (SAF_EQADC_RFxRw) (x = 0, .., 5; w = 0, .., 3) */
	SAF_ADC_SEC_CONFIG_DATA
    static vuint32_t * const SAF_EQADC_RFxRw[ADC_SAF_EQADC_MAX_INSTANCE][SAF_EQADC_RFIFO_COUNT] =
    {
        {&(SAF_EQADC0_PTR->RF0R[0U].R), &(SAF_EQADC0_PTR->RF1R[0U].R), &(SAF_EQADC0_PTR->RF2R[0U].R), &(SAF_EQADC0_PTR->RF3R[0U].R), &(SAF_EQADC0_PTR->RF4R[0U].R), &(SAF_EQADC0_PTR->RF5R[0U].R)},
        {&(SAF_EQADC1_PTR->RF0R[0U].R), &(SAF_EQADC1_PTR->RF1R[0U].R), &(SAF_EQADC1_PTR->RF2R[0U].R), &(SAF_EQADC1_PTR->RF3R[0U].R), &(SAF_EQADC1_PTR->RF4R[0U].R), &(SAF_EQADC1_PTR->RF5R[0U].R)},
        {&(SAF_EQADC2_PTR->RF0R[0U].R), &(SAF_EQADC2_PTR->RF1R[0U].R), &(SAF_EQADC2_PTR->RF2R[0U].R), &(SAF_EQADC2_PTR->RF3R[0U].R), &(SAF_EQADC2_PTR->RF4R[0U].R), &(SAF_EQADC2_PTR->RF5R[0U].R)},
        {&(SAF_EQADC3_PTR->RF0R[0U].R), &(SAF_EQADC3_PTR->RF1R[0U].R), &(SAF_EQADC3_PTR->RF2R[0U].R), &(SAF_EQADC3_PTR->RF3R[0U].R), &(SAF_EQADC3_PTR->RF4R[0U].R), &(SAF_EQADC3_PTR->RF5R[0U].R)},
        {&(SAF_EQADC4_PTR->RF0R[0U].R), &(SAF_EQADC4_PTR->RF1R[0U].R), &(SAF_EQADC4_PTR->RF2R[0U].R), &(SAF_EQADC4_PTR->RF3R[0U].R), &(SAF_EQADC4_PTR->RF4R[0U].R), &(SAF_EQADC4_PTR->RF5R[0U].R)},
#ifdef CCFC3012PT
        {&(SAF_EQADC5_PTR->RF0R[0U].R), &(SAF_EQADC5_PTR->RF1R[0U].R), &(SAF_EQADC5_PTR->RF2R[0U].R), &(SAF_EQADC5_PTR->RF3R[0U].R), &(SAF_EQADC5_PTR->RF4R[0U].R), &(SAF_EQADC5_PTR->RF5R[0U].R)},
        {&(SAF_EQADC6_PTR->RF0R[0U].R), &(SAF_EQADC6_PTR->RF1R[0U].R), &(SAF_EQADC6_PTR->RF2R[0U].R), &(SAF_EQADC6_PTR->RF3R[0U].R), &(SAF_EQADC6_PTR->RF4R[0U].R), &(SAF_EQADC6_PTR->RF5R[0U].R)},
#endif
    };

    return (uint16_t)(SAF_EQADC_RFxRw[instance][CfifoIdx][EntryIdx] & SAF_EQADC_RF0R_RFIFO0_DATAW_MASK);/* polyspace RTE:NIV,IDP */
}

#ifdef RESOURCE_SUPPORT_EQADC_SIUL2_TRIG_SRC_LIMIT
#define NUM_OF_EQADC_SIUL2_ISEL_MAPPED      (2U)
#define EQADC_CFIFO_TRIG_MAPPED_INVALID     (0xFFU)
#define EQADC_CFIFO0_ATRIG_MAPPED_INVALID   (0xFFU)
#ifdef CCFC3012PT
SAF_ADC_SEC_VAR_INIT
static uint8_t EQADC_Trig_SIUL_ISEL_Mapped[NUM_OF_EQADC_SIUL2_ISEL_MAPPED][SAF_EQADC_CFIFO_COUNT] =
{
    {
        EQADC_CFIFO_TRIG_MAPPED_INVALID, EQADC_CFIFO_TRIG_MAPPED_INVALID,
        EQADC_CFIFO_TRIG_MAPPED_INVALID, EQADC_CFIFO_TRIG_MAPPED_INVALID,
        EQADC_CFIFO_TRIG_MAPPED_INVALID, EQADC_CFIFO_TRIG_MAPPED_INVALID
    },
    {
        EQADC_CFIFO_TRIG_MAPPED_INVALID, EQADC_CFIFO_TRIG_MAPPED_INVALID,
        EQADC_CFIFO_TRIG_MAPPED_INVALID, EQADC_CFIFO_TRIG_MAPPED_INVALID,
        EQADC_CFIFO_TRIG_MAPPED_INVALID, EQADC_CFIFO_TRIG_MAPPED_INVALID
    }
};

SAF_ADC_SEC_VAR_INIT
static uint8_t EQADC_AdvanceTrig_SIUL_ISEL_Mapped[NUM_OF_EQADC_SIUL2_ISEL_MAPPED] =
{
    EQADC_CFIFO0_ATRIG_MAPPED_INVALID, EQADC_CFIFO0_ATRIG_MAPPED_INVALID
};
#endif
#endif  /* RESOURCE_SUPPORT_EQADC_SIUL2_TRIG_SRC_LIMIT */

#if defined(RESOURCE_SUPPORT_SIUL2_IP)
SAF_ADC_SEC_CODE
static inline void SAF_EQADC_ISELx_SetCfifoTrig(const uint8_t instance, const uint8_t CfifoIdx, const uint8_t TrigSourceVal)
{
	SAF_ADC_SEC_CONFIG_DATA
    static vuint32_t * const SAF_EQADC_TRIG_CFIFO_01[ADC_SAF_EQADC_MAX_INSTANCE] =
    {
        &(SIUL2_PTR->ISEL5.R),    /* SAF_EQADC0_ADC0/SAF_EQADC0_ADC1: CFIFO0/CFIFO1 */
        &(SIUL2_PTR->ISEL5.R),    /* SAF_EQADC1_ADC2/SAF_EQADC1_ADC3: CFIFO0/CFIFO1 */
        &(SIUL2_PTR->ISEL7.R),    /* SAF_EQADC2_ADC4/SAF_EQADC2_ADC5: CFIFO0/CFIFO1 */
        &(SIUL2_PTR->ISEL7.R),    /* SAF_EQADC3_ADC6/SAF_EQADC3_ADC7: CFIFO0/CFIFO1 */
        &(SIUL2_PTR->ISEL7.R)     /* SAF_EQADC4_ADC8/SAF_EQADC4_ADC9: CFIFO0/CFIFO1 */
    };

	SAF_ADC_SEC_CONFIG_DATA
    static vuint32_t * const SAF_EQADC_TRIG_CFIFO_2345[ADC_SAF_EQADC_MAX_INSTANCE] =
    {
        &(SIUL2_PTR->ISEL4.R),    /* SAF_EQADC0_ADC0/SAF_EQADC0_ADC1: CFIFO2/CFIFO3/CFIFO4/CFIFO5 */
        &(SIUL2_PTR->ISEL4.R),    /* SAF_EQADC1_ADC2/SAF_EQADC1_ADC3: CFIFO2/CFIFO3/CFIFO4/CFIFO5 */
        &(SIUL2_PTR->ISEL6.R),    /* SAF_EQADC2_ADC4/SAF_EQADC2_ADC5: CFIFO2/CFIFO3/CFIFO4/CFIFO5 */
        &(SIUL2_PTR->ISEL6.R),    /* SAF_EQADC3_ADC6/SAF_EQADC3_ADC7: CFIFO2/CFIFO3/CFIFO4/CFIFO5 */
        &(SIUL2_PTR->ISEL6.R)     /* SAF_EQADC4_ADC8/SAF_EQADC4_ADC9: CFIFO2/CFIFO3/CFIFO4/CFIFO5 */
    };

    switch (CfifoIdx)
    {
        case 0U:
            /* CFIFO_0 */
            *(SAF_EQADC_TRIG_CFIFO_01[instance]) &= ~0x7F0000U;/* polyspace RTE:NIV,IDP */
            *(SAF_EQADC_TRIG_CFIFO_01[instance]) |= (((uint32_t)(((uint32_t)(TrigSourceVal)) << 16U)) & 0x7F0000U);/* polyspace RTE:NIV,IDP */
            break;
        case 1U:
            /* CFIFO_1 */
            *(SAF_EQADC_TRIG_CFIFO_01[instance]) &= ~0x7F000000U;/* polyspace RTE:NIV,IDP */
            *(SAF_EQADC_TRIG_CFIFO_01[instance]) |= (((uint32_t)(((uint32_t)(TrigSourceVal)) << 24U)) & 0x7F000000U);/* polyspace RTE:NIV,IDP */
            break;
        case 2U:
            /* CFIFO_2 */
            *(SAF_EQADC_TRIG_CFIFO_2345[instance]) &= ~0x7FU;/* polyspace RTE:NIV,IDP */
            *(SAF_EQADC_TRIG_CFIFO_2345[instance]) |= (((uint32_t)(((uint32_t)(TrigSourceVal)) << 0U)) & 0x7FU); /* PRQA S 2985 *//* polyspace RTE:NIV,IDP */
            break;
        case 3U:
            /* CFIFO_3 */
            *(SAF_EQADC_TRIG_CFIFO_2345[instance]) &= ~0x7F00U;/* polyspace RTE:NIV,IDP */
            *(SAF_EQADC_TRIG_CFIFO_2345[instance]) |= (((uint32_t)(((uint32_t)(TrigSourceVal)) << 8U)) & 0x7F00U);/* polyspace RTE:NIV,IDP */
            break;
        case 4U:
            /* CFIFO_4 */
            *(SAF_EQADC_TRIG_CFIFO_2345[instance]) &= ~0x7F0000U;/* polyspace RTE:NIV,IDP */
            *(SAF_EQADC_TRIG_CFIFO_2345[instance]) |= (((uint32_t)(((uint32_t)(TrigSourceVal)) << 16U)) & 0x7F0000U);/* polyspace RTE:NIV,IDP */
            break;
        case 5U:
            /* CFIFO_5 */
            *(SAF_EQADC_TRIG_CFIFO_2345[instance]) &= ~0x7F000000U;/* polyspace RTE:NIV,IDP */
            *(SAF_EQADC_TRIG_CFIFO_2345[instance]) |= (((uint32_t)(((uint32_t)(TrigSourceVal)) << 24U)) & 0x7F000000U);/* polyspace RTE:NIV,IDP */
            break;
        default:
            /* Nothing to do */
            break;
    }
}
#elif defined(RESOURCE_SUPPORT_SIUL_IP)
static inline void SAF_EQADC_ISELx_SetCfifoTrig(const uint8_t instance, const uint8_t CfifoIdx, const uint8_t TrigSourceVal)
{
    static vuint32_t const SAF_EQADC_CfifoTrig_Offset[ADC_SAF_EQADC_MAX_INSTANCE][SAF_EQADC_CFIFO_COUNT] =
    {
        {2u,  1u,  0u , 7u , 6u , 5u }, /* EQADC0_ADC01: CFIFO0~5 */
        {11u, 10u, 9u , 8u , 15u, 14u}, /* EQADC1_ADC23: CFIFO0~5 */
        {12u, 19u, 18u, 17u, 16u, 23u}, /* EQADC2_ADC45: CFIFO0~5 */
        {21u, 20u, 27u, 26u, 25u, 24u}, /* EQADC3_ADC67: CFIFO0~5 */
        {30u, 29u, 28u, 35u, 34u, 33u}, /* EQADC4_ADC89: CFIFO0~5 */
        {39u, 38u, 37u, 36u, 43u, 42u}, /* EQADC5_ADC1011: CFIFO0~5 */
        {40u, 47u, 46u, 45u, 44u, 51u}  /* EQADC6_ADC12: CFIFO0~5 */
    };

    (*(vuint8_t *)(SIUL_BASEADDR + SIUL_ISEL0_OFFSET_ADDR + SAF_EQADC_CfifoTrig_Offset[instance][CfifoIdx])) = (uint8_t)TrigSourceVal;/* polyspace RTE:IDP */
}
#endif

#if defined(RESOURCE_SUPPORT_SIUL2_IP)
SAF_ADC_SEC_CODE
static inline void SAF_EQADC_ISELx_SetCfifo0AdvanceTrig(const uint8_t instance, const uint8_t AdvanceTrigVal)
{
    switch (instance)
    {
        case 0U:
        case 1U:
            /* SAF_EQADC0_ADC0/SAF_EQADC0_ADC1, SAF_EQADC1_ADC2/SAF_EQADC1_ADC3 */
            SIUL2.ISEL9.R &= ~0x1F0000U;
            SIUL2.ISEL9.R |= (((uint32_t)(((uint32_t)(AdvanceTrigVal)) << 16U)) & 0x1F0000U);
            break;
        case 2U:
        case 3U:
        case 4U:
            /* SAF_EQADC2_ADC4/SAF_EQADC2_ADC5, SAF_EQADC3_ADC6/SAF_EQADC3_ADC7, SAF_EQADC4_ADC8/SAF_EQADC4_ADC9 */
            SIUL2.ISEL9.R &= ~0x1FU;
            SIUL2.ISEL9.R |= (((uint32_t)(((uint32_t)(AdvanceTrigVal)) << 0U)) & 0x1FU); /* PRQA S 2985 */
            break;
        default:
            /* Nothing to do */
            break;
    }
}
#elif defined(RESOURCE_SUPPORT_SIUL_IP)
SAF_ADC_SEC_CODE
static inline void SAF_EQADC_ISELx_SetCfifo0AdvanceTrig(const uint8_t instance, const uint8_t AdvanceTrigVal)
{
    static vuint32_t const EQADC_Cfifo0ATrig_Offset[ADC_SAF_EQADC_MAX_INSTANCE] =
    {
        3u, 4u, 13u, 22u, 31u, 32u, 41u /* EQADC instance 0~6 */
    };

    (*(vuint8_t *)(SIUL_BASEADDR + SIUL_ISEL0_OFFSET_ADDR + EQADC_Cfifo0ATrig_Offset[instance])) = (uint8_t)AdvanceTrigVal;/* polyspace RTE:IDP */
}
#else
#endif  /* RESOURCE_SUPPORT_SIUL2_IP */

/*******************************************************************************
 * Static function declaration.
 *******************************************************************************/
static void SAF_EQADC_WriteConfigCmdSSE(const uint8_t instance, const uint8_t CfifoIdx, const uint8_t AdcIdx, const SafEqadc_OnChipAdcRegAddrType AdcAddr, const uint16_t AdcRegVal);
static void SAF_EQADC_ReadConfigCmdSSE(const uint8_t instance, const uint8_t CfifoIdx, const uint8_t AdcIdx, const SafEqadc_OnChipAdcRegAddrType AdcAddr, const uint8_t RfifoIdx);
static status_t SAF_EQADC_DeinitCfifo(const uint8_t instance, const uint8_t CfifoIdx);
#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
static void SAF_EQADC_DeinitRedLineClient(const uint8_t instance, const uint8_t ClientIdx);
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */
static void SAF_EQADC_DeinitAdcCtrl(const uint8_t instance, const uint8_t AdcIdx, const uint8_t CfgCmdCfifoIdx);
static void SAF_EQADC_DeinitAdcTimeConfig(const uint8_t instance, const uint8_t CfgCmdCfifoIdx);
static void SAF_EQADC_DeinitAltConfig(const uint8_t instance, const SafEqadc_AltConfigSelType AltCfgSel, const uint8_t CfgCmdCfifoIdx);
static void SAF_EQADC_DeinitChanPull(const uint8_t instance, const uint8_t AdcChanIdx, const uint8_t CfgCmdCfifoIdx);
static void SAF_EQADC_GetDefaultCfifoCfg(SafEqadc_CfifoConfigType * const CfifoCfgPtr);
static void SAF_EQADC_GetDefaultRwConfigCmd(SafEqadc_ConfigCmdType * const ConfigCmdPtr);
static void SAF_EQADC_GetDefaultConvCmd(SafEqadc_ConvCmdType * const ConvCmdPtr);
static uint32_t SAF_EQADC_GetCfifoRwConfigCmd(const SafEqadc_ConfigCmdType * const ConfigCmdPtr);
static uint32_t SAF_EQADC_GetCfifoConversionCmd(const SafEqadc_ConvCmdType * const ConvCmdPtr);
static void SAF_EQADC_SetAdcConfig(const uint8_t instance, const SafEqadc_AdcConfigType * const AdcConfig, const uint8_t CfgCmdCfifoIdx);
static void SAF_EQADC_SetAltConfig(const uint8_t instance, const SafEqadc_AlternateConfigType * const AltConfig, const uint8_t CfgCmdCfifoIdx);
#ifdef SAF_EQADC_ADC_PUDCR_EN
static void SAF_EQADC_SetPullUpDownConfig(const uint8_t instance, const SafEqadc_PullUpDownCfgType * const PullUpDownCfg, const uint8_t CfgCmdCfifoIdx);
#endif
#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
static void SAF_EQADC_SetRedLineClientConfig(const uint8_t instance, const SafEqadc_RedLineClientConfigType * const RedLineClientCfg);
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */
static status_t SAF_EQADC_SetCfifoConfig(const uint8_t instance, const SafEqadc_CfifoConfigType * const CfifoCfgPtr);
static void SAF_EQADC_SetDmaForCmd(const uint8_t instance, const SafEqadc_CfifoConfigType * const CfifoCfgPtr);
static void SAF_EQADC_SetDmaForResult(const uint8_t instance, const SafEqadc_ResultDmaConfigType * const RfifoCfgPtr);

/*******************************************************************************
 * @brief SAF_EQADC instance base address pointer array
 *******************************************************************************/
SAF_ADC_SEC_CONFIG_DATA
static SAF_EQADC_TagType * const Adc_SafEqadcBase[ADC_SAF_EQADC_MAX_INSTANCE] = SAF_EQADC_BASE_PTR_ARRAY;

/*******************************************************************************
 * @brief SAF_EQADC ADC Alternate Gain Registers Address Array
 *******************************************************************************/
SAF_ADC_SEC_CONFIG_DATA
static const SafEqadc_OnChipAdcRegAddrType AGRxAddr[2U] =
{
    SAF_EQADC_ADC_REG_AGR1,
    SAF_EQADC_ADC_REG_AGR2
};

/*******************************************************************************
 * @brief SAF_EQADC ADC Alternate Offset Registers Address Array
 *******************************************************************************/
SAF_ADC_SEC_CONFIG_DATA
static const SafEqadc_OnChipAdcRegAddrType AORxAddr[2U] =
{
    SAF_EQADC_ADC_REG_AOR1,
    SAF_EQADC_ADC_REG_AOR2
};

/*******************************************************************************
 * @brief SAF_EQADC ADC Calibration Registers Address Array
 *
 * @note  Standard Configuration or alternate configurations 3 to 8:
 *                                    SAF_EQADC_CAL_STANDARD_CONFIG
 *        Alternate configurations 1: SAF_EQADC_CAL_ALT_CONFIG_1
 *        Alternate configurations 2: SAF_EQADC_CAL_ALT_CONFIG_2
 *******************************************************************************/
#define CAL_STD_CFG_IDX         (0U)
#define CAL_ALT1_CFG_IDX        (1U)
#define CAL_ALT2_CFG_IDX        (2U)
#define ADDR_SEL_CAL_GAIN       (0U)
#define ADDR_SEL_CAL_OFFSET     (1U)

/*******************************************************************************
 * @brief SAF_EQADC FIFO DMA Channel status
 *******************************************************************************/
SAF_ADC_SEC_VAR_INIT
static uint8_t DmaMappedChanForCmd[ADC_SAF_EQADC_MAX_INSTANCE][SAF_EQADC_CFIFO_COUNT] =
{
    {
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID
    }
};

SAF_ADC_SEC_VAR_INIT
static uint8_t DmaMappedChanForResult[ADC_SAF_EQADC_MAX_INSTANCE][SAF_EQADC_RFIFO_COUNT] =
{
    {
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID,
        SAF_EQADC_DMA_MAPPED_CHAN_INVALID, SAF_EQADC_DMA_MAPPED_CHAN_INVALID
    }
};

SAF_ADC_SEC_CODE
static inline uint8_t SAF_EQADC_GetAltConfigIdx(SafEqadc_AltConfigSelType AltConfigSel)
{
    uint8_t AcrIdx = 0U;

    if (AltConfigSel != SAF_EQADC_ALT_CONFIG_DISABLE)
    {
        AcrIdx = (uint8_t)(AltConfigSel) - (uint8_t)(SAF_EQADC_ALT_CONFIG_SEL_1);
        SAF_EQADC_DET_ERR(AcrIdx < SAF_EQADC_ALT_CONFIG_NUM); /* PRQA S 4404 */
    }

    return AcrIdx;
}

SAF_ADC_SEC_CODE
static inline SafEqadc_AltConfigSelType SAF_EQADC_GetAltConfigSel(uint8_t AcrIdx)
{
    const uint8_t AltConfigSel = (uint8_t)SAF_EQADC_ALT_CONFIG_SEL_1 + AcrIdx;

    return (SafEqadc_AltConfigSelType)AltConfigSel;
}

SAF_ADC_SEC_CODE
static inline SafEqadc_OnChipAdcRegAddrType SAF_EQADC_GetAltConfigRegAddr(SafEqadc_AltConfigSelType AltConfigSel)
{
    /* SAF_EQADC ADC Alternate Configuration Control Registers Address Array */
    static const SafEqadc_OnChipAdcRegAddrType ACRxAddr[SAF_EQADC_ALT_CONFIG_NUM] =
    {
        SAF_EQADC_ADC_REG_ACR1,
        SAF_EQADC_ADC_REG_ACR2,
        SAF_EQADC_ADC_REG_ACR3,
        SAF_EQADC_ADC_REG_ACR4,
        SAF_EQADC_ADC_REG_ACR5,
        SAF_EQADC_ADC_REG_ACR6,
        SAF_EQADC_ADC_REG_ACR7,
        SAF_EQADC_ADC_REG_ACR8,
        SAF_EQADC_ADC_REG_ACR9,
        SAF_EQADC_ADC_REG_ACR10,
        SAF_EQADC_ADC_REG_ACR11,
        SAF_EQADC_ADC_REG_ACR12,
        SAF_EQADC_ADC_REG_ACR13,
        SAF_EQADC_ADC_REG_ACR14
    };//SEL NUM? TODO
    const uint8_t AcrIdx = SAF_EQADC_GetAltConfigIdx(AltConfigSel);

    return ACRxAddr[AcrIdx]; /* polyspace RTE:OBAI */
}

SAF_ADC_SEC_CODE
void Adc_SafEqadc_LLD_Init(const Adc_SafEqadcConfigType * const ConfigPtr)
{
    SAF_EQADC_DET_ERR(ConfigPtr != NULL); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR(ConfigPtr->SafEqadcHwInst != NULL); /* PRQA S 4404 */

    SafEqadcInstanceType instance = ConfigPtr->SafEqadcHwInst->SafEqadc_HwInstId;
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    uint8_t i;
    status_t status;

    Adc_SafEqadc_LLD_DeInit(instance);

    SAF_EQADC_MCR_SetDebugEnDis((uint8_t)instance, ConfigPtr->SafEqadcHwInst->DebugModeEn);
    SAF_EQADC_ETDFR_SetDFL((uint8_t)instance, ConfigPtr->SafEqadcHwInst->ExtTrigDigitalFilterLen);

    SafEqadc_CfifoConfigType CfifoIdxInitCfgCmd;
    SAF_EQADC_GetDefaultCfifoCfg(&CfifoIdxInitCfgCmd);
    CfifoIdxInitCfgCmd.CfifoIdx     = SAF_EQADC_CFG_CMD_CFIFO_IDX;
    CfifoIdxInitCfgCmd.CfifoMode    = SAF_EQADC_CFIFO_MODE_SINGLE_SW_TRIG;
    status = SAF_EQADC_SetCfifoConfig((uint8_t)instance, &CfifoIdxInitCfgCmd);
    SAF_EQADC_DET_ERR(status == STATUS_SUCCESS); /* PRQA S 4404 */

    /* Init ADC_TSCR */
    SAF_EQADC_WriteConfigCmdSSE((uint8_t)instance, \
                            (uint8_t)(CfifoIdxInitCfgCmd.CfifoIdx), \
                            (uint8_t)SAF_EQADC_ADC_0, \
                            SAF_EQADC_ADC_REG_TSCR, \
                            SAF_EQADC_ADC_TSCR_TBC_CLK_PS(ConfigPtr->SafEqadcHwInst->TimeBasePresDiv)); /* PRQA S 2985 */

    SAF_EQADC_DET_ERR(((ConfigPtr->AdcConfigNum > 0U) && (ConfigPtr->AdcConfigNum <= SAF_EQADC_ADC_NUM)) && /* PRQA S 4404 */ \
            (ConfigPtr->AdcConfigArray != NULL));
#if SAF_EQADC_DET_SUPPORT
//    uint8_t AdcIdx[SAF_EQADC_ADC_NUM] = {0U};
    uint8_t AdcExtMuxEnNum = 0u;
    for (i = 0U; i < ConfigPtr->AdcConfigNum; i++)
    {
//        AdcIdx[i] = (uint8_t)(ConfigPtr->AdcConfigArray[i].AdcIdx);
        AdcExtMuxEnNum += (ConfigPtr->AdcConfigArray[i].AdcExtMuxEn == TRUE) ? 1U : 0U;
    }
    if (ConfigPtr->AdcConfigNum == SAF_EQADC_ADC_NUM)
    {
        SAF_EQADC_DET_ERR((uint8_t)(ConfigPtr->AdcConfigArray[0].AdcIdx) != (uint8_t)(ConfigPtr->AdcConfigArray[1].AdcIdx)); /* PRQA S 4404 */
    }
    /* Note: Both ADC0/1_EMUX bits must not be asserted at the same time. */
    SAF_EQADC_DET_ERR(AdcExtMuxEnNum <= 1U); /* PRQA S 4404 */
#endif

    for (i = 0U; i < ConfigPtr->AdcConfigNum; i++)
    {
        SAF_EQADC_SetAdcConfig((uint8_t)instance, &(ConfigPtr->AdcConfigArray[i]), (uint8_t)(CfifoIdxInitCfgCmd.CfifoIdx));
    }

    if (ConfigPtr->ResultDmaConfigNum > 0U)
    {
        SAF_EQADC_DET_ERR(ConfigPtr->ResultDmaConfigNum <= SAF_EQADC_RFIFO_COUNT); /* PRQA S 4404 */
        SAF_EQADC_DET_ERR(ConfigPtr->ResultDmaConfigArray != NULL); /* PRQA S 4404 */
        for (i = 0U; i < ConfigPtr->ResultDmaConfigNum; i++)
        {
            SAF_EQADC_SetDmaForResult((uint8_t)instance, &(ConfigPtr->ResultDmaConfigArray[i]));
            SAF_EQADC_IDCRx_FifoIntDmaEnDis((uint8_t)instance, \
                    (uint8_t)(ConfigPtr->ResultDmaConfigArray[i].RfifoIdx), \
                    SAF_EQADC_IRQ_DMA_REQ_SEL_RFIFO_DRAIN, \
                    TRUE);
            SAF_EQADC_LLD_DmaEnDis(instance, \
                    (ConfigPtr->ResultDmaConfigArray[i].RfifoIdx), \
                    SAF_EQADC_IRQ_DMA_REQ_EN_RFIFO_DRAIN, \
                    TRUE);
        }
    }

    if (ConfigPtr->AlternateConfigNum > 0U)
    {
        SAF_EQADC_DET_ERR(ConfigPtr->AlternateConfigNum <= SAF_EQADC_ALT_CONFIG_NUM); /* PRQA S 4404 */
        SAF_EQADC_DET_ERR(ConfigPtr->AlternateConfigArray != NULL); /* PRQA S 4404 */
        for (i = 0U; i < ConfigPtr->AlternateConfigNum; i++)
        {
            SAF_EQADC_SetAltConfig((uint8_t)instance, &(ConfigPtr->AlternateConfigArray[i]), (uint8_t)(CfifoIdxInitCfgCmd.CfifoIdx));
        }
    }
#ifdef SAF_EQADC_ADC_PUDCR_EN
    if (ConfigPtr->PullUpDownCfgNum > 0U)
    {
        SAF_EQADC_DET_ERR(ConfigPtr->PullUpDownCfgNum <= SAF_EQADC_PULL_UP_DOWN_CFG_NUM); /* PRQA S 4404 */
        SAF_EQADC_DET_ERR(ConfigPtr->PullUpDownCfgArray != NULL); /* PRQA S 4404 */
        for (i = 0U; i < ConfigPtr->PullUpDownCfgNum; i++)
        {
            SAF_EQADC_SetPullUpDownConfig((uint8_t)instance, &(ConfigPtr->PullUpDownCfgArray[i]), (uint8_t)(CfifoIdxInitCfgCmd.CfifoIdx));
        }
    }
#endif  /* SAF_EQADC_ADC_PUDCR_EN */
#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
    if (ConfigPtr->RedLineClientConfigNum > 0U)
    {
        SAF_EQADC_DET_ERR(ConfigPtr->RedLineClientConfigNum <= SAF_EQADC_RED_LINE_CLIENT_NUM); /* PRQA S 4404 */
        SAF_EQADC_DET_ERR(ConfigPtr->RedLineClientConfigArray != NULL); /* PRQA S 4404 */
        for (i = 0U; i < ConfigPtr->RedLineClientConfigNum; i++)
        {
            SAF_EQADC_SetRedLineClientConfig((uint8_t)instance, &(ConfigPtr->RedLineClientConfigArray[i]));
        }
    }
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */

    SAF_EQADC_DET_ERR(((ConfigPtr->CfifoConfigNum > 0U) && (ConfigPtr->CfifoConfigNum <= SAF_EQADC_CFIFO_COUNT)) && /* PRQA S 4404 */ \
            (ConfigPtr->CfifoConfigArray != NULL));
    for (i = 0U; i < ConfigPtr->CfifoConfigNum; i++)
    {
        status = SAF_EQADC_SetCfifoConfig((uint8_t)instance, &(ConfigPtr->CfifoConfigArray[i]));
        SAF_EQADC_DET_ERR(status == STATUS_SUCCESS); /* PRQA S 4404 */
    }

    uint32_t u32FifoFlagMask;
    for (i = 0U; i < SAF_EQADC_CFIFO_COUNT; i++)
    {
        u32FifoFlagMask = SAF_EQADC_FIFO_FLAG_ALL & ~SAF_EQADC_FIFO_FLAG_CFIFO_FILL;

        if ((SAF_EQADC_IDCRx_GetFifoIntDma((uint8_t)instance, i) & SAF_EQADC_IRQ_DMA_REQ_SEL_CFIFO_FILL) != 0U)
        {
            u32FifoFlagMask &= ~SAF_EQADC_FIFO_FLAG_CFIFO_FILL; /* PRQA S 2984 */
        }

        if ((SAF_EQADC_IDCRx_GetFifoIntDma((uint8_t)instance, i) & SAF_EQADC_IRQ_DMA_REQ_SEL_RFIFO_DRAIN) != 0U)
        {
            u32FifoFlagMask &= ~SAF_EQADC_FIFO_FLAG_RFIFO_DRAIN; /* PRQA S 2984 */
        }

        SAF_EQADC_LLD_ClearFifoIntFlag(instance, (SafEqadcFifoIdxType)i, u32FifoFlagMask);
    }

    for (i = 0U; i < SAF_EQADC_CFIFO_COUNT; i++)
    {
        SAF_EQADC_CFTCRx_SetCfifoTransCount((uint8_t)instance, i, 0U);
    }
    (void)status;
}

SAF_ADC_SEC_CODE
void Adc_SafEqadc_LLD_DeInit(const SafEqadcInstanceType instance)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    status_t status;
    uint8_t i;
    const SafEqadcFifoIdxType CfgCmdCfifoIdx = SAF_EQADC_CFG_CMD_CFIFO_IDX;

    status = SAF_EQADC_DeinitCfifo((uint8_t)instance, (uint8_t)CfgCmdCfifoIdx);
    SAF_EQADC_DET_ERR(status == STATUS_SUCCESS); /* PRQA S 4404 */

    SafEqadc_CfifoConfigType CfifoIdxInitCfgCmd;
    SAF_EQADC_GetDefaultCfifoCfg(&CfifoIdxInitCfgCmd);
    CfifoIdxInitCfgCmd.CfifoIdx     = CfgCmdCfifoIdx;
    CfifoIdxInitCfgCmd.CfifoMode    = SAF_EQADC_CFIFO_MODE_SINGLE_SW_TRIG;
    status = SAF_EQADC_SetCfifoConfig((uint8_t)instance, &CfifoIdxInitCfgCmd);
    SAF_EQADC_DET_ERR(status == STATUS_SUCCESS); /* PRQA S 4404 */

    for (i = 0U; i < SAF_EQADC_ADC_NUM; i++)
    {
        SAF_EQADC_DeinitAdcCtrl((uint8_t)instance, i, (uint8_t)CfgCmdCfifoIdx);
    }

    for (i = 0U; i < SAF_EQADC_RFIFO_COUNT; i++)
    {
        /* Stop eDMA channel */
        if (DmaMappedChanForResult[((uint8_t)instance)][i] != SAF_EQADC_DMA_MAPPED_CHAN_INVALID)
        {
            (void) SAF_EDMA_LLD_ClearChannelRequest(DmaMappedChanForResult[((uint8_t)instance)][i]);
            DmaMappedChanForResult[((uint8_t)instance)][i] = SAF_EQADC_DMA_MAPPED_CHAN_INVALID;
        }

        /* reset SAF_EQADC RFIFO interrupts and DMA select */
        SAF_EQADC_IDCRx_FifoIntDmaEnDis((uint8_t)instance, i, (uint16_t)SAF_EQADC_IRQ_DMA_REQ_SEL_RFIFO_DRAIN, FALSE);
        /* reset SAF_EQADC RFIFO interrupts and DMA enable */
        SAF_EQADC_IDCRx_FifoIntDmaEnDis((uint8_t)instance, i, (uint16_t)(SAF_EQADC_IRQ_EN_RFIFO_OVERFLOW|SAF_EQADC_IRQ_DMA_REQ_EN_RFIFO_DRAIN), FALSE);

        /* Clear data for all RFIFO entries */
        status = SAF_EQADC_LLD_ClearRfifoAllData(instance, (SafEqadcFifoIdxType)i);
        SAF_EQADC_DET_ERR(status == STATUS_SUCCESS); /* PRQA S 4404 */
    }

    for (i = 0U; i < SAF_EQADC_ALT_CONFIG_NUM; i++)
    {
        SAF_EQADC_DeinitAltConfig((uint8_t)instance, SAF_EQADC_GetAltConfigSel(i), (uint8_t)CfgCmdCfifoIdx);
    }

    //ext alt? TODO

    for (i = 0U; i < SAF_EQADC_PULL_UP_DOWN_CFG_NUM; i++)
    {
        SAF_EQADC_DeinitChanPull((uint8_t)instance, i, (uint8_t)CfgCmdCfifoIdx);
    }

#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
    for (i = 0U; i < SAF_EQADC_RED_LINE_CLIENT_NUM; i++)
    {
        SAF_EQADC_DeinitRedLineClient((uint8_t)instance, i);
    }
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */
    SAF_EQADC_DeinitAdcTimeConfig((uint8_t)instance, (uint8_t)CfgCmdCfifoIdx);

    for (i = 0U; i < SAF_EQADC_CFIFO_COUNT; i++)
    {
        status = SAF_EQADC_DeinitCfifo((uint8_t)instance, i);
        SAF_EQADC_DET_ERR(status == STATUS_SUCCESS); /* PRQA S 4404 */
    }

    const uint32_t FifoFlag = SAF_EQADC_FIFO_FLAG_ALL & ~SAF_EQADC_FIFO_FLAG_CFIFO_FILL;
    for (i = 0U; i < SAF_EQADC_CFIFO_COUNT; i++)
    {
        SAF_EQADC_LLD_ClearFifoIntFlag(instance, (SafEqadcFifoIdxType)i, FifoFlag);
    }

    for (i = 0U; i < SAF_EQADC_CFIFO_COUNT; i++)
    {
        SAF_EQADC_CFTCRx_SetCfifoTransCount((uint8_t)instance, i, 0U);
    }
    (void)status;
}

SAF_ADC_SEC_CODE
static uint64_t SAF_EQADC_GetGcc(uint16_t RAW_RES_75P_Vref, uint16_t RAW_RES_25P_Vref)
{
    /* GCC: (CAL_RES75%VREF - CAL_RES25%VREF) / (RAW_RES75%VREF - RAW_RES25%VREF); */
    const uint64_t ExpectedDiffNum_Div14 = (SAF_EQADC_PCT75_VREF_CAL_RES - SAF_EQADC_PCT25_VREF_CAL_RES) << SAF_EQADC_ADC_GCC_FRAC_WIDTH;/*PRQA S 4499*/
    const uint64_t MeasuredDiffNum_Div14 = ((uint64_t)RAW_RES_75P_Vref - (uint64_t)RAW_RES_25P_Vref) << SAF_EQADC_ADC_GCC_FRAC_WIDTH;
    const uint64_t ExpectedDiffNum_Div28 = ExpectedDiffNum_Div14 << SAF_EQADC_ADC_GCC_FRAC_WIDTH; /* PRQA S 2984 */
    const uint64_t u64Gcc = (ExpectedDiffNum_Div28 + (MeasuredDiffNum_Div14 >> 1U)) / MeasuredDiffNum_Div14;/* PRQA S 2834 */ /* polyspace RTE:ZDV */

    return u64Gcc;
}

#if (SAF_EQADC_ADC_OCC_FORM == SAF_EQADC_ADC_OCC_FORM1)
SAF_ADC_SEC_CODE
static int16_t SAF_EQADC_GetOcc(uint64_t u64GainConvCount, uint16_t RAW_RES_75P_Vref)
{
    /* OCC: CAL_RES75%VREF - GCC * RAW_RES75%VREF - 2; */
    const uint64_t ExpectedValue_Div14 = (SAF_EQADC_PCT75_VREF_CAL_RES - 2U) << SAF_EQADC_ADC_GCC_FRAC_WIDTH;/* PRQA S 4499 */
    const int64_t sign64Occ_Div14 = ExpectedValue_Div14 - (u64GainConvCount * ((uint64_t)RAW_RES_75P_Vref)); /* PRQA S 4446 */
    const int16_t sign16_Occ = (int16_t)(sign64Occ_Div14 >> SAF_EQADC_ADC_GCC_FRAC_WIDTH); /* PRQA S 4533 */ /* polyspace RTE:OVFL */

    return sign16_Occ;
}
#else
SAF_ADC_SEC_CODE
static int16_t SAF_EQADC_GetOcc(uint64_t u64GainConvCount, uint16_t RAW_RES_25P_Vref)
{
    /* OCC: CAL_RES25%VREF - GCC * RAW_RES25%VREF - 2; */
    const uint64_t ExpectedValue_Div14 = (SAF_EQADC_PCT25_VREF_CAL_RES - 2U) << SAF_EQADC_ADC_GCC_FRAC_WIDTH;
    const int64_t sign64Occ_Div14 = ExpectedValue_Div14 - (u64GainConvCount * ((uint64_t)RAW_RES_25P_Vref));
    const int16_t sign16_Occ = (int16_t)(sign64Occ_Div14 >> SAF_EQADC_ADC_GCC_FRAC_WIDTH);

    return sign16_Occ;
}
#endif

SAF_ADC_SEC_CODE
void SAF_EQADC_LLD_InternalFuncEn(void)
{
	SAF_SSCM_VRC33_ENABLE |= (SAF_EQADC_PCT_VREF_EN_MSAK | SAF_EQADC_TSENS_EN_MSAK);
}

SAF_ADC_SEC_CODE
status_t SAF_EQADC_LLD_CalibConvResult(const SafEqadcInstanceType instance, const SafEqadcAdcIdxType AdcIdx, SafEqadc_CalibConfigInfoType * const CalCfgPtr)/* PRQA S 2755 */
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)AdcIdx < SAF_EQADC_ADC_NUM); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR(CalCfgPtr != NULL); /* PRQA S 4404 */

    status_t CalStatus = STATUS_SUCCESS;
    const uint8_t Cfifo_x = (uint8_t)(CalCfgPtr->CfifoIdx);
    const uint8_t Rfifo_x = (uint8_t)(CalCfgPtr->RfifoIdx);
    uint32_t u32TimeoutCal, FifoStatusTimeout;
    uint16_t RawResultPct25Vref, RawResultPct75Vref;    /* RAW_RES: measured result values */
    uint8_t CalibCfgSelIdx;

    SAF_EQADC_DET_ERR(Cfifo_x < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR(Rfifo_x < SAF_EQADC_RFIFO_COUNT); /* PRQA S 4404 */

    static const SafEqadc_OnChipAdcRegAddrType CalibAddr[3U][2U] =
    {
        {SAF_EQADC_ADC_REG_GCCR, SAF_EQADC_ADC_REG_OCCR},
        {SAF_EQADC_ADC_REG_AGR1, SAF_EQADC_ADC_REG_AOR1},
        {SAF_EQADC_ADC_REG_AGR2, SAF_EQADC_ADC_REG_AOR2}
    };

    switch (CalCfgPtr->CalibCfgSel)
    {
        case SAF_EQADC_CAL_STANDARD_CONFIG:
            CalibCfgSelIdx = CAL_STD_CFG_IDX;
            break;
        case SAF_EQADC_CAL_ALT_CONFIG_1:
            CalibCfgSelIdx = CAL_ALT1_CFG_IDX;
            break;
        case SAF_EQADC_CAL_ALT_CONFIG_2:
            CalibCfgSelIdx = CAL_ALT2_CFG_IDX;
            break;
        default:
            SAF_EQADC_DET_ERR(FALSE);
            break;
    }

    /* Save Current status */
    /** Save Current RFIFO Drain request control **/
    const uint16_t IntDmaCtrl_RfifoDrain = SAF_EQADC_IDCRx_GetFifoIntDma((uint8_t)instance, Rfifo_x);

    if ((IntDmaCtrl_RfifoDrain & SAF_EQADC_IRQ_DMA_REQ_EN_RFIFO_DRAIN) != 0U)
    {
        SAF_EQADC_IDCRx_FifoIntDmaEnDis((uint8_t)instance, Rfifo_x, SAF_EQADC_IRQ_DMA_REQ_EN_RFIFO_DRAIN, FALSE);
    }

    if ((IntDmaCtrl_RfifoDrain & SAF_EQADC_IRQ_DMA_REQ_SEL_RFIFO_DRAIN) != (uint16_t)SAF_EQADC_FILL_SEL_INT)
    {
        /* Stop eDMA mapped channel */
        if (DmaMappedChanForResult[((uint8_t)instance)][Rfifo_x] != SAF_EQADC_DMA_MAPPED_CHAN_INVALID)
        {
            (void) SAF_EDMA_LLD_ClearChannelRequest(DmaMappedChanForResult[((uint8_t)instance)][Rfifo_x]);
        }

        SAF_EQADC_IDCRx_FifoIntDmaEnDis((uint8_t)instance, Rfifo_x, SAF_EQADC_IRQ_DMA_REQ_SEL_RFIFO_DRAIN, FALSE);
    }

    /** Save Current Mode **/
    const uint32_t CurrentCfifoMode = SAF_EQADC_CFCRxGetMode((uint8_t)instance, Cfifo_x);
    if (CurrentCfifoMode != (uint32_t)SAF_EQADC_CFIFO_MODE_SINGLE_SW_TRIG)
    {
        FifoStatusTimeout = SAF_EQADC_TIMEOUT_COUNT;
        /* set CFIFO mode disabled first */
        SAF_EQADC_CFCRxSetMode((uint8_t)instance, Cfifo_x, (uint32_t)SAF_EQADC_CFIFO_MODE_DISABLE);
        while ((SAF_EQADC_LLD_GetCFifoStatus(instance, (SafEqadcFifoIdxType)Cfifo_x) != SAF_EQADC_CFIFO_STATUS_IDLE) && (FifoStatusTimeout > 0UL))
        {
            FifoStatusTimeout--;
        }
        if (0UL == FifoStatusTimeout)
        {
            return STATUS_TIMEOUT;
        }
        /* invalidate CFIFO all entries */
        SAF_EQADC_CFCRxSetInvalidate((uint8_t)instance, Cfifo_x);
        /* set target CFIFO mode */
        SAF_EQADC_CFCRxSetMode((uint8_t)instance, Cfifo_x, (uint32_t)SAF_EQADC_CFIFO_MODE_SINGLE_SW_TRIG);
    }

    u32TimeoutCal = CalCfgPtr->TimeoutCal;
    while ((SAF_EQADC_LLD_GetFifoFlagStatus(instance, (SafEqadcFifoIdxType)Rfifo_x, SAF_EQADC_FISR_RFIFO_ENTRY_COUNT) != 0U) && (u32TimeoutCal > 0UL))
    {
        (void) SAF_EQADC_LLD_RfifoPopData(instance, (SafEqadcFifoIdxType)Rfifo_x);
        u32TimeoutCal--;
    }

    if (u32TimeoutCal > 0UL)
    {
        SAF_EQADC_LLD_ClearFifoIntFlag(instance, (SafEqadcFifoIdxType)Rfifo_x, SAF_EQADC_FIFO_FLAG_RFIFO_DRAIN);

        SafEqadc_ConvCmdType ConvCmd;
        SAF_EQADC_GetDefaultConvCmd(&ConvCmd);
        ConvCmd.cBufNum         = (uint8_t)AdcIdx;
        ConvCmd.RfifoMsgTag     = (SafEqadc_RfifoMsgTagType)Rfifo_x;
        ConvCmd.LongSampTime    = CalCfgPtr->LongSampTime;
        ConvCmd.ChanNum         = SAF_EQADC_CH_VDD_PCT25_VREF;
        ConvCmd.AltConfigSel    = (SafEqadc_AltConfigSelType)((uint8_t)(CalCfgPtr->CalibCfgSel));
        SAF_EQADC_LLD_CfifoPushConvCmd(instance, (SafEqadcFifoIdxType)Cfifo_x, &ConvCmd);
        SAF_EQADC_LLD_SingleScanEn(instance, (SafEqadcFifoIdxType)Cfifo_x);

        u32TimeoutCal = CalCfgPtr->TimeoutCal;
        while ((SAF_EQADC_LLD_GetFifoFlagStatus(instance, (SafEqadcFifoIdxType)Rfifo_x, SAF_EQADC_FISR_RFIFO_DRAIN) != 1U) && (u32TimeoutCal > 0UL))
        {
            u32TimeoutCal--;
        }

        if (u32TimeoutCal > 0UL)
        {
            RawResultPct25Vref = SAF_EQADC_LLD_RfifoPopData(instance, (SafEqadcFifoIdxType)Rfifo_x);
            SAF_EQADC_LLD_ClearFifoIntFlag(instance, (SafEqadcFifoIdxType)Rfifo_x, SAF_EQADC_FIFO_FLAG_RFIFO_DRAIN);
            SAF_EQADC_LLD_ClearFifoIntFlag(instance, (SafEqadcFifoIdxType)Cfifo_x, SAF_EQADC_FIFO_FLAG_END_OF_QUEUE);

            ConvCmd.ChanNum     = SAF_EQADC_CH_VDD_PCT75_VREF;
            SAF_EQADC_LLD_CfifoPushConvCmd(instance, (SafEqadcFifoIdxType)Cfifo_x, &ConvCmd);
            SAF_EQADC_LLD_SingleScanEn(instance, (SafEqadcFifoIdxType)Cfifo_x);

            u32TimeoutCal = CalCfgPtr->TimeoutCal;
            while ((SAF_EQADC_LLD_GetFifoFlagStatus(instance, (SafEqadcFifoIdxType)Rfifo_x, SAF_EQADC_FISR_RFIFO_DRAIN) != 1U) && (u32TimeoutCal > 0UL))
            {
                u32TimeoutCal--;
            }

            if (u32TimeoutCal > 0UL)
            {
                RawResultPct75Vref = SAF_EQADC_LLD_RfifoPopData(instance, (SafEqadcFifoIdxType)Rfifo_x);
                SAF_EQADC_LLD_ClearFifoIntFlag(instance, (SafEqadcFifoIdxType)Rfifo_x, SAF_EQADC_FIFO_FLAG_RFIFO_DRAIN);
                SAF_EQADC_LLD_ClearFifoIntFlag(instance, (SafEqadcFifoIdxType)Cfifo_x, SAF_EQADC_FIFO_FLAG_END_OF_QUEUE);

                const uint64_t Gcc_Div14 = SAF_EQADC_GetGcc(RawResultPct75Vref, RawResultPct25Vref);
                uint16_t GainConvCount = (uint16_t) Gcc_Div14;
                if (Gcc_Div14 > SAF_EQADC_ADC_GCCR_GCC_MASK)
                {
                    GainConvCount = SAF_EQADC_ADC_GCCR_GCC_MASK;
                    CalStatus = STATUS_ERROR;
                }

#if (SAF_EQADC_ADC_OCC_FORM == SAF_EQADC_ADC_OCC_FORM1)
                const int16_t OffsetConvCount = SAF_EQADC_GetOcc(Gcc_Div14, RawResultPct75Vref);
#else
                const int16_t OffsetConvCount = SAF_EQADC_GetOcc(Gcc_Div14, RawResultPct25Vref);
#endif

                CalCfgPtr->GainCalibConst   = GainConvCount;
                CalCfgPtr->OffsetCalibConst = OffsetConvCount;

                SAF_EQADC_WriteConfigCmdSSE((uint8_t)instance, Cfifo_x, (uint8_t)AdcIdx, CalibAddr[CalibCfgSelIdx][ADDR_SEL_CAL_GAIN], GainConvCount); /* PRQA S 2962 */
                SAF_EQADC_WriteConfigCmdSSE((uint8_t)instance, Cfifo_x, (uint8_t)AdcIdx, CalibAddr[CalibCfgSelIdx][ADDR_SEL_CAL_OFFSET], (uint16_t)OffsetConvCount);

                SAF_EQADC_LLD_ClearFifoIntFlag(instance, (SafEqadcFifoIdxType)Cfifo_x, SAF_EQADC_FIFO_FLAG_END_OF_QUEUE);

                SAF_EQADC_CFTCRx_SetCfifoTransCount((uint8_t)instance, Cfifo_x, 0U);
            }
            else
            {
                CalStatus = STATUS_TIMEOUT;
            }
        }
        else
        {
            CalStatus = STATUS_TIMEOUT;
        }
    }
    else
    {
        CalStatus = STATUS_TIMEOUT;
    }

    /* Restore previous mode */
    if (CurrentCfifoMode != (uint32_t)SAF_EQADC_CFIFO_MODE_SINGLE_SW_TRIG)
    {
        FifoStatusTimeout = SAF_EQADC_TIMEOUT_COUNT;
        /* set CFIFO mode disabled first */
        SAF_EQADC_CFCRxSetMode((uint8_t)instance, Cfifo_x, (uint32_t)SAF_EQADC_CFIFO_MODE_DISABLE);
        while ((SAF_EQADC_LLD_GetCFifoStatus(instance, (SafEqadcFifoIdxType)Cfifo_x) != SAF_EQADC_CFIFO_STATUS_IDLE) && (FifoStatusTimeout > 0UL))
        {
            FifoStatusTimeout--;
        }
        if (0UL == FifoStatusTimeout)
        {
            return STATUS_TIMEOUT;
        }

        /* set target CFIFO mode */
        SAF_EQADC_CFCRxSetMode((uint8_t)instance, Cfifo_x, CurrentCfifoMode);
    }

    if ((IntDmaCtrl_RfifoDrain & SAF_EQADC_IRQ_DMA_REQ_SEL_RFIFO_DRAIN) != (uint16_t)SAF_EQADC_FILL_SEL_INT)
    {
        /* start eDMA mapped channel */
        (void) SAF_EDMA_LLD_SetChannelRequest(DmaMappedChanForResult[((uint8_t)instance)][Rfifo_x]);

        SAF_EQADC_IDCRx_FifoIntDmaEnDis((uint8_t)instance, Rfifo_x, SAF_EQADC_IRQ_DMA_REQ_SEL_RFIFO_DRAIN, TRUE);
    }

    if ((IntDmaCtrl_RfifoDrain & SAF_EQADC_IRQ_DMA_REQ_EN_RFIFO_DRAIN) != 0U)
    {
        SAF_EQADC_IDCRx_FifoIntDmaEnDis((uint8_t)instance, Rfifo_x, SAF_EQADC_IRQ_DMA_REQ_EN_RFIFO_DRAIN, TRUE);
    }

    return CalStatus;
}

SAF_ADC_SEC_CODE
uint8_t SAF_EQADC_LLD_GetImmediateConvCmdEnDis(const SafEqadcInstanceType instance, const SafEqadcAdcIdxType AdcIdx)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)AdcIdx < SAF_EQADC_ADC_NUM); /* PRQA S 4404 */

    return SAF_EQADC_MCR_GetICEAxEnDis((uint8_t)instance, (uint8_t)AdcIdx);
}

SAF_ADC_SEC_CODE
void SAF_EQADC_LLD_SetImmediateConvCmdEnDis(const SafEqadcInstanceType instance, const SafEqadcAdcIdxType AdcIdx, const boolean EnDis)/* PRQA S 1505 */
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)AdcIdx < SAF_EQADC_ADC_NUM); /* PRQA S 4404 */

    SAF_EQADC_MCR_SetICEAxEnDis((uint8_t)instance, (uint8_t)AdcIdx, EnDis);
}

SAF_ADC_SEC_CODE
uint8_t SAF_EQADC_LLD_GetDebugEnDis(const SafEqadcInstanceType instance)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    return SAF_EQADC_MCR_GetDebugEnDis((uint8_t)instance);
}

SAF_ADC_SEC_CODE
void SAF_EQADC_LLD_SetDebugEnDis(const SafEqadcInstanceType instance, const boolean EnDis)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    SAF_EQADC_MCR_SetDebugEnDis((uint8_t)instance, EnDis);
}

SAF_ADC_SEC_CODE
uint8_t SAF_EQADC_LLD_GetExtTrigDigitalFilterLength(const SafEqadcInstanceType instance)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    return SAF_EQADC_ETDFR_GetDFL((uint8_t)instance);
}

SAF_ADC_SEC_CODE
void SAF_EQADC_LLD_SetExtTrigDigitalFilterLength(const SafEqadcInstanceType instance, const uint8_t DigitalFilterLen)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR(DigitalFilterLen <= SAF_EQADC_ETDFR_DFL_MASK); /* PRQA S 4404 */

    SAF_EQADC_ETDFR_SetDFL((uint8_t)instance, DigitalFilterLen);
}

SAF_ADC_SEC_CODE
void SAF_EQADC_LLD_CfifoPushConfigCmd(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx, const SafEqadc_ConfigCmdType * const ConfigCmdPtr)/* PRQA S 1505 */
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)CfifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR(ConfigCmdPtr != NULL); /* PRQA S 4404 */

    *(SAF_EQADC_CFPR[(uint8_t)instance][(uint8_t)CfifoIdx]) = SAF_EQADC_GetCfifoRwConfigCmd(ConfigCmdPtr); /* polyspace RTE:IDP */
}

SAF_ADC_SEC_CODE
void SAF_EQADC_LLD_SetCQueueConfigCmd(const SafEqadc_ConfigCmdType * const ConfigCmdPtr, const uint8_t CmdCount, uint32_t * const CQueueMemDest)
{
    SAF_EQADC_DET_ERR(ConfigCmdPtr != NULL); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR(CQueueMemDest != NULL); /* PRQA S 4404 */

    uint8_t i;

    for (i = 0U; i < CmdCount; i++)
    {
        CQueueMemDest[i] = SAF_EQADC_GetCfifoRwConfigCmd(&(ConfigCmdPtr[i]));
    }
}

SAF_ADC_SEC_CODE
void SAF_EQADC_LLD_CfifoPushConvCmd(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx, const SafEqadc_ConvCmdType * const ConvCmdPtr)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)CfifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR(ConvCmdPtr != NULL); /* PRQA S 4404 */

    SAF_EQADC_TagType * const BasePtr = Adc_SafEqadcBase[(uint8_t)instance];

    BasePtr->CFPR[(uint8_t)CfifoIdx].R = SAF_EQADC_GetCfifoConversionCmd(ConvCmdPtr);/* polyspace RTE:IDP */
}

SAF_ADC_SEC_CODE
void SAF_EQADC_LLD_SetCQueueConvCmd(const SafEqadc_ConvCmdType * const ConvCmdPtr, const uint8_t CmdCount, uint32_t * const CQueueMemDest)
{
    SAF_EQADC_DET_ERR(ConvCmdPtr != NULL); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR(CQueueMemDest != NULL); /* PRQA S 4404 */

    uint8_t i;

    for (i = 0U; i < CmdCount; i++)
    {
        CQueueMemDest[i] = SAF_EQADC_GetCfifoConversionCmd(&(ConvCmdPtr[i]));
    }
}

SAF_ADC_SEC_CODE
uint16_t SAF_EQADC_LLD_RfifoPopData(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType RfifoIdx)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)RfifoIdx < SAF_EQADC_RFIFO_COUNT); /* PRQA S 4404 */

    uint16_t PopData;

    PopData = (uint16_t)((*(SAF_EQADC_RFPR[(uint8_t)instance][(uint8_t)RfifoIdx])) & SAF_EQADC_RFPR_RF_POPX_MASK);/* polyspace RTE:NIV,IDP,OBAI */

    return PopData;
}

SAF_ADC_SEC_CODE
status_t SAF_EQADC_LLD_ClearRfifoAllData(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType RfifoIdx)/* PRQA S 1505 */
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)RfifoIdx < SAF_EQADC_RFIFO_COUNT); /* PRQA S 4404 */

    status_t ret = STATUS_SUCCESS;
    uint8_t RfifoEntryCount;
    uint32_t u32TimeoutClear = SAF_EQADC_TIMEOUT_COUNT;

    /* Save Current RFIFO Drain request control */
    const uint16_t IntDmaCtrl_RfifoDrain = SAF_EQADC_IDCRx_GetFifoIntDma((uint8_t)instance, (uint8_t)RfifoIdx);

    if (((IntDmaCtrl_RfifoDrain & SAF_EQADC_IRQ_DMA_REQ_EN_RFIFO_DRAIN) == 0U) && \
       ((IntDmaCtrl_RfifoDrain & SAF_EQADC_IRQ_DMA_REQ_SEL_RFIFO_DRAIN) == (uint16_t)SAF_EQADC_FILL_SEL_INT))
    {
        RfifoEntryCount = SAF_EQADC_LLD_GetFifoFlagStatus(instance, RfifoIdx, SAF_EQADC_FISR_RFIFO_ENTRY_COUNT);

        while ((RfifoEntryCount != 0U) && (u32TimeoutClear > 0UL))
        {
            (void) SAF_EQADC_LLD_RfifoPopData(instance, RfifoIdx); /* Clear Result data */

            RfifoEntryCount = SAF_EQADC_LLD_GetFifoFlagStatus(instance, RfifoIdx, SAF_EQADC_FISR_RFIFO_ENTRY_COUNT);

            u32TimeoutClear--;
        }

        if (u32TimeoutClear == 0UL)
        {
            ret = STATUS_TIMEOUT;
        }
        else
        {
            SAF_EQADC_LLD_ClearFifoIntFlag(instance, RfifoIdx, (SAF_EQADC_FIFO_FLAG_RFIFO_OVERFLOW | SAF_EQADC_FIFO_FLAG_RFIFO_DRAIN));
        }
    }
    else
    {
        ret = STATUS_ERROR;
    }

    return ret;
}

SAF_ADC_SEC_CODE
void SAF_EQADC_LLD_SingleScanEn(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)CfifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    SAF_EQADC_TagType * const BasePtr = Adc_SafEqadcBase[(uint8_t)instance];
    const uint8_t Cfifo_x = (uint8_t)CfifoIdx;

    if (Cfifo_x < (uint8_t)SAF_EQADC_FIFO_2)
    {
        BasePtr->CFCR0.R |= (((Cfifo_x % 2U) == 0U) ? SAF_EQADC_CFCR0_SSE0_MASK : SAF_EQADC_CFCR0_SSE1_MASK);/* polyspace RTE:NIV,IDP */
    }
    else if (Cfifo_x < (uint8_t)SAF_EQADC_FIFO_4)
    {
        BasePtr->CFCR1.R |= (((Cfifo_x % 2U) == 0U) ? SAF_EQADC_CFCR1_SSE2_MASK : SAF_EQADC_CFCR1_SSE3_MASK);/* polyspace RTE:NIV,IDP */
    }
    else
    {
        BasePtr->CFCR2.R |= (((Cfifo_x % 2U) == 0U) ? SAF_EQADC_CFCR2_SSE4_MASK : SAF_EQADC_CFCR2_SSE5_MASK);/* polyspace RTE:NIV,IDP */
    }
}

SAF_ADC_SEC_CODE
void SAF_EQADC_LLD_SingleScanEn_Sync(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)CfifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    /* SAF_EQADC CfifoIdx synchronous: 0 & 1, 2 & 3, 4 & 5 */
    SAF_EQADC_CFCRxSetSSE_Sync((uint8_t)instance, (uint8_t)CfifoIdx);
}

SAF_ADC_SEC_CODE
status_t SAF_EQADC_LLD_SetCfifoInvalidate(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)CfifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    status_t ret = STATUS_SUCCESS;
    SafEqadc_CfifoModeType CfifoModeCurrent;
    SafEqadc_CfifoStatusType CfifoStatusCurrent;

    CfifoModeCurrent = (SafEqadc_CfifoModeType)SAF_EQADC_CFCRxGetMode((uint8_t)instance, (uint8_t)CfifoIdx);
    CfifoStatusCurrent = SAF_EQADC_LLD_GetCFifoStatus(instance, CfifoIdx);

    if ((CfifoModeCurrent == SAF_EQADC_CFIFO_MODE_DISABLE) && (CfifoStatusCurrent == SAF_EQADC_CFIFO_STATUS_IDLE))
    {
        SAF_EQADC_CFCRxSetInvalidate((uint8_t)instance, (uint8_t)CfifoIdx);
    }
    else
    {
        ret = STATUS_ERROR;
    }

    return ret;
}

SAF_ADC_SEC_CODE
SafEqadc_CfifoModeType SAF_EQADC_LLD_GetCfifoMode(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)CfifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    SafEqadc_CfifoModeType CfifoModeCurrent;

    CfifoModeCurrent = (SafEqadc_CfifoModeType)SAF_EQADC_CFCRxGetMode((uint8_t)instance, (uint8_t)CfifoIdx);

    return CfifoModeCurrent;
}

SAF_ADC_SEC_CODE
status_t SAF_EQADC_LLD_SetCfifoMode(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx, const SafEqadc_CfifoModeType CfifoModeTarget)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)CfifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    status_t status = STATUS_ERROR;
    SafEqadc_CfifoModeType CfifoModeCurrent;
    SafEqadc_CfifoStatusType CfifoStatusCurrent;

    CfifoModeCurrent = (SafEqadc_CfifoModeType)SAF_EQADC_CFCRxGetMode((uint8_t)instance, (uint8_t)CfifoIdx);
    CfifoStatusCurrent = SAF_EQADC_LLD_GetCFifoStatus(instance, CfifoIdx);

    if (CfifoModeTarget != SAF_EQADC_CFIFO_MODE_DISABLE)
    {
        if ((SAF_EQADC_CFIFO_MODE_DISABLE == CfifoModeCurrent) && (SAF_EQADC_CFIFO_STATUS_IDLE == CfifoStatusCurrent))
        {
            status = STATUS_SUCCESS;
        }
    }
    else
    {
        status = STATUS_SUCCESS;
    }

    if (STATUS_SUCCESS == status)
    {
        SAF_EQADC_CFCRxSetMode((uint8_t)instance, (uint8_t)CfifoIdx, (uint32_t)CfifoModeTarget);
    }

    return status;
}

SAF_ADC_SEC_CODE
uint8_t SAF_EQADC_LLD_GetCfifo0EntryExtEnDis(const SafEqadcInstanceType instance)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    return SAF_EQADC_CFCR0_GetCfifo0EntryExtEnDis((uint8_t)instance);
}

SAF_ADC_SEC_CODE
void SAF_EQADC_LLD_SetCfifo0EntryExtEnDis(const SafEqadcInstanceType instance, const boolean EnDis)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    SAF_EQADC_CFCR0_SetCfifo0EntryExtEnDis((uint8_t)instance, EnDis);
}

SAF_ADC_SEC_CODE
SafEqadc_Cfifo0AModeType SAF_EQADC_LLD_GetCfifo0AdvanceMode(const SafEqadcInstanceType instance)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    return ((SafEqadc_Cfifo0AModeType)SAF_EQADC_CFCR0_GetAMode0((uint8_t)instance));
}

SAF_ADC_SEC_CODE
status_t SAF_EQADC_LLD_SetCfifo0AdvanceMode(const SafEqadcInstanceType instance, const SafEqadc_Cfifo0AModeType AdvanceTrigMode)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)AdvanceTrigMode <= (uint8_t)SAF_EQADC_CFIFO0_AMODE_SINGLE_BOTH_EDGES_EXT_TRIG); /* PRQA S 4404 */

    status_t ret = STATUS_SUCCESS;
    SafEqadc_Cfifo0AModeType Cfifo0AModeCurrent;
    SafEqadc_CfifoStatusType CfifoStatusCurrent;

    Cfifo0AModeCurrent = (SafEqadc_Cfifo0AModeType)SAF_EQADC_CFCR0_GetAMode0((uint8_t)instance);
    CfifoStatusCurrent = SAF_EQADC_LLD_GetCFifoStatus(instance, SAF_EQADC_FIFO_0);

    if (AdvanceTrigMode != SAF_EQADC_CFIFO0_AMODE_DISABLE)
    {
        if ((Cfifo0AModeCurrent != SAF_EQADC_CFIFO0_AMODE_DISABLE) || (CfifoStatusCurrent != SAF_EQADC_CFIFO_STATUS_IDLE))
        {
            ret = STATUS_ERROR;
        }
    }

    if (STATUS_SUCCESS == ret)
    {
        SAF_EQADC_CFCR0_SetAMode0((uint8_t)instance, (uint8_t)AdvanceTrigMode);
    }

    return ret;
}

SAF_ADC_SEC_CODE
uint16_t SAF_EQADC_LLD_GetIntDmaCtrlEn(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType FifoIdx)
{
    uint16_t IntDmaCtrl;

    IntDmaCtrl = SAF_EQADC_IDCRx_GetFifoIntDma((uint8_t)instance, (uint8_t)FifoIdx);

    return IntDmaCtrl;
}

SAF_ADC_SEC_CODE
void SAF_EQADC_LLD_IntEnDis(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType FifoIdx, uint16_t IntMask, boolean EnDis)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)FifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((IntMask & ~SAF_EQADC_IRQ_EN_ALL) == 0U); /* PRQA S 4404 */

    uint16_t IntBitMask = IntMask;

    if ((IntMask & SAF_EQADC_IRQ_DMA_REQ_EN_RFIFO_DRAIN) != 0U)
    {
        /* RFIFO Drain has selected DMA */
        if ((SAF_EQADC_IDCRx_GetFifoIntDma((uint8_t)instance, (uint8_t)FifoIdx) & SAF_EQADC_IRQ_DMA_REQ_SEL_RFIFO_DRAIN) != 0U)
        {
            SAF_EQADC_DET_ERR(FALSE);
            IntBitMask &= ~SAF_EQADC_IRQ_DMA_REQ_EN_RFIFO_DRAIN;
        }
    }
    if ((IntMask & SAF_EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL) != 0U)
    {
        /* CFIFO Fill has selected DMA */
        if ((SAF_EQADC_IDCRx_GetFifoIntDma((uint8_t)instance, (uint8_t)FifoIdx) & SAF_EQADC_IRQ_DMA_REQ_SEL_CFIFO_FILL) != 0U)
        {
            SAF_EQADC_DET_ERR(FALSE);
            IntBitMask &= ~SAF_EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL;
        }
    }

    SAF_EQADC_IDCRx_FifoIntDmaEnDis((uint8_t)instance, (uint8_t)FifoIdx, IntBitMask, EnDis);
}

SAF_ADC_SEC_CODE
void SAF_EQADC_LLD_DmaEnDis(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType FifoIdx, uint16_t DmaMask, boolean EnDis)/* PRQA S 1505 */
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)FifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((DmaMask & ~SAF_EQADC_DMA_EN_ALL) == 0U); /* PRQA S 4404 */

    uint16_t DmaBitMask = DmaMask;

    if ((DmaMask & SAF_EQADC_IRQ_DMA_REQ_EN_RFIFO_DRAIN) != 0U)
    {
        /* RFIFO Drain has selected Interrupt */
        if ((SAF_EQADC_IDCRx_GetFifoIntDma((uint8_t)instance, (uint8_t)FifoIdx) & SAF_EQADC_IRQ_DMA_REQ_SEL_RFIFO_DRAIN) == 0U)
        {
            SAF_EQADC_DET_ERR(FALSE);
            DmaBitMask &= ~SAF_EQADC_IRQ_DMA_REQ_EN_RFIFO_DRAIN;
        }
    }
    if ((DmaMask & SAF_EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL) != 0U)
    {
        /* CFIFO Fill has selected Interrupt */
        if ((SAF_EQADC_IDCRx_GetFifoIntDma((uint8_t)instance, (uint8_t)FifoIdx) & SAF_EQADC_IRQ_DMA_REQ_SEL_CFIFO_FILL) == 0U)
        {
            SAF_EQADC_DET_ERR(FALSE);
            DmaBitMask &= ~SAF_EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL;
        }
    }

    SAF_EQADC_IDCRx_FifoIntDmaEnDis((uint8_t)instance, (uint8_t)FifoIdx, DmaBitMask, EnDis);
}

SAF_ADC_SEC_CODE
uint8_t SAF_EQADC_LLD_GetFifoFlagStatus(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType FifoIdx, const SafEqadc_FifoIntStatusType FifoStatusSel)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)FifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    uint8_t FifoStatus = 0U;
    const SAF_EQADC_TagType * const BasePtr = Adc_SafEqadcBase[(uint8_t)instance];
    const uint8_t Fifo_x = (uint8_t)FifoIdx;

    switch (FifoStatusSel)
    {
        case SAF_EQADC_FISR_NON_COHERENCY:
            FifoStatus = (uint8_t)((BasePtr->FISR[Fifo_x].R & SAF_EQADC_FISR_NCFX_MASK) >> SAF_EQADC_FISR_NCFX_SHIFT);
            break;
        case SAF_EQADC_FISR_TRIG_OVERRUN:
            FifoStatus = (uint8_t)((BasePtr->FISR[Fifo_x].R & SAF_EQADC_FISR_TORFX_MASK) >> SAF_EQADC_FISR_TORFX_SHIFT);
            break;
        case SAF_EQADC_FISR_PAUSE:
            FifoStatus = (uint8_t)((BasePtr->FISR[Fifo_x].R & SAF_EQADC_FISR_PFX_MASK) >> SAF_EQADC_FISR_PFX_SHIFT);
            break;
        case SAF_EQADC_FISR_END_OF_QUEUE:
            FifoStatus = (uint8_t)((BasePtr->FISR[Fifo_x].R & SAF_EQADC_FISR_EOQFX_MASK) >> SAF_EQADC_FISR_EOQFX_SHIFT);/* polyspace RTE:NIV,IDP */
            break;
        case SAF_EQADC_FISR_CFIFO_UNDERFLOW:
            FifoStatus = (uint8_t)((BasePtr->FISR[Fifo_x].R & SAF_EQADC_FISR_CFUFX_MASK) >> SAF_EQADC_FISR_CFUFX_SHIFT);
            break;
        case SAF_EQADC_FISR_CFIFO_SINGLE_SCAN:
            FifoStatus = (uint8_t)((BasePtr->FISR[Fifo_x].R & SAF_EQADC_FISR_SSSX_MASK) >> SAF_EQADC_FISR_SSSX_SHIFT);
            break;
        case SAF_EQADC_FISR_CFIFO_FILL:
            FifoStatus = (uint8_t)((BasePtr->FISR[Fifo_x].R & SAF_EQADC_FISR_CFFFX_MASK) >> SAF_EQADC_FISR_CFFFX_SHIFT);
            break;
        case SAF_EQADC_FISR_RFIFO_OVERFLOW:
            FifoStatus = (uint8_t)((BasePtr->FISR[Fifo_x].R & SAF_EQADC_FISR_RFOFX_MASK) >> SAF_EQADC_FISR_RFOFX_SHIFT);
            break;
        case SAF_EQADC_FISR_RFIFO_DRAIN:
            FifoStatus = (uint8_t)((BasePtr->FISR[Fifo_x].R & SAF_EQADC_FISR_RFDFX_MASK) >> SAF_EQADC_FISR_RFDFX_SHIFT);/* polyspace RTE:NIV,OBAI,IDP */
            break;
        case SAF_EQADC_FISR_CFIFO_ENTRY_COUNT:
            FifoStatus = (uint8_t)((BasePtr->FISR[Fifo_x].R & SAF_EQADC_FISR_CFCTRX_MASK) >> SAF_EQADC_FISR_CFCTRX_SHIFT);
            break;
        case SAF_EQADC_FISR_CFIFO_TRANS_NEXT_PTR:
            FifoStatus = (uint8_t)((BasePtr->FISR[Fifo_x].R & SAF_EQADC_FISR_TNXTPTRX_MASK) >> SAF_EQADC_FISR_TNXTPTRX_SHIFT);
            break;
        case SAF_EQADC_FISR_RFIFO_ENTRY_COUNT:
            FifoStatus = (uint8_t)((BasePtr->FISR[Fifo_x].R & SAF_EQADC_FISR_RFCTRX_MASK) >> SAF_EQADC_FISR_RFCTRX_SHIFT);/* polyspace RTE:NIV,OBAI,IDP */
            break;
        case SAF_EQADC_FISR_RFIFO_POP_NEXT_PTR:
            FifoStatus = (uint8_t)((BasePtr->FISR[Fifo_x].R & SAF_EQADC_FISR_POPNXTPTRX_MASK) >> SAF_EQADC_FISR_POPNXTPTRX_SHIFT);
            break;
        default:
            SAF_EQADC_DET_ERR(FALSE);
            break;
    }

    return FifoStatus;
}

SAF_ADC_SEC_CODE
uint32_t SAF_EQADC_LLD_GetFifoIntFlag(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType FifoIdx)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)FifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    uint32_t FifoFlagMask;
    const SAF_EQADC_TagType * const BasePtr = Adc_SafEqadcBase[(uint8_t)instance];

    FifoFlagMask = BasePtr->FISR[(uint8_t)FifoIdx].R & SAF_EQADC_FIFO_FLAG_ALL;/* polyspace RTE:NIV,IDP */

    return FifoFlagMask;
}

SAF_ADC_SEC_CODE
void SAF_EQADC_LLD_ClearFifoIntFlag(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType FifoIdx, uint32_t FifoFlagMask)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)FifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((FifoFlagMask & ~SAF_EQADC_FIFO_FLAG_ALL) == 0U); /* PRQA S 4404 */

    SAF_EQADC_TagType * const BasePtr = Adc_SafEqadcBase[(uint8_t)instance];

    uint32_t FifoFlagBitMask = FifoFlagMask;

    if ((FifoFlagMask & SAF_EQADC_FIFO_FLAG_CFIFO_FILL) != 0U)
    {
        if ((SAF_EQADC_IDCRx_GetFifoIntDma((uint8_t)instance, (uint8_t)FifoIdx) & SAF_EQADC_IRQ_DMA_REQ_SEL_CFIFO_FILL) != 0U)
        {
            SAF_EQADC_DET_ERR(FALSE);
            FifoFlagBitMask &= ~SAF_EQADC_FIFO_FLAG_CFIFO_FILL;
        }
    }
    if ((FifoFlagMask & SAF_EQADC_FIFO_FLAG_RFIFO_DRAIN) != 0U)
    {
        if ((SAF_EQADC_IDCRx_GetFifoIntDma((uint8_t)instance, (uint8_t)FifoIdx) & SAF_EQADC_IRQ_DMA_REQ_SEL_RFIFO_DRAIN) != 0U)
        {
            SAF_EQADC_DET_ERR(FALSE);
            FifoFlagBitMask &= ~SAF_EQADC_FIFO_FLAG_RFIFO_DRAIN;
        }
    }

    BasePtr->FISR[(uint8_t)FifoIdx].R = FifoFlagBitMask; /* w1c */  /* polyspace RTE:OBAI,IDP */
}

SAF_ADC_SEC_CODE
uint16_t SAF_EQADC_LLD_GetCfifoTransferCounter(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)CfifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    return SAF_EQADC_CFTCRx_GetCfifoTransCount((uint8_t)instance, (uint8_t)CfifoIdx);
}

SAF_ADC_SEC_CODE
void SAF_EQADC_LLD_SetCfifoTransferCounter(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx, const uint16_t TransCount)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)CfifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR(TransCount <= SAF_EQADC_CFTCR0_TC_CF1_MASK); /* PRQA S 4404 */

    SAF_EQADC_CFTCRx_SetCfifoTransCount((uint8_t)instance, (uint8_t)CfifoIdx, TransCount);
}

SAF_ADC_SEC_CODE
SafEqadc_CfifoStatusType SAF_EQADC_LLD_GetCFifoStatusSnapshot(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx, const SafEqadcAdcIdxType AdcIdx)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)CfifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)AdcIdx < SAF_EQADC_ADC_NUM); /* PRQA S 4404 */

    SafEqadc_CfifoStatusType CfifoStatus;

    CfifoStatus = (SafEqadc_CfifoStatusType)SAF_EQADC_CFSSRx_GetCfifoStatusAtTCB_Snapshot((uint8_t)instance, (uint8_t)CfifoIdx, (uint8_t)AdcIdx);

    return CfifoStatus;
}

SAF_ADC_SEC_CODE
SafEqadcFifoIdxType SAF_EQADC_LLD_GetLastCFifoSnapshot(const SafEqadcInstanceType instance, const SafEqadcAdcIdxType AdcIdx)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)AdcIdx < SAF_EQADC_ADC_NUM); /* PRQA S 4404 */

    SafEqadcFifoIdxType Cfifo_x;

    Cfifo_x = (SafEqadcFifoIdxType)SAF_EQADC_CFSSRx_GetLastCfifoToTCB_Snapshot((uint8_t)instance, (uint8_t)AdcIdx);

    return Cfifo_x;
}

SAF_ADC_SEC_CODE
uint16_t SAF_EQADC_LLD_GetTransCountLastCFifoSnapshot(const SafEqadcInstanceType instance, const SafEqadcAdcIdxType AdcIdx)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)AdcIdx < SAF_EQADC_ADC_NUM); /* PRQA S 4404 */

    uint16_t TransferCount;

    TransferCount = SAF_EQADC_CFSSRx_GetTransCountForLastCfifoToTCB_Snapshot((uint8_t)instance, (uint8_t)AdcIdx);

    return TransferCount;
}

SAF_ADC_SEC_CODE
SafEqadc_CfifoStatusType SAF_EQADC_LLD_GetCFifoStatus(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx)/* PRQA S 1505 */
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)CfifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    const SAF_EQADC_TagType * const BasePtr = Adc_SafEqadcBase[(uint8_t)instance];
    uint8_t CfifoStatus = (uint8_t)SAF_EQADC_CFIFO_STATUS_IDLE;
    uint32_t SAF_EQADC_CFSR_CFSx_MaskVal = SAF_EQADC_CFSR_CFS0_MASK >> ((uint8_t)CfifoIdx * 2U);
    uint8_t SAF_EQADC_CFSR_CFSx_ShiftVal = SAF_EQADC_CFSR_CFS0_SHIFT - ((uint8_t)CfifoIdx * 2U);

    CfifoStatus = (uint8_t)((BasePtr->CFSR.R & SAF_EQADC_CFSR_CFSx_MaskVal) >> SAF_EQADC_CFSR_CFSx_ShiftVal);/* polyspace RTE:NIV,IDP */

    return (SafEqadc_CfifoStatusType)CfifoStatus;
}

SAF_ADC_SEC_CODE
#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
void SAF_EQADC_LLD_SetRedLineClientConfig(const SafEqadcInstanceType instance, const uint8_t ClientIdx, const SafEqadc_RedLineBitsSelType RedLineTbaseBitSel, const SafEqadc_RedLineServerDataSlotSelType RedLineSlotSel)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR(ClientIdx <= SAF_EQADC_STAC_BUS_CLIENT_2); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)RedLineTbaseBitSel <= (uint8_t)SAF_EQADC_REDLINE_BITS_SEL_TBASE_8_23); /* PRQA S 4404 */

    SAF_EQADC_REDLCCR_SetREDBS_SRVx((uint8_t)instance, ClientIdx, (uint8_t)RedLineTbaseBitSel, (uint8_t)RedLineSlotSel);
}
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */

SAF_ADC_SEC_CODE
uint32_t SAF_EQADC_LLD_GetCfifoEntryData(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx, const uint8_t EntryIdx)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)CfifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR(EntryIdx < SAF_EQADC_CFIFO_ENTRY_COUNT); /* PRQA S 4404 */

    return SAF_EQADC_CFxRw_GetCfifoData((uint8_t)instance, (uint8_t)CfifoIdx, EntryIdx);
}

SAF_ADC_SEC_CODE
uint32_t SAF_EQADC_LLD_GetCfifo0ExtEntryData(const SafEqadcInstanceType instance, const uint8_t EntryIdx)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR(EntryIdx < SAF_EQADC_CFIFO_ENTRY_COUNT); /* PRQA S 4404 */

    const SAF_EQADC_TagType * const BasePtr = Adc_SafEqadcBase[(uint8_t)instance];

    uint32_t Cfifo0ExtData;

    Cfifo0ExtData = BasePtr->CF0ER[EntryIdx].R;/* polyspace RTE:NIV,OBAI,IDP */

    return Cfifo0ExtData;
}

SAF_ADC_SEC_CODE
uint32_t SAF_EQADC_LLD_GetRfifoEntryData(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType RfifoIdx, const uint8_t EntryIdx)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)RfifoIdx < SAF_EQADC_RFIFO_COUNT); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR(EntryIdx < SAF_EQADC_RFIFO_ENTRY_COUNT); /* PRQA S 4404 */

    return SAF_EQADC_RFxRw_GetRfifoData((uint8_t)instance, (uint8_t)RfifoIdx, EntryIdx);
}

SAF_ADC_SEC_CODE
void SAF_EQADC_LLD_SetCfifoHwTrigSource(const SafEqadcInstanceType instance, const SafEqadcFifoIdxType CfifoIdx, const SafEqadc_HwTrigSourceSelType TrigSourceSel)/* PRQA S 1505 */
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)CfifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    switch (TrigSourceSel)
    {
        case SAF_EQADC_HW_TRIG_NOT_CONNECTED:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_NULL_VAL);
            break;
        case SAF_EQADC_HW_TRIG_RTI:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_RTI_VAL);
            break;
        case SAF_EQADC_HW_TRIG_PIT0_CH0:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_PIT0_CH0_VAL);
            break;
        case SAF_EQADC_HW_TRIG_PIT0_CH1:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_PIT0_CH1_VAL);
            break;
        case SAF_EQADC_HW_TRIG_PIT1_CH0:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_PIT1_CH0_VAL);
            break;
        case SAF_EQADC_HW_TRIG_PIT1_CH1:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_PIT1_CH1_VAL);
            break;
        case SAF_EQADC_HW_TRIG_ETRIG0:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_ETRIG0_VAL((uint8_t)CfifoIdx));
            break;
        case SAF_EQADC_HW_TRIG_ETRIG1:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_ETRIG1_VAL((uint8_t)CfifoIdx));
            break;
        case SAF_EQADC_HW_TRIG_ETPUA28:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_ETPUA28_VAL);
            break;
        case SAF_EQADC_HW_TRIG_ETPUA29:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_ETPUA29_VAL);
            break;
        case SAF_EQADC_HW_TRIG_ETPUA30:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_ETPUA30_VAL);
            break;
        case SAF_EQADC_HW_TRIG_ETPUA31:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_ETPUA31_VAL);
            break;
        case SAF_EQADC_HW_TRIG_ETPUB28:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_ETPUB28_VAL);
            break;
        case SAF_EQADC_HW_TRIG_ETPUB29:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_ETPUB29_VAL);
            break;
        case SAF_EQADC_HW_TRIG_ETPUB30:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_ETPUB30_VAL);
            break;
        case SAF_EQADC_HW_TRIG_ETPUB31:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_ETPUB31_VAL);
            break;
        case SAF_EQADC_HW_TRIG_ETPUC28:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_ETPUC28_VAL);
            break;
        case SAF_EQADC_HW_TRIG_ETPUC29:
             SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_ETPUC29_VAL);
             break;
        case SAF_EQADC_HW_TRIG_ETPUC30:
             SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_ETPUC30_VAL);
             break;
        case SAF_EQADC_HW_TRIG_ETPUC31:
             SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_ETPUC31_VAL);
             break;
        case SAF_EQADC_HW_TRIG_EMIOS0_CH16:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_EMIOS0_CH16_VAL);
            break;
        case SAF_EQADC_HW_TRIG_EMIOS0_CH17:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_EMIOS0_CH17_VAL);
            break;
        case SAF_EQADC_HW_TRIG_EMIOS0_CH18:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_EMIOS0_CH18_VAL);
            break;
        case SAF_EQADC_HW_TRIG_EMIOS0_CH19:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_EMIOS0_CH19_VAL);
            break;
        case SAF_EQADC_HW_TRIG_EMIOS0_CH20:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_EMIOS0_CH20_VAL);
            break;
        case SAF_EQADC_HW_TRIG_EMIOS0_CH21:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_EMIOS0_CH21_VAL);
            break;
        case SAF_EQADC_HW_TRIG_EMIOS0_CH22:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_EMIOS0_CH22_VAL);
            break;
        case SAF_EQADC_HW_TRIG_EMIOS0_CH23:
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_EMIOS0_CH23_VAL);
            break;
        case SAF_EQADC_HW_TRIG_ETPUA7:
            SAF_EQADC_DET_ERR((uint8_t)CfifoIdx == (uint8_t)SAF_EQADC_FIFO_1); /* PRQA S 4404 */
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_ETPUA7_VAL);
            break;
        case SAF_EQADC_HW_TRIG_ETPUA14:
            SAF_EQADC_DET_ERR((uint8_t)CfifoIdx == (uint8_t)SAF_EQADC_FIFO_2); /* PRQA S 4404 */
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_ETPUA14_VAL);
            break;
        case SAF_EQADC_HW_TRIG_ETPUA22:
            SAF_EQADC_DET_ERR((uint8_t)CfifoIdx == (uint8_t)SAF_EQADC_FIFO_3); /* PRQA S 4404 */
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_ETPUA22_VAL);
            break;
        case SAF_EQADC_HW_TRIG_ETPUA26:
            SAF_EQADC_DET_ERR((uint8_t)CfifoIdx == (uint8_t)SAF_EQADC_FIFO_5); /* PRQA S 4404 */
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_ETPUA26_VAL);
            break;
        case SAF_EQADC_HW_TRIG_ETPUA27:
            SAF_EQADC_DET_ERR((uint8_t)CfifoIdx == (uint8_t)SAF_EQADC_FIFO_4); /* PRQA S 4404 */
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_ETPUA27_VAL);
            break;
        case SAF_EQADC_HW_TRIG_EMIOS1_CH2:
            SAF_EQADC_DET_ERR((uint8_t)CfifoIdx == (uint8_t)SAF_EQADC_FIFO_0); /* PRQA S 4404 */
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_EMIOS1_CH2_VAL);
            break;
        case SAF_EQADC_HW_TRIG_EMIOS1_CH3:
            SAF_EQADC_DET_ERR((uint8_t)CfifoIdx == (uint8_t)SAF_EQADC_FIFO_1); /* PRQA S 4404 */
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_EMIOS1_CH3_VAL);
            break;
        case SAF_EQADC_HW_TRIG_EMIOS1_CH4:
            SAF_EQADC_DET_ERR((uint8_t)CfifoIdx == (uint8_t)SAF_EQADC_FIFO_5); /* PRQA S 4404 */
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_EMIOS1_CH4_VAL);
            break;
        case SAF_EQADC_HW_TRIG_EMIOS1_CH5:
            SAF_EQADC_DET_ERR((uint8_t)CfifoIdx == (uint8_t)SAF_EQADC_FIFO_4); /* PRQA S 4404 */
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_EMIOS1_CH5_VAL);
            break;
        case SAF_EQADC_HW_TRIG_EMIOS1_CH6:
            SAF_EQADC_DET_ERR((uint8_t)CfifoIdx == (uint8_t)SAF_EQADC_FIFO_3); /* PRQA S 4404 */
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_EMIOS1_CH6_VAL);
            break;
        case SAF_EQADC_HW_TRIG_EMIOS1_CH7:
            SAF_EQADC_DET_ERR((uint8_t)CfifoIdx == (uint8_t)SAF_EQADC_FIFO_2); /* PRQA S 4404 */
            SAF_EQADC_ISELx_SetCfifoTrig((uint8_t)instance, (uint8_t)CfifoIdx, SAF_EQADC_TRIG_EMIOS1_CH7_VAL);
            break;
        default:
            SAF_EQADC_DET_ERR(FALSE);
            break;
    }
}

#if defined(RESOURCE_SUPPORT_SIUL2_IP)
SAF_ADC_SEC_CODE
void SAF_EQADC_LLD_SetCfifo0AdvanceTrigSource(const SafEqadcInstanceType instance, const SafEqadc_AdvanceTrigSourceSelType AdvTrigSourceSel)/* PRQA S 1505 */
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    switch (AdvTrigSourceSel)
    {
        case SAF_EQADC_ADVANCE_TRIG_NOT:
            SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, SAF_EQADC_ATRIG_NULL_VALUE);
            break;
        case SAF_EQADC_ATRIG_RTI:
            SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, SAF_EQADC_ATRIG_RTI_VALUE);
            break;
        case SAF_EQADC_ATRIG_PIT0_CH0:
            SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, SAF_EQADC_ATRIG_PIT0_CH0_VALUE);
            break;
        case SAF_EQADC_ATRIG_PIT0_CH1:
            SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, SAF_EQADC_ATRIG_PIT0_CH1_VALUE);
            break;
        case SAF_EQADC_ATRIG_PIT1_CH0:
            SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, SAF_EQADC_ATRIG_PIT1_CH0_VALUE);
            break;
        case SAF_EQADC_ATRIG_PIT1_CH1:
            SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, SAF_EQADC_ATRIG_PIT1_CH1_VALUE);
            break;
        case SAF_EQADC_ATRIG_ETPUA30_PIT0_CH0:
            SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, SAF_EQADC_ATRIG_ETPUA30_PIT0_CH0_VAL);
            break;
        case SAF_EQADC_ATRIG_ETPUA30_PIT0_CH1:
            SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, SAF_EQADC_ATRIG_ETPUA30_PIT0_CH1_VAL);
            break;
        case SAF_EQADC_ATRIG_ETPUA28:
            SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, SAF_EQADC_ATRIG_ETPUA28_VAL);
            break;
        case SAF_EQADC_ATRIG_ETPUA29:
            SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, SAF_EQADC_ATRIG_ETPUA29_VAL);
            break;
        case SAF_EQADC_ATRIG_ETPUA30:
            SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, SAF_EQADC_ATRIG_ETPUA30_VAL);
            break;
        case SAF_EQADC_ATRIG_ETPUA31:
            SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, SAF_EQADC_ATRIG_ETPUA31_VAL);
            break;
        case SAF_EQADC_ATRIG_ETPUC28:
            SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, SAF_EQADC_ATRIG_ETPUC28_VAL);
            break;
        case SAF_EQADC_ATRIG_ETPUC29:
            SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, SAF_EQADC_ATRIG_ETPUC29_VAL);
            break;
        case SAF_EQADC_ATRIG_ETPUC30:
            SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, SAF_EQADC_ATRIG_ETPUC30_VAL);
            break;
        case SAF_EQADC_ATRIG_ETPUC31:
            SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, SAF_EQADC_ATRIG_ETPUC31_VAL);
            break;
        case SAF_EQADC_ATRIG_EMIOS1_CH2_PIT1_CH0:
            SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, SAF_EQADC_ATRIG_EMIOS1CH2_PIT1CH0_VAL);
            break;
        case SAF_EQADC_ATRIG_EMIOS1_CH2_PIT1_CH1:
            SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, SAF_EQADC_ATRIG_EMIOS1CH2_PIT1CH1_VAL);
            break;
        case SAF_EQADC_ATRIG_EMIOS0_CH23:
            SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, SAF_EQADC_ATRIG_EMIOS0_CH23_VAL);
            break;
        default:
            SAF_EQADC_DET_ERR(FALSE);
            break;
    }
}
#elif defined(RESOURCE_SUPPORT_SIUL_IP)
void SAF_EQADC_LLD_SetCfifo0AdvanceTrigSource(const SafEqadcInstanceType instance, const uint8_t AdvTrigSourceSel)/* PRQA S 1505 */
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE);  /* PRQA S 4404 */

#if defined(RESOURCE_SUPPORT_SIUL2_IP)
    uint8_t ret;
    ret = EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, AdvTrigSourceSel);
    SAF_EQADC_DET_ERR(ret == TRUE);/* PRQA S 4404 */
#elif defined(RESOURCE_SUPPORT_SIUL_IP)
    SAF_EQADC_ISELx_SetCfifo0AdvanceTrig((uint8_t)instance, AdvTrigSourceSel);
#else
#endif  /* RESOURCE_SUPPORT_SIUL2_IP */
}
#else
#endif

#if SAF_EQADC_ONCHIPADC_RW_LLD
SAF_ADC_SEC_CODE
void SAF_EQADC_LLD_SetAdcRegValueSSE(const SafEqadcInstanceType instance, const SafEqadcAdcIdxType AdcIdx, const SafEqadcFifoIdxType CfifoIdx, const SafEqadc_OnChipAdcRegAddrType AdcReg, const uint16_t AdcRegVal)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)CfifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    uint32_t TestTimeout = SAF_EQADC_TIMEOUT_COUNT;

    SAF_EQADC_WriteConfigCmdSSE((uint8_t)instance, (uint8_t)CfifoIdx, (uint8_t)AdcIdx, AdcReg, AdcRegVal);

    while ((SAF_EQADC_LLD_GetFifoFlagStatus(instance, CfifoIdx, SAF_EQADC_FISR_END_OF_QUEUE) != 1U) && (TestTimeout > 0UL))
    {
        TestTimeout--;
    }
    SAF_EQADC_DET_ERR(TestTimeout > 0UL); /* PRQA S 4404 */

    /* Clear Flag */
    SAF_EQADC_LLD_ClearFifoIntFlag(instance, CfifoIdx, SAF_EQADC_FIFO_FLAG_END_OF_QUEUE);
}

SAF_ADC_SEC_CODE
uint16_t SAF_EQADC_LLD_GetAdcRegValueSSE(const SafEqadcInstanceType instance, const SafEqadcAdcIdxType AdcIdx, const SafEqadcFifoIdxType CfifoIdx, const SafEqadcFifoIdxType RfifoIdx, const SafEqadc_OnChipAdcRegAddrType AdcReg)
{
    SAF_EQADC_DET_ERR((uint8_t)instance < ADC_SAF_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)CfifoIdx < SAF_EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    SAF_EQADC_DET_ERR((uint8_t)RfifoIdx < SAF_EQADC_RFIFO_COUNT); /* PRQA S 4404 */

    uint16_t AdcRegVal = 0xFFFFU;
    uint32_t TestTimeout = SAF_EQADC_TIMEOUT_COUNT;

    SAF_EQADC_ReadConfigCmdSSE((uint8_t)instance, (uint8_t)CfifoIdx, (uint8_t)AdcIdx, AdcReg, (uint8_t)RfifoIdx);

    while ((SAF_EQADC_LLD_GetFifoFlagStatus(instance, RfifoIdx, SAF_EQADC_FISR_RFIFO_DRAIN) != 1U) && (TestTimeout > 0UL))
    {
        TestTimeout--;
    }

    if (TestTimeout > 0UL)
    {
        /* Pop Rfifo result data */
        AdcRegVal = SAF_EQADC_LLD_RfifoPopData(instance, RfifoIdx);
    }
    SAF_EQADC_DET_ERR(TestTimeout > 0UL); /* PRQA S 4404 */

    /* Clear Flag */
    SAF_EQADC_LLD_ClearFifoIntFlag(instance, RfifoIdx, SAF_EQADC_FIFO_FLAG_RFIFO_DRAIN);
    SAF_EQADC_LLD_ClearFifoIntFlag(instance, CfifoIdx, SAF_EQADC_FIFO_FLAG_END_OF_QUEUE);

    return AdcRegVal;
}
#endif

SAF_ADC_SEC_CODE
static void SAF_EQADC_WriteConfigCmdSSE(const uint8_t instance, const uint8_t CfifoIdx, const uint8_t AdcIdx, const SafEqadc_OnChipAdcRegAddrType AdcAddr, const uint16_t AdcRegVal)
{
    SafEqadc_ConfigCmdType ConfigCmd;

    SAF_EQADC_GetDefaultRwConfigCmd(&ConfigCmd);
    ConfigCmd.cBufNum       = AdcIdx;
    ConfigCmd.AdcRegAddr    = AdcAddr;
    ConfigCmd.AdcRegValue   = AdcRegVal;
    SAF_EQADC_LLD_CfifoPushConfigCmd((SafEqadcInstanceType)instance, (SafEqadcFifoIdxType)CfifoIdx, &ConfigCmd);
    SAF_EQADC_CFCRxSetSSE(instance, CfifoIdx);
}

SAF_ADC_SEC_CODE
static void SAF_EQADC_ReadConfigCmdSSE(const uint8_t instance, const uint8_t CfifoIdx, const uint8_t AdcIdx, const SafEqadc_OnChipAdcRegAddrType AdcAddr, const uint8_t RfifoIdx)
{
    SafEqadc_ConfigCmdType ConfigCmd;

    SAF_EQADC_GetDefaultRwConfigCmd(&ConfigCmd);
    ConfigCmd.cBufNum       = AdcIdx;
    ConfigCmd.RwCfgCmdType  = SAF_EQADC_CONFIG_CMD_READ;
    ConfigCmd.AdcRegAddr    = AdcAddr;
    ConfigCmd.RfifoMsgTag   = (SafEqadc_RfifoMsgTagType)RfifoIdx;
    SAF_EQADC_LLD_CfifoPushConfigCmd((SafEqadcInstanceType)instance, (SafEqadcFifoIdxType)CfifoIdx, &ConfigCmd);
    SAF_EQADC_CFCRxSetSSE(instance, CfifoIdx);
}

SAF_ADC_SEC_CODE
static status_t SAF_EQADC_DeinitCfifo(const uint8_t instance, const uint8_t CfifoIdx)
{
    uint16_t IntDmaMask = 0U;
    uint32_t Timeout;

    SAF_EQADC_CFCRxSetMode(instance, CfifoIdx, (uint32_t)SAF_EQADC_CFIFO_MODE_DISABLE);

    Timeout = SAF_EQADC_TIMEOUT_COUNT;
    while ((SAF_EQADC_LLD_GetCFifoStatus((SafEqadcInstanceType)instance, (SafEqadcFifoIdxType)CfifoIdx) != SAF_EQADC_CFIFO_STATUS_IDLE) && (Timeout > 0UL))
    {
        Timeout--;
    }

    if (0UL == Timeout)
    {
        return STATUS_TIMEOUT;
    }

    IntDmaMask = (uint16_t)(SAF_EQADC_IRQ_EN_ALL & ~(SAF_EQADC_IRQ_EN_RFIFO_OVERFLOW | SAF_EQADC_IRQ_DMA_REQ_EN_RFIFO_DRAIN));
    SAF_EQADC_IDCRx_FifoIntDmaEnDis(instance, CfifoIdx, IntDmaMask, FALSE);
    SAF_EQADC_IDCRx_FifoIntDmaEnDis(instance, CfifoIdx, SAF_EQADC_IRQ_DMA_REQ_SEL_CFIFO_FILL, FALSE);

    /* Stop eDMA mapped channel */
    if (DmaMappedChanForCmd[instance][CfifoIdx] != SAF_EQADC_DMA_MAPPED_CHAN_INVALID)
    {
        (void) SAF_EDMA_LLD_ClearChannelRequest(DmaMappedChanForCmd[instance][CfifoIdx]);

        DmaMappedChanForCmd[instance][CfifoIdx] = SAF_EQADC_DMA_MAPPED_CHAN_INVALID;
    }

    /* invalidate CFIFO all entries */
    SAF_EQADC_CFCRxSetInvalidate(instance, CfifoIdx);

    /* close CFIFO Trigger */
    SAF_EQADC_ISELx_SetCfifoTrig(instance, CfifoIdx, SAF_EQADC_TRIG_NULL_VAL);

    if ((uint8_t)SAF_EQADC_FIFO_0 == CfifoIdx)
    {
        /* disable CFIFO0 EntryExt */
        SAF_EQADC_CFCR0_SetCfifo0EntryExtEnDis(instance, FALSE);

        /* disable CFIFO0 AdvanceMode */
        SAF_EQADC_CFCR0_SetAMode0(instance, (uint32_t)SAF_EQADC_CFIFO0_AMODE_DISABLE);

        /* disable CFIFO0 StreamMode */
        SAF_EQADC_CFCR0_Cfifo0StreamModeEnDis(instance, FALSE);

        /* close CFIFO0 AdvanceTrig */
        SAF_EQADC_ISELx_SetCfifo0AdvanceTrig(instance, SAF_EQADC_ATRIG_NULL_VALUE);
    }

    return STATUS_SUCCESS;
}
#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
SAF_ADC_SEC_CODE
static void SAF_EQADC_DeinitRedLineClient(const uint8_t instance, const uint8_t ClientIdx)
{
    SAF_EQADC_TagType * const BasePtr = Adc_SafEqadcBase[instance];

    if (ClientIdx == 0U)
    {
        BasePtr->STACCCR.R &= ~(SAF_EQADC_STACCCR_SRV1_MASK | SAF_EQADC_STACCCR_STACBS1_MASK);/* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->STACCCR.R &= ~(SAF_EQADC_STACCCR_SRV2_MASK | SAF_EQADC_STACCCR_STACBS2_MASK);/* polyspace RTE:NIV */
    }
}
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */

SAF_ADC_SEC_CODE
static void SAF_EQADC_DeinitAdcCtrl(const uint8_t instance, const uint8_t AdcIdx, const uint8_t CfgCmdCfifoIdx)
{
    if (CfgCmdCfifoIdx == (uint8_t)SAF_EQADC_FIFO_0)
    {
        SAF_EQADC_LLD_SetImmediateConvCmdEnDis((SafEqadcInstanceType)instance, (SafEqadcAdcIdxType)AdcIdx, TRUE);
    }

    /* Reset ADCx_CR */
    SAF_EQADC_WriteConfigCmdSSE(instance, CfgCmdCfifoIdx, AdcIdx, SAF_EQADC_ADC_REG_CR, (uint16_t)SAF_EQADC_ADC_CR_CLK_PS_MASK);

    /* Reset ADCx_GCCR */
    SAF_EQADC_WriteConfigCmdSSE(instance, CfgCmdCfifoIdx, AdcIdx, SAF_EQADC_ADC_REG_GCCR, 0x4000U);

    /* Reset ADCx_OCCR */
    SAF_EQADC_WriteConfigCmdSSE(instance, CfgCmdCfifoIdx, AdcIdx, SAF_EQADC_ADC_REG_OCCR, 0x0000U);

    if (CfgCmdCfifoIdx == (uint8_t)SAF_EQADC_FIFO_0)
    {
        SAF_EQADC_LLD_SetImmediateConvCmdEnDis((SafEqadcInstanceType)instance, (SafEqadcAdcIdxType)AdcIdx, FALSE);
    }
}

SAF_ADC_SEC_CODE
static void SAF_EQADC_DeinitAdcTimeConfig(const uint8_t instance, const uint8_t CfgCmdCfifoIdx)
{
    /* Reset ADC_TSCR */
    SAF_EQADC_WriteConfigCmdSSE(instance, CfgCmdCfifoIdx, (uint8_t)SAF_EQADC_ADC_0, SAF_EQADC_ADC_REG_TSCR, 0x0000U);

    /* Reset ADC_TBCR */
    SAF_EQADC_WriteConfigCmdSSE(instance, CfgCmdCfifoIdx, (uint8_t)SAF_EQADC_ADC_0, SAF_EQADC_ADC_REG_TBCR, 0x0000U);
}

SAF_ADC_SEC_CODE
static void SAF_EQADC_DeinitAltConfig(const uint8_t instance, const SafEqadc_AltConfigSelType AltCfgSel, const uint8_t CfgCmdCfifoIdx)
{
    uint8_t i;

    /* Reset ADC_ACRx */
    SAF_EQADC_WriteConfigCmdSSE(instance, CfgCmdCfifoIdx, (uint8_t)SAF_EQADC_ADC_0, SAF_EQADC_GetAltConfigRegAddr(AltCfgSel), 0x0000U);

    if ((SAF_EQADC_ALT_CONFIG_SEL_1 == AltCfgSel) || (SAF_EQADC_ALT_CONFIG_SEL_2 == AltCfgSel))
    {
        uint8_t AltCfgIdx = SAF_EQADC_GetAltConfigIdx(AltCfgSel);
        for (i = 0U; i < SAF_EQADC_ADC_NUM; i++)
        {
            /* Reset ADCx_AGR0/1 */
            SAF_EQADC_WriteConfigCmdSSE(instance, CfgCmdCfifoIdx, i, AGRxAddr[AltCfgIdx], 0x4000U);

            /* Reset ADCx_AOR0/1 */
            SAF_EQADC_WriteConfigCmdSSE(instance, CfgCmdCfifoIdx, i, AORxAddr[AltCfgIdx], 0x0000U);
        }
    }
}

SAF_ADC_SEC_CODE
static void SAF_EQADC_DeinitChanPull(const uint8_t instance, const uint8_t AdcChanIdx, const uint8_t CfgCmdCfifoIdx)
{
    const uint8_t AdcReg = ((uint8_t)SAF_EQADC_ADC_REG_PUDCR0 + AdcChanIdx);

    SAF_EQADC_WriteConfigCmdSSE(instance, CfgCmdCfifoIdx, (uint8_t)SAF_EQADC_ADC_0, (SafEqadc_OnChipAdcRegAddrType)AdcReg, 0x0000U);
}

SAF_ADC_SEC_CODE
static void SAF_EQADC_GetDefaultCfifoCfg(SafEqadc_CfifoConfigType * const CfifoCfgPtr)
{
    CfifoCfgPtr->CfifoIdx       = SAF_EQADC_FIFO_0;
    CfifoCfgPtr->CfifoMode      = SAF_EQADC_CFIFO_MODE_SINGLE_SW_TRIG;
    CfifoCfgPtr->IntDmaFillSel  = SAF_EQADC_FILL_SEL_INT;
    CfifoCfgPtr->DmaMappedChan  = 0U;
    CfifoCfgPtr->SourcePtr      = NULL;
    CfifoCfgPtr->SourceLen      = 0UL;
    CfifoCfgPtr->Callback       = NULL;
    CfifoCfgPtr->CallbackParam  = NULL;
    CfifoCfgPtr->HwTrigSel      = SAF_EQADC_HW_TRIG_NOT_CONNECTED;

    /* CFIFO0 */
    CfifoCfgPtr->Cfifo0EntryExtensionEn = FALSE;
    CfifoCfgPtr->Cfifo0AdvanceMode      = SAF_EQADC_CFIFO0_AMODE_DISABLE;
    CfifoCfgPtr->Cfifo0AdvanceTrigSel   = SAF_EQADC_ADVANCE_TRIG_NOT;
}

SAF_ADC_SEC_CODE
static void SAF_EQADC_GetDefaultRwConfigCmd(SafEqadc_ConfigCmdType * const ConfigCmdPtr)
{
    ConfigCmdPtr->Eoq           = TRUE;
    ConfigCmdPtr->Pause         = FALSE;
    ConfigCmdPtr->RepeatStart   = FALSE;
    ConfigCmdPtr->cBufNum       = (uint8_t)SAF_EQADC_ADC_0;
    ConfigCmdPtr->RwCfgCmdType  = SAF_EQADC_CONFIG_CMD_WRITE;
    ConfigCmdPtr->AdcRegValue   = 0U;
    ConfigCmdPtr->AdcRegAddr    = SAF_EQADC_ADC_REG_GCCR;
    ConfigCmdPtr->RfifoMsgTag   = SAF_EQADC_MSG_TAG_RFIFO0;
}

SAF_ADC_SEC_CODE
static void SAF_EQADC_GetDefaultConvCmd(SafEqadc_ConvCmdType * const ConvCmdPtr)
{
    ConvCmdPtr->Eoq             = TRUE;
    ConvCmdPtr->Pause           = FALSE;
    ConvCmdPtr->RepeatStart     = FALSE;
    ConvCmdPtr->cBufNum         = (uint8_t)SAF_EQADC_ADC_0;
    ConvCmdPtr->CalibConvResEn  = FALSE;
    ConvCmdPtr->RfifoMsgTag     = SAF_EQADC_MSG_TAG_RFIFO0;
    ConvCmdPtr->LongSampTime    = SAF_EQADC_ADCLK_SAMPLING_CYCLES_128;
    ConvCmdPtr->TimeStampReq    = FALSE;
    ConvCmdPtr->FormatSignEn    = FALSE;
    ConvCmdPtr->ChanNum         = SAF_EQADC_CH(0);
    ConvCmdPtr->AltConfigSel    = SAF_EQADC_ALT_CONFIG_DISABLE;
    ConvCmdPtr->FlushOrFMT      = FALSE;
}

SAF_ADC_SEC_CODE
static uint32_t SAF_EQADC_GetCfifoRwConfigCmd(const SafEqadc_ConfigCmdType * const ConfigCmdPtr)
{
    uint32_t CfgCmd = 0U;

    /* CFIFO Header */
    CfgCmd |= SAF_EQADC_ADC_CMD_EOQ(ConfigCmdPtr->Eoq);/* PRQA S 2985, 2986 */
    CfgCmd |= SAF_EQADC_ADC_CMD_PAUSE(ConfigCmdPtr->Pause);
    CfgCmd |= SAF_EQADC_ADC_CMD_REP(ConfigCmdPtr->RepeatStart);
    /** Reserved bit(0x18000000) **/
    /** EB bit(0x04000000) must be 0 **/

    /* ADC Command */
    SAF_EQADC_DET_ERR(ConfigCmdPtr->cBufNum < SAF_EQADC_ADC_NUM); /* PRQA S 4404 */
    CfgCmd |= SAF_EQADC_ADC_CMD_BN(ConfigCmdPtr->cBufNum);  /* BN: CBuffer0->ADC0, CBuffer1->ADC1 */

    switch (ConfigCmdPtr->RwCfgCmdType)
    {
        case SAF_EQADC_CONFIG_CMD_READ:
            CfgCmd |= SAF_EQADC_ADC_CMD_RW(SAF_EQADC_CONFIG_CMD_READ);
            CfgCmd |= SAF_EQADC_ADC_CMD_MESSAGE_TAG(ConfigCmdPtr->RfifoMsgTag);
            break;
        case SAF_EQADC_CONFIG_CMD_WRITE:
            CfgCmd |= SAF_EQADC_ADC_CMD_RW(SAF_EQADC_CONFIG_CMD_WRITE); /* PRQA S 2985 */
            CfgCmd |= SAF_EQADC_ADC_CMD_REG_HL_BYTE(ConfigCmdPtr->AdcRegValue); /* PRQA S 2985 */
            break;
        default:
            SAF_EQADC_DET_ERR(FALSE);
            break;
    }

    CfgCmd |= SAF_EQADC_ADC_CMD_REG_ADDR(ConfigCmdPtr->AdcRegAddr); /* PRQA S 2985 */

    return CfgCmd;
}

SAF_ADC_SEC_CODE
static uint32_t SAF_EQADC_GetCfifoConversionCmd(const SafEqadc_ConvCmdType * const ConvCmdPtr)
{
    uint32_t ConvCmd = 0U;

    /* CFIFO Header */
    ConvCmd |= SAF_EQADC_ADC_CMD_EOQ(ConvCmdPtr->Eoq);/* PRQA S 2985, 2986 */
    ConvCmd |= SAF_EQADC_ADC_CMD_PAUSE(ConvCmdPtr->Pause);
    ConvCmd |= SAF_EQADC_ADC_CMD_REP(ConvCmdPtr->RepeatStart);
    /** Reserved bit(0x18000000) **/
    /** EB bit(0x04000000) must be 0 **/

    /* ADC Command */
    SAF_EQADC_DET_ERR(ConvCmdPtr->cBufNum < SAF_EQADC_ADC_NUM); /* PRQA S 4404 */
    ConvCmd |= SAF_EQADC_ADC_CMD_BN(ConvCmdPtr->cBufNum);   /* BN: CBuffer0->ADC0, CBuffer1->ADC1 */
    ConvCmd |= SAF_EQADC_ADC_CMD_CAL(ConvCmdPtr->CalibConvResEn);
    ConvCmd |= SAF_EQADC_ADC_CMD_MESSAGE_TAG(ConvCmdPtr->RfifoMsgTag);
    ConvCmd |= SAF_EQADC_ADC_CMD_LST(ConvCmdPtr->LongSampTime);
    ConvCmd |= SAF_EQADC_ADC_CMD_TSR(ConvCmdPtr->TimeStampReq);
    ConvCmd |= SAF_EQADC_ADC_CMD_CHAN_NUM(ConvCmdPtr->ChanNum); /* PRQA S 2985 */

    if (ConvCmdPtr->AltConfigSel == SAF_EQADC_ALT_CONFIG_DISABLE)
    {
        /* Conversion Command Format for the Standard Configuration */
        ConvCmd |= SAF_EQADC_ADC_CMD_FMT(ConvCmdPtr->FormatSignEn);
    }
    else
    {
        /* Conversion Command Format for Alternate Configurations */
        ConvCmd |= SAF_EQADC_ADC_CMD_ALT_CFG_SEL(ConvCmdPtr->AltConfigSel); /* PRQA S 2985 */
        ConvCmd |= SAF_EQADC_ADC_CMD_FFMT(ConvCmdPtr->FlushOrFMT);
    }

    return ConvCmd;
}

SAF_ADC_SEC_CODE
static void SAF_EQADC_SetAdcConfig(const uint8_t instance, const SafEqadc_AdcConfigType * const AdcConfig, const uint8_t CfgCmdCfifoIdx)
{
#if SAF_EQADC_DET_SUPPORT
    //TODO CLK freq dev
#endif
    uint16_t AdcCrVal = 0U, AdcGccrVal = 0U, AdcOccrVal = 0U;

    /* Get ADCxCR Config */
    AdcCrVal = SAF_EQADC_ADC_CR_EN_MASK;
    AdcCrVal |= (AdcConfig->AdcExtMuxEn == TRUE) ? SAF_EQADC_ADC_CR_EMUX_MASK : 0U;  /* polyspace RTE:IDP */

    SAF_EQADC_DET_ERR((uint8_t)(AdcConfig->TimeBaseSel) <= (uint8_t)SAF_EQADC_TBS_STACCCR_SRV2); /* PRQA S 4404 */
    AdcCrVal |= SAF_EQADC_ADC_CR_TBSEL(AdcConfig->TimeBaseSel);

    if (AdcConfig->ClkSel == SAF_EQADC_CLK_SEL_PS_DIV)
    {
        AdcCrVal |= SAF_EQADC_ADC_CR_CLK_PS(AdcConfig->ClkPrescale); /* PRQA S 2985 */
    }
#ifdef SAF_EQADC_ADC_CR_CLK_SEL_EN
    else
    {
        /* SAF_EQADC_CLK_SEL_MAX_FREQ */
        AdcCrVal |= SAF_EQADC_ADC_CR_CLK_SEL_MASK;
    }
#endif  /* SAF_EQADC_ADC_CR_CLK_SEL_EN */
    /* Get ADCxGCCR Config */
    AdcGccrVal = (AdcConfig->AdcGainCalibConst & SAF_EQADC_ADC_GCCR_GCC_MASK);

    /* Get ADCxOCCR Config */
    AdcOccrVal = (uint16_t)(AdcConfig->AdcOffsetCalibConst);

    /* En/Dis Immediate ConvCmd */
    SAF_EQADC_LLD_SetImmediateConvCmdEnDis((SafEqadcInstanceType)instance, AdcConfig->AdcIdx, AdcConfig->ImmediateConvCmdEn);

    /* Set ADCxCR/ADCxGCCR/ADCxOCCR Config */
    SAF_EQADC_WriteConfigCmdSSE(instance, CfgCmdCfifoIdx, (uint8_t)AdcConfig->AdcIdx, SAF_EQADC_ADC_REG_CR, AdcCrVal);
    SAF_EQADC_WriteConfigCmdSSE(instance, CfgCmdCfifoIdx, (uint8_t)AdcConfig->AdcIdx, SAF_EQADC_ADC_REG_GCCR, AdcGccrVal);
    SAF_EQADC_WriteConfigCmdSSE(instance, CfgCmdCfifoIdx, (uint8_t)AdcConfig->AdcIdx, SAF_EQADC_ADC_REG_OCCR, AdcOccrVal);
}

SAF_ADC_SEC_CODE
static void SAF_EQADC_SetAltConfig(const uint8_t instance, const SafEqadc_AlternateConfigType * const AltConfig, const uint8_t CfgCmdCfifoIdx)
{
    uint16_t AdcAcrVal = 0U;
    uint8_t i;

    /* Get ADC ACRx Config */
    AdcAcrVal = (AltConfig->ResultTransInhibit == TRUE) ? SAF_EQADC_ADC_ACR_RET_INH_MASK : 0U;
    AdcAcrVal |= SAF_EQADC_ADC_ACR_DEST(AltConfig->AltConvResultDEST);
    AdcAcrVal |= (AltConfig->FMTA_SignEn == TRUE) ? SAF_EQADC_ADC_ACR_FMTA_MASK : 0U;
    AdcAcrVal |= SAF_EQADC_ADC_ACR_RESSEL(AltConfig->AdcResSel);
    AdcAcrVal |= SAF_EQADC_ADC_ACR_PRE_GAIN(AltConfig->AdcPreGain); /* PRQA S 2985 */

    /* Set ADC ACRx Config */
    SAF_EQADC_WriteConfigCmdSSE(instance, CfgCmdCfifoIdx, (uint8_t)SAF_EQADC_ADC_0, SAF_EQADC_GetAltConfigRegAddr(AltConfig->AltConfigSel), AdcAcrVal);

    if ((SAF_EQADC_ALT_CONFIG_SEL_1 == AltConfig->AltConfigSel) || (SAF_EQADC_ALT_CONFIG_SEL_2 == AltConfig->AltConfigSel))
    {
        uint8_t AltCfgIdx = SAF_EQADC_GetAltConfigIdx(AltConfig->AltConfigSel);
        for (i = 0U; i < SAF_EQADC_ADC_NUM; i++)
        {
            /* Set ADC AGRx Config */
            SAF_EQADC_WriteConfigCmdSSE(instance, CfgCmdCfifoIdx, i, AGRxAddr[AltCfgIdx], AltConfig->AdcAltGain[i]);

            /* Set ADC AORx Config */
            SAF_EQADC_WriteConfigCmdSSE(instance, CfgCmdCfifoIdx, i, AORxAddr[AltCfgIdx], AltConfig->AdcAltOffset[i]);
        }
    }
}

#ifdef SAF_EQADC_ADC_PUDCR_EN
SAF_ADC_SEC_CODE
static void SAF_EQADC_SetPullUpDownConfig(const uint8_t instance, const SafEqadc_PullUpDownCfgType * const PullUpDownCfg, const uint8_t CfgCmdCfifoIdx)
{
    const uint8_t AdcReg = ((uint8_t)SAF_EQADC_ADC_REG_PUDCR0 + (PullUpDownCfg->AdcChIdx));
    uint16_t AdcPudcrVal = 0U;

    /* Get ADC PUDCRx Config */
    AdcPudcrVal = SAF_EQADC_ADC_PUDCR_CH_PULL(PullUpDownCfg->ChanPull);
    AdcPudcrVal |= SAF_EQADC_ADC_PUDCR_CH_PULL(PullUpDownCfg->PullStrength);

    /* Set ADC AGRx Config */
    SAF_EQADC_WriteConfigCmdSSE(instance, CfgCmdCfifoIdx, (uint8_t)SAF_EQADC_ADC_0, (SafEqadc_OnChipAdcRegAddrType)AdcReg, AdcPudcrVal);
}
#endif  /* SAF_EQADC_ADC_PUDCR_EN */

#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
SAF_ADC_SEC_CODE
static void SAF_EQADC_SetRedLineClientConfig(const uint8_t instance, const SafEqadc_RedLineClientConfigType * const RedLineClientCfg)
{
    SAF_EQADC_REDLCCR_SetREDBS_SRVx(instance, RedLineClientCfg->clientIdx, (uint8_t)(RedLineClientCfg->TimeBaseBitsSel), (uint8_t)(RedLineClientCfg->SRVnSel));
}
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */

SAF_ADC_SEC_CODE
static status_t SAF_EQADC_SetCfifoConfig(const uint8_t instance, const SafEqadc_CfifoConfigType * const CfifoCfgPtr)
{
    uint32_t Timeout;

    /* 1.Disabled CFIFO mode. */
    SAF_EQADC_CFCRxSetMode(instance, (uint8_t)(CfifoCfgPtr->CfifoIdx), (uint32_t)SAF_EQADC_CFIFO_MODE_DISABLE); /* polyspace RTE:IDP */

    /* 2.Waiting for the IDLE status of CFIFO */
    Timeout = SAF_EQADC_TIMEOUT_COUNT;
    while ((SAF_EQADC_LLD_GetCFifoStatus((SafEqadcInstanceType)instance, CfifoCfgPtr->CfifoIdx) != SAF_EQADC_CFIFO_STATUS_IDLE) && (Timeout > 0UL))
    {
        Timeout--;
    }

    if (0UL == Timeout)
    {
        return STATUS_TIMEOUT;
    }

    /* 3.Set CFIFO other mode. */
    SAF_EQADC_CFCRxSetMode(instance, (uint8_t)(CfifoCfgPtr->CfifoIdx), (uint32_t)(CfifoCfgPtr->CfifoMode));

    /* SSE - HW trigger */
    if (((uint8_t)(CfifoCfgPtr->CfifoMode) >= (uint8_t)SAF_EQADC_CFIFO_MODE_SINGLE_LOW_LVL_GATED_EXT_TRIG) && \
        ((uint8_t)(CfifoCfgPtr->CfifoMode) <= (uint8_t)SAF_EQADC_CFIFO_MODE_SINGLE_BOTH_EDGES_EXT_TRIG))/* PRQA S 2897 */
    {
        SAF_EQADC_LLD_SingleScanEn((SafEqadcInstanceType)instance, CfifoCfgPtr->CfifoIdx);
    }

    if (SAF_EQADC_FILL_SEL_INT == CfifoCfgPtr->IntDmaFillSel)
    {
        SAF_EQADC_IDCRx_FifoIntDmaEnDis(instance, (uint8_t)(CfifoCfgPtr->CfifoIdx), SAF_EQADC_IRQ_DMA_REQ_SEL_CFIFO_FILL, FALSE);
        SAF_EQADC_LLD_IntEnDis((SafEqadcInstanceType)instance, CfifoCfgPtr->CfifoIdx, SAF_EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL, FALSE);
    }
    else
    {
        SAF_EQADC_SetDmaForCmd(instance, CfifoCfgPtr);
        SAF_EQADC_IDCRx_FifoIntDmaEnDis(instance, (uint8_t)(CfifoCfgPtr->CfifoIdx), SAF_EQADC_IRQ_DMA_REQ_SEL_CFIFO_FILL, TRUE);
        SAF_EQADC_LLD_DmaEnDis((SafEqadcInstanceType)instance, CfifoCfgPtr->CfifoIdx, SAF_EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL, TRUE);
    }

    SAF_EQADC_DET_ERR((CfifoCfgPtr->HwTrigSel == SAF_EQADC_HW_TRIG_NOT_CONNECTED) || /* PRQA S 4404 */ \
            ((CfifoCfgPtr->CfifoMode != SAF_EQADC_CFIFO_MODE_SINGLE_SW_TRIG) && (CfifoCfgPtr->CfifoMode != SAF_EQADC_CFIFO_MODE_CONT_SW_TRIG)));
    SAF_EQADC_LLD_SetCfifoHwTrigSource((SafEqadcInstanceType)instance, CfifoCfgPtr->CfifoIdx, CfifoCfgPtr->HwTrigSel);

    //TBG? TODO

    if (SAF_EQADC_FIFO_0 == CfifoCfgPtr->CfifoIdx)
    {
        /* CFIFO0 Entry Number Extension Enable */
        SAF_EQADC_CFCR0_SetCfifo0EntryExtEnDis(instance, CfifoCfgPtr->Cfifo0EntryExtensionEn);

        /* Set CFIFO0 Advance Trigger Operation Mode: disable mode */
        SAF_EQADC_CFCR0_SetAMode0(instance, (uint32_t)SAF_EQADC_CFIFO0_AMODE_DISABLE);
        /* Set CFIFO0 Advance Trigger Source */
        SAF_EQADC_LLD_SetCfifo0AdvanceTrigSource((SafEqadcInstanceType)instance, CfifoCfgPtr->Cfifo0AdvanceTrigSel);

        if (CfifoCfgPtr->Cfifo0AdvanceMode != SAF_EQADC_CFIFO0_AMODE_DISABLE)
        {
            SAF_EQADC_DET_ERR((CfifoCfgPtr->CfifoMode >= SAF_EQADC_CFIFO_MODE_SINGLE_LOW_LVL_GATED_EXT_TRIG) && /* PRQA S 4404 */ \
                    (CfifoCfgPtr->CfifoMode <= SAF_EQADC_CFIFO_MODE_SINGLE_BOTH_EDGES_EXT_TRIG));
            SAF_EQADC_DET_ERR((CfifoCfgPtr->Cfifo0AdvanceMode != SAF_EQADC_CFIFO0_AMODE_SINGLE_SW_TRIG) || /* PRQA S 4404 */ \
                    (CfifoCfgPtr->Cfifo0AdvanceTrigSel == SAF_EQADC_ADVANCE_TRIG_NOT));

            /* Set CFIFO0 Advance Trigger Operation Mode */
            SAF_EQADC_CFCR0_SetAMode0(instance, (uint32_t)(CfifoCfgPtr->Cfifo0AdvanceMode));
            /* CFIFO0 Streaming Mode Operation Enable */
            SAF_EQADC_CFCR0_Cfifo0StreamModeEnDis(instance, TRUE);
        }
        else
        {
            /* CFIFO0 Streaming Mode Operation Disable */
            SAF_EQADC_CFCR0_Cfifo0StreamModeEnDis(instance, FALSE);
        }
    }

    return STATUS_SUCCESS;
}

SAF_ADC_SEC_CODE
static void SAF_EQADC_SetDmaForCmd(const uint8_t instance, const SafEqadc_CfifoConfigType * const CfifoCfgPtr)
{
    uint8_t Cfifo_x = (uint8_t)(CfifoCfgPtr->CfifoIdx);
    uint32_t srcSizeLast = sizeof(CfifoCfgPtr->SourcePtr[0U]) * CfifoCfgPtr->SourceLen;
    status_t ret;
    DmaMappedChanForCmd[instance][Cfifo_x] = CfifoCfgPtr->DmaMappedChan;

    SafeDMATransferConfigType TcdCfg;
    SafeDMALoopTransferConfigType LoopTcdCfg;
    TcdCfg.srcAddr                  = (uint32_t)CfifoCfgPtr->SourcePtr;
    TcdCfg.destAddr                 = (uint32_t)(SAF_EQADC_CFPR[instance][Cfifo_x]);
    TcdCfg.srcTransDataSize         = SAF_EDMA_TRANSFER_SIZE_4B;
    TcdCfg.destTransDataSize        = SAF_EDMA_TRANSFER_SIZE_4B;
    TcdCfg.srcAddrOffset            = (int16_t)sizeof(CfifoCfgPtr->SourcePtr[0U]);
    TcdCfg.destAddrOffset           = 0;
    TcdCfg.srcAddrAdjustLast        = -(int32_t)srcSizeLast; /* polyspace RTE:OVFL */
    TcdCfg.destAddrAdjustLast       = 0;
    TcdCfg.srcAddrModulo            = SAF_EDMA_ADDRESS_MODULO_OFF;
    TcdCfg.destAddrModulo           = SAF_EDMA_ADDRESS_MODULO_OFF;
    TcdCfg.minorTransByte           = sizeof(CfifoCfgPtr->SourcePtr[0U]);
    TcdCfg.featureScatterGatherEn   = FALSE;
    TcdCfg.featureScatterGatherNextDescriptor   = 0U;
    TcdCfg.completeIntEn            = TRUE;
    TcdCfg.lpTransConfigPtr         = &LoopTcdCfg;

    LoopTcdCfg.majorLpIterCnt       = CfifoCfgPtr->SourceLen;
    LoopTcdCfg.srcAddrOffsetEn      = FALSE;
    LoopTcdCfg.dstAddrOffsetEn      = FALSE;
    LoopTcdCfg.minorLpOffset        = 0;
    LoopTcdCfg.minorLpLinkEn        = FALSE;
    LoopTcdCfg.minorLpLinkChn       = 0U;
    LoopTcdCfg.majorLpLinkEn        = FALSE;
    LoopTcdCfg.majorLpLinkChn       = 0U;

    ret = SAF_EDMA_LLD_SetLoopTransferConfig(CfifoCfgPtr->DmaMappedChan, &TcdCfg);
    (void)ret;
    SAF_EQADC_DET_ERR(ret == STATUS_SUCCESS); /* PRQA S 4404 */

    SAF_EDMA_LLD_SetChnDisRequestsOnTransferComplete(CfifoCfgPtr->DmaMappedChan, TRUE);

    if (CfifoCfgPtr->Callback != NULL)
    {
        (void) SAF_EDMA_LLD_SetUpCallback(CfifoCfgPtr->DmaMappedChan, CfifoCfgPtr->Callback, CfifoCfgPtr->CallbackParam);

        SAF_EDMA_LLD_SetInterruptConfig(CfifoCfgPtr->DmaMappedChan, SAF_EDMA_CHN_ENABLE_ERROR_INT, TRUE);
        SAF_EDMA_LLD_SetInterruptConfig(CfifoCfgPtr->DmaMappedChan, SAF_EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT, FALSE);
        SAF_EDMA_LLD_SetInterruptConfig(CfifoCfgPtr->DmaMappedChan, SAF_EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, TRUE);
    }
    else
    {
        SAF_EDMA_LLD_SetInterruptConfig(CfifoCfgPtr->DmaMappedChan, SAF_EDMA_CHN_ENABLE_ERROR_INT, FALSE);
        SAF_EDMA_LLD_SetInterruptConfig(CfifoCfgPtr->DmaMappedChan, SAF_EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT, FALSE);
        SAF_EDMA_LLD_SetInterruptConfig(CfifoCfgPtr->DmaMappedChan, SAF_EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, FALSE);
    }
    /* The start of the DMA channel is outside the SAF_EQADC low-level driver */
}

SAF_ADC_SEC_CODE
static void SAF_EQADC_SetDmaForResult(const uint8_t instance, const SafEqadc_ResultDmaConfigType * const RfifoCfgPtr)
{
    uint8_t Rfifo_x = (uint8_t)(RfifoCfgPtr->RfifoIdx);
    uint32_t destSizeLast = sizeof(RfifoCfgPtr->DestPtr[0U]) * RfifoCfgPtr->DestLen;
    status_t ret;
    DmaMappedChanForResult[instance][Rfifo_x] = RfifoCfgPtr->ResultDmaMappedChan;

    SafeDMATransferConfigType TcdCfg;
    SafeDMALoopTransferConfigType LoopTcdCfg;
    TcdCfg.srcAddr                  = (uint32_t)(SAF_EQADC_RFPR[instance][Rfifo_x]) + 2U;
    TcdCfg.destAddr                 = (uint32_t)RfifoCfgPtr->DestPtr;
    TcdCfg.srcTransDataSize         = SAF_EDMA_TRANSFER_SIZE_2B;
    TcdCfg.destTransDataSize        = SAF_EDMA_TRANSFER_SIZE_2B;
    TcdCfg.srcAddrOffset            = 0;
    TcdCfg.destAddrOffset           = (int16_t)sizeof(RfifoCfgPtr->DestPtr[0U]);
    TcdCfg.srcAddrAdjustLast        = 0;
    TcdCfg.destAddrAdjustLast       = -(int32_t)destSizeLast; /* polyspace RTE:OVFL */
    TcdCfg.srcAddrModulo            = SAF_EDMA_ADDRESS_MODULO_OFF;
    TcdCfg.destAddrModulo           = SAF_EDMA_ADDRESS_MODULO_OFF;
    TcdCfg.minorTransByte           = sizeof(RfifoCfgPtr->DestPtr[0U]);
    TcdCfg.featureScatterGatherEn   = FALSE;
    TcdCfg.featureScatterGatherNextDescriptor   = 0U;
    TcdCfg.completeIntEn            = TRUE;
    TcdCfg.lpTransConfigPtr         = &LoopTcdCfg;

    LoopTcdCfg.majorLpIterCnt       = RfifoCfgPtr->DestLen;
    LoopTcdCfg.srcAddrOffsetEn      = FALSE;
    LoopTcdCfg.dstAddrOffsetEn      = FALSE;
    LoopTcdCfg.minorLpOffset        = 0;
    LoopTcdCfg.minorLpLinkEn        = FALSE;
    LoopTcdCfg.minorLpLinkChn       = 0U;
    LoopTcdCfg.majorLpLinkEn        = FALSE;
    LoopTcdCfg.majorLpLinkChn       = 0U;

    ret = SAF_EDMA_LLD_SetLoopTransferConfig(RfifoCfgPtr->ResultDmaMappedChan, &TcdCfg);
    (void)ret;
    SAF_EQADC_DET_ERR(ret == STATUS_SUCCESS); /* PRQA S 4404 */

    if (RfifoCfgPtr->Callback != NULL)
    {
        (void) SAF_EDMA_LLD_SetUpCallback(RfifoCfgPtr->ResultDmaMappedChan, RfifoCfgPtr->Callback, RfifoCfgPtr->CallbackParam);

        SAF_EDMA_LLD_SetInterruptConfig(RfifoCfgPtr->ResultDmaMappedChan, SAF_EDMA_CHN_ENABLE_ERROR_INT, TRUE);
        if (RfifoCfgPtr->EnHalfDestCallback == TRUE)
        {
            SAF_EDMA_LLD_SetInterruptConfig(RfifoCfgPtr->ResultDmaMappedChan, SAF_EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT, TRUE);
        }
        else
        {
            SAF_EDMA_LLD_SetInterruptConfig(RfifoCfgPtr->ResultDmaMappedChan, SAF_EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT, FALSE);
        }
        SAF_EDMA_LLD_SetInterruptConfig(RfifoCfgPtr->ResultDmaMappedChan, SAF_EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, TRUE);
    }
    else
    {
        SAF_EDMA_LLD_SetInterruptConfig(RfifoCfgPtr->ResultDmaMappedChan, SAF_EDMA_CHN_ENABLE_ERROR_INT, FALSE);
        SAF_EDMA_LLD_SetInterruptConfig(RfifoCfgPtr->ResultDmaMappedChan, SAF_EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT, FALSE);
        SAF_EDMA_LLD_SetInterruptConfig(RfifoCfgPtr->ResultDmaMappedChan, SAF_EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, FALSE);
    }

    (void) SAF_EDMA_LLD_SetChannelRequest(RfifoCfgPtr->ResultDmaMappedChan);
}


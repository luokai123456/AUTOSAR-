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
*   @file    Adc_LLDriver.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Adc MCAL driver.
*
*   @addtogroup Adc
*   @{
*/

/* PRQA S 0380, 3432, 2907, 4404, 4391, 4399, 2842 EOF */
/* PRQA S 2844, 0488, 0491, 0492, 1843, 1880, 3604, 4342, 4397, 3218, 2755 , 0310 EOF */    /* QAC_CWE */
/* PRQA S 0686, 2921, 1258 EOF */

#ifdef __cplusplus
extern "C"{
#endif

#define ADC_LLD_C_VENDOR_ID                     176
#define ADC_LLD_C_AR_REL_MAJOR_VER              4
#define ADC_LLD_C_AR_REL_MINOR_VER              4
#define ADC_LLD_C_AR_REL_REV_VER                0
#define ADC_LLD_C_SW_MAJOR_VER                  3
#define ADC_LLD_C_SW_MINOR_VER                  0
#define ADC_LLD_C_SW_PATCH_VER                  0

#include "Adc.h"
#include "Adc_LLDriver.h"
#include "SchM_Adc.h"
#include "eDma.h"
#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
#include "Dem.h"
#endif

#if (ADC_VENDOR_ID               != ADC_LLD_C_VENDOR_ID)
    #error " NON-MATCHED DATA : ADC_LLD_C_VENDOR_ID "
#endif
#if (ADC_AR_REL_MAJOR_VER    != ADC_LLD_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ADC_LLD_C_AR_REL_MAJOR_VER "
#endif
#if (ADC_AR_REL_MINOR_VER    != ADC_LLD_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ADC_LLD_C_AR_REL_MINOR_VER "
#endif
#if (ADC_AR_REL_REV_VER != ADC_LLD_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ADC_LLD_C_AR_REL_REV_VER "
#endif
#if (ADC_SW_MAJOR_VER        != ADC_LLD_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ADC_LLD_C_SW_MAJOR_VER "
#endif
#if (ADC_SW_MINOR_VER        != ADC_LLD_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ADC_LLD_C_SW_MINOR_VER "
#endif
#if (ADC_SW_PATCH_VER        != ADC_LLD_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ADC_LLD_C_SW_PATCH_VER "
#endif

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

/*******************************************************************************
 * EQADC CFIFO for configuring commands
 *******************************************************************************/
#define EQADC_CFG_CMD_CFIFO_IDX             (EQADC_FIFO_0)

/************************************************************************************************
 *                                  EQADC ADC command format
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
#define EQADC_ADC_CMD_EOQ_MASK              (0x80000000U)
#define EQADC_ADC_CMD_EOQ_SHIFT             (31U)
#define EQADC_ADC_CMD_EOQ(x)                (((uint32)(((uint32)(((x) == TRUE) ? 1U : 0U)) << EQADC_ADC_CMD_EOQ_SHIFT))&EQADC_ADC_CMD_EOQ_MASK)
/** PAUSE Bit Fields **/
#define EQADC_ADC_CMD_PAUSE_MASK            (0x40000000U)
#define EQADC_ADC_CMD_PAUSE_SHIFT           (30U)
#define EQADC_ADC_CMD_PAUSE(x)              (((uint32)(((uint32)(((x) == TRUE) ? 1U : 0U)) << EQADC_ADC_CMD_PAUSE_SHIFT))&EQADC_ADC_CMD_PAUSE_MASK)
/** REP Bit Fields **/
#define EQADC_ADC_CMD_REP_MASK              (0x20000000U)
#define EQADC_ADC_CMD_REP_SHIFT             (29U)
#define EQADC_ADC_CMD_REP(x)                (((uint32)(((uint32)(((x) == TRUE) ? 1U : 0U)) << EQADC_ADC_CMD_REP_SHIFT))&EQADC_ADC_CMD_REP_MASK)
#ifdef RESOURCE_SUPPORT_EQADC_CMD_OSR
#define EQADC_ADC_CMD_OSR_MASK              (0x1C000000U)
#define EQADC_ADC_CMD_OSR_SHIFT             (26U)
#define EQADC_ADC_CMD_OSR(x)                (((uint32)(((uint32)(x)) << EQADC_ADC_CMD_OSR_SHIFT))&EQADC_ADC_CMD_OSR_MASK)
#else
/** EB Bit Fields (External Buffer Bit, must set 0)
define EQADC_ADC_CMD_EB_MASK               (0x04000000U)
define EQADC_ADC_CMD_EB_SHIFT              (26U)
**/
#endif  /* RESOURCE_SUPPORT_EQADC_CMD_OSR */
/* Command format: ADC Command */
/** BN Bit Fields **/
#define EQADC_ADC_CMD_BN_MASK               (0x02000000U)
#define EQADC_ADC_CMD_BN_SHIFT              (25U)
#define EQADC_ADC_CMD_BN(x)                 (((uint32)(((uint32)(x)) << EQADC_ADC_CMD_BN_SHIFT))&EQADC_ADC_CMD_BN_MASK)
/** CAL Bit Fields (Conversion command format) **/
#define EQADC_ADC_CMD_CAL_MASK              (0x01000000U)
#define EQADC_ADC_CMD_CAL_SHIFT             (24U)
#define EQADC_ADC_CMD_CAL(x)                (((uint32)(((uint32)(((x) == TRUE) ? 1U : 0U)) << EQADC_ADC_CMD_CAL_SHIFT))&EQADC_ADC_CMD_CAL_MASK)
#if defined(RESOURCE_SUPPORT_EQADC_CMD_LST)
#if (RESOURCE_SUPPORT_EQADC_CMD_LST == RESOURCE_SUPPORT_EQADC_CMD_LST_2BIT)
/** MESSAGE_TAG Bit Fields **/
#define EQADC_ADC_CMD_MESSAGE_TAG_MASK      (0x00F00000U)
#define EQADC_ADC_CMD_MESSAGE_TAG_SHIFT     (20U)
#define EQADC_ADC_CMD_MESSAGE_TAG(x)        (((uint32)(((uint32)(x)) << EQADC_ADC_CMD_MESSAGE_TAG_SHIFT))&EQADC_ADC_CMD_MESSAGE_TAG_MASK)
/** LST Bit Fields (Conversion command format) **/
#define EQADC_ADC_CMD_LST_MASK              (0x000C0000U)
#define EQADC_ADC_CMD_LST_SHIFT             (18U)
#define EQADC_ADC_CMD_LST(x)                (((uint32)(((uint32)(x)) << EQADC_ADC_CMD_LST_SHIFT))&EQADC_ADC_CMD_LST_MASK)
#elif (RESOURCE_SUPPORT_EQADC_CMD_LST == RESOURCE_SUPPORT_EQADC_CMD_LST_3BIT)
/** MESSAGE_TAG Bit Fields **/
#define EQADC_ADC_CMD_MESSAGE_TAG_MASK      (0x00E00000U)
#define EQADC_ADC_CMD_MESSAGE_TAG_SHIFT     (21U)
#define EQADC_ADC_CMD_MESSAGE_TAG(x)        (((uint32)(((uint32)(x)) << EQADC_ADC_CMD_MESSAGE_TAG_SHIFT))&EQADC_ADC_CMD_MESSAGE_TAG_MASK)
/** LST Bit Fields (Conversion command format) **/
#define EQADC_ADC_CMD_LST_MASK              (0x001C0000U)
#define EQADC_ADC_CMD_LST_SHIFT             (18U)
#define EQADC_ADC_CMD_LST(x)                (((uint32)(((uint32)(x)) << EQADC_ADC_CMD_LST_SHIFT))&EQADC_ADC_CMD_LST_MASK)
#else
    #error "EQADC_ADC_CMD error!"
#endif  /* RESOURCE_SUPPORT_EQADC_CMD_LST == RESOURCE_SUPPORT_EQADC_CMD_LST_2BIT */
#else
    #error "RESOURCE_SUPPORT_EQADC_CMD_LST  is not defined!"
#endif  /* RESOURCE_SUPPORT_EQADC_CMD_LST */
/** TSR Bit Fields (Conversion command format) **/
#define EQADC_ADC_CMD_TSR_MASK              (0x00020000U)
#define EQADC_ADC_CMD_TSR_SHIFT             (17U)
#define EQADC_ADC_CMD_TSR(x)                (((uint32)(((uint32)(((x) == TRUE) ? 1U : 0U)) << EQADC_ADC_CMD_TSR_SHIFT))&EQADC_ADC_CMD_TSR_MASK)
/** FMT Bit Fields (Conversion command format) **/
#define EQADC_ADC_CMD_FMT_MASK              (0x00010000U)
#define EQADC_ADC_CMD_FMT_SHIFT             (16U)
#define EQADC_ADC_CMD_FMT(x)                (((uint32)(((uint32)(((x) == TRUE) ? 1U : 0U)) << EQADC_ADC_CMD_FMT_SHIFT))&EQADC_ADC_CMD_FMT_MASK)
/** FFMT Bit Fields (Conversion command format) **/
#define EQADC_ADC_CMD_FFMT_MASK             (0x00010000U)
#define EQADC_ADC_CMD_FFMT_SHIFT            (16U)
#define EQADC_ADC_CMD_FFMT(x)               (((uint32)(((uint32)(((x) == TRUE) ? 1U : 0U)) << EQADC_ADC_CMD_FFMT_SHIFT))&EQADC_ADC_CMD_FFMT_MASK)
/** CHAN_NUM Bit Fields (Conversion command format) **/
#define EQADC_ADC_CMD_CHAN_NUM_MASK         (0x0000FF00U)
#define EQADC_ADC_CMD_CHAN_NUM_SHIFT        (8U)
#define EQADC_ADC_CMD_CHAN_NUM(x)           (((uint32)(((uint32)(x)) << EQADC_ADC_CMD_CHAN_NUM_SHIFT))&EQADC_ADC_CMD_CHAN_NUM_MASK)
/** ALT_CFG_SEL Bit Fields (Conversion command format) **/
#define EQADC_ADC_CMD_ALT_CFG_SEL_MASK      (0x000000FFU)
#define EQADC_ADC_CMD_ALT_CFG_SEL_SHIFT     (0U)
#define EQADC_ADC_CMD_ALT_CFG_SEL(x)        (((uint32)(((uint32)(x)) << EQADC_ADC_CMD_ALT_CFG_SEL_SHIFT))&EQADC_ADC_CMD_ALT_CFG_SEL_MASK)
/** RW Bit Fields (RW Configuration command format), write(0b0), read(0b1) **/
#define EQADC_ADC_CMD_RW_MASK               (0x01000000U)
#define EQADC_ADC_CMD_RW_SHIFT              (24U)
#define EQADC_ADC_CMD_RW(x)                 (((uint32)(((uint32)(x)) << EQADC_ADC_CMD_RW_SHIFT))&EQADC_ADC_CMD_RW_MASK)
/**[REG_HIGH_BYTE + REG_LOW_BYTE] Bit Fields (RW Configuration command format) **/
#define EQADC_ADC_CMD_REG_HL_BYTE_MASK      (0x00FFFF00U)
#define EQADC_ADC_CMD_REG_HL_BYTE_SHIFT     (8U)
#define EQADC_ADC_CMD_REG_HL_BYTE(x)        (((uint32)(((uint32)(x)) << EQADC_ADC_CMD_REG_HL_BYTE_SHIFT))&EQADC_ADC_CMD_REG_HL_BYTE_MASK)
/** REG_ADDR Bit Fields (RW Configuration command format) **/
#define EQADC_ADC_CMD_REG_ADDR_MASK         (0x000000FFU)
#define EQADC_ADC_CMD_REG_ADDR_SHIFT        (0U)
#define EQADC_ADC_CMD_REG_ADDR(x)           (((uint32)(((uint32)(x)) << EQADC_ADC_CMD_REG_ADDR_SHIFT))&EQADC_ADC_CMD_REG_ADDR_MASK)

#define EQADC_DMA_MAPPED_CHAN_INVALID       (0xFFU)

/* EQADC Module Configuration Register (EQADC_MCR) */
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_MCR[ADC_EQADC_MAX_INSTANCE] =
{
    (volatile uint32 *)&(EQADC0_PTR->MCR.R),
    (volatile uint32 *)&(EQADC1_PTR->MCR.R),
    (volatile uint32 *)&(EQADC2_PTR->MCR.R),
    (volatile uint32 *)&(EQADC3_PTR->MCR.R),
    (volatile uint32 *)&(EQADC4_PTR->MCR.R),
    (volatile uint32 *)&(EQADC5_PTR->MCR.R),
    (volatile uint32 *)&(EQADC6_PTR->MCR.R)
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

/* EQADC External Trigger Digital Filter Register (EQADC_ETDFR) */
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_ETDFR[ADC_EQADC_MAX_INSTANCE] =
{
    (volatile uint32 *)&(EQADC0_PTR->ETDFR.R),
    (volatile uint32 *)&(EQADC1_PTR->ETDFR.R),
    (volatile uint32 *)&(EQADC2_PTR->ETDFR.R),
    (volatile uint32 *)&(EQADC3_PTR->ETDFR.R),
    (volatile uint32 *)&(EQADC4_PTR->ETDFR.R),
    (volatile uint32 *)&(EQADC5_PTR->ETDFR.R),
    (volatile uint32 *)&(EQADC6_PTR->ETDFR.R)
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if defined(RESOURCE_SUPPORT_EQADC_FIFO_CNT)
#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_6)
/* EQADC Command FIFO Push Registers (EQADC_CFPR) */
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_CFPR[ADC_EQADC_MAX_INSTANCE][EQADC_CFIFO_COUNT] =
{
    {(volatile uint32 *)&(EQADC0_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC0_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC0_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC0_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC0_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC0_PTR->CFPR[5U].R)},
    {(volatile uint32 *)&(EQADC1_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC1_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC1_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC1_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC1_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC1_PTR->CFPR[5U].R)},
    {(volatile uint32 *)&(EQADC2_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC2_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC2_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC2_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC2_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC2_PTR->CFPR[5U].R)},
    {(volatile uint32 *)&(EQADC3_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC3_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC3_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC3_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC3_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC3_PTR->CFPR[5U].R)},
    {(volatile uint32 *)&(EQADC4_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC4_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC4_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC4_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC4_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC4_PTR->CFPR[5U].R)},
    {(volatile uint32 *)&(EQADC5_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC5_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC5_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC5_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC5_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC5_PTR->CFPR[5U].R)},
    {(volatile uint32 *)&(EQADC6_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC6_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC6_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC6_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC6_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC6_PTR->CFPR[5U].R)}
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

/* EQADC Result FIFO Pop Registers (EQADC_RFPR) */
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_RFPR[ADC_EQADC_MAX_INSTANCE][EQADC_RFIFO_COUNT] =
{
    {(volatile uint32 *)&(EQADC0_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC0_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC0_PTR->RFPR[2U].R), (volatile uint32 *)&(EQADC0_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC0_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC0_PTR->RFPR[5U].R)},
    {(volatile uint32 *)&(EQADC1_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC1_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC1_PTR->RFPR[2U].R), (volatile uint32 *)&(EQADC1_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC1_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC1_PTR->RFPR[5U].R)},
    {(volatile uint32 *)&(EQADC2_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC2_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC2_PTR->RFPR[2U].R), (volatile uint32 *)&(EQADC2_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC2_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC2_PTR->RFPR[5U].R)},
    {(volatile uint32 *)&(EQADC3_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC3_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC3_PTR->RFPR[2U].R), (volatile uint32 *)&(EQADC3_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC3_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC3_PTR->RFPR[5U].R)},
    {(volatile uint32 *)&(EQADC4_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC4_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC4_PTR->RFPR[2U].R), (volatile uint32 *)&(EQADC4_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC4_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC4_PTR->RFPR[5U].R)},
    {(volatile uint32 *)&(EQADC5_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC5_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC5_PTR->RFPR[2U].R), (volatile uint32 *)&(EQADC5_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC5_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC5_PTR->RFPR[5U].R)},
    {(volatile uint32 *)&(EQADC6_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC6_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC6_PTR->RFPR[2U].R), (volatile uint32 *)&(EQADC6_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC6_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC6_PTR->RFPR[5U].R)}
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

/* EQADC CFIFO Control Registers (EQADC_CFCR) */
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_CFCR[ADC_EQADC_MAX_INSTANCE][EQADC_CFCR_U32_REG_COUNT] =
{
    {(volatile uint32 *)&(EQADC0_PTR->CFCR0.R), (volatile uint32 *)&(EQADC0_PTR->CFCR1.R), (volatile uint32 *)&(EQADC0_PTR->CFCR2.R)},
    {(volatile uint32 *)&(EQADC1_PTR->CFCR0.R), (volatile uint32 *)&(EQADC1_PTR->CFCR1.R), (volatile uint32 *)&(EQADC1_PTR->CFCR2.R)},
    {(volatile uint32 *)&(EQADC2_PTR->CFCR0.R), (volatile uint32 *)&(EQADC2_PTR->CFCR1.R), (volatile uint32 *)&(EQADC2_PTR->CFCR2.R)},
    {(volatile uint32 *)&(EQADC3_PTR->CFCR0.R), (volatile uint32 *)&(EQADC3_PTR->CFCR1.R), (volatile uint32 *)&(EQADC3_PTR->CFCR2.R)},
    {(volatile uint32 *)&(EQADC4_PTR->CFCR0.R), (volatile uint32 *)&(EQADC4_PTR->CFCR1.R), (volatile uint32 *)&(EQADC4_PTR->CFCR2.R)},
    {(volatile uint32 *)&(EQADC5_PTR->CFCR0.R), (volatile uint32 *)&(EQADC5_PTR->CFCR1.R), (volatile uint32 *)&(EQADC5_PTR->CFCR2.R)},
    {(volatile uint32 *)&(EQADC6_PTR->CFCR0.R), (volatile uint32 *)&(EQADC6_PTR->CFCR1.R), (volatile uint32 *)&(EQADC6_PTR->CFCR2.R)}
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

/* EQADC Interrupt and DMA Control Registers (EQADC_IDCR) */
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_IDCR[ADC_EQADC_MAX_INSTANCE][EQADC_IDCR_U32_REG_COUNT] =
{
    {(volatile uint32 *)&(EQADC0_PTR->IDCR0.R), (volatile uint32 *)&(EQADC0_PTR->IDCR1.R), (volatile uint32 *)&(EQADC0_PTR->IDCR2.R)},
    {(volatile uint32 *)&(EQADC1_PTR->IDCR0.R), (volatile uint32 *)&(EQADC1_PTR->IDCR1.R), (volatile uint32 *)&(EQADC1_PTR->IDCR2.R)},
    {(volatile uint32 *)&(EQADC2_PTR->IDCR0.R), (volatile uint32 *)&(EQADC2_PTR->IDCR1.R), (volatile uint32 *)&(EQADC2_PTR->IDCR2.R)},
    {(volatile uint32 *)&(EQADC3_PTR->IDCR0.R), (volatile uint32 *)&(EQADC3_PTR->IDCR1.R), (volatile uint32 *)&(EQADC3_PTR->IDCR2.R)},
    {(volatile uint32 *)&(EQADC4_PTR->IDCR0.R), (volatile uint32 *)&(EQADC4_PTR->IDCR1.R), (volatile uint32 *)&(EQADC4_PTR->IDCR2.R)},
    {(volatile uint32 *)&(EQADC5_PTR->IDCR0.R), (volatile uint32 *)&(EQADC5_PTR->IDCR1.R), (volatile uint32 *)&(EQADC5_PTR->IDCR2.R)},
    {(volatile uint32 *)&(EQADC6_PTR->IDCR0.R), (volatile uint32 *)&(EQADC6_PTR->IDCR1.R), (volatile uint32 *)&(EQADC6_PTR->IDCR2.R)}
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

/* EQADC CFIFO Transfer Counter Registers (EQADC_CFTCR) */
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_CFTCR[ADC_EQADC_MAX_INSTANCE][EQADC_CFTCR_U32_REG_COUNT] =
{
    {(volatile uint32 *)&(EQADC0_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC0_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC0_PTR->CFTCR2.R)},
    {(volatile uint32 *)&(EQADC1_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC1_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC1_PTR->CFTCR2.R)},
    {(volatile uint32 *)&(EQADC2_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC2_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC2_PTR->CFTCR2.R)},
    {(volatile uint32 *)&(EQADC3_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC3_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC3_PTR->CFTCR2.R)},
    {(volatile uint32 *)&(EQADC4_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC4_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC4_PTR->CFTCR2.R)},
    {(volatile uint32 *)&(EQADC5_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC5_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC5_PTR->CFTCR2.R)},
    {(volatile uint32 *)&(EQADC6_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC6_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC6_PTR->CFTCR2.R)}
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
/* EQADC CFIFO Trigger Delay Registers (EQADC_DLY) */
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_DLY[ADC_EQADC_MAX_INSTANCE][EQADC_CFIFO_COUNT] =
{
    {(volatile uint32 *)&(EQADC0_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC0_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC0_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC0_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC0_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC0_PTR->DLY[5U].R)},
    {(volatile uint32 *)&(EQADC1_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC1_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC1_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC1_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC1_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC1_PTR->DLY[5U].R)},
    {(volatile uint32 *)&(EQADC2_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC2_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC2_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC2_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC2_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC2_PTR->DLY[5U].R)},
    {(volatile uint32 *)&(EQADC3_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC3_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC3_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC3_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC3_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC3_PTR->DLY[5U].R)},
    {(volatile uint32 *)&(EQADC4_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC4_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC4_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC4_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC4_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC4_PTR->DLY[5U].R)},
    {(volatile uint32 *)&(EQADC5_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC5_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC5_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC5_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC5_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC5_PTR->DLY[5U].R)},
    {(volatile uint32 *)&(EQADC6_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC6_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC6_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC6_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC6_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC6_PTR->DLY[5U].R)}
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */

#elif (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
/* EQADC Command FIFO Push Registers (EQADC_CFPR) */
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_CFPR[ADC_EQADC_MAX_INSTANCE][EQADC_CFIFO_COUNT] =
{
    {(volatile uint32 *)&(EQADC0_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC0_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC0_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC0_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC0_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC0_PTR->CFPR[5U].R), (volatile uint32 *)&(EQADC0_PTR->CFPR[6U].R), (volatile uint32 *)&(EQADC0_PTR->CFPR[7U].R)},
    {(volatile uint32 *)&(EQADC1_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC1_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC1_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC1_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC1_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC1_PTR->CFPR[5U].R), (volatile uint32 *)&(EQADC1_PTR->CFPR[6U].R), (volatile uint32 *)&(EQADC1_PTR->CFPR[7U].R)},
    {(volatile uint32 *)&(EQADC2_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC2_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC2_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC2_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC2_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC2_PTR->CFPR[5U].R), (volatile uint32 *)&(EQADC2_PTR->CFPR[6U].R), (volatile uint32 *)&(EQADC2_PTR->CFPR[7U].R)},
    {(volatile uint32 *)&(EQADC3_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC3_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC3_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC3_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC3_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC3_PTR->CFPR[5U].R), (volatile uint32 *)&(EQADC3_PTR->CFPR[6U].R), (volatile uint32 *)&(EQADC3_PTR->CFPR[7U].R)},
    {(volatile uint32 *)&(EQADC4_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC4_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC4_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC4_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC4_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC4_PTR->CFPR[5U].R), (volatile uint32 *)&(EQADC4_PTR->CFPR[6U].R), (volatile uint32 *)&(EQADC4_PTR->CFPR[7U].R)},
    {(volatile uint32 *)&(EQADC5_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC5_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC5_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC5_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC5_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC5_PTR->CFPR[5U].R), (volatile uint32 *)&(EQADC5_PTR->CFPR[6U].R), (volatile uint32 *)&(EQADC5_PTR->CFPR[7U].R)},
    {(volatile uint32 *)&(EQADC6_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC6_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC6_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC6_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC6_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC6_PTR->CFPR[5U].R), (volatile uint32 *)&(EQADC6_PTR->CFPR[6U].R), (volatile uint32 *)&(EQADC6_PTR->CFPR[7U].R)}
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

/* EQADC Result FIFO Pop Registers (EQADC_RFPR) */
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_RFPR[ADC_EQADC_MAX_INSTANCE][EQADC_RFIFO_COUNT] =
{
    {(volatile uint32 *)&(EQADC0_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC0_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC0_PTR->RFPR[2U].R), (volatile uint32 *)&(EQADC0_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC0_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC0_PTR->RFPR[5U].R), (volatile uint32 *)&(EQADC0_PTR->RFPR[6U].R), (volatile uint32 *)&(EQADC0_PTR->RFPR[7U].R)},
    {(volatile uint32 *)&(EQADC1_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC1_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC1_PTR->RFPR[2U].R), (volatile uint32 *)&(EQADC1_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC1_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC1_PTR->RFPR[5U].R), (volatile uint32 *)&(EQADC1_PTR->RFPR[6U].R), (volatile uint32 *)&(EQADC1_PTR->RFPR[7U].R)},
    {(volatile uint32 *)&(EQADC2_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC2_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC2_PTR->RFPR[2U].R), (volatile uint32 *)&(EQADC2_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC2_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC2_PTR->RFPR[5U].R), (volatile uint32 *)&(EQADC2_PTR->RFPR[6U].R), (volatile uint32 *)&(EQADC2_PTR->RFPR[7U].R)},
    {(volatile uint32 *)&(EQADC3_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC3_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC3_PTR->RFPR[2U].R), (volatile uint32 *)&(EQADC3_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC3_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC3_PTR->RFPR[5U].R), (volatile uint32 *)&(EQADC3_PTR->RFPR[6U].R), (volatile uint32 *)&(EQADC3_PTR->RFPR[7U].R)},
    {(volatile uint32 *)&(EQADC4_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC4_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC4_PTR->RFPR[2U].R), (volatile uint32 *)&(EQADC4_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC4_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC4_PTR->RFPR[5U].R), (volatile uint32 *)&(EQADC4_PTR->RFPR[6U].R), (volatile uint32 *)&(EQADC4_PTR->RFPR[7U].R)},
    {(volatile uint32 *)&(EQADC5_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC5_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC5_PTR->RFPR[2U].R), (volatile uint32 *)&(EQADC5_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC5_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC5_PTR->RFPR[5U].R), (volatile uint32 *)&(EQADC5_PTR->RFPR[6U].R), (volatile uint32 *)&(EQADC5_PTR->RFPR[7U].R)},
    {(volatile uint32 *)&(EQADC6_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC6_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC6_PTR->RFPR[2U].R), (volatile uint32 *)&(EQADC6_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC6_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC6_PTR->RFPR[5U].R), (volatile uint32 *)&(EQADC6_PTR->RFPR[6U].R), (volatile uint32 *)&(EQADC6_PTR->RFPR[7U].R)}
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

/* EQADC CFIFO Control Registers (EQADC_CFCR) */
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_CFCR[ADC_EQADC_MAX_INSTANCE][EQADC_CFCR_U32_REG_COUNT] =
{
    {(volatile uint32 *)&(EQADC0_PTR->CFCR0.R), (volatile uint32 *)&(EQADC0_PTR->CFCR1.R), (volatile uint32 *)&(EQADC0_PTR->CFCR2.R), (volatile uint32 *)&(EQADC0_PTR->CFCR3.R)},
    {(volatile uint32 *)&(EQADC1_PTR->CFCR0.R), (volatile uint32 *)&(EQADC1_PTR->CFCR1.R), (volatile uint32 *)&(EQADC1_PTR->CFCR2.R), (volatile uint32 *)&(EQADC1_PTR->CFCR3.R)},
    {(volatile uint32 *)&(EQADC2_PTR->CFCR0.R), (volatile uint32 *)&(EQADC2_PTR->CFCR1.R), (volatile uint32 *)&(EQADC2_PTR->CFCR2.R), (volatile uint32 *)&(EQADC2_PTR->CFCR3.R)},
    {(volatile uint32 *)&(EQADC3_PTR->CFCR0.R), (volatile uint32 *)&(EQADC3_PTR->CFCR1.R), (volatile uint32 *)&(EQADC3_PTR->CFCR2.R), (volatile uint32 *)&(EQADC3_PTR->CFCR3.R)},
    {(volatile uint32 *)&(EQADC4_PTR->CFCR0.R), (volatile uint32 *)&(EQADC4_PTR->CFCR1.R), (volatile uint32 *)&(EQADC4_PTR->CFCR2.R), (volatile uint32 *)&(EQADC4_PTR->CFCR3.R)},
    {(volatile uint32 *)&(EQADC5_PTR->CFCR0.R), (volatile uint32 *)&(EQADC5_PTR->CFCR1.R), (volatile uint32 *)&(EQADC5_PTR->CFCR2.R), (volatile uint32 *)&(EQADC5_PTR->CFCR3.R)},
    {(volatile uint32 *)&(EQADC6_PTR->CFCR0.R), (volatile uint32 *)&(EQADC6_PTR->CFCR1.R), (volatile uint32 *)&(EQADC6_PTR->CFCR2.R), (volatile uint32 *)&(EQADC6_PTR->CFCR3.R)}
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

/* EQADC Interrupt and DMA Control Registers (EQADC_IDCR) */
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_IDCR[ADC_EQADC_MAX_INSTANCE][EQADC_IDCR_U32_REG_COUNT] =
{
    {(volatile uint32 *)&(EQADC0_PTR->IDCR0.R), (volatile uint32 *)&(EQADC0_PTR->IDCR1.R), (volatile uint32 *)&(EQADC0_PTR->IDCR2.R), (volatile uint32 *)&(EQADC0_PTR->IDCR3.R)},
    {(volatile uint32 *)&(EQADC1_PTR->IDCR0.R), (volatile uint32 *)&(EQADC1_PTR->IDCR1.R), (volatile uint32 *)&(EQADC1_PTR->IDCR2.R), (volatile uint32 *)&(EQADC1_PTR->IDCR3.R)},
    {(volatile uint32 *)&(EQADC2_PTR->IDCR0.R), (volatile uint32 *)&(EQADC2_PTR->IDCR1.R), (volatile uint32 *)&(EQADC2_PTR->IDCR2.R), (volatile uint32 *)&(EQADC2_PTR->IDCR3.R)},
    {(volatile uint32 *)&(EQADC3_PTR->IDCR0.R), (volatile uint32 *)&(EQADC3_PTR->IDCR1.R), (volatile uint32 *)&(EQADC3_PTR->IDCR2.R), (volatile uint32 *)&(EQADC3_PTR->IDCR3.R)},
    {(volatile uint32 *)&(EQADC4_PTR->IDCR0.R), (volatile uint32 *)&(EQADC4_PTR->IDCR1.R), (volatile uint32 *)&(EQADC4_PTR->IDCR2.R), (volatile uint32 *)&(EQADC4_PTR->IDCR3.R)},
    {(volatile uint32 *)&(EQADC5_PTR->IDCR0.R), (volatile uint32 *)&(EQADC5_PTR->IDCR1.R), (volatile uint32 *)&(EQADC5_PTR->IDCR2.R), (volatile uint32 *)&(EQADC5_PTR->IDCR3.R)},
    {(volatile uint32 *)&(EQADC6_PTR->IDCR0.R), (volatile uint32 *)&(EQADC6_PTR->IDCR1.R), (volatile uint32 *)&(EQADC6_PTR->IDCR2.R), (volatile uint32 *)&(EQADC6_PTR->IDCR3.R)}
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

/* EQADC CFIFO Transfer Counter Registers (EQADC_CFTCR) */
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_CFTCR[ADC_EQADC_MAX_INSTANCE][EQADC_CFTCR_U32_REG_COUNT] =
{
    {(volatile uint32 *)&(EQADC0_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC0_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC0_PTR->CFTCR2.R), (volatile uint32 *)&(EQADC0_PTR->CFTCR3.R)},
    {(volatile uint32 *)&(EQADC1_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC1_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC1_PTR->CFTCR2.R), (volatile uint32 *)&(EQADC1_PTR->CFTCR3.R)},
    {(volatile uint32 *)&(EQADC2_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC2_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC2_PTR->CFTCR2.R), (volatile uint32 *)&(EQADC2_PTR->CFTCR3.R)},
    {(volatile uint32 *)&(EQADC3_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC3_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC3_PTR->CFTCR2.R), (volatile uint32 *)&(EQADC3_PTR->CFTCR3.R)},
    {(volatile uint32 *)&(EQADC4_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC4_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC4_PTR->CFTCR2.R), (volatile uint32 *)&(EQADC4_PTR->CFTCR3.R)},
    {(volatile uint32 *)&(EQADC5_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC5_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC5_PTR->CFTCR2.R), (volatile uint32 *)&(EQADC5_PTR->CFTCR3.R)},
    {(volatile uint32 *)&(EQADC6_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC6_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC6_PTR->CFTCR2.R), (volatile uint32 *)&(EQADC6_PTR->CFTCR3.R)}
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
/* EQADC CFIFO Trigger Delay Registers (EQADC_DLY) */
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_DLY[ADC_EQADC_MAX_INSTANCE][EQADC_CFIFO_COUNT] =
{
    {(volatile uint32 *)&(EQADC0_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC0_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC0_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC0_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC0_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC0_PTR->DLY[5U].R), (volatile uint32 *)&(EQADC0_PTR->DLY[6U].R), (volatile uint32 *)&(EQADC0_PTR->DLY[7U].R)},
    {(volatile uint32 *)&(EQADC1_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC1_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC1_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC1_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC1_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC1_PTR->DLY[5U].R), (volatile uint32 *)&(EQADC1_PTR->DLY[6U].R), (volatile uint32 *)&(EQADC1_PTR->DLY[7U].R)},
    {(volatile uint32 *)&(EQADC2_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC2_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC2_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC2_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC2_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC2_PTR->DLY[5U].R), (volatile uint32 *)&(EQADC2_PTR->DLY[6U].R), (volatile uint32 *)&(EQADC2_PTR->DLY[7U].R)},
    {(volatile uint32 *)&(EQADC3_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC3_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC3_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC3_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC3_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC3_PTR->DLY[5U].R), (volatile uint32 *)&(EQADC3_PTR->DLY[6U].R), (volatile uint32 *)&(EQADC3_PTR->DLY[7U].R)},
    {(volatile uint32 *)&(EQADC4_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC4_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC4_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC4_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC4_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC4_PTR->DLY[5U].R), (volatile uint32 *)&(EQADC4_PTR->DLY[6U].R), (volatile uint32 *)&(EQADC4_PTR->DLY[7U].R)},
    {(volatile uint32 *)&(EQADC5_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC5_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC5_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC5_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC5_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC5_PTR->DLY[5U].R), (volatile uint32 *)&(EQADC5_PTR->DLY[6U].R), (volatile uint32 *)&(EQADC5_PTR->DLY[7U].R)},
    {(volatile uint32 *)&(EQADC6_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC6_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC6_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC6_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC6_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC6_PTR->DLY[5U].R), (volatile uint32 *)&(EQADC6_PTR->DLY[6U].R), (volatile uint32 *)&(EQADC6_PTR->DLY[7U].R)}
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */

#else
    #error "EQADC FIFO COUNT error!"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_6 */
#else
    #error "EQADC FIFO COUNT is not defined!"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */

/* EQADC CFIFO Status Snapshot Registers (EQADC_CFSSR) */
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_CFSSR[ADC_EQADC_MAX_INSTANCE][2U] =
{
    {(volatile uint32 *)&(EQADC0_PTR->CFSSR0.R), (volatile uint32 *)&(EQADC0_PTR->CFSSR1.R)},
    {(volatile uint32 *)&(EQADC1_PTR->CFSSR0.R), (volatile uint32 *)&(EQADC1_PTR->CFSSR1.R)},
    {(volatile uint32 *)&(EQADC2_PTR->CFSSR0.R), (volatile uint32 *)&(EQADC2_PTR->CFSSR1.R)},
    {(volatile uint32 *)&(EQADC3_PTR->CFSSR0.R), (volatile uint32 *)&(EQADC3_PTR->CFSSR1.R)},
    {(volatile uint32 *)&(EQADC4_PTR->CFSSR0.R), (volatile uint32 *)&(EQADC4_PTR->CFSSR1.R)},
    {(volatile uint32 *)&(EQADC5_PTR->CFSSR0.R), (volatile uint32 *)&(EQADC5_PTR->CFSSR1.R)},
    {(volatile uint32 *)&(EQADC6_PTR->CFSSR0.R), (volatile uint32 *)&(EQADC6_PTR->CFSSR1.R)}
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_INIT
#include "Adc_MemMap.h"
static eDMATransferConfigType tcdcfg =
{
    .srcAddr                  = 0,
    .destAddr                 = 0,
    .srcTransDataSize         = EDMA_TRANSFER_SIZE_1B,
    .destTransDataSize        = EDMA_TRANSFER_SIZE_1B,
    .srcAddrOffset            = 0,
    .destAddrOffset           = 0,
    .srcAddrAdjustLast        = 0,
    .destAddrAdjustLast       = 0,
    .srcAddrModulo            = EDMA_ADDRESS_MODULO_OFF,
    .destAddrModulo           = EDMA_ADDRESS_MODULO_OFF,
    .minorTransByte           = 0,
    .featureScatterGatherEn   = FALSE,
    .featureScatterGatherNextDescriptor   = 0U,
    .completeIntEn            = TRUE,
    .lpTransConfigPtr         = NULL_PTR,
}; /* PRQA S 0704 */
#define ADC_STOP_SEC_VAR_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_INIT
#include "Adc_MemMap.h"
static eDMALoopTransferConfigType looptcdcfg = 
{
    .majorLpIterCnt       = 0,
    .srcAddrOffsetEn      = FALSE,
    .dstAddrOffsetEn      = FALSE,
    .minorLpOffset        = 0,
    .minorLpLinkEn        = FALSE,
    .minorLpLinkChn       = 0U,
    .majorLpLinkEn        = FALSE,
    .majorLpLinkChn       = 0U,
};
#define ADC_STOP_SEC_VAR_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC Module Configuration Register: Set ICEAx (EQADC_MCR: ICEAx)
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_AdcIdx: 0, 1 (On-chip ADC0 / ADC1)
 *        bAdc_EnDis: FALSE: Disable
 *                    TRUE: Enable
 *
 * @note  ICEAn enables the EQADC to abort on-chip ADCn current conversion
 *          and to start the immediate conversion command from CFIFO0 in the
 *          requested ADCn.
 *******************************************************************************/
ADC_INLINE FUNC(void, ADC_CODE) EQADC_MCR_SetICEAxEnDis(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_AdcIdx, CONST(boolean , ADC_CONST) bAdc_EnDis)
{
    VAR(uint8, AUTOMATIC) u8Adc_ICEAxEnDis = (uint8)((uint8)(u8Adc_AdcIdx << 1U) | ((bAdc_EnDis == TRUE) ? 1U : 0U));

    switch (u8Adc_ICEAxEnDis)
    {
        case 0U:
        {   /* Disable CFIFO0 Immediate Conversion Command (ADC0) */
            *(EQADC_MCR[u8Adc_Instance]) &= ~EQADC_MCR_ICEA0_MASK;/* polyspace RTE:NIV,IDP */
            break;
        }
        case 1U:
        {   /* Enable CFIFO0 Immediate Conversion Command (ADC0) */
            *(EQADC_MCR[u8Adc_Instance]) |= EQADC_MCR_ICEA0_MASK;/* polyspace RTE:NIV,IDP */
            break;
        }
        case 2U:
        {   /* Disable CFIFO0 Immediate Conversion Command (ADC1) */
            *(EQADC_MCR[u8Adc_Instance]) &= ~EQADC_MCR_ICEA1_MASK;/* polyspace RTE:NIV,IDP */
            break;
        }
        case 3U:
        {   /* Enable CFIFO0 Immediate Conversion Command (ADC1) */
            *(EQADC_MCR[u8Adc_Instance]) |= EQADC_MCR_ICEA1_MASK;/* polyspace RTE:NIV,IDP */
            break;
        }
        default:
        {   /* Nothing to do */
            break;
        }
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC Module Configuration Register: Get Debug enable/disable
 *          (EQADC_MCR: DBG)
 *
 * @param u8Adc_Instance: EQADC instance
 *        [out] FALSE: Disable
 *              TRUE: Enable
 *
 * @note  The DBG field defines the EQADC response to a debug mode entry request.
 *******************************************************************************/
ADC_INLINE FUNC(uint8, ADC_CODE) EQADC_MCR_GetDebugEnDis(CONST(uint8, ADC_CONST) u8Adc_Instance)
{
    return (uint8)(((*(EQADC_MCR[u8Adc_Instance]) & EQADC_MCR_DBG_MASK) == 0U) ? FALSE : TRUE);/* polyspace RTE:NIV,IDP */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC Module Configuration Register: Set Debug enable/disable
 *          (EQADC_MCR: DBG)
 *
 * @param u8Adc_Instance: EQADC instance
 *        bAdc_EnDis: FALSE: Disable
 *               TRUE: Enable
 *
 * @note  The DBG field defines the EQADC response to a debug mode entry request.
 *******************************************************************************/
ADC_INLINE FUNC(void, ADC_CODE) EQADC_MCR_SetDebugEnDis(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(boolean , ADC_CONST) bAdc_EnDis)
{
    if (FALSE == bAdc_EnDis)
    {
        *(EQADC_MCR[u8Adc_Instance]) &= ~EQADC_MCR_DBG_MASK;/* polyspace RTE:NIV,IDP */
    }
    else
    {
        *(EQADC_MCR[u8Adc_Instance]) |= EQADC_MCR_DBG_MASK;/* polyspace RTE:NIV,IDP */
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(uint8, ADC_CODE) EQADC_ETDFR_GetDFL(CONST(uint8, ADC_CONST) u8Adc_Instance)
{
    return (uint8)(*(EQADC_ETDFR[u8Adc_Instance]) & EQADC_ETDFR_DFL_MASK);/* polyspace RTE:IDP */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC External Trigger Digital Filter Register (EQADC_ETDFR: DFL)
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_DigiFilterLen: Digital filter length
 *
 * @note  FilterPeriod = (SystemClockPeriod * 2^DFL) + 1(SystemClockPeriod).
 *******************************************************************************/
ADC_INLINE FUNC(void, ADC_CODE) EQADC_ETDFR_SetDFL(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_DigiFilterLen)
{
    *(EQADC_ETDFR[u8Adc_Instance]) = ((uint32)u8Adc_DigiFilterLen & EQADC_ETDFR_DFL_MASK);/* polyspace RTE:IDP */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC CFIFO Control Register 0: Get CFEEE0 (EQADC_CFCR0: CFEEE0)
 *
 * @param u8Adc_Instance: EQADC instance
 *        [out] FALSE: Disable
 *              TRUE: Enable
 *
 * @note  CFIFO0 Entry Number Extension Enable/Disable.
 *******************************************************************************/
ADC_INLINE FUNC(uint8, ADC_CODE) EQADC_CFCR0_GetCfifo0EntryExtEnDis(CONST(uint8, ADC_CONST) u8Adc_Instance)
{
    return (uint8)(((*(EQADC_CFCR[u8Adc_Instance][0U]) & EQADC_CFCR0_CFEEE0_MASK) == 0U) ? FALSE : TRUE);/* polyspace RTE:NIV,IDP */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC CFIFO Control Register 0: Set CFEEE0 (EQADC_CFCR0: CFEEE0)
 *
 * @param u8Adc_Instance: EQADC instance
 *        bAdc_EnDis: FALSE: Disable
 *                    TRUE: Enable
 *
 * @note  CFIFO0 Entry Number Extension Enable/Disable.
 *******************************************************************************/
ADC_INLINE FUNC(void, ADC_CODE) EQADC_CFCR0_SetCfifo0EntryExtEnDis(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(boolean , ADC_CONST) bAdc_EnDis)
{
    if (FALSE == bAdc_EnDis)
    {
        /* CFIFO0 Entry Number Extension Disable */
        *(EQADC_CFCR[u8Adc_Instance][0U]) &= ~EQADC_CFCR0_CFEEE0_MASK;/* polyspace RTE:NIV,IDP */
    }
    else
    {
        /* CFIFO0 Entry Number Extension Enable */
        *(EQADC_CFCR[u8Adc_Instance][0U]) |= EQADC_CFCR0_CFEEE0_MASK;/* polyspace RTE:NIV,IDP */
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC CFIFO Control Register 0 (EQADC_CFCR0: STRME0)
 *
 * @param u8Adc_Instance: EQADC instance
 *        bAdc_EnDis: 0, 1 (Disable, Enable)
 *
 * @note  CFIFO0 Streaming Mode Operation Enable/Disable.
 *******************************************************************************/
ADC_INLINE FUNC(void, ADC_CODE) EQADC_CFCR0_Cfifo0StreamModeEnDis(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(boolean, ADC_CONST) bAdc_EnDis)
{
    if (0U == bAdc_EnDis)
    {
        /* CFIFO0 Entry Number Extension Disable */
        *(EQADC_CFCR[u8Adc_Instance][0U]) &= ~EQADC_CFCR0_STRME0_MASK;/* polyspace RTE:NIV,IDP */
    }
    else
    {
        /* CFIFO0 Entry Number Extension Enable */
        *(EQADC_CFCR[u8Adc_Instance][0U]) |= EQADC_CFCR0_STRME0_MASK;/* polyspace RTE:NIV,IDP */
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC CFIFO Control Register x (EQADC_CFCRx: SSEy)
 *          (x = 0...2, y = 0...5) / (x = 0...3, y = 0...7).
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_CfifoIdx: CFIFO Index (Index = y)
 *
 * @note  Writing a "1" to SSEx will set the EQADC_FISR[SSSx] field if the
 *          CFIFO is in single-scan mode. SSEx always is read as "0".
 *******************************************************************************/
ADC_INLINE FUNC(void, ADC_CODE) EQADC_CFCRxSetSSE(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx)
{
    VAR(uint8, AUTOMATIC) u8Adc_CFCRx = u8Adc_CfifoIdx / 2U;  /* EQADC CFIFO Control Register x */

    if((u8Adc_Instance < ADC_EQADC_MAX_INSTANCE) && (u8Adc_CFCRx < EQADC_CFCR_U32_REG_COUNT))
    {
        if ((u8Adc_CfifoIdx % 2U) == 0U)
        {   /* EQADC CfifoIdx: 0/2/4/6 */
            *(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) |= EQADC_CFCR0_SSE0_MASK;/* polyspace RTE:NIV,IDP */
        }
        else
        {   /* EQADC CfifoIdx: 1/3/5/7 */
            *(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) |= EQADC_CFCR0_SSE1_MASK;/* polyspace RTE:NIV,IDP */
        }
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC CFIFO Control Register x (EQADC_CFCRx: SSEy)
 *          (x = 0...2, y = 0...5) / (x = 0...3, y = 0...7).
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_CfifoIdx: CFIFO Index (Index = y)(Synchronous: 0 & 1, 2 & 3, 4 & 5,6&7)
 *******************************************************************************/
ADC_INLINE FUNC(void, ADC_CODE) EQADC_CFCRxSetSSE_Sync(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx)
{
    VAR(uint8, AUTOMATIC) u8Adc_CFCRx = u8Adc_CfifoIdx / 2U;  /* EQADC CFIFO Control Register x */
    /* EQADC CfifoIdx synchronous: 0 & 1, 2 & 3, 4 & 5, 6 & 7 */
    *(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) |= (EQADC_CFCR0_SSE0_MASK | EQADC_CFCR0_SSE1_MASK);/* polyspace RTE:NIV,IDP */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*********************************************************************************
 * @brief EQADC CFIFO Control Register x (EQADC_CFCRx: CFINVy)
 *          (x = 0...2, y = 0...5) / (x = 0...3, y = 0...7).
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_CfifoIdx: CFIFO Index (Index = y)
 *
 * @note  Writing CFINVy only invalidates commands stored in CFIFOx;
 *          previously transferred commands that are waiting for execution,
 *          that is commands stored in the CBuffers, will still be executed,
 *          and results generated by them will be stored in the appropriate RFIFO.
 *        CFINVy must not be written unless the MODEy is configured to disabled,
 *          and CFIFO status is IDLE.
 *********************************************************************************/
FUNC(void, ADC_CODE) EQADC_CFCRxSetInvalidate(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx)
{
    VAR(uint8, AUTOMATIC) u8Adc_CFCRx = u8Adc_CfifoIdx / 2U;  /* EQADC CFIFO Control Register x */
    if((u8Adc_Instance < ADC_EQADC_MAX_INSTANCE) && (u8Adc_CFCRx < EQADC_CFCR_U32_REG_COUNT))
    {
        if ((u8Adc_CfifoIdx % 2U) == 0U)
        {   /* EQADC CfifoIdx: 0/2/4/6 */
            *(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) |= EQADC_CFCR0_CFINV0_MASK;/* polyspace RTE:NIV,IDP */
        }
        else
        {   /* EQADC CfifoIdx: 1/3/5/7 */
            *(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) |= EQADC_CFCR0_CFINV1_MASK;/* polyspace RTE:NIV,IDP */
        }
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC CFIFO Control Register x (EQADC_CFCRx: MODEy)
 *          (x = 0...2, y = 0...5) / (x = 0...3, y = 0...7).
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_CfifoIdx: CFIFO Index (Index = y)
 *
 * @param [out]Get the current mode of CFIFO.
 *******************************************************************************/
ADC_INLINE FUNC(uint32, ADC_CODE) EQADC_CFCRxGetMode(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx)
{
    VAR(uint8, AUTOMATIC) u8Adc_CFCRx = u8Adc_CfifoIdx / 2U;  /* EQADC CFIFO Control Register x */
    VAR(uint32, AUTOMATIC) u32Adc_CfifoModeCurrent;
    if ((u8Adc_CfifoIdx % 2U) == 0U)
    {   /* EQADC CfifoIdx: 0/2/4/6 */
        u32Adc_CfifoModeCurrent = (*(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) & EQADC_CFCR0_MODE0_MASK) >> EQADC_CFCR0_MODE0_SHIFT; /* polyspace RTE:NIV,IDP */
    }
    else
    {   /* EQADC CfifoIdx: 1/3/5/7 */
        u32Adc_CfifoModeCurrent = (*(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) & EQADC_CFCR0_MODE1_MASK) >> EQADC_CFCR0_MODE1_SHIFT; /* polyspace RTE:NIV,IDP */
    }

    return u32Adc_CfifoModeCurrent;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(uint32, ADC_CODE) EQADC_CFCR0_GetAMode0(CONST(uint8, ADC_CONST) u8Adc_Instance)
{
    return ((*(EQADC_CFCR[u8Adc_Instance][0U]) & EQADC_CFCR0_AMODE0_MASK) >> EQADC_CFCR0_AMODE0_SHIFT); /* polyspace RTE:NIV,IDP */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC CFIFO Control Register 0 (EQADC_CFCR0: AMODE0)
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_Cfifo0AdvanceMode0: Set the advance trigger operation mode for CFIFO0
 *
 * @note  If AMODE0 is not disabled, it must not be changed to any other mode
 *          besides disabled.
 *******************************************************************************/
ADC_INLINE FUNC(void, ADC_CODE) EQADC_CFCR0_SetAMode0(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_Cfifo0AdvanceMode0)
{
    *(EQADC_CFCR[u8Adc_Instance][0U]) &= ~EQADC_CFCR0_AMODE0_MASK;/* polyspace RTE:NIV,IDP */
    *(EQADC_CFCR[u8Adc_Instance][0U]) |= EQADC_CFCR0_AMODE0(u8Adc_Cfifo0AdvanceMode0);/* polyspace RTE:NIV,IDP */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC Interrupt and DMA Control Registers x (EQADC_IDCRx)
 *          (x = 0...2)  / (x = 0...3)
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_FifoIdx: CFIFO/RFIFO Index (0...5) / (0...7)
 *
 * @param [out] u8Adc_IDCRx result(16 bits)
 *
 * @note  The EQADC Interrupt Control Registers (EQADC_IDCR) contain bits to
 *          enable the generation of interrupt or DMA requests when the
 *          corresponding flag bits are set in "EQADC FIFO
 *          and Interrupt Status Registers (EQADC_FISR)".
 *******************************************************************************/
ADC_INLINE FUNC(uint16, ADC_CODE) EQADC_IDCRx_GetFifoIntDma(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_FifoIdx)
{
    VAR(uint8, AUTOMATIC) u8Adc_IDCRx = u8Adc_FifoIdx / 2U;  /* EQADC Interrupt and DMA Control Registers x */
    VAR(uint16, AUTOMATIC) u16Adc_IDCRxData = 0U;
    if((u8Adc_Instance < ADC_EQADC_MAX_INSTANCE) && (u8Adc_IDCRx < EQADC_IDCR_U32_REG_COUNT))
    {
        if ((u8Adc_FifoIdx % 2U) == 0U)
        {   /* EQADC FifoIdx: 0/2/4/6 */
            u16Adc_IDCRxData = (uint16)((*(EQADC_IDCR[u8Adc_Instance][u8Adc_IDCRx]) >> 16U) & 0xFFFFU);/* polyspace RTE:NIV,IDP */
        }
        else
        {   /* EQADC FifoIdx: 1/3/5/7 */
            u16Adc_IDCRxData = (uint16)(*(EQADC_IDCR[u8Adc_Instance][u8Adc_IDCRx]) & 0xFFFFU);/* polyspace RTE:NIV,IDP */
        }
    }

    return u16Adc_IDCRxData;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
static FUNC(void, ADC_CODE) Adc_DemReportErrorStatus(VAR(Dem_EventIdType, AUTOMATIC) Adc_EventId, VAR(Dem_EventStatusType, AUTOMATIC) Adc_EventStatus)
{
    (void)Dem_SetEventStatus((Dem_EventIdType)Adc_EventId, Adc_EventStatus);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* ADC_DEM_REPORT_ERROR_ENABLE == STD_ON */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC Interrupt and DMA Control Registers x (EQADC_IDCRx)
 *          (x = 0...2)  / (x = 0...3)
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_FifoIdx: CFIFO/RFIFO Index (0...5) / (0...7)
 *        u16Adc_FifoIntDmaMask: IDCRx mask(16 bits)
 *        bAdc_EnDis: 0: Disable, 1: Enable;
 *                    0: INT, 1: DMA(FifoIntDmaMask = EQADC_INT_DMA_SEL_xxx)
 *
 * @note  The EQADC Interrupt Control Registers (EQADC_IDCR) contain bits to
 *          enable the generation of interrupt or DMA requests when the
 *          corresponding flag bits are set in "EQADC FIFO
 *          and Interrupt Status Registers (EQADC_FISR)".
 *******************************************************************************/
FUNC(void, ADC_CODE) EQADC_IDCRx_FifoIntDmaEnDis(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_FifoIdx, CONST(uint16, ADC_CONST) u16Adc_FifoIntDmaMask, CONST(boolean, ADC_CONST) bAdc_EnDis)
{
    VAR(uint8, AUTOMATIC) u8Adc_IDCRx = u8Adc_FifoIdx / 2U;  /* EQADC Interrupt and DMA Control Registers x */
    VAR(uint8, AUTOMATIC) u8Adc_IDCRxEnDis = (uint8)(((uint8)((u8Adc_FifoIdx % 2U) << 1U)) | ((bAdc_EnDis == TRUE) ? 1U : 0U));

    if((u8Adc_Instance < ADC_EQADC_MAX_INSTANCE) && (u8Adc_IDCRx < EQADC_IDCR_U32_REG_COUNT))
    {
        switch (u8Adc_IDCRxEnDis)
        {
            case 0U:
            {   /* EQADC FifoIdx: 0/2/4, interrupt and DMA disable. */
                *(EQADC_IDCR[u8Adc_Instance][u8Adc_IDCRx]) &= ~((uint32)u16Adc_FifoIntDmaMask << 16U);/* polyspace RTE:NIV,IDP */
                break;
            }
            case 1U:
            {   /* EQADC FifoIdx: 0/2/4, interrupt and DMA enable. */
                *(EQADC_IDCR[u8Adc_Instance][u8Adc_IDCRx]) |= ((uint32)u16Adc_FifoIntDmaMask << 16U);/* polyspace RTE:NIV,IDP */
                break;
            }
            case 2U:
            {   /* EQADC FifoIdx: 1/3/5, interrupt and DMA disable. */
                *(EQADC_IDCR[u8Adc_Instance][u8Adc_IDCRx]) &= ~((uint32)u16Adc_FifoIntDmaMask);/* polyspace RTE:NIV,IDP */
                break;
            }
            case 3U:
            {   /* EQADC FifoIdx: 1/3/5, interrupt and DMA enable. */
                *(EQADC_IDCR[u8Adc_Instance][u8Adc_IDCRx]) |= (uint32)u16Adc_FifoIntDmaMask;/* polyspace RTE:NIV,IDP */
                break;
            }
            default:
            {   /* Nothing to do */
                break;
            }
        }
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC CFIFO Transfer Counter Register x (EQADC_CFTCR)
 *          (x = 0...2)  / (x = 0...3)
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_CfifoIdx: CFIFO Index (0...5) / (0...7)
 *
 * @note  TC_CFx counts the number of commands which have been completely
 *          transferred from CFIFOx.
 *******************************************************************************/
ADC_INLINE FUNC(uint16, ADC_CODE) EQADC_CFTCRx_GetCfifoTransCount(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx)
{
    VAR(uint8, AUTOMATIC) u8Adc_CFTCRx = u8Adc_CfifoIdx / 2U; /* EQADC CFIFO Transfer Counter Register x */
    VAR(uint16, AUTOMATIC) u16Adc_TransCount = 0U;
    if ((u8Adc_CfifoIdx % 2U) == 0U)
    {   /* EQADC CfifoIdx: 0/2/4/6 */
        u16Adc_TransCount = (uint16)((*(EQADC_CFTCR[u8Adc_Instance][u8Adc_CFTCRx]) & EQADC_CFTCR0_TC_CF0_MASK) >> EQADC_CFTCR0_TC_CF0_SHIFT); /* polyspace RTE:IDP */
    }
    else
    {   /* EQADC CfifoIdx: 1/3/5/7 */
        u16Adc_TransCount = (uint16)(*(EQADC_CFTCR[u8Adc_Instance][u8Adc_CFTCRx]) & EQADC_CFTCR0_TC_CF1_MASK);/* polyspace RTE:IDP */
    }

    return u16Adc_TransCount;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC CFIFO Transfer Counter Register x (EQADC_CFTCR)
 *          (x = 0...2)  / (x = 0...3)
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_CfifoIdx: CFIFO Index (0...5) / (0...7)
 *        u16Adc_CfifoTransCount: Transfer Counter for CFIFOx
 *
 * @note  TC_CFx counts the number of commands which have been completely
 *          transferred from CFIFOx.
 *******************************************************************************/
ADC_INLINE FUNC(void, ADC_CODE) EQADC_CFTCRx_SetCfifoTransCount(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, CONST(uint16, ADC_CONST) u16Adc_CfifoTransCount)
{
    VAR(uint8, AUTOMATIC) u8Adc_CFTCRx = u8Adc_CfifoIdx / 2U; /* EQADC CFIFO Transfer Counter Register x */
    if ((u8Adc_CfifoIdx % 2U) == 0U)
    {   /* EQADC CfifoIdx: 0/2/4/6 */
        *(EQADC_CFTCR[u8Adc_Instance][u8Adc_CFTCRx]) = EQADC_CFTCR0_TC_CF0(u16Adc_CfifoTransCount);/* polyspace RTE:IDP */
    }
    else
    {   /* EQADC CfifoIdx: 1/3/5/7 */
        *(EQADC_CFTCR[u8Adc_Instance][u8Adc_CFTCRx]) = EQADC_CFTCR0_TC_CF1(u16Adc_CfifoTransCount);    /* PRQA S 2985 *//* polyspace RTE:IDP */
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC CFIFO Status Snapshot Register x: TCB (EQADC_CFSSR)(x = 0...1)
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_CfifoIdx: CFIFO Index (0...5) / (0...7)
 *        u8Adc_AdcIdx: 0, 1 (On-chip ADC0 / ADC1)
 *        [out] CFIFO Status
 *
 * @note  CFIFO Status at Transfer to CBuffer0/1.
 *******************************************************************************/
ADC_INLINE FUNC(uint8, ADC_CODE) EQADC_CFSSRx_GetCfifoStatusAtTCB_Snapshot(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, CONST(uint8, ADC_CONST) u8Adc_AdcIdx)
{
    VAR(uint32, AUTOMATIC) u32Adc_TempVal;
    VAR(uint32, AUTOMATIC) u32Adc_Tcb = 0U;
    VAR(uint8, AUTOMATIC) u8Adc_Tcb = 0U;
    u32Adc_TempVal = (EQADC_CFSSR0_CFS0_TCB0_SHIFT - (EQADC_CFSSR0_CFS0_TCB0_WIDTH * (uint32)u8Adc_CfifoIdx));

    u32Adc_Tcb = (*EQADC_CFSSR[u8Adc_Instance][u8Adc_AdcIdx] >> u32Adc_TempVal);/* polyspace RTE:IDP */

    u8Adc_Tcb = (uint8)(u32Adc_Tcb & (EQADC_CFSSR0_CFS0_TCB0_MASK >> EQADC_CFSSR0_CFS0_TCB0_SHIFT));
    return u8Adc_Tcb;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC CFIFO Status Snapshot Register x: LCFTCB
 *          (EQADC_CFSSR)(x = 0...1)
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_AdcIdx: 0, 1 (On-chip ADC0 / ADC1)
 *        [out] CFIFO Index (0...5)
 *
 * @note  Last CFIFO to Transfer to CBuffer0/1.
 *******************************************************************************/
ADC_INLINE FUNC(uint8, ADC_CODE) EQADC_CFSSRx_GetLastCfifoToTCB_Snapshot(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_AdcIdx)
{
    return (uint8)((*(EQADC_CFSSR[u8Adc_Instance][u8Adc_AdcIdx]) & EQADC_CFSSR0_LCFTCB0_MASK) >> EQADC_CFSSR0_LCFTCB0_SHIFT); /* polyspace RTE:IDP */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC CFIFO Status Snapshot Register x: TC_LCFTCB
 *          (EQADC_CFSSR)(x = 0...1)
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_AdcIdx: 0, 1 (On-chip ADC0 / ADC1)
 *        [out] Transfer Counter
 *
 * @note  Transfer Counter for Last CFIFO to transfer commands to CBuffer0/1.
 *******************************************************************************/
ADC_INLINE FUNC(uint16, ADC_CODE) EQADC_CFSSRx_GetTransCountForLastCfifoToTCB_Snapshot(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_AdcIdx)
{
    return (uint16)((*(EQADC_CFSSR[u8Adc_Instance][u8Adc_AdcIdx]) & EQADC_CFSSR0_TC_LCFTCB0_MASK) >> EQADC_CFSSR0_TC_LCFTCB0_SHIFT); /* polyspace RTE:IDP */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC Red Line Client Configuration Register (EQADC_REDLCCR)
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_ClientIdx: 0 or 1
 *        u8Adc_RedLineTbaseBitSel: Red Line TimeBase Bits Selection m (m=1,2)
 *        u8Adc_RedLineSlotSel: Red Line Server Data Slot Selector m (m=1,2)
 *
 * @note  TC_CFx counts the number of commands which have been completely
 *          transferred from CFIFOx.
 *******************************************************************************/
ADC_INLINE FUNC(void, ADC_CODE) EQADC_REDLCCR_SetREDBS_SRVx(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_ClientIdx, CONST(uint8, ADC_CONST) u8Adc_RedLineTbaseBitSel, CONST(uint8, ADC_CONST) u8Adc_RedLineSlotSel)
{
    /* EQADC Red Line Client Configuration Register (EQADC_REDLCCR) */
    static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_REDLCCR[ADC_EQADC_MAX_INSTANCE] =
    {
        (volatile uint32 *)&(EQADC0_PTR->STACCCR.R),
        (volatile uint32 *)&(EQADC1_PTR->STACCCR.R),
        (volatile uint32 *)&(EQADC2_PTR->STACCCR.R),
        (volatile uint32 *)&(EQADC3_PTR->STACCCR.R),
        (volatile uint32 *)&(EQADC4_PTR->STACCCR.R),
        (volatile uint32 *)&(EQADC5_PTR->STACCCR.R),
        (volatile uint32 *)&(EQADC6_PTR->STACCCR.R)
    };

    switch (u8Adc_ClientIdx)
    {
        case 0U:
        {
            *(EQADC_REDLCCR[u8Adc_Instance]) &= ~(EQADC_STACCCR_SRV1_MASK | EQADC_STACCCR_STACBS1_MASK); /* polyspace RTE:IDP */
            *(EQADC_REDLCCR[u8Adc_Instance]) |= (EQADC_STACCCR_STACBS1(u8Adc_RedLineTbaseBitSel) | EQADC_STACCCR_SRV1(u8Adc_RedLineSlotSel)); /* PRQA S 2985 */ /* polyspace RTE:IDP */
            break;
        }
        case 1U:
        {
            *(EQADC_REDLCCR[u8Adc_Instance]) &= ~(EQADC_STACCCR_SRV2_MASK | EQADC_STACCCR_STACBS2_MASK); /* polyspace RTE:IDP */
            *(EQADC_REDLCCR[u8Adc_Instance]) |= (EQADC_STACCCR_STACBS2(u8Adc_RedLineTbaseBitSel) | EQADC_STACCCR_SRV2(u8Adc_RedLineSlotSel)); /* polyspace RTE:IDP */
            break;
        }
        default:
        {   /* Nothing to do */
            break;
        }
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(uint32, ADC_CODE) EQADC_CFxRw_GetCfifoData(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, CONST(uint8, ADC_CONST) u8Adc_EntryIdx)
{
#if defined(RESOURCE_SUPPORT_EQADC_FIFO_CNT)
#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_6)
    /* EQADC CFIFO Registers (EQADC_CFxRw) (x = 0, .., 5; w = 0, .., 3) */
    static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_CFxRw[ADC_EQADC_MAX_INSTANCE][EQADC_CFIFO_COUNT] =
    {
        {(volatile uint32 *)&(EQADC0_PTR->CF0R[0U].R), (volatile uint32 *)&(EQADC0_PTR->CF1R[0U].R), (volatile uint32 *)&(EQADC0_PTR->CF2R[0U].R), (volatile uint32 *)&(EQADC0_PTR->CF3R[0U].R), (volatile uint32 *)&(EQADC0_PTR->CF4R[0U].R), (volatile uint32 *)&(EQADC0_PTR->CF5R[0U].R)},
        {(volatile uint32 *)&(EQADC1_PTR->CF0R[0U].R), (volatile uint32 *)&(EQADC1_PTR->CF1R[0U].R), (volatile uint32 *)&(EQADC1_PTR->CF2R[0U].R), (volatile uint32 *)&(EQADC1_PTR->CF3R[0U].R), (volatile uint32 *)&(EQADC1_PTR->CF4R[0U].R), (volatile uint32 *)&(EQADC1_PTR->CF5R[0U].R)},
        {(volatile uint32 *)&(EQADC2_PTR->CF0R[0U].R), (volatile uint32 *)&(EQADC2_PTR->CF1R[0U].R), (volatile uint32 *)&(EQADC2_PTR->CF2R[0U].R), (volatile uint32 *)&(EQADC2_PTR->CF3R[0U].R), (volatile uint32 *)&(EQADC2_PTR->CF4R[0U].R), (volatile uint32 *)&(EQADC2_PTR->CF5R[0U].R)},
        {(volatile uint32 *)&(EQADC3_PTR->CF0R[0U].R), (volatile uint32 *)&(EQADC3_PTR->CF1R[0U].R), (volatile uint32 *)&(EQADC3_PTR->CF2R[0U].R), (volatile uint32 *)&(EQADC3_PTR->CF3R[0U].R), (volatile uint32 *)&(EQADC3_PTR->CF4R[0U].R), (volatile uint32 *)&(EQADC3_PTR->CF5R[0U].R)},
        {(volatile uint32 *)&(EQADC4_PTR->CF0R[0U].R), (volatile uint32 *)&(EQADC4_PTR->CF1R[0U].R), (volatile uint32 *)&(EQADC4_PTR->CF2R[0U].R), (volatile uint32 *)&(EQADC4_PTR->CF3R[0U].R), (volatile uint32 *)&(EQADC4_PTR->CF4R[0U].R), (volatile uint32 *)&(EQADC4_PTR->CF5R[0U].R)},
        {(volatile uint32 *)&(EQADC5_PTR->CF0R[0U].R), (volatile uint32 *)&(EQADC5_PTR->CF1R[0U].R), (volatile uint32 *)&(EQADC5_PTR->CF2R[0U].R), (volatile uint32 *)&(EQADC5_PTR->CF3R[0U].R), (volatile uint32 *)&(EQADC5_PTR->CF4R[0U].R), (volatile uint32 *)&(EQADC5_PTR->CF5R[0U].R)},
        {(volatile uint32 *)&(EQADC6_PTR->CF0R[0U].R), (volatile uint32 *)&(EQADC6_PTR->CF1R[0U].R), (volatile uint32 *)&(EQADC6_PTR->CF2R[0U].R), (volatile uint32 *)&(EQADC6_PTR->CF3R[0U].R), (volatile uint32 *)&(EQADC6_PTR->CF4R[0U].R), (volatile uint32 *)&(EQADC6_PTR->CF5R[0U].R)}
    };
#elif (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
    /* EQADC CFIFO Registers (EQADC_CFxRw) (x = 0, .., 7; w = 0, .., 3) */
    static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_CFxRw[ADC_EQADC_MAX_INSTANCE][EQADC_CFIFO_COUNT] =
    {
        {(volatile uint32 *)&(EQADC0_PTR->CF0R[0U].R), (volatile uint32 *)&(EQADC0_PTR->CF1R[0U].R), (volatile uint32 *)&(EQADC0_PTR->CF2R[0U].R), (volatile uint32 *)&(EQADC0_PTR->CF3R[0U].R), (volatile uint32 *)&(EQADC0_PTR->CF4R[0U].R), (volatile uint32 *)&(EQADC0_PTR->CF5R[0U].R), (volatile uint32 *)&(EQADC0_PTR->CF6R[0U].R), (volatile uint32 *)&(EQADC0_PTR->CF7R[0U].R)},
        {(volatile uint32 *)&(EQADC1_PTR->CF0R[0U].R), (volatile uint32 *)&(EQADC1_PTR->CF1R[0U].R), (volatile uint32 *)&(EQADC1_PTR->CF2R[0U].R), (volatile uint32 *)&(EQADC1_PTR->CF3R[0U].R), (volatile uint32 *)&(EQADC1_PTR->CF4R[0U].R), (volatile uint32 *)&(EQADC1_PTR->CF5R[0U].R), (volatile uint32 *)&(EQADC1_PTR->CF6R[0U].R), (volatile uint32 *)&(EQADC1_PTR->CF7R[0U].R)},
        {(volatile uint32 *)&(EQADC2_PTR->CF0R[0U].R), (volatile uint32 *)&(EQADC2_PTR->CF1R[0U].R), (volatile uint32 *)&(EQADC2_PTR->CF2R[0U].R), (volatile uint32 *)&(EQADC2_PTR->CF3R[0U].R), (volatile uint32 *)&(EQADC2_PTR->CF4R[0U].R), (volatile uint32 *)&(EQADC2_PTR->CF5R[0U].R), (volatile uint32 *)&(EQADC2_PTR->CF6R[0U].R), (volatile uint32 *)&(EQADC2_PTR->CF7R[0U].R)},
        {(volatile uint32 *)&(EQADC3_PTR->CF0R[0U].R), (volatile uint32 *)&(EQADC3_PTR->CF1R[0U].R), (volatile uint32 *)&(EQADC3_PTR->CF2R[0U].R), (volatile uint32 *)&(EQADC3_PTR->CF3R[0U].R), (volatile uint32 *)&(EQADC3_PTR->CF4R[0U].R), (volatile uint32 *)&(EQADC3_PTR->CF5R[0U].R), (volatile uint32 *)&(EQADC3_PTR->CF6R[0U].R), (volatile uint32 *)&(EQADC3_PTR->CF7R[0U].R)},
        {(volatile uint32 *)&(EQADC4_PTR->CF0R[0U].R), (volatile uint32 *)&(EQADC4_PTR->CF1R[0U].R), (volatile uint32 *)&(EQADC4_PTR->CF2R[0U].R), (volatile uint32 *)&(EQADC4_PTR->CF3R[0U].R), (volatile uint32 *)&(EQADC4_PTR->CF4R[0U].R), (volatile uint32 *)&(EQADC4_PTR->CF5R[0U].R), (volatile uint32 *)&(EQADC4_PTR->CF6R[0U].R), (volatile uint32 *)&(EQADC4_PTR->CF7R[0U].R)},
        {(volatile uint32 *)&(EQADC5_PTR->CF0R[0U].R), (volatile uint32 *)&(EQADC5_PTR->CF1R[0U].R), (volatile uint32 *)&(EQADC5_PTR->CF2R[0U].R), (volatile uint32 *)&(EQADC5_PTR->CF3R[0U].R), (volatile uint32 *)&(EQADC5_PTR->CF4R[0U].R), (volatile uint32 *)&(EQADC5_PTR->CF5R[0U].R), (volatile uint32 *)&(EQADC5_PTR->CF6R[0U].R), (volatile uint32 *)&(EQADC5_PTR->CF7R[0U].R)},
        {(volatile uint32 *)&(EQADC6_PTR->CF0R[0U].R), (volatile uint32 *)&(EQADC6_PTR->CF1R[0U].R), (volatile uint32 *)&(EQADC6_PTR->CF2R[0U].R), (volatile uint32 *)&(EQADC6_PTR->CF3R[0U].R), (volatile uint32 *)&(EQADC6_PTR->CF4R[0U].R), (volatile uint32 *)&(EQADC6_PTR->CF5R[0U].R), (volatile uint32 *)&(EQADC6_PTR->CF6R[0U].R), (volatile uint32 *)&(EQADC6_PTR->CF7R[0U].R)}
    };
#else
    #error "EQADC FIFO COUNT error!"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_6 */
#else
    #error "EQADC FIFO COUNT is not defined!"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */

    return (EQADC_CFxRw[u8Adc_Instance][u8Adc_CfifoIdx][u8Adc_EntryIdx] & EQADC_CF0R_CFIFO0_DATAW_MASK);/* polyspace RTE:NIV,IDP */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(uint16, ADC_CODE) EQADC_RFxRw_GetRfifoData(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_RfifoIdx, CONST(uint8, ADC_CONST) u8Adc_EntryIdx)
{
#if defined(RESOURCE_SUPPORT_EQADC_FIFO_CNT)
#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_6)
    /* EQADC RFIFO Registers (EQADC_RFxRw) (x = 0, .., 5; w = 0, .., 3/w = 0, .., 7; w depends on RESOURCE_SUPPORT_EQADC_RFIFO_ENTRY_CNT) */
    static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_RFxRw[ADC_EQADC_MAX_INSTANCE][EQADC_RFIFO_COUNT] =
    {
        {(volatile uint32 *)&(EQADC0_PTR->RF0R[0U].R), (volatile uint32 *)&(EQADC0_PTR->RF1R[0U].R), (volatile uint32 *)&(EQADC0_PTR->RF2R[0U].R), (volatile uint32 *)&(EQADC0_PTR->RF3R[0U].R), (volatile uint32 *)&(EQADC0_PTR->RF4R[0U].R), (volatile uint32 *)&(EQADC0_PTR->RF5R[0U].R)},
        {(volatile uint32 *)&(EQADC1_PTR->RF0R[0U].R), (volatile uint32 *)&(EQADC1_PTR->RF1R[0U].R), (volatile uint32 *)&(EQADC1_PTR->RF2R[0U].R), (volatile uint32 *)&(EQADC1_PTR->RF3R[0U].R), (volatile uint32 *)&(EQADC1_PTR->RF4R[0U].R), (volatile uint32 *)&(EQADC1_PTR->RF5R[0U].R)},
        {(volatile uint32 *)&(EQADC2_PTR->RF0R[0U].R), (volatile uint32 *)&(EQADC2_PTR->RF1R[0U].R), (volatile uint32 *)&(EQADC2_PTR->RF2R[0U].R), (volatile uint32 *)&(EQADC2_PTR->RF3R[0U].R), (volatile uint32 *)&(EQADC2_PTR->RF4R[0U].R), (volatile uint32 *)&(EQADC2_PTR->RF5R[0U].R)},
        {(volatile uint32 *)&(EQADC3_PTR->RF0R[0U].R), (volatile uint32 *)&(EQADC3_PTR->RF1R[0U].R), (volatile uint32 *)&(EQADC3_PTR->RF2R[0U].R), (volatile uint32 *)&(EQADC3_PTR->RF3R[0U].R), (volatile uint32 *)&(EQADC3_PTR->RF4R[0U].R), (volatile uint32 *)&(EQADC3_PTR->RF5R[0U].R)},
        {(volatile uint32 *)&(EQADC4_PTR->RF0R[0U].R), (volatile uint32 *)&(EQADC4_PTR->RF1R[0U].R), (volatile uint32 *)&(EQADC4_PTR->RF2R[0U].R), (volatile uint32 *)&(EQADC4_PTR->RF3R[0U].R), (volatile uint32 *)&(EQADC4_PTR->RF4R[0U].R), (volatile uint32 *)&(EQADC4_PTR->RF5R[0U].R)},
        {(volatile uint32 *)&(EQADC5_PTR->RF0R[0U].R), (volatile uint32 *)&(EQADC5_PTR->RF1R[0U].R), (volatile uint32 *)&(EQADC5_PTR->RF2R[0U].R), (volatile uint32 *)&(EQADC5_PTR->RF3R[0U].R), (volatile uint32 *)&(EQADC5_PTR->RF4R[0U].R), (volatile uint32 *)&(EQADC5_PTR->RF5R[0U].R)},
        {(volatile uint32 *)&(EQADC6_PTR->RF0R[0U].R), (volatile uint32 *)&(EQADC6_PTR->RF1R[0U].R), (volatile uint32 *)&(EQADC6_PTR->RF2R[0U].R), (volatile uint32 *)&(EQADC6_PTR->RF3R[0U].R), (volatile uint32 *)&(EQADC6_PTR->RF4R[0U].R), (volatile uint32 *)&(EQADC6_PTR->RF5R[0U].R)}
    };
#elif (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
    /* EQADC RFIFO Registers (EQADC_RFxRw) (x = 0, .., 7; w = 0, .., 3/w = 0, .., 7; w depends on RESOURCE_SUPPORT_EQADC_RFIFO_ENTRY_CNT) */
    static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_RFxRw[ADC_EQADC_MAX_INSTANCE][EQADC_RFIFO_COUNT] =
    {
        {(volatile uint32 *)&(EQADC0_PTR->RF0R[0U].R), (volatile uint32 *)&(EQADC0_PTR->RF1R[0U].R), (volatile uint32 *)&(EQADC0_PTR->RF2R[0U].R), (volatile uint32 *)&(EQADC0_PTR->RF3R[0U].R), (volatile uint32 *)&(EQADC0_PTR->RF4R[0U].R), (volatile uint32 *)&(EQADC0_PTR->RF5R[0U].R), (volatile uint32 *)&(EQADC0_PTR->RF6R[0U].R), (volatile uint32 *)&(EQADC0_PTR->RF7R[0U].R)},
        {(volatile uint32 *)&(EQADC1_PTR->RF0R[0U].R), (volatile uint32 *)&(EQADC1_PTR->RF1R[0U].R), (volatile uint32 *)&(EQADC1_PTR->RF2R[0U].R), (volatile uint32 *)&(EQADC1_PTR->RF3R[0U].R), (volatile uint32 *)&(EQADC1_PTR->RF4R[0U].R), (volatile uint32 *)&(EQADC1_PTR->RF5R[0U].R), (volatile uint32 *)&(EQADC1_PTR->RF6R[0U].R), (volatile uint32 *)&(EQADC1_PTR->RF7R[0U].R)},
        {(volatile uint32 *)&(EQADC2_PTR->RF0R[0U].R), (volatile uint32 *)&(EQADC2_PTR->RF1R[0U].R), (volatile uint32 *)&(EQADC2_PTR->RF2R[0U].R), (volatile uint32 *)&(EQADC2_PTR->RF3R[0U].R), (volatile uint32 *)&(EQADC2_PTR->RF4R[0U].R), (volatile uint32 *)&(EQADC2_PTR->RF5R[0U].R), (volatile uint32 *)&(EQADC2_PTR->RF6R[0U].R), (volatile uint32 *)&(EQADC2_PTR->RF7R[0U].R)},
        {(volatile uint32 *)&(EQADC3_PTR->RF0R[0U].R), (volatile uint32 *)&(EQADC3_PTR->RF1R[0U].R), (volatile uint32 *)&(EQADC3_PTR->RF2R[0U].R), (volatile uint32 *)&(EQADC3_PTR->RF3R[0U].R), (volatile uint32 *)&(EQADC3_PTR->RF4R[0U].R), (volatile uint32 *)&(EQADC3_PTR->RF5R[0U].R), (volatile uint32 *)&(EQADC3_PTR->RF6R[0U].R), (volatile uint32 *)&(EQADC3_PTR->RF7R[0U].R)},
        {(volatile uint32 *)&(EQADC4_PTR->RF0R[0U].R), (volatile uint32 *)&(EQADC4_PTR->RF1R[0U].R), (volatile uint32 *)&(EQADC4_PTR->RF2R[0U].R), (volatile uint32 *)&(EQADC4_PTR->RF3R[0U].R), (volatile uint32 *)&(EQADC4_PTR->RF4R[0U].R), (volatile uint32 *)&(EQADC4_PTR->RF5R[0U].R), (volatile uint32 *)&(EQADC4_PTR->RF6R[0U].R), (volatile uint32 *)&(EQADC4_PTR->RF7R[0U].R)},
        {(volatile uint32 *)&(EQADC5_PTR->RF0R[0U].R), (volatile uint32 *)&(EQADC5_PTR->RF1R[0U].R), (volatile uint32 *)&(EQADC5_PTR->RF2R[0U].R), (volatile uint32 *)&(EQADC5_PTR->RF3R[0U].R), (volatile uint32 *)&(EQADC5_PTR->RF4R[0U].R), (volatile uint32 *)&(EQADC5_PTR->RF5R[0U].R), (volatile uint32 *)&(EQADC5_PTR->RF6R[0U].R), (volatile uint32 *)&(EQADC5_PTR->RF7R[0U].R)},
        {(volatile uint32 *)&(EQADC6_PTR->RF0R[0U].R), (volatile uint32 *)&(EQADC6_PTR->RF1R[0U].R), (volatile uint32 *)&(EQADC6_PTR->RF2R[0U].R), (volatile uint32 *)&(EQADC6_PTR->RF3R[0U].R), (volatile uint32 *)&(EQADC6_PTR->RF4R[0U].R), (volatile uint32 *)&(EQADC6_PTR->RF5R[0U].R), (volatile uint32 *)&(EQADC6_PTR->RF6R[0U].R), (volatile uint32 *)&(EQADC6_PTR->RF7R[0U].R)}
    };
#else
    #error "EQADC FIFO COUNT error!"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_6 */
#else
    #error "EQADC FIFO COUNT is not defined!"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */

    return (uint16)(EQADC_RFxRw[u8Adc_Instance][u8Adc_RfifoIdx][u8Adc_EntryIdx] & EQADC_RF0R_RFIFO0_DATAW_MASK);/* polyspace RTE:NIV,IDP */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

/*******************************************************************************
 * @brief EQADC CFIFO trigger source setting.
 *******************************************************************************/
#if defined(RESOURCE_SUPPORT_SIUL2_IP)
#if defined(RESOURCE_SUPPORT_EQADC_FIFO_CNT)
#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_6)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_ISELx_SetCfifoTrig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, CONST(uint8, ADC_CONST) u8Adc_TrigSourceVal)
{
    static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_TRIG_CFIFO_01[5u] =
    {
        (volatile uint32 *)&(SIUL2_PTR->ISEL5.R),    /* EQADC0_ADC0/EQADC0_ADC1: CFIFO0/CFIFO1 */
        (volatile uint32 *)&(SIUL2_PTR->ISEL5.R),    /* EQADC1_ADC2/EQADC1_ADC3: CFIFO0/CFIFO1 */
        (volatile uint32 *)&(SIUL2_PTR->ISEL7.R),    /* EQADC2_ADC4/EQADC2_ADC5: CFIFO0/CFIFO1 */
        (volatile uint32 *)&(SIUL2_PTR->ISEL7.R),    /* EQADC3_ADC6/EQADC3_ADC7: CFIFO0/CFIFO1 */
        (volatile uint32 *)&(SIUL2_PTR->ISEL7.R)     /* EQADC4_ADC8/EQADC4_ADC9: CFIFO0/CFIFO1 */
    };

    static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_TRIG_CFIFO_2345[5u] =
    {
        (volatile uint32 *)&(SIUL2_PTR->ISEL4.R),    /* EQADC0_ADC0/EQADC0_ADC1: CFIFO2/CFIFO3/CFIFO4/CFIFO5 */
        (volatile uint32 *)&(SIUL2_PTR->ISEL4.R),    /* EQADC1_ADC2/EQADC1_ADC3: CFIFO2/CFIFO3/CFIFO4/CFIFO5 */
        (volatile uint32 *)&(SIUL2_PTR->ISEL6.R),    /* EQADC2_ADC4/EQADC2_ADC5: CFIFO2/CFIFO3/CFIFO4/CFIFO5 */
        (volatile uint32 *)&(SIUL2_PTR->ISEL6.R),    /* EQADC3_ADC6/EQADC3_ADC7: CFIFO2/CFIFO3/CFIFO4/CFIFO5 */
        (volatile uint32 *)&(SIUL2_PTR->ISEL6.R)     /* EQADC4_ADC8/EQADC4_ADC9: CFIFO2/CFIFO3/CFIFO4/CFIFO5 */
    };

    SchM_Enter_Adc_EXCLUSIVE_AREA_10();
    if ((u8Adc_Instance < 5u) && (u8Adc_CfifoIdx < EQADC_CFIFO_COUNT))
    {
        switch (u8Adc_CfifoIdx)
        {
            case 0U:
            {   /* CFIFO_0 */
                *(EQADC_TRIG_CFIFO_01[u8Adc_Instance]) &= ~0x7F0000UL;/* polyspace RTE:NIV,IDP,OBAI */
                *(EQADC_TRIG_CFIFO_01[u8Adc_Instance]) |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 16U)) & 0x7F0000U); /* polyspace RTE:NIV,IDP */
                break;
            }
            case 1U:
            {   /* CFIFO_1 */
                *(EQADC_TRIG_CFIFO_01[u8Adc_Instance]) &= ~0x7F000000UL;/* polyspace RTE:NIV,IDP,OBAI */
                *(EQADC_TRIG_CFIFO_01[u8Adc_Instance]) |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 24U)) & 0x7F000000U); /* polyspace RTE:NIV,IDP */
                break;
            }
            case 2U:
            {   /* CFIFO_2 */
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) &= ~0x7FUL;/* polyspace RTE:NIV,IDP,OBAI */
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 0U)) & 0x7FU); /* PRQA S 2985 */ /* polyspace RTE:NIV,IDP */
                break;
            }
            case 3U:
            {   /* CFIFO_3 */
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) &= ~0x7F00UL;/* polyspace RTE:NIV,IDP,OBAI */
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 8U)) & 0x7F00U); /* polyspace RTE:NIV,IDP */
                break;
            }
            case 4U:
            {   /* CFIFO_4 */
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) &= ~0x7F0000UL;/* polyspace RTE:NIV,IDP,OBAI */
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 16U)) & 0x7F0000U); /* polyspace RTE:NIV,IDP */
                break;
            }
            case 5U:
            {   /* CFIFO_5 */
                    *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) &= ~0x7F000000UL;/* polyspace RTE:NIV,IDP,OBAI */
                    *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 24U)) & 0x7F000000U); /* polyspace RTE:NIV,IDP */
                break;
            }
            default:
            {   /* Nothing to do */
                break;
            }
        }
    }
    SchM_Exit_Adc_EXCLUSIVE_AREA_10();
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#elif (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_ISELx_SetCfifoTrig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, CONST(uint8, ADC_CONST) u8Adc_TrigSourceVal)
{
    static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_TRIG_CFIFO_0167[2u] =
    {
        (volatile uint32 *)&(SIUL2_PTR->ISEL7.R),    /* EQADC0_ADC0/EQADC0_ADC1: CFIFO0/CFIFO1/CFIFO6/CFIFO7 */
        (volatile uint32 *)&(SIUL2_PTR->ISEL5.R)     /* EQADC1_ADC2/EQADC1_ADC3: CFIFO0/CFIFO1/CFIFO6/CFIFO7 */
    };

    static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_TRIG_CFIFO_2345[2u] =
    {
        (volatile uint32 *)&(SIUL2_PTR->ISEL6.R),    /* EQADC0_ADC0/EQADC0_ADC1: CFIFO2/CFIFO3/CFIFO4/CFIFO5 */
        (volatile uint32 *)&(SIUL2_PTR->ISEL4.R)     /* EQADC1_ADC2/EQADC1_ADC3: CFIFO2/CFIFO3/CFIFO4/CFIFO5 */
    };

    SchM_Enter_Adc_EXCLUSIVE_AREA_10();
    if ((u8Adc_Instance < 2u) && (u8Adc_CfifoIdx < EQADC_CFIFO_COUNT))
    {
        switch (u8Adc_CfifoIdx)
        {
            case 0U:
            {   /* CFIFO_0 */
                *(EQADC_TRIG_CFIFO_0167[u8Adc_Instance]) &= ~0x7F0000UL;/* polyspace RTE:NIV,IDP,OBAI */
                *(EQADC_TRIG_CFIFO_0167[u8Adc_Instance]) |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 16U)) & 0x7F0000U); /* polyspace RTE:NIV,IDP */
                break;
            }
            case 1U:
            {   /* CFIFO_1 */
                *(EQADC_TRIG_CFIFO_0167[u8Adc_Instance]) &= ~0x7F000000UL;/* polyspace RTE:NIV,IDP,OBAI */
                *(EQADC_TRIG_CFIFO_0167[u8Adc_Instance]) |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 24U)) & 0x7F000000U); /* polyspace RTE:NIV,IDP */
                break;
            }
            case 2U:
            {   /* CFIFO_2 */
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) &= ~0x7FUL;/* polyspace RTE:NIV,IDP,OBAI */
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 0U)) & 0x7FU); /* PRQA S 2985 */ /* polyspace RTE:NIV,IDP */
                break;
            }
            case 3U:
            {   /* CFIFO_3 */
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) &= ~0x7F00UL;/* polyspace RTE:NIV,IDP,OBAI */
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 8U)) & 0x7F00U); /* polyspace RTE:NIV,IDP */
                break;
            }
            case 4U:
            {   /* CFIFO_4 */
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) &= ~0x7F0000UL;/* polyspace RTE:NIV,IDP,OBAI */
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 16U)) & 0x7F0000U); /* polyspace RTE:NIV,IDP */
                break;
            }
            case 5U:
            {   /* CFIFO_5 */
                    *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) &= ~0x7F000000UL;/* polyspace RTE:NIV,IDP,OBAI */
                    *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 24U)) & 0x7F000000U); /* polyspace RTE:NIV,IDP */
                break;
            }
            case 6U:
            {   /* CFIFO_6 */
                *(EQADC_TRIG_CFIFO_0167[u8Adc_Instance]) &= ~0x7F00UL;/* polyspace RTE:NIV,IDP,OBAI */
                *(EQADC_TRIG_CFIFO_0167[u8Adc_Instance]) |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 8U)) & 0x7F00U); /* polyspace RTE:NIV,IDP */
                break;
            }
            case 7U:
            {   /* CFIFO_7 */
                *(EQADC_TRIG_CFIFO_0167[u8Adc_Instance]) &= ~0x7FUL;/* polyspace RTE:NIV,IDP,OBAI */
                *(EQADC_TRIG_CFIFO_0167[u8Adc_Instance]) |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 0U)) & 0x7FU); /* PRQA S 2985 */ /* polyspace RTE:NIV,IDP */
                break;
            }
            default:
            {   /* Nothing to do */
                break;
            }
        }
    }
    SchM_Exit_Adc_EXCLUSIVE_AREA_10();
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#else
    #error "EQADC FIFO COUNT error!"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_6 */
#else
    #error "EQADC FIFO COUNT is not defined!"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */

#elif defined(RESOURCE_SUPPORT_SIUL_IP)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_ISELx_SetCfifoTrig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, CONST(uint8, ADC_CONST) u8Adc_TrigSourceVal)
{
    static CONST(volatile uint32, ADC_CONST) EQADC_CfifoTrig_Offset[ADC_EQADC_MAX_INSTANCE][EQADC_CFIFO_COUNT] =
    {
        {2u,  1u,  0u , 7u , 6u , 5u }, /* EQADC0_ADC01: CFIFO0~5 */
        {11u, 10u, 9u , 8u , 15u, 14u}, /* EQADC1_ADC23: CFIFO0~5 */
        {12u, 19u, 18u, 17u, 16u, 23u}, /* EQADC2_ADC45: CFIFO0~5 */
        {21u, 20u, 27u, 26u, 25u, 24u}, /* EQADC3_ADC67: CFIFO0~5 */
        {30u, 29u, 28u, 35u, 34u, 33u}, /* EQADC4_ADC89: CFIFO0~5 */
        {39u, 38u, 37u, 36u, 43u, 42u}, /* EQADC5_ADC1011: CFIFO0~5 */
        {40u, 47u, 46u, 45u, 44u, 51u}  /* EQADC6_ADC12: CFIFO0~5 */
    };

    SchM_Enter_Adc_EXCLUSIVE_AREA_10();
    if ((u8Adc_Instance < ADC_EQADC_MAX_INSTANCE) && (u8Adc_CfifoIdx < EQADC_CFIFO_COUNT))
    {
        (*(volatile uint8 *)(SIUL_BASEADDR + SIUL_ISEL0_OFFSET_ADDR + EQADC_CfifoTrig_Offset[u8Adc_Instance][u8Adc_CfifoIdx])) = (uint8)u8Adc_TrigSourceVal;/* polyspace RTE:IDP */
    }
    SchM_Exit_Adc_EXCLUSIVE_AREA_10();
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#else
    #error "No valid IO control!"
#endif  /* RESOURCE_SUPPORT_SIUL2_IP */

#if defined(RESOURCE_SUPPORT_SIUL2_IP)
#if defined(RESOURCE_SUPPORT_EQADC_FIFO_CNT)
#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_6)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_ISELx_SetCfifo0AdvanceTrig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_AdvanceTrigVal)
{
    SchM_Enter_Adc_EXCLUSIVE_AREA_11();
    switch (u8Adc_Instance)
    {
        case 0U:
        case 1U:
        {   /* EQADC0_ADC0/EQADC0_ADC1, EQADC1_ADC2/EQADC1_ADC3 */
            SIUL2.ISEL9.R &= ~0x1F0000UL;
            SIUL2.ISEL9.R |= (((uint32)(((uint32)(u8Adc_AdvanceTrigVal)) << 16U)) & 0x1F0000U);
            break;
        }
        case 2U:
        case 3U:
        case 4U:
        {   /* EQADC2_ADC4/EQADC2_ADC5, EQADC3_ADC6/EQADC3_ADC7, EQADC4_ADC8/EQADC4_ADC9 */
            SIUL2.ISEL9.R &= ~0x1FUL;
            SIUL2.ISEL9.R |= (((uint32)(((uint32)(u8Adc_AdvanceTrigVal)) << 0U)) & 0x1FU); /* PRQA S 2985 */
            break;
        }
        default:
        {   /* Nothing to do */
            break;
        }
    }
    SchM_Exit_Adc_EXCLUSIVE_AREA_11();
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#elif (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_ISELx_SetCfifo0AdvanceTrig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_AdvanceTrigVal)
{
    SchM_Enter_Adc_EXCLUSIVE_AREA_11();
    switch (u8Adc_Instance)
    {
        case 0U:
        {   /* EQADC0_ADC0/EQADC0_ADC1 */
            SIUL2.ISEL9.R &= ~0x1FUL;
            SIUL2.ISEL9.R |= (((uint32)(((uint32)(u8Adc_AdvanceTrigVal)) << 0U)) & 0x1FU);  /* PRQA S 2985 */
            break;
        }
        case 1U:
        {   /* EQADC1_ADC2/EQADC1_ADC3 */
            SIUL2.ISEL9.R &= ~0x1F0000UL;
            SIUL2.ISEL9.R |= (((uint32)(((uint32)(u8Adc_AdvanceTrigVal)) << 16U)) & 0x1F0000U);
            break;
        }
        default:
        {   /* Nothing to do */
            break;
        }
    }
    SchM_Exit_Adc_EXCLUSIVE_AREA_11();
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#else
    #error "EQADC FIFO COUNT error!"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_6 */
#else
    #error "EQADC FIFO COUNT is not defined!"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */

#elif defined(RESOURCE_SUPPORT_SIUL_IP)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_ISELx_SetCfifo0AdvanceTrig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_AdvanceTrigVal)
{
    static CONST(volatile uint32, ADC_CONST) EQADC_Cfifo0ATrig_Offset[ADC_EQADC_MAX_INSTANCE] =
    {
        3u, 4u, 13u, 22u, 31u, 32u, 41u /* EQADC instance 0~6 */
    };

    SchM_Enter_Adc_EXCLUSIVE_AREA_11();
    if (u8Adc_Instance < ADC_EQADC_MAX_INSTANCE)
    {
        (*(volatile uint8 *)(SIUL_BASEADDR + SIUL_ISEL0_OFFSET_ADDR + EQADC_Cfifo0ATrig_Offset[u8Adc_Instance])) = (uint8)u8Adc_AdvanceTrigVal;/* polyspace RTE:IDP */
    }
    SchM_Exit_Adc_EXCLUSIVE_AREA_11();
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#else
    #error "No valid IO control!"
#endif  /* RESOURCE_SUPPORT_SIUL2_IP */

#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
/*******************************************************************************
 * @brief GTM to EQADC Connections
 *
 * @param GtmInstance: GTM instance(always = 0)
 *        TrigRegIdx: Trigger register index(0 ~ 4)
 *        TrigRegMemberIdx: Trigger register member index(0 ~ 11)
 *        TrigSel: Trigger selection(0 ~ 15)
 *
 * @note  GTMi, i = instance;
 *          TRIGx[y], x = TrigRegIdx, y = TrigRegMemberIdx.
 *******************************************************************************/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) GTM_to_EQADC_Connections(CONST(uint8, ADC_CONST) u8Adc_GtmInstance, CONST(uint8, ADC_CONST) u8Adc_trigregidx, CONST(uint8, ADC_CONST) u8Adc_TrigRegMemberIdx, CONST(uint8, ADC_CONST) u8Adc_GTM_ADC_TRIG_OUTSEL)
{
    uint32 u32RegVal;

    GTM4.GLS[u8Adc_GtmInstance].GTMINT.GTMMCR.R &= ~0x40000000UL; /* GTM Module Enable */

    if (u8Adc_TrigRegMemberIdx < 8u)  /* TrigRegMemberIdx: 0 ~ 7 */
    {
        u32RegVal = GTM4.GLS[u8Adc_GtmInstance].ADCTRIG[u8Adc_trigregidx].OUT0.R;
        u32RegVal &= ~(uint32)(GTM_ADC_TRIG_OUTSEL_MASK << (u8Adc_TrigRegMemberIdx * 4u));
        u32RegVal |= (uint32)((u8Adc_GTM_ADC_TRIG_OUTSEL & GTM_ADC_TRIG_OUTSEL_MASK) << (u8Adc_TrigRegMemberIdx * 4u));
        GTM4.GLS[u8Adc_GtmInstance].ADCTRIG[u8Adc_trigregidx].OUT0.R = u32RegVal;
    }
    else    /* TrigRegMemberIdx: 8 ~ 11 */
    {
        u32RegVal = GTM4.GLS[u8Adc_GtmInstance].ADCTRIG[u8Adc_trigregidx].OUT1.R;
        u32RegVal &= ~(uint32)(GTM_ADC_TRIG_OUTSEL_MASK << ((u8Adc_TrigRegMemberIdx - 8u) * 4u));
        u32RegVal |= (uint32)((u8Adc_GTM_ADC_TRIG_OUTSEL & GTM_ADC_TRIG_OUTSEL_MASK) << ((u8Adc_TrigRegMemberIdx - 8u) * 4u));
        GTM4.GLS[u8Adc_GtmInstance].ADCTRIG[u8Adc_trigregidx].OUT1.R = u32RegVal;
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */

/*******************************************************************************
 * Static function declaration.
 *******************************************************************************/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
static FUNC(void, ADC_CODE) EQADC_WriteConfigCmdSSE(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, CONST(uint8, ADC_CONST) u8Adc_AdcIdx, CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) eAdc_AdcAddr, CONST(uint16, ADC_CONST) u16Adc_AdcRegVal);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_ReadConfigCmdSSE(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, CONST(uint8, ADC_CONST) u8Adc_AdcIdx, CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) eAdc_AdcAddr, CONST(uint8, ADC_CONST) u8Adc_RfifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_DeinitRedLineClient(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_ClientIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_DeinitAdcCtrl(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_AdcIdx, CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_DeinitAdcTimeConfig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
static FUNC(void, ADC_CODE) EQADC_DeinitAltConfig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(Eqadc_AltConfigSelType, ADC_CONST) eAdc_AltCfgSel, CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_GetDefaultCfifoCfg(CONSTP2VAR(Eqadc_CfifoConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_CfifoCfgPtr);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_GetDefaultRwConfigCmd(CONSTP2VAR(Eqadc_ConfigCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConfigCmdPtr);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_EQADC_CALIBRATION
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_GetDefaultConvCmd(CONSTP2VAR(Eqadc_ConvCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConvCmdPtr);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_CALIBRATION */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(uint32, ADC_CODE) EQADC_GetCfifoRwConfigCmd(CONSTP2CONST(Eqadc_ConfigCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConfigCmdPtr);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(uint32, ADC_CODE) EQADC_GetCfifoConversionCmd(CONSTP2CONST(Eqadc_ConvCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConvCmdPtr);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_SetAdcConfig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONSTP2CONST(Eqadc_AdcConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_AdcConfig, CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_SetAltConfig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONSTP2CONST(Eqadc_AlternateConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_AltConfig, CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_SetRedLineClientConfig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONSTP2CONST(Eqadc_RedLineClientConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_RedLineClientCfg);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_SetDmaForCmd(CONST(uint8, ADC_CONST) u8Adc_Instance, CONSTP2CONST(Eqadc_CfifoConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_CfifoCfgPtr);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_SetDmaForResult(CONST(uint8, ADC_CONST) u8Adc_Instance, CONSTP2CONST(Eqadc_ResultDmaConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_RfifoCfgPtr);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(status_t, ADC_CODE)  EQADC_LLD_ClearRfifoAllData(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_RfifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
static FUNC(status_t, ADC_CODE)  EQADC_DeinitCfifo(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) GTM_to_EQADC_Connections(CONST(uint8, ADC_CONST) u8Adc_GtmInstance, CONST(uint8, ADC_CONST) u8Adc_trigregidx, CONST(uint8, ADC_CONST) u8Adc_TrigRegMemberIdx, CONST(uint8, ADC_CONST) u8Adc_GTM_ADC_TRIG_OUTSEL);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */

/*******************************************************************************
 * @brief EQADC instance base address pointer array
 *******************************************************************************/
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONSTP2VAR(EQADC_TagType, ADC_CONST, ADC_APPL_CONST) Adc_EqadcBase[ADC_EQADC_MAX_INSTANCE] = EQADC_BASE_PTR_ARRAY;
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC ADC Alternate Gain Registers Address Array
 *******************************************************************************/
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) AGRxAddr[2U] = 
{
    EQADC_ADC_REG_AGR1,
    EQADC_ADC_REG_AGR2
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

/*******************************************************************************
 * @brief EQADC ADC Alternate Offset Registers Address Array
 *******************************************************************************/
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) AORxAddr[2U] =
{
    EQADC_ADC_REG_AOR1,
    EQADC_ADC_REG_AOR2
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC ADC Calibration Registers Address Array
 *
 * @note  Standard Configuration or alternate configurations 3 to 8:
 *                                    EQADC_CAL_STANDARD_CONFIG
 *        Alternate configurations 1: EQADC_CAL_ALT_CONFIG_1
 *        Alternate configurations 2: EQADC_CAL_ALT_CONFIG_2
 *******************************************************************************/
#define CAL_STD_CFG_IDX         (0U)
#define CAL_ALT1_CFG_IDX        (1U)
#define CAL_ALT2_CFG_IDX        (2U)
#define ADDR_SEL_CAL_GAIN       (0U)
#define ADDR_SEL_CAL_OFFSET     (1U)

/*******************************************************************************
 * @brief EQADC FIFO DMA Channel status
 *******************************************************************************/
#if defined(RESOURCE_SUPPORT_EQADC_FIFO_CNT)
#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_6)
#define ADC_START_SEC_VAR_INIT
#include "Adc_MemMap.h"
static VAR(uint8, AUTOMATIC) DmaMappedChanForCmd[ADC_EQADC_MAX_INSTANCE][EQADC_CFIFO_COUNT] =
{
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    }
};
#define ADC_STOP_SEC_VAR_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_INIT
#include "Adc_MemMap.h"
static VAR(uint8, AUTOMATIC) DmaMappedChanForResult[ADC_EQADC_MAX_INSTANCE][EQADC_RFIFO_COUNT] =
{
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    }
};
#define ADC_STOP_SEC_VAR_INIT
#include "Adc_MemMap.h"

#elif (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#define ADC_START_SEC_VAR_INIT
#include "Adc_MemMap.h"
static VAR(uint8, AUTOMATIC) DmaMappedChanForCmd[ADC_EQADC_MAX_INSTANCE][EQADC_CFIFO_COUNT] =
{
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    }
};
#define ADC_STOP_SEC_VAR_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_INIT
#include "Adc_MemMap.h"
static VAR(uint8, AUTOMATIC) DmaMappedChanForResult[ADC_EQADC_MAX_INSTANCE][EQADC_RFIFO_COUNT] =
{
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    }
};
#define ADC_STOP_SEC_VAR_INIT
#include "Adc_MemMap.h"

#else
    #error "EQADC FIFO COUNT error!"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_6 */
#else
    #error "EQADC FIFO COUNT is not defined!"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(uint8, ADC_CODE) EQADC_GetAltConfigIdx(VAR(Eqadc_AltConfigSelType, AUTOMATIC) eAdc_AltConfigSel)
{
    VAR(uint8, AUTOMATIC) u8Adc_AcrIdx = 0U;

    if (eAdc_AltConfigSel != EQADC_ALT_CONFIG_DISABLE)
    {
        u8Adc_AcrIdx = (uint8)((uint8)(eAdc_AltConfigSel) - (uint8)(EQADC_ALT_CONFIG_SEL_1));
        EQADC_DET_ERR(u8Adc_AcrIdx < EQADC_ALT_CONFIG_NUM); /* PRQA S 4404 */
    }

    return u8Adc_AcrIdx;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(Eqadc_AltConfigSelType, ADC_CODE) EQADC_GetAltConfigSel(VAR(uint8, AUTOMATIC) u8Adc_AcrIdx)
{
    CONST(uint8, ADC_CONST) u8Adc_AltConfigSel = (uint8)((uint8)EQADC_ALT_CONFIG_SEL_1 + u8Adc_AcrIdx);

    return (Eqadc_AltConfigSelType)u8Adc_AltConfigSel;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(Eqadc_OnChipAdcRegAddrType, ADC_CODE) EQADC_GetAltConfigRegAddr(VAR(Eqadc_AltConfigSelType, AUTOMATIC) eAdc_AltConfigSel)
{
    /* EQADC ADC Alternate Configuration Control Registers Address Array */
    static CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) eAdc_ACRxAddr[EQADC_ALT_CONFIG_NUM] =
    {
        EQADC_ADC_REG_ACR1,
        EQADC_ADC_REG_ACR2,
        EQADC_ADC_REG_ACR3,
        EQADC_ADC_REG_ACR4,
        EQADC_ADC_REG_ACR5,
        EQADC_ADC_REG_ACR6,
        EQADC_ADC_REG_ACR7,
        EQADC_ADC_REG_ACR8
    };
    CONST(uint8, ADC_CONST) u8Adc_AcrIdx = EQADC_GetAltConfigIdx(eAdc_AltConfigSel);

    return eAdc_ACRxAddr[u8Adc_AcrIdx];/* polyspace RTE:OBAI */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_CFCRx_SetCfifoxEntryExtEnDis(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, CONST(boolean, ADC_CONST) bAdc_EnDis)
{
    if (FALSE == bAdc_EnDis)
    {
        *((EQADC_CFCR[u8Adc_Instance][0U]) + ((uint32)(u8Adc_CfifoIdx) << 1U)) &= ~EQADC_CFCR0_CFEEE0_MASK;/* polyspace RTE:NIV,IDP */
    }
    else
    {
        *((EQADC_CFCR[u8Adc_Instance][0U]) + ((uint32)(u8Adc_CfifoIdx) << 1U)) |= EQADC_CFCR0_CFEEE0_MASK;/* polyspace RTE:NIV,IDP */
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_CFCR_CfifoStreamModeEnDis(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, CONST(boolean, ADC_CONST) bAdc_EnDis)
{
    if (0U == bAdc_EnDis)
    {
        /* CFIFO0 Entry Number Extension Disable */
        *((EQADC_CFCR[u8Adc_Instance][0U]) + ((uint32)(u8Adc_CfifoIdx) << 1U)) &= ~EQADC_CFCR0_STRME0_MASK;/* polyspace RTE:NIV,IDP */
    }
    else
    {
        /* CFIFO0 Entry Number Extension Enable */
        *((EQADC_CFCR[u8Adc_Instance][0U]) + ((uint32)(u8Adc_CfifoIdx) << 1U)) |= EQADC_CFCR0_STRME0_MASK;/* polyspace RTE:NIV,IDP */
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_CFCRx_SetAMode0(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, CONST(uint32, ADC_CONST) u32Adc_Cfifo0AdvanceMode0)
{
    *((EQADC_CFCR[u8Adc_Instance][0U]) + ((uint32)(u8Adc_CfifoIdx) << 1U)) &= ~EQADC_CFCR0_AMODE0_MASK;/* polyspace RTE:NIV,IDP */
    *((EQADC_CFCR[u8Adc_Instance][0U]) + ((uint32)(u8Adc_CfifoIdx) << 1U)) |= EQADC_CFCR0_AMODE0(u32Adc_Cfifo0AdvanceMode0); /* PRQA S 0488 */  /* polyspace RTE:NIV */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc_SetResultDmaConfig(CONST(EqadcInstanceType, ADC_CONST) eAdc_EqadcInst, P2CONST(Eqadc_ResultDmaConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_ResultDmaConfig)
{
    EQADC_SetDmaForResult((uint8)eAdc_EqadcInst, pAdc_ResultDmaConfig);
    EQADC_IDCRx_FifoIntDmaEnDis((uint8)eAdc_EqadcInst, (uint8)(pAdc_ResultDmaConfig->RfifoIdx), EQADC_IRQDMA_REQ_SEL_RFIFODRAIN, TRUE);
    EQADC_LLD_DmaEnDis(eAdc_EqadcInst, (pAdc_ResultDmaConfig->RfifoIdx), EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN, TRUE);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc_SetAlternateConfig(CONST(EqadcInstanceType, ADC_CONST) eAdc_EqadcInst, VAR(EqadcFifoIdxType, ADC_VAR) eAdc_Cfifo_x, P2CONST(Eqadc_AlternateConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_AlternateConfig)
{
    EQADC_SetAltConfig((uint8)eAdc_EqadcInst, pAdc_AlternateConfig, (uint8)(eAdc_Cfifo_x));
    EQADC_LLD_ClearFifoIntFlag(eAdc_EqadcInst, eAdc_Cfifo_x, EQADC_FIFO_FLAG_END_OF_QUEUE);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc_DeinitAlternateConfig(CONST(EqadcInstanceType, ADC_CONST) eAdc_EqadcInst, VAR(EqadcFifoIdxType, ADC_VAR) eAdc_Cfifo_x)
{
    uint8 u8Adc_Index =0U;
    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_ALT_CONFIG_NUM; u8Adc_Index++)
    {
        EQADC_DeinitAltConfig((uint8)eAdc_EqadcInst, EQADC_GetAltConfigSel(u8Adc_Index), (uint8)eAdc_Cfifo_x);
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_Eqadc_LLD_Init(CONST(EqadcInstanceType, ADC_CONST) eAdc_EqadcInst, CONSTP2CONST(Adc_EqadcConfigType, ADC_CONST, ADC_APPL_CONST) sAdc_ConfigPtr)
{
    EQADC_DET_ERR(sAdc_ConfigPtr != NULL); /* PRQA S 4404 */
    EQADC_DET_ERR(sAdc_ConfigPtr->EqadcHwInst != NULL); /* PRQA S 4404 */

    EQADC_DET_ERR((uint8)eAdc_EqadcInst < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    VAR(uint8, AUTOMATIC) u8Adc_Index;
#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
    VAR(status_t, AUTOMATIC) eAdc_status;
#endif  /* ADC_DEM_REPORT_ERROR_ENABLE */

    EQADC_MCR_SetDebugEnDis((uint8)eAdc_EqadcInst, sAdc_ConfigPtr->EqadcHwInst->DebugModeEn); /* polyspace RTE:IDP */
    EQADC_ETDFR_SetDFL((uint8)eAdc_EqadcInst, sAdc_ConfigPtr->EqadcHwInst->ExtTrigDigitalFilterLen);

#ifdef RESOURCE_SUPPORT_EQADC_RFIFO_CLK_SWITCH
    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_RFIFO_COUNT; u8Adc_Index++)
    {
        #if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
        eAdc_status = EQADC_LLD_RfifoClkSwitch(eAdc_EqadcInst, (EqadcFifoIdxType)u8Adc_Index, sAdc_ConfigPtr->EqadcHwInst->ClkSwitchRfifo[u8Adc_Index]);
        if(eAdc_status != STATUS_SUCCESS)
        {
            Adc_DemReportErrorStatus(DME_EVENTID_INIT, DEM_EVENT_TIMEOUT);
        }
        #else
        (void) EQADC_LLD_RfifoClkSwitch(eAdc_EqadcInst, (EqadcFifoIdxType)u8Adc_Index, sAdc_ConfigPtr->EqadcHwInst->ClkSwitchRfifo[u8Adc_Index]);
        #endif  /* ADC_DEM_REPORT_ERROR_ENABLE */

#ifdef RESOURCE_SUPPORT_EQADC_RFIFO_SOFT_RESET
        #if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
        eAdc_status = EQADC_LLD_RfifoSoftwareReset(eAdc_EqadcInst, (EqadcFifoIdxType)u8Adc_Index);
        if(eAdc_status != STATUS_SUCCESS)
        {
            Adc_DemReportErrorStatus(DME_EVENTID_INIT, DEM_EVENT_TIMEOUT);
        }
        #else
        (void) EQADC_LLD_RfifoSoftwareReset(eAdc_EqadcInst, (EqadcFifoIdxType)u8Adc_Index);
        #endif  /* ADC_DEM_REPORT_ERROR_ENABLE */
#endif  /* RESOURCE_SUPPORT_EQADC_RFIFO_SOFT_RESET */
    }
#endif  /* RESOURCE_SUPPORT_EQADC_RFIFO_CLK_SWITCH */

    VAR(Eqadc_CfifoConfigType, AUTOMATIC) sAdc_CfifoIdxInitCfgCmd;
    EQADC_GetDefaultCfifoCfg(&sAdc_CfifoIdxInitCfgCmd);
    sAdc_CfifoIdxInitCfgCmd.CfifoIdx     = EQADC_CFG_CMD_CFIFO_IDX;
    sAdc_CfifoIdxInitCfgCmd.CfifoMode    = EQADC_CFIFO_MODE_SINGLE_SW_TRIG;

    #if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
    eAdc_status = EQADC_SetCfifoConfig((uint8)eAdc_EqadcInst, &sAdc_CfifoIdxInitCfgCmd); /* PRQA S 2976 */
    if(eAdc_status != STATUS_SUCCESS)
    {
        Adc_DemReportErrorStatus(DME_EVENTID_INIT, DEM_EVENT_TIMEOUT);
    }
    #else
    (void) EQADC_SetCfifoConfig((uint8)eAdc_EqadcInst, &sAdc_CfifoIdxInitCfgCmd); /* PRQA S 2976 */
    #endif  /* ADC_DEM_REPORT_ERROR_ENABLE */

    /* Init ADC_TSCR */
    EQADC_WriteConfigCmdSSE((uint8)eAdc_EqadcInst, \
                            (uint8)sAdc_CfifoIdxInitCfgCmd.CfifoIdx, \
                            (uint8)EQADC_ADC_0, \
                            EQADC_ADC_REG_TSCR, \
                            EQADC_ADC_TSCR_TBC_CLK_PS(sAdc_ConfigPtr->EqadcHwInst->TimeBasePresDiv)); /* PRQA S 2985 */

    EQADC_DET_ERR(((sAdc_ConfigPtr->AdcConfigNum > 0U) && \
                   (sAdc_ConfigPtr->AdcConfigNum <= EQADC_ADC_NUM)) && /* PRQA S 4404 */ \
                  (sAdc_ConfigPtr->AdcConfigArray != (void *)NULL));
#if EQADC_DET_SUPPORT
    VAR(uint8, AUTOMATIC) u8Adc_AdcIdx[EQADC_ADC_NUM] = {0U};
    VAR(uint8, AUTOMATIC) u8Adc_AdcExtMuxEnNum = 0u;
    for (u8Adc_Index = 0U; u8Adc_Index < sAdc_ConfigPtr->AdcConfigNum; u8Adc_Index++)
    {
        u8Adc_AdcIdx[u8Adc_Index] = (uint8)(sAdc_ConfigPtr->AdcConfigArray[u8Adc_Index].AdcIdx);
        u8Adc_AdcExtMuxEnNum = (uint8)(u8Adc_AdcExtMuxEnNum + ((sAdc_ConfigPtr->AdcConfigArray[u8Adc_Index].AdcExtMuxEn == TRUE) ? 1U : 0U));
    }
    if (sAdc_ConfigPtr->AdcConfigNum == EQADC_ADC_NUM)
    {
        EQADC_DET_ERR(u8Adc_AdcIdx[0U] != u8Adc_AdcIdx[1U]); /* PRQA S 4404 */
        (void)u8Adc_AdcIdx[u8Adc_Index];
    }
#ifndef RESOURCE_SUPPORT_EQADC_CFG_OPEN_2_EMUX
    /* Note: Both ADC0/1_EMUX bits must not be asserted at the same time. */
    EQADC_DET_ERR(u8Adc_AdcExtMuxEnNum <= 1U); /* PRQA S 4404 */
#endif  /* RESOURCE_SUPPORT_EQADC_CFG_OPEN_2_EMUX */
#endif  /* EQADC_DET_SUPPORT */

    for (u8Adc_Index = 0U; u8Adc_Index < sAdc_ConfigPtr->AdcConfigNum; u8Adc_Index++)
    {
        EQADC_SetAdcConfig((uint8)eAdc_EqadcInst, &(sAdc_ConfigPtr->AdcConfigArray[u8Adc_Index]), (uint8)(sAdc_CfifoIdxInitCfgCmd.CfifoIdx));
    }

#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
    if (sAdc_ConfigPtr->RedLineClientConfigNum > 0U)
    {
        EQADC_DET_ERR(sAdc_ConfigPtr->RedLineClientConfigNum <= EQADC_RED_LINE_CLIENT_NUM); /* PRQA S 4404 */
        EQADC_DET_ERR(sAdc_ConfigPtr->RedLineClientConfigArray != NULL); /* PRQA S 4404 */
        for (u8Adc_Index = 0U; u8Adc_Index < sAdc_ConfigPtr->RedLineClientConfigNum; u8Adc_Index++)
        {
            EQADC_SetRedLineClientConfig((uint8)eAdc_EqadcInst, &(sAdc_ConfigPtr->RedLineClientConfigArray[u8Adc_Index]));
        }
    }
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */

    VAR(uint32, AUTOMATIC) u32FifoFlagMask;
    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_CFIFO_COUNT; u8Adc_Index++)
    {
        u32FifoFlagMask = EQADC_FIFO_FLAG_ALL & ~EQADC_FIFO_FLAG_CFIFO_FILL;

        if ((EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_EqadcInst, u8Adc_Index) & EQADC_IRQDMA_REQ_SEL_CFIFOFILL) != 0U)
        {
            u32FifoFlagMask &= ~EQADC_FIFO_FLAG_CFIFO_FILL; /* PRQA S 2984 */
        }

        if ((EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_EqadcInst, u8Adc_Index) & EQADC_IRQDMA_REQ_SEL_RFIFODRAIN) != 0U)
        {
            u32FifoFlagMask &= ~EQADC_FIFO_FLAG_RFIFO_DRAIN; /* PRQA S 2984 */
        }

        EQADC_LLD_ClearFifoIntFlag(eAdc_EqadcInst, (EqadcFifoIdxType)u8Adc_Index, u32FifoFlagMask);
    }

    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_CFIFO_COUNT; u8Adc_Index++)
    {
        EQADC_CFTCRx_SetCfifoTransCount((uint8)eAdc_EqadcInst, u8Adc_Index, 0U);
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_Eqadc_LLD_DeInit(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
    VAR(status_t, AUTOMATIC) eAdc_status;
#endif  /* ADC_DEM_REPORT_ERROR_ENABLE */
    VAR(uint8, AUTOMATIC) u8Adc_Index;
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfgCmdCfifoIdx = EQADC_FIFO_0;

#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
    eAdc_status = EQADC_DeinitCfifo((uint8)eAdc_Instance, (uint8)eAdc_CfgCmdCfifoIdx);
    if(eAdc_status != STATUS_SUCCESS)
    {
        Adc_DemReportErrorStatus(DEM_EVENTID_DEINIT, DEM_EVENT_TIMEOUT);
    }
#else
    (void) EQADC_DeinitCfifo((uint8)eAdc_Instance, (uint8)eAdc_CfgCmdCfifoIdx);
#endif  /* ADC_DEM_REPORT_ERROR_ENABLE */

    VAR(Eqadc_CfifoConfigType, AUTOMATIC) sAdc_CfifoIdxInitCfgCmd;
    EQADC_GetDefaultCfifoCfg(&sAdc_CfifoIdxInitCfgCmd);
    sAdc_CfifoIdxInitCfgCmd.CfifoIdx     = eAdc_CfgCmdCfifoIdx;
    sAdc_CfifoIdxInitCfgCmd.CfifoMode    = EQADC_CFIFO_MODE_SINGLE_SW_TRIG;
#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
    eAdc_status = EQADC_SetCfifoConfig((uint8)eAdc_Instance, &sAdc_CfifoIdxInitCfgCmd); /* PRQA S 2976 */
    if(eAdc_status != STATUS_SUCCESS)
    {
        Adc_DemReportErrorStatus(DEM_EVENTID_DEINIT, DEM_EVENT_TIMEOUT);
    }
#else
    (void) EQADC_SetCfifoConfig((uint8)eAdc_Instance, &sAdc_CfifoIdxInitCfgCmd); /* PRQA S 2976 */
#endif  /* ADC_DEM_REPORT_ERROR_ENABLE */

    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_ADC_NUM; u8Adc_Index++)
    {
        EQADC_DeinitAdcCtrl((uint8)eAdc_Instance, u8Adc_Index, (uint8)eAdc_CfgCmdCfifoIdx);
    }

    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_RFIFO_COUNT; u8Adc_Index++)
    {
        /* Stop eDMA channel */
        if (DmaMappedChanForResult[((uint8)eAdc_Instance)][u8Adc_Index] != EQADC_DMA_MAPPED_CHAN_INVALID)
        {
            (void) EDMA_ClearChannelRequest(DmaMappedChanForResult[((uint8)eAdc_Instance)][u8Adc_Index]);
            DmaMappedChanForResult[((uint8)eAdc_Instance)][u8Adc_Index] = EQADC_DMA_MAPPED_CHAN_INVALID;
        }

        /* reset EQADC RFIFO interrupts and DMA select */
        EQADC_IDCRx_FifoIntDmaEnDis((uint8)eAdc_Instance, u8Adc_Index, (uint16)EQADC_IRQDMA_REQ_SEL_RFIFODRAIN, FALSE);
        /* reset EQADC RFIFO interrupts and DMA enable */
        EQADC_IDCRx_FifoIntDmaEnDis((uint8)eAdc_Instance, u8Adc_Index, (uint16)(EQADC_IRQ_EN_RFIFO_OVERFLOW|EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN), FALSE);

#ifdef RESOURCE_SUPPORT_EQADC_FIFO_DMA_CTRL_SEL
        EQADC_LLD_RfifoDmaControllerSelect(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Index, EQADC_FIFO_SEL_DMA_0);
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_DMA_CTRL_SEL */

#ifdef RESOURCE_SUPPORT_EQADC_RFIFO_CLK_SWITCH
        #if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
        eAdc_status = EQADC_LLD_RfifoClkSwitch(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Index, EQADC_RFIFO_CLK_SWITCH_IPS);
        if (eAdc_status != STATUS_SUCCESS)
        {
            Adc_DemReportErrorStatus(DEM_EVENTID_DEINIT, DEM_EVENT_TIMEOUT);
        }
        #else
        (void) EQADC_LLD_RfifoClkSwitch(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Index, EQADC_RFIFO_CLK_SWITCH_IPS);
        #endif  /* ADC_DEM_REPORT_ERROR_ENABLE */
#endif  /* RESOURCE_SUPPORT_EQADC_RFIFO_CLK_SWITCH */

#ifdef RESOURCE_SUPPORT_EQADC_RFIFO_SOFT_RESET
        #if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
        eAdc_status = EQADC_LLD_RfifoSoftwareReset(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Index);
        if (eAdc_status != STATUS_SUCCESS)
        {
            Adc_DemReportErrorStatus(DEM_EVENTID_DEINIT, DEM_EVENT_TIMEOUT);
        }
        #else
        (void) EQADC_LLD_RfifoSoftwareReset(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Index);
        #endif  /* ADC_DEM_REPORT_ERROR_ENABLE */
#else
        /* Clear data for all RFIFO entries */
        #if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
        eAdc_status = EQADC_LLD_ClearRfifoAllData(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Index);
        if (eAdc_status != STATUS_SUCCESS)
        {
            Adc_DemReportErrorStatus(DEM_EVENTID_DEINIT, DEM_EVENT_TIMEOUT);
        }
        #else
        (void) EQADC_LLD_ClearRfifoAllData(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Index);
        #endif  /* ADC_DEM_REPORT_ERROR_ENABLE */
#endif  /* RESOURCE_SUPPORT_EQADC_RFIFO_SOFT_RESET */
    }

    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_ALT_CONFIG_NUM; u8Adc_Index++)
    {
        EQADC_DeinitAltConfig((uint8)eAdc_Instance, EQADC_GetAltConfigSel(u8Adc_Index), (uint8)eAdc_CfgCmdCfifoIdx);
    }

#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_RED_LINE_CLIENT_NUM; u8Adc_Index++)
    {
        EQADC_DeinitRedLineClient((uint8)eAdc_Instance, u8Adc_Index);
    }
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */

    EQADC_DeinitAdcTimeConfig((uint8)eAdc_Instance, (uint8)eAdc_CfgCmdCfifoIdx);

    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_CFIFO_COUNT; u8Adc_Index++)
    {
#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
        eAdc_status = EQADC_DeinitCfifo((uint8)eAdc_Instance, u8Adc_Index);
        if (eAdc_status != STATUS_SUCCESS)
        {
            Adc_DemReportErrorStatus(DEM_EVENTID_DEINIT, DEM_EVENT_TIMEOUT);
        }
#else
        (void) EQADC_DeinitCfifo((uint8)eAdc_Instance, u8Adc_Index);
#endif  /* ADC_DEM_REPORT_ERROR_ENABLE */
    }

    CONST(uint32, ADC_CONST) u32Adc_FifoFlag = (EQADC_FIFO_FLAG_ALL) & (~EQADC_FIFO_FLAG_CFIFO_FILL);
    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_CFIFO_COUNT; u8Adc_Index++)
    {
        EQADC_LLD_ClearFifoIntFlag(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Index, u32Adc_FifoFlag);
    }

    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_CFIFO_COUNT; u8Adc_Index++)
    {
        EQADC_CFTCRx_SetCfifoTransCount((uint8)eAdc_Instance, u8Adc_Index, 0U);
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_EQADC_CALIBRATION
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
static  FUNC(uint64, ADC_CODE)  EQADC_GetGcc(VAR(uint16, AUTOMATIC) u16Adc_RAW_RES_75P_Vref, VAR(uint16, AUTOMATIC) u16Adc_RAW_RES_25P_Vref)
{
    /* GCC: (CAL_RES75%VREF - CAL_RES25%VREF) / (RAW_RES75%VREF - RAW_RES25%VREF); */
    CONST(uint64, ADC_CONST) u64Adc_ExpectedDiffNum_Div14 = (uint64)(EQADC_PCT75_VREF_CAL_RES - EQADC_PCT25_VREF_CAL_RES) << EQADC_ADC_GCC_FRAC_WIDTH;
    CONST(uint64, ADC_CONST) u64Adc_MeasuredDiffNum_Div14 = ((uint64)u16Adc_RAW_RES_75P_Vref - (uint64)u16Adc_RAW_RES_25P_Vref) << EQADC_ADC_GCC_FRAC_WIDTH;
    CONST(uint64, ADC_CONST) u64Adc_ExpectedDiffNum_Div28 = u64Adc_ExpectedDiffNum_Div14 << EQADC_ADC_GCC_FRAC_WIDTH; /* PRQA S 2984,2921 */
    if(u64Adc_MeasuredDiffNum_Div14 != 0U)
    {
        CONST(uint64, ADC_CONST) u64Adc_Gcc = (u64Adc_ExpectedDiffNum_Div28 + ((uint64)u64Adc_MeasuredDiffNum_Div14 >> 1U)) / u64Adc_MeasuredDiffNum_Div14; /* PRQA S 2834 */
        return u64Adc_Gcc;
    }
    else
    {
        return 0U;
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (EQADC_ADC_OCC_FORM == EQADC_ADC_OCC_FORM1)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
static FUNC(sint16, ADC_CODE) EQADC_GetOcc(VAR(uint64, AUTOMATIC) u64Adc_GainConvCount, VAR(uint16, AUTOMATIC) u16Adc_RAW_RES_75P_Vref)
{
    /* OCC: CAL_RES75%VREF - GCC * RAW_RES75%VREF - 2; */
    CONST(uint64, ADC_CONST) u64Adc_ExpectedValue_Div14 = (uint64)(EQADC_PCT75_VREF_CAL_RES - 2U) << EQADC_ADC_GCC_FRAC_WIDTH;
    CONST(sint64, ADC_CONST) s64Adc_sign64Occ_Div14 = (sint64)(u64Adc_ExpectedValue_Div14 - (u64Adc_GainConvCount * ((uint64)u16Adc_RAW_RES_75P_Vref))); /* PRQA S 4446, 4394 */
    CONST(sint16, ADC_CONST) s16Adc_sign16_Occ = (sint16)(s64Adc_sign64Occ_Div14 >> EQADC_ADC_GCC_FRAC_WIDTH); /* PRQA S 4533 */ /* polyspace RTE:OVFL */

    return s16Adc_sign16_Occ;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#else
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
static FUNC(sint16, ADC_CODE) EQADC_GetOcc(VAR(uint64, AUTOMATIC) u64Adc_GainConvCount, VAR(uint16, AUTOMATIC) u16Adc_RAW_RES_25P_Vref)
{
    /* OCC: CAL_RES25%VREF - GCC * RAW_RES25%VREF - 2; */
    CONST(uint64, ADC_CONST) u64Adc_ExpectedValue_Div14 = (EQADC_PCT25_VREF_CAL_RES - 2U) << EQADC_ADC_GCC_FRAC_WIDTH;
    CONST(sint64, ADC_CONST) s64Adc_sign64Occ_Div14 = u64Adc_ExpectedValue_Div14 - (u64Adc_GainConvCount * ((uint64)u16Adc_RAW_RES_75P_Vref)); /* PRQA S 4446 */
    CONST(sint16, ADC_CONST) s16Adc_sign16_Occ = (sint16)(s64Adc_sign64Occ_Div14 >> EQADC_ADC_GCC_FRAC_WIDTH); /* PRQA S 4533 */

    return s16Adc_sign16_Occ;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* EQADC_ADC_OCC_FORM */
#endif  /* RESOURCE_SUPPORT_EQADC_CALIBRATION */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_InternalFuncEn(void)
{
    /* EQADC VREF/Temperature channels enable.
     *  SSCM module offsets the 0x38 register bit2: VREF enable,
     *  SSCM module offsets the 0x38 register bit3: Temperature enable */
#ifdef RESOURCE_SUPPORT_EQADC_VREF_SW
    #if (RESOURCE_SUPPORT_EQADC_VREF_SW == RESOURCE_SUPPORT_EQADC_VREF_SW_CTRL_1)
    /* The enable bit of SDADC needs to be turned on (The VREF switch is internally connected to the SDADC_EN),
     * and SSCM module offsets the 0x38 register, bit2/3    */
    /** 1.The enable bit of SDADC needs to be turned on,
     **     Refer to the Mcu_LLD_InternalVrefEn function **/

    /** 2.SSCM module offsets the 0x38 register, bit2/3 **/
    SSCM.CHIP_CR.R |= (uint32)(SSCM_CHIP_CR_EN_VREF_MASK | SSCM_CHIP_CR_EN_TS_MASK);

    #elif (RESOURCE_SUPPORT_EQADC_VREF_SW == RESOURCE_SUPPORT_EQADC_VREF_SW_CTRL_2)
    /* SSCM module offsets the 0x38 register, bit2/3/4
     * (The switch of SDADC_EN has been modified to bit 4 to achieve the function)  */
    SSCM.CHIP_CR.R |= (uint32)(SSCM_CHIP_CR_EN_VREF_MASK | SSCM_CHIP_CR_EN_TS_MASK | SSCM_CHIP_CR_EN_SDADC_BIAS_MASK);

    #elif (RESOURCE_SUPPORT_EQADC_VREF_SW == RESOURCE_SUPPORT_EQADC_VREF_SW_CTRL_3)
    /* SSCM module offsets the 0x38 register, bit2/3
     * (The functions of bit2 and bit4 have been combined into bit2) */
    SSCM.CHIP_CR.R |= (uint32)(SSCM_CHIP_CR_EN_VREF_MASK | SSCM_CHIP_CR_EN_TS_MASK);

    #else
        #error "RESOURCE_SUPPORT_EQADC_VREF_SW error!"
    #endif /* RESOURCE_SUPPORT_EQADC_VREF_SW == RESOURCE_SUPPORT_EQADC_VREF_SW_CTRL_X */

#else
    #error "RESOURCE_SUPPORT_EQADC_VREF_SW no defined!"
#endif /* RESOURCE_SUPPORT_EQADC_VREF_SW */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_EQADC_CALIBRATION
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(status_t, ADC_CODE) EQADC_LLD_CalibConvResult(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcAdcIdxType, ADC_CONST) eAdc_AdcIdx, CONSTP2VAR(Eqadc_CalibConfigInfoType, ADC_CONST, ADC_APPL_CONST) pAdc_CalCfgPtr)/* PRQA S 2755 */
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_AdcIdx < EQADC_ADC_NUM); /* PRQA S 4404 */
    EQADC_DET_ERR(pAdc_CalCfgPtr != NULL); /* PRQA S 4404 */

    VAR(status_t, AUTOMATIC) eAdc_CalStatus = STATUS_SUCCESS;
    CONST(uint8, ADC_CONST) u8Adc_Cfifo_x = (uint8)(pAdc_CalCfgPtr->CfifoIdx);
    CONST(uint8, ADC_CONST) u8Adc_Rfifo_x = (uint8)(pAdc_CalCfgPtr->RfifoIdx);
    VAR(uint32, AUTOMATIC) u32Adc_TimeoutCal, u32Adc_FifoStatusTimeout;
    VAR(uint16, AUTOMATIC) u16Adc_RawResultPct25Vref, u16Adc_RawResultPct75Vref;    /* RAW_RES: measured result values */
    VAR(uint8, AUTOMATIC) u8Adc_CalibCfgSelIdx = 0U;

    EQADC_DET_ERR(u8Adc_Cfifo_x < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR(u8Adc_Rfifo_x < EQADC_RFIFO_COUNT); /* PRQA S 4404 */

    static CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) CalibAddr[3U][2U] =
    {
        {EQADC_ADC_REG_GCCR, EQADC_ADC_REG_OCCR},
        {EQADC_ADC_REG_AGR1, EQADC_ADC_REG_AOR1},
        {EQADC_ADC_REG_AGR2, EQADC_ADC_REG_AOR2}
    };

    switch (pAdc_CalCfgPtr->CalibCfgSel)
    {
        case EQADC_CAL_STANDARD_CONFIG:
        {
            u8Adc_CalibCfgSelIdx = CAL_STD_CFG_IDX;
            break;
        }
        case EQADC_CAL_ALT_CONFIG_1:
        {
            u8Adc_CalibCfgSelIdx = CAL_ALT1_CFG_IDX;
            break;
        }
        case EQADC_CAL_ALT_CONFIG_2:
        {
            u8Adc_CalibCfgSelIdx = CAL_ALT2_CFG_IDX;
            break;
        }
        default:
        {
            EQADC_DET_ERR(FALSE);
            break;
        }
    }
    /* Save Current status */
    /** Save Current RFIFO Drain request control **/
    CONST(uint16, ADC_CONST) u16Adc_IntDmaCtrl_RfifoDrain = EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_Instance, u8Adc_Rfifo_x);

    if ((u16Adc_IntDmaCtrl_RfifoDrain & EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN) != 0U)
    {
        EQADC_IDCRx_FifoIntDmaEnDis((uint8)eAdc_Instance, u8Adc_Rfifo_x, EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN, FALSE);
    }

    if ((u16Adc_IntDmaCtrl_RfifoDrain & EQADC_IRQDMA_REQ_SEL_RFIFODRAIN) != (uint16)EQADC_FILL_SEL_INT)
    {
        /* Stop eDMA mapped channel */
        if (DmaMappedChanForResult[((uint8)eAdc_Instance)][u8Adc_Rfifo_x] != EQADC_DMA_MAPPED_CHAN_INVALID)
        {
            (void) EDMA_ClearChannelRequest(DmaMappedChanForResult[((uint8)eAdc_Instance)][u8Adc_Rfifo_x]);
        }

        EQADC_IDCRx_FifoIntDmaEnDis((uint8)eAdc_Instance, u8Adc_Rfifo_x, EQADC_IRQDMA_REQ_SEL_RFIFODRAIN, FALSE);
    }

    /** Save Current Mode **/
    CONST(uint32, ADC_CONST) u8Adc_CurrentCfifoMode = EQADC_CFCRxGetMode((uint8)eAdc_Instance, u8Adc_Cfifo_x);
    if (u8Adc_CurrentCfifoMode != (uint32)EQADC_CFIFO_MODE_SINGLE_SW_TRIG)
    {
        u32Adc_FifoStatusTimeout = EQADC_TIMEOUT_COUNT;
        /* set CFIFO mode disabled first */
        EQADC_CFCRxSetMode((uint8)eAdc_Instance, u8Adc_Cfifo_x, (uint32)EQADC_CFIFO_MODE_DISABLE);
        while ((EQADC_LLD_GetCFifoStatus(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Cfifo_x) \
                != EQADC_CFIFO_STATUS_IDLE)&& (u32Adc_FifoStatusTimeout > 0UL))
        {
            u32Adc_FifoStatusTimeout--;
        }
        if (0UL == u32Adc_FifoStatusTimeout)
        {
            eAdc_CalStatus =  STATUS_TIMEOUT;
        }
        /* invalidate CFIFO all entries */
        EQADC_CFCRxSetInvalidate((uint8)eAdc_Instance, u8Adc_Cfifo_x);
        /* set target CFIFO mode */
        EQADC_CFCRxSetMode((uint8)eAdc_Instance, u8Adc_Cfifo_x, (uint32)EQADC_CFIFO_MODE_SINGLE_SW_TRIG);
    }

    u32Adc_TimeoutCal = pAdc_CalCfgPtr->TimeoutCal;
    while ((EQADC_LLD_GetFifoFlagStatus(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Rfifo_x, EQADC_FISR_RFIFO_ENTRY_COUNT) != 0U) \
            && (u32Adc_TimeoutCal > 0UL))
    {
        (void) EQADC_LLD_RfifoPopData(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Rfifo_x);
        u32Adc_TimeoutCal--;
    }

    if (u32Adc_TimeoutCal > 0UL)
    {
        EQADC_LLD_ClearFifoIntFlag(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Rfifo_x, EQADC_FIFO_FLAG_RFIFO_DRAIN);

        Eqadc_ConvCmdType ConvCmd;
        EQADC_GetDefaultConvCmd(&ConvCmd);
        ConvCmd.cBufNum         = (uint8)eAdc_AdcIdx;
        ConvCmd.RfifoMsgTag     = (EqadcFifoIdxType)u8Adc_Rfifo_x;
        ConvCmd.LongSampTime    = pAdc_CalCfgPtr->LongSampTime;
        ConvCmd.ChanNum         = EQADC_CH_VDD_PCT25_VREF;
        ConvCmd.AltConfigSel    = (Eqadc_AltConfigSelType)((uint8)(pAdc_CalCfgPtr->CalibCfgSel));
        EQADC_LLD_CfifoPushConvCmd(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Cfifo_x, &ConvCmd);
        EQADC_LLD_SingleScanEn(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Cfifo_x);

        u32Adc_TimeoutCal = pAdc_CalCfgPtr->TimeoutCal;
        while ((EQADC_LLD_GetFifoFlagStatus(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Rfifo_x, EQADC_FISR_RFIFO_DRAIN) != 1U) \
                && (u32Adc_TimeoutCal > 0UL))
        {
            u32Adc_TimeoutCal--;
        }

        if (u32Adc_TimeoutCal > 0UL)
        {
            u16Adc_RawResultPct25Vref = EQADC_LLD_RfifoPopData(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Rfifo_x);
            EQADC_LLD_ClearFifoIntFlag(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Rfifo_x, EQADC_FIFO_FLAG_RFIFO_DRAIN);
            EQADC_LLD_ClearFifoIntFlag(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Cfifo_x, EQADC_FIFO_FLAG_END_OF_QUEUE);

            ConvCmd.ChanNum     = EQADC_CH_VDD_PCT75_VREF;
            EQADC_LLD_CfifoPushConvCmd(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Cfifo_x, &ConvCmd);
            EQADC_LLD_SingleScanEn(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Cfifo_x);

            u32Adc_TimeoutCal = pAdc_CalCfgPtr->TimeoutCal;
            while ((EQADC_LLD_GetFifoFlagStatus(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Rfifo_x, EQADC_FISR_RFIFO_DRAIN) != 1U) \
                    && (u32Adc_TimeoutCal > 0UL))
            {
                u32Adc_TimeoutCal--;
            }

            if (u32Adc_TimeoutCal > 0UL)
            {
                u16Adc_RawResultPct75Vref = EQADC_LLD_RfifoPopData(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Rfifo_x);
                EQADC_LLD_ClearFifoIntFlag(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Rfifo_x, EQADC_FIFO_FLAG_RFIFO_DRAIN);
                EQADC_LLD_ClearFifoIntFlag(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Cfifo_x, EQADC_FIFO_FLAG_END_OF_QUEUE);

                CONST(uint64, ADC_CONST) Gcc_Div14 = EQADC_GetGcc(u16Adc_RawResultPct75Vref, u16Adc_RawResultPct25Vref);
                VAR(uint16, AUTOMATIC) GainConvCount = (uint16) Gcc_Div14;
                if (Gcc_Div14 > EQADC_ADC_GCCR_GCC_MASK)
                {
                    GainConvCount = EQADC_ADC_GCCR_GCC_MASK;
                    eAdc_CalStatus = STATUS_ERROR;
                }

#if (EQADC_ADC_OCC_FORM == EQADC_ADC_OCC_FORM1)
                CONST(sint16, ADC_CONST) OffsetConvCount = EQADC_GetOcc(Gcc_Div14, u16Adc_RawResultPct75Vref);
#else
                CONST(sint16, ADC_CONST) OffsetConvCount = EQADC_GetOcc(Gcc_Div14, u16Adc_RawResultPct25Vref);
#endif

                pAdc_CalCfgPtr->GainCalibConst   = GainConvCount;
                pAdc_CalCfgPtr->OffsetCalibConst = OffsetConvCount;

                EQADC_WriteConfigCmdSSE((uint8)eAdc_Instance, u8Adc_Cfifo_x, (uint8)eAdc_AdcIdx, CalibAddr[u8Adc_CalibCfgSelIdx][ADDR_SEL_CAL_GAIN], GainConvCount);
                EQADC_WriteConfigCmdSSE((uint8)eAdc_Instance, u8Adc_Cfifo_x, (uint8)eAdc_AdcIdx, CalibAddr[u8Adc_CalibCfgSelIdx][ADDR_SEL_CAL_OFFSET], (uint16)OffsetConvCount);

                EQADC_LLD_ClearFifoIntFlag(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Cfifo_x, EQADC_FIFO_FLAG_END_OF_QUEUE);

                EQADC_CFTCRx_SetCfifoTransCount((uint8)eAdc_Instance, u8Adc_Cfifo_x, 0U);
            }
            else
            {
                eAdc_CalStatus = STATUS_TIMEOUT;
            }
        }
        else
        {
            eAdc_CalStatus = STATUS_TIMEOUT;
        }
    }
    else
    {
        eAdc_CalStatus = STATUS_TIMEOUT;
    }

    /* Restore previous mode */
    if (u8Adc_CurrentCfifoMode != (uint32)EQADC_CFIFO_MODE_SINGLE_SW_TRIG)
    {
        u32Adc_FifoStatusTimeout = EQADC_TIMEOUT_COUNT;
        /* set CFIFO mode disabled first */
        EQADC_CFCRxSetMode((uint8)eAdc_Instance, u8Adc_Cfifo_x, (uint32)EQADC_CFIFO_MODE_DISABLE);
        while ((EQADC_LLD_GetCFifoStatus(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Cfifo_x) != EQADC_CFIFO_STATUS_IDLE) \
            && (u32Adc_FifoStatusTimeout > 0UL))
        {
            u32Adc_FifoStatusTimeout--;
        }
        if (0UL == u32Adc_FifoStatusTimeout)
        {
            eAdc_CalStatus = STATUS_TIMEOUT;
        }

        /* set target CFIFO mode */
        EQADC_CFCRxSetMode((uint8)eAdc_Instance, u8Adc_Cfifo_x, u8Adc_CurrentCfifoMode);
    }

    if ((u16Adc_IntDmaCtrl_RfifoDrain & EQADC_IRQDMA_REQ_SEL_RFIFODRAIN) != (uint16)EQADC_FILL_SEL_INT)
    {
        /* start eDMA mapped channel */
        (void) EDMA_SetChannelRequest(DmaMappedChanForResult[((uint8)eAdc_Instance)][u8Adc_Rfifo_x]);

        EQADC_IDCRx_FifoIntDmaEnDis((uint8)eAdc_Instance, u8Adc_Rfifo_x, EQADC_IRQDMA_REQ_SEL_RFIFODRAIN, TRUE);
    }

    if ((u16Adc_IntDmaCtrl_RfifoDrain & EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN) != 0U)
    {
        EQADC_IDCRx_FifoIntDmaEnDis((uint8)eAdc_Instance, u8Adc_Rfifo_x, EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN, TRUE);
    }

    return eAdc_CalStatus;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_CALIBRATION */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
static FUNC(void, ADC_CODE) EQADC_LLD_SetImmediateConvCmdEnDis(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcAdcIdxType, ADC_CONST)  eAdc_AdcIdx, CONST(boolean, ADC_CONST) bAdc_EnDis)/* PRQA S 1505 */
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8) eAdc_AdcIdx < EQADC_ADC_NUM); /* PRQA S 4404 */

    EQADC_MCR_SetICEAxEnDis((uint8)eAdc_Instance, (uint8) eAdc_AdcIdx, bAdc_EnDis);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(uint8, ADC_CODE) EQADC_LLD_GetDebugEnDis(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    return EQADC_MCR_GetDebugEnDis((uint8)eAdc_Instance);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_SetDebugEnDis(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(boolean, ADC_CONST) bAdc_EnDis)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    EQADC_MCR_SetDebugEnDis((uint8)eAdc_Instance, bAdc_EnDis);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_EQADC_RFIFO_CLK_SWITCH
Eqadc_RFifoClkSwitchType EQADC_LLD_GetRfifoClkSwitch(const EqadcInstanceType instance, const EqadcFifoIdxType RfifoIdx)
{
    uint32 ClkSwitchEn;
    Eqadc_RFifoClkSwitchType ClkSwitch;
    uint32 AdcTimeout = EQADC_TIMEOUT_COUNT;

    if (((uint8)instance < ADC_EQADC_MAX_INSTANCE) && ((uint8)RfifoIdx < EQADC_RFIFO_COUNT))
    {
        while (((*(EQADC_MCR[instance]) & (uint32)(EQADC_MCR_CS_ST0_MASK << (2U * (uint8)RfifoIdx))) == 0U) && (AdcTimeout > 0UL))
        {
            AdcTimeout--;
        }
        if (AdcTimeout > 0UL)
        {
            ClkSwitchEn = (*(EQADC_MCR[instance]) & (uint32)(EQADC_MCR_CS_EN0_MASK << (2U * (uint8)RfifoIdx)));
            ClkSwitch = (Eqadc_RFifoClkSwitchType)(ClkSwitchEn >> (EQADC_MCR_CS_EN0_SHIFT + (2U * (uint8)RfifoIdx)));/* PRQA S 4394 */
        }
        else
        {
            ClkSwitch = EQADC_RFIFO_CLK_SWITCH_ERROR;
        }
    }
    else
    {
        ClkSwitch = EQADC_RFIFO_CLK_SWITCH_ERROR;
    }

    return ClkSwitch;
}

/*******************************************************************************
 * @brief EQADC RFIFOx Clock Switch Enable.
 *
 * @param instance: EQADC instance
 *        RfifoIdx: RFIFO number
 *        ClkSwitch: EQADC_RFIFO_CLK_SWITCH_IPS /EQADC_RFIFO_CLK_SWITCH_GTM
 *        [out] Function return status.
 *
 * @note  During Clock Switch Enable of RFIFOx,
 *          make sure that there is no write request or read request to RFIFOx.
 *******************************************************************************/
status_t EQADC_LLD_RfifoClkSwitch(const EqadcInstanceType instance, const EqadcFifoIdxType RfifoIdx, const Eqadc_RFifoClkSwitchType ClkSwitch)
{
    status_t ret = STATUS_SUCCESS;
    uint32 AdcTimeout = EQADC_TIMEOUT_COUNT;

    if (((uint8)instance < ADC_EQADC_MAX_INSTANCE) && ((uint8)RfifoIdx < EQADC_RFIFO_COUNT))
    {
        /* Clock Switch Enable for RFIFOx */
        if (EQADC_RFIFO_CLK_SWITCH_IPS == ClkSwitch)
        {
            *(EQADC_MCR[instance]) &= ~(uint32)(EQADC_MCR_CS_EN0_MASK << (2U * (uint8)RfifoIdx));
            while (((*(EQADC_MCR[instance]) & (uint32)(EQADC_MCR_CS_EN0_MASK << (2U * (uint8)RfifoIdx))) != 0U) && (AdcTimeout > 0UL))
            {
                AdcTimeout--;
            }
        }
        else if (EQADC_RFIFO_CLK_SWITCH_GTM == ClkSwitch)
        {
            *(EQADC_MCR[instance]) |= (uint32)(EQADC_MCR_CS_EN0_MASK << (2U * (uint8)RfifoIdx));
            while (((*(EQADC_MCR[instance]) & (uint32)(EQADC_MCR_CS_EN0_MASK << (2U * (uint8)RfifoIdx))) == 0U) && (AdcTimeout > 0UL))
            {
                AdcTimeout--;
            }
        }
        else
        {
            ret = STATUS_ERROR;
        }

        if (0UL == AdcTimeout)
        {
            ret = STATUS_TIMEOUT;
        }

        if (STATUS_SUCCESS == ret)
        {   /* Clock Switch Status for RFIFOx */
            AdcTimeout = EQADC_TIMEOUT_COUNT;
            while (((*(EQADC_MCR[instance]) & (uint32)(EQADC_MCR_CS_ST0_MASK << (2U * (uint8)RfifoIdx))) == 0U) && (AdcTimeout > 0UL))
            {
                AdcTimeout--;
            }
            if (0UL == AdcTimeout)
            {
                ret = STATUS_TIMEOUT;
            }
        }
    }
    else
    {
        ret = STATUS_ERROR;
    }

    return ret;
}
#endif  /* RESOURCE_SUPPORT_EQADC_RFIFO_CLK_SWITCH */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(uint8, ADC_CODE) EQADC_LLD_GetExtTrigDigitalFilterLength(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    return EQADC_ETDFR_GetDFL((uint8)eAdc_Instance);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_SetExtTrigDigitalFilterLength(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(uint8, ADC_CONST) u8Adc_DigitalFilterLen)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR(u8Adc_DigitalFilterLen <= EQADC_ETDFR_DFL_MASK); /* PRQA S 4404 */

    EQADC_ETDFR_SetDFL((uint8)eAdc_Instance, u8Adc_DigitalFilterLen);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

/* Write/Read Configuration Command Format for On-Chip ADC Operation */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
static FUNC(void, ADC_CODE) EQADC_LLD_CfifoPushConfigCmd(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, CONSTP2CONST(Eqadc_ConfigCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConfigCmdPtr)/* PRQA S 1505 */
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR(pAdc_ConfigCmdPtr != NULL); /* PRQA S 4404 */
    
    if(((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE) && ((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT))
    {
        *(EQADC_CFPR[(uint8)eAdc_Instance][(uint8)eAdc_CfifoIdx]) = EQADC_GetCfifoRwConfigCmd(pAdc_ConfigCmdPtr);/* polyspace RTE:IDP */
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_SetCQueueConfigCmd(CONSTP2CONST(Eqadc_ConfigCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConfigCmdPtr, CONST(uint8, ADC_CONST) u8Adc_CmdCount, CONSTP2VAR(uint32, ADC_CONST, ADC_APPL_CONST) pAdc_CQueueMemDest)
{
    EQADC_DET_ERR(pAdc_ConfigCmdPtr != NULL); /* PRQA S 4404 */
    EQADC_DET_ERR(pAdc_CQueueMemDest != NULL); /* PRQA S 4404 */

    VAR(uint8, AUTOMATIC)u8Adc_Index;

    for (u8Adc_Index = 0U; u8Adc_Index < u8Adc_CmdCount; u8Adc_Index++)
    {
        pAdc_CQueueMemDest[u8Adc_Index] = EQADC_GetCfifoRwConfigCmd(&(pAdc_ConfigCmdPtr[u8Adc_Index]));
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

/* Conversion Command Format for the Standard Configuration
 * Conversion Command Format for Alternate Configurations */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_CfifoPushConvCmd(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, CONSTP2CONST(Eqadc_ConvCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConvCmdPtr)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR(pAdc_ConvCmdPtr != NULL); /* PRQA S 4404 */
    
    if(((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE) && ((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT))
    {
        *(EQADC_CFPR[(uint8)eAdc_Instance][(uint8)eAdc_CfifoIdx]) = EQADC_GetCfifoConversionCmd(pAdc_ConvCmdPtr);
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_SetCQueueConvCmd(CONSTP2CONST(Eqadc_ConvCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConvCmdPtr, CONST(uint16, ADC_CONST) u16Adc_CmdCount, CONST(uint16, ADC_CONST) u16Adc_StreamNumSamp, CONST(uint16, ADC_CONST) u16Adc_DmaSampleNum, CONSTP2VAR(uint32, ADC_CONST, ADC_APPL_CONST) pAdc_CQueueMemDest)
{
    EQADC_DET_ERR(pAdc_ConvCmdPtr != NULL); /* PRQA S 4404 */
    EQADC_DET_ERR(pAdc_CQueueMemDest != NULL); /* PRQA S 4404 */

    VAR(uint16, AUTOMATIC) u16Adc_Index;
    VAR(uint16, AUTOMATIC) u16Adc_TempIndex = 0U;
    VAR(uint16, AUTOMATIC) u16Adc_TempStreamNumSamp = 0U;
    VAR(Eqadc_ConvCmdType, ADC_VAR) sAdc_TempConvCmd = {0};
    for (u16Adc_Index = 0U; u16Adc_Index < u16Adc_CmdCount; u16Adc_Index++)
    {
        if((u16Adc_StreamNumSamp == 1U) && (u16Adc_DmaSampleNum != 1U) && (u16Adc_DmaSampleNum != 0U))
        {
            if(u16Adc_TempStreamNumSamp >= (u16Adc_CmdCount / u16Adc_DmaSampleNum)) /* PRQA S 2834 */
            {
                u16Adc_TempIndex = 0U;
                u16Adc_TempStreamNumSamp = 0U;
            }
            sAdc_TempConvCmd = pAdc_ConvCmdPtr[u16Adc_TempIndex];/* polyspace RTE:NIV,IDP */
            pAdc_CQueueMemDest[u16Adc_Index] = EQADC_GetCfifoConversionCmd(&sAdc_TempConvCmd);/* polyspace RTE:IDP */
            u16Adc_TempStreamNumSamp++;
            u16Adc_TempIndex++;
        }
        else
        {
            if(u16Adc_TempStreamNumSamp >= u16Adc_StreamNumSamp)
            {
                u16Adc_TempIndex = (uint8)(u16Adc_TempIndex + 1U);
                u16Adc_TempStreamNumSamp = 0U;
            }

            sAdc_TempConvCmd = pAdc_ConvCmdPtr[u16Adc_TempIndex];/* polyspace RTE:NIV,IDP */

            if(u16Adc_StreamNumSamp > 0U)
            {
                if((sAdc_TempConvCmd.Eoq == TRUE) && \
                    (((u16Adc_Index + 1U) % (u16Adc_StreamNumSamp)) != 0U))
                {
                    sAdc_TempConvCmd.Eoq = FALSE;
                }
            }

            pAdc_CQueueMemDest[u16Adc_Index] = EQADC_GetCfifoConversionCmd(&sAdc_TempConvCmd);/* polyspace RTE:IDP */
            u16Adc_TempStreamNumSamp++;
        }
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(uint16, ADC_CODE) EQADC_LLD_RfifoPopData(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_RfifoIdx)
{
    EQADC_DET_ERR((uint8) eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8) eAdc_RfifoIdx < EQADC_RFIFO_COUNT); /* PRQA S 4404 */

    VAR(uint16, AUTOMATIC) uAdc_PopData = 0U;
    
    if((eAdc_Instance < ADC_EQADC_MAX_INSTANCE) && (eAdc_RfifoIdx < EQADC_RFIFO_COUNT))
    {
        uAdc_PopData = (uint16)((*(EQADC_RFPR[(uint8)eAdc_Instance][(uint8)eAdc_RfifoIdx])) & EQADC_RFPR_RF_POPX_MASK);/* polyspace RTE:NIV,IDP */
    }

    return uAdc_PopData;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
uint32 EQADC_LLD_RfifoPopData32bit(const EqadcInstanceType instance, const EqadcFifoIdxType RfifoIdx)
{
    EQADC_DET_ERR((uint8)instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)RfifoIdx < EQADC_RFIFO_COUNT); /* PRQA S 4404 */

    uint32 PopData32bit = 0U;

    if((instance < ADC_EQADC_MAX_INSTANCE) && (instance < EQADC_RFIFO_COUNT))/* PRQA S 2995 */
    {
        PopData32bit = (uint32)(*(EQADC_RFPR[(uint8)instance][(uint8)RfifoIdx]));
    }

    return PopData32bit;/* PRQA S 2962 */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
__attribute__((unused)) ADC_INLINE FUNC(status_t, ADC_CODE)  EQADC_LLD_ClearRfifoAllData(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_RfifoIdx)/* PRQA S 1505 */
{
    EQADC_DET_ERR((uint8) eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8) eAdc_RfifoIdx < EQADC_RFIFO_COUNT); /* PRQA S 4404 */

    VAR(status_t, AUTOMATIC) eAdc_ret = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) u8Adc_RfifoEntryCount;
    VAR(uint32, AUTOMATIC) u32Adc_TimeoutClear = EQADC_TIMEOUT_COUNT;

    /* Save Current RFIFO Drain request control */
    CONST(uint16, ADC_CONST) u16Adc_IntDmaCtrl_RfifoDrain \
        = EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_Instance, (uint8)eAdc_RfifoIdx);

    if (((u16Adc_IntDmaCtrl_RfifoDrain & EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN) == 0U) && \
       ((u16Adc_IntDmaCtrl_RfifoDrain & EQADC_IRQDMA_REQ_SEL_RFIFODRAIN) == (uint16)EQADC_FILL_SEL_INT))
    {
        u8Adc_RfifoEntryCount \
            = EQADC_LLD_GetFifoFlagStatus(eAdc_Instance, eAdc_RfifoIdx, EQADC_FISR_RFIFO_ENTRY_COUNT);

        while ((u8Adc_RfifoEntryCount != 0U) && (u32Adc_TimeoutClear > 0UL))
        {
            (void) EQADC_LLD_RfifoPopData(eAdc_Instance, eAdc_RfifoIdx); /* Clear Result data */

            u8Adc_RfifoEntryCount \
                = EQADC_LLD_GetFifoFlagStatus(eAdc_Instance, eAdc_RfifoIdx, EQADC_FISR_RFIFO_ENTRY_COUNT);

            u32Adc_TimeoutClear--;
        }

        if (u32Adc_TimeoutClear == 0UL)
        {
            eAdc_ret = STATUS_TIMEOUT;
        }
        else
        {
            EQADC_LLD_ClearFifoIntFlag(eAdc_Instance, eAdc_RfifoIdx, (EQADC_FIFO_FLAG_RFIFO_OVERFLOW | EQADC_FIFO_FLAG_RFIFO_DRAIN));
        }
    }
    else
    {
        eAdc_ret = STATUS_ERROR;
    }

    return eAdc_ret;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_SingleScanEn(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    if (((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE) && ((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT))
    {
        EQADC_CFCRxSetSSE((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx);
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_SingleScanEn_Sync(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    /* EQADC CfifoIdx synchronous: 0 & 1, 2 & 3, 4 & 5, (6 & 7) */
    EQADC_CFCRxSetSSE_Sync((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(status_t, ADC_CODE)  EQADC_LLD_SetCfifoInvalidate(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    VAR(status_t, AUTOMATIC) eAdc_ret = STATUS_SUCCESS;
    VAR(Eqadc_CfifoModeType, AUTOMATIC) eAdc_CfifoModeCurrent;
    VAR(Eqadc_CfifoStatusType, AUTOMATIC) eAdc_CfifoStatusCurrent;

    eAdc_CfifoModeCurrent = (Eqadc_CfifoModeType)EQADC_CFCRxGetMode((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx);
    eAdc_CfifoStatusCurrent = EQADC_LLD_GetCFifoStatus(eAdc_Instance, eAdc_CfifoIdx);

    if ((eAdc_CfifoModeCurrent == EQADC_CFIFO_MODE_DISABLE) && (eAdc_CfifoStatusCurrent == EQADC_CFIFO_STATUS_IDLE))
    {
        EQADC_CFCRxSetInvalidate((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx);
    }
    else
    {
        eAdc_ret = STATUS_ERROR;
    }

    return eAdc_ret;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Eqadc_CfifoModeType, ADC_CODE) EQADC_LLD_GetCfifoMode(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    VAR(Eqadc_CfifoModeType, AUTOMATIC) eAdc_CfifoModeCurrent;

    eAdc_CfifoModeCurrent = (Eqadc_CfifoModeType)EQADC_CFCRxGetMode((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx);

    return eAdc_CfifoModeCurrent;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(status_t, ADC_CODE)  EQADC_LLD_SetCfifoMode(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, CONST(Eqadc_CfifoModeType, ADC_CONST) eAdc_CfifoModeTarget)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    VAR(status_t, AUTOMATIC) eAdc_status = STATUS_ERROR;
    VAR(Eqadc_CfifoModeType, AUTOMATIC) eAdc_CfifoModeCurrent;
    VAR(Eqadc_CfifoStatusType, AUTOMATIC) eAdc_CfifoStatusCurrent;

    eAdc_CfifoModeCurrent = (Eqadc_CfifoModeType)EQADC_CFCRxGetMode((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx);
    eAdc_CfifoStatusCurrent = EQADC_LLD_GetCFifoStatus(eAdc_Instance, eAdc_CfifoIdx);

    if (eAdc_CfifoModeTarget != EQADC_CFIFO_MODE_DISABLE)
    {
        if ((EQADC_CFIFO_MODE_DISABLE == eAdc_CfifoModeCurrent) && (EQADC_CFIFO_STATUS_IDLE == eAdc_CfifoStatusCurrent))
        {
            eAdc_status = STATUS_SUCCESS;
        }
    }
    else
    {
        eAdc_status = STATUS_SUCCESS;
    }

    if (STATUS_SUCCESS == eAdc_status)
    {
        EQADC_CFCRxSetMode((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx, (uint32)eAdc_CfifoModeTarget);
    }

    return eAdc_status;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(uint8, ADC_CODE) EQADC_LLD_GetCfifo0EntryExtEnDis(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    return EQADC_CFCR0_GetCfifo0EntryExtEnDis((uint8)eAdc_Instance);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_SetCfifo0EntryExtEnDis(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(boolean, ADC_CONST) bAdc_EnDis)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    EQADC_CFCR0_SetCfifo0EntryExtEnDis((uint8)eAdc_Instance, bAdc_EnDis);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Eqadc_Cfifo0AModeType, ADC_CODE) EQADC_LLD_GetCfifo0AdvanceMode(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    return ((Eqadc_Cfifo0AModeType)EQADC_CFCR0_GetAMode0((uint8)eAdc_Instance));
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(status_t, ADC_CODE)  EQADC_LLD_SetCfifo0AdvanceMode(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(Eqadc_Cfifo0AModeType, ADC_CONST) eAdc_AdvanceTrigMode)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_AdvanceTrigMode <= (uint8)EQADC_CFIFO0_AMODE_SINGLE_BOTH_EDGES_EXT_TRIG); /* PRQA S 4404 */

    VAR(status_t, AUTOMATIC) ret = STATUS_SUCCESS;
    VAR(Eqadc_Cfifo0AModeType, AUTOMATIC) eAdc_Cfifo0AModeCurrent;
    VAR(Eqadc_CfifoStatusType, AUTOMATIC) eAdc_CfifoStatusCurrent;

    eAdc_Cfifo0AModeCurrent = (Eqadc_Cfifo0AModeType)EQADC_CFCR0_GetAMode0((uint8)eAdc_Instance);
    eAdc_CfifoStatusCurrent = EQADC_LLD_GetCFifoStatus(eAdc_Instance, EQADC_FIFO_0);

    if (eAdc_AdvanceTrigMode != EQADC_CFIFO0_AMODE_DISABLE)
    {
        if ((eAdc_Cfifo0AModeCurrent != EQADC_CFIFO0_AMODE_DISABLE) || (eAdc_CfifoStatusCurrent != EQADC_CFIFO_STATUS_IDLE))
        {
            ret = STATUS_ERROR;
        }
    }

    if (STATUS_SUCCESS == ret)
    {
        EQADC_CFCR0_SetAMode0((uint8)eAdc_Instance, (uint8)eAdc_AdvanceTrigMode);
    }

    return ret;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(uint16, ADC_CODE) EQADC_LLD_GetIntDmaCtrlEn(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_FifoIdx)
{
    VAR(uint16, AUTOMATIC) u16Adc_IntDmaCtrl;

    u16Adc_IntDmaCtrl = EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_Instance, (uint8)eAdc_FifoIdx);

    return u16Adc_IntDmaCtrl;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_IntEnDis(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_FifoIdx, VAR(uint16, AUTOMATIC) u16Adc_IntMask, VAR(boolean, AUTOMATIC) bAdc_EnDis)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_FifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR((u16Adc_IntMask & ~EQADC_IRQ_EN_ALL) == 0U); /* PRQA S 4404 */

    VAR(uint16, AUTOMATIC) u16Adc_IntBitMask = u16Adc_IntMask;

    if ((u16Adc_IntMask & EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN) != 0U)
    {
        /* RFIFO Drain has selected DMA */
        if ((EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_Instance, (uint8)eAdc_FifoIdx) & EQADC_IRQDMA_REQ_SEL_RFIFODRAIN) != 0U)
        {
            EQADC_DET_ERR(FALSE);
            u16Adc_IntBitMask = (uint16)(u16Adc_IntBitMask & ((uint16)(~(uint16)EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN)));
        }
    }
    if ((u16Adc_IntMask & EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL) != 0U)
    {
        /* CFIFO Fill has selected DMA */
        if ((EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_Instance, (uint8)eAdc_FifoIdx) & EQADC_IRQDMA_REQ_SEL_CFIFOFILL) != 0U)
        {
            EQADC_DET_ERR(FALSE);
            u16Adc_IntBitMask = (uint16)(u16Adc_IntBitMask & ((uint16)(~(uint16)EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL)));
        }
    }

    EQADC_IDCRx_FifoIntDmaEnDis((uint8)eAdc_Instance, (uint8)eAdc_FifoIdx, u16Adc_IntBitMask, bAdc_EnDis);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_DmaEnDis(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_FifoIdx, VAR(uint16, AUTOMATIC) u16Adc_DmaMask, VAR(boolean, AUTOMATIC) bAdc_EnDis) /* PRQA S 1505 */
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_FifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR((u16Adc_DmaMask & ~EQADC_DMA_EN_ALL) == 0U); /* PRQA S 4404 */

    VAR(uint16, AUTOMATIC) u16Adc_DmaBitMask = u16Adc_DmaMask;

    if ((u16Adc_DmaMask & EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN) != 0U)
    {
        /* RFIFO Drain has selected Interrupt */
        if ((EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_Instance, (uint8)eAdc_FifoIdx) & EQADC_IRQDMA_REQ_SEL_RFIFODRAIN) == 0U)
        {
            EQADC_DET_ERR(FALSE);
            u16Adc_DmaBitMask = (uint16)(u16Adc_DmaBitMask & ((uint16)(~(uint16)EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN)));
        }
    }
    if ((u16Adc_DmaMask & EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL) != 0U)
    {
        /* CFIFO Fill has selected Interrupt */
        if ((EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_Instance, (uint8)eAdc_FifoIdx) & EQADC_IRQDMA_REQ_SEL_CFIFOFILL) == 0U)
        {
            EQADC_DET_ERR(FALSE);
            u16Adc_DmaBitMask = (uint16)(u16Adc_DmaBitMask & ((uint16)(~(uint16)EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL)));
        }
    }

    EQADC_IDCRx_FifoIntDmaEnDis((uint8)eAdc_Instance, (uint8)eAdc_FifoIdx, u16Adc_DmaBitMask, bAdc_EnDis);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(uint8, ADC_CODE) EQADC_LLD_GetFifoFlagStatus(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_FifoIdx, CONST(Eqadc_FifoIntStatusType, ADC_CONST) eAdc_FifoStatusSel)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_FifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    VAR(uint8, AUTOMATIC)u8Adc_FifoStatus = 0U;
    CONSTP2CONST(EQADC_TagType, ADC_CONST, ADC_APPL_CONST) pAdc_BasePtr = Adc_EqadcBase[(uint8)eAdc_Instance];
    CONST(uint8, ADC_CONST) u8Adc_Fifo_x = (uint8)eAdc_FifoIdx;

    if(u8Adc_Fifo_x >= EQADC_CFIFO_COUNT)
    {
        return u8Adc_FifoStatus;
    }

    switch (eAdc_FifoStatusSel)
    {
        case EQADC_FISR_NON_COHERENCY:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_NCFX_MASK) >> EQADC_FISR_NCFX_SHIFT);
            break;
        }
        case EQADC_FISR_TRIG_OVERRUN:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_TORFX_MASK) >> EQADC_FISR_TORFX_SHIFT);
            break;
        }
        case EQADC_FISR_PAUSE:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_PFX_MASK) >> EQADC_FISR_PFX_SHIFT);
            break;
        }
        case EQADC_FISR_END_OF_QUEUE:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_EOQFX_MASK) >> EQADC_FISR_EOQFX_SHIFT); /* polyspace RTE:NIV */
            break;
        }
        case EQADC_FISR_CFIFO_UNDERFLOW:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_CFUFX_MASK) >> EQADC_FISR_CFUFX_SHIFT);
            break;
        }
        case EQADC_FISR_CFIFO_SINGLE_SCAN:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_SSSX_MASK) >> EQADC_FISR_SSSX_SHIFT);
            break;
        }
        case EQADC_FISR_CFIFO_FILL:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_CFFFX_MASK) >> EQADC_FISR_CFFFX_SHIFT);
            break;
        }
        case EQADC_FISR_RFIFO_OVERFLOW:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_RFOFX_MASK) >> EQADC_FISR_RFOFX_SHIFT);
            break;
        }
        case EQADC_FISR_RFIFO_DRAIN:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_RFDFX_MASK)>> EQADC_FISR_RFDFX_SHIFT); /* polyspace RTE:NIV */
            break;
        }
        case EQADC_FISR_CFIFO_ENTRY_COUNT:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_CFCTRX_MASK) >> EQADC_FISR_CFCTRX_SHIFT);
            break;
        }
        case EQADC_FISR_CFIFO_TRANS_NEXT_PTR:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_TNXTPTRX_MASK) >> EQADC_FISR_TNXTPTRX_SHIFT);
            break;
        }
        case EQADC_FISR_RFIFO_ENTRY_COUNT:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_RFCTRX_MASK) >> EQADC_FISR_RFCTRX_SHIFT); /* polyspace RTE:NIV */
            break;
        }
        case EQADC_FISR_RFIFO_POP_NEXT_PTR:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_POPNXTPTRX_MASK) >> EQADC_FISR_POPNXTPTRX_SHIFT);
            break;
        }
        default:
        {
            EQADC_DET_ERR(FALSE);
            break;
        }
    }

    return u8Adc_FifoStatus;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(uint32, ADC_CODE) EQADC_LLD_GetFifoIntFlag(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_FifoIdx)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_FifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    VAR(uint32, AUTOMATIC) u32Adc_FifoFlagMask = 0U;
    CONSTP2CONST(EQADC_TagType, ADC_CONST, ADC_APPL_CONST) pAdc_BasePtr = Adc_EqadcBase[(uint8)eAdc_Instance];

    u32Adc_FifoFlagMask = pAdc_BasePtr->FISR[(uint8)eAdc_FifoIdx].R & EQADC_FIFO_FLAG_ALL;/* polyspace RTE:NIV */
    return u32Adc_FifoFlagMask;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_ClearFifoIntFlag(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_FifoIdx, VAR(uint32, AUTOMATIC) u32Adc_FifoFlagMask)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_FifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR((u32Adc_FifoFlagMask & ~EQADC_FIFO_FLAG_ALL) == 0U); /* PRQA S 4404 */

    CONSTP2VAR(EQADC_TagType, ADC_CONST, ADC_APPL_CONST) pAdc_BasePtr = Adc_EqadcBase[(uint8)eAdc_Instance];

    VAR(uint32, AUTOMATIC) u32Adc_FifoFlagBitMask = u32Adc_FifoFlagMask;

    if ((u32Adc_FifoFlagMask & EQADC_FIFO_FLAG_CFIFO_FILL) != 0U)
    {
        if ((EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_Instance, (uint8)eAdc_FifoIdx) & EQADC_IRQDMA_REQ_SEL_CFIFOFILL) != 0U)
        {
            EQADC_DET_ERR(FALSE);
            u32Adc_FifoFlagBitMask &= ~EQADC_FIFO_FLAG_CFIFO_FILL;
        }
    }
    if ((u32Adc_FifoFlagMask & EQADC_FIFO_FLAG_RFIFO_DRAIN) != 0U)
    {
        if ((EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_Instance, (uint8)eAdc_FifoIdx) & EQADC_IRQDMA_REQ_SEL_RFIFODRAIN) != 0U)
        {
            EQADC_DET_ERR(FALSE);
            u32Adc_FifoFlagBitMask &= ~EQADC_FIFO_FLAG_RFIFO_DRAIN;
        }
    }
    if ((uint8)eAdc_FifoIdx < EQADC_CFIFO_COUNT)
    {
        pAdc_BasePtr->FISR[(uint8)eAdc_FifoIdx].R = u32Adc_FifoFlagBitMask; /* w1c */ /* polyspace RTE:OBAI */
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(uint16, ADC_CODE) EQADC_LLD_GetCfifoTransferCounter(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    return EQADC_CFTCRx_GetCfifoTransCount((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_SetCfifoTransferCounter(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, CONST(uint16, ADC_CONST) u16Adc_TransCount)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR(u16Adc_TransCount <= EQADC_CFTCR0_TC_CF1_MASK); /* PRQA S 4404 */

    EQADC_CFTCRx_SetCfifoTransCount((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx, u16Adc_TransCount);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Eqadc_CfifoStatusType, AUTOMATIC) EQADC_LLD_GetCFifoStatusSnapshot(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, CONST(EqadcAdcIdxType, ADC_CONST)  eAdc_AdcIdx)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8) eAdc_AdcIdx < EQADC_ADC_NUM); /* PRQA S 4404 */

    VAR(Eqadc_CfifoStatusType, AUTOMATIC) eAdc_CfifoStatus;

    eAdc_CfifoStatus = (Eqadc_CfifoStatusType)EQADC_CFSSRx_GetCfifoStatusAtTCB_Snapshot((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx, (uint8) eAdc_AdcIdx);

    return eAdc_CfifoStatus;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(EqadcFifoIdxType, ADC_CODE) EQADC_LLD_GetLastCFifoSnapshot(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcAdcIdxType, ADC_CONST)  eAdc_AdcIdx)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8) eAdc_AdcIdx < EQADC_ADC_NUM); /* PRQA S 4404 */

    VAR(EqadcFifoIdxType, AUTOMATIC) eAdc_Cfifo_x;

    eAdc_Cfifo_x = (EqadcFifoIdxType)EQADC_CFSSRx_GetLastCfifoToTCB_Snapshot((uint8)eAdc_Instance, (uint8) eAdc_AdcIdx);

    return eAdc_Cfifo_x;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(uint16, ADC_CODE) EQADC_LLD_GetTransCountLastCFifoSnapshot(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcAdcIdxType, ADC_CONST)  eAdc_AdcIdx)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8) eAdc_AdcIdx < EQADC_ADC_NUM); /* PRQA S 4404 */

    VAR(uint16, AUTOMATIC) u16Adc_TransferCount;

    u16Adc_TransferCount = EQADC_CFSSRx_GetTransCountForLastCfifoToTCB_Snapshot((uint8)eAdc_Instance, (uint8) eAdc_AdcIdx);

    return u16Adc_TransferCount;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Eqadc_CfifoStatusType, ADC_CODE) EQADC_LLD_GetCFifoStatus(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx)/* PRQA S 1505 */
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    VAR(uint32, AUTOMATIC) u32Adc_TempVal;
    CONSTP2CONST(EQADC_TagType, ADC_CONST, ADC_APPL_CONST) pAdc_BasePtr = Adc_EqadcBase[(uint8)eAdc_Instance];
    VAR(uint8, AUTOMATIC) u8Adc_CfifoStatus = (uint8)EQADC_CFIFO_STATUS_IDLE;
    VAR(uint32, AUTOMATIC) EQADC_CFSR_CFSx_MaskVal = EQADC_CFSR_CFS0_MASK;

    u32Adc_TempVal = (uint32)eAdc_CfifoIdx * 2U;
    if(u32Adc_TempVal < 32U)
    {
        EQADC_CFSR_CFSx_MaskVal = (uint32)(EQADC_CFSR_CFS0_MASK >> u32Adc_TempVal);
    }

    VAR(uint8, AUTOMATIC) EQADC_CFSR_CFSx_ShiftVal = EQADC_CFSR_CFS0_SHIFT - ((uint8)eAdc_CfifoIdx * 2U);
    if(EQADC_CFSR_CFSx_ShiftVal < 32u)
    {
        u8Adc_CfifoStatus = (uint8)((uint32)(pAdc_BasePtr->CFSR.R & EQADC_CFSR_CFSx_MaskVal) >> EQADC_CFSR_CFSx_ShiftVal);/* polyspace RTE:NIV */
    }

    return (Eqadc_CfifoStatusType)u8Adc_CfifoStatus;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
/* EQADC CFIFO Trigger Delay */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_SetCfifoTrigDelay(CONST(EqadcInstanceType, ADC_CONST) eAdc_instance, CONST(EqadcFifoIdxType, ADC_CONST)  eAdc_CfifoIdx, CONST(boolean, ADC_CONST)  eAdc_CfifoTrigDelayEn, CONST(uint32, ADC_CONST) eAdc_CfifoTrigDelayCnt)
{
    EQADC_DET_ERR((uint8)eAdc_instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    VAR(uint32, AUTOMATIC) u32Adc_CfifoTrigDelayReg;
    u32Adc_CfifoTrigDelayReg = ((eAdc_CfifoTrigDelayEn == TRUE) ? EQADC_DLY_CFIFO_TRIG_DELAY_EN_MASK : 0UL) | \
                               (eAdc_CfifoTrigDelayCnt & EQADC_DLY_CFIFO_TRIG_DELAY_VAL_MASK);
    *(EQADC_DLY[eAdc_instance][(uint8)(eAdc_CfifoIdx)]) = u32Adc_CfifoTrigDelayReg; /* polyspace RTE:OBAI */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */

#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_SetRedLineClientConfig(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(uint8, ADC_CONST) u8Adc_ClientIdx, CONST(Eqadc_RedLineBitsSelType, ADC_CONST) eAdc_RedLineTbaseBitSel, CONST(Eqadc_RedLineServerDataSlotSelType, ADC_CONST) eAdc_RedLineSlotSel)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR(u8Adc_ClientIdx <= EQADC_STAC_BUS_CLIENT_2); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_RedLineTbaseBitSel <= (uint8)EQADC_REDLINE_BITS_SEL_TBASE_8_23); /* PRQA S 4404 */

    EQADC_REDLCCR_SetREDBS_SRVx((uint8)eAdc_Instance, u8Adc_ClientIdx, (uint8)eAdc_RedLineTbaseBitSel, (uint8)eAdc_RedLineSlotSel);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(uint32, ADC_CODE) EQADC_LLD_GetCfifoEntryData(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, CONST(uint8, ADC_CONST) u8Adc_EntryIdx)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR(u8Adc_EntryIdx < EQADC_CFIFO_ENTRY_COUNT); /* PRQA S 4404 */

    return EQADC_CFxRw_GetCfifoData((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx, u8Adc_EntryIdx);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(uint32, ADC_CODE) EQADC_LLD_GetCfifo0ExtEntryData(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(uint8, ADC_CONST) u8Adc_EntryIdx)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR(u8Adc_EntryIdx < EQADC_CFIFO_ENTRY_COUNT); /* PRQA S 4404 */

    CONSTP2CONST(EQADC_TagType, ADC_CONST, ADC_APPL_CONST) pAdc_BasePtr = Adc_EqadcBase[(uint8)eAdc_Instance];

    VAR(uint32, AUTOMATIC) u32Adc_Cfifo0ExtData = 0U;

    if(u8Adc_EntryIdx < EQADC_CFIFO_ENTRY_COUNT)
    {
        u32Adc_Cfifo0ExtData = pAdc_BasePtr->CF0ER[u8Adc_EntryIdx].R;/* polyspace RTE:NIV */
    }

    return u32Adc_Cfifo0ExtData;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(uint32, ADC_CODE) EQADC_LLD_GetRfifoEntryData(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_RfifoIdx, CONST(uint8, ADC_CONST) u8Adc_EntryIdx)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_RfifoIdx < EQADC_RFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR(u8Adc_EntryIdx < EQADC_RFIFO_ENTRY_COUNT); /* PRQA S 4404 */

    return EQADC_RFxRw_GetRfifoData((uint8)eAdc_Instance, (uint8)eAdc_RfifoIdx, u8Adc_EntryIdx);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_SetCfifoHwTrigSource(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, CONST(uint8, ADC_CONST) eAdc_TrigSourceSel, CONST(uint8, ADC_CONST) eAdc_GTM_ADC_TRIG_OUTSEL)/* PRQA S 1505 */
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    VAR(uint8, ADC_VAR) u8Adc_trigregidx = 0U;
    VAR(uint8, ADC_VAR) u8Adc_TrigRegMemberIdx = 0U;

    EQADC_ISELx_SetCfifoTrig((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx, eAdc_TrigSourceSel);

    if ((eAdc_TrigSourceSel >= EQADC_HW_TRIG_GTM_TRIG0_MEMBER0) && (eAdc_TrigSourceSel <= EQADC_HW_TRIG_GTM_TRIG4_MEMBER11))
    {
        u8Adc_trigregidx = ((eAdc_TrigSourceSel - EQADC_HW_TRIG_GTM_TRIG0_MEMBER0) / GTM_ADC_TRIG_MEMBER_NUM);
        u8Adc_TrigRegMemberIdx = ((eAdc_TrigSourceSel - EQADC_HW_TRIG_GTM_TRIG0_MEMBER0) % GTM_ADC_TRIG_MEMBER_NUM);
        
        GTM_to_EQADC_Connections(0U, u8Adc_trigregidx, u8Adc_TrigRegMemberIdx, eAdc_GTM_ADC_TRIG_OUTSEL); 
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#else
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_SetCfifoHwTrigSource(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, CONST(uint8, ADC_CONST) eAdc_TrigSourceSel)/* PRQA S 1505 */
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    EQADC_ISELx_SetCfifoTrig((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx, eAdc_TrigSourceSel);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_SetCfifo0AdvanceTrigSource(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(uint8, ADC_CONST) eAdc_AdvTrigSourceSel) /* PRQA S 1505 */
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE);  /* PRQA S 4404 */

    EQADC_ISELx_SetCfifo0AdvanceTrig((uint8)eAdc_Instance, eAdc_AdvTrigSourceSel);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_EQADC_RFIFO_SOFT_RESET
/*******************************************************************************
 * @brief EQADC RFIFOx Software Reset.
 *
 * @param instance: EQADC instance
 *        RfifoIdx: RFIFO number
 *        [out] Function return status.
 *
 * @note  During software reset of RFIFOx,
 *          make sure that there is no write request or read request to RFIFOx.
 *        The RFIFO software reset will clear all flags
 *          and the data stored in the FIFO, except for the flag RFDF/RFOF.
 *******************************************************************************/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
status_t EQADC_LLD_RfifoSoftwareReset(const EqadcInstanceType instance, const EqadcFifoIdxType RfifoIdx)
{
    EQADC_DET_ERR((uint8)instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    EQADC_TagType * const BasePtr = Adc_EqadcBase[(uint8)instance];/* PRQA S 2934 */
    status_t ret = STATUS_SUCCESS;
    uint32 AdcTimeout = EQADC_TIMEOUT_COUNT;

    if (((uint8)instance < ADC_EQADC_MAX_INSTANCE) && ((uint8)RfifoIdx < EQADC_RFIFO_COUNT))
    {
        BasePtr->RFSRR.R = (uint32)(EQADC_RFSRR_RF_SW0_MASK << (uint8)RfifoIdx);
        while (((BasePtr->RFSRR.R & (uint32)(EQADC_RFSRR_RF_SW0_MASK << (uint8)RfifoIdx)) == 0U) && (AdcTimeout > 0UL))
        {
            AdcTimeout--;
        }
        if (0UL == AdcTimeout)
        {
            ret = STATUS_TIMEOUT;
        }
        else
        {
            EQADC_LLD_ClearFifoIntFlag(instance, RfifoIdx, (EQADC_FIFO_FLAG_RFIFO_OVERFLOW | EQADC_FIFO_FLAG_RFIFO_DRAIN));
        }
    }
    else
    {
        ret = STATUS_ERROR;
    }

    return ret;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_RFIFO_SOFT_RESET */

#ifdef RESOURCE_SUPPORT_EQADC_FIFO_DMA_CTRL_SEL
/*******************************************************************************
 * @brief EQADC CFIFOx/RFIFOx DMA controller select.
 *
 * @param instance: EQADC instance
 *        CfifoIdx: CFIFO number
 *        RfifoIdx: RFIFO number
 *        DMA_Sel: EQADC_FIFO_SEL_DMA_0 /EQADC_FIFO_SEL_DMA_1
 *
 * @note  The DMA_SEL is used to select which DMA controller will be used to
 *          process CFIFOx/RFIFOx DMA request.
 *******************************************************************************/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
void EQADC_LLD_FifoDmaControllerSelect(const EqadcInstanceType instance, const EqadcFifoIdxType CfifoIdx, const EqadcFifoIdxType RfifoIdx, const Eqadc_FifoDMACtrlSelType DMA_Sel)
{
    EQADC_DET_ERR((uint8)instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    EQADC_TagType * const BasePtr = Adc_EqadcBase[(uint8)instance];

    if (((uint8)instance < ADC_EQADC_MAX_INSTANCE) && ((uint8)CfifoIdx < EQADC_CFIFO_COUNT) && ((uint8)RfifoIdx < EQADC_RFIFO_COUNT))
    {
        if (EQADC_FIFO_SEL_DMA_0 == DMA_Sel)
        {
            BasePtr->DMA_SEL.R &= ~(uint32)(((uint32)EQADC_DMA_SEL_CF0_DMA_SEL_MASK << (uint8)CfifoIdx) | ((uint32)EQADC_DMA_SEL_RF0_DMA_SEL_MASK << (uint8)RfifoIdx));/* PRQA S 1258 *//* polyspace RTE:NIV */
        }
        else if (EQADC_FIFO_SEL_DMA_1 == DMA_Sel)
        {
            BasePtr->DMA_SEL.R |= (uint32)(((uint32)EQADC_DMA_SEL_CF0_DMA_SEL_MASK << (uint8)CfifoIdx) | ((uint32)EQADC_DMA_SEL_RF0_DMA_SEL_MASK << (uint8)RfifoIdx));/* PRQA S 1258 *//* polyspace RTE:NIV */
        }
        else
        {
            /* nothing */
        }
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
void EQADC_LLD_CfifoDmaControllerSelect(const EqadcInstanceType instance, const EqadcFifoIdxType CfifoIdx, const Eqadc_FifoDMACtrlSelType DMA_Sel)
{
    EQADC_DET_ERR((uint8)instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    EQADC_TagType * const BasePtr = Adc_EqadcBase[(uint8)instance];

    if (((uint8)instance < ADC_EQADC_MAX_INSTANCE) && ((uint8)CfifoIdx < EQADC_CFIFO_COUNT))
    {
        if (EQADC_FIFO_SEL_DMA_0 == DMA_Sel)
        {
            BasePtr->DMA_SEL.R &= ~(uint32)(EQADC_DMA_SEL_CF0_DMA_SEL_MASK << (uint8)CfifoIdx);/* polyspace RTE:NIV */
        }
        else if (EQADC_FIFO_SEL_DMA_1 == DMA_Sel)
        {
            BasePtr->DMA_SEL.R |= (uint32)(EQADC_DMA_SEL_CF0_DMA_SEL_MASK << (uint8)CfifoIdx);/* polyspace RTE:NIV */
        }
        else
        {
            /* nothing */
        }
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
void EQADC_LLD_RfifoDmaControllerSelect(const EqadcInstanceType instance, const EqadcFifoIdxType RfifoIdx, const Eqadc_FifoDMACtrlSelType DMA_Sel)
{
    EQADC_DET_ERR((uint8)instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    EQADC_TagType * const BasePtr = Adc_EqadcBase[(uint8)instance];

    if (((uint8)instance < ADC_EQADC_MAX_INSTANCE) && ((uint8)RfifoIdx < EQADC_RFIFO_COUNT))
    {
        if (EQADC_FIFO_SEL_DMA_0 == DMA_Sel)
        {
            BasePtr->DMA_SEL.R &= ~(uint32)(EQADC_DMA_SEL_RF0_DMA_SEL_MASK << (uint8)RfifoIdx);/* polyspace RTE:NIV */
        }
        else if (EQADC_FIFO_SEL_DMA_1 == DMA_Sel)
        {
            BasePtr->DMA_SEL.R |= (uint32)(EQADC_DMA_SEL_RF0_DMA_SEL_MASK << (uint8)RfifoIdx);/* polyspace RTE:NIV */
        }
        else
        {
            /* nothing */
        }
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_DMA_CTRL_SEL */

#if EQADC_ONCHIPADC_RW_LLD
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_LLD_SetAdcRegValueSSE(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcAdcIdxType, ADC_CONST) eAdc_AdcIdx, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) eAdc_AdcReg, CONST(uint16, ADC_CONST) u16Adc_AdcRegVal)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    VAR(uint32, AUTOMATIC) u32Adc_TestTimeout = EQADC_TIMEOUT_COUNT;

    EQADC_WriteConfigCmdSSE((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx, (uint8) eAdc_AdcIdx, eAdc_AdcReg, u16Adc_AdcRegVal);

    while ((EQADC_LLD_GetFifoFlagStatus(eAdc_Instance, eAdc_CfifoIdx, EQADC_FISR_END_OF_QUEUE) != 1U) \
            && (u32Adc_TestTimeout > 0UL))
    {
        u32Adc_TestTimeout--;
    }

    if(u32Adc_TestTimeout == 0U)
    {
#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
        Adc_DemReportErrorStatus(DEM_EVENTID_SETADCREGVALUESSE, DEM_EVENT_TIMEOUT);
#endif
    }

    /* Clear Flag */
    EQADC_LLD_ClearFifoIntFlag(eAdc_Instance, eAdc_CfifoIdx, EQADC_FIFO_FLAG_END_OF_QUEUE);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(uint16, ADC_CODE) EQADC_LLD_GetAdcRegValueSSE(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, CONST(EqadcAdcIdxType, ADC_CONST)  eAdc_AdcIdx, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, CONST(EqadcFifoIdxType, ADC_CONST) eAdc_RfifoIdx, CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) eAdc_AdcReg)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_RfifoIdx < EQADC_RFIFO_COUNT); /* PRQA S 4404 */

    VAR(uint16, AUTOMATIC) u16Adc_AdcRegVal = 0xFFFFU;
    VAR(uint32, AUTOMATIC) u32Adc_TestTimeout = EQADC_TIMEOUT_COUNT;

    EQADC_ReadConfigCmdSSE((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx, (uint8) eAdc_AdcIdx, eAdc_AdcReg, (uint8)eAdc_RfifoIdx);

    while ((EQADC_LLD_GetFifoFlagStatus(eAdc_Instance, eAdc_RfifoIdx, EQADC_FISR_RFIFO_DRAIN) != 1U) \
            && (u32Adc_TestTimeout > 0UL))
    {
        u32Adc_TestTimeout--;
    }

    if (u32Adc_TestTimeout > 0UL)
    {
        /* Pop Rfifo result data */
        u16Adc_AdcRegVal = EQADC_LLD_RfifoPopData(eAdc_Instance, eAdc_RfifoIdx);
    }
#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
    else
    {
        Adc_DemReportErrorStatus(DEM_EVENTID_GETADCREGVALUESSE, DEM_EVENT_TIMEOUT);
    }
#endif  /* ADC_DEM_REPORT_ERROR_ENABLE */

    /* Clear Flag */
    EQADC_LLD_ClearFifoIntFlag(eAdc_Instance, eAdc_RfifoIdx, EQADC_FIFO_FLAG_RFIFO_DRAIN);
    EQADC_LLD_ClearFifoIntFlag(eAdc_Instance, eAdc_CfifoIdx, EQADC_FIFO_FLAG_END_OF_QUEUE);

    return u16Adc_AdcRegVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* EQADC_ONCHIPADC_RW_LLD */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
static FUNC(void, ADC_CODE) EQADC_WriteConfigCmdSSE(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, CONST(uint8, ADC_CONST)  u8Adc_AdcIdx, CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) eAdc_AdcAddr, CONST(uint16, ADC_CONST) u16Adc_AdcRegVal)
{
    Eqadc_ConfigCmdType ConfigCmd;

    EQADC_GetDefaultRwConfigCmd(&ConfigCmd);
    ConfigCmd.cBufNum       = u8Adc_AdcIdx;
    ConfigCmd.AdcRegAddr    = eAdc_AdcAddr;
    ConfigCmd.AdcRegValue   = u16Adc_AdcRegVal;
    EQADC_LLD_CfifoPushConfigCmd((EqadcInstanceType)u8Adc_Instance, (EqadcFifoIdxType)u8Adc_CfifoIdx, &ConfigCmd);
    EQADC_CFCRxSetSSE(u8Adc_Instance, u8Adc_CfifoIdx);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_ReadConfigCmdSSE(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, CONST(uint8, ADC_CONST) u8Adc_AdcIdx, CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) eAdc_AdcAddr, CONST(uint8, ADC_CONST) u8Adc_RfifoIdx)
{
    Eqadc_ConfigCmdType ConfigCmd;

    EQADC_GetDefaultRwConfigCmd(&ConfigCmd);
    ConfigCmd.cBufNum       = u8Adc_AdcIdx;
    ConfigCmd.RwCfgCmdType  = EQADC_CONFIG_CMD_READ;
    ConfigCmd.AdcRegAddr    = eAdc_AdcAddr;
    ConfigCmd.RfifoMsgTag   = (Eqadc_RfifoMsgTagType)u8Adc_RfifoIdx;
    EQADC_LLD_CfifoPushConfigCmd((EqadcInstanceType)u8Adc_Instance, (EqadcFifoIdxType)u8Adc_CfifoIdx, &ConfigCmd);
    EQADC_CFCRxSetSSE(u8Adc_Instance, u8Adc_CfifoIdx);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
static FUNC(status_t, ADC_CODE) EQADC_DeinitCfifo(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx)
{
    VAR(uint16, AUTOMATIC) u16Adc_IntDmaMask = 0U;
    VAR(uint32, AUTOMATIC) u32Adc_Timeout;
    VAR(status_t, AUTOMATIC) eAdc_ret = STATUS_SUCCESS;

    EQADC_CFCRxSetMode(u8Adc_Instance, u8Adc_CfifoIdx, (uint32)EQADC_CFIFO_MODE_DISABLE);

    u32Adc_Timeout = EQADC_TIMEOUT_COUNT;
    while ((EQADC_LLD_GetCFifoStatus((EqadcInstanceType)u8Adc_Instance, (EqadcFifoIdxType)u8Adc_CfifoIdx) != EQADC_CFIFO_STATUS_IDLE) && (u32Adc_Timeout > 0UL))
    {
        u32Adc_Timeout--;
    }

    if (0UL == u32Adc_Timeout)
    {
        eAdc_ret = STATUS_TIMEOUT;
    }

    u16Adc_IntDmaMask = (uint16)(EQADC_IRQ_EN_ALL & (uint16)~((uint16)(EQADC_IRQ_EN_RFIFO_OVERFLOW | EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN)));
    EQADC_IDCRx_FifoIntDmaEnDis(u8Adc_Instance, u8Adc_CfifoIdx, u16Adc_IntDmaMask, FALSE);
    EQADC_IDCRx_FifoIntDmaEnDis(u8Adc_Instance, u8Adc_CfifoIdx, EQADC_IRQDMA_REQ_SEL_CFIFOFILL, FALSE);

    /* Stop eDMA mapped channel */
    if (DmaMappedChanForCmd[u8Adc_Instance][u8Adc_CfifoIdx] != EQADC_DMA_MAPPED_CHAN_INVALID)
    {
        (void) EDMA_ClearChannelRequest(DmaMappedChanForCmd[u8Adc_Instance][u8Adc_CfifoIdx]);

        DmaMappedChanForCmd[u8Adc_Instance][u8Adc_CfifoIdx] = EQADC_DMA_MAPPED_CHAN_INVALID;
    }

#ifdef RESOURCE_SUPPORT_EQADC_FIFO_DMA_CTRL_SEL
    EQADC_LLD_CfifoDmaControllerSelect((EqadcInstanceType)u8Adc_Instance, (EqadcFifoIdxType)u8Adc_CfifoIdx, EQADC_FIFO_SEL_DMA_0);
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_DMA_CTRL_SEL */

    /* invalidate CFIFO all entries */
    EQADC_CFCRxSetInvalidate(u8Adc_Instance,u8Adc_CfifoIdx);

    /* close CFIFO Trigger */
    EQADC_ISELx_SetCfifoTrig(u8Adc_Instance, u8Adc_CfifoIdx, EQADC_HW_TRIG_NOT_CONNECTED);

    if ((uint8)EQADC_FIFO_0 == u8Adc_CfifoIdx)
    {
        /* disable CFIFO0 EntryExt */
        EQADC_CFCR0_SetCfifo0EntryExtEnDis(u8Adc_Instance, FALSE);

        /* disable CFIFO0 AdvanceMode */
        EQADC_CFCR0_SetAMode0(u8Adc_Instance, (uint8)EQADC_CFIFO0_AMODE_DISABLE);

        /* disable CFIFO0 StreamMode */
        EQADC_CFCR0_Cfifo0StreamModeEnDis(u8Adc_Instance, FALSE);

        /* close CFIFO0 AdvanceTrig */
        EQADC_ISELx_SetCfifo0AdvanceTrig(u8Adc_Instance, EQADC_ATRIG_NOT_CONNECTED);
    }

#if defined(RESOURCE_SUPPORT_EQADC_FIFO_CNT)
#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#ifdef RESOURCE_SUPPORT_EQADC_CFIFO_INJECTION
    if ((uint8_t)EQADC_FIFO_6 == u8Adc_CfifoIdx)
    {
        *(EQADC_CFCR[u8Adc_Instance][3U]) &= ~((uint32_t)EQADC_CFCR3_INJ_EN6_MASK);   /* Disable injection of CFIFOx *//* PRQA S 1258 */
    }
    if ((uint8_t)EQADC_FIFO_7 == u8Adc_CfifoIdx)
    {
        *(EQADC_CFCR[u8Adc_Instance][3U]) &= ~((uint32_t)EQADC_CFCR3_INJ_EN7_MASK);   /* Disable injection of CFIFOx *//* PRQA S 1258 */
    }
#endif  /* RESOURCE_SUPPORT_EQADC_CFIFO_INJECTION */
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8 */
#else
    #error "EQADC FIFO COUNT is not defined!"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */

    return eAdc_ret;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_DeinitRedLineClient(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_ClientIdx)
{
    CONSTP2VAR(EQADC_TagType, ADC_CONST, ADC_APPL_CONST) pAdc_BasePtr = Adc_EqadcBase[u8Adc_Instance];
    if (u8Adc_ClientIdx == 0U)
    {
        pAdc_BasePtr->STACCCR.R &= ~(EQADC_STACCCR_SRV1_MASK | EQADC_STACCCR_STACBS1_MASK);/* polyspace RTE:NIV */
    }
    else
    {
        pAdc_BasePtr->STACCCR.R &= ~(EQADC_STACCCR_SRV2_MASK | EQADC_STACCCR_STACBS2_MASK);/* polyspace RTE:NIV */
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_DeinitAdcCtrl(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_AdcIdx, CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx)
{
    if (u8Adc_CfgCmdCfifoIdx == (uint8)EQADC_FIFO_0)
    {
        EQADC_LLD_SetImmediateConvCmdEnDis((EqadcInstanceType)u8Adc_Instance, (EqadcAdcIdxType)u8Adc_AdcIdx, TRUE);
    }

    /* Reset ADCx_CR */
    EQADC_WriteConfigCmdSSE(u8Adc_Instance, u8Adc_CfgCmdCfifoIdx, u8Adc_AdcIdx, EQADC_ADC_REG_CR, (uint16)EQADC_ADC_CR_CLK_PS_MASK);

    /* Reset ADCx_GCCR */
    EQADC_WriteConfigCmdSSE(u8Adc_Instance, u8Adc_CfgCmdCfifoIdx, u8Adc_AdcIdx, EQADC_ADC_REG_GCCR, 0x4000U);

    /* Reset ADCx_OCCR */
    EQADC_WriteConfigCmdSSE(u8Adc_Instance, u8Adc_CfgCmdCfifoIdx, u8Adc_AdcIdx, EQADC_ADC_REG_OCCR, 0x0000U);

    if (u8Adc_CfgCmdCfifoIdx == (uint8)EQADC_FIFO_0)
    {
        EQADC_LLD_SetImmediateConvCmdEnDis((EqadcInstanceType)u8Adc_Instance, (EqadcAdcIdxType)u8Adc_AdcIdx, FALSE);
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_DeinitAdcTimeConfig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx)
{
    /* Reset ADC_TSCR */
    EQADC_WriteConfigCmdSSE(u8Adc_Instance, u8Adc_CfgCmdCfifoIdx, (uint8)EQADC_ADC_0, EQADC_ADC_REG_TSCR, 0x0000U);

    /* Reset ADC_TBCR */
    EQADC_WriteConfigCmdSSE(u8Adc_Instance, u8Adc_CfgCmdCfifoIdx, (uint8)EQADC_ADC_0, EQADC_ADC_REG_TBCR, 0x0000U);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
static FUNC(void, ADC_CODE) EQADC_DeinitAltConfig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(Eqadc_AltConfigSelType, ADC_CONST) eAdc_AltCfgSel, CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx)
{
    VAR(uint8, AUTOMATIC)u8Adc_Index;

    /* Reset ADC_ACRx */
    EQADC_WriteConfigCmdSSE(u8Adc_Instance, u8Adc_CfgCmdCfifoIdx, (uint8)EQADC_ADC_0, EQADC_GetAltConfigRegAddr(eAdc_AltCfgSel), 0x0000U);

    if ((EQADC_ALT_CONFIG_SEL_1 == eAdc_AltCfgSel) || (EQADC_ALT_CONFIG_SEL_2 == eAdc_AltCfgSel))
    {
        VAR(uint8, AUTOMATIC)u8Adc_AltCfgIdx = EQADC_GetAltConfigIdx(eAdc_AltCfgSel);
        for (u8Adc_Index = 0U; u8Adc_Index < EQADC_ADC_NUM; u8Adc_Index++)
        {
            /* Reset ADCx_AGR0/1 */
            EQADC_WriteConfigCmdSSE(u8Adc_Instance, u8Adc_CfgCmdCfifoIdx, u8Adc_Index, AGRxAddr[u8Adc_AltCfgIdx], 0x4000U);

            /* Reset ADCx_AOR0/1 */
            EQADC_WriteConfigCmdSSE(u8Adc_Instance, u8Adc_CfgCmdCfifoIdx, u8Adc_Index, AORxAddr[u8Adc_AltCfgIdx], 0x0000U);
        }
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_GetDefaultCfifoCfg(CONSTP2VAR(Eqadc_CfifoConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_CfifoCfgPtr)
{
    pAdc_CfifoCfgPtr->CfifoIdx       = EQADC_FIFO_0;
    pAdc_CfifoCfgPtr->CfifoMode      = EQADC_CFIFO_MODE_SINGLE_SW_TRIG;
    pAdc_CfifoCfgPtr->IntDmaFillSel  = EQADC_FILL_SEL_INT;
    pAdc_CfifoCfgPtr->DmaMappedChan  = 0U;
    pAdc_CfifoCfgPtr->DmaChanDisReqOnTransComplete  = TRUE;
    pAdc_CfifoCfgPtr->SourcePtr      = NULL;
    pAdc_CfifoCfgPtr->SourceLen      = 0UL;
    pAdc_CfifoCfgPtr->Callback       = NULL;
    pAdc_CfifoCfgPtr->CallbackParam  = NULL;
    pAdc_CfifoCfgPtr->HwTrigSel      = EQADC_HW_TRIG_NOT_CONNECTED;
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
    pAdc_CfifoCfgPtr->CfifoTrigDelayEn  = FALSE;
    pAdc_CfifoCfgPtr->CfifoTrigDelayVal = 0U;
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */

    /* CFIFO0 */
    pAdc_CfifoCfgPtr->Cfifo0EntryExtensionEn = FALSE;
    pAdc_CfifoCfgPtr->Cfifo0AdvanceMode      = EQADC_CFIFO0_AMODE_DISABLE;
    pAdc_CfifoCfgPtr->Cfifo0AdvanceTrigSel   = EQADC_ATRIG_NOT_CONNECTED;

#ifdef RESOURCE_SUPPORT_EQADC_CFIFO_INJECTION
    pAdc_CfifoCfgPtr->CfifoInjectionEn  = FALSE;    /* CFIFO6/CFIFO7 only */
#endif  /* RESOURCE_SUPPORT_EQADC_CFIFO_INJECTION */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_GetDefaultRwConfigCmd(CONSTP2VAR(Eqadc_ConfigCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConfigCmdPtr)
{
    pAdc_ConfigCmdPtr->Eoq           = TRUE;
    pAdc_ConfigCmdPtr->Pause         = FALSE;
    pAdc_ConfigCmdPtr->RepeatStart   = FALSE;
    pAdc_ConfigCmdPtr->cBufNum       = (uint8)EQADC_ADC_0;
    pAdc_ConfigCmdPtr->RwCfgCmdType  = EQADC_CONFIG_CMD_WRITE;
    pAdc_ConfigCmdPtr->AdcRegValue   = 0U;
    pAdc_ConfigCmdPtr->AdcRegAddr    = EQADC_ADC_REG_GCCR;
    pAdc_ConfigCmdPtr->RfifoMsgTag   = EQADC_MSG_TAG_RFIFO0;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_EQADC_CALIBRATION
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_GetDefaultConvCmd(CONSTP2VAR(Eqadc_ConvCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConvCmdPtr)
{
    pAdc_ConvCmdPtr->Eoq             = TRUE;
    pAdc_ConvCmdPtr->Pause           = FALSE;
    pAdc_ConvCmdPtr->RepeatStart     = FALSE;
    pAdc_ConvCmdPtr->cBufNum         = (uint8)EQADC_ADC_0;
    pAdc_ConvCmdPtr->CalibConvResEn  = FALSE;
    pAdc_ConvCmdPtr->RfifoMsgTag     = EQADC_FIFO_0;
    pAdc_ConvCmdPtr->LongSampTime    = EQADC_ADCLK_SAMPLING_CYCLES_128;
    pAdc_ConvCmdPtr->TimeStampReq    = FALSE;
    pAdc_ConvCmdPtr->FormatSignEn    = FALSE;
    pAdc_ConvCmdPtr->ChanNum         = EQADC_CH0;
    pAdc_ConvCmdPtr->AltConfigSel    = EQADC_ALT_CONFIG_DISABLE;
    pAdc_ConvCmdPtr->FlushOrFMT      = FALSE;
#ifdef RESOURCE_SUPPORT_EQADC_CMD_OSR
    pAdc_ConvCmdPtr->OverSampleRate  = EQADC_OVERSAMPLE_DISABLED;
#endif  /* RESOURCE_SUPPORT_EQADC_CMD_OSR */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_CALIBRATION */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(uint32, ADC_CODE) EQADC_GetCfifoRwConfigCmd(CONSTP2CONST(Eqadc_ConfigCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConfigCmdPtr)
{
    VAR(uint32, AUTOMATIC) u32Adc_CfgCmd = 0U;

    /* CFIFO Header */
    u32Adc_CfgCmd  = EQADC_ADC_CMD_EOQ(pAdc_ConfigCmdPtr->Eoq); /* PRQA S 2985 */
    u32Adc_CfgCmd |= EQADC_ADC_CMD_REP(pAdc_ConfigCmdPtr->RepeatStart); /* PRQA S 2985 */
    u32Adc_CfgCmd |= EQADC_ADC_CMD_PAUSE(pAdc_ConfigCmdPtr->Pause); /* PRQA S 2985 */
    /** Reserved bit(0x18000000) **/
    /** EB bit(0x04000000) must be 0 **/

    /* ADC Command */
    EQADC_DET_ERR(pAdc_ConfigCmdPtr->cBufNum < EQADC_ADC_NUM); /* PRQA S 4404  */
    u32Adc_CfgCmd |= EQADC_ADC_CMD_BN(pAdc_ConfigCmdPtr->cBufNum);  /* BN: CBuffer0->ADC0, CBuffer1->ADC1 */

    switch (pAdc_ConfigCmdPtr->RwCfgCmdType)
    {
        case EQADC_CONFIG_CMD_READ:
        {
            u32Adc_CfgCmd |= EQADC_ADC_CMD_RW(EQADC_CONFIG_CMD_READ);
            u32Adc_CfgCmd |= EQADC_ADC_CMD_MESSAGE_TAG(pAdc_ConfigCmdPtr->RfifoMsgTag);
            break;
        }
        case EQADC_CONFIG_CMD_WRITE:
        {
            u32Adc_CfgCmd |= EQADC_ADC_CMD_RW(EQADC_CONFIG_CMD_WRITE); /* PRQA S 2985 */
            u32Adc_CfgCmd |= EQADC_ADC_CMD_REG_HL_BYTE(pAdc_ConfigCmdPtr->AdcRegValue); /* PRQA S 2985 */
            break;
        }
        default:
        {
            EQADC_DET_ERR(FALSE);
            break;
        }
    }

    u32Adc_CfgCmd |= EQADC_ADC_CMD_REG_ADDR(pAdc_ConfigCmdPtr->AdcRegAddr); /* PRQA S 2985 */

    return u32Adc_CfgCmd;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(uint32, ADC_CODE) EQADC_GetCfifoConversionCmd(CONSTP2CONST(Eqadc_ConvCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConvCmdPtr)
{
    VAR(uint32, AUTOMATIC) u32Adc_ConvCmd = 0U;

    /* CFIFO Header */
    u32Adc_ConvCmd  = EQADC_ADC_CMD_EOQ(pAdc_ConvCmdPtr->Eoq); /* PRQA S 2985 */
    u32Adc_ConvCmd |= EQADC_ADC_CMD_PAUSE(pAdc_ConvCmdPtr->Pause); /* PRQA S 2985 */
    u32Adc_ConvCmd |= EQADC_ADC_CMD_REP(pAdc_ConvCmdPtr->RepeatStart); /* PRQA S 2985 */
#ifdef RESOURCE_SUPPORT_EQADC_CMD_OSR
    u32Adc_ConvCmd |= EQADC_ADC_CMD_OSR(pAdc_ConvCmdPtr->OverSampleRate);
#else
    /** Reserved bit(0x18000000) **/
    /** EB bit(0x04000000) must be 0 **/
#endif  /* RESOURCE_SUPPORT_EQADC_CMD_OSR */

    /* ADC Command */
    EQADC_DET_ERR(pAdc_ConvCmdPtr->cBufNum < EQADC_ADC_NUM); /* PRQA S 4404 */
    u32Adc_ConvCmd |= EQADC_ADC_CMD_BN(pAdc_ConvCmdPtr->cBufNum);   /* BN: CBuffer0->ADC0, CBuffer1->ADC1 */
    u32Adc_ConvCmd |= EQADC_ADC_CMD_CAL(pAdc_ConvCmdPtr->CalibConvResEn); /* PRQA S 2985 */
    u32Adc_ConvCmd |= EQADC_ADC_CMD_MESSAGE_TAG(pAdc_ConvCmdPtr->RfifoMsgTag);
    u32Adc_ConvCmd |= EQADC_ADC_CMD_LST(pAdc_ConvCmdPtr->LongSampTime);
    u32Adc_ConvCmd |= EQADC_ADC_CMD_TSR(pAdc_ConvCmdPtr->TimeStampReq); /* PRQA S 2985 */
    u32Adc_ConvCmd |= EQADC_ADC_CMD_CHAN_NUM(pAdc_ConvCmdPtr->ChanNum); /* PRQA S 2985 */

    if (pAdc_ConvCmdPtr->AltConfigSel == EQADC_ALT_CONFIG_DISABLE)
    {
        /* Conversion Command Format for the Standard Configuration */
        u32Adc_ConvCmd |= EQADC_ADC_CMD_FMT(pAdc_ConvCmdPtr->FormatSignEn); /* PRQA S 2985 */
    }
    else
    {
        /* Conversion Command Format for Alternate Configurations */
        u32Adc_ConvCmd |= EQADC_ADC_CMD_ALT_CFG_SEL(pAdc_ConvCmdPtr->AltConfigSel); /* PRQA S 2985 */
        u32Adc_ConvCmd |= EQADC_ADC_CMD_FFMT(pAdc_ConvCmdPtr->FlushOrFMT); /* PRQA S 2985 */
    }

    return u32Adc_ConvCmd;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_SetAdcConfig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONSTP2CONST(Eqadc_AdcConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_AdcConfig, CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx)
{
#if EQADC_DET_SUPPORT
    /* ADC CLK DET */
#endif
    VAR(uint16, AUTOMATIC) u16Adc_AdcCrVal = 0U, u16Adc_AdcGccrVal = 0U, u16Adc_AdcOccrVal = 0U;

    /* Get ADCxCR Config */
    u16Adc_AdcCrVal = EQADC_ADC_CR_EN_MASK;
    u16Adc_AdcCrVal = (uint16)(u16Adc_AdcCrVal | ((pAdc_AdcConfig->AdcExtMuxEn == TRUE) ? EQADC_ADC_CR_EMUX_MASK : 0U));/* polyspace RTE:IDP */

#ifdef RESOURCE_SUPPORT_EQADC_CFG_PRECHARGE
    u16Adc_AdcCrVal |= EQADC_ADC_CR_PRC_SEL(pAdc_AdcConfig->PrechargeClkCycleSel);
#endif  /* RESOURCE_SUPPORT_EQADC_CFG_PRECHARGE */

#ifdef RESOURCE_SUPPORT_EQADC_CFG_AUTO_SHIFT
    u16Adc_AdcCrVal |= EQADC_ADC_CR_SHIFT_MASK;
#endif  /* RESOURCE_SUPPORT_EQADC_CFG_AUTO_SHIFT */

    EQADC_DET_ERR((uint8)(pAdc_AdcConfig->TimeBaseSel) <= (uint8)EQADC_TBS_STACCCR_SRV2); /* PRQA S 4404 */
    u16Adc_AdcCrVal |= EQADC_ADC_CR_TBSEL(pAdc_AdcConfig->TimeBaseSel);

    if (pAdc_AdcConfig->ClkSel == EQADC_CLK_SEL_PS_DIV)
    {
        u16Adc_AdcCrVal |= EQADC_ADC_CR_CLK_PS(pAdc_AdcConfig->ClkPrescale); /* PRQA S 2985 */
    }
#ifdef EQADC_ADC_CR_CLK_SEL_EN
    else
    {
        /* EQADC_CLK_SEL_MAX_FREQ */
        u16Adc_AdcCrVal |= EQADC_ADC_CR_CLK_SEL_MASK;
    }
#endif  /* EQADC_ADC_CR_CLK_SEL_EN */

    /* Get ADCxGCCR Config */
    u16Adc_AdcGccrVal = (pAdc_AdcConfig->AdcGainCalibConst & EQADC_ADC_GCCR_GCC_MASK);

    /* Get ADCxOCCR Config */
    u16Adc_AdcOccrVal = (uint16)(pAdc_AdcConfig->AdcOffsetCalibConst);

    /* En/Dis Immediate ConvCmd */
    EQADC_LLD_SetImmediateConvCmdEnDis((EqadcInstanceType)u8Adc_Instance, pAdc_AdcConfig->AdcIdx, pAdc_AdcConfig->ImmediateConvCmdEn);

    /* Set ADCxCR/ADCxGCCR/ADCxOCCR Config */
    EQADC_WriteConfigCmdSSE(u8Adc_Instance, u8Adc_CfgCmdCfifoIdx, (uint8)pAdc_AdcConfig->AdcIdx, EQADC_ADC_REG_CR, u16Adc_AdcCrVal);
    EQADC_WriteConfigCmdSSE(u8Adc_Instance, u8Adc_CfgCmdCfifoIdx, (uint8)pAdc_AdcConfig->AdcIdx, EQADC_ADC_REG_GCCR, u16Adc_AdcGccrVal);
    EQADC_WriteConfigCmdSSE(u8Adc_Instance, u8Adc_CfgCmdCfifoIdx, (uint8)pAdc_AdcConfig->AdcIdx, EQADC_ADC_REG_OCCR, u16Adc_AdcOccrVal);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_SetAltConfig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONSTP2CONST(Eqadc_AlternateConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_AltConfig, CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx)
{
    VAR(uint16, AUTOMATIC) u16Adc_AdcAcrVal = 0U;
    VAR(uint8, AUTOMATIC) u8Adc_Index;

    /* Get ADC ACRx Config */
    u16Adc_AdcAcrVal = (pAdc_AltConfig->ResultTransInhibit == TRUE) ? EQADC_ADC_ACR_RET_INH_MASK : 0U;
    u16Adc_AdcAcrVal |= EQADC_ADC_ACR_DEST(pAdc_AltConfig->AltConvResultDEST);
    u16Adc_AdcAcrVal = (uint16)(u16Adc_AdcAcrVal | ((pAdc_AltConfig->FMTA_SignEn == TRUE) ? EQADC_ADC_ACR_FMTA_MASK : 0U));
    u16Adc_AdcAcrVal |= EQADC_ADC_ACR_RESSEL(pAdc_AltConfig->AdcResSel);
#ifdef EQADC_ADC_ACR_PRE_GAIN_EN
    u16Adc_AdcAcrVal |= EQADC_ADC_ACR_PRE_GAIN(pAdc_AltConfig->AdcPreGain); /* PRQA S 2985 */
#endif  /* EQADC_ADC_ACR_PRE_GAIN_EN */

    /* Set ADC ACRx Config */
    EQADC_WriteConfigCmdSSE(u8Adc_Instance, u8Adc_CfgCmdCfifoIdx, (uint8)EQADC_ADC_0, EQADC_GetAltConfigRegAddr(pAdc_AltConfig->AltConfigSel), u16Adc_AdcAcrVal);

    if ((EQADC_ALT_CONFIG_SEL_1 == pAdc_AltConfig->AltConfigSel) || (EQADC_ALT_CONFIG_SEL_2 == pAdc_AltConfig->AltConfigSel))
    {
        VAR(uint8, AUTOMATIC)AltCfgIdx = EQADC_GetAltConfigIdx(pAdc_AltConfig->AltConfigSel);
        for (u8Adc_Index = 0U; u8Adc_Index < EQADC_ADC_NUM; u8Adc_Index++)
        {
            /* Set ADC AGRx Config */
            EQADC_WriteConfigCmdSSE(u8Adc_Instance, u8Adc_CfgCmdCfifoIdx, u8Adc_Index, AGRxAddr[AltCfgIdx], pAdc_AltConfig->AdcAltGain[u8Adc_Index]);

            /* Set ADC AORx Config */
            EQADC_WriteConfigCmdSSE(u8Adc_Instance, u8Adc_CfgCmdCfifoIdx, u8Adc_Index, AORxAddr[AltCfgIdx], pAdc_AltConfig->AdcAltOffset[u8Adc_Index]);
        }
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_SetRedLineClientConfig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONSTP2CONST(Eqadc_RedLineClientConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_RedLineClientCfg)
{
    EQADC_REDLCCR_SetREDBS_SRVx(u8Adc_Instance, pAdc_RedLineClientCfg->clientIdx, (uint8)(pAdc_RedLineClientCfg->TimeBaseBitsSel), (uint8)(pAdc_RedLineClientCfg->SRVnSel));
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */

/*******************************************************************************
 * @brief EQADC CFIFO Control Register x (EQADC_CFCRx: MODEy)
 *          (x = 0...2, y = 0...5) / (x = 0...3, y = 0...7).
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_CfifoIdx: CFIFO Index (Index = y)
 *        u32Adc_CfifoModeTarget: Set the target mode for CFIFO
 *
 * @note  If MODEy is not disabled, it must not be changed to any other mode
 *          besides disabled. If MODEy is disabled and the CFIFO status is IDLE,
 *          MODEy can be changed to any other mode.
 *******************************************************************************/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) EQADC_CFCRxSetMode(CONST(uint8, ADC_CONST) u8Adc_Instance, CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, CONST(uint32, ADC_CONST) u32Adc_CfifoModeTarget)
{
    VAR(uint8, AUTOMATIC) u8Adc_CFCRx = u8Adc_CfifoIdx / 2U;  /* EQADC CFIFO Control Register x */
    if((u8Adc_Instance < ADC_EQADC_MAX_INSTANCE) && (u8Adc_CFCRx < EQADC_CFCR_U32_REG_COUNT))
    {
        if ((u8Adc_CfifoIdx % 2U) == 0U)
        {   /* EQADC CfifoIdx: 0/2/4/6 */
            *(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) &= ~EQADC_CFCR0_MODE0_MASK;/* polyspace RTE:NIV,IDP */
            *(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) |= EQADC_CFCR0_MODE0(u32Adc_CfifoModeTarget);/* polyspace RTE:NIV,IDP */
        }
        else
        {   /* EQADC CfifoIdx: 1/3/5/7 */
            *(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) &= ~EQADC_CFCR0_MODE1_MASK;/* polyspace RTE:NIV,IDP */
            *(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) |= EQADC_CFCR0_MODE1(u32Adc_CfifoModeTarget);/* polyspace RTE:NIV,IDP */
        }
    }
    
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(status_t, ADC_CODE) EQADC_SetCfifoConfig(CONST(uint8, ADC_CONST) u8Adc_Instance, CONSTP2CONST(Eqadc_CfifoConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_CfifoCfgPtr)
{
    VAR(uint32, AUTOMATIC) u32Adc_Timeout;
    VAR(status_t, AUTOMATIC) eAdc_ret = STATUS_SUCCESS;

    /* 1.Disabled CFIFO mode. */
    EQADC_CFCRxSetMode(u8Adc_Instance, (uint8)(pAdc_CfifoCfgPtr->CfifoIdx), (uint32)EQADC_CFIFO_MODE_DISABLE);

    /* 2.Waiting for the IDLE status of CFIFO */
    u32Adc_Timeout = EQADC_TIMEOUT_COUNT;
    while ((EQADC_LLD_GetCFifoStatus((EqadcInstanceType)u8Adc_Instance, pAdc_CfifoCfgPtr->CfifoIdx) \
        != EQADC_CFIFO_STATUS_IDLE) && (u32Adc_Timeout > 0UL))
    {
        u32Adc_Timeout--;
    }

    if (0UL == u32Adc_Timeout)
    {
        eAdc_ret = STATUS_TIMEOUT;
    }

#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
    /* CFIFO Trigger Delay */
    EQADC_LLD_SetCfifoTrigDelay((EqadcInstanceType)u8Adc_Instance, (EqadcFifoIdxType)(pAdc_CfifoCfgPtr->CfifoIdx), pAdc_CfifoCfgPtr->CfifoTrigDelayEn, pAdc_CfifoCfgPtr->CfifoTrigDelayVal);
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */

    /* 3.Set CFIFO other mode. */
    EQADC_CFCRxSetMode(u8Adc_Instance, (uint8)(pAdc_CfifoCfgPtr->CfifoIdx), (uint32)(pAdc_CfifoCfgPtr->CfifoMode));

    if (EQADC_FILL_SEL_INT == pAdc_CfifoCfgPtr->IntDmaFillSel)
    {
        EQADC_IDCRx_FifoIntDmaEnDis(u8Adc_Instance, (uint8)(pAdc_CfifoCfgPtr->CfifoIdx), EQADC_IRQDMA_REQ_SEL_CFIFOFILL, FALSE);
        EQADC_LLD_IntEnDis((EqadcInstanceType)u8Adc_Instance, pAdc_CfifoCfgPtr->CfifoIdx, EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL, FALSE);
    }
    else
    {
#ifdef RESOURCE_SUPPORT_EQADC_FIFO_DMA_CTRL_SEL
        if (pAdc_CfifoCfgPtr->DmaMappedChan < EDMA_CHN64_NUMBER)
        {
            EQADC_LLD_CfifoDmaControllerSelect((EqadcInstanceType)u8Adc_Instance, pAdc_CfifoCfgPtr->CfifoIdx, EQADC_FIFO_SEL_DMA_0);
        }
        else
        {
            EQADC_LLD_CfifoDmaControllerSelect((EqadcInstanceType)u8Adc_Instance, pAdc_CfifoCfgPtr->CfifoIdx, EQADC_FIFO_SEL_DMA_1);
        }
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_DMA_CTRL_SEL */
        EQADC_SetDmaForCmd(u8Adc_Instance, pAdc_CfifoCfgPtr);
        EQADC_IDCRx_FifoIntDmaEnDis(u8Adc_Instance, (uint8)(pAdc_CfifoCfgPtr->CfifoIdx), EQADC_IRQDMA_REQ_SEL_CFIFOFILL, TRUE);
        EQADC_LLD_DmaEnDis((EqadcInstanceType)u8Adc_Instance, pAdc_CfifoCfgPtr->CfifoIdx, EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL, TRUE);
    }

    if (EQADC_FIFO_0 == pAdc_CfifoCfgPtr->CfifoIdx)
    {
        /* CFIFO0 Entry Number Extension Enable */
        EQADC_CFCR0_SetCfifo0EntryExtEnDis(u8Adc_Instance, pAdc_CfifoCfgPtr->Cfifo0EntryExtensionEn);

        /* Set CFIFO0 Advance Trigger Operation Mode: disable mode */
        EQADC_CFCR0_SetAMode0(u8Adc_Instance, (uint8)EQADC_CFIFO0_AMODE_DISABLE);

        if (pAdc_CfifoCfgPtr->Cfifo0AdvanceMode != EQADC_CFIFO0_AMODE_DISABLE)
        {
            EQADC_DET_ERR((pAdc_CfifoCfgPtr->CfifoMode >= \
                    EQADC_CFIFO_MODE_SINGLE_LOW_LVL_GATED_EXT_TRIG) && /* PRQA S 4404 */ \
                    (pAdc_CfifoCfgPtr->CfifoMode <= EQADC_CFIFO_MODE_SINGLE_BOTH_EDGES_EXT_TRIG));
            EQADC_DET_ERR((pAdc_CfifoCfgPtr->Cfifo0AdvanceMode != EQADC_CFIFO0_AMODE_SINGLE_SW_TRIG) || /* PRQA S 4404 */ \
                    (pAdc_CfifoCfgPtr->Cfifo0AdvanceTrigSel == EQADC_ATRIG_NOT_CONNECTED));

            /* Set CFIFO0 Advance Trigger Operation Mode */
            EQADC_CFCR0_SetAMode0(u8Adc_Instance, (uint8)(pAdc_CfifoCfgPtr->Cfifo0AdvanceMode));
            /* CFIFO0 Streaming Mode Operation Enable */
            EQADC_CFCR0_Cfifo0StreamModeEnDis(u8Adc_Instance, TRUE);
        }
        else
        {
            /* CFIFO0 Streaming Mode Operation Disable */
            EQADC_CFCR0_Cfifo0StreamModeEnDis(u8Adc_Instance, FALSE);
        }
    }

#if defined(RESOURCE_SUPPORT_EQADC_FIFO_CNT)
#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#ifdef RESOURCE_SUPPORT_EQADC_CFIFO_INJECTION
    if (EQADC_FIFO_6 == pAdc_CfifoCfgPtr->CfifoIdx)
    {
        if (TRUE == pAdc_CfifoCfgPtr->CfifoInjectionEn)
        {
            *(EQADC_CFCR[u8Adc_Instance][3U]) |= ((uint32_t)EQADC_CFCR3_INJ_EN6_MASK);    /* Enable injection of CFIFOx *//* PRQA S 1258 */
        }
        else
        {
            *(EQADC_CFCR[u8Adc_Instance][3U]) &= ~((uint32_t)EQADC_CFCR3_INJ_EN6_MASK);   /* Disable injection of CFIFOx *//* PRQA S 1258 */
        }
    }
    if (EQADC_FIFO_7 == pAdc_CfifoCfgPtr->CfifoIdx)
    {
        if (TRUE == pAdc_CfifoCfgPtr->CfifoInjectionEn)
        {
            *(EQADC_CFCR[u8Adc_Instance][3U]) |= ((uint32_t)EQADC_CFCR3_INJ_EN7_MASK);    /* Enable injection of CFIFOx *//* PRQA S 1258 */
        }
        else
        {
            *(EQADC_CFCR[u8Adc_Instance][3U]) &= ~((uint32_t)EQADC_CFCR3_INJ_EN7_MASK);   /* Disable injection of CFIFOx *//* PRQA S 1258 */
        }
    }
#endif  /* RESOURCE_SUPPORT_EQADC_CFIFO_INJECTION */
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8 */
#else
    #error "EQADC FIFO COUNT is not defined!"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */

    return eAdc_ret;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_SetDmaForCmd(CONST(uint8, ADC_CONST) u8Adc_Instance, CONSTP2CONST(Eqadc_CfifoConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_CfifoCfgPtr)
{
    VAR(uint8, AUTOMATIC) u8Adc_Cfifo_x = (uint8)(pAdc_CfifoCfgPtr->CfifoIdx);
    VAR(uint32, AUTOMATIC) u32Adc_srcSizeLast = sizeof(pAdc_CfifoCfgPtr->SourcePtr[0U]) * pAdc_CfifoCfgPtr->SourceLen;
#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC) u8Adc_ret = (Std_ReturnType)E_OK;
#endif  /* ADC_DEM_REPORT_ERROR_ENABLE */

    if((u8Adc_Instance < ADC_EQADC_MAX_INSTANCE) && (u8Adc_Cfifo_x < EQADC_CFIFO_COUNT))
    {
        DmaMappedChanForCmd[u8Adc_Instance][u8Adc_Cfifo_x] = pAdc_CfifoCfgPtr->DmaMappedChan;

        eDMATransferConfigType TcdCfg   = tcdcfg;
        static eDMALoopTransferConfigType LoopTcdCfg = {0U};
        LoopTcdCfg = looptcdcfg;
        TcdCfg.srcAddr                  = (uint32)pAdc_CfifoCfgPtr->SourcePtr;
        TcdCfg.destAddr                 = (uint32)(EQADC_CFPR[u8Adc_Instance][u8Adc_Cfifo_x]);
        TcdCfg.srcTransDataSize         = EDMA_TRANSFER_SIZE_4B;
        TcdCfg.destTransDataSize        = EDMA_TRANSFER_SIZE_4B;
        TcdCfg.srcAddrOffset            = (sint16)sizeof(pAdc_CfifoCfgPtr->SourcePtr[0U]);
        TcdCfg.srcAddrAdjustLast        = -(sint32)u32Adc_srcSizeLast;
        TcdCfg.minorTransByte           = sizeof(pAdc_CfifoCfgPtr->SourcePtr[0U]);
        TcdCfg.lpTransConfigPtr         = &LoopTcdCfg;

        LoopTcdCfg.majorLpIterCnt       = pAdc_CfifoCfgPtr->SourceLen;

#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
        u8Adc_ret = EDMA_SetLoopTransferConfig(pAdc_CfifoCfgPtr->DmaMappedChan, &TcdCfg);
        if(u8Adc_ret != (Std_ReturnType)E_OK)
        {
            Adc_DemReportErrorStatus(DME_EVENTID_INIT, DEM_EVENT_TIMEOUT);
        }
#else
        (void) EDMA_SetLoopTransferConfig(pAdc_CfifoCfgPtr->DmaMappedChan, &TcdCfg);
#endif  /* ADC_DEM_REPORT_ERROR_ENABLE */

        /* EQADC DMA channel: Disable request.
         *  TRUE  - The DMA channel's ERQ bit is cleared when the major loop is complete.
         *  FALSE - The DMA channel's ERQ bit is not affected. */
        EDMA_SetChnDisRequestsOnTransferComplete(pAdc_CfifoCfgPtr->DmaMappedChan, \
                ((pAdc_CfifoCfgPtr->DmaChanDisReqOnTransComplete == FALSE) ? FALSE : TRUE));

        if (pAdc_CfifoCfgPtr->Callback != NULL)
        {
            (void) EDMA_SetUpCallback(pAdc_CfifoCfgPtr->DmaMappedChan, pAdc_CfifoCfgPtr->Callback, pAdc_CfifoCfgPtr->CallbackParam);

            EDMA_SetInterruptConfig(pAdc_CfifoCfgPtr->DmaMappedChan, EDMA_CHN_ENABLE_ERROR_INT, TRUE);
            EDMA_SetInterruptConfig(pAdc_CfifoCfgPtr->DmaMappedChan, EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT, FALSE);
            EDMA_SetInterruptConfig(pAdc_CfifoCfgPtr->DmaMappedChan, EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, TRUE);
        }
        else
        {
            EDMA_SetInterruptConfig(pAdc_CfifoCfgPtr->DmaMappedChan, EDMA_CHN_ENABLE_ERROR_INT, FALSE);
            EDMA_SetInterruptConfig(pAdc_CfifoCfgPtr->DmaMappedChan, EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT, FALSE);
            EDMA_SetInterruptConfig(pAdc_CfifoCfgPtr->DmaMappedChan, EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, FALSE);
        }
        /* The start of the DMA channel is outside the EQADC low-level driver */
    }
#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
    else
    {
        Adc_DemReportErrorStatus(DME_EVENTID_INIT, DEM_EVENT_TIMEOUT);
    }
#endif  /* ADC_DEM_REPORT_ERROR_ENABLE */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) EQADC_SetDmaForResult(CONST(uint8, ADC_CONST) u8Adc_Instance, CONSTP2CONST(Eqadc_ResultDmaConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_RfifoCfgPtr)
{
    VAR(uint8, AUTOMATIC) u8Adc_Rfifo_x = (uint8)(pAdc_RfifoCfgPtr->RfifoIdx);
    VAR(uint32, AUTOMATIC) u32Adc_destSizeLast = sizeof(pAdc_RfifoCfgPtr->DestPtr[0U]) * pAdc_RfifoCfgPtr->DestLen;
#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC) u8Adc_ret = (Std_ReturnType)E_OK;
#endif  /* ADC_DEM_REPORT_ERROR_ENABLE */

    if((u8Adc_Instance < ADC_EQADC_MAX_INSTANCE) && (u8Adc_Rfifo_x < EQADC_RFIFO_COUNT))
    {
        DmaMappedChanForResult[u8Adc_Instance][u8Adc_Rfifo_x] = pAdc_RfifoCfgPtr->ResultDmaMappedChan;

        eDMATransferConfigType TcdCfg   = tcdcfg;
        static eDMALoopTransferConfigType LoopTcdCfg = {0U};
        LoopTcdCfg = looptcdcfg;
        TcdCfg.srcAddr                  = (uint32)(EQADC_RFPR[ u8Adc_Instance][u8Adc_Rfifo_x]) + 2U;
        TcdCfg.destAddr                 = (uint32)pAdc_RfifoCfgPtr->DestPtr;
        TcdCfg.srcTransDataSize         = EDMA_TRANSFER_SIZE_2B;
        TcdCfg.destTransDataSize        = EDMA_TRANSFER_SIZE_2B;
        TcdCfg.destAddrOffset           = (sint16)sizeof(pAdc_RfifoCfgPtr->DestPtr[0U]);
        TcdCfg.destAddrAdjustLast       = -(sint32)u32Adc_destSizeLast;
        TcdCfg.minorTransByte           = sizeof(pAdc_RfifoCfgPtr->DestPtr[0U]);
        TcdCfg.lpTransConfigPtr         = &LoopTcdCfg;

        LoopTcdCfg.majorLpIterCnt       = pAdc_RfifoCfgPtr->DestLen;

#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
        u8Adc_ret = EDMA_SetLoopTransferConfig(pAdc_RfifoCfgPtr->ResultDmaMappedChan, &TcdCfg);
        if(u8Adc_ret != (Std_ReturnType)E_OK)
        {
            Adc_DemReportErrorStatus(DME_EVENTID_INIT, DEM_EVENT_TIMEOUT);
        }
#else
        (void) EDMA_SetLoopTransferConfig(pAdc_RfifoCfgPtr->ResultDmaMappedChan, &TcdCfg);
#endif  /* ADC_DEM_REPORT_ERROR_ENABLE */

        if (pAdc_RfifoCfgPtr->Callback != NULL)
        {
            (void) EDMA_SetUpCallback(pAdc_RfifoCfgPtr->ResultDmaMappedChan, pAdc_RfifoCfgPtr->Callback, pAdc_RfifoCfgPtr->CallbackParam);

            EDMA_SetInterruptConfig(pAdc_RfifoCfgPtr->ResultDmaMappedChan, EDMA_CHN_ENABLE_ERROR_INT, TRUE);
            if (pAdc_RfifoCfgPtr->EnHalfDestCallback == TRUE)
            {
                EDMA_SetInterruptConfig(pAdc_RfifoCfgPtr->ResultDmaMappedChan, EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT, TRUE);
            }
            else
            {
                EDMA_SetInterruptConfig(pAdc_RfifoCfgPtr->ResultDmaMappedChan, EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT, FALSE);
            }
            EDMA_SetInterruptConfig(pAdc_RfifoCfgPtr->ResultDmaMappedChan, EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, TRUE);
        }
        else
        {
            EDMA_SetInterruptConfig(pAdc_RfifoCfgPtr->ResultDmaMappedChan, EDMA_CHN_ENABLE_ERROR_INT, FALSE);
            EDMA_SetInterruptConfig(pAdc_RfifoCfgPtr->ResultDmaMappedChan, EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT, FALSE);
            EDMA_SetInterruptConfig(pAdc_RfifoCfgPtr->ResultDmaMappedChan, EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, FALSE);
        }

        (void) EDMA_SetChannelRequest(pAdc_RfifoCfgPtr->ResultDmaMappedChan);
    }
#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
    else
    {
        Adc_DemReportErrorStatus(DME_EVENTID_INIT, DEM_EVENT_TIMEOUT);
    }
#endif  /* ADC_DEM_REPORT_ERROR_ENABLE */
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

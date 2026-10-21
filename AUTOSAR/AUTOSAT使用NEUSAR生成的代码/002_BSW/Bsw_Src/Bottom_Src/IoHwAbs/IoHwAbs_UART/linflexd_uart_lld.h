/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx linflexed uart low level drivers h file
* HISTORY     : Initial version
* @file     linflexed_uart_lld.h
* @version  1.0
* @date     2023 - 08 - 17
* @brief    Initial version.
*
*****************************************************************************/

#ifndef LLD_INC_LINFLEXD_UART_LLD_H_
#define LLD_INC_LINFLEXD_UART_LLD_H_
/*PRQA S 1534,3472 EOF*/
#include "typedefs.h"
#include "intc_lld.h"
#include "status.h"

typedef volatile uint8_t semaphore_t;

typedef  struct LINFlexD_tag                   LINFlexD_Type;

/*!
 * @brief Define the enum of the events which can trigger UART callback
 *
 * This enum should include the events for all platforms
 *
 * Implements : uart_event_t_Class
 */
typedef enum
{
    UART_EVENT_RX_FULL      = 0x00U,    /*!< Rx buffer is full */
    UART_EVENT_TX_EMPTY     = 0x01U,    /*!< Tx buffer is empty */
    UART_EVENT_END_TRANSFER = 0x02U,    /*!< The current transfer is ending */
    UART_EVENT_ERROR        = 0x03U,    /*!< An error occured during transfer */
} uart_event_t;
/*!
 * @brief Callback for all peripherals which support UART features
 *
 * Implements : uart_callback_t_Class
 */
typedef void (*uart_callback_t)(void *driverState, uart_event_t event, void *userData);


/*! @brief Device instance number */
typedef enum
{
	INST_LINFLEXD_UART0,
	INST_LINFLEXD_UART1,
	INST_LINFLEXD_UART2,
#if defined RESOURCE_SUPPORT_LINFLEXD_3
	INST_LINFLEXD_UART3,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_4
	INST_LINFLEXD_UART4,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_5
	INST_LINFLEXD_UART5,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_6
	INST_LINFLEXD_UART6,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_7
	INST_LINFLEXD_UART7,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_8
	INST_LINFLEXD_UART8,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_9
	INST_LINFLEXD_UART9,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_10
	INST_LINFLEXD_UART10,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_11
	INST_LINFLEXD_UART11,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_12
	INST_LINFLEXD_UART12,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_14
	INST_LINFLEXD_UART14,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_15
	INST_LINFLEXD_UART15,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_16
	INST_LINFLEXD_UART16,
#endif
}eUartModuleId; /* PRQA S 1535 */

/** Array initializer of LINFlexD peripheral base pointers */
static volatile LINFlexD_Type * const s_LINFlexDBase[LINFLEXD_MAX] =   { /* PRQA S 3228 */
        &LINFlexD_0,
        &LINFlexD_1,
        &LINFlexD_2,
    #if defined RESOURCE_SUPPORT_LINFLEXD_3
        &LINFlexD_3,
    #endif
    #if defined RESOURCE_SUPPORT_LINFLEXD_4
        &LINFlexD_4,
    #endif
    #if defined RESOURCE_SUPPORT_LINFLEXD_5
        &LINFlexD_5,
    #endif
    #if defined RESOURCE_SUPPORT_LINFLEXD_6
        &LINFlexD_6,
    #endif
    #if defined RESOURCE_SUPPORT_LINFLEXD_7
        &LINFlexD_7,
    #endif
    #if defined RESOURCE_SUPPORT_LINFLEXD_8
        &LINFlexD_8,
    #endif
    #if defined RESOURCE_SUPPORT_LINFLEXD_9
        &LINFlexD_9,
    #endif
    #if defined RESOURCE_SUPPORT_LINFLEXD_10
        &LINFlexD_10,
    #endif
    #if defined RESOURCE_SUPPORT_LINFLEXD_11
        &LINFlexD_11,
    #endif
    #if defined RESOURCE_SUPPORT_LINFLEXD_12
        &LINFlexD_12,
    #endif
    #if defined RESOURCE_SUPPORT_LINFLEXD_14
        &LINFlexD_14,
    #endif
    #if defined RESOURCE_SUPPORT_LINFLEXD_15
        &LINFlexD_15,
    #endif
    #if defined RESOURCE_SUPPORT_LINFLEXD_16
        &LINFlexD_16
    #endif
    };

static const boolean s_LINFlexDInstHasDma[LINFLEXD_MAX] =  {/* PRQA S 3218 */
    TRUE,
    TRUE,
    TRUE,
#if defined RESOURCE_SUPPORT_LINFLEXD_3
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_4
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_5
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_6
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_7
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_8
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_9
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_10
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_11
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_12
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_14
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_15
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_16
    TRUE
#endif
};

static const IntrId LINFLEXD_RX_IRQS[LINFLEXD_MAX] = {
    LINFLEXD0_RX_IRQn,
    LINFLEXD1_RX_IRQn,
    LINFLEXD2_RX_IRQn,
#if defined RESOURCE_SUPPORT_LINFLEXD_3
    LINFLEXD3_RX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_4
    LINFLEXD4_RX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_5
    LINFLEXD5_RX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_6
    LINFLEXD6_RX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_7
    LINFLEXD7_RX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_8
    LINFLEXD8_RX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_9
    LINFLEXD9_RX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_10
    LINFLEXD10_RX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_11
    LINFLEXD11_RX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_12
    LINFLEXD12_RX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_14
    LINFLEXD14_RX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_15
    LINFLEXD15_RX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_16
    LINFLEXD16_RX_IRQn
#endif
};

static const IntrId LINFLEXD_TX_IRQS[LINFLEXD_MAX] = {
    LINFLEXD0_TX_IRQn,
    LINFLEXD1_TX_IRQn,
    LINFLEXD2_TX_IRQn,
#if defined RESOURCE_SUPPORT_LINFLEXD_3
    LINFLEXD3_TX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_4
    LINFLEXD4_TX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_5
    LINFLEXD5_TX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_6
    LINFLEXD6_TX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_7
    LINFLEXD7_TX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_8
    LINFLEXD8_TX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_9
    LINFLEXD9_TX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_10
    LINFLEXD10_TX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_11
    LINFLEXD11_TX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_12
    LINFLEXD12_TX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_14
    LINFLEXD14_TX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_15
    LINFLEXD15_TX_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_16
    LINFLEXD16_TX_IRQn,
#endif
};

static const IntrId LINFLEXD_ERR_IRQS[LINFLEXD_MAX] = {
    LINFLEXD0_ERR_IRQn,
    LINFLEXD1_ERR_IRQn,
    LINFLEXD2_ERR_IRQn,
#if defined RESOURCE_SUPPORT_LINFLEXD_3
    LINFLEXD3_ERR_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_4
    LINFLEXD4_ERR_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_5
    LINFLEXD5_ERR_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_6
    LINFLEXD6_ERR_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_7
    LINFLEXD7_ERR_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_8
    LINFLEXD8_ERR_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_9
    LINFLEXD9_ERR_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_10
    LINFLEXD10_ERR_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_11
    LINFLEXD11_ERR_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_12
    LINFLEXD12_ERR_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_14
    LINFLEXD14_ERR_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_15
    LINFLEXD15_ERR_IRQn,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_16
    LINFLEXD16_ERR_IRQn,
#endif
};

static const boolean FEATURE_LINFLEXD_INST_HAS_IFCR[LINFLEXD_MAX] = {
    TRUE,
    TRUE,
    TRUE,
#if defined RESOURCE_SUPPORT_LINFLEXD_3
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_4
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_5
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_6
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_7
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_8
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_9
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_10
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_11
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_12
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_14
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_15
    TRUE,
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_16
    TRUE,
#endif
};

#define FEATURE_LINFLEXD_HAS_DMA_ENABLED 1U
/* ----------------------------------------------------------------------------
  -- LINFlexD Register Masks
  ---------------------------------------------------------------------------- */
/* LINCR1 Bit Fields */
#define LINFlexD_LINCR1_INIT_MASK                0x1u
#define LINFlexD_LINCR1_INIT_SHIFT               0u
#define LINFlexD_LINCR1_INIT_WIDTH               1u
#define LINFlexD_LINCR1_INIT(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINCR1_INIT_SHIFT))&LINFlexD_LINCR1_INIT_MASK)
#define LINFlexD_LINCR1_SLEEP_MASK               0x2u
#define LINFlexD_LINCR1_SLEEP_SHIFT              1u
#define LINFlexD_LINCR1_SLEEP_WIDTH              1u
#define LINFlexD_LINCR1_SLEEP(x)                 (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINCR1_SLEEP_SHIFT))&LINFlexD_LINCR1_SLEEP_MASK)
#define LINFlexD_LINCR1_RBLM_MASK                0x4u
#define LINFlexD_LINCR1_RBLM_SHIFT               2u
#define LINFlexD_LINCR1_RBLM_WIDTH               1u
#define LINFlexD_LINCR1_RBLM(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINCR1_RBLM_SHIFT))&LINFlexD_LINCR1_RBLM_MASK)
#define LINFlexD_LINCR1_SSBL_MASK                0x8u
#define LINFlexD_LINCR1_SSBL_SHIFT               3u
#define LINFlexD_LINCR1_SSBL_WIDTH               1u
#define LINFlexD_LINCR1_SSBL(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINCR1_SSBL_SHIFT))&LINFlexD_LINCR1_SSBL_MASK)
#define LINFlexD_LINCR1_MME_MASK                 0x10u
#define LINFlexD_LINCR1_MME_SHIFT                4u
#define LINFlexD_LINCR1_MME_WIDTH                1u
#define LINFlexD_LINCR1_MME(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINCR1_MME_SHIFT))&LINFlexD_LINCR1_MME_MASK)
#define LINFlexD_LINCR1_LBKM_MASK                0x20u
#define LINFlexD_LINCR1_LBKM_SHIFT               5u
#define LINFlexD_LINCR1_LBKM_WIDTH               1u
#define LINFlexD_LINCR1_LBKM(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINCR1_LBKM_SHIFT))&LINFlexD_LINCR1_LBKM_MASK)
#define LINFlexD_LINCR1_BF_MASK                  0x80u
#define LINFlexD_LINCR1_BF_SHIFT                 7u
#define LINFlexD_LINCR1_BF_WIDTH                 1u
#define LINFlexD_LINCR1_BF(x)                    (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINCR1_BF_SHIFT))&LINFlexD_LINCR1_BF_MASK)
#define LINFlexD_LINCR1_MBL_MASK                 0xF00u
#define LINFlexD_LINCR1_MBL_SHIFT                8u
#define LINFlexD_LINCR1_MBL_WIDTH                4u
#define LINFlexD_LINCR1_MBL(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINCR1_MBL_SHIFT))&LINFlexD_LINCR1_MBL_MASK)
#define LINFlexD_LINCR1_AUTOWU_MASK              0x1000u
#define LINFlexD_LINCR1_AUTOWU_SHIFT             12u
#define LINFlexD_LINCR1_AUTOWU_WIDTH             1u
#define LINFlexD_LINCR1_AUTOWU(x)                (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINCR1_AUTOWU_SHIFT))&LINFlexD_LINCR1_AUTOWU_MASK)
#define LINFlexD_LINCR1_LASE_MASK                0x2000u
#define LINFlexD_LINCR1_LASE_SHIFT               13u
#define LINFlexD_LINCR1_LASE_WIDTH               1u
#define LINFlexD_LINCR1_LASE(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINCR1_LASE_SHIFT))&LINFlexD_LINCR1_LASE_MASK)
#define LINFlexD_LINCR1_CFD_MASK                 0x4000u
#define LINFlexD_LINCR1_CFD_SHIFT                14u
#define LINFlexD_LINCR1_CFD_WIDTH                1u
#define LINFlexD_LINCR1_CFD(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINCR1_CFD_SHIFT))&LINFlexD_LINCR1_CFD_MASK)
#define LINFlexD_LINCR1_CCD_MASK                 0x8000u
#define LINFlexD_LINCR1_CCD_SHIFT                15u
#define LINFlexD_LINCR1_CCD_WIDTH                1u
#define LINFlexD_LINCR1_CCD(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINCR1_CCD_SHIFT))&LINFlexD_LINCR1_CCD_MASK)
/* BIDR Bit Fields */
#define LINFlexD_BIDR_ID_MASK                    0x3Fu
#define LINFlexD_BIDR_ID_SHIFT                   0u
#define LINFlexD_BIDR_ID_WIDTH                   6u
#define LINFlexD_BIDR_ID(x)                      (((uint32_t)(((uint32_t)(x))<<LINFlexD_BIDR_ID_SHIFT))&LINFlexD_BIDR_ID_MASK)
#define LINFlexD_BIDR_CCS_MASK                   0x100u
#define LINFlexD_BIDR_CCS_SHIFT                  8u
#define LINFlexD_BIDR_CCS_WIDTH                  1u
#define LINFlexD_BIDR_CCS(x)                     (((uint32_t)(((uint32_t)(x))<<LINFlexD_BIDR_CCS_SHIFT))&LINFlexD_BIDR_CCS_MASK)
#define LINFlexD_BIDR_DIR_MASK                   0x200u
#define LINFlexD_BIDR_DIR_SHIFT                  9u
#define LINFlexD_BIDR_DIR_WIDTH                  1u
#define LINFlexD_BIDR_DIR(x)                     (((uint32_t)(((uint32_t)(x))<<LINFlexD_BIDR_DIR_SHIFT))&LINFlexD_BIDR_DIR_MASK)
#define LINFlexD_BIDR_DFL_MASK                   0x1C00u
#define LINFlexD_BIDR_DFL_SHIFT                  10u
#define LINFlexD_BIDR_DFL_WIDTH                  3u
#define LINFlexD_BIDR_DFL(x)                     (((uint32_t)(((uint32_t)(x))<<LINFlexD_BIDR_DFL_SHIFT))&LINFlexD_BIDR_DFL_MASK)
/* BDRL Bit Fields */
#define LINFlexD_BDRL_DATA0_MASK                 0xFFu
#define LINFlexD_BDRL_DATA0_SHIFT                0u
#define LINFlexD_BDRL_DATA0_WIDTH                8u
#define LINFlexD_BDRL_DATA0(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_BDRL_DATA0_SHIFT))&LINFlexD_BDRL_DATA0_MASK)
#define LINFlexD_BDRL_DATA1_MASK                 0xFF00u
#define LINFlexD_BDRL_DATA1_SHIFT                8u
#define LINFlexD_BDRL_DATA1_WIDTH                8u
#define LINFlexD_BDRL_DATA1(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_BDRL_DATA1_SHIFT))&LINFlexD_BDRL_DATA1_MASK)
#define LINFlexD_BDRL_DATA2_MASK                 0xFF0000u
#define LINFlexD_BDRL_DATA2_SHIFT                16u
#define LINFlexD_BDRL_DATA2_WIDTH                8u
#define LINFlexD_BDRL_DATA2(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_BDRL_DATA2_SHIFT))&LINFlexD_BDRL_DATA2_MASK)
#define LINFlexD_BDRL_DATA3_MASK                 0xFF000000u
#define LINFlexD_BDRL_DATA3_SHIFT                24u
#define LINFlexD_BDRL_DATA3_WIDTH                8u
#define LINFlexD_BDRL_DATA3(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_BDRL_DATA3_SHIFT))&LINFlexD_BDRL_DATA3_MASK)
/* BDRM Bit Fields */
#define LINFlexD_BDRM_DATA4_MASK                 0xFFu
#define LINFlexD_BDRM_DATA4_SHIFT                0u
#define LINFlexD_BDRM_DATA4_WIDTH                8u
#define LINFlexD_BDRM_DATA4(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_BDRM_DATA4_SHIFT))&LINFlexD_BDRM_DATA4_MASK)
#define LINFlexD_BDRM_DATA5_MASK                 0xFF00u
#define LINFlexD_BDRM_DATA5_SHIFT                8u
#define LINFlexD_BDRM_DATA5_WIDTH                8u
#define LINFlexD_BDRM_DATA5(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_BDRM_DATA5_SHIFT))&LINFlexD_BDRM_DATA5_MASK)
#define LINFlexD_BDRM_DATA6_MASK                 0xFF0000u
#define LINFlexD_BDRM_DATA6_SHIFT                16u
#define LINFlexD_BDRM_DATA6_WIDTH                8u
#define LINFlexD_BDRM_DATA6(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_BDRM_DATA6_SHIFT))&LINFlexD_BDRM_DATA6_MASK)
#define LINFlexD_BDRM_DATA7_MASK                 0xFF000000u
#define LINFlexD_BDRM_DATA7_SHIFT                24u
#define LINFlexD_BDRM_DATA7_WIDTH                8u
#define LINFlexD_BDRM_DATA7(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_BDRM_DATA7_SHIFT))&LINFlexD_BDRM_DATA7_MASK)
/* LINIER Bit Fields */
#define LINFlexD_LINIER_HRIE_MASK                0x1u
#define LINFlexD_LINIER_HRIE_SHIFT               0u
#define LINFlexD_LINIER_HRIE_WIDTH               1u
#define LINFlexD_LINIER_HRIE(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINIER_HRIE_SHIFT))&LINFlexD_LINIER_HRIE_MASK)
#define LINFlexD_LINIER_DTIE_MASK                0x2u
#define LINFlexD_LINIER_DTIE_SHIFT               1u
#define LINFlexD_LINIER_DTIE_WIDTH               1u
#define LINFlexD_LINIER_DTIE(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINIER_DTIE_SHIFT))&LINFlexD_LINIER_DTIE_MASK)
#define LINFlexD_LINIER_DRIE_MASK                0x4u
#define LINFlexD_LINIER_DRIE_SHIFT               2u
#define LINFlexD_LINIER_DRIE_WIDTH               1u
#define LINFlexD_LINIER_DRIE(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINIER_DRIE_SHIFT))&LINFlexD_LINIER_DRIE_MASK)
#define LINFlexD_LINIER_TOIE_MASK                0x8u
#define LINFlexD_LINIER_TOIE_SHIFT               3u
#define LINFlexD_LINIER_TOIE_WIDTH               1u
#define LINFlexD_LINIER_TOIE(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINIER_TOIE_SHIFT))&LINFlexD_LINIER_TOIE_MASK)
#define LINFlexD_LINIER_WUIE_MASK                0x20u
#define LINFlexD_LINIER_WUIE_SHIFT               5u
#define LINFlexD_LINIER_WUIE_WIDTH               1u
#define LINFlexD_LINIER_WUIE(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINIER_WUIE_SHIFT))&LINFlexD_LINIER_WUIE_MASK)
#define LINFlexD_LINIER_LSIE_MASK                0x40u
#define LINFlexD_LINIER_LSIE_SHIFT               6u
#define LINFlexD_LINIER_LSIE_WIDTH               1u
#define LINFlexD_LINIER_LSIE(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINIER_LSIE_SHIFT))&LINFlexD_LINIER_LSIE_MASK)
#define LINFlexD_LINIER_BOIE_MASK                0x80u
#define LINFlexD_LINIER_BOIE_SHIFT               7u
#define LINFlexD_LINIER_BOIE_WIDTH               1u
#define LINFlexD_LINIER_BOIE(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINIER_BOIE_SHIFT))&LINFlexD_LINIER_BOIE_MASK)
#define LINFlexD_LINIER_FEIE_MASK                0x100u
#define LINFlexD_LINIER_FEIE_SHIFT               8u
#define LINFlexD_LINIER_FEIE_WIDTH               1u
#define LINFlexD_LINIER_FEIE(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINIER_FEIE_SHIFT))&LINFlexD_LINIER_FEIE_MASK)
#define LINFlexD_LINIER_HEIE_MASK                0x800u
#define LINFlexD_LINIER_HEIE_SHIFT               11u
#define LINFlexD_LINIER_HEIE_WIDTH               1u
#define LINFlexD_LINIER_HEIE(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINIER_HEIE_SHIFT))&LINFlexD_LINIER_HEIE_MASK)
#define LINFlexD_LINIER_CEIE_MASK                0x1000u
#define LINFlexD_LINIER_CEIE_SHIFT               12u
#define LINFlexD_LINIER_CEIE_WIDTH               1u
#define LINFlexD_LINIER_CEIE(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINIER_CEIE_SHIFT))&LINFlexD_LINIER_CEIE_MASK)
#define LINFlexD_LINIER_BEIE_MASK                0x2000u
#define LINFlexD_LINIER_BEIE_SHIFT               13u
#define LINFlexD_LINIER_BEIE_WIDTH               1u
#define LINFlexD_LINIER_BEIE(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINIER_BEIE_SHIFT))&LINFlexD_LINIER_BEIE_MASK)
#define LINFlexD_LINIER_OCIE_MASK                0x4000u
#define LINFlexD_LINIER_OCIE_SHIFT               14u
#define LINFlexD_LINIER_OCIE_WIDTH               1u
#define LINFlexD_LINIER_OCIE(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINIER_OCIE_SHIFT))&LINFlexD_LINIER_OCIE_MASK)
#define LINFlexD_LINIER_SZIE_MASK                0x8000u
#define LINFlexD_LINIER_SZIE_SHIFT               15u
#define LINFlexD_LINIER_SZIE_WIDTH               1u
#define LINFlexD_LINIER_SZIE(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINIER_SZIE_SHIFT))&LINFlexD_LINIER_SZIE_MASK)
/* UARTCR Bit Fields */
#define LINFlexD_UARTCR_UART_MASK                0x1u
#define LINFlexD_UARTCR_UART_SHIFT               0u
#define LINFlexD_UARTCR_UART_WIDTH               1u
#define LINFlexD_UARTCR_UART(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_UART_SHIFT))&LINFlexD_UARTCR_UART_MASK)
#define LINFlexD_UARTCR_WL0_MASK                 0x2u
#define LINFlexD_UARTCR_WL0_SHIFT                1u
#define LINFlexD_UARTCR_WL0_WIDTH                1u
#define LINFlexD_UARTCR_WL0(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_WL0_SHIFT))&LINFlexD_UARTCR_WL0_MASK)
#define LINFlexD_UARTCR_PCE_MASK                 0x4u
#define LINFlexD_UARTCR_PCE_SHIFT                2u
#define LINFlexD_UARTCR_PCE_WIDTH                1u
#define LINFlexD_UARTCR_PCE(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_PCE_SHIFT))&LINFlexD_UARTCR_PCE_MASK)
#define LINFlexD_UARTCR_PC0_MASK                 0x8u
#define LINFlexD_UARTCR_PC0_SHIFT                3u
#define LINFlexD_UARTCR_PC0_WIDTH                1u
#define LINFlexD_UARTCR_PC0(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_PC0_SHIFT))&LINFlexD_UARTCR_PC0_MASK)
#define LINFlexD_UARTCR_TxEn_MASK                0x10u
#define LINFlexD_UARTCR_TxEn_SHIFT               4u
#define LINFlexD_UARTCR_TxEn_WIDTH               1u
#define LINFlexD_UARTCR_TxEn(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_TxEn_SHIFT))&LINFlexD_UARTCR_TxEn_MASK)
#define LINFlexD_UARTCR_RxEn_MASK                0x20u
#define LINFlexD_UARTCR_RxEn_SHIFT               5u
#define LINFlexD_UARTCR_RxEn_WIDTH               1u
#define LINFlexD_UARTCR_RxEn(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_RxEn_SHIFT))&LINFlexD_UARTCR_RxEn_MASK)
#define LINFlexD_UARTCR_PC1_MASK                 0x40u
#define LINFlexD_UARTCR_PC1_SHIFT                6u
#define LINFlexD_UARTCR_PC1_WIDTH                1u
#define LINFlexD_UARTCR_PC1(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_PC1_SHIFT))&LINFlexD_UARTCR_PC1_MASK)
#define LINFlexD_UARTCR_WL1_MASK                 0x80u
#define LINFlexD_UARTCR_WL1_SHIFT                7u
#define LINFlexD_UARTCR_WL1_WIDTH                1u
#define LINFlexD_UARTCR_WL1(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_WL1_SHIFT))&LINFlexD_UARTCR_WL1_MASK)
#define LINFlexD_UARTCR_TFBM_MASK                0x100u
#define LINFlexD_UARTCR_TFBM_SHIFT               8u
#define LINFlexD_UARTCR_TFBM_WIDTH               1u
#define LINFlexD_UARTCR_TFBM(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_TFBM_SHIFT))&LINFlexD_UARTCR_TFBM_MASK)
#define LINFlexD_UARTCR_RFBM_MASK                0x200u
#define LINFlexD_UARTCR_RFBM_SHIFT               9u
#define LINFlexD_UARTCR_RFBM_WIDTH               1u
#define LINFlexD_UARTCR_RFBM(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_RFBM_SHIFT))&LINFlexD_UARTCR_RFBM_MASK)
#define LINFlexD_UARTCR_RDFL_RFC_MASK            0x1C00u
#define LINFlexD_UARTCR_RDFL_RFC_SHIFT           10u
#define LINFlexD_UARTCR_RDFL_RFC_WIDTH           3u
#define LINFlexD_UARTCR_RDFL_RFC(x)              (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_RDFL_RFC_SHIFT))&LINFlexD_UARTCR_RDFL_RFC_MASK)
#define LINFlexD_UARTCR_TDFL_TFC_MASK            0xE000u
#define LINFlexD_UARTCR_TDFL_TFC_SHIFT           13u
#define LINFlexD_UARTCR_TDFL_TFC_WIDTH           3u
#define LINFlexD_UARTCR_TDFL_TFC(x)              (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_TDFL_TFC_SHIFT))&LINFlexD_UARTCR_TDFL_TFC_MASK)
#define LINFlexD_UARTCR_WLS_MASK                 0x10000u
#define LINFlexD_UARTCR_WLS_SHIFT                16u
#define LINFlexD_UARTCR_WLS_WIDTH                1u
#define LINFlexD_UARTCR_WLS(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_WLS_SHIFT))&LINFlexD_UARTCR_WLS_MASK)
#define LINFlexD_UARTCR_SBUR_MASK                0x60000u
#define LINFlexD_UARTCR_SBUR_SHIFT               17u
#define LINFlexD_UARTCR_SBUR_WIDTH               2u
#define LINFlexD_UARTCR_SBUR(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_SBUR_SHIFT))&LINFlexD_UARTCR_SBUR_MASK)
#define LINFlexD_UARTCR_DTU_PCETX_MASK           0x80000u
#define LINFlexD_UARTCR_DTU_PCETX_SHIFT          19u
#define LINFlexD_UARTCR_DTU_PCETX_WIDTH          1u
#define LINFlexD_UARTCR_DTU_PCETX(x)             (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_DTU_PCETX_SHIFT))&LINFlexD_UARTCR_DTU_PCETX_MASK)
#define LINFlexD_UARTCR_NEF_MASK                 0x700000u
#define LINFlexD_UARTCR_NEF_SHIFT                20u
#define LINFlexD_UARTCR_NEF_WIDTH                3u
#define LINFlexD_UARTCR_NEF(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_NEF_SHIFT))&LINFlexD_UARTCR_NEF_MASK)
#define LINFlexD_UARTCR_ROSE_MASK                0x800000u
#define LINFlexD_UARTCR_ROSE_SHIFT               23u
#define LINFlexD_UARTCR_ROSE_WIDTH               1u
#define LINFlexD_UARTCR_ROSE(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_ROSE_SHIFT))&LINFlexD_UARTCR_ROSE_MASK)
#define LINFlexD_UARTCR_OSR_MASK                 0xF000000u
#define LINFlexD_UARTCR_OSR_SHIFT                24u
#define LINFlexD_UARTCR_OSR_WIDTH                4u
#define LINFlexD_UARTCR_OSR(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_OSR_SHIFT))&LINFlexD_UARTCR_OSR_MASK)
#define LINFlexD_UARTCR_CSP_MASK                 0x70000000u
#define LINFlexD_UARTCR_CSP_SHIFT                28u
#define LINFlexD_UARTCR_CSP_WIDTH                3u
#define LINFlexD_UARTCR_CSP(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_CSP_SHIFT))&LINFlexD_UARTCR_CSP_MASK)
#define LINFlexD_UARTCR_MIS_MASK                 0x80000000u
#define LINFlexD_UARTCR_MIS_SHIFT                31u
#define LINFlexD_UARTCR_MIS_WIDTH                1u
#define LINFlexD_UARTCR_MIS(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTCR_MIS_SHIFT))&LINFlexD_UARTCR_MIS_MASK)
/* UARTSR Bit Fields */
#define LINFlexD_UARTSR_NF_MASK                  0x1u
#define LINFlexD_UARTSR_NF_SHIFT                 0u
#define LINFlexD_UARTSR_NF_WIDTH                 1u
#define LINFlexD_UARTSR_NF(x)                    (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTSR_NF_SHIFT))&LINFlexD_UARTSR_NF_MASK)
#define LINFlexD_UARTSR_DTFTFF_MASK              0x2u
#define LINFlexD_UARTSR_DTFTFF_SHIFT             1u
#define LINFlexD_UARTSR_DTFTFF_WIDTH             1u
#define LINFlexD_UARTSR_DTFTFF(x)                (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTSR_DTFTFF_SHIFT))&LINFlexD_UARTSR_DTFTFF_MASK)
#define LINFlexD_UARTSR_DRFRFE_MASK              0x4u
#define LINFlexD_UARTSR_DRFRFE_SHIFT             2u
#define LINFlexD_UARTSR_DRFRFE_WIDTH             1u
#define LINFlexD_UARTSR_DRFRFE(x)                (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTSR_DRFRFE_SHIFT))&LINFlexD_UARTSR_DRFRFE_MASK)
#define LINFlexD_UARTSR_TO_MASK                  0x8u
#define LINFlexD_UARTSR_TO_SHIFT                 3u
#define LINFlexD_UARTSR_TO_WIDTH                 1u
#define LINFlexD_UARTSR_TO(x)                    (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTSR_TO_SHIFT))&LINFlexD_UARTSR_TO_MASK)
#define LINFlexD_UARTSR_RFNE_MASK                0x10u
#define LINFlexD_UARTSR_RFNE_SHIFT               4u
#define LINFlexD_UARTSR_RFNE_WIDTH               1u
#define LINFlexD_UARTSR_RFNE(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTSR_RFNE_SHIFT))&LINFlexD_UARTSR_RFNE_MASK)
#define LINFlexD_UARTSR_WUF_MASK                 0x20u
#define LINFlexD_UARTSR_WUF_SHIFT                5u
#define LINFlexD_UARTSR_WUF_WIDTH                1u
#define LINFlexD_UARTSR_WUF(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTSR_WUF_SHIFT))&LINFlexD_UARTSR_WUF_MASK)
#define LINFlexD_UARTSR_RDI_MASK                 0x40u
#define LINFlexD_UARTSR_RDI_SHIFT                6u
#define LINFlexD_UARTSR_RDI_WIDTH                1u
#define LINFlexD_UARTSR_RDI(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTSR_RDI_SHIFT))&LINFlexD_UARTSR_RDI_MASK)
#define LINFlexD_UARTSR_BOF_MASK                 0x80u
#define LINFlexD_UARTSR_BOF_SHIFT                7u
#define LINFlexD_UARTSR_BOF_WIDTH                1u
#define LINFlexD_UARTSR_BOF(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTSR_BOF_SHIFT))&LINFlexD_UARTSR_BOF_MASK)
#define LINFlexD_UARTSR_FEF_MASK                 0x100u
#define LINFlexD_UARTSR_FEF_SHIFT                8u
#define LINFlexD_UARTSR_FEF_WIDTH                1u
#define LINFlexD_UARTSR_FEF(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTSR_FEF_SHIFT))&LINFlexD_UARTSR_FEF_MASK)
#define LINFlexD_UARTSR_RMB_MASK                 0x200u
#define LINFlexD_UARTSR_RMB_SHIFT                9u
#define LINFlexD_UARTSR_RMB_WIDTH                1u
#define LINFlexD_UARTSR_RMB(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTSR_RMB_SHIFT))&LINFlexD_UARTSR_RMB_MASK)
#define LINFlexD_UARTSR_PE_MASK                  0x3C00u
#define LINFlexD_UARTSR_PE_SHIFT                 10u
#define LINFlexD_UARTSR_PE_WIDTH                 4u
#define LINFlexD_UARTSR_PE(x)                    (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTSR_PE_SHIFT))&LINFlexD_UARTSR_PE_MASK)
#define LINFlexD_UARTSR_OCF_MASK                 0x4000u
#define LINFlexD_UARTSR_OCF_SHIFT                14u
#define LINFlexD_UARTSR_OCF_WIDTH                1u
#define LINFlexD_UARTSR_OCF(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTSR_OCF_SHIFT))&LINFlexD_UARTSR_OCF_MASK)
#define LINFlexD_UARTSR_SZF_MASK                 0x8000u
#define LINFlexD_UARTSR_SZF_SHIFT                15u
#define LINFlexD_UARTSR_SZF_WIDTH                1u
#define LINFlexD_UARTSR_SZF(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_UARTSR_SZF_SHIFT))&LINFlexD_UARTSR_SZF_MASK)
/* LINFBRR Bit Fields */
#define LINFlexD_LINFBRR_FBR_MASK                0xFu
#define LINFlexD_LINFBRR_FBR_SHIFT               0u
#define LINFlexD_LINFBRR_FBR_WIDTH               4u
#define LINFlexD_LINFBRR_FBR(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINFBRR_FBR_SHIFT))&LINFlexD_LINFBRR_FBR_MASK)
/* LINIBRR Bit Fields */
#define LINFlexD_LINIBRR_IBR_MASK                0xFFFFFu
#define LINFlexD_LINIBRR_IBR_SHIFT               0u
#define LINFlexD_LINIBRR_IBR_WIDTH               20u
#define LINFlexD_LINIBRR_IBR(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINIBRR_IBR_SHIFT))&LINFlexD_LINIBRR_IBR_MASK)

/* LINSR Bit Fields */
#define LINFlexD_LINSR_HRF_MASK                  0x1u
#define LINFlexD_LINSR_HRF_SHIFT                 0u
#define LINFlexD_LINSR_HRF_WIDTH                 1u
#define LINFlexD_LINSR_HRF(x)                    (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINSR_HRF_SHIFT))&LINFlexD_LINSR_HRF_MASK)
#define LINFlexD_LINSR_DTF_MASK                  0x2u
#define LINFlexD_LINSR_DTF_SHIFT                 1u
#define LINFlexD_LINSR_DTF_WIDTH                 1u
#define LINFlexD_LINSR_DTF(x)                    (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINSR_DTF_SHIFT))&LINFlexD_LINSR_DTF_MASK)
#define LINFlexD_LINSR_DRF_MASK                  0x4u
#define LINFlexD_LINSR_DRF_SHIFT                 2u
#define LINFlexD_LINSR_DRF_WIDTH                 1u
#define LINFlexD_LINSR_DRF(x)                    (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINSR_DRF_SHIFT))&LINFlexD_LINSR_DRF_MASK)
#define LINFlexD_LINSR_WUF_MASK                  0x20u
#define LINFlexD_LINSR_WUF_SHIFT                 5u
#define LINFlexD_LINSR_WUF_WIDTH                 1u
#define LINFlexD_LINSR_WUF(x)                    (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINSR_WUF_SHIFT))&LINFlexD_LINSR_WUF_MASK)
#define LINFlexD_LINSR_RDI_MASK                  0x40u
#define LINFlexD_LINSR_RDI_SHIFT                 6u
#define LINFlexD_LINSR_RDI_WIDTH                 1u
#define LINFlexD_LINSR_RDI(x)                    (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINSR_RDI_SHIFT))&LINFlexD_LINSR_RDI_MASK)
#define LINFlexD_LINSR_RXbusy_MASK               0x80u
#define LINFlexD_LINSR_RXbusy_SHIFT              7u
#define LINFlexD_LINSR_RXbusy_WIDTH              1u
#define LINFlexD_LINSR_RXbusy(x)                 (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINSR_RXbusy_SHIFT))&LINFlexD_LINSR_RXbusy_MASK)
#define LINFlexD_LINSR_DRBNE_MASK                0x100u
#define LINFlexD_LINSR_DRBNE_SHIFT               8u
#define LINFlexD_LINSR_DRBNE_WIDTH               1u
#define LINFlexD_LINSR_DRBNE(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINSR_DRBNE_SHIFT))&LINFlexD_LINSR_DRBNE_MASK)
#define LINFlexD_LINSR_RMB_MASK                  0x200u
#define LINFlexD_LINSR_RMB_SHIFT                 9u
#define LINFlexD_LINSR_RMB_WIDTH                 1u
#define LINFlexD_LINSR_RMB(x)                    (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINSR_RMB_SHIFT))&LINFlexD_LINSR_RMB_MASK)
#define LINFlexD_LINSR_LINS_MASK                 0xF000u
#define LINFlexD_LINSR_LINS_SHIFT                12u
#define LINFlexD_LINSR_LINS_WIDTH                4u
#define LINFlexD_LINSR_LINS(x)                   (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINSR_LINS_SHIFT))&LINFlexD_LINSR_LINS_MASK)
#define LINFlexD_LINSR_RDC_MASK                  0x70000u
#define LINFlexD_LINSR_RDC_SHIFT                 16u
#define LINFlexD_LINSR_RDC_WIDTH                 3u
#define LINFlexD_LINSR_RDC(x)                    (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINSR_RDC_SHIFT))&LINFlexD_LINSR_RDC_MASK)
#define LINFlexD_LINSR_AUTOSYNC_COMP_MASK        0x80000u
#define LINFlexD_LINSR_AUTOSYNC_COMP_SHIFT       19u
#define LINFlexD_LINSR_AUTOSYNC_COMP_WIDTH       1u
#define LINFlexD_LINSR_AUTOSYNC_COMP(x)          (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINSR_AUTOSYNC_COMP_SHIFT))&LINFlexD_LINSR_AUTOSYNC_COMP_MASK)
/* GCR Bit Fields */
#define LINFlexD_GCR_SR_MASK                     0x1u
#define LINFlexD_GCR_SR_SHIFT                    0u
#define LINFlexD_GCR_SR_WIDTH                    1u
#define LINFlexD_GCR_SR(x)                       (((uint32_t)(((uint32_t)(x))<<LINFlexD_GCR_SR_SHIFT))&LINFlexD_GCR_SR_MASK)
#define LINFlexD_GCR_STOP_MASK                   0x2u
#define LINFlexD_GCR_STOP_SHIFT                  1u
#define LINFlexD_GCR_STOP_WIDTH                  1u
#define LINFlexD_GCR_STOP(x)                     (((uint32_t)(((uint32_t)(x))<<LINFlexD_GCR_STOP_SHIFT))&LINFlexD_GCR_STOP_MASK)
#define LINFlexD_GCR_RDLIS_MASK                  0x4u
#define LINFlexD_GCR_RDLIS_SHIFT                 2u
#define LINFlexD_GCR_RDLIS_WIDTH                 1u
#define LINFlexD_GCR_RDLIS(x)                    (((uint32_t)(((uint32_t)(x))<<LINFlexD_GCR_RDLIS_SHIFT))&LINFlexD_GCR_RDLIS_MASK)
#define LINFlexD_GCR_TDLIS_MASK                  0x8u
#define LINFlexD_GCR_TDLIS_SHIFT                 3u
#define LINFlexD_GCR_TDLIS_WIDTH                 1u
#define LINFlexD_GCR_TDLIS(x)                    (((uint32_t)(((uint32_t)(x))<<LINFlexD_GCR_TDLIS_SHIFT))&LINFlexD_GCR_TDLIS_MASK)
#define LINFlexD_GCR_RDFBM_MASK                  0x10u
#define LINFlexD_GCR_RDFBM_SHIFT                 4u
#define LINFlexD_GCR_RDFBM_WIDTH                 1u
#define LINFlexD_GCR_RDFBM(x)                    (((uint32_t)(((uint32_t)(x))<<LINFlexD_GCR_RDFBM_SHIFT))&LINFlexD_GCR_RDFBM_MASK)
#define LINFlexD_GCR_TDFBM_MASK                  0x20u
#define LINFlexD_GCR_TDFBM_SHIFT                 5u
#define LINFlexD_GCR_TDFBM_WIDTH                 1u
#define LINFlexD_GCR_TDFBM(x)                    (((uint32_t)(((uint32_t)(x))<<LINFlexD_GCR_TDFBM_SHIFT))&LINFlexD_GCR_TDFBM_MASK)

/*!
 * @addtogroup linflexd_uart
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEFAULT_OSR              16U
#define BAUDRATE_FRACTION_WIDTH  LINFlexD_LINFBRR_FBR_WIDTH

/*! @brief LINFlexD mode: UART/LIN. */
typedef enum
{
    LINFlexD_LIN_MODE = 0U,
    LINFlexD_UART_MODE = 1U
} linflexd_mode_t;

/*! @brief UART Mode: FIFO/BUFFER. */
typedef enum
{
    LINFLEXD_UART_RXTX_BUFFER_MODE = 0U,
    LINFLEXD_UART_RXTX_FIFO_MODE = 1U
} linflexd_uart_rxtx_mode_t;

/*! @brief LINFlexD state. */
typedef enum
{
    LINFlexD_STATE_SLEEP_MODE = 0U,
    LINFlexD_STATE_INIT_MODE = 1U,
    LINFlexD_STATE_IDLE_MODE = 2U,
    LINFlexD_STATE_SYNC_BREAK = 3U,
    LINFlexD_STATE_SYNC_DEL = 4U,
    LINFlexD_STATE_SYNC_FIELD = 5U,
    LINFlexD_STATE_IDENTIFIER_FIELD = 6U,
    LINFlexD_STATE_HEADER_RX_TX = 7U,
    LINFlexD_STATE_DATA_RX_TX = 8U,
    LINFlexD_STATE_CHECKSUM = 9U
} linflexd_state_t;

/*! @brief UART Status flags.
 *  These identifiers provide both mask and shift for status bits in UARTSR register.
 */
typedef enum
{
    LINFlexD_UART_NOISE_FLAG                   = LINFlexD_UARTSR_NF_MASK,
    LINFlexD_UART_DATA_TRANSMITTED_FLAG        = LINFlexD_UARTSR_DTFTFF_MASK,
    LINFlexD_UART_DATA_RECEPTION_COMPLETE_FLAG = LINFlexD_UARTSR_DRFRFE_MASK,
    LINFlexD_UART_TIMEOUT_FLAG                 = LINFlexD_UARTSR_TO_MASK,
    LINFlexD_UART_WAKEUP_FLAG                  = LINFlexD_UARTSR_WUF_MASK,
    LINFlexD_UART_RECEIVER_INPUT_STATE_FLAG    = LINFlexD_UARTSR_RDI_MASK,
    LINFlexD_UART_BUFFER_OVERRUN_FLAG          = LINFlexD_UARTSR_BOF_MASK,
    LINFlexD_UART_FRAME_ERROR_FLAG             = LINFlexD_UARTSR_FEF_MASK,
    LINFlexD_UART_MESSAGE_BUFFER_FULL_FLAG     = LINFlexD_UARTSR_RMB_MASK,
    LINFlexD_UART_PARITY_ERROR_FLAG            = LINFlexD_UARTSR_PE_MASK,
    LINFlexD_UART_OUTPUT_COMPARE_FLAG          = LINFlexD_UARTSR_OCF_MASK,
    LINFlexD_UART_STUCK_AT_ZERO_FLAG           = LINFlexD_UARTSR_SZF_MASK
} linflexd_uart_status_flag_t;

/*! @brief LINFlexD interrupts.
 *  These identifiers provide both mask and shift for the interrupt enable bits in LINIER register.
 */
typedef enum
{
    LINFlexD_HEADER_RECEIVED_INT         = LINFlexD_LINIER_HRIE_MASK,
    LINFlexD_DATA_TRANSMITTED_INT        = LINFlexD_LINIER_DTIE_MASK,
    LINFlexD_DATA_RECEPTION_COMPLETE_INT = LINFlexD_LINIER_DRIE_MASK,
    LINFlexD_UART_TIMEOUT_ERROR_INT      = LINFlexD_LINIER_TOIE_MASK,
    LINFlexD_WAKEUP_INT                  = LINFlexD_LINIER_WUIE_MASK,
    LINFlexD_LIN_STATE_INT               = LINFlexD_LINIER_LSIE_MASK,
    LINFlexD_BUFFER_OVERRUN_INT          = LINFlexD_LINIER_BOIE_MASK,
    LINFlexD_FRAME_ERROR_INT             = LINFlexD_LINIER_FEIE_MASK,
    LINFlexD_HEADER_ERROR_INT            = LINFlexD_LINIER_HEIE_MASK,
    LINFlexD_CHECKSUM_ERROR_INT          = LINFlexD_LINIER_CEIE_MASK,
    LINFlexD_BIT_ERROR_INT               = LINFlexD_LINIER_BEIE_MASK,
    LINFlexD_OUTPUT_COMPARE_INT          = LINFlexD_LINIER_OCIE_MASK,
    LINFlexD_STUCK_AT_ZERO_INT           = LINFlexD_LINIER_SZIE_MASK
} linflexd_interrupt_t;

/*! @brief Word length in UART mode.
 *
 * Implements : linflexd_uart_word_length_t_Class
 */
typedef enum
{
    LINFLEXD_UART_7_BITS = 0U,
    LINFLEXD_UART_8_BITS = 1U,
    LINFLEXD_UART_15_BITS = 2U,
    LINFLEXD_UART_16_BITS = 3U
} linflexd_uart_word_length_t;

/*! @brief Number of stop bits.
 *
 * Implements : linflexd_uart_stop_bits_count_t_Class
 */
typedef enum
{
    LINFLEXD_UART_ONE_STOP_BIT = 0U,
    LINFLEXD_UART_TWO_STOP_BIT = 1U
} linflexd_uart_stop_bits_count_t;

/*! @brief Parity type.
 *
 * Implements : linflexd_uart_parity_type_t_Class
 */
typedef enum
{
    LINFLEXD_UART_PARITY_EVEN = 0U,
    LINFLEXD_UART_PARITY_ODD = 1U,
    LINFLEXD_UART_PARITY_ZERO = 2U,
    LINFLEXD_UART_PARITY_ONE = 3U
} linflexd_uart_parity_type_t;

/*! @brief Type of UART transfer (based on interrupts or DMA).
 *
 * Implements : linflexd_uart_transfer_type_t_Class
 */
typedef enum
{
    LINFLEXD_UART_USING_DMA         = 0U,    /*!< The driver will use DMA to perform UART transfer */
    LINFLEXD_UART_USING_INTERRUPTS  = 1U     /*!< The driver will use interrupts to perform UART transfer */
} linflexd_uart_transfer_type_t;

/*! @brief UART state structure
 *
 * Implements : linflexd_uart_state_t_Class
 */
typedef struct
{
    const uint8_t * txBuff;                      /*!< The buffer of data being sent.*/
    uint8_t * rxBuff;                            /*!< The buffer of received data.*/
    volatile uint32_t txSize;                    /*!< The remaining number of bytes to be transmitted. */
    volatile uint32_t rxSize;                    /*!< The remaining number of bytes to be received. */
    volatile boolean isTxBusy;                      /*!< True if there is an active transmit.*/
    volatile boolean isRxBusy;                      /*!< True if there is an active receive.*/
    volatile boolean isTxBlocking;                  /*!< True if transmit is blocking transaction. */
    volatile boolean isRxBlocking;                  /*!< True if receive is blocking transaction. */
    uart_callback_t rxCallback;                  /*!< Callback to invoke for data receive */
    void * rxCallbackParam;                      /*!< Receive callback parameter pointer.*/
    uart_callback_t txCallback;                  /*!< Callback to invoke for data send */
    void * txCallbackParam;                      /*!< Transmit callback parameter pointer.*/
    uart_callback_t errorCallback;               /*!< Callback to invoke on error conditions */
    void * errorCallbackParam;                   /*!< Error callback parameter pointer */
    linflexd_uart_word_length_t wordLength;      /*!< Word length (8/16 bits) */
    semaphore_t rxComplete;                      /*!< Synchronization object for blocking Rx timeout condition */
    semaphore_t txComplete;                      /*!< Synchronization object for blocking Tx timeout condition */
    linflexd_uart_transfer_type_t transferType;  /*!< Type of UART transfer (interrupt/dma based) */
#if defined(FEATURE_LINFLEXD_HAS_DMA_ENABLED)
    uint8_t rxDMAChannel;                        /*!< DMA channel number for DMA-based rx. */
    uint8_t txDMAChannel;                        /*!< DMA channel number for DMA-based tx. */
    uint8_t txLinkDMAChannel;					 /*!< DMA channel number for DMA-link  tx. */
#endif
    volatile status_t transmitStatus;            /*!< Status of last driver transmit operation */
    volatile status_t receiveStatus;             /*!< Status of last driver receive operation */
} linflexd_uart_state_t;

/*! @brief UART configuration structure
 *
 * Implements : linflexd_uart_user_config_t_Class
 */
typedef struct
{
    uint32_t baudRate;                             /*!< baud rate */
    boolean parityCheck;                              /*!< parity control - enabled/disabled
                                                        NOTE: this parameter is valid only for 8/16 bits words;
                                                              for 7/15 word length parity is always enabled */
    linflexd_uart_parity_type_t parityType;        /*!< always 0/always 1/even/odd */
    linflexd_uart_stop_bits_count_t stopBitsCount; /*!< number of stop bits, 1 stop bit (default) or 2 stop bits */
    linflexd_uart_word_length_t wordLength;        /*!< number of bits per transmitted/received word */
    linflexd_uart_transfer_type_t transferType;    /*!< Type of UART transfer (interrupt/dma based) */
    uint8_t rxDMAChannel;                          /*!< Channel number for DMA rx channel.
                                                        If DMA mode is not used this field will be ignored. */
    uint8_t txDMAChannel;                          /*!< Channel number for DMA tx channel.
                                                        If DMA mode is not used this field will be ignored. */
    uint8_t txLinkDMAChannel;                          /*!< Channel number for DMA tx Link channel.
                                                        If DMA mode is not used this field will be ignored. */
} linflexd_uart_user_config_t;

typedef struct {
	uint8_t  edma_ch;
	eDMARequestSourceType edma_mux;
	boolean triggerEn;
}UartEdmaConfigCh;

typedef struct {
	UartEdmaConfigCh uart_edma_tx;
	UartEdmaConfigCh uart_edma_rx;
}UartEdmaConfig;

#if defined RESOURCE_SUPPORT_SIUL2_IP

#if defined RESOURCE_SUPPORT_EIOMUX2
typedef struct {
    uint32_t pad_num;
    uint32_t mscr_io_val;
    uint32_t imscr;
    uint32_t isss;
    uint32_t iss;
} UartGpioSiul2Cell;

#elif defined RESOURCE_SUPPORT_EIOMUX

typedef struct {
    uint32_t pad_num;
    uint32_t mscr_io_val;
    uint32_t mscr_mux_reg;
    uint32_t mscr_mux_val;
    uint32_t io_mode;
} UartGpioSiul2Cell;

#else

typedef struct {
    uint32_t pad_num;
    uint32_t mscr_io_val;
    uint32_t mscr_mux_reg;
    uint32_t mscr_mux_val;
} UartGpioSiul2Cell;

#endif /* RESOURCE_SUPPORT_EIOMUX2 */

typedef struct {
    UartGpioSiul2Cell uart_tx;
    UartGpioSiul2Cell uart_rx;
}UartGpioSiul2;
#endif /* RESOURCE_SUPPORT_SIUL2_IP */

#if defined RESOURCE_SUPPORT_SIUL_IP
typedef struct {
    uint16_t pad_num;
    uint16_t pcr_val;
    uint16_t psmi_reg;
    uint8_t padsel;
}UartGpioSiulCell;

typedef struct {
    UartGpioSiulCell uart_tx;
    UartGpioSiulCell uart_rx;
}UartGpioSiul;
#endif

extern const IntrHandle g_uartLINFlexDRxIsr[LINFLEXD_MAX];
extern const IntrHandle g_uartLINFlexDTxIsr[LINFLEXD_MAX];
extern const IntrHandle g_uartLINFlexDErrIsr[LINFLEXD_MAX];

#define UART_LLD_GPIO_Init  LINFLEXD_UART_LLD_GPIO_Init
#if defined RESOURCE_SUPPORT_SIUL2_IP
extern void LINFLEXD_UART_LLD_GPIO_Init(uint32_t instance, const UartGpioSiul2 UartGpioList[]);
#elif defined RESOURCE_SUPPORT_SIUL_IP
extern void LINFLEXD_UART_LLD_GPIO_Init(uint32_t instance, const UartGpioSiul UartGpioList[]);
#endif
extern status_t LINFLEXD_UART_LLD_Init(uint32_t instance, linflexd_uart_state_t * uartStatePtr,const linflexd_uart_user_config_t * uartUserConfig);
extern status_t LINFLEXD_UART_LLD_Deinit(uint32_t instance);
extern status_t LINFLEXD_UART_LLD_SetBaudRate(uint32_t instance, uint32_t baudrate);
extern status_t LINFLEXD_UART_LLD_GetBaudRate(uint32_t instance, uint32_t * baudrate);
extern status_t LINFLEXD_UART_LLD_SendData(uint32_t instance,const uint8_t * txBuff,uint32_t txSize);
extern status_t LINFLEXD_UART_LLD_SendDataBlocking(uint32_t instance,const uint8_t * txBuff,uint32_t txSize,uint32_t timeout);
extern status_t LINFLEXD_UART_LLD_ReceiveData(uint32_t instance, uint8_t * rxBuff, uint32_t rxSize);
extern status_t LINFLEXD_UART_LLD_ReceiveDataBlocking(uint32_t instance,uint8_t * rxBuff,uint32_t rxSize,uint32_t timeout);
extern status_t LINFLEXD_UART_LLD_GetTransmitStatus(uint32_t instance, uint32_t * bytesRemaining);
extern status_t LINFLEXD_UART_LLD_AbortSendingData(uint32_t instance);
extern status_t LINFLEXD_UART_LLD_GetReceiveStatus(uint32_t instance, uint32_t * bytesRemaining);
extern status_t LINFLEXD_UART_LLD_AbortReceivingData(uint32_t instance);
extern status_t LINFLEXD_UART_LLD_SetTxBuffer(uint32_t instance, const uint8_t * txBuff, uint32_t txSize);
extern status_t LINFLEXD_UART_LLD_SetRxBuffer(uint32_t instance, uint8_t * rxBuff, uint32_t rxSize);
extern uart_callback_t LINFLEXD_UART_LLD_InstallTxCallback(uint32_t instance, uart_callback_t function, void * callbackParam);
extern uart_callback_t LINFLEXD_UART_LLD_InstallRxCallback(uint32_t instance, uart_callback_t function, void * callbackParam);
extern uart_callback_t LINFLEXD_UART_LLD_InstallErrorCallback(uint32_t instance, uart_callback_t function, void * callbackParam);
extern status_t LINFLEXD_UART_LLD_StartSendUsingDmaLoop(uint32_t instance,const uint8_t * txBuff, uint32_t txSize);
/*! @brief Default ISR. */
extern void DefaultISR(void);

#endif /* LLD_INC_LINFLEXED_UART_LLD_H_ */

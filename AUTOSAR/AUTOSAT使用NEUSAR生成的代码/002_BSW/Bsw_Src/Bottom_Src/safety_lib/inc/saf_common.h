/**
****************************************************************************************
 * @FilePath: saf_common.h
 * @Author: CCORE
 * @Date: 2024-03-05
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: Safety Common Header File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_COMMON_H
#define SAF_COMMON_H


#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
/*PRQA S 0631,0722,0723,1535,2052 EOF*/
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#ifndef SAFETY_ENABLE
typedef volatile int8_t vint8_t;
typedef volatile uint8_t vuint8_t;

typedef volatile int16_t vint16_t;
typedef volatile uint16_t vuint16_t;

typedef volatile int32_t vint32_t;
typedef volatile uint32_t vuint32_t;

typedef float float32_t;
#endif
typedef double float64_t;

typedef void (*saf_intc_irq_callback)(void);/*PRQA S 0631*/

#define SAF_STD_ON     0x01u      /* Standard ON */
#define SAF_STD_OFF    0x00u      /* Standard OFF */

#define FS_CACHE_SUPPORTED                                  1
#define FS_PIM_SUPPORTED                                    0
#define FS_DEBUG_ON                                         (1U)
#define FS_DEBUG_OFF                                        (0U)
#define FS_DEBUG_SWITCH                                     (FS_DEBUG_ON)
#define FS_DIV_32_RIGHT_SHIFT_BIT                           (5U)
#define FS_MUL_32_LEFT_SHIFT_BIT                            (5U)
#define FS_MOD_32_MASK                                      (0x1F)
#define SAF_DIV_8_RIGHT_SHIFT_BIT                           (3U)
#define FS_MUL_8_LEFT_SHIFT_BIT                             (3U)
#define FS_DIV_4096_RIGHT_SHIFT_BIT                         (12U)
#define FS_MUL_4096_LEFT_SHIFT_BIT                          (12U)
#define FS_DIV_128_RIGHT_SHIFT_BIT                          (7U)
#define FS_MUL_128_LEFT_SHIFT_BIT                           (7U)
#define FS_DIV_4_RIGHT_SHIFT_BIT                            (4U)
#define FS_MUL_4_LEFT_SHIFT_BIT                             (4U)
#define FS_DIV_2048_RIGHT_SHIFT_BIT                         (11U)
#define FS_MUL_2048_LEFT_SHIFT_BIT                          (11U)
#define SAF_MOD_8_MASK                                      (0x7)
#define FS_MOD_4_MASK                                       (0x3)
#define FS_REG_BIT_WIDTH                                    (32U)
#define FS_WORD_BIT_WIDTH                                   FS_REG_BIT_WIDTH
#define FS_UIN32_MAX                                        (0xFFFFFFFFUL)
#define SAF_UIN16_MAX                                       (0xFFFFUL)
#define FS_MODULE_ENABLE                                    (true)
#define FS_MODULE_DISABLE                                   (false)
#define FS_DCF_START_ADDR_DATA                              (0x05AA55AFU)
#define SAF_NULL_PTR 										((void *)0)


#define container_of(ptr, type, member) ((type *)( (uint32_t)ptr - (uint32_t)(&(((type *)0)->member)) ))

/*!
 * @brief safety library test mode.
 *
 * This is used to represent safety library test mode. Including startup test
 * and runtime test.
 * Implements : FS_TEST_MODE_Class
 */
typedef enum
{
    FS_STARTUP_CHECK_TEST = 0x0000U, 
    FS_RUNTIME_CHECK_TEST, 
    FS_MAX_CHECK_TEST,
} FS_TEST_MODE;

/*!
 * @brief safety library startup test stage.
 *
 * This is used to represent safety library startup test stage. Including stage1
 * and stage2.
 * Implements : FS_STARTUP_TEST_STAGE_Class
 */
typedef enum
{
    FS_STARTUP_STAGE1_TEST = 1, 
    FS_STARTUP_STAGE2_TEST, 
    FS_STARTUP_STAGE_MAX_TEST,
} FS_STARTUP_TEST_STAGE;

/*!
 * @brief safety library test status.
 *
 * This is used to represent safety library test status.
 * Implements : FS_STATUS_Class
 */
typedef enum
{
    FS_STATUS_SUCCESS = 0x0000U,
    FS_STATUS_ERROR = 0x0001U,
    FS_STATUS_BUSY = 0x0002U,
    FS_STATUS_TIMEOUT = 0x0003U,
    FS_STATUS_DATA_INVALID = 0x0004U,
    FS_STATUS_CFG_ERROR,
    FS_STATUS_ERROR_CORE_ID,
    FS_STATUS_TEST_FAILED,
    FS_STATUS_MEM_OVERFLOW,

    /* test-FCCU */
    FS_STATUS_FCCU_STARTUP_TEST_FAILED = 0x2000U,
    FS_STATUS_FCCU_TESTAPI_INIT_ERROR,

    /* test-BIST */
    FS_STATUS_BIST_STARTUP_TEST_FAILED = 0x3000U,

    /* CRC */
    FS_STATUS_CRC_CALC_ERROR = 0x40000U,
    FS_STATUS_CRC_CALC_SUCCESS,
    FS_STATUS_CRC_TESTAPI_INIT_ERROR,
    FS_STATUS_CRC_SELF_TEST_ERROR,
    FS_STATUS_CRC_SELF_TEST_SUCCESS,
    FS_STATUS_CRC_INV_PARAM_ERR,

    /* FLASH */
    FS_STATUS_FLASH_TESTAPI_INIT_ERROR = 0x50000U,
    FS_STATUS_FLASH_ECC_REPROT_TEST_FAILED,
    FS_STATUS_FLASH_AI_TEST_FAILED,
    FS_STATUS_FLASH_MR_TEST_FAILED,

    /* RAM*/
    FS_STATUS_RAM_INJECTION_FAILED = 0x60000U,
    FS_STATUS_RAM_TESTAPI_INIT_ERROR,
    FS_STATUS_SRAM_ECC_REPROT_TEST_FAILED,
    FS_STATUS_PRAM_ECC_REPROT_TEST_FAILED,
    /* INTC */
    FS_STATUS_INTC_TESTAPI_INIT_ERROR,

    /* DMA */
    FS_STATUS_DMA_TESTAPI_INIT_ERROR,

    /* ADC*/
    FS_STATUS_ADC_TESTAPI_INIT_ERROR,

    /* PIT */
    FS_STATUS_PIT_TESTAPI_INIT_ERROR,

    /* OSC*/
	SAF_STATUS_XOSC_TEST_FAILED,
	SAF_STATUS_XOSC_OUT_RANGE,
    SAF_STATUS_XOSC_CNT_NOT_SET,
    SAF_STATUS_XOSC_NOT_SATBLE,
	SAF_STATUS_IRCOSC_NOT_SATBLE,
    SAF_STATUS_OSC_TESTAPI_INIT_ERROR,

    /* STM */
    FS_STATUS_STM_TESTAPI_INIT_ERROR,

    /* CMU */
    FS_STATUS_CMU_TESTAPI_INIT_ERROR,

    /* PLL */
	SAF_STATUS_PLL_NOT_SATBLE,
    SAF_STATUS_PLL_TESTAPI_INIT_ERROR,

    /* REG PROT */
	SAF_STATUS_REGPROT_LOCK_SUCCESS,
	SAF_STATUS_REGPROT_LOCK_ERROR,


    /* STACK */
    FS_STATUS_STACK_TESTAPI_INIT_ERROR,

    /* PMC */
    FS_STATUS_PMC_HVD_ERROR,
    FS_STATUS_PMC_LVD_ERROR,
    FS_STATUS_PMC_NO_VD_ERROR,

    /*TSENS*/
    FS_STATUS_TSENS_TESTAPI_INIT_ERROR,

    FS_STATUS_INVALID,

} FS_STATUS;

/*!
 * @brief safety library startup test API index.
 *
 * This is used to represent safety library startup test API index.
 * Implements : FS_STARTUP_TEST_ID_Class
 */
typedef enum
{
    FS_STARTUP_FCCU_NCF_ERR_REPORT_PATH_TEST = 0,
    FS_STARTUP_FLASH_ARRAY_INTEGRITY_TEST,
    FS_STARTUP_FLASH_MARGIN_READ_TEST,
    FS_STARTUP_FLASH_ECC_ERR_PATH_TEST,
    FS_STARTUP_RAM_ECC_ERR_PATH_TEST,
    FS_STARTUP_CRC_CHECKSUM_TEST,
    FS_STARTUP_ADC_MODE_SAFETY_TEST,
    FS_STARTUP_CMU_CONFIG_CHECK_TEST,
    FS_STARTUP_CMU_MONITOR_TEST,
    FS_STARTUP_IRCOSC_FREQUENCY_ACCURACY_TEST,
    FS_STARTUP_XOSC_CLOCK_SOURCE_TEST,
    FS_STARTUP_PLL_SYSTEM_CLOCK_SOURCE_TEST,
    FS_STARTUP_CACHE_EDC_ERR_PATH_TEST,
    FS_STARTUP_TSENS_CHIP_TEMPERATURE_TEST,
    FS_STARTUP_STACK_MONITOR_TEST,
    FS_STARTUP_MAX_INDEX_TEST,
} FS_STARTUP_TEST_ID;

/*!
 * @brief safety library runtime test API index.
 *
 * This is used to represent safety library runtime test API index.
 * Implements : FS_RUNTIME_TEST_ID_Class
 */
typedef enum
{
    FS_RUNTIME_DMA_MONITOR_TEST = 0,
    FS_RUNTIME_CRC_CFG_REG_READBACK_TEST,
    FS_RUNTIME_INTC_MONITOR_TEST,
    FS_RUNTIME_STM_TIMER_MONITOR_TEST,
    FS_RUNTIME_PIT_TIMER_MONITOR_TEST,
    FS_RUNTIME_XOSC_SYSTEM_CLOCK_SOURCE_TEST,
    FS_RUNTIME_IRCOSC_FREQUENCY_ACCURACY_TEST,
	FS_RUNTIME_TSENS_CHIP_TEMPERATURE_TEST,
    FS_RUNTIME_MAX_INDEX_TEST,
} FS_RUNTIME_TEST_ID;

/*!
 * @brief clock source type.
 *
 * This is used to represent the clock source type.
 * Implements : FS_CLOCK_SOURCE_TYPE_Class
 */
typedef enum
{
    SAF_CLOCK_SOURCE_IS_IRCOSC = 0,
    SAF_CLOCK_SOURCE_IS_XOSC = 1,
	SAF_CLOCK_SOURCE_IS_NON_FMPLL = 2,
	SAF_CLOCK_SOURCE_IS_DISABLED = 3,
    SAF_CLOCK_SOURCE_IS_FMPLL = 4,
    SAF_CLOCK_SOURCE_IS_INVALID,
} SAF_CLOCK_SOURCE_TYPE;

/*!
 * @brief clock type name.
 *
 * This is used to represent the different clock type name.
 * Implements : FS_CLOCK_NAME_Class
 */
typedef enum
{
    SAF_SYSTEM_CLK = 0,
    SAF_PCS_SYS_CLK,
    SAF_PERIPHERAL_CLK,
    SAF_RTI_0_CLK,
    SAF_MCAN_0,
    SAF_MCAN_1,
    SAF_MCAN_2,
    SAF_MCAN_3,
	SAF_MCAN_4,
	SAF_MCAN_5,
	SAF_MCAN_6,
	SAF_MCAN_7,
    SAF_MCAN_8,
    SAF_MCAN_9,
    SAF_MCAN_10,
    SAF_MCAN_11,
    SAF_NON_FMPLL_CLK, /*PLL0*/
    SAF_FMPLL_CLK, /*PLL1*/
} SAF_CLOCK_NAME;

/*!
 * @brief reset reason type.
 *
 * This is a list of reset reason type.
 * Implements : SAF_RESET_REASON_TYPE_Class
 */
typedef enum
{
	SAF_RESET_DEST_VOR= 0U,
	SAF_RESET_DEST_TSR,
	SAF_RESET_DEST_HSM,
	SAF_RESET_DEST_SCCM,
	SAF_RESET_DEST_JTAG,
	SAF_RESET_DEST_FIF,
    #if defined(CCFC3008PC) | defined(CCFC3008PCSN)
    SAF_RESET_DEST_SWT_AO,
    #endif
	SAF_RESET_DEST_EDR,
	SAF_RESET_DEST_SUF,
	SAF_RESET_DEST_FFRR,
	SAF_RESET_DEST_SOFT,
	SAF_RESET_DEST_PORST,
	SAF_RESET_DEST_POR,
	SAF_RESET_FUNC_VOR,
	SAF_RESET_FUNC_TSR,
	SAF_RESET_FUNC_HSM,
	SAF_RESET_FUNC_JTAG,
    #if defined(CCFC3008PC) | defined(CCFC3008PCSN)
    SAF_RESET_FUNC_SWT_AO,
    #endif
	SAF_RESET_FUNC_FCCU_SOFT,
	SAF_RESET_FUNC_FCCU_HARD,
	SAF_RESET_FUNC_SOFT,
	SAF_RESET_FUNC_ST_DONE,
	SAF_RESET_FUNC_ESR1,
	SAF_RESET_FUNC_ESR0,
	SAF_RESET_COUNT,
} SAF_RESET_REASON_TYPE;

#endif /* SAF_COMMON_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/

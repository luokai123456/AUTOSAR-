/**
****************************************************************************************
 * @FilePath: saf_adc.h
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: ADC include File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_ADC_H
#define SAF_ADC_H

#ifdef __cplusplus
extern "C"{
#endif
/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "eqadc_lld.h"
#include "sdadc_lld.h"
#include "saf_common.h"
#include "saf_ccfc30xx.h"
#include "SafetyPeriphTst_Cfg.h"

/**
****************************************************************************************
 * @brief: Macros
****************************************************************************************
*/

#define SAF_SUPADC_TIMES                                      (1U)

#if SAF_ADC_SDADC_SUPPORTED
#define SAF_ADC_SDADC_INSTANCE_COUNT                          (8U)
#define SAF_ADC_SDADC_CONVERTER_COUNT_LIST                    {0, 1, 2, 3, 4, 6, 7, 8}
#define SAF_SDADC_RESOLUTION                                     (65535U)
#define SAF_SDADC_VRH_MVOLT                                      (5000U)
#define SAF_SDADC_DATA_SIZE                                      (32U)
#define SAF_SDADC_TIMEOUT_COUNT                                  (0x001FFFFFU)
#endif

#if SAF_ADC_EQADC_SUPPORTED
#define SAF_EQADC_CMD_NUM                                    (1U)
#define SAF_ADC_EQADC_INSTANCE_COUNT                         (5U)
#define SAF_ADC_EQADC_RESULT_COUNT                           (9U)
#define SAF_ADC_EQADC_CONVERTER_COUNT_LIST                   {2, 2, 2, 2, 1}
#endif

/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/
/*!
 * @brief EQADC sample configuration structure.
 */
#if SAF_ADC_EQADC_SUPPORTED
typedef struct
{
    /**
    * @brief EQADC channel
    */
    uint8_t eqadcCh;
    /**
    * @brief Supervisor ADC channel
    */
    uint8_t supadcCh;
} saf_eqadc_sample_t;
#endif

/*!
 * @brief SDADC sample configuration structure.
 */
#if SAF_ADC_SDADC_SUPPORTED
typedef struct
{
    /**
    * @brief SDADC converter index
    */
    uint8_t sdadcId;
    /**
    * @brief SDADC channel
    */
    uint8_t sdadcCh;
    /**
    * @brief Supervisor ADC channel
    */
    uint8_t supadcCh;
} saf_sdadc_sample_t;
#endif

/*!
 * @brief ADC sample result structure.
 */
typedef struct
{
#if SAF_ADC_SDADC_SUPPORTED
    /**
    * @brief SDADC sample result
    */
    uint8_t sdadcCalTestResultBitmap[SAF_ADC_SDADC_INSTANCE_COUNT];
#endif
#if SAF_ADC_EQADC_SUPPORTED
     /**
    * @brief EQADC sample result
    */
    uint8_t eqadcCalTestResultBitmap[SAF_ADC_EQADC_RESULT_COUNT];
#endif
    /**
    * @brief Supervisor ADC sample result
    */
    uint8_t supadcCalTestResult;
} saf_adc_mode_safety_test_result_t;

/**
****************************************************************************************
 * @brief: Function prototypes
****************************************************************************************
*/
FS_STATUS SAF_ADC_ModeSafetyTest(void);

FS_STATUS SAF_ADC_ModeSafetyTestResult(saf_adc_mode_safety_test_result_t *pTestResult);

FS_STATUS SAF_ADC_SupadcSampleAvgVoltage(const uint16_t supch, uint16_t *pResultMv, const uint16_t times);

FS_STATUS SAF_ADC_SupadcSampleTest(saf_adc_mode_safety_test_result_t *pResult);

#if SAF_ADC_EQADC_SUPPORTED 
FS_STATUS SAF_ADC_EqadcSampleTest(saf_adc_mode_safety_test_result_t *pResult);

FS_STATUS SAF_ADC_EqadcSampleAvgVoltage(const uint8_t eqadcInst, const uint8_t adcIdx, const uint8_t chan, uint16_t *pResultMv, const uint16_t times);
#endif

#if SAF_ADC_SDADC_SUPPORTED
FS_STATUS SAF_ADC_SdadcSampleTest(saf_adc_mode_safety_test_result_t *pResult);

FS_STATUS SAF_ADC_SdadcSampleAvgVoltage(const Saf_Sdadc_InstanceType sdadcId, const uint8_t chan, uint16_t *pResultMv, const uint16_t times);

#endif

#ifdef __cplusplus
}
#endif

#endif /* SAF_ADC_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/

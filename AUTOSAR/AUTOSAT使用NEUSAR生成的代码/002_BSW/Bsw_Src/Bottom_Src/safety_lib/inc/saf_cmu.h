/**
****************************************************************************************
 * @FilePath: saf_cmu.h
 * @Author: CCORE
 * @Date: 2024-03-05
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: Safety Cmu Header File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_CMU_H
#define SAF_CMU_H

#if defined (__cplusplus)
extern "C" {
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_cpu.h"
#include "mcu_lld.h"

/**
****************************************************************************************
 * @brief: Macros
****************************************************************************************
*/

#define SAF_CMU_IRCOSC_MEASURE_TIMEOUT_CYCLE                 (100000U) // cyh, adpat to 400MHz
#define SAF_CMU_CLK_SELECT_IRCOSC                            (0x3U)
#define SAF_CMU_MEASURE_IRCOSC_MD_VALUE                      (100000)

#define SAF_CMU_MEASURE_IRCOSC_COMPLETE                      (1UL)
#if defined(CCFC3012PT)
#define SAF_CMU_INS0                                         (0UL)
#define SAF_CMU_DIV_BY4_SHIFT                                (2U)
#endif
#define SAF_CMU_FREQ_TEST_ERROR                1U
#define SAF_CMU_FREQ_TEST_SUCCESS              0U

#define SAF_CMU_FULL_RANGE                     100U
#define SAF_CMU_FREF_COEFF                     64U
#define SAF_CMU_HFREF_MAX                      4095U

#define SAF_CMU_CONFIG_CHECK_SUCCESS           0xFFFFFFFFU

/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************/

/**
* @brief  CMU configure structure.
*/
typedef struct
{
	/**
    * @brief CMU instance number
    */
	uint8_t cmuInst;
	/**
    * @brief CMU monitor frequency
    */
    uint32_t frequency;
	/**
    * @brief CMU monitor frequency error ratio,2 for 2%
    */
    uint32_t errRatio;
} saf_cmu_monitor_configure_t;

/**
* @brief  CMU monitor fault type.
*/
typedef struct
{
	/**
    * @brief CMU monitor frequency high error
    */
	uint32_t freqOverHigh :1;
	/**
    * @brief CMU monitor frequency low error
    */
    uint32_t freqOverLow :1;
	/**
    * @brief Osc frequency error
    */
    uint32_t oscFreqOverLow :1;
    uint32_t :29;
} saf_cmu_freq_fault_type_t;

/**
* @brief  CMU clock frequency monitor result.
*/
typedef struct
{
	/**
    * @brief This is used to represent all object clock frequency monitor result.
    */
	saf_cmu_freq_fault_type_t monitorObj[SAF_CMU_MAX_INSTANCE];
} saf_cmu_mgr_freq_monitor_result_t;

/**
* @brief  CMU monitor manage structure.
*/
typedef struct
{
	/**
    * @brief This is used to represent all object clock frequency monitor result.
    */
	saf_cmu_mgr_freq_monitor_result_t freqMonitorObjList;
	/**
    * @brief This is used to represent all object clock frequency monitor high value.
    */
    uint32_t overHighFreq[SAF_CMU_MAX_INSTANCE];
	/**
    * @brief This is used to represent all object clock frequency monitor low value.
    */
    uint32_t overLowFreq[SAF_CMU_MAX_INSTANCE];
} saf_cmu_mgr_monitor_t;

/**
* @brief CMU monitor configuration check result structure.
*/
typedef struct
{
	/**
    * @brief This is used to the test result of CMU monitor configuration check test.
    */
	uint32_t cfgCheckPassedBitmap;
} saf_cmu_config_check_test_result_t;

/**
* @brief CMU monitor configuration check test structure.
*/
typedef struct
{
	/**
    * @brief This is used to the test result of CMU monitor configuration check test.
    */
	saf_cmu_config_check_test_result_t output;

} saf_cmu_config_check_test_t;

/**
* @brief CMU monitor test result structure.
*/
typedef struct
{
	/**
    * @brief This is used to the test result of CMU monitor configuration check test.
    */
	saf_cmu_freq_fault_type_t monitorInstance[SAF_CMU_MAX_INSTANCE];

} saf_cmu_monitor_test_result_t;

/**
* @brief CMU clock monitor test structure.
*/
typedef struct
{
	/**
    * @brief This is used to CMU clock monitor test.
    */
	saf_cmu_monitor_test_result_t output;
} saf_cmu_monitor_test_t;

/**
****************************************************************************************
 * @brief: Function prototypes
****************************************************************************************
*/

FS_STATUS SAF_CMU_MonitorTest(void);

FS_STATUS SAF_CMU_MonitorTestResult(saf_cmu_monitor_test_t *pTestResult);

FS_STATUS SAF_CMU_ConfigCheckTest(void);

FS_STATUS SAF_CMU_ConfigCheckTestResult(saf_cmu_config_check_test_t *pTestResult);

FS_STATUS SAF_CMU_Init(const saf_cmu_monitor_configure_t *pCmuConfigArr, const uint8_t cmuCount);

FS_STATUS SAF_CMU_IrcoscFreqMeasure(uint32_t *pFreq);

FS_STATUS SAF_CMU_Deinit(void);

FS_STATUS SAF_CMU_Enable(const uint8_t cmuInst, const bool enable);

bool SAF_CMU_IsEnabled(const CMU_Type *pBase);

void SAF_CMU_GetAndCleanIrqStatus(const uint32_t cmuInst);

void SAF_CMU_Start(void);

#if defined (__cplusplus)
}
#endif

#endif /* FS_CMU_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/

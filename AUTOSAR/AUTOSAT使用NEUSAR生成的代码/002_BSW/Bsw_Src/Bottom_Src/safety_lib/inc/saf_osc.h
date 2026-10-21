/**
****************************************************************************************
 * @FilePath: saf_osc.h
 * @Author: CCORE
 * @Date: 2024-01-22
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety Osc head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_OSC_H
#define SAF_OSC_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_cpu.h"
#include "SafetyClockTst_cfg.h"
#include "mcu_lld.h"
#include "saf_pll.h"
#include "saf_userservice_callback.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Refer to the data sheet */
#define SAF_IRC_ACCURACY                                     (1U)    /* unit is 1% */

#define GS_S_OSC_NOT_STABLE    0U
#define GS_S_OSC_STABLE        1U

/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/

typedef struct
{
	/**
    * @brief osc frequence Max Margin
    */
    uint32_t ircoscMaxMargin;
	/**
    * @brief osc frequence Min Margin
    */
    uint32_t ircoscMinMargin;
} saf_osc_frequence_threshold_t;

/*!
 * @brief The IRCOSC frequency accuracy test result structure.
 *
 * This is the test result of IRCOSC frequency accuracy test. It contains real IRCOSC frequency
 * and test result.
 * Implements : saf_osc_ircosc_freq_check_test_result_t_Class
 */
typedef struct
{
	/**
    * @brief osc test frequency
    */
    uint32_t realIrcoscFreq;
	/**
    * @brief osc frequency check pass
    */
    bool checkPassed;
} saf_osc_ircosc_freq_check_test_result_t;

/*!
 * @brief The XOSC source clock source check test result structure.
 *
 * This is the test result of XOSC module source source check test. It includes source check test
 * result and available test result.
 * Implements : saf_osc_xosc_sys_clk_source_test_result_t_Class
 */
typedef struct
{
	/**
    * @brief osc soucre check pass
    */
    uint8_t sourceCheckPassed;
} saf_osc_xosc_sys_clk_test_result_t;


/*******************************************************************************
 * API
 ******************************************************************************/

#if defined (__cplusplus)
extern "C" {
#endif

extern const saf_osc_frequence_threshold_t saf_osc_kConfigSet;


/*!
 *
 * This function is executed in the initial and runtime phase, and shall be used to detect the frequency of IRCOSC and compare it with the expected frequency.
 *
 */
FS_STATUS SAF_OSC_IrcoscFreqAccuracyTest(void);


/*!
 * This function is used to init IRCOSC frequence test.
 *
 */
void SAF_OSC_IrcoscFreqAccuracyInit(void);

/*!
 * This function is executed in the initial phase. It shall be used to check that the system clock is available, and sourced by the XOSC. 
 * 
 */ 
FS_STATUS SAF_OSC_XoscSysClkSrcCheckTest(void);

/*!
 * This function is used to check XOSC is stable.
 * 
 */ 
FS_STATUS SAF_OSC_XoscFreqIsStable(void);

/*!
 * This function is used to check XOSC is stable.
 *
 */
FS_STATUS SAF_OSC_IrcoscFreqIsStable(void);

/*!
 * This function is used to get IRCOSC frequence from manager. 
 *
 * @param[out] pFreq - the pointer of frequence parameter.
 */
FS_STATUS SAF_OSC_GetIrcoscMgrFreq(uint32_t *pFreq);

/*!
 * This function is used to set IRCOSC frequence to manager. 
 *
 * @param[in] pFreq - the value of frequence parameter.
 */
FS_STATUS SAF_OSC_SetIrcoscMgrFreq(uint32_t freq);

/*!
 * This function is used to get IRCOSC frequence result.
 *
 * @param[in] pFreq - test parameters.
 */
FS_STATUS SAF_OSC_GetFreqCheckResult(saf_osc_ircosc_freq_check_test_result_t *pTestResult);


/*!
 * This function is used to get the OSC system clock source test results.
 *
 * @param[in] pFreq - test parameters.
 */
FS_STATUS SAF_OSC_GetSysClkSrcCheckResult(saf_osc_xosc_sys_clk_test_result_t *pTestResult);

#if defined (__cplusplus)
}
#endif

#endif/* SAF_OSC_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/

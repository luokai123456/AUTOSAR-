/**
****************************************************************************************
 * @FilePath: saf_pll.h
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: Safety Pll Head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_PLL_H
#define SAF_PLL_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_common.h"
#include "SafetyClockTst_Cfg.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/**
****************************************************************************************
 * @brief: Macros
****************************************************************************************
*/
#define GS_S_PLL_NOT_STABLE    0U
#define GS_S_PLL_STABLE        1U

/*!
 * @brief The PLL module clock source check test result structure.
 *
 * This is the test result of PLL module clock source check test. It includes MCAN and
 * FlexCAN test result.
 * Implements : saf_pll_periph_clksrc_test_result_t_Class
 */
typedef struct
{
    /* PLL mcan clock test result */
    bool mcanCheckPassed;
#if SAF_FlexRay_SUPPORTED
    /* PLL flexray clock test result */
    bool flexrayCheckPassed;
#endif
} saf_pll_periph_clksrc_test_result_t;

/*!
 * @brief The PLL module clock source check test Information structure.
 *
 * This is the test result of PLL module clock source check test. It includes MCAN and
 * FlexCAN test Information.
 * Implements : saf_pll_clk_source_test_info_t_Class
 */
typedef struct
{
	bool mcanIsChecked;
	const char * funcName;
} saf_pll_clk_source_test_info_t;

/*!
 * @brief PLL system clock test result structure.
 *
 * This is the test result of PLL module system clock source check test.
 * Implements : saf_pll_sys_clk_test_result_t_Class
 */
typedef struct
{
    bool sysclkCheckPassed;
} saf_pll_sys_clk_test_result_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined (__cplusplus)
extern "C" {
#endif
/*!
 * This function is executed in the initial phase, and shall be used to detect whether the clock source of MCAN and FlexCAN is XOSC.
 *
 */
FS_STATUS SAF_PLL_PeriphClkSrcCheckTest(void);/*PRQA S 3001*/

/*!
 * This function is executed in the initial phase. It shall be used to check whether the system clock source is FMPLL.
 *
 */
FS_STATUS SAF_PLL_SysClkSrcCheckTest(void);/*PRQA S 3001*/

/*!
 * This function is used to check FMPLL has been locked.
 *
 */
bool SAF_PLL_AccessFmpllIsLocked(void);

/*!
 * This function is used to check non-FMPLL has been locked. 
 *
 */
bool SAF_PLL_AccessNonFmpllIsLocked(void);

/*!
 * This function is used to check pll is stable. 
 *
 */
FS_STATUS SAF_PLL_IsStable(void);

/*!
 * This function is used to get peripheral source test result.
 *
 */
FS_STATUS SAF_PLL_GetPeriphClkSrcResult(saf_pll_periph_clksrc_test_result_t *pTestResult);

/*!
 * This function is used to get system clock source test result.
 *
 */
FS_STATUS SAF_PLL_GetSysClkSrcResult(saf_pll_sys_clk_test_result_t *pTestResult);

#if defined (__cplusplus)
}
#endif

#endif/* SAF_PLL_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/

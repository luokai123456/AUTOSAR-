/**
****************************************************************************************
 * @FilePath: saf_pll.c
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: Safety PLL C Source File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_common.h"
#include "saf_cpu.h"/*PRQA S 0380*/
#include "saf_pll.h"
#include "SafetyClockTst_Cfg.h"
#include "Saf_MemMap.h"
/*PRQA S 0315,3200,3218,4304,4342,4404,4424 EOF*/
/*******************************************************************************
 * Variables
 ******************************************************************************/
SAF_PLL_SEC_VAR_NO_INIT
static saf_pll_sys_clk_test_result_t s_pllSysClkCheckTest;
SAF_PLL_SEC_VAR_NO_INIT
static saf_pll_periph_clksrc_test_result_t s_pllPeriphClkSrcTest;

/**
****************************************************************************************
 * @brief: Local Functions
****************************************************************************************
*/
/**
****************************************************************************************
* @brief[SW_035][SW_037][SW_85] This function is used to get mcan clock source.
* @return clkType
          SAF_CLOCK_SOURCE_IS_IRCOSC:    clock source is IRCOSC
          SAF_CLOCK_SOURCE_IS_XOSC:      clock source is XOSC
          SAF_CLOCK_SOURCE_IS_NON_FMPLL: clock source is NON_FMPLL
          SAF_CLOCK_SOURCE_IS_INVALID:   INVALID value
****************************************************************************************
*/
static SAF_CLOCK_SOURCE_TYPE SAF_PLL_AccessGetMcanClkSrc(void)
{
    uint32_t regValue = 0u;
    SAF_CLOCK_SOURCE_TYPE clkType = SAF_CLOCK_SOURCE_IS_INVALID;

    regValue = ((MC_CGM.AC8_SC.R & MC_CGM_AC8_SC_SELSTAT_MASK) >> MC_CGM_AC8_SC_SELCTL_SHIFT_SAF);/*PRQA S 1841,4542*/
    clkType = (SAF_OSC_CLOCK_SOURCE_IS_IRCOSC == regValue) ? SAF_CLOCK_SOURCE_IS_IRCOSC : clkType;
    clkType = (SAF_OSC_CLOCK_SOURCE_IS_XOSC == regValue) ? SAF_CLOCK_SOURCE_IS_XOSC : clkType;
    clkType = (SAF_OSC_CLOCK_SOURCE_IS_NON_FMPLL == regValue) ? SAF_CLOCK_SOURCE_IS_NON_FMPLL : clkType;

    return clkType;
}

#if SAF_FlexRay_SUPPORTED
/**
****************************************************************************************
* @brief[SW_035][SW_037][SW_85] This function is used to get flexray clock source.
* @return clkType
          SAF_FLEXRAY_CLOCK_SOURCE_IS_OSC:      clock source is XOSC
          SAF_FLEXRAY_CLOCK_SOURCE_IS_PLL: clock source is PLL
          SAF_CLOCK_SOURCE_IS_INVALID:   INVALID value
****************************************************************************************
*/
static SAF_CLOCK_SOURCE_TYPE SAF_PLL_AccessGetFlexrayClkSrc(void)
{
    uint32_t regValue = 0u;
    SAF_CLOCK_SOURCE_TYPE clkType = SAF_CLOCK_SOURCE_IS_INVALID;

    regValue = FR_0.MCR.B.CLKSEL;
    clkType = (SAF_FLEXRAY_CLOCK_SOURCE_IS_OSC == regValue) ? SAF_CLOCK_SOURCE_IS_XOSC : clkType;
    clkType = (SAF_FLEXRAY_CLOCK_SOURCE_IS_PLL == regValue) ? SAF_CLOCK_SOURCE_IS_NON_FMPLL : clkType;

    return clkType;
}
#endif
/*******************************************************************************
 * Global Functions
 ******************************************************************************/

/**
****************************************************************************************
* @brief[SW_032] This function is used to detects if the PLL0 & PLL1 is stable.
* @return  status
*          FS_STATUS_SUCCESS: PLL0 & PLL1 is stable
*          SAF_STATUS_PLL_NOT_SATBLE: PLL0 & PLL1 is unstable
****************************************************************************************
*/
SAF_PLL_SEC_CODE
FS_STATUS SAF_PLL_IsStable(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint32_t GS_S_PLL1 , GS_S_PLL0;
    GS_S_PLL1 = MC_ME.GS.B.S_PLL1;
    GS_S_PLL0 = MC_ME.GS.B.S_PLL0;
    if((GS_S_PLL_NOT_STABLE == GS_S_PLL0) || (GS_S_PLL_NOT_STABLE == GS_S_PLL1))
    {
        status = SAF_STATUS_PLL_NOT_SATBLE;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to execute clock source check test.
* @param[in]    Void
* @return       status test result
****************************************************************************************
*/
SAF_PLL_SEC_CODE
FS_STATUS SAF_PLL_SysClkSrcCheckTest(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    SAF_CLOCK_SOURCE_TYPE clkType = SAF_CLOCK_SOURCE_IS_INVALID;
    saf_pll_sys_clk_test_result_t *pResult = &s_pllSysClkCheckTest;

    /*1.detect system clock source*/
    pResult->sysclkCheckPassed = (bool)true;

    clkType = SAF_MCU_ClkGetClkSrc(SAF_SYSTEM_CLK);
    if (SAF_CLOCK_SOURCE_IS_FMPLL != clkType)
    {
        status = FS_STATUS_ERROR;
        pResult->sysclkCheckPassed = (bool)false;
    }
    return status;
}

/**
****************************************************************************************
* @brief[SW_037][SW_85] This function is used to executes PLL modules clock source check test.
* @return   status
            FS_STATUS_SUCCESS: Mcan clock source check test success.
            FS_STATUS_ERROR:   Mcan clock source check test error.
****************************************************************************************
*/
SAF_PLL_SEC_CODE
FS_STATUS SAF_PLL_PeriphClkSrcCheckTest(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    SAF_CLOCK_SOURCE_TYPE clockSrc;
    saf_pll_periph_clksrc_test_result_t *pResult = &s_pllPeriphClkSrcTest;

    pResult->mcanCheckPassed = true;
    clockSrc = SAF_PLL_AccessGetMcanClkSrc();
    /*1.mcan clock source check*/
    if ((SAF_CLOCK_SOURCE_IS_NON_FMPLL != clockSrc) && (SAF_CLOCK_SOURCE_IS_XOSC != clockSrc))
    {
        pResult->mcanCheckPassed = false;
        status = FS_STATUS_ERROR;
    }

#if SAF_FlexRay_SUPPORTED
    pResult->flexrayCheckPassed = true;
    clockSrc = SAF_PLL_AccessGetFlexrayClkSrc();
    /*2.flexray clock source check*/
    if ((SAF_CLOCK_SOURCE_IS_NON_FMPLL != clockSrc) && (SAF_CLOCK_SOURCE_IS_XOSC != clockSrc))
    {
        pResult->flexrayCheckPassed = false;
        status = FS_STATUS_ERROR;
    }
#endif

    return status;
}

/**
****************************************************************************************
* @brief:  		This function is used to get the PLL Mcan source results.
* @param[in]    pTestResult         test parameters.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     get results success
*               FS_STATUS_ERROR       get results failed
****************************************************************************************
*/
SAF_PLL_SEC_CODE
FS_STATUS SAF_PLL_GetPeriphClkSrcResult(saf_pll_periph_clksrc_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (pTestResult != NULL)
    {
        memcpy(pTestResult, &s_pllPeriphClkSrcTest, sizeof(s_pllPeriphClkSrcTest));
        status = FS_STATUS_SUCCESS;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  		This function is used to get the PLL read back test results.
* @param[in]    pTestResult         test parameters.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     get results success
*               FS_STATUS_ERROR       get results failed
****************************************************************************************
*/
SAF_PLL_SEC_CODE
FS_STATUS SAF_PLL_GetSysClkSrcResult(saf_pll_sys_clk_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (pTestResult != NULL)
    {
        memcpy(pTestResult, &s_pllSysClkCheckTest, sizeof(s_pllSysClkCheckTest));
        status = FS_STATUS_SUCCESS;
    }

    return status;
}
/*******************************************************************************
 * EOF
 ******************************************************************************/

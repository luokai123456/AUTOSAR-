/**
****************************************************************************************
 * @FilePath: SafetyClockTst_Cfg.c
 * @Author: CCORE
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety test Clock configuration C File
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

#include "SafetyClockTst_Cfg.h"
#include "saf_userservice_callback.h"
#include "saf_osc.h"/* PRQA S 0380 */
#include "saf_cmu.h"
#include "Saf_MemMap.h"
/* PRQA S 1533, 3408, 4304 EOF*/
/**
****************************************************************************************
 * @brief: Structs
****************************************************************************************
*/

/**
* @brief  OSC test call back.
*/
SAF_OSC_SEC_CONFIG_DATA
const call_config_t s_oscCallSet =
{
    /* OSC notification function */
    .callback       = NULL,
    /* OSC notification function parameter */
    .callbackParam  = NULL
};

/**
* @brief  PLL SYS CLK test call back.
*/
SAF_PLL_SEC_CONFIG_DATA
const call_config_t s_pllSysClkCallSet =
{
    /* PLL SYS CLK notification function */
    .callback       = NULL,
    /* PLL SYS CLK notification function parameter */
    .callbackParam  = NULL
};

/**
* @brief  PLL Periph Clk test call back.
*/
SAF_PLL_SEC_CONFIG_DATA
const call_config_t s_pllPeriphClkCallSet =
{
    /* PLL periph Clk notification function */
    .callback       = NULL,
    /* PLL periph Clk notification function parameter */
    .callbackParam  = NULL
};

/**
* @brief  Cmu config check test error call back.
*/
SAF_CMU_SEC_CONFIG_DATA
const call_config_t s_cmuConfigcheckCallSet =
{

    /* Cmu config check test error notification function */
    .callback       = NULL,
    /* Cmu config check test errorFlash notification function parameter */
    .callbackParam  = NULL
  
};


/**
* @brief  The frequency over high error call back.
*/
SAF_CMU_SEC_CONFIG_DATA
const call_config_t s_cmuMonitorTestFreqOverHighCallSet =
{

    /* The frequency over high error notification function */
    .callback       = NULL,
    /* The frequency over high error notification function parameter */
    .callbackParam  = NULL
  
};

/**
* @brief  The frequency over low error call back.
*/
SAF_CMU_SEC_CONFIG_DATA
const call_config_t s_cmuMonitorTestFreqOverLowCallSet =
{

    /* The frequency over low notification function */
    .callback       = NULL,
    /* The frequency over low notification function parameter */
    .callbackParam  = NULL
  
};

/**
* @brief  The osc frequency over low error call back.
*/
SAF_CMU_SEC_CONFIG_DATA
const call_config_t s_cmuMonitorTestOscFreqOverLowCallSet =
{

    /* The osc frequency over low notification function */
    .callback       = NULL,
    /* The osc frequency over low notification function parameter */
    .callbackParam  = NULL
  
};


/**
* @brief  The cmu user service test call back.
*/
SAF_CMU_SEC_CONFIG_DATA
const call_config_t s_cmuUserServiceTestCallSet =
{

    /* The cmu user service test notification function */
    .callback       = NULL,
    /* The cmu user service test notification function parameter */
    .callbackParam  = NULL
  
};

/**
* @brief  The OSC frequence threshold.
*/
SAF_OSC_SEC_CONFIG_DATA
const saf_osc_frequence_threshold_t saf_osc_kConfigSet = 
{
	1600000U,
	1600000U
};
/**
* @brief  The cmu instance config list.
*/
SAF_CMU_SEC_VAR_INIT
saf_cmu_monitor_configure_t s_cmuConfigList[CMU_INSTANCE_COUNT]=
{
    {
        .cmuInst=0U,
        .frequency=400000000U,
        .errRatio=12U,
    },
    {
        .cmuInst=1U,
        .frequency=200000000U,
        .errRatio=12U,
    },
    {
        .cmuInst=2U,
        .frequency=100000000U,
        .errRatio=12U,
    },
    {
        .cmuInst=3U,
        .frequency=50000000U,
        .errRatio=12U,
    },
    {
        .cmuInst=4U,
        .frequency=200000000U,
        .errRatio=12U,
    },
    {
        .cmuInst=5U,
        .frequency=16000000U,
        .errRatio=12U,
    },
    {
        .cmuInst=6U,
        .frequency=40000000U,
        .errRatio=12U,
    },
    {
        .cmuInst=7U,
        .frequency=100000000U,
        .errRatio=12U,
    },
    {
        .cmuInst=8U,
        .frequency=6048387U,
        .errRatio=12U,
    },
    {
        .cmuInst=9U,
        .frequency=4000000U,
        .errRatio=12U,
    },
    {
        .cmuInst=10U,
        .frequency=1000000U,
        .errRatio=12U,
    },
    {
        .cmuInst=11U,
        .frequency=400000000U,
        .errRatio=12U,
    },
    {
        .cmuInst=12U,
        .frequency=50000000U,
        .errRatio=12U,
    },
};
#ifdef __cplusplus
}
#endif



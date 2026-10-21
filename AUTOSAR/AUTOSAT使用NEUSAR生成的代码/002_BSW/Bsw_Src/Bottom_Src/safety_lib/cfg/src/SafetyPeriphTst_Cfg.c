/**
****************************************************************************************
 * @FilePath: SafetyPeriphTst_Cfg.c
 * @Author: CCORE
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety test Periph configuration c File
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

#include "saf_stm.h"/*PRQA S 0380*/
#include "saf_pit.h"
#include "saf_tsens.h"
#include "saf_userservice_callback.h"
#include "SafetyPeriphTst_Cfg.h"
#include "Saf_MemMap.h"
/*PRQA S 0704,1533,3408,4304,4404 EOF*/
/**
****************************************************************************************
 * @brief: Structs
****************************************************************************************
*/

/* Stm timer config data init call back */
SAF_STM_SEC_CONFIG_DATA
const call_config_t s_StmTimerConfigDataInitCallSet =
{

    /* Stm notification function */
    .callback       = NULL,
    /* Stm notification function parameter */
    .callbackParam  = NULL
  
};

/* Stm timer monitor test call back */
SAF_STM_SEC_CONFIG_DATA
const call_config_t s_StmTimerMonitorCallSet =
{

    /* Stm notification function */
    .callback       = NULL,
    /* Stm notification function parameter */
    .callbackParam  = NULL
  
};

/* Pit timer config data init call back */
SAF_PIT_SEC_CONFIG_DATA
const call_config_t s_PitTimerConfigDataInitCallSet =
{

    /* Pit notification function */
    .callback       = NULL,
    /* Pit notification function parameter */
    .callbackParam  = NULL
  
};

/* Pit timer monitor test call back */
SAF_PIT_SEC_CONFIG_DATA
const call_config_t s_PitTimerMonitorCallSet =
{

    /* Pit notification function */
    .callback       = NULL,
    /* Pit notification function parameter */
    .callbackParam  = NULL
  
};

/* Tsens chip temperature htd path test call back */
SAF_TSENS_SEC_CONFIG_DATA
const call_config_t s_TsensChipTempHtdPathCallSet =
{

    /* Tsens notification function */
    .callback       = NULL,
    /* Tsens notification function parameter */
    .callbackParam  = NULL
  
};

/* Tsens chip temperature ltd path test call back */
SAF_TSENS_SEC_CONFIG_DATA
const call_config_t s_TsensChipTempLtdPathCallSet =
{

    /* Tsens notification function */
    .callback       = NULL,
    /* Tsens notification function parameter */
    .callbackParam  = NULL
  
};
 
/* Tsens chip temperature error range test call back */
SAF_TSENS_SEC_CONFIG_DATA
const call_config_t s_TsensChipTempErrorRangeCallSet =
{

    /* Tsens notification function */
    .callback       = NULL,
    /* Tsens notification function parameter */
    .callbackParam  = NULL
  
};

/* Swt timer path test call back */
SAF_SWT_SEC_CONFIG_DATA
const call_config_t s_SwtPathCallSet =
{

    /* Swt notification function */
    .callback       = NULL,
    /* Swt notification function parameter */
    .callbackParam  = NULL
  
};


   
   

/* Adc test call back */
SAF_ADC_SEC_CONFIG_DATA
const call_config_t s_AdcTestCallSet =
{

    /* Adc notification function */
    .callback       = NULL,
    /* Adc notification function parameter */
    .callbackParam  = NULL
  
};


   
   

/* Interrupt Monitor call back */
SAF_INTC_SEC_CONFIG_DATA
const call_config_t s_IrqMonitorCallSet =
{

    /* Interrupt Monitor notification function */
    .callback       = NULL,
    /* Interrupt Monitor notification function parameter */
    .callbackParam  = NULL
  
};


   
   

/* DMA Monitor call back */
SAF_DMA_SEC_CONFIG_DATA
const call_config_t s_DmaMonitorCallSet =
{

    /* DMA Monitor notification function */
    .callback       = NULL,
    /* DMA Monitor notification function parameter */
    .callbackParam  = NULL
  
};


/**< @brief:The stm timer config data structure. */
SAF_STM_SEC_CONFIG_DATA
const saf_stm_timer_config_data_t s_SafStmTimerConfig[SAF_STM_TEST_USED_CHANNEL] = {
    
    {
        /**< @brief:This parameter represents the stm channel id. */
        .chan                   = (uint8_t)STM_Channel0,
        /**< @brief:This parameter represents the stm timer cycle. */
        .periodUs               = 500000,
        /**< @brief:This parameter represents the stm timer cycle error range. */
        .periodErrRangeRatio    = SAF_PIT_MONITOR_ACCURACY_RATIO,
        /**< @brief:This parameter represents the stm timer interrupt priority. */
        .priority               = 14,
        /**< @brief:This parameter represents the stm timer need To monitor. */
        .needToMonitor          = true,
        /**< @brief:This parameter represents the stm timer monitor enable. */
        .MonitorEnable          = false,
    },
    
    {
        /**< @brief:This parameter represents the stm channel id. */
        .chan                   = (uint8_t)STM_Channel1,
        /**< @brief:This parameter represents the stm timer cycle. */
        .periodUs               = 2000,
        /**< @brief:This parameter represents the stm timer cycle error range. */
        .periodErrRangeRatio    = 0,
        /**< @brief:This parameter represents the stm timer interrupt priority. */
        .priority               = 14,
        /**< @brief:This parameter represents the stm timer need To monitor. */
        .needToMonitor          = false,
        /**< @brief:This parameter represents the stm timer monitor enable. */
        .MonitorEnable          = true,
    },
    };

/**< @brief:The pit timer config data structure. */
SAF_PIT_SEC_CONFIG_DATA
const saf_pit_timer_config_data_t s_SafPitTimerConfig[SAF_PIT_TEST_USED_CHANNEL] = {
    
    {
        /**< @brief:This parameter represents the pit channel id. */
        .chan                   = (uint8_t)PIT_Channel0,
        /**< @brief:This parameter represents the pit timer cycle. */
        .periodUs               = 300000,
        /**< @brief:This parameter represents the pit timer cycle error range. */
        .periodErrRangeRatio    = SAF_STM_MONITOR_ACCURACY_RATIO,
        /**< @brief:This parameter represents the pit timer interrupt priority. */
        .priority               = 13,
        /**< @brief:This parameter represents the pit timer need To monitor. */
        .needToMonitor          = true,
        /**< @brief:This parameter represents the pit timer monitor enable. */
        .MonitorEnable          = false,
    },
    
    {
        /**< @brief:This parameter represents the pit channel id. */
        .chan                   = (uint8_t)PIT_Channel1,
        /**< @brief:This parameter represents the pit timer cycle. */
        .periodUs               = 3000,
        /**< @brief:This parameter represents the pit timer cycle error range. */
        .periodErrRangeRatio    = 0,
        /**< @brief:This parameter represents the pit timer interrupt priority. */
        .priority               = 13,
        /**< @brief:This parameter represents the pit timer need To monitor. */
        .needToMonitor          = false,
        /**< @brief:This parameter represents the pit timer monitor enable. */
        .MonitorEnable          = true,
    },
    };

/**< @brief:The tsens error type config structure. */
SAF_TSENS_SEC_CONFIG_DATA
const saf_tsens_error_action_type_config s_SafTsensConfig = {
        /**< @brief:This parameter is used to enable the fccu event of the temperature sensor. */
        .TsensFccuEventEnable   = true,
        /**< @brief:This parameter is used to enable the error type of the temperature sensor. */
        .TsensErrorActionType   = SAF_TSENS_ERROR_ACTION_IS_DESTRUCTIVE_RESET
};

#ifdef __cplusplus
}
#endif

/**
****************************************************************************************
 * @FilePath: SafetyCoreTst_Cfg.c
 * @Author: CCORE
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety test Core configuration C File
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
#include "SafetyCoreTst_Cfg.h"
#include "saf_pmc.h"/* PRQA S 0380 */
#include "saf_core.h"/* PRQA S 0380 */
#include "saf_userservice_callback.h"
#include "Saf_MemMap.h"
/* PRQA S 1533, 3408, 4304 EOF*/
/**
****************************************************************************************
 * @brief: Structs
****************************************************************************************
*/
/* CORE module configuration */
SAF_CORE_SEC_CONFIG_DATA
const saf_core_reset_config_t CoreResetCfg =
{
    /* Destructive Reset Escalation Threshold */
    .DesThreshold = 0,
    /* Functional Reset Escalation Threshold */
    .FuncThreshold = 0,
};
   
   

/* Core self test call back */
SAF_CORE_SEC_CONFIG_DATA
const call_config_t s_coreCallSet =
{

    /* Core notification function */
    .callback       = NULL,
    /* Core notification function parameter */
    .callbackParam  = NULL
  
};


   
   

/* Core destructive reset test call back */
SAF_CORE_SEC_CONFIG_DATA
const call_config_t s_coreDestructiveResetCallSet =
{

    /* Core destructive reset notification function */
    .callback       = NULL,
    /* Core destructive reset notification function parameter */
    .callbackParam  = NULL
  
};


   
   

/* Core function reset test call back */
SAF_CORE_SEC_CONFIG_DATA
const call_config_t s_coreFunctionResetCallSet =
{

    /* Core function reset notification function */
    .callback       = NULL,
    /* Core function reset notification function parameter */
    .callbackParam  = NULL
  
};


   
   

/* Dcf Self test call back */
SAF_CORE_SEC_CONFIG_DATA
const call_config_t s_dcfCallSet =
{

    /* Dcf notification function */
    .callback       = NULL,
    /* Dcf notification function parameter */
    .callbackParam  = NULL
  
};


   
   

/* Offline Bist Self test call back */
SAF_BIST_SEC_CONFIG_DATA
const call_config_t s_offlinebistCallSet =
{

    /* Offline Bist notification function */
    .callback       = NULL,
    /* Offline Bist notification function parameter */
    .callbackParam  = NULL
  
};


   
   

/* Online Bist test call back */
SAF_BIST_SEC_CONFIG_DATA
const call_config_t s_OnlinebistCallSet =
{

    /* Online Bist notification function */
    .callback       = NULL,
    /* Online Bist notification function parameter */
    .callbackParam  = NULL
  
};


   
   

/* Pmc Self test call back */
SAF_PMC_SEC_CONFIG_DATA
const call_config_t s_pmcSelfTestCallSet =
{

    /* Pmc notification function */
    .callback       = NULL,
    /* Pmc notification function parameter */
    .callbackParam  = NULL
  
};


/**< @brief:The pmc error type config structure. */
SAF_PMC_SEC_CONFIG_DATA
const saf_pmc_error_action_type_config s_SafPmcConfig = {
        /**< @brief:This parameter is used to enable the FCCU event of the pmc. */
        .PmcFccuEventEnable   = (bool)true,
        /**< @brief:This parameter is used to enable the error type of the pmc. */
        .PmcErrorActionType   = SAF_PMC_ERROR_ACTION_IS_DESTRUCTIVE_RESET
};

#ifdef __cplusplus
}
#endif


/**
****************************************************************************************
 * @FilePath: SafetyFccuTst_Cfg.h
 * @Author: CCORE
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety FCCU configuration head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAFETYFCCUTST_CFG_H
#define SAFETYFCCUTST_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/ 
#include "saf_userservice_callback.h"

/**
****************************************************************************************
* @brief: Macros
****************************************************************************************
*/

/* The number of configured fccu channels */
#ifdef CCFC3012PT
#define SAFETYFCCUTST_CFG_CHANNEL_COUNT       (15U)
#else
#define SAFETYFCCUTST_CFG_CHANNEL_COUNT       (1U)
#endif

/* Master core Id */
#define SAFETYFCCUTST_MASTER_CORE_ID          (0U)

/* Stack monitor status*/
#define STACK_MONITOR_ENABLE                  (STD_OFF)


#ifdef __cplusplus
}
#endif

#endif  /* SAFETYFCCUTST_CFG_H */

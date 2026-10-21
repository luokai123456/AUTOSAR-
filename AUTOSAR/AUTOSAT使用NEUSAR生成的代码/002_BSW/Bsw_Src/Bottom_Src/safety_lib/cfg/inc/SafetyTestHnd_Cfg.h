/**
****************************************************************************************
 * @FilePath: SafetyTestHnd_Cfg.h
 * @Author: CCORE
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety test handle configuration head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAFETYTESTHND_CFG_H
#define SAFETYTESTHND_CFG_H

#ifdef __cplusplus
extern "C"{
#endif
/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/ 

/**
****************************************************************************************
* @brief: Macros
****************************************************************************************
*/

/* Total number of prestartup tests */
#define SAFETYTESTHND_TOTAL_PRESTARTUP_TESTS   (1U)

/* Total number of startup1 tests */
#define SAFETYTESTHND_TOTAL_STARTUP_TESTS      (16U)

/* Total number of run-time tests */
#define SAFETYTESTHND_TOTAL_RUNTIME_TESTS      (6U)

/* Master core Id */
#define SAFETYTESTHND_MASTER_CORE_ID           (0U)


#ifdef __cplusplus
}
#endif

#endif  /* SAFETYTESTHND_CFG_H */

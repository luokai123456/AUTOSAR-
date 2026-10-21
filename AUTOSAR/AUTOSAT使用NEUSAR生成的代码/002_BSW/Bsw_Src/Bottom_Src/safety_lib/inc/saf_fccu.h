/**
****************************************************************************************
 * @FilePath: saf_fccu.h
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: FCCU Head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_FCCU_H
#define SAF_FCCU_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_cpu.h"
#include "fccu_lld.h"
/**
****************************************************************************************
 * @brief: Macros
****************************************************************************************
*/
#define SAF_REG_BIT_WIDTH                                   (32U)
#define SAF_FCCU_RF_STATUS_REG_COUNT                        (3U)
#define SAF_FCCU_RF_MAX_SIZE                                (SAF_REG_BIT_WIDTH * SAF_FCCU_RF_STATUS_REG_COUNT)
#define SAF_FCCU_RFS_REACTION_MASK                          (0x3)

#define SAF_FCCU_RFS_NO_FAILURE                  (0x0U)
#define SAF_FCCU_RFS_FAILURE_BIT                 (0x1U)
#define SAF_FCCU_RFS_FUNC_RESET_FLAG             (1U)
#define SAF_FCCU_CLEAR_FUNC_RESET_FLAG           (0U)

#define SAF_FCCU_BASE_PTRS   ((struct FCCU_tag *)     0xFBF58000UL)

#define SAF_FCCU_RF_EN_REG(idx)       ((uint8_t)((idx) >> 5U))
#define SAF_FCCU_RF_EN_BIT(idx)       ((uint8_t)((idx) & 0x1FU))
#define SAF_FCCU_RFS_CFGN_REG(idx)    ((uint8_t)((idx) >> 4U))
#define SAF_FCCU_RFS_CFGN_BIT(idx)    ((uint8_t)((idx) & 0xFU) << 1U)

#define SAF_FCCU_MASKCODE 0xFF

/**
****************************************************************************************
 * @brief: Global Variable
****************************************************************************************
*/
extern fccu_config_t realfccuCfg;
extern fccu_rf_config_t realFccuRfCfg[SAF_FCCU_RF_MAX_SIZE];

/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/
/**
* @brief  FCCU RF test result structure.
*/
typedef struct
{
	/**
    * @brief Rf test result bit map. Bit0-Bit31:Rftet0-Rftet31 result Bit32-Bit55:Rftet32-Rftet55 result
    */
	uint32_t rfFailureBitmap[SAF_FCCU_RF_STATUS_REG_COUNT];
} saf_fccu_rf_test_result_t;

/**
* @brief  FCCU RF test structure.
*/
typedef struct
{
	/**
    * @brief Number of Rf test
    */
	uint32_t testRfCnt;
	/**
    * @brief Rf test channel ID list
    */
    uint8_t  faultIDList[SAF_FCCU_RF_MAX_SIZE];
} saf_fccu_rf_test_t;
typedef  struct FCCU_tag  FCCU_Type;
/**
****************************************************************************************
 * @brief: Function prototypes
****************************************************************************************
*/
boolean SAF_FCCU_RfIsConfigured(const uint8_t faultIdx);

FS_STATUS SAF_FCCU_InjectFault(const uint8_t faultIdx);

FS_STATUS SAF_FCCU_DetectFault(const uint8_t faultIdx);

FS_STATUS SAF_FCCU_RestoreFault(const uint8_t faultIdx);

FS_STATUS SAF_FCCU_DetectAllChannelFault(void);

FS_STATUS SAF_FCCU_ClearAllChannelFault(void);

FS_STATUS SAF_FCCU_RfErrReportPathTest(void);

FS_STATUS SAF_FCCU_RfErrReportPathTestResult(saf_fccu_rf_test_result_t *TestResult);

FS_STATUS SAF_FCCU_HardwareInit(fccu_config_t *config, fccu_rf_config_t *rfConfig);

void SAF_FCCU_CopyUninitChannelConfig(fccu_config_t* fccuStartUpCfg,fccu_rf_config_t* realRfCfg,fccu_rf_config_t* tempRfCfg, uint32_t chanOffset, uint32_t length);

#ifdef __cplusplus
}
#endif

#endif

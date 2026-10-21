/**
****************************************************************************************
 * @FilePath: saf_tsens.h
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: Tsens Head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/

#ifndef SAF_TSENS_H
#define SAF_TSENS_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_pmc.h"
#include "saf_common.h"
/*PRQA S 0722 EOF*/
/**
****************************************************************************************
 * @brief: Macros
****************************************************************************************
*/
#define SAF_TSENS_LTD_PATH_INJ_TEST_SWITCH      (SAF_SWITCH_OFF)

#define SAF_TSENS_REGISTER_ADDR                 (0xFFFA0710U)
#define SAF_TSENS_TIMEOUT_MAX_COUNT             (5000U)
#define SAF_TSENS_HIGH_TEMPERATURE_THRESHOLD        		(150)
#define SAF_TSENS_LOW_TEMPERATURE_THRESHOLD 				(-40)

#define SAF_TSENS_FCCU_TEMP_INDEX               	(0)
#define SAF_TSENS_SENS_CAL_PARAM_A_ADDR         	(0x00400000)

#define SAF_TSENS_HIGH_THRESHOLD_MASK           (0x3FU)
#define SAF_TSENS_HIGH_THRESHOLD_SHIFT          (24U)
#define SAF_TSENS_LOW_THRESHOLD_MASK            (0x1FU)
#define SAF_TSENS_LOW_THRESHOLD_SHIFT           (16U)
#define SAF_TSENS_BANDGAP_SIGNAL_SHIFT          (15U)
#define SAF_TSENS_ENABLE_MASK                   (0x1U)
#define SAF_TSENS_ENABLE_SHIFT                  (14U)

#define SAF_TSENS_HTD_150_DEGREE   					(0x2E)
#define SAF_TSENS_LTD_39_DEGREE   				    (0xA)

#define SAF_PMCDIG_GR_S_TS3               		(0x4000000)
#define SAF_PMCDIG_GR_S_TS2                   	(0x2000000)
#define SAF_PMCDIG_GR_S_TS0                   	(0x1000000)
#define SAF_TSENS_HTD_GRS_REG_MASK              (0x6000000U)
#define SAF_TSENS_LTD_GRS_REG_MASK              (0x1000000U)
#define SAF_TSENS_TEMPERATURE_MARK    	        (0x7000000U)

#define SAF_TSENS_HTD_150_TEMPRANGE             (0x2EU)
#define SAF_TSENS_HTD_SZ40_TEMPRANGE            (0x2U)
#define SAF_TSENS_LTD_45_TEMPRANGE              (0x1FU)
#define SAF_TSENS_LTD_SZ39_TEMPRANGE            (0xAU)
#define SAF_TSENS_REG_ENABLE                    (1U)
#define SAF_TSENS_REG_DISABLE                   (0U)
#define SAF_TSENS_DESTRUCTIVE_ENABLE            (0U)
#define SAF_TSENS_FUNCTION_ENABLE               (1U)
#define SAF_TSENS_EVENT_MASK                    (0U)
#define SAF_TSENS_CLEAR_EVENT_MASK              (1U)
#define SAF_TSENS_REG_INIT_VALUE                (0U)
/**
****************************************************************************************
 * @brief: Enum
****************************************************************************************
*/

/**
* @brief The temperature error reaction type.
*/
typedef enum
{
	/* Tsens error type interrupt */
    SAF_TSENS_ERROR_ACTION_IS_INTERRUPT = 0,
	/* Tsens error type destructive reset */
	SAF_TSENS_ERROR_ACTION_IS_DESTRUCTIVE_RESET,
	/* Tsens error type funcyion reset */
    SAF_TSENS_ERROR_ACTION_IS_FUNCTION_RESET,
} saf_tsens_error_action_type;
/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/
/**
* @brief The chip temperature path check test result structure.
*/
typedef struct
{
    /* The fccu path check passed of the chip temperature sensor htd */
    bool chipTempHtdFccuPathCheckPassed;
    /* The self test check passed of the chip temperature sensor htd */
    bool chipTempHtdSelfTestCheckPassed;
    /* The fccu path check passed of the chip temperature sensor ltd */
    bool chipTempLtdFccuPathCheckPassed;
    /* The self test check passed of the chip temperature sensor ltd */
    bool chipTempLtdSelfTestCheckPassed;
} saf_tsens_temp_Path_check_test_result_t;
/**
* @brief The chip temperature check test result structure.
*/
typedef struct
{
    /* The actual temperature of the temperature sensor */
    int32_t actualTemp;
    /* The htd warning flag of the temperature sensor  */
    bool TempHtdWarningFlag;
    /* The htd fault flag of the temperature sensor  */
    bool TempHtdFaultFlag;
    /* The ltd fault flag of the temperature sensor  */
    bool TempLtdFaultFlag;
} saf_tsens_temp_check_test_result_t;

/**
* @brief The temperature error config.
*/
typedef struct
{
	/* temperature sensor error config mark */
	bool TempErrorConfigMark;
} saf_tsens_temp_error_config_t;
/**
* @brief The temperature calculate result.
*/
typedef struct
{
	/* temperature calculate result */
	float TsensValue;
} saf_tsens_temp_cal_result_t;

/**
* @brief The temperature sensor error response configuration structure.
*/
typedef struct
{
	/* Enable Fccu events for temperature sensor */
	bool TsensFccuEventEnable;
    /* Error type of the temperature sensor */
	saf_tsens_error_action_type TsensErrorActionType;
} saf_tsens_error_action_type_config;

/**
****************************************************************************************
 * @brief: Function prototypes
****************************************************************************************
*/
FS_STATUS SAF_TSENS_ChipTempErrRangeTest(void);

FS_STATUS SAF_TSENS_ChipTempErrRangeTestResult(saf_tsens_temp_check_test_result_t *pTestResult);

FS_STATUS SAF_TSENS_ConfigErrActionType(const saf_tsens_error_action_type_config *actionType);

FS_STATUS SAF_TSENS_GetTsensFaultFromFccu(void);

uint32_t SAF_TSENS_GetGrsRegResult(const uint8_t pmcInst);

FS_STATUS SAF_TSENS_GetChipTempValue(saf_tsens_temp_cal_result_t *TempValue);

void SAF_TSENS_ConfigInit(void);

void SAF_TSENS_ConfigDeInit(void);

FS_STATUS SAF_TSENS_HtdPathInjTest(void);

FS_STATUS SAF_TSENS_LtdPathInjTest(void);

#ifdef __cplusplus
}
#endif

#endif

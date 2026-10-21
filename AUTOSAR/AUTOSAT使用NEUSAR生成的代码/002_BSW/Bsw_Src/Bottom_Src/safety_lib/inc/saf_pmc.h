/**
****************************************************************************************
 * @FilePath: saf_pmc.h
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: Pmc Head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/

#ifndef SAF_PMC_H
#define SAF_PMC_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_common.h"
#include "saf_ccfc30xx.h"
/**
****************************************************************************************
 * @brief: Macros
****************************************************************************************
*/
#define SAF_PMC_TIMEOUT_MAX_COUNT               (5000U)
#define SAF_PMC_FCCU_LVD_INDEX                 (1)
#define SAF_PMC_FCCU_HVD_INDEX                 (2)
#define SAF_PMC_INSTANCE_0                      (0U)
#define SAF_PMC_REG_ENABLE                      (1U)
#define SAF_PMC_REG_DISABLE                     (0U)
#define SAF_PMC_DESTRUCTIVE_ENABLE              (0U)
#define SAF_PMC_FUNCTION_ENABLE                 (1U)
#define PMC_INSTANCE_COUNT                      (1U)
#define SAF_PMC_REG_INIT_VALUE                  (0U)
#define SAF_PMC_CONFIG_ADDR                     (0xfffa0590U)
#define SAF_PMC_CONFIG1_ADDR                    (0xfffa0594U)
#define SAF_PMC_CONFIG2_ADDR                    (0xfffa0598U)
#define SAF_PMC_CONFIG5_ADDR                    (0xfffa05a4U)
#define SAF_PMC_CONFIG6_ADDR                    (0xfffa05a8U)
#define SAF_PMC_CONFIG7_ADDR                    (0xfffa05acU)
#define SAF_PMC_PBIST_VD_ZERO_MASK              (0xFFFFU)

typedef struct PMCDIG_tag PMC_tag_Type;
#define PMC_BASE_ADDR                          ((uint32_t)&PMCDIG)
#define PMC_BASE                               ((PMC_tag_Type *)PMC_BASE_ADDR)
#define PMC_BASE_ARRAY                         {PMC_BASE}

/* IE_P Bit Fields */
#define SAF_PMC_IE_P_IE_EN_MASK                  0x80000000u
#define SAF_PMC_IE_P_IE_EN_SHIFT                 31u
#define SAF_PMC_IE_P_IE_EN_WIDTH                 1u
#define SAF_PMC_IE_P_IE_EN(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_PMC_IE_P_IE_EN_SHIFT))&SAF_PMC_IE_P_IE_EN_MASK)

#define SAF_PMC_IE_P_INT_ENABLE                  0x367F9FEu

/* EPR_VD3 Bit Fields */
#define SAF_PMC_EPR_VD3_MASK                         0xC1u

/* EPR_VD4 Bit Fields */
#define SAF_PMC_EPR_VD4_MASK                         0x1u

/* EPR_VD7 Bit Fields */
#define SAF_PMC_EPR_VD7_MASK                         0x1u

/* EPR_VD8 Bit Fields */
#define SAF_PMC_EPR_VD8_MASK                         0x41u

/* EPR_VD9 Bit Fields */
#define SAF_PMC_EPR_VD9_MASK                         0x4E09u

/* EPR_VD10 Bit Fields */
#define SAF_PMC_EPR_VD10_MASK                         0x8040u

/* EPR_VD12 Bit Fields */
#define SAF_PMC_EPR_VD12_MASK                         0x40u

/* EPR_VD13 Bit Fields */
#define SAF_PMC_EPR_VD13_MASK                         0x100u

/* EPR_VD14 Bit Fields */
#define SAF_PMC_EPR_VD14_MASK                         0x8100u

/* EPR_VD15 Bit Fields */
#define SAF_PMC_EPR_VD15_MASK                         0x8001u
/**
****************************************************************************************
 * @brief: Enum
****************************************************************************************
*/

/**
* @brief The PMC error reaction type.
*/
typedef enum
{
	/* Pmc error type interrupt */
    SAF_PMC_ERROR_ACTION_IS_INTERRUPT = 0,
	/* Pmc error type destructive reset */
    SAF_PMC_ERROR_ACTION_IS_DESTRUCTIVE_RESET,/*PRQA S 0722*/
	/* Pmc error type funcyion reset */
    SAF_PMC_ERROR_ACTION_IS_FUNCTION_RESET,/*PRQA S 0722*/
} saf_pmc_error_action_type;

/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/

/**
* @brief The pmc check self test result structure.
*/
typedef struct
{
    /* The fccu path check passed of the pmc */
    bool FccuPathCheckPassed;
    /* The self test check passed of the pmc */
    bool SelfTestCheckPassed;
} saf_pmc_check_test_result_t;

/**
* @brief The pmc error response configuration structure.
*/
typedef struct
{
	/* Enable Fccu events for pmc */
	bool PmcFccuEventEnable;
    /* Error type of the pmc */
	saf_pmc_error_action_type PmcErrorActionType;
} saf_pmc_error_action_type_config;
/**
****************************************************************************************
 * @brief: Function prototypes
****************************************************************************************
*/

FS_STATUS SAF_PMC_ConfigErrActionType(const saf_pmc_error_action_type actionType);

FS_STATUS SAF_PMC_GetPmcFaultFromFccu(void);

FS_STATUS SAF_PMC_SelfTestResult(saf_pmc_check_test_result_t *pTestResult);

uint32_t SAF_PMC_GetGrsRegResult(const uint8_t pmcInst);

FS_STATUS SAF_PMC_SelfTest(void);

void SAF_PMC_ConfigInit(void);

void SAF_PMC_ConfigDeInit(void);


#ifdef __cplusplus
}
#endif

#endif

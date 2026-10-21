/**
****************************************************************************************
 * @FilePath: saf_pmc.c
 * @Author: CCORE
 * @Date: 2024-03-01
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety pmc C File
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
#include "saf_pmc.h"/*PRQA S 0380*/
#include "saf_adc.h"/*PRQA S 0380*/
#include "saf_fccu.h"
#include "console.h"
#include "intc_lld.h"
#include "SafetyCoreTst_Cfg.h"
#include "saf_ccfc30xx.h"
#include "Saf_MemMap.h"
/*PRQA S 0499,1258,1259,1281,1831,1840,1841,1881,2844 EOF*/
/*PRQA S 3332,3344,4304,4397,4404,4434,4532,4542,4543,4559 EOF*/
/**
****************************************************************************************
 * @brief: Local Variables
****************************************************************************************
*/

SAF_PMC_SEC_VAR_INIT
static PMC_tag_Type *s_pPmcRegList[PMC_INSTANCE_COUNT] = PMC_BASE_ARRAY;

SAF_PMC_SEC_VAR_INIT
static uint32_t pmcConfigAddr = SAF_PMC_CONFIG_ADDR;
SAF_PMC_SEC_VAR_INIT
static uint32_t pmcConfig1Addr = SAF_PMC_CONFIG1_ADDR;
SAF_PMC_SEC_VAR_INIT
static uint32_t pmcConfig2Addr = SAF_PMC_CONFIG2_ADDR;
SAF_PMC_SEC_VAR_INIT
static uint32_t pmcConfig5Addr = SAF_PMC_CONFIG5_ADDR;
SAF_PMC_SEC_VAR_INIT
static uint32_t pmcConfig6Addr = SAF_PMC_CONFIG6_ADDR;
SAF_PMC_SEC_VAR_INIT
static uint32_t pmcConfig7Addr = SAF_PMC_CONFIG7_ADDR;

SAF_PMC_SEC_VAR_INIT
static saf_pmc_check_test_result_t s_pmcCheckSelfTest =
{
    .FccuPathCheckPassed = false,
    .SelfTestCheckPassed = false,
};

/**
****************************************************************************************
 * @brief: Global Variable
****************************************************************************************
*/

extern  const saf_pmc_error_action_type_config s_SafPmcConfig;

/**
****************************************************************************************
 * @brief: Local Function Prototypes
****************************************************************************************
*/

static void SAF_PMC_AccessEnableInterrupt(const uint8_t pmcInst, const bool enable);

static void SAF_PMC_AccessEnableReset(const uint8_t pmcInst, const bool enable);

static void SAF_PMC_AccessConfigResetType(const uint8_t pmcInst, const saf_pmc_error_action_type actionType);

static void SAF_PMC_AccessClearEventPending(const uint8_t pmcInst);

/**
****************************************************************************************
* @brief: [SW_SM024]This function is used to enable PMC error interrupt.
* @param[in] pmcInst: pmc instance.
* @param[in] enable: true or false.
* @return void.
****************************************************************************************
*/
SAF_PMC_SEC_CODE
static void SAF_PMC_AccessEnableInterrupt(const uint8_t pmcInst, const bool enable)
{
    uint32_t regValue = s_pPmcRegList[pmcInst]->IE_P.R;

    regValue &= (uint32_t)(~(SAF_PMC_IE_P_IE_EN_MASK));
    regValue |= SAF_PMC_IE_P_IE_EN(1);
    s_pPmcRegList[pmcInst]->IE_P.R = regValue;

    if(true == enable)
    {
        s_pPmcRegList[pmcInst]->IE_P.R |= SAF_PMC_IE_P_INT_ENABLE;
        READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->IE_P.R, (SAF_PMC_IE_P_INT_ENABLE | SAF_PMC_IE_P_IE_EN_MASK));
    }
    else
    {
        s_pPmcRegList[pmcInst]->IE_P.R = SAF_PMC_REG_DISABLE;
        READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->IE_P.R, SAF_PMC_REG_DISABLE);
    }
}

/**
****************************************************************************************
* @brief: [SW_SM024]This function is used to enable PMC error reset.
* @param[in] pmcInst: pmc instance.
* @param[in] enable: true or false.
* @return void.
****************************************************************************************
*/
SAF_PMC_SEC_CODE
static void SAF_PMC_AccessEnableReset(const uint8_t pmcInst, const bool enable)
{
    uint8_t regEnable = (enable ? SAF_PMC_REG_ENABLE : SAF_PMC_REG_DISABLE);

    s_pPmcRegList[pmcInst]->REE_VD3.B.LVD3_C = regEnable;
    s_pPmcRegList[pmcInst]->REE_VD3.B.LVD3_F = regEnable;
    s_pPmcRegList[pmcInst]->REE_VD3.B.HVD3_P = regEnable;

    s_pPmcRegList[pmcInst]->REE_VD4.B.LVD4_C = regEnable;

    s_pPmcRegList[pmcInst]->REE_VD7.B.HVD7_C = regEnable;

    s_pPmcRegList[pmcInst]->REE_VD8.B.HVD8_C = regEnable;
    s_pPmcRegList[pmcInst]->REE_VD8.B.LVD8_F = regEnable;

    s_pPmcRegList[pmcInst]->REE_VD9.B.HVD9_IO5V = regEnable;
    s_pPmcRegList[pmcInst]->REE_VD9.B.HVD9_O = regEnable;
    s_pPmcRegList[pmcInst]->REE_VD9.B.HVD9_PMC = regEnable;
    s_pPmcRegList[pmcInst]->REE_VD9.B.LVD9_IO5V = regEnable;
    s_pPmcRegList[pmcInst]->REE_VD9.B.LVD9_O = regEnable;
    s_pPmcRegList[pmcInst]->REE_VD9.B.LVD9_PMC = regEnable;

    s_pPmcRegList[pmcInst]->REE_VD10.B.LVD10_A = regEnable;
    s_pPmcRegList[pmcInst]->REE_VD10.B.LVD10_F = regEnable;

    s_pPmcRegList[pmcInst]->REE_VD12.B.HVD12_F = regEnable;

    s_pPmcRegList[pmcInst]->REE_VD13.B.LVD13_IM = regEnable;

    s_pPmcRegList[pmcInst]->REE_VD14.B.LVD14_A = regEnable;
    s_pPmcRegList[pmcInst]->REE_VD14.B.HVD14_IM = regEnable;

    s_pPmcRegList[pmcInst]->REE_VD15.B.HVD15_A = regEnable;
    s_pPmcRegList[pmcInst]->REE_VD15.B.HVD15_C = regEnable;

    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD3.B.LVD3_C, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD3.B.LVD3_F, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD3.B.HVD3_P, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD4.B.LVD4_C, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD7.B.HVD7_C, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD8.B.HVD8_C, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD8.B.LVD8_F, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD9.B.HVD9_IO5V, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD9.B.HVD9_O, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD9.B.HVD9_PMC, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD9.B.LVD9_IO5V, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD9.B.LVD9_O, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD9.B.LVD9_PMC, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD10.B.LVD10_A, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD10.B.LVD10_F, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD12.B.HVD12_F, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD13.B.LVD13_IM, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD14.B.LVD14_A, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD14.B.HVD14_IM, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD15.B.HVD15_A, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->REE_VD15.B.HVD15_C, regEnable);
}
/**
****************************************************************************************
* @brief: [SW_SM024]This function is used to configure PMC error reset type.
* @param[in] pmcInst: pmc instance.
* @param[in] actionType: pmc reset type.
* @return void.
****************************************************************************************
*/
SAF_PMC_SEC_CODE
static void SAF_PMC_AccessConfigResetType(const uint8_t pmcInst, const saf_pmc_error_action_type actionType)
{
    uint8_t regEnable = SAF_PMC_DESTRUCTIVE_ENABLE;

    if(actionType == SAF_PMC_ERROR_ACTION_IS_FUNCTION_RESET)
    {
        regEnable = SAF_PMC_FUNCTION_ENABLE;
    }

    s_pPmcRegList[pmcInst]->RES_VD3.B.LVD3_C = regEnable;
    s_pPmcRegList[pmcInst]->RES_VD3.B.LVD3_F = regEnable;
    s_pPmcRegList[pmcInst]->RES_VD3.B.HVD3_P = regEnable;

    s_pPmcRegList[pmcInst]->RES_VD4.B.LVD4_C = regEnable;

    s_pPmcRegList[pmcInst]->RES_VD7.B.HVD7_C = regEnable;

    s_pPmcRegList[pmcInst]->RES_VD8.B.HVD8_C = regEnable;
    s_pPmcRegList[pmcInst]->RES_VD8.B.LVD8_F = regEnable;

    s_pPmcRegList[pmcInst]->RES_VD9.B.HVD9_O = regEnable;
    s_pPmcRegList[pmcInst]->RES_VD9.B.HVD9_IO5V = regEnable;
    s_pPmcRegList[pmcInst]->RES_VD9.B.HVD9_PMC = regEnable;

    s_pPmcRegList[pmcInst]->RES_VD12.B.HVD12_F = regEnable;

    s_pPmcRegList[pmcInst]->RES_VD13.B.LVD13_IM = regEnable;

    s_pPmcRegList[pmcInst]->RES_VD14.B.LVD14_A = regEnable;
    s_pPmcRegList[pmcInst]->RES_VD14.B.HVD14_IM = regEnable;

    s_pPmcRegList[pmcInst]->RES_VD15.B.HVD15_A = regEnable;
    s_pPmcRegList[pmcInst]->RES_VD15.B.HVD15_C = regEnable;

    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->RES_VD3.B.LVD3_C, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->RES_VD3.B.LVD3_F, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->RES_VD3.B.HVD3_P, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->RES_VD4.B.LVD4_C, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->RES_VD7.B.HVD7_C, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->RES_VD8.B.HVD8_C, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->RES_VD8.B.LVD8_F, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->RES_VD9.B.HVD9_O, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->RES_VD9.B.HVD9_IO5V, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->RES_VD9.B.HVD9_PMC, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->RES_VD12.B.HVD12_F, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->RES_VD13.B.LVD13_IM, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->RES_VD14.B.LVD14_A, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->RES_VD14.B.HVD14_IM, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->RES_VD15.B.HVD15_A, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->RES_VD15.B.HVD15_C, regEnable);
}
/**
****************************************************************************************
* @brief: [SW_SM024]This function is used to clear the pmc event suspend register.
* @param[in] pmcInst: pmc instance.
* @return void.
****************************************************************************************
*/
SAF_PMC_SEC_CODE
static void SAF_PMC_AccessClearEventPending(const uint8_t pmcInst)
{
    s_pPmcRegList[pmcInst]->EPR_VD3.R = SAF_PMC_EPR_VD3_MASK;
    s_pPmcRegList[pmcInst]->EPR_VD4.R = SAF_PMC_EPR_VD4_MASK;
    s_pPmcRegList[pmcInst]->EPR_VD7.R = SAF_PMC_EPR_VD7_MASK;
    s_pPmcRegList[pmcInst]->EPR_VD8.R = SAF_PMC_EPR_VD8_MASK;
    s_pPmcRegList[pmcInst]->EPR_VD9.R = SAF_PMC_EPR_VD9_MASK;
    s_pPmcRegList[pmcInst]->EPR_VD10.R = SAF_PMC_EPR_VD10_MASK;
    s_pPmcRegList[pmcInst]->EPR_VD12.R = SAF_PMC_EPR_VD12_MASK;
    s_pPmcRegList[pmcInst]->EPR_VD13.R = SAF_PMC_EPR_VD13_MASK;
    s_pPmcRegList[pmcInst]->EPR_VD14.R = SAF_PMC_EPR_VD14_MASK;
    s_pPmcRegList[pmcInst]->EPR_VD15.R = SAF_PMC_EPR_VD15_MASK;

    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->EPR_VD3.R, 0);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->EPR_VD4.R, 0);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->EPR_VD7.R, 0);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->EPR_VD8.R, 0);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->EPR_VD9.R, 0);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->EPR_VD10.R, 0);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->EPR_VD12.R, 0);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->EPR_VD13.R, 0);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->EPR_VD14.R, 0);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->EPR_VD15.R, 0);
}

/**
****************************************************************************************
* @brief: [SW_SM024]This function is used to modify the PMC voltage threshold.
* @return void.
****************************************************************************************
*/
#if !defined(PMC_PBIST_SUPPORTED)
SAF_PMC_SEC_CODE
static void SAF_PMC_AccessThresholdValueTrim(void)
{
    volatile uint32_t pmcConfigVoltageAddr,pmcConfig1VoltageAddr;
    volatile uint32_t pmcConfig2VoltageAddr,pmcConfig5VoltageAddr;
    volatile uint32_t pmcConfig6VoltageAddr,pmcConfig7VoltageAddr;

    pmcConfigVoltageAddr = *(volatile uint32_t *)(pmcConfigAddr);/* polyspace RTE:NIV,IDP */
    pmcConfig1VoltageAddr = *(volatile uint32_t *)(pmcConfig1Addr);/* polyspace RTE:NIV,IDP */
    pmcConfig2VoltageAddr = *(volatile uint32_t *)(pmcConfig2Addr);/* polyspace RTE:NIV,IDP */
    pmcConfig5VoltageAddr = *(volatile uint32_t *)(pmcConfig5Addr);/* polyspace RTE:NIV,IDP */
    pmcConfig6VoltageAddr = *(volatile uint32_t *)(pmcConfig6Addr);/* polyspace RTE:NIV,IDP */
    pmcConfig7VoltageAddr = *(volatile uint32_t *)(pmcConfig7Addr);/* polyspace RTE:NIV,IDP */

    /* en_lvd_pmc */
    pmcConfigVoltageAddr &= ~((uint32_t)0x1<<13);
    pmcConfigVoltageAddr |= (uint32_t)0x1<<13;
    /* pmc_lvd_trim set 4.46v*/
    pmcConfigVoltageAddr &= ~((uint32_t)0xf<<9);
    pmcConfigVoltageAddr |= (uint32_t)0x7<<9;
    /* en_hvd_pmc */
    pmcConfigVoltageAddr &= ~((uint32_t)0x1<<6);
    pmcConfigVoltageAddr |= (uint32_t)0x1<<6;
    /* pmc_hvd_trim set 5.29v*/
    pmcConfigVoltageAddr &= ~((uint32_t)0x7<<3);
    pmcConfigVoltageAddr |= (uint32_t)0x0<<3;

    /* en_lvd_avdd */
    pmcConfigVoltageAddr &= ~((uint32_t)0x1<<0);
    pmcConfigVoltageAddr |= (uint32_t)0x1<<0;
    /* avdd_lvd_trim set 4.46v*/
    pmcConfig1VoltageAddr &= ~((uint32_t)0xf<<28);
    pmcConfig1VoltageAddr |= (uint32_t)0x7<<28;
    /* en_hvd_avdd */
    pmcConfig1VoltageAddr &= ~((uint32_t)0x1<<25);
    pmcConfig1VoltageAddr |= (uint32_t)0x1<<25;
    /* avdd_hvd_trim set 5.29v*/
    pmcConfig1VoltageAddr &= ~((uint32_t)0x7<<22);
    pmcConfig1VoltageAddr |= (uint32_t)0x0<<22;

    /* en_lvd_main_io */
    pmcConfig1VoltageAddr &= ~((uint32_t)0x1<<19);
    pmcConfig1VoltageAddr |= (uint32_t)0x1<<19;
    /* main_io_lvd_trim set 4.46v*/
    pmcConfig1VoltageAddr &= ~((uint32_t)0xf<<15);
    pmcConfig1VoltageAddr |= (uint32_t)0x7<<15;
    /* en_hvd_main_io */
    pmcConfig1VoltageAddr &= ~((uint32_t)0x1<<12);
    pmcConfig1VoltageAddr |= (uint32_t)0x1<<12;
    /* main_io_hvd_trim set 5.29v*/
    pmcConfig1VoltageAddr &= ~((uint32_t)0x7<<9);
    pmcConfig1VoltageAddr |= (uint32_t)0x0<<9;

    /* en_lvd_osc */
    pmcConfig1VoltageAddr &= ~((uint32_t)0x1<<6);
    pmcConfig1VoltageAddr |= (uint32_t)0x1<<6;
    /* osc_lvd_trim set 4.46v*/
    pmcConfig1VoltageAddr &= ~((uint32_t)0xf<<2);
    pmcConfig1VoltageAddr |= (uint32_t)0x7<<2;
    /* en_hvd_osc */
    pmcConfig2VoltageAddr &= ~((uint32_t)0x1<<31);
    pmcConfig2VoltageAddr |= (uint32_t)0x1<<31;
    /* osc_hvd_trim set 5.40v*/
    pmcConfig2VoltageAddr &= ~((uint32_t)0x7<<28);
    pmcConfig2VoltageAddr |= (uint32_t)0x1<<28;

    /* en_lvd_fla */
    pmcConfig2VoltageAddr &= ~((uint32_t)0x1<<25);
    pmcConfig2VoltageAddr |= (uint32_t)0x1<<25;
    /* fla_lvd_trim set 4.46v*/
    pmcConfig2VoltageAddr &= ~((uint32_t)0xf<<21);
    pmcConfig2VoltageAddr |= (uint32_t)0x7<<21;
    /* en_hvd_fla */
    pmcConfig2VoltageAddr &= ~((uint32_t)0x1<<18);
    pmcConfig2VoltageAddr |= (uint32_t)0x1<<18;
    /* fla_hvd_trim set 3.43v*/
    pmcConfig2VoltageAddr &= ~((uint32_t)0x7<<15);
    pmcConfig2VoltageAddr |= (uint32_t)0x0<<15;

    /* en_lvd_vddc */
    pmcConfig2VoltageAddr &= ~((uint32_t)0x1<<12);
    pmcConfig2VoltageAddr |= (uint32_t)0x1<<12;
    /* vddc_lvd_trim set 1.1042v*/
    pmcConfig2VoltageAddr &= ~((uint32_t)0xf<<8);
    pmcConfig2VoltageAddr |= (uint32_t)0x7<<8;
    /* en_hvd_vddc */
    pmcConfig2VoltageAddr &= ~((uint32_t)0x1<<5);
    pmcConfig2VoltageAddr |= (uint32_t)0x1<<5;
    /* vddc_hvd_trim set 1.18v*/
    pmcConfig2VoltageAddr &= ~((uint32_t)0x7<<2);
    pmcConfig2VoltageAddr |= (uint32_t)0x0<<2;

    /* en_lvd_flex */
    pmcConfig5VoltageAddr &= ~((uint32_t)0x1<<13);
    pmcConfig5VoltageAddr |= (uint32_t)0x1<<13;
    /* flex_io_lvd_trim set 4.46v*/
    pmcConfig5VoltageAddr &= ~((uint32_t)0xf<<9);
    pmcConfig5VoltageAddr |= (uint32_t)0x7<<9;
    /* en_hvd_flex_io */
    pmcConfig5VoltageAddr &= ~((uint32_t)0x1<<6);
    pmcConfig5VoltageAddr |= (uint32_t)0x1<<6;
    /* flex_io_hvd_trim set 5.29v*/
    pmcConfig5VoltageAddr &= ~((uint32_t)0x7<<3);
    pmcConfig5VoltageAddr |= (uint32_t)0x0<<3;

    /* en_lvd_sdavdd */
    pmcConfig5VoltageAddr &= ~((uint32_t)0x1<<0);
    pmcConfig5VoltageAddr |= (uint32_t)0x1<<0;
    /* sdavdd_lvd_trim set 4.46v*/
    pmcConfig6VoltageAddr &= ~((uint32_t)0xf<<28);
    pmcConfig6VoltageAddr |= (uint32_t)0x7<<28;
    /* en_hvd_sdavdd */
    pmcConfig6VoltageAddr &= ~((uint32_t)0x1<<25);
    pmcConfig6VoltageAddr |= (uint32_t)0x1<<25;
    /* sdavdd_hvd_trim set 5.29v*/
    pmcConfig6VoltageAddr &= ~((uint32_t)0x7<<22);
    pmcConfig6VoltageAddr |= (uint32_t)0x0<<22;

    /* en_lvd_io_5v */
    pmcConfig6VoltageAddr &= ~((uint32_t)0x1<<6);
    pmcConfig6VoltageAddr |= (uint32_t)0x1<<6;
    /* io_5v_lvd_trim set 4.46v*/
    pmcConfig6VoltageAddr &= ~((uint32_t)0xf<<2);
    pmcConfig6VoltageAddr |= (uint32_t)0x7<<2;
    /* en_hvd_io_5v */
    pmcConfig7VoltageAddr &= ~((uint32_t)0x1<<31);
    pmcConfig7VoltageAddr |= (uint32_t)0x1<<31;
    /* io_5v_hvd_trim set 5.40v*/
    pmcConfig7VoltageAddr &= ~((uint32_t)0x7<<28);
    pmcConfig7VoltageAddr |= (uint32_t)0x1<<28;

    /* en_lvd_fla */
    pmcConfig7VoltageAddr &= ~((uint32_t)0x1<<25);
    pmcConfig7VoltageAddr |= (uint32_t)0x1<<25;
    /* fla_lvd_trim set 4.46v*/
    pmcConfig7VoltageAddr &= ~((uint32_t)0xf<<21);
    pmcConfig7VoltageAddr |= (uint32_t)0x7<<21;
    /* en_hvd_fla */
    pmcConfig7VoltageAddr &= ~((uint32_t)0x1<<18);
    pmcConfig7VoltageAddr |= (uint32_t)0x1<<18;
    /* fla_hvd_trim set 3.43v*/
    pmcConfig7VoltageAddr &= ~((uint32_t)0x7<<15);
    pmcConfig7VoltageAddr |= (uint32_t)0x0<<15;

    /* en_lvd_vddc_c */
    pmcConfig7VoltageAddr &= ~((uint32_t)0x1<<12);
    pmcConfig7VoltageAddr |= (uint32_t)0x1<<12;
    /* vddc_c_lvd_trim set 1.1042v*/
    pmcConfig7VoltageAddr &= ~((uint32_t)0xf<<8);
    pmcConfig7VoltageAddr |= (uint32_t)0x7<<8;
    /* en_hvd_vddc_c */
    pmcConfig7VoltageAddr &= ~((uint32_t)0x1<<5);
    pmcConfig7VoltageAddr |= (uint32_t)0x1<<5;
    /* vddc_c_hvd_trim set 1.18v*/
    pmcConfig7VoltageAddr &= ~((uint32_t)0x7<<2);
    pmcConfig7VoltageAddr |= (uint32_t)0x0<<2;

    *(volatile uint32_t *)(pmcConfigAddr) = pmcConfigVoltageAddr;/* polyspace RTE:IDP */
    *(volatile uint32_t *)(pmcConfig1Addr) = pmcConfig1VoltageAddr;/* polyspace RTE:IDP */
    *(volatile uint32_t *)(pmcConfig2Addr) = pmcConfig2VoltageAddr;/* polyspace RTE:IDP */
    *(volatile uint32_t *)(pmcConfig5Addr) = pmcConfig5VoltageAddr;/* polyspace RTE:IDP */
    *(volatile uint32_t *)(pmcConfig6Addr) = pmcConfig6VoltageAddr;/* polyspace RTE:IDP */
    *(volatile uint32_t *)(pmcConfig7Addr) = pmcConfig7VoltageAddr;/* polyspace RTE:IDP */
}
#endif
/**
****************************************************************************************
* @brief: [SW_SM024]This function is used to restore the PMC voltage threshold.
* @return void.
****************************************************************************************
*/
SAF_PMC_SEC_CODE
static void SAF_PMC_AccessThresholdValueRecover(void)
{
    volatile uint32_t pmcConfigVoltageAddr,pmcConfig1VoltageAddr;
    volatile uint32_t pmcConfig2VoltageAddr,pmcConfig5VoltageAddr;
    volatile uint32_t pmcConfig6VoltageAddr,pmcConfig7VoltageAddr;

    pmcConfigVoltageAddr = *(volatile uint32_t *)(pmcConfigAddr);/* polyspace RTE:NIV,IDP */
    pmcConfig1VoltageAddr = *(volatile uint32_t *)(pmcConfig1Addr);/* polyspace RTE:NIV,IDP */
    pmcConfig2VoltageAddr = *(volatile uint32_t *)(pmcConfig2Addr);/* polyspace RTE:NIV,IDP */
    pmcConfig5VoltageAddr = *(volatile uint32_t *)(pmcConfig5Addr);/* polyspace RTE:NIV,IDP */
    pmcConfig6VoltageAddr = *(volatile uint32_t *)(pmcConfig6Addr);/* polyspace RTE:NIV,IDP */
    pmcConfig7VoltageAddr = *(volatile uint32_t *)(pmcConfig7Addr);/* polyspace RTE:NIV,IDP */

    /* en_lvd_pmc */
    pmcConfigVoltageAddr &= ~((uint32_t)0x1<<13);
    pmcConfigVoltageAddr |= (uint32_t)0x1<<13;
    /* pmc_lvd_trim set 2.44v*/
    pmcConfigVoltageAddr &= ~((uint32_t)0xf<<9);
    pmcConfigVoltageAddr |= (uint32_t)0x8<<9;
    /* en_hvd_pmc */
    pmcConfigVoltageAddr &= ~((uint32_t)0x1<<6);
    pmcConfigVoltageAddr |= (uint32_t)0x1<<6;
    /* pmc_hvd_trim set 6.20v*/
    pmcConfigVoltageAddr &= ~((uint32_t)0x7<<3);
    pmcConfigVoltageAddr |= (uint32_t)0x7<<3;

    /* en_lvd_avdd */
    pmcConfigVoltageAddr &= ~((uint32_t)0x1<<0);
    pmcConfigVoltageAddr |= (uint32_t)0x1<<0;
    /* avdd_lvd_trim set 2.44v*/
    pmcConfig1VoltageAddr &= ~((uint32_t)0xf<<28);
    pmcConfig1VoltageAddr |= (uint32_t)0x8<<28;
    /* en_hvd_avdd */
    pmcConfig1VoltageAddr &= ~((uint32_t)0x1<<25);
    pmcConfig1VoltageAddr |= (uint32_t)0x1<<25;
    /* avdd_hvd_trim set 6.20v*/
    pmcConfig1VoltageAddr &= ~((uint32_t)0x7<<22);
    pmcConfig1VoltageAddr |= (uint32_t)0x7<<22;

    /* en_lvd_main_io */
    pmcConfig1VoltageAddr &= ~((uint32_t)0x1<<19);
    pmcConfig1VoltageAddr |= (uint32_t)0x1<<19;
    /* main_io_lvd_trim set 2.44v*/
    pmcConfig1VoltageAddr &= ~((uint32_t)0xf<<15);
    pmcConfig1VoltageAddr |= (uint32_t)0x8<<15;
    /* en_hvd_main_io */
    pmcConfig1VoltageAddr &= ~((uint32_t)0x1<<12);
    pmcConfig1VoltageAddr |= (uint32_t)0x1<<12;
    /* main_io_hvd_trim set 6.20v*/
    pmcConfig1VoltageAddr &= ~((uint32_t)0x7<<9);
    pmcConfig1VoltageAddr |= (uint32_t)0x7<<9;

    /* en_lvd_osc */
    pmcConfig1VoltageAddr &= ~((uint32_t)0x1<<6);
    pmcConfig1VoltageAddr |= (uint32_t)0x1<<6;
    /* osc_lvd_trim set 2.44v*/
    pmcConfig1VoltageAddr &= ~((uint32_t)0xf<<2);
    pmcConfig1VoltageAddr |= (uint32_t)0x8<<2;
    /* en_hvd_osc */
    pmcConfig2VoltageAddr &= ~((uint32_t)0x1<<31);
    pmcConfig2VoltageAddr |= (uint32_t)0x1<<31;
    /* osc_hvd_trim set 6.20v*/
    pmcConfig2VoltageAddr &= ~((uint32_t)0x7<<28);
    pmcConfig2VoltageAddr |= (uint32_t)0x7<<28;

    /* en_lvd_fla */
    pmcConfig2VoltageAddr &= ~((uint32_t)0x1<<25);
    pmcConfig2VoltageAddr |= (uint32_t)0x1<<25;
    /* fla_lvd_trim set 2.44v*/
    pmcConfig2VoltageAddr &= ~((uint32_t)0xf<<21);
    pmcConfig2VoltageAddr |= (uint32_t)0x8<<21;
    /* en_hvd_fla */
    pmcConfig2VoltageAddr &= ~((uint32_t)0x1<<18);
    pmcConfig2VoltageAddr |= (uint32_t)0x1<<18;
    /* fla_hvd_trim set 4.05v*/
    pmcConfig2VoltageAddr &= ~((uint32_t)0x7<<15);
    pmcConfig2VoltageAddr |= (uint32_t)0x7<<15;

    /* en_lvd_vddc */
    pmcConfig2VoltageAddr &= ~((uint32_t)0x1<<12);
    pmcConfig2VoltageAddr |= (uint32_t)0x1<<12;
    /* vddc_lvd_trim set 0.9105v*/
    pmcConfig2VoltageAddr &= ~((uint32_t)0xf<<8);
    pmcConfig2VoltageAddr |= (uint32_t)0x8<<8;
    /* en_hvd_vddc */
    pmcConfig2VoltageAddr &= ~((uint32_t)0x1<<5);
    pmcConfig2VoltageAddr |= (uint32_t)0x1<<5;
    /* vddc_hvd_trim set 1.45v*/
    pmcConfig2VoltageAddr &= ~((uint32_t)0x7<<2);
    pmcConfig2VoltageAddr |= (uint32_t)0x7<<2;

    /* en_lvd_flex */
    pmcConfig5VoltageAddr &= ~((uint32_t)0x1<<13);
    pmcConfig5VoltageAddr |= (uint32_t)0x1<<13;
    /* flex_io_lvd_trim set 2.54v*/
    pmcConfig5VoltageAddr &= ~((uint32_t)0xf<<9);
    pmcConfig5VoltageAddr |= (uint32_t)0x9<<9;
    /* en_hvd_flex_io */
    pmcConfig5VoltageAddr &= ~((uint32_t)0x1<<6);
    pmcConfig5VoltageAddr |= (uint32_t)0x1<<6;
    /* flex_io_hvd_trim set 6.20v*/
    pmcConfig5VoltageAddr &= ~((uint32_t)0x7<<3);
    pmcConfig5VoltageAddr |= (uint32_t)0x7<<3;

    /* en_lvd_sdavdd */
    pmcConfig5VoltageAddr &= ~((uint32_t)0x1<<0);
    pmcConfig5VoltageAddr |= (uint32_t)0x1<<0;
    /* sdavdd_lvd_trim set 2.44v*/
    pmcConfig6VoltageAddr &= ~((uint32_t)0xf<<28);
    pmcConfig6VoltageAddr |= (uint32_t)0x8<<28;
    /* en_hvd_sdavdd */
    pmcConfig6VoltageAddr &= ~((uint32_t)0x1<<25);
    pmcConfig6VoltageAddr |= (uint32_t)0x1<<25;
    /* sdavdd_hvd_trim set 6.20v*/
    pmcConfig6VoltageAddr &= ~((uint32_t)0x7<<22);
    pmcConfig6VoltageAddr |= (uint32_t)0x7<<22;

    /* en_lvd_io_5v */
    pmcConfig6VoltageAddr &= ~((uint32_t)0x1<<6);
    pmcConfig6VoltageAddr |= (uint32_t)0x1<<6;
    /* io_5v_lvd_trim set 2.44v*/
    pmcConfig6VoltageAddr &= ~((uint32_t)0xf<<2);
    pmcConfig6VoltageAddr |= (uint32_t)0x8<<2;
    /* en_hvd_io_5v */
    pmcConfig7VoltageAddr &= ~((uint32_t)0x1<<31);
    pmcConfig7VoltageAddr |= (uint32_t)0x1<<31;
    /* io_5v_hvd_trim set 6.20v*/
    pmcConfig7VoltageAddr &= ~((uint32_t)0x7<<28);
    pmcConfig7VoltageAddr |= (uint32_t)0x7<<28;

    /* en_lvd_fla */
    pmcConfig7VoltageAddr &= ~((uint32_t)0x1<<25);
    pmcConfig7VoltageAddr |= (uint32_t)0x1<<25;
    /* fla_lvd_trim set 2.44v*/
    pmcConfig7VoltageAddr &= ~((uint32_t)0xf<<21);
    pmcConfig7VoltageAddr |= (uint32_t)0x8<<21;
    /* en_hvd_fla */
    pmcConfig7VoltageAddr &= ~((uint32_t)0x1<<18);
    pmcConfig7VoltageAddr |= (uint32_t)0x1<<18;
    /* fla_hvd_trim set 4.05v*/
    pmcConfig7VoltageAddr &= ~((uint32_t)0x7<<15);
    pmcConfig7VoltageAddr |= (uint32_t)0x7<<15;

    /* en_lvd_vddc_c */
    pmcConfig7VoltageAddr &= ~((uint32_t)0x1<<12);
    pmcConfig7VoltageAddr |= (uint32_t)0x1<<12;
    /* vddc_c_lvd_trim set 0.9105v*/
    pmcConfig7VoltageAddr &= ~((uint32_t)0xf<<8);
    pmcConfig7VoltageAddr |= (uint32_t)0x8<<8;
    /* en_hvd_vddc_c */
    pmcConfig7VoltageAddr &= ~((uint32_t)0x1<<5);
    pmcConfig7VoltageAddr |= (uint32_t)0x1<<5;
    /* vddc_c_hvd_trim set 1.45v*/
    pmcConfig7VoltageAddr &= ~((uint32_t)0x7<<2);
    pmcConfig7VoltageAddr |= (uint32_t)0x7<<2;

    *(volatile uint32_t *)(pmcConfigAddr) = pmcConfigVoltageAddr;/* polyspace RTE:IDP */
    *(volatile uint32_t *)(pmcConfig1Addr) = pmcConfig1VoltageAddr;/* polyspace RTE:IDP */
    *(volatile uint32_t *)(pmcConfig2Addr) = pmcConfig2VoltageAddr;/* polyspace RTE:IDP */
    *(volatile uint32_t *)(pmcConfig5Addr) = pmcConfig5VoltageAddr;/* polyspace RTE:IDP */
    *(volatile uint32_t *)(pmcConfig6Addr) = pmcConfig6VoltageAddr;/* polyspace RTE:IDP */
    *(volatile uint32_t *)(pmcConfig7Addr) = pmcConfig7VoltageAddr;/* polyspace RTE:IDP */
}

/**
****************************************************************************************
* @brief[SW_SM024] This function is used to set the pmc voltage threshold.
* @return void.
****************************************************************************************
*/
static void SAF_PMC_AccessSetThresholdValue(void)
{
    volatile uint32_t pmcConfigVoltageAddr,pmcConfig1VoltageAddr;
    volatile uint32_t pmcConfig2VoltageAddr,pmcConfig5VoltageAddr;
    volatile uint32_t pmcConfig6VoltageAddr,pmcConfig7VoltageAddr;

    pmcConfigVoltageAddr = *(volatile uint32_t *)(pmcConfigAddr);/* polyspace RTE:NIV,IDP */
    pmcConfig1VoltageAddr = *(volatile uint32_t *)(pmcConfig1Addr);/* polyspace RTE:NIV,IDP */
    pmcConfig2VoltageAddr = *(volatile uint32_t *)(pmcConfig2Addr);/* polyspace RTE:NIV,IDP */
    pmcConfig5VoltageAddr = *(volatile uint32_t *)(pmcConfig5Addr);/* polyspace RTE:NIV,IDP */
    pmcConfig6VoltageAddr = *(volatile uint32_t *)(pmcConfig6Addr);/* polyspace RTE:NIV,IDP */
    pmcConfig7VoltageAddr = *(volatile uint32_t *)(pmcConfig7Addr);/* polyspace RTE:NIV,IDP */

    /* en_lvd_pmc */
    pmcConfigVoltageAddr &= ~((uint32_t)0x1<<13);
    pmcConfigVoltageAddr |= (uint32_t)0x1<<13;
    pmcConfigVoltageAddr &= ~((uint32_t)0xf<<9);
    pmcConfigVoltageAddr |= (uint32_t)PMC_LVD_TRIM<<9;
    /* en_hvd_pmc */
    pmcConfigVoltageAddr &= ~((uint32_t)0x1<<6);
    pmcConfigVoltageAddr |= (uint32_t)0x1<<6;
    pmcConfigVoltageAddr &= ~((uint32_t)0x7<<3);
    pmcConfigVoltageAddr |= (uint32_t)PMC_HVD_TRIM<<3;
    /* en_lvd_avdd */
    pmcConfigVoltageAddr &= ~((uint32_t)0x1<<0);
    pmcConfigVoltageAddr |= (uint32_t)0x1<<0;
    pmcConfig1VoltageAddr &= ~((uint32_t)0xf<<28);
    pmcConfig1VoltageAddr |= (uint32_t)AVDD_LVD_TRIM<<28;
    /* en_hvd_avdd */
    pmcConfig1VoltageAddr &= ~((uint32_t)0x1<<25);
    pmcConfig1VoltageAddr |= (uint32_t)0x1<<25;
    pmcConfig1VoltageAddr &= ~((uint32_t)0x7<<22);
    pmcConfig1VoltageAddr |= (uint32_t)AVDD_HVD_TRIM<<22;
    /* en_lvd_main_io */
    pmcConfig1VoltageAddr &= ~((uint32_t)0x1<<19);
    pmcConfig1VoltageAddr |= (uint32_t)0x1<<19;
    pmcConfig1VoltageAddr &= ~((uint32_t)0xf<<15);
    pmcConfig1VoltageAddr |= (uint32_t)MAIN_IO_LVD_TRIM<<15;
    /* en_hvd_main_io */
    pmcConfig1VoltageAddr &= ~((uint32_t)0x1<<12);
    pmcConfig1VoltageAddr |= (uint32_t)0x1<<12;
    pmcConfig1VoltageAddr &= ~((uint32_t)0x7<<9);
    pmcConfig1VoltageAddr |= (uint32_t)MAIN_IO_HVD_TRIM<<9;
    /* en_lvd_osc */
    pmcConfig1VoltageAddr &= ~((uint32_t)0x1<<6);
    pmcConfig1VoltageAddr |= (uint32_t)0x1<<6;
    pmcConfig1VoltageAddr &= ~((uint32_t)0xf<<2);
    pmcConfig1VoltageAddr |= (uint32_t)OSC_LVD_TRIM<<2;
    /* en_hvd_osc */
    pmcConfig2VoltageAddr &= ~((uint32_t)0x1<<31);
    pmcConfig2VoltageAddr |= (uint32_t)0x1<<31;
    pmcConfig2VoltageAddr &= ~((uint32_t)0x7<<28);
    pmcConfig2VoltageAddr |= (uint32_t)OSC_HVD_TRIM<<28;
    /* en_lvd_fla */
    pmcConfig2VoltageAddr &= ~((uint32_t)0x1<<25);
    pmcConfig2VoltageAddr |= (uint32_t)0x1<<25;
    pmcConfig2VoltageAddr &= ~((uint32_t)0xf<<21);
    pmcConfig2VoltageAddr |= (uint32_t)FLA_LVD_TRIM<<21;
    /* en_hvd_fla */
    pmcConfig2VoltageAddr &= ~((uint32_t)0x1<<18);
    pmcConfig2VoltageAddr |= (uint32_t)0x1<<18;
    pmcConfig2VoltageAddr &= ~((uint32_t)0x7<<15);
    pmcConfig2VoltageAddr |= (uint32_t)FLA_HVD_TRIM<<15;
    /* en_lvd_vddc */
    pmcConfig2VoltageAddr &= ~((uint32_t)0x1<<12);
    pmcConfig2VoltageAddr |= (uint32_t)0x1<<12;
    pmcConfig2VoltageAddr &= ~((uint32_t)0xf<<8);
    pmcConfig2VoltageAddr |= (uint32_t)VDDC_LVD_TRIM<<8;
    /* en_hvd_vddc */
    pmcConfig2VoltageAddr &= ~((uint32_t)0x1<<5);
    pmcConfig2VoltageAddr |= (uint32_t)0x1<<5;
    pmcConfig2VoltageAddr &= ~((uint32_t)0x7<<2);
    pmcConfig2VoltageAddr |= (uint32_t)VDDC_HVD_TRIM<<2;
    /* en_lvd_flex */
    pmcConfig5VoltageAddr &= ~((uint32_t)0x1<<13);
    pmcConfig5VoltageAddr |= (uint32_t)0x1<<13;
    pmcConfig5VoltageAddr &= ~((uint32_t)0xf<<9);
    pmcConfig5VoltageAddr |= (uint32_t)FLEX_IO_LVD_TRIM<<9;
    /* en_hvd_flex_io */
    pmcConfig5VoltageAddr &= ~((uint32_t)0x1<<6);
    pmcConfig5VoltageAddr |= (uint32_t)0x1<<6;
    pmcConfig5VoltageAddr &= ~((uint32_t)0x7<<3);
    pmcConfig5VoltageAddr |= (uint32_t)FLEX_IO_HVD_TRIM<<3;
    /* en_lvd_sdavdd */
    pmcConfig5VoltageAddr &= ~((uint32_t)0x1<<0);
    pmcConfig5VoltageAddr |= (uint32_t)0x1<<0;
    pmcConfig6VoltageAddr &= ~((uint32_t)0xf<<28);
    pmcConfig6VoltageAddr |= (uint32_t)SDAVDD_LVD_TRIM<<28;
    /* en_hvd_sdavdd */
    pmcConfig6VoltageAddr &= ~((uint32_t)0x1<<25);
    pmcConfig6VoltageAddr |= (uint32_t)0x1<<25;
    pmcConfig6VoltageAddr &= ~((uint32_t)0x7<<22);
    pmcConfig6VoltageAddr |= (uint32_t)SDAVDD_HVD_TRIM<<22;
    /* en_vd_io_5v */
    pmcConfig6VoltageAddr &= ~((uint32_t)0x1<<6);
    pmcConfig6VoltageAddr |= (uint32_t)0x1<<6;
    pmcConfig6VoltageAddr &= ~((uint32_t)0xf<<2);
    pmcConfig6VoltageAddr |= (uint32_t)IO_5V_LVD_TRIM<<2;
    /* en_hvd_io_5v */
    pmcConfig7VoltageAddr &= ~((uint32_t)0x1<<31);
    pmcConfig7VoltageAddr |= (uint32_t)0x1<<31;
    pmcConfig7VoltageAddr &= ~((uint32_t)0x7<<28);
    pmcConfig7VoltageAddr |= (uint32_t)IO_5V_HVD_TRIM<<28;
    /* en_lvd_fla */
    pmcConfig7VoltageAddr &= ~((uint32_t)0x1<<25);
    pmcConfig7VoltageAddr |= (uint32_t)0x1<<25;
    pmcConfig7VoltageAddr &= ~((uint32_t)0xf<<21);
    pmcConfig7VoltageAddr |= (uint32_t)FLA_LVD_TRIM<<21;
    /* en_hvd_fla */
    pmcConfig7VoltageAddr &= ~((uint32_t)0x1<<18);
    pmcConfig7VoltageAddr |= (uint32_t)0x1<<18;
    pmcConfig7VoltageAddr &= ~((uint32_t)0x7<<15);
    pmcConfig7VoltageAddr |= (uint32_t)FLA_HVD_TRIM<<15;
    /* en_lvd_vddc_c */
    pmcConfig7VoltageAddr &= ~((uint32_t)0x1<<12);
    pmcConfig7VoltageAddr |= (uint32_t)0x1<<12;
    pmcConfig7VoltageAddr &= ~((uint32_t)0xf<<8);
    pmcConfig7VoltageAddr |= (uint32_t)VDDC_C_LVD_TRIM<<8;
    /* en_hvd_vddc_c */
    pmcConfig7VoltageAddr &= ~((uint32_t)0x1<<5);
    pmcConfig7VoltageAddr |= (uint32_t)0x1<<5;
    pmcConfig7VoltageAddr &= ~((uint32_t)0x7<<2);
    pmcConfig7VoltageAddr |= (uint32_t)VDDC_C_HVD_TRIM<<2;

    *(volatile uint32_t *)(pmcConfigAddr) = pmcConfigVoltageAddr;/* polyspace RTE:IDP */
    *(volatile uint32_t *)(pmcConfig1Addr) = pmcConfig1VoltageAddr;/* polyspace RTE:IDP */
    *(volatile uint32_t *)(pmcConfig2Addr) = pmcConfig2VoltageAddr;/* polyspace RTE:IDP */
    *(volatile uint32_t *)(pmcConfig5Addr) = pmcConfig5VoltageAddr;/* polyspace RTE:IDP */
    *(volatile uint32_t *)(pmcConfig6Addr) = pmcConfig6VoltageAddr;/* polyspace RTE:IDP */
    *(volatile uint32_t *)(pmcConfig7Addr) = pmcConfig7VoltageAddr;/* polyspace RTE:IDP */
}

/**
****************************************************************************************
* @brief: [SW_SM024]This function enables the Fccu event function for a pmc.
* @param[in] pmcInst:pmc instance.
* @param[in] enable:true or false.
* @return void.
****************************************************************************************
*/
SAF_PMC_SEC_CODE
static void SAF_PMC_AccessFccuEventEnable(const uint8_t pmcInst,const bool enable)
{
    uint8_t regEnable = (enable ? SAF_PMC_REG_ENABLE : SAF_PMC_REG_DISABLE);

    s_pPmcRegList[pmcInst]->FEE_VD3.B.FEE3_C = regEnable;
    s_pPmcRegList[pmcInst]->FEE_VD3.B.FEE3_F = regEnable;
    s_pPmcRegList[pmcInst]->FEE_VD3.B.FEE3_P = regEnable;

    s_pPmcRegList[pmcInst]->FEE_VD4.B.FEE4_C = regEnable;

    s_pPmcRegList[pmcInst]->FEE_VD7.B.FEE7_C = regEnable;
    s_pPmcRegList[pmcInst]->FEE_VD8.B.FEE8_C = regEnable;
    s_pPmcRegList[pmcInst]->FEE_VD8.B.FEE8_F = regEnable;

    s_pPmcRegList[pmcInst]->FEE_VD9.B.FEE9_O = regEnable;
    s_pPmcRegList[pmcInst]->FEE_VD9.B.FEE9_O_H = regEnable;
    s_pPmcRegList[pmcInst]->FEE_VD9.B.FEE9_IO5V = regEnable;
    s_pPmcRegList[pmcInst]->FEE_VD9.B.FEE9_IO5V_H = regEnable;
    s_pPmcRegList[pmcInst]->FEE_VD9.B.FEE9_PMC = regEnable;
    s_pPmcRegList[pmcInst]->FEE_VD9.B.FEE9_PMC_H = regEnable;

    s_pPmcRegList[pmcInst]->FEE_VD10.B.FEE10_A = regEnable;
    s_pPmcRegList[pmcInst]->FEE_VD10.B.FEE10_F = regEnable;

    s_pPmcRegList[pmcInst]->FEE_VD12.B.FEE12_F = regEnable;

    s_pPmcRegList[pmcInst]->FEE_VD13.B.FEE13_IM = regEnable;

    s_pPmcRegList[pmcInst]->FEE_VD14.B.FEE14_A = regEnable;
    s_pPmcRegList[pmcInst]->FEE_VD14.B.FEE14_IM = regEnable;

    s_pPmcRegList[pmcInst]->FEE_VD15.B.FEE15_A = regEnable;
    s_pPmcRegList[pmcInst]->FEE_VD15.B.FEE15_C = regEnable;

    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD3.B.FEE3_C, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD3.B.FEE3_F, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD3.B.FEE3_P, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD4.B.FEE4_C, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD7.B.FEE7_C, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD8.B.FEE8_C, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD8.B.FEE8_F, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD9.B.FEE9_O, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD9.B.FEE9_O_H, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD9.B.FEE9_IO5V, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD9.B.FEE9_IO5V_H, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD9.B.FEE9_PMC, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD9.B.FEE9_PMC_H, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD10.B.FEE10_A, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD10.B.FEE10_F, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD12.B.FEE12_F, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD13.B.FEE13_IM, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD14.B.FEE14_A, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD14.B.FEE14_IM, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD15.B.FEE15_A, regEnable);
    READ_AFTER_WRITE_ASSERT(s_pPmcRegList[pmcInst]->FEE_VD15.B.FEE15_C, regEnable);
}

/**
****************************************************************************************
 * @brief: Global Functions
****************************************************************************************
*/

/**
****************************************************************************************
* @brief: [SW_SM024]This function is used to configure the PMC error reaction type.
* Including interrupt and reset.
* @param[in] actionType: error response type.
* @return FS_STATUS: FS_STATUS_SUCCESS :config success.
*                    FS_STATUS_ERROR :config failed.
****************************************************************************************
*/
SAF_PMC_SEC_CODE
static FS_STATUS SAF_PMC_AccessConfigErrActionType(const saf_pmc_error_action_type actionType)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    bool enableReset = (bool)false, enableInt = (bool)false;

    if (SAF_PMC_ERROR_ACTION_IS_INTERRUPT == actionType)
    {
        enableInt = (bool)true;
    }
    else if (SAF_PMC_ERROR_ACTION_IS_DESTRUCTIVE_RESET == actionType)
    {
        enableReset = (bool)true;
    }
    else if (SAF_PMC_ERROR_ACTION_IS_FUNCTION_RESET == actionType)
    {
        enableReset = (bool)true;
    }
    else
    {
    	status = FS_STATUS_ERROR;
    }

    if (FS_STATUS_SUCCESS == status)
	{
		SAF_PMC_AccessClearEventPending(SAF_PMC_INSTANCE_0);

		SAF_PMC_AccessEnableInterrupt(SAF_PMC_INSTANCE_0, enableInt);

		SAF_PMC_AccessConfigResetType(SAF_PMC_INSTANCE_0, actionType);

		SAF_PMC_AccessEnableReset(SAF_PMC_INSTANCE_0, enableReset);
    }

    return status;
}

/**
****************************************************************************************
* @brief: [SW_SM024]This function gets the value of register GR_S.
* @param[in] pmcInst: pmc instance.
* @return uint32_t: value of register GR_S.
****************************************************************************************
*/
SAF_PMC_SEC_CODE
uint32_t SAF_PMC_GetGrsRegResult(const uint8_t pmcInst)
{
    uint32_t RegValue = 0;

    RegValue = (uint32_t)s_pPmcRegList[pmcInst]->GR_S.R;

    return RegValue;
}

/**
****************************************************************************************
* @brief[SW_SM024] This function is used to get pmc fault from fccu.
* @return status
*           FS_STATUS_SUCCESS: fault occurred.
            FS_STATUS_ERROR: No fault occurred.
****************************************************************************************
*/
FS_STATUS SAF_PMC_GetPmcFaultFromFccu(void)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if ((FS_STATUS_SUCCESS == SAF_FCCU_DetectFault(SAF_PMC_FCCU_HVD_INDEX)) || \
        (FS_STATUS_SUCCESS == SAF_FCCU_DetectFault(SAF_PMC_FCCU_LVD_INDEX)))
    {
        status = FS_STATUS_SUCCESS;
    }

    return status;
}

/**
****************************************************************************************
* @brief: [SW_SM024]This function is used for PMC self-test.
* @return FS_STATUS: FS_STATUS_SUCCESS :pmc self success.
*                    FS_STATUS_ERROR :pmc self failed.
****************************************************************************************
*/
SAF_PMC_SEC_CODE
FS_STATUS SAF_PMC_SelfTest(void)
{
    FS_STATUS status = FS_STATUS_ERROR;
#if PMC_PBIST_SUPPORTED
    PMC_tag_Type *pBase = s_pPmcRegList[0];
    uint32_t regvalue = 0U;
    uint32_t pbistregValue = 0U;
    uint32_t timeout = SAF_PMC_TIMEOUT_MAX_COUNT;

    FS_PMCDIG_PBIST = FS_ALL_BIST_SEL;

    FS_PMCDIG_PBIST |= FS_ALL_BIST_EN;

    timeout = SAF_PMC_TIMEOUT_MAX_COUNT;
    while ((timeout > 0U) && ((pBase->VD_UTST.R & FS_PMCDIG_VD_UTEST_ALLEVENT_MASK) != FS_PMCDIG_VD_UTEST_ALLEVENT_MASK))
    {
        timeout--;
    }

    regvalue = (pBase->VD_UTST.R & FS_PMCDIG_VD_UTEST_ALLEVENT_MASK);

    if (FS_PMCDIG_VD_UTEST_ALLEVENT_MASK == regvalue)
    {
    	status = FS_STATUS_SUCCESS;
    }
    else if (0U == timeout)
    {
    	status = FS_STATUS_TIMEOUT;
    }
    else
    {
    	status = FS_STATUS_ERROR;
    }

    FS_PMCDIG_PBIST = FS_PBIST_RESET;
    pbistregValue = FS_PMCDIG_PBIST;
    timeout = SAF_PMC_TIMEOUT_MAX_COUNT;
    while ((timeout > 0U) && ((pBase->VD_UTST.R & SAF_PMC_PBIST_VD_ZERO_MASK) != 0U))
    {
        timeout--;
    }

    regvalue = (pBase->VD_UTST.R & SAF_PMC_PBIST_VD_ZERO_MASK);

    if ((0U == regvalue) && (0U == pbistregValue) && (FS_STATUS_SUCCESS == status))
    {
    	status = FS_STATUS_SUCCESS;
    }
    else
    {
        if (status != FS_STATUS_TIMEOUT)
        {
            status = FS_STATUS_ERROR;
        }
    }

#else
	saf_pmc_check_test_result_t *pResult = &s_pmcCheckSelfTest;
	uint32_t Timeout = 0;
    uint32_t regValue = 0;

    status = SAF_PMC_AccessConfigErrActionType(SAF_PMC_ERROR_ACTION_IS_INTERRUPT);

	SAF_PMC_AccessFccuEventEnable(SAF_PMC_INSTANCE_0,(bool)true);

	if(FS_STATUS_SUCCESS == status)/*PRQA S 2991,2995*/
	{
        SAF_PMC_AccessThresholdValueTrim();
        while ((SAF_PMC_REG_INIT_VALUE == regValue) && (SAF_PMC_TIMEOUT_MAX_COUNT > Timeout))
        {
            regValue = SAF_PMC_GetGrsRegResult(SAF_PMC_INSTANCE_0);
            Timeout++;
        }

        SAF_PMC_AccessThresholdValueRecover();

        if(FS_STATUS_SUCCESS != SAF_PMC_GetPmcFaultFromFccu())
        {
            status = FS_STATUS_ERROR;/*PRQA S 2982*/
        }
        else
        {
            (void)SAF_FCCU_RestoreFault(SAF_PMC_FCCU_HVD_INDEX);
            (void)SAF_FCCU_RestoreFault(SAF_PMC_FCCU_LVD_INDEX);
            pResult->FccuPathCheckPassed = true;
        }

        if(regValue == SAF_PMC_REG_INIT_VALUE)
        {
            status = FS_STATUS_ERROR;/*PRQA S 2982*/
        }
        else
        {
            pResult->SelfTestCheckPassed = true;
        }
	}

	status = SAF_PMC_AccessConfigErrActionType(s_SafPmcConfig.PmcErrorActionType);

	SAF_PMC_AccessFccuEventEnable(SAF_PMC_INSTANCE_0,s_SafPmcConfig.PmcFccuEventEnable);
#endif
	return status;
}

/**
****************************************************************************************
* @brief[SW_SM024] This function is used to initialize the configuration of the pmc.
* @return void.
****************************************************************************************
*/
SAF_PMC_SEC_CODE
void SAF_PMC_ConfigInit(void)
{
    (void)SAF_PMC_AccessConfigErrActionType(s_SafPmcConfig.PmcErrorActionType);

    SAF_PMC_AccessFccuEventEnable(SAF_PMC_INSTANCE_0,SAF_PMC_FCCU_EVENT_ENABLE);

    SAF_PMC_AccessSetThresholdValue();
}

/**
****************************************************************************************
* @brief[SW_SM024] This function is used to de-initialize the configuration of the pmc.
* @return void.
****************************************************************************************
*/
SAF_PMC_SEC_CODE
void SAF_PMC_ConfigDeInit(void)
{
    SAF_PMC_AccessThresholdValueRecover();

    SAF_PMC_AccessFccuEventEnable(SAF_PMC_INSTANCE_0,true);

    (void)SAF_PMC_AccessConfigErrActionType(SAF_PMC_ERROR_ACTION_IS_DESTRUCTIVE_RESET);
}

/**
****************************************************************************************
* @brief: [SW_SM024]This function is used to get the self test result of pmc.
* @param[out] pTestResult: test parameters.
* @return FS_STATUS: FS_STATUS_SUCCESS: get success.
*                    FS_STATUS_ERROR: get failed.
****************************************************************************************
*/
SAF_PMC_SEC_CODE
FS_STATUS SAF_PMC_SelfTestResult(saf_pmc_check_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != pTestResult)
    {
        status = FS_STATUS_SUCCESS;
        memcpy(pTestResult, &s_pmcCheckSelfTest, sizeof(s_pmcCheckSelfTest));/*PRQA S 3200,0315*/
    }

    return status;
}



#ifdef __cplusplus
}
#endif

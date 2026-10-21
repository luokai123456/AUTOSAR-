/**
****************************************************************************************
 * @FilePath: saf_tsens.c
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety tsens C File
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
#include "console.h"/*PRQA S 0380*/
#include "saf_adc.h"
#include "saf_fccu.h"
#include "saf_tsens.h"
#include "Adc.h"
#include "SafetyPeriphTst_Cfg.h"
#include "Saf_MemMap.h"
/*PRQA S 0315,0499,1258,1281,1831,1841,2812,2844,1259,0491 EOF*/
/*PRQA S 3200,3218,4304,4404,4434,4454,4532,4542,4543,4559,4462 EOF*/
/**
****************************************************************************************
 * @brief: Local Variables
****************************************************************************************
*/
SAF_TSENS_SEC_VAR_INIT
static PMC_tag_Type *s_pTsensRegList[PMC_INSTANCE_COUNT] = PMC_BASE_ARRAY;
SAF_TSENS_SEC_VAR_INIT
static uint32_t tsensRegisterAddr = SAF_TSENS_REGISTER_ADDR;
SAF_TSENS_SEC_VAR_INIT
static saf_tsens_temp_Path_check_test_result_t s_tsensTempPathCheckTest =
{
    .chipTempHtdFccuPathCheckPassed = false,
    .chipTempHtdSelfTestCheckPassed = false,
    .chipTempLtdFccuPathCheckPassed = false,
    .chipTempLtdSelfTestCheckPassed = false,
};
SAF_TSENS_SEC_VAR_INIT
static saf_tsens_temp_check_test_result_t s_tsensTempCheckTest =
{
	    .TempHtdWarningFlag = false,
	    .TempHtdFaultFlag = false,
	    .TempLtdFaultFlag = false,
};/*PRQA S 0704*/

SAF_TSENS_SEC_VAR_NO_INIT
static uint16_t bandgapValue[4];

/**
****************************************************************************************
 * @brief: Global Variable
****************************************************************************************
*/

extern  const saf_tsens_error_action_type_config s_SafTsensConfig;

/**
****************************************************************************************
 * @brief: Local Function Prototypes
****************************************************************************************
*/
static void SAF_TSENS_AccessEnableInterrupt(const uint8_t pmcInst, const bool enable);

static void SAF_TSENS_AccessEnableReset(const uint8_t pmcInst, const bool enable);

static void SAF_TSENS_AccessConfigResetType(const uint8_t pmcInst, const saf_tsens_error_action_type actionType);

static void SAF_TSENS_AccessFccuEventEnable(const uint8_t pmcInst, const bool enable);

static void SAF_TSENS_AccessClearEventPending(const uint8_t pmcInst);

static FS_STATUS SAF_TSENS_AccessGetChipTemperatureValue(saf_tsens_temp_cal_result_t *pCalResult);

/**
****************************************************************************************
 * @brief: Local Functions
****************************************************************************************
*/

/**
****************************************************************************************
* @brief: [SW_SM049]This function is used to enable TSENS error interrupt.
* @param[in] pmcInst: pmc instance.
* @param[in] enable: true or false.
* @return void.
****************************************************************************************
*/
SAF_TSENS_SEC_CODE
static void SAF_TSENS_AccessEnableInterrupt(const uint8_t pmcInst, const bool enable)
{
    uint8_t regEnable = (enable ? SAF_TSENS_REG_ENABLE : SAF_TSENS_REG_DISABLE);
    uint32_t regValue = s_pTsensRegList[pmcInst]->IE_P.R;/* polyspace RTE:NIV */

    regValue &= (uint32_t)(~(SAF_PMC_IE_P_IE_EN_MASK));
    regValue |= SAF_PMC_IE_P_IE_EN(1);
    s_pTsensRegList[pmcInst]->IE_P.R = regValue;

    s_pTsensRegList[pmcInst]->CTL_TD.B.TS0IE = regEnable;
    s_pTsensRegList[pmcInst]->CTL_TD.B.TS2IE = regEnable;
    s_pTsensRegList[pmcInst]->CTL_TD.B.TS3IE = regEnable;

    READ_AFTER_WRITE_ASSERT(s_pTsensRegList[pmcInst]->IE_P.R, regValue);/* polyspace RTE:NIV */
    READ_AFTER_WRITE_ASSERT(s_pTsensRegList[pmcInst]->CTL_TD.B.TS0IE, regEnable);/* polyspace RTE:NIV */
    READ_AFTER_WRITE_ASSERT(s_pTsensRegList[pmcInst]->CTL_TD.B.TS2IE, regEnable);/* polyspace RTE:NIV */
    READ_AFTER_WRITE_ASSERT(s_pTsensRegList[pmcInst]->CTL_TD.B.TS3IE, regEnable);/* polyspace RTE:NIV */
}

/**
****************************************************************************************
* @brief[SW_SM049] This function is used to enable tsens error reset.
* @param[in] pmcInst: Pmc instance.
* @param[in] enable: Enables or disables tsens error reset.
* @return void.
****************************************************************************************
*/
SAF_TSENS_SEC_CODE
static void SAF_TSENS_AccessEnableReset(const uint8_t pmcInst, const bool enable)
{
    uint8_t regEnable = (enable ? SAF_TSENS_REG_ENABLE : SAF_TSENS_REG_DISABLE);

    s_pTsensRegList[pmcInst]->REE_TD.B.TEMP_0 = regEnable;
    s_pTsensRegList[pmcInst]->REE_TD.B.TEMP_2 = regEnable;
    s_pTsensRegList[pmcInst]->REE_TD.B.TEMP_3 = regEnable;

    READ_AFTER_WRITE_ASSERT(s_pTsensRegList[pmcInst]->REE_TD.B.TEMP_0, regEnable);/* polyspace RTE:NIV */
    READ_AFTER_WRITE_ASSERT(s_pTsensRegList[pmcInst]->REE_TD.B.TEMP_2, regEnable);/* polyspace RTE:NIV */
    READ_AFTER_WRITE_ASSERT(s_pTsensRegList[pmcInst]->REE_TD.B.TEMP_3, regEnable);/* polyspace RTE:NIV */
}

/**
****************************************************************************************
* @brief: [SW_SM049]This function is used to configure TSENS error reset type.
* @param[in] pmcInst: pmc instance.
* @param[in] actionType: tsens reset type.
* @return void.
****************************************************************************************
*/
SAF_TSENS_SEC_CODE
static void SAF_TSENS_AccessConfigResetType(const uint8_t pmcInst, const saf_tsens_error_action_type actionType)
{
	uint8_t regEnable = SAF_TSENS_DESTRUCTIVE_ENABLE;

    if(actionType == SAF_TSENS_ERROR_ACTION_IS_FUNCTION_RESET)
    {
    	regEnable = SAF_TSENS_FUNCTION_ENABLE;
    }

    s_pTsensRegList[pmcInst]->RES_TD.B.TEMP_0 = regEnable;
    s_pTsensRegList[pmcInst]->RES_TD.B.TEMP_2 = regEnable;
    s_pTsensRegList[pmcInst]->RES_TD.B.TEMP_3 = regEnable;

    READ_AFTER_WRITE_ASSERT(s_pTsensRegList[pmcInst]->RES_TD.B.TEMP_0, regEnable);/* polyspace RTE:NIV */
    READ_AFTER_WRITE_ASSERT(s_pTsensRegList[pmcInst]->RES_TD.B.TEMP_2, regEnable);/* polyspace RTE:NIV */
    READ_AFTER_WRITE_ASSERT(s_pTsensRegList[pmcInst]->RES_TD.B.TEMP_3, regEnable);/* polyspace RTE:NIV */
}

/**
****************************************************************************************
* @brief: [SW_SM049]This function is used to clear the tsens event suspend register.
* @param[in] pmcInst: pmc instance.
* @return void.
****************************************************************************************
*/
SAF_TSENS_SEC_CODE
static void SAF_TSENS_AccessClearEventPending(const uint8_t pmcInst)
{
    s_pTsensRegList[pmcInst]->EPR_TD.B.TEMP_0 = SAF_TSENS_CLEAR_EVENT_MASK;
    s_pTsensRegList[pmcInst]->EPR_TD.B.TEMP_2 = SAF_TSENS_CLEAR_EVENT_MASK;
    s_pTsensRegList[pmcInst]->EPR_TD.B.TEMP_3 = SAF_TSENS_CLEAR_EVENT_MASK;

    READ_AFTER_WRITE_ASSERT(s_pTsensRegList[pmcInst]->EPR_TD.B.TEMP_0, SAF_TSENS_EVENT_MASK);/* polyspace RTE:NIV */
    READ_AFTER_WRITE_ASSERT(s_pTsensRegList[pmcInst]->EPR_TD.B.TEMP_2, SAF_TSENS_EVENT_MASK);/* polyspace RTE:NIV */
    READ_AFTER_WRITE_ASSERT(s_pTsensRegList[pmcInst]->EPR_TD.B.TEMP_3, SAF_TSENS_EVENT_MASK);/* polyspace RTE:NIV */
}

/**
****************************************************************************************
* @brief: [SW_SM86]This function is used to get chip temperature value.
* @param[in] pCalResult: Pointer to temperature calculate result.
* @return void.
****************************************************************************************
*/
SAF_TSENS_SEC_CODE
static FS_STATUS SAF_TSENS_AccessGetChipTemperatureValue(saf_tsens_temp_cal_result_t *pCalResult)
{
    FS_STATUS status = FS_STATUS_ERROR;
    uint16_t sensResult;
    uint16_t VoltageValue;
    volatile uint16_t Adc_Shift;
	int16_t sensParamA = 0;
	const Adc_GroupConfigType *GroupConfig = &(Adc_Config.Adc_GroupConfig[0]);

	sensParamA = * ((int16_t *)SAF_TSENS_SENS_CAL_PARAM_A_ADDR);

	Adc_ReadGroup(0, bandgapValue);

#if (ADC_RESULT_ALIGNMENT == ADC_ALIGN_RIGHT)/* PRQA S 3332 */
	Adc_Shift = (uint8)(14U - (uint8)(GroupConfig->Resolution));
	VoltageValue =  ((bandgapValue[0] << Adc_Shift)* SAF_EQADC_VRH_MVOLT) / SAF_EQADC_RESOLUTION_BIT12;/*PRQA S 3393,4397,3401*/ /* polyspace RTE:OVFL,SHF */
#else
	VoltageValue =  bandgapValue[0] * SAF_EQADC_VRH_MVOLT / SAF_EQADC_RESOLUTION_BIT12;
#endif
    if ((0U != VoltageValue) && (NULL != pCalResult))
    {
    	status = FS_STATUS_SUCCESS;
    }
	if(((uint16_t)sensParamA == 0xffff) || (sensParamA == 0))/*PRQA S 2897,1853*/
	{
		pCalResult->TsensValue = ((float)VoltageValue - 862) / (-3.05);/*PRQA S 4453,1892,1800*/
	}
	else
	{
		sensResult = (((float)sensParamA * EQADC_VRH_MVOLT) / EQADC_RESOLUTION_BIT12);/*PRQA S 4454,1800*/ /* polyspace RTE:OVFL */
		sensResult = ((float)sensResult - 862) / (-3.05);/*PRQA S 4453,4454,1892,1800*/ /* polyspace RTE:OVFL */

		pCalResult->TsensValue = ((float)VoltageValue - 862) / (-3.05);/*PRQA S 4453,1892,1800*/

		pCalResult->TsensValue = pCalResult->TsensValue + (40 - sensResult);/*PRQA S 1860,1800*/
	}

    return status;
}

/**
****************************************************************************************
* @brief[SW_SM049] This function is used to modify the chip temperature threshold.
* @param[in] HtdValue: High temperature threshold.
* @param[in] LtdValue: Low temperature threshold.
* @return void.
****************************************************************************************
*/
SAF_TSENS_SEC_CODE
static void SAF_TSENS_AccessThresholdValueTrim(const uint32_t HtdValue, const uint32_t LtdValue)
{
    volatile uint32_t Value = 0u;

    Value = *(volatile uint32_t *)(tsensRegisterAddr);/* polyspace RTE:NIV,IDP */
    Value &= ~((uint32_t)SAF_TSENS_LOW_THRESHOLD_MASK << SAF_TSENS_LOW_THRESHOLD_SHIFT);
    Value &= ~((uint32_t)SAF_TSENS_HIGH_THRESHOLD_MASK << SAF_TSENS_HIGH_THRESHOLD_SHIFT);

    Value |= LtdValue << SAF_TSENS_LOW_THRESHOLD_SHIFT;
    Value |= HtdValue << SAF_TSENS_HIGH_THRESHOLD_SHIFT;
    *(volatile uint32_t *)(tsensRegisterAddr) = Value;/* polyspace RTE:IDP */

    *(volatile uint32_t*)tsensRegisterAddr &= (~((uint32_t)1 << SAF_TSENS_BANDGAP_SIGNAL_SHIFT));/* polyspace RTE:NIV,IDP */
    *(volatile uint32_t*)tsensRegisterAddr |= ((uint32_t)1 << SAF_TSENS_ENABLE_SHIFT);/* polyspace RTE:NIV,IDP */
}

/**
****************************************************************************************
* @brief[SW_SM049] This function is used to set the chip temperature threshold.
* @return void.
****************************************************************************************
*/
static void SAF_TSENS_AccessSetThresholdValue(void)
{
    volatile uint32_t Value = 0u;

    Value = *(volatile uint32_t *)(tsensRegisterAddr);/* polyspace RTE:NIV,IDP */
    Value &= ~((uint32_t)SAF_TSENS_LOW_THRESHOLD_MASK << SAF_TSENS_LOW_THRESHOLD_SHIFT);
    Value &= ~((uint32_t)SAF_TSENS_HIGH_THRESHOLD_MASK << SAF_TSENS_HIGH_THRESHOLD_SHIFT);

    Value |= (uint32_t)SAF_TSENS_LTD_SETTING << SAF_TSENS_LOW_THRESHOLD_SHIFT;
    Value |= (uint32_t)SAF_TSENS_HTD_SETTING << SAF_TSENS_HIGH_THRESHOLD_SHIFT;
    *(volatile uint32_t *)(tsensRegisterAddr) = Value;/* polyspace RTE:IDP */

    *(volatile uint32_t*)tsensRegisterAddr &= (~((uint32_t)1 << SAF_TSENS_BANDGAP_SIGNAL_SHIFT));/* polyspace RTE:NIV,IDP */
    *(volatile uint32_t*)tsensRegisterAddr |= ((uint32_t)1 << SAF_TSENS_ENABLE_SHIFT);/* polyspace RTE:NIV,IDP */
}

/**
****************************************************************************************
* @brief[SW_SM049] This function enables analog and digital output of tsens.
* @param[in] pmcInst: Pmc instance.
* @param[in] enable: Enable or disable tsens analog output and digital output.
* @return void.
****************************************************************************************
*/
SAF_TSENS_SEC_CODE
static void SAF_TSENS_AccessEnableAnalogAndDigitalOutput(const uint8_t pmcInst, const bool enable)
{
    uint8_t regEnable = (enable ? SAF_TSENS_REG_ENABLE : SAF_TSENS_REG_DISABLE);

    s_pTsensRegList[pmcInst]->CTL_TD.B.DOUT_EN = regEnable;
    s_pTsensRegList[pmcInst]->CTL_TD.B.AOUT_EN = regEnable;

    READ_AFTER_WRITE_ASSERT(s_pTsensRegList[pmcInst]->CTL_TD.B.DOUT_EN, regEnable);/* polyspace RTE:NIV */
    READ_AFTER_WRITE_ASSERT(s_pTsensRegList[pmcInst]->CTL_TD.B.AOUT_EN, regEnable);/* polyspace RTE:NIV */
}

/**
****************************************************************************************
* @brief: [SW_SM049]This function enables the Fccu event function for a temperature sensor
* @param[in] pmcInst: pmc instance.
* @param[in] enable: true or false.
* @return void.
****************************************************************************************
*/
SAF_TSENS_SEC_CODE
static void SAF_TSENS_AccessFccuEventEnable(const uint8_t pmcInst, const bool enable)
{
    uint8_t regEnable = (enable ? SAF_TSENS_REG_ENABLE : SAF_TSENS_REG_DISABLE);

    s_pTsensRegList[pmcInst]->FEE_TD.B.FEE_TS0 = regEnable;
    s_pTsensRegList[pmcInst]->FEE_TD.B.FEE_TS2 = regEnable;
    s_pTsensRegList[pmcInst]->FEE_TD.B.FEE_TS3 = regEnable;

    READ_AFTER_WRITE_ASSERT(s_pTsensRegList[pmcInst]->FEE_TD.B.FEE_TS0, regEnable);/* polyspace RTE:NIV */
    READ_AFTER_WRITE_ASSERT(s_pTsensRegList[pmcInst]->FEE_TD.B.FEE_TS2, regEnable);/* polyspace RTE:NIV */
    READ_AFTER_WRITE_ASSERT(s_pTsensRegList[pmcInst]->FEE_TD.B.FEE_TS3, regEnable);/* polyspace RTE:NIV */
}

/**
****************************************************************************************
* @brief[SW_SM049] This function is used to configure the tsens error reaction type.
                   Including interrupt and reset.
* @param[in] actionType: The type of reaction (reset or interrupt).
* @return status
            FS_STATUS_SUCCESS: Config error action type success.
            FS_STATUS_ERROR: Config error action type failed.
****************************************************************************************
*/
SAF_TSENS_SEC_CODE
static FS_STATUS SAF_TSENS_AccessConfigErrActionType(const saf_tsens_error_action_type actionType)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    bool enableReset = false, enableInt = false;

    if (SAF_TSENS_ERROR_ACTION_IS_INTERRUPT == actionType)
    {
        enableInt = true;
    }
    else if (SAF_TSENS_ERROR_ACTION_IS_DESTRUCTIVE_RESET == actionType)
    {
        enableReset = true;
    }
    else if (SAF_TSENS_ERROR_ACTION_IS_FUNCTION_RESET == actionType)
    {
        enableReset = true;
    }
    else
    {
        status = FS_STATUS_ERROR;
    }

    if (FS_STATUS_SUCCESS == status)
    {
        SAF_TSENS_AccessClearEventPending(SAF_PMC_INSTANCE_0);

        SAF_TSENS_AccessEnableInterrupt(SAF_PMC_INSTANCE_0, enableInt);

        SAF_TSENS_AccessConfigResetType(SAF_PMC_INSTANCE_0, actionType);

        SAF_TSENS_AccessEnableReset(SAF_PMC_INSTANCE_0, enableReset);
    }

    return status;
}

/**
****************************************************************************************
 * @brief: Global Functions
****************************************************************************************
*/

/**
****************************************************************************************
* @brief: [SW_SM049]This function is used to modify the chip temperature threshold.
* @return void.
****************************************************************************************
*/

/**
****************************************************************************************
* @brief: [SW_SM86]This function gets the value of register GR_S.
* @param[in] pmcInst: pmc instance.
* @return uint32_t: Returns the value of the register.
****************************************************************************************
*/
SAF_TSENS_SEC_CODE
uint32_t SAF_TSENS_GetGrsRegResult(const uint8_t pmcInst)
{
	uint32_t RegValue = 0;

	RegValue |= (((uint32_t)s_pTsensRegList[pmcInst]->GR_S.R) & SAF_PMCDIG_GR_S_TS0);/* polyspace RTE:NIV */
	RegValue |= (((uint32_t)s_pTsensRegList[pmcInst]->GR_S.R) & SAF_PMCDIG_GR_S_TS2);/* polyspace RTE:NIV */
	RegValue |= (((uint32_t)s_pTsensRegList[pmcInst]->GR_S.R) & SAF_PMCDIG_GR_S_TS3);/* polyspace RTE:NIV */

	return RegValue;
}

/**
****************************************************************************************
* @brief: [SW_SM86]This function is used to get chip temperature value.
* @return int32_t: chip temperature value.
****************************************************************************************
*/
SAF_TSENS_SEC_CODE
FS_STATUS SAF_TSENS_GetChipTempValue(saf_tsens_temp_cal_result_t *TempValue)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    status = SAF_TSENS_AccessGetChipTemperatureValue(TempValue);

    return status;
}

/**
****************************************************************************************
* @brief: [SW_SM86]This function is used to get TSENS error from FCCU.
* @return  FS_STATUS: FS_STATUS_SUCCESS :No error occurred.
*                     FS_STATUS_TSENS_TESTAPI_INIT_ERROR :error occurred.
****************************************************************************************
*/
SAF_TSENS_SEC_CODE
FS_STATUS SAF_TSENS_GetTsensFaultFromFccu(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if (FS_STATUS_SUCCESS == SAF_FCCU_DetectFault(SAF_TSENS_FCCU_TEMP_INDEX))
    {
        status = FS_STATUS_TSENS_TESTAPI_INIT_ERROR;
    }

    return status;
}

/**
****************************************************************************************
* @brief: [SW_SM86][SW_SM049]This function executes chip temperature error range test.
* @return FS_STATUS: FS_STATUS_SUCCESS :test success.
*                    FS_STATUS_ERROR :test failed.
****************************************************************************************
*/
SAF_TSENS_SEC_CODE
FS_STATUS SAF_TSENS_ChipTempErrRangeTest(void)
{
    saf_tsens_temp_check_test_result_t *pResult = &s_tsensTempCheckTest;
    saf_tsens_temp_cal_result_t tsensResult;
    FS_STATUS status = FS_STATUS_SUCCESS;
    int32_t actualTemp = 0;

    pResult->TempHtdWarningFlag = false;
    pResult->TempHtdFaultFlag = false;
    pResult->TempLtdFaultFlag = false;
#if defined(CCFC3012PT)
    SAF_SSCM_VRC33_ENABLE = 0x000000f;
#else
    SAF_SSCM_VRC33_ENABLE = 0x000000c;
#endif
    status = SAF_TSENS_GetChipTempValue(&tsensResult);

    if(FS_STATUS_SUCCESS == status)
    {
        actualTemp = (int32_t)tsensResult.TsensValue;

        pResult->actualTemp = actualTemp;

        if((SAF_TSENS_HTD_WARNING_VALUE <= actualTemp) && (SAF_TSENS_HTD_FAULT_VALUE > actualTemp))
        {
            pResult->TempHtdWarningFlag = true;
            status = FS_STATUS_ERROR;
        }
        else if(SAF_TSENS_HTD_FAULT_VALUE <= actualTemp)
        {
            pResult->TempHtdFaultFlag = true;
            status = FS_STATUS_ERROR;
        }
        else if(SAF_TSENS_LTD_FAULT_VALUE >= actualTemp)
        {
            pResult->TempLtdFaultFlag = true;
            status = FS_STATUS_ERROR;
        }
        else
        {
            /* Do nothing */
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief: [SW_SM86][SW_SM049]This function is used to get the test result of chip
* temperature test.
* @param[out] pTestResult: test parameters.
* @return FS_STATUS: FS_STATUS_SUCCESS :get success.
*                    FS_STATUS_ERROR :get failed.
****************************************************************************************
*/
SAF_TSENS_SEC_CODE
FS_STATUS SAF_TSENS_ChipTempErrRangeTestResult(saf_tsens_temp_check_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != pTestResult)
    {
        status = FS_STATUS_SUCCESS;
        (void)memcpy(pTestResult, &s_tsensTempCheckTest, sizeof(s_tsensTempCheckTest));
    }

    return status;
}

/**
****************************************************************************************
* @brief[SW_SM049] This function is used to initialize the configuration of the
                   temperature sensor.
* @return void.
****************************************************************************************
*/
SAF_TSENS_SEC_CODE
void SAF_TSENS_ConfigInit(void)
{
    (void)SAF_TSENS_AccessConfigErrActionType(s_SafTsensConfig.TsensErrorActionType);

    SAF_TSENS_AccessFccuEventEnable(SAF_PMC_INSTANCE_0,SAF_TSENS_FCCU_EVENT_ENABLE);

    SAF_TSENS_AccessEnableAnalogAndDigitalOutput(SAF_PMC_INSTANCE_0,true);

    SAF_TSENS_AccessSetThresholdValue();
}

/**
****************************************************************************************
* @brief[SW_SM049] This function is used to de-initialize the configuration of the
                   temperature sensor.
* @return void.
****************************************************************************************
*/
SAF_TSENS_SEC_CODE
void SAF_TSENS_ConfigDeInit(void)
{
    SAF_TSENS_AccessThresholdValueTrim(SAF_TSENS_HTD_150_TEMPRANGE, SAF_TSENS_LTD_SZ39_TEMPRANGE);

    SAF_TSENS_AccessFccuEventEnable(SAF_PMC_INSTANCE_0,true);

    SAF_TSENS_AccessEnableAnalogAndDigitalOutput(SAF_PMC_INSTANCE_0,true);

    (void)SAF_TSENS_AccessConfigErrActionType(SAF_TSENS_ERROR_ACTION_IS_DESTRUCTIVE_RESET);
}

/**
****************************************************************************************
* @brief[SW_SM049] This function is used for high temperature path fault injection test
                   of temperature sensor.
* @return status
            FS_STATUS_SUCCESS: Tsens high temperature path test success.
            FS_STATUS_ERROR: Tsens high temperature path test failed.
****************************************************************************************
*/
SAF_TSENS_SEC_CODE
FS_STATUS SAF_TSENS_HtdPathInjTest(void)
{
    FS_STATUS status = FS_STATUS_ERROR;
    saf_tsens_temp_Path_check_test_result_t *pResult = &s_tsensTempPathCheckTest;
    uint32_t Timeout = 0u;
    uint32_t regValue = 0u;
    pResult->chipTempHtdFccuPathCheckPassed = false;
    pResult->chipTempHtdSelfTestCheckPassed = false;

    status = SAF_TSENS_AccessConfigErrActionType(SAF_TSENS_ERROR_ACTION_IS_INTERRUPT);
    SAF_TSENS_AccessFccuEventEnable(SAF_PMC_INSTANCE_0,true);

    if(FS_STATUS_SUCCESS == status)
    {
        SAF_TSENS_AccessThresholdValueTrim(SAF_TSENS_HTD_SZ40_TEMPRANGE, SAF_TSENS_LTD_SZ39_TEMPRANGE);

        while ((SAF_TSENS_REG_INIT_VALUE == regValue) && (SAF_TSENS_TIMEOUT_MAX_COUNT > Timeout))
        {
            regValue = SAF_TSENS_GetGrsRegResult(SAF_PMC_INSTANCE_0);
            Timeout++;
        }

        if(FS_STATUS_TSENS_TESTAPI_INIT_ERROR != SAF_TSENS_GetTsensFaultFromFccu())
        {
            status = FS_STATUS_ERROR;
        }
        else
        {
            (void)SAF_FCCU_RestoreFault(SAF_TSENS_FCCU_TEMP_INDEX);
            pResult->chipTempHtdFccuPathCheckPassed = true;
        }

        if((SAF_TSENS_HTD_GRS_REG_MASK & regValue) == SAF_TSENS_REG_INIT_VALUE)
        {
            status = FS_STATUS_ERROR;
        }
        else
        {
            pResult->chipTempHtdSelfTestCheckPassed = true;
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief[SW_SM049] This function is used for low temperature path fault injection test
                   of temperature sensor.
* @return status
            FS_STATUS_SUCCESS: Tsens low temperature path test success.
            FS_STATUS_ERROR: Tsens low temperature path test failed.
****************************************************************************************
*/
SAF_TSENS_SEC_CODE
FS_STATUS SAF_TSENS_LtdPathInjTest(void)
{
#if (SAF_TSENS_LTD_PATH_INJ_TEST_SWITCH == SAF_SWITCH_ON)
    FS_STATUS status = FS_STATUS_ERROR;
    saf_tsens_temp_Path_check_test_result_t *pResult = &s_tsensTempPathCheckTest;
    uint32_t Timeout = 0u;
    uint32_t regValue = 0u;
    pResult->chipTempLtdFccuPathCheckPassed = false;
    pResult->chipTempLtdSelfTestCheckPassed = false;

    status = SAF_TSENS_AccessConfigErrActionType(SAF_TSENS_ERROR_ACTION_IS_INTERRUPT);
    SAF_TSENS_AccessFccuEventEnable(SAF_PMC_INSTANCE_0,true);

    if(FS_STATUS_SUCCESS == status)
    {
        SAF_TSENS_AccessThresholdValueTrim(SAF_TSENS_HTD_150_TEMPRANGE, SAF_TSENS_LTD_45_TEMPRANGE);

        while ((SAF_TSENS_REG_INIT_VALUE == regValue) && (Timeout < SAF_TSENS_TIMEOUT_MAX_COUNT))
        {
            regValue = SAF_TSENS_GetGrsRegResult(SAF_PMC_INSTANCE_0);
            Timeout++;
        }

        if(FS_STATUS_TSENS_TESTAPI_INIT_ERROR != SAF_TSENS_GetTsensFaultFromFccu())
        {
            status = FS_STATUS_ERROR;
        }
        else
        {
            (void)SAF_FCCU_RestoreFault(SAF_TSENS_FCCU_TEMP_INDEX);
            pResult->chipTempLtdFccuPathCheckPassed = true;
        }

        if((SAF_TSENS_LTD_GRS_REG_MASK & regValue) == SAF_TSENS_REG_INIT_VALUE)
        {
            status = FS_STATUS_ERROR;
        }
        else
        {
            pResult->chipTempLtdSelfTestCheckPassed = true;
        }
    }

    return status;
#else
    return FS_STATUS_SUCCESS;
#endif
}

#ifdef __cplusplus
}
#endif

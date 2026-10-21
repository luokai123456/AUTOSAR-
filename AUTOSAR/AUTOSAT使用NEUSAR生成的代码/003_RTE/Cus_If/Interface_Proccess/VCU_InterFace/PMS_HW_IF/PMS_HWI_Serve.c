/*
 * File: PMS_HWI_Serve.c
 *
 * Code generated for Simulink model 'PMS_HWI_Serve'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Apr 15 16:20:33 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PMS_HWI_Serve.h"
#include "PMS_HWI_Serve_private.h"


/*FXS Code Start*/
#include "IoHwAbs_ADC.h"
#include "IoHwAbs_DIO.h"
#include "IoHwAbs_ICU.h"

uint16 XCU_KL30Vltg=0;
/*FXS Code End*/

/* Model step function */
void PMSHWI_AI_BATTERY_TEMPH_5_PMSHWI_GetAI(uint16 *FileterResult)
{
  /* Outputs for Function Call SubSystem: '<S1>/PMSHWI_AI_BATTERY_TEMPH_5_PMSHWI_GetAI_sys' */
  /* SignalConversion generated from: '<S25>/FileterResult' */

   uint16 FileterResultTemp;

   IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_IN_AN6, &FileterResultTemp);

   FileterResult[0]=FileterResultTemp;

  /* End of Outputs for SubSystem: '<S1>/PMSHWI_AI_BATTERY_TEMPH_5_PMSHWI_GetAI_sys' */
}

/* Model step function */
void PMSHWI_AI_BATTERY_TEMPH_6_PMSHWI_GetAI(uint16 *FileterResult)
{
  /* Outputs for Function Call SubSystem: '<S2>/PMSHWI_AI_BATTERY_TEMPH_6_PMSHWI_GetAI_sys' */
  /* SignalConversion generated from: '<S26>/FileterResult' */
  uint16 FileterResultTemp;
  IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_IN_AN2, &FileterResultTemp);
  FileterResult[0]=FileterResultTemp;
  /* End of Outputs for SubSystem: '<S2>/PMSHWI_AI_BATTERY_TEMPH_6_PMSHWI_GetAI_sys' */
}

/* Model step function */
void PMSHWI_AI_EXT_IGN_ON_AI_PMSHWI_GetAI(uint16 *FileterResult)
{
  /* Outputs for Function Call SubSystem: '<S3>/PMSHWI_AI_EXT_IGN_ON_AI_PMSHWI_GetAI_sys' */
  /* SignalConversion generated from: '<S28>/FileterResult' */
  uint16 FileterResultTemp;
  IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_AN_KEY_Mic, &FileterResultTemp);

FileterResult[0] =FileterResultTemp;

  /* End of Outputs for SubSystem: '<S3>/PMSHWI_AI_EXT_IGN_ON_AI_PMSHWI_GetAI_sys' */
}

/* Model step function */
void PMSHWI_AI_MID_COOLING_TEMPH_8_PMSHWI_GetAI(uint16 *FileterResult)
{
  /* Outputs for Function Call SubSystem: '<S3>/PMSHWI_AI_MID_COOLING_TEMPH_8_PMSHWI_GetAI_sys' */
  /* SignalConversion generated from: '<S27>/FileterResult' */
  uint16 FileterResultTemp;
  IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_IN_AN7, &FileterResultTemp);
  FileterResult[0]=FileterResultTemp;
  /* End of Outputs for SubSystem: '<S3>/PMSHWI_AI_MID_COOLING_TEMPH_8_PMSHWI_GetAI_sys' */
}

/* Model step function */
void PMSHWI_AI_SENSOR_1_PMSHWI_GetAI(uint16 *FileterResult)
{
  /* Outputs for Function Call SubSystem: '<S4>/PMSHWI_AI_SENSOR_1_PMSHWI_GetAI_sys' */
  /* SignalConversion generated from: '<S28>/FileterResult' */
  uint16 FileterResultTemp;
  IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_IN_AN11, &FileterResultTemp);
  FileterResult[0]=FileterResultTemp;
  /* End of Outputs for SubSystem: '<S4>/PMSHWI_AI_SENSOR_1_PMSHWI_GetAI_sys' */
}

/* Model step function */
void PMSHWI_AI_SENSOR_2_PMSHWI_GetAI(uint16 *FileterResult)
{
  /* Outputs for Function Call SubSystem: '<S5>/PMSHWI_AI_SENSOR_2_PMSHWI_GetAI_sys' */
  /* SignalConversion generated from: '<S29>/FileterResult' */
  uint16 FileterResultTemp;
  IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_IN_AN12, &FileterResultTemp);
  FileterResult[0]=FileterResultTemp;
  /* End of Outputs for SubSystem: '<S5>/PMSHWI_AI_SENSOR_2_PMSHWI_GetAI_sys' */
}

/* Model step function */
void PMSHWI_AI_SENSOR_6_PMSHWI_GetAI(uint16 *FileterResult)
{
  /* Outputs for Function Call SubSystem: '<S6>/PMSHWI_AI_SENSOR_6_PMSHWI_GetAI_sys' */
  /* SignalConversion generated from: '<S30>/FileterResult' */
  uint16 FileterResultTemp;
  IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_IN_AN10, &FileterResultTemp);
  FileterResult[0]=FileterResultTemp;
  /* End of Outputs for SubSystem: '<S6>/PMSHWI_AI_SENSOR_6_PMSHWI_GetAI_sys' */
}

/* Model step function */
void PMSHWI_AI_SWITCH_1_PMSHWI_GetAI(uint16 *FileterResult)
{
  /* Outputs for Function Call SubSystem: '<S7>/PMSHWI_AI_SWITCH_1_PMSHWI_GetAI_sys' */
  /* SignalConversion generated from: '<S31>/FileterResult' */
	uint16 FileterResultTemp;
	IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_IN_AN1, &FileterResultTemp);
	FileterResult[0]=FileterResultTemp;
  /* End of Outputs for SubSystem: '<S7>/PMSHWI_AI_SWITCH_1_PMSHWI_GetAI_sys' */
}

/* Model step function */
void PMSHWI_AO_LDO_5V_02_PMSHWI_GetAI(uint16 *FileterResult)
{
  /* Outputs for Function Call SubSystem: '<S8>/PMSHWI_AO_LDO_5V_02_PMSHWI_GetAI_sys' */
  /* SignalConversion generated from: '<S32>/FileterResult' */
	uint16 FileterResultTemp;
  IoHwAbs_ADC_GetChannelRawValue( IOHWABS_ADC_CHANNEL_AN_5Vsensor2, &FileterResultTemp);
  FileterResult[0]=FileterResultTemp;
  /* End of Outputs for SubSystem: '<S8>/PMSHWI_AO_LDO_5V_02_PMSHWI_GetAI_sys' */
}

/* Model step function */
void PMSHWI_AO_TRACKING_5V_01_PMSHWI_GetAI(uint16 *FileterResult)
{
  /* Outputs for Function Call SubSystem: '<S9>/PMSHWI_AO_TRACKING_5V_01_PMSHWI_GetAI_sys' */
  /* SignalConversion generated from: '<S33>/FileterResult' */
	uint16 FileterResultTemp;
  IoHwAbs_ADC_GetChannelRawValue( IOHWABS_ADC_CHANNEL_AN_5Vsensor1, &FileterResultTemp);
  FileterResult[0]=FileterResultTemp;
  /* End of Outputs for SubSystem: '<S9>/PMSHWI_AO_TRACKING_5V_01_PMSHWI_GetAI_sys' */
}

/* Model step function */
void PMSHWI_AO_TRACKING_5V_02_PMSHWI_GetAI(uint16 *FileterResult)
{
  /* Outputs for Function Call SubSystem: '<S10>/PMSHWI_AO_TRACKING_5V_02_PMSHWI_GetAI_sys' */
  /* SignalConversion generated from: '<S34>/FileterResult' */
	uint16 FileterResultTemp;
  IoHwAbs_ADC_GetChannelRawValue( IOHWABS_ADC_CHANNEL_AN_5Vsensor2, &FileterResultTemp);
  FileterResult[0]=FileterResultTemp;
  /* End of Outputs for SubSystem: '<S10>/PMSHWI_AO_TRACKING_5V_02_PMSHWI_GetAI_sys' */
}

/* Model step function */
void PMSHWI_CHARGE_ON_AI_PMSHWI_GetAI(uint16 *FileterResult)
{
  /* Outputs for Function Call SubSystem: '<S11>/PMSHWI_CHARGE_ON_AI_PMSHWI_GetAI_sys' */
  /* SignalConversion generated from: '<S35>/FileterResult' */
  uint16 FileterResultTemp;
  IoHwAbs_ADC_GetChannelRawValue( IOHWABS_ADC_CHANNEL_AN_DC_APlus1_Mic, &FileterResultTemp);
  FileterResult[0]=FileterResultTemp;
  /* End of Outputs for SubSystem: '<S11>/PMSHWI_CHARGE_ON_AI_PMSHWI_GetAI_sys' */
}

/* Model step function */
void PMSHWI_DI_HS_04_PMSHWI_GetDI(boolean *RawResult)
{
  /* Outputs for Function Call SubSystem: '<S12>/PMSHWI_DI_HS_04_PMSHWI_GetDI_sys' */
  /* SignalConversion generated from: '<S36>/RawResult' */
	uint8 RawResultTemp;
  IoHwAbs_DIO_GetChannelValue(IOHWABS_DIOCHANNEL_IN_CH13, &RawResultTemp);
  RawResult[0]=RawResultTemp;
  /* End of Outputs for SubSystem: '<S12>/PMSHWI_DI_HS_04_PMSHWI_GetDI_sys' */
}

/* Model step function */
void PMSHWI_DI_HS_05_PMSHWI_GetDI(boolean *RawResult)
{
  /* Outputs for Function Call SubSystem: '<S13>/PMSHWI_DI_HS_05_PMSHWI_GetDI_sys' */
  /* SignalConversion generated from: '<S37>/RawResult' */
	uint8 RawResultTemp;
  IoHwAbs_DIO_GetChannelValue(IOHWABS_DIOCHANNEL_IN_CH14, &RawResultTemp);
  RawResult[0]=RawResultTemp;
  /* End of Outputs for SubSystem: '<S13>/PMSHWI_DI_HS_05_PMSHWI_GetDI_sys' */
}

/* Model step function */
void PMSHWI_DI_HS_06_PMSHWI_GetDI(boolean *RawResult)
{
  /* Outputs for Function Call SubSystem: '<S14>/PMSHWI_DI_HS_06_PMSHWI_GetDI_sys' */
  /* SignalConversion generated from: '<S38>/RawResult' */
	uint8 RawResultTemp;
  IoHwAbs_DIO_GetChannelValue(IOHWABS_DIOCHANNEL_IN_CH10, &RawResultTemp);
  RawResult[0]=RawResultTemp;
  /* End of Outputs for SubSystem: '<S14>/PMSHWI_DI_HS_06_PMSHWI_GetDI_sys' */
}

/* Model step function */
void PMSHWI_DI_HS_07_PMSHWI_GetDI(boolean *RawResult)
{
  /* Outputs for Function Call SubSystem: '<S15>/PMSHWI_DI_HS_07_PMSHWI_GetDI_sys' */
  /* SignalConversion generated from: '<S39>/RawResult' */
	uint8 RawResultTemp;
  IoHwAbs_DIO_GetChannelValue(IOHWABS_DIOCHANNEL_IN_CH11, &RawResultTemp);
  RawResult[0]=RawResultTemp;
  /* End of Outputs for SubSystem: '<S15>/PMSHWI_DI_HS_07_PMSHWI_GetDI_sys' */
}

/* Model step function */
void PMSHWI_DI_HS_08_PMSHWI_GetDI(boolean *RawResult)
{
  /* Outputs for Function Call SubSystem: '<S16>/PMSHWI_DI_HS_08_PMSHWI_GetDI_sys' */
  /* SignalConversion generated from: '<S40>/RawResult' */
	uint8 RawResultTemp;
  IoHwAbs_DIO_GetChannelValue(IOHWABS_DIOCHANNEL_IN_CH9, &RawResultTemp);
  RawResult[0]=RawResultTemp;
  /* End of Outputs for SubSystem: '<S16>/PMSHWI_DI_HS_08_PMSHWI_GetDI_sys' */
}

/* Model step function */
void PMSHWI_DI_HS_10_PMSHWI_GetDI(boolean *RawResult)
{
  /* Outputs for Function Call SubSystem: '<S17>/PMSHWI_DI_HS_10_PMSHWI_GetDI_sys' */
  /* SignalConversion generated from: '<S41>/RawResult' */
	uint8 RawResultTemp;
  IoHwAbs_DIO_GetChannelValue(IOHWABS_DIOCHANNEL_IN_CH7, &RawResultTemp);
  RawResult[0]=RawResultTemp;
  /* End of Outputs for SubSystem: '<S17>/PMSHWI_DI_HS_10_PMSHWI_GetDI_sys' */
}

/* Model step function */
void PMSHWI_IGN_ON_DI_PMSHWI_GetDI(boolean *RawResult)
{
  /* Outputs for Function Call SubSystem: '<S18>/PMSHWI_IGN_ON_DI_PMSHWI_GetDI_sys' */
  /* SignalConversion generated from: '<S42>/RawResult' */

  uint16 IGN_ON_Vltg;
  IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_AN_KEY_Mic, &IGN_ON_Vltg);
  RawResult[0]=(boolean)(IGN_ON_Vltg >= 9000);

  /* End of Outputs for SubSystem: '<S18>/PMSHWI_IGN_ON_DI_PMSHWI_GetDI_sys' */
}

/* Model step function */
void PMSHWI_KL30_PMSHWI_GetAI(uint16 *FileterResult)
{
  /* Outputs for Function Call SubSystem: '<S19>/PMSHWI_KL30_PMSHWI_GetAI_sys' */
  /* SignalConversion generated from: '<S43>/FileterResult' */
  uint16 FileterResultTemp;

  IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_AN_UBD_Mic, &FileterResultTemp);

  FileterResult[0]=FileterResultTemp;

  XCU_KL30Vltg = FileterResultTemp;

  /* End of Outputs for SubSystem: '<S19>/PMSHWI_KL30_PMSHWI_GetAI_sys' */
}

/* Model step function */
void PMSHWI_PI_HVIL_1_PMSHWI_GetPWM(uint8 *numDuty, uint32 *numFreq)
{
  /* Outputs for Function Call SubSystem: '<S20>/PMSHWI_PI_HVIL_1_PMSHWI_GetPWM_sys' */
  /* SignalConversion generated from: '<S44>/numDuty' */

  Pwm_ResultIn_TDSTR valresult_STR; 
  IoHwAbs_ICU_GetChanneValue(IOHWABS_ICU_PwmIn_CH4, &valresult_STR);
  numDuty[0]=valresult_STR.numDuty;
  numFreq[0]=valresult_STR.numFreq;

  /* End of Outputs for SubSystem: '<S20>/PMSHWI_PI_HVIL_1_PMSHWI_GetPWM_sys' */
}

/* Model step function */
void PMSHWI_PI_HVIL_2_PMSHWI_GetPWM(uint8 *numDuty, uint32 *numFreq)
{
  /* Outputs for Function Call SubSystem: '<S21>/PMSHWI_PI_HVIL_2_PMSHWI_GetPWM_sys' */
  /* SignalConversion generated from: '<S45>/numDuty' */
  
  Pwm_ResultIn_TDSTR valresult_STR; 
  IoHwAbs_ICU_GetChanneValue(IOHWABS_ICU_PwmIn_CH7, &valresult_STR);
  numDuty[0]=valresult_STR.numDuty;
  numFreq[0]=valresult_STR.numFreq;

  /* End of Outputs for SubSystem: '<S21>/PMSHWI_PI_HVIL_2_PMSHWI_GetPWM_sys' */
}

/* Model step function */
void PMSHWI_PI_PWM_1_PMSHWI_GetPWM(uint8 *numDuty, uint32 *numFreq)
{
  /* Outputs for Function Call SubSystem: '<S22>/PMSHWI_PI_PWM_1_PMSHWI_GetPWM_sys' */
  /* SignalConversion generated from: '<S46>/numDuty' */
  
  Pwm_ResultIn_TDSTR valresult_STR; 
  IoHwAbs_ICU_GetChanneValue(IOHWABS_ICU_PwmIn_CH2, &valresult_STR);
  numDuty[0]=valresult_STR.numDuty;
  numFreq[0]=valresult_STR.numFreq;

  /* End of Outputs for SubSystem: '<S22>/PMSHWI_PI_PWM_1_PMSHWI_GetPWM_sys' */
}

/* Model step function */
void PMSHWI_PI_PWM_2_PMSHWI_GetPWM(uint8 *numDuty, uint32 *numFreq)
{
  /* Outputs for Function Call SubSystem: '<S23>/PMSHWI_PI_PWM_2_PMSHWI_GetPWM_sys' */
  /* SignalConversion generated from: '<S47>/numDuty' */
  
  Pwm_ResultIn_TDSTR valresult_STR; 
  IoHwAbs_ICU_GetChanneValue(IOHWABS_ICU_PwmIn_CH6, &valresult_STR);
  numDuty[0]=valresult_STR.numDuty;
  numFreq[0]=valresult_STR.numFreq;

  /* End of Outputs for SubSystem: '<S23>/PMSHWI_PI_PWM_2_PMSHWI_GetPWM_sys' */
}

/* Model initialize function */
void PMS_HWI_Serve_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

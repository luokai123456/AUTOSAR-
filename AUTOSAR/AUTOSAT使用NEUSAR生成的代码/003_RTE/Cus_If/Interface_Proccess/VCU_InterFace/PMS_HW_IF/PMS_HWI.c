/*
 * File: PMS_HWI.c
 *
 * Code generated for Simulink model 'PMS_HWI'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Apr 15 19:43:19 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PMS_HWI.h"
#include "PMS_HWI_private.h"
#include "look1_iflf_binlcpw.h"

/* Exported block parameters */
float32 BatteryTemp5Map_R[37] = { 0.083F, 0.095F, 0.109F, 0.126F, 0.144F, 0.166F,
  0.19F, 0.22F, 0.255F, 0.296F, 0.346F, 0.406F, 0.478F, 0.567F, 0.677F, 0.812F,
  0.979F, 1.187F, 1.449F, 1.778F, 2.2F, 2.731F, 3.417F, 4.305F, 5.462F, 6.945F,
  8.99F, 11.67F, 15.27F, 20.15F, 26.832F, 36.081F, 49.05F, 67.455F, 93.739F,
  130.76F, 179.43F } ;                 /* Variable: BatteryTemp5Map_R
                                        * Referenced by: '<S2>/1-D Lookup Table'
                                        */

float32 BatteryTemp5Map_T[37] = { 125.0F, 120.0F, 115.0F, 110.0F, 105.0F, 100.0F,
  95.0F, 90.0F, 85.0F, 80.0F, 75.0F, 70.0F, 65.0F, 60.0F, 55.0F, 50.0F, 45.0F,
  40.0F, 35.0F, 30.0F, 25.0F, 20.0F, 15.0F, 10.0F, 5.0F, 0.0F, -5.0F, -10.0F,
  -15.0F, -20.0F, -25.0F, -30.0F, -35.0F, -40.0F, -45.0F, -50.0F, -55.0F } ;/* Variable: BatteryTemp5Map_T
                                                                      * Referenced by: '<S2>/1-D Lookup Table'
                                                                      */

float32 BatteryTemp5_R = 1.0F;         /* Variable: BatteryTemp5_R
                                        * Referenced by: '<S2>/Constant2'
                                        */
float32 BatteryTemp6Map_R[37] = { 0.083F, 0.095F, 0.109F, 0.126F, 0.144F, 0.166F,
  0.19F, 0.22F, 0.255F, 0.296F, 0.346F, 0.406F, 0.478F, 0.567F, 0.677F, 0.812F,
  0.979F, 1.187F, 1.449F, 1.778F, 2.2F, 2.731F, 3.417F, 4.305F, 5.462F, 6.945F,
  8.99F, 11.67F, 15.27F, 20.15F, 26.832F, 36.081F, 49.05F, 67.455F, 93.739F,
  130.76F, 179.43F } ;                 /* Variable: BatteryTemp6Map_R
                                        * Referenced by: '<S2>/1-D Lookup Table1'
                                        */

float32 BatteryTemp6Map_T[37] = { 125.0F, 120.0F, 115.0F, 110.0F, 105.0F, 100.0F,
  95.0F, 90.0F, 85.0F, 80.0F, 75.0F, 70.0F, 65.0F, 60.0F, 55.0F, 50.0F, 45.0F,
  40.0F, 35.0F, 30.0F, 25.0F, 20.0F, 15.0F, 10.0F, 5.0F, 0.0F, -5.0F, -10.0F,
  -15.0F, -20.0F, -25.0F, -30.0F, -35.0F, -40.0F, -45.0F, -50.0F, -55.0F } ;/* Variable: BatteryTemp6Map_T
                                                                      * Referenced by: '<S2>/1-D Lookup Table1'
                                                                      */

float32 BatteryTemp6_R = 1.0F;         /* Variable: BatteryTemp6_R
                                        * Referenced by: '<S2>/Constant5'
                                        */
float32 CoolingTempMap_R[37] = { 0.083F, 0.095F, 0.109F, 0.126F, 0.144F, 0.166F,
  0.19F, 0.22F, 0.255F, 0.296F, 0.346F, 0.406F, 0.478F, 0.567F, 0.677F, 0.812F,
  0.979F, 1.187F, 1.449F, 1.778F, 2.2F, 2.731F, 3.417F, 4.305F, 5.462F, 6.945F,
  8.99F, 11.67F, 15.27F, 20.15F, 26.832F, 36.081F, 49.05F, 67.455F, 93.739F,
  130.76F, 179.43F } ;                 /* Variable: CoolingTempMap_R
                                        * Referenced by: '<S2>/1-D Lookup Table2'
                                        */

float32 CoolingTempMap_T[37] = { 125.0F, 120.0F, 115.0F, 110.0F, 105.0F, 100.0F,
  95.0F, 90.0F, 85.0F, 80.0F, 75.0F, 70.0F, 65.0F, 60.0F, 55.0F, 50.0F, 45.0F,
  40.0F, 35.0F, 30.0F, 25.0F, 20.0F, 15.0F, 10.0F, 5.0F, 0.0F, -5.0F, -10.0F,
  -15.0F, -20.0F, -25.0F, -30.0F, -35.0F, -40.0F, -45.0F, -50.0F, -55.0F } ;/* Variable: CoolingTempMap_T
                                                                      * Referenced by: '<S2>/1-D Lookup Table2'
                                                                      */

float32 CoolingTemp_R = 1.0F;          /* Variable: CoolingTemp_R
                                        * Referenced by: '<S2>/Constant8'
                                        */

/* Model step function for TID1 */
void PMS_HWI_Step(void)                /* Explicit Task: PMS_HWI_Step */
{
  uint32 rtb_PMSHWI_PI_PWM_2_PMSHWI_GetP;
  uint16 rtb_PMSHWI_KL30_PMSHWI_GetAI;
  uint16 tmpWrite;
  uint8 rtb_PMSHWI_PI_PWM_2_PMSHWI_Ge_h;
  boolean tmpWrite_0;
  boolean tmpWrite_1;
  boolean tmpWrite_2;
  boolean tmpWrite_3;
  boolean tmpWrite_4;
  boolean tmpWrite_5;
  boolean tmpWrite_6;
  uint16 rtb_PMSHWI_AI_EXT_IGN_ON_AI_PMS;

  /* RootInportFunctionCallGenerator generated from: '<Root>/PMS_HWI_Step' incorporates:
   *  SubSystem: '<Root>/PMS_HWI_Step_sys'
   */
  /* FunctionCaller: '<S2>/PMSHWI_AI_BATTERY_TEMPH_5_PMSHWI_GetAI' */
  Rte_Call_PMSHWI_AI_BATTERY_TEMPH_5_PMSHWI_GetAI(&rtb_PMSHWI_KL30_PMSHWI_GetAI);

  /* Outport: '<Root>/EXT_AI_BATTERY_TEMPH_5_EXT_AI_BATTERY_TEMPH_5' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Lookup_n-D: '<S2>/1-D Lookup Table'
   *  MinMax: '<S2>/Max'
   *  Product: '<S2>/Divide'
   *  Product: '<S2>/Divide1'
   *  Sum: '<S2>/Add'
   */
  (void)Rte_Write_EXT_AI_BATTERY_TEMPH_5_EXT_AI_BATTERY_TEMPH_5
    (look1_iflf_binlcpw(BatteryTemp5_R * (float32)rtb_PMSHWI_KL30_PMSHWI_GetAI /
                        fmaxf(0.1F, 5000.0F - (float32)
       rtb_PMSHWI_KL30_PMSHWI_GetAI), BatteryTemp5Map_R, BatteryTemp5Map_T, 36U));

  /* FunctionCaller: '<S2>/PMSHWI_AI_BATTERY_TEMPH_6_PMSHWI_GetAI' */
  Rte_Call_PMSHWI_AI_BATTERY_TEMPH_6_PMSHWI_GetAI(&rtb_PMSHWI_KL30_PMSHWI_GetAI);

  /* Outport: '<Root>/EXT_AI_BATTERY_TEMPH_6_EXT_AI_BATTERY_TEMPH_6' incorporates:
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   *  Lookup_n-D: '<S2>/1-D Lookup Table1'
   *  MinMax: '<S2>/Max1'
   *  Product: '<S2>/Divide2'
   *  Product: '<S2>/Divide3'
   *  Sum: '<S2>/Add1'
   */
  (void)Rte_Write_EXT_AI_BATTERY_TEMPH_6_EXT_AI_BATTERY_TEMPH_6
    (look1_iflf_binlcpw(BatteryTemp6_R * (float32)rtb_PMSHWI_KL30_PMSHWI_GetAI /
                        fmaxf(0.1F, 5000.0F - (float32)
       rtb_PMSHWI_KL30_PMSHWI_GetAI), BatteryTemp6Map_R, BatteryTemp6Map_T, 36U));

  /* FunctionCaller: '<S2>/PMSHWI_AI_MID_COOLING_TEMPH_8_PMSHWI_GetAI' */
  Rte_Call_PMSHWI_AI_MID_COOLING_TEMPH_8_PMSHWI_GetAI
    (&rtb_PMSHWI_KL30_PMSHWI_GetAI);

  /* Outport: '<Root>/EXT_AI_MID_COOLING_TEMPH_8_EXT_AI_MID_COOLING_TEMPH_8' incorporates:
   *  Constant: '<S2>/Constant6'
   *  Constant: '<S2>/Constant7'
   *  Constant: '<S2>/Constant8'
   *  Lookup_n-D: '<S2>/1-D Lookup Table2'
   *  MinMax: '<S2>/Max2'
   *  Product: '<S2>/Divide4'
   *  Product: '<S2>/Divide5'
   *  Sum: '<S2>/Add2'
   */
  (void)Rte_Write_EXT_AI_MID_COOLING_TEMPH_8_EXT_AI_MID_COOLING_TEMPH_8
    (look1_iflf_binlcpw(CoolingTemp_R * (float32)rtb_PMSHWI_KL30_PMSHWI_GetAI /
                        fmaxf(0.1F, 5000.0F - (float32)
       rtb_PMSHWI_KL30_PMSHWI_GetAI), CoolingTempMap_R, CoolingTempMap_T, 36U));

  /* FunctionCaller: '<S2>/PMSHWI_AI_SENSOR_1_PMSHWI_GetAI' */
  Rte_Call_PMSHWI_AI_SENSOR_1_PMSHWI_GetAI(&rtb_PMSHWI_KL30_PMSHWI_GetAI);

  /* Outport: '<Root>/EXT_AI_SENSOR_1_EXT_AI_SENSOR_1' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  (void)Rte_Write_EXT_AI_SENSOR_1_EXT_AI_SENSOR_1(rtb_PMSHWI_KL30_PMSHWI_GetAI);

  /* FunctionCaller: '<S2>/PMSHWI_AI_SENSOR_2_PMSHWI_GetAI' */
  Rte_Call_PMSHWI_AI_SENSOR_2_PMSHWI_GetAI(&rtb_PMSHWI_KL30_PMSHWI_GetAI);

  /* Outport: '<Root>/EXT_AI_SENSOR_2_EXT_AI_SENSOR_2' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   */
  (void)Rte_Write_EXT_AI_SENSOR_2_EXT_AI_SENSOR_2(rtb_PMSHWI_KL30_PMSHWI_GetAI);

  /* FunctionCaller: '<S2>/PMSHWI_AI_SENSOR_6_PMSHWI_GetAI' */
  Rte_Call_PMSHWI_AI_SENSOR_6_PMSHWI_GetAI(&rtb_PMSHWI_KL30_PMSHWI_GetAI);

  /* Outport: '<Root>/EXT_AI_SENSOR_6_EXT_AI_SENSOR_6' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion2'
   */
  (void)Rte_Write_EXT_AI_SENSOR_6_EXT_AI_SENSOR_6(rtb_PMSHWI_KL30_PMSHWI_GetAI);

  /* FunctionCaller: '<S2>/PMSHWI_AI_SWITCH_1_PMSHWI_GetAI' */
  Rte_Call_PMSHWI_AI_SWITCH_1_PMSHWI_GetAI(&rtb_PMSHWI_KL30_PMSHWI_GetAI);

  /* Outport: '<Root>/EXT_AI_SWITCH_1_EXT_AI_SWITCH_1' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   */
  (void)Rte_Write_EXT_AI_SWITCH_1_EXT_AI_SWITCH_1(rtb_PMSHWI_KL30_PMSHWI_GetAI);

  /* FunctionCaller: '<S2>/PMSHWI_AO_LDO_5V_02_PMSHWI_GetAI' incorporates:
   *  Outport: '<Root>/EXT_AO_LDO_5V_02_EXT_AO_LDO_5V_02'
   */
  Rte_Call_PMSHWI_AO_LDO_5V_02_PMSHWI_GetAI(&tmpWrite);

  /* FunctionCaller: '<S2>/PMSHWI_AO_TRACKING_5V_01_PMSHWI_GetAI' */
  Rte_Call_PMSHWI_AO_TRACKING_5V_01_PMSHWI_GetAI(&rtb_PMSHWI_KL30_PMSHWI_GetAI);

  /* Outport: '<Root>/EXT_AO_TRACKING_5V_01_EXT_AO_TRACKING_5V_01' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion5'
   */
  (void)Rte_Write_EXT_AO_TRACKING_5V_01_EXT_AO_TRACKING_5V_01
    (rtb_PMSHWI_KL30_PMSHWI_GetAI);

  /* FunctionCaller: '<S2>/PMSHWI_AO_TRACKING_5V_02_PMSHWI_GetAI' */
  Rte_Call_PMSHWI_AO_TRACKING_5V_02_PMSHWI_GetAI(&rtb_PMSHWI_KL30_PMSHWI_GetAI);

  /* Outport: '<Root>/EXT_AO_TRACKING_5V_02_EXT_AO_TRACKING_5V_02' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion6'
   */
  (void)Rte_Write_EXT_AO_TRACKING_5V_02_EXT_AO_TRACKING_5V_02
    (rtb_PMSHWI_KL30_PMSHWI_GetAI);

  /* FunctionCaller: '<S2>/PMSHWI_CHARGE_ON_AI_PMSHWI_GetAI' */
  Rte_Call_PMSHWI_CHARGE_ON_AI_PMSHWI_GetAI(&rtb_PMSHWI_KL30_PMSHWI_GetAI);

  /* Outport: '<Root>/EXT_CHARGE_ON_AI_EXT_CHARGE_ON_AI' incorporates:
   *  Constant: '<S3>/Constant'
   *  DataTypeConversion: '<S2>/Data Type Conversion7'
   *  RelationalOperator: '<S3>/Compare'
   */
  (void)Rte_Write_EXT_CHARGE_ON_AI_EXT_CHARGE_ON_AI((float32)
    (rtb_PMSHWI_KL30_PMSHWI_GetAI >= 9000));

  /* FunctionCaller: '<S2>/PMSHWI_DI_HS_04_PMSHWI_GetDI' incorporates:
   *  Outport: '<Root>/EXT_DI_HS_04_EXT_DI_HS_04'
   */
  Rte_Call_PMSHWI_DI_HS_04_PMSHWI_GetDI(&tmpWrite_0);

  /* FunctionCaller: '<S2>/PMSHWI_DI_HS_05_PMSHWI_GetDI' incorporates:
   *  Outport: '<Root>/EXT_DI_HS_05_EXT_DI_HS_05'
   */
  Rte_Call_PMSHWI_DI_HS_05_PMSHWI_GetDI(&tmpWrite_1);

  /* FunctionCaller: '<S2>/PMSHWI_DI_HS_06_PMSHWI_GetDI' incorporates:
   *  Outport: '<Root>/EXT_DI_HS_06_EXT_DI_HS_06'
   */
  Rte_Call_PMSHWI_DI_HS_06_PMSHWI_GetDI(&tmpWrite_2);

  /* FunctionCaller: '<S2>/PMSHWI_DI_HS_07_PMSHWI_GetDI' incorporates:
   *  Outport: '<Root>/EXT_DI_HS_07_EXT_DI_HS_07'
   */
  Rte_Call_PMSHWI_DI_HS_07_PMSHWI_GetDI(&tmpWrite_3);

  /* FunctionCaller: '<S2>/PMSHWI_DI_HS_08_PMSHWI_GetDI' incorporates:
   *  Outport: '<Root>/EXT_DI_HS_08_EXT_DI_HS_08'
   */
  Rte_Call_PMSHWI_DI_HS_08_PMSHWI_GetDI(&tmpWrite_4);

  /* FunctionCaller: '<S2>/PMSHWI_DI_HS_10_PMSHWI_GetDI' incorporates:
   *  Outport: '<Root>/EXT_DI_HS_10_EXT_DI_HS_10'
   */
  Rte_Call_PMSHWI_DI_HS_10_PMSHWI_GetDI(&tmpWrite_5);

  /* FunctionCaller: '<S2>/PMSHWI_IGN_ON_DI_PMSHWI_GetDI' incorporates:
   *  Outport: '<Root>/EXT_IGN_ON_DI_EXT_IGN_ON_DI'
   */
  Rte_Call_PMSHWI_IGN_ON_DI_PMSHWI_GetDI(&tmpWrite_6);

  /* FunctionCaller: '<S2>/PMSHWI_PI_HVIL_1_PMSHWI_GetPWM' */
  Rte_Call_PMSHWI_PI_HVIL_1_PMSHWI_GetPWM(&rtb_PMSHWI_PI_PWM_2_PMSHWI_Ge_h,
    &rtb_PMSHWI_PI_PWM_2_PMSHWI_GetP);

  /* Outport: '<Root>/EXT_PI_HVIL_1_DutyCycle_EXT_PI_HVIL_1_DutyCycle' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion15'
   */
  (void)Rte_Write_EXT_PI_HVIL_1_DutyCycle_EXT_PI_HVIL_1_DutyCycle
    (rtb_PMSHWI_PI_PWM_2_PMSHWI_Ge_h);

  /* Outport: '<Root>/EXT_PI_HVIL_1_Period_EXT_PI_HVIL_1_Period' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion16'
   */
  (void)Rte_Write_EXT_PI_HVIL_1_Period_EXT_PI_HVIL_1_Period((float32)
    rtb_PMSHWI_PI_PWM_2_PMSHWI_GetP);

  /* FunctionCaller: '<S2>/PMSHWI_PI_HVIL_2_PMSHWI_GetPWM' */
  Rte_Call_PMSHWI_PI_HVIL_2_PMSHWI_GetPWM(&rtb_PMSHWI_PI_PWM_2_PMSHWI_Ge_h,
    &rtb_PMSHWI_PI_PWM_2_PMSHWI_GetP);

  /* Outport: '<Root>/EXT_PI_HVIL_2_DutyCycle_EXT_PI_HVIL_2_DutyCycle' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion17'
   */
  (void)Rte_Write_EXT_PI_HVIL_2_DutyCycle_EXT_PI_HVIL_2_DutyCycle
    (rtb_PMSHWI_PI_PWM_2_PMSHWI_Ge_h);

  /* Outport: '<Root>/EXT_PI_HVIL_2_Period_EXT_PI_HVIL_2_Period' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion18'
   */
  (void)Rte_Write_EXT_PI_HVIL_2_Period_EXT_PI_HVIL_2_Period((float32)
    rtb_PMSHWI_PI_PWM_2_PMSHWI_GetP);

  /* FunctionCaller: '<S2>/PMSHWI_PI_PWM_1_PMSHWI_GetPWM' */
  Rte_Call_PMSHWI_PI_PWM_1_PMSHWI_GetPWM(&rtb_PMSHWI_PI_PWM_2_PMSHWI_Ge_h,
    &rtb_PMSHWI_PI_PWM_2_PMSHWI_GetP);

  /* Outport: '<Root>/EXT_PI_PWM_1_DutyCycle_EXT_PI_PWM_1_DutyCycle' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion19'
   */
  (void)Rte_Write_EXT_PI_PWM_1_DutyCycle_EXT_PI_PWM_1_DutyCycle
    (rtb_PMSHWI_PI_PWM_2_PMSHWI_Ge_h);

  /* Outport: '<Root>/EXT_PI_PWM_1_Period_EXT_PI_PWM_1_Period' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion20'
   */
  (void)Rte_Write_EXT_PI_PWM_1_Period_EXT_PI_PWM_1_Period((float32)
    rtb_PMSHWI_PI_PWM_2_PMSHWI_GetP);

  /* FunctionCaller: '<S2>/PMSHWI_PI_PWM_2_PMSHWI_GetPWM' */
  Rte_Call_PMSHWI_PI_PWM_2_PMSHWI_GetPWM(&rtb_PMSHWI_PI_PWM_2_PMSHWI_Ge_h,
    &rtb_PMSHWI_PI_PWM_2_PMSHWI_GetP);

  /* Outport: '<Root>/EXT_PI_PWM_2_DutyCycle_EXT_PI_PWM_2_DutyCycle' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion21'
   */
  (void)Rte_Write_EXT_PI_PWM_2_DutyCycle_EXT_PI_PWM_2_DutyCycle
    (rtb_PMSHWI_PI_PWM_2_PMSHWI_Ge_h);

  /* Outport: '<Root>/EXT_PI_PWM_2_Period_EXT_PI_PWM_2_Period' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion22'
   */
  (void)Rte_Write_EXT_PI_PWM_2_Period_EXT_PI_PWM_2_Period((float32)
    rtb_PMSHWI_PI_PWM_2_PMSHWI_GetP);

  /* FunctionCaller: '<S2>/PMSHWI_KL30_PMSHWI_GetAI' */
  Rte_Call_PMSHWI_KL30_PMSHWI_GetAI(&rtb_PMSHWI_KL30_PMSHWI_GetAI);

  
   
Rte_Call_PMSHWI_AI_EXT_IGN_ON_AI_PMSHWI_GetAI(&rtb_PMSHWI_AI_EXT_IGN_ON_AI_PMS);

(void)Rte_Write_EXT_IGN_ON_AI_EXT_IGN_ON_AI(rtb_PMSHWI_AI_EXT_IGN_ON_AI_PMS); 

  (void)Rte_Write_KL30_KL30(0.001F * (float32)rtb_PMSHWI_KL30_PMSHWI_GetAI);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/PMS_HWI_Step' */

  /* Outport: '<Root>/EXT_AO_LDO_5V_02_EXT_AO_LDO_5V_02' */
  (void)Rte_Write_EXT_AO_LDO_5V_02_EXT_AO_LDO_5V_02(tmpWrite);

  /* Outport: '<Root>/EXT_DI_HS_04_EXT_DI_HS_04' */
  (void)Rte_Write_EXT_DI_HS_04_EXT_DI_HS_04(tmpWrite_0);

  /* Outport: '<Root>/EXT_DI_HS_05_EXT_DI_HS_05' */
  (void)Rte_Write_EXT_DI_HS_05_EXT_DI_HS_05(tmpWrite_1);

  /* Outport: '<Root>/EXT_DI_HS_06_EXT_DI_HS_06' */
  (void)Rte_Write_EXT_DI_HS_06_EXT_DI_HS_06(tmpWrite_2);

  /* Outport: '<Root>/EXT_DI_HS_07_EXT_DI_HS_07' */
  (void)Rte_Write_EXT_DI_HS_07_EXT_DI_HS_07(tmpWrite_3);

  /* Outport: '<Root>/EXT_DI_HS_08_EXT_DI_HS_08' */
  (void)Rte_Write_EXT_DI_HS_08_EXT_DI_HS_08(tmpWrite_4);

  /* Outport: '<Root>/EXT_DI_HS_10_EXT_DI_HS_10' */
  (void)Rte_Write_EXT_DI_HS_10_EXT_DI_HS_10(tmpWrite_5);

  /* Outport: '<Root>/EXT_IGN_ON_DI_EXT_IGN_ON_DI' */
  (void)Rte_Write_EXT_IGN_ON_DI_EXT_IGN_ON_DI(tmpWrite_6);
}

/* Model initialize function */
void PMS_HWI_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

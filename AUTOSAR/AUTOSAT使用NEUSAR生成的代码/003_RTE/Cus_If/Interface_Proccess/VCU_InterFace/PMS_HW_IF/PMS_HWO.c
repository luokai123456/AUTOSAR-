/*
 * File: PMS_HWO.c
 *
 * Code generated for Simulink model 'PMS_HWO'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Aug  7 15:06:14 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PMS_HWO.h"
#include "PMS_HWO_private.h"

/* Model step function for TID1 */
void PMS_HWO_Step(void)                /* Explicit Task: PMS_HWO_Step */
{
  float32 tmpRead_a;
  float32 tmpRead_b;
  float32 tmpRead_c;
  float32 tmpRead_d;
  float32 tmpRead_e;
  float32 tmpRead_f;
  float32 tmpRead_g;
  float32 tmpRead_h;
  float32 tmpRead_i;
  float32 tmpRead_j;
  float32 v;
  uint32 tmp;
  uint32 tmp_0;
  boolean tmpRead;
  boolean tmpRead_0;
  boolean tmpRead_1;
  boolean tmpRead_2;
  boolean tmpRead_3;
  boolean tmpRead_4;
  boolean tmpRead_5;
  boolean tmpRead_6;
  boolean tmpRead_7;
  boolean tmpRead_8;
  boolean tmpRead_9;

  /* Inport: '<Root>/EXT_PO_PWM_4_Period_EXT_PO_PWM_4_Period' */
  (void)Rte_Read_EXT_PO_PWM_4_Period_EXT_PO_PWM_4_Period(&tmpRead_j);

  /* Inport: '<Root>/EXT_PO_PWM_4_DutyCycle_EXT_PO_PWM_4_DutyCycle' */
  (void)Rte_Read_EXT_PO_PWM_4_DutyCycle_EXT_PO_PWM_4_DutyCycle(&tmpRead_i);

  /* Inport: '<Root>/EXT_PO_PWM_2_Period_EXT_PO_PWM_2_Period' */
  (void)Rte_Read_EXT_PO_PWM_2_Period_EXT_PO_PWM_2_Period(&tmpRead_h);

  /* Inport: '<Root>/EXT_PO_PWM_2_DutyCycle_EXT_PO_PWM_2_DutyCycle' */
  (void)Rte_Read_EXT_PO_PWM_2_DutyCycle_EXT_PO_PWM_2_DutyCycle(&tmpRead_g);

  /* Inport: '<Root>/EXT_PO_PWM_1_Period_EXT_PO_PWM_1_Period' */
  (void)Rte_Read_EXT_PO_PWM_1_Period_EXT_PO_PWM_1_Period(&tmpRead_f);

  /* Inport: '<Root>/EXT_PO_PWM_1_DutyCycle_EXT_PO_PWM_1_DutyCycle' */
  (void)Rte_Read_EXT_PO_PWM_1_DutyCycle_EXT_PO_PWM_1_DutyCycle(&tmpRead_e);

  /* Inport: '<Root>/EXT_PO_HVIL_2_Period_EXT_PO_HVIL_2_Period' */
  (void)Rte_Read_EXT_PO_HVIL_2_Period_EXT_PO_HVIL_2_Period(&tmpRead_d);

  /* Inport: '<Root>/EXT_PO_HVIL_2_DutyCycle_EXT_PO_HVIL_2_DutyCycle' */
  (void)Rte_Read_EXT_PO_HVIL_2_DutyCycle_EXT_PO_HVIL_2_DutyCycle(&tmpRead_c);

  /* Inport: '<Root>/EXT_PO_HVIL_1_Period_EXT_PO_HVIL_1_Period' */
  (void)Rte_Read_EXT_PO_HVIL_1_Period_EXT_PO_HVIL_1_Period(&tmpRead_b);

  /* Inport: '<Root>/EXT_PO_HVIL_1_DutyCycle_EXT_PO_HVIL_1_DutyCycle' */
  (void)Rte_Read_EXT_PO_HVIL_1_DutyCycle_EXT_PO_HVIL_1_DutyCycle(&tmpRead_a);

  /* Inport: '<Root>/EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9' */
  (void)Rte_Read_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9(&tmpRead_9);

  /* Inport: '<Root>/EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7' */
  (void)Rte_Read_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7(&tmpRead_8);

  /* Inport: '<Root>/EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5' */
  (void)Rte_Read_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5(&tmpRead_7);

  /* Inport: '<Root>/EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12' */
  (void)Rte_Read_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12(&tmpRead_6);

  /* Inport: '<Root>/EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10' */
  (void)Rte_Read_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10(&tmpRead_5);

  /* Inport: '<Root>/EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9' */
  (void)Rte_Read_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9(&tmpRead_4);

  /* Inport: '<Root>/EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8' */
  (void)Rte_Read_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8(&tmpRead_3);

  /* Inport: '<Root>/EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6' */
  (void)Rte_Read_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6(&tmpRead_2);

  /* Inport: '<Root>/EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11' */
  (void)Rte_Read_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11(&tmpRead_1);

  /* Inport: '<Root>/EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05' */
  (void)Rte_Read_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05(&tmpRead_0);

  /* Inport: '<Root>/EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03' */
  (void)Rte_Read_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/PMS_HWO_Step' incorporates:
   *  SubSystem: '<Root>/PMS_HWO_Step_sys'
   */
  /* FunctionCaller: '<S2>/PMSHWO_DO_KEY_HS_03_PMSHWO_SetDOHS' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  Rte_Call_PMSHWO_DO_KEY_HS_03_PMSHWO_SetDOHS((uint8)tmpRead);

  /* FunctionCaller: '<S2>/PMSHWO_DO_KEY_HS_05_PMSHWO_SetDOHS' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   */
  Rte_Call_PMSHWO_DO_KEY_HS_05_PMSHWO_SetDOHS((uint8)tmpRead_0);

  /* FunctionCaller: '<S2>/PMSHWO_DO_RELAY_HS_11_PMSHWO_SetDOHS' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion2'
   */
  Rte_Call_PMSHWO_DO_RELAY_HS_11_PMSHWO_SetDOHS((uint8)tmpRead_1);

  /* FunctionCaller: '<S2>/PMSHWO_DO_RELAY_HS_6_PMSHWO_SetDOHS' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   */
  Rte_Call_PMSHWO_DO_RELAY_HS_6_PMSHWO_SetDOHS((uint8)tmpRead_2);

  /* FunctionCaller: '<S2>/PMSHWO_DO_RELAY_HS_8_PMSHWO_SetDOHS' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion4'
   */
  Rte_Call_PMSHWO_DO_RELAY_HS_8_PMSHWO_SetDOHS((uint8)tmpRead_3);

  /* FunctionCaller: '<S2>/PMSHWO_DO_RELAY_HS_9_PMSHWO_SetDOHS' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion5'
   */
  Rte_Call_PMSHWO_DO_RELAY_HS_9_PMSHWO_SetDOHS((uint8)tmpRead_4);

  /* FunctionCaller: '<S2>/PMSHWO_DO_RELAY_LS_10_PMSHWO_SetDOLS' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion6'
   */
  Rte_Call_PMSHWO_DO_RELAY_LS_10_PMSHWO_SetDOLS((uint8)tmpRead_5);

  /* FunctionCaller: '<S2>/PMSHWO_DO_RELAY_LS_12_PMSHWO_SetDOLS' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion7'
   */
  Rte_Call_PMSHWO_DO_RELAY_LS_12_PMSHWO_SetDOLS((uint8)tmpRead_6);

  /* FunctionCaller: '<S2>/PMSHWO_DO_RELAY_LS_5_PMSHWO_SetDOLS' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion8'
   */
  Rte_Call_PMSHWO_DO_RELAY_LS_5_PMSHWO_SetDOLS((uint8)tmpRead_7);

  /* FunctionCaller: '<S2>/PMSHWO_DO_RELAY_LS_7_PMSHWO_SetDOLS' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion9'
   */
  Rte_Call_PMSHWO_DO_RELAY_LS_7_PMSHWO_SetDOLS((uint8)tmpRead_8);

  /* FunctionCaller: '<S2>/PMSHWO_DO_RELAY_LS_9_PMSHWO_SetDOLS' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion10'
   */
  Rte_Call_PMSHWO_DO_RELAY_LS_9_PMSHWO_SetDOLS((uint8)tmpRead_9);

  /* Product: '<S2>/Divide' incorporates:
   *  Constant: '<S2>/Constant'
   */
  tmpRead_b = 1.0E+6F / tmpRead_b;

  /* DataTypeConversion: '<S2>/Data Type Conversion11' */
  v = fabsf(tmpRead_b);
  if (v < 8.388608E+6F) {
    if (v >= 0.5F) {
      tmpRead_b = floorf(tmpRead_b + 0.5F);
    } else {
      tmpRead_b = 0.0F;
    }
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion12' */
  v = fabsf(tmpRead_a);
  if (v < 8.388608E+6F) {
    if (v >= 0.5F) {
      tmpRead_a = floorf(tmpRead_a + 0.5F);
    } else {
      tmpRead_a = 0.0F;
    }
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion11' */
  if (tmpRead_b < 4.2949673E+9F) {
    if (tmpRead_b >= 0.0F) {
      tmp = (uint32)tmpRead_b;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = ((uint32_T)(0xFFFFFFFFU));
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion12' */
  if (tmpRead_a < 4.2949673E+9F) {
    if (tmpRead_a >= 0.0F) {
      tmp_0 = (uint32)tmpRead_a;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = ((uint32_T)(0xFFFFFFFFU));
  }

  /* FunctionCaller: '<S2>/PMSHWO_PO_HVIL_1_PMSHWO_SetPWM' */
  Rte_Call_PMSHWO_PO_HVIL_1_PMSHWO_SetPWM(tmp, tmp_0);

  /* Product: '<S2>/Divide1' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  tmpRead_b = 1.0E+6F / tmpRead_d;

  /* DataTypeConversion: '<S2>/Data Type Conversion13' */
  v = fabsf(tmpRead_b);
  if (v < 8.388608E+6F) {
    if (v >= 0.5F) {
      tmpRead_b = floorf(tmpRead_b + 0.5F);
    } else {
      tmpRead_b = 0.0F;
    }
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion14' */
  v = fabsf(tmpRead_c);
  if (v < 8.388608E+6F) {
    if (v >= 0.5F) {
      tmpRead_c = floorf(tmpRead_c + 0.5F);
    } else {
      tmpRead_c = 0.0F;
    }
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion13' */
  if (tmpRead_b < 4.2949673E+9F) {
    if (tmpRead_b >= 0.0F) {
      tmp = (uint32)tmpRead_b;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = ((uint32_T)(0xFFFFFFFFU));
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion14' */
  if (tmpRead_c < 4.2949673E+9F) {
    if (tmpRead_c >= 0.0F) {
      tmp_0 = (uint32)tmpRead_c;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = ((uint32_T)(0xFFFFFFFFU));
  }

  /* FunctionCaller: '<S2>/PMSHWO_PO_HVIL_2_PMSHWO_SetPWM' */
  Rte_Call_PMSHWO_PO_HVIL_2_PMSHWO_SetPWM(tmp, tmp_0);

  /* Product: '<S2>/Divide2' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  tmpRead_b = 1.0E+6F / tmpRead_f;

  /* DataTypeConversion: '<S2>/Data Type Conversion15' */
  v = fabsf(tmpRead_b);
  if (v < 8.388608E+6F) {
    if (v >= 0.5F) {
      tmpRead_b = floorf(tmpRead_b + 0.5F);
    } else {
      tmpRead_b = 0.0F;
    }
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion16' */
  v = fabsf(tmpRead_e);
  if (v < 8.388608E+6F) {
    if (v >= 0.5F) {
      tmpRead_e = floorf(tmpRead_e + 0.5F);
    } else {
      tmpRead_e = 0.0F;
    }
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion15' */
  if (tmpRead_b < 4.2949673E+9F) {
    if (tmpRead_b >= 0.0F) {
      tmp = (uint32)tmpRead_b;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = ((uint32_T)(0xFFFFFFFFU));
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion16' */
  if (tmpRead_e < 4.2949673E+9F) {
    if (tmpRead_e >= 0.0F) {
      tmp_0 = (uint32)tmpRead_e;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = ((uint32_T)(0xFFFFFFFFU));
  }

  /* FunctionCaller: '<S2>/PMSHWO_PO_PWM_1_PMSHWO_SetPWM' */
  Rte_Call_PMSHWO_PO_PWM_1_PMSHWO_SetPWM(tmp, tmp_0);

  /* Product: '<S2>/Divide3' incorporates:
   *  Constant: '<S2>/Constant3'
   */
  tmpRead_b = 1.0E+6F / tmpRead_h;

  /* DataTypeConversion: '<S2>/Data Type Conversion17' */
  v = fabsf(tmpRead_b);
  if (v < 8.388608E+6F) {
    if (v >= 0.5F) {
      tmpRead_b = floorf(tmpRead_b + 0.5F);
    } else {
      tmpRead_b = 0.0F;
    }
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion18' */
  v = fabsf(tmpRead_g);
  if (v < 8.388608E+6F) {
    if (v >= 0.5F) {
      tmpRead_g = floorf(tmpRead_g + 0.5F);
    } else {
      tmpRead_g = 0.0F;
    }
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion17' */
  if (tmpRead_b < 4.2949673E+9F) {
    if (tmpRead_b >= 0.0F) {
      tmp = (uint32)tmpRead_b;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = ((uint32_T)(0xFFFFFFFFU));
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion18' */
  if (tmpRead_g < 4.2949673E+9F) {
    if (tmpRead_g >= 0.0F) {
      tmp_0 = (uint32)tmpRead_g;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = ((uint32_T)(0xFFFFFFFFU));
  }

  /* FunctionCaller: '<S2>/PMSHWO_PO_PWM_2_PMSHWO_SetPWM' */
  Rte_Call_PMSHWO_PO_PWM_2_PMSHWO_SetPWM(tmp, tmp_0);

  /* Product: '<S2>/Divide4' incorporates:
   *  Constant: '<S2>/Constant4'
   */
  tmpRead_b = 1.0E+6F / tmpRead_j;

  /* DataTypeConversion: '<S2>/Data Type Conversion19' */
  v = fabsf(tmpRead_b);
  if (v < 8.388608E+6F) {
    if (v >= 0.5F) {
      tmpRead_b = floorf(tmpRead_b + 0.5F);
    } else {
      tmpRead_b = 0.0F;
    }
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion20' */
  v = fabsf(tmpRead_i);
  if (v < 8.388608E+6F) {
    if (v >= 0.5F) {
      tmpRead_i = floorf(tmpRead_i + 0.5F);
    } else {
      tmpRead_i = 0.0F;
    }
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion19' */
  if (tmpRead_b < 4.2949673E+9F) {
    if (tmpRead_b >= 0.0F) {
      tmp = (uint32)tmpRead_b;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = ((uint32_T)(0xFFFFFFFFU));
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion20' */
  if (tmpRead_i < 4.2949673E+9F) {
    if (tmpRead_i >= 0.0F) {
      tmp_0 = (uint32)tmpRead_i;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = ((uint32_T)(0xFFFFFFFFU));
  }

  /* FunctionCaller: '<S2>/PMSHWO_PO_PWM_4_PMSHWO_SetPWM' */
  Rte_Call_PMSHWO_PO_PWM_4_PMSHWO_SetPWM(tmp, tmp_0);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/PMS_HWO_Step' */
}

/* Model initialize function */
void PMS_HWO_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

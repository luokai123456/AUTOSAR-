/*
 * File: MCU_fc_BIfRx_OUT.c
 *
 * Code generated for Simulink model 'MCU_fc_BIfRx_OUT'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Apr 24 17:26:02 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MCU_fc_BIfRx_OUT.h"
#include "rtwtypes.h"
#ifdef MOTORCTRL_TEST

#else
  float32 SGPP_FOC_f32_Uduty_Null;
  float32 SGPP_FOC_f32_Vduty_Null;
  float32 SGPP_FOC_f32_Wduty_Null;
  float32 SGPP_kFOC_f32_PWMFreq_Hz;
  uint8 SGPP_BSW_u8_ASC_Enable;
  uint8 SGPP_BSW_u8_PWM_Enable;
  uint8 SGPP_BSW_u8_ClearFlt_Roty_En;
  boolean SGPP_BSW_u8_ClearFlt_Volt_Curr_En;
  boolean SGPP_BSW_u8_CutOffDelayEn_flg;
#endif
/* Model step function for TID1 */
void MCU_fc_BIfRx_OUT_100us(void)    /* Explicit Task: MCU_fc_BIfRx_OUT_100us */
{
  float32 tmpRead_4;
  float32 tmpRead_5;
  float32 tmpRead_6;
  float32 tmpRead_7;
  uint8 tmpRead;
  uint8 tmpRead_0;
  uint8 tmpRead_3;
  boolean tmpRead_1;
  boolean tmpRead_2;

  /* Inport: '<Root>/kFOC_f32_PWMFreq_Hz_kFOC_f32_PWMFreq_Hz' */
  (void)Rte_Read_kFOC_f32_PWMFreq_Hz_kFOC_f32_PWMFreq_Hz(&tmpRead_7);
  SGPP_kFOC_f32_PWMFreq_Hz = tmpRead_7;

  // 因客户接口名称与RTE接口名称不一致，故注释掉，客户接口名称在 RTE_Bsw_If.c 中定义
  // /* Inport: '<Root>/FOC_f32_Wduty_Null_FOC_f32_Wduty_Null' */
  // (void)Rte_Read_FOC_f32_Wduty_Null_FOC_f32_Wduty_Null(&tmpRead_6);
  // SGPP_FOC_f32_Wduty_Null = tmpRead_6;

  // /* Inport: '<Root>/FOC_f32_Vduty_Null_FOC_f32_Vduty_Null' */
  // (void)Rte_Read_FOC_f32_Vduty_Null_FOC_f32_Vduty_Null(&tmpRead_5);
  // SGPP_FOC_f32_Vduty_Null = tmpRead_5;

  // /* Inport: '<Root>/FOC_f32_Uduty_Null_FOC_f32_Uduty_Null' */
  // (void)Rte_Read_FOC_f32_Uduty_Null_FOC_f32_Uduty_Null(&tmpRead_4);
  // SGPP_FOC_f32_Uduty_Null = tmpRead_4;

  /* Inport: '<Root>/BSW_u8_PWM_Enable_BSW_u8_PWM_Enable' */
  (void)Rte_Read_BSW_u8_PWM_Enable_BSW_u8_PWM_Enable(&tmpRead_3);
  SGPP_BSW_u8_PWM_Enable = tmpRead_3;

  /* Inport: '<Root>/BSW_u8_CutOffDelayEn_flg_BSW_u8_CutOffDelayEn_flg' */
  (void)Rte_Read_BSW_u8_CutOffDelayEn_flg_BSW_u8_CutOffDelayEn_flg(&tmpRead_2);
  SGPP_BSW_u8_CutOffDelayEn_flg = tmpRead_2;

  /* Inport: '<Root>/BSW_u8_ClearFlt_Volt_Curr_En_BSW_u8_ClearFlt_Volt_Curr_En' */
  (void)Rte_Read_BSW_u8_ClearFlt_Volt_Curr_En_BSW_u8_ClearFlt_Volt_Curr_En
    (&tmpRead_1);
  SGPP_BSW_u8_ClearFlt_Volt_Curr_En = tmpRead_1;

  /* Inport: '<Root>/BSW_u8_ClearFlt_Roty_En_BSW_u8_ClearFlt_Roty_En' */
  (void)Rte_Read_BSW_u8_ClearFlt_Roty_En_BSW_u8_ClearFlt_Roty_En(&tmpRead_0);
  SGPP_BSW_u8_ClearFlt_Roty_En = tmpRead_0;

  /* Inport: '<Root>/BSW_u8_ASC_Enable_BSW_u8_ASC_Enable' */
  (void)Rte_Read_BSW_u8_ASC_Enable_BSW_u8_ASC_Enable(&tmpRead);
  SGPP_BSW_u8_ASC_Enable = tmpRead;

  // /* RootInportFunctionCallGenerator generated from: '<Root>/MCU_fc_BIfRx_OUT_100us' incorporates:
  //  *  SubSystem: '<Root>/MCU_fc_BIfRx_OUT_100us_sys'
  //  */
  // /* Outport: '<Root>/BSW_u8_ASC_Enable_read' incorporates:
  //  *  SignalConversion generated from: '<S1>/BSW_u8_ASC_Enable_BSW_u8_ASC_Enable_read'
  //  */
  // Rte_IWrite_MCU_fc_BIfRx_OUT_100us_BSW_u8_ASC_Enable_read_BSW_u8_ASC_Enable_read
  //   (tmpRead);

  // /* Outport: '<Root>/BSW_u8_ClearFlt_Roty_En_read' incorporates:
  //  *  SignalConversion generated from: '<S1>/BSW_u8_ClearFlt_Roty_En_BSW_u8_ClearFlt_Roty_En_read'
  //  */
  // Rte_IWrite_MCU_fc_BIfRx_OUT_100us_BSW_u8_ClearFlt_Roty_En_read_BSW_u8_ClearFlt_Roty_En_read
  //   (tmpRead_0);

  // /* Outport: '<Root>/BSW_u8_ClearFlt_Volt_Curr_En_read' incorporates:
  //  *  SignalConversion generated from: '<S1>/BSW_u8_ClearFlt_Volt_Curr_En_BSW_u8_ClearFlt_Volt_Curr_En_read'
  //  */
  // Rte_IWrite_MCU_fc_BIfRx_OUT_100us_BSW_u8_ClearFlt_Volt_Curr_En_read_BSW_u8_ClearFlt_Volt_Curr_En_read
  //   (tmpRead_1);

  // /* Outport: '<Root>/BSW_u8_CutOffDelayEn_flg_read' incorporates:
  //  *  SignalConversion generated from: '<S1>/BSW_u8_CutOffDelayEn_flg_BSW_u8_CutOffDelayEn_flg_read'
  //  */
  // Rte_IWrite_MCU_fc_BIfRx_OUT_100us_BSW_u8_CutOffDelayEn_flg_read_BSW_u8_CutOffDelayEn_flg_read
  //   (tmpRead_2);

  // /* Outport: '<Root>/BSW_u8_PWM_Enable_read' incorporates:
  //  *  SignalConversion generated from: '<S1>/BSW_u8_PWM_Enable_BSW_u8_PWM_Enable_read'
  //  */
  // Rte_IWrite_MCU_fc_BIfRx_OUT_100us_BSW_u8_PWM_Enable_read_BSW_u8_PWM_Enable_read
  //   (tmpRead_3);

  // /* Outport: '<Root>/FOC_f32_Uduty_Null_read' incorporates:
  //  *  SignalConversion generated from: '<S1>/FOC_f32_Uduty_Null_FOC_f32_Uduty_Null_read'
  //  */
  // Rte_IWrite_MCU_fc_BIfRx_OUT_100us_FOC_f32_Uduty_Null_read_FOC_f32_Uduty_Null_read
  //   (tmpRead_4);

  // /* Outport: '<Root>/FOC_f32_Vduty_Null_read' incorporates:
  //  *  SignalConversion generated from: '<S1>/FOC_f32_Vduty_Null_FOC_f32_Vduty_Null_read'
  //  */
  // Rte_IWrite_MCU_fc_BIfRx_OUT_100us_FOC_f32_Vduty_Null_read_FOC_f32_Vduty_Null_read
  //   (tmpRead_5);

  // /* Outport: '<Root>/FOC_f32_Wduty_Null_read' incorporates:
  //  *  SignalConversion generated from: '<S1>/FOC_f32_Wduty_Null_FOC_f32_Wduty_Null_read'
  //  */
  // Rte_IWrite_MCU_fc_BIfRx_OUT_100us_FOC_f32_Wduty_Null_read_FOC_f32_Wduty_Null_read
  //   (tmpRead_6);

  // /* Outport: '<Root>/kFOC_f32_PWMFreq_Hz_read' incorporates:
  //  *  SignalConversion generated from: '<S1>/kFOC_f32_PWMFreq_Hz_kFOC_f32_PWMFreq_Hz_read'
  //  */
  // Rte_IWrite_MCU_fc_BIfRx_OUT_100us_kFOC_f32_PWMFreq_Hz_read_kFOC_f32_PWMFreq_Hz_read
  //   (tmpRead_7);

  // /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/MCU_fc_BIfRx_OUT_100us' */
}

/* Model initialize function */
void MCU_fc_BIfRx_OUT_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

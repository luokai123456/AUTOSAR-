/*
 * File: AswAdapter.c
 *
 * Code generated for Simulink model 'AswAdapter'.
 *
 * Model version                  : 1.328
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Jul 10 10:57:43 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AswAdapter.h"
#include <math.h>
#include "rtwtypes.h"
#include "AswAdapter_private.h"

/* Exported data definition */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Par */
volatile uint8_T SGSA_OperatingModeSource_C = 0U;/* Referenced by: '<S10>/Constant' */

/* Operating mode source selection: 0=parameter, 1=CAN */
volatile uint8_T SGSA_OperatingModeSp_C = 0U;/* Referenced by: '<S9>/Constant' */

/* Operating mode selection parameter */
volatile uint8_T SGSA_SpeedSpSource_C = 0U;/* Referenced by: '<S13>/Constant' */

/* Speed setpoint source: 0=external, 1=parameter */
volatile real32_T SGSA_SpeedSp_C = 0.0F;/* Referenced by: '<S14>/Constant' */

/* Speed setpoint parameter */
volatile uint8_T SGSA_TorqueSpSource_C = 0U;/* Referenced by: '<S11>/Constant' */

/* Torque setpoint source: 0=external, 1=parameter */
volatile real32_T SGSA_TorqueSp_C = 0.0F;/* Referenced by: '<S12>/Constant' */

/* Torque setpoint parameter */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Sig */
uint8_T SGPP_BSW_u8_ASC_Enable;        /* '<S1>/Chart' */

/* can signal */
uint8_T SGPP_BSW_u8_ClearFlt_Roty_En;  /* '<S1>/Constant3' */

/* can signal */
boolean_T SGPP_BSW_u8_ClearFlt_Volt_Curr_En;/* '<S1>/Constant2' */

/* can signal */
boolean_T SGPP_BSW_u8_CutOffDelayEn_flg;/* '<S1>/Constant1' */

/* can signal */
uint8_T SGPP_BSW_u8_PWM_Enable;        /* '<S1>/Chart' */

/* can signal */
real32_T SGPP_ElecSpeedAbsolute;       /* '<S7>/Abs' */

/* can signal */
real32_T SGPP_FOC_f32_Uduty_Null;      /* '<S1>/Chart' */

/* can signal */
real32_T SGPP_FOC_f32_Vduty_Null;      /* '<S1>/Chart' */

/* can signal */
real32_T SGPP_FOC_f32_Wduty_Null;      /* '<S1>/Chart' */

/* can signal */
real32_T SGPP_MechSpeedAbsolute;       /* '<S7>/Abs1' */

/* can signal */
real32_T SGPP_kFOC_f32_PWMFreq_Hz;     /* '<S1>/Constant4' */

/* can signal */
uint8_T SGSA_BswInit;                  /* '<S2>/GetBswInit' */

/* can signal */
uint8_T SGSA_HwHsIntBSt;             /* '<S2>/SGPP_BSW_f32_DriveHBridg_Error' */

/* can signal */
uint8_T SGSA_HwLsIntBSt;             /* '<S2>/SGPP_BSW_f32_DriveLBridg_Error' */

/* can signal */
uint8_T SGSA_ModeRequest;              /* '<S4>/Switch' */

/* can signal */
real32_T SGSA_SpeedCommand;            /* '<S4>/Switch2' */

/* can signal */
real32_T SGSA_TorqueCommand;           /* '<S4>/Switch1' */

/* can signal */
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Real-time model */
static RT_MODEL_AswAdapter_T AswAdapter_M_;
RT_MODEL_AswAdapter_T *const AswAdapter_M = &AswAdapter_M_;

/* Model step function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void ASWA_ReadProcess_1ms(void)
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/ASWA_ReadProcess_1ms' incorporates:
   *  SubSystem: '<Root>/SGPP_ReadTempVolt_1ms_sys'
   */
  /* Abs: '<S7>/Abs' incorporates:
   *  Inport: '<Root>/SGPP_ElecSpeed'
   */
  SGPP_ElecSpeedAbsolute = (real32_T)fabs(SGPP_ElecSpeed);

  /* Switch: '<S4>/Switch1' incorporates:
   *  Constant: '<S11>/Constant'
   */
  if (SGSA_TorqueSpSource_C != 0) {
    /* Switch: '<S4>/Switch1' incorporates:
     *  Constant: '<S12>/Constant'
     */
    SGSA_TorqueCommand = SGSA_TorqueSp_C;
  } else {
    /* Switch: '<S4>/Switch1' */
    SGSA_TorqueCommand = AswAdapter_ConstB.DataTypeConversion1;
  }

  /* End of Switch: '<S4>/Switch1' */

  /* Switch: '<S4>/Switch2' incorporates:
   *  Constant: '<S13>/Constant'
   */
  if (SGSA_SpeedSpSource_C != 0) {
    /* Switch: '<S4>/Switch2' incorporates:
     *  Constant: '<S14>/Constant'
     */
    SGSA_SpeedCommand = SGSA_SpeedSp_C;
  } else {
    /* Switch: '<S4>/Switch2' */
    SGSA_SpeedCommand = AswAdapter_ConstB.DataTypeConversion2;
  }

  /* End of Switch: '<S4>/Switch2' */

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S10>/Constant'
   */
  if (SGSA_OperatingModeSource_C != 0) {
    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S9>/Constant'
     */
    SGSA_ModeRequest = SGSA_OperatingModeSp_C;
  } else {
    /* Switch: '<S4>/Switch' */
    SGSA_ModeRequest = AswAdapter_ConstB.DataTypeConversion;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Abs: '<S7>/Abs1' incorporates:
   *  Inport: '<Root>/SGPP_MechSpeed'
   */
  SGPP_MechSpeedAbsolute = (real32_T)fabs(SGPP_MechSpeed);

  /* SignalConversion generated from: '<S2>/SGSA_BswInit' */
  SGSA_BswInit = AswAdapter_ConstB.Constant;

  /* SignalConversion generated from: '<S2>/SGPP_BSW_f32_DriveHBridg_Error' incorporates:
   *  Inport: '<Root>/SGPP_BSW_f32_DriveHBridg_Error'
   */
  SGSA_HwHsIntBSt = SGPP_BSW_f32_DriveHBridg_Error;

  /* SignalConversion generated from: '<S2>/SGPP_BSW_f32_DriveLBridg_Error' incorporates:
   *  Inport: '<Root>/SGPP_BSW_f32_DriveLBridg_Error'
   */
  SGSA_HwLsIntBSt = SGPP_BSW_f32_DriveLBridg_Error;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/ASWA_ReadProcess_1ms' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model step function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void ASWA_WriteProcess_100us(void)
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/ASWA_WriteProcess_100us' incorporates:
   *  SubSystem: '<Root>/ASWA_Write_100us_sys'
   */
  /* Chart: '<S1>/Chart' incorporates:
   *  Inport: '<Root>/CTSO_PWMControlState'
   *  Inport: '<Root>/TFPM_PhaseADuty'
   *  Inport: '<Root>/TFPM_PhaseBDuty'
   *  Inport: '<Root>/TFPM_PhaseCDuty'
   */
  switch (CTSO_PWMControlState) {
   case 1:
    SGPP_BSW_u8_ASC_Enable = 0U;
    SGPP_BSW_u8_PWM_Enable = 1U;
    SGPP_FOC_f32_Uduty_Null = TFPM_PhaseADuty;
    SGPP_FOC_f32_Vduty_Null = TFPM_PhaseBDuty;
    SGPP_FOC_f32_Wduty_Null = TFPM_PhaseCDuty;
    break;

   case 3:
    SGPP_BSW_u8_ASC_Enable = 0U;
    SGPP_BSW_u8_PWM_Enable = 0U;
    SGPP_FOC_f32_Uduty_Null = TFPM_PhaseADuty;
    SGPP_FOC_f32_Vduty_Null = TFPM_PhaseBDuty;
    SGPP_FOC_f32_Wduty_Null = TFPM_PhaseCDuty;
    break;

   default:
    SGPP_BSW_u8_ASC_Enable = 1U;
    SGPP_BSW_u8_PWM_Enable = 0U;
    SGPP_FOC_f32_Uduty_Null = TFPM_PhaseADuty;
    SGPP_FOC_f32_Vduty_Null = TFPM_PhaseBDuty;
    SGPP_FOC_f32_Wduty_Null = TFPM_PhaseCDuty;
    break;
  }

  /* End of Chart: '<S1>/Chart' */

  /* SignalConversion generated from: '<S1>/SGPP_kFOC_f32_PWMFreq_Hz' */
  SGPP_kFOC_f32_PWMFreq_Hz = AswAdapter_ConstB.Constant4;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_ClearFlt_Volt_Curr_En' */
  SGPP_BSW_u8_ClearFlt_Volt_Curr_En = AswAdapter_ConstB.Constant2;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_CutOffDelayEn_flg' */
  SGPP_BSW_u8_CutOffDelayEn_flg = AswAdapter_ConstB.Constant1;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_ClearFlt_Roty_En' */
  SGPP_BSW_u8_ClearFlt_Roty_En = AswAdapter_ConstB.Constant3;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/ASWA_WriteProcess_100us' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model initialize function */
void AswAdapter_initialize(void)
{
  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/ASWA_ReadProcess_1ms' incorporates:
   *  SubSystem: '<Root>/SGPP_ReadTempVolt_1ms_sys'
   */
  /* SystemInitialize for SignalConversion generated from: '<S2>/SGSA_BswInit' */
  SGSA_BswInit = AswAdapter_ConstB.Constant;

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/ASWA_ReadProcess_1ms' */

  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/ASWA_WriteProcess_100us' incorporates:
   *  SubSystem: '<Root>/ASWA_Write_100us_sys'
   */
  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_kFOC_f32_PWMFreq_Hz' */
  SGPP_kFOC_f32_PWMFreq_Hz = AswAdapter_ConstB.Constant4;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_ClearFlt_Volt_Curr_En' */
  SGPP_BSW_u8_ClearFlt_Volt_Curr_En = AswAdapter_ConstB.Constant2;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_CutOffDelayEn_flg' */
  SGPP_BSW_u8_CutOffDelayEn_flg = AswAdapter_ConstB.Constant1;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_ClearFlt_Roty_En' */
  SGPP_BSW_u8_ClearFlt_Roty_En = AswAdapter_ConstB.Constant3;

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/ASWA_WriteProcess_100us' */
}

/* Model terminate function */
void AswAdapter_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

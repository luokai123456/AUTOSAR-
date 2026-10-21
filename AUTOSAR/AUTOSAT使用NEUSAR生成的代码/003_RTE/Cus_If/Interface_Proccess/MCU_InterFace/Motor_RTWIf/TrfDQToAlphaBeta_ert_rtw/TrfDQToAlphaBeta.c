/*
 * File: TrfDQToAlphaBeta.c
 *
 * Code generated for Simulink model 'TrfDQToAlphaBeta'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Jun 18 15:41:08 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TrfDQToAlphaBeta.h"
#include <math.h>
#include "rtwtypes.h"
#include "TrfDQToAlphaBeta_private.h"

/* Exported data definition */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Par */
volatile real32_T TFDA_AngleFactor_C = 1.58F;/* Referenced by: '<S5>/Constant' */

/* Angle correction factor for inverse Park transformation */
volatile real32_T TFDA_Open_Loop_SwitchC = 1.0F;/* Referenced by: '<S1>/Constant1' */

/* Angle correction factor for inverse Park transformation */
volatile real32_T TFDA_Open_Loop_Ud_C = 0.0F;/* Referenced by: '<S1>/Constant3' */

/* Angle correction factor for inverse Park transformation */
volatile real32_T TFDA_Open_Loop_Uq_C = 0.0F;/* Referenced by: '<S1>/Constant2' */

/* Angle correction factor for inverse Park transformation */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Sig */
real32_T TFDA_AlphaVoltSp;             /* '<S3>/Add' */

/* Alpha-axis voltage setpoint in stationary frame */
real32_T TFDA_BetaVoltSp;              /* '<S3>/Add1' */

/* Beta-axis voltage setpoint in stationary frame */
real32_T TFDA_ElecAngleCorrPreNorm;
                     /* Speed-corrected electrical angle before normalization */



/* Real-time model */
static RT_MODEL_TrfDQToAlphaBeta_T TrfDQToAlphaBeta_M_;
RT_MODEL_TrfDQToAlphaBeta_T *const TrfDQToAlphaBeta_M = &TrfDQToAlphaBeta_M_;
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
/* Model step function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void TFDA_InvParkTransform_100us(void)
{
  real32_T rtb_Cos;
  real32_T rtb_Sin;
  real32_T rtb_Switch2;
  real32_T rtb_Switch3;
  int16_T tmp;

  /* RootInportFunctionCallGenerator generated from: '<Root>/TFDA_InvParkTransform_100us' incorporates:
   *  SubSystem: '<Root>/TFDA_InvParkTransform_100us_sys'
   */
  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<S5>/Constant'
   *  DataStoreWrite: '<S4>/Data Store Write'
   *  Inport: '<Root>/SGPP_ElecAngle'
   *  Inport: '<Root>/SGPP_ElecSpeed'
   *  Inport: '<Root>/SGPP_SampleTime1'
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   */
  TFDA_ElecAngleCorrPreNorm = TFDA_AngleFactor_C * SGPP_ElecSpeed *
    SGPP_SampleTime1 + SGPP_ElecAngle;

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Constant: '<S2>/Constant'
   *  DataStoreWrite: '<S4>/Data Store Write'
   *  Product: '<S2>/Product2'
   */
  rtb_Sin = (real32_T)floor(TFDA_ElecAngleCorrPreNorm * 0.159154907F);
  if (rtb_Sin < 32768.0F) {
    if (rtb_Sin >= -32768.0F) {
      tmp = (int16_T)rtb_Sin;
    } else {
      tmp = INT16_MIN;
    }
  } else {
    tmp = INT16_MAX;
  }

  /* Sum: '<S2>/Add1' incorporates:
   *  Constant: '<S2>/Constant1'
   *  DataStoreWrite: '<S4>/Data Store Write'
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   *  Product: '<S2>/Product3'
   */
  rtb_Sin = TFDA_ElecAngleCorrPreNorm - (real32_T)tmp * 6.28318548F;

  /* Switch: '<S1>/Switch2' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   *  Inport: '<Root>/CTCR_UdSp'
   *  Inport: '<Root>/CTCR_UqSp'
   *  Switch: '<S1>/Switch3'
   */
  if (TFDA_Open_Loop_SwitchC != 0.0F) {
    rtb_Switch2 = CTCR_UqSp;
    rtb_Switch3 = CTCR_UdSp;
  } else {
    rtb_Switch2 = TFDA_Open_Loop_Uq_C;
    rtb_Switch3 = TFDA_Open_Loop_Ud_C;
  }

  /* End of Switch: '<S1>/Switch2' */

  /* Trigonometry: '<S3>/Cos' */
  rtb_Cos = (real32_T)cos(rtb_Sin);

  /* Trigonometry: '<S3>/Sin' */
  rtb_Sin = (real32_T)sin(rtb_Sin);

  /* Sum: '<S3>/Add' incorporates:
   *  Product: '<S3>/Product'
   *  Product: '<S3>/Product1'
   */
  TFDA_AlphaVoltSp = rtb_Switch3 * rtb_Cos - rtb_Switch2 * rtb_Sin;

  /* Sum: '<S3>/Add1' incorporates:
   *  Product: '<S3>/Product2'
   *  Product: '<S3>/Product3'
   */
  TFDA_BetaVoltSp = rtb_Switch3 * rtb_Sin + rtb_Switch2 * rtb_Cos;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/TFDA_InvParkTransform_100us' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model initialize function */
void TrfDQToAlphaBeta_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void TrfDQToAlphaBeta_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

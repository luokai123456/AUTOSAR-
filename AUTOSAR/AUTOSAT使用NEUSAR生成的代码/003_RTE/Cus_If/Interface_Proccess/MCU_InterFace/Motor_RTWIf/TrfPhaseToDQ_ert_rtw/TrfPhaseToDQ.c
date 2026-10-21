/*
 * File: TrfPhaseToDQ.c
 *
 * Code generated for Simulink model 'TrfPhaseToDQ'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:28:04 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TrfPhaseToDQ.h"
#include <math.h>
#include "rtwtypes.h"
#include "TrfPhaseToDQ_private.h"

/* Exported data definition */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Par */
volatile real32_T TFPD_DAxisFiltFreq_C = 200.0F;/* Referenced by: '<S13>/Constant' */

/* Cutoff frequency for d-axis current filter */
volatile real32_T TFPD_QAxisFiltFreq_C = 200.0F;/* Referenced by: '<S14>/Constant' */

/* Cutoff frequency for q-axis current filter */
volatile uint8_T TFPD_SensorSelection_C = 3U;/* Referenced by: '<S10>/Constant' */

/* Current sensor configuration selection (1-4) */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Sig */
real32_T TFPD_AlphaCurrent;
                          /* Alpha-axis current in stationary reference frame */
real32_T TFPD_BetaCurrent; /* Beta-axis current in stationary reference frame */
real32_T TFPD_CurrentMagFilt;          /* '<S3>/Sqrt' */

/* Filtered magnitude of current vector */
real32_T TFPD_IdFiltered;              /* '<S11>/Subtract1' */

/* Filtered d-axis current after low-pass filtering */
real32_T TFPD_IdMeasured;              /* '<S3>/Add' */

/* Measured d-axis current */
real32_T TFPD_IqFiltered;              /* '<S12>/Subtract1' */

/* Filtered q-axis current after low-pass filtering */
real32_T TFPD_IqMeasured;              /* '<S3>/Add1' */

/* Measured q-axis current */


/* Real-time model */
static RT_MODEL_TrfPhaseToDQ_T TrfPhaseToDQ_M_;
RT_MODEL_TrfPhaseToDQ_T *const TrfPhaseToDQ_M = &TrfPhaseToDQ_M_;
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
/* Model step function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void TFPD_ClarkeParkTransform_100us(void)
{
  real32_T rtb_Add2_j;
  real32_T rtb_Cos;

  /* RootInportFunctionCallGenerator generated from: '<Root>/TFPD_ClarkeParkTransform_100us' incorporates:
   *  SubSystem: '<Root>/TFPD_ClarkeParkTransform_100us_sys'
   */
  /* SwitchCase: '<S2>/Switch Case' incorporates:
   *  Constant: '<S10>/Constant'
   */
  switch (TFPD_SensorSelection_C) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/ClarkeABC_AmpInv' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S5>/Constant4'
     *  Inport: '<Root>/SGPP_PhaseBCurrent'
     *  Inport: '<Root>/SGPP_PhaseCCurrent'
     *  Product: '<S5>/Product2'
     *  Sum: '<S5>/Add1'
     */
    TFPD_BetaCurrent = (SGPP_PhaseBCurrent - SGPP_PhaseCCurrent) * 0.577350259F;

    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S5>/Constant1'
     *  Constant: '<S5>/Constant3'
     *  Inport: '<Root>/SGPP_PhaseACurrent'
     *  Inport: '<Root>/SGPP_PhaseBCurrent'
     *  Inport: '<Root>/SGPP_PhaseCCurrent'
     *  Product: '<S5>/Product1'
     *  Product: '<S5>/Product3'
     *  Sum: '<S5>/Add'
     *  Sum: '<S5>/Add2'
     */
    TFPD_AlphaCurrent = (SGPP_PhaseACurrent - (SGPP_PhaseBCurrent +
      SGPP_PhaseCCurrent) * 0.5F) * 0.666666687F;

    /* End of Outputs for SubSystem: '<S2>/ClarkeABC_AmpInv' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S2>/ClarkAB_AmpInv' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  DataTypeConversion: '<S4>/Data Type Conversion'
     *  Inport: '<Root>/SGPP_PhaseACurrent'
     */
    TFPD_AlphaCurrent = SGPP_PhaseACurrent;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Constant: '<S4>/Constant4'
     *  Inport: '<Root>/SGPP_PhaseACurrent'
     *  Inport: '<Root>/SGPP_PhaseBCurrent'
     *  Product: '<S4>/Product'
     *  Product: '<S4>/Product1'
     *  Sum: '<S4>/Add'
     */
    TFPD_BetaCurrent = (SGPP_PhaseBCurrent * 2.0F + SGPP_PhaseACurrent) *
      0.57735F;

    /* End of Outputs for SubSystem: '<S2>/ClarkAB_AmpInv' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S2>/ClarkeAC_AmpInv' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S6>/Constant2'
     *  Constant: '<S6>/Constant4'
     *  Inport: '<Root>/SGPP_PhaseACurrent'
     *  Inport: '<Root>/SGPP_PhaseCCurrent'
     *  Product: '<S6>/Product'
     *  Product: '<S6>/Product2'
     *  Sum: '<S6>/Add'
     */
    TFPD_BetaCurrent = SGPP_PhaseACurrent * (-0.57735F) + SGPP_PhaseCCurrent * (
      -1.1547F);

    /* Merge: '<S2>/Merge' incorporates:
     *  DataTypeConversion: '<S6>/Data Type Conversion'
     *  Inport: '<Root>/SGPP_PhaseACurrent'
     */
    TFPD_AlphaCurrent = SGPP_PhaseACurrent;

    /* End of Outputs for SubSystem: '<S2>/ClarkeAC_AmpInv' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S2>/ClarkeBC_AmpInv' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Gain: '<S7>/Gain'
     *  Inport: '<Root>/SGPP_PhaseBCurrent'
     *  Inport: '<Root>/SGPP_PhaseCCurrent'
     *  Sum: '<S7>/Add'
     */
    TFPD_AlphaCurrent = (-1.0F) * SGPP_PhaseBCurrent - SGPP_PhaseCCurrent;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S7>/Constant2'
     *  Inport: '<Root>/SGPP_PhaseBCurrent'
     *  Inport: '<Root>/SGPP_PhaseCCurrent'
     *  Product: '<S7>/Product2'
     *  Sum: '<S7>/Add1'
     */
    TFPD_BetaCurrent = (SGPP_PhaseBCurrent - SGPP_PhaseCCurrent) * 0.57735F;

    /* End of Outputs for SubSystem: '<S2>/ClarkeBC_AmpInv' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case' */

  /* Trigonometry: '<S3>/Cos' incorporates:
   *  Inport: '<Root>/SGPP_ElecAngle'
   */
  rtb_Cos = (real32_T)cos(SGPP_ElecAngle);

  /* Trigonometry: '<S3>/Cos1' incorporates:
   *  Inport: '<Root>/SGPP_ElecAngle'
   */
  rtb_Add2_j = (real32_T)sin(SGPP_ElecAngle);

  /* Sum: '<S3>/Add' incorporates:
   *  Product: '<S3>/Product'
   *  Product: '<S3>/Product1'
   */
  TFPD_IdMeasured = TFPD_AlphaCurrent * rtb_Cos + TFPD_BetaCurrent * rtb_Add2_j;

  /* Sum: '<S3>/Add1' incorporates:
   *  Product: '<S3>/Product2'
   *  Product: '<S3>/Product3'
   */
  TFPD_IqMeasured = TFPD_BetaCurrent * rtb_Cos - TFPD_AlphaCurrent * rtb_Add2_j;

  /* Product: '<S11>/Product' incorporates:
   *  Constant: '<S13>/Constant'
   *  Inport: '<Root>/SGPP_SampleTime1'
   */
  rtb_Cos = TFPD_DAxisFiltFreq_C * SGPP_SampleTime1;

  /* Saturate: '<S11>/Saturation' */
  if (rtb_Cos > 1.0F) {
    rtb_Cos = 1.0F;
  } else if (rtb_Cos < 0.0F) {
    rtb_Cos = 0.0F;
  }

  /* Sum: '<S11>/Subtract1' incorporates:
   *  Delay: '<S11>/Delay'
   *  Product: '<S11>/Product1'
   *  Saturate: '<S11>/Saturation'
   *  Sum: '<S11>/Subtract'
   */
  TFPD_IdFiltered = (TFPD_IdMeasured - TFPD_IdFiltered) * rtb_Cos +
    TFPD_IdFiltered;

  /* Product: '<S12>/Product' incorporates:
   *  Constant: '<S14>/Constant'
   *  Inport: '<Root>/SGPP_SampleTime1'
   */
  rtb_Cos = TFPD_QAxisFiltFreq_C * SGPP_SampleTime1;

  /* Saturate: '<S12>/Saturation' */
  if (rtb_Cos > 1.0F) {
    rtb_Cos = 1.0F;
  } else if (rtb_Cos < 0.0F) {
    rtb_Cos = 0.0F;
  }

  /* Sum: '<S12>/Subtract1' incorporates:
   *  Delay: '<S12>/Delay'
   *  Product: '<S12>/Product1'
   *  Saturate: '<S12>/Saturation'
   *  Sum: '<S12>/Subtract'
   */
  TFPD_IqFiltered = (TFPD_IqMeasured - TFPD_IqFiltered) * rtb_Cos +
    TFPD_IqFiltered;

  /* Sqrt: '<S3>/Sqrt' incorporates:
   *  Product: '<S3>/Product4'
   *  Product: '<S3>/Product5'
   *  Sum: '<S3>/Add2'
   */
  TFPD_CurrentMagFilt = (real32_T)sqrt(TFPD_IdFiltered * TFPD_IdFiltered +
    TFPD_IqFiltered * TFPD_IqFiltered);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/TFPD_ClarkeParkTransform_100us' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model initialize function */
void TrfPhaseToDQ_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void TrfPhaseToDQ_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

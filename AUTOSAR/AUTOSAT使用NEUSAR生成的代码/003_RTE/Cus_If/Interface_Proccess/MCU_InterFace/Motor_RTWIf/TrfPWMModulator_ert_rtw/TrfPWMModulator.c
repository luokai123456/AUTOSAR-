/*
 * File: TrfPWMModulator.c
 *
 * Code generated for Simulink model 'TrfPWMModulator'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:26:20 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TrfPWMModulator.h"
#include "rt_nonfinite.h"
#include "TrfPWMModulator_types.h"
#include "rtwtypes.h"
#include "TrfPWMModulator_private.h"

/* Exported data definition */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Par */
volatile real32_T TFPM_DutyLowerLimit_C = 0.0F;/* Referenced by: '<S25>/Constant' */

/* Lower limit for duty cycle saturation */
volatile real32_T TFPM_DutyUpperLimit_C = 100.0F;/* Referenced by: '<S24>/Constant' */

/* Upper limit for duty cycle saturation */
volatile uint8_T TFPM_HighSideSwitchSel_C = 1U;/* Referenced by: '<S23>/Constant' */

/* Switch side selection: 1=high-side, 0=low-side */
volatile real32_T TFPM_MinSwitchTime_C = 2000.0F;/* Referenced by: '<S28>/Constant' */

/* Minimum switching time constraint */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Sig */
real32_T TFPM_AlphaVoltNorm;
                         /* Normalized alpha-axis voltage relative to DC-link */
real32_T TFPM_AlphaVoltSp;             /* Alpha-axis voltage setpoint */
real32_T TFPM_BetaVoltNorm;
                          /* Normalized beta-axis voltage relative to DC-link */
real32_T TFPM_BetaVoltSp;              /* Beta-axis voltage setpoint */
real32_T TFPM_MinSwitchTimeRel;      /* Relative minimum switching time value */
real32_T TFPM_PhaseACompDutyLim;
                              /* Phase A compensated duty cycle with limiting */
real32_T TFPM_PhaseADuty;              /* '<S3>/Signal Conversion' */

/* Phase A PWM duty cycle output */
real32_T TFPM_PhaseADutyRel;           /* Phase A relative duty cycle value */
real32_T TFPM_PhaseASvmDuty;    /* Phase A space vector modulation duty cycle */
real32_T TFPM_PhaseAVoltNorm;  /* Phase A normalized voltage after modulation */
real32_T TFPM_PhaseBCompDutyLim;
                              /* Phase B compensated duty cycle with limiting */
real32_T TFPM_PhaseBDuty;              /* '<S3>/Signal Conversion1' */

/* Phase B PWM duty cycle output */
real32_T TFPM_PhaseBDutyRel;           /* Phase B relative duty cycle value */
real32_T TFPM_PhaseBSvmDuty;    /* Phase B space vector modulation duty cycle */
real32_T TFPM_PhaseBVoltNorm;  /* Phase B normalized voltage after modulation */
real32_T TFPM_PhaseCCompDutyLim;
                              /* Phase C compensated duty cycle with limiting */
real32_T TFPM_PhaseCDuty;              /* '<S3>/Signal Conversion2' */

/* Phase C PWM duty cycle output */
real32_T TFPM_PhaseCDutyRel;           /* Phase C relative duty cycle value */
real32_T TFPM_PhaseCLvmDuty;    /* Phase C space vector modulation duty cycle */
real32_T TFPM_PhaseCVoltNorm;  /* Phase C normalized voltage after modulation */
real32_T TFPM_ThreePhaseVoltMid;
                           /* Mid-point normalized voltage among three phases */



/* Real-time model */
static RT_MODEL_TrfPWMModulator_T TrfPWMModulator_M_;
RT_MODEL_TrfPWMModulator_T *const TrfPWMModulator_M = &TrfPWMModulator_M_;
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
/* Model step function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void TFPM_ModulatePwm_100us(void)
{
  real32_T rtb_Max;
  real32_T rtb_Min;
  boolean_T tmp;

  /* RootInportFunctionCallGenerator generated from: '<Root>/TFPM_ModulatePwm_100us' incorporates:
   *  SubSystem: '<Root>/TFPM_ModulatePwm_100us_sys'
   */
  /* SwitchCase: '<S4>/Switch Case' incorporates:
   *  Inport: '<Root>/CTSO_OperationMode'
   */
  switch (CTSO_OperationMode) {
   case OpenLoopCtrl:
   case VoltDirectCtrl:
   case ZeroPointCal:
    /* Outputs for IfAction SubSystem: '<S4>/OpenLoop' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* SignalConversion generated from: '<S10>/AlphaOl' incorporates:
     *  Inport: '<Root>/SVOL_OpenLoopAlphaVolt'
     */
    rtb_Min = SVOL_OpenLoopAlphaVolt;

    /* SignalConversion generated from: '<S10>/BetaOl' incorporates:
     *  Inport: '<Root>/SVOL_OpenLoopBetaVolt'
     */
    rtb_Max = SVOL_OpenLoopBetaVolt;

    /* End of Outputs for SubSystem: '<S4>/OpenLoop' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S4>/ClosedLoop' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* SignalConversion generated from: '<S7>/AlphaCl' incorporates:
     *  Inport: '<Root>/TFDA_AlphaVoltSp'
     */
    rtb_Min = TFDA_AlphaVoltSp;

    /* SignalConversion generated from: '<S7>/BetaCl' incorporates:
     *  Inport: '<Root>/TFDA_BetaVoltSp'
     */
    rtb_Max = TFDA_BetaVoltSp;

    /* End of Outputs for SubSystem: '<S4>/ClosedLoop' */
    break;
  }

  /* End of SwitchCase: '<S4>/Switch Case' */

  /* DataStoreWrite: '<S8>/Data Store Write' */
  TFPM_AlphaVoltSp = rtb_Min;

  /* DataStoreWrite: '<S9>/Data Store Write' */
  TFPM_BetaVoltSp = rtb_Max;

  /* Product: '<S6>/Product' incorporates:
   *  DataStoreWrite: '<S14>/Data Store Write'
   *  Inport: '<Root>/SGPP_DcLinkVoltReciprocal'
   */
  TFPM_AlphaVoltNorm = rtb_Min * SGPP_DcLinkVoltReciprocal;

  /* Product: '<S5>/Product' incorporates:
   *  Constant: '<S5>/Constant'
   *  DataStoreWrite: '<S14>/Data Store Write'
   */
  rtb_Min = TFPM_AlphaVoltNorm * (-0.5F);

  /* Product: '<S6>/Product1' incorporates:
   *  DataStoreWrite: '<S15>/Data Store Write'
   *  Inport: '<Root>/SGPP_DcLinkVoltReciprocal'
   */
  TFPM_BetaVoltNorm = rtb_Max * SGPP_DcLinkVoltReciprocal;

  /* Product: '<S5>/Product1' incorporates:
   *  Constant: '<S5>/Constant1'
   *  DataStoreWrite: '<S15>/Data Store Write'
   */
  rtb_Max = TFPM_BetaVoltNorm * 0.866F;

  /* Sum: '<S5>/Add1' incorporates:
   *  DataStoreWrite: '<S11>/Data Store Write'
   */
  TFPM_PhaseCVoltNorm = rtb_Min - rtb_Max;

  /* Sum: '<S5>/Add' incorporates:
   *  DataStoreWrite: '<S12>/Data Store Write'
   */
  TFPM_PhaseBVoltNorm = rtb_Min + rtb_Max;

  /* DataTypeConversion: '<S5>/Data Type Conversion1' incorporates:
   *  DataStoreWrite: '<S13>/Data Store Write'
   *  DataStoreWrite: '<S14>/Data Store Write'
   */
  TFPM_PhaseAVoltNorm = TFPM_AlphaVoltNorm;

  /* Product: '<S6>/Product2' incorporates:
   *  DataStoreWrite: '<S16>/Data Store Write'
   *  Inport: '<Root>/SGPP_DcLinkVoltReciprocal'
   *  Inport: '<Root>/TFEC_PhaseACompVolt'
   */
  TFPM_PhaseACompDutyLim = TFEC_PhaseACompVolt * SGPP_DcLinkVoltReciprocal;

  /* Product: '<S6>/Product3' incorporates:
   *  DataStoreWrite: '<S17>/Data Store Write'
   *  Inport: '<Root>/SGPP_DcLinkVoltReciprocal'
   *  Inport: '<Root>/TFEC_PhaseBCompVolt'
   */
  TFPM_PhaseBCompDutyLim = TFEC_PhaseBCompVolt * SGPP_DcLinkVoltReciprocal;

  /* Product: '<S6>/Product4' incorporates:
   *  DataStoreWrite: '<S18>/Data Store Write'
   *  Inport: '<Root>/SGPP_DcLinkVoltReciprocal'
   *  Inport: '<Root>/TFEC_PhaseCCompVolt'
   */
  TFPM_PhaseCCompDutyLim = TFEC_PhaseCCompVolt * SGPP_DcLinkVoltReciprocal;

  /* Product: '<S20>/Product1' incorporates:
   *  Constant: '<S20>/Constant'
   *  Constant: '<S28>/Constant'
   *  DataStoreWrite: '<S27>/Data Store Write'
   *  Inport: '<Root>/SGPP_SampleTime1Reciprocal'
   *  Product: '<S20>/Product'
   */
  TFPM_MinSwitchTimeRel = SGPP_SampleTime1Reciprocal * 1.0E-9F *
    TFPM_MinSwitchTime_C;

  /* MinMax: '<S22>/Max' incorporates:
   *  DataStoreWrite: '<S12>/Data Store Write'
   *  DataStoreWrite: '<S13>/Data Store Write'
   *  MinMax: '<S22>/Min'
   */
  tmp = rtIsNaNF(TFPM_PhaseBVoltNorm);
  if ((TFPM_PhaseAVoltNorm >= TFPM_PhaseBVoltNorm) || tmp) {
    rtb_Min = TFPM_PhaseAVoltNorm;
  } else {
    rtb_Min = TFPM_PhaseBVoltNorm;
  }

  /* MinMax: '<S22>/Min' incorporates:
   *  DataStoreWrite: '<S12>/Data Store Write'
   *  DataStoreWrite: '<S13>/Data Store Write'
   *  MinMax: '<S22>/Max'
   */
  if ((TFPM_PhaseAVoltNorm <= TFPM_PhaseBVoltNorm) || tmp) {
    rtb_Max = TFPM_PhaseAVoltNorm;
  } else {
    rtb_Max = TFPM_PhaseBVoltNorm;
  }

  /* MinMax: '<S22>/Max' incorporates:
   *  DataStoreWrite: '<S11>/Data Store Write'
   *  MinMax: '<S22>/Min'
   */
  tmp = !rtIsNaNF(TFPM_PhaseCVoltNorm);
  if ((!(rtb_Min >= TFPM_PhaseCVoltNorm)) && tmp) {
    rtb_Min = TFPM_PhaseCVoltNorm;
  }

  /* MinMax: '<S22>/Min' incorporates:
   *  DataStoreWrite: '<S11>/Data Store Write'
   *  MinMax: '<S22>/Max'
   */
  if ((!(rtb_Max <= TFPM_PhaseCVoltNorm)) && tmp) {
    rtb_Max = TFPM_PhaseCVoltNorm;
  }

  /* Gain: '<S22>/Gain' incorporates:
   *  Constant: '<S22>/Constant'
   *  DataStoreWrite: '<S33>/Data Store Write'
   *  MinMax: '<S22>/Max'
   *  MinMax: '<S22>/Min'
   *  Sum: '<S22>/Add'
   */
  TFPM_ThreePhaseVoltMid = ((1.0F - rtb_Min) - rtb_Max) * 0.5F;

  /* Sum: '<S22>/Add1' incorporates:
   *  DataStoreWrite: '<S11>/Data Store Write'
   *  DataStoreWrite: '<S12>/Data Store Write'
   *  DataStoreWrite: '<S13>/Data Store Write'
   *  DataStoreWrite: '<S33>/Data Store Write'
   */
  TFPM_PhaseASvmDuty = TFPM_ThreePhaseVoltMid + TFPM_PhaseAVoltNorm;
  TFPM_PhaseBSvmDuty = TFPM_ThreePhaseVoltMid + TFPM_PhaseBVoltNorm;
  TFPM_PhaseCLvmDuty = TFPM_ThreePhaseVoltMid + TFPM_PhaseCVoltNorm;

  /* Sum: '<S21>/Add' incorporates:
   *  DataStoreWrite: '<S16>/Data Store Write'
   *  DataStoreWrite: '<S17>/Data Store Write'
   *  DataStoreWrite: '<S18>/Data Store Write'
   */
  TFPM_PhaseADuty = TFPM_PhaseACompDutyLim + TFPM_PhaseASvmDuty;
  TFPM_PhaseBDuty = TFPM_PhaseBCompDutyLim + TFPM_PhaseBSvmDuty;
  TFPM_PhaseCDuty = TFPM_PhaseCCompDutyLim + TFPM_PhaseCLvmDuty;

  /* Sum: '<S21>/Add1' incorporates:
   *  Constant: '<S21>/Constant2'
   *  DataStoreWrite: '<S27>/Data Store Write'
   */
  rtb_Min = 1.0F - TFPM_MinSwitchTimeRel;

  /* RelationalOperator: '<S21>/Relational Operator' */
  TFPM_PhaseCDutyRel = TFPM_PhaseADuty;

  /* Switch: '<S21>/Switch3' incorporates:
   *  Constant: '<S21>/Constant6'
   *  RelationalOperator: '<S21>/Relational Operator3'
   */
  if (TFPM_PhaseASvmDuty < 0.999F) {
    /* Switch: '<S21>/Switch2' incorporates:
     *  Constant: '<S21>/Constant4'
     *  RelationalOperator: '<S21>/Relational Operator2'
     */
    if (TFPM_PhaseASvmDuty > 0.001F) {
      /* Switch: '<S21>/Switch' incorporates:
       *  DataStoreWrite: '<S27>/Data Store Write'
       *  RelationalOperator: '<S21>/Relational Operator'
       */
      if (TFPM_PhaseADuty > TFPM_MinSwitchTimeRel) {
        /* Switch: '<S21>/Switch1' incorporates:
         *  RelationalOperator: '<S21>/Relational Operator1'
         */
        if (!(TFPM_PhaseADuty < rtb_Min)) {
          /* Sum: '<S21>/Add' incorporates:
           *  Constant: '<S21>/Constant1'
           */
          TFPM_PhaseCDutyRel = 1.0F;
        }
      } else {
        /* Sum: '<S21>/Add' incorporates:
         *  Constant: '<S21>/Constant'
         */
        TFPM_PhaseCDutyRel = 0.0F;
      }
    } else {
      /* Sum: '<S21>/Add' incorporates:
       *  Constant: '<S21>/Constant3'
       */
      TFPM_PhaseCDutyRel = 0.0F;
    }
  } else {
    /* Sum: '<S21>/Add' incorporates:
     *  Constant: '<S21>/Constant5'
     */
    TFPM_PhaseCDutyRel = 1.0F;
  }

  TFPM_PhaseADuty = TFPM_PhaseCDutyRel;

  /* RelationalOperator: '<S21>/Relational Operator' */
  TFPM_PhaseCDutyRel = TFPM_PhaseBDuty;

  /* Switch: '<S21>/Switch3' incorporates:
   *  Constant: '<S21>/Constant6'
   *  RelationalOperator: '<S21>/Relational Operator3'
   */
  if (TFPM_PhaseBSvmDuty < 0.999F) {
    /* Switch: '<S21>/Switch2' incorporates:
     *  Constant: '<S21>/Constant4'
     *  RelationalOperator: '<S21>/Relational Operator2'
     */
    if (TFPM_PhaseBSvmDuty > 0.001F) {
      /* Switch: '<S21>/Switch' incorporates:
       *  DataStoreWrite: '<S27>/Data Store Write'
       *  RelationalOperator: '<S21>/Relational Operator'
       */
      if (TFPM_PhaseBDuty > TFPM_MinSwitchTimeRel) {
        /* Switch: '<S21>/Switch1' incorporates:
         *  RelationalOperator: '<S21>/Relational Operator1'
         */
        if (!(TFPM_PhaseBDuty < rtb_Min)) {
          /* Sum: '<S21>/Add' incorporates:
           *  Constant: '<S21>/Constant1'
           */
          TFPM_PhaseCDutyRel = 1.0F;
        }
      } else {
        /* Sum: '<S21>/Add' incorporates:
         *  Constant: '<S21>/Constant'
         */
        TFPM_PhaseCDutyRel = 0.0F;
      }
    } else {
      /* Sum: '<S21>/Add' incorporates:
       *  Constant: '<S21>/Constant3'
       */
      TFPM_PhaseCDutyRel = 0.0F;
    }
  } else {
    /* Sum: '<S21>/Add' incorporates:
     *  Constant: '<S21>/Constant5'
     */
    TFPM_PhaseCDutyRel = 1.0F;
  }

  TFPM_PhaseBDuty = TFPM_PhaseCDutyRel;

  /* RelationalOperator: '<S21>/Relational Operator' */
  TFPM_PhaseCDutyRel = TFPM_PhaseCDuty;

  /* Switch: '<S21>/Switch3' incorporates:
   *  Constant: '<S21>/Constant6'
   *  RelationalOperator: '<S21>/Relational Operator3'
   */
  if (TFPM_PhaseCLvmDuty < 0.999F) {
    /* Switch: '<S21>/Switch2' incorporates:
     *  Constant: '<S21>/Constant4'
     *  RelationalOperator: '<S21>/Relational Operator2'
     */
    if (TFPM_PhaseCLvmDuty > 0.001F) {
      /* Switch: '<S21>/Switch' incorporates:
       *  DataStoreWrite: '<S27>/Data Store Write'
       *  RelationalOperator: '<S21>/Relational Operator'
       */
      if (TFPM_PhaseCDuty > TFPM_MinSwitchTimeRel) {
        /* Switch: '<S21>/Switch1' incorporates:
         *  RelationalOperator: '<S21>/Relational Operator1'
         */
        if (!(TFPM_PhaseCDuty < rtb_Min)) {
          /* Sum: '<S21>/Add' incorporates:
           *  Constant: '<S21>/Constant1'
           */
          TFPM_PhaseCDutyRel = 1.0F;
        }
      } else {
        /* Sum: '<S21>/Add' incorporates:
         *  Constant: '<S21>/Constant'
         */
        TFPM_PhaseCDutyRel = 0.0F;
      }
    } else {
      /* Sum: '<S21>/Add' incorporates:
       *  Constant: '<S21>/Constant3'
       */
      TFPM_PhaseCDutyRel = 0.0F;
    }
  } else {
    /* Sum: '<S21>/Add' incorporates:
     *  Constant: '<S21>/Constant5'
     */
    TFPM_PhaseCDutyRel = 1.0F;
  }

  /* DataStoreWrite: '<S29>/Data Store Write' */
  TFPM_PhaseADutyRel = TFPM_PhaseADuty;

  /* DataStoreWrite: '<S30>/Data Store Write' */
  TFPM_PhaseBDutyRel = TFPM_PhaseBDuty;

  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S23>/Constant'
   *  Gain: '<S19>/Gain'
   *  Sum: '<S19>/Add'
   */
  if (TFPM_HighSideSwitchSel_C != 0) {
    TFPM_PhaseADuty = 100.0F * TFPM_PhaseADuty;
    TFPM_PhaseBDuty = 100.0F * TFPM_PhaseBDuty;
    TFPM_PhaseCDuty = 100.0F * TFPM_PhaseCDutyRel;
  } else {
    TFPM_PhaseADuty = 100.0F - 100.0F * TFPM_PhaseADuty;
    TFPM_PhaseBDuty = 100.0F - 100.0F * TFPM_PhaseBDuty;
    TFPM_PhaseCDuty = 100.0F - 100.0F * TFPM_PhaseCDutyRel;
  }

  /* End of Switch: '<S19>/Switch' */

  /* Switch: '<S26>/Switch2' incorporates:
   *  Constant: '<S24>/Constant'
   *  Constant: '<S25>/Constant'
   *  RelationalOperator: '<S26>/LowerRelop1'
   *  RelationalOperator: '<S26>/UpperRelop'
   *  Switch: '<S26>/Switch'
   */
  if (TFPM_PhaseADuty > TFPM_DutyUpperLimit_C) {
    /* Sum: '<S21>/Add' incorporates:
     *  SignalConversion: '<S3>/Signal Conversion'
     */
    TFPM_PhaseADuty = TFPM_DutyUpperLimit_C;
  } else if (TFPM_PhaseADuty < TFPM_DutyLowerLimit_C) {
    /* Sum: '<S21>/Add' incorporates:
     *  Constant: '<S25>/Constant'
     *  SignalConversion: '<S3>/Signal Conversion'
     *  Switch: '<S26>/Switch'
     */
    TFPM_PhaseADuty = TFPM_DutyLowerLimit_C;
  }

  if (TFPM_PhaseBDuty > TFPM_DutyUpperLimit_C) {
    /* Sum: '<S21>/Add' incorporates:
     *  SignalConversion: '<S3>/Signal Conversion1'
     */
    TFPM_PhaseBDuty = TFPM_DutyUpperLimit_C;
  } else if (TFPM_PhaseBDuty < TFPM_DutyLowerLimit_C) {
    /* Sum: '<S21>/Add' incorporates:
     *  Constant: '<S25>/Constant'
     *  SignalConversion: '<S3>/Signal Conversion1'
     *  Switch: '<S26>/Switch'
     */
    TFPM_PhaseBDuty = TFPM_DutyLowerLimit_C;
  }

  if (TFPM_PhaseCDuty > TFPM_DutyUpperLimit_C) {
    /* Sum: '<S21>/Add' incorporates:
     *  SignalConversion: '<S3>/Signal Conversion2'
     */
    TFPM_PhaseCDuty = TFPM_DutyUpperLimit_C;
  } else if (TFPM_PhaseCDuty < TFPM_DutyLowerLimit_C) {
    /* Sum: '<S21>/Add' incorporates:
     *  Constant: '<S25>/Constant'
     *  SignalConversion: '<S3>/Signal Conversion2'
     *  Switch: '<S26>/Switch'
     */
    TFPM_PhaseCDuty = TFPM_DutyLowerLimit_C;
  }

  /* End of Switch: '<S26>/Switch2' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/TFPM_ModulatePwm_100us' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model initialize function */
void TrfPWMModulator_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void TrfPWMModulator_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

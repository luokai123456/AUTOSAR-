/*
 * File: TrfInverterErrorComp.c
 *
 * Code generated for Simulink model 'TrfInverterErrorComp'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:29:06 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TrfInverterErrorComp.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "TrfInverterErrorComp_types.h"
#include "TrfInverterErrorComp_private.h"

/* Exported data definition */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Par */
volatile real32_T TFEC_AngleFactor_C = 1.6F;/* Referenced by: '<S49>/Constant' */

/* Correction factor for electrical angle compensation */
volatile uint8_T TFEC_CompMasterEna_C = 1U;/* Referenced by: '<S22>/Constant' */

/* Master enable for compensation independent of conditions */
volatile real32_T TFEC_CurrentRampStart_C = 0.0F;/* Referenced by: '<S35>/Constant' */

/* Current threshold for sign function ramp initiation */
volatile uint8_T TFEC_CurrentReadMode_C = 1U;/* Referenced by: '<S41>/Constant' */

/* Current source selection: 0=measured dq, 1=dq setpoints */
volatile real32_T TFEC_CurrentSignMax_C = 0.5F;/* Referenced by: '<S33>/Constant' */

/* Current threshold for full sign saturation */
volatile real32_T TFEC_CurrentThrActivate_C = 2.0F;/* Referenced by: '<S26>/Constant' */

/* Current threshold to activate compensation */
volatile real32_T TFEC_CurrentThrDeactivate_C = 0.0F;/* Referenced by: '<S25>/Constant' */

/* Current threshold to deactivate compensation */
volatile uint8_T TFEC_DeadTimeCompEna_C = 1U;/* Referenced by: '<S16>/Constant' */

/* Enable flag for dead-time compensation */
volatile real32_T TFEC_DeadTimeDuration_C = 3.0E-6F;/* Referenced by: '<S15>/Constant' */

/* Dead-time duration for inverter switching */
volatile real32_T TFEC_DeviceVoltDrop_C = 1.1F;/* Referenced by: '<S17>/Constant' */

/* Voltage drop per semiconductor device */
volatile real32_T TFEC_RampSlopeFactor_C = 0.07F;/* Referenced by: '<S34>/Constant' */

/* Slope factor for current sign ramp function */
volatile real32_T TFEC_SpeedThrActivate_C = 150.0F;/* Referenced by: '<S29>/Constant' */

/* Speed threshold to activate compensation */
volatile real32_T TFEC_SpeedThrDeactivate_C = 75.0F;/* Referenced by: '<S28>/Constant' */

/* Speed threshold to deactivate compensation */
volatile uint8_T TFEC_VoltDropCompEna_C = 1U;/* Referenced by: '<S18>/Constant' */

/* Enable flag for voltage drop compensation */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Sig */
uint8_T TFEC_CompConditionEna;
                     /* Conditional enable flag based on operating conditions */
real32_T TFEC_CurrentMagCalc;/* Calculated current magnitude for compensation */
real32_T TFEC_IdRead;    /* D-axis current value for compensation calculation */
real32_T TFEC_IqRead;    /* Q-axis current value for compensation calculation */
real32_T TFEC_PhaseACompVolt;          /* '<S3>/Switch' */

/* Phase A total compensation voltage */
real32_T TFEC_PhaseACurrentCalc;
                               /* Calculated phase A current for compensation */
real32_T TFEC_PhaseACurrentSign;       /* Phase A current direction indicator */
real32_T TFEC_PhaseADeadTimeComp;   /* Phase A dead-time compensation voltage */
real32_T TFEC_PhaseAVoltDrop;          /* Phase A voltage drop compensation */
real32_T TFEC_PhaseBCompVolt;          /* '<S3>/Switch1' */

/* Phase B total compensation voltage */
real32_T TFEC_PhaseBCurrentCalc;
                               /* Calculated phase B current for compensation */
real32_T TFEC_PhaseBCurrentSign;       /* Phase B current direction indicator */
real32_T TFEC_PhaseBDeadTimeComp;   /* Phase B dead-time compensation voltage */
real32_T TFEC_PhaseBVoltDrop;          /* Phase B voltage drop compensation */
real32_T TFEC_PhaseCCompVolt;          /* '<S3>/Switch2' */

/* Phase C total compensation voltage */
real32_T TFEC_PhaseCCurrentCalc;
                               /* Calculated phase C current for compensation */
real32_T TFEC_PhaseCCurrentSign;       /* Phase C current direction indicator */
real32_T TFEC_PhaseCDeadTimeComp;   /* Phase C dead-time compensation voltage */
real32_T TFEC_PhaseCVoltDrop;          /* Phase C voltage drop compensation */
real32_T TFEC_StatorCurrentIs;         /* '<S5>/Sqrt' */

/* Stator Current */


/* Block states (default storage) */
DW_TrfInverterErrorComp_T TrfInverterErrorComp_DW;

/* Real-time model */
static RT_MODEL_TrfInverterErrorComp_T TrfInverterErrorComp_M_;
RT_MODEL_TrfInverterErrorComp_T *const TrfInverterErrorComp_M =
  &TrfInverterErrorComp_M_;
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
/* Model step function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void TFEC_CompInverterError_100us(void)
{
  real32_T rtb_Add1_d;
  real32_T rtb_Add_f;
  real32_T rtb_Product1_h;
  real32_T rtb_Sin;
  real32_T rtb_Switch_d2;
  int16_T tmp;

  /* RootInportFunctionCallGenerator generated from: '<Root>/TFEC_CompInverterError_100us' incorporates:
   *  SubSystem: '<Root>/TFEC_CompInverterError_100us_sys'
   */
  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S17>/Constant'
   *  Constant: '<S18>/Constant'
   */
  if (TFEC_VoltDropCompEna_C != 0) {
    rtb_Switch_d2 = TFEC_DeviceVoltDrop_C;
  } else {
    rtb_Switch_d2 = 0.0F;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Sum: '<S4>/Add1' incorporates:
   *  Constant: '<S33>/Constant'
   *  Constant: '<S35>/Constant'
   */
  rtb_Add1_d = TFEC_CurrentSignMax_C - TFEC_CurrentRampStart_C;

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S41>/Constant'
   *  DataStoreWrite: '<S39>/Data Store Write'
   *  Inport: '<Root>/CTLC_IdSpLimited'
   *  Inport: '<Root>/TFPD_IdMeasured'
   */
  if (TFEC_CurrentReadMode_C != 0) {
    TFEC_IdRead = CTLC_IdSpLimited;
  } else {
    TFEC_IdRead = TFPD_IdMeasured;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Sum: '<S47>/Add' incorporates:
   *  Constant: '<S49>/Constant'
   *  Inport: '<Root>/SGPP_ElecAngle'
   *  Inport: '<Root>/SGPP_ElecSpeed'
   *  Inport: '<Root>/SGPP_SampleTime1'
   *  Product: '<S47>/Product'
   *  Product: '<S47>/Product1'
   */
  rtb_Sin = TFEC_AngleFactor_C * SGPP_ElecSpeed * SGPP_SampleTime1 +
    SGPP_ElecAngle;

  /* DataTypeConversion: '<S47>/Data Type Conversion' incorporates:
   *  Constant: '<S47>/Constant'
   *  Product: '<S47>/Product2'
   */
  rtb_Add_f = (real32_T)floor(rtb_Sin * 0.159154907F);
  if (rtb_Add_f < 32768.0F) {
    if (rtb_Add_f >= -32768.0F) {
      tmp = (int16_T)rtb_Add_f;
    } else {
      tmp = INT16_MIN;
    }
  } else {
    tmp = INT16_MAX;
  }

  /* Sum: '<S47>/Add1' incorporates:
   *  Constant: '<S47>/Constant1'
   *  DataTypeConversion: '<S47>/Data Type Conversion'
   *  DataTypeConversion: '<S47>/Data Type Conversion1'
   *  Product: '<S47>/Product3'
   */
  rtb_Sin -= (real32_T)tmp * 6.28318548F;

  /* Trigonometry: '<S48>/Cos' */
  rtb_Product1_h = (real32_T)cos(rtb_Sin);

  /* Switch: '<S5>/Switch1' incorporates:
   *  Constant: '<S41>/Constant'
   *  DataStoreWrite: '<S38>/Data Store Write'
   *  Inport: '<Root>/CTLC_IqSpLimited'
   *  Inport: '<Root>/TFPD_IqMeasured'
   */
  if (TFEC_CurrentReadMode_C != 0) {
    TFEC_IqRead = CTLC_IqSpLimited;
  } else {
    TFEC_IqRead = TFPD_IqMeasured;
  }

  /* End of Switch: '<S5>/Switch1' */

  /* Trigonometry: '<S48>/Sin' */
  rtb_Sin = (real32_T)sin(rtb_Sin);

  /* Sum: '<S48>/Add' incorporates:
   *  DataStoreWrite: '<S38>/Data Store Write'
   *  DataStoreWrite: '<S39>/Data Store Write'
   *  Product: '<S48>/Product'
   *  Product: '<S48>/Product1'
   */
  rtb_Add_f = TFEC_IdRead * rtb_Product1_h - TFEC_IqRead * rtb_Sin;

  /* DataTypeConversion: '<S42>/Data Type Conversion1' incorporates:
   *  DataStoreWrite: '<S46>/Data Store Write'
   */
  TFEC_PhaseACurrentCalc = rtb_Add_f;

  /* Product: '<S42>/Product' incorporates:
   *  Constant: '<S42>/Constant'
   */
  rtb_Add_f *= (-0.5F);

  /* Product: '<S42>/Product1' incorporates:
   *  Constant: '<S42>/Constant1'
   *  DataStoreWrite: '<S38>/Data Store Write'
   *  DataStoreWrite: '<S39>/Data Store Write'
   *  Product: '<S48>/Product2'
   *  Product: '<S48>/Product3'
   *  Sum: '<S48>/Add1'
   */
  rtb_Product1_h = (TFEC_IdRead * rtb_Sin + TFEC_IqRead * rtb_Product1_h) *
    0.866F;

  /* Sum: '<S42>/Add' incorporates:
   *  DataStoreWrite: '<S45>/Data Store Write'
   */
  TFEC_PhaseBCurrentCalc = rtb_Add_f + rtb_Product1_h;

  /* Sum: '<S42>/Add1' incorporates:
   *  DataStoreWrite: '<S44>/Data Store Write'
   */
  TFEC_PhaseCCurrentCalc = rtb_Add_f - rtb_Product1_h;

  /* Sum: '<S4>/Add' incorporates:
   *  Abs: '<S4>/Abs'
   *  Constant: '<S35>/Constant'
   *  DataStoreWrite: '<S44>/Data Store Write'
   *  DataStoreWrite: '<S45>/Data Store Write'
   *  DataStoreWrite: '<S46>/Data Store Write'
   */
  TFEC_PhaseACurrentSign = (real32_T)fabs(TFEC_PhaseACurrentCalc) -
    TFEC_CurrentRampStart_C;
  TFEC_PhaseBCurrentSign = (real32_T)fabs(TFEC_PhaseBCurrentCalc) -
    TFEC_CurrentRampStart_C;
  rtb_Sin = (real32_T)fabs(TFEC_PhaseCCurrentCalc) - TFEC_CurrentRampStart_C;

  /* Switch: '<S36>/Switch2' incorporates:
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S36>/LowerRelop1'
   *  RelationalOperator: '<S36>/UpperRelop'
   *  Switch: '<S36>/Switch'
   */
  if (TFEC_PhaseACurrentSign > rtb_Add1_d) {
    /* Sum: '<S4>/Add' */
    TFEC_PhaseACurrentSign = rtb_Add1_d;
  } else if (TFEC_PhaseACurrentSign < 0.0F) {
    /* Sum: '<S4>/Add' incorporates:
     *  Constant: '<S4>/Constant'
     *  Switch: '<S36>/Switch'
     */
    TFEC_PhaseACurrentSign = 0.0F;
  }

  /* Signum: '<S4>/Sign' incorporates:
   *  DataStoreWrite: '<S46>/Data Store Write'
   */
  if (rtIsNaNF(TFEC_PhaseACurrentCalc)) {
    rtb_Add_f = (rtNaNF);
  } else if (TFEC_PhaseACurrentCalc < 0.0F) {
    rtb_Add_f = -1.0F;
  } else {
    rtb_Add_f = (real32_T)(TFEC_PhaseACurrentCalc > 0.0F);
  }

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S34>/Constant'
   *  Product: '<S4>/Product'
   *  Signum: '<S4>/Sign'
   *  Switch: '<S36>/Switch2'
   */
  TFEC_PhaseCCurrentSign = TFEC_RampSlopeFactor_C * TFEC_PhaseACurrentSign *
    rtb_Add_f;

  /* Switch: '<S37>/Switch2' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   *  RelationalOperator: '<S37>/LowerRelop1'
   *  RelationalOperator: '<S37>/UpperRelop'
   *  Switch: '<S37>/Switch'
   */
  if (TFEC_PhaseCCurrentSign > 1.0F) {
    /* Sum: '<S4>/Add' */
    TFEC_PhaseCCurrentSign = 1.0F;
  } else if (TFEC_PhaseCCurrentSign < (-1.0F)) {
    /* Sum: '<S4>/Add' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Switch: '<S37>/Switch'
     */
    TFEC_PhaseCCurrentSign = -1.0F;
  }

  /* Product: '<S4>/Product' */
  TFEC_PhaseACurrentSign = TFEC_PhaseCCurrentSign;

  /* Switch: '<S36>/Switch2' incorporates:
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S36>/LowerRelop1'
   *  RelationalOperator: '<S36>/UpperRelop'
   *  Switch: '<S36>/Switch'
   */
  if (TFEC_PhaseBCurrentSign > rtb_Add1_d) {
    /* Sum: '<S4>/Add' */
    TFEC_PhaseBCurrentSign = rtb_Add1_d;
  } else if (TFEC_PhaseBCurrentSign < 0.0F) {
    /* Sum: '<S4>/Add' incorporates:
     *  Constant: '<S4>/Constant'
     *  Switch: '<S36>/Switch'
     */
    TFEC_PhaseBCurrentSign = 0.0F;
  }

  /* Signum: '<S4>/Sign' incorporates:
   *  DataStoreWrite: '<S45>/Data Store Write'
   */
  if (rtIsNaNF(TFEC_PhaseBCurrentCalc)) {
    rtb_Add_f = (rtNaNF);
  } else if (TFEC_PhaseBCurrentCalc < 0.0F) {
    rtb_Add_f = -1.0F;
  } else {
    rtb_Add_f = (real32_T)(TFEC_PhaseBCurrentCalc > 0.0F);
  }

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S34>/Constant'
   *  Product: '<S4>/Product'
   *  Signum: '<S4>/Sign'
   *  Switch: '<S36>/Switch2'
   */
  TFEC_PhaseCCurrentSign = TFEC_RampSlopeFactor_C * TFEC_PhaseBCurrentSign *
    rtb_Add_f;

  /* Switch: '<S37>/Switch2' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   *  RelationalOperator: '<S37>/LowerRelop1'
   *  RelationalOperator: '<S37>/UpperRelop'
   *  Switch: '<S37>/Switch'
   */
  if (TFEC_PhaseCCurrentSign > 1.0F) {
    /* Sum: '<S4>/Add' */
    TFEC_PhaseCCurrentSign = 1.0F;
  } else if (TFEC_PhaseCCurrentSign < (-1.0F)) {
    /* Sum: '<S4>/Add' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Switch: '<S37>/Switch'
     */
    TFEC_PhaseCCurrentSign = -1.0F;
  }

  /* Product: '<S4>/Product' */
  TFEC_PhaseBCurrentSign = TFEC_PhaseCCurrentSign;

  /* Switch: '<S36>/Switch2' incorporates:
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S36>/LowerRelop1'
   *  RelationalOperator: '<S36>/UpperRelop'
   *  Switch: '<S36>/Switch'
   */
  if (rtb_Sin > rtb_Add1_d) {
    rtb_Sin = rtb_Add1_d;
  } else if (rtb_Sin < 0.0F) {
    /* Switch: '<S36>/Switch' incorporates:
     *  Constant: '<S4>/Constant'
     */
    rtb_Sin = 0.0F;
  }

  /* Signum: '<S4>/Sign' incorporates:
   *  DataStoreWrite: '<S44>/Data Store Write'
   */
  if (rtIsNaNF(TFEC_PhaseCCurrentCalc)) {
    rtb_Add_f = (rtNaNF);
  } else if (TFEC_PhaseCCurrentCalc < 0.0F) {
    rtb_Add_f = -1.0F;
  } else {
    rtb_Add_f = (real32_T)(TFEC_PhaseCCurrentCalc > 0.0F);
  }

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S34>/Constant'
   *  Product: '<S4>/Product'
   *  Signum: '<S4>/Sign'
   *  Switch: '<S36>/Switch2'
   */
  TFEC_PhaseCCurrentSign = TFEC_RampSlopeFactor_C * rtb_Sin * rtb_Add_f;

  /* Switch: '<S37>/Switch2' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   *  RelationalOperator: '<S37>/LowerRelop1'
   *  RelationalOperator: '<S37>/UpperRelop'
   *  Switch: '<S37>/Switch'
   */
  if (TFEC_PhaseCCurrentSign > 1.0F) {
    /* Sum: '<S4>/Add' */
    TFEC_PhaseCCurrentSign = 1.0F;
  } else if (TFEC_PhaseCCurrentSign < (-1.0F)) {
    /* Sum: '<S4>/Add' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Switch: '<S37>/Switch'
     */
    TFEC_PhaseCCurrentSign = -1.0F;
  }

  /* Product: '<S2>/Product1' incorporates:
   *  DataStoreWrite: '<S7>/Data Store Write'
   */
  TFEC_PhaseBVoltDrop = rtb_Switch_d2 * TFEC_PhaseBCurrentSign;

  /* Product: '<S2>/Product' incorporates:
   *  DataStoreWrite: '<S8>/Data Store Write'
   */
  TFEC_PhaseAVoltDrop = rtb_Switch_d2 * TFEC_PhaseACurrentSign;

  /* Product: '<S2>/Product2' incorporates:
   *  DataStoreWrite: '<S9>/Data Store Write'
   */
  TFEC_PhaseCVoltDrop = rtb_Switch_d2 * TFEC_PhaseCCurrentSign;

  /* Switch: '<S13>/Switch1' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Constant: '<S15>/Constant'
   *  Constant: '<S16>/Constant'
   *  Inport: '<Root>/SGPP_DcLinkVoltMeas'
   *  Inport: '<Root>/SGPP_SampleTime1Reciprocal'
   *  Product: '<S13>/Product3'
   */
  if (TFEC_DeadTimeCompEna_C != 0) {
    rtb_Add_f = SGPP_DcLinkVoltMeas * SGPP_SampleTime1Reciprocal *
      TFEC_DeadTimeDuration_C;
  } else {
    rtb_Add_f = 0.0F;
  }

  /* End of Switch: '<S13>/Switch1' */

  /* Product: '<S2>/Product4' incorporates:
   *  DataStoreWrite: '<S10>/Data Store Write'
   */
  TFEC_PhaseADeadTimeComp = rtb_Add_f * TFEC_PhaseACurrentSign;

  /* Product: '<S2>/Product5' incorporates:
   *  DataStoreWrite: '<S11>/Data Store Write'
   */
  TFEC_PhaseBDeadTimeComp = rtb_Add_f * TFEC_PhaseBCurrentSign;

  /* Product: '<S2>/Product6' incorporates:
   *  DataStoreWrite: '<S12>/Data Store Write'
   */
  TFEC_PhaseCDeadTimeComp = rtb_Add_f * TFEC_PhaseCCurrentSign;

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S28>/Constant'
   *  Constant: '<S29>/Constant'
   *  Delay: '<S27>/Delay'
   *  Inport: '<Root>/SGPP_MechSpeedAbsolute'
   *  RelationalOperator: '<S27>/Relational Operator1'
   *  RelationalOperator: '<S27>/Relational Operator2'
   *  Switch: '<S27>/Switch1'
   */
  if (SGPP_MechSpeedAbsolute >= TFEC_SpeedThrActivate_C) {
    TrfInverterErrorComp_DW.Delay_DSTATE = true;
  } else if (SGPP_MechSpeedAbsolute < TFEC_SpeedThrDeactivate_C) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S27>/Constant1'
     *  Delay: '<S27>/Delay'
     */
    TrfInverterErrorComp_DW.Delay_DSTATE = false;
  }

  /* End of Switch: '<S27>/Switch' */

  /* Sqrt: '<S5>/Sqrt' incorporates:
   *  DataStoreWrite: '<S38>/Data Store Write'
   *  DataStoreWrite: '<S39>/Data Store Write'
   *  Product: '<S5>/Product'
   *  Product: '<S5>/Product1'
   *  Sum: '<S5>/Add'
   */
  TFEC_StatorCurrentIs = (real32_T)sqrt(TFEC_IdRead * TFEC_IdRead + TFEC_IqRead *
    TFEC_IqRead);

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S24>/Constant'
   *  Constant: '<S25>/Constant'
   *  Constant: '<S26>/Constant'
   *  Delay: '<S24>/Delay'
   *  RelationalOperator: '<S24>/Relational Operator1'
   *  RelationalOperator: '<S24>/Relational Operator2'
   *  Switch: '<S24>/Switch1'
   */
  if (TFEC_StatorCurrentIs >= TFEC_CurrentThrActivate_C) {
    TrfInverterErrorComp_DW.Delay_DSTATE_k = true;
  } else if (TFEC_StatorCurrentIs < TFEC_CurrentThrDeactivate_C) {
    /* Switch: '<S24>/Switch1' incorporates:
     *  Constant: '<S24>/Constant1'
     *  Delay: '<S24>/Delay'
     */
    TrfInverterErrorComp_DW.Delay_DSTATE_k = false;
  }

  /* End of Switch: '<S24>/Switch' */

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Constant: '<S21>/Constant1'
   *  Constant: '<S21>/Constant2'
   *  Constant: '<S21>/Constant3'
   *  Constant: '<S22>/Constant'
   *  DataStoreWrite: '<S20>/Data Store Write'
   *  Delay: '<S24>/Delay'
   *  Delay: '<S27>/Delay'
   *  Logic: '<S21>/Logical Operator'
   *  Logic: '<S3>/Logical Operator1'
   *  RelationalOperator: '<S21>/Relational Operator'
   *  RelationalOperator: '<S21>/Relational Operator1'
   *  RelationalOperator: '<S21>/Relational Operator2'
   */
  TFEC_CompConditionEna = (uint8_T)((TFEC_CompMasterEna_C != 0) &&
    ((CTSO_OperationMode == TorqueCtrl) || (CTSO_OperationMode == SpeedCtrl) ||
     (CTSO_OperationMode == CurrCtrl)) && (TrfInverterErrorComp_DW.Delay_DSTATE
    != 0) && TrfInverterErrorComp_DW.Delay_DSTATE_k);

  /* Switch: '<S3>/Switch' incorporates:
   *  DataStoreWrite: '<S20>/Data Store Write'
   *  Switch: '<S3>/Switch1'
   *  Switch: '<S3>/Switch2'
   */
  if (TFEC_CompConditionEna != 0) {
    /* Switch: '<S3>/Switch' incorporates:
     *  DataStoreWrite: '<S10>/Data Store Write'
     *  DataStoreWrite: '<S8>/Data Store Write'
     *  Sum: '<S2>/Add'
     */
    TFEC_PhaseACompVolt = TFEC_PhaseAVoltDrop + TFEC_PhaseADeadTimeComp;

    /* Switch: '<S3>/Switch1' incorporates:
     *  DataStoreWrite: '<S11>/Data Store Write'
     *  DataStoreWrite: '<S7>/Data Store Write'
     *  Sum: '<S2>/Add2'
     */
    TFEC_PhaseBCompVolt = TFEC_PhaseBVoltDrop + TFEC_PhaseBDeadTimeComp;

    /* Switch: '<S3>/Switch2' incorporates:
     *  DataStoreWrite: '<S12>/Data Store Write'
     *  DataStoreWrite: '<S9>/Data Store Write'
     *  Sum: '<S2>/Add1'
     */
    TFEC_PhaseCCompVolt = TFEC_PhaseCVoltDrop + TFEC_PhaseCDeadTimeComp;
  } else {
    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<S3>/Constant'
     */
    TFEC_PhaseACompVolt = 0.0F;

    /* Switch: '<S3>/Switch1' incorporates:
     *  Constant: '<S3>/Constant'
     */
    TFEC_PhaseBCompVolt = 0.0F;

    /* Switch: '<S3>/Switch2' incorporates:
     *  Constant: '<S3>/Constant'
     */
    TFEC_PhaseCCompVolt = 0.0F;
  }

  /* End of Switch: '<S3>/Switch' */

  /* DataStoreWrite: '<S40>/Data Store Write' */
  TFEC_CurrentMagCalc = TFEC_StatorCurrentIs;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/TFEC_CompInverterError_100us' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model initialize function */
void TrfInverterErrorComp_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void TrfInverterErrorComp_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

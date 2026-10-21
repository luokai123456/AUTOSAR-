/*
 * File: CtlDeratingManager.c
 *
 * Code generated for Simulink model 'CtlDeratingManager'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:43:33 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CtlDeratingManager.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "rtwtypes.h"
#include "CtlDeratingManager_types.h"
#include "plook_u8ff_lincag.h"
#include "intrp1d_fu8fla.h"
#include "intrp2d_fu8fla.h"
#include "CtlDeratingManager_private.h"

/* Exported data definition */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
/* Volatile memory section */
/* Definition for custom storage class: Volatile */
volatile real32_T CTDM_AxisJunctionTempDerate_C[10] = { 50.0F, 51.0F, 52.0F,
  53.0F, 54.0F, 55.0F, 56.0F, 57.0F, 58.0F, 59.0F } ;/* Referenced by: '<S40>/Prelookup' */

/* Junction temperature axis breakpoints for torque derate (switch module temperature) */
volatile real32_T CTDM_AxisMotorTempDerate_C[10] = { 80.0F, 81.0F, 82.0F, 83.0F,
  84.0F, 85.0F, 86.0F, 87.0F, 88.0F, 89.0F } ;/* Referenced by: '<S37>/Prelookup' */

/* Motor winding temperature axis breakpoints for torque derate */
volatile real32_T CTDM_ScaleJunctionTempDerate_C[10] = { 1.0F, 0.888889F,
  0.777778F, 0.666667F, 0.555556F, 0.444444F, 0.333333F, 0.222222F, 0.111111F,
  0.0F } ;            /* Referenced by: '<S40>/Interpolation Using Prelookup' */

/* Junction temperature derate scale map (1.0=no derate, 0.0=full derate) */
volatile real32_T CTDM_ScaleMotorTempDerate_C[10] = { 1.0F, 0.888889F, 0.777778F,
  0.666667F, 0.555556F, 0.444444F, 0.333333F, 0.222222F, 0.111111F, 0.0F } ;
                      /* Referenced by: '<S37>/Interpolation Using Prelookup' */

/* Motor temperature derate scale map (1.0=no derate, 0.0=full derate) */
volatile real32_T CTDM_ScaleSpeedOverDerate_C[10] = { 1.0F, 0.888889F, 0.777778F,
  0.666667F, 0.555556F, 0.444444F, 0.333333F, 0.222222F, 0.111111F, 0.0F } ;
                      /* Referenced by: '<S25>/Interpolation Using Prelookup' */

/* Speed overspeed derate scale map (1.0=no derate, 0.0=full derate) */
volatile real32_T CTDM_ScaleVoltDCOverDerate_C[5] = { 1.0F, 0.75F, 0.5F, 0.25F,
  0.0F } ;            /* Referenced by: '<S54>/Interpolation Using Prelookup' */

/* DC bus overvoltage derate scale map (1.0=no derate, 0.0=full derate) */
volatile real32_T CTDM_ScaleVoltDCUnderDerate_C[5] = { 0.0F, 0.25F, 0.5F, 0.75F,
  1.0F } ;            /* Referenced by: '<S55>/Interpolation Using Prelookup' */

/* DC bus undervoltage derate scale map (1.0=no derate, 0.0=full derate) */
volatile real32_T CTDM_SpeedOverDerate_C[10] = { 2000.0F, 2050.0F, 2100.0F,
  2150.0F, 2200.0F, 2250.0F, 2300.0F, 2350.0F, 2400.0F, 2450.0F } ;/* Referenced by: '<S25>/Prelookup' */

/* Mechanical speed axis breakpoints for overspeed torque derate */
volatile real32_T CTDM_TqVoltDerateMotoring_C[50] = { 200.0F, 200.0F, 166.7F,
  125.0F, 100.0F, 83.3F, 71.4F, 62.5F, 55.6F, 50.0F, 200.0F, 200.0F, 183.3F,
  137.5F, 110.0F, 91.7F, 78.6F, 68.8F, 61.1F, 55.0F, 200.0F, 200.0F, 200.0F,
  150.0F, 120.0F, 100.0F, 85.7F, 75.0F, 66.7F, 60.0F, 200.0F, 200.0F, 200.0F,
  162.5F, 130.0F, 108.3F, 92.9F, 81.2F, 72.2F, 65.0F, 200.0F, 200.0F, 200.0F,
  175.0F, 140.0F, 116.7F, 100.0F, 87.5F, 77.8F, 70.0F } ;
                      /* Referenced by: '<S46>/Interpolation Using Prelookup' */

/* Maximum torque capability map for voltage derate in motoring operation */
volatile real32_T CTDM_TqVoltDerateSpeed_C[10] = { 1000.0F, 2000.0F, 3000.0F,
  4000.0F, 5000.0F, 6000.0F, 7000.0F, 8000.0F, 9000.0F, 10000.0F } ;/* Referenced by: '<S46>/Prelookup' */

/* Speed axis breakpoints for voltage derate torque capability lookup table */
volatile real32_T CTDM_TqVoltDerateVolt_C[5] = { 200.0F, 250.0F, 300.0F, 350.0F,
  400.0F } ;                           /* Referenced by: '<S46>/Prelookup1' */

/* Voltage axis breakpoints for voltage derate torque capability lookup table */
volatile real32_T CTDM_VoltDCOverDerate_C[5] = { 350.0F, 352.0F, 354.0F, 356.0F,
  358.0F } ;                           /* Referenced by: '<S54>/Prelookup' */

/* DC bus overvoltage axis breakpoints for derate scale */
volatile real32_T CTDM_VoltDCUnderDerate_C[5] = { 232.0F, 234.0F, 236.0F, 238.0F,
  240.0F } ;                           /* Referenced by: '<S55>/Prelookup' */

/* DC bus undervoltage axis breakpoints for derate scale (ascending storage) */


/* Definition for custom storage class: MtrCtrl_Par */
volatile uint8_T CTDM_EnJunctionTempDerate_C = 1U;/* Referenced by: '<S39>/Constant' */

/* Enable junction temperature derate: 0=disabled, 1=enabled */
volatile uint8_T CTDM_EnMotorTempDerate_C = 1U;/* Referenced by: '<S38>/Constant' */

/* Enable motor temperature derate: 0=disabled, 1=enabled */
volatile uint8_T CTDM_EnSpeedOverDerate_C = 1U;/* Referenced by: '<S24>/Constant' */

/* Enable speed overspeed derate: 0=disabled, 1=enabled */
volatile uint8_T CTDM_EnVoltDCOverDerate_C = 1U;/* Referenced by: '<S53>/Constant' */

/* Enable DC voltage overvoltage derate: 0=disabled, 1=enabled */
volatile uint8_T CTDM_EnVoltDCUnderDerate_C = 1U;/* Referenced by: '<S52>/Constant' */

/* Enable DC voltage undervoltage derate: 0=disabled, 1=enabled */
volatile real32_T CTDM_ScaleRateDown_C = -2.0F;/* Referenced by: '<S21>/Constant' */

/* Derate scale decreasing rate limit (scale/s). Limit when derating becomes stronger */
volatile real32_T CTDM_ScaleRateUp_C = 1.0F;/* Referenced by: '<S20>/Constant' */

/* Derate scale increasing rate limit (scale/s). Limit for recovery towards 1 */
volatile real32_T CTDM_StallConfirmTime_C = 200.0F;/* Referenced by: '<S31>/Constant' */

/* Debounce time to confirm stall condition entry */
volatile real32_T CTDM_StallCurrentThreshold_C = 50.0F;/* Referenced by: '<S30>/Constant' */

/* Stator current amplitude threshold for stall condition detection */
volatile real32_T CTDM_StallDerateFactor_C = 0.8F;/* Referenced by: '<S43>/Constant' */

/* Torque capability reduction factor when stall derate is active */
volatile real32_T CTDM_StallExitTime_C = 100.0F;/* Referenced by: '<S32>/Constant' */

/* Debounce time to exit stall condition */
volatile real32_T CTDM_StallSpeedThreshold_C = 100.0F;/* Referenced by: '<S29>/Constant' */

/* Speed threshold for stall condition detection */
volatile real32_T CTDM_TorqueSpRateLimit_C = 5000.0F;/* Referenced by: '<S48>/Constant' */

/* Rate limit for torque setpoint after derating (Nm/s) */
volatile real32_T CTDM_TqCapabilityMaxLimit_C = 124.0F;/* Referenced by: '<S45>/Constant' */

/* Upper clipping limit for maximum torque capability */
volatile real32_T CTDM_TqCapabilityMinLimit_C = -124.0F;/* Referenced by: '<S44>/Constant' */

/* Lower clipping limit for minimum torque capability */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Sig */
uint16_T CTDM_DerateReason;            /* '<S2>/Data Type Conversion5' */

/* Derate reason bitfield summary. See bit mapping in variable definition file */
real32_T CTDM_ScaleDerateArb;
                        /* Arbitrated derate scale before rate limiter (0..1) */
real32_T CTDM_ScaleDerateFinal;
                              /* Final derate scale after rate limiter (0..1) */
uint8_T CTDM_StallConditionActive;     /* Active stall condition flag */
real32_T CTDM_StatorCurrentAmp;
/* Stator current amplitude calculated from d-q axis currents (Is = sqrt(Id^2 + Iq^2)) */
real32_T CTDM_TorqueLimitNeg;          /* '<S2>/Product1' */

/* Final negative torque capability limit after all derates (regen min) */
real32_T CTDM_TorqueLimitPos;          /* '<S2>/Product' */

/* Final positive torque capability limit after all derates (motoring max) */
real32_T CTDM_TorqueSpLimited;         /* '<S49>/Add1' */

/* Torque setpoint after derating, saturation, and rate limiter */
real32_T CTDM_TqVoltDerateMax;
                /* Maximum allowed torque based on voltage derate calculation */
real32_T CTDM_TqVoltDerateMin;
                        /* Minimum torque based on voltage derate calculation */
real32_T CTDM_TqVoltDerateMotorRaw;
         /* Raw output torque from voltage derate maps for motoring operation */



/* Block states (default storage) */
DW_CtlDeratingManager_T CtlDeratingManager_DW;

/* Real-time model */
static RT_MODEL_CtlDeratingManager_T CtlDeratingManager_M_;
RT_MODEL_CtlDeratingManager_T *const CtlDeratingManager_M =
  &CtlDeratingManager_M_;
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
/* Model step function for TID1 */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void CTDM_Derating_1ms(void)           /* Explicit Task: CTDM_Derating_1ms */
{
  real32_T frac[2];
  real32_T rtb_Add;
  real32_T rtb_Prelookup1_o2;
  real32_T rtb_Prelookup_o2_g;
  real32_T rtb_Product1_g;
  real32_T rtb_Saturation;
  real32_T rtb_Saturation1;
  real32_T rtb_Saturation2;
  real32_T rtb_Saturation3;
  uint8_T bpIndex[2];
  uint8_T rtb_Prelookup_o1_a;
  boolean_T rtb_RelationalOperator_h;

  /* RootInportFunctionCallGenerator generated from: '<Root>/CTDM_Derating_1ms' incorporates:
   *  SubSystem: '<Root>/CTDM_Derating_1ms_sys'
   */
  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S39>/Constant'
   *  Constant: '<S5>/Constant'
   *  Interpolation_n-D: '<S40>/Interpolation Using Prelookup'
   */
  if (CTDM_EnJunctionTempDerate_C != 0) {
    /* PreLookup: '<S40>/Prelookup' incorporates:
     *  Inport: '<Root>/SGPP_SwitchTempMax'
     */
    rtb_Prelookup_o1_a = plook_u8ff_lincag(SGPP_SwitchTempMax, (real32_T *)
      &CTDM_AxisJunctionTempDerate_C[0], 9U, &rtb_Prelookup_o2_g);
    rtb_Saturation = intrp1d_fu8fla(rtb_Prelookup_o1_a, rtb_Prelookup_o2_g,
      (real32_T *)&CTDM_ScaleJunctionTempDerate_C[0], 9U);
  } else {
    rtb_Saturation = 1.0F;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Saturation > 1.0F) {
    rtb_Saturation = 1.0F;
  } else if (rtb_Saturation < 0.0F) {
    rtb_Saturation = 0.0F;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Switch: '<S5>/Switch1' incorporates:
   *  Constant: '<S38>/Constant'
   *  Constant: '<S5>/Constant1'
   *  Interpolation_n-D: '<S37>/Interpolation Using Prelookup'
   */
  if (CTDM_EnMotorTempDerate_C != 0) {
    /* PreLookup: '<S37>/Prelookup' incorporates:
     *  Inport: '<Root>/SGPP_MotorTemp1'
     */
    rtb_Prelookup_o1_a = plook_u8ff_lincag(SGPP_MotorTemp1, (real32_T *)
      &CTDM_AxisMotorTempDerate_C[0], 9U, &rtb_Prelookup_o2_g);
    rtb_Saturation1 = intrp1d_fu8fla(rtb_Prelookup_o1_a, rtb_Prelookup_o2_g,
      (real32_T *)&CTDM_ScaleMotorTempDerate_C[0], 9U);
  } else {
    rtb_Saturation1 = 1.0F;
  }

  /* End of Switch: '<S5>/Switch1' */

  /* Saturate: '<S2>/Saturation1' */
  if (rtb_Saturation1 > 1.0F) {
    rtb_Saturation1 = 1.0F;
  } else if (rtb_Saturation1 < 0.0F) {
    rtb_Saturation1 = 0.0F;
  }

  /* End of Saturate: '<S2>/Saturation1' */

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S53>/Constant'
   *  Constant: '<S8>/Constant'
   *  Interpolation_n-D: '<S54>/Interpolation Using Prelookup'
   */
  if (CTDM_EnVoltDCOverDerate_C != 0) {
    /* PreLookup: '<S54>/Prelookup' incorporates:
     *  Inport: '<Root>/SGPP_DcLinkVoltMeas'
     */
    rtb_Prelookup_o1_a = plook_u8ff_lincag(SGPP_DcLinkVoltMeas, (real32_T *)
      &CTDM_VoltDCOverDerate_C[0], 4U, &rtb_Prelookup_o2_g);
    rtb_Saturation2 = intrp1d_fu8fla(rtb_Prelookup_o1_a, rtb_Prelookup_o2_g,
      (real32_T *)&CTDM_ScaleVoltDCOverDerate_C[0], 4U);
  } else {
    rtb_Saturation2 = 1.0F;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Saturate: '<S2>/Saturation2' */
  if (rtb_Saturation2 > 1.0F) {
    rtb_Saturation2 = 1.0F;
  } else if (rtb_Saturation2 < 0.0F) {
    rtb_Saturation2 = 0.0F;
  }

  /* End of Saturate: '<S2>/Saturation2' */

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S52>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S8>/Constant3'
   *  Inport: '<Root>/CTSO_OperationMode'
   *  Interpolation_n-D: '<S55>/Interpolation Using Prelookup'
   *  Logic: '<S8>/Logical Operator'
   *  Logic: '<S8>/Logical Operator1'
   *  RelationalOperator: '<S8>/Relational Operator'
   *  RelationalOperator: '<S8>/Relational Operator1'
   */
  if ((CTDM_EnVoltDCUnderDerate_C != 0) && ((CTSO_OperationMode == TorqueCtrl) ||
       (CTSO_OperationMode == SpeedCtrl))) {
    /* PreLookup: '<S55>/Prelookup' incorporates:
     *  Inport: '<Root>/SGPP_DcLinkVoltMeas'
     */
    rtb_Prelookup_o1_a = plook_u8ff_lincag(SGPP_DcLinkVoltMeas, (real32_T *)
      &CTDM_VoltDCUnderDerate_C[0], 4U, &rtb_Prelookup_o2_g);
    rtb_Saturation3 = intrp1d_fu8fla(rtb_Prelookup_o1_a, rtb_Prelookup_o2_g,
      (real32_T *)&CTDM_ScaleVoltDCUnderDerate_C[0], 4U);
  } else {
    rtb_Saturation3 = 1.0F;
  }

  /* End of Switch: '<S8>/Switch1' */

  /* Saturate: '<S2>/Saturation3' */
  if (rtb_Saturation3 > 1.0F) {
    rtb_Saturation3 = 1.0F;
  } else if (rtb_Saturation3 < 0.0F) {
    rtb_Saturation3 = 0.0F;
  }

  /* End of Saturate: '<S2>/Saturation3' */

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S24>/Constant'
   *  Constant: '<S3>/Constant'
   *  Interpolation_n-D: '<S25>/Interpolation Using Prelookup'
   */
  if (CTDM_EnSpeedOverDerate_C != 0) {
    /* PreLookup: '<S25>/Prelookup' incorporates:
     *  Inport: '<Root>/SGPP_MechSpeed'
     */
    rtb_Prelookup_o1_a = plook_u8ff_lincag(SGPP_MechSpeed, (real32_T *)
      &CTDM_SpeedOverDerate_C[0], 9U, &rtb_Prelookup_o2_g);
    rtb_Prelookup1_o2 = intrp1d_fu8fla(rtb_Prelookup_o1_a, rtb_Prelookup_o2_g,
      (real32_T *)&CTDM_ScaleSpeedOverDerate_C[0], 9U);
  } else {
    rtb_Prelookup1_o2 = 1.0F;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Saturate: '<S2>/Saturation4' */
  if (rtb_Prelookup1_o2 > 1.0F) {
    rtb_Prelookup1_o2 = 1.0F;
  } else if (rtb_Prelookup1_o2 < 0.0F) {
    rtb_Prelookup1_o2 = 0.0F;
  }

  /* End of Saturate: '<S2>/Saturation4' */

  /* MinMax: '<S2>/Min' */
  if ((rtb_Saturation <= rtb_Saturation1) || rtIsNaNF(rtb_Saturation1)) {
    CTDM_ScaleDerateArb = rtb_Saturation;
  } else {
    CTDM_ScaleDerateArb = rtb_Saturation1;
  }

  if ((!(CTDM_ScaleDerateArb <= rtb_Saturation2)) && (!rtIsNaNF(rtb_Saturation2)))
  {
    CTDM_ScaleDerateArb = rtb_Saturation2;
  }

  if ((!(CTDM_ScaleDerateArb <= rtb_Saturation3)) && (!rtIsNaNF(rtb_Saturation3)))
  {
    CTDM_ScaleDerateArb = rtb_Saturation3;
  }

  if ((!(CTDM_ScaleDerateArb <= rtb_Prelookup1_o2)) && (!rtIsNaNF
       (rtb_Prelookup1_o2))) {
    CTDM_ScaleDerateArb = rtb_Prelookup1_o2;
  }

  /* End of MinMax: '<S2>/Min' */

  /* Product: '<S22>/Product' incorporates:
   *  Constant: '<S20>/Constant'
   *  Inport: '<Root>/SGPP_SampleTime2'
   */
  rtb_Product1_g = CTDM_ScaleRateUp_C * SGPP_SampleTime2;

  /* Sum: '<S22>/Add' incorporates:
   *  DataStoreWrite: '<S13>/Data Store Write'
   *  UnitDelay: '<S22>/Unit Delay'
   */
  rtb_Add = CTDM_ScaleDerateArb - CtlDeratingManager_DW.UnitDelay_DSTATE;

  /* Product: '<S22>/Product1' incorporates:
   *  Constant: '<S21>/Constant'
   *  Inport: '<Root>/SGPP_SampleTime2'
   */
  rtb_Prelookup_o2_g = SGPP_SampleTime2 * CTDM_ScaleRateDown_C;

  /* Switch: '<S23>/Switch2' incorporates:
   *  RelationalOperator: '<S23>/LowerRelop1'
   *  RelationalOperator: '<S23>/UpperRelop'
   *  Switch: '<S23>/Switch'
   */
  if (rtb_Add > rtb_Product1_g) {
    rtb_Add = rtb_Product1_g;
  } else if (rtb_Add < rtb_Prelookup_o2_g) {
    /* Switch: '<S23>/Switch' */
    rtb_Add = rtb_Prelookup_o2_g;
  }

  /* Sum: '<S22>/Add1' incorporates:
   *  Switch: '<S23>/Switch2'
   *  UnitDelay: '<S22>/Unit Delay'
   */
  CtlDeratingManager_DW.UnitDelay_DSTATE += rtb_Add;

  /* DataStoreWrite: '<S14>/Data Store Write' incorporates:
   *  UnitDelay: '<S22>/Unit Delay'
   */
  CTDM_ScaleDerateFinal = CtlDeratingManager_DW.UnitDelay_DSTATE;

  /* Outputs for Atomic SubSystem: '<S2>/Bit Shift' */
  /* Outputs for Atomic SubSystem: '<S2>/Bit Shift1' */
  /* Outputs for Atomic SubSystem: '<S2>/Bit Shift2' */
  /* Outputs for Atomic SubSystem: '<S2>/Bit Shift3' */
  /* DataTypeConversion: '<S2>/Data Type Conversion5' incorporates:
   *  Constant: '<S2>/Constant'
   *  MATLAB Function: '<S10>/bit_shift'
   *  MATLAB Function: '<S11>/bit_shift'
   *  MATLAB Function: '<S12>/bit_shift'
   *  MATLAB Function: '<S9>/bit_shift'
   *  RelationalOperator: '<S2>/Relational Operator'
   *  RelationalOperator: '<S2>/Relational Operator1'
   *  RelationalOperator: '<S2>/Relational Operator2'
   *  RelationalOperator: '<S2>/Relational Operator3'
   *  RelationalOperator: '<S2>/Relational Operator4'
   *  S-Function (sfix_bitop): '<S2>/Bitwise Operator'
   */
  CTDM_DerateReason = (uint16_T)((rtb_Saturation1 < 1.0F) << 1 | (rtb_Saturation
    < 1.0F) | (rtb_Saturation2 < 1.0F) << 2 | (rtb_Saturation3 < 1.0F) << 3 |
    (rtb_Prelookup1_o2 < 1.0F) << 4);

  /* End of Outputs for SubSystem: '<S2>/Bit Shift3' */
  /* End of Outputs for SubSystem: '<S2>/Bit Shift2' */
  /* End of Outputs for SubSystem: '<S2>/Bit Shift1' */
  /* End of Outputs for SubSystem: '<S2>/Bit Shift' */

  /* Sum: '<S26>/Add2' incorporates:
   *  Constant: '<S26>/0 Constant4'
   *  Constant: '<S31>/Constant'
   */
  rtb_Prelookup_o2_g = CTDM_StallConfirmTime_C + 1.0F;

  /* Sqrt: '<S27>/Sqrt' incorporates:
   *  DataStoreWrite: '<S36>/Data Store Write'
   *  Inport: '<Root>/CTLC_IdSpLimited'
   *  Inport: '<Root>/CTLC_IqSpLimited'
   *  Product: '<S27>/Product'
   *  Product: '<S27>/Product1'
   *  Sum: '<S27>/Add'
   */
  CTDM_StatorCurrentAmp = (real32_T)sqrt(CTLC_IdSpLimited * CTLC_IdSpLimited +
    CTLC_IqSpLimited * CTLC_IqSpLimited);

  /* Logic: '<S4>/Logical Operator' incorporates:
   *  Constant: '<S29>/Constant'
   *  Constant: '<S30>/Constant'
   *  DataStoreWrite: '<S36>/Data Store Write'
   *  Inport: '<Root>/SGPP_MechSpeedAbsolute'
   *  RelationalOperator: '<S4>/Relational Operator'
   *  RelationalOperator: '<S4>/Relational Operator1'
   */
  rtb_RelationalOperator_h = ((SGPP_MechSpeedAbsolute <=
    CTDM_StallSpeedThreshold_C) && (CTDM_StatorCurrentAmp >=
    CTDM_StallCurrentThreshold_C));

  /* MultiPortSwitch: '<S26>/Multiport Switch' incorporates:
   *  Constant: '<S26>/0 Constant'
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  MinMax: '<S26>/Max'
   *  Sum: '<S26>/Add'
   *  Sum: '<S26>/Add1'
   *  UnitDelay: '<S35>/Bare Unit Delay'
   */
  if (!rtb_RelationalOperator_h) {
    rtb_Product1_g = CtlDeratingManager_DW.BareUnitDelay_DSTATE - 1.0F;
  } else {
    if ((0.0F >= CtlDeratingManager_DW.BareUnitDelay_DSTATE) || rtIsNaNF
        (CtlDeratingManager_DW.BareUnitDelay_DSTATE)) {
      /* MinMax: '<S26>/Max' incorporates:
       *  Constant: '<S26>/0 Constant'
       */
      rtb_Product1_g = 0.0F;
    } else {
      /* MinMax: '<S26>/Max' incorporates:
       *  UnitDelay: '<S35>/Bare Unit Delay'
       */
      rtb_Product1_g = CtlDeratingManager_DW.BareUnitDelay_DSTATE;
    }

    rtb_Product1_g += 1.0F;
  }

  /* End of MultiPortSwitch: '<S26>/Multiport Switch' */

  /* Logic: '<S4>/Logical Operator2' incorporates:
   *  Logic: '<S4>/Logical Operator1'
   *  Logic: '<S4>/Logical Operator3'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  rtb_RelationalOperator_h = ((!rtb_RelationalOperator_h) &&
    (CtlDeratingManager_DW.UnitDelay_DSTATE_p == 0));

  /* Switch: '<S35>/Enable' incorporates:
   *  Constant: '<S26>/Constant2'
   *  Logic: '<S35>/Logical Operator1'
   *  Logic: '<S35>/Logical Operator2'
   *  Switch: '<S35>/Reset'
   */
  if ((!rtb_RelationalOperator_h) && true) {
    /* Switch: '<S33>/Switch2' incorporates:
     *  Constant: '<S26>/0 Constant1'
     *  RelationalOperator: '<S33>/LowerRelop1'
     *  RelationalOperator: '<S33>/UpperRelop'
     *  Switch: '<S33>/Switch'
     *  UnitDelay: '<S35>/Bare Unit Delay'
     */
    if (rtb_Product1_g > rtb_Prelookup_o2_g) {
      CtlDeratingManager_DW.BareUnitDelay_DSTATE = rtb_Prelookup_o2_g;
    } else if (rtb_Product1_g < 0.0F) {
      /* Switch: '<S33>/Switch' incorporates:
       *  Constant: '<S26>/0 Constant1'
       *  UnitDelay: '<S35>/Bare Unit Delay'
       */
      CtlDeratingManager_DW.BareUnitDelay_DSTATE = 0.0F;
    } else {
      CtlDeratingManager_DW.BareUnitDelay_DSTATE = rtb_Product1_g;
    }

    /* End of Switch: '<S33>/Switch2' */
  } else if (rtb_RelationalOperator_h) {
    /* Switch: '<S35>/Reset' incorporates:
     *  Constant: '<S35>/iv'
     *  UnitDelay: '<S35>/Bare Unit Delay'
     */
    CtlDeratingManager_DW.BareUnitDelay_DSTATE = 0.0F;
  }

  /* End of Switch: '<S35>/Enable' */

  /* Switch: '<S34>/Switch' incorporates:
   *  Constant: '<S32>/Constant'
   *  RelationalOperator: '<S26>/Relational Operator'
   *  RelationalOperator: '<S26>/Relational Operator1'
   *  Switch: '<S34>/Switch1'
   *  UnitDelay: '<S35>/Bare Unit Delay'
   */
  if (CtlDeratingManager_DW.BareUnitDelay_DSTATE >= rtb_Prelookup_o2_g) {
    /* Switch: '<S34>/Switch' incorporates:
     *  Constant: '<S34>/Constant1'
     */
    CtlDeratingManager_DW.Memory_PreviousInput = true;
  } else if (CtlDeratingManager_DW.BareUnitDelay_DSTATE <= CTDM_StallExitTime_C)
  {
    /* Switch: '<S34>/Switch' incorporates:
     *  Constant: '<S34>/Constant4'
     *  Switch: '<S34>/Switch1'
     */
    CtlDeratingManager_DW.Memory_PreviousInput = false;
  }

  /* End of Switch: '<S34>/Switch' */

  /* DataTypeConversion: '<S34>/Data Type Conversion EveSt2' incorporates:
   *  UnitDelay: '<S4>/Unit Delay'
   */
  CtlDeratingManager_DW.UnitDelay_DSTATE_p =
    CtlDeratingManager_DW.Memory_PreviousInput;

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S43>/Constant'
   *  Constant: '<S6>/Constant'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  if (CtlDeratingManager_DW.UnitDelay_DSTATE_p != 0) {
    rtb_Prelookup_o2_g = CTDM_StallDerateFactor_C;
  } else {
    rtb_Prelookup_o2_g = 1.0F;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Interpolation_n-D: '<S46>/Interpolation Using Prelookup' incorporates:
   *  DataStoreWrite: '<S47>/Data Store Write'
   *  Inport: '<Root>/SGPP_DcLinkVoltMeas'
   *  Inport: '<Root>/SGPP_MechSpeedAbsolute'
   *  PreLookup: '<S46>/Prelookup'
   *  PreLookup: '<S46>/Prelookup1'
   */
  bpIndex[0] = plook_u8ff_lincag(SGPP_MechSpeedAbsolute, (real32_T *)
    &CTDM_TqVoltDerateSpeed_C[0], 9U, &rtb_Product1_g);
  bpIndex[1] = plook_u8ff_lincag(SGPP_DcLinkVoltMeas, (real32_T *)
    &CTDM_TqVoltDerateVolt_C[0], 4U, &rtb_Prelookup1_o2);
  frac[0] = rtb_Product1_g;
  frac[1] = rtb_Prelookup1_o2;
  CTDM_TqVoltDerateMotorRaw = intrp2d_fu8fla(bpIndex, frac, (real32_T *)
    &CTDM_TqVoltDerateMotoring_C[0], 10U,
    rtCP_InterpolationUsingPrelookup_maxIndex_ia);

  /* MinMax: '<S6>/Max1' incorporates:
   *  Constant: '<S45>/Constant'
   *  DataStoreWrite: '<S47>/Data Store Write'
   */
  if ((CTDM_TqVoltDerateMotorRaw <= CTDM_TqCapabilityMaxLimit_C) || rtIsNaNF
      (CTDM_TqCapabilityMaxLimit_C)) {
    rtb_Product1_g = CTDM_TqVoltDerateMotorRaw;
  } else {
    rtb_Product1_g = CTDM_TqCapabilityMaxLimit_C;
  }

  /* Product: '<S6>/Product' incorporates:
   *  DataStoreWrite: '<S42>/Data Store Write'
   *  MinMax: '<S6>/Max1'
   */
  CTDM_TqVoltDerateMax = rtb_Prelookup_o2_g * rtb_Product1_g;

  /* Product: '<S2>/Product' incorporates:
   *  DataStoreWrite: '<S42>/Data Store Write'
   *  UnitDelay: '<S22>/Unit Delay'
   */
  CTDM_TorqueLimitPos = CTDM_TqVoltDerateMax *
    CtlDeratingManager_DW.UnitDelay_DSTATE;

  /* Gain: '<S6>/Gain' incorporates:
   *  DataStoreWrite: '<S47>/Data Store Write'
   */
  rtb_Product1_g = (-1.0F) * CTDM_TqVoltDerateMotorRaw;

  /* MinMax: '<S6>/Max' incorporates:
   *  Constant: '<S44>/Constant'
   */
  if ((!(rtb_Product1_g >= CTDM_TqCapabilityMinLimit_C)) && (!rtIsNaNF
       (CTDM_TqCapabilityMinLimit_C))) {
    rtb_Product1_g = CTDM_TqCapabilityMinLimit_C;
  }

  /* Product: '<S6>/Product1' incorporates:
   *  DataStoreWrite: '<S41>/Data Store Write'
   *  MinMax: '<S6>/Max'
   */
  CTDM_TqVoltDerateMin = rtb_Prelookup_o2_g * rtb_Product1_g;

  /* Product: '<S2>/Product1' incorporates:
   *  DataStoreWrite: '<S41>/Data Store Write'
   *  UnitDelay: '<S22>/Unit Delay'
   */
  CTDM_TorqueLimitNeg = CTDM_TqVoltDerateMin *
    CtlDeratingManager_DW.UnitDelay_DSTATE;

  /* DataStoreWrite: '<S28>/Data Store Write' incorporates:
   *  UnitDelay: '<S4>/Unit Delay'
   */
  CTDM_StallConditionActive = CtlDeratingManager_DW.UnitDelay_DSTATE_p;

  /* Switch: '<S50>/Switch2' incorporates:
   *  Inport: '<Root>/SGSA_TorqueCommand'
   *  RelationalOperator: '<S50>/LowerRelop1'
   *  RelationalOperator: '<S50>/UpperRelop'
   *  Switch: '<S50>/Switch'
   */
  if (SGSA_TorqueCommand > CTDM_TorqueLimitPos) {
    rtb_Product1_g = CTDM_TorqueLimitPos;
  } else if (SGSA_TorqueCommand < CTDM_TorqueLimitNeg) {
    /* Switch: '<S50>/Switch' */
    rtb_Product1_g = CTDM_TorqueLimitNeg;
  } else {
    rtb_Product1_g = SGSA_TorqueCommand;
  }

  /* Sum: '<S49>/Add' incorporates:
   *  Switch: '<S50>/Switch2'
   *  UnitDelay: '<S49>/Unit Delay'
   */
  rtb_Saturation = rtb_Product1_g - CTDM_TorqueSpLimited;

  /* Product: '<S49>/Product' incorporates:
   *  Constant: '<S48>/Constant'
   *  Inport: '<Root>/SGPP_SampleTime2'
   */
  rtb_Prelookup_o2_g = CTDM_TorqueSpRateLimit_C * SGPP_SampleTime2;

  /* Product: '<S49>/Product1' incorporates:
   *  Constant: '<S48>/Constant'
   *  Gain: '<S7>/Gain'
   *  Inport: '<Root>/SGPP_SampleTime2'
   */
  rtb_Product1_g = (-1.0F) * CTDM_TorqueSpRateLimit_C * SGPP_SampleTime2;

  /* Switch: '<S51>/Switch2' incorporates:
   *  RelationalOperator: '<S51>/LowerRelop1'
   *  RelationalOperator: '<S51>/UpperRelop'
   *  Switch: '<S51>/Switch'
   */
  if (rtb_Saturation > rtb_Prelookup_o2_g) {
    rtb_Saturation = rtb_Prelookup_o2_g;
  } else if (rtb_Saturation < rtb_Product1_g) {
    /* Switch: '<S51>/Switch' */
    rtb_Saturation = rtb_Product1_g;
  }

  /* Sum: '<S49>/Add1' incorporates:
   *  Switch: '<S51>/Switch2'
   *  UnitDelay: '<S49>/Unit Delay'
   */
  CTDM_TorqueSpLimited = rtb_Saturation + CTDM_TorqueSpLimited;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/CTDM_Derating_1ms' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model initialize function */
void CtlDeratingManager_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for MinMax: '<S2>/Min' incorporates:
   *  DataStoreMemory generated from: '<S13>/Data Store Write'
   */
  CTDM_ScaleDerateArb = 1.0F;

  /* Start for DataStoreMemory generated from: '<S14>/Data Store Write' */
  CTDM_ScaleDerateFinal = 1.0F;
}

/* Model terminate function */
void CtlDeratingManager_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: CtlCurrentRegulator.c
 *
 * Code generated for Simulink model 'CtlCurrentRegulator'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:45:38 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CtlCurrentRegulator.h"
#include <math.h>
#include "rtwtypes.h"
#include "CtlCurrentRegulator_private.h"

/* Exported data definition */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Par */
volatile uint8_T CTCR_DAxisInductDecoupEna_C = 0U;/* Referenced by: '<S32>/Constant' */

/* Enable d-axis inductance term for decoupling */
volatile real32_T CTCR_DAxisInductance_C = 0.0003F;/* Referenced by: '<S35>/Constant' */

/* D-axis inductance nominal value */
volatile real32_T CTCR_DAxisKi_C = 10.0F;/* Referenced by: '<S9>/Constant' */

/* D-axis current controller integral gain */
volatile real32_T CTCR_DAxisKp_C = 0.6F;/* Referenced by: '<S12>/Constant' */

/* D-axis current controller proportional gain */
volatile uint8_T CTCR_DecoupUseSetpointEna_C = 1U;/* Referenced by: '<S25>/Constant' */

/* Enable use setpoint current for decoupling calculation */
volatile real32_T CTCR_PmFluxLinkage_C = 0.073F;/* Referenced by: '<S30>/Constant' */

/* Permanent magnet flux linkage nominal value */
volatile uint8_T CTCR_QAxisFluxDecoupEna_C = 0U;/* Referenced by: '<S27>/Constant' */

/* Enable permanent magnet flux term for decoupling */
volatile uint8_T CTCR_QAxisInductDecoupEna_C = 0U;/* Referenced by: '<S26>/Constant' */

/* Enable q-axis inductance term for decoupling */
volatile real32_T CTCR_QAxisInductance_C = 0.00065F;/* Referenced by: '<S28>/Constant' */

/* Q-axis inductance nominal value */
volatile real32_T CTCR_QAxisKi_C = 20.0F;/* Referenced by: '<S11>/Constant' */

/* Q-axis current controller integral gain */
volatile real32_T CTCR_QAxisKp_C = 0.6F;/* Referenced by: '<S10>/Constant' */

/* Q-axis current controller proportional gain */
volatile uint8_T CTCR_ResistDecoupEna_C = 0U;/* Referenced by:
                                              * '<S31>/Constant'
                                              * '<S34>/Constant'
                                              */

/* Enable resistance term for decoupling */
volatile real32_T CTCR_StatorResistance_C = 0.02F;/* Referenced by:
                                                   * '<S29>/Constant'
                                                   * '<S33>/Constant'
                                                   */

/* Stator winding resistance nominal value */
volatile real32_T CTCR_VSFilterFreq_C = 50.0F;/* Referenced by: '<S24>/Constant' */

/* Voltage vector magnitude filter frequency */
volatile real32_T CTCR_VoltLimitFactor_C = 0.606218F;/* Referenced by: '<S16>/Constant' */

/* DC-link voltage limitation factor (typically 1/��3) */
volatile real32_T CTCR_VoltVectorMagFilterFreq_C = 200.0F;/* Referenced by: '<S15>/Constant' */

/* Voltage vector magnitude filter frequency */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Sig */
real32_T CTCR_CurrentVs;
uint8_T CTCR_DAxisAntiWindupEna;       /* D-axis anti-windup enable flag */
real32_T CTCR_Ki_Out_Ud;
                    /* D-axis voltage setpoint output from current controller */
real32_T CTCR_Ki_Out_Uq;
                    /* D-axis voltage setpoint output from current controller */
real32_T CTCR_Kp_Out_Ud;
                    /* D-axis voltage setpoint output from current controller */
real32_T CTCR_Kp_Out_Uq;
                    /* D-axis voltage setpoint output from current controller */
real32_T CTCR_LimitVs;
real32_T CTCR_Pi_Out_Ud;
                    /* D-axis voltage setpoint output from current controller */
real32_T CTCR_Pi_Out_Uq;
                    /* D-axis voltage setpoint output from current controller */
uint8_T CTCR_QAxisAntiWindupEna;       /* Q-axis anti-windup enable flag */
real32_T CTCR_UdSp;                    /* '<S17>/Merge' */

/* D-axis voltage setpoint output from current controller */
real32_T CTCR_UqSp;                    /* '<S17>/Merge1' */

/* Q-axis voltage setpoint output from current controller */
real32_T CTCR_Uq_Err;
                    /* D-axis voltage setpoint output from current controller */
real32_T CTCR_VoltVectorMagFiltered;   /* '<S14>/Subtract1' */
real32_T CTCR_VsLpfVal;



/* Block states (default storage) */
DW_CtlCurrentRegulator_T CtlCurrentRegulator_DW;

/* Real-time model */
static RT_MODEL_CtlCurrentRegulator_T CtlCurrentRegulator_M_;
RT_MODEL_CtlCurrentRegulator_T *const CtlCurrentRegulator_M =
  &CtlCurrentRegulator_M_;
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
/* Model step function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void CTCR_RegulateCurrent_100us(void)
{
  real32_T rtb_Abs1;
  real32_T rtb_Add;
  real32_T rtb_Switch;
  real32_T rtb_Switch1;
  real32_T rtb_Switch5;
  real32_T tmp;

  /* RootInportFunctionCallGenerator generated from: '<Root>/CTCR_RegulateCurrent_100us' incorporates:
   *  SubSystem: '<Root>/CTCR_RegulateCurrent_100us_sys'
   */
  /* Sum: '<S7>/Add' incorporates:
   *  Inport: '<Root>/CTLC_IdSpLimited'
   *  Inport: '<Root>/TFPD_IdMeasured'
   */
  rtb_Add = CTLC_IdSpLimited - TFPD_IdMeasured;

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S12>/Constant'
   *  DataStoreWrite: '<S38>/Data Store Write'
   */
  CTCR_Kp_Out_Ud = rtb_Add * CTCR_DAxisKp_C;

  /* Delay: '<S7>/Delay' incorporates:
   *  Constant: '<S7>/Constant'
   *  Inport: '<Root>/CTSO_CurrentIntegralReset'
   */
  CtlCurrentRegulator_DW.icLoad = ((CTSO_CurrentIntegralReset != 0) ||
    CtlCurrentRegulator_DW.icLoad);
  if (CtlCurrentRegulator_DW.icLoad) {
    CtlCurrentRegulator_DW.Delay_DSTATE = 0.0F;
  }

  /* Product: '<S7>/Product2' incorporates:
   *  Constant: '<S7>/Constant1'
   *  Delay: '<S7>/Delay'
   *  Inport: '<Root>/SGPP_SampleTime1'
   *  Product: '<S7>/Product1'
   *  Sum: '<S7>/Add3'
   */
  rtb_Switch5 = (rtb_Add + CtlCurrentRegulator_DW.Delay_DSTATE) * 0.5F *
    SGPP_SampleTime1;

  /* Delay: '<S7>/Delay1' incorporates:
   *  Inport: '<Root>/CTSO_CurrentIntegralReset'
   */
  CtlCurrentRegulator_DW.icLoad_d = ((CTSO_CurrentIntegralReset != 0) ||
    CtlCurrentRegulator_DW.icLoad_d);
  if (CtlCurrentRegulator_DW.icLoad_d) {
    /* Sum: '<S7>/Add1' incorporates:
     *  Constant: '<S7>/Constant2'
     */
    CtlCurrentRegulator_DW.Delay1_DSTATE = 0.0F;
  }

  /* Delay: '<S4>/Delay1' incorporates:
   *  Constant: '<S4>/Constant_uint2'
   *  Inport: '<Root>/CTSO_CurrentIntegralReset'
   */
  CtlCurrentRegulator_DW.icLoad_f = ((CTSO_CurrentIntegralReset != 0) ||
    CtlCurrentRegulator_DW.icLoad_f);
  if (CtlCurrentRegulator_DW.icLoad_f) {
    CtlCurrentRegulator_DW.Delay1_DSTATE_a = ((uint8_T)0U);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion1' incorporates:
   *  DataStoreWrite: '<S37>/Data Store Write'
   *  Delay: '<S4>/Delay1'
   */
  CTCR_DAxisAntiWindupEna = CtlCurrentRegulator_DW.Delay1_DSTATE_a;

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant3'
   *  Constant: '<S7>/Constant4'
   *  Constant: '<S7>/Constant5'
   *  DataStoreWrite: '<S37>/Data Store Write'
   *  Delay: '<S7>/Delay1'
   *  Inport: '<Root>/CTSO_CurrentIntegralDisable'
   *  Logic: '<S7>/Logical Operator'
   *  Logic: '<S7>/Logical Operator1'
   *  RelationalOperator: '<S7>/Relational Operator'
   *  RelationalOperator: '<S7>/Relational Operator1'
   *  RelationalOperator: '<S7>/Relational Operator2'
   */
  if ((((rtb_Switch5 >= 0.0F) == (CtlCurrentRegulator_DW.Delay1_DSTATE >= 0.0F))
       && (CTCR_DAxisAntiWindupEna != 0)) || (CTSO_CurrentIntegralDisable != 0))
  {
    rtb_Switch5 = 0.0F;
  }

  /* Product: '<S7>/Product3' incorporates:
   *  Constant: '<S9>/Constant'
   *  DataStoreWrite: '<S39>/Data Store Write'
   *  Switch: '<S7>/Switch'
   */
  CTCR_Ki_Out_Ud = rtb_Switch5 * CTCR_DAxisKi_C;

  /* Sum: '<S7>/Add1' incorporates:
   *  DataStoreWrite: '<S39>/Data Store Write'
   *  Delay: '<S7>/Delay1'
   */
  CtlCurrentRegulator_DW.Delay1_DSTATE += CTCR_Ki_Out_Ud;

  /* Sum: '<S7>/Add2' incorporates:
   *  DataStoreWrite: '<S38>/Data Store Write'
   *  DataStoreWrite: '<S5>/Data Store Write'
   */
  CTCR_Pi_Out_Ud = CTCR_Kp_Out_Ud + CtlCurrentRegulator_DW.Delay1_DSTATE;

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S25>/Constant'
   *  Inport: '<Root>/CTLC_IdSpLimited'
   *  Inport: '<Root>/CTLC_IqSpLimited'
   *  Inport: '<Root>/TFPD_IdMeasured'
   *  Inport: '<Root>/TFPD_IqMeasured'
   *  Switch: '<S3>/Switch1'
   */
  if (CTCR_DecoupUseSetpointEna_C != 0) {
    rtb_Switch = CTLC_IdSpLimited;
    rtb_Switch1 = CTLC_IqSpLimited;
  } else {
    rtb_Switch = TFPD_IdMeasured;
    rtb_Switch1 = TFPD_IqMeasured;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Switch: '<S3>/Switch3' incorporates:
   *  Constant: '<S29>/Constant'
   *  Constant: '<S31>/Constant'
   *  Constant: '<S3>/Constant1_single'
   *  Product: '<S3>/Product'
   */
  if (CTCR_ResistDecoupEna_C != 0) {
    rtb_Abs1 = CTCR_StatorResistance_C * rtb_Switch;
  } else {
    rtb_Abs1 = 0.0F;
  }

  /* Switch: '<S3>/Switch2' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S32>/Constant'
   *  Constant: '<S3>/Constant1_single1'
   *  Constant: '<S3>/Constant_single'
   *  Inport: '<Root>/SGPP_ElecSpeed'
   *  Product: '<S3>/Product1'
   *  Product: '<S3>/Product2'
   *  Product: '<S3>/Product3'
   */
  if (CTCR_DAxisInductDecoupEna_C != 0) {
    tmp = CTCR_QAxisInductance_C * rtb_Switch1 * SGPP_ElecSpeed * (-1.0F);
  } else {
    tmp = 0.0F;
  }

  /* Sum: '<S13>/Add' incorporates:
   *  DataStoreWrite: '<S5>/Data Store Write'
   *  Sum: '<S3>/Add'
   *  Switch: '<S3>/Switch2'
   *  Switch: '<S3>/Switch3'
   */
  rtb_Switch5 = (rtb_Abs1 + tmp) + CTCR_Pi_Out_Ud;

  /* Sum: '<S8>/Add' incorporates:
   *  DataStoreWrite: '<S42>/Data Store Write'
   *  Inport: '<Root>/CTLC_IqSpLimited'
   *  Inport: '<Root>/TFPD_IqMeasured'
   */
  CTCR_Uq_Err = CTLC_IqSpLimited - TFPD_IqMeasured;

  /* Product: '<S8>/Product' incorporates:
   *  Constant: '<S10>/Constant'
   *  DataStoreWrite: '<S40>/Data Store Write'
   *  DataStoreWrite: '<S42>/Data Store Write'
   */
  CTCR_Kp_Out_Uq = CTCR_Uq_Err * CTCR_QAxisKp_C;

  /* Delay: '<S8>/Delay' incorporates:
   *  Constant: '<S8>/Constant'
   *  Inport: '<Root>/CTSO_CurrentIntegralReset'
   */
  CtlCurrentRegulator_DW.icLoad_g = ((CTSO_CurrentIntegralReset != 0) ||
    CtlCurrentRegulator_DW.icLoad_g);
  if (CtlCurrentRegulator_DW.icLoad_g) {
    CtlCurrentRegulator_DW.Delay_DSTATE_c = 0.0F;
  }

  /* Product: '<S8>/Product2' incorporates:
   *  Constant: '<S8>/Constant1'
   *  DataStoreWrite: '<S42>/Data Store Write'
   *  Delay: '<S8>/Delay'
   *  Inport: '<Root>/SGPP_SampleTime1'
   *  Product: '<S8>/Product1'
   *  Sum: '<S8>/Add3'
   */
  rtb_Abs1 = (CTCR_Uq_Err + CtlCurrentRegulator_DW.Delay_DSTATE_c) * 0.5F *
    SGPP_SampleTime1;

  /* Delay: '<S8>/Delay1' incorporates:
   *  Inport: '<Root>/CTSO_CurrentIntegralReset'
   */
  CtlCurrentRegulator_DW.icLoad_p = ((CTSO_CurrentIntegralReset != 0) ||
    CtlCurrentRegulator_DW.icLoad_p);
  if (CtlCurrentRegulator_DW.icLoad_p) {
    /* Sum: '<S8>/Add1' incorporates:
     *  Constant: '<S8>/Constant2'
     */
    CtlCurrentRegulator_DW.Delay1_DSTATE_j = 0.0F;
  }

  /* Delay: '<S4>/Delay' incorporates:
   *  Constant: '<S4>/Constant_uint1'
   *  Inport: '<Root>/CTSO_CurrentIntegralReset'
   */
  CtlCurrentRegulator_DW.icLoad_j = ((CTSO_CurrentIntegralReset != 0) ||
    CtlCurrentRegulator_DW.icLoad_j);
  if (CtlCurrentRegulator_DW.icLoad_j) {
    CtlCurrentRegulator_DW.Delay_DSTATE_b = ((uint8_T)0U);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  DataStoreWrite: '<S36>/Data Store Write'
   *  Delay: '<S4>/Delay'
   */
  CTCR_QAxisAntiWindupEna = CtlCurrentRegulator_DW.Delay_DSTATE_b;

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant3'
   *  Constant: '<S8>/Constant4'
   *  Constant: '<S8>/Constant5'
   *  DataStoreWrite: '<S36>/Data Store Write'
   *  Delay: '<S8>/Delay1'
   *  Inport: '<Root>/CTSO_CurrentIntegralDisable'
   *  Logic: '<S8>/Logical Operator'
   *  Logic: '<S8>/Logical Operator1'
   *  RelationalOperator: '<S8>/Relational Operator'
   *  RelationalOperator: '<S8>/Relational Operator1'
   *  RelationalOperator: '<S8>/Relational Operator2'
   */
  if ((((rtb_Abs1 >= 0.0F) == (CtlCurrentRegulator_DW.Delay1_DSTATE_j >= 0.0F)) &&
       (CTCR_QAxisAntiWindupEna != 0)) || (CTSO_CurrentIntegralDisable != 0)) {
    rtb_Abs1 = 0.0F;
  }

  /* Product: '<S8>/Product3' incorporates:
   *  Constant: '<S11>/Constant'
   *  DataStoreWrite: '<S41>/Data Store Write'
   *  Switch: '<S8>/Switch'
   */
  CTCR_Ki_Out_Uq = rtb_Abs1 * CTCR_QAxisKi_C;

  /* Sum: '<S8>/Add1' incorporates:
   *  DataStoreWrite: '<S41>/Data Store Write'
   *  Delay: '<S8>/Delay1'
   */
  CtlCurrentRegulator_DW.Delay1_DSTATE_j += CTCR_Ki_Out_Uq;

  /* Sum: '<S8>/Add2' incorporates:
   *  DataStoreWrite: '<S40>/Data Store Write'
   *  DataStoreWrite: '<S6>/Data Store Write'
   */
  CTCR_Pi_Out_Uq = CTCR_Kp_Out_Uq + CtlCurrentRegulator_DW.Delay1_DSTATE_j;

  /* Switch: '<S3>/Switch4' incorporates:
   *  Constant: '<S33>/Constant'
   *  Constant: '<S34>/Constant'
   *  Constant: '<S3>/Constant1_single2'
   *  Product: '<S3>/Product4'
   */
  if (CTCR_ResistDecoupEna_C != 0) {
    rtb_Abs1 = CTCR_StatorResistance_C * rtb_Switch1;
  } else {
    rtb_Abs1 = 0.0F;
  }

  /* Switch: '<S3>/Switch5' incorporates:
   *  Constant: '<S26>/Constant'
   *  Constant: '<S35>/Constant'
   *  Constant: '<S3>/Constant1_single3'
   *  Inport: '<Root>/SGPP_ElecSpeed'
   *  Product: '<S3>/Product5'
   *  Product: '<S3>/Product6'
   */
  if (CTCR_QAxisInductDecoupEna_C != 0) {
    tmp = CTCR_DAxisInductance_C * rtb_Switch * SGPP_ElecSpeed;
  } else {
    tmp = 0.0F;
  }

  /* Switch: '<S3>/Switch6' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S30>/Constant'
   *  Constant: '<S3>/Constant1_single4'
   *  Inport: '<Root>/SGPP_ElecSpeed'
   *  Product: '<S3>/Product7'
   */
  if (CTCR_QAxisFluxDecoupEna_C != 0) {
    rtb_Switch = CTCR_PmFluxLinkage_C * SGPP_ElecSpeed;
  } else {
    rtb_Switch = 0.0F;
  }

  /* Sum: '<S13>/Add1' incorporates:
   *  DataStoreWrite: '<S6>/Data Store Write'
   *  Sum: '<S3>/Add1'
   *  Switch: '<S3>/Switch4'
   *  Switch: '<S3>/Switch5'
   *  Switch: '<S3>/Switch6'
   */
  rtb_Switch = ((rtb_Abs1 + tmp) + rtb_Switch) + CTCR_Pi_Out_Uq;

  /* Sqrt: '<S2>/Sqrt' incorporates:
   *  DataStoreWrite: '<S20>/Data Store Write'
   *  Product: '<S2>/Product1'
   *  Product: '<S2>/Product2'
   *  Sum: '<S2>/Sum'
   */
  CTCR_CurrentVs = (real32_T)sqrt(rtb_Switch5 * rtb_Switch5 + rtb_Switch *
    rtb_Switch);

  /* Product: '<S2>/Product3' incorporates:
   *  Constant: '<S16>/Constant'
   *  DataStoreWrite: '<S21>/Data Store Write'
   *  Inport: '<Root>/SGPP_DcLinkVoltMeas'
   */
  CTCR_LimitVs = SGPP_DcLinkVoltMeas * CTCR_VoltLimitFactor_C;

  /* Product: '<S23>/Product' incorporates:
   *  Constant: '<S24>/Constant'
   *  Inport: '<Root>/SGPP_SampleTime1'
   */
  rtb_Switch1 = CTCR_VSFilterFreq_C * SGPP_SampleTime1;

  /* Saturate: '<S23>/Saturation' */
  if (rtb_Switch1 > 1.0F) {
    rtb_Switch1 = 1.0F;
  } else if (rtb_Switch1 < 0.0F) {
    rtb_Switch1 = 0.0F;
  }

  /* Sum: '<S23>/Subtract1' incorporates:
   *  Constant: '<S17>/Constant'
   *  DataStoreWrite: '<S20>/Data Store Write'
   *  DataStoreWrite: '<S21>/Data Store Write'
   *  Delay: '<S23>/Delay'
   *  Product: '<S17>/Divide'
   *  Product: '<S17>/Product'
   *  Product: '<S23>/Product1'
   *  Saturate: '<S23>/Saturation'
   *  Sum: '<S23>/Subtract'
   */
  CtlCurrentRegulator_DW.Delay_DSTATE_h += (CTCR_CurrentVs / CTCR_LimitVs *
    100.0F - CtlCurrentRegulator_DW.Delay_DSTATE_h) * rtb_Switch1;

  /* DataStoreWrite: '<S22>/Data Store Write' incorporates:
   *  Delay: '<S23>/Delay'
   */
  CTCR_VsLpfVal = CtlCurrentRegulator_DW.Delay_DSTATE_h;

  /* If: '<S17>/If' incorporates:
   *  DataStoreWrite: '<S20>/Data Store Write'
   *  DataStoreWrite: '<S21>/Data Store Write'
   */
  if (CTCR_CurrentVs > CTCR_LimitVs) {
    /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    /* Product: '<S18>/Product1' */
    rtb_Switch1 = CTCR_LimitVs / CTCR_CurrentVs;

    /* Merge: '<S17>/Merge1' incorporates:
     *  Product: '<S18>/Product2'
     */
    CTCR_UqSp = rtb_Switch * rtb_Switch1;

    /* Merge: '<S17>/Merge' incorporates:
     *  Product: '<S18>/Product3'
     */
    CTCR_UdSp = rtb_Switch5 * rtb_Switch1;

    /* End of Outputs for SubSystem: '<S17>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* Merge: '<S17>/Merge' incorporates:
     *  SignalConversion generated from: '<S19>/UDDecoupled'
     */
    CTCR_UdSp = rtb_Switch5;

    /* Merge: '<S17>/Merge1' incorporates:
     *  SignalConversion generated from: '<S19>/UQDecoupled'
     */
    CTCR_UqSp = rtb_Switch;

    /* End of Outputs for SubSystem: '<S17>/If Action Subsystem1' */
  }

  /* End of If: '<S17>/If' */

  /* Product: '<S14>/Product' incorporates:
   *  Constant: '<S15>/Constant'
   *  Inport: '<Root>/SGPP_SampleTime1'
   */
  rtb_Switch1 = CTCR_VoltVectorMagFilterFreq_C * SGPP_SampleTime1;

  /* Saturate: '<S14>/Saturation' */
  if (rtb_Switch1 > 1.0F) {
    rtb_Switch1 = 1.0F;
  } else if (rtb_Switch1 < 0.0F) {
    rtb_Switch1 = 0.0F;
  }

  /* Sum: '<S14>/Subtract1' incorporates:
   *  DataStoreWrite: '<S20>/Data Store Write'
   *  Delay: '<S14>/Delay'
   *  Product: '<S14>/Product1'
   *  Saturate: '<S14>/Saturation'
   *  Sum: '<S14>/Subtract'
   */
  CTCR_VoltVectorMagFiltered = (CTCR_CurrentVs - CTCR_VoltVectorMagFiltered) *
    rtb_Switch1 + CTCR_VoltVectorMagFiltered;

  /* Update for Delay: '<S7>/Delay' */
  CtlCurrentRegulator_DW.icLoad = false;
  CtlCurrentRegulator_DW.Delay_DSTATE = rtb_Add;

  /* Update for Delay: '<S7>/Delay1' */
  CtlCurrentRegulator_DW.icLoad_d = false;

  /* Update for Delay: '<S4>/Delay1' incorporates:
   *  Abs: '<S4>/Abs1'
   *  Constant: '<S4>/Constant1'
   *  DataTypeConversion: '<S4>/Data Type Conversion3'
   *  RelationalOperator: '<S4>/Relational Operator1'
   *  Sum: '<S4>/Sum1'
   */
  CtlCurrentRegulator_DW.icLoad_f = false;
  CtlCurrentRegulator_DW.Delay1_DSTATE_a = (uint8_T)((real32_T)fabs(rtb_Switch -
    CTCR_UqSp) > 1.0E-7F);

  /* Update for Delay: '<S8>/Delay' incorporates:
   *  DataStoreWrite: '<S42>/Data Store Write'
   */
  CtlCurrentRegulator_DW.icLoad_g = false;
  CtlCurrentRegulator_DW.Delay_DSTATE_c = CTCR_Uq_Err;

  /* Update for Delay: '<S8>/Delay1' */
  CtlCurrentRegulator_DW.icLoad_p = false;

  /* Update for Delay: '<S4>/Delay' incorporates:
   *  Abs: '<S4>/Abs'
   *  Constant: '<S4>/Constant'
   *  DataTypeConversion: '<S4>/Data Type Conversion2'
   *  RelationalOperator: '<S4>/Relational Operator'
   *  Sum: '<S4>/Sum3'
   */
  CtlCurrentRegulator_DW.icLoad_j = false;
  CtlCurrentRegulator_DW.Delay_DSTATE_b = (uint8_T)((real32_T)fabs(rtb_Switch5 -
    CTCR_UdSp) > 1.0E-7F);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/CTCR_RegulateCurrent_100us' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model initialize function */
void CtlCurrentRegulator_initialize(void)
{
  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/CTCR_RegulateCurrent_100us' incorporates:
   *  SubSystem: '<Root>/CTCR_RegulateCurrent_100us_sys'
   */
  /* InitializeConditions for Delay: '<S7>/Delay' */
  CtlCurrentRegulator_DW.icLoad = true;

  /* InitializeConditions for Delay: '<S7>/Delay1' */
  CtlCurrentRegulator_DW.icLoad_d = true;

  /* InitializeConditions for Delay: '<S4>/Delay1' */
  CtlCurrentRegulator_DW.icLoad_f = true;

  /* InitializeConditions for Delay: '<S8>/Delay' */
  CtlCurrentRegulator_DW.icLoad_g = true;

  /* InitializeConditions for Delay: '<S8>/Delay1' */
  CtlCurrentRegulator_DW.icLoad_p = true;

  /* InitializeConditions for Delay: '<S4>/Delay' */
  CtlCurrentRegulator_DW.icLoad_j = true;

  /* SystemInitialize for Merge: '<S17>/Merge' */
  CTCR_UdSp = 0.0F;

  /* SystemInitialize for Merge: '<S17>/Merge1' */
  CTCR_UqSp = 0.0F;

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/CTCR_RegulateCurrent_100us' */
}

/* Model terminate function */
void CtlCurrentRegulator_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

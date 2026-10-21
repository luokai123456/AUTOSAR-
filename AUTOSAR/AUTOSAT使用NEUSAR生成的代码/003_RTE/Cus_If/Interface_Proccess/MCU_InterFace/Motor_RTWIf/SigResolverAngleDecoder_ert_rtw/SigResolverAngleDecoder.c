/*
 * File: SigResolverAngleDecoder.c
 *
 * Code generated for Simulink model 'SigResolverAngleDecoder'.
 *
 * Model version                  : 1.118
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Sep  2 15:32:21 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SigResolverAngleDecoder.h"
#include "Hal_ReadResolverSineRaw.h"
#include "Hal_ReadResolverCosineRaw.h"
#include "Hal_GetSwitchFrequency.h"
#include <math.h>
#include "rtwtypes.h"
#include "Hal_ReadCurrentTimestamp.h"
#include "Hal_ReadResolverTimestamp.h"
#include "Hal_GetSwitchPeriod.h"
#include "SigResolverAngleDecoder_private.h"
#include "plook_u32ff_evenc.h"
#include "intrp1d_fu32fl.h"

#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
/* Exported block signals */
real32_T SGRD_NewEstTheta;             /* '<Root>/SGRD_NewEstTheta' */
real32_T SGRD_NewEstOmega;             /* '<Root>/SGRD_NewEstOmega' */

/* Exported data definition */


/* Definition for custom storage class: MtrCtrl_Par */
volatile real32_T SGRD_AmpDosFaultThr_C = 20480.0F;/* Referenced by: '<S81>/Constant' */

/* Dos fault threshold for amplitude detection */
volatile real32_T SGRD_AmpLoFaultThr_C = 5000.0F;/* Referenced by:
                                                  * '<S73>/Constant'
                                                  * '<S101>/Constant'
                                                  */

/* Lower threshold for amplitude fault detection */
volatile uint8_T SGRD_AngleCompEna_C = 1U;/* Referenced by: '<S53>/Constant' */

/* Enable flag for angle compensation */
volatile real32_T SGRD_CosAmp_C = 7.947E-5F;/* Referenced by: '<S41>/Constant' */

/* Amplitude calibration for cosine channel */
volatile real32_T SGRD_CosOffset_C = -29.0F;/* Referenced by: '<S40>/Constant' */

/* Offset calibration for cosine channel */
volatile uint16_T SGRD_DebounceDecr_C = 30U;/* Referenced by:
                                             * '<S76>/Constant'
                                             * '<S84>/Constant'
                                             * '<S95>/Constant'
                                             * '<S104>/Constant'
                                             */

/* Decrement step for fault debounce counter */
volatile uint16_T SGRD_DebounceIncr_C = 1U;/* Referenced by:
                                            * '<S75>/Constant'
                                            * '<S83>/Constant'
                                            * '<S94>/Constant'
                                            * '<S103>/Constant'
                                            */

/* Increment step for fault debounce counter */
volatile uint16_T SGRD_DebounceMaxHi_C = 30U;/* Referenced by: '<S82>/Constant' */

/* Maximum counter for high amplitude fault debounce */
volatile uint16_T SGRD_DebounceMaxLo_C = 30U;/* Referenced by:
                                              * '<S74>/Constant'
                                              * '<S102>/Constant'
                                              */

/* Maximum counter for low amplitude fault debounce */
volatile uint16_T SGRD_DebounceMaxLoss_C = 30U;/* Referenced by: '<S93>/Constant' */

/* Maximum counter for signal loss fault debounce */
volatile uint8_T SGRD_FaultResetEna_C = 1U;/* Referenced by: '<S43>/Constant' */

/* Enable automatic fault reset for resolver diagnostics */
volatile real32_T SGRD_GrpDlyResolverADC_C = 9.0E-5F;/* Referenced by: '<S52>/Constant' */

/* Group delay compensation for resolver ADC */
volatile uint16_T SGRD_InitTimeCount_C = 500U;/* Referenced by: '<S108>/Constant' */

/* Time counter for resolver ADC initialization (500ms) */
volatile real32_T SGRD_MaxAccelLmt_C = 125600.0F;/* Referenced by: '<S32>/Constant' */

/* Maximum allowable angular acceleration */
volatile real32_T SGRD_MaxJerkLmt_C = 1.256E+8F;/* Referenced by: '<S34>/Constant' */

/* Maximum allowable angular jerk */
volatile real32_T SGRD_MaxSpdLmt_C = 12560.0F;/* Referenced by: '<S26>/Constant' */

/* Maximum allowable angular velocity */
volatile real32_T SGRD_ObsrKi_C = 518150.0F;/* Referenced by: '<S16>/Constant' */

/* Integral gain for 3rd-order angle observer */
volatile real32_T SGRD_ObsrKii_C = 3.1006E+7F;/* Referenced by: '<S17>/Constant' */

/* Double integral gain for 3rd-order angle observer */
volatile real32_T SGRD_ObsrKp_C = 1649.3F;/* Referenced by: '<S15>/Constant' */

/* Proportional gain for 3rd-order angle observer */
volatile uint8_T SGRD_ResolverDirection = 1U;/* Referenced by:
                                              * '<S54>/Constant'
                                              * '<S55>/Constant'
                                              */

/* Configuration for resolver rotation direction */
volatile real32_T SGRD_SignalLotThr_C = 5.0F;/* Referenced by: '<S96>/Constant' */

/* Lot fault threshold for signal loss detection */
volatile real32_T SGRD_SineAmp_C = 7.9386E-5F;/* Referenced by: '<S39>/Constant' */

/* Amplitude calibration for sine channel */
volatile real32_T SGRD_SineOffset_C = -215.0F;/* Referenced by: '<S38>/Constant' */

/* Offset calibration for sine channel */
volatile real32_T SGRD_SpdFilterBw_C = 314.16F;/* Referenced by: '<S56>/Constant' */

/* Cutoff frequency for speed low-pass filter */
volatile real32_T SGRD_SpdThrLoFaultDiagLo_C = 670.21F;/* Referenced by: '<S91>/Constant' */

/* Lower speed threshold for low amplitude fault diagnosis */
volatile real32_T SGRD_SpdThrLoFaultDiag_C = 837.75F;/* Referenced by: '<S90>/Constant' */

/* Speed threshold for low amplitude fault diagnosis */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Sig */
uint32_T SGRD_AngleTS;            /* Timestamp for angle measurement sampling */
real32_T SGRD_CompAngle;               /* Delta Times */
real32_T SGRD_CosEnvelope;             /* '<S4>/Data Type Conversion8' */

/* Raw sine signal from resolver */
real32_T SGRD_CosNorm; /* Normalized cosine signal after amplitude correction */
int16_T SGRD_CosRaw;                   /* Raw cosine signal from resolver */
real32_T SGRD_CosRaw3Dly_IRV;          /* '<S10>/Delay2' */

/* Raw cosine signal with 3-sample delay */
real32_T SGRD_CosRaw6Dly_IRV;          /* '<S10>/Delay3' */

/* Raw cosine signal with 6-sample delay */
real32_T SGRD_CosRaw_IRV;              /* '<S10>/Data Type Conversion1' */

/* Raw cosine signal for internal processing */
uint32_T SGRD_CurrentTS;        /* Timestamp for current measurement sampling */
real32_T SGRD_DeltaTimes;              /* Delta Times */
real32_T SGRD_ElecAngle;               /* '<S44>/Switch' */

/* Electrical angle from observer with compensation */
real32_T SGRD_EstAngle;                /* Delta Times */
real32_T SGRD_EstOmega;                /* '<S27>/Switch2' */
real32_T SGRD_EstTheta;                /* '<S19>/Switch' */
real32_T SGRD_ObsrAngleDelta;        /* Angle delta from observer calculation */
real32_T SGRD_ObsrAngleDelta_IRV;      /* '<S18>/Add' */

/* Observer angle delta for internal calculation */
real32_T SGRD_ObsrSpd;            /* Filtered angular frequency from observer */
real32_T SGRD_ObsrSpdRaw;              /* Raw angular frequency from observer */
real32_T SGRD_ObsrSpeed_IRV;           /* '<S2>/Switch2' */

/* Observer angular speed for internal calculation */
real32_T SGRD_PwmFreq;                 /* '<S4>/Data Type Conversion5' */

/* Control system switching Frequency */
real32_T SGRD_PwmTs;                   /* '<S46>/Data Type Conversion2' */
uint8_T SGRD_ResolverErr;              /* '<S65>/Add' */

/* Resolver fault detection signal */
uint8_T SGRD_ResolverErrLatched;
                              /* Latched fault flag from resolver diagnostics */
uint8_T SGRD_ResolverErr_IRV;          /* '<S61>/ErrCodeCalc' */

/* Resolver error signal for internal use */
real32_T SGRD_SinEnvelope;             /* '<S4>/Data Type Conversion9' */

/* Raw sine signal from resolver */
real32_T SGRD_SineNorm;  /* Normalized sine signal after amplitude correction */
int16_T SGRD_SineRaw;                  /* Raw sine signal from resolver */
real32_T SGRD_SineRaw3Dly_IRV;         /* '<S10>/Delay' */

/* Raw sine signal with 3-sample delay */
real32_T SGRD_SineRaw6Dly_IRV;         /* '<S10>/Delay1' */

/* Raw sine signal with 6-sample delay */
real32_T SGRD_SineRaw_IRV;             /* '<S10>/Data Type Conversion' */

/* Raw sine signal for internal processing */
real32_T SGRD_SwitchFreq;              /* Control system switching Frequency */
real32_T SGRD_SwitchPeriod;            /* Control system switching period */



/* Block states (default storage) */
DW_SigResolverAngleDecoder_T SigResolverAngleDecoder_DW;

/* Real-time model */
static RT_MODEL_SigResolverAngleDecoder_T SigResolverAngleDecoder_M_;
RT_MODEL_SigResolverAngleDecoder_T *const SigResolverAngleDecoder_M =
  &SigResolverAngleDecoder_M_;
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
/* Model step function */
#pragma ghs section data =".rdc_data"
#pragma ghs section text =".rdc_code"
#pragma ghs section bss =".rdc_bss"

void SGRD_AngleObserver_96us(void)
{
  int_T idxDelay;
  real32_T correctedAngleV;
  real32_T rtb_Add_g;
  real32_T rtb_Sum1_g;
  real32_T rtb_Sum2;
  uint32_T bpIdx;
  int16_T rtb_DataTypeConversion1;
  int16_T rtb_DataTypeConversion_l;
  boolean_T negFlag;
  boolean_T rtb_LogicalOperator_a;
  static real32_T tableData_c[101] = { 0.0F, 0.0157073177F, 0.0314107575F,
    0.0471064523F, 0.0627905205F, 0.0784591F, 0.0941083133F, 0.109734312F,
    0.125333235F, 0.140901238F, 0.156434461F, 0.171929106F, 0.187381312F,
    0.202787295F, 0.21814324F, 0.233445361F, 0.24868989F, 0.263873041F,
    0.278991103F, 0.294040322F, 0.309017F, 0.323917419F, 0.338737935F,
    0.353474855F, 0.368124545F, 0.382683426F, 0.397147894F, 0.411514372F,
    0.425779283F, 0.439939171F, 0.453990489F, 0.46792981F, 0.481753677F,
    0.495458663F, 0.509041429F, 0.522498548F, 0.535826802F, 0.549022794F,
    0.562083364F, 0.575005233F, 0.587785244F, 0.600420237F, 0.612907052F,
    0.625242651F, 0.637424F, 0.649448037F, 0.661311865F, 0.673012495F,
    0.684547126F, 0.695912778F, 0.707106769F, 0.718126297F, 0.72896862F,
    0.739631116F, 0.750111043F, 0.760405958F, 0.770513237F, 0.780430436F,
    0.790155F, 0.799684644F, 0.809017F, 0.818149745F, 0.827080548F, 0.835807383F,
    0.844327927F, 0.852640152F, 0.860742033F, 0.868631542F, 0.876306653F,
    0.883765638F, 0.891006529F, 0.898027599F, 0.904827058F, 0.911403298F,
    0.91775465F, 0.923879504F, 0.92977649F, 0.935444057F, 0.940880775F,
    0.946085334F, 0.95105654F, 0.955793F, 0.96029371F, 0.964557409F,
    0.968583167F, 0.972369909F, 0.975916743F, 0.979222834F, 0.982287228F,
    0.985109329F, 0.987688363F, 0.990023673F, 0.992114723F, 0.993961F,
    0.995561957F, 0.996917307F, 0.998026729F, 0.998889863F, 0.999506533F,
    0.999876618F, 1.0F };

  /* RootInportFunctionCallGenerator generated from: '<Root>/SGRD_AngleObserver_96us' incorporates:
   *  SubSystem: '<Root>/SGRD_AngleObserver_96us_sys'
   */
  /* FunctionCaller: '<S4>/Hal_ReadResolverSineRaw' */
  rtb_DataTypeConversion_l = Hal_ReadResolverSineRaw();

  /* DataStoreWrite: '<S6>/Data Store Write' */
  SGRD_SineRaw = rtb_DataTypeConversion_l;

  /* FunctionCaller: '<S4>/Hal_ReadResolverCosineRaw' */
  rtb_DataTypeConversion1 = Hal_ReadResolverCosineRaw();

  /* DataStoreWrite: '<S8>/Data Store Write' */
  SGRD_CosRaw = rtb_DataTypeConversion1;

  /* DataTypeConversion: '<S4>/Data Type Conversion5' incorporates:
   *  FunctionCaller: '<S4>/Hal_GetSwitchFrequency'
   */
  SGRD_PwmFreq = Hal_GetSwitchFrequency();

  /* DataStoreWrite: '<S7>/Data Store Write' */
  SGRD_SwitchFreq = SGRD_PwmFreq;

  /* DataTypeConversion: '<S4>/Data Type Conversion9' */
  SGRD_SinEnvelope = (real32_T)rtb_DataTypeConversion_l;

  /* DataTypeConversion: '<S4>/Data Type Conversion8' */
  SGRD_CosEnvelope = (real32_T)rtb_DataTypeConversion1;

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  SGRD_SineRaw_IRV = (real32_T)rtb_DataTypeConversion_l;

  /* Product: '<S10>/Divide' incorporates:
   *  Constant: '<S38>/Constant'
   *  Constant: '<S39>/Constant'
   *  DataStoreWrite: '<S36>/Data Store Write'
   *  Sum: '<S10>/Add'
   */
  SGRD_SineNorm = (SGRD_SineRaw_IRV - SGRD_SineOffset_C) * SGRD_SineAmp_C;

  /* Delay: '<S12>/Delay' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S9>/Constant'
   */
  SigResolverAngleDecoder_DW.icLoad = ((((uint8_T)0U) != 0) ||
    SigResolverAngleDecoder_DW.icLoad);
  if (SigResolverAngleDecoder_DW.icLoad) {
    SigResolverAngleDecoder_DW.Delay_DSTATE_p = 0.0F;
  }

  /* Delay: '<S12>/Delay1' incorporates:
   *  Constant: '<S12>/Constant3'
   *  Constant: '<S9>/Constant1'
   */
  SigResolverAngleDecoder_DW.icLoad_h = ((((uint8_T)0U) != 0) ||
    SigResolverAngleDecoder_DW.icLoad_h);
  if (SigResolverAngleDecoder_DW.icLoad_h) {
    SigResolverAngleDecoder_DW.Delay1_DSTATE = 0.0F;
  }

  /* Sum: '<S12>/Add' incorporates:
   *  Constant: '<S9>/Constant2'
   *  Delay: '<S12>/Delay'
   *  Delay: '<S12>/Delay1'
   *  Product: '<S12>/Product3'
   */
  rtb_Add_g = SigResolverAngleDecoder_DW.Delay_DSTATE_p * 9.984E-5F +
    SigResolverAngleDecoder_DW.Delay1_DSTATE;

  /* DataTypeConversion: '<S19>/Data Type Conversion' incorporates:
   *  Constant: '<S19>/Constant'
   *  Product: '<S19>/Product'
   */
  rtb_Sum1_g = 0.159154937F * rtb_Add_g;
  if (rtb_Sum1_g < 2.14748365E+9F) {
    if (rtb_Sum1_g >= -2.14748365E+9F) {
      idxDelay = (int32_T)rtb_Sum1_g;
    } else {
      idxDelay = INT32_MIN;
    }
  } else {
    idxDelay = INT32_MAX;
  }

  /* Sum: '<S19>/Add' incorporates:
   *  Constant: '<S19>/Constant1'
   *  DataTypeConversion: '<S19>/Data Type Conversion'
   *  Product: '<S19>/Product1'
   */
  SGRD_EstTheta = rtb_Add_g - (real32_T)idxDelay * 6.28318548F;

  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<S19>/Constant2'
   *  Constant: '<S19>/Constant3'
   *  RelationalOperator: '<S19>/Relational Operator'
   *  RelationalOperator: '<S19>/Relational Operator1'
   *  Switch: '<S19>/Switch1'
   */
  if (SGRD_EstTheta < (-3.14159274F)) {
    /* Sum: '<S19>/Add' incorporates:
     *  Constant: '<S19>/Constant4'
     *  Sum: '<S19>/Add1'
     *  Switch: '<S19>/Switch'
     */
    SGRD_EstTheta = 6.28318548F + SGRD_EstTheta;
  } else if (SGRD_EstTheta > 3.14159274F) {
    /* Sum: '<S19>/Add' incorporates:
     *  Constant: '<S19>/Constant5'
     *  Sum: '<S19>/Add2'
     *  Switch: '<S19>/Switch'
     *  Switch: '<S19>/Switch1'
     */
    SGRD_EstTheta = SGRD_EstTheta - 6.28318548F;
  }

  /* End of Switch: '<S19>/Switch' */

  /* Trigonometry: '<S12>/Sin' incorporates:
   *  Trigonometry: '<S12>/Sin1'
   */
  rtb_Add_g = SGRD_EstTheta / 6.28318548F;
  if (rtb_Add_g < 0.0F) {
    rtb_Sum1_g = rtb_Add_g + 1.0F;
    correctedAngleV = rtb_Add_g + 1.0F;
  } else {
    rtb_Sum1_g = rtb_Add_g;
    correctedAngleV = rtb_Add_g;
  }

  correctedAngleV += 0.25F;
  if (rtb_Sum1_g + 0.25F >= 1.0F) {
    correctedAngleV = (rtb_Sum1_g + 0.25F) - 1.0F;
  }

  if (correctedAngleV > 0.5F) {
    correctedAngleV -= 0.5F;
    negFlag = true;
  } else {
    negFlag = false;
  }

  if (correctedAngleV > 0.25F) {
    correctedAngleV = 0.5F - correctedAngleV;
  }

  bpIdx = plook_u32ff_evenc(correctedAngleV, 0.0F, 0.0025F, 100U, &rtb_Sum1_g);
  correctedAngleV = intrp1d_fu32fl(bpIdx, rtb_Sum1_g, tableData_c);
  if (negFlag) {
    correctedAngleV = -correctedAngleV;
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion8'
   */
  SGRD_CosRaw_IRV = (real32_T)rtb_DataTypeConversion1;

  /* Product: '<S10>/Divide1' incorporates:
   *  Constant: '<S40>/Constant'
   *  Constant: '<S41>/Constant'
   *  DataStoreWrite: '<S37>/Data Store Write'
   *  Sum: '<S10>/Add1'
   */
  SGRD_CosNorm = (SGRD_CosRaw_IRV - SGRD_CosOffset_C) * SGRD_CosAmp_C;

  /* Trigonometry: '<S12>/Sin1' */
  if (rtb_Add_g < 0.0F) {
    rtb_Add_g++;
  }

  if (rtb_Add_g > 0.5F) {
    rtb_Add_g -= 0.5F;
    negFlag = true;
  } else {
    negFlag = false;
  }

  if (rtb_Add_g > 0.25F) {
    rtb_Add_g = 0.5F - rtb_Add_g;
  }

  bpIdx = plook_u32ff_evenc(rtb_Add_g, 0.0F, 0.0025F, 100U, &rtb_Sum1_g);
  rtb_Add_g = intrp1d_fu32fl(bpIdx, rtb_Sum1_g, tableData_c);
  if (negFlag) {
    rtb_Add_g = -rtb_Add_g;
  }

  /* Sum: '<S18>/Add' incorporates:
   *  DataStoreWrite: '<S36>/Data Store Write'
   *  DataStoreWrite: '<S37>/Data Store Write'
   *  Product: '<S18>/Product'
   *  Product: '<S18>/Product1'
   *  Trigonometry: '<S12>/Sin'
   *  Trigonometry: '<S12>/Sin1'
   */
  SGRD_ObsrAngleDelta_IRV = SGRD_SineNorm * correctedAngleV - SGRD_CosNorm *
    rtb_Add_g;

  /* Product: '<S12>/Product2' incorporates:
   *  Constant: '<S17>/Constant'
   */
  rtb_Add_g = SGRD_ObsrAngleDelta_IRV * SGRD_ObsrKii_C;

  /* Switch: '<S35>/Switch2' incorporates:
   *  Constant: '<S34>/Constant'
   *  RelationalOperator: '<S35>/LowerRelop1'
   *  RelationalOperator: '<S35>/UpperRelop'
   *  Switch: '<S35>/Switch'
   *  UnaryMinus: '<S23>/Unary Minus'
   */
  if (rtb_Add_g > SGRD_MaxJerkLmt_C) {
    rtb_Add_g = SGRD_MaxJerkLmt_C;
  } else if (rtb_Add_g < -SGRD_MaxJerkLmt_C) {
    /* Switch: '<S35>/Switch' incorporates:
     *  UnaryMinus: '<S23>/Unary Minus'
     */
    rtb_Add_g = -SGRD_MaxJerkLmt_C;
  }

  /* End of Switch: '<S35>/Switch2' */

  /* Logic: '<S11>/Logical Operator' incorporates:
   *  Constant: '<S42>/Constant'
   *  Constant: '<S43>/Constant'
   *  RelationalOperator: '<S42>/Compare'
   */
  negFlag = ((SGRD_ResolverErr_IRV != ((uint8_T)0U)) && (SGRD_FaultResetEna_C !=
              0));

  /* Delay: '<S30>/Delay' incorporates:
   *  Constant: '<S30>/Constant1'
   */
  SigResolverAngleDecoder_DW.icLoad_j = (negFlag ||
    SigResolverAngleDecoder_DW.icLoad_j);
  if (SigResolverAngleDecoder_DW.icLoad_j) {
    SigResolverAngleDecoder_DW.Delay_DSTATE_pn = ((uint8_T)0U);
  }

  /* Logic: '<S22>/Logical Operator' incorporates:
   *  Delay: '<S30>/Delay'
   */
  rtb_LogicalOperator_a = (negFlag ||
    (SigResolverAngleDecoder_DW.Delay_DSTATE_pn != 0));

  /* Delay: '<S28>/Delay' incorporates:
   *  Constant: '<S28>/Constant2'
   */
  SigResolverAngleDecoder_DW.icLoad_p = (rtb_LogicalOperator_a ||
    SigResolverAngleDecoder_DW.icLoad_p);
  if (SigResolverAngleDecoder_DW.icLoad_p) {
    SigResolverAngleDecoder_DW.Delay_DSTATE_i = 0.0F;
  }

  /* Delay: '<S28>/Delay1' */
  SigResolverAngleDecoder_DW.icLoad_e = (rtb_LogicalOperator_a ||
    SigResolverAngleDecoder_DW.icLoad_e);
  if (SigResolverAngleDecoder_DW.icLoad_e) {
    /* Sum: '<S28>/Sum1' incorporates:
     *  Constant: '<S12>/Constant2'
     */
    SigResolverAngleDecoder_DW.Delay1_DSTATE_o = 0.0F;
  }

  /* Sum: '<S28>/Sum1' incorporates:
   *  Constant: '<S28>/Constant3'
   *  Constant: '<S9>/Constant2'
   *  Delay: '<S28>/Delay'
   *  Delay: '<S28>/Delay1'
   *  Product: '<S28>/Product'
   *  Product: '<S28>/Product1'
   *  Sum: '<S28>/Sum3'
   */
  SigResolverAngleDecoder_DW.Delay1_DSTATE_o += (rtb_Add_g +
    SigResolverAngleDecoder_DW.Delay_DSTATE_i) * 0.5F * 9.984E-5F;

  /* Switch: '<S33>/Switch2' incorporates:
   *  Constant: '<S32>/Constant'
   *  RelationalOperator: '<S33>/LowerRelop1'
   *  RelationalOperator: '<S33>/UpperRelop'
   *  Switch: '<S33>/Switch'
   *  UnaryMinus: '<S31>/Unary Minus'
   */
  if (SigResolverAngleDecoder_DW.Delay1_DSTATE_o > SGRD_MaxAccelLmt_C) {
    correctedAngleV = SGRD_MaxAccelLmt_C;
  } else if (SigResolverAngleDecoder_DW.Delay1_DSTATE_o < -SGRD_MaxAccelLmt_C) {
    /* Switch: '<S33>/Switch' incorporates:
     *  UnaryMinus: '<S31>/Unary Minus'
     */
    correctedAngleV = -SGRD_MaxAccelLmt_C;
  } else {
    correctedAngleV = SigResolverAngleDecoder_DW.Delay1_DSTATE_o;
  }

  /* End of Switch: '<S33>/Switch2' */

  /* Sum: '<S12>/Sum1' incorporates:
   *  Constant: '<S16>/Constant'
   *  Product: '<S12>/Product1'
   */
  rtb_Sum1_g = SGRD_ObsrAngleDelta_IRV * SGRD_ObsrKi_C + correctedAngleV;

  /* Delay: '<S24>/Delay' incorporates:
   *  Constant: '<S24>/Constant1'
   */
  SigResolverAngleDecoder_DW.icLoad_o = (negFlag ||
    SigResolverAngleDecoder_DW.icLoad_o);
  if (SigResolverAngleDecoder_DW.icLoad_o) {
    SigResolverAngleDecoder_DW.Delay_DSTATE_g = ((uint8_T)0U);
  }

  /* Delay: '<S21>/Delay' incorporates:
   *  Constant: '<S21>/Constant2'
   *  Delay: '<S24>/Delay'
   */
  SigResolverAngleDecoder_DW.icLoad_ee =
    ((SigResolverAngleDecoder_DW.Delay_DSTATE_g != 0) ||
     SigResolverAngleDecoder_DW.icLoad_ee);
  if (SigResolverAngleDecoder_DW.icLoad_ee) {
    SigResolverAngleDecoder_DW.Delay_DSTATE_m = 0.0F;
  }

  /* Delay: '<S21>/Delay1' incorporates:
   *  Delay: '<S24>/Delay'
   */
  SigResolverAngleDecoder_DW.icLoad_f =
    ((SigResolverAngleDecoder_DW.Delay_DSTATE_g != 0) ||
     SigResolverAngleDecoder_DW.icLoad_f);
  if (SigResolverAngleDecoder_DW.icLoad_f) {
    /* Sum: '<S21>/Sum1' incorporates:
     *  Constant: '<S9>/Constant'
     */
    SigResolverAngleDecoder_DW.Delay1_DSTATE_h = 0.0F;
  }

  /* Sum: '<S21>/Sum1' incorporates:
   *  Constant: '<S21>/Constant3'
   *  Constant: '<S9>/Constant2'
   *  Delay: '<S21>/Delay'
   *  Delay: '<S21>/Delay1'
   *  Product: '<S21>/Product'
   *  Product: '<S21>/Product1'
   *  Sum: '<S21>/Sum3'
   */
  SigResolverAngleDecoder_DW.Delay1_DSTATE_h += (rtb_Sum1_g +
    SigResolverAngleDecoder_DW.Delay_DSTATE_m) * 0.5F * 9.984E-5F;

  /* Sum: '<S12>/Sum2' incorporates:
   *  Constant: '<S15>/Constant'
   *  Product: '<S12>/Product'
   */
  rtb_Sum2 = SGRD_ObsrAngleDelta_IRV * SGRD_ObsrKp_C +
    SigResolverAngleDecoder_DW.Delay1_DSTATE_h;

  /* Switch: '<S27>/Switch2' incorporates:
   *  Constant: '<S26>/Constant'
   *  RelationalOperator: '<S27>/LowerRelop1'
   *  RelationalOperator: '<S27>/UpperRelop'
   *  Switch: '<S27>/Switch'
   *  UnaryMinus: '<S25>/Unary Minus'
   */
  if (rtb_Sum2 > SGRD_MaxSpdLmt_C) {
    /* Switch: '<S27>/Switch2' */
    SGRD_EstOmega = SGRD_MaxSpdLmt_C;
  } else if (rtb_Sum2 < -SGRD_MaxSpdLmt_C) {
    /* Switch: '<S27>/Switch' incorporates:
     *  Switch: '<S27>/Switch2'
     *  UnaryMinus: '<S25>/Unary Minus'
     */
    SGRD_EstOmega = -SGRD_MaxSpdLmt_C;
  } else {
    /* Switch: '<S27>/Switch2' incorporates:
     *  Switch: '<S27>/Switch'
     */
    SGRD_EstOmega = rtb_Sum2;
  }

  /* End of Switch: '<S27>/Switch2' */

  /* DataStoreWrite: '<S13>/Data Store Write' */
  SGRD_ObsrSpdRaw = SGRD_EstOmega;

  /* DataStoreWrite: '<S14>/Data Store Write' */
  SGRD_ObsrAngleDelta = SGRD_ObsrAngleDelta_IRV;

  /* Delay: '<S10>/Delay' */
  SGRD_SineRaw3Dly_IRV = SigResolverAngleDecoder_DW.Delay_DSTATE_c[0];

  /* Delay: '<S10>/Delay1' */
  SGRD_SineRaw6Dly_IRV = SigResolverAngleDecoder_DW.Delay1_DSTATE_j[0];

  /* Delay: '<S10>/Delay2' */
  SGRD_CosRaw3Dly_IRV = SigResolverAngleDecoder_DW.Delay2_DSTATE[0];

  /* Delay: '<S10>/Delay3' */
  SGRD_CosRaw6Dly_IRV = SigResolverAngleDecoder_DW.Delay3_DSTATE[0];

  /* Update for Delay: '<S12>/Delay' */
  SigResolverAngleDecoder_DW.icLoad = false;
  SigResolverAngleDecoder_DW.Delay_DSTATE_p = SGRD_EstOmega;

  /* Update for Delay: '<S12>/Delay1' */
  SigResolverAngleDecoder_DW.icLoad_h = false;
  SigResolverAngleDecoder_DW.Delay1_DSTATE = SGRD_EstTheta;

  /* Update for Delay: '<S30>/Delay' incorporates:
   *  Abs: '<S30>/Abs'
   *  Constant: '<S30>/Constant'
   *  DataTypeConversion: '<S30>/Data Type Conversion1'
   *  RelationalOperator: '<S30>/Relational Operator'
   *  Sum: '<S30>/Add'
   */
  SigResolverAngleDecoder_DW.icLoad_j = false;
  SigResolverAngleDecoder_DW.Delay_DSTATE_pn = (uint8_T)((real32_T)fabs
    (SigResolverAngleDecoder_DW.Delay1_DSTATE_o - correctedAngleV) > 1.0E-7);

  /* Update for Delay: '<S28>/Delay' */
  SigResolverAngleDecoder_DW.icLoad_p = false;
  SigResolverAngleDecoder_DW.Delay_DSTATE_i = rtb_Add_g;

  /* Update for Delay: '<S28>/Delay1' */
  SigResolverAngleDecoder_DW.icLoad_e = false;

  /* Update for Delay: '<S24>/Delay' incorporates:
   *  Abs: '<S24>/Abs'
   *  Constant: '<S24>/Constant'
   *  DataTypeConversion: '<S24>/Data Type Conversion1'
   *  RelationalOperator: '<S24>/Relational Operator'
   *  Sum: '<S24>/Add'
   */
  SigResolverAngleDecoder_DW.icLoad_o = false;
  SigResolverAngleDecoder_DW.Delay_DSTATE_g = (uint8_T)((real32_T)fabs(rtb_Sum2
    - SGRD_EstOmega) > 1.0E-7);

  /* Update for Delay: '<S21>/Delay' */
  SigResolverAngleDecoder_DW.icLoad_ee = false;
  SigResolverAngleDecoder_DW.Delay_DSTATE_m = rtb_Sum1_g;

  /* Update for Delay: '<S21>/Delay1' */
  SigResolverAngleDecoder_DW.icLoad_f = false;

  /* Update for Delay: '<S10>/Delay' */
  SigResolverAngleDecoder_DW.Delay_DSTATE_c[0] =
    SigResolverAngleDecoder_DW.Delay_DSTATE_c[1];
  SigResolverAngleDecoder_DW.Delay_DSTATE_c[1] =
    SigResolverAngleDecoder_DW.Delay_DSTATE_c[2];
  SigResolverAngleDecoder_DW.Delay_DSTATE_c[2] = SGRD_SineRaw_IRV;

  /* Update for Delay: '<S10>/Delay2' */
  SigResolverAngleDecoder_DW.Delay2_DSTATE[0] =
    SigResolverAngleDecoder_DW.Delay2_DSTATE[1];
  SigResolverAngleDecoder_DW.Delay2_DSTATE[1] =
    SigResolverAngleDecoder_DW.Delay2_DSTATE[2];
  SigResolverAngleDecoder_DW.Delay2_DSTATE[2] = SGRD_CosRaw_IRV;
  for (idxDelay = 0; idxDelay < 5; idxDelay++) {
    /* Update for Delay: '<S10>/Delay1' */
    SigResolverAngleDecoder_DW.Delay1_DSTATE_j[idxDelay] =
      SigResolverAngleDecoder_DW.Delay1_DSTATE_j[idxDelay + 1];

    /* Update for Delay: '<S10>/Delay3' */
    SigResolverAngleDecoder_DW.Delay3_DSTATE[idxDelay] =
      SigResolverAngleDecoder_DW.Delay3_DSTATE[idxDelay + 1];
  }

  /* Update for Delay: '<S10>/Delay1' */
  SigResolverAngleDecoder_DW.Delay1_DSTATE_j[5] = SGRD_SineRaw_IRV;

  /* Update for Delay: '<S10>/Delay3' */
  SigResolverAngleDecoder_DW.Delay3_DSTATE[5] = SGRD_CosRaw_IRV;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SGRD_AngleObserver_96us' */
}

#pragma ghs section
#pragma ghs section
#pragma ghs section


/* Model step function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void SGRD_CalcElecAngle_100us(void)
{
  int32_T tmp_0;
  real32_T rtb_Add1;
  real32_T tmp;
  uint32_T rtb_DataTypeConversion3;
  uint32_T rtb_DataTypeConversion4;

  /* RootInportFunctionCallGenerator generated from: '<Root>/SGRD_CalcElecAngle_100us' incorporates:
   *  SubSystem: '<Root>/SGRD_CalcElecAngle_100us_sys'
   */
  /* FunctionCaller: '<S46>/Hal_ReadCurrentTimestamp' */
  rtb_DataTypeConversion3 = Hal_ReadCurrentTimestamp();

  /* DataStoreWrite: '<S58>/Data Store Write' */
  SGRD_CurrentTS = rtb_DataTypeConversion3;

  /* FunctionCaller: '<S46>/Hal_ReadResolverTimestamp' */
  rtb_DataTypeConversion4 = Hal_ReadResolverTimestamp();

  /* DataStoreWrite: '<S59>/Data Store Write' */
  SGRD_AngleTS = rtb_DataTypeConversion4;

  /* DataTypeConversion: '<S46>/Data Type Conversion2' incorporates:
   *  FunctionCaller: '<S46>/Hal_GetSwitchPeriod'
   */
  SGRD_PwmTs = Hal_GetSwitchPeriod();

  /* DataStoreWrite: '<S57>/Data Store Write' */
  SGRD_SwitchPeriod = SGRD_PwmTs;

  /* Product: '<S51>/Product' incorporates:
   *  Constant: '<S56>/Constant'
   */
  rtb_Add1 = SGRD_SpdFilterBw_C * SGRD_PwmTs;

  /* Saturate: '<S51>/Saturation' */
  if (rtb_Add1 > 1.0F) {
    rtb_Add1 = 1.0F;
  } else if (rtb_Add1 < 0.0F) {
    rtb_Add1 = 0.0F;
  }

  /* Sum: '<S51>/Subtract1' incorporates:
   *  Delay: '<S51>/Delay'
   *  Inport: '<Root>/SGRD_NewEstOmega'
   *  Product: '<S51>/Product1'
   *  Saturate: '<S51>/Saturation'
   *  Sum: '<S51>/Subtract'
   */
  SigResolverAngleDecoder_DW.Delay_DSTATE += (SGRD_NewEstOmega -
    SigResolverAngleDecoder_DW.Delay_DSTATE) * rtb_Add1;

  /* Switch: '<S2>/Switch2' incorporates:
   *  Constant: '<S55>/Constant'
   */
  if (SGRD_ResolverDirection != 0) {
    /* Switch: '<S2>/Switch2' incorporates:
     *  Delay: '<S51>/Delay'
     */
    SGRD_ObsrSpeed_IRV = SigResolverAngleDecoder_DW.Delay_DSTATE;
  } else {
    /* Switch: '<S2>/Switch2' incorporates:
     *  Delay: '<S51>/Delay'
     *  UnaryMinus: '<S2>/Unary Minus1'
     */
    SGRD_ObsrSpeed_IRV = -SigResolverAngleDecoder_DW.Delay_DSTATE;
  }

  /* End of Switch: '<S2>/Switch2' */

  /* DataStoreWrite: '<S47>/Data Store Write' */
  SGRD_ObsrSpd = SGRD_ObsrSpeed_IRV;

  /* Sum: '<S45>/Add1' incorporates:
   *  DataTypeConversion: '<S45>/Data Type Conversion'
   *  DataTypeConversion: '<S45>/Data Type Conversion1'
   */
  rtb_Add1 = (real32_T)rtb_DataTypeConversion3 - (real32_T)
    rtb_DataTypeConversion4;

  /* Switch: '<S45>/Switch' incorporates:
   *  Constant: '<S45>/Constant1'
   *  Constant: '<S45>/Constant2'
   *  RelationalOperator: '<S45>/Relational Operator'
   *  RelationalOperator: '<S45>/Relational Operator1'
   *  Sum: '<S45>/Add2'
   *  Switch: '<S45>/Switch1'
   */
  if (rtb_Add1 >= 8.388608E+6F) {
    rtb_Add1 -= 1.6777216E+7F;
  } else if (rtb_Add1 < SigResolverAngleDecoder_ConstB.UnaryMinus) {
    /* Switch: '<S45>/Switch1' incorporates:
     *  Constant: '<S45>/Constant3'
     *  Sum: '<S45>/Add3'
     */
    rtb_Add1 += 1.6777216E+7F;
  }

  /* DataTypeConversion: '<S45>/Data Type Conversion2' incorporates:
   *  Constant: '<S45>/Constant4'
   *  DataStoreWrite: '<S48>/Data Store Write'
   *  Product: '<S45>/Product'
   *  Switch: '<S45>/Switch'
   */
  SGRD_DeltaTimes = rtb_Add1 * 5.0E-9F;

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S52>/Constant'
   *  Constant: '<S53>/Constant'
   *  DataStoreWrite: '<S48>/Data Store Write'
   *  DataStoreWrite: '<S49>/Data Store Write'
   *  Inport: '<Root>/SGRD_NewEstOmega'
   *  Product: '<S2>/Product'
   *  Sum: '<S2>/Add1'
   */
  if (SGRD_AngleCompEna_C != 0) {
    SGRD_CompAngle = (SGRD_DeltaTimes + SGRD_GrpDlyResolverADC_C) *
      SGRD_NewEstOmega;
  } else {
    SGRD_CompAngle = 0.0F;
  }

  /* End of Switch: '<S2>/Switch' */

  /* DataStoreWrite: '<S50>/Data Store Write' incorporates:
   *  Inport: '<Root>/SGRD_NewEstTheta'
   */
  SGRD_EstAngle = SGRD_NewEstTheta;

  /* Switch: '<S2>/Switch1' incorporates:
   *  Constant: '<S54>/Constant'
   *  DataStoreWrite: '<S49>/Data Store Write'
   *  Inport: '<Root>/SGRD_NewEstTheta'
   *  Sum: '<S2>/Add'
   *  UnaryMinus: '<S2>/Unary Minus'
   */
  if (SGRD_ResolverDirection != 0) {
    rtb_Add1 = SGRD_NewEstTheta + SGRD_CompAngle;
  } else {
    rtb_Add1 = -(SGRD_NewEstTheta + SGRD_CompAngle);
  }

  /* End of Switch: '<S2>/Switch1' */

  /* DataTypeConversion: '<S44>/Data Type Conversion' incorporates:
   *  Constant: '<S44>/Constant'
   *  Product: '<S44>/Product'
   */
  tmp = 0.159154937F * rtb_Add1;
  if (tmp < 2.14748365E+9F) {
    if (tmp >= -2.14748365E+9F) {
      tmp_0 = (int32_T)tmp;
    } else {
      tmp_0 = INT32_MIN;
    }
  } else {
    tmp_0 = INT32_MAX;
  }

  /* Sum: '<S44>/Add' incorporates:
   *  Constant: '<S44>/Constant1'
   *  DataTypeConversion: '<S44>/Data Type Conversion'
   *  Product: '<S44>/Product1'
   */
  SGRD_ElecAngle = rtb_Add1 - (real32_T)tmp_0 * 6.28318548F;

  /* Switch: '<S44>/Switch' incorporates:
   *  Constant: '<S44>/Constant2'
   *  RelationalOperator: '<S44>/Relational Operator'
   */
  if (SGRD_ElecAngle < 0.0F) {
    /* Sum: '<S44>/Add' incorporates:
     *  Constant: '<S44>/Constant4'
     *  Sum: '<S44>/Add1'
     *  Switch: '<S44>/Switch'
     */
    SGRD_ElecAngle = 6.28318548F + SGRD_ElecAngle;
  }

  /* End of Switch: '<S44>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SGRD_CalcElecAngle_100us' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model step function */
#define MTRCTRL_START_SEC_CODE_FLS_DEFAULT
#include "MtrCtrl_MemMap.h"
void SGRD_DiagResolverFault_1ms(void)
{
  int32_T tmp_0;
  real32_T rtb_Abs;
  real32_T rtb_Add_cq;
  uint32_T tmp;
  uint32_T tmp_1;
  uint16_T rtb_MultiportSwitch;
  uint8_T rtb_Gain;
  uint8_T rtb_Gain1;
  uint8_T rtb_Gain2;
  boolean_T tmp_2;

  /* RootInportFunctionCallGenerator generated from: '<Root>/SGRD_DiagResolverFault_1ms' incorporates:
   *  SubSystem: '<Root>/SGRD_DiagResolverFault_1ms_sys'
   */
  /* Sum: '<S62>/Add' incorporates:
   *  Constant: '<S62>/Constant'
   *  UnitDelay: '<S62>/Unit Delay'
   */
  tmp_1 = (uint32_T)((uint16_T)1U) + SigResolverAngleDecoder_DW.UnitDelay_DSTATE;
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* Switch: '<S109>/Switch2' incorporates:
   *  Constant: '<S108>/Constant'
   *  Constant: '<S62>/Constant1'
   *  RelationalOperator: '<S109>/LowerRelop1'
   *  RelationalOperator: '<S109>/UpperRelop'
   *  Sum: '<S62>/Add'
   *  Switch: '<S109>/Switch'
   *  UnitDelay: '<S62>/Unit Delay'
   */
  if ((uint16_T)tmp_1 > SGRD_InitTimeCount_C) {
    SigResolverAngleDecoder_DW.UnitDelay_DSTATE = SGRD_InitTimeCount_C;
  } else if ((uint16_T)tmp_1 < ((uint16_T)0U)) {
    /* Switch: '<S109>/Switch' incorporates:
     *  Constant: '<S62>/Constant1'
     *  UnitDelay: '<S62>/Unit Delay'
     */
    SigResolverAngleDecoder_DW.UnitDelay_DSTATE = ((uint16_T)0U);
  } else {
    SigResolverAngleDecoder_DW.UnitDelay_DSTATE = (uint16_T)tmp_1;
  }

  /* End of Switch: '<S109>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S60>/Diag' incorporates:
   *  EnablePort: '<S61>/Enable'
   */
  /* RelationalOperator: '<S62>/Relational Operator' incorporates:
   *  Constant: '<S108>/Constant'
   *  UnitDelay: '<S62>/Unit Delay'
   */
  if (SigResolverAngleDecoder_DW.UnitDelay_DSTATE >= SGRD_InitTimeCount_C) {
    /* Sum: '<S80>/Add2' incorporates:
     *  Constant: '<S80>/0 Constant4'
     *  Constant: '<S82>/Constant'
     */
    tmp_1 = (uint32_T)SGRD_DebounceMaxHi_C + ((uint16_T)1U);
    if (tmp_1 > 65535U) {
      tmp_1 = 65535U;
    }

    /* Sum: '<S70>/Add' incorporates:
     *  Product: '<S70>/Product'
     *  Product: '<S70>/Product1'
     */
    rtb_Add_cq = SGRD_SineRaw_IRV * SGRD_SineRaw_IRV + SGRD_CosRaw_IRV *
      SGRD_CosRaw_IRV;

    /* MultiPortSwitch: '<S80>/Multiport Switch' incorporates:
     *  Constant: '<S80>/0 Constant'
     *  Constant: '<S81>/Constant'
     *  MinMax: '<S80>/Max'
     *  Product: '<S64>/Divide1'
     *  RelationalOperator: '<S64>/Relational Operator'
     *  Sum: '<S80>/Add'
     *  Sum: '<S80>/Add1'
     *  UnitDelay: '<S87>/Bare Unit Delay'
     */
    if (!(rtb_Add_cq >= SGRD_AmpDosFaultThr_C * SGRD_AmpDosFaultThr_C)) {
      /* Sum: '<S80>/Add' incorporates:
       *  Constant: '<S84>/Constant'
       *  UnitDelay: '<S87>/Bare Unit Delay'
       */
      tmp_0 = SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE -
        SGRD_DebounceDecr_C;
      if (tmp_0 < 0) {
        tmp_0 = 0;
      }

      rtb_MultiportSwitch = (uint16_T)tmp_0;
    } else {
      if (((uint16_T)0U) >= SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE) {
        /* MinMax: '<S80>/Max' incorporates:
         *  Constant: '<S80>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint16_T)0U);
      } else {
        /* MinMax: '<S80>/Max' incorporates:
         *  UnitDelay: '<S87>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE;
      }

      /* Sum: '<S80>/Add1' incorporates:
       *  Constant: '<S83>/Constant'
       *  MinMax: '<S80>/Max'
       */
      tmp = (uint32_T)rtb_MultiportSwitch + SGRD_DebounceIncr_C;
      if (tmp > 65535U) {
        tmp = 65535U;
      }

      rtb_MultiportSwitch = (uint16_T)tmp;
    }

    /* End of MultiPortSwitch: '<S80>/Multiport Switch' */

    /* Switch: '<S87>/Enable' incorporates:
     *  Constant: '<S80>/Constant2'
     *  DataTypeConversion: '<S64>/Data Type Conversion1'
     *  Inport: '<Root>/SGPP_ClrResolverFault'
     *  Logic: '<S87>/Logical Operator1'
     *  Logic: '<S87>/Logical Operator2'
     *  Switch: '<S87>/Reset'
     */
    if ((SGPP_ClrResolverFault == 0) && true) {
      /* Switch: '<S85>/Switch2' incorporates:
       *  Constant: '<S80>/0 Constant1'
       *  RelationalOperator: '<S85>/LowerRelop1'
       *  RelationalOperator: '<S85>/UpperRelop'
       *  Sum: '<S80>/Add2'
       *  Switch: '<S85>/Switch'
       *  UnitDelay: '<S87>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint16_T)tmp_1) {
        SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE = (uint16_T)tmp_1;
      } else if (rtb_MultiportSwitch < ((uint16_T)0U)) {
        /* Switch: '<S85>/Switch' incorporates:
         *  Constant: '<S80>/0 Constant1'
         *  UnitDelay: '<S87>/Bare Unit Delay'
         */
        SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE = ((uint16_T)0U);
      } else {
        SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S85>/Switch2' */
    } else if (SGPP_ClrResolverFault != 0) {
      /* Switch: '<S87>/Reset' incorporates:
       *  Constant: '<S87>/iv'
       *  UnitDelay: '<S87>/Bare Unit Delay'
       */
      SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE = ((uint16_T)0U);
    }

    /* End of Switch: '<S87>/Enable' */

    /* Switch: '<S86>/Switch' incorporates:
     *  Constant: '<S64>/Constant'
     *  RelationalOperator: '<S80>/Relational Operator'
     *  RelationalOperator: '<S80>/Relational Operator1'
     *  Sum: '<S80>/Add2'
     *  Switch: '<S86>/Switch1'
     *  UnitDelay: '<S87>/Bare Unit Delay'
     */
    if (SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE >= (uint16_T)tmp_1) {
      /* Switch: '<S86>/Switch' incorporates:
       *  Constant: '<S86>/Constant1'
       */
      SigResolverAngleDecoder_DW.Memory_PreviousInput = true;
    } else if (SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE <= ((uint16_T)0U))
    {
      /* Switch: '<S86>/Switch' incorporates:
       *  Constant: '<S86>/Constant4'
       *  Switch: '<S86>/Switch1'
       */
      SigResolverAngleDecoder_DW.Memory_PreviousInput = false;
    }

    /* End of Switch: '<S86>/Switch' */

    /* Sum: '<S100>/Add2' incorporates:
     *  Constant: '<S100>/0 Constant4'
     *  Constant: '<S102>/Constant'
     */
    tmp_1 = (uint32_T)SGRD_DebounceMaxLo_C + ((uint16_T)1U);
    if (tmp_1 > 65535U) {
      tmp_1 = 65535U;
    }

    /* Abs: '<S66>/Abs' */
    rtb_Abs = (real32_T)fabs(SGRD_ObsrSpeed_IRV);

    /* Switch: '<S89>/Switch' incorporates:
     *  Constant: '<S89>/Constant'
     *  Constant: '<S90>/Constant'
     *  Constant: '<S91>/Constant'
     *  Delay: '<S89>/Delay'
     *  RelationalOperator: '<S89>/Relational Operator1'
     *  RelationalOperator: '<S89>/Relational Operator2'
     *  Switch: '<S89>/Switch1'
     */
    if (rtb_Abs >= SGRD_SpdThrLoFaultDiag_C) {
      SigResolverAngleDecoder_DW.Delay_DSTATE_o = true;
    } else if (rtb_Abs < SGRD_SpdThrLoFaultDiagLo_C) {
      /* Switch: '<S89>/Switch1' incorporates:
       *  Constant: '<S89>/Constant1'
       *  Delay: '<S89>/Delay'
       */
      SigResolverAngleDecoder_DW.Delay_DSTATE_o = false;
    }

    /* End of Switch: '<S89>/Switch' */

    /* Product: '<S71>/Divide1' incorporates:
     *  Constant: '<S101>/Constant'
     *  Product: '<S63>/Divide1'
     */
    rtb_Abs = SGRD_AmpLoFaultThr_C * SGRD_AmpLoFaultThr_C;

    /* Logic: '<S71>/Logical Operator3' incorporates:
     *  Delay: '<S89>/Delay'
     *  Logic: '<S63>/Logical Operator3'
     */
    tmp_2 = !SigResolverAngleDecoder_DW.Delay_DSTATE_o;

    /* MultiPortSwitch: '<S100>/Multiport Switch' incorporates:
     *  Abs: '<S71>/Abs'
     *  Constant: '<S100>/0 Constant'
     *  Constant: '<S101>/Constant'
     *  Logic: '<S71>/Logical Operator1'
     *  Logic: '<S71>/Logical Operator2'
     *  Logic: '<S71>/Logical Operator3'
     *  MinMax: '<S100>/Max'
     *  Product: '<S71>/Divide1'
     *  RelationalOperator: '<S71>/Relational Operator'
     *  RelationalOperator: '<S71>/Relational Operator1'
     *  Sum: '<S100>/Add'
     *  Sum: '<S100>/Add1'
     *  UnitDelay: '<S107>/Bare Unit Delay'
     */
    if ((!(rtb_Add_cq <= rtb_Abs)) && ((!((real32_T)fabs(SGRD_SineRaw_IRV) <=
           SGRD_AmpLoFaultThr_C)) || (!((real32_T)fabs(SGRD_SineRaw3Dly_IRV) <=
           SGRD_AmpLoFaultThr_C)) || (!((real32_T)fabs(SGRD_SineRaw6Dly_IRV) <=
           SGRD_AmpLoFaultThr_C)) || tmp_2)) {
      /* Sum: '<S100>/Add' incorporates:
       *  Constant: '<S104>/Constant'
       *  UnitDelay: '<S107>/Bare Unit Delay'
       */
      tmp_0 = SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_f -
        SGRD_DebounceDecr_C;
      if (tmp_0 < 0) {
        tmp_0 = 0;
      }

      rtb_MultiportSwitch = (uint16_T)tmp_0;
    } else {
      if (((uint16_T)0U) >= SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_f) {
        /* MinMax: '<S100>/Max' incorporates:
         *  Constant: '<S100>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint16_T)0U);
      } else {
        /* MinMax: '<S100>/Max' incorporates:
         *  UnitDelay: '<S107>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_f;
      }

      /* Sum: '<S100>/Add1' incorporates:
       *  Constant: '<S103>/Constant'
       *  MinMax: '<S100>/Max'
       */
      tmp = (uint32_T)rtb_MultiportSwitch + SGRD_DebounceIncr_C;
      if (tmp > 65535U) {
        tmp = 65535U;
      }

      rtb_MultiportSwitch = (uint16_T)tmp;
    }

    /* End of MultiPortSwitch: '<S100>/Multiport Switch' */

    /* Switch: '<S107>/Enable' incorporates:
     *  Constant: '<S100>/Constant2'
     *  DataTypeConversion: '<S71>/Data Type Conversion1'
     *  Inport: '<Root>/SGPP_ClrResolverFault'
     *  Logic: '<S107>/Logical Operator1'
     *  Logic: '<S107>/Logical Operator2'
     *  Switch: '<S107>/Reset'
     */
    if ((SGPP_ClrResolverFault == 0) && true) {
      /* Switch: '<S105>/Switch2' incorporates:
       *  Constant: '<S100>/0 Constant1'
       *  RelationalOperator: '<S105>/LowerRelop1'
       *  RelationalOperator: '<S105>/UpperRelop'
       *  Sum: '<S100>/Add2'
       *  Switch: '<S105>/Switch'
       *  UnitDelay: '<S107>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint16_T)tmp_1) {
        SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_f = (uint16_T)tmp_1;
      } else if (rtb_MultiportSwitch < ((uint16_T)0U)) {
        /* Switch: '<S105>/Switch' incorporates:
         *  Constant: '<S100>/0 Constant1'
         *  UnitDelay: '<S107>/Bare Unit Delay'
         */
        SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_f = ((uint16_T)0U);
      } else {
        SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_f = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S105>/Switch2' */
    } else if (SGPP_ClrResolverFault != 0) {
      /* Switch: '<S107>/Reset' incorporates:
       *  Constant: '<S107>/iv'
       *  UnitDelay: '<S107>/Bare Unit Delay'
       */
      SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_f = ((uint16_T)0U);
    }

    /* End of Switch: '<S107>/Enable' */

    /* Switch: '<S106>/Switch' incorporates:
     *  Constant: '<S71>/Constant'
     *  RelationalOperator: '<S100>/Relational Operator'
     *  RelationalOperator: '<S100>/Relational Operator1'
     *  Sum: '<S100>/Add2'
     *  Switch: '<S106>/Switch1'
     *  UnitDelay: '<S107>/Bare Unit Delay'
     */
    if (SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_f >= (uint16_T)tmp_1) {
      /* Switch: '<S106>/Switch' incorporates:
       *  Constant: '<S106>/Constant1'
       */
      SigResolverAngleDecoder_DW.Memory_PreviousInput_d = true;
    } else if (SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_f <= ((uint16_T)
                0U)) {
      /* Switch: '<S106>/Switch' incorporates:
       *  Constant: '<S106>/Constant4'
       *  Switch: '<S106>/Switch1'
       */
      SigResolverAngleDecoder_DW.Memory_PreviousInput_d = false;
    }

    /* End of Switch: '<S106>/Switch' */

    /* Gain: '<S65>/Gain' incorporates:
     *  DataTypeConversion: '<S106>/Data Type Conversion EveSt2'
     */
    rtb_Gain = (uint8_T)(((uint32_T)((uint8_T)128U) *
                          SigResolverAngleDecoder_DW.Memory_PreviousInput_d) >>
                         6);

    /* Sum: '<S72>/Add2' incorporates:
     *  Constant: '<S72>/0 Constant4'
     *  Constant: '<S74>/Constant'
     */
    tmp_1 = (uint32_T)SGRD_DebounceMaxLo_C + ((uint16_T)1U);
    if (tmp_1 > 65535U) {
      tmp_1 = 65535U;
    }

    /* MultiPortSwitch: '<S72>/Multiport Switch' incorporates:
     *  Abs: '<S63>/Abs'
     *  Constant: '<S72>/0 Constant'
     *  Constant: '<S73>/Constant'
     *  Logic: '<S63>/Logical Operator1'
     *  Logic: '<S63>/Logical Operator2'
     *  Logic: '<S63>/Logical Operator3'
     *  MinMax: '<S72>/Max'
     *  RelationalOperator: '<S63>/Relational Operator'
     *  RelationalOperator: '<S63>/Relational Operator1'
     *  Sum: '<S72>/Add'
     *  Sum: '<S72>/Add1'
     *  UnitDelay: '<S79>/Bare Unit Delay'
     */
    if ((!(rtb_Add_cq <= rtb_Abs)) && ((!((real32_T)fabs(SGRD_CosRaw_IRV) <=
           SGRD_AmpLoFaultThr_C)) || (!((real32_T)fabs(SGRD_CosRaw3Dly_IRV) <=
           SGRD_AmpLoFaultThr_C)) || (!((real32_T)fabs(SGRD_CosRaw6Dly_IRV) <=
           SGRD_AmpLoFaultThr_C)) || tmp_2)) {
      /* Sum: '<S72>/Add' incorporates:
       *  Constant: '<S76>/Constant'
       *  UnitDelay: '<S79>/Bare Unit Delay'
       */
      tmp_0 = SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_a -
        SGRD_DebounceDecr_C;
      if (tmp_0 < 0) {
        tmp_0 = 0;
      }

      rtb_MultiportSwitch = (uint16_T)tmp_0;
    } else {
      if (((uint16_T)0U) >= SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_a) {
        /* MinMax: '<S72>/Max' incorporates:
         *  Constant: '<S72>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint16_T)0U);
      } else {
        /* MinMax: '<S72>/Max' incorporates:
         *  UnitDelay: '<S79>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_a;
      }

      /* Sum: '<S72>/Add1' incorporates:
       *  Constant: '<S75>/Constant'
       *  MinMax: '<S72>/Max'
       */
      tmp = (uint32_T)rtb_MultiportSwitch + SGRD_DebounceIncr_C;
      if (tmp > 65535U) {
        tmp = 65535U;
      }

      rtb_MultiportSwitch = (uint16_T)tmp;
    }

    /* End of MultiPortSwitch: '<S72>/Multiport Switch' */

    /* Switch: '<S79>/Enable' incorporates:
     *  Constant: '<S72>/Constant2'
     *  DataTypeConversion: '<S63>/Data Type Conversion1'
     *  Inport: '<Root>/SGPP_ClrResolverFault'
     *  Logic: '<S79>/Logical Operator1'
     *  Logic: '<S79>/Logical Operator2'
     *  Switch: '<S79>/Reset'
     */
    if ((SGPP_ClrResolverFault == 0) && true) {
      /* Switch: '<S77>/Switch2' incorporates:
       *  Constant: '<S72>/0 Constant1'
       *  RelationalOperator: '<S77>/LowerRelop1'
       *  RelationalOperator: '<S77>/UpperRelop'
       *  Sum: '<S72>/Add2'
       *  Switch: '<S77>/Switch'
       *  UnitDelay: '<S79>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint16_T)tmp_1) {
        SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_a = (uint16_T)tmp_1;
      } else if (rtb_MultiportSwitch < ((uint16_T)0U)) {
        /* Switch: '<S77>/Switch' incorporates:
         *  Constant: '<S72>/0 Constant1'
         *  UnitDelay: '<S79>/Bare Unit Delay'
         */
        SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_a = ((uint16_T)0U);
      } else {
        SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_a = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S77>/Switch2' */
    } else if (SGPP_ClrResolverFault != 0) {
      /* Switch: '<S79>/Reset' incorporates:
       *  Constant: '<S79>/iv'
       *  UnitDelay: '<S79>/Bare Unit Delay'
       */
      SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_a = ((uint16_T)0U);
    }

    /* End of Switch: '<S79>/Enable' */

    /* Switch: '<S78>/Switch' incorporates:
     *  Constant: '<S63>/Constant'
     *  RelationalOperator: '<S72>/Relational Operator'
     *  RelationalOperator: '<S72>/Relational Operator1'
     *  Sum: '<S72>/Add2'
     *  Switch: '<S78>/Switch1'
     *  UnitDelay: '<S79>/Bare Unit Delay'
     */
    if (SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_a >= (uint16_T)tmp_1) {
      /* Switch: '<S78>/Switch' incorporates:
       *  Constant: '<S78>/Constant1'
       */
      SigResolverAngleDecoder_DW.Memory_PreviousInput_j = true;
    } else if (SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_a <= ((uint16_T)
                0U)) {
      /* Switch: '<S78>/Switch' incorporates:
       *  Constant: '<S78>/Constant4'
       *  Switch: '<S78>/Switch1'
       */
      SigResolverAngleDecoder_DW.Memory_PreviousInput_j = false;
    }

    /* End of Switch: '<S78>/Switch' */

    /* Gain: '<S65>/Gain1' incorporates:
     *  DataTypeConversion: '<S78>/Data Type Conversion EveSt2'
     */
    rtb_Gain1 = (uint8_T)(((uint32_T)((uint8_T)128U) *
      SigResolverAngleDecoder_DW.Memory_PreviousInput_j) >> 5);

    /* Sum: '<S92>/Add2' incorporates:
     *  Constant: '<S92>/0 Constant4'
     *  Constant: '<S93>/Constant'
     */
    tmp_1 = (uint32_T)SGRD_DebounceMaxLoss_C + ((uint16_T)1U);
    if (tmp_1 > 65535U) {
      tmp_1 = 65535U;
    }

    /* MultiPortSwitch: '<S92>/Multiport Switch' incorporates:
     *  Abs: '<S67>/Abs'
     *  Constant: '<S67>/Constant1'
     *  Constant: '<S92>/0 Constant'
     *  Constant: '<S96>/Constant'
     *  Logic: '<S67>/Logical Operator1'
     *  Logic: '<S67>/Logical Operator2'
     *  MinMax: '<S92>/Max'
     *  Product: '<S67>/Product'
     *  RelationalOperator: '<S67>/Relational Operator'
     *  S-Function (sfix_bitop): '<S67>/Bitwise Operator'
     *  Sum: '<S92>/Add'
     *  Sum: '<S92>/Add1'
     *  UnitDelay: '<S61>/Unit Delay'
     *  UnitDelay: '<S99>/Bare Unit Delay'
     */
    if ((!((real32_T)fabs(SGRD_ObsrAngleDelta_IRV) * 57.2957802F >
           SGRD_SignalLotThr_C)) || ((SGRD_ResolverErr & ((uint8_T)1U)) != 0)) {
      /* Sum: '<S92>/Add' incorporates:
       *  Constant: '<S95>/Constant'
       *  UnitDelay: '<S99>/Bare Unit Delay'
       */
      tmp_0 = SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_c -
        SGRD_DebounceDecr_C;
      if (tmp_0 < 0) {
        tmp_0 = 0;
      }

      rtb_MultiportSwitch = (uint16_T)tmp_0;
    } else {
      if (((uint16_T)0U) >= SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_c) {
        /* MinMax: '<S92>/Max' incorporates:
         *  Constant: '<S92>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint16_T)0U);
      } else {
        /* MinMax: '<S92>/Max' incorporates:
         *  UnitDelay: '<S99>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_c;
      }

      /* Sum: '<S92>/Add1' incorporates:
       *  Constant: '<S94>/Constant'
       *  MinMax: '<S92>/Max'
       */
      tmp = (uint32_T)rtb_MultiportSwitch + SGRD_DebounceIncr_C;
      if (tmp > 65535U) {
        tmp = 65535U;
      }

      rtb_MultiportSwitch = (uint16_T)tmp;
    }

    /* End of MultiPortSwitch: '<S92>/Multiport Switch' */

    /* Switch: '<S99>/Enable' incorporates:
     *  Constant: '<S92>/Constant2'
     *  DataTypeConversion: '<S67>/Data Type Conversion1'
     *  Inport: '<Root>/SGPP_ClrResolverFault'
     *  Logic: '<S99>/Logical Operator1'
     *  Logic: '<S99>/Logical Operator2'
     *  Switch: '<S99>/Reset'
     */
    if ((SGPP_ClrResolverFault == 0) && true) {
      /* Switch: '<S97>/Switch2' incorporates:
       *  Constant: '<S92>/0 Constant1'
       *  RelationalOperator: '<S97>/LowerRelop1'
       *  RelationalOperator: '<S97>/UpperRelop'
       *  Sum: '<S92>/Add2'
       *  Switch: '<S97>/Switch'
       *  UnitDelay: '<S99>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint16_T)tmp_1) {
        SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_c = (uint16_T)tmp_1;
      } else if (rtb_MultiportSwitch < ((uint16_T)0U)) {
        /* Switch: '<S97>/Switch' incorporates:
         *  Constant: '<S92>/0 Constant1'
         *  UnitDelay: '<S99>/Bare Unit Delay'
         */
        SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_c = ((uint16_T)0U);
      } else {
        SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_c = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S97>/Switch2' */
    } else if (SGPP_ClrResolverFault != 0) {
      /* Switch: '<S99>/Reset' incorporates:
       *  Constant: '<S99>/iv'
       *  UnitDelay: '<S99>/Bare Unit Delay'
       */
      SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_c = ((uint16_T)0U);
    }

    /* End of Switch: '<S99>/Enable' */

    /* Switch: '<S98>/Switch' incorporates:
     *  Constant: '<S67>/Constant'
     *  RelationalOperator: '<S92>/Relational Operator'
     *  RelationalOperator: '<S92>/Relational Operator1'
     *  Sum: '<S92>/Add2'
     *  Switch: '<S98>/Switch1'
     *  UnitDelay: '<S99>/Bare Unit Delay'
     */
    if (SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_c >= (uint16_T)tmp_1) {
      /* Switch: '<S98>/Switch' incorporates:
       *  Constant: '<S98>/Constant1'
       */
      SigResolverAngleDecoder_DW.Memory_PreviousInput_a = true;
    } else if (SigResolverAngleDecoder_DW.BareUnitDelay_DSTATE_c <= ((uint16_T)
                0U)) {
      /* Switch: '<S98>/Switch' incorporates:
       *  Constant: '<S98>/Constant4'
       *  Switch: '<S98>/Switch1'
       */
      SigResolverAngleDecoder_DW.Memory_PreviousInput_a = false;
    }

    /* End of Switch: '<S98>/Switch' */

    /* Gain: '<S65>/Gain2' incorporates:
     *  DataTypeConversion: '<S98>/Data Type Conversion EveSt2'
     */
    rtb_Gain2 = (uint8_T)(((uint32_T)((uint8_T)128U) *
      SigResolverAngleDecoder_DW.Memory_PreviousInput_a) >> 4);

    /* MinMax: '<S65>/Max' incorporates:
     *  DataTypeConversion: '<S65>/Data Type Conversion'
     *  DataTypeConversion: '<S86>/Data Type Conversion EveSt2'
     *  UnitDelay: '<S65>/Unit Delay'
     */
    if ((int32_T)SigResolverAngleDecoder_DW.Memory_PreviousInput >=
        SigResolverAngleDecoder_DW.UnitDelay_DSTATE_o[0]) {
      SigResolverAngleDecoder_DW.UnitDelay_DSTATE_o[0] =
        SigResolverAngleDecoder_DW.Memory_PreviousInput;
    }

    if (rtb_Gain >= SigResolverAngleDecoder_DW.UnitDelay_DSTATE_o[1]) {
      SigResolverAngleDecoder_DW.UnitDelay_DSTATE_o[1] = rtb_Gain;
    }

    if (rtb_Gain1 >= SigResolverAngleDecoder_DW.UnitDelay_DSTATE_o[2]) {
      SigResolverAngleDecoder_DW.UnitDelay_DSTATE_o[2] = rtb_Gain1;
    }

    if (rtb_Gain2 >= SigResolverAngleDecoder_DW.UnitDelay_DSTATE_o[3]) {
      SigResolverAngleDecoder_DW.UnitDelay_DSTATE_o[3] = rtb_Gain2;
    }

    /* End of MinMax: '<S65>/Max' */

    /* Sum: '<S65>/Add1' incorporates:
     *  DataStoreWrite: '<S88>/Data Store Write'
     *  UnitDelay: '<S65>/Unit Delay'
     */
    tmp_0 = (int32_T)((((uint32_T)SigResolverAngleDecoder_DW.UnitDelay_DSTATE_o
                        [0] + SigResolverAngleDecoder_DW.UnitDelay_DSTATE_o[1])
                       + SigResolverAngleDecoder_DW.UnitDelay_DSTATE_o[2]) +
                      SigResolverAngleDecoder_DW.UnitDelay_DSTATE_o[3]);
    if ((uint32_T)tmp_0 > 255U) {
      tmp_0 = 255;
    }

    SGRD_ResolverErrLatched = (uint8_T)tmp_0;

    /* End of Sum: '<S65>/Add1' */

    /* Sum: '<S65>/Add' incorporates:
     *  DataTypeConversion: '<S86>/Data Type Conversion EveSt2'
     */
    SGRD_ResolverErr = (uint8_T)((((uint32_T)
      SigResolverAngleDecoder_DW.Memory_PreviousInput + rtb_Gain) + rtb_Gain1) +
      rtb_Gain2);

    /* SignalConversion generated from: '<S61>/SGRD_ResolverErr_IRV' */
    SGRD_ResolverErr_IRV = SGRD_ResolverErr;
  }

  /* End of RelationalOperator: '<S62>/Relational Operator' */
  /* End of Outputs for SubSystem: '<S60>/Diag' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SGRD_DiagResolverFault_1ms' */
}

/* Model initialize function */
void SigResolverAngleDecoder_initialize(void)
{
  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SGRD_DiagResolverFault_1ms' incorporates:
   *  SubSystem: '<Root>/SGRD_DiagResolverFault_1ms_sys'
   */
  /* SystemInitialize for Enabled SubSystem: '<S60>/Diag' */
  /* SystemInitialize for SignalConversion generated from: '<S61>/SGRD_ResolverErr_IRV' incorporates:
   *  Outport: '<S61>/SGRD_ResolverErr_IRV'
   */
  SGRD_ResolverErr_IRV = ((uint8_T)0U);

  /* End of SystemInitialize for SubSystem: '<S60>/Diag' */
  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SGRD_DiagResolverFault_1ms' */

  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SGRD_AngleObserver_96us' incorporates:
   *  SubSystem: '<Root>/SGRD_AngleObserver_96us_sys'
   */
  /* InitializeConditions for Delay: '<S12>/Delay' */
  SigResolverAngleDecoder_DW.icLoad = true;

  /* InitializeConditions for Delay: '<S12>/Delay1' */
  SigResolverAngleDecoder_DW.icLoad_h = true;

  /* InitializeConditions for Delay: '<S30>/Delay' */
  SigResolverAngleDecoder_DW.icLoad_j = true;

  /* InitializeConditions for Delay: '<S28>/Delay' */
  SigResolverAngleDecoder_DW.icLoad_p = true;

  /* InitializeConditions for Delay: '<S28>/Delay1' */
  SigResolverAngleDecoder_DW.icLoad_e = true;

  /* InitializeConditions for Delay: '<S24>/Delay' */
  SigResolverAngleDecoder_DW.icLoad_o = true;

  /* InitializeConditions for Delay: '<S21>/Delay' */
  SigResolverAngleDecoder_DW.icLoad_ee = true;

  /* InitializeConditions for Delay: '<S21>/Delay1' */
  SigResolverAngleDecoder_DW.icLoad_f = true;

  /* SystemInitialize for DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
   *  Outport: '<S1>/SGRD_SineRaw_IRV'
   */
  SGRD_SineRaw_IRV = 0.0F;

  /* SystemInitialize for Delay: '<S10>/Delay' incorporates:
   *  Outport: '<S1>/SGRD_SineRaw3Dly_IRV'
   */
  SGRD_SineRaw3Dly_IRV = 0.0F;

  /* SystemInitialize for Delay: '<S10>/Delay1' incorporates:
   *  Outport: '<S1>/SGRD_SineRaw6Dly_IRV'
   */
  SGRD_SineRaw6Dly_IRV = 0.0F;

  /* SystemInitialize for DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
   *  Outport: '<S1>/SGRD_CosRaw_IRV'
   */
  SGRD_CosRaw_IRV = 0.0F;

  /* SystemInitialize for Delay: '<S10>/Delay2' incorporates:
   *  Outport: '<S1>/SGRD_CosRaw3Dly_IRV'
   */
  SGRD_CosRaw3Dly_IRV = 0.0F;

  /* SystemInitialize for Delay: '<S10>/Delay3' incorporates:
   *  Outport: '<S1>/SGRD_CosRaw6Dly_IRV'
   */
  SGRD_CosRaw6Dly_IRV = 0.0F;

  /* SystemInitialize for Sum: '<S18>/Add' incorporates:
   *  Outport: '<S1>/SGRD_ObsrAngleDelta_IRV'
   */
  SGRD_ObsrAngleDelta_IRV = 0.0F;

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SGRD_AngleObserver_96us' */

  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SGRD_CalcElecAngle_100us' incorporates:
   *  SubSystem: '<Root>/SGRD_CalcElecAngle_100us_sys'
   */
  /* SystemInitialize for Switch: '<S2>/Switch2' incorporates:
   *  Outport: '<S2>/SGRD_ObsrSpeed_IRV'
   */
  SGRD_ObsrSpeed_IRV = 0.0F;

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SGRD_CalcElecAngle_100us' */
}
#define MTRCTRL_STOP_SEC_CODE_FLS_DEFAULT
#include "MtrCtrl_MemMap.h"
/* Model terminate function */
void SigResolverAngleDecoder_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

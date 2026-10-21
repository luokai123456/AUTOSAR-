/*
 * File: FltFaultDiagnoser.c
 *
 * Code generated for Simulink model 'FltFaultDiagnoser'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:38:06 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FltFaultDiagnoser.h"
#include <math.h>
#include "rtwtypes.h"
#include "FltFaultDiagnoser_private.h"

/* Exported data definition */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Par */
volatile uint16_T FLDG_DebounceDecrDcVoltHi_C = 1U;/* Referenced by: '<S109>/Constant' */

/* Debounce decrement value for diagnostic of DC overvoltage */
volatile uint8_T FLDG_DebounceDecrInvTMonitor_C = 1U;/* Referenced by: '<S74>/Constant' */

/* Debounce decrement value for diagnostic of IGBT overtemperature */
volatile uint8_T FLDG_DebounceDecrPhaCur_C = 1U;/* Referenced by: '<S11>/Constant' */

/* Debounce decrement value for diagnostic of phase overcurrent */
volatile uint8_T FLDG_DebounceDecrResolverSpdMonitor_C = 1U;/* Referenced by:
                                                             * '<S51>/Constant'
                                                             * '<S58>/Constant'
                                                             * '<S97>/Constant'
                                                             */

/* Debounce decrement value for diagnostic of overspeed from position sensor */
volatile uint8_T FLDG_DebounceDecrWindingTMonitor_C = 1U;/* Referenced by: '<S121>/Constant' */

/* Debounce decrement value for winding temperatue monitoring */
volatile uint16_T FLDG_DebounceIncrDcVoltHi_C = 1U;/* Referenced by: '<S108>/Constant' */

/* Debounce increment value for diagnostic of DC overvoltage */
volatile uint8_T FLDG_DebounceIncrInvTMonitor_C = 1U;/* Referenced by: '<S73>/Constant' */

/* Debounce increment value for diagnostic of IGBT overtemperature */
volatile uint8_T FLDG_DebounceIncrPhaCur_C = 1U;/* Referenced by: '<S10>/Constant' */

/* Debounce increment value for diagnostic of phase overcurrent */
volatile uint8_T FLDG_DebounceIncrResolverSpdMonitor_C = 1U;/* Referenced by:
                                                             * '<S50>/Constant'
                                                             * '<S57>/Constant'
                                                             * '<S96>/Constant'
                                                             */

/* Debounce increment value for diagnostic of overspeed from position sensor */
volatile uint8_T FLDG_DebounceIncrWindingTMonitor_C = 1U;/* Referenced by: '<S120>/Constant' */

/* Debounce increment value for winding temperature monitoring */
volatile uint16_T FLDG_DebounceMaxDcVoltHi_C = 10U;/* Referenced by: '<S106>/Constant' */

/* Debounce maximum value for diagnostic of DC overvoltage */
volatile uint8_T FLDG_DebounceMaxInvTMonitor_C = 30U;/* Referenced by: '<S71>/Constant' */

/* Debounce maximum value for diagnostic of IGBT overtemperature */
volatile uint8_T FLDG_DebounceMaxPhaCur_C = 5U;/* Referenced by: '<S8>/Constant' */

/* Debounce maximum value for diagnostic of phase overcurrent */
volatile uint8_T FLDG_DebounceMaxResolverSpdMonitor_C = 30U;/* Referenced by:
                                                             * '<S55>/Constant'
                                                             * '<S61>/Constant'
                                                             * '<S94>/Constant'
                                                             */

/* Debounce maximum value for diagnostic of overspeed from position sensor */
volatile uint8_T FLDG_DebounceMaxWindingTMonitor_C = 3U;/* Referenced by: '<S118>/Constant' */

/* Debounce maximum value for winding temperature monitoring */
volatile uint16_T FLDG_DebounceMinDcVoltHi_C = 0U;/* Referenced by: '<S107>/Constant' */

/* Debounce minimum value for diagnostic of DC overvoltage */
volatile uint8_T FLDG_DebounceMinInvTMonitor_C = 0U;/* Referenced by: '<S72>/Constant' */

/* Debounce minimum value for diagnostic of IGBT overtemperature */
volatile uint8_T FLDG_DebounceMinPhaCur_C = 0U;/* Referenced by: '<S9>/Constant' */

/* Debounce minimum value for diagnostic of phase overcurrent */
volatile uint8_T FLDG_DebounceMinResolverSpdMonitor_C = 0U;/* Referenced by:
                                                            * '<S49>/Constant'
                                                            * '<S56>/Constant'
                                                            * '<S95>/Constant'
                                                            */

/* Debounce minimum value for diagnostic of overspeed from position sensor */
volatile uint8_T FLDG_DebounceMinWindingTMonitor_C = 0U;/* Referenced by: '<S119>/Constant' */

/* Debounce minimum value for winding temperature monitoring */
volatile uint8_T FLDG_EnableDiagHwDcLinkVoltDiag_C = 1U;/* Referenced by: '<S36>/Constant' */

/* Enable flag for hardware monitor DC link voltage diagnostic */
volatile uint8_T FLDG_EnableDiagHwErrPhaCurDiag_C = 1U;/* Referenced by: '<S38>/Constant' */

/* Enable flag for hardware monitor phase current diagnostic */
volatile uint8_T FLDG_EnableDiagHwFltHiSideB_C = 1U;/* Referenced by: '<S40>/Constant' */

/* Enable flag for hardware monitor DC fault B HS diagnostic */
volatile uint8_T FLDG_EnableDiagHwFltLoSideB_C = 1U;/* Referenced by: '<S42>/Constant' */

/* Enable flag for hardware monitor DC fault B LS diagnostic */
volatile uint8_T FLDG_EnableDiagResolverCosLosDiag_C = 1U;/* Referenced by: '<S86>/Constant' */

/* Enable flag for Resolver diagnostic of tracking */
volatile uint8_T FLDG_EnableDiagResolverDiagDos_C = 1U;/* Referenced by: '<S82>/Constant' */

/* Enable flag for Resolver diagnostic of phase lock range error */
volatile uint8_T FLDG_EnableDiagResolverDiagSigLot_C = 1U;/* Referenced by: '<S88>/Constant' */

/* Enable flag for Resolver diagnostic of LOS (loss of signal)  threshold */
volatile uint8_T FLDG_EnableDiagResolverSineLosDiag_C = 1U;/* Referenced by: '<S84>/Constant' */

/* Enable flag for Resolver diagnostic of velocity tracking rate */
volatile uint8_T FLDG_EnableShutdownReq_C = 1U;/* Referenced by:
                                                * '<S26>/Constant'
                                                * '<S28>/Constant'
                                                * '<S30>/Constant'
                                                */

/* Enable flag for shutdown request function */
volatile real32_T FLDG_IHiThr_C = 280.0F;/* Referenced by: '<S6>/Constant' */

/* Max permissible current */
volatile uint8_T FLDG_ResetDcDiagUHi_C = 0U;/* Referenced by: '<S105>/Constant' */

/* Reset for diagnostic of DC Link overvoltage */
volatile uint8_T FLDG_ResetDiagPhaCur_C = 0U;/* Referenced by: '<S7>/Constant' */

/* Reset for diagnostic of phase current */
volatile uint8_T FLDG_ResetInvTMonitor_C = 0U;/* Referenced by: '<S70>/Constant' */

/* Rst for Temperature monitoring of Inverter */
volatile uint8_T FLDG_ResetLatchDcVoltHi_C = 0U;/* Referenced by: '<S110>/Constant' */

/* Fault detection flag */
volatile uint8_T FLDG_ResetLatchHwDcLinkVolt_C = 0U;/* Referenced by: '<S37>/Constant' */

/* clear to enable latching. */
volatile uint8_T FLDG_ResetLatchHwFltLoSideB_C = 0U;/* Referenced by:
                                                     * '<S41>/Constant'
                                                     * '<S43>/Constant'
                                                     */

/* clear to enable latching. */
volatile uint8_T FLDG_ResetLatchHwPhaCur_C = 0U;/* Referenced by: '<S39>/Constant' */

/* clear to enable latching. */
volatile uint8_T FLDG_ResetLatchResolverCosLos_C = 0U;/* Referenced by: '<S87>/Constant' */

/* clear to enable latching. */
volatile uint8_T FLDG_ResetLatchResolverDos_C = 0U;/* Referenced by: '<S83>/Constant' */

/* clear to enable latching. */
volatile uint8_T FLDG_ResetLatchResolverSigLot_C = 0U;/* Referenced by: '<S89>/Constant' */

/* clear to enable latching. */
volatile uint8_T FLDG_ResetLatchResolverSineLos_C = 0U;/* Referenced by: '<S85>/Constant' */

/* clear to enable latching. */
volatile uint8_T FLDG_ResetLatchShutdownReq_C = 1U;/* Referenced by:
                                                    * '<S27>/Constant'
                                                    * '<S29>/Constant'
                                                    * '<S31>/Constant'
                                                    */

/* Reset control for shutdown request latched error functionality */
volatile uint8_T FLDG_ResetResolverNMonitor_C = 0U;/* Referenced by:
                                                    * '<S54>/Constant'
                                                    * '<S59>/Constant'
                                                    * '<S93>/Constant'
                                                    */

/* Reset for speed monitoring from position sensor */
volatile uint8_T FLDG_ResetWindingTMonitor_C = 0U;/* Referenced by: '<S117>/Constant' */

/* Reset for Temperature monitoring of Winding */
volatile real32_T FLDG_SpdResolverThrFaiRcvrr_C = 2400.0F;/* Referenced by: '<S98>/Constant' */

/* over speed recovery Threshold */
volatile real32_T FLDG_SpdResolverThrFai_C = 2500.0F;/* Referenced by: '<S92>/Constant' */

/* Threshold speed from position sensor above which the machine should be shut down */
volatile real32_T FLDG_TIgbtPha1Thr_C = 60.0F;/* Referenced by: '<S69>/Constant' */

/* Threshold value for power switch temperature at phase A */
volatile real32_T FLDG_TWindingThr_C = 90.0F;/* Referenced by: '<S116>/Constant' */

/* Winding temp above which error is set to 1 */
volatile real32_T FLDG_UBattVoltThrHiRcvrr_C = 15.5F;/* Referenced by: '<S53>/Constant' */

/* OVER voltage RECOVERY threshold of battery voltage */
volatile real32_T FLDG_UBattVoltThrHi_C = 16.0F;/* Referenced by: '<S52>/Constant' */

/* OVER voltage threshold of battery voltage */
volatile real32_T FLDG_UBattVoltThrLoRcvrr_C = 9.0F;/* Referenced by: '<S48>/Constant' */

/* UNDER voltage recovery threshold of battery voltage */
volatile real32_T FLDG_UBattVoltThrLo_C = 8.5F;/* Referenced by: '<S60>/Constant' */

/* Voltage at battery voltage below which a DEM error entry is set */
volatile real32_T FLDG_UDcThrHi_C = 360.0F;/* Referenced by: '<S104>/Constant' */

/* DC voltage above which error is set to 1 */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Sig */
uint8_T FLDG_ActiveShortHsReq;         /* '<S25>/Switch XOR' */

/* Active short circuit request for high-side switches */
uint8_T FLDG_BattVoltHiErr;            /* '<S66>/Data Type Conversion EveSt2' */

/* Fault detection active when the voltage at battery voltage is above a threshold value */
uint8_T FLDG_BattVoltLoErr;            /* '<S63>/Data Type Conversion EveSt2' */

/* Fault detection active when the voltage at battery voltage is below a threshold value */
uint8_T FLDG_DcVoltHiWarn;             /* '<S103>/Switch XOR' */

/* Warning flag is set when DC bus voltage is above the critical value */
uint8_T FLDG_DischargeErr;             /* '<S2>/CTSO_DischargeFaultFlag' */

/* Discharge Error */
uint8_T FLDG_HwDcLinkVoltErr;          /* '<S32>/Switch XOR' */

/* Scanned errors of hardware monitor Bit 9: DC link overvoltage */
uint8_T FLDG_HwHsShortErr;             /* '<S34>/Switch XOR' */

/* Scanned errors of hardware monitor Bit 11: Fault B HS */
uint8_T FLDG_HwLsShortErr;             /* '<S35>/Switch XOR' */

/* Scanned errors of hardware monitor Bit 14: Fault B LS */
uint8_T FLDG_HwPhaCurErr;              /* '<S33>/Switch XOR' */

/* hardware monitor Phase Current Error */
uint8_T FLDG_IgbtTemp1Err;             /* '<S18>/Signal Conversion' */

/* Fault detection active when power switch at phase A temperature above threshold value */
uint8_T FLDG_IgbtTemp2Err;             /* '<S18>/Signal Conversion1' */

/* Fault detection active when power switch at phase B temperature above threshold value */
uint8_T FLDG_IgbtTemp3Err;             /* '<S18>/Signal Conversion2' */

/* Fault detection active when power switch at phase C temperature above threshold value */
uint8_T FLDG_PhaCur1Err;               /* '<S4>/Signal Conversion' */

/* Fault indicator active when maximum allowable current at phase A is  exceeds limit */
uint8_T FLDG_PhaCur1Err_IRV;           /* '<S1>/OverCurrentDiag' */

/* Fault indicator active when maximum allowable current at phase A is  exceeds limit */
uint8_T FLDG_PhaCur2Err;               /* '<S4>/Signal Conversion1' */

/* Fault indicator active when maximum allowable current exceeds limit at phase B */
uint8_T FLDG_PhaCur2Err_IRV;           /* '<S1>/OverCurrentDiag' */

/* Fault indicator active when maximum allowable current exceeds limit at phase B */
uint8_T FLDG_PhaCur3Err;               /* '<S4>/Signal Conversion2' */

/* Fault indicator active when maximum allowable current exceeds limit at phase C */
uint8_T FLDG_PhaCur3Err_IRV;           /* '<S1>/OverCurrentDiag' */

/* Fault indicator active when maximum allowable current exceeds limit at phase C */
uint8_T FLDG_PowerSwitchOffReq;        /* '<S24>/Switch XOR' */

/* Error reaction request for power switches off (freewheeling mode) */
uint8_T FLDG_ResolverCosLosErr;        /* '<S80>/Switch XOR' */

/* Scanned errors of Resolver Bit 3: tracking error exceeds LOT (Loss of tracking) threshold */
uint8_T FLDG_ResolverDosErr;           /* '<S78>/Switch XOR' */

/* Scanned errors of Resolver Bit 1: phase error exceeds phase lock range */
uint8_T FLDG_ResolverError;            /* '<S19>/Data Type Conversion4' */

/* Resolver Error */
uint8_T FLDG_ResolverSigLotErr;        /* '<S81>/Switch XOR' */

/* Scanned errors of Resolver Bit 6: sin/cos below LOS (loss of signa)l threshold */
uint8_T FLDG_ResolverSineLosErr;       /* '<S79>/Switch XOR' */

/* Scanned errors of Resolver Bit 2: velocity exceeds maximum tracking rate */
uint8_T FLDG_ResolverSpdErr;          /* '<S100>/Data Type Conversion EveSt2' */

/* When the absolut value of measured rotor speed exceeds the maximum threshold value, this flag is set to one */
uint8_T FLDG_ShutdownReq;              /* '<S23>/Switch XOR' */

/* System shutdown request flag indicator */
uint8_T FLDG_WindingTempErr;          /* '<S123>/Data Type Conversion EveSt2' */

/* Fault detection active when motor winding temperature above threshold value */
uint8_T FLDG_WindingTempErr_IRV;       /* '<S3>/MotorTemperatureDiag' */

/* Fault detection active when motor winding temperature above threshold value */
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Block states (default storage) */
DW_FltFaultDiagnoser_T FltFaultDiagnoser_DW;

/* Real-time model */
static RT_MODEL_FltFaultDiagnoser_T FltFaultDiagnoser_M_;
RT_MODEL_FltFaultDiagnoser_T *const FltFaultDiagnoser_M = &FltFaultDiagnoser_M_;

/* Model step function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void FLDG_DiagCurrentFast_100us(void)
{
  int32_T tmp;
  int32_T tmp_0;
  uint8_T rtb_MultiportSwitch_h_idx_0;
  uint8_T rtb_MultiportSwitch_h_idx_1;
  uint8_T rtb_MultiportSwitch_h_idx_2;

  /* RootInportFunctionCallGenerator generated from: '<Root>/FLDG_DiagCurrentFast_100us' incorporates:
   *  SubSystem: '<Root>/FLDG_DiagCurrentFast_100us_sys'
   */
  /* Sum: '<S5>/Add' incorporates:
   *  Constant: '<S11>/Constant'
   *  UnitDelay: '<S14>/Bare Unit Delay'
   */
  tmp_0 = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[0] -
    FLDG_DebounceDecrPhaCur_C;
  if (tmp_0 < 0) {
    tmp_0 = 0;
  }

  /* MinMax: '<S5>/Max' incorporates:
   *  UnitDelay: '<S14>/Bare Unit Delay'
   */
  if (((uint8_T)0U) >= FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[0]) {
    rtb_MultiportSwitch_h_idx_2 = ((uint8_T)0U);
  } else {
    rtb_MultiportSwitch_h_idx_2 = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[0];
  }

  /* Sum: '<S5>/Add1' incorporates:
   *  Constant: '<S10>/Constant'
   *  MinMax: '<S5>/Max'
   */
  tmp = (int32_T)((uint32_T)rtb_MultiportSwitch_h_idx_2 +
                  FLDG_DebounceIncrPhaCur_C);
  if ((uint32_T)tmp > 255U) {
    tmp = 255;
  }

  /* MultiPortSwitch: '<S5>/Multiport Switch' incorporates:
   *  Abs: '<S4>/Abs'
   *  Constant: '<S6>/Constant'
   *  Inport: '<Root>/SGPP_PhaseACurrent'
   *  RelationalOperator: '<S4>/Relational Operator'
   *  Sum: '<S5>/Add'
   *  Sum: '<S5>/Add1'
   */
  if (!((real32_T)fabs(SGPP_PhaseACurrent) > FLDG_IHiThr_C)) {
    rtb_MultiportSwitch_h_idx_0 = (uint8_T)tmp_0;
  } else {
    rtb_MultiportSwitch_h_idx_0 = (uint8_T)tmp;
  }

  /* Sum: '<S5>/Add' incorporates:
   *  Constant: '<S11>/Constant'
   *  UnitDelay: '<S14>/Bare Unit Delay'
   */
  tmp_0 = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[1] -
    FLDG_DebounceDecrPhaCur_C;
  if (tmp_0 < 0) {
    tmp_0 = 0;
  }

  /* MinMax: '<S5>/Max' incorporates:
   *  UnitDelay: '<S14>/Bare Unit Delay'
   */
  if (((uint8_T)0U) >= FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[1]) {
    rtb_MultiportSwitch_h_idx_2 = ((uint8_T)0U);
  } else {
    rtb_MultiportSwitch_h_idx_2 = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[1];
  }

  /* Sum: '<S5>/Add1' incorporates:
   *  Constant: '<S10>/Constant'
   *  MinMax: '<S5>/Max'
   */
  tmp = (int32_T)((uint32_T)rtb_MultiportSwitch_h_idx_2 +
                  FLDG_DebounceIncrPhaCur_C);
  if ((uint32_T)tmp > 255U) {
    tmp = 255;
  }

  /* MultiPortSwitch: '<S5>/Multiport Switch' incorporates:
   *  Abs: '<S4>/Abs'
   *  Constant: '<S6>/Constant'
   *  Inport: '<Root>/SGPP_PhaseBCurrent'
   *  RelationalOperator: '<S4>/Relational Operator'
   *  Sum: '<S5>/Add'
   *  Sum: '<S5>/Add1'
   */
  if (!((real32_T)fabs(SGPP_PhaseBCurrent) > FLDG_IHiThr_C)) {
    rtb_MultiportSwitch_h_idx_1 = (uint8_T)tmp_0;
  } else {
    rtb_MultiportSwitch_h_idx_1 = (uint8_T)tmp;
  }

  /* Sum: '<S5>/Add' incorporates:
   *  Constant: '<S11>/Constant'
   *  UnitDelay: '<S14>/Bare Unit Delay'
   */
  tmp_0 = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[2] -
    FLDG_DebounceDecrPhaCur_C;
  if (tmp_0 < 0) {
    tmp_0 = 0;
  }

  /* MinMax: '<S5>/Max' incorporates:
   *  UnitDelay: '<S14>/Bare Unit Delay'
   */
  if (((uint8_T)0U) >= FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[2]) {
    rtb_MultiportSwitch_h_idx_2 = ((uint8_T)0U);
  } else {
    rtb_MultiportSwitch_h_idx_2 = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[2];
  }

  /* Sum: '<S5>/Add1' incorporates:
   *  Constant: '<S10>/Constant'
   *  MinMax: '<S5>/Max'
   */
  tmp = (int32_T)((uint32_T)rtb_MultiportSwitch_h_idx_2 +
                  FLDG_DebounceIncrPhaCur_C);
  if ((uint32_T)tmp > 255U) {
    tmp = 255;
  }

  /* MultiPortSwitch: '<S5>/Multiport Switch' incorporates:
   *  Abs: '<S4>/Abs'
   *  Constant: '<S6>/Constant'
   *  Inport: '<Root>/SGPP_PhaseCCurrent'
   *  RelationalOperator: '<S4>/Relational Operator'
   *  Sum: '<S5>/Add'
   *  Sum: '<S5>/Add1'
   */
  if (!((real32_T)fabs(SGPP_PhaseCCurrent) > FLDG_IHiThr_C)) {
    rtb_MultiportSwitch_h_idx_2 = (uint8_T)tmp_0;
  } else {
    rtb_MultiportSwitch_h_idx_2 = (uint8_T)tmp;
  }

  /* Sum: '<S5>/Add2' incorporates:
   *  Constant: '<S5>/0 Constant4'
   *  Constant: '<S8>/Constant'
   */
  tmp_0 = (int32_T)((uint32_T)FLDG_DebounceMaxPhaCur_C + ((uint8_T)1U));
  if ((uint32_T)tmp_0 > 255U) {
    tmp_0 = 255;
  }

  /* Switch: '<S14>/Enable' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Constant: '<S7>/Constant'
   *  Logic: '<S14>/Logical Operator1'
   *  Logic: '<S14>/Logical Operator2'
   *  Switch: '<S14>/Reset'
   */
  if ((FLDG_ResetDiagPhaCur_C == 0) && true) {
    /* Switch: '<S12>/Switch2' incorporates:
     *  Constant: '<S5>/0 Constant1'
     *  RelationalOperator: '<S12>/LowerRelop1'
     *  RelationalOperator: '<S12>/UpperRelop'
     *  Sum: '<S5>/Add2'
     *  Switch: '<S12>/Switch'
     *  UnitDelay: '<S14>/Bare Unit Delay'
     */
    if (rtb_MultiportSwitch_h_idx_0 > (uint8_T)tmp_0) {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[0] = (uint8_T)tmp_0;
    } else if (rtb_MultiportSwitch_h_idx_0 < ((uint8_T)0U)) {
      /* Switch: '<S12>/Switch' incorporates:
       *  Constant: '<S5>/0 Constant1'
       *  UnitDelay: '<S14>/Bare Unit Delay'
       */
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[0] = ((uint8_T)0U);
    } else {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[0] =
        rtb_MultiportSwitch_h_idx_0;
    }

    if (rtb_MultiportSwitch_h_idx_1 > (uint8_T)tmp_0) {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[1] = (uint8_T)tmp_0;
    } else if (rtb_MultiportSwitch_h_idx_1 < ((uint8_T)0U)) {
      /* Switch: '<S12>/Switch' incorporates:
       *  Constant: '<S5>/0 Constant1'
       *  UnitDelay: '<S14>/Bare Unit Delay'
       */
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[1] = ((uint8_T)0U);
    } else {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[1] =
        rtb_MultiportSwitch_h_idx_1;
    }

    if (rtb_MultiportSwitch_h_idx_2 > (uint8_T)tmp_0) {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[2] = (uint8_T)tmp_0;
    } else if (rtb_MultiportSwitch_h_idx_2 < ((uint8_T)0U)) {
      /* Switch: '<S12>/Switch' incorporates:
       *  Constant: '<S5>/0 Constant1'
       *  UnitDelay: '<S14>/Bare Unit Delay'
       */
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[2] = ((uint8_T)0U);
    } else {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[2] =
        rtb_MultiportSwitch_h_idx_2;
    }

    /* End of Switch: '<S12>/Switch2' */
  } else if (FLDG_ResetDiagPhaCur_C != 0) {
    /* Switch: '<S14>/Reset' incorporates:
     *  Constant: '<S14>/iv'
     *  UnitDelay: '<S14>/Bare Unit Delay'
     */
    FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[0] = ((uint8_T)0U);
    FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[1] = ((uint8_T)0U);
    FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[2] = ((uint8_T)0U);
  }

  /* End of Switch: '<S14>/Enable' */

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S5>/Relational Operator'
   *  RelationalOperator: '<S5>/Relational Operator1'
   *  Sum: '<S5>/Add2'
   *  Switch: '<S13>/Switch1'
   *  UnitDelay: '<S14>/Bare Unit Delay'
   */
  if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[0] >= (uint8_T)tmp_0) {
    FltFaultDiagnoser_DW.Memory_PreviousInput_nc[0] = true;
  } else if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[0] <=
             FLDG_DebounceMinPhaCur_C) {
    /* Switch: '<S13>/Switch1' incorporates:
     *  Constant: '<S13>/Constant4'
     */
    FltFaultDiagnoser_DW.Memory_PreviousInput_nc[0] = false;
  }

  if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[1] >= (uint8_T)tmp_0) {
    FltFaultDiagnoser_DW.Memory_PreviousInput_nc[1] = true;
  } else if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[1] <=
             FLDG_DebounceMinPhaCur_C) {
    /* Switch: '<S13>/Switch1' incorporates:
     *  Constant: '<S13>/Constant4'
     */
    FltFaultDiagnoser_DW.Memory_PreviousInput_nc[1] = false;
  }

  if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[2] >= (uint8_T)tmp_0) {
    FltFaultDiagnoser_DW.Memory_PreviousInput_nc[2] = true;
  } else if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_p[2] <=
             FLDG_DebounceMinPhaCur_C) {
    /* Switch: '<S13>/Switch1' incorporates:
     *  Constant: '<S13>/Constant4'
     */
    FltFaultDiagnoser_DW.Memory_PreviousInput_nc[2] = false;
  }

  /* End of Switch: '<S13>/Switch' */

  /* SignalConversion: '<S4>/Signal Conversion' incorporates:
   *  DataTypeConversion: '<S13>/Data Type Conversion EveSt2'
   */
  FLDG_PhaCur1Err = (uint8_T)FltFaultDiagnoser_DW.Memory_PreviousInput_nc[0];

  /* SignalConversion generated from: '<S1>/FLDG_PhaCur1Err_IRV' */
  FLDG_PhaCur1Err_IRV = FLDG_PhaCur1Err;

  /* SignalConversion: '<S4>/Signal Conversion1' incorporates:
   *  DataTypeConversion: '<S13>/Data Type Conversion EveSt2'
   */
  FLDG_PhaCur2Err = (uint8_T)FltFaultDiagnoser_DW.Memory_PreviousInput_nc[1];

  /* SignalConversion generated from: '<S1>/FLDG_PhaCur2Err_IRV' */
  FLDG_PhaCur2Err_IRV = FLDG_PhaCur2Err;

  /* SignalConversion: '<S4>/Signal Conversion2' incorporates:
   *  DataTypeConversion: '<S13>/Data Type Conversion EveSt2'
   */
  FLDG_PhaCur3Err = (uint8_T)FltFaultDiagnoser_DW.Memory_PreviousInput_nc[2];

  /* SignalConversion generated from: '<S1>/FLDG_PhaCur3Err_IRV' */
  FLDG_PhaCur3Err_IRV = FLDG_PhaCur3Err;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/FLDG_DiagCurrentFast_100us' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model step function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void FLDG_DiagFaultResponse_1ms(void)
{
  int32_T rtb_DataTypeConversion1;
  int32_T rtb_DataTypeConversion1_h2;
  int32_T tmp_1;
  uint32_T tmp;
  uint32_T tmp_0;
  uint16_T rtb_MultiportSwitch;
  uint8_T rtb_MultiportSwitch_d_idx_0;
  uint8_T rtb_MultiportSwitch_d_idx_1;
  uint8_T rtb_MultiportSwitch_d_idx_2;

  /* RootInportFunctionCallGenerator generated from: '<Root>/FLDG_DiagFaultResponse_1ms' incorporates:
   *  SubSystem: '<Root>/FLDG_DiagFaultResponse_1ms_sys'
   */
  /* Sum: '<S68>/Add' incorporates:
   *  Constant: '<S74>/Constant'
   *  UnitDelay: '<S77>/Bare Unit Delay'
   */
  rtb_DataTypeConversion1 = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[0] -
    FLDG_DebounceDecrInvTMonitor_C;
  if (rtb_DataTypeConversion1 < 0) {
    rtb_DataTypeConversion1 = 0;
  }

  /* MinMax: '<S68>/Max' incorporates:
   *  UnitDelay: '<S77>/Bare Unit Delay'
   */
  if (((uint8_T)0U) >= FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[0]) {
    rtb_MultiportSwitch_d_idx_2 = ((uint8_T)0U);
  } else {
    rtb_MultiportSwitch_d_idx_2 = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[0];
  }

  /* Sum: '<S68>/Add1' incorporates:
   *  Constant: '<S73>/Constant'
   *  MinMax: '<S68>/Max'
   */
  rtb_DataTypeConversion1_h2 = (int32_T)((uint32_T)rtb_MultiportSwitch_d_idx_2 +
    FLDG_DebounceIncrInvTMonitor_C);
  if ((uint32_T)rtb_DataTypeConversion1_h2 > 255U) {
    rtb_DataTypeConversion1_h2 = 255;
  }

  /* MultiPortSwitch: '<S68>/Multiport Switch' incorporates:
   *  Constant: '<S69>/Constant'
   *  Inport: '<Root>/SGSA_PhaseASwitchTemp'
   *  RelationalOperator: '<S18>/Relational Operator'
   *  Sum: '<S68>/Add'
   *  Sum: '<S68>/Add1'
   */
  if (!(SGSA_PhaseASwitchTemp > FLDG_TIgbtPha1Thr_C)) {
    rtb_MultiportSwitch_d_idx_0 = (uint8_T)rtb_DataTypeConversion1;
  } else {
    rtb_MultiportSwitch_d_idx_0 = (uint8_T)rtb_DataTypeConversion1_h2;
  }

  /* Sum: '<S68>/Add' incorporates:
   *  Constant: '<S74>/Constant'
   *  UnitDelay: '<S77>/Bare Unit Delay'
   */
  rtb_DataTypeConversion1 = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[1] -
    FLDG_DebounceDecrInvTMonitor_C;
  if (rtb_DataTypeConversion1 < 0) {
    rtb_DataTypeConversion1 = 0;
  }

  /* MinMax: '<S68>/Max' incorporates:
   *  UnitDelay: '<S77>/Bare Unit Delay'
   */
  if (((uint8_T)0U) >= FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[1]) {
    rtb_MultiportSwitch_d_idx_2 = ((uint8_T)0U);
  } else {
    rtb_MultiportSwitch_d_idx_2 = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[1];
  }

  /* Sum: '<S68>/Add1' incorporates:
   *  Constant: '<S73>/Constant'
   *  MinMax: '<S68>/Max'
   */
  rtb_DataTypeConversion1_h2 = (int32_T)((uint32_T)rtb_MultiportSwitch_d_idx_2 +
    FLDG_DebounceIncrInvTMonitor_C);
  if ((uint32_T)rtb_DataTypeConversion1_h2 > 255U) {
    rtb_DataTypeConversion1_h2 = 255;
  }

  /* MultiPortSwitch: '<S68>/Multiport Switch' incorporates:
   *  Constant: '<S69>/Constant'
   *  Inport: '<Root>/SGSA_PhaseBSwitchTemp'
   *  RelationalOperator: '<S18>/Relational Operator'
   *  Sum: '<S68>/Add'
   *  Sum: '<S68>/Add1'
   */
  if (!(SGSA_PhaseBSwitchTemp > FLDG_TIgbtPha1Thr_C)) {
    rtb_MultiportSwitch_d_idx_1 = (uint8_T)rtb_DataTypeConversion1;
  } else {
    rtb_MultiportSwitch_d_idx_1 = (uint8_T)rtb_DataTypeConversion1_h2;
  }

  /* Sum: '<S68>/Add' incorporates:
   *  Constant: '<S74>/Constant'
   *  UnitDelay: '<S77>/Bare Unit Delay'
   */
  rtb_DataTypeConversion1 = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[2] -
    FLDG_DebounceDecrInvTMonitor_C;
  if (rtb_DataTypeConversion1 < 0) {
    rtb_DataTypeConversion1 = 0;
  }

  /* MinMax: '<S68>/Max' incorporates:
   *  UnitDelay: '<S77>/Bare Unit Delay'
   */
  if (((uint8_T)0U) >= FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[2]) {
    rtb_MultiportSwitch_d_idx_2 = ((uint8_T)0U);
  } else {
    rtb_MultiportSwitch_d_idx_2 = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[2];
  }

  /* Sum: '<S68>/Add1' incorporates:
   *  Constant: '<S73>/Constant'
   *  MinMax: '<S68>/Max'
   */
  rtb_DataTypeConversion1_h2 = (int32_T)((uint32_T)rtb_MultiportSwitch_d_idx_2 +
    FLDG_DebounceIncrInvTMonitor_C);
  if ((uint32_T)rtb_DataTypeConversion1_h2 > 255U) {
    rtb_DataTypeConversion1_h2 = 255;
  }

  /* MultiPortSwitch: '<S68>/Multiport Switch' incorporates:
   *  Constant: '<S69>/Constant'
   *  Inport: '<Root>/SGSA_PhaseCSwitchTemp'
   *  RelationalOperator: '<S18>/Relational Operator'
   *  Sum: '<S68>/Add'
   *  Sum: '<S68>/Add1'
   */
  if (!(SGSA_PhaseCSwitchTemp > FLDG_TIgbtPha1Thr_C)) {
    rtb_MultiportSwitch_d_idx_2 = (uint8_T)rtb_DataTypeConversion1;
  } else {
    rtb_MultiportSwitch_d_idx_2 = (uint8_T)rtb_DataTypeConversion1_h2;
  }

  /* Sum: '<S68>/Add2' incorporates:
   *  Constant: '<S68>/0 Constant4'
   *  Constant: '<S71>/Constant'
   */
  rtb_DataTypeConversion1 = (int32_T)((uint32_T)FLDG_DebounceMaxInvTMonitor_C +
    ((uint8_T)1U));
  if ((uint32_T)rtb_DataTypeConversion1 > 255U) {
    rtb_DataTypeConversion1 = 255;
  }

  /* Switch: '<S77>/Enable' incorporates:
   *  Constant: '<S68>/Constant2'
   *  Constant: '<S70>/Constant'
   *  Logic: '<S77>/Logical Operator1'
   *  Logic: '<S77>/Logical Operator2'
   *  Switch: '<S77>/Reset'
   */
  if ((FLDG_ResetInvTMonitor_C == 0) && true) {
    /* Switch: '<S75>/Switch2' incorporates:
     *  Constant: '<S68>/0 Constant1'
     *  RelationalOperator: '<S75>/LowerRelop1'
     *  RelationalOperator: '<S75>/UpperRelop'
     *  Sum: '<S68>/Add2'
     *  Switch: '<S75>/Switch'
     *  UnitDelay: '<S77>/Bare Unit Delay'
     */
    if (rtb_MultiportSwitch_d_idx_0 > (uint8_T)rtb_DataTypeConversion1) {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[0] = (uint8_T)
        rtb_DataTypeConversion1;
    } else if (rtb_MultiportSwitch_d_idx_0 < ((uint8_T)0U)) {
      /* Switch: '<S75>/Switch' incorporates:
       *  Constant: '<S68>/0 Constant1'
       *  UnitDelay: '<S77>/Bare Unit Delay'
       */
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[0] = ((uint8_T)0U);
    } else {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[0] =
        rtb_MultiportSwitch_d_idx_0;
    }

    if (rtb_MultiportSwitch_d_idx_1 > (uint8_T)rtb_DataTypeConversion1) {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[1] = (uint8_T)
        rtb_DataTypeConversion1;
    } else if (rtb_MultiportSwitch_d_idx_1 < ((uint8_T)0U)) {
      /* Switch: '<S75>/Switch' incorporates:
       *  Constant: '<S68>/0 Constant1'
       *  UnitDelay: '<S77>/Bare Unit Delay'
       */
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[1] = ((uint8_T)0U);
    } else {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[1] =
        rtb_MultiportSwitch_d_idx_1;
    }

    if (rtb_MultiportSwitch_d_idx_2 > (uint8_T)rtb_DataTypeConversion1) {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[2] = (uint8_T)
        rtb_DataTypeConversion1;
    } else if (rtb_MultiportSwitch_d_idx_2 < ((uint8_T)0U)) {
      /* Switch: '<S75>/Switch' incorporates:
       *  Constant: '<S68>/0 Constant1'
       *  UnitDelay: '<S77>/Bare Unit Delay'
       */
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[2] = ((uint8_T)0U);
    } else {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[2] =
        rtb_MultiportSwitch_d_idx_2;
    }

    /* End of Switch: '<S75>/Switch2' */
  } else if (FLDG_ResetInvTMonitor_C != 0) {
    /* Switch: '<S77>/Reset' incorporates:
     *  Constant: '<S77>/iv'
     *  UnitDelay: '<S77>/Bare Unit Delay'
     */
    FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[0] = ((uint8_T)0U);
    FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[1] = ((uint8_T)0U);
    FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[2] = ((uint8_T)0U);
  }

  /* End of Switch: '<S77>/Enable' */

  /* Switch: '<S76>/Switch' incorporates:
   *  Constant: '<S72>/Constant'
   *  Constant: '<S76>/Constant1'
   *  RelationalOperator: '<S68>/Relational Operator'
   *  RelationalOperator: '<S68>/Relational Operator1'
   *  Sum: '<S68>/Add2'
   *  Switch: '<S76>/Switch1'
   *  UnitDelay: '<S77>/Bare Unit Delay'
   */
  if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[0] >= (uint8_T)
      rtb_DataTypeConversion1) {
    FltFaultDiagnoser_DW.Memory_PreviousInput_i[0] = true;
  } else if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[0] <=
             FLDG_DebounceMinInvTMonitor_C) {
    /* Switch: '<S76>/Switch1' incorporates:
     *  Constant: '<S76>/Constant4'
     */
    FltFaultDiagnoser_DW.Memory_PreviousInput_i[0] = false;
  }

  if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[1] >= (uint8_T)
      rtb_DataTypeConversion1) {
    FltFaultDiagnoser_DW.Memory_PreviousInput_i[1] = true;
  } else if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[1] <=
             FLDG_DebounceMinInvTMonitor_C) {
    /* Switch: '<S76>/Switch1' incorporates:
     *  Constant: '<S76>/Constant4'
     */
    FltFaultDiagnoser_DW.Memory_PreviousInput_i[1] = false;
  }

  if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[2] >= (uint8_T)
      rtb_DataTypeConversion1) {
    FltFaultDiagnoser_DW.Memory_PreviousInput_i[2] = true;
  } else if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e[2] <=
             FLDG_DebounceMinInvTMonitor_C) {
    /* Switch: '<S76>/Switch1' incorporates:
     *  Constant: '<S76>/Constant4'
     */
    FltFaultDiagnoser_DW.Memory_PreviousInput_i[2] = false;
  }

  /* End of Switch: '<S76>/Switch' */

  /* SignalConversion: '<S18>/Signal Conversion' incorporates:
   *  DataTypeConversion: '<S76>/Data Type Conversion EveSt2'
   */
  FLDG_IgbtTemp1Err = (uint8_T)FltFaultDiagnoser_DW.Memory_PreviousInput_i[0];

  /* SignalConversion generated from: '<S2>/CTSO_DischargeFaultFlag' incorporates:
   *  Inport: '<Root>/CTSO_DischargeFaultFlag'
   */
  FLDG_DischargeErr = CTSO_DischargeFaultFlag;

  /* DataTypeConversion: '<S16>/Data Type Conversion1' incorporates:
   *  Constant: '<S38>/Constant'
   *  Inport: '<Root>/SGSA_HwOvercurSt'
   *  Logic: '<S16>/Logical Operator1'
   */
  rtb_DataTypeConversion1 = ((SGSA_HwOvercurSt != 0) &&
    (FLDG_EnableDiagHwErrPhaCurDiag_C != 0));

  /* Switch: '<S33>/Switch XOR' incorporates:
   *  Constant: '<S39>/Constant'
   *  Logic: '<S33>/XOR'
   *  Switch: '<S33>/Switch AND'
   */
  if ((boolean_T)((rtb_DataTypeConversion1 != 0) ^ (FLDG_ResetLatchHwPhaCur_C !=
        0))) {
    /* Switch: '<S33>/Switch XOR' incorporates:
     *  DataTypeConversion: '<S33>/Data Type Conversion1'
     */
    FLDG_HwPhaCurErr = (uint8_T)rtb_DataTypeConversion1;
  } else if (rtb_DataTypeConversion1 != 0) {
    /* Switch: '<S33>/Switch AND' incorporates:
     *  Constant: '<S33>/Constant'
     *  Switch: '<S33>/Switch XOR'
     */
    FLDG_HwPhaCurErr = ((uint8_T)1U);
  } else {
    /* Switch: '<S33>/Switch XOR' incorporates:
     *  UnitDelay: '<S33>/Unit Delay'
     */
    FLDG_HwPhaCurErr = FltFaultDiagnoser_DW.UnitDelay_DSTATE;
  }

  /* End of Switch: '<S33>/Switch XOR' */

  /* DataTypeConversion: '<S16>/Data Type Conversion2' incorporates:
   *  Constant: '<S40>/Constant'
   *  Inport: '<Root>/SGSA_HwHsIntBSt'
   *  Logic: '<S16>/Logical Operator2'
   */
  rtb_DataTypeConversion1 = ((SGSA_HwHsIntBSt != 0) &&
    (FLDG_EnableDiagHwFltHiSideB_C != 0));

  /* Switch: '<S34>/Switch XOR' incorporates:
   *  Constant: '<S41>/Constant'
   *  Logic: '<S34>/XOR'
   *  Switch: '<S34>/Switch AND'
   */
  if ((boolean_T)((rtb_DataTypeConversion1 != 0) ^
                  (FLDG_ResetLatchHwFltLoSideB_C != 0))) {
    /* Switch: '<S34>/Switch XOR' incorporates:
     *  DataTypeConversion: '<S34>/Data Type Conversion1'
     */
    FLDG_HwHsShortErr = (uint8_T)rtb_DataTypeConversion1;
  } else if (rtb_DataTypeConversion1 != 0) {
    /* Switch: '<S34>/Switch AND' incorporates:
     *  Constant: '<S34>/Constant'
     *  Switch: '<S34>/Switch XOR'
     */
    FLDG_HwHsShortErr = ((uint8_T)1U);
  } else {
    /* Switch: '<S34>/Switch XOR' incorporates:
     *  UnitDelay: '<S34>/Unit Delay'
     */
    FLDG_HwHsShortErr = FltFaultDiagnoser_DW.UnitDelay_DSTATE_o;
  }

  /* End of Switch: '<S34>/Switch XOR' */

  /* DataTypeConversion: '<S16>/Data Type Conversion3' incorporates:
   *  Constant: '<S42>/Constant'
   *  Inport: '<Root>/SGSA_HwLsIntBSt'
   *  Logic: '<S16>/Logical Operator3'
   */
  rtb_DataTypeConversion1 = ((SGSA_HwLsIntBSt != 0) &&
    (FLDG_EnableDiagHwFltLoSideB_C != 0));

  /* Switch: '<S35>/Switch XOR' incorporates:
   *  Constant: '<S43>/Constant'
   *  Logic: '<S35>/XOR'
   *  Switch: '<S35>/Switch AND'
   */
  if ((boolean_T)((rtb_DataTypeConversion1 != 0) ^
                  (FLDG_ResetLatchHwFltLoSideB_C != 0))) {
    /* Switch: '<S35>/Switch XOR' incorporates:
     *  DataTypeConversion: '<S35>/Data Type Conversion1'
     */
    FLDG_HwLsShortErr = (uint8_T)rtb_DataTypeConversion1;
  } else if (rtb_DataTypeConversion1 != 0) {
    /* Switch: '<S35>/Switch AND' incorporates:
     *  Constant: '<S35>/Constant'
     *  Switch: '<S35>/Switch XOR'
     */
    FLDG_HwLsShortErr = ((uint8_T)1U);
  } else {
    /* Switch: '<S35>/Switch XOR' incorporates:
     *  UnitDelay: '<S35>/Unit Delay'
     */
    FLDG_HwLsShortErr = FltFaultDiagnoser_DW.UnitDelay_DSTATE_a;
  }

  /* End of Switch: '<S35>/Switch XOR' */

  /* SignalConversion: '<S18>/Signal Conversion1' incorporates:
   *  DataTypeConversion: '<S76>/Data Type Conversion EveSt2'
   */
  FLDG_IgbtTemp2Err = (uint8_T)FltFaultDiagnoser_DW.Memory_PreviousInput_i[1];

  /* SignalConversion: '<S18>/Signal Conversion2' incorporates:
   *  DataTypeConversion: '<S76>/Data Type Conversion EveSt2'
   */
  FLDG_IgbtTemp3Err = (uint8_T)FltFaultDiagnoser_DW.Memory_PreviousInput_i[2];

  /* Sum: '<S44>/Add2' incorporates:
   *  Constant: '<S44>/0 Constant4'
   *  Constant: '<S55>/Constant'
   *  Sum: '<S45>/Add2'
   *  Sum: '<S90>/Add2'
   */
  rtb_DataTypeConversion1 = (int32_T)((uint32_T)
    FLDG_DebounceMaxResolverSpdMonitor_C + ((uint8_T)1U));
  rtb_DataTypeConversion1_h2 = rtb_DataTypeConversion1;
  if ((uint32_T)rtb_DataTypeConversion1 > 255U) {
    rtb_DataTypeConversion1_h2 = 255;
  }

  /* Switch: '<S46>/Switch' incorporates:
   *  Constant: '<S46>/Constant'
   *  Constant: '<S48>/Constant'
   *  Constant: '<S60>/Constant'
   *  Delay: '<S46>/Delay'
   *  Inport: '<Root>/SGSA_BatteryVolt'
   *  RelationalOperator: '<S46>/Relational Operator1'
   *  RelationalOperator: '<S46>/Relational Operator2'
   *  Switch: '<S46>/Switch1'
   */
  if (SGSA_BatteryVolt >= FLDG_UBattVoltThrLoRcvrr_C) {
    FltFaultDiagnoser_DW.Delay_DSTATE = true;
  } else if (SGSA_BatteryVolt < FLDG_UBattVoltThrLo_C) {
    /* Switch: '<S46>/Switch1' incorporates:
     *  Constant: '<S46>/Constant1'
     *  Delay: '<S46>/Delay'
     */
    FltFaultDiagnoser_DW.Delay_DSTATE = false;
  }

  /* End of Switch: '<S46>/Switch' */

  /* MultiPortSwitch: '<S44>/Multiport Switch' incorporates:
   *  Delay: '<S46>/Delay'
   *  Logic: '<S17>/Logical Operator'
   *  MinMax: '<S44>/Max'
   *  Sum: '<S44>/Add'
   *  Sum: '<S44>/Add1'
   */
  if (FltFaultDiagnoser_DW.Delay_DSTATE) {
    /* Sum: '<S44>/Add' incorporates:
     *  Constant: '<S58>/Constant'
     *  UnitDelay: '<S64>/Bare Unit Delay'
     */
    tmp_1 = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_d -
      FLDG_DebounceDecrResolverSpdMonitor_C;
    if (tmp_1 < 0) {
      tmp_1 = 0;
    }

    rtb_MultiportSwitch_d_idx_2 = (uint8_T)tmp_1;
  } else {
    if (((uint8_T)0U) >= FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_d) {
      /* MinMax: '<S44>/Max' */
      rtb_MultiportSwitch_d_idx_2 = ((uint8_T)0U);
    } else {
      /* MinMax: '<S44>/Max' */
      rtb_MultiportSwitch_d_idx_2 = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_d;
    }

    /* Sum: '<S44>/Add1' incorporates:
     *  Constant: '<S57>/Constant'
     *  MinMax: '<S44>/Max'
     */
    tmp_1 = (int32_T)((uint32_T)rtb_MultiportSwitch_d_idx_2 +
                      FLDG_DebounceIncrResolverSpdMonitor_C);
    if ((uint32_T)tmp_1 > 255U) {
      tmp_1 = 255;
    }

    rtb_MultiportSwitch_d_idx_2 = (uint8_T)tmp_1;
  }

  /* End of MultiPortSwitch: '<S44>/Multiport Switch' */

  /* Switch: '<S64>/Enable' incorporates:
   *  Constant: '<S44>/Constant2'
   *  Constant: '<S54>/Constant'
   *  Logic: '<S64>/Logical Operator1'
   *  Logic: '<S64>/Logical Operator2'
   *  Switch: '<S64>/Reset'
   */
  if ((FLDG_ResetResolverNMonitor_C == 0) && true) {
    /* Switch: '<S62>/Switch2' incorporates:
     *  Constant: '<S44>/0 Constant1'
     *  RelationalOperator: '<S62>/LowerRelop1'
     *  RelationalOperator: '<S62>/UpperRelop'
     *  Sum: '<S44>/Add2'
     *  Switch: '<S62>/Switch'
     *  UnitDelay: '<S64>/Bare Unit Delay'
     */
    if (rtb_MultiportSwitch_d_idx_2 > (uint8_T)rtb_DataTypeConversion1_h2) {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_d = (uint8_T)
        rtb_DataTypeConversion1_h2;
    } else if (rtb_MultiportSwitch_d_idx_2 < ((uint8_T)0U)) {
      /* Switch: '<S62>/Switch' incorporates:
       *  Constant: '<S44>/0 Constant1'
       *  UnitDelay: '<S64>/Bare Unit Delay'
       */
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_d = ((uint8_T)0U);
    } else {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_d = rtb_MultiportSwitch_d_idx_2;
    }

    /* End of Switch: '<S62>/Switch2' */
  } else if (FLDG_ResetResolverNMonitor_C != 0) {
    /* Switch: '<S64>/Reset' incorporates:
     *  Constant: '<S64>/iv'
     *  UnitDelay: '<S64>/Bare Unit Delay'
     */
    FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_d = ((uint8_T)0U);
  }

  /* End of Switch: '<S64>/Enable' */

  /* Switch: '<S63>/Switch' incorporates:
   *  Constant: '<S56>/Constant'
   *  RelationalOperator: '<S44>/Relational Operator'
   *  RelationalOperator: '<S44>/Relational Operator1'
   *  Sum: '<S44>/Add2'
   *  Switch: '<S63>/Switch1'
   *  UnitDelay: '<S64>/Bare Unit Delay'
   */
  if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_d >= (uint8_T)
      rtb_DataTypeConversion1_h2) {
    /* Switch: '<S63>/Switch' incorporates:
     *  Constant: '<S63>/Constant1'
     */
    FltFaultDiagnoser_DW.Memory_PreviousInput_n = true;
  } else if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_d <=
             FLDG_DebounceMinResolverSpdMonitor_C) {
    /* Switch: '<S63>/Switch' incorporates:
     *  Constant: '<S63>/Constant4'
     *  Switch: '<S63>/Switch1'
     */
    FltFaultDiagnoser_DW.Memory_PreviousInput_n = false;
  }

  /* End of Switch: '<S63>/Switch' */

  /* DataTypeConversion: '<S63>/Data Type Conversion EveSt2' */
  FLDG_BattVoltLoErr = (uint8_T)FltFaultDiagnoser_DW.Memory_PreviousInput_n;

  /* Sum: '<S45>/Add2' */
  rtb_DataTypeConversion1_h2 = rtb_DataTypeConversion1;
  if ((uint32_T)rtb_DataTypeConversion1 > 255U) {
    rtb_DataTypeConversion1_h2 = 255;
  }

  /* Switch: '<S47>/Switch' incorporates:
   *  Constant: '<S47>/Constant'
   *  Constant: '<S52>/Constant'
   *  Constant: '<S53>/Constant'
   *  Delay: '<S47>/Delay'
   *  Inport: '<Root>/SGSA_BatteryVolt'
   *  RelationalOperator: '<S47>/Relational Operator1'
   *  RelationalOperator: '<S47>/Relational Operator2'
   *  Switch: '<S47>/Switch1'
   */
  if (SGSA_BatteryVolt >= FLDG_UBattVoltThrHi_C) {
    FltFaultDiagnoser_DW.Delay_DSTATE_b = true;
  } else if (SGSA_BatteryVolt < FLDG_UBattVoltThrHiRcvrr_C) {
    /* Switch: '<S47>/Switch1' incorporates:
     *  Constant: '<S47>/Constant1'
     *  Delay: '<S47>/Delay'
     */
    FltFaultDiagnoser_DW.Delay_DSTATE_b = false;
  }

  /* End of Switch: '<S47>/Switch' */

  /* MultiPortSwitch: '<S45>/Multiport Switch' incorporates:
   *  Delay: '<S47>/Delay'
   *  MinMax: '<S45>/Max'
   *  Sum: '<S45>/Add'
   *  Sum: '<S45>/Add1'
   */
  if (!FltFaultDiagnoser_DW.Delay_DSTATE_b) {
    /* Sum: '<S45>/Add' incorporates:
     *  Constant: '<S51>/Constant'
     *  UnitDelay: '<S67>/Bare Unit Delay'
     */
    tmp_1 = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_o -
      FLDG_DebounceDecrResolverSpdMonitor_C;
    if (tmp_1 < 0) {
      tmp_1 = 0;
    }

    rtb_MultiportSwitch_d_idx_2 = (uint8_T)tmp_1;
  } else {
    if (((uint8_T)0U) >= FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_o) {
      /* MinMax: '<S45>/Max' */
      rtb_MultiportSwitch_d_idx_2 = ((uint8_T)0U);
    } else {
      /* MinMax: '<S45>/Max' */
      rtb_MultiportSwitch_d_idx_2 = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_o;
    }

    /* Sum: '<S45>/Add1' incorporates:
     *  Constant: '<S50>/Constant'
     *  MinMax: '<S45>/Max'
     */
    tmp_1 = (int32_T)((uint32_T)rtb_MultiportSwitch_d_idx_2 +
                      FLDG_DebounceIncrResolverSpdMonitor_C);
    if ((uint32_T)tmp_1 > 255U) {
      tmp_1 = 255;
    }

    rtb_MultiportSwitch_d_idx_2 = (uint8_T)tmp_1;
  }

  /* End of MultiPortSwitch: '<S45>/Multiport Switch' */

  /* Switch: '<S67>/Enable' incorporates:
   *  Constant: '<S45>/Constant2'
   *  Constant: '<S59>/Constant'
   *  Logic: '<S67>/Logical Operator1'
   *  Logic: '<S67>/Logical Operator2'
   *  Switch: '<S67>/Reset'
   */
  if ((FLDG_ResetResolverNMonitor_C == 0) && true) {
    /* Switch: '<S65>/Switch2' incorporates:
     *  Constant: '<S45>/0 Constant1'
     *  RelationalOperator: '<S65>/LowerRelop1'
     *  RelationalOperator: '<S65>/UpperRelop'
     *  Sum: '<S45>/Add2'
     *  Switch: '<S65>/Switch'
     *  UnitDelay: '<S67>/Bare Unit Delay'
     */
    if (rtb_MultiportSwitch_d_idx_2 > (uint8_T)rtb_DataTypeConversion1_h2) {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_o = (uint8_T)
        rtb_DataTypeConversion1_h2;
    } else if (rtb_MultiportSwitch_d_idx_2 < ((uint8_T)0U)) {
      /* Switch: '<S65>/Switch' incorporates:
       *  Constant: '<S45>/0 Constant1'
       *  UnitDelay: '<S67>/Bare Unit Delay'
       */
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_o = ((uint8_T)0U);
    } else {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_o = rtb_MultiportSwitch_d_idx_2;
    }

    /* End of Switch: '<S65>/Switch2' */
  } else if (FLDG_ResetResolverNMonitor_C != 0) {
    /* Switch: '<S67>/Reset' incorporates:
     *  Constant: '<S67>/iv'
     *  UnitDelay: '<S67>/Bare Unit Delay'
     */
    FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_o = ((uint8_T)0U);
  }

  /* End of Switch: '<S67>/Enable' */

  /* Switch: '<S66>/Switch' incorporates:
   *  Constant: '<S49>/Constant'
   *  RelationalOperator: '<S45>/Relational Operator'
   *  RelationalOperator: '<S45>/Relational Operator1'
   *  Sum: '<S45>/Add2'
   *  Switch: '<S66>/Switch1'
   *  UnitDelay: '<S67>/Bare Unit Delay'
   */
  if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_o >= (uint8_T)
      rtb_DataTypeConversion1_h2) {
    /* Switch: '<S66>/Switch' incorporates:
     *  Constant: '<S66>/Constant1'
     */
    FltFaultDiagnoser_DW.Memory_PreviousInput_k = true;
  } else if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_o <=
             FLDG_DebounceMinResolverSpdMonitor_C) {
    /* Switch: '<S66>/Switch' incorporates:
     *  Constant: '<S66>/Constant4'
     *  Switch: '<S66>/Switch1'
     */
    FltFaultDiagnoser_DW.Memory_PreviousInput_k = false;
  }

  /* End of Switch: '<S66>/Switch' */

  /* DataTypeConversion: '<S66>/Data Type Conversion EveSt2' */
  FLDG_BattVoltHiErr = (uint8_T)FltFaultDiagnoser_DW.Memory_PreviousInput_k;

  /* DataTypeConversion: '<S15>/Data Type Conversion1' incorporates:
   *  Constant: '<S28>/Constant'
   *  Logic: '<S15>/Logical Operator1'
   *  Logic: '<S15>/Logical Operator3'
   */
  rtb_DataTypeConversion1_h2 = (((FLDG_PhaCur1Err_IRV != 0) ||
    (FLDG_PhaCur2Err_IRV != 0) || (FLDG_PhaCur3Err_IRV != 0) ||
    (FLDG_HwPhaCurErr != 0) || (FLDG_HwHsShortErr != 0) || (FLDG_HwLsShortErr !=
    0) || (FLDG_IgbtTemp1Err != 0) || (FLDG_IgbtTemp2Err != 0) ||
    (FLDG_IgbtTemp3Err != 0) || (FLDG_WindingTempErr_IRV != 0) ||
    (FLDG_BattVoltLoErr != 0) || (FLDG_BattVoltHiErr != 0) || (FLDG_DischargeErr
    != 0)) && (FLDG_EnableShutdownReq_C != 0));

  /* Switch: '<S24>/Switch XOR' incorporates:
   *  Constant: '<S29>/Constant'
   *  Logic: '<S24>/XOR'
   *  Switch: '<S24>/Switch AND'
   */
  if ((boolean_T)((rtb_DataTypeConversion1_h2 != 0) ^
                  (FLDG_ResetLatchShutdownReq_C != 0))) {
    /* Switch: '<S24>/Switch XOR' incorporates:
     *  DataTypeConversion: '<S24>/Data Type Conversion1'
     */
    FLDG_PowerSwitchOffReq = (uint8_T)rtb_DataTypeConversion1_h2;
  } else if (rtb_DataTypeConversion1_h2 != 0) {
    /* Switch: '<S24>/Switch AND' incorporates:
     *  Constant: '<S24>/Constant'
     *  Switch: '<S24>/Switch XOR'
     */
    FLDG_PowerSwitchOffReq = ((uint8_T)1U);
  } else {
    /* Switch: '<S24>/Switch XOR' incorporates:
     *  UnitDelay: '<S24>/Unit Delay'
     */
    FLDG_PowerSwitchOffReq = FltFaultDiagnoser_DW.UnitDelay_DSTATE_k;
  }

  /* End of Switch: '<S24>/Switch XOR' */

  /* Sum: '<S90>/Add2' */
  if ((uint32_T)rtb_DataTypeConversion1 > 255U) {
    rtb_DataTypeConversion1 = 255;
  }

  /* Switch: '<S91>/Switch' incorporates:
   *  Constant: '<S91>/Constant'
   *  Constant: '<S92>/Constant'
   *  Constant: '<S98>/Constant'
   *  Delay: '<S91>/Delay'
   *  Inport: '<Root>/SGPP_MechSpeedAbsolute'
   *  RelationalOperator: '<S91>/Relational Operator1'
   *  RelationalOperator: '<S91>/Relational Operator2'
   *  Switch: '<S91>/Switch1'
   */
  if (SGPP_MechSpeedAbsolute >= FLDG_SpdResolverThrFai_C) {
    FltFaultDiagnoser_DW.Delay_DSTATE_i = true;
  } else if (SGPP_MechSpeedAbsolute < FLDG_SpdResolverThrFaiRcvrr_C) {
    /* Switch: '<S91>/Switch1' incorporates:
     *  Constant: '<S91>/Constant1'
     *  Delay: '<S91>/Delay'
     */
    FltFaultDiagnoser_DW.Delay_DSTATE_i = false;
  }

  /* End of Switch: '<S91>/Switch' */

  /* MultiPortSwitch: '<S90>/Multiport Switch' incorporates:
   *  Delay: '<S91>/Delay'
   *  MinMax: '<S90>/Max'
   *  Sum: '<S90>/Add'
   *  Sum: '<S90>/Add1'
   */
  if (!FltFaultDiagnoser_DW.Delay_DSTATE_i) {
    /* Sum: '<S90>/Add' incorporates:
     *  Constant: '<S97>/Constant'
     *  UnitDelay: '<S101>/Bare Unit Delay'
     */
    rtb_DataTypeConversion1_h2 = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e2 -
      FLDG_DebounceDecrResolverSpdMonitor_C;
    if (rtb_DataTypeConversion1_h2 < 0) {
      rtb_DataTypeConversion1_h2 = 0;
    }

    rtb_MultiportSwitch_d_idx_2 = (uint8_T)rtb_DataTypeConversion1_h2;
  } else {
    if (((uint8_T)0U) >= FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e2) {
      /* MinMax: '<S90>/Max' */
      rtb_MultiportSwitch_d_idx_2 = ((uint8_T)0U);
    } else {
      /* MinMax: '<S90>/Max' */
      rtb_MultiportSwitch_d_idx_2 = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e2;
    }

    /* Sum: '<S90>/Add1' incorporates:
     *  Constant: '<S96>/Constant'
     *  MinMax: '<S90>/Max'
     */
    rtb_DataTypeConversion1_h2 = (int32_T)((uint32_T)rtb_MultiportSwitch_d_idx_2
      + FLDG_DebounceIncrResolverSpdMonitor_C);
    if ((uint32_T)rtb_DataTypeConversion1_h2 > 255U) {
      rtb_DataTypeConversion1_h2 = 255;
    }

    rtb_MultiportSwitch_d_idx_2 = (uint8_T)rtb_DataTypeConversion1_h2;
  }

  /* End of MultiPortSwitch: '<S90>/Multiport Switch' */

  /* Switch: '<S101>/Enable' incorporates:
   *  Constant: '<S90>/Constant2'
   *  Constant: '<S93>/Constant'
   *  Logic: '<S101>/Logical Operator1'
   *  Logic: '<S101>/Logical Operator2'
   *  Switch: '<S101>/Reset'
   */
  if ((FLDG_ResetResolverNMonitor_C == 0) && true) {
    /* Switch: '<S99>/Switch2' incorporates:
     *  Constant: '<S90>/0 Constant1'
     *  RelationalOperator: '<S99>/LowerRelop1'
     *  RelationalOperator: '<S99>/UpperRelop'
     *  Sum: '<S90>/Add2'
     *  Switch: '<S99>/Switch'
     *  UnitDelay: '<S101>/Bare Unit Delay'
     */
    if (rtb_MultiportSwitch_d_idx_2 > (uint8_T)rtb_DataTypeConversion1) {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e2 = (uint8_T)
        rtb_DataTypeConversion1;
    } else if (rtb_MultiportSwitch_d_idx_2 < ((uint8_T)0U)) {
      /* Switch: '<S99>/Switch' incorporates:
       *  Constant: '<S90>/0 Constant1'
       *  UnitDelay: '<S101>/Bare Unit Delay'
       */
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e2 = ((uint8_T)0U);
    } else {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e2 = rtb_MultiportSwitch_d_idx_2;
    }

    /* End of Switch: '<S99>/Switch2' */
  } else if (FLDG_ResetResolverNMonitor_C != 0) {
    /* Switch: '<S101>/Reset' incorporates:
     *  Constant: '<S101>/iv'
     *  UnitDelay: '<S101>/Bare Unit Delay'
     */
    FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e2 = ((uint8_T)0U);
  }

  /* End of Switch: '<S101>/Enable' */

  /* Switch: '<S100>/Switch' incorporates:
   *  Constant: '<S95>/Constant'
   *  RelationalOperator: '<S90>/Relational Operator'
   *  RelationalOperator: '<S90>/Relational Operator1'
   *  Sum: '<S90>/Add2'
   *  Switch: '<S100>/Switch1'
   *  UnitDelay: '<S101>/Bare Unit Delay'
   */
  if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e2 >= (uint8_T)
      rtb_DataTypeConversion1) {
    /* Switch: '<S100>/Switch' incorporates:
     *  Constant: '<S100>/Constant1'
     */
    FltFaultDiagnoser_DW.Memory_PreviousInput_l = true;
  } else if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_e2 <=
             FLDG_DebounceMinResolverSpdMonitor_C) {
    /* Switch: '<S100>/Switch' incorporates:
     *  Constant: '<S100>/Constant4'
     *  Switch: '<S100>/Switch1'
     */
    FltFaultDiagnoser_DW.Memory_PreviousInput_l = false;
  }

  /* End of Switch: '<S100>/Switch' */

  /* DataTypeConversion: '<S100>/Data Type Conversion EveSt2' */
  FLDG_ResolverSpdErr = (uint8_T)FltFaultDiagnoser_DW.Memory_PreviousInput_l;

  /* DataTypeConversion: '<S15>/Data Type Conversion' incorporates:
   *  Constant: '<S26>/Constant'
   *  Logic: '<S15>/Logical Operator4'
   */
  rtb_DataTypeConversion1 = ((FLDG_ResolverSpdErr != 0) &&
    (FLDG_EnableShutdownReq_C != 0));

  /* Switch: '<S23>/Switch XOR' incorporates:
   *  Constant: '<S27>/Constant'
   *  Logic: '<S23>/XOR'
   *  Switch: '<S23>/Switch AND'
   */
  if ((boolean_T)((rtb_DataTypeConversion1 != 0) ^ (FLDG_ResetLatchShutdownReq_C
        != 0))) {
    /* Switch: '<S23>/Switch XOR' incorporates:
     *  DataTypeConversion: '<S23>/Data Type Conversion1'
     */
    FLDG_ShutdownReq = (uint8_T)rtb_DataTypeConversion1;
  } else if (rtb_DataTypeConversion1 != 0) {
    /* Switch: '<S23>/Switch AND' incorporates:
     *  Constant: '<S23>/Constant'
     *  Switch: '<S23>/Switch XOR'
     */
    FLDG_ShutdownReq = ((uint8_T)1U);
  } else {
    /* Switch: '<S23>/Switch XOR' incorporates:
     *  UnitDelay: '<S23>/Unit Delay'
     */
    FLDG_ShutdownReq = FltFaultDiagnoser_DW.UnitDelay_DSTATE_i;
  }

  /* End of Switch: '<S23>/Switch XOR' */

  /* Sum: '<S102>/Add2' incorporates:
   *  Constant: '<S102>/0 Constant4'
   *  Constant: '<S106>/Constant'
   */
  tmp_0 = (uint32_T)FLDG_DebounceMaxDcVoltHi_C + ((uint16_T)1U);
  if (tmp_0 > 65535U) {
    tmp_0 = 65535U;
  }

  /* MultiPortSwitch: '<S102>/Multiport Switch' incorporates:
   *  Constant: '<S102>/0 Constant'
   *  Constant: '<S104>/Constant'
   *  Inport: '<Root>/SGPP_DcLinkVoltMeas'
   *  MinMax: '<S102>/Max'
   *  RelationalOperator: '<S22>/Relational Operator'
   *  Sum: '<S102>/Add'
   *  Sum: '<S102>/Add1'
   *  UnitDelay: '<S113>/Bare Unit Delay'
   */
  if (!(SGPP_DcLinkVoltMeas > FLDG_UDcThrHi_C)) {
    /* Sum: '<S102>/Add' incorporates:
     *  Constant: '<S109>/Constant'
     *  UnitDelay: '<S113>/Bare Unit Delay'
     */
    rtb_DataTypeConversion1 = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE -
      FLDG_DebounceDecrDcVoltHi_C;
    if (rtb_DataTypeConversion1 < 0) {
      rtb_DataTypeConversion1 = 0;
    }

    rtb_MultiportSwitch = (uint16_T)rtb_DataTypeConversion1;
  } else {
    if (((uint16_T)0U) >= FltFaultDiagnoser_DW.BareUnitDelay_DSTATE) {
      /* MinMax: '<S102>/Max' incorporates:
       *  Constant: '<S102>/0 Constant'
       */
      rtb_MultiportSwitch = ((uint16_T)0U);
    } else {
      /* MinMax: '<S102>/Max' incorporates:
       *  UnitDelay: '<S113>/Bare Unit Delay'
       */
      rtb_MultiportSwitch = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE;
    }

    /* Sum: '<S102>/Add1' incorporates:
     *  Constant: '<S108>/Constant'
     *  MinMax: '<S102>/Max'
     */
    tmp = (uint32_T)rtb_MultiportSwitch + FLDG_DebounceIncrDcVoltHi_C;
    if (tmp > 65535U) {
      tmp = 65535U;
    }

    rtb_MultiportSwitch = (uint16_T)tmp;
  }

  /* End of MultiPortSwitch: '<S102>/Multiport Switch' */

  /* Switch: '<S113>/Enable' incorporates:
   *  Constant: '<S102>/Constant2'
   *  Constant: '<S105>/Constant'
   *  Logic: '<S113>/Logical Operator1'
   *  Logic: '<S113>/Logical Operator2'
   *  Switch: '<S113>/Reset'
   */
  if ((FLDG_ResetDcDiagUHi_C == 0) && true) {
    /* Switch: '<S111>/Switch2' incorporates:
     *  Constant: '<S102>/0 Constant1'
     *  RelationalOperator: '<S111>/LowerRelop1'
     *  RelationalOperator: '<S111>/UpperRelop'
     *  Sum: '<S102>/Add2'
     *  Switch: '<S111>/Switch'
     *  UnitDelay: '<S113>/Bare Unit Delay'
     */
    if (rtb_MultiportSwitch > (uint16_T)tmp_0) {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE = (uint16_T)tmp_0;
    } else if (rtb_MultiportSwitch < ((uint16_T)0U)) {
      /* Switch: '<S111>/Switch' incorporates:
       *  Constant: '<S102>/0 Constant1'
       *  UnitDelay: '<S113>/Bare Unit Delay'
       */
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE = ((uint16_T)0U);
    } else {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE = rtb_MultiportSwitch;
    }

    /* End of Switch: '<S111>/Switch2' */
  } else if (FLDG_ResetDcDiagUHi_C != 0) {
    /* Switch: '<S113>/Reset' incorporates:
     *  Constant: '<S113>/iv'
     *  UnitDelay: '<S113>/Bare Unit Delay'
     */
    FltFaultDiagnoser_DW.BareUnitDelay_DSTATE = ((uint16_T)0U);
  }

  /* End of Switch: '<S113>/Enable' */

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S107>/Constant'
   *  RelationalOperator: '<S102>/Relational Operator'
   *  RelationalOperator: '<S102>/Relational Operator1'
   *  Sum: '<S102>/Add2'
   *  Switch: '<S112>/Switch1'
   *  UnitDelay: '<S113>/Bare Unit Delay'
   */
  if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE >= (uint16_T)tmp_0) {
    /* Switch: '<S112>/Switch' incorporates:
     *  Constant: '<S112>/Constant1'
     */
    FltFaultDiagnoser_DW.Memory_PreviousInput_m = true;
  } else if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE <=
             FLDG_DebounceMinDcVoltHi_C) {
    /* Switch: '<S112>/Switch' incorporates:
     *  Constant: '<S112>/Constant4'
     *  Switch: '<S112>/Switch1'
     */
    FltFaultDiagnoser_DW.Memory_PreviousInput_m = false;
  }

  /* End of Switch: '<S112>/Switch' */

  /* Switch: '<S103>/Switch XOR' incorporates:
   *  Constant: '<S110>/Constant'
   *  DataTypeConversion: '<S112>/Data Type Conversion EveSt2'
   *  Logic: '<S103>/XOR'
   *  Switch: '<S103>/Switch AND'
   */
  if ((boolean_T)((FLDG_ResetLatchDcVoltHi_C != 0) ^
                  FltFaultDiagnoser_DW.Memory_PreviousInput_m)) {
    /* Switch: '<S103>/Switch XOR' incorporates:
     *  DataTypeConversion: '<S103>/Data Type Conversion1'
     */
    FLDG_DcVoltHiWarn = (uint8_T)FltFaultDiagnoser_DW.Memory_PreviousInput_m;
  } else if (FltFaultDiagnoser_DW.Memory_PreviousInput_m) {
    /* Switch: '<S103>/Switch AND' incorporates:
     *  Constant: '<S103>/Constant'
     *  Switch: '<S103>/Switch XOR'
     */
    FLDG_DcVoltHiWarn = ((uint8_T)1U);
  } else {
    /* Switch: '<S103>/Switch XOR' incorporates:
     *  UnitDelay: '<S103>/Unit Delay'
     */
    FLDG_DcVoltHiWarn = FltFaultDiagnoser_DW.UnitDelay_DSTATE_h;
  }

  /* End of Switch: '<S103>/Switch XOR' */

  /* DataTypeConversion: '<S16>/Data Type Conversion' incorporates:
   *  Constant: '<S36>/Constant'
   *  Inport: '<Root>/SGSA_HwOvervoltSt'
   *  Logic: '<S16>/Logical Operator'
   */
  rtb_DataTypeConversion1 = ((SGSA_HwOvervoltSt != 0) &&
    (FLDG_EnableDiagHwDcLinkVoltDiag_C != 0));

  /* Switch: '<S32>/Switch XOR' incorporates:
   *  Constant: '<S37>/Constant'
   *  Logic: '<S32>/XOR'
   *  Switch: '<S32>/Switch AND'
   */
  if ((boolean_T)((rtb_DataTypeConversion1 != 0) ^
                  (FLDG_ResetLatchHwDcLinkVolt_C != 0))) {
    /* Switch: '<S32>/Switch XOR' incorporates:
     *  DataTypeConversion: '<S32>/Data Type Conversion1'
     */
    FLDG_HwDcLinkVoltErr = (uint8_T)rtb_DataTypeConversion1;
  } else if (rtb_DataTypeConversion1 != 0) {
    /* Switch: '<S32>/Switch AND' incorporates:
     *  Constant: '<S32>/Constant'
     *  Switch: '<S32>/Switch XOR'
     */
    FLDG_HwDcLinkVoltErr = ((uint8_T)1U);
  } else {
    /* Switch: '<S32>/Switch XOR' incorporates:
     *  UnitDelay: '<S32>/Unit Delay'
     */
    FLDG_HwDcLinkVoltErr = FltFaultDiagnoser_DW.UnitDelay_DSTATE_kt;
  }

  /* End of Switch: '<S32>/Switch XOR' */

  /* DataTypeConversion: '<S19>/Data Type Conversion' incorporates:
   *  Constant: '<S82>/Constant'
   *  Inport: '<Root>/SGSA_ResolverError'
   *  Logic: '<S19>/Logical Operator'
   *  S-Function (sfix_bitop): '<S19>/Bitwise AND'
   */
  rtb_DataTypeConversion1 = (((SGSA_ResolverError & ((uint8_T)1U)) != 0) &&
    (FLDG_EnableDiagResolverDiagDos_C != 0));

  /* Switch: '<S78>/Switch XOR' incorporates:
   *  Constant: '<S83>/Constant'
   *  Logic: '<S78>/XOR'
   *  Switch: '<S78>/Switch AND'
   */
  if ((boolean_T)((rtb_DataTypeConversion1 != 0) ^ (FLDG_ResetLatchResolverDos_C
        != 0))) {
    /* Switch: '<S78>/Switch XOR' incorporates:
     *  DataTypeConversion: '<S78>/Data Type Conversion1'
     */
    FLDG_ResolverDosErr = (uint8_T)rtb_DataTypeConversion1;
  } else if (rtb_DataTypeConversion1 != 0) {
    /* Switch: '<S78>/Switch AND' incorporates:
     *  Constant: '<S78>/Constant'
     *  Switch: '<S78>/Switch XOR'
     */
    FLDG_ResolverDosErr = ((uint8_T)1U);
  } else {
    /* Switch: '<S78>/Switch XOR' incorporates:
     *  UnitDelay: '<S78>/Unit Delay'
     */
    FLDG_ResolverDosErr = FltFaultDiagnoser_DW.UnitDelay_DSTATE_ax;
  }

  /* End of Switch: '<S78>/Switch XOR' */

  /* DataTypeConversion: '<S19>/Data Type Conversion1' incorporates:
   *  Constant: '<S84>/Constant'
   *  Inport: '<Root>/SGSA_ResolverError'
   *  Logic: '<S19>/Logical Operator1'
   *  S-Function (sfix_bitop): '<S19>/Bitwise AND1'
   */
  rtb_DataTypeConversion1 = (((SGSA_ResolverError & ((uint8_T)2U)) != 0) &&
    (FLDG_EnableDiagResolverSineLosDiag_C != 0));

  /* Switch: '<S79>/Switch XOR' incorporates:
   *  Constant: '<S85>/Constant'
   *  Logic: '<S79>/XOR'
   *  Switch: '<S79>/Switch AND'
   */
  if ((boolean_T)((rtb_DataTypeConversion1 != 0) ^
                  (FLDG_ResetLatchResolverSineLos_C != 0))) {
    /* Switch: '<S79>/Switch XOR' incorporates:
     *  DataTypeConversion: '<S79>/Data Type Conversion1'
     */
    FLDG_ResolverSineLosErr = (uint8_T)rtb_DataTypeConversion1;
  } else if (rtb_DataTypeConversion1 != 0) {
    /* Switch: '<S79>/Switch AND' incorporates:
     *  Constant: '<S79>/Constant'
     *  Switch: '<S79>/Switch XOR'
     */
    FLDG_ResolverSineLosErr = ((uint8_T)1U);
  } else {
    /* Switch: '<S79>/Switch XOR' incorporates:
     *  UnitDelay: '<S79>/Unit Delay'
     */
    FLDG_ResolverSineLosErr = FltFaultDiagnoser_DW.UnitDelay_DSTATE_f;
  }

  /* End of Switch: '<S79>/Switch XOR' */

  /* DataTypeConversion: '<S19>/Data Type Conversion2' incorporates:
   *  Constant: '<S86>/Constant'
   *  Inport: '<Root>/SGSA_ResolverError'
   *  Logic: '<S19>/Logical Operator2'
   *  S-Function (sfix_bitop): '<S19>/Bitwise AND2'
   */
  rtb_DataTypeConversion1 = (((SGSA_ResolverError & ((uint8_T)4U)) != 0) &&
    (FLDG_EnableDiagResolverCosLosDiag_C != 0));

  /* Switch: '<S80>/Switch XOR' incorporates:
   *  Constant: '<S87>/Constant'
   *  Logic: '<S80>/XOR'
   *  Switch: '<S80>/Switch AND'
   */
  if ((boolean_T)((rtb_DataTypeConversion1 != 0) ^
                  (FLDG_ResetLatchResolverCosLos_C != 0))) {
    /* Switch: '<S80>/Switch XOR' incorporates:
     *  DataTypeConversion: '<S80>/Data Type Conversion1'
     */
    FLDG_ResolverCosLosErr = (uint8_T)rtb_DataTypeConversion1;
  } else if (rtb_DataTypeConversion1 != 0) {
    /* Switch: '<S80>/Switch AND' incorporates:
     *  Constant: '<S80>/Constant'
     *  Switch: '<S80>/Switch XOR'
     */
    FLDG_ResolverCosLosErr = ((uint8_T)1U);
  } else {
    /* Switch: '<S80>/Switch XOR' incorporates:
     *  UnitDelay: '<S80>/Unit Delay'
     */
    FLDG_ResolverCosLosErr = FltFaultDiagnoser_DW.UnitDelay_DSTATE_l;
  }

  /* End of Switch: '<S80>/Switch XOR' */

  /* DataTypeConversion: '<S19>/Data Type Conversion3' incorporates:
   *  Constant: '<S88>/Constant'
   *  Inport: '<Root>/SGSA_ResolverError'
   *  Logic: '<S19>/Logical Operator3'
   *  S-Function (sfix_bitop): '<S19>/Bitwise AND3'
   */
  rtb_DataTypeConversion1 = (((SGSA_ResolverError & ((uint8_T)8U)) != 0) &&
    (FLDG_EnableDiagResolverDiagSigLot_C != 0));

  /* Switch: '<S81>/Switch XOR' incorporates:
   *  Constant: '<S89>/Constant'
   *  Logic: '<S81>/XOR'
   *  Switch: '<S81>/Switch AND'
   */
  if ((boolean_T)((rtb_DataTypeConversion1 != 0) ^
                  (FLDG_ResetLatchResolverSigLot_C != 0))) {
    /* Switch: '<S81>/Switch XOR' incorporates:
     *  DataTypeConversion: '<S81>/Data Type Conversion1'
     */
    FLDG_ResolverSigLotErr = (uint8_T)rtb_DataTypeConversion1;
  } else if (rtb_DataTypeConversion1 != 0) {
    /* Switch: '<S81>/Switch AND' incorporates:
     *  Constant: '<S81>/Constant'
     *  Switch: '<S81>/Switch XOR'
     */
    FLDG_ResolverSigLotErr = ((uint8_T)1U);
  } else {
    /* Switch: '<S81>/Switch XOR' incorporates:
     *  UnitDelay: '<S81>/Unit Delay'
     */
    FLDG_ResolverSigLotErr = FltFaultDiagnoser_DW.UnitDelay_DSTATE_m;
  }

  /* End of Switch: '<S81>/Switch XOR' */

  /* DataTypeConversion: '<S15>/Data Type Conversion2' incorporates:
   *  Constant: '<S30>/Constant'
   *  Logic: '<S15>/Logical Operator2'
   *  Logic: '<S15>/Logical Operator5'
   */
  rtb_DataTypeConversion1 = (((FLDG_DcVoltHiWarn != 0) || (FLDG_HwDcLinkVoltErr
    != 0) || (FLDG_ResolverDosErr != 0) || (FLDG_ResolverSineLosErr != 0) ||
    (FLDG_ResolverCosLosErr != 0) || (FLDG_ResolverSigLotErr != 0)) &&
    (FLDG_EnableShutdownReq_C != 0));

  /* Switch: '<S25>/Switch XOR' incorporates:
   *  Constant: '<S31>/Constant'
   *  Logic: '<S25>/XOR'
   *  Switch: '<S25>/Switch AND'
   */
  if ((boolean_T)((rtb_DataTypeConversion1 != 0) ^ (FLDG_ResetLatchShutdownReq_C
        != 0))) {
    /* Switch: '<S25>/Switch XOR' incorporates:
     *  DataTypeConversion: '<S25>/Data Type Conversion1'
     */
    FLDG_ActiveShortHsReq = (uint8_T)rtb_DataTypeConversion1;
  } else if (rtb_DataTypeConversion1 != 0) {
    /* Switch: '<S25>/Switch AND' incorporates:
     *  Constant: '<S25>/Constant'
     *  Switch: '<S25>/Switch XOR'
     */
    FLDG_ActiveShortHsReq = ((uint8_T)1U);
  } else {
    /* Switch: '<S25>/Switch XOR' incorporates:
     *  UnitDelay: '<S25>/Unit Delay'
     */
    FLDG_ActiveShortHsReq = FltFaultDiagnoser_DW.UnitDelay_DSTATE_d;
  }

  /* End of Switch: '<S25>/Switch XOR' */

  /* DataTypeConversion: '<S19>/Data Type Conversion4' incorporates:
   *  Logic: '<S19>/Logical Operator4'
   */
  FLDG_ResolverError = (uint8_T)((FLDG_ResolverSigLotErr != 0) ||
    (FLDG_ResolverCosLosErr != 0) || (FLDG_ResolverSineLosErr != 0) ||
    (FLDG_ResolverDosErr != 0));

  /* Update for UnitDelay: '<S33>/Unit Delay' */
  FltFaultDiagnoser_DW.UnitDelay_DSTATE = FLDG_HwPhaCurErr;

  /* Update for UnitDelay: '<S34>/Unit Delay' */
  FltFaultDiagnoser_DW.UnitDelay_DSTATE_o = FLDG_HwHsShortErr;

  /* Update for UnitDelay: '<S35>/Unit Delay' */
  FltFaultDiagnoser_DW.UnitDelay_DSTATE_a = FLDG_HwLsShortErr;

  /* Update for UnitDelay: '<S24>/Unit Delay' */
  FltFaultDiagnoser_DW.UnitDelay_DSTATE_k = FLDG_PowerSwitchOffReq;

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  FltFaultDiagnoser_DW.UnitDelay_DSTATE_i = FLDG_ShutdownReq;

  /* Update for UnitDelay: '<S103>/Unit Delay' */
  FltFaultDiagnoser_DW.UnitDelay_DSTATE_h = FLDG_DcVoltHiWarn;

  /* Update for UnitDelay: '<S32>/Unit Delay' */
  FltFaultDiagnoser_DW.UnitDelay_DSTATE_kt = FLDG_HwDcLinkVoltErr;

  /* Update for UnitDelay: '<S78>/Unit Delay' */
  FltFaultDiagnoser_DW.UnitDelay_DSTATE_ax = FLDG_ResolverDosErr;

  /* Update for UnitDelay: '<S79>/Unit Delay' */
  FltFaultDiagnoser_DW.UnitDelay_DSTATE_f = FLDG_ResolverSineLosErr;

  /* Update for UnitDelay: '<S80>/Unit Delay' */
  FltFaultDiagnoser_DW.UnitDelay_DSTATE_l = FLDG_ResolverCosLosErr;

  /* Update for UnitDelay: '<S81>/Unit Delay' */
  FltFaultDiagnoser_DW.UnitDelay_DSTATE_m = FLDG_ResolverSigLotErr;

  /* Update for UnitDelay: '<S25>/Unit Delay' */
  FltFaultDiagnoser_DW.UnitDelay_DSTATE_d = FLDG_ActiveShortHsReq;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/FLDG_DiagFaultResponse_1ms' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model step function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void FLDG_DiagTempSlow_10ms(void)
{
  int32_T tmp;
  uint8_T rtb_MultiportSwitch;

  /* RootInportFunctionCallGenerator generated from: '<Root>/FLDG_DiagTempSlow_10ms' incorporates:
   *  SubSystem: '<Root>/FLDG_DiagTempSlow_10ms_sys'
   */
  /* MultiPortSwitch: '<S115>/Multiport Switch' incorporates:
   *  Constant: '<S116>/Constant'
   *  Inport: '<Root>/SGPP_MotorTemp1'
   *  MinMax: '<S115>/Max'
   *  RelationalOperator: '<S114>/Relational Operator'
   *  Sum: '<S115>/Add'
   *  Sum: '<S115>/Add1'
   */
  if (!(SGPP_MotorTemp1 > FLDG_TWindingThr_C)) {
    /* Sum: '<S115>/Add' incorporates:
     *  Constant: '<S121>/Constant'
     *  UnitDelay: '<S124>/Bare Unit Delay'
     */
    tmp = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_k -
      FLDG_DebounceDecrWindingTMonitor_C;
    if (tmp < 0) {
      tmp = 0;
    }

    rtb_MultiportSwitch = (uint8_T)tmp;
  } else {
    if (((uint8_T)0U) >= FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_k) {
      /* MinMax: '<S115>/Max' */
      rtb_MultiportSwitch = ((uint8_T)0U);
    } else {
      /* MinMax: '<S115>/Max' */
      rtb_MultiportSwitch = FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_k;
    }

    /* Sum: '<S115>/Add1' incorporates:
     *  Constant: '<S120>/Constant'
     *  MinMax: '<S115>/Max'
     */
    tmp = (int32_T)((uint32_T)rtb_MultiportSwitch +
                    FLDG_DebounceIncrWindingTMonitor_C);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    rtb_MultiportSwitch = (uint8_T)tmp;
  }

  /* End of MultiPortSwitch: '<S115>/Multiport Switch' */

  /* Sum: '<S115>/Add2' incorporates:
   *  Constant: '<S115>/0 Constant4'
   *  Constant: '<S118>/Constant'
   */
  tmp = (int32_T)((uint32_T)FLDG_DebounceMaxWindingTMonitor_C + ((uint8_T)1U));
  if ((uint32_T)tmp > 255U) {
    tmp = 255;
  }

  /* Switch: '<S124>/Enable' incorporates:
   *  Constant: '<S115>/Constant2'
   *  Constant: '<S117>/Constant'
   *  Logic: '<S124>/Logical Operator1'
   *  Logic: '<S124>/Logical Operator2'
   *  Switch: '<S124>/Reset'
   */
  if ((FLDG_ResetWindingTMonitor_C == 0) && true) {
    /* Switch: '<S122>/Switch2' incorporates:
     *  Constant: '<S115>/0 Constant1'
     *  RelationalOperator: '<S122>/LowerRelop1'
     *  RelationalOperator: '<S122>/UpperRelop'
     *  Sum: '<S115>/Add2'
     *  Switch: '<S122>/Switch'
     *  UnitDelay: '<S124>/Bare Unit Delay'
     */
    if (rtb_MultiportSwitch > (uint8_T)tmp) {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_k = (uint8_T)tmp;
    } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
      /* Switch: '<S122>/Switch' incorporates:
       *  Constant: '<S115>/0 Constant1'
       *  UnitDelay: '<S124>/Bare Unit Delay'
       */
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_k = ((uint8_T)0U);
    } else {
      FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_k = rtb_MultiportSwitch;
    }

    /* End of Switch: '<S122>/Switch2' */
  } else if (FLDG_ResetWindingTMonitor_C != 0) {
    /* Switch: '<S124>/Reset' incorporates:
     *  Constant: '<S124>/iv'
     *  UnitDelay: '<S124>/Bare Unit Delay'
     */
    FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_k = ((uint8_T)0U);
  }

  /* End of Switch: '<S124>/Enable' */

  /* Switch: '<S123>/Switch' incorporates:
   *  Constant: '<S119>/Constant'
   *  RelationalOperator: '<S115>/Relational Operator'
   *  RelationalOperator: '<S115>/Relational Operator1'
   *  Sum: '<S115>/Add2'
   *  Switch: '<S123>/Switch1'
   *  UnitDelay: '<S124>/Bare Unit Delay'
   */
  if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_k >= (uint8_T)tmp) {
    /* Switch: '<S123>/Switch' incorporates:
     *  Constant: '<S123>/Constant1'
     */
    FltFaultDiagnoser_DW.Memory_PreviousInput = true;
  } else if (FltFaultDiagnoser_DW.BareUnitDelay_DSTATE_k <=
             FLDG_DebounceMinWindingTMonitor_C) {
    /* Switch: '<S123>/Switch' incorporates:
     *  Constant: '<S123>/Constant4'
     *  Switch: '<S123>/Switch1'
     */
    FltFaultDiagnoser_DW.Memory_PreviousInput = false;
  }

  /* End of Switch: '<S123>/Switch' */

  /* DataTypeConversion: '<S123>/Data Type Conversion EveSt2' */
  FLDG_WindingTempErr = (uint8_T)FltFaultDiagnoser_DW.Memory_PreviousInput;

  /* SignalConversion generated from: '<S3>/FLDG_WindingTempErr_IRV' */
  FLDG_WindingTempErr_IRV = FLDG_WindingTempErr;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/FLDG_DiagTempSlow_10ms' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model initialize function */
void FltFaultDiagnoser_initialize(void)
{
  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/FLDG_DiagCurrentFast_100us' incorporates:
   *  SubSystem: '<Root>/FLDG_DiagCurrentFast_100us_sys'
   */
  /* SystemInitialize for SignalConversion generated from: '<S1>/FLDG_PhaCur1Err_IRV' incorporates:
   *  Outport: '<S1>/FLDG_PhaCur1Err_IRV'
   */
  FLDG_PhaCur1Err_IRV = ((uint8_T)0U);

  /* SystemInitialize for SignalConversion generated from: '<S1>/FLDG_PhaCur2Err_IRV' incorporates:
   *  Outport: '<S1>/FLDG_PhaCur2Err_IRV'
   */
  FLDG_PhaCur2Err_IRV = ((uint8_T)0U);

  /* SystemInitialize for SignalConversion generated from: '<S1>/FLDG_PhaCur3Err_IRV' incorporates:
   *  Outport: '<S1>/FLDG_PhaCur3Err_IRV'
   */
  FLDG_PhaCur3Err_IRV = ((uint8_T)0U);

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/FLDG_DiagCurrentFast_100us' */

  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/FLDG_DiagTempSlow_10ms' incorporates:
   *  SubSystem: '<Root>/FLDG_DiagTempSlow_10ms_sys'
   */
  /* SystemInitialize for SignalConversion generated from: '<S3>/FLDG_WindingTempErr_IRV' incorporates:
   *  Outport: '<S3>/FLDG_WindingTempErr_IRV'
   */
  FLDG_WindingTempErr_IRV = ((uint8_T)0U);

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/FLDG_DiagTempSlow_10ms' */
}

/* Model terminate function */
void FltFaultDiagnoser_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

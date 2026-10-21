/*
 * File: SrvOpenLoopService.c
 *
 * Code generated for Simulink model 'SrvOpenLoopService'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:31:51 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SrvOpenLoopService.h"
#include "rtwtypes.h"
#include <math.h>
#include "SrvOpenLoopService_types.h"
#include "SrvOpenLoopService_private.h"

/* Named constants for Chart: '<S5>/Chart' */
#define SrvOpenLoopService_const_0_lc  (0.0F)
#define SrvOpenLoopService_const_pi_lc (6.28318548F)

/* Exported data definition */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Par */
volatile real32_T SVOL_DirectionVoltAmp_C = 0.0F;/* Referenced by: '<S6>/Constant' */

/* Voltage amplitude for direction control mode */
volatile real32_T SVOL_OpenLoopVoltGain_C = 0.0F;/* Referenced by: '<S9>/Constant' */

/* Voltage-to-speed gain for open-loop control (V/rpm) */
volatile real32_T SVOL_OpenLoopVoltOffset_C = 0.0F;/* Referenced by: '<S10>/Constant' */

/* Base voltage offset for open-loop control */
volatile boolean_T SVOL_ZeroCalStartFlag_C = false;/* Referenced by: '<S18>/Constant' */
volatile real32_T SVOL_ZeroDiff_C = 0.05F;/* Referenced by: '<S17>/Constant' */
volatile int32_T SVOL_ZeroRadCalTimeTick_C = 3700;/* Referenced by: '<S16>/Constant' */
volatile real32_T SVOL_ZeroRadCalVs_C = 4.0F;/* Referenced by: '<S15>/Constant' */

#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Sig */
real32_T SVOL_MtrZeroPoint;
real32_T SVOL_OpenLoopAlphaVolt;       /* '<S1>/Merge' */

/* Alpha-axis voltage setpoint for open-loop control */
real32_T SVOL_OpenLoopBetaVolt;        /* '<S1>/Merge1' */

/* Beta-axis voltage setpoint for open-loop control */
boolean_T SVOL_ZeroCalResult;



/* Block signals (default storage) */
B_SrvOpenLoopService_T SrvOpenLoopService_B;

/* Block states (default storage) */
DW_SrvOpenLoopService_T SrvOpenLoopService_DW;

/* Real-time model */
static RT_MODEL_SrvOpenLoopService_T SrvOpenLoopService_M_;
RT_MODEL_SrvOpenLoopService_T *const SrvOpenLoopService_M =
  &SrvOpenLoopService_M_;
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T absIn0;
  uint32_T absIn1;
  uint32_T in0Hi;
  uint32_T in0Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0 ? ~(uint32_T)in0 + 1U : (uint32_T)in0;
  absIn1 = in1 < 0 ? ~(uint32_T)in1 + 1U : (uint32_T)in1;
  in0Hi = absIn0 >> 16U;
  in0Lo = absIn0 & 65535U;
  in1Hi = absIn1 >> 16U;
  absIn0 = absIn1 & 65535U;
  productHiLo = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 *= in0Lo;
  absIn1 = 0U;
  in0Lo = (productLoHi << /*MW:OvBitwiseOk*/ 16U) + /*MW:OvCarryOk*/ absIn0;
  if (in0Lo < absIn0) {
    absIn1 = 1U;
  }

  absIn0 = in0Lo;
  in0Lo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16U;
  if (in0Lo < absIn0) {
    absIn1++;
  }

  absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) +
    absIn1;
  if ((in0 != 0) && ((in1 != 0) && ((in0 > 0) != (in1 > 0)))) {
    absIn0 = ~absIn0;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0U) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = in0Lo;
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

int32_T mul_s32_sat(int32_T a, int32_T b)
{
  int32_T result;
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  if (((int32_T)u32_chi > 0) || ((u32_chi == 0U) && (u32_clo >= 2147483648U))) {
    result = INT32_MAX;
  } else if (((int32_T)u32_chi < -1) || (((int32_T)u32_chi == -1) && (u32_clo <
               2147483648U))) {
    result = INT32_MIN;
  } else {
    result = (int32_T)u32_clo;
  }

  return result;
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model step function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void SVOL_CalcAlphaBetaVolt_100us(void)
{
  int32_T tmp;
  real32_T rtb_Add_a;
  real32_T rtb_Product1_d;

  /* RootInportFunctionCallGenerator generated from: '<Root>/SVOL_CalcAlphaBetaVolt_100us' incorporates:
   *  SubSystem: '<Root>/SVOL_CalcAlphaBetaVolt_100us_sys'
   */
  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Inport: '<Root>/CTSO_OperationMode'
   */
  switch (CTSO_OperationMode) {
   case OpenLoopCtrl:
    /* Outputs for IfAction SubSystem: '<S1>/OpenLoop' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Sum: '<S7>/Add' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S9>/Constant'
     *  Inport: '<Root>/SGPP_SpeedSp'
     *  Product: '<S7>/Product'
     */
    rtb_Add_a = SGPP_SpeedSp * SVOL_OpenLoopVoltGain_C +
      SVOL_OpenLoopVoltOffset_C;

    /* Product: '<S8>/Product1' incorporates:
     *  Constant: '<S8>/Constant'
     *  Inport: '<Root>/SGPP_PolePairs'
     *  Inport: '<Root>/SGPP_SpeedSp'
     *  Product: '<S8>/Product'
     */
    rtb_Product1_d = SGPP_SpeedSp * 0.104719803F * (real32_T)SGPP_PolePairs;

    /* Sum: '<S11>/Add' incorporates:
     *  Inport: '<Root>/SGPP_SampleTime1'
     *  Product: '<S11>/Product'
     *  UnitDelay: '<S11>/Unit Delay'
     */
    SrvOpenLoopService_DW.UnitDelay_DSTATE += SGPP_SampleTime1 * rtb_Product1_d;

    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S11>/Constant2'
     *  RelationalOperator: '<S11>/Relational Operator'
     *  RelationalOperator: '<S11>/Relational Operator2'
     *  Switch: '<S11>/Switch2'
     */
    if (rtb_Product1_d >= 0.0F) {
      /* Switch: '<S11>/Switch1' incorporates:
       *  Constant: '<S11>/Constant1'
       *  RelationalOperator: '<S11>/Relational Operator1'
       */
      if (SrvOpenLoopService_DW.UnitDelay_DSTATE >= 6.28318548F) {
        /* Sum: '<S11>/Add' incorporates:
         *  Sum: '<S11>/Add1'
         */
        SrvOpenLoopService_DW.UnitDelay_DSTATE -= 6.28318548F;
      }

      /* End of Switch: '<S11>/Switch1' */
    } else if (SrvOpenLoopService_DW.UnitDelay_DSTATE <= 0.0F) {
      /* Sum: '<S11>/Add' incorporates:
       *  Constant: '<S11>/Constant3'
       *  Sum: '<S11>/Add2'
       *  Switch: '<S11>/Switch2'
       */
      SrvOpenLoopService_DW.UnitDelay_DSTATE += 6.28318548F;
    }

    /* End of Switch: '<S11>/Switch' */

    /* Merge: '<S1>/Merge1' incorporates:
     *  Product: '<S7>/Product1'
     *  Trigonometry: '<S8>/Sin'
     */
    SVOL_OpenLoopBetaVolt = (real32_T)sin(SrvOpenLoopService_DW.UnitDelay_DSTATE)
      * rtb_Add_a;

    /* Merge: '<S1>/Merge' incorporates:
     *  Product: '<S7>/Product2'
     *  Trigonometry: '<S8>/Cos'
     */
    SVOL_OpenLoopAlphaVolt = (real32_T)cos
      (SrvOpenLoopService_DW.UnitDelay_DSTATE) * rtb_Add_a;

    /* End of Outputs for SubSystem: '<S1>/OpenLoop' */
    break;

   case VoltDirectCtrl:
    /* Outputs for IfAction SubSystem: '<S1>/DirAmp' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S6>/Constant'
     *  Inport: '<Root>/SGPP_ElecAngle'
     *  Product: '<S2>/Product'
     *  Trigonometry: '<S2>/Cos'
     */
    SVOL_OpenLoopAlphaVolt = (real32_T)cos(SGPP_ElecAngle) *
      SVOL_DirectionVoltAmp_C;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S6>/Constant'
     *  Inport: '<Root>/SGPP_ElecAngle'
     *  Product: '<S2>/Product1'
     *  Trigonometry: '<S2>/Sin'
     */
    SVOL_OpenLoopBetaVolt = (real32_T)sin(SGPP_ElecAngle) *
      SVOL_DirectionVoltAmp_C;

    /* End of Outputs for SubSystem: '<S1>/DirAmp' */
    break;

   case ZeroPointCal:
    /* Outputs for IfAction SubSystem: '<S1>/ZeroCal' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Chart: '<S5>/Chart' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S16>/Constant'
     *  Constant: '<S17>/Constant'
     *  Constant: '<S18>/Constant'
     *  Constant: '<S19>/Constant1'
     *  Constant: '<S19>/Constant2'
     *  Constant: '<S19>/Constant3'
     *  DataStoreWrite: '<S13>/Data Store Write'
     *  DataStoreWrite: '<S14>/Data Store Write'
     *  Inport: '<Root>/SGPP_ElecAngle'
     *  Product: '<S19>/Product'
     *  Product: '<S19>/Product1'
     *  Sum: '<S19>/Add'
     *  Sum: '<S19>/Add1'
     */
    if (SVOL_ZeroCalStartFlag_C) {
      if ((!SVOL_ZeroCalResult) && (SrvOpenLoopService_DW.u8_zero_cal_fail < 2))
      {
        if (SrvOpenLoopService_DW.run_delay_cnt > 2147483646) {
          SrvOpenLoopService_DW.run_delay_cnt = INT32_MAX;
        } else {
          SrvOpenLoopService_DW.run_delay_cnt++;
        }

        if (SVOL_ZeroRadCalTimeTick_C > 1073741823) {
          tmp = INT32_MAX;
        } else if (SVOL_ZeroRadCalTimeTick_C <= -1073741824) {
          tmp = INT32_MIN;
        } else {
          tmp = SVOL_ZeroRadCalTimeTick_C << 1;
        }

        if (SrvOpenLoopService_DW.run_delay_cnt <= tmp) {
          SVOL_MtrZeroPoint = 0.0F;
          SrvOpenLoopService_B.FocVal_Ubeta = 0.0F;
          SrvOpenLoopService_B.FocVal_Ualpha = -SVOL_ZeroRadCalVs_C;
        } else {
          if (SVOL_ZeroRadCalTimeTick_C > 536870911) {
            tmp = INT32_MAX;
          } else if (SVOL_ZeroRadCalTimeTick_C <= -536870912) {
            tmp = INT32_MIN;
          } else {
            tmp = SVOL_ZeroRadCalTimeTick_C << 2;
          }

          if (SrvOpenLoopService_DW.run_delay_cnt <= tmp) {
            SrvOpenLoopService_B.FocVal_Ubeta = SVOL_ZeroRadCalVs_C;
            SrvOpenLoopService_B.FocVal_Ualpha = 0.0F;
            SrvOpenLoopService_DW.rad_temp_90 = SGPP_ElecAngle;
          } else if (SrvOpenLoopService_DW.run_delay_cnt <= mul_s32_sat
                     (SVOL_ZeroRadCalTimeTick_C, 6)) {
            SrvOpenLoopService_B.FocVal_Ubeta = 0.0F;
            SrvOpenLoopService_B.FocVal_Ualpha = SVOL_ZeroRadCalVs_C;
            SrvOpenLoopService_DW.rad_temp_0 = SGPP_ElecAngle;
          } else {
            rtb_Add_a = SrvOpenLoopService_DW.rad_temp_90 -
              SrvOpenLoopService_DW.rad_temp_0;
            if (rtb_Add_a > SrvOpenLoopService_const_pi_lc) {
              rtb_Add_a -= SrvOpenLoopService_const_pi_lc;
            }

            if (rtb_Add_a < SrvOpenLoopService_const_0_lc) {
              rtb_Add_a += SrvOpenLoopService_const_pi_lc;
            }

            if ((rtb_Add_a > (1.0F + SVOL_ZeroDiff_C) * 1.57079637F) ||
                (rtb_Add_a < (1.0F - SVOL_ZeroDiff_C) * 1.57079637F)) {
              /* �궨ʧ�� */
              SrvOpenLoopService_DW.u8_zero_cal_fail++;
            } else {
              /* �궨�ɹ� */
              SVOL_MtrZeroPoint = SrvOpenLoopService_DW.rad_temp_0;
              SVOL_ZeroCalResult = true;
            }

            SrvOpenLoopService_B.FocVal_Ubeta = 0.0F;
            SrvOpenLoopService_B.FocVal_Ualpha = 0.0F;
            SrvOpenLoopService_DW.run_delay_cnt = 0;
          }
        }
      }
    } else {
      SrvOpenLoopService_B.FocVal_Ubeta = 0.0F;
      SrvOpenLoopService_B.FocVal_Ualpha = 0.0F;
      SrvOpenLoopService_DW.run_delay_cnt = 0;
      SVOL_ZeroCalResult = false;
      SrvOpenLoopService_DW.u8_zero_cal_fail = 0U;
    }

    /* End of Chart: '<S5>/Chart' */

    /* Merge: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S5>/AlphaOl'
     */
    SVOL_OpenLoopAlphaVolt = SrvOpenLoopService_B.FocVal_Ualpha;

    /* Merge: '<S1>/Merge1' incorporates:
     *  SignalConversion generated from: '<S5>/BetaOl'
     */
    SVOL_OpenLoopBetaVolt = SrvOpenLoopService_B.FocVal_Ubeta;

    /* End of Outputs for SubSystem: '<S1>/ZeroCal' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/Zero' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S4>/Constant'
     *  SignalConversion generated from: '<S4>/AlphaOl'
     */
    SVOL_OpenLoopAlphaVolt = 0.0F;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S4>/Constant1'
     *  SignalConversion generated from: '<S4>/BetaOl'
     */
    SVOL_OpenLoopBetaVolt = 0.0F;

    /* End of Outputs for SubSystem: '<S1>/Zero' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SVOL_CalcAlphaBetaVolt_100us' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model initialize function */
void SrvOpenLoopService_initialize(void)
{
  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SVOL_CalcAlphaBetaVolt_100us' incorporates:
   *  SubSystem: '<Root>/SVOL_CalcAlphaBetaVolt_100us_sys'
   */
  /* SystemInitialize for Merge: '<S1>/Merge' */
  SVOL_OpenLoopAlphaVolt = 0.0F;

  /* SystemInitialize for Merge: '<S1>/Merge1' */
  SVOL_OpenLoopBetaVolt = 0.0F;

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SVOL_CalcAlphaBetaVolt_100us' */
}

/* Model terminate function */
void SrvOpenLoopService_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: swc_EGYM.c
 *
 * Code generated for Simulink model 'swc_EGYM'.
 *
 * Model version                  : 6.175
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jun 10 09:48:41 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "swc_EGYM.h"
#include "rtwtypes.h"
#include <math.h>

/* Named constants for Chart: '<S41>/timed_delay' */
#define swc_EGYM_IN_OFF                ((uint8)1U)
#define swc_EGYM_IN_OFF_WAIT           ((uint8)2U)
#define swc_EGYM_IN_ON                 ((uint8)3U)

/* Exported data definition */
#define swc_EGYM_START_SEC_CONST_VOLATILE
#include "swc_EGYM_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_CAL */
const volatile float32 egmc_fact_obcChg = 0.8F;/* Referenced by: '<S3>/Constant24' */

/* obcChgEf */
const volatile float32 egmc_pwr_accyPwr_kW = 10.0F;/* Referenced by:
                                                    * '<S3>/Constant37'
                                                    * '<S32>/Constant'
                                                    */

/* PtcRearPwr */
const volatile float32 egmc_pwr_dcdcChgMaxPwr = 1.2F;/* Referenced by: '<S3>/Constant1' */

/* DcdcMaxPwr */
const volatile float32 egmc_pwr_dcdcMaxPwr = 2.5F;/* Referenced by: '<S3>/Constant' */

/* DcdcMaxPwr */
const volatile float32 egmc_pwr_ewpMaxPwr_kW = 3.32F;/* Referenced by: '<S3>/Saturation2' */

/* ewpMaxPwr */
const volatile float32 egmc_pwr_mcuEnbPwr = 5.0F;/* Referenced by: '<S23>/Constant' */

/* MCU output min pwr */
const volatile float32 egmc_pwr_obcPwr_kW = 6.0F;/* Referenced by: '<S19>/Constant' */

/* PtcRearPwr */
const volatile float32 egmc_pwr_ptcMaxPwr = 3.0F;/* Referenced by: '<S38>/Constant' */

/* PtcMaxPwr */
const volatile float32 egmc_pwr_ptcRearPwr_kW = 3.0F;/* Referenced by: '<S17>/Constant' */

/* PtcRearPwr */
const volatile float32 egmc_tm_ptcDelyOff_s = 0.0F;/* Referenced by: '<S3>/Constant42' */

/* Ptc Dely off */
#define swc_EGYM_STOP_SEC_CONST_VOLATILE
#include "swc_EGYM_MemMap.h"
#define swc_EGYM_START_SEC_VAR
#include "swc_EGYM_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_SIG */
float32 accd_pwr_hvAttpwr_kW;          /* '<S3>/Add4' */

/* indicated power limiting allowed */
boolean egmd_b_accyEnbFlg;             /* '<S3>/Switch17' */

/* allow ACCY OutPut pwr flg */
boolean egmd_b_dcdcEnbAllowFlg;        /* '<S3>/Switch9' */

/* allow DCDC enb flg */
boolean egmd_b_mcuEnbFlg;              /* '<S3>/Switch6' */

/* allow MCU OutPut pwr flg */
boolean egmd_b_obcEnbAllowFlg;         /* '<S3>/Switch13' */

/* allow discharge OutPut pwr flg */
boolean egmd_b_ptcEnbAllowFlg;         /* '<S3>/Switch10' */

/* allow PTC enb flg */
boolean egmd_b_ptcRearEnbAllowFlg;     /* '<S3>/Switch11' */

/* allow PtcRear OutPut pwr flg */
boolean egmd_b_zeroPwrFb;              /* '<S3>/Logical Operator2' */

/* allow ACCY OutPut pwr flg */
float32 egmd_pwr_accmHvClPwrAllwd_kW;  /* '<S3>/Saturation' */

/* indicated power limiting allowed */
float32 egmd_pwr_acwpHeatPwrCnsAllwd;  /* '<S3>/Switch25' */

/* EWP power limiting allowed */
float32 egmd_pwr_ptcHvHtPwrAllwd_kW;   /* '<S3>/Switch12' */

/* indicated power limiting allowed */
#define swc_EGYM_STOP_SEC_VAR
#include "swc_EGYM_MemMap.h"

/* Invariant block signals (default storage) */
const ConstB_swc_EGYM_T swc_EGYM_ConstB = {
  0.0F,                                /* '<Root>/Data Type Conversion108' */
  0U,                                  /* '<Root>/Data Type Conversion106' */
  0U,                                  /* '<Root>/Data Type Conversion107' */
  0,                                   /* '<S16>/Compare' */
  1,                                   /* '<S3>/Constant13' */

  /* Start of '<S3>/turnOFF_delay8' */
  {
    0.9F                               /* '<S49>/Saturation1' */
  }
  ,

  /* End of '<S3>/turnOFF_delay8' */

  /* Start of '<S3>/turnOFF_delay6' */
  {
    1.5F                               /* '<S47>/Saturation1' */
  }
  ,

  /* End of '<S3>/turnOFF_delay6' */

  /* Start of '<S3>/turnOFF_delay5' */
  {
    2.1F                               /* '<S46>/Saturation1' */
  }
  ,

  /* End of '<S3>/turnOFF_delay5' */

  /* Start of '<S3>/turnOFF_delay4' */
  {
    1.8F                               /* '<S45>/Saturation1' */
  }
  ,

  /* End of '<S3>/turnOFF_delay4' */

  /* Start of '<S3>/turnOFF_delay3' */
  {
    1.2F                               /* '<S44>/Saturation1' */
  }
  ,

  /* End of '<S3>/turnOFF_delay3' */

  /* Start of '<S3>/turnOFF_delay2' */
  {
    0.9F                               /* '<S43>/Saturation1' */
  }
  ,

  /* End of '<S3>/turnOFF_delay2' */

  /* Start of '<S3>/turnOFF_delay1' */
  {
    0.6F                               /* '<S42>/Saturation1' */
  }
  ,

  /* End of '<S3>/turnOFF_delay1' */

  /* Start of '<S3>/turnOFF_delay' */
  {
    0.3F                               /* '<S41>/Saturation1' */
  }
  /* End of '<S3>/turnOFF_delay' */
};

/* PublicStructure Variables for Internal Data */
ARID_DEF_swc_EGYM_T swc_EGYM_ARID_DEF;
static void swc_EGYM_timed_delay_Init(boolean *rty_flg_out);
static void swc_EGYM_timed_delay(boolean rtu_flg_in, float32 rtu_t_delay_off,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_timed_delay_swc_EGYM_T
  *swc_EGYM__ARID_DEF_arg);
static void swc_EGYM_turnOFF_delay_Init(boolean *rty_flg_out);
static void swc_EGYM_turnOFF_delay(boolean rtu_flg_in, float32 rtu_t_step,
  boolean *rty_flg_out, const ConstB_turnOFF_delay_swc_EGYM_T *localC,
  ARID_DEF_turnOFF_delay_swc_EG_T *swc_EGYM__ARID_DEF_arg);
static void swc_EG_ACC_PowerLimitation_Init(void);
static void swc_EGYM_ACC_PowerLimitation(void);

/*
 * System initialize for atomic system:
 *    '<S41>/timed_delay'
 *    '<S42>/timed_delay'
 *    '<S43>/timed_delay'
 *    '<S44>/timed_delay'
 *    '<S45>/timed_delay'
 *    '<S46>/timed_delay'
 *    '<S47>/timed_delay'
 *    '<S48>/timed_delay'
 *    '<S49>/timed_delay'
 */
static void swc_EGYM_timed_delay_Init(boolean *rty_flg_out)
{
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S41>/timed_delay'
 *    '<S42>/timed_delay'
 *    '<S43>/timed_delay'
 *    '<S44>/timed_delay'
 *    '<S45>/timed_delay'
 *    '<S46>/timed_delay'
 *    '<S47>/timed_delay'
 *    '<S48>/timed_delay'
 *    '<S49>/timed_delay'
 */
static void swc_EGYM_timed_delay(boolean rtu_flg_in, float32 rtu_t_delay_off,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_timed_delay_swc_EGYM_T
  *swc_EGYM__ARID_DEF_arg)
{
  /* Chart: '<S41>/timed_delay' */
  if (swc_EGYM__ARID_DEF_arg->is_active_c12_Ricardo_SW_dev_li == 0U) {
    swc_EGYM__ARID_DEF_arg->is_active_c12_Ricardo_SW_dev_li = 1U;
    if (rtu_flg_in) {
      swc_EGYM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_EGYM_IN_ON;
      *rty_flg_out = true;
    } else {
      swc_EGYM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_EGYM_IN_OFF;
      *rty_flg_out = false;
    }
  } else {
    switch (swc_EGYM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib) {
     case swc_EGYM_IN_OFF:
      if (rtu_flg_in) {
        swc_EGYM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_EGYM_IN_ON;
        *rty_flg_out = true;
      } else {
        *rty_flg_out = false;
      }
      break;

     case swc_EGYM_IN_OFF_WAIT:
      if (rtu_flg_in) {
        swc_EGYM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_EGYM_IN_ON;
        *rty_flg_out = true;
      } else if (swc_EGYM__ARID_DEF_arg->t_wait > rtu_t_delay_off - rtu_t_step)
      {
        swc_EGYM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_EGYM_IN_OFF;
        *rty_flg_out = false;
      } else {
        swc_EGYM__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = true;
      }
      break;

     default:
      /* case IN_ON: */
      if (!rtu_flg_in) {
        if (rtu_t_delay_off == 0.0F) {
          swc_EGYM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_EGYM_IN_OFF;
          *rty_flg_out = false;
        } else {
          swc_EGYM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib =
            swc_EGYM_IN_OFF_WAIT;
          swc_EGYM__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = true;
        }
      } else {
        *rty_flg_out = true;
      }
      break;
    }
  }

  /* End of Chart: '<S41>/timed_delay' */
}

/*
 * System initialize for atomic system:
 *    '<S3>/turnOFF_delay'
 *    '<S3>/turnOFF_delay1'
 *    '<S3>/turnOFF_delay2'
 *    '<S3>/turnOFF_delay3'
 *    '<S3>/turnOFF_delay4'
 *    '<S3>/turnOFF_delay5'
 *    '<S3>/turnOFF_delay6'
 *    '<S3>/turnOFF_delay8'
 */
static void swc_EGYM_turnOFF_delay_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S41>/timed_delay' */
  swc_EGYM_timed_delay_Init(rty_flg_out);
}

/*
 * Output and update for atomic system:
 *    '<S3>/turnOFF_delay'
 *    '<S3>/turnOFF_delay1'
 *    '<S3>/turnOFF_delay2'
 *    '<S3>/turnOFF_delay3'
 *    '<S3>/turnOFF_delay4'
 *    '<S3>/turnOFF_delay5'
 *    '<S3>/turnOFF_delay6'
 *    '<S3>/turnOFF_delay8'
 */
static void swc_EGYM_turnOFF_delay(boolean rtu_flg_in, float32 rtu_t_step,
  boolean *rty_flg_out, const ConstB_turnOFF_delay_swc_EGYM_T *localC,
  ARID_DEF_turnOFF_delay_swc_EG_T *swc_EGYM__ARID_DEF_arg)
{
  /* local block i/o variables */
  boolean rtb_DataTypeConversion_l;

  /* DataTypeConversion: '<S41>/Data Type Conversion' */
  rtb_DataTypeConversion_l = rtu_flg_in;

  /* Chart: '<S41>/timed_delay' */
  swc_EGYM_timed_delay(rtb_DataTypeConversion_l, localC->t_delay_off, rtu_t_step,
                       rty_flg_out,
                       &swc_EGYM__ARID_DEF_arg->ARID_DEF_timed_delay);
}

/* System initialize for function-call system: '<S1>/ACC_PowerLimitation' */
static void swc_EG_ACC_PowerLimitation_Init(void)
{
  /* local block i/o variables */
  boolean rtb_flg_out;
  boolean rtb_flg_out_k;
  boolean rtb_flg_out_l;
  boolean rtb_flg_out_k3;
  boolean rtb_flg_out_h;
  boolean rtb_flg_out_i;
  boolean rtb_flg_out_g;
  boolean rtb_flg_out_o;
  boolean rtb_flg_out_e;

  /* SystemInitialize for SignalConversion generated from: '<S2>/egmd_b_acEnbAllowFlg' */
  swc_EGYM_ARID_DEF.OutportBufferForegmd_b_acEnbAll =
    swc_EGYM_ConstB.egmd_b_acEnbAllowFlg;

  /* SystemInitialize for Atomic SubSystem: '<S3>/turnOFF_delay7' */

  /* SystemInitialize for Chart: '<S48>/timed_delay' */
  swc_EGYM_timed_delay_Init(&rtb_flg_out_k);

  /* End of SystemInitialize for SubSystem: '<S3>/turnOFF_delay7' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/turnOFF_delay3' */
  swc_EGYM_turnOFF_delay_Init(&rtb_flg_out_i);

  /* End of SystemInitialize for SubSystem: '<S3>/turnOFF_delay3' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/turnOFF_delay' */
  swc_EGYM_turnOFF_delay_Init(&rtb_flg_out_e);

  /* End of SystemInitialize for SubSystem: '<S3>/turnOFF_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/turnOFF_delay1' */
  swc_EGYM_turnOFF_delay_Init(&rtb_flg_out_o);

  /* End of SystemInitialize for SubSystem: '<S3>/turnOFF_delay1' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/turnOFF_delay2' */
  swc_EGYM_turnOFF_delay_Init(&rtb_flg_out_g);

  /* End of SystemInitialize for SubSystem: '<S3>/turnOFF_delay2' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/turnOFF_delay4' */
  swc_EGYM_turnOFF_delay_Init(&rtb_flg_out_h);

  /* End of SystemInitialize for SubSystem: '<S3>/turnOFF_delay4' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/turnOFF_delay6' */
  swc_EGYM_turnOFF_delay_Init(&rtb_flg_out_l);

  /* End of SystemInitialize for SubSystem: '<S3>/turnOFF_delay6' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/turnOFF_delay8' */
  swc_EGYM_turnOFF_delay_Init(&rtb_flg_out);

  /* End of SystemInitialize for SubSystem: '<S3>/turnOFF_delay8' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/turnOFF_delay5' */
  swc_EGYM_turnOFF_delay_Init(&rtb_flg_out_k3);

  /* End of SystemInitialize for SubSystem: '<S3>/turnOFF_delay5' */
}

/* Output and update for function-call system: '<S1>/ACC_PowerLimitation' */
static void swc_EGYM_ACC_PowerLimitation(void)
{
  /* local block i/o variables */
  float32 rtb_t_delay_off;
  boolean rtb_Compare_bk;
  boolean rtb_UnitDelay;
  boolean rtb_flg_out;
  boolean rtb_DataTypeConversion;
  boolean rtb_flg_out_k;
  boolean rtb_flg_out_l;
  boolean rtb_flg_out_k3;
  boolean rtb_flg_out_h;
  boolean rtb_flg_out_i;
  boolean rtb_flg_out_g;
  boolean rtb_flg_out_o;
  boolean rtb_flg_out_e;
  float32 rtb_Abs;
  float32 rtb_Abs1;
  float32 rtb_Abs10;
  float32 rtb_Abs11;
  float32 rtb_Abs6;
  float32 rtb_Switch1;
  float32 rtb_Switch18;
  float32 rtb_Switch20;
  float32 rtb_Switch4;
  float32 rtb_Switch5;
  boolean rtb_LogicalOperator14;
  boolean rtb_LogicalOperator17;
  boolean rtb_LogicalOperator19;
  boolean rtb_LogicalOperator4;
  boolean rtb_LogicalOperator9;

  /* SignalConversion generated from: '<S2>/accd_pwr_maxPwrLim_kW' */
  swc_EGYM_ARID_DEF.OutportBufferForaccd_pwr_maxPwr = 0.0;

  /* SignalConversion generated from: '<S2>/accd_pwr_minPwrLim_kW' */
  swc_EGYM_ARID_DEF.OutportBufferForaccd_pwr_minPwr = 0.0;

  /* SignalConversion generated from: '<S2>/egmd_b_acEnbAllowFlg' */
  swc_EGYM_ARID_DEF.OutportBufferForegmd_b_acEnbAll =
    swc_EGYM_ConstB.egmd_b_acEnbAllowFlg;

  /* Outputs for Atomic SubSystem: '<S3>/turnOFF_delay7' */
  /* DataTypeConversion: '<S48>/Data Type Conversion' */
  rtb_DataTypeConversion = swc_EGYM_ARID_DEF.DataTypeConversion1;

  /* Saturate: '<S48>/Saturation1' incorporates:
   *  Constant: '<S3>/Constant42'
   */
  if (egmc_tm_ptcDelyOff_s > 1.6777216E+7F) {
    /* Saturate: '<S48>/Saturation1' */
    rtb_t_delay_off = 1.6777216E+7F;
  } else if (egmc_tm_ptcDelyOff_s < 0.0F) {
    /* Saturate: '<S48>/Saturation1' */
    rtb_t_delay_off = 0.0F;
  } else {
    /* Saturate: '<S48>/Saturation1' */
    rtb_t_delay_off = egmc_tm_ptcDelyOff_s;
  }

  /* End of Saturate: '<S48>/Saturation1' */

  /* Chart: '<S48>/timed_delay' incorporates:
   *  Constant: '<S3>/Constant41'
   */
  swc_EGYM_timed_delay(rtb_DataTypeConversion, rtb_t_delay_off, 0.01F,
                       &rtb_flg_out_k, &swc_EGYM_ARID_DEF.ARID_DEF_timed_delay);

  /* End of Outputs for SubSystem: '<S3>/turnOFF_delay7' */

  /* Switch: '<S3>/Switch29' incorporates:
   *  Constant: '<S26>/Constant'
   *  Constant: '<S27>/Constant'
   *  Constant: '<S35>/Constant'
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S26>/Compare'
   *  RelationalOperator: '<S27>/Compare'
   *  RelationalOperator: '<S35>/Compare'
   *  RelationalOperator: '<S4>/Compare'
   *  Switch: '<S3>/Switch8'
   */
  if (swc_EGYM_ARID_DEF.DataTypeConversion2 == ((uint8)1U)) {
    rtb_LogicalOperator9 = (swc_EGYM_ARID_DEF.DataTypeConversion100 == ((uint8)
      1U));
  } else if (swc_EGYM_ARID_DEF.DataTypeConversion110 == ((uint8)1U)) {
    /* Switch: '<S3>/Switch8' incorporates:
     *  Constant: '<S5>/Constant'
     *  Logic: '<S3>/Logical Operator5'
     *  RelationalOperator: '<S5>/Compare'
     */
    rtb_LogicalOperator9 = ((swc_EGYM_ARID_DEF.DataTypeConversion126 == ((uint8)
      1U)) || rtb_flg_out_k);
  } else {
    rtb_LogicalOperator9 = (swc_EGYM_ARID_DEF.DataTypeConversion125 == ((uint8)
      1U));
  }

  /* Switch: '<S3>/Switch16' incorporates:
   *  Constant: '<S3>/Constant17'
   *  Switch: '<S3>/Switch29'
   */
  if (rtb_LogicalOperator9) {
    rtb_Switch5 = swc_EGYM_ARID_DEF.DataTypeConversion85;
  } else {
    rtb_Switch5 = 0.0F;
  }

  /* Abs: '<S3>/Abs' incorporates:
   *  Switch: '<S3>/Switch16'
   */
  rtb_Abs = fabsf(rtb_Switch5);

  /* Switch: '<S3>/Switch2' incorporates:
   *  Constant: '<S33>/Constant'
   *  Constant: '<S3>/Constant3'
   *  RelationalOperator: '<S33>/Compare'
   */
  if (swc_EGYM_ARID_DEF.DataTypeConversion93 == ((uint8)1U)) {
    rtb_Switch5 = swc_EGYM_ARID_DEF.DataTypeConversion86;
  } else {
    rtb_Switch5 = 0.0F;
  }

  /* Abs: '<S3>/Abs1' incorporates:
   *  Switch: '<S3>/Switch2'
   */
  rtb_Abs1 = fabsf(rtb_Switch5);

  /* Switch: '<S3>/Switch23' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S3>/Constant38'
   *  Constant: '<S6>/Constant'
   *  RelationalOperator: '<S15>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   *  Switch: '<S3>/Switch15'
   */
  if (swc_EGYM_ARID_DEF.DataTypeConversion2 == ((uint8)1U)) {
    /* Switch: '<S3>/Switch28' incorporates:
     *  Constant: '<S3>/Constant48'
     *  Constant: '<S8>/Constant'
     *  RelationalOperator: '<S8>/Compare'
     */
    if (swc_EGYM_ARID_DEF.DataTypeConversion4 == ((uint8)1U)) {
      rtb_Switch5 = swc_EGYM_ARID_DEF.DataTypeConversion3;
    } else {
      rtb_Switch5 = 0.0F;
    }

    /* End of Switch: '<S3>/Switch28' */
  } else if (swc_EGYM_ARID_DEF.DataTypeConversion114 == ((uint8)1U)) {
    /* Switch: '<S3>/Switch15' */
    rtb_Switch5 = swc_EGYM_ARID_DEF.DataTypeConversion87;
  } else {
    rtb_Switch5 = 0.0F;
  }

  /* Abs: '<S3>/Abs10' incorporates:
   *  Switch: '<S3>/Switch23'
   */
  rtb_Abs10 = fabsf(rtb_Switch5);

  /* Switch: '<S3>/Switch27' incorporates:
   *  Constant: '<S31>/Constant'
   *  Constant: '<S7>/Constant'
   *  RelationalOperator: '<S31>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   *  Switch: '<S3>/Switch14'
   */
  if (swc_EGYM_ARID_DEF.DataTypeConversion2 == ((uint8)1U)) {
    /* Switch: '<S3>/Switch5' incorporates:
     *  Constant: '<S3>/Constant47'
     */
    rtb_Switch5 = 0.0F;
  } else {
    if (swc_EGYM_ARID_DEF.DataTypeConversion110 == ((uint8)1U)) {
      /* Switch: '<S3>/Switch14' */
      rtb_LogicalOperator9 = swc_EGYM_ARID_DEF.DataTypeConversion127;
    } else {
      /* Switch: '<S3>/Switch14' */
      rtb_LogicalOperator9 = swc_EGYM_ConstB.Compare;
    }

    /* Switch: '<S3>/Switch32' incorporates:
     *  Switch: '<S3>/Switch14'
     */
    if (rtb_LogicalOperator9) {
      /* Switch: '<S3>/Switch5' */
      rtb_Switch5 = swc_EGYM_ARID_DEF.DataTypeConversion116;
    } else {
      /* Switch: '<S3>/Switch5' incorporates:
       *  Constant: '<S3>/Constant32'
       */
      rtb_Switch5 = 0.0F;
    }

    /* End of Switch: '<S3>/Switch32' */
  }

  /* End of Switch: '<S3>/Switch27' */

  /* Abs: '<S3>/Abs11' */
  rtb_Abs11 = fabsf(rtb_Switch5);

  /* Abs: '<S3>/Abs6' */
  rtb_Abs6 = fabsf(swc_EGYM_ARID_DEF.DataTypeConversion17);

  /* Logic: '<S3>/Logical Operator9' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S11>/Constant'
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   */
  rtb_LogicalOperator9 = ((swc_EGYM_ARID_DEF.DataTypeConversion121 == ((uint8)2U))
    && (swc_EGYM_ARID_DEF.DataTypeConversion120 == ((uint8)2U)) &&
    (swc_EGYM_ARID_DEF.DataTypeConversion122 == ((uint8)2U)));

  /* Logic: '<S3>/Logical Operator14' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S13>/Constant'
   *  Constant: '<S14>/Constant'
   *  Logic: '<S3>/Logical Operator15'
   *  RelationalOperator: '<S12>/Compare'
   *  RelationalOperator: '<S13>/Compare'
   *  RelationalOperator: '<S14>/Compare'
   */
  rtb_LogicalOperator14 = ((swc_EGYM_ARID_DEF.DataTypeConversion121 == ((uint8)
    2U)) && ((swc_EGYM_ARID_DEF.DataTypeConversion120 == ((uint8)1U)) ||
             (swc_EGYM_ARID_DEF.DataTypeConversion122 == ((uint8)1U))));

  /* Switch: '<S3>/Switch4' incorporates:
   *  Logic: '<S3>/Logical Operator10'
   */
  if (rtb_LogicalOperator9 || rtb_LogicalOperator14) {
    /* Switch: '<S3>/Switch3' incorporates:
     *  Constant: '<S34>/Constant'
     *  Constant: '<S3>/Constant5'
     *  RelationalOperator: '<S34>/Compare'
     */
    if (swc_EGYM_ARID_DEF.DataTypeConversion94 == 255.0F) {
      rtb_Switch5 = 0.0F;
    } else {
      rtb_Switch5 = swc_EGYM_ARID_DEF.DataTypeConversion94;
    }

    /* Switch: '<S3>/Switch4' incorporates:
     *  Abs: '<S3>/Abs2'
     *  Constant: '<S3>/Constant21'
     *  Product: '<S3>/Divide3'
     *  Switch: '<S3>/Switch3'
     */
    rtb_Switch4 = fabsf(rtb_Switch5 * swc_EGYM_ARID_DEF.DataTypeConversion96 /
                        1000.0F);
  } else {
    /* Switch: '<S3>/Switch4' incorporates:
     *  Constant: '<S3>/Constant9'
     */
    rtb_Switch4 = 0.0F;
  }

  /* End of Switch: '<S3>/Switch4' */

  /* Logic: '<S3>/Logical Operator17' incorporates:
   *  Constant: '<S20>/Constant'
   *  Constant: '<S21>/Constant'
   *  Constant: '<S22>/Constant'
   *  Constant: '<S24>/Constant'
   *  Logic: '<S3>/Logical Operator18'
   *  RelationalOperator: '<S20>/Compare'
   *  RelationalOperator: '<S21>/Compare'
   *  RelationalOperator: '<S22>/Compare'
   *  RelationalOperator: '<S24>/Compare'
   */
  rtb_LogicalOperator17 = (((swc_EGYM_ARID_DEF.DataTypeConversion123 == ((uint8)
    4U)) || (swc_EGYM_ARID_DEF.DataTypeConversion123 == ((uint8)9U))) &&
    (swc_EGYM_ARID_DEF.DataTypeConversion120 == ((uint8)2U)) &&
    (swc_EGYM_ARID_DEF.DataTypeConversion122 == ((uint8)2U)));

  /* Logic: '<S3>/Logical Operator19' incorporates:
   *  Constant: '<S25>/Constant'
   *  Constant: '<S28>/Constant'
   *  Constant: '<S29>/Constant'
   *  Constant: '<S30>/Constant'
   *  Logic: '<S3>/Logical Operator20'
   *  Logic: '<S3>/Logical Operator21'
   *  RelationalOperator: '<S25>/Compare'
   *  RelationalOperator: '<S28>/Compare'
   *  RelationalOperator: '<S29>/Compare'
   *  RelationalOperator: '<S30>/Compare'
   */
  rtb_LogicalOperator19 = (((swc_EGYM_ARID_DEF.DataTypeConversion123 == ((uint8)
    4U)) || (swc_EGYM_ARID_DEF.DataTypeConversion123 == ((uint8)9U))) &&
    ((swc_EGYM_ARID_DEF.DataTypeConversion120 == ((uint8)1U)) ||
     (swc_EGYM_ARID_DEF.DataTypeConversion122 == ((uint8)1U))));

  /* Switch: '<S3>/Switch20' incorporates:
   *  Logic: '<S3>/Logical Operator7'
   */
  if (rtb_LogicalOperator17 || rtb_LogicalOperator19) {
    /* Switch: '<S3>/Switch20' incorporates:
     *  Abs: '<S3>/Abs3'
     */
    rtb_Switch20 = fabsf(swc_EGYM_ARID_DEF.DataTypeConversion95);
  } else {
    /* Switch: '<S3>/Switch20' incorporates:
     *  Constant: '<S3>/Constant6'
     */
    rtb_Switch20 = 0.0F;
  }

  /* End of Switch: '<S3>/Switch20' */

  /* Logic: '<S3>/Logical Operator4' incorporates:
   *  Constant: '<S36>/Constant'
   *  Constant: '<S37>/Constant'
   *  Logic: '<S3>/Logical Operator'
   *  RelationalOperator: '<S36>/Compare'
   *  RelationalOperator: '<S37>/Compare'
   */
  rtb_LogicalOperator4 = ((!rtb_LogicalOperator9) && (!rtb_LogicalOperator17) &&
    (swc_EGYM_ARID_DEF.DataTypeConversion120 == ((uint8)2U)) &&
    (swc_EGYM_ARID_DEF.DataTypeConversion122 == ((uint8)2U)));

  /* Switch: '<S3>/Switch34' incorporates:
   *  Switch: '<S3>/Switch35'
   *  Switch: '<S3>/Switch36'
   *  Switch: '<S3>/Switch37'
   */
  if (rtb_LogicalOperator9) {
    /* Switch: '<S3>/Switch34' incorporates:
     *  Sum: '<S3>/Add8'
     */
    rtb_Switch20 = rtb_Abs6 + rtb_Switch4;
  } else if (rtb_LogicalOperator17) {
    /* Switch: '<S3>/Switch34' incorporates:
     *  Sum: '<S3>/Add16'
     *  Switch: '<S3>/Switch35'
     */
    rtb_Switch20 += rtb_Abs6;
  } else if (rtb_LogicalOperator14) {
    /* Switch: '<S3>/Switch34' incorporates:
     *  Switch: '<S3>/Switch35'
     *  Switch: '<S3>/Switch36'
     */
    rtb_Switch20 = rtb_Switch4;
  } else if (!rtb_LogicalOperator19) {
    /* Switch: '<S3>/Switch21' incorporates:
     *  Switch: '<S3>/Switch35'
     *  Switch: '<S3>/Switch36'
     *  Switch: '<S3>/Switch37'
     */
    if (rtb_LogicalOperator4) {
      /* Switch: '<S3>/Switch34' incorporates:
       *  Switch: '<S3>/Switch36'
       *  Switch: '<S3>/Switch37'
       */
      rtb_Switch20 = rtb_Abs6;
    } else {
      /* Switch: '<S3>/Switch34' incorporates:
       *  Constant: '<S3>/Constant39'
       *  Switch: '<S3>/Switch36'
       *  Switch: '<S3>/Switch37'
       */
      rtb_Switch20 = 0.0F;
    }

    /* End of Switch: '<S3>/Switch21' */
  }

  /* End of Switch: '<S3>/Switch34' */

  /* Switch: '<S3>/Switch7' incorporates:
   *  Constant: '<S39>/Constant'
   *  RelationalOperator: '<S39>/Compare'
   */
  if (swc_EGYM_ARID_DEF.DataTypeConversion92 == ((uint8)1U)) {
    /* Switch: '<S3>/Switch7' incorporates:
     *  Abs: '<S3>/Abs5'
     */
    rtb_Switch4 = fabsf(swc_EGYM_ARID_DEF.DataTypeConversion77);
  } else {
    /* Switch: '<S3>/Switch7' incorporates:
     *  Constant: '<S3>/Constant8'
     */
    rtb_Switch4 = 0.0F;
  }

  /* End of Switch: '<S3>/Switch7' */

  /* Switch: '<S3>/Switch1' */
  if (swc_EGYM_ARID_DEF.DataTypeConversion112) {
    /* Switch: '<S3>/Switch1' incorporates:
     *  Constant: '<S3>/Constant40'
     *  Switch: '<S3>/Switch22'
     */
    rtb_Switch1 = fmaxf(swc_EGYM_ARID_DEF.DataTypeConversion124, 0.0F);
  } else {
    /* Switch: '<S3>/Switch1' incorporates:
     *  Constant: '<S3>/Constant7'
     */
    rtb_Switch1 = 0.0F;
  }

  /* End of Switch: '<S3>/Switch1' */

  /* Switch: '<S3>/Switch18' */
  if (swc_EGYM_ARID_DEF.DataTypeConversion129) {
    /* Switch: '<S3>/Switch18' incorporates:
     *  Constant: '<S3>/Constant37'
     */
    rtb_Switch18 = egmc_pwr_accyPwr_kW;
  } else {
    /* Switch: '<S3>/Switch18' incorporates:
     *  Constant: '<S3>/Constant36'
     */
    rtb_Switch18 = 0.0F;
  }

  /* End of Switch: '<S3>/Switch18' */

  /* Sum: '<S3>/Add4' */
  accd_pwr_hvAttpwr_kW = (((((rtb_Switch4 + rtb_Abs1) + rtb_Abs) + rtb_Abs11) +
    rtb_Abs10) + rtb_Switch1) + rtb_Switch18;

  /* RelationalOperator: '<S18>/Compare' incorporates:
   *  Constant: '<S18>/Constant'
   */
  rtb_Compare_bk = (swc_EGYM_ARID_DEF.DataTypeConversion118 == ((uint8)1U));

  /* Logic: '<S3>/Logical Operator2' incorporates:
   *  Constant: '<S40>/Constant'
   *  RelationalOperator: '<S40>/Compare'
   */
  egmd_b_zeroPwrFb = ((accd_pwr_hvAttpwr_kW == 0.0F) && rtb_Compare_bk);

  /* Outputs for Atomic SubSystem: '<S3>/turnOFF_delay3' */
  /* Constant: '<S3>/Constant20' */
  swc_EGYM_turnOFF_delay(rtb_Compare_bk, 0.01F, &rtb_flg_out_i,
    &swc_EGYM_ConstB.turnOFF_delay3, &swc_EGYM_ARID_DEF.ARID_DEF_turnOFF_delay3);

  /* End of Outputs for SubSystem: '<S3>/turnOFF_delay3' */

  /* Switch: '<S3>/Switch5' incorporates:
   *  Switch: '<S3>/Switch24'
   */
  if (rtb_flg_out_i) {
    /* Switch: '<S3>/Switch5' incorporates:
     *  Constant: '<S3>/Constant26'
     */
    rtb_Switch5 = 0.0F;
  } else if (rtb_LogicalOperator14) {
    /* Switch: '<S3>/Switch24' incorporates:
     *  Sum: '<S3>/Add21'
     *  Switch: '<S3>/Switch5'
     */
    rtb_Switch5 = (((rtb_Switch20 - rtb_Switch4) - rtb_Abs) - rtb_Abs10) -
      rtb_Abs11;
  } else {
    /* Switch: '<S3>/Switch5' incorporates:
     *  Constant: '<S3>/Constant24'
     *  Product: '<S3>/Divide4'
     *  Sum: '<S3>/Add21'
     *  Switch: '<S3>/Switch24'
     */
    rtb_Switch5 = ((((rtb_Switch20 - rtb_Switch4) - rtb_Abs) - rtb_Abs10) -
                   rtb_Abs11) * egmc_fact_obcChg;
  }

  /* End of Switch: '<S3>/Switch5' */

  /* Saturate: '<S3>/Saturation' */
  if (rtb_Switch5 > 25.4F) {
    /* Saturate: '<S3>/Saturation' */
    egmd_pwr_accmHvClPwrAllwd_kW = 25.4F;
  } else if (rtb_Switch5 < 0.0F) {
    /* Saturate: '<S3>/Saturation' */
    egmd_pwr_accmHvClPwrAllwd_kW = 0.0F;
  } else {
    /* Saturate: '<S3>/Saturation' */
    egmd_pwr_accmHvClPwrAllwd_kW = rtb_Switch5;
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S3>/turnOFF_delay' */
  /* Constant: '<S3>/Constant4' */
  swc_EGYM_turnOFF_delay(rtb_Compare_bk, 0.01F, &rtb_flg_out_e,
    &swc_EGYM_ConstB.turnOFF_delay, &swc_EGYM_ARID_DEF.ARID_DEF_turnOFF_delay);

  /* End of Outputs for SubSystem: '<S3>/turnOFF_delay' */

  /* Switch: '<S3>/Switch10' */
  if (rtb_flg_out_e) {
    /* Switch: '<S3>/Switch10' incorporates:
     *  Constant: '<S3>/Constant18'
     */
    egmd_b_ptcEnbAllowFlg = false;
  } else {
    /* Switch: '<S3>/Switch10' incorporates:
     *  Constant: '<S38>/Constant'
     *  RelationalOperator: '<S38>/Compare'
     *  Sum: '<S3>/Add6'
     */
    egmd_b_ptcEnbAllowFlg = (rtb_Switch20 - rtb_Switch4 >= egmc_pwr_ptcMaxPwr);
  }

  /* End of Switch: '<S3>/Switch10' */

  /* Outputs for Atomic SubSystem: '<S3>/turnOFF_delay1' */
  /* Constant: '<S3>/Constant14' */
  swc_EGYM_turnOFF_delay(rtb_Compare_bk, 0.01F, &rtb_flg_out_o,
    &swc_EGYM_ConstB.turnOFF_delay1, &swc_EGYM_ARID_DEF.ARID_DEF_turnOFF_delay1);

  /* End of Outputs for SubSystem: '<S3>/turnOFF_delay1' */

  /* Switch: '<S3>/Switch11' */
  if (rtb_flg_out_o) {
    /* Switch: '<S3>/Switch11' incorporates:
     *  Constant: '<S3>/Constant22'
     */
    egmd_b_ptcRearEnbAllowFlg = false;
  } else {
    /* Switch: '<S3>/Switch11' incorporates:
     *  Constant: '<S17>/Constant'
     *  RelationalOperator: '<S17>/Compare'
     *  Sum: '<S3>/Add11'
     */
    egmd_b_ptcRearEnbAllowFlg = ((rtb_Switch20 - rtb_Switch4) - rtb_Abs >=
      egmc_pwr_ptcRearPwr_kW);
  }

  /* End of Switch: '<S3>/Switch11' */

  /* Outputs for Atomic SubSystem: '<S3>/turnOFF_delay2' */
  /* Constant: '<S3>/Constant16' */
  swc_EGYM_turnOFF_delay(rtb_Compare_bk, 0.01F, &rtb_flg_out_g,
    &swc_EGYM_ConstB.turnOFF_delay2, &swc_EGYM_ARID_DEF.ARID_DEF_turnOFF_delay2);

  /* End of Outputs for SubSystem: '<S3>/turnOFF_delay2' */

  /* Switch: '<S3>/Switch12' incorporates:
   *  Switch: '<S3>/Switch19'
   */
  if (rtb_flg_out_g) {
    /* Switch: '<S3>/Switch12' incorporates:
     *  Constant: '<S3>/Constant23'
     */
    egmd_pwr_ptcHvHtPwrAllwd_kW = 0.0F;
  } else {
    if (rtb_LogicalOperator14) {
      /* Switch: '<S3>/Switch19' incorporates:
       *  Sum: '<S3>/Add15'
       */
      rtb_Switch5 = ((rtb_Switch20 - rtb_Switch4) - rtb_Abs) - rtb_Abs11;
    } else {
      /* Switch: '<S3>/Switch19' incorporates:
       *  Constant: '<S3>/Constant2'
       *  Product: '<S3>/Divide2'
       *  Sum: '<S3>/Add15'
       */
      rtb_Switch5 = (((rtb_Switch20 - rtb_Switch4) - rtb_Abs) - rtb_Abs11) *
        0.8F;
    }

    /* Saturate: '<S3>/Saturation1' */
    if (rtb_Switch5 > 25.4F) {
      /* Switch: '<S3>/Switch12' */
      egmd_pwr_ptcHvHtPwrAllwd_kW = 25.4F;
    } else if (rtb_Switch5 < 0.0F) {
      /* Switch: '<S3>/Switch12' */
      egmd_pwr_ptcHvHtPwrAllwd_kW = 0.0F;
    } else {
      /* Switch: '<S3>/Switch12' */
      egmd_pwr_ptcHvHtPwrAllwd_kW = rtb_Switch5;
    }

    /* End of Saturate: '<S3>/Saturation1' */
  }

  /* End of Switch: '<S3>/Switch12' */

  /* Outputs for Atomic SubSystem: '<S3>/turnOFF_delay4' */
  /* Constant: '<S3>/Constant28' */
  swc_EGYM_turnOFF_delay(rtb_Compare_bk, 0.01F, &rtb_flg_out_h,
    &swc_EGYM_ConstB.turnOFF_delay4, &swc_EGYM_ARID_DEF.ARID_DEF_turnOFF_delay4);

  /* End of Outputs for SubSystem: '<S3>/turnOFF_delay4' */

  /* Switch: '<S3>/Switch13' */
  if (rtb_flg_out_h) {
    /* Switch: '<S3>/Switch13' incorporates:
     *  Constant: '<S3>/Constant25'
     */
    egmd_b_obcEnbAllowFlg = false;
  } else {
    /* Switch: '<S3>/Switch13' incorporates:
     *  Constant: '<S19>/Constant'
     *  RelationalOperator: '<S19>/Compare'
     *  Sum: '<S3>/Add5'
     */
    egmd_b_obcEnbAllowFlg = ((((((rtb_Switch20 - rtb_Switch4) - rtb_Abs) -
      rtb_Abs11) - rtb_Abs10) - rtb_Abs1) - rtb_Switch18 >= egmc_pwr_obcPwr_kW);
  }

  /* End of Switch: '<S3>/Switch13' */

  /* Outputs for Atomic SubSystem: '<S3>/turnOFF_delay6' */
  /* Constant: '<S3>/Constant35' */
  swc_EGYM_turnOFF_delay(rtb_Compare_bk, 0.01F, &rtb_flg_out_l,
    &swc_EGYM_ConstB.turnOFF_delay6, &swc_EGYM_ARID_DEF.ARID_DEF_turnOFF_delay6);

  /* End of Outputs for SubSystem: '<S3>/turnOFF_delay6' */

  /* Switch: '<S3>/Switch17' */
  if (rtb_flg_out_l) {
    /* Switch: '<S3>/Switch17' incorporates:
     *  Constant: '<S3>/Constant29'
     */
    egmd_b_accyEnbFlg = false;
  } else {
    /* Switch: '<S3>/Switch17' incorporates:
     *  Constant: '<S32>/Constant'
     *  RelationalOperator: '<S32>/Compare'
     *  Sum: '<S3>/Add2'
     */
    egmd_b_accyEnbFlg = (((((rtb_Switch20 - rtb_Switch4) - rtb_Abs) - rtb_Abs11)
                          - rtb_Abs10) - rtb_Abs1 >= egmc_pwr_accyPwr_kW);
  }

  /* End of Switch: '<S3>/Switch17' */

  /* Outputs for Atomic SubSystem: '<S3>/turnOFF_delay8' */
  /* Constant: '<S3>/Constant44' */
  swc_EGYM_turnOFF_delay(rtb_Compare_bk, 0.01F, &rtb_flg_out,
    &swc_EGYM_ConstB.turnOFF_delay8, &swc_EGYM_ARID_DEF.ARID_DEF_turnOFF_delay8);

  /* End of Outputs for SubSystem: '<S3>/turnOFF_delay8' */

  /* Switch: '<S3>/Switch25' incorporates:
   *  Switch: '<S3>/Switch26'
   */
  if (rtb_flg_out) {
    /* Switch: '<S3>/Switch25' incorporates:
     *  Constant: '<S3>/Constant46'
     */
    egmd_pwr_acwpHeatPwrCnsAllwd = 0.0F;
  } else {
    if (rtb_LogicalOperator14) {
      /* Switch: '<S3>/Switch26' incorporates:
       *  Sum: '<S3>/Add1'
       */
      rtb_Switch5 = (rtb_Switch20 - rtb_Switch4) - rtb_Abs;
    } else {
      /* Switch: '<S3>/Switch26' incorporates:
       *  Constant: '<S3>/Constant45'
       *  Product: '<S3>/Divide1'
       *  Sum: '<S3>/Add1'
       */
      rtb_Switch5 = ((rtb_Switch20 - rtb_Switch4) - rtb_Abs) * 0.8F;
    }

    /* Saturate: '<S3>/Saturation2' */
    if (rtb_Switch5 > egmc_pwr_ewpMaxPwr_kW) {
      /* Switch: '<S3>/Switch25' */
      egmd_pwr_acwpHeatPwrCnsAllwd = egmc_pwr_ewpMaxPwr_kW;
    } else if (rtb_Switch5 < 0.0F) {
      /* Switch: '<S3>/Switch25' */
      egmd_pwr_acwpHeatPwrCnsAllwd = 0.0F;
    } else {
      /* Switch: '<S3>/Switch25' */
      egmd_pwr_acwpHeatPwrCnsAllwd = rtb_Switch5;
    }

    /* End of Saturate: '<S3>/Saturation2' */
  }

  /* End of Switch: '<S3>/Switch25' */

  /* Outputs for Atomic SubSystem: '<S3>/turnOFF_delay5' */
  /* Constant: '<S3>/Constant31' */
  swc_EGYM_turnOFF_delay(rtb_Compare_bk, 0.01F, &rtb_flg_out_k3,
    &swc_EGYM_ConstB.turnOFF_delay5, &swc_EGYM_ARID_DEF.ARID_DEF_turnOFF_delay5);

  /* End of Outputs for SubSystem: '<S3>/turnOFF_delay5' */

  /* Switch: '<S3>/Switch6' */
  if (rtb_flg_out_k3) {
    /* Switch: '<S3>/Switch6' incorporates:
     *  Constant: '<S3>/Constant33'
     */
    egmd_b_mcuEnbFlg = false;
  } else {
    /* Switch: '<S3>/Switch6' incorporates:
     *  Constant: '<S23>/Constant'
     *  RelationalOperator: '<S23>/Compare'
     *  Sum: '<S3>/Add14'
     */
    egmd_b_mcuEnbFlg = (((((((rtb_Abs6 - rtb_Switch4) - rtb_Abs1) - rtb_Abs) -
      rtb_Abs11) - rtb_Abs10) - rtb_Switch1) - rtb_Switch18 >=
                        egmc_pwr_mcuEnbPwr);
  }

  /* End of Switch: '<S3>/Switch6' */

  /* Switch: '<S3>/Switch9' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if (rtb_Compare_bk) {
    /* Switch: '<S3>/Switch9' incorporates:
     *  Constant: '<S3>/Constant12'
     */
    egmd_b_dcdcEnbAllowFlg = false;
  } else {
    if (rtb_LogicalOperator4) {
      /* Switch: '<S3>/Switch' incorporates:
       *  Constant: '<S3>/Constant'
       */
      rtb_Switch5 = egmc_pwr_dcdcMaxPwr;
    } else {
      /* Switch: '<S3>/Switch' incorporates:
       *  Constant: '<S3>/Constant1'
       */
      rtb_Switch5 = egmc_pwr_dcdcChgMaxPwr;
    }

    /* Switch: '<S3>/Switch9' incorporates:
     *  RelationalOperator: '<S3>/Relational Operator'
     *  Switch: '<S3>/Switch'
     */
    egmd_b_dcdcEnbAllowFlg = (rtb_Switch20 >= rtb_Switch5);
  }

  /* End of Switch: '<S3>/Switch9' */

  /* UnitDelay: '<S3>/Unit Delay' */
  rtb_UnitDelay = swc_EGYM_ARID_DEF.UnitDelay_DSTATE;

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  swc_EGYM_ARID_DEF.UnitDelay_DSTATE = swc_EGYM_ARID_DEF.DataTypeConversion76;
}

/* Model step function */
void swc_EGYM_Step(void)
{
  /* local block i/o variables */
  float32 rtb_DataTypeConversion102;
  float32 rtb_DataTypeConversion105;
  uint8 rtb_DataTypeConversion99;
  uint8 rtb_DataTypeConversion119;
  uint8 rtb_DataTypeConversion103;
  uint8 rtb_DataTypeConversion104;
  boolean rtb_DataTypeConversion109;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Inport generated from: '<Root>/BusElementIn1'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion1 =
    Rte_IRead_swc_EGYM_Step_vcsb_THSM_thmd_b_heaterEna();

  /* DataTypeConversion: '<Root>/Data Type Conversion100' incorporates:
   *  Inport generated from: '<Root>/BusElementIn19'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion100 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_st_ptcConnStsFb();

  /* DataTypeConversion: '<Root>/Data Type Conversion17' incorporates:
   *  Inport generated from: '<Root>/BusElementIn'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion17 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_hvbd_pwr_PeakDischMax_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion87' incorporates:
   *  Inport generated from: '<Root>/BusElementIn31'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion87 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_pwr_iptActPwr_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion86' incorporates:
   *  Inport generated from: '<Root>/BusElementIn11'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion86 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_pwr_airCmprAct_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion77' incorporates:
   *  Inport generated from: '<Root>/BusElementIn2'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion77 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_dccd_pwr_dcdcHVpwr_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion94' incorporates:
   *  Inport generated from: '<Root>/BusElementIn13'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion94 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_i_hvbDCChgCurReq_A();

  /* DataTypeConversion: '<Root>/Data Type Conversion95' incorporates:
   *  Inport generated from: '<Root>/BusElementIn14'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion95 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_obcd_pwr_obcOutpt_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion96' incorporates:
   *  Inport generated from: '<Root>/BusElementIn15'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion96 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_u_hvbVolt_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion99' incorporates:
   *  Inport generated from: '<Root>/BusElementIn18'
   */
  rtb_DataTypeConversion99 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_st_actWorkSts1();

  /* DataTypeConversion: '<Root>/Data Type Conversion85' incorporates:
   *  Inport generated from: '<Root>/BusElementIn10'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion85 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_pwr_PTCActPwr_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion76' incorporates:
   *  Inport generated from: '<Root>/BusElementIn28'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion76 =
    Rte_IRead_swc_EGYM_Step_vcsb_THSM_thmd_b_heaterEna2();

  /* DataTypeConversion: '<Root>/Data Type Conversion116' incorporates:
   *  Inport generated from: '<Root>/BusElementIn9'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion116 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_pwr_ptcActPwrRear_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion119' incorporates:
   *  Inport generated from: '<Root>/BusElementIn27'
   */
  rtb_DataTypeConversion119 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_st_hcmAccConnStsFb();

  /* DataTypeConversion: '<Root>/Data Type Conversion118' incorporates:
   *  Inport generated from: '<Root>/BusElementIn20'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion118 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_b_hvbZeroPwrReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion112' incorporates:
   *  Inport generated from: '<Root>/BusElementIn29'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion112 =
    Rte_IRead_swc_EGYM_Step_vcsb_HVSM_hvbd_b_dchaOn();

  /* DataTypeConversion: '<Root>/Data Type Conversion92' incorporates:
   *  Inport generated from: '<Root>/BusElementIn37'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion92 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_dccd_e_24vDcdcModAct();

  /* DataTypeConversion: '<Root>/Data Type Conversion93' incorporates:
   *  Inport generated from: '<Root>/BusElementIn3'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion93 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_accd_st_airCmprSt();

  /* DataTypeConversion: '<Root>/Data Type Conversion114' incorporates:
   *  Inport generated from: '<Root>/BusElementIn8'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion114 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_accd_st_iptWorkSt();

  /* DataTypeConversion: '<Root>/Data Type Conversion121' incorporates:
   *  Inport generated from: '<Root>/BusElementIn7'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion121 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_st_hvbDCChgProcss();

  /* DataTypeConversion: '<Root>/Data Type Conversion120' incorporates:
   *  Inport generated from: '<Root>/BusElementIn32'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion120 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_hvbd_e_hvbMaiRlyPos();

  /* DataTypeConversion: '<Root>/Data Type Conversion122' incorporates:
   *  Inport generated from: '<Root>/BusElementIn33'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion122 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_hvbd_st_hcmMaiRlyNeg();

  /* DataTypeConversion: '<Root>/Data Type Conversion123' incorporates:
   *  Inport generated from: '<Root>/BusElementIn34'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion123 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_st_obcChgSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion124' incorporates:
   *  Inport generated from: '<Root>/BusElementIn35'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion124 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_obcd_pwr_obcRlTmOutpt_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion125' incorporates:
   *  Inport generated from: '<Root>/BusElementIn36'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion125 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_st_hcmPtcDefRlyStFb();

  /* DataTypeConversion: '<Root>/Data Type Conversion126' incorporates:
   *  Inport generated from: '<Root>/BusElementIn39'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion126 =
    Rte_IRead_swc_EGYM_Step_vcsb_THSM_thmd_st_ptcConnStsFb();

  /* DataTypeConversion: '<Root>/Data Type Conversion110' incorporates:
   *  Inport generated from: '<Root>/BusElementIn26'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion110 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_st_flgFctCfgVehTyp();

  /* DataTypeConversion: '<Root>/Data Type Conversion127' incorporates:
   *  Inport generated from: '<Root>/BusElementIn38'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion127 =
    Rte_IRead_swc_EGYM_Step_vcsb_THSM_thmd_b_heaterEna3HW();

  /* DataTypeConversion: '<Root>/Data Type Conversion129' incorporates:
   *  Inport generated from: '<Root>/BusElementIn40'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion129 =
    Rte_IRead_swc_EGYM_Step_vcsb_HVSM_hvbd_b_accyWrkEnCmd();

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Inport generated from: '<Root>/BusElementIn4'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion2 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_st_flg2FctCfgVehTyp();

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Inport generated from: '<Root>/BusElementIn5'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion3 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_pwr_acwpHeatPower_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
   *  Inport generated from: '<Root>/BusElementIn6'
   */
  swc_EGYM_ARID_DEF.DataTypeConversion4 =
    Rte_IRead_swc_EGYM_Step_vcsb_THSM_thmd_st_acwpHeat();

  /* S-Function (fcgen): '<S1>/FuncCall_emg' incorporates:
   *  SubSystem: '<S1>/ACC_PowerLimitation'
   */
  swc_EGYM_ACC_PowerLimitation();

  /* End of Outputs for S-Function (fcgen): '<S1>/FuncCall_emg' */

  /* DataTypeConversion: '<Root>/Data Type Conversion102' incorporates:
   *  Inport generated from: '<Root>/BusElementIn23'
   */
  rtb_DataTypeConversion102 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_pct_tboxChgDepth();

  /* DataTypeConversion: '<Root>/Data Type Conversion103' incorporates:
   *  Inport generated from: '<Root>/BusElementIn24'
   */
  rtb_DataTypeConversion103 = Rte_IRead_swc_EGYM_Step_vcsb_HVSM_bmsd_e_modeTgt();

  /* DataTypeConversion: '<Root>/Data Type Conversion104' incorporates:
   *  Inport generated from: '<Root>/BusElementIn21'
   */
  rtb_DataTypeConversion104 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_st_tboxChgLmtSw();

  /* DataTypeConversion: '<Root>/Data Type Conversion105' incorporates:
   *  Inport generated from: '<Root>/BusElementIn22'
   */
  rtb_DataTypeConversion105 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_pct_tboxAlwChgCurrMax();

  /* DataTypeConversion: '<Root>/Data Type Conversion109' incorporates:
   *  Inport generated from: '<Root>/BusElementIn25'
   */
  rtb_DataTypeConversion109 =
    Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_b_flgFctCfgMaxChgCurr();

  /* Outport generated from: '<Root>/Out Bus Element' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion74'
   */
  Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_accd_pwr_maxPwrLim_kW((float32)
    swc_EGYM_ARID_DEF.OutportBufferForaccd_pwr_maxPwr);

  /* Outport generated from: '<Root>/Out Bus Element1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion73'
   */
  Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_accd_pwr_minPwrLim_kW((float32)
    swc_EGYM_ARID_DEF.OutportBufferForaccd_pwr_minPwr);

  /* Outport generated from: '<Root>/Out Bus Element13' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion29'
   */
  Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_accd_pwr_hvAttpwr_kW(accd_pwr_hvAttpwr_kW);

  /* Outport generated from: '<Root>/Out Bus Element14' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion78'
   */
  Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_b_dcdcEnbAllowFlg
    (egmd_b_dcdcEnbAllowFlg);

  /* Outport generated from: '<Root>/Out Bus Element15' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion79'
   */
  Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_b_ptcEnbAllowFlg(egmd_b_ptcEnbAllowFlg);

  /* Outport generated from: '<Root>/Out Bus Element16' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion80'
   */
  Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_b_acEnbAllowFlg
    (swc_EGYM_ARID_DEF.OutportBufferForegmd_b_acEnbAll);

  /* Outport generated from: '<Root>/Out Bus Element17' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion81'
   */
  Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_b_mcuEnbFlg(egmd_b_mcuEnbFlg);

  /* Outport generated from: '<Root>/Out Bus Element20' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion90'
   */
  Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_pwr_accmHvClPwrAllwd_kW
    (egmd_pwr_accmHvClPwrAllwd_kW);

  /* Outport generated from: '<Root>/Out Bus Element19' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion89'
   */
  Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_pwr_ptcHvHtPwrAllwd_kW
    (egmd_pwr_ptcHvHtPwrAllwd_kW);

  /* Outport generated from: '<Root>/Out Bus Element21' */
  Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_i_bmshAlwChgCurrMax
    (swc_EGYM_ConstB.DataTypeConversion108);

  /* Outport generated from: '<Root>/Out Bus Element22' */
  Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_pct_vcuChgDepReq
    (swc_EGYM_ConstB.DataTypeConversion107);

  /* Outport generated from: '<Root>/Out Bus Element23' */
  Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_st_vcuChgLimResp
    (swc_EGYM_ConstB.DataTypeConversion106);

  /* Outport generated from: '<Root>/Out Bus Element18' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion113'
   */
  Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_b_obcEnbAllowFlg(egmd_b_obcEnbAllowFlg);

  /* Outport generated from: '<Root>/Out Bus Element24' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion88'
   */
  Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_b_ptcRearEnbAllowFlg
    (egmd_b_ptcRearEnbAllowFlg);

  /* Outport generated from: '<Root>/Out Bus Element25' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion101'
   */
  Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_b_zeroPwrFb(egmd_b_zeroPwrFb);

  /* Outport generated from: '<Root>/Out Bus Element26' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion128'
   */
  Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_b_accyEnbFlg(egmd_b_accyEnbFlg);

  /* Outport generated from: '<Root>/Out Bus Element2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   */
  Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_pwr_acwpHeatPwrCnsAllwd
    (egmd_pwr_acwpHeatPwrCnsAllwd);
}

/* Model initialize function */
void swc_EGYM_Init(void)
{
  /* SystemInitialize for S-Function (fcgen): '<S1>/FuncCall_emg' incorporates:
   *  SubSystem: '<S1>/ACC_PowerLimitation'
   */
  swc_EG_ACC_PowerLimitation_Init();

  /* End of SystemInitialize for S-Function (fcgen): '<S1>/FuncCall_emg' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

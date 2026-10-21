/*
 * File: swc_ATAU.c
 *
 * Code generated for Simulink model 'swc_ATAU'.
 *
 * Model version                  : 1.68
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon May 11 13:37:20 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "swc_ATAU.h"
#include "rtwtypes.h"
#include <math.h>
#include "Rte_Type.h"
#include <string.h>
#include "const_ImportFromFile.h"
#include "zero_crossing_types.h"

/* Named constants for Chart: '<S45>/timed_delay' */
#define swc_ATAU_IN_OFF                ((uint8)1U)
#define swc_ATAU_IN_ON                 ((uint8)2U)
#define swc_ATAU_IN_ON_WAIT            ((uint8)3U)

/* Named constants for Chart: '<S13>/FrameInterval' */
#define swc_ATAU_IN_FrameUpdate        ((uint8)1U)
#define swc_ATAU_IN_IgOnClear          ((uint8)2U)
#define swc_ATAU_IN_NoValid            ((uint8)1U)
#define swc_ATAU_IN_Valid              ((uint8)2U)
#define swc_ATAU_IN_defualt            ((uint8)3U)

/* Exported data definition */
#define swc_ATAU_START_SEC_CONST_VOLATILE
#include "swc_ATAU_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_CAL */
const volatile boolean pmmc_b_antiAutethTestVal = true;/* Referenced by: '<S5>/Constant20' */
const volatile boolean pmmc_b_antiAutethTestflg = true;/* Referenced by: '<S5>/Constant19' */
const volatile boolean pmmc_b_testRdnNvmDataWrite = false;/* Referenced by: '<S13>/TestUse' */
const volatile boolean pmmc_b_useEskNvmDataEna = true;/* Referenced by: '<S5>/Constant9' */
const volatile boolean pmmc_b_useImmo_flg = false;/* Referenced by: '<S5>/Constant7' */
const volatile boolean pmmc_b_xcuAuthEna = false;/* Referenced by: '<S5>/Constant26' */
const volatile uint8 pmmc_n_testRdnNvmData = 0U;/* Referenced by: '<S13>/TestUse1' */
const volatile uint8 pmmc_n_useEskNvmDataDefualt[16] = { 79U, 78U, 77U, 73U, 75U,
  82U, 83U, 85U, 86U, 102U, 102U, 136U, 136U, 136U, 136U, 136U } ;/* Referenced by: '<S5>/Constant5' */

const volatile uint8 pmmc_num_antiAuthFactoryCnt = 26U;/* Referenced by: '<S15>/Constant26' */
const volatile float32 pmmc_tm_authMaxAllowTim_s = 0.8F;/* Referenced by: '<S5>/Constant17' */
const volatile float32 pmmc_tm_verifyEskVldTime_s = 0.1F;/* Referenced by: '<S15>/Constant17' */

#define swc_ATAU_STOP_SEC_CONST_VOLATILE
#include "swc_ATAU_MemMap.h"
#define swc_ATAU_START_SEC_VAR
#include "swc_ATAU_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_SIG */
boolean pmmd_b_aesEna_flg;             /* '<S5>/Logical Operator23' */
boolean pmmd_b_antiSuccess;            /* '<S5>/SR_latch2' */
boolean pmmd_b_atauIgOn;               /* '<S3>/Data Type Conversion3' */
boolean pmmd_b_errCodeScen;            /* '<S5>/Logical Operator21' */
boolean pmmd_b_existFatryMod_flg;      /* '<S15>/Relational Operator9' */
boolean pmmd_b_framUpdate;             /* '<S13>/Logical Operator3' */
boolean pmmd_b_frameAuthReq;           /* '<S13>/FrameInterval' */
boolean pmmd_b_noRespScen;             /* '<S5>/Logical Operator16' */
boolean pmmd_b_normalScen;             /* '<S5>/Logical Operator7' */
boolean pmmd_b_updateAuthFlg;          /* '<S5>/Unit Delay7' */
boolean pmmd_b_xcuAuthEna;             /* '<S3>/Data Type Conversion6' */
uint8 pmmd_num_keyOnCntRaw;            /* '<S3>/Data Type Conversion4' */
uint8 pmmd_num_keyOncnt;               /* '<S15>/Saturation' */
uint8 pmmd_st_atauRept;                /* '<S13>/FrameInterval' */
uint8 pmmd_st_atauRndNumSet;           /* '<S18>/Switch8' */
uint8 pmmd_st_authFailReason;          /* '<S5>/Switch16' */
uint8 pmmd_v_antiAuthEskBsw[16];       /* '<S3>/Data Type Conversion7' */
uint8 pmmd_v_authCodeVect[8];          /* '<S13>/Switch2' */
uint8 pmmd_v_compCodeVect[8];          /* '<S5>/Signal Conversion' */
uint8 pmmd_v_eskNumVect[16];           /* '<S15>/Switch9' */
uint8 pmmd_v_pepsCodeVect[8];          /* '<S3>/Data Type Conversion1' */
uint8 pmmd_v_xcuCodeVect[8];           /* '<S3>/Data Type Conversion5' */

#define swc_ATAU_STOP_SEC_VAR
#include "swc_ATAU_MemMap.h"

/* Constant parameters (default storage) */
const ConstP_swc_ATAU_T swc_ATAU_ConstP = {
  /* Pooled Parameter (Expression: uint8([0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]))
   * Referenced by:
   *   '<S15>/Constant1'
   *   '<S15>/Constant24'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Pooled Parameter (Expression: uint8([0 0 0 0 0 0 0 0]))
   * Referenced by:
   *   '<S3>/Constant8'
   *   '<S5>/Constant11'
   *   '<S5>/Constant21'
   *   '<S5>/Constant4'
   *   '<S5>/Constant6'
   *   '<S5>/Constant8'
   *   '<S13>/AuthReqDefualt'
   *   '<S13>/Unit Delay1'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
};

/* PublicStructure Variables for Internal Data */
ARID_DEF_swc_ATAU_T swc_ATAU_ARID_DEF;
static boolean swc_ATAU_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_ATAU_T *swc_ATAU__ARID_DEF_arg);
static void swc_ATAU_turnON_delay_Init(boolean *rty_flg_out);
static boolean swc_ATAU_turnON_delay(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, ARID_DEF_turnON_delay_swc_ATA_T *swc_ATAU__ARID_DEF_arg);
static boolean swc_ATAU_SR_latch1(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch1_swc_ATAU_T *swc_ATAU__ARID_DEF_arg);
static boolean swc_ATAU_SR_latch2(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch2_swc_ATAU_T *swc_ATAU__ARID_DEF_arg);
static boolean swc_ATAU_SR_latch3(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch3_swc_ATAU_T *swc_ATAU__ARID_DEF_arg);
static boolean swc_ATAU_SR_latch4(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch4_swc_ATAU_T *swc_ATAU__ARID_DEF_arg);
static boolean swc_ATAU_SR_latch5(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch5_swc_ATAU_T *swc_ATAU__ARID_DEF_arg);

/* Forward declaration for local functions */
static void swc_ATAU_rand(float32 r[4]);

/*
 * Output and update for atomic system:
 *    '<S15>/SR_latch'
 *    '<S5>/SR_latch'
 *    '<S5>/SR_latch6'
 */
static boolean swc_ATAU_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_ATAU_T *swc_ATAU__ARID_DEF_arg)
{
  boolean rty_flg_out_0;

  /* Logic: '<S44>/Logical Operator3' incorporates:
   *  Logic: '<S44>/Logical Operator'
   *  Logic: '<S44>/Logical Operator1'
   *  UnitDelay: '<S44>/Unit Delay'
   */
  rty_flg_out_0 = ((swc_ATAU__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) &&
                   (!rtu_flg_reset));

  /* Update for UnitDelay: '<S44>/Unit Delay' */
  swc_ATAU__ARID_DEF_arg->UnitDelay_DSTATE = rty_flg_out_0;
  return rty_flg_out_0;
}

/*
 * System initialize for atomic system:
 *    '<S15>/turnON_delay'
 *    '<S5>/turnON_delay'
 *    '<S5>/turnON_delay1'
 *    '<S5>/turnON_delay2'
 *    '<S5>/turnON_delay3'
 *    '<S5>/turnON_delay4'
 */
static void swc_ATAU_turnON_delay_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S45>/timed_delay' */
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S15>/turnON_delay'
 *    '<S5>/turnON_delay'
 *    '<S5>/turnON_delay1'
 *    '<S5>/turnON_delay2'
 *    '<S5>/turnON_delay3'
 *    '<S5>/turnON_delay4'
 */
static boolean swc_ATAU_turnON_delay(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, ARID_DEF_turnON_delay_swc_ATA_T *swc_ATAU__ARID_DEF_arg)
{
  boolean rty_flg_out_0;
  float32 rtb_t_delay_on;

  /* Saturate: '<S45>/Saturation' */
  if (rtu_t_delay_on > 1.6777216E+7F) {
    /* Saturate: '<S45>/Saturation' */
    rtb_t_delay_on = 1.6777216E+7F;
  } else if (rtu_t_delay_on < 0.0F) {
    /* Saturate: '<S45>/Saturation' */
    rtb_t_delay_on = 0.0F;
  } else {
    /* Saturate: '<S45>/Saturation' */
    rtb_t_delay_on = rtu_t_delay_on;
  }

  /* End of Saturate: '<S45>/Saturation' */

  /* Chart: '<S45>/timed_delay' incorporates:
   *  DataTypeConversion: '<S45>/Data Type Conversion'
   */
  if (swc_ATAU__ARID_DEF_arg->is_active_c8_swc_ATAU == 0U) {
    swc_ATAU__ARID_DEF_arg->is_active_c8_swc_ATAU = 1U;
    if (rtu_flg_in) {
      swc_ATAU__ARID_DEF_arg->is_c8_swc_ATAU = swc_ATAU_IN_ON;
      rty_flg_out_0 = true;
    } else {
      swc_ATAU__ARID_DEF_arg->is_c8_swc_ATAU = swc_ATAU_IN_OFF;
      rty_flg_out_0 = false;
    }
  } else {
    switch (swc_ATAU__ARID_DEF_arg->is_c8_swc_ATAU) {
     case swc_ATAU_IN_OFF:
      if (rtu_flg_in) {
        if (rtb_t_delay_on == 0.0F) {
          swc_ATAU__ARID_DEF_arg->is_c8_swc_ATAU = swc_ATAU_IN_ON;
          rty_flg_out_0 = true;
        } else {
          swc_ATAU__ARID_DEF_arg->is_c8_swc_ATAU = swc_ATAU_IN_ON_WAIT;
          swc_ATAU__ARID_DEF_arg->t_wait = rtu_t_step;
          rty_flg_out_0 = false;
        }
      } else {
        rty_flg_out_0 = false;
      }
      break;

     case swc_ATAU_IN_ON:
      if (!rtu_flg_in) {
        swc_ATAU__ARID_DEF_arg->is_c8_swc_ATAU = swc_ATAU_IN_OFF;
        rty_flg_out_0 = false;
      } else {
        rty_flg_out_0 = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtu_flg_in) {
        swc_ATAU__ARID_DEF_arg->is_c8_swc_ATAU = swc_ATAU_IN_OFF;
        rty_flg_out_0 = false;
      } else if (swc_ATAU__ARID_DEF_arg->t_wait > rtb_t_delay_on - rtu_t_step) {
        swc_ATAU__ARID_DEF_arg->is_c8_swc_ATAU = swc_ATAU_IN_ON;
        rty_flg_out_0 = true;
      } else {
        swc_ATAU__ARID_DEF_arg->t_wait += rtu_t_step;
        rty_flg_out_0 = false;
      }
      break;
    }
  }

  /* End of Chart: '<S45>/timed_delay' */
  return rty_flg_out_0;
}

/* Output and update for atomic system: '<S5>/SR_latch1' */
static boolean swc_ATAU_SR_latch1(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch1_swc_ATAU_T *swc_ATAU__ARID_DEF_arg)
{
  boolean rty_flg_out_0;

  /* Logic: '<S20>/Logical Operator3' incorporates:
   *  Logic: '<S20>/Logical Operator'
   *  Logic: '<S20>/Logical Operator1'
   *  UnitDelay: '<S20>/Unit Delay'
   */
  rty_flg_out_0 = ((swc_ATAU__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) &&
                   (!rtu_flg_reset));

  /* Update for UnitDelay: '<S20>/Unit Delay' */
  swc_ATAU__ARID_DEF_arg->UnitDelay_DSTATE = rty_flg_out_0;
  return rty_flg_out_0;
}

/* Output and update for atomic system: '<S5>/SR_latch2' */
static boolean swc_ATAU_SR_latch2(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch2_swc_ATAU_T *swc_ATAU__ARID_DEF_arg)
{
  boolean rty_flg_out_0;

  /* Logic: '<S21>/Logical Operator3' incorporates:
   *  Logic: '<S21>/Logical Operator'
   *  Logic: '<S21>/Logical Operator1'
   *  UnitDelay: '<S21>/Unit Delay'
   */
  rty_flg_out_0 = ((swc_ATAU__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) &&
                   (!rtu_flg_reset));

  /* Update for UnitDelay: '<S21>/Unit Delay' */
  swc_ATAU__ARID_DEF_arg->UnitDelay_DSTATE = rty_flg_out_0;
  return rty_flg_out_0;
}

/* Output and update for atomic system: '<S5>/SR_latch3' */
static boolean swc_ATAU_SR_latch3(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch3_swc_ATAU_T *swc_ATAU__ARID_DEF_arg)
{
  boolean rty_flg_out_0;

  /* Logic: '<S22>/Logical Operator3' incorporates:
   *  Logic: '<S22>/Logical Operator'
   *  Logic: '<S22>/Logical Operator1'
   *  UnitDelay: '<S22>/Unit Delay'
   */
  rty_flg_out_0 = ((swc_ATAU__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) &&
                   (!rtu_flg_reset));

  /* Update for UnitDelay: '<S22>/Unit Delay' */
  swc_ATAU__ARID_DEF_arg->UnitDelay_DSTATE = rty_flg_out_0;
  return rty_flg_out_0;
}

/* Output and update for atomic system: '<S5>/SR_latch4' */
static boolean swc_ATAU_SR_latch4(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch4_swc_ATAU_T *swc_ATAU__ARID_DEF_arg)
{
  boolean rty_flg_out_0;

  /* Logic: '<S23>/Logical Operator3' incorporates:
   *  Logic: '<S23>/Logical Operator'
   *  Logic: '<S23>/Logical Operator1'
   *  UnitDelay: '<S23>/Unit Delay'
   */
  rty_flg_out_0 = ((swc_ATAU__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) &&
                   (!rtu_flg_reset));

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  swc_ATAU__ARID_DEF_arg->UnitDelay_DSTATE = rty_flg_out_0;
  return rty_flg_out_0;
}

/* Output and update for atomic system: '<S5>/SR_latch5' */
static boolean swc_ATAU_SR_latch5(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch5_swc_ATAU_T *swc_ATAU__ARID_DEF_arg)
{
  boolean rty_flg_out_0;

  /* Logic: '<S24>/Logical Operator3' incorporates:
   *  Logic: '<S24>/Logical Operator'
   *  Logic: '<S24>/Logical Operator1'
   *  UnitDelay: '<S24>/Unit Delay'
   */
  rty_flg_out_0 = ((swc_ATAU__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) &&
                   (!rtu_flg_reset));

  /* Update for UnitDelay: '<S24>/Unit Delay' */
  swc_ATAU__ARID_DEF_arg->UnitDelay_DSTATE = rty_flg_out_0;
  return rty_flg_out_0;
}

/* Function for MATLAB Function: '<S55>/MATLAB Function' */
static void swc_ATAU_rand(float32 r[4])
{
  sint32 c_k;
  sint32 e_k;
  sint32 kk;
  uint32 u[2];
  switch (swc_ATAU_ARID_DEF.method) {
   case 4U:
    {
      float32 b_r;
      uint32 mti;
      uint32 y;
      e_k = (sint32)(swc_ATAU_ARID_DEF.state_h / 127773U);
      mti = (swc_ATAU_ARID_DEF.state_h - (uint32)e_k * 127773U) * 16807U;
      y = 2836U * (uint32)e_k;
      if (mti < y) {
        mti = ~(y - mti) & 2147483647U;
      } else {
        mti -= y;
      }

      b_r = (float32)mti * 4.65661287E-10F;
      if (b_r == 0.0F) {
        b_r = 1.17549435E-38F;
      } else if (b_r == 1.0F) {
        b_r = 0.99999994F;
      }

      r[0] = b_r;
      e_k = (sint32)(mti / 127773U);
      mti = (mti - (uint32)e_k * 127773U) * 16807U;
      y = 2836U * (uint32)e_k;
      if (mti < y) {
        mti = ~(y - mti) & 2147483647U;
      } else {
        mti -= y;
      }

      b_r = (float32)mti * 4.65661287E-10F;
      if (b_r == 0.0F) {
        b_r = 1.17549435E-38F;
      } else if (b_r == 1.0F) {
        b_r = 0.99999994F;
      }

      r[1] = b_r;
      e_k = (sint32)(mti / 127773U);
      mti = (mti - (uint32)e_k * 127773U) * 16807U;
      y = 2836U * (uint32)e_k;
      if (mti < y) {
        mti = ~(y - mti) & 2147483647U;
      } else {
        mti -= y;
      }

      b_r = (float32)mti * 4.65661287E-10F;
      if (b_r == 0.0F) {
        b_r = 1.17549435E-38F;
      } else if (b_r == 1.0F) {
        b_r = 0.99999994F;
      }

      r[2] = b_r;
      e_k = (sint32)(mti / 127773U);
      mti = (mti - (uint32)e_k * 127773U) * 16807U;
      y = 2836U * (uint32)e_k;
      if (mti < y) {
        mti = ~(y - mti) & 2147483647U;
      } else {
        mti -= y;
      }

      b_r = (float32)mti * 4.65661287E-10F;
      if (b_r == 0.0F) {
        b_r = 1.17549435E-38F;
      } else if (b_r == 1.0F) {
        b_r = 0.99999994F;
      }

      r[3] = b_r;
      swc_ATAU_ARID_DEF.state_h = mti;
    }
    break;

   case 5U:
    {
      float32 b_r;
      uint32 mti;
      uint32 y;
      mti = 69069U * swc_ATAU_ARID_DEF.state_l[0] + 1234567U;
      y = swc_ATAU_ARID_DEF.state_l[1] << 13 ^ swc_ATAU_ARID_DEF.state_l[1];
      y ^= y >> 17;
      y ^= y << 5;
      swc_ATAU_ARID_DEF.state_l[0] = mti;
      swc_ATAU_ARID_DEF.state_l[1] = y;
      b_r = (float32)(mti + y) * 2.32830644E-10F;
      if (b_r == 0.0F) {
        b_r = 1.17549435E-38F;
      } else if (b_r == 1.0F) {
        b_r = 0.99999994F;
      }

      r[0] = b_r;
      mti = 69069U * swc_ATAU_ARID_DEF.state_l[0] + 1234567U;
      y = swc_ATAU_ARID_DEF.state_l[1] << 13 ^ swc_ATAU_ARID_DEF.state_l[1];
      y ^= y >> 17;
      y ^= y << 5;
      swc_ATAU_ARID_DEF.state_l[0] = mti;
      swc_ATAU_ARID_DEF.state_l[1] = y;
      b_r = (float32)(mti + y) * 2.32830644E-10F;
      if (b_r == 0.0F) {
        b_r = 1.17549435E-38F;
      } else if (b_r == 1.0F) {
        b_r = 0.99999994F;
      }

      r[1] = b_r;
      mti = 69069U * swc_ATAU_ARID_DEF.state_l[0] + 1234567U;
      y = swc_ATAU_ARID_DEF.state_l[1] << 13 ^ swc_ATAU_ARID_DEF.state_l[1];
      y ^= y >> 17;
      y ^= y << 5;
      swc_ATAU_ARID_DEF.state_l[0] = mti;
      swc_ATAU_ARID_DEF.state_l[1] = y;
      b_r = (float32)(mti + y) * 2.32830644E-10F;
      if (b_r == 0.0F) {
        b_r = 1.17549435E-38F;
      } else if (b_r == 1.0F) {
        b_r = 0.99999994F;
      }

      r[2] = b_r;
      mti = 69069U * swc_ATAU_ARID_DEF.state_l[0] + 1234567U;
      y = swc_ATAU_ARID_DEF.state_l[1] << 13 ^ swc_ATAU_ARID_DEF.state_l[1];
      y ^= y >> 17;
      y ^= y << 5;
      swc_ATAU_ARID_DEF.state_l[0] = mti;
      swc_ATAU_ARID_DEF.state_l[1] = y;
      b_r = (float32)(mti + y) * 2.32830644E-10F;
      if (b_r == 0.0F) {
        b_r = 1.17549435E-38F;
      } else if (b_r == 1.0F) {
        b_r = 0.99999994F;
      }

      r[3] = b_r;
    }
    break;

   default:
    {
      for (c_k = 0; c_k < 4; c_k++) {
        float32 b_r;

        /* ========================= COPYRIGHT NOTICE ============================ */
        /*  This is a uniform (0,1) pseudorandom number generator based on:        */
        /*                                                                         */
        /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
        /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
        /*                                                                         */
        /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
        /*  All rights reserved.                                                   */
        /*                                                                         */
        /*  Redistribution and use in source and binary forms, with or without     */
        /*  modification, are permitted provided that the following conditions     */
        /*  are met:                                                               */
        /*                                                                         */
        /*    1. Redistributions of source code must retain the above copyright    */
        /*       notice, this list of conditions and the following disclaimer.     */
        /*                                                                         */
        /*    2. Redistributions in binary form must reproduce the above copyright */
        /*       notice, this list of conditions and the following disclaimer      */
        /*       in the documentation and/or other materials provided with the     */
        /*       distribution.                                                     */
        /*                                                                         */
        /*    3. The names of its contributors may not be used to endorse or       */
        /*       promote products derived from this software without specific      */
        /*       prior written permission.                                         */
        /*                                                                         */
        /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
        /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
        /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
        /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
        /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
        /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
        /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
        /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
        /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
        /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
        /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
        /*                                                                         */
        /* =============================   END   ================================= */
        sint32 exitg1;
        do {
          uint32 mti;
          exitg1 = 0;
          for (e_k = 0; e_k < 2; e_k++) {
            uint32 y;
            mti = swc_ATAU_ARID_DEF.state[624] + 1U;
            if (swc_ATAU_ARID_DEF.state[624] + 1U >= 625U) {
              for (kk = 0; kk < 227; kk++) {
                mti = (swc_ATAU_ARID_DEF.state[kk + 1] & 2147483647U) |
                  (swc_ATAU_ARID_DEF.state[kk] & 2147483648U);
                if ((mti & 1U) == 0U) {
                  mti >>= 1U;
                } else {
                  mti = mti >> 1U ^ 2567483615U;
                }

                swc_ATAU_ARID_DEF.state[kk] = swc_ATAU_ARID_DEF.state[kk + 397] ^
                  mti;
              }

              for (kk = 0; kk < 396; kk++) {
                mti = (swc_ATAU_ARID_DEF.state[kk + 227] & 2147483648U) |
                  (swc_ATAU_ARID_DEF.state[kk + 228] & 2147483647U);
                if ((mti & 1U) == 0U) {
                  mti >>= 1U;
                } else {
                  mti = mti >> 1U ^ 2567483615U;
                }

                swc_ATAU_ARID_DEF.state[kk + 227] = swc_ATAU_ARID_DEF.state[kk] ^
                  mti;
              }

              mti = (swc_ATAU_ARID_DEF.state[623] & 2147483648U) |
                (swc_ATAU_ARID_DEF.state[0] & 2147483647U);
              if ((mti & 1U) == 0U) {
                mti >>= 1U;
              } else {
                mti = mti >> 1U ^ 2567483615U;
              }

              swc_ATAU_ARID_DEF.state[623] = swc_ATAU_ARID_DEF.state[396] ^ mti;
              mti = 1U;
            }

            y = swc_ATAU_ARID_DEF.state[(sint32)mti - 1];
            swc_ATAU_ARID_DEF.state[624] = mti;
            y ^= y >> 11U;
            y ^= y << 7U & 2636928640U;
            y ^= y << 15U & 4022730752U;
            u[e_k] = y >> 18U ^ y;
          }

          mti = u[0] >> 5U;
          b_r = (float32)mti * 7.4505806E-9F;
          if (((sint32)mti == 0) && ((sint32)(u[1] >> 6U) == 0)) {
            boolean b_isvalid;
            b_isvalid = ((swc_ATAU_ARID_DEF.state[624] >= 1U) &&
                         (swc_ATAU_ARID_DEF.state[624] < 625U));
            if (b_isvalid) {
              boolean exitg2;
              b_isvalid = false;
              e_k = 1;
              exitg2 = false;
              while ((!exitg2) && (e_k < 625)) {
                if (swc_ATAU_ARID_DEF.state[e_k - 1] == 0U) {
                  e_k++;
                } else {
                  b_isvalid = true;
                  exitg2 = true;
                }
              }
            }

            if (!b_isvalid) {
              mti = 5489U;
              swc_ATAU_ARID_DEF.state[0] = 5489U;
              for (e_k = 0; e_k < 623; e_k++) {
                mti = ((mti >> 30U ^ mti) * 1812433253U + (uint32)e_k) + 1U;
                swc_ATAU_ARID_DEF.state[e_k + 1] = mti;
              }

              swc_ATAU_ARID_DEF.state[624] = 624U;
            }
          } else {
            exitg1 = 1;
          }
        } while (exitg1 == 0);

        if (b_r < 5.96046448E-8F) {
          b_r = 5.96046448E-8F;
        } else if (b_r > 0.99999994F) {
          b_r = 0.99999994F;
        }

        r[c_k] = b_r;
      }
    }
    break;
  }
}

/* Model step function */
void swc_ATAU_Step(void)
{
  /* local block i/o variables */
  uint8 rtb_SignalConversion3;
  uint8 rtb_CCaller[8];
  uint8 rtb_Switch3;
  boolean rtb_Switch10;
  boolean rtb_IgOnDual;
  boolean rtb_LogicalOperator50;
  boolean rtb_UnitDelay3_f;
  boolean rtb_LogicalOperator5;
  boolean rtb_Switch2_d;
  boolean rtb_LogicalOperator4_p;
  boolean rtb_LogicalOperator6;
  boolean rtb_Compare_n;
  boolean rtb_LogicalOperator30;
  boolean rtb_Compare_d;
  boolean rtb_Compare_j;
  boolean rtb_LogicalOperator37;
  boolean rtb_Switch3_b;
  boolean rtb_LogicalOperator25;
  boolean rtb_SignalConversion1;
  boolean rtb_Switch1_i;
  boolean rtb_LogicalOperator8;
  boolean rtb_LogicalOperator36;
  boolean rtb_flg_out;
  boolean rtb_flg_out_g;
  boolean rtb_flg_out_d;
  boolean rtb_flg_out_n;
  boolean rtb_flg_out_p;
  boolean rtb_flg_out_m;
  boolean rtb_LogicalOperator3_g;
  boolean rtb_LogicalOperator3_gl;
  boolean rtb_LogicalOperator3_n;
  boolean rtb_UnitDelay;
  sint32 i;
  float32 b_a[4];
  KeyAuthStatus rtb_Switch8_e;
  uint8 rtb_SignalConversion[16];
  uint8 rtb_TmpSignalConversionAtSFunct[16];
  uint8 rtb_UnitDelay1_f[8];
  uint8 rtb_DataTypeConversion2;
  uint8 rtb_Switch8;
  uint8 rtb_Switch8_h;
  boolean rtb_RelationalOperator3[16];
  boolean rtb_RelationalOperator_a[8];
  boolean rtb_Compare;
  boolean rtb_Compare_o;
  boolean rtb_FixPtRelationalOperator;
  boolean rtb_LogicalOperator17;
  boolean rtb_LogicalOperator1_l;
  boolean rtb_LogicalOperator3;
  boolean rtb_RelationalOperator;
  boolean tmp;
  boolean tmp_0;
  boolean tmp_1;
  boolean tmp_2;
  boolean tmp_4;
  for (i = 0; i < 16; i++) {
    /* SignalConversion generated from: '<S40>/ SFunction ' incorporates:
     *  SignalConversion generated from: '<S3>/C Caller'
     */
    rtb_TmpSignalConversionAtSFunct[i] = 0U;
  }

  /* CCaller: '<S3>/C Caller' incorporates:
   *  SignalConversion generated from: '<S40>/ SFunction '
   */
  mBSW_Get_PMS_ESK(&rtb_TmpSignalConversionAtSFunct[0]);
  for (i = 0; i < 16; i++) {
    /* DataTypeConversion: '<S3>/Data Type Conversion7' */
    pmmd_v_antiAuthEskBsw[i] = rtb_TmpSignalConversionAtSFunct[i];
  }

  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  CCaller: '<S3>/C Caller2'
   */
  rtb_DataTypeConversion2 = mBSW_NvmRead_Rdn();
  for (i = 0; i < 8; i++) {
    /* UnitDelay: '<S13>/Unit Delay1' incorporates:
     *  SignalConversion generated from: '<S3>/C Caller1'
     */
    rtb_UnitDelay1_f[i] = 0U;
  }

  /* CCaller: '<S3>/C Caller1' incorporates:
   *  UnitDelay: '<S13>/Unit Delay1'
   */
  mBSW_Get_PEPS_IMMOCode(&rtb_UnitDelay1_f[0]);
  for (i = 0; i < 8; i++) {
    /* DataTypeConversion: '<S3>/Data Type Conversion1' */
    pmmd_v_pepsCodeVect[i] = rtb_UnitDelay1_f[i];
  }

  /* DataTypeConversion: '<S3>/Data Type Conversion4' incorporates:
   *  CCaller: '<S3>/C Caller3'
   *  SignalConversion: '<S4>/Signal Conversion2'
   */
  pmmd_num_keyOnCntRaw = mBSW_NvmRead_KeyOnCnt();

  /* DataTypeConversion: '<S3>/Data Type Conversion3' incorporates:
   *  Inport generated from: '<Root>/In Bus Element6'
   */
  pmmd_b_atauIgOn = Rte_IRead_swc_ATAU_Step_vcib_VCIP_pmmd_b_ignOn();
  for (i = 0; i < 8; i++) {
    /* DataTypeConversion: '<S3>/Data Type Conversion5' incorporates:
     *  Constant: '<S3>/Constant8'
     */
    pmmd_v_xcuCodeVect[i] = swc_ATAU_ConstP.pooled15[i];
  }

  /* RelationalOperator: '<S43>/Relational Operator' incorporates:
   *  UnitDelay: '<S43>/Unit Delay1'
   */
  rtb_RelationalOperator = (pmmd_num_keyOnCntRaw !=
    swc_ATAU_ARID_DEF.UnitDelay1_DSTATE);

  /* Switch: '<S5>/Switch10' incorporates:
   *  Constant: '<S5>/Constant19'
   */
  if (pmmc_b_antiAutethTestflg) {
    /* Switch: '<S5>/Switch10' incorporates:
     *  Constant: '<S5>/Constant20'
     */
    rtb_Switch10 = pmmc_b_antiAutethTestVal;
  } else {
    /* Switch: '<S5>/Switch10' */
    rtb_Switch10 = pmmd_b_atauIgOn;
  }

  /* End of Switch: '<S5>/Switch10' */

  /* Outputs for Atomic SubSystem: '<S5>/turnON_delay4' */
  /* Constant: '<S5>/Constant27' incorporates:
   *  Constant: '<S5>/Constant28'
   */
  rtb_flg_out = swc_ATAU_turnON_delay(rtb_Switch10, 0.1F, 0.01F,
    &swc_ATAU_ARID_DEF.ARID_DEF_turnON_delay4);

  /* End of Outputs for SubSystem: '<S5>/turnON_delay4' */

  /* Logic: '<S20>/Logical Operator3' incorporates:
   *  Constant: '<S5>/Constant26'
   *  Logic: '<S5>/Logical Operator48'
   */
  rtb_LogicalOperator3_gl = (pmmc_b_xcuAuthEna || pmmd_b_xcuAuthEna);

  /* Switch: '<S5>/Switch15' */
  if (rtb_LogicalOperator3_gl) {
    /* Switch: '<S5>/Switch15' */
    rtb_IgOnDual = rtb_flg_out;
  } else {
    /* Switch: '<S5>/Switch15' */
    rtb_IgOnDual = rtb_Switch10;
  }

  /* End of Switch: '<S5>/Switch15' */

  /* UnitDelay: '<S16>/Unit Delay' incorporates:
   *  UnitDelay: '<S46>/Unit Delay'
   */
  rtb_UnitDelay = swc_ATAU_ARID_DEF.UnitDelay_DSTATE_p;

  /* Switch: '<S43>/Switch8' incorporates:
   *  Logic: '<S43>/Logical Operator4'
   *  Logic: '<S46>/Logical Operator'
   *  Logic: '<S46>/Logical Operator1'
   */
  if (rtb_RelationalOperator || (rtb_IgOnDual && (!rtb_UnitDelay))) {
    /* Switch: '<S43>/Switch9' incorporates:
     *  Switch: '<S43>/Switch1'
     */
    if (rtb_RelationalOperator) {
      /* Switch: '<S43>/Switch8' incorporates:
       *  Switch: '<S43>/Switch9'
       */
      rtb_Switch8 = pmmd_num_keyOnCntRaw;
    } else {
      if (rtb_IgOnDual) {
        /* Switch: '<S43>/Switch1' incorporates:
         *  Constant: '<S43>/Constant1'
         */
        rtb_Switch8 = ((uint8)1U);
      } else {
        /* Switch: '<S43>/Switch1' incorporates:
         *  Constant: '<S43>/Constant2'
         */
        rtb_Switch8 = ((uint8)0U);
      }

      /* Switch: '<S43>/Switch8' incorporates:
       *  Sum: '<S43>/Sum2'
       *  Switch: '<S43>/Switch1'
       *  Switch: '<S43>/Switch9'
       *  UnitDelay: '<S43>/Unit Delay3'
       */
      rtb_Switch8 = (uint8)((uint32)rtb_Switch8 +
                            swc_ATAU_ARID_DEF.UnitDelay3_DSTATE);
    }

    /* End of Switch: '<S43>/Switch9' */
  } else {
    /* Switch: '<S43>/Switch8' incorporates:
     *  UnitDelay: '<S43>/Unit Delay2'
     */
    rtb_Switch8 = swc_ATAU_ARID_DEF.UnitDelay2_DSTATE;
  }

  /* End of Switch: '<S43>/Switch8' */

  /* Saturate: '<S15>/Saturation' */
  if (rtb_Switch8 <= ((uint8)254U)) {
    /* Saturate: '<S15>/Saturation' */
    pmmd_num_keyOncnt = rtb_Switch8;
  } else {
    /* Saturate: '<S15>/Saturation' */
    pmmd_num_keyOncnt = ((uint8)254U);
  }

  /* End of Saturate: '<S15>/Saturation' */

  /* RelationalOperator: '<S15>/Relational Operator9' incorporates:
   *  Constant: '<S15>/Constant26'
   */
  pmmd_b_existFatryMod_flg = (pmmd_num_keyOncnt > pmmc_num_antiAuthFactoryCnt);
  for (i = 0; i < 16; i++) {
    /* Switch: '<S5>/Switch1' incorporates:
     *  Constant: '<S5>/Constant9'
     */
    if (pmmc_b_useEskNvmDataEna) {
      /* SignalConversion generated from: '<S40>/ SFunction ' */
      rtb_TmpSignalConversionAtSFunct[i] = pmmd_v_antiAuthEskBsw[i];
    } else {
      /* SignalConversion generated from: '<S40>/ SFunction ' incorporates:
       *  Constant: '<S5>/Constant5'
       */
      rtb_TmpSignalConversionAtSFunct[i] = pmmc_n_useEskNvmDataDefualt[i];
    }

    /* End of Switch: '<S5>/Switch1' */
  }

  for (i = 0; i < 16; i++) {
    /* RelationalOperator: '<S15>/Relational Operator3' incorporates:
     *  Constant: '<S15>/Constant24'
     */
    rtb_RelationalOperator3[i] = (rtb_TmpSignalConversionAtSFunct[i] !=
      swc_ATAU_ConstP.pooled11[i]);
  }

  /* Logic: '<S15>/Logical Operator24' */
  rtb_RelationalOperator = rtb_RelationalOperator3[0];
  for (i = 0; i < 15; i++) {
    rtb_RelationalOperator = (rtb_RelationalOperator ||
      rtb_RelationalOperator3[i + 1]);
  }

  /* Logic: '<S15>/Logical Operator3' incorporates:
   *  Logic: '<S15>/Logical Operator1'
   *  Logic: '<S15>/Logical Operator24'
   */
  rtb_LogicalOperator3 = ((!pmmd_b_existFatryMod_flg) || rtb_RelationalOperator);
  for (i = 0; i < 16; i++) {
    /* Switch: '<S15>/Switch9' incorporates:
     *  Logic: '<S15>/Logical Operator24'
     */
    if (rtb_RelationalOperator) {
      /* Switch: '<S15>/Switch9' */
      pmmd_v_eskNumVect[i] = rtb_TmpSignalConversionAtSFunct[i];
    } else {
      /* Switch: '<S15>/Switch9' incorporates:
       *  Constant: '<S15>/Constant1'
       */
      pmmd_v_eskNumVect[i] = swc_ATAU_ConstP.pooled11[i];
    }

    /* End of Switch: '<S15>/Switch9' */
  }

  /* UnitDelay: '<S16>/Unit Delay' incorporates:
   *  UnitDelay: '<S52>/Delay Input1'
   *
   * Block description for '<S52>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_UnitDelay = swc_ATAU_ARID_DEF.DelayInput1_DSTATE_g;

  /* RelationalOperator: '<S52>/FixPt Relational Operator' */
  rtb_FixPtRelationalOperator = ((sint32)rtb_IgOnDual < (sint32)rtb_UnitDelay);

  /* RelationalOperator: '<S51>/Compare' incorporates:
   *  Constant: '<S51>/Constant'
   *  UnitDelay: '<S17>/Unit Delay1'
   */
  rtb_Compare = (swc_ATAU_ARID_DEF.UnitDelay1_DSTATE_k == ((uint8)255U));

  /* Delay: '<S17>/Resettable Delay' incorporates:
   *  Constant: '<S17>/Constant3'
   */
  swc_ATAU_ARID_DEF.icLoad = ((rtb_Compare &&
    (swc_ATAU_ARID_DEF.ResettableDelay_Reset_ZCE != POS_ZCSIG)) ||
    swc_ATAU_ARID_DEF.icLoad);
  swc_ATAU_ARID_DEF.ResettableDelay_Reset_ZCE = rtb_Compare;
  if (swc_ATAU_ARID_DEF.icLoad) {
    swc_ATAU_ARID_DEF.ResettableDelay_DSTATE = ((uint8)0U);
  }

  /* Switch: '<S17>/Switch8' */
  if (rtb_FixPtRelationalOperator) {
    /* Switch: '<S17>/Switch8' incorporates:
     *  Constant: '<S17>/Constant1'
     *  Sum: '<S17>/Sum2'
     *  Switch: '<S17>/Switch2'
     *  UnitDelay: '<S17>/Unit Delay2'
     */
    rtb_Switch8_h = (uint8)((uint32)swc_ATAU_ARID_DEF.UnitDelay2_DSTATE_n +
      ((uint8)1U));
  } else {
    /* Switch: '<S17>/Switch8' incorporates:
     *  Delay: '<S17>/Resettable Delay'
     */
    rtb_Switch8_h = swc_ATAU_ARID_DEF.ResettableDelay_DSTATE;
  }

  /* End of Switch: '<S17>/Switch8' */

  /* UnitDelay: '<S5>/Unit Delay7' */
  pmmd_b_updateAuthFlg = swc_ATAU_ARID_DEF.UnitDelay7_DSTATE;

  /* Logic: '<S5>/Logical Operator50' */
  rtb_LogicalOperator50 = !pmmd_b_updateAuthFlg;

  /* Outputs for Atomic SubSystem: '<S5>/SR_latch6' */
  rtb_LogicalOperator3_n = swc_ATAU_SR_latch(pmmd_b_updateAuthFlg,
    rtb_LogicalOperator50, &swc_ATAU_ARID_DEF.ARID_DEF_SR_latch6);

  /* End of Outputs for SubSystem: '<S5>/SR_latch6' */

  /* UnitDelay: '<S16>/Unit Delay' incorporates:
   *  UnitDelay: '<S54>/Delay Input1'
   *
   * Block description for '<S54>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_UnitDelay = swc_ATAU_ARID_DEF.DelayInput1_DSTATE_d;

  /* RelationalOperator: '<S54>/FixPt Relational Operator' */
  rtb_FixPtRelationalOperator = ((sint32)rtb_IgOnDual < (sint32)rtb_UnitDelay);

  /* RelationalOperator: '<S56>/Relational Operator' incorporates:
   *  DataTypeConversion: '<S56>/Data Type Conversion'
   *  UnitDelay: '<S56>/Unit Delay'
   */
  rtb_Compare = (rtb_DataTypeConversion2 != swc_ATAU_ARID_DEF.UnitDelay_DSTATE);

  /* RelationalOperator: '<S53>/Compare' incorporates:
   *  Constant: '<S53>/Constant'
   *  UnitDelay: '<S18>/Unit Delay1'
   */
  rtb_Compare_o = (swc_ATAU_ARID_DEF.UnitDelay1_DSTATE_a >= ((uint8)255U));

  /* Delay: '<S18>/Resettable Delay4' incorporates:
   *  Constant: '<S18>/Constant6'
   */
  swc_ATAU_ARID_DEF.icLoad_p = ((rtb_Compare_o &&
    (swc_ATAU_ARID_DEF.ResettableDelay4_Reset_ZCE != POS_ZCSIG)) ||
    swc_ATAU_ARID_DEF.icLoad_p);
  swc_ATAU_ARID_DEF.ResettableDelay4_Reset_ZCE = rtb_Compare_o;
  if (swc_ATAU_ARID_DEF.icLoad_p) {
    swc_ATAU_ARID_DEF.ResettableDelay4_DSTATE = ((uint8)0U);
  }

  /* Switch: '<S18>/Switch8' incorporates:
   *  Logic: '<S56>/Logical Operator'
   *  Logic: '<S56>/Logical Operator1'
   *  RelationalOperator: '<S58>/FixPt Relational Operator'
   *  Switch: '<S56>/Switch1'
   *  UnitDelay: '<S58>/Delay Input1'
   *
   * Block description for '<S58>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (rtb_FixPtRelationalOperator) {
    /* Switch: '<S18>/Switch8' incorporates:
     *  Constant: '<S18>/Constant1'
     *  Sum: '<S18>/Sum2'
     *  Switch: '<S18>/Switch2'
     *  UnitDelay: '<S18>/Unit Delay2'
     */
    pmmd_st_atauRndNumSet = (uint8)((uint32)
      swc_ATAU_ARID_DEF.UnitDelay2_DSTATE_m + ((uint8)1U));
  } else if (((sint32)rtb_Compare > (sint32)
              swc_ATAU_ARID_DEF.DelayInput1_DSTATE_a) && (!rtb_Compare_o)) {
    /* Switch: '<S56>/Switch1' incorporates:
     *  DataTypeConversion: '<S56>/Data Type Conversion'
     *  Switch: '<S18>/Switch8'
     */
    pmmd_st_atauRndNumSet = rtb_DataTypeConversion2;
  } else {
    /* Switch: '<S18>/Switch8' incorporates:
     *  Delay: '<S18>/Resettable Delay4'
     */
    pmmd_st_atauRndNumSet = swc_ATAU_ARID_DEF.ResettableDelay4_DSTATE;
  }

  /* End of Switch: '<S18>/Switch8' */

  /* Outputs for Enabled SubSystem: '<S18>/Subsystem' incorporates:
   *  EnablePort: '<S55>/Enable'
   */
  /* RelationalOperator: '<S18>/Relational Operator' incorporates:
   *  UnitDelay: '<S18>/Unit Delay'
   */
  if (pmmd_st_atauRndNumSet != swc_ATAU_ARID_DEF.UnitDelay_DSTATE_c) {
    float32 tmp_3;

    /* MATLAB Function: '<S55>/MATLAB Function' */
    i = pmmd_st_atauRndNumSet;
    switch (swc_ATAU_ARID_DEF.method) {
     case 7U:
      {
        uint32 r;
        if (pmmd_st_atauRndNumSet == 0) {
          i = 5489;
        }

        r = (uint32)i;
        swc_ATAU_ARID_DEF.state[0] = (uint32)i;
        for (i = 0; i < 623; i++) {
          r = ((r >> 30U ^ r) * 1812433253U + (uint32)i) + 1U;
          swc_ATAU_ARID_DEF.state[i + 1] = r;
        }

        swc_ATAU_ARID_DEF.state[624] = 624U;
      }
      break;

     case 5U:
      swc_ATAU_ARID_DEF.state_l[0] = 362436069U;
      swc_ATAU_ARID_DEF.state_l[1] = pmmd_st_atauRndNumSet;
      if (swc_ATAU_ARID_DEF.state_l[1] == 0U) {
        swc_ATAU_ARID_DEF.state_l[1] = 521288629U;
      }
      break;

     default:
      {
        uint32 r;
        r = (uint32)pmmd_st_atauRndNumSet << 16U;
        if ((sint32)r < 1) {
          r = 1144108930U;
        }

        swc_ATAU_ARID_DEF.state_h = r;
      }
      break;
    }

    swc_ATAU_rand(b_a);
    tmp_3 = roundf(b_a[0] * 255.0F);
    if (tmp_3 < 256.0F) {
      if (tmp_3 >= 0.0F) {
        swc_ATAU_ARID_DEF.output[0] = (uint8)tmp_3;
      } else {
        swc_ATAU_ARID_DEF.output[0] = 0U;
      }
    } else {
      swc_ATAU_ARID_DEF.output[0] = MAX_uint8_T;
    }

    tmp_3 = roundf(b_a[1] * 255.0F);
    if (tmp_3 < 256.0F) {
      if (tmp_3 >= 0.0F) {
        swc_ATAU_ARID_DEF.output[1] = (uint8)tmp_3;
      } else {
        swc_ATAU_ARID_DEF.output[1] = 0U;
      }
    } else {
      swc_ATAU_ARID_DEF.output[1] = MAX_uint8_T;
    }

    tmp_3 = roundf(b_a[2] * 255.0F);
    if (tmp_3 < 256.0F) {
      if (tmp_3 >= 0.0F) {
        swc_ATAU_ARID_DEF.output[2] = (uint8)tmp_3;
      } else {
        swc_ATAU_ARID_DEF.output[2] = 0U;
      }
    } else {
      swc_ATAU_ARID_DEF.output[2] = MAX_uint8_T;
    }

    tmp_3 = roundf(b_a[3] * 255.0F);
    if (tmp_3 < 256.0F) {
      if (tmp_3 >= 0.0F) {
        swc_ATAU_ARID_DEF.output[3] = (uint8)tmp_3;
      } else {
        swc_ATAU_ARID_DEF.output[3] = 0U;
      }
    } else {
      swc_ATAU_ARID_DEF.output[3] = MAX_uint8_T;
    }

    /* End of MATLAB Function: '<S55>/MATLAB Function' */
  }

  /* End of RelationalOperator: '<S18>/Relational Operator' */
  /* End of Outputs for SubSystem: '<S18>/Subsystem' */

  /* UnitDelay: '<S5>/Unit Delay3' */
  rtb_UnitDelay3_f = swc_ATAU_ARID_DEF.UnitDelay3_DSTATE_o;

  /* Logic: '<S5>/Logical Operator5' */
  tmp_4 = !rtb_IgOnDual;

  /* Logic: '<S5>/Logical Operator5' */
  rtb_LogicalOperator5 = tmp_4;

  /* Outputs for Atomic SubSystem: '<S5>/SR_latch' */
  rtb_UnitDelay = swc_ATAU_SR_latch(rtb_UnitDelay3_f, rtb_LogicalOperator5,
    &swc_ATAU_ARID_DEF.ARID_DEF_SR_latch);

  /* End of Outputs for SubSystem: '<S5>/SR_latch' */

  /* Logic: '<S5>/Logical Operator4' */
  rtb_Compare_o = !rtb_UnitDelay;

  /* Outputs for Atomic SubSystem: '<S15>/turnON_delay' */
  /* Constant: '<S15>/Constant17' incorporates:
   *  Constant: '<S15>/Constant18'
   */
  rtb_flg_out_m = swc_ATAU_turnON_delay(rtb_IgOnDual, pmmc_tm_verifyEskVldTime_s,
    0.01F, &swc_ATAU_ARID_DEF.ARID_DEF_turnON_delay_m);

  /* End of Outputs for SubSystem: '<S15>/turnON_delay' */

  /* Switch: '<S15>/Switch1' */
  if (rtb_flg_out_m) {
    /* UnitDelay: '<S16>/Unit Delay' incorporates:
     *  Constant: '<S15>/Constant10'
     */
    rtb_UnitDelay = true;
  } else {
    /* UnitDelay: '<S16>/Unit Delay' incorporates:
     *  Constant: '<S15>/Constant2'
     */
    rtb_UnitDelay = false;
  }

  /* End of Switch: '<S15>/Switch1' */

  /* Switch: '<S15>/Switch2' */
  if (rtb_UnitDelay) {
    /* Switch: '<S15>/Switch2' */
    rtb_Switch2_d = rtb_LogicalOperator3;
  } else {
    /* Switch: '<S15>/Switch2' incorporates:
     *  Logic: '<S15>/Logical Operator24'
     */
    rtb_Switch2_d = rtb_RelationalOperator;
  }

  /* End of Switch: '<S15>/Switch2' */

  /* Logic: '<S15>/Logical Operator4' incorporates:
   *  Logic: '<S5>/Logical Operator5'
   */
  rtb_LogicalOperator4_p = tmp_4;

  /* Outputs for Atomic SubSystem: '<S15>/SR_latch' */
  rtb_UnitDelay = swc_ATAU_SR_latch(rtb_Switch2_d, rtb_LogicalOperator4_p,
    &swc_ATAU_ARID_DEF.ARID_DEF_SR_latch_c);

  /* End of Outputs for SubSystem: '<S15>/SR_latch' */

  /* Logic: '<S5>/Logical Operator23' incorporates:
   *  Logic: '<S5>/Logical Operator2'
   */
  pmmd_b_aesEna_flg = (rtb_IgOnDual && (rtb_Compare_o || pmmd_b_updateAuthFlg) &&
                       rtb_UnitDelay);

  /* Outputs for Enabled SubSystem: '<S5>/AES_Algorithm' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (pmmd_b_aesEna_flg) {
    if (!swc_ATAU_ARID_DEF.AES_Algorithm_MODE) {
      /* SystemReset for Chart: '<S36>/AES_Cal' */
      swc_ATAU_ARID_DEF.is_active_c3_swc_ATAU = 0U;

      /* SystemReset for Chart: '<S37>/AES_Cal' */
      swc_ATAU_ARID_DEF.is_active_c4_swc_ATAU = 0U;
      for (i = 0; i < 16; i++) {
        swc_ATAU_ARID_DEF.out[i] = 0U;
      }

      /* End of SystemReset for Chart: '<S37>/AES_Cal' */
      swc_ATAU_ARID_DEF.AES_Algorithm_MODE = true;
    }

    for (i = 0; i < 16; i++) {
      /* SignalConversion: '<S38>/Signal Conversion' */
      rtb_SignalConversion[i] = pmmd_v_eskNumVect[i];
    }

    /* Switch: '<S5>/Switch17' */
    if (rtb_LogicalOperator3_n) {
      /* DataTypeConversion: '<S38>/Data Type Conversion' incorporates:
       *  Constant: '<S5>/Fix_Rdn1'
       */
      swc_ATAU_ARID_DEF.DataTypeConversion[0] = InitRand[0];
      swc_ATAU_ARID_DEF.DataTypeConversion[1] = InitRand[1];
      swc_ATAU_ARID_DEF.DataTypeConversion[2] = InitRand[2];
    } else {
      /* DataTypeConversion: '<S38>/Data Type Conversion' */
      swc_ATAU_ARID_DEF.DataTypeConversion[0] = swc_ATAU_ARID_DEF.output[0];
      swc_ATAU_ARID_DEF.DataTypeConversion[1] = swc_ATAU_ARID_DEF.output[1];
      swc_ATAU_ARID_DEF.DataTypeConversion[2] = swc_ATAU_ARID_DEF.output[2];
    }

    if (rtb_LogicalOperator3_n) {
      /* DataTypeConversion: '<S38>/Data Type Conversion' */
      swc_ATAU_ARID_DEF.DataTypeConversion[3] = rtb_Switch8_h;
    } else {
      /* DataTypeConversion: '<S38>/Data Type Conversion' */
      swc_ATAU_ARID_DEF.DataTypeConversion[3] = swc_ATAU_ARID_DEF.output[3];
    }

    /* End of Switch: '<S5>/Switch17' */

    /* SignalConversion generated from: '<S40>/ SFunction ' incorporates:
     *  Chart: '<S36>/AES_Cal'
     *  Constant: '<S7>/CC64'
     *  SignalConversion generated from: '<S39>/ SFunction '
     */
    rtb_TmpSignalConversionAtSFunct[0] = swc_ATAU_ARID_DEF.DataTypeConversion[0];
    rtb_TmpSignalConversionAtSFunct[1] = swc_ATAU_ARID_DEF.DataTypeConversion[1];
    rtb_TmpSignalConversionAtSFunct[2] = swc_ATAU_ARID_DEF.DataTypeConversion[2];
    rtb_TmpSignalConversionAtSFunct[3] = swc_ATAU_ARID_DEF.DataTypeConversion[3];
    rtb_TmpSignalConversionAtSFunct[4] = pmmd_v_eskNumVect[0];
    rtb_TmpSignalConversionAtSFunct[5] = pmmd_v_eskNumVect[1];
    rtb_TmpSignalConversionAtSFunct[6] = pmmd_v_eskNumVect[2];
    rtb_TmpSignalConversionAtSFunct[7] = pmmd_v_eskNumVect[3];
    for (i = 0; i < 8; i++) {
      rtb_TmpSignalConversionAtSFunct[i + 8] = CC64[i];
    }

    /* Chart: '<S36>/AES_Cal' incorporates:
     *  SignalConversion: '<S38>/Signal Conversion'
     *  SignalConversion generated from: '<S40>/ SFunction '
     */
    if (swc_ATAU_ARID_DEF.is_active_c3_swc_ATAU == 0U) {
      swc_ATAU_ARID_DEF.is_active_c3_swc_ATAU = 1U;
      AES_InitKey(&rtb_SignalConversion[0]);
      AES_Encrypt(&rtb_TmpSignalConversionAtSFunct[0]);
      for (i = 0; i < 16; i++) {
        rtb_SignalConversion[i] = rtb_TmpSignalConversionAtSFunct[i];
      }
    } else {
      AES_InitKey(&rtb_SignalConversion[0]);
      AES_Encrypt(&rtb_TmpSignalConversionAtSFunct[0]);
      for (i = 0; i < 16; i++) {
        rtb_SignalConversion[i] = rtb_TmpSignalConversionAtSFunct[i];
      }
    }

    for (i = 0; i < 8; i++) {
      /* SignalConversion generated from: '<S40>/ SFunction ' incorporates:
       *  Chart: '<S37>/AES_Cal'
       *  Constant: '<S7>/CC64_1'
       */
      rtb_TmpSignalConversionAtSFunct[i] = CC64[i];
    }

    for (i = 0; i < 8; i++) {
      /* SignalConversion generated from: '<S40>/ SFunction ' incorporates:
       *  Chart: '<S37>/AES_Cal'
       */
      rtb_TmpSignalConversionAtSFunct[i + 8] = rtb_SignalConversion[i + 8];
    }

    /* Chart: '<S37>/AES_Cal' incorporates:
     *  SignalConversion generated from: '<S40>/ SFunction '
     *  Switch: '<S15>/Switch9'
     */
    if (swc_ATAU_ARID_DEF.is_active_c4_swc_ATAU == 0U) {
      swc_ATAU_ARID_DEF.is_active_c4_swc_ATAU = 1U;
      AES_InitKey(&pmmd_v_eskNumVect[0]);
      AES_Encrypt(&rtb_TmpSignalConversionAtSFunct[0]);
      for (i = 0; i < 16; i++) {
        swc_ATAU_ARID_DEF.out[i] = rtb_TmpSignalConversionAtSFunct[i];
      }
    } else {
      AES_InitKey(&pmmd_v_eskNumVect[0]);
      AES_Encrypt(&rtb_TmpSignalConversionAtSFunct[0]);
      for (i = 0; i < 16; i++) {
        swc_ATAU_ARID_DEF.out[i] = rtb_TmpSignalConversionAtSFunct[i];
      }
    }

    /* SignalConversion generated from: '<S7>/AuthCode' */
    swc_ATAU_ARID_DEF.OutportBufferForAuthCode[0] =
      swc_ATAU_ARID_DEF.DataTypeConversion[0];
    swc_ATAU_ARID_DEF.OutportBufferForAuthCode[1] =
      swc_ATAU_ARID_DEF.DataTypeConversion[1];
    swc_ATAU_ARID_DEF.OutportBufferForAuthCode[2] =
      swc_ATAU_ARID_DEF.DataTypeConversion[2];
    swc_ATAU_ARID_DEF.OutportBufferForAuthCode[3] =
      swc_ATAU_ARID_DEF.DataTypeConversion[3];
    swc_ATAU_ARID_DEF.OutportBufferForAuthCode[4] = rtb_SignalConversion[0];
    swc_ATAU_ARID_DEF.OutportBufferForAuthCode[5] = rtb_SignalConversion[1];
    swc_ATAU_ARID_DEF.OutportBufferForAuthCode[6] = rtb_SignalConversion[2];
    swc_ATAU_ARID_DEF.OutportBufferForAuthCode[7] = rtb_SignalConversion[3];
  } else {
    swc_ATAU_ARID_DEF.AES_Algorithm_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S5>/AES_Algorithm' */
  for (i = 0; i < 8; i++) {
    /* UnitDelay: '<S13>/Unit Delay1' */
    rtb_UnitDelay1_f[i] = swc_ATAU_ARID_DEF.UnitDelay1_DSTATE_h[i];
  }

  for (i = 0; i < 8; i++) {
    /* RelationalOperator: '<S13>/Relational Operator' incorporates:
     *  SignalConversion generated from: '<S7>/AuthCode'
     *  UnitDelay: '<S13>/Unit Delay1'
     */
    rtb_RelationalOperator_a[i] = (swc_ATAU_ARID_DEF.OutportBufferForAuthCode[i]
      != rtb_UnitDelay1_f[i]);
  }

  /* Logic: '<S13>/Logical Operator' incorporates:
   *  RelationalOperator: '<S13>/Relational Operator'
   */
  rtb_Compare_o = rtb_RelationalOperator_a[0];
  for (i = 0; i < 7; i++) {
    rtb_Compare_o = (rtb_Compare_o || rtb_RelationalOperator_a[i + 1]);
  }

  /* Logic: '<S13>/Logical Operator3' incorporates:
   *  Logic: '<S13>/Logical Operator'
   */
  pmmd_b_framUpdate = (rtb_Compare_o && rtb_IgOnDual);

  /* UnitDelay: '<S16>/Unit Delay' incorporates:
   *  UnitDelay: '<S5>/Unit Delay11'
   */
  rtb_UnitDelay = swc_ATAU_ARID_DEF.UnitDelay11_DSTATE;

  /* Logic: '<S5>/Logical Operator6' */
  rtb_LogicalOperator6 = !rtb_IgOnDual;

  /* Outputs for Atomic SubSystem: '<S5>/SR_latch5' */
  rtb_LogicalOperator3_n = swc_ATAU_SR_latch5(pmmd_b_updateAuthFlg,
    rtb_LogicalOperator6, &swc_ATAU_ARID_DEF.ARID_DEF_SR_latch5);

  /* End of Outputs for SubSystem: '<S5>/SR_latch5' */

  /* Switch: '<S5>/Switch6' incorporates:
   *  Logic: '<S5>/Logical Operator24'
   */
  if (rtb_UnitDelay || rtb_LogicalOperator3_n) {
    /* UnitDelay: '<S16>/Unit Delay' incorporates:
     *  Constant: '<S5>/Constant22'
     */
    rtb_UnitDelay = false;
  } else {
    /* UnitDelay: '<S16>/Unit Delay' incorporates:
     *  Logic: '<S5>/Logical Operator20'
     *  UnitDelay: '<S5>/Unit Delay10'
     *  UnitDelay: '<S5>/Unit Delay9'
     */
    rtb_UnitDelay = (swc_ATAU_ARID_DEF.UnitDelay9_DSTATE ||
                     swc_ATAU_ARID_DEF.UnitDelay10_DSTATE);
  }

  /* End of Switch: '<S5>/Switch6' */

  /* Logic: '<S13>/Logical Operator1' incorporates:
   *  Logic: '<S13>/Logical Operator2'
   */
  rtb_Compare_o = (pmmd_b_framUpdate || (rtb_IgOnDual && rtb_UnitDelay));

  /* Chart: '<S13>/FrameInterval' */
  if (swc_ATAU_ARID_DEF.is_active_c6_swc_ATAU == 0U) {
    swc_ATAU_ARID_DEF.is_active_c6_swc_ATAU = 1U;
    if (rtb_Compare_o) {
      swc_ATAU_ARID_DEF.cnt = 0U;
      pmmd_st_atauRept = 0U;
      swc_ATAU_ARID_DEF.is_c6_swc_ATAU = swc_ATAU_IN_FrameUpdate;
      swc_ATAU_ARID_DEF.is_FrameUpdate = swc_ATAU_IN_Valid;
      pmmd_b_frameAuthReq = true;
      swc_ATAU_ARID_DEF.timer = 0.0F;
      swc_ATAU_ARID_DEF.cnt++;
    } else {
      swc_ATAU_ARID_DEF.is_c6_swc_ATAU = swc_ATAU_IN_FrameUpdate;
      swc_ATAU_ARID_DEF.is_FrameUpdate = swc_ATAU_IN_defualt;
      pmmd_b_frameAuthReq = false;
      swc_ATAU_ARID_DEF.timer = 0.0F;
      swc_ATAU_ARID_DEF.cnt = 0U;
    }
  } else if (swc_ATAU_ARID_DEF.is_c6_swc_ATAU == swc_ATAU_IN_FrameUpdate) {
    if (!rtb_IgOnDual) {
      swc_ATAU_ARID_DEF.is_FrameUpdate = 0;
      swc_ATAU_ARID_DEF.is_c6_swc_ATAU = swc_ATAU_IN_IgOnClear;
      swc_ATAU_ARID_DEF.cnt = 0U;
      pmmd_st_atauRept = 0U;
      pmmd_b_frameAuthReq = false;
    } else {
      switch (swc_ATAU_ARID_DEF.is_FrameUpdate) {
       case swc_ATAU_IN_NoValid:
        pmmd_b_frameAuthReq = false;

        /*  This is frame interval time */
        if (swc_ATAU_ARID_DEF.timer >= 1.0F) {
          swc_ATAU_ARID_DEF.is_FrameUpdate = swc_ATAU_IN_Valid;
          pmmd_b_frameAuthReq = true;
          swc_ATAU_ARID_DEF.timer = 0.0F;
          swc_ATAU_ARID_DEF.cnt++;
        } else {
          swc_ATAU_ARID_DEF.timer++;
        }
        break;

       case swc_ATAU_IN_Valid:
        /*  This is 3 frame  */
        if (swc_ATAU_ARID_DEF.cnt >= 3) {
          pmmd_st_atauRept = (uint8)(pmmd_st_atauRept + 1);
          swc_ATAU_ARID_DEF.is_FrameUpdate = swc_ATAU_IN_defualt;
          pmmd_b_frameAuthReq = false;
          swc_ATAU_ARID_DEF.timer = 0.0F;
          swc_ATAU_ARID_DEF.cnt = 0U;
        } else {
          swc_ATAU_ARID_DEF.is_FrameUpdate = swc_ATAU_IN_NoValid;
          pmmd_b_frameAuthReq = false;
          swc_ATAU_ARID_DEF.timer++;
        }
        break;

       default:
        /* case IN_defualt: */
        pmmd_b_frameAuthReq = false;
        if (rtb_Compare_o) {
          swc_ATAU_ARID_DEF.is_FrameUpdate = swc_ATAU_IN_Valid;
          pmmd_b_frameAuthReq = true;
          swc_ATAU_ARID_DEF.timer = 0.0F;
          swc_ATAU_ARID_DEF.cnt++;
        }
        break;
      }
    }
  } else {
    /* case IN_IgOnClear: */
    pmmd_b_frameAuthReq = false;
    if (rtb_Compare_o) {
      swc_ATAU_ARID_DEF.is_c6_swc_ATAU = swc_ATAU_IN_FrameUpdate;
      swc_ATAU_ARID_DEF.is_FrameUpdate = swc_ATAU_IN_Valid;
      pmmd_b_frameAuthReq = true;
      swc_ATAU_ARID_DEF.timer = 0.0F;
      swc_ATAU_ARID_DEF.cnt++;
    }
  }

  /* End of Chart: '<S13>/FrameInterval' */
  for (i = 0; i < 8; i++) {
    /* Switch: '<S5>/Switch14' */
    if (rtb_LogicalOperator3_gl) {
      /* Switch: '<S5>/Switch14' */
      rtb_UnitDelay1_f[i] = pmmd_v_xcuCodeVect[i];
    } else {
      /* Switch: '<S5>/Switch14' */
      rtb_UnitDelay1_f[i] = pmmd_v_pepsCodeVect[i];
    }

    /* End of Switch: '<S5>/Switch14' */
  }

  for (i = 0; i < 8; i++) {
    /* RelationalOperator: '<S5>/Relational Operator5' incorporates:
     *  RelationalOperator: '<S5>/Relational Operator2'
     */
    rtb_RelationalOperator_a[i] = (swc_ATAU_ARID_DEF.out[i + 8] ==
      rtb_UnitDelay1_f[i]);
  }

  /* Logic: '<S5>/Logical Operator27' */
  rtb_Compare_o = rtb_RelationalOperator_a[0];
  for (i = 0; i < 7; i++) {
    rtb_Compare_o = (rtb_Compare_o && rtb_RelationalOperator_a[i + 1]);
  }

  for (i = 0; i < 8; i++) {
    /* RelationalOperator: '<S5>/Relational Operator5' incorporates:
     *  RelationalOperator: '<S5>/Relational Operator4'
     */
    rtb_RelationalOperator_a[i] = (swc_ATAU_ARID_DEF.out[i + 8] ==
      pmmd_v_pepsCodeVect[i]);
  }

  /* Logic: '<S5>/Logical Operator9' */
  tmp_4 = rtb_RelationalOperator_a[0];
  for (i = 0; i < 7; i++) {
    tmp_4 = (tmp_4 && rtb_RelationalOperator_a[i + 1]);
  }

  /* RelationalOperator: '<S8>/Compare' incorporates:
   *  Constant: '<S8>/Constant'
   */
  rtb_Compare_n = (pmmd_st_atauRept == ((uint8)1U));

  /* Outputs for Atomic SubSystem: '<S5>/turnON_delay' */
  /* Constant: '<S5>/Constant2' incorporates:
   *  Constant: '<S5>/Constant3'
   */
  rtb_flg_out_p = swc_ATAU_turnON_delay(rtb_Compare_n, 0.09F, 0.01F,
    &swc_ATAU_ARID_DEF.ARID_DEF_turnON_delay);

  /* End of Outputs for SubSystem: '<S5>/turnON_delay' */

  /* UnitDelay: '<S16>/Unit Delay' incorporates:
   *  UnitDelay: '<S5>/Unit Delay'
   */
  rtb_UnitDelay = swc_ATAU_ARID_DEF.UnitDelay_DSTATE_e;

  /* Logic: '<S5>/Logical Operator1' incorporates:
   *  Logic: '<S5>/Logical Operator3'
   */
  rtb_LogicalOperator1_l = (rtb_flg_out_p && (!rtb_UnitDelay));

  /* Logic: '<S5>/Logical Operator30' incorporates:
   *  Logic: '<S5>/Logical Operator32'
   */
  rtb_LogicalOperator30 = ((!rtb_IgOnDual) || rtb_LogicalOperator1_l);

  /* Outputs for Atomic SubSystem: '<S5>/SR_latch1' */
  rtb_LogicalOperator3_gl = swc_ATAU_SR_latch1(rtb_Compare_n,
    rtb_LogicalOperator30, &swc_ATAU_ARID_DEF.ARID_DEF_SR_latch1);

  /* End of Outputs for SubSystem: '<S5>/SR_latch1' */

  /* Logic: '<S5>/Logical Operator7' incorporates:
   *  Logic: '<S5>/Logical Operator27'
   *  Logic: '<S5>/Logical Operator9'
   */
  pmmd_b_normalScen = (rtb_Compare_o && tmp_4 && rtb_LogicalOperator3_gl);
  for (i = 0; i < 8; i++) {
    /* RelationalOperator: '<S5>/Relational Operator3' incorporates:
     *  Constant: '<S5>/Constant8'
     */
    rtb_RelationalOperator_a[i] = (rtb_UnitDelay1_f[i] ==
      swc_ATAU_ConstP.pooled15[i]);
  }

  /* Logic: '<S5>/Logical Operator31' */
  tmp = rtb_RelationalOperator_a[0];
  for (i = 0; i < 7; i++) {
    tmp = (tmp || rtb_RelationalOperator_a[i + 1]);
  }

  for (i = 0; i < 8; i++) {
    /* RelationalOperator: '<S5>/Relational Operator5' incorporates:
     *  RelationalOperator: '<S5>/Relational Operator9'
     */
    rtb_RelationalOperator_a[i] = (swc_ATAU_ARID_DEF.out[i + 8] !=
      rtb_UnitDelay1_f[i]);
  }

  /* Logic: '<S5>/Logical Operator33' */
  tmp_0 = rtb_RelationalOperator_a[0];
  for (i = 0; i < 7; i++) {
    tmp_0 = (tmp_0 || rtb_RelationalOperator_a[i + 1]);
  }

  for (i = 0; i < 8; i++) {
    /* RelationalOperator: '<S5>/Relational Operator6' incorporates:
     *  Constant: '<S5>/Constant11'
     */
    rtb_RelationalOperator_a[i] = (pmmd_v_pepsCodeVect[i] ==
      swc_ATAU_ConstP.pooled15[i]);
  }

  /* Logic: '<S5>/Logical Operator13' */
  tmp_1 = rtb_RelationalOperator_a[0];
  for (i = 0; i < 7; i++) {
    tmp_1 = (tmp_1 || rtb_RelationalOperator_a[i + 1]);
  }

  for (i = 0; i < 8; i++) {
    /* RelationalOperator: '<S5>/Relational Operator5' incorporates:
     *  RelationalOperator: '<S5>/Relational Operator7'
     */
    rtb_RelationalOperator_a[i] = (swc_ATAU_ARID_DEF.out[i + 8] !=
      pmmd_v_pepsCodeVect[i]);
  }

  /* Logic: '<S5>/Logical Operator14' */
  tmp_2 = rtb_RelationalOperator_a[0];
  for (i = 0; i < 7; i++) {
    tmp_2 = (tmp_2 || rtb_RelationalOperator_a[i + 1]);
  }

  /* RelationalOperator: '<S9>/Compare' incorporates:
   *  Constant: '<S9>/Constant'
   */
  rtb_Compare_d = (pmmd_st_atauRept == ((uint8)2U));

  /* Outputs for Atomic SubSystem: '<S5>/turnON_delay1' */
  /* Constant: '<S5>/Constant12' incorporates:
   *  Constant: '<S5>/Constant13'
   */
  rtb_flg_out_n = swc_ATAU_turnON_delay(rtb_Compare_d, 0.09F, 0.01F,
    &swc_ATAU_ARID_DEF.ARID_DEF_turnON_delay1);

  /* End of Outputs for SubSystem: '<S5>/turnON_delay1' */

  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Constant: '<S10>/Constant'
   */
  rtb_Compare_j = (pmmd_st_atauRept == ((uint8)3U));

  /* Outputs for Atomic SubSystem: '<S5>/turnON_delay2' */
  /* Constant: '<S5>/Constant15' incorporates:
   *  Constant: '<S5>/Constant16'
   */
  rtb_flg_out_d = swc_ATAU_turnON_delay(rtb_Compare_j, 0.09F, 0.01F,
    &swc_ATAU_ARID_DEF.ARID_DEF_turnON_delay2);

  /* End of Outputs for SubSystem: '<S5>/turnON_delay2' */

  /* UnitDelay: '<S16>/Unit Delay' incorporates:
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  rtb_UnitDelay = swc_ATAU_ARID_DEF.UnitDelay2_DSTATE_p;

  /* Logic: '<S5>/Logical Operator17' incorporates:
   *  Logic: '<S5>/Logical Operator18'
   *  Logic: '<S5>/Logical Operator19'
   */
  rtb_LogicalOperator17 = ((rtb_flg_out_n || rtb_flg_out_d) && (!rtb_UnitDelay));

  /* Logic: '<S5>/Logical Operator37' incorporates:
   *  Logic: '<S5>/Logical Operator39'
   */
  rtb_LogicalOperator37 = ((!rtb_IgOnDual) || rtb_LogicalOperator17);

  /* Outputs for Atomic SubSystem: '<S5>/SR_latch3' */
  rtb_LogicalOperator3_n = swc_ATAU_SR_latch3(rtb_Compare_d,
    rtb_LogicalOperator37, &swc_ATAU_ARID_DEF.ARID_DEF_SR_latch3);

  /* End of Outputs for SubSystem: '<S5>/SR_latch3' */

  /* Logic: '<S5>/Logical Operator16' incorporates:
   *  Logic: '<S5>/Logical Operator13'
   *  Logic: '<S5>/Logical Operator14'
   *  Logic: '<S5>/Logical Operator15'
   *  Logic: '<S5>/Logical Operator31'
   *  Logic: '<S5>/Logical Operator33'
   *  Logic: '<S5>/Logical Operator34'
   *  Logic: '<S5>/Logical Operator38'
   */
  pmmd_b_noRespScen = (((tmp && tmp_0) || (tmp_1 && tmp_2)) &&
                       rtb_LogicalOperator3_n);
  for (i = 0; i < 8; i++) {
    /* RelationalOperator: '<S5>/Relational Operator5' incorporates:
     *  Constant: '<S5>/Constant4'
     *  RelationalOperator: '<S5>/Relational Operator10'
     */
    rtb_RelationalOperator_a[i] = (swc_ATAU_ARID_DEF.out[i + 8] !=
      swc_ATAU_ConstP.pooled15[i]);
  }

  /* Logic: '<S5>/Logical Operator28' */
  tmp = rtb_RelationalOperator_a[0];
  for (i = 0; i < 7; i++) {
    tmp = (tmp && rtb_RelationalOperator_a[i + 1]);
  }

  for (i = 0; i < 8; i++) {
    /* RelationalOperator: '<S5>/Relational Operator5' incorporates:
     *  RelationalOperator: '<S5>/Relational Operator8'
     */
    rtb_RelationalOperator_a[i] = (swc_ATAU_ARID_DEF.out[i + 8] ==
      pmmd_v_pepsCodeVect[i]);
  }

  /* Logic: '<S5>/Logical Operator22' */
  tmp_0 = rtb_RelationalOperator_a[0];
  for (i = 0; i < 7; i++) {
    tmp_0 = (tmp_0 && rtb_RelationalOperator_a[i + 1]);
  }

  for (i = 0; i < 8; i++) {
    /* RelationalOperator: '<S5>/Relational Operator5' incorporates:
     *  RelationalOperator: '<S5>/Relational Operator11'
     */
    rtb_RelationalOperator_a[i] = (swc_ATAU_ARID_DEF.out[i + 8] ==
      rtb_UnitDelay1_f[i]);
  }

  /* Logic: '<S5>/Logical Operator40' */
  tmp_1 = rtb_RelationalOperator_a[0];
  for (i = 0; i < 7; i++) {
    tmp_1 = (tmp_1 && rtb_RelationalOperator_a[i + 1]);
  }

  /* Logic: '<S5>/Logical Operator21' incorporates:
   *  Constant: '<S11>/Constant'
   *  Logic: '<S5>/Logical Operator22'
   *  Logic: '<S5>/Logical Operator28'
   *  Logic: '<S5>/Logical Operator40'
   *  RelationalOperator: '<S11>/Compare'
   */
  pmmd_b_errCodeScen = ((pmmd_st_atauRept >= ((uint8)2U)) && tmp && tmp_0 &&
                        tmp_1);

  /* Switch: '<S5>/Switch3' incorporates:
   *  Switch: '<S5>/Switch2'
   *  Switch: '<S5>/Switch4'
   */
  if (pmmd_b_normalScen) {
    /* Switch: '<S5>/Switch3' incorporates:
     *  Constant: '<S5>/Constant10'
     */
    rtb_Switch3_b = true;
  } else if (pmmd_b_noRespScen) {
    /* Switch: '<S5>/Switch2' incorporates:
     *  Constant: '<S5>/Constant14'
     *  Switch: '<S5>/Switch3'
     */
    rtb_Switch3_b = false;
  } else if (pmmd_b_errCodeScen) {
    /* Switch: '<S5>/Switch4' incorporates:
     *  Constant: '<S5>/Constant1'
     *  Switch: '<S5>/Switch2'
     *  Switch: '<S5>/Switch3'
     */
    rtb_Switch3_b = true;
  } else {
    /* Switch: '<S5>/Switch3' incorporates:
     *  Switch: '<S5>/Switch2'
     *  UnitDelay: '<S5>/Unit Delay8'
     */
    rtb_Switch3_b = swc_ATAU_ARID_DEF.UnitDelay8_DSTATE;
  }

  /* End of Switch: '<S5>/Switch3' */

  /* Logic: '<S5>/Logical Operator25' */
  rtb_LogicalOperator25 = !rtb_IgOnDual;

  /* Outputs for Atomic SubSystem: '<S5>/SR_latch2' */
  rtb_LogicalOperator3_g = swc_ATAU_SR_latch2(rtb_Switch3_b,
    rtb_LogicalOperator25, &swc_ATAU_ARID_DEF.ARID_DEF_SR_latch2);

  /* End of Outputs for SubSystem: '<S5>/SR_latch2' */

  /* SignalConversion generated from: '<S5>/SR_latch2' */
  pmmd_b_antiSuccess = rtb_LogicalOperator3_g;

  /* Outputs for Atomic SubSystem: '<S5>/turnON_delay3' */
  /* Constant: '<S5>/Constant17' incorporates:
   *  Constant: '<S5>/Constant18'
   */
  rtb_flg_out_g = swc_ATAU_turnON_delay(rtb_IgOnDual, pmmc_tm_authMaxAllowTim_s,
    0.01F, &swc_ATAU_ARID_DEF.ARID_DEF_turnON_delay3);

  /* End of Outputs for SubSystem: '<S5>/turnON_delay3' */

  /* Switch: '<S5>/Switch8' incorporates:
   *  Constant: '<S5>/Constant7'
   */
  if (pmmc_b_useImmo_flg) {
    /* Switch: '<S5>/Switch9' incorporates:
     *  Constant: '<S12>/Constant'
     *  Logic: '<S15>/Logical Operator24'
     *  Logic: '<S15>/Logical Operator7'
     *  Logic: '<S15>/Logical Operator8'
     *  Logic: '<S5>/Logical Operator26'
     *  RelationalOperator: '<S12>/Compare'
     *  Switch: '<S5>/Switch5'
     *  Switch: '<S5>/Switch7'
     */
    if (rtb_LogicalOperator3 && (!rtb_RelationalOperator) && (pmmd_st_atauRept >=
         ((uint8)1U))) {
      /* Switch: '<S5>/Switch8' incorporates:
       *  Constant: '<S30>/Constant'
       *  Switch: '<S5>/Switch9'
       */
      rtb_Switch8_e = KeyAuthStatus_SUCCESS;
    } else if (pmmd_b_antiSuccess) {
      /* Switch: '<S5>/Switch5' incorporates:
       *  Constant: '<S28>/Constant'
       *  Switch: '<S5>/Switch8'
       */
      rtb_Switch8_e = KeyAuthStatus_SUCCESS;
    } else if (rtb_flg_out_g) {
      /* Switch: '<S5>/Switch7' incorporates:
       *  Constant: '<S26>/Constant'
       *  Switch: '<S5>/Switch5'
       *  Switch: '<S5>/Switch8'
       */
      rtb_Switch8_e = KeyAuthStatus_FAIL;
    } else {
      /* Switch: '<S5>/Switch8' incorporates:
       *  Constant: '<S14>/Constant'
       *  Switch: '<S5>/Switch5'
       *  Switch: '<S5>/Switch7'
       */
      rtb_Switch8_e = KeyAuthStatus_DEFAULT;
    }

    /* End of Switch: '<S5>/Switch9' */
  } else {
    /* Switch: '<S5>/Switch8' incorporates:
     *  Constant: '<S29>/Constant'
     */
    rtb_Switch8_e = KeyAuthStatus_SUCCESS;
  }

  /* End of Switch: '<S5>/Switch8' */

  /* UnitDelay: '<S16>/Unit Delay' incorporates:
   *  Constant: '<S29>/Constant'
   *  RelationalOperator: '<S5>/Relational Operator'
   */
  rtb_UnitDelay = (rtb_Switch8_e == KeyAuthStatus_SUCCESS);

  /* SignalConversion: '<S4>/Signal Conversion1' */
  rtb_SignalConversion1 = rtb_UnitDelay;

  /* Switch: '<S5>/Switch16' incorporates:
   *  Logic: '<S5>/Logical Operator'
   *  Logic: '<S5>/Logical Operator49'
   */
  if (pmmd_b_antiSuccess || (!rtb_IgOnDual)) {
    /* Switch: '<S5>/Switch16' incorporates:
     *  Constant: '<S5>/Constant30'
     */
    pmmd_st_authFailReason = ((uint8)0U);
  } else {
    for (i = 0; i < 8; i++) {
      /* RelationalOperator: '<S5>/Relational Operator18' incorporates:
       *  RelationalOperator: '<S5>/Relational Operator17'
       */
      rtb_RelationalOperator_a[i] = (swc_ATAU_ARID_DEF.out[i + 8] !=
        rtb_UnitDelay1_f[i]);
    }

    /* Logic: '<S5>/Logical Operator54' */
    rtb_RelationalOperator = rtb_RelationalOperator_a[0];
    for (i = 0; i < 7; i++) {
      rtb_RelationalOperator = (rtb_RelationalOperator ||
        rtb_RelationalOperator_a[i + 1]);
    }

    for (i = 0; i < 8; i++) {
      /* RelationalOperator: '<S5>/Relational Operator18' */
      rtb_RelationalOperator_a[i] = (swc_ATAU_ARID_DEF.out[i + 8] !=
        pmmd_v_pepsCodeVect[i]);
    }

    /* Logic: '<S5>/Logical Operator55' */
    tmp = rtb_RelationalOperator_a[0];
    for (i = 0; i < 7; i++) {
      tmp = (tmp || rtb_RelationalOperator_a[i + 1]);
    }

    /* RelationalOperator: '<S5>/Relational Operator14' incorporates:
     *  Constant: '<S27>/Constant'
     */
    rtb_LogicalOperator3 = (rtb_Switch8_e == KeyAuthStatus_FAIL);

    /* Switch: '<S5>/Switch11' incorporates:
     *  Logic: '<S5>/Logical Operator27'
     *  Logic: '<S5>/Logical Operator45'
     *  Logic: '<S5>/Logical Operator46'
     *  Logic: '<S5>/Logical Operator47'
     *  Logic: '<S5>/Logical Operator54'
     *  Logic: '<S5>/Logical Operator55'
     *  Logic: '<S5>/Logical Operator9'
     *  Switch: '<S5>/Switch12'
     *  Switch: '<S5>/Switch13'
     */
    if (rtb_RelationalOperator && tmp && rtb_LogicalOperator3) {
      /* Switch: '<S5>/Switch16' incorporates:
       *  Constant: '<S5>/Constant23'
       *  Switch: '<S5>/Switch11'
       */
      pmmd_st_authFailReason = ((uint8)3U);
    } else if (rtb_RelationalOperator && tmp_4 && rtb_LogicalOperator3) {
      /* Switch: '<S5>/Switch12' incorporates:
       *  Constant: '<S5>/Constant24'
       *  Switch: '<S5>/Switch16'
       */
      pmmd_st_authFailReason = ((uint8)2U);
    } else if (rtb_Compare_o && tmp && rtb_LogicalOperator3) {
      /* Switch: '<S5>/Switch13' incorporates:
       *  Constant: '<S5>/Constant25'
       *  Switch: '<S5>/Switch12'
       *  Switch: '<S5>/Switch16'
       */
      pmmd_st_authFailReason = ((uint8)1U);
    } else {
      /* Switch: '<S5>/Switch16' incorporates:
       *  Switch: '<S5>/Switch12'
       *  UnitDelay: '<S5>/Unit Delay1'
       */
      pmmd_st_authFailReason = swc_ATAU_ARID_DEF.UnitDelay1_DSTATE_p;
    }

    /* End of Switch: '<S5>/Switch11' */
  }

  /* End of Switch: '<S5>/Switch16' */

  /* SignalConversion: '<S4>/Signal Conversion3' */
  rtb_SignalConversion3 = pmmd_st_authFailReason;
  for (i = 0; i < 8; i++) {
    /* Switch: '<S13>/Switch2' */
    if (pmmd_b_frameAuthReq) {
      /* Switch: '<S13>/Switch2' incorporates:
       *  SignalConversion generated from: '<S7>/AuthCode'
       */
      pmmd_v_authCodeVect[i] = swc_ATAU_ARID_DEF.OutportBufferForAuthCode[i];
    } else {
      /* Switch: '<S13>/Switch2' incorporates:
       *  Constant: '<S13>/AuthReqDefualt'
       */
      pmmd_v_authCodeVect[i] = swc_ATAU_ConstP.pooled15[i];
    }

    /* End of Switch: '<S13>/Switch2' */
  }

  for (i = 0; i < 8; i++) {
    /* CCaller: '<S4>/C Caller' incorporates:
     *  Switch: '<S13>/Switch2'
     */
    rtb_CCaller[i] = pmmd_v_authCodeVect[i];
  }

  /* CCaller: '<S4>/C Caller' */
  mBSW_Set_PMS_Auth_Req(&rtb_CCaller[0]);

  /* CCaller: '<S4>/C Caller1' */
  mBSW_NvmWrite_KeyOnCnt(pmmd_num_keyOncnt);

  /* Outputs for Enabled SubSystem: '<S4>/Write_Random' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (rtb_FixPtRelationalOperator) {
    /* CCaller: '<S6>/C Caller' */
    mBSW_NvmWrite_Rdn(pmmd_st_atauRndNumSet);
  }

  /* End of Outputs for SubSystem: '<S4>/Write_Random' */

  /* Switch: '<S13>/Switch1' incorporates:
   *  Constant: '<S13>/TestUse'
   *  Switch: '<S13>/Switch3'
   */
  if (pmmc_b_testRdnNvmDataWrite) {
    /* Switch: '<S13>/Switch1' incorporates:
     *  RelationalOperator: '<S41>/FixPt Relational Operator'
     *  UnitDelay: '<S41>/Delay Input1'
     *
     * Block description for '<S41>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_Switch1_i = (swc_ATAU_ARID_DEF.DelayInput1_DSTATE < 1);

    /* Switch: '<S13>/Switch3' incorporates:
     *  Constant: '<S13>/TestUse1'
     */
    rtb_Switch3 = pmmc_n_testRdnNvmData;
  } else {
    /* Switch: '<S13>/Switch1' */
    rtb_Switch1_i = pmmd_b_framUpdate;

    /* Switch: '<S13>/Switch3' */
    rtb_Switch3 = swc_ATAU_ARID_DEF.DataTypeConversion[3];
  }

  /* End of Switch: '<S13>/Switch1' */
  for (i = 0; i < 8; i++) {
    /* RelationalOperator: '<S5>/Relational Operator12' incorporates:
     *  Constant: '<S5>/Constant21'
     */
    rtb_RelationalOperator_a[i] = (rtb_UnitDelay1_f[i] !=
      swc_ATAU_ConstP.pooled15[i]);
  }

  /* Logic: '<S5>/Logical Operator41' */
  rtb_RelationalOperator = rtb_RelationalOperator_a[0];
  for (i = 0; i < 7; i++) {
    rtb_RelationalOperator = (rtb_RelationalOperator ||
      rtb_RelationalOperator_a[i + 1]);
  }

  for (i = 0; i < 8; i++) {
    /* RelationalOperator: '<S5>/Relational Operator5' incorporates:
     *  RelationalOperator: '<S5>/Relational Operator13'
     */
    rtb_RelationalOperator_a[i] = (swc_ATAU_ARID_DEF.out[i + 8] !=
      rtb_UnitDelay1_f[i]);
  }

  /* Logic: '<S5>/Logical Operator42' */
  rtb_Compare_o = rtb_RelationalOperator_a[0];
  for (i = 0; i < 7; i++) {
    rtb_Compare_o = (rtb_Compare_o || rtb_RelationalOperator_a[i + 1]);
  }

  for (i = 0; i < 8; i++) {
    /* RelationalOperator: '<S5>/Relational Operator1' incorporates:
     *  Constant: '<S5>/Constant6'
     */
    rtb_RelationalOperator_a[i] = (pmmd_v_pepsCodeVect[i] !=
      swc_ATAU_ConstP.pooled15[i]);
  }

  /* Logic: '<S5>/Logical Operator10' */
  tmp_4 = rtb_RelationalOperator_a[0];
  for (i = 0; i < 7; i++) {
    tmp_4 = (tmp_4 || rtb_RelationalOperator_a[i + 1]);
  }

  for (i = 0; i < 8; i++) {
    /* RelationalOperator: '<S5>/Relational Operator5' */
    rtb_RelationalOperator_a[i] = (swc_ATAU_ARID_DEF.out[i + 8] !=
      pmmd_v_pepsCodeVect[i]);
  }

  /* Logic: '<S5>/Logical Operator11' */
  tmp = rtb_RelationalOperator_a[0];
  for (i = 0; i < 7; i++) {
    tmp = (tmp || rtb_RelationalOperator_a[i + 1]);
  }

  /* Logic: '<S5>/Logical Operator8' incorporates:
   *  Logic: '<S5>/Logical Operator10'
   *  Logic: '<S5>/Logical Operator11'
   *  Logic: '<S5>/Logical Operator12'
   *  Logic: '<S5>/Logical Operator41'
   *  Logic: '<S5>/Logical Operator42'
   *  Logic: '<S5>/Logical Operator43'
   *  Logic: '<S5>/Logical Operator44'
   */
  rtb_LogicalOperator8 = (((rtb_RelationalOperator && rtb_Compare_o) || (tmp_4 &&
    tmp)) && rtb_LogicalOperator3_gl);

  /* Logic: '<S5>/Logical Operator36' incorporates:
   *  Logic: '<S5>/Logical Operator29'
   *  Logic: '<S5>/Logical Operator35'
   */
  rtb_LogicalOperator36 = ((!rtb_LogicalOperator3_gl) || (!rtb_IgOnDual));

  /* Outputs for Atomic SubSystem: '<S5>/SR_latch4' */
  rtb_LogicalOperator3_n = swc_ATAU_SR_latch4(rtb_LogicalOperator8,
    rtb_LogicalOperator36, &swc_ATAU_ARID_DEF.ARID_DEF_SR_latch4);

  /* End of Outputs for SubSystem: '<S5>/SR_latch4' */

  /* Outputs for Atomic SubSystem: '<S5>/Falling_Edge' */
  /* UnitDelay: '<S16>/Unit Delay' */
  rtb_UnitDelay = swc_ATAU_ARID_DEF.UnitDelay_DSTATE_f;

  /* Update for UnitDelay: '<S16>/Unit Delay' */
  swc_ATAU_ARID_DEF.UnitDelay_DSTATE_f = rtb_LogicalOperator3_n;

  /* End of Outputs for SubSystem: '<S5>/Falling_Edge' */
  for (i = 0; i < 8; i++) {
    /* SignalConversion: '<S5>/Signal Conversion' */
    pmmd_v_compCodeVect[i] = swc_ATAU_ARID_DEF.out[i + 8];
  }

  /* Update for UnitDelay: '<S43>/Unit Delay1' */
  swc_ATAU_ARID_DEF.UnitDelay1_DSTATE = pmmd_num_keyOnCntRaw;

  /* Update for UnitDelay: '<S43>/Unit Delay3' */
  swc_ATAU_ARID_DEF.UnitDelay3_DSTATE = pmmd_num_keyOncnt;

  /* Update for UnitDelay: '<S46>/Unit Delay' */
  swc_ATAU_ARID_DEF.UnitDelay_DSTATE_p = rtb_IgOnDual;

  /* Update for UnitDelay: '<S43>/Unit Delay2' */
  swc_ATAU_ARID_DEF.UnitDelay2_DSTATE = rtb_Switch8;

  /* Update for UnitDelay: '<S17>/Unit Delay2' */
  swc_ATAU_ARID_DEF.UnitDelay2_DSTATE_n = rtb_Switch8_h;

  /* Update for UnitDelay: '<S52>/Delay Input1'
   *
   * Block description for '<S52>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_ATAU_ARID_DEF.DelayInput1_DSTATE_g = rtb_IgOnDual;

  /* Update for UnitDelay: '<S17>/Unit Delay1' */
  swc_ATAU_ARID_DEF.UnitDelay1_DSTATE_k = rtb_Switch8_h;

  /* Update for Delay: '<S17>/Resettable Delay' */
  swc_ATAU_ARID_DEF.icLoad = false;
  swc_ATAU_ARID_DEF.ResettableDelay_DSTATE = rtb_Switch8_h;

  /* Outputs for Atomic SubSystem: '<S5>/Falling_Edge' */
  /* Update for UnitDelay: '<S5>/Unit Delay7' incorporates:
   *  Logic: '<S16>/Logical Operator1'
   *  Logic: '<S16>/Logical Operator2'
   */
  swc_ATAU_ARID_DEF.UnitDelay7_DSTATE = (rtb_UnitDelay &&
    (!rtb_LogicalOperator3_n));

  /* End of Outputs for SubSystem: '<S5>/Falling_Edge' */

  /* Update for UnitDelay: '<S18>/Unit Delay2' */
  swc_ATAU_ARID_DEF.UnitDelay2_DSTATE_m = pmmd_st_atauRndNumSet;

  /* Update for UnitDelay: '<S54>/Delay Input1'
   *
   * Block description for '<S54>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_ATAU_ARID_DEF.DelayInput1_DSTATE_d = rtb_IgOnDual;

  /* Update for UnitDelay: '<S56>/Unit Delay' incorporates:
   *  DataTypeConversion: '<S56>/Data Type Conversion'
   */
  swc_ATAU_ARID_DEF.UnitDelay_DSTATE = rtb_DataTypeConversion2;

  /* Update for UnitDelay: '<S58>/Delay Input1'
   *
   * Block description for '<S58>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_ATAU_ARID_DEF.DelayInput1_DSTATE_a = rtb_Compare;

  /* Update for UnitDelay: '<S18>/Unit Delay1' */
  swc_ATAU_ARID_DEF.UnitDelay1_DSTATE_a = pmmd_st_atauRndNumSet;

  /* Update for Delay: '<S18>/Resettable Delay4' */
  swc_ATAU_ARID_DEF.icLoad_p = false;
  swc_ATAU_ARID_DEF.ResettableDelay4_DSTATE = pmmd_st_atauRndNumSet;

  /* Update for UnitDelay: '<S18>/Unit Delay' */
  swc_ATAU_ARID_DEF.UnitDelay_DSTATE_c = pmmd_st_atauRndNumSet;

  /* Update for UnitDelay: '<S5>/Unit Delay3' */
  swc_ATAU_ARID_DEF.UnitDelay3_DSTATE_o = pmmd_b_framUpdate;

  /* Update for UnitDelay: '<S13>/Unit Delay1' incorporates:
   *  SignalConversion generated from: '<S7>/AuthCode'
   */
  for (i = 0; i < 8; i++) {
    swc_ATAU_ARID_DEF.UnitDelay1_DSTATE_h[i] =
      swc_ATAU_ARID_DEF.OutportBufferForAuthCode[i];
  }

  /* End of Update for UnitDelay: '<S13>/Unit Delay1' */

  /* Update for UnitDelay: '<S5>/Unit Delay11' */
  swc_ATAU_ARID_DEF.UnitDelay11_DSTATE = pmmd_b_antiSuccess;

  /* Update for UnitDelay: '<S5>/Unit Delay9' */
  swc_ATAU_ARID_DEF.UnitDelay9_DSTATE = rtb_LogicalOperator1_l;

  /* Update for UnitDelay: '<S5>/Unit Delay10' */
  swc_ATAU_ARID_DEF.UnitDelay10_DSTATE = rtb_LogicalOperator17;

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  swc_ATAU_ARID_DEF.UnitDelay_DSTATE_e = pmmd_b_antiSuccess;

  /* Update for UnitDelay: '<S5>/Unit Delay2' */
  swc_ATAU_ARID_DEF.UnitDelay2_DSTATE_p = pmmd_b_antiSuccess;

  /* Update for UnitDelay: '<S5>/Unit Delay8' */
  swc_ATAU_ARID_DEF.UnitDelay8_DSTATE = pmmd_b_antiSuccess;

  /* Update for UnitDelay: '<S5>/Unit Delay1' */
  swc_ATAU_ARID_DEF.UnitDelay1_DSTATE_p = pmmd_st_authFailReason;

  /* Update for UnitDelay: '<S41>/Delay Input1' incorporates:
   *  Constant: '<S13>/TestUse'
   *
   * Block description for '<S41>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_ATAU_ARID_DEF.DelayInput1_DSTATE = pmmc_b_testRdnNvmDataWrite;

  /* Outport generated from: '<Root>/Out Bus Element' incorporates:
   *  SignalConversion: '<S4>/Signal Conversion'
   *  Switch: '<S5>/Switch8'
   */
  Rte_IWrite_swc_ATAU_Step_vcsb_ATAU_pmmd_e_authenticationStatus(rtb_Switch8_e);

  /* Outport generated from: '<Root>/Out Bus Element1' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion1'
   *  Switch: '<S5>/Switch8'
   */
  Rte_IWrite_swc_ATAU_Step_vcsb_ATAU_pmmd_b_ePTRelease_flg(rtb_Switch8_e);
}

/* Model initialize function */
void swc_ATAU_Init(void)
{
  {
    /* local block i/o variables */
    boolean rtb_flg_out;
    boolean rtb_flg_out_g;
    boolean rtb_flg_out_d;
    boolean rtb_flg_out_n;
    boolean rtb_flg_out_p;
    boolean rtb_flg_out_m;
    static const uint32 tmp[625] = { 5489U, 1301868182U, 2938499221U,
      2950281878U, 1875628136U, 751856242U, 944701696U, 2243192071U, 694061057U,
      219885934U, 2066767472U, 3182869408U, 485472502U, 2336857883U, 1071588843U,
      3418470598U, 951210697U, 3693558366U, 2923482051U, 1793174584U,
      2982310801U, 1586906132U, 1951078751U, 1808158765U, 1733897588U,
      431328322U, 4202539044U, 530658942U, 1714810322U, 3025256284U, 3342585396U,
      1937033938U, 2640572511U, 1654299090U, 3692403553U, 4233871309U,
      3497650794U, 862629010U, 2943236032U, 2426458545U, 1603307207U,
      1133453895U, 3099196360U, 2208657629U, 2747653927U, 931059398U, 761573964U,
      3157853227U, 785880413U, 730313442U, 124945756U, 2937117055U, 3295982469U,
      1724353043U, 3021675344U, 3884886417U, 4010150098U, 4056961966U,
      699635835U, 2681338818U, 1339167484U, 720757518U, 2800161476U, 2376097373U,
      1532957371U, 3902664099U, 1238982754U, 3725394514U, 3449176889U,
      3570962471U, 4287636090U, 4087307012U, 3603343627U, 202242161U,
      2995682783U, 1620962684U, 3704723357U, 371613603U, 2814834333U,
      2111005706U, 624778151U, 2094172212U, 4284947003U, 1211977835U, 991917094U,
      1570449747U, 2962370480U, 1259410321U, 170182696U, 146300961U, 2836829791U,
      619452428U, 2723670296U, 1881399711U, 1161269684U, 1675188680U,
      4132175277U, 780088327U, 3409462821U, 1036518241U, 1834958505U,
      3048448173U, 161811569U, 618488316U, 44795092U, 3918322701U, 1924681712U,
      3239478144U, 383254043U, 4042306580U, 2146983041U, 3992780527U,
      3518029708U, 3545545436U, 3901231469U, 1896136409U, 2028528556U,
      2339662006U, 501326714U, 2060962201U, 2502746480U, 561575027U, 581893337U,
      3393774360U, 1778912547U, 3626131687U, 2175155826U, 319853231U, 986875531U,
      819755096U, 2915734330U, 2688355739U, 3482074849U, 2736559U, 2296975761U,
      1029741190U, 2876812646U, 690154749U, 579200347U, 4027461746U, 1285330465U,
      2701024045U, 4117700889U, 759495121U, 3332270341U, 2313004527U,
      2277067795U, 4131855432U, 2722057515U, 1264804546U, 3848622725U,
      2211267957U, 4100593547U, 959123777U, 2130745407U, 3194437393U, 486673947U,
      1377371204U, 17472727U, 352317554U, 3955548058U, 159652094U, 1232063192U,
      3835177280U, 49423123U, 3083993636U, 733092U, 2120519771U, 2573409834U,
      1112952433U, 3239502554U, 761045320U, 1087580692U, 2540165110U, 641058802U,
      1792435497U, 2261799288U, 1579184083U, 627146892U, 2165744623U,
      2200142389U, 2167590760U, 2381418376U, 1793358889U, 3081659520U,
      1663384067U, 2009658756U, 2689600308U, 739136266U, 2304581039U,
      3529067263U, 591360555U, 525209271U, 3131882996U, 294230224U, 2076220115U,
      3113580446U, 1245621585U, 1386885462U, 3203270426U, 123512128U, 12350217U,
      354956375U, 4282398238U, 3356876605U, 3888857667U, 157639694U, 2616064085U,
      1563068963U, 2762125883U, 4045394511U, 4180452559U, 3294769488U,
      1684529556U, 1002945951U, 3181438866U, 22506664U, 691783457U, 2685221343U,
      171579916U, 3878728600U, 2475806724U, 2030324028U, 3331164912U,
      1708711359U, 1970023127U, 2859691344U, 2588476477U, 2748146879U,
      136111222U, 2967685492U, 909517429U, 2835297809U, 3206906216U, 3186870716U,
      341264097U, 2542035121U, 3353277068U, 548223577U, 3170936588U, 1678403446U,
      297435620U, 2337555430U, 466603495U, 1132321815U, 1208589219U, 696392160U,
      894244439U, 2562678859U, 470224582U, 3306867480U, 201364898U, 2075966438U,
      1767227936U, 2929737987U, 3674877796U, 2654196643U, 3692734598U,
      3528895099U, 2796780123U, 3048728353U, 842329300U, 191554730U, 2922459673U,
      3489020079U, 3979110629U, 1022523848U, 2202932467U, 3583655201U,
      3565113719U, 587085778U, 4176046313U, 3013713762U, 950944241U, 396426791U,
      3784844662U, 3477431613U, 3594592395U, 2782043838U, 3392093507U,
      3106564952U, 2829419931U, 1358665591U, 2206918825U, 3170783123U, 31522386U,
      2988194168U, 1782249537U, 1105080928U, 843500134U, 1225290080U,
      1521001832U, 3605886097U, 2802786495U, 2728923319U, 3996284304U,
      903417639U, 1171249804U, 1020374987U, 2824535874U, 423621996U, 1988534473U,
      2493544470U, 1008604435U, 1756003503U, 1488867287U, 1386808992U,
      732088248U, 1780630732U, 2482101014U, 976561178U, 1543448953U, 2602866064U,
      2021139923U, 1952599828U, 2360242564U, 2117959962U, 2753061860U,
      2388623612U, 4138193781U, 2962920654U, 2284970429U, 766920861U,
      3457264692U, 2879611383U, 815055854U, 2332929068U, 1254853997U,
      3740375268U, 3799380844U, 4091048725U, 2006331129U, 1982546212U,
      686850534U, 1907447564U, 2682801776U, 2780821066U, 998290361U, 1342433871U,
      4195430425U, 607905174U, 3902331779U, 2454067926U, 1708133115U,
      1170874362U, 2008609376U, 3260320415U, 2211196135U, 433538229U,
      2728786374U, 2189520818U, 262554063U, 1182318347U, 3710237267U,
      1221022450U, 715966018U, 2417068910U, 2591870721U, 2870691989U,
      3418190842U, 4238214053U, 1540704231U, 1575580968U, 2095917976U,
      4078310857U, 2313532447U, 2110690783U, 4056346629U, 4061784526U,
      1123218514U, 551538993U, 597148360U, 4120175196U, 3581618160U, 3181170517U,
      422862282U, 3227524138U, 1713114790U, 662317149U, 1230418732U, 928171837U,
      1324564878U, 1928816105U, 1786535431U, 2878099422U, 3290185549U,
      539474248U, 1657512683U, 552370646U, 1671741683U, 3655312128U, 1552739510U,
      2605208763U, 1441755014U, 181878989U, 3124053868U, 1447103986U,
      3183906156U, 1728556020U, 3502241336U, 3055466967U, 1013272474U,
      818402132U, 1715099063U, 2900113506U, 397254517U, 4194863039U, 1009068739U,
      232864647U, 2540223708U, 2608288560U, 2415367765U, 478404847U, 3455100648U,
      3182600021U, 2115988978U, 434269567U, 4117179324U, 3461774077U, 887256537U,
      3545801025U, 286388911U, 3451742129U, 1981164769U, 786667016U, 3310123729U,
      3097811076U, 2224235657U, 2959658883U, 3370969234U, 2514770915U,
      3345656436U, 2677010851U, 2206236470U, 271648054U, 2342188545U,
      4292848611U, 3646533909U, 3754009956U, 3803931226U, 4160647125U,
      1477814055U, 4043852216U, 1876372354U, 3133294443U, 3871104810U,
      3177020907U, 2074304428U, 3479393793U, 759562891U, 164128153U, 1839069216U,
      2114162633U, 3989947309U, 3611054956U, 1333547922U, 835429831U, 494987340U,
      171987910U, 1252001001U, 370809172U, 3508925425U, 2535703112U, 1276855041U,
      1922855120U, 835673414U, 3030664304U, 613287117U, 171219893U, 3423096126U,
      3376881639U, 2287770315U, 1658692645U, 1262815245U, 3957234326U,
      1168096164U, 2968737525U, 2655813712U, 2132313144U, 3976047964U,
      326516571U, 353088456U, 3679188938U, 3205649712U, 2654036126U, 1249024881U,
      880166166U, 691800469U, 2229503665U, 1673458056U, 4032208375U, 1851778863U,
      2563757330U, 376742205U, 1794655231U, 340247333U, 1505873033U, 396524441U,
      879666767U, 3335579166U, 3260764261U, 3335999539U, 506221798U, 4214658741U,
      975887814U, 2080536343U, 3360539560U, 571586418U, 138896374U, 4234352651U,
      2737620262U, 3928362291U, 1516365296U, 38056726U, 3599462320U, 3585007266U,
      3850961033U, 471667319U, 1536883193U, 2310166751U, 1861637689U,
      2530999841U, 4139843801U, 2710569485U, 827578615U, 2012334720U,
      2907369459U, 3029312804U, 2820112398U, 1965028045U, 35518606U, 2478379033U,
      643747771U, 1924139484U, 4123405127U, 3811735531U, 3429660832U,
      3285177704U, 1948416081U, 1311525291U, 1183517742U, 1739192232U,
      3979815115U, 2567840007U, 4116821529U, 213304419U, 4125718577U,
      1473064925U, 2442436592U, 1893310111U, 4195361916U, 3747569474U,
      828465101U, 2991227658U, 750582866U, 1205170309U, 1409813056U, 678418130U,
      1171531016U, 3821236156U, 354504587U, 4202874632U, 3882511497U,
      1893248677U, 1903078632U, 26340130U, 2069166240U, 3657122492U, 3725758099U,
      831344905U, 811453383U, 3447711422U, 2434543565U, 4166886888U, 3358210805U,
      4142984013U, 2988152326U, 3527824853U, 982082992U, 2809155763U, 190157081U,
      3340214818U, 2365432395U, 2548636180U, 2894533366U, 3474657421U,
      2372634704U, 2845748389U, 43024175U, 2774226648U, 1987702864U, 3186502468U,
      453610222U, 4204736567U, 1392892630U, 2471323686U, 2470534280U,
      3541393095U, 4269885866U, 3909911300U, 759132955U, 1482612480U, 667715263U,
      1795580598U, 2337923983U, 3390586366U, 581426223U, 1515718634U, 476374295U,
      705213300U, 363062054U, 2084697697U, 2407503428U, 2292957699U, 2426213835U,
      2199989172U, 1987356470U, 4026755612U, 2147252133U, 270400031U,
      1367820199U, 2369854699U, 2844269403U, 79981964U, 624U };

    swc_ATAU_ARID_DEF.ResettableDelay_Reset_ZCE = POS_ZCSIG;
    swc_ATAU_ARID_DEF.ResettableDelay4_Reset_ZCE = POS_ZCSIG;

    /* InitializeConditions for Delay: '<S17>/Resettable Delay' */
    swc_ATAU_ARID_DEF.icLoad = true;

    /* InitializeConditions for Delay: '<S18>/Resettable Delay4' */
    swc_ATAU_ARID_DEF.icLoad_p = true;

    /* InitializeConditions for UnitDelay: '<S5>/Unit Delay' */
    swc_ATAU_ARID_DEF.UnitDelay_DSTATE_e = true;

    /* InitializeConditions for UnitDelay: '<S5>/Unit Delay2' */
    swc_ATAU_ARID_DEF.UnitDelay2_DSTATE_p = true;

    /* SystemInitialize for Atomic SubSystem: '<S5>/turnON_delay4' */
    swc_ATAU_turnON_delay_Init(&rtb_flg_out);

    /* End of SystemInitialize for SubSystem: '<S5>/turnON_delay4' */

    /* SystemInitialize for Enabled SubSystem: '<S18>/Subsystem' */
    /* SystemInitialize for MATLAB Function: '<S55>/MATLAB Function' */
    memcpy(&swc_ATAU_ARID_DEF.state[0], &tmp[0], 625U * sizeof(uint32));
    swc_ATAU_ARID_DEF.method = 7U;
    swc_ATAU_ARID_DEF.state_l[0] = 362436069U;
    swc_ATAU_ARID_DEF.state_l[1] = 521288629U;
    swc_ATAU_ARID_DEF.state_h = 1144108930U;

    /* End of SystemInitialize for SubSystem: '<S18>/Subsystem' */

    /* SystemInitialize for Atomic SubSystem: '<S15>/turnON_delay' */
    swc_ATAU_turnON_delay_Init(&rtb_flg_out_m);

    /* End of SystemInitialize for SubSystem: '<S15>/turnON_delay' */

    /* SystemInitialize for Atomic SubSystem: '<S5>/turnON_delay' */
    swc_ATAU_turnON_delay_Init(&rtb_flg_out_p);

    /* End of SystemInitialize for SubSystem: '<S5>/turnON_delay' */

    /* SystemInitialize for Atomic SubSystem: '<S5>/turnON_delay1' */
    swc_ATAU_turnON_delay_Init(&rtb_flg_out_n);

    /* End of SystemInitialize for SubSystem: '<S5>/turnON_delay1' */

    /* SystemInitialize for Atomic SubSystem: '<S5>/turnON_delay2' */
    swc_ATAU_turnON_delay_Init(&rtb_flg_out_d);

    /* End of SystemInitialize for SubSystem: '<S5>/turnON_delay2' */

    /* SystemInitialize for Atomic SubSystem: '<S5>/turnON_delay3' */
    swc_ATAU_turnON_delay_Init(&rtb_flg_out_g);

    /* End of SystemInitialize for SubSystem: '<S5>/turnON_delay3' */

    /* ConstCode for DataTypeConversion: '<S3>/Data Type Conversion6' incorporates:
     *  Constant: '<S1>/Constant'
     */
    pmmd_b_xcuAuthEna = false;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

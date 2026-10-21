/*
 * File: swc_RMLK.c
 *
 * Code generated for Simulink model 'swc_RMLK'.
 *
 * Model version                  : 1.63
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Apr 14 10:15:08 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "swc_RMLK.h"
#include "rtwtypes.h"
#include <math.h>
#include <string.h>

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef VEH_SPD_MAX
#error The value of parameter "VEH_SPD_MAX" is not defined
#endif

/* Named constants for Chart: '<S9>/ChgAntiStateReq' */
#define swc_RMLK_IN_AntiActv           ((uint8)1U)
#define swc_RMLK_IN_AntiNotActv        ((uint8)2U)
#define swc_RMLK_IN_ChgAntiVerify      ((uint8)1U)
#define swc_RMLK_IN_FuelUpVerify       ((uint8)2U)
#define swc_RMLK_IN_KeyOnTimer         ((uint8)3U)
#define swc_RMLK_IN_NO_ACTIVE_CHILD    ((uint8)0U)
#define swc_RMLK_IN_UpdateAntiReq      ((uint8)3U)

/* Named constants for Chart: '<S9>/KeyOnAntiStateReq' */
#define swc_RMLK_IN_AntiReqVerify      ((uint8)1U)
#define swc_RMLK_IN_ChgAnti            ((uint8)2U)

/* Named constants for Chart: '<S10>/AuthState' */
#define swc_RMLK_IN_CmdExecutedFail    ((uint8)1U)
#define swc_RMLK_IN_Default            ((uint8)2U)
#define swc_RMLK_IN_DefualtAuthFail    ((uint8)3U)
#define swc_RMLK_IN_DefualtAuthSuccess ((uint8)4U)
#define swc_RMLK_IN_LockAuthFail       ((uint8)5U)
#define swc_RMLK_IN_LockAuthSuccess    ((uint8)6U)
#define swc_RMLK_IN_ReptAuthFrame1     ((uint8)7U)
#define swc_RMLK_IN_ReptAuthFrame2     ((uint8)8U)
#define swc_RMLK_IN_ReptAuthFrame3     ((uint8)9U)
#define swc_RMLK_IN_ReptAuthFrame4     ((uint8)10U)
#define swc_RMLK_IN_ReptAuthFrame5     ((uint8)11U)
#define swc_RMLK_IN_ReptDefault        ((uint8)12U)
#define swc_RMLK_IN_SeedReq            ((uint8)13U)

/* Named constants for Chart: '<S149>/timed_delay' */
#define swc_RMLK_IN_OFF                ((uint8)1U)
#define swc_RMLK_IN_OFF_WAIT           ((uint8)2U)
#define swc_RMLK_IN_ON                 ((uint8)3U)

/* Named constants for Chart: '<S180>/fuelUpMode' */
#define swc_RMLK_IN_Defualt            ((uint8)1U)
#define swc_RMLK_IN_DelayB             ((uint8)1U)
#define swc_RMLK_IN_FuelUpMet          ((uint8)2U)
#define swc_RMLK_IN_FuelUpMetB         ((uint8)3U)
#define swc_RMLK_IN_MetB               ((uint8)2U)
#define swc_RMLK_IN_delayA             ((uint8)1U)
#define swc_RMLK_IN_getA1              ((uint8)2U)
#define swc_RMLK_IN_getA2              ((uint8)3U)
#define swc_RMLK_IN_getB1              ((uint8)3U)

/* Named constants for Chart: '<S184>/ExeSts' */
#define swc_RMLK_IN_ExcuteLock         ((uint8)2U)
#define swc_RMLK_IN_ExcuteLockFailed   ((uint8)3U)
#define swc_RMLK_IN_ExcuteUnLockFailed ((uint8)4U)
#define swc_RMLK_IN_ExcuteUnlock       ((uint8)5U)
#define swc_RMLK_IN_HoldLockSts        ((uint8)6U)
#define swc_RMLK_IN_HoldUnlockSts      ((uint8)7U)
#define swc_RMLK_IN_LockReq            ((uint8)8U)
#define swc_RMLK_IN_UnlockReq          ((uint8)9U)

/* Named constants for Chart: '<S186>/Chart' */
#define swc_RMLK_IN_AntiLockTyp        ((uint8)1U)
#define swc_RMLK_IN_ChgLockTyp         ((uint8)2U)
#define swc_RMLK_IN_InitLockTyp        ((uint8)3U)
#define swc_RMLK_IN_NormlLockTyp       ((uint8)4U)

/* Named constants for Chart: '<S27>/timed_delay' */
#define swc_RMLK_IN_ON_WAIT            ((uint8)3U)
#define swc_RMLK_IN_ON_l               ((uint8)2U)

/* Exported data definition */
#define swc_RMLK_START_SEC_CONST_VOLATILE
#include "swc_RMLK_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_CAL */
const volatile boolean rlcc_b_VSLTEST1_sw = false;/* Referenced by: '<S9>/Constant3' */
const volatile boolean rlcc_b_VSLTEST2_sw = false;/* Referenced by: '<S9>/Constant11' */
const volatile boolean rlcc_b_VSLTEST3_sw = false;/* Referenced by: '<S9>/Constant13' */
const volatile boolean rlcc_b_VSLTEST5_sw = false;/* Referenced by: '<S7>/Constant14' */
const volatile boolean rlcc_b_useEskNvmDataEna = true;/* Referenced by: '<S145>/Constant9' */
const volatile float32 rlcc_n_igOnDelayCnt = 5.0F;/* Referenced by: '<S26>/Constant1' */
const volatile uint32 rlcc_n_pwrCntAntiLock = 2U;/* Referenced by: '<S17>/Constant' */
const volatile uint8 rlcc_n_useEskNvmDataDefualt[16] = { 0U, 1U, 2U, 3U, 4U, 5U,
  6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U } ;/* Referenced by: '<S145>/Constant4' */

const volatile float32 rlcc_tm_antiChgTm_s = 120.0F;/* Referenced by: '<S9>/Constant17' */
const volatile float32 rlcc_tm_antiKL15Tm_s = 60.0F;/* Referenced by:
                                                     * '<S9>/Constant16'
                                                     * '<S9>/Constant5'
                                                     */
const volatile float32 rlcc_tm_fuleUpA1Dly_s = 10.0F;/* Referenced by: '<S180>/Constant2' */
const volatile float32 rlcc_tm_fuleUpA2Dly_s = 10.0F;/* Referenced by: '<S180>/Constant3' */
const volatile float32 rlcc_tm_fuleUpB1Dly_s = 10.0F;/* Referenced by: '<S180>/Constant4' */
const volatile float32 rlcc_tm_fuleUpB2Dly_s = 10.0F;/* Referenced by: '<S180>/Constant5' */
const volatile float32 rlcc_tm_fuleUpB3Dly_s = 10.0F;/* Referenced by: '<S180>/Constant6' */
const volatile float32 rlcc_v_VehSpdMax_kph = 240.0F;/* Referenced by:
                                                      * '<S20>/Constant4'
                                                      * '<S20>/Constant5'
                                                      */
const volatile float32 rlcc_v_antiDismantleSpdLim_kph = 5.0F;/* Referenced by: '<S20>/Constant6' */
const volatile float32 rlcc_v_fuleLv1 = 5.0F;/* Referenced by: '<S180>/Constant' */
const volatile float32 rlcc_v_fuleLv2 = 10.0F;/* Referenced by: '<S180>/Constant1' */
const volatile float32 rlcc_v_normLockSpdLimDft_kph = 20.0F;/* Referenced by: '<S20>/Unit Delay1' */
const volatile float32 rlcc_v_normlLckSpd_kph = 3.0F;/* Referenced by: '<S26>/Constant3' */
const volatile float32 rlcc_v_rmtCtrlPedlOff_kph = 5.0F;/* Referenced by: '<S20>/Constant1' */
const volatile float32 rlcc_v_rmtCtrlTqOff_kph = 1.0F;/* Referenced by: '<S20>/Constant7' */
const volatile float32 rlcc_v_vehSpdUpdLimCfg_kph = 20.0F;/* Referenced by: '<S20>/Constant2' */
const volatile float32 rlcv_v_vehSpdLimCfg_kph[4] = { 0.0F, 5.0F, 10.0F, 20.0F }
;                                     /* Referenced by: '<S19>/TV4V2_Status5' */

#define swc_RMLK_STOP_SEC_CONST_VOLATILE
#include "swc_RMLK_MemMap.h"
#define swc_RMLK_START_SEC_VAR
#include "swc_RMLK_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_SIG */
uint8 rlcd_TBOXFunAntiDismantleActive; /* '<S5>/Data Type Conversion8' */
uint8 rlcd_TBOX_FunLockVehActive;      /* '<S5>/Data Type Conversion9' */
uint8 rlcd_TBOX_Key[7];                /* '<S5>/Data Type Conversion24' */
uint8 rlcd_TBOX_LockLimSet;            /* '<S5>/Data Type Conversion10' */
uint8 rlcd_TBOX_LockVehCtrl;           /* '<S5>/Data Type Conversion11' */
uint8 rlcd_TBOX_LockVehType;           /* '<S5>/Data Type Conversion12' */
uint8 rlcd_TBOX_Update;                /* '<S5>/Data Type Conversion23' */
boolean rlcd_b_ChgAntiLockReq;         /* '<S9>/SR_latch2' */
boolean rlcd_b_ChgLockExcReqCur;       /* '<S9>/Logical Operator' */
boolean rlcd_b_LockVehResults;         /* '<S185>/Logical Operator5' */
boolean rlcd_b_NormLockActv;           /* '<S26>/Logical Operator2' */
boolean rlcd_b_NormLockActvRaw;        /* '<S26>/SR_latch1' */
boolean rlcd_b_NormLockNotActv;        /* '<S26>/Logical Operator3' */
boolean rlcd_b_aswTboxUpdate;          /* '<S10>/Logical Operator11' */
boolean rlcd_b_chgAnti_flg;            /* '<S273>/Logical Operator' */
boolean rlcd_b_cmdFail_flg;            /* '<S10>/Logical Operator21' */
boolean rlcd_b_cmdLockAuth_flg;        /* '<S10>/Logical Operator12' */
boolean rlcd_b_defualtAuth_flg;        /* '<S10>/Logical Operator5' */
boolean rlcd_b_frameUpdateFlg;         /* '<S150>/timed_delay' */
boolean rlcd_b_fuelUpAntiLockReq;      /* '<S180>/Logical Operator6' */
boolean rlcd_b_fuelUpCalEna;           /* '<S180>/Logical Operator1' */
boolean rlcd_b_fuelUpNormalLockReq;    /* '<S180>/Logical Operator3' */
boolean rlcd_b_fuleUpAntiLockExcReq;   /* '<S9>/SR_latch4' */
boolean rlcd_b_ignOn;                  /* '<S5>/Data Type Conversion14' */
boolean rlcd_b_obcWakeUp;              /* '<S5>/Data Type Conversion15' */
boolean rlcd_b_rmtCtrlAntiDismtLock;   /* '<S14>/Compare' */
boolean rlcd_b_rmtCtrlChrgLock;        /* '<S13>/Compare' */
boolean rlcd_b_rmtCtrlNormLock;        /* '<S12>/Compare' */
boolean rlcd_b_tboxCmd_flg;            /* '<S10>/Logical Operator10' */
boolean rlcd_b_tboxKey_flg;            /* '<S10>/Logical Operator9' */
uint32 rlcd_n_flashCnt;                /* '<S17>/Switch8' */
uint16 rlcd_n_gcvRlcVer;               /* '<S4>/Constant' */
uint32 rlcd_n_pwrCntDiff;              /* '<S17>/Add' */
uint32 rlcd_n_rmlkIgOnCnt;             /* '<S17>/Saturation' */
uint8 rlcd_num_AntiLockReq;            /* '<S9>/Switch15' */
uint8 rlcd_num_ChgLockExcReq;          /* '<S9>/Switch14' */
uint8 rlcd_num_ChgLockReq;             /* '<S9>/Switch13' */
uint8 rlcd_num_ExeStsUpdate;           /* '<S184>/ExeSts' */
uint8 rlcd_num_ExeStsUpdate1;          /* '<S184>/ExeSts' */
uint8 rlcd_num_ExeStsUpdate1SaveResult;/* '<S5>/Data Type Conversion25' */
uint8 rlcd_num_ExeStsUpdateSaveResult; /* '<S5>/Data Type Conversion16' */
uint8 rlcd_num_FunAnti_DismantleActiveReq;/* '<S8>/Switch6' */
uint8 rlcd_num_FunLockVehActiveReq;    /* '<S8>/Switch1' */
uint8 rlcd_num_LockLimSetReq;          /* '<S7>/Switch11' */
uint8 rlcd_num_NormLockReq;            /* '<S9>/Switch12' */
uint8 rlcd_num_NormLockReqRaw;         /* '<S9>/Switch3' */
uint8 rlcd_num_NormLockSaveRltRaw;     /* '<S26>/Switch8' */
uint8 rlcd_num_VCU_AntiLockSaveResult; /* '<S5>/Data Type Conversion6' */
uint8 rlcd_num_VCU_AuthResult;         /* '<S10>/AuthState' */
uint8 rlcd_num_VCU_ChgLockExcSaveResult;/* '<S5>/Data Type Conversion5' */
uint8 rlcd_num_VCU_ChgLockSaveResult;  /* '<S5>/Data Type Conversion4' */
uint8 rlcd_num_VCU_FunAnti_DismantleActiveResult;/* '<S5>/Data Type Conversion2' */
uint8 rlcd_num_VCU_FunLockVehActiveResult;/* '<S5>/Data Type Conversion1' */
uint8 rlcd_num_VCU_LockLimSetSaveResult;/* '<S5>/Data Type Conversion' */
uint8 rlcd_num_VCU_NormLockSaveResult; /* '<S5>/Data Type Conversion3' */
uint8 rlcd_num_pmsRespResult;          /* '<S10>/AuthState' */
uint8 rlcd_num_rmtLkSpdLimCfg;         /* '<S19>/Switch17' */
uint8 rlcd_num_rmtLkSpdLimCfg3;        /* '<S176>/Switch4' */
uint8 rlcd_num_rmtLkSpdLimCfgInit;     /* '<S19>/Switch1' */
uint8 rlcd_st_FuelingStatus;           /* '<S180>/Unit Delay' */
uint8 rlcd_st_LockVehExecutedSts;      /* '<S184>/ExeSts' */
uint8 rlcd_st_LockVehExecutedStsOut;   /* '<S184>/ExeSts' */
uint8 rlcd_st_authState;               /* '<S10>/AuthState' */
float32 rlcd_v_fuelA1Pos;              /* '<S180>/fuelUpMode' */
float32 rlcd_v_fuelA2Pos;              /* '<S180>/fuelUpMode' */
float32 rlcd_v_fuelB1Pos;              /* '<S180>/fuelUpMode' */
uint8 rlcd_v_pmsReqSeed[7];            /* '<S10>/AuthState' */
uint8 rlcd_v_remoteEskBsw[16];         /* '<S5>/Data Type Conversion7' */
float32 rlcd_v_rmtCtrlFctSpdLimCfg_kph;/* '<S19>/Index Vector1' */
uint8 rlcd_v_tboxKeyVect[7];           /* '<S4>/Signal Conversion' */
float32 rlcd_v_vehSpd_kph;             /* '<S5>/Data Type Conversion13' */

#define swc_RMLK_STOP_SEC_VAR
#include "swc_RMLK_MemMap.h"

/* Invariant block signals (default storage) */
const ConstB_swc_RMLK_T swc_RMLK_ConstB = {
  0.1F,                                /* '<S27>/Saturation' */
  0.3F                                 /* '<S149>/Saturation1' */
};

/* Constant parameters (default storage) */
const ConstP_swc_RMLK_T swc_RMLK_ConstP = {
  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S146>/Constant1'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Pooled Parameter (Expression: [170 170 170 170 170 170 170])
   * Referenced by:
   *   '<S10>/Constant2'
   *   '<S10>/Constant4'
   */
  { 170U, 170U, 170U, 170U, 170U, 170U, 170U },

  /* Pooled Parameter (Expression: [0 0 0 0 0 0 0])
   * Referenced by:
   *   '<S10>/Constant3'
   *   '<S10>/Constant5'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U }
};

/* PublicStructure Variables for Internal Data */
ARID_DEF_swc_RMLK_T swc_RMLK_ARID_DEF;
static void swc_RMLK_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch_swc_RMLK_T *swc_RMLK__ARID_DEF_arg);
static void swc_RMLK_SR_latch1(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch1_swc_RMLK_T *swc_RMLK__ARID_DEF_arg);
static void swc_RMLK_SR_latch2(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch2_swc_RMLK_T *swc_RMLK__ARID_DEF_arg);
static void swc_RMLK_Falling_Edge1(boolean rtu_flg_in, boolean *rty_flg_out,
  ARID_DEF_Falling_Edge1_swc_RM_T *swc_RMLK__ARID_DEF_arg);
static void swc_RMLK_EnabledSubsystem(boolean rtu_Enable, uint32 rtu_Inport);

/* Forward declaration for local functions */
static float64 swc_RMLK_rand(void);
static void enter_atomic_DefualtAuthSuccess(void);
static void sw_enter_atomic_LockAuthSuccess(void);
static void swc_RMLK_SeedReq(const boolean *TBOX_AuthSuccess);
static void swc_RMLK_enter_atomic_Default(void);
static void swc_R_enter_atomic_LockAuthFail(void);
static void sw_enter_atomic_CmdExecutedFail(void);
static void sw_enter_atomic_DefualtAuthFail(void);
static void swc_RMLK_ReptDefault(const boolean *TBOX_AuthFail_dismatch, const
  boolean *TBOX_AuthSuccess);

/*
 * Output and update for atomic system:
 *    '<S9>/SR_latch'
 *    '<S10>/SR_latch'
 */
static void swc_RMLK_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch_swc_RMLK_T *swc_RMLK__ARID_DEF_arg)
{
  /* Logic: '<S109>/Logical Operator3' incorporates:
   *  Logic: '<S109>/Logical Operator'
   *  Logic: '<S109>/Logical Operator1'
   *  UnitDelay: '<S109>/Unit Delay'
   */
  *rty_flg_out = ((swc_RMLK__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) && (
    !rtu_flg_reset));

  /* Update for UnitDelay: '<S109>/Unit Delay' */
  swc_RMLK__ARID_DEF_arg->UnitDelay_DSTATE = *rty_flg_out;
}

/*
 * Output and update for atomic system:
 *    '<S9>/SR_latch1'
 *    '<S9>/SR_latch5'
 *    '<S26>/SR_latch1'
 */
static void swc_RMLK_SR_latch1(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch1_swc_RMLK_T *swc_RMLK__ARID_DEF_arg)
{
  /* Logic: '<S110>/Logical Operator3' incorporates:
   *  Logic: '<S110>/Logical Operator'
   *  Logic: '<S110>/Logical Operator1'
   *  UnitDelay: '<S110>/Unit Delay'
   */
  *rty_flg_out = ((swc_RMLK__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) && (
    !rtu_flg_reset));

  /* Update for UnitDelay: '<S110>/Unit Delay' */
  swc_RMLK__ARID_DEF_arg->UnitDelay_DSTATE = *rty_flg_out;
}

/*
 * Output and update for atomic system:
 *    '<S9>/SR_latch2'
 *    '<S9>/SR_latch4'
 */
static void swc_RMLK_SR_latch2(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch2_swc_RMLK_T *swc_RMLK__ARID_DEF_arg)
{
  /* Logic: '<S111>/Logical Operator3' incorporates:
   *  Logic: '<S111>/Logical Operator'
   *  Logic: '<S111>/Logical Operator1'
   *  UnitDelay: '<S111>/Unit Delay'
   */
  *rty_flg_out = ((swc_RMLK__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) && (
    !rtu_flg_reset));

  /* Update for UnitDelay: '<S111>/Unit Delay' */
  swc_RMLK__ARID_DEF_arg->UnitDelay_DSTATE = *rty_flg_out;
}

/*
 * Output and update for atomic system:
 *    '<S4>/Falling_Edge1'
 *    '<S17>/Falling_Edge'
 *    '<S227>/Falling_Edge'
 *    '<S227>/Falling_Edge1'
 *    '<S239>/Falling_Edge'
 *    '<S239>/Falling_Edge1'
 */
static void swc_RMLK_Falling_Edge1(boolean rtu_flg_in, boolean *rty_flg_out,
  ARID_DEF_Falling_Edge1_swc_RM_T *swc_RMLK__ARID_DEF_arg)
{
  /* Logic: '<S16>/Logical Operator1' incorporates:
   *  Logic: '<S16>/Logical Operator2'
   *  UnitDelay: '<S16>/Unit Delay'
   */
  *rty_flg_out = (swc_RMLK__ARID_DEF_arg->UnitDelay_DSTATE && (!rtu_flg_in));

  /* Update for UnitDelay: '<S16>/Unit Delay' */
  swc_RMLK__ARID_DEF_arg->UnitDelay_DSTATE = rtu_flg_in;
}

/*
 * Output and update for enable system:
 *    '<S17>/Enabled Subsystem'
 *    '<S17>/Enabled Subsystem1'
 */
static void swc_RMLK_EnabledSubsystem(boolean rtu_Enable, uint32 rtu_Inport)
{
  /* Outputs for Enabled SubSystem: '<S17>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S160>/Enable'
   */
  if (rtu_Enable) {
    /* CCaller: '<S160>/C Caller' */
    mBSW_NvmWrite_FlashCnt(rtu_Inport);
  }

  /* End of Outputs for SubSystem: '<S17>/Enabled Subsystem' */
}

/* Function for MATLAB Function: '<S146>/MATLAB Function' */
static float64 swc_RMLK_rand(void)
{
  float64 r;
  sint32 b_k;
  sint32 kk;
  uint32 u[2];
  switch (swc_RMLK_ARID_DEF.method) {
   case 4U:
    {
      uint32 mti;
      uint32 y;
      b_k = (sint32)(swc_RMLK_ARID_DEF.state / 127773U);
      mti = (swc_RMLK_ARID_DEF.state - (uint32)b_k * 127773U) * 16807U;
      y = 2836U * (uint32)b_k;
      if (mti < y) {
        mti = ~(y - mti) & 2147483647U;
      } else {
        mti -= y;
      }

      r = (float64)mti * 4.6566128752457969E-10;
      swc_RMLK_ARID_DEF.state = mti;
    }
    break;

   case 5U:
    {
      uint32 mti;
      uint32 y;
      mti = 69069U * swc_RMLK_ARID_DEF.state_i[0] + 1234567U;
      y = swc_RMLK_ARID_DEF.state_i[1] << 13 ^ swc_RMLK_ARID_DEF.state_i[1];
      y ^= y >> 17;
      y ^= y << 5;
      swc_RMLK_ARID_DEF.state_i[0] = mti;
      swc_RMLK_ARID_DEF.state_i[1] = y;
      r = (float64)(mti + y) * 2.328306436538696E-10;
    }
    break;

   default:
    {
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
        for (b_k = 0; b_k < 2; b_k++) {
          uint32 y;
          mti = swc_RMLK_ARID_DEF.state_b[624] + 1U;
          if (swc_RMLK_ARID_DEF.state_b[624] + 1U >= 625U) {
            for (kk = 0; kk < 227; kk++) {
              mti = (swc_RMLK_ARID_DEF.state_b[kk + 1] & 2147483647U) |
                (swc_RMLK_ARID_DEF.state_b[kk] & 2147483648U);
              if ((mti & 1U) == 0U) {
                mti >>= 1U;
              } else {
                mti = mti >> 1U ^ 2567483615U;
              }

              swc_RMLK_ARID_DEF.state_b[kk] = swc_RMLK_ARID_DEF.state_b[kk + 397]
                ^ mti;
            }

            for (kk = 0; kk < 396; kk++) {
              mti = (swc_RMLK_ARID_DEF.state_b[kk + 227] & 2147483648U) |
                (swc_RMLK_ARID_DEF.state_b[kk + 228] & 2147483647U);
              if ((mti & 1U) == 0U) {
                mti >>= 1U;
              } else {
                mti = mti >> 1U ^ 2567483615U;
              }

              swc_RMLK_ARID_DEF.state_b[kk + 227] = swc_RMLK_ARID_DEF.state_b[kk]
                ^ mti;
            }

            mti = (swc_RMLK_ARID_DEF.state_b[623] & 2147483648U) |
              (swc_RMLK_ARID_DEF.state_b[0] & 2147483647U);
            if ((mti & 1U) == 0U) {
              mti >>= 1U;
            } else {
              mti = mti >> 1U ^ 2567483615U;
            }

            swc_RMLK_ARID_DEF.state_b[623] = swc_RMLK_ARID_DEF.state_b[396] ^
              mti;
            mti = 1U;
          }

          y = swc_RMLK_ARID_DEF.state_b[(sint32)mti - 1];
          swc_RMLK_ARID_DEF.state_b[624] = mti;
          y ^= y >> 11U;
          y ^= y << 7U & 2636928640U;
          y ^= y << 15U & 4022730752U;
          u[b_k] = y >> 18U ^ y;
        }

        r = ((float64)(u[0] >> 5U) * 6.7108864E+7 + (float64)(u[1] >> 6U)) *
          1.1102230246251565E-16;
        if (r == 0.0) {
          boolean b_isvalid;
          b_isvalid = ((swc_RMLK_ARID_DEF.state_b[624] >= 1U) &&
                       (swc_RMLK_ARID_DEF.state_b[624] < 625U));
          if (b_isvalid) {
            boolean exitg2;
            b_isvalid = false;
            b_k = 1;
            exitg2 = false;
            while ((!exitg2) && (b_k < 625)) {
              if (swc_RMLK_ARID_DEF.state_b[b_k - 1] == 0U) {
                b_k++;
              } else {
                b_isvalid = true;
                exitg2 = true;
              }
            }
          }

          if (!b_isvalid) {
            mti = 5489U;
            swc_RMLK_ARID_DEF.state_b[0] = 5489U;
            for (b_k = 0; b_k < 623; b_k++) {
              mti = ((mti >> 30U ^ mti) * 1812433253U + (uint32)b_k) + 1U;
              swc_RMLK_ARID_DEF.state_b[b_k + 1] = mti;
            }

            swc_RMLK_ARID_DEF.state_b[624] = 624U;
          }
        } else {
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    break;
  }

  return r;
}

/* Function for Chart: '<S10>/AuthState' */
static void enter_atomic_DefualtAuthSuccess(void)
{
  rlcd_st_authState = 7U;
  rlcd_num_VCU_AuthResult = 1U;
  rlcd_num_pmsRespResult = 3U;
  rlcd_v_pmsReqSeed[0] = 170U;
  rlcd_v_pmsReqSeed[1] = 170U;
  rlcd_v_pmsReqSeed[2] = 170U;
  rlcd_v_pmsReqSeed[3] = 170U;
  rlcd_v_pmsReqSeed[4] = 170U;
  rlcd_v_pmsReqSeed[5] = 170U;
  rlcd_v_pmsReqSeed[6] = 170U;
  swc_RMLK_ARID_DEF.timer_d += 0.01F;
}

/* Function for Chart: '<S10>/AuthState' */
static void sw_enter_atomic_LockAuthSuccess(void)
{
  rlcd_st_authState = 6U;
  rlcd_num_VCU_AuthResult = 1U;
  rlcd_num_pmsRespResult = 1U;
  rlcd_v_pmsReqSeed[0] = 170U;
  rlcd_v_pmsReqSeed[1] = 170U;
  rlcd_v_pmsReqSeed[2] = 170U;
  rlcd_v_pmsReqSeed[3] = 170U;
  rlcd_v_pmsReqSeed[4] = 170U;
  rlcd_v_pmsReqSeed[5] = 170U;
  rlcd_v_pmsReqSeed[6] = 170U;
  swc_RMLK_ARID_DEF.timer_d += 0.01F;
}

/* Function for Chart: '<S10>/AuthState' */
static void swc_RMLK_SeedReq(const boolean *TBOX_AuthSuccess)
{
  rlcd_st_authState = 2U;
  rlcd_num_VCU_AuthResult = 3U;
  rlcd_num_pmsRespResult = 3U;
  if ((*TBOX_AuthSuccess) && (swc_RMLK_ARID_DEF.AuthType == 2) &&
      (!rlcd_b_cmdFail_flg)) {
    swc_RMLK_ARID_DEF.timer_d = 0.01F;
    swc_RMLK_ARID_DEF.ReqCnt = 1U;
    swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_LockAuthSuccess;
    sw_enter_atomic_LockAuthSuccess();
  } else if ((*TBOX_AuthSuccess) && (swc_RMLK_ARID_DEF.AuthType == 1)) {
    swc_RMLK_ARID_DEF.timer_d = 0.01F;
    swc_RMLK_ARID_DEF.ReqCnt = 1U;
    swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_DefualtAuthSuccess;
    enter_atomic_DefualtAuthSuccess();
  } else if (swc_RMLK_ARID_DEF.timer_d > 0.01F) {
    swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_ReptDefault;
    rlcd_st_authState = 3U;
    rlcd_num_VCU_AuthResult = 0U;
    rlcd_num_pmsRespResult = 0U;
    rlcd_v_pmsReqSeed[0] = 0U;
    rlcd_v_pmsReqSeed[1] = 0U;
    rlcd_v_pmsReqSeed[2] = 0U;
    rlcd_v_pmsReqSeed[3] = 0U;
    rlcd_v_pmsReqSeed[4] = 0U;
    rlcd_v_pmsReqSeed[5] = 0U;
    rlcd_v_pmsReqSeed[6] = 0U;
    swc_RMLK_ARID_DEF.timer_d = 0.02F;
  }
}

/* Function for Chart: '<S10>/AuthState' */
static void swc_RMLK_enter_atomic_Default(void)
{
  rlcd_st_authState = 0U;
  swc_RMLK_ARID_DEF.timer_d = 0.01F;
  swc_RMLK_ARID_DEF.ReqCnt = 1U;
  rlcd_num_VCU_AuthResult = 0U;
  rlcd_num_pmsRespResult = 0U;
  rlcd_v_pmsReqSeed[0] = 0U;
  rlcd_v_pmsReqSeed[1] = 0U;
  rlcd_v_pmsReqSeed[2] = 0U;
  rlcd_v_pmsReqSeed[3] = 0U;
  rlcd_v_pmsReqSeed[4] = 0U;
  rlcd_v_pmsReqSeed[5] = 0U;
  rlcd_v_pmsReqSeed[6] = 0U;
  swc_RMLK_ARID_DEF.AuthType = 0U;
}

/* Function for Chart: '<S10>/AuthState' */
static void swc_R_enter_atomic_LockAuthFail(void)
{
  rlcd_st_authState = 5U;
  rlcd_num_VCU_AuthResult = 0U;
  rlcd_num_pmsRespResult = 0U;
  rlcd_v_pmsReqSeed[0] = 170U;
  rlcd_v_pmsReqSeed[1] = 170U;
  rlcd_v_pmsReqSeed[2] = 170U;
  rlcd_v_pmsReqSeed[3] = 170U;
  rlcd_v_pmsReqSeed[4] = 170U;
  rlcd_v_pmsReqSeed[5] = 170U;
  rlcd_v_pmsReqSeed[6] = 170U;
  swc_RMLK_ARID_DEF.timer_d += 0.01F;
}

/* Function for Chart: '<S10>/AuthState' */
static void sw_enter_atomic_CmdExecutedFail(void)
{
  rlcd_st_authState = 51U;
  rlcd_num_VCU_AuthResult = 1U;
  rlcd_num_pmsRespResult = 0U;
  rlcd_v_pmsReqSeed[0] = 170U;
  rlcd_v_pmsReqSeed[1] = 170U;
  rlcd_v_pmsReqSeed[2] = 170U;
  rlcd_v_pmsReqSeed[3] = 170U;
  rlcd_v_pmsReqSeed[4] = 170U;
  rlcd_v_pmsReqSeed[5] = 170U;
  rlcd_v_pmsReqSeed[6] = 170U;
  swc_RMLK_ARID_DEF.timer_d += 0.01F;
}

/* Function for Chart: '<S10>/AuthState' */
static void sw_enter_atomic_DefualtAuthFail(void)
{
  rlcd_st_authState = 4U;
  rlcd_num_VCU_AuthResult = 0U;
  rlcd_num_pmsRespResult = 3U;
  rlcd_v_pmsReqSeed[0] = 170U;
  rlcd_v_pmsReqSeed[1] = 170U;
  rlcd_v_pmsReqSeed[2] = 170U;
  rlcd_v_pmsReqSeed[3] = 170U;
  rlcd_v_pmsReqSeed[4] = 170U;
  rlcd_v_pmsReqSeed[5] = 170U;
  rlcd_v_pmsReqSeed[6] = 170U;
  swc_RMLK_ARID_DEF.timer_d += 0.01F;
}

/* Function for Chart: '<S10>/AuthState' */
static void swc_RMLK_ReptDefault(const boolean *TBOX_AuthFail_dismatch, const
  boolean *TBOX_AuthSuccess)
{
  sint32 i;
  rlcd_st_authState = 3U;
  rlcd_num_VCU_AuthResult = 0U;
  rlcd_num_pmsRespResult = 0U;
  if ((*TBOX_AuthSuccess) && (swc_RMLK_ARID_DEF.AuthType == 2) &&
      rlcd_b_cmdFail_flg) {
    swc_RMLK_ARID_DEF.timer_d = 0.01F;
    swc_RMLK_ARID_DEF.ReqCnt = 1U;
    swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_CmdExecutedFail;
    sw_enter_atomic_CmdExecutedFail();
  } else if ((*TBOX_AuthSuccess) && (swc_RMLK_ARID_DEF.AuthType == 2) &&
             (!rlcd_b_cmdFail_flg)) {
    swc_RMLK_ARID_DEF.timer_d = 0.01F;
    swc_RMLK_ARID_DEF.ReqCnt = 1U;
    swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_LockAuthSuccess;
    sw_enter_atomic_LockAuthSuccess();
  } else if ((*TBOX_AuthSuccess) && (swc_RMLK_ARID_DEF.AuthType == 1)) {
    swc_RMLK_ARID_DEF.timer_d = 0.01F;
    swc_RMLK_ARID_DEF.ReqCnt = 1U;
    swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_DefualtAuthSuccess;
    enter_atomic_DefualtAuthSuccess();
  } else {
    boolean guard1 = false;
    boolean guard2 = false;
    guard1 = false;
    guard2 = false;
    if ((*TBOX_AuthFail_dismatch) && (swc_RMLK_ARID_DEF.ReqCnt == 3) &&
        (swc_RMLK_ARID_DEF.timer_d > 0.3F) && (swc_RMLK_ARID_DEF.AuthType == 2))
    {
      swc_RMLK_ARID_DEF.timer_d = 0.01F;
      swc_RMLK_ARID_DEF.ReqCnt = 1U;
      guard1 = true;
    } else if ((*TBOX_AuthFail_dismatch) && (swc_RMLK_ARID_DEF.ReqCnt == 3) &&
               (swc_RMLK_ARID_DEF.timer_d > 0.3F) && (swc_RMLK_ARID_DEF.AuthType
                == 1)) {
      swc_RMLK_ARID_DEF.timer_d = 0.01F;
      swc_RMLK_ARID_DEF.ReqCnt = 1U;
      guard2 = true;
    } else if ((swc_RMLK_ARID_DEF.ReqCnt == 3) && (swc_RMLK_ARID_DEF.timer_d >
                0.3F) && (swc_RMLK_ARID_DEF.AuthType == 2)) {
      swc_RMLK_ARID_DEF.timer_d = 0.01F;
      swc_RMLK_ARID_DEF.ReqCnt = 1U;
      guard1 = true;
    } else if ((swc_RMLK_ARID_DEF.ReqCnt == 3) && (swc_RMLK_ARID_DEF.timer_d >
                0.3F) && (swc_RMLK_ARID_DEF.AuthType == 1)) {
      swc_RMLK_ARID_DEF.timer_d = 0.01F;
      swc_RMLK_ARID_DEF.ReqCnt = 1U;
      guard2 = true;
    } else if ((swc_RMLK_ARID_DEF.timer_d > 0.3F) && (swc_RMLK_ARID_DEF.ReqCnt <
                4)) {
      swc_RMLK_ARID_DEF.ReqCnt++;
      swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_SeedReq;
      rlcd_st_authState = 2U;
      swc_RMLK_ARID_DEF.timer_d += 0.01F;
      rlcd_num_VCU_AuthResult = 3U;
      rlcd_num_pmsRespResult = 3U;
      for (i = 0; i < 7; i++) {
        rlcd_v_pmsReqSeed[i] = swc_RMLK_ARID_DEF.out_o[i];
      }
    } else {
      swc_RMLK_ARID_DEF.timer_d += 0.01F;
    }

    if (guard2) {
      swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_DefualtAuthFail;
      sw_enter_atomic_DefualtAuthFail();
    }

    if (guard1) {
      swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_LockAuthFail;
      swc_R_enter_atomic_LockAuthFail();
    }
  }
}

/* Model step function */
void swc_RMLK_Step(void)
{
  /* local block i/o variables */
  uint8 rtb_CCaller1;
  uint8 rtb_CCaller2_m;
  uint8 rtb_CCaller4;
  uint8 rtb_CCaller3[7];
  uint8 rtb_UnitDelay3_bb;
  uint8 rtb_UnitDelay2_j;
  uint8 rtb_UnitDelay3_o;
  uint8 rtb_UnitDelay3_ai;
  uint8 rtb_UnitDelay3_nk;
  uint8 rtb_UnitDelay3_c;
  uint8 rtb_UnitDelay3_g;
  boolean rtb_LogicalOperator_j;
  boolean rtb_LogicalOperator_jt;
  boolean rtb_FixPtRelationalOperator_j;
  boolean rtb_LogicalOperator7;
  boolean rtb_Compare_em;
  boolean rtb_Compare_gl;
  boolean rtb_LogicalOperator4_a;
  boolean rtb_Compare_ev;
  boolean rtb_LogicalOperator11;
  boolean rtb_UnitDelay7;
  boolean rtb_LogicalOperator1_k;
  boolean rtb_LogicalOperator18_l;
  boolean rtb_LogicalOperator9;
  boolean rtb_LogicalOperator17_a;
  boolean rtb_Compare_as;
  boolean rtb_LogicalOperator3_pj;
  boolean rtb_flg_out_g;
  boolean rtb_flg_out_l;
  boolean rtb_flg_out_g5;
  boolean rtb_flg_out_d;
  boolean rtb_flg_out_e;
  boolean rtb_flg_out_eo;
  boolean rtb_LogicalOperator3_a;
  boolean rtb_LogicalOperator3_i;
  boolean rtb_LogicalOperator3_ic;
  boolean rtb_LogicalOperator3_k;
  boolean rtb_LogicalOperator4_l;
  float64 hashTbl[7];
  float64 link[7];
  float64 loc[7];
  float64 p[7];
  sint32 i;
  uint8 rtb_CCaller2_o[16];
  uint8 rtb_TmpSignalConversionAtSFunct[16];
  uint8 rtb_CCaller1_i[7];
  boolean rtb_RelationalOperator9[7];
  boolean TBOX_AuthFail_dismatch;
  boolean TBOX_AuthSuccess;

  /* Outputs for Enabled SubSystem: '<S1>/RMLK_Enable' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S17>/Constant1'
   *  Constant: '<S2>/Constant'
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   *  Inport generated from: '<Root>/In Bus Element9'
   *  Logic: '<S147>/Logical Operator'
   *  Logic: '<S147>/Logical Operator1'
   *  UnitDelay: '<S147>/Unit Delay'
   *
   * Block description for Inport generated from '<Root>/In Bus Element9':
   *  TBOX&#x9501;&#x8F66;&#x6307;&#x4EE4;
   */
  if (Rte_IRead_swc_RMLK_Step_vcib_VCIP_vild_st_flgFctCfgVehCfg() == ((uint8)0U))
  {
    float32 Switch1;
    float32 rtb_t_delay_off;
    uint32 rtb_CCaller;
    uint32 rtb_CCaller2;
    uint32 rtb_CCaller_g;
    uint32 rtb_Switch8;
    uint8 FunAntiDismtActiveResultCur;
    uint8 LockLimSetBswCur;
    uint8 Switch17;
    uint8 Switch1_h;
    uint8 Switch9;
    uint8 VCU_NormLockSaveResultCur;
    uint8 rlcd_num_AntiLockReq_b;
    uint8 rlcd_num_ChgLockReq_o;
    uint8 rlcd_num_ExeStsUpdate1_j;
    uint8 rtb_CCaller10;
    uint8 rtb_CCaller11;
    uint8 rtb_CCaller3_a;
    uint8 rtb_CCaller4_a;
    uint8 rtb_CCaller5;
    uint8 rtb_CCaller6;
    uint8 rtb_CCaller7;
    uint8 rtb_CCaller8;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_LockTyp;
    uint8 rtb_Switch1_g;
    uint8 rtb_Switch1_mx;
    uint8 rtb_Switch1_o;
    uint8 rtb_Switch5;
    uint8 rtb_Switch6;
    uint8 rtb_Switch8_i;
    uint8 rtb_Switch8_ib;
    uint8 rtb_UnitDelay3_f;
    uint8 rtb_UnitDelay3_hg;
    uint8 rtb_UnitDelay8;
    uint8 rtb_UnitDelay9_h;
    uint8 vsld_num_ChgLockExcReq;
    boolean TBOX_SeedReq;
    boolean guard1 = false;
    boolean rtb_Compare_dp;
    boolean rtb_Compare_fof;
    boolean rtb_Compare_hjh;
    boolean rtb_Compare_oc;
    boolean rtb_Compare_ok;
    boolean rtb_Compare_pv;
    boolean rtb_LogicalOperator1_o0;
    boolean rtb_LogicalOperator2_c;
    boolean rtb_LogicalOperator_oe;
    boolean rtb_RelationalOperator;
    boolean rtb_RelationalOperator5;
    boolean rtb_RelationalOperator_g;
    boolean rtb_RelationalOperator_j;
    boolean rtb_VariableIntegerDelay;
    swc_RMLK_ARID_DEF.RMLK_Enable_MODE = true;

    /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
     *  SubSystem: '<S3>/RmtLckCtrl_InputLayer_N72'
     */
    /* CCaller: '<S5>/C Caller10' */
    rtb_CCaller10 = mBSW_NvmRead_ExeStsUpdate();

    /* CCaller: '<S5>/C Caller11' */
    rtb_CCaller11 = mBSW_NvmRead_ExeStsUpdate1();
    for (i = 0; i < 16; i++) {
      /* CCaller: '<S5>/C Caller2' incorporates:
       *  SignalConversion generated from: '<S5>/C Caller2'
       */
      rtb_CCaller2_o[i] = 0U;
    }

    /* CCaller: '<S5>/C Caller2' */
    mBSW_Get_PMS_ESK(&rtb_CCaller2_o[0]);

    /* CCaller: '<S5>/C Caller3' */
    rtb_CCaller3_a = mBSW_NvmRead_LockLimSetReq();

    /* CCaller: '<S5>/C Caller4' */
    rtb_CCaller4_a = mBSW_NvmRead_FunLockVehActiveReq();

    /* CCaller: '<S5>/C Caller5' */
    rtb_CCaller5 = mBSW_NvmRead_FunAnti_DismantleActiveReq();

    /* CCaller: '<S5>/C Caller6' */
    rtb_CCaller6 = mBSW_NvmRead_NormLockReq();

    /* CCaller: '<S5>/C Caller7' */
    rtb_CCaller7 = mBSW_NvmRead_ChgLockReq();

    /* CCaller: '<S5>/C Caller8' */
    rtb_CCaller8 = mBSW_NvmRead_ChgLockExcReq();

    /* DataTypeConversion: '<S5>/Data Type Conversion6' incorporates:
     *  CCaller: '<S5>/C Caller'
     *  CCaller: '<S5>/C Caller9'
     */
    rlcd_num_VCU_AntiLockSaveResult = mBSW_NvmRead_AntiLockReq();

    /* DataTypeConversion: '<S5>/Data Type Conversion' */
    rlcd_num_VCU_LockLimSetSaveResult = rtb_CCaller3_a;

    /* DataTypeConversion: '<S5>/Data Type Conversion1' */
    rlcd_num_VCU_FunLockVehActiveResult = rtb_CCaller4_a;

    /* DataTypeConversion: '<S5>/Data Type Conversion16' */
    rlcd_num_ExeStsUpdateSaveResult = rtb_CCaller10;

    /* DataTypeConversion: '<S5>/Data Type Conversion2' */
    rlcd_num_VCU_FunAnti_DismantleActiveResult = rtb_CCaller5;

    /* DataTypeConversion: '<S5>/Data Type Conversion25' */
    rlcd_num_ExeStsUpdate1SaveResult = rtb_CCaller11;

    /* DataTypeConversion: '<S5>/Data Type Conversion3' */
    rlcd_num_VCU_NormLockSaveResult = rtb_CCaller6;

    /* DataTypeConversion: '<S5>/Data Type Conversion4' */
    rlcd_num_VCU_ChgLockSaveResult = rtb_CCaller7;

    /* DataTypeConversion: '<S5>/Data Type Conversion5' */
    rlcd_num_VCU_ChgLockExcSaveResult = rtb_CCaller8;
    for (i = 0; i < 16; i++) {
      /* DataTypeConversion: '<S5>/Data Type Conversion7' */
      rlcd_v_remoteEskBsw[i] = rtb_CCaller2_o[i];
    }

    /* DataTypeConversion: '<S5>/Data Type Conversion8' incorporates:
     *  Inport generated from: '<Root>/In Bus Element'
     *
     * Block description for Inport generated from '<Root>/In Bus Element':
     *  TBOX&#x8BF7;&#x6C42;&#x9632;&#x62C6;&#x6FC0;&#x6D3B;&#x6307;&#x4EE4;
     */
    rlcd_TBOXFunAntiDismantleActive =
      Rte_IRead_swc_RMLK_Step_vcib_VCIP_vild_st_TBOXFunAntiDismantleActive();

    /* DataTypeConversion: '<S5>/Data Type Conversion9' incorporates:
     *  Inport generated from: '<Root>/In Bus Element1'
     *
     * Block description for Inport generated from '<Root>/In Bus Element1':
     *  TBOX&#x8BF7;&#x6C42;&#x9501;&#x8F66;&#x529F;&#x80FD;&#x6307;&#x4EE4;
     */
    rlcd_TBOX_FunLockVehActive =
      Rte_IRead_swc_RMLK_Step_vcib_VCIP_vild_st_TBOXFunLockVehActive();

    /* DataTypeConversion: '<S5>/Data Type Conversion10' incorporates:
     *  Inport generated from: '<Root>/In Bus Element2'
     *
     * Block description for Inport generated from '<Root>/In Bus Element2':
     *  TBOX&#x9650;&#x901F;&#x6307;&#x4EE4;
     */
    rlcd_TBOX_LockLimSet =
      Rte_IRead_swc_RMLK_Step_vcib_VCIP_vild_st_TBOXLockLimSet();

    /* DataTypeConversion: '<S5>/Data Type Conversion11' incorporates:
     *  Inport generated from: '<Root>/In Bus Element3'
     *
     * Block description for Inport generated from '<Root>/In Bus Element3':
     *  TBOX&#x9501;&#x8F66;&#x6307;&#x4EE4;
     */
    rlcd_TBOX_LockVehCtrl =
      Rte_IRead_swc_RMLK_Step_vcib_VCIP_vild_st_TBOXLockVehCtrl();

    /* DataTypeConversion: '<S5>/Data Type Conversion12' incorporates:
     *  Inport generated from: '<Root>/In Bus Element4'
     *
     * Block description for Inport generated from '<Root>/In Bus Element4':
     *  TBOX&#x9501;&#x8F66;&#x7C7B;&#x578B;&#x6307;&#x4EE4;
     */
    rlcd_TBOX_LockVehType =
      Rte_IRead_swc_RMLK_Step_vcib_VCIP_vild_st_TBOXLockVehType();

    /* DataTypeConversion: '<S5>/Data Type Conversion13' incorporates:
     *  Inport generated from: '<Root>/In Bus Element5'
     *
     * Block description for Inport generated from '<Root>/In Bus Element5':
     *  &#x8F66;&#x901F;
     */
    rlcd_v_vehSpd_kph = Rte_IRead_swc_RMLK_Step_vcib_VCIP_vscd_v_vehSpd_kph();

    /* DataTypeConversion: '<S5>/Data Type Conversion14' incorporates:
     *  Inport generated from: '<Root>/In Bus Element6'
     *
     * Block description for Inport generated from '<Root>/In Bus Element6':
     *  KL15&#x5524;&#x9192;
     */
    rlcd_b_ignOn = Rte_IRead_swc_RMLK_Step_vcib_VCIP_pmmd_b_ignOn();

    /* DataTypeConversion: '<S5>/Data Type Conversion15' incorporates:
     *  Inport generated from: '<Root>/In Bus Element7'
     *
     * Block description for Inport generated from '<Root>/In Bus Element7':
     *  &#x5145;&#x7535;&#x5524;&#x9192;
     */
    rlcd_b_obcWakeUp = Rte_IRead_swc_RMLK_Step_vcib_VCIP_obcd_b_obcWakeUp();
    for (i = 0; i < 7; i++) {
      /* CCaller: '<S5>/C Caller1' incorporates:
       *  SignalConversion generated from: '<S5>/C Caller1'
       */
      rtb_CCaller1_i[i] = 0U;
    }

    /* CCaller: '<S5>/C Caller1' */
    mBSW_Get_TBOX_Key(&rtb_CCaller1_i[0]);
    for (i = 0; i < 7; i++) {
      /* DataTypeConversion: '<S5>/Data Type Conversion24' */
      rlcd_TBOX_Key[i] = rtb_CCaller1_i[i];
    }

    /* DataTypeConversion: '<S5>/Data Type Conversion23' incorporates:
     *  CCaller: '<S5>/C Caller'
     */
    rlcd_TBOX_Update = mBSW_ReceiveCtr_TBOX_Key();

    /* RelationalOperator: '<S274>/Compare' incorporates:
     *  Inport generated from: '<Root>/In Bus Element8'
     *  RelationalOperator: '<S275>/Compare'
     *  RelationalOperator: '<S276>/Compare'
     *
     * Block description for Inport generated from '<Root>/In Bus Element8':
     *  &#x5145;&#x7535;&#x5524;&#x9192;
     */
    rtb_CCaller10 = Rte_IRead_swc_RMLK_Step_vcib_VCIP_vild_st_actWorkSts1();

    /* Logic: '<S273>/Logical Operator' incorporates:
     *  Constant: '<S274>/Constant'
     *  Constant: '<S275>/Constant'
     *  Constant: '<S276>/Constant'
     *  Inport generated from: '<Root>/In Bus Element8'
     *  RelationalOperator: '<S274>/Compare'
     *  RelationalOperator: '<S275>/Compare'
     *  RelationalOperator: '<S276>/Compare'
     *
     * Block description for Inport generated from '<Root>/In Bus Element8':
     *  &#x5145;&#x7535;&#x5524;&#x9192;
     */
    rlcd_b_chgAnti_flg = ((rtb_CCaller10 == ((uint8)5U)) || (rtb_CCaller10 ==
      ((uint8)8U)) || (rtb_CCaller10 == ((uint8)9U)));

    /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
     *  SubSystem: '<S3>/RLC'
     */
    /* CCaller: '<S163>/C Caller' */
    rtb_CCaller = mBSW_NvmRead_RmlkIgOnCnt();

    /* RelationalOperator: '<S163>/Relational Operator' incorporates:
     *  UnitDelay: '<S163>/Unit Delay1'
     */
    rtb_RelationalOperator = (rtb_CCaller !=
      swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_o);

    /* Switch: '<S163>/Switch8' incorporates:
     *  Logic: '<S163>/Logical Operator4'
     *  Logic: '<S171>/Logical Operator'
     *  Logic: '<S171>/Logical Operator1'
     *  UnitDelay: '<S171>/Unit Delay'
     */
    if (rtb_RelationalOperator || (rlcd_b_ignOn &&
         (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_hv))) {
      /* Switch: '<S163>/Switch9' incorporates:
       *  Switch: '<S163>/Switch1'
       */
      if (rtb_RelationalOperator) {
        /* Switch: '<S163>/Switch8' incorporates:
         *  Switch: '<S163>/Switch9'
         */
        rtb_Switch8 = rtb_CCaller;
      } else {
        if (rlcd_b_ignOn) {
          /* Switch: '<S163>/Switch1' incorporates:
           *  Constant: '<S163>/Constant1'
           */
          Switch9 = ((uint8)1U);
        } else {
          /* Switch: '<S163>/Switch1' incorporates:
           *  Constant: '<S163>/Constant2'
           */
          Switch9 = ((uint8)0U);
        }

        /* Switch: '<S163>/Switch8' incorporates:
         *  Sum: '<S163>/Sum2'
         *  Switch: '<S163>/Switch1'
         *  Switch: '<S163>/Switch9'
         *  UnitDelay: '<S163>/Unit Delay3'
         */
        rtb_Switch8 = Switch9 + swc_RMLK_ARID_DEF.UnitDelay3_DSTATE;
      }

      /* End of Switch: '<S163>/Switch9' */
    } else {
      /* Switch: '<S163>/Switch8' incorporates:
       *  UnitDelay: '<S163>/Unit Delay2'
       */
      rtb_Switch8 = swc_RMLK_ARID_DEF.UnitDelay2_DSTATE;
    }

    /* End of Switch: '<S163>/Switch8' */

    /* Saturate: '<S17>/Saturation' */
    if (rtb_Switch8 <= 4294967290U) {
      /* Saturate: '<S17>/Saturation' */
      rlcd_n_rmlkIgOnCnt = rtb_Switch8;
    } else {
      /* Saturate: '<S17>/Saturation' */
      rlcd_n_rmlkIgOnCnt = 4294967290U;
    }

    /* End of Saturate: '<S17>/Saturation' */

    /* CCaller: '<S17>/C Caller1' */
    rtb_RelationalOperator = mBSW_HvShutDnReq();

    /* Logic: '<S166>/Logical Operator' incorporates:
     *  Logic: '<S166>/Logical Operator1'
     *  UnitDelay: '<S166>/Unit Delay'
     */
    rtb_LogicalOperator_j = (rtb_RelationalOperator &&
      (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_hp));

    /* Outputs for Enabled SubSystem: '<S17>/Enabled Subsystem' */
    swc_RMLK_EnabledSubsystem(rtb_LogicalOperator_j, rlcd_n_rmlkIgOnCnt);

    /* End of Outputs for SubSystem: '<S17>/Enabled Subsystem' */

    /* CCaller: '<S17>/C Caller' */
    rtb_CCaller_g = mBSW_NvmRead_RmlkIgOnCnt();

    /* CCaller: '<S9>/C Caller2' incorporates:
     *  CCaller: '<S17>/C Caller2'
     */
    rtb_CCaller2 = mBSW_NvmRead_FlashCnt();

    /* Switch: '<S17>/Switch8' incorporates:
     *  Logic: '<S164>/Logical Operator'
     *  Logic: '<S164>/Logical Operator1'
     *  UnitDelay: '<S164>/Unit Delay'
     */
    if (rlcd_b_ignOn && (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_j)) {
      /* Switch: '<S17>/Switch8' */
      rlcd_n_flashCnt = rtb_CCaller2;
    } else {
      /* Switch: '<S17>/Switch8' incorporates:
       *  UnitDelay: '<S17>/Unit Delay'
       */
      rlcd_n_flashCnt = swc_RMLK_ARID_DEF.UnitDelay_DSTATE;
    }

    /* End of Switch: '<S17>/Switch8' */

    /* MinMax: '<S17>/Max' */
    if (rtb_CCaller_g < rlcd_n_flashCnt) {
      rtb_CCaller_g = rlcd_n_flashCnt;
    }

    /* Sum: '<S17>/Add' incorporates:
     *  MinMax: '<S17>/Max'
     */
    rlcd_n_pwrCntDiff = rtb_CCaller_g - rlcd_n_flashCnt;

    /* RelationalOperator: '<S17>/Relational Operator' incorporates:
     *  Constant: '<S17>/Constant'
     */
    rtb_RelationalOperator_g = (rlcd_n_pwrCntDiff == rlcc_n_pwrCntAntiLock);

    /* Logic: '<S165>/Logical Operator' incorporates:
     *  Logic: '<S165>/Logical Operator1'
     *  UnitDelay: '<S165>/Unit Delay'
     */
    rtb_LogicalOperator_jt = (rtb_RelationalOperator_g &&
      (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_k));

    /* Outputs for Enabled SubSystem: '<S17>/Enabled Subsystem1' */
    swc_RMLK_EnabledSubsystem(rtb_LogicalOperator_jt, 0U);

    /* End of Outputs for SubSystem: '<S17>/Enabled Subsystem1' */

    /* Outputs for Atomic SubSystem: '<S17>/Falling_Edge' */
    swc_RMLK_Falling_Edge1(rlcd_b_ignOn, &rtb_flg_out_e,
      &swc_RMLK_ARID_DEF.ARID_DEF_Falling_Edge_k);

    /* End of Outputs for SubSystem: '<S17>/Falling_Edge' */

    /* Outputs for Enabled SubSystem: '<S17>/Write_KeyOnCnt' incorporates:
     *  EnablePort: '<S167>/Enable'
     */
    if (rtb_flg_out_e) {
      /* CCaller: '<S167>/C Caller' */
      mBSW_NvmWrite_RmlkIgOnCnt(rlcd_n_rmlkIgOnCnt);
    }

    /* End of Outputs for SubSystem: '<S17>/Write_KeyOnCnt' */

    /* Switch: '<S18>/Switch8' incorporates:
     *  Constant: '<S17>/Constant1'
     *  Logic: '<S172>/Logical Operator'
     *  Logic: '<S172>/Logical Operator1'
     *  Logic: '<S173>/Logical Operator'
     *  Logic: '<S173>/Logical Operator1'
     *  Logic: '<S18>/Logical Operator'
     *  UnitDelay: '<S172>/Unit Delay'
     *  UnitDelay: '<S173>/Unit Delay'
     *  UnitDelay: '<S18>/Unit Delay1'
     */
    if ((rlcd_b_ignOn && (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_n)) ||
        (rlcd_b_obcWakeUp && (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_o)) ||
        swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_d4) {
      /* Switch: '<S18>/Switch8' */
      rtb_CCaller10 = rlcd_num_VCU_LockLimSetSaveResult;
    } else {
      /* Switch: '<S18>/Switch8' incorporates:
       *  UnitDelay: '<S18>/Unit Delay'
       */
      rtb_CCaller10 = swc_RMLK_ARID_DEF.UnitDelay_DSTATE_h;
    }

    /* End of Switch: '<S18>/Switch8' */

    /* Switch: '<S7>/Switch2' incorporates:
     *  Constant: '<S28>/Constant'
     *  Constant: '<S29>/Constant'
     *  Constant: '<S30>/Constant'
     *  Constant: '<S31>/Constant'
     *  Logic: '<S7>/Logical Operator1'
     *  RelationalOperator: '<S28>/Compare'
     *  RelationalOperator: '<S29>/Compare'
     *  RelationalOperator: '<S30>/Compare'
     *  RelationalOperator: '<S31>/Compare'
     *  RelationalOperator: '<S32>/FixPt Relational Operator'
     *  RelationalOperator: '<S33>/FixPt Relational Operator'
     *  Switch: '<S7>/Switch1'
     *  Switch: '<S7>/Switch6'
     *  Switch: '<S7>/Switch7'
     *  Switch: '<S7>/Switch8'
     *  UnitDelay: '<S32>/Delay Input1'
     *  UnitDelay: '<S33>/Delay Input1'
     *  UnitDelay: '<S7>/Unit Delay1'
     *
     * Block description for '<S32>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S33>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((sint32)rlcd_b_ignOn > (sint32)swc_RMLK_ARID_DEF.DelayInput1_DSTATE) ||
        ((sint32)rlcd_b_obcWakeUp > (sint32)
         swc_RMLK_ARID_DEF.DelayInput1_DSTATE_h) ||
        swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_cd) {
      /* Switch: '<S7>/Switch2' */
      rtb_CCaller11 = rtb_CCaller10;
    } else if (rlcd_TBOX_LockLimSet == ((uint8)0U)) {
      /* Switch: '<S7>/Switch6' incorporates:
       *  Constant: '<S7>/Constant10'
       *  Switch: '<S7>/Switch2'
       */
      rtb_CCaller11 = ((uint8)5U);
    } else if (rlcd_TBOX_LockLimSet == ((uint8)1U)) {
      /* Switch: '<S7>/Switch7' incorporates:
       *  Constant: '<S7>/Constant11'
       *  Switch: '<S7>/Switch2'
       *  Switch: '<S7>/Switch6'
       */
      rtb_CCaller11 = ((uint8)1U);
    } else if (rlcd_TBOX_LockLimSet == ((uint8)2U)) {
      /* Switch: '<S7>/Switch8' incorporates:
       *  Constant: '<S7>/Constant12'
       *  Switch: '<S7>/Switch2'
       *  Switch: '<S7>/Switch6'
       *  Switch: '<S7>/Switch7'
       */
      rtb_CCaller11 = ((uint8)2U);
    } else if (rlcd_TBOX_LockLimSet == ((uint8)3U)) {
      /* Switch: '<S7>/Switch1' incorporates:
       *  Constant: '<S7>/Constant1'
       *  Switch: '<S7>/Switch2'
       *  Switch: '<S7>/Switch6'
       *  Switch: '<S7>/Switch7'
       *  Switch: '<S7>/Switch8'
       */
      rtb_CCaller11 = ((uint8)3U);
    } else {
      /* Switch: '<S7>/Switch2' incorporates:
       *  Switch: '<S7>/Switch6'
       *  Switch: '<S7>/Switch7'
       *  Switch: '<S7>/Switch8'
       *  UnitDelay: '<S7>/Unit Delay'
       */
      rtb_CCaller11 = swc_RMLK_ARID_DEF.UnitDelay_DSTATE_g;
    }

    /* End of Switch: '<S7>/Switch2' */

    /* Switch: '<S7>/Switch11' incorporates:
     *  Constant: '<S7>/Constant14'
     */
    if (rlcc_b_VSLTEST5_sw) {
      /* Switch: '<S7>/Switch11' incorporates:
       *  Constant: '<S7>/Constant2'
       */
      rlcd_num_LockLimSetReq = ((uint8)1U);
    } else {
      /* Switch: '<S7>/Switch11' */
      rlcd_num_LockLimSetReq = rtb_CCaller11;
    }

    /* End of Switch: '<S7>/Switch11' */

    /* RelationalOperator: '<S34>/Compare' incorporates:
     *  Constant: '<S34>/Constant'
     */
    rtb_Compare_fof = (rlcd_TBOX_FunLockVehActive == ((uint8)1U));
    for (i = 0; i < 16; i++) {
      /* Switch: '<S145>/Switch1' incorporates:
       *  Constant: '<S145>/Constant9'
       */
      if (rlcc_b_useEskNvmDataEna) {
        /* Switch: '<S145>/Switch1' */
        rtb_CCaller2_o[i] = rlcd_v_remoteEskBsw[i];
      } else {
        /* Switch: '<S145>/Switch1' incorporates:
         *  Constant: '<S145>/Constant4'
         */
        rtb_CCaller2_o[i] = rlcc_n_useEskNvmDataDefualt[i];
      }

      /* End of Switch: '<S145>/Switch1' */
    }

    /* Logic: '<S10>/Logical Operator10' incorporates:
     *  Constant: '<S121>/Constant'
     *  Constant: '<S141>/Constant'
     *  Constant: '<S142>/Constant'
     *  Constant: '<S143>/Constant'
     *  RelationalOperator: '<S121>/Compare'
     *  RelationalOperator: '<S141>/Compare'
     *  RelationalOperator: '<S142>/Compare'
     *  RelationalOperator: '<S143>/Compare'
     */
    rlcd_b_tboxCmd_flg = ((rlcd_TBOX_FunLockVehActive == ((uint8)3U)) &&
                          (rlcd_TBOX_LockVehCtrl == ((uint8)3U)) &&
                          (rlcd_TBOXFunAntiDismantleActive == ((uint8)3U)) &&
                          (rlcd_TBOX_LockVehType == ((uint8)3U)));
    for (i = 0; i < 7; i++) {
      /* SignalConversion: '<S4>/Signal Conversion' */
      rlcd_v_tboxKeyVect[i] = rlcd_TBOX_Key[i];

      /* RelationalOperator: '<S10>/Relational Operator9' incorporates:
       *  Constant: '<S10>/Constant4'
       */
      rtb_RelationalOperator9[i] = (rlcd_v_tboxKeyVect[i] ==
        swc_RMLK_ConstP.pooled16[i]);
    }

    /* Logic: '<S10>/Logical Operator9' */
    TBOX_AuthSuccess = rtb_RelationalOperator9[0];
    for (i = 0; i < 6; i++) {
      TBOX_AuthSuccess = (TBOX_AuthSuccess && rtb_RelationalOperator9[i + 1]);
    }

    /* Logic: '<S10>/Logical Operator9' */
    rlcd_b_tboxKey_flg = TBOX_AuthSuccess;

    /* RelationalOperator: '<S10>/Relational Operator5' incorporates:
     *  UnitDelay: '<S10>/Unit Delay4'
     */
    rtb_RelationalOperator5 = (rlcd_TBOX_Update !=
      swc_RMLK_ARID_DEF.UnitDelay4_DSTATE);

    /* Outputs for Atomic SubSystem: '<S10>/turnOFF_delay1' */
    /* Saturate: '<S150>/Saturation1' incorporates:
     *  Constant: '<S10>/Constant6'
     */
    if (0.02F > 1.6777216E+7F) {
      /* Saturate: '<S150>/Saturation1' */
      rtb_t_delay_off = 1.6777216E+7F;
    } else if (0.02F < 0.0F) {
      /* Saturate: '<S150>/Saturation1' */
      rtb_t_delay_off = 0.0F;
    } else {
      /* Saturate: '<S150>/Saturation1' */
      rtb_t_delay_off = 0.02F;
    }

    /* End of Saturate: '<S150>/Saturation1' */

    /* Chart: '<S150>/timed_delay' incorporates:
     *  Constant: '<S10>/Constant1'
     *  DataTypeConversion: '<S150>/Data Type Conversion'
     */
    if (swc_RMLK_ARID_DEF.is_active_c15_swc_RMLK == 0U) {
      swc_RMLK_ARID_DEF.is_active_c15_swc_RMLK = 1U;
      if (rtb_RelationalOperator5) {
        swc_RMLK_ARID_DEF.is_c15_swc_RMLK = swc_RMLK_IN_ON;
        rlcd_b_frameUpdateFlg = true;
      } else {
        swc_RMLK_ARID_DEF.is_c15_swc_RMLK = swc_RMLK_IN_OFF;
        rlcd_b_frameUpdateFlg = false;
      }
    } else {
      switch (swc_RMLK_ARID_DEF.is_c15_swc_RMLK) {
       case swc_RMLK_IN_OFF:
        if (rtb_RelationalOperator5) {
          swc_RMLK_ARID_DEF.is_c15_swc_RMLK = swc_RMLK_IN_ON;
          rlcd_b_frameUpdateFlg = true;
        } else {
          rlcd_b_frameUpdateFlg = false;
        }
        break;

       case swc_RMLK_IN_OFF_WAIT:
        if (rtb_RelationalOperator5) {
          swc_RMLK_ARID_DEF.is_c15_swc_RMLK = swc_RMLK_IN_ON;
          rlcd_b_frameUpdateFlg = true;
        } else if (swc_RMLK_ARID_DEF.t_wait_a > rtb_t_delay_off - 0.01F) {
          swc_RMLK_ARID_DEF.is_c15_swc_RMLK = swc_RMLK_IN_OFF;
          rlcd_b_frameUpdateFlg = false;
        } else {
          swc_RMLK_ARID_DEF.t_wait_a += 0.01F;
          rlcd_b_frameUpdateFlg = true;
        }
        break;

       default:
        /* case IN_ON: */
        if (!rtb_RelationalOperator5) {
          if (rtb_t_delay_off == 0.0F) {
            swc_RMLK_ARID_DEF.is_c15_swc_RMLK = swc_RMLK_IN_OFF;
            rlcd_b_frameUpdateFlg = false;
          } else {
            swc_RMLK_ARID_DEF.is_c15_swc_RMLK = swc_RMLK_IN_OFF_WAIT;
            swc_RMLK_ARID_DEF.t_wait_a = 0.0F;
            swc_RMLK_ARID_DEF.t_wait_a += 0.01F;
            rlcd_b_frameUpdateFlg = true;
          }
        } else {
          rlcd_b_frameUpdateFlg = true;
        }
        break;
      }
    }

    /* End of Chart: '<S150>/timed_delay' */
    /* End of Outputs for SubSystem: '<S10>/turnOFF_delay1' */

    /* Logic: '<S10>/Logical Operator26' */
    TBOX_AuthSuccess = (rlcd_b_ignOn || rlcd_b_obcWakeUp);

    /* Logic: '<S10>/Logical Operator12' incorporates:
     *  Constant: '<S132>/Constant'
     *  Constant: '<S139>/Constant'
     *  Constant: '<S140>/Constant'
     *  Logic: '<S10>/Logical Operator13'
     *  Logic: '<S10>/Logical Operator26'
     *  Logic: '<S10>/Logical Operator4'
     *  RelationalOperator: '<S132>/Compare'
     *  RelationalOperator: '<S139>/Compare'
     *  RelationalOperator: '<S140>/Compare'
     *  UnitDelay: '<S10>/Unit Delay1'
     */
    rlcd_b_cmdLockAuth_flg = (TBOX_AuthSuccess && (!rlcd_b_tboxCmd_flg) &&
      rlcd_b_tboxKey_flg && rlcd_b_frameUpdateFlg &&
      ((swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_l == ((uint8)1U)) ||
       (swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_l == ((uint8)4U)) ||
       (swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_l == ((uint8)7U))));

    /* Logic: '<S10>/Logical Operator5' incorporates:
     *  Logic: '<S10>/Logical Operator26'
     *  Logic: '<S10>/Logical Operator8'
     */
    rlcd_b_defualtAuth_flg = (rlcd_b_tboxCmd_flg && rlcd_b_tboxKey_flg &&
      TBOX_AuthSuccess && rlcd_b_frameUpdateFlg);

    /* Logic: '<S10>/Logical Operator14' */
    rtb_RelationalOperator5 = (rlcd_b_cmdLockAuth_flg || rlcd_b_defualtAuth_flg);

    /* Outputs for Enabled SubSystem: '<S10>/Rand_AES' incorporates:
     *  EnablePort: '<S146>/Enable'
     */
    if (rtb_RelationalOperator5 && (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_e)) {
      float64 newEntry;

      /* MATLAB Function: '<S146>/MATLAB Function' */
      for (i = 0; i < 7; i++) {
        hashTbl[i] = 0.0;
        link[i] = 0.0;
      }

      for (i = 0; i < 7; i++) {
        rtb_CCaller1_i[i] = 0U;
      }

      for (i = 0; i < 7; i++) {
        loc[i] = 0.0;
      }

      newEntry = 1.0;
      for (i = 0; i < 7; i++) {
        float64 j;
        float64 r;
        float64 selectedLoc;
        selectedLoc = ((255.0 - ((float64)i + 1.0)) + 1.0) * swc_RMLK_rand();
        selectedLoc = floor(selectedLoc);
        if (selectedLoc == 0.0) {
          r = 0.0;
        } else {
          r = fmod(selectedLoc, 7.0);
          if (r == 0.0) {
            r = 0.0;
          } else if (selectedLoc < 0.0) {
            r += 7.0;
          }
        }

        j = hashTbl[(sint32)(r + 1.0) - 1];
        while ((j > 0.0) && (loc[(sint32)j - 1] != selectedLoc)) {
          j = link[(sint32)j - 1];
        }

        if (j > 0.0) {
          p[i] = (float64)rtb_CCaller1_i[(sint32)j - 1] + 1.0;
        } else {
          p[i] = selectedLoc + 1.0;
          j = newEntry;
          newEntry++;
          loc[(sint32)j - 1] = selectedLoc;
          link[(sint32)j - 1] = hashTbl[(sint32)(r + 1.0) - 1];
          hashTbl[(sint32)(r + 1.0) - 1] = j;
        }

        if (i + 1 < 7) {
          selectedLoc = hashTbl[(sint32)fmod(255.0 - ((float64)i + 1.0), 7.0)];
          while ((selectedLoc > 0.0) && (255.0 - ((float64)i + 1.0) != loc
                  [(sint32)selectedLoc - 1])) {
            selectedLoc = link[(sint32)selectedLoc - 1];
          }

          if (selectedLoc > 0.0) {
            rtb_CCaller1_i[(sint32)j - 1] = rtb_CCaller1_i[(sint32)selectedLoc -
              1];
          } else {
            rtb_CCaller1_i[(sint32)j - 1] = (uint8)(254 - i);
          }
        }
      }

      for (i = 0; i < 7; i++) {
        newEntry = p[i];
        if (newEntry < 256.0) {
          if (newEntry >= 0.0) {
            swc_RMLK_ARID_DEF.out_o[i] = (uint8)newEntry;
          } else {
            swc_RMLK_ARID_DEF.out_o[i] = 0U;
          }
        } else {
          swc_RMLK_ARID_DEF.out_o[i] = MAX_uint8_T;
        }
      }

      /* End of MATLAB Function: '<S146>/MATLAB Function' */
      for (i = 0; i < 7; i++) {
        /* SignalConversion generated from: '<S151>/ SFunction ' incorporates:
         *  Chart: '<S146>/AES_Cal'
         */
        rtb_TmpSignalConversionAtSFunct[i] = swc_RMLK_ARID_DEF.out_o[i];
      }

      for (i = 0; i < 9; i++) {
        /* SignalConversion generated from: '<S151>/ SFunction ' incorporates:
         *  Chart: '<S146>/AES_Cal'
         *  Constant: '<S146>/Constant1'
         */
        rtb_TmpSignalConversionAtSFunct[i + 7] =
          swc_RMLK_ConstP.Constant1_Value[i];
      }

      /* Chart: '<S146>/AES_Cal' incorporates:
       *  SignalConversion generated from: '<S151>/ SFunction '
       *  Switch: '<S145>/Switch1'
       */
      if (swc_RMLK_ARID_DEF.is_active_c10_swc_RMLK == 0U) {
        swc_RMLK_ARID_DEF.is_active_c10_swc_RMLK = 1U;
        AES_ExpandKey_RemoteLock((AES_U8 *)&rtb_CCaller2_o[0], (AES_U8 *)
          &swc_RMLK_ARID_DEF.expKey[0]);
        AES_Encrypt_RemoteLock((AES_U8 *)&rtb_TmpSignalConversionAtSFunct[0],
          (AES_U8 *)&swc_RMLK_ARID_DEF.expKey[0], (AES_U8 *)
          &swc_RMLK_ARID_DEF.s_out[0]);
        swc_RMLK_ARID_DEF.Cnt = 1U;
      } else {
        AES_ExpandKey_RemoteLock((AES_U8 *)&rtb_CCaller2_o[0], (AES_U8 *)
          &swc_RMLK_ARID_DEF.expKey[0]);
        AES_Encrypt_RemoteLock((AES_U8 *)&rtb_TmpSignalConversionAtSFunct[0],
          (AES_U8 *)&swc_RMLK_ARID_DEF.expKey[0], (AES_U8 *)
          &swc_RMLK_ARID_DEF.s_out[0]);
        swc_RMLK_ARID_DEF.Cnt++;
      }

      /* Saturate: '<S146>/Saturation' */
      swc_RMLK_ARID_DEF.Saturation = swc_RMLK_ARID_DEF.Cnt;
    }

    /* End of Outputs for SubSystem: '<S10>/Rand_AES' */

    /* RelationalOperator: '<S10>/Relational Operator4' incorporates:
     *  Logic: '<S147>/Logical Operator'
     *  Logic: '<S147>/Logical Operator1'
     *  UnitDelay: '<S10>/Unit Delay3'
     *  UnitDelay: '<S147>/Unit Delay'
     */
    TBOX_SeedReq = (swc_RMLK_ARID_DEF.Saturation !=
                    swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_b);
    for (i = 0; i < 7; i++) {
      /* RelationalOperator: '<S10>/Relational Operator1' incorporates:
       *  RelationalOperator: '<S10>/Relational Operator2'
       */
      rtb_RelationalOperator9[i] = (swc_RMLK_ARID_DEF.s_out[i] !=
        rlcd_v_tboxKeyVect[i]);
    }

    /* Logic: '<S10>/Logical Operator6' */
    TBOX_AuthSuccess = rtb_RelationalOperator9[0];
    for (i = 0; i < 6; i++) {
      TBOX_AuthSuccess = (TBOX_AuthSuccess || rtb_RelationalOperator9[i + 1]);
    }

    for (i = 0; i < 7; i++) {
      /* RelationalOperator: '<S10>/Relational Operator6' incorporates:
       *  Constant: '<S10>/Constant2'
       */
      rtb_RelationalOperator9[i] = (rlcd_v_tboxKeyVect[i] !=
        swc_RMLK_ConstP.pooled16[i]);
    }

    /* Logic: '<S10>/Logical Operator15' */
    rtb_VariableIntegerDelay = rtb_RelationalOperator9[0];
    for (i = 0; i < 6; i++) {
      rtb_VariableIntegerDelay = (rtb_VariableIntegerDelay ||
        rtb_RelationalOperator9[i + 1]);
    }

    for (i = 0; i < 7; i++) {
      /* RelationalOperator: '<S10>/Relational Operator7' incorporates:
       *  Constant: '<S10>/Constant3'
       */
      rtb_RelationalOperator9[i] = (rlcd_v_tboxKeyVect[i] !=
        swc_RMLK_ConstP.pooled18[i]);
    }

    /* Logic: '<S10>/Logical Operator18' */
    TBOX_AuthFail_dismatch = rtb_RelationalOperator9[0];
    for (i = 0; i < 6; i++) {
      TBOX_AuthFail_dismatch = (TBOX_AuthFail_dismatch ||
        rtb_RelationalOperator9[i + 1]);
    }

    /* Logic: '<S10>/Logical Operator7' incorporates:
     *  Constant: '<S126>/Constant'
     *  Logic: '<S10>/Logical Operator15'
     *  Logic: '<S10>/Logical Operator18'
     *  Logic: '<S10>/Logical Operator6'
     *  RelationalOperator: '<S126>/Compare'
     */
    TBOX_AuthFail_dismatch = ((swc_RMLK_ARID_DEF.Saturation >= ((uint16)1U)) &&
      TBOX_AuthSuccess && rtb_VariableIntegerDelay && TBOX_AuthFail_dismatch);
    for (i = 0; i < 7; i++) {
      /* RelationalOperator: '<S10>/Relational Operator1' */
      rtb_RelationalOperator9[i] = (swc_RMLK_ARID_DEF.s_out[i] ==
        rlcd_v_tboxKeyVect[i]);
    }

    /* Logic: '<S10>/Logical Operator2' */
    TBOX_AuthSuccess = rtb_RelationalOperator9[0];
    for (i = 0; i < 6; i++) {
      TBOX_AuthSuccess = (TBOX_AuthSuccess && rtb_RelationalOperator9[i + 1]);
    }

    /* Logic: '<S10>/Logical Operator3' incorporates:
     *  Constant: '<S138>/Constant'
     *  Logic: '<S10>/Logical Operator2'
     *  RelationalOperator: '<S138>/Compare'
     */
    TBOX_AuthSuccess = (TBOX_AuthSuccess && (swc_RMLK_ARID_DEF.Saturation >=
      ((uint16)1U)));

    /* Switch: '<S22>/Switch8' incorporates:
     *  Logic: '<S22>/Logical Operator'
     *  Logic: '<S258>/Logical Operator'
     *  Logic: '<S258>/Logical Operator1'
     *  Logic: '<S259>/Logical Operator'
     *  Logic: '<S259>/Logical Operator1'
     *  UnitDelay: '<S22>/Unit Delay'
     *  UnitDelay: '<S258>/Unit Delay'
     *  UnitDelay: '<S259>/Unit Delay'
     */
    if ((rlcd_b_ignOn && (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_hn)) ||
        (rlcd_b_obcWakeUp && (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_b)) ||
        swc_RMLK_ARID_DEF.UnitDelay_DSTATE_d) {
      /* Switch: '<S22>/Switch8' */
      rtb_CCaller3_a = rlcd_num_VCU_AntiLockSaveResult;
    } else {
      /* Switch: '<S22>/Switch8' incorporates:
       *  UnitDelay: '<S22>/Unit Delay2'
       */
      rtb_CCaller3_a = swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_k;
    }

    /* End of Switch: '<S22>/Switch8' */

    /* Switch: '<S26>/Switch8' incorporates:
     *  Logic: '<S269>/Logical Operator'
     *  Logic: '<S269>/Logical Operator1'
     *  Logic: '<S26>/Logical Operator'
     *  Logic: '<S270>/Logical Operator'
     *  Logic: '<S270>/Logical Operator1'
     *  UnitDelay: '<S269>/Unit Delay'
     *  UnitDelay: '<S26>/Unit Delay'
     *  UnitDelay: '<S270>/Unit Delay'
     */
    if ((rlcd_b_ignOn && (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_nk)) ||
        (rlcd_b_obcWakeUp && (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_dh)) ||
        swc_RMLK_ARID_DEF.UnitDelay_DSTATE_bo) {
      /* Switch: '<S26>/Switch8' */
      rlcd_num_NormLockSaveRltRaw = rlcd_num_VCU_NormLockSaveResult;
    } else {
      /* Switch: '<S26>/Switch8' incorporates:
       *  UnitDelay: '<S26>/Unit Delay2'
       */
      rlcd_num_NormLockSaveRltRaw = swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_p;
    }

    /* End of Switch: '<S26>/Switch8' */

    /* Delay: '<S26>/Variable Integer Delay' incorporates:
     *  Constant: '<S26>/Constant1'
     */
    if (rlcc_n_igOnDelayCnt < 1.0F) {
      /* Delay: '<S26>/Variable Integer Delay' */
      rtb_VariableIntegerDelay = rlcd_b_ignOn;
    } else {
      if (rlcc_n_igOnDelayCnt > 100.0F) {
        rtb_CCaller_g = 100U;
      } else {
        rtb_t_delay_off = fmodf(truncf(rlcc_n_igOnDelayCnt), 4.2949673E+9F);
        rtb_CCaller_g = rtb_t_delay_off < 0.0F ? (uint32)-(sint32)(uint32)-
          rtb_t_delay_off : (uint32)rtb_t_delay_off;
      }

      /* Delay: '<S26>/Variable Integer Delay' */
      rtb_VariableIntegerDelay = swc_RMLK_ARID_DEF.VariableIntegerDelay_DSTATE
        [100U - rtb_CCaller_g];
    }

    /* End of Delay: '<S26>/Variable Integer Delay' */

    /* RelationalOperator: '<S268>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S268>/Delay Input1'
     *
     * Block description for '<S268>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_FixPtRelationalOperator_j = ((sint32)rtb_VariableIntegerDelay > (sint32)
      swc_RMLK_ARID_DEF.DelayInput1_DSTATE_e);

    /* RelationalOperator: '<S192>/Compare' incorporates:
     *  Constant: '<S26>/Constant3'
     *  RelationalOperator: '<S26>/Relational Operator4'
     */
    rtb_Compare_oc = (rlcd_v_vehSpd_kph <= rlcc_v_normlLckSpd_kph);

    /* Logic: '<S26>/Logical Operator7' incorporates:
     *  Logic: '<S26>/Logical Operator1'
     *  Logic: '<S26>/Logical Operator6'
     */
    rtb_LogicalOperator7 = ((!rlcd_b_ignOn) || (!rtb_Compare_oc));

    /* Outputs for Atomic SubSystem: '<S26>/SR_latch1' */
    swc_RMLK_SR_latch1(rtb_FixPtRelationalOperator_j, rtb_LogicalOperator7,
                       &rtb_LogicalOperator3_pj,
                       &swc_RMLK_ARID_DEF.ARID_DEF_SR_latch1);

    /* End of Outputs for SubSystem: '<S26>/SR_latch1' */

    /* SignalConversion generated from: '<S26>/SR_latch1' */
    rlcd_b_NormLockActvRaw = rtb_LogicalOperator3_pj;

    /* Logic: '<S26>/Logical Operator2' incorporates:
     *  Constant: '<S267>/Constant'
     *  RelationalOperator: '<S267>/Compare'
     */
    rlcd_b_NormLockActv = ((rlcd_num_NormLockSaveRltRaw == ((uint8)1U)) &&
      rlcd_b_NormLockActvRaw && rtb_Compare_oc);

    /* Logic: '<S26>/Logical Operator3' incorporates:
     *  Constant: '<S266>/Constant'
     *  RelationalOperator: '<S266>/Compare'
     */
    rlcd_b_NormLockNotActv = ((rlcd_num_NormLockSaveRltRaw == ((uint8)2U)) &&
      rlcd_b_ignOn);

    /* Switch: '<S26>/Switch1' incorporates:
     *  Logic: '<S26>/Logical Operator5'
     */
    if (rlcd_b_NormLockActv || rlcd_b_NormLockNotActv) {
      /* Switch: '<S26>/Switch1' */
      rtb_CCaller4_a = rlcd_num_NormLockSaveRltRaw;
    } else {
      /* Switch: '<S26>/Switch1' incorporates:
       *  UnitDelay: '<S26>/Unit Delay4'
       */
      rtb_CCaller4_a = swc_RMLK_ARID_DEF.UnitDelay4_DSTATE_l;
    }

    /* End of Switch: '<S26>/Switch1' */

    /* Switch: '<S23>/Switch8' incorporates:
     *  Logic: '<S23>/Logical Operator'
     *  Logic: '<S260>/Logical Operator'
     *  Logic: '<S260>/Logical Operator1'
     *  Logic: '<S261>/Logical Operator'
     *  Logic: '<S261>/Logical Operator1'
     *  UnitDelay: '<S23>/Unit Delay'
     *  UnitDelay: '<S260>/Unit Delay'
     *  UnitDelay: '<S261>/Unit Delay'
     */
    if ((rlcd_b_ignOn && (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_l)) ||
        (rlcd_b_obcWakeUp && (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_i)) ||
        swc_RMLK_ARID_DEF.UnitDelay_DSTATE_nk2) {
      /* Switch: '<S23>/Switch8' */
      rtb_CCaller5 = rlcd_num_VCU_ChgLockExcSaveResult;
    } else {
      /* Switch: '<S23>/Switch8' incorporates:
       *  UnitDelay: '<S23>/Unit Delay2'
       */
      rtb_CCaller5 = swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_e;
    }

    /* End of Switch: '<S23>/Switch8' */

    /* Logic: '<S10>/Logical Operator21' incorporates:
     *  Constant: '<S123>/Constant'
     *  Constant: '<S124>/Constant'
     *  Constant: '<S128>/Constant'
     *  Constant: '<S129>/Constant'
     *  Constant: '<S130>/Constant'
     *  Constant: '<S131>/Constant'
     *  Constant: '<S133>/Constant'
     *  Constant: '<S134>/Constant'
     *  Constant: '<S135>/Constant'
     *  Constant: '<S136>/Constant'
     *  Constant: '<S137>/Constant'
     *  Constant: '<S144>/Constant'
     *  Logic: '<S10>/Logical Operator1'
     *  Logic: '<S10>/Logical Operator20'
     *  Logic: '<S10>/Logical Operator22'
     *  Logic: '<S10>/Logical Operator23'
     *  Logic: '<S10>/Logical Operator24'
     *  Logic: '<S10>/Logical Operator30'
     *  RelationalOperator: '<S123>/Compare'
     *  RelationalOperator: '<S124>/Compare'
     *  RelationalOperator: '<S128>/Compare'
     *  RelationalOperator: '<S129>/Compare'
     *  RelationalOperator: '<S130>/Compare'
     *  RelationalOperator: '<S131>/Compare'
     *  RelationalOperator: '<S133>/Compare'
     *  RelationalOperator: '<S134>/Compare'
     *  RelationalOperator: '<S135>/Compare'
     *  RelationalOperator: '<S136>/Compare'
     *  RelationalOperator: '<S137>/Compare'
     *  RelationalOperator: '<S144>/Compare'
     *  UnitDelay: '<S10>/Unit Delay'
     *  UnitDelay: '<S10>/Unit Delay2'
     *  UnitDelay: '<S10>/Unit Delay5'
     *  UnitDelay: '<S10>/Unit Delay8'
     *  UnitDelay: '<S10>/Unit Delay9'
     */
    rlcd_b_cmdFail_flg = (((rlcd_TBOXFunAntiDismantleActive == ((uint8)0U)) &&
      ((rtb_CCaller3_a == ((uint8)1U)) || (swc_RMLK_ARID_DEF.UnitDelay5_DSTATE ==
      true)) && (swc_RMLK_ARID_DEF.UnitDelay_DSTATE_on == true)) ||
                          ((rlcd_TBOX_FunLockVehActive == ((uint8)0U)) &&
      ((rtb_CCaller4_a == ((uint8)1U)) || (rtb_CCaller5 == ((uint8)1U)) ||
       (swc_RMLK_ARID_DEF.UnitDelay8_DSTATE_p == true)) &&
      ((swc_RMLK_ARID_DEF.UnitDelay_DSTATE_on == true) ||
       (swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_l == ((uint8)0U)))) ||
                          ((swc_RMLK_ARID_DEF.UnitDelay9_DSTATE == ((uint8)0U)) &&
      (rlcd_TBOX_LockVehCtrl == ((uint8)1U))));

    /* Chart: '<S10>/AuthState' */
    if (swc_RMLK_ARID_DEF.is_active_c8_swc_RMLK == 0U) {
      swc_RMLK_ARID_DEF.is_active_c8_swc_RMLK = 1U;
      swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_Default;
      swc_RMLK_enter_atomic_Default();
    } else {
      guard1 = false;
      switch (swc_RMLK_ARID_DEF.is_c8_swc_RMLK) {
       case swc_RMLK_IN_CmdExecutedFail:
        rlcd_st_authState = 51U;
        rlcd_num_VCU_AuthResult = 1U;
        rlcd_num_pmsRespResult = 0U;
        if (swc_RMLK_ARID_DEF.ReqCnt == 3) {
          swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_Default;
          swc_RMLK_enter_atomic_Default();
        } else if (swc_RMLK_ARID_DEF.timer_d > 0.01F) {
          swc_RMLK_ARID_DEF.timer_d = 0.01F;
          swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_ReptAuthFrame4;
          rlcd_st_authState = 34U;
          rlcd_num_VCU_AuthResult = 0U;
          rlcd_num_pmsRespResult = 0U;
          rlcd_v_pmsReqSeed[0] = 0U;
          rlcd_v_pmsReqSeed[1] = 0U;
          rlcd_v_pmsReqSeed[2] = 0U;
          rlcd_v_pmsReqSeed[3] = 0U;
          rlcd_v_pmsReqSeed[4] = 0U;
          rlcd_v_pmsReqSeed[5] = 0U;
          rlcd_v_pmsReqSeed[6] = 0U;
          swc_RMLK_ARID_DEF.timer_d += 0.01F;
        }
        break;

       case swc_RMLK_IN_Default:
        rlcd_st_authState = 0U;
        rlcd_num_VCU_AuthResult = 0U;
        rlcd_num_pmsRespResult = 0U;
        if (TBOX_SeedReq && rlcd_b_defualtAuth_flg) {
          swc_RMLK_ARID_DEF.AuthType = 1U;
          guard1 = true;
        } else if (TBOX_SeedReq && rlcd_b_cmdLockAuth_flg) {
          swc_RMLK_ARID_DEF.AuthType = 2U;
          guard1 = true;
        }
        break;

       case swc_RMLK_IN_DefualtAuthFail:
        rlcd_st_authState = 4U;
        rlcd_num_VCU_AuthResult = 0U;
        rlcd_num_pmsRespResult = 3U;
        if (swc_RMLK_ARID_DEF.ReqCnt == 3) {
          swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_Default;
          swc_RMLK_enter_atomic_Default();
        } else if (swc_RMLK_ARID_DEF.timer_d > 0.01F) {
          swc_RMLK_ARID_DEF.timer_d = 0.01F;
          swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_ReptAuthFrame5;
          rlcd_st_authState = 35U;
          rlcd_num_VCU_AuthResult = 0U;
          rlcd_num_pmsRespResult = 0U;
          rlcd_v_pmsReqSeed[0] = 0U;
          rlcd_v_pmsReqSeed[1] = 0U;
          rlcd_v_pmsReqSeed[2] = 0U;
          rlcd_v_pmsReqSeed[3] = 0U;
          rlcd_v_pmsReqSeed[4] = 0U;
          rlcd_v_pmsReqSeed[5] = 0U;
          rlcd_v_pmsReqSeed[6] = 0U;
          swc_RMLK_ARID_DEF.timer_d += 0.01F;
        }
        break;

       case swc_RMLK_IN_DefualtAuthSuccess:
        rlcd_st_authState = 7U;
        rlcd_num_VCU_AuthResult = 1U;
        rlcd_num_pmsRespResult = 3U;
        if (swc_RMLK_ARID_DEF.ReqCnt == 3) {
          swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_Default;
          swc_RMLK_enter_atomic_Default();
        } else if (swc_RMLK_ARID_DEF.timer_d > 0.01F) {
          swc_RMLK_ARID_DEF.timer_d = 0.01F;
          swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_ReptAuthFrame3;
          rlcd_st_authState = 33U;
          rlcd_num_VCU_AuthResult = 0U;
          rlcd_num_pmsRespResult = 0U;
          rlcd_v_pmsReqSeed[0] = 0U;
          rlcd_v_pmsReqSeed[1] = 0U;
          rlcd_v_pmsReqSeed[2] = 0U;
          rlcd_v_pmsReqSeed[3] = 0U;
          rlcd_v_pmsReqSeed[4] = 0U;
          rlcd_v_pmsReqSeed[5] = 0U;
          rlcd_v_pmsReqSeed[6] = 0U;
          swc_RMLK_ARID_DEF.timer_d += 0.01F;
        }
        break;

       case swc_RMLK_IN_LockAuthFail:
        rlcd_st_authState = 5U;
        rlcd_num_VCU_AuthResult = 0U;
        rlcd_num_pmsRespResult = 0U;
        if (swc_RMLK_ARID_DEF.ReqCnt == 3) {
          swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_Default;
          swc_RMLK_enter_atomic_Default();
        } else if (swc_RMLK_ARID_DEF.timer_d > 0.01F) {
          swc_RMLK_ARID_DEF.timer_d = 0.01F;
          swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_ReptAuthFrame1;
          rlcd_st_authState = 31U;
          rlcd_num_VCU_AuthResult = 0U;
          rlcd_num_pmsRespResult = 0U;
          rlcd_v_pmsReqSeed[0] = 0U;
          rlcd_v_pmsReqSeed[1] = 0U;
          rlcd_v_pmsReqSeed[2] = 0U;
          rlcd_v_pmsReqSeed[3] = 0U;
          rlcd_v_pmsReqSeed[4] = 0U;
          rlcd_v_pmsReqSeed[5] = 0U;
          rlcd_v_pmsReqSeed[6] = 0U;
          swc_RMLK_ARID_DEF.timer_d += 0.01F;
        }
        break;

       case swc_RMLK_IN_LockAuthSuccess:
        rlcd_st_authState = 6U;
        rlcd_num_VCU_AuthResult = 1U;
        rlcd_num_pmsRespResult = 1U;
        if (swc_RMLK_ARID_DEF.ReqCnt == 3) {
          swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_Default;
          swc_RMLK_enter_atomic_Default();
        } else if (swc_RMLK_ARID_DEF.timer_d > 0.01F) {
          swc_RMLK_ARID_DEF.timer_d = 0.01F;
          swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_ReptAuthFrame2;
          rlcd_st_authState = 32U;
          rlcd_num_VCU_AuthResult = 0U;
          rlcd_num_pmsRespResult = 0U;
          rlcd_v_pmsReqSeed[0] = 0U;
          rlcd_v_pmsReqSeed[1] = 0U;
          rlcd_v_pmsReqSeed[2] = 0U;
          rlcd_v_pmsReqSeed[3] = 0U;
          rlcd_v_pmsReqSeed[4] = 0U;
          rlcd_v_pmsReqSeed[5] = 0U;
          rlcd_v_pmsReqSeed[6] = 0U;
          swc_RMLK_ARID_DEF.timer_d += 0.01F;
        }
        break;

       case swc_RMLK_IN_ReptAuthFrame1:
        rlcd_st_authState = 31U;
        rlcd_num_VCU_AuthResult = 0U;
        rlcd_num_pmsRespResult = 0U;
        if ((swc_RMLK_ARID_DEF.timer_d > 0.1F) && (swc_RMLK_ARID_DEF.ReqCnt < 3))
        {
          i = swc_RMLK_ARID_DEF.ReqCnt + 1;
          if (swc_RMLK_ARID_DEF.ReqCnt + 1 > 255) {
            i = 255;
          }

          swc_RMLK_ARID_DEF.ReqCnt = (uint8)i;
          swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_LockAuthFail;
          swc_R_enter_atomic_LockAuthFail();
        } else {
          swc_RMLK_ARID_DEF.timer_d += 0.01F;
        }
        break;

       case swc_RMLK_IN_ReptAuthFrame2:
        rlcd_st_authState = 32U;
        rlcd_num_VCU_AuthResult = 0U;
        rlcd_num_pmsRespResult = 0U;
        if ((swc_RMLK_ARID_DEF.timer_d > 0.1F) && (swc_RMLK_ARID_DEF.ReqCnt < 3))
        {
          i = swc_RMLK_ARID_DEF.ReqCnt + 1;
          if (swc_RMLK_ARID_DEF.ReqCnt + 1 > 255) {
            i = 255;
          }

          swc_RMLK_ARID_DEF.ReqCnt = (uint8)i;
          swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_LockAuthSuccess;
          sw_enter_atomic_LockAuthSuccess();
        } else {
          swc_RMLK_ARID_DEF.timer_d += 0.01F;
        }
        break;

       case swc_RMLK_IN_ReptAuthFrame3:
        rlcd_st_authState = 33U;
        rlcd_num_VCU_AuthResult = 0U;
        rlcd_num_pmsRespResult = 0U;
        if ((swc_RMLK_ARID_DEF.timer_d > 0.1F) && (swc_RMLK_ARID_DEF.ReqCnt < 3))
        {
          i = swc_RMLK_ARID_DEF.ReqCnt + 1;
          if (swc_RMLK_ARID_DEF.ReqCnt + 1 > 255) {
            i = 255;
          }

          swc_RMLK_ARID_DEF.ReqCnt = (uint8)i;
          swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_DefualtAuthSuccess;
          enter_atomic_DefualtAuthSuccess();
        } else {
          swc_RMLK_ARID_DEF.timer_d += 0.01F;
        }
        break;

       case swc_RMLK_IN_ReptAuthFrame4:
        rlcd_st_authState = 34U;
        rlcd_num_VCU_AuthResult = 0U;
        rlcd_num_pmsRespResult = 0U;
        if ((swc_RMLK_ARID_DEF.timer_d > 0.1F) && (swc_RMLK_ARID_DEF.ReqCnt < 3))
        {
          i = swc_RMLK_ARID_DEF.ReqCnt + 1;
          if (swc_RMLK_ARID_DEF.ReqCnt + 1 > 255) {
            i = 255;
          }

          swc_RMLK_ARID_DEF.ReqCnt = (uint8)i;
          swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_CmdExecutedFail;
          sw_enter_atomic_CmdExecutedFail();
        } else {
          swc_RMLK_ARID_DEF.timer_d += 0.01F;
        }
        break;

       case swc_RMLK_IN_ReptAuthFrame5:
        rlcd_st_authState = 35U;
        rlcd_num_VCU_AuthResult = 0U;
        rlcd_num_pmsRespResult = 0U;
        if ((swc_RMLK_ARID_DEF.timer_d > 0.1F) && (swc_RMLK_ARID_DEF.ReqCnt < 3))
        {
          i = swc_RMLK_ARID_DEF.ReqCnt + 1;
          if (swc_RMLK_ARID_DEF.ReqCnt + 1 > 255) {
            i = 255;
          }

          swc_RMLK_ARID_DEF.ReqCnt = (uint8)i;
          swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_DefualtAuthFail;
          sw_enter_atomic_DefualtAuthFail();
        } else {
          swc_RMLK_ARID_DEF.timer_d += 0.01F;
        }
        break;

       case swc_RMLK_IN_ReptDefault:
        swc_RMLK_ReptDefault(&TBOX_AuthFail_dismatch, &TBOX_AuthSuccess);
        break;

       default:
        /* case IN_SeedReq: */
        swc_RMLK_SeedReq(&TBOX_AuthSuccess);
        break;
      }

      if (guard1) {
        swc_RMLK_ARID_DEF.is_c8_swc_RMLK = swc_RMLK_IN_SeedReq;
        rlcd_st_authState = 2U;
        swc_RMLK_ARID_DEF.timer_d += 0.01F;
        rlcd_num_VCU_AuthResult = 3U;
        rlcd_num_pmsRespResult = 3U;
        for (i = 0; i < 7; i++) {
          rlcd_v_pmsReqSeed[i] = swc_RMLK_ARID_DEF.out_o[i];
        }
      }
    }

    /* End of Chart: '<S10>/AuthState' */

    /* RelationalOperator: '<S127>/Compare' incorporates:
     *  Constant: '<S127>/Constant'
     */
    rtb_Compare_em = (rlcd_num_VCU_AuthResult == ((uint8)1U));

    /* Outputs for Atomic SubSystem: '<S10>/turnOFF_delay' */
    /* Chart: '<S149>/timed_delay' incorporates:
     *  Constant: '<S10>/Constant'
     *  DataTypeConversion: '<S149>/Data Type Conversion'
     */
    if (swc_RMLK_ARID_DEF.is_active_c12_swc_RMLK == 0U) {
      swc_RMLK_ARID_DEF.is_active_c12_swc_RMLK = 1U;
      if (rtb_Compare_em) {
        swc_RMLK_ARID_DEF.is_c12_swc_RMLK = swc_RMLK_IN_ON;
        TBOX_AuthSuccess = true;
      } else {
        swc_RMLK_ARID_DEF.is_c12_swc_RMLK = swc_RMLK_IN_OFF;
        TBOX_AuthSuccess = false;
      }
    } else {
      switch (swc_RMLK_ARID_DEF.is_c12_swc_RMLK) {
       case swc_RMLK_IN_OFF:
        if (rtb_Compare_em) {
          swc_RMLK_ARID_DEF.is_c12_swc_RMLK = swc_RMLK_IN_ON;
          TBOX_AuthSuccess = true;
        } else {
          TBOX_AuthSuccess = false;
        }
        break;

       case swc_RMLK_IN_OFF_WAIT:
        if (rtb_Compare_em) {
          swc_RMLK_ARID_DEF.is_c12_swc_RMLK = swc_RMLK_IN_ON;
          TBOX_AuthSuccess = true;
        } else if (swc_RMLK_ARID_DEF.t_wait_n > swc_RMLK_ConstB.t_delay_off -
                   0.01F) {
          swc_RMLK_ARID_DEF.is_c12_swc_RMLK = swc_RMLK_IN_OFF;
          TBOX_AuthSuccess = false;
        } else {
          swc_RMLK_ARID_DEF.t_wait_n += 0.01F;
          TBOX_AuthSuccess = true;
        }
        break;

       default:
        /* case IN_ON: */
        if (!rtb_Compare_em) {
          if (swc_RMLK_ConstB.t_delay_off == 0.0F) {
            swc_RMLK_ARID_DEF.is_c12_swc_RMLK = swc_RMLK_IN_OFF;
            TBOX_AuthSuccess = false;
          } else {
            swc_RMLK_ARID_DEF.is_c12_swc_RMLK = swc_RMLK_IN_OFF_WAIT;
            swc_RMLK_ARID_DEF.t_wait_n = 0.0F;
            swc_RMLK_ARID_DEF.t_wait_n += 0.01F;
            TBOX_AuthSuccess = true;
          }
        } else {
          TBOX_AuthSuccess = true;
        }
        break;
      }
    }

    /* End of Chart: '<S149>/timed_delay' */
    /* End of Outputs for SubSystem: '<S10>/turnOFF_delay' */

    /* DataTypeConversion: '<S10>/Data Type Conversion' */
    rtb_DataTypeConversion = TBOX_AuthSuccess;

    /* RelationalOperator: '<S35>/Compare' incorporates:
     *  Constant: '<S35>/Constant'
     *  DataTypeConversion: '<S10>/Data Type Conversion'
     */
    TBOX_AuthSuccess = (TBOX_AuthSuccess == ((uint8)1U));

    /* Switch: '<S8>/Switch2' incorporates:
     *  Constant: '<S38>/Constant'
     *  Constant: '<S40>/Constant'
     *  Constant: '<S44>/Constant'
     *  Constant: '<S45>/Constant'
     *  Constant: '<S46>/Constant'
     *  Constant: '<S47>/Constant'
     *  Constant: '<S48>/Constant'
     *  Logic: '<S8>/Logical Operator1'
     *  Logic: '<S8>/Logical Operator2'
     *  Logic: '<S8>/Logical Operator23'
     *  RelationalOperator: '<S38>/Compare'
     *  RelationalOperator: '<S40>/Compare'
     *  RelationalOperator: '<S44>/Compare'
     *  RelationalOperator: '<S45>/Compare'
     *  RelationalOperator: '<S46>/Compare'
     *  RelationalOperator: '<S47>/Compare'
     *  RelationalOperator: '<S48>/Compare'
     *  Switch: '<S8>/Switch3'
     *  UnitDelay: '<S8>/Unit Delay3'
     *  UnitDelay: '<S8>/Unit Delay8'
     */
    if ((rlcd_TBOX_LockVehCtrl == ((uint8)3U)) && TBOX_AuthSuccess &&
        rtb_Compare_fof) {
      /* Switch: '<S8>/Switch2' incorporates:
       *  Constant: '<S8>/Constant4'
       */
      rtb_CCaller6 = ((uint8)1U);
    } else if ((rlcd_TBOX_FunLockVehActive == ((uint8)0U)) && TBOX_AuthSuccess &&
               ((rtb_CCaller4_a != ((uint8)1U)) && (rtb_CCaller5 != ((uint8)1U))
                && (swc_RMLK_ARID_DEF.UnitDelay8_DSTATE_a != true)) &&
               (rlcd_TBOX_LockVehCtrl == ((uint8)3U)) &&
               (swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_a != ((uint8)0U))) {
      /* Switch: '<S8>/Switch3' incorporates:
       *  Constant: '<S8>/Constant5'
       *  Switch: '<S8>/Switch2'
       */
      rtb_CCaller6 = ((uint8)2U);
    } else {
      /* Switch: '<S8>/Switch2' incorporates:
       *  UnitDelay: '<S8>/Unit Delay1'
       */
      rtb_CCaller6 = swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_n;
    }

    /* End of Switch: '<S8>/Switch2' */

    /* Switch: '<S8>/Switch4' incorporates:
     *  Constant: '<S36>/Constant'
     *  Constant: '<S37>/Constant'
     *  Constant: '<S39>/Constant'
     *  Constant: '<S41>/Constant'
     *  Logic: '<S8>/Logical Operator20'
     *  Logic: '<S8>/Logical Operator8'
     *  Logic: '<S8>/Logical Operator9'
     *  RelationalOperator: '<S36>/Compare'
     *  RelationalOperator: '<S37>/Compare'
     *  RelationalOperator: '<S39>/Compare'
     *  RelationalOperator: '<S41>/Compare'
     *  Switch: '<S8>/Switch5'
     *  UnitDelay: '<S8>/Unit Delay5'
     */
    if (TBOX_AuthSuccess && (rlcd_TBOXFunAntiDismantleActive == ((uint8)1U))) {
      /* Switch: '<S8>/Switch4' incorporates:
       *  Constant: '<S8>/Constant7'
       */
      rtb_CCaller7 = ((uint8)1U);
    } else if ((rlcd_TBOXFunAntiDismantleActive == ((uint8)0U)) &&
               TBOX_AuthSuccess && ((rtb_CCaller3_a != ((uint8)1U)) &&
                (swc_RMLK_ARID_DEF.UnitDelay5_DSTATE_e != true))) {
      /* Switch: '<S8>/Switch5' incorporates:
       *  Constant: '<S8>/Constant8'
       *  Switch: '<S8>/Switch4'
       */
      rtb_CCaller7 = ((uint8)2U);
    } else {
      /* Switch: '<S8>/Switch4' incorporates:
       *  UnitDelay: '<S8>/Unit Delay2'
       */
      rtb_CCaller7 = swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_ev;
    }

    /* End of Switch: '<S8>/Switch4' */

    /* Switch: '<S25>/Switch8' incorporates:
     *  Logic: '<S25>/Logical Operator'
     *  Logic: '<S264>/Logical Operator'
     *  Logic: '<S264>/Logical Operator1'
     *  Logic: '<S265>/Logical Operator'
     *  Logic: '<S265>/Logical Operator1'
     *  UnitDelay: '<S25>/Unit Delay'
     *  UnitDelay: '<S264>/Unit Delay'
     *  UnitDelay: '<S265>/Unit Delay'
     */
    if ((rlcd_b_ignOn && (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_gw)) ||
        (rlcd_b_obcWakeUp && (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_a)) ||
        swc_RMLK_ARID_DEF.UnitDelay_DSTATE_ok) {
      /* Switch: '<S25>/Switch8' */
      rtb_CCaller8 = rlcd_num_VCU_FunLockVehActiveResult;
    } else {
      /* Switch: '<S25>/Switch8' incorporates:
       *  UnitDelay: '<S25>/Unit Delay2'
       */
      rtb_CCaller8 = swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_i;
    }

    /* End of Switch: '<S25>/Switch8' */

    /* Switch: '<S8>/Switch1' incorporates:
     *  Constant: '<S42>/Constant'
     *  RelationalOperator: '<S42>/Compare'
     */
    if (rtb_CCaller6 != ((uint8)0U)) {
      /* Switch: '<S8>/Switch1' */
      rlcd_num_FunLockVehActiveReq = rtb_CCaller6;
    } else {
      /* Switch: '<S8>/Switch1' */
      rlcd_num_FunLockVehActiveReq = rtb_CCaller8;
    }

    /* End of Switch: '<S8>/Switch1' */

    /* Switch: '<S24>/Switch8' incorporates:
     *  Logic: '<S24>/Logical Operator'
     *  Logic: '<S262>/Logical Operator'
     *  Logic: '<S262>/Logical Operator1'
     *  Logic: '<S263>/Logical Operator'
     *  Logic: '<S263>/Logical Operator1'
     *  UnitDelay: '<S24>/Unit Delay'
     *  UnitDelay: '<S262>/Unit Delay'
     *  UnitDelay: '<S263>/Unit Delay'
     */
    if ((rlcd_b_ignOn && (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_mq)) ||
        (rlcd_b_obcWakeUp && (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_da)) ||
        swc_RMLK_ARID_DEF.UnitDelay_DSTATE_c) {
      /* Switch: '<S24>/Switch8' */
      rtb_Switch8_i = rlcd_num_VCU_FunAnti_DismantleActiveResult;
    } else {
      /* Switch: '<S24>/Switch8' incorporates:
       *  UnitDelay: '<S24>/Unit Delay2'
       */
      rtb_Switch8_i = swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_im;
    }

    /* End of Switch: '<S24>/Switch8' */

    /* Switch: '<S8>/Switch6' incorporates:
     *  Constant: '<S43>/Constant'
     *  RelationalOperator: '<S43>/Compare'
     */
    if (rtb_CCaller7 != ((uint8)0U)) {
      /* Switch: '<S8>/Switch6' */
      rlcd_num_FunAnti_DismantleActiveReq = rtb_CCaller7;
    } else {
      /* Switch: '<S8>/Switch6' */
      rlcd_num_FunAnti_DismantleActiveReq = rtb_Switch8_i;
    }

    /* End of Switch: '<S8>/Switch6' */

    /* UnitDelay: '<S9>/Unit Delay10' */
    rtb_Compare_fof = swc_RMLK_ARID_DEF.UnitDelay10_DSTATE;

    /* Switch: '<S49>/Switch1' incorporates:
     *  Constant: '<S114>/Constant'
     *  Constant: '<S115>/Constant'
     *  Constant: '<S116>/Constant'
     *  Constant: '<S117>/Constant'
     *  Constant: '<S118>/Constant'
     *  Constant: '<S119>/Constant'
     *  Logic: '<S106>/Logical Operator'
     *  Logic: '<S106>/Logical Operator1'
     *  Logic: '<S107>/Logical Operator'
     *  Logic: '<S107>/Logical Operator1'
     *  Logic: '<S108>/Logical Operator'
     *  Logic: '<S108>/Logical Operator1'
     *  Logic: '<S49>/Logical Operator1'
     *  Logic: '<S49>/Logical Operator2'
     *  Logic: '<S9>/Logical Operator17'
     *  RelationalOperator: '<S114>/Compare'
     *  RelationalOperator: '<S115>/Compare'
     *  RelationalOperator: '<S116>/Compare'
     *  RelationalOperator: '<S117>/Compare'
     *  RelationalOperator: '<S118>/Compare'
     *  RelationalOperator: '<S119>/Compare'
     *  Switch: '<S49>/Switch16'
     *  Switch: '<S49>/Switch17'
     *  Switch: '<S49>/Switch18'
     *  UnitDelay: '<S106>/Unit Delay'
     *  UnitDelay: '<S107>/Unit Delay'
     *  UnitDelay: '<S108>/Unit Delay'
     */
    if ((rlcd_b_ignOn && (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_am)) ||
        (rlcd_b_chgAnti_flg && (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_hx)) ||
        (rtb_Compare_fof && (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_br))) {
      /* Switch: '<S49>/Switch1' incorporates:
       *  Constant: '<S49>/Constant1'
       */
      rtb_Switch1_mx = ((uint8)0U);
    } else if (rlcd_st_authState == ((uint8)2U)) {
      /* Switch: '<S49>/Switch16' incorporates:
       *  Constant: '<S49>/Constant16'
       *  Switch: '<S49>/Switch1'
       */
      rtb_Switch1_mx = ((uint8)2U);
    } else if ((rlcd_st_authState == ((uint8)6U)) || (rlcd_st_authState ==
                ((uint8)7U)) || (rlcd_st_authState == ((uint8)51U))) {
      /* Switch: '<S49>/Switch17' incorporates:
       *  Constant: '<S49>/Constant17'
       *  Switch: '<S49>/Switch1'
       *  Switch: '<S49>/Switch16'
       */
      rtb_Switch1_mx = ((uint8)6U);
    } else if ((rlcd_st_authState == ((uint8)5U)) || (rlcd_st_authState ==
                ((uint8)4U))) {
      /* Switch: '<S49>/Switch18' incorporates:
       *  Constant: '<S49>/Constant18'
       *  Switch: '<S49>/Switch1'
       *  Switch: '<S49>/Switch16'
       *  Switch: '<S49>/Switch17'
       */
      rtb_Switch1_mx = ((uint8)5U);
    } else {
      /* Switch: '<S49>/Switch1' incorporates:
       *  Switch: '<S49>/Switch16'
       *  Switch: '<S49>/Switch17'
       *  UnitDelay: '<S49>/Unit Delay4'
       */
      rtb_Switch1_mx = swc_RMLK_ARID_DEF.UnitDelay4_DSTATE_k;
    }

    /* End of Switch: '<S49>/Switch1' */

    /* CCaller: '<S9>/C Caller2' */
    rtb_CCaller2 = mBSW_NvmRead_FlashCnt();

    /* Logic: '<S9>/Logical Operator2' incorporates:
     *  Constant: '<S75>/Constant'
     *  Constant: '<S92>/Constant'
     *  RelationalOperator: '<S75>/Compare'
     *  RelationalOperator: '<S92>/Compare'
     */
    TBOX_AuthFail_dismatch = ((rtb_CCaller2 == 0U) &&
      (rlcd_num_FunAnti_DismantleActiveReq == ((uint8)1U)) && rlcd_b_ignOn);

    /* Logic: '<S9>/Logical Operator12' incorporates:
     *  Constant: '<S76>/Constant'
     *  RelationalOperator: '<S76>/Compare'
     */
    TBOX_AuthSuccess = ((rlcd_num_FunAnti_DismantleActiveReq == ((uint8)1U)) &&
                        rlcd_b_chgAnti_flg);

    /* UnitDelay: '<S9>/Unit Delay8' */
    rtb_UnitDelay8 = swc_RMLK_ARID_DEF.UnitDelay8_DSTATE;

    /* Chart: '<S9>/KeyOnAntiStateReq' incorporates:
     *  Constant: '<S9>/Constant16'
     */
    if (swc_RMLK_ARID_DEF.is_active_c9_swc_RMLK == 0U) {
      swc_RMLK_ARID_DEF.is_active_c9_swc_RMLK = 1U;
      swc_RMLK_ARID_DEF.AntiReqBuff = rtb_CCaller3_a;
      swc_RMLK_ARID_DEF.is_c9_swc_RMLK = swc_RMLK_IN_UpdateAntiReq;
      swc_RMLK_ARID_DEF.AntiReq = swc_RMLK_ARID_DEF.AntiReqBuff;
      swc_RMLK_ARID_DEF.timer_b = 0.0F;
      swc_RMLK_ARID_DEF.TboxReq = false;
    } else {
      switch (swc_RMLK_ARID_DEF.is_c9_swc_RMLK) {
       case swc_RMLK_IN_AntiReqVerify:
        if ((!TBOX_AuthFail_dismatch) || TBOX_AuthSuccess || rtb_Compare_fof) {
          swc_RMLK_ARID_DEF.is_AntiReqVerify = swc_RMLK_IN_NO_ACTIVE_CHILD;
          swc_RMLK_ARID_DEF.is_c9_swc_RMLK = swc_RMLK_IN_UpdateAntiReq;
          swc_RMLK_ARID_DEF.AntiReq = swc_RMLK_ARID_DEF.AntiReqBuff;
          swc_RMLK_ARID_DEF.timer_b = 0.0F;
          swc_RMLK_ARID_DEF.TboxReq = false;
        } else {
          switch (swc_RMLK_ARID_DEF.is_AntiReqVerify) {
           case swc_RMLK_IN_AntiActv:
           case swc_RMLK_IN_AntiNotActv:
            break;

           default:
            /* case IN_KeyOnTimer: */
            if (rtb_Switch1_mx == 6) {
              swc_RMLK_ARID_DEF.is_AntiReqVerify = swc_RMLK_IN_AntiNotActv;
              swc_RMLK_ARID_DEF.AntiReqBuff = 2U;
              swc_RMLK_ARID_DEF.AntiReq = swc_RMLK_ARID_DEF.AntiReqBuff;
            } else if (((rtb_Switch1_mx == 5) || (!swc_RMLK_ARID_DEF.TboxReq)) &&
                       (swc_RMLK_ARID_DEF.timer_b >= rlcc_tm_antiKL15Tm_s)) {
              swc_RMLK_ARID_DEF.is_AntiReqVerify = swc_RMLK_IN_AntiActv;
              swc_RMLK_ARID_DEF.AntiReqBuff = 1U;
              swc_RMLK_ARID_DEF.AntiReq = swc_RMLK_ARID_DEF.AntiReqBuff;
            } else {
              swc_RMLK_ARID_DEF.timer_b += 0.01F;
            }
            break;
          }
        }
        break;

       case swc_RMLK_IN_ChgAnti:
        rtb_LogicalOperator_oe = !TBOX_AuthFail_dismatch;
        if (((!TBOX_AuthSuccess) && rtb_LogicalOperator_oe) ||
            ((!rtb_Compare_fof) && rtb_LogicalOperator_oe)) {
          swc_RMLK_ARID_DEF.is_c9_swc_RMLK = swc_RMLK_IN_UpdateAntiReq;
          swc_RMLK_ARID_DEF.AntiReq = swc_RMLK_ARID_DEF.AntiReqBuff;
          swc_RMLK_ARID_DEF.timer_b = 0.0F;
          swc_RMLK_ARID_DEF.TboxReq = false;
        } else {
          swc_RMLK_ARID_DEF.AntiReq = rtb_UnitDelay8;
          swc_RMLK_ARID_DEF.AntiReqBuff = rtb_UnitDelay8;
        }
        break;

       default:
        /* case IN_UpdateAntiReq: */
        if (TBOX_AuthSuccess || rtb_Compare_fof) {
          swc_RMLK_ARID_DEF.is_c9_swc_RMLK = swc_RMLK_IN_ChgAnti;
          swc_RMLK_ARID_DEF.AntiReq = rtb_UnitDelay8;
          swc_RMLK_ARID_DEF.AntiReqBuff = rtb_UnitDelay8;
        } else if (TBOX_AuthFail_dismatch) {
          swc_RMLK_ARID_DEF.is_c9_swc_RMLK = swc_RMLK_IN_AntiReqVerify;
          swc_RMLK_ARID_DEF.is_AntiReqVerify = swc_RMLK_IN_KeyOnTimer;
          swc_RMLK_ARID_DEF.timer_b += 0.01F;
        }
        break;
      }
    }

    /* End of Chart: '<S9>/KeyOnAntiStateReq' */

    /* Chart: '<S9>/ChgAntiStateReq' incorporates:
     *  Constant: '<S9>/Constant17'
     *  Constant: '<S9>/Constant5'
     */
    if (swc_RMLK_ARID_DEF.is_active_c1_swc_RMLK == 0U) {
      swc_RMLK_ARID_DEF.is_active_c1_swc_RMLK = 1U;
      swc_RMLK_ARID_DEF.is_c1_swc_RMLK = swc_RMLK_IN_UpdateAntiReq;
      swc_RMLK_ARID_DEF.AntiReq_b = swc_RMLK_ARID_DEF.AntiReq;
      swc_RMLK_ARID_DEF.TboxReq_g = false;
      swc_RMLK_ARID_DEF.timer_fy = 0.0F;
    } else {
      switch (swc_RMLK_ARID_DEF.is_c1_swc_RMLK) {
       case swc_RMLK_IN_ChgAntiVerify:
        if (!TBOX_AuthSuccess) {
          swc_RMLK_ARID_DEF.is_ChgAntiVerify = swc_RMLK_IN_NO_ACTIVE_CHILD;
          swc_RMLK_ARID_DEF.is_c1_swc_RMLK = swc_RMLK_IN_UpdateAntiReq;
          swc_RMLK_ARID_DEF.AntiReq_b = swc_RMLK_ARID_DEF.AntiReq;
          swc_RMLK_ARID_DEF.TboxReq_g = false;
          swc_RMLK_ARID_DEF.timer_fy = 0.0F;
        } else {
          switch (swc_RMLK_ARID_DEF.is_ChgAntiVerify) {
           case swc_RMLK_IN_AntiActv:
           case swc_RMLK_IN_AntiNotActv:
            break;

           default:
            /* case IN_KeyOnTimer: */
            if (((rtb_Switch1_mx == 5) || (!swc_RMLK_ARID_DEF.TboxReq_g)) &&
                (swc_RMLK_ARID_DEF.timer_fy >= rlcc_tm_antiChgTm_s)) {
              swc_RMLK_ARID_DEF.is_ChgAntiVerify = swc_RMLK_IN_AntiActv;
              swc_RMLK_ARID_DEF.AntiReq_b = 1U;
            } else if (rtb_Switch1_mx == 6) {
              swc_RMLK_ARID_DEF.is_ChgAntiVerify = swc_RMLK_IN_AntiNotActv;
              swc_RMLK_ARID_DEF.AntiReq_b = 2U;
            } else {
              swc_RMLK_ARID_DEF.timer_fy += 0.01F;
            }
            break;
          }
        }
        break;

       case swc_RMLK_IN_FuelUpVerify:
        if (!rtb_Compare_fof) {
          swc_RMLK_ARID_DEF.is_FuelUpVerify = swc_RMLK_IN_NO_ACTIVE_CHILD;
          swc_RMLK_ARID_DEF.is_c1_swc_RMLK = swc_RMLK_IN_UpdateAntiReq;
          swc_RMLK_ARID_DEF.AntiReq_b = swc_RMLK_ARID_DEF.AntiReq;
          swc_RMLK_ARID_DEF.TboxReq_g = false;
          swc_RMLK_ARID_DEF.timer_fy = 0.0F;
        } else {
          switch (swc_RMLK_ARID_DEF.is_FuelUpVerify) {
           case swc_RMLK_IN_AntiActv:
           case swc_RMLK_IN_AntiNotActv:
            break;

           default:
            /* case IN_KeyOnTimer: */
            if (((rtb_Switch1_mx == 5) || (!swc_RMLK_ARID_DEF.TboxReq_g)) &&
                (swc_RMLK_ARID_DEF.timer_fy >= rlcc_tm_antiKL15Tm_s)) {
              swc_RMLK_ARID_DEF.is_FuelUpVerify = swc_RMLK_IN_AntiActv;
              swc_RMLK_ARID_DEF.AntiReq_b = 1U;
            } else if (rtb_Switch1_mx == 6) {
              swc_RMLK_ARID_DEF.is_FuelUpVerify = swc_RMLK_IN_AntiNotActv;
              swc_RMLK_ARID_DEF.AntiReq_b = 2U;
            } else {
              swc_RMLK_ARID_DEF.timer_fy += 0.01F;
            }
            break;
          }
        }
        break;

       default:
        /* case IN_UpdateAntiReq: */
        if (TBOX_AuthSuccess) {
          swc_RMLK_ARID_DEF.is_c1_swc_RMLK = swc_RMLK_IN_ChgAntiVerify;
          swc_RMLK_ARID_DEF.is_ChgAntiVerify = swc_RMLK_IN_KeyOnTimer;
          swc_RMLK_ARID_DEF.timer_fy += 0.01F;
        } else if (rtb_Compare_fof) {
          swc_RMLK_ARID_DEF.is_c1_swc_RMLK = swc_RMLK_IN_FuelUpVerify;
          swc_RMLK_ARID_DEF.is_FuelUpVerify = swc_RMLK_IN_KeyOnTimer;
          swc_RMLK_ARID_DEF.timer_fy += 0.01F;
        } else {
          swc_RMLK_ARID_DEF.AntiReq_b = swc_RMLK_ARID_DEF.AntiReq;
        }
        break;
      }
    }

    /* End of Chart: '<S9>/ChgAntiStateReq' */

    /* UnitDelay: '<S9>/Unit Delay9' */
    rtb_UnitDelay9_h = swc_RMLK_ARID_DEF.UnitDelay9_DSTATE_i;

    /* Switch: '<S11>/Switch8' incorporates:
     *  Logic: '<S11>/Logical Operator'
     *  Logic: '<S155>/Logical Operator'
     *  Logic: '<S155>/Logical Operator1'
     *  Logic: '<S156>/Logical Operator'
     *  Logic: '<S156>/Logical Operator1'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S155>/Unit Delay'
     *  UnitDelay: '<S156>/Unit Delay'
     */
    if ((rlcd_b_ignOn && (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_ni)) ||
        (rlcd_b_obcWakeUp && (!swc_RMLK_ARID_DEF.UnitDelay_DSTATE_fw)) ||
        swc_RMLK_ARID_DEF.UnitDelay_DSTATE_i1) {
      /* Switch: '<S11>/Switch8' */
      rtb_UnitDelay8 = rlcd_num_VCU_ChgLockSaveResult;
    } else {
      /* Switch: '<S11>/Switch8' incorporates:
       *  UnitDelay: '<S11>/Unit Delay2'
       */
      rtb_UnitDelay8 = swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_f;
    }

    /* End of Switch: '<S11>/Switch8' */

    /* Switch: '<S9>/Switch' incorporates:
     *  Constant: '<S101>/Constant'
     *  Constant: '<S54>/Constant'
     *  Constant: '<S84>/Constant'
     *  Constant: '<S98>/Constant'
     *  Constant: '<S9>/Constant3'
     *  Logic: '<S9>/Logical Operator3'
     *  RelationalOperator: '<S101>/Compare'
     *  RelationalOperator: '<S54>/Compare'
     *  RelationalOperator: '<S84>/Compare'
     *  RelationalOperator: '<S98>/Compare'
     */
    if (rlcc_b_VSLTEST1_sw) {
      rtb_LogicalOperator_oe = rlcc_b_VSLTEST1_sw;
    } else {
      rtb_LogicalOperator_oe = ((rtb_UnitDelay9_h == ((uint8)1U)) &&
        (rtb_DataTypeConversion == ((uint8)1U)) && (rlcd_TBOX_LockVehCtrl ==
        ((uint8)1U)) && (rlcd_TBOX_LockVehType == ((uint8)0U)));
    }

    /* Switch: '<S9>/Switch3' incorporates:
     *  Constant: '<S52>/Constant'
     *  Constant: '<S53>/Constant'
     *  Constant: '<S83>/Constant'
     *  Constant: '<S85>/Constant'
     *  Constant: '<S86>/Constant'
     *  Constant: '<S87>/Constant'
     *  Constant: '<S88>/Constant'
     *  Constant: '<S89>/Constant'
     *  Constant: '<S93>/Constant'
     *  Constant: '<S94>/Constant'
     *  Logic: '<S9>/Logical Operator15'
     *  Logic: '<S9>/Logical Operator5'
     *  RelationalOperator: '<S52>/Compare'
     *  RelationalOperator: '<S53>/Compare'
     *  RelationalOperator: '<S83>/Compare'
     *  RelationalOperator: '<S85>/Compare'
     *  RelationalOperator: '<S86>/Compare'
     *  RelationalOperator: '<S87>/Compare'
     *  RelationalOperator: '<S88>/Compare'
     *  RelationalOperator: '<S89>/Compare'
     *  RelationalOperator: '<S93>/Compare'
     *  RelationalOperator: '<S94>/Compare'
     *  Switch: '<S9>/Switch'
     *  Switch: '<S9>/Switch1'
     *  Switch: '<S9>/Switch4'
     *  UnitDelay: '<S9>/Unit Delay4'
     *  UnitDelay: '<S9>/Unit Delay5'
     */
    if (rtb_LogicalOperator_oe) {
      /* Switch: '<S9>/Switch3' incorporates:
       *  Constant: '<S9>/Constant15'
       */
      rlcd_num_NormLockReqRaw = ((uint8)1U);
    } else if ((rtb_UnitDelay9_h == ((uint8)1U)) && (rtb_DataTypeConversion ==
                ((uint8)1U)) && (rlcd_TBOX_LockVehCtrl == ((uint8)0U))) {
      /* Switch: '<S9>/Switch4' incorporates:
       *  Constant: '<S9>/Constant7'
       *  Switch: '<S9>/Switch3'
       */
      rlcd_num_NormLockReqRaw = ((uint8)2U);
    } else if ((rtb_UnitDelay9_h == ((uint8)0U)) && (rtb_DataTypeConversion ==
                ((uint8)1U)) && (rtb_CCaller4_a != ((uint8)1U)) &&
               (rtb_UnitDelay8 != ((uint8)1U)) && (rtb_CCaller5 != ((uint8)1U)) &&
               (swc_RMLK_ARID_DEF.UnitDelay4_DSTATE_a != true) &&
               (swc_RMLK_ARID_DEF.UnitDelay5_DSTATE_a != true)) {
      /* Switch: '<S9>/Switch1' incorporates:
       *  Constant: '<S9>/Constant1'
       *  Switch: '<S9>/Switch3'
       *  Switch: '<S9>/Switch4'
       */
      rlcd_num_NormLockReqRaw = ((uint8)0U);
    } else {
      /* Switch: '<S9>/Switch3' incorporates:
       *  Switch: '<S9>/Switch4'
       *  UnitDelay: '<S9>/Unit Delay3'
       */
      rlcd_num_NormLockReqRaw = swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_d;
    }

    /* End of Switch: '<S9>/Switch3' */

    /* Switch: '<S9>/Switch9' incorporates:
     *  Constant: '<S57>/Constant'
     *  Constant: '<S58>/Constant'
     *  Constant: '<S60>/Constant'
     *  Constant: '<S61>/Constant'
     *  Constant: '<S9>/Constant11'
     *  Logic: '<S9>/Logical Operator6'
     *  RelationalOperator: '<S57>/Compare'
     *  RelationalOperator: '<S58>/Compare'
     *  RelationalOperator: '<S60>/Compare'
     *  RelationalOperator: '<S61>/Compare'
     */
    if (rlcc_b_VSLTEST2_sw) {
      rtb_LogicalOperator_oe = rlcc_b_VSLTEST2_sw;
    } else {
      rtb_LogicalOperator_oe = ((rtb_UnitDelay9_h == ((uint8)1U)) &&
        (rtb_DataTypeConversion == ((uint8)1U)) && (rlcd_TBOX_LockVehCtrl ==
        ((uint8)1U)) && (rlcd_TBOX_LockVehType == ((uint8)0U)));
    }

    /* Switch: '<S9>/Switch5' incorporates:
     *  Constant: '<S55>/Constant'
     *  Constant: '<S56>/Constant'
     *  Constant: '<S59>/Constant'
     *  Constant: '<S67>/Constant'
     *  Constant: '<S77>/Constant'
     *  Constant: '<S79>/Constant'
     *  Constant: '<S80>/Constant'
     *  Constant: '<S81>/Constant'
     *  Constant: '<S82>/Constant'
     *  Constant: '<S95>/Constant'
     *  Logic: '<S9>/Logical Operator14'
     *  Logic: '<S9>/Logical Operator7'
     *  RelationalOperator: '<S55>/Compare'
     *  RelationalOperator: '<S56>/Compare'
     *  RelationalOperator: '<S59>/Compare'
     *  RelationalOperator: '<S67>/Compare'
     *  RelationalOperator: '<S77>/Compare'
     *  RelationalOperator: '<S79>/Compare'
     *  RelationalOperator: '<S80>/Compare'
     *  RelationalOperator: '<S81>/Compare'
     *  RelationalOperator: '<S82>/Compare'
     *  RelationalOperator: '<S95>/Compare'
     *  Switch: '<S9>/Switch2'
     *  Switch: '<S9>/Switch7'
     *  Switch: '<S9>/Switch9'
     *  UnitDelay: '<S9>/Unit Delay'
     *  UnitDelay: '<S9>/Unit Delay6'
     */
    if (rtb_LogicalOperator_oe) {
      /* Switch: '<S9>/Switch5' incorporates:
       *  Constant: '<S9>/Constant9'
       */
      rtb_Switch5 = ((uint8)1U);
    } else if ((rtb_UnitDelay9_h == ((uint8)1U)) && (rtb_DataTypeConversion ==
                ((uint8)1U)) && (rlcd_TBOX_LockVehCtrl == ((uint8)0U))) {
      /* Switch: '<S9>/Switch7' incorporates:
       *  Constant: '<S9>/Constant10'
       *  Switch: '<S9>/Switch5'
       */
      rtb_Switch5 = ((uint8)2U);
    } else if ((rtb_UnitDelay9_h == ((uint8)0U)) && (rtb_DataTypeConversion ==
                ((uint8)1U)) && (rtb_CCaller4_a != ((uint8)1U)) &&
               (rtb_UnitDelay8 != ((uint8)1U)) && (rtb_CCaller5 != ((uint8)1U)) &&
               (swc_RMLK_ARID_DEF.UnitDelay_DSTATE_fh != true) &&
               (swc_RMLK_ARID_DEF.UnitDelay6_DSTATE != true)) {
      /* Switch: '<S9>/Switch2' incorporates:
       *  Constant: '<S9>/Constant2'
       *  Switch: '<S9>/Switch5'
       *  Switch: '<S9>/Switch7'
       */
      rtb_Switch5 = ((uint8)0U);
    } else {
      /* Switch: '<S9>/Switch5' incorporates:
       *  Switch: '<S9>/Switch7'
       *  UnitDelay: '<S9>/Unit Delay1'
       */
      rtb_Switch5 = swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_d;
    }

    /* End of Switch: '<S9>/Switch5' */

    /* RelationalOperator: '<S66>/Compare' incorporates:
     *  Constant: '<S66>/Constant'
     */
    rtb_Compare_gl = (rtb_Switch5 == ((uint8)2U));

    /* Logic: '<S9>/Logical Operator4' incorporates:
     *  Constant: '<S63>/Constant'
     *  Constant: '<S65>/Constant'
     *  Constant: '<S73>/Constant'
     *  Logic: '<S9>/Logical Operator10'
     *  Logic: '<S9>/Logical Operator8'
     *  RelationalOperator: '<S63>/Compare'
     *  RelationalOperator: '<S65>/Compare'
     *  RelationalOperator: '<S73>/Compare'
     */
    rtb_LogicalOperator4_a = (((rtb_Switch5 == ((uint8)1U)) || (rtb_UnitDelay8 ==
      ((uint8)1U))) && (rtb_Switch5 != ((uint8)2U)) && rlcd_b_chgAnti_flg);

    /* Outputs for Atomic SubSystem: '<S9>/SR_latch' */
    swc_RMLK_SR_latch(rtb_LogicalOperator4_a, rtb_Compare_gl,
                      &rtb_LogicalOperator4_l,
                      &swc_RMLK_ARID_DEF.ARID_DEF_SR_latch_p);

    /* End of Outputs for SubSystem: '<S9>/SR_latch' */

    /* Switch: '<S9>/Switch6' incorporates:
     *  Constant: '<S9>/Constant13'
     *  Switch: '<S9>/Switch10'
     *  Switch: '<S9>/Switch8'
     */
    if (rlcc_b_VSLTEST3_sw || rtb_LogicalOperator4_l) {
      /* Switch: '<S9>/Switch6' incorporates:
       *  Constant: '<S9>/Constant12'
       */
      rtb_Switch6 = ((uint8)1U);
    } else if (rtb_Compare_gl) {
      /* Switch: '<S9>/Switch8' incorporates:
       *  Constant: '<S9>/Constant4'
       *  Switch: '<S9>/Switch6'
       */
      rtb_Switch6 = ((uint8)2U);
    } else {
      /* Switch: '<S9>/Switch6' incorporates:
       *  UnitDelay: '<S9>/Unit Delay2'
       */
      rtb_Switch6 = swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_ko;
    }

    /* End of Switch: '<S9>/Switch6' */

    /* RelationalOperator: '<S70>/Compare' incorporates:
     *  Constant: '<S70>/Constant'
     */
    rtb_Compare_ev = (rtb_Switch6 == ((uint8)1U));

    /* Switch: '<S9>/Switch12' incorporates:
     *  Constant: '<S100>/Constant'
     *  Constant: '<S62>/Constant'
     *  Constant: '<S91>/Constant'
     *  Logic: '<S9>/Logical Operator19'
     *  RelationalOperator: '<S100>/Compare'
     *  RelationalOperator: '<S62>/Compare'
     *  RelationalOperator: '<S91>/Compare'
     *  Switch: '<S9>/Switch16'
     */
    if (rlcd_num_NormLockReqRaw != ((uint8)0U)) {
      /* Switch: '<S9>/Switch12' */
      rlcd_num_NormLockReq = rlcd_num_NormLockReqRaw;
    } else if ((rlcd_b_NormLockActv == false) && (rlcd_b_NormLockNotActv ==
                false)) {
      /* Switch: '<S9>/Switch16' incorporates:
       *  Switch: '<S9>/Switch12'
       */
      rlcd_num_NormLockReq = rlcd_num_NormLockSaveRltRaw;
    } else {
      /* Switch: '<S9>/Switch12' incorporates:
       *  Switch: '<S9>/Switch16'
       */
      rlcd_num_NormLockReq = rtb_CCaller4_a;
    }

    /* End of Switch: '<S9>/Switch12' */

    /* RelationalOperator: '<S192>/Compare' incorporates:
     *  RelationalOperator: '<S102>/FixPt Relational Operator'
     *  UnitDelay: '<S102>/Delay Input1'
     *
     * Block description for '<S102>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_Compare_oc = ((sint32)rlcd_b_ignOn > (sint32)
                      swc_RMLK_ARID_DEF.DelayInput1_DSTATE_hw);

    /* Logic: '<S9>/Logical Operator11' incorporates:
     *  Constant: '<S71>/Constant'
     *  Constant: '<S72>/Constant'
     *  Constant: '<S74>/Constant'
     *  Constant: '<S96>/Constant'
     *  Constant: '<S97>/Constant'
     *  Logic: '<S9>/Logical Operator16'
     *  Logic: '<S9>/Logical Operator20'
     *  RelationalOperator: '<S71>/Compare'
     *  RelationalOperator: '<S72>/Compare'
     *  RelationalOperator: '<S74>/Compare'
     *  RelationalOperator: '<S96>/Compare'
     *  RelationalOperator: '<S97>/Compare'
     */
    rtb_LogicalOperator11 = ((rtb_CCaller5 == ((uint8)1U)) || (rtb_CCaller4_a ==
      ((uint8)1U)) || (rtb_CCaller3_a == ((uint8)1U)) || ((rtb_UnitDelay8 ==
      ((uint8)2U)) && rtb_Compare_oc) || (rtb_Compare_oc &&
      (rlcd_num_NormLockReq == ((uint8)2U))));

    /* Outputs for Atomic SubSystem: '<S9>/SR_latch1' */
    swc_RMLK_SR_latch1(rtb_Compare_ev, rtb_LogicalOperator11,
                       &rtb_LogicalOperator3_k,
                       &swc_RMLK_ARID_DEF.ARID_DEF_SR_latch1_b);

    /* End of Outputs for SubSystem: '<S9>/SR_latch1' */

    /* UnitDelay: '<S9>/Unit Delay7' */
    rtb_UnitDelay7 = swc_RMLK_ARID_DEF.UnitDelay7_DSTATE;

    /* Outputs for Atomic SubSystem: '<S9>/SR_latch5' */
    swc_RMLK_SR_latch1(rtb_UnitDelay7, rtb_LogicalOperator11,
                       &rtb_LogicalOperator3_a,
                       &swc_RMLK_ARID_DEF.ARID_DEF_SR_latch5);

    /* End of Outputs for SubSystem: '<S9>/SR_latch5' */

    /* Logic: '<S9>/Logical Operator' */
    rlcd_b_ChgLockExcReqCur = (rtb_LogicalOperator3_k || rtb_LogicalOperator3_a);

    /* Logic: '<S9>/Logical Operator1' incorporates:
     *  Constant: '<S51>/Constant'
     *  RelationalOperator: '<S51>/Compare'
     */
    rtb_LogicalOperator1_k = ((swc_RMLK_ARID_DEF.AntiReq_b == ((uint8)1U)) &&
      TBOX_AuthSuccess);

    /* Logic: '<S9>/Logical Operator18' incorporates:
     *  Constant: '<S78>/Constant'
     *  RelationalOperator: '<S78>/Compare'
     */
    rtb_LogicalOperator18_l = ((swc_RMLK_ARID_DEF.AntiReq_b == ((uint8)1U)) &&
      rtb_Compare_fof);

    /* Logic: '<S9>/Logical Operator9' incorporates:
     *  Constant: '<S90>/Constant'
     *  Constant: '<S99>/Constant'
     *  Logic: '<S9>/Logical Operator13'
     *  RelationalOperator: '<S103>/FixPt Relational Operator'
     *  RelationalOperator: '<S90>/Compare'
     *  RelationalOperator: '<S99>/Compare'
     *  UnitDelay: '<S103>/Delay Input1'
     *
     * Block description for '<S103>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_LogicalOperator9 = ((rtb_CCaller3_a == ((uint8)1U)) || ((rtb_CCaller3_a ==
      ((uint8)2U)) && ((sint32)rlcd_b_ignOn > (sint32)
                       swc_RMLK_ARID_DEF.DelayInput1_DSTATE_b)));

    /* Outputs for Atomic SubSystem: '<S9>/SR_latch2' */
    swc_RMLK_SR_latch2(rtb_LogicalOperator1_k, rtb_LogicalOperator9,
                       &rtb_LogicalOperator3_ic,
                       &swc_RMLK_ARID_DEF.ARID_DEF_SR_latch2);

    /* End of Outputs for SubSystem: '<S9>/SR_latch2' */

    /* Outputs for Atomic SubSystem: '<S9>/SR_latch4' */
    swc_RMLK_SR_latch2(rtb_LogicalOperator18_l, rtb_LogicalOperator9,
                       &rtb_LogicalOperator3_i,
                       &swc_RMLK_ARID_DEF.ARID_DEF_SR_latch4);

    /* End of Outputs for SubSystem: '<S9>/SR_latch4' */

    /* Switch: '<S9>/Switch13' incorporates:
     *  Constant: '<S64>/Constant'
     *  RelationalOperator: '<S64>/Compare'
     */
    if (rtb_Switch5 != ((uint8)0U)) {
      /* Switch: '<S9>/Switch13' */
      rlcd_num_ChgLockReq = rtb_Switch5;
    } else {
      /* Switch: '<S9>/Switch13' */
      rlcd_num_ChgLockReq = rtb_UnitDelay8;
    }

    /* End of Switch: '<S9>/Switch13' */

    /* Switch: '<S9>/Switch14' incorporates:
     *  Constant: '<S68>/Constant'
     *  RelationalOperator: '<S68>/Compare'
     */
    if (rtb_Switch6 != ((uint8)0U)) {
      /* Switch: '<S9>/Switch14' */
      rlcd_num_ChgLockExcReq = rtb_Switch6;
    } else {
      /* Switch: '<S9>/Switch14' */
      rlcd_num_ChgLockExcReq = rtb_CCaller5;
    }

    /* End of Switch: '<S9>/Switch14' */

    /* Switch: '<S9>/Switch15' incorporates:
     *  Constant: '<S69>/Constant'
     *  RelationalOperator: '<S69>/Compare'
     */
    if (swc_RMLK_ARID_DEF.AntiReq_b != ((uint8)0U)) {
      /* Switch: '<S9>/Switch15' */
      rlcd_num_AntiLockReq = swc_RMLK_ARID_DEF.AntiReq_b;
    } else {
      /* Switch: '<S9>/Switch15' */
      rlcd_num_AntiLockReq = rtb_CCaller3_a;
    }

    /* End of Switch: '<S9>/Switch15' */

    /* SignalConversion generated from: '<S9>/SR_latch2' */
    rlcd_b_ChgAntiLockReq = rtb_LogicalOperator3_ic;

    /* SignalConversion generated from: '<S9>/SR_latch4' */
    rlcd_b_fuleUpAntiLockExcReq = rtb_LogicalOperator3_i;
    for (i = 0; i < 7; i++) {
      /* RelationalOperator: '<S10>/Relational Operator3' incorporates:
       *  Constant: '<S10>/Constant5'
       */
      rtb_RelationalOperator9[i] = (rlcd_v_pmsReqSeed[i] !=
        swc_RMLK_ConstP.pooled18[i]);
    }

    /* Logic: '<S10>/Logical Operator16' */
    TBOX_AuthSuccess = rtb_RelationalOperator9[0];
    for (i = 0; i < 6; i++) {
      TBOX_AuthSuccess = (TBOX_AuthSuccess && rtb_RelationalOperator9[i + 1]);
    }

    /* Logic: '<S10>/Logical Operator11' incorporates:
     *  Constant: '<S122>/Constant'
     *  Constant: '<S125>/Constant'
     *  Logic: '<S10>/Logical Operator16'
     *  RelationalOperator: '<S122>/Compare'
     *  RelationalOperator: '<S125>/Compare'
     */
    rlcd_b_aswTboxUpdate = ((rlcd_num_VCU_AuthResult != ((uint8)0U)) ||
      (rlcd_num_pmsRespResult != ((uint8)0U)) || TBOX_AuthSuccess);

    /* Logic: '<S10>/Logical Operator17' incorporates:
     *  Logic: '<S10>/Logical Operator19'
     *  Logic: '<S10>/Logical Operator27'
     *  Logic: '<S10>/Logical Operator28'
     */
    rtb_LogicalOperator17_a = (TBOX_SeedReq || ((!rlcd_b_ignOn) &&
      (!rlcd_b_obcWakeUp)));

    /* Outputs for Atomic SubSystem: '<S10>/SR_latch' */
    swc_RMLK_SR_latch(rtb_Compare_em, rtb_LogicalOperator17_a,
                      &rtb_LogicalOperator4_l,
                      &swc_RMLK_ARID_DEF.ARID_DEF_SR_latch);

    /* End of Outputs for SubSystem: '<S10>/SR_latch' */

    /* UnitDelay: '<S11>/Unit Delay3' */
    rtb_UnitDelay3_bb = swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_l;

    /* RelationalOperator: '<S12>/Compare' incorporates:
     *  Constant: '<S12>/Constant'
     */
    rlcd_b_rmtCtrlNormLock = (rtb_CCaller4_a == ((uint8)1U));

    /* RelationalOperator: '<S13>/Compare' incorporates:
     *  Constant: '<S13>/Constant'
     */
    rlcd_b_rmtCtrlChrgLock = (rtb_CCaller5 == ((uint8)1U));

    /* RelationalOperator: '<S14>/Compare' incorporates:
     *  Constant: '<S14>/Constant'
     */
    rlcd_b_rmtCtrlAntiDismtLock = (rtb_CCaller3_a == ((uint8)1U));

    /* Logic: '<S4>/Logical Operator3' */
    TBOX_SeedReq = (rlcd_b_ignOn || rlcd_b_obcWakeUp);

    /* Outputs for Atomic SubSystem: '<S4>/turnON_delay' */
    /* Chart: '<S27>/timed_delay' incorporates:
     *  Constant: '<S4>/Constant4'
     *  Logic: '<S4>/Logical Operator3'
     */
    if (swc_RMLK_ARID_DEF.is_active_c14_mylib2017a == 0U) {
      swc_RMLK_ARID_DEF.is_active_c14_mylib2017a = 1U;
      if (TBOX_SeedReq) {
        swc_RMLK_ARID_DEF.is_c14_mylib2017a = swc_RMLK_IN_ON_l;
      } else {
        swc_RMLK_ARID_DEF.is_c14_mylib2017a = swc_RMLK_IN_OFF;
      }
    } else {
      switch (swc_RMLK_ARID_DEF.is_c14_mylib2017a) {
       case swc_RMLK_IN_OFF:
        if (TBOX_SeedReq) {
          if (swc_RMLK_ConstB.t_delay_on == 0.0F) {
            swc_RMLK_ARID_DEF.is_c14_mylib2017a = swc_RMLK_IN_ON_l;
          } else {
            swc_RMLK_ARID_DEF.is_c14_mylib2017a = swc_RMLK_IN_ON_WAIT;
            swc_RMLK_ARID_DEF.t_wait = 0.0F;
            swc_RMLK_ARID_DEF.t_wait += 0.01F;
            TBOX_SeedReq = false;
          }
        }
        break;

       case swc_RMLK_IN_ON_l:
        if (!TBOX_SeedReq) {
          swc_RMLK_ARID_DEF.is_c14_mylib2017a = swc_RMLK_IN_OFF;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!TBOX_SeedReq) {
          swc_RMLK_ARID_DEF.is_c14_mylib2017a = swc_RMLK_IN_OFF;
        } else if (swc_RMLK_ARID_DEF.t_wait > swc_RMLK_ConstB.t_delay_on - 0.01F)
        {
          swc_RMLK_ARID_DEF.is_c14_mylib2017a = swc_RMLK_IN_ON_l;
        } else {
          swc_RMLK_ARID_DEF.t_wait += 0.01F;
          TBOX_SeedReq = false;
        }
        break;
      }
    }

    /* End of Chart: '<S27>/timed_delay' */
    /* End of Outputs for SubSystem: '<S4>/turnON_delay' */

    /* DataTypeConversion: '<S4>/Data Type Conversion1' */
    rtb_DataTypeConversion = rlcd_num_FunLockVehActiveReq;

    /* DataTypeConversion: '<S4>/Data Type Conversion11' */
    rtb_UnitDelay9_h = rlcd_num_pmsRespResult;
    for (i = 0; i < 7; i++) {
      /* DataTypeConversion: '<S4>/Data Type Conversion12' */
      rtb_CCaller1_i[i] = rlcd_v_pmsReqSeed[i];
    }

    /* DataTypeConversion: '<S4>/Data Type Conversion2' */
    FunAntiDismtActiveResultCur = rlcd_num_FunAnti_DismantleActiveReq;

    /* DataTypeConversion: '<S4>/Data Type Conversion3' */
    LockLimSetBswCur = rlcd_num_LockLimSetReq;

    /* DataTypeConversion: '<S4>/Data Type Conversion4' */
    VCU_NormLockSaveResultCur = rlcd_num_NormLockReq;

    /* DataTypeConversion: '<S4>/Data Type Conversion5' */
    rlcd_num_ChgLockReq_o = rlcd_num_ChgLockReq;

    /* DataTypeConversion: '<S4>/Data Type Conversion6' */
    vsld_num_ChgLockExcReq = rlcd_num_ChgLockExcReq;

    /* DataTypeConversion: '<S4>/Data Type Conversion7' */
    rlcd_num_AntiLockReq_b = rlcd_num_AntiLockReq;

    /* Logic: '<S184>/Logical Operator5' incorporates:
     *  Constant: '<S207>/Constant'
     *  Constant: '<S208>/Constant'
     *  RelationalOperator: '<S207>/Compare'
     *  RelationalOperator: '<S208>/Compare'
     */
    rtb_Compare_oc = (rlcd_b_ChgLockExcReqCur || (rtb_CCaller4_a == ((uint8)1U))
                      || (rtb_CCaller5 == ((uint8)1U)));

    /* RelationalOperator: '<S206>/Compare' incorporates:
     *  Constant: '<S206>/Constant'
     */
    TBOX_AuthSuccess = (rlcd_num_NormLockReqRaw == ((uint8)1U));

    /* RelationalOperator: '<S210>/Compare' incorporates:
     *  Constant: '<S210>/Constant'
     */
    TBOX_AuthFail_dismatch = (rtb_Switch5 == ((uint8)1U));

    /* Logic: '<S184>/Logical Operator1' incorporates:
     *  RelationalOperator: '<S218>/FixPt Relational Operator'
     *  RelationalOperator: '<S219>/FixPt Relational Operator'
     *  UnitDelay: '<S218>/Delay Input1'
     *  UnitDelay: '<S219>/Delay Input1'
     *
     * Block description for '<S218>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S219>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_LogicalOperator1_o0 = (((sint32)TBOX_AuthSuccess > (sint32)
      swc_RMLK_ARID_DEF.DelayInput1_DSTATE_k) || ((sint32)TBOX_AuthFail_dismatch
      > (sint32)swc_RMLK_ARID_DEF.DelayInput1_DSTATE_a));

    /* RelationalOperator: '<S211>/Compare' incorporates:
     *  Constant: '<S211>/Constant'
     */
    rtb_Compare_ok = (rlcd_num_NormLockReqRaw == ((uint8)2U));

    /* RelationalOperator: '<S212>/Compare' incorporates:
     *  Constant: '<S212>/Constant'
     */
    rtb_Compare_dp = (rtb_Switch5 == ((uint8)2U));

    /* Logic: '<S184>/Logical Operator2' incorporates:
     *  RelationalOperator: '<S220>/FixPt Relational Operator'
     *  RelationalOperator: '<S221>/FixPt Relational Operator'
     *  UnitDelay: '<S220>/Delay Input1'
     *  UnitDelay: '<S221>/Delay Input1'
     *
     * Block description for '<S220>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S221>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_LogicalOperator2_c = (((sint32)rtb_Compare_ok > (sint32)
      swc_RMLK_ARID_DEF.DelayInput1_DSTATE_m) || ((sint32)rtb_Compare_dp >
      (sint32)swc_RMLK_ARID_DEF.DelayInput1_DSTATE_n));

    /* RelationalOperator: '<S213>/Compare' incorporates:
     *  Constant: '<S213>/Constant'
     */
    rtb_Compare_hjh = (rlcd_num_NormLockReqRaw == ((uint8)0U));

    /* RelationalOperator: '<S214>/Compare' incorporates:
     *  Constant: '<S214>/Constant'
     */
    rtb_Compare_pv = (rtb_Switch5 == ((uint8)0U));

    /* RelationalOperator: '<S225>/Relational Operator' incorporates:
     *  UnitDelay: '<S225>/Unit Delay1'
     */
    rtb_RelationalOperator_j = (rlcd_num_ExeStsUpdateSaveResult !=
      swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_j);

    /* UnitDelay: '<S225>/Unit Delay3' */
    rtb_UnitDelay3_hg = swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_h;

    /* Outputs for Atomic SubSystem: '<S227>/Falling_Edge' */
    swc_RMLK_Falling_Edge1(rlcd_b_ignOn, &rtb_flg_out_d,
      &swc_RMLK_ARID_DEF.ARID_DEF_Falling_Edge_c);

    /* End of Outputs for SubSystem: '<S227>/Falling_Edge' */

    /* Outputs for Atomic SubSystem: '<S227>/Falling_Edge1' */
    swc_RMLK_Falling_Edge1(rlcd_b_obcWakeUp, &rtb_flg_out_g5,
      &swc_RMLK_ARID_DEF.ARID_DEF_Falling_Edge1_m);

    /* End of Outputs for SubSystem: '<S227>/Falling_Edge1' */

    /* Switch: '<S227>/Switch1' incorporates:
     *  Constant: '<S227>/Constant'
     *  Logic: '<S227>/Logical Operator1'
     *  Logic: '<S227>/Logical Operator4'
     *  RelationalOperator: '<S227>/Relational Operator1'
     */
    if ((rtb_UnitDelay3_hg != ((uint8)0U)) && (rtb_flg_out_d || rtb_flg_out_g5))
    {
      /* Switch: '<S227>/Switch1' */
      rtb_Switch1_g = rtb_UnitDelay3_hg;
    } else {
      /* Switch: '<S227>/Switch1' incorporates:
       *  UnitDelay: '<S227>/Unit Delay4'
       */
      rtb_Switch1_g = swc_RMLK_ARID_DEF.UnitDelay4_DSTATE_c;
    }

    /* End of Switch: '<S227>/Switch1' */

    /* Switch: '<S225>/Switch8' incorporates:
     *  Constant: '<S228>/Constant'
     *  Logic: '<S225>/Logical Operator4'
     *  Logic: '<S227>/Logical Operator3'
     *  Logic: '<S227>/Logical Operator5'
     *  RelationalOperator: '<S228>/Compare'
     *  RelationalOperator: '<S229>/FixPt Relational Operator'
     *  RelationalOperator: '<S230>/FixPt Relational Operator'
     *  UnitDelay: '<S229>/Delay Input1'
     *  UnitDelay: '<S230>/Delay Input1'
     *
     * Block description for '<S229>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S230>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (rtb_RelationalOperator_j || ((((sint32)rlcd_b_ignOn > (sint32)
           swc_RMLK_ARID_DEF.DelayInput1_DSTATE_bz) || ((sint32)rlcd_b_obcWakeUp
           > (sint32)swc_RMLK_ARID_DEF.DelayInput1_DSTATE_i)) && (rtb_Switch1_g
          != ((uint8)0U)))) {
      /* Switch: '<S225>/Switch9' */
      if (rtb_RelationalOperator_j) {
        /* Switch: '<S225>/Switch8' */
        rtb_UnitDelay3_hg = rlcd_num_ExeStsUpdateSaveResult;
      }

      /* End of Switch: '<S225>/Switch9' */
    } else {
      /* Switch: '<S225>/Switch8' incorporates:
       *  UnitDelay: '<S225>/Unit Delay2'
       */
      rtb_UnitDelay3_hg = swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_ij;
    }

    /* End of Switch: '<S225>/Switch8' */

    /* RelationalOperator: '<S226>/Relational Operator' incorporates:
     *  UnitDelay: '<S226>/Unit Delay1'
     */
    rtb_RelationalOperator_j = (rlcd_num_ExeStsUpdate1SaveResult !=
      swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_k);

    /* UnitDelay: '<S226>/Unit Delay3' */
    rtb_UnitDelay3_f = swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_ay;

    /* Outputs for Atomic SubSystem: '<S239>/Falling_Edge' */
    swc_RMLK_Falling_Edge1(rlcd_b_ignOn, &rtb_flg_out_l,
      &swc_RMLK_ARID_DEF.ARID_DEF_Falling_Edge);

    /* End of Outputs for SubSystem: '<S239>/Falling_Edge' */

    /* Outputs for Atomic SubSystem: '<S239>/Falling_Edge1' */
    swc_RMLK_Falling_Edge1(rlcd_b_obcWakeUp, &rtb_flg_out_g,
      &swc_RMLK_ARID_DEF.ARID_DEF_Falling_Edge1);

    /* End of Outputs for SubSystem: '<S239>/Falling_Edge1' */

    /* Switch: '<S239>/Switch1' incorporates:
     *  Constant: '<S239>/Constant'
     *  Logic: '<S239>/Logical Operator1'
     *  Logic: '<S239>/Logical Operator2'
     *  RelationalOperator: '<S239>/Relational Operator1'
     */
    if ((rtb_UnitDelay3_f != ((uint8)0U)) && (rtb_flg_out_l || rtb_flg_out_g)) {
      /* Switch: '<S239>/Switch1' */
      rtb_Switch1_o = rtb_UnitDelay3_f;
    } else {
      /* Switch: '<S239>/Switch1' incorporates:
       *  UnitDelay: '<S239>/Unit Delay4'
       */
      rtb_Switch1_o = swc_RMLK_ARID_DEF.UnitDelay4_DSTATE_j;
    }

    /* End of Switch: '<S239>/Switch1' */

    /* Switch: '<S226>/Switch8' incorporates:
     *  Constant: '<S240>/Constant'
     *  Logic: '<S226>/Logical Operator4'
     *  Logic: '<S239>/Logical Operator3'
     *  Logic: '<S239>/Logical Operator5'
     *  RelationalOperator: '<S240>/Compare'
     *  RelationalOperator: '<S241>/FixPt Relational Operator'
     *  RelationalOperator: '<S242>/FixPt Relational Operator'
     *  UnitDelay: '<S241>/Delay Input1'
     *  UnitDelay: '<S242>/Delay Input1'
     *
     * Block description for '<S241>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S242>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (rtb_RelationalOperator_j || ((((sint32)rlcd_b_ignOn > (sint32)
           swc_RMLK_ARID_DEF.DelayInput1_DSTATE_hu) || ((sint32)rlcd_b_obcWakeUp
           > (sint32)swc_RMLK_ARID_DEF.DelayInput1_DSTATE_b1)) && (rtb_Switch1_o
          != ((uint8)0U)))) {
      /* Switch: '<S226>/Switch9' */
      if (rtb_RelationalOperator_j) {
        /* Switch: '<S226>/Switch8' */
        rtb_Switch8_ib = rlcd_num_ExeStsUpdate1SaveResult;
      } else {
        /* Switch: '<S226>/Switch8' */
        rtb_Switch8_ib = rtb_UnitDelay3_f;
      }

      /* End of Switch: '<S226>/Switch9' */
    } else {
      /* Switch: '<S226>/Switch8' incorporates:
       *  UnitDelay: '<S226>/Unit Delay2'
       */
      rtb_Switch8_ib = swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_g;
    }

    /* End of Switch: '<S226>/Switch8' */

    /* Logic: '<S184>/Logical Operator3' */
    rtb_RelationalOperator_j = (rlcd_b_ignOn || rlcd_b_obcWakeUp);

    /* Chart: '<S184>/ExeSts' incorporates:
     *  Logic: '<S184>/Logical Operator3'
     */
    if (swc_RMLK_ARID_DEF.is_active_c16_swc_RMLK == 0U) {
      swc_RMLK_ARID_DEF.is_active_c16_swc_RMLK = 1U;
      swc_RMLK_ARID_DEF.BuffSts = 7U;
      swc_RMLK_ARID_DEF.LockCmd = 0U;
      swc_RMLK_ARID_DEF.UnlockCmd = 0U;
      swc_RMLK_ARID_DEF.UpdtBuff = true;
      swc_RMLK_ARID_DEF.ExcuteUnlockCmd = false;
      swc_RMLK_ARID_DEF.ExcuteLockCmd = false;
      swc_RMLK_ARID_DEF.is_c16_swc_RMLK = swc_RMLK_IN_Defualt;
      rlcd_st_LockVehExecutedStsOut = 0U;
      rlcd_st_LockVehExecutedSts = swc_RMLK_ARID_DEF.BuffSts;
      swc_RMLK_ARID_DEF.timer = 0.01F;
    } else {
      boolean guard2 = false;
      boolean guard3 = false;
      boolean guard4 = false;
      boolean guard5 = false;
      boolean guard6 = false;
      guard1 = false;
      guard2 = false;
      guard3 = false;
      guard4 = false;
      guard5 = false;
      guard6 = false;
      switch (swc_RMLK_ARID_DEF.is_c16_swc_RMLK) {
       case swc_RMLK_IN_Defualt:
        rlcd_st_LockVehExecutedStsOut = 0U;
        if (rtb_LogicalOperator1_o0 && rlcd_b_ChgLockExcReqCur &&
            rtb_RelationalOperator_j) {
          rlcd_num_ExeStsUpdate1 = 2U;
          swc_RMLK_ARID_DEF.UpdtBuff = true;
          guard1 = true;
        } else {
          rtb_LogicalOperator_oe = !rtb_Compare_oc;
          if (rtb_LogicalOperator1_o0 && rtb_LogicalOperator_oe &&
              rtb_RelationalOperator_j) {
            rlcd_num_ExeStsUpdate = 1U;
            rlcd_num_ExeStsUpdate1 = 2U;
            swc_RMLK_ARID_DEF.UpdtBuff = true;
            guard1 = true;
          } else if (rtb_LogicalOperator2_c && rtb_Compare_oc &&
                     rtb_RelationalOperator_j) {
            rlcd_num_ExeStsUpdate1 = 1U;
            rlcd_num_ExeStsUpdate = 2U;
            swc_RMLK_ARID_DEF.UpdtBuff = true;
            swc_RMLK_ARID_DEF.is_c16_swc_RMLK = swc_RMLK_IN_UnlockReq;
            rlcd_st_LockVehExecutedStsOut = 21U;
            swc_RMLK_ARID_DEF.BuffSts = 4U;
            swc_RMLK_ARID_DEF.UnlockCmd = 1U;
            swc_RMLK_ARID_DEF.LockCmd = 0U;
          } else if ((rtb_Compare_oc && (rtb_UnitDelay3_hg == ((uint8)1U)) &&
                      (swc_RMLK_ARID_DEF.UnlockCmd == 0) &&
                      swc_RMLK_ARID_DEF.UpdtBuff && rtb_RelationalOperator_j) ||
                     (swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_o &&
                      swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_b &&
                      swc_RMLK_ARID_DEF.UnitDelay_DSTATE_o5)) {
            rlcd_num_ExeStsUpdate = 2U;
            swc_RMLK_ARID_DEF.is_c16_swc_RMLK = swc_RMLK_IN_ExcuteLock;
            rlcd_st_LockVehExecutedStsOut = 12U;
            rlcd_st_LockVehExecutedSts = 1U;
            swc_RMLK_ARID_DEF.timer += 0.01F;
          } else if (rtb_LogicalOperator_oe && (rtb_Switch8_ib == ((uint8)1U)) &&
                     swc_RMLK_ARID_DEF.UpdtBuff && (swc_RMLK_ARID_DEF.LockCmd ==
                      0) && rtb_RelationalOperator_j) {
            rlcd_num_ExeStsUpdate1 = 2U;
            swc_RMLK_ARID_DEF.is_c16_swc_RMLK = swc_RMLK_IN_ExcuteUnlock;
            rlcd_st_LockVehExecutedStsOut = 22U;
            rlcd_st_LockVehExecutedSts = 4U;
            swc_RMLK_ARID_DEF.timer += 0.01F;
          } else if ((swc_RMLK_ARID_DEF.ExcuteLockCmd ||
                      (rlcd_b_ChgLockExcReqCur && (swc_RMLK_ARID_DEF.LockCmd !=
                        0))) && rtb_Compare_oc && rtb_RelationalOperator_j) {
            rlcd_num_ExeStsUpdate = 2U;
            swc_RMLK_ARID_DEF.is_c16_swc_RMLK = swc_RMLK_IN_HoldLockSts;
            rlcd_st_LockVehExecutedStsOut = 13U;
            rlcd_st_LockVehExecutedSts = 2U;
            swc_RMLK_ARID_DEF.timer += 0.01F;
          } else if (swc_RMLK_ARID_DEF.ExcuteUnlockCmd && rtb_LogicalOperator_oe
                     && rtb_RelationalOperator_j) {
            rlcd_num_ExeStsUpdate1 = 2U;
            swc_RMLK_ARID_DEF.is_c16_swc_RMLK = swc_RMLK_IN_HoldUnlockSts;
            rlcd_st_LockVehExecutedStsOut = 23U;
            rlcd_st_LockVehExecutedSts = 5U;
            swc_RMLK_ARID_DEF.timer += 0.01F;
          } else if ((((sint32)rtb_Compare_hjh > (sint32)
                       swc_RMLK_ARID_DEF.DelayInput1_DSTATE_p) || ((sint32)
                       rtb_Compare_pv > (sint32)
                       swc_RMLK_ARID_DEF.DelayInput1_DSTATE_o)) &&
                     rtb_LogicalOperator_oe && swc_RMLK_ARID_DEF.UpdtBuff &&
                     (swc_RMLK_ARID_DEF.LockCmd != 0) &&
                     rtb_RelationalOperator_j) {
            rlcd_num_ExeStsUpdate = 2U;
            swc_RMLK_ARID_DEF.ExcuteUnlockCmd = false;
            swc_RMLK_ARID_DEF.ExcuteLockCmd = false;
            swc_RMLK_ARID_DEF.LockCmd = 0U;
            guard2 = true;
          } else if (rtb_LogicalOperator1_o0 && rtb_Compare_oc &&
                     swc_RMLK_ARID_DEF.UpdtBuff && (swc_RMLK_ARID_DEF.UnlockCmd
                      != 0) && rtb_RelationalOperator_j) {
            rlcd_num_ExeStsUpdate1 = 2U;
            swc_RMLK_ARID_DEF.is_c16_swc_RMLK = swc_RMLK_IN_ExcuteUnLockFailed;
            rlcd_st_LockVehExecutedStsOut = 24U;
            rlcd_st_LockVehExecutedSts = 3U;
            swc_RMLK_ARID_DEF.timer += 0.01F;
            swc_RMLK_ARID_DEF.UnlockCmd = 0U;
            swc_RMLK_ARID_DEF.LockCmd = 1U;
            swc_RMLK_ARID_DEF.ExcuteUnlockCmd = false;
            swc_RMLK_ARID_DEF.ExcuteLockCmd = true;
          } else if (rtb_LogicalOperator2_c && rtb_LogicalOperator_oe &&
                     swc_RMLK_ARID_DEF.UpdtBuff && (swc_RMLK_ARID_DEF.LockCmd !=
                      0) && rtb_RelationalOperator_j) {
            rlcd_num_ExeStsUpdate = 2U;
            swc_RMLK_ARID_DEF.ExcuteUnlockCmd = true;
            swc_RMLK_ARID_DEF.ExcuteLockCmd = false;
            guard2 = true;
          }
        }
        break;

       case swc_RMLK_IN_ExcuteLock:
        rlcd_st_LockVehExecutedStsOut = 12U;
        if (!rtb_RelationalOperator_j) {
          swc_RMLK_ARID_DEF.BuffSts = 7U;
          swc_RMLK_ARID_DEF.is_c16_swc_RMLK = swc_RMLK_IN_Defualt;
          rlcd_st_LockVehExecutedStsOut = 0U;
          rlcd_st_LockVehExecutedSts = swc_RMLK_ARID_DEF.BuffSts;
          swc_RMLK_ARID_DEF.timer = 0.01F;
        } else if (swc_RMLK_ARID_DEF.timer > 0.02F) {
          swc_RMLK_ARID_DEF.timer = 0.01F;
          swc_RMLK_ARID_DEF.is_c16_swc_RMLK = swc_RMLK_IN_HoldLockSts;
          rlcd_st_LockVehExecutedStsOut = 13U;
          rlcd_st_LockVehExecutedSts = 2U;
          swc_RMLK_ARID_DEF.timer += 0.01F;
        } else {
          swc_RMLK_ARID_DEF.timer += 0.01F;
        }
        break;

       case swc_RMLK_IN_ExcuteLockFailed:
        rlcd_st_LockVehExecutedStsOut = 14U;
        if (!rtb_RelationalOperator_j) {
          swc_RMLK_ARID_DEF.BuffSts = 7U;
          guard3 = true;
        } else if ((swc_RMLK_ARID_DEF.timer > 2.0F) &&
                   (!swc_RMLK_ARID_DEF.ExcuteUnlockCmd)) {
          swc_RMLK_ARID_DEF.UpdtBuff = false;
          swc_RMLK_ARID_DEF.BuffSts = 7U;
          guard3 = true;
        } else if ((swc_RMLK_ARID_DEF.timer > 2.0F) &&
                   swc_RMLK_ARID_DEF.ExcuteUnlockCmd) {
          swc_RMLK_ARID_DEF.UpdtBuff = false;
          swc_RMLK_ARID_DEF.BuffSts = 0U;
          guard3 = true;
        } else {
          swc_RMLK_ARID_DEF.timer += 0.01F;
        }
        break;

       case swc_RMLK_IN_ExcuteUnLockFailed:
        rlcd_st_LockVehExecutedStsOut = 24U;
        if (!rtb_RelationalOperator_j) {
          swc_RMLK_ARID_DEF.BuffSts = 7U;
          guard4 = true;
        } else if (swc_RMLK_ARID_DEF.timer > 2.0F) {
          swc_RMLK_ARID_DEF.UpdtBuff = false;
          guard4 = true;
        } else {
          swc_RMLK_ARID_DEF.timer += 0.01F;
        }
        break;

       case swc_RMLK_IN_ExcuteUnlock:
        rlcd_st_LockVehExecutedStsOut = 22U;
        if (!rtb_RelationalOperator_j) {
          swc_RMLK_ARID_DEF.BuffSts = 7U;
          swc_RMLK_ARID_DEF.is_c16_swc_RMLK = swc_RMLK_IN_Defualt;
          rlcd_st_LockVehExecutedStsOut = 0U;
          rlcd_st_LockVehExecutedSts = swc_RMLK_ARID_DEF.BuffSts;
          swc_RMLK_ARID_DEF.timer = 0.01F;
        } else if (swc_RMLK_ARID_DEF.timer > 0.02F) {
          swc_RMLK_ARID_DEF.timer = 0.01F;
          swc_RMLK_ARID_DEF.is_c16_swc_RMLK = swc_RMLK_IN_HoldUnlockSts;
          rlcd_st_LockVehExecutedStsOut = 23U;
          rlcd_st_LockVehExecutedSts = 5U;
          swc_RMLK_ARID_DEF.timer += 0.01F;
        } else {
          swc_RMLK_ARID_DEF.timer += 0.01F;
        }
        break;

       case swc_RMLK_IN_HoldLockSts:
        rlcd_st_LockVehExecutedStsOut = 13U;
        if (!rtb_RelationalOperator_j) {
          guard5 = true;
        } else if (swc_RMLK_ARID_DEF.timer > 2.0F) {
          swc_RMLK_ARID_DEF.UpdtBuff = false;
          swc_RMLK_ARID_DEF.LockCmd = 0U;
          swc_RMLK_ARID_DEF.ExcuteLockCmd = false;
          swc_RMLK_ARID_DEF.UnlockCmd = 0U;
          guard5 = true;
        } else {
          swc_RMLK_ARID_DEF.timer += 0.01F;
        }
        break;

       case swc_RMLK_IN_HoldUnlockSts:
        rlcd_st_LockVehExecutedStsOut = 23U;
        if (!rtb_RelationalOperator_j) {
          guard6 = true;
        } else if (swc_RMLK_ARID_DEF.timer > 2.0F) {
          swc_RMLK_ARID_DEF.UpdtBuff = false;
          swc_RMLK_ARID_DEF.ExcuteUnlockCmd = false;
          swc_RMLK_ARID_DEF.LockCmd = 0U;
          guard6 = true;
        } else {
          swc_RMLK_ARID_DEF.timer += 0.01F;
        }
        break;

       case swc_RMLK_IN_LockReq:
        swc_RMLK_ARID_DEF.is_c16_swc_RMLK = swc_RMLK_IN_Defualt;
        rlcd_st_LockVehExecutedStsOut = 0U;
        rlcd_st_LockVehExecutedSts = swc_RMLK_ARID_DEF.BuffSts;
        swc_RMLK_ARID_DEF.timer = 0.01F;
        break;

       default:
        /* case IN_UnlockReq: */
        swc_RMLK_ARID_DEF.is_c16_swc_RMLK = swc_RMLK_IN_Defualt;
        rlcd_st_LockVehExecutedStsOut = 0U;
        rlcd_st_LockVehExecutedSts = swc_RMLK_ARID_DEF.BuffSts;
        swc_RMLK_ARID_DEF.timer = 0.01F;
        break;
      }

      if (guard6) {
        swc_RMLK_ARID_DEF.BuffSts = 7U;
        swc_RMLK_ARID_DEF.is_c16_swc_RMLK = swc_RMLK_IN_Defualt;
        rlcd_st_LockVehExecutedStsOut = 0U;
        rlcd_st_LockVehExecutedSts = swc_RMLK_ARID_DEF.BuffSts;
        swc_RMLK_ARID_DEF.timer = 0.01F;
      }

      if (guard5) {
        swc_RMLK_ARID_DEF.BuffSts = 7U;
        swc_RMLK_ARID_DEF.is_c16_swc_RMLK = swc_RMLK_IN_Defualt;
        rlcd_st_LockVehExecutedStsOut = 0U;
        rlcd_st_LockVehExecutedSts = swc_RMLK_ARID_DEF.BuffSts;
        swc_RMLK_ARID_DEF.timer = 0.01F;
      }

      if (guard4) {
        swc_RMLK_ARID_DEF.is_c16_swc_RMLK = swc_RMLK_IN_Defualt;
        rlcd_st_LockVehExecutedStsOut = 0U;
        rlcd_st_LockVehExecutedSts = swc_RMLK_ARID_DEF.BuffSts;
        swc_RMLK_ARID_DEF.timer = 0.01F;
      }

      if (guard3) {
        swc_RMLK_ARID_DEF.is_c16_swc_RMLK = swc_RMLK_IN_Defualt;
        rlcd_st_LockVehExecutedStsOut = 0U;
        rlcd_st_LockVehExecutedSts = swc_RMLK_ARID_DEF.BuffSts;
        swc_RMLK_ARID_DEF.timer = 0.01F;
      }

      if (guard2) {
        swc_RMLK_ARID_DEF.is_c16_swc_RMLK = swc_RMLK_IN_ExcuteLockFailed;
        rlcd_st_LockVehExecutedStsOut = 14U;
        rlcd_st_LockVehExecutedSts = 0U;
        swc_RMLK_ARID_DEF.timer += 0.01F;
      }

      if (guard1) {
        swc_RMLK_ARID_DEF.is_c16_swc_RMLK = swc_RMLK_IN_LockReq;
        rlcd_st_LockVehExecutedStsOut = 11U;
        swc_RMLK_ARID_DEF.BuffSts = 1U;
        swc_RMLK_ARID_DEF.UnlockCmd = 0U;
        swc_RMLK_ARID_DEF.LockCmd = 1U;
      }
    }

    /* End of Chart: '<S184>/ExeSts' */

    /* DataTypeConversion: '<S4>/Data Type Conversion8' */
    rtb_UnitDelay3_f = rlcd_num_ExeStsUpdate;

    /* DataTypeConversion: '<S4>/Data Type Conversion9' */
    rlcd_num_ExeStsUpdate1_j = rlcd_num_ExeStsUpdate1;

    /* Outputs for Atomic SubSystem: '<S4>/Falling_Edge1' */
    swc_RMLK_Falling_Edge1(rlcd_b_ignOn, &rtb_flg_out_eo,
      &swc_RMLK_ARID_DEF.ARID_DEF_Falling_Edge1_c);

    /* End of Outputs for SubSystem: '<S4>/Falling_Edge1' */

    /* UnitDelay: '<S18>/Unit Delay2' */
    rtb_UnitDelay2_j = swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_l4;

    /* Logic: '<S186>/Logical Operator1' incorporates:
     *  Constant: '<S257>/Constant'
     *  RelationalOperator: '<S257>/Compare'
     */
    rtb_Compare_oc = (rlcd_b_fuleUpAntiLockExcReq || rlcd_b_ChgAntiLockReq ||
                      (rtb_CCaller3_a == ((uint8)1U)));

    /* RelationalOperator: '<S255>/Compare' incorporates:
     *  Constant: '<S255>/Constant'
     */
    rtb_LogicalOperator1_o0 = (rtb_CCaller4_a == ((uint8)1U));

    /* Logic: '<S186>/Logical Operator4' incorporates:
     *  Constant: '<S256>/Constant'
     *  RelationalOperator: '<S256>/Compare'
     */
    rtb_LogicalOperator2_c = ((rtb_CCaller5 == ((uint8)1U)) ||
      rlcd_b_ChgLockExcReqCur);

    /* Chart: '<S186>/Chart' */
    if (swc_RMLK_ARID_DEF.is_active_c17_swc_RMLK == 0U) {
      swc_RMLK_ARID_DEF.is_active_c17_swc_RMLK = 1U;
      swc_RMLK_ARID_DEF.is_c17_swc_RMLK = swc_RMLK_IN_InitLockTyp;
      rtb_LockTyp = 3U;
    } else {
      switch (swc_RMLK_ARID_DEF.is_c17_swc_RMLK) {
       case swc_RMLK_IN_AntiLockTyp:
        rtb_LockTyp = 3U;
        if (!rtb_Compare_oc) {
          swc_RMLK_ARID_DEF.is_c17_swc_RMLK = swc_RMLK_IN_InitLockTyp;
        }
        break;

       case swc_RMLK_IN_ChgLockTyp:
        rtb_LockTyp = 0U;
        if (rtb_Compare_oc) {
          swc_RMLK_ARID_DEF.is_c17_swc_RMLK = swc_RMLK_IN_AntiLockTyp;
          rtb_LockTyp = 3U;
        } else if (!rtb_LogicalOperator2_c) {
          swc_RMLK_ARID_DEF.is_c17_swc_RMLK = swc_RMLK_IN_InitLockTyp;
          rtb_LockTyp = 3U;
        }
        break;

       case swc_RMLK_IN_InitLockTyp:
        rtb_LockTyp = 3U;
        if (rtb_Compare_oc) {
          swc_RMLK_ARID_DEF.is_c17_swc_RMLK = swc_RMLK_IN_AntiLockTyp;
        } else if (rtb_LogicalOperator2_c) {
          swc_RMLK_ARID_DEF.is_c17_swc_RMLK = swc_RMLK_IN_ChgLockTyp;
          rtb_LockTyp = 0U;
        } else if (rtb_LogicalOperator1_o0) {
          swc_RMLK_ARID_DEF.is_c17_swc_RMLK = swc_RMLK_IN_NormlLockTyp;
          rtb_LockTyp = 0U;
        }
        break;

       default:
        /* case IN_NormlLockTyp: */
        rtb_LockTyp = 0U;
        if (rtb_Compare_oc) {
          swc_RMLK_ARID_DEF.is_c17_swc_RMLK = swc_RMLK_IN_AntiLockTyp;
          rtb_LockTyp = 3U;
        } else if (!rtb_LogicalOperator1_o0) {
          swc_RMLK_ARID_DEF.is_c17_swc_RMLK = swc_RMLK_IN_InitLockTyp;
          rtb_LockTyp = 3U;
        }
        break;
      }
    }

    /* End of Chart: '<S186>/Chart' */

    /* Switch: '<S19>/Switch17' incorporates:
     *  Constant: '<S175>/Constant'
     *  RelationalOperator: '<S175>/Compare'
     */
    if (rtb_CCaller10 == ((uint8)5U)) {
      /* Switch: '<S19>/Switch17' incorporates:
       *  Constant: '<S19>/Constant20'
       */
      rlcd_num_rmtLkSpdLimCfg = ((uint8)0U);
    } else {
      /* Switch: '<S19>/Switch17' */
      rlcd_num_rmtLkSpdLimCfg = rtb_CCaller10;
    }

    /* End of Switch: '<S19>/Switch17' */

    /* Switch: '<S176>/Switch4' incorporates:
     *  Logic: '<S176>/Logical Operator1'
     *  RelationalOperator: '<S177>/FixPt Relational Operator'
     *  RelationalOperator: '<S178>/FixPt Relational Operator'
     *  UnitDelay: '<S177>/Delay Input1'
     *  UnitDelay: '<S178>/Delay Input1'
     *
     * Block description for '<S177>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S178>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((sint32)rlcd_b_ignOn > (sint32)swc_RMLK_ARID_DEF.DelayInput1_DSTATE_j) ||
        ((sint32)rlcd_b_obcWakeUp > (sint32)
         swc_RMLK_ARID_DEF.DelayInput1_DSTATE_g)) {
      /* Switch: '<S176>/Switch4' */
      rlcd_num_rmtLkSpdLimCfg3 = rlcd_num_rmtLkSpdLimCfg;
    } else {
      /* Switch: '<S176>/Switch4' incorporates:
       *  UnitDelay: '<S19>/Unit Delay1'
       */
      rlcd_num_rmtLkSpdLimCfg3 = swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_c;
    }

    /* End of Switch: '<S176>/Switch4' */

    /* Switch: '<S19>/Switch1' */
    if (rlcd_b_ChgLockExcReqCur) {
      /* Switch: '<S19>/Switch2' incorporates:
       *  Constant: '<S174>/Constant'
       *  RelationalOperator: '<S174>/Compare'
       */
      if (rtb_CCaller10 == ((uint8)5U)) {
        /* Switch: '<S19>/Switch1' incorporates:
         *  Constant: '<S19>/Constant1'
         */
        rlcd_num_rmtLkSpdLimCfgInit = ((uint8)0U);
      } else {
        /* Switch: '<S19>/Switch1' */
        rlcd_num_rmtLkSpdLimCfgInit = rtb_CCaller10;
      }

      /* End of Switch: '<S19>/Switch2' */
    } else {
      /* Switch: '<S19>/Switch1' */
      rlcd_num_rmtLkSpdLimCfgInit = rlcd_num_rmtLkSpdLimCfg3;
    }

    /* End of Switch: '<S19>/Switch1' */

    /* MultiPortSwitch: '<S19>/Index Vector1' incorporates:
     *  Saturate: '<S19>/Saturation1'
     */
    if (rlcd_num_rmtLkSpdLimCfgInit <= ((uint8)3U)) {
      Switch9 = rlcd_num_rmtLkSpdLimCfgInit;
    } else {
      Switch9 = ((uint8)3U);
    }

    /* MultiPortSwitch: '<S19>/Index Vector1' incorporates:
     *  Constant: '<S19>/TV4V2_Status5'
     *  Saturate: '<S19>/Saturation1'
     */
    rlcd_v_rmtCtrlFctSpdLimCfg_kph = rlcv_v_vehSpdLimCfg_kph[Switch9];

    /* Switch: '<S20>/Switch3' incorporates:
     *  Constant: '<S20>/Constant2'
     *  RelationalOperator: '<S20>/Relational Operator1'
     */
    if (rlcd_v_vehSpd_kph < rlcc_v_vehSpdUpdLimCfg_kph) {
      /* Switch: '<S20>/Switch3' */
      rtb_t_delay_off = rlcd_v_rmtCtrlFctSpdLimCfg_kph;
    } else {
      /* Switch: '<S20>/Switch3' incorporates:
       *  UnitDelay: '<S20>/Unit Delay1'
       */
      rtb_t_delay_off = swc_RMLK_ARID_DEF.UnitDelay1_DSTATE;
    }

    /* End of Switch: '<S20>/Switch3' */

    /* Switch: '<S20>/Switch1' incorporates:
     *  Logic: '<S20>/Logical Operator1'
     *  Logic: '<S20>/Logical Operator4'
     *  Switch: '<S20>/Switch2'
     */
    if (rlcd_b_rmtCtrlAntiDismtLock || rlcd_b_ChgAntiLockReq ||
        rlcd_b_fuleUpAntiLockExcReq) {
      /* Switch: '<S20>/Switch1' incorporates:
       *  Constant: '<S20>/Constant6'
       */
      Switch1 = rlcc_v_antiDismantleSpdLim_kph;
    } else if (rlcd_b_ChgLockExcReqCur || rlcd_b_rmtCtrlNormLock ||
               rlcd_b_rmtCtrlChrgLock) {
      /* Switch: '<S20>/Switch2' incorporates:
       *  Switch: '<S20>/Switch1'
       */
      Switch1 = rtb_t_delay_off;
    } else {
      /* Switch: '<S20>/Switch1' incorporates:
       *  Constant: '<S20>/Constant4'
       *  Switch: '<S20>/Switch2'
       */
      Switch1 = rlcc_v_VehSpdMax_kph;
    }

    /* End of Switch: '<S20>/Switch1' */

    /* RelationalOperator: '<S20>/Relational Operator2' incorporates:
     *  Constant: '<S20>/Constant1'
     */
    rtb_LogicalOperator1_o0 = (Switch1 <= rlcc_v_rmtCtrlPedlOff_kph);

    /* RelationalOperator: '<S20>/Relational Operator3' incorporates:
     *  Constant: '<S20>/Constant5'
     */
    rtb_LogicalOperator2_c = (Switch1 < rlcc_v_VehSpdMax_kph);

    /* RelationalOperator: '<S20>/Relational Operator5' incorporates:
     *  Constant: '<S20>/Constant7'
     */
    rtb_RelationalOperator_j = (Switch1 <= rlcc_v_rmtCtrlTqOff_kph);

    /* Switch: '<S181>/Switch9' incorporates:
     *  Constant: '<S196>/Constant'
     *  Constant: '<S197>/Constant'
     *  Logic: '<S181>/Logical Operator1'
     *  RelationalOperator: '<S196>/Compare'
     *  RelationalOperator: '<S197>/Compare'
     *  RelationalOperator: '<S198>/FixPt Relational Operator'
     *  RelationalOperator: '<S199>/FixPt Relational Operator'
     *  Switch: '<S181>/Switch10'
     *  Switch: '<S181>/Switch11'
     *  UnitDelay: '<S198>/Delay Input1'
     *  UnitDelay: '<S199>/Delay Input1'
     *
     * Block description for '<S198>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S199>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((sint32)rlcd_b_ignOn > (sint32)swc_RMLK_ARID_DEF.DelayInput1_DSTATE_o2)
        || ((sint32)rlcd_b_obcWakeUp > (sint32)
            swc_RMLK_ARID_DEF.DelayInput1_DSTATE_n5)) {
      /* Switch: '<S181>/Switch9' incorporates:
       *  Constant: '<S195>/Constant'
       *  RelationalOperator: '<S195>/Compare'
       */
      Switch9 = (uint8)(rtb_Switch8_i == ((uint8)1U));
    } else if (rlcd_num_FunAnti_DismantleActiveReq == ((uint8)1U)) {
      /* Switch: '<S181>/Switch10' incorporates:
       *  Constant: '<S181>/Constant6'
       *  Switch: '<S181>/Switch9'
       */
      Switch9 = ((uint8)1U);
    } else if (rlcd_num_FunAnti_DismantleActiveReq == ((uint8)2U)) {
      /* Switch: '<S181>/Switch11' incorporates:
       *  Constant: '<S181>/Constant13'
       *  Switch: '<S181>/Switch10'
       *  Switch: '<S181>/Switch9'
       */
      Switch9 = ((uint8)0U);
    } else {
      /* Switch: '<S181>/Switch9' incorporates:
       *  Switch: '<S181>/Switch10'
       *  UnitDelay: '<S181>/Unit Delay1'
       */
      Switch9 = swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_n2;
    }

    /* End of Switch: '<S181>/Switch9' */

    /* Logic: '<S185>/Logical Operator5' incorporates:
     *  Constant: '<S251>/Constant'
     *  Constant: '<S252>/Constant'
     *  Constant: '<S253>/Constant'
     *  RelationalOperator: '<S251>/Compare'
     *  RelationalOperator: '<S252>/Compare'
     *  RelationalOperator: '<S253>/Compare'
     */
    rlcd_b_LockVehResults = ((rtb_CCaller4_a == ((uint8)1U)) || (rtb_CCaller5 ==
      ((uint8)1U)) || (rtb_CCaller3_a == ((uint8)1U)) || rlcd_b_ChgLockExcReqCur
      || rlcd_b_ChgAntiLockReq || rlcd_b_fuleUpAntiLockExcReq);

    /* Switch: '<S182>/Switch1' incorporates:
     *  Constant: '<S201>/Constant'
     *  Constant: '<S202>/Constant'
     *  Logic: '<S182>/Logical Operator1'
     *  RelationalOperator: '<S201>/Compare'
     *  RelationalOperator: '<S202>/Compare'
     *  RelationalOperator: '<S203>/FixPt Relational Operator'
     *  RelationalOperator: '<S204>/FixPt Relational Operator'
     *  Switch: '<S182>/Switch4'
     *  Switch: '<S182>/Switch7'
     *  UnitDelay: '<S203>/Delay Input1'
     *  UnitDelay: '<S204>/Delay Input1'
     *
     * Block description for '<S203>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S204>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((sint32)rlcd_b_ignOn > (sint32)swc_RMLK_ARID_DEF.DelayInput1_DSTATE_bx)
        || ((sint32)rlcd_b_obcWakeUp > (sint32)
            swc_RMLK_ARID_DEF.DelayInput1_DSTATE_eb)) {
      /* Switch: '<S182>/Switch1' incorporates:
       *  Constant: '<S200>/Constant'
       *  RelationalOperator: '<S200>/Compare'
       */
      Switch1_h = (uint8)(rtb_CCaller8 == ((uint8)1U));
    } else if (rlcd_num_FunLockVehActiveReq == ((uint8)1U)) {
      /* Switch: '<S182>/Switch4' incorporates:
       *  Constant: '<S182>/Constant1'
       *  Switch: '<S182>/Switch1'
       */
      Switch1_h = ((uint8)1U);
    } else if (rlcd_num_FunLockVehActiveReq == ((uint8)2U)) {
      /* Switch: '<S182>/Switch7' incorporates:
       *  Constant: '<S182>/Constant2'
       *  Switch: '<S182>/Switch1'
       *  Switch: '<S182>/Switch4'
       */
      Switch1_h = ((uint8)0U);
    } else {
      /* Switch: '<S182>/Switch1' incorporates:
       *  Switch: '<S182>/Switch4'
       *  UnitDelay: '<S182>/Unit Delay'
       */
      Switch1_h = swc_RMLK_ARID_DEF.UnitDelay_DSTATE_f;
    }

    /* End of Switch: '<S182>/Switch1' */

    /* UnitDelay: '<S180>/Unit Delay' */
    rlcd_st_FuelingStatus = swc_RMLK_ARID_DEF.UnitDelay_DSTATE_m;

    /* RelationalOperator: '<S192>/Compare' incorporates:
     *  Constant: '<S192>/Constant'
     */
    rtb_Compare_oc = (rlcd_st_FuelingStatus == ((uint8)1U));

    /* Logic: '<S180>/Logical Operator' incorporates:
     *  Constant: '<S188>/Constant'
     *  Constant: '<S189>/Constant'
     *  RelationalOperator: '<S188>/Compare'
     *  RelationalOperator: '<S189>/Compare'
     */
    rtb_LogicalOperator_oe = ((Switch9 == ((uint8)1U)) && (rlcd_b_LockVehResults
      != true));

    /* Logic: '<S180>/Logical Operator4' incorporates:
     *  Constant: '<S187>/Constant'
     *  Constant: '<S191>/Constant'
     *  DataTypeConversion: '<S184>/Data Type Conversion1'
     *  RelationalOperator: '<S187>/Compare'
     *  RelationalOperator: '<S191>/Compare'
     */
    rtb_LogicalOperator4_l = ((rlcd_st_LockVehExecutedSts == ((uint8)1U)) &&
      (Switch1_h == ((uint8)1U)));

    /* Logic: '<S180>/Logical Operator1' incorporates:
     *  Constant: '<S190>/Constant'
     *  Logic: '<S180>/Logical Operator2'
     *  RelationalOperator: '<S190>/Compare'
     */
    rlcd_b_fuelUpCalEna = (rlcd_b_ignOn && (rlcd_v_vehSpd_kph <= 3.0F) &&
      (rtb_LogicalOperator_oe || rtb_LogicalOperator4_l));

    /* Logic: '<S180>/Logical Operator3' */
    rlcd_b_fuelUpNormalLockReq = (rtb_Compare_oc && rtb_LogicalOperator4_l);

    /* Logic: '<S180>/Logical Operator6' */
    rlcd_b_fuelUpAntiLockReq = (rtb_Compare_oc && rtb_LogicalOperator_oe);

    /* Chart: '<S180>/fuelUpMode' incorporates:
     *  Constant: '<S180>/Constant'
     *  Constant: '<S180>/Constant1'
     *  Constant: '<S180>/Constant2'
     *  Constant: '<S180>/Constant3'
     *  Constant: '<S180>/Constant4'
     *  Constant: '<S3>/Constant'
     */
    if (swc_RMLK_ARID_DEF.is_active_c2_swc_RMLK == 0U) {
      swc_RMLK_ARID_DEF.is_active_c2_swc_RMLK = 1U;
      swc_RMLK_ARID_DEF.is_c2_swc_RMLK = swc_RMLK_IN_Defualt;
      swc_RMLK_ARID_DEF.timer_f = 0.0F;
      swc_RMLK_ARID_DEF.out = 0U;
      rlcd_v_fuelA1Pos = 1000.0F;
    } else {
      switch (swc_RMLK_ARID_DEF.is_c2_swc_RMLK) {
       case swc_RMLK_IN_Defualt:
        swc_RMLK_ARID_DEF.out = 0U;
        if (rlcd_b_fuelUpCalEna) {
          swc_RMLK_ARID_DEF.is_c2_swc_RMLK = swc_RMLK_IN_FuelUpMet;
          swc_RMLK_ARID_DEF.is_FuelUpMet = swc_RMLK_IN_delayA;
          swc_RMLK_ARID_DEF.timer_f = 0.0F;
        }
        break;

       case swc_RMLK_IN_FuelUpMet:
        {
          if (!rlcd_b_fuelUpCalEna) {
            swc_RMLK_ARID_DEF.is_FuelUpMet = swc_RMLK_IN_NO_ACTIVE_CHILD;
            swc_RMLK_ARID_DEF.is_c2_swc_RMLK = swc_RMLK_IN_Defualt;
            swc_RMLK_ARID_DEF.timer_f = 0.0F;
            swc_RMLK_ARID_DEF.out = 0U;
            rlcd_v_fuelA1Pos = 1000.0F;
          } else {
            switch (swc_RMLK_ARID_DEF.is_FuelUpMet) {
             case swc_RMLK_IN_delayA:
              /*  delay 6s */
              if (swc_RMLK_ARID_DEF.timer_f >= rlcc_tm_fuleUpA1Dly_s) {
                swc_RMLK_ARID_DEF.is_FuelUpMet = swc_RMLK_IN_getA1;
                swc_RMLK_ARID_DEF.timer_f = 0.0F;
                rlcd_v_fuelA1Pos = 100.0F;
              } else {
                swc_RMLK_ARID_DEF.timer_f = (float32)(swc_RMLK_ARID_DEF.timer_f
                  + 0.01);
              }
              break;

             case swc_RMLK_IN_getA1:
              /*  delay 2s */
              if (swc_RMLK_ARID_DEF.timer_f >= rlcc_tm_fuleUpA2Dly_s) {
                swc_RMLK_ARID_DEF.is_FuelUpMet = swc_RMLK_IN_getA2;
                swc_RMLK_ARID_DEF.timer_f = 0.0F;
                rlcd_v_fuelA2Pos = 100.0F;
              } else {
                swc_RMLK_ARID_DEF.timer_f = (float32)(swc_RMLK_ARID_DEF.timer_f
                  + 0.01);
              }
              break;

             default:
              {
                float32 c;

                /* case IN_getA2: */
                c = fabsf(rlcd_v_fuelA1Pos - rlcd_v_fuelA2Pos);
                if (c <= rlcc_v_fuleLv1) {
                  swc_RMLK_ARID_DEF.is_FuelUpMet = swc_RMLK_IN_NO_ACTIVE_CHILD;
                  swc_RMLK_ARID_DEF.is_c2_swc_RMLK = swc_RMLK_IN_FuelUpMetB;
                  swc_RMLK_ARID_DEF.is_FuelUpMetB = swc_RMLK_IN_DelayB;

                  /*  delay timer start */
                  swc_RMLK_ARID_DEF.timer_f = 0.0F;
                  rlcd_v_fuelA1Pos = 100.0F;
                } else if (c > rlcc_v_fuleLv1) {
                  swc_RMLK_ARID_DEF.is_FuelUpMet = swc_RMLK_IN_NO_ACTIVE_CHILD;
                  swc_RMLK_ARID_DEF.is_c2_swc_RMLK = swc_RMLK_IN_Defualt;
                  swc_RMLK_ARID_DEF.timer_f = 0.0F;
                  swc_RMLK_ARID_DEF.out = 0U;
                  rlcd_v_fuelA1Pos = 1000.0F;
                }
              }
              break;
            }
          }
        }
        break;

       default:
        /* case IN_FuelUpMetB: */
        if (!rlcd_b_fuelUpCalEna) {
          swc_RMLK_ARID_DEF.is_FuelUpMetB = swc_RMLK_IN_NO_ACTIVE_CHILD;
          swc_RMLK_ARID_DEF.is_c2_swc_RMLK = swc_RMLK_IN_Defualt;
          swc_RMLK_ARID_DEF.timer_f = 0.0F;
          swc_RMLK_ARID_DEF.out = 0U;
          rlcd_v_fuelA1Pos = 1000.0F;
        } else {
          switch (swc_RMLK_ARID_DEF.is_FuelUpMetB) {
           case swc_RMLK_IN_DelayB:
            /*  delay 10s */
            if (swc_RMLK_ARID_DEF.timer_f >= rlcc_tm_fuleUpB1Dly_s) {
              swc_RMLK_ARID_DEF.is_FuelUpMetB = swc_RMLK_IN_getB1;
              swc_RMLK_ARID_DEF.timer_f = 0.0F;
              rlcd_v_fuelB1Pos = 100.0F;
            } else {
              swc_RMLK_ARID_DEF.timer_f = (float32)(swc_RMLK_ARID_DEF.timer_f +
                0.01);
            }
            break;

           case swc_RMLK_IN_MetB:
            swc_RMLK_ARID_DEF.out = 1U;
            break;

           default:
            /* case IN_getB1: */
            if (rlcd_v_fuelB1Pos - rlcd_v_fuelA1Pos >= rlcc_v_fuleLv2) {
              swc_RMLK_ARID_DEF.is_FuelUpMetB = swc_RMLK_IN_MetB;
              swc_RMLK_ARID_DEF.out = 1U;
            } else {
              swc_RMLK_ARID_DEF.is_FuelUpMetB = swc_RMLK_IN_DelayB;

              /*  delay timer start */
              swc_RMLK_ARID_DEF.timer_f = 0.0F;
              rlcd_v_fuelA1Pos = 100.0F;
            }
            break;
          }
        }
        break;
      }
    }

    /* End of Chart: '<S180>/fuelUpMode' */

    /* RelationalOperator: '<S193>/Compare' incorporates:
     *  Constant: '<S193>/Constant'
     */
    rtb_Compare_as = (rlcd_st_authState == ((uint8)4U));

    /* Switch: '<S183>/Switch17' incorporates:
     *  Constant: '<S205>/Constant'
     *  RelationalOperator: '<S205>/Compare'
     */
    if (rlcd_num_LockLimSetReq == ((uint8)5U)) {
      /* Switch: '<S183>/Switch17' incorporates:
       *  Constant: '<S183>/Constant20'
       */
      Switch17 = ((uint8)0U);
    } else {
      /* Switch: '<S183>/Switch17' */
      Switch17 = rlcd_num_LockLimSetReq;
    }

    /* End of Switch: '<S183>/Switch17' */

    /* UnitDelay: '<S22>/Unit Delay3' */
    rtb_UnitDelay3_o = swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_h0;

    /* UnitDelay: '<S23>/Unit Delay3' */
    rtb_UnitDelay3_ai = swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_ly;

    /* UnitDelay: '<S24>/Unit Delay3' */
    rtb_UnitDelay3_nk = swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_k;

    /* UnitDelay: '<S25>/Unit Delay3' */
    rtb_UnitDelay3_c = swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_a4;

    /* UnitDelay: '<S26>/Unit Delay3' */
    rtb_UnitDelay3_g = swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_br;

    /* Update for UnitDelay: '<S163>/Unit Delay1' */
    swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_o = rtb_CCaller;

    /* Update for UnitDelay: '<S163>/Unit Delay3' */
    swc_RMLK_ARID_DEF.UnitDelay3_DSTATE = rlcd_n_rmlkIgOnCnt;

    /* Update for UnitDelay: '<S171>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_hv = rlcd_b_ignOn;

    /* Update for UnitDelay: '<S163>/Unit Delay2' */
    swc_RMLK_ARID_DEF.UnitDelay2_DSTATE = rtb_Switch8;

    /* Update for UnitDelay: '<S166>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_hp = rtb_RelationalOperator;

    /* Update for UnitDelay: '<S164>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_j = rlcd_b_ignOn;

    /* Update for UnitDelay: '<S17>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE = rlcd_n_flashCnt;

    /* Update for UnitDelay: '<S165>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_k = rtb_RelationalOperator_g;

    /* Update for UnitDelay: '<S32>/Delay Input1'
     *
     * Block description for '<S32>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE = rlcd_b_ignOn;

    /* Update for UnitDelay: '<S33>/Delay Input1'
     *
     * Block description for '<S33>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_h = rlcd_b_obcWakeUp;

    /* Update for UnitDelay: '<S7>/Unit Delay1' incorporates:
     *  Constant: '<S7>/Constant3'
     */
    swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_cd = false;

    /* Update for UnitDelay: '<S7>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_g = rtb_CCaller11;

    /* Update for UnitDelay: '<S172>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_n = rlcd_b_ignOn;

    /* Update for UnitDelay: '<S173>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_o = rlcd_b_obcWakeUp;

    /* Update for UnitDelay: '<S18>/Unit Delay1' incorporates:
     *  Constant: '<S18>/Constant2'
     */
    swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_d4 = false;

    /* Update for UnitDelay: '<S18>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_h = rtb_CCaller10;

    /* Update for UnitDelay: '<S10>/Unit Delay4' */
    swc_RMLK_ARID_DEF.UnitDelay4_DSTATE = rlcd_TBOX_Update;

    /* Update for UnitDelay: '<S10>/Unit Delay1' incorporates:
     *  DataTypeConversion: '<S184>/Data Type Conversion1'
     */
    swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_l = rlcd_st_LockVehExecutedSts;

    /* Update for UnitDelay: '<S147>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_e = rtb_RelationalOperator5;

    /* Update for UnitDelay: '<S10>/Unit Delay3' */
    swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_b = swc_RMLK_ARID_DEF.Saturation;

    /* Update for UnitDelay: '<S258>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_hn = rlcd_b_ignOn;

    /* Update for UnitDelay: '<S259>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_b = rlcd_b_obcWakeUp;

    /* Update for UnitDelay: '<S22>/Unit Delay' incorporates:
     *  Constant: '<S22>/Constant2'
     */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_d = false;

    /* Update for UnitDelay: '<S22>/Unit Delay2' */
    swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_k = rtb_CCaller3_a;

    /* Update for UnitDelay: '<S10>/Unit Delay5' */
    swc_RMLK_ARID_DEF.UnitDelay5_DSTATE = rlcd_b_ChgAntiLockReq;

    /* Update for UnitDelay: '<S10>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_on = rlcd_b_LockVehResults;

    /* Update for UnitDelay: '<S269>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_nk = rlcd_b_ignOn;

    /* Update for UnitDelay: '<S270>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_dh = rlcd_b_obcWakeUp;

    /* Update for UnitDelay: '<S26>/Unit Delay' incorporates:
     *  Constant: '<S26>/Constant2'
     */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_bo = false;

    /* Update for UnitDelay: '<S26>/Unit Delay2' */
    swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_p = rlcd_num_NormLockSaveRltRaw;

    /* Update for Delay: '<S26>/Variable Integer Delay' */
    for (i = 0; i < 99; i++) {
      swc_RMLK_ARID_DEF.VariableIntegerDelay_DSTATE[i] =
        swc_RMLK_ARID_DEF.VariableIntegerDelay_DSTATE[i + 1];
    }

    swc_RMLK_ARID_DEF.VariableIntegerDelay_DSTATE[99] = rlcd_b_ignOn;

    /* End of Update for Delay: '<S26>/Variable Integer Delay' */

    /* Update for UnitDelay: '<S268>/Delay Input1'
     *
     * Block description for '<S268>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_e = rtb_VariableIntegerDelay;

    /* Update for UnitDelay: '<S26>/Unit Delay4' */
    swc_RMLK_ARID_DEF.UnitDelay4_DSTATE_l = rtb_CCaller4_a;

    /* Update for UnitDelay: '<S260>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_l = rlcd_b_ignOn;

    /* Update for UnitDelay: '<S261>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_i = rlcd_b_obcWakeUp;

    /* Update for UnitDelay: '<S23>/Unit Delay' incorporates:
     *  Constant: '<S23>/Constant2'
     */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_nk2 = false;

    /* Update for UnitDelay: '<S23>/Unit Delay2' */
    swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_e = rtb_CCaller5;

    /* Update for UnitDelay: '<S10>/Unit Delay8' */
    swc_RMLK_ARID_DEF.UnitDelay8_DSTATE_p = rlcd_b_ChgLockExcReqCur;

    /* Update for UnitDelay: '<S10>/Unit Delay2' */
    swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_l = rtb_LockTyp;

    /* Update for UnitDelay: '<S10>/Unit Delay9' */
    swc_RMLK_ARID_DEF.UnitDelay9_DSTATE = Switch1_h;

    /* Update for UnitDelay: '<S8>/Unit Delay5' */
    swc_RMLK_ARID_DEF.UnitDelay5_DSTATE_e = rlcd_b_ChgAntiLockReq;

    /* Update for UnitDelay: '<S8>/Unit Delay8' */
    swc_RMLK_ARID_DEF.UnitDelay8_DSTATE_a = rlcd_b_ChgLockExcReqCur;

    /* Update for UnitDelay: '<S8>/Unit Delay3' */
    swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_a = rtb_LockTyp;

    /* Update for UnitDelay: '<S8>/Unit Delay1' */
    swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_n = rtb_CCaller6;

    /* Update for UnitDelay: '<S8>/Unit Delay2' */
    swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_ev = rtb_CCaller7;

    /* Update for UnitDelay: '<S264>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_gw = rlcd_b_ignOn;

    /* Update for UnitDelay: '<S265>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_a = rlcd_b_obcWakeUp;

    /* Update for UnitDelay: '<S25>/Unit Delay' incorporates:
     *  Constant: '<S25>/Constant2'
     */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_ok = false;

    /* Update for UnitDelay: '<S25>/Unit Delay2' */
    swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_i = rtb_CCaller8;

    /* Update for UnitDelay: '<S262>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_mq = rlcd_b_ignOn;

    /* Update for UnitDelay: '<S263>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_da = rlcd_b_obcWakeUp;

    /* Update for UnitDelay: '<S24>/Unit Delay' incorporates:
     *  Constant: '<S24>/Constant2'
     */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_c = false;

    /* Update for UnitDelay: '<S24>/Unit Delay2' */
    swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_im = rtb_Switch8_i;

    /* Update for UnitDelay: '<S106>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_am = rlcd_b_ignOn;

    /* Update for UnitDelay: '<S107>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_hx = rlcd_b_chgAnti_flg;

    /* Update for UnitDelay: '<S9>/Unit Delay10' */
    swc_RMLK_ARID_DEF.UnitDelay10_DSTATE = rlcd_b_fuelUpAntiLockReq;

    /* Update for UnitDelay: '<S108>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_br = rtb_Compare_fof;

    /* Update for UnitDelay: '<S49>/Unit Delay4' */
    swc_RMLK_ARID_DEF.UnitDelay4_DSTATE_k = rtb_Switch1_mx;

    /* Update for UnitDelay: '<S9>/Unit Delay8' */
    swc_RMLK_ARID_DEF.UnitDelay8_DSTATE = swc_RMLK_ARID_DEF.AntiReq_b;

    /* Update for UnitDelay: '<S9>/Unit Delay9' */
    swc_RMLK_ARID_DEF.UnitDelay9_DSTATE_i = Switch1_h;

    /* Update for UnitDelay: '<S155>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_ni = rlcd_b_ignOn;

    /* Update for UnitDelay: '<S156>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_fw = rlcd_b_obcWakeUp;

    /* Update for UnitDelay: '<S11>/Unit Delay' incorporates:
     *  Constant: '<S11>/Constant2'
     */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_i1 = false;

    /* Update for UnitDelay: '<S11>/Unit Delay2' */
    swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_f = rtb_UnitDelay8;

    /* Update for UnitDelay: '<S9>/Unit Delay4' */
    swc_RMLK_ARID_DEF.UnitDelay4_DSTATE_a = rtb_LogicalOperator3_k;

    /* Update for UnitDelay: '<S9>/Unit Delay5' */
    swc_RMLK_ARID_DEF.UnitDelay5_DSTATE_a = rtb_LogicalOperator3_a;

    /* Update for UnitDelay: '<S9>/Unit Delay3' */
    swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_d = rlcd_num_NormLockReqRaw;

    /* Update for UnitDelay: '<S9>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_fh = rtb_LogicalOperator3_k;

    /* Update for UnitDelay: '<S9>/Unit Delay6' */
    swc_RMLK_ARID_DEF.UnitDelay6_DSTATE = rtb_LogicalOperator3_a;

    /* Update for UnitDelay: '<S9>/Unit Delay1' */
    swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_d = rtb_Switch5;

    /* Update for UnitDelay: '<S9>/Unit Delay2' */
    swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_ko = rtb_Switch6;

    /* Update for UnitDelay: '<S102>/Delay Input1'
     *
     * Block description for '<S102>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_hw = rlcd_b_ignOn;

    /* Update for UnitDelay: '<S103>/Delay Input1'
     *
     * Block description for '<S103>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_b = rlcd_b_ignOn;

    /* Update for UnitDelay: '<S9>/Unit Delay7' */
    swc_RMLK_ARID_DEF.UnitDelay7_DSTATE = rlcd_b_fuelUpNormalLockReq;

    /* Update for UnitDelay: '<S11>/Unit Delay3' */
    swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_l = rtb_Switch5;

    /* Update for UnitDelay: '<S184>/Unit Delay2' incorporates:
     *  Logic: '<S184>/Logical Operator7'
     */
    swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_o = !rlcd_b_fuleUpAntiLockExcReq;

    /* Update for UnitDelay: '<S184>/Unit Delay1' incorporates:
     *  Constant: '<S217>/Constant'
     *  RelationalOperator: '<S217>/Compare'
     */
    swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_b = (rlcd_st_FuelingStatus == ((uint8)1U));

    /* Update for UnitDelay: '<S184>/Unit Delay' incorporates:
     *  Constant: '<S209>/Constant'
     *  RelationalOperator: '<S209>/Compare'
     */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_o5 = (rlcd_st_LockVehExecutedSts ==
      ((uint8)1U));

    /* Update for UnitDelay: '<S218>/Delay Input1'
     *
     * Block description for '<S218>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_k = TBOX_AuthSuccess;

    /* Update for UnitDelay: '<S219>/Delay Input1'
     *
     * Block description for '<S219>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_a = TBOX_AuthFail_dismatch;

    /* Update for UnitDelay: '<S220>/Delay Input1'
     *
     * Block description for '<S220>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_m = rtb_Compare_ok;

    /* Update for UnitDelay: '<S221>/Delay Input1'
     *
     * Block description for '<S221>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_n = rtb_Compare_dp;

    /* Update for UnitDelay: '<S222>/Delay Input1'
     *
     * Block description for '<S222>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_p = rtb_Compare_hjh;

    /* Update for UnitDelay: '<S223>/Delay Input1'
     *
     * Block description for '<S223>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_o = rtb_Compare_pv;

    /* Update for UnitDelay: '<S225>/Unit Delay1' */
    swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_j = rlcd_num_ExeStsUpdateSaveResult;

    /* Update for UnitDelay: '<S225>/Unit Delay3' */
    swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_h = rlcd_num_ExeStsUpdate;

    /* Update for UnitDelay: '<S229>/Delay Input1'
     *
     * Block description for '<S229>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_bz = rlcd_b_ignOn;

    /* Update for UnitDelay: '<S230>/Delay Input1'
     *
     * Block description for '<S230>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_i = rlcd_b_obcWakeUp;

    /* Update for UnitDelay: '<S227>/Unit Delay4' */
    swc_RMLK_ARID_DEF.UnitDelay4_DSTATE_c = rtb_Switch1_g;

    /* Update for UnitDelay: '<S225>/Unit Delay2' */
    swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_ij = rtb_UnitDelay3_hg;

    /* Update for UnitDelay: '<S226>/Unit Delay1' */
    swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_k = rlcd_num_ExeStsUpdate1SaveResult;

    /* Update for UnitDelay: '<S226>/Unit Delay3' */
    swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_ay = rlcd_num_ExeStsUpdate1;

    /* Update for UnitDelay: '<S241>/Delay Input1'
     *
     * Block description for '<S241>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_hu = rlcd_b_ignOn;

    /* Update for UnitDelay: '<S242>/Delay Input1'
     *
     * Block description for '<S242>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_b1 = rlcd_b_obcWakeUp;

    /* Update for UnitDelay: '<S239>/Unit Delay4' */
    swc_RMLK_ARID_DEF.UnitDelay4_DSTATE_j = rtb_Switch1_o;

    /* Update for UnitDelay: '<S226>/Unit Delay2' */
    swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_g = rtb_Switch8_ib;

    /* Update for UnitDelay: '<S18>/Unit Delay2' */
    swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_l4 = rlcd_num_LockLimSetReq;

    /* Update for UnitDelay: '<S177>/Delay Input1'
     *
     * Block description for '<S177>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_j = rlcd_b_ignOn;

    /* Update for UnitDelay: '<S178>/Delay Input1'
     *
     * Block description for '<S178>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_g = rlcd_b_obcWakeUp;

    /* Update for UnitDelay: '<S19>/Unit Delay1' */
    swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_c = rlcd_num_rmtLkSpdLimCfg3;

    /* Update for UnitDelay: '<S20>/Unit Delay1' */
    swc_RMLK_ARID_DEF.UnitDelay1_DSTATE = rtb_t_delay_off;

    /* Update for UnitDelay: '<S198>/Delay Input1'
     *
     * Block description for '<S198>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_o2 = rlcd_b_ignOn;

    /* Update for UnitDelay: '<S199>/Delay Input1'
     *
     * Block description for '<S199>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_n5 = rlcd_b_obcWakeUp;

    /* Update for UnitDelay: '<S181>/Unit Delay1' */
    swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_n2 = Switch9;

    /* Update for UnitDelay: '<S203>/Delay Input1'
     *
     * Block description for '<S203>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_bx = rlcd_b_ignOn;

    /* Update for UnitDelay: '<S204>/Delay Input1'
     *
     * Block description for '<S204>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_RMLK_ARID_DEF.DelayInput1_DSTATE_eb = rlcd_b_obcWakeUp;

    /* Update for UnitDelay: '<S182>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_f = Switch1_h;

    /* Update for UnitDelay: '<S180>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_m = swc_RMLK_ARID_DEF.out;

    /* Update for UnitDelay: '<S22>/Unit Delay3' */
    swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_h0 = swc_RMLK_ARID_DEF.AntiReq_b;

    /* Update for UnitDelay: '<S23>/Unit Delay3' */
    swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_ly = rtb_Switch6;

    /* Update for UnitDelay: '<S24>/Unit Delay3' */
    swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_k = rlcd_num_FunAnti_DismantleActiveReq;

    /* Update for UnitDelay: '<S25>/Unit Delay3' */
    swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_a4 = rlcd_num_FunLockVehActiveReq;

    /* Update for UnitDelay: '<S26>/Unit Delay3' */
    swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_br = rlcd_num_NormLockReq;

    /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
     *  SubSystem: '<S3>/RmtLckCtrl_OutputLayer_N72'
     */
    /* SignalConversion: '<S6>/over1_9' */
    rtb_RelationalOperator = rlcd_b_LockVehResults;

    /* End of Outputs for S-Function (fcgen): '<S3>/Function-Call Generator' */

    /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
     *  SubSystem: '<S3>/RLC'
     */
    /* SignalConversion: '<S6>/over1_12' incorporates:
     *  DataTypeConversion: '<S184>/Data Type Conversion1'
     */
    rtb_CCaller10 = rlcd_st_LockVehExecutedSts;

    /* CCaller: '<S6>/C Caller1' incorporates:
     *  DataTypeConversion: '<S4>/Data Type Conversion10'
     */
    rtb_CCaller1 = rlcd_num_VCU_AuthResult;

    /* CCaller: '<S6>/C Caller1' */
    mBSW_Set_PMS_AuthResult(&rtb_CCaller1);

    /* CCaller: '<S6>/C Caller2' incorporates:
     *  DataTypeConversion: '<S4>/Data Type Conversion11'
     */
    rtb_CCaller2_m = rtb_UnitDelay9_h;

    /* CCaller: '<S6>/C Caller2' */
    mBSW_Set_PMS_RespResult(&rtb_CCaller2_m);

    /* CCaller: '<S6>/C Caller4' incorporates:
     *  DataTypeConversion: '<S6>/Data Type Conversion'
     */
    rtb_CCaller4 = rlcd_b_aswTboxUpdate;

    /* CCaller: '<S6>/C Caller4' */
    mBSW_Set_aswAuthUpdate(&rtb_CCaller4);
    for (i = 0; i < 7; i++) {
      /* CCaller: '<S6>/C Caller3' incorporates:
       *  DataTypeConversion: '<S4>/Data Type Conversion12'
       */
      rtb_CCaller3[i] = rtb_CCaller1_i[i];
    }

    /* CCaller: '<S6>/C Caller3' */
    mBSW_Set_PMS_ReqSeed(&rtb_CCaller3[0]);

    /* End of Outputs for S-Function (fcgen): '<S3>/Function-Call Generator' */

    /* Outputs for Enabled SubSystem: '<S6>/NvmUpdate1' incorporates:
     *  EnablePort: '<S278>/Enable'
     */
    /* Outputs for Enabled SubSystem: '<S6>/NvmUpdate' incorporates:
     *  EnablePort: '<S277>/Enable'
     */
    /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
     *  SubSystem: '<S3>/RLC'
     */
    if (TBOX_SeedReq) {
      /* CCaller: '<S277>/C Caller10' */
      mBSW_NvmWrite_FunLockVehActiveReq(rtb_DataTypeConversion);

      /* CCaller: '<S277>/C Caller11' */
      mBSW_NvmWrite_FunAnti_DismantleActiveReq(FunAntiDismtActiveResultCur);

      /* CCaller: '<S277>/C Caller9' */
      mBSW_NvmWrite_LockLimSetReq(LockLimSetBswCur);

      /* CCaller: '<S277>/C Caller12' */
      mBSW_NvmWrite_NormLockReq(VCU_NormLockSaveResultCur);

      /* CCaller: '<S277>/C Caller13' */
      mBSW_NvmWrite_ChgLockReq(rlcd_num_ChgLockReq_o);

      /* CCaller: '<S277>/C Caller14' */
      mBSW_NvmWrite_ChgLockExcReq(vsld_num_ChgLockExcReq);

      /* CCaller: '<S277>/C Caller15' */
      mBSW_NvmWrite_AntiLockReq(rlcd_num_AntiLockReq_b);

      /* CCaller: '<S278>/C Caller9' */
      mBSW_NvmWrite_ExeStsUpdate(rtb_UnitDelay3_f);

      /* CCaller: '<S278>/C Caller1' */
      mBSW_NvmWrite_ExeStsUpdate1(rlcd_num_ExeStsUpdate1_j);
    }

    /* End of Outputs for S-Function (fcgen): '<S3>/Function-Call Generator' */
    /* End of Outputs for SubSystem: '<S6>/NvmUpdate' */
    /* End of Outputs for SubSystem: '<S6>/NvmUpdate1' */

    /* SignalConversion generated from: '<S3>/rlcd_b_LockVehSts' incorporates:
     *  DataTypeConversion: '<S4>/Data Type Conversion'
     */
    swc_RMLK_ARID_DEF.OutportBufferForrlcd_b_LockVehS = rtb_RelationalOperator;

    /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
     *  SubSystem: '<S3>/RmtLckCtrl_OutputLayer_N72'
     */
    /* SignalConversion generated from: '<S3>/rlcd_b_rmtCtrlAccPedlOff' incorporates:
     *  SignalConversion: '<S6>/over1_4'
     */
    swc_RMLK_ARID_DEF.OutportBufferForrlcd_b_rmtCtrlA = rtb_LogicalOperator1_o0;

    /* SignalConversion generated from: '<S3>/rlcd_b_rmtCtrlTqOff' incorporates:
     *  SignalConversion: '<S6>/over1_3'
     */
    swc_RMLK_ARID_DEF.OutportBufferForrlcd_b_rmtCtrlT = rtb_RelationalOperator_j;

    /* SignalConversion generated from: '<S3>/rlcd_b_rmtCtrlTurtleLampOn' incorporates:
     *  SignalConversion: '<S6>/over1_2'
     */
    swc_RMLK_ARID_DEF.OutportBufferForrlcd_b_rmtCtr_d = rtb_LogicalOperator2_c;

    /* SignalConversion generated from: '<S3>/rlcd_num_FunAnti_DismantleActive' incorporates:
     *  SignalConversion: '<S6>/over1_6'
     */
    swc_RMLK_ARID_DEF.OutportBufferForrlcd_num_FunAnt = Switch9;

    /* SignalConversion generated from: '<S3>/rlcd_num_FunLockVehActive' incorporates:
     *  SignalConversion: '<S6>/over1_5'
     */
    swc_RMLK_ARID_DEF.OutportBufferForrlcd_num_FunLoc = Switch1_h;

    /* SignalConversion generated from: '<S3>/rlcd_num_LockLimResult' incorporates:
     *  SignalConversion: '<S6>/over1_7'
     */
    swc_RMLK_ARID_DEF.OutportBufferForrlcd_num_LockLi = Switch17;

    /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
     *  SubSystem: '<S3>/RLC'
     */
    /* SignalConversion generated from: '<S3>/rlcd_num_LockVehType' incorporates:
     *  SignalConversion generated from: '<S4>/rlcd_num_LockVehType'
     */
    swc_RMLK_ARID_DEF.OutportBufferForrlcd_num_LockVe = rtb_LockTyp;

    /* End of Outputs for S-Function (fcgen): '<S3>/Function-Call Generator' */

    /* SignalConversion generated from: '<S3>/rlcd_st_LockVehExecutedSts' */
    swc_RMLK_ARID_DEF.OutportBufferForrlcd_st_LockVeh = rtb_CCaller10;

    /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
     *  SubSystem: '<S3>/RmtLckCtrl_OutputLayer_N72'
     */
    /* SignalConversion generated from: '<S3>/rlcd_v_rmtCtrlFctSpdLim_kph' incorporates:
     *  SignalConversion: '<S6>/over1_1'
     */
    swc_RMLK_ARID_DEF.OutportBufferForrlcd_v_rmtCtrlF = Switch1;

    /* End of Outputs for S-Function (fcgen): '<S3>/Function-Call Generator' */
  } else if (swc_RMLK_ARID_DEF.RMLK_Enable_MODE) {
    /* Disable for S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
     *  SubSystem: '<S3>/RLC'
     */
    /* Disable for Logic: '<S185>/Logical Operator5' incorporates:
     *  Outport: '<S4>/rlcd_b_LockVehSts '
     */
    rlcd_b_LockVehResults = false;

    /* End of Disable for S-Function (fcgen): '<S3>/Function-Call Generator' */
    swc_RMLK_ARID_DEF.RMLK_Enable_MODE = false;
  }

  /* End of RelationalOperator: '<S2>/Compare' */
  /* End of Outputs for SubSystem: '<S1>/RMLK_Enable' */

  /* Outport generated from: '<Root>/Out Bus Element'
   *
   * Block description for Outport generated from '<Root>/Out Bus Element':
   *  Remote Lock Limit Speed
   */
  Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_v_rmtCtrlFctSpdLim_kph
    (swc_RMLK_ARID_DEF.OutportBufferForrlcd_v_rmtCtrlF);

  /* Outport generated from: '<Root>/Out Bus Element1'
   *
   * Block description for Outport generated from '<Root>/Out Bus Element1':
   *  &#x9501;&#x8F66;&#x70B9;&#x4E4C;&#x9F9F;&#x7B49;&#x6807;&#x5FD7;&#x4F4D;
   */
  Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_b_rmtCtrlTurtleLampOn
    (swc_RMLK_ARID_DEF.OutportBufferForrlcd_b_rmtCtr_d);

  /* Outport generated from: '<Root>/Out Bus Element2'
   *
   * Block description for Outport generated from '<Root>/Out Bus Element2':
   *  &#x9501;&#x8F66;&#x9650;&#x5236;&#x626D;&#x77E9;&#x6807;&#x5FD7;&#x4F4D;
   */
  Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_b_rmtCtrlTqOff
    (swc_RMLK_ARID_DEF.OutportBufferForrlcd_b_rmtCtrlT);

  /* Outport generated from: '<Root>/Out Bus Element3'
   *
   * Block description for Outport generated from '<Root>/Out Bus Element3':
   *  &#x9501;&#x8F66;&#x6FC0;&#x6D3B;&#x9650;&#x5236;&#x6CB9;&#x95E8;&#x6807;&#x5FD7;&#x4F4D;
   */
  Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_b_rmtCtrlAccPedlOff
    (swc_RMLK_ARID_DEF.OutportBufferForrlcd_b_rmtCtrlA);

  /* Outport generated from: '<Root>/Out Bus Element5'
   *
   * Block description for Outport generated from '<Root>/Out Bus Element5':
   *  &#x9501;&#x8F66;&#x529F;&#x80FD;&#x6FC0;&#x6D3B;
   */
  Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_num_FunLockVehActive
    (swc_RMLK_ARID_DEF.OutportBufferForrlcd_num_FunLoc);

  /* Outport generated from: '<Root>/Out Bus Element6'
   *
   * Block description for Outport generated from '<Root>/Out Bus Element6':
   *  &#x9632;&#x76D7;&#x9501;&#x8F66;&#x529F;&#x80FD;&#x6FC0;&#x6D3B;
   */
  Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_num_FunAnti_DismantleActive
    (swc_RMLK_ARID_DEF.OutportBufferForrlcd_num_FunAnt);

  /* Outport generated from: '<Root>/Out Bus Element7'
   *
   * Block description for Outport generated from '<Root>/Out Bus Element7':
   *  &#x9501;&#x8F66;&#x9650;&#x901F;&#x7ED3;&#x679C;
   */
  Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_num_LockLimResult
    (swc_RMLK_ARID_DEF.OutportBufferForrlcd_num_LockLi);

  /* Outport generated from: '<Root>/Out Bus Element8'
   *
   * Block description for Outport generated from '<Root>/Out Bus Element8':
   *  &#x9501;&#x8F66;&#x7C7B;&#x578B;
   */
  Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_num_LockVehType
    (swc_RMLK_ARID_DEF.OutportBufferForrlcd_num_LockVe);

  /* Outport generated from: '<Root>/Out Bus Element9'
   *
   * Block description for Outport generated from '<Root>/Out Bus Element9':
   *  &#x9501;&#x8F66;&#x6267;&#x884C;&#x72B6;&#x6001;
   */
  Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_b_LockVehSts
    (swc_RMLK_ARID_DEF.OutportBufferForrlcd_b_LockVehS);

  /* Outport generated from: '<Root>/Out Bus Element4'
   *
   * Block description for Outport generated from '<Root>/Out Bus Element4':
   *  PMS&#x53D1;&#x9001;&#x7684;&#x52A0;&#x5BC6;seed7
   */
  Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_st_LockVehExecutedSts
    (swc_RMLK_ARID_DEF.OutportBufferForrlcd_st_LockVeh);
}

/* Model initialize function */
void swc_RMLK_Init(void)
{
  {
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

    /* SystemInitialize for Enabled SubSystem: '<S1>/RMLK_Enable' */
    /* SystemInitialize for S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
     *  SubSystem: '<S3>/RLC'
     */
    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay1' */
    swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_cd = true;

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_g = ((uint8)3U);

    /* InitializeConditions for UnitDelay: '<S18>/Unit Delay1' */
    swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_d4 = true;

    /* InitializeConditions for UnitDelay: '<S18>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_h = ((uint8)3U);

    /* InitializeConditions for UnitDelay: '<S10>/Unit Delay1' */
    swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_l = ((uint8)7U);

    /* InitializeConditions for UnitDelay: '<S22>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_d = true;

    /* InitializeConditions for UnitDelay: '<S26>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_bo = true;

    /* InitializeConditions for UnitDelay: '<S23>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_nk2 = true;

    /* InitializeConditions for UnitDelay: '<S10>/Unit Delay2' */
    swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_l = ((uint8)3U);

    /* InitializeConditions for UnitDelay: '<S8>/Unit Delay3' */
    swc_RMLK_ARID_DEF.UnitDelay3_DSTATE_a = ((uint8)3U);

    /* InitializeConditions for UnitDelay: '<S25>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_ok = true;

    /* InitializeConditions for UnitDelay: '<S24>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_c = true;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_i1 = true;

    /* InitializeConditions for UnitDelay: '<S18>/Unit Delay2' */
    swc_RMLK_ARID_DEF.UnitDelay2_DSTATE_l4 = ((uint8)3U);

    /* InitializeConditions for UnitDelay: '<S19>/Unit Delay1' */
    swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_c = ((uint8)3U);

    /* InitializeConditions for UnitDelay: '<S20>/Unit Delay1' */
    swc_RMLK_ARID_DEF.UnitDelay1_DSTATE = rlcc_v_normLockSpdLimDft_kph;

    /* InitializeConditions for UnitDelay: '<S181>/Unit Delay1' */
    swc_RMLK_ARID_DEF.UnitDelay1_DSTATE_n2 = ((uint8)3U);

    /* InitializeConditions for UnitDelay: '<S182>/Unit Delay' */
    swc_RMLK_ARID_DEF.UnitDelay_DSTATE_f = ((uint8)3U);

    /* SystemInitialize for Enabled SubSystem: '<S10>/Rand_AES' */
    /* SystemInitialize for MATLAB Function: '<S146>/MATLAB Function' */
    memcpy(&swc_RMLK_ARID_DEF.state_b[0], &tmp[0], 625U * sizeof(uint32));
    swc_RMLK_ARID_DEF.method = 7U;
    swc_RMLK_ARID_DEF.state = 1144108930U;
    swc_RMLK_ARID_DEF.state_i[0] = 362436069U;
    swc_RMLK_ARID_DEF.state_i[1] = 521288629U;

    /* End of SystemInitialize for SubSystem: '<S10>/Rand_AES' */
    /* End of SystemInitialize for S-Function (fcgen): '<S3>/Function-Call Generator' */

    /* SystemInitialize for SignalConversion generated from: '<S3>/rlcd_v_rmtCtrlFctSpdLim_kph' incorporates:
     *  Outport: '<S3>/rlcd_v_rmtCtrlFctSpdLim_kph'
     */
    swc_RMLK_ARID_DEF.OutportBufferForrlcd_v_rmtCtrlF = 255.0F;

    /* SystemInitialize for SignalConversion generated from: '<S3>/rlcd_num_LockLimResult' incorporates:
     *  Outport: '<S3>/rlcd_num_LockLimResult'
     */
    swc_RMLK_ARID_DEF.OutportBufferForrlcd_num_LockLi = ((uint8)3U);

    /* SystemInitialize for SignalConversion generated from: '<S3>/rlcd_num_LockVehType' incorporates:
     *  Outport: '<S3>/rlcd_num_LockVehType'
     */
    swc_RMLK_ARID_DEF.OutportBufferForrlcd_num_LockVe = ((uint8)3U);

    /* End of SystemInitialize for SubSystem: '<S1>/RMLK_Enable' */

    /* ConstCode for Enabled SubSystem: '<S1>/RMLK_Enable' */
    /* ConstCode for S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
     *  SubSystem: '<S3>/RLC'
     */
    /* ConstCode for Constant: '<S4>/Constant' */
    rlcd_n_gcvRlcVer = ((uint16)812U);

    /* End of ConstCode for S-Function (fcgen): '<S3>/Function-Call Generator' */
    /* End of ConstCode for SubSystem: '<S1>/RMLK_Enable' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

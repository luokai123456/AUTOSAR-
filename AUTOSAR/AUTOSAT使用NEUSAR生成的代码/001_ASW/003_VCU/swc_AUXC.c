/*
 * File: swc_AUXC.c
 *
 * Code generated for Simulink model 'swc_AUXC'.
 *
 * Model version                  : 6.67
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Jan  5 16:12:56 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "swc_AUXC.h"
#include "rtwtypes.h"
#include <math.h>
#include "Rte_Type.h"
#include "const_ImportedDefine.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef BRP_TASK_INTERVAL_S
#error The value of parameter "BRP_TASK_INTERVAL_S" is not defined
#endif

#ifndef VEH_SWT_INF
#error The value of parameter "VEH_SWT_INF" is not defined
#endif

/* Named constants for Chart: '<S23>/timed_delay' */
#define swc_AUXC_IN_NO_ACTIVE_CHILD    ((uint8)0U)
#define swc_AUXC_IN_OFF                ((uint8)1U)
#define swc_AUXC_IN_ON                 ((uint8)2U)
#define swc_AUXC_IN_ON_WAIT            ((uint8)3U)

/* Named constants for Chart: '<S33>/timed_debounce' */
#define swc_AUXC_IN_OFF_WAIT           ((uint8)2U)
#define swc_AUXC_IN_OFF_j              ((uint8)1U)
#define swc_AUXC_IN_ON_WAIT_m          ((uint8)4U)
#define swc_AUXC_IN_ON_n               ((uint8)3U)

/* Named constants for Chart: '<S3>/BDCACOnOffProtection' */
#define swc_AUXC_IN_INIT               ((uint8)1U)
#define swc_AUXC_IN_NO_ACTIVE_CHILD_h  ((uint8)0U)
#define swc_AUXC_IN_Off                ((uint8)2U)
#define swc_AUXC_IN_Off2On             ((uint8)3U)
#define swc_AUXC_IN_On                 ((uint8)4U)

/* Named constants for Chart: '<S3>/BrkVacPmpMode_Cal1' */
#define swc_AUXC_IN_VacPmp_Chg         ((uint8)1U)
#define swc_AUXC_IN_VacPmp_InitMdWrk   ((uint8)2U)
#define swc_AUXC_IN_VacPmp_NrmMdWrk1   ((uint8)3U)
#define swc_AUXC_IN_VacPmp_Off         ((uint8)1U)
#define swc_AUXC_IN_VacPmp_On          ((uint8)2U)
#define swc_AUXC_IN_VacPmp_OverTime1   ((uint8)3U)
#define swc_AUXC_IN_VacPmp_OverTime2   ((uint8)4U)
#define swc_AUXC_IN_VacPmp_OverTime3   ((uint8)5U)
#define swc_AUXC_IN_VacPmp_SftyMdWrk1  ((uint8)4U)
#define swc_AUXC_IN_VacPmp_SftyMdWrkOff ((uint8)1U)
#define swc_AUXC_IN_VacPmp_SftyMdWrkOn ((uint8)2U)

/* Named constants for Chart: '<S7>/VacuumPumpEnableControl' */
#define swc_AUXC_IN_CycleControl       ((uint8)1U)
#define swc_AUXC_IN_NormalControl      ((uint8)2U)
#define swc_AUXC_IN_OFF_i              ((uint8)1U)
#define swc_AUXC_IN_ON_m               ((uint8)2U)
#define swc_AUXC_IN_VacPumpOff         ((uint8)3U)

/* Named constants for Chart: '<S61>/timed_delay' */
#define swc_AUXC_IN_ON_WAIT_b          ((uint8)3U)

/* Exported data definition */
#define swc_AUXC_START_SEC_CONST_VOLATILE
#include "swc_AUXC_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_CAL */
const volatile boolean brpc_b_brkPumpVp2BevEnb = false;/* Referenced by: '<S3>/Constant18' */

/* enable cal for the BEV VP2 BDCAC function */
const volatile boolean brpc_b_enbBdcacTmOut = true;/* Referenced by: '<S9>/Constant6' */

/* Enable Brake Pump time out detection */
const volatile float32 brpc_p_airTankPresAllowDrv_bar = 5.0F;/* Referenced by: '<S3>/Relay1' */

/* Air Tank pressure high threshold for drive inhibition */
const volatile float32 brpc_p_airTankPresEVDisHi_bar = 5.5F;/* Referenced by: '<S3>/Relay2' */

/* Air Tank pressure high threshold for EV Mode Available */
const volatile float32 brpc_p_airTankPresEVDisLo_bar = 5.0F;/* Referenced by: '<S3>/Relay2' */

/* Air Tank pressure low threshold for EV Mode Available */
const volatile float32 brpc_p_airTankPresHiThr_bar = 5.5F;/* Referenced by: '<S3>/Relay9' */

/* Air Tank pressure high threshold for airTankFlt */
const volatile float32 brpc_p_airTankPresInhDrv_bar = 4.5F;/* Referenced by: '<S3>/Relay1' */

/* Air Tank pressure low threshold for drive inhibition */
const volatile float32 brpc_p_airTankPresLoThr_bar = 5.0F;/* Referenced by: '<S3>/Relay9' */

/* Air Tank pressure low threshold for airTankFlt */
const volatile float32 brpc_p_brkVacuumHiThr_bar = -0.45F;/* Referenced by: '<S3>/Relay4' */

/* Brake pressure threshold for brake pump ON */
const volatile float32 brpc_p_brkVacuumLoThr_bar = -0.6F;/* Referenced by: '<S3>/Relay4' */

/* Brake pressure threshold for brake pump OFF */
const volatile float32 brpc_pwr_brkPumpPeakPwr_kW = 5.0F;/* Referenced by: '<S3>/Constant13' */

/* BDCAC peak power */
const volatile float32 brpc_t_brkPumpOnLim_s = 600.0F;/* Referenced by: '<S3>/Constant6' */

/* Brake pump operation maximum time */
const volatile float32 brpc_t_brkPumpRstLim1_s = 180.0F;/* Referenced by: '<S3>/Constant7' */

/* Brake pump reset time1 */
const volatile float32 brpc_t_brkPumpRstLim2_s = 90.0F;/* Referenced by: '<S3>/Constant4' */

/* Brake pump reset time2 */
const volatile float32 brpc_t_vacPumpEnOvrTm_s = 45.0F;/* Referenced by:
                                                        * '<S44>/Constant15'
                                                        * '<S44>/Constant20'
                                                        */
const volatile float32 brpc_t_vacPumpLoPreFlt_s = 5.0F;/* Referenced by: '<S44>/Constant12' */
const volatile float32 brpc_t_vacPumpOffDly_s = 0.2F;/* Referenced by: '<S44>/Constant41' */
const volatile float32 brpc_t_vacPumpOnDly_s = 0.2F;/* Referenced by: '<S44>/Constant38' */
const volatile float32 brpc_t_vacPumpRlyFltThd_s = 1.0F;/* Referenced by: '<S43>/Constant20' */
const volatile float32 brpc_t_vacPumpSnrFlt_s = 0.5F;/* Referenced by:
                                                      * '<S44>/Constant14'
                                                      * '<S44>/Constant2'
                                                      */
const volatile float32 brpc_t_vacPumpSysFail1_s = 5.0F;/* Referenced by: '<S44>/Constant26' */
const volatile float32 brpc_t_vacPumpSysFail2_s = 10.0F;/* Referenced by: '<S44>/Constant33' */
const volatile float32 brpc_tm_airTankFltDtrmn_s = 0.01F;/* Referenced by: '<S3>/Batt_Heat3' */

/* Ari Tank Fault ON debounce time */
const volatile float32 brpc_tm_airTankFltRecv_s = 0.01F;/* Referenced by: '<S3>/Batt_Heat1' */

/* Ari Tank Fault OFF debounce time */
const volatile float32 brpc_tm_airTankPresLowOff_s = 0.01F;/* Referenced by: '<S3>/Batt_Heat2' */

/* Ari Tank Pressure Low OFF debounce time */
const volatile float32 brpc_tm_airTankPresLowOn_s = 0.01F;/* Referenced by: '<S3>/Batt_Heat4' */

/* Ari Tank Pressure Low ON debounce time */
const volatile float32 brpc_tm_bdcacTimeOut_s = 300.0F;/* Referenced by: '<S9>/Constant5' */

/* Brake pump time out threshold */
const volatile float32 brpc_u_vacPumpEnOvrTmH1_V = 1.67F;/* Referenced by: '<S44>/Constant11' */
const volatile float32 brpc_u_vacPumpEnOvrTmH2_V = 2.5F;/* Referenced by: '<S44>/Constant19' */
const volatile float32 brpc_u_vacPumpEnOvrTmL1_V = 0.79F;/* Referenced by: '<S44>/Constant10' */
const volatile float32 brpc_u_vacPumpEnOvrTmL2_V = 1.67F;/* Referenced by: '<S44>/Constant18' */
const volatile float32 brpc_u_vacPumpEnThd_V = 0.0F;/* Referenced by: '<S43>/Constant2' */
const volatile float32 brpc_u_vacPumpLoPreFltThd_V = 2.5F;/* Referenced by: '<S44>/Constant4' */
const volatile float32 brpc_u_vacPumpOff_V = 0.79F;/* Referenced by: '<S44>/Constant40' */
const volatile float32 brpc_u_vacPumpOn_V = 1.67F;/* Referenced by: '<S44>/Constant36' */
const volatile float32 brpc_u_vacPumpPowSup_V = 11.5F;/* Referenced by: '<S44>/Constant7' */
const volatile float32 brpc_u_vacPumpSnrFltThdH_V = 4.65F;/* Referenced by: '<S44>/Constant1' */
const volatile float32 brpc_u_vacPumpSnrFltThdL_V = 0.4F;/* Referenced by: '<S44>/Constant' */
const volatile float32 brpc_u_vacPumpSysFailThd_V = 1.67F;/* Referenced by:
                                                           * '<S44>/Constant25'
                                                           * '<S44>/Constant32'
                                                           */
const volatile float32 brpc_u_vacPumpVotDiff_V = 0.1F;/* Referenced by:
                                                       * '<S44>/Constant31'
                                                       * '<S44>/Constant35'
                                                       */
const volatile float32 brpc_u_vacsnrDwLim_V = 0.4F;/* Referenced by: '<S32>/Lower Limit' */

/* vaccumsensor volt low threshold */
const volatile float32 brpc_u_vacsnrUpLim_V = 4.65F;/* Referenced by: '<S32>/Upper Limit' */

/* vaccumsensor volt high  threshold */
const volatile float32 brpc_v_brkPumpVehSpdHiThr_kph = 10.0F;/* Referenced by: '<S3>/Relay3' */

/* BDCAC emergency enable vehicle speed high */
const volatile float32 brpc_v_brkPumpVehSpdLoThr_kph = 5.0F;/* Referenced by: '<S3>/Relay3' */

/* BDCAC emergency disable vehicle speed low */
const volatile float32 brpc_x_brkVacPmpClsdThr_pct = 0.25F;/* Referenced by: '<S3>/Constant1' */

/* Brake pressure threshold for brake pump ON */
const volatile float32 brpc_x_brkVacPmpOpnThr_pct = 0.4F;/* Referenced by: '<S3>/Constant' */

/* Brake pressure threshold for brake pump ON */
const volatile float32 brpc_x_brkVacPmpPresLowlim_pct = 0.65F;/* Referenced by: '<S3>/Constant11' */

/* Brake pressure threshold for brake pump ON */
const volatile float32 swcauxc_apuc_fact_12vDcdcEff = 0.98F;/* Referenced by: '<S3>/Constant15' */

#define swc_AUXC_STOP_SEC_CONST_VOLATILE
#include "swc_AUXC_MemMap.h"
#define swc_AUXC_START_SEC_VAR
#include "swc_AUXC_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_SIG */
boolean brpd_b_VacPumpEnOvrTmHiPre;    /* '<S61>/timed_delay' */
boolean brpd_b_VacPumpEnOvrTmHiPreFlt; /* '<S54>/Logical Operator3' */
boolean brpd_b_VacPumpEnOvrTmLoPreFlt; /* '<S52>/Logical Operator3' */
boolean brpd_b_VacPumpEnReq;           /* '<S7>/Signal Conversion5' */
boolean brpd_b_VacPumpEnReqRaw;        /* '<S44>/SR_latch3' */
boolean brpd_b_VacPumpLoPreFlt;        /* '<S50>/Logical Operator3' */
boolean brpd_b_VacPumpRlyEn;           /* '<S7>/Signal Conversion1' */
boolean brpd_b_VacPumpRlyFlt;          /* '<S45>/Logical Operator3' */
boolean brpd_b_VacPumpSnrFlt;          /* '<S49>/Logical Operator3' */
boolean brpd_b_VacPumpSysFailFlt;      /* '<S53>/Logical Operator3' */
boolean brpd_b_airTankFlt;             /* '<S3>/Signal Conversion2' */

/* Brake air tank error flag */
boolean brpd_b_airTankPresLow;         /* '<S3>/Signal Conversion3' */

/* Brake air tank pressure low flag */
boolean brpd_b_airTankPresLowEVDis;    /* '<S3>/Signal Conversion5' */

/* Brake air tank pressure low flag for EV Unavailable */
boolean brpd_b_airTankPresLowInhDrv;   /* '<S3>/Signal Conversion4' */

/* Brake air tank pressure low flag for drive inhibition */
boolean brpd_b_bdcacEna;               /* '<S3>/Signal Conversion6' */

/* Brake pump enable */
boolean brpd_b_bdcacTmOut;             /* '<S9>/Logical Operator3' */

/* Brake pump time out */
boolean brpd_b_brkPmp1Rly;             /* '<S12>/equal' */

/* Brake pump 1 relay */
boolean brpd_b_brkPmp2Rly;             /* '<S3>/Signal Conversion1' */

/* Brake pump 2 relay */
boolean brpd_b_pumpRdy;                /* '<S3>/Logical Operator2' */

/* Brake pump ready */
float32 brpd_p_VacPumpPressure_kPa;    /* '<S44>/Add3' */

/* Brake vacuum Pressure */
float32 brpd_x_PFactor;                /* '<S3>/Divide' */
float32 swcauxc_brpd_p_AirPres_kpa;    /* '<Root>/Data Type Conversion13' */

/* Air Pressure */
float32 swcauxc_brpd_p_brkVacuumPres_bar;/* '<Root>/Data Type Conversion46' */

/* Brake vacuum Pressure */
#define swc_AUXC_STOP_SEC_VAR
#include "swc_AUXC_MemMap.h"

/* Invariant block signals (default storage) */
const ConstB_swc_AUXC_T swc_AUXC_ConstB = {
  0.0F,                                /* '<Root>/Data Type Conversion8' */
  0.0F,                                /* '<Root>/Data Type Conversion9' */
  10.0F,                               /* '<S21>/Saturation' */
  0,                                   /* '<Root>/Data Type Conversion10' */
  0,                                   /* '<Root>/Data Type Conversion31' */
  0,                                   /* '<Root>/Data Type Conversion7' */
  0,                                   /* '<S44>/Relational Operator10' */
  1,                                   /* '<S44>/Logical Operator5' */

  /* Start of '<S13>/debounce1' */
  {
    5.0F,                              /* '<S34>/Saturation' */
    1.0F                               /* '<S34>/Saturation1' */
  }
  ,

  /* End of '<S13>/debounce1' */

  /* Start of '<S13>/debounce' */
  {
    0.5F,                              /* '<S33>/Saturation' */
    0.05F                              /* '<S33>/Saturation1' */
  }
  /* End of '<S13>/debounce' */
};

/* PublicStructure Variables for Internal Data */
ARID_DEF_swc_AUXC_T swc_AUXC_ARID_DEF;
static void swc_AUXC_timed_delay_Init(boolean *rty_flg_out);
static void swc_AUXC_timed_delay_Reset(boolean *rty_flg_out,
  ARID_DEF_timed_delay_swc_AUXC_T *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_timed_delay(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_timed_delay_swc_AUXC_T
  *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_turnON_delay_Init(boolean *rty_flg_out);
static void swc_AUXC_turnON_delay_Reset(boolean *rty_flg_out,
  ARID_DEF_turnON_delay_swc_AUX_T *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_turnON_delay(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnON_delay_swc_AUX_T
  *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch_Init(ARID_DEF_SR_latch_swc_AUXC_T
  *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch_Reset(ARID_DEF_SR_latch_swc_AUXC_T
  *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch_swc_AUXC_T *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_timed_debounce_Init(boolean *rty_flg_out);
static void swc_AUXC_timed_debounce(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_delay_off, float32 rtu_t_step, boolean *rty_flg_out,
  ARID_DEF_timed_debounce_swc_A_T *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_debounce_Init(boolean *rty_flg_out);
static void swc_AUXC_debounce(boolean rtu_flg_in, float32 rtu_t_step, boolean
  *rty_flg_out, const ConstB_debounce_swc_AUXC_T *localC,
  ARID_DEF_debounce_swc_AUXC_T *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_debounce_h_Init(boolean *rty_flg_out);
static void swc_AUXC_debounce_d(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_delay_off, float32 rtu_t_step, boolean *rty_flg_out,
  ARID_DEF_debounce_swc_AUXC_h_T *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch4_Init(ARID_DEF_SR_latch_swc_AUXC_n_T
  *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch4_Reset(ARID_DEF_SR_latch_swc_AUXC_n_T
  *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch4(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_AUXC_n_T *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch1_Init(ARID_DEF_SR_latch_swc_AUXC_f_T
  *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch1_Reset(ARID_DEF_SR_latch_swc_AUXC_f_T
  *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch1(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_AUXC_f_T *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch2_Init(ARID_DEF_SR_latch_swc_AUXC_p_T
  *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch2_Reset(ARID_DEF_SR_latch_swc_AUXC_p_T
  *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch2(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_AUXC_p_T *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch4_a_Init(ARID_DEF_SR_latch_swc_AUXC_ff_T
  *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch4_p_Reset(ARID_DEF_SR_latch_swc_AUXC_ff_T
  *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch4_c(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_AUXC_ff_T *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch5_Init(ARID_DEF_SR_latch_swc_AUXC_b_T
  *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch5_Reset(ARID_DEF_SR_latch_swc_AUXC_b_T
  *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch5(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_AUXC_b_T *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch6_Init(ARID_DEF_SR_latch_swc_AUXC_p5_T
  *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch6_Reset(ARID_DEF_SR_latch_swc_AUXC_p5_T
  *swc_AUXC__ARID_DEF_arg);
static void swc_AUXC_SR_latch6(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_AUXC_p5_T *swc_AUXC__ARID_DEF_arg);
static void BRP_BrakeVacuumPumpControl_Init(void);
static void swc__BRP_BrakeVacuumPumpControl(void);

/* Forward declaration for local functions */
static void swc_AUXC_VacPmp_NrmMdWrk1(uint8 *vcu_b_BrkVacPmpMode, const boolean *
  Delay);

/*
 * System initialize for atomic system:
 *    '<S23>/timed_delay'
 *    '<S21>/timed_delay'
 *    '<S46>/timed_delay'
 *    '<S55>/timed_delay'
 *    '<S56>/timed_delay'
 *    '<S57>/timed_delay'
 *    '<S58>/timed_delay'
 *    '<S59>/timed_delay'
 *    '<S60>/timed_delay'
 *    '<S62>/timed_delay'
 *    '<S63>/timed_delay'
 */
static void swc_AUXC_timed_delay_Init(boolean *rty_flg_out)
{
  *rty_flg_out = false;
}

/*
 * System reset for atomic system:
 *    '<S23>/timed_delay'
 *    '<S21>/timed_delay'
 *    '<S46>/timed_delay'
 *    '<S55>/timed_delay'
 *    '<S56>/timed_delay'
 *    '<S57>/timed_delay'
 *    '<S58>/timed_delay'
 *    '<S59>/timed_delay'
 *    '<S60>/timed_delay'
 *    '<S62>/timed_delay'
 *    '<S63>/timed_delay'
 */
static void swc_AUXC_timed_delay_Reset(boolean *rty_flg_out,
  ARID_DEF_timed_delay_swc_AUXC_T *swc_AUXC__ARID_DEF_arg)
{
  swc_AUXC__ARID_DEF_arg->is_active_c14_Ricardo_SW_dev_li = 0U;
  swc_AUXC__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib =
    swc_AUXC_IN_NO_ACTIVE_CHILD;
  swc_AUXC__ARID_DEF_arg->t_wait = 0.0F;
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S23>/timed_delay'
 *    '<S21>/timed_delay'
 *    '<S46>/timed_delay'
 *    '<S55>/timed_delay'
 *    '<S56>/timed_delay'
 *    '<S57>/timed_delay'
 *    '<S58>/timed_delay'
 *    '<S59>/timed_delay'
 *    '<S60>/timed_delay'
 *    '<S62>/timed_delay'
 *    '<S63>/timed_delay'
 */
static void swc_AUXC_timed_delay(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_timed_delay_swc_AUXC_T
  *swc_AUXC__ARID_DEF_arg)
{
  /* Chart: '<S23>/timed_delay' */
  if (swc_AUXC__ARID_DEF_arg->is_active_c14_Ricardo_SW_dev_li == 0U) {
    swc_AUXC__ARID_DEF_arg->is_active_c14_Ricardo_SW_dev_li = 1U;
    if (rtu_flg_in) {
      swc_AUXC__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_AUXC_IN_ON;
      *rty_flg_out = true;
    } else {
      swc_AUXC__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_AUXC_IN_OFF;
      *rty_flg_out = false;
    }
  } else {
    switch (swc_AUXC__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib) {
     case swc_AUXC_IN_OFF:
      if (rtu_flg_in) {
        if (rtu_t_delay_on == 0.0F) {
          swc_AUXC__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_AUXC_IN_ON;
          *rty_flg_out = true;
        } else {
          swc_AUXC__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib =
            swc_AUXC_IN_ON_WAIT;
          swc_AUXC__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = false;
        }
      } else {
        *rty_flg_out = false;
      }
      break;

     case swc_AUXC_IN_ON:
      if (!rtu_flg_in) {
        swc_AUXC__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_AUXC_IN_OFF;
        *rty_flg_out = false;
      } else {
        *rty_flg_out = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtu_flg_in) {
        swc_AUXC__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_AUXC_IN_OFF;
        *rty_flg_out = false;
      } else if (swc_AUXC__ARID_DEF_arg->t_wait > rtu_t_delay_on - rtu_t_step) {
        swc_AUXC__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_AUXC_IN_ON;
        *rty_flg_out = true;
      } else {
        swc_AUXC__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = false;
      }
      break;
    }
  }

  /* End of Chart: '<S23>/timed_delay' */
}

/*
 * System initialize for atomic system:
 *    '<S9>/turnON_delay'
 *    '<S43>/turnON_delay4'
 *    '<S44>/turnON_delay'
 *    '<S44>/turnON_delay1'
 *    '<S44>/turnON_delay10'
 *    '<S44>/turnON_delay11'
 *    '<S44>/turnON_delay12'
 *    '<S44>/turnON_delay2'
 *    '<S44>/turnON_delay4'
 *    '<S44>/turnON_delay8'
 */
static void swc_AUXC_turnON_delay_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S23>/timed_delay' */
  swc_AUXC_timed_delay_Init(rty_flg_out);
}

/*
 * System reset for atomic system:
 *    '<S9>/turnON_delay'
 *    '<S43>/turnON_delay4'
 *    '<S44>/turnON_delay'
 *    '<S44>/turnON_delay1'
 *    '<S44>/turnON_delay10'
 *    '<S44>/turnON_delay11'
 *    '<S44>/turnON_delay12'
 *    '<S44>/turnON_delay2'
 *    '<S44>/turnON_delay4'
 *    '<S44>/turnON_delay8'
 */
static void swc_AUXC_turnON_delay_Reset(boolean *rty_flg_out,
  ARID_DEF_turnON_delay_swc_AUX_T *swc_AUXC__ARID_DEF_arg)
{
  /* SystemReset for Chart: '<S23>/timed_delay' */
  swc_AUXC_timed_delay_Reset(rty_flg_out,
    &swc_AUXC__ARID_DEF_arg->ARID_DEF_timed_delay);
}

/*
 * Output and update for atomic system:
 *    '<S9>/turnON_delay'
 *    '<S43>/turnON_delay4'
 *    '<S44>/turnON_delay'
 *    '<S44>/turnON_delay1'
 *    '<S44>/turnON_delay10'
 *    '<S44>/turnON_delay11'
 *    '<S44>/turnON_delay12'
 *    '<S44>/turnON_delay2'
 *    '<S44>/turnON_delay4'
 *    '<S44>/turnON_delay8'
 */
static void swc_AUXC_turnON_delay(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnON_delay_swc_AUX_T
  *swc_AUXC__ARID_DEF_arg)
{
  /* local block i/o variables */
  float32 rtb_t_delay_on_k;
  boolean rtb_DataTypeConversion_p;

  /* DataTypeConversion: '<S23>/Data Type Conversion' */
  rtb_DataTypeConversion_p = rtu_flg_in;

  /* Saturate: '<S23>/Saturation' */
  if (rtu_t_delay_on > 1.6777216E+7F) {
    /* Saturate: '<S23>/Saturation' */
    rtb_t_delay_on_k = 1.6777216E+7F;
  } else if (rtu_t_delay_on < 0.0F) {
    /* Saturate: '<S23>/Saturation' */
    rtb_t_delay_on_k = 0.0F;
  } else {
    /* Saturate: '<S23>/Saturation' */
    rtb_t_delay_on_k = rtu_t_delay_on;
  }

  /* End of Saturate: '<S23>/Saturation' */

  /* Chart: '<S23>/timed_delay' */
  swc_AUXC_timed_delay(rtb_DataTypeConversion_p, rtb_t_delay_on_k, rtu_t_step,
                       rty_flg_out,
                       &swc_AUXC__ARID_DEF_arg->ARID_DEF_timed_delay);
}

/*
 * System initialize for atomic system:
 *    '<S10>/SR_latch'
 *    '<S3>/SR_latch'
 *    '<S44>/SR_latch3'
 */
static void swc_AUXC_SR_latch_Init(ARID_DEF_SR_latch_swc_AUXC_T
  *swc_AUXC__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S29>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/*
 * System reset for atomic system:
 *    '<S10>/SR_latch'
 *    '<S3>/SR_latch'
 *    '<S44>/SR_latch3'
 */
static void swc_AUXC_SR_latch_Reset(ARID_DEF_SR_latch_swc_AUXC_T
  *swc_AUXC__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S29>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/*
 * Output and update for atomic system:
 *    '<S10>/SR_latch'
 *    '<S3>/SR_latch'
 *    '<S44>/SR_latch3'
 */
static void swc_AUXC_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch_swc_AUXC_T *swc_AUXC__ARID_DEF_arg)
{
  /* Logic: '<S29>/Logical Operator3' incorporates:
   *  Logic: '<S29>/Logical Operator'
   *  Logic: '<S29>/Logical Operator1'
   *  UnitDelay: '<S29>/Unit Delay'
   */
  *rty_flg_out = ((swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) && (
    !rtu_flg_reset));

  /* Update for UnitDelay: '<S29>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = *rty_flg_out;
}

/*
 * System initialize for atomic system:
 *    '<S33>/timed_debounce'
 *    '<S34>/timed_debounce'
 *    '<S17>/timed_debounce'
 *    '<S18>/timed_debounce'
 *    '<S19>/timed_debounce'
 *    '<S20>/timed_debounce'
 */
static void swc_AUXC_timed_debounce_Init(boolean *rty_flg_out)
{
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S33>/timed_debounce'
 *    '<S34>/timed_debounce'
 *    '<S17>/timed_debounce'
 *    '<S18>/timed_debounce'
 *    '<S19>/timed_debounce'
 *    '<S20>/timed_debounce'
 */
static void swc_AUXC_timed_debounce(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_delay_off, float32 rtu_t_step, boolean *rty_flg_out,
  ARID_DEF_timed_debounce_swc_A_T *swc_AUXC__ARID_DEF_arg)
{
  /* Chart: '<S33>/timed_debounce' */
  if (swc_AUXC__ARID_DEF_arg->is_active_c6_Ricardo_SW_dev_lib == 0U) {
    swc_AUXC__ARID_DEF_arg->is_active_c6_Ricardo_SW_dev_lib = 1U;
    if (rtu_flg_in) {
      swc_AUXC__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib = swc_AUXC_IN_ON_n;
      *rty_flg_out = true;
    } else {
      swc_AUXC__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib = swc_AUXC_IN_OFF_j;
      *rty_flg_out = false;
    }
  } else {
    switch (swc_AUXC__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib) {
     case swc_AUXC_IN_OFF_j:
      if (rtu_flg_in) {
        if (rtu_t_delay_on == 0.0F) {
          swc_AUXC__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib = swc_AUXC_IN_ON_n;
          *rty_flg_out = true;
        } else {
          swc_AUXC__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib =
            swc_AUXC_IN_ON_WAIT_m;
          swc_AUXC__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = false;
        }
      } else {
        *rty_flg_out = false;
      }
      break;

     case swc_AUXC_IN_OFF_WAIT:
      if (rtu_flg_in) {
        swc_AUXC__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib = swc_AUXC_IN_ON_n;
        *rty_flg_out = true;
      } else if (swc_AUXC__ARID_DEF_arg->t_wait > rtu_t_delay_off - rtu_t_step)
      {
        swc_AUXC__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib = swc_AUXC_IN_OFF_j;
        *rty_flg_out = false;
      } else {
        swc_AUXC__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = true;
      }
      break;

     case swc_AUXC_IN_ON_n:
      if (!rtu_flg_in) {
        if (rtu_t_delay_off == 0.0F) {
          swc_AUXC__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib = swc_AUXC_IN_OFF_j;
          *rty_flg_out = false;
        } else {
          swc_AUXC__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib =
            swc_AUXC_IN_OFF_WAIT;
          swc_AUXC__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = true;
        }
      } else {
        *rty_flg_out = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtu_flg_in) {
        swc_AUXC__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib = swc_AUXC_IN_OFF_j;
        *rty_flg_out = false;
      } else if (swc_AUXC__ARID_DEF_arg->t_wait > rtu_t_delay_on - rtu_t_step) {
        swc_AUXC__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib = swc_AUXC_IN_ON_n;
        *rty_flg_out = true;
      } else {
        swc_AUXC__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = false;
      }
      break;
    }
  }

  /* End of Chart: '<S33>/timed_debounce' */
}

/*
 * System initialize for atomic system:
 *    '<S13>/debounce'
 *    '<S13>/debounce1'
 */
static void swc_AUXC_debounce_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S33>/timed_debounce' */
  swc_AUXC_timed_debounce_Init(rty_flg_out);
}

/*
 * Output and update for atomic system:
 *    '<S13>/debounce'
 *    '<S13>/debounce1'
 */
static void swc_AUXC_debounce(boolean rtu_flg_in, float32 rtu_t_step, boolean
  *rty_flg_out, const ConstB_debounce_swc_AUXC_T *localC,
  ARID_DEF_debounce_swc_AUXC_T *swc_AUXC__ARID_DEF_arg)
{
  /* local block i/o variables */
  boolean rtb_DataTypeConversion_h;

  /* DataTypeConversion: '<S33>/Data Type Conversion' */
  rtb_DataTypeConversion_h = rtu_flg_in;

  /* Chart: '<S33>/timed_debounce' */
  swc_AUXC_timed_debounce(rtb_DataTypeConversion_h, localC->t_delay_on,
    localC->t_delay_off, rtu_t_step, rty_flg_out,
    &swc_AUXC__ARID_DEF_arg->ARID_DEF_timed_debounce);
}

/*
 * System initialize for atomic system:
 *    '<S3>/debounce'
 *    '<S3>/debounce1'
 *    '<S3>/debounce2'
 *    '<S3>/debounce3'
 */
static void swc_AUXC_debounce_h_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S17>/timed_debounce' */
  swc_AUXC_timed_debounce_Init(rty_flg_out);
}

/*
 * Output and update for atomic system:
 *    '<S3>/debounce'
 *    '<S3>/debounce1'
 *    '<S3>/debounce2'
 *    '<S3>/debounce3'
 */
static void swc_AUXC_debounce_d(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_delay_off, float32 rtu_t_step, boolean *rty_flg_out,
  ARID_DEF_debounce_swc_AUXC_h_T *swc_AUXC__ARID_DEF_arg)
{
  /* local block i/o variables */
  float32 rtb_t_delay_on_p;
  float32 rtb_t_delay_off;
  boolean rtb_DataTypeConversion_a;

  /* DataTypeConversion: '<S17>/Data Type Conversion' */
  rtb_DataTypeConversion_a = rtu_flg_in;

  /* Saturate: '<S17>/Saturation' */
  if (rtu_t_delay_on > 1.6777216E+7F) {
    /* Saturate: '<S17>/Saturation' */
    rtb_t_delay_on_p = 1.6777216E+7F;
  } else if (rtu_t_delay_on < 0.0F) {
    /* Saturate: '<S17>/Saturation' */
    rtb_t_delay_on_p = 0.0F;
  } else {
    /* Saturate: '<S17>/Saturation' */
    rtb_t_delay_on_p = rtu_t_delay_on;
  }

  /* End of Saturate: '<S17>/Saturation' */

  /* Saturate: '<S17>/Saturation1' */
  if (rtu_t_delay_off > 1.6777216E+7F) {
    /* Saturate: '<S17>/Saturation1' */
    rtb_t_delay_off = 1.6777216E+7F;
  } else if (rtu_t_delay_off < 0.0F) {
    /* Saturate: '<S17>/Saturation1' */
    rtb_t_delay_off = 0.0F;
  } else {
    /* Saturate: '<S17>/Saturation1' */
    rtb_t_delay_off = rtu_t_delay_off;
  }

  /* End of Saturate: '<S17>/Saturation1' */

  /* Chart: '<S17>/timed_debounce' */
  swc_AUXC_timed_debounce(rtb_DataTypeConversion_a, rtb_t_delay_on_p,
    rtb_t_delay_off, rtu_t_step, rty_flg_out,
    &swc_AUXC__ARID_DEF_arg->ARID_DEF_timed_debounce);
}

/* System initialize for atomic system: '<S43>/SR_latch4' */
static void swc_AUXC_SR_latch4_Init(ARID_DEF_SR_latch_swc_AUXC_n_T
  *swc_AUXC__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S45>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/* System reset for atomic system: '<S43>/SR_latch4' */
static void swc_AUXC_SR_latch4_Reset(ARID_DEF_SR_latch_swc_AUXC_n_T
  *swc_AUXC__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S45>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/* Output and update for atomic system: '<S43>/SR_latch4' */
static void swc_AUXC_SR_latch4(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_AUXC_n_T *swc_AUXC__ARID_DEF_arg)
{
  /* Logic: '<S45>/Logical Operator3' incorporates:
   *  Logic: '<S45>/Logical Operator'
   *  Logic: '<S45>/Logical Operator1'
   *  UnitDelay: '<S45>/Unit Delay'
   */
  brpd_b_VacPumpRlyFlt = ((swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE ||
    rtu_flg_set) && (!rtu_flg_reset));

  /* Update for UnitDelay: '<S45>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = brpd_b_VacPumpRlyFlt;
}

/* System initialize for atomic system: '<S44>/SR_latch1' */
static void swc_AUXC_SR_latch1_Init(ARID_DEF_SR_latch_swc_AUXC_f_T
  *swc_AUXC__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S49>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/* System reset for atomic system: '<S44>/SR_latch1' */
static void swc_AUXC_SR_latch1_Reset(ARID_DEF_SR_latch_swc_AUXC_f_T
  *swc_AUXC__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S49>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/* Output and update for atomic system: '<S44>/SR_latch1' */
static void swc_AUXC_SR_latch1(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_AUXC_f_T *swc_AUXC__ARID_DEF_arg)
{
  /* Logic: '<S49>/Logical Operator3' incorporates:
   *  Logic: '<S49>/Logical Operator'
   *  Logic: '<S49>/Logical Operator1'
   *  UnitDelay: '<S49>/Unit Delay'
   */
  brpd_b_VacPumpSnrFlt = ((swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE ||
    rtu_flg_set) && (!rtu_flg_reset));

  /* Update for UnitDelay: '<S49>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = brpd_b_VacPumpSnrFlt;
}

/* System initialize for atomic system: '<S44>/SR_latch2' */
static void swc_AUXC_SR_latch2_Init(ARID_DEF_SR_latch_swc_AUXC_p_T
  *swc_AUXC__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S50>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/* System reset for atomic system: '<S44>/SR_latch2' */
static void swc_AUXC_SR_latch2_Reset(ARID_DEF_SR_latch_swc_AUXC_p_T
  *swc_AUXC__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S50>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/* Output and update for atomic system: '<S44>/SR_latch2' */
static void swc_AUXC_SR_latch2(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_AUXC_p_T *swc_AUXC__ARID_DEF_arg)
{
  /* Logic: '<S50>/Logical Operator3' incorporates:
   *  Logic: '<S50>/Logical Operator'
   *  Logic: '<S50>/Logical Operator1'
   *  UnitDelay: '<S50>/Unit Delay'
   */
  brpd_b_VacPumpLoPreFlt = ((swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE ||
    rtu_flg_set) && (!rtu_flg_reset));

  /* Update for UnitDelay: '<S50>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = brpd_b_VacPumpLoPreFlt;
}

/* System initialize for atomic system: '<S44>/SR_latch4' */
static void swc_AUXC_SR_latch4_a_Init(ARID_DEF_SR_latch_swc_AUXC_ff_T
  *swc_AUXC__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S52>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/* System reset for atomic system: '<S44>/SR_latch4' */
static void swc_AUXC_SR_latch4_p_Reset(ARID_DEF_SR_latch_swc_AUXC_ff_T
  *swc_AUXC__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S52>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/* Output and update for atomic system: '<S44>/SR_latch4' */
static void swc_AUXC_SR_latch4_c(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_AUXC_ff_T *swc_AUXC__ARID_DEF_arg)
{
  /* Logic: '<S52>/Logical Operator3' incorporates:
   *  Logic: '<S52>/Logical Operator'
   *  Logic: '<S52>/Logical Operator1'
   *  UnitDelay: '<S52>/Unit Delay'
   */
  brpd_b_VacPumpEnOvrTmLoPreFlt = ((swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE ||
    rtu_flg_set) && (!rtu_flg_reset));

  /* Update for UnitDelay: '<S52>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = brpd_b_VacPumpEnOvrTmLoPreFlt;
}

/* System initialize for atomic system: '<S44>/SR_latch5' */
static void swc_AUXC_SR_latch5_Init(ARID_DEF_SR_latch_swc_AUXC_b_T
  *swc_AUXC__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S53>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/* System reset for atomic system: '<S44>/SR_latch5' */
static void swc_AUXC_SR_latch5_Reset(ARID_DEF_SR_latch_swc_AUXC_b_T
  *swc_AUXC__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S53>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/* Output and update for atomic system: '<S44>/SR_latch5' */
static void swc_AUXC_SR_latch5(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_AUXC_b_T *swc_AUXC__ARID_DEF_arg)
{
  /* Logic: '<S53>/Logical Operator3' incorporates:
   *  Logic: '<S53>/Logical Operator'
   *  Logic: '<S53>/Logical Operator1'
   *  UnitDelay: '<S53>/Unit Delay'
   */
  brpd_b_VacPumpSysFailFlt = ((swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE ||
    rtu_flg_set) && (!rtu_flg_reset));

  /* Update for UnitDelay: '<S53>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = brpd_b_VacPumpSysFailFlt;
}

/* System initialize for atomic system: '<S44>/SR_latch6' */
static void swc_AUXC_SR_latch6_Init(ARID_DEF_SR_latch_swc_AUXC_p5_T
  *swc_AUXC__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S54>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/* System reset for atomic system: '<S44>/SR_latch6' */
static void swc_AUXC_SR_latch6_Reset(ARID_DEF_SR_latch_swc_AUXC_p5_T
  *swc_AUXC__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S54>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/* Output and update for atomic system: '<S44>/SR_latch6' */
static void swc_AUXC_SR_latch6(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_AUXC_p5_T *swc_AUXC__ARID_DEF_arg)
{
  /* Logic: '<S54>/Logical Operator3' incorporates:
   *  Logic: '<S54>/Logical Operator'
   *  Logic: '<S54>/Logical Operator1'
   *  UnitDelay: '<S54>/Unit Delay'
   */
  brpd_b_VacPumpEnOvrTmHiPreFlt = ((swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE ||
    rtu_flg_set) && (!rtu_flg_reset));

  /* Update for UnitDelay: '<S54>/Unit Delay' */
  swc_AUXC__ARID_DEF_arg->UnitDelay_DSTATE = brpd_b_VacPumpEnOvrTmHiPreFlt;
}

/* Function for Chart: '<S3>/BrkVacPmpMode_Cal1' */
static void swc_AUXC_VacPmp_NrmMdWrk1(uint8 *vcu_b_BrkVacPmpMode, const boolean *
  Delay)
{
  if (*Delay) {
    if (swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1 == swc_AUXC_IN_VacPmp_On) {
      swc_AUXC_ARID_DEF.Local_Timer = 0U;
      swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1 = swc_AUXC_IN_NO_ACTIVE_CHILD_h;
    } else {
      swc_AUXC_ARID_DEF.is_VacPmp_OverTime2 = swc_AUXC_IN_NO_ACTIVE_CHILD_h;
      swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1 = swc_AUXC_IN_NO_ACTIVE_CHILD_h;
    }

    swc_AUXC_ARID_DEF.is_c190_brp = swc_AUXC_IN_VacPmp_SftyMdWrk1;
    swc_AUXC_ARID_DEF.is_VacPmp_SftyMdWrk1 = swc_AUXC_IN_VacPmp_SftyMdWrkOff;
    *vcu_b_BrkVacPmpMode = 0U;
    swc_AUXC_ARID_DEF.Timer = 0U;
  } else if (!swc_AUXC_ARID_DEF.flg_out) {
    if (swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1 == swc_AUXC_IN_VacPmp_On) {
      swc_AUXC_ARID_DEF.Local_Timer = 0U;
      swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1 = swc_AUXC_IN_NO_ACTIVE_CHILD_h;
    } else {
      swc_AUXC_ARID_DEF.is_VacPmp_OverTime2 = swc_AUXC_IN_NO_ACTIVE_CHILD_h;
      swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1 = swc_AUXC_IN_NO_ACTIVE_CHILD_h;
    }

    swc_AUXC_ARID_DEF.is_c190_brp = swc_AUXC_IN_VacPmp_InitMdWrk;
    swc_AUXC_ARID_DEF.is_VacPmp_InitMdWrk = swc_AUXC_IN_VacPmp_On;
    *vcu_b_BrkVacPmpMode = 1U;
    swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 0U;
    swc_AUXC_ARID_DEF.Timer = 0U;
  } else {
    switch (swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1) {
     case swc_AUXC_IN_VacPmp_Off:
      *vcu_b_BrkVacPmpMode = 0U;
      swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 0U;

      /* Constant: '<S3>/Constant' */
      if (brpd_x_PFactor > brpc_x_brkVacPmpOpnThr_pct) {
        swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1 = swc_AUXC_IN_VacPmp_On;
        *vcu_b_BrkVacPmpMode = 1U;
        swc_AUXC_ARID_DEF.Local_Timer = 0U;
      }
      break;

     case swc_AUXC_IN_VacPmp_On:
      {
        *vcu_b_BrkVacPmpMode = 1U;
        swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 0U;

        /* Constant: '<S3>/Constant1' incorporates:
         *  Constant: '<S3>/Constant'
         *  Constant: '<S3>/Constant11'
         */
        if (brpd_x_PFactor <= brpc_x_brkVacPmpClsdThr_pct) {
          swc_AUXC_ARID_DEF.Local_Timer = 0U;
          swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1 = swc_AUXC_IN_VacPmp_Off;
          *vcu_b_BrkVacPmpMode = 0U;
        } else if ((brpd_x_PFactor <= brpc_x_brkVacPmpOpnThr_pct) &&
                   (brpd_x_PFactor > brpc_x_brkVacPmpClsdThr_pct) &&
                   (swc_AUXC_ARID_DEF.Local_Timer >= 4500)) {
          swc_AUXC_ARID_DEF.Local_Timer = 0U;
          swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1 = swc_AUXC_IN_VacPmp_OverTime1;
          *vcu_b_BrkVacPmpMode = 0U;
          swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 1U;
          swc_AUXC_ARID_DEF.Timer = 0U;
        } else if ((brpd_x_PFactor <= brpc_x_brkVacPmpPresLowlim_pct) &&
                   (brpd_x_PFactor > brpc_x_brkVacPmpOpnThr_pct) &&
                   (swc_AUXC_ARID_DEF.Local_Timer >= 4500)) {
          swc_AUXC_ARID_DEF.Local_Timer = 0U;
          swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1 = swc_AUXC_IN_VacPmp_OverTime2;
          swc_AUXC_ARID_DEF.is_VacPmp_OverTime2 =
            swc_AUXC_IN_VacPmp_SftyMdWrkOff;
          *vcu_b_BrkVacPmpMode = 0U;
          swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 2U;
          swc_AUXC_ARID_DEF.Timer = 0U;
        } else {
          sint32 tmp;
          tmp = swc_AUXC_ARID_DEF.Local_Timer + 1;
          if (swc_AUXC_ARID_DEF.Local_Timer + 1 > 65535) {
            tmp = 65535;
          }

          swc_AUXC_ARID_DEF.Local_Timer = (uint16)tmp;
          if (swc_AUXC_ARID_DEF.Local_Timer > 4500) {
            swc_AUXC_ARID_DEF.Local_Timer = 4500U;
          }
        }
      }
      break;

     case swc_AUXC_IN_VacPmp_OverTime1:
      {
        *vcu_b_BrkVacPmpMode = 0U;
        swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 1U;

        /* Constant: '<S3>/Constant1' incorporates:
         *  Constant: '<S3>/Constant'
         */
        if (brpd_x_PFactor <= brpc_x_brkVacPmpClsdThr_pct) {
          swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1 = swc_AUXC_IN_VacPmp_Off;
          *vcu_b_BrkVacPmpMode = 0U;
          swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 0U;
        } else if (brpd_x_PFactor > brpc_x_brkVacPmpOpnThr_pct) {
          swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1 = swc_AUXC_IN_VacPmp_OverTime3;
          swc_AUXC_ARID_DEF.Timer = 0U;
          *vcu_b_BrkVacPmpMode = 1U;
        } else {
          sint32 tmp;
          tmp = swc_AUXC_ARID_DEF.Timer + 1;
          if (swc_AUXC_ARID_DEF.Timer + 1 > 65535) {
            tmp = 65535;
          }

          swc_AUXC_ARID_DEF.Timer = (uint16)tmp;
        }
      }
      break;

     case swc_AUXC_IN_VacPmp_OverTime2:
      /* Constant: '<S3>/Constant' */
      if (brpd_x_PFactor <= brpc_x_brkVacPmpOpnThr_pct) {
        swc_AUXC_ARID_DEF.is_VacPmp_OverTime2 = swc_AUXC_IN_NO_ACTIVE_CHILD_h;
        swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1 = swc_AUXC_IN_VacPmp_OverTime3;
        swc_AUXC_ARID_DEF.Timer = 0U;
        *vcu_b_BrkVacPmpMode = 1U;
      } else if (brpd_x_PFactor <= brpc_x_brkVacPmpOpnThr_pct) {
        swc_AUXC_ARID_DEF.is_VacPmp_OverTime2 = swc_AUXC_IN_NO_ACTIVE_CHILD_h;
        swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1 = swc_AUXC_IN_VacPmp_On;
        *vcu_b_BrkVacPmpMode = 1U;
        swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 0U;
        swc_AUXC_ARID_DEF.Local_Timer = 0U;
      } else if (swc_AUXC_ARID_DEF.is_VacPmp_OverTime2 ==
                 swc_AUXC_IN_VacPmp_SftyMdWrkOff) {
        *vcu_b_BrkVacPmpMode = 0U;
        swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 2U;
        if (swc_AUXC_ARID_DEF.Timer > 500) {
          swc_AUXC_ARID_DEF.is_VacPmp_OverTime2 = swc_AUXC_IN_VacPmp_SftyMdWrkOn;
          swc_AUXC_ARID_DEF.Timer = 0U;
          *vcu_b_BrkVacPmpMode = 1U;
        } else {
          swc_AUXC_ARID_DEF.Timer++;
        }
      } else {
        /* case IN_VacPmp_SftyMdWrkOn: */
        *vcu_b_BrkVacPmpMode = 1U;
        swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 2U;
        if (swc_AUXC_ARID_DEF.Timer > 1500) {
          swc_AUXC_ARID_DEF.is_VacPmp_OverTime2 =
            swc_AUXC_IN_VacPmp_SftyMdWrkOff;
          *vcu_b_BrkVacPmpMode = 0U;
          swc_AUXC_ARID_DEF.Timer = 0U;
        } else {
          swc_AUXC_ARID_DEF.Timer++;
        }
      }
      break;

     default:
      {
        /* case IN_VacPmp_OverTime3: */
        *vcu_b_BrkVacPmpMode = 1U;

        /* Constant: '<S3>/Constant' incorporates:
         *  Constant: '<S3>/Constant1'
         *  Constant: '<S3>/Constant11'
         */
        if ((brpd_x_PFactor <= brpc_x_brkVacPmpOpnThr_pct) && (brpd_x_PFactor >
             brpc_x_brkVacPmpClsdThr_pct) && (swc_AUXC_ARID_DEF.Timer >= 4500))
        {
          swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1 = swc_AUXC_IN_VacPmp_OverTime1;
          *vcu_b_BrkVacPmpMode = 0U;
          swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 1U;
          swc_AUXC_ARID_DEF.Timer = 0U;
        } else if (brpd_x_PFactor <= brpc_x_brkVacPmpClsdThr_pct) {
          swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1 = swc_AUXC_IN_VacPmp_Off;
          *vcu_b_BrkVacPmpMode = 0U;
          swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 0U;
        } else if ((brpd_x_PFactor <= brpc_x_brkVacPmpPresLowlim_pct) &&
                   (brpd_x_PFactor > brpc_x_brkVacPmpOpnThr_pct) &&
                   (swc_AUXC_ARID_DEF.Timer >= 4500)) {
          swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1 = swc_AUXC_IN_VacPmp_OverTime2;
          swc_AUXC_ARID_DEF.is_VacPmp_OverTime2 =
            swc_AUXC_IN_VacPmp_SftyMdWrkOff;
          *vcu_b_BrkVacPmpMode = 0U;
          swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 2U;
          swc_AUXC_ARID_DEF.Timer = 0U;
        } else {
          sint32 tmp;
          tmp = swc_AUXC_ARID_DEF.Timer + 1;
          if (swc_AUXC_ARID_DEF.Timer + 1 > 65535) {
            tmp = 65535;
          }

          swc_AUXC_ARID_DEF.Timer = (uint16)tmp;
        }
      }
      break;
    }
  }
}

/* System initialize for function-call system: '<S1>/BRP_BrakeVacuumPumpControl' */
static void BRP_BrakeVacuumPumpControl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_flg_out_a;
  boolean rtb_flg_out_j;
  boolean rtb_flg_out_o;
  boolean rtb_flg_out_jv;
  boolean rtb_flg_out_b;
  boolean rtb_flg_out_jx;
  boolean rtb_flg_out_d;
  boolean rtb_flg_out_bz;
  boolean rtb_flg_out_n;
  boolean rtb_flg_out_on;
  boolean rtb_flg_out_p;
  boolean rtb_flg_out_m;
  boolean rtb_flg_out_e;
  boolean rtb_flg_out_nq;
  boolean rtb_flg_out_pq;
  boolean rtb_flg_out_i;
  sint32 i;

  /* SystemInitialize for Atomic SubSystem: '<S10>/SR_latch' */
  swc_AUXC_SR_latch_Init(&swc_AUXC_ARID_DEF.ARID_DEF_SR_latch_b);

  /* End of SystemInitialize for SubSystem: '<S10>/SR_latch' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/SR_latch' */
  swc_AUXC_SR_latch_Init(&swc_AUXC_ARID_DEF.ARID_DEF_SR_latch);

  /* End of SystemInitialize for SubSystem: '<S3>/SR_latch' */

  /* SystemInitialize for Atomic SubSystem: '<S9>/turnON_delay' */
  swc_AUXC_turnON_delay_Init(&rtb_flg_out_i);

  /* End of SystemInitialize for SubSystem: '<S9>/turnON_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/turnON_delay' */
  /* SystemInitialize for Chart: '<S21>/timed_delay' */
  swc_AUXC_timed_delay_Init(&swc_AUXC_ARID_DEF.flg_out);

  /* End of SystemInitialize for SubSystem: '<S3>/turnON_delay' */

  /* SystemInitialize for Enabled SubSystem: '<S3>/BrkVacPmp_ErrCalc' */
  /* SystemInitialize for Atomic SubSystem: '<S13>/debounce' */
  swc_AUXC_debounce_Init(&rtb_flg_out_pq);

  /* End of SystemInitialize for SubSystem: '<S13>/debounce' */

  /* SystemInitialize for Atomic SubSystem: '<S13>/debounce1' */
  swc_AUXC_debounce_Init(&rtb_flg_out_nq);

  /* End of SystemInitialize for SubSystem: '<S13>/debounce1' */
  /* End of SystemInitialize for SubSystem: '<S3>/BrkVacPmp_ErrCalc' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/debounce' */
  swc_AUXC_debounce_h_Init(&rtb_flg_out_e);

  /* End of SystemInitialize for SubSystem: '<S3>/debounce' */

  /* SystemInitialize for SignalConversion: '<S3>/Signal Conversion2' */
  brpd_b_airTankFlt = rtb_flg_out_e;

  /* SystemInitialize for Atomic SubSystem: '<S3>/debounce1' */
  swc_AUXC_debounce_h_Init(&rtb_flg_out_m);

  /* End of SystemInitialize for SubSystem: '<S3>/debounce1' */

  /* SystemInitialize for SignalConversion: '<S3>/Signal Conversion3' */
  brpd_b_airTankPresLow = rtb_flg_out_m;

  /* SystemInitialize for Atomic SubSystem: '<S3>/debounce2' */
  swc_AUXC_debounce_h_Init(&rtb_flg_out_p);

  /* End of SystemInitialize for SubSystem: '<S3>/debounce2' */

  /* SystemInitialize for SignalConversion: '<S3>/Signal Conversion4' */
  brpd_b_airTankPresLowInhDrv = rtb_flg_out_p;

  /* SystemInitialize for Atomic SubSystem: '<S3>/debounce3' */
  swc_AUXC_debounce_h_Init(&rtb_flg_out_on);

  /* End of SystemInitialize for SubSystem: '<S3>/debounce3' */

  /* SystemInitialize for SignalConversion: '<S3>/Signal Conversion5' */
  brpd_b_airTankPresLowEVDis = rtb_flg_out_on;

  /* SystemInitialize for Enabled SubSystem: '<S2>/VacuumPumpControlByPMS' */
  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
  swc_AUXC_ARID_DEF.UnitDelay_DSTATE = ((uint8)0U);
  for (i = 0; i < 100; i++) {
    /* InitializeConditions for Delay: '<S44>/Delay' */
    swc_AUXC_ARID_DEF.Delay_DSTATE[i] = 0.0F;

    /* InitializeConditions for Delay: '<S44>/Delay1' */
    swc_AUXC_ARID_DEF.Delay1_DSTATE[i] = 0.0F;
  }

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay1' */
  swc_AUXC_ARID_DEF.UnitDelay1_DSTATE_h = false;

  /* SystemInitialize for Atomic SubSystem: '<S44>/turnON_delay' */
  swc_AUXC_turnON_delay_Init(&rtb_flg_out_bz);

  /* End of SystemInitialize for SubSystem: '<S44>/turnON_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S44>/turnON_delay1' */
  swc_AUXC_turnON_delay_Init(&rtb_flg_out_d);

  /* End of SystemInitialize for SubSystem: '<S44>/turnON_delay1' */

  /* SystemInitialize for Atomic SubSystem: '<S44>/SR_latch1' */
  swc_AUXC_SR_latch1_Init(&swc_AUXC_ARID_DEF.ARID_DEF_SR_latch1);

  /* End of SystemInitialize for SubSystem: '<S44>/SR_latch1' */

  /* SystemInitialize for Atomic SubSystem: '<S44>/turnON_delay11' */
  swc_AUXC_turnON_delay_Init(&rtb_flg_out_b);

  /* End of SystemInitialize for SubSystem: '<S44>/turnON_delay11' */

  /* SystemInitialize for Atomic SubSystem: '<S44>/turnON_delay12' */
  swc_AUXC_turnON_delay_Init(&rtb_flg_out_jv);

  /* End of SystemInitialize for SubSystem: '<S44>/turnON_delay12' */

  /* SystemInitialize for Atomic SubSystem: '<S44>/SR_latch3' */
  swc_AUXC_SR_latch_Init(&swc_AUXC_ARID_DEF.ARID_DEF_SR_latch3);

  /* End of SystemInitialize for SubSystem: '<S44>/SR_latch3' */

  /* SystemInitialize for Atomic SubSystem: '<S44>/turnON_delay2' */
  swc_AUXC_turnON_delay_Init(&rtb_flg_out_o);

  /* End of SystemInitialize for SubSystem: '<S44>/turnON_delay2' */

  /* SystemInitialize for Atomic SubSystem: '<S44>/SR_latch2' */
  swc_AUXC_SR_latch2_Init(&swc_AUXC_ARID_DEF.ARID_DEF_SR_latch2);

  /* End of SystemInitialize for SubSystem: '<S44>/SR_latch2' */

  /* SystemInitialize for Atomic SubSystem: '<S44>/turnON_delay4' */
  swc_AUXC_turnON_delay_Init(&rtb_flg_out_j);

  /* End of SystemInitialize for SubSystem: '<S44>/turnON_delay4' */

  /* SystemInitialize for Atomic SubSystem: '<S44>/SR_latch4' */
  swc_AUXC_SR_latch4_a_Init(&swc_AUXC_ARID_DEF.ARID_DEF_SR_latch4);

  /* End of SystemInitialize for SubSystem: '<S44>/SR_latch4' */

  /* SystemInitialize for Atomic SubSystem: '<S44>/turnON_delay8' */
  swc_AUXC_turnON_delay_Init(&rtb_flg_out_a);

  /* End of SystemInitialize for SubSystem: '<S44>/turnON_delay8' */

  /* SystemInitialize for Atomic SubSystem: '<S44>/turnON_delay10' */
  swc_AUXC_turnON_delay_Init(&rtb_flg_out_jx);

  /* End of SystemInitialize for SubSystem: '<S44>/turnON_delay10' */

  /* SystemInitialize for Atomic SubSystem: '<S44>/SR_latch5' */
  swc_AUXC_SR_latch5_Init(&swc_AUXC_ARID_DEF.ARID_DEF_SR_latch5);

  /* End of SystemInitialize for SubSystem: '<S44>/SR_latch5' */

  /* SystemInitialize for Atomic SubSystem: '<S43>/turnON_delay4' */
  swc_AUXC_turnON_delay_Init(&rtb_flg_out_n);

  /* End of SystemInitialize for SubSystem: '<S43>/turnON_delay4' */

  /* SystemInitialize for Atomic SubSystem: '<S43>/SR_latch4' */
  swc_AUXC_SR_latch4_Init(&swc_AUXC_ARID_DEF.ARID_DEF_SR_latch4_c);

  /* End of SystemInitialize for SubSystem: '<S43>/SR_latch4' */

  /* SystemInitialize for Atomic SubSystem: '<S44>/SR_latch6' */
  swc_AUXC_SR_latch6_Init(&swc_AUXC_ARID_DEF.ARID_DEF_SR_latch6);

  /* End of SystemInitialize for SubSystem: '<S44>/SR_latch6' */
  /* End of SystemInitialize for SubSystem: '<S2>/VacuumPumpControlByPMS' */
}

/* Output and update for function-call system: '<S1>/BRP_BrakeVacuumPumpControl' */
static void swc__BRP_BrakeVacuumPumpControl(void)
{
  /* local block i/o variables */
  boolean rtb_RelationalOperator;
  boolean rtb_LogicalOperator12;
  boolean rtb_LogicalOperator16;
  boolean rtb_LogicalOperator17;
  boolean rtb_UnitDelay_o;
  boolean rtb_SignalConversion;
  boolean rtb_UnitDelay1;
  boolean rtb_UnitDelay2;
  boolean rtb_UnitDelay3;
  boolean rtb_UnitDelay4;
  boolean rtb_LogicalOperator_f;
  boolean rtb_LogicalOperator8;
  boolean rtb_LogicalOperator1_b;
  boolean rtb_RelationalOperator16;
  boolean rtb_LogicalOperator3_k;
  boolean rtb_RelationalOperator17;
  boolean rtb_RelationalOperator3_o;
  boolean rtb_LogicalOperator11_i;
  boolean rtb_LogicalOperator4_h;
  boolean rtb_LogicalOperator14_n;
  boolean rtb_LogicalOperator10_d;
  boolean rtb_LogicalOperator9_m;
  boolean rtb_LogicalOperator15_f;
  boolean rtb_LogicalOperator_j;
  boolean rtb_LogicalOperator1_p;
  boolean rtb_LogicalOperator12_d;
  boolean rtb_LogicalOperator13;
  boolean rtb_flg_out_a;
  boolean rtb_flg_out_j;
  boolean rtb_flg_out_o;
  boolean rtb_flg_out_jv;
  boolean rtb_flg_out_b;
  boolean rtb_flg_out_jx;
  boolean rtb_flg_out_d;
  boolean rtb_flg_out_bz;
  boolean rtb_LogicalOperator3_f;
  boolean rtb_flg_out_n;
  boolean rtb_DataTypeConversion_n;
  boolean rtb_flg_out_on;
  boolean rtb_flg_out_p;
  boolean rtb_flg_out_m;
  boolean rtb_flg_out_e;
  boolean rtb_LogicalOperator3_i;
  boolean rtb_LogicalOperator1_l;
  boolean rtb_LogicalOperator4_o;
  boolean rtb_BrkPresVeryLowFlg;
  boolean rtb_BrkVcmSensorErrFlg;
  boolean rtb_Compare_d;
  boolean rtb_Compare_c;
  boolean rtb_flg_out_nq;
  boolean rtb_flg_out_pq;
  boolean rtb_LogicalOperator3_n;
  boolean rtb_flg_out_i;
  float64 rtb_min;
  sint32 i;
  PmmStatus rtb_RelationalOperator_tmp;
  uint8 rtb_Relay3;
  boolean Delay;
  boolean RelationalOperator2;
  boolean rtb_LogicalOperator2_j;
  boolean rtb_LogicalOperator5;
  boolean rtb_Relay9;
  boolean rtb_Switch3;

  /* Logic: '<S3>/Logical Operator14' incorporates:
   *  Logic: '<S3>/Logical Operator11'
   */
  rtb_Switch3 = !swc_AUXC_ARID_DEF.DataTypeConversion14;

  /* Logic: '<S3>/Logical Operator5' incorporates:
   *  Logic: '<S3>/Logical Operator14'
   */
  rtb_LogicalOperator5 = (swc_AUXC_ARID_DEF.DataTypeConversion15 && rtb_Switch3);

  /* RelationalOperator: '<S10>/Relational Operator' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion12'
   *  RelationalOperator: '<S10>/Relational Operator1'
   *  RelationalOperator: '<S10>/Relational Operator2'
   *  RelationalOperator: '<S10>/Relational Operator3'
   *  RelationalOperator: '<S3>/Relational Operator2'
   */
  rtb_RelationalOperator_tmp = swc_AUXC_ARID_DEF.DataTypeConversion12;

  /* RelationalOperator: '<S10>/Relational Operator' incorporates:
   *  Constant: '<S25>/Constant'
   */
  rtb_RelationalOperator = (rtb_RelationalOperator_tmp == PmmStatus_BDCACACT);

  /* Logic: '<S10>/Logical Operator12' incorporates:
   *  Constant: '<S26>/Constant'
   *  Constant: '<S27>/Constant'
   *  Constant: '<S28>/Constant'
   *  RelationalOperator: '<S10>/Relational Operator1'
   *  RelationalOperator: '<S10>/Relational Operator2'
   *  RelationalOperator: '<S10>/Relational Operator3'
   */
  rtb_LogicalOperator12 = ((rtb_RelationalOperator_tmp ==
    PmmStatus_HVDEVICEDEACT) || (rtb_RelationalOperator_tmp ==
    PmmStatus_MAINPOSOPENEMGY) || (rtb_RelationalOperator_tmp ==
    PmmStatus_BMSNEGOPENEMGY));

  /* Outputs for Atomic SubSystem: '<S10>/SR_latch' */
  swc_AUXC_SR_latch(rtb_RelationalOperator, rtb_LogicalOperator12,
                    &rtb_LogicalOperator3_n,
                    &swc_AUXC_ARID_DEF.ARID_DEF_SR_latch_b);

  /* End of Outputs for SubSystem: '<S10>/SR_latch' */

  /* Relay: '<S3>/Relay3' */
  swc_AUXC_ARID_DEF.Relay3_Mode = ((swc_AUXC_ARID_DEF.DataTypeConversion47 >=
    brpc_v_brkPumpVehSpdHiThr_kph) || ((swc_AUXC_ARID_DEF.DataTypeConversion47 >
    brpc_v_brkPumpVehSpdLoThr_kph) && swc_AUXC_ARID_DEF.Relay3_Mode));
  if (swc_AUXC_ARID_DEF.Relay3_Mode) {
    /* Relay: '<S3>/Relay3' */
    rtb_Relay3 = ((uint8)1U);
  } else {
    /* Relay: '<S3>/Relay3' */
    rtb_Relay3 = ((uint8)0U);
  }

  /* End of Relay: '<S3>/Relay3' */

  /* Logic: '<S3>/Logical Operator15' incorporates:
   *  Logic: '<S3>/Logical Operator19'
   */
  rtb_Relay9 = !swc_AUXC_ARID_DEF.DataTypeConversion15;

  /* Logic: '<S3>/Logical Operator16' incorporates:
   *  Logic: '<S3>/Logical Operator15'
   *  Logic: '<S3>/Logical Operator4'
   */
  rtb_LogicalOperator2_j = (rtb_Switch3 && rtb_Relay9);

  /* Logic: '<S3>/Logical Operator16' */
  rtb_LogicalOperator16 = rtb_LogicalOperator2_j;

  /* Logic: '<S3>/Logical Operator17' */
  rtb_LogicalOperator17 = (swc_AUXC_ARID_DEF.DataTypeConversion14 &&
    swc_AUXC_ARID_DEF.DataTypeConversion15);

  /* Outputs for Atomic SubSystem: '<S3>/SR_latch' */
  swc_AUXC_SR_latch(rtb_LogicalOperator16, rtb_LogicalOperator17,
                    &rtb_LogicalOperator3_i,
                    &swc_AUXC_ARID_DEF.ARID_DEF_SR_latch);

  /* End of Outputs for SubSystem: '<S3>/SR_latch' */

  /* Switch: '<S3>/Switch3' incorporates:
   *  Logic: '<S3>/Logical Operator18'
   *  Switch: '<S3>/Switch4'
   */
  if (rtb_LogicalOperator5) {
    /* Switch: '<S3>/Switch3' incorporates:
     *  Constant: '<S3>/Constant8'
     */
    rtb_Switch3 = false;
  } else if (!rtb_LogicalOperator3_i) {
    /* Switch: '<S3>/Switch5' incorporates:
     *  Constant: '<S3>/Constant18'
     *  Switch: '<S3>/Switch4'
     */
    if (brpc_b_brkPumpVp2BevEnb) {
      /* Switch: '<S3>/Switch5' incorporates:
       *  Constant: '<S3>/Constant13'
       *  Constant: '<S3>/Constant15'
       *  Logic: '<S3>/Logical Operator8'
       *  Product: '<S3>/Divide2'
       *  RelationalOperator: '<S3>/Relational Operator'
       *  Sum: '<S3>/Sum3'
       */
      rtb_Switch3 = ((0.0F - 0.0F / swcauxc_apuc_fact_12vDcdcEff >
                      brpc_pwr_brkPumpPeakPwr_kW) || (rtb_Relay3 != 0));
    } else {
      /* Switch: '<S3>/Switch5' incorporates:
       *  Constant: '<S3>/Constant2'
       */
      rtb_Switch3 = true;
    }

    /* End of Switch: '<S3>/Switch5' */

    /* Switch: '<S3>/Switch3' incorporates:
     *  Logic: '<S3>/Logical Operator'
     *  Logic: '<S3>/Logical Operator7'
     *  Switch: '<S3>/Switch4'
     */
    rtb_Switch3 = ((swc_AUXC_ARID_DEF.DataTypeConversion14 ||
                    swc_AUXC_ARID_DEF.DataTypeConversion15) &&
                   rtb_LogicalOperator3_n && rtb_Switch3);
  } else {
    /* Switch: '<S3>/Switch3' incorporates:
     *  Constant: '<S3>/Constant3'
     *  Switch: '<S3>/Switch4'
     */
    rtb_Switch3 = false;
  }

  /* End of Switch: '<S3>/Switch3' */

  /* Chart: '<S3>/BDCACOnOffProtection' incorporates:
   *  Constant: '<S3>/Constant12'
   *  Constant: '<S3>/Constant4'
   *  Constant: '<S3>/Constant7'
   */
  if (swc_AUXC_ARID_DEF.is_active_c6_brp == 0U) {
    swc_AUXC_ARID_DEF.is_active_c6_brp = 1U;
    swc_AUXC_ARID_DEF.is_c6_brp = swc_AUXC_IN_INIT;
    swc_AUXC_ARID_DEF.T = 0.0F;
    swc_AUXC_ARID_DEF.bdcacEna = false;
    swc_AUXC_ARID_DEF.bdcacWrkTmOut = false;
  } else {
    boolean guard1 = false;
    guard1 = false;
    switch (swc_AUXC_ARID_DEF.is_c6_brp) {
     case swc_AUXC_IN_INIT:
      if (rtb_Switch3 && swc_AUXC_ARID_DEF.DataTypeConversion17) {
        swc_AUXC_ARID_DEF.is_c6_brp = swc_AUXC_IN_On;
        swc_AUXC_ARID_DEF.T = 0.0F;
        swc_AUXC_ARID_DEF.bdcacEna = true;
        swc_AUXC_ARID_DEF.bdcacWrkTmOut = false;
      } else {
        swc_AUXC_ARID_DEF.bdcacEna = false;
        swc_AUXC_ARID_DEF.bdcacWrkTmOut = false;
      }
      break;

     case swc_AUXC_IN_Off:
      if ((!swc_AUXC_ARID_DEF.DataTypeConversion17) || ((swc_AUXC_ARID_DEF.T >
            brpc_t_brkPumpRstLim2_s) && (!swc_AUXC_ARID_DEF.bdcacWrkTmOut)) ||
          (swc_AUXC_ARID_DEF.T > brpc_t_brkPumpRstLim1_s)) {
        swc_AUXC_ARID_DEF.is_c6_brp = swc_AUXC_IN_Off2On;
        swc_AUXC_ARID_DEF.T = 0.0F;
        swc_AUXC_ARID_DEF.bdcacEna = false;
      } else {
        swc_AUXC_ARID_DEF.T += ((float32)BRP_TASK_INTERVAL_S);
      }
      break;

     case swc_AUXC_IN_Off2On:
      if (!swc_AUXC_ARID_DEF.DataTypeConversion17) {
        swc_AUXC_ARID_DEF.is_c6_brp = swc_AUXC_IN_INIT;
        swc_AUXC_ARID_DEF.T = 0.0F;
        swc_AUXC_ARID_DEF.bdcacEna = false;
        swc_AUXC_ARID_DEF.bdcacWrkTmOut = false;
      } else if (rtb_Switch3 && swc_AUXC_ARID_DEF.DataTypeConversion17) {
        swc_AUXC_ARID_DEF.is_c6_brp = swc_AUXC_IN_On;
        swc_AUXC_ARID_DEF.T = 0.0F;
        swc_AUXC_ARID_DEF.bdcacEna = true;
        swc_AUXC_ARID_DEF.bdcacWrkTmOut = false;
      } else {
        swc_AUXC_ARID_DEF.bdcacEna = false;
      }
      break;

     default:
      /* case IN_On: */
      if ((!rtb_Switch3) || (!swc_AUXC_ARID_DEF.DataTypeConversion17)) {
        guard1 = true;
      } else if (swc_AUXC_ARID_DEF.T > brpc_t_brkPumpOnLim_s) {
        swc_AUXC_ARID_DEF.bdcacWrkTmOut = true;
        guard1 = true;
      } else {
        swc_AUXC_ARID_DEF.T += ((float32)BRP_TASK_INTERVAL_S);
      }
      break;
    }

    if (guard1) {
      swc_AUXC_ARID_DEF.is_c6_brp = swc_AUXC_IN_Off;
      swc_AUXC_ARID_DEF.T = 0.0F;
      swc_AUXC_ARID_DEF.bdcacEna = false;
    }
  }

  /* End of Chart: '<S3>/BDCACOnOffProtection' */

  /* SignalConversion: '<S3>/Signal Conversion6' */
  brpd_b_bdcacEna = swc_AUXC_ARID_DEF.bdcacEna;

  /* UnitDelay: '<S9>/Unit Delay' */
  rtb_UnitDelay_o = swc_AUXC_ARID_DEF.UnitDelay_DSTATE_e;

  /* Outputs for Atomic SubSystem: '<S9>/turnON_delay' */
  /* Constant: '<S9>/Constant5' incorporates:
   *  Constant: '<S9>/Constant4'
   */
  swc_AUXC_turnON_delay(rtb_UnitDelay_o, brpc_tm_bdcacTimeOut_s, ((float32)
    BRP_TASK_INTERVAL_S), &rtb_flg_out_i,
                        &swc_AUXC_ARID_DEF.ARID_DEF_turnON_delay_p);

  /* End of Outputs for SubSystem: '<S9>/turnON_delay' */

  /* Logic: '<S22>/Logic7164' incorporates:
   *  UnitDelay: '<S22>/UnitDelay1467'
   */
  rtb_Switch3 = (rtb_flg_out_i || swc_AUXC_ARID_DEF.UnitDelay1467_DSTATE);

  /* Logic: '<S9>/Logical Operator3' incorporates:
   *  Constant: '<S9>/Constant6'
   */
  brpd_b_bdcacTmOut = (rtb_Switch3 && brpc_b_enbBdcacTmOut);

  /* Product: '<S3>/Divide' incorporates:
   *  Sum: '<S3>/Add'
   */
  brpd_x_PFactor = (swcauxc_brpd_p_brkVacuumPres_bar +
                    swcauxc_brpd_p_AirPres_kpa) / swcauxc_brpd_p_AirPres_kpa;

  /* RelationalOperator: '<S3>/Relational Operator2' incorporates:
   *  Constant: '<S15>/Constant'
   */
  RelationalOperator2 = (rtb_RelationalOperator_tmp == PmmStatus_CHARGE);

  /* Outputs for Atomic SubSystem: '<S3>/turnON_delay' */
  /* DataTypeConversion: '<S21>/Data Type Conversion' */
  rtb_DataTypeConversion_n = (swc_AUXC_ARID_DEF.DataTypeConversion26 != 0);

  /* Chart: '<S21>/timed_delay' incorporates:
   *  Constant: '<S3>/Constant14'
   */
  swc_AUXC_timed_delay(rtb_DataTypeConversion_n, swc_AUXC_ConstB.t_delay_on,
                       0.01F, &swc_AUXC_ARID_DEF.flg_out,
                       &swc_AUXC_ARID_DEF.ARID_DEF_timed_delay);

  /* End of Outputs for SubSystem: '<S3>/turnON_delay' */

  /* Chart: '<S3>/BrkVacPmpMode_Cal1' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Delay: '<S3>/Delay'
   */
  if (swc_AUXC_ARID_DEF.is_active_c190_brp == 0U) {
    swc_AUXC_ARID_DEF.is_active_c190_brp = 1U;
    swc_AUXC_ARID_DEF.is_c190_brp = swc_AUXC_IN_VacPmp_InitMdWrk;
    swc_AUXC_ARID_DEF.is_VacPmp_InitMdWrk = swc_AUXC_IN_VacPmp_On;
    rtb_Relay3 = 1U;
    swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 0U;
    swc_AUXC_ARID_DEF.Timer = 0U;
  } else {
    switch (swc_AUXC_ARID_DEF.is_c190_brp) {
     case swc_AUXC_IN_VacPmp_Chg:
      rtb_Relay3 = 0U;
      swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 0U;
      if (!RelationalOperator2) {
        swc_AUXC_ARID_DEF.is_c190_brp = swc_AUXC_IN_VacPmp_InitMdWrk;
        swc_AUXC_ARID_DEF.is_VacPmp_InitMdWrk = swc_AUXC_IN_VacPmp_On;
        rtb_Relay3 = 1U;
        swc_AUXC_ARID_DEF.Timer = 0U;
      }
      break;

     case swc_AUXC_IN_VacPmp_InitMdWrk:
      if (RelationalOperator2) {
        swc_AUXC_ARID_DEF.is_VacPmp_InitMdWrk = swc_AUXC_IN_NO_ACTIVE_CHILD_h;
        swc_AUXC_ARID_DEF.is_c190_brp = swc_AUXC_IN_VacPmp_Chg;
        rtb_Relay3 = 0U;
        swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 0U;
      } else if (swc_AUXC_ARID_DEF.flg_out) {
        swc_AUXC_ARID_DEF.is_VacPmp_InitMdWrk = swc_AUXC_IN_NO_ACTIVE_CHILD_h;
        swc_AUXC_ARID_DEF.is_c190_brp = swc_AUXC_IN_VacPmp_NrmMdWrk1;
        swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1 = swc_AUXC_IN_VacPmp_On;
        rtb_Relay3 = 1U;
        swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 0U;
        swc_AUXC_ARID_DEF.Local_Timer = 0U;
      } else if (swc_AUXC_ARID_DEF.is_VacPmp_InitMdWrk == swc_AUXC_IN_VacPmp_Off)
      {
        rtb_Relay3 = 0U;
        swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 0U;
        if (brpd_x_PFactor > brpc_x_brkVacPmpOpnThr_pct) {
          swc_AUXC_ARID_DEF.is_VacPmp_InitMdWrk = swc_AUXC_IN_VacPmp_On;
          rtb_Relay3 = 1U;
          swc_AUXC_ARID_DEF.Timer = 0U;
        } else {
          i = swc_AUXC_ARID_DEF.Timer + 1;
          if (swc_AUXC_ARID_DEF.Timer + 1 > 65535) {
            i = 65535;
          }

          swc_AUXC_ARID_DEF.Timer = (uint16)i;
        }
      } else {
        /* case IN_VacPmp_On: */
        rtb_Relay3 = 1U;
        swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 0U;
        if (brpd_x_PFactor <= brpc_x_brkVacPmpClsdThr_pct) {
          swc_AUXC_ARID_DEF.is_VacPmp_InitMdWrk = swc_AUXC_IN_VacPmp_Off;
          rtb_Relay3 = 0U;
          swc_AUXC_ARID_DEF.Timer = 0U;
        } else {
          i = swc_AUXC_ARID_DEF.Timer + 1;
          if (swc_AUXC_ARID_DEF.Timer + 1 > 65535) {
            i = 65535;
          }

          swc_AUXC_ARID_DEF.Timer = (uint16)i;
        }
      }
      break;

     case swc_AUXC_IN_VacPmp_NrmMdWrk1:
      swc_AUXC_VacPmp_NrmMdWrk1(&rtb_Relay3,
        &swc_AUXC_ARID_DEF.vcu_st_BrkVacPmpSftyMdWrkFlg);
      break;

     default:
      /* case IN_VacPmp_SftyMdWrk1: */
      if (!swc_AUXC_ARID_DEF.vcu_st_BrkVacPmpSftyMdWrkFlg) {
        swc_AUXC_ARID_DEF.is_VacPmp_SftyMdWrk1 = swc_AUXC_IN_NO_ACTIVE_CHILD_h;
        swc_AUXC_ARID_DEF.is_c190_brp = swc_AUXC_IN_VacPmp_NrmMdWrk1;
        swc_AUXC_ARID_DEF.is_VacPmp_NrmMdWrk1 = swc_AUXC_IN_VacPmp_On;
        rtb_Relay3 = 1U;
        swc_AUXC_ARID_DEF.vcu_st_BrkVacErr = 0U;
        swc_AUXC_ARID_DEF.Local_Timer = 0U;
      } else if (swc_AUXC_ARID_DEF.is_VacPmp_SftyMdWrk1 ==
                 swc_AUXC_IN_VacPmp_SftyMdWrkOff) {
        rtb_Relay3 = 0U;
        if (swc_AUXC_ARID_DEF.Timer > 500) {
          swc_AUXC_ARID_DEF.is_VacPmp_SftyMdWrk1 =
            swc_AUXC_IN_VacPmp_SftyMdWrkOn;
          swc_AUXC_ARID_DEF.Timer = 0U;
          rtb_Relay3 = 1U;
        } else {
          swc_AUXC_ARID_DEF.Timer++;
        }
      } else {
        /* case IN_VacPmp_SftyMdWrkOn: */
        rtb_Relay3 = 1U;
        if (swc_AUXC_ARID_DEF.Timer > 1500) {
          swc_AUXC_ARID_DEF.is_VacPmp_SftyMdWrk1 =
            swc_AUXC_IN_VacPmp_SftyMdWrkOff;
          rtb_Relay3 = 0U;
          swc_AUXC_ARID_DEF.Timer = 0U;
        } else {
          swc_AUXC_ARID_DEF.Timer++;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S3>/BrkVacPmpMode_Cal1' */

  /* RelationalOperator: '<S12>/equal' incorporates:
   *  Constant: '<S12>/On'
   */
  brpd_b_brkPmp1Rly = (rtb_Relay3 == 1.0);

  /* Delay: '<S3>/Delay1' */
  rtb_Relay3 = swc_AUXC_ARID_DEF.Delay1_DSTATE_f;

  /* Outputs for Enabled SubSystem: '<S3>/BrkVacPmp_ErrCalc' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  /* Logic: '<S3>/Logical Operator9' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S13>/Constant5'
   *  Constant: '<S14>/Constant'
   *  RelationalOperator: '<S14>/Compare'
   */
  if (swc_AUXC_ARID_DEF.flg_out && (swc_AUXC_ARID_DEF.DataTypeConversion25 ==
       ((uint8)2U))) {
    swc_AUXC_ARID_DEF.BrkVacPmp_ErrCalc_MODE = true;

    /* Logic: '<S13>/Logical Operator3' */
    Delay = !RelationalOperator2;

    /* Logic: '<S13>/Logical Operator1' incorporates:
     *  Constant: '<S32>/Lower Limit'
     *  Constant: '<S32>/Upper Limit'
     *  Logic: '<S13>/Logical Operator2'
     *  Logic: '<S32>/AND'
     *  RelationalOperator: '<S32>/Lower Test'
     *  RelationalOperator: '<S32>/Upper Test'
     */
    rtb_LogicalOperator1_l = (((brpc_u_vacsnrDwLim_V >
      swc_AUXC_ARID_DEF.DataTypeConversion44) ||
      (swc_AUXC_ARID_DEF.DataTypeConversion44 > brpc_u_vacsnrUpLim_V)) && Delay);

    /* Logic: '<S13>/Logical Operator4' incorporates:
     *  Abs: '<S13>/Abs'
     *  Constant: '<S13>/Constant1'
     *  Constant: '<S13>/Constant2'
     *  RelationalOperator: '<S13>/Relational Operator1'
     *  RelationalOperator: '<S13>/Relational Operator2'
     */
    rtb_LogicalOperator4_o = (Delay && (brpd_x_PFactor > 0.65F) && (fabsf
      (swc_AUXC_ARID_DEF.DataTypeConversion47) > 10.0F));

    /* Outputs for Atomic SubSystem: '<S13>/debounce' */
    swc_AUXC_debounce(rtb_LogicalOperator1_l, 0.01F, &rtb_flg_out_pq,
                      &swc_AUXC_ConstB.debounce_c,
                      &swc_AUXC_ARID_DEF.ARID_DEF_debounce_c);

    /* End of Outputs for SubSystem: '<S13>/debounce' */

    /* Outputs for Atomic SubSystem: '<S13>/debounce1' */
    swc_AUXC_debounce(rtb_LogicalOperator4_o, 0.01F, &rtb_flg_out_nq,
                      &swc_AUXC_ConstB.debounce1_l,
                      &swc_AUXC_ARID_DEF.ARID_DEF_debounce1_k);

    /* End of Outputs for SubSystem: '<S13>/debounce1' */

    /* Logic: '<S13>/Logical Operator5' incorporates:
     *  Constant: '<S13>/Constant'
     *  Constant: '<S13>/Constant5'
     */
    swc_AUXC_ARID_DEF.vcu_st_BrkVacPmpSftyMdWrkFlg = (rtb_flg_out_pq ||
      rtb_flg_out_nq);

    /* SignalConversion generated from: '<S13>/BrkPresVeryLowFlg' */
    rtb_BrkPresVeryLowFlg = rtb_flg_out_nq;

    /* SignalConversion generated from: '<S13>/BrkVcmSensorErrFlg' */
    rtb_BrkVcmSensorErrFlg = rtb_flg_out_pq;

    /* RelationalOperator: '<S30>/Compare' incorporates:
     *  Constant: '<S30>/Constant'
     */
    rtb_Compare_d = (rtb_Relay3 == ((uint8)1U));

    /* RelationalOperator: '<S31>/Compare' incorporates:
     *  Constant: '<S31>/Constant'
     */
    rtb_Compare_c = (rtb_Relay3 == ((uint8)2U));
  } else if (swc_AUXC_ARID_DEF.BrkVacPmp_ErrCalc_MODE) {
    /* Disable for Logic: '<S13>/Logical Operator5' incorporates:
     *  Outport: '<S13>/vcu_st_BrkVacPmpSftyMdWrkFlg'
     */
    swc_AUXC_ARID_DEF.vcu_st_BrkVacPmpSftyMdWrkFlg = false;
    swc_AUXC_ARID_DEF.BrkVacPmp_ErrCalc_MODE = false;
  }

  /* End of Logic: '<S3>/Logical Operator9' */
  /* End of Outputs for SubSystem: '<S3>/BrkVacPmp_ErrCalc' */

  /* Relay: '<S3>/Relay4' */
  swc_AUXC_ARID_DEF.Relay4_Mode = ((brpd_x_PFactor >= brpc_p_brkVacuumHiThr_bar)
    || ((brpd_x_PFactor > brpc_p_brkVacuumLoThr_bar) &&
        swc_AUXC_ARID_DEF.Relay4_Mode));
  if (swc_AUXC_ARID_DEF.Relay4_Mode) {
    /* Relay: '<S3>/Relay4' */
    rtb_Relay3 = ((uint8)1U);
  } else {
    /* Relay: '<S3>/Relay4' */
    rtb_Relay3 = ((uint8)0U);
  }

  /* End of Relay: '<S3>/Relay4' */

  /* Logic: '<S3>/Logical Operator2' incorporates:
   *  Logic: '<S3>/Logical Operator3'
   */
  brpd_b_pumpRdy = ((swc_AUXC_ARID_DEF.DataTypeConversion14 && rtb_Relay9) ||
                    rtb_LogicalOperator2_j);

  /* SignalConversion: '<S3>/Signal Conversion' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  rtb_SignalConversion = (rtb_Relay3 != 0);

  /* SignalConversion: '<S3>/Signal Conversion1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  brpd_b_brkPmp2Rly = (rtb_Relay3 != 0);

  /* UnitDelay: '<S3>/Unit Delay1' */
  rtb_UnitDelay1 = swc_AUXC_ARID_DEF.UnitDelay1_DSTATE;

  /* Outputs for Atomic SubSystem: '<S3>/debounce' */
  /* Constant: '<S3>/Batt_Heat3' incorporates:
   *  Constant: '<S3>/Batt_Heat1'
   *  Constant: '<S3>/Constant5'
   */
  swc_AUXC_debounce_d(rtb_UnitDelay1, brpc_tm_airTankFltDtrmn_s,
                      brpc_tm_airTankFltRecv_s, ((float32)BRP_TASK_INTERVAL_S),
                      &rtb_flg_out_e, &swc_AUXC_ARID_DEF.ARID_DEF_debounce);

  /* End of Outputs for SubSystem: '<S3>/debounce' */

  /* SignalConversion: '<S3>/Signal Conversion2' */
  brpd_b_airTankFlt = rtb_flg_out_e;

  /* MinMax: '<S3>/min' */
  rtb_min = fmin(swc_AUXC_ARID_DEF.DataTypeConversion19,
                 swc_AUXC_ARID_DEF.DataTypeConversion20);

  /* Relay: '<S3>/Relay9' */
  swc_AUXC_ARID_DEF.Relay9_Mode = ((rtb_min >= brpc_p_airTankPresHiThr_bar) ||
    ((rtb_min > brpc_p_airTankPresLoThr_bar) && swc_AUXC_ARID_DEF.Relay9_Mode));
  if (swc_AUXC_ARID_DEF.Relay9_Mode) {
    /* Relay: '<S3>/Relay9' */
    rtb_Relay9 = false;
  } else {
    /* Relay: '<S3>/Relay9' */
    rtb_Relay9 = true;
  }

  /* End of Relay: '<S3>/Relay9' */

  /* MultiPortSwitch: '<S3>/Multiport Switch2' incorporates:
   *  Constant: '<S3>/Constant10'
   */
  if (((uint8)VEH_SWT_INF) == 0) {
    /* MultiPortSwitch: '<S3>/Multiport Switch2' */
    rtb_Relay9 = swc_AUXC_ARID_DEF.DataTypeConversion27;
  }

  /* End of MultiPortSwitch: '<S3>/Multiport Switch2' */

  /* Relay: '<S3>/Relay1' */
  swc_AUXC_ARID_DEF.Relay1_Mode = ((rtb_min >= brpc_p_airTankPresAllowDrv_bar) ||
    ((rtb_min > brpc_p_airTankPresInhDrv_bar) && swc_AUXC_ARID_DEF.Relay1_Mode));

  /* Relay: '<S3>/Relay2' */
  swc_AUXC_ARID_DEF.Relay2_Mode = ((rtb_min >= brpc_p_airTankPresEVDisHi_bar) ||
    ((rtb_min > brpc_p_airTankPresEVDisLo_bar) && swc_AUXC_ARID_DEF.Relay2_Mode));

  /* UnitDelay: '<S3>/Unit Delay2' */
  rtb_UnitDelay2 = swc_AUXC_ARID_DEF.UnitDelay2_DSTATE;

  /* Outputs for Atomic SubSystem: '<S3>/debounce1' */
  /* Constant: '<S3>/Batt_Heat4' incorporates:
   *  Constant: '<S3>/Batt_Heat2'
   *  Constant: '<S3>/Constant9'
   */
  swc_AUXC_debounce_d(rtb_UnitDelay2, brpc_tm_airTankPresLowOn_s,
                      brpc_tm_airTankPresLowOff_s, ((float32)BRP_TASK_INTERVAL_S),
                      &rtb_flg_out_m, &swc_AUXC_ARID_DEF.ARID_DEF_debounce1);

  /* End of Outputs for SubSystem: '<S3>/debounce1' */

  /* SignalConversion: '<S3>/Signal Conversion3' */
  brpd_b_airTankPresLow = rtb_flg_out_m;

  /* UnitDelay: '<S3>/Unit Delay3' */
  rtb_UnitDelay3 = swc_AUXC_ARID_DEF.UnitDelay3_DSTATE;

  /* Outputs for Atomic SubSystem: '<S3>/debounce2' */
  /* Constant: '<S3>/Batt_Heat4' incorporates:
   *  Constant: '<S3>/Batt_Heat2'
   *  Constant: '<S3>/Constant9'
   */
  swc_AUXC_debounce_d(rtb_UnitDelay3, brpc_tm_airTankPresLowOn_s,
                      brpc_tm_airTankPresLowOff_s, ((float32)BRP_TASK_INTERVAL_S),
                      &rtb_flg_out_p, &swc_AUXC_ARID_DEF.ARID_DEF_debounce2);

  /* End of Outputs for SubSystem: '<S3>/debounce2' */

  /* SignalConversion: '<S3>/Signal Conversion4' */
  brpd_b_airTankPresLowInhDrv = rtb_flg_out_p;

  /* UnitDelay: '<S3>/Unit Delay4' */
  rtb_UnitDelay4 = swc_AUXC_ARID_DEF.UnitDelay4_DSTATE;

  /* Outputs for Atomic SubSystem: '<S3>/debounce3' */
  /* Constant: '<S3>/Batt_Heat4' incorporates:
   *  Constant: '<S3>/Batt_Heat2'
   *  Constant: '<S3>/Constant9'
   */
  swc_AUXC_debounce_d(rtb_UnitDelay4, brpc_tm_airTankPresLowOn_s,
                      brpc_tm_airTankPresLowOff_s, ((float32)BRP_TASK_INTERVAL_S),
                      &rtb_flg_out_on, &swc_AUXC_ARID_DEF.ARID_DEF_debounce3);

  /* End of Outputs for SubSystem: '<S3>/debounce3' */

  /* SignalConversion: '<S3>/Signal Conversion5' */
  brpd_b_airTankPresLowEVDis = rtb_flg_out_on;

  /* Outputs for Enabled SubSystem: '<S2>/VacPumpWitchController' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S4>/Constant'
   */
  if (swc_AUXC_ARID_DEF.DataTypeConversion51 == 2.0) {
    /* SignalConversion: '<S6>/Signal Conversion' */
    swc_AUXC_ARID_DEF.brpd_b_VacTkAirPresLowFlt = 0.0;
  }

  /* End of RelationalOperator: '<S4>/Compare' */
  /* End of Outputs for SubSystem: '<S2>/VacPumpWitchController' */

  /* Outputs for Enabled SubSystem: '<S2>/VacuumPumpControlByPMS' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  /* RelationalOperator: '<S5>/Compare' incorporates:
   *  Constant: '<S43>/Constant20'
   *  Constant: '<S43>/Constant21'
   *  Constant: '<S44>/Constant12'
   *  Constant: '<S44>/Constant13'
   *  Constant: '<S44>/Constant14'
   *  Constant: '<S44>/Constant16'
   *  Constant: '<S44>/Constant2'
   *  Constant: '<S44>/Constant20'
   *  Constant: '<S44>/Constant21'
   *  Constant: '<S44>/Constant26'
   *  Constant: '<S44>/Constant27'
   *  Constant: '<S44>/Constant3'
   *  Constant: '<S44>/Constant33'
   *  Constant: '<S44>/Constant34'
   *  Constant: '<S44>/Constant37'
   *  Constant: '<S44>/Constant38'
   *  Constant: '<S44>/Constant39'
   *  Constant: '<S44>/Constant41'
   *  Constant: '<S5>/Constant'
   */
  if (swc_AUXC_ARID_DEF.DataTypeConversion51 == 1.0) {
    float32 rtb_t_delay_on;
    if (!swc_AUXC_ARID_DEF.VacuumPumpControlByPMS_MODE) {
      /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
      swc_AUXC_ARID_DEF.UnitDelay_DSTATE = ((uint8)0U);
      for (i = 0; i < 100; i++) {
        /* InitializeConditions for Delay: '<S44>/Delay' */
        swc_AUXC_ARID_DEF.Delay_DSTATE[i] = 0.0F;

        /* InitializeConditions for Delay: '<S44>/Delay1' */
        swc_AUXC_ARID_DEF.Delay1_DSTATE[i] = 0.0F;
      }

      /* InitializeConditions for UnitDelay: '<S7>/Unit Delay1' */
      swc_AUXC_ARID_DEF.UnitDelay1_DSTATE_h = false;

      /* SystemReset for Atomic SubSystem: '<S44>/turnON_delay' */
      swc_AUXC_turnON_delay_Reset(&rtb_flg_out_bz,
        &swc_AUXC_ARID_DEF.ARID_DEF_turnON_delay);

      /* End of SystemReset for SubSystem: '<S44>/turnON_delay' */

      /* SystemReset for Atomic SubSystem: '<S44>/turnON_delay1' */
      swc_AUXC_turnON_delay_Reset(&rtb_flg_out_d,
        &swc_AUXC_ARID_DEF.ARID_DEF_turnON_delay1);

      /* End of SystemReset for SubSystem: '<S44>/turnON_delay1' */

      /* SystemReset for Atomic SubSystem: '<S44>/SR_latch1' */
      swc_AUXC_SR_latch1_Reset(&swc_AUXC_ARID_DEF.ARID_DEF_SR_latch1);

      /* End of SystemReset for SubSystem: '<S44>/SR_latch1' */

      /* SystemReset for Atomic SubSystem: '<S44>/turnON_delay11' */
      swc_AUXC_turnON_delay_Reset(&rtb_flg_out_b,
        &swc_AUXC_ARID_DEF.ARID_DEF_turnON_delay11);

      /* End of SystemReset for SubSystem: '<S44>/turnON_delay11' */

      /* SystemReset for Atomic SubSystem: '<S44>/turnON_delay12' */
      swc_AUXC_turnON_delay_Reset(&rtb_flg_out_jv,
        &swc_AUXC_ARID_DEF.ARID_DEF_turnON_delay12);

      /* End of SystemReset for SubSystem: '<S44>/turnON_delay12' */

      /* SystemReset for Atomic SubSystem: '<S44>/SR_latch3' */
      swc_AUXC_SR_latch_Reset(&swc_AUXC_ARID_DEF.ARID_DEF_SR_latch3);

      /* End of SystemReset for SubSystem: '<S44>/SR_latch3' */

      /* SystemReset for Atomic SubSystem: '<S44>/turnON_delay2' */
      swc_AUXC_turnON_delay_Reset(&rtb_flg_out_o,
        &swc_AUXC_ARID_DEF.ARID_DEF_turnON_delay2);

      /* End of SystemReset for SubSystem: '<S44>/turnON_delay2' */

      /* SystemReset for Atomic SubSystem: '<S44>/SR_latch2' */
      swc_AUXC_SR_latch2_Reset(&swc_AUXC_ARID_DEF.ARID_DEF_SR_latch2);

      /* End of SystemReset for SubSystem: '<S44>/SR_latch2' */

      /* SystemReset for Atomic SubSystem: '<S44>/turnON_delay3' */
      /* SystemReset for Chart: '<S61>/timed_delay' */
      swc_AUXC_ARID_DEF.is_active_c14_Ricardo_SW_dev_li = 0U;
      swc_AUXC_ARID_DEF.is_c14_Ricardo_SW_dev_lib =
        swc_AUXC_IN_NO_ACTIVE_CHILD_h;
      swc_AUXC_ARID_DEF.t_wait = 0.0F;

      /* End of SystemReset for SubSystem: '<S44>/turnON_delay3' */

      /* SystemReset for Atomic SubSystem: '<S44>/turnON_delay4' */
      swc_AUXC_turnON_delay_Reset(&rtb_flg_out_j,
        &swc_AUXC_ARID_DEF.ARID_DEF_turnON_delay4);

      /* End of SystemReset for SubSystem: '<S44>/turnON_delay4' */

      /* SystemReset for Atomic SubSystem: '<S44>/SR_latch4' */
      swc_AUXC_SR_latch4_p_Reset(&swc_AUXC_ARID_DEF.ARID_DEF_SR_latch4);

      /* End of SystemReset for SubSystem: '<S44>/SR_latch4' */

      /* SystemReset for Atomic SubSystem: '<S44>/turnON_delay8' */
      swc_AUXC_turnON_delay_Reset(&rtb_flg_out_a,
        &swc_AUXC_ARID_DEF.ARID_DEF_turnON_delay8);

      /* End of SystemReset for SubSystem: '<S44>/turnON_delay8' */

      /* SystemReset for Atomic SubSystem: '<S44>/turnON_delay10' */
      swc_AUXC_turnON_delay_Reset(&rtb_flg_out_jx,
        &swc_AUXC_ARID_DEF.ARID_DEF_turnON_delay10);

      /* End of SystemReset for SubSystem: '<S44>/turnON_delay10' */

      /* SystemReset for Atomic SubSystem: '<S44>/SR_latch5' */
      swc_AUXC_SR_latch5_Reset(&swc_AUXC_ARID_DEF.ARID_DEF_SR_latch5);

      /* End of SystemReset for SubSystem: '<S44>/SR_latch5' */

      /* SystemReset for Chart: '<S7>/VacuumPumpEnableControl' */
      swc_AUXC_ARID_DEF.is_CycleControl = swc_AUXC_IN_NO_ACTIVE_CHILD_h;
      swc_AUXC_ARID_DEF.is_active_c3_brp = 0U;
      swc_AUXC_ARID_DEF.is_c3_brp = swc_AUXC_IN_NO_ACTIVE_CHILD_h;
      swc_AUXC_ARID_DEF.t = 0.0F;

      /* SystemReset for Atomic SubSystem: '<S43>/turnON_delay4' */
      swc_AUXC_turnON_delay_Reset(&rtb_flg_out_n,
        &swc_AUXC_ARID_DEF.ARID_DEF_turnON_delay4_m);

      /* End of SystemReset for SubSystem: '<S43>/turnON_delay4' */

      /* SystemReset for Atomic SubSystem: '<S43>/SR_latch4' */
      swc_AUXC_SR_latch4_Reset(&swc_AUXC_ARID_DEF.ARID_DEF_SR_latch4_c);

      /* End of SystemReset for SubSystem: '<S43>/SR_latch4' */

      /* SystemReset for Atomic SubSystem: '<S44>/SR_latch6' */
      swc_AUXC_SR_latch6_Reset(&swc_AUXC_ARID_DEF.ARID_DEF_SR_latch6);

      /* End of SystemReset for SubSystem: '<S44>/SR_latch6' */
      swc_AUXC_ARID_DEF.VacuumPumpControlByPMS_MODE = true;
    }

    /* RelationalOperator: '<S44>/Relational Operator18' incorporates:
     *  Constant: '<S44>/Constant7'
     *  RelationalOperator: '<S44>/Relational Operator4'
     */
    Delay = (swc_AUXC_ARID_DEF.DataTypeConversion33 > brpc_u_vacPumpPowSup_V);

    /* Logic: '<S44>/Logical Operator6' */
    RelationalOperator2 = (swc_AUXC_ARID_DEF.DataTypeConversion17 && Delay);

    /* Logic: '<S44>/Logical Operator' incorporates:
     *  Constant: '<S44>/Constant'
     *  Constant: '<S44>/Constant1'
     *  RelationalOperator: '<S44>/Relational Operator1'
     *  RelationalOperator: '<S44>/Relational Operator2'
     */
    rtb_LogicalOperator_f = ((swc_AUXC_ARID_DEF.DataTypeConversion49 <
      brpc_u_vacPumpSnrFltThdL_V) || (swc_AUXC_ARID_DEF.DataTypeConversion49 >
      brpc_u_vacPumpSnrFltThdH_V));

    /* Outputs for Atomic SubSystem: '<S44>/turnON_delay' */
    swc_AUXC_turnON_delay(rtb_LogicalOperator_f, brpc_t_vacPumpSnrFlt_s,
                          ((float32)BRP_TASK_INTERVAL_S), &rtb_flg_out_bz,
                          &swc_AUXC_ARID_DEF.ARID_DEF_turnON_delay);

    /* End of Outputs for SubSystem: '<S44>/turnON_delay' */

    /* Logic: '<S44>/Logical Operator8' incorporates:
     *  Constant: '<S44>/Constant14'
     *  Constant: '<S44>/Constant16'
     */
    rtb_LogicalOperator8 = (RelationalOperator2 && rtb_flg_out_bz);

    /* Logic: '<S44>/Logical Operator1' */
    rtb_LogicalOperator1_b = !rtb_LogicalOperator_f;

    /* Outputs for Atomic SubSystem: '<S44>/turnON_delay1' */
    swc_AUXC_turnON_delay(rtb_LogicalOperator1_b, brpc_t_vacPumpSnrFlt_s,
                          ((float32)BRP_TASK_INTERVAL_S), &rtb_flg_out_d,
                          &swc_AUXC_ARID_DEF.ARID_DEF_turnON_delay1);

    /* End of Outputs for SubSystem: '<S44>/turnON_delay1' */

    /* Outputs for Atomic SubSystem: '<S44>/SR_latch1' */
    swc_AUXC_SR_latch1(rtb_LogicalOperator8, rtb_flg_out_d,
                       &swc_AUXC_ARID_DEF.ARID_DEF_SR_latch1);

    /* End of Outputs for SubSystem: '<S44>/SR_latch1' */

    /* RelationalOperator: '<S44>/Relational Operator16' incorporates:
     *  Constant: '<S44>/Constant2'
     *  Constant: '<S44>/Constant3'
     *  Constant: '<S44>/Constant36'
     */
    rtb_RelationalOperator16 = (swc_AUXC_ARID_DEF.DataTypeConversion49 >
      brpc_u_vacPumpOn_V);

    /* Outputs for Atomic SubSystem: '<S44>/turnON_delay11' */
    swc_AUXC_turnON_delay(rtb_RelationalOperator16, brpc_t_vacPumpOnDly_s,
                          ((float32)BRP_TASK_INTERVAL_S), &rtb_flg_out_b,
                          &swc_AUXC_ARID_DEF.ARID_DEF_turnON_delay11);

    /* End of Outputs for SubSystem: '<S44>/turnON_delay11' */

    /* Logic: '<S44>/Logical Operator3' incorporates:
     *  Constant: '<S44>/Constant38'
     *  Constant: '<S44>/Constant39'
     */
    rtb_LogicalOperator3_k = (Delay && rtb_flg_out_b);

    /* RelationalOperator: '<S44>/Relational Operator17' incorporates:
     *  Constant: '<S44>/Constant40'
     */
    rtb_RelationalOperator17 = (swc_AUXC_ARID_DEF.DataTypeConversion49 <
      brpc_u_vacPumpOff_V);

    /* Outputs for Atomic SubSystem: '<S44>/turnON_delay12' */
    swc_AUXC_turnON_delay(rtb_RelationalOperator17, brpc_t_vacPumpOffDly_s,
                          ((float32)BRP_TASK_INTERVAL_S), &rtb_flg_out_jv,
                          &swc_AUXC_ARID_DEF.ARID_DEF_turnON_delay12);

    /* End of Outputs for SubSystem: '<S44>/turnON_delay12' */

    /* Outputs for Atomic SubSystem: '<S44>/SR_latch3' */
    swc_AUXC_SR_latch(rtb_LogicalOperator3_k, rtb_flg_out_jv,
                      &rtb_LogicalOperator3_f,
                      &swc_AUXC_ARID_DEF.ARID_DEF_SR_latch3);

    /* End of Outputs for SubSystem: '<S44>/SR_latch3' */

    /* SignalConversion generated from: '<S44>/SR_latch3' incorporates:
     *  Constant: '<S44>/Constant37'
     *  Constant: '<S44>/Constant41'
     */
    brpd_b_VacPumpEnReqRaw = rtb_LogicalOperator3_f;

    /* RelationalOperator: '<S44>/Relational Operator3' incorporates:
     *  Constant: '<S44>/Constant4'
     */
    rtb_RelationalOperator3_o = (swc_AUXC_ARID_DEF.DataTypeConversion49 >
      brpc_u_vacPumpLoPreFltThd_V);

    /* Outputs for Atomic SubSystem: '<S44>/turnON_delay2' */
    swc_AUXC_turnON_delay(rtb_RelationalOperator3_o, brpc_t_vacPumpLoPreFlt_s,
                          ((float32)BRP_TASK_INTERVAL_S), &rtb_flg_out_o,
                          &swc_AUXC_ARID_DEF.ARID_DEF_turnON_delay2);

    /* End of Outputs for SubSystem: '<S44>/turnON_delay2' */

    /* Logic: '<S44>/Logical Operator11' incorporates:
     *  Constant: '<S44>/Constant12'
     *  Constant: '<S44>/Constant13'
     */
    rtb_LogicalOperator11_i = (RelationalOperator2 && rtb_flg_out_o);

    /* Outputs for Atomic SubSystem: '<S44>/SR_latch2' */
    swc_AUXC_SR_latch2(rtb_LogicalOperator11_i, rtb_RelationalOperator17,
                       &swc_AUXC_ARID_DEF.ARID_DEF_SR_latch2);

    /* End of Outputs for SubSystem: '<S44>/SR_latch2' */

    /* RelationalOperator: '<S44>/Relational Operator18' incorporates:
     *  Constant: '<S44>/Constant9'
     *  UnitDelay: '<S7>/Unit Delay'
     */
    Delay = (swc_AUXC_ARID_DEF.UnitDelay_DSTATE == 1.0F);

    /* Logic: '<S44>/Logical Operator2' incorporates:
     *  Constant: '<S44>/Constant10'
     *  Constant: '<S44>/Constant11'
     *  RelationalOperator: '<S44>/Relational Operator5'
     *  RelationalOperator: '<S44>/Relational Operator6'
     */
    rtb_LogicalOperator2_j = (Delay && (swc_AUXC_ARID_DEF.DataTypeConversion49 >=
      brpc_u_vacPumpEnOvrTmL1_V) && (swc_AUXC_ARID_DEF.DataTypeConversion49 <=
      brpc_u_vacPumpEnOvrTmH1_V));

    /* Outputs for Atomic SubSystem: '<S44>/turnON_delay3' */
    /* Saturate: '<S61>/Saturation' incorporates:
     *  Constant: '<S44>/Constant15'
     */
    if (brpc_t_vacPumpEnOvrTm_s > 1.6777216E+7F) {
      /* Saturate: '<S61>/Saturation' */
      rtb_t_delay_on = 1.6777216E+7F;
    } else if (brpc_t_vacPumpEnOvrTm_s < 0.0F) {
      /* Saturate: '<S61>/Saturation' */
      rtb_t_delay_on = 0.0F;
    } else {
      /* Saturate: '<S61>/Saturation' */
      rtb_t_delay_on = brpc_t_vacPumpEnOvrTm_s;
    }

    /* End of Saturate: '<S61>/Saturation' */

    /* Chart: '<S61>/timed_delay' incorporates:
     *  Constant: '<S44>/Constant17'
     *  DataTypeConversion: '<S61>/Data Type Conversion'
     */
    if (swc_AUXC_ARID_DEF.is_active_c14_Ricardo_SW_dev_li == 0U) {
      swc_AUXC_ARID_DEF.is_active_c14_Ricardo_SW_dev_li = 1U;
      if (rtb_LogicalOperator2_j) {
        swc_AUXC_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_AUXC_IN_ON_m;
        brpd_b_VacPumpEnOvrTmHiPre = true;
      } else {
        swc_AUXC_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_AUXC_IN_OFF_i;
        brpd_b_VacPumpEnOvrTmHiPre = false;
      }
    } else {
      switch (swc_AUXC_ARID_DEF.is_c14_Ricardo_SW_dev_lib) {
       case swc_AUXC_IN_OFF_i:
        if (rtb_LogicalOperator2_j) {
          if (rtb_t_delay_on == 0.0F) {
            swc_AUXC_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_AUXC_IN_ON_m;
            brpd_b_VacPumpEnOvrTmHiPre = true;
          } else {
            swc_AUXC_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_AUXC_IN_ON_WAIT_b;
            swc_AUXC_ARID_DEF.t_wait = ((float32)BRP_TASK_INTERVAL_S);
            brpd_b_VacPumpEnOvrTmHiPre = false;
          }
        } else {
          brpd_b_VacPumpEnOvrTmHiPre = false;
        }
        break;

       case swc_AUXC_IN_ON_m:
        if (!rtb_LogicalOperator2_j) {
          swc_AUXC_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_AUXC_IN_OFF_i;
          brpd_b_VacPumpEnOvrTmHiPre = false;
        } else {
          brpd_b_VacPumpEnOvrTmHiPre = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!rtb_LogicalOperator2_j) {
          swc_AUXC_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_AUXC_IN_OFF_i;
          brpd_b_VacPumpEnOvrTmHiPre = false;
        } else if (swc_AUXC_ARID_DEF.t_wait > rtb_t_delay_on - ((float32)
                    BRP_TASK_INTERVAL_S)) {
          swc_AUXC_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_AUXC_IN_ON_m;
          brpd_b_VacPumpEnOvrTmHiPre = true;
        } else {
          swc_AUXC_ARID_DEF.t_wait += ((float32)BRP_TASK_INTERVAL_S);
          brpd_b_VacPumpEnOvrTmHiPre = false;
        }
        break;
      }
    }

    /* End of Chart: '<S61>/timed_delay' */
    /* End of Outputs for SubSystem: '<S44>/turnON_delay3' */

    /* Logic: '<S44>/Logical Operator4' incorporates:
     *  Constant: '<S44>/Constant18'
     *  Constant: '<S44>/Constant19'
     *  RelationalOperator: '<S44>/Relational Operator7'
     *  RelationalOperator: '<S44>/Relational Operator8'
     */
    rtb_LogicalOperator4_h = (Delay && (swc_AUXC_ARID_DEF.DataTypeConversion49 >
      brpc_u_vacPumpEnOvrTmL2_V) && (swc_AUXC_ARID_DEF.DataTypeConversion49 <=
      brpc_u_vacPumpEnOvrTmH2_V));

    /* Outputs for Atomic SubSystem: '<S44>/turnON_delay4' */
    swc_AUXC_turnON_delay(rtb_LogicalOperator4_h, brpc_t_vacPumpEnOvrTm_s,
                          ((float32)BRP_TASK_INTERVAL_S), &rtb_flg_out_j,
                          &swc_AUXC_ARID_DEF.ARID_DEF_turnON_delay4);

    /* End of Outputs for SubSystem: '<S44>/turnON_delay4' */

    /* Logic: '<S44>/Logical Operator14' incorporates:
     *  Constant: '<S44>/Constant20'
     *  Constant: '<S44>/Constant21'
     */
    rtb_LogicalOperator14_n = (RelationalOperator2 && rtb_flg_out_j);

    /* Outputs for Atomic SubSystem: '<S44>/SR_latch4' */
    swc_AUXC_SR_latch4_c(rtb_LogicalOperator14_n, rtb_RelationalOperator17,
                         &swc_AUXC_ARID_DEF.ARID_DEF_SR_latch4);

    /* End of Outputs for SubSystem: '<S44>/SR_latch4' */

    /* Logic: '<S44>/Logical Operator10' incorporates:
     *  Constant: '<S44>/Constant25'
     *  Constant: '<S44>/Constant31'
     *  Delay: '<S44>/Delay'
     *  RelationalOperator: '<S44>/Relational Operator11'
     *  RelationalOperator: '<S44>/Relational Operator13'
     *  Sum: '<S44>/Add'
     */
    rtb_LogicalOperator10_d = (Delay && swc_AUXC_ConstB.LogicalOperator5 &&
      (swc_AUXC_ARID_DEF.DataTypeConversion49 > brpc_u_vacPumpSysFailThd_V) &&
      (swc_AUXC_ARID_DEF.DataTypeConversion49 - swc_AUXC_ARID_DEF.Delay_DSTATE[0]
       <= brpc_u_vacPumpVotDiff_V));

    /* Outputs for Atomic SubSystem: '<S44>/turnON_delay8' */
    swc_AUXC_turnON_delay(rtb_LogicalOperator10_d, brpc_t_vacPumpSysFail1_s,
                          ((float32)BRP_TASK_INTERVAL_S), &rtb_flg_out_a,
                          &swc_AUXC_ARID_DEF.ARID_DEF_turnON_delay8);

    /* End of Outputs for SubSystem: '<S44>/turnON_delay8' */

    /* Logic: '<S44>/Logical Operator9' incorporates:
     *  Constant: '<S44>/Constant26'
     *  Constant: '<S44>/Constant27'
     *  Constant: '<S44>/Constant32'
     *  Constant: '<S44>/Constant35'
     *  Delay: '<S44>/Delay1'
     *  RelationalOperator: '<S44>/Relational Operator14'
     *  RelationalOperator: '<S44>/Relational Operator15'
     *  Sum: '<S44>/Add1'
     */
    rtb_LogicalOperator9_m = (Delay && swc_AUXC_ConstB.RelationalOperator10 &&
      (swc_AUXC_ARID_DEF.DataTypeConversion49 > brpc_u_vacPumpSysFailThd_V) &&
      (swc_AUXC_ARID_DEF.DataTypeConversion49 - swc_AUXC_ARID_DEF.Delay1_DSTATE
       [0] <= brpc_u_vacPumpVotDiff_V));

    /* Outputs for Atomic SubSystem: '<S44>/turnON_delay10' */
    swc_AUXC_turnON_delay(rtb_LogicalOperator9_m, brpc_t_vacPumpSysFail2_s,
                          ((float32)BRP_TASK_INTERVAL_S), &rtb_flg_out_jx,
                          &swc_AUXC_ARID_DEF.ARID_DEF_turnON_delay10);

    /* End of Outputs for SubSystem: '<S44>/turnON_delay10' */

    /* Logic: '<S44>/Logical Operator15' incorporates:
     *  Constant: '<S44>/Constant33'
     *  Constant: '<S44>/Constant34'
     *  Logic: '<S44>/Logical Operator7'
     */
    rtb_LogicalOperator15_f = (RelationalOperator2 && (rtb_flg_out_a ||
      rtb_flg_out_jx));

    /* Outputs for Atomic SubSystem: '<S44>/SR_latch5' */
    swc_AUXC_SR_latch5(rtb_LogicalOperator15_f, rtb_RelationalOperator17,
                       &swc_AUXC_ARID_DEF.ARID_DEF_SR_latch5);

    /* End of Outputs for SubSystem: '<S44>/SR_latch5' */

    /* Chart: '<S7>/VacuumPumpEnableControl' incorporates:
     *  Constant: '<S7>/Constant23'
     */
    if (swc_AUXC_ARID_DEF.is_active_c3_brp == 0U) {
      swc_AUXC_ARID_DEF.is_active_c3_brp = 1U;
      swc_AUXC_ARID_DEF.is_c3_brp = swc_AUXC_IN_VacPumpOff;

      /* Update for UnitDelay: '<S7>/Unit Delay' */
      swc_AUXC_ARID_DEF.UnitDelay_DSTATE = 0U;

      /* SignalConversion: '<S7>/Signal Conversion5' */
      brpd_b_VacPumpEnReq = false;
    } else {
      switch (swc_AUXC_ARID_DEF.is_c3_brp) {
       case swc_AUXC_IN_CycleControl:
        /* Update for UnitDelay: '<S7>/Unit Delay' */
        swc_AUXC_ARID_DEF.UnitDelay_DSTATE = 2U;
        if ((!brpd_b_VacPumpSnrFlt) && (!brpd_b_VacPumpEnOvrTmLoPreFlt) &&
            (!brpd_b_VacPumpLoPreFlt) && (!brpd_b_VacPumpSysFailFlt)) {
          swc_AUXC_ARID_DEF.is_CycleControl = swc_AUXC_IN_NO_ACTIVE_CHILD_h;
          swc_AUXC_ARID_DEF.is_c3_brp = swc_AUXC_IN_NormalControl;

          /* Update for UnitDelay: '<S7>/Unit Delay' */
          swc_AUXC_ARID_DEF.UnitDelay_DSTATE = 1U;

          /* SignalConversion: '<S7>/Signal Conversion5' */
          brpd_b_VacPumpEnReq = true;
        } else if (swc_AUXC_ARID_DEF.is_CycleControl == swc_AUXC_IN_OFF_i) {
          /* SignalConversion: '<S7>/Signal Conversion5' */
          brpd_b_VacPumpEnReq = false;
          if (swc_AUXC_ARID_DEF.t >= 5.0F) {
            swc_AUXC_ARID_DEF.is_CycleControl = swc_AUXC_IN_ON_m;
            swc_AUXC_ARID_DEF.t = 0.0F;

            /* SignalConversion: '<S7>/Signal Conversion5' */
            brpd_b_VacPumpEnReq = true;
          } else {
            swc_AUXC_ARID_DEF.t += ((float32)BRP_TASK_INTERVAL_S);
          }
        } else {
          /* SignalConversion: '<S7>/Signal Conversion5' */
          /* case IN_ON: */
          brpd_b_VacPumpEnReq = true;
          if (swc_AUXC_ARID_DEF.t >= 25.0F) {
            swc_AUXC_ARID_DEF.is_CycleControl = swc_AUXC_IN_OFF_i;
            swc_AUXC_ARID_DEF.t = 0.0F;

            /* SignalConversion: '<S7>/Signal Conversion5' */
            brpd_b_VacPumpEnReq = false;
          } else {
            swc_AUXC_ARID_DEF.t += ((float32)BRP_TASK_INTERVAL_S);
          }
        }
        break;

       case swc_AUXC_IN_NormalControl:
        /* Update for UnitDelay: '<S7>/Unit Delay' */
        swc_AUXC_ARID_DEF.UnitDelay_DSTATE = 1U;

        /* SignalConversion: '<S7>/Signal Conversion5' */
        brpd_b_VacPumpEnReq = true;
        if (brpd_b_VacPumpSnrFlt || brpd_b_VacPumpEnOvrTmLoPreFlt ||
            brpd_b_VacPumpLoPreFlt || brpd_b_VacPumpSysFailFlt) {
          swc_AUXC_ARID_DEF.is_c3_brp = swc_AUXC_IN_CycleControl;

          /* Update for UnitDelay: '<S7>/Unit Delay' */
          swc_AUXC_ARID_DEF.UnitDelay_DSTATE = 2U;
          swc_AUXC_ARID_DEF.is_CycleControl = swc_AUXC_IN_ON_m;
          swc_AUXC_ARID_DEF.t = 0.0F;
        } else if (brpd_b_VacPumpEnOvrTmHiPre || (!brpd_b_VacPumpEnReqRaw)) {
          swc_AUXC_ARID_DEF.is_c3_brp = swc_AUXC_IN_VacPumpOff;

          /* Update for UnitDelay: '<S7>/Unit Delay' */
          swc_AUXC_ARID_DEF.UnitDelay_DSTATE = 0U;

          /* SignalConversion: '<S7>/Signal Conversion5' */
          brpd_b_VacPumpEnReq = false;
        }
        break;

       default:
        /* Update for UnitDelay: '<S7>/Unit Delay' */
        /* case IN_VacPumpOff: */
        swc_AUXC_ARID_DEF.UnitDelay_DSTATE = 0U;

        /* SignalConversion: '<S7>/Signal Conversion5' */
        brpd_b_VacPumpEnReq = false;
        if (brpd_b_VacPumpEnReqRaw) {
          swc_AUXC_ARID_DEF.is_c3_brp = swc_AUXC_IN_NormalControl;

          /* Update for UnitDelay: '<S7>/Unit Delay' */
          swc_AUXC_ARID_DEF.UnitDelay_DSTATE = 1U;

          /* SignalConversion: '<S7>/Signal Conversion5' */
          brpd_b_VacPumpEnReq = true;
        } else if (brpd_b_VacPumpSnrFlt) {
          swc_AUXC_ARID_DEF.is_c3_brp = swc_AUXC_IN_CycleControl;

          /* Update for UnitDelay: '<S7>/Unit Delay' */
          swc_AUXC_ARID_DEF.UnitDelay_DSTATE = 2U;
          swc_AUXC_ARID_DEF.is_CycleControl = swc_AUXC_IN_ON_m;
          swc_AUXC_ARID_DEF.t = 0.0F;

          /* SignalConversion: '<S7>/Signal Conversion5' */
          brpd_b_VacPumpEnReq = true;
        }
        break;
      }
    }

    /* End of Chart: '<S7>/VacuumPumpEnableControl' */

    /* SignalConversion: '<S7>/Signal Conversion1' */
    brpd_b_VacPumpRlyEn = brpd_b_VacPumpEnReq;

    /* Logic: '<S43>/Logical Operator' incorporates:
     *  Constant: '<S43>/Constant2'
     *  RelationalOperator: '<S43>/Relational Operator3'
     *  UnitDelay: '<S7>/Unit Delay1'
     */
    rtb_LogicalOperator_j = (swc_AUXC_ARID_DEF.UnitDelay1_DSTATE_h &&
      (swc_AUXC_ARID_DEF.DataTypeConversion50 <= brpc_u_vacPumpEnThd_V));

    /* Logic: '<S43>/Logical Operator1' */
    rtb_LogicalOperator1_p = !swc_AUXC_ARID_DEF.DataTypeConversion17;

    /* Outputs for Atomic SubSystem: '<S43>/turnON_delay4' */
    swc_AUXC_turnON_delay(rtb_LogicalOperator_j, brpc_t_vacPumpRlyFltThd_s,
                          ((float32)BRP_TASK_INTERVAL_S), &rtb_flg_out_n,
                          &swc_AUXC_ARID_DEF.ARID_DEF_turnON_delay4_m);

    /* End of Outputs for SubSystem: '<S43>/turnON_delay4' */

    /* Outputs for Atomic SubSystem: '<S43>/SR_latch4' */
    swc_AUXC_SR_latch4(rtb_flg_out_n, rtb_LogicalOperator1_p,
                       &swc_AUXC_ARID_DEF.ARID_DEF_SR_latch4_c);

    /* End of Outputs for SubSystem: '<S43>/SR_latch4' */

    /* Sum: '<S44>/Add3' incorporates:
     *  Constant: '<S43>/Constant20'
     *  Constant: '<S43>/Constant21'
     *  Constant: '<S44>/Constant5'
     *  Constant: '<S44>/Constant6'
     *  Constant: '<S44>/Constant8'
     *  Product: '<S44>/Divide'
     *  Sum: '<S44>/Add2'
     */
    brpd_p_VacPumpPressure_kPa = 6.7F - (4.6F -
      swc_AUXC_ARID_DEF.DataTypeConversion49) / 0.0439F;

    /* Logic: '<S44>/Logical Operator12' */
    rtb_LogicalOperator12_d = (rtb_RelationalOperator16 ||
      rtb_RelationalOperator17);

    /* Logic: '<S44>/Logical Operator13' */
    rtb_LogicalOperator13 = (brpd_b_VacPumpEnOvrTmHiPre && RelationalOperator2);

    /* Outputs for Atomic SubSystem: '<S44>/SR_latch6' */
    swc_AUXC_SR_latch6(rtb_LogicalOperator13, rtb_LogicalOperator12_d,
                       &swc_AUXC_ARID_DEF.ARID_DEF_SR_latch6);

    /* End of Outputs for SubSystem: '<S44>/SR_latch6' */

    /* SignalConversion: '<S44>/Signal Conversion' */
    swc_AUXC_ARID_DEF.brpd_u_VacPumpVol_V =
      swc_AUXC_ARID_DEF.DataTypeConversion49;

    /* Update for Delay: '<S44>/Delay' */
    for (i = 0; i < 99; i++) {
      swc_AUXC_ARID_DEF.Delay_DSTATE[i] = swc_AUXC_ARID_DEF.Delay_DSTATE[i + 1];
    }

    swc_AUXC_ARID_DEF.Delay_DSTATE[99] = swc_AUXC_ARID_DEF.DataTypeConversion49;

    /* End of Update for Delay: '<S44>/Delay' */

    /* Update for Delay: '<S44>/Delay1' */
    for (i = 0; i < 99; i++) {
      swc_AUXC_ARID_DEF.Delay1_DSTATE[i] = swc_AUXC_ARID_DEF.Delay1_DSTATE[i + 1];
    }

    swc_AUXC_ARID_DEF.Delay1_DSTATE[99] = swc_AUXC_ARID_DEF.DataTypeConversion49;

    /* End of Update for Delay: '<S44>/Delay1' */

    /* Update for UnitDelay: '<S7>/Unit Delay1' */
    swc_AUXC_ARID_DEF.UnitDelay1_DSTATE_h = brpd_b_VacPumpRlyEn;
  } else {
    swc_AUXC_ARID_DEF.VacuumPumpControlByPMS_MODE = false;
  }

  /* End of RelationalOperator: '<S5>/Compare' */
  /* End of Outputs for SubSystem: '<S2>/VacuumPumpControlByPMS' */

  /* Update for UnitDelay: '<S9>/Unit Delay' incorporates:
   *  Constant: '<S9>/Constant2'
   *  Constant: '<S9>/Constant3'
   *  Logic: '<S9>/Logical Operator'
   *  Logic: '<S9>/Logical Operator1'
   *  Logic: '<S9>/Logical Operator2'
   *  Logic: '<S9>/Logical Operator4'
   *  RelationalOperator: '<S9>/Relational Operator2'
   *  RelationalOperator: '<S9>/Relational Operator3'
   */
  swc_AUXC_ARID_DEF.UnitDelay_DSTATE_e = ((brpd_b_bdcacEna &&
    (swc_AUXC_ARID_DEF.DataTypeConversion18 != ((uint8)1U))) ||
    ((!brpd_b_bdcacEna) && (swc_AUXC_ARID_DEF.DataTypeConversion18 != ((uint8)0U))));

  /* Update for UnitDelay: '<S22>/UnitDelay1467' */
  swc_AUXC_ARID_DEF.UnitDelay1467_DSTATE = rtb_Switch3;

  /* Update for Delay: '<S3>/Delay1' */
  swc_AUXC_ARID_DEF.Delay1_DSTATE_f = swc_AUXC_ARID_DEF.vcu_st_BrkVacErr;

  /* Update for UnitDelay: '<S3>/Unit Delay1' incorporates:
   *  Logic: '<S3>/Logical Operator6'
   */
  swc_AUXC_ARID_DEF.UnitDelay1_DSTATE = (rtb_LogicalOperator5 ||
    brpd_b_bdcacTmOut);

  /* Update for UnitDelay: '<S3>/Unit Delay2' */
  swc_AUXC_ARID_DEF.UnitDelay2_DSTATE = rtb_Relay9;

  /* Relay: '<S3>/Relay1' */
  if (swc_AUXC_ARID_DEF.Relay1_Mode) {
    /* Update for UnitDelay: '<S3>/Unit Delay3' */
    swc_AUXC_ARID_DEF.UnitDelay3_DSTATE = false;
  } else {
    /* Update for UnitDelay: '<S3>/Unit Delay3' */
    swc_AUXC_ARID_DEF.UnitDelay3_DSTATE = true;
  }

  /* Relay: '<S3>/Relay2' */
  if (swc_AUXC_ARID_DEF.Relay2_Mode) {
    /* Update for UnitDelay: '<S3>/Unit Delay4' */
    swc_AUXC_ARID_DEF.UnitDelay4_DSTATE = false;
  } else {
    /* Update for UnitDelay: '<S3>/Unit Delay4' */
    swc_AUXC_ARID_DEF.UnitDelay4_DSTATE = true;
  }
}

/* Model step function */
void swc_AUXC_Step(void)
{
  /* local block i/o variables */
  float32 rtb_DataTypeConversion22;
  float32 rtb_DataTypeConversion23;
  uint8 rtb_DataTypeConversion48;
  boolean rtb_DataTypeConversion16;
  boolean rtb_DataTypeConversion28;
  boolean rtb_DataTypeConversion30;
  EngineState rtb_DataTypeConversion29;
  EngStartType rtb_DataTypeConversion24;
  DCDCMode rtb_DataTypeConversion21;

  /* DataTypeConversion: '<Root>/Data Type Conversion12' incorporates:
   *  Inport generated from: '<Root>/In Bus Element15'
   */
  swc_AUXC_ARID_DEF.DataTypeConversion12 =
    Rte_IRead_swc_AUXC_Step_vcsb_HVSM_hvbd_e_PmmStatus();

  /* DataTypeConversion: '<Root>/Data Type Conversion46' incorporates:
   *  Inport generated from: '<Root>/In Bus Element4'
   */
  swcauxc_brpd_p_brkVacuumPres_bar =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_brpd_p_brkVacuumPres_bar();

  /* DataTypeConversion: '<Root>/Data Type Conversion14' incorporates:
   *  Inport generated from: '<Root>/In Bus Element5'
   */
  swc_AUXC_ARID_DEF.DataTypeConversion14 =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_brpd_b_DryAirSwitch();

  /* DataTypeConversion: '<Root>/Data Type Conversion15' incorporates:
   *  Inport generated from: '<Root>/In Bus Element6'
   */
  swc_AUXC_ARID_DEF.DataTypeConversion15 =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_brpd_b_ResrAirSwitch();

  /* DataTypeConversion: '<Root>/Data Type Conversion16' incorporates:
   *  Inport generated from: '<Root>/In Bus Element7'
   */
  rtb_DataTypeConversion16 =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_brpd_b_brkPumpFault();

  /* DataTypeConversion: '<Root>/Data Type Conversion17' incorporates:
   *  Inport generated from: '<Root>/In Bus Element8'
   */
  swc_AUXC_ARID_DEF.DataTypeConversion17 =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_pmmd_b_ignOn();

  /* DataTypeConversion: '<Root>/Data Type Conversion18' incorporates:
   *  Inport generated from: '<Root>/In Bus Element9'
   */
  swc_AUXC_ARID_DEF.DataTypeConversion18 =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_brpd_st_bdcacWrk();

  /* DataTypeConversion: '<Root>/Data Type Conversion19' incorporates:
   *  Inport generated from: '<Root>/In Bus Element10'
   */
  swc_AUXC_ARID_DEF.DataTypeConversion19 =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_macd_p_frontAirTankPres_bar();

  /* DataTypeConversion: '<Root>/Data Type Conversion20' incorporates:
   *  Inport generated from: '<Root>/In Bus Element11'
   */
  swc_AUXC_ARID_DEF.DataTypeConversion20 =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_macd_p_rearAirTankPres_bar();

  /* DataTypeConversion: '<Root>/Data Type Conversion27' incorporates:
   *  Inport generated from: '<Root>/In Bus Element3'
   */
  swc_AUXC_ARID_DEF.DataTypeConversion27 =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_brpd_b_vacTankLowPrs();

  /* DataTypeConversion: '<Root>/Data Type Conversion47' incorporates:
   *  Inport generated from: '<Root>/In Bus Element12'
   */
  swc_AUXC_ARID_DEF.DataTypeConversion47 =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_vscd_v_vehSpd_kph();

  /* DataTypeConversion: '<Root>/Data Type Conversion49' incorporates:
   *  Inport generated from: '<Root>/BusElementIn3'
   */
  swc_AUXC_ARID_DEF.DataTypeConversion49 =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_vild_u_VacTkAirPres_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion50' incorporates:
   *  Inport generated from: '<Root>/BusElementIn4'
   */
  swc_AUXC_ARID_DEF.DataTypeConversion50 =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_vild_u_VacTkEnFb_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion51' incorporates:
   *  Inport generated from: '<Root>/BusElementIn5'
   */
  swc_AUXC_ARID_DEF.DataTypeConversion51 =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_vild_b_flgNetConfgABS();

  /* DataTypeConversion: '<Root>/Data Type Conversion13' incorporates:
   *  Inport generated from: '<Root>/In Bus Element19'
   */
  swcauxc_brpd_p_AirPres_kpa =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_brpd_p_AirPres_kpa();

  /* DataTypeConversion: '<Root>/Data Type Conversion26' incorporates:
   *  Inport generated from: '<Root>/BusElementIn1'
   */
  swc_AUXC_ARID_DEF.DataTypeConversion26 =
    Rte_IRead_swc_AUXC_Step_vcsb_HVSM_hvbd_st_ptRdyInd();

  /* DataTypeConversion: '<Root>/Data Type Conversion44' incorporates:
   *  Inport generated from: '<Root>/BusElementIn2'
   */
  swc_AUXC_ARID_DEF.DataTypeConversion44 =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_vild_u_brkVacuumPres_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion25' incorporates:
   *  Inport generated from: '<Root>/BusElementIn'
   */
  swc_AUXC_ARID_DEF.DataTypeConversion25 =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_vild_st_flgFctCfgVehTyp();

  /* DataTypeConversion: '<Root>/Data Type Conversion33' incorporates:
   *  Inport generated from: '<Root>/BusElementIn6'
   */
  swc_AUXC_ARID_DEF.DataTypeConversion33 =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_vild_u_vacTkPowSup_V();

  /* S-Function (fcgen): '<S1>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S1>/BRP_BrakeVacuumPumpControl'
   */
  swc__BRP_BrakeVacuumPumpControl();

  /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator1' */

  /* DataTypeConversion: '<Root>/Data Type Conversion21' incorporates:
   *  Inport generated from: '<Root>/In Bus Element'
   */
  rtb_DataTypeConversion21 = Rte_IRead_swc_AUXC_Step_vcib_VCIP_dccd_e_modeAct();

  /* DataTypeConversion: '<Root>/Data Type Conversion22' incorporates:
   *  Inport generated from: '<Root>/In Bus Element1'
   */
  rtb_DataTypeConversion22 =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_lvbd_t_lvbEstTemp_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion23' incorporates:
   *  Inport generated from: '<Root>/In Bus Element2'
   */
  rtb_DataTypeConversion23 =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_lvbd_u_dcdcLVBusActFilt_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion24' incorporates:
   *  Inport generated from: '<Root>/In Bus Element13'
   */
  rtb_DataTypeConversion24 = Rte_IRead_swc_AUXC_Step_vcsb_VOMM_essd_e_engStrtTyp
    ();

  /* DataTypeConversion: '<Root>/Data Type Conversion28' incorporates:
   *  Inport generated from: '<Root>/In Bus Element16'
   */
  rtb_DataTypeConversion28 = Rte_IRead_swc_AUXC_Step_vcib_VCIP_cesd_b_crash();

  /* DataTypeConversion: '<Root>/Data Type Conversion29' incorporates:
   *  Inport generated from: '<Root>/In Bus Element18'
   */
  rtb_DataTypeConversion29 = Rte_IRead_swc_AUXC_Step_vcsb_PTSM_engd_e_engState();

  /* DataTypeConversion: '<Root>/Data Type Conversion30' incorporates:
   *  Inport generated from: '<Root>/In Bus Element17'
   */
  rtb_DataTypeConversion30 =
    Rte_IRead_swc_AUXC_Step_vcsb_VOMM_hmmd_b_EVModeEpsEna();

  /* DataTypeConversion: '<Root>/Data Type Conversion48' incorporates:
   *  Inport generated from: '<Root>/In Bus Element14'
   */
  rtb_DataTypeConversion48 =
    Rte_IRead_swc_AUXC_Step_vcib_VCIP_macd_st_epsErrorCode();

  /* Outport generated from: '<Root>/Out Bus Element13' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion34'
   */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_airTankPresLowEVDis
    (brpd_b_airTankPresLowEVDis);

  /* Outport generated from: '<Root>/Out Bus Element17' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion38'
   */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpSnrFlt(brpd_b_VacPumpSnrFlt);

  /* Outport generated from: '<Root>/Out Bus Element16' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion35'
   */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacTkAirPresLowFlt
    (swc_AUXC_ARID_DEF.brpd_b_VacTkAirPresLowFlt != 0.0);

  /* Outport generated from: '<Root>/Out Bus Element14' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion32'
   */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpRlyEn(brpd_b_VacPumpRlyEn);

  /* Outport generated from: '<Root>/Out Bus Element21' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion39'
   */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpSysFailFlt
    (brpd_b_VacPumpSysFailFlt);

  /* Outport generated from: '<Root>/Out Bus Element20' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion41'
   */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpEnOvrTmLoPreFlt
    (brpd_b_VacPumpEnOvrTmLoPreFlt);

  /* Outport generated from: '<Root>/Out Bus Element19' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion37'
   */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpEnOvrTmHiPreFlt
    (brpd_b_VacPumpEnOvrTmHiPreFlt);

  /* Outport generated from: '<Root>/Out Bus Element18' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion36'
   */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpLoPreFlt
    (brpd_b_VacPumpLoPreFlt);

  /* Outport generated from: '<Root>/Out Bus Element24' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion45'
   */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_p_VacPumpPressure_kPa
    (brpd_p_VacPumpPressure_kPa);

  /* Outport generated from: '<Root>/Out Bus Element25' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion43'
   */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_u_VacPumpVol_V
    (swc_AUXC_ARID_DEF.brpd_u_VacPumpVol_V);

  /* Outport generated from: '<Root>/Out Bus Element12' */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_pscd_b_epsStopFlt
    (swc_AUXC_ConstB.DataTypeConversion31);

  /* Outport generated from: '<Root>/Out Bus Element' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_brkPmp1Rly(brpd_b_brkPmp1Rly);

  /* Outport generated from: '<Root>/Out Bus Element1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_brkPmp2Rly(brpd_b_brkPmp2Rly);

  /* Outport generated from: '<Root>/Out Bus Element2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_bdcacEna(brpd_b_bdcacEna);

  /* Outport generated from: '<Root>/Out Bus Element3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_pumpRdy(brpd_b_pumpRdy);

  /* Outport generated from: '<Root>/Out Bus Element4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_airTankFlt(brpd_b_airTankFlt);

  /* Outport generated from: '<Root>/Out Bus Element5' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_bdcacTmOut(brpd_b_bdcacTmOut);

  /* Outport generated from: '<Root>/Out Bus Element6' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion6'
   */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_airTankPresLow(brpd_b_airTankPresLow);

  /* Outport generated from: '<Root>/Out Bus Element7' */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_lvbd_b_lvbSOCValid
    (swc_AUXC_ConstB.DataTypeConversion7);

  /* Outport generated from: '<Root>/Out Bus Element8' */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_lvbd_q_lvbSOC_pct
    (swc_AUXC_ConstB.DataTypeConversion8);

  /* Outport generated from: '<Root>/Out Bus Element9' */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_pscd_frq_epsFrqTgt_Hz
    (swc_AUXC_ConstB.DataTypeConversion9);

  /* Outport generated from: '<Root>/Out Bus Element10' */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_pscd_b_epsEna
    (swc_AUXC_ConstB.DataTypeConversion10);

  /* Outport generated from: '<Root>/Out Bus Element11' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion11'
   */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_airTankPresLowInhDrv
    (brpd_b_airTankPresLowInhDrv);

  /* Outport generated from: '<Root>/Out Bus Element22' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion40'
   */
  Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpRlyFlt(brpd_b_VacPumpRlyFlt);
}

/* Model initialize function */
void swc_AUXC_Init(void)
{
  /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S1>/BRP_BrakeVacuumPumpControl'
   */
  BRP_BrakeVacuumPumpControl_Init();

  /* End of SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

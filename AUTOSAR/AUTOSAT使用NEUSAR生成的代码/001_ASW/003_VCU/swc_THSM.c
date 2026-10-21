/*
 * File: swc_THSM.c
 *
 * Code generated for Simulink model 'swc_THSM'.
 *
 * Model version                  : 6.156
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Jul  3 15:08:27 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "swc_THSM.h"
#include "rtwtypes.h"
#include <math.h>
#include "Rte_Type.h"
#include "const_ImportedDefine.h"
#include "const_ImportFromFile.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef THM_TASK_INTERVAL_S
#error The value of parameter "THM_TASK_INTERVAL_S" is not defined
#endif

#ifndef VEH_SWT_INF
#error The value of parameter "VEH_SWT_INF" is not defined
#endif

/* Named constants for Chart: '<S25>/timed_delay' */
#define swc_THSM_IN_OFF                ((uint8)1U)
#define swc_THSM_IN_OFF_WAIT           ((uint8)2U)
#define swc_THSM_IN_ON                 ((uint8)3U)

/* Named constants for Chart: '<S70>/timed_delay' */
#define swc_THSM_IN_NO_ACTIVE_CHILD    ((uint8)0U)
#define swc_THSM_IN_OFF_c              ((uint8)1U)
#define swc_THSM_IN_ON_WAIT            ((uint8)3U)
#define swc_THSM_IN_ON_h               ((uint8)2U)

/* Named constants for Chart: '<S3>/AccmOnOffProtection' */
#define swc_THSM_IN_INIT               ((uint8)1U)
#define swc_THSM_IN_NO_ACTIVE_CHILD_c  ((uint8)0U)
#define swc_THSM_IN_Off                ((uint8)2U)
#define swc_THSM_IN_On                 ((uint8)3U)

/* Named constants for Chart: '<S115>/timed_debounce' */
#define swc_THSM_IN_OFF_WAIT_a         ((uint8)2U)
#define swc_THSM_IN_OFF_i              ((uint8)1U)
#define swc_THSM_IN_ON_WAIT_n          ((uint8)4U)
#define swc_THSM_IN_ON_e               ((uint8)3U)

/* Named constants for Chart: '<S137>/timed_delay' */
#define swc_THSM_IN_ON_WAIT_d          ((uint8)3U)
#define swc_THSM_IN_ON_hp              ((uint8)2U)

/* Named constants for Chart: '<S11>/Chart' */
#define swc_IN_WaterPumpMode_VacuumFill ((uint8)2U)
#define swc_THSM_IN_AfterIgnOnTimer    ((uint8)1U)
#define swc_THSM_IN_Init               ((uint8)3U)
#define swc_THS_IN_BrakePedalStateTimer ((uint8)2U)
#define swc_T_IN_WaterPumpMode_NormWork ((uint8)1U)

/* Exported data definition */
#define swc_THSM_START_SEC_CONST_VOLATILE
#include "swc_THSM_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_CAL */
const volatile boolean thmc_b_diHVBHeatEnadCnd = false;/* Referenced by: '<S7>/Constant1' */

/* disable water pump1 stop function in battery heating. */
const volatile boolean thmc_b_enaIntelChgAfterRun = false;/* Referenced by: '<S20>/Constant6' */

/* Enable after-run after inteligent charge */
const volatile boolean thmc_b_enaLongerAfterRun = false;/* Referenced by: '<S20>/Constant3' */

/* Enable longer after-run if temperatures are not yet acceptable */
const volatile boolean thmc_b_enaShorterAfterRun = false;/* Referenced by: '<S20>/Constant2' */

/* Enable shorter after-run if temperatures are already acceptable */
const volatile boolean thmc_b_fanRly1Dflt = false;/* Referenced by: '<S32>/Constant1' */

/* Fan Request relay 1 default value */
const volatile boolean thmc_b_fanRly2Dflt = false;/* Referenced by: '<S32>/Constant3' */

/* Fan Request relay 2 default value */
const volatile boolean thmc_b_nonFillingFlg = true;/* Referenced by: '<S11>/Constant' */
const volatile boolean thmc_b_onlyfterRunAcv = true;/* Referenced by:
                                                     * '<S36>/Constant8'
                                                     * '<S37>/Constant8'
                                                     */
const volatile boolean thmc_b_wtrPmpRly1Dflt = false;/* Referenced by: '<S149>/Constant1' */

/* Water Pump Request relay 1 default value */
const volatile boolean thmc_b_wtrPmpRly2Dflt = false;/* Referenced by: '<S149>/Constant3' */

/* Water Pump Request relay 2 default value */
const volatile float32 thmc_n_Fan1SpdIni_pct = 95.0F;/* Referenced by:
                                                      * '<S36>/Constant12'
                                                      * '<S37>/Constant12'
                                                      */
const volatile float32 thmc_n_Fan1SpdOff_pct = 5.0F;/* Referenced by: '<S37>/Constant11' */
const volatile float32 thmc_n_fan120SpdReqFltSts_pct = 50.0F;/* Referenced by: '<S33>/Constant3' */
const volatile float32 thmc_n_fan1SpdOffAirCl_pct = 3.0F;/* Referenced by: '<S36>/Constant11' */
const volatile boolean thmc_n_fan1SpdReqEnable = false;/* Referenced by: '<S33>/Constant5' */
const volatile boolean thmc_n_fan1SpdReqEnbAirCl = false;/* Referenced by: '<S34>/Constant5' */
const volatile float32 thmc_n_fan1SpdReqFltAirCl_pct = 85.0F;/* Referenced by: '<S34>/Constant1' */

/* Air Cool Fan1 Request during fault status */
const volatile float32 thmc_n_fan1SpdReqFltSts_pct = 100.0F;/* Referenced by: '<S33>/Constant1' */

/* Fan1 Request during fault status */
const volatile float32 thmc_n_fan1SpdReqOffAirCl_pct = 5.0F;/* Referenced by:
                                                             * '<S34>/Constant2'
                                                             * '<S34>/Constant3'
                                                             */

/* Fan1 Request during OFF */
const volatile float32 thmc_n_fan1SpdReqOff_pct = 0.0F;/* Referenced by:
                                                        * '<S33>/Constant2'
                                                        * '<S33>/Constant7'
                                                        * '<S37>/Constant14'
                                                        */

/* Fan1 Request during OFF */
const volatile float32 thmc_n_fan1SpdReqfull_pct = 100.0F;/* Referenced by:
                                                           * '<S33>/Constant6'
                                                           * '<S34>/Constant6'
                                                           */
const volatile float32 thmc_n_fanMaxSpd_rpm = 8000.0F;/* Referenced by:
                                                       * '<S33>/Constant4'
                                                       * '<S34>/Constant4'
                                                       */

/* Fan Max Speed */
const volatile float32 thmc_n_pmp1BalceTgtSpd_pct = 214.0F;/* Referenced by: '<S147>/Constant14' */
const volatile float32 thmc_n_pmp1BmshThemReqTgtSpd_pct = 254.0F;/* Referenced by: '<S147>/Constant1' */
const volatile float32 thmc_n_pmp1CoolChrTgtSpd_pct = 95.0F;/* Referenced by: '<S147>/Constant5' */
const volatile float32 thmc_n_pmp1CoolUnChrTgtSpd_pct = 50.0F;/* Referenced by: '<S147>/Constant6' */
const volatile float32 thmc_n_pmp1DefTgtSpd_pct = 0.0F;/* Referenced by:
                                                        * '<S147>/Constant13'
                                                        * '<S147>/Constant2'
                                                        * '<S147>/Constant3'
                                                        * '<S147>/Constant7'
                                                        * '<S147>/Constant8'
                                                        * '<S192>/Constant'
                                                        */
const volatile float32 thmc_n_pmp1FltStsTgtSpd_pct = 254.0F;/* Referenced by: '<S147>/Constant15' */
const volatile float32 thmc_n_pmp1NonVacFillTgtSpd_pct = 254.0F;/* Referenced by: '<S147>/Constant11' */
const volatile float32 thmc_n_pmp2FltTgtSpdAirCl_pct = 92.0F;/* Referenced by: '<S148>/Constant15' */
const volatile float32 thmc_n_pmp2HiSpdReqDis_pct = 65.0F;/* Referenced by: '<S150>/Relay5' */

/* Water Pump 2 Request threshold for disable high speed */
const volatile float32 thmc_n_pmp2HiSpdReqEna_pct = 70.0F;/* Referenced by: '<S150>/Relay5' */

/* Water Pump 2 Request threshold for enable high speed */
const volatile float32 thmc_n_pmp2LoSpdReqDis_pct = 11.0F;/* Referenced by: '<S150>/Relay4' */

/* Water Pump 2 Request threshold for disable low speed */
const volatile float32 thmc_n_pmp2LoSpdReqEna_pct = 15.0F;/* Referenced by: '<S150>/Relay4' */

/* Water Pump 2 Request threshold for enable low speed */
const volatile float32 thmc_n_pmp2MedSpdReqDis_pct = 35.0F;/* Referenced by: '<S150>/Relay3' */

/* Water Pump 2 Request threshold for disable medium speed */
const volatile float32 thmc_n_pmp2MedSpdReqEna_pct = 40.0F;/* Referenced by: '<S150>/Relay3' */

/* Water Pump 2 Request threshold for enable medium speed */
const volatile float32 thmc_n_pmp2NonVacTgtSpdAirCl_pct = 95.0F;/* Referenced by: '<S148>/Constant11' */
const volatile float32 thmc_n_pmp2StopTgtSpdAirCl_pct = 10.0F;/* Referenced by:
                                                               * '<S148>/Constant'
                                                               * '<S148>/Constant2'
                                                               */
const volatile float32 thmc_n_wtrPmp1MaxSpd_rpm = 6500.0F;/* Referenced by: '<S147>/Constant4' */

/* Water Pump 1 Max Speed */
const volatile float32 thmc_n_wtrPmp2MaxSpd_rpm = 6500.0F;/* Referenced by: '<S148>/Constant4' */

/* Water Pump 2 Max Speed */
const volatile uint8 thmc_st_fanReqStatusDflt = 0U;/* Referenced by: '<S35>/Constant3' */

/* Fan Request Status default value */
const volatile uint8 thmc_st_pmp1ReqStatusDflt = 0U;/* Referenced by: '<S150>/Constant3' */

/* Pump 1 Request Status default value */
const volatile uint8 thmc_st_pmp2ReqStatusDflt = 0U;/* Referenced by: '<S150>/Constant2' */

/* Pump 2 Request Status default value */
const volatile float32 thmc_t_acewpDisTemp_C = 0.0F;/* Referenced by: '<S10>/Constant' */
const volatile float32 thmc_t_dcdcOverTempDw_C = 80.0F;/* Referenced by: '<S9>/Relay2' */
const volatile float32 thmc_t_dcdcOverTempUp_C = 80.0F;/* Referenced by: '<S9>/Relay2' */
const volatile float32 thmc_t_ewpOutFltThrDw = -40.0F;/* Referenced by: '<S114>/Lower Limit' */
const volatile float32 thmc_t_ewpOutFltThrUp = 120.0F;/* Referenced by: '<S114>/Upper Limit' */
const volatile float32 thmc_t_fanEnaInvHiThd_C = 50.0F;/* Referenced by: '<S7>/Relay2' */

/* Fan enable TMM inverter temperature high threshold */
const volatile float32 thmc_t_fanEnaInvLoThd_C = 40.0F;/* Referenced by: '<S7>/Relay2' */

/* Fan enable TMM inverter temperature low threshold */
const volatile float32 thmc_t_fanEnaMotHiThd_C = 70.0F;/* Referenced by: '<S7>/Relay3' */

/* Fan enable TMM motor temperature high threshold */
const volatile float32 thmc_t_fanEnaMotLoThd_C = 60.0F;/* Referenced by: '<S7>/Relay3' */

/* Fan enable TMM motor temperature low threshold */
const volatile float32 thmc_t_inv2OverTempDw_C = 78.0F;/* Referenced by: '<S9>/Relay1' */
const volatile float32 thmc_t_inv2OverTempUp_C = 80.0F;/* Referenced by: '<S9>/Relay1' */
const volatile float32 thmc_t_mot2OverTempDw_C = 78.0F;/* Referenced by: '<S9>/Relay' */
const volatile float32 thmc_t_mot2OverTempUp_C = 80.0F;/* Referenced by: '<S9>/Relay' */
const volatile float32 thmc_t_ts5LowTempDw_C = -48.0F;/* Referenced by: '<S9>/Relay4' */
const volatile float32 thmc_t_ts5LowTempUp_C = -45.0F;/* Referenced by: '<S9>/Relay4' */
const volatile float32 thmc_t_ts5OverTempDw_C = 120.0F;/* Referenced by: '<S9>/Relay3' */
const volatile float32 thmc_t_ts5OverTempUp_C = 125.0F;/* Referenced by: '<S9>/Relay3' */
const volatile float32 thmc_t_wtrPmp2EnaInvHiThd_C = 50.0F;/* Referenced by: '<S7>/Relay1' */

/* Water Pump enable TMM inverter temperature high threshold */
const volatile float32 thmc_t_wtrPmp2EnaInvLoThd_C = 40.0F;/* Referenced by: '<S7>/Relay1' */

/* Water Pump enable TMM inverter temperature low threshold */
const volatile float32 thmc_t_wtrPmp2EnaMotHiThd_C = 70.0F;/* Referenced by: '<S7>/Relay4' */

/* Water Pump enable TMM motor temperature high threshold */
const volatile float32 thmc_t_wtrPmp2EnaMotLoThd_C = 60.0F;/* Referenced by: '<S7>/Relay4' */

/* Water Pump enable TMM motor temperature low threshold */
const volatile float32 thmc_tm_Fan115OffDlyAirCl_s = 3.0F;/* Referenced by: '<S34>/Constant10' */
const volatile float32 thmc_tm_Fan115OffDly_s = 3.0F;/* Referenced by: '<S33>/Constant10' */
const volatile float32 thmc_tm_Fan1EnbDly_s = 0.0F;/* Referenced by:
                                                    * '<S36>/Constant10'
                                                    * '<S37>/Constant10'
                                                    */
const volatile float32 thmc_tm_FltStsOffDly_s = 2.0F;/* Referenced by:
                                                      * '<S9>/Constant1'
                                                      * '<S9>/Constant11'
                                                      * '<S9>/Constant4'
                                                      * '<S9>/Constant7'
                                                      */

/* Fault status hold time */
const volatile float32 thmc_tm_FltStsOnDly_s = 3.0F;/* Referenced by:
                                                     * '<S9>/Constant2'
                                                     * '<S9>/Constant5'
                                                     * '<S9>/Constant8'
                                                     * '<S9>/Constant9'
                                                     */

/* Fault status hold time */
const volatile float32 thmc_tm_Pump215OffDlyAirCl_s = 3.0F;/* Referenced by: '<S148>/Constant10' */
const volatile float32 thmc_tm_Pump215OffDly_s = 3.0F;/* Referenced by: '<S147>/Constant10' */
const volatile float32 thmc_tm_accmRstLim_s = 0.0F;/* Referenced by: '<S3>/Constant7' */

/* ACCM enable reset time */
const volatile float32 thmc_tm_maxAfterRunTime_s = 3.0F;/* Referenced by:
                                                         * '<S20>/Constant5'
                                                         * '<S20>/Constant7'
                                                         */

/* Max after-run time */
const volatile float32 thmc_tm_ptc3DlyCan_s = 0.0F;/* Referenced by: '<S10>/Constant6' */

/* ptc3 Can signal delayed sent */
const volatile float32 thmc_tm_ptc3DlyHw_s = 0.0F;/* Referenced by: '<S10>/Constant8' */

/* ptc3 HW signal delayed stop */
const volatile float32 thmc_tm_ptc3VoltFaultThr1_s = 0.5F;/* Referenced by: '<S202>/Constant8' */
const volatile float32 thmc_tm_ptc3VoltFaultThr_s = 0.5F;/* Referenced by: '<S202>/Constant3' */
const volatile float32 thmc_tm_ptcDlyCan_s = 0.0F;/* Referenced by: '<S10>/Constant4' */

/* ptc Can signal delayed sent */
const volatile float32 thmc_tm_ptcDlyHw_s = 0.0F;/* Referenced by: '<S10>/Constant1' */

/* ptc HW signal delayed stop */
const volatile float32 thmc_tm_ptcVoltFaultThr1_s = 0.5F;/* Referenced by: '<S207>/Constant8' */
const volatile float32 thmc_tm_ptcVoltFaultThr_s = 0.5F;/* Referenced by: '<S207>/Constant3' */
const volatile float32 thmc_v_hvbInFltThrDw = 0.1F;/* Referenced by: '<S112>/Lower Limit' */
const volatile float32 thmc_v_hvbInFltThrUp = 4.9F;/* Referenced by: '<S112>/Upper Limit' */
const volatile float32 thmc_v_hvbOutFltThrDw = 0.1F;/* Referenced by: '<S113>/Lower Limit' */
const volatile float32 thmc_v_hvbOutFltThrUp = 4.9F;/* Referenced by: '<S113>/Upper Limit' */
const volatile float32 thmc_v_ts5FltThrDw = 100.0F;/* Referenced by: '<S111>/Lower Limit' */
const volatile float32 thmc_v_ts5FltThrUp = 4900.0F;/* Referenced by: '<S111>/Upper Limit' */
const volatile float32 thmf_X_ObcEdcpDecPct[7] = { 56.99F, 57.0F, 59.0F, 61.0F,
  63.0F, 70.0F, 73.0F } ;         /* Referenced by: '<S173>/1D_Lookup_Table3' */

const volatile float32 thmf_X_ObcEdcpIdleDecPct[7] = { 56.99F, 57.0F, 59.0F,
  61.0F, 63.0F, 70.0F, 73.0F } ;  /* Referenced by: '<S174>/1D_Lookup_Table3' */

const volatile float32 thmf_X_ObcEdcpIdleIncPct[7] = { 61.99F, 62.0F, 64.0F,
  66.0F, 68.0F, 75.0F, 78.0F } ;  /* Referenced by: '<S174>/1D_Lookup_Table2' */

const volatile float32 thmf_X_ObcEdcpIncPct[7] = { 61.99F, 62.0F, 64.0F, 66.0F,
  68.0F, 75.0F, 78.0F } ;         /* Referenced by: '<S173>/1D_Lookup_Table2' */

const volatile float32 thmf_X_PassCoolSnsrTempFan1_t[4] = { 15.0F, 25.0F, 35.0F,
  40.0F } ;                        /* Referenced by: '<S37>/1D_Lookup_Table6' */

const volatile float32 thmf_X_Pmp2DcdcIdleDecPct[6] = { 54.99F, 55.0F, 60.0F,
  65.0F, 68.0F, 68.01F } ;        /* Referenced by: '<S166>/1D_Lookup_Table3' */

const volatile float32 thmf_X_Pmp2DcdcIdleIncPct[6] = { 59.99F, 60.0F, 65.0F,
  70.0F, 73.0F, 73.01F } ;        /* Referenced by: '<S166>/1D_Lookup_Table1' */

const volatile float32 thmf_X_Pmp2McuIdleDecPct[6] = { 44.99F, 45.0F, 55.0F,
  60.0F, 65.0F, 65.01F } ;        /* Referenced by: '<S169>/1D_Lookup_Table5' */

const volatile float32 thmf_X_Pmp2McuIdleIncPct[6] = { 49.99F, 50.0F, 60.0F,
  65.0F, 70.0F, 70.01F } ;        /* Referenced by: '<S169>/1D_Lookup_Table2' */

const volatile float32 thmf_X_Pmp2MotorIdleDecPct[6] = { 74.99F, 75.0F, 85.0F,
  95.0F, 110.0F, 110.01F } ;      /* Referenced by: '<S171>/1D_Lookup_Table7' */

const volatile float32 thmf_X_Pmp2MotorIdleIncPct[6] = { 79.99F, 80.0F, 90.0F,
  100.0F, 115.0F, 115.01F } ;     /* Referenced by: '<S171>/1D_Lookup_Table3' */

const volatile float32 thmf_X_Pmp2SnsrTempIdleDecPct[8] = { 40.99F, 41.0F, 42.0F,
  45.0F, 46.0F, 47.0F, 48.0F, 48.01F } ;
                                  /* Referenced by: '<S163>/1D_Lookup_Table1' */

const volatile float32 thmf_X_Pmp2SnsrTempIdleIncPct[8] = { 42.99F, 43.0F, 45.0F,
  47.0F, 48.0F, 49.0F, 50.0F, 50.01F } ;
                                   /* Referenced by: '<S163>/1D_Lookup_Table' */

const volatile float32 thmf_X_SnsrTempFan1Dec_t[5] = { 47.99F, 48.0F, 50.0F,
  50.01F, 55.0F } ;                /* Referenced by: '<S80>/1D_Lookup_Table7' */

const volatile float32 thmf_X_SnsrTempFan1Inc_t[5] = { 48.0F, 50.0F, 55.0F,
  58.0F, 59.0F } ;                 /* Referenced by: '<S80>/1D_Lookup_Table6' */

const volatile float32 thmf_X_SnsrTempFanDec_t[5] = { 45.0F, 47.0F, 47.01F,
  55.0F, 58.0F } ;                 /* Referenced by: '<S81>/1D_Lookup_Table7' */

const volatile float32 thmf_X_SnsrTempFanInc_t[4] = { 45.0F, 47.0F, 50.0F, 58.0F
} ;                                /* Referenced by: '<S81>/1D_Lookup_Table6' */

const volatile float32 thmf_X_dcdcTempFan1DecChr_t[5] = { 79.99F, 80.0F, 85.0F,
  85.01F, 90.0F } ;                /* Referenced by: '<S84>/1D_Lookup_Table7' */

const volatile float32 thmf_X_dcdcTempFan1Dec_t[7] = { 60.0F, 65.0F, 65.01F,
  70.0F, 70.01F, 75.0F, 77.0F } ;  /* Referenced by: '<S82>/1D_Lookup_Table7' */

const volatile float32 thmf_X_dcdcTempFan1IncChr_t[4] = { 80.0F, 85.0F, 90.0F,
  95.0F } ;                        /* Referenced by: '<S84>/1D_Lookup_Table6' */

const volatile float32 thmf_X_dcdcTempFan1Inc_t[5] = { 58.0F, 65.0F, 70.0F,
  75.0F, 77.0F } ;                 /* Referenced by: '<S82>/1D_Lookup_Table6' */

const volatile float32 thmf_X_dcdcTempFanDecChr_t[4] = { 80.0F, 80.01F, 85.0F,
  90.0F } ;                        /* Referenced by: '<S85>/1D_Lookup_Table7' */

const volatile float32 thmf_X_dcdcTempFanDec_t[6] = { 58.0F, 60.0F, 67.0F,
  67.01F, 73.0F, 77.0F } ;         /* Referenced by: '<S83>/1D_Lookup_Table7' */

const volatile float32 thmf_X_dcdcTempFanIncChr_t[3] = { 80.0F, 85.0F, 90.0F } ;
                                   /* Referenced by: '<S85>/1D_Lookup_Table6' */

const volatile float32 thmf_X_dcdcTempFanInc_t[5] = { 58.0F, 60.0F, 67.0F, 73.0F,
  77.0F } ;                        /* Referenced by: '<S83>/1D_Lookup_Table6' */

const volatile float32 thmf_X_fan1DcdcTempChgDecAirCl_t[8] = { 84.99F, 85.0F,
  88.0F, 90.0F, 92.0F, 95.0F, 97.0F, 98.0F } ;
                                   /* Referenced by: '<S65>/1D_Lookup_Table7' */

const volatile float32 thmf_X_fan1DcdcTempChgIncAirCl_t[8] = { 84.99F, 85.0F,
  88.0F, 90.0F, 92.0F, 95.0F, 97.0F, 98.0F } ;
                                   /* Referenced by: '<S65>/1D_Lookup_Table6' */

const volatile float32 thmf_X_fan1VehSpdAirCl_kph[5] = { 30.0F, 60.0F, 80.0F,
  100.0F, 120.0F } ;               /* Referenced by: '<S63>/2-D Lookup Table' */

const volatile float32 thmf_X_fan1dcdcTempDecAirCl_t[7] = { 70.0F, 72.0F, 74.0F,
  76.0F, 78.0F, 80.0F, 82.0F } ;   /* Referenced by: '<S64>/1D_Lookup_Table7' */

const volatile float32 thmf_X_fan1dcdcTempIncAirCl_t[7] = { 70.0F, 72.0F, 74.0F,
  76.0F, 78.0F, 80.0F, 82.0F } ;   /* Referenced by: '<S64>/1D_Lookup_Table6' */

const volatile float32 thmf_X_fan1inv2TempDecAirCl_t[7] = { 70.0F, 72.0F, 74.0F,
  76.0F, 78.0F, 80.0F, 82.0F } ;   /* Referenced by: '<S66>/1D_Lookup_Table7' */

const volatile float32 thmf_X_fan1inv2TempIncAirCl_t[7] = { 70.0F, 72.0F, 74.0F,
  76.0F, 78.0F, 80.0F, 82.0F } ;   /* Referenced by: '<S66>/1D_Lookup_Table6' */

const volatile float32 thmf_X_fan1mot2TempDecAirCl_t[8] = { 114.99F, 115.0F,
  120.0F, 125.0F, 130.0F, 135.0F, 140.0F, 145.0F } ;
                                   /* Referenced by: '<S67>/1D_Lookup_Table7' */

const volatile float32 thmf_X_fan1mot2TempIncAirCl_t[8] = { 114.99F, 115.0F,
  120.0F, 125.0F, 130.0F, 135.0F, 140.0F, 145.0F } ;
                                   /* Referenced by: '<S67>/1D_Lookup_Table6' */

const volatile float32 thmf_X_fan1obcTempChgDecAirCl_t[6] = { 119.99F, 120.0F,
  122.0F, 124.0F, 126.0F, 130.0F } ;
                                   /* Referenced by: '<S68>/1D_Lookup_Table3' */

const volatile float32 thmf_X_fan1obcTempChgIncAirCl_t[6] = { 119.99F, 120.0F,
  122.0F, 124.0F, 126.0F, 130.0F } ;
                                   /* Referenced by: '<S68>/1D_Lookup_Table2' */

const volatile float32 thmf_X_fan1ts5TempChgDecAirCl_t[8] = { 50.0F, 52.0F,
  54.0F, 56.0F, 58.0F, 60.0F, 62.0F, 65.0F } ;
                                   /* Referenced by: '<S69>/1D_Lookup_Table7' */

const volatile float32 thmf_X_fan1ts5TempChgIncAirCl_t[8] = { 50.0F, 52.0F,
  54.0F, 56.0F, 58.0F, 60.0F, 62.0F, 65.0F } ;
                                   /* Referenced by: '<S69>/1D_Lookup_Table6' */

const volatile float32 thmf_X_inv2TempFan1Dec_t[7] = { 60.0F, 65.0F, 65.01F,
  70.0F, 70.01F, 75.0F, 77.0F } ;  /* Referenced by: '<S86>/1D_Lookup_Table7' */

const volatile float32 thmf_X_inv2TempFan1Inc_t[5] = { 60.0F, 65.0F, 70.0F,
  75.0F, 77.0F } ;                 /* Referenced by: '<S86>/1D_Lookup_Table6' */

const volatile float32 thmf_X_inv2TempFanDec_t[6] = { 58.0F, 60.0F, 67.0F,
  67.01F, 73.0F, 77.0F } ;         /* Referenced by: '<S87>/1D_Lookup_Table7' */

const volatile float32 thmf_X_inv2TempFanInc_t[5] = { 58.0F, 60.0F, 67.0F, 73.0F,
  77.0F } ;                        /* Referenced by: '<S87>/1D_Lookup_Table6' */

const volatile float32 thmf_X_mot2TempFan1lowDec_t[7] = { 108.0F, 110.0F,
  110.01F, 115.0F, 115.01F, 120.0F, 125.0F } ;
                                   /* Referenced by: '<S88>/1D_Lookup_Table7' */

const volatile float32 thmf_X_mot2TempFan1lowInc_t[5] = { 108.0F, 110.0F, 115.0F,
  120.0F, 125.0F } ;               /* Referenced by: '<S88>/1D_Lookup_Table6' */

const volatile float32 thmf_X_mot2TempFanlowDec_t[6] = { 108.0F, 110.0F, 114.0F,
  114.01F, 120.0F, 125.0F } ;      /* Referenced by: '<S89>/1D_Lookup_Table7' */

const volatile float32 thmf_X_mot2TempFanlowInc_t[5] = { 108.0F, 110.0F, 114.0F,
  120.0F, 125.0F } ;               /* Referenced by: '<S89>/1D_Lookup_Table6' */

const volatile float32 thmf_X_obcTempFan1Dec_t[5] = { 114.99F, 115.0F, 120.0F,
  120.01F, 125.0F } ;              /* Referenced by: '<S90>/1D_Lookup_Table3' */

const volatile float32 thmf_X_obcTempFan1Inc_t[4] = { 114.99F, 120.0F, 125.0F,
  130.0F } ;                       /* Referenced by: '<S90>/1D_Lookup_Table2' */

const volatile float32 thmf_X_obcTempFanDec_t[4] = { 110.0F, 115.0F, 115.01F,
  130.0F } ;                       /* Referenced by: '<S91>/1D_Lookup_Table3' */

const volatile float32 thmf_X_obcTempFanInc_t[3] = { 115.0F, 120.0F, 130.0F } ;
                                   /* Referenced by: '<S91>/1D_Lookup_Table2' */

const volatile float32 thmf_X_pmp2DcdcTempChgDecAirCl_t[5] = { 61.99F, 62.0F,
  64.0F, 66.0F, 68.0F } ;         /* Referenced by: '<S167>/1D_Lookup_Table3' */

const volatile float32 thmf_X_pmp2DcdcTempChgIncAirCl_t[5] = { 61.99F, 62.0F,
  64.0F, 66.0F, 68.0F } ;         /* Referenced by: '<S167>/1D_Lookup_Table2' */

const volatile float32 thmf_X_pmp2DcdcTempReqDecAirCl_t[5] = { 49.99F, 50.0F,
  60.0F, 65.0F, 70.0F } ;         /* Referenced by: '<S165>/1D_Lookup_Table3' */

const volatile float32 thmf_X_pmp2DcdcTempReqIncAirCl_t[5] = { 49.99F, 50.0F,
  60.0F, 65.0F, 70.0F } ;         /* Referenced by: '<S165>/1D_Lookup_Table2' */

const volatile float32 thmf_X_pmp2Inv2TempReqDecAirCl_t[5] = { 49.99F, 50.0F,
  60.0F, 65.0F, 70.0F } ;         /* Referenced by: '<S168>/1D_Lookup_Table5' */

const volatile float32 thmf_X_pmp2Inv2TempReqIncAirCl_t[5] = { 49.99F, 50.0F,
  60.0F, 65.0F, 70.0F } ;         /* Referenced by: '<S168>/1D_Lookup_Table4' */

const volatile float32 thmf_X_pmp2Mot2TempReqDecAirCl_t[5] = { 79.99F, 80.0F,
  90.0F, 100.0F, 115.0F } ;       /* Referenced by: '<S170>/1D_Lookup_Table7' */

const volatile float32 thmf_X_pmp2Mot2TempReqIncAirCl_t[5] = { 79.99F, 80.0F,
  90.0F, 100.0F, 115.0F } ;       /* Referenced by: '<S170>/1D_Lookup_Table6' */

const volatile float32 thmf_X_pmp2ObcTempDecBig_t[5] = { 100.0F, 103.0F, 106.0F,
  109.0F, 113.0F } ;              /* Referenced by: '<S172>/1D_Lookup_Table3' */

const volatile float32 thmf_X_pmp2ObcTempIncBigAirCl_t[5] = { 61.99F, 62.0F,
  64.0F, 66.0F, 68.0F } ;         /* Referenced by: '<S172>/1D_Lookup_Table2' */

const volatile float32 thmf_X_pmp2SnsrTempChrDecAirCl_t[7] = { 39.99F, 40.0F,
  42.0F, 44.0F, 46.0F, 48.0F, 50.0F } ;
                                  /* Referenced by: '<S164>/1D_Lookup_Table1' */

const volatile float32 thmf_X_pmp2SnsrTempChrIncAirCl_t[7] = { 39.99F, 40.0F,
  42.0F, 44.0F, 46.0F, 48.0F, 50.0F } ;
                                   /* Referenced by: '<S164>/1D_Lookup_Table' */

const volatile float32 thmf_X_pmp2SnsrTempReqDecAirCl_t[7] = { 39.99F, 40.0F,
  42.0F, 44.0F, 46.0F, 48.0F, 50.0F } ;
                                  /* Referenced by: '<S162>/1D_Lookup_Table1' */

const volatile float32 thmf_X_pmp2SnsrTempReqIncAirCl_t[7] = { 39.99F, 40.0F,
  42.0F, 44.0F, 46.0F, 48.0F, 50.0F } ;
                                   /* Referenced by: '<S162>/1D_Lookup_Table' */

const volatile float32 thmf_X_pmp2TgtSpd_pct[9] = { 10.0F, 20.0F, 30.0F, 40.0F,
  50.0F, 60.0F, 70.0F, 80.0F, 92.0F } ;
                                  /* Referenced by: '<S148>/1-D Lookup Table' */

const volatile float32 thmf_X_ts5TempFan1Dec_t[7] = { 59.99F, 60.0F, 65.0F,
  65.01F, 70.0F, 71.0F, 72.0F } ;  /* Referenced by: '<S92>/1D_Lookup_Table7' */

const volatile float32 thmf_X_ts5TempFan1Inc_t[5] = { 64.99F, 65.0F, 70.0F,
  70.01F, 75.0F } ;                /* Referenced by: '<S92>/1D_Lookup_Table6' */

const volatile float32 thmf_X_ts5TempFanDec_t[6] = { 48.0F, 50.0F, 52.0F, 52.01F,
  55.0F, 60.0F } ;                 /* Referenced by: '<S93>/1D_Lookup_Table7' */

const volatile float32 thmf_X_ts5TempFanInc_t[5] = { 48.0F, 50.0F, 52.0F, 55.0F,
  60.0F } ;                        /* Referenced by: '<S93>/1D_Lookup_Table6' */

const volatile float32 thmf_Y_ObcEdcpDecPct[7] = { 10.0F, 30.0F, 50.0F, 80.0F,
  95.0F, 95.0F, 95.0F } ;         /* Referenced by: '<S173>/1D_Lookup_Table3' */

const volatile float32 thmf_Y_ObcEdcpIdleDecPct[7] = { 10.0F, 20.0F, 20.0F,
  20.0F, 20.0F, 20.0F, 95.0F } ;  /* Referenced by: '<S174>/1D_Lookup_Table3' */

const volatile float32 thmf_Y_ObcEdcpIdleIncPct[7] = { 10.0F, 20.0F, 20.0F,
  20.0F, 20.0F, 20.0F, 95.0F } ;  /* Referenced by: '<S174>/1D_Lookup_Table2' */

const volatile float32 thmf_Y_ObcEdcpIncPct[7] = { 10.0F, 30.0F, 50.0F, 80.0F,
  95.0F, 95.0F, 95.0F } ;         /* Referenced by: '<S173>/1D_Lookup_Table2' */

const volatile float32 thmf_Y_PassCoolSnsrTempFan1_pct[4] = { 30.0F, 40.0F,
  50.0F, 50.0F } ;                 /* Referenced by: '<S37>/1D_Lookup_Table6' */

const volatile float32 thmf_Y_Pmp2DcdcIdleDecPct[6] = { 10.0F, 20.0F, 20.0F,
  20.0F, 20.0F, 30.0F } ;         /* Referenced by: '<S166>/1D_Lookup_Table3' */

const volatile float32 thmf_Y_Pmp2DcdcIdleIncPct[6] = { 10.0F, 20.0F, 20.0F,
  20.0F, 20.0F, 30.0F } ;         /* Referenced by: '<S166>/1D_Lookup_Table1' */

const volatile float32 thmf_Y_Pmp2McuIdleDecPct[6] = { 10.0F, 20.0F, 20.0F,
  20.0F, 20.0F, 30.0F } ;         /* Referenced by: '<S169>/1D_Lookup_Table5' */

const volatile float32 thmf_Y_Pmp2McuIdleIncPct[6] = { 10.0F, 20.0F, 20.0F,
  20.0F, 20.0F, 30.0F } ;         /* Referenced by: '<S169>/1D_Lookup_Table2' */

const volatile float32 thmf_Y_Pmp2MotorIdleDecPct[6] = { 10.0F, 20.0F, 20.0F,
  20.0F, 20.0F, 30.0F } ;         /* Referenced by: '<S171>/1D_Lookup_Table7' */

const volatile float32 thmf_Y_Pmp2MotorIdleIncPct[6] = { 10.0F, 20.0F, 20.0F,
  20.0F, 20.0F, 30.0F } ;         /* Referenced by: '<S171>/1D_Lookup_Table3' */

const volatile float32 thmf_Y_Pmp2SnsrTempIdleDecPct[8] = { 10.0F, 20.0F, 20.0F,
  20.0F, 20.0F, 20.0F, 20.0F, 30.0F } ;
                                  /* Referenced by: '<S163>/1D_Lookup_Table1' */

const volatile float32 thmf_Y_Pmp2SnsrTempIdleIncPct[8] = { 10.0F, 20.0F, 20.0F,
  20.0F, 20.0F, 20.0F, 20.0F, 30.0F } ;
                                   /* Referenced by: '<S163>/1D_Lookup_Table' */

const volatile float32 thmf_Y_SnsrTempFan1Dec_pct[5] = { 0.0F, 50.0F, 50.0F,
  100.0F, 100.0F } ;               /* Referenced by: '<S80>/1D_Lookup_Table7' */

const volatile float32 thmf_Y_SnsrTempFan1Inc_pct[5] = { 0.0F, 50.0F, 100.0F,
  100.0F, 100.0F } ;               /* Referenced by: '<S80>/1D_Lookup_Table6' */

const volatile float32 thmf_Y_SnsrTempFanDec_pct[5] = { 0.0F, 0.0F, 50.0F, 50.0F,
  50.0F } ;                        /* Referenced by: '<S81>/1D_Lookup_Table7' */

const volatile float32 thmf_Y_SnsrTempFanInc_pct[4] = { 0.0F, 0.0F, 50.0F, 50.0F
} ;                                /* Referenced by: '<S81>/1D_Lookup_Table6' */

const volatile float32 thmf_Y_dcdcTempFan1DecChr_pct[5] = { 0.0F, 50.0F, 50.0F,
  100.0F, 100.0F } ;               /* Referenced by: '<S84>/1D_Lookup_Table7' */

const volatile float32 thmf_Y_dcdcTempFan1Dec_pct[7] = { 0.0F, 0.0F, 50.0F,
  50.0F, 100.0F, 100.0F, 100.0F } ;/* Referenced by: '<S82>/1D_Lookup_Table7' */

const volatile float32 thmf_Y_dcdcTempFan1IncChr_pct[4] = { 0.0F, 50.0F, 100.0F,
  100.0F } ;                       /* Referenced by: '<S84>/1D_Lookup_Table6' */

const volatile float32 thmf_Y_dcdcTempFan1Inc_pct[5] = { 0.0F, 0.0F, 50.0F,
  100.0F, 100.0F } ;               /* Referenced by: '<S82>/1D_Lookup_Table6' */

const volatile float32 thmf_Y_dcdcTempFanDecChr_pct[4] = { 0.0F, 50.0F, 50.0F,
  50.0F } ;                        /* Referenced by: '<S85>/1D_Lookup_Table7' */

const volatile float32 thmf_Y_dcdcTempFanDec_pct[6] = { 0.0F, 0.0F, 0.0F, 50.0F,
  50.0F, 50.0F } ;                 /* Referenced by: '<S83>/1D_Lookup_Table7' */

const volatile float32 thmf_Y_dcdcTempFanIncChr_pct[3] = { 0.0F, 50.0F, 50.0F } ;
                                   /* Referenced by: '<S85>/1D_Lookup_Table6' */

const volatile float32 thmf_Y_dcdcTempFanInc_pct[5] = { 0.0F, 0.0F, 0.0F, 50.0F,
  50.0F } ;                        /* Referenced by: '<S83>/1D_Lookup_Table6' */

const volatile float32 thmf_Y_fan1DcdcTempChgDecAirCl_pct[8] = { 5.0F, 30.0F,
  60.0F, 75.0F, 92.0F, 92.0F, 92.0F, 92.0F } ;
                                   /* Referenced by: '<S65>/1D_Lookup_Table7' */

const volatile float32 thmf_Y_fan1DcdcTempChgIncAirCl_pct[8] = { 5.0F, 15.0F,
  30.0F, 60.0F, 75.0F, 92.0F, 92.0F, 92.0F } ;
                                   /* Referenced by: '<S65>/1D_Lookup_Table6' */

const volatile float32 thmf_Y_fan1SnsrTempAirCl_t[7] = { 39.99F, 40.0F, 45.0F,
  50.0F, 55.0F, 60.0F, 63.0F } ;   /* Referenced by: '<S63>/2-D Lookup Table' */

const volatile float32 thmf_Y_fan1dcdcTempDecAirCl_pct[7] = { 5.0F, 30.0F, 40.0F,
  60.0F, 75.0F, 92.0F, 92.0F } ;   /* Referenced by: '<S64>/1D_Lookup_Table7' */

const volatile float32 thmf_Y_fan1dcdcTempIncAirCl_pct[7] = { 5.0F, 15.0F, 30.0F,
  40.0F, 60.0F, 75.0F, 92.0F } ;   /* Referenced by: '<S64>/1D_Lookup_Table6' */

const volatile float32 thmf_Y_fan1inv2TempDecAirCl_pct[7] = { 5.0F, 30.0F, 40.0F,
  60.0F, 75.0F, 92.0F, 92.0F } ;   /* Referenced by: '<S66>/1D_Lookup_Table7' */

const volatile float32 thmf_Y_fan1inv2TempIncAirCl_pct[7] = { 5.0F, 15.0F, 30.0F,
  40.0F, 60.0F, 75.0F, 92.0F } ;   /* Referenced by: '<S66>/1D_Lookup_Table6' */

const volatile float32 thmf_Y_fan1mot2TempDecAirCl_pct[8] = { 5.0F, 30.0F, 60.0F,
  70.0F, 80.0F, 92.0F, 92.0F, 92.0F } ;
                                   /* Referenced by: '<S67>/1D_Lookup_Table7' */

const volatile float32 thmf_Y_fan1mot2TempIncAirCl_pct[8] = { 5.0F, 15.0F, 30.0F,
  60.0F, 70.0F, 80.0F, 92.0F, 92.0F } ;
                                   /* Referenced by: '<S67>/1D_Lookup_Table6' */

const volatile float32 thmf_Y_fan1obcTempChgDecAirCl_pct[6] = { 5.0F, 30.0F,
  60.0F, 75.0F, 92.0F, 92.0F } ;   /* Referenced by: '<S68>/1D_Lookup_Table3' */

const volatile float32 thmf_Y_fan1obcTempChgIncAirCl_pct[6] = { 5.0F, 15.0F,
  30.0F, 60.0F, 75.0F, 92.0F } ;   /* Referenced by: '<S68>/1D_Lookup_Table2' */

const volatile float32 thmf_Y_fan1ts5TempChgDecAirCl_pct[8] = { 5.0F, 30.0F,
  40.0F, 50.0F, 60.0F, 70.0F, 92.0F, 92.0F } ;
                                   /* Referenced by: '<S69>/1D_Lookup_Table7' */

const volatile float32 thmf_Y_fan1ts5TempChgIncAirCl_pct[8] = { 5.0F, 15.0F,
  30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 92.0F } ;
                                   /* Referenced by: '<S69>/1D_Lookup_Table6' */

const volatile float32 thmf_Y_inv2TempFan1Dec_pct[7] = { 0.0F, 0.0F, 50.0F,
  50.0F, 100.0F, 100.0F, 100.0F } ;/* Referenced by: '<S86>/1D_Lookup_Table7' */

const volatile float32 thmf_Y_inv2TempFan1Inc_pct[5] = { 0.0F, 0.0F, 50.0F,
  100.0F, 100.0F } ;               /* Referenced by: '<S86>/1D_Lookup_Table6' */

const volatile float32 thmf_Y_inv2TempFanDec_pct[6] = { 0.0F, 0.0F, 0.0F, 50.0F,
  50.0F, 50.0F } ;                 /* Referenced by: '<S87>/1D_Lookup_Table7' */

const volatile float32 thmf_Y_inv2TempFanInc_pct[5] = { 0.0F, 0.0F, 0.0F, 50.0F,
  50.0F } ;                        /* Referenced by: '<S87>/1D_Lookup_Table6' */

const volatile float32 thmf_Y_mot2TempFan1lowDec_pct[7] = { 0.0F, 0.0F, 50.0F,
  50.0F, 100.0F, 100.0F, 100.0F } ;/* Referenced by: '<S88>/1D_Lookup_Table7' */

const volatile float32 thmf_Y_mot2TempFan1lowInc_pct[5] = { 0.0F, 0.0F, 50.0F,
  100.0F, 100.0F } ;               /* Referenced by: '<S88>/1D_Lookup_Table6' */

const volatile float32 thmf_Y_mot2TempFanlowDec_pct[6] = { 0.0F, 0.0F, 0.0F,
  50.0F, 50.0F, 50.0F } ;          /* Referenced by: '<S89>/1D_Lookup_Table7' */

const volatile float32 thmf_Y_mot2TempFanlowInc_pct[5] = { 0.0F, 0.0F, 0.0F,
  50.0F, 50.0F } ;                 /* Referenced by: '<S89>/1D_Lookup_Table6' */

const volatile float32 thmf_Y_obcTempFan1Dec_pct[5] = { 0.0F, 50.0F, 50.0F,
  100.0F, 100.0F } ;               /* Referenced by: '<S90>/1D_Lookup_Table3' */

const volatile float32 thmf_Y_obcTempFan1Inc_pct[4] = { 0.0F, 50.0F, 100.0F,
  100.0F } ;                       /* Referenced by: '<S90>/1D_Lookup_Table2' */

const volatile float32 thmf_Y_obcTempFanDec_pct[4] = { 0.0F, 0.0F, 50.0F, 50.0F
} ;                                /* Referenced by: '<S91>/1D_Lookup_Table3' */

const volatile float32 thmf_Y_obcTempFanInc_pct[3] = { 0.0F, 50.0F, 50.0F } ;
                                   /* Referenced by: '<S91>/1D_Lookup_Table2' */

const volatile float32 thmf_Y_pmp2DcdcTempChgDecAirCl_pct[5] = { 10.0F, 30.0F,
  50.0F, 80.0F, 95.0F } ;         /* Referenced by: '<S167>/1D_Lookup_Table3' */

const volatile float32 thmf_Y_pmp2DcdcTempChgIncAirCl_pct[5] = { 10.0F, 30.0F,
  50.0F, 80.0F, 95.0F } ;         /* Referenced by: '<S167>/1D_Lookup_Table2' */

const volatile float32 thmf_Y_pmp2DcdcTempReqDecAirCl_pct[5] = { 10.0F, 20.0F,
  50.0F, 80.0F, 95.0F } ;         /* Referenced by: '<S165>/1D_Lookup_Table3' */

const volatile float32 thmf_Y_pmp2DcdcTempReqIncAirCl_pct[5] = { 10.0F, 20.0F,
  50.0F, 80.0F, 95.0F } ;         /* Referenced by: '<S165>/1D_Lookup_Table2' */

const volatile float32 thmf_Y_pmp2FlowFeedback_Lmin[9] = { 0.0F, 8.4F, 8.9F,
  9.3F, 9.8F, 10.1F, 10.4F, 10.7F, 10.9F } ;
                                  /* Referenced by: '<S148>/1-D Lookup Table' */

const volatile float32 thmf_Y_pmp2Inv2TempReqDecAirCl_pct[5] = { 10.0F, 20.0F,
  50.0F, 80.0F, 95.0F } ;         /* Referenced by: '<S168>/1D_Lookup_Table5' */

const volatile float32 thmf_Y_pmp2Inv2TempReqIncAirCl_pct[5] = { 10.0F, 20.0F,
  50.0F, 80.0F, 95.0F } ;         /* Referenced by: '<S168>/1D_Lookup_Table4' */

const volatile float32 thmf_Y_pmp2Mot2TempReqDecAirCl_pct[5] = { 10.0F, 30.0F,
  50.0F, 80.0F, 95.0F } ;         /* Referenced by: '<S170>/1D_Lookup_Table7' */

const volatile float32 thmf_Y_pmp2Mot2TempReqIncAirCl_pct[5] = { 10.0F, 30.0F,
  50.0F, 80.0F, 95.0F } ;         /* Referenced by: '<S170>/1D_Lookup_Table6' */

const volatile float32 thmf_Y_pmp2ObcTempDecBig_pct[5] = { 10.0F, 30.0F, 50.0F,
  80.0F, 92.0F } ;                /* Referenced by: '<S172>/1D_Lookup_Table3' */

const volatile float32 thmf_Y_pmp2ObcTempIncBigAirCl_pct[5] = { 10.0F, 30.0F,
  50.0F, 80.0F, 95.0F } ;         /* Referenced by: '<S172>/1D_Lookup_Table2' */

const volatile float32 thmf_Y_pmp2SnsrTempChrDecAirCl_pct[7] = { 10.0F, 30.0F,
  50.0F, 60.0F, 70.0F, 80.0F, 95.0F } ;
                                  /* Referenced by: '<S164>/1D_Lookup_Table1' */

const volatile float32 thmf_Y_pmp2SnsrTempChrIncAirCl_pct[7] = { 10.0F, 30.0F,
  50.0F, 60.0F, 70.0F, 80.0F, 95.0F } ;
                                   /* Referenced by: '<S164>/1D_Lookup_Table' */

const volatile float32 thmf_Y_pmp2SnsrTempReqDecAirCl_pct[7] = { 10.0F, 20.0F,
  40.0F, 50.0F, 60.0F, 70.0F, 95.0F } ;
                                  /* Referenced by: '<S162>/1D_Lookup_Table1' */

const volatile float32 thmf_Y_pmp2SnsrTempReqIncAirCl_pct[7] = { 10.0F, 20.0F,
  40.0F, 50.0F, 60.0F, 70.0F, 95.0F } ;
                                   /* Referenced by: '<S162>/1D_Lookup_Table' */

const volatile float32 thmf_Y_ts5TempFan1Dec_pct[7] = { 0.0F, 50.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F } ;
                                   /* Referenced by: '<S92>/1D_Lookup_Table7' */

const volatile float32 thmf_Y_ts5TempFan1Inc_pct[5] = { 0.0F, 50.0F, 100.0F,
  100.0F, 100.0F } ;               /* Referenced by: '<S92>/1D_Lookup_Table6' */

const volatile float32 thmf_Y_ts5TempFanDec_pct[6] = { 0.0F, 0.0F, 0.0F, 50.0F,
  50.0F, 50.0F } ;                 /* Referenced by: '<S93>/1D_Lookup_Table7' */

const volatile float32 thmf_Y_ts5TempFanInc_pct[5] = { 0.0F, 0.0F, 0.0F, 50.0F,
  50.0F } ;                        /* Referenced by: '<S93>/1D_Lookup_Table6' */

const volatile float32 thmf_Z_fan1SnsrTempAirCl_pct[35] = { 5.0F, 5.0F, 5.0F,
  15.0F, 30.0F, 75.0F, 92.0F, 5.0F, 5.0F, 5.0F, 15.0F, 30.0F, 50.0F, 92.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 30.0F, 92.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
  92.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 92.0F } ;
                                   /* Referenced by: '<S63>/2-D Lookup Table' */

#define swc_THSM_STOP_SEC_CONST_VOLATILE
#include "swc_THSM_MemMap.h"
#define swc_THSM_START_SEC_VAR
#include "swc_THSM_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_SIG */
boolean thmd_b_FaultStsHvbIn_flg;      /* '<S116>/timed_debounce' */
boolean thmd_b_FaultStsHvbOut_flg;     /* '<S117>/timed_debounce' */
boolean thmd_b_FaultSts_flg;           /* '<S115>/timed_debounce' */

/* Fault status flg */
boolean thmd_b_FaultSts_flg1;          /* '<S9>/Switch' */
boolean thmd_b_NonVacFilling_flg;      /* '<S11>/Switch' */

/* Non Vacuum filling mode flg */
boolean thmd_b_accmEnaCnd1;            /* '<S3>/Logical Operator5' */

/* ACCM Enable condition 1 */
boolean thmd_b_accmEnaCnd2;            /* '<S3>/Logical Operator20' */

/* ACCM Enable condition 2 */
boolean thmd_b_accmEnaCnd3;            /* '<Root>/Data Type Conversion40' */

/* ACCM Enable condition 3 */
boolean thmd_b_accmEnb;                /* '<S3>/AccmOnOffProtection' */
boolean thmd_b_accmEnbChrflg;          /* '<S3>/Relational Operator11' */
boolean thmd_b_accmEnbRaw;             /* '<S3>/SR_latch1' */
boolean thmd_b_accmEnboffChrflg;       /* '<S3>/Logical Operator21' */
boolean thmd_b_accmEnterEnableFlg;     /* '<S3>/Logical Operator1' */
boolean thmd_b_accmExitEnableFlg;      /* '<S3>/Logical Operator23' */
boolean thmd_b_afterRunActive;         /* '<S20>/Logical Operator14' */

/* After-run active for cooling and power-hold */
boolean thmd_b_ewpOutTempFaultFlg;     /* '<S118>/timed_debounce' */
boolean thmd_b_fanCtrlEnabled;         /* '<S7>/Logical Operator1' */

/* Fan Control Enabled */
boolean thmd_b_fanRly1Req;             /* '<S38>/Switch' */

/* Fan Relay 1 request */
boolean thmd_b_fanRly2Req;             /* '<S39>/Switch' */

/* Fan Relay 2 request */
boolean thmd_b_heaterEna2;             /* '<S133>/Logical Operator3' */

/* BPTC Enable */
boolean thmd_b_heaterEna3;             /* '<S10>/SR_latch3' */

/* BPTC Enable */
boolean thmd_b_heaterEnaCnd1;          /* '<S10>/Logical Operator2' */

/* BPTC Enable condition 1 */
boolean thmd_b_heaterEnaCnd2;          /* '<S10>/Relational Operator5' */

/* BPTC Enable condition 2 */
boolean thmd_b_iptcEnbCmd2;            /* '<S10>/Logical Operator10' */
boolean thmd_b_ptc2EnterEnableFlg;     /* '<S10>/Logical Operator11' */
boolean thmd_b_ptc2ExitEnableFlg;      /* '<S10>/Logical Operator16' */
boolean thmd_b_ptc3EnterEnableFlg;     /* '<S10>/Logical Operator19' */
boolean thmd_b_ptc3ExitEnableFlg;      /* '<S10>/Logical Operator24' */
boolean thmd_b_ptcCanEnbFlg;           /* '<S137>/timed_delay' */
boolean thmd_b_ptcEna;                 /* '<S10>/SR_latch1' */

/* PTC Enable */
boolean thmd_b_ptcEnterEnableFlg;      /* '<S10>/Logical Operator3' */
boolean thmd_b_ptcExitEnableFlg;       /* '<S10>/Logical Operator6' */
boolean thmd_b_ptcHWEnbFlg;            /* '<S135>/timed_delay' */
boolean thmd_b_wtrPmp1CtrlEnabled;     /* '<S7>/Logical Operator3' */

/* Water Pump 1 Control Enabled */
boolean thmd_b_wtrPmp2CtrlEnabled;     /* '<S7>/Logical Operator4' */

/* Water Pump 2 Control Enabled */
boolean thmd_b_wtrPmpRly1Req;          /* '<S190>/Switch' */

/* Water Pump Relay 1 request */
boolean thmd_b_wtrPmpRly2Req;          /* '<S191>/Switch' */

/* Water Pump Relay 2 request */
FanStatus thmd_e_fanTgtSts;            /* '<S35>/Switch' */

/* Fan Target Status */
PumpStatus thmd_e_wtrPmp1TgtSts;       /* '<S150>/Switch4' */

/* Water Pump 1 Target Status */
PumpStatus thmd_e_wtrPmp2TgtSts;       /* '<S150>/Switch8' */

/* Water Pump 2 Target Status */
float32 thmd_n_SnsrTempFan1_pct;       /* '<S81>/Switch3' */

/* Fan1 Target Speed PWM BEV acording to SnsrTemp  */
float32 thmd_n_dcdcTempChrFan1_pct;    /* '<S85>/Switch3' */

/* Fan1 Target Speed in Charge mode PWM BEV acording to SnsrTemp  */
float32 thmd_n_dcdcTempFan1_pct;       /* '<S83>/Switch3' */

/* Fan1 Target Speed PWM BEV acording to SnsrTemp  */
float32 thmd_n_fan1DcdcTempAirCl_pct;  /* '<S64>/Switch3' */
float32 thmd_n_fan1DcdcTempChrAirCl_pct;/* '<S65>/Switch3' */
float32 thmd_n_fan1DelayModTgtSpd_pct; /* '<S33>/Switch2' */
float32 thmd_n_fan1DlyTgtSpdAirCl_pct; /* '<S34>/Switch2' */
float32 thmd_n_fan1Inv2TempAirCl_pct;  /* '<S66>/Switch3' */
float32 thmd_n_fan1Mot2TempAirCl_pct;  /* '<S67>/Switch3' */
float32 thmd_n_fan1SnsrTempAirCl_pct;  /* '<S63>/2-D Lookup Table' */
float32 thmd_n_fan1TgtSpdAirCl2_pct;   /* '<S34>/Switch6' */

/* Fan1 Target Speed PWM */
float32 thmd_n_fan1TgtSpdAirCl_pct;    /* '<S36>/Switch19' */
float32 thmd_n_fan1TgtSpdLdtBev_pct;   /* '<S37>/Switch19' */

/* Fan1 Target Speed PWM BEV */
float32 thmd_n_fan1TgtSpd_pct;         /* '<S33>/Switch6' */

/* Fan1 Target Speed PWM */
float32 thmd_n_fan1obcTempChrAirCl_pct;/* '<S68>/Switch1' */

/* Fan1 Target Speed in Charge mode PWM BEV acording to SnsrTemp  */
float32 thmd_n_fan1ts5TempChrAirCl_pct;/* '<S69>/Switch3' */
float32 thmd_n_fan300ts5TempTgtSpd_pct;/* '<S80>/Switch3' */
float32 thmd_n_inv2TempFan1_pct;       /* '<S87>/Switch3' */
float32 thmd_n_obcTempChrFan1_pct;     /* '<S91>/Switch1' */
float32 thmd_n_pmp1FaultTgtSpd_pct;    /* '<S147>/Switch11' */
float32 thmd_n_pmp1NewTgtSpd_pct;      /* '<S147>/Switch1' */

/* HBCP Target Speed  */
float32 thmd_n_pmp1SwapTgtSpd_pct;     /* '<S147>/Switch6' */
float32 thmd_n_pmp2IpuClTgtSpdAirCl_pct;/* '<S148>/Switch' */
float32 thmd_n_pmp2Kl15TgtSpdAirCl_pct;/* '<S148>/Switch2' */
float32 thmd_n_pmp2ObcTempTgtSpdBigAirCl_pct;/* '<S172>/Switch1' */
float32 thmd_n_pmp2TgtSpdAirCl_pct;    /* '<S148>/Switch1' */
float32 thmd_n_ts5TempChrFan1_pct;     /* '<S93>/Switch3' */

/* Fan1 Target Speed in Charge mode PWM BEV acording to SnsrTemp  */
float32 thmd_n_wtrPmp1NewTgtSpd_rpm;   /* '<S147>/Product2' */

/* HBCP Target Speed */
uint8 thmd_st_FanReqCmd;               /* '<S61>/Switch' */

/* Fan Request Command */
uint8 thmd_st_acwpHeat;                /* '<S10>/Switch1' */
uint8 thmd_st_ptc3ConnStsFb;           /* '<S13>/ptc3FaultStatus' */
uint8 thmd_st_ptc3RlyFlt;              /* '<S13>/ptc3FaultStatus' */
uint8 thmd_st_ptcConnStsFb;            /* '<S207>/Switch' */
uint8 thmd_st_ptcRlyFlt;               /* '<S207>/Switch1' */
uint8 thmd_st_wtrPmp1ReqCmd;           /* '<S200>/Switch' */

/* Water Pump 1 Request Command */
uint8 thmd_st_wtrPmp2ReqCmd;           /* '<S201>/Switch' */

/* Water Pump 2 Request Command */
float32 thmd_t_acwpTemp_C;             /* '<S10>/Switch' */

#define swc_THSM_STOP_SEC_VAR
#include "swc_THSM_MemMap.h"

/* Invariant block signals (default storage) */
const ConstB_swc_THSM_T swc_THSM_ConstB = {
  1.0,                                 /* '<S11>/Data Type Conversion1' */
  0.0F,                                /* '<S7>/Data Type Conversion' */
  0.0F,                                /* '<S7>/Data Type Conversion1' */
  0.0F,                                /* '<S7>/Data Type Conversion2' */
  0.0F,                                /* '<S7>/Data Type Conversion3' */
  0U,                                  /* '<Root>/Data Type Conversion85' */
  0U,                                  /* '<Root>/Data Type Conversion90' */
  1U,                                  /* '<S14>/Constant' */
  0,                                   /* '<Root>/Data Type Conversion83' */
  0,                                   /* '<Root>/Data Type Conversion86' */
  0,                                   /* '<Root>/Data Type Conversion88' */
  0,                                   /* '<Root>/Data Type Conversion89' */
  0,                                   /* '<Root>/Data Type Conversion91' */
  0,                                   /* '<Root>/Data Type Conversion96' */
  1,                                   /* '<S20>/Logical Operator1' */

  /* Start of '<S20>/SR_latch' */
  {
    0                                  /* '<S24>/Logical Operator1' */
  }
  /* End of '<S20>/SR_latch' */
};

/* Constant parameters (default storage) */
const ConstP_swc_THSM_T swc_THSM_ConstP = {
  /* Computed Parameter: uDLookupTable_maxIndex
   * Referenced by: '<S63>/2-D Lookup Table'
   */
  { 6U, 4U }
};

/* PublicStructure Variables for Internal Data */
ARID_DEF_swc_THSM_T swc_THSM_ARID_DEF;
static float32 look1_iflf_binlxpw(float32 u0, const float32 bp0[], const float32
  table[], uint32 maxIndex);
static float32 look2_iflf_binlcpw(float32 u0, float32 u1, const float32 bp0[],
  const float32 bp1[], const float32 table[], const uint32 maxIndex[], uint32
  stride);
static float32 look1_iflf_binlcapw(float32 u0, const float32 bp0[], const
  float32 table[], uint32 maxIndex);
static uint32 plook_u32f_bincka(float32 u, const float32 bp[], uint32 maxIndex);
static uint32 binsearch_u32f(float32 u, const float32 bp[], uint32 startIndex,
  uint32 maxIndex);
static void swc_THSM_SR_latch1(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch1_swc_THSM_T *swc_THSM__ARID_DEF_arg);
static void swc_THSM_SR_latch(boolean rtu_flg_set, boolean *rty_flg_out, const
  ConstB_SR_latch_swc_THSM_T *localC, ARID_DEF_SR_latch_swc_THSM_T
  *swc_THSM__ARID_DEF_arg);
static void swc_THSM_timed_delay_Init(boolean *rty_flg_out);
static void swc_THSM_timed_delay(boolean rtu_flg_in, float32 rtu_t_delay_off,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_timed_delay_swc_THSM_T
  *swc_THSM__ARID_DEF_arg);
static void swc_THSM_turnOFF_delay_Init(boolean *rty_flg_out);
static void swc_THSM_turnOFF_delay(boolean rtu_flg_in, float32 rtu_t_delay_off,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnOFF_delay_swc_TH_T
  *swc_THSM__ARID_DEF_arg);
static void swc_THSM_timed_delay_k_Init(boolean *rty_flg_out);
static void swc_THSM_timed_delay_e_Reset(boolean *rty_flg_out,
  ARID_DEF_timed_delay_swc_TH_c_T *swc_THSM__ARID_DEF_arg);
static void swc_THSM_timed_delay_c(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_timed_delay_swc_TH_c_T
  *swc_THSM__ARID_DEF_arg);
static void swc_THSM_turnON_delay_Init(boolean *rty_flg_out);
static void swc_THSM_turnON_delay_Reset(boolean *rty_flg_out,
  ARID_DEF_turnON_delay_swc_THS_T *swc_THSM__ARID_DEF_arg);
static void swc_THSM_turnON_delay(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnON_delay_swc_THS_T
  *swc_THSM__ARID_DEF_arg);
static void swc_THSM_SR_latch2(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch2_swc_THSM_T *swc_THSM__ARID_DEF_arg);
static void swc_THSM_SR_latch3(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch3_swc_THSM_T *swc_THSM__ARID_DEF_arg);
static void swc_THS_THM_ThermalControl_Init(void);
static void swc_THSM_THM_ThermalControl(void);
static float32 look1_iflf_binlxpw(float32 u0, const float32 bp0[], const float32
  table[], uint32 maxIndex)
{
  float32 frac;
  float32 yL_0d0;
  uint32 iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32 bpIdx;
    uint32 iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

static float32 look2_iflf_binlcpw(float32 u0, float32 u1, const float32 bp0[],
  const float32 bp1[], const float32 table[], const uint32 maxIndex[], uint32
  stride)
{
  float32 fractions[2];
  float32 frac;
  float32 yL_0d0;
  float32 yL_0d1;
  uint32 bpIndices[2];
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = 1.0F;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = 1.0F;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_0d0 = table[bpIdx];
  yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
  bpIdx += stride;
  yL_0d1 = table[bpIdx];
  return (((table[bpIdx + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

static float32 look1_iflf_binlcapw(float32 u0, const float32 bp0[], const
  float32 table[], uint32 maxIndex)
{
  float32 frac;
  float32 y;
  uint32 iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
    uint32 bpIdx;
    uint32 iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex;
    frac = 0.0F;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    float32 yL_0d0;
    yL_0d0 = table[iLeft];
    y = (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
  }

  return y;
}

static uint32 plook_u32f_bincka(float32 u, const float32 bp[], uint32 maxIndex)
{
  uint32 bpIndex;

  /* Prelookup - Index only
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32f(u, bp, maxIndex >> 1U, maxIndex);
  } else {
    bpIndex = maxIndex;
  }

  return bpIndex;
}

static uint32 binsearch_u32f(float32 u, const float32 bp[], uint32 startIndex,
  uint32 maxIndex)
{
  uint32 bpIdx;
  uint32 bpIndex;
  uint32 iRght;

  /* Binary Search */
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
}

/*
 * Output and update for atomic system:
 *    '<S3>/SR_latch1'
 *    '<S10>/SR_latch1'
 */
static void swc_THSM_SR_latch1(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch1_swc_THSM_T *swc_THSM__ARID_DEF_arg)
{
  /* Logic: '<S19>/Logical Operator3' incorporates:
   *  Logic: '<S19>/Logical Operator'
   *  Logic: '<S19>/Logical Operator1'
   *  UnitDelay: '<S19>/Unit Delay'
   */
  *rty_flg_out = ((swc_THSM__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) && (
    !rtu_flg_reset));

  /* Update for UnitDelay: '<S19>/Unit Delay' */
  swc_THSM__ARID_DEF_arg->UnitDelay_DSTATE = *rty_flg_out;
}

/* Output and update for atomic system: '<S20>/SR_latch' */
static void swc_THSM_SR_latch(boolean rtu_flg_set, boolean *rty_flg_out, const
  ConstB_SR_latch_swc_THSM_T *localC, ARID_DEF_SR_latch_swc_THSM_T
  *swc_THSM__ARID_DEF_arg)
{
  /* Logic: '<S24>/Logical Operator3' incorporates:
   *  Logic: '<S24>/Logical Operator'
   *  UnitDelay: '<S24>/Unit Delay'
   */
  *rty_flg_out = ((swc_THSM__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) &&
                  localC->LogicalOperator1);

  /* Update for UnitDelay: '<S24>/Unit Delay' */
  swc_THSM__ARID_DEF_arg->UnitDelay_DSTATE = *rty_flg_out;
}

/*
 * System initialize for atomic system:
 *    '<S25>/timed_delay'
 *    '<S26>/timed_delay'
 *    '<S27>/timed_delay'
 *    '<S44>/timed_delay'
 *    '<S49>/timed_delay'
 *    '<S136>/timed_delay'
 *    '<S155>/timed_delay'
 *    '<S175>/timed_delay'
 */
static void swc_THSM_timed_delay_Init(boolean *rty_flg_out)
{
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S25>/timed_delay'
 *    '<S26>/timed_delay'
 *    '<S27>/timed_delay'
 *    '<S44>/timed_delay'
 *    '<S49>/timed_delay'
 *    '<S136>/timed_delay'
 *    '<S155>/timed_delay'
 *    '<S175>/timed_delay'
 */
static void swc_THSM_timed_delay(boolean rtu_flg_in, float32 rtu_t_delay_off,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_timed_delay_swc_THSM_T
  *swc_THSM__ARID_DEF_arg)
{
  /* Chart: '<S25>/timed_delay' */
  if (swc_THSM__ARID_DEF_arg->is_active_c12_swc_THSM == 0U) {
    swc_THSM__ARID_DEF_arg->is_active_c12_swc_THSM = 1U;
    if (rtu_flg_in) {
      swc_THSM__ARID_DEF_arg->is_c12_swc_THSM = swc_THSM_IN_ON;
      *rty_flg_out = true;
    } else {
      swc_THSM__ARID_DEF_arg->is_c12_swc_THSM = swc_THSM_IN_OFF;
      *rty_flg_out = false;
    }
  } else {
    switch (swc_THSM__ARID_DEF_arg->is_c12_swc_THSM) {
     case swc_THSM_IN_OFF:
      if (rtu_flg_in) {
        swc_THSM__ARID_DEF_arg->is_c12_swc_THSM = swc_THSM_IN_ON;
        *rty_flg_out = true;
      } else {
        *rty_flg_out = false;
      }
      break;

     case swc_THSM_IN_OFF_WAIT:
      if (rtu_flg_in) {
        swc_THSM__ARID_DEF_arg->is_c12_swc_THSM = swc_THSM_IN_ON;
        *rty_flg_out = true;
      } else if (swc_THSM__ARID_DEF_arg->t_wait > rtu_t_delay_off - rtu_t_step)
      {
        swc_THSM__ARID_DEF_arg->is_c12_swc_THSM = swc_THSM_IN_OFF;
        *rty_flg_out = false;
      } else {
        swc_THSM__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = true;
      }
      break;

     default:
      /* case IN_ON: */
      if (!rtu_flg_in) {
        if (rtu_t_delay_off == 0.0F) {
          swc_THSM__ARID_DEF_arg->is_c12_swc_THSM = swc_THSM_IN_OFF;
          *rty_flg_out = false;
        } else {
          swc_THSM__ARID_DEF_arg->is_c12_swc_THSM = swc_THSM_IN_OFF_WAIT;
          swc_THSM__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = true;
        }
      } else {
        *rty_flg_out = true;
      }
      break;
    }
  }

  /* End of Chart: '<S25>/timed_delay' */
}

/*
 * System initialize for atomic system:
 *    '<S20>/turnOFF_delay'
 *    '<S20>/turnOFF_delay1'
 *    '<S20>/turnOFF_delay2'
 *    '<S33>/turnOFF_delay'
 *    '<S34>/turnOFF_delay'
 *    '<S147>/turnOFF_delay'
 *    '<S148>/turnOFF_delay'
 */
static void swc_THSM_turnOFF_delay_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S25>/timed_delay' */
  swc_THSM_timed_delay_Init(rty_flg_out);
}

/*
 * Output and update for atomic system:
 *    '<S20>/turnOFF_delay'
 *    '<S20>/turnOFF_delay1'
 *    '<S20>/turnOFF_delay2'
 *    '<S33>/turnOFF_delay'
 *    '<S34>/turnOFF_delay'
 *    '<S147>/turnOFF_delay'
 *    '<S148>/turnOFF_delay'
 */
static void swc_THSM_turnOFF_delay(boolean rtu_flg_in, float32 rtu_t_delay_off,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnOFF_delay_swc_TH_T
  *swc_THSM__ARID_DEF_arg)
{
  /* local block i/o variables */
  float32 rtb_t_delay_off_jz;
  boolean rtb_DataTypeConversion_l;

  /* DataTypeConversion: '<S25>/Data Type Conversion' */
  rtb_DataTypeConversion_l = rtu_flg_in;

  /* Saturate: '<S25>/Saturation1' */
  if (rtu_t_delay_off > 1.6777216E+7F) {
    /* Saturate: '<S25>/Saturation1' */
    rtb_t_delay_off_jz = 1.6777216E+7F;
  } else if (rtu_t_delay_off < 0.0F) {
    /* Saturate: '<S25>/Saturation1' */
    rtb_t_delay_off_jz = 0.0F;
  } else {
    /* Saturate: '<S25>/Saturation1' */
    rtb_t_delay_off_jz = rtu_t_delay_off;
  }

  /* End of Saturate: '<S25>/Saturation1' */

  /* Chart: '<S25>/timed_delay' */
  swc_THSM_timed_delay(rtb_DataTypeConversion_l, rtb_t_delay_off_jz, rtu_t_step,
                       rty_flg_out,
                       &swc_THSM__ARID_DEF_arg->ARID_DEF_timed_delay);
}

/*
 * System initialize for atomic system:
 *    '<S70>/timed_delay'
 *    '<S94>/timed_delay'
 *    '<S138>/timed_delay'
 *    '<S203>/timed_delay'
 *    '<S204>/timed_delay'
 *    '<S208>/timed_delay'
 *    '<S209>/timed_delay'
 */
static void swc_THSM_timed_delay_k_Init(boolean *rty_flg_out)
{
  *rty_flg_out = false;
}

/*
 * System reset for atomic system:
 *    '<S70>/timed_delay'
 *    '<S94>/timed_delay'
 *    '<S138>/timed_delay'
 *    '<S203>/timed_delay'
 *    '<S204>/timed_delay'
 *    '<S208>/timed_delay'
 *    '<S209>/timed_delay'
 */
static void swc_THSM_timed_delay_e_Reset(boolean *rty_flg_out,
  ARID_DEF_timed_delay_swc_TH_c_T *swc_THSM__ARID_DEF_arg)
{
  swc_THSM__ARID_DEF_arg->is_active_c9_swc_THSM = 0U;
  swc_THSM__ARID_DEF_arg->is_c9_swc_THSM = swc_THSM_IN_NO_ACTIVE_CHILD;
  swc_THSM__ARID_DEF_arg->t_wait = 0.0F;
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S70>/timed_delay'
 *    '<S94>/timed_delay'
 *    '<S138>/timed_delay'
 *    '<S203>/timed_delay'
 *    '<S204>/timed_delay'
 *    '<S208>/timed_delay'
 *    '<S209>/timed_delay'
 */
static void swc_THSM_timed_delay_c(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_timed_delay_swc_TH_c_T
  *swc_THSM__ARID_DEF_arg)
{
  /* Chart: '<S70>/timed_delay' */
  if (swc_THSM__ARID_DEF_arg->is_active_c9_swc_THSM == 0U) {
    swc_THSM__ARID_DEF_arg->is_active_c9_swc_THSM = 1U;
    if (rtu_flg_in) {
      swc_THSM__ARID_DEF_arg->is_c9_swc_THSM = swc_THSM_IN_ON_h;
      *rty_flg_out = true;
    } else {
      swc_THSM__ARID_DEF_arg->is_c9_swc_THSM = swc_THSM_IN_OFF_c;
      *rty_flg_out = false;
    }
  } else {
    switch (swc_THSM__ARID_DEF_arg->is_c9_swc_THSM) {
     case swc_THSM_IN_OFF_c:
      if (rtu_flg_in) {
        if (rtu_t_delay_on == 0.0F) {
          swc_THSM__ARID_DEF_arg->is_c9_swc_THSM = swc_THSM_IN_ON_h;
          *rty_flg_out = true;
        } else {
          swc_THSM__ARID_DEF_arg->is_c9_swc_THSM = swc_THSM_IN_ON_WAIT;
          swc_THSM__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = false;
        }
      } else {
        *rty_flg_out = false;
      }
      break;

     case swc_THSM_IN_ON_h:
      if (!rtu_flg_in) {
        swc_THSM__ARID_DEF_arg->is_c9_swc_THSM = swc_THSM_IN_OFF_c;
        *rty_flg_out = false;
      } else {
        *rty_flg_out = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtu_flg_in) {
        swc_THSM__ARID_DEF_arg->is_c9_swc_THSM = swc_THSM_IN_OFF_c;
        *rty_flg_out = false;
      } else if (swc_THSM__ARID_DEF_arg->t_wait > rtu_t_delay_on - rtu_t_step) {
        swc_THSM__ARID_DEF_arg->is_c9_swc_THSM = swc_THSM_IN_ON_h;
        *rty_flg_out = true;
      } else {
        swc_THSM__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = false;
      }
      break;
    }
  }

  /* End of Chart: '<S70>/timed_delay' */
}

/*
 * System initialize for atomic system:
 *    '<S36>/turnON_delay'
 *    '<S37>/turnON_delay'
 *    '<S202>/turnON_delay'
 *    '<S202>/turnON_delay1'
 *    '<S207>/turnON_delay'
 *    '<S207>/turnON_delay1'
 */
static void swc_THSM_turnON_delay_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S70>/timed_delay' */
  swc_THSM_timed_delay_k_Init(rty_flg_out);
}

/*
 * System reset for atomic system:
 *    '<S36>/turnON_delay'
 *    '<S37>/turnON_delay'
 *    '<S202>/turnON_delay'
 *    '<S202>/turnON_delay1'
 *    '<S207>/turnON_delay'
 *    '<S207>/turnON_delay1'
 */
static void swc_THSM_turnON_delay_Reset(boolean *rty_flg_out,
  ARID_DEF_turnON_delay_swc_THS_T *swc_THSM__ARID_DEF_arg)
{
  /* SystemReset for Chart: '<S70>/timed_delay' */
  swc_THSM_timed_delay_e_Reset(rty_flg_out,
    &swc_THSM__ARID_DEF_arg->ARID_DEF_timed_delay);
}

/*
 * Output and update for atomic system:
 *    '<S36>/turnON_delay'
 *    '<S37>/turnON_delay'
 *    '<S202>/turnON_delay'
 *    '<S202>/turnON_delay1'
 *    '<S207>/turnON_delay'
 *    '<S207>/turnON_delay1'
 */
static void swc_THSM_turnON_delay(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnON_delay_swc_THS_T
  *swc_THSM__ARID_DEF_arg)
{
  /* local block i/o variables */
  float32 rtb_t_delay_on_jd;
  boolean rtb_DataTypeConversion_eo;

  /* DataTypeConversion: '<S70>/Data Type Conversion' */
  rtb_DataTypeConversion_eo = rtu_flg_in;

  /* Saturate: '<S70>/Saturation' */
  if (rtu_t_delay_on > 1.6777216E+7F) {
    /* Saturate: '<S70>/Saturation' */
    rtb_t_delay_on_jd = 1.6777216E+7F;
  } else if (rtu_t_delay_on < 0.0F) {
    /* Saturate: '<S70>/Saturation' */
    rtb_t_delay_on_jd = 0.0F;
  } else {
    /* Saturate: '<S70>/Saturation' */
    rtb_t_delay_on_jd = rtu_t_delay_on;
  }

  /* End of Saturate: '<S70>/Saturation' */

  /* Chart: '<S70>/timed_delay' */
  swc_THSM_timed_delay_c(rtb_DataTypeConversion_eo, rtb_t_delay_on_jd,
    rtu_t_step, rty_flg_out, &swc_THSM__ARID_DEF_arg->ARID_DEF_timed_delay);
}

/* Output and update for atomic system: '<S10>/SR_latch2' */
static void swc_THSM_SR_latch2(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch2_swc_THSM_T *swc_THSM__ARID_DEF_arg)
{
  /* Logic: '<S133>/Logical Operator3' incorporates:
   *  Logic: '<S133>/Logical Operator'
   *  Logic: '<S133>/Logical Operator1'
   *  UnitDelay: '<S133>/Unit Delay'
   */
  thmd_b_heaterEna2 = ((swc_THSM__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set)
                       && (!rtu_flg_reset));

  /* Update for UnitDelay: '<S133>/Unit Delay' */
  swc_THSM__ARID_DEF_arg->UnitDelay_DSTATE = thmd_b_heaterEna2;
}

/* Output and update for atomic system: '<S10>/SR_latch3' */
static void swc_THSM_SR_latch3(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch3_swc_THSM_T *swc_THSM__ARID_DEF_arg)
{
  /* Logic: '<S134>/Logical Operator3' incorporates:
   *  Logic: '<S134>/Logical Operator'
   *  Logic: '<S134>/Logical Operator1'
   *  UnitDelay: '<S134>/Unit Delay'
   */
  *rty_flg_out = ((swc_THSM__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) && (
    !rtu_flg_reset));

  /* Update for UnitDelay: '<S134>/Unit Delay' */
  swc_THSM__ARID_DEF_arg->UnitDelay_DSTATE = *rty_flg_out;
}

/* System initialize for function-call system: '<S1>/THM_ThermalControl' */
static void swc_THS_THM_ThermalControl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_flg_out;
  boolean rtb_flg_out_e;
  boolean rtb_flg_out_a;
  boolean rtb_flg_out_o;
  boolean rtb_flg_out_ao;
  boolean rtb_flg_out_c;
  boolean rtb_flg_out_o1;
  boolean rtb_flg_out_am;
  boolean rtb_flg_out_eb;
  boolean rtb_flg_out_l;
  boolean rtb_flg_out_f;
  boolean rtb_flg_out_b;
  boolean rtb_flg_out_e0;

  /* InitializeConditions for Delay: '<S147>/Delay One Step1' */
  swc_THSM_ARID_DEF.icLoad = true;

  /* InitializeConditions for Delay: '<S148>/Delay One Step1' */
  swc_THSM_ARID_DEF.icLoad_n = true;

  /* SystemInitialize for Atomic SubSystem: '<S20>/turnOFF_delay' */
  swc_THSM_turnOFF_delay_Init(&rtb_flg_out_e0);

  /* End of SystemInitialize for SubSystem: '<S20>/turnOFF_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S20>/turnOFF_delay2' */
  swc_THSM_turnOFF_delay_Init(&rtb_flg_out_f);

  /* End of SystemInitialize for SubSystem: '<S20>/turnOFF_delay2' */

  /* SystemInitialize for Atomic SubSystem: '<S20>/turnOFF_delay1' */
  swc_THSM_turnOFF_delay_Init(&rtb_flg_out_b);

  /* End of SystemInitialize for SubSystem: '<S20>/turnOFF_delay1' */

  /* SystemInitialize for Enabled SubSystem: '<S8>/Fan1TgtSpdLdt45TBev' */
  /* SystemInitialize for Atomic SubSystem: '<S37>/turnON_delay' */
  swc_THSM_turnON_delay_Init(&rtb_flg_out_o1);

  /* End of SystemInitialize for SubSystem: '<S37>/turnON_delay' */
  /* End of SystemInitialize for SubSystem: '<S8>/Fan1TgtSpdLdt45TBev' */

  /* SystemInitialize for Enabled SubSystem: '<S8>/Fan1TargetSpeedArbitration' */
  /* SystemInitialize for Atomic SubSystem: '<S33>/turnOFF_delay' */
  swc_THSM_turnOFF_delay_Init(&rtb_flg_out_l);

  /* End of SystemInitialize for SubSystem: '<S33>/turnOFF_delay' */
  /* End of SystemInitialize for SubSystem: '<S8>/Fan1TargetSpeedArbitration' */

  /* SystemInitialize for Enabled SubSystem: '<S8>/Fan1TgtSpdAirCool' */
  /* SystemInitialize for Atomic SubSystem: '<S36>/turnON_delay' */
  swc_THSM_turnON_delay_Init(&rtb_flg_out_am);

  /* End of SystemInitialize for SubSystem: '<S36>/turnON_delay' */
  /* End of SystemInitialize for SubSystem: '<S8>/Fan1TgtSpdAirCool' */

  /* SystemInitialize for Enabled SubSystem: '<S8>/Fan1TargetSpeedArbitrationAirCool' */
  /* SystemInitialize for Atomic SubSystem: '<S34>/turnOFF_delay' */
  swc_THSM_turnOFF_delay_Init(&rtb_flg_out_eb);

  /* End of SystemInitialize for SubSystem: '<S34>/turnOFF_delay' */
  /* End of SystemInitialize for SubSystem: '<S8>/Fan1TargetSpeedArbitrationAirCool' */

  /* SystemInitialize for Atomic SubSystem: '<S10>/turnOFF_delay1' */
  /* SystemInitialize for Chart: '<S136>/timed_delay' */
  swc_THSM_timed_delay_Init(&swc_THSM_ARID_DEF.flg_out_j);

  /* End of SystemInitialize for SubSystem: '<S10>/turnOFF_delay1' */

  /* SystemInitialize for Atomic SubSystem: '<S10>/turnON_delay1' */
  /* SystemInitialize for Chart: '<S138>/timed_delay' */
  swc_THSM_timed_delay_k_Init(&swc_THSM_ARID_DEF.flg_out);

  /* End of SystemInitialize for SubSystem: '<S10>/turnON_delay1' */

  /* SystemInitialize for SignalConversion generated from: '<S2>/thmd_st_ptcRlyVoltSamSwitch' */
  swc_THSM_ARID_DEF.OutportBufferForthmd_st_ptcRlyV = swc_THSM_ConstB.Constant;

  /* SystemInitialize for Atomic SubSystem: '<S147>/turnOFF_delay' */
  swc_THSM_turnOFF_delay_Init(&rtb_flg_out_c);

  /* End of SystemInitialize for SubSystem: '<S147>/turnOFF_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S148>/turnOFF_delay' */
  swc_THSM_turnOFF_delay_Init(&rtb_flg_out_ao);

  /* End of SystemInitialize for SubSystem: '<S148>/turnOFF_delay' */

  /* SystemInitialize for Enabled SubSystem: '<S2>/ptc3FaultStatusControl' */
  /* SystemInitialize for Enabled SubSystem: '<S13>/ptc3FaultStatus' */
  /* SystemInitialize for Atomic SubSystem: '<S202>/turnON_delay' */
  swc_THSM_turnON_delay_Init(&rtb_flg_out_o);

  /* End of SystemInitialize for SubSystem: '<S202>/turnON_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S202>/turnON_delay1' */
  swc_THSM_turnON_delay_Init(&rtb_flg_out_a);

  /* End of SystemInitialize for SubSystem: '<S202>/turnON_delay1' */

  /* SystemInitialize for Switch: '<S202>/Switch' incorporates:
   *  Outport: '<S202>/thmd_st_ptc3ConnStsFb'
   */
  swc_THSM_ARID_DEF.Switch = ((uint8)3U);

  /* End of SystemInitialize for SubSystem: '<S13>/ptc3FaultStatus' */

  /* SystemInitialize for SignalConversion generated from: '<S13>/thmd_st_acceRlyVoltSamSwitch' incorporates:
   *  Outport: '<S13>/thmd_st_acceRlyVoltSamSwitch'
   */
  swc_THSM_ARID_DEF.OutportBufferForthmd_st_acceRly = ((uint8)3U);

  /* SystemInitialize for SignalConversion generated from: '<S13>/thmd_st_ptc3ConnStsFb' incorporates:
   *  Outport: '<S13>/thmd_st_ptc3ConnStsFb'
   */
  thmd_st_ptc3ConnStsFb = ((uint8)3U);

  /* End of SystemInitialize for SubSystem: '<S2>/ptc3FaultStatusControl' */

  /* SystemInitialize for Enabled SubSystem: '<S14>/ptc1FaultStatus' */
  /* SystemInitialize for Atomic SubSystem: '<S207>/turnON_delay' */
  swc_THSM_turnON_delay_Init(&rtb_flg_out_e);

  /* End of SystemInitialize for SubSystem: '<S207>/turnON_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S207>/turnON_delay1' */
  swc_THSM_turnON_delay_Init(&rtb_flg_out);

  /* End of SystemInitialize for SubSystem: '<S207>/turnON_delay1' */

  /* SystemInitialize for Switch: '<S207>/Switch' incorporates:
   *  Outport: '<S207>/thmd_st_ptcConnStsFb'
   */
  thmd_st_ptcConnStsFb = ((uint8)3U);

  /* End of SystemInitialize for SubSystem: '<S14>/ptc1FaultStatus' */
}

/* Output and update for function-call system: '<S1>/THM_ThermalControl' */
static void swc_THSM_THM_ThermalControl(void)
{
  /* local block i/o variables */
  float32 rtb_Switch;
  float32 rtb_DelayOneStep1;
  float32 rtb_DelayOneStep2;
  float32 rtb_Relay;
  float32 rtb_Relay1;
  float32 rtb_Relay2;
  float32 rtb_uDLookupTable;
  float32 rtb_Product2;
  float32 rtb_t_delay_on;
  float32 rtb_t_delay_off;
  float32 rtb_Switch1_h;
  float32 rtb_thmd_n_fan1TgtSpd_rpm;
  float32 rtb_thmd_n_fan1TgtSpd_rpm_m;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator5;
  boolean rtb_LogicalOperator2;
  boolean rtb_LogicalOperator11;
  boolean rtb_thmd_b_fan2CtrlEnabled;
  boolean rtb_LogicalOperator3_d;
  boolean rtb_RelationalOperator3_b;
  boolean rtb_FixPtRelationalOperator_g;
  boolean rtb_FixPtRelationalOperator_f;
  boolean rtb_RelationalOperator_bx;
  boolean rtb_LogicalOperator_n;
  boolean rtb_flg_out;
  boolean rtb_flg_out_e;
  boolean rtb_RelationalOperator_f;
  boolean rtb_LogicalOperator_c;
  boolean rtb_flg_out_a;
  boolean rtb_flg_out_o;
  boolean rtb_flg_out_ao;
  boolean rtb_flg_out_c;
  boolean rtb_DataTypeConversion_jd;
  boolean rtb_DataTypeConversion_h;
  boolean rtb_LogicalOperator3_p;
  boolean rtb_LogicalOperator3_i;
  boolean rtb_UnitDelay_o;
  boolean rtb_flg_out_o1;
  boolean rtb_UnitDelay_k;
  boolean rtb_flg_out_am;
  boolean rtb_FixPtRelationalOperator_h;
  boolean rtb_flg_out_eb;
  boolean rtb_FixPtRelationalOperator_m;
  boolean rtb_flg_out_l;
  boolean rtb_flg_out_f;
  boolean rtb_flg_out_b;
  boolean rtb_flg_out_e0;
  boolean rtb_LogicalOperator3_l;
  boolean rtb_RelationalOperator12;
  float32 rtb_Relay3;
  float32 rtb_Relay4;
  float32 rtb_Switch1;
  float32 rtb_Switch1_gh;
  float32 rtb_Switch3_a;
  float32 rtb_Switch3_cu;
  float32 rtb_Switch3_g;
  float32 rtb_Switch3_hw;
  float32 rtb_Switch3_ig;
  float32 rtb_Switch3_p;
  float32 rtb_Switch3_pp;
  float32 rtb_t_delay_off_f;
  FanStatus rtb_Switch4_d;
  PmmStatus thmd_b_accmEnbChrflg_tmp;
  uint8 rtb_Saturation1_c;
  boolean rtb_LogicalOperator2_f;
  boolean rtb_Relay4_g;
  boolean rtb_SignalConversion1;
  boolean thmd_b_accmEnboffChrflg_tmp;
  boolean thmd_b_accmExitEnableFlg_tmp;

  /* Logic: '<S3>/Logical Operator5' incorporates:
   *  Constant: '<S3>/Cabin_Cool'
   *  Constant: '<S3>/Heat_Cool'
   *  RelationalOperator: '<S3>/Relational Operator1'
   *  RelationalOperator: '<S3>/Relational Operator3'
   */
  thmd_b_accmEnaCnd1 = ((swc_THSM_ARID_DEF.DataTypeConversion35 == ((uint8)2U)) ||
                        (swc_THSM_ARID_DEF.DataTypeConversion35 == ((uint8)3U)));

  /* Outputs for Enabled SubSystem: '<S8>/Fan1TargetSpeedArbitration' incorporates:
   *  EnablePort: '<S33>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S8>/Fan1TgtSpdLdt45TBev' incorporates:
   *  EnablePort: '<S37>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S8>/Fan1TargetSpeedArbitrationAirCool' incorporates:
   *  EnablePort: '<S34>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S8>/Fan1TgtSpdAirCool' incorporates:
   *  EnablePort: '<S36>/Enable'
   */
  /* RelationalOperator: '<S3>/Relational Operator11' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion25'
   *  RelationalOperator: '<S10>/Relational Operator10'
   *  RelationalOperator: '<S10>/Relational Operator11'
   *  RelationalOperator: '<S10>/Relational Operator13'
   *  RelationalOperator: '<S10>/Relational Operator14'
   *  RelationalOperator: '<S10>/Relational Operator2'
   *  RelationalOperator: '<S10>/Relational Operator3'
   *  RelationalOperator: '<S10>/Relational Operator4'
   *  RelationalOperator: '<S10>/Relational Operator8'
   *  RelationalOperator: '<S10>/Relational Operator9'
   *  RelationalOperator: '<S11>/Relational Operator3'
   *  RelationalOperator: '<S147>/Relational Operator1'
   *  RelationalOperator: '<S147>/Relational Operator2'
   *  RelationalOperator: '<S147>/Relational Operator5'
   *  RelationalOperator: '<S148>/Relational Operator'
   *  RelationalOperator: '<S148>/Relational Operator1'
   *  RelationalOperator: '<S148>/Relational Operator2'
   *  RelationalOperator: '<S20>/Relational Operator'
   *  RelationalOperator: '<S33>/Relational Operator1'
   *  RelationalOperator: '<S33>/Relational Operator2'
   *  RelationalOperator: '<S34>/Relational Operator1'
   *  RelationalOperator: '<S34>/Relational Operator2'
   *  RelationalOperator: '<S36>/Relational Operator'
   *  RelationalOperator: '<S37>/Relational Operator'
   *  RelationalOperator: '<S3>/Relational Operator'
   *  RelationalOperator: '<S3>/Relational Operator13'
   *  Switch: '<S147>/Switch1'
   *  Switch: '<S147>/Switch11'
   *  Switch: '<S147>/Switch3'
   *  Switch: '<S147>/Switch7'
   *  Switch: '<S33>/Switch5'
   *  Switch: '<S34>/Switch5'
   *  Switch: '<S36>/Switch19'
   */
  thmd_b_accmEnbChrflg_tmp = swc_THSM_ARID_DEF.DataTypeConversion25;

  /* End of Outputs for SubSystem: '<S8>/Fan1TgtSpdAirCool' */
  /* End of Outputs for SubSystem: '<S8>/Fan1TargetSpeedArbitrationAirCool' */
  /* End of Outputs for SubSystem: '<S8>/Fan1TgtSpdLdt45TBev' */
  /* End of Outputs for SubSystem: '<S8>/Fan1TargetSpeedArbitration' */

  /* RelationalOperator: '<S3>/Relational Operator11' incorporates:
   *  Constant: '<S17>/Constant'
   */
  thmd_b_accmEnbChrflg = (thmd_b_accmEnbChrflg_tmp == PmmStatus_CHARGE);

  /* Logic: '<S3>/Logical Operator20' incorporates:
   *  Constant: '<S16>/Constant'
   *  RelationalOperator: '<S3>/Relational Operator'
   */
  thmd_b_accmEnaCnd2 = (swc_THSM_ARID_DEF.DataTypeConversion22 ||
                        (thmd_b_accmEnbChrflg_tmp == PmmStatus_DRIVE) ||
                        thmd_b_accmEnbChrflg);

  /* Logic: '<S3>/Logical Operator1' */
  thmd_b_accmEnterEnableFlg = (thmd_b_accmEnaCnd1 && thmd_b_accmEnaCnd2 &&
    thmd_b_accmEnaCnd3);

  /* Outputs for Enabled SubSystem: '<S8>/Fan1TargetSpeedArbitration' incorporates:
   *  EnablePort: '<S33>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S8>/Fan1TargetSpeedArbitrationAirCool' incorporates:
   *  EnablePort: '<S34>/Enable'
   */
  /* Logic: '<S3>/Logical Operator22' incorporates:
   *  Chart: '<S11>/Chart'
   *  Logic: '<S10>/Logical Operator15'
   *  Logic: '<S10>/Logical Operator23'
   *  Logic: '<S10>/Logical Operator5'
   *  Logic: '<S147>/Logical Operator2'
   *  Logic: '<S147>/Logical Operator4'
   *  Logic: '<S148>/Logical Operator1'
   *  Logic: '<S148>/Logical Operator3'
   *  Logic: '<S33>/Logical Operator4'
   *  Logic: '<S34>/Logical Operator5'
   *  Switch: '<S147>/Switch1'
   */
  thmd_b_accmEnboffChrflg_tmp = !swc_THSM_ARID_DEF.DataTypeConversion22;

  /* End of Outputs for SubSystem: '<S8>/Fan1TargetSpeedArbitrationAirCool' */
  /* End of Outputs for SubSystem: '<S8>/Fan1TargetSpeedArbitration' */

  /* Logic: '<S3>/Logical Operator21' incorporates:
   *  Constant: '<S17>/Constant'
   *  Logic: '<S3>/Logical Operator22'
   *  RelationalOperator: '<S3>/Relational Operator11'
   *  RelationalOperator: '<S3>/Relational Operator13'
   */
  thmd_b_accmEnboffChrflg = (thmd_b_accmEnboffChrflg_tmp &&
    (thmd_b_accmEnbChrflg_tmp != PmmStatus_CHARGE));

  /* Logic: '<S3>/Logical Operator24' incorporates:
   *  Logic: '<S10>/Logical Operator17'
   *  Logic: '<S10>/Logical Operator25'
   *  Logic: '<S10>/Logical Operator7'
   */
  thmd_b_accmExitEnableFlg_tmp = !thmd_b_accmEnaCnd3;

  /* Logic: '<S3>/Logical Operator23' incorporates:
   *  Logic: '<S3>/Logical Operator24'
   *  Logic: '<S3>/Logical Operator25'
   */
  thmd_b_accmExitEnableFlg = (thmd_b_accmExitEnableFlg_tmp ||
    (!thmd_b_accmEnaCnd1) || thmd_b_accmEnboffChrflg);

  /* Outputs for Atomic SubSystem: '<S3>/SR_latch1' */
  swc_THSM_SR_latch1(thmd_b_accmEnterEnableFlg, thmd_b_accmExitEnableFlg,
                     &rtb_LogicalOperator3_l,
                     &swc_THSM_ARID_DEF.ARID_DEF_SR_latch1_g);

  /* End of Outputs for SubSystem: '<S3>/SR_latch1' */

  /* SignalConversion generated from: '<S3>/SR_latch1' */
  thmd_b_accmEnbRaw = rtb_LogicalOperator3_l;

  /* Chart: '<S3>/AccmOnOffProtection' incorporates:
   *  Constant: '<S3>/Constant12'
   *  Constant: '<S3>/Constant7'
   */
  if (swc_THSM_ARID_DEF.is_active_c11_swc_THSM == 0U) {
    swc_THSM_ARID_DEF.is_active_c11_swc_THSM = 1U;
    swc_THSM_ARID_DEF.is_c11_swc_THSM = swc_THSM_IN_INIT;
    swc_THSM_ARID_DEF.T = 0.0F;
    thmd_b_accmEnb = false;
  } else {
    switch (swc_THSM_ARID_DEF.is_c11_swc_THSM) {
     case swc_THSM_IN_INIT:
      if (thmd_b_accmEnbRaw) {
        swc_THSM_ARID_DEF.is_c11_swc_THSM = swc_THSM_IN_On;
        swc_THSM_ARID_DEF.T = 0.0F;
        thmd_b_accmEnb = true;
      } else {
        thmd_b_accmEnb = false;
      }
      break;

     case swc_THSM_IN_Off:
      if (swc_THSM_ARID_DEF.T > thmc_tm_accmRstLim_s) {
        swc_THSM_ARID_DEF.is_c11_swc_THSM = swc_THSM_IN_INIT;
        swc_THSM_ARID_DEF.T = 0.0F;
        thmd_b_accmEnb = false;
      } else {
        swc_THSM_ARID_DEF.T += ((float32)THM_TASK_INTERVAL_S);
      }
      break;

     default:
      /* case IN_On: */
      if (!thmd_b_accmEnbRaw) {
        swc_THSM_ARID_DEF.is_c11_swc_THSM = swc_THSM_IN_Off;
        swc_THSM_ARID_DEF.T = 0.0F;
        thmd_b_accmEnb = false;
      } else {
        thmd_b_accmEnb = true;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/AccmOnOffProtection' */

  /* Logic: '<S20>/Logical Operator' incorporates:
   *  Constant: '<S17>/Constant'
   *  RelationalOperator: '<S20>/Relational Operator'
   *  RelationalOperator: '<S3>/Relational Operator11'
   */
  rtb_LogicalOperator = (swc_THSM_ARID_DEF.DataTypeConversion22 ||
    (thmd_b_accmEnbChrflg_tmp == PmmStatus_CHARGE));

  /* Logic: '<S20>/Logical Operator5' */
  rtb_LogicalOperator5 = false;

  /* Outputs for Atomic SubSystem: '<S20>/SR_latch' */
  swc_THSM_SR_latch(rtb_LogicalOperator5, &rtb_RelationalOperator12,
                    &swc_THSM_ConstB.SR_latch,
                    &swc_THSM_ARID_DEF.ARID_DEF_SR_latch);

  /* End of Outputs for SubSystem: '<S20>/SR_latch' */

  /* Switch: '<S20>/Switch1' incorporates:
   *  RelationalOperator: '<S22>/FixPt Relational Operator'
   *  Switch: '<S20>/Switch'
   *  UnitDelay: '<S22>/Delay Input1'
   *
   * Block description for '<S22>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((sint32)rtb_LogicalOperator > (sint32)
      swc_THSM_ARID_DEF.DelayInput1_DSTATE_k) {
    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S20>/Constant1'
     */
    rtb_Switch = 0.0F;
  } else {
    /* Switch: '<S20>/Switch' incorporates:
     *  UnitDelay: '<S20>/Unit Delay'
     */
    rtb_Switch = swc_THSM_ARID_DEF.UnitDelay_DSTATE;
  }

  /* End of Switch: '<S20>/Switch1' */

  /* Outputs for Atomic SubSystem: '<S20>/turnOFF_delay' */
  /* Constant: '<S20>/Constant8' */
  swc_THSM_turnOFF_delay(rtb_LogicalOperator, rtb_Switch, ((float32)
    THM_TASK_INTERVAL_S), &rtb_flg_out_e0,
    &swc_THSM_ARID_DEF.ARID_DEF_turnOFF_delay_g);

  /* End of Outputs for SubSystem: '<S20>/turnOFF_delay' */

  /* Outputs for Atomic SubSystem: '<S20>/turnOFF_delay2' */
  /* Constant: '<S20>/Constant7' incorporates:
   *  Constant: '<S20>/Constant9'
   */
  swc_THSM_turnOFF_delay(rtb_LogicalOperator, thmc_tm_maxAfterRunTime_s,
    ((float32)THM_TASK_INTERVAL_S), &rtb_flg_out_f,
    &swc_THSM_ARID_DEF.ARID_DEF_turnOFF_delay2);

  /* End of Outputs for SubSystem: '<S20>/turnOFF_delay2' */

  /* Logic: '<S20>/Logical Operator12' incorporates:
   *  Logic: '<S20>/Logical Operator3'
   */
  rtb_LogicalOperator2_f = !rtb_LogicalOperator;

  /* Logic: '<S20>/Logical Operator14' incorporates:
   *  Logic: '<S20>/Logical Operator12'
   *  Logic: '<S20>/Logical Operator13'
   */
  thmd_b_afterRunActive = ((rtb_LogicalOperator2_f && rtb_flg_out_f) ||
    rtb_LogicalOperator);

  /* Outputs for Atomic SubSystem: '<S20>/turnOFF_delay1' */
  /* Constant: '<S20>/Constant5' incorporates:
   *  Constant: '<S20>/Constant4'
   */
  swc_THSM_turnOFF_delay(rtb_LogicalOperator, thmc_tm_maxAfterRunTime_s,
    ((float32)THM_TASK_INTERVAL_S), &rtb_flg_out_b,
    &swc_THSM_ARID_DEF.ARID_DEF_turnOFF_delay1);

  /* End of Outputs for SubSystem: '<S20>/turnOFF_delay1' */

  /* Logic: '<S20>/Logical Operator2' incorporates:
   *  Constant: '<S20>/Constant2'
   *  Constant: '<S20>/Constant3'
   *  Logic: '<S20>/Logical Operator10'
   *  Logic: '<S20>/Logical Operator6'
   *  Logic: '<S20>/Logical Operator7'
   *  Logic: '<S20>/Logical Operator8'
   *  Logic: '<S20>/Logical Operator9'
   */
  rtb_LogicalOperator2 = (((thmc_b_enaLongerAfterRun && rtb_RelationalOperator12)
    || ((rtb_RelationalOperator12 || (!thmc_b_enaShorterAfterRun)) &&
        rtb_flg_out_e0)) && rtb_LogicalOperator2_f && rtb_flg_out_b);

  /* Logic: '<S20>/Logical Operator11' incorporates:
   *  Constant: '<S20>/Constant6'
   */
  rtb_LogicalOperator11 = (swc_THSM_ARID_DEF.DataTypeConversion111 &&
    thmc_b_enaIntelChgAfterRun);

  /* Delay: '<S2>/Delay One Step1' */
  rtb_DelayOneStep1 = thmd_n_pmp2TgtSpdAirCl_pct;

  /* Delay: '<S2>/Delay One Step2' */
  rtb_DelayOneStep2 = swc_THSM_ARID_DEF.thmd_n_fan1TgtSpd_pct_b;

  /* Logic: '<S7>/Logical Operator2' */
  rtb_LogicalOperator2_f = (swc_THSM_ARID_DEF.DataTypeConversion22 ||
    swc_THSM_ARID_DEF.DataTypeConversion29 ||
    swc_THSM_ARID_DEF.DataTypeConversion111 || thmd_b_afterRunActive);

  /* Relay: '<S7>/Relay3' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion2'
   */
  swc_THSM_ARID_DEF.Relay3_Mode = ((swc_THSM_ConstB.DataTypeConversion2 >=
    thmc_t_fanEnaMotHiThd_C) || ((swc_THSM_ConstB.DataTypeConversion2 >
    thmc_t_fanEnaMotLoThd_C) && swc_THSM_ARID_DEF.Relay3_Mode));

  /* Relay: '<S7>/Relay2' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion3'
   */
  swc_THSM_ARID_DEF.Relay2_Mode = ((swc_THSM_ConstB.DataTypeConversion3 >=
    thmc_t_fanEnaInvHiThd_C) || ((swc_THSM_ConstB.DataTypeConversion3 >
    thmc_t_fanEnaInvLoThd_C) && swc_THSM_ARID_DEF.Relay2_Mode));

  /* Relay: '<S7>/Relay3' */
  if (swc_THSM_ARID_DEF.Relay3_Mode) {
    rtb_Relay4_g = true;
  } else {
    rtb_Relay4_g = false;
  }

  /* Relay: '<S7>/Relay2' */
  if (swc_THSM_ARID_DEF.Relay2_Mode) {
    rtb_SignalConversion1 = true;
  } else {
    rtb_SignalConversion1 = false;
  }

  /* Logic: '<S7>/Logical Operator1' incorporates:
   *  Constant: '<S7>/Constant3'
   *  Constant: '<S7>/HDT49T_P1'
   *  Logic: '<S7>/Logical Operator9'
   *  RelationalOperator: '<S7>/Relational Operator3'
   *  Relay: '<S7>/Relay2'
   *  Relay: '<S7>/Relay3'
   */
  thmd_b_fanCtrlEnabled = (rtb_LogicalOperator2_f && (rtb_Relay4_g ||
    rtb_SignalConversion1 || (((uint8)VEH_SWT_INF) != ((uint8)4U))));

  /* Switch: '<S7>/Switch3' incorporates:
   *  Constant: '<S31>/Constant'
   *  Constant: '<S7>/Constant4'
   *  RelationalOperator: '<S31>/Compare'
   */
  if (((uint8)VEH_SWT_INF) == ((uint8)1U)) {
    /* SignalConversion: '<S10>/Signal Conversion1' incorporates:
     *  Logic: '<S7>/Logical Operator10'
     */
    rtb_SignalConversion1 = (thmd_b_afterRunActive ||
      swc_THSM_ARID_DEF.DataTypeConversion64);
  } else {
    /* SignalConversion: '<S10>/Signal Conversion1' */
    rtb_SignalConversion1 = rtb_LogicalOperator2_f;
  }

  /* End of Switch: '<S7>/Switch3' */

  /* Logic: '<S7>/Logical Operator3' incorporates:
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/Constant8'
   *  Constant: '<S7>/LDT45T_BEV'
   *  Logic: '<S7>/Logical Operator5'
   *  Logic: '<S7>/Logical Operator7'
   *  RelationalOperator: '<S7>/Relational Operator2'
   */
  thmd_b_wtrPmp1CtrlEnabled = (rtb_SignalConversion1 &&
    ((!swc_THSM_ARID_DEF.DataTypeConversion65) || (((uint8)VEH_SWT_INF) !=
    ((uint8)0U)) || thmc_b_diHVBHeatEnadCnd));

  /* Relay: '<S7>/Relay4' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   */
  swc_THSM_ARID_DEF.Relay4_Mode = ((swc_THSM_ConstB.DataTypeConversion >=
    thmc_t_wtrPmp2EnaMotHiThd_C) || ((swc_THSM_ConstB.DataTypeConversion >
    thmc_t_wtrPmp2EnaMotLoThd_C) && swc_THSM_ARID_DEF.Relay4_Mode));

  /* Relay: '<S7>/Relay1' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion1'
   */
  swc_THSM_ARID_DEF.Relay1_Mode = ((swc_THSM_ConstB.DataTypeConversion1_m >=
    thmc_t_wtrPmp2EnaInvHiThd_C) || ((swc_THSM_ConstB.DataTypeConversion1_m >
    thmc_t_wtrPmp2EnaInvLoThd_C) && swc_THSM_ARID_DEF.Relay1_Mode));
  if (swc_THSM_ARID_DEF.Relay1_Mode) {
    /* RelationalOperator: '<S10>/Relational Operator12' */
    rtb_RelationalOperator12 = true;
  } else {
    /* RelationalOperator: '<S10>/Relational Operator12' */
    rtb_RelationalOperator12 = false;
  }

  /* End of Relay: '<S7>/Relay1' */

  /* Relay: '<S7>/Relay4' */
  if (swc_THSM_ARID_DEF.Relay4_Mode) {
    rtb_Relay4_g = true;
  } else {
    rtb_Relay4_g = false;
  }

  /* Logic: '<S7>/Logical Operator4' incorporates:
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/HDT49T_P2'
   *  Logic: '<S7>/Logical Operator8'
   *  RelationalOperator: '<S7>/Relational Operator1'
   *  Relay: '<S7>/Relay4'
   */
  thmd_b_wtrPmp2CtrlEnabled = (rtb_SignalConversion1 && (rtb_Relay4_g ||
    rtb_RelationalOperator12 || (((uint8)VEH_SWT_INF) != ((uint8)4U))));

  /* SignalConversion: '<S7>/Signal Conversion' */
  rtb_thmd_b_fan2CtrlEnabled = rtb_LogicalOperator2_f;

  /* Logic: '<S9>/Logical Operator' incorporates:
   *  Constant: '<S111>/Lower Limit'
   *  Constant: '<S111>/Upper Limit'
   *  Logic: '<S111>/AND'
   *  RelationalOperator: '<S111>/Lower Test'
   *  RelationalOperator: '<S111>/Upper Test'
   */
  rtb_LogicalOperator2_f = ((thmc_v_ts5FltThrDw >
    swc_THSM_ARID_DEF.DataTypeConversion149) ||
    (swc_THSM_ARID_DEF.DataTypeConversion149 > thmc_v_ts5FltThrUp));

  /* Outputs for Atomic SubSystem: '<S9>/debounce' */
  /* Saturate: '<S115>/Saturation' incorporates:
   *  Constant: '<S9>/Constant2'
   */
  if (thmc_tm_FltStsOnDly_s > 1.6777216E+7F) {
    /* Outputs for Atomic SubSystem: '<S9>/debounce3' */
    /* Outputs for Atomic SubSystem: '<S9>/debounce2' */
    /* Outputs for Atomic SubSystem: '<S9>/debounce1' */
    /* Saturate: '<S116>/Saturation' incorporates:
     *  Saturate: '<S117>/Saturation'
     *  Saturate: '<S118>/Saturation'
     */
    rtb_t_delay_off_f = 1.6777216E+7F;

    /* End of Outputs for SubSystem: '<S9>/debounce1' */
    /* End of Outputs for SubSystem: '<S9>/debounce2' */
    /* End of Outputs for SubSystem: '<S9>/debounce3' */
  } else if (thmc_tm_FltStsOnDly_s < 0.0F) {
    /* Outputs for Atomic SubSystem: '<S9>/debounce3' */
    /* Outputs for Atomic SubSystem: '<S9>/debounce2' */
    /* Outputs for Atomic SubSystem: '<S9>/debounce1' */
    /* Saturate: '<S116>/Saturation' incorporates:
     *  Saturate: '<S117>/Saturation'
     *  Saturate: '<S118>/Saturation'
     */
    rtb_t_delay_off_f = 0.0F;

    /* End of Outputs for SubSystem: '<S9>/debounce1' */
    /* End of Outputs for SubSystem: '<S9>/debounce2' */
    /* End of Outputs for SubSystem: '<S9>/debounce3' */
  } else {
    /* Outputs for Atomic SubSystem: '<S9>/debounce3' */
    /* Outputs for Atomic SubSystem: '<S9>/debounce2' */
    /* Outputs for Atomic SubSystem: '<S9>/debounce1' */
    /* Saturate: '<S116>/Saturation' incorporates:
     *  Saturate: '<S117>/Saturation'
     *  Saturate: '<S118>/Saturation'
     */
    rtb_t_delay_off_f = thmc_tm_FltStsOnDly_s;

    /* End of Outputs for SubSystem: '<S9>/debounce1' */
    /* End of Outputs for SubSystem: '<S9>/debounce2' */
    /* End of Outputs for SubSystem: '<S9>/debounce3' */
  }

  /* Saturate: '<S115>/Saturation1' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  if (thmc_tm_FltStsOffDly_s > 1.6777216E+7F) {
    /* Outputs for Atomic SubSystem: '<S9>/debounce3' */
    /* Outputs for Atomic SubSystem: '<S9>/debounce2' */
    /* Outputs for Atomic SubSystem: '<S9>/debounce1' */
    /* Saturate: '<S116>/Saturation1' incorporates:
     *  Saturate: '<S117>/Saturation1'
     *  Saturate: '<S118>/Saturation1'
     */
    rtb_Switch1 = 1.6777216E+7F;

    /* End of Outputs for SubSystem: '<S9>/debounce1' */
    /* End of Outputs for SubSystem: '<S9>/debounce2' */
    /* End of Outputs for SubSystem: '<S9>/debounce3' */
  } else if (thmc_tm_FltStsOffDly_s < 0.0F) {
    /* Outputs for Atomic SubSystem: '<S9>/debounce3' */
    /* Outputs for Atomic SubSystem: '<S9>/debounce2' */
    /* Outputs for Atomic SubSystem: '<S9>/debounce1' */
    /* Saturate: '<S116>/Saturation1' incorporates:
     *  Saturate: '<S117>/Saturation1'
     *  Saturate: '<S118>/Saturation1'
     */
    rtb_Switch1 = 0.0F;

    /* End of Outputs for SubSystem: '<S9>/debounce1' */
    /* End of Outputs for SubSystem: '<S9>/debounce2' */
    /* End of Outputs for SubSystem: '<S9>/debounce3' */
  } else {
    /* Outputs for Atomic SubSystem: '<S9>/debounce3' */
    /* Outputs for Atomic SubSystem: '<S9>/debounce2' */
    /* Outputs for Atomic SubSystem: '<S9>/debounce1' */
    /* Saturate: '<S116>/Saturation1' incorporates:
     *  Saturate: '<S117>/Saturation1'
     *  Saturate: '<S118>/Saturation1'
     */
    rtb_Switch1 = thmc_tm_FltStsOffDly_s;

    /* End of Outputs for SubSystem: '<S9>/debounce1' */
    /* End of Outputs for SubSystem: '<S9>/debounce2' */
    /* End of Outputs for SubSystem: '<S9>/debounce3' */
  }

  /* Chart: '<S115>/timed_debounce' incorporates:
   *  Constant: '<S9>/Constant'
   *  DataTypeConversion: '<S115>/Data Type Conversion'
   *  Saturate: '<S115>/Saturation'
   *  Saturate: '<S115>/Saturation1'
   */
  if (swc_THSM_ARID_DEF.is_active_c13_swc_THSM == 0U) {
    swc_THSM_ARID_DEF.is_active_c13_swc_THSM = 1U;
    if (rtb_LogicalOperator2_f) {
      swc_THSM_ARID_DEF.is_c13_swc_THSM = swc_THSM_IN_ON_e;
      thmd_b_FaultSts_flg = true;
    } else {
      swc_THSM_ARID_DEF.is_c13_swc_THSM = swc_THSM_IN_OFF_i;
      thmd_b_FaultSts_flg = false;
    }
  } else {
    switch (swc_THSM_ARID_DEF.is_c13_swc_THSM) {
     case swc_THSM_IN_OFF_i:
      if (rtb_LogicalOperator2_f) {
        if (rtb_t_delay_off_f == 0.0F) {
          swc_THSM_ARID_DEF.is_c13_swc_THSM = swc_THSM_IN_ON_e;
          thmd_b_FaultSts_flg = true;
        } else {
          swc_THSM_ARID_DEF.is_c13_swc_THSM = swc_THSM_IN_ON_WAIT_n;
          swc_THSM_ARID_DEF.t_wait_j = ((float32)THM_TASK_INTERVAL_S);
          thmd_b_FaultSts_flg = false;
        }
      } else {
        thmd_b_FaultSts_flg = false;
      }
      break;

     case swc_THSM_IN_OFF_WAIT_a:
      if (rtb_LogicalOperator2_f) {
        swc_THSM_ARID_DEF.is_c13_swc_THSM = swc_THSM_IN_ON_e;
        thmd_b_FaultSts_flg = true;
      } else if (swc_THSM_ARID_DEF.t_wait_j > rtb_Switch1 - ((float32)
                  THM_TASK_INTERVAL_S)) {
        swc_THSM_ARID_DEF.is_c13_swc_THSM = swc_THSM_IN_OFF_i;
        thmd_b_FaultSts_flg = false;
      } else {
        swc_THSM_ARID_DEF.t_wait_j += ((float32)THM_TASK_INTERVAL_S);
        thmd_b_FaultSts_flg = true;
      }
      break;

     case swc_THSM_IN_ON_e:
      if (!rtb_LogicalOperator2_f) {
        if (rtb_Switch1 == 0.0F) {
          swc_THSM_ARID_DEF.is_c13_swc_THSM = swc_THSM_IN_OFF_i;
          thmd_b_FaultSts_flg = false;
        } else {
          swc_THSM_ARID_DEF.is_c13_swc_THSM = swc_THSM_IN_OFF_WAIT_a;
          swc_THSM_ARID_DEF.t_wait_j = ((float32)THM_TASK_INTERVAL_S);
          thmd_b_FaultSts_flg = true;
        }
      } else {
        thmd_b_FaultSts_flg = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtb_LogicalOperator2_f) {
        swc_THSM_ARID_DEF.is_c13_swc_THSM = swc_THSM_IN_OFF_i;
        thmd_b_FaultSts_flg = false;
      } else if (swc_THSM_ARID_DEF.t_wait_j > rtb_t_delay_off_f - ((float32)
                  THM_TASK_INTERVAL_S)) {
        swc_THSM_ARID_DEF.is_c13_swc_THSM = swc_THSM_IN_ON_e;
        thmd_b_FaultSts_flg = true;
      } else {
        swc_THSM_ARID_DEF.t_wait_j += ((float32)THM_TASK_INTERVAL_S);
        thmd_b_FaultSts_flg = false;
      }
      break;
    }
  }

  /* End of Chart: '<S115>/timed_debounce' */
  /* End of Outputs for SubSystem: '<S9>/debounce' */

  /* Outputs for Enabled SubSystem: '<S8>/Fan1TargetSpeedArbitration' incorporates:
   *  EnablePort: '<S33>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S8>/Fan1TgtSpdLdt45TBev' incorporates:
   *  EnablePort: '<S37>/Enable'
   */
  /* Logic: '<S8>/Logical Operator1' incorporates:
   *  Constant: '<S33>/Constant10'
   *  Constant: '<S33>/Constant9'
   *  Constant: '<S34>/Constant10'
   *  Constant: '<S34>/Constant9'
   *  Constant: '<S36>/Constant10'
   *  Constant: '<S36>/Constant9'
   *  Constant: '<S37>/Constant10'
   *  Constant: '<S37>/Constant9'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  RelationalOperator: '<S8>/Relational Operator'
   *  RelationalOperator: '<S8>/Relational Operator1'
   */
  if ((swc_THSM_ARID_DEF.DataTypeConversion140 == ((uint8)0U)) ||
      (swc_THSM_ARID_DEF.DataTypeConversion140 == ((uint8)1U))) {
    /* UnitDelay: '<S37>/Unit Delay' */
    rtb_UnitDelay_o = swc_THSM_ARID_DEF.UnitDelay_DSTATE_i;

    /* Outputs for Atomic SubSystem: '<S37>/turnON_delay' */
    swc_THSM_turnON_delay(rtb_UnitDelay_o, thmc_tm_Fan1EnbDly_s, ((float32)
      THM_TASK_INTERVAL_S), &rtb_flg_out_o1,
                          &swc_THSM_ARID_DEF.ARID_DEF_turnON_delay_b);

    /* End of Outputs for SubSystem: '<S37>/turnON_delay' */

    /* Switch: '<S80>/Switch3' incorporates:
     *  Constant: '<S37>/Constant10'
     *  Constant: '<S37>/Constant9'
     *  Constant: '<S95>/Constant'
     *  RelationalOperator: '<S95>/Compare'
     *  Sum: '<S80>/Sum3'
     *  UnitDelay: '<S80>/Unit Delay6'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion33 -
        swc_THSM_ARID_DEF.UnitDelay6_DSTATE_gi >= 0.0F) {
      /* Switch: '<S80>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion33'
       *  Lookup_n-D: '<S80>/1D_Lookup_Table6'
       *  MinMax: '<S80>/MinMax6'
       *  UnitDelay: '<S80>/Unit Delay7'
       */
      thmd_n_fan300ts5TempTgtSpd_pct = fmaxf
        (thmf_Y_SnsrTempFan1Inc_pct[plook_u32f_bincka
         (swc_THSM_ARID_DEF.DataTypeConversion33, (const float32 *)
          &thmf_X_SnsrTempFan1Inc_t[0], 4U)], thmd_n_fan300ts5TempTgtSpd_pct);
    } else {
      /* Switch: '<S80>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion33'
       *  Lookup_n-D: '<S80>/1D_Lookup_Table7'
       *  MinMax: '<S80>/MinMax7'
       *  UnitDelay: '<S80>/Unit Delay7'
       */
      thmd_n_fan300ts5TempTgtSpd_pct = fminf
        (thmf_Y_SnsrTempFan1Dec_pct[plook_u32f_bincka
         (swc_THSM_ARID_DEF.DataTypeConversion33, (const float32 *)
          &thmf_X_SnsrTempFan1Dec_t[0], 4U)], thmd_n_fan300ts5TempTgtSpd_pct);
    }

    /* End of Switch: '<S80>/Switch3' */

    /* Switch: '<S82>/Switch3' incorporates:
     *  Constant: '<S97>/Constant'
     *  RelationalOperator: '<S97>/Compare'
     *  Sum: '<S82>/Sum3'
     *  UnitDelay: '<S82>/Unit Delay6'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion11 -
        swc_THSM_ARID_DEF.UnitDelay6_DSTATE_i >= 0.0F) {
      /* Switch: '<S82>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion11'
       *  Lookup_n-D: '<S82>/1D_Lookup_Table6'
       *  MinMax: '<S82>/MinMax6'
       *  UnitDelay: '<S82>/Unit Delay7'
       */
      rtb_Switch3_a = fmaxf(thmf_Y_dcdcTempFan1Inc_pct[plook_u32f_bincka
                            (swc_THSM_ARID_DEF.DataTypeConversion11, (const
        float32 *)&thmf_X_dcdcTempFan1Inc_t[0], 4U)],
                            swc_THSM_ARID_DEF.UnitDelay7_DSTATE_og);
    } else {
      /* Switch: '<S82>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion11'
       *  Lookup_n-D: '<S82>/1D_Lookup_Table7'
       *  MinMax: '<S82>/MinMax7'
       *  UnitDelay: '<S82>/Unit Delay7'
       */
      rtb_Switch3_a = fminf(thmf_Y_dcdcTempFan1Dec_pct[plook_u32f_bincka
                            (swc_THSM_ARID_DEF.DataTypeConversion11, (const
        float32 *)&thmf_X_dcdcTempFan1Dec_t[0], 6U)],
                            swc_THSM_ARID_DEF.UnitDelay7_DSTATE_og);
    }

    /* End of Switch: '<S82>/Switch3' */

    /* Switch: '<S86>/Switch3' incorporates:
     *  Constant: '<S101>/Constant'
     *  RelationalOperator: '<S101>/Compare'
     *  Sum: '<S86>/Sum3'
     *  UnitDelay: '<S86>/Unit Delay6'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion27 -
        swc_THSM_ARID_DEF.UnitDelay6_DSTATE_o >= 0.0F) {
      /* Switch: '<S86>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion27'
       *  Lookup_n-D: '<S86>/1D_Lookup_Table6'
       *  MinMax: '<S86>/MinMax6'
       *  UnitDelay: '<S86>/Unit Delay7'
       */
      rtb_Switch3_ig = fmaxf(thmf_Y_inv2TempFan1Inc_pct[plook_u32f_bincka
        (swc_THSM_ARID_DEF.DataTypeConversion27, (const float32 *)
         &thmf_X_inv2TempFan1Inc_t[0], 4U)],
        swc_THSM_ARID_DEF.UnitDelay7_DSTATE_l);
    } else {
      /* Switch: '<S86>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion27'
       *  Lookup_n-D: '<S86>/1D_Lookup_Table7'
       *  MinMax: '<S86>/MinMax7'
       *  UnitDelay: '<S86>/Unit Delay7'
       */
      rtb_Switch3_ig = fminf(thmf_Y_inv2TempFan1Dec_pct[plook_u32f_bincka
        (swc_THSM_ARID_DEF.DataTypeConversion27, (const float32 *)
         &thmf_X_inv2TempFan1Dec_t[0], 6U)],
        swc_THSM_ARID_DEF.UnitDelay7_DSTATE_l);
    }

    /* End of Switch: '<S86>/Switch3' */

    /* Switch: '<S88>/Switch3' incorporates:
     *  Constant: '<S103>/Constant'
     *  RelationalOperator: '<S103>/Compare'
     *  Sum: '<S88>/Sum3'
     *  UnitDelay: '<S88>/Unit Delay6'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion31 -
        swc_THSM_ARID_DEF.UnitDelay6_DSTATE_o4 >= 0.0F) {
      /* Switch: '<S88>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion31'
       *  Lookup_n-D: '<S88>/1D_Lookup_Table6'
       *  MinMax: '<S88>/MinMax6'
       *  UnitDelay: '<S88>/Unit Delay7'
       */
      rtb_Switch3_pp = fmaxf(thmf_Y_mot2TempFan1lowInc_pct[plook_u32f_bincka
        (swc_THSM_ARID_DEF.DataTypeConversion31, (const float32 *)
         &thmf_X_mot2TempFan1lowInc_t[0], 4U)],
        swc_THSM_ARID_DEF.UnitDelay7_DSTATE_d);
    } else {
      /* Switch: '<S88>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion31'
       *  Lookup_n-D: '<S88>/1D_Lookup_Table7'
       *  MinMax: '<S88>/MinMax7'
       *  UnitDelay: '<S88>/Unit Delay7'
       */
      rtb_Switch3_pp = fminf(thmf_Y_mot2TempFan1lowDec_pct[plook_u32f_bincka
        (swc_THSM_ARID_DEF.DataTypeConversion31, (const float32 *)
         &thmf_X_mot2TempFan1lowDec_t[0], 6U)],
        swc_THSM_ARID_DEF.UnitDelay7_DSTATE_d);
    }

    /* End of Switch: '<S88>/Switch3' */

    /* Switch: '<S92>/Switch3' incorporates:
     *  Constant: '<S107>/Constant'
     *  RelationalOperator: '<S107>/Compare'
     *  Sum: '<S92>/Sum3'
     *  UnitDelay: '<S92>/Unit Delay6'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion33 -
        swc_THSM_ARID_DEF.UnitDelay6_DSTATE_a >= 0.0F) {
      /* Switch: '<S92>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion33'
       *  Lookup_n-D: '<S92>/1D_Lookup_Table6'
       *  MinMax: '<S92>/MinMax6'
       *  UnitDelay: '<S92>/Unit Delay7'
       */
      rtb_Switch3_p = fmaxf(thmf_Y_ts5TempFan1Inc_pct[plook_u32f_bincka
                            (swc_THSM_ARID_DEF.DataTypeConversion33, (const
        float32 *)&thmf_X_ts5TempFan1Inc_t[0], 4U)],
                            swc_THSM_ARID_DEF.UnitDelay7_DSTATE_f);
    } else {
      /* Switch: '<S92>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion33'
       *  Lookup_n-D: '<S92>/1D_Lookup_Table7'
       *  MinMax: '<S92>/MinMax7'
       *  UnitDelay: '<S92>/Unit Delay7'
       */
      rtb_Switch3_p = fminf(thmf_Y_ts5TempFan1Dec_pct[plook_u32f_bincka
                            (swc_THSM_ARID_DEF.DataTypeConversion33, (const
        float32 *)&thmf_X_ts5TempFan1Dec_t[0], 6U)],
                            swc_THSM_ARID_DEF.UnitDelay7_DSTATE_f);
    }

    /* End of Switch: '<S92>/Switch3' */

    /* Switch: '<S84>/Switch3' incorporates:
     *  Constant: '<S99>/Constant'
     *  RelationalOperator: '<S99>/Compare'
     *  Sum: '<S84>/Sum3'
     *  UnitDelay: '<S84>/Unit Delay6'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion11 -
        swc_THSM_ARID_DEF.UnitDelay6_DSTATE_n >= 0.0F) {
      /* Switch: '<S84>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion11'
       *  Lookup_n-D: '<S84>/1D_Lookup_Table6'
       *  MinMax: '<S84>/MinMax6'
       *  UnitDelay: '<S84>/Unit Delay7'
       */
      rtb_Switch3_hw = fmaxf(thmf_Y_dcdcTempFan1IncChr_pct[plook_u32f_bincka
        (swc_THSM_ARID_DEF.DataTypeConversion11, (const float32 *)
         &thmf_X_dcdcTempFan1IncChr_t[0], 3U)],
        swc_THSM_ARID_DEF.UnitDelay7_DSTATE_k);
    } else {
      /* Switch: '<S84>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion11'
       *  Lookup_n-D: '<S84>/1D_Lookup_Table7'
       *  MinMax: '<S84>/MinMax7'
       *  UnitDelay: '<S84>/Unit Delay7'
       */
      rtb_Switch3_hw = fminf(thmf_Y_dcdcTempFan1DecChr_pct[plook_u32f_bincka
        (swc_THSM_ARID_DEF.DataTypeConversion11, (const float32 *)
         &thmf_X_dcdcTempFan1DecChr_t[0], 4U)],
        swc_THSM_ARID_DEF.UnitDelay7_DSTATE_k);
    }

    /* End of Switch: '<S84>/Switch3' */

    /* Switch: '<S81>/Switch3' incorporates:
     *  Constant: '<S96>/Constant'
     *  RelationalOperator: '<S96>/Compare'
     *  Sum: '<S81>/Sum3'
     *  UnitDelay: '<S81>/Unit Delay6'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion33 -
        swc_THSM_ARID_DEF.UnitDelay6_DSTATE_k >= 0.0F) {
      /* Switch: '<S81>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion33'
       *  Lookup_n-D: '<S81>/1D_Lookup_Table6'
       *  MinMax: '<S81>/MinMax6'
       *  UnitDelay: '<S81>/Unit Delay7'
       */
      thmd_n_SnsrTempFan1_pct = fmaxf
        (thmf_Y_SnsrTempFanInc_pct[plook_u32f_bincka
         (swc_THSM_ARID_DEF.DataTypeConversion33, (const float32 *)
          &thmf_X_SnsrTempFanInc_t[0], 3U)], thmd_n_SnsrTempFan1_pct);
    } else {
      /* Switch: '<S81>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion33'
       *  Lookup_n-D: '<S81>/1D_Lookup_Table7'
       *  MinMax: '<S81>/MinMax7'
       *  UnitDelay: '<S81>/Unit Delay7'
       */
      thmd_n_SnsrTempFan1_pct = fminf
        (thmf_Y_SnsrTempFanDec_pct[plook_u32f_bincka
         (swc_THSM_ARID_DEF.DataTypeConversion33, (const float32 *)
          &thmf_X_SnsrTempFanDec_t[0], 4U)], thmd_n_SnsrTempFan1_pct);
    }

    /* End of Switch: '<S81>/Switch3' */

    /* Switch: '<S83>/Switch3' incorporates:
     *  Constant: '<S98>/Constant'
     *  RelationalOperator: '<S98>/Compare'
     *  Sum: '<S83>/Sum3'
     *  UnitDelay: '<S83>/Unit Delay6'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion11 -
        swc_THSM_ARID_DEF.UnitDelay6_DSTATE_l >= 0.0F) {
      /* Switch: '<S83>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion11'
       *  Lookup_n-D: '<S83>/1D_Lookup_Table6'
       *  MinMax: '<S83>/MinMax6'
       *  UnitDelay: '<S83>/Unit Delay7'
       */
      thmd_n_dcdcTempFan1_pct = fmaxf
        (thmf_Y_dcdcTempFanInc_pct[plook_u32f_bincka
         (swc_THSM_ARID_DEF.DataTypeConversion11, (const float32 *)
          &thmf_X_dcdcTempFanInc_t[0], 4U)], thmd_n_dcdcTempFan1_pct);
    } else {
      /* Switch: '<S83>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion11'
       *  Lookup_n-D: '<S83>/1D_Lookup_Table7'
       *  MinMax: '<S83>/MinMax7'
       *  UnitDelay: '<S83>/Unit Delay7'
       */
      thmd_n_dcdcTempFan1_pct = fminf
        (thmf_Y_dcdcTempFanDec_pct[plook_u32f_bincka
         (swc_THSM_ARID_DEF.DataTypeConversion11, (const float32 *)
          &thmf_X_dcdcTempFanDec_t[0], 5U)], thmd_n_dcdcTempFan1_pct);
    }

    /* End of Switch: '<S83>/Switch3' */

    /* Switch: '<S87>/Switch3' incorporates:
     *  Constant: '<S102>/Constant'
     *  RelationalOperator: '<S102>/Compare'
     *  Sum: '<S87>/Sum3'
     *  UnitDelay: '<S87>/Unit Delay6'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion27 -
        swc_THSM_ARID_DEF.UnitDelay6_DSTATE_f >= 0.0F) {
      /* Switch: '<S87>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion27'
       *  Lookup_n-D: '<S87>/1D_Lookup_Table6'
       *  MinMax: '<S87>/MinMax6'
       *  UnitDelay: '<S87>/Unit Delay7'
       */
      thmd_n_inv2TempFan1_pct = fmaxf
        (thmf_Y_inv2TempFanInc_pct[plook_u32f_bincka
         (swc_THSM_ARID_DEF.DataTypeConversion27, (const float32 *)
          &thmf_X_inv2TempFanInc_t[0], 4U)], thmd_n_inv2TempFan1_pct);
    } else {
      /* Switch: '<S87>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion27'
       *  Lookup_n-D: '<S87>/1D_Lookup_Table7'
       *  MinMax: '<S87>/MinMax7'
       *  UnitDelay: '<S87>/Unit Delay7'
       */
      thmd_n_inv2TempFan1_pct = fminf
        (thmf_Y_inv2TempFanDec_pct[plook_u32f_bincka
         (swc_THSM_ARID_DEF.DataTypeConversion27, (const float32 *)
          &thmf_X_inv2TempFanDec_t[0], 5U)], thmd_n_inv2TempFan1_pct);
    }

    /* End of Switch: '<S87>/Switch3' */

    /* Switch: '<S89>/Switch3' incorporates:
     *  Constant: '<S104>/Constant'
     *  RelationalOperator: '<S104>/Compare'
     *  Sum: '<S89>/Sum3'
     *  UnitDelay: '<S89>/Unit Delay6'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion31 -
        swc_THSM_ARID_DEF.UnitDelay6_DSTATE_h >= 0.0F) {
      /* Switch: '<S89>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion31'
       *  Lookup_n-D: '<S89>/1D_Lookup_Table6'
       *  MinMax: '<S89>/MinMax6'
       *  UnitDelay: '<S89>/Unit Delay7'
       */
      rtb_Switch3_cu = fmaxf(thmf_Y_mot2TempFanlowInc_pct[plook_u32f_bincka
        (swc_THSM_ARID_DEF.DataTypeConversion31, (const float32 *)
         &thmf_X_mot2TempFanlowInc_t[0], 4U)],
        swc_THSM_ARID_DEF.UnitDelay7_DSTATE_m);
    } else {
      /* Switch: '<S89>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion31'
       *  Lookup_n-D: '<S89>/1D_Lookup_Table7'
       *  MinMax: '<S89>/MinMax7'
       *  UnitDelay: '<S89>/Unit Delay7'
       */
      rtb_Switch3_cu = fminf(thmf_Y_mot2TempFanlowDec_pct[plook_u32f_bincka
        (swc_THSM_ARID_DEF.DataTypeConversion31, (const float32 *)
         &thmf_X_mot2TempFanlowDec_t[0], 5U)],
        swc_THSM_ARID_DEF.UnitDelay7_DSTATE_m);
    }

    /* End of Switch: '<S89>/Switch3' */

    /* Switch: '<S93>/Switch3' incorporates:
     *  Constant: '<S108>/Constant'
     *  RelationalOperator: '<S108>/Compare'
     *  Sum: '<S93>/Sum3'
     *  UnitDelay: '<S93>/Unit Delay6'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion33 -
        swc_THSM_ARID_DEF.UnitDelay6_DSTATE_b >= 0.0F) {
      /* Switch: '<S93>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion33'
       *  Lookup_n-D: '<S93>/1D_Lookup_Table6'
       *  MinMax: '<S93>/MinMax6'
       *  UnitDelay: '<S93>/Unit Delay7'
       */
      thmd_n_ts5TempChrFan1_pct = fmaxf
        (thmf_Y_ts5TempFanInc_pct[plook_u32f_bincka
         (swc_THSM_ARID_DEF.DataTypeConversion33, (const float32 *)
          &thmf_X_ts5TempFanInc_t[0], 4U)], thmd_n_ts5TempChrFan1_pct);
    } else {
      /* Switch: '<S93>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion33'
       *  Lookup_n-D: '<S93>/1D_Lookup_Table7'
       *  MinMax: '<S93>/MinMax7'
       *  UnitDelay: '<S93>/Unit Delay7'
       */
      thmd_n_ts5TempChrFan1_pct = fminf
        (thmf_Y_ts5TempFanDec_pct[plook_u32f_bincka
         (swc_THSM_ARID_DEF.DataTypeConversion33, (const float32 *)
          &thmf_X_ts5TempFanDec_t[0], 5U)], thmd_n_ts5TempChrFan1_pct);
    }

    /* End of Switch: '<S93>/Switch3' */

    /* Switch: '<S85>/Switch3' incorporates:
     *  Constant: '<S100>/Constant'
     *  RelationalOperator: '<S100>/Compare'
     *  Sum: '<S85>/Sum3'
     *  UnitDelay: '<S85>/Unit Delay6'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion11 -
        swc_THSM_ARID_DEF.UnitDelay6_DSTATE_p >= 0.0F) {
      /* Switch: '<S85>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion11'
       *  Lookup_n-D: '<S85>/1D_Lookup_Table6'
       *  MinMax: '<S85>/MinMax6'
       *  UnitDelay: '<S85>/Unit Delay7'
       */
      thmd_n_dcdcTempChrFan1_pct = fmaxf
        (thmf_Y_dcdcTempFanIncChr_pct[plook_u32f_bincka
         (swc_THSM_ARID_DEF.DataTypeConversion11, (const float32 *)
          &thmf_X_dcdcTempFanIncChr_t[0], 2U)], thmd_n_dcdcTempChrFan1_pct);
    } else {
      /* Switch: '<S85>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion11'
       *  Lookup_n-D: '<S85>/1D_Lookup_Table7'
       *  MinMax: '<S85>/MinMax7'
       *  UnitDelay: '<S85>/Unit Delay7'
       */
      thmd_n_dcdcTempChrFan1_pct = fminf
        (thmf_Y_dcdcTempFanDecChr_pct[plook_u32f_bincka
         (swc_THSM_ARID_DEF.DataTypeConversion11, (const float32 *)
          &thmf_X_dcdcTempFanDecChr_t[0], 3U)], thmd_n_dcdcTempChrFan1_pct);
    }

    /* End of Switch: '<S85>/Switch3' */

    /* Switch: '<S37>/Switch1' incorporates:
     *  Constant: '<S37>/Constant14'
     */
    rtb_Switch1_h = thmc_n_fan1SpdReqOff_pct;

    /* Switch: '<S37>/Switch19' incorporates:
     *  Constant: '<S37>/Constant8'
     *  Logic: '<S37>/Logical Operator1'
     *  Switch: '<S37>/Switch18'
     */
    if (thmc_b_onlyfterRunAcv || rtb_flg_out_o1) {
      /* Switch: '<S37>/Switch3' incorporates:
       *  Constant: '<S17>/Constant'
       *  Constant: '<S78>/Constant'
       *  RelationalOperator: '<S37>/Relational Operator'
       *  RelationalOperator: '<S3>/Relational Operator11'
       *  RelationalOperator: '<S78>/Compare'
       *  Switch: '<S37>/Switch2'
       */
      if (swc_THSM_ARID_DEF.DataTypeConversion140 == ((uint8)1U)) {
        /* Switch: '<S37>/Switch' incorporates:
         *  Constant: '<S17>/Constant'
         *  RelationalOperator: '<S37>/Relational Operator'
         *  RelationalOperator: '<S3>/Relational Operator11'
         */
        if (thmd_b_accmEnbChrflg_tmp == PmmStatus_CHARGE) {
          /* Switch: '<S37>/Switch19' incorporates:
           *  Constant: '<S37>/Constant1'
           *  MinMax: '<S37>/Max1'
           *  Switch: '<S37>/Switch'
           *  Switch: '<S37>/Switch3'
           */
          thmd_n_fan1TgtSpdLdtBev_pct = fmaxf(fmaxf(fmaxf(0.0F, rtb_Switch3_p),
            rtb_Switch3_hw), swc_THSM_ARID_DEF.DataTypeConversion120);
        } else {
          /* Switch: '<S37>/Switch19' incorporates:
           *  MinMax: '<S37>/Max'
           *  Switch: '<S37>/Switch'
           *  Switch: '<S37>/Switch3'
           */
          thmd_n_fan1TgtSpdLdtBev_pct = fmaxf(fmaxf(fmaxf(fmaxf
            (thmd_n_fan300ts5TempTgtSpd_pct, rtb_Switch3_a), rtb_Switch3_ig),
            rtb_Switch3_pp), swc_THSM_ARID_DEF.DataTypeConversion120);
        }

        /* End of Switch: '<S37>/Switch' */
      } else if (thmd_b_accmEnbChrflg_tmp == PmmStatus_CHARGE) {
        /* Switch: '<S37>/Switch2' incorporates:
         *  Constant: '<S37>/Constant'
         *  MinMax: '<S37>/Max3'
         *  Switch: '<S37>/Switch19'
         *  Switch: '<S37>/Switch3'
         */
        thmd_n_fan1TgtSpdLdtBev_pct = fmaxf(fmaxf(fmaxf(0.0F,
          thmd_n_ts5TempChrFan1_pct), thmd_n_dcdcTempChrFan1_pct),
          swc_THSM_ARID_DEF.DataTypeConversion120);
      } else {
        /* Switch: '<S37>/Switch19' incorporates:
         *  MinMax: '<S37>/Max2'
         *  Switch: '<S37>/Switch2'
         *  Switch: '<S37>/Switch3'
         */
        thmd_n_fan1TgtSpdLdtBev_pct = fmaxf(fmaxf(fmaxf(fmaxf
          (thmd_n_SnsrTempFan1_pct, thmd_n_dcdcTempFan1_pct),
          thmd_n_inv2TempFan1_pct), rtb_Switch3_cu),
          swc_THSM_ARID_DEF.DataTypeConversion120);
      }

      /* End of Switch: '<S37>/Switch3' */
    } else if (thmd_b_fanCtrlEnabled) {
      /* Switch: '<S37>/Switch18' incorporates:
       *  Constant: '<S37>/Constant12'
       *  Switch: '<S37>/Switch19'
       */
      thmd_n_fan1TgtSpdLdtBev_pct = thmc_n_Fan1SpdIni_pct;
    } else {
      /* Switch: '<S37>/Switch19' incorporates:
       *  Constant: '<S37>/Constant11'
       *  Switch: '<S37>/Switch18'
       */
      thmd_n_fan1TgtSpdLdtBev_pct = thmc_n_Fan1SpdOff_pct;
    }

    /* End of Switch: '<S37>/Switch19' */

    /* Switch: '<S90>/Switch1' incorporates:
     *  Constant: '<S105>/Constant'
     *  RelationalOperator: '<S105>/Compare'
     *  Sum: '<S90>/Sum1'
     *  UnitDelay: '<S90>/Unit Delay2'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion21 -
        swc_THSM_ARID_DEF.UnitDelay2_DSTATE_d >= 0.0F) {
      /* Update for UnitDelay: '<S90>/Unit Delay3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion21'
       *  Lookup_n-D: '<S90>/1D_Lookup_Table2'
       *  MinMax: '<S90>/MinMax2'
       *  Switch: '<S90>/Switch1'
       */
      swc_THSM_ARID_DEF.UnitDelay3_DSTATE_j = fmaxf
        (thmf_Y_obcTempFan1Inc_pct[plook_u32f_bincka
         (swc_THSM_ARID_DEF.DataTypeConversion21, (const float32 *)
          &thmf_X_obcTempFan1Inc_t[0], 3U)],
         swc_THSM_ARID_DEF.UnitDelay3_DSTATE_j);
    } else {
      /* Update for UnitDelay: '<S90>/Unit Delay3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion21'
       *  Lookup_n-D: '<S90>/1D_Lookup_Table3'
       *  MinMax: '<S90>/MinMax3'
       *  Switch: '<S90>/Switch1'
       */
      swc_THSM_ARID_DEF.UnitDelay3_DSTATE_j = fminf
        (thmf_Y_obcTempFan1Dec_pct[plook_u32f_bincka
         (swc_THSM_ARID_DEF.DataTypeConversion21, (const float32 *)
          &thmf_X_obcTempFan1Dec_t[0], 4U)],
         swc_THSM_ARID_DEF.UnitDelay3_DSTATE_j);
    }

    /* End of Switch: '<S90>/Switch1' */

    /* Switch: '<S91>/Switch1' incorporates:
     *  Constant: '<S106>/Constant'
     *  RelationalOperator: '<S106>/Compare'
     *  Sum: '<S91>/Sum1'
     *  UnitDelay: '<S91>/Unit Delay2'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion21 -
        swc_THSM_ARID_DEF.UnitDelay2_DSTATE_e >= 0.0F) {
      /* Switch: '<S91>/Switch1' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion21'
       *  Lookup_n-D: '<S91>/1D_Lookup_Table2'
       *  MinMax: '<S91>/MinMax2'
       *  UnitDelay: '<S91>/Unit Delay3'
       */
      thmd_n_obcTempChrFan1_pct = fmaxf
        (thmf_Y_obcTempFanInc_pct[plook_u32f_bincka
         (swc_THSM_ARID_DEF.DataTypeConversion21, (const float32 *)
          &thmf_X_obcTempFanInc_t[0], 2U)], thmd_n_obcTempChrFan1_pct);
    } else {
      /* Switch: '<S91>/Switch1' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion21'
       *  Lookup_n-D: '<S91>/1D_Lookup_Table3'
       *  MinMax: '<S91>/MinMax3'
       *  UnitDelay: '<S91>/Unit Delay3'
       */
      thmd_n_obcTempChrFan1_pct = fminf
        (thmf_Y_obcTempFanDec_pct[plook_u32f_bincka
         (swc_THSM_ARID_DEF.DataTypeConversion21, (const float32 *)
          &thmf_X_obcTempFanDec_t[0], 3U)], thmd_n_obcTempChrFan1_pct);
    }

    /* End of Switch: '<S91>/Switch1' */

    /* Update for UnitDelay: '<S37>/Unit Delay' */
    swc_THSM_ARID_DEF.UnitDelay_DSTATE_i = thmd_b_fanCtrlEnabled;

    /* Update for UnitDelay: '<S80>/Unit Delay6' */
    swc_THSM_ARID_DEF.UnitDelay6_DSTATE_gi =
      swc_THSM_ARID_DEF.DataTypeConversion33;

    /* Update for UnitDelay: '<S82>/Unit Delay7' */
    swc_THSM_ARID_DEF.UnitDelay7_DSTATE_og = rtb_Switch3_a;

    /* Update for UnitDelay: '<S82>/Unit Delay6' */
    swc_THSM_ARID_DEF.UnitDelay6_DSTATE_i =
      swc_THSM_ARID_DEF.DataTypeConversion11;

    /* Update for UnitDelay: '<S86>/Unit Delay7' */
    swc_THSM_ARID_DEF.UnitDelay7_DSTATE_l = rtb_Switch3_ig;

    /* Update for UnitDelay: '<S86>/Unit Delay6' */
    swc_THSM_ARID_DEF.UnitDelay6_DSTATE_o =
      swc_THSM_ARID_DEF.DataTypeConversion27;

    /* Update for UnitDelay: '<S88>/Unit Delay7' */
    swc_THSM_ARID_DEF.UnitDelay7_DSTATE_d = rtb_Switch3_pp;

    /* Update for UnitDelay: '<S88>/Unit Delay6' */
    swc_THSM_ARID_DEF.UnitDelay6_DSTATE_o4 =
      swc_THSM_ARID_DEF.DataTypeConversion31;

    /* Update for UnitDelay: '<S92>/Unit Delay7' */
    swc_THSM_ARID_DEF.UnitDelay7_DSTATE_f = rtb_Switch3_p;

    /* Update for UnitDelay: '<S92>/Unit Delay6' */
    swc_THSM_ARID_DEF.UnitDelay6_DSTATE_a =
      swc_THSM_ARID_DEF.DataTypeConversion33;

    /* Update for UnitDelay: '<S84>/Unit Delay7' */
    swc_THSM_ARID_DEF.UnitDelay7_DSTATE_k = rtb_Switch3_hw;

    /* Update for UnitDelay: '<S84>/Unit Delay6' */
    swc_THSM_ARID_DEF.UnitDelay6_DSTATE_n =
      swc_THSM_ARID_DEF.DataTypeConversion11;

    /* Update for UnitDelay: '<S81>/Unit Delay6' */
    swc_THSM_ARID_DEF.UnitDelay6_DSTATE_k =
      swc_THSM_ARID_DEF.DataTypeConversion33;

    /* Update for UnitDelay: '<S83>/Unit Delay6' */
    swc_THSM_ARID_DEF.UnitDelay6_DSTATE_l =
      swc_THSM_ARID_DEF.DataTypeConversion11;

    /* Update for UnitDelay: '<S87>/Unit Delay6' */
    swc_THSM_ARID_DEF.UnitDelay6_DSTATE_f =
      swc_THSM_ARID_DEF.DataTypeConversion27;

    /* Update for UnitDelay: '<S89>/Unit Delay7' */
    swc_THSM_ARID_DEF.UnitDelay7_DSTATE_m = rtb_Switch3_cu;

    /* Update for UnitDelay: '<S89>/Unit Delay6' */
    swc_THSM_ARID_DEF.UnitDelay6_DSTATE_h =
      swc_THSM_ARID_DEF.DataTypeConversion31;

    /* Update for UnitDelay: '<S93>/Unit Delay6' */
    swc_THSM_ARID_DEF.UnitDelay6_DSTATE_b =
      swc_THSM_ARID_DEF.DataTypeConversion33;

    /* Update for UnitDelay: '<S85>/Unit Delay6' */
    swc_THSM_ARID_DEF.UnitDelay6_DSTATE_p =
      swc_THSM_ARID_DEF.DataTypeConversion11;

    /* Update for UnitDelay: '<S90>/Unit Delay2' */
    swc_THSM_ARID_DEF.UnitDelay2_DSTATE_d =
      swc_THSM_ARID_DEF.DataTypeConversion21;

    /* Update for UnitDelay: '<S91>/Unit Delay2' */
    swc_THSM_ARID_DEF.UnitDelay2_DSTATE_e =
      swc_THSM_ARID_DEF.DataTypeConversion21;

    /* Logic: '<S33>/Logical Operator' incorporates:
     *  Constant: '<S17>/Constant'
     *  RelationalOperator: '<S33>/Relational Operator2'
     *  RelationalOperator: '<S3>/Relational Operator11'
     */
    rtb_Relay4_g = ((thmd_b_accmEnbChrflg_tmp != PmmStatus_CHARGE) &&
                    thmd_b_accmEnboffChrflg_tmp);

    /* RelationalOperator: '<S41>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S41>/Delay Input1'
     *
     * Block description for '<S41>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_FixPtRelationalOperator_m = ((sint32)rtb_Relay4_g > (sint32)
      swc_THSM_ARID_DEF.DelayInput1_DSTATE_ny);

    /* Outputs for Atomic SubSystem: '<S33>/turnOFF_delay' */
    swc_THSM_turnOFF_delay(rtb_FixPtRelationalOperator_m, thmc_tm_Fan115OffDly_s,
      ((float32)THM_TASK_INTERVAL_S), &rtb_flg_out_l,
      &swc_THSM_ARID_DEF.ARID_DEF_turnOFF_delay_f);

    /* End of Outputs for SubSystem: '<S33>/turnOFF_delay' */

    /* Switch: '<S33>/Switch2' incorporates:
     *  Constant: '<S33>/Constant10'
     *  Constant: '<S33>/Constant9'
     */
    if (thmd_b_FaultSts_flg) {
      /* Switch: '<S33>/Switch3' incorporates:
       *  Constant: '<S40>/Constant'
       *  RelationalOperator: '<S40>/Compare'
       */
      if (swc_THSM_ARID_DEF.DataTypeConversion140 == ((uint8)1U)) {
        /* Switch: '<S33>/Switch2' incorporates:
         *  Constant: '<S33>/Constant1'
         */
        thmd_n_fan1DelayModTgtSpd_pct = thmc_n_fan1SpdReqFltSts_pct;
      } else {
        /* Switch: '<S33>/Switch2' incorporates:
         *  Constant: '<S33>/Constant3'
         */
        thmd_n_fan1DelayModTgtSpd_pct = thmc_n_fan120SpdReqFltSts_pct;
      }

      /* End of Switch: '<S33>/Switch3' */
    } else {
      /* Switch: '<S33>/Switch2' */
      thmd_n_fan1DelayModTgtSpd_pct = thmd_n_fan1TgtSpdLdtBev_pct;
    }

    /* End of Switch: '<S33>/Switch2' */

    /* Switch: '<S33>/Switch5' incorporates:
     *  Constant: '<S17>/Constant'
     *  Logic: '<S33>/Logical Operator1'
     *  Logic: '<S33>/Logical Operator2'
     *  Logic: '<S33>/Logical Operator3'
     *  Logic: '<S33>/Logical Operator5'
     *  RelationalOperator: '<S33>/Relational Operator1'
     *  RelationalOperator: '<S3>/Relational Operator11'
     *  Switch: '<S33>/Switch1'
     */
    if (rtb_flg_out_l && rtb_Relay4_g) {
      /* Switch: '<S33>/Switch5' incorporates:
       *  Delay: '<S33>/Delay One Step1'
       */
      rtb_Switch3_a = swc_THSM_ARID_DEF.DelayOneStep1_DSTATE_f;
    } else if ((thmd_b_accmEnbChrflg_tmp == PmmStatus_CHARGE) ||
               swc_THSM_ARID_DEF.DataTypeConversion22) {
      /* Switch: '<S33>/Switch1' incorporates:
       *  Switch: '<S33>/Switch5'
       */
      rtb_Switch3_a = thmd_n_fan1DelayModTgtSpd_pct;
    } else {
      /* Switch: '<S33>/Switch5' incorporates:
       *  Constant: '<S33>/Constant2'
       *  Switch: '<S33>/Switch1'
       */
      rtb_Switch3_a = thmc_n_fan1SpdReqOff_pct;
    }

    /* Switch: '<S33>/Switch6' incorporates:
     *  Constant: '<S33>/Constant'
     *  Constant: '<S33>/Constant5'
     *  RelationalOperator: '<S33>/Relational Operator'
     *  Switch: '<S33>/Switch4'
     */
    if (thmc_n_fan1SpdReqEnable) {
      /* Switch: '<S33>/Switch4' incorporates:
       *  Constant: '<S33>/Constant'
       *  Constant: '<S33>/Constant7'
       *  RelationalOperator: '<S33>/Relational Operator'
       */
      if (swc_THSM_ARID_DEF.DataTypeConversion15 == true) {
        rtb_Switch3_ig = thmc_n_fan1SpdReqOff_pct;
      } else {
        rtb_Switch3_ig = rtb_Switch3_a;
      }

      /* Switch: '<S33>/Switch6' incorporates:
       *  Constant: '<S33>/Constant6'
       *  Sum: '<S33>/Subtract'
       *  Switch: '<S33>/Switch4'
       */
      thmd_n_fan1TgtSpd_pct = thmc_n_fan1SpdReqfull_pct - rtb_Switch3_ig;
    } else if (swc_THSM_ARID_DEF.DataTypeConversion15 == true) {
      /* Switch: '<S33>/Switch4' incorporates:
       *  Constant: '<S33>/Constant7'
       *  Switch: '<S33>/Switch6'
       */
      thmd_n_fan1TgtSpd_pct = thmc_n_fan1SpdReqOff_pct;
    } else {
      /* Switch: '<S33>/Switch6' incorporates:
       *  Switch: '<S33>/Switch4'
       */
      thmd_n_fan1TgtSpd_pct = rtb_Switch3_a;
    }

    /* End of Switch: '<S33>/Switch6' */

    /* Product: '<S33>/Product2' incorporates:
     *  Constant: '<S33>/Constant4'
     *  Gain: '<S33>/Gain2'
     */
    rtb_thmd_n_fan1TgtSpd_rpm_m = 0.01F * thmd_n_fan1TgtSpd_pct *
      thmc_n_fanMaxSpd_rpm;

    /* Update for Delay: '<S33>/Delay One Step1' */
    swc_THSM_ARID_DEF.DelayOneStep1_DSTATE_f = rtb_Switch3_a;

    /* Update for UnitDelay: '<S41>/Delay Input1'
     *
     * Block description for '<S41>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_THSM_ARID_DEF.DelayInput1_DSTATE_ny = rtb_Relay4_g;

    /* Switch: '<S8>/Switch' */
    rtb_Switch3_a = thmd_n_fan1TgtSpd_pct;
  } else {
    /* Outputs for Enabled SubSystem: '<S8>/Fan1TgtSpdAirCool' incorporates:
     *  EnablePort: '<S36>/Enable'
     */
    /* UnitDelay: '<S36>/Unit Delay' */
    rtb_UnitDelay_k = swc_THSM_ARID_DEF.UnitDelay_DSTATE_f;

    /* Outputs for Atomic SubSystem: '<S36>/turnON_delay' */
    swc_THSM_turnON_delay(rtb_UnitDelay_k, thmc_tm_Fan1EnbDly_s, ((float32)
      THM_TASK_INTERVAL_S), &rtb_flg_out_am,
                          &swc_THSM_ARID_DEF.ARID_DEF_turnON_delay_p);

    /* End of Outputs for SubSystem: '<S36>/turnON_delay' */

    /* Lookup_n-D: '<S63>/2-D Lookup Table' incorporates:
     *  Constant: '<S36>/Constant10'
     *  Constant: '<S36>/Constant9'
     *  DataTypeConversion: '<Root>/Data Type Conversion33'
     *  DataTypeConversion: '<Root>/Data Type Conversion39'
     */
    thmd_n_fan1SnsrTempAirCl_pct = look2_iflf_binlcpw
      (swc_THSM_ARID_DEF.DataTypeConversion33,
       swc_THSM_ARID_DEF.DataTypeConversion39, (const float32 *)
       &thmf_Y_fan1SnsrTempAirCl_t[0], (const float32 *)
       &thmf_X_fan1VehSpdAirCl_kph[0], (const float32 *)
       &thmf_Z_fan1SnsrTempAirCl_pct[0], swc_THSM_ConstP.uDLookupTable_maxIndex,
       7U);

    /* Switch: '<S64>/Switch3' incorporates:
     *  Constant: '<S71>/Constant'
     *  RelationalOperator: '<S71>/Compare'
     *  Sum: '<S64>/Sum3'
     *  UnitDelay: '<S64>/Unit Delay6'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion11 -
        swc_THSM_ARID_DEF.UnitDelay6_DSTATE_oi >= 0.0F) {
      /* Switch: '<S64>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion11'
       *  Lookup_n-D: '<S64>/1D_Lookup_Table6'
       *  MinMax: '<S64>/MinMax6'
       *  UnitDelay: '<S64>/Unit Delay7'
       */
      thmd_n_fan1DcdcTempAirCl_pct = fmaxf(look1_iflf_binlcapw
        (swc_THSM_ARID_DEF.DataTypeConversion11, (const float32 *)
         &thmf_X_fan1dcdcTempIncAirCl_t[0], (const float32 *)
         &thmf_Y_fan1dcdcTempIncAirCl_pct[0], 6U), thmd_n_fan1DcdcTempAirCl_pct);
    } else {
      /* Switch: '<S64>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion11'
       *  Lookup_n-D: '<S64>/1D_Lookup_Table7'
       *  MinMax: '<S64>/MinMax7'
       *  UnitDelay: '<S64>/Unit Delay7'
       */
      thmd_n_fan1DcdcTempAirCl_pct = fminf(look1_iflf_binlcapw
        (swc_THSM_ARID_DEF.DataTypeConversion11, (const float32 *)
         &thmf_X_fan1dcdcTempDecAirCl_t[0], (const float32 *)
         &thmf_Y_fan1dcdcTempDecAirCl_pct[0], 6U), thmd_n_fan1DcdcTempAirCl_pct);
    }

    /* End of Switch: '<S64>/Switch3' */

    /* Switch: '<S66>/Switch3' incorporates:
     *  Constant: '<S73>/Constant'
     *  RelationalOperator: '<S73>/Compare'
     *  Sum: '<S66>/Sum3'
     *  UnitDelay: '<S66>/Unit Delay6'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion27 -
        swc_THSM_ARID_DEF.UnitDelay6_DSTATE_gk >= 0.0F) {
      /* Switch: '<S66>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion27'
       *  Lookup_n-D: '<S66>/1D_Lookup_Table6'
       *  MinMax: '<S66>/MinMax6'
       *  UnitDelay: '<S66>/Unit Delay7'
       */
      thmd_n_fan1Inv2TempAirCl_pct = fmaxf(look1_iflf_binlcapw
        (swc_THSM_ARID_DEF.DataTypeConversion27, (const float32 *)
         &thmf_X_fan1inv2TempIncAirCl_t[0], (const float32 *)
         &thmf_Y_fan1inv2TempIncAirCl_pct[0], 6U), thmd_n_fan1Inv2TempAirCl_pct);
    } else {
      /* Switch: '<S66>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion27'
       *  Lookup_n-D: '<S66>/1D_Lookup_Table7'
       *  MinMax: '<S66>/MinMax7'
       *  UnitDelay: '<S66>/Unit Delay7'
       */
      thmd_n_fan1Inv2TempAirCl_pct = fminf(look1_iflf_binlcapw
        (swc_THSM_ARID_DEF.DataTypeConversion27, (const float32 *)
         &thmf_X_fan1inv2TempDecAirCl_t[0], (const float32 *)
         &thmf_Y_fan1inv2TempDecAirCl_pct[0], 6U), thmd_n_fan1Inv2TempAirCl_pct);
    }

    /* End of Switch: '<S66>/Switch3' */

    /* Switch: '<S67>/Switch3' incorporates:
     *  Constant: '<S74>/Constant'
     *  RelationalOperator: '<S74>/Compare'
     *  Sum: '<S67>/Sum3'
     *  UnitDelay: '<S67>/Unit Delay6'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion31 -
        swc_THSM_ARID_DEF.UnitDelay6_DSTATE_oh >= 0.0F) {
      /* Switch: '<S67>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion31'
       *  Lookup_n-D: '<S67>/1D_Lookup_Table6'
       *  MinMax: '<S67>/MinMax6'
       *  UnitDelay: '<S67>/Unit Delay7'
       */
      thmd_n_fan1Mot2TempAirCl_pct = fmaxf(look1_iflf_binlcapw
        (swc_THSM_ARID_DEF.DataTypeConversion31, (const float32 *)
         &thmf_X_fan1mot2TempIncAirCl_t[0], (const float32 *)
         &thmf_Y_fan1mot2TempIncAirCl_pct[0], 7U), thmd_n_fan1Mot2TempAirCl_pct);
    } else {
      /* Switch: '<S67>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion31'
       *  Lookup_n-D: '<S67>/1D_Lookup_Table7'
       *  MinMax: '<S67>/MinMax7'
       *  UnitDelay: '<S67>/Unit Delay7'
       */
      thmd_n_fan1Mot2TempAirCl_pct = fminf(look1_iflf_binlcapw
        (swc_THSM_ARID_DEF.DataTypeConversion31, (const float32 *)
         &thmf_X_fan1mot2TempDecAirCl_t[0], (const float32 *)
         &thmf_Y_fan1mot2TempDecAirCl_pct[0], 7U), thmd_n_fan1Mot2TempAirCl_pct);
    }

    /* End of Switch: '<S67>/Switch3' */

    /* Switch: '<S69>/Switch3' incorporates:
     *  Constant: '<S76>/Constant'
     *  RelationalOperator: '<S76>/Compare'
     *  Sum: '<S69>/Sum3'
     *  UnitDelay: '<S69>/Unit Delay6'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion33 -
        swc_THSM_ARID_DEF.UnitDelay6_DSTATE_g3 >= 0.0F) {
      /* Switch: '<S69>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion33'
       *  Lookup_n-D: '<S69>/1D_Lookup_Table6'
       *  MinMax: '<S69>/MinMax6'
       *  UnitDelay: '<S69>/Unit Delay7'
       */
      thmd_n_fan1ts5TempChrAirCl_pct = fmaxf(look1_iflf_binlcapw
        (swc_THSM_ARID_DEF.DataTypeConversion33, (const float32 *)
         &thmf_X_fan1ts5TempChgIncAirCl_t[0], (const float32 *)
         &thmf_Y_fan1ts5TempChgIncAirCl_pct[0], 7U),
        thmd_n_fan1ts5TempChrAirCl_pct);
    } else {
      /* Switch: '<S69>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion33'
       *  Lookup_n-D: '<S69>/1D_Lookup_Table7'
       *  MinMax: '<S69>/MinMax7'
       *  UnitDelay: '<S69>/Unit Delay7'
       */
      thmd_n_fan1ts5TempChrAirCl_pct = fminf(look1_iflf_binlcapw
        (swc_THSM_ARID_DEF.DataTypeConversion33, (const float32 *)
         &thmf_X_fan1ts5TempChgDecAirCl_t[0], (const float32 *)
         &thmf_Y_fan1ts5TempChgDecAirCl_pct[0], 7U),
        thmd_n_fan1ts5TempChrAirCl_pct);
    }

    /* End of Switch: '<S69>/Switch3' */

    /* Switch: '<S65>/Switch3' incorporates:
     *  Constant: '<S72>/Constant'
     *  RelationalOperator: '<S72>/Compare'
     *  Sum: '<S65>/Sum3'
     *  UnitDelay: '<S65>/Unit Delay6'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion11 -
        swc_THSM_ARID_DEF.UnitDelay6_DSTATE_fq >= 0.0F) {
      /* Switch: '<S65>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion11'
       *  Lookup_n-D: '<S65>/1D_Lookup_Table6'
       *  MinMax: '<S65>/MinMax6'
       *  UnitDelay: '<S65>/Unit Delay7'
       */
      thmd_n_fan1DcdcTempChrAirCl_pct = fmaxf(look1_iflf_binlcapw
        (swc_THSM_ARID_DEF.DataTypeConversion11, (const float32 *)
         &thmf_X_fan1DcdcTempChgIncAirCl_t[0], (const float32 *)
         &thmf_Y_fan1DcdcTempChgIncAirCl_pct[0], 7U),
        thmd_n_fan1DcdcTempChrAirCl_pct);
    } else {
      /* Switch: '<S65>/Switch3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion11'
       *  Lookup_n-D: '<S65>/1D_Lookup_Table7'
       *  MinMax: '<S65>/MinMax7'
       *  UnitDelay: '<S65>/Unit Delay7'
       */
      thmd_n_fan1DcdcTempChrAirCl_pct = fminf(look1_iflf_binlcapw
        (swc_THSM_ARID_DEF.DataTypeConversion11, (const float32 *)
         &thmf_X_fan1DcdcTempChgDecAirCl_t[0], (const float32 *)
         &thmf_Y_fan1DcdcTempChgDecAirCl_pct[0], 7U),
        thmd_n_fan1DcdcTempChrAirCl_pct);
    }

    /* End of Switch: '<S65>/Switch3' */

    /* Switch: '<S36>/Switch19' incorporates:
     *  Constant: '<S36>/Constant8'
     *  Logic: '<S36>/Logical Operator1'
     *  Switch: '<S36>/Switch18'
     */
    if (thmc_b_onlyfterRunAcv || rtb_flg_out_am) {
      /* Switch: '<S36>/Switch' incorporates:
       *  Constant: '<S17>/Constant'
       *  RelationalOperator: '<S36>/Relational Operator'
       *  RelationalOperator: '<S3>/Relational Operator11'
       */
      if (thmd_b_accmEnbChrflg_tmp == PmmStatus_CHARGE) {
        /* Switch: '<S36>/Switch19' incorporates:
         *  Constant: '<S36>/Constant'
         *  MinMax: '<S36>/Max1'
         *  Switch: '<S36>/Switch'
         */
        thmd_n_fan1TgtSpdAirCl_pct = fmaxf(fmaxf(fmaxf(5.0F,
          thmd_n_fan1ts5TempChrAirCl_pct), thmd_n_fan1DcdcTempChrAirCl_pct),
          swc_THSM_ARID_DEF.DataTypeConversion120);
      } else {
        /* Switch: '<S36>/Switch19' incorporates:
         *  MinMax: '<S36>/Max'
         *  Switch: '<S36>/Switch'
         */
        thmd_n_fan1TgtSpdAirCl_pct = fmaxf(fmaxf(fmaxf(fmaxf
          (thmd_n_fan1SnsrTempAirCl_pct, thmd_n_fan1DcdcTempAirCl_pct),
          thmd_n_fan1Inv2TempAirCl_pct), thmd_n_fan1Mot2TempAirCl_pct),
          swc_THSM_ARID_DEF.DataTypeConversion120);
      }

      /* End of Switch: '<S36>/Switch' */
    } else if (thmd_b_fanCtrlEnabled) {
      /* Switch: '<S36>/Switch18' incorporates:
       *  Constant: '<S36>/Constant12'
       *  Switch: '<S36>/Switch19'
       */
      thmd_n_fan1TgtSpdAirCl_pct = thmc_n_Fan1SpdIni_pct;
    } else {
      /* Switch: '<S36>/Switch19' incorporates:
       *  Constant: '<S36>/Constant11'
       *  Switch: '<S36>/Switch18'
       */
      thmd_n_fan1TgtSpdAirCl_pct = thmc_n_fan1SpdOffAirCl_pct;
    }

    /* Switch: '<S68>/Switch1' incorporates:
     *  Constant: '<S75>/Constant'
     *  RelationalOperator: '<S75>/Compare'
     *  Sum: '<S68>/Sum1'
     *  UnitDelay: '<S68>/Unit Delay2'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion21 -
        swc_THSM_ARID_DEF.UnitDelay2_DSTATE_dp >= 0.0F) {
      /* Switch: '<S68>/Switch1' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion21'
       *  Lookup_n-D: '<S68>/1D_Lookup_Table2'
       *  MinMax: '<S68>/MinMax2'
       *  UnitDelay: '<S68>/Unit Delay3'
       */
      thmd_n_fan1obcTempChrAirCl_pct = fmaxf(look1_iflf_binlcapw
        (swc_THSM_ARID_DEF.DataTypeConversion21, (const float32 *)
         &thmf_X_fan1obcTempChgIncAirCl_t[0], (const float32 *)
         &thmf_Y_fan1obcTempChgIncAirCl_pct[0], 5U),
        thmd_n_fan1obcTempChrAirCl_pct);
    } else {
      /* Switch: '<S68>/Switch1' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion21'
       *  Lookup_n-D: '<S68>/1D_Lookup_Table3'
       *  MinMax: '<S68>/MinMax3'
       *  UnitDelay: '<S68>/Unit Delay3'
       */
      thmd_n_fan1obcTempChrAirCl_pct = fminf(look1_iflf_binlcapw
        (swc_THSM_ARID_DEF.DataTypeConversion21, (const float32 *)
         &thmf_X_fan1obcTempChgDecAirCl_t[0], (const float32 *)
         &thmf_Y_fan1obcTempChgDecAirCl_pct[0], 5U),
        thmd_n_fan1obcTempChrAirCl_pct);
    }

    /* End of Switch: '<S68>/Switch1' */

    /* Update for UnitDelay: '<S36>/Unit Delay' */
    swc_THSM_ARID_DEF.UnitDelay_DSTATE_f = thmd_b_fanCtrlEnabled;

    /* Update for UnitDelay: '<S64>/Unit Delay6' */
    swc_THSM_ARID_DEF.UnitDelay6_DSTATE_oi =
      swc_THSM_ARID_DEF.DataTypeConversion11;

    /* Update for UnitDelay: '<S66>/Unit Delay6' */
    swc_THSM_ARID_DEF.UnitDelay6_DSTATE_gk =
      swc_THSM_ARID_DEF.DataTypeConversion27;

    /* Update for UnitDelay: '<S67>/Unit Delay6' */
    swc_THSM_ARID_DEF.UnitDelay6_DSTATE_oh =
      swc_THSM_ARID_DEF.DataTypeConversion31;

    /* Update for UnitDelay: '<S69>/Unit Delay6' */
    swc_THSM_ARID_DEF.UnitDelay6_DSTATE_g3 =
      swc_THSM_ARID_DEF.DataTypeConversion33;

    /* Update for UnitDelay: '<S65>/Unit Delay6' */
    swc_THSM_ARID_DEF.UnitDelay6_DSTATE_fq =
      swc_THSM_ARID_DEF.DataTypeConversion11;

    /* Update for UnitDelay: '<S68>/Unit Delay2' */
    swc_THSM_ARID_DEF.UnitDelay2_DSTATE_dp =
      swc_THSM_ARID_DEF.DataTypeConversion21;

    /* End of Outputs for SubSystem: '<S8>/Fan1TgtSpdAirCool' */

    /* Outputs for Enabled SubSystem: '<S8>/Fan1TargetSpeedArbitrationAirCool' incorporates:
     *  EnablePort: '<S34>/Enable'
     */
    /* Logic: '<S34>/Logical Operator' incorporates:
     *  Constant: '<S17>/Constant'
     *  RelationalOperator: '<S34>/Relational Operator2'
     *  RelationalOperator: '<S3>/Relational Operator11'
     */
    rtb_Relay4_g = ((thmd_b_accmEnbChrflg_tmp != PmmStatus_CHARGE) &&
                    thmd_b_accmEnboffChrflg_tmp);

    /* RelationalOperator: '<S46>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S46>/Delay Input1'
     *
     * Block description for '<S46>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_FixPtRelationalOperator_h = ((sint32)rtb_Relay4_g > (sint32)
      swc_THSM_ARID_DEF.DelayInput1_DSTATE_nm);

    /* Outputs for Atomic SubSystem: '<S34>/turnOFF_delay' */
    swc_THSM_turnOFF_delay(rtb_FixPtRelationalOperator_h,
      thmc_tm_Fan115OffDlyAirCl_s, ((float32)THM_TASK_INTERVAL_S),
      &rtb_flg_out_eb, &swc_THSM_ARID_DEF.ARID_DEF_turnOFF_delay_c);

    /* End of Outputs for SubSystem: '<S34>/turnOFF_delay' */

    /* Switch: '<S34>/Switch2' incorporates:
     *  Constant: '<S34>/Constant10'
     *  Constant: '<S34>/Constant9'
     */
    if (thmd_b_FaultSts_flg) {
      /* Switch: '<S34>/Switch2' incorporates:
       *  Constant: '<S34>/Constant1'
       */
      thmd_n_fan1DlyTgtSpdAirCl_pct = thmc_n_fan1SpdReqFltAirCl_pct;
    } else {
      /* Switch: '<S34>/Switch2' */
      thmd_n_fan1DlyTgtSpdAirCl_pct = thmd_n_fan1TgtSpdAirCl_pct;
    }

    /* End of Switch: '<S34>/Switch2' */

    /* Switch: '<S34>/Switch5' incorporates:
     *  Constant: '<S17>/Constant'
     *  Logic: '<S34>/Logical Operator1'
     *  Logic: '<S34>/Logical Operator2'
     *  Logic: '<S34>/Logical Operator3'
     *  Logic: '<S34>/Logical Operator4'
     *  RelationalOperator: '<S34>/Relational Operator1'
     *  RelationalOperator: '<S3>/Relational Operator11'
     *  Switch: '<S34>/Switch1'
     */
    if (rtb_flg_out_eb && rtb_Relay4_g) {
      /* Switch: '<S34>/Switch5' incorporates:
       *  Delay: '<S34>/Delay One Step1'
       */
      rtb_Switch3_a = swc_THSM_ARID_DEF.DelayOneStep1_DSTATE_c;
    } else if ((thmd_b_accmEnbChrflg_tmp == PmmStatus_CHARGE) ||
               swc_THSM_ARID_DEF.DataTypeConversion22) {
      /* Switch: '<S34>/Switch1' incorporates:
       *  Switch: '<S34>/Switch5'
       */
      rtb_Switch3_a = thmd_n_fan1DlyTgtSpdAirCl_pct;
    } else {
      /* Switch: '<S34>/Switch5' incorporates:
       *  Constant: '<S34>/Constant2'
       *  Switch: '<S34>/Switch1'
       */
      rtb_Switch3_a = thmc_n_fan1SpdReqOffAirCl_pct;
    }

    /* Switch: '<S34>/Switch6' incorporates:
     *  Constant: '<S34>/Constant'
     *  Constant: '<S34>/Constant5'
     *  RelationalOperator: '<S34>/Relational Operator'
     *  Switch: '<S34>/Switch4'
     */
    if (thmc_n_fan1SpdReqEnbAirCl) {
      /* Switch: '<S34>/Switch4' incorporates:
       *  Constant: '<S34>/Constant'
       *  Constant: '<S34>/Constant3'
       *  RelationalOperator: '<S34>/Relational Operator'
       */
      if (swc_THSM_ARID_DEF.DataTypeConversion15 == true) {
        rtb_Switch3_ig = thmc_n_fan1SpdReqOffAirCl_pct;
      } else {
        rtb_Switch3_ig = rtb_Switch3_a;
      }

      /* Switch: '<S34>/Switch6' incorporates:
       *  Constant: '<S34>/Constant6'
       *  Sum: '<S34>/Subtract'
       *  Switch: '<S34>/Switch4'
       */
      thmd_n_fan1TgtSpdAirCl2_pct = thmc_n_fan1SpdReqfull_pct - rtb_Switch3_ig;
    } else if (swc_THSM_ARID_DEF.DataTypeConversion15 == true) {
      /* Switch: '<S34>/Switch4' incorporates:
       *  Constant: '<S34>/Constant3'
       *  Switch: '<S34>/Switch6'
       */
      thmd_n_fan1TgtSpdAirCl2_pct = thmc_n_fan1SpdReqOffAirCl_pct;
    } else {
      /* Switch: '<S34>/Switch6' incorporates:
       *  Switch: '<S34>/Switch4'
       */
      thmd_n_fan1TgtSpdAirCl2_pct = rtb_Switch3_a;
    }

    /* End of Switch: '<S34>/Switch6' */

    /* Product: '<S34>/Product2' incorporates:
     *  Constant: '<S34>/Constant4'
     *  Gain: '<S34>/Gain2'
     */
    rtb_thmd_n_fan1TgtSpd_rpm = 0.01F * thmd_n_fan1TgtSpdAirCl2_pct *
      thmc_n_fanMaxSpd_rpm;

    /* Update for Delay: '<S34>/Delay One Step1' */
    swc_THSM_ARID_DEF.DelayOneStep1_DSTATE_c = rtb_Switch3_a;

    /* Update for UnitDelay: '<S46>/Delay Input1'
     *
     * Block description for '<S46>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_THSM_ARID_DEF.DelayInput1_DSTATE_nm = rtb_Relay4_g;

    /* End of Outputs for SubSystem: '<S8>/Fan1TargetSpeedArbitrationAirCool' */

    /* Switch: '<S8>/Switch' */
    rtb_Switch3_a = thmd_n_fan1TgtSpdAirCl2_pct;
  }

  /* End of Logic: '<S8>/Logical Operator1' */
  /* End of Outputs for SubSystem: '<S8>/Fan1TgtSpdLdt45TBev' */
  /* End of Outputs for SubSystem: '<S8>/Fan1TargetSpeedArbitration' */

  /* Switch: '<S35>/Switch' incorporates:
   *  Constant: '<S35>/Constant12'
   *  Constant: '<S35>/Constant9'
   *  RelationalOperator: '<S35>/Relational Operator5'
   *  RelationalOperator: '<S35>/Relational Operator8'
   *  Switch: '<S35>/Switch9'
   */
  if (swc_THSM_ARID_DEF.DataTypeConversion140 == ((uint8)1U)) {
    /* Switch: '<S35>/Switch8' incorporates:
     *  Constant: '<S35>/Constant10'
     *  Constant: '<S35>/Constant11'
     *  RelationalOperator: '<S35>/Relational Operator6'
     *  RelationalOperator: '<S35>/Relational Operator7'
     *  Switch: '<S35>/Switch7'
     */
    if (rtb_Switch3_a == ((uint8)100U)) {
      /* Switch: '<S35>/Switch' incorporates:
       *  Constant: '<S57>/Constant'
       *  Switch: '<S35>/Switch8'
       */
      thmd_e_fanTgtSts = FanStatus_HIGH_SPEED;
    } else if (rtb_Switch3_a == ((uint8)50U)) {
      /* Switch: '<S35>/Switch7' incorporates:
       *  Constant: '<S56>/Constant'
       *  Switch: '<S35>/Switch'
       *  Switch: '<S35>/Switch8'
       */
      thmd_e_fanTgtSts = FanStatus_LOW_SPEED;
    } else {
      /* Switch: '<S35>/Switch' incorporates:
       *  Constant: '<S51>/Constant'
       *  Switch: '<S35>/Switch7'
       *  Switch: '<S35>/Switch8'
       */
      thmd_e_fanTgtSts = FanStatus_OFF;
    }

    /* End of Switch: '<S35>/Switch8' */
  } else if (rtb_Switch3_a == ((uint8)50U)) {
    /* Switch: '<S35>/Switch9' incorporates:
     *  Constant: '<S59>/Constant'
     *  Switch: '<S35>/Switch'
     */
    thmd_e_fanTgtSts = FanStatus_LOW_SPEED;
  } else {
    /* Switch: '<S35>/Switch' incorporates:
     *  Constant: '<S60>/Constant'
     *  Switch: '<S35>/Switch9'
     */
    thmd_e_fanTgtSts = FanStatus_OFF;
  }

  /* End of Switch: '<S35>/Switch' */

  /* Outputs for Atomic SubSystem: '<S32>/state_mapping' */
  /* Saturate: '<S38>/Saturation1' incorporates:
   *  DataTypeConversion: '<S38>/Data Type Conversion'
   *  Switch: '<S35>/Switch'
   */
  if (thmd_e_fanTgtSts <= ((uint8)3U)) {
    /* Saturate: '<S38>/Saturation1' */
    rtb_Saturation1_c = thmd_e_fanTgtSts;
  } else {
    /* Saturate: '<S38>/Saturation1' */
    rtb_Saturation1_c = ((uint8)3U);
  }

  /* End of Saturate: '<S38>/Saturation1' */

  /* Switch: '<S38>/Switch' incorporates:
   *  DataTypeConversion: '<S38>/Data Type Conversion'
   *  RelationalOperator: '<S38>/Relational Operator'
   *  Switch: '<S35>/Switch'
   */
  if (thmd_e_fanTgtSts > rtb_Saturation1_c) {
    /* Switch: '<S38>/Switch' incorporates:
     *  Constant: '<S32>/Constant1'
     */
    thmd_b_fanRly1Req = thmc_b_fanRly1Dflt;
  } else {
    /* Switch: '<S38>/Switch' incorporates:
     *  Constant: '<S32>/Constant'
     *  MultiPortSwitch: '<S38>/Index Vector'
     */
    thmd_b_fanRly1Req = THM_FANRLY1[rtb_Saturation1_c];
  }

  /* End of Switch: '<S38>/Switch' */

  /* Outputs for Atomic SubSystem: '<S32>/state_mapping1' */
  /* Saturate: '<S39>/Saturation1' incorporates:
   *  DataTypeConversion: '<S38>/Data Type Conversion'
   *  Switch: '<S35>/Switch'
   */
  if (thmd_e_fanTgtSts <= ((uint8)3U)) {
    /* Saturate: '<S39>/Saturation1' */
    rtb_Saturation1_c = thmd_e_fanTgtSts;
  } else {
    /* Saturate: '<S39>/Saturation1' */
    rtb_Saturation1_c = ((uint8)3U);
  }

  /* End of Saturate: '<S39>/Saturation1' */

  /* Switch: '<S39>/Switch' incorporates:
   *  DataTypeConversion: '<S38>/Data Type Conversion'
   *  RelationalOperator: '<S39>/Relational Operator'
   *  Switch: '<S35>/Switch'
   */
  if (thmd_e_fanTgtSts > rtb_Saturation1_c) {
    /* Switch: '<S39>/Switch' incorporates:
     *  Constant: '<S32>/Constant3'
     */
    thmd_b_fanRly2Req = thmc_b_fanRly2Dflt;
  } else {
    /* Switch: '<S39>/Switch' incorporates:
     *  Constant: '<S32>/Constant2'
     *  MultiPortSwitch: '<S39>/Index Vector'
     */
    thmd_b_fanRly2Req = THM_FANRLY2[rtb_Saturation1_c];
  }

  /* End of Switch: '<S39>/Switch' */
  /* End of Outputs for SubSystem: '<S32>/state_mapping1' */
  /* End of Outputs for SubSystem: '<S32>/state_mapping' */

  /* Switch: '<S35>/Switch4' incorporates:
   *  Constant: '<S35>/Constant1'
   */
  if (((uint8)1U) != 0) {
    /* Switch: '<S35>/Switch5' incorporates:
     *  Constant: '<S35>/Constant2'
     *  Constant: '<S35>/Constant4'
     *  Constant: '<S35>/Constant5'
     *  RelationalOperator: '<S35>/Relational Operator'
     *  RelationalOperator: '<S35>/Relational Operator1'
     *  RelationalOperator: '<S35>/Relational Operator2'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion140 == ((uint8)0U)) {
      rtb_Relay4_g = (rtb_Switch3_a == ((uint8)50U));
    } else {
      rtb_Relay4_g = (rtb_Switch3_a == ((uint8)100U));
    }

    /* Switch: '<S35>/Switch2' incorporates:
     *  Constant: '<S35>/Constant6'
     *  RelationalOperator: '<S35>/Relational Operator3'
     *  Switch: '<S35>/Switch1'
     *  Switch: '<S35>/Switch5'
     *  Switch: '<S35>/Switch6'
     */
    if (rtb_Relay4_g) {
      /* Switch: '<S35>/Switch4' incorporates:
       *  Constant: '<S58>/Constant'
       *  Switch: '<S35>/Switch2'
       */
      rtb_Switch4_d = FanStatus_HIGH_SPEED;
    } else {
      if (swc_THSM_ARID_DEF.DataTypeConversion140 == ((uint8)1U)) {
        /* Switch: '<S35>/Switch6' incorporates:
         *  Constant: '<S35>/Constant7'
         *  RelationalOperator: '<S35>/Relational Operator4'
         *  Switch: '<S35>/Switch1'
         */
        rtb_Saturation1_c = (uint8)(rtb_Switch3_a == ((uint8)50U));
      } else {
        /* Switch: '<S35>/Switch6' incorporates:
         *  Constant: '<S35>/Constant8'
         *  Switch: '<S35>/Switch1'
         */
        rtb_Saturation1_c = ((uint8)0U);
      }

      /* Switch: '<S35>/Switch3' incorporates:
       *  DataTypeConversion: '<S35>/Data Type Conversion2'
       *  Switch: '<S35>/Switch1'
       *  Switch: '<S35>/Switch6'
       */
      if (rtb_Saturation1_c != 0) {
        /* Switch: '<S35>/Switch4' incorporates:
         *  Constant: '<S53>/Constant'
         *  Switch: '<S35>/Switch1'
         */
        rtb_Switch4_d = FanStatus_LOW_SPEED;
      } else {
        /* Switch: '<S35>/Switch4' incorporates:
         *  Constant: '<S54>/Constant'
         *  Switch: '<S35>/Switch1'
         */
        rtb_Switch4_d = FanStatus_OFF;
      }

      /* End of Switch: '<S35>/Switch3' */
    }

    /* End of Switch: '<S35>/Switch2' */
  } else {
    /* Switch: '<S35>/Switch4' incorporates:
     *  Constant: '<S55>/Constant'
     */
    rtb_Switch4_d = FanStatus_OFF;
  }

  /* End of Switch: '<S35>/Switch4' */

  /* Outputs for Atomic SubSystem: '<S35>/state_mapping' */
  /* Saturate: '<S61>/Saturation1' incorporates:
   *  DataTypeConversion: '<S61>/Data Type Conversion'
   *  Switch: '<S35>/Switch4'
   */
  if (rtb_Switch4_d <= ((uint8)10U)) {
    /* Saturate: '<S61>/Saturation1' */
    rtb_Saturation1_c = rtb_Switch4_d;
  } else {
    /* Saturate: '<S61>/Saturation1' */
    rtb_Saturation1_c = ((uint8)10U);
  }

  /* End of Saturate: '<S61>/Saturation1' */

  /* Switch: '<S61>/Switch' incorporates:
   *  DataTypeConversion: '<S61>/Data Type Conversion'
   *  RelationalOperator: '<S61>/Relational Operator'
   *  Switch: '<S35>/Switch4'
   */
  if (rtb_Switch4_d > rtb_Saturation1_c) {
    /* Switch: '<S61>/Switch' incorporates:
     *  Constant: '<S35>/Constant3'
     */
    thmd_st_FanReqCmd = thmc_st_fanReqStatusDflt;
  } else {
    /* Switch: '<S61>/Switch' incorporates:
     *  Constant: '<S35>/Constant'
     *  MultiPortSwitch: '<S61>/Index Vector'
     */
    thmd_st_FanReqCmd = THM_FANREQSTATUS[rtb_Saturation1_c];
  }

  /* End of Switch: '<S61>/Switch' */
  /* End of Outputs for SubSystem: '<S35>/state_mapping' */

  /* SignalConversion: '<S8>/Signal Conversion' */
  swc_THSM_ARID_DEF.thmd_n_fan1TgtSpd_pct_b = rtb_Switch3_a;

  /* SignalConversion: '<S8>/Signal Conversion1' */
  swc_THSM_ARID_DEF.thmd_n_fan2TgtSpd_pct = rtb_Switch3_a;

  /* Logic: '<S9>/Logical Operator1' incorporates:
   *  Constant: '<S112>/Lower Limit'
   *  Constant: '<S112>/Upper Limit'
   *  Logic: '<S112>/AND'
   *  RelationalOperator: '<S112>/Lower Test'
   *  RelationalOperator: '<S112>/Upper Test'
   */
  rtb_LogicalOperator2_f = ((thmc_v_hvbInFltThrDw >
    swc_THSM_ARID_DEF.DataTypeConversion144) ||
    (swc_THSM_ARID_DEF.DataTypeConversion144 > thmc_v_hvbInFltThrUp));

  /* Logic: '<S9>/Logical Operator2' incorporates:
   *  Constant: '<S113>/Lower Limit'
   *  Constant: '<S113>/Upper Limit'
   *  Logic: '<S113>/AND'
   *  RelationalOperator: '<S113>/Lower Test'
   *  RelationalOperator: '<S113>/Upper Test'
   */
  rtb_Relay4_g = ((thmc_v_hvbOutFltThrDw >
                   swc_THSM_ARID_DEF.DataTypeConversion145) ||
                  (swc_THSM_ARID_DEF.DataTypeConversion145 >
                   thmc_v_hvbOutFltThrUp));

  /* Outputs for Atomic SubSystem: '<S9>/debounce1' */
  /* Chart: '<S116>/timed_debounce' incorporates:
   *  Constant: '<S9>/Constant3'
   *  DataTypeConversion: '<S116>/Data Type Conversion'
   */
  if (swc_THSM_ARID_DEF.is_active_c15_swc_THSM == 0U) {
    swc_THSM_ARID_DEF.is_active_c15_swc_THSM = 1U;
    if (rtb_LogicalOperator2_f) {
      swc_THSM_ARID_DEF.is_c15_swc_THSM = swc_THSM_IN_ON_e;
      thmd_b_FaultStsHvbIn_flg = true;
    } else {
      swc_THSM_ARID_DEF.is_c15_swc_THSM = swc_THSM_IN_OFF_i;
      thmd_b_FaultStsHvbIn_flg = false;
    }
  } else {
    switch (swc_THSM_ARID_DEF.is_c15_swc_THSM) {
     case swc_THSM_IN_OFF_i:
      if (rtb_LogicalOperator2_f) {
        if (rtb_t_delay_off_f == 0.0F) {
          swc_THSM_ARID_DEF.is_c15_swc_THSM = swc_THSM_IN_ON_e;
          thmd_b_FaultStsHvbIn_flg = true;
        } else {
          swc_THSM_ARID_DEF.is_c15_swc_THSM = swc_THSM_IN_ON_WAIT_n;
          swc_THSM_ARID_DEF.t_wait_i = ((float32)THM_TASK_INTERVAL_S);
          thmd_b_FaultStsHvbIn_flg = false;
        }
      } else {
        thmd_b_FaultStsHvbIn_flg = false;
      }
      break;

     case swc_THSM_IN_OFF_WAIT_a:
      if (rtb_LogicalOperator2_f) {
        swc_THSM_ARID_DEF.is_c15_swc_THSM = swc_THSM_IN_ON_e;
        thmd_b_FaultStsHvbIn_flg = true;
      } else if (swc_THSM_ARID_DEF.t_wait_i > rtb_Switch1 - ((float32)
                  THM_TASK_INTERVAL_S)) {
        swc_THSM_ARID_DEF.is_c15_swc_THSM = swc_THSM_IN_OFF_i;
        thmd_b_FaultStsHvbIn_flg = false;
      } else {
        swc_THSM_ARID_DEF.t_wait_i += ((float32)THM_TASK_INTERVAL_S);
        thmd_b_FaultStsHvbIn_flg = true;
      }
      break;

     case swc_THSM_IN_ON_e:
      if (!rtb_LogicalOperator2_f) {
        if (rtb_Switch1 == 0.0F) {
          swc_THSM_ARID_DEF.is_c15_swc_THSM = swc_THSM_IN_OFF_i;
          thmd_b_FaultStsHvbIn_flg = false;
        } else {
          swc_THSM_ARID_DEF.is_c15_swc_THSM = swc_THSM_IN_OFF_WAIT_a;
          swc_THSM_ARID_DEF.t_wait_i = ((float32)THM_TASK_INTERVAL_S);
          thmd_b_FaultStsHvbIn_flg = true;
        }
      } else {
        thmd_b_FaultStsHvbIn_flg = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtb_LogicalOperator2_f) {
        swc_THSM_ARID_DEF.is_c15_swc_THSM = swc_THSM_IN_OFF_i;
        thmd_b_FaultStsHvbIn_flg = false;
      } else if (swc_THSM_ARID_DEF.t_wait_i > rtb_t_delay_off_f - ((float32)
                  THM_TASK_INTERVAL_S)) {
        swc_THSM_ARID_DEF.is_c15_swc_THSM = swc_THSM_IN_ON_e;
        thmd_b_FaultStsHvbIn_flg = true;
      } else {
        swc_THSM_ARID_DEF.t_wait_i += ((float32)THM_TASK_INTERVAL_S);
        thmd_b_FaultStsHvbIn_flg = false;
      }
      break;
    }
  }

  /* End of Chart: '<S116>/timed_debounce' */
  /* End of Outputs for SubSystem: '<S9>/debounce1' */

  /* Outputs for Atomic SubSystem: '<S9>/debounce2' */
  /* Chart: '<S117>/timed_debounce' incorporates:
   *  Constant: '<S9>/Constant6'
   *  DataTypeConversion: '<S117>/Data Type Conversion'
   */
  if (swc_THSM_ARID_DEF.is_active_c16_swc_THSM == 0U) {
    swc_THSM_ARID_DEF.is_active_c16_swc_THSM = 1U;
    if (rtb_Relay4_g) {
      swc_THSM_ARID_DEF.is_c16_swc_THSM = swc_THSM_IN_ON_e;
      thmd_b_FaultStsHvbOut_flg = true;
    } else {
      swc_THSM_ARID_DEF.is_c16_swc_THSM = swc_THSM_IN_OFF_i;
      thmd_b_FaultStsHvbOut_flg = false;
    }
  } else {
    switch (swc_THSM_ARID_DEF.is_c16_swc_THSM) {
     case swc_THSM_IN_OFF_i:
      if (rtb_Relay4_g) {
        if (rtb_t_delay_off_f == 0.0F) {
          swc_THSM_ARID_DEF.is_c16_swc_THSM = swc_THSM_IN_ON_e;
          thmd_b_FaultStsHvbOut_flg = true;
        } else {
          swc_THSM_ARID_DEF.is_c16_swc_THSM = swc_THSM_IN_ON_WAIT_n;
          swc_THSM_ARID_DEF.t_wait_g = ((float32)THM_TASK_INTERVAL_S);
          thmd_b_FaultStsHvbOut_flg = false;
        }
      } else {
        thmd_b_FaultStsHvbOut_flg = false;
      }
      break;

     case swc_THSM_IN_OFF_WAIT_a:
      if (rtb_Relay4_g) {
        swc_THSM_ARID_DEF.is_c16_swc_THSM = swc_THSM_IN_ON_e;
        thmd_b_FaultStsHvbOut_flg = true;
      } else if (swc_THSM_ARID_DEF.t_wait_g > rtb_Switch1 - ((float32)
                  THM_TASK_INTERVAL_S)) {
        swc_THSM_ARID_DEF.is_c16_swc_THSM = swc_THSM_IN_OFF_i;
        thmd_b_FaultStsHvbOut_flg = false;
      } else {
        swc_THSM_ARID_DEF.t_wait_g += ((float32)THM_TASK_INTERVAL_S);
        thmd_b_FaultStsHvbOut_flg = true;
      }
      break;

     case swc_THSM_IN_ON_e:
      if (!rtb_Relay4_g) {
        if (rtb_Switch1 == 0.0F) {
          swc_THSM_ARID_DEF.is_c16_swc_THSM = swc_THSM_IN_OFF_i;
          thmd_b_FaultStsHvbOut_flg = false;
        } else {
          swc_THSM_ARID_DEF.is_c16_swc_THSM = swc_THSM_IN_OFF_WAIT_a;
          swc_THSM_ARID_DEF.t_wait_g = ((float32)THM_TASK_INTERVAL_S);
          thmd_b_FaultStsHvbOut_flg = true;
        }
      } else {
        thmd_b_FaultStsHvbOut_flg = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtb_Relay4_g) {
        swc_THSM_ARID_DEF.is_c16_swc_THSM = swc_THSM_IN_OFF_i;
        thmd_b_FaultStsHvbOut_flg = false;
      } else if (swc_THSM_ARID_DEF.t_wait_g > rtb_t_delay_off_f - ((float32)
                  THM_TASK_INTERVAL_S)) {
        swc_THSM_ARID_DEF.is_c16_swc_THSM = swc_THSM_IN_ON_e;
        thmd_b_FaultStsHvbOut_flg = true;
      } else {
        swc_THSM_ARID_DEF.t_wait_g += ((float32)THM_TASK_INTERVAL_S);
        thmd_b_FaultStsHvbOut_flg = false;
      }
      break;
    }
  }

  /* End of Chart: '<S117>/timed_debounce' */
  /* End of Outputs for SubSystem: '<S9>/debounce2' */

  /* Logic: '<S9>/Logical Operator6' incorporates:
   *  Constant: '<S114>/Lower Limit'
   *  Constant: '<S114>/Upper Limit'
   *  Logic: '<S114>/AND'
   *  RelationalOperator: '<S114>/Lower Test'
   *  RelationalOperator: '<S114>/Upper Test'
   */
  rtb_LogicalOperator2_f = ((thmc_t_ewpOutFltThrDw >
    swc_THSM_ARID_DEF.DataTypeConversion3) ||
    (swc_THSM_ARID_DEF.DataTypeConversion3 > thmc_t_ewpOutFltThrUp));

  /* Outputs for Atomic SubSystem: '<S9>/debounce3' */
  /* Chart: '<S118>/timed_debounce' incorporates:
   *  Constant: '<S9>/Constant10'
   *  DataTypeConversion: '<S118>/Data Type Conversion'
   */
  if (swc_THSM_ARID_DEF.is_active_c17_swc_THSM == 0U) {
    swc_THSM_ARID_DEF.is_active_c17_swc_THSM = 1U;
    if (rtb_LogicalOperator2_f) {
      swc_THSM_ARID_DEF.is_c17_swc_THSM = swc_THSM_IN_ON_e;
      thmd_b_ewpOutTempFaultFlg = true;
    } else {
      swc_THSM_ARID_DEF.is_c17_swc_THSM = swc_THSM_IN_OFF_i;
      thmd_b_ewpOutTempFaultFlg = false;
    }
  } else {
    switch (swc_THSM_ARID_DEF.is_c17_swc_THSM) {
     case swc_THSM_IN_OFF_i:
      if (rtb_LogicalOperator2_f) {
        if (rtb_t_delay_off_f == 0.0F) {
          swc_THSM_ARID_DEF.is_c17_swc_THSM = swc_THSM_IN_ON_e;
          thmd_b_ewpOutTempFaultFlg = true;
        } else {
          swc_THSM_ARID_DEF.is_c17_swc_THSM = swc_THSM_IN_ON_WAIT_n;
          swc_THSM_ARID_DEF.t_wait_n = ((float32)THM_TASK_INTERVAL_S);
          thmd_b_ewpOutTempFaultFlg = false;
        }
      } else {
        thmd_b_ewpOutTempFaultFlg = false;
      }
      break;

     case swc_THSM_IN_OFF_WAIT_a:
      if (rtb_LogicalOperator2_f) {
        swc_THSM_ARID_DEF.is_c17_swc_THSM = swc_THSM_IN_ON_e;
        thmd_b_ewpOutTempFaultFlg = true;
      } else if (swc_THSM_ARID_DEF.t_wait_n > rtb_Switch1 - ((float32)
                  THM_TASK_INTERVAL_S)) {
        swc_THSM_ARID_DEF.is_c17_swc_THSM = swc_THSM_IN_OFF_i;
        thmd_b_ewpOutTempFaultFlg = false;
      } else {
        swc_THSM_ARID_DEF.t_wait_n += ((float32)THM_TASK_INTERVAL_S);
        thmd_b_ewpOutTempFaultFlg = true;
      }
      break;

     case swc_THSM_IN_ON_e:
      if (!rtb_LogicalOperator2_f) {
        if (rtb_Switch1 == 0.0F) {
          swc_THSM_ARID_DEF.is_c17_swc_THSM = swc_THSM_IN_OFF_i;
          thmd_b_ewpOutTempFaultFlg = false;
        } else {
          swc_THSM_ARID_DEF.is_c17_swc_THSM = swc_THSM_IN_OFF_WAIT_a;
          swc_THSM_ARID_DEF.t_wait_n = ((float32)THM_TASK_INTERVAL_S);
          thmd_b_ewpOutTempFaultFlg = true;
        }
      } else {
        thmd_b_ewpOutTempFaultFlg = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtb_LogicalOperator2_f) {
        swc_THSM_ARID_DEF.is_c17_swc_THSM = swc_THSM_IN_OFF_i;
        thmd_b_ewpOutTempFaultFlg = false;
      } else if (swc_THSM_ARID_DEF.t_wait_n > rtb_t_delay_off_f - ((float32)
                  THM_TASK_INTERVAL_S)) {
        swc_THSM_ARID_DEF.is_c17_swc_THSM = swc_THSM_IN_ON_e;
        thmd_b_ewpOutTempFaultFlg = true;
      } else {
        swc_THSM_ARID_DEF.t_wait_n += ((float32)THM_TASK_INTERVAL_S);
        thmd_b_ewpOutTempFaultFlg = false;
      }
      break;
    }
  }

  /* End of Chart: '<S118>/timed_debounce' */
  /* End of Outputs for SubSystem: '<S9>/debounce3' */

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S110>/Constant'
   *  RelationalOperator: '<S110>/Compare'
   */
  if (swc_THSM_ARID_DEF.DataTypeConversion1 == ((uint8)0U)) {
    /* Switch: '<S9>/Switch' incorporates:
     *  Logic: '<S9>/Logical Operator4'
     */
    thmd_b_FaultSts_flg1 = (thmd_b_FaultStsHvbIn_flg ||
      thmd_b_FaultStsHvbOut_flg);
  } else {
    /* Switch: '<S9>/Switch' */
    thmd_b_FaultSts_flg1 = thmd_b_ewpOutTempFaultFlg;
  }

  /* End of Switch: '<S9>/Switch' */

  /* Relay: '<S9>/Relay' */
  swc_THSM_ARID_DEF.Relay_Mode = ((swc_THSM_ARID_DEF.DataTypeConversion31 >=
    thmc_t_mot2OverTempUp_C) || ((swc_THSM_ARID_DEF.DataTypeConversion31 >
    thmc_t_mot2OverTempDw_C) && swc_THSM_ARID_DEF.Relay_Mode));
  if (swc_THSM_ARID_DEF.Relay_Mode) {
    /* Relay: '<S9>/Relay' */
    rtb_Relay = 1.0F;
  } else {
    /* Relay: '<S9>/Relay' */
    rtb_Relay = 0.0F;
  }

  /* End of Relay: '<S9>/Relay' */

  /* Relay: '<S9>/Relay1' */
  swc_THSM_ARID_DEF.Relay1_Mode_j = ((swc_THSM_ARID_DEF.DataTypeConversion27 >=
    thmc_t_inv2OverTempUp_C) || ((swc_THSM_ARID_DEF.DataTypeConversion27 >
    thmc_t_inv2OverTempDw_C) && swc_THSM_ARID_DEF.Relay1_Mode_j));
  if (swc_THSM_ARID_DEF.Relay1_Mode_j) {
    /* Relay: '<S9>/Relay1' */
    rtb_Relay1 = 1.0F;
  } else {
    /* Relay: '<S9>/Relay1' */
    rtb_Relay1 = 0.0F;
  }

  /* End of Relay: '<S9>/Relay1' */

  /* Relay: '<S9>/Relay2' */
  swc_THSM_ARID_DEF.Relay2_Mode_g = ((swc_THSM_ARID_DEF.DataTypeConversion11 >=
    thmc_t_dcdcOverTempUp_C) || ((swc_THSM_ARID_DEF.DataTypeConversion11 >
    thmc_t_dcdcOverTempDw_C) && swc_THSM_ARID_DEF.Relay2_Mode_g));
  if (swc_THSM_ARID_DEF.Relay2_Mode_g) {
    /* Relay: '<S9>/Relay2' */
    rtb_Relay2 = 1.0F;
  } else {
    /* Relay: '<S9>/Relay2' */
    rtb_Relay2 = 0.0F;
  }

  /* End of Relay: '<S9>/Relay2' */

  /* Relay: '<S9>/Relay3' */
  swc_THSM_ARID_DEF.Relay3_Mode_o = ((swc_THSM_ARID_DEF.DataTypeConversion33 >=
    thmc_t_ts5OverTempUp_C) || ((swc_THSM_ARID_DEF.DataTypeConversion33 >
    thmc_t_ts5OverTempDw_C) && swc_THSM_ARID_DEF.Relay3_Mode_o));

  /* Relay: '<S9>/Relay4' */
  swc_THSM_ARID_DEF.Relay4_Mode_o = ((swc_THSM_ARID_DEF.DataTypeConversion33 >=
    thmc_t_ts5LowTempUp_C) || ((swc_THSM_ARID_DEF.DataTypeConversion33 >
    thmc_t_ts5LowTempDw_C) && swc_THSM_ARID_DEF.Relay4_Mode_o));

  /* Relay: '<S9>/Relay3' */
  if (swc_THSM_ARID_DEF.Relay3_Mode_o) {
    rtb_Switch3_ig = 1.0F;
  } else {
    rtb_Switch3_ig = 0.0F;
  }

  /* Relay: '<S9>/Relay4' */
  if (swc_THSM_ARID_DEF.Relay4_Mode_o) {
    rtb_t_delay_off_f = 1.0F;
  } else {
    rtb_t_delay_off_f = 0.0F;
  }

  /* Logic: '<S9>/Logical Operator3' incorporates:
   *  Relay: '<S9>/Relay3'
   *  Relay: '<S9>/Relay4'
   */
  rtb_LogicalOperator3_d = ((rtb_Switch3_ig != 0.0F) || (rtb_t_delay_off_f !=
    0.0F));

  /* RelationalOperator: '<S10>/Relational Operator12' incorporates:
   *  Constant: '<S10>/Constant12'
   */
  rtb_RelationalOperator12 = (swc_THSM_ARID_DEF.DataTypeConversion1 == ((uint8)
    0U));

  /* Logic: '<S10>/Logical Operator10' incorporates:
   *  Constant: '<S10>/Cbn_Heat2'
   *  Constant: '<S10>/Cbn_Heat6'
   *  Logic: '<S10>/Logical Operator'
   *  Logic: '<S10>/Logical Operator12'
   *  Logic: '<S10>/Logical Operator13'
   *  RelationalOperator: '<S10>/Relational Operator15'
   *  RelationalOperator: '<S10>/Relational Operator7'
   */
  thmd_b_iptcEnbCmd2 = (((swc_THSM_ARID_DEF.DataTypeConversion147 == ((uint8)1U))
    && rtb_RelationalOperator12) || ((!rtb_RelationalOperator12) &&
    (swc_THSM_ARID_DEF.DataTypeConversion34 == ((uint8)1U))));

  /* Logic: '<S10>/Logical Operator11' incorporates:
   *  Constant: '<S16>/Constant'
   *  Constant: '<S17>/Constant'
   *  Logic: '<S10>/Logical Operator9'
   *  RelationalOperator: '<S10>/Relational Operator8'
   *  RelationalOperator: '<S10>/Relational Operator9'
   *  RelationalOperator: '<S3>/Relational Operator'
   *  RelationalOperator: '<S3>/Relational Operator11'
   */
  thmd_b_ptc2EnterEnableFlg = ((swc_THSM_ARID_DEF.DataTypeConversion22 ||
    (thmd_b_accmEnbChrflg_tmp == PmmStatus_DRIVE) || (thmd_b_accmEnbChrflg_tmp ==
    PmmStatus_CHARGE)) && thmd_b_iptcEnbCmd2 && thmd_b_accmEnaCnd3);

  /* Logic: '<S10>/Logical Operator16' incorporates:
   *  Constant: '<S17>/Constant'
   *  Logic: '<S10>/Logical Operator14'
   *  Logic: '<S10>/Logical Operator18'
   *  RelationalOperator: '<S10>/Relational Operator10'
   *  RelationalOperator: '<S3>/Relational Operator11'
   */
  thmd_b_ptc2ExitEnableFlg = (thmd_b_accmExitEnableFlg_tmp ||
    (!thmd_b_iptcEnbCmd2) || (thmd_b_accmEnboffChrflg_tmp &&
    (thmd_b_accmEnbChrflg_tmp != PmmStatus_CHARGE)));

  /* SignalConversion: '<S10>/Signal Conversion1' incorporates:
   *  Constant: '<S10>/Cbn_Heat3'
   *  RelationalOperator: '<S10>/Relational Operator16'
   */
  rtb_SignalConversion1 = (swc_THSM_ARID_DEF.DataTypeConversion148 == ((uint8)1U));

  /* Logic: '<S10>/Logical Operator19' incorporates:
   *  Constant: '<S16>/Constant'
   *  Constant: '<S17>/Constant'
   *  Logic: '<S10>/Logical Operator27'
   *  RelationalOperator: '<S10>/Relational Operator13'
   *  RelationalOperator: '<S10>/Relational Operator14'
   *  RelationalOperator: '<S3>/Relational Operator'
   *  RelationalOperator: '<S3>/Relational Operator11'
   */
  thmd_b_ptc3EnterEnableFlg = ((swc_THSM_ARID_DEF.DataTypeConversion22 ||
    (thmd_b_accmEnbChrflg_tmp == PmmStatus_DRIVE) || (thmd_b_accmEnbChrflg_tmp ==
    PmmStatus_CHARGE)) && rtb_SignalConversion1 && thmd_b_accmEnaCnd3 &&
    swc_THSM_ARID_DEF.DataTypeConversion143);

  /* Logic: '<S10>/Logical Operator2' incorporates:
   *  Constant: '<S16>/Constant'
   *  Constant: '<S17>/Constant'
   *  RelationalOperator: '<S10>/Relational Operator2'
   *  RelationalOperator: '<S10>/Relational Operator3'
   *  RelationalOperator: '<S3>/Relational Operator'
   *  RelationalOperator: '<S3>/Relational Operator11'
   */
  thmd_b_heaterEnaCnd1 = (swc_THSM_ARID_DEF.DataTypeConversion22 ||
    (thmd_b_accmEnbChrflg_tmp == PmmStatus_DRIVE) || (thmd_b_accmEnbChrflg_tmp ==
    PmmStatus_CHARGE));

  /* Logic: '<S10>/Logical Operator24' incorporates:
   *  Constant: '<S17>/Constant'
   *  Logic: '<S10>/Logical Operator20'
   *  Logic: '<S10>/Logical Operator22'
   *  Logic: '<S10>/Logical Operator26'
   *  RelationalOperator: '<S10>/Relational Operator11'
   *  RelationalOperator: '<S3>/Relational Operator11'
   */
  thmd_b_ptc3ExitEnableFlg = (thmd_b_accmExitEnableFlg_tmp ||
    (!rtb_SignalConversion1) || (thmd_b_accmEnboffChrflg_tmp &&
    (thmd_b_accmEnbChrflg_tmp != PmmStatus_CHARGE)) ||
    (!swc_THSM_ARID_DEF.DataTypeConversion143));

  /* RelationalOperator: '<S10>/Relational Operator5' incorporates:
   *  Constant: '<S10>/Cbn_Heat1'
   */
  thmd_b_heaterEnaCnd2 = (swc_THSM_ARID_DEF.DataTypeConversion146 == ((uint8)1U));

  /* Logic: '<S10>/Logical Operator3' */
  thmd_b_ptcEnterEnableFlg = (thmd_b_heaterEnaCnd1 && thmd_b_heaterEnaCnd2 &&
    thmd_b_accmEnaCnd3 && swc_THSM_ARID_DEF.DataTypeConversion138);

  /* Logic: '<S10>/Logical Operator6' incorporates:
   *  Constant: '<S17>/Constant'
   *  Logic: '<S10>/Logical Operator1'
   *  Logic: '<S10>/Logical Operator4'
   *  Logic: '<S10>/Logical Operator8'
   *  RelationalOperator: '<S10>/Relational Operator4'
   *  RelationalOperator: '<S3>/Relational Operator11'
   */
  thmd_b_ptcExitEnableFlg = (thmd_b_accmExitEnableFlg_tmp ||
    (!thmd_b_heaterEnaCnd2) || (thmd_b_accmEnboffChrflg_tmp &&
    (thmd_b_accmEnbChrflg_tmp != PmmStatus_CHARGE)) ||
    (!swc_THSM_ARID_DEF.DataTypeConversion138));

  /* Outputs for Atomic SubSystem: '<S10>/SR_latch1' */
  swc_THSM_SR_latch1(thmd_b_ptcEnterEnableFlg, thmd_b_ptcExitEnableFlg,
                     &rtb_LogicalOperator3_i,
                     &swc_THSM_ARID_DEF.ARID_DEF_SR_latch1);

  /* End of Outputs for SubSystem: '<S10>/SR_latch1' */

  /* Outputs for Atomic SubSystem: '<S10>/SR_latch2' */
  swc_THSM_SR_latch2(thmd_b_ptc2EnterEnableFlg, thmd_b_ptc2ExitEnableFlg,
                     &swc_THSM_ARID_DEF.ARID_DEF_SR_latch2);

  /* End of Outputs for SubSystem: '<S10>/SR_latch2' */

  /* Outputs for Atomic SubSystem: '<S10>/SR_latch3' */
  swc_THSM_SR_latch3(thmd_b_ptc3EnterEnableFlg, thmd_b_ptc3ExitEnableFlg,
                     &rtb_LogicalOperator3_p,
                     &swc_THSM_ARID_DEF.ARID_DEF_SR_latch3);

  /* End of Outputs for SubSystem: '<S10>/SR_latch3' */

  /* Switch: '<S10>/Switch' incorporates:
   *  SignalConversion: '<S10>/Signal Conversion1'
   *  Switch: '<S10>/Switch1'
   */
  if (thmd_b_heaterEna2) {
    /* Switch: '<S10>/Switch' */
    thmd_t_acwpTemp_C = swc_THSM_ARID_DEF.DataTypeConversion2;

    /* Switch: '<S10>/Switch1' incorporates:
     *  Constant: '<S10>/Constant9'
     */
    thmd_st_acwpHeat = ((uint8)1U);
  } else {
    /* Switch: '<S10>/Switch' incorporates:
     *  Constant: '<S10>/Constant'
     */
    thmd_t_acwpTemp_C = thmc_t_acewpDisTemp_C;

    /* Switch: '<S10>/Switch1' incorporates:
     *  Constant: '<S10>/Constant10'
     */
    thmd_st_acwpHeat = ((uint8)2U);
  }

  /* End of Switch: '<S10>/Switch' */

  /* SignalConversion generated from: '<S10>/SR_latch3' */
  thmd_b_heaterEna3 = rtb_LogicalOperator3_p;

  /* Switch: '<S10>/Switch2' */
  if (rtb_RelationalOperator12) {
    /* Switch: '<S10>/Switch2' */
    rtb_LogicalOperator2_f = thmd_b_heaterEna3;
  } else {
    /* Switch: '<S10>/Switch2' incorporates:
     *  Constant: '<S10>/Constant11'
     */
    rtb_LogicalOperator2_f = false;
  }

  /* End of Switch: '<S10>/Switch2' */

  /* SignalConversion generated from: '<S10>/SR_latch1' */
  thmd_b_ptcEna = rtb_LogicalOperator3_i;

  /* Outputs for Atomic SubSystem: '<S10>/turnOFF_delay' */
  /* Saturate: '<S135>/Saturation1' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  if (thmc_tm_ptcDlyHw_s > 1.6777216E+7F) {
    /* Saturate: '<S135>/Saturation1' */
    rtb_t_delay_off_f = 1.6777216E+7F;
  } else if (thmc_tm_ptcDlyHw_s < 0.0F) {
    /* Saturate: '<S135>/Saturation1' */
    rtb_t_delay_off_f = 0.0F;
  } else {
    /* Saturate: '<S135>/Saturation1' */
    rtb_t_delay_off_f = thmc_tm_ptcDlyHw_s;
  }

  /* End of Saturate: '<S135>/Saturation1' */

  /* Chart: '<S135>/timed_delay' incorporates:
   *  Constant: '<S10>/Constant3'
   *  DataTypeConversion: '<S135>/Data Type Conversion'
   */
  if (swc_THSM_ARID_DEF.is_active_c18_swc_THSM == 0U) {
    swc_THSM_ARID_DEF.is_active_c18_swc_THSM = 1U;
    if (thmd_b_ptcEna) {
      swc_THSM_ARID_DEF.is_c18_swc_THSM = swc_THSM_IN_ON_e;
      thmd_b_ptcHWEnbFlg = true;
    } else {
      swc_THSM_ARID_DEF.is_c18_swc_THSM = swc_THSM_IN_OFF_i;
      thmd_b_ptcHWEnbFlg = false;
    }
  } else {
    switch (swc_THSM_ARID_DEF.is_c18_swc_THSM) {
     case swc_THSM_IN_OFF_i:
      if (thmd_b_ptcEna) {
        swc_THSM_ARID_DEF.is_c18_swc_THSM = swc_THSM_IN_ON_e;
        thmd_b_ptcHWEnbFlg = true;
      } else {
        thmd_b_ptcHWEnbFlg = false;
      }
      break;

     case swc_THSM_IN_OFF_WAIT_a:
      if (thmd_b_ptcEna) {
        swc_THSM_ARID_DEF.is_c18_swc_THSM = swc_THSM_IN_ON_e;
        thmd_b_ptcHWEnbFlg = true;
      } else if (swc_THSM_ARID_DEF.t_wait_b > rtb_t_delay_off_f - ((float32)
                  THM_TASK_INTERVAL_S)) {
        swc_THSM_ARID_DEF.is_c18_swc_THSM = swc_THSM_IN_OFF_i;
        thmd_b_ptcHWEnbFlg = false;
      } else {
        swc_THSM_ARID_DEF.t_wait_b += ((float32)THM_TASK_INTERVAL_S);
        thmd_b_ptcHWEnbFlg = true;
      }
      break;

     default:
      /* case IN_ON: */
      if (!thmd_b_ptcEna) {
        if (rtb_t_delay_off_f == 0.0F) {
          swc_THSM_ARID_DEF.is_c18_swc_THSM = swc_THSM_IN_OFF_i;
          thmd_b_ptcHWEnbFlg = false;
        } else {
          swc_THSM_ARID_DEF.is_c18_swc_THSM = swc_THSM_IN_OFF_WAIT_a;
          swc_THSM_ARID_DEF.t_wait_b = ((float32)THM_TASK_INTERVAL_S);
          thmd_b_ptcHWEnbFlg = true;
        }
      } else {
        thmd_b_ptcHWEnbFlg = true;
      }
      break;
    }
  }

  /* End of Chart: '<S135>/timed_delay' */
  /* End of Outputs for SubSystem: '<S10>/turnOFF_delay' */

  /* Outputs for Atomic SubSystem: '<S10>/turnOFF_delay1' */
  /* DataTypeConversion: '<S136>/Data Type Conversion' */
  rtb_DataTypeConversion_h = rtb_LogicalOperator2_f;

  /* Saturate: '<S136>/Saturation1' incorporates:
   *  Constant: '<S10>/Constant8'
   */
  if (thmc_tm_ptc3DlyHw_s > 1.6777216E+7F) {
    /* Saturate: '<S136>/Saturation1' */
    rtb_t_delay_off = 1.6777216E+7F;
  } else if (thmc_tm_ptc3DlyHw_s < 0.0F) {
    /* Saturate: '<S136>/Saturation1' */
    rtb_t_delay_off = 0.0F;
  } else {
    /* Saturate: '<S136>/Saturation1' */
    rtb_t_delay_off = thmc_tm_ptc3DlyHw_s;
  }

  /* End of Saturate: '<S136>/Saturation1' */

  /* Chart: '<S136>/timed_delay' incorporates:
   *  Constant: '<S10>/Constant7'
   */
  swc_THSM_timed_delay(rtb_DataTypeConversion_h, rtb_t_delay_off, ((float32)
    THM_TASK_INTERVAL_S), &swc_THSM_ARID_DEF.flg_out_j,
                       &swc_THSM_ARID_DEF.ARID_DEF_timed_delay_c);

  /* End of Outputs for SubSystem: '<S10>/turnOFF_delay1' */

  /* Outputs for Atomic SubSystem: '<S10>/turnON_delay' */
  /* Saturate: '<S137>/Saturation' incorporates:
   *  Constant: '<S10>/Constant4'
   */
  if (thmc_tm_ptcDlyCan_s > 1.6777216E+7F) {
    /* Saturate: '<S137>/Saturation' */
    rtb_t_delay_off_f = 1.6777216E+7F;
  } else if (thmc_tm_ptcDlyCan_s < 0.0F) {
    /* Saturate: '<S137>/Saturation' */
    rtb_t_delay_off_f = 0.0F;
  } else {
    /* Saturate: '<S137>/Saturation' */
    rtb_t_delay_off_f = thmc_tm_ptcDlyCan_s;
  }

  /* End of Saturate: '<S137>/Saturation' */

  /* Chart: '<S137>/timed_delay' incorporates:
   *  Constant: '<S10>/Constant2'
   *  DataTypeConversion: '<S137>/Data Type Conversion'
   */
  if (swc_THSM_ARID_DEF.is_active_c20_swc_THSM == 0U) {
    swc_THSM_ARID_DEF.is_active_c20_swc_THSM = 1U;
    if (thmd_b_ptcEna) {
      swc_THSM_ARID_DEF.is_c20_swc_THSM = swc_THSM_IN_ON_hp;
      thmd_b_ptcCanEnbFlg = true;
    } else {
      swc_THSM_ARID_DEF.is_c20_swc_THSM = swc_THSM_IN_OFF_i;
      thmd_b_ptcCanEnbFlg = false;
    }
  } else {
    switch (swc_THSM_ARID_DEF.is_c20_swc_THSM) {
     case swc_THSM_IN_OFF_i:
      if (thmd_b_ptcEna) {
        if (rtb_t_delay_off_f == 0.0F) {
          swc_THSM_ARID_DEF.is_c20_swc_THSM = swc_THSM_IN_ON_hp;
          thmd_b_ptcCanEnbFlg = true;
        } else {
          swc_THSM_ARID_DEF.is_c20_swc_THSM = swc_THSM_IN_ON_WAIT_d;
          swc_THSM_ARID_DEF.t_wait = ((float32)THM_TASK_INTERVAL_S);
          thmd_b_ptcCanEnbFlg = false;
        }
      } else {
        thmd_b_ptcCanEnbFlg = false;
      }
      break;

     case swc_THSM_IN_ON_hp:
      if (!thmd_b_ptcEna) {
        swc_THSM_ARID_DEF.is_c20_swc_THSM = swc_THSM_IN_OFF_i;
        thmd_b_ptcCanEnbFlg = false;
      } else {
        thmd_b_ptcCanEnbFlg = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!thmd_b_ptcEna) {
        swc_THSM_ARID_DEF.is_c20_swc_THSM = swc_THSM_IN_OFF_i;
        thmd_b_ptcCanEnbFlg = false;
      } else if (swc_THSM_ARID_DEF.t_wait > rtb_t_delay_off_f - ((float32)
                  THM_TASK_INTERVAL_S)) {
        swc_THSM_ARID_DEF.is_c20_swc_THSM = swc_THSM_IN_ON_hp;
        thmd_b_ptcCanEnbFlg = true;
      } else {
        swc_THSM_ARID_DEF.t_wait += ((float32)THM_TASK_INTERVAL_S);
        thmd_b_ptcCanEnbFlg = false;
      }
      break;
    }
  }

  /* End of Chart: '<S137>/timed_delay' */
  /* End of Outputs for SubSystem: '<S10>/turnON_delay' */

  /* Outputs for Atomic SubSystem: '<S10>/turnON_delay1' */
  /* DataTypeConversion: '<S138>/Data Type Conversion' */
  rtb_DataTypeConversion_jd = rtb_LogicalOperator2_f;

  /* Saturate: '<S138>/Saturation' incorporates:
   *  Constant: '<S10>/Constant6'
   */
  if (thmc_tm_ptc3DlyCan_s > 1.6777216E+7F) {
    /* Saturate: '<S138>/Saturation' */
    rtb_t_delay_on = 1.6777216E+7F;
  } else if (thmc_tm_ptc3DlyCan_s < 0.0F) {
    /* Saturate: '<S138>/Saturation' */
    rtb_t_delay_on = 0.0F;
  } else {
    /* Saturate: '<S138>/Saturation' */
    rtb_t_delay_on = thmc_tm_ptc3DlyCan_s;
  }

  /* End of Saturate: '<S138>/Saturation' */

  /* Chart: '<S138>/timed_delay' incorporates:
   *  Constant: '<S10>/Constant5'
   */
  swc_THSM_timed_delay_c(rtb_DataTypeConversion_jd, rtb_t_delay_on, ((float32)
    THM_TASK_INTERVAL_S), &swc_THSM_ARID_DEF.flg_out,
    &swc_THSM_ARID_DEF.ARID_DEF_timed_delay);

  /* End of Outputs for SubSystem: '<S10>/turnON_delay1' */

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion62'
   */
  rtb_Saturation1_c = swc_THSM_ARID_DEF.DataTypeConversion62;

  /* Chart: '<S11>/Chart' incorporates:
   *  Constant: '<S146>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion118'
   *  RelationalOperator: '<S11>/Relational Operator6'
   *  RelationalOperator: '<S144>/FixPt Relational Operator'
   *  UnitDelay: '<S144>/Delay Input1'
   *
   * Block description for '<S144>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (swc_THSM_ARID_DEF.is_active_c27_swc_THSM == 0U) {
    swc_THSM_ARID_DEF.is_active_c27_swc_THSM = 1U;
    swc_THSM_ARID_DEF.is_c27_swc_THSM = swc_T_IN_WaterPumpMode_NormWork;
    swc_THSM_ARID_DEF.is_WaterPumpMode_NormWork = swc_THSM_IN_Init;
    swc_THSM_ARID_DEF.flg_WaterPumpMode = false;
  } else if (swc_THSM_ARID_DEF.is_c27_swc_THSM ==
             swc_T_IN_WaterPumpMode_NormWork) {
    switch (swc_THSM_ARID_DEF.is_WaterPumpMode_NormWork) {
     case swc_THSM_IN_AfterIgnOnTimer:
      {
        if ((swc_THSM_ARID_DEF.Counter <= 50U) &&
            (swc_THSM_ARID_DEF.DataTypeConversion118 == BrakePedalStatus_PRESSED)
            && (rtb_Saturation1_c == 0) && (swc_THSM_ConstB.DataTypeConversion1 ==
             1.0)) {
          swc_THSM_ARID_DEF.is_WaterPumpMode_NormWork =
            swc_THS_IN_BrakePedalStateTimer;
          swc_THSM_ARID_DEF.Counter = 0U;
        } else if (swc_THSM_ARID_DEF.Counter > 50U) {
          swc_THSM_ARID_DEF.Counter = 0U;
          swc_THSM_ARID_DEF.is_WaterPumpMode_NormWork = swc_THSM_IN_Init;
          swc_THSM_ARID_DEF.flg_WaterPumpMode = false;
        } else {
          uint32 qY;
          qY = swc_THSM_ARID_DEF.Counter + /*MW:OvSatOk*/ 1U;
          if (swc_THSM_ARID_DEF.Counter + 1U < swc_THSM_ARID_DEF.Counter) {
            qY = MAX_uint32_T;
          }

          swc_THSM_ARID_DEF.Counter = qY;
        }
      }
      break;

     case swc_THS_IN_BrakePedalStateTimer:
      {
        if ((swc_THSM_ARID_DEF.DataTypeConversion118 != BrakePedalStatus_PRESSED)
            || thmd_b_accmEnboffChrflg_tmp || (rtb_Saturation1_c != 0) ||
            (swc_THSM_ConstB.DataTypeConversion1 != 1.0)) {
          swc_THSM_ARID_DEF.Counter = 0U;
          swc_THSM_ARID_DEF.is_WaterPumpMode_NormWork = swc_THSM_IN_Init;
          swc_THSM_ARID_DEF.flg_WaterPumpMode = false;
        } else if ((swc_THSM_ARID_DEF.Counter > 99U) &&
                   (swc_THSM_ConstB.DataTypeConversion1 == 1.0)) {
          swc_THSM_ARID_DEF.is_WaterPumpMode_NormWork =
            swc_THSM_IN_NO_ACTIVE_CHILD_c;
          swc_THSM_ARID_DEF.is_c27_swc_THSM = swc_IN_WaterPumpMode_VacuumFill;
          swc_THSM_ARID_DEF.flg_WaterPumpMode = true;
          swc_THSM_ARID_DEF.Counter = 0U;
        } else {
          uint32 qY;
          qY = swc_THSM_ARID_DEF.Counter + /*MW:OvSatOk*/ 1U;
          if (swc_THSM_ARID_DEF.Counter + 1U < swc_THSM_ARID_DEF.Counter) {
            qY = MAX_uint32_T;
          }

          swc_THSM_ARID_DEF.Counter = qY;
        }
      }
      break;

     default:
      /* case IN_Init: */
      if ((sint32)swc_THSM_ARID_DEF.DataTypeConversion22 > (sint32)
          swc_THSM_ARID_DEF.DelayInput1_DSTATE_i) {
        swc_THSM_ARID_DEF.is_WaterPumpMode_NormWork =
          swc_THSM_IN_AfterIgnOnTimer;
        swc_THSM_ARID_DEF.Counter = 0U;
      }
      break;
    }

    /* case IN_WaterPumpMode_VacuumFill: */
  } else if ((swc_THSM_ARID_DEF.Counter > 1800U) || (rtb_Saturation1_c != 0) ||
             thmd_b_accmEnboffChrflg_tmp || (swc_THSM_ConstB.DataTypeConversion1
              != 1.0)) {
    swc_THSM_ARID_DEF.Counter = 0U;
    swc_THSM_ARID_DEF.is_c27_swc_THSM = swc_T_IN_WaterPumpMode_NormWork;
    swc_THSM_ARID_DEF.is_WaterPumpMode_NormWork = swc_THSM_IN_Init;
    swc_THSM_ARID_DEF.flg_WaterPumpMode = false;
  } else {
    uint32 qY;
    qY = swc_THSM_ARID_DEF.Counter + /*MW:OvSatOk*/ 1U;
    if (swc_THSM_ARID_DEF.Counter + 1U < swc_THSM_ARID_DEF.Counter) {
      qY = MAX_uint32_T;
    }

    swc_THSM_ARID_DEF.Counter = qY;
  }

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Constant'
   */
  if (thmc_b_nonFillingFlg) {
    /* Switch: '<S11>/Switch' */
    thmd_b_NonVacFilling_flg = swc_THSM_ARID_DEF.flg_WaterPumpMode;
  } else {
    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<S11>/Constant1'
     */
    thmd_b_NonVacFilling_flg = false;
  }

  /* End of Switch: '<S11>/Switch' */

  /* RelationalOperator: '<S11>/Relational Operator3' incorporates:
   *  Constant: '<S16>/Constant'
   *  RelationalOperator: '<S3>/Relational Operator'
   */
  rtb_RelationalOperator3_b = (thmd_b_accmEnbChrflg_tmp != PmmStatus_DRIVE);

  /* SignalConversion generated from: '<S2>/thmd_b_PassCool_flg' */
  swc_THSM_ARID_DEF.OutportBufferForthmd_b_PassCool = 0.0;

  /* SignalConversion generated from: '<S2>/thmd_n_wtrPmp2TgtSpd_rpm' */
  swc_THSM_ARID_DEF.OutportBufferForthmd_n_wtrPmp2T = 0.0;

  /* SignalConversion generated from: '<S2>/thmd_q_pmp2FlowFeedback' */
  swc_THSM_ARID_DEF.OutportBufferForthmd_q_pmp2Flow = 0.0;

  /* SignalConversion generated from: '<S2>/thmd_st_ptcRlyVoltSamSwitch' */
  swc_THSM_ARID_DEF.OutportBufferForthmd_st_ptcRlyV = swc_THSM_ConstB.Constant;

  /* Delay: '<S147>/Delay One Step1' incorporates:
   *  Constant: '<S147>/Constant8'
   */
  if (swc_THSM_ARID_DEF.icLoad) {
    swc_THSM_ARID_DEF.DelayOneStep1_DSTATE_m = thmc_n_pmp1DefTgtSpd_pct;
  }

  /* Logic: '<S147>/Logical Operator' incorporates:
   *  Constant: '<S17>/Constant'
   *  RelationalOperator: '<S147>/Relational Operator2'
   *  RelationalOperator: '<S3>/Relational Operator11'
   */
  rtb_LogicalOperator2_f = ((thmd_b_accmEnbChrflg_tmp != PmmStatus_CHARGE) &&
    thmd_b_accmEnboffChrflg_tmp);

  /* RelationalOperator: '<S151>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S151>/Delay Input1'
   *
   * Block description for '<S151>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator_g = ((sint32)rtb_LogicalOperator2_f > (sint32)
    swc_THSM_ARID_DEF.DelayInput1_DSTATE_j);

  /* Outputs for Atomic SubSystem: '<S147>/turnOFF_delay' */
  /* Constant: '<S147>/Constant10' incorporates:
   *  Constant: '<S147>/Constant9'
   */
  swc_THSM_turnOFF_delay(rtb_FixPtRelationalOperator_g, thmc_tm_Pump215OffDly_s,
    ((float32)THM_TASK_INTERVAL_S), &rtb_flg_out_c,
    &swc_THSM_ARID_DEF.ARID_DEF_turnOFF_delay_k);

  /* End of Outputs for SubSystem: '<S147>/turnOFF_delay' */

  /* Switch: '<S147>/Switch11' incorporates:
   *  Constant: '<S147>/Constant'
   *  Constant: '<S147>/Constant22'
   *  Constant: '<S147>/Constant23'
   *  RelationalOperator: '<S147>/Relational Operator'
   *  RelationalOperator: '<S147>/Relational Operator3'
   *  RelationalOperator: '<S147>/Relational Operator4'
   *  Switch: '<S147>/Switch2'
   *  Switch: '<S147>/Switch7'
   *  Switch: '<S147>/Switch8'
   */
  if (thmd_b_FaultSts_flg1) {
    /* Switch: '<S147>/Switch11' incorporates:
     *  Constant: '<S147>/Constant15'
     */
    thmd_n_pmp1FaultTgtSpd_pct = thmc_n_pmp1FltStsTgtSpd_pct;
  } else if (swc_THSM_ARID_DEF.DataTypeConversion34 == ((uint8)2U)) {
    /* Switch: '<S147>/Switch3' incorporates:
     *  Switch: '<S147>/Switch7'
     */
    if (swc_THSM_ARID_DEF.DataTypeConversion12) {
      /* Switch: '<S147>/Switch4' incorporates:
       *  Constant: '<S17>/Constant'
       *  RelationalOperator: '<S147>/Relational Operator5'
       *  RelationalOperator: '<S3>/Relational Operator11'
       */
      if (thmd_b_accmEnbChrflg_tmp == PmmStatus_CHARGE) {
        /* Switch: '<S147>/Switch11' incorporates:
         *  Constant: '<S147>/Constant5'
         *  Switch: '<S147>/Switch3'
         *  Switch: '<S147>/Switch7'
         */
        thmd_n_pmp1FaultTgtSpd_pct = thmc_n_pmp1CoolChrTgtSpd_pct;
      } else {
        /* Switch: '<S147>/Switch11' incorporates:
         *  Constant: '<S147>/Constant6'
         *  Switch: '<S147>/Switch3'
         *  Switch: '<S147>/Switch7'
         */
        thmd_n_pmp1FaultTgtSpd_pct = thmc_n_pmp1CoolUnChrTgtSpd_pct;
      }

      /* End of Switch: '<S147>/Switch4' */
    } else {
      /* Switch: '<S147>/Switch11' incorporates:
       *  Constant: '<S147>/Constant3'
       *  Switch: '<S147>/Switch3'
       *  Switch: '<S147>/Switch7'
       */
      thmd_n_pmp1FaultTgtSpd_pct = thmc_n_pmp1DefTgtSpd_pct;
    }
  } else if (swc_THSM_ARID_DEF.DataTypeConversion34 == ((uint8)1U)) {
    /* Switch: '<S147>/Switch2' incorporates:
     *  Constant: '<S147>/Constant1'
     *  Switch: '<S147>/Switch11'
     *  Switch: '<S147>/Switch7'
     */
    thmd_n_pmp1FaultTgtSpd_pct = thmc_n_pmp1BmshThemReqTgtSpd_pct;
  } else if (swc_THSM_ARID_DEF.DataTypeConversion34 == ((uint8)3U)) {
    /* Switch: '<S147>/Switch8' incorporates:
     *  Constant: '<S147>/Constant14'
     *  Switch: '<S147>/Switch11'
     *  Switch: '<S147>/Switch2'
     *  Switch: '<S147>/Switch7'
     */
    thmd_n_pmp1FaultTgtSpd_pct = thmc_n_pmp1BalceTgtSpd_pct;
  } else {
    /* Switch: '<S147>/Switch11' incorporates:
     *  Constant: '<S147>/Constant7'
     *  Switch: '<S147>/Switch2'
     *  Switch: '<S147>/Switch7'
     *  Switch: '<S147>/Switch8'
     */
    thmd_n_pmp1FaultTgtSpd_pct = thmc_n_pmp1DefTgtSpd_pct;
  }

  /* Switch: '<S147>/Switch1' incorporates:
   *  Constant: '<S17>/Constant'
   *  Logic: '<S147>/Logical Operator1'
   *  Logic: '<S147>/Logical Operator5'
   *  RelationalOperator: '<S147>/Relational Operator1'
   *  RelationalOperator: '<S3>/Relational Operator11'
   *  Switch: '<S147>/Switch'
   *  Switch: '<S147>/Switch10'
   */
  if (rtb_flg_out_c && rtb_LogicalOperator2_f) {
    /* Switch: '<S147>/Switch1' incorporates:
     *  Delay: '<S147>/Delay One Step1'
     */
    thmd_n_pmp1NewTgtSpd_pct = swc_THSM_ARID_DEF.DelayOneStep1_DSTATE_m;
  } else if ((thmd_b_accmEnbChrflg_tmp != PmmStatus_CHARGE) &&
             thmd_b_accmEnboffChrflg_tmp) {
    /* Switch: '<S147>/Switch' incorporates:
     *  Constant: '<S147>/Constant2'
     *  Switch: '<S147>/Switch1'
     */
    thmd_n_pmp1NewTgtSpd_pct = thmc_n_pmp1DefTgtSpd_pct;
  } else if (thmd_b_NonVacFilling_flg) {
    /* Switch: '<S147>/Switch10' incorporates:
     *  Constant: '<S147>/Constant11'
     *  Switch: '<S147>/Switch'
     *  Switch: '<S147>/Switch1'
     */
    thmd_n_pmp1NewTgtSpd_pct = thmc_n_pmp1NonVacFillTgtSpd_pct;
  } else {
    /* Switch: '<S147>/Switch1' incorporates:
     *  Switch: '<S147>/Switch'
     *  Switch: '<S147>/Switch10'
     */
    thmd_n_pmp1NewTgtSpd_pct = thmd_n_pmp1FaultTgtSpd_pct;
  }

  /* Switch: '<S147>/Switch6' */
  if (swc_THSM_ARID_DEF.DataTypeConversion139 != 0.0) {
    /* Switch: '<S147>/Switch6' incorporates:
     *  Constant: '<S147>/Constant13'
     */
    thmd_n_pmp1SwapTgtSpd_pct = thmc_n_pmp1DefTgtSpd_pct;
  } else {
    /* Switch: '<S147>/Switch6' */
    thmd_n_pmp1SwapTgtSpd_pct = thmd_n_pmp1NewTgtSpd_pct;
  }

  /* End of Switch: '<S147>/Switch6' */

  /* Product: '<S147>/Product2' incorporates:
   *  Constant: '<S147>/Constant4'
   *  Gain: '<S147>/Gain2'
   */
  thmd_n_wtrPmp1NewTgtSpd_rpm = 0.01F * thmd_n_pmp1SwapTgtSpd_pct *
    thmc_n_wtrPmp1MaxSpd_rpm;

  /* SignalConversion: '<S147>/Signal Conversion' */
  swc_THSM_ARID_DEF.SignalConversion = thmd_n_pmp1SwapTgtSpd_pct;

  /* Delay: '<S148>/Delay One Step1' incorporates:
   *  Constant: '<S148>/Constant2'
   */
  if (swc_THSM_ARID_DEF.icLoad_n) {
    swc_THSM_ARID_DEF.DelayOneStep1_DSTATE_j = thmc_n_pmp2StopTgtSpdAirCl_pct;
  }

  /* Logic: '<S148>/Logical Operator' incorporates:
   *  Constant: '<S17>/Constant'
   *  RelationalOperator: '<S148>/Relational Operator2'
   *  RelationalOperator: '<S3>/Relational Operator11'
   */
  rtb_Relay4_g = ((thmd_b_accmEnbChrflg_tmp != PmmStatus_CHARGE) &&
                  thmd_b_accmEnboffChrflg_tmp);

  /* RelationalOperator: '<S158>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S158>/Delay Input1'
   *
   * Block description for '<S158>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator_f = ((sint32)rtb_Relay4_g > (sint32)
    swc_THSM_ARID_DEF.DelayInput1_DSTATE_n);

  /* Outputs for Atomic SubSystem: '<S148>/turnOFF_delay' */
  /* Constant: '<S148>/Constant10' incorporates:
   *  Constant: '<S148>/Constant9'
   */
  swc_THSM_turnOFF_delay(rtb_FixPtRelationalOperator_f,
    thmc_tm_Pump215OffDlyAirCl_s, ((float32)THM_TASK_INTERVAL_S),
    &rtb_flg_out_ao, &swc_THSM_ARID_DEF.ARID_DEF_turnOFF_delay);

  /* End of Outputs for SubSystem: '<S148>/turnOFF_delay' */

  /* Switch: '<S172>/Switch1' incorporates:
   *  Constant: '<S186>/Constant'
   *  RelationalOperator: '<S186>/Compare'
   *  Sum: '<S172>/Sum1'
   *  UnitDelay: '<S172>/Unit Delay2'
   */
  if (swc_THSM_ARID_DEF.DataTypeConversion21 -
      swc_THSM_ARID_DEF.UnitDelay2_DSTATE >= 0.0F) {
    /* Switch: '<S172>/Switch1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion21'
     *  Lookup_n-D: '<S172>/1D_Lookup_Table2'
     *  MinMax: '<S172>/MinMax2'
     *  UnitDelay: '<S172>/Unit Delay3'
     */
    thmd_n_pmp2ObcTempTgtSpdBigAirCl_pct = fmaxf(look1_iflf_binlcapw
      (swc_THSM_ARID_DEF.DataTypeConversion21, (const float32 *)
       &thmf_X_pmp2ObcTempIncBigAirCl_t[0], (const float32 *)
       &thmf_Y_pmp2ObcTempIncBigAirCl_pct[0], 4U),
      thmd_n_pmp2ObcTempTgtSpdBigAirCl_pct);
  } else {
    /* Switch: '<S172>/Switch1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion21'
     *  Lookup_n-D: '<S172>/1D_Lookup_Table3'
     *  MinMax: '<S172>/MinMax3'
     *  UnitDelay: '<S172>/Unit Delay3'
     */
    thmd_n_pmp2ObcTempTgtSpdBigAirCl_pct = fminf(look1_iflf_binlcapw
      (swc_THSM_ARID_DEF.DataTypeConversion21, (const float32 *)
       &thmf_X_pmp2ObcTempDecBig_t[0], (const float32 *)
       &thmf_Y_pmp2ObcTempDecBig_pct[0], 4U),
      thmd_n_pmp2ObcTempTgtSpdBigAirCl_pct);
  }

  /* End of Switch: '<S172>/Switch1' */

  /* Switch: '<S164>/Switch' incorporates:
   *  Constant: '<S178>/Constant'
   *  RelationalOperator: '<S178>/Compare'
   *  Sum: '<S164>/Sum'
   *  UnitDelay: '<S164>/Unit Delay'
   */
  if (swc_THSM_ARID_DEF.DataTypeConversion33 -
      swc_THSM_ARID_DEF.UnitDelay_DSTATE_k >= 0.0F) {
    /* Switch: '<S164>/Switch' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion33'
     *  Lookup_n-D: '<S164>/1D_Lookup_Table'
     *  MinMax: '<S164>/MinMax'
     *  UnitDelay: '<S164>/Unit Delay1'
     */
    rtb_t_delay_off_f = fmaxf(look1_iflf_binlcapw
      (swc_THSM_ARID_DEF.DataTypeConversion33, (const float32 *)
       &thmf_X_pmp2SnsrTempChrIncAirCl_t[0], (const float32 *)
       &thmf_Y_pmp2SnsrTempChrIncAirCl_pct[0], 6U),
      swc_THSM_ARID_DEF.UnitDelay1_DSTATE);
  } else {
    /* Switch: '<S164>/Switch' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion33'
     *  Lookup_n-D: '<S164>/1D_Lookup_Table1'
     *  MinMax: '<S164>/MinMax1'
     *  UnitDelay: '<S164>/Unit Delay1'
     */
    rtb_t_delay_off_f = fminf(look1_iflf_binlcapw
      (swc_THSM_ARID_DEF.DataTypeConversion33, (const float32 *)
       &thmf_X_pmp2SnsrTempChrDecAirCl_t[0], (const float32 *)
       &thmf_Y_pmp2SnsrTempChrDecAirCl_pct[0], 6U),
      swc_THSM_ARID_DEF.UnitDelay1_DSTATE);
  }

  /* End of Switch: '<S164>/Switch' */

  /* Switch: '<S167>/Switch1' incorporates:
   *  Constant: '<S181>/Constant'
   *  RelationalOperator: '<S181>/Compare'
   *  Sum: '<S167>/Sum1'
   *  UnitDelay: '<S167>/Unit Delay2'
   */
  if (swc_THSM_ARID_DEF.DataTypeConversion11 -
      swc_THSM_ARID_DEF.UnitDelay2_DSTATE_n >= 0.0F) {
    /* Switch: '<S167>/Switch1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion11'
     *  Lookup_n-D: '<S167>/1D_Lookup_Table2'
     *  MinMax: '<S167>/MinMax2'
     *  UnitDelay: '<S167>/Unit Delay3'
     */
    rtb_Switch1 = fmaxf(look1_iflf_binlcapw
                        (swc_THSM_ARID_DEF.DataTypeConversion11, (const float32 *)
                         &thmf_X_pmp2DcdcTempChgIncAirCl_t[0], (const float32 *)
                         &thmf_Y_pmp2DcdcTempChgIncAirCl_pct[0], 4U),
                        swc_THSM_ARID_DEF.UnitDelay3_DSTATE_p);
  } else {
    /* Switch: '<S167>/Switch1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion11'
     *  Lookup_n-D: '<S167>/1D_Lookup_Table3'
     *  MinMax: '<S167>/MinMax3'
     *  UnitDelay: '<S167>/Unit Delay3'
     */
    rtb_Switch1 = fminf(look1_iflf_binlcapw
                        (swc_THSM_ARID_DEF.DataTypeConversion11, (const float32 *)
                         &thmf_X_pmp2DcdcTempChgDecAirCl_t[0], (const float32 *)
                         &thmf_Y_pmp2DcdcTempChgDecAirCl_pct[0], 4U),
                        swc_THSM_ARID_DEF.UnitDelay3_DSTATE_p);
  }

  /* End of Switch: '<S167>/Switch1' */

  /* Switch: '<S162>/Switch' incorporates:
   *  Constant: '<S176>/Constant'
   *  RelationalOperator: '<S176>/Compare'
   *  Sum: '<S162>/Sum'
   *  UnitDelay: '<S162>/Unit Delay'
   */
  if (swc_THSM_ARID_DEF.DataTypeConversion33 -
      swc_THSM_ARID_DEF.UnitDelay_DSTATE_m >= 0.0F) {
    /* Switch: '<S162>/Switch' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion33'
     *  Lookup_n-D: '<S162>/1D_Lookup_Table'
     *  MinMax: '<S162>/MinMax'
     *  UnitDelay: '<S162>/Unit Delay1'
     */
    rtb_Relay3 = fmaxf(look1_iflf_binlcapw
                       (swc_THSM_ARID_DEF.DataTypeConversion33, (const float32 *)
                        &thmf_X_pmp2SnsrTempReqIncAirCl_t[0], (const float32 *)
                        &thmf_Y_pmp2SnsrTempReqIncAirCl_pct[0], 6U),
                       swc_THSM_ARID_DEF.UnitDelay1_DSTATE_a);
  } else {
    /* Switch: '<S162>/Switch' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion33'
     *  Lookup_n-D: '<S162>/1D_Lookup_Table1'
     *  MinMax: '<S162>/MinMax1'
     *  UnitDelay: '<S162>/Unit Delay1'
     */
    rtb_Relay3 = fminf(look1_iflf_binlcapw
                       (swc_THSM_ARID_DEF.DataTypeConversion33, (const float32 *)
                        &thmf_X_pmp2SnsrTempReqDecAirCl_t[0], (const float32 *)
                        &thmf_Y_pmp2SnsrTempReqDecAirCl_pct[0], 6U),
                       swc_THSM_ARID_DEF.UnitDelay1_DSTATE_a);
  }

  /* End of Switch: '<S162>/Switch' */

  /* Switch: '<S165>/Switch1' incorporates:
   *  Constant: '<S179>/Constant'
   *  RelationalOperator: '<S179>/Compare'
   *  Sum: '<S165>/Sum1'
   *  UnitDelay: '<S165>/Unit Delay2'
   */
  if (swc_THSM_ARID_DEF.DataTypeConversion11 -
      swc_THSM_ARID_DEF.UnitDelay2_DSTATE_p >= 0.0F) {
    /* Switch: '<S165>/Switch1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion11'
     *  Lookup_n-D: '<S165>/1D_Lookup_Table2'
     *  MinMax: '<S165>/MinMax2'
     *  UnitDelay: '<S165>/Unit Delay3'
     */
    rtb_Relay4 = fmaxf(look1_iflf_binlcapw
                       (swc_THSM_ARID_DEF.DataTypeConversion11, (const float32 *)
                        &thmf_X_pmp2DcdcTempReqIncAirCl_t[0], (const float32 *)
                        &thmf_Y_pmp2DcdcTempReqIncAirCl_pct[0], 4U),
                       swc_THSM_ARID_DEF.UnitDelay3_DSTATE_d);
  } else {
    /* Switch: '<S165>/Switch1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion11'
     *  Lookup_n-D: '<S165>/1D_Lookup_Table3'
     *  MinMax: '<S165>/MinMax3'
     *  UnitDelay: '<S165>/Unit Delay3'
     */
    rtb_Relay4 = fminf(look1_iflf_binlcapw
                       (swc_THSM_ARID_DEF.DataTypeConversion11, (const float32 *)
                        &thmf_X_pmp2DcdcTempReqDecAirCl_t[0], (const float32 *)
                        &thmf_Y_pmp2DcdcTempReqDecAirCl_pct[0], 4U),
                       swc_THSM_ARID_DEF.UnitDelay3_DSTATE_d);
  }

  /* End of Switch: '<S165>/Switch1' */

  /* Switch: '<S168>/Switch2' incorporates:
   *  Constant: '<S182>/Constant'
   *  RelationalOperator: '<S182>/Compare'
   *  Sum: '<S168>/Sum2'
   *  UnitDelay: '<S168>/Unit Delay4'
   */
  if (swc_THSM_ARID_DEF.DataTypeConversion27 -
      swc_THSM_ARID_DEF.UnitDelay4_DSTATE >= 0.0F) {
    /* Switch: '<S168>/Switch2' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion27'
     *  Lookup_n-D: '<S168>/1D_Lookup_Table4'
     *  MinMax: '<S168>/MinMax4'
     *  UnitDelay: '<S168>/Unit Delay5'
     */
    rtb_Switch3_a = fmaxf(look1_iflf_binlcapw
                          (swc_THSM_ARID_DEF.DataTypeConversion27, (const
      float32 *)&thmf_X_pmp2Inv2TempReqIncAirCl_t[0], (const float32 *)
      &thmf_Y_pmp2Inv2TempReqIncAirCl_pct[0], 4U),
                          swc_THSM_ARID_DEF.UnitDelay5_DSTATE);
  } else {
    /* Switch: '<S168>/Switch2' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion27'
     *  Lookup_n-D: '<S168>/1D_Lookup_Table5'
     *  MinMax: '<S168>/MinMax5'
     *  UnitDelay: '<S168>/Unit Delay5'
     */
    rtb_Switch3_a = fminf(look1_iflf_binlcapw
                          (swc_THSM_ARID_DEF.DataTypeConversion27, (const
      float32 *)&thmf_X_pmp2Inv2TempReqDecAirCl_t[0], (const float32 *)
      &thmf_Y_pmp2Inv2TempReqDecAirCl_pct[0], 4U),
                          swc_THSM_ARID_DEF.UnitDelay5_DSTATE);
  }

  /* End of Switch: '<S168>/Switch2' */

  /* Switch: '<S170>/Switch3' incorporates:
   *  Constant: '<S184>/Constant'
   *  RelationalOperator: '<S184>/Compare'
   *  Sum: '<S170>/Sum3'
   *  UnitDelay: '<S170>/Unit Delay6'
   */
  if (swc_THSM_ARID_DEF.DataTypeConversion31 -
      swc_THSM_ARID_DEF.UnitDelay6_DSTATE >= 0.0F) {
    /* Switch: '<S170>/Switch3' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion31'
     *  Lookup_n-D: '<S170>/1D_Lookup_Table6'
     *  MinMax: '<S170>/MinMax6'
     *  UnitDelay: '<S170>/Unit Delay7'
     */
    rtb_Switch3_ig = fmaxf(look1_iflf_binlcapw
      (swc_THSM_ARID_DEF.DataTypeConversion31, (const float32 *)
       &thmf_X_pmp2Mot2TempReqIncAirCl_t[0], (const float32 *)
       &thmf_Y_pmp2Mot2TempReqIncAirCl_pct[0], 4U),
      swc_THSM_ARID_DEF.UnitDelay7_DSTATE);
  } else {
    /* Switch: '<S170>/Switch3' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion31'
     *  Lookup_n-D: '<S170>/1D_Lookup_Table7'
     *  MinMax: '<S170>/MinMax7'
     *  UnitDelay: '<S170>/Unit Delay7'
     */
    rtb_Switch3_ig = fminf(look1_iflf_binlcapw
      (swc_THSM_ARID_DEF.DataTypeConversion31, (const float32 *)
       &thmf_X_pmp2Mot2TempReqDecAirCl_t[0], (const float32 *)
       &thmf_Y_pmp2Mot2TempReqDecAirCl_pct[0], 4U),
      swc_THSM_ARID_DEF.UnitDelay7_DSTATE);
  }

  /* End of Switch: '<S170>/Switch3' */

  /* Switch: '<S173>/Switch1' incorporates:
   *  Constant: '<S187>/Constant'
   *  RelationalOperator: '<S187>/Compare'
   *  Sum: '<S173>/Sum1'
   *  UnitDelay: '<S173>/Unit Delay2'
   */
  if (swc_THSM_ARID_DEF.DataTypeConversion21 -
      swc_THSM_ARID_DEF.UnitDelay2_DSTATE_c >= 0.0F) {
    /* Switch: '<S173>/Switch1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion21'
     *  Lookup_n-D: '<S173>/1D_Lookup_Table2'
     *  MinMax: '<S173>/MinMax2'
     *  UnitDelay: '<S173>/Unit Delay3'
     */
    rtb_Switch3_pp = fmaxf(look1_iflf_binlcapw
      (swc_THSM_ARID_DEF.DataTypeConversion21, (const float32 *)
       &thmf_X_ObcEdcpIncPct[0], (const float32 *)&thmf_Y_ObcEdcpIncPct[0], 6U),
      swc_THSM_ARID_DEF.UnitDelay3_DSTATE_n);
  } else {
    /* Switch: '<S173>/Switch1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion21'
     *  Lookup_n-D: '<S173>/1D_Lookup_Table3'
     *  MinMax: '<S173>/MinMax3'
     *  UnitDelay: '<S173>/Unit Delay3'
     */
    rtb_Switch3_pp = fminf(look1_iflf_binlcapw
      (swc_THSM_ARID_DEF.DataTypeConversion21, (const float32 *)
       &thmf_X_ObcEdcpDecPct[0], (const float32 *)&thmf_Y_ObcEdcpDecPct[0], 6U),
      swc_THSM_ARID_DEF.UnitDelay3_DSTATE_n);
  }

  /* End of Switch: '<S173>/Switch1' */

  /* Switch: '<S163>/Switch' incorporates:
   *  Constant: '<S177>/Constant'
   *  RelationalOperator: '<S177>/Compare'
   *  Sum: '<S163>/Sum'
   *  UnitDelay: '<S163>/Unit Delay'
   */
  if (swc_THSM_ARID_DEF.DataTypeConversion33 -
      swc_THSM_ARID_DEF.UnitDelay_DSTATE_b >= 0.0F) {
    /* Switch: '<S163>/Switch' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion33'
     *  Lookup_n-D: '<S163>/1D_Lookup_Table'
     *  MinMax: '<S163>/MinMax'
     *  UnitDelay: '<S163>/Unit Delay1'
     */
    rtb_Switch3_p = fmaxf(look1_iflf_binlcapw
                          (swc_THSM_ARID_DEF.DataTypeConversion33, (const
      float32 *)&thmf_X_Pmp2SnsrTempIdleIncPct[0], (const float32 *)
      &thmf_Y_Pmp2SnsrTempIdleIncPct[0], 7U),
                          swc_THSM_ARID_DEF.UnitDelay1_DSTATE_h);
  } else {
    /* Switch: '<S163>/Switch' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion33'
     *  Lookup_n-D: '<S163>/1D_Lookup_Table1'
     *  MinMax: '<S163>/MinMax1'
     *  UnitDelay: '<S163>/Unit Delay1'
     */
    rtb_Switch3_p = fminf(look1_iflf_binlcapw
                          (swc_THSM_ARID_DEF.DataTypeConversion33, (const
      float32 *)&thmf_X_Pmp2SnsrTempIdleDecPct[0], (const float32 *)
      &thmf_Y_Pmp2SnsrTempIdleDecPct[0], 7U),
                          swc_THSM_ARID_DEF.UnitDelay1_DSTATE_h);
  }

  /* End of Switch: '<S163>/Switch' */

  /* Switch: '<S166>/Switch1' incorporates:
   *  Constant: '<S180>/Constant'
   *  RelationalOperator: '<S180>/Compare'
   *  Sum: '<S166>/Sum1'
   *  UnitDelay: '<S166>/Unit Delay2'
   */
  if (swc_THSM_ARID_DEF.DataTypeConversion11 -
      swc_THSM_ARID_DEF.UnitDelay2_DSTATE_i >= 0.0F) {
    /* Switch: '<S166>/Switch1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion11'
     *  Lookup_n-D: '<S166>/1D_Lookup_Table1'
     *  MinMax: '<S166>/MinMax2'
     *  UnitDelay: '<S166>/Unit Delay3'
     */
    rtb_Switch3_hw = fmaxf(look1_iflf_binlcapw
      (swc_THSM_ARID_DEF.DataTypeConversion11, (const float32 *)
       &thmf_X_Pmp2DcdcIdleIncPct[0], (const float32 *)
       &thmf_Y_Pmp2DcdcIdleIncPct[0], 5U), swc_THSM_ARID_DEF.UnitDelay3_DSTATE_b);
  } else {
    /* Switch: '<S166>/Switch1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion11'
     *  Lookup_n-D: '<S166>/1D_Lookup_Table3'
     *  MinMax: '<S166>/MinMax3'
     *  UnitDelay: '<S166>/Unit Delay3'
     */
    rtb_Switch3_hw = fminf(look1_iflf_binlcapw
      (swc_THSM_ARID_DEF.DataTypeConversion11, (const float32 *)
       &thmf_X_Pmp2DcdcIdleDecPct[0], (const float32 *)
       &thmf_Y_Pmp2DcdcIdleDecPct[0], 5U), swc_THSM_ARID_DEF.UnitDelay3_DSTATE_b);
  }

  /* End of Switch: '<S166>/Switch1' */

  /* Switch: '<S169>/Switch2' incorporates:
   *  Constant: '<S183>/Constant'
   *  RelationalOperator: '<S183>/Compare'
   *  Sum: '<S169>/Sum2'
   *  UnitDelay: '<S169>/Unit Delay4'
   */
  if (swc_THSM_ARID_DEF.DataTypeConversion27 -
      swc_THSM_ARID_DEF.UnitDelay4_DSTATE_g >= 0.0F) {
    /* Switch: '<S169>/Switch2' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion27'
     *  Lookup_n-D: '<S169>/1D_Lookup_Table2'
     *  MinMax: '<S169>/MinMax4'
     *  UnitDelay: '<S169>/Unit Delay5'
     */
    rtb_Switch3_cu = fmaxf(look1_iflf_binlcapw
      (swc_THSM_ARID_DEF.DataTypeConversion27, (const float32 *)
       &thmf_X_Pmp2McuIdleIncPct[0], (const float32 *)&thmf_Y_Pmp2McuIdleIncPct
       [0], 5U), swc_THSM_ARID_DEF.UnitDelay5_DSTATE_g);
  } else {
    /* Switch: '<S169>/Switch2' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion27'
     *  Lookup_n-D: '<S169>/1D_Lookup_Table5'
     *  MinMax: '<S169>/MinMax5'
     *  UnitDelay: '<S169>/Unit Delay5'
     */
    rtb_Switch3_cu = fminf(look1_iflf_binlcapw
      (swc_THSM_ARID_DEF.DataTypeConversion27, (const float32 *)
       &thmf_X_Pmp2McuIdleDecPct[0], (const float32 *)&thmf_Y_Pmp2McuIdleDecPct
       [0], 5U), swc_THSM_ARID_DEF.UnitDelay5_DSTATE_g);
  }

  /* End of Switch: '<S169>/Switch2' */

  /* Switch: '<S171>/Switch3' incorporates:
   *  Constant: '<S185>/Constant'
   *  RelationalOperator: '<S185>/Compare'
   *  Sum: '<S171>/Sum3'
   *  UnitDelay: '<S171>/Unit Delay6'
   */
  if (swc_THSM_ARID_DEF.DataTypeConversion31 -
      swc_THSM_ARID_DEF.UnitDelay6_DSTATE_g >= 0.0F) {
    /* Switch: '<S171>/Switch3' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion31'
     *  Lookup_n-D: '<S171>/1D_Lookup_Table3'
     *  MinMax: '<S171>/MinMax6'
     *  UnitDelay: '<S171>/Unit Delay7'
     */
    rtb_Switch3_g = fmaxf(look1_iflf_binlcapw
                          (swc_THSM_ARID_DEF.DataTypeConversion31, (const
      float32 *)&thmf_X_Pmp2MotorIdleIncPct[0], (const float32 *)
      &thmf_Y_Pmp2MotorIdleIncPct[0], 5U), swc_THSM_ARID_DEF.UnitDelay7_DSTATE_o);
  } else {
    /* Switch: '<S171>/Switch3' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion31'
     *  Lookup_n-D: '<S171>/1D_Lookup_Table7'
     *  MinMax: '<S171>/MinMax7'
     *  UnitDelay: '<S171>/Unit Delay7'
     */
    rtb_Switch3_g = fminf(look1_iflf_binlcapw
                          (swc_THSM_ARID_DEF.DataTypeConversion31, (const
      float32 *)&thmf_X_Pmp2MotorIdleDecPct[0], (const float32 *)
      &thmf_Y_Pmp2MotorIdleDecPct[0], 5U), swc_THSM_ARID_DEF.UnitDelay7_DSTATE_o);
  }

  /* End of Switch: '<S171>/Switch3' */

  /* Switch: '<S174>/Switch1' incorporates:
   *  Constant: '<S188>/Constant'
   *  RelationalOperator: '<S188>/Compare'
   *  Sum: '<S174>/Sum1'
   *  UnitDelay: '<S174>/Unit Delay2'
   */
  if (swc_THSM_ARID_DEF.DataTypeConversion21 -
      swc_THSM_ARID_DEF.UnitDelay2_DSTATE_o >= 0.0F) {
    /* Switch: '<S174>/Switch1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion21'
     *  Lookup_n-D: '<S174>/1D_Lookup_Table2'
     *  MinMax: '<S174>/MinMax2'
     *  UnitDelay: '<S174>/Unit Delay3'
     */
    rtb_Switch1_gh = fmaxf(look1_iflf_binlcapw
      (swc_THSM_ARID_DEF.DataTypeConversion21, (const float32 *)
       &thmf_X_ObcEdcpIdleIncPct[0], (const float32 *)&thmf_Y_ObcEdcpIdleIncPct
       [0], 6U), swc_THSM_ARID_DEF.UnitDelay3_DSTATE_p1);
  } else {
    /* Switch: '<S174>/Switch1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion21'
     *  Lookup_n-D: '<S174>/1D_Lookup_Table3'
     *  MinMax: '<S174>/MinMax3'
     *  UnitDelay: '<S174>/Unit Delay3'
     */
    rtb_Switch1_gh = fminf(look1_iflf_binlcapw
      (swc_THSM_ARID_DEF.DataTypeConversion21, (const float32 *)
       &thmf_X_ObcEdcpIdleDecPct[0], (const float32 *)&thmf_Y_ObcEdcpIdleDecPct
       [0], 6U), swc_THSM_ARID_DEF.UnitDelay3_DSTATE_p1);
  }

  /* End of Switch: '<S174>/Switch1' */

  /* Switch: '<S148>/Switch' incorporates:
   *  Constant: '<S157>/Constant'
   *  Constant: '<S17>/Constant'
   *  RelationalOperator: '<S148>/Relational Operator'
   *  RelationalOperator: '<S157>/Compare'
   *  RelationalOperator: '<S3>/Relational Operator11'
   *  Switch: '<S148>/Switch3'
   */
  if (thmd_b_accmEnbChrflg_tmp == PmmStatus_CHARGE) {
    /* Switch: '<S148>/Switch' incorporates:
     *  MinMax: '<S148>/MinMax2'
     */
    thmd_n_pmp2IpuClTgtSpdAirCl_pct = fmaxf(fmaxf
      (thmd_n_pmp2ObcTempTgtSpdBigAirCl_pct, rtb_t_delay_off_f), rtb_Switch1);
  } else if (swc_THSM_ARID_DEF.DataTypeConversion39 >= 3.0F) {
    /* Switch: '<S148>/Switch3' incorporates:
     *  MinMax: '<S148>/MinMax1'
     *  Switch: '<S148>/Switch'
     */
    thmd_n_pmp2IpuClTgtSpdAirCl_pct = fmaxf(fmaxf(fmaxf(fmaxf(rtb_Relay3,
      rtb_Relay4), rtb_Switch3_a), rtb_Switch3_ig), rtb_Switch3_pp);
  } else {
    /* Switch: '<S148>/Switch' incorporates:
     *  MinMax: '<S148>/MinMax3'
     *  Switch: '<S148>/Switch3'
     */
    thmd_n_pmp2IpuClTgtSpdAirCl_pct = fmaxf(fmaxf(fmaxf(fmaxf(rtb_Switch3_p,
      rtb_Switch3_hw), rtb_Switch3_cu), rtb_Switch3_g), rtb_Switch1_gh);
  }

  /* End of Switch: '<S148>/Switch' */

  /* Switch: '<S148>/Switch2' incorporates:
   *  Constant: '<S17>/Constant'
   *  Logic: '<S148>/Logical Operator2'
   *  RelationalOperator: '<S148>/Relational Operator1'
   *  RelationalOperator: '<S3>/Relational Operator11'
   *  Switch: '<S148>/Switch10'
   *  Switch: '<S148>/Switch11'
   */
  if ((thmd_b_accmEnbChrflg_tmp != PmmStatus_CHARGE) &&
      thmd_b_accmEnboffChrflg_tmp) {
    /* Switch: '<S148>/Switch2' incorporates:
     *  Constant: '<S148>/Constant'
     */
    thmd_n_pmp2Kl15TgtSpdAirCl_pct = thmc_n_pmp2StopTgtSpdAirCl_pct;
  } else if (thmd_b_NonVacFilling_flg) {
    /* Switch: '<S148>/Switch10' incorporates:
     *  Constant: '<S148>/Constant11'
     *  Switch: '<S148>/Switch2'
     */
    thmd_n_pmp2Kl15TgtSpdAirCl_pct = thmc_n_pmp2NonVacTgtSpdAirCl_pct;
  } else if (thmd_b_FaultSts_flg) {
    /* Switch: '<S148>/Switch11' incorporates:
     *  Constant: '<S148>/Constant15'
     *  Switch: '<S148>/Switch10'
     *  Switch: '<S148>/Switch2'
     */
    thmd_n_pmp2Kl15TgtSpdAirCl_pct = thmc_n_pmp2FltTgtSpdAirCl_pct;
  } else {
    /* Switch: '<S148>/Switch2' incorporates:
     *  Switch: '<S148>/Switch10'
     *  Switch: '<S148>/Switch11'
     */
    thmd_n_pmp2Kl15TgtSpdAirCl_pct = thmd_n_pmp2IpuClTgtSpdAirCl_pct;
  }

  /* End of Switch: '<S148>/Switch2' */

  /* Switch: '<S148>/Switch1' incorporates:
   *  Logic: '<S148>/Logical Operator4'
   */
  if (rtb_flg_out_ao && rtb_Relay4_g) {
    /* Switch: '<S148>/Switch1' incorporates:
     *  Delay: '<S148>/Delay One Step1'
     */
    thmd_n_pmp2TgtSpdAirCl_pct = swc_THSM_ARID_DEF.DelayOneStep1_DSTATE_j;
  } else {
    /* Switch: '<S148>/Switch1' */
    thmd_n_pmp2TgtSpdAirCl_pct = thmd_n_pmp2Kl15TgtSpdAirCl_pct;
  }

  /* End of Switch: '<S148>/Switch1' */

  /* Lookup_n-D: '<S148>/1-D Lookup Table' incorporates:
   *  Switch: '<S148>/Switch1'
   */
  rtb_uDLookupTable = look1_iflf_binlxpw(thmd_n_pmp2TgtSpdAirCl_pct, (const
    float32 *)&thmf_X_pmp2TgtSpd_pct[0], (const float32 *)
    &thmf_Y_pmp2FlowFeedback_Lmin[0], 8U);

  /* Product: '<S148>/Product2' incorporates:
   *  Constant: '<S148>/Constant4'
   *  Gain: '<S148>/Gain2'
   */
  rtb_Product2 = 0.01F * thmd_n_pmp2TgtSpdAirCl_pct * thmc_n_wtrPmp2MaxSpd_rpm;

  /* Switch: '<S150>/Switch4' incorporates:
   *  Constant: '<S192>/Constant'
   *  RelationalOperator: '<S192>/Compare'
   */
  if (thmd_n_pmp1SwapTgtSpd_pct <= thmc_n_pmp1DefTgtSpd_pct) {
    /* Switch: '<S150>/Switch4' incorporates:
     *  Constant: '<S195>/Constant'
     */
    thmd_e_wtrPmp1TgtSts = PumpStatus_OFF;
  } else {
    /* Switch: '<S150>/Switch4' incorporates:
     *  Constant: '<S194>/Constant'
     */
    thmd_e_wtrPmp1TgtSts = PumpStatus_LOW_SPEED;
  }

  /* End of Switch: '<S150>/Switch4' */

  /* Outputs for Atomic SubSystem: '<S149>/state_mapping' */
  /* Saturate: '<S190>/Saturation1' incorporates:
   *  DataTypeConversion: '<S190>/Data Type Conversion'
   *  Switch: '<S150>/Switch4'
   */
  if (thmd_e_wtrPmp1TgtSts <= ((uint8)3U)) {
    /* Saturate: '<S190>/Saturation1' */
    rtb_Saturation1_c = thmd_e_wtrPmp1TgtSts;
  } else {
    /* Saturate: '<S190>/Saturation1' */
    rtb_Saturation1_c = ((uint8)3U);
  }

  /* End of Saturate: '<S190>/Saturation1' */

  /* Switch: '<S190>/Switch' incorporates:
   *  DataTypeConversion: '<S190>/Data Type Conversion'
   *  RelationalOperator: '<S190>/Relational Operator'
   *  Switch: '<S150>/Switch4'
   */
  if (thmd_e_wtrPmp1TgtSts > rtb_Saturation1_c) {
    /* Switch: '<S190>/Switch' incorporates:
     *  Constant: '<S149>/Constant1'
     */
    thmd_b_wtrPmpRly1Req = thmc_b_wtrPmpRly1Dflt;
  } else {
    /* Switch: '<S190>/Switch' incorporates:
     *  Constant: '<S149>/Constant'
     *  MultiPortSwitch: '<S190>/Index Vector'
     */
    thmd_b_wtrPmpRly1Req = THM_WTRPMPRLY1[rtb_Saturation1_c];
  }

  /* End of Switch: '<S190>/Switch' */
  /* End of Outputs for SubSystem: '<S149>/state_mapping' */

  /* Relay: '<S150>/Relay5' */
  swc_THSM_ARID_DEF.Relay5_Mode = ((thmd_n_pmp2TgtSpdAirCl_pct >=
    thmc_n_pmp2HiSpdReqEna_pct) || ((thmd_n_pmp2TgtSpdAirCl_pct >
    thmc_n_pmp2HiSpdReqDis_pct) && swc_THSM_ARID_DEF.Relay5_Mode));

  /* Relay: '<S150>/Relay3' */
  swc_THSM_ARID_DEF.Relay3_Mode_d = ((thmd_n_pmp2TgtSpdAirCl_pct >=
    thmc_n_pmp2MedSpdReqEna_pct) || ((thmd_n_pmp2TgtSpdAirCl_pct >
    thmc_n_pmp2MedSpdReqDis_pct) && swc_THSM_ARID_DEF.Relay3_Mode_d));

  /* Relay: '<S150>/Relay4' */
  swc_THSM_ARID_DEF.Relay4_Mode_d = ((thmd_n_pmp2TgtSpdAirCl_pct >=
    thmc_n_pmp2LoSpdReqEna_pct) || ((thmd_n_pmp2TgtSpdAirCl_pct >
    thmc_n_pmp2LoSpdReqDis_pct) && swc_THSM_ARID_DEF.Relay4_Mode_d));

  /* Switch: '<S150>/Switch8' */
  if (thmd_b_wtrPmp2CtrlEnabled) {
    /* Relay: '<S150>/Relay5' */
    if (swc_THSM_ARID_DEF.Relay5_Mode) {
      rtb_Saturation1_c = ((uint8)1U);
    } else {
      rtb_Saturation1_c = ((uint8)0U);
    }

    /* Switch: '<S150>/Switch6' incorporates:
     *  DataTypeConversion: '<S150>/Data Type Conversion6'
     *  Relay: '<S150>/Relay3'
     *  Relay: '<S150>/Relay5'
     */
    if (rtb_Saturation1_c != 0) {
      /* Switch: '<S150>/Switch8' incorporates:
       *  Constant: '<S199>/Constant'
       *  Switch: '<S150>/Switch6'
       */
      thmd_e_wtrPmp2TgtSts = PumpStatus_HIGH_SPEED;
    } else {
      if (swc_THSM_ARID_DEF.Relay3_Mode_d) {
        /* Relay: '<S150>/Relay3' */
        rtb_Saturation1_c = ((uint8)1U);
      } else {
        /* Relay: '<S150>/Relay3' */
        rtb_Saturation1_c = ((uint8)0U);
      }

      /* Switch: '<S150>/Switch5' incorporates:
       *  DataTypeConversion: '<S150>/Data Type Conversion4'
       *  Relay: '<S150>/Relay3'
       *  Relay: '<S150>/Relay4'
       */
      if (rtb_Saturation1_c != 0) {
        /* Switch: '<S150>/Switch8' incorporates:
         *  Constant: '<S196>/Constant'
         *  Switch: '<S150>/Switch5'
         */
        thmd_e_wtrPmp2TgtSts = PumpStatus_MEDIUM_SPEED;
      } else {
        if (swc_THSM_ARID_DEF.Relay4_Mode_d) {
          /* Relay: '<S150>/Relay4' */
          rtb_Saturation1_c = ((uint8)1U);
        } else {
          /* Relay: '<S150>/Relay4' */
          rtb_Saturation1_c = ((uint8)0U);
        }

        /* Switch: '<S150>/Switch7' incorporates:
         *  DataTypeConversion: '<S150>/Data Type Conversion5'
         *  Relay: '<S150>/Relay4'
         */
        if (rtb_Saturation1_c != 0) {
          /* Switch: '<S150>/Switch8' incorporates:
           *  Constant: '<S197>/Constant'
           *  Switch: '<S150>/Switch5'
           */
          thmd_e_wtrPmp2TgtSts = PumpStatus_LOW_SPEED;
        } else {
          /* Switch: '<S150>/Switch8' incorporates:
           *  Constant: '<S198>/Constant'
           *  Switch: '<S150>/Switch5'
           */
          thmd_e_wtrPmp2TgtSts = PumpStatus_OFF;
        }

        /* End of Switch: '<S150>/Switch7' */
      }

      /* End of Switch: '<S150>/Switch5' */
    }

    /* End of Switch: '<S150>/Switch6' */
  } else {
    /* Switch: '<S150>/Switch8' incorporates:
     *  Constant: '<S193>/Constant'
     */
    thmd_e_wtrPmp2TgtSts = PumpStatus_OFF;
  }

  /* End of Switch: '<S150>/Switch8' */

  /* Outputs for Atomic SubSystem: '<S149>/state_mapping1' */
  /* Saturate: '<S191>/Saturation1' incorporates:
   *  DataTypeConversion: '<S191>/Data Type Conversion'
   *  Switch: '<S150>/Switch8'
   */
  if (thmd_e_wtrPmp2TgtSts <= ((uint8)3U)) {
    /* Saturate: '<S191>/Saturation1' */
    rtb_Saturation1_c = thmd_e_wtrPmp2TgtSts;
  } else {
    /* Saturate: '<S191>/Saturation1' */
    rtb_Saturation1_c = ((uint8)3U);
  }

  /* End of Saturate: '<S191>/Saturation1' */

  /* Switch: '<S191>/Switch' incorporates:
   *  DataTypeConversion: '<S191>/Data Type Conversion'
   *  RelationalOperator: '<S191>/Relational Operator'
   *  Switch: '<S150>/Switch8'
   */
  if (thmd_e_wtrPmp2TgtSts > rtb_Saturation1_c) {
    /* Switch: '<S191>/Switch' incorporates:
     *  Constant: '<S149>/Constant3'
     */
    thmd_b_wtrPmpRly2Req = thmc_b_wtrPmpRly2Dflt;
  } else {
    /* Switch: '<S191>/Switch' incorporates:
     *  Constant: '<S149>/Constant2'
     *  MultiPortSwitch: '<S191>/Index Vector'
     */
    thmd_b_wtrPmpRly2Req = THM_WTRPMPRLY2[rtb_Saturation1_c];
  }

  /* End of Switch: '<S191>/Switch' */
  /* End of Outputs for SubSystem: '<S149>/state_mapping1' */

  /* Outputs for Atomic SubSystem: '<S150>/state_mapping' */
  /* Outputs for Atomic SubSystem: '<S149>/state_mapping' */
  /* Saturate: '<S200>/Saturation1' incorporates:
   *  DataTypeConversion: '<S190>/Data Type Conversion'
   *  Switch: '<S150>/Switch4'
   */
  if (thmd_e_wtrPmp1TgtSts <= ((uint8)10U)) {
    /* Saturate: '<S200>/Saturation1' */
    rtb_Saturation1_c = thmd_e_wtrPmp1TgtSts;
  } else {
    /* Saturate: '<S200>/Saturation1' */
    rtb_Saturation1_c = ((uint8)10U);
  }

  /* End of Saturate: '<S200>/Saturation1' */

  /* Switch: '<S200>/Switch' incorporates:
   *  DataTypeConversion: '<S190>/Data Type Conversion'
   *  RelationalOperator: '<S200>/Relational Operator'
   *  Switch: '<S150>/Switch4'
   */
  if (thmd_e_wtrPmp1TgtSts > rtb_Saturation1_c) {
    /* Switch: '<S200>/Switch' incorporates:
     *  Constant: '<S150>/Constant3'
     */
    thmd_st_wtrPmp1ReqCmd = thmc_st_pmp1ReqStatusDflt;
  } else {
    /* Switch: '<S200>/Switch' incorporates:
     *  Constant: '<S150>/Constant'
     *  MultiPortSwitch: '<S200>/Index Vector'
     */
    thmd_st_wtrPmp1ReqCmd = THM_WTRPMP1REQSTATUS[rtb_Saturation1_c];
  }

  /* End of Switch: '<S200>/Switch' */
  /* End of Outputs for SubSystem: '<S149>/state_mapping' */
  /* End of Outputs for SubSystem: '<S150>/state_mapping' */

  /* Outputs for Atomic SubSystem: '<S150>/state_mapping1' */
  /* Saturate: '<S201>/Saturation1' incorporates:
   *  DataTypeConversion: '<S201>/Data Type Conversion'
   *  Switch: '<S150>/Switch8'
   */
  if (thmd_e_wtrPmp2TgtSts <= ((uint8)10U)) {
    /* Saturate: '<S201>/Saturation1' */
    rtb_Saturation1_c = thmd_e_wtrPmp2TgtSts;
  } else {
    /* Saturate: '<S201>/Saturation1' */
    rtb_Saturation1_c = ((uint8)10U);
  }

  /* End of Saturate: '<S201>/Saturation1' */

  /* Switch: '<S201>/Switch' incorporates:
   *  DataTypeConversion: '<S201>/Data Type Conversion'
   *  RelationalOperator: '<S201>/Relational Operator'
   *  Switch: '<S150>/Switch8'
   */
  if (thmd_e_wtrPmp2TgtSts > rtb_Saturation1_c) {
    /* Switch: '<S201>/Switch' incorporates:
     *  Constant: '<S150>/Constant2'
     */
    thmd_st_wtrPmp2ReqCmd = thmc_st_pmp2ReqStatusDflt;
  } else {
    /* Switch: '<S201>/Switch' incorporates:
     *  Constant: '<S150>/Constant1'
     *  MultiPortSwitch: '<S201>/Index Vector'
     */
    thmd_st_wtrPmp2ReqCmd = THM_WTRPMP2REQSTATUS[rtb_Saturation1_c];
  }

  /* End of Switch: '<S201>/Switch' */
  /* End of Outputs for SubSystem: '<S150>/state_mapping1' */

  /* Outputs for Enabled SubSystem: '<S2>/ptc3FaultStatusControl' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  /* Logic: '<S2>/Logical Operator' incorporates:
   *  Constant: '<S202>/Constant3'
   *  Constant: '<S202>/Constant4'
   *  Constant: '<S202>/Constant7'
   *  Constant: '<S202>/Constant8'
   *  Constant: '<S5>/Constant'
   *  Constant: '<S6>/Constant'
   *  Logic: '<S13>/Logical Operator1'
   *  RelationalOperator: '<S5>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   */
  if ((swc_THSM_ARID_DEF.DataTypeConversion151 == 2.0) &&
      (swc_THSM_ARID_DEF.DataTypeConversion1 == ((uint8)0U))) {
    swc_THSM_ARID_DEF.ptc3FaultStatusControl_MODE = true;

    /* SignalConversion generated from: '<S13>/thmd_st_acceRlyVoltSamSwitch' incorporates:
     *  Constant: '<S13>/Constant'
     */
    swc_THSM_ARID_DEF.OutportBufferForthmd_st_acceRly = ((uint8)1U);

    /* Outputs for Enabled SubSystem: '<S13>/ptc3FaultStatus' incorporates:
     *  EnablePort: '<S202>/Enable'
     */
    if (!swc_THSM_ARID_DEF.DataTypeConversion155) {
      if (!swc_THSM_ARID_DEF.ptc3FaultStatus_MODE) {
        /* SystemReset for Atomic SubSystem: '<S202>/turnON_delay' */
        swc_THSM_turnON_delay_Reset(&rtb_flg_out_o,
          &swc_THSM_ARID_DEF.ARID_DEF_turnON_delay_c);

        /* End of SystemReset for SubSystem: '<S202>/turnON_delay' */

        /* SystemReset for Atomic SubSystem: '<S202>/turnON_delay1' */
        swc_THSM_turnON_delay_Reset(&rtb_flg_out_a,
          &swc_THSM_ARID_DEF.ARID_DEF_turnON_delay1_m);

        /* End of SystemReset for SubSystem: '<S202>/turnON_delay1' */
        swc_THSM_ARID_DEF.ptc3FaultStatus_MODE = true;
      }

      /* RelationalOperator: '<S202>/Relational Operator' incorporates:
       *  Gain: '<S202>/Gain'
       */
      rtb_RelationalOperator_f = (swc_THSM_ARID_DEF.DataTypeConversion153 >= 0.8
        * swc_THSM_ARID_DEF.DataTypeConversion150);

      /* Logic: '<S202>/Logical Operator' */
      rtb_LogicalOperator_c = !rtb_RelationalOperator_f;

      /* Switch: '<S202>/Switch' */
      if (rtb_RelationalOperator_f) {
        /* Switch: '<S202>/Switch' incorporates:
         *  Constant: '<S202>/Constant1'
         */
        swc_THSM_ARID_DEF.Switch = ((uint8)1U);
      } else {
        /* Switch: '<S202>/Switch' incorporates:
         *  Constant: '<S202>/Constant2'
         */
        swc_THSM_ARID_DEF.Switch = ((uint8)0U);
      }

      /* End of Switch: '<S202>/Switch' */

      /* Outputs for Atomic SubSystem: '<S202>/turnON_delay' */
      swc_THSM_turnON_delay(rtb_LogicalOperator_c, thmc_tm_ptc3VoltFaultThr_s,
                            ((float32)THM_TASK_INTERVAL_S), &rtb_flg_out_o,
                            &swc_THSM_ARID_DEF.ARID_DEF_turnON_delay_c);

      /* End of Outputs for SubSystem: '<S202>/turnON_delay' */

      /* Outputs for Atomic SubSystem: '<S202>/turnON_delay1' */
      swc_THSM_turnON_delay(rtb_RelationalOperator_f,
                            thmc_tm_ptc3VoltFaultThr1_s, ((float32)
        THM_TASK_INTERVAL_S), &rtb_flg_out_a,
                            &swc_THSM_ARID_DEF.ARID_DEF_turnON_delay1_m);

      /* End of Outputs for SubSystem: '<S202>/turnON_delay1' */

      /* Switch: '<S202>/Switch1' incorporates:
       *  Constant: '<S202>/Constant3'
       *  Constant: '<S202>/Constant4'
       *  Constant: '<S202>/Constant7'
       *  Constant: '<S202>/Constant8'
       *  Switch: '<S202>/Switch3'
       */
      if (swc_THSM_ARID_DEF.flg_out_j) {
        /* Switch: '<S202>/Switch2' */
        if (rtb_flg_out_o) {
          /* Switch: '<S202>/Switch1' incorporates:
           *  Constant: '<S202>/Constant5'
           */
          swc_THSM_ARID_DEF.Switch1 = ((uint8)1U);
        } else {
          /* Switch: '<S202>/Switch1' incorporates:
           *  Constant: '<S202>/Constant6'
           */
          swc_THSM_ARID_DEF.Switch1 = ((uint8)0U);
        }

        /* End of Switch: '<S202>/Switch2' */
      } else if (rtb_flg_out_a) {
        /* Switch: '<S202>/Switch3' incorporates:
         *  Constant: '<S202>/Constant9'
         *  Switch: '<S202>/Switch1'
         */
        swc_THSM_ARID_DEF.Switch1 = ((uint8)2U);
      } else {
        /* Switch: '<S202>/Switch1' incorporates:
         *  Constant: '<S202>/Constant10'
         *  Switch: '<S202>/Switch3'
         */
        swc_THSM_ARID_DEF.Switch1 = ((uint8)0U);
      }

      /* End of Switch: '<S202>/Switch1' */
    } else if (swc_THSM_ARID_DEF.ptc3FaultStatus_MODE) {
      /* Disable for Switch: '<S202>/Switch' incorporates:
       *  Outport: '<S202>/thmd_st_ptc3ConnStsFb'
       */
      swc_THSM_ARID_DEF.Switch = ((uint8)3U);

      /* Disable for Switch: '<S202>/Switch1' incorporates:
       *  Outport: '<S202>/thmd_st_ptc3RlyFlt'
       */
      swc_THSM_ARID_DEF.Switch1 = ((uint8)0U);
      swc_THSM_ARID_DEF.ptc3FaultStatus_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S13>/ptc3FaultStatus' */

    /* SignalConversion generated from: '<S13>/thmd_st_ptc3ConnStsFb' incorporates:
     *  Constant: '<S202>/Constant3'
     *  Constant: '<S202>/Constant4'
     *  Constant: '<S202>/Constant7'
     *  Constant: '<S202>/Constant8'
     *  Logic: '<S13>/Logical Operator1'
     */
    thmd_st_ptc3ConnStsFb = swc_THSM_ARID_DEF.Switch;

    /* SignalConversion generated from: '<S13>/thmd_st_ptc3RlyFlt' */
    thmd_st_ptc3RlyFlt = swc_THSM_ARID_DEF.Switch1;
  } else if (swc_THSM_ARID_DEF.ptc3FaultStatusControl_MODE) {
    /* Disable for Enabled SubSystem: '<S13>/ptc3FaultStatus' */
    if (swc_THSM_ARID_DEF.ptc3FaultStatus_MODE) {
      /* Disable for Switch: '<S202>/Switch' incorporates:
       *  Outport: '<S202>/thmd_st_ptc3ConnStsFb'
       */
      swc_THSM_ARID_DEF.Switch = ((uint8)3U);

      /* Disable for Switch: '<S202>/Switch1' incorporates:
       *  Outport: '<S202>/thmd_st_ptc3RlyFlt'
       */
      swc_THSM_ARID_DEF.Switch1 = ((uint8)0U);
      swc_THSM_ARID_DEF.ptc3FaultStatus_MODE = false;
    }

    /* End of Disable for SubSystem: '<S13>/ptc3FaultStatus' */

    /* Disable for SignalConversion generated from: '<S13>/thmd_st_acceRlyVoltSamSwitch' incorporates:
     *  Outport: '<S13>/thmd_st_acceRlyVoltSamSwitch'
     */
    swc_THSM_ARID_DEF.OutportBufferForthmd_st_acceRly = ((uint8)3U);

    /* Disable for SignalConversion generated from: '<S13>/thmd_st_ptc3ConnStsFb' incorporates:
     *  Outport: '<S13>/thmd_st_ptc3ConnStsFb'
     */
    thmd_st_ptc3ConnStsFb = ((uint8)3U);

    /* Disable for SignalConversion generated from: '<S13>/thmd_st_ptc3RlyFlt' incorporates:
     *  Outport: '<S13>/thmd_st_ptc3RlyFlt'
     */
    thmd_st_ptc3RlyFlt = ((uint8)0U);
    swc_THSM_ARID_DEF.ptc3FaultStatusControl_MODE = false;
  }

  /* End of Logic: '<S2>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S2>/ptc3FaultStatusControl' */

  /* Outputs for Enabled SubSystem: '<S14>/ptc1FaultStatus' incorporates:
   *  EnablePort: '<S207>/Enable'
   */
  /* Logic: '<S14>/Logical Operator1' incorporates:
   *  Constant: '<S207>/Constant3'
   *  Constant: '<S207>/Constant4'
   *  Constant: '<S207>/Constant7'
   *  Constant: '<S207>/Constant8'
   */
  if (!swc_THSM_ARID_DEF.DataTypeConversion154) {
    if (!swc_THSM_ARID_DEF.ptc1FaultStatus_MODE) {
      /* SystemReset for Atomic SubSystem: '<S207>/turnON_delay' */
      swc_THSM_turnON_delay_Reset(&rtb_flg_out_e,
        &swc_THSM_ARID_DEF.ARID_DEF_turnON_delay);

      /* End of SystemReset for SubSystem: '<S207>/turnON_delay' */

      /* SystemReset for Atomic SubSystem: '<S207>/turnON_delay1' */
      swc_THSM_turnON_delay_Reset(&rtb_flg_out,
        &swc_THSM_ARID_DEF.ARID_DEF_turnON_delay1);

      /* End of SystemReset for SubSystem: '<S207>/turnON_delay1' */
      swc_THSM_ARID_DEF.ptc1FaultStatus_MODE = true;
    }

    /* RelationalOperator: '<S207>/Relational Operator' incorporates:
     *  Gain: '<S207>/Gain'
     */
    rtb_RelationalOperator_bx = (swc_THSM_ARID_DEF.DataTypeConversion152 >= 0.8 *
      swc_THSM_ARID_DEF.DataTypeConversion150);

    /* Logic: '<S207>/Logical Operator' */
    rtb_LogicalOperator_n = !rtb_RelationalOperator_bx;

    /* Switch: '<S207>/Switch' */
    if (rtb_RelationalOperator_bx) {
      /* Switch: '<S207>/Switch' incorporates:
       *  Constant: '<S207>/Constant1'
       */
      thmd_st_ptcConnStsFb = ((uint8)1U);
    } else {
      /* Switch: '<S207>/Switch' incorporates:
       *  Constant: '<S207>/Constant2'
       */
      thmd_st_ptcConnStsFb = ((uint8)0U);
    }

    /* End of Switch: '<S207>/Switch' */

    /* Outputs for Atomic SubSystem: '<S207>/turnON_delay' */
    swc_THSM_turnON_delay(rtb_LogicalOperator_n, thmc_tm_ptcVoltFaultThr_s,
                          ((float32)THM_TASK_INTERVAL_S), &rtb_flg_out_e,
                          &swc_THSM_ARID_DEF.ARID_DEF_turnON_delay);

    /* End of Outputs for SubSystem: '<S207>/turnON_delay' */

    /* Outputs for Atomic SubSystem: '<S207>/turnON_delay1' */
    swc_THSM_turnON_delay(rtb_RelationalOperator_bx, thmc_tm_ptcVoltFaultThr1_s,
                          ((float32)THM_TASK_INTERVAL_S), &rtb_flg_out,
                          &swc_THSM_ARID_DEF.ARID_DEF_turnON_delay1);

    /* End of Outputs for SubSystem: '<S207>/turnON_delay1' */

    /* Switch: '<S207>/Switch1' incorporates:
     *  Constant: '<S207>/Constant3'
     *  Constant: '<S207>/Constant4'
     *  Constant: '<S207>/Constant7'
     *  Constant: '<S207>/Constant8'
     *  Switch: '<S207>/Switch3'
     */
    if (thmd_b_ptcHWEnbFlg) {
      /* Switch: '<S207>/Switch2' */
      if (rtb_flg_out_e) {
        /* Switch: '<S207>/Switch1' incorporates:
         *  Constant: '<S207>/Constant5'
         */
        thmd_st_ptcRlyFlt = ((uint8)1U);
      } else {
        /* Switch: '<S207>/Switch1' incorporates:
         *  Constant: '<S207>/Constant6'
         */
        thmd_st_ptcRlyFlt = ((uint8)0U);
      }

      /* End of Switch: '<S207>/Switch2' */
    } else if (rtb_flg_out) {
      /* Switch: '<S207>/Switch3' incorporates:
       *  Constant: '<S207>/Constant9'
       *  Switch: '<S207>/Switch1'
       */
      thmd_st_ptcRlyFlt = ((uint8)2U);
    } else {
      /* Switch: '<S207>/Switch1' incorporates:
       *  Constant: '<S207>/Constant10'
       *  Switch: '<S207>/Switch3'
       */
      thmd_st_ptcRlyFlt = ((uint8)0U);
    }

    /* End of Switch: '<S207>/Switch1' */
  } else if (swc_THSM_ARID_DEF.ptc1FaultStatus_MODE) {
    /* Disable for Switch: '<S207>/Switch' incorporates:
     *  Outport: '<S207>/thmd_st_ptcConnStsFb'
     */
    thmd_st_ptcConnStsFb = ((uint8)3U);

    /* Disable for Switch: '<S207>/Switch1' incorporates:
     *  Outport: '<S207>/thmd_st_ptcRlyFlt'
     */
    thmd_st_ptcRlyFlt = ((uint8)0U);
    swc_THSM_ARID_DEF.ptc1FaultStatus_MODE = false;
  }

  /* End of Logic: '<S14>/Logical Operator1' */
  /* End of Outputs for SubSystem: '<S14>/ptc1FaultStatus' */

  /* SignalConversion generated from: '<S2>/thmd_n_MHGVTgt_PCT' */
  swc_THSM_ARID_DEF.OutportBufferForthmd_n_MHGVTgt_ = 0.0;

  /* SignalConversion generated from: '<S2>/thmd_n_FWFVTgt_PCT' */
  swc_THSM_ARID_DEF.OutportBufferForthmd_n_FWFVTgt_ = 0.0;

  /* SignalConversion generated from: '<S2>/thmd_b_ActiveCool_flg' */
  swc_THSM_ARID_DEF.OutportBufferForthmd_b_ActiveCo = 0.0;

  /* SignalConversion generated from: '<S2>/thmd_b_BalanceHeat_flg' */
  swc_THSM_ARID_DEF.OutportBufferForthmd_b_BalanceH = 0.0;

  /* SignalConversion generated from: '<S2>/thmd_b_PassHeat_flg' */
  swc_THSM_ARID_DEF.OutportBufferForthmd_b_PassHeat = 0.0;

  /* SignalConversion generated from: '<S2>/thmd_b_hvbDeft' */
  swc_THSM_ARID_DEF.OutportBufferForthmd_b_hvbDeft = 0.0;

  /* SignalConversion generated from: '<S2>/thmd_b_iptcHtIpuResvHt' */
  swc_THSM_ARID_DEF.OutportBufferForthmd_b_iptcHtIp = 0.0;

  /* SignalConversion generated from: '<S2>/thmd_b_iptcHtIpuCl' */
  swc_THSM_ARID_DEF.OutportBufferForthmd_b_iptcHt_h = 0.0;

  /* SignalConversion generated from: '<S2>/thmd_b_ipuResvHt' */
  swc_THSM_ARID_DEF.OutportBufferForthmd_b_ipuResvH = 0.0;

  /* SignalConversion generated from: '<S2>/thmd_b_ipuSupHtIptcHt' */
  swc_THSM_ARID_DEF.OutportBufferForthmd_b_ipuSupHt = 0.0;

  /* SignalConversion generated from: '<S2>/thmd_b_ipuHeatEnableFlg' */
  swc_THSM_ARID_DEF.OutportBufferForthmd_b_ipuHeatE = 0.0;

  /* SignalConversion generated from: '<S2>/thmd_pwr_ipuHeatPwrAllwd_kW' */
  swc_THSM_ARID_DEF.OutportBufferForthmd_pwr_ipuHea = 0.0;

  /* Update for UnitDelay: '<S21>/Delay Input1'
   *
   * Block description for '<S21>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_THSM_ARID_DEF.DelayInput1_DSTATE = rtb_LogicalOperator;

  /* Update for UnitDelay: '<S22>/Delay Input1'
   *
   * Block description for '<S22>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_THSM_ARID_DEF.DelayInput1_DSTATE_k = rtb_LogicalOperator;

  /* Update for UnitDelay: '<S20>/Unit Delay' */
  swc_THSM_ARID_DEF.UnitDelay_DSTATE = rtb_Switch;

  /* Update for UnitDelay: '<S144>/Delay Input1'
   *
   * Block description for '<S144>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_THSM_ARID_DEF.DelayInput1_DSTATE_i =
    swc_THSM_ARID_DEF.DataTypeConversion22;

  /* Update for Delay: '<S147>/Delay One Step1' */
  swc_THSM_ARID_DEF.icLoad = false;
  swc_THSM_ARID_DEF.DelayOneStep1_DSTATE_m = thmd_n_pmp1NewTgtSpd_pct;

  /* Update for UnitDelay: '<S151>/Delay Input1'
   *
   * Block description for '<S151>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_THSM_ARID_DEF.DelayInput1_DSTATE_j = rtb_LogicalOperator2_f;

  /* Update for Delay: '<S148>/Delay One Step1' */
  swc_THSM_ARID_DEF.icLoad_n = false;
  swc_THSM_ARID_DEF.DelayOneStep1_DSTATE_j = thmd_n_pmp2TgtSpdAirCl_pct;

  /* Update for UnitDelay: '<S158>/Delay Input1'
   *
   * Block description for '<S158>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_THSM_ARID_DEF.DelayInput1_DSTATE_n = rtb_Relay4_g;

  /* Update for UnitDelay: '<S172>/Unit Delay2' */
  swc_THSM_ARID_DEF.UnitDelay2_DSTATE = swc_THSM_ARID_DEF.DataTypeConversion21;

  /* Update for UnitDelay: '<S164>/Unit Delay1' */
  swc_THSM_ARID_DEF.UnitDelay1_DSTATE = rtb_t_delay_off_f;

  /* Update for UnitDelay: '<S164>/Unit Delay' */
  swc_THSM_ARID_DEF.UnitDelay_DSTATE_k = swc_THSM_ARID_DEF.DataTypeConversion33;

  /* Update for UnitDelay: '<S167>/Unit Delay3' */
  swc_THSM_ARID_DEF.UnitDelay3_DSTATE_p = rtb_Switch1;

  /* Update for UnitDelay: '<S167>/Unit Delay2' */
  swc_THSM_ARID_DEF.UnitDelay2_DSTATE_n = swc_THSM_ARID_DEF.DataTypeConversion11;

  /* Update for UnitDelay: '<S162>/Unit Delay1' */
  swc_THSM_ARID_DEF.UnitDelay1_DSTATE_a = rtb_Relay3;

  /* Update for UnitDelay: '<S162>/Unit Delay' */
  swc_THSM_ARID_DEF.UnitDelay_DSTATE_m = swc_THSM_ARID_DEF.DataTypeConversion33;

  /* Update for UnitDelay: '<S165>/Unit Delay3' */
  swc_THSM_ARID_DEF.UnitDelay3_DSTATE_d = rtb_Relay4;

  /* Update for UnitDelay: '<S165>/Unit Delay2' */
  swc_THSM_ARID_DEF.UnitDelay2_DSTATE_p = swc_THSM_ARID_DEF.DataTypeConversion11;

  /* Update for UnitDelay: '<S168>/Unit Delay5' */
  swc_THSM_ARID_DEF.UnitDelay5_DSTATE = rtb_Switch3_a;

  /* Update for UnitDelay: '<S168>/Unit Delay4' */
  swc_THSM_ARID_DEF.UnitDelay4_DSTATE = swc_THSM_ARID_DEF.DataTypeConversion27;

  /* Update for UnitDelay: '<S170>/Unit Delay7' */
  swc_THSM_ARID_DEF.UnitDelay7_DSTATE = rtb_Switch3_ig;

  /* Update for UnitDelay: '<S170>/Unit Delay6' */
  swc_THSM_ARID_DEF.UnitDelay6_DSTATE = swc_THSM_ARID_DEF.DataTypeConversion31;

  /* Update for UnitDelay: '<S173>/Unit Delay3' */
  swc_THSM_ARID_DEF.UnitDelay3_DSTATE_n = rtb_Switch3_pp;

  /* Update for UnitDelay: '<S173>/Unit Delay2' */
  swc_THSM_ARID_DEF.UnitDelay2_DSTATE_c = swc_THSM_ARID_DEF.DataTypeConversion21;

  /* Update for UnitDelay: '<S163>/Unit Delay1' */
  swc_THSM_ARID_DEF.UnitDelay1_DSTATE_h = rtb_Switch3_p;

  /* Update for UnitDelay: '<S163>/Unit Delay' */
  swc_THSM_ARID_DEF.UnitDelay_DSTATE_b = swc_THSM_ARID_DEF.DataTypeConversion33;

  /* Update for UnitDelay: '<S166>/Unit Delay3' */
  swc_THSM_ARID_DEF.UnitDelay3_DSTATE_b = rtb_Switch3_hw;

  /* Update for UnitDelay: '<S166>/Unit Delay2' */
  swc_THSM_ARID_DEF.UnitDelay2_DSTATE_i = swc_THSM_ARID_DEF.DataTypeConversion11;

  /* Update for UnitDelay: '<S169>/Unit Delay5' */
  swc_THSM_ARID_DEF.UnitDelay5_DSTATE_g = rtb_Switch3_cu;

  /* Update for UnitDelay: '<S169>/Unit Delay4' */
  swc_THSM_ARID_DEF.UnitDelay4_DSTATE_g = swc_THSM_ARID_DEF.DataTypeConversion27;

  /* Update for UnitDelay: '<S171>/Unit Delay7' */
  swc_THSM_ARID_DEF.UnitDelay7_DSTATE_o = rtb_Switch3_g;

  /* Update for UnitDelay: '<S171>/Unit Delay6' */
  swc_THSM_ARID_DEF.UnitDelay6_DSTATE_g = swc_THSM_ARID_DEF.DataTypeConversion31;

  /* Update for UnitDelay: '<S174>/Unit Delay3' */
  swc_THSM_ARID_DEF.UnitDelay3_DSTATE_p1 = rtb_Switch1_gh;

  /* Update for UnitDelay: '<S174>/Unit Delay2' */
  swc_THSM_ARID_DEF.UnitDelay2_DSTATE_o = swc_THSM_ARID_DEF.DataTypeConversion21;
}

/* Model step function */
void swc_THSM_Step(void)
{
  /* local block i/o variables */
  float32 rtb_DataTypeConversion23;
  float32 rtb_DataTypeConversion14;
  float32 rtb_DataTypeConversion44;
  float32 rtb_DataTypeConversion45;
  float32 rtb_DataTypeConversion46;
  float32 tmp;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Inport generated from: '<Root>/BusElementIn1'
   */
  swc_THSM_ARID_DEF.DataTypeConversion1 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_st_flg2FctCfgVehTyp();

  /* DataTypeConversion: '<Root>/Data Type Conversion11' incorporates:
   *  Inport generated from: '<Root>/In Bus Element3'
   */
  swc_THSM_ARID_DEF.DataTypeConversion11 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_dccd_t_dcdcTemp_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion27' incorporates:
   *  Inport generated from: '<Root>/In Bus Element12'
   */
  swc_THSM_ARID_DEF.DataTypeConversion27 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_eadd_t_inv2Temp_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion31' incorporates:
   *  Inport generated from: '<Root>/In Bus Element13'
   */
  swc_THSM_ARID_DEF.DataTypeConversion31 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_eadd_t_mot2Temp_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion21' incorporates:
   *  Inport generated from: '<Root>/In Bus Element15'
   */
  swc_THSM_ARID_DEF.DataTypeConversion21 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_obcd_t_obcTemp_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion22' incorporates:
   *  Inport generated from: '<Root>/In Bus Element16'
   */
  swc_THSM_ARID_DEF.DataTypeConversion22 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_pmmd_b_ignOn();

  /* DataTypeConversion: '<Root>/Data Type Conversion23' incorporates:
   *  Inport generated from: '<Root>/In Bus Element17'
   */
  rtb_DataTypeConversion23 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_accd_u_acPresVolt_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion29' incorporates:
   *  Inport generated from: '<Root>/In Bus Element52'
   */
  swc_THSM_ARID_DEF.DataTypeConversion29 =
    Rte_IRead_swc_THSM_Step_vcsb_HVSM_obcd_b_chargerPlugged();

  /* DataTypeConversion: '<Root>/Data Type Conversion25' incorporates:
   *  Inport generated from: '<Root>/In Bus Element55'
   */
  swc_THSM_ARID_DEF.DataTypeConversion25 =
    Rte_IRead_swc_THSM_Step_vcsb_HVSM_hvbd_e_PmmStatus();

  /* DataTypeConversion: '<Root>/Data Type Conversion39' incorporates:
   *  Inport generated from: '<Root>/In Bus Element19'
   */
  swc_THSM_ARID_DEF.DataTypeConversion39 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_vscd_v_vehSpd_kph();

  /* DataTypeConversion: '<Root>/Data Type Conversion33' incorporates:
   *  Inport generated from: '<Root>/In Bus Element22'
   */
  swc_THSM_ARID_DEF.DataTypeConversion33 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_macd_t_ts5SnsrTemp_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion34' incorporates:
   *  Inport generated from: '<Root>/In Bus Element23'
   */
  swc_THSM_ARID_DEF.DataTypeConversion34 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_hvbd_st_hvbThermMngReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion35' incorporates:
   *  Inport generated from: '<Root>/In Bus Element24'
   */
  swc_THSM_ARID_DEF.DataTypeConversion35 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_accd_st_cbnThermMngReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion14' incorporates:
   *  Inport generated from: '<Root>/In Bus Element8'
   */
  rtb_DataTypeConversion14 = Rte_IRead_swc_THSM_Step_vcib_VCIP_hvbd_t_hvbTemp_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion44' incorporates:
   *  Inport generated from: '<Root>/In Bus Element34'
   */
  rtb_DataTypeConversion44 = Rte_IRead_swc_THSM_Step_vcib_VCIP_hvbd_t_hvbMin_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion45' incorporates:
   *  Inport generated from: '<Root>/In Bus Element35'
   */
  rtb_DataTypeConversion45 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_hvbd_t_hvbInCoolTemp_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion46' incorporates:
   *  Inport generated from: '<Root>/In Bus Element36'
   */
  rtb_DataTypeConversion46 = Rte_IRead_swc_THSM_Step_vcib_VCIP_accd_t_ambTemp_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion65' incorporates:
   *  Inport generated from: '<Root>/In Bus Element50'
   */
  swc_THSM_ARID_DEF.DataTypeConversion65 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_hvbd_b_hvbHeatEnad();

  /* DataTypeConversion: '<Root>/Data Type Conversion111' incorporates:
   *  Inport generated from: '<Root>/In Bus Element1'
   */
  swc_THSM_ARID_DEF.DataTypeConversion111 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw();

  /* DataTypeConversion: '<Root>/Data Type Conversion62' incorporates:
   *  Inport generated from: '<Root>/In Bus Element57'
   */
  swc_THSM_ARID_DEF.DataTypeConversion62 =
    Rte_IRead_swc_THSM_Step_vcsb_VOMM_drid_e_gearLvrPos();

  /* DataTypeConversion: '<Root>/Data Type Conversion64' incorporates:
   *  Inport generated from: '<Root>/In Bus Element59'
   */
  swc_THSM_ARID_DEF.DataTypeConversion64 =
    Rte_IRead_swc_THSM_Step_vcsb_VOMM_pmmd_b_pwrHoldReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion118' incorporates:
   *  Inport generated from: '<Root>/In Bus Element68'
   */
  swc_THSM_ARID_DEF.DataTypeConversion118 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_brpd_e_brkPedalStatus();

  /* DataTypeConversion: '<Root>/Data Type Conversion120' incorporates:
   *  Inport generated from: '<Root>/In Bus Element71'
   */
  swc_THSM_ARID_DEF.DataTypeConversion120 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_accd_n_acFanReqSpd_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion40' incorporates:
   *  Inport generated from: '<Root>/In Bus Element30'
   */
  thmd_b_accmEnaCnd3 = (Rte_IRead_swc_THSM_Step_vcib_VCIP_dccd_st_12vDcdcModAct()
                        != 0);

  /* DataTypeConversion: '<Root>/Data Type Conversion138' incorporates:
   *  Inport generated from: '<Root>/BusElementIn7'
   */
  swc_THSM_ARID_DEF.DataTypeConversion138 =
    Rte_IRead_swc_THSM_Step_vcsb_EGYM_egmd_b_ptcEnbAllowFlg();

  /* DataTypeConversion: '<Root>/Data Type Conversion139' incorporates:
   *  Inport generated from: '<Root>/In Bus Element70'
   */
  swc_THSM_ARID_DEF.DataTypeConversion139 =
    Rte_IRead_swc_THSM_Step_vcsb_VBSW_vbsd_b_vbsShtDwnHVReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion140' incorporates:
   *  Inport generated from: '<Root>/BusElementIn11'
   */
  swc_THSM_ARID_DEF.DataTypeConversion140 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_st_flgFctCfgFan();

  /* DataTypeConversion: '<Root>/Data Type Conversion144' incorporates:
   *  Inport generated from: '<Root>/BusElementIn12'
   */
  swc_THSM_ARID_DEF.DataTypeConversion144 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_u_hvbCooltInSnsr_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion145' incorporates:
   *  Inport generated from: '<Root>/BusElementIn13'
   */
  swc_THSM_ARID_DEF.DataTypeConversion145 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_u_hvbCooltOutSnsr_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion146' incorporates:
   *  Inport generated from: '<Root>/BusElementIn14'
   */
  swc_THSM_ARID_DEF.DataTypeConversion146 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_accd_e_PtcSt();

  /* DataTypeConversion: '<Root>/Data Type Conversion147' incorporates:
   *  Inport generated from: '<Root>/BusElementIn15'
   */
  swc_THSM_ARID_DEF.DataTypeConversion147 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_accd_st_iptWorkSt();

  /* DataTypeConversion: '<Root>/Data Type Conversion148' incorporates:
   *  Inport generated from: '<Root>/BusElementIn16'
   */
  swc_THSM_ARID_DEF.DataTypeConversion148 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_accd_st_ptcWorkStRear();

  /* DataTypeConversion: '<Root>/Data Type Conversion143' incorporates:
   *  Inport generated from: '<Root>/BusElementIn10'
   */
  swc_THSM_ARID_DEF.DataTypeConversion143 =
    Rte_IRead_swc_THSM_Step_vcsb_EGYM_egmd_b_ptcRearEnbAllowFlg();

  /* DataTypeConversion: '<Root>/Data Type Conversion149' incorporates:
   *  Inport generated from: '<Root>/BusElementIn17'
   */
  swc_THSM_ARID_DEF.DataTypeConversion149 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_u_TS5sensorFb_mV();

  /* DataTypeConversion: '<Root>/Data Type Conversion151' incorporates:
   *  Inport generated from: '<Root>/BusElementIn18'
   */
  swc_THSM_ARID_DEF.DataTypeConversion151 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_st_flgFctCfgAccy();

  /* DataTypeConversion: '<Root>/Data Type Conversion152' incorporates:
   *  Inport generated from: '<Root>/BusElementIn19'
   */
  swc_THSM_ARID_DEF.DataTypeConversion152 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_u_hcmPtcRlyVolt();

  /* DataTypeConversion: '<Root>/Data Type Conversion153' incorporates:
   *  Inport generated from: '<Root>/BusElementIn20'
   */
  swc_THSM_ARID_DEF.DataTypeConversion153 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_u_hcmAcceRlyVolt();

  /* DataTypeConversion: '<Root>/Data Type Conversion154' incorporates:
   *  Inport generated from: '<Root>/BusElementIn21'
   */
  swc_THSM_ARID_DEF.DataTypeConversion154 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_b_hcmPtcRlyVoltVldSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion155' incorporates:
   *  Inport generated from: '<Root>/BusElementIn22'
   */
  swc_THSM_ARID_DEF.DataTypeConversion155 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion150' incorporates:
   *  Inport generated from: '<Root>/BusElementIn24'
   */
  swc_THSM_ARID_DEF.DataTypeConversion150 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_u_ipuHVBusVolt_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Inport generated from: '<Root>/BusElementIn2'
   */
  swc_THSM_ARID_DEF.DataTypeConversion2 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_t_hvbSetTgtTemp_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Inport generated from: '<Root>/BusElementIn3'
   */
  swc_THSM_ARID_DEF.DataTypeConversion3 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_t_acwpOutptTemp_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion12' incorporates:
   *  Inport generated from: '<Root>/BusElementIn4'
   */
  swc_THSM_ARID_DEF.DataTypeConversion12 =
    Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_b_flgFctCfgBatCol();

  /* DataTypeConversion: '<Root>/Data Type Conversion15' incorporates:
   *  Inport generated from: '<Root>/vcsb_DIAG_in12'
   */
  swc_THSM_ARID_DEF.DataTypeConversion15 =
    Rte_IRead_swc_THSM_Step_vcsb_DIAG_digd_b_vehCrashFltLvl33();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/THM_ThermalControl'
   */
  swc_THSM_THM_ThermalControl();

  /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator' */

  /* Outport generated from: '<Root>/Out Bus Element3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion6'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_afterRunActive(thmd_b_afterRunActive);

  /* Outport generated from: '<Root>/Out Bus Element4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_fanRly1Req(thmd_b_fanRly1Req);

  /* Outport generated from: '<Root>/Out Bus Element5' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion72'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_fanRly2Req(thmd_b_fanRly2Req);

  /* Outport generated from: '<Root>/Out Bus Element6' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_wtrPmpRly1Req(thmd_b_wtrPmpRly1Req);

  /* Outport generated from: '<Root>/Out Bus Element7' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion8'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_wtrPmpRly2Req(thmd_b_wtrPmpRly2Req);

  /* Outport generated from: '<Root>/Out Bus Element11' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion76'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_n_fan1TgtSpd_pct
    (swc_THSM_ARID_DEF.thmd_n_fan1TgtSpd_pct_b);

  /* Outport generated from: '<Root>/Out Bus Element12' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion78'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_n_pmp1TgtSpd_pct
    (thmd_n_pmp1SwapTgtSpd_pct);

  /* Outport generated from: '<Root>/Out Bus Element13' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion77'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_n_pmp2TgtSpd_pct
    (thmd_n_pmp2TgtSpdAirCl_pct);

  /* Outport generated from: '<Root>/Out Bus Element17' */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_TwoWayVlvReq
    (swc_THSM_ConstB.DataTypeConversion83);

  /* Outport generated from: '<Root>/Out Bus Element18' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion84'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_n_fan2TgtSpd_pct
    (swc_THSM_ARID_DEF.thmd_n_fan2TgtSpd_pct);

  /* Outport generated from: '<Root>/Out Bus Element19' */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_fan2Ena
    (swc_THSM_ConstB.DataTypeConversion85);

  /* Outport generated from: '<Root>/Out Bus Element20' */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_tv4V2
    (swc_THSM_ConstB.DataTypeConversion86);

  /* Outport generated from: '<Root>/Out Bus Element21' */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_tv4V3
    (swc_THSM_ConstB.DataTypeConversion88);

  /* Outport generated from: '<Root>/Out Bus Element23' */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_st_tv4
    (swc_THSM_ConstB.DataTypeConversion90);

  /* Outport generated from: '<Root>/Out Bus Element24' */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_tv1V2
    (swc_THSM_ConstB.DataTypeConversion89);

  /* Outport generated from: '<Root>/Out Bus Element25' */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_tv1V3
    (swc_THSM_ConstB.DataTypeConversion96);

  /* Outport generated from: '<Root>/Out Bus Element27' */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_tv2V2
    (swc_THSM_ConstB.DataTypeConversion91);

  /* Outport generated from: '<Root>/Out Bus Element28' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion92'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_heaterEna(thmd_b_ptcCanEnbFlg);

  /* Outport generated from: '<Root>/Out Bus Element33' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion97'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_accmEnb(thmd_b_accmEnb);

  /* Outport generated from: '<Root>/Out Bus Element40' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion107'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_wtrPmp1CtrlEnabled
    (thmd_b_wtrPmp1CtrlEnabled);

  /* Outport generated from: '<Root>/Out Bus Element41' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion102'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_wtrPmp2CtrlEnabled
    (thmd_b_wtrPmp2CtrlEnabled);

  /* Outport generated from: '<Root>/Out Bus Element43' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion109'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_n_MHGVTgt_pct((float32)
    swc_THSM_ARID_DEF.OutportBufferForthmd_n_MHGVTgt_);

  /* Outport generated from: '<Root>/Out Bus Element44' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion110'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_n_FWFVTgt_pct((float32)
    swc_THSM_ARID_DEF.OutportBufferForthmd_n_FWFVTgt_);

  /* Outport generated from: '<Root>/Out Bus Element45' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion112'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_PassCool_flg
    (swc_THSM_ARID_DEF.OutportBufferForthmd_b_PassCool != 0.0);

  /* Outport generated from: '<Root>/Out Bus Element46' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion116'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_ActiveCool_flg
    (swc_THSM_ARID_DEF.OutportBufferForthmd_b_ActiveCo != 0.0);

  /* Outport generated from: '<Root>/Out Bus Element47' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion117'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_BalanceHeat_flg
    (swc_THSM_ARID_DEF.OutportBufferForthmd_b_BalanceH != 0.0);

  /* Outport generated from: '<Root>/Out Bus Element48' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion119'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_PassHeat_flg
    (swc_THSM_ARID_DEF.OutportBufferForthmd_b_PassHeat != 0.0);

  /* Outport generated from: '<Root>/Out Bus Element51' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion128'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_q_pmp2FlowFeedback((float32)
    swc_THSM_ARID_DEF.OutportBufferForthmd_q_pmp2Flow);

  /* Outport generated from: '<Root>/Out Bus Element52' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion129'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_hvbDeft
    (swc_THSM_ARID_DEF.OutportBufferForthmd_b_hvbDeft != 0.0);

  /* Outport generated from: '<Root>/Out Bus Element53' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion130'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_iptcHtIpuResvHt
    (swc_THSM_ARID_DEF.OutportBufferForthmd_b_iptcHtIp != 0.0);

  /* Outport generated from: '<Root>/Out Bus Element54' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion131'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_iptcHtIpuCl
    (swc_THSM_ARID_DEF.OutportBufferForthmd_b_iptcHt_h != 0.0);

  /* Outport generated from: '<Root>/Out Bus Element56' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion132'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_ipuResvHt
    (swc_THSM_ARID_DEF.OutportBufferForthmd_b_ipuResvH != 0.0);

  /* Outport generated from: '<Root>/Out Bus Element55' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion133'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_ipuSupHtIptcHt
    (swc_THSM_ARID_DEF.OutportBufferForthmd_b_ipuSupHt != 0.0);

  /* Outport generated from: '<Root>/Out Bus Element57' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion135'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_ipuHeatEnableFlg
    (swc_THSM_ARID_DEF.OutportBufferForthmd_b_ipuHeatE != 0.0);

  /* Outport generated from: '<Root>/Out Bus Element58' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion136'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_pwr_ipuHeatPwrAllwd_kW((float32)
    swc_THSM_ARID_DEF.OutportBufferForthmd_pwr_ipuHea);

  /* Outport generated from: '<Root>/Out Bus Element49' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion141'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_heaterEna2(thmd_b_heaterEna2);

  /* Outport generated from: '<Root>/Out Bus Element50' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion142'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_heaterEna3(swc_THSM_ARID_DEF.flg_out);

  /* Outport generated from: '<Root>/Out Bus Element59' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion157'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_heaterEnaHW(thmd_b_ptcHWEnbFlg);

  /* Outport generated from: '<Root>/Out Bus Element60' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion158'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_heaterEna3HW
    (swc_THSM_ARID_DEF.flg_out_j);

  /* Outport generated from: '<Root>/Out Bus Element61' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion159'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_st_ptcRlyVoltSamSwitch
    (swc_THSM_ARID_DEF.OutportBufferForthmd_st_ptcRlyV);

  /* Outport generated from: '<Root>/Out Bus Element64' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion163'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_st_acceRlyVoltSamSwitch
    (swc_THSM_ARID_DEF.OutportBufferForthmd_st_acceRly);

  /* Outport generated from: '<Root>/Out Bus Element62' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion161'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_st_ptcConnStsFb(thmd_st_ptcConnStsFb);

  /* Outport generated from: '<Root>/Out Bus Element63' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion162'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_st_ptcRlyFlt(thmd_st_ptcRlyFlt);

  /* Outport generated from: '<Root>/Out Bus Element65' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion164'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_st_ptc3ConnStsFb(thmd_st_ptc3ConnStsFb);

  /* Outport generated from: '<Root>/Out Bus Element66' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion165'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_st_ptc3RlyFlt(thmd_st_ptc3RlyFlt);

  /* DataTypeConversion: '<Root>/Data Type Conversion10' */
  tmp = fmodf(floorf(swc_THSM_ARID_DEF.SignalConversion), 256.0F);

  /* Outport generated from: '<Root>/Out Bus Element8' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion10'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_st_acwpSpdReq((uint8)(tmp < 0.0F ?
    (sint32)(uint8)-(sint8)(uint8)-tmp : (sint32)(uint8)tmp));

  /* Outport generated from: '<Root>/Out Bus Element2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion9'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_t_acwpTemp_C(thmd_t_acwpTemp_C);

  /* Outport generated from: '<Root>/Out Bus Element1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   */
  Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_st_acwpHeat(thmd_st_acwpHeat);
}

/* Model initialize function */
void swc_THSM_Init(void)
{
  /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/THM_ThermalControl'
   */
  swc_THS_THM_ThermalControl_Init();

  /* End of SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

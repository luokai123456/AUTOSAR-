/*
 * File: swc_SCAP.c
 *
 * Code generated for Simulink model 'swc_SCAP'.
 *
 * Model version                  : 6.223
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Aug 14 10:27:28 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "swc_SCAP.h"
#include "rtwtypes.h"
#include <math.h>
#include "Rte_Type.h"
#include "const_ImportedDefine.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef EAD_TASK_INTERVAL_S
#error The value of parameter "EAD_TASK_INTERVAL_S" is not defined
#endif

#ifndef PTL_TASK_INTERVAL_S
#error The value of parameter "PTL_TASK_INTERVAL_S" is not defined
#endif

#ifndef PWR_ZERO
#error The value of parameter "PWR_ZERO" is not defined
#endif

#ifndef RPM_2_RADpS
#error The value of parameter "RPM_2_RADpS" is not defined
#endif

#ifndef TRQ_ZERO
#error The value of parameter "TRQ_ZERO" is not defined
#endif

#ifndef XX_2_kXX
#error The value of parameter "XX_2_kXX" is not defined
#endif

#ifndef kXX_2_XX
#error The value of parameter "kXX_2_XX" is not defined
#endif

/* Named constants for Chart: '<S20>/Chart' */
#define swc_SCAP_IN_NO_ACTIVE_CHILD    ((uint8)0U)
#define swc_SCAP_IN_U1                 ((uint8)1U)
#define swc_SCAP_IN_U1_TO_U2           ((uint8)2U)
#define swc_SCAP_IN_U1_TO_U2_DEC       ((uint8)1U)
#define swc_SCAP_IN_U1_TO_U2_INC       ((uint8)2U)
#define swc_SCAP_IN_U2                 ((uint8)3U)
#define swc_SCAP_IN_U2_TO_U1           ((uint8)4U)
#define swc_SCAP_IN_U2_TO_U1_DEC       ((uint8)1U)
#define swc_SCAP_IN_U2_TO_U1_INC       ((uint8)2U)

/* Named constants for Chart: '<S22>/Chart' */
#define swc_SCAP_IN_NO_ACTIVE_CHILD_m  ((uint8)0U)
#define swc_SCAP_IN_U1_TO_U2_DEC_g     ((uint8)1U)
#define swc_SCAP_IN_U1_TO_U2_INC_c     ((uint8)2U)
#define swc_SCAP_IN_U1_TO_U2_p         ((uint8)2U)
#define swc_SCAP_IN_U1_m               ((uint8)1U)
#define swc_SCAP_IN_U2_TO_U1_DEC_k     ((uint8)1U)
#define swc_SCAP_IN_U2_TO_U1_INC_k     ((uint8)2U)
#define swc_SCAP_IN_U2_TO_U1_b         ((uint8)4U)
#define swc_SCAP_IN_U2_m               ((uint8)3U)

/* Named constants for Chart: '<S24>/Chart' */
#define swc_SCAP_IN_NO_ACTIVE_CHILD_n  ((uint8)0U)
#define swc_SCAP_IN_U1_TO_U2_DEC_e     ((uint8)1U)
#define swc_SCAP_IN_U1_TO_U2_INC_f     ((uint8)2U)
#define swc_SCAP_IN_U1_TO_U2_d         ((uint8)2U)
#define swc_SCAP_IN_U1_h               ((uint8)1U)
#define swc_SCAP_IN_U2_TO_U1_DEC_c     ((uint8)1U)
#define swc_SCAP_IN_U2_TO_U1_INC_i     ((uint8)2U)
#define swc_SCAP_IN_U2_TO_U1_a         ((uint8)4U)
#define swc_SCAP_IN_U2_p               ((uint8)3U)

/* Named constants for Chart: '<S26>/Chart' */
#define swc_SCAP_IN_NO_ACTIVE_CHILD_h  ((uint8)0U)
#define swc_SCAP_IN_U1_TO_U2_DEC_l     ((uint8)1U)
#define swc_SCAP_IN_U1_TO_U2_INC_l     ((uint8)2U)
#define swc_SCAP_IN_U1_TO_U2_i         ((uint8)2U)
#define swc_SCAP_IN_U1_c               ((uint8)1U)
#define swc_SCAP_IN_U2_TO_U1_DEC_ca    ((uint8)1U)
#define swc_SCAP_IN_U2_TO_U1_INC_ki    ((uint8)2U)
#define swc_SCAP_IN_U2_TO_U1_p         ((uint8)4U)
#define swc_SCAP_IN_U2_k               ((uint8)3U)

/* Named constants for Chart: '<S39>/Chart' */
#define swc_SCAP_IN_NO_ACTIVE_CHILD_i  ((uint8)0U)
#define swc_SCAP_IN_U1_TO_U2_DEC_ge    ((uint8)1U)
#define swc_SCAP_IN_U1_TO_U2_INC_j     ((uint8)2U)
#define swc_SCAP_IN_U1_TO_U2_n         ((uint8)2U)
#define swc_SCAP_IN_U1_p               ((uint8)1U)
#define swc_SCAP_IN_U2_TO_U1_DEC_l     ((uint8)1U)
#define swc_SCAP_IN_U2_TO_U1_INC_b     ((uint8)2U)
#define swc_SCAP_IN_U2_TO_U1_f         ((uint8)4U)
#define swc_SCAP_IN_U2_i               ((uint8)3U)

/* Named constants for Chart: '<S76>/Chart' */
#define swc_SCAP_IN_NO_ACTIVE_CHILD_l  ((uint8)0U)
#define swc_SCAP_IN_U1_TO_U2_DEC_a     ((uint8)1U)
#define swc_SCAP_IN_U1_TO_U2_INC_o     ((uint8)2U)
#define swc_SCAP_IN_U1_TO_U2_a         ((uint8)2U)
#define swc_SCAP_IN_U1_me              ((uint8)1U)
#define swc_SCAP_IN_U2_TO_U1_DEC_m     ((uint8)1U)
#define swc_SCAP_IN_U2_TO_U1_INC_e     ((uint8)2U)
#define swc_SCAP_IN_U2_TO_U1_m         ((uint8)4U)
#define swc_SCAP_IN_U2_b               ((uint8)3U)

/* Named constants for Chart: '<S123>/Chart' */
#define swc_SCAP_IN_NO_ACTIVE_CHILD_c  ((uint8)0U)
#define swc_SCAP_IN_U1_TO_U2_DEC_b     ((uint8)1U)
#define swc_SCAP_IN_U1_TO_U2_INC_h     ((uint8)2U)
#define swc_SCAP_IN_U1_TO_U2_dc        ((uint8)2U)
#define swc_SCAP_IN_U1_g               ((uint8)1U)
#define swc_SCAP_IN_U2_TO_U1_DEC_f     ((uint8)1U)
#define swc_SCAP_IN_U2_TO_U1_INC_bv    ((uint8)2U)
#define swc_SCAP_IN_U2_TO_U1_bs        ((uint8)4U)
#define swc_SCAP_IN_U2_l               ((uint8)3U)

/* Named constants for Chart: '<S38>/timed_delay' */
#define swc_SCAP_IN_OFF                ((uint8)1U)
#define swc_SCAP_IN_ON                 ((uint8)2U)
#define swc_SCAP_IN_ON_WAIT            ((uint8)3U)

/* Named constants for Chart: '<S86>/timed_delay' */
#define swc_SCAP_IN_OFF_p              ((uint8)1U)
#define swc_SCAP_IN_ON_WAIT_k          ((uint8)3U)
#define swc_SCAP_IN_ON_p               ((uint8)2U)

/* Exported data definition */
#define swc_SCAP_START_SEC_CONST_VOLATILE
#include "swc_SCAP_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_CAL */
const volatile boolean eadc_b_disMot2BrkTqDurgESP = true;/* Referenced by: '<S7>/Constant3' */

/* Disable Secondary EAD Braking Torque during ESP Intervention */
const volatile boolean eadc_b_disMot2BstTqDurgESP = true;/* Referenced by: '<S7>/Constant1' */

/* Disable Secondary EAD Boosting Torque during ESP Intervention */
const volatile boolean eadc_b_disMot2TqInGear0 = true;/* Referenced by: '<S7>/Constant4' */

/* Disable Secondary EAD Torque when actual gear is 0 */
const volatile boolean eadc_b_enaMot2GenGearR = false;/* Referenced by: '<S7>/Constant6' */

/* Enable Secondary EAD generation in gear R */
const volatile boolean eadc_b_enaMot2GenInEVGearR = false;/* Referenced by: '<S7>/Constant7' */

/* Enable Secondary EAD generation in gear R during EV mode */
const volatile boolean eadc_b_enaMot2Tq = true;/* Referenced by: '<S7>/Constant12' */

/* Enable Secondary EAD Torque */
const volatile boolean eadc_b_useActTq2SwtOffMot2 = false;/* Referenced by:
                                                           * '<S6>/Constant11'
                                                           * '<S6>/Constant12'
                                                           * '<S6>/Constant15'
                                                           * '<S6>/Constant19'
                                                           */

/* Use Actual Torque to switch-off Secondary EAD Motor */
const volatile float32 eadc_n_mot2GenDisHiThdRev_rpm = -210.0F;/* Referenced by: '<S7>/Relay1' */

/* Secondary EAD high speed threshold for EAD generation disabling in reverse gear */
const volatile float32 eadc_n_mot2GenDisLoThdRev_rpm = -350.0F;/* Referenced by: '<S7>/Relay1' */

/* Secondary EAD low speed threshold for EAD generation disabling in reverse gear */
const volatile float32 eadc_n_mot2GenEnaHiThdFwd_rpm = 350.0F;/* Referenced by: '<S7>/Relay' */

/* Secondary EAD high speed threshold for EAD generation enabling in forward gear */
const volatile float32 eadc_n_mot2GenEnaLoThdFwd_rpm = 210.0F;/* Referenced by: '<S7>/Relay' */

/* Secondary EAD low speed threshold for EAD generation enabling in forward gear */
const volatile float32 eadc_tq_mot2MnTqDecGrad_Nmps = -300.0F;/* Referenced by:
                                                               * '<S6>/Constant21'
                                                               * '<S6>/Constant5'
                                                               */

/* Secondary EAD min torque decrease gradient when enabled */
const volatile float32 eadc_tq_mot2MnTqIncGradESP_Nmps = 50000.0F;/* Referenced by:
                                                                   * '<S6>/Constant13'
                                                                   * '<S6>/Constant20'
                                                                   */

/* Secondary EAD min torque increase gradient during ESP intervention */
const volatile float32 eadc_tq_mot2MnTqIncGrad_Nmps = 420.0F;/* Referenced by:
                                                              * '<S6>/Constant10'
                                                              * '<S6>/Constant18'
                                                              */

/* Secondary EAD min torque increase gradient when disabled */
const volatile float32 eadc_tq_mot2MxTqDecGradESP_Nmps = -50000.0F;/* Referenced by:
                                                                    * '<S6>/Constant24'
                                                                    * '<S6>/Constant25'
                                                                    */

/* Secondary EAD max torque decrease gradient during ESP intervention */
const volatile float32 eadc_tq_mot2MxTqDecGrad_Nmps = -420.0F;/* Referenced by:
                                                               * '<S6>/Constant23'
                                                               * '<S6>/Constant6'
                                                               */

/* Secondary EAD max torque decrease gradient when disabled */
const volatile float32 eadc_tq_mot2MxTqIncGrad_Nmps = 300.0F;/* Referenced by:
                                                              * '<S6>/Constant14'
                                                              * '<S6>/Constant4'
                                                              */

/* Secondary EAD max torque increase gradient when enabled */
const volatile float32 eadc_tq_mot2SwtOffThd_Nm = 5.0F;/* Referenced by: '<S6>/Constant9' */

/* Motor torque threshold for Secondary EAD switch-off */
const volatile float32 eadf_mot2MnTqLim_X_motSpd_rpm[11] = { 500.0F, 4500.0F,
  5000.0F, 6000.0F, 7000.0F, 8000.0F, 9000.0F, 10000.0F, 11000.0F, 12000.0F,
  13000.0F } ;                     /* Referenced by: '<S8>/1-D Lookup Table3' */

/* Secondary EAD Min Torque Limit Map - EAD Speed Axis */
const volatile float32 eadf_mot2MnTqLim_Y_Nm[11] = { -220.43F, -220.43F,
  -201.72F, -161.7F, -134.25F, -114.55F, -99.86F, -87.95F, -78.62F, -70.91F,
  -64.63F } ;                      /* Referenced by: '<S8>/1-D Lookup Table3' */

/* Secondary EAD Min Torque Limit Map - torque */
const volatile float32 eadf_mot2MxTqLim_X_motSpd_rpm[11] = { 500.0F, 4500.0F,
  5000.0F, 6000.0F, 7000.0F, 8000.0F, 9000.0F, 10000.0F, 11000.0F, 12000.0F,
  13000.0F } ;                     /* Referenced by: '<S8>/1-D Lookup Table2' */

/* Secondary EAD Max Torque Limit Map - EAD Speed Axis */
const volatile float32 eadf_mot2MxTqLim_Y_Nm[11] = { 190.0F, 190.0F, 171.0F,
  143.0F, 123.0F, 107.0F, 96.0F, 87.0F, 77.0F, 72.0F, 67.0F } ;
                                   /* Referenced by: '<S8>/1-D Lookup Table2' */

/* Secondary EAD Max Torque Limit Map - torque */
const volatile float32 ptla_ead2Eff_Y_MotSpd_rpm[21] = { 0.0F, 300.0F, 600.0F,
  900.0F, 1000.0F, 1250.0F, 1500.0F, 2500.0F, 3000.0F, 4000.0F, 5000.0F, 6000.0F,
  7000.0F, 8000.0F, 9000.0F, 10000.0F, 11000.0F, 12500.0F, 13000.0F, 14000.0F,
  15000.0F } ;                         /* Referenced by:
                                        * '<S109>/2-D Lookup Table5'
                                        * '<S110>/2-D Lookup Table4'
                                        * '<S68>/2-D Lookup Table5'
                                        * '<S69>/2-D Lookup Table4'
                                        */

/* Secondary EAD Motor Efficiency - Motor Speed Axis */
const volatile boolean ptlc_b_enaHVBSTPwrLimIn4WDMod = true;/* Referenced by: '<S58>/Constant5' */

/* Enable HVB Short-term Power limits in 4WD Mode */
const volatile boolean ptlc_b_enaHVBSTPwrLimInEVMod = false;/* Referenced by: '<S58>/Constant4' */

/* Enable HVB Short-term Power limits in EV Mode */
const volatile boolean ptlc_b_enaHVBSTPwrLimInSportMod = true;/* Referenced by: '<S58>/Constant2' */

/* Enable HVB Short-term Power limits in Sport Mode */
const volatile boolean ptlc_b_enaMotSTPwrLimIn4WDMod = true;/* Referenced by: '<S57>/Constant5' */

/* Enable Motors Short-term Power limits in 4WD Mode */
const volatile boolean ptlc_b_enaMotSTPwrLimInEVMod = false;/* Referenced by: '<S57>/Constant4' */

/* Enable Motors Short-term Power limits in EV Mode */
const volatile boolean ptlc_b_enaMotSTPwrLimInSportMod = true;/* Referenced by: '<S57>/Constant1' */

/* Enable Motors Short-term Power limits in Sport Mode */
const volatile float32 ptlc_f_bmsMaxChgCurrPreFidLvl1Factor = 0.98F;/* Referenced by: '<S58>/Constant59' */

/* Bms charge Current high level 1 pre FID */
const volatile float32 ptlc_f_bmsMaxChgCurrPreFidLvl2Factor = 1.1F;/* Referenced by: '<S58>/Constant62' */

/* Bms charge Current high level 2 pre FID */
const volatile float32 ptlc_f_bmsMaxDischCurrPreFidLvl1Factor = 0.98F;/* Referenced by: '<S58>/Constant27' */

/* Bms discharge Current high level 1 pre FID */
const volatile float32 ptlc_f_bmsMaxDischCurrPreFidLvl2Factor = 1.1F;/* Referenced by: '<S58>/Constant31' */

/* Bms discharge Current high level 2 pre FID */
const volatile float32 ptlc_fact_vehLvl2DerateDecGrad = -1.0F;/* Referenced by:
                                                               * '<S58>/Constant16'
                                                               * '<S62>/Constant16'
                                                               */

/* Vehicle level 2 fault discharge power derating factor decrease gradient */
const volatile float32 ptlc_fact_vehLvl2DerateIncGrad = 0.1F;/* Referenced by:
                                                              * '<S58>/Constant14'
                                                              * '<S62>/Constant14'
                                                              */

/* Vehicle level 2 fault discharge power derating factor increase gradient */
const volatile float32 ptlc_frac_hvbChEff = 1.0F;/* Referenced by: '<S58>/Constant1' */

/* Battery charge efficiency */
const volatile float32 ptlc_frac_hvbDischEff = 0.92F;/* Referenced by: '<S58>/Constant3' */

/* Battery discharge efficiency */
const volatile float32 ptlc_frac_motBrkEffGain = 1.0F;/* Referenced by:
                                                       * '<S109>/Constant3'
                                                       * '<S68>/Constant3'
                                                       */
const volatile float32 ptlc_frac_motBstEffGain = 1.0F;/* Referenced by:
                                                       * '<S110>/Constant5'
                                                       * '<S69>/Constant5'
                                                       */
const volatile float32 ptlc_pct_bmsCurrLimitPctPreFid = 0.8F;/* Referenced by: '<S81>/Constant54' */

/* power limit percent of bms current Pre FID */
const volatile float32 ptlc_s_preFidDlyTm_s = 0.03F;/* Referenced by:
                                                     * '<S58>/Constant28'
                                                     * '<S58>/Constant32'
                                                     * '<S58>/Constant60'
                                                     * '<S58>/Constant63'
                                                     */

/* Pre FID delay on time */
const volatile float32 ptlf_X_hvbSocForDerate_pct[7] = { 0.0F, 5.0F, 14.0F,
  16.0F, 20.0F, 40.0F, 100.0F } ; /* Referenced by: '<S58>/1-D Lookup Table3' */

/* HVB Discharge Power Derating f(SOC) Map - SOC Axis */
const volatile float32 ptlf_Y_hvbDsChrgDerate_fact[7] = { 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F } ;            /* Referenced by: '<S58>/1-D Lookup Table3' */

/* HVB Discharge Power Derating f(SOC) Map - factor */
const volatile float32 ptlf_ead2BrkEff_X_MotTrq_Nm[21] = { -400.0F, -380.0F,
  -360.0F, -340.0F, -320.0F, -300.0F, -280.0F, -260.0F, -240.0F, -220.0F,
  -200.0F, -180.0F, -160.0F, -140.0F, -120.0F, -100.0F, -80.0F, -60.0F, -40.0F,
  -20.0F, 0.0F } ;                     /* Referenced by:
                                        * '<S109>/2-D Lookup Table5'
                                        * '<S68>/2-D Lookup Table5'
                                        */

/* Secondary EAD Motor Brake Efficiency - Motor Torque Axis */
const volatile float32 ptlf_ead2BstEff_X_MotTrq_Nm[21] = { 0.0F, 20.0F, 40.0F,
  60.0F, 80.0F, 100.0F, 120.0F, 140.0F, 160.0F, 180.0F, 200.0F, 220.0F, 240.0F,
  260.0F, 280.0F, 300.0F, 320.0F, 340.0F, 360.0F, 380.0F, 400.0F } ;/* Referenced by:
                                                                     * '<S110>/2-D Lookup Table4'
                                                                     * '<S69>/2-D Lookup Table4'
                                                                     */

/* Secondary EAD Motor Boost Efficiency - Motor Torque Axis */
const volatile float32 ptlf_ead2MaxTqCorrSOC_X_SOC_pct[4] = { 18.0F, 19.0F,
  30.0F, 50.0F } ;                /* Referenced by: '<S62>/1-D Lookup Table6' */

/* Secondary EAD Max Torque Correction f(SOC) Map - SOC Axis */
const volatile float32 ptlf_ead2MaxTqCorrSOC_Y_frac[4] = { 1.0F, 1.0F, 1.0F,
  1.0F } ;                        /* Referenced by: '<S62>/1-D Lookup Table6' */

/* Secondary EAD Max Torque Correction f(SOC) Map - factor */
const volatile float32 ptlf_ead2MaxTqLmtTemp_Y_factor[2] = { 1.0F, 0.5F } ;
                                  /* Referenced by: '<S62>/1-D Lookup Table1' */

/* Secondary EAD Max Torque Limit f(Moter Temperature) Map - factor */
const volatile float32 ptlf_ead2MaxTqLmt_X_MotTemp_C[2] = { 135.0F, 145.0F } ;
                                  /* Referenced by: '<S62>/1-D Lookup Table1' */

/* Secondary EAD Max Torque Limit f(Moter Temperature) Map - Temp Axis */
const volatile float32 ptlf_ead2MinTqCorrSOC_X_SOC_pct[4] = { 50.0F, 70.0F,
  95.0F, 99.0F } ;                /* Referenced by: '<S62>/1-D Lookup Table7' */

/* Secondary EAD Min Torque Correction f(SOC) Map - SOC Axis */
const volatile float32 ptlf_ead2MinTqCorrSOC_Y_frac[4] = { 1.0F, 1.0F, 1.0F,
  0.0F } ;                        /* Referenced by: '<S62>/1-D Lookup Table7' */

/* Secondary EAD Min Torque Correction f(SOC) Map - factor */
const volatile float32 ptlf_ead2MinTqCorr_X_VehSpd_kph[5] = { 0.0F, 10.0F, 15.0F,
  50.0F, 100.0F } ;               /* Referenced by: '<S62>/1-D Lookup Table4' */

/* Secondary EAD Min Torque Correction f(Spd) Map - Vehicle Speed Axis */
const volatile float32 ptlf_ead2MinTqCorr_Y_frac[5] = { 0.0F, 1.0F, 1.0F, 1.0F,
  1.0F } ;                        /* Referenced by: '<S62>/1-D Lookup Table4' */

/* Secondary EAD Min Torque Correction f(Spd) Map - factor */
const volatile float32 ptlm_ead2BrkEff_Z_frac[441] = { 0.8F, 0.95F, 0.95F, 0.95F,
  0.95F, 0.95F, 0.95F, 0.95F, 0.95F, 0.95F, 0.95F, 0.95F, 0.95F, 0.95F, 0.95F,
  0.95F, 0.95F, 0.95F, 0.95F, 0.95F, 0.95F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 0.8F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F } ;/* Referenced by:
                                                                      * '<S109>/2-D Lookup Table5'
                                                                      * '<S68>/2-D Lookup Table5'
                                                                      */

/* Secondary EAD Motor Brake Efficiency */
const volatile float32 ptlm_ead2BstEff_Z_frac[441] = { 0.609F, 0.62F, 0.619F,
  0.6F, 0.577F, 0.551F, 0.524F, 0.499F, 0.474F, 0.446F, 0.423F, 0.415F, 0.415F,
  0.415F, 0.415F, 0.415F, 0.415F, 0.415F, 0.415F, 0.415F, 0.415F, 0.609F, 0.62F,
  0.619F, 0.6F, 0.577F, 0.551F, 0.524F, 0.499F, 0.474F, 0.446F, 0.423F, 0.415F,
  0.415F, 0.415F, 0.415F, 0.415F, 0.415F, 0.415F, 0.415F, 0.415F, 0.415F, 0.721F,
  0.773F, 0.763F, 0.744F, 0.723F, 0.7F, 0.653F, 0.63F, 0.63F, 0.604F, 0.583F,
  0.571F, 0.571F, 0.571F, 0.571F, 0.571F, 0.571F, 0.571F, 0.571F, 0.571F, 0.571F,
  0.81F, 0.827F, 0.825F, 0.811F, 0.797F, 0.78F, 0.76F, 0.741F, 0.721F, 0.699F,
  0.68F, 0.667F, 0.667F, 0.667F, 0.667F, 0.667F, 0.667F, 0.667F, 0.667F, 0.667F,
  0.667F, 0.821F, 0.832F, 0.841F, 0.832F, 0.819F, 0.804F, 0.789F, 0.773F, 0.755F,
  0.735F, 0.719F, 0.704F, 0.704F, 0.704F, 0.704F, 0.704F, 0.704F, 0.704F, 0.704F,
  0.704F, 0.704F, 0.845F, 0.854F, 0.851F, 0.842F, 0.829F, 0.814F, 0.799F, 0.783F,
  0.765F, 0.745F, 0.729F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F,
  0.714F, 0.714F, 0.714F, 0.868F, 0.878F, 0.877F, 0.87F, 0.859F, 0.848F, 0.835F,
  0.821F, 0.805F, 0.787F, 0.774F, 0.759F, 0.759F, 0.759F, 0.759F, 0.759F, 0.759F,
  0.759F, 0.759F, 0.759F, 0.759F, 0.87F, 0.904F, 0.907F, 0.904F, 0.897F, 0.89F,
  0.881F, 0.871F, 0.861F, 0.849F, 0.838F, 0.821F, 0.821F, 0.821F, 0.821F, 0.821F,
  0.821F, 0.821F, 0.821F, 0.821F, 0.821F, 0.89F, 0.913F, 0.919F, 0.917F, 0.9128F,
  0.912F, 0.9F, 0.892F, 0.883F, 0.872F, 0.862F, 0.845F, 0.845F, 0.845F, 0.845F,
  0.845F, 0.845F, 0.845F, 0.845F, 0.845F, 0.845F, 0.903F, 0.923F, 0.933F, 0.934F,
  0.931F, 0.927F, 0.921F, 0.915F, 0.908F, 0.9F, 0.892F, 0.882F, 0.882F, 0.882F,
  0.882F, 0.882F, 0.882F, 0.882F, 0.882F, 0.882F, 0.882F, 0.923F, 0.943F, 0.944F,
  0.945F, 0.943F, 0.9432F, 0.936F, 0.931F, 0.924F, 0.917F, 0.907F, 0.907F,
  0.907F, 0.907F, 0.907F, 0.907F, 0.907F, 0.907F, 0.907F, 0.907F, 0.907F, 0.92F,
  0.94F, 0.951F, 0.952F, 0.951F, 0.949F, 0.939F, 0.93F, 0.92F, 0.92F, 0.92F,
  0.92F, 0.92F, 0.92F, 0.92F, 0.92F, 0.92F, 0.92F, 0.92F, 0.92F, 0.92F, 0.921F,
  0.921F, 0.98F, 0.9563F, 0.9523F, 0.944F, 0.935F, 0.915F, 0.915F, 0.915F,
  0.915F, 0.915F, 0.915F, 0.915F, 0.915F, 0.915F, 0.915F, 0.915F, 0.915F, 0.915F,
  0.915F, 0.93F, 0.95F, 0.955F, 0.9551F, 0.934F, 0.914F, 0.914F, 0.914F, 0.914F,
  0.914F, 0.914F, 0.914F, 0.914F, 0.914F, 0.914F, 0.914F, 0.914F, 0.914F, 0.914F,
  0.914F, 0.914F, 0.928F, 0.948F, 0.953F, 0.952F, 0.9418F, 0.9238F, 0.903F,
  0.903F, 0.903F, 0.903F, 0.903F, 0.903F, 0.903F, 0.903F, 0.903F, 0.903F, 0.903F,
  0.903F, 0.903F, 0.903F, 0.903F, 0.834F, 0.834F, 0.834F, 0.834F, 0.874F, 0.854F,
  0.854F, 0.854F, 0.854F, 0.854F, 0.854F, 0.854F, 0.854F, 0.854F, 0.854F, 0.854F,
  0.854F, 0.854F, 0.854F, 0.854F, 0.854F, 0.9F, 0.929F, 0.941F, 0.932F, 0.916F,
  0.9025F, 0.9025F, 0.9025F, 0.9025F, 0.9025F, 0.9025F, 0.9025F, 0.9025F,
  0.9025F, 0.9025F, 0.9025F, 0.9025F, 0.9025F, 0.9025F, 0.9025F, 0.9025F, 0.88F,
  0.912F, 0.94F, 0.927F, 0.91F, 0.9F, 0.9F, 0.9F, 0.9F, 0.9F, 0.9F, 0.9F, 0.9F,
  0.9F, 0.9F, 0.9F, 0.9F, 0.9F, 0.9F, 0.9F, 0.9F, 0.714F, 0.714F, 0.714F, 0.714F,
  0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F,
  0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F,
  0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F,
  0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F,
  0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F,
  0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F, 0.714F } ;/* Referenced by:
                                                                      * '<S110>/2-D Lookup Table4'
                                                                      * '<S69>/2-D Lookup Table4'
                                                                      */

/* Secondary EAD Motor Boost Efficiency */
const volatile boolean scap_eadc_b_useFctCfgMot = true;/* Referenced by:
                                                        * '<S8>/Constant1'
                                                        * '<S8>/Constant13'
                                                        */
const volatile boolean scap_eadc_b_useGetEventSts = true;/* Referenced by: '<S3>/Constant3' */
const volatile float32 scap_eadc_tm_pwrOffCmdLmtDly_s = 10.0F;/* Referenced by: '<S19>/Constant28' */
const volatile float32 scap_eadc_tq_PwrOffCmdDecGrad_Nmps = -420.0F;/* Referenced by: '<S19>/Constant30' */
const volatile float32 scap_eadc_tq_PwrOffCmdIncGrad_Nmps = 300.0F;/* Referenced by: '<S19>/Constant27' */
const volatile float32 scap_eadc_tq_mot2LmtPwrOffCmd_Nm = 60.0F;/* Referenced by:
                                                                 * '<S19>/Constant1'
                                                                 * '<S19>/Constant26'
                                                                 */
const volatile float32 scap_eadc_v_pwrOffCmdVspdThd_kmh = 3.0F;/* Referenced by: '<S19>/Constant3' */
const volatile float32 scap_eadf_mot2MnTqLimMotTyp2_X_rpm[13] = { 1000.0F,
  2000.0F, 3000.0F, 4000.0F, 5000.0F, 6000.0F, 7000.0F, 8000.0F, 9000.0F,
  10001.0F, 11000.0F, 12000.0F, 12500.0F } ;
                                   /* Referenced by: '<S8>/1-D Lookup Table4' */

const volatile float32 scap_eadf_mot2MnTqLimMotTyp2_Y_Nm[13] = { -194.1F,
  -192.9F, -197.1F, -195.0F, -172.6F, -142.8F, -123.4F, -107.1F, -94.3F, -85.1F,
  -76.1F, -72.1F, -69.2F } ;       /* Referenced by: '<S8>/1-D Lookup Table4' */

const volatile float32 scap_eadf_mot2MxTqLimMotTyp2_X_rpm[13] = { 1000.0F,
  2000.0F, 3000.0F, 4200.0F, 5100.0F, 6000.0F, 7200.0F, 8100.0F, 9000.0F,
  9900.0F, 10800.0F, 12000.0F, 12500.0F } ;
                                   /* Referenced by: '<S8>/1-D Lookup Table1' */

const volatile float32 scap_eadf_mot2MxTqLimMotTyp2_Y_Nm[13] = { 195.0F, 195.0F,
  195.0F, 195.0F, 177.66F, 152.0F, 126.18F, 111.5F, 102.5F, 91.5F, 85.28F,
  77.86F, 73.0F } ;                /* Referenced by: '<S8>/1-D Lookup Table1' */

const volatile float32 scap_ptlc_pct_bmsCurrChgLmtPctPreFid = 0.8F;/* Referenced by: '<S80>/Constant54' */

/* power limit percent of bms current Pre FID */
const volatile boolean swcscap_eadc_b_adcOvrCtlPmt = false;/* Referenced by: '<S7>/Constant8' */
const volatile float32 swcscap_eadc_n_mot2GenEnaHiThdAdc_rpm = 350.0F;/* Referenced by: '<S7>/Relay2' */

/* Secondary EAD high speed threshold for EAD generation enabling in Adc Controll */
const volatile float32 swcscap_eadc_n_mot2GenEnaLoThdAdc_rpm = 210.0F;/* Referenced by: '<S7>/Relay2' */

/* Secondary EAD low speed threshold for EAD generation enabling in Adc Controll */
const volatile boolean swcscap_ptlc_b_adcOvrCtlPmt = false;/* Referenced by: '<S62>/Constant8' */
const volatile boolean swcscap_ptlc_b_useHvAttpwr = false;/* Referenced by: '<S58>/Constant22' */
const volatile float32 swcscap_ptlf_ead2MinTqCorrAdc_X_VehSpd_kph[5] = { 0.0F,
  3.0F, 6.0F, 50.0F, 100.0F } ;   /* Referenced by: '<S62>/1-D Lookup Table2' */

/* Secondary EAD Min Torque Correction f(Spd) Map - Vehicle Speed Axis */
const volatile float32 swcscap_ptlf_ead2MinTqCorrAdc_Y_frac[5] = { 0.0F, 0.0F,
  1.0F, 1.0F, 1.0F } ;            /* Referenced by: '<S62>/1-D Lookup Table2' */

/* Secondary EAD Min Torque Correction f(Spd) Map - factor */
const volatile boolean tqlc_b_enaEADMot2In2WDMod = true;/* Referenced by: '<S119>/Constant1' */

/* Enable Secondary EAD Motor in 2WD Mode */
const volatile float32 tqlc_tq_eadMot2MnTqDecGrad_Nmps = -200.0F;/* Referenced by: '<S118>/Constant3' */

/* Secondary EAD min torque decrease gradient when enabled */
const volatile float32 tqlc_tq_eadMot2MnTqIncGrad_Nmps = 200.0F;/* Referenced by: '<S118>/Constant4' */

/* Secondary EAD min torque increase gradient when disabled */
const volatile float32 tqlc_tq_eadMot2MxTqDecGrad_Nmps = -200.0F;/* Referenced by: '<S118>/Constant2' */

/* Secondary EAD max torque decrease gradient when disabled */
const volatile float32 tqlc_tq_eadMot2MxTqIncGrad_Nmps = 200.0F;/* Referenced by: '<S118>/Constant6' */

/* Secondary EAD max torque increase gradient when enabled */
#define swc_SCAP_STOP_SEC_CONST_VOLATILE
#include "swc_SCAP_MemMap.h"
#define swc_SCAP_START_SEC_VAR
#include "swc_SCAP_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_SIG */
boolean eadd_b_mot2BrkTqEnad;          /* '<S7>/Logical Operator1' */

/* Secondary EAD Brake Torque Enabled */
boolean eadd_b_mot2BstTqEnad;          /* '<S7>/Logical Operator20' */

/* Secondary EAD Boost Torque Enabled */
boolean eadd_b_mot2TqOff;              /* '<S6>/Relational Operator' */

/* Secondary EAD Torque Off */
float32 eadd_tq_mot2MaxLTTqLimd_Nm;    /* '<S8>/MinMax10' */

/* Secondary EAD Max Long-term Limited Motoring Torque */
float32 eadd_tq_mot2MaxLTTq_Nm;        /* '<S22>/Chart' */

/* Secondary EAD Max Long-term Motoring Torque */
float32 eadd_tq_mot2MaxSTTqLimd_Nm;    /* '<S8>/MinMax1' */

/* Secondary EAD Max Short-term Limited Motoring Torque */
float32 eadd_tq_mot2MaxSTTq_Nm;        /* '<S20>/Chart' */

/* Secondary EAD Max Short-term Motoring Torque */
float32 eadd_tq_mot2MinLTTqLimd_Nm;    /* '<S8>/MinMax11' */

/* Secondary EAD Max Long-term Limited Generating Torque */
float32 eadd_tq_mot2MinLTTq_Nm;        /* '<S26>/Chart' */

/* Secondary EAD Max Long-term Generating Torque */
float32 eadd_tq_mot2MinSTTqLimd_Nm;    /* '<S8>/MinMax2' */

/* Secondary EAD Max Short-term Limited Generating Torque */
float32 eadd_tq_mot2MinSTTq_Nm;        /* '<S24>/Chart' */

/* Secondary EAD Max Short-term Generating Torque */
float32 ptld_fact_hvbFltDegrd;         /* '<S58>/switch_ramp' */

/* Vehicle Fault Level Power Degradation Factor */
float32 ptld_frac_ead2MaxBrkEff;       /* '<S68>/MinMax2' */

/* Secondary EAD Max Brake Efficiency */
float32 ptld_frac_ead2MaxBrkEffFinal;  /* '<S109>/MinMax2' */

/* Secondary EAD Max Brake Efficiency Final */
float32 ptld_frac_ead2MaxBstEff;       /* '<S69>/MinMax2' */

/* Secondary EAD Max Boost Efficiency */
float32 ptld_frac_ead2MaxBstEffFinal;  /* '<S110>/MinMax2' */

/* Secondary EAD Max Boost Efficiency Final */
float32 ptld_pwr_ead2ChrgAvail_kW;     /* '<S73>/Product' */

/* Secondary EAD Available Charge Power */
float32 ptld_pwr_ead2DischAvail_kW;    /* '<S72>/Product' */

/* Secondary EAD Available Discharge Power */
float32 ptld_pwr_ead2PwrMax_kW;        /* '<S107>/Switch2' */

/* Secondary EAD Max Power (motor) */
float32 ptld_pwr_ead2PwrMin_kW;        /* '<S59>/Gain4' */

/* Secondary EAD Min Power (generator) */
float32 ptld_pwr_hvbChrgAvail_kW;      /* '<S80>/Switch9' */

/* HVB Available Charge Power */
float32 ptld_pwr_hvbDischAvail_kW;     /* '<S81>/Switch9' */

/* HVB Available Discharge Power */
float32 ptld_tq_ead2MaxTqLimd_Nm;      /* '<S62>/Product4' */

/* Secondary EAD Max Torque Limit */
float32 ptld_tq_ead2MinTqLimd_Nm;      /* '<S62>/Product5' */

/* Secondary EAD Min Torque Limit */
float32 ptld_tq_ead2TqMaxRaw_Nm;       /* '<S60>/Product7' */

/* Secondary EAD Max Torque Raw */
float32 ptld_tq_ead2TqMax_Nm;          /* '<S60>/Product5' */

/* Secondary EAD Max Torque */
float32 ptld_tq_ead2TqMinRaw_Nm;       /* '<S60>/Product9' */

/* Secondary EAD Min Torque Raw */
float32 ptld_tq_ead2TqMin_Nm;          /* '<S60>/Product10' */

/* Secondary EAD Min Torque */
boolean scap_eadd_b_ehbMsgErrDebd;     /* '<S3>/Logical Operator1' */
boolean scap_eadd_b_tqLmtPwrOffCmd_flg;/* '<S19>/SR_latch' */
uint8 scap_eadd_st_getEhbMsgErrSts;    /* '<S3>/C Caller1' */
float32 scap_eadd_tq_mot2LmPwrOffCmd_Nm;/* '<S19>/Switch1' */
float32 scap_eadd_tq_mot2MaxLmtEnaOff_Nm;/* '<S19>/Switch8' */
boolean swcscap_pltd_b_PwrPreLimitLvl1ChgCurr;/* '<S89>/timed_delay' */
boolean swcscap_pltd_b_PwrPreLimitLvl1DischCurr;/* '<S86>/timed_delay' */
boolean swcscap_pltd_b_PwrPreLimitLvl2ChgCurr;/* '<S87>/timed_delay' */
boolean swcscap_pltd_b_PwrPreLimitLvl2DischCurr;/* '<S88>/timed_delay' */
float32 swcscap_pltd_i_hvbMaxChgCurr_A;/* '<S58>/Product10' */

/* HV Battery Available Charge Current */
float32 swcscap_pltd_i_hvbMaxDischCurr_A;/* '<S58>/Product3' */

/* HV Battery Available Discharge Current */
float32 swcscap_ptld_pwr_hvbChrgAvailRaw_kW;/* '<S58>/Product5' */

/* HVB Available Charge Power */
float32 swcscap_ptld_pwr_hvbDischAvailRaw_kW;/* '<S58>/Product2' */

/* HVB Available Discharge Power */
boolean tqld_b_eadMot2TqEnad;          /* '<S119>/Logical Operator10' */

/* Secondary EAD Torque enabled */
float32 tqld_tq_axle2MaxTq_Nm;         /* '<S117>/Product2' */

/* Secondary Axle Max Torque */
float32 tqld_tq_axle2MinTq_Nm;         /* '<S117>/Product1' */

/* Secondary Axle Min Torque */
float32 tqld_tq_eadMot2AllwdMaxTq_Nm;  /* '<S118>/SwitchRampMOTMaxTrqLim' */

/* Secondary EAD Max Allowed Torque */
float32 tqld_tq_eadMot2AllwdMinTq_Nm;  /* '<S118>/SwitchRampMOTMinTrqLim' */

/* Secondary EAD Min Allowed Torque */
float32 tqld_tq_whlMax_Nm;             /* '<S116>/MinMax3' */

/* Wheel Max Torque */
float32 tqld_tq_whlMin_Nm;             /* '<S116>/MinMax4' */

/* Wheel Min Torque */
#define swc_SCAP_STOP_SEC_VAR
#include "swc_SCAP_MemMap.h"

/* Constant parameters (default storage) */
const ConstP_swc_SCAP_T swc_SCAP_ConstP = {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S109>/2-D Lookup Table5'
   *   '<S110>/2-D Lookup Table4'
   *   '<S68>/2-D Lookup Table5'
   *   '<S69>/2-D Lookup Table4'
   */
  { 20U, 20U }
};

/* PublicStructure Variables for Internal Data */
ARID_DEF_swc_SCAP_T swc_SCAP_ARID_DEF;
static float32 look1_iflf_binlcapw(float32 u0, const float32 bp0[], const
  float32 table[], uint32 maxIndex);
static float32 look2_iflf_binlcapw(float32 u0, float32 u1, const float32 bp0[],
  const float32 bp1[], const float32 table[], const uint32 maxIndex[], uint32
  stride);
static void swc_SCAP_switch_ramp_Init(boolean *rty_RampOn);
static void swc_SCAP_switch_ramp(float32 rtu_u1, boolean rtu_sw, float32 rtu_u2,
  float32 rtu_up, float32 rtu_lo, boolean *rty_RampOn,
  ARID_DEF_switch_ramp_swc_SCAP_T *swc_SCAP__ARID_DEF_arg);
static void swc_SC_SwitchRampMOTMaxTrq_Init(boolean *rty_RampOn);
static void swc_SCAP_SwitchRampMOTMaxTrq(float32 rtu_u1, boolean rtu_sw, float32
  rtu_u2, float32 rtu_up, float32 rtu_lo, boolean *rty_RampOn,
  ARID_DEF_switch_ramp_swc_SC_f_T *swc_SCAP__ARID_DEF_arg);
static void sw_SwitchRampMOTMinPeakTrq_Init(boolean *rty_RampOn);
static void swc_SCA_SwitchRampMOTMinPeakTrq(float32 rtu_u1, boolean rtu_sw,
  float32 rtu_u2, float32 rtu_up, float32 rtu_lo, boolean *rty_RampOn,
  ARID_DEF_switch_ramp_swc_SC_k_T *swc_SCAP__ARID_DEF_arg);
static void swc_SC_SwitchRampMOTMinTrq_Init(boolean *rty_RampOn);
static void swc_SCAP_SwitchRampMOTMinTrq(float32 rtu_u1, boolean rtu_sw, float32
  rtu_u2, float32 rtu_up, float32 rtu_lo, boolean *rty_RampOn,
  ARID_DEF_switch_ramp_swc_SC_d_T *swc_SCAP__ARID_DEF_arg);
static void swc_SCAP_pos(float32 rtu_in_val, float32 *rty_same_val);
static void swc_SCAP_neg(float32 rtu_in_val, float32 *rty_neg_val);
static void swc_SCAP_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch_swc_SCAP_T *swc_SCAP__ARID_DEF_arg);
static void swc_S_SwitchRampMOTMaxTrq1_Init(float32 *rty_y, boolean *rty_RampOn);
static void swc_SCAP_SwitchRampMOTMaxTrq1(float32 rtu_u1, boolean rtu_sw,
  float32 rtu_u2, float32 rtu_up, float32 rtu_lo, float32 *rty_y, boolean
  *rty_RampOn, ARID_DEF_switch_ramp_swc_S_dk_T *swc_SCAP__ARID_DEF_arg);
static void swc_SCAP_switch_ramp_d_Init(float32 *rty_y, boolean *rty_RampOn);
static void swc_SCAP_switch_ramp_o(float32 rtu_u1, boolean rtu_sw, float32
  rtu_u2, float32 rtu_up, float32 rtu_lo, float32 *rty_y, boolean *rty_RampOn,
  ARID_DEF_switch_ramp_swc_SC_c_T *swc_SCAP__ARID_DEF_arg);
static void swc_SwitchRampMOTMaxTrqLim_Init(float32 *rty_y, boolean *rty_RampOn);
static void swc_SCAP_SwitchRampMOTMaxTrqLim(float32 rtu_u1, boolean rtu_sw,
  float32 rtu_u2, float32 rtu_up, float32 rtu_lo, float32 *rty_y, boolean
  *rty_RampOn, ARID_DEF_switch_ramp_swc_SC_h_T *swc_SCAP__ARID_DEF_arg);
static void swc_S_EAD_TorqueLimitsMot2_Init(void);
static void swc_SCAP_EAD_TorqueLimitsMot2(void);
static void ElectricalMotorsPowerLimit_Init(void);
static void ElectricalMotorsPowerLimitation(void);
static void swc_SCAP_PowerLimitsArbitration(void);
static void s_PowerToTorqueLimitsConversion(void);
static void swc_SC_PTL_PowerLimitation_Init(void);
static void swc_SCAP_PTL_PowerLimitation(void);
static void swc_SCAP_AxleDrive2Whl_Conv(void);
static void swc_EADShaft2SecondaryAxle_Conv(void);
static void SecondaryEADMotorAllowedTo_Init(void);
static void SecondaryEADMotorAllowedTorque(void);
static void swc_SCAP_TorqueEnable(void);
static void TQL_TorqueLimitsConversion_Init(void);
static void swc__TQL_TorqueLimitsConversion(void);
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

static float32 look2_iflf_binlcapw(float32 u0, float32 u1, const float32 bp0[],
  const float32 bp1[], const float32 table[], const uint32 maxIndex[], uint32
  stride)
{
  float32 fractions[2];
  float32 frac;
  float32 y;
  float32 yL_0d0;
  uint32 bpIndices[2];
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;

  /* Column-major Lookup 2-D
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
    iLeft = maxIndex[0U];
    frac = 0.0F;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
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
    iLeft = maxIndex[1U];
    frac = 0.0F;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  if (bpIndices[0U] == maxIndex[0U]) {
    y = table[bpIdx];
  } else {
    yL_0d0 = table[bpIdx];
    y = (table[bpIdx + 1U] - yL_0d0) * fractions[0U] + yL_0d0;
  }

  if (iLeft == maxIndex[1U]) {
  } else {
    bpIdx += stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yL_0d0 = table[bpIdx];
    } else {
      yL_0d0 = table[bpIdx];
      yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
    }

    y += (yL_0d0 - y) * frac;
  }

  return y;
}

/* System initialize for atomic system: '<S6>/SwitchRampMOTMaxPeakTrq' */
static void swc_SCAP_switch_ramp_Init(boolean *rty_RampOn)
{
  /* SystemInitialize for Chart: '<S20>/Chart' */
  *rty_RampOn = false;
}

/* Output and update for atomic system: '<S6>/SwitchRampMOTMaxPeakTrq' */
static void swc_SCAP_switch_ramp(float32 rtu_u1, boolean rtu_sw, float32 rtu_u2,
  float32 rtu_up, float32 rtu_lo, boolean *rty_RampOn,
  ARID_DEF_switch_ramp_swc_SCAP_T *swc_SCAP__ARID_DEF_arg)
{
  float32 rtb_MinMax1_db;
  float32 rtb_MinMax_lu;

  /* MinMax: '<S13>/MinMax' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Constant: '<S13>/Constant2'
   *  Product: '<S13>/Product'
   */
  rtb_MinMax_lu = fmaxf(rtu_up * 0.01F, 0.0F);

  /* MinMax: '<S13>/MinMax1' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Constant: '<S13>/Constant2'
   *  Product: '<S13>/Product1'
   */
  rtb_MinMax1_db = fminf(0.0F, 0.01F * rtu_lo);

  /* Chart: '<S20>/Chart' */
  if (swc_SCAP__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li == 0U) {
    swc_SCAP__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li = 1U;
    swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2;
    *rty_RampOn = false;
    eadd_tq_mot2MaxSTTq_Nm = rtu_u2;
  } else {
    switch (swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib) {
     case swc_SCAP_IN_U1:
      *rty_RampOn = false;
      if (!rtu_sw) {
        if (rtu_u2 >= rtu_u1) {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_INC;
          *rty_RampOn = true;
          eadd_tq_mot2MaxSTTq_Nm = fminf(fmaxf(fminf(rtu_u2 -
            eadd_tq_mot2MaxSTTq_Nm, rtb_MinMax_lu) + eadd_tq_mot2MaxSTTq_Nm,
            rtu_u1), rtu_u2);
        } else {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_DEC;
          *rty_RampOn = true;
          eadd_tq_mot2MaxSTTq_Nm = fmaxf(fminf(fmaxf(rtu_u2 -
            eadd_tq_mot2MaxSTTq_Nm, rtb_MinMax1_db) + eadd_tq_mot2MaxSTTq_Nm,
            rtu_u1), rtu_u2);
        }
      } else {
        eadd_tq_mot2MaxSTTq_Nm = rtu_u1;
      }
      break;

     case swc_SCAP_IN_U1_TO_U2:
      if (rtu_sw) {
        if (rtu_u1 >= rtu_u2) {
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_INC;
          *rty_RampOn = true;
          eadd_tq_mot2MaxSTTq_Nm = fminf(fmaxf(fminf(rtu_u1 -
            eadd_tq_mot2MaxSTTq_Nm, rtb_MinMax_lu) + eadd_tq_mot2MaxSTTq_Nm,
            rtu_u2), rtu_u1);
        } else {
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_DEC;
          *rty_RampOn = true;
          eadd_tq_mot2MaxSTTq_Nm = fmaxf(fminf(fmaxf(rtu_u1 -
            eadd_tq_mot2MaxSTTq_Nm, rtb_MinMax1_db) + eadd_tq_mot2MaxSTTq_Nm,
            rtu_u2), rtu_u1);
        }
      } else if (swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 == swc_SCAP_IN_U1_TO_U2_DEC)
      {
        *rty_RampOn = true;
        rtb_MinMax_lu = rtu_u2 - eadd_tq_mot2MaxSTTq_Nm;
        if (rtb_MinMax_lu >= rtb_MinMax1_db) {
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2;
          *rty_RampOn = false;
          eadd_tq_mot2MaxSTTq_Nm = rtu_u2;
        } else {
          eadd_tq_mot2MaxSTTq_Nm = fmaxf(fminf(fmaxf(rtb_MinMax_lu,
            rtb_MinMax1_db) + eadd_tq_mot2MaxSTTq_Nm, rtu_u1), rtu_u2);
        }
      } else {
        /* case IN_U1_TO_U2_INC: */
        *rty_RampOn = true;
        if (rtu_u2 - eadd_tq_mot2MaxSTTq_Nm <= rtb_MinMax_lu) {
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2;
          *rty_RampOn = false;
          eadd_tq_mot2MaxSTTq_Nm = rtu_u2;
        } else {
          eadd_tq_mot2MaxSTTq_Nm = fminf(fmaxf(fminf(rtu_u2 -
            eadd_tq_mot2MaxSTTq_Nm, rtb_MinMax_lu) + eadd_tq_mot2MaxSTTq_Nm,
            rtu_u1), rtu_u2);
        }
      }
      break;

     case swc_SCAP_IN_U2:
      *rty_RampOn = false;
      if (rtu_sw) {
        if (rtu_u1 >= rtu_u2) {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_INC;
          *rty_RampOn = true;
          eadd_tq_mot2MaxSTTq_Nm = fminf(fmaxf(fminf(rtu_u1 -
            eadd_tq_mot2MaxSTTq_Nm, rtb_MinMax_lu) + eadd_tq_mot2MaxSTTq_Nm,
            rtu_u2), rtu_u1);
        } else {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_DEC;
          *rty_RampOn = true;
          eadd_tq_mot2MaxSTTq_Nm = fmaxf(fminf(fmaxf(rtu_u1 -
            eadd_tq_mot2MaxSTTq_Nm, rtb_MinMax1_db) + eadd_tq_mot2MaxSTTq_Nm,
            rtu_u2), rtu_u1);
        }
      } else {
        eadd_tq_mot2MaxSTTq_Nm = rtu_u2;
      }
      break;

     default:
      /* case IN_U2_TO_U1: */
      if (!rtu_sw) {
        if (rtu_u2 >= rtu_u1) {
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_INC;
          *rty_RampOn = true;
          eadd_tq_mot2MaxSTTq_Nm = fminf(fmaxf(fminf(rtu_u2 -
            eadd_tq_mot2MaxSTTq_Nm, rtb_MinMax_lu) + eadd_tq_mot2MaxSTTq_Nm,
            rtu_u1), rtu_u2);
        } else {
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_DEC;
          *rty_RampOn = true;
          eadd_tq_mot2MaxSTTq_Nm = fmaxf(fminf(fmaxf(rtu_u2 -
            eadd_tq_mot2MaxSTTq_Nm, rtb_MinMax1_db) + eadd_tq_mot2MaxSTTq_Nm,
            rtu_u1), rtu_u2);
        }
      } else if (swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 == swc_SCAP_IN_U2_TO_U1_DEC)
      {
        *rty_RampOn = true;
        rtb_MinMax_lu = rtu_u1 - eadd_tq_mot2MaxSTTq_Nm;
        if (rtb_MinMax_lu >= rtb_MinMax1_db) {
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U1;
          *rty_RampOn = false;
          eadd_tq_mot2MaxSTTq_Nm = rtu_u1;
        } else {
          eadd_tq_mot2MaxSTTq_Nm = fmaxf(fminf(fmaxf(rtb_MinMax_lu,
            rtb_MinMax1_db) + eadd_tq_mot2MaxSTTq_Nm, rtu_u2), rtu_u1);
        }
      } else {
        /* case IN_U2_TO_U1_INC: */
        *rty_RampOn = true;
        if (rtu_u1 - eadd_tq_mot2MaxSTTq_Nm <= rtb_MinMax_lu) {
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U1;
          *rty_RampOn = false;
          eadd_tq_mot2MaxSTTq_Nm = rtu_u1;
        } else {
          eadd_tq_mot2MaxSTTq_Nm = fminf(fmaxf(fminf(rtu_u1 -
            eadd_tq_mot2MaxSTTq_Nm, rtb_MinMax_lu) + eadd_tq_mot2MaxSTTq_Nm,
            rtu_u2), rtu_u1);
        }
      }
      break;
    }
  }

  /* End of Chart: '<S20>/Chart' */
}

/* System initialize for atomic system: '<S6>/SwitchRampMOTMaxTrq' */
static void swc_SC_SwitchRampMOTMaxTrq_Init(boolean *rty_RampOn)
{
  /* SystemInitialize for Chart: '<S22>/Chart' */
  *rty_RampOn = false;
}

/* Output and update for atomic system: '<S6>/SwitchRampMOTMaxTrq' */
static void swc_SCAP_SwitchRampMOTMaxTrq(float32 rtu_u1, boolean rtu_sw, float32
  rtu_u2, float32 rtu_up, float32 rtu_lo, boolean *rty_RampOn,
  ARID_DEF_switch_ramp_swc_SC_f_T *swc_SCAP__ARID_DEF_arg)
{
  float32 rtb_MinMax1_k;
  float32 rtb_MinMax_o1;

  /* MinMax: '<S14>/MinMax' incorporates:
   *  Constant: '<S14>/Constant1'
   *  Constant: '<S14>/Constant2'
   *  Product: '<S14>/Product'
   */
  rtb_MinMax_o1 = fmaxf(rtu_up * 0.01F, 0.0F);

  /* MinMax: '<S14>/MinMax1' incorporates:
   *  Constant: '<S14>/Constant1'
   *  Constant: '<S14>/Constant2'
   *  Product: '<S14>/Product1'
   */
  rtb_MinMax1_k = fminf(0.0F, 0.01F * rtu_lo);

  /* Chart: '<S22>/Chart' */
  if (swc_SCAP__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li == 0U) {
    swc_SCAP__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li = 1U;
    swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2_m;
    *rty_RampOn = false;
    eadd_tq_mot2MaxLTTq_Nm = rtu_u2;
  } else {
    switch (swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib) {
     case swc_SCAP_IN_U1_m:
      *rty_RampOn = false;
      if (!rtu_sw) {
        if (rtu_u2 >= rtu_u1) {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2_p;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_INC_c;
          *rty_RampOn = true;
          eadd_tq_mot2MaxLTTq_Nm = fminf(fmaxf(fminf(rtu_u2 -
            eadd_tq_mot2MaxLTTq_Nm, rtb_MinMax_o1) + eadd_tq_mot2MaxLTTq_Nm,
            rtu_u1), rtu_u2);
        } else {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2_p;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_DEC_g;
          *rty_RampOn = true;
          eadd_tq_mot2MaxLTTq_Nm = fmaxf(fminf(fmaxf(rtu_u2 -
            eadd_tq_mot2MaxLTTq_Nm, rtb_MinMax1_k) + eadd_tq_mot2MaxLTTq_Nm,
            rtu_u1), rtu_u2);
        }
      } else {
        eadd_tq_mot2MaxLTTq_Nm = rtu_u1;
      }
      break;

     case swc_SCAP_IN_U1_TO_U2_p:
      if (rtu_sw) {
        if (rtu_u1 >= rtu_u2) {
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_m;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1_b;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_INC_k;
          *rty_RampOn = true;
          eadd_tq_mot2MaxLTTq_Nm = fminf(fmaxf(fminf(rtu_u1 -
            eadd_tq_mot2MaxLTTq_Nm, rtb_MinMax_o1) + eadd_tq_mot2MaxLTTq_Nm,
            rtu_u2), rtu_u1);
        } else {
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_m;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1_b;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_DEC_k;
          *rty_RampOn = true;
          eadd_tq_mot2MaxLTTq_Nm = fmaxf(fminf(fmaxf(rtu_u1 -
            eadd_tq_mot2MaxLTTq_Nm, rtb_MinMax1_k) + eadd_tq_mot2MaxLTTq_Nm,
            rtu_u2), rtu_u1);
        }
      } else if (swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 ==
                 swc_SCAP_IN_U1_TO_U2_DEC_g) {
        *rty_RampOn = true;
        rtb_MinMax_o1 = rtu_u2 - eadd_tq_mot2MaxLTTq_Nm;
        if (rtb_MinMax_o1 >= rtb_MinMax1_k) {
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_m;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2_m;
          *rty_RampOn = false;
          eadd_tq_mot2MaxLTTq_Nm = rtu_u2;
        } else {
          eadd_tq_mot2MaxLTTq_Nm = fmaxf(fminf(fmaxf(rtb_MinMax_o1,
            rtb_MinMax1_k) + eadd_tq_mot2MaxLTTq_Nm, rtu_u1), rtu_u2);
        }
      } else {
        /* case IN_U1_TO_U2_INC: */
        *rty_RampOn = true;
        if (rtu_u2 - eadd_tq_mot2MaxLTTq_Nm <= rtb_MinMax_o1) {
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_m;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2_m;
          *rty_RampOn = false;
          eadd_tq_mot2MaxLTTq_Nm = rtu_u2;
        } else {
          eadd_tq_mot2MaxLTTq_Nm = fminf(fmaxf(fminf(rtu_u2 -
            eadd_tq_mot2MaxLTTq_Nm, rtb_MinMax_o1) + eadd_tq_mot2MaxLTTq_Nm,
            rtu_u1), rtu_u2);
        }
      }
      break;

     case swc_SCAP_IN_U2_m:
      *rty_RampOn = false;
      if (rtu_sw) {
        if (rtu_u1 >= rtu_u2) {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1_b;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_INC_k;
          *rty_RampOn = true;
          eadd_tq_mot2MaxLTTq_Nm = fminf(fmaxf(fminf(rtu_u1 -
            eadd_tq_mot2MaxLTTq_Nm, rtb_MinMax_o1) + eadd_tq_mot2MaxLTTq_Nm,
            rtu_u2), rtu_u1);
        } else {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1_b;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_DEC_k;
          *rty_RampOn = true;
          eadd_tq_mot2MaxLTTq_Nm = fmaxf(fminf(fmaxf(rtu_u1 -
            eadd_tq_mot2MaxLTTq_Nm, rtb_MinMax1_k) + eadd_tq_mot2MaxLTTq_Nm,
            rtu_u2), rtu_u1);
        }
      } else {
        eadd_tq_mot2MaxLTTq_Nm = rtu_u2;
      }
      break;

     default:
      /* case IN_U2_TO_U1: */
      if (!rtu_sw) {
        if (rtu_u2 >= rtu_u1) {
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_m;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2_p;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_INC_c;
          *rty_RampOn = true;
          eadd_tq_mot2MaxLTTq_Nm = fminf(fmaxf(fminf(rtu_u2 -
            eadd_tq_mot2MaxLTTq_Nm, rtb_MinMax_o1) + eadd_tq_mot2MaxLTTq_Nm,
            rtu_u1), rtu_u2);
        } else {
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_m;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2_p;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_DEC_g;
          *rty_RampOn = true;
          eadd_tq_mot2MaxLTTq_Nm = fmaxf(fminf(fmaxf(rtu_u2 -
            eadd_tq_mot2MaxLTTq_Nm, rtb_MinMax1_k) + eadd_tq_mot2MaxLTTq_Nm,
            rtu_u1), rtu_u2);
        }
      } else if (swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 ==
                 swc_SCAP_IN_U2_TO_U1_DEC_k) {
        *rty_RampOn = true;
        rtb_MinMax_o1 = rtu_u1 - eadd_tq_mot2MaxLTTq_Nm;
        if (rtb_MinMax_o1 >= rtb_MinMax1_k) {
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_m;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U1_m;
          *rty_RampOn = false;
          eadd_tq_mot2MaxLTTq_Nm = rtu_u1;
        } else {
          eadd_tq_mot2MaxLTTq_Nm = fmaxf(fminf(fmaxf(rtb_MinMax_o1,
            rtb_MinMax1_k) + eadd_tq_mot2MaxLTTq_Nm, rtu_u2), rtu_u1);
        }
      } else {
        /* case IN_U2_TO_U1_INC: */
        *rty_RampOn = true;
        if (rtu_u1 - eadd_tq_mot2MaxLTTq_Nm <= rtb_MinMax_o1) {
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_m;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U1_m;
          *rty_RampOn = false;
          eadd_tq_mot2MaxLTTq_Nm = rtu_u1;
        } else {
          eadd_tq_mot2MaxLTTq_Nm = fminf(fmaxf(fminf(rtu_u1 -
            eadd_tq_mot2MaxLTTq_Nm, rtb_MinMax_o1) + eadd_tq_mot2MaxLTTq_Nm,
            rtu_u2), rtu_u1);
        }
      }
      break;
    }
  }

  /* End of Chart: '<S22>/Chart' */
}

/* System initialize for atomic system: '<S6>/SwitchRampMOTMinPeakTrq' */
static void sw_SwitchRampMOTMinPeakTrq_Init(boolean *rty_RampOn)
{
  /* SystemInitialize for Chart: '<S24>/Chart' */
  *rty_RampOn = false;
}

/* Output and update for atomic system: '<S6>/SwitchRampMOTMinPeakTrq' */
static void swc_SCA_SwitchRampMOTMinPeakTrq(float32 rtu_u1, boolean rtu_sw,
  float32 rtu_u2, float32 rtu_up, float32 rtu_lo, boolean *rty_RampOn,
  ARID_DEF_switch_ramp_swc_SC_k_T *swc_SCAP__ARID_DEF_arg)
{
  float32 rtb_MinMax1_c;
  float32 rtb_MinMax_h;

  /* MinMax: '<S15>/MinMax' incorporates:
   *  Constant: '<S15>/Constant1'
   *  Constant: '<S15>/Constant2'
   *  Product: '<S15>/Product'
   */
  rtb_MinMax_h = fmaxf(rtu_up * 0.01F, 0.0F);

  /* MinMax: '<S15>/MinMax1' incorporates:
   *  Constant: '<S15>/Constant1'
   *  Constant: '<S15>/Constant2'
   *  Product: '<S15>/Product1'
   */
  rtb_MinMax1_c = fminf(0.0F, 0.01F * rtu_lo);

  /* Chart: '<S24>/Chart' */
  if (swc_SCAP__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li == 0U) {
    swc_SCAP__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li = 1U;
    swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2_p;
    *rty_RampOn = false;
    eadd_tq_mot2MinSTTq_Nm = rtu_u2;
  } else {
    switch (swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib) {
     case swc_SCAP_IN_U1_h:
      *rty_RampOn = false;
      if (!rtu_sw) {
        if (rtu_u2 >= rtu_u1) {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2_d;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_INC_f;
          *rty_RampOn = true;
          eadd_tq_mot2MinSTTq_Nm = fminf(fmaxf(fminf(rtu_u2 -
            eadd_tq_mot2MinSTTq_Nm, rtb_MinMax_h) + eadd_tq_mot2MinSTTq_Nm,
            rtu_u1), rtu_u2);
        } else {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2_d;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_DEC_e;
          *rty_RampOn = true;
          eadd_tq_mot2MinSTTq_Nm = fmaxf(fminf(fmaxf(rtu_u2 -
            eadd_tq_mot2MinSTTq_Nm, rtb_MinMax1_c) + eadd_tq_mot2MinSTTq_Nm,
            rtu_u1), rtu_u2);
        }
      } else {
        eadd_tq_mot2MinSTTq_Nm = rtu_u1;
      }
      break;

     case swc_SCAP_IN_U1_TO_U2_d:
      if (rtu_sw) {
        if (rtu_u1 >= rtu_u2) {
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_n;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1_a;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_INC_i;
          *rty_RampOn = true;
          eadd_tq_mot2MinSTTq_Nm = fminf(fmaxf(fminf(rtu_u1 -
            eadd_tq_mot2MinSTTq_Nm, rtb_MinMax_h) + eadd_tq_mot2MinSTTq_Nm,
            rtu_u2), rtu_u1);
        } else {
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_n;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1_a;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_DEC_c;
          *rty_RampOn = true;
          eadd_tq_mot2MinSTTq_Nm = fmaxf(fminf(fmaxf(rtu_u1 -
            eadd_tq_mot2MinSTTq_Nm, rtb_MinMax1_c) + eadd_tq_mot2MinSTTq_Nm,
            rtu_u2), rtu_u1);
        }
      } else if (swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 ==
                 swc_SCAP_IN_U1_TO_U2_DEC_e) {
        *rty_RampOn = true;
        rtb_MinMax_h = rtu_u2 - eadd_tq_mot2MinSTTq_Nm;
        if (rtb_MinMax_h >= rtb_MinMax1_c) {
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_n;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2_p;
          *rty_RampOn = false;
          eadd_tq_mot2MinSTTq_Nm = rtu_u2;
        } else {
          eadd_tq_mot2MinSTTq_Nm = fmaxf(fminf(fmaxf(rtb_MinMax_h, rtb_MinMax1_c)
            + eadd_tq_mot2MinSTTq_Nm, rtu_u1), rtu_u2);
        }
      } else {
        /* case IN_U1_TO_U2_INC: */
        *rty_RampOn = true;
        if (rtu_u2 - eadd_tq_mot2MinSTTq_Nm <= rtb_MinMax_h) {
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_n;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2_p;
          *rty_RampOn = false;
          eadd_tq_mot2MinSTTq_Nm = rtu_u2;
        } else {
          eadd_tq_mot2MinSTTq_Nm = fminf(fmaxf(fminf(rtu_u2 -
            eadd_tq_mot2MinSTTq_Nm, rtb_MinMax_h) + eadd_tq_mot2MinSTTq_Nm,
            rtu_u1), rtu_u2);
        }
      }
      break;

     case swc_SCAP_IN_U2_p:
      *rty_RampOn = false;
      if (rtu_sw) {
        if (rtu_u1 >= rtu_u2) {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1_a;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_INC_i;
          *rty_RampOn = true;
          eadd_tq_mot2MinSTTq_Nm = fminf(fmaxf(fminf(rtu_u1 -
            eadd_tq_mot2MinSTTq_Nm, rtb_MinMax_h) + eadd_tq_mot2MinSTTq_Nm,
            rtu_u2), rtu_u1);
        } else {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1_a;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_DEC_c;
          *rty_RampOn = true;
          eadd_tq_mot2MinSTTq_Nm = fmaxf(fminf(fmaxf(rtu_u1 -
            eadd_tq_mot2MinSTTq_Nm, rtb_MinMax1_c) + eadd_tq_mot2MinSTTq_Nm,
            rtu_u2), rtu_u1);
        }
      } else {
        eadd_tq_mot2MinSTTq_Nm = rtu_u2;
      }
      break;

     default:
      /* case IN_U2_TO_U1: */
      if (!rtu_sw) {
        if (rtu_u2 >= rtu_u1) {
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_n;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2_d;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_INC_f;
          *rty_RampOn = true;
          eadd_tq_mot2MinSTTq_Nm = fminf(fmaxf(fminf(rtu_u2 -
            eadd_tq_mot2MinSTTq_Nm, rtb_MinMax_h) + eadd_tq_mot2MinSTTq_Nm,
            rtu_u1), rtu_u2);
        } else {
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_n;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2_d;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_DEC_e;
          *rty_RampOn = true;
          eadd_tq_mot2MinSTTq_Nm = fmaxf(fminf(fmaxf(rtu_u2 -
            eadd_tq_mot2MinSTTq_Nm, rtb_MinMax1_c) + eadd_tq_mot2MinSTTq_Nm,
            rtu_u1), rtu_u2);
        }
      } else if (swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 ==
                 swc_SCAP_IN_U2_TO_U1_DEC_c) {
        *rty_RampOn = true;
        rtb_MinMax_h = rtu_u1 - eadd_tq_mot2MinSTTq_Nm;
        if (rtb_MinMax_h >= rtb_MinMax1_c) {
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_n;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U1_h;
          *rty_RampOn = false;
          eadd_tq_mot2MinSTTq_Nm = rtu_u1;
        } else {
          eadd_tq_mot2MinSTTq_Nm = fmaxf(fminf(fmaxf(rtb_MinMax_h, rtb_MinMax1_c)
            + eadd_tq_mot2MinSTTq_Nm, rtu_u2), rtu_u1);
        }
      } else {
        /* case IN_U2_TO_U1_INC: */
        *rty_RampOn = true;
        if (rtu_u1 - eadd_tq_mot2MinSTTq_Nm <= rtb_MinMax_h) {
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_n;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U1_h;
          *rty_RampOn = false;
          eadd_tq_mot2MinSTTq_Nm = rtu_u1;
        } else {
          eadd_tq_mot2MinSTTq_Nm = fminf(fmaxf(fminf(rtu_u1 -
            eadd_tq_mot2MinSTTq_Nm, rtb_MinMax_h) + eadd_tq_mot2MinSTTq_Nm,
            rtu_u2), rtu_u1);
        }
      }
      break;
    }
  }

  /* End of Chart: '<S24>/Chart' */
}

/* System initialize for atomic system: '<S6>/SwitchRampMOTMinTrq' */
static void swc_SC_SwitchRampMOTMinTrq_Init(boolean *rty_RampOn)
{
  /* SystemInitialize for Chart: '<S26>/Chart' */
  *rty_RampOn = false;
}

/* Output and update for atomic system: '<S6>/SwitchRampMOTMinTrq' */
static void swc_SCAP_SwitchRampMOTMinTrq(float32 rtu_u1, boolean rtu_sw, float32
  rtu_u2, float32 rtu_up, float32 rtu_lo, boolean *rty_RampOn,
  ARID_DEF_switch_ramp_swc_SC_d_T *swc_SCAP__ARID_DEF_arg)
{
  float32 rtb_MinMax1_c;
  float32 rtb_MinMax_p;

  /* MinMax: '<S16>/MinMax' incorporates:
   *  Constant: '<S16>/Constant1'
   *  Constant: '<S16>/Constant2'
   *  Product: '<S16>/Product'
   */
  rtb_MinMax_p = fmaxf(rtu_up * 0.01F, 0.0F);

  /* MinMax: '<S16>/MinMax1' incorporates:
   *  Constant: '<S16>/Constant1'
   *  Constant: '<S16>/Constant2'
   *  Product: '<S16>/Product1'
   */
  rtb_MinMax1_c = fminf(0.0F, 0.01F * rtu_lo);

  /* Chart: '<S26>/Chart' */
  if (swc_SCAP__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li == 0U) {
    swc_SCAP__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li = 1U;
    swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2_k;
    *rty_RampOn = false;
    eadd_tq_mot2MinLTTq_Nm = rtu_u2;
  } else {
    switch (swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib) {
     case swc_SCAP_IN_U1_c:
      *rty_RampOn = false;
      if (!rtu_sw) {
        if (rtu_u2 >= rtu_u1) {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2_i;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_INC_l;
          *rty_RampOn = true;
          eadd_tq_mot2MinLTTq_Nm = fminf(fmaxf(fminf(rtu_u2 -
            eadd_tq_mot2MinLTTq_Nm, rtb_MinMax_p) + eadd_tq_mot2MinLTTq_Nm,
            rtu_u1), rtu_u2);
        } else {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2_i;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_DEC_l;
          *rty_RampOn = true;
          eadd_tq_mot2MinLTTq_Nm = fmaxf(fminf(fmaxf(rtu_u2 -
            eadd_tq_mot2MinLTTq_Nm, rtb_MinMax1_c) + eadd_tq_mot2MinLTTq_Nm,
            rtu_u1), rtu_u2);
        }
      } else {
        eadd_tq_mot2MinLTTq_Nm = rtu_u1;
      }
      break;

     case swc_SCAP_IN_U1_TO_U2_i:
      if (rtu_sw) {
        if (rtu_u1 >= rtu_u2) {
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_h;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1_p;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_INC_ki;
          *rty_RampOn = true;
          eadd_tq_mot2MinLTTq_Nm = fminf(fmaxf(fminf(rtu_u1 -
            eadd_tq_mot2MinLTTq_Nm, rtb_MinMax_p) + eadd_tq_mot2MinLTTq_Nm,
            rtu_u2), rtu_u1);
        } else {
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_h;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1_p;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_DEC_ca;
          *rty_RampOn = true;
          eadd_tq_mot2MinLTTq_Nm = fmaxf(fminf(fmaxf(rtu_u1 -
            eadd_tq_mot2MinLTTq_Nm, rtb_MinMax1_c) + eadd_tq_mot2MinLTTq_Nm,
            rtu_u2), rtu_u1);
        }
      } else if (swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 ==
                 swc_SCAP_IN_U1_TO_U2_DEC_l) {
        *rty_RampOn = true;
        rtb_MinMax_p = rtu_u2 - eadd_tq_mot2MinLTTq_Nm;
        if (rtb_MinMax_p >= rtb_MinMax1_c) {
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_h;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2_k;
          *rty_RampOn = false;
          eadd_tq_mot2MinLTTq_Nm = rtu_u2;
        } else {
          eadd_tq_mot2MinLTTq_Nm = fmaxf(fminf(fmaxf(rtb_MinMax_p, rtb_MinMax1_c)
            + eadd_tq_mot2MinLTTq_Nm, rtu_u1), rtu_u2);
        }
      } else {
        /* case IN_U1_TO_U2_INC: */
        *rty_RampOn = true;
        if (rtu_u2 - eadd_tq_mot2MinLTTq_Nm <= rtb_MinMax_p) {
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_h;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2_k;
          *rty_RampOn = false;
          eadd_tq_mot2MinLTTq_Nm = rtu_u2;
        } else {
          eadd_tq_mot2MinLTTq_Nm = fminf(fmaxf(fminf(rtu_u2 -
            eadd_tq_mot2MinLTTq_Nm, rtb_MinMax_p) + eadd_tq_mot2MinLTTq_Nm,
            rtu_u1), rtu_u2);
        }
      }
      break;

     case swc_SCAP_IN_U2_k:
      *rty_RampOn = false;
      if (rtu_sw) {
        if (rtu_u1 >= rtu_u2) {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1_p;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_INC_ki;
          *rty_RampOn = true;
          eadd_tq_mot2MinLTTq_Nm = fminf(fmaxf(fminf(rtu_u1 -
            eadd_tq_mot2MinLTTq_Nm, rtb_MinMax_p) + eadd_tq_mot2MinLTTq_Nm,
            rtu_u2), rtu_u1);
        } else {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1_p;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_DEC_ca;
          *rty_RampOn = true;
          eadd_tq_mot2MinLTTq_Nm = fmaxf(fminf(fmaxf(rtu_u1 -
            eadd_tq_mot2MinLTTq_Nm, rtb_MinMax1_c) + eadd_tq_mot2MinLTTq_Nm,
            rtu_u2), rtu_u1);
        }
      } else {
        eadd_tq_mot2MinLTTq_Nm = rtu_u2;
      }
      break;

     default:
      /* case IN_U2_TO_U1: */
      if (!rtu_sw) {
        if (rtu_u2 >= rtu_u1) {
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_h;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2_i;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_INC_l;
          *rty_RampOn = true;
          eadd_tq_mot2MinLTTq_Nm = fminf(fmaxf(fminf(rtu_u2 -
            eadd_tq_mot2MinLTTq_Nm, rtb_MinMax_p) + eadd_tq_mot2MinLTTq_Nm,
            rtu_u1), rtu_u2);
        } else {
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_h;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2_i;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_DEC_l;
          *rty_RampOn = true;
          eadd_tq_mot2MinLTTq_Nm = fmaxf(fminf(fmaxf(rtu_u2 -
            eadd_tq_mot2MinLTTq_Nm, rtb_MinMax1_c) + eadd_tq_mot2MinLTTq_Nm,
            rtu_u1), rtu_u2);
        }
      } else if (swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 ==
                 swc_SCAP_IN_U2_TO_U1_DEC_ca) {
        *rty_RampOn = true;
        rtb_MinMax_p = rtu_u1 - eadd_tq_mot2MinLTTq_Nm;
        if (rtb_MinMax_p >= rtb_MinMax1_c) {
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_h;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U1_c;
          *rty_RampOn = false;
          eadd_tq_mot2MinLTTq_Nm = rtu_u1;
        } else {
          eadd_tq_mot2MinLTTq_Nm = fmaxf(fminf(fmaxf(rtb_MinMax_p, rtb_MinMax1_c)
            + eadd_tq_mot2MinLTTq_Nm, rtu_u2), rtu_u1);
        }
      } else {
        /* case IN_U2_TO_U1_INC: */
        *rty_RampOn = true;
        if (rtu_u1 - eadd_tq_mot2MinLTTq_Nm <= rtb_MinMax_p) {
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_h;
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U1_c;
          *rty_RampOn = false;
          eadd_tq_mot2MinLTTq_Nm = rtu_u1;
        } else {
          eadd_tq_mot2MinLTTq_Nm = fminf(fmaxf(fminf(rtu_u1 -
            eadd_tq_mot2MinLTTq_Nm, rtb_MinMax_p) + eadd_tq_mot2MinLTTq_Nm,
            rtu_u2), rtu_u1);
        }
      }
      break;
    }
  }

  /* End of Chart: '<S26>/Chart' */
}

/*
 * Output and update for action system:
 *    '<S17>/pos'
 *    '<S18>/pos'
 *    '<S54>/pos'
 *    '<S67>/pos'
 *    '<S63>/pos'
 *    '<S82>/pos'
 *    '<S83>/pos'
 *    '<S84>/pos'
 *    '<S108>/pos'
 */
static void swc_SCAP_pos(float32 rtu_in_val, float32 *rty_same_val)
{
  /* SignalConversion generated from: '<S29>/in_val' */
  *rty_same_val = rtu_in_val;
}

/*
 * Output and update for action system:
 *    '<S17>/neg'
 *    '<S18>/neg'
 *    '<S54>/neg'
 *    '<S67>/neg'
 *    '<S63>/neg'
 *    '<S82>/neg'
 *    '<S83>/neg'
 *    '<S84>/neg'
 *    '<S108>/neg'
 */
static void swc_SCAP_neg(float32 rtu_in_val, float32 *rty_neg_val)
{
  /* UnaryMinus: '<S28>/Unary Minus' */
  *rty_neg_val = -rtu_in_val;
}

/*
 * Output and update for atomic system:
 *    '<S19>/SR_latch'
 *    '<S19>/SR_latch1'
 */
static void swc_SCAP_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch_swc_SCAP_T *swc_SCAP__ARID_DEF_arg)
{
  /* Logic: '<S35>/Logical Operator3' incorporates:
   *  Logic: '<S35>/Logical Operator'
   *  Logic: '<S35>/Logical Operator1'
   *  UnitDelay: '<S35>/Unit Delay'
   */
  *rty_flg_out = ((swc_SCAP__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) && (
    !rtu_flg_reset));

  /* Update for UnitDelay: '<S35>/Unit Delay' */
  swc_SCAP__ARID_DEF_arg->UnitDelay_DSTATE = *rty_flg_out;
}

/*
 * System initialize for atomic system:
 *    '<S19>/SwitchRampMOTMaxTrq1'
 *    '<S58>/switch_ramp'
 */
static void swc_S_SwitchRampMOTMaxTrq1_Init(float32 *rty_y, boolean *rty_RampOn)
{
  /* SystemInitialize for Chart: '<S39>/Chart' */
  *rty_y = 0.0F;
  *rty_RampOn = false;
}

/*
 * Output and update for atomic system:
 *    '<S19>/SwitchRampMOTMaxTrq1'
 *    '<S58>/switch_ramp'
 */
static void swc_SCAP_SwitchRampMOTMaxTrq1(float32 rtu_u1, boolean rtu_sw,
  float32 rtu_u2, float32 rtu_up, float32 rtu_lo, float32 *rty_y, boolean
  *rty_RampOn, ARID_DEF_switch_ramp_swc_S_dk_T *swc_SCAP__ARID_DEF_arg)
{
  float32 rtb_MinMax1_a;
  float32 rtb_MinMax_f;

  /* MinMax: '<S37>/MinMax' incorporates:
   *  Constant: '<S37>/Constant1'
   *  Constant: '<S37>/Constant2'
   *  Product: '<S37>/Product'
   */
  rtb_MinMax_f = fmaxf(rtu_up * 0.01F, 0.0F);

  /* MinMax: '<S37>/MinMax1' incorporates:
   *  Constant: '<S37>/Constant1'
   *  Constant: '<S37>/Constant2'
   *  Product: '<S37>/Product1'
   */
  rtb_MinMax1_a = fminf(0.0F, 0.01F * rtu_lo);

  /* Chart: '<S39>/Chart' */
  if (swc_SCAP__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li == 0U) {
    swc_SCAP__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li = 1U;
    swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2_i;
    *rty_RampOn = false;
    *rty_y = rtu_u2;
  } else {
    switch (swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib) {
     case swc_SCAP_IN_U1_p:
      *rty_RampOn = false;
      if (!rtu_sw) {
        if (rtu_u2 >= rtu_u1) {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2_n;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_INC_j;
          *rty_RampOn = true;
          *rty_y = fminf(fmaxf(fminf(rtu_u2 - *rty_y, rtb_MinMax_f) + *rty_y,
                               rtu_u1), rtu_u2);
        } else {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2_n;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_DEC_ge;
          *rty_RampOn = true;
          *rty_y = fmaxf(fminf(fmaxf(rtu_u2 - *rty_y, rtb_MinMax1_a) + *rty_y,
                               rtu_u1), rtu_u2);
        }
      } else {
        *rty_y = rtu_u1;
      }
      break;

     case swc_SCAP_IN_U1_TO_U2_n:
      {
        if (rtu_sw) {
          if (rtu_u1 >= rtu_u2) {
            swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_i;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_SCAP_IN_U2_TO_U1_f;
            swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_INC_b;
            *rty_RampOn = true;
            *rty_y = fminf(fmaxf(fminf(rtu_u1 - *rty_y, rtb_MinMax_f) + *rty_y,
                                 rtu_u2), rtu_u1);
          } else {
            swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_i;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_SCAP_IN_U2_TO_U1_f;
            swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_DEC_l;
            *rty_RampOn = true;
            *rty_y = fmaxf(fminf(fmaxf(rtu_u1 - *rty_y, rtb_MinMax1_a) + *rty_y,
                                 rtu_u2), rtu_u1);
          }
        } else if (swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 ==
                   swc_SCAP_IN_U1_TO_U2_DEC_ge) {
          float32 tmp;
          *rty_RampOn = true;
          tmp = rtu_u2 - *rty_y;
          if (tmp >= rtb_MinMax1_a) {
            swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_i;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2_i;
            *rty_RampOn = false;
            *rty_y = rtu_u2;
          } else {
            *rty_y = fmaxf(fminf(fmaxf(tmp, rtb_MinMax1_a) + *rty_y, rtu_u1),
                           rtu_u2);
          }
        } else {
          float32 tmp;

          /* case IN_U1_TO_U2_INC: */
          *rty_RampOn = true;
          tmp = rtu_u2 - *rty_y;
          if (tmp <= rtb_MinMax_f) {
            swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_i;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2_i;
            *rty_RampOn = false;
            *rty_y = rtu_u2;
          } else {
            *rty_y = fminf(fmaxf(fminf(tmp, rtb_MinMax_f) + *rty_y, rtu_u1),
                           rtu_u2);
          }
        }
      }
      break;

     case swc_SCAP_IN_U2_i:
      *rty_RampOn = false;
      if (rtu_sw) {
        if (rtu_u1 >= rtu_u2) {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1_f;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_INC_b;
          *rty_RampOn = true;
          *rty_y = fminf(fmaxf(fminf(rtu_u1 - *rty_y, rtb_MinMax_f) + *rty_y,
                               rtu_u2), rtu_u1);
        } else {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1_f;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_DEC_l;
          *rty_RampOn = true;
          *rty_y = fmaxf(fminf(fmaxf(rtu_u1 - *rty_y, rtb_MinMax1_a) + *rty_y,
                               rtu_u2), rtu_u1);
        }
      } else {
        *rty_y = rtu_u2;
      }
      break;

     default:
      {
        /* case IN_U2_TO_U1: */
        if (!rtu_sw) {
          if (rtu_u2 >= rtu_u1) {
            swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_i;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_SCAP_IN_U1_TO_U2_n;
            swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_INC_j;
            *rty_RampOn = true;
            *rty_y = fminf(fmaxf(fminf(rtu_u2 - *rty_y, rtb_MinMax_f) + *rty_y,
                                 rtu_u1), rtu_u2);
          } else {
            swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_i;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_SCAP_IN_U1_TO_U2_n;
            swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_DEC_ge;
            *rty_RampOn = true;
            *rty_y = fmaxf(fminf(fmaxf(rtu_u2 - *rty_y, rtb_MinMax1_a) + *rty_y,
                                 rtu_u1), rtu_u2);
          }
        } else if (swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 ==
                   swc_SCAP_IN_U2_TO_U1_DEC_l) {
          float32 tmp;
          *rty_RampOn = true;
          tmp = rtu_u1 - *rty_y;
          if (tmp >= rtb_MinMax1_a) {
            swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_i;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U1_p;
            *rty_RampOn = false;
            *rty_y = rtu_u1;
          } else {
            *rty_y = fmaxf(fminf(fmaxf(tmp, rtb_MinMax1_a) + *rty_y, rtu_u2),
                           rtu_u1);
          }
        } else {
          float32 tmp;

          /* case IN_U2_TO_U1_INC: */
          *rty_RampOn = true;
          tmp = rtu_u1 - *rty_y;
          if (tmp <= rtb_MinMax_f) {
            swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_i;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U1_p;
            *rty_RampOn = false;
            *rty_y = rtu_u1;
          } else {
            *rty_y = fminf(fmaxf(fminf(tmp, rtb_MinMax_f) + *rty_y, rtu_u2),
                           rtu_u1);
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<S39>/Chart' */
}

/* System initialize for function-call system: '<S1>/EAD_TorqueLimitsMot2' */
static void swc_S_EAD_TorqueLimitsMot2_Init(void)
{
  /* local block i/o variables */
  boolean rtb_RampOn;
  boolean rtb_RampOn_g;
  boolean rtb_RampOn_a;
  boolean rtb_RampOn_h;
  boolean rtb_RampOn_p;

  /* SystemInitialize for Atomic SubSystem: '<S19>/SwitchRampMOTMaxTrq1' */
  swc_S_SwitchRampMOTMaxTrq1_Init(&swc_SCAP_ARID_DEF.y_j, &rtb_RampOn);

  /* End of SystemInitialize for SubSystem: '<S19>/SwitchRampMOTMaxTrq1' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/SwitchRampMOTMaxPeakTrq' */
  swc_SCAP_switch_ramp_Init(&rtb_RampOn_p);

  /* End of SystemInitialize for SubSystem: '<S6>/SwitchRampMOTMaxPeakTrq' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/SwitchRampMOTMinPeakTrq' */
  sw_SwitchRampMOTMinPeakTrq_Init(&rtb_RampOn_a);

  /* End of SystemInitialize for SubSystem: '<S6>/SwitchRampMOTMinPeakTrq' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/SwitchRampMOTMaxTrq' */
  swc_SC_SwitchRampMOTMaxTrq_Init(&rtb_RampOn_h);

  /* End of SystemInitialize for SubSystem: '<S6>/SwitchRampMOTMaxTrq' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/SwitchRampMOTMinTrq' */
  swc_SC_SwitchRampMOTMinTrq_Init(&rtb_RampOn_g);

  /* End of SystemInitialize for SubSystem: '<S6>/SwitchRampMOTMinTrq' */
}

/* Output and update for function-call system: '<S1>/EAD_TorqueLimitsMot2' */
static void swc_SCAP_EAD_TorqueLimitsMot2(void)
{
  /* local block i/o variables */
  float32 rtb_Merge;
  float32 rtb_Switch3;
  float32 rtb_Switch6;
  float32 rtb_Switch5;
  float32 rtb_Switch4;
  float32 rtb_Switch;
  float32 rtb_Switch1;
  float32 rtb_Switch2;
  float32 rtb_Switch7;
  float32 rtb_Merge_m;
  float32 rtb_Merge_l;
  boolean rtb_LogicalOperator7_n;
  boolean rtb_LogicalOperator5_k;
  boolean rtb_LogicalOperator4_e;
  boolean rtb_LogicalOperator3_o;
  boolean rtb_LogicalOperator17;
  boolean rtb_RampOn;
  boolean rtb_LogicalOperator3_b;
  boolean rtb_RampOn_g;
  boolean rtb_RampOn_a;
  boolean rtb_RampOn_h;
  boolean rtb_RampOn_p;
  boolean rtb_LogicalOperator3_f;
  float32 rtb_Switch3_n;
  float32 rtb_t_delay_on;
  DriveDir rtb_LogicalOperator3_i_tmp_0;
  ElMac rtb_LogicalOperator3_i_tmp;
  uint8 eadd_b_mot2BstTqEnad_tmp;
  uint8 rtb_Switch2_j;
  uint8 tmp;
  boolean rtb_LogicalOperator11;
  boolean rtb_LogicalOperator3_c;
  boolean rtb_flg_out;

  /* RelationalOperator: '<S7>/Relational Operator13' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion60'
   *  RelationalOperator: '<S7>/Relational Operator12'
   */
  rtb_LogicalOperator3_i_tmp = swc_SCAP_ARID_DEF.DataTypeConversion60;

  /* RelationalOperator: '<S7>/Relational Operator3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion8'
   *  RelationalOperator: '<S7>/Relational Operator2'
   *  RelationalOperator: '<S7>/Relational Operator4'
   *  RelationalOperator: '<S7>/Relational Operator7'
   *  Switch: '<S7>/Switch2'
   */
  rtb_LogicalOperator3_i_tmp_0 = swc_SCAP_ARID_DEF.DataTypeConversion8;

  /* Logic: '<S7>/Logical Operator3' incorporates:
   *  Constant: '<S45>/Constant'
   *  Constant: '<S46>/Constant'
   *  Constant: '<S50>/Constant'
   *  Constant: '<S51>/Constant'
   *  Constant: '<S7>/Constant12'
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/Constant4'
   *  Logic: '<S7>/Logical Operator13'
   *  Logic: '<S7>/Logical Operator18'
   *  Logic: '<S7>/Logical Operator19'
   *  Logic: '<S7>/Logical Operator7'
   *  Logic: '<S7>/Logical Operator8'
   *  Logic: '<S7>/Logical Operator9'
   *  RelationalOperator: '<S7>/Relational Operator1'
   *  RelationalOperator: '<S7>/Relational Operator12'
   *  RelationalOperator: '<S7>/Relational Operator13'
   *  RelationalOperator: '<S7>/Relational Operator3'
   *  RelationalOperator: '<S7>/Relational Operator4'
   */
  rtb_LogicalOperator3_c = (swc_SCAP_ARID_DEF.DataTypeConversion57 &&
    ((rtb_LogicalOperator3_i_tmp == ElMac_SPEED_CTRL) ||
     (rtb_LogicalOperator3_i_tmp == ElMac_TORQUE_CTRL)) && eadc_b_enaMot2Tq &&
    ((rtb_LogicalOperator3_i_tmp_0 != DriveDir_NO_DRIVE) &&
     (rtb_LogicalOperator3_i_tmp_0 != DriveDir_INVALID)) &&
    ((swc_SCAP_ARID_DEF.DataTypeConversion71 != ((uint8)0U)) ||
     swc_SCAP_ARID_DEF.DataTypeConversion70 || (!eadc_b_disMot2TqInGear0)) &&
    (!swc_SCAP_ARID_DEF.DataTypeConversion52));

  /* RelationalOperator: '<S44>/Compare' incorporates:
   *  Inport generated from: '<Root>/Bus Element In'
   *  RelationalOperator: '<S33>/Compare'
   */
  eadd_b_mot2BstTqEnad_tmp = Rte_IRead_swc_SCAP_Step_vcsb_OGVL_dtld_st_pwrOffCmd
    ();

  /* Logic: '<S7>/Logical Operator20' incorporates:
   *  Constant: '<S44>/Constant'
   *  Inport generated from: '<Root>/In Bus Element31'
   *  Inport generated from: '<Root>/Bus Element In'
   *  RelationalOperator: '<S44>/Compare'
   */
  eadd_b_mot2BstTqEnad = (rtb_LogicalOperator3_c &&
    Rte_IRead_swc_SCAP_Step_vcsb_EGYM_egmd_b_mcuEnbFlg() &&
    (eadd_b_mot2BstTqEnad_tmp == ((uint8)0U)));

  /* Logic: '<S7>/Logical Operator11' incorporates:
   *  Constant: '<S7>/Constant3'
   *  Logic: '<S7>/Logical Operator10'
   *  Logic: '<S7>/Logical Operator12'
   *  Logic: '<S7>/Logical Operator32'
   */
  rtb_LogicalOperator11 = ((!scap_eadd_b_ehbMsgErrDebd) ||
    (!eadc_b_disMot2BrkTqDurgESP));

  /* Relay: '<S7>/Relay2' */
  swc_SCAP_ARID_DEF.Relay2_Mode = ((swc_SCAP_ARID_DEF.DataTypeConversion38 >=
    swcscap_eadc_n_mot2GenEnaHiThdAdc_rpm) ||
    ((swc_SCAP_ARID_DEF.DataTypeConversion38 >
      swcscap_eadc_n_mot2GenEnaLoThdAdc_rpm) && swc_SCAP_ARID_DEF.Relay2_Mode));
  if (swc_SCAP_ARID_DEF.Relay2_Mode) {
    /* Switch: '<S7>/Switch2' */
    rtb_Switch2_j = ((uint8)1U);
  } else {
    /* Switch: '<S7>/Switch2' */
    rtb_Switch2_j = ((uint8)0U);
  }

  /* End of Relay: '<S7>/Relay2' */

  /* Relay: '<S7>/Relay1' */
  swc_SCAP_ARID_DEF.Relay1_Mode = ((swc_SCAP_ARID_DEF.DataTypeConversion38 >=
    eadc_n_mot2GenDisHiThdRev_rpm) || ((swc_SCAP_ARID_DEF.DataTypeConversion38 >
    eadc_n_mot2GenDisLoThdRev_rpm) && swc_SCAP_ARID_DEF.Relay1_Mode));

  /* Relay: '<S7>/Relay' */
  swc_SCAP_ARID_DEF.Relay_Mode = ((swc_SCAP_ARID_DEF.DataTypeConversion38 >=
    eadc_n_mot2GenEnaHiThdFwd_rpm) || ((swc_SCAP_ARID_DEF.DataTypeConversion38 >
    eadc_n_mot2GenEnaLoThdFwd_rpm) && swc_SCAP_ARID_DEF.Relay_Mode));

  /* RelationalOperator: '<S42>/Compare' incorporates:
   *  Inport generated from: '<Root>/In Bus Element83'
   *  RelationalOperator: '<S43>/Compare'
   */
  tmp = Rte_IRead_swc_SCAP_Step_vcib_VCIP_adcd_st_pmsAdcCtrldSts();

  /* Switch: '<S7>/Switch2' incorporates:
   *  Constant: '<S42>/Constant'
   *  Constant: '<S43>/Constant'
   *  Constant: '<S49>/Constant'
   *  Constant: '<S7>/Constant8'
   *  Inport generated from: '<Root>/In Bus Element83'
   *  Inport generated from: '<Root>/In Bus Element85'
   *  Logic: '<S7>/Logical Operator28'
   *  Logic: '<S7>/Logical Operator29'
   *  RelationalOperator: '<S42>/Compare'
   *  RelationalOperator: '<S43>/Compare'
   *  RelationalOperator: '<S7>/Relational Operator5'
   */
  if (((tmp != ((uint8)0U)) && (tmp != ((uint8)1U))) ||
      (Rte_IRead_swc_SCAP_Step_vcib_VCIP_brpd_e_brkPedalStatus() ==
       BrakePedalStatus_PRESSED) || (!swcscap_eadc_b_adcOvrCtlPmt)) {
    /* Switch: '<S7>/Switch' incorporates:
     *  Constant: '<S48>/Constant'
     *  RelationalOperator: '<S7>/Relational Operator7'
     *  Relay: '<S7>/Relay'
     */
    if (rtb_LogicalOperator3_i_tmp_0 == DriveDir_REVERSE) {
      /* Relay: '<S7>/Relay1' */
      if (swc_SCAP_ARID_DEF.Relay1_Mode) {
        /* Switch: '<S7>/Switch2' */
        rtb_Switch2_j = ((uint8)0U);
      } else {
        /* Switch: '<S7>/Switch2' */
        rtb_Switch2_j = ((uint8)1U);
      }
    } else if (swc_SCAP_ARID_DEF.Relay_Mode) {
      /* Relay: '<S7>/Relay' incorporates:
       *  Switch: '<S7>/Switch2'
       */
      rtb_Switch2_j = ((uint8)1U);
    } else {
      /* Switch: '<S7>/Switch2' incorporates:
       *  Relay: '<S7>/Relay'
       */
      rtb_Switch2_j = ((uint8)0U);
    }

    /* End of Switch: '<S7>/Switch' */
  }

  /* Logic: '<S36>/Logical Operator3' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   */
  rtb_LogicalOperator3_f = (rtb_Switch2_j != 0);

  /* Logic: '<S7>/Logical Operator1' incorporates:
   *  Constant: '<S47>/Constant'
   *  Constant: '<S7>/Constant6'
   *  Constant: '<S7>/Constant7'
   *  Logic: '<S7>/Logical Operator2'
   *  Logic: '<S7>/Logical Operator4'
   *  Logic: '<S7>/Logical Operator5'
   *  Logic: '<S7>/Logical Operator6'
   *  RelationalOperator: '<S7>/Relational Operator2'
   */
  eadd_b_mot2BrkTqEnad = (rtb_LogicalOperator3_c && rtb_LogicalOperator11 &&
    ((rtb_LogicalOperator3_i_tmp_0 == DriveDir_FORWARD) ||
     (eadc_b_enaMot2GenGearR && (!swc_SCAP_ARID_DEF.DataTypeConversion28)) ||
     (swc_SCAP_ARID_DEF.DataTypeConversion28 && eadc_b_enaMot2GenInEVGearR)) &&
    rtb_LogicalOperator3_f);

  /* If: '<S54>/If' incorporates:
   *  Constant: '<S54>/Constant'
   */
  if (swc_SCAP_ARID_DEF.DataTypeConversion38 >= 0.0F) {
    /* Outputs for IfAction SubSystem: '<S54>/pos' incorporates:
     *  ActionPort: '<S56>/Action Port'
     */
    swc_SCAP_pos(swc_SCAP_ARID_DEF.DataTypeConversion38, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S54>/pos' */
  } else {
    /* Outputs for IfAction SubSystem: '<S54>/neg' incorporates:
     *  ActionPort: '<S55>/Action Port'
     */
    swc_SCAP_neg(swc_SCAP_ARID_DEF.DataTypeConversion38, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S54>/neg' */
  }

  /* End of If: '<S54>/If' */

  /* RelationalOperator: '<S53>/Compare' incorporates:
   *  Inport generated from: '<Root>/In Bus Element86'
   *  RelationalOperator: '<S52>/Compare'
   */
  tmp = Rte_IRead_swc_SCAP_Step_vcib_VCIP_vild_st_flgFctCfgMotTyp();

  /* Switch: '<S8>/Switch3' incorporates:
   *  Constant: '<S53>/Constant'
   *  Constant: '<S8>/Constant13'
   *  Inport generated from: '<Root>/In Bus Element86'
   *  Logic: '<S8>/Logical Operator37'
   *  RelationalOperator: '<S53>/Compare'
   */
  if ((tmp == ((uint8)2U)) && scap_eadc_b_useFctCfgMot) {
    /* Switch: '<S8>/Switch3' incorporates:
     *  Lookup_n-D: '<S8>/1-D Lookup Table1'
     *  Merge: '<S54>/Merge'
     */
    rtb_Switch3_n = look1_iflf_binlcapw(rtb_Merge, (const float32 *)
      &scap_eadf_mot2MxTqLimMotTyp2_X_rpm[0], (const float32 *)
      &scap_eadf_mot2MxTqLimMotTyp2_Y_Nm[0], 12U);
  } else {
    /* Switch: '<S8>/Switch3' incorporates:
     *  Lookup_n-D: '<S8>/1-D Lookup Table2'
     *  Merge: '<S54>/Merge'
     */
    rtb_Switch3_n = look1_iflf_binlcapw(rtb_Merge, (const float32 *)
      &eadf_mot2MxTqLim_X_motSpd_rpm[0], (const float32 *)
      &eadf_mot2MxTqLim_Y_Nm[0], 10U);
  }

  /* End of Switch: '<S8>/Switch3' */

  /* MinMax: '<S8>/MinMax1' */
  eadd_tq_mot2MaxSTTqLimd_Nm = fminf(swc_SCAP_ARID_DEF.DataTypeConversion68,
    rtb_Switch3_n);

  /* Switch: '<S6>/Switch3' incorporates:
   *  Constant: '<S6>/Constant15'
   *  Logic: '<S6>/Logical Operator2'
   *  RelationalOperator: '<S11>/FixPt Relational Operator'
   *  UnitDelay: '<S11>/Delay Input1'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (eadc_b_useActTq2SwtOffMot2 && ((sint32)eadd_b_mot2BstTqEnad < (sint32)
       swc_SCAP_ARID_DEF.DelayInput1_DSTATE_e)) {
    /* Switch: '<S6>/Switch3' incorporates:
     *  Constant: '<S6>/Constant16'
     *  MinMax: '<S6>/MinMax2'
     */
    rtb_Switch3 = fmaxf(swc_SCAP_ARID_DEF.DataTypeConversion49, 0.0F);
  } else {
    /* Switch: '<S6>/Switch3' */
    rtb_Switch3 = eadd_tq_mot2MaxSTTqLimd_Nm;
  }

  /* End of Switch: '<S6>/Switch3' */

  /* Logic: '<S19>/Logical Operator6' incorporates:
   *  Constant: '<S32>/Constant'
   *  Constant: '<S33>/Constant'
   *  RelationalOperator: '<S32>/Compare'
   *  RelationalOperator: '<S33>/Compare'
   */
  rtb_LogicalOperator3_c = ((eadd_b_mot2BstTqEnad_tmp != ((uint8)0U)) &&
    (eadd_b_mot2BstTqEnad == false));

  /* Logic: '<S19>/Logical Operator7' incorporates:
   *  Constant: '<S19>/Constant3'
   *  RelationalOperator: '<S19>/Relational Operator1'
   */
  rtb_LogicalOperator7_n = ((swc_SCAP_ARID_DEF.DataTypeConversion65 >
    scap_eadc_v_pwrOffCmdVspdThd_kmh) && rtb_LogicalOperator3_c);

  /* Outputs for Atomic SubSystem: '<S19>/turnON_delay' */
  /* Saturate: '<S38>/Saturation' incorporates:
   *  Constant: '<S19>/Constant28'
   */
  if (scap_eadc_tm_pwrOffCmdLmtDly_s > 1.6777216E+7F) {
    /* Saturate: '<S38>/Saturation' */
    rtb_t_delay_on = 1.6777216E+7F;
  } else if (scap_eadc_tm_pwrOffCmdLmtDly_s < 0.0F) {
    /* Saturate: '<S38>/Saturation' */
    rtb_t_delay_on = 0.0F;
  } else {
    /* Saturate: '<S38>/Saturation' */
    rtb_t_delay_on = scap_eadc_tm_pwrOffCmdLmtDly_s;
  }

  /* End of Saturate: '<S38>/Saturation' */

  /* Chart: '<S38>/timed_delay' incorporates:
   *  Constant: '<S19>/Constant41'
   *  DataTypeConversion: '<S38>/Data Type Conversion'
   */
  if (swc_SCAP_ARID_DEF.is_active_c14_Ricardo_SW_dev_fv == 0U) {
    swc_SCAP_ARID_DEF.is_active_c14_Ricardo_SW_dev_fv = 1U;
    if (rtb_LogicalOperator3_c) {
      swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_d = swc_SCAP_IN_ON;
      rtb_flg_out = true;
    } else {
      swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_d = swc_SCAP_IN_OFF;
      rtb_flg_out = false;
    }
  } else {
    switch (swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_d) {
     case swc_SCAP_IN_OFF:
      if (rtb_LogicalOperator3_c) {
        if (rtb_t_delay_on == 0.0F) {
          swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_d = swc_SCAP_IN_ON;
          rtb_flg_out = true;
        } else {
          swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_d = swc_SCAP_IN_ON_WAIT;
          swc_SCAP_ARID_DEF.t_wait_l = ((float32)EAD_TASK_INTERVAL_S);
          rtb_flg_out = false;
        }
      } else {
        rtb_flg_out = false;
      }
      break;

     case swc_SCAP_IN_ON:
      if (!rtb_LogicalOperator3_c) {
        swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_d = swc_SCAP_IN_OFF;
        rtb_flg_out = false;
      } else {
        rtb_flg_out = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtb_LogicalOperator3_c) {
        swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_d = swc_SCAP_IN_OFF;
        rtb_flg_out = false;
      } else if (swc_SCAP_ARID_DEF.t_wait_l > rtb_t_delay_on - ((float32)
                  EAD_TASK_INTERVAL_S)) {
        swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_d = swc_SCAP_IN_ON;
        rtb_flg_out = true;
      } else {
        swc_SCAP_ARID_DEF.t_wait_l += ((float32)EAD_TASK_INTERVAL_S);
        rtb_flg_out = false;
      }
      break;
    }
  }

  /* End of Chart: '<S38>/timed_delay' */
  /* End of Outputs for SubSystem: '<S19>/turnON_delay' */

  /* Logic: '<S19>/Logical Operator5' incorporates:
   *  Logic: '<S19>/Logical Operator13'
   */
  rtb_LogicalOperator5_k = ((!rtb_LogicalOperator3_c) || rtb_flg_out);

  /* Outputs for Atomic SubSystem: '<S19>/SR_latch' */
  swc_SCAP_SR_latch(rtb_LogicalOperator7_n, rtb_LogicalOperator5_k,
                    &rtb_LogicalOperator3_b,
                    &swc_SCAP_ARID_DEF.ARID_DEF_SR_latch);

  /* End of Outputs for SubSystem: '<S19>/SR_latch' */

  /* SignalConversion generated from: '<S19>/SR_latch' */
  scap_eadd_b_tqLmtPwrOffCmd_flg = rtb_LogicalOperator3_b;

  /* Logic: '<S19>/Logical Operator4' */
  rtb_LogicalOperator4_e = !scap_eadd_b_tqLmtPwrOffCmd_flg;

  /* Outputs for Atomic SubSystem: '<S19>/SwitchRampMOTMaxTrq1' */
  /* Constant: '<S19>/Constant29' incorporates:
   *  Constant: '<S19>/Constant26'
   *  Constant: '<S19>/Constant27'
   *  Constant: '<S19>/Constant30'
   */
  swc_SCAP_SwitchRampMOTMaxTrq1(((float32)TRQ_ZERO), rtb_LogicalOperator4_e,
    scap_eadc_tq_mot2LmtPwrOffCmd_Nm, scap_eadc_tq_PwrOffCmdIncGrad_Nmps,
    scap_eadc_tq_PwrOffCmdDecGrad_Nmps, &swc_SCAP_ARID_DEF.y_j, &rtb_RampOn,
    &swc_SCAP_ARID_DEF.ARID_DEF_SwitchRampMOTMaxTrq1);

  /* End of Outputs for SubSystem: '<S19>/SwitchRampMOTMaxTrq1' */

  /* Switch: '<S19>/Switch1' */
  if (scap_eadd_b_tqLmtPwrOffCmd_flg) {
    /* Switch: '<S19>/Switch1' incorporates:
     *  Constant: '<S19>/Constant1'
     */
    scap_eadd_tq_mot2LmPwrOffCmd_Nm = scap_eadc_tq_mot2LmtPwrOffCmd_Nm;
  } else {
    /* Switch: '<S19>/Switch1' */
    scap_eadd_tq_mot2LmPwrOffCmd_Nm = swc_SCAP_ARID_DEF.y_j;
  }

  /* End of Switch: '<S19>/Switch1' */

  /* Logic: '<S19>/Logical Operator3' incorporates:
   *  Constant: '<S19>/Constant32'
   *  Constant: '<S34>/Constant'
   *  RelationalOperator: '<S19>/Relational Operator2'
   *  RelationalOperator: '<S34>/Compare'
   */
  rtb_LogicalOperator3_o = ((scap_eadd_tq_mot2LmPwrOffCmd_Nm == ((float32)
    TRQ_ZERO)) || (eadd_b_mot2BstTqEnad != false));

  /* Outputs for Atomic SubSystem: '<S19>/SR_latch1' */
  swc_SCAP_SR_latch(scap_eadd_b_tqLmtPwrOffCmd_flg, rtb_LogicalOperator3_o,
                    &rtb_LogicalOperator3_f,
                    &swc_SCAP_ARID_DEF.ARID_DEF_SR_latch1);

  /* End of Outputs for SubSystem: '<S19>/SR_latch1' */

  /* Switch: '<S19>/Switch8' */
  if (rtb_LogicalOperator3_f) {
    /* Switch: '<S19>/Switch8' */
    scap_eadd_tq_mot2MaxLmtEnaOff_Nm = scap_eadd_tq_mot2LmPwrOffCmd_Nm;
  } else {
    /* Switch: '<S19>/Switch8' incorporates:
     *  Constant: '<S19>/Constant31'
     */
    scap_eadd_tq_mot2MaxLmtEnaOff_Nm = ((float32)TRQ_ZERO);
  }

  /* End of Switch: '<S19>/Switch8' */

  /* Logic: '<S7>/Logical Operator11' */
  rtb_LogicalOperator11 = !rtb_LogicalOperator11;

  /* Switch: '<S6>/Switch6' */
  if (rtb_LogicalOperator11) {
    /* Switch: '<S6>/Switch6' incorporates:
     *  Constant: '<S6>/Constant24'
     */
    rtb_Switch6 = eadc_tq_mot2MxTqDecGradESP_Nmps;
  } else {
    /* Switch: '<S6>/Switch6' incorporates:
     *  Constant: '<S6>/Constant23'
     */
    rtb_Switch6 = eadc_tq_mot2MxTqDecGrad_Nmps;
  }

  /* End of Switch: '<S6>/Switch6' */

  /* Outputs for Atomic SubSystem: '<S6>/SwitchRampMOTMaxPeakTrq' */
  /* Constant: '<S6>/Constant14' */
  swc_SCAP_switch_ramp(rtb_Switch3, eadd_b_mot2BstTqEnad,
                       scap_eadd_tq_mot2MaxLmtEnaOff_Nm,
                       eadc_tq_mot2MxTqIncGrad_Nmps, rtb_Switch6, &rtb_RampOn_p,
                       &swc_SCAP_ARID_DEF.ARID_DEF_SwitchRampMOTMaxPeakT);

  /* End of Outputs for SubSystem: '<S6>/SwitchRampMOTMaxPeakTrq' */

  /* If: '<S17>/If' incorporates:
   *  Constant: '<S17>/Constant'
   */
  if (eadd_tq_mot2MaxSTTq_Nm >= 0.0F) {
    /* Outputs for IfAction SubSystem: '<S17>/pos' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    swc_SCAP_pos(eadd_tq_mot2MaxSTTq_Nm, &rtb_Merge_m);

    /* End of Outputs for SubSystem: '<S17>/pos' */
  } else {
    /* Outputs for IfAction SubSystem: '<S17>/neg' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    swc_SCAP_neg(eadd_tq_mot2MaxSTTq_Nm, &rtb_Merge_m);

    /* End of Outputs for SubSystem: '<S17>/neg' */
  }

  /* End of If: '<S17>/If' */

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S52>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Logic: '<S8>/Logical Operator1'
   *  RelationalOperator: '<S52>/Compare'
   */
  if ((tmp == ((uint8)2U)) && scap_eadc_b_useFctCfgMot) {
    /* Switch: '<S8>/Switch1' incorporates:
     *  Lookup_n-D: '<S8>/1-D Lookup Table4'
     *  Merge: '<S54>/Merge'
     */
    rtb_t_delay_on = look1_iflf_binlcapw(rtb_Merge, (const float32 *)
      &scap_eadf_mot2MnTqLimMotTyp2_X_rpm[0], (const float32 *)
      &scap_eadf_mot2MnTqLimMotTyp2_Y_Nm[0], 12U);
  } else {
    /* Switch: '<S8>/Switch1' incorporates:
     *  Lookup_n-D: '<S8>/1-D Lookup Table3'
     *  Merge: '<S54>/Merge'
     */
    rtb_t_delay_on = look1_iflf_binlcapw(rtb_Merge, (const float32 *)
      &eadf_mot2MnTqLim_X_motSpd_rpm[0], (const float32 *)
      &eadf_mot2MnTqLim_Y_Nm[0], 10U);
  }

  /* End of Switch: '<S8>/Switch1' */

  /* MinMax: '<S8>/MinMax2' */
  eadd_tq_mot2MinSTTqLimd_Nm = fmaxf(rtb_t_delay_on,
    swc_SCAP_ARID_DEF.DataTypeConversion69);

  /* Switch: '<S6>/Switch5' incorporates:
   *  Constant: '<S6>/Constant19'
   *  Logic: '<S6>/Logical Operator3'
   *  RelationalOperator: '<S12>/FixPt Relational Operator'
   *  UnitDelay: '<S12>/Delay Input1'
   *
   * Block description for '<S12>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (eadc_b_useActTq2SwtOffMot2 && ((sint32)eadd_b_mot2BrkTqEnad < (sint32)
       swc_SCAP_ARID_DEF.DelayInput1_DSTATE_d)) {
    /* Switch: '<S6>/Switch5' incorporates:
     *  Constant: '<S6>/Constant22'
     *  MinMax: '<S6>/MinMax4'
     */
    rtb_Switch5 = fminf(swc_SCAP_ARID_DEF.DataTypeConversion49, 0.0F);
  } else {
    /* Switch: '<S6>/Switch5' */
    rtb_Switch5 = eadd_tq_mot2MinSTTqLimd_Nm;
  }

  /* End of Switch: '<S6>/Switch5' */

  /* Switch: '<S6>/Switch4' */
  if (rtb_LogicalOperator11) {
    /* Switch: '<S6>/Switch4' incorporates:
     *  Constant: '<S6>/Constant20'
     */
    rtb_Switch4 = eadc_tq_mot2MnTqIncGradESP_Nmps;
  } else {
    /* Switch: '<S6>/Switch4' incorporates:
     *  Constant: '<S6>/Constant18'
     */
    rtb_Switch4 = eadc_tq_mot2MnTqIncGrad_Nmps;
  }

  /* End of Switch: '<S6>/Switch4' */

  /* Outputs for Atomic SubSystem: '<S6>/SwitchRampMOTMinPeakTrq' */
  /* Constant: '<S6>/Constant17' incorporates:
   *  Constant: '<S6>/Constant21'
   */
  swc_SCA_SwitchRampMOTMinPeakTrq(rtb_Switch5, eadd_b_mot2BrkTqEnad, ((float32)
    TRQ_ZERO), rtb_Switch4, eadc_tq_mot2MnTqDecGrad_Nmps, &rtb_RampOn_a,
    &swc_SCAP_ARID_DEF.ARID_DEF_SwitchRampMOTMinPeakT);

  /* End of Outputs for SubSystem: '<S6>/SwitchRampMOTMinPeakTrq' */

  /* If: '<S18>/If' incorporates:
   *  Constant: '<S18>/Constant'
   */
  if (eadd_tq_mot2MinSTTq_Nm >= 0.0F) {
    /* Outputs for IfAction SubSystem: '<S18>/pos' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    swc_SCAP_pos(eadd_tq_mot2MinSTTq_Nm, &rtb_Merge_l);

    /* End of Outputs for SubSystem: '<S18>/pos' */
  } else {
    /* Outputs for IfAction SubSystem: '<S18>/neg' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    swc_SCAP_neg(eadd_tq_mot2MinSTTq_Nm, &rtb_Merge_l);

    /* End of Outputs for SubSystem: '<S18>/neg' */
  }

  /* End of If: '<S18>/If' */

  /* RelationalOperator: '<S6>/Relational Operator' incorporates:
   *  Constant: '<S6>/Constant9'
   *  MinMax: '<S6>/MinMax'
   */
  eadd_b_mot2TqOff = (fmaxf(rtb_Merge_m, rtb_Merge_l) <=
                      eadc_tq_mot2SwtOffThd_Nm);

  /* Switch: '<S6>/Switch' */
  if (rtb_LogicalOperator11) {
    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/Constant13'
     */
    rtb_Switch = eadc_tq_mot2MnTqIncGradESP_Nmps;
  } else {
    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/Constant10'
     */
    rtb_Switch = eadc_tq_mot2MnTqIncGrad_Nmps;
  }

  /* End of Switch: '<S6>/Switch' */

  /* MinMax: '<S8>/MinMax10' */
  eadd_tq_mot2MaxLTTqLimd_Nm = fminf(rtb_Switch3_n,
    swc_SCAP_ARID_DEF.DataTypeConversion66);

  /* Switch: '<S6>/Switch1' incorporates:
   *  Constant: '<S6>/Constant11'
   *  Logic: '<S6>/Logical Operator19'
   *  RelationalOperator: '<S9>/FixPt Relational Operator'
   *  UnitDelay: '<S9>/Delay Input1'
   *
   * Block description for '<S9>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (eadc_b_useActTq2SwtOffMot2 && ((sint32)eadd_b_mot2BstTqEnad < (sint32)
       swc_SCAP_ARID_DEF.DelayInput1_DSTATE_g)) {
    /* Switch: '<S6>/Switch1' incorporates:
     *  Constant: '<S6>/Constant7'
     *  MinMax: '<S6>/MinMax1'
     */
    rtb_Switch1 = fmaxf(swc_SCAP_ARID_DEF.DataTypeConversion49, 0.0F);
  } else {
    /* Switch: '<S6>/Switch1' */
    rtb_Switch1 = eadd_tq_mot2MaxLTTqLimd_Nm;
  }

  /* End of Switch: '<S6>/Switch1' */

  /* MinMax: '<S8>/MinMax11' */
  eadd_tq_mot2MinLTTqLimd_Nm = fmaxf(swc_SCAP_ARID_DEF.DataTypeConversion67,
    rtb_t_delay_on);

  /* Switch: '<S6>/Switch2' incorporates:
   *  Constant: '<S6>/Constant12'
   *  Logic: '<S6>/Logical Operator1'
   *  RelationalOperator: '<S10>/FixPt Relational Operator'
   *  UnitDelay: '<S10>/Delay Input1'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (eadc_b_useActTq2SwtOffMot2 && ((sint32)eadd_b_mot2BrkTqEnad < (sint32)
       swc_SCAP_ARID_DEF.DelayInput1_DSTATE_l)) {
    /* Switch: '<S6>/Switch2' incorporates:
     *  Constant: '<S6>/Constant8'
     *  MinMax: '<S6>/MinMax3'
     */
    rtb_Switch2 = fminf(swc_SCAP_ARID_DEF.DataTypeConversion49, 0.0F);
  } else {
    /* Switch: '<S6>/Switch2' */
    rtb_Switch2 = eadd_tq_mot2MinLTTqLimd_Nm;
  }

  /* End of Switch: '<S6>/Switch2' */

  /* Switch: '<S6>/Switch7' */
  if (rtb_LogicalOperator11) {
    /* Switch: '<S6>/Switch7' incorporates:
     *  Constant: '<S6>/Constant25'
     */
    rtb_Switch7 = eadc_tq_mot2MxTqDecGradESP_Nmps;
  } else {
    /* Switch: '<S6>/Switch7' incorporates:
     *  Constant: '<S6>/Constant6'
     */
    rtb_Switch7 = eadc_tq_mot2MxTqDecGrad_Nmps;
  }

  /* End of Switch: '<S6>/Switch7' */

  /* Outputs for Atomic SubSystem: '<S6>/SwitchRampMOTMaxTrq' */
  /* Constant: '<S6>/Constant4' */
  swc_SCAP_SwitchRampMOTMaxTrq(rtb_Switch1, eadd_b_mot2BstTqEnad,
    scap_eadd_tq_mot2MaxLmtEnaOff_Nm, eadc_tq_mot2MxTqIncGrad_Nmps, rtb_Switch7,
    &rtb_RampOn_h, &swc_SCAP_ARID_DEF.ARID_DEF_SwitchRampMOTMaxTrq);

  /* End of Outputs for SubSystem: '<S6>/SwitchRampMOTMaxTrq' */

  /* Outputs for Atomic SubSystem: '<S6>/SwitchRampMOTMinTrq' */
  /* Constant: '<S6>/Constant1' incorporates:
   *  Constant: '<S6>/Constant5'
   */
  swc_SCAP_SwitchRampMOTMinTrq(rtb_Switch2, eadd_b_mot2BrkTqEnad, ((float32)
    TRQ_ZERO), rtb_Switch, eadc_tq_mot2MnTqDecGrad_Nmps, &rtb_RampOn_g,
    &swc_SCAP_ARID_DEF.ARID_DEF_SwitchRampMOTMinTrq);

  /* End of Outputs for SubSystem: '<S6>/SwitchRampMOTMinTrq' */

  /* Logic: '<S7>/Logical Operator17' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Logic: '<S7>/Logical Operator14'
   *  Logic: '<S7>/Logical Operator15'
   *  Logic: '<S7>/Logical Operator16'
   */
  rtb_LogicalOperator17 = ((!swc_SCAP_ARID_DEF.DataTypeConversion138) ||
    (!eadc_b_disMot2BstTqDurgESP) || true);

  /* Update for UnitDelay: '<S9>/Delay Input1'
   *
   * Block description for '<S9>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_SCAP_ARID_DEF.DelayInput1_DSTATE_g = eadd_b_mot2BstTqEnad;

  /* Update for UnitDelay: '<S10>/Delay Input1'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_SCAP_ARID_DEF.DelayInput1_DSTATE_l = eadd_b_mot2BrkTqEnad;

  /* Update for UnitDelay: '<S11>/Delay Input1'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_SCAP_ARID_DEF.DelayInput1_DSTATE_e = eadd_b_mot2BstTqEnad;

  /* Update for UnitDelay: '<S12>/Delay Input1'
   *
   * Block description for '<S12>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_SCAP_ARID_DEF.DelayInput1_DSTATE_d = eadd_b_mot2BrkTqEnad;
}

/* System initialize for atomic system: '<S62>/switch_ramp' */
static void swc_SCAP_switch_ramp_d_Init(float32 *rty_y, boolean *rty_RampOn)
{
  /* SystemInitialize for Chart: '<S76>/Chart' */
  *rty_y = 0.0F;
  *rty_RampOn = false;
}

/* Output and update for atomic system: '<S62>/switch_ramp' */
static void swc_SCAP_switch_ramp_o(float32 rtu_u1, boolean rtu_sw, float32
  rtu_u2, float32 rtu_up, float32 rtu_lo, float32 *rty_y, boolean *rty_RampOn,
  ARID_DEF_switch_ramp_swc_SC_c_T *swc_SCAP__ARID_DEF_arg)
{
  float32 rtb_MinMax1_f;
  float32 rtb_MinMax_b;

  /* MinMax: '<S71>/MinMax' incorporates:
   *  Constant: '<S71>/Constant1'
   *  Constant: '<S71>/Constant2'
   *  Product: '<S71>/Product'
   */
  rtb_MinMax_b = fmaxf(rtu_up * 0.01F, 0.0F);

  /* MinMax: '<S71>/MinMax1' incorporates:
   *  Constant: '<S71>/Constant1'
   *  Constant: '<S71>/Constant2'
   *  Product: '<S71>/Product1'
   */
  rtb_MinMax1_f = fminf(0.0F, 0.01F * rtu_lo);

  /* Chart: '<S76>/Chart' */
  if (swc_SCAP__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li == 0U) {
    swc_SCAP__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li = 1U;
    swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2_b;
    *rty_RampOn = false;
    *rty_y = rtu_u2;
  } else {
    switch (swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib) {
     case swc_SCAP_IN_U1_me:
      *rty_RampOn = false;
      if (!rtu_sw) {
        if (rtu_u2 >= rtu_u1) {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2_a;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_INC_o;
          *rty_RampOn = true;
          *rty_y = fminf(fmaxf(fminf(rtu_u2 - *rty_y, rtb_MinMax_b) + *rty_y,
                               rtu_u1), rtu_u2);
        } else {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2_a;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_DEC_a;
          *rty_RampOn = true;
          *rty_y = fmaxf(fminf(fmaxf(rtu_u2 - *rty_y, rtb_MinMax1_f) + *rty_y,
                               rtu_u1), rtu_u2);
        }
      } else {
        *rty_y = rtu_u1;
      }
      break;

     case swc_SCAP_IN_U1_TO_U2_a:
      {
        if (rtu_sw) {
          if (rtu_u1 >= rtu_u2) {
            swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_l;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_SCAP_IN_U2_TO_U1_m;
            swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_INC_e;
            *rty_RampOn = true;
            *rty_y = fminf(fmaxf(fminf(rtu_u1 - *rty_y, rtb_MinMax_b) + *rty_y,
                                 rtu_u2), rtu_u1);
          } else {
            swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_l;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_SCAP_IN_U2_TO_U1_m;
            swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_DEC_m;
            *rty_RampOn = true;
            *rty_y = fmaxf(fminf(fmaxf(rtu_u1 - *rty_y, rtb_MinMax1_f) + *rty_y,
                                 rtu_u2), rtu_u1);
          }
        } else if (swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 ==
                   swc_SCAP_IN_U1_TO_U2_DEC_a) {
          float32 tmp;
          *rty_RampOn = true;
          tmp = rtu_u2 - *rty_y;
          if (tmp >= rtb_MinMax1_f) {
            swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_l;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2_b;
            *rty_RampOn = false;
            *rty_y = rtu_u2;
          } else {
            *rty_y = fmaxf(fminf(fmaxf(tmp, rtb_MinMax1_f) + *rty_y, rtu_u1),
                           rtu_u2);
          }
        } else {
          float32 tmp;

          /* case IN_U1_TO_U2_INC: */
          *rty_RampOn = true;
          tmp = rtu_u2 - *rty_y;
          if (tmp <= rtb_MinMax_b) {
            swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_l;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2_b;
            *rty_RampOn = false;
            *rty_y = rtu_u2;
          } else {
            *rty_y = fminf(fmaxf(fminf(tmp, rtb_MinMax_b) + *rty_y, rtu_u1),
                           rtu_u2);
          }
        }
      }
      break;

     case swc_SCAP_IN_U2_b:
      *rty_RampOn = false;
      if (rtu_sw) {
        if (rtu_u1 >= rtu_u2) {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1_m;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_INC_e;
          *rty_RampOn = true;
          *rty_y = fminf(fmaxf(fminf(rtu_u1 - *rty_y, rtb_MinMax_b) + *rty_y,
                               rtu_u2), rtu_u1);
        } else {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1_m;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_DEC_m;
          *rty_RampOn = true;
          *rty_y = fmaxf(fminf(fmaxf(rtu_u1 - *rty_y, rtb_MinMax1_f) + *rty_y,
                               rtu_u2), rtu_u1);
        }
      } else {
        *rty_y = rtu_u2;
      }
      break;

     default:
      {
        /* case IN_U2_TO_U1: */
        if (!rtu_sw) {
          if (rtu_u2 >= rtu_u1) {
            swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_l;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_SCAP_IN_U1_TO_U2_a;
            swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_INC_o;
            *rty_RampOn = true;
            *rty_y = fminf(fmaxf(fminf(rtu_u2 - *rty_y, rtb_MinMax_b) + *rty_y,
                                 rtu_u1), rtu_u2);
          } else {
            swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_l;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_SCAP_IN_U1_TO_U2_a;
            swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_DEC_a;
            *rty_RampOn = true;
            *rty_y = fmaxf(fminf(fmaxf(rtu_u2 - *rty_y, rtb_MinMax1_f) + *rty_y,
                                 rtu_u1), rtu_u2);
          }
        } else if (swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 ==
                   swc_SCAP_IN_U2_TO_U1_DEC_m) {
          float32 tmp;
          *rty_RampOn = true;
          tmp = rtu_u1 - *rty_y;
          if (tmp >= rtb_MinMax1_f) {
            swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_l;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_SCAP_IN_U1_me;
            *rty_RampOn = false;
            *rty_y = rtu_u1;
          } else {
            *rty_y = fmaxf(fminf(fmaxf(tmp, rtb_MinMax1_f) + *rty_y, rtu_u2),
                           rtu_u1);
          }
        } else {
          float32 tmp;

          /* case IN_U2_TO_U1_INC: */
          *rty_RampOn = true;
          tmp = rtu_u1 - *rty_y;
          if (tmp <= rtb_MinMax_b) {
            swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_l;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_SCAP_IN_U1_me;
            *rty_RampOn = false;
            *rty_y = rtu_u1;
          } else {
            *rty_y = fminf(fmaxf(fminf(tmp, rtb_MinMax_b) + *rty_y, rtu_u2),
                           rtu_u1);
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<S76>/Chart' */
}

/* System initialize for atomic system: '<S4>/ElectricalMotorsPowerLimitation' */
static void ElectricalMotorsPowerLimit_Init(void)
{
  /* local block i/o variables */
  boolean rtb_RampOn_hi;

  /* SystemInitialize for Atomic SubSystem: '<S62>/switch_ramp' */
  swc_SCAP_switch_ramp_d_Init(&swc_SCAP_ARID_DEF.y_b, &rtb_RampOn_hi);

  /* End of SystemInitialize for SubSystem: '<S62>/switch_ramp' */
}

/* Output and update for atomic system: '<S4>/ElectricalMotorsPowerLimitation' */
static void ElectricalMotorsPowerLimitation(void)
{
  /* local block i/o variables */
  float32 rtb_uDLookupTable1_p;
  float32 rtb_Product17;
  float32 rtb_Product;
  float32 rtb_Merge_p;
  boolean rtb_LogicalOperator17_i;
  boolean rtb_RampOn_hi;
  float32 ptld_tq_ead2MaxTqLimd_Nm_tmp;
  float32 rtb_MinMax2_p;
  float32 rtb_Switch1_f;
  uint8 tmp;
  boolean rtb_LogicalOperator1_j;

  /* Lookup_n-D: '<S62>/1-D Lookup Table1' */
  rtb_uDLookupTable1_p = look1_iflf_binlcapw(0.0F, (const float32 *)
    &ptlf_ead2MaxTqLmt_X_MotTemp_C[0], (const float32 *)
    &ptlf_ead2MaxTqLmtTemp_Y_factor[0], 1U);

  /* Logic: '<S62>/Logical Operator17' incorporates:
   *  Inport generated from: '<Root>/In Bus Element38'
   *  Inport generated from: '<Root>/In Bus Element39'
   */
  rtb_LogicalOperator17_i =
    (Rte_IRead_swc_SCAP_Step_vcsb_DIAG_digd_b_VehLvl31Flt_flg() ||
     Rte_IRead_swc_SCAP_Step_vcsb_DIAG_digd_b_VehLvl32Flt_flg());

  /* If: '<S63>/If' incorporates:
   *  Constant: '<S63>/Constant'
   */
  if (swc_SCAP_ARID_DEF.DataTypeConversion38 >= 0.0F) {
    /* Outputs for IfAction SubSystem: '<S63>/pos' incorporates:
     *  ActionPort: '<S79>/Action Port'
     */
    swc_SCAP_pos(swc_SCAP_ARID_DEF.DataTypeConversion38, &rtb_Product);

    /* End of Outputs for SubSystem: '<S63>/pos' */
  } else {
    /* Outputs for IfAction SubSystem: '<S63>/neg' incorporates:
     *  ActionPort: '<S78>/Action Port'
     */
    swc_SCAP_neg(swc_SCAP_ARID_DEF.DataTypeConversion38, &rtb_Product);

    /* End of Outputs for SubSystem: '<S63>/neg' */
  }

  /* End of If: '<S63>/If' */

  /* MinMax: '<S62>/MinMax2' incorporates:
   *  Constant: '<S62>/Constant2'
   *  Constant: '<S70>/Constant'
   *  Product: '<S70>/Product'
   */
  rtb_MinMax2_p = fmaxf(rtb_Product * ((float32)RPM_2_RADpS), 1.0F);

  /* Logic: '<S57>/Logical Operator1' incorporates:
   *  Constant: '<S57>/Constant1'
   *  Constant: '<S57>/Constant4'
   *  Constant: '<S57>/Constant5'
   *  Logic: '<S57>/Logical Operator'
   *  Logic: '<S57>/Logical Operator2'
   *  Logic: '<S57>/Logical Operator3'
   */
  rtb_LogicalOperator1_j = ((swc_SCAP_ARID_DEF.DataTypeConversion12 &&
    ptlc_b_enaMotSTPwrLimInSportMod) || (swc_SCAP_ARID_DEF.DataTypeConversion160
    && ptlc_b_enaMotSTPwrLimIn4WDMod) || (swc_SCAP_ARID_DEF.DataTypeConversion28
    && ptlc_b_enaMotSTPwrLimInEVMod));

  /* Switch: '<S62>/Switch2' */
  if (rtb_LogicalOperator1_j) {
    /* Merge: '<S67>/Merge' */
    rtb_Merge_p = eadd_tq_mot2MaxSTTq_Nm;
  } else {
    /* Merge: '<S67>/Merge' */
    rtb_Merge_p = eadd_tq_mot2MaxLTTq_Nm;
  }

  /* End of Switch: '<S62>/Switch2' */

  /* Lookup_n-D: '<S62>/1-D Lookup Table6' incorporates:
   *  Inport generated from: '<Root>/In Bus Element46'
   *  Lookup_n-D: '<S62>/1-D Lookup Table7'
   */
  ptld_tq_ead2MaxTqLimd_Nm_tmp =
    Rte_IRead_swc_SCAP_Step_vcib_VCIP_hvbd_q_hvbSOC_pct();

  /* Product: '<S62>/Product4' incorporates:
   *  Inport generated from: '<Root>/In Bus Element46'
   *  Lookup_n-D: '<S62>/1-D Lookup Table6'
   */
  ptld_tq_ead2MaxTqLimd_Nm = rtb_Merge_p * look1_iflf_binlcapw
    (ptld_tq_ead2MaxTqLimd_Nm_tmp, (const float32 *)
     &ptlf_ead2MaxTqCorrSOC_X_SOC_pct[0], (const float32 *)
     &ptlf_ead2MaxTqCorrSOC_Y_frac[0], 3U);

  /* Merge: '<S67>/Merge' incorporates:
   *  Constant: '<S69>/Constant3'
   *  Constant: '<S69>/Constant5'
   *  Lookup_n-D: '<S69>/2-D Lookup Table4'
   *  MinMax: '<S69>/MinMax1'
   *  Product: '<S62>/Product4'
   *  Product: '<S68>/Product'
   *  Product: '<S69>/Product'
   */
  rtb_Merge_p = look2_iflf_binlcapw(ptld_tq_ead2MaxTqLimd_Nm, rtb_Product, (
    const float32 *)&ptlf_ead2BstEff_X_MotTrq_Nm[0], (const float32 *)
    &ptla_ead2Eff_Y_MotSpd_rpm[0], (const float32 *)&ptlm_ead2BstEff_Z_frac[0],
    swc_SCAP_ConstP.pooled6, 21U);
  rtb_Merge_p *= ptlc_frac_motBstEffGain;
  rtb_Merge_p = fmaxf(rtb_Merge_p, 0.01F);

  /* MinMax: '<S69>/MinMax2' incorporates:
   *  Constant: '<S69>/Constant1'
   */
  ptld_frac_ead2MaxBstEff = fminf(1.0F, rtb_Merge_p);

  /* Switch: '<S62>/Switch3' */
  if (rtb_LogicalOperator1_j) {
    /* Merge: '<S67>/Merge' */
    rtb_Merge_p = eadd_tq_mot2MinSTTq_Nm;
  } else {
    /* Merge: '<S67>/Merge' */
    rtb_Merge_p = eadd_tq_mot2MinLTTq_Nm;
  }

  /* End of Switch: '<S62>/Switch3' */

  /* RelationalOperator: '<S64>/Compare' incorporates:
   *  Inport generated from: '<Root>/In Bus Element83'
   *  RelationalOperator: '<S65>/Compare'
   */
  tmp = Rte_IRead_swc_SCAP_Step_vcib_VCIP_adcd_st_pmsAdcCtrldSts();

  /* Switch: '<S62>/Switch1' incorporates:
   *  Constant: '<S62>/Constant8'
   *  Constant: '<S64>/Constant'
   *  Constant: '<S65>/Constant'
   *  Constant: '<S66>/Constant'
   *  Inport generated from: '<Root>/In Bus Element83'
   *  Inport generated from: '<Root>/In Bus Element85'
   *  Logic: '<S62>/Logical Operator28'
   *  Logic: '<S62>/Logical Operator29'
   *  RelationalOperator: '<S62>/Relational Operator5'
   *  RelationalOperator: '<S64>/Compare'
   *  RelationalOperator: '<S65>/Compare'
   */
  if (((tmp == ((uint8)0U)) || (tmp == ((uint8)1U))) &&
      swcscap_ptlc_b_adcOvrCtlPmt &&
      (Rte_IRead_swc_SCAP_Step_vcib_VCIP_brpd_e_brkPedalStatus() !=
       BrakePedalStatus_PRESSED)) {
    /* Switch: '<S62>/Switch1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion65'
     *  Lookup_n-D: '<S62>/1-D Lookup Table2'
     */
    rtb_Switch1_f = look1_iflf_binlcapw(swc_SCAP_ARID_DEF.DataTypeConversion65,
      (const float32 *)&swcscap_ptlf_ead2MinTqCorrAdc_X_VehSpd_kph[0], (const
      float32 *)&swcscap_ptlf_ead2MinTqCorrAdc_Y_frac[0], 4U);
  } else {
    /* Switch: '<S62>/Switch1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion65'
     *  Lookup_n-D: '<S62>/1-D Lookup Table4'
     */
    rtb_Switch1_f = look1_iflf_binlcapw(swc_SCAP_ARID_DEF.DataTypeConversion65,
      (const float32 *)&ptlf_ead2MinTqCorr_X_VehSpd_kph[0], (const float32 *)
      &ptlf_ead2MinTqCorr_Y_frac[0], 4U);
  }

  /* End of Switch: '<S62>/Switch1' */

  /* Product: '<S62>/Product5' incorporates:
   *  Lookup_n-D: '<S62>/1-D Lookup Table7'
   */
  ptld_tq_ead2MinTqLimd_Nm = rtb_Merge_p * look1_iflf_binlcapw
    (ptld_tq_ead2MaxTqLimd_Nm_tmp, (const float32 *)
     &ptlf_ead2MinTqCorrSOC_X_SOC_pct[0], (const float32 *)
     &ptlf_ead2MinTqCorrSOC_Y_frac[0], 3U) * rtb_Switch1_f;

  /* Product: '<S68>/Product' incorporates:
   *  Constant: '<S68>/Constant3'
   *  Lookup_n-D: '<S68>/2-D Lookup Table5'
   *  Product: '<S62>/Product5'
   */
  rtb_Product = look2_iflf_binlcapw(ptld_tq_ead2MinTqLimd_Nm, rtb_Product, (
    const float32 *)&ptlf_ead2BrkEff_X_MotTrq_Nm[0], (const float32 *)
    &ptla_ead2Eff_Y_MotSpd_rpm[0], (const float32 *)&ptlm_ead2BrkEff_Z_frac[0],
    swc_SCAP_ConstP.pooled6, 21U);
  rtb_Product *= ptlc_frac_motBrkEffGain;

  /* MinMax: '<S68>/MinMax2' incorporates:
   *  Constant: '<S68>/Constant1'
   */
  ptld_frac_ead2MaxBrkEff = fminf(1.0F, rtb_Product);

  /* Product: '<S62>/Product17' */
  rtb_Product17 = ptld_tq_ead2MinTqLimd_Nm * ptld_frac_ead2MaxBrkEff;

  /* Outputs for Atomic SubSystem: '<S62>/switch_ramp' */
  /* Constant: '<S62>/ptlc_fact_vehLvl2FltPwrDerate' incorporates:
   *  Constant: '<S62>/Constant14'
   *  Constant: '<S62>/Constant16'
   */
  swc_SCAP_switch_ramp_o(0.0F, rtb_LogicalOperator17_i, rtb_uDLookupTable1_p,
    ptlc_fact_vehLvl2DerateIncGrad, ptlc_fact_vehLvl2DerateDecGrad,
    &swc_SCAP_ARID_DEF.y_b, &rtb_RampOn_hi,
    &swc_SCAP_ARID_DEF.ARID_DEF_switch_ramp_m);

  /* End of Outputs for SubSystem: '<S62>/switch_ramp' */

  /* If: '<S67>/If' incorporates:
   *  Constant: '<S67>/Constant'
   */
  if (rtb_Product17 >= 0.0F) {
    /* Outputs for IfAction SubSystem: '<S67>/pos' incorporates:
     *  ActionPort: '<S75>/Action Port'
     */
    swc_SCAP_pos(rtb_Product17, &rtb_Merge_p);

    /* End of Outputs for SubSystem: '<S67>/pos' */
  } else {
    /* Outputs for IfAction SubSystem: '<S67>/neg' incorporates:
     *  ActionPort: '<S74>/Action Port'
     */
    swc_SCAP_neg(rtb_Product17, &rtb_Merge_p);

    /* End of Outputs for SubSystem: '<S67>/neg' */
  }

  /* End of If: '<S67>/If' */

  /* Product: '<S72>/Product' incorporates:
   *  Constant: '<S72>/Constant'
   *  Product: '<S62>/Product16'
   *  Product: '<S62>/Product6'
   */
  ptld_pwr_ead2DischAvail_kW = ptld_tq_ead2MaxTqLimd_Nm /
    ptld_frac_ead2MaxBstEff * swc_SCAP_ARID_DEF.y_b * rtb_MinMax2_p * ((float32)
    XX_2_kXX);

  /* Product: '<S73>/Product' incorporates:
   *  Constant: '<S73>/Constant'
   *  Product: '<S62>/Product7'
   */
  ptld_pwr_ead2ChrgAvail_kW = rtb_MinMax2_p * rtb_Merge_p * ((float32)XX_2_kXX);
}

/* Output and update for atomic system: '<S4>/PowerLimitsArbitration' */
static void swc_SCAP_PowerLimitsArbitration(void)
{
  float32 tmp;

  /* Switch: '<S107>/Switch2' incorporates:
   *  Constant: '<S105>/Constant3'
   *  RelationalOperator: '<S107>/LowerRelop1'
   *  RelationalOperator: '<S107>/UpperRelop'
   *  Switch: '<S107>/Switch'
   */
  if (ptld_pwr_hvbDischAvail_kW > ptld_pwr_ead2DischAvail_kW) {
    /* Switch: '<S107>/Switch2' */
    ptld_pwr_ead2PwrMax_kW = ptld_pwr_ead2DischAvail_kW;
  } else if (ptld_pwr_hvbDischAvail_kW < ((float32)PWR_ZERO)) {
    /* Switch: '<S107>/Switch' incorporates:
     *  Constant: '<S105>/Constant3'
     *  Switch: '<S107>/Switch2'
     */
    ptld_pwr_ead2PwrMax_kW = ((float32)PWR_ZERO);
  } else {
    /* Switch: '<S107>/Switch2' incorporates:
     *  Switch: '<S107>/Switch'
     */
    ptld_pwr_ead2PwrMax_kW = ptld_pwr_hvbDischAvail_kW;
  }

  /* End of Switch: '<S107>/Switch2' */

  /* Switch: '<S106>/Switch2' incorporates:
   *  Constant: '<S104>/Constant3'
   *  RelationalOperator: '<S106>/LowerRelop1'
   *  RelationalOperator: '<S106>/UpperRelop'
   *  Switch: '<S106>/Switch'
   */
  if (ptld_pwr_hvbChrgAvail_kW > ptld_pwr_ead2ChrgAvail_kW) {
    tmp = ptld_pwr_ead2ChrgAvail_kW;
  } else if (ptld_pwr_hvbChrgAvail_kW < ((float32)PWR_ZERO)) {
    /* Switch: '<S106>/Switch' incorporates:
     *  Constant: '<S104>/Constant3'
     */
    tmp = ((float32)PWR_ZERO);
  } else {
    tmp = ptld_pwr_hvbChrgAvail_kW;
  }

  /* Gain: '<S59>/Gain4' incorporates:
   *  Switch: '<S106>/Switch2'
   */
  ptld_pwr_ead2PwrMin_kW = (-1.0F) * tmp;
}

/* Output and update for atomic system: '<S4>/PowerToTorqueLimitsConversion' */
static void s_PowerToTorqueLimitsConversion(void)
{
  /* local block i/o variables */
  float32 rtb_Product_p;
  float32 rtb_MinMax2_n;

  /* If: '<S108>/If' incorporates:
   *  Constant: '<S108>/Constant'
   */
  if (swc_SCAP_ARID_DEF.DataTypeConversion38 >= 0.0F) {
    /* Outputs for IfAction SubSystem: '<S108>/pos' incorporates:
     *  ActionPort: '<S115>/Action Port'
     */
    swc_SCAP_pos(swc_SCAP_ARID_DEF.DataTypeConversion38, &rtb_Product_p);

    /* End of Outputs for SubSystem: '<S108>/pos' */
  } else {
    /* Outputs for IfAction SubSystem: '<S108>/neg' incorporates:
     *  ActionPort: '<S114>/Action Port'
     */
    swc_SCAP_neg(swc_SCAP_ARID_DEF.DataTypeConversion38, &rtb_Product_p);

    /* End of Outputs for SubSystem: '<S108>/neg' */
  }

  /* End of If: '<S108>/If' */

  /* MinMax: '<S60>/MinMax2' incorporates:
   *  Constant: '<S113>/Constant'
   *  Constant: '<S60>/Constant2'
   *  Product: '<S113>/Product'
   */
  rtb_MinMax2_n = fmaxf(rtb_Product_p * ((float32)RPM_2_RADpS), 1.0F);

  /* Product: '<S60>/Product9' incorporates:
   *  Constant: '<S112>/Constant'
   *  Product: '<S112>/Product'
   */
  ptld_tq_ead2TqMinRaw_Nm = 1.0F / rtb_MinMax2_n * (ptld_pwr_ead2PwrMin_kW *
    ((float32)kXX_2_XX));

  /* MinMax: '<S109>/MinMax2' incorporates:
   *  Constant: '<S109>/Constant1'
   *  Constant: '<S109>/Constant3'
   *  Constant: '<S109>/Constant5'
   *  Lookup_n-D: '<S109>/2-D Lookup Table5'
   *  MinMax: '<S109>/MinMax4'
   *  Product: '<S109>/Product'
   *  Product: '<S110>/Product'
   *  Product: '<S60>/Product9'
   */
  ptld_frac_ead2MaxBrkEffFinal = fminf(1.0F, fmaxf(look2_iflf_binlcapw
    (ptld_tq_ead2TqMinRaw_Nm, rtb_Product_p, (const float32 *)
     &ptlf_ead2BrkEff_X_MotTrq_Nm[0], (const float32 *)
     &ptla_ead2Eff_Y_MotSpd_rpm[0], (const float32 *)&ptlm_ead2BrkEff_Z_frac[0],
     swc_SCAP_ConstP.pooled6, 21U) * ptlc_frac_motBrkEffGain, 0.01F));

  /* Product: '<S60>/Product10' */
  ptld_tq_ead2TqMin_Nm = ptld_tq_ead2TqMinRaw_Nm / ptld_frac_ead2MaxBrkEffFinal;

  /* Product: '<S60>/Product7' incorporates:
   *  Constant: '<S111>/Constant'
   *  Product: '<S111>/Product'
   */
  ptld_tq_ead2TqMaxRaw_Nm = ptld_pwr_ead2PwrMax_kW * ((float32)kXX_2_XX) /
    rtb_MinMax2_n;

  /* Product: '<S110>/Product' incorporates:
   *  Constant: '<S110>/Constant5'
   *  Lookup_n-D: '<S110>/2-D Lookup Table4'
   *  Product: '<S60>/Product7'
   */
  rtb_Product_p = look2_iflf_binlcapw(ptld_tq_ead2TqMaxRaw_Nm, rtb_Product_p, (
    const float32 *)&ptlf_ead2BstEff_X_MotTrq_Nm[0], (const float32 *)
    &ptla_ead2Eff_Y_MotSpd_rpm[0], (const float32 *)&ptlm_ead2BstEff_Z_frac[0],
    swc_SCAP_ConstP.pooled6, 21U);
  rtb_Product_p *= ptlc_frac_motBstEffGain;

  /* MinMax: '<S110>/MinMax2' incorporates:
   *  Constant: '<S110>/Constant1'
   */
  ptld_frac_ead2MaxBstEffFinal = fminf(1.0F, rtb_Product_p);

  /* Product: '<S60>/Product5' */
  ptld_tq_ead2TqMax_Nm = ptld_tq_ead2TqMaxRaw_Nm * ptld_frac_ead2MaxBstEffFinal;
}

/* System initialize for function-call system: '<S1>/PTL_PowerLimitation' */
static void swc_SC_PTL_PowerLimitation_Init(void)
{
  /* local block i/o variables */
  boolean rtb_RampOn_pr;

  /* SystemInitialize for Atomic SubSystem: '<S4>/ElectricalMotorsPowerLimitation' */
  ElectricalMotorsPowerLimit_Init();

  /* End of SystemInitialize for SubSystem: '<S4>/ElectricalMotorsPowerLimitation' */

  /* SystemInitialize for Atomic SubSystem: '<S4>/HVBatteryPowerLimitation' */
  /* SystemInitialize for Atomic SubSystem: '<S58>/switch_ramp' */
  swc_S_SwitchRampMOTMaxTrq1_Init(&swc_SCAP_ARID_DEF.y_o2, &rtb_RampOn_pr);

  /* End of SystemInitialize for SubSystem: '<S58>/switch_ramp' */
  /* End of SystemInitialize for SubSystem: '<S4>/HVBatteryPowerLimitation' */
}

/* Output and update for function-call system: '<S1>/PTL_PowerLimitation' */
static void swc_SCAP_PTL_PowerLimitation(void)
{
  /* local block i/o variables */
  float32 rtb_Merge_i;
  float32 rtb_Merge_h;
  boolean rtb_LogicalOperator17_l;
  boolean rtb_RelationalOperator6;
  boolean rtb_RampOn_pr;
  float32 rtb_Product3;
  float32 rtb_Product3_n;
  float32 rtb_Switch8;
  float32 rtb_t_delay_on_pj_tmp;
  float32 tmp;
  boolean rtb_LogicalOperator1_d;
  boolean rtb_RelationalOperator11;

  /* Outputs for Atomic SubSystem: '<S4>/ElectricalMotorsPowerLimitation' */
  ElectricalMotorsPowerLimitation();

  /* End of Outputs for SubSystem: '<S4>/ElectricalMotorsPowerLimitation' */

  /* Outputs for Atomic SubSystem: '<S4>/HVBatteryPowerLimitation' */
  /* If: '<S82>/If' incorporates:
   *  Constant: '<S82>/Constant'
   *  Inport generated from: '<Root>/In Bus Element92'
   */
  if (Rte_IRead_swc_SCAP_Step_vcib_VCIP_vild_i_hvbCurr_A() >= 0.0F) {
    /* Outputs for IfAction SubSystem: '<S82>/pos' incorporates:
     *  ActionPort: '<S93>/Action Port'
     */
    swc_SCAP_pos(Rte_IRead_swc_SCAP_Step_vcib_VCIP_vild_i_hvbCurr_A(),
                 &rtb_Merge_i);

    /* End of Outputs for SubSystem: '<S82>/pos' */
  } else {
    /* Outputs for IfAction SubSystem: '<S82>/neg' incorporates:
     *  ActionPort: '<S92>/Action Port'
     */
    swc_SCAP_neg(Rte_IRead_swc_SCAP_Step_vcib_VCIP_vild_i_hvbCurr_A(),
                 &rtb_Merge_i);

    /* End of Outputs for SubSystem: '<S82>/neg' */
  }

  /* End of If: '<S82>/If' */

  /* Logic: '<S58>/Logical Operator1' incorporates:
   *  Constant: '<S58>/Constant2'
   *  Constant: '<S58>/Constant4'
   *  Constant: '<S58>/Constant5'
   *  Logic: '<S58>/Logical Operator'
   *  Logic: '<S58>/Logical Operator2'
   *  Logic: '<S58>/Logical Operator3'
   */
  rtb_LogicalOperator1_d = ((swc_SCAP_ARID_DEF.DataTypeConversion12 &&
    ptlc_b_enaHVBSTPwrLimInSportMod) || (swc_SCAP_ARID_DEF.DataTypeConversion160
    && ptlc_b_enaHVBSTPwrLimIn4WDMod) || (swc_SCAP_ARID_DEF.DataTypeConversion28
    && ptlc_b_enaHVBSTPwrLimInEVMod));

  /* Switch: '<S58>/Switch1' */
  if (rtb_LogicalOperator1_d) {
    /* Switch: '<S58>/Switch8' */
    rtb_Switch8 = swc_SCAP_ARID_DEF.DataTypeConversion46;
  } else {
    /* Switch: '<S58>/Switch8' */
    rtb_Switch8 = swc_SCAP_ARID_DEF.DataTypeConversion31;
  }

  /* End of Switch: '<S58>/Switch1' */

  /* MinMax: '<S58>/MinMax4' incorporates:
   *  Constant: '<S58>/Constant69'
   *  Inport generated from: '<Root>/In Bus Element20'
   *  MinMax: '<S58>/MinMax3'
   */
  rtb_Product3_n = fmaxf(Rte_IRead_swc_SCAP_Step_vcib_VCIP_vild_u_hvbVolt_V(),
    1.0F);

  /* Product: '<S58>/Product10' incorporates:
   *  Constant: '<S58>/Constant68'
   *  MinMax: '<S58>/MinMax4'
   */
  swcscap_pltd_i_hvbMaxChgCurr_A = rtb_Switch8 * 1000.0F / rtb_Product3_n;

  /* If: '<S84>/If' incorporates:
   *  Constant: '<S84>/Constant'
   */
  if (swcscap_pltd_i_hvbMaxChgCurr_A >= 0.0F) {
    /* Outputs for IfAction SubSystem: '<S84>/pos' incorporates:
     *  ActionPort: '<S97>/Action Port'
     */
    swc_SCAP_pos(swcscap_pltd_i_hvbMaxChgCurr_A, &rtb_Merge_h);

    /* End of Outputs for SubSystem: '<S84>/pos' */
  } else {
    /* Outputs for IfAction SubSystem: '<S84>/neg' incorporates:
     *  ActionPort: '<S96>/Action Port'
     */
    swc_SCAP_neg(swcscap_pltd_i_hvbMaxChgCurr_A, &rtb_Merge_h);

    /* End of Outputs for SubSystem: '<S84>/neg' */
  }

  /* End of If: '<S84>/If' */

  /* RelationalOperator: '<S58>/Relational Operator11' incorporates:
   *  Constant: '<S58>/Constant62'
   *  Product: '<S58>/Product9'
   */
  rtb_RelationalOperator11 = (rtb_Merge_i > ptlc_f_bmsMaxChgCurrPreFidLvl2Factor
    * rtb_Merge_h);

  /* Outputs for Atomic SubSystem: '<S58>/turnON_delay10' */
  /* Saturate: '<S87>/Saturation' incorporates:
   *  Constant: '<S58>/Constant63'
   */
  if (ptlc_s_preFidDlyTm_s > 1.6777216E+7F) {
    /* Outputs for Atomic SubSystem: '<S58>/turnON_delay1' */
    /* Outputs for Atomic SubSystem: '<S58>/turnON_delay8' */
    /* Outputs for Atomic SubSystem: '<S58>/turnON_delay9' */
    /* Saturate: '<S89>/Saturation' incorporates:
     *  Saturate: '<S86>/Saturation'
     *  Saturate: '<S88>/Saturation'
     */
    rtb_t_delay_on_pj_tmp = 1.6777216E+7F;

    /* End of Outputs for SubSystem: '<S58>/turnON_delay9' */
    /* End of Outputs for SubSystem: '<S58>/turnON_delay8' */
    /* End of Outputs for SubSystem: '<S58>/turnON_delay1' */
  } else if (ptlc_s_preFidDlyTm_s < 0.0F) {
    /* Outputs for Atomic SubSystem: '<S58>/turnON_delay1' */
    /* Outputs for Atomic SubSystem: '<S58>/turnON_delay8' */
    /* Outputs for Atomic SubSystem: '<S58>/turnON_delay9' */
    /* Saturate: '<S89>/Saturation' incorporates:
     *  Saturate: '<S86>/Saturation'
     *  Saturate: '<S88>/Saturation'
     */
    rtb_t_delay_on_pj_tmp = 0.0F;

    /* End of Outputs for SubSystem: '<S58>/turnON_delay9' */
    /* End of Outputs for SubSystem: '<S58>/turnON_delay8' */
    /* End of Outputs for SubSystem: '<S58>/turnON_delay1' */
  } else {
    /* Outputs for Atomic SubSystem: '<S58>/turnON_delay1' */
    /* Outputs for Atomic SubSystem: '<S58>/turnON_delay8' */
    /* Outputs for Atomic SubSystem: '<S58>/turnON_delay9' */
    /* Saturate: '<S89>/Saturation' incorporates:
     *  Saturate: '<S86>/Saturation'
     *  Saturate: '<S88>/Saturation'
     */
    rtb_t_delay_on_pj_tmp = ptlc_s_preFidDlyTm_s;

    /* End of Outputs for SubSystem: '<S58>/turnON_delay9' */
    /* End of Outputs for SubSystem: '<S58>/turnON_delay8' */
    /* End of Outputs for SubSystem: '<S58>/turnON_delay1' */
  }

  /* Chart: '<S87>/timed_delay' incorporates:
   *  Constant: '<S58>/Constant64'
   *  DataTypeConversion: '<S87>/Data Type Conversion'
   *  Saturate: '<S87>/Saturation'
   */
  if (swc_SCAP_ARID_DEF.is_active_c14_Ricardo_SW_dev__i == 0U) {
    swc_SCAP_ARID_DEF.is_active_c14_Ricardo_SW_dev__i = 1U;
    if (rtb_RelationalOperator11) {
      swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_i = swc_SCAP_IN_ON_p;
      swcscap_pltd_b_PwrPreLimitLvl2ChgCurr = true;
    } else {
      swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_i = swc_SCAP_IN_OFF_p;
      swcscap_pltd_b_PwrPreLimitLvl2ChgCurr = false;
    }
  } else {
    switch (swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_i) {
     case swc_SCAP_IN_OFF_p:
      if (rtb_RelationalOperator11) {
        if (rtb_t_delay_on_pj_tmp == 0.0F) {
          swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_i = swc_SCAP_IN_ON_p;
          swcscap_pltd_b_PwrPreLimitLvl2ChgCurr = true;
        } else {
          swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_i = swc_SCAP_IN_ON_WAIT_k;
          swc_SCAP_ARID_DEF.t_wait_bk = ((float32)PTL_TASK_INTERVAL_S);
          swcscap_pltd_b_PwrPreLimitLvl2ChgCurr = false;
        }
      } else {
        swcscap_pltd_b_PwrPreLimitLvl2ChgCurr = false;
      }
      break;

     case swc_SCAP_IN_ON_p:
      if (!rtb_RelationalOperator11) {
        swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_i = swc_SCAP_IN_OFF_p;
        swcscap_pltd_b_PwrPreLimitLvl2ChgCurr = false;
      } else {
        swcscap_pltd_b_PwrPreLimitLvl2ChgCurr = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtb_RelationalOperator11) {
        swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_i = swc_SCAP_IN_OFF_p;
        swcscap_pltd_b_PwrPreLimitLvl2ChgCurr = false;
      } else if (swc_SCAP_ARID_DEF.t_wait_bk > rtb_t_delay_on_pj_tmp - ((float32)
                  PTL_TASK_INTERVAL_S)) {
        swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_i = swc_SCAP_IN_ON_p;
        swcscap_pltd_b_PwrPreLimitLvl2ChgCurr = true;
      } else {
        swc_SCAP_ARID_DEF.t_wait_bk += ((float32)PTL_TASK_INTERVAL_S);
        swcscap_pltd_b_PwrPreLimitLvl2ChgCurr = false;
      }
      break;
    }
  }

  /* End of Chart: '<S87>/timed_delay' */
  /* End of Outputs for SubSystem: '<S58>/turnON_delay10' */

  /* Switch: '<S58>/Switch7' incorporates:
   *  Constant: '<S58>/Constant12'
   *  Constant: '<S58>/Constant22'
   *  Inport generated from: '<Root>/In Bus Element28'
   */
  if (swcscap_ptlc_b_useHvAttpwr) {
    tmp = Rte_IRead_swc_SCAP_Step_vcsb_EGYM_accd_pwr_hvAttpwr_kW();
  } else {
    tmp = 0.0F;
  }

  /* Product: '<S58>/Product5' incorporates:
   *  Constant: '<S58>/Constant1'
   *  Constant: '<S58>/Constant21'
   *  Constant: '<S58>/Constant23'
   *  MinMax: '<S58>/MinMax1'
   *  Sum: '<S58>/Sum3'
   *  Switch: '<S58>/Switch7'
   */
  swcscap_ptld_pwr_hvbChrgAvailRaw_kW = (tmp + rtb_Switch8) * 1.0F / fmaxf
    (ptlc_frac_hvbChEff, 0.01F);

  /* Product: '<S80>/Product3' incorporates:
   *  Constant: '<S80>/Constant54'
   */
  rtb_Product3 = scap_ptlc_pct_bmsCurrChgLmtPctPreFid *
    swcscap_ptld_pwr_hvbChrgAvailRaw_kW;

  /* Switch: '<S80>/Switch10' incorporates:
   *  RelationalOperator: '<S90>/FixPt Relational Operator'
   *  UnitDelay: '<S90>/Delay Input1'
   *
   * Block description for '<S90>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((sint32)swcscap_pltd_b_PwrPreLimitLvl2ChgCurr > (sint32)
      swc_SCAP_ARID_DEF.DelayInput1_DSTATE) {
    /* Switch: '<S80>/Switch10' */
    rtb_Switch8 = rtb_Product3;
  } else {
    /* Switch: '<S80>/Switch10' incorporates:
     *  UnitDelay: '<S80>/Unit Delay1'
     */
    rtb_Switch8 = swc_SCAP_ARID_DEF.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S80>/Switch10' */

  /* RelationalOperator: '<S58>/Relational Operator3' incorporates:
   *  Constant: '<S58>/Constant59'
   *  Product: '<S58>/Product8'
   */
  rtb_RelationalOperator11 = (rtb_Merge_i > ptlc_f_bmsMaxChgCurrPreFidLvl1Factor
    * rtb_Merge_h);

  /* Outputs for Atomic SubSystem: '<S58>/turnON_delay9' */
  /* Chart: '<S89>/timed_delay' incorporates:
   *  Constant: '<S58>/Constant61'
   *  DataTypeConversion: '<S89>/Data Type Conversion'
   */
  if (swc_SCAP_ARID_DEF.is_active_c14_Ricardo_SW_dev_li == 0U) {
    swc_SCAP_ARID_DEF.is_active_c14_Ricardo_SW_dev_li = 1U;
    if (rtb_RelationalOperator11) {
      swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_SCAP_IN_ON_p;
      swcscap_pltd_b_PwrPreLimitLvl1ChgCurr = true;
    } else {
      swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_SCAP_IN_OFF_p;
      swcscap_pltd_b_PwrPreLimitLvl1ChgCurr = false;
    }
  } else {
    switch (swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib) {
     case swc_SCAP_IN_OFF_p:
      if (rtb_RelationalOperator11) {
        if (rtb_t_delay_on_pj_tmp == 0.0F) {
          swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_SCAP_IN_ON_p;
          swcscap_pltd_b_PwrPreLimitLvl1ChgCurr = true;
        } else {
          swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_SCAP_IN_ON_WAIT_k;
          swc_SCAP_ARID_DEF.t_wait = ((float32)PTL_TASK_INTERVAL_S);
          swcscap_pltd_b_PwrPreLimitLvl1ChgCurr = false;
        }
      } else {
        swcscap_pltd_b_PwrPreLimitLvl1ChgCurr = false;
      }
      break;

     case swc_SCAP_IN_ON_p:
      if (!rtb_RelationalOperator11) {
        swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_SCAP_IN_OFF_p;
        swcscap_pltd_b_PwrPreLimitLvl1ChgCurr = false;
      } else {
        swcscap_pltd_b_PwrPreLimitLvl1ChgCurr = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtb_RelationalOperator11) {
        swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_SCAP_IN_OFF_p;
        swcscap_pltd_b_PwrPreLimitLvl1ChgCurr = false;
      } else if (swc_SCAP_ARID_DEF.t_wait > rtb_t_delay_on_pj_tmp - ((float32)
                  PTL_TASK_INTERVAL_S)) {
        swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_SCAP_IN_ON_p;
        swcscap_pltd_b_PwrPreLimitLvl1ChgCurr = true;
      } else {
        swc_SCAP_ARID_DEF.t_wait += ((float32)PTL_TASK_INTERVAL_S);
        swcscap_pltd_b_PwrPreLimitLvl1ChgCurr = false;
      }
      break;
    }
  }

  /* End of Chart: '<S89>/timed_delay' */
  /* End of Outputs for SubSystem: '<S58>/turnON_delay9' */

  /* Switch: '<S80>/Switch9' incorporates:
   *  MinMax: '<S80>/MinMax'
   *  Switch: '<S80>/Switch11'
   */
  if (swcscap_pltd_b_PwrPreLimitLvl2ChgCurr) {
    ptld_pwr_hvbChrgAvail_kW = fminf(swcscap_ptld_pwr_hvbChrgAvailRaw_kW,
      rtb_Switch8);
  } else if (swcscap_pltd_b_PwrPreLimitLvl1ChgCurr) {
    /* Switch: '<S80>/Switch11' */
    ptld_pwr_hvbChrgAvail_kW = rtb_Product3;
  } else {
    ptld_pwr_hvbChrgAvail_kW = swcscap_ptld_pwr_hvbChrgAvailRaw_kW;
  }

  /* End of Switch: '<S80>/Switch9' */

  /* Switch: '<S58>/Switch' */
  if (rtb_LogicalOperator1_d) {
    /* UnitDelay: '<S81>/Unit Delay1' */
    rtb_Product3 = swc_SCAP_ARID_DEF.DataTypeConversion30;
  } else {
    /* UnitDelay: '<S81>/Unit Delay1' */
    rtb_Product3 = swc_SCAP_ARID_DEF.DataTypeConversion34;
  }

  /* End of Switch: '<S58>/Switch' */

  /* Product: '<S58>/Product3' incorporates:
   *  Constant: '<S58>/Constant54'
   */
  swcscap_pltd_i_hvbMaxDischCurr_A = rtb_Product3 * 1000.0F / rtb_Product3_n;

  /* If: '<S83>/If' incorporates:
   *  Constant: '<S83>/Constant'
   */
  if (swcscap_pltd_i_hvbMaxDischCurr_A >= 0.0F) {
    /* Outputs for IfAction SubSystem: '<S83>/pos' incorporates:
     *  ActionPort: '<S95>/Action Port'
     */
    swc_SCAP_pos(swcscap_pltd_i_hvbMaxDischCurr_A, &rtb_Merge_h);

    /* End of Outputs for SubSystem: '<S83>/pos' */
  } else {
    /* Outputs for IfAction SubSystem: '<S83>/neg' incorporates:
     *  ActionPort: '<S94>/Action Port'
     */
    swc_SCAP_neg(swcscap_pltd_i_hvbMaxDischCurr_A, &rtb_Merge_h);

    /* End of Outputs for SubSystem: '<S83>/neg' */
  }

  /* End of If: '<S83>/If' */

  /* RelationalOperator: '<S58>/Relational Operator2' incorporates:
   *  Constant: '<S58>/Constant31'
   *  Product: '<S58>/Product7'
   */
  rtb_LogicalOperator1_d = (rtb_Merge_i > ptlc_f_bmsMaxDischCurrPreFidLvl2Factor
    * rtb_Merge_h);

  /* Outputs for Atomic SubSystem: '<S58>/turnON_delay8' */
  /* Chart: '<S88>/timed_delay' incorporates:
   *  Constant: '<S58>/Constant33'
   *  DataTypeConversion: '<S88>/Data Type Conversion'
   */
  if (swc_SCAP_ARID_DEF.is_active_c14_Ricardo_SW_dev__n == 0U) {
    swc_SCAP_ARID_DEF.is_active_c14_Ricardo_SW_dev__n = 1U;
    if (rtb_LogicalOperator1_d) {
      swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h = swc_SCAP_IN_ON_p;
      swcscap_pltd_b_PwrPreLimitLvl2DischCurr = true;
    } else {
      swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h = swc_SCAP_IN_OFF_p;
      swcscap_pltd_b_PwrPreLimitLvl2DischCurr = false;
    }
  } else {
    switch (swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h) {
     case swc_SCAP_IN_OFF_p:
      if (rtb_LogicalOperator1_d) {
        if (rtb_t_delay_on_pj_tmp == 0.0F) {
          swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h = swc_SCAP_IN_ON_p;
          swcscap_pltd_b_PwrPreLimitLvl2DischCurr = true;
        } else {
          swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h = swc_SCAP_IN_ON_WAIT_k;
          swc_SCAP_ARID_DEF.t_wait_b = ((float32)PTL_TASK_INTERVAL_S);
          swcscap_pltd_b_PwrPreLimitLvl2DischCurr = false;
        }
      } else {
        swcscap_pltd_b_PwrPreLimitLvl2DischCurr = false;
      }
      break;

     case swc_SCAP_IN_ON_p:
      if (!rtb_LogicalOperator1_d) {
        swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h = swc_SCAP_IN_OFF_p;
        swcscap_pltd_b_PwrPreLimitLvl2DischCurr = false;
      } else {
        swcscap_pltd_b_PwrPreLimitLvl2DischCurr = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtb_LogicalOperator1_d) {
        swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h = swc_SCAP_IN_OFF_p;
        swcscap_pltd_b_PwrPreLimitLvl2DischCurr = false;
      } else if (swc_SCAP_ARID_DEF.t_wait_b > rtb_t_delay_on_pj_tmp - ((float32)
                  PTL_TASK_INTERVAL_S)) {
        swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h = swc_SCAP_IN_ON_p;
        swcscap_pltd_b_PwrPreLimitLvl2DischCurr = true;
      } else {
        swc_SCAP_ARID_DEF.t_wait_b += ((float32)PTL_TASK_INTERVAL_S);
        swcscap_pltd_b_PwrPreLimitLvl2DischCurr = false;
      }
      break;
    }
  }

  /* End of Chart: '<S88>/timed_delay' */
  /* End of Outputs for SubSystem: '<S58>/turnON_delay8' */

  /* Logic: '<S58>/Logical Operator17' incorporates:
   *  Inport generated from: '<Root>/In Bus Element38'
   *  Inport generated from: '<Root>/In Bus Element39'
   */
  rtb_LogicalOperator17_l =
    (Rte_IRead_swc_SCAP_Step_vcsb_DIAG_digd_b_VehLvl31Flt_flg() ||
     Rte_IRead_swc_SCAP_Step_vcsb_DIAG_digd_b_VehLvl32Flt_flg());

  /* Outputs for Atomic SubSystem: '<S58>/switch_ramp' */
  /* Constant: '<S58>/ptlc_fact_vehLvl2FltPwrDerate' incorporates:
   *  Constant: '<S58>/Constant13'
   *  Constant: '<S58>/Constant14'
   *  Constant: '<S58>/Constant16'
   */
  swc_SCAP_SwitchRampMOTMaxTrq1(0.0F, rtb_LogicalOperator17_l, 1.0F,
    ptlc_fact_vehLvl2DerateIncGrad, ptlc_fact_vehLvl2DerateDecGrad,
    &swc_SCAP_ARID_DEF.y_o2, &rtb_RampOn_pr,
    &swc_SCAP_ARID_DEF.ARID_DEF_switch_ramp);

  /* End of Outputs for SubSystem: '<S58>/switch_ramp' */

  /* SignalConversion generated from: '<S58>/switch_ramp' */
  ptld_fact_hvbFltDegrd = swc_SCAP_ARID_DEF.y_o2;

  /* Switch: '<S58>/Switch8' incorporates:
   *  Constant: '<S58>/Constant24'
   *  Constant: '<S58>/Constant25'
   */
  if (0.0 < 0.0) {
    tmp = 0.5F;
  } else {
    tmp = 1.0F;
  }

  /* Product: '<S58>/Product2' incorporates:
   *  Constant: '<S58>/Constant19'
   *  Constant: '<S58>/Constant3'
   *  Constant: '<S58>/Constant56'
   *  Inport generated from: '<Root>/In Bus Element46'
   *  Inport generated from: '<Root>/In Bus Element28'
   *  Lookup_n-D: '<S58>/1-D Lookup Table3'
   *  MinMax: '<S58>/MinMax2'
   *  Product: '<S58>/Product'
   *  Product: '<S58>/Product1'
   *  Product: '<S58>/Product4'
   *  Sum: '<S58>/Sum1'
   *  Switch: '<S58>/Switch8'
   */
  swcscap_ptld_pwr_hvbDischAvailRaw_kW = fmaxf(look1_iflf_binlcapw
    (Rte_IRead_swc_SCAP_Step_vcib_VCIP_hvbd_q_hvbSOC_pct(), (const float32 *)
     &ptlf_X_hvbSocForDerate_pct[0], (const float32 *)
     &ptlf_Y_hvbDsChrgDerate_fact[0], 6U) * rtb_Product3 * ptld_fact_hvbFltDegrd
    - Rte_IRead_swc_SCAP_Step_vcsb_EGYM_accd_pwr_hvAttpwr_kW(), 0.0F) *
    ptlc_frac_hvbDischEff * 1.0F * tmp;

  /* Product: '<S81>/Product3' incorporates:
   *  Constant: '<S81>/Constant54'
   */
  rtb_Product3_n = ptlc_pct_bmsCurrLimitPctPreFid *
    swcscap_ptld_pwr_hvbDischAvailRaw_kW;

  /* Switch: '<S81>/Switch10' incorporates:
   *  RelationalOperator: '<S91>/FixPt Relational Operator'
   *  UnitDelay: '<S91>/Delay Input1'
   *
   * Block description for '<S91>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((sint32)swcscap_pltd_b_PwrPreLimitLvl2DischCurr > (sint32)
      swc_SCAP_ARID_DEF.DelayInput1_DSTATE_h) {
    /* Switch: '<S81>/Switch10' */
    rtb_Product3 = rtb_Product3_n;
  } else {
    /* Switch: '<S81>/Switch10' incorporates:
     *  UnitDelay: '<S81>/Unit Delay1'
     */
    rtb_Product3 = swc_SCAP_ARID_DEF.UnitDelay1_DSTATE_f;
  }

  /* End of Switch: '<S81>/Switch10' */

  /* RelationalOperator: '<S58>/Relational Operator' incorporates:
   *  Constant: '<S58>/Constant27'
   *  Product: '<S58>/Product6'
   */
  rtb_LogicalOperator1_d = (rtb_Merge_i > ptlc_f_bmsMaxDischCurrPreFidLvl1Factor
    * rtb_Merge_h);

  /* Outputs for Atomic SubSystem: '<S58>/turnON_delay1' */
  /* Chart: '<S86>/timed_delay' incorporates:
   *  Constant: '<S58>/Constant29'
   *  DataTypeConversion: '<S86>/Data Type Conversion'
   */
  if (swc_SCAP_ARID_DEF.is_active_c14_Ricardo_SW_dev__f == 0U) {
    swc_SCAP_ARID_DEF.is_active_c14_Ricardo_SW_dev__f = 1U;
    if (rtb_LogicalOperator1_d) {
      swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_i5 = swc_SCAP_IN_ON_p;
      swcscap_pltd_b_PwrPreLimitLvl1DischCurr = true;
    } else {
      swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_i5 = swc_SCAP_IN_OFF_p;
      swcscap_pltd_b_PwrPreLimitLvl1DischCurr = false;
    }
  } else {
    switch (swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_i5) {
     case swc_SCAP_IN_OFF_p:
      if (rtb_LogicalOperator1_d) {
        if (rtb_t_delay_on_pj_tmp == 0.0F) {
          swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_i5 = swc_SCAP_IN_ON_p;
          swcscap_pltd_b_PwrPreLimitLvl1DischCurr = true;
        } else {
          swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_i5 = swc_SCAP_IN_ON_WAIT_k;
          swc_SCAP_ARID_DEF.t_wait_a = ((float32)PTL_TASK_INTERVAL_S);
          swcscap_pltd_b_PwrPreLimitLvl1DischCurr = false;
        }
      } else {
        swcscap_pltd_b_PwrPreLimitLvl1DischCurr = false;
      }
      break;

     case swc_SCAP_IN_ON_p:
      if (!rtb_LogicalOperator1_d) {
        swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_i5 = swc_SCAP_IN_OFF_p;
        swcscap_pltd_b_PwrPreLimitLvl1DischCurr = false;
      } else {
        swcscap_pltd_b_PwrPreLimitLvl1DischCurr = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtb_LogicalOperator1_d) {
        swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_i5 = swc_SCAP_IN_OFF_p;
        swcscap_pltd_b_PwrPreLimitLvl1DischCurr = false;
      } else if (swc_SCAP_ARID_DEF.t_wait_a > rtb_t_delay_on_pj_tmp - ((float32)
                  PTL_TASK_INTERVAL_S)) {
        swc_SCAP_ARID_DEF.is_c14_Ricardo_SW_dev_lib_i5 = swc_SCAP_IN_ON_p;
        swcscap_pltd_b_PwrPreLimitLvl1DischCurr = true;
      } else {
        swc_SCAP_ARID_DEF.t_wait_a += ((float32)PTL_TASK_INTERVAL_S);
        swcscap_pltd_b_PwrPreLimitLvl1DischCurr = false;
      }
      break;
    }
  }

  /* End of Chart: '<S86>/timed_delay' */
  /* End of Outputs for SubSystem: '<S58>/turnON_delay1' */

  /* Switch: '<S81>/Switch9' incorporates:
   *  MinMax: '<S81>/MinMax'
   *  Switch: '<S81>/Switch11'
   */
  if (swcscap_pltd_b_PwrPreLimitLvl2DischCurr) {
    ptld_pwr_hvbDischAvail_kW = fminf(swcscap_ptld_pwr_hvbDischAvailRaw_kW,
      rtb_Product3);
  } else if (swcscap_pltd_b_PwrPreLimitLvl1DischCurr) {
    /* Switch: '<S81>/Switch11' */
    ptld_pwr_hvbDischAvail_kW = rtb_Product3_n;
  } else {
    ptld_pwr_hvbDischAvail_kW = swcscap_ptld_pwr_hvbDischAvailRaw_kW;
  }

  /* End of Switch: '<S81>/Switch9' */

  /* RelationalOperator: '<S58>/Relational Operator6' incorporates:
   *  Constant: '<S58>/Constant30'
   */
  rtb_RelationalOperator6 = (((uint8)1U) == 0);

  /* Update for UnitDelay: '<S90>/Delay Input1'
   *
   * Block description for '<S90>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_SCAP_ARID_DEF.DelayInput1_DSTATE = swcscap_pltd_b_PwrPreLimitLvl2ChgCurr;

  /* Update for UnitDelay: '<S80>/Unit Delay1' */
  swc_SCAP_ARID_DEF.UnitDelay1_DSTATE = rtb_Switch8;

  /* Update for UnitDelay: '<S91>/Delay Input1'
   *
   * Block description for '<S91>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_SCAP_ARID_DEF.DelayInput1_DSTATE_h =
    swcscap_pltd_b_PwrPreLimitLvl2DischCurr;

  /* Update for UnitDelay: '<S81>/Unit Delay1' */
  swc_SCAP_ARID_DEF.UnitDelay1_DSTATE_f = rtb_Product3;

  /* End of Outputs for SubSystem: '<S4>/HVBatteryPowerLimitation' */

  /* Outputs for Atomic SubSystem: '<S4>/PowerLimitsArbitration' */
  swc_SCAP_PowerLimitsArbitration();

  /* End of Outputs for SubSystem: '<S4>/PowerLimitsArbitration' */

  /* Outputs for Atomic SubSystem: '<S4>/PowerToTorqueLimitsConversion' */
  s_PowerToTorqueLimitsConversion();

  /* End of Outputs for SubSystem: '<S4>/PowerToTorqueLimitsConversion' */
}

/* Output and update for atomic system: '<S5>/AxleDrive2Whl_Conv' */
static void swc_SCAP_AxleDrive2Whl_Conv(void)
{
  /* MinMax: '<S116>/MinMax3' incorporates:
   *  Constant: '<S116>/Constant7'
   */
  tqld_tq_whlMax_Nm = fmaxf(((float32)TRQ_ZERO), tqld_tq_axle2MaxTq_Nm);

  /* MinMax: '<S116>/MinMax4' incorporates:
   *  Constant: '<S116>/Constant1'
   */
  tqld_tq_whlMin_Nm = fminf(((float32)TRQ_ZERO), tqld_tq_axle2MinTq_Nm);
}

/* Output and update for atomic system: '<S5>/EADShaft2SecondaryAxle_Conv' */
static void swc_EADShaft2SecondaryAxle_Conv(void)
{
  float32 rtb_Product3;

  /* Product: '<S117>/Product3' */
  rtb_Product3 = swc_SCAP_ARID_DEF.DataTypeConversion16 *
    swc_SCAP_ARID_DEF.DataTypeConversion2;

  /* Product: '<S117>/Product1' */
  tqld_tq_axle2MinTq_Nm = tqld_tq_eadMot2AllwdMinTq_Nm * rtb_Product3;

  /* Product: '<S117>/Product2' */
  tqld_tq_axle2MaxTq_Nm = tqld_tq_eadMot2AllwdMaxTq_Nm * rtb_Product3;
}

/*
 * System initialize for atomic system:
 *    '<S118>/SwitchRampMOTMaxTrqLim'
 *    '<S118>/SwitchRampMOTMinTrqLim'
 */
static void swc_SwitchRampMOTMaxTrqLim_Init(float32 *rty_y, boolean *rty_RampOn)
{
  /* SystemInitialize for Chart: '<S123>/Chart' */
  *rty_y = 0.0F;
  *rty_RampOn = false;
}

/*
 * Output and update for atomic system:
 *    '<S118>/SwitchRampMOTMaxTrqLim'
 *    '<S118>/SwitchRampMOTMinTrqLim'
 */
static void swc_SCAP_SwitchRampMOTMaxTrqLim(float32 rtu_u1, boolean rtu_sw,
  float32 rtu_u2, float32 rtu_up, float32 rtu_lo, float32 *rty_y, boolean
  *rty_RampOn, ARID_DEF_switch_ramp_swc_SC_h_T *swc_SCAP__ARID_DEF_arg)
{
  float32 rtb_MinMax1_h;
  float32 rtb_MinMax_if;

  /* MinMax: '<S121>/MinMax' incorporates:
   *  Constant: '<S121>/Constant1'
   *  Constant: '<S121>/Constant2'
   *  Product: '<S121>/Product'
   */
  rtb_MinMax_if = fmaxf(rtu_up * 0.01F, 0.0F);

  /* MinMax: '<S121>/MinMax1' incorporates:
   *  Constant: '<S121>/Constant1'
   *  Constant: '<S121>/Constant2'
   *  Product: '<S121>/Product1'
   */
  rtb_MinMax1_h = fminf(0.0F, 0.01F * rtu_lo);

  /* Chart: '<S123>/Chart' */
  if (swc_SCAP__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li == 0U) {
    swc_SCAP__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li = 1U;
    swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2_l;
    *rty_RampOn = false;
    *rty_y = rtu_u2;
  } else {
    switch (swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib) {
     case swc_SCAP_IN_U1_g:
      *rty_RampOn = false;
      if (!rtu_sw) {
        if (rtu_u2 >= rtu_u1) {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2_dc;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_INC_h;
          *rty_RampOn = true;
          *rty_y = fminf(fmaxf(fminf(rtu_u2 - *rty_y, rtb_MinMax_if) + *rty_y,
                               rtu_u1), rtu_u2);
        } else {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U1_TO_U2_dc;
          swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_DEC_b;
          *rty_RampOn = true;
          *rty_y = fmaxf(fminf(fmaxf(rtu_u2 - *rty_y, rtb_MinMax1_h) + *rty_y,
                               rtu_u1), rtu_u2);
        }
      } else {
        *rty_y = rtu_u1;
      }
      break;

     case swc_SCAP_IN_U1_TO_U2_dc:
      {
        if (rtu_sw) {
          if (rtu_u1 >= rtu_u2) {
            swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_c;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_SCAP_IN_U2_TO_U1_bs;
            swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_INC_bv;
            *rty_RampOn = true;
            *rty_y = fminf(fmaxf(fminf(rtu_u1 - *rty_y, rtb_MinMax_if) + *rty_y,
                                 rtu_u2), rtu_u1);
          } else {
            swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_c;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_SCAP_IN_U2_TO_U1_bs;
            swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_DEC_f;
            *rty_RampOn = true;
            *rty_y = fmaxf(fminf(fmaxf(rtu_u1 - *rty_y, rtb_MinMax1_h) + *rty_y,
                                 rtu_u2), rtu_u1);
          }
        } else if (swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 ==
                   swc_SCAP_IN_U1_TO_U2_DEC_b) {
          float32 tmp;
          *rty_RampOn = true;
          tmp = rtu_u2 - *rty_y;
          if (tmp >= rtb_MinMax1_h) {
            swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_c;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2_l;
            *rty_RampOn = false;
            *rty_y = rtu_u2;
          } else {
            *rty_y = fmaxf(fminf(fmaxf(tmp, rtb_MinMax1_h) + *rty_y, rtu_u1),
                           rtu_u2);
          }
        } else {
          float32 tmp;

          /* case IN_U1_TO_U2_INC: */
          *rty_RampOn = true;
          tmp = rtu_u2 - *rty_y;
          if (tmp <= rtb_MinMax_if) {
            swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_NO_ACTIVE_CHILD_c;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U2_l;
            *rty_RampOn = false;
            *rty_y = rtu_u2;
          } else {
            *rty_y = fminf(fmaxf(fminf(tmp, rtb_MinMax_if) + *rty_y, rtu_u1),
                           rtu_u2);
          }
        }
      }
      break;

     case swc_SCAP_IN_U2_l:
      *rty_RampOn = false;
      if (rtu_sw) {
        if (rtu_u1 >= rtu_u2) {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1_bs;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_INC_bv;
          *rty_RampOn = true;
          *rty_y = fminf(fmaxf(fminf(rtu_u1 - *rty_y, rtb_MinMax_if) + *rty_y,
                               rtu_u2), rtu_u1);
        } else {
          swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCAP_IN_U2_TO_U1_bs;
          swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_U2_TO_U1_DEC_f;
          *rty_RampOn = true;
          *rty_y = fmaxf(fminf(fmaxf(rtu_u1 - *rty_y, rtb_MinMax1_h) + *rty_y,
                               rtu_u2), rtu_u1);
        }
      } else {
        *rty_y = rtu_u2;
      }
      break;

     default:
      {
        /* case IN_U2_TO_U1: */
        if (!rtu_sw) {
          if (rtu_u2 >= rtu_u1) {
            swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_c;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_SCAP_IN_U1_TO_U2_dc;
            swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_INC_h;
            *rty_RampOn = true;
            *rty_y = fminf(fmaxf(fminf(rtu_u2 - *rty_y, rtb_MinMax_if) + *rty_y,
                                 rtu_u1), rtu_u2);
          } else {
            swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_c;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_SCAP_IN_U1_TO_U2_dc;
            swc_SCAP__ARID_DEF_arg->is_U1_TO_U2 = swc_SCAP_IN_U1_TO_U2_DEC_b;
            *rty_RampOn = true;
            *rty_y = fmaxf(fminf(fmaxf(rtu_u2 - *rty_y, rtb_MinMax1_h) + *rty_y,
                                 rtu_u1), rtu_u2);
          }
        } else if (swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 ==
                   swc_SCAP_IN_U2_TO_U1_DEC_f) {
          float32 tmp;
          *rty_RampOn = true;
          tmp = rtu_u1 - *rty_y;
          if (tmp >= rtb_MinMax1_h) {
            swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_c;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U1_g;
            *rty_RampOn = false;
            *rty_y = rtu_u1;
          } else {
            *rty_y = fmaxf(fminf(fmaxf(tmp, rtb_MinMax1_h) + *rty_y, rtu_u2),
                           rtu_u1);
          }
        } else {
          float32 tmp;

          /* case IN_U2_TO_U1_INC: */
          *rty_RampOn = true;
          tmp = rtu_u1 - *rty_y;
          if (tmp <= rtb_MinMax_if) {
            swc_SCAP__ARID_DEF_arg->is_U2_TO_U1 = swc_SCAP_IN_NO_ACTIVE_CHILD_c;
            swc_SCAP__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCAP_IN_U1_g;
            *rty_RampOn = false;
            *rty_y = rtu_u1;
          } else {
            *rty_y = fminf(fmaxf(fminf(tmp, rtb_MinMax_if) + *rty_y, rtu_u2),
                           rtu_u1);
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<S123>/Chart' */
}

/* System initialize for atomic system: '<S5>/SecondaryEADMotorAllowedTorque' */
static void SecondaryEADMotorAllowedTo_Init(void)
{
  /* local block i/o variables */
  boolean rtb_RampOn_l;
  boolean rtb_RampOn_aa;

  /* SystemInitialize for Atomic SubSystem: '<S118>/SwitchRampMOTMaxTrqLim' */
  swc_SwitchRampMOTMaxTrqLim_Init(&swc_SCAP_ARID_DEF.y_o, &rtb_RampOn_aa);

  /* End of SystemInitialize for SubSystem: '<S118>/SwitchRampMOTMaxTrqLim' */

  /* SystemInitialize for Atomic SubSystem: '<S118>/SwitchRampMOTMinTrqLim' */
  swc_SwitchRampMOTMaxTrqLim_Init(&swc_SCAP_ARID_DEF.y, &rtb_RampOn_l);

  /* End of SystemInitialize for SubSystem: '<S118>/SwitchRampMOTMinTrqLim' */
}

/* Output and update for atomic system: '<S5>/SecondaryEADMotorAllowedTorque' */
static void SecondaryEADMotorAllowedTorque(void)
{
  /* local block i/o variables */
  boolean rtb_RampOn_l;
  boolean rtb_RampOn_aa;

  /* Outputs for Atomic SubSystem: '<S118>/SwitchRampMOTMaxTrqLim' */

  /* Constant: '<S118>/Constant7' incorporates:
   *  Constant: '<S118>/Constant2'
   *  Constant: '<S118>/Constant6'
   */
  swc_SCAP_SwitchRampMOTMaxTrqLim(ptld_tq_ead2TqMax_Nm, tqld_b_eadMot2TqEnad,
    ((float32)TRQ_ZERO), tqlc_tq_eadMot2MxTqIncGrad_Nmps,
    tqlc_tq_eadMot2MxTqDecGrad_Nmps, &swc_SCAP_ARID_DEF.y_o, &rtb_RampOn_aa,
    &swc_SCAP_ARID_DEF.ARID_DEF_SwitchRampMOTMaxTrqLi);

  /* End of Outputs for SubSystem: '<S118>/SwitchRampMOTMaxTrqLim' */

  /* Outputs for Atomic SubSystem: '<S118>/SwitchRampMOTMinTrqLim' */

  /* Constant: '<S118>/Constant1' incorporates:
   *  Constant: '<S118>/Constant3'
   *  Constant: '<S118>/Constant4'
   */
  swc_SCAP_SwitchRampMOTMaxTrqLim(ptld_tq_ead2TqMin_Nm, tqld_b_eadMot2TqEnad,
    ((float32)TRQ_ZERO), tqlc_tq_eadMot2MnTqIncGrad_Nmps,
    tqlc_tq_eadMot2MnTqDecGrad_Nmps, &swc_SCAP_ARID_DEF.y, &rtb_RampOn_l,
    &swc_SCAP_ARID_DEF.ARID_DEF_SwitchRampMOTMinTrqLi);

  /* End of Outputs for SubSystem: '<S118>/SwitchRampMOTMinTrqLim' */

  /* SignalConversion generated from: '<S118>/SwitchRampMOTMaxTrqLim' */
  tqld_tq_eadMot2AllwdMaxTq_Nm = swc_SCAP_ARID_DEF.y_o;

  /* SignalConversion generated from: '<S118>/SwitchRampMOTMinTrqLim' */
  tqld_tq_eadMot2AllwdMinTq_Nm = swc_SCAP_ARID_DEF.y;
}

/* Output and update for atomic system: '<S5>/TorqueEnable' */
static void swc_SCAP_TorqueEnable(void)
{
  /* Logic: '<S119>/Logical Operator10' incorporates:
   *  Constant: '<S119>/Constant1'
   *  Logic: '<S119>/Logical Operator8'
   */
  tqld_b_eadMot2TqEnad = (swc_SCAP_ARID_DEF.DataTypeConversion58 &&
    (swc_SCAP_ARID_DEF.DataTypeConversion160 || tqlc_b_enaEADMot2In2WDMod));
}

/* System initialize for function-call system: '<S1>/TQL_TorqueLimitsConversion' */
static void TQL_TorqueLimitsConversion_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S5>/SecondaryEADMotorAllowedTorque' */
  SecondaryEADMotorAllowedTo_Init();

  /* End of SystemInitialize for SubSystem: '<S5>/SecondaryEADMotorAllowedTorque' */
}

/* Output and update for function-call system: '<S1>/TQL_TorqueLimitsConversion' */
static void swc__TQL_TorqueLimitsConversion(void)
{
  /* Outputs for Atomic SubSystem: '<S5>/TorqueEnable' */
  swc_SCAP_TorqueEnable();

  /* End of Outputs for SubSystem: '<S5>/TorqueEnable' */

  /* Outputs for Atomic SubSystem: '<S5>/SecondaryEADMotorAllowedTorque' */
  SecondaryEADMotorAllowedTorque();

  /* End of Outputs for SubSystem: '<S5>/SecondaryEADMotorAllowedTorque' */

  /* Outputs for Atomic SubSystem: '<S5>/EADShaft2SecondaryAxle_Conv' */
  swc_EADShaft2SecondaryAxle_Conv();

  /* End of Outputs for SubSystem: '<S5>/EADShaft2SecondaryAxle_Conv' */

  /* Outputs for Atomic SubSystem: '<S5>/AxleDrive2Whl_Conv' */
  swc_SCAP_AxleDrive2Whl_Conv();

  /* End of Outputs for SubSystem: '<S5>/AxleDrive2Whl_Conv' */
}

/* Model step function */
void swc_SCAP_Step(void)
{
  /* local block i/o variables */
  boolean rtb_Constant3;
  boolean rtb_DataTypeConversion27;
  uint8 rtb_BitwiseAnd1;

  /* Constant: '<Root>/Constant3' */
  rtb_Constant3 = true;

  /* DataTypeConversion: '<Root>/Data Type Conversion160' incorporates:
   *  Inport generated from: '<Root>/In Bus Element109'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion160 =
    Rte_IRead_swc_SCAP_Step_vcsb_VOMM_drid_b_veh4WDModActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Inport generated from: '<Root>/In Bus Element63'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion2 =
    Rte_IRead_swc_SCAP_Step_vcib_VCIP_eadd_fact_mot2GearRat();

  /* DataTypeConversion: '<Root>/Data Type Conversion16' incorporates:
   *  Inport generated from: '<Root>/In Bus Element71'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion16 =
    Rte_IRead_swc_SCAP_Step_vcib_VCIP_trad_fact_trsm2GearRat();

  /* DataTypeConversion: '<Root>/Data Type Conversion58' incorporates:
   *  Inport generated from: '<Root>/In Bus Element96'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion58 =
    Rte_IRead_swc_SCAP_Step_vcsb_VOMM_vsmd_b_VehRun();

  /* DataTypeConversion: '<Root>/Data Type Conversion12' incorporates:
   *  Inport generated from: '<Root>/In Bus Element91'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion12 =
    Rte_IRead_swc_SCAP_Step_vcsb_VOMM_drid_b_vehSportModActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion46' incorporates:
   *  Inport generated from: '<Root>/In Bus Element47'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion46 =
    Rte_IRead_swc_SCAP_Step_vcib_VCIP_hvbd_pwr_PeakChMax_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion30' incorporates:
   *  Inport generated from: '<Root>/In Bus Element48'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion30 =
    Rte_IRead_swc_SCAP_Step_vcib_VCIP_hvbd_pwr_PeakDischMax_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion31' incorporates:
   *  Inport generated from: '<Root>/In Bus Element49'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion31 =
    Rte_IRead_swc_SCAP_Step_vcib_VCIP_hvbd_pwr_StatChMax_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion34' incorporates:
   *  Inport generated from: '<Root>/In Bus Element50'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion34 =
    Rte_IRead_swc_SCAP_Step_vcib_VCIP_hvbd_pwr_StatDischMax_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion38' incorporates:
   *  Inport generated from: '<Root>/In Bus Element52'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion38 =
    Rte_IRead_swc_SCAP_Step_vcib_VCIP_eadd_n_mot2ActSpd_rpm();

  /* DataTypeConversion: '<Root>/Data Type Conversion65' incorporates:
   *  Inport generated from: '<Root>/In Bus Element57'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion65 =
    Rte_IRead_swc_SCAP_Step_vcib_VCIP_vscd_v_vehSpd_kph();

  /* DataTypeConversion: '<Root>/Data Type Conversion28' incorporates:
   *  Inport generated from: '<Root>/In Bus Element81'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion28 =
    Rte_IRead_swc_SCAP_Step_vcsb_VOMM_hmmd_b_EVModeActive();

  /* DataTypeConversion: '<Root>/Data Type Conversion8' incorporates:
   *  Inport generated from: '<Root>/In Bus Element80'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion8 =
    Rte_IRead_swc_SCAP_Step_vcsb_VOMM_drid_e_driveDirSel();

  /* DataTypeConversion: '<Root>/Data Type Conversion60' incorporates:
   *  Inport generated from: '<Root>/In Bus Element10'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion60 =
    Rte_IRead_swc_SCAP_Step_vcib_VCIP_eadd_e_inv2ModeAct();

  /* DataTypeConversion: '<Root>/Data Type Conversion49' incorporates:
   *  Inport generated from: '<Root>/In Bus Element12'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion49 =
    Rte_IRead_swc_SCAP_Step_vcib_VCIP_eadd_tq_mot2ActTq_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion66' incorporates:
   *  Inport generated from: '<Root>/In Bus Element13'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion66 =
    Rte_IRead_swc_SCAP_Step_vcib_VCIP_eadd_tq_mot2MaxAvailLTBst_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion68' incorporates:
   *  Inport generated from: '<Root>/In Bus Element14'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion68 =
    Rte_IRead_swc_SCAP_Step_vcib_VCIP_eadd_tq_mot2MaxAvailSTBst_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion67' incorporates:
   *  Inport generated from: '<Root>/In Bus Element15'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion67 =
    Rte_IRead_swc_SCAP_Step_vcib_VCIP_eadd_tq_mot2MaxAvailLTBrk_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion69' incorporates:
   *  Inport generated from: '<Root>/In Bus Element16'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion69 =
    Rte_IRead_swc_SCAP_Step_vcib_VCIP_eadd_tq_mot2MaxAvailSTBrk_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion70' incorporates:
   *  Inport generated from: '<Root>/In Bus Element17'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion70 =
    Rte_IRead_swc_SCAP_Step_vcib_VCIP_trad_b_trsm2GearshiftActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion71' incorporates:
   *  Inport generated from: '<Root>/In Bus Element18'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion71 = (uint8)
    Rte_IRead_swc_SCAP_Step_vcib_VCIP_trad_st_trsm2GearAct();

  /* DataTypeConversion: '<Root>/Data Type Conversion27' incorporates:
   *  Inport generated from: '<Root>/In Bus Element9'
   */
  rtb_DataTypeConversion27 = Rte_IRead_swc_SCAP_Step_vcib_VCIP_vscd_b_ESPActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion138' incorporates:
   *  Inport generated from: '<Root>/In Bus Element11'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion138 =
    Rte_IRead_swc_SCAP_Step_vcib_VCIP_vscd_b_ESPActvRaw();

  /* DataTypeConversion: '<Root>/Data Type Conversion57' incorporates:
   *  Inport generated from: '<Root>/In Bus Element100'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion57 =
    Rte_IRead_swc_SCAP_Step_vcsb_HVSM_eadd_b_ead2Enad();

  /* DataTypeConversion: '<Root>/Data Type Conversion52' incorporates:
   *  Inport generated from: '<Root>/In Bus Element90'
   */
  swc_SCAP_ARID_DEF.DataTypeConversion52 =
    Rte_IRead_swc_SCAP_Step_vcsb_RMLK_rlcd_b_rmtCtrlTqOff();

  /* CCaller: '<S3>/C Caller1' */
  scap_eadd_st_getEhbMsgErrSts = 0U;

  /* CCaller: '<S3>/C Caller1' incorporates:
   *  Constant: '<S3>/Constant158'
   */
  Dem_GetEventStatus(((uint16)32894U), &scap_eadd_st_getEhbMsgErrSts);

  /* S-Function (sfix_bitop): '<S3>/Bitwise And1' */
  rtb_BitwiseAnd1 = (uint8)(scap_eadd_st_getEhbMsgErrSts & ((uint8)1U));

  /* Logic: '<S3>/Logical Operator1' incorporates:
   *  Constant: '<S3>/Constant3'
   *  DataTypeConversion: '<S3>/con_3'
   */
  scap_eadd_b_ehbMsgErrDebd = ((rtb_BitwiseAnd1 != 0) &&
    scap_eadc_b_useGetEventSts);

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/EAD_TorqueLimitsMot2'
   */
  swc_SCAP_EAD_TorqueLimitsMot2();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/PTL_PowerLimitation'
   */
  swc_SCAP_PTL_PowerLimitation();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/TQL_TorqueLimitsConversion'
   */
  swc__TQL_TorqueLimitsConversion();

  /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator' */

  /* Outport generated from: '<Root>/Out Bus Element19' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion125'
   */
  Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_tqld_tq_axle2MaxTq_Nm(tqld_tq_axle2MaxTq_Nm);

  /* Outport generated from: '<Root>/Out Bus Element21' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion123'
   */
  Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_tqld_tq_axle2MinTq_Nm(tqld_tq_axle2MinTq_Nm);

  /* Outport generated from: '<Root>/Out Bus Element31' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion136'
   */
  Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_eadd_tq_mot2MaxLTTq_Nm
    (eadd_tq_mot2MaxLTTq_Nm);

  /* Outport generated from: '<Root>/Out Bus Element33' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion134'
   */
  Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_tqld_tq_whlMax_Nm(tqld_tq_whlMax_Nm);

  /* Outport generated from: '<Root>/Out Bus Element36' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion131'
   */
  Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_eadd_tq_mot2MaxSTTq_Nm
    (eadd_tq_mot2MaxSTTq_Nm);

  /* Outport generated from: '<Root>/Out Bus Element37' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion130'
   */
  Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_tqld_tq_whlMin_Nm(tqld_tq_whlMin_Nm);

  /* Outport generated from: '<Root>/Out Bus Element40' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion127'
   */
  Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_eadd_tq_mot2MinLTTq_Nm
    (eadd_tq_mot2MinLTTq_Nm);

  /* Outport generated from: '<Root>/Out Bus Element44' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion111'
   */
  Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_eadd_tq_mot2MinSTTq_Nm
    (eadd_tq_mot2MinSTTq_Nm);

  /* Outport generated from: '<Root>/Out Bus Element49' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion106'
   */
  Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_eadd_b_mot2TqOff(eadd_b_mot2TqOff);

  /* Outport generated from: '<Root>/Out Bus Element56' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion98'
   */
  Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW
    (ptld_pwr_hvbDischAvail_kW);
}

/* Model initialize function */
void swc_SCAP_Init(void)
{
  /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/EAD_TorqueLimitsMot2'
   */
  swc_S_EAD_TorqueLimitsMot2_Init();

  /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/PTL_PowerLimitation'
   */
  swc_SC_PTL_PowerLimitation_Init();

  /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/TQL_TorqueLimitsConversion'
   */
  TQL_TorqueLimitsConversion_Init();

  /* End of SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

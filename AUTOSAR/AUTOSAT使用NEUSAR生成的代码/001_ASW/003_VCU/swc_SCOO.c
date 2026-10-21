/*
 * File: swc_SCOO.c
 *
 * Code generated for Simulink model 'swc_SCOO'.
 *
 * Model version                  : 6.56
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Sep  9 11:13:02 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "swc_SCOO.h"
#include "rtwtypes.h"
#include "Rte_Type.h"
#include <math.h>
#include "const_ImportedDefine.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef CCD_TASK_INTERVAL_S
#error The value of parameter "CCD_TASK_INTERVAL_S" is not defined
#endif

#ifndef CTD_TASK_INTERVAL_S
#error The value of parameter "CTD_TASK_INTERVAL_S" is not defined
#endif

#ifndef VEH_SPD_MAX
#error The value of parameter "VEH_SPD_MAX" is not defined
#endif

#ifndef VSL_TASK_INTERVAL_S
#error The value of parameter "VSL_TASK_INTERVAL_S" is not defined
#endif

#ifndef WHL_TRQ_MAX
#error The value of parameter "WHL_TRQ_MAX" is not defined
#endif

#ifndef WHL_TRQ_MIN
#error The value of parameter "WHL_TRQ_MIN" is not defined
#endif

/* Named constants for Chart: '<S16>/timed_delay' */
#define swc_SCOO_IN_OFF                ((uint8)1U)
#define swc_SCOO_IN_ON                 ((uint8)2U)
#define swc_SCOO_IN_ON_WAIT            ((uint8)3U)

/* Named constants for Chart: '<S43>/Chart' */
#define swc_SCOO_IN_NO_ACTIVE_CHILD    ((uint8)0U)
#define swc_SCOO_IN_U1                 ((uint8)1U)
#define swc_SCOO_IN_U1_TO_U2           ((uint8)2U)
#define swc_SCOO_IN_U1_TO_U2_DEC       ((uint8)1U)
#define swc_SCOO_IN_U1_TO_U2_INC       ((uint8)2U)
#define swc_SCOO_IN_U2                 ((uint8)3U)
#define swc_SCOO_IN_U2_TO_U1           ((uint8)4U)
#define swc_SCOO_IN_U2_TO_U1_DEC       ((uint8)1U)
#define swc_SCOO_IN_U2_TO_U1_INC       ((uint8)2U)

/* Named constants for Chart: '<S130>/Chart' */
#define swc_SCOO_IN_NO_ACTIVE_CHILD_h  ((uint8)0U)
#define swc_SCOO_IN_U1_TO_U2_DEC_d     ((uint8)1U)
#define swc_SCOO_IN_U1_TO_U2_INC_i     ((uint8)2U)
#define swc_SCOO_IN_U1_TO_U2_c         ((uint8)2U)
#define swc_SCOO_IN_U1_e               ((uint8)1U)
#define swc_SCOO_IN_U2_TO_U1_DEC_h     ((uint8)1U)
#define swc_SCOO_IN_U2_TO_U1_INC_p     ((uint8)2U)
#define swc_SCOO_IN_U2_TO_U1_e         ((uint8)4U)
#define swc_SCOO_IN_U2_n               ((uint8)3U)

/* Named constants for Chart: '<S11>/Chart' */
#define swc_SCOO_IN_Init               ((uint8)1U)
#define swc_SCOO_IN_NO_ACTIVE_CHILD_j  ((uint8)0U)
#define swc_SCOO_IN_RETOutput          ((uint8)2U)

/* Named constants for Chart: '<S6>/Button_Sts' */
#define swc_SCOO_IN_Accel_Error        ((uint8)1U)
#define swc_SCOO_IN_Accel_Pressed      ((uint8)2U)
#define swc_SCOO_IN_Accel_Sts          ((uint8)1U)
#define swc_SCOO_IN_Coast_Error        ((uint8)1U)
#define swc_SCOO_IN_Coast_Pressed      ((uint8)2U)
#define swc_SCOO_IN_Coast_Sts          ((uint8)2U)
#define swc_SCOO_IN_Cruise_Error       ((uint8)1U)
#define swc_SCOO_IN_Cruise_Pressed     ((uint8)2U)
#define swc_SCOO_IN_Cruise_Sts         ((uint8)3U)
#define swc_SCOO_IN_Default_Sts        ((uint8)4U)
#define swc_SCOO_IN_Pre_Accel_Sts      ((uint8)5U)
#define swc_SCOO_IN_Pre_Coast_Sts      ((uint8)6U)
#define swc_SCOO_IN_Pre_Cruise_Sts     ((uint8)7U)
#define swc_SCOO_IN_Pre_Voltage_OC     ((uint8)9U)
#define swc_SCOO_IN_Pre_Voltage_SCB    ((uint8)10U)
#define swc_SCOO_IN_Pre_Voltage_SCG    ((uint8)11U)
#define swc_SCOO_IN_Voltage_Abnormal   ((uint8)12U)
#define swc_SCOO_IN_Voltage_OC         ((uint8)13U)
#define swc_SCOO_IN_Voltage_SCB        ((uint8)14U)
#define swc_SCOO_IN_Voltage_SCG        ((uint8)15U)
#define swc_SCO_IN_Pre_Voltage_Abnormal ((uint8)8U)

/* Named constants for Chart: '<S7>/CruiseStates' */
#define IN_Cruise_Speed_Inc_Acceleratio ((uint8)3U)
#define sw_IN_Cruise_Speed_Deceleration ((uint8)2U)
#define swc_SCOO_IN_AccelOverride      ((uint8)1U)
#define swc_SCOO_IN_Active             ((uint8)2U)
#define swc_SCOO_IN_Cruise_Active      ((uint8)1U)
#define swc_SCOO_IN_Cruise_Disabled    ((uint8)2U)
#define swc_SCOO_IN_Cruise_Speed_TipIn ((uint8)4U)
#define swc_SCOO_IN_Cruise_Speed_TipOut ((uint8)5U)
#define swc_SCOO_IN_Cruise_Standby     ((uint8)3U)

/* Named constants for Chart: '<S62>/timed_delay' */
#define swc_SCOO_IN_OFF_a              ((uint8)1U)
#define swc_SCOO_IN_ON_WAIT_n          ((uint8)3U)
#define swc_SCOO_IN_ON_j               ((uint8)2U)

/* Named constants for Chart: '<S117>/timed_delay' */
#define swc_SCOO_IN_OFF_c              ((uint8)1U)
#define swc_SCOO_IN_ON_WAIT_i          ((uint8)3U)
#define swc_SCOO_IN_ON_b               ((uint8)2U)

/* Exported data definition */
#define swc_SCOO_START_SEC_CONST_VOLATILE
#include "swc_SCOO_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_CAL */
const volatile float32 ccc_dacc_accTgtMaxRate_mps3 = 2.0F;/* Referenced by: '<S47>/Constant4' */
const volatile float32 ccc_dacc_accTgtMinRate_mps3 = -2.0F;/* Referenced by: '<S47>/Constant6' */
const volatile float32 ccda_crsSpdCtrl_X_VehSpd_kph[10] = { 20.0F, 30.0F, 40.0F,
  50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F, 120.0F } ;/* Referenced by:
                                                        * '<S76>/1-D Lookup Table'
                                                        * '<S66>/1-D Lookup Table'
                                                        */

/* Vehicle speed limit control - vehicle speed axis */
const volatile float32 ccda_crsSpdCtrl_Y_VehSpdErr_kph[11] = { -20.0F, -10.0F,
  -5.0F, -2.0F, -1.0F, 0.0F, 1.0F, 2.0F, 5.0F, 10.0F, 20.0F } ;/* Referenced by:
                                                                * '<S76>/1-D Lookup Table1'
                                                                * '<S76>/1-D Lookup Table2'
                                                                */

/* Vehicle speed limit control - vehicle speed error axis */
const volatile float32 ccda_pedlPosVirt_X_VehSpd_kph[12] = { 21.9809F, 30.7733F,
  39.5656F, 48.358F, 57.1504F, 65.9427F, 74.7351F, 83.5275F, 92.3198F,
  101.112198F, 109.904602F, 118.696899F } ;
                                   /* Referenced by: '<S5>/2-D Lookup Table4' */

/* Virtual accelerator Pedal position  - Vehicle Speed Axis */
const volatile float32 ccda_pedlPosVirt_Y_WhlDem_Nm[10] = { 0.0F, 500.0F,
  1000.0F, 1500.0F, 2000.0F, 2500.0F, 3000.0F, 4000.0F, 5000.0F, 6000.0F } ;
                                   /* Referenced by: '<S5>/2-D Lookup Table4' */

/* Virtual accelerator Pedal position  - Wheel Torque Demand Axis */
const volatile float32 ccdc_acc_tqKiEnaVehAccErrHi_mps2 = 0.3F;/* Referenced by: '<S66>/Relay4' */
const volatile float32 ccdc_acc_tqKiEnaVehAccErrLo_mps2 = 0.2F;/* Referenced by: '<S66>/Relay4' */
const volatile float32 ccdc_acc_vehAccLongMin_mps2 = 0.05F;/* Referenced by: '<S53>/Constant1' */
const volatile float32 ccdc_acc_vehAccTgtMax_mps2 = 1.0F;/* Referenced by: '<S48>/Constant8' */
const volatile float32 ccdc_acc_vehAccTgtMin_mps2 = -1.0F;/* Referenced by: '<S48>/Constant9' */
const volatile boolean ccdc_b_crsCtrlAccKiEna_ovrdflg = true;/* Referenced by: '<S51>/Constant9' */
const volatile boolean ccdc_b_crsCtrlAccKiEna_ovrdval = false;/* Referenced by: '<S51>/Constant1' */
const volatile boolean ccdc_b_crsCtrlBaseLineEna = false;/* Referenced by:
                                                          * '<S37>/Constant1'
                                                          * '<S37>/Constant9'
                                                          */
const volatile boolean ccdc_b_enaVehCrsCtrl = true;/* Referenced by:
                                                    * '<S22>/Constant2'
                                                    * '<S35>/Constant2'
                                                    */

/* Cruise Control Enable */
const volatile boolean ccdc_b_whlDem_ovrdflg = false;/* Referenced by: '<S34>/Constant2' */

/* Cruise Torque over flag */
const volatile float32 ccdc_dacc_vehAccLongDec_mps3 = -0.1F;/* Referenced by: '<S53>/Constant7' */
const volatile float32 ccdc_dacc_vehAccLongInc_mps3 = 0.1F;/* Referenced by: '<S53>/Constant6' */
const volatile float32 ccdc_dtq_crsCtrlTqDecGrad_Nmps = -50000.0F;/* Referenced by: '<S8>/Constant6' */

/* Cruise Control Torque decrease gradient when disabled */
const volatile float32 ccdc_dtq_crsCtrlTqIncGrad_Nmps = 50000.0F;/* Referenced by: '<S8>/Constant2' */

/* Cruise Control Torque increase gradient when enabled */
const volatile float32 ccdc_fact_crsSpdCtrlKd = 0.0F;/* Referenced by: '<S46>/Constant3' */

/* Vehicle cruise speed control - Kd (derivative) term gain */
const volatile float32 ccdc_l_vehTyreRadius_m = 0.37125F;/* Referenced by: '<S66>/Constant1' */
const volatile float32 ccdc_m_vehMass_kg = 4000.0F;/* Referenced by: '<S66>/Constant4' */
const volatile float32 ccdc_t_vehAccActTau_s = 0.2F;/* Referenced by: '<S65>/Constant4' */
const volatile float32 ccdc_tm_accelOvrdMax_s = 900.0F;/* Referenced by: '<S7>/Constant1' */

/* Maximum time allowed in override state */
const volatile float32 ccdc_tm_btnPrsd_s = 0.2F;/* Referenced by: '<S6>/Constant5' */

/* Time to confirm button has been pressed */
const volatile float32 ccdc_tm_btnRlsd_s = 0.01F;/* Referenced by: '<S6>/Constant3' */

/* Time to confirm button has been released */
const volatile float32 ccdc_tm_btnStuck_s = 300.0F;/* Referenced by: '<S6>/Constant1' */

/* Button Push Stuck Time */
const volatile float32 ccdc_tm_btnVltgAbn_s = 1.0F;/* Referenced by: '<S6>/Constant2' */

/* Time to confirm cruise button has been long pressed (cancel) */
const volatile float32 ccdc_tm_btnVltgOC_s = 1.0F;/* Referenced by: '<S6>/Constant7' */

/* Time to confirm cruise button has been long pressed (cancel) */
const volatile float32 ccdc_tm_btnVltgSCB_s = 1.0F;/* Referenced by: '<S6>/Constant6' */

/* Time to confirm cruise button has been long pressed (cancel) */
const volatile float32 ccdc_tm_btnVltgSCG_s = 1.0F;/* Referenced by: '<S6>/Constant14' */

/* Time to confirm cruise button has been long pressed (cancel) */
const volatile float32 ccdc_tm_cnclBtnDly_s = 0.75F;/* Referenced by: '<S6>/Constant22' */

/* Time to confirm cruise button has been long pressed (cancel) */
const volatile float32 ccdc_tm_crsBtnLongPrs_s = 0.75F;/* Referenced by: '<S7>/Constant5' */

/* Button Delay Time to detect long press */
const volatile float32 ccdc_tm_crsSpdCtrlDerivTc_s = 0.02F;/* Referenced by: '<S46>/Constant4' */

/* Vehicle cruise speed control Derivative term time constant */
const volatile float32 ccdc_tm_crsSpdUpdtDly_s = 0.75F;/* Referenced by: '<S7>/Constant10' */

/* Delay to update target speed during long press */
const volatile float32 ccdc_tm_vehAccLongActvWait_s = 20.0F;/* Referenced by: '<S53>/Constant4' */
const volatile float32 ccdc_tm_vehSpdDiffTmOut_s = 120.0F;/* Referenced by: '<S22>/Constant22' */

/* Maximum allowable speed deviation time-out */
const volatile float32 ccdc_tq_crsAccelPdlOvrdHi_Nm = 5.0F;/* Referenced by: '<S5>/Relay4' */

/* Cruise control overriden by accel pedal torque demand - high threshold */
const volatile float32 ccdc_tq_crsAccelPdlOvrdLo_Nm = 0.0F;/* Referenced by: '<S5>/Relay4' */

/* Cruise control overriden by accel pedal torque demand - low threshold */
const volatile float32 ccdc_tq_whlDem_ovrdval = 0.0F;/* Referenced by: '<S34>/Constant1' */

/* Cruise Torque over value */
const volatile float32 ccdc_u_btnVltgAbnHiThd_V = 4.2F;/* Referenced by: '<S6>/Constant15' */

/* Button voltage abnormal high threshold */
const volatile float32 ccdc_u_btnVltgAbnLoThd_V = 0.2F;/* Referenced by: '<S6>/Constant16' */

/* Button voltage abnormal low threshold */
const volatile float32 ccdc_u_btnVltgDftHiThd_V = 4.0F;/* Referenced by: '<S6>/Constant23' */

/* Button voltage Default high threshold */
const volatile float32 ccdc_u_btnVltgDftLoThd_V = 3.47F;/* Referenced by: '<S6>/Constant24' */

/* Button voltage Default low threshold */
const volatile float32 ccdc_u_btnVltgOCHiThd_V = 4.95F;/* Referenced by: '<S6>/Constant17' */

/* Button voltage OC high threshold */
const volatile float32 ccdc_u_btnVltgOCLoThd_V = 4.19F;/* Referenced by: '<S6>/Constant18' */

/* Button voltage OC low threshold */
const volatile float32 ccdc_u_btnVltgSCBHiThd_V = 4.96F;/* Referenced by: '<S6>/Constant19' */

/* Button voltage SCB high threshold */
const volatile float32 ccdc_u_btnVltgSCGLoThd_V = 0.19F;/* Referenced by: '<S6>/Constant20' */

/* Button voltage SCG low threshold */
const volatile float32 ccdc_u_crsBtnHiThd_V = 0.54F;/* Referenced by: '<S6>/Constant4' */

/* Cruise main button voltage high threshold */
const volatile float32 ccdc_u_crsBtnLoThd_V = 0.28F;/* Referenced by: '<S6>/Constant13' */

/* Cruise main button voltage low threshold */
const volatile float32 ccdc_u_resBtnHiThd_V = 1.6F;/* Referenced by: '<S6>/Constant8' */

/* Resume button voltage high threshold */
const volatile float32 ccdc_u_resBtnLoThd_V = 1.24F;/* Referenced by: '<S6>/Constant9' */

/* Resume button voltage low threshold */
const volatile float32 ccdc_u_setBtnHiThd_V = 1.0F;/* Referenced by: '<S6>/Constant10' */

/* Set button voltage high threshold */
const volatile float32 ccdc_u_setBtnLoThd_V = 0.72F;/* Referenced by: '<S6>/Constant11' */

/* Set button voltage low threshold */
const volatile float32 ccdc_v_accKiEnaVehSpdErrHi_kph = 5.0F;/* Referenced by: '<S51>/Relay4' */
const volatile float32 ccdc_v_accKiEnaVehSpdErrLo_kph = 3.0F;/* Referenced by: '<S51>/Relay4' */
const volatile float32 ccdc_v_crsSpdLargeChng_kph = 5.0F;/* Referenced by: '<S7>/Constant7' */

/* Cruise Target Speed large change */
const volatile float32 ccdc_v_crsSpdTipChng_kph = 1.0F;/* Referenced by: '<S7>/Constant6' */

/* Cruise Target Speed small change */
const volatile float32 ccdc_v_crsTgtSpdChngMax_kph = 15.0F;/* Referenced by: '<S7>/Constant8' */

/* Maximum target speed change allowed in one button press */
const volatile float32 ccdc_v_crsTgtSpdMax_kph = 110.0F;/* Referenced by: '<S7>/Constant2' */

/* Cruise Maximum Target Speed */
const volatile float32 ccdc_v_crsTgtSpdMin_kph = 30.0F;/* Referenced by: '<S7>/Constant3' */

/* Cruise Minimum Target Speed */
const volatile float32 ccdc_v_vehSpdDiffMax_kph = 20.0F;/* Referenced by: '<S22>/Constant20' */

/* Maximum allowable speed deviation from target */
const volatile float32 ccdc_v_vehSpdErrIntglEnagHi_kph = 5.0F;/* Referenced by: '<S35>/Relay4' */

/* Vehicle Speed error to disable the integral control */
const volatile float32 ccdc_v_vehSpdErrIntglEnagLo_kph = 3.0F;/* Referenced by: '<S35>/Relay4' */

/* Vehicle Speed error to enable the integral control */
const volatile float32 ccdc_v_vehSpdMaxEnaCrs_kph = 110.0F;/* Referenced by: '<S7>/Constant11' */

/* Vehicle Maximum Speed to Enable Cruise Control */
const volatile float32 ccdc_v_vehSpdMinEnaCrs_kph = 5.0F;/* Referenced by: '<S7>/Constant12' */

/* Vehicle Minimum Speed to Enable Cruise Control */
const volatile float32 ccdc_x_crsAccelPdlOvrdHi_pct = 5.0F;/* Referenced by: '<S5>/Relay1' */

/* Cruise control overriden by accel pedal position - high threshold */
const volatile float32 ccdc_x_crsAccelPdlOvrdLo_pct = 2.0F;/* Referenced by: '<S5>/Relay1' */

/* Cruise control overriden by accel pedal position - low threshold */
const volatile float32 ccdf_crsSpdCtrlFF_Y_Nm[10] = { 140.706528F, 172.242752F,
  210.874542F, 256.601868F, 309.424774F, 369.343201F, 436.357239F, 510.466827F,
  591.671936F, 775.368896F } ;         /* Referenced by:
                                        * '<S76>/1-D Lookup Table'
                                        * '<S66>/1-D Lookup Table'
                                        */

/* Vehicle cruise speed control feedforward torque Map */
const volatile float32 ccdf_crsSpdCtrlKi_Y_fact[11] = { 0.0F, 0.0F, 0.0F, 5.0F,
  10.0F, 10.0F, 10.0F, 5.0F, 0.0F, 0.0F, 0.0F } ;
                                  /* Referenced by: '<S76>/1-D Lookup Table1' */

/* Vehicle cruise speed control - Ki (integral) Map */
const volatile float32 ccdf_crsSpdCtrlKp_Y_fact[11] = { 100.0F, 100.0F, 100.0F,
  70.0F, 50.0F, 50.0F, 50.0F, 70.0F, 100.0F, 100.0F, 100.0F } ;
                                  /* Referenced by: '<S76>/1-D Lookup Table2' */

/* Vehicle cruise speed control - Kp (proportional) Map */
const volatile float32 ccdm_crsCtrlAccKi_X_VehSpdErr_kph[17] = { -20.0F, -15.0F,
  -10.0F, -5.0F, -4.0F, -3.0F, -2.0F, -1.0F, 0.0F, 1.0F, 2.0F, 3.0F, 4.0F, 5.0F,
  10.0F, 15.0F, 20.0F } ;         /* Referenced by: '<S51>/1-D Lookup Table2' */

const volatile float32 ccdm_crsCtrlAccKi_Y_VehSpdAct_kph[17] = { 0.0F, 10.0F,
  20.0F, 30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F, 110.0F, 120.0F,
  130.0F, 140.0F, 150.0F, 160.0F } ;
                                  /* Referenced by: '<S51>/1-D Lookup Table2' */

const volatile float32 ccdm_crsCtrlAccKi_Z_fact[289] = { 0.005F, 0.005F, 0.005F,
  0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
  0.005F, 0.005F, 0.005F, 0.005F, 0.00533333328F, 0.00533333328F, 0.00533333328F,
  0.00533333328F, 0.00533333328F, 0.00533333328F, 0.00533333328F, 0.00533333328F,
  0.00533333328F, 0.00533333328F, 0.00533333328F, 0.00533333328F, 0.00533333328F,
  0.00533333328F, 0.00533333328F, 0.00533333328F, 0.00533333328F, 0.006F, 0.006F,
  0.006F, 0.006F, 0.006F, 0.006F, 0.006F, 0.006F, 0.006F, 0.006F, 0.006F, 0.006F,
  0.006F, 0.006F, 0.006F, 0.006F, 0.006F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
  0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
  0.01F, 0.0125F, 0.0125F, 0.0125F, 0.0125F, 0.0125F, 0.0125F, 0.0125F, 0.0125F,
  0.0125F, 0.0125F, 0.0125F, 0.0125F, 0.0125F, 0.0125F, 0.0125F, 0.0125F,
  0.0125F, 0.0166666675F, 0.0166666675F, 0.0166666675F, 0.0166666675F,
  0.0166666675F, 0.0166666675F, 0.0166666675F, 0.0166666675F, 0.0166666675F,
  0.0166666675F, 0.0166666675F, 0.0166666675F, 0.0166666675F, 0.0166666675F,
  0.0166666675F, 0.0166666675F, 0.0166666675F, 0.025F, 0.025F, 0.025F, 0.025F,
  0.025F, 0.025F, 0.025F, 0.025F, 0.025F, 0.025F, 0.025F, 0.025F, 0.025F, 0.025F,
  0.025F, 0.025F, 0.025F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F,
  0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F,
  0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F,
  0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F,
  0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.025F,
  0.025F, 0.025F, 0.025F, 0.025F, 0.025F, 0.025F, 0.025F, 0.025F, 0.025F, 0.025F,
  0.025F, 0.025F, 0.025F, 0.025F, 0.025F, 0.025F, 0.0166666675F, 0.0166666675F,
  0.0166666675F, 0.0166666675F, 0.0166666675F, 0.0166666675F, 0.0166666675F,
  0.0166666675F, 0.0166666675F, 0.0166666675F, 0.0166666675F, 0.0166666675F,
  0.0166666675F, 0.0166666675F, 0.0166666675F, 0.0166666675F, 0.0166666675F,
  0.0125F, 0.0125F, 0.0125F, 0.0125F, 0.0125F, 0.0125F, 0.0125F, 0.0125F,
  0.0125F, 0.0125F, 0.0125F, 0.0125F, 0.0125F, 0.0125F, 0.0125F, 0.0125F,
  0.0125F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
  0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.006F, 0.006F, 0.006F,
  0.006F, 0.006F, 0.006F, 0.006F, 0.006F, 0.006F, 0.006F, 0.006F, 0.006F, 0.006F,
  0.006F, 0.006F, 0.006F, 0.006F, 0.00533333328F, 0.00533333328F, 0.00533333328F,
  0.00533333328F, 0.00533333328F, 0.00533333328F, 0.00533333328F, 0.00533333328F,
  0.00533333328F, 0.00533333328F, 0.00533333328F, 0.00533333328F, 0.00533333328F,
  0.00533333328F, 0.00533333328F, 0.00533333328F, 0.00533333328F, 0.005F, 0.005F,
  0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
  0.005F, 0.005F, 0.005F, 0.005F, 0.005F } ;
                                  /* Referenced by: '<S51>/1-D Lookup Table2' */

const volatile float32 ccdm_crsCtrlAccKp_X_VehSpdErr_kph[17] = { -20.0F, -15.0F,
  -10.0F, -5.0F, -4.0F, -3.0F, -2.0F, -1.0F, 0.0F, 1.0F, 2.0F, 3.0F, 4.0F, 5.0F,
  10.0F, 15.0F, 20.0F } ;         /* Referenced by: '<S51>/1-D Lookup Table1' */

const volatile float32 ccdm_crsCtrlAccKp_Y_VehSpdAct_kph[17] = { 0.0F, 10.0F,
  20.0F, 30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F, 110.0F, 120.0F,
  130.0F, 140.0F, 150.0F, 160.0F } ;
                                  /* Referenced by: '<S51>/1-D Lookup Table1' */

const volatile float32 ccdm_crsCtrlAccKp_Z_fact[289] = { 0.05F, 0.05F, 0.05F,
  0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F,
  0.05F, 0.05F, 0.05F, 0.0533333346F, 0.0533333346F, 0.0533333346F,
  0.0533333346F, 0.0533333346F, 0.0533333346F, 0.0533333346F, 0.0533333346F,
  0.0533333346F, 0.0533333346F, 0.0533333346F, 0.0533333346F, 0.0533333346F,
  0.0533333346F, 0.0533333346F, 0.0533333346F, 0.0533333346F, 0.06F, 0.06F,
  0.06F, 0.06F, 0.06F, 0.06F, 0.06F, 0.06F, 0.06F, 0.06F, 0.06F, 0.06F, 0.06F,
  0.06F, 0.06F, 0.06F, 0.06F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.125F, 0.125F, 0.125F,
  0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F,
  0.125F, 0.125F, 0.125F, 0.125F, 0.166666672F, 0.166666672F, 0.166666672F,
  0.166666672F, 0.166666672F, 0.166666672F, 0.166666672F, 0.166666672F,
  0.166666672F, 0.166666672F, 0.166666672F, 0.166666672F, 0.166666672F,
  0.166666672F, 0.166666672F, 0.166666672F, 0.166666672F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.166666672F,
  0.166666672F, 0.166666672F, 0.166666672F, 0.166666672F, 0.166666672F,
  0.166666672F, 0.166666672F, 0.166666672F, 0.166666672F, 0.166666672F,
  0.166666672F, 0.166666672F, 0.166666672F, 0.166666672F, 0.166666672F,
  0.166666672F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F,
  0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.125F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.06F, 0.06F, 0.06F, 0.06F, 0.06F, 0.06F, 0.06F, 0.06F,
  0.06F, 0.06F, 0.06F, 0.06F, 0.06F, 0.06F, 0.06F, 0.06F, 0.06F, 0.0533333346F,
  0.0533333346F, 0.0533333346F, 0.0533333346F, 0.0533333346F, 0.0533333346F,
  0.0533333346F, 0.0533333346F, 0.0533333346F, 0.0533333346F, 0.0533333346F,
  0.0533333346F, 0.0533333346F, 0.0533333346F, 0.0533333346F, 0.0533333346F,
  0.0533333346F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F,
  0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F } ;
                                  /* Referenced by: '<S51>/1-D Lookup Table1' */

const volatile float32 ccdm_crsCtrlTqKi_X_VehAccErr_mps2[17] = { -0.5F, -0.4F,
  -0.3F, -0.25F, -0.2F, -0.15F, -0.1F, -0.05F, 0.0F, 0.05F, 0.1F, 0.15F, 0.2F,
  0.25F, 0.3F, 0.4F, 0.5F } ;     /* Referenced by: '<S66>/1-D Lookup Table3' */

const volatile float32 ccdm_crsCtrlTqKi_Y_VehAccAct_mps2[9] = { -1.0F, -0.75F,
  -0.5F, -0.25F, 0.0F, 0.25F, 0.5F, 0.75F, 1.0F } ;
                                  /* Referenced by: '<S66>/1-D Lookup Table3' */

const volatile float32 ccdm_crsCtrlTqKi_Z_fact[153] = { 4000.0F, 4000.0F,
  4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F,
  4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F,
  4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F,
  4000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F,
  3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F,
  3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F,
  3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F,
  3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 2000.0F, 2000.0F, 2000.0F,
  2000.0F, 2000.0F, 2000.0F, 2000.0F, 2000.0F, 2000.0F, 2000.0F, 2000.0F,
  2000.0F, 2000.0F, 2000.0F, 2000.0F, 2000.0F, 2000.0F, 2000.0F, 2000.0F,
  2000.0F, 2000.0F, 2000.0F, 2000.0F, 2000.0F, 2000.0F, 2000.0F, 2000.0F,
  3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F,
  3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F,
  3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F,
  3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F, 3000.0F,
  3000.0F, 3000.0F, 3000.0F, 3000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F,
  4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F,
  4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F,
  4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F } ;
                                  /* Referenced by: '<S66>/1-D Lookup Table3' */

const volatile float32 ccdm_crsCtrlTqKp_X_VehAccErr_mps2[17] = { -0.5F, -0.4F,
  -0.3F, -0.25F, -0.2F, -0.15F, -0.1F, -0.05F, 0.0F, 0.05F, 0.1F, 0.15F, 0.2F,
  0.25F, 0.3F, 0.4F, 0.5F } ;     /* Referenced by: '<S66>/1-D Lookup Table1' */

const volatile float32 ccdm_crsCtrlTqKp_Y_VehAccAct_mps2[9] = { -1.0F, -0.75F,
  -0.5F, -0.25F, 0.0F, 0.25F, 0.5F, 0.75F, 1.0F } ;
                                  /* Referenced by: '<S66>/1-D Lookup Table1' */

const volatile float32 ccdm_crsCtrlTqKp_Z_fact[153] = { 400.0F, 400.0F, 400.0F,
  400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F,
  400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F,
  400.0F, 400.0F, 400.0F, 400.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F,
  300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F,
  300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F,
  300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F,
  200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F,
  200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F,
  200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 300.0F, 300.0F, 300.0F,
  300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F,
  300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F,
  300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F,
  300.0F, 300.0F, 300.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F,
  400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F,
  400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F
} ;                               /* Referenced by: '<S66>/1-D Lookup Table1' */

const volatile float32 ccdm_pedlPosVirt_Z_pct[120] = { 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 26.8928623F, 26.8928623F,
  26.8928623F, 26.8928623F, 26.8928623F, 29.821085F, 38.4721603F, 58.431282F,
  67.8411713F, 97.3981171F, 100.0F, 100.0F, 63.7857246F, 63.7857246F,
  63.7857246F, 63.7857246F, 63.7857246F, 69.6894379F, 93.8886337F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F } ;
                                   /* Referenced by: '<S5>/2-D Lookup Table4' */

/* Virtual accelerator Pedal position */
const volatile float32 cdtc_fact_whlSpdCtrlKd = 0.0F;/* Referenced by: '<S84>/Constant3' */

/* Creep Derivative term gain */
const volatile float32 ctdc_a_crpSlopeGradThr_mps2 = 0.01F;/* Referenced by: '<S114>/Constant' */
const volatile float32 ctdc_a_yrsLongAccAvgDnD_mps2 = 0.0F;/* Referenced by: '<S122>/Constant' */
const volatile float32 ctdc_a_yrsLongAccAvgDnR_mps2 = -0.4F;/* Referenced by: '<S124>/Constant' */
const volatile float32 ctdc_a_yrsLongAccAvgUpD_mps2 = 0.4F;/* Referenced by: '<S121>/Constant' */
const volatile float32 ctdc_a_yrsLongAccAvgUpR_mps2 = 0.0F;/* Referenced by: '<S123>/Constant' */
const volatile float32 ctdc_a_yrsLongAccDn_mps2 = -0.4F;/* Referenced by: '<S113>/Constant' */
const volatile float32 ctdc_a_yrsLongAccUp_mps2 = 0.4F;/* Referenced by: '<S112>/Constant' */
const volatile boolean ctdc_b_chkBrkPedlStsToEnaCrp = true;/* Referenced by: '<S83>/Constant3' */

/* Check brake pedal status to enable Creep */
const volatile boolean ctdc_b_chkPmmStsToEnaCrp = false;/* Referenced by: '<S83>/Constant6' */

/* Enable Creep if EPB is released */
const volatile boolean ctdc_b_enaCreepAftEPBRels = true;/* Referenced by: '<S83>/Constant2' */

/* Enable Creep if EPB is released */
const volatile boolean ctdc_b_enableCreep = true;/* Referenced by: '<S83>/Constant1' */

/* Enable Creep function */
const volatile boolean ctdc_b_slopeTrqOffsetEn = false;/* Referenced by: '<S86>/Constant1' */
const volatile float32 ctdc_dtq_CrpTqDisDecGrad_Nmps = -50000.0F;/* Referenced by: '<S3>/Constant5' */

/* Wheel Creep Target Torque decrease gradient when disabled */
const volatile float32 ctdc_dtq_CrpTqEnaIncGrad_Nmps = 50000.0F;/* Referenced by: '<S3>/Constant4' */

/* Wheel Creep Target Torque increase gradient when enabled */
const volatile float32 ctdc_fact_roadSlopeFilt = 0.3F;/* Referenced by: '<S86>/Constant2' */
const volatile float32 ctdc_tm_crpSlopeCalStepTm_ms = 100.0F;/* Referenced by: '<S116>/Constant1' */
const volatile float32 ctdc_tm_crpSlopeStopDly_s = 1.0F;/* Referenced by: '<S85>/Constant22' */
const volatile float32 ctdc_tm_whlSpdCtrlDerivTc_s = 0.02F;/* Referenced by: '<S84>/Constant1' */

/* Creep Derivative term time constant */
const volatile float32 ctdc_v_crpSlopeStopThr_kph = 1.0F;/* Referenced by: '<S115>/Constant' */
const volatile float32 ctdc_v_slopeTrqOffsetSpdDisa_kph = 5.0F;/* Referenced by: '<S125>/Constant' */
const volatile float32 ctdc_v_vehHiThrSafeDisCrp_kph = 11.0F;/* Referenced by: '<S83>/Relay' */

/* Vehicle speed high threshold for safe Creep disabling */
const volatile float32 ctdc_v_vehLoThrSafeDisCrp_kph = 9.0F;/* Referenced by: '<S83>/Relay' */

/* Vehicle speed low threshold for safe Creep disabling */
const volatile float32 ctdf_TgtTqKiMap_X_VehSpdErr_kph[6] = { -6.0F, -2.0F, 2.0F,
  4.0F, 8.0F, 10.0F } ;          /* Referenced by: '<S104>/1-D Lookup Table1' */

/* Creep Torque Demand Ki Map - Vehicle Speed Axis */
const volatile float32 ctdf_TgtTqKiMap_Y_Nm[6] = { 15.0F, 15.0F, 15.0F, 10.0F,
  10.0F, 10.0F } ;               /* Referenced by: '<S104>/1-D Lookup Table1' */

/* Creep Torque Demand Ki Map - Torque Demand */
const volatile float32 ctdf_TgtTqKpMap_X_VehSpdErr_kph[6] = { -6.0F, -2.0F, 2.0F,
  4.0F, 8.0F, 10.0F } ;           /* Referenced by: '<S104>/1-D Lookup Table' */

/* Creep Torque Demand Kp Map - Vehicle Speed Axis */
const volatile float32 ctdf_TgtTqKpMap_Y_Nm[6] = { 100.0F, 100.0F, 100.0F, 60.0F,
  60.0F, 60.0F } ;                /* Referenced by: '<S104>/1-D Lookup Table' */

/* Creep Torque Demand Kp Map - Torque Demand */
const volatile float32 ctdf_crpTgtTqFFMap_X_RoadSlope_deg[9] = { -0.4F, -0.3F,
  -0.2F, -0.1F, 0.0F, 0.1F, 0.2F, 0.3F, 0.4F } ;
                                  /* Referenced by: '<S84>/1-D Lookup Table2' */

/* Creep Torque Demand FeedForward Map - Road Slope Axis */
const volatile float32 ctdf_crpTgtTqFFMap_Y_Nm[9] = { 3528.0F, 2646.0F, 1764.0F,
  882.0F, 0.0F, 882.0F, 1764.0F, 2646.0F, 3528.0F } ;
                                  /* Referenced by: '<S84>/1-D Lookup Table2' */

/* Creep Torque Demand FeedForward Map - Torque Demand */
const volatile float32 ctdf_slopeTrqOffsetFact_X_VehSpd_kph[7] = { 0.0F, 1.0F,
  2.0F, 3.0F, 4.0F, 5.0F, 6.0F } ;/* Referenced by: '<S84>/1-D Lookup Table3' */

const volatile float32 ctdf_slopeTrqOffsetFact_Y[7] = { 1.2F, 1.1F, 1.0F, 1.0F,
  0.9F, 0.8F, 0.0F } ;            /* Referenced by: '<S84>/1-D Lookup Table3' */

const volatile float32 ctdf_slopeTrqOffsetRFact_X_VehSpd_kph[7] = { 0.0F, 0.5F,
  1.0F, 1.5F, 2.0F, 2.5F, 3.0F } ;/* Referenced by: '<S84>/1-D Lookup Table4' */

const volatile float32 ctdf_slopeTrqOffsetRFact_Y[7] = { 1.2F, 1.1F, 1.0F, 1.0F,
  0.9F, 0.8F, 0.0F } ;            /* Referenced by: '<S84>/1-D Lookup Table4' */

const volatile float32 ctdf_whlTqMaxMap_X_VehSpd_kph[4] = { 0.0F, 5.0F, 10.0F,
  15.0F } ;                       /* Referenced by: '<S84>/1-D Lookup Table1' */

/* Creep Max Torque Map - Vehicle Speed Axis */
const volatile float32 ctdf_whlTqMaxMap_Y_Nm[4] = { 2000.0F, 2000.0F, 0.0F, 0.0F
} ;                               /* Referenced by: '<S84>/1-D Lookup Table1' */

/* Creep Max Torque Map - Torque Limit */
const volatile float32 swcscoo_ctda_CrpTgtSpd_X_brkPedlPos_pct[8] = { 0.0F, 2.0F,
  4.0F, 8.0F, 10.0F, 15.0F, 20.0F, 30.0F } ;/* Referenced by:
                                             * '<S103>/1-D Lookup Table1'
                                             * '<S103>/1-D Lookup Table2'
                                             */

/* Creep Target Speed Map - Brake Pedal Position Axis */
const volatile float32 swcscoo_ctdf_CrpTgtFwdSpdMap_Y_kph[8] = { 7.0F, 7.0F,
  6.0F, 5.0F, 4.0F, 2.0F, 0.0F, 0.0F } ;
                                 /* Referenced by: '<S103>/1-D Lookup Table2' */

/* Creep Target Speed Map - Forward Target Speed */
const volatile float32 swcscoo_ctdf_CrpTgtRevSpdMap_Y_kph[8] = { 5.0F, 5.0F,
  5.0F, 5.0F, 4.0F, 2.0F, 0.0F, 0.0F } ;
                                 /* Referenced by: '<S103>/1-D Lookup Table1' */

/* Creep Target Speed Map - Reverse Target Speed */
const volatile float32 vsla_SpdLimCtrl_X_VehSpd_kph[11] = { 0.0F, 20.0F, 40.0F,
  60.0F, 80.0F, 100.0F, 120.0F, 140.0F, 160.0F, 180.0F, 200.0F } ;/* Referenced by:
                                                                   * '<S140>/2-D Lookup Table'
                                                                   * '<S140>/2-D Lookup Table1'
                                                                   */

/* Vehicle speed limit control - vehicle speed axis */
const volatile float32 vsla_SpdLimCtrl_Y_VehSpdErr_kph[11] = { -25.0F, -20.0F,
  -15.0F, -10.0F, -5.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F } ;/* Referenced by:
                                                                    * '<S140>/2-D Lookup Table'
                                                                    * '<S140>/2-D Lookup Table1'
                                                                    */

/* Vehicle speed limit control - vehicle speed error axis */
const volatile boolean vslc_b_brkMismatchActvLvl = true;/* Referenced by: '<S83>/Constant4' */

/* Brake mismatch signal active level */
const volatile boolean vslc_b_chkHhcStsToEnaCrp = true;/* Referenced by: '<S83>/Constant' */

/* Enable Creep if HHC is released */
const volatile boolean vslc_b_enaVehSpdLimr = true;/* Referenced by: '<S133>/Constant2' */

/* Enable Vehicle Speed Limiter */
const volatile boolean vslc_b_rmtCtrlSpdLmtEn = false;/* Referenced by: '<S145>/Constant7' */

/* remote limit speed Enable */
const volatile float32 vslc_v_vehMaxSpd = 100.0F;/* Referenced by: '<S138>/Constant8' */

/* Vehicle Speed limit  */
const volatile float32 vslc_v_vehMaxSpdFwdEco_kph = 82.0F;/* Referenced by: '<S146>/Constant20' */

/* Max Speed limit for Forward drive in Eco mode */
const volatile float32 vslc_v_vehMaxSpdFwdNorm_kph = 102.0F;/* Referenced by: '<S146>/Constant22' */

/* Max Speed limit for Forward drive in Norm mode */
const volatile float32 vslc_v_vehMaxSpdFwdPwr_kph = 122.0F;/* Referenced by: '<S146>/Constant21' */

/* Max Speed limit for Forward drive in Power mode */
const volatile float32 vslc_v_vehMaxSpdLimpHome1_kph = 65.0F;/* Referenced by: '<S145>/Constant1' */

/* Vehicle Speed limit for limp-home level 1 */
const volatile float32 vslc_v_vehMaxSpdLimpHome2_kph = 10.0F;/* Referenced by: '<S145>/Constant4' */

/* Vehicle Speed limit for limp-home level 2 */
const volatile float32 vslc_v_vehMaxSpdRvsDrv1_kph = 45.0F;/* Referenced by: '<S146>/Constant1' */

/* Max Speed limit for Reverse drive */
const volatile float32 vslc_v_vehMaxSpdRvsDrv_kph = 25.0F;/* Referenced by: '<S146>/Constant2' */

/* Max Speed limit for Reverse drive */
const volatile float32 vslc_v_vehMaxSpderr = 2.0F;/* Referenced by:
                                                   * '<S4>/Constant1'
                                                   * '<S138>/Constant1'
                                                   */

/* Vehicle Speed limit err  */
const volatile float32 vslc_v_vehSpdErrCtrlCfgHi_kph = 5.0F;/* Referenced by: '<S133>/Relay2' */

/* Vehicle Speed error to disable the integral control */
const volatile float32 vslc_v_vehSpdErrCtrlCfgLo_kph = 2.0F;/* Referenced by: '<S133>/Relay2' */

/* Vehicle Speed error to enable the integral control */
const volatile float32 vslc_v_vehSpdErrCtrlEnagHi_kph = 5.0F;/* Referenced by: '<S133>/Relay1' */

/* Vehicle Speed error to disable the VSL control */
const volatile float32 vslc_v_vehSpdErrCtrlEnagLo_kph = 2.0F;/* Referenced by: '<S133>/Relay1' */

/* Vehicle Speed error to enable the VSL control */
const volatile float32 vslc_v_vehSpdErrIntglEnagHi_kph = 5.0F;/* Referenced by: '<S133>/Relay4' */

/* Vehicle Speed error to disable the integral control */
const volatile float32 vslc_v_vehSpdErrIntglEnagLo_kph = 2.0F;/* Referenced by: '<S133>/Relay4' */

/* Vehicle Speed error to enable the integral control */
const volatile float32 vslm_SpdLimCtrlKi_Z_fact[121] = { 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F } ;
                                 /* Referenced by: '<S140>/2-D Lookup Table1' */

/* Vehicle speed limit control - Ki (integral) Map */
const volatile float32 vslm_SpdLimCtrlKp_Z_fact[121] = { 400.0F, 400.0F, 400.0F,
  400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F,
  400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F,
  400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F,
  400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F,
  400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F,
  400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F,
  400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F,
  400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F,
  400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F,
  400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F,
  400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F,
  400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F } ;
                                  /* Referenced by: '<S140>/2-D Lookup Table' */

/* Vehicle speed limit control - Kp (proportional) Map */
#define swc_SCOO_STOP_SEC_CONST_VOLATILE
#include "swc_SCOO_MemMap.h"
#define swc_SCOO_START_SEC_VAR
#include "swc_SCOO_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_SIG */
float32 ccdd_acc_intAccTgt_mps2;       /* '<S55>/Switch' */
float32 ccdd_acc_vehAccActRaw_mps2;    /* '<S65>/Divide' */
float32 ccdd_acc_vehAccAct_mps2;       /* '<S68>/Data Type Conversion3' */
float32 ccdd_acc_vehAccErr_mps2;       /* '<S66>/Add1' */
float32 ccdd_acc_vehAccSP_mps2;        /* '<S60>/Divide1' */
float32 ccdd_acc_vehAccTgtIntgl_mps2;  /* '<S58>/Product' */
float32 ccdd_acc_vehAccTgtLong_mps2;   /* '<S61>/Data Type Conversion' */
float32 ccdd_acc_vehAccTgtProp_mps2;   /* '<S57>/Switch1' */
float32 ccdd_acc_vehAccTgt_mps2;       /* '<S50>/Data Type Conversion' */
boolean ccdd_b_accCtrlActv;            /* '<S47>/Logical Operator3' */
boolean ccdd_b_crsAccelResBtnPrsd;     /* '<S11>/Chart' */

/* Button Accel Flag */
boolean ccdd_b_crsCnclBtnPrsd;         /* '<S15>/FixPt Relational Operator' */

/* Button Cancel Flag (Main Cruise Long Press) */
boolean ccdd_b_crsCoastSetBtnPrsd;     /* '<S13>/Chart' */

/* Button Coast Flag */
boolean ccdd_b_crsCtrlAccKiEna;        /* '<S51>/Switch' */
boolean ccdd_b_crsCtrlAccPedlOvrd;     /* '<S5>/Logical Operator' */

/* Cruise Control Request Overrides Accelerator Pedal */
boolean ccdd_b_crsCtrlTqKiEna;         /* '<S66>/Logical Operator' */
boolean ccdd_b_crsEna;                 /* '<S22>/Switch2' */

/* Cruise enable flag */
boolean ccdd_b_crsEnaRaw;              /* '<S22>/Logical Operator2' */

/* Cruise enable flag */
boolean ccdd_b_crsMainBtnPrsd;         /* '<S14>/FixPt Relational Operator' */

/* Button Cruise Flag */
boolean ccdd_b_crsSpdCtrlEnad;         /* '<S35>/Logical Operator' */

/* VSL enabled */
boolean ccdd_b_crsSpdCtrlIntglEnad;    /* '<S35>/Logical Operator1' */

/* VSL integral enabled */
boolean ccdd_b_vehAccTgtLongActv;      /* '<S62>/timed_delay' */
CrsBtnErrSts ccdd_e_crsBtnErrSts;      /* '<S6>/Button_Sts' */

/* Cruise Button Error Status */
CrsBtnSts ccdd_e_crsBtnSts;            /* '<S6>/Button_Sts' */

/* Cruise Button Status */
CrModeMngr_e ccdd_e_crsCtrlSpdMode;    /* '<S7>/CruiseStates' */

/* Cruise Control Speed Mode Status */
CruiseSts_e ccdd_e_crsCtrlSts;         /* '<S7>/CruiseStates' */

/* Cruise Control Mode Status */
float32 ccdd_fact_crsCtrlAccKi;        /* '<S51>/1-D Lookup Table2' */
float32 ccdd_fact_crsCtrlAccKp;        /* '<S51>/1-D Lookup Table1' */
float32 ccdd_fact_crsCtrlTqKi;         /* '<S66>/1-D Lookup Table3' */
float32 ccdd_fact_crsCtrlTqKp;         /* '<S66>/1-D Lookup Table1' */
float32 ccdd_fact_crsSpdCtrlKi;        /* '<S76>/1-D Lookup Table1' */

/* Vehicle Speed closed loop control proportional factor Ki */
float32 ccdd_fact_crsSpdCtrlKp;        /* '<S76>/1-D Lookup Table2' */

/* Vehicle Speed closed loop control proportional factor Kp */
float32 ccdd_tq_crsCtrlTqFF_Nm;        /* '<S66>/Add' */
float32 ccdd_tq_crsSpdCtrlFF_Nm;       /* '<S76>/1-D Lookup Table' */

/* Vehicle Speed closed loop control feedforward term */
float32 ccdd_tq_whlDemRawAdvIntgl_Nm;  /* '<S74>/Product' */
float32 ccdd_tq_whlDemRawAdvProp_Nm;   /* '<S73>/Switch1' */
float32 ccdd_tq_whlDemRawAdv_Nm;       /* '<S71>/Switch' */
float32 ccdd_tq_whlDemRawBase_Nm;      /* '<S78>/Switch' */
float32 ccdd_tq_whlDemRaw_Nm;          /* '<S37>/Switch3' */
float32 ccdd_tq_whlDem_Nm;             /* '<S34>/Switch1' */

/* Cruise Control Torque Demand */
float32 ccdd_v_crsCtrlTgtSpd_kph;      /* '<S7>/CruiseStates' */

/* Cruise Control Target Speed */
float32 ccdd_v_crsTgtSpdQuit_kph;      /* '<S7>/CruiseStates' */

/* Last Cruise Control Active Target Speed */
float32 ccdd_v_vehSpdErr_kph;          /* '<S51>/Add' */
float32 ccdd_x_accPedlPosVirtRaw_pct;  /* '<S5>/2-D Lookup Table4' */

/* Virtual accelerator Pedal position raw value */
float32 ccdd_x_accPedlPosVirt_pct;     /* '<S5>/Switch1' */

/* Virtual accelerator Pedal position */
float32 ctdd_a_yrsLongAccAvgVld_mps2;  /* '<S120>/Data Type Conversion3' */
float32 ctdd_a_yrsLongAccAvg_mps2;     /* '<S111>/Mean' */
float32 ctdd_a_yrsLongAccSgm_mps2;     /* '<S111>/Standard Deviation' */
float32 ctdd_a_yrsLongAcc_mps2;        /* '<S85>/Switch' */
boolean ctdd_b_CreepEnabled;           /* '<S83>/Logical Operator' */

/* Creep Enabled */
boolean ctdd_b_crpSlopeStopStd;        /* '<S117>/timed_delay' */
boolean ctdd_b_crpSlopeTrqOffsetEn;    /* '<S85>/Logical Operator1' */
boolean ctdd_b_crpSlopeTrqOffsetEnHld; /* '<S129>/Logical Operator3' */
boolean ctdd_b_eCreepReq;              /* '<S83>/Logical Operator3' */

/* Request eCreep Mode */
float32 ctdd_fact_CrpTgtTqCtlKi;       /* '<S104>/1-D Lookup Table1' */

/* Creep target torque control Ki */
float32 ctdd_fact_CrpTgtTqCtlKp;       /* '<S104>/1-D Lookup Table' */

/* Creep target torque control Kp */
float32 ctdd_n_vehTgtCrpSpdFwd_kph;    /* '<S103>/MinMax1' */

/* Creep Forward target speed */
float32 ctdd_tq_whlDemRaw_Nm;          /* '<S105>/Switch' */

/* Creep Torque Demand Raw */
float32 ctdd_tq_whlDem_Nm;             /* '<S130>/Chart' */

/* Creep Torque Demand */
float32 ctdd_v_vehCrpTgt_kph;          /* '<S103>/MinMax4' */

/* Creep target speed */
boolean vsld_b_vehSpdLimrEnad;         /* '<S133>/Logical Operator' */

/* VSL enabled */
boolean vsld_b_vehSpdLimrIntglEnad;    /* '<S133>/Logical Operator1' */

/* VSL integral enabled */
boolean vsld_b_vslTqIntvReq;           /* '<S4>/Signal Conversion5' */

/* VSL Torque Intervention request */
float32 vsld_fact_vehSpdLimCtrlKi;     /* '<S140>/2-D Lookup Table1' */

/* Vehicle Speed closed loop control proportional factor Ki */
float32 vsld_fact_vehSpdLimCtrlKp;     /* '<S140>/2-D Lookup Table' */

/* Vehicle Speed closed loop control proportional factor Kp */
float32 vsld_tq_whlMaxTqLimFast_Nm;    /* '<S136>/Switch1' */

/* VSL Max Fast Torque Limit */
float32 vsld_tq_whlMaxTqLimSlow_Nm;    /* '<S136>/Switch' */

/* VSL Max Slow Torque Limit */
float32 vsld_tq_whlMaxTqLim_Nm;        /* '<S142>/Switch' */

/* VSL Max Wheel Torque Limit */
float32 vsld_v_vehMaxAllwdSpd_kph;     /* '<S146>/Switch' */

/* Vehicle max allowed speed */
float32 vsld_v_vehMaxCfgSpd_kph;       /* '<S146>/Switch2' */

/* Vehicle max speed */
float32 vsld_v_vehMaxSpdLimpHome_kph;  /* '<S145>/MinMax3' */

/* Vehicle max speed for LimpHome Mode */
float32 vsld_v_vehMaxSpd_kph;          /* '<S138>/MinMax1' */

/* Vehicle max speed */
#define swc_SCOO_STOP_SEC_VAR
#include "swc_SCOO_MemMap.h"

/* Invariant block signals (default storage) */
const ConstB_swc_SCOO_T swc_SCOO_ConstB = {
  0.0F,                                /* '<S1>/Constant' */
  0,                                   /* '<S102>/Logical Operator2' */
  1,                                   /* '<S22>/Logical Operator1' */
  1                                    /* '<S51>/Logical Operator1' */
};

/* Constant parameters (default storage) */
const ConstP_swc_SCOO_T swc_SCOO_ConstP = {
  /* Computed Parameter: uDLookupTable4_maxIndex
   * Referenced by: '<S5>/2-D Lookup Table4'
   */
  { 11U, 9U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S51>/1-D Lookup Table1'
   *   '<S51>/1-D Lookup Table2'
   */
  { 16U, 16U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S66>/1-D Lookup Table1'
   *   '<S66>/1-D Lookup Table3'
   */
  { 8U, 16U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S140>/2-D Lookup Table'
   *   '<S140>/2-D Lookup Table1'
   */
  { 10U, 10U }
};

/* PublicStructure Variables for Internal Data */
ARID_DEF_swc_SCOO_T swc_SCOO_ARID_DEF;
static float32 look1_iflf_binlcapw(float32 u0, const float32 bp0[], const
  float32 table[], uint32 maxIndex);
static float32 look2_iflf_binlcapw(float32 u0, float32 u1, const float32 bp0[],
  const float32 bp1[], const float32 table[], const uint32 maxIndex[], uint32
  stride);
static void swc_SCOO_turnON_delay_Init(boolean *rty_flg_out);
static void swc_SCOO_turnON_delay(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnON_delay_swc_SCO_T
  *swc_SCOO__ARID_DEF_arg);
static void swc_SCOO_pos(float32 rtu_in_val, float32 *rty_same_val);
static void swc_SCOO_neg(float32 rtu_in_val, float32 *rty_neg_val);
static void swc_SCOO_switch_ramp_Init(float32 *rty_y, boolean *rty_RampOn);
static void swc_SCOO_switch_ramp(float32 rtu_u1, boolean rtu_sw, float32 rtu_u2,
  float32 rtu_up, float32 rtu_lo, float32 *rty_y, boolean *rty_RampOn,
  ARID_DEF_switch_ramp_swc_SCOO_T *swc_SCOO__ARID_DEF_arg);
static void swc_SCO_determine_creep_vel_tgt(DriveDir rtu_drid_e_driveDirSel,
  float32 rtu_brpd_x_brkPedlPos_pct, float32 rtu_vsld_v_rmtCtrlFctSpdLim_kph);
static void swc_SCOO_determine_pi_factors(float32 rtu_VehSpdErr);
static void swc_SCOO_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_SCOO_T *swc_SCOO__ARID_DEF_arg);
static void swc__SwitchRampCreepTrqDem_Init(boolean *rty_RampOn);
static void swc_SCOO_SwitchRampCreepTrqDem(float32 rtu_u1, boolean rtu_sw,
  float32 rtu_u2, float32 rtu_up, float32 rtu_lo, boolean *rty_RampOn,
  ARID_DEF_switch_ramp_swc_SC_n_T *swc_SCOO__ARID_DEF_arg);
static void swc_SCOO_PID_FeedForward_Init(void);
static void swc_SCOO_PID_FeedForward(void);
static void swc_SCOO_PID_FeedForward_c_Init(void);
static void swc_SCOO_PID_FeedForward_e(void);
static void swc_SCOO_PID_FeedForward_i_Init(void);
static void swc_SCOO_PID_FeedForward_d(void);
static void sw_CCD_CruiseControlDemand_Init(void);
static void swc_SCO_CCD_CruiseControlDemand(void);
static void swc_SCOO_PID_FeedForward_g_Init(void);
static void swc_SCOO_PID_FeedForward_f(void);
static void swc_SCOO_CTD_CreepDemand_Init(void);
static void swc_SCOO_CTD_CreepDemand(void);
static void swc_SCOO_PI_adjustable(void);
static void s_VehicleSpeedClosedLoopControl(void);
static void swc_SCO_VSL_VehicleSpeedLimiter(void);

/* Forward declaration for local functions */
static void swc_SCOO_Coast_Sts(void);
static void swc_SCOO_Cruise_Sts(void);
static void swc_SCOO_Default_Sts(void);
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

/*
 * System initialize for atomic system:
 *    '<S6>/turnON_delay'
 *    '<S22>/turnON_delay'
 */
static void swc_SCOO_turnON_delay_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S16>/timed_delay' */
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S6>/turnON_delay'
 *    '<S22>/turnON_delay'
 */
static void swc_SCOO_turnON_delay(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnON_delay_swc_SCO_T
  *swc_SCOO__ARID_DEF_arg)
{
  float32 rtb_t_delay_on_f;

  /* Saturate: '<S16>/Saturation' */
  if (rtu_t_delay_on > 1.6777216E+7F) {
    /* Saturate: '<S16>/Saturation' */
    rtb_t_delay_on_f = 1.6777216E+7F;
  } else if (rtu_t_delay_on < 0.0F) {
    /* Saturate: '<S16>/Saturation' */
    rtb_t_delay_on_f = 0.0F;
  } else {
    /* Saturate: '<S16>/Saturation' */
    rtb_t_delay_on_f = rtu_t_delay_on;
  }

  /* End of Saturate: '<S16>/Saturation' */

  /* Chart: '<S16>/timed_delay' incorporates:
   *  DataTypeConversion: '<S16>/Data Type Conversion'
   */
  if (swc_SCOO__ARID_DEF_arg->is_active_c14_Ricardo_SW_dev_li == 0U) {
    swc_SCOO__ARID_DEF_arg->is_active_c14_Ricardo_SW_dev_li = 1U;
    if (rtu_flg_in) {
      swc_SCOO__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_SCOO_IN_ON;
      *rty_flg_out = true;
    } else {
      swc_SCOO__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_SCOO_IN_OFF;
      *rty_flg_out = false;
    }
  } else {
    switch (swc_SCOO__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib) {
     case swc_SCOO_IN_OFF:
      if (rtu_flg_in) {
        if (rtb_t_delay_on_f == 0.0F) {
          swc_SCOO__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_SCOO_IN_ON;
          *rty_flg_out = true;
        } else {
          swc_SCOO__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib =
            swc_SCOO_IN_ON_WAIT;
          swc_SCOO__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = false;
        }
      } else {
        *rty_flg_out = false;
      }
      break;

     case swc_SCOO_IN_ON:
      if (!rtu_flg_in) {
        swc_SCOO__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_SCOO_IN_OFF;
        *rty_flg_out = false;
      } else {
        *rty_flg_out = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtu_flg_in) {
        swc_SCOO__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_SCOO_IN_OFF;
        *rty_flg_out = false;
      } else if (swc_SCOO__ARID_DEF_arg->t_wait > rtb_t_delay_on_f - rtu_t_step)
      {
        swc_SCOO__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_SCOO_IN_ON;
        *rty_flg_out = true;
      } else {
        swc_SCOO__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = false;
      }
      break;
    }
  }

  /* End of Chart: '<S16>/timed_delay' */
}

/*
 * Output and update for action system:
 *    '<S29>/pos'
 *    '<S40>/pos'
 */
static void swc_SCOO_pos(float32 rtu_in_val, float32 *rty_same_val)
{
  /* SignalConversion generated from: '<S32>/in_val' */
  *rty_same_val = rtu_in_val;
}

/*
 * Output and update for action system:
 *    '<S29>/neg'
 *    '<S40>/neg'
 */
static void swc_SCOO_neg(float32 rtu_in_val, float32 *rty_neg_val)
{
  /* UnaryMinus: '<S31>/Unary Minus' */
  *rty_neg_val = -rtu_in_val;
}

/* System initialize for atomic system: '<S8>/SwitchRampCreepTrqDem' */
static void swc_SCOO_switch_ramp_Init(float32 *rty_y, boolean *rty_RampOn)
{
  /* SystemInitialize for Chart: '<S43>/Chart' */
  *rty_y = 0.0F;
  *rty_RampOn = false;
}

/* Output and update for atomic system: '<S8>/SwitchRampCreepTrqDem' */
static void swc_SCOO_switch_ramp(float32 rtu_u1, boolean rtu_sw, float32 rtu_u2,
  float32 rtu_up, float32 rtu_lo, float32 *rty_y, boolean *rty_RampOn,
  ARID_DEF_switch_ramp_swc_SCOO_T *swc_SCOO__ARID_DEF_arg)
{
  float32 rtb_MinMax1_m;
  float32 rtb_MinMax_l;

  /* MinMax: '<S36>/MinMax' incorporates:
   *  Constant: '<S36>/Constant1'
   *  Constant: '<S36>/Constant2'
   *  Product: '<S36>/Product'
   */
  rtb_MinMax_l = fmaxf(rtu_up * 0.01F, 0.0F);

  /* MinMax: '<S36>/MinMax1' incorporates:
   *  Constant: '<S36>/Constant1'
   *  Constant: '<S36>/Constant2'
   *  Product: '<S36>/Product1'
   */
  rtb_MinMax1_m = fminf(0.0F, 0.01F * rtu_lo);

  /* Chart: '<S43>/Chart' */
  if (swc_SCOO__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li == 0U) {
    swc_SCOO__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li = 1U;
    swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCOO_IN_U2;
    *rty_RampOn = false;
    *rty_y = rtu_u2;
  } else {
    switch (swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib) {
     case swc_SCOO_IN_U1:
      *rty_RampOn = false;
      if (!rtu_sw) {
        if (rtu_u2 >= rtu_u1) {
          swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCOO_IN_U1_TO_U2;
          swc_SCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_SCOO_IN_U1_TO_U2_INC;
          *rty_RampOn = true;
          *rty_y = fminf(fmaxf(fminf(rtu_u2 - *rty_y, rtb_MinMax_l) + *rty_y,
                               rtu_u1), rtu_u2);
        } else {
          swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCOO_IN_U1_TO_U2;
          swc_SCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_SCOO_IN_U1_TO_U2_DEC;
          *rty_RampOn = true;
          *rty_y = fmaxf(fminf(fmaxf(rtu_u2 - *rty_y, rtb_MinMax1_m) + *rty_y,
                               rtu_u1), rtu_u2);
        }
      } else {
        *rty_y = rtu_u1;
      }
      break;

     case swc_SCOO_IN_U1_TO_U2:
      {
        if (rtu_sw) {
          if (rtu_u1 >= rtu_u2) {
            swc_SCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_SCOO_IN_NO_ACTIVE_CHILD;
            swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_SCOO_IN_U2_TO_U1;
            swc_SCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_SCOO_IN_U2_TO_U1_INC;
            *rty_RampOn = true;
            *rty_y = fminf(fmaxf(fminf(rtu_u1 - *rty_y, rtb_MinMax_l) + *rty_y,
                                 rtu_u2), rtu_u1);
          } else {
            swc_SCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_SCOO_IN_NO_ACTIVE_CHILD;
            swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_SCOO_IN_U2_TO_U1;
            swc_SCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_SCOO_IN_U2_TO_U1_DEC;
            *rty_RampOn = true;
            *rty_y = fmaxf(fminf(fmaxf(rtu_u1 - *rty_y, rtb_MinMax1_m) + *rty_y,
                                 rtu_u2), rtu_u1);
          }
        } else if (swc_SCOO__ARID_DEF_arg->is_U1_TO_U2 ==
                   swc_SCOO_IN_U1_TO_U2_DEC) {
          float32 tmp;
          *rty_RampOn = true;
          tmp = rtu_u2 - *rty_y;
          if (tmp >= rtb_MinMax1_m) {
            swc_SCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_SCOO_IN_NO_ACTIVE_CHILD;
            swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCOO_IN_U2;
            *rty_RampOn = false;
            *rty_y = rtu_u2;
          } else {
            *rty_y = fmaxf(fminf(fmaxf(tmp, rtb_MinMax1_m) + *rty_y, rtu_u1),
                           rtu_u2);
          }
        } else {
          float32 tmp;

          /* case IN_U1_TO_U2_INC: */
          *rty_RampOn = true;
          tmp = rtu_u2 - *rty_y;
          if (tmp <= rtb_MinMax_l) {
            swc_SCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_SCOO_IN_NO_ACTIVE_CHILD;
            swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCOO_IN_U2;
            *rty_RampOn = false;
            *rty_y = rtu_u2;
          } else {
            *rty_y = fminf(fmaxf(fminf(tmp, rtb_MinMax_l) + *rty_y, rtu_u1),
                           rtu_u2);
          }
        }
      }
      break;

     case swc_SCOO_IN_U2:
      *rty_RampOn = false;
      if (rtu_sw) {
        if (rtu_u1 >= rtu_u2) {
          swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCOO_IN_U2_TO_U1;
          swc_SCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_SCOO_IN_U2_TO_U1_INC;
          *rty_RampOn = true;
          *rty_y = fminf(fmaxf(fminf(rtu_u1 - *rty_y, rtb_MinMax_l) + *rty_y,
                               rtu_u2), rtu_u1);
        } else {
          swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCOO_IN_U2_TO_U1;
          swc_SCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_SCOO_IN_U2_TO_U1_DEC;
          *rty_RampOn = true;
          *rty_y = fmaxf(fminf(fmaxf(rtu_u1 - *rty_y, rtb_MinMax1_m) + *rty_y,
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
            swc_SCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_SCOO_IN_NO_ACTIVE_CHILD;
            swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_SCOO_IN_U1_TO_U2;
            swc_SCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_SCOO_IN_U1_TO_U2_INC;
            *rty_RampOn = true;
            *rty_y = fminf(fmaxf(fminf(rtu_u2 - *rty_y, rtb_MinMax_l) + *rty_y,
                                 rtu_u1), rtu_u2);
          } else {
            swc_SCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_SCOO_IN_NO_ACTIVE_CHILD;
            swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_SCOO_IN_U1_TO_U2;
            swc_SCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_SCOO_IN_U1_TO_U2_DEC;
            *rty_RampOn = true;
            *rty_y = fmaxf(fminf(fmaxf(rtu_u2 - *rty_y, rtb_MinMax1_m) + *rty_y,
                                 rtu_u1), rtu_u2);
          }
        } else if (swc_SCOO__ARID_DEF_arg->is_U2_TO_U1 ==
                   swc_SCOO_IN_U2_TO_U1_DEC) {
          float32 tmp;
          *rty_RampOn = true;
          tmp = rtu_u1 - *rty_y;
          if (tmp >= rtb_MinMax1_m) {
            swc_SCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_SCOO_IN_NO_ACTIVE_CHILD;
            swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCOO_IN_U1;
            *rty_RampOn = false;
            *rty_y = rtu_u1;
          } else {
            *rty_y = fmaxf(fminf(fmaxf(tmp, rtb_MinMax1_m) + *rty_y, rtu_u2),
                           rtu_u1);
          }
        } else {
          float32 tmp;

          /* case IN_U2_TO_U1_INC: */
          *rty_RampOn = true;
          tmp = rtu_u1 - *rty_y;
          if (tmp <= rtb_MinMax_l) {
            swc_SCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_SCOO_IN_NO_ACTIVE_CHILD;
            swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCOO_IN_U1;
            *rty_RampOn = false;
            *rty_y = rtu_u1;
          } else {
            *rty_y = fminf(fmaxf(fminf(tmp, rtb_MinMax_l) + *rty_y, rtu_u2),
                           rtu_u1);
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<S43>/Chart' */
}

/* System initialize for atomic system: '<S48>/PID_FeedForward' */
static void swc_SCOO_PID_FeedForward_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S59>/init' */
  swc_SCOO_ARID_DEF.init_DSTATE_hd = true;
}

/* Output and update for atomic system: '<S48>/PID_FeedForward' */
static void swc_SCOO_PID_FeedForward(void)
{
  float32 rtb_Divide;
  float32 rtb_error;
  boolean rtb_AboveMax;
  boolean rtb_BelowMin;

  /* Sum: '<S52>/Sum' */
  rtb_error = ccdd_v_crsCtrlTgtSpd_kph - swc_SCOO_ARID_DEF.DataTypeConversion5;

  /* Product: '<S58>/Product' */
  ccdd_acc_vehAccTgtIntgl_mps2 = rtb_error * ccdd_fact_crsCtrlAccKp;

  /* Switch: '<S59>/Switch' incorporates:
   *  UnitDelay: '<S59>/init'
   */
  if (swc_SCOO_ARID_DEF.init_DSTATE_hd) {
    /* Switch: '<S59>/Switch' incorporates:
     *  DataTypeConversion: '<S59>/Data Type Conversion'
     */
    rtb_Divide = rtb_error;
  } else {
    /* Product: '<S59>/Divide' incorporates:
     *  Constant: '<S48>/Constant5'
     *  Constant: '<S48>/Constant7'
     *  DataTypeConversion: '<S59>/Data Type Conversion1'
     *  DataTypeConversion: '<S59>/Data Type Conversion2'
     *  Sum: '<S59>/Add1'
     */
    rtb_Divide = 1.0F / (1.0F + ((float32)CCD_TASK_INTERVAL_S));

    /* Switch: '<S59>/Switch' incorporates:
     *  Constant: '<S59>/Constant'
     *  DataTypeConversion: '<S59>/Data Type Conversion'
     *  Product: '<S59>/Product'
     *  Product: '<S59>/Product1'
     *  Sum: '<S59>/Add'
     *  Sum: '<S59>/Add2'
     *  UnitDelay: '<S59>/Unit Delay'
     */
    rtb_Divide = (1.0F - rtb_Divide) * rtb_error + rtb_Divide *
      swc_SCOO_ARID_DEF.UnitDelay_DSTATE_m;
  }

  /* End of Switch: '<S59>/Switch' */

  /* Switch: '<S57>/Switch1' incorporates:
   *  Constant: '<S48>/Constant6'
   *  Logic: '<S52>/Logical Operator1'
   *  Logic: '<S52>/Logical Operator2'
   *  Switch: '<S57>/Switch'
   *  UnitDelay: '<S52>/ClippedPrev'
   */
  if (swc_SCOO_ARID_DEF.LogicalOperator_l) {
    /* Switch: '<S57>/Switch1' incorporates:
     *  Constant: '<S57>/Constant'
     */
    ccdd_acc_vehAccTgtProp_mps2 = 0.0F;
  } else {
    float32 tmp;
    if ((!false) || swc_SCOO_ARID_DEF.ClippedPrev_DSTATE_g) {
      /* Switch: '<S57>/Switch' incorporates:
       *  Constant: '<S57>/Constant'
       */
      tmp = 0.0F;
    } else {
      /* Switch: '<S57>/Switch' incorporates:
       *  Constant: '<S48>/Constant5'
       *  Product: '<S57>/Product2'
       */
      tmp = rtb_error * ccdd_fact_crsCtrlAccKi * ((float32)CCD_TASK_INTERVAL_S);
    }

    /* Switch: '<S57>/Switch1' incorporates:
     *  Sum: '<S57>/Sum1'
     *  Switch: '<S57>/Switch'
     *  UnitDelay: '<S57>/Unit Delay'
     */
    ccdd_acc_vehAccTgtProp_mps2 = tmp + ccdd_acc_vehAccTgtProp_mps2;
  }

  /* End of Switch: '<S57>/Switch1' */

  /* Sum: '<S52>/rawdmd' incorporates:
   *  Constant: '<S48>/Constant2'
   *  Constant: '<S48>/Constant7'
   *  DataTypeConversion: '<S59>/Data Type Conversion3'
   *  Product: '<S56>/Product'
   *  Product: '<S56>/Product1'
   *  Sum: '<S56>/rawdmd'
   */
  rtb_error = ((rtb_error - rtb_Divide) / 1.0F * 0.0F +
               (ccdd_acc_vehAccTgtLong_mps2 + ccdd_acc_vehAccTgtIntgl_mps2)) +
    ccdd_acc_vehAccTgtProp_mps2;

  /* RelationalOperator: '<S55>/AboveMax' incorporates:
   *  Constant: '<S48>/Constant8'
   */
  rtb_AboveMax = (ccdc_acc_vehAccTgtMax_mps2 < rtb_error);

  /* RelationalOperator: '<S55>/BelowMin' incorporates:
   *  Constant: '<S48>/Constant9'
   */
  rtb_BelowMin = (rtb_error < ccdc_acc_vehAccTgtMin_mps2);

  /* Switch: '<S55>/Switch' incorporates:
   *  Switch: '<S55>/Switch1'
   */
  if (rtb_AboveMax) {
    /* Switch: '<S55>/Switch' incorporates:
     *  Constant: '<S48>/Constant8'
     */
    ccdd_acc_intAccTgt_mps2 = ccdc_acc_vehAccTgtMax_mps2;
  } else if (rtb_BelowMin) {
    /* Switch: '<S55>/Switch1' incorporates:
     *  Constant: '<S48>/Constant9'
     *  Switch: '<S55>/Switch'
     */
    ccdd_acc_intAccTgt_mps2 = ccdc_acc_vehAccTgtMin_mps2;
  } else {
    /* Switch: '<S55>/Switch' incorporates:
     *  Switch: '<S55>/Switch1'
     */
    ccdd_acc_intAccTgt_mps2 = rtb_error;
  }

  /* End of Switch: '<S55>/Switch' */

  /* Update for UnitDelay: '<S52>/ClippedPrev' incorporates:
   *  Logic: '<S55>/OutsideLimit'
   */
  swc_SCOO_ARID_DEF.ClippedPrev_DSTATE_g = (rtb_AboveMax || rtb_BelowMin);

  /* Update for UnitDelay: '<S59>/init' incorporates:
   *  Constant: '<S59>/Constant1'
   */
  swc_SCOO_ARID_DEF.init_DSTATE_hd = false;

  /* Update for UnitDelay: '<S59>/Unit Delay' incorporates:
   *  DataTypeConversion: '<S59>/Data Type Conversion3'
   */
  swc_SCOO_ARID_DEF.UnitDelay_DSTATE_m = rtb_Divide;
}

/* System initialize for atomic system: '<S49>/PID_FeedForward' */
static void swc_SCOO_PID_FeedForward_c_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S75>/init' */
  swc_SCOO_ARID_DEF.init_DSTATE_j = true;
}

/* Output and update for atomic system: '<S49>/PID_FeedForward' */
static void swc_SCOO_PID_FeedForward_e(void)
{
  float32 rtb_Divide;
  float32 rtb_error;
  boolean rtb_AboveMax;
  boolean rtb_BelowMin;

  /* Sum: '<S67>/Sum' */
  rtb_error = ccdd_acc_vehAccTgt_mps2 - ccdd_acc_vehAccAct_mps2;

  /* Product: '<S74>/Product' */
  ccdd_tq_whlDemRawAdvIntgl_Nm = rtb_error * ccdd_fact_crsCtrlTqKp;

  /* Switch: '<S75>/Switch' incorporates:
   *  UnitDelay: '<S75>/init'
   */
  if (swc_SCOO_ARID_DEF.init_DSTATE_j) {
    /* Switch: '<S75>/Switch' incorporates:
     *  DataTypeConversion: '<S75>/Data Type Conversion'
     */
    rtb_Divide = rtb_error;
  } else {
    /* Product: '<S75>/Divide' incorporates:
     *  Constant: '<S49>/Constant2'
     *  Constant: '<S49>/Constant3'
     *  DataTypeConversion: '<S75>/Data Type Conversion1'
     *  DataTypeConversion: '<S75>/Data Type Conversion2'
     *  Sum: '<S75>/Add1'
     */
    rtb_Divide = 1.0F / (1.0F + ((float32)CCD_TASK_INTERVAL_S));

    /* Switch: '<S75>/Switch' incorporates:
     *  Constant: '<S75>/Constant'
     *  DataTypeConversion: '<S75>/Data Type Conversion'
     *  Product: '<S75>/Product'
     *  Product: '<S75>/Product1'
     *  Sum: '<S75>/Add'
     *  Sum: '<S75>/Add2'
     *  UnitDelay: '<S75>/Unit Delay'
     */
    rtb_Divide = (1.0F - rtb_Divide) * rtb_error + rtb_Divide *
      swc_SCOO_ARID_DEF.UnitDelay_DSTATE_ah;
  }

  /* End of Switch: '<S75>/Switch' */

  /* Switch: '<S73>/Switch1' incorporates:
   *  Constant: '<S49>/Constant1'
   *  Logic: '<S67>/Logical Operator1'
   *  Logic: '<S67>/Logical Operator2'
   *  Switch: '<S73>/Switch'
   *  UnitDelay: '<S67>/ClippedPrev'
   */
  if (swc_SCOO_ARID_DEF.LogicalOperator_l) {
    /* Switch: '<S73>/Switch1' incorporates:
     *  Constant: '<S73>/Constant'
     */
    ccdd_tq_whlDemRawAdvProp_Nm = 0.0F;
  } else {
    float32 tmp;
    if ((!true) || swc_SCOO_ARID_DEF.ClippedPrev_DSTATE_b) {
      /* Switch: '<S73>/Switch' incorporates:
       *  Constant: '<S73>/Constant'
       */
      tmp = 0.0F;
    } else {
      /* Switch: '<S73>/Switch' incorporates:
       *  Constant: '<S49>/Constant2'
       *  Product: '<S73>/Product2'
       */
      tmp = rtb_error * ccdd_fact_crsCtrlTqKi * ((float32)CCD_TASK_INTERVAL_S);
    }

    /* Switch: '<S73>/Switch1' incorporates:
     *  Sum: '<S73>/Sum1'
     *  Switch: '<S73>/Switch'
     *  UnitDelay: '<S73>/Unit Delay'
     */
    ccdd_tq_whlDemRawAdvProp_Nm = tmp + ccdd_tq_whlDemRawAdvProp_Nm;
  }

  /* End of Switch: '<S73>/Switch1' */

  /* Sum: '<S67>/rawdmd' incorporates:
   *  Constant: '<S49>/Constant3'
   *  Constant: '<S49>/Constant4'
   *  DataTypeConversion: '<S75>/Data Type Conversion3'
   *  Product: '<S72>/Product'
   *  Product: '<S72>/Product1'
   *  Sum: '<S72>/rawdmd'
   */
  rtb_error = ((rtb_error - rtb_Divide) / 1.0F * 0.0F + (ccdd_tq_crsCtrlTqFF_Nm
    + ccdd_tq_whlDemRawAdvIntgl_Nm)) + ccdd_tq_whlDemRawAdvProp_Nm;

  /* RelationalOperator: '<S71>/AboveMax' */
  rtb_AboveMax = (swc_SCOO_ARID_DEF.DataTypeConversion10 < rtb_error);

  /* RelationalOperator: '<S71>/BelowMin' */
  rtb_BelowMin = (rtb_error < swc_SCOO_ARID_DEF.DataTypeConversion26);

  /* Switch: '<S71>/Switch' incorporates:
   *  Switch: '<S71>/Switch1'
   */
  if (rtb_AboveMax) {
    /* Switch: '<S71>/Switch' */
    ccdd_tq_whlDemRawAdv_Nm = swc_SCOO_ARID_DEF.DataTypeConversion10;
  } else if (rtb_BelowMin) {
    /* Switch: '<S71>/Switch1' incorporates:
     *  Switch: '<S71>/Switch'
     */
    ccdd_tq_whlDemRawAdv_Nm = swc_SCOO_ARID_DEF.DataTypeConversion26;
  } else {
    /* Switch: '<S71>/Switch' incorporates:
     *  Switch: '<S71>/Switch1'
     */
    ccdd_tq_whlDemRawAdv_Nm = rtb_error;
  }

  /* End of Switch: '<S71>/Switch' */

  /* Update for UnitDelay: '<S67>/ClippedPrev' incorporates:
   *  Logic: '<S71>/OutsideLimit'
   */
  swc_SCOO_ARID_DEF.ClippedPrev_DSTATE_b = (rtb_AboveMax || rtb_BelowMin);

  /* Update for UnitDelay: '<S75>/init' incorporates:
   *  Constant: '<S75>/Constant1'
   */
  swc_SCOO_ARID_DEF.init_DSTATE_j = false;

  /* Update for UnitDelay: '<S75>/Unit Delay' incorporates:
   *  DataTypeConversion: '<S75>/Data Type Conversion3'
   */
  swc_SCOO_ARID_DEF.UnitDelay_DSTATE_ah = rtb_Divide;
}

/* System initialize for atomic system: '<S46>/PID_FeedForward' */
static void swc_SCOO_PID_FeedForward_i_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S82>/init' */
  swc_SCOO_ARID_DEF.init_DSTATE_m = true;
}

/* Output and update for atomic system: '<S46>/PID_FeedForward' */
static void swc_SCOO_PID_FeedForward_d(void)
{
  float32 rtb_Divide;
  float32 rtb_Switch_i;
  float32 rtb_error;
  boolean rtb_AboveMax;
  boolean rtb_BelowMin;

  /* Sum: '<S77>/Sum' */
  rtb_error = ccdd_v_crsCtrlTgtSpd_kph - swc_SCOO_ARID_DEF.DataTypeConversion5;

  /* Switch: '<S82>/Switch' incorporates:
   *  UnitDelay: '<S82>/init'
   */
  if (swc_SCOO_ARID_DEF.init_DSTATE_m) {
    /* Switch: '<S82>/Switch' incorporates:
     *  DataTypeConversion: '<S82>/Data Type Conversion'
     */
    rtb_Divide = rtb_error;
  } else {
    /* Product: '<S82>/Divide' incorporates:
     *  Constant: '<S46>/Constant2'
     *  Constant: '<S46>/Constant4'
     *  DataTypeConversion: '<S82>/Data Type Conversion1'
     *  DataTypeConversion: '<S82>/Data Type Conversion2'
     *  Sum: '<S82>/Add1'
     */
    rtb_Divide = ccdc_tm_crsSpdCtrlDerivTc_s / (ccdc_tm_crsSpdCtrlDerivTc_s +
      ((float32)CCD_TASK_INTERVAL_S));

    /* Switch: '<S82>/Switch' incorporates:
     *  Constant: '<S82>/Constant'
     *  DataTypeConversion: '<S82>/Data Type Conversion'
     *  Product: '<S82>/Product'
     *  Product: '<S82>/Product1'
     *  Sum: '<S82>/Add'
     *  Sum: '<S82>/Add2'
     *  UnitDelay: '<S82>/Unit Delay'
     */
    rtb_Divide = (1.0F - rtb_Divide) * rtb_error + rtb_Divide *
      swc_SCOO_ARID_DEF.UnitDelay_DSTATE_g;
  }

  /* End of Switch: '<S82>/Switch' */

  /* Switch: '<S80>/Switch1' incorporates:
   *  Constant: '<S46>/Constant1'
   *  Logic: '<S77>/Logical Operator1'
   *  Logic: '<S77>/Logical Operator2'
   *  Switch: '<S80>/Switch'
   *  UnitDelay: '<S77>/ClippedPrev'
   */
  if (swc_SCOO_ARID_DEF.LogicalOperator_i) {
    /* Switch: '<S80>/Switch1' incorporates:
     *  Constant: '<S80>/Constant'
     */
    rtb_Switch_i = 0.0F;
  } else {
    if ((!true) || swc_SCOO_ARID_DEF.ClippedPrev_DSTATE_n) {
      /* Switch: '<S80>/Switch' incorporates:
       *  Constant: '<S80>/Constant'
       */
      rtb_Switch_i = 0.0F;
    } else {
      /* Switch: '<S80>/Switch' incorporates:
       *  Constant: '<S46>/Constant2'
       *  Product: '<S80>/Product2'
       */
      rtb_Switch_i = rtb_error * ccdd_fact_crsSpdCtrlKi * ((float32)
        CCD_TASK_INTERVAL_S);
    }

    /* Switch: '<S80>/Switch1' incorporates:
     *  Sum: '<S80>/Sum1'
     *  Switch: '<S80>/Switch'
     *  UnitDelay: '<S80>/Unit Delay'
     */
    rtb_Switch_i += swc_SCOO_ARID_DEF.UnitDelay_DSTATE_gu;
  }

  /* End of Switch: '<S80>/Switch1' */

  /* Sum: '<S77>/rawdmd' incorporates:
   *  Constant: '<S46>/Constant3'
   *  Constant: '<S46>/Constant4'
   *  DataTypeConversion: '<S82>/Data Type Conversion3'
   *  Product: '<S79>/Product'
   *  Product: '<S79>/Product1'
   *  Product: '<S81>/Product'
   *  Sum: '<S79>/rawdmd'
   */
  rtb_error = ((rtb_error - rtb_Divide) / ccdc_tm_crsSpdCtrlDerivTc_s *
               ccdc_fact_crsSpdCtrlKd + (rtb_error * ccdd_fact_crsSpdCtrlKp +
    ccdd_tq_crsSpdCtrlFF_Nm)) + rtb_Switch_i;

  /* RelationalOperator: '<S78>/AboveMax' */
  rtb_AboveMax = (swc_SCOO_ARID_DEF.DataTypeConversion10 < rtb_error);

  /* RelationalOperator: '<S78>/BelowMin' */
  rtb_BelowMin = (rtb_error < swc_SCOO_ARID_DEF.DataTypeConversion26);

  /* Switch: '<S78>/Switch' incorporates:
   *  Switch: '<S78>/Switch1'
   */
  if (rtb_AboveMax) {
    /* Switch: '<S78>/Switch' */
    ccdd_tq_whlDemRawBase_Nm = swc_SCOO_ARID_DEF.DataTypeConversion10;
  } else if (rtb_BelowMin) {
    /* Switch: '<S78>/Switch1' incorporates:
     *  Switch: '<S78>/Switch'
     */
    ccdd_tq_whlDemRawBase_Nm = swc_SCOO_ARID_DEF.DataTypeConversion26;
  } else {
    /* Switch: '<S78>/Switch' incorporates:
     *  Switch: '<S78>/Switch1'
     */
    ccdd_tq_whlDemRawBase_Nm = rtb_error;
  }

  /* End of Switch: '<S78>/Switch' */

  /* Update for UnitDelay: '<S77>/ClippedPrev' incorporates:
   *  Logic: '<S78>/OutsideLimit'
   */
  swc_SCOO_ARID_DEF.ClippedPrev_DSTATE_n = (rtb_AboveMax || rtb_BelowMin);

  /* Update for UnitDelay: '<S82>/init' incorporates:
   *  Constant: '<S82>/Constant1'
   */
  swc_SCOO_ARID_DEF.init_DSTATE_m = false;

  /* Update for UnitDelay: '<S82>/Unit Delay' incorporates:
   *  DataTypeConversion: '<S82>/Data Type Conversion3'
   */
  swc_SCOO_ARID_DEF.UnitDelay_DSTATE_g = rtb_Divide;

  /* Update for UnitDelay: '<S80>/Unit Delay' */
  swc_SCOO_ARID_DEF.UnitDelay_DSTATE_gu = rtb_Switch_i;
}

/* Function for Chart: '<S6>/Button_Sts' */
static void swc_SCOO_Coast_Sts(void)
{
  /* Constant: '<S6>/Constant10' incorporates:
   *  Constant: '<S6>/Constant11'
   *  Constant: '<S6>/Constant3'
   */
  if ((swc_SCOO_ARID_DEF.DataTypeConversion3 > ccdc_u_setBtnHiThd_V) ||
      ((swc_SCOO_ARID_DEF.DataTypeConversion3 < ccdc_u_setBtnLoThd_V) &&
       (swc_SCOO_ARID_DEF.time_c >= ccdc_tm_btnRlsd_s))) {
    swc_SCOO_ARID_DEF.is_Coast_Sts = swc_SCOO_IN_NO_ACTIVE_CHILD_j;
    swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Default_Sts;
    swc_SCOO_ARID_DEF.Butt_Cruise_Sts = false;
    swc_SCOO_ARID_DEF.Butt_Accel_Sts = false;
    swc_SCOO_ARID_DEF.Butt_Coast_Sts = false;
    ccdd_e_crsBtnSts = CrsBtnSts_NONE;
    ccdd_e_crsBtnErrSts = CrsBtnErrSts_NONE;
  } else if (swc_SCOO_ARID_DEF.is_Coast_Sts == swc_SCOO_IN_Coast_Error) {
    ccdd_e_crsBtnErrSts = CrsBtnErrSts_SET_STUCK;

    /* Constant: '<S6>/Constant12' */
    swc_SCOO_ARID_DEF.time_c += ((float32)CCD_TASK_INTERVAL_S);
  } else {
    /* case IN_Coast_Pressed: */
    ccdd_e_crsBtnSts = CrsBtnSts_SET;

    /* Constant: '<S6>/Constant1' */
    if (swc_SCOO_ARID_DEF.DataTypeConversion1 && (swc_SCOO_ARID_DEF.time_c >
         ccdc_tm_btnStuck_s)) {
      swc_SCOO_ARID_DEF.Butt_Coast_Sts = false;
      swc_SCOO_ARID_DEF.is_Coast_Sts = swc_SCOO_IN_Coast_Error;
      swc_SCOO_ARID_DEF.time_c = 0.0F;
      ccdd_e_crsBtnErrSts = CrsBtnErrSts_SET_STUCK;
    } else {
      /* Constant: '<S6>/Constant12' */
      swc_SCOO_ARID_DEF.time_c = fminf(swc_SCOO_ARID_DEF.time_c + ((float32)
        CCD_TASK_INTERVAL_S), 5000.0F);
    }

    /* End of Constant: '<S6>/Constant1' */
  }

  /* End of Constant: '<S6>/Constant10' */
}

/* Function for Chart: '<S6>/Button_Sts' */
static void swc_SCOO_Cruise_Sts(void)
{
  /* Constant: '<S6>/Constant4' incorporates:
   *  Constant: '<S6>/Constant13'
   *  Constant: '<S6>/Constant3'
   */
  if ((swc_SCOO_ARID_DEF.DataTypeConversion3 > ccdc_u_crsBtnHiThd_V) ||
      ((swc_SCOO_ARID_DEF.DataTypeConversion3 < ccdc_u_crsBtnLoThd_V) &&
       (swc_SCOO_ARID_DEF.time_c >= ccdc_tm_btnRlsd_s))) {
    if (swc_SCOO_ARID_DEF.is_Cruise_Sts == swc_SCOO_IN_Cruise_Pressed) {
      swc_SCOO_ARID_DEF.Butt_Cruise_Sts = false;
      swc_SCOO_ARID_DEF.is_Cruise_Sts = swc_SCOO_IN_NO_ACTIVE_CHILD_j;
    } else {
      swc_SCOO_ARID_DEF.is_Cruise_Sts = swc_SCOO_IN_NO_ACTIVE_CHILD_j;
    }

    swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Default_Sts;
    swc_SCOO_ARID_DEF.Butt_Cruise_Sts = false;
    swc_SCOO_ARID_DEF.Butt_Accel_Sts = false;
    swc_SCOO_ARID_DEF.Butt_Coast_Sts = false;
    ccdd_e_crsBtnSts = CrsBtnSts_NONE;
    ccdd_e_crsBtnErrSts = CrsBtnErrSts_NONE;
  } else if (swc_SCOO_ARID_DEF.is_Cruise_Sts == swc_SCOO_IN_Cruise_Error) {
    ccdd_e_crsBtnErrSts = CrsBtnErrSts_CRUISE_STUCK;

    /* Constant: '<S6>/Constant12' */
    swc_SCOO_ARID_DEF.time_c += ((float32)CCD_TASK_INTERVAL_S);
  } else {
    /* case IN_Cruise_Pressed: */
    ccdd_e_crsBtnSts = CrsBtnSts_CRUISE_MAIN;

    /* Constant: '<S6>/Constant1' */
    if (swc_SCOO_ARID_DEF.DataTypeConversion1 && (swc_SCOO_ARID_DEF.time_c >
         ccdc_tm_btnStuck_s)) {
      swc_SCOO_ARID_DEF.Butt_Cruise_Sts = false;
      swc_SCOO_ARID_DEF.is_Cruise_Sts = swc_SCOO_IN_Cruise_Error;
      swc_SCOO_ARID_DEF.time_c = 0.0F;
      ccdd_e_crsBtnErrSts = CrsBtnErrSts_CRUISE_STUCK;
    } else {
      /* Constant: '<S6>/Constant12' */
      swc_SCOO_ARID_DEF.time_c = fminf(swc_SCOO_ARID_DEF.time_c + ((float32)
        CCD_TASK_INTERVAL_S), 5000.0F);
    }

    /* End of Constant: '<S6>/Constant1' */
  }

  /* End of Constant: '<S6>/Constant4' */
}

/* Function for Chart: '<S6>/Button_Sts' */
static void swc_SCOO_Default_Sts(void)
{
  ccdd_e_crsBtnSts = CrsBtnSts_NONE;
  ccdd_e_crsBtnErrSts = CrsBtnErrSts_NONE;

  /* Constant: '<S6>/Constant15' incorporates:
   *  Constant: '<S6>/Constant10'
   *  Constant: '<S6>/Constant11'
   *  Constant: '<S6>/Constant13'
   *  Constant: '<S6>/Constant16'
   *  Constant: '<S6>/Constant17'
   *  Constant: '<S6>/Constant18'
   *  Constant: '<S6>/Constant19'
   *  Constant: '<S6>/Constant20'
   *  Constant: '<S6>/Constant23'
   *  Constant: '<S6>/Constant24'
   *  Constant: '<S6>/Constant4'
   *  Constant: '<S6>/Constant8'
   *  Constant: '<S6>/Constant9'
   */
  if ((swc_SCOO_ARID_DEF.DataTypeConversion3 <= ccdc_u_btnVltgAbnHiThd_V) &&
      (swc_SCOO_ARID_DEF.DataTypeConversion3 >= ccdc_u_btnVltgAbnLoThd_V) &&
      ((swc_SCOO_ARID_DEF.DataTypeConversion3 > ccdc_u_resBtnHiThd_V) ||
       (swc_SCOO_ARID_DEF.DataTypeConversion3 < ccdc_u_resBtnLoThd_V)) &&
      ((swc_SCOO_ARID_DEF.DataTypeConversion3 > ccdc_u_setBtnHiThd_V) ||
       (swc_SCOO_ARID_DEF.DataTypeConversion3 < ccdc_u_setBtnLoThd_V)) &&
      ((swc_SCOO_ARID_DEF.DataTypeConversion3 > ccdc_u_crsBtnHiThd_V) ||
       (swc_SCOO_ARID_DEF.DataTypeConversion3 < ccdc_u_crsBtnLoThd_V)) &&
      ((swc_SCOO_ARID_DEF.DataTypeConversion3 > ccdc_u_btnVltgDftHiThd_V) ||
       (swc_SCOO_ARID_DEF.DataTypeConversion3 < ccdc_u_btnVltgDftLoThd_V))) {
    swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCO_IN_Pre_Voltage_Abnormal;
    swc_SCOO_ARID_DEF.time_c = 0.0F;
  } else if ((swc_SCOO_ARID_DEF.DataTypeConversion3 <= ccdc_u_crsBtnHiThd_V) &&
             (swc_SCOO_ARID_DEF.DataTypeConversion3 >= ccdc_u_crsBtnLoThd_V)) {
    swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Pre_Cruise_Sts;
    swc_SCOO_ARID_DEF.time_c = 0.0F;
  } else if (swc_SCOO_ARID_DEF.DataTypeConversion3 > ccdc_u_btnVltgSCBHiThd_V) {
    swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Pre_Voltage_SCB;
    swc_SCOO_ARID_DEF.time_c = 0.0F;
  } else if (swc_SCOO_ARID_DEF.DataTypeConversion3 < ccdc_u_btnVltgSCGLoThd_V) {
    swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Pre_Voltage_SCG;
    swc_SCOO_ARID_DEF.time_c = 0.0F;
  } else if ((swc_SCOO_ARID_DEF.DataTypeConversion3 <= ccdc_u_setBtnHiThd_V) &&
             (swc_SCOO_ARID_DEF.DataTypeConversion3 >= ccdc_u_setBtnLoThd_V)) {
    swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Pre_Coast_Sts;
    swc_SCOO_ARID_DEF.time_c = 0.0F;
  } else if ((swc_SCOO_ARID_DEF.DataTypeConversion3 <= ccdc_u_resBtnHiThd_V) &&
             (swc_SCOO_ARID_DEF.DataTypeConversion3 >= ccdc_u_resBtnLoThd_V)) {
    swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Pre_Accel_Sts;
    swc_SCOO_ARID_DEF.time_c = 0.0F;
  } else if ((swc_SCOO_ARID_DEF.DataTypeConversion3 < ccdc_u_btnVltgOCHiThd_V) &&
             (swc_SCOO_ARID_DEF.DataTypeConversion3 > ccdc_u_btnVltgOCLoThd_V))
  {
    swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Pre_Voltage_OC;
    swc_SCOO_ARID_DEF.time_c = 0.0F;
  }

  /* End of Constant: '<S6>/Constant15' */
}

/* System initialize for function-call system: '<S1>/CCD_CruiseControlDemand' */
static void sw_CCD_CruiseControlDemand_Init(void)
{
  /* local block i/o variables */
  boolean rtb_RampOn;
  boolean rtb_flg_out;
  boolean rtb_flg_out_g;

  /* Start for InitialCondition: '<S60>/IC' */
  swc_SCOO_ARID_DEF.IC_FirstOutputTime = true;

  /* Start for InitialCondition: '<S65>/IC' */
  swc_SCOO_ARID_DEF.IC_FirstOutputTime_o = true;

  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay1' */
  swc_SCOO_ARID_DEF.UnitDelay1_DSTATE_g = CrModeMngr_e_OFF;

  /* InitializeConditions for UnitDelay: '<S13>/Unit Delay1' */
  swc_SCOO_ARID_DEF.UnitDelay1_DSTATE_gm = CrModeMngr_e_OFF;

  /* InitializeConditions for UnitDelay: '<S61>/init' */
  swc_SCOO_ARID_DEF.init_DSTATE_d = true;

  /* InitializeConditions for UnitDelay: '<S50>/init' */
  swc_SCOO_ARID_DEF.init_DSTATE_k = true;

  /* InitializeConditions for UnitDelay: '<S68>/init' */
  swc_SCOO_ARID_DEF.init_DSTATE_h = true;

  /* SystemInitialize for Atomic SubSystem: '<S22>/turnON_delay' */
  swc_SCOO_turnON_delay_Init(&rtb_flg_out);

  /* End of SystemInitialize for SubSystem: '<S22>/turnON_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/turnON_delay' */
  swc_SCOO_turnON_delay_Init(&rtb_flg_out_g);

  /* End of SystemInitialize for SubSystem: '<S6>/turnON_delay' */

  /* SystemInitialize for Enabled SubSystem: '<S37>/BaselineControl' */
  /* SystemInitialize for Atomic SubSystem: '<S46>/PID_FeedForward' */
  swc_SCOO_PID_FeedForward_i_Init();

  /* End of SystemInitialize for SubSystem: '<S46>/PID_FeedForward' */
  /* End of SystemInitialize for SubSystem: '<S37>/BaselineControl' */

  /* SystemInitialize for Atomic SubSystem: '<S48>/PID_FeedForward' */
  swc_SCOO_PID_FeedForward_Init();

  /* End of SystemInitialize for SubSystem: '<S48>/PID_FeedForward' */

  /* SystemInitialize for Atomic SubSystem: '<S49>/PID_FeedForward' */
  swc_SCOO_PID_FeedForward_c_Init();

  /* End of SystemInitialize for SubSystem: '<S49>/PID_FeedForward' */

  /* SystemInitialize for Atomic SubSystem: '<S8>/SwitchRampCreepTrqDem' */
  swc_SCOO_switch_ramp_Init(&swc_SCOO_ARID_DEF.y, &rtb_RampOn);

  /* End of SystemInitialize for SubSystem: '<S8>/SwitchRampCreepTrqDem' */
}

/* Output and update for function-call system: '<S1>/CCD_CruiseControlDemand' */
static void swc_SCO_CCD_CruiseControlDemand(void)
{
  /* local block i/o variables */
  float32 rtb_Add_i;
  float32 rtb_Sum;
  float32 rtb_uDLookupTable;
  boolean rtb_LogicalOperator4;
  boolean rtb_LogicalOperator2_g;
  boolean rtb_RampOn;
  boolean rtb_flg_out;
  boolean rtb_flg_out_g;
  float32 rtb_Sum_m;
  float32 rtb_Sum_tmp;
  CrModeMngr_e tmp_1;
  uint8 tmp;
  uint8 tmp_0;
  boolean rtb_FixPtRelationalOperator;
  boolean rtb_RelationalOperator4_l;

  /* Lookup_n-D: '<S66>/1-D Lookup Table' incorporates:
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  rtb_uDLookupTable = ccdd_tq_whlDem_Nm;

  /* Lookup_n-D: '<S5>/2-D Lookup Table4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   *  Lookup_n-D: '<S66>/1-D Lookup Table'
   */
  ccdd_x_accPedlPosVirtRaw_pct = look2_iflf_binlcapw
    (swc_SCOO_ARID_DEF.DataTypeConversion5, rtb_uDLookupTable, (const float32 *)
     &ccda_pedlPosVirt_X_VehSpd_kph[0], (const float32 *)
     &ccda_pedlPosVirt_Y_WhlDem_Nm[0], (const float32 *)&ccdm_pedlPosVirt_Z_pct
     [0], swc_SCOO_ConstP.uDLookupTable4_maxIndex, 12U);

  /* Lookup_n-D: '<S66>/1-D Lookup Table' incorporates:
   *  Sum: '<S5>/Sum'
   */
  rtb_uDLookupTable = swc_SCOO_ARID_DEF.DataTypeConversion11 - rtb_uDLookupTable;

  /* Relay: '<S5>/Relay4' */
  swc_SCOO_ARID_DEF.Relay4_Mode_h = ((rtb_uDLookupTable >=
    ccdc_tq_crsAccelPdlOvrdHi_Nm) || ((rtb_uDLookupTable >
    ccdc_tq_crsAccelPdlOvrdLo_Nm) && swc_SCOO_ARID_DEF.Relay4_Mode_h));

  /* Relay: '<S5>/Relay1' */
  swc_SCOO_ARID_DEF.Relay1_Mode_p = ((swc_SCOO_ARID_DEF.DataTypeConversion7 >=
    ccdc_x_crsAccelPdlOvrdHi_pct) || ((swc_SCOO_ARID_DEF.DataTypeConversion7 >
    ccdc_x_crsAccelPdlOvrdLo_pct) && swc_SCOO_ARID_DEF.Relay1_Mode_p));

  /* Relay: '<S5>/Relay4' */
  if (swc_SCOO_ARID_DEF.Relay4_Mode_h) {
    tmp = ((uint8)1U);
  } else {
    tmp = ((uint8)0U);
  }

  /* Relay: '<S5>/Relay1' */
  if (swc_SCOO_ARID_DEF.Relay1_Mode_p) {
    tmp_0 = ((uint8)1U);
  } else {
    tmp_0 = ((uint8)0U);
  }

  /* Logic: '<S5>/Logical Operator' incorporates:
   *  Relay: '<S5>/Relay1'
   *  Relay: '<S5>/Relay4'
   */
  ccdd_b_crsCtrlAccPedlOvrd = ((tmp != 0) && (tmp_0 != 0));

  /* Chart: '<S6>/Button_Sts' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant10'
   *  Constant: '<S6>/Constant11'
   *  Constant: '<S6>/Constant12'
   *  Constant: '<S6>/Constant13'
   *  Constant: '<S6>/Constant14'
   *  Constant: '<S6>/Constant15'
   *  Constant: '<S6>/Constant16'
   *  Constant: '<S6>/Constant17'
   *  Constant: '<S6>/Constant18'
   *  Constant: '<S6>/Constant19'
   *  Constant: '<S6>/Constant2'
   *  Constant: '<S6>/Constant20'
   *  Constant: '<S6>/Constant23'
   *  Constant: '<S6>/Constant24'
   *  Constant: '<S6>/Constant3'
   *  Constant: '<S6>/Constant4'
   *  Constant: '<S6>/Constant5'
   *  Constant: '<S6>/Constant6'
   *  Constant: '<S6>/Constant7'
   *  Constant: '<S6>/Constant8'
   *  Constant: '<S6>/Constant9'
   */
  if (swc_SCOO_ARID_DEF.is_active_c15_vsl == 0U) {
    swc_SCOO_ARID_DEF.is_active_c15_vsl = 1U;
    swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Default_Sts;
    swc_SCOO_ARID_DEF.Butt_Cruise_Sts = false;
    swc_SCOO_ARID_DEF.Butt_Accel_Sts = false;
    swc_SCOO_ARID_DEF.Butt_Coast_Sts = false;
    ccdd_e_crsBtnSts = CrsBtnSts_NONE;
    ccdd_e_crsBtnErrSts = CrsBtnErrSts_NONE;
  } else {
    switch (swc_SCOO_ARID_DEF.is_c15_vsl) {
     case swc_SCOO_IN_Accel_Sts:
      if ((swc_SCOO_ARID_DEF.DataTypeConversion3 > ccdc_u_resBtnHiThd_V) ||
          ((swc_SCOO_ARID_DEF.DataTypeConversion3 < ccdc_u_resBtnLoThd_V) &&
           (swc_SCOO_ARID_DEF.time_c >= ccdc_tm_btnRlsd_s))) {
        swc_SCOO_ARID_DEF.is_Accel_Sts = swc_SCOO_IN_NO_ACTIVE_CHILD_j;
        swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Default_Sts;
        swc_SCOO_ARID_DEF.Butt_Cruise_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Accel_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Coast_Sts = false;
        ccdd_e_crsBtnSts = CrsBtnSts_NONE;
        ccdd_e_crsBtnErrSts = CrsBtnErrSts_NONE;
      } else if (swc_SCOO_ARID_DEF.is_Accel_Sts == swc_SCOO_IN_Accel_Error) {
        ccdd_e_crsBtnErrSts = CrsBtnErrSts_RESUME_STUCK;
        swc_SCOO_ARID_DEF.time_c += ((float32)CCD_TASK_INTERVAL_S);
      } else {
        /* case IN_Accel_Pressed: */
        ccdd_e_crsBtnSts = CrsBtnSts_RESUME;
        if (swc_SCOO_ARID_DEF.DataTypeConversion1 && (swc_SCOO_ARID_DEF.time_c >
             ccdc_tm_btnStuck_s)) {
          swc_SCOO_ARID_DEF.Butt_Accel_Sts = false;
          swc_SCOO_ARID_DEF.is_Accel_Sts = swc_SCOO_IN_Accel_Error;
          swc_SCOO_ARID_DEF.time_c = 0.0F;
          ccdd_e_crsBtnErrSts = CrsBtnErrSts_RESUME_STUCK;
        } else {
          swc_SCOO_ARID_DEF.time_c = fminf(swc_SCOO_ARID_DEF.time_c + ((float32)
            CCD_TASK_INTERVAL_S), 5000.0F);
        }
      }
      break;

     case swc_SCOO_IN_Coast_Sts:
      swc_SCOO_Coast_Sts();
      break;

     case swc_SCOO_IN_Cruise_Sts:
      swc_SCOO_Cruise_Sts();
      break;

     case swc_SCOO_IN_Default_Sts:
      swc_SCOO_Default_Sts();
      break;

     case swc_SCOO_IN_Pre_Accel_Sts:
      if ((swc_SCOO_ARID_DEF.DataTypeConversion3 > ccdc_u_resBtnHiThd_V) ||
          (swc_SCOO_ARID_DEF.DataTypeConversion3 < ccdc_u_resBtnLoThd_V)) {
        swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Default_Sts;
        swc_SCOO_ARID_DEF.Butt_Cruise_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Accel_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Coast_Sts = false;
        ccdd_e_crsBtnSts = CrsBtnSts_NONE;
        ccdd_e_crsBtnErrSts = CrsBtnErrSts_NONE;
      } else if (swc_SCOO_ARID_DEF.time_c >= ccdc_tm_btnPrsd_s) {
        swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Accel_Sts;
        swc_SCOO_ARID_DEF.is_Accel_Sts = swc_SCOO_IN_Accel_Pressed;
        swc_SCOO_ARID_DEF.Butt_Cruise_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Accel_Sts = true;
        swc_SCOO_ARID_DEF.Butt_Coast_Sts = false;
        ccdd_e_crsBtnSts = CrsBtnSts_RESUME;
        swc_SCOO_ARID_DEF.time_c = 0.0F;
      } else {
        swc_SCOO_ARID_DEF.time_c = fminf(swc_SCOO_ARID_DEF.time_c + ((float32)
          CCD_TASK_INTERVAL_S), 5000.0F);
      }
      break;

     case swc_SCOO_IN_Pre_Coast_Sts:
      if (swc_SCOO_ARID_DEF.time_c >= ccdc_tm_btnPrsd_s) {
        swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Coast_Sts;
        swc_SCOO_ARID_DEF.is_Coast_Sts = swc_SCOO_IN_Coast_Pressed;
        swc_SCOO_ARID_DEF.Butt_Cruise_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Accel_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Coast_Sts = true;
        ccdd_e_crsBtnSts = CrsBtnSts_SET;
        swc_SCOO_ARID_DEF.time_c = 0.0F;
      } else if ((swc_SCOO_ARID_DEF.DataTypeConversion3 > ccdc_u_setBtnHiThd_V) ||
                 (swc_SCOO_ARID_DEF.DataTypeConversion3 < ccdc_u_setBtnLoThd_V))
      {
        swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Default_Sts;
        swc_SCOO_ARID_DEF.Butt_Cruise_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Accel_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Coast_Sts = false;
        ccdd_e_crsBtnSts = CrsBtnSts_NONE;
        ccdd_e_crsBtnErrSts = CrsBtnErrSts_NONE;
      } else {
        swc_SCOO_ARID_DEF.time_c = fminf(swc_SCOO_ARID_DEF.time_c + ((float32)
          CCD_TASK_INTERVAL_S), 5000.0F);
      }
      break;

     case swc_SCOO_IN_Pre_Cruise_Sts:
      if (swc_SCOO_ARID_DEF.time_c >= ccdc_tm_btnPrsd_s) {
        swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Cruise_Sts;
        swc_SCOO_ARID_DEF.is_Cruise_Sts = swc_SCOO_IN_Cruise_Pressed;
        swc_SCOO_ARID_DEF.Butt_Cruise_Sts = true;
        swc_SCOO_ARID_DEF.Butt_Accel_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Coast_Sts = false;
        ccdd_e_crsBtnSts = CrsBtnSts_CRUISE_MAIN;
        swc_SCOO_ARID_DEF.time_c = 0.0F;
      } else if ((swc_SCOO_ARID_DEF.DataTypeConversion3 > ccdc_u_crsBtnHiThd_V) ||
                 (swc_SCOO_ARID_DEF.DataTypeConversion3 < ccdc_u_crsBtnLoThd_V))
      {
        swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Default_Sts;
        swc_SCOO_ARID_DEF.Butt_Cruise_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Accel_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Coast_Sts = false;
        ccdd_e_crsBtnSts = CrsBtnSts_NONE;
        ccdd_e_crsBtnErrSts = CrsBtnErrSts_NONE;
      } else {
        swc_SCOO_ARID_DEF.time_c = fminf(swc_SCOO_ARID_DEF.time_c + ((float32)
          CCD_TASK_INTERVAL_S), 5000.0F);
      }
      break;

     case swc_SCO_IN_Pre_Voltage_Abnormal:
      if (swc_SCOO_ARID_DEF.time_c >= ccdc_tm_btnVltgAbn_s) {
        swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Voltage_Abnormal;
        swc_SCOO_ARID_DEF.time_c = 0.0F;
        ccdd_e_crsBtnErrSts = CrsBtnErrSts_VOLTAGE_ABNORMAL;
      } else if ((swc_SCOO_ARID_DEF.DataTypeConversion3 >
                  ccdc_u_btnVltgAbnHiThd_V) ||
                 (swc_SCOO_ARID_DEF.DataTypeConversion3 <
                  ccdc_u_btnVltgAbnLoThd_V) ||
                 ((swc_SCOO_ARID_DEF.DataTypeConversion3 <= ccdc_u_resBtnHiThd_V)
                  && (swc_SCOO_ARID_DEF.DataTypeConversion3 >=
                      ccdc_u_resBtnLoThd_V)) ||
                 ((swc_SCOO_ARID_DEF.DataTypeConversion3 <= ccdc_u_setBtnHiThd_V)
                  && (swc_SCOO_ARID_DEF.DataTypeConversion3 >=
                      ccdc_u_setBtnLoThd_V)) ||
                 ((swc_SCOO_ARID_DEF.DataTypeConversion3 <= ccdc_u_crsBtnHiThd_V)
                  && (swc_SCOO_ARID_DEF.DataTypeConversion3 >=
                      ccdc_u_crsBtnLoThd_V)) ||
                 ((swc_SCOO_ARID_DEF.DataTypeConversion3 <=
                   ccdc_u_btnVltgDftHiThd_V) &&
                  (swc_SCOO_ARID_DEF.DataTypeConversion3 >=
                   ccdc_u_btnVltgDftLoThd_V))) {
        swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Default_Sts;
        swc_SCOO_ARID_DEF.Butt_Cruise_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Accel_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Coast_Sts = false;
        ccdd_e_crsBtnSts = CrsBtnSts_NONE;
        ccdd_e_crsBtnErrSts = CrsBtnErrSts_NONE;
      } else {
        swc_SCOO_ARID_DEF.time_c = fminf(swc_SCOO_ARID_DEF.time_c + ((float32)
          CCD_TASK_INTERVAL_S), 5000.0F);
      }
      break;

     case swc_SCOO_IN_Pre_Voltage_OC:
      if (swc_SCOO_ARID_DEF.time_c >= ccdc_tm_btnVltgOC_s) {
        swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Voltage_OC;
        swc_SCOO_ARID_DEF.time_c = 0.0F;
        ccdd_e_crsBtnErrSts = CrsBtnErrSts_VOLTAGE_OC;
      } else if ((swc_SCOO_ARID_DEF.DataTypeConversion3 >
                  ccdc_u_btnVltgOCHiThd_V) ||
                 (swc_SCOO_ARID_DEF.DataTypeConversion3 <
                  ccdc_u_btnVltgOCLoThd_V)) {
        swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Default_Sts;
        swc_SCOO_ARID_DEF.Butt_Cruise_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Accel_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Coast_Sts = false;
        ccdd_e_crsBtnSts = CrsBtnSts_NONE;
        ccdd_e_crsBtnErrSts = CrsBtnErrSts_NONE;
      } else {
        swc_SCOO_ARID_DEF.time_c = fminf(swc_SCOO_ARID_DEF.time_c + ((float32)
          CCD_TASK_INTERVAL_S), 5000.0F);
      }
      break;

     case swc_SCOO_IN_Pre_Voltage_SCB:
      if (swc_SCOO_ARID_DEF.time_c >= ccdc_tm_btnVltgSCB_s) {
        swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Voltage_SCB;
        swc_SCOO_ARID_DEF.time_c = 0.0F;
        ccdd_e_crsBtnErrSts = CrsBtnErrSts_VOLTAGE_SCB;
      } else if (swc_SCOO_ARID_DEF.DataTypeConversion3 <
                 ccdc_u_btnVltgSCBHiThd_V) {
        swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Default_Sts;
        swc_SCOO_ARID_DEF.Butt_Cruise_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Accel_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Coast_Sts = false;
        ccdd_e_crsBtnSts = CrsBtnSts_NONE;
        ccdd_e_crsBtnErrSts = CrsBtnErrSts_NONE;
      } else {
        swc_SCOO_ARID_DEF.time_c = fminf(swc_SCOO_ARID_DEF.time_c + ((float32)
          CCD_TASK_INTERVAL_S), 5000.0F);
      }
      break;

     case swc_SCOO_IN_Pre_Voltage_SCG:
      if (swc_SCOO_ARID_DEF.time_c >= ccdc_tm_btnVltgSCG_s) {
        swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Voltage_SCG;
        swc_SCOO_ARID_DEF.time_c = 0.0F;
        ccdd_e_crsBtnErrSts = CrsBtnErrSts_VOLTAGE_SCG;
      } else if (swc_SCOO_ARID_DEF.DataTypeConversion3 >
                 ccdc_u_btnVltgSCGLoThd_V) {
        swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Default_Sts;
        swc_SCOO_ARID_DEF.Butt_Cruise_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Accel_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Coast_Sts = false;
        ccdd_e_crsBtnSts = CrsBtnSts_NONE;
        ccdd_e_crsBtnErrSts = CrsBtnErrSts_NONE;
      } else {
        swc_SCOO_ARID_DEF.time_c = fminf(swc_SCOO_ARID_DEF.time_c + ((float32)
          CCD_TASK_INTERVAL_S), 5000.0F);
      }
      break;

     case swc_SCOO_IN_Voltage_Abnormal:
      ccdd_e_crsBtnErrSts = CrsBtnErrSts_VOLTAGE_ABNORMAL;
      if ((swc_SCOO_ARID_DEF.DataTypeConversion3 > ccdc_u_btnVltgAbnHiThd_V) ||
          (swc_SCOO_ARID_DEF.DataTypeConversion3 < ccdc_u_btnVltgAbnLoThd_V) ||
          ((swc_SCOO_ARID_DEF.DataTypeConversion3 <= ccdc_u_resBtnHiThd_V) &&
           (swc_SCOO_ARID_DEF.DataTypeConversion3 >= ccdc_u_resBtnLoThd_V)) ||
          ((swc_SCOO_ARID_DEF.DataTypeConversion3 <= ccdc_u_setBtnHiThd_V) &&
           (swc_SCOO_ARID_DEF.DataTypeConversion3 >= ccdc_u_setBtnLoThd_V)) ||
          ((swc_SCOO_ARID_DEF.DataTypeConversion3 <= ccdc_u_crsBtnHiThd_V) &&
           (swc_SCOO_ARID_DEF.DataTypeConversion3 >= ccdc_u_crsBtnLoThd_V)) ||
          ((swc_SCOO_ARID_DEF.DataTypeConversion3 <= ccdc_u_btnVltgDftHiThd_V) &&
           (swc_SCOO_ARID_DEF.DataTypeConversion3 >= ccdc_u_btnVltgDftLoThd_V)))
      {
        swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Default_Sts;
        swc_SCOO_ARID_DEF.Butt_Cruise_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Accel_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Coast_Sts = false;
        ccdd_e_crsBtnSts = CrsBtnSts_NONE;
        ccdd_e_crsBtnErrSts = CrsBtnErrSts_NONE;
      } else {
        swc_SCOO_ARID_DEF.time_c = fminf(swc_SCOO_ARID_DEF.time_c + ((float32)
          CCD_TASK_INTERVAL_S), 5000.0F);
      }
      break;

     case swc_SCOO_IN_Voltage_OC:
      ccdd_e_crsBtnErrSts = CrsBtnErrSts_VOLTAGE_OC;
      if ((swc_SCOO_ARID_DEF.DataTypeConversion3 > ccdc_u_btnVltgOCHiThd_V) ||
          (swc_SCOO_ARID_DEF.DataTypeConversion3 < ccdc_u_btnVltgOCLoThd_V)) {
        swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Default_Sts;
        swc_SCOO_ARID_DEF.Butt_Cruise_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Accel_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Coast_Sts = false;
        ccdd_e_crsBtnSts = CrsBtnSts_NONE;
        ccdd_e_crsBtnErrSts = CrsBtnErrSts_NONE;
      } else {
        swc_SCOO_ARID_DEF.time_c = fminf(swc_SCOO_ARID_DEF.time_c + ((float32)
          CCD_TASK_INTERVAL_S), 5000.0F);
      }
      break;

     case swc_SCOO_IN_Voltage_SCB:
      ccdd_e_crsBtnErrSts = CrsBtnErrSts_VOLTAGE_SCB;
      if (swc_SCOO_ARID_DEF.DataTypeConversion3 < ccdc_u_btnVltgSCBHiThd_V) {
        swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Default_Sts;
        swc_SCOO_ARID_DEF.Butt_Cruise_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Accel_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Coast_Sts = false;
        ccdd_e_crsBtnSts = CrsBtnSts_NONE;
        ccdd_e_crsBtnErrSts = CrsBtnErrSts_NONE;
      } else {
        swc_SCOO_ARID_DEF.time_c = fminf(swc_SCOO_ARID_DEF.time_c + ((float32)
          CCD_TASK_INTERVAL_S), 5000.0F);
      }
      break;

     default:
      /* case IN_Voltage_SCG: */
      ccdd_e_crsBtnErrSts = CrsBtnErrSts_VOLTAGE_SCG;
      if (swc_SCOO_ARID_DEF.DataTypeConversion3 > ccdc_u_btnVltgSCGLoThd_V) {
        swc_SCOO_ARID_DEF.is_c15_vsl = swc_SCOO_IN_Default_Sts;
        swc_SCOO_ARID_DEF.Butt_Cruise_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Accel_Sts = false;
        swc_SCOO_ARID_DEF.Butt_Coast_Sts = false;
        ccdd_e_crsBtnSts = CrsBtnSts_NONE;
        ccdd_e_crsBtnErrSts = CrsBtnErrSts_NONE;
      } else {
        swc_SCOO_ARID_DEF.time_c = fminf(swc_SCOO_ARID_DEF.time_c + ((float32)
          CCD_TASK_INTERVAL_S), 5000.0F);
      }
      break;
    }
  }

  /* End of Chart: '<S6>/Button_Sts' */

  /* Sum: '<S22>/Add' incorporates:
   *  UnitDelay: '<S22>/Unit Delay2'
   */
  rtb_Add_i = ccdd_v_crsCtrlTgtSpd_kph - swc_SCOO_ARID_DEF.DataTypeConversion5;

  /* If: '<S29>/If' incorporates:
   *  Constant: '<S29>/Constant'
   */
  if (rtb_Add_i >= 0.0F) {
    /* Outputs for IfAction SubSystem: '<S29>/pos' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    swc_SCOO_pos(rtb_Add_i, &rtb_uDLookupTable);

    /* End of Outputs for SubSystem: '<S29>/pos' */
  } else {
    /* Outputs for IfAction SubSystem: '<S29>/neg' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    swc_SCOO_neg(rtb_Add_i, &rtb_uDLookupTable);

    /* End of Outputs for SubSystem: '<S29>/neg' */
  }

  /* End of If: '<S29>/If' */

  /* Logic: '<S22>/Logical Operator4' incorporates:
   *  Constant: '<S22>/Constant20'
   *  Constant: '<S27>/Constant'
   *  RelationalOperator: '<S22>/Relational Operator6'
   *  RelationalOperator: '<S22>/Relational Operator7'
   *  UnitDelay: '<S22>/Unit Delay1'
   */
  rtb_LogicalOperator4 = ((swc_SCOO_ARID_DEF.UnitDelay1_DSTATE ==
    CruiseSts_e_ACTIVE) && (rtb_uDLookupTable > ccdc_v_vehSpdDiffMax_kph));

  /* Outputs for Atomic SubSystem: '<S22>/turnON_delay' */
  /* Constant: '<S22>/Constant22' incorporates:
   *  Constant: '<S22>/Constant21'
   */
  swc_SCOO_turnON_delay(rtb_LogicalOperator4, ccdc_tm_vehSpdDiffTmOut_s,
                        ((float32)CCD_TASK_INTERVAL_S), &rtb_flg_out,
                        &swc_SCOO_ARID_DEF.ARID_DEF_turnON_delay);

  /* End of Outputs for SubSystem: '<S22>/turnON_delay' */

  /* Logic: '<S22>/Logical Operator2' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Constant: '<S22>/Constant19'
   *  Constant: '<S22>/Constant2'
   *  Constant: '<S25>/Constant'
   *  Constant: '<S26>/Constant'
   *  Constant: '<S28>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion16'
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  Logic: '<S22>/Logical Operator3'
   *  Logic: '<S22>/Logical Operator5'
   *  Logic: '<S22>/Logical Operator6'
   *  RelationalOperator: '<S22>/Relational Operator1'
   *  RelationalOperator: '<S22>/Relational Operator3'
   *  RelationalOperator: '<S22>/Relational Operator4'
   *  RelationalOperator: '<S22>/Relational Operator5'
   */
  ccdd_b_crsEnaRaw = (ccdc_b_enaVehCrsCtrl && (ccdd_e_crsBtnErrSts ==
    CrsBtnErrSts_NONE) && swc_SCOO_ARID_DEF.DataTypeConversion1 &&
                      (!swc_SCOO_ARID_DEF.DataTypeConversion6) &&
                      (!swc_SCOO_ARID_DEF.DataTypeConversion8) &&
                      (swc_SCOO_ARID_DEF.DataTypeConversion9 <= ((uint8)1U)) &&
                      (swc_SCOO_ARID_DEF.DataTypeConversion16 ==
                       ParkingStatus_DISENGAGED) &&
                      (swc_SCOO_ARID_DEF.DataTypeConversion2 == DriveDir_FORWARD)
                      && true && swc_SCOO_ConstB.LogicalOperator1 &&
                      (!rtb_flg_out));

  /* Switch: '<S22>/Switch2' incorporates:
   *  Constant: '<S1>/Constant5'
   */
  ccdd_b_crsEna = (false && ccdd_b_crsEnaRaw);

  /* RelationalOperator: '<S7>/Relational Operator4' incorporates:
   *  Constant: '<S24>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   */
  rtb_RelationalOperator4_l = (swc_SCOO_ARID_DEF.DataTypeConversion4 ==
    BrakePedalStatus_PRESSED);

  /* RelationalOperator: '<S14>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S14>/Delay Input1'
   *
   * Block description for '<S14>/Delay Input1':
   *
   *  Store in Global RAM
   */
  ccdd_b_crsMainBtnPrsd = ((sint32)swc_SCOO_ARID_DEF.Butt_Cruise_Sts > (sint32)
    swc_SCOO_ARID_DEF.DelayInput1_DSTATE_p);

  /* Outputs for Atomic SubSystem: '<S6>/turnON_delay' */
  /* Constant: '<S6>/Constant22' incorporates:
   *  Constant: '<S6>/Constant21'
   */
  swc_SCOO_turnON_delay(swc_SCOO_ARID_DEF.Butt_Cruise_Sts, ccdc_tm_cnclBtnDly_s,
                        ((float32)CCD_TASK_INTERVAL_S), &rtb_flg_out_g,
                        &swc_SCOO_ARID_DEF.ARID_DEF_turnON_delay_c);

  /* End of Outputs for SubSystem: '<S6>/turnON_delay' */

  /* RelationalOperator: '<S15>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S15>/Delay Input1'
   *
   * Block description for '<S15>/Delay Input1':
   *
   *  Store in Global RAM
   */
  ccdd_b_crsCnclBtnPrsd = ((sint32)rtb_flg_out_g > (sint32)
    swc_SCOO_ARID_DEF.DelayInput1_DSTATE_e);

  /* RelationalOperator: '<S18>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S18>/Delay Input1'
   *
   * Block description for '<S18>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator = ((sint32)swc_SCOO_ARID_DEF.Butt_Accel_Sts >
    (sint32)swc_SCOO_ARID_DEF.DelayInput1_DSTATE_k);

  /* Chart: '<S11>/Chart' incorporates:
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  if (swc_SCOO_ARID_DEF.is_active_c13_vsl == 0U) {
    swc_SCOO_ARID_DEF.is_active_c13_vsl = 1U;
    swc_SCOO_ARID_DEF.is_c13_vsl = swc_SCOO_IN_Init;
    ccdd_b_crsAccelResBtnPrsd = swc_SCOO_ARID_DEF.Butt_Accel_Sts;
  } else if (swc_SCOO_ARID_DEF.is_c13_vsl == swc_SCOO_IN_Init) {
    tmp_1 = swc_SCOO_ARID_DEF.UnitDelay1_DSTATE_g;
    if (((tmp_1 == CrModeMngr_e_ACTIVE_KEEP) || (tmp_1 ==
          CrModeMngr_e_ACTIVE_RESUME) || (tmp_1 == CrModeMngr_e_OFF)) &&
        swc_SCOO_ARID_DEF.Butt_Accel_Sts) {
      swc_SCOO_ARID_DEF.is_c13_vsl = swc_SCOO_IN_RETOutput;
      ccdd_b_crsAccelResBtnPrsd = rtb_FixPtRelationalOperator;
    } else {
      ccdd_b_crsAccelResBtnPrsd = swc_SCOO_ARID_DEF.Butt_Accel_Sts;
    }
  } else {
    /* case IN_RETOutput: */
    tmp_1 = swc_SCOO_ARID_DEF.UnitDelay1_DSTATE_g;
    if (((tmp_1 != CrModeMngr_e_ACTIVE_KEEP) && (tmp_1 !=
          CrModeMngr_e_ACTIVE_RESUME) && (tmp_1 != CrModeMngr_e_OFF)) ||
        (!swc_SCOO_ARID_DEF.Butt_Accel_Sts)) {
      swc_SCOO_ARID_DEF.is_c13_vsl = swc_SCOO_IN_Init;
      ccdd_b_crsAccelResBtnPrsd = swc_SCOO_ARID_DEF.Butt_Accel_Sts;
    } else {
      ccdd_b_crsAccelResBtnPrsd = rtb_FixPtRelationalOperator;
    }
  }

  /* End of Chart: '<S11>/Chart' */

  /* RelationalOperator: '<S20>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S20>/Delay Input1'
   *
   * Block description for '<S20>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator = ((sint32)swc_SCOO_ARID_DEF.Butt_Coast_Sts >
    (sint32)swc_SCOO_ARID_DEF.DelayInput1_DSTATE_np);

  /* Chart: '<S13>/Chart' incorporates:
   *  UnitDelay: '<S13>/Unit Delay1'
   */
  if (swc_SCOO_ARID_DEF.is_active_c1_vsl == 0U) {
    swc_SCOO_ARID_DEF.is_active_c1_vsl = 1U;
    swc_SCOO_ARID_DEF.is_c1_vsl = swc_SCOO_IN_Init;
    ccdd_b_crsCoastSetBtnPrsd = swc_SCOO_ARID_DEF.Butt_Coast_Sts;
  } else if (swc_SCOO_ARID_DEF.is_c1_vsl == swc_SCOO_IN_Init) {
    tmp_1 = swc_SCOO_ARID_DEF.UnitDelay1_DSTATE_gm;
    if (((tmp_1 == CrModeMngr_e_ACTIVE_KEEP) || (tmp_1 ==
          CrModeMngr_e_ACTIVE_RESUME)) && swc_SCOO_ARID_DEF.Butt_Coast_Sts) {
      swc_SCOO_ARID_DEF.is_c1_vsl = swc_SCOO_IN_RETOutput;
      ccdd_b_crsCoastSetBtnPrsd = rtb_FixPtRelationalOperator;
    } else {
      ccdd_b_crsCoastSetBtnPrsd = swc_SCOO_ARID_DEF.Butt_Coast_Sts;
    }
  } else {
    /* case IN_RETOutput: */
    tmp_1 = swc_SCOO_ARID_DEF.UnitDelay1_DSTATE_gm;
    if (((tmp_1 != CrModeMngr_e_ACTIVE_KEEP) && (tmp_1 !=
          CrModeMngr_e_ACTIVE_RESUME)) || (!swc_SCOO_ARID_DEF.Butt_Coast_Sts)) {
      swc_SCOO_ARID_DEF.is_c1_vsl = swc_SCOO_IN_Init;
      ccdd_b_crsCoastSetBtnPrsd = swc_SCOO_ARID_DEF.Butt_Coast_Sts;
    } else {
      ccdd_b_crsCoastSetBtnPrsd = rtb_FixPtRelationalOperator;
    }
  }

  /* End of Chart: '<S13>/Chart' */

  /* Chart: '<S7>/CruiseStates' incorporates:
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/Constant10'
   *  Constant: '<S7>/Constant16'
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/Constant3'
   *  Constant: '<S7>/Constant5'
   *  Constant: '<S7>/Constant6'
   *  Constant: '<S7>/Constant7'
   *  Constant: '<S7>/Constant8'
   */
  if (swc_SCOO_ARID_DEF.is_active_c11_vsl == 0U) {
    swc_SCOO_ARID_DEF.is_active_c11_vsl = 1U;
    swc_SCOO_ARID_DEF.is_c11_vsl = swc_SCOO_IN_Cruise_Disabled;
    ccdd_e_crsCtrlSts = CruiseSts_e_OFF;
    ccdd_e_crsCtrlSpdMode = CrModeMngr_e_OFF;
    ccdd_v_crsCtrlTgtSpd_kph = 0.0F;
    ccdd_v_crsTgtSpdQuit_kph = 0.0F;
    swc_SCOO_ARID_DEF.time = 0.0F;
    swc_SCOO_ARID_DEF.Cruise_Speed_Dvl_Accum = 0.0F;
  } else {
    boolean guard1 = false;
    boolean guard2 = false;
    boolean guard3 = false;
    guard1 = false;
    guard2 = false;
    guard3 = false;
    switch (swc_SCOO_ARID_DEF.is_c11_vsl) {
     case swc_SCOO_IN_Cruise_Active:
      if (ccdd_b_crsCnclBtnPrsd || (!ccdd_b_crsEna)) {
        swc_SCOO_ARID_DEF.is_Cruise_Active_p = swc_SCOO_IN_NO_ACTIVE_CHILD_j;
        swc_SCOO_ARID_DEF.is_Cruise_Active = swc_SCOO_IN_NO_ACTIVE_CHILD_j;
        swc_SCOO_ARID_DEF.is_c11_vsl = swc_SCOO_IN_Cruise_Disabled;
        ccdd_e_crsCtrlSts = CruiseSts_e_OFF;
        ccdd_e_crsCtrlSpdMode = CrModeMngr_e_OFF;
        ccdd_v_crsCtrlTgtSpd_kph = 0.0F;
        ccdd_v_crsTgtSpdQuit_kph = 0.0F;
        swc_SCOO_ARID_DEF.time = 0.0F;
        swc_SCOO_ARID_DEF.Cruise_Speed_Dvl_Accum = 0.0F;
      } else if (ccdd_b_crsMainBtnPrsd || rtb_RelationalOperator4_l || false ||
                 ((ccdd_e_crsCtrlSts == CruiseSts_e_OVERRIDE) &&
                  (swc_SCOO_ARID_DEF.time >= ccdc_tm_accelOvrdMax_s))) {
        swc_SCOO_ARID_DEF.is_Cruise_Active_p = swc_SCOO_IN_NO_ACTIVE_CHILD_j;
        swc_SCOO_ARID_DEF.is_Cruise_Active = swc_SCOO_IN_NO_ACTIVE_CHILD_j;
        swc_SCOO_ARID_DEF.is_c11_vsl = swc_SCOO_IN_Cruise_Standby;
        swc_SCOO_ARID_DEF.Cruise_Sts_Prev = ccdd_e_crsCtrlSts;
        ccdd_e_crsCtrlSts = CruiseSts_e_STANDBY;
        ccdd_e_crsCtrlSpdMode = CrModeMngr_e_OFF;
        swc_SCOO_ARID_DEF.time = 0.0F;
        ccdd_v_crsTgtSpdQuit_kph = ccdd_v_crsCtrlTgtSpd_kph;
        ccdd_v_crsCtrlTgtSpd_kph = 0.0F;
        swc_SCOO_ARID_DEF.Cruise_Speed_Dvl_Accum = 0.0F;
      } else {
        switch (swc_SCOO_ARID_DEF.is_Cruise_Active) {
         case swc_SCOO_IN_Cruise_Active:
          if (ccdd_b_crsAccelResBtnPrsd && (swc_SCOO_ARID_DEF.time >= 0.02) &&
              (ccdd_v_crsCtrlTgtSpd_kph < ccdc_v_crsTgtSpdMax_kph)) {
            swc_SCOO_ARID_DEF.is_Cruise_Active_p = swc_SCOO_IN_NO_ACTIVE_CHILD_j;
            swc_SCOO_ARID_DEF.is_Cruise_Active = swc_SCOO_IN_Cruise_Speed_TipIn;
            ccdd_e_crsCtrlSts = CruiseSts_e_ACTIVE;
            ccdd_e_crsCtrlSpdMode = CrModeMngr_e_TIP_IN;
            swc_SCOO_ARID_DEF.time = 0.0F;
          } else if (ccdd_b_crsCoastSetBtnPrsd && (swc_SCOO_ARID_DEF.time >=
                      0.02) && (ccdd_v_crsCtrlTgtSpd_kph >
                                ccdc_v_crsTgtSpdMin_kph)) {
            swc_SCOO_ARID_DEF.is_Cruise_Active_p = swc_SCOO_IN_NO_ACTIVE_CHILD_j;
            swc_SCOO_ARID_DEF.is_Cruise_Active = swc_SCOO_IN_Cruise_Speed_TipOut;
            ccdd_e_crsCtrlSts = CruiseSts_e_ACTIVE;
            ccdd_e_crsCtrlSpdMode = CrModeMngr_e_TIP_OUT;
            swc_SCOO_ARID_DEF.time = 0.0F;
          } else if (swc_SCOO_ARID_DEF.is_Cruise_Active_p ==
                     swc_SCOO_IN_AccelOverride) {
            if (!ccdd_b_crsCtrlAccPedlOvrd) {
              swc_SCOO_ARID_DEF.is_Cruise_Active_p = swc_SCOO_IN_Active;
              ccdd_e_crsCtrlSts = CruiseSts_e_ACTIVE;
              swc_SCOO_ARID_DEF.time = 0.0F;
            } else {
              swc_SCOO_ARID_DEF.time = fminf(swc_SCOO_ARID_DEF.time + ((float32)
                CCD_TASK_INTERVAL_S), 5000.0F);
            }

            /* case IN_Active: */
          } else if (ccdd_b_crsCtrlAccPedlOvrd) {
            swc_SCOO_ARID_DEF.is_Cruise_Active_p = swc_SCOO_IN_AccelOverride;
            ccdd_e_crsCtrlSts = CruiseSts_e_OVERRIDE;
            swc_SCOO_ARID_DEF.time = 0.0F;
          } else {
            swc_SCOO_ARID_DEF.time = fminf(swc_SCOO_ARID_DEF.time + ((float32)
              CCD_TASK_INTERVAL_S), 5000.0F);
          }
          break;

         case sw_IN_Cruise_Speed_Deceleration:
          if ((!ccdd_b_crsCoastSetBtnPrsd) || (ccdd_v_crsCtrlTgtSpd_kph ==
               ccdc_v_crsTgtSpdMin_kph) ||
              (swc_SCOO_ARID_DEF.Cruise_Speed_Dvl_Accum >=
               ccdc_v_crsTgtSpdChngMax_kph)) {
            swc_SCOO_ARID_DEF.Cruise_Speed_Dvl_Accum = 0.0F;
            ccdd_e_crsCtrlSpdMode = CrModeMngr_e_ACTIVE_KEEP;

            /* Reset cruise speed increment/decrement accumulator */
            swc_SCOO_ARID_DEF.is_Cruise_Active = swc_SCOO_IN_Cruise_Active;
            swc_SCOO_ARID_DEF.is_Cruise_Active_p = swc_SCOO_IN_Active;
            ccdd_e_crsCtrlSts = CruiseSts_e_ACTIVE;
            swc_SCOO_ARID_DEF.time = 0.0F;
          } else if (swc_SCOO_ARID_DEF.time >= ccdc_tm_crsSpdUpdtDly_s) {
            swc_SCOO_ARID_DEF.is_Cruise_Active = sw_IN_Cruise_Speed_Deceleration;
            swc_SCOO_ARID_DEF.time = 0.0F;
            ccdd_e_crsCtrlSts = CruiseSts_e_ACTIVE;
            ccdd_e_crsCtrlSpdMode = CrModeMngr_e_DECEL;
            ccdd_v_crsCtrlTgtSpd_kph = fmaxf(ccdd_v_crsCtrlTgtSpd_kph -
              ccdc_v_crsSpdLargeChng_kph, ccdc_v_crsTgtSpdMin_kph);
            swc_SCOO_ARID_DEF.Cruise_Speed_Dvl_Accum +=
              ccdc_v_crsSpdLargeChng_kph;
          } else {
            swc_SCOO_ARID_DEF.time = fminf(swc_SCOO_ARID_DEF.time + ((float32)
              CCD_TASK_INTERVAL_S), 5000.0F);
          }
          break;

         case IN_Cruise_Speed_Inc_Acceleratio:
          if ((!ccdd_b_crsAccelResBtnPrsd) || (ccdd_v_crsCtrlTgtSpd_kph ==
               ccdc_v_crsTgtSpdMax_kph) ||
              (swc_SCOO_ARID_DEF.Cruise_Speed_Dvl_Accum >=
               ccdc_v_crsTgtSpdChngMax_kph)) {
            swc_SCOO_ARID_DEF.Cruise_Speed_Dvl_Accum = 0.0F;
            ccdd_e_crsCtrlSpdMode = CrModeMngr_e_ACTIVE_KEEP;

            /* Reset cruise speed increment/decrement accumulator */
            swc_SCOO_ARID_DEF.is_Cruise_Active = swc_SCOO_IN_Cruise_Active;
            swc_SCOO_ARID_DEF.is_Cruise_Active_p = swc_SCOO_IN_Active;
            ccdd_e_crsCtrlSts = CruiseSts_e_ACTIVE;
            swc_SCOO_ARID_DEF.time = 0.0F;
          } else if (swc_SCOO_ARID_DEF.time >= ccdc_tm_crsSpdUpdtDly_s) {
            swc_SCOO_ARID_DEF.is_Cruise_Active = IN_Cruise_Speed_Inc_Acceleratio;
            swc_SCOO_ARID_DEF.time = 0.0F;
            ccdd_e_crsCtrlSts = CruiseSts_e_ACTIVE;
            ccdd_e_crsCtrlSpdMode = CrModeMngr_e_ACCEL;
            ccdd_v_crsCtrlTgtSpd_kph = fminf(ccdd_v_crsCtrlTgtSpd_kph +
              ccdc_v_crsSpdLargeChng_kph, ccdc_v_crsTgtSpdMax_kph);
            swc_SCOO_ARID_DEF.Cruise_Speed_Dvl_Accum +=
              ccdc_v_crsSpdLargeChng_kph;
          } else {
            swc_SCOO_ARID_DEF.time = fminf(swc_SCOO_ARID_DEF.time + ((float32)
              CCD_TASK_INTERVAL_S), 5000.0F);
          }
          break;

         case swc_SCOO_IN_Cruise_Speed_TipIn:
          if (swc_SCOO_ARID_DEF.time >= ccdc_tm_crsBtnLongPrs_s) {
            swc_SCOO_ARID_DEF.is_Cruise_Active = IN_Cruise_Speed_Inc_Acceleratio;
            swc_SCOO_ARID_DEF.time = 0.0F;
            ccdd_e_crsCtrlSts = CruiseSts_e_ACTIVE;
            ccdd_e_crsCtrlSpdMode = CrModeMngr_e_ACCEL;
            ccdd_v_crsCtrlTgtSpd_kph = fminf(ccdd_v_crsCtrlTgtSpd_kph +
              ccdc_v_crsSpdLargeChng_kph, ccdc_v_crsTgtSpdMax_kph);
            swc_SCOO_ARID_DEF.Cruise_Speed_Dvl_Accum +=
              ccdc_v_crsSpdLargeChng_kph;
          } else if (((!ccdd_b_crsAccelResBtnPrsd) || (ccdd_v_crsCtrlTgtSpd_kph >=
            ccdc_v_crsTgtSpdMax_kph)) && (swc_SCOO_ARID_DEF.time >= 0.02)) {
            ccdd_v_crsCtrlTgtSpd_kph = fminf(ccdd_v_crsCtrlTgtSpd_kph +
              ccdc_v_crsSpdTipChng_kph, ccdc_v_crsTgtSpdMax_kph);
            ccdd_e_crsCtrlSpdMode = CrModeMngr_e_ACTIVE_KEEP;
            swc_SCOO_ARID_DEF.is_Cruise_Active = swc_SCOO_IN_Cruise_Active;
            swc_SCOO_ARID_DEF.is_Cruise_Active_p = swc_SCOO_IN_Active;
            ccdd_e_crsCtrlSts = CruiseSts_e_ACTIVE;
            swc_SCOO_ARID_DEF.time = 0.0F;
          } else {
            swc_SCOO_ARID_DEF.time = fminf(swc_SCOO_ARID_DEF.time + ((float32)
              CCD_TASK_INTERVAL_S), 5000.0F);
          }
          break;

         default:
          /* case IN_Cruise_Speed_TipOut: */
          if (swc_SCOO_ARID_DEF.time >= ccdc_tm_crsBtnLongPrs_s) {
            swc_SCOO_ARID_DEF.is_Cruise_Active = sw_IN_Cruise_Speed_Deceleration;
            swc_SCOO_ARID_DEF.time = 0.0F;
            ccdd_e_crsCtrlSts = CruiseSts_e_ACTIVE;
            ccdd_e_crsCtrlSpdMode = CrModeMngr_e_DECEL;
            ccdd_v_crsCtrlTgtSpd_kph = fmaxf(ccdd_v_crsCtrlTgtSpd_kph -
              ccdc_v_crsSpdLargeChng_kph, ccdc_v_crsTgtSpdMin_kph);
            swc_SCOO_ARID_DEF.Cruise_Speed_Dvl_Accum +=
              ccdc_v_crsSpdLargeChng_kph;
          } else if (((!ccdd_b_crsCoastSetBtnPrsd) || (ccdd_v_crsCtrlTgtSpd_kph <=
            ccdc_v_crsTgtSpdMin_kph)) && (swc_SCOO_ARID_DEF.time >= 0.02)) {
            ccdd_v_crsCtrlTgtSpd_kph = fmaxf(ccdd_v_crsCtrlTgtSpd_kph -
              ccdc_v_crsSpdTipChng_kph, ccdc_v_crsTgtSpdMin_kph);
            ccdd_e_crsCtrlSpdMode = CrModeMngr_e_ACTIVE_KEEP;
            swc_SCOO_ARID_DEF.is_Cruise_Active = swc_SCOO_IN_Cruise_Active;
            swc_SCOO_ARID_DEF.is_Cruise_Active_p = swc_SCOO_IN_Active;
            ccdd_e_crsCtrlSts = CruiseSts_e_ACTIVE;
            swc_SCOO_ARID_DEF.time = 0.0F;
          } else {
            swc_SCOO_ARID_DEF.time = fminf(swc_SCOO_ARID_DEF.time + ((float32)
              CCD_TASK_INTERVAL_S), 5000.0F);
          }
          break;
        }
      }
      break;

     case swc_SCOO_IN_Cruise_Disabled:
      if (ccdd_b_crsMainBtnPrsd && (swc_SCOO_ARID_DEF.time >= 0.02) &&
          ccdd_b_crsEna) {
        swc_SCOO_ARID_DEF.is_c11_vsl = swc_SCOO_IN_Cruise_Standby;
        swc_SCOO_ARID_DEF.Cruise_Sts_Prev = ccdd_e_crsCtrlSts;
        ccdd_e_crsCtrlSts = CruiseSts_e_STANDBY;
        ccdd_e_crsCtrlSpdMode = CrModeMngr_e_OFF;
        swc_SCOO_ARID_DEF.time = 0.0F;
        ccdd_v_crsTgtSpdQuit_kph = ccdd_v_crsCtrlTgtSpd_kph;
        ccdd_v_crsCtrlTgtSpd_kph = 0.0F;
        swc_SCOO_ARID_DEF.Cruise_Speed_Dvl_Accum = 0.0F;
      } else {
        swc_SCOO_ARID_DEF.time = fminf(swc_SCOO_ARID_DEF.time + ((float32)
          CCD_TASK_INTERVAL_S), 5000.0F);
      }
      break;

     default:
      /* case IN_Cruise_Standby: */
      if ((swc_SCOO_ARID_DEF.time >= 0.02) && (!rtb_RelationalOperator4_l) &&
          (!false) && (swc_SCOO_ARID_DEF.DataTypeConversion5 <=
                       ccdc_v_vehSpdMaxEnaCrs_kph) &&
          (swc_SCOO_ARID_DEF.DataTypeConversion5 >= ccdc_v_vehSpdMinEnaCrs_kph))
      {
        if (ccdd_b_crsAccelResBtnPrsd) {
          if (ccdd_v_crsTgtSpdQuit_kph != 0.0F) {
            ccdd_v_crsCtrlTgtSpd_kph = ccdd_v_crsTgtSpdQuit_kph;
            ccdd_e_crsCtrlSpdMode = CrModeMngr_e_ACTIVE_RESUME;
            guard2 = true;
          } else {
            guard3 = true;
          }
        } else if (ccdd_b_crsCoastSetBtnPrsd) {
          guard3 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;
    }

    if (guard3) {
      ccdd_v_crsCtrlTgtSpd_kph = (float32)(floorf
        (swc_SCOO_ARID_DEF.DataTypeConversion5) + 0.5);
      ccdd_v_crsTgtSpdQuit_kph = 0.0F;
      ccdd_e_crsCtrlSpdMode = CrModeMngr_e_ACTIVE_KEEP;
      guard2 = true;
    }

    if (guard2) {
      swc_SCOO_ARID_DEF.is_c11_vsl = swc_SCOO_IN_Cruise_Active;
      swc_SCOO_ARID_DEF.is_Cruise_Active = swc_SCOO_IN_Cruise_Active;
      swc_SCOO_ARID_DEF.is_Cruise_Active_p = swc_SCOO_IN_Active;
      ccdd_e_crsCtrlSts = CruiseSts_e_ACTIVE;
      swc_SCOO_ARID_DEF.time = 0.0F;
    }

    if (guard1) {
      if ((ccdd_b_crsMainBtnPrsd && (swc_SCOO_ARID_DEF.time >= 0.02)) ||
          (ccdd_b_crsCnclBtnPrsd && ((swc_SCOO_ARID_DEF.Cruise_Sts_Prev !=
             CruiseSts_e_OFF) || (swc_SCOO_ARID_DEF.time >= 1.0F))) ||
          (!ccdd_b_crsEna)) {
        swc_SCOO_ARID_DEF.is_c11_vsl = swc_SCOO_IN_Cruise_Disabled;
        ccdd_e_crsCtrlSts = CruiseSts_e_OFF;
        ccdd_e_crsCtrlSpdMode = CrModeMngr_e_OFF;
        ccdd_v_crsCtrlTgtSpd_kph = 0.0F;
        ccdd_v_crsTgtSpdQuit_kph = 0.0F;
        swc_SCOO_ARID_DEF.time = 0.0F;
        swc_SCOO_ARID_DEF.Cruise_Speed_Dvl_Accum = 0.0F;
      } else {
        swc_SCOO_ARID_DEF.time = fminf(swc_SCOO_ARID_DEF.time + ((float32)
          CCD_TASK_INTERVAL_S), 5000.0F);
      }
    }
  }

  /* End of Chart: '<S7>/CruiseStates' */

  /* Switch: '<S5>/Switch1' incorporates:
   *  Constant: '<S27>/Constant'
   *  RelationalOperator: '<S22>/Relational Operator6'
   *  RelationalOperator: '<S5>/Relational Operator6'
   */
  if (ccdd_e_crsCtrlSts == CruiseSts_e_ACTIVE) {
    /* Switch: '<S5>/Switch1' */
    ccdd_x_accPedlPosVirt_pct = ccdd_x_accPedlPosVirtRaw_pct;
  } else {
    /* Switch: '<S5>/Switch1' */
    ccdd_x_accPedlPosVirt_pct = swc_SCOO_ARID_DEF.DataTypeConversion7;
  }

  /* End of Switch: '<S5>/Switch1' */

  /* DataTypeConversion: '<S66>/Data Type Conversion5' incorporates:
   *  Constant: '<S38>/Constant'
   *  RelationalOperator: '<S35>/Relational Operator3'
   */
  rtb_RelationalOperator4_l = (ccdd_e_crsCtrlSts == CruiseSts_e_OVERRIDE);

  /* Logic: '<S35>/Logical Operator' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S35>/Constant2'
   *  Logic: '<S35>/Logical Operator2'
   *  RelationalOperator: '<S22>/Relational Operator6'
   *  RelationalOperator: '<S35>/Relational Operator6'
   */
  ccdd_b_crsSpdCtrlEnad = (ccdc_b_enaVehCrsCtrl && ((ccdd_e_crsCtrlSts ==
    CruiseSts_e_ACTIVE) || rtb_RelationalOperator4_l));

  /* Outputs for Enabled SubSystem: '<S37>/BaselineControl' incorporates:
   *  EnablePort: '<S46>/Enable'
   */
  /* Sum: '<S35>/Sum' incorporates:
   *  Sum: '<S51>/Add'
   *  Sum: '<S76>/Sum'
   */
  rtb_Sum_tmp = ccdd_v_crsCtrlTgtSpd_kph - swc_SCOO_ARID_DEF.DataTypeConversion5;

  /* End of Outputs for SubSystem: '<S37>/BaselineControl' */

  /* Sum: '<S35>/Sum' */
  rtb_Sum = rtb_Sum_tmp;

  /* If: '<S40>/If' incorporates:
   *  Constant: '<S40>/Constant'
   */
  if (rtb_Sum >= 0.0F) {
    /* Outputs for IfAction SubSystem: '<S40>/pos' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    swc_SCOO_pos(rtb_Sum, &rtb_uDLookupTable);

    /* End of Outputs for SubSystem: '<S40>/pos' */
  } else {
    /* Outputs for IfAction SubSystem: '<S40>/neg' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    swc_SCOO_neg(rtb_Sum, &rtb_uDLookupTable);

    /* End of Outputs for SubSystem: '<S40>/neg' */
  }

  /* End of If: '<S40>/If' */

  /* Relay: '<S35>/Relay4' */
  swc_SCOO_ARID_DEF.Relay4_Mode_g = ((rtb_uDLookupTable >=
    ccdc_v_vehSpdErrIntglEnagHi_kph) || ((rtb_uDLookupTable >
    ccdc_v_vehSpdErrIntglEnagLo_kph) && swc_SCOO_ARID_DEF.Relay4_Mode_g));
  if (swc_SCOO_ARID_DEF.Relay4_Mode_g) {
    tmp = ((uint8)0U);
  } else {
    tmp = ((uint8)1U);
  }

  /* Logic: '<S35>/Logical Operator1' incorporates:
   *  DataTypeConversion: '<S35>/Data Type Conversion5'
   *  Logic: '<S35>/Logical Operator3'
   *  Relay: '<S35>/Relay4'
   */
  ccdd_b_crsSpdCtrlIntglEnad = (ccdd_b_crsSpdCtrlEnad &&
    (!rtb_RelationalOperator4_l) && (tmp != 0));

  /* Outputs for Enabled SubSystem: '<S37>/BaselineControl' incorporates:
   *  EnablePort: '<S46>/Enable'
   */
  /* Logic: '<S37>/Logical Operator' incorporates:
   *  Constant: '<S37>/Constant9'
   */
  if (ccdc_b_crsCtrlBaseLineEna && ccdd_b_crsSpdCtrlEnad) {
    /* Lookup_n-D: '<S76>/1-D Lookup Table' */
    ccdd_tq_crsSpdCtrlFF_Nm = look1_iflf_binlcapw(ccdd_v_crsCtrlTgtSpd_kph, (
      const float32 *)&ccda_crsSpdCtrl_X_VehSpd_kph[0], (const float32 *)
      &ccdf_crsSpdCtrlFF_Y_Nm[0], 9U);

    /* Lookup_n-D: '<S76>/1-D Lookup Table1' */
    ccdd_fact_crsSpdCtrlKi = look1_iflf_binlcapw(rtb_Sum_tmp, (const float32 *)
      &ccda_crsSpdCtrl_Y_VehSpdErr_kph[0], (const float32 *)
      &ccdf_crsSpdCtrlKi_Y_fact[0], 10U);

    /* Lookup_n-D: '<S76>/1-D Lookup Table2' */
    ccdd_fact_crsSpdCtrlKp = look1_iflf_binlcapw(rtb_Sum_tmp, (const float32 *)
      &ccda_crsSpdCtrl_Y_VehSpdErr_kph[0], (const float32 *)
      &ccdf_crsSpdCtrlKp_Y_fact[0], 10U);

    /* Logic: '<S46>/Logical Operator' */
    swc_SCOO_ARID_DEF.LogicalOperator_i = !ccdd_b_crsSpdCtrlIntglEnad;

    /* Outputs for Atomic SubSystem: '<S46>/PID_FeedForward' */
    swc_SCOO_PID_FeedForward_d();

    /* End of Outputs for SubSystem: '<S46>/PID_FeedForward' */
  }

  /* End of Logic: '<S37>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S37>/BaselineControl' */

  /* Lookup_n-D: '<S66>/1-D Lookup Table' incorporates:
   *  Sum: '<S63>/Diff'
   *  UnitDelay: '<S63>/UD'
   *
   * Block description for '<S63>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S63>/UD':
   *
   *  Store in Global RAM
   */
  rtb_uDLookupTable = ccdd_v_crsCtrlTgtSpd_kph - swc_SCOO_ARID_DEF.UD_DSTATE;

  /* InitialCondition: '<S60>/IC' */
  if (swc_SCOO_ARID_DEF.IC_FirstOutputTime) {
    swc_SCOO_ARID_DEF.IC_FirstOutputTime = false;

    /* Lookup_n-D: '<S66>/1-D Lookup Table' */
    rtb_uDLookupTable = 0.0F;
  }

  /* End of InitialCondition: '<S60>/IC' */

  /* Product: '<S60>/Divide1' incorporates:
   *  Constant: '<S60>/Constant2'
   *  Gain: '<S60>/Gain'
   */
  ccdd_acc_vehAccSP_mps2 = 0.277777791F * rtb_uDLookupTable / ((float32)
    CCD_TASK_INTERVAL_S);

  /* Lookup_n-D: '<S66>/1-D Lookup Table' incorporates:
   *  Abs: '<S53>/Abs'
   */
  rtb_uDLookupTable = fabsf(ccdd_acc_vehAccSP_mps2);

  /* RelationalOperator: '<S53>/Relational Operator' incorporates:
   *  Constant: '<S53>/Constant1'
   */
  rtb_RelationalOperator4_l = (rtb_uDLookupTable > ccdc_acc_vehAccLongMin_mps2);

  /* Outputs for Atomic SubSystem: '<S53>/turnON_delay' */
  /* Saturate: '<S62>/Saturation' incorporates:
   *  Constant: '<S53>/Constant4'
   */
  if (ccdc_tm_vehAccLongActvWait_s > 1.6777216E+7F) {
    /* Saturate: '<S62>/Saturation' */
    rtb_Sum_m = 1.6777216E+7F;
  } else if (ccdc_tm_vehAccLongActvWait_s < 0.0F) {
    /* Saturate: '<S62>/Saturation' */
    rtb_Sum_m = 0.0F;
  } else {
    /* Saturate: '<S62>/Saturation' */
    rtb_Sum_m = ccdc_tm_vehAccLongActvWait_s;
  }

  /* End of Saturate: '<S62>/Saturation' */

  /* Chart: '<S62>/timed_delay' incorporates:
   *  Constant: '<S53>/Constant3'
   *  DataTypeConversion: '<S62>/Data Type Conversion'
   */
  if (swc_SCOO_ARID_DEF.is_active_c14_Ricardo_SW_dev__l == 0U) {
    swc_SCOO_ARID_DEF.is_active_c14_Ricardo_SW_dev__l = 1U;
    if (rtb_RelationalOperator4_l) {
      swc_SCOO_ARID_DEF.is_c14_Ricardo_SW_dev_lib_g = swc_SCOO_IN_ON_j;
      ccdd_b_vehAccTgtLongActv = true;
    } else {
      swc_SCOO_ARID_DEF.is_c14_Ricardo_SW_dev_lib_g = swc_SCOO_IN_OFF_a;
      ccdd_b_vehAccTgtLongActv = false;
    }
  } else {
    switch (swc_SCOO_ARID_DEF.is_c14_Ricardo_SW_dev_lib_g) {
     case swc_SCOO_IN_OFF_a:
      if (rtb_RelationalOperator4_l) {
        if (rtb_Sum_m == 0.0F) {
          swc_SCOO_ARID_DEF.is_c14_Ricardo_SW_dev_lib_g = swc_SCOO_IN_ON_j;
          ccdd_b_vehAccTgtLongActv = true;
        } else {
          swc_SCOO_ARID_DEF.is_c14_Ricardo_SW_dev_lib_g = swc_SCOO_IN_ON_WAIT_n;
          swc_SCOO_ARID_DEF.t_wait_j = ((float32)CCD_TASK_INTERVAL_S);
          ccdd_b_vehAccTgtLongActv = false;
        }
      } else {
        ccdd_b_vehAccTgtLongActv = false;
      }
      break;

     case swc_SCOO_IN_ON_j:
      if (!rtb_RelationalOperator4_l) {
        swc_SCOO_ARID_DEF.is_c14_Ricardo_SW_dev_lib_g = swc_SCOO_IN_OFF_a;
        ccdd_b_vehAccTgtLongActv = false;
      } else {
        ccdd_b_vehAccTgtLongActv = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtb_RelationalOperator4_l) {
        swc_SCOO_ARID_DEF.is_c14_Ricardo_SW_dev_lib_g = swc_SCOO_IN_OFF_a;
        ccdd_b_vehAccTgtLongActv = false;
      } else if (swc_SCOO_ARID_DEF.t_wait_j > rtb_Sum_m - ((float32)
                  CCD_TASK_INTERVAL_S)) {
        swc_SCOO_ARID_DEF.is_c14_Ricardo_SW_dev_lib_g = swc_SCOO_IN_ON_j;
        ccdd_b_vehAccTgtLongActv = true;
      } else {
        swc_SCOO_ARID_DEF.t_wait_j += ((float32)CCD_TASK_INTERVAL_S);
        ccdd_b_vehAccTgtLongActv = false;
      }
      break;
    }
  }

  /* End of Chart: '<S62>/timed_delay' */
  /* End of Outputs for SubSystem: '<S53>/turnON_delay' */

  /* Switch: '<S61>/Switch' incorporates:
   *  Switch: '<S53>/Switch1'
   *  UnitDelay: '<S61>/init'
   */
  if (swc_SCOO_ARID_DEF.init_DSTATE_d) {
    /* Switch: '<S53>/Switch1' */
    if (ccdd_b_vehAccTgtLongActv) {
      /* Lookup_n-D: '<S66>/1-D Lookup Table' */
      rtb_uDLookupTable = ccdd_acc_vehAccSP_mps2;
    } else {
      /* Lookup_n-D: '<S66>/1-D Lookup Table' incorporates:
       *  Constant: '<S53>/Constant2'
       */
      rtb_uDLookupTable = 0.0F;
    }
  } else {
    if (ccdd_b_vehAccTgtLongActv) {
      /* Switch: '<S53>/Switch1' */
      rtb_Sum_m = ccdd_acc_vehAccSP_mps2;
    } else {
      /* Switch: '<S53>/Switch1' incorporates:
       *  Constant: '<S53>/Constant2'
       */
      rtb_Sum_m = 0.0F;
    }

    /* Lookup_n-D: '<S66>/1-D Lookup Table' incorporates:
     *  Constant: '<S53>/Constant5'
     *  Constant: '<S53>/Constant6'
     *  Constant: '<S53>/Constant7'
     *  Constant: '<S61>/step_time6'
     *  MinMax: '<S61>/MinMax'
     *  MinMax: '<S61>/MinMax1'
     *  MinMax: '<S61>/MinMax2'
     *  MinMax: '<S61>/MinMax3'
     *  Product: '<S61>/Product'
     *  Product: '<S61>/Product1'
     *  Sum: '<S61>/Sum5'
     *  Sum: '<S61>/Sum6'
     *  Switch: '<S53>/Switch1'
     *  UnitDelay: '<S61>/Unit Delay'
     */
    rtb_uDLookupTable = fminf(fmaxf(ccdc_dacc_vehAccLongInc_mps3 * ((float32)
      CCD_TASK_INTERVAL_S), 0.0F), fmaxf(rtb_Sum_m -
      swc_SCOO_ARID_DEF.UnitDelay_DSTATE_a, fminf(0.0F, ((float32)
      CCD_TASK_INTERVAL_S) * ccdc_dacc_vehAccLongDec_mps3))) +
      swc_SCOO_ARID_DEF.UnitDelay_DSTATE_a;
  }

  /* End of Switch: '<S61>/Switch' */

  /* DataTypeConversion: '<S61>/Data Type Conversion' */
  ccdd_acc_vehAccTgtLong_mps2 = rtb_uDLookupTable;

  /* Sum: '<S51>/Add' */
  ccdd_v_vehSpdErr_kph = rtb_Sum_tmp;

  /* Lookup_n-D: '<S51>/1-D Lookup Table1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   *  Sum: '<S51>/Add'
   */
  ccdd_fact_crsCtrlAccKp = look2_iflf_binlcapw
    (swc_SCOO_ARID_DEF.DataTypeConversion5, ccdd_v_vehSpdErr_kph, (const float32
      *)&ccdm_crsCtrlAccKp_Y_VehSpdAct_kph[0], (const float32 *)
     &ccdm_crsCtrlAccKp_X_VehSpdErr_kph[0], (const float32 *)
     &ccdm_crsCtrlAccKp_Z_fact[0], swc_SCOO_ConstP.pooled9, 17U);

  /* Lookup_n-D: '<S51>/1-D Lookup Table2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   *  Sum: '<S51>/Add'
   */
  ccdd_fact_crsCtrlAccKi = look2_iflf_binlcapw
    (swc_SCOO_ARID_DEF.DataTypeConversion5, ccdd_v_vehSpdErr_kph, (const float32
      *)&ccdm_crsCtrlAccKi_Y_VehSpdAct_kph[0], (const float32 *)
     &ccdm_crsCtrlAccKi_X_VehSpdErr_kph[0], (const float32 *)
     &ccdm_crsCtrlAccKi_Z_fact[0], swc_SCOO_ConstP.pooled9, 17U);

  /* Relay: '<S51>/Relay4' */
  swc_SCOO_ARID_DEF.Relay4_Mode_n = ((ccdd_v_vehSpdErr_kph >=
    ccdc_v_accKiEnaVehSpdErrHi_kph) || ((ccdd_v_vehSpdErr_kph >
    ccdc_v_accKiEnaVehSpdErrLo_kph) && swc_SCOO_ARID_DEF.Relay4_Mode_n));

  /* Switch: '<S51>/Switch' incorporates:
   *  Constant: '<S51>/Constant9'
   *  Relay: '<S51>/Relay4'
   */
  if (ccdc_b_crsCtrlAccKiEna_ovrdflg) {
    /* Switch: '<S51>/Switch' incorporates:
     *  Constant: '<S51>/Constant1'
     */
    ccdd_b_crsCtrlAccKiEna = ccdc_b_crsCtrlAccKiEna_ovrdval;
  } else {
    if (swc_SCOO_ARID_DEF.Relay4_Mode_n) {
      /* Relay: '<S51>/Relay4' */
      tmp = ((uint8)0U);
    } else {
      /* Relay: '<S51>/Relay4' */
      tmp = ((uint8)1U);
    }

    /* Switch: '<S51>/Switch' incorporates:
     *  Constant: '<S38>/Constant'
     *  DataTypeConversion: '<S51>/Data Type Conversion5'
     *  Logic: '<S51>/Logical Operator'
     *  RelationalOperator: '<S35>/Relational Operator3'
     *  RelationalOperator: '<S35>/Relational Operator6'
     *  RelationalOperator: '<S51>/Relational Operator3'
     *  Relay: '<S51>/Relay4'
     */
    ccdd_b_crsCtrlAccKiEna = ((tmp != 0) && ccdd_b_crsSpdCtrlEnad &&
      (ccdd_e_crsCtrlSts != CruiseSts_e_OVERRIDE) &&
      swc_SCOO_ConstB.LogicalOperator1_e);
  }

  /* End of Switch: '<S51>/Switch' */

  /* Logic: '<S48>/Logical Operator' */
  swc_SCOO_ARID_DEF.LogicalOperator_l = !ccdd_b_crsCtrlAccKiEna;

  /* Outputs for Atomic SubSystem: '<S48>/PID_FeedForward' */
  swc_SCOO_PID_FeedForward();

  /* End of Outputs for SubSystem: '<S48>/PID_FeedForward' */

  /* Logic: '<S47>/Logical Operator3' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  ccdd_b_accCtrlActv = (false && ccdd_b_crsSpdCtrlEnad);

  /* Switch: '<S47>/Switch3' incorporates:
   *  Switch: '<S47>/Switch2'
   */
  if (ccdd_b_accCtrlActv) {
    /* Switch: '<S47>/Switch3' incorporates:
     *  Constant: '<S1>/Constant2'
     *  MinMax: '<S47>/Min'
     */
    rtb_Sum_m = fminf(ccdd_acc_intAccTgt_mps2, 0.0F);
  } else if (ccdd_b_crsSpdCtrlEnad) {
    /* Switch: '<S47>/Switch2' incorporates:
     *  Switch: '<S47>/Switch3'
     */
    rtb_Sum_m = ccdd_acc_intAccTgt_mps2;
  } else {
    /* Switch: '<S47>/Switch3' incorporates:
     *  Constant: '<S1>/Constant2'
     *  Switch: '<S47>/Switch2'
     *  Switch: '<S47>/Switch4'
     */
    rtb_Sum_m = 0.0F;
  }

  /* End of Switch: '<S47>/Switch3' */

  /* Switch: '<S50>/Switch' incorporates:
   *  UnitDelay: '<S50>/init'
   */
  if (swc_SCOO_ARID_DEF.init_DSTATE_k) {
    /* Lookup_n-D: '<S66>/1-D Lookup Table' */
    rtb_uDLookupTable = rtb_Sum_m;
  } else {
    /* Lookup_n-D: '<S66>/1-D Lookup Table' incorporates:
     *  Constant: '<S47>/Constant3'
     *  Constant: '<S47>/Constant4'
     *  Constant: '<S47>/Constant6'
     *  Constant: '<S50>/step_time6'
     *  MinMax: '<S50>/MinMax'
     *  MinMax: '<S50>/MinMax1'
     *  MinMax: '<S50>/MinMax2'
     *  MinMax: '<S50>/MinMax3'
     *  Product: '<S50>/Product'
     *  Product: '<S50>/Product1'
     *  Sum: '<S50>/Sum5'
     *  Sum: '<S50>/Sum6'
     *  UnitDelay: '<S50>/Unit Delay'
     */
    rtb_uDLookupTable = fminf(fmaxf(ccc_dacc_accTgtMaxRate_mps3 * ((float32)
      CCD_TASK_INTERVAL_S), 0.0F), fmaxf(rtb_Sum_m -
      swc_SCOO_ARID_DEF.UnitDelay_DSTATE_d, fminf(0.0F, ((float32)
      CCD_TASK_INTERVAL_S) * ccc_dacc_accTgtMinRate_mps3))) +
      swc_SCOO_ARID_DEF.UnitDelay_DSTATE_d;
  }

  /* End of Switch: '<S50>/Switch' */

  /* DataTypeConversion: '<S50>/Data Type Conversion' */
  ccdd_acc_vehAccTgt_mps2 = rtb_uDLookupTable;

  /* Lookup_n-D: '<S66>/1-D Lookup Table' incorporates:
   *  Sum: '<S69>/Diff'
   *  UnitDelay: '<S69>/UD'
   *
   * Block description for '<S69>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S69>/UD':
   *
   *  Store in Global RAM
   */
  rtb_uDLookupTable = swc_SCOO_ARID_DEF.DataTypeConversion5 -
    swc_SCOO_ARID_DEF.UD_DSTATE_g;

  /* InitialCondition: '<S65>/IC' */
  if (swc_SCOO_ARID_DEF.IC_FirstOutputTime_o) {
    swc_SCOO_ARID_DEF.IC_FirstOutputTime_o = false;

    /* Lookup_n-D: '<S66>/1-D Lookup Table' */
    rtb_uDLookupTable = 0.0F;
  }

  /* End of InitialCondition: '<S65>/IC' */

  /* Product: '<S65>/Divide' incorporates:
   *  Constant: '<S65>/Constant5'
   *  Gain: '<S65>/Gain'
   */
  ccdd_acc_vehAccActRaw_mps2 = 0.277777791F * rtb_uDLookupTable / ((float32)
    CCD_TASK_INTERVAL_S);

  /* Switch: '<S68>/Switch' incorporates:
   *  UnitDelay: '<S68>/init'
   */
  if (swc_SCOO_ARID_DEF.init_DSTATE_h) {
    /* Lookup_n-D: '<S66>/1-D Lookup Table' incorporates:
     *  DataTypeConversion: '<S68>/Data Type Conversion'
     */
    rtb_uDLookupTable = ccdd_acc_vehAccActRaw_mps2;
  } else {
    /* Product: '<S68>/Divide' incorporates:
     *  Constant: '<S65>/Constant1'
     *  Constant: '<S65>/Constant4'
     *  DataTypeConversion: '<S68>/Data Type Conversion1'
     *  DataTypeConversion: '<S68>/Data Type Conversion2'
     *  Sum: '<S68>/Add1'
     */
    rtb_Sum_m = ccdc_t_vehAccActTau_s / (ccdc_t_vehAccActTau_s + ((float32)
      CCD_TASK_INTERVAL_S));

    /* Lookup_n-D: '<S66>/1-D Lookup Table' incorporates:
     *  Constant: '<S68>/Constant'
     *  DataTypeConversion: '<S68>/Data Type Conversion'
     *  Product: '<S68>/Product'
     *  Product: '<S68>/Product1'
     *  Sum: '<S68>/Add'
     *  Sum: '<S68>/Add2'
     *  UnitDelay: '<S68>/Unit Delay'
     */
    rtb_uDLookupTable = (1.0F - rtb_Sum_m) * ccdd_acc_vehAccActRaw_mps2 +
      rtb_Sum_m * ccdd_acc_vehAccAct_mps2;
  }

  /* End of Switch: '<S68>/Switch' */

  /* DataTypeConversion: '<S68>/Data Type Conversion3' */
  ccdd_acc_vehAccAct_mps2 = rtb_uDLookupTable;

  /* Lookup_n-D: '<S66>/1-D Lookup Table' */
  rtb_uDLookupTable = look1_iflf_binlcapw(ccdd_v_crsCtrlTgtSpd_kph, (const
    float32 *)&ccda_crsSpdCtrl_X_VehSpd_kph[0], (const float32 *)
    &ccdf_crsSpdCtrlFF_Y_Nm[0], 9U);

  /* Sum: '<S66>/Add' incorporates:
   *  Constant: '<S66>/Constant1'
   *  Constant: '<S66>/Constant4'
   *  Product: '<S66>/Product'
   *  Product: '<S66>/Product1'
   */
  ccdd_tq_crsCtrlTqFF_Nm = ccdd_acc_vehAccTgt_mps2 * ccdc_m_vehMass_kg *
    ccdc_l_vehTyreRadius_m + rtb_uDLookupTable;

  /* Sum: '<S66>/Add1' */
  ccdd_acc_vehAccErr_mps2 = ccdd_acc_vehAccTgt_mps2 - ccdd_acc_vehAccAct_mps2;

  /* Lookup_n-D: '<S66>/1-D Lookup Table1' incorporates:
   *  DataTypeConversion: '<S68>/Data Type Conversion3'
   *  Sum: '<S66>/Add1'
   */
  ccdd_fact_crsCtrlTqKp = look2_iflf_binlcapw(ccdd_acc_vehAccAct_mps2,
    ccdd_acc_vehAccErr_mps2, (const float32 *)
    &ccdm_crsCtrlTqKp_Y_VehAccAct_mps2[0], (const float32 *)
    &ccdm_crsCtrlTqKp_X_VehAccErr_mps2[0], (const float32 *)
    &ccdm_crsCtrlTqKp_Z_fact[0], swc_SCOO_ConstP.pooled10, 9U);

  /* Lookup_n-D: '<S66>/1-D Lookup Table3' incorporates:
   *  DataTypeConversion: '<S68>/Data Type Conversion3'
   *  Sum: '<S66>/Add1'
   */
  ccdd_fact_crsCtrlTqKi = look2_iflf_binlcapw(ccdd_acc_vehAccAct_mps2,
    ccdd_acc_vehAccErr_mps2, (const float32 *)
    &ccdm_crsCtrlTqKi_Y_VehAccAct_mps2[0], (const float32 *)
    &ccdm_crsCtrlTqKi_X_VehAccErr_mps2[0], (const float32 *)
    &ccdm_crsCtrlTqKi_Z_fact[0], swc_SCOO_ConstP.pooled10, 9U);

  /* Relay: '<S66>/Relay4' */
  swc_SCOO_ARID_DEF.Relay4_Mode_i = ((ccdd_acc_vehAccErr_mps2 >=
    ccdc_acc_tqKiEnaVehAccErrHi_mps2) || ((ccdd_acc_vehAccErr_mps2 >
    ccdc_acc_tqKiEnaVehAccErrLo_mps2) && swc_SCOO_ARID_DEF.Relay4_Mode_i));
  if (swc_SCOO_ARID_DEF.Relay4_Mode_i) {
    tmp = ((uint8)0U);
  } else {
    tmp = ((uint8)1U);
  }

  /* Logic: '<S66>/Logical Operator' incorporates:
   *  Constant: '<S38>/Constant'
   *  DataTypeConversion: '<S66>/Data Type Conversion5'
   *  RelationalOperator: '<S35>/Relational Operator3'
   *  RelationalOperator: '<S35>/Relational Operator6'
   *  RelationalOperator: '<S66>/Relational Operator3'
   *  Relay: '<S66>/Relay4'
   */
  ccdd_b_crsCtrlTqKiEna = ((tmp != 0) && ccdd_b_crsSpdCtrlEnad &&
    (ccdd_e_crsCtrlSts != CruiseSts_e_OVERRIDE));

  /* Logic: '<S49>/Logical Operator' */
  swc_SCOO_ARID_DEF.LogicalOperator_l = !ccdd_b_crsCtrlTqKiEna;

  /* Outputs for Atomic SubSystem: '<S49>/PID_FeedForward' */
  swc_SCOO_PID_FeedForward_e();

  /* End of Outputs for SubSystem: '<S49>/PID_FeedForward' */

  /* Switch: '<S37>/Switch3' incorporates:
   *  Constant: '<S37>/Constant1'
   */
  if (ccdc_b_crsCtrlBaseLineEna) {
    /* Switch: '<S37>/Switch3' */
    ccdd_tq_whlDemRaw_Nm = ccdd_tq_whlDemRawBase_Nm;
  } else {
    /* Switch: '<S37>/Switch3' */
    ccdd_tq_whlDemRaw_Nm = ccdd_tq_whlDemRawAdv_Nm;
  }

  /* End of Switch: '<S37>/Switch3' */

  /* Logic: '<S8>/Logical Operator2' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  rtb_LogicalOperator2_g = (ccdd_b_crsSpdCtrlEnad || false);

  /* Outputs for Atomic SubSystem: '<S8>/SwitchRampCreepTrqDem' */
  /* Constant: '<S8>/Constant3' incorporates:
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S8>/Constant6'
   */
  swc_SCOO_switch_ramp(ccdd_tq_whlDemRaw_Nm, rtb_LogicalOperator2_g, ((float32)
    WHL_TRQ_MIN), ccdc_dtq_crsCtrlTqIncGrad_Nmps, ccdc_dtq_crsCtrlTqDecGrad_Nmps,
                       &swc_SCOO_ARID_DEF.y, &rtb_RampOn,
                       &swc_SCOO_ARID_DEF.ARID_DEF_SwitchRampCreepTrqDe_m);

  /* End of Outputs for SubSystem: '<S8>/SwitchRampCreepTrqDem' */

  /* Switch: '<S34>/Switch1' incorporates:
   *  Constant: '<S34>/Constant2'
   */
  if (ccdc_b_whlDem_ovrdflg) {
    /* Switch: '<S34>/Switch1' incorporates:
     *  Constant: '<S34>/Constant1'
     */
    ccdd_tq_whlDem_Nm = ccdc_tq_whlDem_ovrdval;
  } else {
    /* Switch: '<S34>/Switch1' */
    ccdd_tq_whlDem_Nm = swc_SCOO_ARID_DEF.y;
  }

  /* End of Switch: '<S34>/Switch1' */

  /* Update for UnitDelay: '<S22>/Unit Delay1' */
  swc_SCOO_ARID_DEF.UnitDelay1_DSTATE = ccdd_e_crsCtrlSts;

  /* Update for UnitDelay: '<S14>/Delay Input1'
   *
   * Block description for '<S14>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_SCOO_ARID_DEF.DelayInput1_DSTATE_p = swc_SCOO_ARID_DEF.Butt_Cruise_Sts;

  /* Update for UnitDelay: '<S15>/Delay Input1'
   *
   * Block description for '<S15>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_SCOO_ARID_DEF.DelayInput1_DSTATE_e = rtb_flg_out_g;

  /* Update for UnitDelay: '<S18>/Delay Input1'
   *
   * Block description for '<S18>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_SCOO_ARID_DEF.DelayInput1_DSTATE_k = swc_SCOO_ARID_DEF.Butt_Accel_Sts;

  /* Update for UnitDelay: '<S11>/Unit Delay1' */
  swc_SCOO_ARID_DEF.UnitDelay1_DSTATE_g = ccdd_e_crsCtrlSpdMode;

  /* Update for UnitDelay: '<S20>/Delay Input1'
   *
   * Block description for '<S20>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_SCOO_ARID_DEF.DelayInput1_DSTATE_np = swc_SCOO_ARID_DEF.Butt_Coast_Sts;

  /* Update for UnitDelay: '<S13>/Unit Delay1' */
  swc_SCOO_ARID_DEF.UnitDelay1_DSTATE_gm = ccdd_e_crsCtrlSpdMode;

  /* Update for UnitDelay: '<S63>/UD'
   *
   * Block description for '<S63>/UD':
   *
   *  Store in Global RAM
   */
  swc_SCOO_ARID_DEF.UD_DSTATE = ccdd_v_crsCtrlTgtSpd_kph;

  /* Update for UnitDelay: '<S61>/init' incorporates:
   *  Constant: '<S61>/Constant'
   */
  swc_SCOO_ARID_DEF.init_DSTATE_d = false;

  /* Update for UnitDelay: '<S61>/Unit Delay' */
  swc_SCOO_ARID_DEF.UnitDelay_DSTATE_a = ccdd_acc_vehAccTgtLong_mps2;

  /* Update for UnitDelay: '<S50>/init' incorporates:
   *  Constant: '<S50>/Constant'
   */
  swc_SCOO_ARID_DEF.init_DSTATE_k = false;

  /* Update for UnitDelay: '<S50>/Unit Delay' */
  swc_SCOO_ARID_DEF.UnitDelay_DSTATE_d = ccdd_acc_vehAccTgt_mps2;

  /* Update for UnitDelay: '<S69>/UD'
   *
   * Block description for '<S69>/UD':
   *
   *  Store in Global RAM
   */
  swc_SCOO_ARID_DEF.UD_DSTATE_g = swc_SCOO_ARID_DEF.DataTypeConversion5;

  /* Update for UnitDelay: '<S68>/init' incorporates:
   *  Constant: '<S68>/Constant1'
   */
  swc_SCOO_ARID_DEF.init_DSTATE_h = false;
}

/* System initialize for atomic system: '<S84>/PID_FeedForward' */
static void swc_SCOO_PID_FeedForward_g_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S109>/init' */
  swc_SCOO_ARID_DEF.init_DSTATE_p = true;
}

/* Output and update for atomic system: '<S84>/PID_FeedForward' */
static void swc_SCOO_PID_FeedForward_f(void)
{
  float32 rtb_Divide;
  float32 rtb_Switch_o;
  float32 rtb_error;
  boolean rtb_AboveMax;
  boolean rtb_BelowMin;

  /* Sum: '<S102>/Sum' */
  rtb_error = ctdd_v_vehCrpTgt_kph - swc_SCOO_ARID_DEF.Switch1;

  /* Switch: '<S109>/Switch' incorporates:
   *  UnitDelay: '<S109>/init'
   */
  if (swc_SCOO_ARID_DEF.init_DSTATE_p) {
    /* Switch: '<S109>/Switch' incorporates:
     *  DataTypeConversion: '<S109>/Data Type Conversion'
     */
    rtb_Divide = rtb_error;
  } else {
    /* Product: '<S109>/Divide' incorporates:
     *  Constant: '<S84>/Constant1'
     *  Constant: '<S84>/Constant4'
     *  DataTypeConversion: '<S109>/Data Type Conversion1'
     *  DataTypeConversion: '<S109>/Data Type Conversion2'
     *  Sum: '<S109>/Add1'
     */
    rtb_Divide = ctdc_tm_whlSpdCtrlDerivTc_s / (ctdc_tm_whlSpdCtrlDerivTc_s +
      ((float32)CTD_TASK_INTERVAL_S));

    /* Switch: '<S109>/Switch' incorporates:
     *  Constant: '<S109>/Constant'
     *  DataTypeConversion: '<S109>/Data Type Conversion'
     *  Product: '<S109>/Product'
     *  Product: '<S109>/Product1'
     *  Sum: '<S109>/Add'
     *  Sum: '<S109>/Add2'
     *  UnitDelay: '<S109>/Unit Delay'
     */
    rtb_Divide = (1.0F - rtb_Divide) * rtb_error + rtb_Divide *
      swc_SCOO_ARID_DEF.UnitDelay_DSTATE_k;
  }

  /* End of Switch: '<S109>/Switch' */

  /* Switch: '<S107>/Switch1' incorporates:
   *  Logic: '<S102>/Logical Operator1'
   *  Switch: '<S107>/Switch'
   *  UnitDelay: '<S102>/ClippedPrev'
   */
  if (swc_SCOO_ARID_DEF.FixPtRelationalOperator) {
    /* Switch: '<S107>/Switch1' incorporates:
     *  Constant: '<S107>/Constant'
     */
    rtb_Switch_o = 0.0F;
  } else {
    if (swc_SCOO_ConstB.LogicalOperator2 ||
        swc_SCOO_ARID_DEF.ClippedPrev_DSTATE_k) {
      /* Switch: '<S107>/Switch' incorporates:
       *  Constant: '<S107>/Constant'
       */
      rtb_Switch_o = 0.0F;
    } else {
      /* Switch: '<S107>/Switch' incorporates:
       *  Constant: '<S84>/Constant4'
       *  Product: '<S107>/Product2'
       */
      rtb_Switch_o = rtb_error * ctdd_fact_CrpTgtTqCtlKi * ((float32)
        CTD_TASK_INTERVAL_S);
    }

    /* Switch: '<S107>/Switch1' incorporates:
     *  Sum: '<S107>/Sum1'
     *  Switch: '<S107>/Switch'
     *  UnitDelay: '<S107>/Unit Delay'
     */
    rtb_Switch_o += swc_SCOO_ARID_DEF.UnitDelay_DSTATE_bv;
  }

  /* End of Switch: '<S107>/Switch1' */

  /* Sum: '<S102>/rawdmd' incorporates:
   *  Constant: '<S84>/Constant1'
   *  Constant: '<S84>/Constant3'
   *  DataTypeConversion: '<S109>/Data Type Conversion3'
   *  Product: '<S106>/Product'
   *  Product: '<S106>/Product1'
   *  Product: '<S108>/Product'
   *  Sum: '<S106>/rawdmd'
   */
  rtb_error = ((rtb_error - rtb_Divide) / ctdc_tm_whlSpdCtrlDerivTc_s *
               cdtc_fact_whlSpdCtrlKd + (rtb_error * ctdd_fact_CrpTgtTqCtlKp +
    swc_SCOO_ARID_DEF.Product)) + rtb_Switch_o;

  /* RelationalOperator: '<S105>/AboveMax' */
  rtb_AboveMax = (swc_SCOO_ARID_DEF.Plus < rtb_error);

  /* RelationalOperator: '<S105>/BelowMin' */
  rtb_BelowMin = (rtb_error < swc_SCOO_ARID_DEF.DataTypeConversion26);

  /* Switch: '<S105>/Switch' incorporates:
   *  Switch: '<S105>/Switch1'
   */
  if (rtb_AboveMax) {
    /* Switch: '<S105>/Switch' */
    ctdd_tq_whlDemRaw_Nm = swc_SCOO_ARID_DEF.Plus;
  } else if (rtb_BelowMin) {
    /* Switch: '<S105>/Switch1' incorporates:
     *  Switch: '<S105>/Switch'
     */
    ctdd_tq_whlDemRaw_Nm = swc_SCOO_ARID_DEF.DataTypeConversion26;
  } else {
    /* Switch: '<S105>/Switch' incorporates:
     *  Switch: '<S105>/Switch1'
     */
    ctdd_tq_whlDemRaw_Nm = rtb_error;
  }

  /* End of Switch: '<S105>/Switch' */

  /* Update for UnitDelay: '<S102>/ClippedPrev' incorporates:
   *  Logic: '<S105>/OutsideLimit'
   */
  swc_SCOO_ARID_DEF.ClippedPrev_DSTATE_k = (rtb_AboveMax || rtb_BelowMin);

  /* Update for UnitDelay: '<S109>/init' incorporates:
   *  Constant: '<S109>/Constant1'
   */
  swc_SCOO_ARID_DEF.init_DSTATE_p = false;

  /* Update for UnitDelay: '<S109>/Unit Delay' incorporates:
   *  DataTypeConversion: '<S109>/Data Type Conversion3'
   */
  swc_SCOO_ARID_DEF.UnitDelay_DSTATE_k = rtb_Divide;

  /* Update for UnitDelay: '<S107>/Unit Delay' */
  swc_SCOO_ARID_DEF.UnitDelay_DSTATE_bv = rtb_Switch_o;
}

/* Output and update for atomic system: '<S84>/determine_creep_vel_tgt' */
static void swc_SCO_determine_creep_vel_tgt(DriveDir rtu_drid_e_driveDirSel,
  float32 rtu_brpd_x_brkPedlPos_pct, float32 rtu_vsld_v_rmtCtrlFctSpdLim_kph)
{
  float32 rtb_Switch_o;

  /* Switch: '<S103>/Switch' incorporates:
   *  Lookup_n-D: '<S103>/1-D Lookup Table2'
   */
  rtb_Switch_o = look1_iflf_binlcapw(rtu_brpd_x_brkPedlPos_pct, (const float32 *)
    &swcscoo_ctda_CrpTgtSpd_X_brkPedlPos_pct[0], (const float32 *)
    &swcscoo_ctdf_CrpTgtFwdSpdMap_Y_kph[0], 7U);

  /* MinMax: '<S103>/MinMax1' */
  ctdd_n_vehTgtCrpSpdFwd_kph = fminf(rtu_vsld_v_rmtCtrlFctSpdLim_kph,
    rtb_Switch_o);

  /* Switch: '<S103>/Switch' incorporates:
   *  Constant: '<S110>/Constant'
   *  RelationalOperator: '<S103>/Relational Operator'
   */
  if (rtu_drid_e_driveDirSel == DriveDir_REVERSE) {
    /* Switch: '<S103>/Switch' incorporates:
     *  Lookup_n-D: '<S103>/1-D Lookup Table1'
     */
    rtb_Switch_o = look1_iflf_binlcapw(rtu_brpd_x_brkPedlPos_pct, (const float32
      *)&swcscoo_ctda_CrpTgtSpd_X_brkPedlPos_pct[0], (const float32 *)
      &swcscoo_ctdf_CrpTgtRevSpdMap_Y_kph[0], 7U);
  }

  /* End of Switch: '<S103>/Switch' */

  /* MinMax: '<S103>/MinMax4' */
  ctdd_v_vehCrpTgt_kph = fminf(rtb_Switch_o, rtu_vsld_v_rmtCtrlFctSpdLim_kph);
}

/* Output and update for atomic system: '<S84>/determine_pi_factors' */
static void swc_SCOO_determine_pi_factors(float32 rtu_VehSpdErr)
{
  /* Lookup_n-D: '<S104>/1-D Lookup Table' */
  ctdd_fact_CrpTgtTqCtlKp = look1_iflf_binlcapw(rtu_VehSpdErr, (const float32 *)
    &ctdf_TgtTqKpMap_X_VehSpdErr_kph[0], (const float32 *)&ctdf_TgtTqKpMap_Y_Nm
    [0], 5U);

  /* Lookup_n-D: '<S104>/1-D Lookup Table1' */
  ctdd_fact_CrpTgtTqCtlKi = look1_iflf_binlcapw(rtu_VehSpdErr, (const float32 *)
    &ctdf_TgtTqKiMap_X_VehSpdErr_kph[0], (const float32 *)&ctdf_TgtTqKiMap_Y_Nm
    [0], 5U);
}

/* Output and update for atomic system: '<S86>/SR_latch' */
static void swc_SCOO_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_SCOO_T *swc_SCOO__ARID_DEF_arg)
{
  /* Logic: '<S129>/Logical Operator3' incorporates:
   *  Logic: '<S129>/Logical Operator'
   *  Logic: '<S129>/Logical Operator1'
   *  UnitDelay: '<S129>/Unit Delay'
   */
  ctdd_b_crpSlopeTrqOffsetEnHld = ((swc_SCOO__ARID_DEF_arg->UnitDelay_DSTATE ||
    rtu_flg_set) && (!rtu_flg_reset));

  /* Update for UnitDelay: '<S129>/Unit Delay' */
  swc_SCOO__ARID_DEF_arg->UnitDelay_DSTATE = ctdd_b_crpSlopeTrqOffsetEnHld;
}

/* System initialize for atomic system: '<S3>/SwitchRampCreepTrqDem' */
static void swc__SwitchRampCreepTrqDem_Init(boolean *rty_RampOn)
{
  /* SystemInitialize for Chart: '<S130>/Chart' */
  *rty_RampOn = false;
}

/* Output and update for atomic system: '<S3>/SwitchRampCreepTrqDem' */
static void swc_SCOO_SwitchRampCreepTrqDem(float32 rtu_u1, boolean rtu_sw,
  float32 rtu_u2, float32 rtu_up, float32 rtu_lo, boolean *rty_RampOn,
  ARID_DEF_switch_ramp_swc_SC_n_T *swc_SCOO__ARID_DEF_arg)
{
  float32 rtb_MinMax1_k;
  float32 rtb_MinMax_m;

  /* MinMax: '<S87>/MinMax' incorporates:
   *  Constant: '<S87>/Constant1'
   *  Constant: '<S87>/Constant2'
   *  Product: '<S87>/Product'
   */
  rtb_MinMax_m = fmaxf(rtu_up * 0.01F, 0.0F);

  /* MinMax: '<S87>/MinMax1' incorporates:
   *  Constant: '<S87>/Constant1'
   *  Constant: '<S87>/Constant2'
   *  Product: '<S87>/Product1'
   */
  rtb_MinMax1_k = fminf(0.0F, 0.01F * rtu_lo);

  /* Chart: '<S130>/Chart' */
  if (swc_SCOO__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li == 0U) {
    swc_SCOO__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li = 1U;
    swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCOO_IN_U2_n;
    *rty_RampOn = false;
    ctdd_tq_whlDem_Nm = rtu_u2;
  } else {
    switch (swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib) {
     case swc_SCOO_IN_U1_e:
      *rty_RampOn = false;
      if (!rtu_sw) {
        if (rtu_u2 >= rtu_u1) {
          swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCOO_IN_U1_TO_U2_c;
          swc_SCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_SCOO_IN_U1_TO_U2_INC_i;
          *rty_RampOn = true;
          ctdd_tq_whlDem_Nm = fminf(fmaxf(fminf(rtu_u2 - ctdd_tq_whlDem_Nm,
            rtb_MinMax_m) + ctdd_tq_whlDem_Nm, rtu_u1), rtu_u2);
        } else {
          swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCOO_IN_U1_TO_U2_c;
          swc_SCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_SCOO_IN_U1_TO_U2_DEC_d;
          *rty_RampOn = true;
          ctdd_tq_whlDem_Nm = fmaxf(fminf(fmaxf(rtu_u2 - ctdd_tq_whlDem_Nm,
            rtb_MinMax1_k) + ctdd_tq_whlDem_Nm, rtu_u1), rtu_u2);
        }
      } else {
        ctdd_tq_whlDem_Nm = rtu_u1;
      }
      break;

     case swc_SCOO_IN_U1_TO_U2_c:
      if (rtu_sw) {
        if (rtu_u1 >= rtu_u2) {
          swc_SCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_SCOO_IN_NO_ACTIVE_CHILD_h;
          swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCOO_IN_U2_TO_U1_e;
          swc_SCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_SCOO_IN_U2_TO_U1_INC_p;
          *rty_RampOn = true;
          ctdd_tq_whlDem_Nm = fminf(fmaxf(fminf(rtu_u1 - ctdd_tq_whlDem_Nm,
            rtb_MinMax_m) + ctdd_tq_whlDem_Nm, rtu_u2), rtu_u1);
        } else {
          swc_SCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_SCOO_IN_NO_ACTIVE_CHILD_h;
          swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCOO_IN_U2_TO_U1_e;
          swc_SCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_SCOO_IN_U2_TO_U1_DEC_h;
          *rty_RampOn = true;
          ctdd_tq_whlDem_Nm = fmaxf(fminf(fmaxf(rtu_u1 - ctdd_tq_whlDem_Nm,
            rtb_MinMax1_k) + ctdd_tq_whlDem_Nm, rtu_u2), rtu_u1);
        }
      } else if (swc_SCOO__ARID_DEF_arg->is_U1_TO_U2 ==
                 swc_SCOO_IN_U1_TO_U2_DEC_d) {
        *rty_RampOn = true;
        rtb_MinMax_m = rtu_u2 - ctdd_tq_whlDem_Nm;
        if (rtb_MinMax_m >= rtb_MinMax1_k) {
          swc_SCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_SCOO_IN_NO_ACTIVE_CHILD_h;
          swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCOO_IN_U2_n;
          *rty_RampOn = false;
          ctdd_tq_whlDem_Nm = rtu_u2;
        } else {
          ctdd_tq_whlDem_Nm = fmaxf(fminf(fmaxf(rtb_MinMax_m, rtb_MinMax1_k) +
            ctdd_tq_whlDem_Nm, rtu_u1), rtu_u2);
        }
      } else {
        /* case IN_U1_TO_U2_INC: */
        *rty_RampOn = true;
        if (rtu_u2 - ctdd_tq_whlDem_Nm <= rtb_MinMax_m) {
          swc_SCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_SCOO_IN_NO_ACTIVE_CHILD_h;
          swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCOO_IN_U2_n;
          *rty_RampOn = false;
          ctdd_tq_whlDem_Nm = rtu_u2;
        } else {
          ctdd_tq_whlDem_Nm = fminf(fmaxf(fminf(rtu_u2 - ctdd_tq_whlDem_Nm,
            rtb_MinMax_m) + ctdd_tq_whlDem_Nm, rtu_u1), rtu_u2);
        }
      }
      break;

     case swc_SCOO_IN_U2_n:
      *rty_RampOn = false;
      if (rtu_sw) {
        if (rtu_u1 >= rtu_u2) {
          swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCOO_IN_U2_TO_U1_e;
          swc_SCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_SCOO_IN_U2_TO_U1_INC_p;
          *rty_RampOn = true;
          ctdd_tq_whlDem_Nm = fminf(fmaxf(fminf(rtu_u1 - ctdd_tq_whlDem_Nm,
            rtb_MinMax_m) + ctdd_tq_whlDem_Nm, rtu_u2), rtu_u1);
        } else {
          swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCOO_IN_U2_TO_U1_e;
          swc_SCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_SCOO_IN_U2_TO_U1_DEC_h;
          *rty_RampOn = true;
          ctdd_tq_whlDem_Nm = fmaxf(fminf(fmaxf(rtu_u1 - ctdd_tq_whlDem_Nm,
            rtb_MinMax1_k) + ctdd_tq_whlDem_Nm, rtu_u2), rtu_u1);
        }
      } else {
        ctdd_tq_whlDem_Nm = rtu_u2;
      }
      break;

     default:
      /* case IN_U2_TO_U1: */
      if (!rtu_sw) {
        if (rtu_u2 >= rtu_u1) {
          swc_SCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_SCOO_IN_NO_ACTIVE_CHILD_h;
          swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCOO_IN_U1_TO_U2_c;
          swc_SCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_SCOO_IN_U1_TO_U2_INC_i;
          *rty_RampOn = true;
          ctdd_tq_whlDem_Nm = fminf(fmaxf(fminf(rtu_u2 - ctdd_tq_whlDem_Nm,
            rtb_MinMax_m) + ctdd_tq_whlDem_Nm, rtu_u1), rtu_u2);
        } else {
          swc_SCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_SCOO_IN_NO_ACTIVE_CHILD_h;
          swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_SCOO_IN_U1_TO_U2_c;
          swc_SCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_SCOO_IN_U1_TO_U2_DEC_d;
          *rty_RampOn = true;
          ctdd_tq_whlDem_Nm = fmaxf(fminf(fmaxf(rtu_u2 - ctdd_tq_whlDem_Nm,
            rtb_MinMax1_k) + ctdd_tq_whlDem_Nm, rtu_u1), rtu_u2);
        }
      } else if (swc_SCOO__ARID_DEF_arg->is_U2_TO_U1 ==
                 swc_SCOO_IN_U2_TO_U1_DEC_h) {
        *rty_RampOn = true;
        rtb_MinMax_m = rtu_u1 - ctdd_tq_whlDem_Nm;
        if (rtb_MinMax_m >= rtb_MinMax1_k) {
          swc_SCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_SCOO_IN_NO_ACTIVE_CHILD_h;
          swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCOO_IN_U1_e;
          *rty_RampOn = false;
          ctdd_tq_whlDem_Nm = rtu_u1;
        } else {
          ctdd_tq_whlDem_Nm = fmaxf(fminf(fmaxf(rtb_MinMax_m, rtb_MinMax1_k) +
            ctdd_tq_whlDem_Nm, rtu_u2), rtu_u1);
        }
      } else {
        /* case IN_U2_TO_U1_INC: */
        *rty_RampOn = true;
        if (rtu_u1 - ctdd_tq_whlDem_Nm <= rtb_MinMax_m) {
          swc_SCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_SCOO_IN_NO_ACTIVE_CHILD_h;
          swc_SCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_SCOO_IN_U1_e;
          *rty_RampOn = false;
          ctdd_tq_whlDem_Nm = rtu_u1;
        } else {
          ctdd_tq_whlDem_Nm = fminf(fmaxf(fminf(rtu_u1 - ctdd_tq_whlDem_Nm,
            rtb_MinMax_m) + ctdd_tq_whlDem_Nm, rtu_u2), rtu_u1);
        }
      }
      break;
    }
  }

  /* End of Chart: '<S130>/Chart' */
}

/* System initialize for function-call system: '<S1>/CTD_CreepDemand' */
static void swc_SCOO_CTD_CreepDemand_Init(void)
{
  /* local block i/o variables */
  boolean rtb_RampOn_b;

  /* InitializeConditions for UnitDelay: '<S116>/Unit Delay' */
  swc_SCOO_ARID_DEF.UnitDelay_DSTATE = 10.0;

  /* InitializeConditions for UnitDelay: '<S120>/init' */
  swc_SCOO_ARID_DEF.init_DSTATE = true;

  /* SystemInitialize for Enabled SubSystem: '<S116>/Enabled Subsystem' */
  /* SystemInitialize for S-Function (fcgen): '<S118>/Function-Call Generator' incorporates:
   *  SubSystem: '<S85>/100msRoadGradCalc'
   */
  /* InitializeConditions for Delay: '<S111>/Delay' */
  swc_SCOO_ARID_DEF.icLoad = true;

  /* InitializeConditions for Delay: '<S111>/Delay1' */
  swc_SCOO_ARID_DEF.icLoad_k = true;

  /* InitializeConditions for Delay: '<S111>/Delay2' */
  swc_SCOO_ARID_DEF.icLoad_d = true;

  /* InitializeConditions for Delay: '<S111>/Delay3' */
  swc_SCOO_ARID_DEF.icLoad_e = true;

  /* InitializeConditions for Delay: '<S111>/Delay4' */
  swc_SCOO_ARID_DEF.icLoad_l = true;

  /* InitializeConditions for Delay: '<S111>/Delay5' */
  swc_SCOO_ARID_DEF.icLoad_c = true;

  /* InitializeConditions for Delay: '<S111>/Delay6' */
  swc_SCOO_ARID_DEF.icLoad_h = true;

  /* InitializeConditions for Delay: '<S111>/Delay7' */
  swc_SCOO_ARID_DEF.icLoad_j = true;

  /* InitializeConditions for Delay: '<S111>/Delay8' */
  swc_SCOO_ARID_DEF.icLoad_g = true;

  /* End of SystemInitialize for S-Function (fcgen): '<S118>/Function-Call Generator' */
  /* End of SystemInitialize for SubSystem: '<S116>/Enabled Subsystem' */

  /* SystemInitialize for Atomic SubSystem: '<S84>/PID_FeedForward' */
  swc_SCOO_PID_FeedForward_g_Init();

  /* End of SystemInitialize for SubSystem: '<S84>/PID_FeedForward' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/SwitchRampCreepTrqDem' */
  swc__SwitchRampCreepTrqDem_Init(&rtb_RampOn_b);

  /* End of SystemInitialize for SubSystem: '<S3>/SwitchRampCreepTrqDem' */
}

/* Output and update for function-call system: '<S1>/CTD_CreepDemand' */
static void swc_SCOO_CTD_CreepDemand(void)
{
  /* local block i/o variables */
  float32 rtb_Sum_o;
  float32 rtb_Switch_a;
  boolean rtb_FixPtRelationalOperator_i;
  boolean rtb_LogicalOperator8_e;
  boolean rtb_LogicalOperator4_a;
  boolean rtb_RampOn_b;
  float64 rtb_Add_m;
  float64 rtb_Divide;
  sint32 i;
  sint32 n;
  float32 rtb_TmpSignalConversionAtMeanIn[10];
  float32 rtb_Divide_i;
  float32 rtb_t_delay_on_d;
  DriveDir ctdd_b_CreepEnabled_tmp;
  boolean rtb_Relay;

  /* Relay: '<S83>/Relay' */
  swc_SCOO_ARID_DEF.Relay_Mode = ((swc_SCOO_ARID_DEF.DataTypeConversion5 >=
    ctdc_v_vehHiThrSafeDisCrp_kph) || ((swc_SCOO_ARID_DEF.DataTypeConversion5 >
    ctdc_v_vehLoThrSafeDisCrp_kph) && swc_SCOO_ARID_DEF.Relay_Mode));
  if (swc_SCOO_ARID_DEF.Relay_Mode) {
    rtb_Relay = false;
  } else {
    rtb_Relay = true;
  }

  /* Switch: '<S83>/Switch' */
  if (swc_SCOO_ARID_DEF.DataTypeConversion45 > 0.0) {
    rtb_Add_m = swc_SCOO_ARID_DEF.DataTypeConversion44;
  } else {
    rtb_Add_m = swc_SCOO_ARID_DEF.DataTypeConversion46;
  }

  /* RelationalOperator: '<S83>/Relational Operator' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  RelationalOperator: '<S84>/Relational Operator'
   *  RelationalOperator: '<S84>/Relational Operator1'
   *  RelationalOperator: '<S84>/Relational Operator2'
   *  RelationalOperator: '<S86>/Relational Operator'
   *  RelationalOperator: '<S86>/Relational Operator1'
   */
  ctdd_b_CreepEnabled_tmp = swc_SCOO_ARID_DEF.DataTypeConversion2;

  /* Logic: '<S83>/Logical Operator' incorporates:
   *  Constant: '<S83>/Constant'
   *  Constant: '<S83>/Constant10'
   *  Constant: '<S83>/Constant2'
   *  Constant: '<S83>/Constant3'
   *  Constant: '<S83>/Constant4'
   *  Constant: '<S83>/Constant5'
   *  Constant: '<S83>/Constant6'
   *  Constant: '<S83>/Constant7'
   *  Constant: '<S83>/Constant8'
   *  Constant: '<S83>/Constant9'
   *  Constant: '<S89>/Constant'
   *  Constant: '<S90>/Constant'
   *  Constant: '<S91>/Constant'
   *  Constant: '<S92>/Constant'
   *  Constant: '<S93>/Constant'
   *  Constant: '<S94>/Constant'
   *  Constant: '<S95>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion16'
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  DataTypeConversion: '<Root>/Data Type Conversion41'
   *  Logic: '<S83>/Logical Operator1'
   *  Logic: '<S83>/Logical Operator10'
   *  Logic: '<S83>/Logical Operator11'
   *  Logic: '<S83>/Logical Operator12'
   *  Logic: '<S83>/Logical Operator14'
   *  Logic: '<S83>/Logical Operator2'
   *  Logic: '<S83>/Logical Operator4'
   *  Logic: '<S83>/Logical Operator5'
   *  Logic: '<S83>/Logical Operator6'
   *  Logic: '<S83>/Logical Operator7'
   *  Logic: '<S83>/Logical Operator8'
   *  Logic: '<S83>/Logical Operator9'
   *  RelationalOperator: '<S83>/Relational Operator'
   *  RelationalOperator: '<S83>/Relational Operator1'
   *  RelationalOperator: '<S83>/Relational Operator2'
   *  RelationalOperator: '<S83>/Relational Operator3'
   *  RelationalOperator: '<S83>/Relational Operator4'
   *  RelationalOperator: '<S83>/Relational Operator5'
   *  RelationalOperator: '<S83>/Relational Operator6'
   *  RelationalOperator: '<S83>/Relational Operator7'
   *  RelationalOperator: '<S83>/Relational Operator8'
   *  RelationalOperator: '<S83>/Relational Operator9'
   *  RelationalOperator: '<S89>/Compare'
   *  RelationalOperator: '<S90>/Compare'
   *  RelationalOperator: '<S91>/Compare'
   *  Relay: '<S83>/Relay'
   *  Switch: '<S83>/Switch'
   */
  ctdd_b_CreepEnabled = ((ctdd_b_CreepEnabled_tmp != DriveDir_NO_DRIVE) &&
    (((vslc_b_brkMismatchActvLvl != swc_SCOO_ARID_DEF.DataTypeConversion38) &&
      (swc_SCOO_ARID_DEF.DataTypeConversion4 == BrakePedalStatus_NOT_PRESSED)) ||
     (!ctdc_b_chkBrkPedlStsToEnaCrp)) &&
    ((swc_SCOO_ARID_DEF.DataTypeConversion16 == ParkingStatus_DISENGAGED) ||
     (!ctdc_b_enaCreepAftEPBRels)) && ((swc_SCOO_ARID_DEF.DataTypeConversion41 ==
    PmmStatus_DRIVE) || ctdc_b_chkPmmStsToEnaCrp) && (rtb_Relay &&
    swc_SCOO_ARID_DEF.DataTypeConversion36) &&
    (swc_SCOO_ARID_DEF.DataTypeConversion31 != ((uint8)1U)) &&
    ((swc_SCOO_ARID_DEF.DataTypeConversion13 != ((uint8)1U)) &&
     (swc_SCOO_ARID_DEF.DataTypeConversion13 != ((uint8)2U)) &&
     (swc_SCOO_ARID_DEF.DataTypeConversion13 != ((uint8)3U))) &&
    ((swc_SCOO_ARID_DEF.DataTypeConversion14 != ((uint8)1U)) ||
     vslc_b_chkHhcStsToEnaCrp) && (!swc_SCOO_ARID_DEF.DataTypeConversion22) && (
    !swc_SCOO_ARID_DEF.LogicalOperator) &&
    (swc_SCOO_ARID_DEF.DataTypeConversion40 == 0.0) &&
    (swc_SCOO_ARID_DEF.DataTypeConversion43 == 0.0) && (rtb_Add_m == 0.0));

  /* Logic: '<S83>/Logical Operator3' incorporates:
   *  Constant: '<S83>/Constant1'
   */
  ctdd_b_eCreepReq = (ctdc_b_enableCreep && ctdd_b_CreepEnabled);

  /* Sum: '<S116>/Add' incorporates:
   *  Constant: '<S116>/Constant'
   *  UnitDelay: '<S116>/Unit Delay'
   */
  rtb_Add_m = 1.0 + swc_SCOO_ARID_DEF.UnitDelay_DSTATE;

  /* Product: '<S116>/Divide' incorporates:
   *  Constant: '<S116>/Constant1'
   *  Constant: '<S116>/Constant2'
   */
  rtb_Divide = ctdc_tm_crpSlopeCalStepTm_ms / 10.0;

  /* Switch: '<S116>/Switch' incorporates:
   *  RelationalOperator: '<S116>/Relational Operator'
   */
  if (rtb_Add_m > rtb_Divide) {
    /* Switch: '<S116>/Switch' incorporates:
     *  Constant: '<S116>/Constant4'
     */
    rtb_Add_m = 1.0;
  }

  /* End of Switch: '<S116>/Switch' */

  /* Switch: '<S85>/Switch' incorporates:
   *  Constant: '<S112>/Constant'
   *  Constant: '<S113>/Constant'
   *  Logic: '<S85>/Logical Operator'
   *  RelationalOperator: '<S112>/Compare'
   *  RelationalOperator: '<S113>/Compare'
   */
  if ((swc_SCOO_ARID_DEF.DataTypeConversion27 <= ctdc_a_yrsLongAccUp_mps2) &&
      (swc_SCOO_ARID_DEF.DataTypeConversion27 >= ctdc_a_yrsLongAccDn_mps2)) {
    /* Switch: '<S85>/Switch' */
    ctdd_a_yrsLongAcc_mps2 = swc_SCOO_ARID_DEF.DataTypeConversion27;
  } else {
    /* Switch: '<S85>/Switch' incorporates:
     *  Constant: '<S85>/Constant'
     */
    ctdd_a_yrsLongAcc_mps2 = 0.0F;
  }

  /* End of Switch: '<S85>/Switch' */

  /* Outputs for Enabled SubSystem: '<S116>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S118>/Enable'
   */
  /* RelationalOperator: '<S116>/Relational Operator1' */
  if (rtb_Add_m == rtb_Divide) {
    /* S-Function (fcgen): '<S118>/Function-Call Generator' incorporates:
     *  SubSystem: '<S85>/100msRoadGradCalc'
     */
    /* Delay: '<S111>/Delay' */
    if (swc_SCOO_ARID_DEF.icLoad) {
      swc_SCOO_ARID_DEF.Delay_DSTATE_d = ctdd_a_yrsLongAcc_mps2;
    }

    /* Delay: '<S111>/Delay1' */
    if (swc_SCOO_ARID_DEF.icLoad_k) {
      swc_SCOO_ARID_DEF.Delay1_DSTATE[0] = ctdd_a_yrsLongAcc_mps2;
      swc_SCOO_ARID_DEF.Delay1_DSTATE[1] = ctdd_a_yrsLongAcc_mps2;
    }

    /* Delay: '<S111>/Delay2' */
    if (swc_SCOO_ARID_DEF.icLoad_d) {
      swc_SCOO_ARID_DEF.Delay2_DSTATE[0] = ctdd_a_yrsLongAcc_mps2;
      swc_SCOO_ARID_DEF.Delay2_DSTATE[1] = ctdd_a_yrsLongAcc_mps2;
      swc_SCOO_ARID_DEF.Delay2_DSTATE[2] = ctdd_a_yrsLongAcc_mps2;
    }

    /* Delay: '<S111>/Delay3' */
    if (swc_SCOO_ARID_DEF.icLoad_e) {
      swc_SCOO_ARID_DEF.Delay3_DSTATE[0] = ctdd_a_yrsLongAcc_mps2;
      swc_SCOO_ARID_DEF.Delay3_DSTATE[1] = ctdd_a_yrsLongAcc_mps2;
      swc_SCOO_ARID_DEF.Delay3_DSTATE[2] = ctdd_a_yrsLongAcc_mps2;
      swc_SCOO_ARID_DEF.Delay3_DSTATE[3] = ctdd_a_yrsLongAcc_mps2;
    }

    /* Delay: '<S111>/Delay4' */
    if (swc_SCOO_ARID_DEF.icLoad_l) {
      for (i = 0; i < 5; i++) {
        swc_SCOO_ARID_DEF.Delay4_DSTATE[i] = ctdd_a_yrsLongAcc_mps2;
      }
    }

    /* Delay: '<S111>/Delay5' */
    if (swc_SCOO_ARID_DEF.icLoad_c) {
      for (i = 0; i < 6; i++) {
        swc_SCOO_ARID_DEF.Delay5_DSTATE[i] = ctdd_a_yrsLongAcc_mps2;
      }
    }

    /* Delay: '<S111>/Delay6' */
    if (swc_SCOO_ARID_DEF.icLoad_h) {
      for (i = 0; i < 7; i++) {
        swc_SCOO_ARID_DEF.Delay6_DSTATE[i] = ctdd_a_yrsLongAcc_mps2;
      }
    }

    /* Delay: '<S111>/Delay7' */
    if (swc_SCOO_ARID_DEF.icLoad_j) {
      for (i = 0; i < 8; i++) {
        swc_SCOO_ARID_DEF.Delay7_DSTATE[i] = ctdd_a_yrsLongAcc_mps2;
      }
    }

    /* Delay: '<S111>/Delay8' */
    if (swc_SCOO_ARID_DEF.icLoad_g) {
      for (i = 0; i < 9; i++) {
        swc_SCOO_ARID_DEF.Delay8_DSTATE[i] = ctdd_a_yrsLongAcc_mps2;
      }
    }

    /* SignalConversion generated from: '<S111>/Mean' incorporates:
     *  Delay: '<S111>/Delay'
     *  Delay: '<S111>/Delay1'
     *  Delay: '<S111>/Delay2'
     *  Delay: '<S111>/Delay3'
     *  Delay: '<S111>/Delay4'
     *  Delay: '<S111>/Delay5'
     *  Delay: '<S111>/Delay6'
     *  Delay: '<S111>/Delay7'
     *  Delay: '<S111>/Delay8'
     */
    rtb_TmpSignalConversionAtMeanIn[0] = ctdd_a_yrsLongAcc_mps2;
    rtb_TmpSignalConversionAtMeanIn[1] = swc_SCOO_ARID_DEF.Delay_DSTATE_d;
    rtb_TmpSignalConversionAtMeanIn[2] = swc_SCOO_ARID_DEF.Delay1_DSTATE[0U];
    rtb_TmpSignalConversionAtMeanIn[3] = swc_SCOO_ARID_DEF.Delay2_DSTATE[0U];
    rtb_TmpSignalConversionAtMeanIn[4] = swc_SCOO_ARID_DEF.Delay3_DSTATE[0U];
    rtb_TmpSignalConversionAtMeanIn[5] = swc_SCOO_ARID_DEF.Delay4_DSTATE[0U];
    rtb_TmpSignalConversionAtMeanIn[6] = swc_SCOO_ARID_DEF.Delay5_DSTATE[0U];
    rtb_TmpSignalConversionAtMeanIn[7] = swc_SCOO_ARID_DEF.Delay6_DSTATE[0U];
    rtb_TmpSignalConversionAtMeanIn[8] = swc_SCOO_ARID_DEF.Delay7_DSTATE[0U];
    rtb_TmpSignalConversionAtMeanIn[9] = swc_SCOO_ARID_DEF.Delay8_DSTATE[0U];

    /* S-Function (sdspstatfcns): '<S111>/Mean' incorporates:
     *  SignalConversion generated from: '<S111>/Mean'
     */
    swc_SCOO_ARID_DEF.Mean_AccVal = ctdd_a_yrsLongAcc_mps2;
    i = 1;
    for (n = 8; n >= 0; n--) {
      swc_SCOO_ARID_DEF.Mean_AccVal += rtb_TmpSignalConversionAtMeanIn[i];
      i++;
    }

    /* S-Function (sdspstatfcns): '<S111>/Mean' */
    ctdd_a_yrsLongAccAvg_mps2 = swc_SCOO_ARID_DEF.Mean_AccVal / 10.0F;

    /* S-Function (sdspstatfcns): '<S111>/Standard Deviation' incorporates:
     *  SignalConversion generated from: '<S111>/Mean'
     */
    swc_SCOO_ARID_DEF.StandardDeviation_AccVal = ctdd_a_yrsLongAcc_mps2;
    swc_SCOO_ARID_DEF.StandardDeviation_SqData = ctdd_a_yrsLongAcc_mps2 *
      ctdd_a_yrsLongAcc_mps2;
    i = 1;
    for (n = 8; n >= 0; n--) {
      swc_SCOO_ARID_DEF.StandardDeviation_AccVal +=
        rtb_TmpSignalConversionAtMeanIn[i];
      swc_SCOO_ARID_DEF.StandardDeviation_SqData +=
        rtb_TmpSignalConversionAtMeanIn[i] * rtb_TmpSignalConversionAtMeanIn[i];
      i++;
    }

    /* S-Function (sdspstatfcns): '<S111>/Standard Deviation' */
    ctdd_a_yrsLongAccSgm_mps2 = (swc_SCOO_ARID_DEF.StandardDeviation_SqData -
      swc_SCOO_ARID_DEF.StandardDeviation_AccVal *
      swc_SCOO_ARID_DEF.StandardDeviation_AccVal / 10.0F) / 9.0F;
    ctdd_a_yrsLongAccSgm_mps2 = sqrtf(fabsf(ctdd_a_yrsLongAccSgm_mps2));

    /* Update for Delay: '<S111>/Delay' */
    swc_SCOO_ARID_DEF.icLoad = false;
    swc_SCOO_ARID_DEF.Delay_DSTATE_d = ctdd_a_yrsLongAcc_mps2;

    /* Update for Delay: '<S111>/Delay1' */
    swc_SCOO_ARID_DEF.icLoad_k = false;
    swc_SCOO_ARID_DEF.Delay1_DSTATE[0] = swc_SCOO_ARID_DEF.Delay1_DSTATE[1];
    swc_SCOO_ARID_DEF.Delay1_DSTATE[1] = ctdd_a_yrsLongAcc_mps2;

    /* Update for Delay: '<S111>/Delay2' */
    swc_SCOO_ARID_DEF.icLoad_d = false;
    swc_SCOO_ARID_DEF.Delay2_DSTATE[0] = swc_SCOO_ARID_DEF.Delay2_DSTATE[1];
    swc_SCOO_ARID_DEF.Delay2_DSTATE[1] = swc_SCOO_ARID_DEF.Delay2_DSTATE[2];
    swc_SCOO_ARID_DEF.Delay2_DSTATE[2] = ctdd_a_yrsLongAcc_mps2;

    /* Update for Delay: '<S111>/Delay3' */
    swc_SCOO_ARID_DEF.icLoad_e = false;
    swc_SCOO_ARID_DEF.Delay3_DSTATE[0] = swc_SCOO_ARID_DEF.Delay3_DSTATE[1];
    swc_SCOO_ARID_DEF.Delay3_DSTATE[1] = swc_SCOO_ARID_DEF.Delay3_DSTATE[2];
    swc_SCOO_ARID_DEF.Delay3_DSTATE[2] = swc_SCOO_ARID_DEF.Delay3_DSTATE[3];
    swc_SCOO_ARID_DEF.Delay3_DSTATE[3] = ctdd_a_yrsLongAcc_mps2;

    /* Update for Delay: '<S111>/Delay4' */
    swc_SCOO_ARID_DEF.icLoad_l = false;
    swc_SCOO_ARID_DEF.Delay4_DSTATE[0] = swc_SCOO_ARID_DEF.Delay4_DSTATE[1];
    swc_SCOO_ARID_DEF.Delay4_DSTATE[1] = swc_SCOO_ARID_DEF.Delay4_DSTATE[2];
    swc_SCOO_ARID_DEF.Delay4_DSTATE[2] = swc_SCOO_ARID_DEF.Delay4_DSTATE[3];
    swc_SCOO_ARID_DEF.Delay4_DSTATE[3] = swc_SCOO_ARID_DEF.Delay4_DSTATE[4];
    swc_SCOO_ARID_DEF.Delay4_DSTATE[4] = ctdd_a_yrsLongAcc_mps2;

    /* Update for Delay: '<S111>/Delay5' */
    swc_SCOO_ARID_DEF.icLoad_c = false;
    for (i = 0; i < 5; i++) {
      swc_SCOO_ARID_DEF.Delay5_DSTATE[i] = swc_SCOO_ARID_DEF.Delay5_DSTATE[i + 1];
    }

    swc_SCOO_ARID_DEF.Delay5_DSTATE[5] = ctdd_a_yrsLongAcc_mps2;

    /* End of Update for Delay: '<S111>/Delay5' */

    /* Update for Delay: '<S111>/Delay6' */
    swc_SCOO_ARID_DEF.icLoad_h = false;
    for (i = 0; i < 6; i++) {
      swc_SCOO_ARID_DEF.Delay6_DSTATE[i] = swc_SCOO_ARID_DEF.Delay6_DSTATE[i + 1];
    }

    swc_SCOO_ARID_DEF.Delay6_DSTATE[6] = ctdd_a_yrsLongAcc_mps2;

    /* End of Update for Delay: '<S111>/Delay6' */

    /* Update for Delay: '<S111>/Delay7' */
    swc_SCOO_ARID_DEF.icLoad_j = false;
    for (i = 0; i < 7; i++) {
      swc_SCOO_ARID_DEF.Delay7_DSTATE[i] = swc_SCOO_ARID_DEF.Delay7_DSTATE[i + 1];
    }

    swc_SCOO_ARID_DEF.Delay7_DSTATE[7] = ctdd_a_yrsLongAcc_mps2;

    /* End of Update for Delay: '<S111>/Delay7' */

    /* Update for Delay: '<S111>/Delay8' */
    swc_SCOO_ARID_DEF.icLoad_g = false;
    for (i = 0; i < 8; i++) {
      swc_SCOO_ARID_DEF.Delay8_DSTATE[i] = swc_SCOO_ARID_DEF.Delay8_DSTATE[i + 1];
    }

    swc_SCOO_ARID_DEF.Delay8_DSTATE[8] = ctdd_a_yrsLongAcc_mps2;

    /* End of Update for Delay: '<S111>/Delay8' */
    /* End of Outputs for S-Function (fcgen): '<S118>/Function-Call Generator' */
  }

  /* End of RelationalOperator: '<S116>/Relational Operator1' */
  /* End of Outputs for SubSystem: '<S116>/Enabled Subsystem' */

  /* RelationalOperator: '<S115>/Compare' incorporates:
   *  Constant: '<S115>/Constant'
   */
  rtb_Relay = (swc_SCOO_ARID_DEF.DataTypeConversion5 <
               ctdc_v_crpSlopeStopThr_kph);

  /* Outputs for Atomic SubSystem: '<S85>/turnON_delay' */
  /* Saturate: '<S117>/Saturation' incorporates:
   *  Constant: '<S85>/Constant22'
   */
  if (ctdc_tm_crpSlopeStopDly_s > 1.6777216E+7F) {
    /* Saturate: '<S117>/Saturation' */
    rtb_t_delay_on_d = 1.6777216E+7F;
  } else if (ctdc_tm_crpSlopeStopDly_s < 0.0F) {
    /* Saturate: '<S117>/Saturation' */
    rtb_t_delay_on_d = 0.0F;
  } else {
    /* Saturate: '<S117>/Saturation' */
    rtb_t_delay_on_d = ctdc_tm_crpSlopeStopDly_s;
  }

  /* End of Saturate: '<S117>/Saturation' */

  /* Chart: '<S117>/timed_delay' incorporates:
   *  Constant: '<S85>/Constant21'
   *  DataTypeConversion: '<S117>/Data Type Conversion'
   */
  if (swc_SCOO_ARID_DEF.is_active_c14_Ricardo_SW_dev_li == 0U) {
    swc_SCOO_ARID_DEF.is_active_c14_Ricardo_SW_dev_li = 1U;
    if (rtb_Relay) {
      swc_SCOO_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_SCOO_IN_ON_b;
      ctdd_b_crpSlopeStopStd = true;
    } else {
      swc_SCOO_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_SCOO_IN_OFF_c;
      ctdd_b_crpSlopeStopStd = false;
    }
  } else {
    switch (swc_SCOO_ARID_DEF.is_c14_Ricardo_SW_dev_lib) {
     case swc_SCOO_IN_OFF_c:
      if (rtb_Relay) {
        if (rtb_t_delay_on_d == 0.0F) {
          swc_SCOO_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_SCOO_IN_ON_b;
          ctdd_b_crpSlopeStopStd = true;
        } else {
          swc_SCOO_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_SCOO_IN_ON_WAIT_i;
          swc_SCOO_ARID_DEF.t_wait = ((float32)CTD_TASK_INTERVAL_S);
          ctdd_b_crpSlopeStopStd = false;
        }
      } else {
        ctdd_b_crpSlopeStopStd = false;
      }
      break;

     case swc_SCOO_IN_ON_b:
      if (!rtb_Relay) {
        swc_SCOO_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_SCOO_IN_OFF_c;
        ctdd_b_crpSlopeStopStd = false;
      } else {
        ctdd_b_crpSlopeStopStd = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtb_Relay) {
        swc_SCOO_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_SCOO_IN_OFF_c;
        ctdd_b_crpSlopeStopStd = false;
      } else if (swc_SCOO_ARID_DEF.t_wait > rtb_t_delay_on_d - ((float32)
                  CTD_TASK_INTERVAL_S)) {
        swc_SCOO_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_SCOO_IN_ON_b;
        ctdd_b_crpSlopeStopStd = true;
      } else {
        swc_SCOO_ARID_DEF.t_wait += ((float32)CTD_TASK_INTERVAL_S);
        ctdd_b_crpSlopeStopStd = false;
      }
      break;
    }
  }

  /* End of Chart: '<S117>/timed_delay' */
  /* End of Outputs for SubSystem: '<S85>/turnON_delay' */

  /* Logic: '<S85>/Logical Operator1' incorporates:
   *  Constant: '<S114>/Constant'
   *  RelationalOperator: '<S114>/Compare'
   */
  ctdd_b_crpSlopeTrqOffsetEn = ((ctdd_a_yrsLongAccSgm_mps2 <
    ctdc_a_crpSlopeGradThr_mps2) && ctdd_b_crpSlopeStopStd);

  /* Logic: '<S86>/Logical Operator3' */
  rtb_Relay = (ctdd_b_crpSlopeTrqOffsetEn && ctdd_b_eCreepReq);

  /* RelationalOperator: '<S126>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S126>/Delay Input1'
   *
   * Block description for '<S126>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator_i = ((sint32)rtb_Relay > (sint32)
    swc_SCOO_ARID_DEF.DelayInput1_DSTATE);

  /* Switch: '<S86>/Switch1' */
  if (rtb_FixPtRelationalOperator_i) {
    /* Switch: '<S86>/Switch1' */
    rtb_t_delay_on_d = ctdd_a_yrsLongAccAvg_mps2;
  } else {
    /* Switch: '<S86>/Switch1' incorporates:
     *  Delay: '<S86>/Delay'
     */
    rtb_t_delay_on_d = swc_SCOO_ARID_DEF.Delay_DSTATE;
  }

  /* End of Switch: '<S86>/Switch1' */

  /* Logic: '<S86>/Logical Operator8' incorporates:
   *  Logic: '<S86>/Logical Operator7'
   */
  rtb_LogicalOperator8_e = ((!ctdd_b_eCreepReq) ||
    swc_SCOO_ARID_DEF.DataTypeConversion39);

  /* Outputs for Atomic SubSystem: '<S86>/SR_latch' */
  swc_SCOO_SR_latch(rtb_FixPtRelationalOperator_i, rtb_LogicalOperator8_e,
                    &swc_SCOO_ARID_DEF.ARID_DEF_SR_latch);

  /* End of Outputs for SubSystem: '<S86>/SR_latch' */

  /* Switch: '<S120>/Switch' incorporates:
   *  UnitDelay: '<S120>/init'
   */
  if (swc_SCOO_ARID_DEF.init_DSTATE) {
    /* Switch: '<S86>/Switch' incorporates:
     *  Constant: '<S121>/Constant'
     *  Constant: '<S122>/Constant'
     *  Constant: '<S123>/Constant'
     *  Constant: '<S124>/Constant'
     *  Constant: '<S127>/Constant'
     *  Constant: '<S128>/Constant'
     *  Logic: '<S86>/Logical Operator'
     *  Logic: '<S86>/Logical Operator1'
     *  Logic: '<S86>/Logical Operator2'
     *  Logic: '<S86>/Logical Operator5'
     *  RelationalOperator: '<S121>/Compare'
     *  RelationalOperator: '<S122>/Compare'
     *  RelationalOperator: '<S123>/Compare'
     *  RelationalOperator: '<S124>/Compare'
     *  RelationalOperator: '<S86>/Relational Operator'
     *  RelationalOperator: '<S86>/Relational Operator1'
     */
    if ((((rtb_t_delay_on_d <= ctdc_a_yrsLongAccAvgUpD_mps2) &&
          (rtb_t_delay_on_d >= ctdc_a_yrsLongAccAvgDnD_mps2) &&
          (ctdd_b_CreepEnabled_tmp == DriveDir_FORWARD)) || ((rtb_t_delay_on_d <=
           ctdc_a_yrsLongAccAvgUpR_mps2) && (rtb_t_delay_on_d >=
           ctdc_a_yrsLongAccAvgDnR_mps2) && (ctdd_b_CreepEnabled_tmp ==
           DriveDir_REVERSE))) && ctdd_b_crpSlopeTrqOffsetEnHld) {
      /* DataTypeConversion: '<S120>/Data Type Conversion3' incorporates:
       *  Lookup_n-D: '<S84>/1-D Lookup Table2'
       */
      ctdd_a_yrsLongAccAvgVld_mps2 = rtb_t_delay_on_d;
    } else {
      /* DataTypeConversion: '<S120>/Data Type Conversion3' incorporates:
       *  Constant: '<S86>/Constant'
       *  Lookup_n-D: '<S84>/1-D Lookup Table2'
       */
      ctdd_a_yrsLongAccAvgVld_mps2 = 0.0F;
    }
  } else {
    float32 tmp;

    /* Product: '<S120>/Divide' incorporates:
     *  Constant: '<S86>/Constant2'
     *  Constant: '<S86>/Constant4'
     *  DataTypeConversion: '<S120>/Data Type Conversion1'
     *  DataTypeConversion: '<S120>/Data Type Conversion2'
     *  Sum: '<S120>/Add1'
     */
    rtb_Divide_i = ctdc_fact_roadSlopeFilt / (ctdc_fact_roadSlopeFilt +
      ((float32)CTD_TASK_INTERVAL_S));

    /* Switch: '<S86>/Switch' incorporates:
     *  Constant: '<S121>/Constant'
     *  Constant: '<S122>/Constant'
     *  Constant: '<S123>/Constant'
     *  Constant: '<S124>/Constant'
     *  Constant: '<S127>/Constant'
     *  Constant: '<S128>/Constant'
     *  Constant: '<S86>/Constant'
     *  Logic: '<S86>/Logical Operator'
     *  Logic: '<S86>/Logical Operator1'
     *  Logic: '<S86>/Logical Operator2'
     *  Logic: '<S86>/Logical Operator5'
     *  RelationalOperator: '<S121>/Compare'
     *  RelationalOperator: '<S122>/Compare'
     *  RelationalOperator: '<S123>/Compare'
     *  RelationalOperator: '<S124>/Compare'
     *  RelationalOperator: '<S86>/Relational Operator'
     *  RelationalOperator: '<S86>/Relational Operator1'
     */
    if ((((rtb_t_delay_on_d <= ctdc_a_yrsLongAccAvgUpD_mps2) &&
          (rtb_t_delay_on_d >= ctdc_a_yrsLongAccAvgDnD_mps2) &&
          (ctdd_b_CreepEnabled_tmp == DriveDir_FORWARD)) || ((rtb_t_delay_on_d <=
           ctdc_a_yrsLongAccAvgUpR_mps2) && (rtb_t_delay_on_d >=
           ctdc_a_yrsLongAccAvgDnR_mps2) && (ctdd_b_CreepEnabled_tmp ==
           DriveDir_REVERSE))) && ctdd_b_crpSlopeTrqOffsetEnHld) {
      tmp = rtb_t_delay_on_d;
    } else {
      tmp = 0.0F;
    }

    /* DataTypeConversion: '<S120>/Data Type Conversion3' incorporates:
     *  Constant: '<S120>/Constant'
     *  Lookup_n-D: '<S84>/1-D Lookup Table2'
     *  Product: '<S120>/Product'
     *  Product: '<S120>/Product1'
     *  Sum: '<S120>/Add'
     *  Sum: '<S120>/Add2'
     *  Switch: '<S86>/Switch'
     *  UnitDelay: '<S120>/Unit Delay'
     */
    ctdd_a_yrsLongAccAvgVld_mps2 = (1.0F - rtb_Divide_i) * tmp + rtb_Divide_i *
      ctdd_a_yrsLongAccAvgVld_mps2;
  }

  /* End of Switch: '<S120>/Switch' */

  /* RelationalOperator: '<S98>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S98>/Delay Input1'
   *
   * Block description for '<S98>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_SCOO_ARID_DEF.FixPtRelationalOperator = ((sint32)ctdd_b_eCreepReq >
    (sint32)swc_SCOO_ARID_DEF.DelayInput1_DSTATE_n);

  /* Outputs for Atomic SubSystem: '<S84>/determine_creep_vel_tgt' */
  swc_SCO_determine_creep_vel_tgt(swc_SCOO_ARID_DEF.DataTypeConversion2,
    swc_SCOO_ARID_DEF.DataTypeConversion42, vsld_v_vehMaxSpdLimpHome_kph);

  /* End of Outputs for SubSystem: '<S84>/determine_creep_vel_tgt' */

  /* Switch: '<S84>/Switch1' incorporates:
   *  Constant: '<S101>/Constant'
   *  Constant: '<S96>/Constant'
   *  Constant: '<S97>/Constant'
   *  Constant: '<S99>/Constant'
   *  Gain: '<S84>/Gain'
   *  Logic: '<S84>/Logical Operator'
   *  Logic: '<S84>/Logical Operator1'
   *  Logic: '<S84>/Logical Operator2'
   *  RelationalOperator: '<S84>/Relational Operator'
   *  RelationalOperator: '<S84>/Relational Operator1'
   *  RelationalOperator: '<S96>/Compare'
   *  RelationalOperator: '<S97>/Compare'
   */
  if (((swc_SCOO_ARID_DEF.DataTypeConversion37 < 0.0) &&
       (ctdd_b_CreepEnabled_tmp == DriveDir_FORWARD)) ||
      ((ctdd_b_CreepEnabled_tmp == DriveDir_REVERSE) &&
       (swc_SCOO_ARID_DEF.DataTypeConversion37 >= 0.0))) {
    swc_SCOO_ARID_DEF.Switch1 = (-1.0F) * swc_SCOO_ARID_DEF.DataTypeConversion5;
  } else {
    swc_SCOO_ARID_DEF.Switch1 = swc_SCOO_ARID_DEF.DataTypeConversion5;
  }

  /* End of Switch: '<S84>/Switch1' */

  /* Switch: '<S84>/Switch2' incorporates:
   *  Constant: '<S99>/Constant'
   *  RelationalOperator: '<S84>/Relational Operator1'
   *  RelationalOperator: '<S84>/Relational Operator2'
   */
  if (ctdd_b_CreepEnabled_tmp == DriveDir_REVERSE) {
    /* Switch: '<S84>/Switch2' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion5'
     *  Lookup_n-D: '<S84>/1-D Lookup Table4'
     */
    rtb_Divide_i = look1_iflf_binlcapw(swc_SCOO_ARID_DEF.DataTypeConversion5, (
      const float32 *)&ctdf_slopeTrqOffsetRFact_X_VehSpd_kph[0], (const float32 *)
      &ctdf_slopeTrqOffsetRFact_Y[0], 6U);
  } else {
    /* Switch: '<S84>/Switch2' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion5'
     *  Lookup_n-D: '<S84>/1-D Lookup Table3'
     */
    rtb_Divide_i = look1_iflf_binlcapw(swc_SCOO_ARID_DEF.DataTypeConversion5, (
      const float32 *)&ctdf_slopeTrqOffsetFact_X_VehSpd_kph[0], (const float32 *)
      &ctdf_slopeTrqOffsetFact_Y[0], 6U);
  }

  /* End of Switch: '<S84>/Switch2' */

  /* Product: '<S84>/Product' incorporates:
   *  DataTypeConversion: '<S120>/Data Type Conversion3'
   *  Lookup_n-D: '<S84>/1-D Lookup Table2'
   */
  swc_SCOO_ARID_DEF.Product = rtb_Divide_i * look1_iflf_binlcapw
    (ctdd_a_yrsLongAccAvgVld_mps2, (const float32 *)
     &ctdf_crpTgtTqFFMap_X_RoadSlope_deg[0], (const float32 *)
     &ctdf_crpTgtTqFFMap_Y_Nm[0], 8U);

  /* Sum: '<S84>/Sum' */
  rtb_Sum_o = ctdd_v_vehCrpTgt_kph - swc_SCOO_ARID_DEF.DataTypeConversion5;

  /* Outputs for Atomic SubSystem: '<S84>/determine_pi_factors' */
  swc_SCOO_determine_pi_factors(rtb_Sum_o);

  /* End of Outputs for SubSystem: '<S84>/determine_pi_factors' */

  /* Sum: '<S84>/Plus' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   *  Lookup_n-D: '<S84>/1-D Lookup Table1'
   *  MinMax: '<S84>/MinMax3'
   */
  swc_SCOO_ARID_DEF.Plus = swc_SCOO_ARID_DEF.Product + fminf(look1_iflf_binlcapw
    (swc_SCOO_ARID_DEF.DataTypeConversion5, (const float32 *)
     &ctdf_whlTqMaxMap_X_VehSpd_kph[0], (const float32 *)&ctdf_whlTqMaxMap_Y_Nm
     [0], 3U), swc_SCOO_ARID_DEF.DataTypeConversion10);

  /* Outputs for Atomic SubSystem: '<S84>/PID_FeedForward' */
  swc_SCOO_PID_FeedForward_f();

  /* End of Outputs for SubSystem: '<S84>/PID_FeedForward' */

  /* Logic: '<S86>/Logical Operator4' incorporates:
   *  Constant: '<S125>/Constant'
   *  Constant: '<S86>/Constant1'
   *  Logic: '<S86>/Logical Operator6'
   *  RelationalOperator: '<S125>/Compare'
   */
  rtb_LogicalOperator4_a = ((swc_SCOO_ARID_DEF.DataTypeConversion5 >=
    ctdc_v_slopeTrqOffsetSpdDisa_kph) || (!ctdc_b_slopeTrqOffsetEn));

  /* Switch: '<S3>/Switch' */
  if (ctdd_b_eCreepReq) {
    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<S3>/Constant7'
     */
    rtb_Switch_a = 0.0F;
  } else {
    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<S3>/Constant3'
     */
    rtb_Switch_a = ((float32)WHL_TRQ_MIN);
  }

  /* End of Switch: '<S3>/Switch' */

  /* Outputs for Atomic SubSystem: '<S3>/SwitchRampCreepTrqDem' */
  /* Constant: '<S3>/Constant4' incorporates:
   *  Constant: '<S3>/Constant5'
   */
  swc_SCOO_SwitchRampCreepTrqDem(ctdd_tq_whlDemRaw_Nm, ctdd_b_eCreepReq,
    rtb_Switch_a, ctdc_dtq_CrpTqEnaIncGrad_Nmps, ctdc_dtq_CrpTqDisDecGrad_Nmps,
    &rtb_RampOn_b, &swc_SCOO_ARID_DEF.ARID_DEF_SwitchRampCreepTrqDem);

  /* End of Outputs for SubSystem: '<S3>/SwitchRampCreepTrqDem' */

  /* Update for UnitDelay: '<S116>/Unit Delay' */
  swc_SCOO_ARID_DEF.UnitDelay_DSTATE = rtb_Add_m;

  /* Update for UnitDelay: '<S126>/Delay Input1'
   *
   * Block description for '<S126>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_SCOO_ARID_DEF.DelayInput1_DSTATE = rtb_Relay;

  /* Update for Delay: '<S86>/Delay' */
  swc_SCOO_ARID_DEF.Delay_DSTATE = rtb_t_delay_on_d;

  /* Update for UnitDelay: '<S120>/init' incorporates:
   *  Constant: '<S120>/Constant1'
   */
  swc_SCOO_ARID_DEF.init_DSTATE = false;

  /* Update for UnitDelay: '<S98>/Delay Input1'
   *
   * Block description for '<S98>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_SCOO_ARID_DEF.DelayInput1_DSTATE_n = ctdd_b_eCreepReq;
}

/* Output and update for atomic system: '<S137>/PI_adjustable' */
static void swc_SCOO_PI_adjustable(void)
{
  float32 rtb_Switch_mw;
  float32 rtb_error;
  boolean rtb_AboveMax;
  boolean rtb_BelowMin;

  /* Sum: '<S141>/Sum' */
  rtb_error = vsld_v_vehMaxSpd_kph - swc_SCOO_ARID_DEF.DataTypeConversion5;

  /* Switch: '<S143>/Switch1' incorporates:
   *  Switch: '<S143>/Switch'
   *  UnitDelay: '<S141>/ClippedPrev'
   */
  if (swc_SCOO_ARID_DEF.LogicalOperator_m) {
    /* Switch: '<S143>/Switch1' incorporates:
     *  Constant: '<S143>/Constant'
     */
    rtb_Switch_mw = 0.0F;
  } else {
    if (swc_SCOO_ARID_DEF.ClippedPrev_DSTATE) {
      /* Switch: '<S143>/Switch' incorporates:
       *  Constant: '<S143>/Constant'
       */
      rtb_Switch_mw = 0.0F;
    } else {
      /* Switch: '<S143>/Switch' incorporates:
       *  Constant: '<S137>/Constant2'
       *  Product: '<S143>/Product2'
       */
      rtb_Switch_mw = rtb_error * vsld_fact_vehSpdLimCtrlKi * ((float32)
        VSL_TASK_INTERVAL_S);
    }

    /* Switch: '<S143>/Switch1' incorporates:
     *  Sum: '<S143>/Sum1'
     *  Switch: '<S143>/Switch'
     *  UnitDelay: '<S143>/Unit Delay'
     */
    rtb_Switch_mw += swc_SCOO_ARID_DEF.UnitDelay_DSTATE_b;
  }

  /* End of Switch: '<S143>/Switch1' */

  /* Sum: '<S141>/rawdmd' incorporates:
   *  Product: '<S144>/Product'
   */
  rtb_error = rtb_error * vsld_fact_vehSpdLimCtrlKp + rtb_Switch_mw;

  /* RelationalOperator: '<S142>/AboveMax' */
  rtb_AboveMax = (swc_SCOO_ARID_DEF.DataTypeConversion10 < rtb_error);

  /* RelationalOperator: '<S142>/BelowMin' */
  rtb_BelowMin = (rtb_error < swc_SCOO_ARID_DEF.Switch_h);

  /* Switch: '<S142>/Switch' incorporates:
   *  Switch: '<S142>/Switch1'
   */
  if (rtb_AboveMax) {
    /* Switch: '<S142>/Switch' */
    vsld_tq_whlMaxTqLim_Nm = swc_SCOO_ARID_DEF.DataTypeConversion10;
  } else if (rtb_BelowMin) {
    /* Switch: '<S142>/Switch1' incorporates:
     *  Switch: '<S142>/Switch'
     */
    vsld_tq_whlMaxTqLim_Nm = swc_SCOO_ARID_DEF.Switch_h;
  } else {
    /* Switch: '<S142>/Switch' incorporates:
     *  Switch: '<S142>/Switch1'
     */
    vsld_tq_whlMaxTqLim_Nm = rtb_error;
  }

  /* End of Switch: '<S142>/Switch' */

  /* Update for UnitDelay: '<S141>/ClippedPrev' incorporates:
   *  Logic: '<S141>/OutsideLimit'
   */
  swc_SCOO_ARID_DEF.ClippedPrev_DSTATE = (rtb_AboveMax || rtb_BelowMin);

  /* Update for UnitDelay: '<S143>/Unit Delay' */
  swc_SCOO_ARID_DEF.UnitDelay_DSTATE_b = rtb_Switch_mw;
}

/* Output and update for enable system: '<S4>/VehicleSpeedClosedLoopControl' */
static void s_VehicleSpeedClosedLoopControl(void)
{
  /* Outputs for Enabled SubSystem: '<S4>/VehicleSpeedClosedLoopControl' incorporates:
   *  EnablePort: '<S137>/Enable'
   */
  if (vsld_b_vehSpdLimrEnad) {
    float32 rtb_Sum_m;

    /* Logic: '<S137>/Logical Operator' */
    swc_SCOO_ARID_DEF.LogicalOperator_m = !vsld_b_vehSpdLimrIntglEnad;

    /* Sum: '<S140>/Sum' */
    rtb_Sum_m = vsld_v_vehMaxSpd_kph - swc_SCOO_ARID_DEF.DataTypeConversion5;

    /* Lookup_n-D: '<S140>/2-D Lookup Table' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion5'
     *  Sum: '<S140>/Sum'
     */
    vsld_fact_vehSpdLimCtrlKp = look2_iflf_binlcapw
      (swc_SCOO_ARID_DEF.DataTypeConversion5, rtb_Sum_m, (const float32 *)
       &vsla_SpdLimCtrl_X_VehSpd_kph[0], (const float32 *)
       &vsla_SpdLimCtrl_Y_VehSpdErr_kph[0], (const float32 *)
       &vslm_SpdLimCtrlKp_Z_fact[0], swc_SCOO_ConstP.pooled11, 11U);

    /* Lookup_n-D: '<S140>/2-D Lookup Table1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion5'
     *  Sum: '<S140>/Sum'
     */
    vsld_fact_vehSpdLimCtrlKi = look2_iflf_binlcapw
      (swc_SCOO_ARID_DEF.DataTypeConversion5, rtb_Sum_m, (const float32 *)
       &vsla_SpdLimCtrl_X_VehSpd_kph[0], (const float32 *)
       &vsla_SpdLimCtrl_Y_VehSpdErr_kph[0], (const float32 *)
       &vslm_SpdLimCtrlKi_Z_fact[0], swc_SCOO_ConstP.pooled11, 11U);

    /* Switch: '<S137>/Switch' incorporates:
     *  Constant: '<S137>/Constant1'
     */
    if (swc_SCOO_ARID_DEF.Relay2) {
      swc_SCOO_ARID_DEF.Switch_h = swc_SCOO_ARID_DEF.DataTypeConversion15;
    } else {
      swc_SCOO_ARID_DEF.Switch_h = 0.0F;
    }

    /* End of Switch: '<S137>/Switch' */

    /* Outputs for Atomic SubSystem: '<S137>/PI_adjustable' */
    swc_SCOO_PI_adjustable();

    /* End of Outputs for SubSystem: '<S137>/PI_adjustable' */
  }

  /* End of Outputs for SubSystem: '<S4>/VehicleSpeedClosedLoopControl' */
}

/* Output and update for function-call system: '<S1>/VSL_VehicleSpeedLimiter' */
static void swc_SCO_VSL_VehicleSpeedLimiter(void)
{
  float32 rtb_Sum1_f;
  float32 tmp;
  float32 tmp_0;
  DriveDir tmp_2;
  boolean tmp_1;

  /* Switch: '<S146>/Switch2' incorporates:
   *  Constant: '<S148>/Constant'
   *  RelationalOperator: '<S148>/Compare'
   *  Switch: '<S146>/Switch3'
   *  Switch: '<S146>/Switch5'
   */
  if (swc_SCOO_ARID_DEF.DataTypeConversion12 != 0.0) {
    /* Switch: '<S146>/Switch4' incorporates:
     *  Constant: '<S147>/Constant'
     *  RelationalOperator: '<S147>/Compare'
     */
    if (swc_SCOO_ARID_DEF.DataTypeConversion18 > 0.0F) {
      /* Switch: '<S146>/Switch2' */
      vsld_v_vehMaxCfgSpd_kph = swc_SCOO_ARID_DEF.DataTypeConversion18;
    } else {
      /* Switch: '<S146>/Switch2' incorporates:
       *  Constant: '<S146>/Constant20'
       */
      vsld_v_vehMaxCfgSpd_kph = vslc_v_vehMaxSpdFwdEco_kph;
    }

    /* End of Switch: '<S146>/Switch4' */
  } else if (swc_SCOO_ARID_DEF.DataTypeConversion21 != 0.0) {
    /* Switch: '<S146>/Switch6' incorporates:
     *  Constant: '<S149>/Constant'
     *  RelationalOperator: '<S149>/Compare'
     *  Switch: '<S146>/Switch3'
     */
    if (swc_SCOO_ARID_DEF.DataTypeConversion20 > 0.0F) {
      /* Switch: '<S146>/Switch2' incorporates:
       *  Switch: '<S146>/Switch3'
       */
      vsld_v_vehMaxCfgSpd_kph = swc_SCOO_ARID_DEF.DataTypeConversion20;
    } else {
      /* Switch: '<S146>/Switch2' incorporates:
       *  Constant: '<S146>/Constant21'
       *  Switch: '<S146>/Switch3'
       */
      vsld_v_vehMaxCfgSpd_kph = vslc_v_vehMaxSpdFwdPwr_kph;
    }

    /* End of Switch: '<S146>/Switch6' */
  } else if (swc_SCOO_ARID_DEF.DataTypeConversion19 > 0.0F) {
    /* Switch: '<S146>/Switch5' incorporates:
     *  Switch: '<S146>/Switch2'
     *  Switch: '<S146>/Switch3'
     */
    vsld_v_vehMaxCfgSpd_kph = swc_SCOO_ARID_DEF.DataTypeConversion19;
  } else {
    /* Switch: '<S146>/Switch2' incorporates:
     *  Constant: '<S146>/Constant22'
     *  Switch: '<S146>/Switch3'
     *  Switch: '<S146>/Switch5'
     */
    vsld_v_vehMaxCfgSpd_kph = vslc_v_vehMaxSpdFwdNorm_kph;
  }

  /* End of Switch: '<S146>/Switch2' */

  /* RelationalOperator: '<S146>/Relational Operator2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  RelationalOperator: '<S4>/Relational Operator2'
   */
  tmp_2 = swc_SCOO_ARID_DEF.DataTypeConversion2;

  /* Switch: '<S146>/Switch' incorporates:
   *  Constant: '<S150>/Constant'
   *  RelationalOperator: '<S146>/Relational Operator2'
   */
  if (tmp_2 == DriveDir_REVERSE) {
    /* Switch: '<S146>/Switch1' */
    if (swc_SCOO_ARID_DEF.DataTypeConversion25 != 0.0) {
      /* Switch: '<S146>/Switch' incorporates:
       *  Constant: '<S146>/Constant1'
       */
      vsld_v_vehMaxAllwdSpd_kph = vslc_v_vehMaxSpdRvsDrv1_kph;
    } else {
      /* Switch: '<S146>/Switch' incorporates:
       *  Constant: '<S146>/Constant2'
       */
      vsld_v_vehMaxAllwdSpd_kph = vslc_v_vehMaxSpdRvsDrv_kph;
    }

    /* End of Switch: '<S146>/Switch1' */
  } else {
    /* Switch: '<S146>/Switch' */
    vsld_v_vehMaxAllwdSpd_kph = vsld_v_vehMaxCfgSpd_kph;
  }

  /* End of Switch: '<S146>/Switch' */

  /* Switch: '<S145>/Switch1' incorporates:
   *  Constant: '<S145>/Constant1'
   *  Constant: '<S145>/Constant3'
   */
  if (swc_SCOO_ARID_DEF.DataTypeConversion30 != 0.0) {
    rtb_Sum1_f = vslc_v_vehMaxSpdLimpHome1_kph;
  } else {
    rtb_Sum1_f = ((float32)VEH_SPD_MAX);
  }

  /* Switch: '<S145>/Switch2' incorporates:
   *  Constant: '<S145>/Constant4'
   *  Constant: '<S145>/Constant5'
   */
  if (swc_SCOO_ARID_DEF.DataTypeConversion32 != 0.0) {
    tmp = vslc_v_vehMaxSpdLimpHome2_kph;
  } else {
    tmp = ((float32)VEH_SPD_MAX);
  }

  /* Switch: '<S145>/Switch3' incorporates:
   *  Constant: '<S145>/Constant7'
   *  Constant: '<S145>/Constant8'
   *  MinMax: '<S145>/MinMax1'
   */
  if (vslc_b_rmtCtrlSpdLmtEn) {
    tmp_0 = fminf(swc_SCOO_ARID_DEF.DataTypeConversion17,
                  swc_SCOO_ARID_DEF.DataTypeConversion24);
  } else {
    tmp_0 = ((float32)VEH_SPD_MAX);
  }

  /* MinMax: '<S145>/MinMax3' incorporates:
   *  Switch: '<S145>/Switch1'
   *  Switch: '<S145>/Switch2'
   *  Switch: '<S145>/Switch3'
   */
  vsld_v_vehMaxSpdLimpHome_kph = fminf(fminf(rtb_Sum1_f, tmp), tmp_0);

  /* MinMax: '<S138>/MinMax1' incorporates:
   *  Constant: '<S138>/Constant1'
   *  Constant: '<S138>/Constant8'
   *  MinMax: '<S138>/MinMax2'
   *  Sum: '<S138>/Plus'
   */
  vsld_v_vehMaxSpd_kph = fminf(fminf(vslc_v_vehMaxSpd, vsld_v_vehMaxAllwdSpd_kph)
    + vslc_v_vehMaxSpderr, vsld_v_vehMaxSpdLimpHome_kph);

  /* Sum: '<S133>/Sum1' incorporates:
   *  Sum: '<S133>/Sum'
   */
  rtb_Sum1_f = vsld_v_vehMaxSpd_kph - swc_SCOO_ARID_DEF.DataTypeConversion5;

  /* Relay: '<S133>/Relay1' */
  swc_SCOO_ARID_DEF.Relay1_Mode = ((rtb_Sum1_f >= vslc_v_vehSpdErrCtrlEnagHi_kph)
    || ((rtb_Sum1_f > vslc_v_vehSpdErrCtrlEnagLo_kph) &&
        swc_SCOO_ARID_DEF.Relay1_Mode));
  if (swc_SCOO_ARID_DEF.Relay1_Mode) {
    tmp_1 = false;
  } else {
    tmp_1 = true;
  }

  /* Logic: '<S133>/Logical Operator' incorporates:
   *  Constant: '<S133>/Constant2'
   *  Relay: '<S133>/Relay1'
   */
  vsld_b_vehSpdLimrEnad = (vslc_b_enaVehSpdLimr && tmp_1);

  /* Relay: '<S133>/Relay4' */
  swc_SCOO_ARID_DEF.Relay4_Mode = ((rtb_Sum1_f >=
    vslc_v_vehSpdErrIntglEnagHi_kph) || ((rtb_Sum1_f >
    vslc_v_vehSpdErrIntglEnagLo_kph) && swc_SCOO_ARID_DEF.Relay4_Mode));
  if (swc_SCOO_ARID_DEF.Relay4_Mode) {
    tmp_1 = false;
  } else {
    tmp_1 = true;
  }

  /* Logic: '<S133>/Logical Operator1' incorporates:
   *  Relay: '<S133>/Relay4'
   */
  vsld_b_vehSpdLimrIntglEnad = (vsld_b_vehSpdLimrEnad && tmp_1);

  /* Sum: '<S133>/Sum1' */
  rtb_Sum1_f = vsld_v_vehMaxCfgSpd_kph - swc_SCOO_ARID_DEF.DataTypeConversion5;

  /* Relay: '<S133>/Relay2' */
  swc_SCOO_ARID_DEF.Relay2_Mode = ((rtb_Sum1_f >= vslc_v_vehSpdErrCtrlCfgHi_kph)
    || ((rtb_Sum1_f > vslc_v_vehSpdErrCtrlCfgLo_kph) &&
        swc_SCOO_ARID_DEF.Relay2_Mode));
  if (swc_SCOO_ARID_DEF.Relay2_Mode) {
    swc_SCOO_ARID_DEF.Relay2 = false;
  } else {
    swc_SCOO_ARID_DEF.Relay2 = true;
  }

  /* End of Relay: '<S133>/Relay2' */

  /* SignalConversion: '<S4>/Signal Conversion5' */
  vsld_b_vslTqIntvReq = vsld_b_vehSpdLimrEnad;

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S132>/Constant'
   *  Constant: '<S134>/Constant'
   *  Constant: '<S135>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion41'
   *  Logic: '<S4>/Logical Operator'
   *  RelationalOperator: '<S132>/Compare'
   *  RelationalOperator: '<S4>/Relational Operator2'
   *  RelationalOperator: '<S4>/Relational Operator4'
   *  Switch: '<S4>/Switch1'
   */
  if ((tmp_2 == DriveDir_NO_DRIVE) || (swc_SCOO_ARID_DEF.DataTypeConversion41 !=
       PmmStatus_DRIVE)) {
    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/Constant'
     */
    swc_SCOO_ARID_DEF.Switch = 0.0F;
  } else if (vsld_v_vehMaxSpd_kph >= 70.0F) {
    /* Switch: '<S4>/Switch1' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Sum: '<S4>/Plus'
     *  Switch: '<S4>/Switch'
     */
    swc_SCOO_ARID_DEF.Switch = vsld_v_vehMaxSpd_kph - vslc_v_vehMaxSpderr;
  } else {
    /* Switch: '<S4>/Switch' incorporates:
     *  Switch: '<S4>/Switch1'
     */
    swc_SCOO_ARID_DEF.Switch = vsld_v_vehMaxSpd_kph;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Outputs for Enabled SubSystem: '<S4>/VehicleSpeedClosedLoopControl' */
  s_VehicleSpeedClosedLoopControl();

  /* End of Outputs for SubSystem: '<S4>/VehicleSpeedClosedLoopControl' */

  /* Switch: '<S136>/Switch' incorporates:
   *  Switch: '<S136>/Switch1'
   */
  if (vsld_b_vehSpdLimrEnad) {
    /* MinMax: '<S136>/MinMax2' incorporates:
     *  Constant: '<S136>/Constant3'
     *  MinMax: '<S136>/MinMax1'
     */
    rtb_Sum1_f = fminf(vsld_tq_whlMaxTqLim_Nm, ((float32)WHL_TRQ_MAX));

    /* Switch: '<S136>/Switch' incorporates:
     *  MinMax: '<S136>/MinMax2'
     */
    vsld_tq_whlMaxTqLimSlow_Nm = rtb_Sum1_f;

    /* Switch: '<S136>/Switch1' */
    vsld_tq_whlMaxTqLimFast_Nm = rtb_Sum1_f;
  } else {
    /* Switch: '<S136>/Switch' incorporates:
     *  Constant: '<S136>/Constant3'
     */
    vsld_tq_whlMaxTqLimSlow_Nm = ((float32)WHL_TRQ_MAX);

    /* Switch: '<S136>/Switch1' incorporates:
     *  Constant: '<S136>/Constant1'
     */
    vsld_tq_whlMaxTqLimFast_Nm = ((float32)WHL_TRQ_MAX);
  }

  /* End of Switch: '<S136>/Switch' */
}

/* Model step function */
void swc_SCOO_Step(void)
{
  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Inport generated from: '<Root>/In Bus Element1'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion1 =
    Rte_IRead_swc_SCOO_Step_vcsb_VOMM_vsmd_b_VehRun();

  /* DataTypeConversion: '<Root>/Data Type Conversion10' incorporates:
   *  Inport generated from: '<Root>/In Bus Element12'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion10 =
    Rte_IRead_swc_SCOO_Step_vcsb_SCAP_tqld_tq_whlMax_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion11' incorporates:
   *  Inport generated from: '<Root>/In Bus Element14'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion11 =
    Rte_IRead_swc_SCOO_Step_vcsb_TCOO_apdd_tq_whlDem_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion12' incorporates:
   *  Inport generated from: '<Root>/In Bus Element10'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion12 =
    Rte_IRead_swc_SCOO_Step_vcsb_VOMM_drid_b_vehEcoModActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion13' incorporates:
   *  Inport generated from: '<Root>/In Bus Element17'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion13 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_vscd_st_ehbEPBDynAppSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion14' incorporates:
   *  Inport generated from: '<Root>/In Bus Element19'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion14 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_vscd_st_ehbHHCActive();

  /* DataTypeConversion: '<Root>/Data Type Conversion15' incorporates:
   *  Inport generated from: '<Root>/In Bus Element15'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion15 =
    Rte_IRead_swc_SCOO_Step_vcsb_TCOO_dtdd_tq_whlCstDrgDemNoEhb_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion16' incorporates:
   *  Inport generated from: '<Root>/In Bus Element8'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion16 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_epbd_e_parkingSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion17' incorporates:
   *  Inport generated from: '<Root>/Bus Element In1'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion17 =
    Rte_IRead_swc_SCOO_Step_vcsb_RMLK_rlcd_v_rmtCtrlFctSpdLim_kph();

  /* DataTypeConversion: '<Root>/Data Type Conversion18' incorporates:
   *  Inport generated from: '<Root>/In Bus Element20'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion18 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_st_flgFctCfgECOMaxSpd();

  /* DataTypeConversion: '<Root>/Data Type Conversion19' incorporates:
   *  Inport generated from: '<Root>/In Bus Element21'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion19 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd();

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Inport generated from: '<Root>/In Bus Element2'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion2 =
    Rte_IRead_swc_SCOO_Step_vcsb_VOMM_drid_e_driveDirSel();

  /* DataTypeConversion: '<Root>/Data Type Conversion20' incorporates:
   *  Inport generated from: '<Root>/In Bus Element22'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion20 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_st_flgFctCfgPowerMaxSpd();

  /* DataTypeConversion: '<Root>/Data Type Conversion21' incorporates:
   *  Inport generated from: '<Root>/In Bus Element11'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion21 =
    Rte_IRead_swc_SCOO_Step_vcsb_VOMM_drid_b_vehSportModActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion22' incorporates:
   *  Inport generated from: '<Root>/In Bus Element23'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion22 =
    Rte_IRead_swc_SCOO_Step_vcsb_TCOO_tqdd_b_ehbDisEnbCreep();

  /* DataTypeConversion: '<Root>/Data Type Conversion5' incorporates:
   *  Inport generated from: '<Root>/In Bus Element6'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion5 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_vscd_v_vehSpd_kph();

  /* DataTypeConversion: '<Root>/Data Type Conversion24' incorporates:
   *  Inport generated from: '<Root>/In Bus Element24'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion24 =
    Rte_IRead_swc_SCOO_Step_vcsb_OGVL_dtld_v_dstSpdLim_kph();

  /* DataTypeConversion: '<Root>/Data Type Conversion25' incorporates:
   *  Inport generated from: '<Root>/In Bus Element25'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion25 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_vscd_b_ehbTrqDecReqActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion30' incorporates:
   *  Inport generated from: '<Root>/In Bus Element28'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion30 =
    Rte_IRead_swc_SCOO_Step_vcsb_DIAG_digd_b_VehLvl22Flt_flg();

  /* DataTypeConversion: '<Root>/Data Type Conversion32' incorporates:
   *  Inport generated from: '<Root>/In Bus Element29'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion32 =
    Rte_IRead_swc_SCOO_Step_vcsb_DIAG_digd_b_VehLvl23Flt_flg();

  /* DataTypeConversion: '<Root>/Data Type Conversion41' incorporates:
   *  Inport generated from: '<Root>/In Bus Element16'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion41 =
    Rte_IRead_swc_SCOO_Step_vcsb_HVSM_hvbd_e_PmmStatus();

  /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
   *  Inport generated from: '<Root>/In Bus Element5'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion4 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_brpd_e_brkPedalStatus();

  /* DataTypeConversion: '<Root>/Data Type Conversion42' incorporates:
   *  Inport generated from: '<Root>/In Bus Element18'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion42 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_brpd_x_brkPedlPos_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion26' incorporates:
   *  Inport generated from: '<Root>/In Bus Element26'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion26 =
    Rte_IRead_swc_SCOO_Step_vcsb_TCOO_dtdd_tq_whlDragDem_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion31' incorporates:
   *  Inport generated from: '<Root>/In Bus Element13'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion31 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_st_vscEHBAVHSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion27' incorporates:
   *  Inport generated from: '<Root>/In Bus Element27'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion27 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_a_yrsLongitAcce_mps2();

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion33'
   *  DataTypeConversion: '<Root>/Data Type Conversion34'
   *  DataTypeConversion: '<Root>/Data Type Conversion35'
   *  Inport generated from: '<Root>/In Bus Element30'
   *  Inport generated from: '<Root>/In Bus Element31'
   *  Inport generated from: '<Root>/In Bus Element33'
   */
  swc_SCOO_ARID_DEF.LogicalOperator =
    (Rte_IRead_swc_SCOO_Step_vcsb_DIAG_digd_b_VehLvl31Flt_flg() ||
     Rte_IRead_swc_SCOO_Step_vcsb_DIAG_digd_b_VehLvl32Flt_flg() ||
     Rte_IRead_swc_SCOO_Step_vcsb_DIAG_digd_b_VehLvl33Flt_flg());

  /* DataTypeConversion: '<Root>/Data Type Conversion36' incorporates:
   *  Inport generated from: '<Root>/In Bus Element32'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion36 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_vscd_b_vehSpdVld();

  /* DataTypeConversion: '<Root>/Data Type Conversion37' incorporates:
   *  Inport generated from: '<Root>/In Bus Element34'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion37 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_eadd_n_mot2ActSpd_rpm();

  /* DataTypeConversion: '<Root>/Data Type Conversion38' incorporates:
   *  Inport generated from: '<Root>/In Bus Element35'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion38 =
    Rte_IRead_swc_SCOO_Step_vcsb_DIAG_brpd_b_brkSwtMismatch();

  /* DataTypeConversion: '<Root>/Data Type Conversion39' incorporates:
   *  Inport generated from: '<Root>/In Bus Element36'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion39 =
    (Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_st_flgFctCfgVehCfg() != 0);

  /* DataTypeConversion: '<Root>/Data Type Conversion40' incorporates:
   *  Inport generated from: '<Root>/In Bus Element37'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion40 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld();

  /* DataTypeConversion: '<Root>/Data Type Conversion43' incorporates:
   *  Inport generated from: '<Root>/In Bus Element38'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion43 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion44' incorporates:
   *  Inport generated from: '<Root>/In Bus Element39'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion44 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_b_bcmFrntRDrAjSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion45' incorporates:
   *  Inport generated from: '<Root>/In Bus Element40'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion45 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_b_flgFctCfgDrvSeat();

  /* DataTypeConversion: '<Root>/Data Type Conversion46' incorporates:
   *  Inport generated from: '<Root>/In Bus Element41'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion46 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_b_bcmFrntLftDrAjSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion9' incorporates:
   *  Inport generated from: '<Root>/In Bus Element'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion9 =
    Rte_IRead_swc_SCOO_Step_vcsb_HMIF_dspd_st_vehFailLvl();

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Inport generated from: '<Root>/In Bus Element3'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion3 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_ccdd_u_cruiseADvoltage_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion7' incorporates:
   *  Inport generated from: '<Root>/In Bus Element4'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion7 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_acpd_x_accPedlPos_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
   *  Inport generated from: '<Root>/In Bus Element7'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion6 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_vscd_b_ESPActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion8' incorporates:
   *  Inport generated from: '<Root>/In Bus Element9'
   */
  swc_SCOO_ARID_DEF.DataTypeConversion8 =
    Rte_IRead_swc_SCOO_Step_vcib_VCIP_vscd_b_vehSlipWarn();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/CCD_CruiseControlDemand'
   */
  swc_SCO_CCD_CruiseControlDemand();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/CTD_CreepDemand'
   */
  swc_SCOO_CTD_CreepDemand();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/VSL_VehicleSpeedLimiter'
   */
  swc_SCO_VSL_VehicleSpeedLimiter();

  /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator' */

  /* Outport generated from: '<Root>/Out Bus Element25' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion85'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_tq_whlDemRawAdv_Nm
    (ccdd_tq_whlDemRawAdv_Nm);

  /* Outport generated from: '<Root>/Out Bus Element26' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion86'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_acc_vehAccTgt_mps2
    (ccdd_acc_vehAccTgt_mps2);

  /* Outport generated from: '<Root>/Out Bus Element28' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion88'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_b_accCtrlActv(ccdd_b_accCtrlActv);

  /* Outport generated from: '<Root>/Out Bus Element27' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion87'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_acc_intAccTgt_mps2
    (ccdd_acc_intAccTgt_mps2);

  /* Outport generated from: '<Root>/Out Bus Element' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion84'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_e_crsCtrlSts(ccdd_e_crsCtrlSts);

  /* Outport generated from: '<Root>/Out Bus Element1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion83'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_v_crsCtrlTgtSpd_kph
    (ccdd_v_crsCtrlTgtSpd_kph);

  /* Outport generated from: '<Root>/Out Bus Element2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion82'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_e_crsCtrlSpdMode(ccdd_e_crsCtrlSpdMode);

  /* Outport generated from: '<Root>/Out Bus Element3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion81'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_e_crsBtnSts(ccdd_e_crsBtnSts);

  /* Outport generated from: '<Root>/Out Bus Element4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion80'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_v_crsTgtSpdQuit_kph
    (ccdd_v_crsTgtSpdQuit_kph);

  /* Outport generated from: '<Root>/Out Bus Element5' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion79'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_tq_whlDem_Nm(ccdd_tq_whlDem_Nm);

  /* Outport generated from: '<Root>/Out Bus Element6' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion78'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_b_crsCtrlAccPedlOvrd
    (ccdd_b_crsCtrlAccPedlOvrd);

  /* Outport generated from: '<Root>/Out Bus Element7' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion77'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_e_crsBtnErrSts(ccdd_e_crsBtnErrSts);

  /* Outport generated from: '<Root>/Out Bus Element8' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion76'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_x_accPedlPosVirt_pct
    (ccdd_x_accPedlPosVirt_pct);

  /* Outport generated from: '<Root>/Out Bus Element10' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion74'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ctdd_tq_whlDem_Nm(ctdd_tq_whlDem_Nm);

  /* Outport generated from: '<Root>/Out Bus Element11' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion73'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ctdd_b_eCreepReq(ctdd_b_eCreepReq);

  /* Outport generated from: '<Root>/Out Bus Element12' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion72'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ctdd_n_vehTgtCrpSpdFwd_kph
    (ctdd_n_vehTgtCrpSpdFwd_kph);

  /* Outport generated from: '<Root>/Out Bus Element13' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion71'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_vsld_b_vslTqIntvReq(vsld_b_vslTqIntvReq);

  /* Outport generated from: '<Root>/Out Bus Element14' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion70'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_vsld_tq_whlMaxTqLimFast_Nm
    (vsld_tq_whlMaxTqLimFast_Nm);

  /* Outport generated from: '<Root>/Out Bus Element15' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion69'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_vsld_tq_whlMaxTqLimSlow_Nm
    (vsld_tq_whlMaxTqLimSlow_Nm);

  /* Outport generated from: '<Root>/Out Bus Element9' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion23'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_vsld_v_vehMaxCfgSpd_kph
    (vsld_v_vehMaxCfgSpd_kph);

  /* Outport generated from: '<Root>/Out Bus Element16' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion29'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ctdd_b_crpSlopeTrqOffsetEnHld
    (ctdd_b_crpSlopeTrqOffsetEnHld);

  /* Outport generated from: '<Root>/Out Bus Element17' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion28'
   */
  Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ctdd_a_yrsLongAccAvgVld_mps2
    (ctdd_a_yrsLongAccAvgVld_mps2);

  /* Outport generated from: '<Root>/Out Bus Element18' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion47'
   */
  (void)Rte_Write_vcsb_SCOO_vsld_v_vehMaxSpd_kph(swc_SCOO_ARID_DEF.Switch);
}

/* Model initialize function */
void swc_SCOO_Init(void)
{
  /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/CCD_CruiseControlDemand'
   */
  sw_CCD_CruiseControlDemand_Init();

  /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/CTD_CreepDemand'
   */
  swc_SCOO_CTD_CreepDemand_Init();

  /* End of SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

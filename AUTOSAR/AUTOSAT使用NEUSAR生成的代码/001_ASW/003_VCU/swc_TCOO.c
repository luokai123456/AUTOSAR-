/*
 * File: swc_TCOO.c
 *
 * Code generated for Simulink model 'swc_TCOO'.
 *
 * Model version                  : 6.575
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Sep 21 15:11:05 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "swc_TCOO.h"
#include "rtwtypes.h"
#include <math.h>
#include "Rte_Type.h"
#include "const_ImportedDefine.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef APD_TASK_INTERVAL_S
#error The value of parameter "APD_TASK_INTERVAL_S" is not defined
#endif

#ifndef DTD_TASK_INTERVAL_S
#error The value of parameter "DTD_TASK_INTERVAL_S" is not defined
#endif

#ifndef EAD_TASK_INTERVAL_S
#error The value of parameter "EAD_TASK_INTERVAL_S" is not defined
#endif

#ifndef KPH_2_MPS
#error The value of parameter "KPH_2_MPS" is not defined
#endif

#ifndef RADpS_2_RPM
#error The value of parameter "RADpS_2_RPM" is not defined
#endif

#ifndef TDA_TASK_INTERVAL_S
#error The value of parameter "TDA_TASK_INTERVAL_S" is not defined
#endif

#ifndef TRQ_ZERO
#error The value of parameter "TRQ_ZERO" is not defined
#endif

#ifndef WHL_TRQ_MAX
#error The value of parameter "WHL_TRQ_MAX" is not defined
#endif

#ifndef WHL_TRQ_MIN
#error The value of parameter "WHL_TRQ_MIN" is not defined
#endif

#ifndef VEH_SWT_INF
#error The value of parameter "VEH_SWT_INF" is not defined
#endif

/* Named constants for Chart: '<S84>/timed_delay' */
#define swc_TCOO_IN_OFF                ((uint8)1U)
#define swc_TCOO_IN_ON                 ((uint8)2U)
#define swc_TCOO_IN_ON_WAIT            ((uint8)3U)

/* Named constants for Chart: '<S130>/timed_delay' */
#define swc_TCOO_IN_OFF_WAIT           ((uint8)2U)
#define swc_TCOO_IN_OFF_m              ((uint8)1U)
#define swc_TCOO_IN_ON_p               ((uint8)3U)

/* Named constants for Chart: '<S433>/Chart' */
#define swc_TCOO_IN_NO_ACTIVE_CHILD    ((uint8)0U)
#define swc_TCOO_IN_U1                 ((uint8)1U)
#define swc_TCOO_IN_U1_TO_U2           ((uint8)2U)
#define swc_TCOO_IN_U1_TO_U2_DEC       ((uint8)1U)
#define swc_TCOO_IN_U1_TO_U2_INC       ((uint8)2U)
#define swc_TCOO_IN_U2                 ((uint8)3U)
#define swc_TCOO_IN_U2_TO_U1           ((uint8)4U)
#define swc_TCOO_IN_U2_TO_U1_DEC       ((uint8)1U)
#define swc_TCOO_IN_U2_TO_U1_INC       ((uint8)2U)

/* Named constants for Chart: '<S436>/Chart' */
#define swc_TCOO_IN_NO_ACTIVE_CHILD_b  ((uint8)0U)
#define swc_TCOO_IN_U1_TO_U2_DEC_k     ((uint8)1U)
#define swc_TCOO_IN_U1_TO_U2_INC_j     ((uint8)2U)
#define swc_TCOO_IN_U1_TO_U2_l         ((uint8)2U)
#define swc_TCOO_IN_U1_f               ((uint8)1U)
#define swc_TCOO_IN_U2_TO_U1_DEC_a     ((uint8)1U)
#define swc_TCOO_IN_U2_TO_U1_INC_p     ((uint8)2U)
#define swc_TCOO_IN_U2_TO_U1_h         ((uint8)4U)
#define swc_TCOO_IN_U2_k               ((uint8)3U)

/* Named constants for Chart: '<S442>/Chart' */
#define swc_TCOO_IN_NO_ACTIVE_CHILD_h  ((uint8)0U)
#define swc_TCOO_IN_U1_TO_U2_DEC_i     ((uint8)1U)
#define swc_TCOO_IN_U1_TO_U2_INC_i     ((uint8)2U)
#define swc_TCOO_IN_U1_TO_U2_i         ((uint8)2U)
#define swc_TCOO_IN_U1_o               ((uint8)1U)
#define swc_TCOO_IN_U2_TO_U1_DEC_m     ((uint8)1U)
#define swc_TCOO_IN_U2_TO_U1_INC_pd    ((uint8)2U)
#define swc_TCOO_IN_U2_TO_U1_l         ((uint8)4U)
#define swc_TCOO_IN_U2_p               ((uint8)3U)

/* Named constants for Chart: '<S79>/CoastingDrgAutoModeKCal' */
#define swc_TCOO_IN_CALCK              ((uint8)1U)
#define swc_TCOO_IN_IINI_K             ((uint8)2U)
#define swc_TCOO_IN_QUITCALK           ((uint8)3U)
#define swc_TCOO_IN_QUITCALK_WAIT      ((uint8)4U)

/* Named constants for Chart: '<S223>/TorqueRange' */
#define swc_TCOO_IN_BRAKING_NEG        ((uint8)1U)
#define swc_TCOO_IN_BRAKING_POS        ((uint8)1U)
#define swc_TCOO_IN_NO_ACTIVE_CHILD_hl ((uint8)0U)
#define swc_TCOO_IN_PEDAL_TIP_IN       ((uint8)1U)
#define swc_TCOO_IN_PEDAL_TIP_OUT      ((uint8)2U)
#define swc_TCOO_IN_POWER_NEG          ((uint8)2U)
#define swc_TCOO_IN_POWER_POS          ((uint8)2U)
#define swc_TCOO_IN_ZEROCROSS_NEG      ((uint8)3U)
#define swc_TCOO_IN_ZEROCROSS_POS      ((uint8)3U)

/* Exported data definition */
#define swc_TCOO_START_SEC_CONST_VOLATILE
#include "swc_TCOO_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_CAL */
const volatile float32 apda_trqDemGearD_Y_EngSpd_rpm[12] = { 500.0F, 1500.0F,
  2000.0F, 3000.0F, 4000.0F, 5000.0F, 6000.0F, 8000.0F, 9000.0F, 11000.0F,
  12000.0F, 13000.0F } ;               /* Referenced by:
                                        * '<S34>/2-D Lookup Table1'
                                        * '<S35>/2-D Lookup Table'
                                        * '<S36>/2-D Lookup Table1'
                                        * '<S49>/2-D Lookup Table1'
                                        * '<S51>/2-D Lookup Table1'
                                        * '<S64>/2-D Lookup Table1'
                                        * '<S66>/2-D Lookup Table1'
                                        */

/* Driver Pedal Map in Gear D - Vehicle Speed Axis */
const volatile float32 apda_trqDemGearE_Y_EngSpd_rpm[12] = { 500.0F, 1500.0F,
  2000.0F, 3000.0F, 4000.0F, 5000.0F, 6000.0F, 8000.0F, 9000.0F, 11000.0F,
  12000.0F, 13000.0F } ;           /* Referenced by: '<S33>/2-D Lookup Table' */

const volatile float32 apda_trqDemGearS_Y_EngSpd_rpm[12] = { 1000.0F, 1500.0F,
  2000.0F, 3000.0F, 4500.0F, 5000.0F, 6000.0F, 8000.0F, 9000.0F, 11000.0F,
  12000.0F, 13000.0F } ;               /* Referenced by:
                                        * '<S37>/2-D Lookup Table'
                                        * '<S38>/2-D Lookup Table1'
                                        * '<S53>/2-D Lookup Table1'
                                        * '<S68>/2-D Lookup Table1'
                                        */

/* Driver Pedal Map in Gear S - Vehicle Speed Axis */
const volatile boolean apdc_b_trsmGearTgt_ovrdflg = true;
                         /* Referenced by: '<S69>/apdc_b_trsmGearTgt_ovrdflg' */

/* Override flag for apdd_st_trsmGearTgt */
const volatile boolean apdc_b_useSportMapsIn4WDMode = true;/* Referenced by:
                                                            * '<S21>/Constant17'
                                                            * '<S22>/Constant17'
                                                            * '<S23>/Constant17'
                                                            */

/* Use Sport Pedal Maps in 4WD Mode */
const volatile float32 apdc_frac_pedalDeadBandHigh_pct = 1.5F;/* Referenced by: '<S11>/Relay' */

/* Pedal dead band high threshold */
const volatile float32 apdc_frac_pedalDeadBandLow_pct = 0.5F;/* Referenced by: '<S11>/Relay' */

/* Pedal dead band low threshold */
const volatile sint8 apdc_st_trsmGearTgt_ovrdval = 1;
                        /* Referenced by: '<S69>/apdc_st_trsmGearTgt_ovrdval' */

/* Override value for apdd_st_trsmGearTgt */
const volatile float32 apdc_tm_engMdlActSpdFilter_s = 0.2F;/* Referenced by: '<S10>/Constant17' */

/* Engine Modeled Actual Speed Time constant filter */
const volatile float32 apdm_trqDemGearD1_X_PedPos_pct[11] = { 0.0F, 10.0F, 20.0F,
  30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F } ;/* Referenced by:
                                                              * '<S35>/2-D Lookup Table'
                                                              * '<S50>/2-D Lookup Table'
                                                              * '<S65>/2-D Lookup Table'
                                                              */

/* Driver Pedal Map in Gear D1 - Pedal Position Axis */
const volatile float32 apdm_trqDemGearD1_Z_Nm[132] = { 0.0F, 33.1F, 66.2F, 88.3F,
  110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F, 0.0F, 33.1F, 66.2F,
  88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F, 0.0F, 33.1F,
  66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F, 0.0F,
  33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F,
  0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F,
  220.8F, 0.0F, 30.7F, 61.3F, 81.8F, 102.2F, 122.6F, 143.1F, 163.5F, 184.0F,
  194.2F, 204.4F, 0.0F, 25.2F, 50.4F, 67.2F, 84.0F, 100.8F, 117.5F, 134.3F,
  151.1F, 159.6F, 168.0F, 0.0F, 17.9F, 35.7F, 47.6F, 59.5F, 71.4F, 83.3F, 95.2F,
  107.1F, 113.0F, 119.0F, 0.0F, 15.7F, 31.4F, 41.9F, 52.3F, 62.7F, 73.2F, 83.7F,
  94.1F, 99.4F, 104.6F, 0.0F, 12.4F, 24.8F, 33.0F, 41.2F, 49.5F, 57.7F, 66.0F,
  74.3F, 78.4F, 82.5F, 0.0F, 11.1F, 22.2F, 29.6F, 36.9F, 44.3F, 51.7F, 59.1F,
  66.5F, 70.2F, 73.9F, 0.0F, 10.1F, 20.2F, 26.9F, 33.6F, 40.3F, 47.0F, 53.7F,
  60.4F, 63.8F, 67.1F } ;          /* Referenced by: '<S35>/2-D Lookup Table' */

/* Driver Pedal Map in Gear D1 - Torque Demand */
const volatile float32 apdm_trqDemGearD2_X_PedPos_pct[11] = { 0.0F, 10.0F, 20.0F,
  30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F } ;/* Referenced by:
                                                              * '<S34>/2-D Lookup Table1'
                                                              * '<S36>/2-D Lookup Table1'
                                                              * '<S49>/2-D Lookup Table1'
                                                              * '<S51>/2-D Lookup Table1'
                                                              * '<S64>/2-D Lookup Table1'
                                                              * '<S66>/2-D Lookup Table1'
                                                              */

/* Driver Pedal Map in Gear D2 - Pedal Position Axis */
const volatile float32 apdm_trqDemGearD2_Z_Nm[132] = { 0.0F, 44.0F, 88.0F,
  132.0F, 176.0F, 220.0F, 264.0F, 308.0F, 352.0F, 396.0F, 440.0F, 0.0F, 44.0F,
  88.0F, 132.0F, 176.0F, 220.0F, 264.0F, 308.0F, 352.0F, 396.0F, 440.0F, 0.0F,
  44.0F, 88.0F, 132.0F, 176.0F, 220.0F, 264.0F, 308.0F, 352.0F, 396.0F, 440.0F,
  0.0F, 44.0F, 88.0F, 132.0F, 176.0F, 220.0F, 264.0F, 308.0F, 352.0F, 396.0F,
  440.0F, 0.0F, 44.0F, 88.0F, 132.0F, 176.0F, 220.0F, 264.0F, 308.0F, 352.0F,
  396.0F, 440.0F, 0.0F, 44.0F, 88.0F, 132.0F, 176.0F, 220.0F, 264.0F, 308.0F,
  352.0F, 396.0F, 440.0F, 0.0F, 44.0F, 88.0F, 132.0F, 176.0F, 220.0F, 264.0F,
  308.0F, 352.0F, 396.0F, 440.0F, 0.0F, 44.0F, 88.0F, 132.0F, 176.0F, 220.0F,
  264.0F, 308.0F, 352.0F, 396.0F, 440.0F, 0.0F, 44.0F, 88.0F, 132.0F, 176.0F,
  220.0F, 264.0F, 308.0F, 352.0F, 396.0F, 440.0F, 0.0F, 44.0F, 88.0F, 132.0F,
  176.0F, 220.0F, 264.0F, 308.0F, 352.0F, 396.0F, 440.0F, 0.0F, 44.0F, 88.0F,
  132.0F, 176.0F, 220.0F, 264.0F, 308.0F, 352.0F, 396.0F, 440.0F, 0.0F, 44.0F,
  88.0F, 132.0F, 176.0F, 220.0F, 264.0F, 308.0F, 352.0F, 396.0F, 440.0F } ;/* Referenced by:
                                                                      * '<S34>/2-D Lookup Table1'
                                                                      * '<S36>/2-D Lookup Table1'
                                                                      * '<S49>/2-D Lookup Table1'
                                                                      * '<S51>/2-D Lookup Table1'
                                                                      * '<S64>/2-D Lookup Table1'
                                                                      * '<S66>/2-D Lookup Table1'
                                                                      */

/* Driver Pedal Map in Gear D2 - Torque Demand */
const volatile float32 apdm_trqDemGearE1_X_PedPos_pct[11] = { 0.0F, 10.0F, 20.0F,
  30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F } ;/* Referenced by:
                                                              * '<S33>/2-D Lookup Table'
                                                              * '<S48>/2-D Lookup Table'
                                                              * '<S63>/2-D Lookup Table'
                                                              */

const volatile float32 apdm_trqDemGearE1_Z_Nm[132] = { 0.0F, 33.1F, 66.2F, 88.3F,
  110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F, 0.0F, 33.1F, 66.2F,
  88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F, 0.0F, 33.1F,
  66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F, 0.0F,
  33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F,
  0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F,
  220.8F, 0.0F, 30.7F, 61.3F, 81.8F, 102.2F, 122.6F, 143.1F, 163.5F, 184.0F,
  194.2F, 204.4F, 0.0F, 25.2F, 50.4F, 67.2F, 84.0F, 100.8F, 117.5F, 134.3F,
  151.1F, 159.6F, 168.0F, 0.0F, 17.9F, 35.7F, 47.6F, 59.5F, 71.4F, 83.3F, 95.2F,
  107.1F, 113.0F, 119.0F, 0.0F, 15.7F, 31.4F, 41.9F, 52.3F, 62.7F, 73.2F, 83.7F,
  94.1F, 99.4F, 104.6F, 0.0F, 12.4F, 24.8F, 33.0F, 41.2F, 49.5F, 57.7F, 66.0F,
  74.3F, 78.4F, 82.5F, 0.0F, 11.1F, 22.2F, 29.6F, 36.9F, 44.3F, 51.7F, 59.1F,
  66.5F, 70.2F, 73.9F, 0.0F, 10.1F, 20.2F, 26.9F, 33.6F, 40.3F, 47.0F, 53.7F,
  60.4F, 63.8F, 67.1F } ;          /* Referenced by: '<S33>/2-D Lookup Table' */

const volatile float32 apdm_trqDemGearN_X_PedPos_pct[11] = { 0.0F, 10.0F, 20.0F,
  30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F } ;/* Referenced by:
                                                              * '<S27>/2-D Lookup Table'
                                                              * '<S42>/2-D Lookup Table'
                                                              * '<S57>/2-D Lookup Table'
                                                              */

/* Driver Pedal Map in Gear N - Pedal Position Axis */
const volatile float32 apdm_trqDemGearN_Y_EngSpd_rpm[12] = { 1000.0F, 1500.0F,
  2000.0F, 3000.0F, 4500.0F, 5000.0F, 6000.0F, 8000.0F, 9000.0F, 11000.0F,
  12000.0F, 13000.0F } ;               /* Referenced by:
                                        * '<S27>/2-D Lookup Table'
                                        * '<S42>/2-D Lookup Table'
                                        * '<S57>/2-D Lookup Table'
                                        */

/* Driver Pedal Map in Gear N - Vehicle Speed Axis */
const volatile float32 apdm_trqDemGearN_Z_Nm[132] = { 0.0F, -0.0F, -0.0F, -0.0F,
  -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0F, -0.0F, -0.0F, -0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0F, -0.0F, -0.0F, -0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0F, -0.0F, -0.0F, -0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0F, -0.0F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, -0.0F, -0.0F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, -0.0F, -0.0F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, -0.0F, -0.0F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, -0.0F, -0.0F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  -0.0F, -0.0F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0F,
  -0.0F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0F, -0.0F,
  -0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;
                                   /* Referenced by: '<S27>/2-D Lookup Table' */

/* Driver Pedal Map in Gear N - Torque Demand */
const volatile float32 apdm_trqDemGearR_X_PedPos_pct[11] = { 0.0F, 10.0F, 20.0F,
  30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F } ;/* Referenced by:
                                                              * '<S28>/2-D Lookup Table'
                                                              * '<S28>/2-D Lookup Table1'
                                                              * '<S43>/2-D Lookup Table'
                                                              * '<S43>/2-D Lookup Table1'
                                                              * '<S58>/2-D Lookup Table'
                                                              * '<S58>/2-D Lookup Table1'
                                                              */

/* Driver Pedal Map in Gear R - Pedal Position Axis */
const volatile float32 apdm_trqDemGearR_Y_EngSpd_rpm[12] = { 500.0F, 1000.0F,
  1500.0F, 1550.0F, 2300.0F, 2500.0F, 3000.0F, 9000.0F, 10000.0F, 11000.0F,
  12000.0F, 13000.0F } ;               /* Referenced by:
                                        * '<S28>/2-D Lookup Table'
                                        * '<S28>/2-D Lookup Table1'
                                        * '<S43>/2-D Lookup Table'
                                        * '<S43>/2-D Lookup Table1'
                                        * '<S58>/2-D Lookup Table'
                                        * '<S58>/2-D Lookup Table1'
                                        */

/* Driver Pedal Map in Gear R - Vehicle Speed Axis */
const volatile float32 apdm_trqDemGearR_Z_Nm[132] = { 0.0F, 33.1F, 66.2F, 88.3F,
  110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F, 0.0F, 33.1F, 66.2F,
  88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F, 0.0F, 33.1F,
  66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F, 0.0F,
  33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F,
  0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F,
  220.8F, 0.0F, 30.7F, 61.3F, 81.8F, 102.2F, 122.6F, 143.1F, 163.5F, 184.0F,
  194.2F, 204.4F, 0.0F, 25.2F, 50.4F, 67.2F, 84.0F, 100.8F, 117.5F, 134.3F,
  151.1F, 159.6F, 168.0F, 0.0F, 17.9F, 35.7F, 47.6F, 59.5F, 71.4F, 83.3F, 95.2F,
  107.1F, 113.0F, 119.0F, 0.0F, 15.7F, 31.4F, 41.9F, 52.3F, 62.7F, 73.2F, 83.7F,
  94.1F, 99.4F, 104.6F, 0.0F, 12.4F, 24.8F, 33.0F, 41.2F, 49.5F, 57.7F, 66.0F,
  74.3F, 78.4F, 82.5F, 0.0F, 11.1F, 22.2F, 29.6F, 36.9F, 44.3F, 51.7F, 59.1F,
  66.5F, 70.2F, 73.9F, 0.0F, 10.1F, 20.2F, 26.9F, 33.6F, 40.3F, 47.0F, 53.7F,
  60.4F, 63.8F, 67.1F } ;          /* Referenced by: '<S28>/2-D Lookup Table' */

/* Driver Pedal Map in Gear R - Torque Demand */
const volatile float32 apdm_trqDemGearS1_X_PedPos_pct[11] = { 0.0F, 10.0F, 20.0F,
  30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F } ;/* Referenced by:
                                                              * '<S37>/2-D Lookup Table'
                                                              * '<S52>/2-D Lookup Table'
                                                              * '<S67>/2-D Lookup Table'
                                                              */

/* Driver Pedal Map in Gear S1 - Pedal Position Axis */
const volatile float32 apdm_trqDemGearS1_Z_Nm[132] = { 0.0F, 33.1F, 66.2F, 88.3F,
  110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F, 0.0F, 33.1F, 66.2F,
  88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F, 0.0F, 33.1F,
  66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F, 0.0F,
  33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F,
  0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F,
  220.8F, 0.0F, 30.7F, 61.3F, 81.8F, 102.2F, 122.6F, 143.1F, 163.5F, 184.0F,
  194.2F, 204.4F, 0.0F, 25.2F, 50.4F, 67.2F, 84.0F, 100.8F, 117.5F, 134.3F,
  151.1F, 159.6F, 168.0F, 0.0F, 17.9F, 35.7F, 47.6F, 59.5F, 71.4F, 83.3F, 95.2F,
  107.1F, 113.0F, 119.0F, 0.0F, 15.7F, 31.4F, 41.9F, 52.3F, 62.7F, 73.2F, 83.7F,
  94.1F, 99.4F, 104.6F, 0.0F, 12.4F, 24.8F, 33.0F, 41.2F, 49.5F, 57.7F, 66.0F,
  74.3F, 78.4F, 82.5F, 0.0F, 11.1F, 22.2F, 29.6F, 36.9F, 44.3F, 51.7F, 59.1F,
  66.5F, 70.2F, 73.9F, 0.0F, 10.1F, 20.2F, 26.9F, 33.6F, 40.3F, 47.0F, 53.7F,
  60.4F, 63.8F, 67.1F } ;          /* Referenced by: '<S37>/2-D Lookup Table' */

/* Driver Pedal Map in Gear S1 - Torque Demand */
const volatile float32 apdm_trqDemGearS2_X_PedPos_pct[11] = { 0.0F, 10.0F, 20.0F,
  30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F } ;/* Referenced by:
                                                              * '<S38>/2-D Lookup Table1'
                                                              * '<S53>/2-D Lookup Table1'
                                                              * '<S68>/2-D Lookup Table1'
                                                              */

/* Driver Pedal Map in Gear S2 - Pedal Position Axis */
const volatile float32 apdm_trqDemGearS2_Z_Nm[132] = { 0.0F, 62.0F, 124.0F,
  186.0F, 248.0F, 310.0F, 372.0F, 434.0F, 496.0F, 558.0F, 620.0F, 0.0F, 62.0F,
  124.0F, 186.0F, 248.0F, 310.0F, 372.0F, 434.0F, 496.0F, 558.0F, 620.0F, 0.0F,
  62.0F, 124.0F, 186.0F, 248.0F, 310.0F, 372.0F, 434.0F, 496.0F, 558.0F, 620.0F,
  0.0F, 62.0F, 124.0F, 186.0F, 248.0F, 310.0F, 372.0F, 434.0F, 496.0F, 558.0F,
  620.0F, 0.0F, 62.0F, 124.0F, 186.0F, 248.0F, 310.0F, 372.0F, 434.0F, 496.0F,
  558.0F, 620.0F, 0.0F, 62.0F, 124.0F, 186.0F, 248.0F, 310.0F, 372.0F, 434.0F,
  496.0F, 558.0F, 620.0F, 0.0F, 62.0F, 124.0F, 186.0F, 248.0F, 310.0F, 372.0F,
  434.0F, 496.0F, 558.0F, 620.0F, 0.0F, 62.0F, 124.0F, 186.0F, 248.0F, 310.0F,
  372.0F, 434.0F, 496.0F, 558.0F, 620.0F, 0.0F, 62.0F, 124.0F, 186.0F, 248.0F,
  310.0F, 372.0F, 434.0F, 496.0F, 558.0F, 620.0F, 0.0F, 62.0F, 124.0F, 186.0F,
  248.0F, 310.0F, 372.0F, 434.0F, 496.0F, 558.0F, 620.0F, 0.0F, 62.0F, 124.0F,
  186.0F, 248.0F, 310.0F, 372.0F, 434.0F, 496.0F, 558.0F, 620.0F, 0.0F, 62.0F,
  124.0F, 186.0F, 248.0F, 310.0F, 372.0F, 434.0F, 496.0F, 558.0F, 620.0F } ;/* Referenced by:
                                                                      * '<S38>/2-D Lookup Table1'
                                                                      * '<S53>/2-D Lookup Table1'
                                                                      * '<S68>/2-D Lookup Table1'
                                                                      */

/* Driver Pedal Map in Gear S2 - Torque Demand */
const volatile float32 dtda_regBrkTrqDerate_X_VehSpd_kph[10] = { 0.0F, 3.0F,
  15.0F, 30.0F, 45.0F, 60.0F, 80.0F, 100.0F, 120.0F, 140.0F } ;
                                  /* Referenced by: '<S71>/1-D Lookup Table2' */

/* Brake Drag Torque Demand Derate X Axle - Vehicle Speed */
const volatile float32 dtda_regBrkTrqMap_X_BrkPres_bar[8] = { 0.0F, 3.0F, 15.0F,
  30.0F, 45.0F, 60.0F, 75.0F, 100.0F } ;
                                   /* Referenced by: '<S71>/1-D Lookup Table' */

/* Regenerative Braking Map - Brake Pressure Axis */
const volatile float32 dtda_trqDragDemEV_Y_VehSpd_kph[27] = { 0.0F, 5.0F, 10.0F,
  20.0F, 25.0F, 30.0F, 35.0F, 40.0F, 45.0F, 50.0F, 55.0F, 60.0F, 65.0F, 70.0F,
  75.0F, 80.0F, 85.0F, 90.0F, 95.0F, 100.0F, 105.0F, 110.0F, 115.0F, 120.0F,
  123.0F, 124.0F, 160.0F } ;           /* Referenced by:
                                        * '<S75>/1-D Lookup Table3'
                                        * '<S78>/1-D Lookup Table'
                                        * '<S78>/1-D Lookup Table3'
                                        * '<S78>/1-D Lookup Table5'
                                        * '<S78>/1-D Lookup Table6'
                                        */

/* Drag Torque Demand Map EV Mode - Vehicle Speed Axis */
const volatile uint8 dtdc_ECODefaultRegLvl = 2U;/* Referenced by: '<S86>/Constant22' */
const volatile uint8 dtdc_EEPDefaultRegLvl = 255U;/* Referenced by:
                                                   * '<S86>/Constant1'
                                                   * '<S86>/Constant2'
                                                   * '<S86>/Constant4'
                                                   */
const volatile uint8 dtdc_EEPDefaultRegLvl1 = 1U;/* Referenced by:
                                                  * '<S86>/Constant19'
                                                  * '<S86>/Constant30'
                                                  * '<S86>/Constant6'
                                                  */
const volatile uint8 dtdc_EEPDefaultRegLvl2 = 2U;/* Referenced by:
                                                  * '<S86>/Constant20'
                                                  * '<S86>/Constant31'
                                                  * '<S86>/Constant7'
                                                  */
const volatile uint8 dtdc_EEPDefaultRegLvl3 = 3U;/* Referenced by:
                                                  * '<S86>/Constant21'
                                                  * '<S86>/Constant32'
                                                  * '<S86>/Constant8'
                                                  */
const volatile float32 dtdc_EEPUpdDelay_s = 0.05F;/* Referenced by:
                                                   * '<S86>/Constant13'
                                                   * '<S86>/Constant36'
                                                   * '<S86>/Constant38'
                                                   * '<S87>/Constant15'
                                                   * '<S87>/Constant4'
                                                   */
const volatile uint8 dtdc_MaxCounterValue = 3U;/* Referenced by:
                                                * '<S88>/Constant2'
                                                * '<S88>/Constant3'
                                                * '<S88>/Constant35'
                                                */
const volatile uint8 dtdc_NormalDefaultRegLvl = 1U;/* Referenced by: '<S86>/Constant18' */
const volatile boolean dtdc_b_noUseGearLeverPos = true;/* Referenced by: '<S87>/Constant1' */
const volatile boolean dtdc_b_useIncEdgeCount = true;/* Referenced by: '<S89>/Constant4' */
const volatile boolean dtdc_b_useRgnOffEna = true;/* Referenced by: '<S87>/Constant12' */
const volatile boolean dtdc_b_useS2CstDrgTqOvrSpd = false;/* Referenced by: '<S75>/Constant7' */
const volatile boolean dtdc_b_useSportMapsIn4WDMode = true;/* Referenced by: '<S87>/Constant17' */

/* Use Sport Drag Maps in 4WD Mode */
const volatile uint8 dtdc_cnt_rgnOffEnaCount = 5U;/* Referenced by: '<S87>/Constant13' */
const volatile float32 dtdc_frac_rgnOffAccPdl_pct = 95.0F;/* Referenced by: '<S87>/Constant11' */
const volatile float32 dtdc_p_brkPresHighThd_bar = 8.0F;/* Referenced by: '<S78>/Relay' */
const volatile float32 dtdc_p_brkPresLowThd_bar = 6.0F;/* Referenced by: '<S78>/Relay' */
const volatile float32 dtdc_t_IgonInitTime_s = 0.03F;/* Referenced by:
                                                      * '<S87>/Constant6'
                                                      * '<S87>/Constant7'
                                                      */
const volatile boolean dtdc_useLvl123Ena = true;/* Referenced by:
                                                 * '<S86>/Constant12'
                                                 * '<S86>/Constant34'
                                                 * '<S86>/Constant9'
                                                 */
const volatile float32 dtdf_regBrkTrqDerate_Y_fact[10] = { 0.0F, 0.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F } ;
                                  /* Referenced by: '<S71>/1-D Lookup Table2' */

/* Brake Drag Torque Demand Derate Y Axle - factor */
const volatile float32 dtdf_regBrkTrqEVMap_Y_Nm[8] = { 0.0F, 0.0F, -1670.0F,
  -1670.0F, -1670.0F, -1250.0F, -800.0F, -800.0F } ;
                                   /* Referenced by: '<S71>/1-D Lookup Table' */

/* Regenerative Braking Map EV Mode - Torque Demand */
const volatile float32 dtdm_trqDragDemEVOffs1_Z_Nm[27] = { 0.0F, 0.0F, 0.0F,
  -291.0F, -291.0F, -303.0F, -303.0F, -291.0F, -267.0F, -242.0F, -242.0F,
  -230.0F, -230.0F, -218.0F, -218.0F, -206.0F, -182.0F, -146.0F, -134.0F,
  -121.0F, -109.0F, -97.0F, -97.0F, -97.0F, -97.0F, -97.0F, -279.0F } ;
                                  /* Referenced by: '<S78>/1-D Lookup Table5' */

/* Drag Torque Demand Offset1 Map EV Mode - Torque Demand */
const volatile float32 dtdm_trqDragDemEVOffs2_Z_Nm[27] = { 0.0F, 0.0F, 0.0F,
  -702.0F, -751.0F, -799.0F, -787.0F, -787.0F, -775.0F, -775.0F, -763.0F,
  -751.0F, -739.0F, -726.0F, -714.0F, -702.0F, -690.0F, -678.0F, -654.0F,
  -642.0F, -630.0F, -605.0F, -327.0F, -327.0F, -279.0F, -279.0F, -279.0F } ;/* Referenced by:
                                                                      * '<S75>/1-D Lookup Table3'
                                                                      * '<S78>/1-D Lookup Table3'
                                                                      */

/* Drag Torque Demand Offset2 Map EV Mode - Torque Demand */
const volatile float32 dtdm_trqDragDemEVOffs3_Z_Nm[27] = { 0.0F, 0.0F, 0.0F,
  -291.0F, -291.0F, -303.0F, -303.0F, -291.0F, -267.0F, -242.0F, -242.0F,
  -230.0F, -230.0F, -218.0F, -218.0F, -206.0F, -182.0F, -146.0F, -134.0F,
  -121.0F, -109.0F, -97.0F, -97.0F, -97.0F, -97.0F, -97.0F, -279.0F } ;
                                  /* Referenced by: '<S78>/1-D Lookup Table6' */

/* Drag Torque Demand Offset3 Map EV Mode - Torque Demand */
const volatile float32 dtdm_trqDragDemEV_Z_Nm[27] = { 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;
                                   /* Referenced by: '<S78>/1-D Lookup Table' */

/* Drag Torque Demand Map EV Mode - Torque Demand */
const volatile float32 eada_mot2ZeroCross_X_VehSpd_kph[6] = { 0.0F, 20.0F, 50.0F,
  80.0F, 100.0F, 120.0F } ;            /* Referenced by:
                                        * '<S188>/2-D Lookup Table'
                                        * '<S188>/2-D Lookup Table1'
                                        * '<S188>/2-D Lookup Table6'
                                        * '<S188>/2-D Lookup Table7'
                                        * '<S188>/2-D Lookup Table8'
                                        * '<S188>/2-D Lookup Table9'
                                        */

/* Motor zero-crossing filter gradient map - Vehicle Speed Axis */
const volatile float32 eada_mot2ZeroCross_Y_MotTrq_Nm[11] = { -350.0F, -100.0F,
  -60.0F, -10.0F, -3.0F, 0.0F, 3.0F, 10.0F, 30.0F, 100.0F, 350.0F } ;/* Referenced by:
                                                                      * '<S188>/2-D Lookup Table'
                                                                      * '<S188>/2-D Lookup Table1'
                                                                      * '<S188>/2-D Lookup Table6'
                                                                      * '<S188>/2-D Lookup Table7'
                                                                      * '<S188>/2-D Lookup Table8'
                                                                      * '<S188>/2-D Lookup Table9'
                                                                      */

/* Motor zero-crossing filter gradient map - motor torque Axis */
const volatile float32 eada_mot2ZroCrsAcceLmt_X_VehSpd_kph[6] = { 0.0F, 20.0F,
  40.0F, 60.0F, 80.0F, 100.0F } ;      /* Referenced by:
                                        * '<S188>/2-D Lookup Table10'
                                        * '<S188>/2-D Lookup Table11'
                                        */

const volatile float32 eada_mot2ZroCrsAcceLmt_Y_MotTrq_Nm[11] = { -200.0F,
  -100.0F, -60.0F, -30.0F, -10.0F, 0.0F, 10.0F, 30.0F, 60.0F, 100.0F, 200.0F } ;/* Referenced by:
                                                                      * '<S188>/2-D Lookup Table10'
                                                                      * '<S188>/2-D Lookup Table11'
                                                                      */

const volatile float32 eadc_a_acceSuprsnEnSlpeHi_mps2 = 0.05F;/* Referenced by: '<S189>/Constant11' */
const volatile boolean eadc_b_disMot2ZeroCrossDurESP = true;/* Referenced by: '<S188>/Constant1' */

/* Disable motor zero-crossing filter during the ESP intervention */
const volatile boolean eadc_b_enAcceSuprsn = true;/* Referenced by: '<S189>/Constant9' */
const volatile boolean eadc_b_enaMot2ZeroCrossRamp = true;/* Referenced by: '<S188>/Constant10' */

/* Enable motor zero-crossing filter */
const volatile boolean eadc_b_enbEad2TqOvrd = false;/* Referenced by: '<S177>/Constant6' */
const volatile boolean eadc_b_useForceTqBrkGearR = true;/* Referenced by: '<S175>/Constant5' */
const volatile boolean eadc_b_useGearR2NTqDirSwt = true;/* Referenced by:
                                                         * '<S175>/Constant6'
                                                         * '<S175>/Constant8'
                                                         */
const volatile float32 eadc_tq_ead2TqOvrdVal_Nm = 0.0F;/* Referenced by: '<S177>/Constant7' */
const volatile float32 eadc_tq_mot2FrcDrvTqDirR_Nm = 0.0F;/* Referenced by: '<S175>/Constant' */

/* Drive Direction R Motor2 Force Torque */
const volatile float32 eadc_v_acceSuprsnEnVehSpd_kph = 7.0F;/* Referenced by: '<S189>/Constant14' */
const volatile float32 eadc_v_acceSuprsnQutVehSpd_kph = 30.0F;/* Referenced by:
                                                               * '<S189>/Constant6'
                                                               * '<S189>/Constant7'
                                                               */
const volatile float32 eadc_x_accPdlRate_pctps = 250.0F;/* Referenced by: '<S189>/Constant5' */
const volatile float32 eadc_x_acceSuprsnAccPdlHi_pct = 97.0F;/* Referenced by:
                                                              * '<S189>/Constant2'
                                                              * '<S189>/Constant3'
                                                              * '<S189>/Constant8'
                                                              */
const volatile float32 eadc_x_acceSuprsnAccPdlLo_pct = 20.0F;/* Referenced by:
                                                              * '<S189>/Constant1'
                                                              * '<S189>/Constant4'
                                                              */
const volatile float32 eadm_mot2ZeroCrossDec_Z_Nmps[66] = { -192.0F, -230.3F,
  -230.3F, -230.3F, -230.3F, -184.3F, -115.1F, -138.2F, -138.2F, -138.2F,
  -138.2F, -110.5F, -115.1F, -138.2F, -138.2F, -138.2F, -138.2F, -110.5F,
  -115.1F, -138.2F, -138.2F, -138.2F, -138.2F, -110.5F, -96.0F, -126.7F, -126.7F,
  -138.2F, -138.2F, -110.5F, -67.19F, -80.63F, -80.63F, -80.63F, -80.63F,
  -64.51F, -180.0F, -216.0F, -216.0F, -216.0F, -216.0F, -172.8F, -260.0F,
  -312.0F, -312.0F, -312.0F, -390.0F, -374.3F, -390.0F, -390.0F, -390.0F,
  -390.0F, -390.0F, -312.0F, -600.0F, -600.0F, -600.0F, -600.0F, -600.0F,
  -480.0F, -600.0F, -600.0F, -600.0F, -600.0F, -600.0F, -480.0F } ;
                                 /* Referenced by: '<S188>/2-D Lookup Table1' */

/* Motor zero-crossing filter negative gradient map */
const volatile float32 eadm_mot2ZeroCrossInc_Z_Nmps[66] = { 600.0F, 600.0F,
  600.0F, 600.0F, 600.0F, 480.0F, 600.0F, 600.0F, 600.0F, 600.0F, 600.0F, 480.0F,
  360.0F, 420.0F, 600.0F, 600.0F, 600.0F, 480.0F, 120.0F, 280.0F, 600.0F, 600.0F,
  600.0F, 480.0F, 84.0F, 140.0F, 200.0F, 200.0F, 200.0F, 160.0F, 110.0F, 110.0F,
  110.0F, 110.0F, 110.0F, 110.0F, 154.0F, 198.0F, 154.0F, 154.0F, 154.0F, 154.0F,
  165.0F, 209.0F, 209.0F, 242.0F, 231.0F, 165.0F, 176.0F, 231.0F, 242.0F, 264.0F,
  231.0F, 176.0F, 330.0F, 286.0F, 286.0F, 330.0F, 286.0F, 220.0F, 385.0F, 330.0F,
  341.0F, 385.0F, 319.0F, 264.0F } ;
                                  /* Referenced by: '<S188>/2-D Lookup Table' */

/* Motor zero-crossing filter positive gradient map */
const volatile float32 eadm_mot2ZroCrsDecAcceLmt_Z_Nmps[66] = { -385.0F, -330.0F,
  -341.0F, -385.0F, -319.0F, -264.0F, -240.0F, -200.0F, -200.0F, -200.0F,
  -200.0F, -160.0F, -144.0F, -120.0F, -120.0F, -120.0F, -120.0F, -96.0F, -144.0F,
  -120.0F, -120.0F, -120.0F, -120.0F, -96.0F, -144.0F, -120.0F, -120.0F, -120.0F,
  -120.0F, -96.0F, -120.0F, -110.0F, -110.0F, -120.0F, -120.0F, -96.0F, -84.0F,
  -70.0F, -70.0F, -70.0F, -70.0F, -56.0F, -150.0F, -150.0F, -150.0F, -150.0F,
  -150.0F, -120.0F, -260.0F, -260.0F, -260.0F, -260.0F, -325.0F, -312.0F,
  -390.0F, -390.0F, -390.0F, -390.0F, -390.0F, -312.0F, -600.0F, -600.0F,
  -600.0F, -600.0F, -600.0F, -480.0F } ;
                                /* Referenced by: '<S188>/2-D Lookup Table11' */

const volatile float32 eadm_mot2ZroCrsIncAcceLmt_Z_Nmps[66] = { 600.0F, 600.0F,
  600.0F, 600.0F, 600.0F, 480.0F, 600.0F, 600.0F, 600.0F, 600.0F, 600.0F, 480.0F,
  600.0F, 600.0F, 600.0F, 600.0F, 600.0F, 480.0F, 360.0F, 420.0F, 600.0F, 600.0F,
  600.0F, 480.0F, 120.0F, 280.0F, 600.0F, 600.0F, 600.0F, 480.0F, 84.0F, 140.0F,
  200.0F, 200.0F, 200.0F, 160.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 80.0F,
  180.0F, 160.0F, 160.0F, 160.0F, 160.0F, 100.0F, 240.0F, 149.5F, 149.5F, 149.5F,
  149.5F, 130.0F, 260.0F, 161.0F, 149.5F, 149.5F, 149.5F, 120.0F, 280.0F, 115.0F,
  138.0F, 149.5F, 115.0F, 69.0F } ;
                                /* Referenced by: '<S188>/2-D Lookup Table10' */

const volatile float32 swctcoo_apda_trqDemGearDVehTyp1_Y_EngSpd_rpm[12] = {
  1000.0F, 1500.0F, 2000.0F, 3000.0F, 4500.0F, 5000.0F, 6000.0F, 8000.0F,
  9000.0F, 11000.0F, 12000.0F, 13000.0F } ;
                                   /* Referenced by: '<S50>/2-D Lookup Table' */

const volatile float32 swctcoo_apda_trqDemGearDVehTyp2_Y_EngSpd_rpm[12] = {
  1000.0F, 1500.0F, 4200.0F, 5100.0F, 6000.0F, 7200.0F, 8100.0F, 9000.0F,
  9900.0F, 10800.0F, 12000.0F, 12500.0F } ;
                                   /* Referenced by: '<S65>/2-D Lookup Table' */

const volatile float32 swctcoo_apda_trqDemGearEVehTyp1_Y_EngSpd_rpm[12] = {
  1000.0F, 1500.0F, 2000.0F, 3000.0F, 4500.0F, 5000.0F, 6000.0F, 8000.0F,
  9000.0F, 11000.0F, 12000.0F, 13000.0F } ;
                                   /* Referenced by: '<S48>/2-D Lookup Table' */

const volatile float32 swctcoo_apda_trqDemGearEVehTyp2_Y_EngSpd_rpm[12] = {
  1000.0F, 1500.0F, 4200.0F, 5100.0F, 6000.0F, 7200.0F, 8100.0F, 9000.0F,
  9900.0F, 10800.0F, 12000.0F, 12500.0F } ;
                                   /* Referenced by: '<S63>/2-D Lookup Table' */

const volatile float32 swctcoo_apda_trqDemGearSVehTyp1_Y_EngSpd_rpm[12] = {
  1000.0F, 1500.0F, 2000.0F, 3000.0F, 4500.0F, 5000.0F, 6000.0F, 8000.0F,
  9000.0F, 11000.0F, 12000.0F, 13000.0F } ;
                                   /* Referenced by: '<S52>/2-D Lookup Table' */

const volatile float32 swctcoo_apda_trqDemGearSVehTyp2_Y_EngSpd_rpm[12] = {
  1000.0F, 1500.0F, 2000.0F, 3000.0F, 4500.0F, 5000.0F, 6000.0F, 8000.0F,
  9000.0F, 11000.0F, 12000.0F, 13000.0F } ;
                                   /* Referenced by: '<S67>/2-D Lookup Table' */

const volatile float32 swctcoo_apdm_trqDemGearD1VehTyp1_Z_Nm[132] = { 0.0F,
  33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F,
  0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F,
  220.8F, 0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F,
  209.7F, 220.8F, 0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F,
  198.7F, 209.7F, 220.8F, 0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F,
  176.6F, 198.7F, 209.7F, 220.8F, 0.0F, 30.7F, 61.3F, 81.8F, 102.2F, 122.6F,
  143.1F, 163.5F, 184.0F, 194.2F, 204.4F, 0.0F, 25.2F, 50.4F, 67.2F, 84.0F,
  100.8F, 117.5F, 134.3F, 151.1F, 159.6F, 168.0F, 0.0F, 17.9F, 35.7F, 47.6F,
  59.5F, 71.4F, 83.3F, 95.2F, 107.1F, 113.0F, 119.0F, 0.0F, 15.7F, 31.4F, 41.9F,
  52.3F, 62.7F, 73.2F, 83.7F, 94.1F, 99.4F, 104.6F, 0.0F, 12.4F, 24.8F, 33.0F,
  41.2F, 49.5F, 57.7F, 66.0F, 74.3F, 78.4F, 82.5F, 0.0F, 11.1F, 22.2F, 29.6F,
  36.9F, 44.3F, 51.7F, 59.1F, 66.5F, 70.2F, 73.9F, 0.0F, 10.1F, 20.2F, 26.9F,
  33.6F, 40.3F, 47.0F, 53.7F, 60.4F, 63.8F, 67.1F } ;
                                   /* Referenced by: '<S50>/2-D Lookup Table' */

const volatile float32 swctcoo_apdm_trqDemGearD1VehTyp2_Z_Nm[132] = { 0.0F,
  19.5F, 48.75F, 68.25F, 97.5F, 117.0F, 136.5F, 156.0F, 175.5F, 195.0F, 195.0F,
  0.0F, 19.5F, 48.75F, 68.25F, 97.5F, 117.0F, 136.5F, 156.0F, 175.5F, 195.0F,
  195.0F, 0.0F, 19.5F, 48.75F, 68.25F, 97.5F, 117.0F, 136.5F, 156.0F, 175.5F,
  195.0F, 195.0F, 0.0F, 17.766F, 44.415F, 62.181F, 88.83F, 106.596F, 124.362F,
  142.128F, 159.894F, 177.66F, 177.66F, 0.0F, 15.2F, 38.0F, 53.2F, 76.0F, 91.2F,
  106.4F, 121.6F, 136.8F, 152.0F, 152.0F, 0.0F, 12.618F, 31.545F, 44.163F,
  63.09F, 75.708F, 88.326F, 100.944F, 113.562F, 126.18F, 126.18F, 0.0F, 11.15F,
  27.875F, 39.025F, 55.75F, 66.9F, 78.05F, 89.2F, 100.35F, 111.5F, 111.5F, 0.0F,
  10.25F, 25.625F, 35.875F, 51.25F, 61.5F, 71.75F, 82.0F, 92.25F, 102.5F, 102.5F,
  0.0F, 9.15F, 22.875F, 32.025F, 45.75F, 54.9F, 64.05F, 73.2F, 82.35F, 91.5F,
  91.5F, 0.0F, 8.528F, 21.32F, 29.848F, 42.64F, 51.168F, 59.696F, 68.224F,
  76.752F, 85.28F, 85.28F, 0.0F, 7.786F, 19.465F, 27.251F, 38.93F, 46.716F,
  54.502F, 62.288F, 70.074F, 77.86F, 77.86F, 0.0F, 7.3F, 18.25F, 25.55F, 36.5F,
  43.8F, 51.1F, 58.4F, 65.7F, 73.0F, 73.0F } ;
                                   /* Referenced by: '<S65>/2-D Lookup Table' */

const volatile float32 swctcoo_apdm_trqDemGearE1VehTyp1_Z_Nm[132] = { 0.0F,
  33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F,
  0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F,
  220.8F, 0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F,
  209.7F, 220.8F, 0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F,
  198.7F, 209.7F, 220.8F, 0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F,
  176.6F, 198.7F, 209.7F, 220.8F, 0.0F, 30.7F, 61.3F, 81.8F, 102.2F, 122.6F,
  143.1F, 163.5F, 184.0F, 194.2F, 204.4F, 0.0F, 25.2F, 50.4F, 67.2F, 84.0F,
  100.8F, 117.5F, 134.3F, 151.1F, 159.6F, 168.0F, 0.0F, 17.9F, 35.7F, 47.6F,
  59.5F, 71.4F, 83.3F, 95.2F, 107.1F, 113.0F, 119.0F, 0.0F, 15.7F, 31.4F, 41.9F,
  52.3F, 62.7F, 73.2F, 83.7F, 94.1F, 99.4F, 104.6F, 0.0F, 12.4F, 24.8F, 33.0F,
  41.2F, 49.5F, 57.7F, 66.0F, 74.3F, 78.4F, 82.5F, 0.0F, 11.1F, 22.2F, 29.6F,
  36.9F, 44.3F, 51.7F, 59.1F, 66.5F, 70.2F, 73.9F, 0.0F, 10.1F, 20.2F, 26.9F,
  33.6F, 40.3F, 47.0F, 53.7F, 60.4F, 63.8F, 67.1F } ;
                                   /* Referenced by: '<S48>/2-D Lookup Table' */

const volatile float32 swctcoo_apdm_trqDemGearE1VehTyp2_Z_Nm[132] = { 0.0F,
  15.6F, 19.5F, 39.0F, 48.75F, 68.25F, 78.0F, 97.5F, 117.0F, 136.5F, 195.0F,
  0.0F, 15.6F, 19.5F, 39.0F, 48.75F, 68.25F, 78.0F, 97.5F, 117.0F, 136.5F,
  195.0F, 0.0F, 15.6F, 19.5F, 39.0F, 48.75F, 68.25F, 78.0F, 97.5F, 117.0F,
  136.5F, 165.75F, 0.0F, 14.2128F, 17.766F, 35.532F, 44.415F, 62.181F, 71.064F,
  88.83F, 106.596F, 124.362F, 151.011F, 0.0F, 12.16F, 15.2F, 30.4F, 38.0F, 53.2F,
  60.8F, 76.0F, 91.2F, 106.4F, 129.2F, 0.0F, 10.0944F, 12.618F, 25.236F, 31.545F,
  44.163F, 50.472F, 63.09F, 75.708F, 88.326F, 100.944F, 0.0F, 8.92F, 11.15F,
  22.3F, 27.875F, 39.025F, 44.6F, 55.75F, 66.9F, 78.05F, 89.2F, 0.0F, 8.2F,
  10.25F, 20.5F, 25.625F, 35.875F, 41.0F, 51.25F, 61.5F, 71.75F, 82.0F, 0.0F,
  7.32F, 9.15F, 18.3F, 22.875F, 32.025F, 36.6F, 45.75F, 54.9F, 64.05F, 73.2F,
  0.0F, 6.8224F, 8.528F, 17.056F, 21.32F, 29.848F, 34.112F, 42.64F, 51.168F,
  59.696F, 68.224F, 0.0F, 6.2288F, 7.786F, 15.572F, 19.465F, 27.251F, 31.144F,
  38.93F, 46.716F, 54.502F, 62.288F, 0.0F, 5.84F, 7.3F, 14.6F, 18.25F, 25.55F,
  29.2F, 36.5F, 43.8F, 51.1F, 58.4F } ;
                                   /* Referenced by: '<S63>/2-D Lookup Table' */

const volatile float32 swctcoo_apdm_trqDemGearNVehTyp1_Z_Nm[132] = { 0.0F, -0.0F,
  -0.0F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0F, -0.0F,
  -0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0F, -0.0F, -0.0F,
  -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0F, -0.0F, -0.0F, -0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0F, -0.0F, -0.0F, -0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0F, -0.0F, -0.0F, -0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0F, -0.0F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, -0.0F, -0.0F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, -0.0F, -0.0F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, -0.0F, -0.0F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, -0.0F, -0.0F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  -0.0F, -0.0F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;
                                   /* Referenced by: '<S42>/2-D Lookup Table' */

const volatile float32 swctcoo_apdm_trqDemGearNVehTyp2_Z_Nm[132] = { 0.0F, 20.0F,
  40.0F, 60.0F, 80.0F, 100.0F, 120.0F, 140.0F, 160.0F, 180.0F, 200.0F, 0.0F,
  20.0F, 40.0F, 60.0F, 80.0F, 100.0F, 120.0F, 140.0F, 160.0F, 180.0F, 200.0F,
  0.0F, 20.0F, 40.0F, 60.0F, 80.0F, 100.0F, 120.0F, 140.0F, 160.0F, 180.0F,
  200.0F, 0.0F, 20.0F, 40.0F, 60.0F, 80.0F, 100.0F, 120.0F, 140.0F, 160.0F,
  180.0F, 200.0F, 0.0F, 20.0F, 40.0F, 60.0F, 80.0F, 100.0F, 120.0F, 140.0F,
  160.0F, 180.0F, 200.0F, 0.0F, 20.0F, 40.0F, 60.0F, 80.0F, 100.0F, 120.0F,
  140.0F, 160.0F, 180.0F, 200.0F, 0.0F, 20.0F, 40.0F, 60.0F, 80.0F, 100.0F,
  120.0F, 140.0F, 160.0F, 180.0F, 200.0F, 0.0F, 20.0F, 40.0F, 60.0F, 80.0F,
  100.0F, 120.0F, 140.0F, 160.0F, 180.0F, 200.0F, 0.0F, 20.0F, 40.0F, 60.0F,
  80.0F, 100.0F, 120.0F, 140.0F, 160.0F, 180.0F, 200.0F, 0.0F, 20.0F, 40.0F,
  60.0F, 80.0F, 100.0F, 120.0F, 140.0F, 160.0F, 180.0F, 200.0F, 0.0F, 20.0F,
  40.0F, 60.0F, 80.0F, 100.0F, 120.0F, 140.0F, 160.0F, 180.0F, 200.0F, 0.0F,
  20.0F, 40.0F, 60.0F, 80.0F, 100.0F, 120.0F, 140.0F, 160.0F, 180.0F, 200.0F } ;
                                   /* Referenced by: '<S57>/2-D Lookup Table' */

const volatile float32 swctcoo_apdm_trqDemGearRVehTyp1_Z_Nm[132] = { 0.0F, 33.1F,
  66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F, 0.0F,
  33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F,
  0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F,
  220.8F, 0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F,
  209.7F, 220.8F, 0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F,
  198.7F, 209.7F, 220.8F, 0.0F, 30.7F, 61.3F, 81.8F, 102.2F, 122.6F, 143.1F,
  163.5F, 184.0F, 194.2F, 204.4F, 0.0F, 25.2F, 50.4F, 67.2F, 84.0F, 100.8F,
  117.5F, 134.3F, 151.1F, 159.6F, 168.0F, 0.0F, 17.9F, 35.7F, 47.6F, 59.5F,
  71.4F, 83.3F, 95.2F, 107.1F, 113.0F, 119.0F, 0.0F, 15.7F, 31.4F, 41.9F, 52.3F,
  62.7F, 73.2F, 83.7F, 94.1F, 99.4F, 104.6F, 0.0F, 12.4F, 24.8F, 33.0F, 41.2F,
  49.5F, 57.7F, 66.0F, 74.3F, 78.4F, 82.5F, 0.0F, 11.1F, 22.2F, 29.6F, 36.9F,
  44.3F, 51.7F, 59.1F, 66.5F, 70.2F, 73.9F, 0.0F, 10.1F, 20.2F, 26.9F, 33.6F,
  40.3F, 47.0F, 53.7F, 60.4F, 63.8F, 67.1F } ;
                                   /* Referenced by: '<S43>/2-D Lookup Table' */

const volatile float32 swctcoo_apdm_trqDemGearRVehTyp2_Z_Nm[132] = { 0.0F, 19.5F,
  48.75F, 78.0F, 97.5F, 117.0F, 136.5F, 156.0F, 175.5F, 185.25F, 195.0F, 0.0F,
  19.5F, 48.75F, 78.0F, 97.5F, 117.0F, 136.5F, 156.0F, 175.5F, 185.25F, 195.0F,
  0.0F, 19.5F, 48.75F, 78.0F, 97.5F, 117.0F, 136.5F, 156.0F, 175.5F, 185.25F,
  195.0F, 0.0F, 19.5F, 48.75F, 78.0F, 97.5F, 117.0F, 136.5F, 156.0F, 175.5F,
  185.25F, 195.0F, 0.0F, 9.36F, 29.25F, 46.8F, 58.5F, 70.2F, 81.9F, 93.6F,
  105.3F, 111.15F, 117.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F } ;             /* Referenced by: '<S58>/2-D Lookup Table' */

const volatile float32 swctcoo_apdm_trqDemGearS1VehTyp1_Z_Nm[132] = { 0.0F,
  33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F,
  0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F,
  220.8F, 0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F,
  209.7F, 220.8F, 0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F,
  198.7F, 209.7F, 220.8F, 0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F,
  176.6F, 198.7F, 209.7F, 220.8F, 0.0F, 30.7F, 61.3F, 81.8F, 102.2F, 122.6F,
  143.1F, 163.5F, 184.0F, 194.2F, 204.4F, 0.0F, 25.2F, 50.4F, 67.2F, 84.0F,
  100.8F, 117.5F, 134.3F, 151.1F, 159.6F, 168.0F, 0.0F, 17.9F, 35.7F, 47.6F,
  59.5F, 71.4F, 83.3F, 95.2F, 107.1F, 113.0F, 119.0F, 0.0F, 15.7F, 31.4F, 41.9F,
  52.3F, 62.7F, 73.2F, 83.7F, 94.1F, 99.4F, 104.6F, 0.0F, 12.4F, 24.8F, 33.0F,
  41.2F, 49.5F, 57.7F, 66.0F, 74.3F, 78.4F, 82.5F, 0.0F, 11.1F, 22.2F, 29.6F,
  36.9F, 44.3F, 51.7F, 59.1F, 66.5F, 70.2F, 73.9F, 0.0F, 10.1F, 20.2F, 26.9F,
  33.6F, 40.3F, 47.0F, 53.7F, 60.4F, 63.8F, 67.1F } ;
                                   /* Referenced by: '<S52>/2-D Lookup Table' */

const volatile float32 swctcoo_apdm_trqDemGearS1VehTyp2_Z_Nm[132] = { 0.0F,
  33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F,
  0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F,
  220.8F, 0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F,
  209.7F, 220.8F, 0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F,
  198.7F, 209.7F, 220.8F, 0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F,
  176.6F, 198.7F, 209.7F, 220.8F, 0.0F, 30.7F, 61.3F, 81.8F, 102.2F, 122.6F,
  143.1F, 163.5F, 184.0F, 194.2F, 204.4F, 0.0F, 25.2F, 50.4F, 67.2F, 84.0F,
  100.8F, 117.5F, 134.3F, 151.1F, 159.6F, 168.0F, 0.0F, 17.9F, 35.7F, 47.6F,
  59.5F, 71.4F, 83.3F, 95.2F, 107.1F, 113.0F, 119.0F, 0.0F, 15.7F, 31.4F, 41.9F,
  52.3F, 62.7F, 73.2F, 83.7F, 94.1F, 99.4F, 104.6F, 0.0F, 12.4F, 24.8F, 33.0F,
  41.2F, 49.5F, 57.7F, 66.0F, 74.3F, 78.4F, 82.5F, 0.0F, 11.1F, 22.2F, 29.6F,
  36.9F, 44.3F, 51.7F, 59.1F, 66.5F, 70.2F, 73.9F, 0.0F, 10.1F, 20.2F, 26.9F,
  33.6F, 40.3F, 47.0F, 53.7F, 60.4F, 63.8F, 67.1F } ;
                                   /* Referenced by: '<S67>/2-D Lookup Table' */

const volatile uint8 swctcoo_dtdc_SptDefaultRegLvl = 1U;/* Referenced by: '<S86>/Constant5' */
const volatile boolean swctcoo_dtdc_b_ehbOvrCtlWhlDrgPmt = true;/* Referenced by: '<S75>/Constant12' */
const volatile boolean swctcoo_dtdc_b_useFctCfgEHB = true;/* Referenced by: '<S75>/Constant3' */
const volatile boolean swctcoo_dtdc_b_whlDrgDemEhb_ovrdflg = false;/* Referenced by: '<S75>/Constant4' */
const volatile float32 swctcoo_dtdc_frac_hvbSocDrgDecHigh_pct = 95.0F;/* Referenced by: '<S87>/Relay2' */
const volatile float32 swctcoo_dtdc_frac_hvbSocDrgDecLow_pct = 93.0F;/* Referenced by: '<S87>/Relay2' */
const volatile float32 swctcoo_dtdc_frac_pedCoastOffHigh_pct = 3.0F;/* Referenced by: '<S75>/Relay1' */
const volatile float32 swctcoo_dtdc_frac_pedCoastOffLow_pct = 1.0F;/* Referenced by: '<S75>/Relay1' */
const volatile float32 swctcoo_dtdc_tq_whlDrgDemEhb_ovrdval = 0.0F;/* Referenced by: '<S75>/Constant5' */
const volatile float32 swctcoo_dtdc_v_vSpdCrbsOnHigh_kph = 8.0F;/* Referenced by: '<S75>/Relay2' */
const volatile float32 swctcoo_dtdc_v_vSpdCrbsOnLow_kph = 7.0F;/* Referenced by: '<S75>/Relay2' */
const volatile float32 swctcoo_dtdf_brkTqMinMapEHB_X_VehSpd_kph[12] = { 0.0F,
  2.0F, 20.0F, 60.0F, 80.0F, 100.0F, 120.0F, 140.0F, 160.0F, 180.0F, 200.0F,
  220.0F } ;                      /* Referenced by: '<S75>/1-D Lookup Table1' */

const volatile float32 swctcoo_dtdf_brkTqMinMapEHB_Y_Nm[12] = { 0.0F, -2700.0F,
  -2700.0F, -2700.0F, -2700.0F, -2700.0F, -2700.0F, -2700.0F, -2700.0F, -2700.0F,
  -2700.0F, -2700.0F } ;          /* Referenced by: '<S75>/1-D Lookup Table1' */

/* Braking Min Torque Map - Torque Limit */
const volatile float32 swctcoo_dtdf_brkTqMinMap_X_VehSpd_kph[12] = { 0.0F, 20.0F,
  40.0F, 60.0F, 80.0F, 100.0F, 120.0F, 140.0F, 160.0F, 180.0F, 200.0F, 220.0F } ;
                                  /* Referenced by: '<S75>/1-D Lookup Table2' */

/* Braking Min Torque Map - Vehicle Speed Axis */
const volatile float32 swctcoo_dtdf_brkTqMinMap_Y_Nm[12] = { -716.0F, -716.0F,
  -716.0F, -716.0F, -716.0F, -716.0F, -716.0F, -716.0F, -716.0F, -716.0F,
  -716.0F, -716.0F } ;            /* Referenced by: '<S75>/1-D Lookup Table2' */

/* Braking Min Torque Map - Torque Limit */
const volatile float32 swctcoo_eada_mot2ZroCrsAdc_X_VehSpd_kph[6] = { 0.0F,
  20.0F, 40.0F, 60.0F, 80.0F, 100.0F } ;/* Referenced by:
                                         * '<S188>/2-D Lookup Table4'
                                         * '<S188>/2-D Lookup Table5'
                                         */

const volatile float32 swctcoo_eada_mot2ZroCrsAdc_Y_MotTrq_Nm[11] = { -125.0F,
  -100.0F, -75.0F, -50.0F, -25.0F, 0.0F, 25.0F, 50.0F, 75.0F, 100.0F, 125.0F } ;/* Referenced by:
                                                                      * '<S188>/2-D Lookup Table4'
                                                                      * '<S188>/2-D Lookup Table5'
                                                                      */

const volatile float32 swctcoo_eada_mot2ZroCrsEhb_X_VehSpd_kph[6] = { 0.0F, 8.0F,
  10.0F, 60.0F, 80.0F, 100.0F } ;      /* Referenced by:
                                        * '<S188>/2-D Lookup Table2'
                                        * '<S188>/2-D Lookup Table3'
                                        */

const volatile float32 swctcoo_eada_mot2ZroCrsEhb_Y_MotTrq_Nm[11] = { -125.0F,
  -100.0F, -75.0F, -50.0F, -25.0F, 0.0F, 25.0F, 50.0F, 75.0F, 100.0F, 125.0F } ;/* Referenced by:
                                                                      * '<S188>/2-D Lookup Table2'
                                                                      * '<S188>/2-D Lookup Table3'
                                                                      */

const volatile boolean swctcoo_eadc_b_enaAdcFild = true;/* Referenced by: '<S188>/Constant5' */
const volatile boolean swctcoo_eadc_b_enaCtlFild = false;/* Referenced by:
                                                          * '<S188>/Constant13'
                                                          * '<S188>/Constant15'
                                                          * '<S188>/Constant16'
                                                          * '<S188>/Constant17'
                                                          * '<S188>/Constant18'
                                                          * '<S188>/Constant21'
                                                          * '<S188>/Constant22'
                                                          */
const volatile boolean swctcoo_eadc_b_enaEcoModeFild = true;/* Referenced by: '<S188>/Constant12' */
const volatile boolean swctcoo_eadc_b_enaEhbMbRgnFild = true;/* Referenced by: '<S188>/Constant3' */
const volatile boolean swctcoo_eadc_b_enaSptModeFild = true;/* Referenced by: '<S188>/Constant14' */
const volatile boolean swctcoo_eadc_b_useSportMapsIn4WDMode = true;/* Referenced by: '<S188>/Constant11' */
const volatile float32 swctcoo_eadm_mot2ZroCrsDecAdc_Z_Nmps[66] = { -1500.0F,
  -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F,
  -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F,
  -1500.0F, -1000.0F, -1000.0F, -1000.0F, -1000.0F, -1250.0F, -1500.0F, -1000.0F,
  -1000.0F, -1000.0F, -1000.0F, -1000.0F, -1250.0F, -1000.0F, -1000.0F, -1000.0F,
  -1000.0F, -1000.0F, -1000.0F, -1000.0F, -1000.0F, -1000.0F, -1000.0F, -1000.0F,
  -1250.0F, -1000.0F, -1000.0F, -1000.0F, -1000.0F, -1250.0F, -1500.0F, -1500.0F,
  -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F,
  -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F,
  -1500.0F } ;                   /* Referenced by: '<S188>/2-D Lookup Table5' */

/* L4&#x74D2;&#x5A43;&#x6F48;&#x9422;&#x57AB;&#x6E80;2&#x93B5;&#xE160;&#x7169;&#x5A4A;&#x3086;&#x5C1D;map-&#x6D93;&#x5B2E;&#x6AB7;&#x93C2;&#x6EC5;&#x5DFC; */
const volatile float32 swctcoo_eadm_mot2ZroCrsDecEco_Z_Nmps[66] = { -192.0F,
  -230.3F, -230.3F, -230.3F, -230.3F, -184.3F, -115.1F, -138.2F, -138.2F,
  -138.2F, -138.2F, -110.5F, -115.1F, -138.2F, -138.2F, -138.2F, -138.2F,
  -110.5F, -115.1F, -138.2F, -138.2F, -138.2F, -138.2F, -110.5F, -96.0F, -126.7F,
  -126.7F, -138.2F, -138.2F, -110.5F, -67.19F, -80.63F, -80.63F, -80.63F,
  -80.63F, -64.51F, -180.0F, -216.0F, -216.0F, -216.0F, -216.0F, -172.8F,
  -260.0F, -312.0F, -312.0F, -312.0F, -390.0F, -374.3F, -390.0F, -390.0F,
  -390.0F, -390.0F, -390.0F, -312.0F, -600.0F, -600.0F, -600.0F, -600.0F,
  -600.0F, -480.0F, -600.0F, -600.0F, -600.0F, -600.0F, -600.0F, -480.0F } ;
                                 /* Referenced by: '<S188>/2-D Lookup Table9' */

/* Eco&#x59AF;&#x2033;&#x7D21;&#x6D93;&#x5B2C;&#x6578;&#x93C8;?&#x93B5;&#xE160;&#x7169;&#x5A4A;&#x3086;&#x5C1D;map-&#x6D93;&#x5B2E;&#x6AB7;&#x93C2;&#x6EC5;&#x5DFC; */
const volatile float32 swctcoo_eadm_mot2ZroCrsDecEhb_Z_Nmps[66] = { -200.0F,
  -200.0F, -300.0F, -300.0F, -300.0F, -300.0F, -200.0F, -200.0F, -300.0F,
  -300.0F, -300.0F, -300.0F, -200.0F, -200.0F, -300.0F, -300.0F, -300.0F,
  -300.0F, -200.0F, -200.0F, -200.0F, -200.0F, -200.0F, -200.0F, -160.0F,
  -160.0F, -200.0F, -200.0F, -200.0F, -200.0F, -100.0F, -100.0F, -200.0F,
  -200.0F, -200.0F, -200.0F, -160.0F, -160.0F, -200.0F, -200.0F, -200.0F,
  -200.0F, -100.0F, -100.0F, -200.0F, -200.0F, -200.0F, -200.0F, -100.0F,
  -100.0F, -300.0F, -300.0F, -300.0F, -300.0F, -100.0F, -100.0F, -300.0F,
  -300.0F, -300.0F, -300.0F, -100.0F, -100.0F, -300.0F, -300.0F, -300.0F,
  -300.0F } ;                    /* Referenced by: '<S188>/2-D Lookup Table3' */

const volatile float32 swctcoo_eadm_mot2ZroCrsDecSpt_Z_Nmps[66] = { -195.0F,
  -150.0F, -150.0F, -150.0F, -150.0F, -135.0F, -195.0F, -150.0F, -150.0F,
  -150.0F, -150.0F, -135.0F, -195.0F, -150.0F, -150.0F, -150.0F, -150.0F,
  -135.0F, -195.0F, -150.0F, -150.0F, -150.0F, -150.0F, -135.0F, -143.0F,
  -110.0F, -110.0F, -120.0F, -120.0F, -108.0F, -91.0F, -70.0F, -70.0F, -70.0F,
  -70.0F, -70.0F, -150.0F, -150.0F, -150.0F, -150.0F, -150.0F, -135.0F, -440.0F,
  -440.0F, -440.0F, -440.0F, -550.0F, -594.0F, -660.0F, -660.0F, -660.0F,
  -660.0F, -660.0F, -594.0F, -660.0F, -660.0F, -660.0F, -660.0F, -660.0F,
  -594.0F, -660.0F, -660.0F, -660.0F, -660.0F, -660.0F, -594.0F } ;
                                 /* Referenced by: '<S188>/2-D Lookup Table7' */

/* Sport&#x59AF;&#x2033;&#x7D21;&#x6D93;&#x5B2C;&#x6578;&#x93C8;?&#x93B5;&#xE160;&#x7169;&#x5A4A;&#x3086;&#x5C1D;map-&#x6D93;&#x5B2E;&#x6AB7;&#x93C2;&#x6EC5;&#x5DFC; */
const volatile float32 swctcoo_eadm_mot2ZroCrsIncAdc_Z_Nmps[66] = { 1500.0F,
  1500.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F,
  1500.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F,
  1500.0F, 500.0F, 1000.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 200.0F, 500.0F,
  1000.0F, 1500.0F, 1500.0F, 1500.0F, 100.0F, 200.0F, 500.0F, 1500.0F, 1500.0F,
  1500.0F, 200.0F, 200.0F, 200.0F, 1500.0F, 1500.0F, 1500.0F, 500.0F, 1000.0F,
  1500.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F,
  1500.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F,
  1500.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F } ;
                                 /* Referenced by: '<S188>/2-D Lookup Table4' */

/* L4&#x74D2;&#x5A43;&#x6F48;&#x9422;&#x57AB;&#x6E80;2&#x93B5;&#xE160;&#x7169;&#x5A4A;&#x3086;&#x5C1D;map-&#x6D93;&#x5A42;&#x5D0C;&#x93C2;&#x6EC5;&#x5DFC; */
const volatile float32 swctcoo_eadm_mot2ZroCrsIncEco_Z_Nmps[66] = { 600.0F,
  600.0F, 600.0F, 600.0F, 600.0F, 480.0F, 600.0F, 600.0F, 600.0F, 600.0F, 600.0F,
  480.0F, 360.0F, 420.0F, 600.0F, 600.0F, 600.0F, 480.0F, 120.0F, 280.0F, 600.0F,
  600.0F, 600.0F, 480.0F, 84.0F, 140.0F, 200.0F, 200.0F, 200.0F, 160.0F, 99.0F,
  99.0F, 99.0F, 99.0F, 99.0F, 74.36F, 143.0F, 165.0F, 165.0F, 157.3F, 157.3F,
  85.8F, 143.0F, 176.0F, 176.0F, 165.0F, 154.0F, 132.0F, 143.0F, 176.0F, 198.0F,
  198.0F, 187.0F, 132.0F, 198.0F, 231.0F, 264.0F, 275.0F, 220.0F, 132.0F, 275.0F,
  308.0F, 330.0F, 330.0F, 242.0F, 154.0F } ;
                                 /* Referenced by: '<S188>/2-D Lookup Table8' */

/* Eco&#x59AF;&#x2033;&#x7D21;&#x6D93;&#x5B2C;&#x6578;&#x93C8;?&#x93B5;&#xE160;&#x7169;&#x5A4A;&#x3086;&#x5C1D;map-&#x6D93;&#x5A42;&#x5D0C;&#x93C2;&#x6EC5;&#x5DFC; */
const volatile float32 swctcoo_eadm_mot2ZroCrsIncEhb_Z_Nmps[66] = { 200.0F,
  200.0F, 12000.0F, 12000.0F, 12000.0F, 12000.0F, 200.0F, 200.0F, 12000.0F,
  12000.0F, 12000.0F, 12000.0F, 400.0F, 400.0F, 12000.0F, 12000.0F, 12000.0F,
  12000.0F, 200.0F, 200.0F, 12000.0F, 12000.0F, 12000.0F, 12000.0F, 160.0F,
  160.0F, 8000.0F, 8000.0F, 8000.0F, 8000.0F, 100.0F, 100.0F, 1600.0F, 1600.0F,
  1600.0F, 1600.0F, 160.0F, 160.0F, 8000.0F, 8000.0F, 8000.0F, 8000.0F, 200.0F,
  200.0F, 12000.0F, 12000.0F, 12000.0F, 12000.0F, 200.0F, 200.0F, 12000.0F,
  12000.0F, 12000.0F, 12000.0F, 200.0F, 200.0F, 12000.0F, 12000.0F, 12000.0F,
  12000.0F, 200.0F, 200.0F, 12000.0F, 12000.0F, 12000.0F, 12000.0F } ;
                                 /* Referenced by: '<S188>/2-D Lookup Table2' */

const volatile float32 swctcoo_eadm_mot2ZroCrsIncSpt_Z_Nmps[66] = { 660.0F,
  660.0F, 660.0F, 660.0F, 660.0F, 594.0F, 660.0F, 660.0F, 660.0F, 660.0F, 660.0F,
  594.0F, 396.0F, 462.0F, 660.0F, 660.0F, 660.0F, 594.0F, 132.0F, 308.0F, 660.0F,
  660.0F, 660.0F, 594.0F, 92.4F, 140.0F, 200.0F, 200.0F, 200.0F, 180.0F, 90.0F,
  90.0F, 90.0F, 90.0F, 90.0F, 81.0F, 180.0F, 198.0F, 198.0F, 231.0F, 220.0F,
  158.0F, 240.0F, 242.0F, 254.0F, 277.0F, 242.0F, 166.0F, 260.0F, 277.0F, 277.0F,
  311.0F, 277.0F, 187.0F, 280.0F, 308.0F, 308.0F, 320.0F, 320.0F, 217.0F, 280.0F,
  308.0F, 308.0F, 320.0F, 320.0F, 217.0F } ;
                                 /* Referenced by: '<S188>/2-D Lookup Table6' */

/* Sport&#x59AF;&#x2033;&#x7D21;&#x6D93;&#x5B2C;&#x6578;&#x93C8;?&#x93B5;&#xE160;&#x7169;&#x5A4A;&#x3086;&#x5C1D;map-&#x6D93;&#x5A42;&#x5D0C;&#x93C2;&#x6EC5;&#x5DFC; */
const volatile boolean swctcoo_tdac_b_adcCtrlSts_ovrdflg = false;/* Referenced by: '<S204>/Constant9' */
const volatile boolean swctcoo_tdac_b_adcOvrCtlPmt = false;/* Referenced by:
                                                            * '<S204>/Constant12'
                                                            * '<S204>/Constant13'
                                                            * '<S204>/Constant14'
                                                            */
const volatile boolean swctcoo_tdac_b_ehbOvrCtlWhlDrgPmt = true;/* Referenced by: '<S206>/Constant1' */
const volatile boolean swctcoo_tdac_b_whlDemAdcCtl_ovrdflg = false;/* Referenced by: '<S204>/Constant1' */
const volatile uint8 swctcoo_tdac_st_adcCtrlSts_ovrdval = 2U;/* Referenced by: '<S204>/Constant11' */
const volatile float32 swctcoo_tdac_tq_whlDemAdcCtl_ovrdval = 0.0F;/* Referenced by: '<S204>/Constant5' */
const volatile boolean swctcoo_tqdc_b_axle2EhbTgtTq_ovrdflg = false;/* Referenced by: '<S335>/Constant4' */
const volatile boolean swctcoo_tqdc_b_ehbOvrCtlPmt = true;/* Referenced by: '<S364>/Constant2' */
const volatile boolean swctcoo_tqdc_b_enaEhbTqRamp = true;/* Referenced by: '<S335>/Constant12' */
const volatile float32 swctcoo_tqdc_tq_axle2EhbTgtTq_ovrdval = 0.0F;/* Referenced by: '<S335>/Constant5' */
const volatile float32 swctcoo_tqdc_tq_axle2EhbTqDecGrd_Nmps = -100000.0F;/* Referenced by: '<S335>/Constant9' */
const volatile float32 swctcoo_tqdc_tq_axle2EhbTqIncGrd_Nmps = 100000.0F;/* Referenced by: '<S335>/Constant8' */
const volatile float32 swctcoo_tqdc_tq_vlcAccPedlOvrdHi_Nm = 5.0F;/* Referenced by: '<S365>/Relay2' */
const volatile float32 swctcoo_tqdc_tq_vlcAccPedlOvrdLo_Nm = 0.0F;/* Referenced by: '<S365>/Relay2' */
const volatile boolean tcoo_apdc_b_useFctCfgMotor = true;/* Referenced by:
                                                          * '<S12>/Constant1'
                                                          * '<S12>/Constant12'
                                                          */
const volatile float32 tcoo_apdm_trqDemGearRTcs_Z_Nm[132] = { 0.0F, 33.1F, 66.2F,
  88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F, 0.0F, 33.1F,
  66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F, 0.0F,
  33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F,
  0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F,
  220.8F, 0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F,
  209.7F, 220.8F, 0.0F, 30.7F, 61.3F, 81.8F, 102.2F, 122.6F, 143.1F, 163.5F,
  184.0F, 194.2F, 204.4F, 0.0F, 25.2F, 50.4F, 67.2F, 84.0F, 100.8F, 117.5F,
  134.3F, 151.1F, 159.6F, 168.0F, 0.0F, 17.9F, 35.7F, 47.6F, 59.5F, 71.4F, 83.3F,
  95.2F, 107.1F, 113.0F, 119.0F, 0.0F, 15.7F, 31.4F, 41.9F, 52.3F, 62.7F, 73.2F,
  83.7F, 94.1F, 99.4F, 104.6F, 0.0F, 12.4F, 24.8F, 33.0F, 41.2F, 49.5F, 57.7F,
  66.0F, 74.3F, 78.4F, 82.5F, 0.0F, 11.1F, 22.2F, 29.6F, 36.9F, 44.3F, 51.7F,
  59.1F, 66.5F, 70.2F, 73.9F, 0.0F, 10.1F, 20.2F, 26.9F, 33.6F, 40.3F, 47.0F,
  53.7F, 60.4F, 63.8F, 67.1F } ;  /* Referenced by: '<S28>/2-D Lookup Table1' */

const volatile float32 tcoo_apdm_trqDemGearRVehTyp1Tcs_Z_Nm[132] = { 0.0F, 33.1F,
  66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F, 0.0F,
  33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F, 220.8F,
  0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F, 209.7F,
  220.8F, 0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F, 198.7F,
  209.7F, 220.8F, 0.0F, 33.1F, 66.2F, 88.3F, 110.4F, 132.4F, 154.5F, 176.6F,
  198.7F, 209.7F, 220.8F, 0.0F, 30.7F, 61.3F, 81.8F, 102.2F, 122.6F, 143.1F,
  163.5F, 184.0F, 194.2F, 204.4F, 0.0F, 25.2F, 50.4F, 67.2F, 84.0F, 100.8F,
  117.5F, 134.3F, 151.1F, 159.6F, 168.0F, 0.0F, 17.9F, 35.7F, 47.6F, 59.5F,
  71.4F, 83.3F, 95.2F, 107.1F, 113.0F, 119.0F, 0.0F, 15.7F, 31.4F, 41.9F, 52.3F,
  62.7F, 73.2F, 83.7F, 94.1F, 99.4F, 104.6F, 0.0F, 12.4F, 24.8F, 33.0F, 41.2F,
  49.5F, 57.7F, 66.0F, 74.3F, 78.4F, 82.5F, 0.0F, 11.1F, 22.2F, 29.6F, 36.9F,
  44.3F, 51.7F, 59.1F, 66.5F, 70.2F, 73.9F, 0.0F, 10.1F, 20.2F, 26.9F, 33.6F,
  40.3F, 47.0F, 53.7F, 60.4F, 63.8F, 67.1F } ;
                                  /* Referenced by: '<S43>/2-D Lookup Table1' */

const volatile float32 tcoo_apdm_trqDemGearRVehTyp2Tcs_Z_Nm[132] = { 0.0F, 19.5F,
  48.75F, 78.0F, 97.5F, 117.0F, 136.5F, 156.0F, 175.5F, 185.25F, 195.0F, 0.0F,
  19.5F, 48.75F, 78.0F, 97.5F, 117.0F, 136.5F, 156.0F, 175.5F, 185.25F, 195.0F,
  0.0F, 19.5F, 48.75F, 78.0F, 97.5F, 117.0F, 136.5F, 156.0F, 175.5F, 185.25F,
  195.0F, 0.0F, 19.5F, 48.75F, 78.0F, 97.5F, 117.0F, 136.5F, 156.0F, 175.5F,
  185.25F, 195.0F, 0.0F, 15.6F, 39.0F, 62.4F, 78.0F, 93.6F, 109.2F, 124.8F,
  140.4F, 148.2F, 156.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F } ;            /* Referenced by: '<S58>/2-D Lookup Table1' */

const volatile float32 tcoo_dtdc_a_yrsLgtAcceTgt_mps2 = 0.8F;/* Referenced by: '<S79>/Constant14' */
const volatile boolean tcoo_dtdc_b_useAccPdlEhbWhlCstDrg = true;/* Referenced by: '<S75>/Constant2' */
const volatile boolean tcoo_dtdc_b_useCoastDrgKi_flg = true;/* Referenced by: '<S79>/Constant8' */
const volatile uint8 tcoo_dtdc_defaultRegLvl = 1U;/* Referenced by: '<S86>/Constant16' */
const volatile float32 tcoo_dtdc_frac_coastDrgKMax = 2.0F;/* Referenced by: '<S79>/Constant2' */
const volatile float32 tcoo_dtdc_frac_coastDrgKMin = 0.2F;/* Referenced by: '<S79>/Constant5' */
const volatile float32 tcoo_dtdc_frac_drvAccPedalHi_pct = 3.0F;/* Referenced by: '<S79>/Relay' */
const volatile float32 tcoo_dtdc_frac_drvAccPedalLo_pct = 1.0F;/* Referenced by: '<S79>/Relay' */
const volatile float32 tcoo_dtdc_tm_timeCalKDelay_s = 3.0F;/* Referenced by: '<S79>/Constant11' */
const volatile float32 tcoo_dtdc_tm_vehStopDelay_s = 1200.0F;/* Referenced by: '<S79>/Constant15' */
const volatile float32 tcoo_dtdc_v_calAvrgKVehSpdLo_kph = 20.0F;/* Referenced by: '<S79>/Constant4' */
const volatile float32 tcoo_dtdc_v_vehSpdErrCtrlHi_kph = 2.0F;/* Referenced by: '<S79>/Relay1' */
const volatile float32 tcoo_dtdc_v_vehSpdErrCtrlLo_kph = -2.0F;/* Referenced by: '<S79>/Relay1' */
const volatile float32 tcoo_dtdc_v_vehStopSpd_kph = 3.0F;/* Referenced by: '<S79>/Constant7' */
const volatile float32 tcoo_eada_mot2ZroCrsCrpSlp_X_yrsAcc_mps2[9] = { -0.4F,
  -0.3F, -0.2F, -0.1F, 0.0F, 0.1F, 0.2F, 0.3F, 0.4F } ;/* Referenced by:
                                                        * '<S188>/1-D Lookup Table1'
                                                        * '<S188>/1-D Lookup Table2'
                                                        */

const volatile boolean tcoo_eadc_b_enaCrpSlopeModeFild = true;/* Referenced by: '<S188>/Constant19' */
const volatile boolean tcoo_eadc_b_useGetEventSts = true;/* Referenced by: '<S6>/Constant3' */
const volatile float32 tcoo_eadm_mot2ZroCrsDecCrsSlp_Y_Nmps[9] = { -300.0F,
  -300.0F, -300.0F, -300.0F, -300.0F, -300.0F, -300.0F, -300.0F, -300.0F } ;
                                 /* Referenced by: '<S188>/1-D Lookup Table1' */

const volatile float32 tcoo_eadm_mot2ZroCrsIncCrpSlp_Y_Nmps[9] = { 300.0F,
  300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F } ;
                                 /* Referenced by: '<S188>/1-D Lookup Table2' */

const volatile boolean tcoo_tdac_b_enaEhbVlcFilt = false;/* Referenced by: '<S224>/Constant2' */
const volatile float32 tcoo_tqda_pedlPosVirt_X_VehSpd_kph[11] = { 0.0F, 20.0F,
  40.0F, 60.0F, 80.0F, 100.0F, 120.0F, 140.0F, 160.0F, 180.0F, 200.0F } ;
                                 /* Referenced by: '<S366>/2-D Lookup Table4' */

/* Virtual accelerator Pedal position  - Vehicle Speed Axis */
const volatile float32 tcoo_tqda_pedlPosVirt_Y_WhlDem_Nm[10] = { 0.0F, 500.0F,
  1000.0F, 1500.0F, 2000.0F, 2500.0F, 3000.0F, 4000.0F, 5000.0F, 6000.0F } ;
                                 /* Referenced by: '<S366>/2-D Lookup Table4' */

/* Virtual accelerator Pedal position  - Wheel Torque Demand Axis */
const volatile boolean tcoo_tqdc_b_enaVlcMaxSpdLmt = true;/* Referenced by: '<S365>/Constant22' */
const volatile float32 tcoo_tqdc_frac_vlcAccPedlOvrdHi_pct = 3.0F;/* Referenced by: '<S365>/Relay1' */
const volatile float32 tcoo_tqdc_frac_vlcAccPedlOvrdLo_pct = 1.0F;/* Referenced by: '<S365>/Relay1' */
const volatile float32 tcoo_tqdc_tq_vlcDisGpOvrdFiltHi_Nm = 5.0F;/* Referenced by: '<S365>/Relay3' */
const volatile float32 tcoo_tqdc_tq_vlcDisGpOvrdFiltLo_Nm = 3.0F;/* Referenced by: '<S365>/Relay3' */
const volatile boolean tcoo_tqdd_b_gpOvrdCtrlFilt_ovrdflg = false;/* Referenced by: '<S365>/Constant1' */
const volatile boolean tcoo_tqdd_b_gpOvrdCtrlFilt_ovrdval = false;/* Referenced by: '<S365>/Constant14' */
const volatile float32 tcoo_tqdm_pedlPosVirt_Z_pct[110] = { 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 18.51F, 18.51F, 18.51F, 18.51F,
  18.51F, 18.51F, 18.51F, 18.51F, 18.51F, 18.51F, 18.51F, 37.02F, 37.02F, 37.02F,
  37.02F, 37.02F, 37.02F, 37.02F, 37.02F, 37.02F, 37.02F, 37.02F, 55.52F, 55.52F,
  55.52F, 55.52F, 55.52F, 55.52F, 55.52F, 55.52F, 55.52F, 55.52F, 55.52F, 74.03F,
  74.03F, 74.03F, 74.03F, 74.03F, 74.03F, 74.03F, 74.03F, 74.03F, 74.03F, 74.03F,
  92.54F, 92.54F, 92.54F, 92.54F, 92.54F, 92.54F, 92.54F, 92.54F, 92.54F, 92.54F,
  92.54F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F } ;
                                 /* Referenced by: '<S366>/2-D Lookup Table4' */

/* Virtual accelerator Pedal position */
const volatile float32 tdaa_dmp2nd_X_VehSpd_kph[6] = { 0.0F, 20.0F, 40.0F, 60.0F,
  80.0F, 100.0F } ;                    /* Referenced by:
                                        * '<S310>/2-D Lookup Table7'
                                        * '<S311>/2-D Lookup Table8'
                                        * '<S312>/2-D Lookup Table5'
                                        * '<S313>/2-D Lookup Table6'
                                        */

/* Damping Factor Map 2nd Order Filter - Vehicle Speed Axis */
const volatile float32 tdaa_dmp2nd_Y_TgtTrq_Nm[11] = { -1250.0F, -1000.0F,
  -750.0F, -500.0F, -250.0F, 0.0F, 250.0F, 500.0F, 750.0F, 1000.0F, 1250.0F } ;/* Referenced by:
                                                                      * '<S310>/2-D Lookup Table7'
                                                                      * '<S311>/2-D Lookup Table8'
                                                                      * '<S312>/2-D Lookup Table5'
                                                                      * '<S313>/2-D Lookup Table6'
                                                                      */

/* Damping Factor Map 2nd Order Filter - Target Torque Axis */
const volatile float32 tdaa_tau1st_X_VehSpd_kph[6] = { 0.0F, 20.0F, 40.0F, 60.0F,
  80.0F, 100.0F } ;                    /* Referenced by:
                                        * '<S284>/2-D Lookup Table3'
                                        * '<S285>/2-D Lookup Table4'
                                        * '<S286>/2-D Lookup Table1'
                                        * '<S287>/2-D Lookup Table2'
                                        * '<S288>/2-D Lookup Table3'
                                        * '<S289>/2-D Lookup Table4'
                                        * '<S290>/2-D Lookup Table1'
                                        * '<S291>/2-D Lookup Table2'
                                        * '<S292>/2-D Lookup Table3'
                                        * '<S293>/2-D Lookup Table4'
                                        * '<S294>/2-D Lookup Table1'
                                        * '<S295>/2-D Lookup Table2'
                                        */

/* Time Constant Map 1st Order Filter - Vehicle Speed Axis */
const volatile float32 tdaa_tau1st_Y_TgtTrq_Nm[11] = { -1250.0F, -1000.0F,
  -750.0F, -500.0F, -250.0F, 0.0F, 250.0F, 500.0F, 750.0F, 1000.0F, 1250.0F } ;/* Referenced by:
                                                                      * '<S284>/2-D Lookup Table3'
                                                                      * '<S285>/2-D Lookup Table4'
                                                                      * '<S286>/2-D Lookup Table1'
                                                                      * '<S287>/2-D Lookup Table2'
                                                                      * '<S288>/2-D Lookup Table3'
                                                                      * '<S289>/2-D Lookup Table4'
                                                                      * '<S290>/2-D Lookup Table1'
                                                                      * '<S291>/2-D Lookup Table2'
                                                                      * '<S292>/2-D Lookup Table3'
                                                                      * '<S293>/2-D Lookup Table4'
                                                                      * '<S294>/2-D Lookup Table1'
                                                                      * '<S295>/2-D Lookup Table2'
                                                                      */

/* Time Constant Map 1st Order Filter - Target Torque Axis */
const volatile float32 tdaa_tau2nd_X_VehSpd_kph[6] = { 0.0F, 20.0F, 40.0F, 60.0F,
  80.0F, 100.0F } ;                    /* Referenced by:
                                        * '<S310>/2-D Lookup Table3'
                                        * '<S311>/2-D Lookup Table4'
                                        * '<S312>/2-D Lookup Table1'
                                        * '<S313>/2-D Lookup Table2'
                                        */

/* Time Constant Map 2nd Order Filter - Vehicle Speed Axis */
const volatile float32 tdaa_tau2nd_Y_TgtTrq_Nm[11] = { -1250.0F, -1000.0F,
  -750.0F, -500.0F, -250.0F, 0.0F, 250.0F, 500.0F, 750.0F, 1000.0F, 1250.0F } ;/* Referenced by:
                                                                      * '<S310>/2-D Lookup Table3'
                                                                      * '<S311>/2-D Lookup Table4'
                                                                      * '<S312>/2-D Lookup Table1'
                                                                      * '<S313>/2-D Lookup Table2'
                                                                      */

/* Time Constant Map 2nd Order Filter - Target Torque Axis */
const volatile float32 tdaa_tauParabola_X_VehSpd_kph[6] = { 0.0F, 20.0F, 40.0F,
  60.0F, 80.0F, 100.0F } ;             /* Referenced by:
                                        * '<S300>/1-D Lookup Table'
                                        * '<S301>/1-D Lookup Table'
                                        * '<S302>/1-D Lookup Table'
                                        * '<S303>/1-D Lookup Table'
                                        * '<S304>/1-D Lookup Table'
                                        * '<S305>/1-D Lookup Table'
                                        * '<S306>/1-D Lookup Table'
                                        * '<S307>/1-D Lookup Table'
                                        */

/* Time Constant Map Parabolic Filter - Vehicle Speed Axis */
const volatile boolean tdac_b_enaEhbCrbsFilt = false;/* Referenced by: '<S224>/Constant3' */
const volatile boolean tdac_b_useSportMapsIn4WDMode = true;/* Referenced by: '<S221>/Constant17' */

/* Use Drivability Sport Maps in 4WD Mode */
const volatile float32 tdac_dtq_whlMaxLimDecGrad_Nmps = -200.0F;/* Referenced by: '<S222>/Constant2' */

/* Wheel Max Safety Limit Decrease Gradient */
const volatile float32 tdac_dtq_whlMinLimIncGrad_Nmps = 200.0F;/* Referenced by: '<S222>/Constant6' */

/* Wheel Min Safety Limit Increase Gradient */
const volatile uint8 tdac_st_filtEnaCW = 255U;/* Referenced by: '<S267>/Constant7' */

/* Filter Enable CodeWord */
const volatile float32 tdac_tm_negFiltSetTime_s = 0.03F;/* Referenced by: '<S316>/Constant7' */

/* Negative filtering set time */
const volatile float32 tdac_tm_posFiltSetTime_s = 0.03F;/* Referenced by: '<S316>/Constant8' */

/* Positive filtering set time */
const volatile float32 tdac_tm_tipInSetTime_s = 0.03F;/* Referenced by: '<S316>/Constant6' */

/* Tip-In set time */
const volatile float32 tdac_tm_tipOutSetTime_s = 0.03F;/* Referenced by: '<S316>/Constant5' */

/* Tip-Out set time */
const volatile float32 tdac_tq_whlLoLimNegOffs_Nm = -200.0F;/* Referenced by: '<S318>/Constant5' */

/* Lower Torque Limit for negative demand */
const volatile float32 tdac_tq_whlLoLimPosOffs_Nm = -100.0F;/* Referenced by: '<S318>/Constant4' */

/* Lower Torque Limit for positive demand */
const volatile float32 tdac_tq_whlMaxLimOffset_Nm = 0.0F;/* Referenced by: '<S222>/Constant1' */

/* Wheel Max Safety Limit Offset */
const volatile float32 tdac_tq_whlMinLimOffset_Nm = 0.0F;/* Referenced by: '<S222>/Constant4' */

/* Wheel Min Safety Limit Offset */
const volatile float32 tdac_tq_whlNegErrTqOffs_Nm = -10.0F;/* Referenced by: '<S316>/Constant3' */

/* Negative Torque Error Offset */
const volatile float32 tdac_tq_whlNegTgtTqOffsNoDeb_Nm = -20.0F;/* Referenced by: '<S316>/Constant11' */

/* Negative Target Torque Offset without debounce */
const volatile float32 tdac_tq_whlNegTgtTqOffs_Nm = -3.0F;/* Referenced by: '<S316>/Constant2' */

/* Negative Target Torque Offset */
const volatile float32 tdac_tq_whlPosErrTqOffs_Nm = 10.0F;/* Referenced by: '<S316>/Constant1' */

/* Positive Torque Error Offset */
const volatile float32 tdac_tq_whlPosTgtTqOffsNoDeb_Nm = 20.0F;/* Referenced by: '<S316>/Constant10' */

/* Positive Target Torque Offset without debounce */
const volatile float32 tdac_tq_whlPosTgtTqOffs_Nm = 4.0F;/* Referenced by: '<S316>/Constant9' */

/* Positive Target Torque Offset */
const volatile float32 tdac_tq_whlUpLimNegOffs_Nm = 100.0F;/* Referenced by: '<S318>/Constant1' */

/* Upper Torque Limit for negative demand */
const volatile float32 tdac_tq_whlUpLimPosOffs_Nm = 0.0F;/* Referenced by: '<S318>/Constant' */

/* Upper Torque Limit for positive demand */
const volatile float32 tdac_tq_whlZeroRefNeg_Nm = -20.0F;/* Referenced by: '<S318>/Constant3' */

/* Zero Torque Reference for negative demand */
const volatile float32 tdac_tq_whlZeroRefPos_Nm = 20.0F;/* Referenced by: '<S318>/Constant2' */

/* Zero Torque Reference for positive demand */
const volatile float32 tdam_dmp2ndPwrPosEVSprt_Z_fact[66] = { 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F } ;
                                 /* Referenced by: '<S311>/2-D Lookup Table8' */

/* Damping Factor Map 2nd Order Filter - EV Sport Map */
const volatile float32 tdam_dmp2ndPwrPosEV_Z_fact[66] = { 0.6F, 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F } ;
                                 /* Referenced by: '<S310>/2-D Lookup Table7' */

/* Damping Factor Map 2nd Order Filter - EV Map */
const volatile float32 tdam_dmp2ndPwrPosSprt_Z_fact[66] = { 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F } ;
                                 /* Referenced by: '<S313>/2-D Lookup Table6' */

/* Damping Factor Map 2nd Order Filter - Sport Map */
const volatile float32 tdam_dmp2ndPwrPos_Z_fact[66] = { 0.6F, 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F } ;
                                 /* Referenced by: '<S312>/2-D Lookup Table5' */

/* Damping Factor Map 2nd Order Filter - Normal Map */
const volatile float32 tdam_tau1stBrkNegEVSprt_Z_s[66] = { 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F } ;
                                 /* Referenced by: '<S285>/2-D Lookup Table4' */

/* Time Constant Map 1st Order Filter - EV Sport Map */
const volatile float32 tdam_tau1stBrkNegEV_Z_s[66] = { 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F } ;
                                 /* Referenced by: '<S284>/2-D Lookup Table3' */

/* Time Constant Map 1st Order Filter - EV Map */
const volatile float32 tdam_tau1stBrkNegSprt_Z_s[66] = { 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F } ;
                                 /* Referenced by: '<S287>/2-D Lookup Table2' */

/* Time Constant Map 1st Order Filter - Sport Map */
const volatile float32 tdam_tau1stBrkNeg_Z_s[66] = { 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F } ;
                                 /* Referenced by: '<S286>/2-D Lookup Table1' */

/* Time Constant Map 1st Order Filter - Normal Map */
const volatile float32 tdam_tau1stBrkPosEVSprt_Z_s[66] = { 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F } ;
                                 /* Referenced by: '<S289>/2-D Lookup Table4' */

/* Time Constant Map 1st Order Filter - EV Sport Map */
const volatile float32 tdam_tau1stBrkPosEV_Z_s[66] = { 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F } ;
                                 /* Referenced by: '<S288>/2-D Lookup Table3' */

/* Time Constant Map 1st Order Filter - EV Map */
const volatile float32 tdam_tau1stBrkPosSprt_Z_s[66] = { 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F } ;
                                 /* Referenced by: '<S291>/2-D Lookup Table2' */

/* Time Constant Map 1st Order Filter - Sport Map */
const volatile float32 tdam_tau1stBrkPos_Z_s[66] = { 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F } ;
                                 /* Referenced by: '<S290>/2-D Lookup Table1' */

/* Time Constant Map 1st Order Filter - Normal Map */
const volatile float32 tdam_tau1stPwrNegEVSprt_Z_s[66] = { 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F } ;
                                 /* Referenced by: '<S293>/2-D Lookup Table4' */

/* Time Constant Map 1st Order Filter - EV Sport Map */
const volatile float32 tdam_tau1stPwrNegEV_Z_s[66] = { 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F } ;
                                 /* Referenced by: '<S292>/2-D Lookup Table3' */

/* Time Constant Map 1st Order Filter - EV Map */
const volatile float32 tdam_tau1stPwrNegSprt_Z_s[66] = { 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F } ;
                                 /* Referenced by: '<S295>/2-D Lookup Table2' */

/* Time Constant Map 1st Order Filter - Sport Map */
const volatile float32 tdam_tau1stPwrNeg_Z_s[66] = { 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F } ;
                                 /* Referenced by: '<S294>/2-D Lookup Table1' */

/* Time Constant Map 1st Order Filter - Normal Map */
const volatile float32 tdam_tau2ndPwrPosEVSprt_Z_s[66] = { 0.12F, 0.12F, 0.12F,
  0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F,
  0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F,
  0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F,
  0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F,
  0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F,
  0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F } ;
                                 /* Referenced by: '<S311>/2-D Lookup Table4' */

/* Time Constant Map 2nd Order Filter - EV Sport Map */
const volatile float32 tdam_tau2ndPwrPosEV_Z_s[66] = { 0.3F, 0.3F, 0.3F, 0.3F,
  0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F,
  0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F,
  0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F,
  0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F,
  0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F } ;
                                 /* Referenced by: '<S310>/2-D Lookup Table3' */

/* Time Constant Map 2nd Order Filter - EV Map */
const volatile float32 tdam_tau2ndPwrPosSprt_Z_s[66] = { 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F } ;
                                 /* Referenced by: '<S313>/2-D Lookup Table2' */

/* Time Constant Map 2nd Order Filter - Sport Map */
const volatile float32 tdam_tau2ndPwrPos_Z_s[66] = { 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F,
  0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F, 0.25F } ;
                                 /* Referenced by: '<S312>/2-D Lookup Table1' */

/* Time Constant Map 2nd Order Filter - Normal Map */
const volatile float32 tdam_tauParabolaNegEVSprt_Z_s[6] = { 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F } ;            /* Referenced by: '<S301>/1-D Lookup Table' */

/* Time Constant Map Parabolic Filter - EV Sport Map */
const volatile float32 tdam_tauParabolaNegEV_Z_s[6] = { 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F } ;                  /* Referenced by: '<S300>/1-D Lookup Table' */

/* Time Constant Map Parabolic Filter - EV Map */
const volatile float32 tdam_tauParabolaNegSprt_Z_s[6] = { 0.1F, 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F } ;                  /* Referenced by: '<S303>/1-D Lookup Table' */

/* Time Constant Map Parabolic Filter - Sport Map */
const volatile float32 tdam_tauParabolaNeg_Z_s[6] = { 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F } ;                  /* Referenced by: '<S302>/1-D Lookup Table' */

/* Time Constant Map Parabolic Filter - Normal Map */
const volatile float32 tdam_tauParabolaPosEVSprt_Z_s[6] = { 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F } ;            /* Referenced by: '<S305>/1-D Lookup Table' */

/* Time Constant Map Parabolic Filter - EV Sport Map */
const volatile float32 tdam_tauParabolaPosEV_Z_s[6] = { 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F } ;                  /* Referenced by: '<S304>/1-D Lookup Table' */

/* Time Constant Map Parabolic Filter - EV Map */
const volatile float32 tdam_tauParabolaPosSprt_Z_s[6] = { 0.1F, 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F } ;                  /* Referenced by: '<S307>/1-D Lookup Table' */

/* Time Constant Map Parabolic Filter - Sport Map */
const volatile float32 tdam_tauParabolaPos_Z_s[6] = { 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F } ;                  /* Referenced by: '<S306>/1-D Lookup Table' */

/* Time Constant Map Parabolic Filter - Normal Map */
const volatile boolean tqdc_b_disGpOvrdTq = false;/* Referenced by: '<S352>/Constant11' */
const volatile float32 tqdc_tq_axle2RBSLimDecGrad_Nmps = -50000.0F;/* Referenced by: '<S332>/Constant1' */

/* Regenerative Braking Torque Limit Decrease Gradient on Secondary Axle */
const volatile float32 tqdc_tq_axle2RBSLimIncGrad_Nmps = 50000.0F;/* Referenced by: '<S332>/Constant3' */

/* Regenerative Braking Torque Limit Increase Gradient on Secondary Axle */
const volatile float32 tqdc_x_accPedlPosHiDisRBS_pct = 1.0F;/* Referenced by: '<S332>/Relay' */

/* Accelerator Pedal Position high threshold to disable Regenerative Braking */
const volatile float32 tqdc_x_accPedlPosLoDisRBS_pct = 0.5F;/* Referenced by: '<S332>/Relay' */

/* Accelerator Pedal Position low threshold to disable Regenerative Braking */
const volatile float32 tqdc_x_brkPedlPosHiEnaRBS_pct = 3.0F;/* Referenced by: '<S332>/Relay1' */

/* Brake Pedal Position high threshold to enable Regenerative Braking */
const volatile float32 tqdc_x_brkPedlPosLoEnaRBS_pct = 1.0F;/* Referenced by: '<S332>/Relay1' */

/* Brake Pedal Position low threshold to enable Regenerative Braking */
const volatile float32 tvrc_dtq_Mot2TqDec_Nmps = -50000.0F;/* Referenced by: '<S9>/Constant11' */
const volatile float32 tvrc_dtq_Mot2TqInc_Nmps = 50000.0F;/* Referenced by: '<S9>/Constant10' */

#define swc_TCOO_STOP_SEC_CONST_VOLATILE
#include "swc_TCOO_MemMap.h"
#define swc_TCOO_START_SEC_VAR
#include "swc_TCOO_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_SIG */
float32 apdd_fact_trsmGearRat;         /* '<S13>/Multiport Switch1' */

/* Arbitrated Transmission Gear Ratio for Pedal Maps */
float32 apdd_n_engActSpdMdl_rpm;       /* '<S15>/Data Type Conversion3' */

/* Engine Actual Speed Modeled */
sint8 apdd_st_trsmGearTgt;             /* '<S70>/Switch2' */

/* Arbitrated Transmission Target Gear for Pedal Maps */
float32 apdd_tq_crsDem_Nm;             /* '<S21>/Merge' */

/* Crank-shaft Driver Torque Demand */
float32 apdd_tq_whlDem_Nm;             /* '<S18>/Switch2' */

/* Wheel Torque Demand */
float32 apdd_tq_whlDrvrDem_Nm;         /* '<S21>/Product' */

/* Wheel Driver Torque Demand */
boolean drid_b_rgnOffGlobalEna;        /* '<S87>/Logical Operator14' */
boolean dtdd_b_rgnOffEna;              /* '<S87>/SR_latch1' */
uint8 dtdd_cnt_rgnOffCount;            /* '<S116>/Switch5' */
uint8 dtdd_st_EcoMemRegenLvl;          /* '<S88>/Signal Conversion1' */

/* Regeneration Level Actual */
uint8 dtdd_st_EcoRegenLvlAct;          /* '<S140>/Switch3' */

/* Regeneration Level Actual */
uint8 dtdd_st_EcoRegenLvlFromEE;       /* '<S86>/C Caller24' */

/* Regeneration Level From EEPROM */
uint8 dtdd_st_NormMemRegenLvl;         /* '<S88>/Signal Conversion' */

/* Regeneration Level Actual */
uint8 dtdd_st_NormRegenLvlFromEE;      /* '<S86>/C Caller23' */

/* Regeneration Level From EEPROM */
uint8 dtdd_st_NormalRegenLvlAct;       /* '<S144>/Switch3' */

/* Regeneration Level Actual */
uint8 dtdd_st_RegenLvlAct;             /* '<S88>/Switch4' */

/* Regeneration Level Actual */
uint8 dtdd_st_RegenLvlDisp;            /* '<S88>/Switch6' */

/* Regeneration Level Display */
float32 dtdd_tq_whlDragDem_Nm;         /* '<S75>/MinMax4' */

/* Drag Torque Demand */
float32 dtdd_tq_whlEVBrakingDrag_Nm;   /* '<S71>/Sum' */

/* EV Braking Drag Torque Demand */
float32 dtdd_tq_whlEVCoastingDrag_Nm;  /* '<S78>/Sum1' */

/* EV Coasting Drag Torque Demand */
boolean eadd_b_gearR2NTqDirSwt;        /* '<S175>/SR_latch' */
boolean eadd_b_whlAcceSupprsn;         /* '<S189>/Logical Operator3' */
float32 eadd_tq_axle2TgtTq_Nm;         /* '<S186>/Switch2' */

/* Secondary EAD Target Torque Raw */
float32 eadd_tq_mot2TgtFldAcceLmt_Nm;  /* '<S201>/Sum6' */
float32 eadd_tq_mot2TgtTqFild_Nm;      /* '<S199>/Sum6' */

/* Secondary EAD Filtered Target Torque */
float32 eadd_tq_mot2TgtTqReq_Nm;       /* '<S177>/Switch2' */

/* Secondary EAD Torque Request */
float32 eadd_tq_mot2TgtTqUnfilt_Nm;    /* '<S175>/Product1' */

/* Secondary EAD Unfiltered Target Torque */
float32 eadd_tq_mot2TgtTq_Nm;          /* '<S188>/Switch5' */

/* Secondary EAD Target Torque */
float32 swctcoo_apdd_tq_crsDemVehTyp1_Nm;/* '<S22>/Merge' */
float32 swctcoo_apdd_tq_crsDemVehTyp2_Nm;/* '<S23>/Merge' */
float32 swctcoo_apdd_tq_whlDrvrDemVehTyp1_Nm;/* '<S22>/Product' */
float32 swctcoo_apdd_tq_whlDrvrDemVehTyp2_Nm;/* '<S23>/Product' */
float32 swctcoo_apdd_tq_whlDrvrDem_Nm; /* '<S12>/Switch3' */
boolean swctcoo_dtdd_b_drvPfmncDrgDec; /* '<S87>/Switch11' */

/* DIM&#x93BB;&#x612E;&#x305A;&#x9473;&#x4ECB;&#x567A;&#x9365;&#x70B4;&#x6579;&#x9351;&#x5FD3;&#x6025; */
boolean swctcoo_dtdd_b_ehbMbRgnOvrCtl; /* '<S75>/Logical Operator5' */
uint8 swctcoo_dtdd_st_SptMemRegenLvl;  /* '<S88>/Signal Conversion2' */

/* Regeneration Level Actual */
uint8 swctcoo_dtdd_st_SptRegenLvlAct;  /* '<S145>/Switch3' */

/* Regeneration Level Actual */
uint8 swctcoo_dtdd_st_ecoRegLvlInit;   /* '<S86>/Switch15' */

/* Regeneration Level Init */
uint8 swctcoo_dtdd_st_normRegLvlInit;  /* '<S86>/Switch10' */

/* Regeneration Level Init */
uint8 swctcoo_dtdd_st_sptRegLvlInit;   /* '<S86>/Switch17' */

/* Regeneration Level Init */
uint8 swctcoo_dtdd_st_sptRegenLvlFromEE;/* '<S86>/C Caller' */

/* Regeneration Level From EEPROM */
float32 swctcoo_dtdd_tq_whlCoastDrgDem_Nm;/* '<S75>/MinMax3' */
float32 swctcoo_dtdd_tq_whlDrgDemEhb_Nm;/* '<S75>/Switch2' */
boolean swctcoo_eadd_b_adcOvrCtl;      /* '<S188>/Logical Operator3' */
boolean swctcoo_eadd_b_ehbOvrCtl;      /* '<S188>/Logical Operator2' */
boolean swctcoo_eadd_b_vehEcoModCtl;   /* '<S188>/Logical Operator10' */
boolean swctcoo_eadd_b_vehSptModCtl;   /* '<S188>/Logical Operator9' */
float32 swctcoo_eadd_tq_axle2TgtUnitDlyMotTyp0_Nm;/* '<S188>/Switch2' */
float32 swctcoo_eadd_tq_mot2TgtFldAdc_Nm;/* '<S195>/Sum6' */
float32 swctcoo_eadd_tq_mot2TgtFldEco_Nm;/* '<S198>/Sum6' */
float32 swctcoo_eadd_tq_mot2TgtFldEhb_Nm;/* '<S196>/Sum6' */
float32 swctcoo_eadd_tq_mot2TgtFldSpt_Nm;/* '<S197>/Sum6' */
uint8 swctcoo_tdad_st_adcCtrlSts;      /* '<S204>/Switch7' */
float32 swctcoo_tdad_tq_whlDemAdcCtl_Nm;/* '<S204>/Switch4' */
float32 swctcoo_tdad_tq_whlDemUnAdc_Nm;/* '<S225>/Switch2' */
boolean swctcoo_tqdd_b_ehbOvrCtl;      /* '<S364>/Logical Operator6' */
boolean swctcoo_tqdd_b_ehbVlcOvrCtl;   /* '<S364>/Logical Operator23' */
boolean swctcoo_tqdd_b_gpOvrd;         /* '<S365>/Switch9' */
float32 swctcoo_tqdd_tq_axle2EhbTgtTqRaw_Nm;/* '<S335>/Switch4' */
float32 swctcoo_tqdd_tq_axle2EhbTgtTq_Nm;/* '<S335>/Switch8' */
float32 swctcoo_tqdd_tq_ehbAccCtrlTgtTq_Nm;/* '<S352>/Switch4' */
float32 tcoo_dtdd_a_acce;              /* '<S79>/CoastingDrgAutoModeKCal' */
boolean tcoo_dtdd_b_calKVld;           /* '<S79>/CoastingDrgAutoModeKCal' */
float32 tcoo_dtdd_frac_coastDrgK;      /* '<S79>/CoastingDrgAutoModeKCal' */
float32 tcoo_dtdd_frac_coastDrgKlast;  /* '<S79>/Switch2' */
float32 tcoo_dtdd_frac_coastDrgKlastUnLim;/* '<S79>/CoastingDrgAutoModeKCal' */
uint8 tcoo_dtdd_st_calKSts;            /* '<S79>/CoastingDrgAutoModeKCal' */
float32 tcoo_dtdd_tm_calKTime_s;       /* '<S79>/CoastingDrgAutoModeKCal' */
float32 tcoo_dtdd_tq_whlCstDrgDemNoEhb_Nm;/* '<S75>/MinMax7' */
float32 tcoo_dtdd_v_coastDrgVehSpdEnd; /* '<S79>/CoastingDrgAutoModeKCal' */
float32 tcoo_dtdd_v_coastDrgVehSpdStrt;/* '<S79>/CoastingDrgAutoModeKCal' */
boolean tcoo_eadd_b_acpCrsFltDebd;     /* '<S6>/con_1' */
boolean tcoo_eadd_b_ehbMsgErrDebd;     /* '<S6>/Logical Operator1' */
float32 tcoo_eadd_tq_mot2TgtFldCrpSlp_Nm;/* '<S200>/Sum6' */
boolean tcoo_tqdd_b_accPedlPosVirtVld; /* '<S366>/Switch3' */
boolean tcoo_tqdd_b_ehbDisEnbCreep;    /* '<S364>/Logical Operator10' */
boolean tcoo_tqdd_b_gpOvrdCtrlFilt;    /* '<S365>/Switch11' */
boolean tcoo_tqdd_b_vlcMaxSpdLmtFilt;  /* '<S365>/Logical Operator46' */
float32 tcoo_tqdd_x_accPedlPosVirtRaw_pct;/* '<S366>/2-D Lookup Table4' */

/* Virtual accelerator Pedal position raw value */
float32 tcoo_tqdd_x_accPedlPosVirt_pct;/* '<S366>/Switch1' */

/* Virtual accelerator Pedal position */
boolean tdad_b_disEnbDrvFilter;        /* '<S224>/Logical Operator5' */
boolean tdad_b_tipIn;                  /* '<S316>/SR_latch1' */

/* Driver tip-in detected */
FiltTrqRange tdad_e_filterTrqRange;    /* '<S223>/TorqueRange' */

/* Filter torque range */
FiltTrqRange tdad_e_filterType;        /* '<S267>/Switch' */

/* Filter type */
float32 tdad_fact_dampFilt2nd;         /* '<S309>/Merge1' */

/* Damping Factor 2nd Order Filter */
float32 tdad_tm_tauFilt1st_s;          /* '<S268>/Merge' */

/* Time Constant 1st Order Filter */
float32 tdad_tm_tauFilt2nd_s;          /* '<S309>/Merge' */

/* Time Constant 2nd Order Filter */
float32 tdad_tm_tauFiltPar_s;          /* '<S269>/Merge' */

/* Time Constant Parabolic Filter */
float32 tdad_tq_whlDemFilt1st_Nm;      /* '<S238>/Switch2' */

/* Wheel Filtered Torque Demand after 1st order filter */
float32 tdad_tq_whlDemFilt2nd_Nm;      /* '<S228>/Switch2' */

/* Wheel Filtered Torque Demand after 2nd order filter */
float32 tdad_tq_whlDemFiltPar_Nm;      /* '<S227>/Switch2' */

/* Wheel Filtered Torque Demand after parabolic filter */
float32 tdad_tq_whlDemFilt_Nm;         /* '<S230>/Switch2' */

/* Wheel Filtered Torque Demand */
float32 tdad_tq_whlDemUnfilt_Nm;       /* '<S329>/Switch2' */

/* Wheel Unfiltered Torque Demand */
float32 tdad_tq_whlDemUnlim_Nm;        /* '<S205>/MinMax2' */

/* Wheel Unlimited Driver Torque Demand */
float32 tdad_tq_whlDem_Nm;             /* '<S206>/Switch2' */

/* Wheel Fast Torque Demand */
float32 tdad_tq_whlFiltMax_Nm;         /* '<S314>/MinMax2' */

/* Wheel Max Filtered Torque Limit */
float32 tdad_tq_whlFiltMin_Nm;         /* '<S315>/MinMax2' */

/* Wheel Min Filtered Torque Limit */
boolean tqdd_b_absOvrCtl_flg;          /* '<S364>/Logical Operator50' */
boolean tqdd_b_pdcBrkFlg;              /* '<S335>/Logical Operator4' */
uint8 tqdd_st_ehbTrqOvrdActv;          /* '<S367>/Switch10' */
uint8 tqdd_st_ehbTrqOvrdType;          /* '<S367>/Switch8' */
float32 tqdd_tq_axle2AbsTgtTq_Nm;      /* '<S338>/Switch11' */
float32 tqdd_tq_axle2RBSTqLim_Nm;      /* '<S332>/SwitchRampMot2RegenBrkLim' */

/* Secondary Axle Torque Limit For Regenerative Braking */
float32 tqdd_tq_axle2TqDem_Nm;         /* '<S334>/Switch2' */

/* Secondary Axle Torque Demand */
float32 tqdd_tq_axle2VSCMaxTqIntv_Nm;  /* '<S336>/MinMax6' */

/* Secondary Axle Max torque for VSC intervention */
float32 tqdd_tq_axle2VSCMinTqIntv_Nm;  /* '<S336>/MinMax3' */

/* Secondary Axle Min torque for VSC intervention */
float32 tqdd_tq_axle2VSCTqTgt_Nm;      /* '<S337>/Switch2' */

/* Secondary Axle Target Torque after VSC Intervention */
float32 tvrd_tq_mot2TgtTqReq_Nm;       /* '<S442>/Chart' */

#define swc_TCOO_STOP_SEC_VAR
#include "swc_TCOO_MemMap.h"

/* Constant parameters (default storage) */
const ConstP_swc_TCOO_T swc_TCOO_ConstP = {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S27>/2-D Lookup Table'
   *   '<S28>/2-D Lookup Table'
   *   '<S28>/2-D Lookup Table1'
   *   '<S42>/2-D Lookup Table'
   *   '<S43>/2-D Lookup Table'
   *   '<S43>/2-D Lookup Table1'
   *   '<S57>/2-D Lookup Table'
   *   '<S58>/2-D Lookup Table'
   *   '<S58>/2-D Lookup Table1'
   *   '<S33>/2-D Lookup Table'
   *   '<S34>/2-D Lookup Table1'
   *   '<S35>/2-D Lookup Table'
   *   '<S36>/2-D Lookup Table1'
   *   '<S37>/2-D Lookup Table'
   *   '<S38>/2-D Lookup Table1'
   *   '<S48>/2-D Lookup Table'
   *   '<S49>/2-D Lookup Table1'
   *   '<S50>/2-D Lookup Table'
   *   '<S51>/2-D Lookup Table1'
   *   '<S52>/2-D Lookup Table'
   *   '<S53>/2-D Lookup Table1'
   *   '<S63>/2-D Lookup Table'
   *   '<S64>/2-D Lookup Table1'
   *   '<S65>/2-D Lookup Table'
   *   '<S66>/2-D Lookup Table1'
   *   '<S67>/2-D Lookup Table'
   *   '<S68>/2-D Lookup Table1'
   */
  { 10U, 11U },

  /* Computed Parameter: uDLookupTable4_maxIndex
   * Referenced by: '<S366>/2-D Lookup Table4'
   */
  { 10U, 9U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S188>/2-D Lookup Table'
   *   '<S188>/2-D Lookup Table1'
   *   '<S188>/2-D Lookup Table10'
   *   '<S188>/2-D Lookup Table11'
   *   '<S188>/2-D Lookup Table2'
   *   '<S188>/2-D Lookup Table3'
   *   '<S188>/2-D Lookup Table4'
   *   '<S188>/2-D Lookup Table5'
   *   '<S188>/2-D Lookup Table6'
   *   '<S188>/2-D Lookup Table7'
   *   '<S188>/2-D Lookup Table8'
   *   '<S188>/2-D Lookup Table9'
   *   '<S284>/2-D Lookup Table3'
   *   '<S285>/2-D Lookup Table4'
   *   '<S286>/2-D Lookup Table1'
   *   '<S287>/2-D Lookup Table2'
   *   '<S288>/2-D Lookup Table3'
   *   '<S289>/2-D Lookup Table4'
   *   '<S290>/2-D Lookup Table1'
   *   '<S291>/2-D Lookup Table2'
   *   '<S292>/2-D Lookup Table3'
   *   '<S293>/2-D Lookup Table4'
   *   '<S294>/2-D Lookup Table1'
   *   '<S295>/2-D Lookup Table2'
   *   '<S310>/2-D Lookup Table3'
   *   '<S310>/2-D Lookup Table7'
   *   '<S311>/2-D Lookup Table4'
   *   '<S311>/2-D Lookup Table8'
   *   '<S312>/2-D Lookup Table1'
   *   '<S312>/2-D Lookup Table5'
   *   '<S313>/2-D Lookup Table2'
   *   '<S313>/2-D Lookup Table6'
   */
  { 5U, 10U }
};

/* PublicStructure Variables for Internal Data */
ARID_DEF_swc_TCOO_T swc_TCOO_ARID_DEF;
static float32 look2_iflf_binlcapw(float32 u0, float32 u1, const float32 bp0[],
  const float32 bp1[], const float32 table[], const uint32 maxIndex[], uint32
  stride);
static float32 look1_iflf_binlcapw(float32 u0, const float32 bp0[], const
  float32 table[], uint32 maxIndex);
static void swc_TCOO_turnON_delay_Init(boolean *rty_flg_out);
static void swc_TCOO_turnON_delay(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnON_delay_swc_TCO_T
  *swc_TCOO__ARID_DEF_arg);
static void swc_TCOO_Falling_Edge(boolean rtu_flg_in, boolean *rty_flg_out,
  ARID_DEF_Falling_Edge_swc_TCO_T *swc_TCOO__ARID_DEF_arg);
static void swc_TCOO_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch_swc_TCOO_T *swc_TCOO__ARID_DEF_arg);
static void swc_TCOO_turnOFF_delay_Init(boolean *rty_flg_out);
static void swc_TCOO_turnOFF_delay(boolean rtu_flg_in, float32 rtu_t_delay_off,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnOFF_delay_swc_TC_T
  *swc_TCOO__ARID_DEF_arg);
static void swc__SwitchCaseActionSubsystem1(float32 rtu_AccPedPos, float32
  rtu_EngSpd, float32 *rty_TrqDemGearS2);
static void sw_SwitchCaseActionSubsystem1_p(float32 rtu_AccPedPos, float32
  rtu_EngSpd, float32 *rty_TrqDemGearD2);
static void swc_TCOO_pos(float32 rtu_in_val, float32 *rty_same_val);
static void swc_TCOO_neg(float32 rtu_in_val, float32 *rty_neg_val);
static void swc_TCOO_switch_ramp_Init(float32 *rty_y, boolean *rty_RampOn);
static void swc_TCOO_switch_ramp(float32 rtu_u1, boolean rtu_sw, float32 rtu_u2,
  float32 rtu_up, float32 rtu_lo, float32 *rty_y, boolean *rty_RampOn,
  ARID_DEF_switch_ramp_swc_TCOO_T *swc_TCOO__ARID_DEF_arg);
static void SwitchRampMot2RegenBrkLim_Init(float32 *rty_y, boolean *rty_RampOn);
static void swc_T_SwitchRampMot2RegenBrkLim(float32 rtu_u1, boolean rtu_sw,
  float32 rtu_u2, float32 rtu_up, float32 rtu_lo, float32 *rty_y, boolean
  *rty_RampOn, ARID_DEF_switch_ramp_swc_TC_m_T *swc_TCOO__ARID_DEF_arg);
static void swc_T_SwitchRampMot2TrqDem_Init(boolean *rty_RampOn);
static void swc_TCOO_SwitchRampMot2TrqDem(float32 rtu_u1, boolean rtu_sw,
  float32 rtu_u2, float32 rtu_up, float32 rtu_lo, boolean *rty_RampOn,
  ARID_DEF_switch_ramp_swc_TC_c_T *swc_TCOO__ARID_DEF_arg);
static void sw_DTD_DecelerationControl_Init(void);
static void swc_TCO_DTD_DecelerationControl(void);
static void swc_TCOO_APD_DriverDemand_Init(void);
static void swc_TCOO_APD_DriverDemand(void);
static void TDA_TorqueDemandsArbitrati_Init(void);
static void sw_TDA_TorqueDemandsArbitration(void);
static void Front_Rear_Axle_Torque_Distribu(void);
static void Front_Rear_Axle_VSC_Torque_Init(void);
static void Front_Rear_Axle_VSC_Torque_Inte(void);
static void RegenerativeBrakeTorqueCap_Init(void);
static void RegenerativeBrakeTorqueCapacity(void);
static void swc_TQD_TorqueDistribution_Init(void);
static void swc_TCOO_TQD_TorqueDistribution(void);
static void swc_EAD_TargetTorqueControlMot2(void);
static void sw_TVR_TorqueVectorControl_Init(void);
static void swc_TCO_TVR_TorqueVectorControl(void);
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

/*
 * System initialize for atomic system:
 *    '<S79>/turnON_delay'
 *    '<S86>/turnON_delay1'
 *    '<S86>/turnON_delay2'
 *    '<S86>/turnON_delay3'
 *    '<S87>/turnON_delay'
 *    '<S87>/turnON_delay1'
 *    '<S316>/turnON_delay1'
 *    '<S316>/turnON_delay2'
 *    '<S316>/turnON_delay3'
 *    '<S316>/turnON_delay4'
 */
static void swc_TCOO_turnON_delay_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S84>/timed_delay' */
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S79>/turnON_delay'
 *    '<S86>/turnON_delay1'
 *    '<S86>/turnON_delay2'
 *    '<S86>/turnON_delay3'
 *    '<S87>/turnON_delay'
 *    '<S87>/turnON_delay1'
 *    '<S316>/turnON_delay1'
 *    '<S316>/turnON_delay2'
 *    '<S316>/turnON_delay3'
 *    '<S316>/turnON_delay4'
 */
static void swc_TCOO_turnON_delay(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnON_delay_swc_TCO_T
  *swc_TCOO__ARID_DEF_arg)
{
  float32 rtb_t_delay_on;

  /* Saturate: '<S84>/Saturation' */
  if (rtu_t_delay_on > 1.6777216E+7F) {
    /* Saturate: '<S84>/Saturation' */
    rtb_t_delay_on = 1.6777216E+7F;
  } else if (rtu_t_delay_on < 0.0F) {
    /* Saturate: '<S84>/Saturation' */
    rtb_t_delay_on = 0.0F;
  } else {
    /* Saturate: '<S84>/Saturation' */
    rtb_t_delay_on = rtu_t_delay_on;
  }

  /* End of Saturate: '<S84>/Saturation' */

  /* Chart: '<S84>/timed_delay' incorporates:
   *  DataTypeConversion: '<S84>/Data Type Conversion'
   */
  if (swc_TCOO__ARID_DEF_arg->is_active_c14_Ricardo_SW_dev_li == 0U) {
    swc_TCOO__ARID_DEF_arg->is_active_c14_Ricardo_SW_dev_li = 1U;
    if (rtu_flg_in) {
      swc_TCOO__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_TCOO_IN_ON;
      *rty_flg_out = true;
    } else {
      swc_TCOO__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_TCOO_IN_OFF;
      *rty_flg_out = false;
    }
  } else {
    switch (swc_TCOO__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib) {
     case swc_TCOO_IN_OFF:
      if (rtu_flg_in) {
        if (rtb_t_delay_on == 0.0F) {
          swc_TCOO__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_TCOO_IN_ON;
          *rty_flg_out = true;
        } else {
          swc_TCOO__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib =
            swc_TCOO_IN_ON_WAIT;
          swc_TCOO__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = false;
        }
      } else {
        *rty_flg_out = false;
      }
      break;

     case swc_TCOO_IN_ON:
      if (!rtu_flg_in) {
        swc_TCOO__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_TCOO_IN_OFF;
        *rty_flg_out = false;
      } else {
        *rty_flg_out = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtu_flg_in) {
        swc_TCOO__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_TCOO_IN_OFF;
        *rty_flg_out = false;
      } else if (swc_TCOO__ARID_DEF_arg->t_wait > rtb_t_delay_on - rtu_t_step) {
        swc_TCOO__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_TCOO_IN_ON;
        *rty_flg_out = true;
      } else {
        swc_TCOO__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = false;
      }
      break;
    }
  }

  /* End of Chart: '<S84>/timed_delay' */
}

/*
 * Output and update for atomic system:
 *    '<S92>/Falling_Edge'
 *    '<S93>/Falling_Edge'
 *    '<S94>/Falling_Edge'
 *    '<S88>/Falling_Edge'
 *    '<S88>/Falling_Edge1'
 *    '<S88>/Falling_Edge2'
 */
static void swc_TCOO_Falling_Edge(boolean rtu_flg_in, boolean *rty_flg_out,
  ARID_DEF_Falling_Edge_swc_TCO_T *swc_TCOO__ARID_DEF_arg)
{
  /* Logic: '<S98>/Logical Operator1' incorporates:
   *  Logic: '<S98>/Logical Operator2'
   *  UnitDelay: '<S98>/Unit Delay'
   */
  *rty_flg_out = (swc_TCOO__ARID_DEF_arg->UnitDelay_DSTATE && (!rtu_flg_in));

  /* Update for UnitDelay: '<S98>/Unit Delay' */
  swc_TCOO__ARID_DEF_arg->UnitDelay_DSTATE = rtu_flg_in;
}

/*
 * Output and update for atomic system:
 *    '<S87>/SR_latch'
 *    '<S87>/SR_latch1'
 *    '<S316>/SR_latch'
 *    '<S316>/SR_latch1'
 *    '<S365>/SR_latch'
 *    '<S175>/SR_latch'
 *    '<S189>/SR_latch1'
 */
static void swc_TCOO_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch_swc_TCOO_T *swc_TCOO__ARID_DEF_arg)
{
  /* Logic: '<S128>/Logical Operator3' incorporates:
   *  Logic: '<S128>/Logical Operator'
   *  Logic: '<S128>/Logical Operator1'
   *  UnitDelay: '<S128>/Unit Delay'
   */
  *rty_flg_out = ((swc_TCOO__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) && (
    !rtu_flg_reset));

  /* Update for UnitDelay: '<S128>/Unit Delay' */
  swc_TCOO__ARID_DEF_arg->UnitDelay_DSTATE = *rty_flg_out;
}

/*
 * System initialize for atomic system:
 *    '<S87>/turnOFF_delay'
 *    '<S87>/turnOFF_delay1'
 */
static void swc_TCOO_turnOFF_delay_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S130>/timed_delay' */
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S87>/turnOFF_delay'
 *    '<S87>/turnOFF_delay1'
 */
static void swc_TCOO_turnOFF_delay(boolean rtu_flg_in, float32 rtu_t_delay_off,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnOFF_delay_swc_TC_T
  *swc_TCOO__ARID_DEF_arg)
{
  float32 rtb_t_delay_off;

  /* Saturate: '<S130>/Saturation1' */
  if (rtu_t_delay_off > 1.6777216E+7F) {
    /* Saturate: '<S130>/Saturation1' */
    rtb_t_delay_off = 1.6777216E+7F;
  } else if (rtu_t_delay_off < 0.0F) {
    /* Saturate: '<S130>/Saturation1' */
    rtb_t_delay_off = 0.0F;
  } else {
    /* Saturate: '<S130>/Saturation1' */
    rtb_t_delay_off = rtu_t_delay_off;
  }

  /* End of Saturate: '<S130>/Saturation1' */

  /* Chart: '<S130>/timed_delay' incorporates:
   *  DataTypeConversion: '<S130>/Data Type Conversion'
   */
  if (swc_TCOO__ARID_DEF_arg->is_active_c12_Ricardo_SW_dev_li == 0U) {
    swc_TCOO__ARID_DEF_arg->is_active_c12_Ricardo_SW_dev_li = 1U;
    if (rtu_flg_in) {
      swc_TCOO__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_TCOO_IN_ON_p;
      *rty_flg_out = true;
    } else {
      swc_TCOO__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_TCOO_IN_OFF_m;
      *rty_flg_out = false;
    }
  } else {
    switch (swc_TCOO__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib) {
     case swc_TCOO_IN_OFF_m:
      if (rtu_flg_in) {
        swc_TCOO__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_TCOO_IN_ON_p;
        *rty_flg_out = true;
      } else {
        *rty_flg_out = false;
      }
      break;

     case swc_TCOO_IN_OFF_WAIT:
      if (rtu_flg_in) {
        swc_TCOO__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_TCOO_IN_ON_p;
        *rty_flg_out = true;
      } else if (swc_TCOO__ARID_DEF_arg->t_wait > rtb_t_delay_off - rtu_t_step)
      {
        swc_TCOO__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_TCOO_IN_OFF_m;
        *rty_flg_out = false;
      } else {
        swc_TCOO__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = true;
      }
      break;

     default:
      /* case IN_ON: */
      if (!rtu_flg_in) {
        if (rtb_t_delay_off == 0.0F) {
          swc_TCOO__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_TCOO_IN_OFF_m;
          *rty_flg_out = false;
        } else {
          swc_TCOO__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib =
            swc_TCOO_IN_OFF_WAIT;
          swc_TCOO__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = true;
        }
      } else {
        *rty_flg_out = true;
      }
      break;
    }
  }

  /* End of Chart: '<S130>/timed_delay' */
}

/* System initialize for function-call system: '<S1>/DTD_DecelerationControl' */
static void sw_DTD_DecelerationControl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_flg_out_n;
  boolean rtb_flg_out_d;
  boolean rtb_flg_out_i;
  boolean rtb_flg_out_c;
  boolean rtb_flg_out_nk;
  boolean rtb_flg_out_h;
  boolean rtb_flg_out_f5;
  boolean rtb_flg_out_dp;

  /* SystemInitialize for Atomic SubSystem: '<S79>/turnON_delay' */
  swc_TCOO_turnON_delay_Init(&rtb_flg_out_dp);

  /* End of SystemInitialize for SubSystem: '<S79>/turnON_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S86>/turnON_delay1' */
  swc_TCOO_turnON_delay_Init(&rtb_flg_out_f5);

  /* End of SystemInitialize for SubSystem: '<S86>/turnON_delay1' */

  /* SystemInitialize for Atomic SubSystem: '<S87>/turnON_delay' */
  swc_TCOO_turnON_delay_Init(&rtb_flg_out_d);

  /* End of SystemInitialize for SubSystem: '<S87>/turnON_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S87>/turnOFF_delay' */
  swc_TCOO_turnOFF_delay_Init(&rtb_flg_out_c);

  /* End of SystemInitialize for SubSystem: '<S87>/turnOFF_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S87>/turnON_delay1' */
  swc_TCOO_turnON_delay_Init(&rtb_flg_out_n);

  /* End of SystemInitialize for SubSystem: '<S87>/turnON_delay1' */

  /* SystemInitialize for Atomic SubSystem: '<S87>/turnOFF_delay1' */
  swc_TCOO_turnOFF_delay_Init(&rtb_flg_out_i);

  /* End of SystemInitialize for SubSystem: '<S87>/turnOFF_delay1' */

  /* SystemInitialize for Enabled SubSystem: '<S88>/SptRegenLvlCalc' */
  /* InitializeConditions for UnitDelay: '<S145>/Unit Delay2' */
  swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_i = ((uint8)0U);

  /* InitializeConditions for UnitDelay: '<S145>/Unit Delay3' */
  swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_n = false;

  /* InitializeConditions for UnitDelay: '<S145>/Unit Delay1' */
  swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_ol = false;

  /* End of SystemInitialize for SubSystem: '<S88>/SptRegenLvlCalc' */

  /* SystemInitialize for Atomic SubSystem: '<S86>/turnON_delay2' */
  swc_TCOO_turnON_delay_Init(&rtb_flg_out_h);

  /* End of SystemInitialize for SubSystem: '<S86>/turnON_delay2' */

  /* SystemInitialize for Enabled SubSystem: '<S88>/EcoRegenLvlCalc' */
  /* InitializeConditions for UnitDelay: '<S140>/Unit Delay2' */
  swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_em = ((uint8)0U);

  /* InitializeConditions for UnitDelay: '<S140>/Unit Delay3' */
  swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_l = false;

  /* InitializeConditions for UnitDelay: '<S140>/Unit Delay1' */
  swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_o4 = false;

  /* End of SystemInitialize for SubSystem: '<S88>/EcoRegenLvlCalc' */

  /* SystemInitialize for Atomic SubSystem: '<S86>/turnON_delay3' */
  swc_TCOO_turnON_delay_Init(&rtb_flg_out_nk);

  /* End of SystemInitialize for SubSystem: '<S86>/turnON_delay3' */

  /* SystemInitialize for Enabled SubSystem: '<S88>/NormalRegenLvlCalc' */
  /* InitializeConditions for UnitDelay: '<S144>/Unit Delay2' */
  swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_o = ((uint8)0U);

  /* InitializeConditions for UnitDelay: '<S144>/Unit Delay3' */
  swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_j = false;

  /* InitializeConditions for UnitDelay: '<S144>/Unit Delay1' */
  swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_l = false;

  /* End of SystemInitialize for SubSystem: '<S88>/NormalRegenLvlCalc' */
}

/* Output and update for function-call system: '<S1>/DTD_DecelerationControl' */
static void swc_TCO_DTD_DecelerationControl(void)
{
  /* local block i/o variables */
  boolean rtb_RelationalOperator5;
  boolean rtb_LogicalOperator15;
  boolean rtb_LogicalOperator17;
  boolean rtb_RelationalOperator7;
  boolean rtb_FixPtRelationalOperator_l;
  boolean rtb_UnitDelay3_ft;
  boolean rtb_FixPtRelationalOperator_c;
  boolean rtb_FixPtRelationalOperator_f;
  boolean rtb_UnitDelay2_ji;
  boolean rtb_UnitDelay1_n;
  boolean rtb_RelationalOperator1_d;
  boolean rtb_flg_out;
  boolean rtb_flg_out_m;
  boolean rtb_flg_out_f;
  boolean rtb_flg_out_n;
  boolean rtb_flg_out_d;
  boolean rtb_flg_out_i;
  boolean rtb_flg_out_c;
  boolean rtb_LogicalOperator3_l;
  boolean rtb_LogicalOperator3_k;
  boolean rtb_flg_out_nk;
  boolean rtb_flg_out_h;
  boolean rtb_flg_out_f5;
  boolean rtb_flg_out_f2;
  boolean rtb_flg_out_a;
  boolean rtb_flg_out_fg;
  boolean rtb_flg_out_dp;
  float32 rtb_Switch3_g_tmp;
  float32 rtb_Switch3_h;
  float32 rtb_brpd_p_brkPres_bar;
  float32 tmp;
  BrakePedalStatus tmp_1;
  uint8 rtb_Switch20;
  uint8 rtb_Switch2_k1;
  uint8 rtb_Switch6_a;
  uint8 rtb_Switch6_e;
  uint8 rtb_Switch6_p;
  uint8 rtb_Switch7_i;
  uint8 rtb_Switch_mj;
  uint8 rtb_UnitDelay;
  uint8 rtb_UnitDelay1;
  uint8 rtb_UnitDelay1_d;
  uint8 rtb_UnitDelay2;
  uint8 rtb_UnitDelay2_f;
  boolean rtb_Compare;
  boolean rtb_LogicalOperator3;
  boolean rtb_LogicalOperator4;
  boolean rtb_RelationalOperator1_ju;
  boolean rtb_Relay;
  boolean rtb_Relay1;
  boolean rtb_Switch2_bx;
  boolean tmp_0;

  /* RelationalOperator: '<S4>/Relational Operator1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion167'
   *  RelationalOperator: '<S79>/Relational Operator1'
   *  RelationalOperator: '<S87>/Relational Operator3'
   */
  tmp_1 = swc_TCOO_ARID_DEF.DataTypeConversion167;

  /* Switch: '<S4>/Switch2' incorporates:
   *  Constant: '<S74>/Constant'
   *  RelationalOperator: '<S4>/Relational Operator1'
   */
  if (tmp_1 == BrakePedalStatus_PRESSED) {
    /* Switch: '<S4>/Switch2' incorporates:
     *  Constant: '<S4>/Constant2'
     */
    rtb_brpd_p_brkPres_bar = 100.0F;
  } else {
    /* Switch: '<S4>/Switch2' incorporates:
     *  Constant: '<S4>/Constant1'
     */
    rtb_brpd_p_brkPres_bar = 0.0F;
  }

  /* End of Switch: '<S4>/Switch2' */

  /* RelationalOperator: '<S77>/Compare' incorporates:
   *  Constant: '<S77>/Constant'
   */
  rtb_Compare = (swc_TCOO_ARID_DEF.Compare == true);

  /* Relay: '<S78>/Relay' */
  swc_TCOO_ARID_DEF.Relay_Mode_i = ((rtb_brpd_p_brkPres_bar >=
    dtdc_p_brkPresHighThd_bar) || ((rtb_brpd_p_brkPres_bar >
    dtdc_p_brkPresLowThd_bar) && swc_TCOO_ARID_DEF.Relay_Mode_i));
  if (swc_TCOO_ARID_DEF.Relay_Mode_i) {
    tmp = 1.0F;
  } else {
    tmp = 0.0F;
  }

  /* Logic: '<S78>/Logical Operator3' incorporates:
   *  Constant: '<S80>/Constant'
   *  RelationalOperator: '<S80>/Compare'
   *  Relay: '<S78>/Relay'
   */
  rtb_LogicalOperator3 = ((swc_TCOO_ARID_DEF.Compare == false) && (tmp != 0.0F));

  /* Switch: '<S78>/Switch3' incorporates:
   *  Sum: '<S79>/Sum1'
   */
  rtb_Switch3_h = swc_TCOO_ARID_DEF.DataTypeConversion4 -
    swc_TCOO_ARID_DEF.DataTypeConversion8;

  /* Relay: '<S79>/Relay1' */
  swc_TCOO_ARID_DEF.Relay1_Mode_a = ((rtb_Switch3_h >=
    tcoo_dtdc_v_vehSpdErrCtrlHi_kph) || ((rtb_Switch3_h >
    tcoo_dtdc_v_vehSpdErrCtrlLo_kph) && swc_TCOO_ARID_DEF.Relay1_Mode_a));
  if (swc_TCOO_ARID_DEF.Relay1_Mode_a) {
    /* Relay: '<S79>/Relay1' */
    rtb_Relay1 = true;
  } else {
    /* Relay: '<S79>/Relay1' */
    rtb_Relay1 = false;
  }

  /* End of Relay: '<S79>/Relay1' */

  /* RelationalOperator: '<S79>/Relational Operator5' incorporates:
   *  Constant: '<S79>/Constant7'
   */
  rtb_RelationalOperator5 = (swc_TCOO_ARID_DEF.DataTypeConversion4 <=
    tcoo_dtdc_v_vehStopSpd_kph);

  /* Outputs for Atomic SubSystem: '<S79>/turnON_delay' */
  /* Constant: '<S79>/Constant15' incorporates:
   *  Constant: '<S79>/Constant16'
   */
  swc_TCOO_turnON_delay(rtb_RelationalOperator5, tcoo_dtdc_tm_vehStopDelay_s,
                        ((float32)DTD_TASK_INTERVAL_S), &rtb_flg_out_dp,
                        &swc_TCOO_ARID_DEF.ARID_DEF_turnON_delay_p);

  /* End of Outputs for SubSystem: '<S79>/turnON_delay' */

  /* RelationalOperator: '<S79>/Relational Operator1' incorporates:
   *  Constant: '<S74>/Constant'
   *  RelationalOperator: '<S4>/Relational Operator1'
   */
  rtb_RelationalOperator1_ju = (tmp_1 == BrakePedalStatus_PRESSED);

  /* Relay: '<S79>/Relay' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in5'
   *  Relay: '<S75>/Relay1'
   */
  rtb_Switch3_g_tmp = Rte_IRead_swc_TCOO_Step_vcib_VCIP_acpd_x_accPedlPos_pct();
  swc_TCOO_ARID_DEF.Relay_Mode_c = ((rtb_Switch3_g_tmp >=
    tcoo_dtdc_frac_drvAccPedalHi_pct) || ((rtb_Switch3_g_tmp >
    tcoo_dtdc_frac_drvAccPedalLo_pct) && swc_TCOO_ARID_DEF.Relay_Mode_c));
  if (swc_TCOO_ARID_DEF.Relay_Mode_c) {
    /* Relay: '<S79>/Relay' */
    rtb_Relay = true;
  } else {
    /* Relay: '<S79>/Relay' */
    rtb_Relay = false;
  }

  /* End of Relay: '<S79>/Relay' */

  /* Logic: '<S79>/Logical Operator4' incorporates:
   *  Constant: '<S79>/Constant4'
   *  Logic: '<S79>/Logical Operator5'
   *  RelationalOperator: '<S79>/Relational Operator2'
   */
  rtb_LogicalOperator4 = ((swc_TCOO_ARID_DEF.DataTypeConversion4 >=
    tcoo_dtdc_v_calAvrgKVehSpdLo_kph) && (!rtb_Relay1));

  /* Chart: '<S79>/CoastingDrgAutoModeKCal' incorporates:
   *  Constant: '<S79>/Constant10'
   *  Constant: '<S79>/Constant11'
   *  Constant: '<S79>/Constant14'
   *  Constant: '<S79>/Constant6'
   *  RelationalOperator: '<S79>/Relational Operator4'
   */
  if (swc_TCOO_ARID_DEF.is_active_c3_swc_TCOO == 0U) {
    swc_TCOO_ARID_DEF.is_active_c3_swc_TCOO = 1U;
    swc_TCOO_ARID_DEF.is_c3_swc_TCOO = swc_TCOO_IN_IINI_K;
    tcoo_dtdd_st_calKSts = 1U;
    tcoo_dtdd_tm_calKTime_s = 0.0F;
    swc_TCOO_ARID_DEF.time = 0.0F;
    tcoo_dtdd_a_acce = 0.0F;
    tcoo_dtdd_frac_coastDrgK = 1.0F;
    tcoo_dtdd_frac_coastDrgKlastUnLim = 1.0F;
    tcoo_dtdd_b_calKVld = false;
  } else {
    switch (swc_TCOO_ARID_DEF.is_c3_swc_TCOO) {
     case swc_TCOO_IN_CALCK:
      tcoo_dtdd_st_calKSts = 3U;
      if ((!swc_TCOO_ARID_DEF.DataTypeConversion164) || rtb_flg_out_dp) {
        tcoo_dtdd_v_coastDrgVehSpdEnd = swc_TCOO_ARID_DEF.DataTypeConversion4;
        swc_TCOO_ARID_DEF.is_c3_swc_TCOO = swc_TCOO_IN_IINI_K;
        tcoo_dtdd_st_calKSts = 1U;
        tcoo_dtdd_tm_calKTime_s = 0.0F;
        swc_TCOO_ARID_DEF.time = 0.0F;
        tcoo_dtdd_a_acce = 0.0F;
        tcoo_dtdd_frac_coastDrgK = 1.0F;
        tcoo_dtdd_frac_coastDrgKlastUnLim = 1.0F;
        tcoo_dtdd_b_calKVld = false;
      } else if (rtb_RelationalOperator1_ju || rtb_Relay ||
                 (!rtb_LogicalOperator4)) {
        tcoo_dtdd_v_coastDrgVehSpdEnd = swc_TCOO_ARID_DEF.DataTypeConversion4;
        tcoo_dtdd_a_acce = (tcoo_dtdd_v_coastDrgVehSpdStrt -
                            tcoo_dtdd_v_coastDrgVehSpdEnd) / 3.6F / fmaxf
          (tcoo_dtdd_tm_calKTime_s, 0.01F);
        tcoo_dtdd_frac_coastDrgK = tcoo_dtdc_a_yrsLgtAcceTgt_mps2 / fminf(fmaxf
          (tcoo_dtdd_a_acce, 0.01F), 20.0F);
        swc_TCOO_ARID_DEF.is_c3_swc_TCOO = swc_TCOO_IN_QUITCALK_WAIT;
        swc_TCOO_ARID_DEF.time = 0.0F;
      } else {
        tcoo_dtdd_tm_calKTime_s = tcoo_dtdd_tm_calKTime_s + ((float32)
          DTD_TASK_INTERVAL_S);
      }
      break;

     case swc_TCOO_IN_IINI_K:
      tcoo_dtdd_st_calKSts = 1U;
      if (swc_TCOO_ARID_DEF.DataTypeConversion164 && (!rtb_flg_out_dp)) {
        swc_TCOO_ARID_DEF.is_c3_swc_TCOO = swc_TCOO_IN_QUITCALK;
        tcoo_dtdd_st_calKSts = 2U;
        tcoo_dtdd_tm_calKTime_s = 0.0F;
        swc_TCOO_ARID_DEF.time = 0.0F;
      }
      break;

     case swc_TCOO_IN_QUITCALK:
      tcoo_dtdd_st_calKSts = 2U;
      if ((!swc_TCOO_ARID_DEF.DataTypeConversion164) || rtb_flg_out_dp) {
        swc_TCOO_ARID_DEF.is_c3_swc_TCOO = swc_TCOO_IN_IINI_K;
        tcoo_dtdd_st_calKSts = 1U;
        tcoo_dtdd_tm_calKTime_s = 0.0F;
        swc_TCOO_ARID_DEF.time = 0.0F;
        tcoo_dtdd_a_acce = 0.0F;
        tcoo_dtdd_frac_coastDrgK = 1.0F;
        tcoo_dtdd_frac_coastDrgKlastUnLim = 1.0F;
        tcoo_dtdd_b_calKVld = false;
      } else if ((!rtb_RelationalOperator1_ju) && (!rtb_Relay) &&
                 rtb_LogicalOperator4 &&
                 (swc_TCOO_ARID_DEF.DataTypeConversion106 <= 0.0F)) {
        swc_TCOO_ARID_DEF.is_c3_swc_TCOO = swc_TCOO_IN_CALCK;
        tcoo_dtdd_st_calKSts = 3U;
        tcoo_dtdd_tm_calKTime_s = 0.0F;
        tcoo_dtdd_v_coastDrgVehSpdStrt = swc_TCOO_ARID_DEF.DataTypeConversion4;
      }
      break;

     default:
      /* case IN_QUITCALK_WAIT: */
      if (swc_TCOO_ARID_DEF.time > 0.01) {
        if ((tcoo_dtdd_tm_calKTime_s > tcoo_dtdc_tm_timeCalKDelay_s) &&
            (tcoo_dtdd_a_acce > 0.0F)) {
          tcoo_dtdd_frac_coastDrgKlastUnLim = tcoo_dtdd_frac_coastDrgK;
          tcoo_dtdd_b_calKVld = true;
        } else {
          tcoo_dtdd_b_calKVld = false;
        }

        swc_TCOO_ARID_DEF.is_c3_swc_TCOO = swc_TCOO_IN_QUITCALK;
        tcoo_dtdd_st_calKSts = 2U;
        tcoo_dtdd_tm_calKTime_s = 0.0F;
        swc_TCOO_ARID_DEF.time = 0.0F;
      } else {
        swc_TCOO_ARID_DEF.time += ((float32)DTD_TASK_INTERVAL_S);
      }
      break;
    }
  }

  /* End of Chart: '<S79>/CoastingDrgAutoModeKCal' */

  /* Switch: '<S79>/Switch2' incorporates:
   *  Constant: '<S79>/Constant8'
   */
  if (tcoo_dtdc_b_useCoastDrgKi_flg) {
    /* Switch: '<S79>/Switch6' incorporates:
     *  Constant: '<S79>/Constant2'
     *  Constant: '<S79>/Constant5'
     *  RelationalOperator: '<S83>/LowerRelop1'
     *  RelationalOperator: '<S83>/UpperRelop'
     *  Switch: '<S83>/Switch'
     *  Switch: '<S83>/Switch2'
     */
    if (rtb_Relay1) {
      /* Switch: '<S79>/Switch2' incorporates:
       *  Constant: '<S79>/Constant18'
       */
      tcoo_dtdd_frac_coastDrgKlast = 1.0F;
    } else if (tcoo_dtdd_frac_coastDrgKlastUnLim > tcoo_dtdc_frac_coastDrgKMax)
    {
      /* Switch: '<S83>/Switch2' incorporates:
       *  Constant: '<S79>/Constant2'
       *  Switch: '<S79>/Switch2'
       */
      tcoo_dtdd_frac_coastDrgKlast = tcoo_dtdc_frac_coastDrgKMax;
    } else if (tcoo_dtdd_frac_coastDrgKlastUnLim < tcoo_dtdc_frac_coastDrgKMin)
    {
      /* Switch: '<S83>/Switch' incorporates:
       *  Constant: '<S79>/Constant5'
       *  Switch: '<S79>/Switch2'
       */
      tcoo_dtdd_frac_coastDrgKlast = tcoo_dtdc_frac_coastDrgKMin;
    } else {
      /* Switch: '<S79>/Switch2' incorporates:
       *  Switch: '<S83>/Switch'
       */
      tcoo_dtdd_frac_coastDrgKlast = tcoo_dtdd_frac_coastDrgKlastUnLim;
    }

    /* End of Switch: '<S79>/Switch6' */
  } else {
    /* Switch: '<S79>/Switch2' incorporates:
     *  Constant: '<S79>/Constant13'
     */
    tcoo_dtdd_frac_coastDrgKlast = 1.0F;
  }

  /* End of Switch: '<S79>/Switch2' */

  /* UnitDelay: '<S88>/Unit Delay2' */
  rtb_UnitDelay2 = swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_k;

  /* UnitDelay: '<S88>/Unit Delay1' */
  rtb_UnitDelay1 = swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_b;

  /* Switch: '<S87>/Switch2' */
  if (swc_TCOO_ARID_DEF.DataTypeConversion3 != 0.0) {
    /* Switch: '<S87>/Switch' incorporates:
     *  Constant: '<S115>/Constant'
     *  Constant: '<S87>/Constant17'
     *  Logic: '<S87>/Logical Operator13'
     *  Logic: '<S87>/Logical Operator7'
     *  Logic: '<S87>/Logical Operator8'
     *  RelationalOperator: '<S115>/Compare'
     *  Switch: '<S87>/Switch1'
     */
    if ((swc_TCOO_ARID_DEF.DataTypeConversion170 == 1.0) &&
        (swc_TCOO_ARID_DEF.DataTypeConversion1 ||
         (swc_TCOO_ARID_DEF.DataTypeConversion160 &&
          dtdc_b_useSportMapsIn4WDMode))) {
      /* Switch: '<S87>/Switch2' incorporates:
       *  Constant: '<S87>/Sport'
       *  Switch: '<S87>/Switch'
       */
      rtb_Switch2_k1 = ((uint8)2U);
    } else if (swc_TCOO_ARID_DEF.DataTypeConversion6) {
      /* Switch: '<S87>/Switch1' incorporates:
       *  Constant: '<S87>/ECO'
       *  Switch: '<S87>/Switch'
       *  Switch: '<S87>/Switch2'
       */
      rtb_Switch2_k1 = ((uint8)1U);
    } else {
      /* Switch: '<S87>/Switch2' incorporates:
       *  Constant: '<S87>/Normal'
       *  Switch: '<S87>/Switch'
       *  Switch: '<S87>/Switch1'
       */
      rtb_Switch2_k1 = ((uint8)0U);
    }

    /* End of Switch: '<S87>/Switch' */
  } else {
    /* Switch: '<S87>/Switch2' incorporates:
     *  Constant: '<S87>/Normal1'
     */
    rtb_Switch2_k1 = ((uint8)0U);
  }

  /* End of Switch: '<S87>/Switch2' */

  /* Switch: '<S89>/Switch' incorporates:
   *  Constant: '<S89>/Constant4'
   *  RelationalOperator: '<S161>/FixPt Relational Operator'
   *  Switch: '<S89>/Switch2'
   *  UnitDelay: '<S161>/Delay Input1'
   *
   * Block description for '<S161>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (dtdc_b_useIncEdgeCount) {
    /* Switch: '<S89>/Switch1' incorporates:
     *  RelationalOperator: '<S162>/FixPt Relational Operator'
     *  UnitDelay: '<S162>/Delay Input1'
     *
     * Block description for '<S162>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (swc_TCOO_ARID_DEF.DataTypeConversion39 >
        swc_TCOO_ARID_DEF.DelayInput1_DSTATE) {
      /* Switch: '<S89>/Switch' incorporates:
       *  Constant: '<S89>/Constant7'
       */
      rtb_Switch_mj = ((uint8)1U);
    } else {
      /* Switch: '<S89>/Switch' incorporates:
       *  Constant: '<S89>/Constant8'
       */
      rtb_Switch_mj = ((uint8)0U);
    }

    /* End of Switch: '<S89>/Switch1' */
  } else if (swc_TCOO_ARID_DEF.DataTypeConversion39 <
             swc_TCOO_ARID_DEF.DelayInput1_DSTATE_o) {
    /* Switch: '<S89>/Switch2' incorporates:
     *  Constant: '<S89>/Constant5'
     *  Switch: '<S89>/Switch'
     */
    rtb_Switch_mj = ((uint8)1U);
  } else {
    /* Switch: '<S89>/Switch' incorporates:
     *  Constant: '<S89>/Constant6'
     *  Switch: '<S89>/Switch2'
     */
    rtb_Switch_mj = ((uint8)0U);
  }

  /* End of Switch: '<S89>/Switch' */

  /* RelationalOperator: '<S87>/Relational Operator5' incorporates:
   *  Constant: '<S125>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   */
  rtb_RelationalOperator1_ju = (swc_TCOO_ARID_DEF.DataTypeConversion7 ==
    DriveDir_FORWARD);

  /* Switch: '<S87>/Switch3' incorporates:
   *  Constant: '<S113>/Constant'
   *  Constant: '<S87>/Constant10'
   *  RelationalOperator: '<S113>/Compare'
   */
  if (swc_TCOO_ARID_DEF.DataTypeConversion35 == 0.0) {
    tmp_0 = swc_TCOO_ARID_DEF.DataTypeConversion34;
  } else {
    tmp_0 = true;
  }

  /* Logic: '<S87>/Logical Operator14' incorporates:
   *  Constant: '<S114>/Constant'
   *  Constant: '<S126>/Constant'
   *  Constant: '<S74>/Constant'
   *  Constant: '<S87>/Constant11'
   *  Constant: '<S87>/Constant12'
   *  DataTypeConversion: '<Root>/Data Type Conversion36'
   *  RelationalOperator: '<S114>/Compare'
   *  RelationalOperator: '<S4>/Relational Operator1'
   *  RelationalOperator: '<S87>/Relational Operator3'
   *  RelationalOperator: '<S87>/Relational Operator4'
   *  RelationalOperator: '<S87>/Relational Operator6'
   *  Switch: '<S87>/Switch3'
   */
  drid_b_rgnOffGlobalEna = ((swc_TCOO_ARID_DEF.DataTypeConversion36 ==
    GearLeverPos_PARKING) && (tmp_0 == false) && (tmp_1 ==
    BrakePedalStatus_PRESSED) && (swc_TCOO_ARID_DEF.DataTypeConversion33 >=
    dtdc_frac_rgnOffAccPdl_pct) && dtdc_b_useRgnOffEna);

  /* Logic: '<S87>/Logical Operator15' incorporates:
   *  RelationalOperator: '<S123>/FixPt Relational Operator'
   *  UnitDelay: '<S123>/Delay Input1'
   *
   * Block description for '<S123>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator15 = (((sint32)drid_b_rgnOffGlobalEna > (sint32)
    swc_TCOO_ARID_DEF.DelayInput1_DSTATE_n1) &&
    swc_TCOO_ARID_DEF.DataTypeConversion6);

  /* Logic: '<S87>/Logical Operator17' incorporates:
   *  Logic: '<S87>/Logical Operator16'
   *  RelationalOperator: '<S117>/FixPt Relational Operator'
   *  UnitDelay: '<S117>/Delay Input1'
   *
   * Block description for '<S117>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator17 = (((sint32)swc_TCOO_ARID_DEF.DataTypeConversion164 <
    (sint32)swc_TCOO_ARID_DEF.DelayInput1_DSTATE_d) || (!drid_b_rgnOffGlobalEna));

  /* Outputs for Atomic SubSystem: '<S87>/SR_latch' */
  swc_TCOO_SR_latch(rtb_LogicalOperator15, rtb_LogicalOperator17,
                    &rtb_LogicalOperator3_k,
                    &swc_TCOO_ARID_DEF.ARID_DEF_SR_latch_p);

  /* End of Outputs for SubSystem: '<S87>/SR_latch' */

  /* Switch: '<S116>/Switch4' incorporates:
   *  Logic: '<S87>/Logical Operator18'
   *  Switch: '<S116>/Switch5'
   *  Switch: '<S87>/Switch4'
   */
  if (!drid_b_rgnOffGlobalEna) {
    /* Switch: '<S116>/Switch5' incorporates:
     *  Constant: '<S116>/Constant12'
     */
    dtdd_cnt_rgnOffCount = ((uint8)0U);
  } else {
    if (rtb_LogicalOperator3_k) {
      /* Switch: '<S87>/Switch4' incorporates:
       *  RelationalOperator: '<S118>/FixPt Relational Operator'
       *  UnitDelay: '<S118>/Delay Input1'
       *
       * Block description for '<S118>/Delay Input1':
       *
       *  Store in Global RAM
       */
      tmp_0 = ((sint32)swc_TCOO_ARID_DEF.DataTypeConversion6 < (sint32)
               swc_TCOO_ARID_DEF.DelayInput1_DSTATE_nh);
    } else {
      /* Switch: '<S87>/Switch4' incorporates:
       *  RelationalOperator: '<S120>/FixPt Relational Operator'
       *  UnitDelay: '<S120>/Delay Input1'
       *
       * Block description for '<S120>/Delay Input1':
       *
       *  Store in Global RAM
       */
      tmp_0 = ((sint32)swc_TCOO_ARID_DEF.DataTypeConversion6 > (sint32)
               swc_TCOO_ARID_DEF.DelayInput1_DSTATE_dr);
    }

    /* Switch: '<S116>/Switch5' incorporates:
     *  Sum: '<S116>/Add'
     *  Switch: '<S116>/Switch4'
     *  Switch: '<S87>/Switch4'
     *  UnitDelay: '<S116>/Unit Delay2'
     */
    dtdd_cnt_rgnOffCount = (uint8)((uint32)tmp_0 +
      swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_d4);
  }

  /* End of Switch: '<S116>/Switch4' */

  /* RelationalOperator: '<S87>/Relational Operator7' incorporates:
   *  Constant: '<S87>/Constant13'
   */
  rtb_RelationalOperator7 = (dtdd_cnt_rgnOffCount >= dtdc_cnt_rgnOffEnaCount);

  /* RelationalOperator: '<S119>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S119>/Delay Input1'
   *
   * Block description for '<S119>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator_l = ((sint32)
    swc_TCOO_ARID_DEF.DataTypeConversion164 < (sint32)
    swc_TCOO_ARID_DEF.DelayInput1_DSTATE_ie);

  /* Outputs for Atomic SubSystem: '<S87>/SR_latch1' */
  swc_TCOO_SR_latch(rtb_RelationalOperator7, rtb_FixPtRelationalOperator_l,
                    &rtb_LogicalOperator3_l,
                    &swc_TCOO_ARID_DEF.ARID_DEF_SR_latch1_b);

  /* End of Outputs for SubSystem: '<S87>/SR_latch1' */

  /* SignalConversion generated from: '<S87>/SR_latch1' */
  dtdd_b_rgnOffEna = rtb_LogicalOperator3_l;

  /* Logic: '<S87>/Logical Operator2' incorporates:
   *  Constant: '<S87>/Constant1'
   *  Logic: '<S87>/Logical Operator1'
   *  Logic: '<S87>/Logical Operator19'
   */
  rtb_LogicalOperator4 = (swc_TCOO_ARID_DEF.DataTypeConversion164 &&
    (rtb_RelationalOperator1_ju || dtdc_b_noUseGearLeverPos) &&
    (!dtdd_b_rgnOffEna));

  /* Switch: '<S89>/Switch7' */
  if (rtb_LogicalOperator4) {
    /* Switch: '<S89>/Switch7' */
    rtb_Switch7_i = rtb_Switch_mj;
  } else {
    /* Switch: '<S89>/Switch7' incorporates:
     *  Constant: '<S89>/Constant17'
     */
    rtb_Switch7_i = ((uint8)0U);
  }

  /* End of Switch: '<S89>/Switch7' */

  /* Switch: '<S86>/Switch20' */
  if (swc_TCOO_ARID_DEF.DataTypeConversion3 != 0.0) {
    /* Switch: '<S86>/Switch16' incorporates:
     *  Constant: '<S90>/Constant'
     *  Constant: '<S91>/Constant'
     *  RelationalOperator: '<S90>/Compare'
     *  RelationalOperator: '<S91>/Compare'
     *  Switch: '<S86>/Switch9'
     */
    if (rtb_Switch2_k1 == ((uint8)2U)) {
      /* Switch: '<S86>/Switch20' incorporates:
       *  Constant: '<S86>/Constant5'
       *  Switch: '<S86>/Switch16'
       */
      rtb_Switch20 = swctcoo_dtdc_SptDefaultRegLvl;
    } else if (rtb_Switch2_k1 == ((uint8)1U)) {
      /* Switch: '<S86>/Switch9' incorporates:
       *  Constant: '<S86>/Constant22'
       *  Switch: '<S86>/Switch16'
       *  Switch: '<S86>/Switch20'
       */
      rtb_Switch20 = dtdc_ECODefaultRegLvl;
    } else {
      /* Switch: '<S86>/Switch20' incorporates:
       *  Constant: '<S86>/Constant18'
       *  Switch: '<S86>/Switch16'
       *  Switch: '<S86>/Switch9'
       */
      rtb_Switch20 = dtdc_NormalDefaultRegLvl;
    }

    /* End of Switch: '<S86>/Switch16' */
  } else {
    /* Switch: '<S86>/Switch20' incorporates:
     *  Constant: '<S86>/Constant16'
     */
    rtb_Switch20 = tcoo_dtdc_defaultRegLvl;
  }

  /* End of Switch: '<S86>/Switch20' */

  /* UnitDelay: '<S73>/Unit Delay2' */
  rtb_UnitDelay2_f = swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_eb;

  /* UnitDelay: '<S86>/Unit Delay3' */
  rtb_UnitDelay3_ft = swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_o;

  /* Outputs for Atomic SubSystem: '<S86>/turnON_delay1' */
  /* Constant: '<S86>/Constant13' incorporates:
   *  Constant: '<S86>/Constant14'
   */
  swc_TCOO_turnON_delay(rtb_UnitDelay3_ft, dtdc_EEPUpdDelay_s, ((float32)
    DTD_TASK_INTERVAL_S), &rtb_flg_out_f5,
                        &swc_TCOO_ARID_DEF.ARID_DEF_turnON_delay1_g);

  /* End of Outputs for SubSystem: '<S86>/turnON_delay1' */

  /* CCaller: '<S86>/C Caller' */
  swctcoo_dtdd_st_sptRegenLvlFromEE = mBSW_NvmRead_RegenLvlSport();

  /* RelationalOperator: '<S94>/Relational Operator' incorporates:
   *  UnitDelay: '<S94>/Unit Delay3'
   */
  rtb_Relay1 = (swctcoo_dtdd_st_sptRegenLvlFromEE !=
                swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_c);

  /* Outputs for Atomic SubSystem: '<S94>/Falling_Edge' */
  swc_TCOO_Falling_Edge(swc_TCOO_ARID_DEF.DataTypeConversion164, &rtb_flg_out_f2,
                        &swc_TCOO_ARID_DEF.ARID_DEF_Falling_Edge_g);

  /* End of Outputs for SubSystem: '<S94>/Falling_Edge' */

  /* Switch: '<S94>/Switch6' incorporates:
   *  Logic: '<S94>/Logical Operator4'
   */
  if (rtb_Relay1 || rtb_flg_out_f2) {
    /* Switch: '<S94>/Switch7' */
    if (rtb_Relay1) {
      /* Switch: '<S94>/Switch6' */
      rtb_Switch6_a = swctcoo_dtdd_st_sptRegenLvlFromEE;
    } else {
      /* Switch: '<S94>/Switch6' */
      rtb_Switch6_a = rtb_UnitDelay2_f;
    }

    /* End of Switch: '<S94>/Switch7' */
  } else {
    /* Switch: '<S94>/Switch6' incorporates:
     *  UnitDelay: '<S94>/Unit Delay4'
     */
    rtb_Switch6_a = swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_p;
  }

  /* End of Switch: '<S94>/Switch6' */

  /* Switch: '<S86>/Switch17' */
  if (swc_TCOO_ARID_DEF.DataTypeConversion2 != 0.0) {
    /* Switch: '<S86>/Switch17' */
    swctcoo_dtdd_st_sptRegLvlInit = rtb_Switch20;
  } else {
    /* Switch: '<S86>/Switch17' */
    swctcoo_dtdd_st_sptRegLvlInit = rtb_Switch6_a;
  }

  /* End of Switch: '<S86>/Switch17' */

  /* Switch: '<S86>/Switch6' */
  if (!rtb_flg_out_f5) {
    /* Switch: '<S86>/Switch6' */
    rtb_UnitDelay2_f = swctcoo_dtdd_st_sptRegLvlInit;
  }

  /* End of Switch: '<S86>/Switch6' */

  /* Outputs for Atomic SubSystem: '<S87>/turnON_delay' */
  /* Constant: '<S87>/Constant15' incorporates:
   *  Constant: '<S87>/Constant16'
   */
  swc_TCOO_turnON_delay(swc_TCOO_ARID_DEF.DataTypeConversion164,
                        dtdc_EEPUpdDelay_s, ((float32)DTD_TASK_INTERVAL_S),
                        &rtb_flg_out_d, &swc_TCOO_ARID_DEF.ARID_DEF_turnON_delay);

  /* End of Outputs for SubSystem: '<S87>/turnON_delay' */

  /* RelationalOperator: '<S122>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S122>/Delay Input1'
   *
   * Block description for '<S122>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator_c = ((sint32)rtb_flg_out_d > (sint32)
    swc_TCOO_ARID_DEF.DelayInput1_DSTATE_iv);

  /* Outputs for Atomic SubSystem: '<S87>/turnOFF_delay' */
  /* Constant: '<S87>/Constant7' incorporates:
   *  Constant: '<S87>/Constant8'
   */
  swc_TCOO_turnOFF_delay(rtb_FixPtRelationalOperator_c, dtdc_t_IgonInitTime_s,
    ((float32)DTD_TASK_INTERVAL_S), &rtb_flg_out_c,
    &swc_TCOO_ARID_DEF.ARID_DEF_turnOFF_delay);

  /* End of Outputs for SubSystem: '<S87>/turnOFF_delay' */

  /* Outputs for Atomic SubSystem: '<S87>/turnON_delay1' */
  /* Constant: '<S87>/Constant4' incorporates:
   *  Constant: '<S87>/Constant5'
   */
  swc_TCOO_turnON_delay(swc_TCOO_ARID_DEF.DataTypeConversion195,
                        dtdc_EEPUpdDelay_s, ((float32)DTD_TASK_INTERVAL_S),
                        &rtb_flg_out_n,
                        &swc_TCOO_ARID_DEF.ARID_DEF_turnON_delay1_c);

  /* End of Outputs for SubSystem: '<S87>/turnON_delay1' */

  /* RelationalOperator: '<S121>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S121>/Delay Input1'
   *
   * Block description for '<S121>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator_f = ((sint32)rtb_flg_out_n > (sint32)
    swc_TCOO_ARID_DEF.DelayInput1_DSTATE_hb);

  /* Outputs for Atomic SubSystem: '<S87>/turnOFF_delay1' */
  /* Constant: '<S87>/Constant6' incorporates:
   *  Constant: '<S87>/Constant9'
   */
  swc_TCOO_turnOFF_delay(rtb_FixPtRelationalOperator_f, dtdc_t_IgonInitTime_s,
    ((float32)DTD_TASK_INTERVAL_S), &rtb_flg_out_i,
    &swc_TCOO_ARID_DEF.ARID_DEF_turnOFF_delay1);

  /* End of Outputs for SubSystem: '<S87>/turnOFF_delay1' */

  /* Logic: '<S87>/Logical Operator12' */
  rtb_Relay1 = (rtb_flg_out_c || rtb_flg_out_i);

  /* Logic: '<S87>/Logical Operator10' incorporates:
   *  Constant: '<S87>/Constant2'
   *  Logic: '<S87>/Logical Operator9'
   *  RelationalOperator: '<S87>/Relational Operator2'
   */
  rtb_Relay = ((rtb_flg_out_d && (rtb_Switch2_k1 == ((uint8)2U))) || rtb_Relay1);

  /* Switch: '<S86>/Switch1' */
  if (rtb_Relay) {
    /* Switch: '<S86>/Switch2' incorporates:
     *  Constant: '<S86>/Constant12'
     *  Constant: '<S86>/Constant4'
     *  Constant: '<S86>/Constant6'
     *  Constant: '<S86>/Constant7'
     *  Constant: '<S86>/Constant8'
     *  Logic: '<S86>/Logical Operator2'
     *  RelationalOperator: '<S86>/Relational Operator5'
     *  RelationalOperator: '<S86>/Relational Operator7'
     *  RelationalOperator: '<S86>/Relational Operator8'
     *  RelationalOperator: '<S86>/Relational Operator9'
     */
    if (dtdc_useLvl123Ena) {
      tmp_0 = ((rtb_UnitDelay2_f != dtdc_EEPDefaultRegLvl1) && (rtb_UnitDelay2_f
                != dtdc_EEPDefaultRegLvl2) && (rtb_UnitDelay2_f !=
                dtdc_EEPDefaultRegLvl3));
    } else {
      tmp_0 = (rtb_UnitDelay2_f == dtdc_EEPDefaultRegLvl);
    }

    /* Switch: '<S86>/Switch7' incorporates:
     *  Switch: '<S86>/Switch2'
     */
    if (tmp_0) {
      /* Switch: '<S86>/Switch1' */
      rtb_UnitDelay2_f = rtb_Switch20;
    }

    /* End of Switch: '<S86>/Switch7' */
  } else {
    /* Switch: '<S86>/Switch1' incorporates:
     *  Constant: '<S86>/Constant3'
     */
    rtb_UnitDelay2_f = ((uint8)0U);
  }

  /* End of Switch: '<S86>/Switch1' */

  /* Switch: '<S89>/Switch3' incorporates:
   *  Constant: '<S89>/Constant1'
   *  Logic: '<S89>/Logical Operator1'
   *  RelationalOperator: '<S89>/Relational Operator'
   */
  if (rtb_LogicalOperator4 && (rtb_Switch_mj == ((uint8)0U))) {
    /* Switch: '<S89>/Switch3' */
    rtb_Switch_mj = swc_TCOO_ARID_DEF.DataTypeConversion18;
  } else {
    /* Switch: '<S89>/Switch3' incorporates:
     *  Constant: '<S89>/Constant2'
     */
    rtb_Switch_mj = ((uint8)0U);
  }

  /* End of Switch: '<S89>/Switch3' */

  /* Outputs for Enabled SubSystem: '<S88>/SptRegenLvlCalc' incorporates:
   *  EnablePort: '<S145>/FuncEnable'
   */
  /* RelationalOperator: '<S88>/Relational Operator1' incorporates:
   *  Constant: '<S88>/Constant1'
   */
  if (rtb_Relay == true) {
    if (!swc_TCOO_ARID_DEF.SptRegenLvlCalc_MODE) {
      /* InitializeConditions for UnitDelay: '<S145>/Unit Delay2' */
      swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_i = ((uint8)0U);

      /* InitializeConditions for UnitDelay: '<S145>/Unit Delay3' */
      swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_n = false;

      /* InitializeConditions for UnitDelay: '<S145>/Unit Delay1' */
      swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_ol = false;
      swc_TCOO_ARID_DEF.SptRegenLvlCalc_MODE = true;
    }

    /* Switch: '<S145>/Switch' incorporates:
     *  Constant: '<S88>/Constant2'
     *  RelationalOperator: '<S145>/Relational Operator'
     *  UnitDelay: '<S145>/Unit Delay2'
     */
    if (swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_i <= dtdc_MaxCounterValue) {
      /* Switch: '<S145>/Switch2' incorporates:
       *  UnitDelay: '<S145>/Unit Delay3'
       */
      if (swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_n) {
        rtb_UnitDelay2_f = rtb_Switch7_i;
      }

      /* Switch: '<S145>/Switch' incorporates:
       *  Sum: '<S145>/Add'
       *  Switch: '<S145>/Switch2'
       */
      rtb_UnitDelay2_f = (uint8)((uint32)swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_i +
        rtb_UnitDelay2_f);
    } else {
      /* Switch: '<S145>/Switch' incorporates:
       *  Constant: '<S145>/Constant4'
       */
      rtb_UnitDelay2_f = ((uint8)1U);
    }

    /* End of Switch: '<S145>/Switch' */

    /* Switch: '<S145>/Switch3' incorporates:
     *  UnitDelay: '<S145>/Unit Delay1'
     */
    if (swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_ol) {
      /* Switch: '<S145>/Switch1' incorporates:
       *  Constant: '<S160>/Constant'
       *  RelationalOperator: '<S160>/Compare'
       */
      if (rtb_Switch_mj != ((uint8)0U)) {
        /* MinMax: '<S145>/Min' incorporates:
         *  Constant: '<S88>/Constant2'
         */
        if (dtdc_MaxCounterValue <= rtb_Switch_mj) {
          /* Switch: '<S145>/Switch3' incorporates:
           *  Switch: '<S145>/Switch1'
           */
          swctcoo_dtdd_st_SptRegenLvlAct = dtdc_MaxCounterValue;
        } else {
          /* Switch: '<S145>/Switch3' incorporates:
           *  Switch: '<S145>/Switch1'
           */
          swctcoo_dtdd_st_SptRegenLvlAct = rtb_Switch_mj;
        }

        /* End of MinMax: '<S145>/Min' */
      } else {
        /* Switch: '<S145>/Switch3' incorporates:
         *  Switch: '<S145>/Switch1'
         */
        swctcoo_dtdd_st_SptRegenLvlAct = rtb_UnitDelay2_f;
      }

      /* End of Switch: '<S145>/Switch1' */
    } else {
      /* Switch: '<S145>/Switch3' */
      swctcoo_dtdd_st_SptRegenLvlAct = rtb_UnitDelay2_f;
    }

    /* End of Switch: '<S145>/Switch3' */

    /* Update for UnitDelay: '<S145>/Unit Delay2' */
    swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_i = swctcoo_dtdd_st_SptRegenLvlAct;

    /* Update for UnitDelay: '<S145>/Unit Delay3' */
    swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_n = rtb_Relay;

    /* Update for UnitDelay: '<S145>/Unit Delay1' */
    swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_ol = rtb_Relay;
  } else {
    swc_TCOO_ARID_DEF.SptRegenLvlCalc_MODE = false;
  }

  /* End of RelationalOperator: '<S88>/Relational Operator1' */
  /* End of Outputs for SubSystem: '<S88>/SptRegenLvlCalc' */

  /* Saturate: '<S88>/Saturation2' */
  if (swctcoo_dtdd_st_SptRegenLvlAct <= ((uint8)3U)) {
    /* Saturate: '<S88>/Saturation2' */
    rtb_UnitDelay2_f = swctcoo_dtdd_st_SptRegenLvlAct;
  } else {
    /* Saturate: '<S88>/Saturation2' */
    rtb_UnitDelay2_f = ((uint8)3U);
  }

  /* End of Saturate: '<S88>/Saturation2' */

  /* RelationalOperator: '<S139>/Compare' incorporates:
   *  Constant: '<S139>/Constant'
   */
  rtb_Relay = (rtb_Switch2_k1 == ((uint8)2U));

  /* UnitDelay: '<S73>/Unit Delay1' */
  rtb_UnitDelay1_d = swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_n;

  /* UnitDelay: '<S86>/Unit Delay2' */
  rtb_UnitDelay2_ji = swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_kd;

  /* Outputs for Atomic SubSystem: '<S86>/turnON_delay2' */
  /* Constant: '<S86>/Constant36' incorporates:
   *  Constant: '<S86>/Constant37'
   */
  swc_TCOO_turnON_delay(rtb_UnitDelay2_ji, dtdc_EEPUpdDelay_s, ((float32)
    DTD_TASK_INTERVAL_S), &rtb_flg_out_h,
                        &swc_TCOO_ARID_DEF.ARID_DEF_turnON_delay2_f);

  /* End of Outputs for SubSystem: '<S86>/turnON_delay2' */

  /* CCaller: '<S86>/C Caller24' */
  dtdd_st_EcoRegenLvlFromEE = mBSW_NvmRead_RegenLvlEco();

  /* RelationalOperator: '<S92>/Relational Operator' incorporates:
   *  UnitDelay: '<S92>/Unit Delay3'
   */
  rtb_Switch2_bx = (dtdd_st_EcoRegenLvlFromEE !=
                    swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_p);

  /* Outputs for Atomic SubSystem: '<S92>/Falling_Edge' */
  swc_TCOO_Falling_Edge(swc_TCOO_ARID_DEF.DataTypeConversion164, &rtb_flg_out_fg,
                        &swc_TCOO_ARID_DEF.ARID_DEF_Falling_Edge_n);

  /* End of Outputs for SubSystem: '<S92>/Falling_Edge' */

  /* Switch: '<S92>/Switch6' incorporates:
   *  Logic: '<S92>/Logical Operator4'
   */
  if (rtb_Switch2_bx || rtb_flg_out_fg) {
    /* Switch: '<S92>/Switch7' */
    if (rtb_Switch2_bx) {
      /* Switch: '<S92>/Switch6' */
      rtb_Switch6_e = dtdd_st_EcoRegenLvlFromEE;
    } else {
      /* Switch: '<S92>/Switch6' */
      rtb_Switch6_e = rtb_UnitDelay1_d;
    }

    /* End of Switch: '<S92>/Switch7' */
  } else {
    /* Switch: '<S92>/Switch6' incorporates:
     *  UnitDelay: '<S92>/Unit Delay4'
     */
    rtb_Switch6_e = swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_j;
  }

  /* End of Switch: '<S92>/Switch6' */

  /* Switch: '<S86>/Switch15' */
  if (swc_TCOO_ARID_DEF.DataTypeConversion2 != 0.0) {
    /* Switch: '<S86>/Switch15' */
    swctcoo_dtdd_st_ecoRegLvlInit = rtb_Switch20;
  } else {
    /* Switch: '<S86>/Switch15' */
    swctcoo_dtdd_st_ecoRegLvlInit = rtb_Switch6_e;
  }

  /* End of Switch: '<S86>/Switch15' */

  /* Switch: '<S86>/Switch13' */
  if (!rtb_flg_out_h) {
    /* Switch: '<S86>/Switch13' */
    rtb_UnitDelay1_d = swctcoo_dtdd_st_ecoRegLvlInit;
  }

  /* End of Switch: '<S86>/Switch13' */

  /* Logic: '<S87>/Logical Operator6' incorporates:
   *  Constant: '<S87>/Constant23'
   *  Logic: '<S87>/Logical Operator4'
   *  RelationalOperator: '<S87>/Relational Operator8'
   */
  rtb_Switch2_bx = (rtb_Relay1 || (rtb_flg_out_d && (rtb_Switch2_k1 == ((uint8)
    1U))));

  /* Switch: '<S86>/Switch11' */
  if (rtb_Switch2_bx) {
    /* Switch: '<S86>/Switch12' incorporates:
     *  Constant: '<S86>/Constant2'
     *  Constant: '<S86>/Constant30'
     *  Constant: '<S86>/Constant31'
     *  Constant: '<S86>/Constant32'
     *  Constant: '<S86>/Constant34'
     *  Logic: '<S86>/Logical Operator5'
     *  RelationalOperator: '<S86>/Relational Operator1'
     *  RelationalOperator: '<S86>/Relational Operator10'
     *  RelationalOperator: '<S86>/Relational Operator11'
     *  RelationalOperator: '<S86>/Relational Operator12'
     */
    if (dtdc_useLvl123Ena) {
      tmp_0 = ((rtb_UnitDelay1_d != dtdc_EEPDefaultRegLvl1) && (rtb_UnitDelay1_d
                != dtdc_EEPDefaultRegLvl2) && (rtb_UnitDelay1_d !=
                dtdc_EEPDefaultRegLvl3));
    } else {
      tmp_0 = (rtb_UnitDelay1_d == dtdc_EEPDefaultRegLvl);
    }

    /* Switch: '<S86>/Switch14' incorporates:
     *  Switch: '<S86>/Switch12'
     */
    if (tmp_0) {
      /* Switch: '<S86>/Switch11' */
      rtb_UnitDelay1_d = rtb_Switch20;
    }

    /* End of Switch: '<S86>/Switch14' */
  } else {
    /* Switch: '<S86>/Switch11' incorporates:
     *  Constant: '<S86>/Constant24'
     */
    rtb_UnitDelay1_d = ((uint8)0U);
  }

  /* End of Switch: '<S86>/Switch11' */

  /* Outputs for Enabled SubSystem: '<S88>/EcoRegenLvlCalc' incorporates:
   *  EnablePort: '<S140>/FuncEnable'
   */
  /* RelationalOperator: '<S88>/Relational Operator7' incorporates:
   *  Constant: '<S88>/Constant12'
   */
  if (rtb_Switch2_bx == true) {
    if (!swc_TCOO_ARID_DEF.EcoRegenLvlCalc_MODE) {
      /* InitializeConditions for UnitDelay: '<S140>/Unit Delay2' */
      swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_em = ((uint8)0U);

      /* InitializeConditions for UnitDelay: '<S140>/Unit Delay3' */
      swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_l = false;

      /* InitializeConditions for UnitDelay: '<S140>/Unit Delay1' */
      swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_o4 = false;
      swc_TCOO_ARID_DEF.EcoRegenLvlCalc_MODE = true;
    }

    /* Switch: '<S140>/Switch' incorporates:
     *  Constant: '<S88>/Constant35'
     *  RelationalOperator: '<S140>/Relational Operator'
     *  UnitDelay: '<S140>/Unit Delay2'
     */
    if (swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_em <= dtdc_MaxCounterValue) {
      /* Switch: '<S140>/Switch2' incorporates:
       *  UnitDelay: '<S140>/Unit Delay3'
       */
      if (swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_l) {
        rtb_UnitDelay1_d = rtb_Switch7_i;
      }

      /* Switch: '<S140>/Switch' incorporates:
       *  Sum: '<S140>/Add'
       *  Switch: '<S140>/Switch2'
       */
      rtb_UnitDelay1_d = (uint8)((uint32)swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_em
        + rtb_UnitDelay1_d);
    } else {
      /* Switch: '<S140>/Switch' incorporates:
       *  Constant: '<S140>/Constant4'
       */
      rtb_UnitDelay1_d = ((uint8)1U);
    }

    /* End of Switch: '<S140>/Switch' */

    /* Switch: '<S140>/Switch3' incorporates:
     *  UnitDelay: '<S140>/Unit Delay1'
     */
    if (swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_o4) {
      /* Switch: '<S140>/Switch1' incorporates:
       *  Constant: '<S149>/Constant'
       *  RelationalOperator: '<S149>/Compare'
       */
      if (rtb_Switch_mj != ((uint8)0U)) {
        /* MinMax: '<S140>/Min' incorporates:
         *  Constant: '<S88>/Constant35'
         */
        if (dtdc_MaxCounterValue <= rtb_Switch_mj) {
          /* Switch: '<S140>/Switch3' incorporates:
           *  Switch: '<S140>/Switch1'
           */
          dtdd_st_EcoRegenLvlAct = dtdc_MaxCounterValue;
        } else {
          /* Switch: '<S140>/Switch3' incorporates:
           *  Switch: '<S140>/Switch1'
           */
          dtdd_st_EcoRegenLvlAct = rtb_Switch_mj;
        }

        /* End of MinMax: '<S140>/Min' */
      } else {
        /* Switch: '<S140>/Switch3' incorporates:
         *  Switch: '<S140>/Switch1'
         */
        dtdd_st_EcoRegenLvlAct = rtb_UnitDelay1_d;
      }

      /* End of Switch: '<S140>/Switch1' */
    } else {
      /* Switch: '<S140>/Switch3' */
      dtdd_st_EcoRegenLvlAct = rtb_UnitDelay1_d;
    }

    /* End of Switch: '<S140>/Switch3' */

    /* Update for UnitDelay: '<S140>/Unit Delay2' */
    swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_em = dtdd_st_EcoRegenLvlAct;

    /* Update for UnitDelay: '<S140>/Unit Delay3' */
    swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_l = rtb_Switch2_bx;

    /* Update for UnitDelay: '<S140>/Unit Delay1' */
    swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_o4 = rtb_Switch2_bx;
  } else {
    swc_TCOO_ARID_DEF.EcoRegenLvlCalc_MODE = false;
  }

  /* End of RelationalOperator: '<S88>/Relational Operator7' */
  /* End of Outputs for SubSystem: '<S88>/EcoRegenLvlCalc' */

  /* Saturate: '<S88>/Saturation1' */
  if (dtdd_st_EcoRegenLvlAct <= ((uint8)3U)) {
    /* Saturate: '<S88>/Saturation1' */
    rtb_UnitDelay1_d = dtdd_st_EcoRegenLvlAct;
  } else {
    /* Saturate: '<S88>/Saturation1' */
    rtb_UnitDelay1_d = ((uint8)3U);
  }

  /* End of Saturate: '<S88>/Saturation1' */

  /* UnitDelay: '<S73>/Unit Delay' */
  rtb_UnitDelay = swc_TCOO_ARID_DEF.UnitDelay_DSTATE_b;

  /* UnitDelay: '<S86>/Unit Delay1' */
  rtb_UnitDelay1_n = swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_o;

  /* Outputs for Atomic SubSystem: '<S86>/turnON_delay3' */
  /* Constant: '<S86>/Constant38' incorporates:
   *  Constant: '<S86>/Constant39'
   */
  swc_TCOO_turnON_delay(rtb_UnitDelay1_n, dtdc_EEPUpdDelay_s, ((float32)
    DTD_TASK_INTERVAL_S), &rtb_flg_out_nk,
                        &swc_TCOO_ARID_DEF.ARID_DEF_turnON_delay3_c);

  /* End of Outputs for SubSystem: '<S86>/turnON_delay3' */

  /* CCaller: '<S86>/C Caller23' */
  dtdd_st_NormRegenLvlFromEE = mBSW_NvmRead_RegenLvl();

  /* RelationalOperator: '<S93>/Relational Operator' incorporates:
   *  UnitDelay: '<S93>/Unit Delay3'
   */
  rtb_Switch2_bx = (dtdd_st_NormRegenLvlFromEE !=
                    swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_h);

  /* Outputs for Atomic SubSystem: '<S93>/Falling_Edge' */
  swc_TCOO_Falling_Edge(swc_TCOO_ARID_DEF.DataTypeConversion164, &rtb_flg_out_a,
                        &swc_TCOO_ARID_DEF.ARID_DEF_Falling_Edge_m);

  /* End of Outputs for SubSystem: '<S93>/Falling_Edge' */

  /* Switch: '<S93>/Switch6' incorporates:
   *  Logic: '<S93>/Logical Operator4'
   */
  if (rtb_Switch2_bx || rtb_flg_out_a) {
    /* Switch: '<S93>/Switch7' */
    if (rtb_Switch2_bx) {
      /* Switch: '<S93>/Switch6' */
      rtb_Switch6_p = dtdd_st_NormRegenLvlFromEE;
    } else {
      /* Switch: '<S93>/Switch6' */
      rtb_Switch6_p = rtb_UnitDelay;
    }

    /* End of Switch: '<S93>/Switch7' */
  } else {
    /* Switch: '<S93>/Switch6' incorporates:
     *  UnitDelay: '<S93>/Unit Delay4'
     */
    rtb_Switch6_p = swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_pd;
  }

  /* End of Switch: '<S93>/Switch6' */

  /* Switch: '<S86>/Switch10' */
  if (swc_TCOO_ARID_DEF.DataTypeConversion2 != 0.0) {
    /* Switch: '<S86>/Switch10' */
    swctcoo_dtdd_st_normRegLvlInit = rtb_Switch20;
  } else {
    /* Switch: '<S86>/Switch10' */
    swctcoo_dtdd_st_normRegLvlInit = rtb_Switch6_p;
  }

  /* End of Switch: '<S86>/Switch10' */

  /* Switch: '<S86>/Switch5' */
  if (!rtb_flg_out_nk) {
    /* Switch: '<S86>/Switch5' */
    rtb_UnitDelay = swctcoo_dtdd_st_normRegLvlInit;
  }

  /* End of Switch: '<S86>/Switch5' */

  /* Logic: '<S87>/Logical Operator5' incorporates:
   *  Constant: '<S87>/Constant27'
   *  Logic: '<S87>/Logical Operator3'
   *  RelationalOperator: '<S87>/Relational Operator9'
   */
  rtb_Relay1 = (((rtb_Switch2_k1 == ((uint8)0U)) && rtb_flg_out_d) || rtb_Relay1);

  /* Switch: '<S86>/Switch3' */
  if (rtb_Relay1) {
    /* Switch: '<S86>/Switch4' incorporates:
     *  Constant: '<S86>/Constant1'
     *  Constant: '<S86>/Constant19'
     *  Constant: '<S86>/Constant20'
     *  Constant: '<S86>/Constant21'
     *  Constant: '<S86>/Constant9'
     *  Logic: '<S86>/Logical Operator1'
     *  RelationalOperator: '<S86>/Relational Operator2'
     *  RelationalOperator: '<S86>/Relational Operator3'
     *  RelationalOperator: '<S86>/Relational Operator4'
     *  RelationalOperator: '<S86>/Relational Operator6'
     */
    if (dtdc_useLvl123Ena) {
      tmp_0 = ((rtb_UnitDelay != dtdc_EEPDefaultRegLvl1) && (rtb_UnitDelay !=
                dtdc_EEPDefaultRegLvl2) && (rtb_UnitDelay !=
                dtdc_EEPDefaultRegLvl3));
    } else {
      tmp_0 = (rtb_UnitDelay == dtdc_EEPDefaultRegLvl);
    }

    /* Switch: '<S86>/Switch8' incorporates:
     *  Switch: '<S86>/Switch4'
     */
    if (!tmp_0) {
      /* Switch: '<S86>/Switch3' */
      rtb_Switch20 = rtb_UnitDelay;
    }

    /* End of Switch: '<S86>/Switch8' */
  } else {
    /* Switch: '<S86>/Switch3' incorporates:
     *  Constant: '<S86>/Constant10'
     */
    rtb_Switch20 = ((uint8)0U);
  }

  /* End of Switch: '<S86>/Switch3' */

  /* Outputs for Enabled SubSystem: '<S88>/NormalRegenLvlCalc' incorporates:
   *  EnablePort: '<S144>/FuncEnable'
   */
  /* RelationalOperator: '<S88>/Relational Operator2' incorporates:
   *  Constant: '<S88>/Constant13'
   */
  if (rtb_Relay1 == true) {
    if (!swc_TCOO_ARID_DEF.NormalRegenLvlCalc_MODE) {
      /* InitializeConditions for UnitDelay: '<S144>/Unit Delay2' */
      swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_o = ((uint8)0U);

      /* InitializeConditions for UnitDelay: '<S144>/Unit Delay3' */
      swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_j = false;

      /* InitializeConditions for UnitDelay: '<S144>/Unit Delay1' */
      swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_l = false;
      swc_TCOO_ARID_DEF.NormalRegenLvlCalc_MODE = true;
    }

    /* Switch: '<S144>/Switch' incorporates:
     *  Constant: '<S88>/Constant3'
     *  RelationalOperator: '<S144>/Relational Operator'
     *  UnitDelay: '<S144>/Unit Delay2'
     */
    if (swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_o <= dtdc_MaxCounterValue) {
      /* Switch: '<S144>/Switch2' incorporates:
       *  UnitDelay: '<S144>/Unit Delay3'
       */
      if (swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_j) {
        rtb_Switch20 = rtb_Switch7_i;
      }

      /* Switch: '<S144>/Switch' incorporates:
       *  Sum: '<S144>/Add'
       *  Switch: '<S144>/Switch2'
       */
      rtb_Switch7_i = (uint8)((uint32)swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_o +
        rtb_Switch20);
    } else {
      /* Switch: '<S144>/Switch' incorporates:
       *  Constant: '<S144>/Constant4'
       */
      rtb_Switch7_i = ((uint8)1U);
    }

    /* End of Switch: '<S144>/Switch' */

    /* Switch: '<S144>/Switch3' incorporates:
     *  UnitDelay: '<S144>/Unit Delay1'
     */
    if (swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_l) {
      /* Switch: '<S144>/Switch1' incorporates:
       *  Constant: '<S159>/Constant'
       *  RelationalOperator: '<S159>/Compare'
       */
      if (rtb_Switch_mj != ((uint8)0U)) {
        /* MinMax: '<S144>/Min' incorporates:
         *  Constant: '<S88>/Constant3'
         */
        if (dtdc_MaxCounterValue <= rtb_Switch_mj) {
          /* Switch: '<S144>/Switch3' incorporates:
           *  Switch: '<S144>/Switch1'
           */
          dtdd_st_NormalRegenLvlAct = dtdc_MaxCounterValue;
        } else {
          /* Switch: '<S144>/Switch3' incorporates:
           *  Switch: '<S144>/Switch1'
           */
          dtdd_st_NormalRegenLvlAct = rtb_Switch_mj;
        }

        /* End of MinMax: '<S144>/Min' */
      } else {
        /* Switch: '<S144>/Switch3' incorporates:
         *  Switch: '<S144>/Switch1'
         */
        dtdd_st_NormalRegenLvlAct = rtb_Switch7_i;
      }

      /* End of Switch: '<S144>/Switch1' */
    } else {
      /* Switch: '<S144>/Switch3' */
      dtdd_st_NormalRegenLvlAct = rtb_Switch7_i;
    }

    /* End of Switch: '<S144>/Switch3' */

    /* Update for UnitDelay: '<S144>/Unit Delay2' */
    swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_o = dtdd_st_NormalRegenLvlAct;

    /* Update for UnitDelay: '<S144>/Unit Delay3' */
    swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_j = rtb_Relay1;

    /* Update for UnitDelay: '<S144>/Unit Delay1' */
    swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_l = rtb_Relay1;
  } else {
    swc_TCOO_ARID_DEF.NormalRegenLvlCalc_MODE = false;
  }

  /* End of RelationalOperator: '<S88>/Relational Operator2' */
  /* End of Outputs for SubSystem: '<S88>/NormalRegenLvlCalc' */

  /* Saturate: '<S88>/Saturation' */
  if (dtdd_st_NormalRegenLvlAct <= ((uint8)3U)) {
    /* Saturate: '<S88>/Saturation' */
    rtb_Switch7_i = dtdd_st_NormalRegenLvlAct;
  } else {
    /* Saturate: '<S88>/Saturation' */
    rtb_Switch7_i = ((uint8)3U);
  }

  /* End of Saturate: '<S88>/Saturation' */

  /* Switch: '<S88>/Switch2' incorporates:
   *  Constant: '<S138>/Constant'
   *  RelationalOperator: '<S138>/Compare'
   *  Switch: '<S88>/Switch1'
   */
  if (rtb_Relay) {
    /* Switch: '<S88>/Switch2' */
    rtb_Switch20 = rtb_UnitDelay2_f;
  } else if (rtb_Switch2_k1 == ((uint8)1U)) {
    /* Switch: '<S88>/Switch1' incorporates:
     *  Switch: '<S88>/Switch2'
     */
    rtb_Switch20 = rtb_UnitDelay1_d;
  } else {
    /* Switch: '<S88>/Switch2' incorporates:
     *  Switch: '<S88>/Switch1'
     */
    rtb_Switch20 = rtb_Switch7_i;
  }

  /* End of Switch: '<S88>/Switch2' */

  /* Switch: '<S88>/Switch4' */
  if (swc_TCOO_ARID_DEF.DataTypeConversion3 != 0.0) {
    /* Switch: '<S88>/Switch3' incorporates:
     *  RelationalOperator: '<S88>/Relational Operator3'
     */
    if (rtb_UnitDelay1 != rtb_Switch2_k1) {
      /* Switch: '<S88>/Switch4' */
      dtdd_st_RegenLvlAct = rtb_UnitDelay2;
    } else {
      /* Switch: '<S88>/Switch4' */
      dtdd_st_RegenLvlAct = rtb_Switch20;
    }

    /* End of Switch: '<S88>/Switch3' */
  } else {
    /* Switch: '<S88>/Switch4' */
    dtdd_st_RegenLvlAct = rtb_Switch7_i;
  }

  /* End of Switch: '<S88>/Switch4' */

  /* Switch: '<S78>/Switch3' incorporates:
   *  Constant: '<S78>/Constant1'
   *  Constant: '<S78>/Constant9'
   *  RelationalOperator: '<S78>/Relational Operator'
   *  RelationalOperator: '<S78>/Relational Operator1'
   *  Switch: '<S78>/Switch1'
   *  Switch: '<S78>/Switch2'
   */
  if (rtb_LogicalOperator3) {
    /* Switch: '<S78>/Switch3' incorporates:
     *  Constant: '<S78>/Constant3'
     */
    rtb_Switch3_h = 0.0F;
  } else if (dtdd_st_RegenLvlAct == ((uint8)3U)) {
    /* Switch: '<S78>/Switch3' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion4'
     *  Lookup_n-D: '<S78>/1-D Lookup Table6'
     *  Product: '<S78>/Product1'
     *  Switch: '<S78>/Switch2'
     */
    rtb_Switch3_h = tcoo_dtdd_frac_coastDrgKlast * look1_iflf_binlcapw
      (swc_TCOO_ARID_DEF.DataTypeConversion4, (const float32 *)
       &dtda_trqDragDemEV_Y_VehSpd_kph[0], (const float32 *)
       &dtdm_trqDragDemEVOffs3_Z_Nm[0], 26U);
  } else if (dtdd_st_RegenLvlAct == ((uint8)2U)) {
    /* Switch: '<S78>/Switch3' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion4'
     *  Lookup_n-D: '<S78>/1-D Lookup Table3'
     *  Switch: '<S78>/Switch1'
     *  Switch: '<S78>/Switch2'
     */
    rtb_Switch3_h = look1_iflf_binlcapw(swc_TCOO_ARID_DEF.DataTypeConversion4, (
      const float32 *)&dtda_trqDragDemEV_Y_VehSpd_kph[0], (const float32 *)
      &dtdm_trqDragDemEVOffs2_Z_Nm[0], 26U);
  } else {
    /* Switch: '<S78>/Switch3' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion4'
     *  Lookup_n-D: '<S78>/1-D Lookup Table5'
     *  Switch: '<S78>/Switch1'
     *  Switch: '<S78>/Switch2'
     */
    rtb_Switch3_h = look1_iflf_binlcapw(swc_TCOO_ARID_DEF.DataTypeConversion4, (
      const float32 *)&dtda_trqDragDemEV_Y_VehSpd_kph[0], (const float32 *)
      &dtdm_trqDragDemEVOffs1_Z_Nm[0], 26U);
  }

  /* End of Switch: '<S78>/Switch3' */

  /* Sum: '<S78>/Sum1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  Lookup_n-D: '<S78>/1-D Lookup Table'
   */
  dtdd_tq_whlEVCoastingDrag_Nm = rtb_Switch3_h + look1_iflf_binlcapw
    (swc_TCOO_ARID_DEF.DataTypeConversion4, (const float32 *)
     &dtda_trqDragDemEV_Y_VehSpd_kph[0], (const float32 *)
     &dtdm_trqDragDemEV_Z_Nm[0], 26U);

  /* Switch: '<S71>/Switch2' */
  if (rtb_Compare) {
    /* MinMax: '<S75>/MinMax6' incorporates:
     *  Constant: '<S71>/Constant'
     */
    rtb_brpd_p_brkPres_bar = 0.0F;
  } else {
    /* MinMax: '<S75>/MinMax6' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion4'
     *  Lookup_n-D: '<S71>/1-D Lookup Table'
     *  Lookup_n-D: '<S71>/1-D Lookup Table2'
     *  Product: '<S71>/Product'
     *  Switch: '<S4>/Switch2'
     */
    rtb_brpd_p_brkPres_bar = look1_iflf_binlcapw(rtb_brpd_p_brkPres_bar, (const
      float32 *)&dtda_regBrkTrqMap_X_BrkPres_bar[0], (const float32 *)
      &dtdf_regBrkTrqEVMap_Y_Nm[0], 7U) * look1_iflf_binlcapw
      (swc_TCOO_ARID_DEF.DataTypeConversion4, (const float32 *)
       &dtda_regBrkTrqDerate_X_VehSpd_kph[0], (const float32 *)
       &dtdf_regBrkTrqDerate_Y_fact[0], 9U);
  }

  /* End of Switch: '<S71>/Switch2' */

  /* Sum: '<S71>/Sum' */
  dtdd_tq_whlEVBrakingDrag_Nm = dtdd_tq_whlEVCoastingDrag_Nm +
    rtb_brpd_p_brkPres_bar;

  /* Relay: '<S87>/Relay2' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in4'
   */
  rtb_brpd_p_brkPres_bar = Rte_IRead_swc_TCOO_Step_vcib_VCIP_hvbd_q_hvbSOC_pct();
  swc_TCOO_ARID_DEF.Relay2_Mode_n = ((rtb_brpd_p_brkPres_bar >=
    swctcoo_dtdc_frac_hvbSocDrgDecHigh_pct) || ((rtb_brpd_p_brkPres_bar >
    swctcoo_dtdc_frac_hvbSocDrgDecLow_pct) && swc_TCOO_ARID_DEF.Relay2_Mode_n));
  if (swc_TCOO_ARID_DEF.Relay2_Mode_n) {
    tmp = 1.0F;
  } else {
    tmp = 0.0F;
  }

  /* Switch: '<S87>/Switch11' incorporates:
   *  Logic: '<S87>/Logical Operator11'
   *  Relay: '<S87>/Relay2'
   */
  if ((tmp != 0.0F) && rtb_RelationalOperator1_ju &&
      swc_TCOO_ARID_DEF.DataTypeConversion164) {
    /* Switch: '<S87>/Switch11' incorporates:
     *  Constant: '<S87>/Constant3'
     */
    swctcoo_dtdd_b_drvPfmncDrgDec = true;
  } else {
    /* Switch: '<S87>/Switch11' incorporates:
     *  Constant: '<S87>/Constant24'
     */
    swctcoo_dtdd_b_drvPfmncDrgDec = false;
  }

  /* End of Switch: '<S87>/Switch11' */

  /* RelationalOperator: '<S87>/Relational Operator1' incorporates:
   *  Constant: '<S127>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion165'
   */
  rtb_RelationalOperator1_d = (swc_TCOO_ARID_DEF.DataTypeConversion165 ==
    PmmStatus_DRIVE);

  /* Outputs for Atomic SubSystem: '<S88>/Falling_Edge1' */
  swc_TCOO_Falling_Edge(swc_TCOO_ARID_DEF.DataTypeConversion164, &rtb_flg_out_m,
                        &swc_TCOO_ARID_DEF.ARID_DEF_Falling_Edge1);

  /* End of Outputs for SubSystem: '<S88>/Falling_Edge1' */

  /* Outputs for Enabled SubSystem: '<S88>/mBSW_NvmWrite_RegenLvlECO' incorporates:
   *  EnablePort: '<S146>/Enable'
   */
  if (rtb_flg_out_m) {
    /* CCaller: '<S146>/C Caller47' */
    mBSW_NvmWrite_RegenLvlEco(rtb_UnitDelay1_d);
  }

  /* End of Outputs for SubSystem: '<S88>/mBSW_NvmWrite_RegenLvlECO' */

  /* Outputs for Atomic SubSystem: '<S88>/Falling_Edge' */
  swc_TCOO_Falling_Edge(swc_TCOO_ARID_DEF.DataTypeConversion164, &rtb_flg_out_f,
                        &swc_TCOO_ARID_DEF.ARID_DEF_Falling_Edge);

  /* End of Outputs for SubSystem: '<S88>/Falling_Edge' */

  /* Outputs for Enabled SubSystem: '<S88>/mBSW_NvmWrite_RegenLvlNORMAL' incorporates:
   *  EnablePort: '<S147>/Enable'
   */
  if (rtb_flg_out_f) {
    /* CCaller: '<S147>/C Caller26' */
    mBSW_NvmWrite_RegenLvl(rtb_Switch7_i);
  }

  /* End of Outputs for SubSystem: '<S88>/mBSW_NvmWrite_RegenLvlNORMAL' */

  /* Outputs for Atomic SubSystem: '<S88>/Falling_Edge2' */
  swc_TCOO_Falling_Edge(swc_TCOO_ARID_DEF.DataTypeConversion164, &rtb_flg_out,
                        &swc_TCOO_ARID_DEF.ARID_DEF_Falling_Edge2);

  /* End of Outputs for SubSystem: '<S88>/Falling_Edge2' */

  /* Outputs for Enabled SubSystem: '<S88>/mBSW_NvmWrite_RegenLvlSPORT' incorporates:
   *  EnablePort: '<S148>/Enable'
   */
  if (rtb_flg_out) {
    /* CCaller: '<S148>/C Caller' */
    mBSW_NvmWrite_RegenLvlSport(rtb_UnitDelay2_f);
  }

  /* End of Outputs for SubSystem: '<S88>/mBSW_NvmWrite_RegenLvlSPORT' */

  /* SignalConversion: '<S88>/Signal Conversion' */
  dtdd_st_NormMemRegenLvl = rtb_Switch7_i;

  /* SignalConversion: '<S88>/Signal Conversion1' */
  dtdd_st_EcoMemRegenLvl = rtb_UnitDelay1_d;

  /* SignalConversion: '<S88>/Signal Conversion2' */
  swctcoo_dtdd_st_SptMemRegenLvl = rtb_UnitDelay2_f;

  /* Switch: '<S88>/Switch6' */
  if (rtb_LogicalOperator4) {
    /* Switch: '<S88>/Switch6' */
    dtdd_st_RegenLvlDisp = dtdd_st_RegenLvlAct;
  } else {
    /* Switch: '<S88>/Switch6' incorporates:
     *  Constant: '<S88>/Constant14'
     */
    dtdd_st_RegenLvlDisp = ((uint8)0U);
  }

  /* End of Switch: '<S88>/Switch6' */

  /* Relay: '<S75>/Relay1' */
  swc_TCOO_ARID_DEF.Relay1_Mode_f = ((rtb_Switch3_g_tmp >=
    swctcoo_dtdc_frac_pedCoastOffHigh_pct) || ((rtb_Switch3_g_tmp >
    swctcoo_dtdc_frac_pedCoastOffLow_pct) && swc_TCOO_ARID_DEF.Relay1_Mode_f));

  /* Relay: '<S75>/Relay2' */
  swc_TCOO_ARID_DEF.Relay2_Mode_m = ((swc_TCOO_ARID_DEF.DataTypeConversion4 >=
    swctcoo_dtdc_v_vSpdCrbsOnHigh_kph) ||
    ((swc_TCOO_ARID_DEF.DataTypeConversion4 > swctcoo_dtdc_v_vSpdCrbsOnLow_kph) &&
     swc_TCOO_ARID_DEF.Relay2_Mode_m));
  if (swc_TCOO_ARID_DEF.Relay2_Mode_m) {
    tmp = 1.0F;
  } else {
    tmp = 0.0F;
  }

  /* Logic: '<S75>/Logical Operator5' incorporates:
   *  Constant: '<S170>/Constant'
   *  Constant: '<S172>/Constant'
   *  Constant: '<S75>/Constant12'
   *  Logic: '<S75>/Logical Operator7'
   *  RelationalOperator: '<S170>/Compare'
   *  RelationalOperator: '<S172>/Compare'
   *  Relay: '<S75>/Relay2'
   */
  swctcoo_dtdd_b_ehbMbRgnOvrCtl = ((swc_TCOO_ARID_DEF.Compare == true) &&
    (swc_TCOO_ARID_DEF.DataTypeConversion187 == 1.0) &&
    swctcoo_dtdc_b_ehbOvrCtlWhlDrgPmt && (!tcoo_eadd_b_ehbMsgErrDebd) && (tmp !=
    0.0F));

  /* Switch: '<S75>/Switch2' incorporates:
   *  Constant: '<S164>/Constant'
   *  Constant: '<S165>/Constant'
   *  Constant: '<S171>/Constant'
   *  Constant: '<S173>/Constant'
   *  Constant: '<S174>/Constant'
   *  Constant: '<S75>/Constant4'
   *  Logic: '<S75>/Logical Operator10'
   *  RelationalOperator: '<S164>/Compare'
   *  RelationalOperator: '<S165>/Compare'
   *  RelationalOperator: '<S171>/Compare'
   *  RelationalOperator: '<S173>/Compare'
   *  RelationalOperator: '<S174>/Compare'
   *  Switch: '<S75>/Switch1'
   *  Switch: '<S75>/Switch7'
   */
  if (swctcoo_dtdc_b_whlDrgDemEhb_ovrdflg) {
    /* Switch: '<S75>/Switch2' incorporates:
     *  Constant: '<S75>/Constant5'
     */
    swctcoo_dtdd_tq_whlDrgDemEhb_Nm = swctcoo_dtdc_tq_whlDrgDemEhb_ovrdval;
  } else if ((swc_TCOO_ARID_DEF.DataTypeConversion192 == 0.0) ||
             (swc_TCOO_ARID_DEF.DataTypeConversion192 == 255.0) ||
             (swc_TCOO_ARID_DEF.DataTypeConversion193 == 0.0) ||
             (swc_TCOO_ARID_DEF.DataTypeConversion193 == 255.0) ||
             dtdd_b_rgnOffEna) {
    /* Switch: '<S75>/Switch7' incorporates:
     *  Constant: '<S75>/Constant13'
     *  Switch: '<S75>/Switch2'
     */
    swctcoo_dtdd_tq_whlDrgDemEhb_Nm = ((float32)TRQ_ZERO);
  } else if (swc_TCOO_ARID_DEF.Compare == true) {
    /* Switch: '<S75>/Switch1' incorporates:
     *  Switch: '<S75>/Switch2'
     *  Switch: '<S75>/Switch7'
     */
    swctcoo_dtdd_tq_whlDrgDemEhb_Nm = swc_TCOO_ARID_DEF.DataTypeConversion189;
  } else {
    /* Switch: '<S75>/Switch2' incorporates:
     *  Switch: '<S75>/Switch1'
     *  Switch: '<S75>/Switch7'
     */
    swctcoo_dtdd_tq_whlDrgDemEhb_Nm = dtdd_tq_whlEVBrakingDrag_Nm;
  }

  /* End of Switch: '<S75>/Switch2' */

  /* Switch: '<S75>/Switch5' incorporates:
   *  Constant: '<S163>/Constant'
   *  Constant: '<S75>/Constant3'
   *  Logic: '<S75>/Logical Operator3'
   *  RelationalOperator: '<S163>/Compare'
   */
  if ((swc_TCOO_ARID_DEF.Compare == true) && swctcoo_dtdc_b_useFctCfgEHB) {
    /* Switch: '<S75>/Switch5' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion4'
     *  Lookup_n-D: '<S75>/1-D Lookup Table1'
     */
    rtb_Switch3_h = look1_iflf_binlcapw(swc_TCOO_ARID_DEF.DataTypeConversion4, (
      const float32 *)&swctcoo_dtdf_brkTqMinMapEHB_X_VehSpd_kph[0], (const
      float32 *)&swctcoo_dtdf_brkTqMinMapEHB_Y_Nm[0], 11U);
  } else {
    /* Switch: '<S75>/Switch5' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion4'
     *  Lookup_n-D: '<S75>/1-D Lookup Table2'
     */
    rtb_Switch3_h = look1_iflf_binlcapw(swc_TCOO_ARID_DEF.DataTypeConversion4, (
      const float32 *)&swctcoo_dtdf_brkTqMinMap_X_VehSpd_kph[0], (const float32 *)
      &swctcoo_dtdf_brkTqMinMap_Y_Nm[0], 11U);
  }

  /* End of Switch: '<S75>/Switch5' */

  /* Switch: '<S75>/Switch9' incorporates:
   *  Constant: '<S168>/Constant'
   *  Constant: '<S169>/Constant'
   *  Logic: '<S75>/Logical Operator13'
   *  MinMax: '<S75>/MinMax1'
   *  RelationalOperator: '<S168>/Compare'
   *  RelationalOperator: '<S169>/Compare'
   *  Relay: '<S75>/Relay1'
   *  Switch: '<S75>/Switch8'
   */
  if ((swctcoo_tdad_st_adcCtrlSts == ((uint8)0U)) || (swctcoo_tdad_st_adcCtrlSts
       == ((uint8)1U))) {
    /* Relay: '<S75>/Relay1' */
    if (swc_TCOO_ARID_DEF.Relay1_Mode_f) {
      tmp = 1.0F;
    } else {
      tmp = 0.0F;
    }

    /* Switch: '<S75>/Switch3' incorporates:
     *  Constant: '<S75>/Constant2'
     *  Constant: '<S75>/Constant9'
     *  Logic: '<S75>/Logical Operator1'
     *  Logic: '<S75>/Logical Operator2'
     *  Relay: '<S75>/Relay1'
     */
    if (dtdd_b_rgnOffEna || (tcoo_dtdc_b_useAccPdlEhbWhlCstDrg && (tmp != 0.0F)))
    {
      tmp = ((float32)TRQ_ZERO);
    } else {
      tmp = dtdd_tq_whlEVCoastingDrag_Nm;
    }

    /* MinMax: '<S75>/MinMax6' incorporates:
     *  MinMax: '<S75>/MinMax5'
     *  Switch: '<S75>/Switch3'
     */
    rtb_brpd_p_brkPres_bar = fmaxf(swc_TCOO_ARID_DEF.DataTypeConversion95, tmp);
    tmp = swctcoo_dtdd_tq_whlDrgDemEhb_Nm;
  } else {
    if (swc_TCOO_ARID_DEF.Relay1_Mode_f) {
      /* Relay: '<S75>/Relay1' */
      tmp = 1.0F;
    } else {
      /* Relay: '<S75>/Relay1' */
      tmp = 0.0F;
    }

    /* Switch: '<S75>/Switch3' incorporates:
     *  Constant: '<S75>/Constant2'
     *  Constant: '<S75>/Constant9'
     *  Logic: '<S75>/Logical Operator1'
     *  Logic: '<S75>/Logical Operator2'
     *  Relay: '<S75>/Relay1'
     */
    if (dtdd_b_rgnOffEna || (tcoo_dtdc_b_useAccPdlEhbWhlCstDrg && (tmp != 0.0F)))
    {
      tmp = ((float32)TRQ_ZERO);
    } else {
      tmp = dtdd_tq_whlEVCoastingDrag_Nm;
    }

    /* MinMax: '<S75>/MinMax6' incorporates:
     *  MinMax: '<S75>/MinMax2'
     *  Switch: '<S75>/Switch3'
     */
    rtb_brpd_p_brkPres_bar = fmaxf(fmaxf(tmp, rtb_Switch3_h),
      swc_TCOO_ARID_DEF.DataTypeConversion95);
    tmp = fmaxf(swctcoo_dtdd_tq_whlDrgDemEhb_Nm, rtb_Switch3_h);
  }

  /* End of Switch: '<S75>/Switch9' */

  /* MinMax: '<S75>/MinMax3' incorporates:
   *  Constant: '<S75>/Constant8'
   */
  swctcoo_dtdd_tq_whlCoastDrgDem_Nm = fminf(((float32)TRQ_ZERO),
    rtb_brpd_p_brkPres_bar);

  /* MinMax: '<S75>/MinMax4' incorporates:
   *  Constant: '<S75>/Constant'
   *  Switch: '<S75>/Switch8'
   */
  dtdd_tq_whlDragDem_Nm = fminf(((float32)TRQ_ZERO), tmp);

  /* Switch: '<S75>/Switch4' incorporates:
   *  Constant: '<S75>/Constant7'
   *  Switch: '<S75>/Switch6'
   */
  if (dtdd_b_rgnOffEna) {
    /* MinMax: '<S75>/MinMax6' incorporates:
     *  Constant: '<S75>/Constant6'
     */
    rtb_brpd_p_brkPres_bar = ((float32)TRQ_ZERO);
  } else if (dtdc_b_useS2CstDrgTqOvrSpd) {
    /* MinMax: '<S75>/MinMax6' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion4'
     *  Lookup_n-D: '<S75>/1-D Lookup Table3'
     *  Switch: '<S75>/Switch6'
     */
    rtb_brpd_p_brkPres_bar = look1_iflf_binlcapw
      (swc_TCOO_ARID_DEF.DataTypeConversion4, (const float32 *)
       &dtda_trqDragDemEV_Y_VehSpd_kph[0], (const float32 *)
       &dtdm_trqDragDemEVOffs2_Z_Nm[0], 26U);
  } else {
    /* MinMax: '<S75>/MinMax6' incorporates:
     *  Switch: '<S75>/Switch6'
     */
    rtb_brpd_p_brkPres_bar = dtdd_tq_whlEVCoastingDrag_Nm;
  }

  /* End of Switch: '<S75>/Switch4' */

  /* MinMax: '<S75>/MinMax7' incorporates:
   *  Constant: '<S75>/Constant1'
   *  MinMax: '<S75>/MinMax6'
   */
  tcoo_dtdd_tq_whlCstDrgDemNoEhb_Nm = fminf(((float32)TRQ_ZERO), fmaxf(fmaxf
    (rtb_brpd_p_brkPres_bar, rtb_Switch3_h),
    swc_TCOO_ARID_DEF.DataTypeConversion95));

  /* Update for UnitDelay: '<S88>/Unit Delay2' */
  swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_k = rtb_Switch20;

  /* Update for UnitDelay: '<S88>/Unit Delay1' */
  swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_b = rtb_Switch2_k1;

  /* Update for UnitDelay: '<S162>/Delay Input1'
   *
   * Block description for '<S162>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_TCOO_ARID_DEF.DelayInput1_DSTATE = swc_TCOO_ARID_DEF.DataTypeConversion39;

  /* Update for UnitDelay: '<S161>/Delay Input1'
   *
   * Block description for '<S161>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_TCOO_ARID_DEF.DelayInput1_DSTATE_o =
    swc_TCOO_ARID_DEF.DataTypeConversion39;

  /* Update for UnitDelay: '<S118>/Delay Input1'
   *
   * Block description for '<S118>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_TCOO_ARID_DEF.DelayInput1_DSTATE_nh =
    swc_TCOO_ARID_DEF.DataTypeConversion6;

  /* Update for UnitDelay: '<S123>/Delay Input1'
   *
   * Block description for '<S123>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_TCOO_ARID_DEF.DelayInput1_DSTATE_n1 = drid_b_rgnOffGlobalEna;

  /* Update for UnitDelay: '<S117>/Delay Input1'
   *
   * Block description for '<S117>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_TCOO_ARID_DEF.DelayInput1_DSTATE_d =
    swc_TCOO_ARID_DEF.DataTypeConversion164;

  /* Update for UnitDelay: '<S120>/Delay Input1'
   *
   * Block description for '<S120>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_TCOO_ARID_DEF.DelayInput1_DSTATE_dr =
    swc_TCOO_ARID_DEF.DataTypeConversion6;

  /* Update for UnitDelay: '<S116>/Unit Delay2' */
  swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_d4 = dtdd_cnt_rgnOffCount;

  /* Update for UnitDelay: '<S119>/Delay Input1'
   *
   * Block description for '<S119>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_TCOO_ARID_DEF.DelayInput1_DSTATE_ie =
    swc_TCOO_ARID_DEF.DataTypeConversion164;

  /* Update for UnitDelay: '<S73>/Unit Delay2' */
  swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_eb = swctcoo_dtdd_st_SptMemRegenLvl;

  /* Update for UnitDelay: '<S86>/Unit Delay3' */
  swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_o =
    swc_TCOO_ARID_DEF.DataTypeConversion164;

  /* Update for UnitDelay: '<S94>/Unit Delay3' */
  swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_c = swctcoo_dtdd_st_sptRegenLvlFromEE;

  /* Update for UnitDelay: '<S94>/Unit Delay4' */
  swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_p = rtb_Switch6_a;

  /* Update for UnitDelay: '<S122>/Delay Input1'
   *
   * Block description for '<S122>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_TCOO_ARID_DEF.DelayInput1_DSTATE_iv = rtb_flg_out_d;

  /* Update for UnitDelay: '<S121>/Delay Input1'
   *
   * Block description for '<S121>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_TCOO_ARID_DEF.DelayInput1_DSTATE_hb = rtb_flg_out_n;

  /* Update for UnitDelay: '<S73>/Unit Delay1' */
  swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_n = dtdd_st_EcoMemRegenLvl;

  /* Update for UnitDelay: '<S86>/Unit Delay2' */
  swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_kd =
    swc_TCOO_ARID_DEF.DataTypeConversion164;

  /* Update for UnitDelay: '<S92>/Unit Delay3' */
  swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_p = dtdd_st_EcoRegenLvlFromEE;

  /* Update for UnitDelay: '<S92>/Unit Delay4' */
  swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_j = rtb_Switch6_e;

  /* Update for UnitDelay: '<S73>/Unit Delay' */
  swc_TCOO_ARID_DEF.UnitDelay_DSTATE_b = dtdd_st_NormMemRegenLvl;

  /* Update for UnitDelay: '<S86>/Unit Delay1' */
  swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_o =
    swc_TCOO_ARID_DEF.DataTypeConversion164;

  /* Update for UnitDelay: '<S93>/Unit Delay3' */
  swc_TCOO_ARID_DEF.UnitDelay3_DSTATE_h = dtdd_st_NormRegenLvlFromEE;

  /* Update for UnitDelay: '<S93>/Unit Delay4' */
  swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_pd = rtb_Switch6_p;
}

/*
 * Output and update for action system:
 *    '<S31>/Switch Case Action Subsystem1'
 *    '<S46>/Switch Case Action Subsystem1'
 *    '<S61>/Switch Case Action Subsystem1'
 */
static void swc__SwitchCaseActionSubsystem1(float32 rtu_AccPedPos, float32
  rtu_EngSpd, float32 *rty_TrqDemGearS2)
{
  /* Lookup_n-D: '<S38>/2-D Lookup Table1' */
  *rty_TrqDemGearS2 = look2_iflf_binlcapw(rtu_AccPedPos, rtu_EngSpd, (const
    float32 *)&apdm_trqDemGearS2_X_PedPos_pct[0], (const float32 *)
    &apda_trqDemGearS_Y_EngSpd_rpm[0], (const float32 *)&apdm_trqDemGearS2_Z_Nm
    [0], swc_TCOO_ConstP.pooled13, 11U);
}

/*
 * Output and update for action system:
 *    '<S29>/Switch Case Action Subsystem1'
 *    '<S30>/Switch Case Action Subsystem1'
 *    '<S44>/Switch Case Action Subsystem1'
 *    '<S45>/Switch Case Action Subsystem1'
 *    '<S59>/Switch Case Action Subsystem1'
 *    '<S60>/Switch Case Action Subsystem1'
 */
static void sw_SwitchCaseActionSubsystem1_p(float32 rtu_AccPedPos, float32
  rtu_EngSpd, float32 *rty_TrqDemGearD2)
{
  /* Lookup_n-D: '<S34>/2-D Lookup Table1' */
  *rty_TrqDemGearD2 = look2_iflf_binlcapw(rtu_AccPedPos, rtu_EngSpd, (const
    float32 *)&apdm_trqDemGearD2_X_PedPos_pct[0], (const float32 *)
    &apda_trqDemGearD_Y_EngSpd_rpm[0], (const float32 *)&apdm_trqDemGearD2_Z_Nm
    [0], swc_TCOO_ConstP.pooled13, 11U);
}

/* System initialize for function-call system: '<S1>/APD_DriverDemand' */
static void swc_TCOO_APD_DriverDemand_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S15>/init' */
  swc_TCOO_ARID_DEF.init_DSTATE = true;

  /* SystemInitialize for Merge: '<S23>/Merge' */
  swctcoo_apdd_tq_crsDemVehTyp2_Nm = 0.0F;

  /* SystemInitialize for Merge: '<S22>/Merge' */
  swctcoo_apdd_tq_crsDemVehTyp1_Nm = 0.0F;

  /* SystemInitialize for Merge: '<S21>/Merge' */
  apdd_tq_crsDem_Nm = 0.0F;
}

/* Output and update for function-call system: '<S1>/APD_DriverDemand' */
static void swc_TCOO_APD_DriverDemand(void)
{
  float32 rtb_Divide;
  float32 rtb_MinMax4;
  float32 rtb_Switch_h;
  DriveDir tmp_0;
  sint8 tmp;

  /* MultiPortSwitch: '<S13>/Multiport Switch1' */
  apdd_fact_trsmGearRat = swc_TCOO_ARID_DEF.DataTypeConversion13;

  /* Switch: '<S15>/Switch' incorporates:
   *  UnitDelay: '<S15>/init'
   */
  if (swc_TCOO_ARID_DEF.init_DSTATE) {
    /* DataTypeConversion: '<S15>/Data Type Conversion3' incorporates:
     *  Constant: '<S10>/Constant23'
     *  Constant: '<S16>/Constant'
     *  Constant: '<S17>/Constant'
     *  MinMax: '<S10>/MinMax1'
     *  MinMax: '<S11>/MinMax3'
     *  Product: '<S10>/Product1'
     *  Product: '<S10>/Product2'
     *  Product: '<S16>/Product'
     *  Product: '<S17>/Product'
     */
    apdd_n_engActSpdMdl_rpm = swc_TCOO_ARID_DEF.DataTypeConversion4 * ((float32)
      KPH_2_MPS) / fmaxf(swc_TCOO_ARID_DEF.DataTypeConversion29, 0.1F) *
      ((float32)RADpS_2_RPM) * apdd_fact_trsmGearRat;
  } else {
    /* Product: '<S15>/Divide' incorporates:
     *  Constant: '<S10>/Constant17'
     *  Constant: '<S10>/Constant4'
     *  DataTypeConversion: '<S15>/Data Type Conversion1'
     *  DataTypeConversion: '<S15>/Data Type Conversion2'
     *  Sum: '<S15>/Add1'
     */
    rtb_Divide = apdc_tm_engMdlActSpdFilter_s / (apdc_tm_engMdlActSpdFilter_s +
      ((float32)APD_TASK_INTERVAL_S));

    /* DataTypeConversion: '<S15>/Data Type Conversion3' incorporates:
     *  Constant: '<S10>/Constant23'
     *  Constant: '<S15>/Constant'
     *  Constant: '<S16>/Constant'
     *  Constant: '<S17>/Constant'
     *  MinMax: '<S10>/MinMax1'
     *  MinMax: '<S11>/MinMax3'
     *  Product: '<S10>/Product1'
     *  Product: '<S10>/Product2'
     *  Product: '<S15>/Product'
     *  Product: '<S15>/Product1'
     *  Product: '<S16>/Product'
     *  Product: '<S17>/Product'
     *  Sum: '<S15>/Add'
     *  Sum: '<S15>/Add2'
     *  UnitDelay: '<S15>/Unit Delay'
     */
    apdd_n_engActSpdMdl_rpm = swc_TCOO_ARID_DEF.DataTypeConversion4 * ((float32)
      KPH_2_MPS) / fmaxf(swc_TCOO_ARID_DEF.DataTypeConversion29, 0.1F) *
      ((float32)RADpS_2_RPM) * apdd_fact_trsmGearRat * (1.0F - rtb_Divide) +
      rtb_Divide * apdd_n_engActSpdMdl_rpm;
  }

  /* End of Switch: '<S15>/Switch' */

  /* Outputs for IfAction SubSystem: '<S21>/PedalMaps_Eco' incorporates:
   *  ActionPort: '<S29>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S29>/Switch Case Action Subsystem' incorporates:
   *  ActionPort: '<S33>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S21>/PedalMaps_GearD' incorporates:
   *  ActionPort: '<S30>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S30>/Switch Case Action Subsystem' incorporates:
   *  ActionPort: '<S35>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S21>/PedalMaps_Sport' incorporates:
   *  ActionPort: '<S31>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S31>/Switch Case Action Subsystem' incorporates:
   *  ActionPort: '<S37>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S22>/PedalMaps_Eco' incorporates:
   *  ActionPort: '<S44>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S44>/Switch Case Action Subsystem' incorporates:
   *  ActionPort: '<S48>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S22>/PedalMaps_GearD' incorporates:
   *  ActionPort: '<S45>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S45>/Switch Case Action Subsystem' incorporates:
   *  ActionPort: '<S50>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S21>/PedalMap_GearR' incorporates:
   *  ActionPort: '<S28>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S22>/PedalMaps_Sport' incorporates:
   *  ActionPort: '<S46>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S46>/Switch Case Action Subsystem' incorporates:
   *  ActionPort: '<S52>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S21>/PedalMap_GearN' incorporates:
   *  ActionPort: '<S27>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S23>/PedalMaps_Eco' incorporates:
   *  ActionPort: '<S59>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S59>/Switch Case Action Subsystem' incorporates:
   *  ActionPort: '<S63>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S23>/PedalMaps_GearD' incorporates:
   *  ActionPort: '<S60>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S60>/Switch Case Action Subsystem' incorporates:
   *  ActionPort: '<S65>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S22>/PedalMap_GearR' incorporates:
   *  ActionPort: '<S43>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S23>/PedalMaps_Sport' incorporates:
   *  ActionPort: '<S61>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S61>/Switch Case Action Subsystem' incorporates:
   *  ActionPort: '<S67>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S22>/PedalMap_GearN' incorporates:
   *  ActionPort: '<S42>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S23>/PedalMap_GearR' incorporates:
   *  ActionPort: '<S58>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S23>/PedalMap_GearN' incorporates:
   *  ActionPort: '<S57>/Action Port'
   */
  /* If: '<S21>/If' incorporates:
   *  If: '<S22>/If'
   *  If: '<S23>/If'
   *  Inport generated from: '<Root>/vcib_VCIP_in5'
   *  Lookup_n-D: '<S27>/2-D Lookup Table'
   *  Lookup_n-D: '<S28>/2-D Lookup Table'
   *  Lookup_n-D: '<S28>/2-D Lookup Table1'
   *  Lookup_n-D: '<S33>/2-D Lookup Table'
   *  Lookup_n-D: '<S35>/2-D Lookup Table'
   *  Lookup_n-D: '<S37>/2-D Lookup Table'
   *  Lookup_n-D: '<S42>/2-D Lookup Table'
   *  Lookup_n-D: '<S43>/2-D Lookup Table'
   *  Lookup_n-D: '<S43>/2-D Lookup Table1'
   *  Lookup_n-D: '<S48>/2-D Lookup Table'
   *  Lookup_n-D: '<S50>/2-D Lookup Table'
   *  Lookup_n-D: '<S52>/2-D Lookup Table'
   *  Lookup_n-D: '<S57>/2-D Lookup Table'
   *  Lookup_n-D: '<S58>/2-D Lookup Table'
   *  Lookup_n-D: '<S58>/2-D Lookup Table1'
   *  Lookup_n-D: '<S63>/2-D Lookup Table'
   *  Lookup_n-D: '<S65>/2-D Lookup Table'
   *  Lookup_n-D: '<S67>/2-D Lookup Table'
   *  Relay: '<S11>/Relay'
   *  Switch: '<S28>/Switch2'
   *  Switch: '<S43>/Switch2'
   *  Switch: '<S58>/Switch2'
   *  SwitchCase: '<S29>/Switch Case'
   *  SwitchCase: '<S30>/Switch Case'
   *  SwitchCase: '<S31>/Switch Case'
   *  SwitchCase: '<S44>/Switch Case'
   *  SwitchCase: '<S45>/Switch Case'
   *  SwitchCase: '<S46>/Switch Case'
   *  SwitchCase: '<S59>/Switch Case'
   *  SwitchCase: '<S60>/Switch Case'
   *  SwitchCase: '<S61>/Switch Case'
   */
  rtb_Divide = Rte_IRead_swc_TCOO_Step_vcib_VCIP_acpd_x_accPedlPos_pct();

  /* End of Outputs for SubSystem: '<S23>/PedalMap_GearN' */
  /* End of Outputs for SubSystem: '<S23>/PedalMap_GearR' */
  /* End of Outputs for SubSystem: '<S22>/PedalMap_GearN' */
  /* End of Outputs for SubSystem: '<S61>/Switch Case Action Subsystem' */
  /* End of Outputs for SubSystem: '<S23>/PedalMaps_Sport' */
  /* End of Outputs for SubSystem: '<S22>/PedalMap_GearR' */
  /* End of Outputs for SubSystem: '<S60>/Switch Case Action Subsystem' */
  /* End of Outputs for SubSystem: '<S23>/PedalMaps_GearD' */
  /* End of Outputs for SubSystem: '<S59>/Switch Case Action Subsystem' */
  /* End of Outputs for SubSystem: '<S23>/PedalMaps_Eco' */
  /* End of Outputs for SubSystem: '<S21>/PedalMap_GearN' */
  /* End of Outputs for SubSystem: '<S46>/Switch Case Action Subsystem' */
  /* End of Outputs for SubSystem: '<S22>/PedalMaps_Sport' */
  /* End of Outputs for SubSystem: '<S21>/PedalMap_GearR' */
  /* End of Outputs for SubSystem: '<S45>/Switch Case Action Subsystem' */
  /* End of Outputs for SubSystem: '<S22>/PedalMaps_GearD' */
  /* End of Outputs for SubSystem: '<S44>/Switch Case Action Subsystem' */
  /* End of Outputs for SubSystem: '<S22>/PedalMaps_Eco' */
  /* End of Outputs for SubSystem: '<S31>/Switch Case Action Subsystem' */
  /* End of Outputs for SubSystem: '<S21>/PedalMaps_Sport' */
  /* End of Outputs for SubSystem: '<S30>/Switch Case Action Subsystem' */
  /* End of Outputs for SubSystem: '<S21>/PedalMaps_GearD' */
  /* End of Outputs for SubSystem: '<S29>/Switch Case Action Subsystem' */
  /* End of Outputs for SubSystem: '<S21>/PedalMaps_Eco' */

  /* Relay: '<S11>/Relay' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in5'
   */
  swc_TCOO_ARID_DEF.Relay_Mode_o = ((rtb_Divide >=
    apdc_frac_pedalDeadBandHigh_pct) || ((rtb_Divide >
    apdc_frac_pedalDeadBandLow_pct) && swc_TCOO_ARID_DEF.Relay_Mode_o));

  /* Switch: '<S70>/Switch2' incorporates:
   *  Constant: '<S69>/apdc_b_trsmGearTgt_ovrdflg'
   */
  if (apdc_b_trsmGearTgt_ovrdflg) {
    /* Switch: '<S70>/Switch2' incorporates:
     *  Constant: '<S69>/apdc_st_trsmGearTgt_ovrdval'
     */
    apdd_st_trsmGearTgt = apdc_st_trsmGearTgt_ovrdval;
  } else {
    /* Switch: '<S70>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in13'
     *  MultiPortSwitch: '<S13>/Multiport Switch2'
     */
    apdd_st_trsmGearTgt = Rte_IRead_swc_TCOO_Step_vcib_VCIP_trad_st_trsm2GearAct
      ();
  }

  /* End of Switch: '<S70>/Switch2' */

  /* RelationalOperator: '<S23>/Relational Operator' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   *  RelationalOperator: '<S21>/Relational Operator'
   *  RelationalOperator: '<S21>/Relational Operator1'
   *  RelationalOperator: '<S22>/Relational Operator'
   *  RelationalOperator: '<S22>/Relational Operator1'
   *  RelationalOperator: '<S23>/Relational Operator1'
   */
  tmp_0 = swc_TCOO_ARID_DEF.DataTypeConversion7;

  /* If: '<S23>/If' incorporates:
   *  Constant: '<S23>/Constant17'
   *  Constant: '<S54>/Constant'
   *  Constant: '<S55>/Constant'
   *  Constant: '<S56>/Constant'
   *  Logic: '<S23>/Logical Operator1'
   *  Logic: '<S23>/Logical Operator2'
   *  Logic: '<S23>/Logical Operator3'
   *  RelationalOperator: '<S23>/Relational Operator'
   *  RelationalOperator: '<S23>/Relational Operator1'
   *  RelationalOperator: '<S54>/Compare'
   *  Saturate: '<S60>/Saturation'
   */
  if (tmp_0 == DriveDir_NO_DRIVE) {
    /* Outputs for IfAction SubSystem: '<S23>/PedalMap_GearN' incorporates:
     *  ActionPort: '<S57>/Action Port'
     */
    /* Merge: '<S23>/Merge' incorporates:
     *  DataTypeConversion: '<S15>/Data Type Conversion3'
     *  Lookup_n-D: '<S57>/2-D Lookup Table'
     */
    swctcoo_apdd_tq_crsDemVehTyp2_Nm = look2_iflf_binlcapw(rtb_Divide,
      apdd_n_engActSpdMdl_rpm, (const float32 *)&apdm_trqDemGearN_X_PedPos_pct[0],
      (const float32 *)&apdm_trqDemGearN_Y_EngSpd_rpm[0], (const float32 *)
      &swctcoo_apdm_trqDemGearNVehTyp2_Z_Nm[0], swc_TCOO_ConstP.pooled13, 11U);

    /* End of Outputs for SubSystem: '<S23>/PedalMap_GearN' */
  } else if (tmp_0 == DriveDir_REVERSE) {
    /* Outputs for IfAction SubSystem: '<S23>/PedalMap_GearR' incorporates:
     *  ActionPort: '<S58>/Action Port'
     */
    /* Switch: '<S58>/Switch2' incorporates:
     *  Constant: '<S62>/Constant'
     *  RelationalOperator: '<S62>/Compare'
     */
    if (swc_TCOO_ARID_DEF.DataTypeConversion176 == 1.0) {
      /* Merge: '<S23>/Merge' incorporates:
       *  DataTypeConversion: '<S15>/Data Type Conversion3'
       *  Lookup_n-D: '<S58>/2-D Lookup Table1'
       */
      swctcoo_apdd_tq_crsDemVehTyp2_Nm = look2_iflf_binlcapw(rtb_Divide,
        apdd_n_engActSpdMdl_rpm, (const float32 *)
        &apdm_trqDemGearR_X_PedPos_pct[0], (const float32 *)
        &apdm_trqDemGearR_Y_EngSpd_rpm[0], (const float32 *)
        &tcoo_apdm_trqDemGearRVehTyp2Tcs_Z_Nm[0], swc_TCOO_ConstP.pooled13, 11U);
    } else {
      /* Merge: '<S23>/Merge' incorporates:
       *  DataTypeConversion: '<S15>/Data Type Conversion3'
       *  Lookup_n-D: '<S58>/2-D Lookup Table'
       */
      swctcoo_apdd_tq_crsDemVehTyp2_Nm = look2_iflf_binlcapw(rtb_Divide,
        apdd_n_engActSpdMdl_rpm, (const float32 *)
        &apdm_trqDemGearR_X_PedPos_pct[0], (const float32 *)
        &apdm_trqDemGearR_Y_EngSpd_rpm[0], (const float32 *)
        &swctcoo_apdm_trqDemGearRVehTyp2_Z_Nm[0], swc_TCOO_ConstP.pooled13, 11U);
    }

    /* End of Outputs for SubSystem: '<S23>/PedalMap_GearR' */
  } else if ((swc_TCOO_ARID_DEF.DataTypeConversion170 == 1.0) &&
             (swc_TCOO_ARID_DEF.DataTypeConversion1 ||
              (swc_TCOO_ARID_DEF.DataTypeConversion160 &&
               apdc_b_useSportMapsIn4WDMode))) {
    /* Outputs for IfAction SubSystem: '<S23>/PedalMaps_Sport' incorporates:
     *  ActionPort: '<S61>/Action Port'
     */
    /* Saturate: '<S61>/Saturation' */
    if (apdd_st_trsmGearTgt > 8) {
      tmp = 8;
    } else if (apdd_st_trsmGearTgt < 1) {
      tmp = 1;
    } else {
      tmp = apdd_st_trsmGearTgt;
    }

    /* SwitchCase: '<S61>/Switch Case' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in5'
     *  Saturate: '<S61>/Saturation'
     */
    switch (tmp) {
     case 1:
      /* Outputs for IfAction SubSystem: '<S61>/Switch Case Action Subsystem' incorporates:
       *  ActionPort: '<S67>/Action Port'
       */
      /* Merge: '<S23>/Merge' incorporates:
       *  DataTypeConversion: '<S15>/Data Type Conversion3'
       *  Lookup_n-D: '<S67>/2-D Lookup Table'
       */
      swctcoo_apdd_tq_crsDemVehTyp2_Nm = look2_iflf_binlcapw(rtb_Divide,
        apdd_n_engActSpdMdl_rpm, (const float32 *)
        &apdm_trqDemGearS1_X_PedPos_pct[0], (const float32 *)
        &swctcoo_apda_trqDemGearSVehTyp2_Y_EngSpd_rpm[0], (const float32 *)
        &swctcoo_apdm_trqDemGearS1VehTyp2_Z_Nm[0], swc_TCOO_ConstP.pooled13, 11U);

      /* End of Outputs for SubSystem: '<S61>/Switch Case Action Subsystem' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S61>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S68>/Action Port'
       */
      swc__SwitchCaseActionSubsystem1
        (Rte_IRead_swc_TCOO_Step_vcib_VCIP_acpd_x_accPedlPos_pct(),
         apdd_n_engActSpdMdl_rpm, &swctcoo_apdd_tq_crsDemVehTyp2_Nm);

      /* End of Outputs for SubSystem: '<S61>/Switch Case Action Subsystem1' */
      break;
    }

    /* End of Outputs for SubSystem: '<S23>/PedalMaps_Sport' */
  } else if (swc_TCOO_ARID_DEF.DataTypeConversion6) {
    /* Outputs for IfAction SubSystem: '<S23>/PedalMaps_Eco' incorporates:
     *  ActionPort: '<S59>/Action Port'
     */
    /* Saturate: '<S59>/Saturation' */
    if (apdd_st_trsmGearTgt > 8) {
      tmp = 8;
    } else if (apdd_st_trsmGearTgt < 1) {
      tmp = 1;
    } else {
      tmp = apdd_st_trsmGearTgt;
    }

    /* SwitchCase: '<S59>/Switch Case' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in5'
     *  Saturate: '<S59>/Saturation'
     */
    switch (tmp) {
     case 1:
      /* Outputs for IfAction SubSystem: '<S59>/Switch Case Action Subsystem' incorporates:
       *  ActionPort: '<S63>/Action Port'
       */
      /* Merge: '<S23>/Merge' incorporates:
       *  DataTypeConversion: '<S15>/Data Type Conversion3'
       *  Lookup_n-D: '<S63>/2-D Lookup Table'
       */
      swctcoo_apdd_tq_crsDemVehTyp2_Nm = look2_iflf_binlcapw(rtb_Divide,
        apdd_n_engActSpdMdl_rpm, (const float32 *)
        &apdm_trqDemGearE1_X_PedPos_pct[0], (const float32 *)
        &swctcoo_apda_trqDemGearEVehTyp2_Y_EngSpd_rpm[0], (const float32 *)
        &swctcoo_apdm_trqDemGearE1VehTyp2_Z_Nm[0], swc_TCOO_ConstP.pooled13, 11U);

      /* End of Outputs for SubSystem: '<S59>/Switch Case Action Subsystem' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S59>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S64>/Action Port'
       */
      sw_SwitchCaseActionSubsystem1_p
        (Rte_IRead_swc_TCOO_Step_vcib_VCIP_acpd_x_accPedlPos_pct(),
         apdd_n_engActSpdMdl_rpm, &swctcoo_apdd_tq_crsDemVehTyp2_Nm);

      /* End of Outputs for SubSystem: '<S59>/Switch Case Action Subsystem1' */
      break;
    }

    /* End of Outputs for SubSystem: '<S23>/PedalMaps_Eco' */
  } else {
    /* Outputs for IfAction SubSystem: '<S23>/PedalMaps_GearD' incorporates:
     *  ActionPort: '<S60>/Action Port'
     */
    if (apdd_st_trsmGearTgt > 8) {
      /* Saturate: '<S60>/Saturation' */
      tmp = 8;
    } else if (apdd_st_trsmGearTgt < 1) {
      /* Saturate: '<S60>/Saturation' */
      tmp = 1;
    } else {
      /* Saturate: '<S60>/Saturation' */
      tmp = apdd_st_trsmGearTgt;
    }

    /* SwitchCase: '<S60>/Switch Case' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in5'
     *  Saturate: '<S60>/Saturation'
     */
    switch (tmp) {
     case 1:
      /* Outputs for IfAction SubSystem: '<S60>/Switch Case Action Subsystem' incorporates:
       *  ActionPort: '<S65>/Action Port'
       */
      /* Merge: '<S23>/Merge' incorporates:
       *  DataTypeConversion: '<S15>/Data Type Conversion3'
       *  Lookup_n-D: '<S65>/2-D Lookup Table'
       */
      swctcoo_apdd_tq_crsDemVehTyp2_Nm = look2_iflf_binlcapw(rtb_Divide,
        apdd_n_engActSpdMdl_rpm, (const float32 *)
        &apdm_trqDemGearD1_X_PedPos_pct[0], (const float32 *)
        &swctcoo_apda_trqDemGearDVehTyp2_Y_EngSpd_rpm[0], (const float32 *)
        &swctcoo_apdm_trqDemGearD1VehTyp2_Z_Nm[0], swc_TCOO_ConstP.pooled13, 11U);

      /* End of Outputs for SubSystem: '<S60>/Switch Case Action Subsystem' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S60>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S66>/Action Port'
       */
      sw_SwitchCaseActionSubsystem1_p
        (Rte_IRead_swc_TCOO_Step_vcib_VCIP_acpd_x_accPedlPos_pct(),
         apdd_n_engActSpdMdl_rpm, &swctcoo_apdd_tq_crsDemVehTyp2_Nm);

      /* End of Outputs for SubSystem: '<S60>/Switch Case Action Subsystem1' */
      break;
    }

    /* End of Outputs for SubSystem: '<S23>/PedalMaps_GearD' */
  }

  /* Product: '<S23>/Product' */
  swctcoo_apdd_tq_whlDrvrDemVehTyp2_Nm = swctcoo_apdd_tq_crsDemVehTyp2_Nm *
    apdd_fact_trsmGearRat;

  /* If: '<S22>/If' incorporates:
   *  Constant: '<S22>/Constant17'
   *  Constant: '<S39>/Constant'
   *  Constant: '<S40>/Constant'
   *  Constant: '<S56>/Constant'
   *  Logic: '<S22>/Logical Operator1'
   *  Logic: '<S22>/Logical Operator2'
   *  Logic: '<S22>/Logical Operator3'
   *  RelationalOperator: '<S22>/Relational Operator'
   *  RelationalOperator: '<S22>/Relational Operator1'
   *  RelationalOperator: '<S23>/Relational Operator'
   *  RelationalOperator: '<S39>/Compare'
   *  Saturate: '<S45>/Saturation'
   */
  if (tmp_0 == DriveDir_NO_DRIVE) {
    /* Outputs for IfAction SubSystem: '<S22>/PedalMap_GearN' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    /* Merge: '<S22>/Merge' incorporates:
     *  DataTypeConversion: '<S15>/Data Type Conversion3'
     *  Lookup_n-D: '<S42>/2-D Lookup Table'
     */
    swctcoo_apdd_tq_crsDemVehTyp1_Nm = look2_iflf_binlcapw(rtb_Divide,
      apdd_n_engActSpdMdl_rpm, (const float32 *)&apdm_trqDemGearN_X_PedPos_pct[0],
      (const float32 *)&apdm_trqDemGearN_Y_EngSpd_rpm[0], (const float32 *)
      &swctcoo_apdm_trqDemGearNVehTyp1_Z_Nm[0], swc_TCOO_ConstP.pooled13, 11U);

    /* End of Outputs for SubSystem: '<S22>/PedalMap_GearN' */
  } else if (tmp_0 == DriveDir_REVERSE) {
    /* Outputs for IfAction SubSystem: '<S22>/PedalMap_GearR' incorporates:
     *  ActionPort: '<S43>/Action Port'
     */
    /* Switch: '<S43>/Switch2' incorporates:
     *  Constant: '<S47>/Constant'
     *  RelationalOperator: '<S47>/Compare'
     */
    if (swc_TCOO_ARID_DEF.DataTypeConversion176 == 1.0) {
      /* Merge: '<S22>/Merge' incorporates:
       *  DataTypeConversion: '<S15>/Data Type Conversion3'
       *  Lookup_n-D: '<S43>/2-D Lookup Table1'
       */
      swctcoo_apdd_tq_crsDemVehTyp1_Nm = look2_iflf_binlcapw(rtb_Divide,
        apdd_n_engActSpdMdl_rpm, (const float32 *)
        &apdm_trqDemGearR_X_PedPos_pct[0], (const float32 *)
        &apdm_trqDemGearR_Y_EngSpd_rpm[0], (const float32 *)
        &tcoo_apdm_trqDemGearRVehTyp1Tcs_Z_Nm[0], swc_TCOO_ConstP.pooled13, 11U);
    } else {
      /* Merge: '<S22>/Merge' incorporates:
       *  DataTypeConversion: '<S15>/Data Type Conversion3'
       *  Lookup_n-D: '<S43>/2-D Lookup Table'
       */
      swctcoo_apdd_tq_crsDemVehTyp1_Nm = look2_iflf_binlcapw(rtb_Divide,
        apdd_n_engActSpdMdl_rpm, (const float32 *)
        &apdm_trqDemGearR_X_PedPos_pct[0], (const float32 *)
        &apdm_trqDemGearR_Y_EngSpd_rpm[0], (const float32 *)
        &swctcoo_apdm_trqDemGearRVehTyp1_Z_Nm[0], swc_TCOO_ConstP.pooled13, 11U);
    }

    /* End of Outputs for SubSystem: '<S22>/PedalMap_GearR' */
  } else if ((swc_TCOO_ARID_DEF.DataTypeConversion170 == 1.0) &&
             (swc_TCOO_ARID_DEF.DataTypeConversion1 ||
              (swc_TCOO_ARID_DEF.DataTypeConversion160 &&
               apdc_b_useSportMapsIn4WDMode))) {
    /* Outputs for IfAction SubSystem: '<S22>/PedalMaps_Sport' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    /* Saturate: '<S46>/Saturation' */
    if (apdd_st_trsmGearTgt > 8) {
      tmp = 8;
    } else if (apdd_st_trsmGearTgt < 1) {
      tmp = 1;
    } else {
      tmp = apdd_st_trsmGearTgt;
    }

    /* SwitchCase: '<S46>/Switch Case' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in5'
     *  Saturate: '<S46>/Saturation'
     */
    switch (tmp) {
     case 1:
      /* Outputs for IfAction SubSystem: '<S46>/Switch Case Action Subsystem' incorporates:
       *  ActionPort: '<S52>/Action Port'
       */
      /* Merge: '<S22>/Merge' incorporates:
       *  DataTypeConversion: '<S15>/Data Type Conversion3'
       *  Lookup_n-D: '<S52>/2-D Lookup Table'
       */
      swctcoo_apdd_tq_crsDemVehTyp1_Nm = look2_iflf_binlcapw(rtb_Divide,
        apdd_n_engActSpdMdl_rpm, (const float32 *)
        &apdm_trqDemGearS1_X_PedPos_pct[0], (const float32 *)
        &swctcoo_apda_trqDemGearSVehTyp1_Y_EngSpd_rpm[0], (const float32 *)
        &swctcoo_apdm_trqDemGearS1VehTyp1_Z_Nm[0], swc_TCOO_ConstP.pooled13, 11U);

      /* End of Outputs for SubSystem: '<S46>/Switch Case Action Subsystem' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S46>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S53>/Action Port'
       */
      swc__SwitchCaseActionSubsystem1
        (Rte_IRead_swc_TCOO_Step_vcib_VCIP_acpd_x_accPedlPos_pct(),
         apdd_n_engActSpdMdl_rpm, &swctcoo_apdd_tq_crsDemVehTyp1_Nm);

      /* End of Outputs for SubSystem: '<S46>/Switch Case Action Subsystem1' */
      break;
    }

    /* End of Outputs for SubSystem: '<S22>/PedalMaps_Sport' */
  } else if (swc_TCOO_ARID_DEF.DataTypeConversion6) {
    /* Outputs for IfAction SubSystem: '<S22>/PedalMaps_Eco' incorporates:
     *  ActionPort: '<S44>/Action Port'
     */
    /* Saturate: '<S44>/Saturation' */
    if (apdd_st_trsmGearTgt > 8) {
      tmp = 8;
    } else if (apdd_st_trsmGearTgt < 1) {
      tmp = 1;
    } else {
      tmp = apdd_st_trsmGearTgt;
    }

    /* SwitchCase: '<S44>/Switch Case' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in5'
     *  Saturate: '<S44>/Saturation'
     */
    switch (tmp) {
     case 1:
      /* Outputs for IfAction SubSystem: '<S44>/Switch Case Action Subsystem' incorporates:
       *  ActionPort: '<S48>/Action Port'
       */
      /* Merge: '<S22>/Merge' incorporates:
       *  DataTypeConversion: '<S15>/Data Type Conversion3'
       *  Lookup_n-D: '<S48>/2-D Lookup Table'
       */
      swctcoo_apdd_tq_crsDemVehTyp1_Nm = look2_iflf_binlcapw(rtb_Divide,
        apdd_n_engActSpdMdl_rpm, (const float32 *)
        &apdm_trqDemGearE1_X_PedPos_pct[0], (const float32 *)
        &swctcoo_apda_trqDemGearEVehTyp1_Y_EngSpd_rpm[0], (const float32 *)
        &swctcoo_apdm_trqDemGearE1VehTyp1_Z_Nm[0], swc_TCOO_ConstP.pooled13, 11U);

      /* End of Outputs for SubSystem: '<S44>/Switch Case Action Subsystem' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S44>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S49>/Action Port'
       */
      sw_SwitchCaseActionSubsystem1_p
        (Rte_IRead_swc_TCOO_Step_vcib_VCIP_acpd_x_accPedlPos_pct(),
         apdd_n_engActSpdMdl_rpm, &swctcoo_apdd_tq_crsDemVehTyp1_Nm);

      /* End of Outputs for SubSystem: '<S44>/Switch Case Action Subsystem1' */
      break;
    }

    /* End of Outputs for SubSystem: '<S22>/PedalMaps_Eco' */
  } else {
    /* Outputs for IfAction SubSystem: '<S22>/PedalMaps_GearD' incorporates:
     *  ActionPort: '<S45>/Action Port'
     */
    if (apdd_st_trsmGearTgt > 8) {
      /* Saturate: '<S45>/Saturation' */
      tmp = 8;
    } else if (apdd_st_trsmGearTgt < 1) {
      /* Saturate: '<S45>/Saturation' */
      tmp = 1;
    } else {
      /* Saturate: '<S45>/Saturation' */
      tmp = apdd_st_trsmGearTgt;
    }

    /* SwitchCase: '<S45>/Switch Case' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in5'
     *  Saturate: '<S45>/Saturation'
     */
    switch (tmp) {
     case 1:
      /* Outputs for IfAction SubSystem: '<S45>/Switch Case Action Subsystem' incorporates:
       *  ActionPort: '<S50>/Action Port'
       */
      /* Merge: '<S22>/Merge' incorporates:
       *  DataTypeConversion: '<S15>/Data Type Conversion3'
       *  Lookup_n-D: '<S50>/2-D Lookup Table'
       */
      swctcoo_apdd_tq_crsDemVehTyp1_Nm = look2_iflf_binlcapw(rtb_Divide,
        apdd_n_engActSpdMdl_rpm, (const float32 *)
        &apdm_trqDemGearD1_X_PedPos_pct[0], (const float32 *)
        &swctcoo_apda_trqDemGearDVehTyp1_Y_EngSpd_rpm[0], (const float32 *)
        &swctcoo_apdm_trqDemGearD1VehTyp1_Z_Nm[0], swc_TCOO_ConstP.pooled13, 11U);

      /* End of Outputs for SubSystem: '<S45>/Switch Case Action Subsystem' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S45>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S51>/Action Port'
       */
      sw_SwitchCaseActionSubsystem1_p
        (Rte_IRead_swc_TCOO_Step_vcib_VCIP_acpd_x_accPedlPos_pct(),
         apdd_n_engActSpdMdl_rpm, &swctcoo_apdd_tq_crsDemVehTyp1_Nm);

      /* End of Outputs for SubSystem: '<S45>/Switch Case Action Subsystem1' */
      break;
    }

    /* End of Outputs for SubSystem: '<S22>/PedalMaps_GearD' */
  }

  /* Product: '<S22>/Product' */
  swctcoo_apdd_tq_whlDrvrDemVehTyp1_Nm = swctcoo_apdd_tq_crsDemVehTyp1_Nm *
    apdd_fact_trsmGearRat;

  /* If: '<S21>/If' incorporates:
   *  Constant: '<S21>/Constant17'
   *  Constant: '<S24>/Constant'
   *  Constant: '<S25>/Constant'
   *  Constant: '<S56>/Constant'
   *  Logic: '<S21>/Logical Operator1'
   *  Logic: '<S21>/Logical Operator2'
   *  Logic: '<S21>/Logical Operator3'
   *  RelationalOperator: '<S21>/Relational Operator'
   *  RelationalOperator: '<S21>/Relational Operator1'
   *  RelationalOperator: '<S23>/Relational Operator'
   *  RelationalOperator: '<S24>/Compare'
   *  Saturate: '<S30>/Saturation'
   */
  if (tmp_0 == DriveDir_NO_DRIVE) {
    /* Outputs for IfAction SubSystem: '<S21>/PedalMap_GearN' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    /* Merge: '<S21>/Merge' incorporates:
     *  DataTypeConversion: '<S15>/Data Type Conversion3'
     *  Lookup_n-D: '<S27>/2-D Lookup Table'
     */
    apdd_tq_crsDem_Nm = look2_iflf_binlcapw(rtb_Divide, apdd_n_engActSpdMdl_rpm,
      (const float32 *)&apdm_trqDemGearN_X_PedPos_pct[0], (const float32 *)
      &apdm_trqDemGearN_Y_EngSpd_rpm[0], (const float32 *)
      &apdm_trqDemGearN_Z_Nm[0], swc_TCOO_ConstP.pooled13, 11U);

    /* End of Outputs for SubSystem: '<S21>/PedalMap_GearN' */
  } else if (tmp_0 == DriveDir_REVERSE) {
    /* Outputs for IfAction SubSystem: '<S21>/PedalMap_GearR' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    /* Switch: '<S28>/Switch2' incorporates:
     *  Constant: '<S32>/Constant'
     *  RelationalOperator: '<S32>/Compare'
     */
    if (swc_TCOO_ARID_DEF.DataTypeConversion176 == 1.0) {
      /* Merge: '<S21>/Merge' incorporates:
       *  DataTypeConversion: '<S15>/Data Type Conversion3'
       *  Lookup_n-D: '<S28>/2-D Lookup Table1'
       */
      apdd_tq_crsDem_Nm = look2_iflf_binlcapw(rtb_Divide,
        apdd_n_engActSpdMdl_rpm, (const float32 *)
        &apdm_trqDemGearR_X_PedPos_pct[0], (const float32 *)
        &apdm_trqDemGearR_Y_EngSpd_rpm[0], (const float32 *)
        &tcoo_apdm_trqDemGearRTcs_Z_Nm[0], swc_TCOO_ConstP.pooled13, 11U);
    } else {
      /* Merge: '<S21>/Merge' incorporates:
       *  DataTypeConversion: '<S15>/Data Type Conversion3'
       *  Lookup_n-D: '<S28>/2-D Lookup Table'
       */
      apdd_tq_crsDem_Nm = look2_iflf_binlcapw(rtb_Divide,
        apdd_n_engActSpdMdl_rpm, (const float32 *)
        &apdm_trqDemGearR_X_PedPos_pct[0], (const float32 *)
        &apdm_trqDemGearR_Y_EngSpd_rpm[0], (const float32 *)
        &apdm_trqDemGearR_Z_Nm[0], swc_TCOO_ConstP.pooled13, 11U);
    }

    /* End of Outputs for SubSystem: '<S21>/PedalMap_GearR' */
  } else if ((swc_TCOO_ARID_DEF.DataTypeConversion170 == 1.0) &&
             (swc_TCOO_ARID_DEF.DataTypeConversion1 ||
              (swc_TCOO_ARID_DEF.DataTypeConversion160 &&
               apdc_b_useSportMapsIn4WDMode))) {
    /* Outputs for IfAction SubSystem: '<S21>/PedalMaps_Sport' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    /* Saturate: '<S31>/Saturation' */
    if (apdd_st_trsmGearTgt > 8) {
      tmp = 8;
    } else if (apdd_st_trsmGearTgt < 1) {
      tmp = 1;
    } else {
      tmp = apdd_st_trsmGearTgt;
    }

    /* SwitchCase: '<S31>/Switch Case' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in5'
     *  Saturate: '<S31>/Saturation'
     */
    switch (tmp) {
     case 1:
      /* Outputs for IfAction SubSystem: '<S31>/Switch Case Action Subsystem' incorporates:
       *  ActionPort: '<S37>/Action Port'
       */
      /* Merge: '<S21>/Merge' incorporates:
       *  DataTypeConversion: '<S15>/Data Type Conversion3'
       *  Lookup_n-D: '<S37>/2-D Lookup Table'
       */
      apdd_tq_crsDem_Nm = look2_iflf_binlcapw(rtb_Divide,
        apdd_n_engActSpdMdl_rpm, (const float32 *)
        &apdm_trqDemGearS1_X_PedPos_pct[0], (const float32 *)
        &apda_trqDemGearS_Y_EngSpd_rpm[0], (const float32 *)
        &apdm_trqDemGearS1_Z_Nm[0], swc_TCOO_ConstP.pooled13, 11U);

      /* End of Outputs for SubSystem: '<S31>/Switch Case Action Subsystem' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S31>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S38>/Action Port'
       */
      swc__SwitchCaseActionSubsystem1
        (Rte_IRead_swc_TCOO_Step_vcib_VCIP_acpd_x_accPedlPos_pct(),
         apdd_n_engActSpdMdl_rpm, &apdd_tq_crsDem_Nm);

      /* End of Outputs for SubSystem: '<S31>/Switch Case Action Subsystem1' */
      break;
    }

    /* End of Outputs for SubSystem: '<S21>/PedalMaps_Sport' */
  } else if (swc_TCOO_ARID_DEF.DataTypeConversion6) {
    /* Outputs for IfAction SubSystem: '<S21>/PedalMaps_Eco' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    /* Saturate: '<S29>/Saturation' */
    if (apdd_st_trsmGearTgt > 8) {
      tmp = 8;
    } else if (apdd_st_trsmGearTgt < 1) {
      tmp = 1;
    } else {
      tmp = apdd_st_trsmGearTgt;
    }

    /* SwitchCase: '<S29>/Switch Case' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in5'
     *  Saturate: '<S29>/Saturation'
     */
    switch (tmp) {
     case 1:
      /* Outputs for IfAction SubSystem: '<S29>/Switch Case Action Subsystem' incorporates:
       *  ActionPort: '<S33>/Action Port'
       */
      /* Merge: '<S21>/Merge' incorporates:
       *  DataTypeConversion: '<S15>/Data Type Conversion3'
       *  Lookup_n-D: '<S33>/2-D Lookup Table'
       */
      apdd_tq_crsDem_Nm = look2_iflf_binlcapw(rtb_Divide,
        apdd_n_engActSpdMdl_rpm, (const float32 *)
        &apdm_trqDemGearE1_X_PedPos_pct[0], (const float32 *)
        &apda_trqDemGearE_Y_EngSpd_rpm[0], (const float32 *)
        &apdm_trqDemGearE1_Z_Nm[0], swc_TCOO_ConstP.pooled13, 11U);

      /* End of Outputs for SubSystem: '<S29>/Switch Case Action Subsystem' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S29>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S34>/Action Port'
       */
      sw_SwitchCaseActionSubsystem1_p
        (Rte_IRead_swc_TCOO_Step_vcib_VCIP_acpd_x_accPedlPos_pct(),
         apdd_n_engActSpdMdl_rpm, &apdd_tq_crsDem_Nm);

      /* End of Outputs for SubSystem: '<S29>/Switch Case Action Subsystem1' */
      break;
    }

    /* End of Outputs for SubSystem: '<S21>/PedalMaps_Eco' */
  } else {
    /* Outputs for IfAction SubSystem: '<S21>/PedalMaps_GearD' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    if (apdd_st_trsmGearTgt > 8) {
      /* Saturate: '<S30>/Saturation' */
      tmp = 8;
    } else if (apdd_st_trsmGearTgt < 1) {
      /* Saturate: '<S30>/Saturation' */
      tmp = 1;
    } else {
      /* Saturate: '<S30>/Saturation' */
      tmp = apdd_st_trsmGearTgt;
    }

    /* SwitchCase: '<S30>/Switch Case' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in5'
     *  Saturate: '<S30>/Saturation'
     */
    switch (tmp) {
     case 1:
      /* Outputs for IfAction SubSystem: '<S30>/Switch Case Action Subsystem' incorporates:
       *  ActionPort: '<S35>/Action Port'
       */
      /* Merge: '<S21>/Merge' incorporates:
       *  DataTypeConversion: '<S15>/Data Type Conversion3'
       *  Lookup_n-D: '<S35>/2-D Lookup Table'
       */
      apdd_tq_crsDem_Nm = look2_iflf_binlcapw(rtb_Divide,
        apdd_n_engActSpdMdl_rpm, (const float32 *)
        &apdm_trqDemGearD1_X_PedPos_pct[0], (const float32 *)
        &apda_trqDemGearD_Y_EngSpd_rpm[0], (const float32 *)
        &apdm_trqDemGearD1_Z_Nm[0], swc_TCOO_ConstP.pooled13, 11U);

      /* End of Outputs for SubSystem: '<S30>/Switch Case Action Subsystem' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S30>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S36>/Action Port'
       */
      sw_SwitchCaseActionSubsystem1_p
        (Rte_IRead_swc_TCOO_Step_vcib_VCIP_acpd_x_accPedlPos_pct(),
         apdd_n_engActSpdMdl_rpm, &apdd_tq_crsDem_Nm);

      /* End of Outputs for SubSystem: '<S30>/Switch Case Action Subsystem1' */
      break;
    }

    /* End of Outputs for SubSystem: '<S21>/PedalMaps_GearD' */
  }

  /* Product: '<S21>/Product' */
  apdd_tq_whlDrvrDem_Nm = apdd_tq_crsDem_Nm * apdd_fact_trsmGearRat;

  /* Switch: '<S12>/Switch3' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S12>/Constant12'
   *  Constant: '<S19>/Constant'
   *  Constant: '<S20>/Constant'
   *  Logic: '<S12>/Logical Operator1'
   *  Logic: '<S12>/Logical Operator13'
   *  RelationalOperator: '<S19>/Compare'
   *  RelationalOperator: '<S20>/Compare'
   *  Switch: '<S12>/Switch1'
   */
  if ((swc_TCOO_ARID_DEF.DataTypeConversion197 == 2.0) &&
      tcoo_apdc_b_useFctCfgMotor) {
    /* Switch: '<S12>/Switch3' */
    swctcoo_apdd_tq_whlDrvrDem_Nm = swctcoo_apdd_tq_whlDrvrDemVehTyp2_Nm;
  } else if ((swc_TCOO_ARID_DEF.DataTypeConversion197 == 1.0) &&
             tcoo_apdc_b_useFctCfgMotor) {
    /* Switch: '<S12>/Switch1' incorporates:
     *  Switch: '<S12>/Switch3'
     */
    swctcoo_apdd_tq_whlDrvrDem_Nm = swctcoo_apdd_tq_whlDrvrDemVehTyp1_Nm;
  } else {
    /* Switch: '<S12>/Switch3' incorporates:
     *  Switch: '<S12>/Switch1'
     */
    swctcoo_apdd_tq_whlDrvrDem_Nm = apdd_tq_whlDrvrDem_Nm;
  }

  /* End of Switch: '<S12>/Switch3' */

  /* MinMax: '<S11>/MinMax3' incorporates:
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S11>/Constant16'
   */
  rtb_Divide = fminf(((float32)WHL_TRQ_MIN), ((float32)TRQ_ZERO));

  /* MinMax: '<S11>/MinMax4' incorporates:
   *  Constant: '<S11>/Constant2'
   *  Constant: '<S11>/Constant3'
   */
  rtb_MinMax4 = fmaxf(((float32)TRQ_ZERO), ((float32)WHL_TRQ_MAX));

  /* Relay: '<S11>/Relay' */
  if (swc_TCOO_ARID_DEF.Relay_Mode_o) {
    rtb_Switch_h = 1.0F;
  } else {
    rtb_Switch_h = 0.0F;
  }

  /* Switch: '<S11>/Switch' incorporates:
   *  Logic: '<S11>/Logical Operator1'
   *  Logic: '<S11>/Logical Operator2'
   *  Relay: '<S11>/Relay'
   */
  if ((!swctcoo_dtdd_b_ehbMbRgnOvrCtl) && (rtb_Switch_h != 0.0F)) {
    /* Switch: '<S11>/Switch' incorporates:
     *  MinMax: '<S11>/MinMax'
     */
    rtb_Switch_h = fmaxf(swctcoo_apdd_tq_whlDrvrDem_Nm, dtdd_tq_whlDragDem_Nm);
  } else {
    /* Switch: '<S11>/Switch' */
    rtb_Switch_h = dtdd_tq_whlDragDem_Nm;
  }

  /* End of Switch: '<S11>/Switch' */

  /* Switch: '<S18>/Switch2' incorporates:
   *  RelationalOperator: '<S18>/LowerRelop1'
   *  RelationalOperator: '<S18>/UpperRelop'
   *  Switch: '<S18>/Switch'
   */
  if (rtb_Switch_h > rtb_MinMax4) {
    /* Switch: '<S18>/Switch2' */
    apdd_tq_whlDem_Nm = rtb_MinMax4;
  } else if (rtb_Switch_h < rtb_Divide) {
    /* Switch: '<S18>/Switch' incorporates:
     *  Switch: '<S18>/Switch2'
     */
    apdd_tq_whlDem_Nm = rtb_Divide;
  } else {
    /* Switch: '<S18>/Switch2' incorporates:
     *  Switch: '<S18>/Switch'
     */
    apdd_tq_whlDem_Nm = rtb_Switch_h;
  }

  /* End of Switch: '<S18>/Switch2' */

  /* Update for UnitDelay: '<S15>/init' incorporates:
   *  Constant: '<S15>/Constant1'
   */
  swc_TCOO_ARID_DEF.init_DSTATE = false;
}

/*
 * Output and update for action system:
 *    '<S249>/pos'
 *    '<S252>/pos'
 *    '<S253>/pos'
 */
static void swc_TCOO_pos(float32 rtu_in_val, float32 *rty_same_val)
{
  /* SignalConversion generated from: '<S251>/in_val' */
  *rty_same_val = rtu_in_val;
}

/*
 * Output and update for action system:
 *    '<S249>/neg'
 *    '<S252>/neg'
 *    '<S253>/neg'
 */
static void swc_TCOO_neg(float32 rtu_in_val, float32 *rty_neg_val)
{
  /* UnaryMinus: '<S250>/Unary Minus' */
  *rty_neg_val = -rtu_in_val;
}

/* System initialize for function-call system: '<S1>/TDA_TorqueDemandsArbitration' */
static void TDA_TorqueDemandsArbitrati_Init(void)
{
  /* local block i/o variables */
  boolean rtb_flg_out_j;
  boolean rtb_flg_out_a0;
  boolean rtb_flg_out_mk;
  boolean rtb_flg_out_cn;

  /* SystemInitialize for Atomic SubSystem: '<S316>/turnON_delay2' */
  swc_TCOO_turnON_delay_Init(&rtb_flg_out_mk);

  /* End of SystemInitialize for SubSystem: '<S316>/turnON_delay2' */

  /* SystemInitialize for Atomic SubSystem: '<S316>/turnON_delay1' */
  swc_TCOO_turnON_delay_Init(&rtb_flg_out_cn);

  /* End of SystemInitialize for SubSystem: '<S316>/turnON_delay1' */

  /* SystemInitialize for Atomic SubSystem: '<S316>/turnON_delay4' */
  swc_TCOO_turnON_delay_Init(&rtb_flg_out_j);

  /* End of SystemInitialize for SubSystem: '<S316>/turnON_delay4' */

  /* SystemInitialize for Atomic SubSystem: '<S316>/turnON_delay3' */
  swc_TCOO_turnON_delay_Init(&rtb_flg_out_a0);

  /* End of SystemInitialize for SubSystem: '<S316>/turnON_delay3' */

  /* SystemInitialize for Merge: '<S268>/Merge' */
  tdad_tm_tauFilt1st_s = 0.01F;

  /* SystemInitialize for Enabled SubSystem: '<S226>/Filter' */
  /* InitializeConditions for UnitDelay: '<S239>/Unit Delay' */
  swc_TCOO_ARID_DEF.UnitDelay_DSTATE_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S226>/Filter' */

  /* SystemInitialize for Merge: '<S269>/Merge' */
  tdad_tm_tauFiltPar_s = 0.01F;

  /* SystemInitialize for Enabled SubSystem: '<S270>/Power_Pos' */
  /* SystemInitialize for Merge: '<S309>/Merge' */
  tdad_tm_tauFilt2nd_s = 0.01F;

  /* SystemInitialize for Merge: '<S309>/Merge1' */
  tdad_fact_dampFilt2nd = 1.0F;

  /* End of SystemInitialize for SubSystem: '<S270>/Power_Pos' */

  /* SystemInitialize for Enabled SubSystem: '<S228>/Filter' */
  /* InitializeConditions for UnitDelay: '<S261>/Unit Delay' */
  swc_TCOO_ARID_DEF.UnitDelay_DSTATE_n = 0.0F;

  /* InitializeConditions for UnitDelay: '<S262>/Unit Delay' */
  swc_TCOO_ARID_DEF.UnitDelay_DSTATE_l = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S228>/Filter' */
}

/* Output and update for function-call system: '<S1>/TDA_TorqueDemandsArbitration' */
static void sw_TDA_TorqueDemandsArbitration(void)
{
  /* local block i/o variables */
  float32 rtb_Sum1_e;
  float32 rtb_Sum1_b;
  float32 rtb_Sum2_c;
  float32 rtb_Merge;
  float32 rtb_Merge_d;
  boolean rtb_RelationalOperator_h;
  boolean rtb_LogicalOperator7_n;
  boolean rtb_RelationalOperator2_b;
  boolean rtb_LogicalOperator9_h;
  boolean rtb_RelationalOperator3_n;
  boolean rtb_RelationalOperator1_hu;
  boolean rtb_LogicalOperator3_c;
  boolean rtb_LogicalOperator1_p;
  boolean rtb_flg_out_j;
  boolean rtb_flg_out_a0;
  boolean rtb_flg_out_mk;
  boolean rtb_flg_out_cn;
  boolean rtb_LogicalOperator3_as;
  boolean rtb_RelationalOperator2_j;
  float32 rtb_MinMax3_b_tmp;
  float32 rtb_MinMax3_n;
  float32 rtb_MinMax4;
  float32 rtb_MinMax4_i_tmp;
  float32 rtb_MinMax4_i_tmp_0;
  float32 rtb_Sum;
  float32 rtb_Sum1;
  float32 rtb_Sum2;
  float32 rtb_Sum3;
  float32 rtb_Switch2_i5;
  uint8 tmp;
  boolean rtb_LogicalOperator3;
  boolean rtb_LogicalOperator7_b;
  boolean rtb_RelationalOperator1_f;
  boolean rtb_RelationalOperator6_f;
  boolean rtb_RelationalOperator6_ku;
  boolean tdad_b_disEnbDrvFilter_tmp;

  /* MinMax: '<S207>/MinMax4' incorporates:
   *  Constant: '<S207>/Constant2'
   *  MinMax: '<S204>/MinMax4'
   *  MinMax: '<S220>/MinMax4'
   */
  rtb_MinMax3_b_tmp = fmaxf(((float32)TRQ_ZERO),
    swc_TCOO_ARID_DEF.DataTypeConversion94);

  /* Switch: '<S205>/Switch8' incorporates:
   *  MinMax: '<S205>/MinMax'
   */
  if (swc_TCOO_ARID_DEF.tqdd_b_ehbVlcCtlDrvTqEnb) {
    rtb_Sum1 = apdd_tq_whlDem_Nm;
  } else {
    rtb_Sum1 = fmaxf(fmaxf(apdd_tq_whlDem_Nm,
      swc_TCOO_ARID_DEF.DataTypeConversion91),
                     swc_TCOO_ARID_DEF.DataTypeConversion92);
  }

  /* MinMax: '<S205>/MinMax2' incorporates:
   *  Switch: '<S205>/Switch8'
   */
  tdad_tq_whlDemUnlim_Nm = fminf(rtb_Sum1,
    swc_TCOO_ARID_DEF.DataTypeConversion54);

  /* MinMax: '<S207>/MinMax3' incorporates:
   *  Constant: '<S207>/Constant1'
   *  MinMax: '<S204>/MinMax3'
   *  MinMax: '<S220>/MinMax3'
   */
  rtb_MinMax4_i_tmp = fminf(swc_TCOO_ARID_DEF.DataTypeConversion95, ((float32)
    TRQ_ZERO));

  /* Switch: '<S329>/Switch2' incorporates:
   *  MinMax: '<S207>/MinMax3'
   *  MinMax: '<S207>/MinMax4'
   *  RelationalOperator: '<S329>/LowerRelop1'
   *  RelationalOperator: '<S329>/UpperRelop'
   *  Switch: '<S329>/Switch'
   */
  if (tdad_tq_whlDemUnlim_Nm > rtb_MinMax3_b_tmp) {
    /* Switch: '<S329>/Switch2' */
    tdad_tq_whlDemUnfilt_Nm = rtb_MinMax3_b_tmp;
  } else if (tdad_tq_whlDemUnlim_Nm < rtb_MinMax4_i_tmp) {
    /* Switch: '<S329>/Switch' incorporates:
     *  MinMax: '<S207>/MinMax3'
     *  Switch: '<S329>/Switch2'
     */
    tdad_tq_whlDemUnfilt_Nm = rtb_MinMax4_i_tmp;
  } else {
    /* Switch: '<S329>/Switch2' incorporates:
     *  Switch: '<S329>/Switch'
     */
    tdad_tq_whlDemUnfilt_Nm = tdad_tq_whlDemUnlim_Nm;
  }

  /* End of Switch: '<S329>/Switch2' */

  /* MinMax: '<S204>/MinMax4' incorporates:
   *  Constant: '<S222>/Constant1'
   *  Constant: '<S314>/step_time1'
   *  Constant: '<S314>/step_time2'
   *  MinMax: '<S314>/MinMax4'
   *  MinMax: '<S314>/MinMax5'
   *  Sum: '<S314>/Sum2'
   */
  rtb_MinMax4 = fminf(((float32)WHL_TRQ_MAX), tdad_tq_whlDemUnfilt_Nm + fmaxf
                      (tdac_tq_whlMaxLimOffset_Nm, 0.0F));

  /* MinMax: '<S314>/MinMax2' incorporates:
   *  Constant: '<S222>/Constant10'
   *  Constant: '<S222>/Constant2'
   *  Constant: '<S314>/step_time6'
   *  MinMax: '<S314>/MinMax1'
   *  MinMax: '<S314>/MinMax3'
   *  Product: '<S314>/Product1'
   *  Sum: '<S314>/Sum1'
   *  Sum: '<S314>/Sum5'
   *  UnitDelay: '<S314>/UnitDelay1'
   */
  tdad_tq_whlFiltMax_Nm = fmaxf(rtb_MinMax4, fmaxf(rtb_MinMax4 -
    swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_f, fminf(0.0F, ((float32)
    TDA_TASK_INTERVAL_S) * tdac_dtq_whlMaxLimDecGrad_Nmps)) +
    swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_f);

  /* MinMax: '<S204>/MinMax4' incorporates:
   *  Sum: '<S316>/Sum4'
   *  UnitDelay: '<S316>/Unit Delay4'
   */
  rtb_MinMax4 = tdad_tq_whlDemUnfilt_Nm - swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_h;

  /* RelationalOperator: '<S316>/Relational Operator' incorporates:
   *  Constant: '<S316>/Constant9'
   */
  rtb_RelationalOperator_h = (rtb_MinMax4 > tdac_tq_whlPosTgtTqOffs_Nm);

  /* Outputs for Atomic SubSystem: '<S316>/turnON_delay2' */
  /* Constant: '<S316>/Constant6' incorporates:
   *  Constant: '<S316>/Constant4'
   */
  swc_TCOO_turnON_delay(rtb_RelationalOperator_h, tdac_tm_tipInSetTime_s,
                        ((float32)TDA_TASK_INTERVAL_S), &rtb_flg_out_mk,
                        &swc_TCOO_ARID_DEF.ARID_DEF_turnON_delay2);

  /* End of Outputs for SubSystem: '<S316>/turnON_delay2' */

  /* Logic: '<S316>/Logical Operator7' incorporates:
   *  Constant: '<S316>/Constant10'
   *  RelationalOperator: '<S316>/Relational Operator4'
   */
  rtb_LogicalOperator7_n = (rtb_flg_out_mk || (rtb_MinMax4 >
    tdac_tq_whlPosTgtTqOffsNoDeb_Nm));

  /* RelationalOperator: '<S316>/Relational Operator2' incorporates:
   *  Constant: '<S316>/Constant2'
   */
  rtb_RelationalOperator2_b = (rtb_MinMax4 < tdac_tq_whlNegTgtTqOffs_Nm);

  /* Outputs for Atomic SubSystem: '<S316>/turnON_delay1' */
  /* Constant: '<S316>/Constant5' incorporates:
   *  Constant: '<S316>/Constant12'
   */
  swc_TCOO_turnON_delay(rtb_RelationalOperator2_b, tdac_tm_tipOutSetTime_s,
                        ((float32)TDA_TASK_INTERVAL_S), &rtb_flg_out_cn,
                        &swc_TCOO_ARID_DEF.ARID_DEF_turnON_delay1);

  /* End of Outputs for SubSystem: '<S316>/turnON_delay1' */

  /* Logic: '<S316>/Logical Operator9' incorporates:
   *  Constant: '<S316>/Constant11'
   *  RelationalOperator: '<S316>/Relational Operator5'
   */
  rtb_LogicalOperator9_h = (rtb_flg_out_cn || (rtb_MinMax4 <
    tdac_tq_whlNegTgtTqOffsNoDeb_Nm));

  /* Outputs for Atomic SubSystem: '<S316>/SR_latch' */
  swc_TCOO_SR_latch(rtb_LogicalOperator7_n, rtb_LogicalOperator9_h,
                    &rtb_RelationalOperator2_j,
                    &swc_TCOO_ARID_DEF.ARID_DEF_SR_latch_k);

  /* End of Outputs for SubSystem: '<S316>/SR_latch' */

  /* Outputs for Enabled SubSystem: '<S228>/Filter' incorporates:
   *  EnablePort: '<S260>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S226>/Filter' incorporates:
   *  EnablePort: '<S237>/Enable'
   */
  /* Sum: '<S316>/Sum2' incorporates:
   *  Sum: '<S237>/Sum2'
   *  Sum: '<S260>/Sum6'
   *  UnitDelay: '<S220>/Unit Delay4'
   */
  rtb_MinMax4_i_tmp_0 = tdad_tq_whlDemUnfilt_Nm -
    swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b;

  /* End of Outputs for SubSystem: '<S226>/Filter' */
  /* End of Outputs for SubSystem: '<S228>/Filter' */

  /* RelationalOperator: '<S316>/Relational Operator3' incorporates:
   *  Constant: '<S316>/Constant3'
   *  Sum: '<S316>/Sum2'
   */
  rtb_RelationalOperator3_n = (rtb_MinMax4_i_tmp_0 < tdac_tq_whlNegErrTqOffs_Nm);

  /* Outputs for Atomic SubSystem: '<S316>/turnON_delay4' */
  /* Constant: '<S316>/Constant7' incorporates:
   *  Constant: '<S316>/Constant14'
   */
  swc_TCOO_turnON_delay(rtb_RelationalOperator3_n, tdac_tm_negFiltSetTime_s,
                        ((float32)TDA_TASK_INTERVAL_S), &rtb_flg_out_j,
                        &swc_TCOO_ARID_DEF.ARID_DEF_turnON_delay4);

  /* End of Outputs for SubSystem: '<S316>/turnON_delay4' */

  /* RelationalOperator: '<S316>/Relational Operator1' incorporates:
   *  Constant: '<S316>/Constant1'
   *  Sum: '<S316>/Sum2'
   */
  rtb_RelationalOperator1_hu = (rtb_MinMax4_i_tmp_0 > tdac_tq_whlPosErrTqOffs_Nm);

  /* Outputs for Atomic SubSystem: '<S316>/turnON_delay3' */
  /* Constant: '<S316>/Constant8' incorporates:
   *  Constant: '<S316>/Constant13'
   */
  swc_TCOO_turnON_delay(rtb_RelationalOperator1_hu, tdac_tm_posFiltSetTime_s,
                        ((float32)TDA_TASK_INTERVAL_S), &rtb_flg_out_a0,
                        &swc_TCOO_ARID_DEF.ARID_DEF_turnON_delay3);

  /* End of Outputs for SubSystem: '<S316>/turnON_delay3' */

  /* Logic: '<S316>/Logical Operator3' incorporates:
   *  Logic: '<S316>/Logical Operator4'
   *  Logic: '<S316>/Logical Operator5'
   */
  rtb_LogicalOperator3_c = ((rtb_RelationalOperator2_j && (!rtb_flg_out_j)) ||
    rtb_flg_out_a0);

  /* Logic: '<S316>/Logical Operator1' incorporates:
   *  Logic: '<S316>/Logical Operator2'
   *  Logic: '<S316>/Logical Operator6'
   *  Logic: '<S316>/Logical Operator8'
   */
  rtb_LogicalOperator1_p = (((!rtb_RelationalOperator2_j) && (!rtb_flg_out_a0)) ||
    rtb_flg_out_j);

  /* Outputs for Atomic SubSystem: '<S316>/SR_latch1' */
  swc_TCOO_SR_latch(rtb_LogicalOperator3_c, rtb_LogicalOperator1_p,
                    &rtb_LogicalOperator3_as,
                    &swc_TCOO_ARID_DEF.ARID_DEF_SR_latch1_c);

  /* End of Outputs for SubSystem: '<S316>/SR_latch1' */

  /* SignalConversion generated from: '<S316>/SR_latch1' */
  tdad_b_tipIn = rtb_LogicalOperator3_as;

  /* Sum: '<S318>/Sum' incorporates:
   *  Constant: '<S318>/Constant'
   *  Constant: '<S318>/Constant2'
   */
  rtb_Sum = tdac_tq_whlUpLimPosOffs_Nm + tdac_tq_whlZeroRefPos_Nm;

  /* Sum: '<S318>/Sum1' incorporates:
   *  Constant: '<S318>/Constant2'
   *  Constant: '<S318>/Constant4'
   */
  rtb_Sum1 = tdac_tq_whlZeroRefPos_Nm + tdac_tq_whlLoLimPosOffs_Nm;

  /* Sum: '<S318>/Sum2' incorporates:
   *  Constant: '<S318>/Constant1'
   *  Constant: '<S318>/Constant3'
   */
  rtb_Sum2 = tdac_tq_whlUpLimNegOffs_Nm + tdac_tq_whlZeroRefNeg_Nm;

  /* Sum: '<S318>/Sum3' incorporates:
   *  Constant: '<S318>/Constant3'
   *  Constant: '<S318>/Constant5'
   */
  rtb_Sum3 = tdac_tq_whlZeroRefNeg_Nm + tdac_tq_whlLoLimNegOffs_Nm;

  /* Chart: '<S223>/TorqueRange' incorporates:
   *  Constant: '<S318>/Constant2'
   *  Constant: '<S318>/Constant3'
   *  UnitDelay: '<S220>/Unit Delay4'
   */
  if (swc_TCOO_ARID_DEF.is_active_c2_tda == 0U) {
    swc_TCOO_ARID_DEF.is_active_c2_tda = 1U;
    if (tdad_b_tipIn) {
      swc_TCOO_ARID_DEF.is_c2_tda = swc_TCOO_IN_PEDAL_TIP_IN;
      if (swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b >= tdac_tq_whlZeroRefPos_Nm) {
        swc_TCOO_ARID_DEF.is_PEDAL_TIP_IN = swc_TCOO_IN_POWER_POS;
        tdad_e_filterTrqRange = FiltTrqRange_POWER_POS;
      } else if (swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b >= rtb_Sum1) {
        swc_TCOO_ARID_DEF.is_PEDAL_TIP_IN = swc_TCOO_IN_ZEROCROSS_POS;
        tdad_e_filterTrqRange = FiltTrqRange_ZEROCROSS_POS;
      } else {
        swc_TCOO_ARID_DEF.is_PEDAL_TIP_IN = swc_TCOO_IN_BRAKING_POS;
        tdad_e_filterTrqRange = FiltTrqRange_BRAKING_POS;
      }
    } else {
      swc_TCOO_ARID_DEF.is_c2_tda = swc_TCOO_IN_PEDAL_TIP_OUT;
      if (swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b <= tdac_tq_whlZeroRefNeg_Nm) {
        swc_TCOO_ARID_DEF.is_PEDAL_TIP_OUT = swc_TCOO_IN_BRAKING_NEG;
        tdad_e_filterTrqRange = FiltTrqRange_BRAKING_NEG;
      } else if (swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b <= rtb_Sum2) {
        swc_TCOO_ARID_DEF.is_PEDAL_TIP_OUT = swc_TCOO_IN_ZEROCROSS_NEG;
        tdad_e_filterTrqRange = FiltTrqRange_ZEROCROSS_NEG;
      } else {
        swc_TCOO_ARID_DEF.is_PEDAL_TIP_OUT = swc_TCOO_IN_POWER_NEG;
        tdad_e_filterTrqRange = FiltTrqRange_POWER_NEG;
      }
    }
  } else if (swc_TCOO_ARID_DEF.is_c2_tda == swc_TCOO_IN_PEDAL_TIP_IN) {
    if (!tdad_b_tipIn) {
      swc_TCOO_ARID_DEF.is_PEDAL_TIP_IN = swc_TCOO_IN_NO_ACTIVE_CHILD_hl;
      swc_TCOO_ARID_DEF.is_c2_tda = swc_TCOO_IN_PEDAL_TIP_OUT;
      if (swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b <= tdac_tq_whlZeroRefNeg_Nm) {
        swc_TCOO_ARID_DEF.is_PEDAL_TIP_OUT = swc_TCOO_IN_BRAKING_NEG;
        tdad_e_filterTrqRange = FiltTrqRange_BRAKING_NEG;
      } else if (swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b <= rtb_Sum2) {
        swc_TCOO_ARID_DEF.is_PEDAL_TIP_OUT = swc_TCOO_IN_ZEROCROSS_NEG;
        tdad_e_filterTrqRange = FiltTrqRange_ZEROCROSS_NEG;
      } else {
        swc_TCOO_ARID_DEF.is_PEDAL_TIP_OUT = swc_TCOO_IN_POWER_NEG;
        tdad_e_filterTrqRange = FiltTrqRange_POWER_NEG;
      }
    } else {
      switch (swc_TCOO_ARID_DEF.is_PEDAL_TIP_IN) {
       case swc_TCOO_IN_BRAKING_POS:
        tdad_e_filterTrqRange = FiltTrqRange_BRAKING_POS;
        if (swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b >= rtb_Sum) {
          swc_TCOO_ARID_DEF.is_PEDAL_TIP_IN = swc_TCOO_IN_POWER_POS;
          tdad_e_filterTrqRange = FiltTrqRange_POWER_POS;
        } else if (swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b >= rtb_Sum1) {
          swc_TCOO_ARID_DEF.is_PEDAL_TIP_IN = swc_TCOO_IN_ZEROCROSS_POS;
          tdad_e_filterTrqRange = FiltTrqRange_ZEROCROSS_POS;
        }
        break;

       case swc_TCOO_IN_POWER_POS:
        tdad_e_filterTrqRange = FiltTrqRange_POWER_POS;
        break;

       default:
        /* case IN_ZEROCROSS_POS: */
        tdad_e_filterTrqRange = FiltTrqRange_ZEROCROSS_POS;
        if (swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b >= rtb_Sum) {
          swc_TCOO_ARID_DEF.is_PEDAL_TIP_IN = swc_TCOO_IN_POWER_POS;
          tdad_e_filterTrqRange = FiltTrqRange_POWER_POS;
        }
        break;
      }
    }

    /* case IN_PEDAL_TIP_OUT: */
  } else if (tdad_b_tipIn) {
    swc_TCOO_ARID_DEF.is_PEDAL_TIP_OUT = swc_TCOO_IN_NO_ACTIVE_CHILD_hl;
    swc_TCOO_ARID_DEF.is_c2_tda = swc_TCOO_IN_PEDAL_TIP_IN;
    if (swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b >= tdac_tq_whlZeroRefPos_Nm) {
      swc_TCOO_ARID_DEF.is_PEDAL_TIP_IN = swc_TCOO_IN_POWER_POS;
      tdad_e_filterTrqRange = FiltTrqRange_POWER_POS;
    } else if (swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b >= rtb_Sum1) {
      swc_TCOO_ARID_DEF.is_PEDAL_TIP_IN = swc_TCOO_IN_ZEROCROSS_POS;
      tdad_e_filterTrqRange = FiltTrqRange_ZEROCROSS_POS;
    } else {
      swc_TCOO_ARID_DEF.is_PEDAL_TIP_IN = swc_TCOO_IN_BRAKING_POS;
      tdad_e_filterTrqRange = FiltTrqRange_BRAKING_POS;
    }
  } else {
    switch (swc_TCOO_ARID_DEF.is_PEDAL_TIP_OUT) {
     case swc_TCOO_IN_BRAKING_NEG:
      tdad_e_filterTrqRange = FiltTrqRange_BRAKING_NEG;
      break;

     case swc_TCOO_IN_POWER_NEG:
      tdad_e_filterTrqRange = FiltTrqRange_POWER_NEG;
      if (swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b <= rtb_Sum3) {
        swc_TCOO_ARID_DEF.is_PEDAL_TIP_OUT = swc_TCOO_IN_BRAKING_NEG;
        tdad_e_filterTrqRange = FiltTrqRange_BRAKING_NEG;
      } else if (swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b <= rtb_Sum2) {
        swc_TCOO_ARID_DEF.is_PEDAL_TIP_OUT = swc_TCOO_IN_ZEROCROSS_NEG;
        tdad_e_filterTrqRange = FiltTrqRange_ZEROCROSS_NEG;
      }
      break;

     default:
      /* case IN_ZEROCROSS_NEG: */
      tdad_e_filterTrqRange = FiltTrqRange_ZEROCROSS_NEG;
      if (swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b <= rtb_Sum3) {
        swc_TCOO_ARID_DEF.is_PEDAL_TIP_OUT = swc_TCOO_IN_BRAKING_NEG;
        tdad_e_filterTrqRange = FiltTrqRange_BRAKING_NEG;
      }
      break;
    }
  }

  /* End of Chart: '<S223>/TorqueRange' */

  /* Switch: '<S226>/Switch3' incorporates:
   *  Constant: '<S235>/Constant'
   *  RelationalOperator: '<S226>/Relational Operator4'
   */
  if (tdad_e_filterTrqRange == FiltTrqRange_BRAKING_POS) {
    /* MinMax: '<S204>/MinMax4' */
    rtb_MinMax4 = rtb_Sum1;
  } else {
    /* MinMax: '<S204>/MinMax4' incorporates:
     *  Constant: '<S226>/Constant2'
     */
    rtb_MinMax4 = ((float32)WHL_TRQ_MAX);
  }

  /* End of Switch: '<S226>/Switch3' */

  /* Logic: '<S224>/Logical Operator4' incorporates:
   *  Logic: '<S206>/Logical Operator5'
   */
  tdad_b_disEnbDrvFilter_tmp = !swc_TCOO_ARID_DEF.tqdd_b_ehbVlcCtlDrvTqEnb;

  /* Logic: '<S224>/Logical Operator5' incorporates:
   *  Constant: '<S224>/Constant2'
   *  Constant: '<S224>/Constant3'
   *  Logic: '<S224>/Logical Operator1'
   *  Logic: '<S224>/Logical Operator3'
   *  Logic: '<S224>/Logical Operator4'
   *  Logic: '<S224>/Logical Operator6'
   *  Logic: '<S224>/Logical Operator7'
   *  Logic: '<S224>/Logical Operator9'
   */
  tdad_b_disEnbDrvFilter = ((swc_TCOO_ARID_DEF.tqdd_b_ehbVlcCtlDrvTqEnb &&
    (!swc_TCOO_ARID_DEF.LogicalOperator48) && (!tcoo_tdac_b_enaEhbVlcFilt)) ||
    ((!tdac_b_enaEhbCrbsFilt) && swctcoo_dtdd_b_ehbMbRgnOvrCtl &&
     tdad_b_disEnbDrvFilter_tmp));

  /* Switch: '<S267>/Switch' incorporates:
   *  Constant: '<S235>/Constant'
   *  Constant: '<S267>/Constant7'
   *  Constant: '<S272>/Constant'
   *  Constant: '<S273>/Constant'
   *  Constant: '<S274>/Constant'
   *  Constant: '<S275>/Constant'
   *  Constant: '<S276>/Constant'
   *  Logic: '<S267>/Logical Operator'
   *  Logic: '<S267>/Logical Operator1'
   *  Logic: '<S267>/Logical Operator2'
   *  Logic: '<S267>/Logical Operator3'
   *  Logic: '<S267>/Logical Operator4'
   *  Logic: '<S267>/Logical Operator5'
   *  Logic: '<S267>/Logical Operator6'
   *  Logic: '<S267>/Logical Operator7'
   *  Logic: '<S267>/Logical Operator8'
   *  RelationalOperator: '<S226>/Relational Operator4'
   *  RelationalOperator: '<S267>/Relational Operator1'
   *  RelationalOperator: '<S267>/Relational Operator2'
   *  RelationalOperator: '<S267>/Relational Operator3'
   *  RelationalOperator: '<S267>/Relational Operator4'
   *  RelationalOperator: '<S267>/Relational Operator5'
   *  RelationalOperator: '<S267>/Relational Operator6'
   *  S-Function (sfix_bitop): '<S267>/Bitwise Operator'
   *  S-Function (sfix_bitop): '<S267>/Bitwise Operator1'
   *  S-Function (sfix_bitop): '<S267>/Bitwise Operator2'
   *  S-Function (sfix_bitop): '<S267>/Bitwise Operator3'
   *  S-Function (sfix_bitop): '<S267>/Bitwise Operator4'
   *  S-Function (sfix_bitop): '<S267>/Bitwise Operator5'
   *  S-Function (sfix_bitop): '<S267>/Bitwise Operator6'
   */
  if ((((tdad_e_filterTrqRange == FiltTrqRange_BRAKING_POS) &&
        ((tdac_st_filtEnaCW & ((uint8)2U)) != 0)) || ((tdad_e_filterTrqRange ==
         FiltTrqRange_BRAKING_NEG) && ((tdac_st_filtEnaCW & ((uint8)4U)) != 0)) ||
       ((tdad_e_filterTrqRange == FiltTrqRange_ZEROCROSS_POS) &&
        ((tdac_st_filtEnaCW & ((uint8)8U)) != 0)) || ((tdad_e_filterTrqRange ==
         FiltTrqRange_ZEROCROSS_NEG) && ((tdac_st_filtEnaCW & ((uint8)16U)) != 0))
       || ((tdad_e_filterTrqRange == FiltTrqRange_POWER_POS) &&
           ((tdac_st_filtEnaCW & ((uint8)32U)) != 0)) || ((tdad_e_filterTrqRange
         == FiltTrqRange_POWER_NEG) && ((tdac_st_filtEnaCW & ((uint8)64U)) != 0)))
      && ((tdac_st_filtEnaCW & ((uint8)1U)) != 0) && (!tdad_b_disEnbDrvFilter))
  {
    /* Switch: '<S267>/Switch' */
    tdad_e_filterType = tdad_e_filterTrqRange;
  } else {
    /* Switch: '<S267>/Switch' incorporates:
     *  Constant: '<S277>/Constant'
     */
    tdad_e_filterType = FiltTrqRange_FILTER_OFF;
  }

  /* End of Switch: '<S267>/Switch' */

  /* Logic: '<S226>/Logical Operator7' incorporates:
   *  Constant: '<S235>/Constant'
   *  Constant: '<S272>/Constant'
   *  Constant: '<S276>/Constant'
   *  RelationalOperator: '<S226>/Relational Operator1'
   *  RelationalOperator: '<S226>/Relational Operator3'
   *  RelationalOperator: '<S226>/Relational Operator4'
   *  RelationalOperator: '<S226>/Relational Operator6'
   *  RelationalOperator: '<S267>/Relational Operator1'
   *  RelationalOperator: '<S267>/Relational Operator3'
   *  Switch: '<S267>/Switch'
   */
  rtb_LogicalOperator7_b = ((tdad_e_filterType == FiltTrqRange_BRAKING_POS) ||
    (tdad_e_filterType == FiltTrqRange_BRAKING_NEG) || (tdad_e_filterType ==
    FiltTrqRange_POWER_NEG));

  /* Logic: '<S221>/Logical Operator3' incorporates:
   *  Constant: '<S221>/Constant17'
   *  Constant: '<S266>/Constant'
   *  Logic: '<S221>/Logical Operator1'
   *  Logic: '<S221>/Logical Operator2'
   *  RelationalOperator: '<S266>/Compare'
   */
  rtb_LogicalOperator3 = ((swc_TCOO_ARID_DEF.DataTypeConversion170 == 1.0) &&
    (swc_TCOO_ARID_DEF.DataTypeConversion1 ||
     (swc_TCOO_ARID_DEF.DataTypeConversion160 && tdac_b_useSportMapsIn4WDMode)));

  /* Outputs for Enabled SubSystem: '<S268>/Braking_Pos' incorporates:
   *  EnablePort: '<S279>/Enable'
   */
  /* RelationalOperator: '<S268>/Relational Operator' incorporates:
   *  Constant: '<S235>/Constant'
   *  RelationalOperator: '<S226>/Relational Operator4'
   *  RelationalOperator: '<S226>/Relational Operator6'
   *  Switch: '<S267>/Switch'
   */
  if (tdad_e_filterType == FiltTrqRange_BRAKING_POS) {
    /* If: '<S279>/If' */
    if (swc_TCOO_ARID_DEF.DataTypeConversion5 && rtb_LogicalOperator3) {
      /* Outputs for IfAction SubSystem: '<S279>/EVSportMap' incorporates:
       *  ActionPort: '<S289>/Action Port'
       */
      /* Merge: '<S268>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S289>/2-D Lookup Table4'
       *  Switch: '<S329>/Switch2'
       */
      tdad_tm_tauFilt1st_s = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_tau1st_X_VehSpd_kph[0], (const float32 *)
         &tdaa_tau1st_Y_TgtTrq_Nm[0], (const float32 *)
         &tdam_tau1stBrkPosEVSprt_Z_s[0], swc_TCOO_ConstP.pooled14, 6U);

      /* End of Outputs for SubSystem: '<S279>/EVSportMap' */
    } else if (swc_TCOO_ARID_DEF.DataTypeConversion5) {
      /* Outputs for IfAction SubSystem: '<S279>/EVMap' incorporates:
       *  ActionPort: '<S288>/Action Port'
       */
      /* Merge: '<S268>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S288>/2-D Lookup Table3'
       *  Switch: '<S329>/Switch2'
       */
      tdad_tm_tauFilt1st_s = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_tau1st_X_VehSpd_kph[0], (const float32 *)
         &tdaa_tau1st_Y_TgtTrq_Nm[0], (const float32 *)&tdam_tau1stBrkPosEV_Z_s
         [0], swc_TCOO_ConstP.pooled14, 6U);

      /* End of Outputs for SubSystem: '<S279>/EVMap' */
    } else if (rtb_LogicalOperator3) {
      /* Outputs for IfAction SubSystem: '<S279>/SportMap' incorporates:
       *  ActionPort: '<S291>/Action Port'
       */
      /* Merge: '<S268>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S291>/2-D Lookup Table2'
       *  Switch: '<S329>/Switch2'
       */
      tdad_tm_tauFilt1st_s = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_tau1st_X_VehSpd_kph[0], (const float32 *)
         &tdaa_tau1st_Y_TgtTrq_Nm[0], (const float32 *)
         &tdam_tau1stBrkPosSprt_Z_s[0], swc_TCOO_ConstP.pooled14, 6U);

      /* End of Outputs for SubSystem: '<S279>/SportMap' */
    } else {
      /* Outputs for IfAction SubSystem: '<S279>/NormalMap' incorporates:
       *  ActionPort: '<S290>/Action Port'
       */
      /* Merge: '<S268>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S290>/2-D Lookup Table1'
       *  Switch: '<S329>/Switch2'
       */
      tdad_tm_tauFilt1st_s = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_tau1st_X_VehSpd_kph[0], (const float32 *)
         &tdaa_tau1st_Y_TgtTrq_Nm[0], (const float32 *)&tdam_tau1stBrkPos_Z_s[0],
         swc_TCOO_ConstP.pooled14, 6U);

      /* End of Outputs for SubSystem: '<S279>/NormalMap' */
    }

    /* End of If: '<S279>/If' */
  }

  /* End of RelationalOperator: '<S268>/Relational Operator' */
  /* End of Outputs for SubSystem: '<S268>/Braking_Pos' */

  /* Outputs for Enabled SubSystem: '<S268>/Braking_Neg' incorporates:
   *  EnablePort: '<S278>/Enable'
   */
  /* RelationalOperator: '<S268>/Relational Operator1' incorporates:
   *  Constant: '<S272>/Constant'
   *  RelationalOperator: '<S226>/Relational Operator6'
   *  RelationalOperator: '<S267>/Relational Operator1'
   *  Switch: '<S267>/Switch'
   */
  if (tdad_e_filterType == FiltTrqRange_BRAKING_NEG) {
    /* If: '<S278>/If' */
    if (swc_TCOO_ARID_DEF.DataTypeConversion5 && rtb_LogicalOperator3) {
      /* Outputs for IfAction SubSystem: '<S278>/EVSportMap' incorporates:
       *  ActionPort: '<S285>/Action Port'
       */
      /* Merge: '<S268>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S285>/2-D Lookup Table4'
       *  Switch: '<S329>/Switch2'
       */
      tdad_tm_tauFilt1st_s = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_tau1st_X_VehSpd_kph[0], (const float32 *)
         &tdaa_tau1st_Y_TgtTrq_Nm[0], (const float32 *)
         &tdam_tau1stBrkNegEVSprt_Z_s[0], swc_TCOO_ConstP.pooled14, 6U);

      /* End of Outputs for SubSystem: '<S278>/EVSportMap' */
    } else if (swc_TCOO_ARID_DEF.DataTypeConversion5) {
      /* Outputs for IfAction SubSystem: '<S278>/EVMap' incorporates:
       *  ActionPort: '<S284>/Action Port'
       */
      /* Merge: '<S268>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S284>/2-D Lookup Table3'
       *  Switch: '<S329>/Switch2'
       */
      tdad_tm_tauFilt1st_s = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_tau1st_X_VehSpd_kph[0], (const float32 *)
         &tdaa_tau1st_Y_TgtTrq_Nm[0], (const float32 *)&tdam_tau1stBrkNegEV_Z_s
         [0], swc_TCOO_ConstP.pooled14, 6U);

      /* End of Outputs for SubSystem: '<S278>/EVMap' */
    } else if (rtb_LogicalOperator3) {
      /* Outputs for IfAction SubSystem: '<S278>/SportMap' incorporates:
       *  ActionPort: '<S287>/Action Port'
       */
      /* Merge: '<S268>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S287>/2-D Lookup Table2'
       *  Switch: '<S329>/Switch2'
       */
      tdad_tm_tauFilt1st_s = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_tau1st_X_VehSpd_kph[0], (const float32 *)
         &tdaa_tau1st_Y_TgtTrq_Nm[0], (const float32 *)
         &tdam_tau1stBrkNegSprt_Z_s[0], swc_TCOO_ConstP.pooled14, 6U);

      /* End of Outputs for SubSystem: '<S278>/SportMap' */
    } else {
      /* Outputs for IfAction SubSystem: '<S278>/NormalMap' incorporates:
       *  ActionPort: '<S286>/Action Port'
       */
      /* Merge: '<S268>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S286>/2-D Lookup Table1'
       *  Switch: '<S329>/Switch2'
       */
      tdad_tm_tauFilt1st_s = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_tau1st_X_VehSpd_kph[0], (const float32 *)
         &tdaa_tau1st_Y_TgtTrq_Nm[0], (const float32 *)&tdam_tau1stBrkNeg_Z_s[0],
         swc_TCOO_ConstP.pooled14, 6U);

      /* End of Outputs for SubSystem: '<S278>/NormalMap' */
    }

    /* End of If: '<S278>/If' */
  }

  /* End of RelationalOperator: '<S268>/Relational Operator1' */
  /* End of Outputs for SubSystem: '<S268>/Braking_Neg' */

  /* Outputs for Enabled SubSystem: '<S268>/Power_Neg' incorporates:
   *  EnablePort: '<S283>/Enable'
   */
  /* RelationalOperator: '<S268>/Relational Operator6' incorporates:
   *  Constant: '<S276>/Constant'
   *  RelationalOperator: '<S226>/Relational Operator6'
   *  RelationalOperator: '<S267>/Relational Operator3'
   *  Switch: '<S267>/Switch'
   */
  if (tdad_e_filterType == FiltTrqRange_POWER_NEG) {
    /* If: '<S283>/If' */
    if (swc_TCOO_ARID_DEF.DataTypeConversion5 && rtb_LogicalOperator3) {
      /* Outputs for IfAction SubSystem: '<S283>/EVSportMap' incorporates:
       *  ActionPort: '<S293>/Action Port'
       */
      /* Merge: '<S268>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S293>/2-D Lookup Table4'
       *  Switch: '<S329>/Switch2'
       */
      tdad_tm_tauFilt1st_s = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_tau1st_X_VehSpd_kph[0], (const float32 *)
         &tdaa_tau1st_Y_TgtTrq_Nm[0], (const float32 *)
         &tdam_tau1stPwrNegEVSprt_Z_s[0], swc_TCOO_ConstP.pooled14, 6U);

      /* End of Outputs for SubSystem: '<S283>/EVSportMap' */
    } else if (swc_TCOO_ARID_DEF.DataTypeConversion5) {
      /* Outputs for IfAction SubSystem: '<S283>/EVMap' incorporates:
       *  ActionPort: '<S292>/Action Port'
       */
      /* Merge: '<S268>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S292>/2-D Lookup Table3'
       *  Switch: '<S329>/Switch2'
       */
      tdad_tm_tauFilt1st_s = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_tau1st_X_VehSpd_kph[0], (const float32 *)
         &tdaa_tau1st_Y_TgtTrq_Nm[0], (const float32 *)&tdam_tau1stPwrNegEV_Z_s
         [0], swc_TCOO_ConstP.pooled14, 6U);

      /* End of Outputs for SubSystem: '<S283>/EVMap' */
    } else if (rtb_LogicalOperator3) {
      /* Outputs for IfAction SubSystem: '<S283>/SportMap' incorporates:
       *  ActionPort: '<S295>/Action Port'
       */
      /* Merge: '<S268>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S295>/2-D Lookup Table2'
       *  Switch: '<S329>/Switch2'
       */
      tdad_tm_tauFilt1st_s = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_tau1st_X_VehSpd_kph[0], (const float32 *)
         &tdaa_tau1st_Y_TgtTrq_Nm[0], (const float32 *)
         &tdam_tau1stPwrNegSprt_Z_s[0], swc_TCOO_ConstP.pooled14, 6U);

      /* End of Outputs for SubSystem: '<S283>/SportMap' */
    } else {
      /* Outputs for IfAction SubSystem: '<S283>/NormalMap' incorporates:
       *  ActionPort: '<S294>/Action Port'
       */
      /* Merge: '<S268>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S294>/2-D Lookup Table1'
       *  Switch: '<S329>/Switch2'
       */
      tdad_tm_tauFilt1st_s = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_tau1st_X_VehSpd_kph[0], (const float32 *)
         &tdaa_tau1st_Y_TgtTrq_Nm[0], (const float32 *)&tdam_tau1stPwrNeg_Z_s[0],
         swc_TCOO_ConstP.pooled14, 6U);

      /* End of Outputs for SubSystem: '<S283>/NormalMap' */
    }

    /* End of If: '<S283>/If' */
  }

  /* End of RelationalOperator: '<S268>/Relational Operator6' */
  /* End of Outputs for SubSystem: '<S268>/Power_Neg' */

  /* Outputs for Enabled SubSystem: '<S226>/Filter' incorporates:
   *  EnablePort: '<S237>/Enable'
   */
  if (rtb_LogicalOperator7_b) {
    if (!swc_TCOO_ARID_DEF.Filter_MODE_c) {
      /* InitializeConditions for UnitDelay: '<S239>/Unit Delay' */
      swc_TCOO_ARID_DEF.UnitDelay_DSTATE_h = 0.0F;
      swc_TCOO_ARID_DEF.Filter_MODE_c = true;
    }

    /* Switch: '<S239>/Switch' incorporates:
     *  UnitDelay: '<S231>/Delay Input1'
     *
     * Block description for '<S231>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (!swc_TCOO_ARID_DEF.DelayInput1_DSTATE_i) {
      /* DataTypeConversion: '<S239>/Data Type Conversion' incorporates:
       *  Constant: '<S226>/Constant1'
       *  MinMax: '<S237>/MinMax'
       *  Product: '<S237>/Product1'
       *  Product: '<S237>/Product3'
       *  Sum: '<S237>/Sum1'
       *  Sum: '<S237>/Sum2'
       *  Switch: '<S239>/Switch'
       *  UnitDelay: '<S220>/Unit Delay4'
       */
      swc_TCOO_ARID_DEF.DataTypeConversion_d = (tdad_tq_whlDemUnfilt_Nm -
        swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b) / fmaxf(tdad_tm_tauFilt1st_s,
        ((float32)TDA_TASK_INTERVAL_S)) * ((float32)TDA_TASK_INTERVAL_S) +
        swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b;
    } else {
      /* DataTypeConversion: '<S239>/Data Type Conversion' incorporates:
       *  Constant: '<S226>/Constant1'
       *  MinMax: '<S237>/MinMax'
       *  Product: '<S237>/Product3'
       *  Product: '<S239>/Product'
       *  Sum: '<S239>/Sum'
       *  Switch: '<S239>/Switch'
       *  UnitDelay: '<S239>/Unit Delay'
       */
      swc_TCOO_ARID_DEF.DataTypeConversion_d = rtb_MinMax4_i_tmp_0 / fmaxf
        (tdad_tm_tauFilt1st_s, ((float32)TDA_TASK_INTERVAL_S)) * ((float32)
        TDA_TASK_INTERVAL_S) + swc_TCOO_ARID_DEF.UnitDelay_DSTATE_h;
    }

    /* End of Switch: '<S239>/Switch' */

    /* Update for UnitDelay: '<S239>/Unit Delay' */
    swc_TCOO_ARID_DEF.UnitDelay_DSTATE_h =
      swc_TCOO_ARID_DEF.DataTypeConversion_d;

    /* Switch: '<S226>/Switch2' */
    rtb_Switch2_i5 = swc_TCOO_ARID_DEF.DataTypeConversion_d;
  } else {
    swc_TCOO_ARID_DEF.Filter_MODE_c = false;

    /* Switch: '<S226>/Switch2' */
    rtb_Switch2_i5 = tdad_tq_whlDemUnfilt_Nm;
  }

  /* End of Outputs for SubSystem: '<S226>/Filter' */

  /* Switch: '<S226>/Switch1' incorporates:
   *  Constant: '<S276>/Constant'
   *  RelationalOperator: '<S226>/Relational Operator2'
   *  RelationalOperator: '<S226>/Relational Operator4'
   *  RelationalOperator: '<S267>/Relational Operator3'
   */
  if (tdad_e_filterTrqRange == FiltTrqRange_POWER_NEG) {
    /* MinMax: '<S315>/MinMax3' */
    rtb_MinMax3_n = rtb_Sum2;
  } else {
    /* MinMax: '<S315>/MinMax3' incorporates:
     *  Constant: '<S226>/Constant3'
     */
    rtb_MinMax3_n = ((float32)WHL_TRQ_MIN);
  }

  /* End of Switch: '<S226>/Switch1' */

  /* Switch: '<S238>/Switch2' incorporates:
   *  RelationalOperator: '<S238>/LowerRelop1'
   *  RelationalOperator: '<S238>/UpperRelop'
   *  Switch: '<S238>/Switch'
   */
  if (rtb_Switch2_i5 > rtb_MinMax4) {
    /* Switch: '<S238>/Switch2' */
    tdad_tq_whlDemFilt1st_Nm = rtb_MinMax4;
  } else if (rtb_Switch2_i5 < rtb_MinMax3_n) {
    /* Switch: '<S238>/Switch' incorporates:
     *  Switch: '<S238>/Switch2'
     */
    tdad_tq_whlDemFilt1st_Nm = rtb_MinMax3_n;
  } else {
    /* Switch: '<S238>/Switch2' incorporates:
     *  Switch: '<S238>/Switch'
     */
    tdad_tq_whlDemFilt1st_Nm = rtb_Switch2_i5;
  }

  /* End of Switch: '<S238>/Switch2' */

  /* RelationalOperator: '<S227>/Relational Operator6' incorporates:
   *  Constant: '<S273>/Constant'
   *  RelationalOperator: '<S226>/Relational Operator6'
   *  RelationalOperator: '<S267>/Relational Operator5'
   *  Switch: '<S267>/Switch'
   */
  rtb_RelationalOperator6_ku = (tdad_e_filterType == FiltTrqRange_ZEROCROSS_POS);

  /* RelationalOperator: '<S227>/Relational Operator1' incorporates:
   *  Constant: '<S274>/Constant'
   *  RelationalOperator: '<S226>/Relational Operator6'
   *  RelationalOperator: '<S267>/Relational Operator4'
   *  Switch: '<S267>/Switch'
   */
  rtb_RelationalOperator1_f = (tdad_e_filterType == FiltTrqRange_ZEROCROSS_NEG);

  /* Outputs for Enabled SubSystem: '<S269>/Parabola_Pos' incorporates:
   *  EnablePort: '<S299>/Enable'
   */
  /* RelationalOperator: '<S269>/Relational Operator' incorporates:
   *  Constant: '<S273>/Constant'
   *  RelationalOperator: '<S226>/Relational Operator6'
   *  RelationalOperator: '<S267>/Relational Operator5'
   *  Switch: '<S267>/Switch'
   */
  if (tdad_e_filterType == FiltTrqRange_ZEROCROSS_POS) {
    /* If: '<S299>/If' */
    if (swc_TCOO_ARID_DEF.DataTypeConversion5 && rtb_LogicalOperator3) {
      /* Outputs for IfAction SubSystem: '<S299>/EVSportMap' incorporates:
       *  ActionPort: '<S305>/Action Port'
       */
      /* Merge: '<S269>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S305>/1-D Lookup Table'
       */
      tdad_tm_tauFiltPar_s = look1_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, (const float32 *)
         &tdaa_tauParabola_X_VehSpd_kph[0], (const float32 *)
         &tdam_tauParabolaPosEVSprt_Z_s[0], 5U);

      /* End of Outputs for SubSystem: '<S299>/EVSportMap' */
    } else if (swc_TCOO_ARID_DEF.DataTypeConversion5) {
      /* Outputs for IfAction SubSystem: '<S299>/EVMap' incorporates:
       *  ActionPort: '<S304>/Action Port'
       */
      /* Merge: '<S269>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S304>/1-D Lookup Table'
       */
      tdad_tm_tauFiltPar_s = look1_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, (const float32 *)
         &tdaa_tauParabola_X_VehSpd_kph[0], (const float32 *)
         &tdam_tauParabolaPosEV_Z_s[0], 5U);

      /* End of Outputs for SubSystem: '<S299>/EVMap' */
    } else if (rtb_LogicalOperator3) {
      /* Outputs for IfAction SubSystem: '<S299>/SportMap' incorporates:
       *  ActionPort: '<S307>/Action Port'
       */
      /* Merge: '<S269>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S307>/1-D Lookup Table'
       */
      tdad_tm_tauFiltPar_s = look1_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, (const float32 *)
         &tdaa_tauParabola_X_VehSpd_kph[0], (const float32 *)
         &tdam_tauParabolaPosSprt_Z_s[0], 5U);

      /* End of Outputs for SubSystem: '<S299>/SportMap' */
    } else {
      /* Outputs for IfAction SubSystem: '<S299>/NormalMap' incorporates:
       *  ActionPort: '<S306>/Action Port'
       */
      /* Merge: '<S269>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S306>/1-D Lookup Table'
       */
      tdad_tm_tauFiltPar_s = look1_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, (const float32 *)
         &tdaa_tauParabola_X_VehSpd_kph[0], (const float32 *)
         &tdam_tauParabolaPos_Z_s[0], 5U);

      /* End of Outputs for SubSystem: '<S299>/NormalMap' */
    }

    /* End of If: '<S299>/If' */
  }

  /* End of RelationalOperator: '<S269>/Relational Operator' */
  /* End of Outputs for SubSystem: '<S269>/Parabola_Pos' */

  /* Outputs for Enabled SubSystem: '<S269>/Parabola_Neg' incorporates:
   *  EnablePort: '<S298>/Enable'
   */
  /* RelationalOperator: '<S269>/Relational Operator1' incorporates:
   *  Constant: '<S274>/Constant'
   *  RelationalOperator: '<S226>/Relational Operator6'
   *  RelationalOperator: '<S267>/Relational Operator4'
   *  Switch: '<S267>/Switch'
   */
  if (tdad_e_filterType == FiltTrqRange_ZEROCROSS_NEG) {
    /* If: '<S298>/If' */
    if (swc_TCOO_ARID_DEF.DataTypeConversion5 && rtb_LogicalOperator3) {
      /* Outputs for IfAction SubSystem: '<S298>/EVSportMap' incorporates:
       *  ActionPort: '<S301>/Action Port'
       */
      /* Merge: '<S269>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S301>/1-D Lookup Table'
       */
      tdad_tm_tauFiltPar_s = look1_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, (const float32 *)
         &tdaa_tauParabola_X_VehSpd_kph[0], (const float32 *)
         &tdam_tauParabolaNegEVSprt_Z_s[0], 5U);

      /* End of Outputs for SubSystem: '<S298>/EVSportMap' */
    } else if (swc_TCOO_ARID_DEF.DataTypeConversion5) {
      /* Outputs for IfAction SubSystem: '<S298>/EVMap' incorporates:
       *  ActionPort: '<S300>/Action Port'
       */
      /* Merge: '<S269>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S300>/1-D Lookup Table'
       */
      tdad_tm_tauFiltPar_s = look1_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, (const float32 *)
         &tdaa_tauParabola_X_VehSpd_kph[0], (const float32 *)
         &tdam_tauParabolaNegEV_Z_s[0], 5U);

      /* End of Outputs for SubSystem: '<S298>/EVMap' */
    } else if (rtb_LogicalOperator3) {
      /* Outputs for IfAction SubSystem: '<S298>/SportMap' incorporates:
       *  ActionPort: '<S303>/Action Port'
       */
      /* Merge: '<S269>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S303>/1-D Lookup Table'
       */
      tdad_tm_tauFiltPar_s = look1_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, (const float32 *)
         &tdaa_tauParabola_X_VehSpd_kph[0], (const float32 *)
         &tdam_tauParabolaNegSprt_Z_s[0], 5U);

      /* End of Outputs for SubSystem: '<S298>/SportMap' */
    } else {
      /* Outputs for IfAction SubSystem: '<S298>/NormalMap' incorporates:
       *  ActionPort: '<S302>/Action Port'
       */
      /* Merge: '<S269>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S302>/1-D Lookup Table'
       */
      tdad_tm_tauFiltPar_s = look1_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, (const float32 *)
         &tdaa_tauParabola_X_VehSpd_kph[0], (const float32 *)
         &tdam_tauParabolaNeg_Z_s[0], 5U);

      /* End of Outputs for SubSystem: '<S298>/NormalMap' */
    }

    /* End of If: '<S298>/If' */
  }

  /* End of RelationalOperator: '<S269>/Relational Operator1' */
  /* End of Outputs for SubSystem: '<S269>/Parabola_Neg' */

  /* RelationalOperator: '<S227>/Relational Operator2' incorporates:
   *  Constant: '<S273>/Constant'
   *  RelationalOperator: '<S226>/Relational Operator4'
   *  RelationalOperator: '<S267>/Relational Operator5'
   */
  rtb_RelationalOperator2_j = (tdad_e_filterTrqRange ==
    FiltTrqRange_ZEROCROSS_POS);

  /* Switch: '<S227>/Switch7' incorporates:
   *  Switch: '<S227>/Switch8'
   */
  if (rtb_RelationalOperator2_j) {
    /* Switch: '<S227>/Switch7' incorporates:
     *  Constant: '<S318>/Constant2'
     */
    rtb_MinMax4 = tdac_tq_whlZeroRefPos_Nm;
    rtb_Sum2 = rtb_Sum1;
  } else {
    /* Switch: '<S227>/Switch7' incorporates:
     *  Constant: '<S318>/Constant3'
     */
    rtb_MinMax4 = tdac_tq_whlZeroRefNeg_Nm;
  }

  /* End of Switch: '<S227>/Switch7' */

  /* Sum: '<S227>/Sum1' incorporates:
   *  Switch: '<S227>/Switch8'
   */
  rtb_Sum1_e = rtb_MinMax4 - rtb_Sum2;

  /* Outputs for Enabled SubSystem: '<S227>/ParabolaLimit' incorporates:
   *  EnablePort: '<S245>/Enable'
   */
  /* Logic: '<S227>/Logical Operator2' incorporates:
   *  Logic: '<S227>/Logical Operator3'
   *  RelationalOperator: '<S240>/FixPt Relational Operator'
   *  RelationalOperator: '<S241>/FixPt Relational Operator'
   *  UnitDelay: '<S240>/Delay Input1'
   *  UnitDelay: '<S241>/Delay Input1'
   *
   * Block description for '<S240>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S241>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (rtb_RelationalOperator6_ku || rtb_RelationalOperator1_f) {
    /* Outputs for Enabled SubSystem: '<S245>/CalcGain' incorporates:
     *  EnablePort: '<S247>/Enable'
     */
    if (((sint32)rtb_RelationalOperator6_ku > (sint32)
         swc_TCOO_ARID_DEF.DelayInput1_DSTATE_f) || ((sint32)
         rtb_RelationalOperator1_f > (sint32)
         swc_TCOO_ARID_DEF.DelayInput1_DSTATE_n)) {
      /* If: '<S249>/If' incorporates:
       *  Constant: '<S249>/Constant'
       */
      if (rtb_Sum1_e >= 0.0F) {
        /* Outputs for IfAction SubSystem: '<S249>/pos' incorporates:
         *  ActionPort: '<S251>/Action Port'
         */
        swc_TCOO_pos(rtb_Sum1_e, &rtb_Merge);

        /* End of Outputs for SubSystem: '<S249>/pos' */
      } else {
        /* Outputs for IfAction SubSystem: '<S249>/neg' incorporates:
         *  ActionPort: '<S250>/Action Port'
         */
        swc_TCOO_neg(rtb_Sum1_e, &rtb_Merge);

        /* End of Outputs for SubSystem: '<S249>/neg' */
      }

      /* End of If: '<S249>/If' */

      /* Product: '<S247>/Product' incorporates:
       *  Product: '<S247>/Product1'
       */
      swc_TCOO_ARID_DEF.Product = rtb_Merge / (tdad_tm_tauFiltPar_s *
        tdad_tm_tauFiltPar_s);
    }

    /* End of Outputs for SubSystem: '<S245>/CalcGain' */

    /* MinMax: '<S248>/MinMax1' incorporates:
     *  Constant: '<S248>/Constant2'
     *  Logic: '<S227>/Logical Operator3'
     *  RelationalOperator: '<S240>/FixPt Relational Operator'
     *  RelationalOperator: '<S241>/FixPt Relational Operator'
     *  UnitDelay: '<S240>/Delay Input1'
     *  UnitDelay: '<S241>/Delay Input1'
     *
     * Block description for '<S240>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S241>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_Sum2 = fmaxf(swc_TCOO_ARID_DEF.Product, 0.1F);

    /* Sum: '<S248>/Sum1' incorporates:
     *  UnitDelay: '<S220>/Unit Delay4'
     */
    rtb_Sum1_b = swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b - rtb_MinMax4;

    /* If: '<S252>/If' incorporates:
     *  Constant: '<S252>/Constant'
     */
    if (rtb_Sum1_b >= 0.0F) {
      /* Outputs for IfAction SubSystem: '<S252>/pos' incorporates:
       *  ActionPort: '<S255>/Action Port'
       */
      swc_TCOO_pos(rtb_Sum1_b, &rtb_Merge_d);

      /* End of Outputs for SubSystem: '<S252>/pos' */
    } else {
      /* Outputs for IfAction SubSystem: '<S252>/neg' incorporates:
       *  ActionPort: '<S254>/Action Port'
       */
      swc_TCOO_neg(rtb_Sum1_b, &rtb_Merge_d);

      /* End of Outputs for SubSystem: '<S252>/neg' */
    }

    /* End of If: '<S252>/If' */

    /* Merge: '<S253>/Merge' incorporates:
     *  Product: '<S248>/Product'
     *  Sqrt: '<S248>/Sqrt'
     */
    rtb_Merge_d /= rtb_Sum2;
    rtb_Merge_d = sqrtf(rtb_Merge_d);

    /* Signum: '<S248>/Sign' */
    if (rtb_Sum1_b < 0.0F) {
      rtb_Sum1 = -1.0F;
    } else {
      rtb_Sum1 = (float32)(rtb_Sum1_b > 0.0F);
    }

    /* Switch: '<S227>/Switch5' incorporates:
     *  Constant: '<S227>/Constant6'
     *  Gain: '<S227>/Gain'
     */
    if (rtb_RelationalOperator2_j) {
      rtb_Switch2_i5 = ((float32)TDA_TASK_INTERVAL_S);
    } else {
      rtb_Switch2_i5 = (-1.0F) * ((float32)TDA_TASK_INTERVAL_S);
    }

    /* Sum: '<S248>/Sum2' incorporates:
     *  Product: '<S248>/Product2'
     *  Signum: '<S248>/Sign'
     *  Switch: '<S227>/Switch5'
     */
    rtb_Sum2_c = rtb_Sum1 * rtb_Merge_d + rtb_Switch2_i5;

    /* If: '<S253>/If' incorporates:
     *  Constant: '<S253>/Constant'
     */
    if (rtb_Sum2_c >= 0.0F) {
      /* Outputs for IfAction SubSystem: '<S253>/pos' incorporates:
       *  ActionPort: '<S257>/Action Port'
       */
      swc_TCOO_pos(rtb_Sum2_c, &rtb_Merge_d);

      /* End of Outputs for SubSystem: '<S253>/pos' */
    } else {
      /* Outputs for IfAction SubSystem: '<S253>/neg' incorporates:
       *  ActionPort: '<S256>/Action Port'
       */
      swc_TCOO_neg(rtb_Sum2_c, &rtb_Merge_d);

      /* End of Outputs for SubSystem: '<S253>/neg' */
    }

    /* End of If: '<S253>/If' */

    /* Sum: '<S248>/Sum3' incorporates:
     *  Product: '<S248>/Product1'
     */
    swc_TCOO_ARID_DEF.Sum3 = rtb_Sum2_c * rtb_Merge_d * rtb_Sum2 + rtb_MinMax4;
  }

  /* End of Logic: '<S227>/Logical Operator2' */
  /* End of Outputs for SubSystem: '<S227>/ParabolaLimit' */

  /* Switch: '<S227>/Switch4' incorporates:
   *  Switch: '<S227>/Switch3'
   */
  if (rtb_RelationalOperator2_j) {
    /* MinMax: '<S204>/MinMax4' */
    rtb_MinMax4 = rtb_Sum;

    /* MinMax: '<S315>/MinMax3' incorporates:
     *  Constant: '<S227>/Constant1'
     */
    rtb_MinMax3_n = ((float32)WHL_TRQ_MIN);
  } else {
    /* MinMax: '<S204>/MinMax4' incorporates:
     *  Constant: '<S227>/Constant2'
     */
    rtb_MinMax4 = ((float32)WHL_TRQ_MAX);

    /* MinMax: '<S315>/MinMax3' */
    rtb_MinMax3_n = rtb_Sum3;
  }

  /* End of Switch: '<S227>/Switch4' */

  /* Switch: '<S227>/Switch2' incorporates:
   *  RelationalOperator: '<S246>/LowerRelop1'
   *  RelationalOperator: '<S246>/UpperRelop'
   *  Switch: '<S227>/Switch1'
   *  Switch: '<S246>/Switch'
   *  Switch: '<S246>/Switch2'
   */
  if (rtb_RelationalOperator6_ku) {
    /* Switch: '<S227>/Switch2' incorporates:
     *  MinMax: '<S227>/MinMax'
     */
    tdad_tq_whlDemFiltPar_Nm = fminf(swc_TCOO_ARID_DEF.Sum3,
      tdad_tq_whlDemUnfilt_Nm);
  } else if (rtb_RelationalOperator1_f) {
    /* Switch: '<S227>/Switch1' incorporates:
     *  MinMax: '<S227>/MinMax1'
     *  Switch: '<S227>/Switch2'
     */
    tdad_tq_whlDemFiltPar_Nm = fmaxf(tdad_tq_whlDemUnfilt_Nm,
      swc_TCOO_ARID_DEF.Sum3);
  } else if (tdad_tq_whlDemUnfilt_Nm > rtb_MinMax4) {
    /* Switch: '<S246>/Switch2' incorporates:
     *  Switch: '<S227>/Switch1'
     *  Switch: '<S227>/Switch2'
     */
    tdad_tq_whlDemFiltPar_Nm = rtb_MinMax4;
  } else if (tdad_tq_whlDemUnfilt_Nm < rtb_MinMax3_n) {
    /* Switch: '<S246>/Switch' incorporates:
     *  Switch: '<S227>/Switch1'
     *  Switch: '<S227>/Switch2'
     */
    tdad_tq_whlDemFiltPar_Nm = rtb_MinMax3_n;
  } else {
    /* Switch: '<S227>/Switch2' incorporates:
     *  Switch: '<S227>/Switch1'
     *  Switch: '<S246>/Switch'
     */
    tdad_tq_whlDemFiltPar_Nm = tdad_tq_whlDemUnfilt_Nm;
  }

  /* End of Switch: '<S227>/Switch2' */

  /* RelationalOperator: '<S228>/Relational Operator6' incorporates:
   *  Constant: '<S275>/Constant'
   *  RelationalOperator: '<S226>/Relational Operator6'
   *  RelationalOperator: '<S267>/Relational Operator2'
   *  Switch: '<S267>/Switch'
   */
  rtb_RelationalOperator6_f = (tdad_e_filterType == FiltTrqRange_POWER_POS);

  /* Outputs for Enabled SubSystem: '<S270>/Power_Pos' incorporates:
   *  EnablePort: '<S309>/Enable'
   */
  /* RelationalOperator: '<S270>/Relational Operator' incorporates:
   *  Constant: '<S275>/Constant'
   *  RelationalOperator: '<S226>/Relational Operator6'
   *  RelationalOperator: '<S267>/Relational Operator2'
   *  Switch: '<S267>/Switch'
   */
  if (tdad_e_filterType == FiltTrqRange_POWER_POS) {
    /* If: '<S309>/If' */
    if (swc_TCOO_ARID_DEF.DataTypeConversion5 && rtb_LogicalOperator3) {
      /* Outputs for IfAction SubSystem: '<S309>/EVSportMap' incorporates:
       *  ActionPort: '<S311>/Action Port'
       */
      /* Merge: '<S309>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S311>/2-D Lookup Table4'
       *  Switch: '<S329>/Switch2'
       */
      tdad_tm_tauFilt2nd_s = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_tau2nd_X_VehSpd_kph[0], (const float32 *)
         &tdaa_tau2nd_Y_TgtTrq_Nm[0], (const float32 *)
         &tdam_tau2ndPwrPosEVSprt_Z_s[0], swc_TCOO_ConstP.pooled14, 6U);

      /* Merge: '<S309>/Merge1' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S311>/2-D Lookup Table8'
       *  Switch: '<S329>/Switch2'
       */
      tdad_fact_dampFilt2nd = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_dmp2nd_X_VehSpd_kph[0], (const float32 *)
         &tdaa_dmp2nd_Y_TgtTrq_Nm[0], (const float32 *)
         &tdam_dmp2ndPwrPosEVSprt_Z_fact[0], swc_TCOO_ConstP.pooled14, 6U);

      /* End of Outputs for SubSystem: '<S309>/EVSportMap' */
    } else if (swc_TCOO_ARID_DEF.DataTypeConversion5) {
      /* Outputs for IfAction SubSystem: '<S309>/EVMap' incorporates:
       *  ActionPort: '<S310>/Action Port'
       */
      /* Merge: '<S309>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S310>/2-D Lookup Table3'
       *  Switch: '<S329>/Switch2'
       */
      tdad_tm_tauFilt2nd_s = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_tau2nd_X_VehSpd_kph[0], (const float32 *)
         &tdaa_tau2nd_Y_TgtTrq_Nm[0], (const float32 *)&tdam_tau2ndPwrPosEV_Z_s
         [0], swc_TCOO_ConstP.pooled14, 6U);

      /* Merge: '<S309>/Merge1' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S310>/2-D Lookup Table7'
       *  Switch: '<S329>/Switch2'
       */
      tdad_fact_dampFilt2nd = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_dmp2nd_X_VehSpd_kph[0], (const float32 *)
         &tdaa_dmp2nd_Y_TgtTrq_Nm[0], (const float32 *)
         &tdam_dmp2ndPwrPosEV_Z_fact[0], swc_TCOO_ConstP.pooled14, 6U);

      /* End of Outputs for SubSystem: '<S309>/EVMap' */
    } else if (rtb_LogicalOperator3) {
      /* Outputs for IfAction SubSystem: '<S309>/SportMap' incorporates:
       *  ActionPort: '<S313>/Action Port'
       */
      /* Merge: '<S309>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S313>/2-D Lookup Table2'
       *  Switch: '<S329>/Switch2'
       */
      tdad_tm_tauFilt2nd_s = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_tau2nd_X_VehSpd_kph[0], (const float32 *)
         &tdaa_tau2nd_Y_TgtTrq_Nm[0], (const float32 *)
         &tdam_tau2ndPwrPosSprt_Z_s[0], swc_TCOO_ConstP.pooled14, 6U);

      /* Merge: '<S309>/Merge1' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S313>/2-D Lookup Table6'
       *  Switch: '<S329>/Switch2'
       */
      tdad_fact_dampFilt2nd = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_dmp2nd_X_VehSpd_kph[0], (const float32 *)
         &tdaa_dmp2nd_Y_TgtTrq_Nm[0], (const float32 *)
         &tdam_dmp2ndPwrPosSprt_Z_fact[0], swc_TCOO_ConstP.pooled14, 6U);

      /* End of Outputs for SubSystem: '<S309>/SportMap' */
    } else {
      /* Outputs for IfAction SubSystem: '<S309>/NormalMap' incorporates:
       *  ActionPort: '<S312>/Action Port'
       */
      /* Merge: '<S309>/Merge' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S312>/2-D Lookup Table1'
       *  Switch: '<S329>/Switch2'
       */
      tdad_tm_tauFilt2nd_s = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_tau2nd_X_VehSpd_kph[0], (const float32 *)
         &tdaa_tau2nd_Y_TgtTrq_Nm[0], (const float32 *)&tdam_tau2ndPwrPos_Z_s[0],
         swc_TCOO_ConstP.pooled14, 6U);

      /* Merge: '<S309>/Merge1' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion4'
       *  Lookup_n-D: '<S312>/2-D Lookup Table5'
       *  Switch: '<S329>/Switch2'
       */
      tdad_fact_dampFilt2nd = look2_iflf_binlcapw
        (swc_TCOO_ARID_DEF.DataTypeConversion4, tdad_tq_whlDemUnfilt_Nm, (const
          float32 *)&tdaa_dmp2nd_X_VehSpd_kph[0], (const float32 *)
         &tdaa_dmp2nd_Y_TgtTrq_Nm[0], (const float32 *)
         &tdam_dmp2ndPwrPos_Z_fact[0], swc_TCOO_ConstP.pooled14, 6U);

      /* End of Outputs for SubSystem: '<S309>/NormalMap' */
    }

    /* End of If: '<S309>/If' */
  }

  /* End of RelationalOperator: '<S270>/Relational Operator' */
  /* End of Outputs for SubSystem: '<S270>/Power_Pos' */

  /* Logic: '<S228>/Logical Operator1' incorporates:
   *  RelationalOperator: '<S228>/Relational Operator4'
   *  RelationalOperator: '<S258>/FixPt Relational Operator'
   *  UnitDelay: '<S220>/Unit Delay4'
   *  UnitDelay: '<S258>/Delay Input1'
   *
   * Block description for '<S258>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator3 = (((sint32)rtb_RelationalOperator6_f > (sint32)
    swc_TCOO_ARID_DEF.DelayInput1_DSTATE_k) || (tdad_tq_whlDemUnfilt_Nm <=
    swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b));

  /* Outputs for Enabled SubSystem: '<S228>/Filter' incorporates:
   *  EnablePort: '<S260>/Enable'
   */
  if (rtb_RelationalOperator6_f) {
    if (!swc_TCOO_ARID_DEF.Filter_MODE) {
      /* InitializeConditions for UnitDelay: '<S261>/Unit Delay' */
      swc_TCOO_ARID_DEF.UnitDelay_DSTATE_n = 0.0F;

      /* InitializeConditions for UnitDelay: '<S262>/Unit Delay' */
      swc_TCOO_ARID_DEF.UnitDelay_DSTATE_l = 0.0F;
      swc_TCOO_ARID_DEF.Filter_MODE = true;
    }

    /* MinMax: '<S260>/MinMax' incorporates:
     *  Constant: '<S228>/Constant1'
     */
    rtb_Sum = fmaxf(((float32)TDA_TASK_INTERVAL_S), tdad_tm_tauFilt2nd_s);

    /* Switch: '<S261>/Switch' */
    if (rtb_LogicalOperator3) {
      /* Switch: '<S262>/Switch' incorporates:
       *  Constant: '<S228>/Constant1'
       *  Gain: '<S260>/Gain3'
       *  Product: '<S260>/Product2'
       *  Product: '<S260>/Product4'
       *  Product: '<S260>/Product5'
       *  Sum: '<S260>/Sum2'
       *  Sum: '<S260>/Sum6'
       *  UnitDelay: '<S220>/Unit Delay4'
       */
      rtb_Sum3 = (tdad_tq_whlDemUnfilt_Nm -
                  swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b) / rtb_Sum * ((float32)
        TDA_TASK_INTERVAL_S) + 2.0F * tdad_fact_dampFilt2nd *
        swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b;
    } else {
      /* Switch: '<S262>/Switch' incorporates:
       *  Constant: '<S228>/Constant1'
       *  Product: '<S260>/Product5'
       *  Product: '<S261>/Product'
       *  Sum: '<S261>/Sum'
       *  UnitDelay: '<S261>/Unit Delay'
       */
      rtb_Sum3 = rtb_MinMax4_i_tmp_0 / rtb_Sum * ((float32)TDA_TASK_INTERVAL_S)
        + swc_TCOO_ARID_DEF.UnitDelay_DSTATE_n;
    }

    /* End of Switch: '<S261>/Switch' */

    /* Update for UnitDelay: '<S261>/Unit Delay' incorporates:
     *  DataTypeConversion: '<S261>/Data Type Conversion'
     */
    swc_TCOO_ARID_DEF.UnitDelay_DSTATE_n = rtb_Sum3;

    /* Switch: '<S262>/Switch' */
    if (rtb_LogicalOperator3) {
      /* DataTypeConversion: '<S262>/Data Type Conversion' incorporates:
       *  Constant: '<S228>/Constant1'
       *  DataTypeConversion: '<S261>/Data Type Conversion'
       *  Gain: '<S260>/Gain1'
       *  Product: '<S260>/Product1'
       *  Product: '<S260>/Product3'
       *  Product: '<S260>/Product6'
       *  Sum: '<S260>/Sum3'
       *  Sum: '<S260>/Sum7'
       *  Switch: '<S262>/Switch'
       *  UnitDelay: '<S220>/Unit Delay4'
       */
      swc_TCOO_ARID_DEF.DataTypeConversion = (rtb_Sum3 - 2.0F *
        tdad_fact_dampFilt2nd * swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b) / rtb_Sum
        * ((float32)TDA_TASK_INTERVAL_S) + swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b;
    } else {
      /* DataTypeConversion: '<S262>/Data Type Conversion' incorporates:
       *  Constant: '<S228>/Constant1'
       *  DataTypeConversion: '<S261>/Data Type Conversion'
       *  Gain: '<S260>/Gain1'
       *  Product: '<S260>/Product1'
       *  Product: '<S260>/Product6'
       *  Product: '<S262>/Product'
       *  Sum: '<S260>/Sum7'
       *  Sum: '<S262>/Sum'
       *  Switch: '<S262>/Switch'
       *  UnitDelay: '<S220>/Unit Delay4'
       *  UnitDelay: '<S262>/Unit Delay'
       */
      swc_TCOO_ARID_DEF.DataTypeConversion = (rtb_Sum3 - 2.0F *
        tdad_fact_dampFilt2nd * swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b) / rtb_Sum
        * ((float32)TDA_TASK_INTERVAL_S) + swc_TCOO_ARID_DEF.UnitDelay_DSTATE_l;
    }

    /* End of Switch: '<S262>/Switch' */

    /* Update for UnitDelay: '<S262>/Unit Delay' */
    swc_TCOO_ARID_DEF.UnitDelay_DSTATE_l = swc_TCOO_ARID_DEF.DataTypeConversion;

    /* Switch: '<S228>/Switch2' incorporates:
     *  MinMax: '<S228>/MinMax'
     */
    tdad_tq_whlDemFilt2nd_Nm = fminf(tdad_tq_whlDemUnfilt_Nm,
      swc_TCOO_ARID_DEF.DataTypeConversion);
  } else {
    swc_TCOO_ARID_DEF.Filter_MODE = false;

    /* Switch: '<S228>/Switch2' */
    tdad_tq_whlDemFilt2nd_Nm = tdad_tq_whlDemUnfilt_Nm;
  }

  /* End of Outputs for SubSystem: '<S228>/Filter' */

  /* Switch: '<S229>/Switch1' incorporates:
   *  Constant: '<S229>/Constant2'
   *  Constant: '<S229>/Constant4'
   *  Constant: '<S273>/Constant'
   *  Constant: '<S274>/Constant'
   *  Constant: '<S275>/Constant'
   *  Logic: '<S229>/Logical Operator1'
   *  RelationalOperator: '<S226>/Relational Operator4'
   *  RelationalOperator: '<S229>/Relational Operator2'
   *  RelationalOperator: '<S229>/Relational Operator4'
   *  RelationalOperator: '<S229>/Relational Operator5'
   *  RelationalOperator: '<S267>/Relational Operator2'
   *  RelationalOperator: '<S267>/Relational Operator4'
   *  RelationalOperator: '<S267>/Relational Operator5'
   *  Switch: '<S229>/Switch2'
   */
  if (tdad_e_filterTrqRange == FiltTrqRange_POWER_POS) {
    tmp = ((uint8)3U);
  } else if ((tdad_e_filterTrqRange == FiltTrqRange_ZEROCROSS_POS) ||
             (tdad_e_filterTrqRange == FiltTrqRange_ZEROCROSS_NEG)) {
    /* Switch: '<S229>/Switch2' incorporates:
     *  Constant: '<S229>/Constant3'
     */
    tmp = ((uint8)2U);
  } else {
    tmp = ((uint8)1U);
  }

  /* MultiPortSwitch: '<S220>/Multiport Switch' incorporates:
   *  Switch: '<S229>/Switch1'
   */
  switch (tmp) {
   case 1:
    /* MultiPortSwitch: '<S220>/Multiport Switch' */
    rtb_Sum = tdad_tq_whlDemFilt1st_Nm;
    break;

   case 2:
    /* MultiPortSwitch: '<S220>/Multiport Switch' */
    rtb_Sum = tdad_tq_whlDemFiltPar_Nm;
    break;

   default:
    /* MultiPortSwitch: '<S220>/Multiport Switch' */
    rtb_Sum = tdad_tq_whlDemFilt2nd_Nm;
    break;
  }

  /* End of MultiPortSwitch: '<S220>/Multiport Switch' */

  /* Switch: '<S230>/Switch2' incorporates:
   *  RelationalOperator: '<S230>/LowerRelop1'
   *  RelationalOperator: '<S230>/UpperRelop'
   *  Switch: '<S230>/Switch'
   */
  if (rtb_Sum > rtb_MinMax3_b_tmp) {
    /* Switch: '<S230>/Switch2' */
    tdad_tq_whlDemFilt_Nm = rtb_MinMax3_b_tmp;
  } else if (rtb_Sum < rtb_MinMax4_i_tmp) {
    /* Switch: '<S230>/Switch' incorporates:
     *  Switch: '<S230>/Switch2'
     */
    tdad_tq_whlDemFilt_Nm = rtb_MinMax4_i_tmp;
  } else {
    /* Switch: '<S230>/Switch2' incorporates:
     *  Switch: '<S230>/Switch'
     */
    tdad_tq_whlDemFilt_Nm = rtb_Sum;
  }

  /* End of Switch: '<S230>/Switch2' */

  /* MinMax: '<S204>/MinMax3' incorporates:
   *  Constant: '<S222>/Constant4'
   *  Constant: '<S315>/step_time1'
   *  Constant: '<S315>/step_time2'
   *  MinMax: '<S315>/MinMax4'
   *  MinMax: '<S315>/MinMax5'
   *  Sum: '<S315>/Sum2'
   */
  rtb_Sum = fmaxf(tdad_tq_whlDemUnfilt_Nm + fminf(tdac_tq_whlMinLimOffset_Nm,
    0.0F), ((float32)WHL_TRQ_MIN));

  /* MinMax: '<S315>/MinMax2' incorporates:
   *  Constant: '<S222>/Constant5'
   *  Constant: '<S222>/Constant6'
   *  Constant: '<S315>/step_time6'
   *  MinMax: '<S315>/MinMax1'
   *  MinMax: '<S315>/MinMax3'
   *  Product: '<S315>/Product1'
   *  Sum: '<S315>/Sum1'
   *  Sum: '<S315>/Sum5'
   *  UnitDelay: '<S315>/UnitDelay1'
   */
  tdad_tq_whlFiltMin_Nm = fminf(rtb_Sum, fminf(rtb_Sum -
    swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_i, fmaxf(0.0F, ((float32)
    TDA_TASK_INTERVAL_S) * tdac_dtq_whlMinLimIncGrad_Nmps)) +
    swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_i);

  /* Switch: '<S225>/Switch2' incorporates:
   *  RelationalOperator: '<S225>/LowerRelop1'
   *  RelationalOperator: '<S225>/UpperRelop'
   *  Switch: '<S225>/Switch'
   */
  if (tdad_tq_whlDemFilt_Nm > tdad_tq_whlFiltMax_Nm) {
    /* Switch: '<S225>/Switch2' */
    swctcoo_tdad_tq_whlDemUnAdc_Nm = tdad_tq_whlFiltMax_Nm;
  } else if (tdad_tq_whlDemFilt_Nm < tdad_tq_whlFiltMin_Nm) {
    /* Switch: '<S225>/Switch' incorporates:
     *  Switch: '<S225>/Switch2'
     */
    swctcoo_tdad_tq_whlDemUnAdc_Nm = tdad_tq_whlFiltMin_Nm;
  } else {
    /* Switch: '<S225>/Switch2' incorporates:
     *  Switch: '<S225>/Switch'
     */
    swctcoo_tdad_tq_whlDemUnAdc_Nm = tdad_tq_whlDemFilt_Nm;
  }

  /* End of Switch: '<S225>/Switch2' */

  /* Switch: '<S204>/Switch8' incorporates:
   *  Constant: '<S204>/Constant12'
   *  Constant: '<S212>/Constant'
   *  Constant: '<S213>/Constant'
   *  Logic: '<S204>/Logical Operator10'
   *  Logic: '<S204>/Logical Operator6'
   *  RelationalOperator: '<S212>/Compare'
   *  RelationalOperator: '<S213>/Compare'
   */
  if (((swc_TCOO_ARID_DEF.DataTypeConversion190 == 0.0) ||
       (swc_TCOO_ARID_DEF.DataTypeConversion190 == 1.0)) &&
      swctcoo_tdac_b_adcOvrCtlPmt) {
    /* Switch: '<S204>/Switch9' incorporates:
     *  Constant: '<S204>/Constant17'
     *  Constant: '<S211>/Constant'
     *  RelationalOperator: '<S211>/Compare'
     */
    if (swc_TCOO_ARID_DEF.DataTypeConversion171 == 1.0) {
      rtb_Sum1 = swc_TCOO_ARID_DEF.DataTypeConversion179;
    } else {
      rtb_Sum1 = ((float32)TRQ_ZERO);
    }

    /* End of Switch: '<S204>/Switch9' */
  } else {
    rtb_Sum1 = swctcoo_tdad_tq_whlDemUnAdc_Nm;
  }

  /* MinMax: '<S204>/MinMax2' incorporates:
   *  Switch: '<S204>/Switch8'
   */
  rtb_Sum = fminf(rtb_Sum1, swc_TCOO_ARID_DEF.DataTypeConversion54);

  /* Switch: '<S204>/Switch4' incorporates:
   *  Constant: '<S204>/Constant1'
   *  RelationalOperator: '<S216>/LowerRelop1'
   *  RelationalOperator: '<S216>/UpperRelop'
   *  Switch: '<S216>/Switch'
   *  Switch: '<S216>/Switch2'
   */
  if (swctcoo_tdac_b_whlDemAdcCtl_ovrdflg) {
    /* Switch: '<S204>/Switch4' incorporates:
     *  Constant: '<S204>/Constant5'
     */
    swctcoo_tdad_tq_whlDemAdcCtl_Nm = swctcoo_tdac_tq_whlDemAdcCtl_ovrdval;
  } else if (rtb_Sum > rtb_MinMax3_b_tmp) {
    /* Switch: '<S216>/Switch2' incorporates:
     *  Switch: '<S204>/Switch4'
     */
    swctcoo_tdad_tq_whlDemAdcCtl_Nm = rtb_MinMax3_b_tmp;
  } else if (rtb_Sum < rtb_MinMax4_i_tmp) {
    /* Switch: '<S216>/Switch' incorporates:
     *  Switch: '<S204>/Switch4'
     */
    swctcoo_tdad_tq_whlDemAdcCtl_Nm = rtb_MinMax4_i_tmp;
  } else {
    /* Switch: '<S204>/Switch4' incorporates:
     *  Switch: '<S216>/Switch'
     */
    swctcoo_tdad_tq_whlDemAdcCtl_Nm = rtb_Sum;
  }

  /* End of Switch: '<S204>/Switch4' */

  /* Switch: '<S204>/Switch7' incorporates:
   *  Constant: '<S204>/Constant11'
   *  Constant: '<S204>/Constant9'
   */
  if (swctcoo_tdac_b_adcCtrlSts_ovrdflg) {
    swctcoo_tdad_st_adcCtrlSts = swctcoo_tdac_st_adcCtrlSts_ovrdval;
  } else {
    BrakePedalStatus tmp_0;

    /* RelationalOperator: '<S204>/Relational Operator1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion167'
     *  RelationalOperator: '<S204>/Relational Operator2'
     *  Switch: '<S204>/Switch5'
     */
    tmp_0 = swc_TCOO_ARID_DEF.DataTypeConversion167;

    /* Switch: '<S204>/Switch5' incorporates:
     *  Constant: '<S204>/Constant13'
     *  Constant: '<S204>/Constant14'
     *  Constant: '<S209>/Constant'
     *  Constant: '<S210>/Constant'
     *  Constant: '<S214>/Constant'
     *  Logic: '<S204>/Logical Operator11'
     *  Logic: '<S204>/Logical Operator13'
     *  RelationalOperator: '<S204>/Relational Operator1'
     *  RelationalOperator: '<S204>/Relational Operator2'
     *  RelationalOperator: '<S209>/Compare'
     *  RelationalOperator: '<S210>/Compare'
     *  Switch: '<S204>/Switch6'
     */
    if ((swc_TCOO_ARID_DEF.DataTypeConversion190 == 0.0) && (tmp_0 !=
         BrakePedalStatus_PRESSED) && swctcoo_tdac_b_adcOvrCtlPmt) {
      /* Switch: '<S204>/Switch5' incorporates:
       *  Constant: '<S204>/Constant7'
       */
      swctcoo_tdad_st_adcCtrlSts = ((uint8)0U);
    } else if ((swc_TCOO_ARID_DEF.DataTypeConversion190 == 1.0) && (tmp_0 !=
                BrakePedalStatus_PRESSED) && swctcoo_tdac_b_adcOvrCtlPmt) {
      /* Switch: '<S204>/Switch6' incorporates:
       *  Constant: '<S204>/Constant10'
       *  Switch: '<S204>/Switch5'
       */
      swctcoo_tdad_st_adcCtrlSts = ((uint8)1U);
    } else {
      /* Switch: '<S204>/Switch5' incorporates:
       *  Constant: '<S204>/Constant8'
       *  Switch: '<S204>/Switch6'
       */
      swctcoo_tdad_st_adcCtrlSts = ((uint8)2U);
    }
  }

  /* End of Switch: '<S204>/Switch7' */

  /* Switch: '<S206>/Switch2' incorporates:
   *  Constant: '<S217>/Constant'
   *  Constant: '<S219>/Constant'
   *  Logic: '<S206>/Logical Operator2'
   *  Logic: '<S206>/Logical Operator6'
   *  RelationalOperator: '<S217>/Compare'
   *  RelationalOperator: '<S219>/Compare'
   */
  if (((swctcoo_tdad_st_adcCtrlSts == ((uint8)0U)) ||
       (swctcoo_tdad_st_adcCtrlSts == ((uint8)1U))) &&
      tdad_b_disEnbDrvFilter_tmp) {
    /* Switch: '<S206>/Switch5' incorporates:
     *  Constant: '<S206>/Constant1'
     *  Constant: '<S218>/Constant'
     *  Logic: '<S206>/Logical Operator1'
     *  RelationalOperator: '<S218>/Compare'
     */
    if ((swctcoo_dtdd_b_ehbMbRgnOvrCtl == true) &&
        swctcoo_tdac_b_ehbOvrCtlWhlDrgPmt) {
      /* Switch: '<S206>/Switch2' incorporates:
       *  MinMax: '<S206>/MinMax2'
       *  Switch: '<S206>/Switch5'
       */
      tdad_tq_whlDem_Nm = fminf(swctcoo_tdad_tq_whlDemUnAdc_Nm,
        swctcoo_tdad_tq_whlDemAdcCtl_Nm);
    } else {
      /* Switch: '<S206>/Switch2' incorporates:
       *  Switch: '<S206>/Switch5'
       */
      tdad_tq_whlDem_Nm = swctcoo_tdad_tq_whlDemAdcCtl_Nm;
    }

    /* End of Switch: '<S206>/Switch5' */
  } else {
    /* Switch: '<S206>/Switch2' */
    tdad_tq_whlDem_Nm = swctcoo_tdad_tq_whlDemUnAdc_Nm;
  }

  /* End of Switch: '<S206>/Switch2' */

  /* Update for UnitDelay: '<S314>/UnitDelay1' */
  swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_f = tdad_tq_whlFiltMax_Nm;

  /* Update for UnitDelay: '<S220>/Unit Delay4' */
  swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_b = tdad_tq_whlDemFilt_Nm;

  /* Update for UnitDelay: '<S316>/Unit Delay4' */
  swc_TCOO_ARID_DEF.UnitDelay4_DSTATE_h = tdad_tq_whlDemUnfilt_Nm;

  /* Update for UnitDelay: '<S231>/Delay Input1'
   *
   * Block description for '<S231>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_TCOO_ARID_DEF.DelayInput1_DSTATE_i = rtb_LogicalOperator7_b;

  /* Update for UnitDelay: '<S240>/Delay Input1'
   *
   * Block description for '<S240>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_TCOO_ARID_DEF.DelayInput1_DSTATE_f = rtb_RelationalOperator6_ku;

  /* Update for UnitDelay: '<S241>/Delay Input1'
   *
   * Block description for '<S241>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_TCOO_ARID_DEF.DelayInput1_DSTATE_n = rtb_RelationalOperator1_f;

  /* Update for UnitDelay: '<S258>/Delay Input1'
   *
   * Block description for '<S258>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_TCOO_ARID_DEF.DelayInput1_DSTATE_k = rtb_RelationalOperator6_f;

  /* Update for UnitDelay: '<S315>/UnitDelay1' */
  swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_i = tdad_tq_whlFiltMin_Nm;
}

/* Output and update for atomic system: '<S8>/Front_Rear_Axle_Torque_Distribution' */
static void Front_Rear_Axle_Torque_Distribu(void)
{
  float32 rtb_MinMax3_f3;
  float32 rtb_MinMax4;

  /* MinMax: '<S330>/MinMax3' incorporates:
   *  Constant: '<S330>/Constant3'
   */
  rtb_MinMax3_f3 = fminf(swc_TCOO_ARID_DEF.DataTypeConversion47, ((float32)
    TRQ_ZERO));

  /* MinMax: '<S330>/MinMax4' incorporates:
   *  Constant: '<S330>/Constant2'
   */
  rtb_MinMax4 = fmaxf(((float32)TRQ_ZERO),
                      swc_TCOO_ARID_DEF.DataTypeConversion26);

  /* Switch: '<S334>/Switch2' incorporates:
   *  RelationalOperator: '<S334>/LowerRelop1'
   *  RelationalOperator: '<S334>/UpperRelop'
   *  Switch: '<S334>/Switch'
   */
  if (tdad_tq_whlDem_Nm > rtb_MinMax4) {
    /* Switch: '<S334>/Switch2' */
    tqdd_tq_axle2TqDem_Nm = rtb_MinMax4;
  } else if (tdad_tq_whlDem_Nm < rtb_MinMax3_f3) {
    /* Switch: '<S334>/Switch' incorporates:
     *  Switch: '<S334>/Switch2'
     */
    tqdd_tq_axle2TqDem_Nm = rtb_MinMax3_f3;
  } else {
    /* Switch: '<S334>/Switch2' incorporates:
     *  Switch: '<S334>/Switch'
     */
    tqdd_tq_axle2TqDem_Nm = tdad_tq_whlDem_Nm;
  }

  /* End of Switch: '<S334>/Switch2' */
}

/* System initialize for atomic system: '<S335>/SwitchRampEADShiftIntvn' */
static void swc_TCOO_switch_ramp_Init(float32 *rty_y, boolean *rty_RampOn)
{
  /* SystemInitialize for Chart: '<S433>/Chart' */
  *rty_y = 0.0F;
  *rty_RampOn = false;
}

/* Output and update for atomic system: '<S335>/SwitchRampEADShiftIntvn' */
static void swc_TCOO_switch_ramp(float32 rtu_u1, boolean rtu_sw, float32 rtu_u2,
  float32 rtu_up, float32 rtu_lo, float32 *rty_y, boolean *rty_RampOn,
  ARID_DEF_switch_ramp_swc_TCOO_T *swc_TCOO__ARID_DEF_arg)
{
  float32 rtb_MinMax1_kl;
  float32 rtb_MinMax_oq;

  /* MinMax: '<S355>/MinMax' incorporates:
   *  Constant: '<S355>/Constant1'
   *  Constant: '<S355>/Constant2'
   *  Product: '<S355>/Product'
   */
  rtb_MinMax_oq = fmaxf(rtu_up * 0.01F, 0.0F);

  /* MinMax: '<S355>/MinMax1' incorporates:
   *  Constant: '<S355>/Constant1'
   *  Constant: '<S355>/Constant2'
   *  Product: '<S355>/Product1'
   */
  rtb_MinMax1_kl = fminf(0.0F, 0.01F * rtu_lo);

  /* Chart: '<S433>/Chart' */
  if (swc_TCOO__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li == 0U) {
    swc_TCOO__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li = 1U;
    swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_TCOO_IN_U2;
    *rty_RampOn = false;
    *rty_y = rtu_u2;
  } else {
    switch (swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib) {
     case swc_TCOO_IN_U1:
      *rty_RampOn = false;
      if (!rtu_sw) {
        if (rtu_u2 >= rtu_u1) {
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_TCOO_IN_U1_TO_U2;
          swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_U1_TO_U2_INC;
          *rty_RampOn = true;
          *rty_y = fminf(fmaxf(fminf(rtu_u2 - *rty_y, rtb_MinMax_oq) + *rty_y,
                               rtu_u1), rtu_u2);
        } else {
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_TCOO_IN_U1_TO_U2;
          swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_U1_TO_U2_DEC;
          *rty_RampOn = true;
          *rty_y = fmaxf(fminf(fmaxf(rtu_u2 - *rty_y, rtb_MinMax1_kl) + *rty_y,
                               rtu_u1), rtu_u2);
        }
      } else {
        *rty_y = rtu_u1;
      }
      break;

     case swc_TCOO_IN_U1_TO_U2:
      {
        if (rtu_sw) {
          if (rtu_u1 >= rtu_u2) {
            swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_NO_ACTIVE_CHILD;
            swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_TCOO_IN_U2_TO_U1;
            swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_U2_TO_U1_INC;
            *rty_RampOn = true;
            *rty_y = fminf(fmaxf(fminf(rtu_u1 - *rty_y, rtb_MinMax_oq) + *rty_y,
                                 rtu_u2), rtu_u1);
          } else {
            swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_NO_ACTIVE_CHILD;
            swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_TCOO_IN_U2_TO_U1;
            swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_U2_TO_U1_DEC;
            *rty_RampOn = true;
            *rty_y = fmaxf(fminf(fmaxf(rtu_u1 - *rty_y, rtb_MinMax1_kl) + *rty_y,
                                 rtu_u2), rtu_u1);
          }
        } else if (swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 ==
                   swc_TCOO_IN_U1_TO_U2_DEC) {
          float32 tmp;
          *rty_RampOn = true;
          tmp = rtu_u2 - *rty_y;
          if (tmp >= rtb_MinMax1_kl) {
            swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_NO_ACTIVE_CHILD;
            swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_TCOO_IN_U2;
            *rty_RampOn = false;
            *rty_y = rtu_u2;
          } else {
            *rty_y = fmaxf(fminf(fmaxf(tmp, rtb_MinMax1_kl) + *rty_y, rtu_u1),
                           rtu_u2);
          }
        } else {
          float32 tmp;

          /* case IN_U1_TO_U2_INC: */
          *rty_RampOn = true;
          tmp = rtu_u2 - *rty_y;
          if (tmp <= rtb_MinMax_oq) {
            swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_NO_ACTIVE_CHILD;
            swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_TCOO_IN_U2;
            *rty_RampOn = false;
            *rty_y = rtu_u2;
          } else {
            *rty_y = fminf(fmaxf(fminf(tmp, rtb_MinMax_oq) + *rty_y, rtu_u1),
                           rtu_u2);
          }
        }
      }
      break;

     case swc_TCOO_IN_U2:
      *rty_RampOn = false;
      if (rtu_sw) {
        if (rtu_u1 >= rtu_u2) {
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_TCOO_IN_U2_TO_U1;
          swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_U2_TO_U1_INC;
          *rty_RampOn = true;
          *rty_y = fminf(fmaxf(fminf(rtu_u1 - *rty_y, rtb_MinMax_oq) + *rty_y,
                               rtu_u2), rtu_u1);
        } else {
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_TCOO_IN_U2_TO_U1;
          swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_U2_TO_U1_DEC;
          *rty_RampOn = true;
          *rty_y = fmaxf(fminf(fmaxf(rtu_u1 - *rty_y, rtb_MinMax1_kl) + *rty_y,
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
            swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_NO_ACTIVE_CHILD;
            swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_TCOO_IN_U1_TO_U2;
            swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_U1_TO_U2_INC;
            *rty_RampOn = true;
            *rty_y = fminf(fmaxf(fminf(rtu_u2 - *rty_y, rtb_MinMax_oq) + *rty_y,
                                 rtu_u1), rtu_u2);
          } else {
            swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_NO_ACTIVE_CHILD;
            swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_TCOO_IN_U1_TO_U2;
            swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_U1_TO_U2_DEC;
            *rty_RampOn = true;
            *rty_y = fmaxf(fminf(fmaxf(rtu_u2 - *rty_y, rtb_MinMax1_kl) + *rty_y,
                                 rtu_u1), rtu_u2);
          }
        } else if (swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 ==
                   swc_TCOO_IN_U2_TO_U1_DEC) {
          float32 tmp;
          *rty_RampOn = true;
          tmp = rtu_u1 - *rty_y;
          if (tmp >= rtb_MinMax1_kl) {
            swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_NO_ACTIVE_CHILD;
            swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_TCOO_IN_U1;
            *rty_RampOn = false;
            *rty_y = rtu_u1;
          } else {
            *rty_y = fmaxf(fminf(fmaxf(tmp, rtb_MinMax1_kl) + *rty_y, rtu_u2),
                           rtu_u1);
          }
        } else {
          float32 tmp;

          /* case IN_U2_TO_U1_INC: */
          *rty_RampOn = true;
          tmp = rtu_u1 - *rty_y;
          if (tmp <= rtb_MinMax_oq) {
            swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_NO_ACTIVE_CHILD;
            swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_TCOO_IN_U1;
            *rty_RampOn = false;
            *rty_y = rtu_u1;
          } else {
            *rty_y = fminf(fmaxf(fminf(tmp, rtb_MinMax_oq) + *rty_y, rtu_u2),
                           rtu_u1);
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<S433>/Chart' */
}

/* System initialize for atomic system: '<S8>/Front_Rear_Axle_VSC_Torque_Intervention_Distribution' */
static void Front_Rear_Axle_VSC_Torque_Init(void)
{
  /* local block i/o variables */
  boolean rtb_RampOn;

  /* SystemInitialize for Atomic SubSystem: '<S335>/SwitchRampEADShiftIntvn' */
  swc_TCOO_switch_ramp_Init(&swc_TCOO_ARID_DEF.y_b, &rtb_RampOn);

  /* End of SystemInitialize for SubSystem: '<S335>/SwitchRampEADShiftIntvn' */
}

/* Outputs for atomic system: '<S8>/Front_Rear_Axle_VSC_Torque_Intervention_Distribution' */
static void Front_Rear_Axle_VSC_Torque_Inte(void)
{
  /* local block i/o variables */
  float32 rtb_Switch6_f;
  float32 rtb_Switch_mx;
  boolean rtb_LogicalOperator22;
  boolean rtb_LogicalOperator13_f;
  boolean rtb_LogicalOperator7_j;
  boolean rtb_RampOn;
  boolean rtb_LogicalOperator3_kp;
  float32 rtb_MinMax3_i_tmp;
  float32 rtb_MinMax3_p;
  float32 rtb_Sum11;
  float32 tcoo_tqdd_b_vlcMaxSpdLmtFilt_tm;
  boolean rtb_LogicalOperator20;
  boolean rtb_LogicalOperator20_tmp;
  boolean rtb_Relay1;
  boolean rtb_Relay2;
  boolean tmp;

  /* Sum: '<S331>/Sum11' incorporates:
   *  MinMax: '<S331>/MinMax1'
   */
  rtb_Sum11 = tqdd_tq_axle2TqDem_Nm + fmaxf
    (swc_TCOO_ARID_DEF.DataTypeConversion84, tqdd_tq_axle2RBSTqLim_Nm);

  /* Switch: '<S338>/Switch11' incorporates:
   *  Constant: '<S356>/Constant'
   *  Constant: '<S357>/Constant'
   *  Constant: '<S358>/Constant'
   *  Logic: '<S338>/Logical Operator8'
   *  RelationalOperator: '<S356>/Compare'
   *  RelationalOperator: '<S357>/Compare'
   *  RelationalOperator: '<S358>/Compare'
   *  Switch: '<S338>/Switch12'
   */
  if (swc_TCOO_ARID_DEF.DataTypeConversion176 == 1.0) {
    /* Switch: '<S338>/Switch11' incorporates:
     *  Constant: '<S338>/Constant7'
     *  MinMax: '<S338>/MinMax2'
     */
    tqdd_tq_axle2AbsTgtTq_Nm = fmaxf(swc_TCOO_ARID_DEF.DataTypeConversion177,
      ((float32)TRQ_ZERO));
  } else if ((swc_TCOO_ARID_DEF.DataTypeConversion182 == 1.0) &&
             (swc_TCOO_ARID_DEF.DataTypeConversion183 == 1.0)) {
    /* Switch: '<S338>/Switch12' incorporates:
     *  Constant: '<S338>/Constant10'
     *  MinMax: '<S338>/MinMax3'
     *  Switch: '<S338>/Switch11'
     */
    tqdd_tq_axle2AbsTgtTq_Nm = fminf(swc_TCOO_ARID_DEF.DataTypeConversion188,
      ((float32)TRQ_ZERO));
  } else {
    /* Switch: '<S338>/Switch11' incorporates:
     *  Switch: '<S338>/Switch12'
     */
    tqdd_tq_axle2AbsTgtTq_Nm = rtb_Sum11;
  }

  /* End of Switch: '<S338>/Switch11' */

  /* Logic: '<S364>/Logical Operator12' incorporates:
   *  Logic: '<S335>/Logical Operator10'
   *  Logic: '<S335>/Logical Operator6'
   *  Logic: '<S364>/Logical Operator17'
   *  Switch: '<S335>/Switch7'
   *  Switch: '<S335>/Switch8'
   */
  rtb_LogicalOperator20_tmp = !tcoo_eadd_b_ehbMsgErrDebd;

  /* Logic: '<S364>/Logical Operator20' incorporates:
   *  Constant: '<S364>/Constant2'
   *  Constant: '<S381>/Constant'
   *  Logic: '<S364>/Logical Operator12'
   *  RelationalOperator: '<S381>/Compare'
   */
  rtb_LogicalOperator20 = (swctcoo_tqdc_b_ehbOvrCtlPmt &&
    rtb_LogicalOperator20_tmp && (swc_TCOO_ARID_DEF.Compare == true));

  /* MinMax: '<S331>/MinMax3' incorporates:
   *  Sum: '<S365>/Sum1'
   */
  rtb_MinMax3_p = rtb_Sum11 - swc_TCOO_ARID_DEF.DataTypeConversion184;

  /* Relay: '<S365>/Relay2' */
  swc_TCOO_ARID_DEF.Relay2_Mode = ((rtb_MinMax3_p >=
    swctcoo_tqdc_tq_vlcAccPedlOvrdHi_Nm) || ((rtb_MinMax3_p >
    swctcoo_tqdc_tq_vlcAccPedlOvrdLo_Nm) && swc_TCOO_ARID_DEF.Relay2_Mode));

  /* Relay: '<S365>/Relay1' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in5'
   *  Switch: '<S366>/Switch1'
   */
  rtb_MinMax3_i_tmp = Rte_IRead_swc_TCOO_Step_vcib_VCIP_acpd_x_accPedlPos_pct();
  swc_TCOO_ARID_DEF.Relay1_Mode_j = ((rtb_MinMax3_i_tmp >=
    tcoo_tqdc_frac_vlcAccPedlOvrdHi_pct) || ((rtb_MinMax3_i_tmp >
    tcoo_tqdc_frac_vlcAccPedlOvrdLo_pct) && swc_TCOO_ARID_DEF.Relay1_Mode_j));
  if (swc_TCOO_ARID_DEF.Relay1_Mode_j) {
    /* Relay: '<S365>/Relay1' */
    rtb_Relay1 = true;
  } else {
    /* Relay: '<S365>/Relay1' */
    rtb_Relay1 = false;
  }

  /* End of Relay: '<S365>/Relay1' */

  /* Switch: '<S365>/Switch4' incorporates:
   *  Constant: '<S402>/Constant'
   *  RelationalOperator: '<S402>/Compare'
   */
  if (swc_TCOO_ARID_DEF.DataTypeConversion181 == true) {
    /* Relay: '<S365>/Relay2' */
    if (swc_TCOO_ARID_DEF.Relay2_Mode) {
      tmp = true;
    } else {
      tmp = false;
    }

    /* Logic: '<S365>/Logical Operator8' incorporates:
     *  Logic: '<S365>/Logical Operator1'
     *  Relay: '<S365>/Relay2'
     */
    rtb_Relay1 = (tmp && rtb_Relay1);
  }

  /* End of Switch: '<S365>/Switch4' */

  /* Switch: '<S365>/Switch9' incorporates:
   *  Constant: '<S397>/Constant'
   *  Constant: '<S408>/Constant'
   *  Logic: '<S365>/Logical Operator14'
   *  Logic: '<S365>/Logical Operator4'
   *  RelationalOperator: '<S397>/Compare'
   *  RelationalOperator: '<S408>/Compare'
   */
  if (rtb_LogicalOperator20 && (swc_TCOO_ARID_DEF.DataTypeConversion185 == 1.0) &&
      (swc_TCOO_ARID_DEF.DataTypeConversion180 == 1.0) && rtb_Relay1) {
    /* Switch: '<S365>/Switch9' incorporates:
     *  Constant: '<S365>/Constant10'
     */
    swctcoo_tqdd_b_gpOvrd = true;
  } else {
    /* Switch: '<S365>/Switch9' incorporates:
     *  Constant: '<S365>/Constant11'
     */
    swctcoo_tqdd_b_gpOvrd = false;
  }

  /* End of Switch: '<S365>/Switch9' */

  /* Switch: '<S352>/Switch4' incorporates:
   *  Constant: '<S362>/Constant'
   *  RelationalOperator: '<S362>/Compare'
   */
  if (swc_TCOO_ARID_DEF.DataTypeConversion181 == true) {
    /* Switch: '<S352>/Switch13' incorporates:
     *  Constant: '<S352>/Constant11'
     *  Constant: '<S359>/Constant'
     *  Constant: '<S360>/Constant'
     *  Constant: '<S361>/Constant'
     *  Constant: '<S363>/Constant'
     *  Logic: '<S352>/Logical Operator18'
     *  Logic: '<S352>/Logical Operator2'
     *  Logic: '<S352>/Logical Operator3'
     *  RelationalOperator: '<S359>/Compare'
     *  RelationalOperator: '<S360>/Compare'
     *  RelationalOperator: '<S361>/Compare'
     *  RelationalOperator: '<S363>/Compare'
     *  Switch: '<S352>/Switch14'
     */
    if ((swc_TCOO_ARID_DEF.DataTypeConversion185 == 1.0) &&
        (swc_TCOO_ARID_DEF.DataTypeConversion180 == 1.0) &&
        (swc_TCOO_ARID_DEF.DataTypeConversion181 == true) &&
        (swctcoo_eadd_tq_axle2TgtUnitDlyMotTyp0_Nm < 0.0F)) {
      /* Switch: '<S352>/Switch4' incorporates:
       *  Constant: '<S352>/Constant3'
       *  Switch: '<S352>/Switch13'
       */
      swctcoo_tqdd_tq_ehbAccCtrlTgtTq_Nm = ((float32)TRQ_ZERO);
    } else {
      if (swctcoo_tqdd_b_gpOvrd || (!tqdc_b_disGpOvrdTq)) {
        /* Switch: '<S352>/Switch14' incorporates:
         *  MinMax: '<S352>/MinMax1'
         */
        rtb_MinMax3_p = fmaxf(rtb_Sum11, swc_TCOO_ARID_DEF.DataTypeConversion184);
      } else {
        /* Switch: '<S352>/Switch14' */
        rtb_MinMax3_p = swc_TCOO_ARID_DEF.DataTypeConversion184;
      }

      /* Switch: '<S352>/Switch4' incorporates:
       *  Constant: '<S352>/Constant2'
       *  MinMax: '<S352>/MinMax3'
       *  MinMax: '<S352>/MinMax4'
       *  Switch: '<S352>/Switch13'
       *  Switch: '<S352>/Switch14'
       */
      swctcoo_tqdd_tq_ehbAccCtrlTgtTq_Nm = fminf(fmaxf
        (swc_TCOO_ARID_DEF.DataTypeConversion54, 0.0F), rtb_MinMax3_p);
    }

    /* End of Switch: '<S352>/Switch13' */
  } else {
    /* Switch: '<S352>/Switch4' incorporates:
     *  Constant: '<S352>/Constant5'
     *  Constant: '<S352>/Constant7'
     *  MinMax: '<S352>/MinMax2'
     *  MinMax: '<S352>/MinMax5'
     *  MinMax: '<S352>/MinMax6'
     */
    swctcoo_tqdd_tq_ehbAccCtrlTgtTq_Nm = fminf(fmaxf
      (swc_TCOO_ARID_DEF.DataTypeConversion54, 0.0F), fmaxf(rtb_Sum11, ((float32)
      TRQ_ZERO)));
  }

  /* End of Switch: '<S352>/Switch4' */

  /* Logic: '<S335>/Logical Operator4' incorporates:
   *  Constant: '<S350>/Constant'
   *  Constant: '<S354>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   *  RelationalOperator: '<S335>/Relational Operator2'
   *  RelationalOperator: '<S350>/Compare'
   */
  tqdd_b_pdcBrkFlg = ((swc_TCOO_ARID_DEF.DataTypeConversion22 == 1.0) &&
                      (swc_TCOO_ARID_DEF.DataTypeConversion7 == DriveDir_REVERSE));

  /* Logic: '<S364>/Logical Operator10' incorporates:
   *  Constant: '<S385>/Constant'
   *  Constant: '<S386>/Constant'
   *  Constant: '<S388>/Constant'
   *  Constant: '<S393>/Constant'
   *  Logic: '<S364>/Logical Operator11'
   *  Logic: '<S364>/Logical Operator21'
   *  RelationalOperator: '<S385>/Compare'
   *  RelationalOperator: '<S386>/Compare'
   *  RelationalOperator: '<S388>/Compare'
   *  RelationalOperator: '<S393>/Compare'
   */
  tcoo_tqdd_b_ehbDisEnbCreep = (rtb_LogicalOperator20 &&
    ((swc_TCOO_ARID_DEF.DataTypeConversion175 == 1.0) ||
     ((swc_TCOO_ARID_DEF.DataTypeConversion185 == 1.0) &&
      (swc_TCOO_ARID_DEF.DataTypeConversion180 == 1.0)) || (tqdd_b_pdcBrkFlg ==
    true)));

  /* Logic: '<S364>/Logical Operator6' incorporates:
   *  Constant: '<S368>/Constant'
   *  Constant: '<S370>/Constant'
   *  Constant: '<S371>/Constant'
   *  Constant: '<S378>/Constant'
   *  Constant: '<S383>/Constant'
   *  Constant: '<S394>/Constant'
   *  Constant: '<S395>/Constant'
   *  Logic: '<S364>/Logical Operator2'
   *  Logic: '<S364>/Logical Operator3'
   *  Logic: '<S364>/Logical Operator5'
   *  RelationalOperator: '<S368>/Compare'
   *  RelationalOperator: '<S370>/Compare'
   *  RelationalOperator: '<S371>/Compare'
   *  RelationalOperator: '<S378>/Compare'
   *  RelationalOperator: '<S383>/Compare'
   *  RelationalOperator: '<S394>/Compare'
   *  RelationalOperator: '<S395>/Compare'
   */
  swctcoo_tqdd_b_ehbOvrCtl = ((((swc_TCOO_ARID_DEF.DataTypeConversion12 == 1.0) &&
    (swc_TCOO_ARID_DEF.DataTypeConversion15 == 1.0)) ||
    (swc_TCOO_ARID_DEF.DataTypeConversion175 == 1.0) || (tqdd_b_pdcBrkFlg ==
    true) || (swc_TCOO_ARID_DEF.DataTypeConversion176 == 1.0) ||
    ((swc_TCOO_ARID_DEF.DataTypeConversion182 == 1.0) &&
     (swc_TCOO_ARID_DEF.DataTypeConversion183 == 1.0))) && rtb_LogicalOperator20);

  /* Logic: '<S364>/Logical Operator23' incorporates:
   *  Constant: '<S369>/Constant'
   *  Constant: '<S372>/Constant'
   *  Constant: '<S374>/Constant'
   *  Constant: '<S396>/Constant'
   *  Logic: '<S364>/Logical Operator4'
   *  Logic: '<S364>/Logical Operator8'
   *  RelationalOperator: '<S369>/Compare'
   *  RelationalOperator: '<S372>/Compare'
   *  RelationalOperator: '<S374>/Compare'
   *  RelationalOperator: '<S396>/Compare'
   */
  swctcoo_tqdd_b_ehbVlcOvrCtl = (rtb_LogicalOperator20 &&
    ((swc_TCOO_ARID_DEF.DataTypeConversion185 == 1.0) &&
     (swc_TCOO_ARID_DEF.DataTypeConversion180 == 1.0) &&
     ((swc_TCOO_ARID_DEF.DataTypeConversion37 == 0.0) ||
      (swc_TCOO_ARID_DEF.DataTypeConversion181 == true))));

  /* Logic: '<S364>/Logical Operator22' */
  rtb_LogicalOperator22 = (swctcoo_tqdd_b_ehbOvrCtl ||
    swctcoo_tqdd_b_ehbVlcOvrCtl);

  /* Logic: '<S364>/Logical Operator24' incorporates:
   *  Constant: '<S373>/Constant'
   *  Constant: '<S375>/Constant'
   *  Constant: '<S376>/Constant'
   *  Constant: '<S377>/Constant'
   *  Constant: '<S379>/Constant'
   *  Constant: '<S380>/Constant'
   *  Constant: '<S382>/Constant'
   *  Constant: '<S384>/Constant'
   *  Constant: '<S387>/Constant'
   *  Logic: '<S364>/Logical Operator1'
   *  Logic: '<S364>/Logical Operator25'
   *  Logic: '<S364>/Logical Operator31'
   *  Logic: '<S364>/Logical Operator34'
   *  Logic: '<S364>/Logical Operator9'
   *  RelationalOperator: '<S373>/Compare'
   *  RelationalOperator: '<S375>/Compare'
   *  RelationalOperator: '<S376>/Compare'
   *  RelationalOperator: '<S377>/Compare'
   *  RelationalOperator: '<S379>/Compare'
   *  RelationalOperator: '<S380>/Compare'
   *  RelationalOperator: '<S382>/Compare'
   *  RelationalOperator: '<S384>/Compare'
   *  RelationalOperator: '<S387>/Compare'
   */
  swc_TCOO_ARID_DEF.tqdd_b_ehbVlcCtlDrvTqEnb = (rtb_LogicalOperator20 &&
    ((swc_TCOO_ARID_DEF.DataTypeConversion12 != 1.0) ||
     (swc_TCOO_ARID_DEF.DataTypeConversion15 != 1.0)) &&
    (swc_TCOO_ARID_DEF.DataTypeConversion175 != 1.0) && (tqdd_b_pdcBrkFlg !=
    true) && (swc_TCOO_ARID_DEF.DataTypeConversion176 != 1.0) &&
    ((swc_TCOO_ARID_DEF.DataTypeConversion185 == 1.0) &&
     (swc_TCOO_ARID_DEF.DataTypeConversion180 == 1.0) &&
     ((swc_TCOO_ARID_DEF.DataTypeConversion37 == 0.0) ||
      (swc_TCOO_ARID_DEF.DataTypeConversion181 == true))));

  /* Logic: '<S364>/Logical Operator53' incorporates:
   *  Constant: '<S389>/Constant'
   *  RelationalOperator: '<S389>/Compare'
   */
  rtb_Relay2 = ((swc_TCOO_ARID_DEF.Compare == false) &&
                rtb_LogicalOperator20_tmp);

  /* Logic: '<S364>/Logical Operator50' incorporates:
   *  Constant: '<S390>/Constant'
   *  Constant: '<S391>/Constant'
   *  Constant: '<S392>/Constant'
   *  Logic: '<S364>/Logical Operator51'
   *  Logic: '<S364>/Logical Operator52'
   *  RelationalOperator: '<S390>/Compare'
   *  RelationalOperator: '<S391>/Compare'
   *  RelationalOperator: '<S392>/Compare'
   */
  tqdd_b_absOvrCtl_flg = (rtb_Relay2 &&
    ((swc_TCOO_ARID_DEF.DataTypeConversion176 == 1.0) ||
     ((swc_TCOO_ARID_DEF.DataTypeConversion182 == 1.0) &&
      (swc_TCOO_ARID_DEF.DataTypeConversion183 == 1.0))));

  /* Logic: '<S365>/Logical Operator8' incorporates:
   *  Constant: '<S398>/Constant'
   *  Constant: '<S399>/Constant'
   *  RelationalOperator: '<S398>/Compare'
   *  RelationalOperator: '<S399>/Compare'
   */
  rtb_Relay1 = ((swctcoo_tqdd_b_ehbVlcOvrCtl == true) &&
                (swc_TCOO_ARID_DEF.DataTypeConversion181 == true));

  /* MinMax: '<S331>/MinMax3' incorporates:
   *  Sum: '<S365>/Sum2'
   */
  rtb_MinMax3_p = swctcoo_eadd_tq_axle2TgtUnitDlyMotTyp0_Nm -
    swc_TCOO_ARID_DEF.DataTypeConversion184;

  /* Relay: '<S365>/Relay3' */
  swc_TCOO_ARID_DEF.Relay3_Mode = ((rtb_MinMax3_p >=
    tcoo_tqdc_tq_vlcDisGpOvrdFiltHi_Nm) || ((rtb_MinMax3_p >
    tcoo_tqdc_tq_vlcDisGpOvrdFiltLo_Nm) && swc_TCOO_ARID_DEF.Relay3_Mode));
  if (swc_TCOO_ARID_DEF.Relay3_Mode) {
    /* Logic: '<S409>/Logical Operator3' */
    rtb_LogicalOperator3_kp = false;
  } else {
    /* Logic: '<S409>/Logical Operator3' */
    rtb_LogicalOperator3_kp = true;
  }

  /* End of Relay: '<S365>/Relay3' */

  /* Logic: '<S365>/Logical Operator13' incorporates:
   *  Logic: '<S365>/Logical Operator16'
   *  Logic: '<S365>/Logical Operator18'
   *  Logic: '<S365>/Logical Operator19'
   */
  rtb_LogicalOperator13_f = ((!rtb_Relay1) || ((!swctcoo_tqdd_b_gpOvrd) &&
    rtb_LogicalOperator3_kp));

  /* MinMax: '<S365>/MinMax3' incorporates:
   *  Constant: '<S365>/Constant21'
   *  MinMax: '<S335>/MinMax5'
   *  Switch: '<S335>/Switch4'
   */
  tcoo_tqdd_b_vlcMaxSpdLmtFilt_tm = fmaxf(swc_TCOO_ARID_DEF.DataTypeConversion54,
    0.0F);

  /* Logic: '<S365>/Logical Operator46' incorporates:
   *  Constant: '<S365>/Constant22'
   *  Constant: '<S403>/Constant'
   *  Constant: '<S404>/Constant'
   *  MinMax: '<S365>/MinMax1'
   *  MinMax: '<S365>/MinMax3'
   *  RelationalOperator: '<S365>/Relational Operator1'
   *  RelationalOperator: '<S403>/Compare'
   *  RelationalOperator: '<S404>/Compare'
   */
  tcoo_tqdd_b_vlcMaxSpdLmtFilt = (tcoo_tqdc_b_enaVlcMaxSpdLmt &&
    (swctcoo_tqdd_b_ehbVlcOvrCtl == true) &&
    (swc_TCOO_ARID_DEF.DataTypeConversion181 == true) &&
    (tcoo_tqdd_b_vlcMaxSpdLmtFilt_tm < fmaxf(rtb_Sum11,
    swc_TCOO_ARID_DEF.DataTypeConversion184)));

  /* Logic: '<S365>/Logical Operator7' */
  rtb_LogicalOperator7_j = (rtb_Relay1 && swctcoo_tqdd_b_gpOvrd);

  /* Outputs for Atomic SubSystem: '<S365>/SR_latch' */
  swc_TCOO_SR_latch(rtb_LogicalOperator7_j, rtb_LogicalOperator13_f,
                    &rtb_LogicalOperator3_kp,
                    &swc_TCOO_ARID_DEF.ARID_DEF_SR_latch_m);

  /* End of Outputs for SubSystem: '<S365>/SR_latch' */

  /* Logic: '<S365>/Logical Operator48' incorporates:
   *  Constant: '<S405>/Constant'
   *  Constant: '<S406>/Constant'
   *  RelationalOperator: '<S405>/Compare'
   *  RelationalOperator: '<S406>/Compare'
   */
  swc_TCOO_ARID_DEF.LogicalOperator48 = ((swctcoo_tqdd_b_ehbVlcOvrCtl == true) &&
    (swc_TCOO_ARID_DEF.DataTypeConversion181 == false));

  /* Switch: '<S365>/Switch11' incorporates:
   *  Constant: '<S365>/Constant1'
   */
  if (tcoo_tqdd_b_gpOvrdCtrlFilt_ovrdflg) {
    /* Switch: '<S365>/Switch11' incorporates:
     *  Constant: '<S365>/Constant14'
     */
    tcoo_tqdd_b_gpOvrdCtrlFilt = tcoo_tqdd_b_gpOvrdCtrlFilt_ovrdval;
  } else {
    /* Switch: '<S365>/Switch11' incorporates:
     *  Constant: '<S400>/Constant'
     *  Constant: '<S401>/Constant'
     *  Constant: '<S407>/Constant'
     *  Logic: '<S365>/Logical Operator15'
     *  Logic: '<S365>/Logical Operator47'
     *  Logic: '<S365>/Logical Operator49'
     *  RelationalOperator: '<S400>/Compare'
     *  RelationalOperator: '<S401>/Compare'
     *  RelationalOperator: '<S407>/Compare'
     */
    tcoo_tqdd_b_gpOvrdCtrlFilt = (rtb_LogicalOperator3_kp ||
      swc_TCOO_ARID_DEF.LogicalOperator48 || ((swctcoo_tqdd_b_ehbVlcOvrCtl ==
      true) && (swc_TCOO_ARID_DEF.DataTypeConversion181 == true) &&
      (swctcoo_eadd_tq_axle2TgtUnitDlyMotTyp0_Nm < 0.0F)) ||
      tcoo_tqdd_b_vlcMaxSpdLmtFilt);
  }

  /* End of Switch: '<S365>/Switch11' */

  /* Switch: '<S366>/Switch2' incorporates:
   *  Constant: '<S414>/Constant'
   *  Constant: '<S415>/Constant'
   *  Logic: '<S366>/Logical Operator27'
   *  Logic: '<S366>/Logical Operator32'
   *  RelationalOperator: '<S414>/Compare'
   *  RelationalOperator: '<S415>/Compare'
   *  Switch: '<S366>/Switch6'
   */
  if (swc_TCOO_ARID_DEF.tqdd_b_ehbVlcCtlDrvTqEnb &&
      swc_TCOO_ARID_DEF.DataTypeConversion181) {
    rtb_MinMax3_p = swc_TCOO_ARID_DEF.DataTypeConversion184;
  } else if ((swctcoo_tdad_st_adcCtrlSts == ((uint8)0U)) ||
             (swctcoo_tdad_st_adcCtrlSts == ((uint8)1U))) {
    /* Switch: '<S366>/Switch6' */
    rtb_MinMax3_p = swctcoo_tdad_tq_whlDemAdcCtl_Nm;
  } else {
    rtb_MinMax3_p = rtb_Sum11;
  }

  /* Lookup_n-D: '<S366>/2-D Lookup Table4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  Switch: '<S366>/Switch2'
   */
  tcoo_tqdd_x_accPedlPosVirtRaw_pct = look2_iflf_binlcapw
    (swc_TCOO_ARID_DEF.DataTypeConversion4, rtb_MinMax3_p, (const float32 *)
     &tcoo_tqda_pedlPosVirt_X_VehSpd_kph[0], (const float32 *)
     &tcoo_tqda_pedlPosVirt_Y_WhlDem_Nm[0], (const float32 *)
     &tcoo_tqdm_pedlPosVirt_Z_pct[0], swc_TCOO_ConstP.uDLookupTable4_maxIndex,
     11U);

  /* Logic: '<S366>/Logical Operator26' incorporates:
   *  Logic: '<S366>/Logical Operator35'
   *  Switch: '<S366>/Switch3'
   */
  tmp = (swc_TCOO_ARID_DEF.tqdd_b_ehbVlcCtlDrvTqEnb &&
         swc_TCOO_ARID_DEF.DataTypeConversion181);

  /* Switch: '<S366>/Switch1' incorporates:
   *  Constant: '<S410>/Constant'
   *  Constant: '<S411>/Constant'
   *  Logic: '<S366>/Logical Operator26'
   *  Logic: '<S366>/Logical Operator28'
   *  RelationalOperator: '<S410>/Compare'
   *  RelationalOperator: '<S411>/Compare'
   *  Switch: '<S366>/Switch3'
   */
  if (tmp || (swctcoo_tdad_st_adcCtrlSts == ((uint8)0U)) ||
      (swctcoo_tdad_st_adcCtrlSts == ((uint8)1U)) ||
      swc_TCOO_ARID_DEF.DataTypeConversion27) {
    /* Switch: '<S366>/Switch1' */
    tcoo_tqdd_x_accPedlPosVirt_pct = tcoo_tqdd_x_accPedlPosVirtRaw_pct;

    /* Switch: '<S366>/Switch7' incorporates:
     *  Constant: '<S416>/Constant'
     *  Constant: '<S417>/Constant'
     *  Logic: '<S366>/Logical Operator36'
     *  RelationalOperator: '<S416>/Compare'
     *  RelationalOperator: '<S417>/Compare'
     */
    if (tmp || (swctcoo_tdad_st_adcCtrlSts == ((uint8)0U)) ||
        (swctcoo_tdad_st_adcCtrlSts == ((uint8)1U))) {
      /* Switch: '<S366>/Switch5' incorporates:
       *  Constant: '<S366>/Constant'
       *  RelationalOperator: '<S366>/Relational Operator'
       */
      if (tcoo_tqdd_x_accPedlPosVirtRaw_pct > 100.0F) {
        /* Switch: '<S366>/Switch3' incorporates:
         *  Constant: '<S366>/Constant3'
         *  Switch: '<S366>/Switch7'
         */
        tcoo_tqdd_b_accPedlPosVirtVld = false;
      } else {
        /* Switch: '<S366>/Switch3' incorporates:
         *  Constant: '<S366>/Constant4'
         *  Switch: '<S366>/Switch7'
         */
        tcoo_tqdd_b_accPedlPosVirtVld = true;
      }

      /* End of Switch: '<S366>/Switch5' */
    } else {
      /* Switch: '<S366>/Switch3' incorporates:
       *  Constant: '<S366>/Constant5'
       *  Switch: '<S366>/Switch7'
       */
      tcoo_tqdd_b_accPedlPosVirtVld = true;
    }

    /* End of Switch: '<S366>/Switch7' */
  } else {
    /* Switch: '<S366>/Switch1' */
    tcoo_tqdd_x_accPedlPosVirt_pct = rtb_MinMax3_i_tmp;

    /* Switch: '<S366>/Switch3' */
    tcoo_tqdd_b_accPedlPosVirtVld = swc_TCOO_ARID_DEF.DataTypeConversion14;
  }

  /* Switch: '<S367>/Switch10' incorporates:
   *  Constant: '<S421>/Constant'
   *  Constant: '<S432>/Constant'
   *  Logic: '<S367>/Logical Operator33'
   *  Logic: '<S367>/Logical Operator37'
   *  Logic: '<S367>/Logical Operator54'
   *  Logic: '<S367>/Logical Operator55'
   *  Logic: '<S367>/Logical Operator56'
   *  RelationalOperator: '<S421>/Compare'
   *  RelationalOperator: '<S432>/Compare'
   */
  if (((swc_TCOO_ARID_DEF.Compare == true) && (tcoo_eadd_b_ehbMsgErrDebd ||
        rtb_LogicalOperator22 || swctcoo_dtdd_b_ehbMbRgnOvrCtl)) ||
      ((swc_TCOO_ARID_DEF.Compare == false) && (tqdd_b_absOvrCtl_flg ||
        tcoo_eadd_b_ehbMsgErrDebd))) {
    /* Switch: '<S367>/Switch10' incorporates:
     *  Constant: '<S367>/Constant7'
     */
    tqdd_st_ehbTrqOvrdActv = ((uint8)1U);
  } else {
    /* Switch: '<S367>/Switch10' incorporates:
     *  Constant: '<S367>/Constant8'
     */
    tqdd_st_ehbTrqOvrdActv = ((uint8)0U);
  }

  /* End of Switch: '<S367>/Switch10' */

  /* Switch: '<S367>/Switch8' incorporates:
   *  Constant: '<S418>/Constant'
   *  Constant: '<S419>/Constant'
   *  Constant: '<S420>/Constant'
   *  Constant: '<S422>/Constant'
   *  Constant: '<S423>/Constant'
   *  Constant: '<S424>/Constant'
   *  Constant: '<S425>/Constant'
   *  Constant: '<S426>/Constant'
   *  Constant: '<S427>/Constant'
   *  Constant: '<S428>/Constant'
   *  Constant: '<S429>/Constant'
   *  Constant: '<S430>/Constant'
   *  Constant: '<S431>/Constant'
   *  Logic: '<S367>/Logical Operator1'
   *  Logic: '<S367>/Logical Operator2'
   *  Logic: '<S367>/Logical Operator38'
   *  Logic: '<S367>/Logical Operator39'
   *  Logic: '<S367>/Logical Operator40'
   *  Logic: '<S367>/Logical Operator41'
   *  Logic: '<S367>/Logical Operator42'
   *  Logic: '<S367>/Logical Operator43'
   *  Logic: '<S367>/Logical Operator44'
   *  Logic: '<S367>/Logical Operator45'
   *  Logic: '<S367>/Logical Operator57'
   *  Logic: '<S367>/Logical Operator8'
   *  RelationalOperator: '<S418>/Compare'
   *  RelationalOperator: '<S419>/Compare'
   *  RelationalOperator: '<S420>/Compare'
   *  RelationalOperator: '<S422>/Compare'
   *  RelationalOperator: '<S423>/Compare'
   *  RelationalOperator: '<S424>/Compare'
   *  RelationalOperator: '<S425>/Compare'
   *  RelationalOperator: '<S426>/Compare'
   *  RelationalOperator: '<S427>/Compare'
   *  RelationalOperator: '<S428>/Compare'
   *  RelationalOperator: '<S429>/Compare'
   *  RelationalOperator: '<S430>/Compare'
   *  RelationalOperator: '<S431>/Compare'
   *  Switch: '<S367>/Switch13'
   *  Switch: '<S367>/Switch14'
   *  Switch: '<S367>/Switch15'
   *  Switch: '<S367>/Switch16'
   *  Switch: '<S367>/Switch17'
   *  Switch: '<S367>/Switch18'
   *  Switch: '<S367>/Switch19'
   */
  if (rtb_LogicalOperator20 && (swc_TCOO_ARID_DEF.DataTypeConversion12 == 1.0) &&
      (swc_TCOO_ARID_DEF.DataTypeConversion15 == 1.0)) {
    /* Switch: '<S367>/Switch8' incorporates:
     *  Constant: '<S367>/Constant6'
     */
    tqdd_st_ehbTrqOvrdType = ((uint8)8U);
  } else if (((swc_TCOO_ARID_DEF.Compare == false) || (swc_TCOO_ARID_DEF.Compare
    == true)) && tcoo_eadd_b_ehbMsgErrDebd) {
    /* Switch: '<S367>/Switch13' incorporates:
     *  Constant: '<S367>/Constant9'
     *  Switch: '<S367>/Switch8'
     */
    tqdd_st_ehbTrqOvrdType = ((uint8)1U);
  } else if (rtb_LogicalOperator20 && (swc_TCOO_ARID_DEF.DataTypeConversion175 ==
              1.0)) {
    /* Switch: '<S367>/Switch14' incorporates:
     *  Constant: '<S367>/Constant12'
     *  Switch: '<S367>/Switch13'
     *  Switch: '<S367>/Switch8'
     */
    tqdd_st_ehbTrqOvrdType = ((uint8)3U);
  } else if (rtb_LogicalOperator20 && (tqdd_b_pdcBrkFlg == true)) {
    /* Switch: '<S367>/Switch15' incorporates:
     *  Constant: '<S367>/Constant15'
     *  Switch: '<S367>/Switch13'
     *  Switch: '<S367>/Switch14'
     *  Switch: '<S367>/Switch8'
     */
    tqdd_st_ehbTrqOvrdType = ((uint8)4U);
  } else if ((rtb_Relay2 || rtb_LogicalOperator20) &&
             (swc_TCOO_ARID_DEF.DataTypeConversion176 == 1.0)) {
    /* Switch: '<S367>/Switch16' incorporates:
     *  Constant: '<S367>/Constant16'
     *  Switch: '<S367>/Switch13'
     *  Switch: '<S367>/Switch14'
     *  Switch: '<S367>/Switch15'
     *  Switch: '<S367>/Switch8'
     */
    tqdd_st_ehbTrqOvrdType = ((uint8)2U);
  } else if (rtb_LogicalOperator20 && (swc_TCOO_ARID_DEF.DataTypeConversion185 ==
              1.0) && (swc_TCOO_ARID_DEF.DataTypeConversion180 == 1.0) &&
             ((swc_TCOO_ARID_DEF.DataTypeConversion37 == 0.0) ||
              (swc_TCOO_ARID_DEF.DataTypeConversion181 == true))) {
    /* Switch: '<S367>/Switch17' incorporates:
     *  Constant: '<S367>/Constant17'
     *  Switch: '<S367>/Switch13'
     *  Switch: '<S367>/Switch14'
     *  Switch: '<S367>/Switch15'
     *  Switch: '<S367>/Switch16'
     *  Switch: '<S367>/Switch8'
     */
    tqdd_st_ehbTrqOvrdType = ((uint8)5U);
  } else if ((rtb_Relay2 || rtb_LogicalOperator20) &&
             (swc_TCOO_ARID_DEF.DataTypeConversion182 == 1.0) &&
             (swc_TCOO_ARID_DEF.DataTypeConversion183 == 1.0)) {
    /* Switch: '<S367>/Switch18' incorporates:
     *  Constant: '<S367>/Constant18'
     *  Switch: '<S367>/Switch13'
     *  Switch: '<S367>/Switch14'
     *  Switch: '<S367>/Switch15'
     *  Switch: '<S367>/Switch16'
     *  Switch: '<S367>/Switch17'
     *  Switch: '<S367>/Switch8'
     */
    tqdd_st_ehbTrqOvrdType = ((uint8)7U);
  } else if (rtb_LogicalOperator20 && swctcoo_dtdd_b_ehbMbRgnOvrCtl) {
    /* Switch: '<S367>/Switch19' incorporates:
     *  Constant: '<S367>/Constant19'
     *  Switch: '<S367>/Switch13'
     *  Switch: '<S367>/Switch14'
     *  Switch: '<S367>/Switch15'
     *  Switch: '<S367>/Switch16'
     *  Switch: '<S367>/Switch17'
     *  Switch: '<S367>/Switch18'
     *  Switch: '<S367>/Switch8'
     */
    tqdd_st_ehbTrqOvrdType = ((uint8)6U);
  } else {
    /* Switch: '<S367>/Switch8' incorporates:
     *  Constant: '<S367>/Constant20'
     *  Switch: '<S367>/Switch13'
     *  Switch: '<S367>/Switch14'
     *  Switch: '<S367>/Switch15'
     *  Switch: '<S367>/Switch16'
     *  Switch: '<S367>/Switch17'
     *  Switch: '<S367>/Switch18'
     *  Switch: '<S367>/Switch19'
     */
    tqdd_st_ehbTrqOvrdType = ((uint8)0U);
  }

  /* End of Switch: '<S367>/Switch8' */

  /* Switch: '<S335>/Switch4' incorporates:
   *  Constant: '<S339>/Constant'
   *  Constant: '<S340>/Constant'
   *  Constant: '<S341>/Constant'
   *  Constant: '<S342>/Constant'
   *  Constant: '<S343>/Constant'
   *  Constant: '<S345>/Constant'
   *  Constant: '<S346>/Constant'
   *  Constant: '<S347>/Constant'
   *  Constant: '<S348>/Constant'
   *  Constant: '<S349>/Constant'
   *  Logic: '<S335>/Logical Operator1'
   *  Logic: '<S335>/Logical Operator2'
   *  Logic: '<S335>/Logical Operator3'
   *  Logic: '<S335>/Logical Operator5'
   *  Logic: '<S335>/Logical Operator8'
   *  RelationalOperator: '<S339>/Compare'
   *  RelationalOperator: '<S340>/Compare'
   *  RelationalOperator: '<S341>/Compare'
   *  RelationalOperator: '<S342>/Compare'
   *  RelationalOperator: '<S343>/Compare'
   *  RelationalOperator: '<S345>/Compare'
   *  RelationalOperator: '<S346>/Compare'
   *  RelationalOperator: '<S347>/Compare'
   *  RelationalOperator: '<S348>/Compare'
   *  RelationalOperator: '<S349>/Compare'
   *  Switch: '<S335>/Switch1'
   *  Switch: '<S335>/Switch2'
   *  Switch: '<S335>/Switch3'
   *  Switch: '<S335>/Switch5'
   */
  if ((swc_TCOO_ARID_DEF.DataTypeConversion12 == 1.0) &&
      (swc_TCOO_ARID_DEF.DataTypeConversion15 == 1.0)) {
    /* Switch: '<S335>/Switch4' incorporates:
     *  MinMax: '<S335>/MinMax6'
     */
    swctcoo_tqdd_tq_axle2EhbTgtTqRaw_Nm = fminf(tcoo_tqdd_b_vlcMaxSpdLmtFilt_tm,
      swc_TCOO_ARID_DEF.DataTypeConversion11);
  } else if ((swc_TCOO_ARID_DEF.DataTypeConversion175 == 1.0) ||
             tqdd_b_pdcBrkFlg) {
    /* Switch: '<S335>/Switch1' incorporates:
     *  Constant: '<S335>/Constant3'
     *  Switch: '<S335>/Switch4'
     */
    swctcoo_tqdd_tq_axle2EhbTgtTqRaw_Nm = ((float32)TRQ_ZERO);
  } else if (swc_TCOO_ARID_DEF.DataTypeConversion176 == 1.0) {
    /* Switch: '<S335>/Switch2' incorporates:
     *  Constant: '<S335>/Constant2'
     *  MinMax: '<S335>/MinMax4'
     *  Switch: '<S335>/Switch1'
     *  Switch: '<S335>/Switch4'
     */
    swctcoo_tqdd_tq_axle2EhbTgtTqRaw_Nm = fmaxf
      (swc_TCOO_ARID_DEF.DataTypeConversion177, ((float32)TRQ_ZERO));
  } else if ((swc_TCOO_ARID_DEF.DataTypeConversion185 == 1.0) &&
             (swc_TCOO_ARID_DEF.DataTypeConversion180 == 1.0) &&
             ((swc_TCOO_ARID_DEF.DataTypeConversion37 == 0.0) ||
              (swc_TCOO_ARID_DEF.DataTypeConversion181 == true))) {
    /* Switch: '<S335>/Switch3' incorporates:
     *  Switch: '<S335>/Switch1'
     *  Switch: '<S335>/Switch2'
     *  Switch: '<S335>/Switch4'
     */
    swctcoo_tqdd_tq_axle2EhbTgtTqRaw_Nm = swctcoo_tqdd_tq_ehbAccCtrlTgtTq_Nm;
  } else if ((swc_TCOO_ARID_DEF.DataTypeConversion182 == 1.0) &&
             (swc_TCOO_ARID_DEF.DataTypeConversion183 == 1.0)) {
    /* Switch: '<S335>/Switch5' incorporates:
     *  Constant: '<S335>/Constant6'
     *  MinMax: '<S335>/MinMax1'
     *  Switch: '<S335>/Switch1'
     *  Switch: '<S335>/Switch2'
     *  Switch: '<S335>/Switch3'
     *  Switch: '<S335>/Switch4'
     */
    swctcoo_tqdd_tq_axle2EhbTgtTqRaw_Nm = fminf
      (swc_TCOO_ARID_DEF.DataTypeConversion188, ((float32)TRQ_ZERO));
  } else {
    /* Switch: '<S335>/Switch4' incorporates:
     *  Switch: '<S335>/Switch1'
     *  Switch: '<S335>/Switch2'
     *  Switch: '<S335>/Switch3'
     *  Switch: '<S335>/Switch5'
     */
    swctcoo_tqdd_tq_axle2EhbTgtTqRaw_Nm = rtb_Sum11;
  }

  /* Switch: '<S335>/Switch6' */
  if (rtb_LogicalOperator22) {
    /* Switch: '<S335>/Switch6' */
    rtb_Switch6_f = swctcoo_eadd_tq_axle2TgtUnitDlyMotTyp0_Nm;
  } else {
    /* Switch: '<S335>/Switch6' */
    rtb_Switch6_f = rtb_Sum11;
  }

  /* End of Switch: '<S335>/Switch6' */

  /* Outputs for Atomic SubSystem: '<S335>/SwitchRampEADShiftIntvn' */
  /* Constant: '<S335>/Constant8' incorporates:
   *  Constant: '<S335>/Constant9'
   */
  swc_TCOO_switch_ramp(swctcoo_tqdd_tq_axle2EhbTgtTqRaw_Nm,
                       rtb_LogicalOperator22, rtb_Switch6_f,
                       swctcoo_tqdc_tq_axle2EhbTqIncGrd_Nmps,
                       swctcoo_tqdc_tq_axle2EhbTqDecGrd_Nmps,
                       &swc_TCOO_ARID_DEF.y_b, &rtb_RampOn,
                       &swc_TCOO_ARID_DEF.ARID_DEF_SwitchRampEADShiftInt);

  /* End of Outputs for SubSystem: '<S335>/SwitchRampEADShiftIntvn' */

  /* Switch: '<S335>/Switch8' incorporates:
   *  Constant: '<S335>/Constant4'
   *  Constant: '<S344>/Constant'
   *  Constant: '<S351>/Constant'
   *  Logic: '<S335>/Logical Operator11'
   *  Logic: '<S335>/Logical Operator7'
   *  RelationalOperator: '<S344>/Compare'
   *  RelationalOperator: '<S351>/Compare'
   *  Switch: '<S335>/Switch7'
   *  Switch: '<S335>/Switch9'
   */
  if (swctcoo_tqdc_b_axle2EhbTgtTq_ovrdflg) {
    /* Switch: '<S335>/Switch8' incorporates:
     *  Constant: '<S335>/Constant5'
     */
    swctcoo_tqdd_tq_axle2EhbTgtTq_Nm = swctcoo_tqdc_tq_axle2EhbTgtTq_ovrdval;
  } else if ((swc_TCOO_ARID_DEF.Compare == true) && rtb_LogicalOperator20_tmp) {
    /* Switch: '<S335>/Switch10' incorporates:
     *  Constant: '<S335>/Constant12'
     *  Logic: '<S335>/Logical Operator9'
     *  Switch: '<S335>/Switch7'
     */
    if (!swctcoo_tqdc_b_enaEhbTqRamp) {
      /* Switch: '<S335>/Switch8' incorporates:
       *  Switch: '<S335>/Switch7'
       */
      swctcoo_tqdd_tq_axle2EhbTgtTq_Nm = swctcoo_tqdd_tq_axle2EhbTgtTqRaw_Nm;
    } else {
      /* Switch: '<S335>/Switch8' incorporates:
       *  Switch: '<S335>/Switch7'
       */
      swctcoo_tqdd_tq_axle2EhbTgtTq_Nm = swc_TCOO_ARID_DEF.y_b;
    }

    /* End of Switch: '<S335>/Switch10' */
  } else if ((swc_TCOO_ARID_DEF.Compare == false) && rtb_LogicalOperator20_tmp)
  {
    /* Switch: '<S335>/Switch9' incorporates:
     *  Switch: '<S335>/Switch7'
     *  Switch: '<S335>/Switch8'
     */
    swctcoo_tqdd_tq_axle2EhbTgtTq_Nm = tqdd_tq_axle2AbsTgtTq_Nm;
  } else {
    /* Switch: '<S335>/Switch8' incorporates:
     *  Switch: '<S335>/Switch7'
     *  Switch: '<S335>/Switch9'
     */
    swctcoo_tqdd_tq_axle2EhbTgtTq_Nm = rtb_Sum11;
  }

  /* MinMax: '<S336>/MinMax6' */
  tqdd_tq_axle2VSCMaxTqIntv_Nm = fminf(swc_TCOO_ARID_DEF.DataTypeConversion65,
    swc_TCOO_ARID_DEF.DataTypeConversion26);

  /* MinMax: '<S336>/MinMax3' */
  tqdd_tq_axle2VSCMinTqIntv_Nm = fmaxf(swc_TCOO_ARID_DEF.DataTypeConversion78,
    swc_TCOO_ARID_DEF.DataTypeConversion47);

  /* MinMax: '<S331>/MinMax3' incorporates:
   *  Constant: '<S331>/Constant1'
   */
  rtb_MinMax3_p = fminf(tqdd_tq_axle2VSCMinTqIntv_Nm, ((float32)TRQ_ZERO));

  /* MinMax: '<S331>/MinMax4' incorporates:
   *  Constant: '<S331>/Constant2'
   */
  rtb_Sum11 = fmaxf(((float32)TRQ_ZERO), tqdd_tq_axle2VSCMaxTqIntv_Nm);

  /* Switch: '<S337>/Switch' incorporates:
   *  RelationalOperator: '<S337>/UpperRelop'
   */
  if (swctcoo_tqdd_tq_axle2EhbTgtTq_Nm < rtb_MinMax3_p) {
    /* Switch: '<S337>/Switch' */
    rtb_Switch_mx = rtb_MinMax3_p;
  } else {
    /* Switch: '<S337>/Switch' */
    rtb_Switch_mx = swctcoo_tqdd_tq_axle2EhbTgtTq_Nm;
  }

  /* End of Switch: '<S337>/Switch' */

  /* Switch: '<S337>/Switch2' incorporates:
   *  RelationalOperator: '<S337>/LowerRelop1'
   */
  if (swctcoo_tqdd_tq_axle2EhbTgtTq_Nm > rtb_Sum11) {
    /* Switch: '<S337>/Switch2' */
    tqdd_tq_axle2VSCTqTgt_Nm = rtb_Sum11;
  } else {
    /* Switch: '<S337>/Switch2' */
    tqdd_tq_axle2VSCTqTgt_Nm = rtb_Switch_mx;
  }

  /* End of Switch: '<S337>/Switch2' */
}

/* System initialize for atomic system: '<S332>/SwitchRampMot2RegenBrkLim' */
static void SwitchRampMot2RegenBrkLim_Init(float32 *rty_y, boolean *rty_RampOn)
{
  /* SystemInitialize for Chart: '<S436>/Chart' */
  *rty_y = 0.0F;
  *rty_RampOn = false;
}

/* Output and update for atomic system: '<S332>/SwitchRampMot2RegenBrkLim' */
static void swc_T_SwitchRampMot2RegenBrkLim(float32 rtu_u1, boolean rtu_sw,
  float32 rtu_u2, float32 rtu_up, float32 rtu_lo, float32 *rty_y, boolean
  *rty_RampOn, ARID_DEF_switch_ramp_swc_TC_m_T *swc_TCOO__ARID_DEF_arg)
{
  float32 rtb_MinMax1_b;
  float32 rtb_MinMax_d;

  /* MinMax: '<S435>/MinMax' incorporates:
   *  Constant: '<S435>/Constant1'
   *  Constant: '<S435>/Constant2'
   *  Product: '<S435>/Product'
   */
  rtb_MinMax_d = fmaxf(rtu_up * 0.01F, 0.0F);

  /* MinMax: '<S435>/MinMax1' incorporates:
   *  Constant: '<S435>/Constant1'
   *  Constant: '<S435>/Constant2'
   *  Product: '<S435>/Product1'
   */
  rtb_MinMax1_b = fminf(0.0F, 0.01F * rtu_lo);

  /* Chart: '<S436>/Chart' */
  if (swc_TCOO__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li == 0U) {
    swc_TCOO__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li = 1U;
    swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_TCOO_IN_U2_k;
    *rty_RampOn = false;
    *rty_y = rtu_u2;
  } else {
    switch (swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib) {
     case swc_TCOO_IN_U1_f:
      *rty_RampOn = false;
      if (!rtu_sw) {
        if (rtu_u2 >= rtu_u1) {
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_TCOO_IN_U1_TO_U2_l;
          swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_U1_TO_U2_INC_j;
          *rty_RampOn = true;
          *rty_y = fminf(fmaxf(fminf(rtu_u2 - *rty_y, rtb_MinMax_d) + *rty_y,
                               rtu_u1), rtu_u2);
        } else {
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_TCOO_IN_U1_TO_U2_l;
          swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_U1_TO_U2_DEC_k;
          *rty_RampOn = true;
          *rty_y = fmaxf(fminf(fmaxf(rtu_u2 - *rty_y, rtb_MinMax1_b) + *rty_y,
                               rtu_u1), rtu_u2);
        }
      } else {
        *rty_y = rtu_u1;
      }
      break;

     case swc_TCOO_IN_U1_TO_U2_l:
      {
        if (rtu_sw) {
          if (rtu_u1 >= rtu_u2) {
            swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_NO_ACTIVE_CHILD_b;
            swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_TCOO_IN_U2_TO_U1_h;
            swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_U2_TO_U1_INC_p;
            *rty_RampOn = true;
            *rty_y = fminf(fmaxf(fminf(rtu_u1 - *rty_y, rtb_MinMax_d) + *rty_y,
                                 rtu_u2), rtu_u1);
          } else {
            swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_NO_ACTIVE_CHILD_b;
            swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_TCOO_IN_U2_TO_U1_h;
            swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_U2_TO_U1_DEC_a;
            *rty_RampOn = true;
            *rty_y = fmaxf(fminf(fmaxf(rtu_u1 - *rty_y, rtb_MinMax1_b) + *rty_y,
                                 rtu_u2), rtu_u1);
          }
        } else if (swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 ==
                   swc_TCOO_IN_U1_TO_U2_DEC_k) {
          float32 tmp;
          *rty_RampOn = true;
          tmp = rtu_u2 - *rty_y;
          if (tmp >= rtb_MinMax1_b) {
            swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_NO_ACTIVE_CHILD_b;
            swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_TCOO_IN_U2_k;
            *rty_RampOn = false;
            *rty_y = rtu_u2;
          } else {
            *rty_y = fmaxf(fminf(fmaxf(tmp, rtb_MinMax1_b) + *rty_y, rtu_u1),
                           rtu_u2);
          }
        } else {
          float32 tmp;

          /* case IN_U1_TO_U2_INC: */
          *rty_RampOn = true;
          tmp = rtu_u2 - *rty_y;
          if (tmp <= rtb_MinMax_d) {
            swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_NO_ACTIVE_CHILD_b;
            swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_TCOO_IN_U2_k;
            *rty_RampOn = false;
            *rty_y = rtu_u2;
          } else {
            *rty_y = fminf(fmaxf(fminf(tmp, rtb_MinMax_d) + *rty_y, rtu_u1),
                           rtu_u2);
          }
        }
      }
      break;

     case swc_TCOO_IN_U2_k:
      *rty_RampOn = false;
      if (rtu_sw) {
        if (rtu_u1 >= rtu_u2) {
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_TCOO_IN_U2_TO_U1_h;
          swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_U2_TO_U1_INC_p;
          *rty_RampOn = true;
          *rty_y = fminf(fmaxf(fminf(rtu_u1 - *rty_y, rtb_MinMax_d) + *rty_y,
                               rtu_u2), rtu_u1);
        } else {
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_TCOO_IN_U2_TO_U1_h;
          swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_U2_TO_U1_DEC_a;
          *rty_RampOn = true;
          *rty_y = fmaxf(fminf(fmaxf(rtu_u1 - *rty_y, rtb_MinMax1_b) + *rty_y,
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
            swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_NO_ACTIVE_CHILD_b;
            swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_TCOO_IN_U1_TO_U2_l;
            swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_U1_TO_U2_INC_j;
            *rty_RampOn = true;
            *rty_y = fminf(fmaxf(fminf(rtu_u2 - *rty_y, rtb_MinMax_d) + *rty_y,
                                 rtu_u1), rtu_u2);
          } else {
            swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_NO_ACTIVE_CHILD_b;
            swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
              swc_TCOO_IN_U1_TO_U2_l;
            swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_U1_TO_U2_DEC_k;
            *rty_RampOn = true;
            *rty_y = fmaxf(fminf(fmaxf(rtu_u2 - *rty_y, rtb_MinMax1_b) + *rty_y,
                                 rtu_u1), rtu_u2);
          }
        } else if (swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 ==
                   swc_TCOO_IN_U2_TO_U1_DEC_a) {
          float32 tmp;
          *rty_RampOn = true;
          tmp = rtu_u1 - *rty_y;
          if (tmp >= rtb_MinMax1_b) {
            swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_NO_ACTIVE_CHILD_b;
            swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_TCOO_IN_U1_f;
            *rty_RampOn = false;
            *rty_y = rtu_u1;
          } else {
            *rty_y = fmaxf(fminf(fmaxf(tmp, rtb_MinMax1_b) + *rty_y, rtu_u2),
                           rtu_u1);
          }
        } else {
          float32 tmp;

          /* case IN_U2_TO_U1_INC: */
          *rty_RampOn = true;
          tmp = rtu_u1 - *rty_y;
          if (tmp <= rtb_MinMax_d) {
            swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_NO_ACTIVE_CHILD_b;
            swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_TCOO_IN_U1_f;
            *rty_RampOn = false;
            *rty_y = rtu_u1;
          } else {
            *rty_y = fminf(fmaxf(fminf(tmp, rtb_MinMax_d) + *rty_y, rtu_u2),
                           rtu_u1);
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<S436>/Chart' */
}

/* System initialize for atomic system: '<S8>/RegenerativeBrakeTorqueCapacityCalc' */
static void RegenerativeBrakeTorqueCap_Init(void)
{
  /* local block i/o variables */
  boolean rtb_RampOn_n;

  /* SystemInitialize for Atomic SubSystem: '<S332>/SwitchRampMot2RegenBrkLim' */
  SwitchRampMot2RegenBrkLim_Init(&swc_TCOO_ARID_DEF.y, &rtb_RampOn_n);

  /* End of SystemInitialize for SubSystem: '<S332>/SwitchRampMot2RegenBrkLim' */
}

/* Output and update for atomic system: '<S8>/RegenerativeBrakeTorqueCapacityCalc' */
static void RegenerativeBrakeTorqueCapacity(void)
{
  /* local block i/o variables */
  float32 rtb_MinMax1_h4;
  boolean rtb_LogicalOperator12_h;
  boolean rtb_RampOn_n;
  float64 tmp;
  float32 rtb_Sum1;

  /* Relay: '<S332>/Relay' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in5'
   */
  rtb_Sum1 = Rte_IRead_swc_TCOO_Step_vcib_VCIP_acpd_x_accPedlPos_pct();
  swc_TCOO_ARID_DEF.Relay_Mode = ((rtb_Sum1 >= tqdc_x_accPedlPosHiDisRBS_pct) ||
    ((rtb_Sum1 > tqdc_x_accPedlPosLoDisRBS_pct) && swc_TCOO_ARID_DEF.Relay_Mode));

  /* Relay: '<S332>/Relay1' */
  swc_TCOO_ARID_DEF.Relay1_Mode = ((swc_TCOO_ARID_DEF.DataTypeConversion63 >=
    tqdc_x_brkPedlPosHiEnaRBS_pct) || ((swc_TCOO_ARID_DEF.DataTypeConversion63 >
    tqdc_x_brkPedlPosLoEnaRBS_pct) && swc_TCOO_ARID_DEF.Relay1_Mode));

  /* Relay: '<S332>/Relay' */
  if (swc_TCOO_ARID_DEF.Relay_Mode) {
    rtb_Sum1 = 0.0F;
  } else {
    rtb_Sum1 = 1.0F;
  }

  /* Relay: '<S332>/Relay1' */
  if (swc_TCOO_ARID_DEF.Relay1_Mode) {
    tmp = 1.0;
  } else {
    tmp = 0.0;
  }

  /* Logic: '<S332>/Logical Operator12' incorporates:
   *  DataTypeConversion: '<S332>/Data Type Conversion1'
   *  DataTypeConversion: '<S332>/Data Type Conversion2'
   *  Logic: '<S332>/Logical Operator1'
   *  Relay: '<S332>/Relay'
   *  Relay: '<S332>/Relay1'
   */
  rtb_LogicalOperator12_h = ((rtb_Sum1 != 0.0F) && (tmp != 0.0) &&
    (!swc_TCOO_ARID_DEF.DataTypeConversion23));

  /* MinMax: '<S332>/MinMax1' incorporates:
   *  Constant: '<S332>/Constant8'
   *  Sum: '<S332>/Sum1'
   */
  rtb_MinMax1_h4 = fminf(swc_TCOO_ARID_DEF.DataTypeConversion47 -
    tqdd_tq_axle2TqDem_Nm, ((float32)TRQ_ZERO));

  /* Outputs for Atomic SubSystem: '<S332>/SwitchRampMot2RegenBrkLim' */
  /* Constant: '<S332>/Constant4' incorporates:
   *  Constant: '<S332>/Constant1'
   *  Constant: '<S332>/Constant3'
   */
  swc_T_SwitchRampMot2RegenBrkLim(rtb_MinMax1_h4, rtb_LogicalOperator12_h,
    ((float32)TRQ_ZERO), tqdc_tq_axle2RBSLimIncGrad_Nmps,
    tqdc_tq_axle2RBSLimDecGrad_Nmps, &swc_TCOO_ARID_DEF.y, &rtb_RampOn_n,
    &swc_TCOO_ARID_DEF.ARID_DEF_SwitchRampMot2RegenBr);

  /* End of Outputs for SubSystem: '<S332>/SwitchRampMot2RegenBrkLim' */

  /* SignalConversion generated from: '<S332>/SwitchRampMot2RegenBrkLim' */
  tqdd_tq_axle2RBSTqLim_Nm = swc_TCOO_ARID_DEF.y;
}

/* System initialize for function-call system: '<S1>/TQD_TorqueDistribution' */
static void swc_TQD_TorqueDistribution_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S8>/RegenerativeBrakeTorqueCapacityCalc' */
  RegenerativeBrakeTorqueCap_Init();

  /* End of SystemInitialize for SubSystem: '<S8>/RegenerativeBrakeTorqueCapacityCalc' */

  /* SystemInitialize for Atomic SubSystem: '<S8>/Front_Rear_Axle_VSC_Torque_Intervention_Distribution' */
  Front_Rear_Axle_VSC_Torque_Init();

  /* End of SystemInitialize for SubSystem: '<S8>/Front_Rear_Axle_VSC_Torque_Intervention_Distribution' */
}

/* Output and update for function-call system: '<S1>/TQD_TorqueDistribution' */
static void swc_TCOO_TQD_TorqueDistribution(void)
{
  /* Outputs for Atomic SubSystem: '<S8>/Front_Rear_Axle_Torque_Distribution' */
  Front_Rear_Axle_Torque_Distribu();

  /* End of Outputs for SubSystem: '<S8>/Front_Rear_Axle_Torque_Distribution' */

  /* Outputs for Atomic SubSystem: '<S8>/RegenerativeBrakeTorqueCapacityCalc' */
  RegenerativeBrakeTorqueCapacity();

  /* End of Outputs for SubSystem: '<S8>/RegenerativeBrakeTorqueCapacityCalc' */

  /* Outputs for Atomic SubSystem: '<S8>/Front_Rear_Axle_VSC_Torque_Intervention_Distribution' */
  Front_Rear_Axle_VSC_Torque_Inte();

  /* End of Outputs for SubSystem: '<S8>/Front_Rear_Axle_VSC_Torque_Intervention_Distribution' */
}

/* Output and update for function-call system: '<S1>/EAD_TargetTorqueControlMot2' */
static void swc_EAD_TargetTorqueControlMot2(void)
{
  /* local block i/o variables */
  float64 rtb_Switch1_fx;
  float64 rtb_Switch2_nk;
  boolean rtb_LogicalOperator2_mp;
  boolean rtb_LogicalOperator3_dl;
  boolean rtb_RelationalOperator2_jf;
  boolean rtb_LogicalOperator_b;
  boolean rtb_LogicalOperator2_jm;
  boolean rtb_LogicalOperator3_mc;
  boolean rtb_RelationalOperator2_k;
  sint32 idxDelay;
  float32 rtb_MinMax1_fv;
  float32 rtb_MinMax2_n;
  float32 rtb_Product4_k;
  float32 rtb_Switch1_d4;
  float32 rtb_Switch1_i1_tmp;
  float32 rtb_Switch2_cg;
  BrakePedalStatus tmp;
  DriveDir rtb_RelationalOperator2_a_tmp;
  boolean rtb_Delay;
  boolean rtb_LogicalOperator46;
  boolean rtb_LogicalOperator50;
  boolean rtb_RelationalOperator2_ex;
  boolean rtb_RelationalOperator2_k_tmp;

  /* MinMax: '<S176>/MinMax2' incorporates:
   *  Constant: '<S176>/Constant2'
   *  MinMax: '<S175>/MinMax3'
   */
  rtb_MinMax2_n = fmaxf(((float32)TRQ_ZERO),
                        swc_TCOO_ARID_DEF.DataTypeConversion26);

  /* MinMax: '<S176>/MinMax1' incorporates:
   *  Constant: '<S176>/Constant1'
   *  MinMax: '<S175>/MinMax2'
   */
  rtb_MinMax1_fv = fminf(swc_TCOO_ARID_DEF.DataTypeConversion47, ((float32)
    TRQ_ZERO));

  /* Switch: '<S186>/Switch2' incorporates:
   *  MinMax: '<S176>/MinMax1'
   *  MinMax: '<S176>/MinMax2'
   *  RelationalOperator: '<S186>/LowerRelop1'
   *  RelationalOperator: '<S186>/UpperRelop'
   *  Switch: '<S186>/Switch'
   */
  if (tqdd_tq_axle2VSCTqTgt_Nm > rtb_MinMax2_n) {
    /* Switch: '<S186>/Switch2' */
    eadd_tq_axle2TgtTq_Nm = rtb_MinMax2_n;
  } else if (tqdd_tq_axle2VSCTqTgt_Nm < rtb_MinMax1_fv) {
    /* Switch: '<S186>/Switch' incorporates:
     *  MinMax: '<S176>/MinMax1'
     *  Switch: '<S186>/Switch2'
     */
    eadd_tq_axle2TgtTq_Nm = rtb_MinMax1_fv;
  } else {
    /* Switch: '<S186>/Switch2' incorporates:
     *  Switch: '<S186>/Switch'
     */
    eadd_tq_axle2TgtTq_Nm = tqdd_tq_axle2VSCTqTgt_Nm;
  }

  /* End of Switch: '<S186>/Switch2' */

  /* Product: '<S175>/Product2' incorporates:
   *  Product: '<S188>/Product2'
   */
  rtb_Switch1_i1_tmp = swc_TCOO_ARID_DEF.DataTypeConversion13 *
    swc_TCOO_ARID_DEF.DataTypeConversion25;

  /* Switch: '<S199>/Switch1' incorporates:
   *  Constant: '<S175>/Constant9'
   *  MinMax: '<S175>/MinMax1'
   *  Product: '<S175>/Product2'
   */
  rtb_Switch1_d4 = fmaxf(rtb_Switch1_i1_tmp, 0.1F);

  /* Product: '<S175>/Product4' incorporates:
   *  Constant: '<S175>/Constant'
   */
  rtb_Product4_k = eadc_tq_mot2FrcDrvTqDirR_Nm * rtb_Switch1_d4;

  /* RelationalOperator: '<S175>/Relational Operator2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   *  RelationalOperator: '<S175>/Relational Operator4'
   *  RelationalOperator: '<S178>/Relational Operator2'
   *  RelationalOperator: '<S188>/Relational Operator2'
   */
  rtb_RelationalOperator2_a_tmp = swc_TCOO_ARID_DEF.DataTypeConversion7;

  /* RelationalOperator: '<S175>/Relational Operator2' incorporates:
   *  Constant: '<S181>/Constant'
   */
  rtb_RelationalOperator2_ex = (rtb_RelationalOperator2_a_tmp ==
    DriveDir_REVERSE);

  /* RelationalOperator: '<S178>/Relational Operator2' incorporates:
   *  Constant: '<S182>/Constant'
   *  RelationalOperator: '<S175>/Relational Operator4'
   */
  rtb_RelationalOperator2_k = (rtb_RelationalOperator2_a_tmp ==
    DriveDir_NO_DRIVE);

  /* Logic: '<S175>/Logical Operator2' incorporates:
   *  Constant: '<S175>/Constant6'
   *  UnitDelay: '<S175>/Unit Delay'
   */
  rtb_LogicalOperator2_mp = (eadc_b_useGearR2NTqDirSwt &&
    swc_TCOO_ARID_DEF.UnitDelay_DSTATE_g && rtb_RelationalOperator2_k);

  /* Logic: '<S175>/Logical Operator3' incorporates:
   *  Constant: '<S175>/Constant10'
   *  Constant: '<S175>/Constant7'
   *  Constant: '<S175>/Constant8'
   *  Logic: '<S175>/Logical Operator4'
   *  Logic: '<S175>/Logical Operator5'
   *  Logic: '<S175>/Logical Operator6'
   *  RelationalOperator: '<S175>/Relational Operator3'
   *  RelationalOperator: '<S175>/Relational Operator5'
   *  UnitDelay: '<S175>/Unit Delay1'
   */
  rtb_LogicalOperator3_dl = ((!rtb_RelationalOperator2_k) ||
    (rtb_RelationalOperator2_k && (eadd_tq_axle2TgtTq_Nm <= 0.0F) &&
     (eadd_tq_mot2TgtTqReq_Nm == 0.0F)) || (!eadc_b_useGearR2NTqDirSwt));

  /* Switch: '<S175>/Switch2' */
  if (rtb_RelationalOperator2_ex) {
    /* Switch: '<S175>/Switch2' incorporates:
     *  Gain: '<S175>/Gain1'
     */
    rtb_Switch2_cg = (-1.0F) * eadd_tq_axle2TgtTq_Nm;
  } else {
    /* Switch: '<S175>/Switch2' */
    rtb_Switch2_cg = eadd_tq_axle2TgtTq_Nm;
  }

  /* End of Switch: '<S175>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S175>/SR_latch' */
  swc_TCOO_SR_latch(rtb_LogicalOperator2_mp, rtb_LogicalOperator3_dl,
                    &rtb_LogicalOperator3_mc,
                    &swc_TCOO_ARID_DEF.ARID_DEF_SR_latch);

  /* End of Outputs for SubSystem: '<S175>/SR_latch' */

  /* SignalConversion generated from: '<S175>/SR_latch' */
  eadd_b_gearR2NTqDirSwt = rtb_LogicalOperator3_mc;

  /* RelationalOperator: '<S175>/Relational Operator1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion167'
   *  RelationalOperator: '<S188>/Relational Operator1'
   */
  tmp = swc_TCOO_ARID_DEF.DataTypeConversion167;

  /* Switch: '<S175>/Switch3' incorporates:
   *  Constant: '<S175>/Constant5'
   *  Constant: '<S180>/Constant'
   *  Logic: '<S175>/Logical Operator'
   *  Logic: '<S175>/Logical Operator1'
   *  RelationalOperator: '<S175>/Relational Operator1'
   *  Switch: '<S175>/Switch1'
   */
  if (rtb_RelationalOperator2_ex && (tmp == BrakePedalStatus_PRESSED) &&
      eadc_b_useForceTqBrkGearR) {
    /* Switch: '<S185>/Switch2' incorporates:
     *  RelationalOperator: '<S185>/LowerRelop1'
     *  RelationalOperator: '<S185>/UpperRelop'
     *  Switch: '<S185>/Switch'
     */
    if (rtb_Product4_k > rtb_MinMax2_n) {
      rtb_Product4_k = rtb_MinMax2_n;
    } else if (rtb_Product4_k < rtb_MinMax1_fv) {
      /* Switch: '<S185>/Switch' */
      rtb_Product4_k = rtb_MinMax1_fv;
    }

    /* MinMax: '<S199>/MinMax2' incorporates:
     *  Gain: '<S175>/Gain2'
     *  Switch: '<S185>/Switch2'
     */
    rtb_MinMax2_n = (-1.0F) * rtb_Product4_k;
  } else if (eadd_b_gearR2NTqDirSwt) {
    /* Switch: '<S184>/Switch2' incorporates:
     *  Constant: '<S175>/Constant3'
     *  Constant: '<S175>/Constant4'
     *  RelationalOperator: '<S184>/LowerRelop1'
     *  RelationalOperator: '<S184>/UpperRelop'
     *  Switch: '<S184>/Switch'
     */
    if (rtb_Switch2_cg > ((float32)TRQ_ZERO)) {
      /* Switch: '<S175>/Switch1' incorporates:
       *  MinMax: '<S199>/MinMax2'
       */
      rtb_MinMax2_n = ((float32)TRQ_ZERO);
    } else if (rtb_Switch2_cg < ((float32)WHL_TRQ_MIN)) {
      /* Switch: '<S184>/Switch' incorporates:
       *  Constant: '<S175>/Constant4'
       *  MinMax: '<S199>/MinMax2'
       *  Switch: '<S175>/Switch1'
       */
      rtb_MinMax2_n = ((float32)WHL_TRQ_MIN);
    } else {
      /* Switch: '<S175>/Switch1' incorporates:
       *  MinMax: '<S199>/MinMax2'
       *  Switch: '<S184>/Switch'
       */
      rtb_MinMax2_n = rtb_Switch2_cg;
    }

    /* End of Switch: '<S184>/Switch2' */
  } else {
    /* MinMax: '<S199>/MinMax2' incorporates:
     *  Switch: '<S175>/Switch1'
     */
    rtb_MinMax2_n = rtb_Switch2_cg;
  }

  /* End of Switch: '<S175>/Switch3' */

  /* Product: '<S175>/Product1' */
  eadd_tq_mot2TgtTqUnfilt_Nm = 1.0F / rtb_Switch1_d4 * rtb_MinMax2_n;

  /* Logic: '<S188>/Logical Operator2' incorporates:
   *  Constant: '<S188>/Constant1'
   *  Constant: '<S188>/Constant10'
   *  Constant: '<S188>/Constant7'
   *  Logic: '<S188>/Logical Operator1'
   *  Logic: '<S188>/Logical Operator11'
   *  Logic: '<S188>/Logical Operator42'
   *  Logic: '<S188>/Logical Operator43'
   *  Logic: '<S188>/Logical Operator7'
   *  RelationalOperator: '<S188>/Relational Operator3'
   */
  swctcoo_eadd_b_ehbOvrCtl = ((tcoo_eadd_b_ehbMsgErrDebd &&
    eadc_b_disMot2ZeroCrossDurESP && (tdad_tq_whlDem_Nm <= 0.0F)) ||
    (!eadc_b_enaMot2ZeroCrossRamp) || (swctcoo_tqdd_b_ehbOvrCtl ||
    (swctcoo_tqdd_b_ehbVlcOvrCtl && (!tcoo_tqdd_b_gpOvrdCtrlFilt))) ||
    tqdd_b_absOvrCtl_flg);

  /* Logic: '<S188>/Logical Operator3' incorporates:
   *  Constant: '<S180>/Constant'
   *  Constant: '<S188>/Constant5'
   *  Constant: '<S190>/Constant'
   *  Constant: '<S191>/Constant'
   *  Logic: '<S188>/Logical Operator4'
   *  RelationalOperator: '<S175>/Relational Operator1'
   *  RelationalOperator: '<S188>/Relational Operator1'
   *  RelationalOperator: '<S190>/Compare'
   *  RelationalOperator: '<S191>/Compare'
   */
  swctcoo_eadd_b_adcOvrCtl = (swctcoo_eadc_b_enaAdcFild && (tmp !=
    BrakePedalStatus_PRESSED) && ((swctcoo_tdad_st_adcCtrlSts == ((uint8)0U)) ||
    (swctcoo_tdad_st_adcCtrlSts == ((uint8)1U))));

  /* Logic: '<S188>/Logical Operator13' incorporates:
   *  Logic: '<S188>/Logical Operator16'
   */
  rtb_RelationalOperator2_k_tmp = !swctcoo_eadd_b_ehbOvrCtl;

  /* RelationalOperator: '<S178>/Relational Operator2' incorporates:
   *  Constant: '<S188>/Constant13'
   *  Logic: '<S188>/Logical Operator12'
   *  Logic: '<S188>/Logical Operator13'
   *  Logic: '<S188>/Logical Operator37'
   */
  rtb_RelationalOperator2_k = ((rtb_RelationalOperator2_k_tmp &&
    swctcoo_eadd_b_adcOvrCtl) || swctcoo_eadc_b_enaCtlFild);

  /* Switch: '<S188>/Switch8' incorporates:
   *  Logic: '<S188>/Logical Operator14'
   *  Switch: '<S195>/Switch1'
   */
  if (!rtb_RelationalOperator2_k) {
    /* Switch: '<S199>/Switch1' incorporates:
     *  UnitDelay: '<S188>/Unit Delay1'
     */
    rtb_Switch1_d4 = swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_k;

    /* MinMax: '<S199>/MinMax3' incorporates:
     *  UnitDelay: '<S188>/Unit Delay1'
     */
    rtb_MinMax2_n = swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_k;
  } else {
    /* Switch: '<S199>/Switch1' */
    rtb_Switch1_d4 = eadd_tq_mot2TgtTqUnfilt_Nm;

    /* MinMax: '<S199>/MinMax3' incorporates:
     *  UnitDelay: '<S195>/Unit Delay2'
     */
    rtb_MinMax2_n = swctcoo_eadd_tq_mot2TgtFldAdc_Nm;
  }

  /* End of Switch: '<S188>/Switch8' */

  /* Sum: '<S195>/Sum6' incorporates:
   *  Constant: '<S188>/Constant6'
   *  Constant: '<S195>/step_time6'
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  Lookup_n-D: '<S188>/2-D Lookup Table4'
   *  Lookup_n-D: '<S188>/2-D Lookup Table5'
   *  MinMax: '<S195>/MinMax'
   *  MinMax: '<S195>/MinMax1'
   *  MinMax: '<S195>/MinMax2'
   *  MinMax: '<S195>/MinMax3'
   *  Product: '<S195>/Product'
   *  Product: '<S195>/Product1'
   *  Sum: '<S195>/Sum5'
   *  UnitDelay: '<S188>/Unit Delay3'
   */
  swctcoo_eadd_tq_mot2TgtFldAdc_Nm = fminf(fmaxf(look2_iflf_binlcapw
    (swc_TCOO_ARID_DEF.DataTypeConversion4, swc_TCOO_ARID_DEF.UnitDelay3_DSTATE,
     (const float32 *)&swctcoo_eada_mot2ZroCrsAdc_X_VehSpd_kph[0], (const
    float32 *)&swctcoo_eada_mot2ZroCrsAdc_Y_MotTrq_Nm[0], (const float32 *)
     &swctcoo_eadm_mot2ZroCrsIncAdc_Z_Nmps[0], swc_TCOO_ConstP.pooled14, 6U) *
    ((float32)EAD_TASK_INTERVAL_S), 0.0F), fmaxf(rtb_Switch1_d4 - rtb_MinMax2_n,
    fminf(0.0F, ((float32)EAD_TASK_INTERVAL_S) * look2_iflf_binlcapw
          (swc_TCOO_ARID_DEF.DataTypeConversion4,
           swc_TCOO_ARID_DEF.UnitDelay3_DSTATE, (const float32 *)
           &swctcoo_eada_mot2ZroCrsAdc_X_VehSpd_kph[0], (const float32 *)
           &swctcoo_eada_mot2ZroCrsAdc_Y_MotTrq_Nm[0], (const float32 *)
           &swctcoo_eadm_mot2ZroCrsDecAdc_Z_Nmps[0], swc_TCOO_ConstP.pooled14,
           6U)))) + rtb_MinMax2_n;

  /* Logic: '<S188>/Logical Operator46' incorporates:
   *  Logic: '<S188>/Logical Operator44'
   *  Logic: '<S188>/Logical Operator45'
   */
  rtb_LogicalOperator46 = ((!swctcoo_tqdd_b_ehbOvrCtl) &&
    (!swctcoo_tqdd_b_ehbVlcOvrCtl) && swctcoo_dtdd_b_ehbMbRgnOvrCtl);

  /* Logic: '<S188>/Logical Operator15' incorporates:
   *  Logic: '<S188>/Logical Operator17'
   *  Logic: '<S188>/Logical Operator52'
   */
  rtb_RelationalOperator2_k_tmp = (rtb_RelationalOperator2_k_tmp &&
    (!swctcoo_eadd_b_adcOvrCtl));

  /* RelationalOperator: '<S178>/Relational Operator2' incorporates:
   *  Constant: '<S188>/Constant15'
   *  Logic: '<S188>/Logical Operator15'
   *  Logic: '<S188>/Logical Operator38'
   */
  rtb_RelationalOperator2_k = ((rtb_RelationalOperator2_k_tmp &&
    rtb_LogicalOperator46) || swctcoo_eadc_b_enaCtlFild);

  /* Switch: '<S188>/Switch10' incorporates:
   *  Logic: '<S188>/Logical Operator33'
   *  Switch: '<S196>/Switch1'
   */
  if (!rtb_RelationalOperator2_k) {
    /* MinMax: '<S199>/MinMax1' incorporates:
     *  UnitDelay: '<S188>/Unit Delay1'
     */
    rtb_MinMax1_fv = swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_k;

    /* Switch: '<S199>/Switch1' incorporates:
     *  UnitDelay: '<S188>/Unit Delay1'
     */
    rtb_Switch1_d4 = swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_k;
  } else {
    /* MinMax: '<S199>/MinMax1' */
    rtb_MinMax1_fv = eadd_tq_mot2TgtTqUnfilt_Nm;

    /* Switch: '<S199>/Switch1' incorporates:
     *  UnitDelay: '<S196>/Unit Delay2'
     */
    rtb_Switch1_d4 = swctcoo_eadd_tq_mot2TgtFldEhb_Nm;
  }

  /* End of Switch: '<S188>/Switch10' */

  /* Sum: '<S196>/Sum6' incorporates:
   *  Constant: '<S188>/Constant4'
   *  Constant: '<S196>/step_time6'
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  Lookup_n-D: '<S188>/2-D Lookup Table2'
   *  Lookup_n-D: '<S188>/2-D Lookup Table3'
   *  MinMax: '<S196>/MinMax'
   *  MinMax: '<S196>/MinMax1'
   *  MinMax: '<S196>/MinMax2'
   *  MinMax: '<S196>/MinMax3'
   *  Product: '<S196>/Product'
   *  Product: '<S196>/Product1'
   *  Sum: '<S196>/Sum5'
   *  UnitDelay: '<S188>/Unit Delay2'
   */
  swctcoo_eadd_tq_mot2TgtFldEhb_Nm = fminf(fmaxf(look2_iflf_binlcapw
    (swc_TCOO_ARID_DEF.DataTypeConversion4,
     swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_d, (const float32 *)
     &swctcoo_eada_mot2ZroCrsEhb_X_VehSpd_kph[0], (const float32 *)
     &swctcoo_eada_mot2ZroCrsEhb_Y_MotTrq_Nm[0], (const float32 *)
     &swctcoo_eadm_mot2ZroCrsIncEhb_Z_Nmps[0], swc_TCOO_ConstP.pooled14, 6U) *
    ((float32)EAD_TASK_INTERVAL_S), 0.0F), fmaxf(rtb_MinMax1_fv - rtb_Switch1_d4,
    fminf(0.0F, ((float32)EAD_TASK_INTERVAL_S) * look2_iflf_binlcapw
          (swc_TCOO_ARID_DEF.DataTypeConversion4,
           swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_d, (const float32 *)
           &swctcoo_eada_mot2ZroCrsEhb_X_VehSpd_kph[0], (const float32 *)
           &swctcoo_eada_mot2ZroCrsEhb_Y_MotTrq_Nm[0], (const float32 *)
           &swctcoo_eadm_mot2ZroCrsDecEhb_Z_Nmps[0], swc_TCOO_ConstP.pooled14,
           6U)))) + rtb_Switch1_d4;

  /* Logic: '<S188>/Logical Operator50' incorporates:
   *  Constant: '<S188>/Constant19'
   */
  rtb_LogicalOperator50 = (tcoo_eadc_b_enaCrpSlopeModeFild &&
    swc_TCOO_ARID_DEF.DataTypeConversion17);

  /* Logic: '<S188>/Logical Operator52' incorporates:
   *  Logic: '<S188>/Logical Operator47'
   *  Logic: '<S188>/Logical Operator55'
   */
  rtb_RelationalOperator2_k_tmp = (rtb_RelationalOperator2_k_tmp &&
    (!rtb_LogicalOperator46));

  /* RelationalOperator: '<S178>/Relational Operator2' incorporates:
   *  Constant: '<S188>/Constant21'
   *  Logic: '<S188>/Logical Operator52'
   *  Logic: '<S188>/Logical Operator56'
   */
  rtb_RelationalOperator2_k = ((rtb_RelationalOperator2_k_tmp &&
    rtb_LogicalOperator50) || swctcoo_eadc_b_enaCtlFild);

  /* Switch: '<S188>/Switch15' incorporates:
   *  Logic: '<S188>/Logical Operator51'
   *  Switch: '<S200>/Switch1'
   */
  if (!rtb_RelationalOperator2_k) {
    /* MinMax: '<S199>/MinMax2' incorporates:
     *  UnitDelay: '<S188>/Unit Delay1'
     */
    rtb_MinMax2_n = swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_k;

    /* MinMax: '<S199>/MinMax1' incorporates:
     *  UnitDelay: '<S188>/Unit Delay1'
     */
    rtb_MinMax1_fv = swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_k;
  } else {
    /* MinMax: '<S199>/MinMax2' */
    rtb_MinMax2_n = eadd_tq_mot2TgtTqUnfilt_Nm;

    /* MinMax: '<S199>/MinMax1' incorporates:
     *  UnitDelay: '<S200>/Unit Delay2'
     */
    rtb_MinMax1_fv = tcoo_eadd_tq_mot2TgtFldCrpSlp_Nm;
  }

  /* End of Switch: '<S188>/Switch15' */

  /* Sum: '<S200>/Sum6' incorporates:
   *  Constant: '<S188>/Constant20'
   *  Constant: '<S200>/step_time6'
   *  DataTypeConversion: '<Root>/Data Type Conversion21'
   *  Lookup_n-D: '<S188>/1-D Lookup Table1'
   *  Lookup_n-D: '<S188>/1-D Lookup Table2'
   *  MinMax: '<S200>/MinMax'
   *  MinMax: '<S200>/MinMax1'
   *  MinMax: '<S200>/MinMax2'
   *  MinMax: '<S200>/MinMax3'
   *  Product: '<S200>/Product'
   *  Product: '<S200>/Product1'
   *  Sum: '<S200>/Sum5'
   */
  tcoo_eadd_tq_mot2TgtFldCrpSlp_Nm = fminf(fmaxf(look1_iflf_binlcapw
    (swc_TCOO_ARID_DEF.DataTypeConversion21, (const float32 *)
     &tcoo_eada_mot2ZroCrsCrpSlp_X_yrsAcc_mps2[0], (const float32 *)
     &tcoo_eadm_mot2ZroCrsIncCrpSlp_Y_Nmps[0], 8U) * ((float32)
    EAD_TASK_INTERVAL_S), 0.0F), fmaxf(rtb_MinMax2_n - rtb_MinMax1_fv, fminf
    (0.0F, ((float32)EAD_TASK_INTERVAL_S) * look1_iflf_binlcapw
     (swc_TCOO_ARID_DEF.DataTypeConversion21, (const float32 *)
      &tcoo_eada_mot2ZroCrsCrpSlp_X_yrsAcc_mps2[0], (const float32 *)
      &tcoo_eadm_mot2ZroCrsDecCrsSlp_Y_Nmps[0], 8U)))) + rtb_MinMax1_fv;

  /* RelationalOperator: '<S189>/Relational Operator2' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in5'
   *  RelationalOperator: '<S189>/Relational Operator3'
   *  RelationalOperator: '<S189>/Relational Operator6'
   */
  rtb_Switch1_d4 = Rte_IRead_swc_TCOO_Step_vcib_VCIP_acpd_x_accPedlPos_pct();

  /* RelationalOperator: '<S189>/Relational Operator2' incorporates:
   *  Constant: '<S189>/Constant1'
   *  Inport generated from: '<Root>/vcib_VCIP_in5'
   */
  rtb_RelationalOperator2_jf = (rtb_Switch1_d4 <= eadc_x_acceSuprsnAccPdlLo_pct);

  /* Product: '<S189>/Divide1' incorporates:
   *  Constant: '<S189>/Constant12'
   *  Constant: '<S189>/Constant13'
   *  Constant: '<S189>/Constant16'
   *  Constant: '<S189>/Constant3'
   *  Constant: '<S189>/Constant4'
   *  Constant: '<S189>/Constant5'
   *  MinMax: '<S189>/MinMax1'
   *  MinMax: '<S189>/MinMax2'
   *  Product: '<S189>/Divide'
   *  Sum: '<S189>/Plus'
   */
  rtb_MinMax2_n = (eadc_x_acceSuprsnAccPdlHi_pct - eadc_x_acceSuprsnAccPdlLo_pct)
    / fmaxf(eadc_x_accPdlRate_pctps, 0.1F) / fmaxf(((float32)EAD_TASK_INTERVAL_S),
    0.01F);

  /* Delay: '<S189>/Delay' */
  if (rtb_MinMax2_n < 1.0F) {
    /* Delay: '<S189>/Delay' */
    rtb_Delay = rtb_RelationalOperator2_jf;
  } else {
    if (rtb_MinMax2_n > 100.0F) {
      idxDelay = 100;
    } else {
      idxDelay = (sint32)(uint32)fmodf(truncf(rtb_MinMax2_n), 4.2949673E+9F);
    }

    /* Delay: '<S189>/Delay' */
    rtb_Delay = swc_TCOO_ARID_DEF.Delay_DSTATE[100U - (uint32)idxDelay];
  }

  /* End of Delay: '<S189>/Delay' */

  /* Logic: '<S189>/Logical Operator' incorporates:
   *  Constant: '<S189>/Constant11'
   *  Constant: '<S189>/Constant14'
   *  Constant: '<S189>/Constant2'
   *  Logic: '<S189>/Logical Operator66'
   *  RelationalOperator: '<S189>/Relational Operator1'
   *  RelationalOperator: '<S189>/Relational Operator3'
   *  RelationalOperator: '<S189>/Relational Operator7'
   */
  rtb_LogicalOperator_b = ((swc_TCOO_ARID_DEF.DataTypeConversion172 <
    eadc_a_acceSuprsnEnSlpeHi_mps2) && (swc_TCOO_ARID_DEF.DataTypeConversion4 <
    eadc_v_acceSuprsnEnVehSpd_kph) && swc_TCOO_ARID_DEF.DataTypeConversion31 &&
    (!tcoo_eadd_b_acpCrsFltDebd) && rtb_Delay && (rtb_Switch1_d4 >=
    eadc_x_acceSuprsnAccPdlHi_pct));

  /* Logic: '<S189>/Logical Operator2' incorporates:
   *  Constant: '<S189>/Constant6'
   *  Constant: '<S189>/Constant8'
   *  Logic: '<S189>/Logical Operator1'
   *  RelationalOperator: '<S189>/Relational Operator4'
   *  RelationalOperator: '<S189>/Relational Operator6'
   */
  rtb_LogicalOperator2_jm = ((swc_TCOO_ARID_DEF.DataTypeConversion4 >=
    eadc_v_acceSuprsnQutVehSpd_kph) || (rtb_Switch1_d4 <
    eadc_x_acceSuprsnAccPdlHi_pct));

  /* Outputs for Atomic SubSystem: '<S189>/SR_latch1' */
  swc_TCOO_SR_latch(rtb_LogicalOperator_b, rtb_LogicalOperator2_jm,
                    &rtb_RelationalOperator2_k,
                    &swc_TCOO_ARID_DEF.ARID_DEF_SR_latch1);

  /* End of Outputs for SubSystem: '<S189>/SR_latch1' */

  /* Logic: '<S189>/Logical Operator3' incorporates:
   *  Constant: '<S189>/Constant9'
   *  Constant: '<S202>/Constant'
   *  RelationalOperator: '<S202>/Compare'
   */
  eadd_b_whlAcceSupprsn = ((swc_TCOO_ARID_DEF.DataTypeConversion30 == 1.0) &&
    eadc_b_enAcceSuprsn && rtb_RelationalOperator2_k);

  /* Logic: '<S188>/Logical Operator47' incorporates:
   *  Logic: '<S188>/Logical Operator18'
   *  Logic: '<S188>/Logical Operator62'
   */
  rtb_RelationalOperator2_k_tmp = (rtb_RelationalOperator2_k_tmp &&
    (!rtb_LogicalOperator50));

  /* RelationalOperator: '<S178>/Relational Operator2' incorporates:
   *  Constant: '<S188>/Constant22'
   *  Logic: '<S188>/Logical Operator47'
   *  Logic: '<S188>/Logical Operator61'
   */
  rtb_RelationalOperator2_k = ((rtb_RelationalOperator2_k_tmp &&
    eadd_b_whlAcceSupprsn) || swctcoo_eadc_b_enaCtlFild);

  /* Switch: '<S188>/Switch17' incorporates:
   *  Logic: '<S188>/Logical Operator66'
   *  Switch: '<S201>/Switch1'
   */
  if (!rtb_RelationalOperator2_k) {
    /* MinMax: '<S199>/MinMax1' incorporates:
     *  UnitDelay: '<S188>/Unit Delay1'
     */
    rtb_MinMax1_fv = swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_k;

    /* Switch: '<S199>/Switch1' incorporates:
     *  UnitDelay: '<S188>/Unit Delay1'
     */
    rtb_Switch1_d4 = swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_k;
  } else {
    /* MinMax: '<S199>/MinMax1' */
    rtb_MinMax1_fv = eadd_tq_mot2TgtTqUnfilt_Nm;

    /* Switch: '<S199>/Switch1' incorporates:
     *  UnitDelay: '<S201>/Unit Delay2'
     */
    rtb_Switch1_d4 = eadd_tq_mot2TgtFldAcceLmt_Nm;
  }

  /* End of Switch: '<S188>/Switch17' */

  /* Sum: '<S201>/Sum6' incorporates:
   *  Constant: '<S188>/Constant23'
   *  Constant: '<S201>/step_time6'
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  Lookup_n-D: '<S188>/2-D Lookup Table10'
   *  Lookup_n-D: '<S188>/2-D Lookup Table11'
   *  MinMax: '<S201>/MinMax'
   *  MinMax: '<S201>/MinMax1'
   *  MinMax: '<S201>/MinMax2'
   *  MinMax: '<S201>/MinMax3'
   *  Product: '<S201>/Product'
   *  Product: '<S201>/Product1'
   *  Sum: '<S201>/Sum5'
   *  UnitDelay: '<S188>/Unit Delay6'
   */
  eadd_tq_mot2TgtFldAcceLmt_Nm = fminf(fmaxf(look2_iflf_binlcapw
    (swc_TCOO_ARID_DEF.DataTypeConversion4, swc_TCOO_ARID_DEF.UnitDelay6_DSTATE,
     (const float32 *)&eada_mot2ZroCrsAcceLmt_X_VehSpd_kph[0], (const float32 *)
     &eada_mot2ZroCrsAcceLmt_Y_MotTrq_Nm[0], (const float32 *)
     &eadm_mot2ZroCrsIncAcceLmt_Z_Nmps[0], swc_TCOO_ConstP.pooled14, 6U) *
    ((float32)EAD_TASK_INTERVAL_S), 0.0F), fmaxf(rtb_MinMax1_fv - rtb_Switch1_d4,
    fminf(0.0F, ((float32)EAD_TASK_INTERVAL_S) * look2_iflf_binlcapw
          (swc_TCOO_ARID_DEF.DataTypeConversion4,
           swc_TCOO_ARID_DEF.UnitDelay6_DSTATE, (const float32 *)
           &eada_mot2ZroCrsAcceLmt_X_VehSpd_kph[0], (const float32 *)
           &eada_mot2ZroCrsAcceLmt_Y_MotTrq_Nm[0], (const float32 *)
           &eadm_mot2ZroCrsDecAcceLmt_Z_Nmps[0], swc_TCOO_ConstP.pooled14, 6U))))
    + rtb_Switch1_d4;

  /* Logic: '<S188>/Logical Operator9' incorporates:
   *  Constant: '<S188>/Constant11'
   *  Constant: '<S188>/Constant14'
   *  Constant: '<S192>/Constant'
   *  Logic: '<S188>/Logical Operator6'
   *  Logic: '<S188>/Logical Operator8'
   *  RelationalOperator: '<S192>/Compare'
   */
  swctcoo_eadd_b_vehSptModCtl = ((swc_TCOO_ARID_DEF.DataTypeConversion1 ||
    (swc_TCOO_ARID_DEF.DataTypeConversion160 &&
     swctcoo_eadc_b_useSportMapsIn4WDMode)) && swctcoo_eadc_b_enaSptModeFild &&
    (swc_TCOO_ARID_DEF.DataTypeConversion170 == 1.0));

  /* Logic: '<S188>/Logical Operator18' incorporates:
   *  Logic: '<S188>/Logical Operator22'
   *  Logic: '<S188>/Logical Operator63'
   */
  rtb_RelationalOperator2_k_tmp = (rtb_RelationalOperator2_k_tmp &&
    (!eadd_b_whlAcceSupprsn));

  /* RelationalOperator: '<S178>/Relational Operator2' incorporates:
   *  Constant: '<S188>/Constant16'
   *  Logic: '<S188>/Logical Operator18'
   *  Logic: '<S188>/Logical Operator39'
   */
  rtb_RelationalOperator2_k = ((rtb_RelationalOperator2_k_tmp &&
    swctcoo_eadd_b_vehSptModCtl) || swctcoo_eadc_b_enaCtlFild);

  /* Switch: '<S188>/Switch9' incorporates:
   *  Logic: '<S188>/Logical Operator34'
   *  Switch: '<S197>/Switch1'
   */
  if (!rtb_RelationalOperator2_k) {
    /* MinMax: '<S199>/MinMax1' incorporates:
     *  UnitDelay: '<S188>/Unit Delay1'
     */
    rtb_MinMax1_fv = swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_k;

    /* Switch: '<S199>/Switch1' incorporates:
     *  UnitDelay: '<S188>/Unit Delay1'
     */
    rtb_Switch1_d4 = swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_k;
  } else {
    /* MinMax: '<S199>/MinMax1' */
    rtb_MinMax1_fv = eadd_tq_mot2TgtTqUnfilt_Nm;

    /* Switch: '<S199>/Switch1' incorporates:
     *  UnitDelay: '<S197>/Unit Delay2'
     */
    rtb_Switch1_d4 = swctcoo_eadd_tq_mot2TgtFldSpt_Nm;
  }

  /* End of Switch: '<S188>/Switch9' */

  /* Sum: '<S197>/Sum6' incorporates:
   *  Constant: '<S188>/Constant8'
   *  Constant: '<S197>/step_time6'
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  Lookup_n-D: '<S188>/2-D Lookup Table6'
   *  Lookup_n-D: '<S188>/2-D Lookup Table7'
   *  MinMax: '<S197>/MinMax'
   *  MinMax: '<S197>/MinMax1'
   *  MinMax: '<S197>/MinMax2'
   *  MinMax: '<S197>/MinMax3'
   *  Product: '<S197>/Product'
   *  Product: '<S197>/Product1'
   *  Sum: '<S197>/Sum5'
   *  UnitDelay: '<S188>/Unit Delay4'
   */
  swctcoo_eadd_tq_mot2TgtFldSpt_Nm = fminf(fmaxf(look2_iflf_binlcapw
    (swc_TCOO_ARID_DEF.DataTypeConversion4, swc_TCOO_ARID_DEF.UnitDelay4_DSTATE,
     (const float32 *)&eada_mot2ZeroCross_X_VehSpd_kph[0], (const float32 *)
     &eada_mot2ZeroCross_Y_MotTrq_Nm[0], (const float32 *)
     &swctcoo_eadm_mot2ZroCrsIncSpt_Z_Nmps[0], swc_TCOO_ConstP.pooled14, 6U) *
    ((float32)EAD_TASK_INTERVAL_S), 0.0F), fmaxf(rtb_MinMax1_fv - rtb_Switch1_d4,
    fminf(0.0F, ((float32)EAD_TASK_INTERVAL_S) * look2_iflf_binlcapw
          (swc_TCOO_ARID_DEF.DataTypeConversion4,
           swc_TCOO_ARID_DEF.UnitDelay4_DSTATE, (const float32 *)
           &eada_mot2ZeroCross_X_VehSpd_kph[0], (const float32 *)
           &eada_mot2ZeroCross_Y_MotTrq_Nm[0], (const float32 *)
           &swctcoo_eadm_mot2ZroCrsDecSpt_Z_Nmps[0], swc_TCOO_ConstP.pooled14,
           6U)))) + rtb_Switch1_d4;

  /* Logic: '<S188>/Logical Operator10' incorporates:
   *  Constant: '<S188>/Constant12'
   */
  swctcoo_eadd_b_vehEcoModCtl = (swc_TCOO_ARID_DEF.DataTypeConversion6 &&
    swctcoo_eadc_b_enaEcoModeFild);

  /* Logic: '<S188>/Logical Operator22' incorporates:
   *  Logic: '<S188>/Logical Operator26'
   *  Logic: '<S188>/Logical Operator27'
   */
  rtb_RelationalOperator2_k_tmp = (rtb_RelationalOperator2_k_tmp &&
    (!swctcoo_eadd_b_vehSptModCtl));

  /* RelationalOperator: '<S178>/Relational Operator2' incorporates:
   *  Constant: '<S188>/Constant17'
   *  Logic: '<S188>/Logical Operator22'
   *  Logic: '<S188>/Logical Operator40'
   */
  rtb_RelationalOperator2_k = ((rtb_RelationalOperator2_k_tmp &&
    swctcoo_eadd_b_vehEcoModCtl) || swctcoo_eadc_b_enaCtlFild);

  /* Switch: '<S188>/Switch11' incorporates:
   *  Logic: '<S188>/Logical Operator35'
   *  Switch: '<S198>/Switch1'
   */
  if (!rtb_RelationalOperator2_k) {
    /* MinMax: '<S199>/MinMax1' incorporates:
     *  UnitDelay: '<S188>/Unit Delay1'
     */
    rtb_MinMax1_fv = swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_k;

    /* Switch: '<S199>/Switch1' incorporates:
     *  UnitDelay: '<S188>/Unit Delay1'
     */
    rtb_Switch1_d4 = swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_k;
  } else {
    /* MinMax: '<S199>/MinMax1' */
    rtb_MinMax1_fv = eadd_tq_mot2TgtTqUnfilt_Nm;

    /* Switch: '<S199>/Switch1' incorporates:
     *  UnitDelay: '<S198>/Unit Delay2'
     */
    rtb_Switch1_d4 = swctcoo_eadd_tq_mot2TgtFldEco_Nm;
  }

  /* End of Switch: '<S188>/Switch11' */

  /* Sum: '<S198>/Sum6' incorporates:
   *  Constant: '<S188>/Constant9'
   *  Constant: '<S198>/step_time6'
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  Lookup_n-D: '<S188>/2-D Lookup Table8'
   *  Lookup_n-D: '<S188>/2-D Lookup Table9'
   *  MinMax: '<S198>/MinMax'
   *  MinMax: '<S198>/MinMax1'
   *  MinMax: '<S198>/MinMax2'
   *  MinMax: '<S198>/MinMax3'
   *  Product: '<S198>/Product'
   *  Product: '<S198>/Product1'
   *  Sum: '<S198>/Sum5'
   *  UnitDelay: '<S188>/Unit Delay5'
   */
  swctcoo_eadd_tq_mot2TgtFldEco_Nm = fminf(fmaxf(look2_iflf_binlcapw
    (swc_TCOO_ARID_DEF.DataTypeConversion4, swc_TCOO_ARID_DEF.UnitDelay5_DSTATE,
     (const float32 *)&eada_mot2ZeroCross_X_VehSpd_kph[0], (const float32 *)
     &eada_mot2ZeroCross_Y_MotTrq_Nm[0], (const float32 *)
     &swctcoo_eadm_mot2ZroCrsIncEco_Z_Nmps[0], swc_TCOO_ConstP.pooled14, 6U) *
    ((float32)EAD_TASK_INTERVAL_S), 0.0F), fmaxf(rtb_MinMax1_fv - rtb_Switch1_d4,
    fminf(0.0F, ((float32)EAD_TASK_INTERVAL_S) * look2_iflf_binlcapw
          (swc_TCOO_ARID_DEF.DataTypeConversion4,
           swc_TCOO_ARID_DEF.UnitDelay5_DSTATE, (const float32 *)
           &eada_mot2ZeroCross_X_VehSpd_kph[0], (const float32 *)
           &eada_mot2ZeroCross_Y_MotTrq_Nm[0], (const float32 *)
           &swctcoo_eadm_mot2ZroCrsDecEco_Z_Nmps[0], swc_TCOO_ConstP.pooled14,
           6U)))) + rtb_Switch1_d4;

  /* RelationalOperator: '<S178>/Relational Operator2' incorporates:
   *  Constant: '<S188>/Constant18'
   *  Logic: '<S188>/Logical Operator27'
   *  Logic: '<S188>/Logical Operator32'
   *  Logic: '<S188>/Logical Operator41'
   */
  rtb_RelationalOperator2_k = ((rtb_RelationalOperator2_k_tmp &&
    (!swctcoo_eadd_b_vehEcoModCtl)) || swctcoo_eadc_b_enaCtlFild);

  /* Switch: '<S188>/Switch12' incorporates:
   *  Logic: '<S188>/Logical Operator36'
   *  Switch: '<S199>/Switch1'
   */
  if (!rtb_RelationalOperator2_k) {
    /* MinMax: '<S199>/MinMax1' incorporates:
     *  UnitDelay: '<S188>/Unit Delay1'
     */
    rtb_MinMax1_fv = swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_k;

    /* Switch: '<S199>/Switch1' incorporates:
     *  UnitDelay: '<S188>/Unit Delay1'
     */
    rtb_Switch1_d4 = swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_k;
  } else {
    /* MinMax: '<S199>/MinMax1' */
    rtb_MinMax1_fv = eadd_tq_mot2TgtTqUnfilt_Nm;

    /* Switch: '<S199>/Switch1' incorporates:
     *  UnitDelay: '<S199>/Unit Delay2'
     */
    rtb_Switch1_d4 = eadd_tq_mot2TgtTqFild_Nm;
  }

  /* End of Switch: '<S188>/Switch12' */

  /* Sum: '<S199>/Sum6' incorporates:
   *  Constant: '<S188>/Constant2'
   *  Constant: '<S199>/step_time6'
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  Lookup_n-D: '<S188>/2-D Lookup Table'
   *  Lookup_n-D: '<S188>/2-D Lookup Table1'
   *  MinMax: '<S199>/MinMax'
   *  MinMax: '<S199>/MinMax1'
   *  MinMax: '<S199>/MinMax2'
   *  MinMax: '<S199>/MinMax3'
   *  Product: '<S199>/Product'
   *  Product: '<S199>/Product1'
   *  Sum: '<S199>/Sum5'
   *  UnitDelay: '<S188>/Unit Delay'
   */
  eadd_tq_mot2TgtTqFild_Nm = fminf(fmaxf(look2_iflf_binlcapw
    (swc_TCOO_ARID_DEF.DataTypeConversion4, swc_TCOO_ARID_DEF.UnitDelay_DSTATE,
     (const float32 *)&eada_mot2ZeroCross_X_VehSpd_kph[0], (const float32 *)
     &eada_mot2ZeroCross_Y_MotTrq_Nm[0], (const float32 *)
     &eadm_mot2ZeroCrossInc_Z_Nmps[0], swc_TCOO_ConstP.pooled14, 6U) * ((float32)
    EAD_TASK_INTERVAL_S), 0.0F), fmaxf(rtb_MinMax1_fv - rtb_Switch1_d4, fminf
    (0.0F, ((float32)EAD_TASK_INTERVAL_S) * look2_iflf_binlcapw
     (swc_TCOO_ARID_DEF.DataTypeConversion4, swc_TCOO_ARID_DEF.UnitDelay_DSTATE,
      (const float32 *)&eada_mot2ZeroCross_X_VehSpd_kph[0], (const float32 *)
      &eada_mot2ZeroCross_Y_MotTrq_Nm[0], (const float32 *)
      &eadm_mot2ZeroCrossDec_Z_Nmps[0], swc_TCOO_ConstP.pooled14, 6U)))) +
    rtb_Switch1_d4;

  /* Switch: '<S188>/Switch5' incorporates:
   *  Switch: '<S188>/Switch1'
   *  Switch: '<S188>/Switch14'
   *  Switch: '<S188>/Switch16'
   *  Switch: '<S188>/Switch3'
   *  Switch: '<S188>/Switch6'
   *  Switch: '<S188>/Switch7'
   */
  if (swctcoo_eadd_b_ehbOvrCtl) {
    /* Switch: '<S188>/Switch5' */
    eadd_tq_mot2TgtTq_Nm = eadd_tq_mot2TgtTqUnfilt_Nm;
  } else if (swctcoo_eadd_b_adcOvrCtl) {
    /* Switch: '<S188>/Switch1' incorporates:
     *  Switch: '<S188>/Switch5'
     */
    eadd_tq_mot2TgtTq_Nm = swctcoo_eadd_tq_mot2TgtFldAdc_Nm;
  } else if (rtb_LogicalOperator46) {
    /* Switch: '<S188>/Switch4' incorporates:
     *  Constant: '<S188>/Constant3'
     *  Switch: '<S188>/Switch1'
     *  Switch: '<S188>/Switch3'
     */
    if (swctcoo_eadc_b_enaEhbMbRgnFild) {
      /* Switch: '<S188>/Switch5' incorporates:
       *  Switch: '<S188>/Switch3'
       */
      eadd_tq_mot2TgtTq_Nm = swctcoo_eadd_tq_mot2TgtFldEhb_Nm;
    } else {
      /* Switch: '<S188>/Switch5' incorporates:
       *  Switch: '<S188>/Switch3'
       */
      eadd_tq_mot2TgtTq_Nm = eadd_tq_mot2TgtTqUnfilt_Nm;
    }

    /* End of Switch: '<S188>/Switch4' */
  } else if (rtb_LogicalOperator50) {
    /* Switch: '<S188>/Switch14' incorporates:
     *  Switch: '<S188>/Switch1'
     *  Switch: '<S188>/Switch3'
     *  Switch: '<S188>/Switch5'
     */
    eadd_tq_mot2TgtTq_Nm = tcoo_eadd_tq_mot2TgtFldCrpSlp_Nm;
  } else if (eadd_b_whlAcceSupprsn) {
    /* Switch: '<S188>/Switch16' incorporates:
     *  Switch: '<S188>/Switch1'
     *  Switch: '<S188>/Switch14'
     *  Switch: '<S188>/Switch3'
     *  Switch: '<S188>/Switch5'
     */
    eadd_tq_mot2TgtTq_Nm = eadd_tq_mot2TgtFldAcceLmt_Nm;
  } else if (swctcoo_eadd_b_vehSptModCtl) {
    /* Switch: '<S188>/Switch6' incorporates:
     *  Switch: '<S188>/Switch1'
     *  Switch: '<S188>/Switch14'
     *  Switch: '<S188>/Switch16'
     *  Switch: '<S188>/Switch3'
     *  Switch: '<S188>/Switch5'
     */
    eadd_tq_mot2TgtTq_Nm = swctcoo_eadd_tq_mot2TgtFldSpt_Nm;
  } else if (swctcoo_eadd_b_vehEcoModCtl) {
    /* Switch: '<S188>/Switch7' incorporates:
     *  Switch: '<S188>/Switch1'
     *  Switch: '<S188>/Switch14'
     *  Switch: '<S188>/Switch16'
     *  Switch: '<S188>/Switch3'
     *  Switch: '<S188>/Switch5'
     *  Switch: '<S188>/Switch6'
     */
    eadd_tq_mot2TgtTq_Nm = swctcoo_eadd_tq_mot2TgtFldEco_Nm;
  } else {
    /* Switch: '<S188>/Switch5' incorporates:
     *  Switch: '<S188>/Switch1'
     *  Switch: '<S188>/Switch14'
     *  Switch: '<S188>/Switch16'
     *  Switch: '<S188>/Switch3'
     *  Switch: '<S188>/Switch6'
     *  Switch: '<S188>/Switch7'
     */
    eadd_tq_mot2TgtTq_Nm = eadd_tq_mot2TgtTqFild_Nm;
  }

  /* End of Switch: '<S188>/Switch5' */

  /* Switch: '<S177>/Switch2' incorporates:
   *  Constant: '<S177>/Constant6'
   */
  if (eadc_b_enbEad2TqOvrd) {
    /* Switch: '<S177>/Switch2' incorporates:
     *  Constant: '<S177>/Constant7'
     */
    eadd_tq_mot2TgtTqReq_Nm = eadc_tq_ead2TqOvrdVal_Nm;
  } else {
    /* Switch: '<S177>/Switch2' */
    eadd_tq_mot2TgtTqReq_Nm = eadd_tq_mot2TgtTq_Nm;
  }

  /* End of Switch: '<S177>/Switch2' */

  /* RelationalOperator: '<S178>/Relational Operator2' incorporates:
   *  Constant: '<S181>/Constant'
   *  RelationalOperator: '<S175>/Relational Operator2'
   */
  rtb_RelationalOperator2_k = (rtb_RelationalOperator2_a_tmp == DriveDir_REVERSE);

  /* Switch: '<S178>/Switch1' incorporates:
   *  Switch: '<S178>/Switch2'
   */
  if (rtb_RelationalOperator2_k) {
    /* Switch: '<S178>/Switch1' incorporates:
     *  Gain: '<S178>/Gain1'
     */
    rtb_Switch1_fx = (-1.0) * swc_TCOO_ARID_DEF.DataTypeConversion46;

    /* Switch: '<S178>/Switch2' incorporates:
     *  Gain: '<S178>/Gain2'
     */
    rtb_Switch2_nk = (-1.0) * swc_TCOO_ARID_DEF.DataTypeConversion45;
  } else {
    /* Switch: '<S178>/Switch1' */
    rtb_Switch1_fx = swc_TCOO_ARID_DEF.DataTypeConversion45;

    /* Switch: '<S178>/Switch2' */
    rtb_Switch2_nk = swc_TCOO_ARID_DEF.DataTypeConversion46;
  }

  /* End of Switch: '<S178>/Switch1' */

  /* Switch: '<S188>/Switch2' incorporates:
   *  Constant: '<S181>/Constant'
   *  Gain: '<S188>/Gain2'
   *  Product: '<S188>/Product2'
   *  RelationalOperator: '<S175>/Relational Operator2'
   *  RelationalOperator: '<S188>/Relational Operator2'
   *  UnitDelay: '<S188>/Unit Delay1'
   */
  if (rtb_RelationalOperator2_a_tmp == DriveDir_REVERSE) {
    swctcoo_eadd_tq_axle2TgtUnitDlyMotTyp0_Nm =
      swc_TCOO_ARID_DEF.DataTypeConversion13 *
      swc_TCOO_ARID_DEF.DataTypeConversion25 *
      swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_k * (-1.0F);
  } else {
    swctcoo_eadd_tq_axle2TgtUnitDlyMotTyp0_Nm = rtb_Switch1_i1_tmp *
      swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_k;
  }

  /* End of Switch: '<S188>/Switch2' */

  /* Update for UnitDelay: '<S175>/Unit Delay' */
  swc_TCOO_ARID_DEF.UnitDelay_DSTATE_g = rtb_RelationalOperator2_ex;

  /* Update for UnitDelay: '<S188>/Unit Delay3' */
  swc_TCOO_ARID_DEF.UnitDelay3_DSTATE = swctcoo_eadd_tq_mot2TgtFldAdc_Nm;

  /* Update for UnitDelay: '<S188>/Unit Delay1' */
  swc_TCOO_ARID_DEF.UnitDelay1_DSTATE_k = eadd_tq_mot2TgtTq_Nm;

  /* Update for UnitDelay: '<S188>/Unit Delay2' */
  swc_TCOO_ARID_DEF.UnitDelay2_DSTATE_d = swctcoo_eadd_tq_mot2TgtFldEhb_Nm;

  /* Update for UnitDelay: '<S188>/Unit Delay6' */
  swc_TCOO_ARID_DEF.UnitDelay6_DSTATE = eadd_tq_mot2TgtFldAcceLmt_Nm;

  /* Update for Delay: '<S189>/Delay' */
  for (idxDelay = 0; idxDelay < 99; idxDelay++) {
    swc_TCOO_ARID_DEF.Delay_DSTATE[idxDelay] =
      swc_TCOO_ARID_DEF.Delay_DSTATE[idxDelay + 1];
  }

  swc_TCOO_ARID_DEF.Delay_DSTATE[99] = rtb_RelationalOperator2_jf;

  /* End of Update for Delay: '<S189>/Delay' */

  /* Update for UnitDelay: '<S188>/Unit Delay4' */
  swc_TCOO_ARID_DEF.UnitDelay4_DSTATE = swctcoo_eadd_tq_mot2TgtFldSpt_Nm;

  /* Update for UnitDelay: '<S188>/Unit Delay5' */
  swc_TCOO_ARID_DEF.UnitDelay5_DSTATE = swctcoo_eadd_tq_mot2TgtFldEco_Nm;

  /* Update for UnitDelay: '<S188>/Unit Delay' */
  swc_TCOO_ARID_DEF.UnitDelay_DSTATE = eadd_tq_mot2TgtTqFild_Nm;
}

/* System initialize for atomic system: '<S9>/SwitchRampMot2TrqDem' */
static void swc_T_SwitchRampMot2TrqDem_Init(boolean *rty_RampOn)
{
  /* SystemInitialize for Chart: '<S442>/Chart' */
  *rty_RampOn = false;
}

/* Output and update for atomic system: '<S9>/SwitchRampMot2TrqDem' */
static void swc_TCOO_SwitchRampMot2TrqDem(float32 rtu_u1, boolean rtu_sw,
  float32 rtu_u2, float32 rtu_up, float32 rtu_lo, boolean *rty_RampOn,
  ARID_DEF_switch_ramp_swc_TC_c_T *swc_TCOO__ARID_DEF_arg)
{
  float32 rtb_MinMax1_ni;
  float32 rtb_MinMax_d;

  /* MinMax: '<S439>/MinMax' incorporates:
   *  Constant: '<S439>/Constant1'
   *  Constant: '<S439>/Constant2'
   *  Product: '<S439>/Product'
   */
  rtb_MinMax_d = fmaxf(rtu_up * 0.01F, 0.0F);

  /* MinMax: '<S439>/MinMax1' incorporates:
   *  Constant: '<S439>/Constant1'
   *  Constant: '<S439>/Constant2'
   *  Product: '<S439>/Product1'
   */
  rtb_MinMax1_ni = fminf(0.0F, 0.01F * rtu_lo);

  /* Chart: '<S442>/Chart' */
  if (swc_TCOO__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li == 0U) {
    swc_TCOO__ARID_DEF_arg->is_active_c11_Ricardo_SW_dev_li = 1U;
    swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_TCOO_IN_U2_p;
    *rty_RampOn = false;
    tvrd_tq_mot2TgtTqReq_Nm = rtu_u2;
  } else {
    switch (swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib) {
     case swc_TCOO_IN_U1_o:
      *rty_RampOn = false;
      if (!rtu_sw) {
        if (rtu_u2 >= rtu_u1) {
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_TCOO_IN_U1_TO_U2_i;
          swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_U1_TO_U2_INC_i;
          *rty_RampOn = true;
          tvrd_tq_mot2TgtTqReq_Nm = fminf(fmaxf(fminf(rtu_u2 -
            tvrd_tq_mot2TgtTqReq_Nm, rtb_MinMax_d) + tvrd_tq_mot2TgtTqReq_Nm,
            rtu_u1), rtu_u2);
        } else {
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_TCOO_IN_U1_TO_U2_i;
          swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_U1_TO_U2_DEC_i;
          *rty_RampOn = true;
          tvrd_tq_mot2TgtTqReq_Nm = fmaxf(fminf(fmaxf(rtu_u2 -
            tvrd_tq_mot2TgtTqReq_Nm, rtb_MinMax1_ni) + tvrd_tq_mot2TgtTqReq_Nm,
            rtu_u1), rtu_u2);
        }
      } else {
        tvrd_tq_mot2TgtTqReq_Nm = rtu_u1;
      }
      break;

     case swc_TCOO_IN_U1_TO_U2_i:
      if (rtu_sw) {
        if (rtu_u1 >= rtu_u2) {
          swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_NO_ACTIVE_CHILD_h;
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_TCOO_IN_U2_TO_U1_l;
          swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_U2_TO_U1_INC_pd;
          *rty_RampOn = true;
          tvrd_tq_mot2TgtTqReq_Nm = fminf(fmaxf(fminf(rtu_u1 -
            tvrd_tq_mot2TgtTqReq_Nm, rtb_MinMax_d) + tvrd_tq_mot2TgtTqReq_Nm,
            rtu_u2), rtu_u1);
        } else {
          swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_NO_ACTIVE_CHILD_h;
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_TCOO_IN_U2_TO_U1_l;
          swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_U2_TO_U1_DEC_m;
          *rty_RampOn = true;
          tvrd_tq_mot2TgtTqReq_Nm = fmaxf(fminf(fmaxf(rtu_u1 -
            tvrd_tq_mot2TgtTqReq_Nm, rtb_MinMax1_ni) + tvrd_tq_mot2TgtTqReq_Nm,
            rtu_u2), rtu_u1);
        }
      } else if (swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 ==
                 swc_TCOO_IN_U1_TO_U2_DEC_i) {
        *rty_RampOn = true;
        rtb_MinMax_d = rtu_u2 - tvrd_tq_mot2TgtTqReq_Nm;
        if (rtb_MinMax_d >= rtb_MinMax1_ni) {
          swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_NO_ACTIVE_CHILD_h;
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_TCOO_IN_U2_p;
          *rty_RampOn = false;
          tvrd_tq_mot2TgtTqReq_Nm = rtu_u2;
        } else {
          tvrd_tq_mot2TgtTqReq_Nm = fmaxf(fminf(fmaxf(rtb_MinMax_d,
            rtb_MinMax1_ni) + tvrd_tq_mot2TgtTqReq_Nm, rtu_u1), rtu_u2);
        }
      } else {
        /* case IN_U1_TO_U2_INC: */
        *rty_RampOn = true;
        if (rtu_u2 - tvrd_tq_mot2TgtTqReq_Nm <= rtb_MinMax_d) {
          swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_NO_ACTIVE_CHILD_h;
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_TCOO_IN_U2_p;
          *rty_RampOn = false;
          tvrd_tq_mot2TgtTqReq_Nm = rtu_u2;
        } else {
          tvrd_tq_mot2TgtTqReq_Nm = fminf(fmaxf(fminf(rtu_u2 -
            tvrd_tq_mot2TgtTqReq_Nm, rtb_MinMax_d) + tvrd_tq_mot2TgtTqReq_Nm,
            rtu_u1), rtu_u2);
        }
      }
      break;

     case swc_TCOO_IN_U2_p:
      *rty_RampOn = false;
      if (rtu_sw) {
        if (rtu_u1 >= rtu_u2) {
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_TCOO_IN_U2_TO_U1_l;
          swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_U2_TO_U1_INC_pd;
          *rty_RampOn = true;
          tvrd_tq_mot2TgtTqReq_Nm = fminf(fmaxf(fminf(rtu_u1 -
            tvrd_tq_mot2TgtTqReq_Nm, rtb_MinMax_d) + tvrd_tq_mot2TgtTqReq_Nm,
            rtu_u2), rtu_u1);
        } else {
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_TCOO_IN_U2_TO_U1_l;
          swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_U2_TO_U1_DEC_m;
          *rty_RampOn = true;
          tvrd_tq_mot2TgtTqReq_Nm = fmaxf(fminf(fmaxf(rtu_u1 -
            tvrd_tq_mot2TgtTqReq_Nm, rtb_MinMax1_ni) + tvrd_tq_mot2TgtTqReq_Nm,
            rtu_u2), rtu_u1);
        }
      } else {
        tvrd_tq_mot2TgtTqReq_Nm = rtu_u2;
      }
      break;

     default:
      /* case IN_U2_TO_U1: */
      if (!rtu_sw) {
        if (rtu_u2 >= rtu_u1) {
          swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_NO_ACTIVE_CHILD_h;
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_TCOO_IN_U1_TO_U2_i;
          swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_U1_TO_U2_INC_i;
          *rty_RampOn = true;
          tvrd_tq_mot2TgtTqReq_Nm = fminf(fmaxf(fminf(rtu_u2 -
            tvrd_tq_mot2TgtTqReq_Nm, rtb_MinMax_d) + tvrd_tq_mot2TgtTqReq_Nm,
            rtu_u1), rtu_u2);
        } else {
          swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_NO_ACTIVE_CHILD_h;
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib =
            swc_TCOO_IN_U1_TO_U2_i;
          swc_TCOO__ARID_DEF_arg->is_U1_TO_U2 = swc_TCOO_IN_U1_TO_U2_DEC_i;
          *rty_RampOn = true;
          tvrd_tq_mot2TgtTqReq_Nm = fmaxf(fminf(fmaxf(rtu_u2 -
            tvrd_tq_mot2TgtTqReq_Nm, rtb_MinMax1_ni) + tvrd_tq_mot2TgtTqReq_Nm,
            rtu_u1), rtu_u2);
        }
      } else if (swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 ==
                 swc_TCOO_IN_U2_TO_U1_DEC_m) {
        *rty_RampOn = true;
        rtb_MinMax_d = rtu_u1 - tvrd_tq_mot2TgtTqReq_Nm;
        if (rtb_MinMax_d >= rtb_MinMax1_ni) {
          swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_NO_ACTIVE_CHILD_h;
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_TCOO_IN_U1_o;
          *rty_RampOn = false;
          tvrd_tq_mot2TgtTqReq_Nm = rtu_u1;
        } else {
          tvrd_tq_mot2TgtTqReq_Nm = fmaxf(fminf(fmaxf(rtb_MinMax_d,
            rtb_MinMax1_ni) + tvrd_tq_mot2TgtTqReq_Nm, rtu_u2), rtu_u1);
        }
      } else {
        /* case IN_U2_TO_U1_INC: */
        *rty_RampOn = true;
        if (rtu_u1 - tvrd_tq_mot2TgtTqReq_Nm <= rtb_MinMax_d) {
          swc_TCOO__ARID_DEF_arg->is_U2_TO_U1 = swc_TCOO_IN_NO_ACTIVE_CHILD_h;
          swc_TCOO__ARID_DEF_arg->is_c11_Ricardo_SW_dev_lib = swc_TCOO_IN_U1_o;
          *rty_RampOn = false;
          tvrd_tq_mot2TgtTqReq_Nm = rtu_u1;
        } else {
          tvrd_tq_mot2TgtTqReq_Nm = fminf(fmaxf(fminf(rtu_u1 -
            tvrd_tq_mot2TgtTqReq_Nm, rtb_MinMax_d) + tvrd_tq_mot2TgtTqReq_Nm,
            rtu_u2), rtu_u1);
        }
      }
      break;
    }
  }

  /* End of Chart: '<S442>/Chart' */
}

/* System initialize for function-call system: '<S1>/TVR_TorqueVectorControl' */
static void sw_TVR_TorqueVectorControl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_RampOn_a;

  /* SystemInitialize for Atomic SubSystem: '<S9>/SwitchRampMot2TrqDem' */
  swc_T_SwitchRampMot2TrqDem_Init(&rtb_RampOn_a);

  /* End of SystemInitialize for SubSystem: '<S9>/SwitchRampMot2TrqDem' */
}

/* Output and update for function-call system: '<S1>/TVR_TorqueVectorControl' */
static void swc_TCO_TVR_TorqueVectorControl(void)
{
  /* local block i/o variables */
  float32 rtb_Switch2_p;
  float32 rtb_Product_aq;
  boolean rtb_LogicalOperator3_ol;
  boolean rtb_RampOn_a;

  /* Logic: '<S9>/Logical Operator3' incorporates:
   *  Constant: '<S9>/Constant41'
   */
  rtb_LogicalOperator3_ol = !false;

  /* Switch: '<S438>/Switch2' incorporates:
   *  RelationalOperator: '<S441>/FixPt Relational Operator'
   *  UnitDelay: '<S441>/Delay Input1'
   *
   * Block description for '<S441>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((sint32)rtb_LogicalOperator3_ol > (sint32)
      swc_TCOO_ARID_DEF.DelayInput1_DSTATE_h) {
    /* Switch: '<S438>/Switch2' */
    rtb_Switch2_p = swc_TCOO_ARID_DEF.DataTypeConversion106;
  } else {
    /* Switch: '<S438>/Switch2' incorporates:
     *  Constant: '<S438>/Constant18'
     */
    rtb_Switch2_p = ((float32)TRQ_ZERO);
  }

  /* End of Switch: '<S438>/Switch2' */

  /* Product: '<S9>/Product' incorporates:
   *  Constant: '<S9>/Constant40'
   */
  rtb_Product_aq = 1.0F * eadd_tq_mot2TgtTqReq_Nm;

  /* Outputs for Atomic SubSystem: '<S9>/SwitchRampMot2TrqDem' */
  /* Constant: '<S9>/Constant10' incorporates:
   *  Constant: '<S9>/Constant11'
   */
  swc_TCOO_SwitchRampMot2TrqDem(rtb_Product_aq, rtb_LogicalOperator3_ol,
    rtb_Switch2_p, tvrc_dtq_Mot2TqInc_Nmps, tvrc_dtq_Mot2TqDec_Nmps,
    &rtb_RampOn_a, &swc_TCOO_ARID_DEF.ARID_DEF_SwitchRampMot2TrqDem);

  /* End of Outputs for SubSystem: '<S9>/SwitchRampMot2TrqDem' */

  /* Update for UnitDelay: '<S441>/Delay Input1'
   *
   * Block description for '<S441>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_TCOO_ARID_DEF.DelayInput1_DSTATE_h = rtb_LogicalOperator3_ol;
}

/* Model step function */
void swc_TCOO_Step(void)
{
  /* local block i/o variables */
  uint8 rtb_DataTypeConversion9;
  boolean rtb_DataTypeConversion10;
  boolean rtb_DataTypeConversion186;
  uint8 rtb_BitwiseAnd2;
  boolean rtb_con_3;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in1'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion1 =
    Rte_IRead_swc_TCOO_Step_vcsb_VOMM_drid_b_vehSportModActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion10' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in8'
   */
  rtb_DataTypeConversion10 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_flgFctCfgChgTyp();

  /* DataTypeConversion: '<Root>/Data Type Conversion106' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in49'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion106 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_eadd_tq_mot2ActTq_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion11' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in9'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion11 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_tq_ehbIsaPtTrqDecReq_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion12' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in10'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion12 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_st_ehbIsaSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion63' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in36'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion63 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_brpd_x_brkPedlPos_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion23' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in19'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion23 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_ESPActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion65' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in40'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion65 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_tq_axle2MaxTqReq_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion78' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in41'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion78 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_tq_axle2MinTqReq_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion84' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in42'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion84 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_tq_axle2RgnBrkTqReq_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion26' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCAP_in6'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion26 =
    Rte_IRead_swc_TCOO_Step_vcsb_SCAP_tqld_tq_axle2MaxTq_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion47' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCAP_in7'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion47 =
    Rte_IRead_swc_TCOO_Step_vcsb_SCAP_tqld_tq_axle2MinTq_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion175' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in61'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion175 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_ehbAebActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion176' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in62'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion176 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_ehbTrqDecReqActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion177' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in63'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion177 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_tq_ehbTrqDecReq_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion185' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in64'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion185 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_ehbVlcAvailb();

  /* DataTypeConversion: '<Root>/Data Type Conversion180' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in65'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion180 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_ehbVlcActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion181' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in66'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion181 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_ehbVlcTrqReqActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion184' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in67'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion184 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_tq_ehbVlcTrqReq_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion182' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in68'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion182 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_ehbDtcActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion183' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in69'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion183 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_ehbTrqIncReqActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion188' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in70'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion188 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_tq_ehbTrqIncReq_Nm();

  /* S-Function (sfix_bitop): '<S6>/Bitwise And2' incorporates:
   *  CCaller: '<S6>/C Caller1'
   */
  rtb_BitwiseAnd2 = 0U;

  /* CCaller: '<S6>/C Caller1' incorporates:
   *  Constant: '<S6>/Constant158'
   */
  Dem_GetEventStatus(((uint16)32894U), &rtb_BitwiseAnd2);

  /* CCaller: '<S6>/C Caller2' incorporates:
   *  S-Function (sfix_bitop): '<S6>/Bitwise And1'
   */
  rtb_BitwiseAnd2 &= ((uint8)1U);

  /* DataTypeConversion: '<S6>/con_3' */
  rtb_con_3 = (rtb_BitwiseAnd2 != 0);

  /* Logic: '<S6>/Logical Operator1' incorporates:
   *  Constant: '<S6>/Constant3'
   */
  tcoo_eadd_b_ehbMsgErrDebd = (rtb_con_3 && tcoo_eadc_b_useGetEventSts);

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion196'
   *  Inport generated from: '<Root>/vcib_VCIP_in24'
   */
  swc_TCOO_ARID_DEF.Compare =
    (Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_flgNetConfgABS() == 0.0);

  /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in3'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion4 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_v_vehSpd_kph();

  /* DataTypeConversion: '<Root>/Data Type Conversion14' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in14'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion14 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_acpd_b_accPedlPosVld();

  /* DataTypeConversion: '<Root>/Data Type Conversion15' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in11'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion15 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_ehbIsaPtTrqDecReqActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion7' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in3'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion7 =
    Rte_IRead_swc_TCOO_Step_vcsb_VOMM_drid_e_driveDirSel();

  /* DataTypeConversion: '<Root>/Data Type Conversion22' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in15'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion22 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_pdcBrkFlg();

  /* DataTypeConversion: '<Root>/Data Type Conversion27' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCOO_in3'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion27 =
    Rte_IRead_swc_TCOO_Step_vcsb_SCOO_ctdd_b_eCreepReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion54' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCOO_in7'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion54 =
    Rte_IRead_swc_TCOO_Step_vcsb_SCOO_vsld_tq_whlMaxTqLimFast_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion37' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in25'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion37 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_ehbVlcCddActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion160' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion160 =
    Rte_IRead_swc_TCOO_Step_vcsb_VOMM_drid_b_veh4WDModActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion92' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCOO_in5'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion92 =
    Rte_IRead_swc_TCOO_Step_vcsb_SCOO_ccdd_tq_whlDem_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion91' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCOO_in6'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion91 =
    Rte_IRead_swc_TCOO_Step_vcsb_SCOO_ctdd_tq_whlDem_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion5' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in2'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion5 =
    Rte_IRead_swc_TCOO_Step_vcsb_VOMM_hmmd_b_EVModeActive();

  /* DataTypeConversion: '<Root>/Data Type Conversion94' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCAP_in11'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion94 =
    Rte_IRead_swc_TCOO_Step_vcsb_SCAP_tqld_tq_whlMax_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion95' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCAP_in13'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion95 =
    Rte_IRead_swc_TCOO_Step_vcsb_SCAP_tqld_tq_whlMin_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion171' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in55'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion171 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_adcd_b_adcCtrlTorqEn();

  /* DataTypeConversion: '<Root>/Data Type Conversion179' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in56'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion179 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_adcd_tq_adcTgtDrvTorq_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion167' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in48'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion167 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_brpd_e_brkPedalStatus();

  /* DataTypeConversion: '<Root>/Data Type Conversion190' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in75'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion190 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_adcd_st_pmsAdcCtrldSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion170' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in1'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion170 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_flgFctCfgDrvMod();

  /* DataTypeConversion: '<Root>/Data Type Conversion25' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in20'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion25 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_eadd_fact_mot2GearRat();

  /* DataTypeConversion: '<Root>/Data Type Conversion13' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in12'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion13 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_trad_fact_trsm2GearRat();

  /* DataTypeConversion: '<Root>/Data Type Conversion45' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCAP_in4'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion45 =
    Rte_IRead_swc_TCOO_Step_vcsb_SCAP_eadd_tq_mot2MaxSTTq_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion46' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCAP_in5'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion46 =
    Rte_IRead_swc_TCOO_Step_vcsb_SCAP_eadd_tq_mot2MinSTTq_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion186' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in73'
   */
  rtb_DataTypeConversion186 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_ehbAbsOvrdActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in6'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion6 =
    Rte_IRead_swc_TCOO_Step_vcsb_VOMM_drid_b_vehEcoModActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion197' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in79'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion197 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_st_flgFctCfgMotTyp();

  /* DataTypeConversion: '<Root>/Data Type Conversion17' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCOO_in1'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion17 =
    Rte_IRead_swc_TCOO_Step_vcsb_SCOO_ctdd_b_crpSlopeTrqOffsetEnHld();

  /* DataTypeConversion: '<Root>/Data Type Conversion21' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCOO_in2'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion21 =
    Rte_IRead_swc_TCOO_Step_vcsb_SCOO_ctdd_a_yrsLongAccAvgVld_mps2();

  /* DataTypeConversion: '<Root>/Data Type Conversion30' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in17'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion30 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_st_flgFctCfgVehCfg();

  /* DataTypeConversion: '<Root>/Data Type Conversion172' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in54'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion172 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_a_yrsLongitAcce_mps2();

  /* DataTypeConversion: '<Root>/Data Type Conversion31' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in18'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion31 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_vehSpdVld();

  /* CCaller: '<S6>/C Caller2' */
  rtb_BitwiseAnd2 = 0U;

  /* CCaller: '<S6>/C Caller2' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  Dem_GetEventStatus(((uint16)32888U), &rtb_BitwiseAnd2);

  /* S-Function (sfix_bitop): '<S6>/Bitwise And2' */
  rtb_BitwiseAnd2 &= ((uint8)1U);

  /* DataTypeConversion: '<S6>/con_1' */
  tcoo_eadd_b_acpCrsFltDebd = (rtb_BitwiseAnd2 != 0);

  /* DataTypeConversion: '<Root>/Data Type Conversion18' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in74'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion18 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_st_csmRgnLvlSet();

  /* DataTypeConversion: '<Root>/Data Type Conversion164' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in53'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion164 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_pmmd_b_ignOn();

  /* DataTypeConversion: '<Root>/Data Type Conversion165' incorporates:
   *  Inport generated from: '<Root>/vcsb_HVSM_in27'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion165 =
    Rte_IRead_swc_TCOO_Step_vcsb_HVSM_hvbd_e_PmmStatus();

  /* DataTypeConversion: '<Root>/Data Type Conversion187' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in71'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion187 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_st_ehbMbRgnTgtWhlSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion189' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in72'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion189 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_tq_ehbMbRgnTgtWhl_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion192' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in76'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion192 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_hvbd_pwr_StatChMax_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion193' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in77'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion193 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_hvbd_pwr_PeakChMax_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion195' incorporates:
   *  Inport generated from: '<Root>/vcsb_HVSM_in1'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion195 =
    Rte_IRead_swc_TCOO_Step_vcsb_HVSM_hvbd_b_vcuWkUpCmd();

  /* DataTypeConversion: '<Root>/Data Type Conversion8' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCOO_in14'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion8 =
    Rte_IRead_swc_TCOO_Step_vcsb_SCOO_vsld_v_vehMaxCfgSpd_kph();

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in2'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion2 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_flgFctCfgDrvModStor();

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in6'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion3 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_flgFctCfgDrvModConn();

  /* DataTypeConversion: '<Root>/Data Type Conversion33' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in21'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion33 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_acpd_x_accPedlPosLimd_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion34' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in22'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion34 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion35' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in23'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion35 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld();

  /* DataTypeConversion: '<Root>/Data Type Conversion36' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in4'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion36 =
    Rte_IRead_swc_TCOO_Step_vcsb_VOMM_drid_e_gearLvrPos();

  /* DataTypeConversion: '<Root>/Data Type Conversion39' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in27'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion39 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_csmEngRecSwtReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion29' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in16'
   */
  swc_TCOO_ARID_DEF.DataTypeConversion29 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_l_whlRad_m();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/DTD_DecelerationControl'
   */
  swc_TCO_DTD_DecelerationControl();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/APD_DriverDemand'
   */
  swc_TCOO_APD_DriverDemand();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/TDA_TorqueDemandsArbitration'
   */
  sw_TDA_TorqueDemandsArbitration();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/TQD_TorqueDistribution'
   */
  swc_TCOO_TQD_TorqueDistribution();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/EAD_TargetTorqueControlMot2'
   */
  swc_EAD_TargetTorqueControlMot2();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/TVR_TorqueVectorControl'
   */
  swc_TCO_TVR_TorqueVectorControl();

  /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator' */

  /* DataTypeConversion: '<Root>/Data Type Conversion9' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in7'
   */
  rtb_DataTypeConversion9 =
    Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd();

  /* Outport generated from: '<Root>/Out Bus Element53' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion163'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_dtdd_st_RegenLvlDisp(dtdd_st_RegenLvlDisp);

  /* Outport generated from: '<Root>/Out Bus Element3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion158'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_dtdd_tq_whlDragDem_Nm(dtdd_tq_whlDragDem_Nm);

  /* Outport generated from: '<Root>/Out Bus Element7' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion154'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_apdd_tq_whlDem_Nm(apdd_tq_whlDem_Nm);

  /* Outport generated from: '<Root>/Out Bus Element9' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion152'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tdad_tq_whlDemUnfilt_Nm
    (tdad_tq_whlDemUnfilt_Nm);

  /* Outport generated from: '<Root>/Out Bus Element10' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion151'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tdad_tq_whlDemUnlim_Nm
    (tdad_tq_whlDemUnlim_Nm);

  /* Outport generated from: '<Root>/Out Bus Element11' incorporates:
   *  Constant: '<S1>/Constant3'
   *  DataTypeConversion: '<Root>/Data Type Conversion150'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_msgd_tq_targetTqReq_Nm(((float32)TRQ_ZERO));

  /* Outport generated from: '<Root>/Out Bus Element12' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion149'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tdad_tq_whlDem_Nm(tdad_tq_whlDem_Nm);

  /* Outport generated from: '<Root>/Out Bus Element20' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion141'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm
    (eadd_tq_mot2TgtTqReq_Nm);

  /* Outport generated from: '<Root>/Out Bus Element27' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion134'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_eadd_tq_mot2TgtTq_Nm(eadd_tq_mot2TgtTq_Nm);

  /* Outport generated from: '<Root>/Out Bus Element37' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion124'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tvrd_tq_mot2TgtTqReq_Nm
    (tvrd_tq_mot2TgtTqReq_Nm);

  /* Outport generated from: '<Root>/Out Bus Element54' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion168'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_dtdd_tq_whlCoastDrgDem_Nm
    (swctcoo_dtdd_tq_whlCoastDrgDem_Nm);

  /* Outport generated from: '<Root>/Out Bus Element55' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion169'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tqdd_b_gpOvrd(swctcoo_tqdd_b_gpOvrd);

  /* Outport generated from: '<Root>/Out Bus Element56' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion191'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_dtdd_b_drvPfmncDrgDec
    (swctcoo_dtdd_b_drvPfmncDrgDec);

  /* Outport generated from: '<Root>/Out Bus Element57' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion173'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tqdd_b_ehbDisEnbCreep
    (tcoo_tqdd_b_ehbDisEnbCreep);

  /* Outport generated from: '<Root>/Out Bus Element1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion19'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tqdd_x_accPedlPosVirt_pct
    (tcoo_tqdd_x_accPedlPosVirt_pct);

  /* Outport generated from: '<Root>/Out Bus Element2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion20'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tqdd_b_accPedlPosVirtVld
    (tcoo_tqdd_b_accPedlPosVirtVld);

  /* Outport generated from: '<Root>/Out Bus Element4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion16'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_dtdd_tq_whlCstDrgDemNoEhb_Nm
    (tcoo_dtdd_tq_whlCstDrgDemNoEhb_Nm);

  /* Outport generated from: '<Root>/Out Bus Element5' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion24'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tqdd_st_ehbOvrdActv(tqdd_st_ehbTrqOvrdActv);

  /* Outport generated from: '<Root>/Out Bus Element6' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion28'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tqdd_st_ehbOvrdTyp(tqdd_st_ehbTrqOvrdType);

  /* Outport generated from: '<Root>/Out Bus Element8' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion32'
   */
  Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tqdd_st_whlAcceSupprsn
    (eadd_b_whlAcceSupprsn);
}

/* Model initialize function */
void swc_TCOO_Init(void)
{
  /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/DTD_DecelerationControl'
   */
  sw_DTD_DecelerationControl_Init();

  /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/APD_DriverDemand'
   */
  swc_TCOO_APD_DriverDemand_Init();

  /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/TDA_TorqueDemandsArbitration'
   */
  TDA_TorqueDemandsArbitrati_Init();

  /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/TQD_TorqueDistribution'
   */
  swc_TQD_TorqueDistribution_Init();

  /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/TVR_TorqueVectorControl'
   */
  sw_TVR_TorqueVectorControl_Init();

  /* End of SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

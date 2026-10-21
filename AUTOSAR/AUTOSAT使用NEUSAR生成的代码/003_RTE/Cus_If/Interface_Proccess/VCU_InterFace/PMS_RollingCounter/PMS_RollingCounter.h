/*
 * File: PMS_RollingCounter.h
 *
 * Code generated for Simulink model 'PMS_RollingCounter'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Aug 12 17:16:19 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PMS_RollingCounter_h_
#define RTW_HEADER_PMS_RollingCounter_h_
#ifndef PMS_RollingCounter_COMMON_INCLUDES_
#define PMS_RollingCounter_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_PMS_RollingCounter.h"
#endif                                 /* PMS_RollingCounter_COMMON_INCLUDES_ */

#include "PMS_RollingCounter_types.h"

/* Macros for accessing real-time model data structure */

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_PMS_RollingCounter_T {
  uint8 UnitDelay_DSTATE;              /* '<S2>/Unit Delay' */
  uint8 UnitDelay2_DSTATE;             /* '<S21>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE;             /* '<S21>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_i;           /* '<S8>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_f;           /* '<S8>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_o;           /* '<S19>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_b;           /* '<S19>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_a;           /* '<S23>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_b0;          /* '<S23>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_j;           /* '<S24>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_n;           /* '<S24>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_c;           /* '<S11>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_e;           /* '<S11>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_h;           /* '<S13>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_p;           /* '<S13>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_n;           /* '<S14>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_o;           /* '<S14>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_f;           /* '<S15>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_j;           /* '<S15>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_k;           /* '<S20>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_k;           /* '<S20>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_c2;          /* '<S28>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_i;           /* '<S28>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_fw;          /* '<S17>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_b1;          /* '<S17>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_nm;          /* '<S9>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_a;           /* '<S2>/Unit Delay1' */
  uint8 UnitDelay1_DSTATE_ou;          /* '<S9>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_ht;          /* '<S10>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_ji;          /* '<S10>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_hl;          /* '<S12>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_c;           /* '<S12>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_ix;          /* '<S16>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_l;           /* '<S16>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_ho;          /* '<S18>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_g;           /* '<S18>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_m;           /* '<S22>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_gp;          /* '<S22>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_o3;          /* '<S25>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_py;          /* '<S25>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_l;           /* '<S26>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_kf;          /* '<S26>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_e;           /* '<S27>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_e2;          /* '<S27>/Unit Delay1' */
} DW_PMS_RollingCounter_T;

/* Block states (default storage) */
extern DW_PMS_RollingCounter_T PMS_RollingCounter_DW;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PMS_RollingCounter'
 * '<S1>'   : 'PMS_RollingCounter/PMS_RollingCounter_Init'
 * '<S2>'   : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys'
 * '<S3>'   : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Compare To Constant'
 * '<S4>'   : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Compare To Constant1'
 * '<S5>'   : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Compare To Constant2'
 * '<S6>'   : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Compare To Constant3'
 * '<S7>'   : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Compare To Constant4'
 * '<S8>'   : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem1'
 * '<S9>'   : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem10'
 * '<S10>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem11'
 * '<S11>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem12'
 * '<S12>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem13'
 * '<S13>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem14'
 * '<S14>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem15'
 * '<S15>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem16'
 * '<S16>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem17'
 * '<S17>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem18'
 * '<S18>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem19'
 * '<S19>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem2'
 * '<S20>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem20'
 * '<S21>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem21'
 * '<S22>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem3'
 * '<S23>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem4'
 * '<S24>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem5'
 * '<S25>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem6'
 * '<S26>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem7'
 * '<S27>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem8'
 * '<S28>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem9'
 * '<S29>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem1/Compare To Constant2'
 * '<S30>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem10/Compare To Constant2'
 * '<S31>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem11/Compare To Constant2'
 * '<S32>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem12/Compare To Constant2'
 * '<S33>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem13/Compare To Constant2'
 * '<S34>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem14/Compare To Constant2'
 * '<S35>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem15/Compare To Constant2'
 * '<S36>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem16/Compare To Constant2'
 * '<S37>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem17/Compare To Constant2'
 * '<S38>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem18/Compare To Constant2'
 * '<S39>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem19/Compare To Constant2'
 * '<S40>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem2/Compare To Constant2'
 * '<S41>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem20/Compare To Constant2'
 * '<S42>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem21/Compare To Constant2'
 * '<S43>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem3/Compare To Constant2'
 * '<S44>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem4/Compare To Constant2'
 * '<S45>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem5/Compare To Constant2'
 * '<S46>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem6/Compare To Constant2'
 * '<S47>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem7/Compare To Constant2'
 * '<S48>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem8/Compare To Constant2'
 * '<S49>'  : 'PMS_RollingCounter/PMS_RollingCounter_Runnable_sys/Subsystem9/Compare To Constant2'
 */
#endif                                 /* RTW_HEADER_PMS_RollingCounter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

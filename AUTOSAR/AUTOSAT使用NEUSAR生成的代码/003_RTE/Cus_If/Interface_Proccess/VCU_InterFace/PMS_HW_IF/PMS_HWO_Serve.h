/*
 * File: PMS_HWO_Serve.h
 *
 * Code generated for Simulink model 'PMS_HWO_Serve'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Apr 15 16:22:37 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PMS_HWO_Serve_h_
#define RTW_HEADER_PMS_HWO_Serve_h_
#ifndef PMS_HWO_Serve_COMMON_INCLUDES_
#define PMS_HWO_Serve_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_PMS_HWO_Serve.h"
#endif                                 /* PMS_HWO_Serve_COMMON_INCLUDES_ */

#include "PMS_HWO_Serve_types.h"

/* Child system includes */
#include "PMSHWO_DO_KEY_HS_03_PMSHWO_SetDOHS_private.h"
#include "PMSHWO_DO_KEY_HS_05_PMSHWO_SetDOHS_private.h"
#include "PMSHWO_DO_RELAY_HS_11_PMSHWO_SetDOHS_private.h"
#include "PMSHWO_DO_RELAY_HS_6_PMSHWO_SetDOHS_private.h"
#include "PMSHWO_DO_RELAY_HS_8_PMSHWO_SetDOHS_private.h"
#include "PMSHWO_DO_RELAY_HS_9_PMSHWO_SetDOHS_private.h"
#include "PMSHWO_DO_RELAY_LS_10_PMSHWO_SetDOLS_private.h"
#include "PMSHWO_DO_RELAY_LS_12_PMSHWO_SetDOLS_private.h"
#include "PMSHWO_DO_RELAY_LS_5_PMSHWO_SetDOLS_private.h"
#include "PMSHWO_DO_RELAY_LS_7_PMSHWO_SetDOLS_private.h"
#include "PMSHWO_DO_RELAY_LS_9_PMSHWO_SetDOLS_private.h"
#include "PMSHWO_PO_HVIL_1_PMSHWO_SetPWM_private.h"
#include "PMSHWO_PO_HVIL_2_PMSHWO_SetPWM_private.h"
#include "PMSHWO_PO_PWM_1_PMSHWO_SetPWM_private.h"
#include "PMSHWO_PO_PWM_2_PMSHWO_SetPWM_private.h"
#include "PMSHWO_PO_PWM_4_PMSHWO_SetPWM_private.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */

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
 * '<Root>' : 'PMS_HWO_Serve'
 * '<S1>'   : 'PMS_HWO_Serve/PMSHWO_DO_KEY_HS_03'
 * '<S2>'   : 'PMS_HWO_Serve/PMSHWO_DO_KEY_HS_05'
 * '<S3>'   : 'PMS_HWO_Serve/PMSHWO_DO_RELAY_HS_11'
 * '<S4>'   : 'PMS_HWO_Serve/PMSHWO_DO_RELAY_HS_6'
 * '<S5>'   : 'PMS_HWO_Serve/PMSHWO_DO_RELAY_HS_8'
 * '<S6>'   : 'PMS_HWO_Serve/PMSHWO_DO_RELAY_HS_9'
 * '<S7>'   : 'PMS_HWO_Serve/PMSHWO_DO_RELAY_LS_10'
 * '<S8>'   : 'PMS_HWO_Serve/PMSHWO_DO_RELAY_LS_12'
 * '<S9>'   : 'PMS_HWO_Serve/PMSHWO_DO_RELAY_LS_5'
 * '<S10>'  : 'PMS_HWO_Serve/PMSHWO_DO_RELAY_LS_7'
 * '<S11>'  : 'PMS_HWO_Serve/PMSHWO_DO_RELAY_LS_9'
 * '<S12>'  : 'PMS_HWO_Serve/PMSHWO_PO_HVIL_1'
 * '<S13>'  : 'PMS_HWO_Serve/PMSHWO_PO_HVIL_2'
 * '<S14>'  : 'PMS_HWO_Serve/PMSHWO_PO_PWM_1'
 * '<S15>'  : 'PMS_HWO_Serve/PMSHWO_PO_PWM_2'
 * '<S16>'  : 'PMS_HWO_Serve/PMSHWO_PO_PWM_4'
 * '<S17>'  : 'PMS_HWO_Serve/PMS_HWO_Serve_Init'
 * '<S18>'  : 'PMS_HWO_Serve/PMSHWO_DO_KEY_HS_03/PMSHWO_DO_KEY_HS_03_PMSHWO_SetDOHS_sys'
 * '<S19>'  : 'PMS_HWO_Serve/PMSHWO_DO_KEY_HS_05/PMSHWO_DO_KEY_HS_05_PMSHWO_SetDOHS_sys'
 * '<S20>'  : 'PMS_HWO_Serve/PMSHWO_DO_RELAY_HS_11/PMSHWO_DO_RELAY_HS_11_PMSHWO_SetDOHS_sys'
 * '<S21>'  : 'PMS_HWO_Serve/PMSHWO_DO_RELAY_HS_6/PMSHWO_DO_RELAY_HS_6_PMSHWO_SetDOHS_sys'
 * '<S22>'  : 'PMS_HWO_Serve/PMSHWO_DO_RELAY_HS_8/PMSHWO_DO_RELAY_HS_8_PMSHWO_SetDOHS_sys'
 * '<S23>'  : 'PMS_HWO_Serve/PMSHWO_DO_RELAY_HS_9/PMSHWO_DO_RELAY_HS_9_PMSHWO_SetDOHS_sys'
 * '<S24>'  : 'PMS_HWO_Serve/PMSHWO_DO_RELAY_LS_10/PMSHWO_DO_RELAY_LS_10_PMSHWO_SetDOLS_sys'
 * '<S25>'  : 'PMS_HWO_Serve/PMSHWO_DO_RELAY_LS_12/PMSHWO_DO_RELAY_LS_12_PMSHWO_SetDOLS_sys'
 * '<S26>'  : 'PMS_HWO_Serve/PMSHWO_DO_RELAY_LS_5/PMSHWO_DO_RELAY_LS_5_PMSHWO_SetDOLS_sys'
 * '<S27>'  : 'PMS_HWO_Serve/PMSHWO_DO_RELAY_LS_7/PMSHWO_DO_RELAY_LS_7_PMSHWO_SetDOLS_sys'
 * '<S28>'  : 'PMS_HWO_Serve/PMSHWO_DO_RELAY_LS_9/PMSHWO_DO_RELAY_LS_9_PMSHWO_SetDOLS_sys'
 * '<S29>'  : 'PMS_HWO_Serve/PMSHWO_PO_HVIL_1/PMSHWO_PO_HVIL_1_PMSHWO_SetPWM_sys'
 * '<S30>'  : 'PMS_HWO_Serve/PMSHWO_PO_HVIL_2/PMSHWO_PO_HVIL_2_PMSHWO_SetPWM_sys'
 * '<S31>'  : 'PMS_HWO_Serve/PMSHWO_PO_PWM_1/PMSHWO_PO_PWM_1_PMSHWO_SetPWM_sys'
 * '<S32>'  : 'PMS_HWO_Serve/PMSHWO_PO_PWM_2/PMSHWO_PO_PWM_2_PMSHWO_SetPWM_sys'
 * '<S33>'  : 'PMS_HWO_Serve/PMSHWO_PO_PWM_4/PMSHWO_PO_PWM_4_PMSHWO_SetPWM_sys'
 */
#endif                                 /* RTW_HEADER_PMS_HWO_Serve_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

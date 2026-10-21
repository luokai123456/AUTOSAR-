/*
 * File: PMS_HWI_Serve.h
 *
 * Code generated for Simulink model 'PMS_HWI_Serve'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Apr 15 16:20:33 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PMS_HWI_Serve_h_
#define RTW_HEADER_PMS_HWI_Serve_h_
#ifndef PMS_HWI_Serve_COMMON_INCLUDES_
#define PMS_HWI_Serve_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_PMS_HWI_Serve.h"
#endif                                 /* PMS_HWI_Serve_COMMON_INCLUDES_ */

#include "PMS_HWI_Serve_types.h"

/* Child system includes */
#include "PMSHWI_AI_BATTERY_TEMPH_5_PMSHWI_GetAI_private.h"
#include "PMSHWI_AI_BATTERY_TEMPH_6_PMSHWI_GetAI_private.h"
#include "PMSHWI_AI_EXT_IGN_ON_AI_PMSHWI_GetAI_private.h"
#include "PMSHWI_AI_MID_COOLING_TEMPH_8_PMSHWI_GetAI_private.h"
#include "PMSHWI_AI_SENSOR_1_PMSHWI_GetAI_private.h"
#include "PMSHWI_AI_SENSOR_2_PMSHWI_GetAI_private.h"
#include "PMSHWI_AI_SENSOR_6_PMSHWI_GetAI_private.h"
#include "PMSHWI_AI_SWITCH_1_PMSHWI_GetAI_private.h"
#include "PMSHWI_AO_LDO_5V_02_PMSHWI_GetAI_private.h"
#include "PMSHWI_AO_TRACKING_5V_01_PMSHWI_GetAI_private.h"
#include "PMSHWI_AO_TRACKING_5V_02_PMSHWI_GetAI_private.h"
#include "PMSHWI_CHARGE_ON_AI_PMSHWI_GetAI_private.h"
#include "PMSHWI_DI_HS_04_PMSHWI_GetDI_private.h"
#include "PMSHWI_DI_HS_05_PMSHWI_GetDI_private.h"
#include "PMSHWI_DI_HS_06_PMSHWI_GetDI_private.h"
#include "PMSHWI_DI_HS_07_PMSHWI_GetDI_private.h"
#include "PMSHWI_DI_HS_08_PMSHWI_GetDI_private.h"
#include "PMSHWI_DI_HS_10_PMSHWI_GetDI_private.h"
#include "PMSHWI_IGN_ON_DI_PMSHWI_GetDI_private.h"
#include "PMSHWI_KL30_PMSHWI_GetAI_private.h"
#include "PMSHWI_PI_HVIL_1_PMSHWI_GetPWM_private.h"
#include "PMSHWI_PI_HVIL_2_PMSHWI_GetPWM_private.h"
#include "PMSHWI_PI_PWM_1_PMSHWI_GetPWM_private.h"
#include "PMSHWI_PI_PWM_2_PMSHWI_GetPWM_private.h"

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
 * '<Root>' : 'PMS_HWI_Serve'
 * '<S1>'   : 'PMS_HWI_Serve/PMSHWI_AI_BATTERY_TEMPH_5'
 * '<S2>'   : 'PMS_HWI_Serve/PMSHWI_AI_BATTERY_TEMPH_6'
 * '<S3>'   : 'PMS_HWI_Serve/PMSHWI_AI_MID_COOLING_TEMPH_8'
 * '<S4>'   : 'PMS_HWI_Serve/PMSHWI_AI_SENSOR_1'
 * '<S5>'   : 'PMS_HWI_Serve/PMSHWI_AI_SENSOR_2'
 * '<S6>'   : 'PMS_HWI_Serve/PMSHWI_AI_SENSOR_6'
 * '<S7>'   : 'PMS_HWI_Serve/PMSHWI_AI_SWITCH_1'
 * '<S8>'   : 'PMS_HWI_Serve/PMSHWI_AO_LDO_5V_02'
 * '<S9>'   : 'PMS_HWI_Serve/PMSHWI_AO_TRACKING_5V_01'
 * '<S10>'  : 'PMS_HWI_Serve/PMSHWI_AO_TRACKING_5V_02'
 * '<S11>'  : 'PMS_HWI_Serve/PMSHWI_CHARGE_ON_AI'
 * '<S12>'  : 'PMS_HWI_Serve/PMSHWI_DI_HS_04'
 * '<S13>'  : 'PMS_HWI_Serve/PMSHWI_DI_HS_05'
 * '<S14>'  : 'PMS_HWI_Serve/PMSHWI_DI_HS_06'
 * '<S15>'  : 'PMS_HWI_Serve/PMSHWI_DI_HS_07'
 * '<S16>'  : 'PMS_HWI_Serve/PMSHWI_DI_HS_08'
 * '<S17>'  : 'PMS_HWI_Serve/PMSHWI_DI_HS_10'
 * '<S18>'  : 'PMS_HWI_Serve/PMSHWI_IGN_ON_DI'
 * '<S19>'  : 'PMS_HWI_Serve/PMSHWI_KL30'
 * '<S20>'  : 'PMS_HWI_Serve/PMSHWI_PI_HVIL_1'
 * '<S21>'  : 'PMS_HWI_Serve/PMSHWI_PI_HVIL_2'
 * '<S22>'  : 'PMS_HWI_Serve/PMSHWI_PI_PWM_1'
 * '<S23>'  : 'PMS_HWI_Serve/PMSHWI_PI_PWM_2'
 * '<S24>'  : 'PMS_HWI_Serve/PMS_HWI_Serve_Init'
 * '<S25>'  : 'PMS_HWI_Serve/PMSHWI_AI_BATTERY_TEMPH_5/PMSHWI_AI_BATTERY_TEMPH_5_PMSHWI_GetAI_sys'
 * '<S26>'  : 'PMS_HWI_Serve/PMSHWI_AI_BATTERY_TEMPH_6/PMSHWI_AI_BATTERY_TEMPH_6_PMSHWI_GetAI_sys'
 * '<S27>'  : 'PMS_HWI_Serve/PMSHWI_AI_MID_COOLING_TEMPH_8/PMSHWI_AI_MID_COOLING_TEMPH_8_PMSHWI_GetAI_sys'
 * '<S28>'  : 'PMS_HWI_Serve/PMSHWI_AI_SENSOR_1/PMSHWI_AI_SENSOR_1_PMSHWI_GetAI_sys'
 * '<S29>'  : 'PMS_HWI_Serve/PMSHWI_AI_SENSOR_2/PMSHWI_AI_SENSOR_2_PMSHWI_GetAI_sys'
 * '<S30>'  : 'PMS_HWI_Serve/PMSHWI_AI_SENSOR_6/PMSHWI_AI_SENSOR_6_PMSHWI_GetAI_sys'
 * '<S31>'  : 'PMS_HWI_Serve/PMSHWI_AI_SWITCH_1/PMSHWI_AI_SWITCH_1_PMSHWI_GetAI_sys'
 * '<S32>'  : 'PMS_HWI_Serve/PMSHWI_AO_LDO_5V_02/PMSHWI_AO_LDO_5V_02_PMSHWI_GetAI_sys'
 * '<S33>'  : 'PMS_HWI_Serve/PMSHWI_AO_TRACKING_5V_01/PMSHWI_AO_TRACKING_5V_01_PMSHWI_GetAI_sys'
 * '<S34>'  : 'PMS_HWI_Serve/PMSHWI_AO_TRACKING_5V_02/PMSHWI_AO_TRACKING_5V_02_PMSHWI_GetAI_sys'
 * '<S35>'  : 'PMS_HWI_Serve/PMSHWI_CHARGE_ON_AI/PMSHWI_CHARGE_ON_AI_PMSHWI_GetAI_sys'
 * '<S36>'  : 'PMS_HWI_Serve/PMSHWI_DI_HS_04/PMSHWI_DI_HS_04_PMSHWI_GetDI_sys'
 * '<S37>'  : 'PMS_HWI_Serve/PMSHWI_DI_HS_05/PMSHWI_DI_HS_05_PMSHWI_GetDI_sys'
 * '<S38>'  : 'PMS_HWI_Serve/PMSHWI_DI_HS_06/PMSHWI_DI_HS_06_PMSHWI_GetDI_sys'
 * '<S39>'  : 'PMS_HWI_Serve/PMSHWI_DI_HS_07/PMSHWI_DI_HS_07_PMSHWI_GetDI_sys'
 * '<S40>'  : 'PMS_HWI_Serve/PMSHWI_DI_HS_08/PMSHWI_DI_HS_08_PMSHWI_GetDI_sys'
 * '<S41>'  : 'PMS_HWI_Serve/PMSHWI_DI_HS_10/PMSHWI_DI_HS_10_PMSHWI_GetDI_sys'
 * '<S42>'  : 'PMS_HWI_Serve/PMSHWI_IGN_ON_DI/PMSHWI_IGN_ON_DI_PMSHWI_GetDI_sys'
 * '<S43>'  : 'PMS_HWI_Serve/PMSHWI_KL30/PMSHWI_KL30_PMSHWI_GetAI_sys'
 * '<S44>'  : 'PMS_HWI_Serve/PMSHWI_PI_HVIL_1/PMSHWI_PI_HVIL_1_PMSHWI_GetPWM_sys'
 * '<S45>'  : 'PMS_HWI_Serve/PMSHWI_PI_HVIL_2/PMSHWI_PI_HVIL_2_PMSHWI_GetPWM_sys'
 * '<S46>'  : 'PMS_HWI_Serve/PMSHWI_PI_PWM_1/PMSHWI_PI_PWM_1_PMSHWI_GetPWM_sys'
 * '<S47>'  : 'PMS_HWI_Serve/PMSHWI_PI_PWM_2/PMSHWI_PI_PWM_2_PMSHWI_GetPWM_sys'
 */
#endif                                 /* RTW_HEADER_PMS_HWI_Serve_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

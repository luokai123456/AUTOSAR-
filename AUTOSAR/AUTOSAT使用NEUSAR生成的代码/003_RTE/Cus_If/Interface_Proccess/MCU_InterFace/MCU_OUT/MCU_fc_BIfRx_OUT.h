/*
 * File: MCU_fc_BIfRx_OUT.h
 *
 * Code generated for Simulink model 'MCU_fc_BIfRx_OUT'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Apr 24 17:26:02 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MCU_fc_BIfRx_OUT_h_
#define RTW_HEADER_MCU_fc_BIfRx_OUT_h_
#ifndef MCU_fc_BIfRx_OUT_COMMON_INCLUDES_
#define MCU_fc_BIfRx_OUT_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_MCU_fc_BIfRx_OUT.h"
#endif                                 /* MCU_fc_BIfRx_OUT_COMMON_INCLUDES_ */

#include "MCU_fc_BIfRx_OUT_types.h"


  extern float32 SGPP_FOC_f32_Uduty_Null;
  extern float32 SGPP_FOC_f32_Vduty_Null;
  extern float32 SGPP_FOC_f32_Wduty_Null;
  extern float32 SGPP_kFOC_f32_PWMFreq_Hz;
  extern uint8 SGPP_BSW_u8_ASC_Enable;
  extern uint8 SGPP_BSW_u8_PWM_Enable;
  extern uint8 SGPP_BSW_u8_ClearFlt_Roty_En;
  extern boolean SGPP_BSW_u8_ClearFlt_Volt_Curr_En;
  extern boolean SGPP_BSW_u8_CutOffDelayEn_flg;
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
 * '<Root>' : 'MCU_fc_BIfRx_OUT'
 * '<S1>'   : 'MCU_fc_BIfRx_OUT/MCU_fc_BIfRx_OUT_100us_sys'
 * '<S2>'   : 'MCU_fc_BIfRx_OUT/MCU_fc_BIfRx_OUT_Init'
 */
#endif                                 /* RTW_HEADER_MCU_fc_BIfRx_OUT_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: MCU_fc_BIfRx_IN.h
 *
 * Code generated for Simulink model 'MCU_fc_BIfRx_IN'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Apr 24 11:00:19 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MCU_fc_BIfRx_IN_h_
#define RTW_HEADER_MCU_fc_BIfRx_IN_h_
#ifndef MCU_fc_BIfRx_IN_COMMON_INCLUDES_
#define MCU_fc_BIfRx_IN_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_MCU_fc_BIfRx_IN.h"
#endif                                 /* MCU_fc_BIfRx_IN_COMMON_INCLUDES_ */

#include "MCU_fc_BIfRx_IN_types.h"

extern uint8_T SGPP_BSW_f32_ChrgWakeup_State;/* '<S4>/Constant2' */
extern uint8_T SGPP_BSW_f32_Drive_Error;/* '<S3>/SGSA_DriveErr'
                                         * Ignition power supply status
                                         */
extern uint8_T SGPP_BSW_f32_DriveHBridg_Error;/* '<S3>/SGSA_HDriFault'
                                               * Ignition power supply status
                                               */
extern uint8_T SGPP_BSW_f32_DriveLBridg_Error;/* '<S3>/SGSA_LDriFault'
                                               * Ignition power supply status
                                               */
extern real32_T SGPP_BSW_f32_eAngle_rad;/* '<S1>/SpeedEstimationAndCmdFilter'
                                         * Electrical angle for coordinate transformation
                                         */
extern real32_T SGPP_BSW_f32_iSmpPhaU_A;/* '<S6>/Data Type Conversion' */
extern real32_T SGPP_BSW_f32_iSmpPhaW_A;/* '<S6>/Data Type Conversion2' */
extern real32_T SGPP_BSW_f32_iSmpPhaV_A;/* '<S4>/Constant5' */
extern uint8_T  SGPP_BSW_f32_KL15_State;/* '<Root>/SGPP_BSW_f32_KL15_State' */
extern real32_T SGPP_BSW_f32_nRotateSpd_rpm;/* '<S10>/Product1'
                                             * Mechanical rotor speed
                                             */
extern real32_T SGPP_BSW_f32_RDC_CosEvlp;   /* '<S1>/SGRD_CosRawBkUp' */
extern real32_T SGPP_BSW_f32_RDC_SinEvlp;   /* '<S1>/SGRD_SineRawBkUp' */
extern real32_T SGPP_BSW_f32_tIGBTTempU_C;/* '<S3>/Signal Conversion'
                                           * Phase A power switch temperature
                                           */
extern real32_T SGPP_BSW_f32_tIGBTTempV_C;/* '<S3>/Signal Conversion1'
                                           * Phase B power switch temperature
                                           */
extern real32_T SGPP_BSW_f32_tIGBTTempW_C;/* '<S3>/Signal Conversion2'
                                           * Phase C power switch temperature
                                           */
extern real32_T SGPP_BSW_f32_tMotTemp_C;/* '<S2>/SGSA_MotorTemp1'
                                         * Motor temperature sensor 1 reading
                                         */
extern real32_T SGPP_BSW_f32_u12V_V;
extern real32_T SGPP_BSW_f32_u5V_V;
extern real32_T SGPP_BSW_f32_uCurrSnsrRefSmp_V;
extern real32_T SGPP_BSW_f32_uCurrSnsrUSmp_V;/* '<S1>/SGSA_PhaseACurrentAD' */
extern real32_T SGPP_BSW_f32_uCurrSnsrWSmp_V;/* '<S1>/SGSA_PhaseCCurrentAD' */
extern real32_T SGPP_BSW_f32_uCurrSnsrVSmp_V;/* '<S4>/Constant1' */
extern real32_T SGPP_BSW_f32_uCurrSnsrWSmp_V;/* '<S1>/SGSA_PhaseCCurrentAD' */
extern real32_T SGPP_BSW_f32_uDCActSmp_V;
extern real32_T SGPP_BSW_f32_uDcHV_V;
extern real32_T SGPP_BSW_f32_uDcHVSmp_V;
extern real32_T SGPP_BSW_f32_uIGBTTempUSmp_V;/* '<S3>/SGSA_PhaseASwitchTempAD' */
extern real32_T SGPP_BSW_f32_uIGBTTempVSmp_V;/* '<S3>/SGSA_PhaseBSwitchTempAD' */
extern real32_T SGPP_BSW_f32_uIGBTTempWSmp_V;/* '<S3>/SGSA_PhaseCSwitchTempAD' */
extern real32_T SGPP_BSW_f32_uMotTempSmp_V;/* '<S2>/SGSA_MotorTemp1AD' */
extern uint8_T SGPP_BSW_u8_bERCNVFlt;  /* '<S4>/Constant21' */
extern uint8_T SGPP_BSW_u8_bERDCNVFlt; /* '<S4>/Constant16' */
extern uint8_T SGPP_BSW_u8_bERDEXCFlt; /* '<S4>/Constant17' */
extern uint8_T SGPP_BSW_u8_bERDP2Flt;  /* '<S4>/Constant18' */
extern uint8_T SGPP_BSW_u8_bERDSBCFlt; /* '<S4>/Constant19' */
extern uint8_T SGPP_BSW_u8_bERDSBSFlt; /* '<S4>/Constant20' */
extern uint8_T SGPP_BSW_u8_bERDSQFlt;  /* '<S4>/Constant22' */
extern uint8_T SGPP_BSW_u8_bEREXCFlt;  /* '<S4>/Constant28' */
extern uint8_T SGPP_BSW_u8_bERHDFlt;   /* '<S4>/Constant23' */
extern uint8_T SGPP_BSW_u8_bERP2Flt;   /* '<S4>/Constant24' */
extern uint8_T SGPP_BSW_u8_bERRFlt;    /* '<S4>/Constant25' */
extern uint8_T SGPP_BSW_u8_bERSBCFlt;  /* '<S4>/Constant26' */
extern uint8_T SGPP_BSW_u8_bERSBSFlt;  /* '<S4>/Constant27' */
extern uint8_T SGPP_BSW_u8_bERSQFlt;   /* '<S4>/Constant29' */
extern uint8_T SGPP_BSW_u8_bMcuStorgUnitFlt;/* '<S4>/Constant35' */
extern uint8_T SGPP_BSW_u8_bRotyTrfrDosFlt;/* '<S4>/Constant30' */
extern uint8_T SGPP_BSW_u8_bRotyTrfrLosFlt;/* '<S4>/Constant31' */
extern uint8_T SGPP_BSW_u8_bRotyTrfrLotFlt;/* '<S4>/Constant32' */
extern uint8_T SGPP_BSW_u8_DriFault_UH;/* '<S4>/Constant33' */
extern uint8_T SGPP_BSW_u8_DriFault_UL;/* '<S4>/Constant34' */
extern uint8_T SGPP_BSW_u8_DriFault_VH;/* '<S4>/Constant36' */
extern uint8_T SGPP_BSW_u8_DriFault_VL;/* '<S4>/Constant37' */
extern uint8_T SGPP_BSW_u8_DriFault_WH;/* '<S4>/Constant38' */
extern uint8_T SGPP_BSW_u8_DriFault_WL;/* '<S4>/Constant39' */
extern uint8_T SGPP_BSW_u8_HWOCFlt;    /* '<S3>/SGSA_HwOvercurSt' */
extern uint8_T SGPP_BSW_u8_HWOVFlt;    /* '<S3>/SGSA_HwOvervoltSt' */
extern uint8_T SGPP_BSW_u8_stPWM;      /* '<S1>/SGSA_PWMSts' */
extern uint8_T SGPP_BSW_u8_bRotyTrfrFlt;
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
 * '<Root>' : 'MCU_fc_BIfRx_IN'
 * '<S1>'   : 'MCU_fc_BIfRx_IN/MCU_fc_BIfRx_IN_Init'
 * '<S2>'   : 'MCU_fc_BIfRx_IN/MCU_fc_BIfRx_OUT100us_sys'
 */
#endif                                 /* RTW_HEADER_MCU_fc_BIfRx_IN_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

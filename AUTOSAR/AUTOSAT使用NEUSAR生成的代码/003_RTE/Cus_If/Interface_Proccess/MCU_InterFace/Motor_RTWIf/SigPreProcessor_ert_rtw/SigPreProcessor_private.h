/*
 * File: SigPreProcessor_private.h
 *
 * Code generated for Simulink model 'SigPreProcessor'.
 *
 * Model version                  : 1.363
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Sep 18 14:17:48 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SigPreProcessor_private_h_
#define RTW_HEADER_SigPreProcessor_private_h_
#include "rtwtypes.h"
#include "SigPreProcessor_types.h"

/* Exported data declaration */

/* Data with Imported storage */
extern EnumCtlMode CTSO_OperationMode; /* '<Root>/CTSO_OperationMode' */
extern uint8_T CTSO_SpeedCalcReset;    /* '<Root>/CTSO_SpeedCalcReset' */
extern uint8_T SGPP_BSW_u8_ASC_Enable; /* '<Root>/SGPP_BSW_u8_ASC_Enable' */
extern uint8_T SGPP_BSW_u8_ClearFlt_Roty_En;
                                     /* '<Root>/SGPP_BSW_u8_ClearFlt_Roty_En' */
extern boolean_T SGPP_BSW_u8_ClearFlt_Volt_Curr_En;
                                /* '<Root>/SGPP_BSW_u8_ClearFlt_Volt_Curr_En' */
extern boolean_T SGPP_BSW_u8_CutOffDelayEn_flg;
                                    /* '<Root>/SGPP_BSW_u8_CutOffDelayEn_flg' */
extern uint8_T SGPP_BSW_u8_PWM_Enable; /* '<Root>/SGPP_BSW_u8_PWM_Enable' */
extern real32_T SGPP_FOC_f32_Uduty_Null;/* '<Root>/SGPP_FOC_f32_Uduty_Null' */
extern real32_T SGPP_FOC_f32_Vduty_Null;/* '<Root>/SGPP_FOC_f32_Vduty_Null' */
extern real32_T SGPP_FOC_f32_Wduty_Null;/* '<Root>/SGPP_FOC_f32_Wduty_Null' */
extern real32_T SGPP_kFOC_f32_PWMFreq_Hz;/* '<Root>/SGPP_kFOC_f32_PWMFreq_Hz' */
extern real32_T SGRD_CosEnvelope;      /* '<Root>/SGRD_CosEnvelope' */
extern real32_T SGRD_EstTheta;         /* '<Root>/SGRD_EstTheta' */
extern real32_T SGRD_PwmFreq;          /* '<Root>/SGRD_PwmFreq' */
extern real32_T SGRD_PwmTs;            /* '<Root>/SGRD_PwmTs' */
extern real32_T SGRD_SinEnvelope;      /* '<Root>/SGRD_SinEnvelope' */
extern real32_T SGSA_BatteryVolt;      /* '<Root>/SGSA_BatteryVolt' */
extern real32_T SGSA_DcLinkVoltMeas;   /* '<Root>/SGSA_DcLinkVoltMeas' */
extern real32_T SGSA_DcLinkVoltMeasAD; /* '<Root>/SGSA_DcLinkVoltMeasAD' */
extern uint8_T SGSA_DriveErr;          /* '<Root>/SGSA_DriveErr' */
extern real32_T SGSA_ElecAngle;        /* '<Root>/SGSA_ElecAngle' */
extern uint8_T SGSA_HDriFault;         /* '<Root>/SGSA_HDriFault' */
extern uint8_T SGSA_HwOvercurSt;       /* '<Root>/SGSA_HwOvercurSt' */
extern uint8_T SGSA_HwOvervoltSt;      /* '<Root>/SGSA_HwOvervoltSt' */
extern real32_T SGSA_IgnitionVolt;     /* '<Root>/SGSA_IgnitionVolt' */
extern uint8_T SGSA_LDriFault;         /* '<Root>/SGSA_LDriFault' */
extern real32_T SGSA_MotorTemp1;       /* '<Root>/SGSA_MotorTemp1' */
extern real32_T SGSA_MotorTemp1AD;     /* '<Root>/SGSA_MotorTemp1AD' */
extern uint8_T SGSA_PWMSts;            /* '<Root>/SGSA_PWMSts' */
extern real32_T SGSA_PhaseACurrent;    /* '<Root>/SGSA_PhaseACurrent' */
extern real32_T SGSA_PhaseACurrentAD;  /* '<Root>/SGSA_PhaseACurrentAD' */
extern real32_T SGSA_PhaseASwitchTemp; /* '<Root>/SGSA_PhaseASwitchTemp' */
extern real32_T SGSA_PhaseASwitchTempAD;/* '<Root>/SGSA_PhaseASwitchTempAD' */
extern real32_T SGSA_PhaseBSwitchTemp; /* '<Root>/SGSA_PhaseBSwitchTemp' */
extern real32_T SGSA_PhaseBSwitchTempAD;/* '<Root>/SGSA_PhaseBSwitchTempAD' */
extern real32_T SGSA_PhaseCCurrent;    /* '<Root>/SGSA_PhaseCCurrent' */
extern real32_T SGSA_PhaseCCurrentAD;  /* '<Root>/SGSA_PhaseCCurrentAD' */
extern real32_T SGSA_PhaseCSwitchTemp; /* '<Root>/SGSA_PhaseCSwitchTemp' */
extern real32_T SGSA_PhaseCSwitchTempAD;/* '<Root>/SGSA_PhaseCSwitchTempAD' */
extern real32_T SGSA_PwrChipVolt;      /* '<Root>/SGSA_PwrChipVolt' */
extern uint8_T SGSA_ResolverError;     /* '<Root>/SGSA_ResolverError' */
extern real32_T SGSA_SpeedCommand;     /* '<Root>/SGSA_SpeedCommand' */

#endif                               /* RTW_HEADER_SigPreProcessor_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

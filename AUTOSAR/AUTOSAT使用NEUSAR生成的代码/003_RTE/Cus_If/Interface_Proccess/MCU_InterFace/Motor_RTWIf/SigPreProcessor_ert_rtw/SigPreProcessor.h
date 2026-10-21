/*
 * File: SigPreProcessor.h
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

#ifndef RTW_HEADER_SigPreProcessor_h_
#define RTW_HEADER_SigPreProcessor_h_
#ifndef SigPreProcessor_COMMON_INCLUDES_
#define SigPreProcessor_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SigPreProcessor_COMMON_INCLUDES_ */

#include "SigPreProcessor_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S61>/Delay' */
  real32_T UnitDelay_DSTATE;           /* '<S65>/Unit Delay' */
  real32_T UnitDelay_DSTATE_b;         /* '<S66>/Unit Delay' */
  uint8_T BareUnitDelay_DSTATE;        /* '<S30>/Bare Unit Delay' */
  uint8_T UnitDelay_DSTATE_i;          /* '<S26>/Unit Delay' */
  boolean_T Memory_PreviousInput;      /* '<S29>/Memory' */
} DW_SigPreProcessor_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Constant4;            /* '<S1>/Constant4' */
  const real32_T Constant5;            /* '<S1>/Constant5' */
  const real32_T Constant6;            /* '<S1>/Constant6' */
  const real32_T Constant7;            /* '<S1>/Constant7' */
  const real32_T Constant8;            /* '<S1>/Constant8' */
  const real32_T Constant9;            /* '<S1>/Constant9' */
  const real32_T Constant10;           /* '<S1>/Constant10' */
  const real32_T Constant11;           /* '<S1>/Constant11' */
  const real32_T Constant12;           /* '<S1>/Constant12' */
  const real32_T Constant13;           /* '<S1>/Constant13' */
  const real32_T Constant14;           /* '<S1>/Constant14' */
  const real32_T Constant15;           /* '<S1>/Constant15' */
  const real32_T Constant1;            /* '<S1>/Constant1' */
  const real32_T Constant3;            /* '<S1>/Constant3' */
  const real32_T Constant16;           /* '<S1>/Constant16' */
  const uint8_T Constant19;            /* '<S1>/Constant19' */
  const uint8_T Constant20;            /* '<S1>/Constant20' */
  const uint8_T Constant22;            /* '<S1>/Constant22' */
  const uint8_T Constant28;            /* '<S1>/Constant28' */
  const uint8_T Constant23;            /* '<S1>/Constant23' */
  const uint8_T Constant24;            /* '<S1>/Constant24' */
  const uint8_T Constant25;            /* '<S1>/Constant25' */
  const uint8_T Constant26;            /* '<S1>/Constant26' */
  const uint8_T Constant27;            /* '<S1>/Constant27' */
  const uint8_T Constant29;            /* '<S1>/Constant29' */
  const uint8_T Constant35;            /* '<S1>/Constant35' */
  const uint8_T Constant30;            /* '<S1>/Constant30' */
  const uint8_T Constant31;            /* '<S1>/Constant31' */
  const uint8_T Constant32;            /* '<S1>/Constant32' */
  const uint8_T Constant33;            /* '<S1>/Constant33' */
  const uint8_T Constant34;            /* '<S1>/Constant34' */
  const uint8_T Constant36;            /* '<S1>/Constant36' */
  const uint8_T Constant37;            /* '<S1>/Constant37' */
  const uint8_T Constant38;            /* '<S1>/Constant38' */
  const uint8_T Constant39;            /* '<S1>/Constant39' */
  const uint8_T Constant2;             /* '<S1>/Constant2' */
} ConstB_SigPreProcessor_T;

/* Real-time Model Data Structure */
struct tag_RTM_SigPreProcessor_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_SigPreProcessor_T SigPreProcessor_DW;
extern const ConstB_SigPreProcessor_T SigPreProcessor_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void SigPreProcessor_initialize(void);
extern void SigPreProcessor_terminate(void);

/* Exported entry point function */
extern void SGPP_InitSystemParam_Init(void);

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void SGPP_ReadCmd_100us(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported entry point function */
extern void SGPP_ReadTempVolt_1ms(void);

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void SGPP_Read_100us(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void SGPP_SpeedClc_96us(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported data declaration */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Par */
extern volatile uint8_T SGPP_AngleSourceSelect_C;/* Referenced by:
                                                  * '<S41>/Constant'
                                                  * '<S64>/Constant'
                                                  */

/* Angle source selection for control mode */
extern volatile uint8_T SGPP_IgnitionStatusSource_C;/* Referenced by: '<S23>/Constant' */

/* Ignition status source: 0=communication, 1=parameter */
extern volatile uint8_T SGPP_IgnitionStatus_C;/* Referenced by: '<S22>/Constant' */

/* Ignition status parameter value */
extern volatile uint8_T SGPP_IgnitionVoltThrHigh_C;/* Referenced by: '<S27>/Constant' */

/* Ignition voltage high threshold for debouncing */
extern volatile uint8_T SGPP_IgnitionVoltThreshold_C;/* Referenced by: '<S24>/Constant' */

/* Ignition signal debounce threshold */
extern volatile real32_T SGPP_MechSpeedFilterFreq_C;/* Referenced by: '<S62>/Constant' */

/* Mechanical speed filter cutoff frequency */
extern volatile uint8_T SGPP_PhaseMappingConfig_C;/* Referenced by:
                                                   * '<S11>/Constant'
                                                   * '<S45>/Constant'
                                                   */

/* Phase sequence remapping configuration (0-5) */
extern volatile uint8_T SGPP_PolePairs_C;/* Referenced by: '<S7>/Constant' */

/* Motor pole pair configuration value */
extern volatile uint8_T SGPP_ResolverFaultClrEnable_C;/* Referenced by: '<S10>/Constant' */

/* Angle source selection for control mode */
extern volatile uint8_T SGPP_ResolverPolePairs_C;/* Referenced by: '<S6>/Constant' */

/* Resolver pole pair configuration value */
extern volatile real32_T SGPP_SetSpeed_C;/* Referenced by: '<S63>/Constant' */
extern volatile uint8_T SGSA_ResolverFaultClr_C;/* Referenced by: '<S9>/Constant' */

#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Sig */
extern uint8_T SGPP_BSW_f32_ChrgWakeup_State;/* '<S1>/Constant2' */
extern uint8_T SGPP_BSW_f32_DriveHBridg_Error;/* '<S3>/SGSA_HDriFault' */

/* Ignition power supply status */
extern uint8_T SGPP_BSW_f32_DriveLBridg_Error;/* '<S3>/SGSA_LDriFault' */

/* Ignition power supply status */
extern uint8_T SGPP_BSW_f32_Drive_Error;/* '<S3>/SGSA_DriveErr' */

/* Ignition power supply status */
extern uint8_T SGPP_BSW_f32_KL15_State;/* '<S15>/Switch' */

/* Ignition power supply status */
extern real32_T SGPP_BSW_f32_RDC_CosEvlp;/* '<S4>/SGRD_CosEnvelope' */
extern real32_T SGPP_BSW_f32_RDC_CosN; /* '<S1>/Constant6' */
extern real32_T SGPP_BSW_f32_RDC_CosP; /* '<S1>/Constant7' */
extern real32_T SGPP_BSW_f32_RDC_ExctN;/* '<S1>/Constant8' */
extern real32_T SGPP_BSW_f32_RDC_ExctP;/* '<S1>/Constant9' */
extern real32_T SGPP_BSW_f32_RDC_GroupDelay;/* '<S1>/Constant10' */
extern real32_T SGPP_BSW_f32_RDC_SinEvlp;/* '<S4>/SGRD_SineEnvelope' */
extern real32_T SGPP_BSW_f32_RDC_SinN; /* '<S1>/Constant11' */
extern real32_T SGPP_BSW_f32_RDC_SinP; /* '<S1>/Constant12' */
extern real32_T SGPP_BSW_f32_RDC_TimeStamp;/* '<S1>/Constant13' */
extern real32_T SGPP_BSW_f32_eAngle_rad;/* '<S4>/AngleClc' */

/* Electrical angle for coordinate transformation */
extern real32_T SGPP_BSW_f32_iSmpPhaU_A;/* '<S35>/Data Type Conversion' */
extern real32_T SGPP_BSW_f32_iSmpPhaV_A;/* '<S1>/Constant5' */
extern real32_T SGPP_BSW_f32_iSmpPhaW_A;/* '<S35>/Data Type Conversion2' */
extern real32_T SGPP_BSW_f32_nRotateSpd_rpm;/* '<S5>/SpeedEstimationAndCmdFilter' */

/* Mechanical rotor speed */
extern real32_T SGPP_BSW_f32_tIGBTTempU_C;/* '<S3>/Signal Conversion' */

/* Phase A power switch temperature */
extern real32_T SGPP_BSW_f32_tIGBTTempV_C;/* '<S3>/Signal Conversion1' */

/* Phase B power switch temperature */
extern real32_T SGPP_BSW_f32_tIGBTTempW_C;/* '<S3>/Signal Conversion2' */

/* Phase C power switch temperature */
extern real32_T SGPP_BSW_f32_tMotTemp_C;/* '<S3>/SGSA_MotorTemp1' */

/* Motor temperature sensor 1 reading */
extern real32_T SGPP_BSW_f32_u12V_V;   /* '<S3>/SGSA_BatteryVolt' */
extern real32_T SGPP_BSW_f32_u5V_V;    /* '<S3>/SGSA_PwrChipVolt' */
extern real32_T SGPP_BSW_f32_uCurrSnsrRefSmp_V;/* '<S1>/Constant14' */
extern real32_T SGPP_BSW_f32_uCurrSnsrUSmp_V;/* '<S4>/SGSA_PhaseACurrentAD' */
extern real32_T SGPP_BSW_f32_uCurrSnsrVSmp_V;/* '<S1>/Constant1' */
extern real32_T SGPP_BSW_f32_uCurrSnsrWSmp_V;/* '<S4>/SGSA_PhaseCCurrentAD' */
extern real32_T SGPP_BSW_f32_uDCActSmp_V;/* '<S1>/Constant4' */
extern real32_T SGPP_BSW_f32_uDcHVSmp_V;/* '<S4>/SGSA_DcLinkVoltMeasAD' */
extern real32_T SGPP_BSW_f32_uDcHV_V;  /* '<S4>/Udc' */

/* DC-link voltage measurement */
extern real32_T SGPP_BSW_f32_uIGBTTempUSmp_V;/* '<S3>/SGSA_PhaseASwitchTempAD' */
extern real32_T SGPP_BSW_f32_uIGBTTempVSmp_V;/* '<S3>/SGSA_PhaseBSwitchTempAD' */
extern real32_T SGPP_BSW_f32_uIGBTTempWSmp_V;/* '<S3>/SGSA_PhaseCSwitchTempAD' */
extern real32_T SGPP_BSW_f32_uMotTempSmp_V;/* '<S3>/SGSA_MotorTemp1AD' */
extern real32_T SGPP_BSW_f32_uSmpRpl_V;/* '<S1>/Constant15' */
extern uint8_T SGPP_BSW_u8_DriFault_UH;/* '<S1>/Constant33' */
extern uint8_T SGPP_BSW_u8_DriFault_UL;/* '<S1>/Constant34' */
extern uint8_T SGPP_BSW_u8_DriFault_VH;/* '<S1>/Constant36' */
extern uint8_T SGPP_BSW_u8_DriFault_VL;/* '<S1>/Constant37' */
extern uint8_T SGPP_BSW_u8_DriFault_WH;/* '<S1>/Constant38' */
extern uint8_T SGPP_BSW_u8_DriFault_WL;/* '<S1>/Constant39' */
extern uint8_T SGPP_BSW_u8_HWOCFlt;    /* '<S3>/SGSA_HwOvercurSt' */
extern uint8_T SGPP_BSW_u8_HWOVFlt;    /* '<S3>/SGSA_HwOvervoltSt' */
extern uint8_T SGPP_BSW_u8_bERCNVFlt;  /* '<S37>/Data Type Conversion1' */
extern uint8_T SGPP_BSW_u8_bERDCNVFlt; /* '<S37>/Data Type Conversion2' */
extern uint8_T SGPP_BSW_u8_bERDEXCFlt; /* '<S37>/Data Type Conversion3' */
extern uint8_T SGPP_BSW_u8_bERDP2Flt;  /* '<S37>/Data Type Conversion4' */
extern uint8_T SGPP_BSW_u8_bERDSBCFlt; /* '<S1>/Constant19' */
extern uint8_T SGPP_BSW_u8_bERDSBSFlt; /* '<S1>/Constant20' */
extern uint8_T SGPP_BSW_u8_bERDSQFlt;  /* '<S1>/Constant22' */
extern uint8_T SGPP_BSW_u8_bEREXCFlt;  /* '<S1>/Constant28' */
extern uint8_T SGPP_BSW_u8_bERHDFlt;   /* '<S1>/Constant23' */
extern uint8_T SGPP_BSW_u8_bERP2Flt;   /* '<S1>/Constant24' */
extern uint8_T SGPP_BSW_u8_bERRFlt;    /* '<S1>/Constant25' */
extern uint8_T SGPP_BSW_u8_bERSBCFlt;  /* '<S1>/Constant26' */
extern uint8_T SGPP_BSW_u8_bERSBSFlt;  /* '<S1>/Constant27' */
extern uint8_T SGPP_BSW_u8_bERSQFlt;   /* '<S1>/Constant29' */
extern uint8_T SGPP_BSW_u8_bMcuStorgUnitFlt;/* '<S1>/Constant35' */
extern uint8_T SGPP_BSW_u8_bRotyTrfrDosFlt;/* '<S1>/Constant30' */
extern uint8_T SGPP_BSW_u8_bRotyTrfrFlt;/* '<S37>/Data Type Conversion' */
extern uint8_T SGPP_BSW_u8_bRotyTrfrLosFlt;/* '<S1>/Constant31' */
extern uint8_T SGPP_BSW_u8_bRotyTrfrLotFlt;/* '<S1>/Constant32' */
extern uint8_T SGPP_BSW_u8_stPWM;      /* '<S4>/SGSA_PWMSts' */
extern boolean_T SGPP_ClrHWFault; /* '<S2>/SGPP_BSW_u8_ClearFlt_Volt_Curr_En' */
extern uint8_T SGPP_ClrResolverFault;  /* '<S2>/Switch2' */
extern real32_T SGPP_DcLinkVoltMeas;   /* '<S4>/SGSA_DcLinkVoltMeas' */

/* DC-link voltage measurement */
extern real32_T SGPP_DcLinkVoltReciprocal;/* '<S4>/Udc' */

/* Reciprocal of DC-link voltage */
extern real32_T SGPP_ElecAngle;        /* '<S4>/AngleClc' */

/* Electrical angle for coordinate transformation */
extern real32_T SGPP_ElecSpeed;        /* '<S5>/SpeedEstimationAndCmdFilter' */

/* Electrical rotor speed */
extern real32_T SGPP_ElecSpeedAfterFilter;

/* Filtered electrical speed output */
extern real32_T SGPP_ElecSpeedBeforeFilter;

/* Raw electrical speed before filtering */
extern uint8_T SGPP_IgnitionStatus;    /* '<S3>/KL15StatusPrc' */

/* Ignition power supply status */
extern real32_T SGPP_MechSpeed;        /* '<S58>/Product1' */

/* Speed setpoint from communication */
extern real32_T SGPP_MotorTemp1;       /* '<S3>/MotorTemperaturePrc' */

/* Motor temperature sensor 1 reading */
extern real32_T SGPP_PhaseACurrent;    /* '<S4>/CurrentMapAndFilter' */

/* Phase A measured current for control */
extern real32_T SGPP_PhaseADuty;       /* '<S2>/MapThreePhaseSignal' */

/* Phase A PWM duty cycle */
extern real32_T SGPP_PhaseASwitchTemp; /* '<S3>/Signal Conversion' */

/* Maximum power switch temperature */
extern real32_T SGPP_PhaseBCurrent;    /* '<S35>/Data Type Conversion1' */

/* Phase B calculated current for control */
extern real32_T SGPP_PhaseBDuty;       /* '<S2>/MapThreePhaseSignal' */

/* Phase B PWM duty cycle */
extern real32_T SGPP_PhaseBSwitchTemp; /* '<S3>/Signal Conversion1' */

/* Maximum power switch temperature */
extern real32_T SGPP_PhaseCCurrent;    /* '<S4>/CurrentMapAndFilter' */

/* Phase C measured current for control */
extern real32_T SGPP_PhaseCDuty;       /* '<S2>/MapThreePhaseSignal' */

/* Phase C PWM duty cycle */
extern real32_T SGPP_PhaseCSwitchTemp; /* '<S3>/Signal Conversion2' */

/* Maximum power switch temperature */
extern real32_T SGPP_PolePairRatio;    /* '<S1>/Divide1' */

/* Motor to resolver pole pair ratio */
extern uint8_T SGPP_PolePairs;         /* '<S1>/Parameter4' */

/* Motor pole pair count */
extern real32_T SGPP_PolePairsReciprocal;/* '<S1>/Divide' */

/* Reciprocal of motor pole pair number */
extern real32_T SGPP_PolePairsReciprocal_IRV;/* '<S1>/Divide' */

/* Pole pair reciprocal for internal routing */
extern uint8_T SGPP_PolePairs_IRV;     /* '<S1>/Parameter4' */

/* Motor pole pairs for internal routing */
extern uint8_T SGPP_ResolverPolePairs; /* '<S1>/Parameter1' */

/* Resolver pole pair count */
extern real32_T SGPP_SampleTime1;      /* '<S39>/Data Type Conversion' */

/* Primary control loop sampling time */
extern real32_T SGPP_SampleTime1Reciprocal;/* '<S39>/Data Type Conversion1' */

/* Reciprocal of primary sampling time */
extern real32_T SGPP_SampleTime2;      /* '<S1>/Constant3' */

/* Secondary control loop sampling time */
extern real32_T SGPP_SampleTime2_IRV;  /* '<S1>/Constant3' */

/* Secondary sampling time for internal routing */
extern real32_T SGPP_SampleTime4;      /* '<S1>/Constant16' */

/* Quaternary control loop sampling time */
extern real32_T SGPP_SampleTime4_IRV;  /* '<S1>/Constant16' */

/* Quaternary sampling time for internal routing */
extern uint8_T SGPP_SetDriverSts;      /* '<S2>/SGPP_BSW_u8_PWM_Enable' */
extern real32_T SGPP_SetFreq;          /* '<S2>/SGPP_kFOC_f32_PWMFreq_Hz' */
extern uint8_T SGPP_SetHighASCFlg;     /* '<S2>/SGPP_BSW_u8_ASC_Enable' */
extern boolean_T SGPP_SetPwrOffDlyFlg;/* '<S2>/SGPP_BSW_u8_CutOffDelayEn_flg' */
extern real32_T SGPP_SimElecAngle;     /* '<S5>/SpeedEstimationAndCmdFilter' */

/* Electrical angle for coordinate transformation */
extern real32_T SGPP_SpeedSp;          /* '<S5>/SpeedEstimationAndCmdFilter' */

/* Speed setpoint from communication */
extern real32_T SGPP_SwitchTempMax;    /* '<S3>/IGBTTemperaturePrc' */

/* Maximum power switch temperature */
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Real-time Model object */
extern RT_MODEL_SigPreProcessor_T *const SigPreProcessor_M;

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
 * '<Root>' : 'SigPreProcessor'
 * '<S1>'   : 'SigPreProcessor/SGPP_InitSystemParam_Init_sys'
 * '<S2>'   : 'SigPreProcessor/SGPP_ReadCmd_100us_sys'
 * '<S3>'   : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys'
 * '<S4>'   : 'SigPreProcessor/SGPP_Read_100us_sys'
 * '<S5>'   : 'SigPreProcessor/SGPP_SpeedClc_96us_sys'
 * '<S6>'   : 'SigPreProcessor/SGPP_InitSystemParam_Init_sys/Parameter1'
 * '<S7>'   : 'SigPreProcessor/SGPP_InitSystemParam_Init_sys/Parameter4'
 * '<S8>'   : 'SigPreProcessor/SGPP_ReadCmd_100us_sys/MapThreePhaseSignal'
 * '<S9>'   : 'SigPreProcessor/SGPP_ReadCmd_100us_sys/Parameter2'
 * '<S10>'  : 'SigPreProcessor/SGPP_ReadCmd_100us_sys/Parameter3'
 * '<S11>'  : 'SigPreProcessor/SGPP_ReadCmd_100us_sys/Parameter4'
 * '<S12>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/HWFaultPrc'
 * '<S13>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/HWFaultStatus'
 * '<S14>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/IGBTTemperaturePrc'
 * '<S15>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/KL15StatusPrc'
 * '<S16>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/KL30Prc'
 * '<S17>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/MotorTemperaturePrc'
 * '<S18>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/PowerChipVoltPrc'
 * '<S19>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/IGBTTemperaturePrc/Variant Subsystem1'
 * '<S20>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/IGBTTemperaturePrc/Variant Subsystem1/XCU_Code'
 * '<S21>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/KL15StatusPrc/Debounce'
 * '<S22>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/KL15StatusPrc/Parameter1'
 * '<S23>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/KL15StatusPrc/Parameter4'
 * '<S24>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/KL15StatusPrc/Parameter9'
 * '<S25>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/KL15StatusPrc/Debounce/Debounce'
 * '<S26>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/KL15StatusPrc/Debounce/InitRest'
 * '<S27>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/KL15StatusPrc/Debounce/Parameter6'
 * '<S28>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/KL15StatusPrc/Debounce/Debounce/Saturation Dynamic'
 * '<S29>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/KL15StatusPrc/Debounce/Debounce/Subsystem'
 * '<S30>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/KL15StatusPrc/Debounce/Debounce/UnitDelay'
 * '<S31>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/KL15StatusPrc/Debounce/InitRest/Saturation Dynamic'
 * '<S32>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/MotorTemperaturePrc/Variant Subsystem1'
 * '<S33>'  : 'SigPreProcessor/SGPP_ReadTempVolt_1ms_sys/MotorTemperaturePrc/Variant Subsystem1/XCU_Code'
 * '<S34>'  : 'SigPreProcessor/SGPP_Read_100us_sys/AngleClc'
 * '<S35>'  : 'SigPreProcessor/SGPP_Read_100us_sys/CurrentMapAndFilter'
 * '<S36>'  : 'SigPreProcessor/SGPP_Read_100us_sys/PwmStsSignals'
 * '<S37>'  : 'SigPreProcessor/SGPP_Read_100us_sys/ResolverFault'
 * '<S38>'  : 'SigPreProcessor/SGPP_Read_100us_sys/ResolverRaw'
 * '<S39>'  : 'SigPreProcessor/SGPP_Read_100us_sys/TsSignals'
 * '<S40>'  : 'SigPreProcessor/SGPP_Read_100us_sys/Udc'
 * '<S41>'  : 'SigPreProcessor/SGPP_Read_100us_sys/AngleClc/Parameter4'
 * '<S42>'  : 'SigPreProcessor/SGPP_Read_100us_sys/AngleClc/Subsystem'
 * '<S43>'  : 'SigPreProcessor/SGPP_Read_100us_sys/AngleClc/Subsystem1'
 * '<S44>'  : 'SigPreProcessor/SGPP_Read_100us_sys/CurrentMapAndFilter/MapThreePhaseSignal'
 * '<S45>'  : 'SigPreProcessor/SGPP_Read_100us_sys/CurrentMapAndFilter/Parameter4'
 * '<S46>'  : 'SigPreProcessor/SGPP_Read_100us_sys/ResolverFault/Bit Shift'
 * '<S47>'  : 'SigPreProcessor/SGPP_Read_100us_sys/ResolverFault/Bit Shift1'
 * '<S48>'  : 'SigPreProcessor/SGPP_Read_100us_sys/ResolverFault/Bit Shift2'
 * '<S49>'  : 'SigPreProcessor/SGPP_Read_100us_sys/ResolverFault/Bit Shift3'
 * '<S50>'  : 'SigPreProcessor/SGPP_Read_100us_sys/ResolverFault/Bit Shift/bit_shift'
 * '<S51>'  : 'SigPreProcessor/SGPP_Read_100us_sys/ResolverFault/Bit Shift1/bit_shift'
 * '<S52>'  : 'SigPreProcessor/SGPP_Read_100us_sys/ResolverFault/Bit Shift2/bit_shift'
 * '<S53>'  : 'SigPreProcessor/SGPP_Read_100us_sys/ResolverFault/Bit Shift3/bit_shift'
 * '<S54>'  : 'SigPreProcessor/SGPP_Read_100us_sys/Udc/Variant Subsystem1'
 * '<S55>'  : 'SigPreProcessor/SGPP_Read_100us_sys/Udc/Variant Subsystem1/XCU_Code'
 * '<S56>'  : 'SigPreProcessor/SGPP_SpeedClc_96us_sys/SpeedEstimationAndCmdFilter'
 * '<S57>'  : 'SigPreProcessor/SGPP_SpeedClc_96us_sys/SpeedEstimationAndCmdFilter/Variant Subsystem'
 * '<S58>'  : 'SigPreProcessor/SGPP_SpeedClc_96us_sys/SpeedEstimationAndCmdFilter/Variant Subsystem/XCU_Code'
 * '<S59>'  : 'SigPreProcessor/SGPP_SpeedClc_96us_sys/SpeedEstimationAndCmdFilter/Variant Subsystem/XCU_Code/Local Variable Storage'
 * '<S60>'  : 'SigPreProcessor/SGPP_SpeedClc_96us_sys/SpeedEstimationAndCmdFilter/Variant Subsystem/XCU_Code/Local Variable Storage1'
 * '<S61>'  : 'SigPreProcessor/SGPP_SpeedClc_96us_sys/SpeedEstimationAndCmdFilter/Variant Subsystem/XCU_Code/LowPassFilter'
 * '<S62>'  : 'SigPreProcessor/SGPP_SpeedClc_96us_sys/SpeedEstimationAndCmdFilter/Variant Subsystem/XCU_Code/Parameter1'
 * '<S63>'  : 'SigPreProcessor/SGPP_SpeedClc_96us_sys/SpeedEstimationAndCmdFilter/Variant Subsystem/XCU_Code/Parameter2'
 * '<S64>'  : 'SigPreProcessor/SGPP_SpeedClc_96us_sys/SpeedEstimationAndCmdFilter/Variant Subsystem/XCU_Code/Parameter4'
 * '<S65>'  : 'SigPreProcessor/SGPP_SpeedClc_96us_sys/SpeedEstimationAndCmdFilter/Variant Subsystem/XCU_Code/ResolverSignalEmulation'
 * '<S66>'  : 'SigPreProcessor/SGPP_SpeedClc_96us_sys/SpeedEstimationAndCmdFilter/Variant Subsystem/XCU_Code/ThetaSensor'
 * '<S67>'  : 'SigPreProcessor/SGPP_SpeedClc_96us_sys/SpeedEstimationAndCmdFilter/Variant Subsystem/XCU_Code/ResolverSignalEmulation/AngleWrapZeroToTwoPi'
 * '<S68>'  : 'SigPreProcessor/SGPP_SpeedClc_96us_sys/SpeedEstimationAndCmdFilter/Variant Subsystem/XCU_Code/ThetaSensor/SpeedCalc'
 */
#endif                                 /* RTW_HEADER_SigPreProcessor_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

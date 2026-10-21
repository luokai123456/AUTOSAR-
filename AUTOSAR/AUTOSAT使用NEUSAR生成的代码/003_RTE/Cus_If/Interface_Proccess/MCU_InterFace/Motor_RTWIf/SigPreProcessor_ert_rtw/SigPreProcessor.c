/*
 * File: SigPreProcessor.c
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

#include "SigPreProcessor.h"
#include "rtwtypes.h"
#include "SigPreProcessor_private.h"

/* Exported data definition */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Par */
volatile uint8_T SGPP_AngleSourceSelect_C = 3U;/* Referenced by:
                                                * '<S41>/Constant'
                                                * '<S64>/Constant'
                                                */

/* Angle source selection for control mode */
volatile uint8_T SGPP_IgnitionStatusSource_C = 0U;/* Referenced by: '<S23>/Constant' */

/* Ignition status source: 0=communication, 1=parameter */
volatile uint8_T SGPP_IgnitionStatus_C = 0U;/* Referenced by: '<S22>/Constant' */

/* Ignition status parameter value */
volatile uint8_T SGPP_IgnitionVoltThrHigh_C = 10U;/* Referenced by: '<S27>/Constant' */

/* Ignition voltage high threshold for debouncing */
volatile uint8_T SGPP_IgnitionVoltThreshold_C = 8U;/* Referenced by: '<S24>/Constant' */

/* Ignition signal debounce threshold */
volatile real32_T SGPP_MechSpeedFilterFreq_C = 100.0F;/* Referenced by: '<S62>/Constant' */

/* Mechanical speed filter cutoff frequency */
volatile uint8_T SGPP_PhaseMappingConfig_C = 0U;/* Referenced by:
                                                 * '<S11>/Constant'
                                                 * '<S45>/Constant'
                                                 */

/* Phase sequence remapping configuration (0-5) */
volatile uint8_T SGPP_PolePairs_C = 4U;/* Referenced by: '<S7>/Constant' */

/* Motor pole pair configuration value */
volatile uint8_T SGPP_ResolverFaultClrEnable_C = 0U;/* Referenced by: '<S10>/Constant' */

/* Angle source selection for control mode */
volatile uint8_T SGPP_ResolverPolePairs_C = 4U;/* Referenced by: '<S6>/Constant' */

/* Resolver pole pair configuration value */
volatile real32_T SGPP_SetSpeed_C = 3.0F;/* Referenced by: '<S63>/Constant' */
volatile uint8_T SGSA_ResolverFaultClr_C = 0U;/* Referenced by: '<S9>/Constant' */

#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Sig */
uint8_T SGPP_BSW_f32_ChrgWakeup_State; /* '<S1>/Constant2' */
uint8_T SGPP_BSW_f32_DriveHBridg_Error;/* '<S3>/SGSA_HDriFault' */

/* Ignition power supply status */
uint8_T SGPP_BSW_f32_DriveLBridg_Error;/* '<S3>/SGSA_LDriFault' */

/* Ignition power supply status */
uint8_T SGPP_BSW_f32_Drive_Error;      /* '<S3>/SGSA_DriveErr' */

/* Ignition power supply status */
uint8_T SGPP_BSW_f32_KL15_State;       /* '<S15>/Switch' */

/* Ignition power supply status */
real32_T SGPP_BSW_f32_RDC_CosEvlp;     /* '<S4>/SGRD_CosEnvelope' */
real32_T SGPP_BSW_f32_RDC_CosN;        /* '<S1>/Constant6' */
real32_T SGPP_BSW_f32_RDC_CosP;        /* '<S1>/Constant7' */
real32_T SGPP_BSW_f32_RDC_ExctN;       /* '<S1>/Constant8' */
real32_T SGPP_BSW_f32_RDC_ExctP;       /* '<S1>/Constant9' */
real32_T SGPP_BSW_f32_RDC_GroupDelay;  /* '<S1>/Constant10' */
real32_T SGPP_BSW_f32_RDC_SinEvlp;     /* '<S4>/SGRD_SineEnvelope' */
real32_T SGPP_BSW_f32_RDC_SinN;        /* '<S1>/Constant11' */
real32_T SGPP_BSW_f32_RDC_SinP;        /* '<S1>/Constant12' */
real32_T SGPP_BSW_f32_RDC_TimeStamp;   /* '<S1>/Constant13' */
real32_T SGPP_BSW_f32_eAngle_rad;      /* '<S4>/AngleClc' */

/* Electrical angle for coordinate transformation */
real32_T SGPP_BSW_f32_iSmpPhaU_A;      /* '<S35>/Data Type Conversion' */
real32_T SGPP_BSW_f32_iSmpPhaV_A;      /* '<S1>/Constant5' */
real32_T SGPP_BSW_f32_iSmpPhaW_A;      /* '<S35>/Data Type Conversion2' */
real32_T SGPP_BSW_f32_nRotateSpd_rpm;  /* '<S5>/SpeedEstimationAndCmdFilter' */

/* Mechanical rotor speed */
real32_T SGPP_BSW_f32_tIGBTTempU_C;    /* '<S3>/Signal Conversion' */

/* Phase A power switch temperature */
real32_T SGPP_BSW_f32_tIGBTTempV_C;    /* '<S3>/Signal Conversion1' */

/* Phase B power switch temperature */
real32_T SGPP_BSW_f32_tIGBTTempW_C;    /* '<S3>/Signal Conversion2' */

/* Phase C power switch temperature */
real32_T SGPP_BSW_f32_tMotTemp_C;      /* '<S3>/SGSA_MotorTemp1' */

/* Motor temperature sensor 1 reading */
real32_T SGPP_BSW_f32_u12V_V;          /* '<S3>/SGSA_BatteryVolt' */
real32_T SGPP_BSW_f32_u5V_V;           /* '<S3>/SGSA_PwrChipVolt' */
real32_T SGPP_BSW_f32_uCurrSnsrRefSmp_V;/* '<S1>/Constant14' */
real32_T SGPP_BSW_f32_uCurrSnsrUSmp_V; /* '<S4>/SGSA_PhaseACurrentAD' */
real32_T SGPP_BSW_f32_uCurrSnsrVSmp_V; /* '<S1>/Constant1' */
real32_T SGPP_BSW_f32_uCurrSnsrWSmp_V; /* '<S4>/SGSA_PhaseCCurrentAD' */
real32_T SGPP_BSW_f32_uDCActSmp_V;     /* '<S1>/Constant4' */
real32_T SGPP_BSW_f32_uDcHVSmp_V;      /* '<S4>/SGSA_DcLinkVoltMeasAD' */
real32_T SGPP_BSW_f32_uDcHV_V;         /* '<S4>/Udc' */

/* DC-link voltage measurement */
real32_T SGPP_BSW_f32_uIGBTTempUSmp_V; /* '<S3>/SGSA_PhaseASwitchTempAD' */
real32_T SGPP_BSW_f32_uIGBTTempVSmp_V; /* '<S3>/SGSA_PhaseBSwitchTempAD' */
real32_T SGPP_BSW_f32_uIGBTTempWSmp_V; /* '<S3>/SGSA_PhaseCSwitchTempAD' */
real32_T SGPP_BSW_f32_uMotTempSmp_V;   /* '<S3>/SGSA_MotorTemp1AD' */
real32_T SGPP_BSW_f32_uSmpRpl_V;       /* '<S1>/Constant15' */
uint8_T SGPP_BSW_u8_DriFault_UH;       /* '<S1>/Constant33' */
uint8_T SGPP_BSW_u8_DriFault_UL;       /* '<S1>/Constant34' */
uint8_T SGPP_BSW_u8_DriFault_VH;       /* '<S1>/Constant36' */
uint8_T SGPP_BSW_u8_DriFault_VL;       /* '<S1>/Constant37' */
uint8_T SGPP_BSW_u8_DriFault_WH;       /* '<S1>/Constant38' */
uint8_T SGPP_BSW_u8_DriFault_WL;       /* '<S1>/Constant39' */
uint8_T SGPP_BSW_u8_HWOCFlt;           /* '<S3>/SGSA_HwOvercurSt' */
uint8_T SGPP_BSW_u8_HWOVFlt;           /* '<S3>/SGSA_HwOvervoltSt' */
uint8_T SGPP_BSW_u8_bERCNVFlt;         /* '<S37>/Data Type Conversion1' */
uint8_T SGPP_BSW_u8_bERDCNVFlt;        /* '<S37>/Data Type Conversion2' */
uint8_T SGPP_BSW_u8_bERDEXCFlt;        /* '<S37>/Data Type Conversion3' */
uint8_T SGPP_BSW_u8_bERDP2Flt;         /* '<S37>/Data Type Conversion4' */
uint8_T SGPP_BSW_u8_bERDSBCFlt;        /* '<S1>/Constant19' */
uint8_T SGPP_BSW_u8_bERDSBSFlt;        /* '<S1>/Constant20' */
uint8_T SGPP_BSW_u8_bERDSQFlt;         /* '<S1>/Constant22' */
uint8_T SGPP_BSW_u8_bEREXCFlt;         /* '<S1>/Constant28' */
uint8_T SGPP_BSW_u8_bERHDFlt;          /* '<S1>/Constant23' */
uint8_T SGPP_BSW_u8_bERP2Flt;          /* '<S1>/Constant24' */
uint8_T SGPP_BSW_u8_bERRFlt;           /* '<S1>/Constant25' */
uint8_T SGPP_BSW_u8_bERSBCFlt;         /* '<S1>/Constant26' */
uint8_T SGPP_BSW_u8_bERSBSFlt;         /* '<S1>/Constant27' */
uint8_T SGPP_BSW_u8_bERSQFlt;          /* '<S1>/Constant29' */
uint8_T SGPP_BSW_u8_bMcuStorgUnitFlt;  /* '<S1>/Constant35' */
uint8_T SGPP_BSW_u8_bRotyTrfrDosFlt;   /* '<S1>/Constant30' */
uint8_T SGPP_BSW_u8_bRotyTrfrFlt;      /* '<S37>/Data Type Conversion' */
uint8_T SGPP_BSW_u8_bRotyTrfrLosFlt;   /* '<S1>/Constant31' */
uint8_T SGPP_BSW_u8_bRotyTrfrLotFlt;   /* '<S1>/Constant32' */
uint8_T SGPP_BSW_u8_stPWM;             /* '<S4>/SGSA_PWMSts' */
boolean_T SGPP_ClrHWFault;        /* '<S2>/SGPP_BSW_u8_ClearFlt_Volt_Curr_En' */
uint8_T SGPP_ClrResolverFault;         /* '<S2>/Switch2' */
real32_T SGPP_DcLinkVoltMeas;          /* '<S4>/SGSA_DcLinkVoltMeas' */

/* DC-link voltage measurement */
real32_T SGPP_DcLinkVoltReciprocal;    /* '<S4>/Udc' */

/* Reciprocal of DC-link voltage */
real32_T SGPP_ElecAngle;               /* '<S4>/AngleClc' */

/* Electrical angle for coordinate transformation */
real32_T SGPP_ElecSpeed;               /* '<S5>/SpeedEstimationAndCmdFilter' */

/* Electrical rotor speed */
real32_T SGPP_ElecSpeedAfterFilter;    /* Filtered electrical speed output */
real32_T SGPP_ElecSpeedBeforeFilter; /* Raw electrical speed before filtering */
uint8_T SGPP_IgnitionStatus;           /* '<S3>/KL15StatusPrc' */

/* Ignition power supply status */
real32_T SGPP_MechSpeed;               /* '<S58>/Product1' */

/* Speed setpoint from communication */
real32_T SGPP_MotorTemp1;              /* '<S3>/MotorTemperaturePrc' */

/* Motor temperature sensor 1 reading */
real32_T SGPP_PhaseACurrent;           /* '<S4>/CurrentMapAndFilter' */

/* Phase A measured current for control */
real32_T SGPP_PhaseADuty;              /* '<S2>/MapThreePhaseSignal' */

/* Phase A PWM duty cycle */
real32_T SGPP_PhaseASwitchTemp;        /* '<S3>/Signal Conversion' */

/* Maximum power switch temperature */
real32_T SGPP_PhaseBCurrent;           /* '<S35>/Data Type Conversion1' */

/* Phase B calculated current for control */
real32_T SGPP_PhaseBDuty;              /* '<S2>/MapThreePhaseSignal' */

/* Phase B PWM duty cycle */
real32_T SGPP_PhaseBSwitchTemp;        /* '<S3>/Signal Conversion1' */

/* Maximum power switch temperature */
real32_T SGPP_PhaseCCurrent;           /* '<S4>/CurrentMapAndFilter' */

/* Phase C measured current for control */
real32_T SGPP_PhaseCDuty;              /* '<S2>/MapThreePhaseSignal' */

/* Phase C PWM duty cycle */
real32_T SGPP_PhaseCSwitchTemp;        /* '<S3>/Signal Conversion2' */

/* Maximum power switch temperature */
real32_T SGPP_PolePairRatio;           /* '<S1>/Divide1' */

/* Motor to resolver pole pair ratio */
uint8_T SGPP_PolePairs;                /* '<S1>/Parameter4' */

/* Motor pole pair count */
real32_T SGPP_PolePairsReciprocal;     /* '<S1>/Divide' */

/* Reciprocal of motor pole pair number */
real32_T SGPP_PolePairsReciprocal_IRV; /* '<S1>/Divide' */

/* Pole pair reciprocal for internal routing */
uint8_T SGPP_PolePairs_IRV;            /* '<S1>/Parameter4' */

/* Motor pole pairs for internal routing */
uint8_T SGPP_ResolverPolePairs;        /* '<S1>/Parameter1' */

/* Resolver pole pair count */
real32_T SGPP_SampleTime1;             /* '<S39>/Data Type Conversion' */

/* Primary control loop sampling time */
real32_T SGPP_SampleTime1Reciprocal;   /* '<S39>/Data Type Conversion1' */

/* Reciprocal of primary sampling time */
real32_T SGPP_SampleTime2;             /* '<S1>/Constant3' */

/* Secondary control loop sampling time */
real32_T SGPP_SampleTime2_IRV;         /* '<S1>/Constant3' */

/* Secondary sampling time for internal routing */
real32_T SGPP_SampleTime4;             /* '<S1>/Constant16' */

/* Quaternary control loop sampling time */
real32_T SGPP_SampleTime4_IRV;         /* '<S1>/Constant16' */

/* Quaternary sampling time for internal routing */
uint8_T SGPP_SetDriverSts;             /* '<S2>/SGPP_BSW_u8_PWM_Enable' */
real32_T SGPP_SetFreq;                 /* '<S2>/SGPP_kFOC_f32_PWMFreq_Hz' */
uint8_T SGPP_SetHighASCFlg;            /* '<S2>/SGPP_BSW_u8_ASC_Enable' */
boolean_T SGPP_SetPwrOffDlyFlg;       /* '<S2>/SGPP_BSW_u8_CutOffDelayEn_flg' */
real32_T SGPP_SimElecAngle;            /* '<S5>/SpeedEstimationAndCmdFilter' */

/* Electrical angle for coordinate transformation */
real32_T SGPP_SpeedSp;                 /* '<S5>/SpeedEstimationAndCmdFilter' */

/* Speed setpoint from communication */
real32_T SGPP_SwitchTempMax;           /* '<S3>/IGBTTemperaturePrc' */

/* Maximum power switch temperature */
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Block states (default storage) */
DW_SigPreProcessor_T SigPreProcessor_DW;

/* Real-time model */
static RT_MODEL_SigPreProcessor_T SigPreProcessor_M_;
RT_MODEL_SigPreProcessor_T *const SigPreProcessor_M = &SigPreProcessor_M_;

/* Model step function */
#define MTRCTRL_START_SEC_CODE_FLS_DEFAULT
#include "MtrCtrl_MemMap.h"
void SGPP_InitSystemParam_Init(void)
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/SGPP_InitSystemParam_Init' incorporates:
   *  SubSystem: '<Root>/SGPP_InitSystemParam_Init_sys'
   */
  /* Product: '<S1>/Divide' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S7>/Constant'
   */
  SGPP_PolePairsReciprocal = 1.0F / (real32_T)SGPP_PolePairs_C;

  /* Product: '<S1>/Divide1' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   */
  SGPP_PolePairRatio = (real32_T)SGPP_PolePairs_C / (real32_T)
    SGPP_ResolverPolePairs_C;

  /* SignalConversion generated from: '<S1>/SGPP_PolePairs' incorporates:
   *  Constant: '<S7>/Constant'
   */
  SGPP_PolePairs = SGPP_PolePairs_C;

  /* SignalConversion generated from: '<S1>/SGPP_PolePairsReciprocal_IRV' */
  SGPP_PolePairsReciprocal_IRV = SGPP_PolePairsReciprocal;

  /* SignalConversion generated from: '<S1>/SGPP_PolePairs_IRV' incorporates:
   *  Constant: '<S7>/Constant'
   */
  SGPP_PolePairs_IRV = SGPP_PolePairs_C;

  /* SignalConversion generated from: '<S1>/SGPP_ResolverPolePairs' incorporates:
   *  Constant: '<S6>/Constant'
   */
  SGPP_ResolverPolePairs = SGPP_ResolverPolePairs_C;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_f32_uDCActSmp_V' */
  SGPP_BSW_f32_uDCActSmp_V = SigPreProcessor_ConstB.Constant4;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_f32_iSmpPhaV_A' */
  SGPP_BSW_f32_iSmpPhaV_A = SigPreProcessor_ConstB.Constant5;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_f32_RDC_CosN' */
  SGPP_BSW_f32_RDC_CosN = SigPreProcessor_ConstB.Constant6;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_f32_RDC_CosP' */
  SGPP_BSW_f32_RDC_CosP = SigPreProcessor_ConstB.Constant7;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_f32_RDC_ExctN' */
  SGPP_BSW_f32_RDC_ExctN = SigPreProcessor_ConstB.Constant8;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_f32_RDC_ExctP' */
  SGPP_BSW_f32_RDC_ExctP = SigPreProcessor_ConstB.Constant9;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_f32_RDC_GroupDelay' */
  SGPP_BSW_f32_RDC_GroupDelay = SigPreProcessor_ConstB.Constant10;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_f32_RDC_SinN' */
  SGPP_BSW_f32_RDC_SinN = SigPreProcessor_ConstB.Constant11;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_f32_RDC_SinP' */
  SGPP_BSW_f32_RDC_SinP = SigPreProcessor_ConstB.Constant12;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_f32_RDC_TimeStamp' */
  SGPP_BSW_f32_RDC_TimeStamp = SigPreProcessor_ConstB.Constant13;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_f32_uCurrSnsrRefSmp_V' */
  SGPP_BSW_f32_uCurrSnsrRefSmp_V = SigPreProcessor_ConstB.Constant14;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_f32_uSmpRpl_V' */
  SGPP_BSW_f32_uSmpRpl_V = SigPreProcessor_ConstB.Constant15;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_bERDSBCFlt' */
  SGPP_BSW_u8_bERDSBCFlt = SigPreProcessor_ConstB.Constant19;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_bERDSBSFlt' */
  SGPP_BSW_u8_bERDSBSFlt = SigPreProcessor_ConstB.Constant20;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_bERDSQFlt' */
  SGPP_BSW_u8_bERDSQFlt = SigPreProcessor_ConstB.Constant22;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_bEREXCFlt' */
  SGPP_BSW_u8_bEREXCFlt = SigPreProcessor_ConstB.Constant28;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_bERHDFlt' */
  SGPP_BSW_u8_bERHDFlt = SigPreProcessor_ConstB.Constant23;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_bERP2Flt' */
  SGPP_BSW_u8_bERP2Flt = SigPreProcessor_ConstB.Constant24;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_bERRFlt' */
  SGPP_BSW_u8_bERRFlt = SigPreProcessor_ConstB.Constant25;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_bERSBCFlt' */
  SGPP_BSW_u8_bERSBCFlt = SigPreProcessor_ConstB.Constant26;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_bERSBSFlt' */
  SGPP_BSW_u8_bERSBSFlt = SigPreProcessor_ConstB.Constant27;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_bERSQFlt' */
  SGPP_BSW_u8_bERSQFlt = SigPreProcessor_ConstB.Constant29;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_bMcuStorgUnitFlt' */
  SGPP_BSW_u8_bMcuStorgUnitFlt = SigPreProcessor_ConstB.Constant35;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_bRotyTrfrDosFlt' */
  SGPP_BSW_u8_bRotyTrfrDosFlt = SigPreProcessor_ConstB.Constant30;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_bRotyTrfrLosFlt' */
  SGPP_BSW_u8_bRotyTrfrLosFlt = SigPreProcessor_ConstB.Constant31;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_bRotyTrfrLotFlt' */
  SGPP_BSW_u8_bRotyTrfrLotFlt = SigPreProcessor_ConstB.Constant32;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_DriFault_UH' */
  SGPP_BSW_u8_DriFault_UH = SigPreProcessor_ConstB.Constant33;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_DriFault_UL' */
  SGPP_BSW_u8_DriFault_UL = SigPreProcessor_ConstB.Constant34;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_DriFault_VH' */
  SGPP_BSW_u8_DriFault_VH = SigPreProcessor_ConstB.Constant36;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_DriFault_VL' */
  SGPP_BSW_u8_DriFault_VL = SigPreProcessor_ConstB.Constant37;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_DriFault_WH' */
  SGPP_BSW_u8_DriFault_WH = SigPreProcessor_ConstB.Constant38;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_u8_DriFault_WL' */
  SGPP_BSW_u8_DriFault_WL = SigPreProcessor_ConstB.Constant39;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_f32_uCurrSnsrVSmp_V' */
  SGPP_BSW_f32_uCurrSnsrVSmp_V = SigPreProcessor_ConstB.Constant1;

  /* SignalConversion generated from: '<S1>/SGPP_BSW_f32_ChrgWakeup_State' */
  SGPP_BSW_f32_ChrgWakeup_State = SigPreProcessor_ConstB.Constant2;

  /* SignalConversion generated from: '<S1>/SGPP_SampleTime1ms' */
  SGPP_SampleTime2 = SigPreProcessor_ConstB.Constant3;

  /* SignalConversion generated from: '<S1>/SGPP_SampleTime1ms_IRV' */
  SGPP_SampleTime2_IRV = SigPreProcessor_ConstB.Constant3;

  /* SignalConversion generated from: '<S1>/SGPP_SampleTime10ms' */
  SGPP_SampleTime4 = SigPreProcessor_ConstB.Constant16;

  /* SignalConversion generated from: '<S1>/SGPP_SampleTime10ms_IRV' */
  SGPP_SampleTime4_IRV = SigPreProcessor_ConstB.Constant16;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SGPP_InitSystemParam_Init' */
}

#define MTRCTRL_STOP_SEC_CODE_FLS_DEFAULT
#include "MtrCtrl_MemMap.h"
/* Model step function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void SGPP_ReadCmd_100us(void)
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/SGPP_ReadCmd_100us' incorporates:
   *  SubSystem: '<Root>/SGPP_ReadCmd_100us_sys'
   */
  /* MATLAB Function: '<S2>/MapThreePhaseSignal' incorporates:
   *  Constant: '<S11>/Constant'
   *  Inport: '<Root>/SGPP_FOC_f32_Uduty_Null'
   *  Inport: '<Root>/SGPP_FOC_f32_Vduty_Null'
   *  Inport: '<Root>/SGPP_FOC_f32_Wduty_Null'
   */
  switch (SGPP_PhaseMappingConfig_C) {
   case 1U:
    SGPP_PhaseADuty = SGPP_FOC_f32_Vduty_Null;
    SGPP_PhaseBDuty = SGPP_FOC_f32_Wduty_Null;
    SGPP_PhaseCDuty = SGPP_FOC_f32_Uduty_Null;
    break;

   case 2U:
    SGPP_PhaseADuty = SGPP_FOC_f32_Wduty_Null;
    SGPP_PhaseBDuty = SGPP_FOC_f32_Uduty_Null;
    SGPP_PhaseCDuty = SGPP_FOC_f32_Vduty_Null;
    break;

   case 3U:
    SGPP_PhaseADuty = SGPP_FOC_f32_Uduty_Null;
    SGPP_PhaseBDuty = SGPP_FOC_f32_Wduty_Null;
    SGPP_PhaseCDuty = SGPP_FOC_f32_Vduty_Null;
    break;

   case 4U:
    SGPP_PhaseADuty = SGPP_FOC_f32_Vduty_Null;
    SGPP_PhaseBDuty = SGPP_FOC_f32_Uduty_Null;
    SGPP_PhaseCDuty = SGPP_FOC_f32_Wduty_Null;
    break;

   case 5U:
    SGPP_PhaseADuty = SGPP_FOC_f32_Wduty_Null;
    SGPP_PhaseBDuty = SGPP_FOC_f32_Vduty_Null;
    SGPP_PhaseCDuty = SGPP_FOC_f32_Uduty_Null;
    break;

   default:
    SGPP_PhaseADuty = SGPP_FOC_f32_Uduty_Null;
    SGPP_PhaseBDuty = SGPP_FOC_f32_Vduty_Null;
    SGPP_PhaseCDuty = SGPP_FOC_f32_Wduty_Null;
    break;
  }

  /* End of MATLAB Function: '<S2>/MapThreePhaseSignal' */

  /* SignalConversion generated from: '<S2>/SGPP_BSW_u8_ASC_Enable' incorporates:
   *  Inport: '<Root>/SGPP_BSW_u8_ASC_Enable'
   */
  SGPP_SetHighASCFlg = SGPP_BSW_u8_ASC_Enable;

  /* SignalConversion generated from: '<S2>/SGPP_kFOC_f32_PWMFreq_Hz' incorporates:
   *  Inport: '<Root>/SGPP_kFOC_f32_PWMFreq_Hz'
   */
  SGPP_SetFreq = SGPP_kFOC_f32_PWMFreq_Hz;

  /* SignalConversion generated from: '<S2>/SGPP_BSW_u8_ClearFlt_Volt_Curr_En' incorporates:
   *  Inport: '<Root>/SGPP_BSW_u8_ClearFlt_Volt_Curr_En'
   */
  SGPP_ClrHWFault = SGPP_BSW_u8_ClearFlt_Volt_Curr_En;

  /* SignalConversion generated from: '<S2>/SGPP_BSW_u8_PWM_Enable' incorporates:
   *  Inport: '<Root>/SGPP_BSW_u8_PWM_Enable'
   */
  SGPP_SetDriverSts = SGPP_BSW_u8_PWM_Enable;

  /* SignalConversion generated from: '<S2>/SGPP_BSW_u8_CutOffDelayEn_flg' incorporates:
   *  Inport: '<Root>/SGPP_BSW_u8_CutOffDelayEn_flg'
   */
  SGPP_SetPwrOffDlyFlg = SGPP_BSW_u8_CutOffDelayEn_flg;

  /* Switch: '<S2>/Switch2' incorporates:
   *  Constant: '<S10>/Constant'
   */
  if (SGPP_ResolverFaultClrEnable_C != 0) {
    /* Switch: '<S2>/Switch2' incorporates:
     *  Constant: '<S9>/Constant'
     */
    SGPP_ClrResolverFault = SGSA_ResolverFaultClr_C;
  } else {
    /* Switch: '<S2>/Switch2' incorporates:
     *  Inport: '<Root>/SGPP_BSW_u8_ClearFlt_Roty_En'
     */
    SGPP_ClrResolverFault = SGPP_BSW_u8_ClearFlt_Roty_En;
  }

  /* End of Switch: '<S2>/Switch2' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SGPP_ReadCmd_100us' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model step function */
#define MTRCTRL_START_SEC_CODE_FLS_DEFAULT
#include "MtrCtrl_MemMap.h"
void SGPP_ReadTempVolt_1ms(void)
{
  int32_T tmp;
  int32_T tmp_0;
  uint8_T rtb_MultiportSwitch;
  boolean_T rtb_RelationalOperator1_a;

  /* RootInportFunctionCallGenerator generated from: '<Root>/SGPP_ReadTempVolt_1ms' incorporates:
   *  SubSystem: '<Root>/SGPP_ReadTempVolt_1ms_sys'
   */
  /* SignalConversion generated from: '<S3>/SGSA_MotorTemp1' incorporates:
   *  Inport: '<Root>/SGSA_MotorTemp1'
   */
  SGPP_BSW_f32_tMotTemp_C = SGSA_MotorTemp1;

  /* SignalConversion generated from: '<S3>/SGPP_MotorTemp1' */
  SGPP_MotorTemp1 = SGPP_BSW_f32_tMotTemp_C;

  /* SignalConversion: '<S3>/Signal Conversion' incorporates:
   *  Inport: '<Root>/SGSA_PhaseASwitchTemp'
   */
  SGPP_BSW_f32_tIGBTTempU_C = SGSA_PhaseASwitchTemp;

  /* SignalConversion generated from: '<S3>/SGPP_PhaseASwitchTemp' */
  SGPP_PhaseASwitchTemp = SGPP_BSW_f32_tIGBTTempU_C;

  /* SignalConversion: '<S3>/Signal Conversion1' incorporates:
   *  Inport: '<Root>/SGSA_PhaseBSwitchTemp'
   */
  SGPP_BSW_f32_tIGBTTempV_C = SGSA_PhaseBSwitchTemp;

  /* SignalConversion generated from: '<S3>/SGPP_PhaseBSwitchTemp' */
  SGPP_PhaseBSwitchTemp = SGPP_BSW_f32_tIGBTTempV_C;

  /* SignalConversion: '<S3>/Signal Conversion2' incorporates:
   *  Inport: '<Root>/SGSA_PhaseCSwitchTemp'
   */
  SGPP_BSW_f32_tIGBTTempW_C = SGSA_PhaseCSwitchTemp;

  /* SignalConversion generated from: '<S3>/SGPP_PhaseCSwitchTemp' */
  SGPP_PhaseCSwitchTemp = SGPP_BSW_f32_tIGBTTempW_C;

  /* SignalConversion generated from: '<S3>/SGPP_SwitchTempMax' */
  SGPP_SwitchTempMax = 0.0F;

  /* SignalConversion generated from: '<S3>/SGSA_PhaseASwitchTempAD' incorporates:
   *  Inport: '<Root>/SGSA_PhaseASwitchTempAD'
   */
  SGPP_BSW_f32_uIGBTTempUSmp_V = SGSA_PhaseASwitchTempAD;

  /* SignalConversion generated from: '<S3>/SGSA_PhaseBSwitchTempAD' incorporates:
   *  Inport: '<Root>/SGSA_PhaseBSwitchTempAD'
   */
  SGPP_BSW_f32_uIGBTTempVSmp_V = SGSA_PhaseBSwitchTempAD;

  /* SignalConversion generated from: '<S3>/SGSA_PhaseCSwitchTempAD' incorporates:
   *  Inport: '<Root>/SGSA_PhaseCSwitchTempAD'
   */
  SGPP_BSW_f32_uIGBTTempWSmp_V = SGSA_PhaseCSwitchTempAD;

  /* SignalConversion generated from: '<S3>/SGSA_BatteryVolt' incorporates:
   *  Inport: '<Root>/SGSA_BatteryVolt'
   */
  SGPP_BSW_f32_u12V_V = SGSA_BatteryVolt;

  /* SignalConversion generated from: '<S3>/SGSA_PwrChipVolt' incorporates:
   *  Inport: '<Root>/SGSA_PwrChipVolt'
   */
  SGPP_BSW_f32_u5V_V = SGSA_PwrChipVolt;

  /* SignalConversion generated from: '<S3>/SGSA_MotorTemp1AD' incorporates:
   *  Inport: '<Root>/SGSA_MotorTemp1AD'
   */
  SGPP_BSW_f32_uMotTempSmp_V = SGSA_MotorTemp1AD;

  /* SignalConversion generated from: '<S3>/SGSA_DriveErr' incorporates:
   *  Inport: '<Root>/SGSA_DriveErr'
   */
  SGPP_BSW_f32_Drive_Error = SGSA_DriveErr;

  /* SignalConversion generated from: '<S3>/SGSA_HDriFault' incorporates:
   *  Inport: '<Root>/SGSA_HDriFault'
   */
  SGPP_BSW_f32_DriveHBridg_Error = SGSA_HDriFault;

  /* SignalConversion generated from: '<S3>/SGSA_LDriFault' incorporates:
   *  Inport: '<Root>/SGSA_LDriFault'
   */
  SGPP_BSW_f32_DriveLBridg_Error = SGSA_LDriFault;

  /* SignalConversion generated from: '<S3>/SGSA_HwOvercurSt' incorporates:
   *  Inport: '<Root>/SGSA_HwOvercurSt'
   */
  SGPP_BSW_u8_HWOCFlt = SGSA_HwOvercurSt;

  /* SignalConversion generated from: '<S3>/SGSA_HwOvervoltSt' incorporates:
   *  Inport: '<Root>/SGSA_HwOvervoltSt'
   */
  SGPP_BSW_u8_HWOVFlt = SGSA_HwOvervoltSt;

  /* Sum: '<S25>/Add2' incorporates:
   *  Constant: '<S25>/0 Constant4'
   *  Constant: '<S27>/Constant'
   */
  tmp_0 = (int32_T)((uint32_T)SGPP_IgnitionVoltThrHigh_C + ((uint8_T)1U));
  if ((uint32_T)tmp_0 > 255U) {
    tmp_0 = 255;
  }

  /* MultiPortSwitch: '<S25>/Multiport Switch' incorporates:
   *  Constant: '<S24>/Constant'
   *  Constant: '<S25>/0 Constant'
   *  Inport: '<Root>/SGSA_IgnitionVolt'
   *  MinMax: '<S25>/Max'
   *  RelationalOperator: '<S15>/Relational Operator'
   *  Sum: '<S25>/Add'
   *  Sum: '<S25>/Add1'
   *  UnitDelay: '<S30>/Bare Unit Delay'
   */
  if (!(SGSA_IgnitionVolt < SGPP_IgnitionVoltThreshold_C)) {
    /* Sum: '<S25>/Add' incorporates:
     *  Constant: '<S21>/Constant2'
     *  UnitDelay: '<S30>/Bare Unit Delay'
     */
    tmp = SigPreProcessor_DW.BareUnitDelay_DSTATE - ((uint8_T)1U);
    if (tmp < 0) {
      tmp = 0;
    }

    rtb_MultiportSwitch = (uint8_T)tmp;
  } else {
    if (((uint8_T)0U) >= SigPreProcessor_DW.BareUnitDelay_DSTATE) {
      /* MinMax: '<S25>/Max' incorporates:
       *  Constant: '<S25>/0 Constant'
       */
      rtb_MultiportSwitch = ((uint8_T)0U);
    } else {
      /* MinMax: '<S25>/Max' incorporates:
       *  UnitDelay: '<S30>/Bare Unit Delay'
       */
      rtb_MultiportSwitch = SigPreProcessor_DW.BareUnitDelay_DSTATE;
    }

    /* Sum: '<S25>/Add1' incorporates:
     *  Constant: '<S21>/Constant1'
     *  MinMax: '<S25>/Max'
     */
    tmp = (int32_T)((uint32_T)rtb_MultiportSwitch + ((uint8_T)1U));
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    rtb_MultiportSwitch = (uint8_T)tmp;
  }

  /* End of MultiPortSwitch: '<S25>/Multiport Switch' */

  /* Sum: '<S26>/Add' incorporates:
   *  Constant: '<S26>/Constant3'
   *  UnitDelay: '<S26>/Unit Delay'
   */
  tmp = (int32_T)((uint32_T)((uint8_T)1U) +
                  SigPreProcessor_DW.UnitDelay_DSTATE_i);
  if ((uint32_T)tmp > 255U) {
    tmp = 255;
  }

  /* Switch: '<S31>/Switch2' incorporates:
   *  Constant: '<S26>/Constant4'
   *  Constant: '<S26>/Constant5'
   *  RelationalOperator: '<S31>/LowerRelop1'
   *  RelationalOperator: '<S31>/UpperRelop'
   *  Sum: '<S26>/Add'
   *  Switch: '<S31>/Switch'
   *  UnitDelay: '<S26>/Unit Delay'
   */
  if ((uint8_T)tmp > ((uint8_T)15U)) {
    SigPreProcessor_DW.UnitDelay_DSTATE_i = ((uint8_T)15U);
  } else if ((uint8_T)tmp < ((uint8_T)0U)) {
    /* Switch: '<S31>/Switch' incorporates:
     *  Constant: '<S26>/Constant4'
     *  UnitDelay: '<S26>/Unit Delay'
     */
    SigPreProcessor_DW.UnitDelay_DSTATE_i = ((uint8_T)0U);
  } else {
    SigPreProcessor_DW.UnitDelay_DSTATE_i = (uint8_T)tmp;
  }

  /* End of Switch: '<S31>/Switch2' */

  /* RelationalOperator: '<S26>/Relational Operator1' incorporates:
   *  Constant: '<S26>/Constant5'
   *  UnitDelay: '<S26>/Unit Delay'
   */
  rtb_RelationalOperator1_a = (SigPreProcessor_DW.UnitDelay_DSTATE_i < ((uint8_T)
    15U));

  /* Switch: '<S30>/Enable' incorporates:
   *  Constant: '<S25>/Constant2'
   *  Logic: '<S30>/Logical Operator1'
   *  Logic: '<S30>/Logical Operator2'
   *  Switch: '<S30>/Reset'
   */
  if ((!rtb_RelationalOperator1_a) && true) {
    /* Switch: '<S28>/Switch2' incorporates:
     *  Constant: '<S25>/0 Constant1'
     *  RelationalOperator: '<S28>/LowerRelop1'
     *  RelationalOperator: '<S28>/UpperRelop'
     *  Sum: '<S25>/Add2'
     *  Switch: '<S28>/Switch'
     *  UnitDelay: '<S30>/Bare Unit Delay'
     */
    if (rtb_MultiportSwitch > (uint8_T)tmp_0) {
      SigPreProcessor_DW.BareUnitDelay_DSTATE = (uint8_T)tmp_0;
    } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
      /* Switch: '<S28>/Switch' incorporates:
       *  Constant: '<S25>/0 Constant1'
       *  UnitDelay: '<S30>/Bare Unit Delay'
       */
      SigPreProcessor_DW.BareUnitDelay_DSTATE = ((uint8_T)0U);
    } else {
      SigPreProcessor_DW.BareUnitDelay_DSTATE = rtb_MultiportSwitch;
    }

    /* End of Switch: '<S28>/Switch2' */
  } else if (rtb_RelationalOperator1_a) {
    /* Switch: '<S30>/Reset' incorporates:
     *  Constant: '<S30>/iv'
     *  UnitDelay: '<S30>/Bare Unit Delay'
     */
    SigPreProcessor_DW.BareUnitDelay_DSTATE = ((uint8_T)0U);
  }

  /* End of Switch: '<S30>/Enable' */

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S21>/Constant'
   *  RelationalOperator: '<S25>/Relational Operator'
   *  RelationalOperator: '<S25>/Relational Operator1'
   *  Sum: '<S25>/Add2'
   *  Switch: '<S29>/Switch1'
   *  UnitDelay: '<S30>/Bare Unit Delay'
   */
  if (SigPreProcessor_DW.BareUnitDelay_DSTATE >= (uint8_T)tmp_0) {
    /* Switch: '<S29>/Switch' incorporates:
     *  Constant: '<S29>/Constant1'
     */
    SigPreProcessor_DW.Memory_PreviousInput = true;
  } else if (SigPreProcessor_DW.BareUnitDelay_DSTATE <= ((uint8_T)0U)) {
    /* Switch: '<S29>/Switch' incorporates:
     *  Constant: '<S29>/Constant4'
     *  Switch: '<S29>/Switch1'
     */
    SigPreProcessor_DW.Memory_PreviousInput = false;
  }

  /* End of Switch: '<S29>/Switch' */

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S23>/Constant'
   */
  if (SGPP_IgnitionStatusSource_C != 0) {
    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S22>/Constant'
     */
    SGPP_BSW_f32_KL15_State = SGPP_IgnitionStatus_C;
  } else {
    /* Switch: '<S15>/Switch' incorporates:
     *  DataTypeConversion: '<S15>/Data Type Conversion'
     *  DataTypeConversion: '<S29>/Data Type Conversion EveSt2'
     *  Logic: '<S15>/Logical Operator1'
     */
    SGPP_BSW_f32_KL15_State = (uint8_T)!SigPreProcessor_DW.Memory_PreviousInput;
  }

  /* End of Switch: '<S15>/Switch' */

  /* SignalConversion generated from: '<S3>/SGPP_IgnitionStatus' */
  SGPP_IgnitionStatus = SGPP_BSW_f32_KL15_State;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SGPP_ReadTempVolt_1ms' */
}

#define MTRCTRL_STOP_SEC_CODE_FLS_DEFAULT
#include "MtrCtrl_MemMap.h"
/* Model step function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void SGPP_Read_100us(void)
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/SGPP_Read_100us' incorporates:
   *  SubSystem: '<Root>/SGPP_Read_100us_sys'
   */
  /* MATLAB Function: '<S35>/MapThreePhaseSignal' incorporates:
   *  Constant: '<S45>/Constant'
   */
  switch (SGPP_PhaseMappingConfig_C) {
   case 1U:
    /* DataTypeConversion: '<S35>/Data Type Conversion' */
    SGPP_BSW_f32_iSmpPhaU_A = 0.0F;

    /* DataTypeConversion: '<S35>/Data Type Conversion1' incorporates:
     *  Inport: '<Root>/SGSA_PhaseCCurrent'
     */
    SGPP_PhaseBCurrent = SGSA_PhaseCCurrent;

    /* DataTypeConversion: '<S35>/Data Type Conversion2' incorporates:
     *  Inport: '<Root>/SGSA_PhaseACurrent'
     */
    SGPP_BSW_f32_iSmpPhaW_A = SGSA_PhaseACurrent;
    break;

   case 2U:
    /* DataTypeConversion: '<S35>/Data Type Conversion' incorporates:
     *  Inport: '<Root>/SGSA_PhaseCCurrent'
     */
    SGPP_BSW_f32_iSmpPhaU_A = SGSA_PhaseCCurrent;

    /* DataTypeConversion: '<S35>/Data Type Conversion1' incorporates:
     *  Inport: '<Root>/SGSA_PhaseACurrent'
     */
    SGPP_PhaseBCurrent = SGSA_PhaseACurrent;

    /* DataTypeConversion: '<S35>/Data Type Conversion2' */
    SGPP_BSW_f32_iSmpPhaW_A = 0.0F;
    break;

   case 3U:
    /* DataTypeConversion: '<S35>/Data Type Conversion' incorporates:
     *  Inport: '<Root>/SGSA_PhaseACurrent'
     */
    SGPP_BSW_f32_iSmpPhaU_A = SGSA_PhaseACurrent;

    /* DataTypeConversion: '<S35>/Data Type Conversion1' incorporates:
     *  Inport: '<Root>/SGSA_PhaseCCurrent'
     */
    SGPP_PhaseBCurrent = SGSA_PhaseCCurrent;

    /* DataTypeConversion: '<S35>/Data Type Conversion2' */
    SGPP_BSW_f32_iSmpPhaW_A = 0.0F;
    break;

   case 4U:
    /* DataTypeConversion: '<S35>/Data Type Conversion' */
    SGPP_BSW_f32_iSmpPhaU_A = 0.0F;

    /* DataTypeConversion: '<S35>/Data Type Conversion1' incorporates:
     *  Inport: '<Root>/SGSA_PhaseACurrent'
     */
    SGPP_PhaseBCurrent = SGSA_PhaseACurrent;

    /* DataTypeConversion: '<S35>/Data Type Conversion2' incorporates:
     *  Inport: '<Root>/SGSA_PhaseCCurrent'
     */
    SGPP_BSW_f32_iSmpPhaW_A = SGSA_PhaseCCurrent;
    break;

   case 5U:
    /* DataTypeConversion: '<S35>/Data Type Conversion' incorporates:
     *  Inport: '<Root>/SGSA_PhaseCCurrent'
     */
    SGPP_BSW_f32_iSmpPhaU_A = SGSA_PhaseCCurrent;

    /* DataTypeConversion: '<S35>/Data Type Conversion1' */
    SGPP_PhaseBCurrent = 0.0F;

    /* DataTypeConversion: '<S35>/Data Type Conversion2' incorporates:
     *  Inport: '<Root>/SGSA_PhaseACurrent'
     */
    SGPP_BSW_f32_iSmpPhaW_A = SGSA_PhaseACurrent;
    break;

   default:
    /* DataTypeConversion: '<S35>/Data Type Conversion' incorporates:
     *  Inport: '<Root>/SGSA_PhaseACurrent'
     */
    SGPP_BSW_f32_iSmpPhaU_A = SGSA_PhaseACurrent;

    /* DataTypeConversion: '<S35>/Data Type Conversion1' */
    SGPP_PhaseBCurrent = 0.0F;

    /* DataTypeConversion: '<S35>/Data Type Conversion2' incorporates:
     *  Inport: '<Root>/SGSA_PhaseCCurrent'
     */
    SGPP_BSW_f32_iSmpPhaW_A = SGSA_PhaseCCurrent;
    break;
  }

  /* End of MATLAB Function: '<S35>/MapThreePhaseSignal' */

  /* SignalConversion generated from: '<S4>/SGPP_PhaseACurrent' */
  SGPP_PhaseACurrent = SGPP_BSW_f32_iSmpPhaU_A;

  /* SignalConversion generated from: '<S4>/SGPP_PhaseCCurrent' */
  SGPP_PhaseCCurrent = SGPP_BSW_f32_iSmpPhaW_A;

  /* SignalConversion generated from: '<S4>/SGSA_PhaseACurrentAD' incorporates:
   *  Inport: '<Root>/SGSA_PhaseACurrentAD'
   */
  SGPP_BSW_f32_uCurrSnsrUSmp_V = SGSA_PhaseACurrentAD;

  /* SignalConversion generated from: '<S4>/SGSA_PhaseCCurrentAD' incorporates:
   *  Inport: '<Root>/SGSA_PhaseCCurrentAD'
   */
  SGPP_BSW_f32_uCurrSnsrWSmp_V = SGSA_PhaseCCurrentAD;

  /* SignalConversion generated from: '<S4>/SGSA_DcLinkVoltMeas' incorporates:
   *  Inport: '<Root>/SGSA_DcLinkVoltMeas'
   */
  SGPP_DcLinkVoltMeas = SGSA_DcLinkVoltMeas;

  /* SignalConversion generated from: '<S4>/SGPP_BSW_f32_uDcHV_V' */
  SGPP_BSW_f32_uDcHV_V = SGPP_DcLinkVoltMeas;

  /* SignalConversion generated from: '<S4>/SGPP_DcLinkVoltReciprocal' */
  SGPP_DcLinkVoltReciprocal = 0.0F;

  /* SignalConversion generated from: '<S4>/SGSA_DcLinkVoltMeasAD' incorporates:
   *  Inport: '<Root>/SGSA_DcLinkVoltMeasAD'
   */
  SGPP_BSW_f32_uDcHVSmp_V = SGSA_DcLinkVoltMeasAD;

  /* DataTypeConversion: '<S39>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/SGRD_PwmTs'
   */
  SGPP_SampleTime1 = SGRD_PwmTs;

  /* DataTypeConversion: '<S39>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/SGRD_PwmFreq'
   */
  SGPP_SampleTime1Reciprocal = SGRD_PwmFreq;

  /* SignalConversion generated from: '<S4>/SGSA_PWMSts' incorporates:
   *  Inport: '<Root>/SGSA_PWMSts'
   */
  SGPP_BSW_u8_stPWM = SGSA_PWMSts;

  /* SignalConversion generated from: '<S4>/SGRD_CosEnvelope' incorporates:
   *  Inport: '<Root>/SGRD_CosEnvelope'
   */
  SGPP_BSW_f32_RDC_CosEvlp = SGRD_CosEnvelope;

  /* SignalConversion generated from: '<S4>/SGRD_SineEnvelope' incorporates:
   *  Inport: '<Root>/SGRD_SinEnvelope'
   */
  SGPP_BSW_f32_RDC_SinEvlp = SGRD_SinEnvelope;

  /* DataTypeConversion: '<S37>/Data Type Conversion' incorporates:
   *  Constant: '<S37>/Constant'
   *  Inport: '<Root>/SGSA_ResolverError'
   *  RelationalOperator: '<S37>/Relational Operator1'
   */
  SGPP_BSW_u8_bRotyTrfrFlt = (uint8_T)(SGSA_ResolverError > ((uint8_T)0U));

  /* DataTypeConversion: '<S37>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/SGSA_ResolverError'
   *  S-Function (sfix_bitop): '<S37>/Bitwise AND'
   */
  SGPP_BSW_u8_bERCNVFlt = (uint8_T)(SGSA_ResolverError & ((uint8_T)1U));

  /* Outputs for Atomic SubSystem: '<S37>/Bit Shift1' */
  /* DataTypeConversion: '<S37>/Data Type Conversion2' incorporates:
   *  Inport: '<Root>/SGSA_ResolverError'
   *  MATLAB Function: '<S47>/bit_shift'
   *  S-Function (sfix_bitop): '<S37>/Bitwise AND1'
   */
  SGPP_BSW_u8_bERDCNVFlt = (uint8_T)((uint32_T)(SGSA_ResolverError & ((uint8_T)
    2U)) >> 1);

  /* End of Outputs for SubSystem: '<S37>/Bit Shift1' */

  /* Outputs for Atomic SubSystem: '<S37>/Bit Shift2' */
  /* DataTypeConversion: '<S37>/Data Type Conversion3' incorporates:
   *  Inport: '<Root>/SGSA_ResolverError'
   *  MATLAB Function: '<S48>/bit_shift'
   *  S-Function (sfix_bitop): '<S37>/Bitwise AND2'
   */
  SGPP_BSW_u8_bERDEXCFlt = (uint8_T)((uint32_T)(SGSA_ResolverError & ((uint8_T)
    4U)) >> 2);

  /* End of Outputs for SubSystem: '<S37>/Bit Shift2' */

  /* Outputs for Atomic SubSystem: '<S37>/Bit Shift3' */
  /* DataTypeConversion: '<S37>/Data Type Conversion4' incorporates:
   *  Inport: '<Root>/SGSA_ResolverError'
   *  MATLAB Function: '<S49>/bit_shift'
   *  S-Function (sfix_bitop): '<S37>/Bitwise AND3'
   */
  SGPP_BSW_u8_bERDP2Flt = (uint8_T)((uint32_T)(SGSA_ResolverError & ((uint8_T)8U))
    >> 3);

  /* End of Outputs for SubSystem: '<S37>/Bit Shift3' */

  /* SwitchCase: '<S34>/Switch_Angle' incorporates:
   *  Constant: '<S41>/Constant'
   */
  if (SGPP_AngleSourceSelect_C == 3) {
    /* Outputs for IfAction SubSystem: '<S34>/Subsystem' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    /* Merge: '<S34>/Merge' incorporates:
     *  Inport: '<Root>/SGSA_ElecAngle'
     *  SignalConversion generated from: '<S42>/SGSA_ElecAngle'
     */
    SGPP_BSW_f32_eAngle_rad = SGSA_ElecAngle;

    /* End of Outputs for SubSystem: '<S34>/Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S34>/Subsystem1' incorporates:
     *  ActionPort: '<S43>/Action Port'
     */
    /* Merge: '<S34>/Merge' incorporates:
     *  SignalConversion generated from: '<S43>/SGPP_SimElecAngle'
     */
    SGPP_BSW_f32_eAngle_rad = SGPP_SimElecAngle;

    /* End of Outputs for SubSystem: '<S34>/Subsystem1' */
  }

  /* End of SwitchCase: '<S34>/Switch_Angle' */

  /* SignalConversion generated from: '<S4>/SGPP_ElecAngle' */
  SGPP_ElecAngle = SGPP_BSW_f32_eAngle_rad;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SGPP_Read_100us' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model step function */
#pragma ghs section data =".rdc_data"
#pragma ghs section text =".rdc_code"
#pragma ghs section bss =".rdc_bss"

void SGPP_SpeedClc_96us(void)
{
  int32_T tmp_0;
  real32_T rtb_Add_md;
  real32_T tmp;

  /* RootInportFunctionCallGenerator generated from: '<Root>/SGPP_SpeedClc_96us' incorporates:
   *  SubSystem: '<Root>/SGPP_SpeedClc_96us_sys'
   */
  /* SwitchCase: '<S58>/Switch_Angle' incorporates:
   *  Constant: '<S64>/Constant'
   */
  if (SGPP_AngleSourceSelect_C == 3) {
    /* Outputs for IfAction SubSystem: '<S58>/ThetaSensor' incorporates:
     *  ActionPort: '<S66>/Action Port'
     */
    /* Sum: '<S66>/Add' incorporates:
     *  Inport: '<Root>/SGRD_EstTheta'
     *  UnitDelay: '<S66>/Unit Delay'
     */
    SigPreProcessor_DW.UnitDelay_DSTATE_b = SGRD_EstTheta -
      SigPreProcessor_DW.UnitDelay_DSTATE_b;

    /* SignalConversion generated from: '<S5>/SGPP_SimElecAngle' incorporates:
     *  Inport: '<Root>/SGRD_EstTheta'
     *  SignalConversion generated from: '<S66>/AgEltl'
     */
    SGPP_SimElecAngle = SGRD_EstTheta;

    /* Switch: '<S68>/Switch' incorporates:
     *  Constant: '<S68>/Constant'
     *  Constant: '<S68>/Constant2'
     *  RelationalOperator: '<S68>/Relational Operator'
     *  RelationalOperator: '<S68>/Relational Operator1'
     *  Switch: '<S68>/Switch1'
     */
    if (SigPreProcessor_DW.UnitDelay_DSTATE_b >= 4.71238899F) {
      /* Sum: '<S66>/Add' incorporates:
       *  Constant: '<S68>/Constant1'
       *  Sum: '<S68>/Add'
       */
      SigPreProcessor_DW.UnitDelay_DSTATE_b -= 6.28318548F;
    } else if (SigPreProcessor_DW.UnitDelay_DSTATE_b <= (-4.71238899F)) {
      /* Sum: '<S66>/Add' incorporates:
       *  Constant: '<S68>/Constant3'
       *  Sum: '<S68>/Add1'
       *  Switch: '<S68>/Switch1'
       *  UnitDelay: '<S66>/Unit Delay'
       */
      SigPreProcessor_DW.UnitDelay_DSTATE_b += 6.28318548F;
    }

    /* End of Switch: '<S68>/Switch' */

    /* Product: '<S65>/Product' incorporates:
     *  Constant: '<S56>/Constant3'
     *  Product: '<S68>/Product'
     *  UnitDelay: '<S66>/Unit Delay'
     */
    SGPP_ElecSpeedBeforeFilter = SigPreProcessor_DW.UnitDelay_DSTATE_b *
      10016.0254F;

    /* Update for Sum: '<S66>/Add' incorporates:
     *  Inport: '<Root>/SGRD_EstTheta'
     *  UnitDelay: '<S66>/Unit Delay'
     */
    SigPreProcessor_DW.UnitDelay_DSTATE_b = SGRD_EstTheta;

    /* End of Outputs for SubSystem: '<S58>/ThetaSensor' */
  } else {
    /* Outputs for IfAction SubSystem: '<S58>/ResolverSignalEmulation' incorporates:
     *  ActionPort: '<S65>/Action Port'
     */
    /* Product: '<S65>/Product' incorporates:
     *  Constant: '<S63>/Constant'
     *  Constant: '<S65>/Constant'
     */
    SGPP_ElecSpeedBeforeFilter = (real32_T)(SGPP_SetSpeed_C * (real32_T)
      SGPP_PolePairs_IRV * 0.1047198);

    /* Sum: '<S65>/Add' incorporates:
     *  Constant: '<S56>/Constant1'
     *  Product: '<S65>/Product1'
     *  UnitDelay: '<S65>/Unit Delay'
     */
    rtb_Add_md = SGPP_ElecSpeedBeforeFilter * 9.984E-5F +
      SigPreProcessor_DW.UnitDelay_DSTATE;

    /* DataTypeConversion: '<S67>/Data Type Conversion' incorporates:
     *  Constant: '<S67>/Constant'
     *  Product: '<S67>/Product'
     */
    tmp = 0.159154937F * rtb_Add_md;
    if (tmp < 2.14748365E+9F) {
      if (tmp >= -2.14748365E+9F) {
        tmp_0 = (int32_T)tmp;
      } else {
        tmp_0 = INT32_MIN;
      }
    } else {
      tmp_0 = INT32_MAX;
    }

    /* Sum: '<S67>/Add' incorporates:
     *  Constant: '<S67>/Constant1'
     *  DataTypeConversion: '<S67>/Data Type Conversion'
     *  Product: '<S67>/Product1'
     */
    SigPreProcessor_DW.UnitDelay_DSTATE = rtb_Add_md - (real32_T)tmp_0 *
      6.28318548F;

    /* Switch: '<S67>/Switch' incorporates:
     *  Constant: '<S67>/Constant2'
     *  RelationalOperator: '<S67>/Relational Operator'
     */
    if (SigPreProcessor_DW.UnitDelay_DSTATE < 0.0F) {
      /* Sum: '<S67>/Add' incorporates:
       *  Constant: '<S67>/Constant4'
       *  Sum: '<S67>/Add1'
       */
      SigPreProcessor_DW.UnitDelay_DSTATE += 6.28318548F;
    }

    /* End of Switch: '<S67>/Switch' */

    /* SignalConversion generated from: '<S5>/SGPP_SimElecAngle' incorporates:
     *  SignalConversion generated from: '<S65>/AgEltl'
     *  UnitDelay: '<S65>/Unit Delay'
     */
    SGPP_SimElecAngle = SigPreProcessor_DW.UnitDelay_DSTATE;

    /* End of Outputs for SubSystem: '<S58>/ResolverSignalEmulation' */
  }

  /* End of SwitchCase: '<S58>/Switch_Angle' */

  /* Product: '<S61>/Product' incorporates:
   *  Constant: '<S56>/Constant1'
   *  Constant: '<S62>/Constant'
   */
  rtb_Add_md = SGPP_MechSpeedFilterFreq_C * 9.984E-5F;

  /* Saturate: '<S61>/Saturation' */
  if (rtb_Add_md > 1.0F) {
    rtb_Add_md = 1.0F;
  } else if (rtb_Add_md < 0.0F) {
    rtb_Add_md = 0.0F;
  }

  /* Sum: '<S61>/Subtract1' incorporates:
   *  Delay: '<S61>/Delay'
   *  Product: '<S61>/Product1'
   *  Saturate: '<S61>/Saturation'
   *  Sum: '<S61>/Subtract'
   */
  SigPreProcessor_DW.Delay_DSTATE += (SGPP_ElecSpeedBeforeFilter -
    SigPreProcessor_DW.Delay_DSTATE) * rtb_Add_md;

  /* DataStoreWrite: '<S60>/Data Store Write' incorporates:
   *  Delay: '<S61>/Delay'
   */
  SGPP_ElecSpeedAfterFilter = SigPreProcessor_DW.Delay_DSTATE;

  /* Product: '<S58>/Product1' incorporates:
   *  Constant: '<S58>/Constant'
   *  Delay: '<S61>/Delay'
   *  Product: '<S58>/Product'
   */
  SGPP_MechSpeed = SGPP_PolePairsReciprocal_IRV * 9.54929638F *
    SigPreProcessor_DW.Delay_DSTATE;

  /* SignalConversion generated from: '<S5>/SGPP_BSW_f32_nRotateSpd_rpm' */
  SGPP_BSW_f32_nRotateSpd_rpm = SGPP_MechSpeed;

  /* SignalConversion generated from: '<S5>/SGPP_ElecSpeed' */
  SGPP_ElecSpeed = 0.0F;

  /* SignalConversion generated from: '<S5>/SGPP_SpeedSp' */
  SGPP_SpeedSp = 0.0F;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SGPP_SpeedClc_96us' */
}
#pragma ghs section
#pragma ghs section
#pragma ghs section


/* Model initialize function */
void SigPreProcessor_initialize(void)
{
  /* Registration code */

  /* block I/O */

  /* custom signals */
  SGPP_SampleTime2_IRV = 0.001F;
  SGPP_SampleTime4_IRV = 0.01F;
  SGPP_PolePairs_IRV = ((uint8_T)4U);

  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SGPP_InitSystemParam_Init' incorporates:
   *  SubSystem: '<Root>/SGPP_InitSystemParam_Init_sys'
   */
  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_PolePairs' incorporates:
   *  Constant: '<S7>/Constant'
   */
  SGPP_PolePairs = SGPP_PolePairs_C;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_PolePairs_IRV' incorporates:
   *  Constant: '<S7>/Constant'
   */
  SGPP_PolePairs_IRV = SGPP_PolePairs_C;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_ResolverPolePairs' incorporates:
   *  Constant: '<S6>/Constant'
   */
  SGPP_ResolverPolePairs = SGPP_ResolverPolePairs_C;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_f32_uDCActSmp_V' */
  SGPP_BSW_f32_uDCActSmp_V = SigPreProcessor_ConstB.Constant4;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_f32_iSmpPhaV_A' */
  SGPP_BSW_f32_iSmpPhaV_A = SigPreProcessor_ConstB.Constant5;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_f32_RDC_CosN' */
  SGPP_BSW_f32_RDC_CosN = SigPreProcessor_ConstB.Constant6;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_f32_RDC_CosP' */
  SGPP_BSW_f32_RDC_CosP = SigPreProcessor_ConstB.Constant7;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_f32_RDC_ExctN' */
  SGPP_BSW_f32_RDC_ExctN = SigPreProcessor_ConstB.Constant8;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_f32_RDC_ExctP' */
  SGPP_BSW_f32_RDC_ExctP = SigPreProcessor_ConstB.Constant9;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_f32_RDC_GroupDelay' */
  SGPP_BSW_f32_RDC_GroupDelay = SigPreProcessor_ConstB.Constant10;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_f32_RDC_SinN' */
  SGPP_BSW_f32_RDC_SinN = SigPreProcessor_ConstB.Constant11;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_f32_RDC_SinP' */
  SGPP_BSW_f32_RDC_SinP = SigPreProcessor_ConstB.Constant12;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_f32_RDC_TimeStamp' */
  SGPP_BSW_f32_RDC_TimeStamp = SigPreProcessor_ConstB.Constant13;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_f32_uCurrSnsrRefSmp_V' */
  SGPP_BSW_f32_uCurrSnsrRefSmp_V = SigPreProcessor_ConstB.Constant14;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_f32_uSmpRpl_V' */
  SGPP_BSW_f32_uSmpRpl_V = SigPreProcessor_ConstB.Constant15;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_bERDSBCFlt' */
  SGPP_BSW_u8_bERDSBCFlt = SigPreProcessor_ConstB.Constant19;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_bERDSBSFlt' */
  SGPP_BSW_u8_bERDSBSFlt = SigPreProcessor_ConstB.Constant20;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_bERDSQFlt' */
  SGPP_BSW_u8_bERDSQFlt = SigPreProcessor_ConstB.Constant22;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_bEREXCFlt' */
  SGPP_BSW_u8_bEREXCFlt = SigPreProcessor_ConstB.Constant28;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_bERHDFlt' */
  SGPP_BSW_u8_bERHDFlt = SigPreProcessor_ConstB.Constant23;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_bERP2Flt' */
  SGPP_BSW_u8_bERP2Flt = SigPreProcessor_ConstB.Constant24;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_bERRFlt' */
  SGPP_BSW_u8_bERRFlt = SigPreProcessor_ConstB.Constant25;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_bERSBCFlt' */
  SGPP_BSW_u8_bERSBCFlt = SigPreProcessor_ConstB.Constant26;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_bERSBSFlt' */
  SGPP_BSW_u8_bERSBSFlt = SigPreProcessor_ConstB.Constant27;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_bERSQFlt' */
  SGPP_BSW_u8_bERSQFlt = SigPreProcessor_ConstB.Constant29;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_bMcuStorgUnitFlt' */
  SGPP_BSW_u8_bMcuStorgUnitFlt = SigPreProcessor_ConstB.Constant35;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_bRotyTrfrDosFlt' */
  SGPP_BSW_u8_bRotyTrfrDosFlt = SigPreProcessor_ConstB.Constant30;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_bRotyTrfrLosFlt' */
  SGPP_BSW_u8_bRotyTrfrLosFlt = SigPreProcessor_ConstB.Constant31;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_bRotyTrfrLotFlt' */
  SGPP_BSW_u8_bRotyTrfrLotFlt = SigPreProcessor_ConstB.Constant32;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_DriFault_UH' */
  SGPP_BSW_u8_DriFault_UH = SigPreProcessor_ConstB.Constant33;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_DriFault_UL' */
  SGPP_BSW_u8_DriFault_UL = SigPreProcessor_ConstB.Constant34;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_DriFault_VH' */
  SGPP_BSW_u8_DriFault_VH = SigPreProcessor_ConstB.Constant36;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_DriFault_VL' */
  SGPP_BSW_u8_DriFault_VL = SigPreProcessor_ConstB.Constant37;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_DriFault_WH' */
  SGPP_BSW_u8_DriFault_WH = SigPreProcessor_ConstB.Constant38;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_u8_DriFault_WL' */
  SGPP_BSW_u8_DriFault_WL = SigPreProcessor_ConstB.Constant39;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_f32_uCurrSnsrVSmp_V' */
  SGPP_BSW_f32_uCurrSnsrVSmp_V = SigPreProcessor_ConstB.Constant1;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_BSW_f32_ChrgWakeup_State' */
  SGPP_BSW_f32_ChrgWakeup_State = SigPreProcessor_ConstB.Constant2;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_SampleTime1ms' */
  SGPP_SampleTime2 = SigPreProcessor_ConstB.Constant3;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_SampleTime1ms_IRV' */
  SGPP_SampleTime2_IRV = SigPreProcessor_ConstB.Constant3;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_SampleTime10ms' */
  SGPP_SampleTime4 = SigPreProcessor_ConstB.Constant16;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_SampleTime10ms_IRV' */
  SGPP_SampleTime4_IRV = SigPreProcessor_ConstB.Constant16;

  /* SystemInitialize for SignalConversion generated from: '<S1>/SGPP_PolePairsReciprocal_IRV' incorporates:
   *  Outport: '<S1>/SGPP_PolePairsReciprocal_IRV'
   */
  SGPP_PolePairsReciprocal_IRV = 0.0F;

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SGPP_InitSystemParam_Init' */

  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SGPP_ReadTempVolt_1ms' incorporates:
   *  SubSystem: '<Root>/SGPP_ReadTempVolt_1ms_sys'
   */
  /* SystemInitialize for Switch: '<S15>/Switch' incorporates:
   *  Outport: '<S3>/SGPP_BSW_f32_KL15_State'
   */
  SGPP_BSW_f32_KL15_State = ((uint8_T)1U);

  /* SystemInitialize for SignalConversion generated from: '<S3>/SGPP_IgnitionStatus' incorporates:
   *  Outport: '<S3>/SGPP_IgnitionStatus'
   */
  SGPP_IgnitionStatus = ((uint8_T)1U);

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SGPP_ReadTempVolt_1ms' */
}

/* Model terminate function */
void SigPreProcessor_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

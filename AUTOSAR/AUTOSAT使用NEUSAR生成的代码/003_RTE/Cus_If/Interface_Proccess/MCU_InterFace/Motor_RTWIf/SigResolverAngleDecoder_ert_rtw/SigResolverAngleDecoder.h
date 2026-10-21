/*
 * File: SigResolverAngleDecoder.h
 *
 * Code generated for Simulink model 'SigResolverAngleDecoder'.
 *
 * Model version                  : 1.117
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Jul  9 10:42:09 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SigResolverAngleDecoder_h_
#define RTW_HEADER_SigResolverAngleDecoder_h_
#ifndef SigResolverAngleDecoder_COMMON_INCLUDES_
#define SigResolverAngleDecoder_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                            /* SigResolverAngleDecoder_COMMON_INCLUDES_ */

#include "SigResolverAngleDecoder_types.h"
#include "Hal_GetSwitchFrequency.h"
#include "Hal_GetSwitchPeriod.h"
#include "Hal_ReadResolverSineRaw.h"
#include "Hal_ReadCurrentTimestamp.h"
#include "Hal_ReadResolverCosineRaw.h"
#include "Hal_ReadResolverTimestamp.h"
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
  real32_T Delay_DSTATE;               /* '<S51>/Delay' */
  real32_T Delay_DSTATE_p;             /* '<S12>/Delay' */
  real32_T Delay1_DSTATE;              /* '<S12>/Delay1' */
  real32_T Delay_DSTATE_i;             /* '<S28>/Delay' */
  real32_T Delay1_DSTATE_o;            /* '<S28>/Delay1' */
  real32_T Delay_DSTATE_m;             /* '<S21>/Delay' */
  real32_T Delay1_DSTATE_h;            /* '<S21>/Delay1' */
  real32_T Delay_DSTATE_c[3];          /* '<S10>/Delay' */
  real32_T Delay1_DSTATE_j[6];         /* '<S10>/Delay1' */
  real32_T Delay2_DSTATE[3];           /* '<S10>/Delay2' */
  real32_T Delay3_DSTATE[6];           /* '<S10>/Delay3' */
  uint16_T UnitDelay_DSTATE;           /* '<S62>/Unit Delay' */
  uint16_T BareUnitDelay_DSTATE;       /* '<S87>/Bare Unit Delay' */
  uint16_T BareUnitDelay_DSTATE_f;     /* '<S107>/Bare Unit Delay' */
  uint16_T BareUnitDelay_DSTATE_a;     /* '<S79>/Bare Unit Delay' */
  uint16_T BareUnitDelay_DSTATE_c;     /* '<S99>/Bare Unit Delay' */
  uint8_T UnitDelay_DSTATE_o[4];       /* '<S65>/Unit Delay' */
  uint8_T Delay_DSTATE_pn;             /* '<S30>/Delay' */
  uint8_T Delay_DSTATE_g;              /* '<S24>/Delay' */
  boolean_T Delay_DSTATE_o;            /* '<S89>/Delay' */
  boolean_T Memory_PreviousInput;      /* '<S86>/Memory' */
  boolean_T Memory_PreviousInput_d;    /* '<S106>/Memory' */
  boolean_T Memory_PreviousInput_j;    /* '<S78>/Memory' */
  boolean_T Memory_PreviousInput_a;    /* '<S98>/Memory' */
  boolean_T icLoad;                    /* '<S12>/Delay' */
  boolean_T icLoad_h;                  /* '<S12>/Delay1' */
  boolean_T icLoad_j;                  /* '<S30>/Delay' */
  boolean_T icLoad_p;                  /* '<S28>/Delay' */
  boolean_T icLoad_e;                  /* '<S28>/Delay1' */
  boolean_T icLoad_o;                  /* '<S24>/Delay' */
  boolean_T icLoad_ee;                 /* '<S21>/Delay' */
  boolean_T icLoad_f;                  /* '<S21>/Delay1' */
} DW_SigResolverAngleDecoder_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T UnaryMinus;           /* '<S45>/Unary Minus' */
} ConstB_SigResolverAngleDecoder_T;

/* Real-time Model Data Structure */
struct tag_RTM_SigResolverAngleDecoder_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_SigResolverAngleDecoder_T SigResolverAngleDecoder_DW;
extern const ConstB_SigResolverAngleDecoder_T SigResolverAngleDecoder_ConstB;/* constant block i/o */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T SGRD_NewEstTheta;      /* '<Root>/SGRD_NewEstTheta' */
extern real32_T SGRD_NewEstOmega;      /* '<Root>/SGRD_NewEstOmega' */

/* Model entry point functions */
extern void SigResolverAngleDecoder_initialize(void);
extern void SigResolverAngleDecoder_terminate(void);

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void SGRD_AngleObserver_96us(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void SGRD_CalcElecAngle_100us(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported entry point function */
extern void SGRD_DiagResolverFault_1ms(void);

/* Exported data declaration */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Par */
extern volatile real32_T SGRD_AmpDosFaultThr_C;/* Referenced by: '<S81>/Constant' */

/* Dos fault threshold for amplitude detection */
extern volatile real32_T SGRD_AmpLoFaultThr_C;/* Referenced by:
                                               * '<S73>/Constant'
                                               * '<S101>/Constant'
                                               */

/* Lower threshold for amplitude fault detection */
extern volatile uint8_T SGRD_AngleCompEna_C;/* Referenced by: '<S53>/Constant' */

/* Enable flag for angle compensation */
extern volatile real32_T SGRD_CosAmp_C;/* Referenced by: '<S41>/Constant' */

/* Amplitude calibration for cosine channel */
extern volatile real32_T SGRD_CosOffset_C;/* Referenced by: '<S40>/Constant' */

/* Offset calibration for cosine channel */
extern volatile uint16_T SGRD_DebounceDecr_C;/* Referenced by:
                                              * '<S76>/Constant'
                                              * '<S84>/Constant'
                                              * '<S95>/Constant'
                                              * '<S104>/Constant'
                                              */

/* Decrement step for fault debounce counter */
extern volatile uint16_T SGRD_DebounceIncr_C;/* Referenced by:
                                              * '<S75>/Constant'
                                              * '<S83>/Constant'
                                              * '<S94>/Constant'
                                              * '<S103>/Constant'
                                              */

/* Increment step for fault debounce counter */
extern volatile uint16_T SGRD_DebounceMaxHi_C;/* Referenced by: '<S82>/Constant' */

/* Maximum counter for high amplitude fault debounce */
extern volatile uint16_T SGRD_DebounceMaxLo_C;/* Referenced by:
                                               * '<S74>/Constant'
                                               * '<S102>/Constant'
                                               */

/* Maximum counter for low amplitude fault debounce */
extern volatile uint16_T SGRD_DebounceMaxLoss_C;/* Referenced by: '<S93>/Constant' */

/* Maximum counter for signal loss fault debounce */
extern volatile uint8_T SGRD_FaultResetEna_C;/* Referenced by: '<S43>/Constant' */

/* Enable automatic fault reset for resolver diagnostics */
extern volatile real32_T SGRD_GrpDlyResolverADC_C;/* Referenced by: '<S52>/Constant' */

/* Group delay compensation for resolver ADC */
extern volatile uint16_T SGRD_InitTimeCount_C;/* Referenced by: '<S108>/Constant' */

/* Time counter for resolver ADC initialization (500ms) */
extern volatile real32_T SGRD_MaxAccelLmt_C;/* Referenced by: '<S32>/Constant' */

/* Maximum allowable angular acceleration */
extern volatile real32_T SGRD_MaxJerkLmt_C;/* Referenced by: '<S34>/Constant' */

/* Maximum allowable angular jerk */
extern volatile real32_T SGRD_MaxSpdLmt_C;/* Referenced by: '<S26>/Constant' */

/* Maximum allowable angular velocity */
extern volatile real32_T SGRD_ObsrKi_C;/* Referenced by: '<S16>/Constant' */

/* Integral gain for 3rd-order angle observer */
extern volatile real32_T SGRD_ObsrKii_C;/* Referenced by: '<S17>/Constant' */

/* Double integral gain for 3rd-order angle observer */
extern volatile real32_T SGRD_ObsrKp_C;/* Referenced by: '<S15>/Constant' */

/* Proportional gain for 3rd-order angle observer */
extern volatile uint8_T SGRD_ResolverDirection;/* Referenced by:
                                                * '<S54>/Constant'
                                                * '<S55>/Constant'
                                                */

/* Configuration for resolver rotation direction */
extern volatile real32_T SGRD_SignalLotThr_C;/* Referenced by: '<S96>/Constant' */

/* Lot fault threshold for signal loss detection */
extern volatile real32_T SGRD_SineAmp_C;/* Referenced by: '<S39>/Constant' */

/* Amplitude calibration for sine channel */
extern volatile real32_T SGRD_SineOffset_C;/* Referenced by: '<S38>/Constant' */

/* Offset calibration for sine channel */
extern volatile real32_T SGRD_SpdFilterBw_C;/* Referenced by: '<S56>/Constant' */

/* Cutoff frequency for speed low-pass filter */
extern volatile real32_T SGRD_SpdThrLoFaultDiagLo_C;/* Referenced by: '<S91>/Constant' */

/* Lower speed threshold for low amplitude fault diagnosis */
extern volatile real32_T SGRD_SpdThrLoFaultDiag_C;/* Referenced by: '<S90>/Constant' */

/* Speed threshold for low amplitude fault diagnosis */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Sig */
extern uint32_T SGRD_AngleTS;

/* Timestamp for angle measurement sampling */
extern real32_T SGRD_CompAngle;

/* Delta Times */
extern real32_T SGRD_CosEnvelope;      /* '<S4>/Data Type Conversion8' */

/* Raw sine signal from resolver */
extern real32_T SGRD_CosNorm;

/* Normalized cosine signal after amplitude correction */
extern int16_T SGRD_CosRaw;

/* Raw cosine signal from resolver */
extern real32_T SGRD_CosRaw3Dly_IRV;   /* '<S10>/Delay2' */

/* Raw cosine signal with 3-sample delay */
extern real32_T SGRD_CosRaw6Dly_IRV;   /* '<S10>/Delay3' */

/* Raw cosine signal with 6-sample delay */
extern real32_T SGRD_CosRaw_IRV;       /* '<S10>/Data Type Conversion1' */

/* Raw cosine signal for internal processing */
extern uint32_T SGRD_CurrentTS;

/* Timestamp for current measurement sampling */
extern real32_T SGRD_DeltaTimes;

/* Delta Times */
extern real32_T SGRD_ElecAngle;        /* '<S44>/Switch' */

/* Electrical angle from observer with compensation */
extern real32_T SGRD_EstAngle;

/* Delta Times */
extern real32_T SGRD_EstOmega;         /* '<S27>/Switch2' */
extern real32_T SGRD_EstTheta;         /* '<S19>/Switch' */
extern real32_T SGRD_ObsrAngleDelta;

/* Angle delta from observer calculation */
extern real32_T SGRD_ObsrAngleDelta_IRV;/* '<S18>/Add' */

/* Observer angle delta for internal calculation */
extern real32_T SGRD_ObsrSpd;

/* Filtered angular frequency from observer */
extern real32_T SGRD_ObsrSpdRaw;

/* Raw angular frequency from observer */
extern real32_T SGRD_ObsrSpeed_IRV;    /* '<S2>/Switch2' */

/* Observer angular speed for internal calculation */
extern real32_T SGRD_PwmFreq;          /* '<S4>/Data Type Conversion5' */

/* Control system switching Frequency */
extern real32_T SGRD_PwmTs;            /* '<S46>/Data Type Conversion2' */
extern uint8_T SGRD_ResolverErr;       /* '<S65>/Add' */

/* Resolver fault detection signal */
extern uint8_T SGRD_ResolverErrLatched;

/* Latched fault flag from resolver diagnostics */
extern uint8_T SGRD_ResolverErr_IRV;   /* '<S61>/ErrCodeCalc' */

/* Resolver error signal for internal use */
extern real32_T SGRD_SinEnvelope;      /* '<S4>/Data Type Conversion9' */

/* Raw sine signal from resolver */
extern real32_T SGRD_SineNorm;

/* Normalized sine signal after amplitude correction */
extern int16_T SGRD_SineRaw;

/* Raw sine signal from resolver */
extern real32_T SGRD_SineRaw3Dly_IRV;  /* '<S10>/Delay' */

/* Raw sine signal with 3-sample delay */
extern real32_T SGRD_SineRaw6Dly_IRV;  /* '<S10>/Delay1' */

/* Raw sine signal with 6-sample delay */
extern real32_T SGRD_SineRaw_IRV;      /* '<S10>/Data Type Conversion' */

/* Raw sine signal for internal processing */
extern real32_T SGRD_SwitchFreq;

/* Control system switching Frequency */
extern real32_T SGRD_SwitchPeriod;

/* Control system switching period */
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Real-time Model object */
extern RT_MODEL_SigResolverAngleDecoder_T *const SigResolverAngleDecoder_M;

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
 * '<Root>' : 'SigResolverAngleDecoder'
 * '<S1>'   : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys'
 * '<S2>'   : 'SigResolverAngleDecoder/SGRD_CalcElecAngle_100us_sys'
 * '<S3>'   : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys'
 * '<S4>'   : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Function Caller Interface'
 * '<S5>'   : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem'
 * '<S6>'   : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Function Caller Interface/Local Variable Storage'
 * '<S7>'   : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Function Caller Interface/Local Variable Storage1'
 * '<S8>'   : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Function Caller Interface/Local Variable Storage6'
 * '<S9>'   : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver'
 * '<S10>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/Normalization'
 * '<S11>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/ResetIprtCheck'
 * '<S12>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/AngleObserver3Order'
 * '<S13>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/Local Variable Storage'
 * '<S14>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/Local Variable Storage1'
 * '<S15>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/Parameter'
 * '<S16>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/Parameter1'
 * '<S17>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/Parameter2'
 * '<S18>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/AngleObserver3Order/AgDeltaCalc'
 * '<S19>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/AngleObserver3Order/AngleWrapNegPiToPi'
 * '<S20>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/AngleObserver3Order/EnaAntiWindup'
 * '<S21>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/AngleObserver3Order/Integrator'
 * '<S22>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/AngleObserver3Order/IntegratorWithAntiSaturation'
 * '<S23>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/AngleObserver3Order/Saturation'
 * '<S24>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/AngleObserver3Order/EnaAntiWindup/EnaAntiWindup'
 * '<S25>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/AngleObserver3Order/EnaAntiWindup/Saturation'
 * '<S26>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/AngleObserver3Order/EnaAntiWindup/Saturation/Parameter'
 * '<S27>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/AngleObserver3Order/EnaAntiWindup/Saturation/Saturation Dynamic'
 * '<S28>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/AngleObserver3Order/IntegratorWithAntiSaturation/Integrator'
 * '<S29>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/AngleObserver3Order/IntegratorWithAntiSaturation/Saturation'
 * '<S30>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/AngleObserver3Order/IntegratorWithAntiSaturation/Saturation/EnaAntiWindup'
 * '<S31>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/AngleObserver3Order/IntegratorWithAntiSaturation/Saturation/Saturation'
 * '<S32>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/AngleObserver3Order/IntegratorWithAntiSaturation/Saturation/Saturation/Parameter'
 * '<S33>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/AngleObserver3Order/IntegratorWithAntiSaturation/Saturation/Saturation/Saturation Dynamic'
 * '<S34>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/AngleObserver3Order/Saturation/Parameter'
 * '<S35>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/AngleObserver/AngleObserver3Order/Saturation/Saturation Dynamic'
 * '<S36>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/Normalization/Local Variable Storage'
 * '<S37>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/Normalization/Local Variable Storage1'
 * '<S38>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/Normalization/Parameter'
 * '<S39>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/Normalization/Parameter1'
 * '<S40>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/Normalization/Parameter2'
 * '<S41>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/Normalization/Parameter3'
 * '<S42>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/ResetIprtCheck/Compare To Zero'
 * '<S43>'  : 'SigResolverAngleDecoder/SGRD_AngleObserver_96us_sys/Subsystem/ResetIprtCheck/Parameter'
 * '<S44>'  : 'SigResolverAngleDecoder/SGRD_CalcElecAngle_100us_sys/AngleWrapZeroToTwoPi'
 * '<S45>'  : 'SigResolverAngleDecoder/SGRD_CalcElecAngle_100us_sys/DeltaTimeCalc'
 * '<S46>'  : 'SigResolverAngleDecoder/SGRD_CalcElecAngle_100us_sys/Function Caller Interface'
 * '<S47>'  : 'SigResolverAngleDecoder/SGRD_CalcElecAngle_100us_sys/Local Variable Storage'
 * '<S48>'  : 'SigResolverAngleDecoder/SGRD_CalcElecAngle_100us_sys/Local Variable Storage1'
 * '<S49>'  : 'SigResolverAngleDecoder/SGRD_CalcElecAngle_100us_sys/Local Variable Storage2'
 * '<S50>'  : 'SigResolverAngleDecoder/SGRD_CalcElecAngle_100us_sys/Local Variable Storage3'
 * '<S51>'  : 'SigResolverAngleDecoder/SGRD_CalcElecAngle_100us_sys/LowPassFilter'
 * '<S52>'  : 'SigResolverAngleDecoder/SGRD_CalcElecAngle_100us_sys/Parameter'
 * '<S53>'  : 'SigResolverAngleDecoder/SGRD_CalcElecAngle_100us_sys/Parameter1'
 * '<S54>'  : 'SigResolverAngleDecoder/SGRD_CalcElecAngle_100us_sys/Parameter2'
 * '<S55>'  : 'SigResolverAngleDecoder/SGRD_CalcElecAngle_100us_sys/Parameter3'
 * '<S56>'  : 'SigResolverAngleDecoder/SGRD_CalcElecAngle_100us_sys/Parameter4'
 * '<S57>'  : 'SigResolverAngleDecoder/SGRD_CalcElecAngle_100us_sys/Function Caller Interface/Local Variable Storage7'
 * '<S58>'  : 'SigResolverAngleDecoder/SGRD_CalcElecAngle_100us_sys/Function Caller Interface/Local Variable Storage8'
 * '<S59>'  : 'SigResolverAngleDecoder/SGRD_CalcElecAngle_100us_sys/Function Caller Interface/Local Variable Storage9'
 * '<S60>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem'
 * '<S61>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag'
 * '<S62>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/EnDiag'
 * '<S63>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/CosLosDiag'
 * '<S64>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/DosDiag'
 * '<S65>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/ErrCodeCalc'
 * '<S66>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/LosDiagEnCheck'
 * '<S67>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/LotDiag'
 * '<S68>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/MuxCosRawBuffer'
 * '<S69>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/MuxSineRawBuffer'
 * '<S70>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/RawAmpCalc'
 * '<S71>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/SineLosDiag'
 * '<S72>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/CosLosDiag/FaultDebounce'
 * '<S73>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/CosLosDiag/Parameter'
 * '<S74>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/CosLosDiag/Parameter2'
 * '<S75>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/CosLosDiag/Parameter3'
 * '<S76>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/CosLosDiag/Parameter4'
 * '<S77>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/CosLosDiag/FaultDebounce/Saturation Dynamic'
 * '<S78>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/CosLosDiag/FaultDebounce/Subsystem'
 * '<S79>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/CosLosDiag/FaultDebounce/UnitDelay'
 * '<S80>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/DosDiag/FaultDebounce'
 * '<S81>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/DosDiag/Parameter'
 * '<S82>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/DosDiag/Parameter2'
 * '<S83>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/DosDiag/Parameter3'
 * '<S84>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/DosDiag/Parameter4'
 * '<S85>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/DosDiag/FaultDebounce/Saturation Dynamic'
 * '<S86>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/DosDiag/FaultDebounce/Subsystem'
 * '<S87>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/DosDiag/FaultDebounce/UnitDelay'
 * '<S88>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/ErrCodeCalc/Local Variable Storage'
 * '<S89>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/LosDiagEnCheck/HysteresisCtrl'
 * '<S90>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/LosDiagEnCheck/Parameter'
 * '<S91>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/LosDiagEnCheck/Parameter1'
 * '<S92>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/LotDiag/FaultDebounce'
 * '<S93>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/LotDiag/Parameter2'
 * '<S94>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/LotDiag/Parameter3'
 * '<S95>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/LotDiag/Parameter4'
 * '<S96>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/LotDiag/Parameter5'
 * '<S97>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/LotDiag/FaultDebounce/Saturation Dynamic'
 * '<S98>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/LotDiag/FaultDebounce/Subsystem'
 * '<S99>'  : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/LotDiag/FaultDebounce/UnitDelay'
 * '<S100>' : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/SineLosDiag/FaultDebounce'
 * '<S101>' : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/SineLosDiag/Parameter'
 * '<S102>' : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/SineLosDiag/Parameter2'
 * '<S103>' : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/SineLosDiag/Parameter3'
 * '<S104>' : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/SineLosDiag/Parameter4'
 * '<S105>' : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/SineLosDiag/FaultDebounce/Saturation Dynamic'
 * '<S106>' : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/SineLosDiag/FaultDebounce/Subsystem'
 * '<S107>' : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/Diag/SineLosDiag/FaultDebounce/UnitDelay'
 * '<S108>' : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/EnDiag/Parameter'
 * '<S109>' : 'SigResolverAngleDecoder/SGRD_DiagResolverFault_1ms_sys/Subsystem/EnDiag/Saturation Dynamic'
 */
#endif                               /* RTW_HEADER_SigResolverAngleDecoder_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

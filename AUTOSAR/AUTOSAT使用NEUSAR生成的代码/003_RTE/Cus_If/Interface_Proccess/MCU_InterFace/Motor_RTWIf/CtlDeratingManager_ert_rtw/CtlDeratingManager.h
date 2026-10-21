/*
 * File: CtlDeratingManager.h
 *
 * Code generated for Simulink model 'CtlDeratingManager'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:43:33 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CtlDeratingManager_h_
#define RTW_HEADER_CtlDeratingManager_h_
#ifndef CtlDeratingManager_COMMON_INCLUDES_
#define CtlDeratingManager_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* CtlDeratingManager_COMMON_INCLUDES_ */

#include "CtlDeratingManager_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
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
  real32_T UnitDelay_DSTATE;           /* '<S22>/Unit Delay' */
  real32_T BareUnitDelay_DSTATE;       /* '<S35>/Bare Unit Delay' */
  uint8_T UnitDelay_DSTATE_p;          /* '<S4>/Unit Delay' */
  boolean_T Memory_PreviousInput;      /* '<S34>/Memory' */
} DW_CtlDeratingManager_T;

/* Real-time Model Data Structure */
struct tag_RTM_CtlDeratingManager_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_CtlDeratingManager_T CtlDeratingManager_DW;

/* Model entry point functions */
extern void CtlDeratingManager_initialize(void);
extern void CtlDeratingManager_terminate(void);

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void CTDM_Derating_1ms(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported data declaration */

/* Volatile memory section */
/* Declaration for custom storage class: Volatile */
extern volatile real32_T CTDM_AxisJunctionTempDerate_C[10];/* Referenced by: '<S40>/Prelookup' */

/* Junction temperature axis breakpoints for torque derate (switch module temperature) */
extern volatile real32_T CTDM_AxisMotorTempDerate_C[10];/* Referenced by: '<S37>/Prelookup' */

/* Motor winding temperature axis breakpoints for torque derate */
extern volatile real32_T CTDM_ScaleJunctionTempDerate_C[10];
                      /* Referenced by: '<S40>/Interpolation Using Prelookup' */

/* Junction temperature derate scale map (1.0=no derate, 0.0=full derate) */
extern volatile real32_T CTDM_ScaleMotorTempDerate_C[10];
                      /* Referenced by: '<S37>/Interpolation Using Prelookup' */

/* Motor temperature derate scale map (1.0=no derate, 0.0=full derate) */
extern volatile real32_T CTDM_ScaleSpeedOverDerate_C[10];
                      /* Referenced by: '<S25>/Interpolation Using Prelookup' */

/* Speed overspeed derate scale map (1.0=no derate, 0.0=full derate) */
extern volatile real32_T CTDM_ScaleVoltDCOverDerate_C[5];
                      /* Referenced by: '<S54>/Interpolation Using Prelookup' */

/* DC bus overvoltage derate scale map (1.0=no derate, 0.0=full derate) */
extern volatile real32_T CTDM_ScaleVoltDCUnderDerate_C[5];
                      /* Referenced by: '<S55>/Interpolation Using Prelookup' */

/* DC bus undervoltage derate scale map (1.0=no derate, 0.0=full derate) */
extern volatile real32_T CTDM_SpeedOverDerate_C[10];/* Referenced by: '<S25>/Prelookup' */

/* Mechanical speed axis breakpoints for overspeed torque derate */
extern volatile real32_T CTDM_TqVoltDerateMotoring_C[50];
                      /* Referenced by: '<S46>/Interpolation Using Prelookup' */

/* Maximum torque capability map for voltage derate in motoring operation */
extern volatile real32_T CTDM_TqVoltDerateSpeed_C[10];/* Referenced by: '<S46>/Prelookup' */

/* Speed axis breakpoints for voltage derate torque capability lookup table */
extern volatile real32_T CTDM_TqVoltDerateVolt_C[5];/* Referenced by: '<S46>/Prelookup1' */

/* Voltage axis breakpoints for voltage derate torque capability lookup table */
extern volatile real32_T CTDM_VoltDCOverDerate_C[5];/* Referenced by: '<S54>/Prelookup' */

/* DC bus overvoltage axis breakpoints for derate scale */
extern volatile real32_T CTDM_VoltDCUnderDerate_C[5];/* Referenced by: '<S55>/Prelookup' */

/* DC bus undervoltage axis breakpoints for derate scale (ascending storage) */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Par */
extern volatile uint8_T CTDM_EnJunctionTempDerate_C;/* Referenced by: '<S39>/Constant' */

/* Enable junction temperature derate: 0=disabled, 1=enabled */
extern volatile uint8_T CTDM_EnMotorTempDerate_C;/* Referenced by: '<S38>/Constant' */

/* Enable motor temperature derate: 0=disabled, 1=enabled */
extern volatile uint8_T CTDM_EnSpeedOverDerate_C;/* Referenced by: '<S24>/Constant' */

/* Enable speed overspeed derate: 0=disabled, 1=enabled */
extern volatile uint8_T CTDM_EnVoltDCOverDerate_C;/* Referenced by: '<S53>/Constant' */

/* Enable DC voltage overvoltage derate: 0=disabled, 1=enabled */
extern volatile uint8_T CTDM_EnVoltDCUnderDerate_C;/* Referenced by: '<S52>/Constant' */

/* Enable DC voltage undervoltage derate: 0=disabled, 1=enabled */
extern volatile real32_T CTDM_ScaleRateDown_C;/* Referenced by: '<S21>/Constant' */

/* Derate scale decreasing rate limit (scale/s). Limit when derating becomes stronger */
extern volatile real32_T CTDM_ScaleRateUp_C;/* Referenced by: '<S20>/Constant' */

/* Derate scale increasing rate limit (scale/s). Limit for recovery towards 1 */
extern volatile real32_T CTDM_StallConfirmTime_C;/* Referenced by: '<S31>/Constant' */

/* Debounce time to confirm stall condition entry */
extern volatile real32_T CTDM_StallCurrentThreshold_C;/* Referenced by: '<S30>/Constant' */

/* Stator current amplitude threshold for stall condition detection */
extern volatile real32_T CTDM_StallDerateFactor_C;/* Referenced by: '<S43>/Constant' */

/* Torque capability reduction factor when stall derate is active */
extern volatile real32_T CTDM_StallExitTime_C;/* Referenced by: '<S32>/Constant' */

/* Debounce time to exit stall condition */
extern volatile real32_T CTDM_StallSpeedThreshold_C;/* Referenced by: '<S29>/Constant' */

/* Speed threshold for stall condition detection */
extern volatile real32_T CTDM_TorqueSpRateLimit_C;/* Referenced by: '<S48>/Constant' */

/* Rate limit for torque setpoint after derating (Nm/s) */
extern volatile real32_T CTDM_TqCapabilityMaxLimit_C;/* Referenced by: '<S45>/Constant' */

/* Upper clipping limit for maximum torque capability */
extern volatile real32_T CTDM_TqCapabilityMinLimit_C;/* Referenced by: '<S44>/Constant' */

/* Lower clipping limit for minimum torque capability */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Sig */
extern uint16_T CTDM_DerateReason;     /* '<S2>/Data Type Conversion5' */

/* Derate reason bitfield summary. See bit mapping in variable definition file */
extern real32_T CTDM_ScaleDerateArb;

/* Arbitrated derate scale before rate limiter (0..1) */
extern real32_T CTDM_ScaleDerateFinal;

/* Final derate scale after rate limiter (0..1) */
extern uint8_T CTDM_StallConditionActive;

/* Active stall condition flag */
extern real32_T CTDM_StatorCurrentAmp;

/* Stator current amplitude calculated from d-q axis currents (Is = sqrt(Id^2 + Iq^2)) */
extern real32_T CTDM_TorqueLimitNeg;   /* '<S2>/Product1' */

/* Final negative torque capability limit after all derates (regen min) */
extern real32_T CTDM_TorqueLimitPos;   /* '<S2>/Product' */

/* Final positive torque capability limit after all derates (motoring max) */
extern real32_T CTDM_TorqueSpLimited;  /* '<S49>/Add1' */

/* Torque setpoint after derating, saturation, and rate limiter */
extern real32_T CTDM_TqVoltDerateMax;

/* Maximum allowed torque based on voltage derate calculation */
extern real32_T CTDM_TqVoltDerateMin;

/* Minimum torque based on voltage derate calculation */
extern real32_T CTDM_TqVoltDerateMotorRaw;

/* Raw output torque from voltage derate maps for motoring operation */
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Real-time Model object */
extern RT_MODEL_CtlDeratingManager_T *const CtlDeratingManager_M;

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
 * '<Root>' : 'CtlDeratingManager'
 * '<S1>'   : 'CtlDeratingManager/CTDM_Derating_1ms_sys'
 * '<S2>'   : 'CtlDeratingManager/CTDM_Derating_1ms_sys/DeratingArbitration'
 * '<S3>'   : 'CtlDeratingManager/CTDM_Derating_1ms_sys/SpeedDerating'
 * '<S4>'   : 'CtlDeratingManager/CTDM_Derating_1ms_sys/StallDerating'
 * '<S5>'   : 'CtlDeratingManager/CTDM_Derating_1ms_sys/ThermalDerating'
 * '<S6>'   : 'CtlDeratingManager/CTDM_Derating_1ms_sys/TorqueCapabilityMap'
 * '<S7>'   : 'CtlDeratingManager/CTDM_Derating_1ms_sys/TorqueCommandLimiter'
 * '<S8>'   : 'CtlDeratingManager/CTDM_Derating_1ms_sys/UdcDerating'
 * '<S9>'   : 'CtlDeratingManager/CTDM_Derating_1ms_sys/DeratingArbitration/Bit Shift'
 * '<S10>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/DeratingArbitration/Bit Shift1'
 * '<S11>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/DeratingArbitration/Bit Shift2'
 * '<S12>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/DeratingArbitration/Bit Shift3'
 * '<S13>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/DeratingArbitration/Local Variable Storage1'
 * '<S14>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/DeratingArbitration/Local Variable Storage3'
 * '<S15>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/DeratingArbitration/Subsystem'
 * '<S16>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/DeratingArbitration/Bit Shift/bit_shift'
 * '<S17>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/DeratingArbitration/Bit Shift1/bit_shift'
 * '<S18>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/DeratingArbitration/Bit Shift2/bit_shift'
 * '<S19>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/DeratingArbitration/Bit Shift3/bit_shift'
 * '<S20>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/DeratingArbitration/Subsystem/Parameter1'
 * '<S21>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/DeratingArbitration/Subsystem/Parameter2'
 * '<S22>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/DeratingArbitration/Subsystem/RateLimiter'
 * '<S23>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/DeratingArbitration/Subsystem/RateLimiter/Saturation Dynamic'
 * '<S24>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/SpeedDerating/Parameter3'
 * '<S25>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/SpeedDerating/SpeedOVDeratLUT'
 * '<S26>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/StallDerating/Debounce'
 * '<S27>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/StallDerating/IAmpCal'
 * '<S28>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/StallDerating/Local Variable Storage3'
 * '<S29>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/StallDerating/Parameter1'
 * '<S30>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/StallDerating/Parameter2'
 * '<S31>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/StallDerating/Parameter3'
 * '<S32>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/StallDerating/Parameter4'
 * '<S33>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/StallDerating/Debounce/Saturation Dynamic'
 * '<S34>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/StallDerating/Debounce/Subsystem'
 * '<S35>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/StallDerating/Debounce/UnitDelay'
 * '<S36>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/StallDerating/IAmpCal/Local Variable Storage3'
 * '<S37>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/ThermalDerating/MotorTempDeratLUT'
 * '<S38>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/ThermalDerating/Parameter1'
 * '<S39>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/ThermalDerating/Parameter3'
 * '<S40>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/ThermalDerating/SwitchTempDeratLUT'
 * '<S41>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/TorqueCapabilityMap/Local Variable Storage1'
 * '<S42>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/TorqueCapabilityMap/Local Variable Storage3'
 * '<S43>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/TorqueCapabilityMap/Parameter1'
 * '<S44>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/TorqueCapabilityMap/Parameter10'
 * '<S45>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/TorqueCapabilityMap/Parameter2'
 * '<S46>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/TorqueCapabilityMap/TorqueCapLUT'
 * '<S47>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/TorqueCapabilityMap/TorqueCapLUT/Local Variable Storage3'
 * '<S48>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/TorqueCommandLimiter/Parameter1'
 * '<S49>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/TorqueCommandLimiter/RateLimiter'
 * '<S50>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/TorqueCommandLimiter/Saturation Dynamic'
 * '<S51>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/TorqueCommandLimiter/RateLimiter/Saturation Dynamic'
 * '<S52>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/UdcDerating/Parameter1'
 * '<S53>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/UdcDerating/Parameter3'
 * '<S54>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/UdcDerating/UdcOVDeratLUT'
 * '<S55>'  : 'CtlDeratingManager/CTDM_Derating_1ms_sys/UdcDerating/UdcUVDeratLUT'
 */
#endif                                 /* RTW_HEADER_CtlDeratingManager_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: CtlTorqueLoopController.h
 *
 * Code generated for Simulink model 'CtlTorqueLoopController'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:39:37 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CtlTorqueLoopController_h_
#define RTW_HEADER_CtlTorqueLoopController_h_
#ifndef CtlTorqueLoopController_COMMON_INCLUDES_
#define CtlTorqueLoopController_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                            /* CtlTorqueLoopController_COMMON_INCLUDES_ */

#include "CtlTorqueLoopController_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
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
  real32_T Delay_DSTATE;               /* '<S26>/Delay' */
  real32_T Delay1_DSTATE;              /* '<S26>/Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<S32>/Unit Delay' */
  real32_T Delay_DSTATE_h;             /* '<S34>/Delay' */
  real32_T Delay1_DSTATE_l;            /* '<S47>/Delay1' */
  real32_T Delay_DSTATE_f;             /* '<S47>/Delay' */
  real32_T Delay_DSTATE_g;             /* '<S12>/Delay' */
  real32_T Delay_DSTATE_p;             /* '<S13>/Delay' */
  uint8_T UnitDelay_DSTATE_a;          /* '<S2>/Unit Delay' */
  uint8_T Delay_DSTATE_b;              /* '<S37>/Delay' */
  uint8_T Delay_DSTATE_p4;             /* '<S46>/Delay' */
  boolean_T Delay_DSTATE_e;            /* '<S41>/Delay' */
  boolean_T icLoad;                    /* '<S26>/Delay' */
  boolean_T icLoad_o;                  /* '<S26>/Delay1' */
  boolean_T icLoad_n;                  /* '<S37>/Delay' */
  boolean_T icLoad_g;                  /* '<S47>/Delay1' */
  boolean_T icLoad_h;                  /* '<S47>/Delay' */
  boolean_T icLoad_i;                  /* '<S46>/Delay' */
  boolean_T icLoad_e;                  /* '<S12>/Delay' */
  boolean_T icLoad_h5;                 /* '<S13>/Delay' */
} DW_CtlTorqueLoopController_T;

/* Real-time Model Data Structure */
struct tag_RTM_CtlTorqueLoopController_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_CtlTorqueLoopController_T CtlTorqueLoopController_DW;

/* Model entry point functions */
extern void CtlTorqueLoopController_initialize(void);
extern void CtlTorqueLoopController_terminate(void);

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void CTLC_CalcIdIqRef_1ms(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported data declaration */

/* Volatile memory section */
/* Declaration for custom storage class: Volatile */
extern volatile real32_T CTLC_IdMapMotor_C[5250];
                      /* Referenced by: '<S19>/Interpolation Using Prelookup' */
extern volatile real32_T CTLC_IqMapMotor_C[5250];
                     /* Referenced by: '<S19>/Interpolation Using Prelookup1' */
extern volatile real32_T CTLC_SpeedAxis_C[35];/* Referenced by: '<S19>/Prelookup' */
extern volatile real32_T CTLC_TorqueAxis_C[50];/* Referenced by: '<S19>/Prelookup1' */
extern volatile real32_T CTLC_VoltageAxis_C[3];/* Referenced by: '<S19>/Prelookup2' */

#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Par */
extern volatile real32_T CTLC_CurrentMax_C;/* Referenced by: '<S52>/Constant' */

/* Maximum peak phase current limit */
extern volatile real32_T CTLC_FluxWknDeactRate_C;/* Referenced by: '<S31>/Constant' */

/* Ramp-down rate limit for flux controller deactivation */
extern volatile uint8_T CTLC_FluxWknEnable_C;/* Referenced by: '<S28>/Constant' */

/* Enable flag for flux weakening controller */
extern volatile real32_T CTLC_FluxWknKi_C;/* Referenced by: '<S29>/Constant' */

/* Integral gain of flux weakening PI controller */
extern volatile real32_T CTLC_FluxWknKp_C;/* Referenced by: '<S27>/Constant' */

/* Proportional gain of flux weakening PI controller */
extern volatile real32_T CTLC_FluxWknVoltHyst_C;/* Referenced by: '<S42>/Constant' */

/* Voltage hysteresis for flux weakening activation */
extern volatile real32_T CTLC_IdDischargeMode_C;/* Referenced by: '<S16>/Constant' */

/* D-axis current setpoint for discharge operation */
extern volatile real32_T CTLC_IdRateLimit_C;/* Referenced by: '<S9>/Constant' */

/* Rate limiter for d-axis current change */
extern volatile real32_T CTLC_IdSetpointCal_C;/* Referenced by: '<S11>/Constant' */

/* D-axis current setpoint for calibration mode */
extern volatile real32_T CTLC_IqRateLimit_C;/* Referenced by: '<S10>/Constant' */

/* Rate limiter for q-axis current change */
extern volatile real32_T CTLC_IqSetpointCal_C;/* Referenced by: '<S8>/Constant' */

/* Q-axis current setpoint for calibration mode */
extern volatile real32_T CTLC_SpeedCorrMax_C;/* Referenced by: '<S39>/Constant' */

/* Maximum speed correction during flux weakening */
extern volatile real32_T CTLC_SpeedCtrlKi_C;/* Referenced by: '<S48>/Constant' */

/* Integral gain of speed PI controller */
extern volatile real32_T CTLC_SpeedCtrlKp_C;/* Referenced by: '<S49>/Constant' */

/* Proportional gain of speed PI controller */
extern volatile real32_T CTLC_SpeedFilterFreq_C;/* Referenced by: '<S35>/Constant' */

/* Filter cutoff frequency for interpolation speed */
extern volatile real32_T CTLC_VoltReserveEarly_C;/* Referenced by: '<S25>/Constant' */

/* Voltage factor for early flux weakening activation */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Sig */
extern real32_T CTLC_IdSpLimited;      /* '<S3>/Merge' */

/* D-axis current reference after limitation for control loop */
extern real32_T CTLC_IqSpLimited;      /* '<S3>/Merge1' */

/* Q-axis current reference after limitation for control loop */
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Real-time Model object */
extern RT_MODEL_CtlTorqueLoopController_T *const CtlTorqueLoopController_M;

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
 * '<Root>' : 'CtlTorqueLoopController'
 * '<S1>'   : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys'
 * '<S2>'   : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute'
 * '<S3>'   : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefLimit'
 * '<S4>'   : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/CurrentModeGen'
 * '<S5>'   : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/Default'
 * '<S6>'   : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/DischargeModeGen'
 * '<S7>'   : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode'
 * '<S8>'   : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/CurrentModeGen/Parameter1'
 * '<S9>'   : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/CurrentModeGen/Parameter2'
 * '<S10>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/CurrentModeGen/Parameter3'
 * '<S11>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/CurrentModeGen/Parameter7'
 * '<S12>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/CurrentModeGen/RateLimiter'
 * '<S13>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/CurrentModeGen/RateLimiter1'
 * '<S14>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/CurrentModeGen/RateLimiter/Saturation Dynamic'
 * '<S15>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/CurrentModeGen/RateLimiter1/Saturation Dynamic'
 * '<S16>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/DischargeModeGen/Parameter2'
 * '<S17>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque'
 * '<S18>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/TorqueRefCalc'
 * '<S19>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/IdIqCmdLookup'
 * '<S20>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup'
 * '<S21>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/CalcUVecMax'
 * '<S22>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/FwCtl'
 * '<S23>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/Limit'
 * '<S24>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/StateFw'
 * '<S25>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/CalcUVecMax/Parameter2'
 * '<S26>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/FwCtl/Fw_PI'
 * '<S27>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/FwCtl/Parameter1'
 * '<S28>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/FwCtl/Parameter2'
 * '<S29>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/FwCtl/Parameter3'
 * '<S30>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/FwCtl/RampDown'
 * '<S31>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/FwCtl/RampDown/Parameter2'
 * '<S32>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/FwCtl/RampDown/RateLimiter'
 * '<S33>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/FwCtl/RampDown/RateLimiter/Saturation Dynamic'
 * '<S34>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/Limit/LowPassFilter'
 * '<S35>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/Limit/Parameter'
 * '<S36>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/Limit/Saturation'
 * '<S37>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/Limit/Saturation/EnaAntiWindup'
 * '<S38>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/Limit/Saturation/Saturation'
 * '<S39>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/Limit/Saturation/Saturation/Parameter'
 * '<S40>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/Limit/Saturation/Saturation/Saturation Dynamic'
 * '<S41>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/StateFw/HysteresisCtrl'
 * '<S42>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/IdIqFromTorque/SpeedCalcForLookup/StateFw/Parameter2'
 * '<S43>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/TorqueRefCalc/DefaultRefCalc'
 * '<S44>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/TorqueRefCalc/SpeedModeRefCalc'
 * '<S45>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/TorqueRefCalc/TorqueModeRefCalc'
 * '<S46>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/TorqueRefCalc/SpeedModeRefCalc/EnAwUp'
 * '<S47>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/TorqueRefCalc/SpeedModeRefCalc/PI_SpeedLoop'
 * '<S48>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/TorqueRefCalc/SpeedModeRefCalc/Parameter1'
 * '<S49>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/TorqueRefCalc/SpeedModeRefCalc/Parameter7'
 * '<S50>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/TorqueRefCalc/SpeedModeRefCalc/TqSaturation'
 * '<S51>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefCompute/SpeedTorqueMode/TorqueRefCalc/SpeedModeRefCalc/TqSaturation/Saturation Dynamic'
 * '<S52>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefLimit/Parameter7'
 * '<S53>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefLimit/no_limitation'
 * '<S54>'  : 'CtlTorqueLoopController/CTLC_CalcIdIqRef_1ms_sys/IdIqRefLimit/proportional_limitation'
 */
#endif                               /* RTW_HEADER_CtlTorqueLoopController_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

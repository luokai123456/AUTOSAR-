/*
 * File: SrvOpenLoopService.h
 *
 * Code generated for Simulink model 'SrvOpenLoopService'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:31:51 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SrvOpenLoopService_h_
#define RTW_HEADER_SrvOpenLoopService_h_
#ifndef SrvOpenLoopService_COMMON_INCLUDES_
#define SrvOpenLoopService_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SrvOpenLoopService_COMMON_INCLUDES_ */

#include "SrvOpenLoopService_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T FocVal_Ualpha;              /* '<S5>/Chart' */
  real32_T FocVal_Ubeta;               /* '<S5>/Chart' */
} B_SrvOpenLoopService_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S11>/Unit Delay' */
  real32_T rad_temp_0;                 /* '<S5>/Chart' */
  real32_T rad_temp_90;                /* '<S5>/Chart' */
  int32_T run_delay_cnt;               /* '<S5>/Chart' */
  uint8_T u8_zero_cal_fail;            /* '<S5>/Chart' */
} DW_SrvOpenLoopService_T;

/* Real-time Model Data Structure */
struct tag_RTM_SrvOpenLoopService_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_SrvOpenLoopService_T SrvOpenLoopService_B;

/* Block states (default storage) */
extern DW_SrvOpenLoopService_T SrvOpenLoopService_DW;

/* Model entry point functions */
extern void SrvOpenLoopService_initialize(void);
extern void SrvOpenLoopService_terminate(void);

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void SVOL_CalcAlphaBetaVolt_100us(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported data declaration */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Par */
extern volatile real32_T SVOL_DirectionVoltAmp_C;/* Referenced by: '<S6>/Constant' */

/* Voltage amplitude for direction control mode */
extern volatile real32_T SVOL_OpenLoopVoltGain_C;/* Referenced by: '<S9>/Constant' */

/* Voltage-to-speed gain for open-loop control (V/rpm) */
extern volatile real32_T SVOL_OpenLoopVoltOffset_C;/* Referenced by: '<S10>/Constant' */

/* Base voltage offset for open-loop control */
extern volatile boolean_T SVOL_ZeroCalStartFlag_C;/* Referenced by: '<S18>/Constant' */
extern volatile real32_T SVOL_ZeroDiff_C;/* Referenced by: '<S17>/Constant' */
extern volatile int32_T SVOL_ZeroRadCalTimeTick_C;/* Referenced by: '<S16>/Constant' */
extern volatile real32_T SVOL_ZeroRadCalVs_C;/* Referenced by: '<S15>/Constant' */

#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Sig */
extern real32_T SVOL_MtrZeroPoint;
extern real32_T SVOL_OpenLoopAlphaVolt;/* '<S1>/Merge' */

/* Alpha-axis voltage setpoint for open-loop control */
extern real32_T SVOL_OpenLoopBetaVolt; /* '<S1>/Merge1' */

/* Beta-axis voltage setpoint for open-loop control */
extern boolean_T SVOL_ZeroCalResult;

#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Real-time Model object */
extern RT_MODEL_SrvOpenLoopService_T *const SrvOpenLoopService_M;

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
 * '<Root>' : 'SrvOpenLoopService'
 * '<S1>'   : 'SrvOpenLoopService/SVOL_CalcAlphaBetaVolt_100us_sys'
 * '<S2>'   : 'SrvOpenLoopService/SVOL_CalcAlphaBetaVolt_100us_sys/DirAmp'
 * '<S3>'   : 'SrvOpenLoopService/SVOL_CalcAlphaBetaVolt_100us_sys/OpenLoop'
 * '<S4>'   : 'SrvOpenLoopService/SVOL_CalcAlphaBetaVolt_100us_sys/Zero'
 * '<S5>'   : 'SrvOpenLoopService/SVOL_CalcAlphaBetaVolt_100us_sys/ZeroCal'
 * '<S6>'   : 'SrvOpenLoopService/SVOL_CalcAlphaBetaVolt_100us_sys/DirAmp/Parameter1'
 * '<S7>'   : 'SrvOpenLoopService/SVOL_CalcAlphaBetaVolt_100us_sys/OpenLoop/AlphaBetaCalc'
 * '<S8>'   : 'SrvOpenLoopService/SVOL_CalcAlphaBetaVolt_100us_sys/OpenLoop/SimThetaCalc'
 * '<S9>'   : 'SrvOpenLoopService/SVOL_CalcAlphaBetaVolt_100us_sys/OpenLoop/AlphaBetaCalc/Parameter1'
 * '<S10>'  : 'SrvOpenLoopService/SVOL_CalcAlphaBetaVolt_100us_sys/OpenLoop/AlphaBetaCalc/Parameter2'
 * '<S11>'  : 'SrvOpenLoopService/SVOL_CalcAlphaBetaVolt_100us_sys/OpenLoop/SimThetaCalc/Subsystem'
 * '<S12>'  : 'SrvOpenLoopService/SVOL_CalcAlphaBetaVolt_100us_sys/ZeroCal/Chart'
 * '<S13>'  : 'SrvOpenLoopService/SVOL_CalcAlphaBetaVolt_100us_sys/ZeroCal/Local Variable Storage1'
 * '<S14>'  : 'SrvOpenLoopService/SVOL_CalcAlphaBetaVolt_100us_sys/ZeroCal/Local Variable Storage2'
 * '<S15>'  : 'SrvOpenLoopService/SVOL_CalcAlphaBetaVolt_100us_sys/ZeroCal/Parameter1'
 * '<S16>'  : 'SrvOpenLoopService/SVOL_CalcAlphaBetaVolt_100us_sys/ZeroCal/Parameter2'
 * '<S17>'  : 'SrvOpenLoopService/SVOL_CalcAlphaBetaVolt_100us_sys/ZeroCal/Parameter3'
 * '<S18>'  : 'SrvOpenLoopService/SVOL_CalcAlphaBetaVolt_100us_sys/ZeroCal/Parameter4'
 * '<S19>'  : 'SrvOpenLoopService/SVOL_CalcAlphaBetaVolt_100us_sys/ZeroCal/Subsystem'
 */
#endif                                 /* RTW_HEADER_SrvOpenLoopService_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

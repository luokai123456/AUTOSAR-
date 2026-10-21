/*
 * File: CtlCurrentRegulator.h
 *
 * Code generated for Simulink model 'CtlCurrentRegulator'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:45:38 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CtlCurrentRegulator_h_
#define RTW_HEADER_CtlCurrentRegulator_h_
#ifndef CtlCurrentRegulator_COMMON_INCLUDES_
#define CtlCurrentRegulator_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                /* CtlCurrentRegulator_COMMON_INCLUDES_ */

#include "CtlCurrentRegulator_types.h"
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
  real32_T Delay_DSTATE;               /* '<S7>/Delay' */
  real32_T Delay1_DSTATE;              /* '<S7>/Delay1' */
  real32_T Delay_DSTATE_c;             /* '<S8>/Delay' */
  real32_T Delay1_DSTATE_j;            /* '<S8>/Delay1' */
  real32_T Delay_DSTATE_h;             /* '<S23>/Delay' */
  uint8_T Delay1_DSTATE_a;             /* '<S4>/Delay1' */
  uint8_T Delay_DSTATE_b;              /* '<S4>/Delay' */
  boolean_T icLoad;                    /* '<S7>/Delay' */
  boolean_T icLoad_d;                  /* '<S7>/Delay1' */
  boolean_T icLoad_f;                  /* '<S4>/Delay1' */
  boolean_T icLoad_g;                  /* '<S8>/Delay' */
  boolean_T icLoad_p;                  /* '<S8>/Delay1' */
  boolean_T icLoad_j;                  /* '<S4>/Delay' */
} DW_CtlCurrentRegulator_T;

/* Real-time Model Data Structure */
struct tag_RTM_CtlCurrentRegulator_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_CtlCurrentRegulator_T CtlCurrentRegulator_DW;

/* Model entry point functions */
extern void CtlCurrentRegulator_initialize(void);
extern void CtlCurrentRegulator_terminate(void);

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void CTCR_RegulateCurrent_100us(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported data declaration */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Par */
extern volatile uint8_T CTCR_DAxisInductDecoupEna_C;/* Referenced by: '<S32>/Constant' */

/* Enable d-axis inductance term for decoupling */
extern volatile real32_T CTCR_DAxisInductance_C;/* Referenced by: '<S35>/Constant' */

/* D-axis inductance nominal value */
extern volatile real32_T CTCR_DAxisKi_C;/* Referenced by: '<S9>/Constant' */

/* D-axis current controller integral gain */
extern volatile real32_T CTCR_DAxisKp_C;/* Referenced by: '<S12>/Constant' */

/* D-axis current controller proportional gain */
extern volatile uint8_T CTCR_DecoupUseSetpointEna_C;/* Referenced by: '<S25>/Constant' */

/* Enable use setpoint current for decoupling calculation */
extern volatile real32_T CTCR_PmFluxLinkage_C;/* Referenced by: '<S30>/Constant' */

/* Permanent magnet flux linkage nominal value */
extern volatile uint8_T CTCR_QAxisFluxDecoupEna_C;/* Referenced by: '<S27>/Constant' */

/* Enable permanent magnet flux term for decoupling */
extern volatile uint8_T CTCR_QAxisInductDecoupEna_C;/* Referenced by: '<S26>/Constant' */

/* Enable q-axis inductance term for decoupling */
extern volatile real32_T CTCR_QAxisInductance_C;/* Referenced by: '<S28>/Constant' */

/* Q-axis inductance nominal value */
extern volatile real32_T CTCR_QAxisKi_C;/* Referenced by: '<S11>/Constant' */

/* Q-axis current controller integral gain */
extern volatile real32_T CTCR_QAxisKp_C;/* Referenced by: '<S10>/Constant' */

/* Q-axis current controller proportional gain */
extern volatile uint8_T CTCR_ResistDecoupEna_C;/* Referenced by:
                                                * '<S31>/Constant'
                                                * '<S34>/Constant'
                                                */

/* Enable resistance term for decoupling */
extern volatile real32_T CTCR_StatorResistance_C;/* Referenced by:
                                                  * '<S29>/Constant'
                                                  * '<S33>/Constant'
                                                  */

/* Stator winding resistance nominal value */
extern volatile real32_T CTCR_VSFilterFreq_C;/* Referenced by: '<S24>/Constant' */

/* Voltage vector magnitude filter frequency */
extern volatile real32_T CTCR_VoltLimitFactor_C;/* Referenced by: '<S16>/Constant' */

/* DC-link voltage limitation factor (typically 1/��3) */
extern volatile real32_T CTCR_VoltVectorMagFilterFreq_C;/* Referenced by: '<S15>/Constant' */

/* Voltage vector magnitude filter frequency */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Sig */
extern real32_T CTCR_CurrentVs;
extern uint8_T CTCR_DAxisAntiWindupEna;

/* D-axis anti-windup enable flag */
extern real32_T CTCR_Ki_Out_Ud;

/* D-axis voltage setpoint output from current controller */
extern real32_T CTCR_Ki_Out_Uq;

/* D-axis voltage setpoint output from current controller */
extern real32_T CTCR_Kp_Out_Ud;

/* D-axis voltage setpoint output from current controller */
extern real32_T CTCR_Kp_Out_Uq;

/* D-axis voltage setpoint output from current controller */
extern real32_T CTCR_LimitVs;
extern real32_T CTCR_Pi_Out_Ud;

/* D-axis voltage setpoint output from current controller */
extern real32_T CTCR_Pi_Out_Uq;

/* D-axis voltage setpoint output from current controller */
extern uint8_T CTCR_QAxisAntiWindupEna;

/* Q-axis anti-windup enable flag */
extern real32_T CTCR_UdSp;             /* '<S17>/Merge' */

/* D-axis voltage setpoint output from current controller */
extern real32_T CTCR_UqSp;             /* '<S17>/Merge1' */

/* Q-axis voltage setpoint output from current controller */
extern real32_T CTCR_Uq_Err;

/* D-axis voltage setpoint output from current controller */
extern real32_T CTCR_VoltVectorMagFiltered;/* '<S14>/Subtract1' */
extern real32_T CTCR_VsLpfVal;

#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Real-time Model object */
extern RT_MODEL_CtlCurrentRegulator_T *const CtlCurrentRegulator_M;

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
 * '<Root>' : 'CtlCurrentRegulator'
 * '<S1>'   : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys'
 * '<S2>'   : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/ VoltageSaturation'
 * '<S3>'   : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/DecoupleFeedforward'
 * '<S4>'   : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/EnAwUp'
 * '<S5>'   : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/Local Variable Storage'
 * '<S6>'   : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/Local Variable Storage1'
 * '<S7>'   : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/PI_DAxis'
 * '<S8>'   : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/PI_QAxis'
 * '<S9>'   : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/Parameter1'
 * '<S10>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/Parameter2'
 * '<S11>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/Parameter3'
 * '<S12>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/Parameter7'
 * '<S13>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/UDecoupled'
 * '<S14>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/ VoltageSaturation/LowPassFilter'
 * '<S15>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/ VoltageSaturation/Parameter1'
 * '<S16>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/ VoltageSaturation/Parameter8'
 * '<S17>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/ VoltageSaturation/Subsystem'
 * '<S18>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/ VoltageSaturation/Subsystem/If Action Subsystem'
 * '<S19>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/ VoltageSaturation/Subsystem/If Action Subsystem1'
 * '<S20>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/ VoltageSaturation/Subsystem/Local Variable Storage'
 * '<S21>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/ VoltageSaturation/Subsystem/Local Variable Storage1'
 * '<S22>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/ VoltageSaturation/Subsystem/Local Variable Storage2'
 * '<S23>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/ VoltageSaturation/Subsystem/LowPassFilter'
 * '<S24>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/ VoltageSaturation/Subsystem/Parameter1'
 * '<S25>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/DecoupleFeedforward/Parameter'
 * '<S26>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/DecoupleFeedforward/Parameter10'
 * '<S27>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/DecoupleFeedforward/Parameter11'
 * '<S28>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/DecoupleFeedforward/Parameter2'
 * '<S29>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/DecoupleFeedforward/Parameter3'
 * '<S30>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/DecoupleFeedforward/Parameter4'
 * '<S31>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/DecoupleFeedforward/Parameter5'
 * '<S32>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/DecoupleFeedforward/Parameter6'
 * '<S33>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/DecoupleFeedforward/Parameter7'
 * '<S34>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/DecoupleFeedforward/Parameter8'
 * '<S35>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/DecoupleFeedforward/Parameter9'
 * '<S36>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/EnAwUp/Local Variable Storage'
 * '<S37>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/EnAwUp/Local Variable Storage1'
 * '<S38>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/PI_DAxis/Local Variable Storage'
 * '<S39>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/PI_DAxis/Local Variable Storage1'
 * '<S40>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/PI_QAxis/Local Variable Storage'
 * '<S41>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/PI_QAxis/Local Variable Storage1'
 * '<S42>'  : 'CtlCurrentRegulator/CTCR_RegulateCurrent_100us_sys/PI_QAxis/Local Variable Storage2'
 */
#endif                                 /* RTW_HEADER_CtlCurrentRegulator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

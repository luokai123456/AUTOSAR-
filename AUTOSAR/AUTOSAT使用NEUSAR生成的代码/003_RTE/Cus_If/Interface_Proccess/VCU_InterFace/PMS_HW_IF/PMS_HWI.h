/*
 * File: PMS_HWI.h
 *
 * Code generated for Simulink model 'PMS_HWI'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Apr 15 19:43:19 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PMS_HWI_h_
#define RTW_HEADER_PMS_HWI_h_
#include <math.h>
#ifndef PMS_HWI_COMMON_INCLUDES_
#define PMS_HWI_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_PMS_HWI.h"
#endif                                 /* PMS_HWI_COMMON_INCLUDES_ */

#include "PMS_HWI_types.h"

/* Macros for accessing real-time model data structure */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern float32 BatteryTemp5Map_R[37];  /* Variable: BatteryTemp5Map_R
                                        * Referenced by: '<S2>/1-D Lookup Table'
                                        */
extern float32 BatteryTemp5Map_T[37];  /* Variable: BatteryTemp5Map_T
                                        * Referenced by: '<S2>/1-D Lookup Table'
                                        */
extern float32 BatteryTemp5_R;         /* Variable: BatteryTemp5_R
                                        * Referenced by: '<S2>/Constant2'
                                        */
extern float32 BatteryTemp6Map_R[37];  /* Variable: BatteryTemp6Map_R
                                        * Referenced by: '<S2>/1-D Lookup Table1'
                                        */
extern float32 BatteryTemp6Map_T[37];  /* Variable: BatteryTemp6Map_T
                                        * Referenced by: '<S2>/1-D Lookup Table1'
                                        */
extern float32 BatteryTemp6_R;         /* Variable: BatteryTemp6_R
                                        * Referenced by: '<S2>/Constant5'
                                        */
extern float32 CoolingTempMap_R[37];   /* Variable: CoolingTempMap_R
                                        * Referenced by: '<S2>/1-D Lookup Table2'
                                        */
extern float32 CoolingTempMap_T[37];   /* Variable: CoolingTempMap_T
                                        * Referenced by: '<S2>/1-D Lookup Table2'
                                        */
extern float32 CoolingTemp_R;          /* Variable: CoolingTemp_R
                                        * Referenced by: '<S2>/Constant8'
                                        */

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Conversion10' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion11' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion12' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion13' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion14' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion9' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'PMS_HWI'
 * '<S1>'   : 'PMS_HWI/PMS_HWI_Init'
 * '<S2>'   : 'PMS_HWI/PMS_HWI_Step_sys'
 * '<S3>'   : 'PMS_HWI/PMS_HWI_Step_sys/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_PMS_HWI_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

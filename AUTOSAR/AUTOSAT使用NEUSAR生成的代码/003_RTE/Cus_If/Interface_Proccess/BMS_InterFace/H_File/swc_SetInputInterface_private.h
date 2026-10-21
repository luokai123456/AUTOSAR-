/*
 * File: swc_SetInputInterface_private.h
 *
 * Code generated for Simulink model 'swc_SetInputInterface'.
 *
 * Model version                  : 1.57
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Apr 24 17:14:54 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_swc_SetInputInterface_private_h_
#define RTW_HEADER_swc_SetInputInterface_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern const float32 rtCP_pooled_adGaT2HJGktJ[206];
extern const float32 rtCP_pooled_hsT6bshhuPkb[206];
extern const float32 rtCP_pooled_rPwzJKkan3Yv[166];
extern const float32 rtCP_pooled_lb891nyyM7x2[166];

#define rtCP_uDLookupTable_tableData   rtCP_pooled_adGaT2HJGktJ  /* Computed Parameter: rtCP_uDLookupTable_tableData
                                                                  * Referenced by: '<S1>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data    rtCP_pooled_hsT6bshhuPkb  /* Computed Parameter: rtCP_uDLookupTable_bp01Data
                                                                  * Referenced by: '<S1>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable1_tableData  rtCP_pooled_rPwzJKkan3Yv  /* Computed Parameter: rtCP_uDLookupTable1_tableData
                                                                  * Referenced by: '<S1>/1-D Lookup Table1'
                                                                  */
#define rtCP_uDLookupTable1_bp01Data   rtCP_pooled_lb891nyyM7x2  /* Computed Parameter: rtCP_uDLookupTable1_bp01Data
                                                                  * Referenced by: '<S1>/1-D Lookup Table1'
                                                                  */
#endif                         /* RTW_HEADER_swc_SetInputInterface_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

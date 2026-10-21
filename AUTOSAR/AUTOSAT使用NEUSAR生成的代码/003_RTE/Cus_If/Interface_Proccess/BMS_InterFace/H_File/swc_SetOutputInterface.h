/*
 * File: swc_SetOutputInterface.h
 *
 * Code generated for Simulink model 'swc_SetOutputInterface'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Apr 25 18:23:10 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_swc_SetOutputInterface_h_
#define RTW_HEADER_swc_SetOutputInterface_h_
#ifndef swc_SetOutputInterface_COMMON_INCLUDES_
#define swc_SetOutputInterface_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_swc_SetOutputInterface.h"
#endif                             /* swc_SetOutputInterface_COMMON_INCLUDES_ */

#include "swc_SetOutputInterface_types.h"

/* Child system includes */
#include "If_DiscreteValueOutput_SetDiscreteValue_private.h"
#include "If_PwmValueOutput_SetPwmValue_private.h"
#include "If_RequestElectcContorCls_RequestElectcContorCls_private.h"
#include "If_SetRtcWakeUp_SetWakeUpTime_private.h"
#include "Ram_Service_ReadStatus_private.h"
#include "Ram_Service_Write_private.h"
#include "rt_defines.h"
#include "IoHwAbs_ADC.h"
#include "Hsd_Release.h"
#include "Lsd_Release.h"
#include "System_Release.h"
#include "EvptCdd_HBridge.h"
#include "NVM_XCU.h"
extern FUNC(Std_ReturnType, NVM_CODE) NvM_GetErrorStatus
(
    NvM_BlockIdType BlockId,
    P2VAR(NvM_RequestResultType, AUTOMATIC, NVM_APPL_DATA) RequestResultPtr
);
/* Macros for accessing real-time model data structure */

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
 * '<Root>' : 'swc_SetOutputInterface'
 * '<S1>'   : 'swc_SetOutputInterface/If_DiscreteValueOutput'
 * '<S2>'   : 'swc_SetOutputInterface/If_PwmValueOutput'
 * '<S3>'   : 'swc_SetOutputInterface/If_RequestElectcContorCls'
 * '<S4>'   : 'swc_SetOutputInterface/If_SetRtcWakeUp'
 * '<S5>'   : 'swc_SetOutputInterface/Ram_Service'
 * '<S6>'   : 'swc_SetOutputInterface/swc_SetOutputInterface_100ms_sys'
 * '<S7>'   : 'swc_SetOutputInterface/swc_SetOutputInterface_10ms_sys'
 * '<S8>'   : 'swc_SetOutputInterface/swc_SetOutputInterface_50ms_sys'
 * '<S9>'   : 'swc_SetOutputInterface/swc_SetOutputInterface_Init'
 * '<S10>'  : 'swc_SetOutputInterface/If_DiscreteValueOutput/If_DiscreteValueOutput_SetDiscreteValue_sys'
 * '<S11>'  : 'swc_SetOutputInterface/If_PwmValueOutput/If_PwmValueOutput_SetPwmValue_sys'
 * '<S12>'  : 'swc_SetOutputInterface/If_RequestElectcContorCls/If_RequestElectcContorCls_RequestElectcContorCls_sys'
 * '<S13>'  : 'swc_SetOutputInterface/If_SetRtcWakeUp/If_SetRtcWakeUp_SetWakeUpTime_sys'
 * '<S14>'  : 'swc_SetOutputInterface/Ram_Service/Ram_Service_ReadStatus_sys'
 * '<S15>'  : 'swc_SetOutputInterface/Ram_Service/Ram_Service_Write_sys'
 */
#endif                                /* RTW_HEADER_swc_SetOutputInterface_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

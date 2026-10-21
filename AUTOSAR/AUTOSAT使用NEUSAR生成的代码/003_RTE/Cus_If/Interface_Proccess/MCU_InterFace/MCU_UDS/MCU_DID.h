/*
 * File: MCU_DID.h
 *
 * Code generated for Simulink model 'MCU_DID'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Aug 10 14:06:22 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MCU_DID_h_
#define RTW_HEADER_MCU_DID_h_
#ifndef MCU_DID_COMMON_INCLUDES_
#define MCU_DID_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_MCU_DID.h"
#endif                                 /* MCU_DID_COMMON_INCLUDES_ */

#include "MCU_DID_types.h"

/* Child system includes */
#include "IPU_IsgInvrT_0x040C_CS_ReadData_private.h"
#include "IPU_DTC_0x0402_CS_ReadData_private.h"
#include "IPU_DischgState_0X04CF_CS_ReadData_private.h"
#include "PMS_DriverDemandTorque_0x0405_CS_ReadData_private.h"
#include "IPU_HVBusCur_0x0409_CS_ReadData_private.h"
#include "IPU_HVBusVolt_500_0x0408_CS_ReadData_private.h"
#include "IPU_IsgMotT_0x040B_CS_ReadData_private.h"
#include "IPU_IsgSpdActSgn_0x0403_CS_ReadData_private.h"
#include "IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData_private.h"
#include "IPU_MotorTemp_0x040D_CS_ReadData_private.h"
#include "IPU_TqAvlIsgMax_0x0406_CS_ReadData_private.h"
#include "IPU_TqAvlIsgMin_0x0407_CS_ReadData_private.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Conversion6' : Eliminate redundant data type conversion
 * Block '<S14>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S17>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S18>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion6' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion1' : Eliminate redundant data type conversion
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
 * '<Root>' : 'MCU_DID'
 * '<S1>'   : 'MCU_DID/IPU_DTC_0x0402_CS_ReadData_sys'
 * '<S2>'   : 'MCU_DID/IPU_DischgState_0X04CF_CS_ReadData_sys'
 * '<S3>'   : 'MCU_DID/IPU_HVBusCur_0x0409_CS_ReadData_sys'
 * '<S4>'   : 'MCU_DID/IPU_HVBusVolt_500_0x0408_CS_ReadData_sys'
 * '<S5>'   : 'MCU_DID/IPU_IsgInvrT_0x040C_CS'
 * '<S6>'   : 'MCU_DID/IPU_IsgMotT_0x040B_CS_ReadData_sys'
 * '<S7>'   : 'MCU_DID/IPU_IsgSpdActSgn_0x0403_CS_ReadData_sys'
 * '<S8>'   : 'MCU_DID/IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData_sys'
 * '<S9>'   : 'MCU_DID/IPU_MotorTemp_0x040D_CS_ReadData_sys'
 * '<S10>'  : 'MCU_DID/IPU_TqAvlIsgMax_0x0406_CS_ReadData_sys'
 * '<S11>'  : 'MCU_DID/IPU_TqAvlIsgMin_0x0407_CS_ReadData_sys'
 * '<S12>'  : 'MCU_DID/MCU_DID_Init'
 * '<S13>'  : 'MCU_DID/PMS_DriverDemandTorque_0x0405_CS_ReadData_sys'
 * '<S14>'  : 'MCU_DID/IPU_HVBusCur_0x0409_CS_ReadData_sys/Subsystem'
 * '<S15>'  : 'MCU_DID/IPU_HVBusVolt_500_0x0408_CS_ReadData_sys/Subsystem'
 * '<S16>'  : 'MCU_DID/IPU_IsgInvrT_0x040C_CS/IPU_IsgInvrT_0x040C_CS_ReadData_sys'
 * '<S17>'  : 'MCU_DID/IPU_IsgSpdActSgn_0x0403_CS_ReadData_sys/Subsystem'
 * '<S18>'  : 'MCU_DID/IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData_sys/Subsystem'
 * '<S19>'  : 'MCU_DID/IPU_TqAvlIsgMax_0x0406_CS_ReadData_sys/Subsystem'
 * '<S20>'  : 'MCU_DID/IPU_TqAvlIsgMin_0x0407_CS_ReadData_sys/Subsystem'
 * '<S21>'  : 'MCU_DID/PMS_DriverDemandTorque_0x0405_CS_ReadData_sys/Subsystem'
 */
#endif                                 /* RTW_HEADER_MCU_DID_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

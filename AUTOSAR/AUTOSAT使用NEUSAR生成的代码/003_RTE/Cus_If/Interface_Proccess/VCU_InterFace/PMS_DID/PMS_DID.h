/*
 * File: PMS_DID.h
 *
 * Code generated for Simulink model 'PMS_DID'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Aug 19 16:55:06 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PMS_DID_h_
#define RTW_HEADER_PMS_DID_h_
#ifndef PMS_DID_COMMON_INCLUDES_
#define PMS_DID_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_PMS_DID.h"
#endif                                 /* PMS_DID_COMMON_INCLUDES_ */

#include "PMS_DID_types.h"

/* Child system includes */
#include "ClearNumOfOdometer_0x0335_CS_ReadData_private.h"
#include "AC_ACCM_ActPower_0x0328_CS_ReadData_private.h"
#include "BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData_private.h"
#include "PMS_Brake1Switch_0x0311_CS_ReadData_private.h"
#include "PMS_Brake2Switch_0x0333_CS_ReadData_private.h"
#include "PMS_CPSREn_0x0313_CS_ReadData_private.h"
#include "PMS_CoolingFanPWMSpd_0x031C_CS_ReadData_private.h"
#include "PMS_DCDCCutOffLV_0x032E_CS_ReadData_private.h"
#include "PMS_DcDcActvdReq_0x032D_CS_ReadData_private.h"
#include "PMS_DriveModeInd_0x0317_CS_ReadData_private.h"
#include "PMS_EDCPPWMCtrl_0x031A_CS_ReadData_private.h"
#include "PMS_EngRecMode_Fb_0x0325_CS_ReadData_private.h"
#include "PMS_FunLockVehActive_0x0318_CS_ReadData_private.h"
#include "BMSH_SelfCheckFault_0x032B_CS_ReadData_private.h"
#include "PMS_HBCPPWMCtrl_0x031B_CS_ReadData_private.h"
#include "PMS_HVIL1Sts_0x0322_CS_ReadData_private.h"
#include "PMS_HVIL2Sts_0x0323_CS_ReadData_private.h"
#include "PMS_IPKTotalOdometer_0x0334_CS_ReadData_private.h"
#include "PMS_IgnONSts_0x0332_CS_ReadData_private.h"
#include "PMS_IsgModReq_0x032F_CS_ReadData_private.h"
#include "PMS_IsgTqReq_0x0314_CS_ReadData_private.h"
#include "PMS_ModeGearDisplaySts_0x0316_CS_ReadData_private.h"
#include "PMS_PTC2Enable_0x031F_CS_ReadData_private.h"
#include "PMS_PTC3Enable_0x0320_CS_ReadData_private.h"
#include "CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData_private.h"
#include "PMS_PTCEnable_0x031E_CS_ReadData_private.h"
#include "PMS_PTResiduePwrInd_0x0315_CS_ReadData_private.h"
#include "PMS_Real_PedalPosition_0x0310_CS_ReadData_private.h"
#include "PMS_SelfCheckSts_0x0321_CS_ReadData_private.h"
#include "PMS_VehicleSpeed_0x0327_CS_ReadData_private.h"
#include "ServiceCheckRule_0x1002_Operation_private.h"
#include "ServiceCheckRule_0x1003_Operation_private.h"
#include "ServiceCheckRule_0x11_Operation_private.h"
#include "ServiceCheckRule_0x14_Operation_private.h"
#include "ServiceCheckRule_0x22_Operation_private.h"
#include "DCDC_SelfChkSts_0x032C_CS_ReadData_private.h"
#include "ServiceCheckRule_0x27_Operation_private.h"
#include "ServiceCheckRule_0x28_Operation_private.h"
#include "ServiceCheckRule_0x2E_Operation_private.h"
#include "ServiceCheckRule_0x31_Operation_private.h"
#include "ServiceCheckRule_0x85_Operation_private.h"
#include "VCU_BMSH_StsModeReq_0x0330_CS_ReadData_private.h"
#include "VCU_Odometerbackup_0x0326_CS_ReadData_private.h"
#include "EHB_EPBStatus_0x0312_CS_ReadData_private.h"
#include "IPU_SelfChkSts_0x032A_CS_ReadData_private.h"
#include "PEPS_PowerMode_0x0319_CS_ReadData_private.h"
#include "PMS_ACCMEnable_0x031D_CS_ReadData_private.h"
#include "PMS_BatteryVol_0x0331_CS_ReadData_private.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S52>/Abs' : Eliminated since data is unsigned
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
 * '<Root>' : 'PMS_DID'
 * '<S1>'   : 'PMS_DID/AC_ACCM_ActPower_0x0328_CS_ReadData_sys'
 * '<S2>'   : 'PMS_DID/BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData_sys'
 * '<S3>'   : 'PMS_DID/BMSH_SelfCheckFault_0x032B_CS_ReadData_sys'
 * '<S4>'   : 'PMS_DID/CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData_sys'
 * '<S5>'   : 'PMS_DID/ClearNumOfOdometer_0x0335_CS'
 * '<S6>'   : 'PMS_DID/DCDC_SelfChkSts_0x032C_CS_ReadData_sys'
 * '<S7>'   : 'PMS_DID/EHB_EPBStatus_0x0312_CS_ReadData_sys'
 * '<S8>'   : 'PMS_DID/IPU_SelfChkSts_0x032A_CS_ReadData_sys'
 * '<S9>'   : 'PMS_DID/PEPS_PowerMode_0x0319_CS_ReadData_sys'
 * '<S10>'  : 'PMS_DID/PMS_ACCMEnable_0x031D_CS_ReadData_sys'
 * '<S11>'  : 'PMS_DID/PMS_BatteryVol_0x0331_CS_ReadData_sys'
 * '<S12>'  : 'PMS_DID/PMS_Brake1Switch_0x0311_CS_ReadData_sys'
 * '<S13>'  : 'PMS_DID/PMS_Brake2Switch_0x0333_CS_ReadData_sys'
 * '<S14>'  : 'PMS_DID/PMS_CPSREn_0x0313_CS_ReadData_sys'
 * '<S15>'  : 'PMS_DID/PMS_CoolingFanPWMSpd_0x031C_CS_ReadData_sys'
 * '<S16>'  : 'PMS_DID/PMS_DCDCCutOffLV_0x032E_CS_ReadData_sys'
 * '<S17>'  : 'PMS_DID/PMS_DID_Init'
 * '<S18>'  : 'PMS_DID/PMS_DcDcActvdReq_0x032D_CS_ReadData_sys'
 * '<S19>'  : 'PMS_DID/PMS_DriveModeInd_0x0317_CS_ReadData_sys'
 * '<S20>'  : 'PMS_DID/PMS_EDCPPWMCtrl_0x031A_CS_ReadData_sys'
 * '<S21>'  : 'PMS_DID/PMS_EngRecMode_Fb_0x0325_CS_ReadData_sys'
 * '<S22>'  : 'PMS_DID/PMS_FunLockVehActive_0x0318_CS_ReadData_sys'
 * '<S23>'  : 'PMS_DID/PMS_HBCPPWMCtrl_0x031B_CS_ReadData_sys'
 * '<S24>'  : 'PMS_DID/PMS_HVIL1Sts_0x0322_CS_ReadData_sys'
 * '<S25>'  : 'PMS_DID/PMS_HVIL2Sts_0x0323_CS_ReadData_sys'
 * '<S26>'  : 'PMS_DID/PMS_IPKTotalOdometer_0x0334_CS_ReadData_sys'
 * '<S27>'  : 'PMS_DID/PMS_IgnONSts_0x0332_CS_ReadData_sys'
 * '<S28>'  : 'PMS_DID/PMS_IsgModReq_0x032F_CS_ReadData_sys'
 * '<S29>'  : 'PMS_DID/PMS_IsgTqReq_0x0314_CS_ReadData_sys'
 * '<S30>'  : 'PMS_DID/PMS_ModeGearDisplaySts_0x0316_CS_ReadData_sys'
 * '<S31>'  : 'PMS_DID/PMS_PTC2Enable_0x031F_CS_ReadData_sys'
 * '<S32>'  : 'PMS_DID/PMS_PTC3Enable_0x0320_CS_ReadData_sys'
 * '<S33>'  : 'PMS_DID/PMS_PTCEnable_0x031E_CS_ReadData_sys'
 * '<S34>'  : 'PMS_DID/PMS_PTResiduePwrInd_0x0315_CS_ReadData_sys'
 * '<S35>'  : 'PMS_DID/PMS_Real_PedalPosition_0x0310_CS_ReadData_sys'
 * '<S36>'  : 'PMS_DID/PMS_SelfCheckSts_0x0321_CS_ReadData_sys'
 * '<S37>'  : 'PMS_DID/PMS_VehicleSpeed_0x0327_CS_ReadData_sys'
 * '<S38>'  : 'PMS_DID/ServiceCheckRule_0x1002_Operation_sys'
 * '<S39>'  : 'PMS_DID/ServiceCheckRule_0x1003_Operation_sys'
 * '<S40>'  : 'PMS_DID/ServiceCheckRule_0x11_Operation_sys'
 * '<S41>'  : 'PMS_DID/ServiceCheckRule_0x14_Operation_sys'
 * '<S42>'  : 'PMS_DID/ServiceCheckRule_0x22_Operation_sys'
 * '<S43>'  : 'PMS_DID/ServiceCheckRule_0x27_Operation_sys'
 * '<S44>'  : 'PMS_DID/ServiceCheckRule_0x28_Operation_sys'
 * '<S45>'  : 'PMS_DID/ServiceCheckRule_0x2E_Operation_sys'
 * '<S46>'  : 'PMS_DID/ServiceCheckRule_0x31_Operation_sys'
 * '<S47>'  : 'PMS_DID/ServiceCheckRule_0x85_Operation_sys'
 * '<S48>'  : 'PMS_DID/VCU_BMSH_StsModeReq_0x0330_CS_ReadData_sys'
 * '<S49>'  : 'PMS_DID/VCU_Odometerbackup_0x0326_CS_ReadData_sys'
 * '<S50>'  : 'PMS_DID/ClearNumOfOdometer_0x0335_CS/ClearNumOfOdometer_0x0335_CS_ReadData_sys'
 * '<S51>'  : 'PMS_DID/ServiceCheckRule_0x1002_Operation_sys/Subsystem'
 * '<S52>'  : 'PMS_DID/ServiceCheckRule_0x1002_Operation_sys/Subsystem1'
 * '<S53>'  : 'PMS_DID/ServiceCheckRule_0x1002_Operation_sys/Subsystem1/Compare To Constant'
 * '<S54>'  : 'PMS_DID/ServiceCheckRule_0x1002_Operation_sys/Subsystem1/Compare To Constant1'
 * '<S55>'  : 'PMS_DID/ServiceCheckRule_0x1002_Operation_sys/Subsystem1/Compare To Constant2'
 * '<S56>'  : 'PMS_DID/ServiceCheckRule_0x1002_Operation_sys/Subsystem1/Compare To Constant3'
 * '<S57>'  : 'PMS_DID/ServiceCheckRule_0x1003_Operation_sys/Subsystem21'
 */
#endif                                 /* RTW_HEADER_PMS_DID_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

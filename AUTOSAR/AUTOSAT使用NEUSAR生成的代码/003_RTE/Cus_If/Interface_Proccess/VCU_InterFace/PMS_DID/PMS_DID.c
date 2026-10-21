/*
 * File: PMS_DID.c
 *
 * Code generated for Simulink model 'PMS_DID'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Aug  5 14:56:21 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

// #define FXS_DIDTestSwitch 1

#include "PMS_DID.h"
#include "PMS_DID_private.h"

/* FXS */
extern uint8 PMS_OdoClrCntNum;
/* FXS */

/* Model step function */
uint8 DID_0x0328_OverVal=0;
Std_ReturnType AC_ACCM_ActPower_0x0328_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0328_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/AC_ACCM_ActPower_0x0328_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S1>/Data' incorporates:
   *  Inport: '<Root>/AC_ACCM_ActPower_AC_ACCM_ActPower'
   */
  (void)Rte_Read_AC_ACCM_ActPower_AC_ACCM_ActPower(Data);

  /* SignalConversion generated from: '<S1>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S1>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/AC_ACCM_ActPower_0x0328_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0329_OverVal=0;
/* Model step function */
Std_ReturnType BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData(UInt8_T OpStatus,
  uint8 *Data, UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0329_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S2>/Data' incorporates:
   *  Inport: '<Root>/BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq'
   */
  (void)Rte_Read_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq(Data);

  /* SignalConversion generated from: '<S2>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S2>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x032B_OverVal=0;
/* Model step function */
Std_ReturnType BMSH_SelfCheckFault_0x032B_CS_ReadData(UInt8_T OpStatus, uint8
  *Data, UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x032B_OverVal;
  #else
  boolean tmpRead;
  UNUSED_PARAMETER(OpStatus);

  /* Inport: '<Root>/BMSH_SelfCheckFault_BMSH_SelfCheckFault' */
  (void)Rte_Read_BMSH_SelfCheckFault_BMSH_SelfCheckFault(&tmpRead);

  /* Outputs for Function Call SubSystem: '<Root>/BMSH_SelfCheckFault_0x032B_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S3>/Data' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion6'
   *  SignalConversion generated from: '<S3>/BMSH_SelfCheckFault_BMSH_SelfCheckFault_read'
   */
  *Data = tmpRead;

  /* SignalConversion generated from: '<S3>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S3>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/BMSH_SelfCheckFault_0x032B_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0324_OverVal=0;
/* Model step function */
Std_ReturnType CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData(UInt8_T OpStatus, uint8 *
  Data, UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0324_OverVal;
  #else
  boolean tmpRead;
  UNUSED_PARAMETER(OpStatus);

  /* Inport: '<Root>/CSM_V2XDchaSwtInvalid_CSM_V2XDchaSwtInvalid' */
  (void)Rte_Read_CSM_V2XDchaSwtInvalid_CSM_V2XDchaSwtInvalid(&tmpRead);

  /* Outputs for Function Call SubSystem: '<Root>/CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S4>/Data' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion6'
   *  SignalConversion generated from: '<S4>/CSM_V2XDchaSwtInvalid_CSM_V2XDchaSwtInvalid_read'
   */
  *Data = tmpRead;

  /* SignalConversion generated from: '<S4>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S4>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0335_OverVal=0;
/* Model step function */
Std_ReturnType ClearNumOfOdometer_0x0335_CS_ReadData(UInt8_T OpStatus, UInt8_T
  *Data, UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0335_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<S5>/ClearNumOfOdometer_0x0335_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S42>/Data' */
  *Data = PMS_OdoClrCntNum;

  /* SignalConversion generated from: '<S42>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S42>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<S5>/ClearNumOfOdometer_0x0335_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x032C_OverVal=0;
/* Model step function */
Std_ReturnType DCDC_SelfChkSts_0x032C_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x032C_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/DCDC_SelfChkSts_0x032C_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S6>/Data' incorporates:
   *  Inport: '<Root>/DCDC_SelfChkSts_DCDC_SelfChkSts'
   */
  (void)Rte_Read_DCDC_SelfChkSts_DCDC_SelfChkSts(Data);

  /* SignalConversion generated from: '<S6>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S6>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/DCDC_SelfChkSts_0x032C_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0312_OverVal=0;
/* Model step function */
Std_ReturnType EHB_EPBStatus_0x0312_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0312_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/EHB_EPBStatus_0x0312_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S7>/Data' incorporates:
   *  Inport: '<Root>/EHB_EPBStatus_EHB_EPBStatus'
   */
  (void)Rte_Read_EHB_EPBStatus_EHB_EPBStatus(Data);

  /* SignalConversion generated from: '<S7>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S7>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/EHB_EPBStatus_0x0312_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x032A_OverVal=0;
/* Model step function */
Std_ReturnType IPU_SelfChkSts_0x032A_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x032A_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/IPU_SelfChkSts_0x032A_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S8>/Data' incorporates:
   *  Inport: '<Root>/IPU_SelfChkSts_IPU_SelfChkSts'
   */
  (void)Rte_Read_IPU_SelfChkSts_IPU_SelfChkSts(Data);

  /* SignalConversion generated from: '<S8>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S8>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/IPU_SelfChkSts_0x032A_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0319_OverVal=0;
/* Model step function */
Std_ReturnType PEPS_PowerMode_0x0319_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0319_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/PEPS_PowerMode_0x0319_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S9>/Data' incorporates:
   *  Inport: '<Root>/PEPS_PowerMode_PEPS_PowerMode'
   */
  (void)Rte_Read_PEPS_PowerMode_PEPS_PowerMode(Data);

  /* SignalConversion generated from: '<S9>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S9>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PEPS_PowerMode_0x0319_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x031D_OverVal=0;
/* Model step function */
Std_ReturnType PMS_ACCMEnable_0x031D_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x031D_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_ACCMEnable_0x031D_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S10>/Data' incorporates:
   *  Inport: '<Root>/PMS_ACCMEnable_PMS_ACCMEnable'
   */
  (void)Rte_Read_PMS_ACCMEnable_PMS_ACCMEnable(Data);

  /* SignalConversion generated from: '<S10>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S10>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_ACCMEnable_0x031D_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0331_OverVal=0;
/* Model step function */
Std_ReturnType PMS_BatteryVol_0x0331_CS_ReadData(UInt8_T OpStatus, uint8 Data[2],
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0331_OverVal;
  #else
  uint8 tmpRead;
  UNUSED_PARAMETER(OpStatus);

  /* Inport: '<Root>/PMS_BatteryVol_PMS_BatteryVol' */
  (void)Rte_Read_PMS_BatteryVol_PMS_BatteryVol(&tmpRead);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_BatteryVol_0x0331_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S11>/Data' incorporates:
   *  ArithShift: '<S43>/Shift Arithmetic1'
   *  ArithShift: '<S43>/Shift Arithmetic2'
   *  DataTypeConversion: '<S43>/Data Type Conversion5'
   *  DataTypeConversion: '<S43>/Data Type Conversion6'
   *  SignalConversion generated from: '<S11>/PMS_BatteryVol_PMS_BatteryVol_read'
   */
  Data[0] = 0U;
  Data[1] = (uint8)((uint32)(tmpRead << 8) >> 8);

  /* SignalConversion generated from: '<S11>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S11>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_BatteryVol_0x0331_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0311_OverVal=0;
/* Model step function */
Std_ReturnType PMS_Brake1Switch_0x0311_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0311_OverVal;
  #else
  boolean tmpRead;
  UNUSED_PARAMETER(OpStatus);

  /* Inport: '<Root>/PMS_Brake1Switch_PMS_Brake1Switch' */
  (void)Rte_Read_PMS_Brake1Switch_PMS_Brake1Switch(&tmpRead);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_Brake1Switch_0x0311_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S12>/Data' incorporates:
   *  DataTypeConversion: '<S12>/Data Type Conversion5'
   *  SignalConversion generated from: '<S12>/PMS_Brake1Switch_PMS_Brake1Switch_read'
   */
  *Data = tmpRead;

  /* SignalConversion generated from: '<S12>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S12>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_Brake1Switch_0x0311_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0333_OverVal=0;
/* Model step function */
Std_ReturnType PMS_Brake2Switch_0x0333_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0333_OverVal;
  #else
  boolean tmpRead;
  UNUSED_PARAMETER(OpStatus);

  /* Inport: '<Root>/PMS_Brake2Switch_PMS_Brake2Switch' */
  (void)Rte_Read_PMS_Brake2Switch_PMS_Brake2Switch(&tmpRead);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_Brake2Switch_0x0333_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S13>/Data' incorporates:
   *  DataTypeConversion: '<S13>/Data Type Conversion6'
   *  SignalConversion generated from: '<S13>/PMS_Brake2Switch_PMS_Brake2Switch_read'
   */
  *Data = tmpRead;

  /* SignalConversion generated from: '<S13>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S13>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_Brake2Switch_0x0333_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0313_OverVal=0;
/* Model step function */
Std_ReturnType PMS_CPSREn_0x0313_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0313_OverVal;
  #else
  boolean tmpRead;
  UNUSED_PARAMETER(OpStatus);

  /* Inport: '<Root>/PMS_CPSREn_PMS_CPSREn' */
  (void)Rte_Read_PMS_CPSREn_PMS_CPSREn(&tmpRead);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_CPSREn_0x0313_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S14>/Data' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion6'
   *  SignalConversion generated from: '<S14>/PMS_CPSREn_PMS_CPSREn_read'
   */
  *Data = tmpRead;

  /* SignalConversion generated from: '<S14>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S14>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_CPSREn_0x0313_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x031C_OverVal=0;
/* Model step function */
Std_ReturnType PMS_CoolingFanPWMSpd_0x031C_CS_ReadData(UInt8_T OpStatus, uint8
  *Data, UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x031C_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_CoolingFanPWMSpd_0x031C_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S15>/Data' incorporates:
   *  Inport: '<Root>/PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd'
   */
  (void)Rte_Read_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd(Data);

  /* SignalConversion generated from: '<S15>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S15>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_CoolingFanPWMSpd_0x031C_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x032E_OverVal=0;
/* Model step function */
Std_ReturnType PMS_DCDCCutOffLV_0x032E_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x032E_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_DCDCCutOffLV_0x032E_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S16>/Data' incorporates:
   *  Inport: '<Root>/PMS_DCDCCutOffLV_PMS_DCDCCutOffLV'
   */
  (void)Rte_Read_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV(Data);

  /* SignalConversion generated from: '<S16>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S16>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_DCDCCutOffLV_0x032E_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x032D_OverVal=0;
/* Model step function */
Std_ReturnType PMS_DcDcActvdReq_0x032D_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x032D_OverVal;
  #else
  boolean tmpRead;
  UNUSED_PARAMETER(OpStatus);

  /* Inport: '<Root>/PMS_DcDcActvdReq_PMS_DcDcActvdReq' */
  (void)Rte_Read_PMS_DcDcActvdReq_PMS_DcDcActvdReq(&tmpRead);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_DcDcActvdReq_0x032D_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S18>/Data' incorporates:
   *  DataTypeConversion: '<S18>/Data Type Conversion6'
   *  SignalConversion generated from: '<S18>/PMS_DcDcActvdReq_PMS_DcDcActvdReq_read'
   */
  *Data = tmpRead;

  /* SignalConversion generated from: '<S18>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S18>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_DcDcActvdReq_0x032D_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0317_OverVal=0;
/* Model step function */
Std_ReturnType PMS_DriveModeInd_0x0317_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0317_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_DriveModeInd_0x0317_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S19>/Data' incorporates:
   *  Inport: '<Root>/PMS_DriveModeInd_PMS_DriveModeInd'
   */
  (void)Rte_Read_PMS_DriveModeInd_PMS_DriveModeInd(Data);

  /* SignalConversion generated from: '<S19>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S19>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_DriveModeInd_0x0317_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x031A_OverVal=0;
/* Model step function */
Std_ReturnType PMS_EDCPPWMCtrl_0x031A_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x031A_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_EDCPPWMCtrl_0x031A_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S20>/Data' incorporates:
   *  Inport: '<Root>/PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl'
   */
  (void)Rte_Read_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl(Data);

  /* SignalConversion generated from: '<S20>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S20>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_EDCPPWMCtrl_0x031A_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0325_OverVal=0;
/* Model step function */
Std_ReturnType PMS_EngRecMode_Fb_0x0325_CS_ReadData(UInt8_T OpStatus, uint8
  *Data, UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0325_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_EngRecMode_Fb_0x0325_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S21>/Data' incorporates:
   *  Inport: '<Root>/PMS_EngRecMode_Fb_PMS_EngRecMode_Fb'
   */
  (void)Rte_Read_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb(Data);

  /* SignalConversion generated from: '<S21>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S21>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_EngRecMode_Fb_0x0325_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0318_OverVal=0;
/* Model step function */
Std_ReturnType PMS_FunLockVehActive_0x0318_CS_ReadData(UInt8_T OpStatus, uint8
  *Data, UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0318_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_FunLockVehActive_0x0318_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S22>/Data' incorporates:
   *  Inport: '<Root>/PMS_FunLockVehActive_PMS_FunLockVehActive'
   */
  (void)Rte_Read_PMS_FunLockVehActive_PMS_FunLockVehActive(Data);

  /* SignalConversion generated from: '<S22>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S22>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_FunLockVehActive_0x0318_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x031B_OverVal=0;
/* Model step function */
Std_ReturnType PMS_HBCPPWMCtrl_0x031B_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x031B_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_HBCPPWMCtrl_0x031B_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S23>/Data' incorporates:
   *  Inport: '<Root>/PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl'
   */
  (void)Rte_Read_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl(Data);

  /* SignalConversion generated from: '<S23>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S23>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_HBCPPWMCtrl_0x031B_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0322_OverVal=0;
/* Model step function */
Std_ReturnType PMS_HVIL1Sts_0x0322_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0322_OverVal;
  #else
  boolean tmpRead;
  UNUSED_PARAMETER(OpStatus);

  /* Inport: '<Root>/PMS_HVIL1Sts_PMS_HVIL1Sts' */
  (void)Rte_Read_PMS_HVIL1Sts_PMS_HVIL1Sts(&tmpRead);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_HVIL1Sts_0x0322_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S24>/Data' incorporates:
   *  DataTypeConversion: '<S24>/Data Type Conversion6'
   *  SignalConversion generated from: '<S24>/PMS_HVIL1Sts_PMS_HVIL1Sts_read'
   */
  *Data = tmpRead;

  /* SignalConversion generated from: '<S24>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S24>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_HVIL1Sts_0x0322_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0323_OverVal=0;
/* Model step function */
Std_ReturnType PMS_HVIL2Sts_0x0323_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0323_OverVal;
  #else
  boolean tmpRead;
  UNUSED_PARAMETER(OpStatus);

  /* Inport: '<Root>/PMS_HVIL2Sts_PMS_HVIL2Sts' */
  (void)Rte_Read_PMS_HVIL2Sts_PMS_HVIL2Sts(&tmpRead);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_HVIL2Sts_0x0323_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S25>/Data' incorporates:
   *  DataTypeConversion: '<S25>/Data Type Conversion6'
   *  SignalConversion generated from: '<S25>/PMS_HVIL2Sts_PMS_HVIL2Sts_read'
   */
  *Data = tmpRead;

  /* SignalConversion generated from: '<S25>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S25>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_HVIL2Sts_0x0323_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0334_OverVal=0;
/* Model step function */
Std_ReturnType PMS_IPKTotalOdometer_0x0334_CS_ReadData(UInt8_T OpStatus, uint8
  Data[3], UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0334_OverVal;
  #else
  sint32 tmp;
  uint32 tmpRead;
  UNUSED_PARAMETER(OpStatus);

  /* Inport: '<Root>/PMS_IPKTotalOdometer_PMS_IPKTotalOdometer' */
  (void)Rte_Read_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer(&tmpRead);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_IPKTotalOdometer_0x0334_CS_ReadData_sys' */
  /* DataTypeConversion: '<S44>/Data Type Conversion5' incorporates:
   *  ArithShift: '<S44>/Shift Arithmetic'
   *  SignalConversion generated from: '<S26>/PMS_IPKTotalOdometer_PMS_IPKTotalOdometer_read'
   */
  tmp = (sint32)(tmpRead >> 16);
  if ((uint32)tmp > 255U) {
    tmp = 255;
  }

  /* SignalConversion generated from: '<S26>/Data' incorporates:
   *  ArithShift: '<S44>/Shift Arithmetic1'
   *  ArithShift: '<S44>/Shift Arithmetic2'
   *  ArithShift: '<S44>/Shift Arithmetic3'
   *  ArithShift: '<S44>/Shift Arithmetic4'
   *  DataTypeConversion: '<S44>/Data Type Conversion5'
   *  SignalConversion generated from: '<S26>/PMS_IPKTotalOdometer_PMS_IPKTotalOdometer_read'
   */
  Data[0] = (uint8)tmp;
  Data[1] = (uint8)((tmpRead << 16) >> 24);
  Data[2] = (uint8)((tmpRead << 24) >> 24);

  /* SignalConversion generated from: '<S26>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S26>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_IPKTotalOdometer_0x0334_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0332_OverVal=0;
/* Model step function */
Std_ReturnType PMS_IgnONSts_0x0332_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0332_OverVal;
  #else
  boolean tmpRead;
  UNUSED_PARAMETER(OpStatus);

  /* Inport: '<Root>/PMS_IgnONSts_PMS_IgnONSts' */
  (void)Rte_Read_PMS_IgnONSts_PMS_IgnONSts(&tmpRead);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_IgnONSts_0x0332_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S27>/Data' incorporates:
   *  DataTypeConversion: '<S27>/Data Type Conversion6'
   *  SignalConversion generated from: '<S27>/PMS_IgnONSts_PMS_IgnONSts_read'
   */
  *Data = tmpRead;

  /* SignalConversion generated from: '<S27>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S27>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_IgnONSts_0x0332_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x032F_OverVal=0;
/* Model step function */
Std_ReturnType PMS_IsgModReq_0x032F_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x032F_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_IsgModReq_0x032F_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S28>/Data' incorporates:
   *  Inport: '<Root>/PMS_IsgModReq_PMS_IsgModReq'
   */
  (void)Rte_Read_PMS_IsgModReq_PMS_IsgModReq(Data);

  /* SignalConversion generated from: '<S28>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S28>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_IsgModReq_0x032F_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0314_OverVal=0;
/* Model step function */
Std_ReturnType PMS_IsgTqReq_0x0314_CS_ReadData(UInt8_T OpStatus, uint8 Data[2],
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0314_OverVal;
  #else
  uint16 tmpRead;
  UNUSED_PARAMETER(OpStatus);

  /* Inport: '<Root>/PMS_IsgTqReq_PMS_IsgTqReq' */
  (void)Rte_Read_PMS_IsgTqReq_PMS_IsgTqReq(&tmpRead);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_IsgTqReq_0x0314_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S29>/Data' incorporates:
   *  ArithShift: '<S45>/Shift Arithmetic'
   *  ArithShift: '<S45>/Shift Arithmetic1'
   *  ArithShift: '<S45>/Shift Arithmetic2'
   *  DataTypeConversion: '<S45>/Data Type Conversion5'
   *  DataTypeConversion: '<S45>/Data Type Conversion6'
   *  SignalConversion generated from: '<S29>/PMS_IsgTqReq_PMS_IsgTqReq_read'
   */
  Data[0] = (uint8)((uint32)tmpRead >> 8);
  Data[1] = (uint8)((uint32)(uint16)(tmpRead << 8) >> 8);

  /* SignalConversion generated from: '<S29>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S29>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_IsgTqReq_0x0314_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0316_OverVal=0;
/* Model step function */
Std_ReturnType PMS_ModeGearDisplaySts_0x0316_CS_ReadData(UInt8_T OpStatus, uint8
  *Data, UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0316_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_ModeGearDisplaySts_0x0316_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S30>/Data' incorporates:
   *  Inport: '<Root>/PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts'
   */
  (void)Rte_Read_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts(Data);

  /* SignalConversion generated from: '<S30>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S30>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_ModeGearDisplaySts_0x0316_CS_ReadData_sys' */
  #endif
}

/* Model step function */
void pms_odometerbackup_0x0326_cs_readdata_1(UInt8_T OpStatus, UInt8_T *Data,
  UInt8_T *ErrorCode, Std_ReturnType *ERR)
{
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_Odometerbackup_0x0326_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S31>/Data' */
  *Data = 0U;

  /* SignalConversion generated from: '<S31>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S31>/ERR' */
  *ERR = 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_Odometerbackup_0x0326_CS_ReadData_sys' */
}

uint8 DID_0x031F_OverVal=0;
/* Model step function */
Std_ReturnType PMS_PTC2Enable_0x031F_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x031F_OverVal;
  #else
  boolean tmpRead;
  UNUSED_PARAMETER(OpStatus);

  /* Inport: '<Root>/PMS_PTC2Enable_PMS_PTC2Enable' */
  (void)Rte_Read_PMS_PTC2Enable_PMS_PTC2Enable(&tmpRead);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_PTC2Enable_0x031F_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S32>/Data' incorporates:
   *  DataTypeConversion: '<S32>/Data Type Conversion6'
   *  SignalConversion generated from: '<S32>/PMS_PTC2Enable_PMS_PTC2Enable_read'
   */
  *Data = tmpRead;

  /* SignalConversion generated from: '<S32>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S32>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_PTC2Enable_0x031F_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0320_OverVal=0;
/* Model step function */
Std_ReturnType PMS_PTC3Enable_0x0320_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0320_OverVal;
  #else
  boolean tmpRead;
  UNUSED_PARAMETER(OpStatus);

  /* Inport: '<Root>/PMS_PTC3Enable_PMS_PTC3Enable' */
  (void)Rte_Read_PMS_PTC3Enable_PMS_PTC3Enable(&tmpRead);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_PTC3Enable_0x0320_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S33>/Data' incorporates:
   *  DataTypeConversion: '<S33>/Data Type Conversion6'
   *  SignalConversion generated from: '<S33>/PMS_PTC3Enable_PMS_PTC3Enable_read'
   */
  *Data = tmpRead;

  /* SignalConversion generated from: '<S33>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S33>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_PTC3Enable_0x0320_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x031E_OverVal=0;
/* Model step function */
Std_ReturnType PMS_PTCEnable_0x031E_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x031E_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_PTCEnable_0x031E_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S34>/Data' incorporates:
   *  Inport: '<Root>/PMS_PTCEnable_PMS_PTCEnable'
   */
  (void)Rte_Read_PMS_PTCEnable_PMS_PTCEnable(Data);

  /* SignalConversion generated from: '<S34>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S34>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_PTCEnable_0x031E_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0315_OverVal=0;
/* Model step function */
Std_ReturnType PMS_PTResiduePwrInd_0x0315_CS_ReadData(UInt8_T OpStatus, uint8
  Data[2], UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0315_OverVal;
  #else
  uint16 tmpRead;
  UNUSED_PARAMETER(OpStatus);

  /* Inport: '<Root>/PMS_PTResiduePwrInd_PMS_PTResiduePwrInd' */
  (void)Rte_Read_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd(&tmpRead);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_PTResiduePwrInd_0x0315_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S35>/Data' incorporates:
   *  ArithShift: '<S46>/Shift Arithmetic'
   *  ArithShift: '<S46>/Shift Arithmetic1'
   *  ArithShift: '<S46>/Shift Arithmetic2'
   *  DataTypeConversion: '<S46>/Data Type Conversion5'
   *  DataTypeConversion: '<S46>/Data Type Conversion6'
   *  SignalConversion generated from: '<S35>/PMS_PTResiduePwrInd_PMS_PTResiduePwrInd_read'
   */
  Data[0] = (uint8)((uint32)tmpRead >> 8);
  Data[1] = (uint8)((uint32)(uint16)(tmpRead << 8) >> 8);

  /* SignalConversion generated from: '<S35>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S35>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_PTResiduePwrInd_0x0315_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0310_OverVal=0;
/* Model step function */
Std_ReturnType PMS_Real_PedalPosition_0x0310_CS_ReadData(UInt8_T OpStatus, uint8
  *Data, UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0310_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_Real_PedalPosition_0x0310_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S36>/Data' incorporates:
   *  Inport: '<Root>/PMS_Real_PedalPosition_PMS_Real_PedalPosition'
   */
  (void)Rte_Read_PMS_Real_PedalPosition_PMS_Real_PedalPosition(Data);

  /* SignalConversion generated from: '<S36>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S36>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_Real_PedalPosition_0x0310_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0321_OverVal=0;
/* Model step function */
Std_ReturnType PMS_SelfCheckSts_0x0321_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0321_OverVal;
  #else
  UNUSED_PARAMETER(OpStatus);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_SelfCheckSts_0x0321_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S37>/Data' incorporates:
   *  Inport: '<Root>/PMS_SelfCheckSts_PMS_SelfCheckSts'


  /* Outputs for Function Call SubSystem: '<Root>/PMS_SelfCheckSts_0x0321_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S37>/Data' incorporates:
   *  Inport: '<Root>/PMS_SelfCheckSts_PMS_SelfCheckSts'
   */
  (void)Rte_Read_PMS_SelfCheckSts_PMS_SelfCheckSts(Data);

  /* SignalConversion generated from: '<S37>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S37>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_SelfCheckSts_0x0321_CS_ReadData_sys' */
  #endif
}

uint8 DID_0x0327_OverVal=0;
/* Model step function */
Std_ReturnType PMS_VehicleSpeed_0x0327_CS_ReadData(UInt8_T OpStatus, uint8 Data[2], UInt8_T *ErrorCode)
{
  #ifdef FXS_DIDTestSwitch
  Data[0]=DID_0x0327_OverVal;
  #else
  uint16 tmpRead;
  UNUSED_PARAMETER(OpStatus);

  /* Inport: '<Root>/PMS_VehicleSpeed_PMS_VehicleSpeed' */
  (void)Rte_Read_PMS_VehicleSpeed_PMS_VehicleSpeed(&tmpRead);

  /* Outputs for Function Call SubSystem: '<Root>/PMS_VehicleSpeed_0x0327_CS_ReadData_sys' */
  /* SignalConversion generated from: '<S38>/Data' incorporates:
   *  ArithShift: '<S47>/Shift Arithmetic'
   *  ArithShift: '<S47>/Shift Arithmetic1'
   *  ArithShift: '<S47>/Shift Arithmetic2'
   *  DataTypeConversion: '<S47>/Data Type Conversion5'
   *  DataTypeConversion: '<S47>/Data Type Conversion6'
   *  SignalConversion generated from: '<S38>/PMS_VehicleSpeed_PMS_VehicleSpeed_read'
   */
  Data[0] = (uint8)((uint32)tmpRead >> 8);
  Data[1] = (uint8)((uint32)(uint16)(tmpRead << 8) >> 8);

  /* SignalConversion generated from: '<S38>/ErrorCode' */
  *ErrorCode = 0U;

  /* SignalConversion generated from: '<S38>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/PMS_VehicleSpeed_0x0327_CS_ReadData_sys' */
  #endif
}

/* Model step function */
// uint8 DID_0x0325_OverVal = 0U;
void pms_eptregencylevind_0x0325_cs_readdata_1(UInt8_T OpStatus, UInt8_T *Data,
  UInt8_T *ErrorCode, Std_ReturnType *ERR)
{
#if 0
    *Data = DID_0x0325_OverVal;
#else
    UNUSED_PARAMETER(OpStatus);

    /* Outputs for Function Call SubSystem: '<Root>/PMS_ePTRegencyLevInd_0x0325_CS_ReadData_sys' */
    /* SignalConversion generated from: '<S39>/Data' */
    *Data = 0U;

    /* SignalConversion generated from: '<S39>/ErrorCode' */
    *ErrorCode = 0U;

    /* SignalConversion generated from: '<S39>/ERR' */
    *ERR = 0U;

    /* End of Outputs for SubSystem: '<Root>/PMS_ePTRegencyLevInd_0x0325_CS_ReadData_sys' */
#endif
}

uint8 DID_0x0330_OverVal = 0U;
/* Model step function */
Std_ReturnType VCU_BMSH_StsModeReq_0x0330_CS_ReadData(UInt8_T OpStatus, uint8
  *Data, UInt8_T *ErrorCode)
{
#ifdef FXS_DIDTestSwitch
    *Data = DID_0x0330_OverVal;
#else
    UNUSED_PARAMETER(OpStatus);

    /* Outputs for Function Call SubSystem: '<Root>/VCU_BMSH_StsModeReq_0x0330_CS_ReadData_sys' */
    /* SignalConversion generated from: '<S40>/Data' incorporates:
     *  Inport: '<Root>/VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq'
     */
    (void)Rte_Read_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq(Data);

    /* SignalConversion generated from: '<S40>/ErrorCode' */
    *ErrorCode = 0U;

    /* SignalConversion generated from: '<S40>/ERR' */
    return 0U;

    /* End of Outputs for SubSystem: '<Root>/VCU_BMSH_StsModeReq_0x0330_CS_ReadData_sys' */
#endif
}

uint8 DID_0x0326_OverVal = 0U;
/* Model step function */
Std_ReturnType VCU_Odometerbackup_0x0326_CS_ReadData(UInt8_T OpStatus, uint8
  Data[2], UInt8_T *ErrorCode)
{
#ifdef FXS_DIDTestSwitch
    Data[0] = DID_0x0326_OverVal;
#else
    uint16 tmpRead;
    UNUSED_PARAMETER(OpStatus);

    /* Inport: '<Root>/VCU_Odometerbackup_VCU_Odometerbackup' */
    (void)Rte_Read_VCU_Odometerbackup_VCU_Odometerbackup(&tmpRead);

    /* Outputs for Function Call SubSystem: '<Root>/VCU_Odometerbackup_0x0326_CS_ReadData_sys' */
    /* SignalConversion generated from: '<S41>/Data' incorporates:
     *  ArithShift: '<S48>/Shift Arithmetic'
     *  ArithShift: '<S48>/Shift Arithmetic1'
     *  ArithShift: '<S48>/Shift Arithmetic2'
     *  DataTypeConversion: '<S48>/Data Type Conversion5'
     *  DataTypeConversion: '<S48>/Data Type Conversion6'
     *  SignalConversion generated from: '<S41>/VCU_Odometerbackup_VCU_Odometerbackup_read'
     */
    Data[0] = (uint8)((uint32)tmpRead >> 8);
    Data[1] = (uint8)((uint32)(uint16)(tmpRead << 8) >> 8);

    /* SignalConversion generated from: '<S41>/ErrorCode' */
    *ErrorCode = 0U;

    /* SignalConversion generated from: '<S41>/ERR' */
    return 0U;

    /* End of Outputs for SubSystem: '<Root>/VCU_Odometerbackup_0x0326_CS_ReadData_sys' */
#endif
}
Std_ReturnType ServiceCheckRule_0x1002_Operation(Std_ReturnType *Cond)
{
  /* local block i/o variables */
  uint16 rtb_TmpLatchAtPMS_VehicleSpeed_;
  uint8 rtb_TmpLatchAtPMS_CurrentGearPo;
  uint8 rtb_TmpLatchAtPMS_VehicleSpeedI;
  boolean rtb_TmpLatchAtEXT_IGN_ON_DI_EXT;
  boolean rtb_TmpLatchAtPMS_CurrentGear_m;
  boolean rtb_TmpLatchAtPMS_ePTReady_PMS_;
  boolean rtb_TmpLatchAtPMS_VehicleSpee_m;

  /* Outputs for Function Call SubSystem: '<Root>/ServiceCheckRule_0x1002_Operation_sys' */
  /* SignalConversion generated from: '<S38>/EXT_IGN_ON_DI_EXT_IGN_ON_DI_read' incorporates:
   *  Inport: '<Root>/EXT_IGN_ON_DI_EXT_IGN_ON_DI'
   */
  (void)Rte_Read_EXT_IGN_ON_DI_EXT_IGN_ON_DI(&rtb_TmpLatchAtEXT_IGN_ON_DI_EXT);

  /* SignalConversion generated from: '<S38>/PMS_CurrentGearPosition_PMS_CurrentGearPosition_read' incorporates:
   *  Inport: '<Root>/PMS_CurrentGearPosition_PMS_CurrentGearPosition'
   */
  (void)Rte_Read_PMS_CurrentGearPosition_PMS_CurrentGearPosition
    (&rtb_TmpLatchAtPMS_CurrentGearPo);

  /* SignalConversion generated from: '<S38>/PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid_read' incorporates:
   *  Inport: '<Root>/PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid'
   */
  (void)Rte_Read_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid
    (&rtb_TmpLatchAtPMS_CurrentGear_m);

  /* SignalConversion generated from: '<S38>/PMS_ePTReady_PMS_ePTReady_read' incorporates:
   *  Inport: '<Root>/PMS_ePTReady_PMS_ePTReady'
   */
  (void)Rte_Read_PMS_ePTReady_PMS_ePTReady(&rtb_TmpLatchAtPMS_ePTReady_PMS_);

  /* SignalConversion generated from: '<S38>/PMS_VehicleSpeed_PMS_VehicleSpeed_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeed_PMS_VehicleSpeed'
   */
  (void)Rte_Read_PMS_VehicleSpeed_PMS_VehicleSpeed
    (&rtb_TmpLatchAtPMS_VehicleSpeed_);

  /* SignalConversion generated from: '<S38>/PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV'
   */
  (void)Rte_Read_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV
    (&rtb_TmpLatchAtPMS_VehicleSpee_m);

  /* SignalConversion generated from: '<S38>/PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS'
   */
  (void)Rte_Read_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS
    (&rtb_TmpLatchAtPMS_VehicleSpeedI);

  /* SignalConversion generated from: '<S38>/Cond1' incorporates:
   *  Constant: '<S55>/Constant'
   *  Constant: '<S56>/Constant'
   *  DataTypeConversion: '<S51>/Data Type Conversion'
   *  Logic: '<S51>/NOT'
   *  Logic: '<S52>/AND'
   *  Logic: '<S52>/OR'
   *  Logic: '<S52>/OR1'
   *  Logic: '<S52>/OR2'
   *  Logic: '<S52>/OR3'
   *  RelationalOperator: '<S53>/Compare'
   *  RelationalOperator: '<S54>/Compare'
   *  RelationalOperator: '<S55>/Compare'
   *  RelationalOperator: '<S56>/Compare'
   */
  *Cond = (Std_ReturnType)((!rtb_TmpLatchAtEXT_IGN_ON_DI_EXT) ||
    rtb_TmpLatchAtPMS_ePTReady_PMS_ || ((rtb_TmpLatchAtPMS_CurrentGearPo != 0) &&
    (rtb_TmpLatchAtPMS_CurrentGearPo != 10) && (!rtb_TmpLatchAtPMS_CurrentGear_m))
    || (((!rtb_TmpLatchAtPMS_VehicleSpee_m) || (rtb_TmpLatchAtPMS_VehicleSpeedI ==
    0)) && (rtb_TmpLatchAtPMS_VehicleSpeed_ >= 3)));

  /* SignalConversion generated from: '<S38>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/ServiceCheckRule_0x1002_Operation_sys' */
}

/* Model step function */
Std_ReturnType ServiceCheckRule_0x1003_Operation(Std_ReturnType *Cond)
{
  /* local block i/o variables */
  boolean rtb_TmpLatchAtEXT_IGN_ON_DI_E_g;

  /* Outputs for Function Call SubSystem: '<Root>/ServiceCheckRule_0x1003_Operation_sys' */
  /* SignalConversion generated from: '<S39>/EXT_IGN_ON_DI_EXT_IGN_ON_DI_read' incorporates:
   *  Inport: '<Root>/EXT_IGN_ON_DI_EXT_IGN_ON_DI'
   */
  (void)Rte_Read_EXT_IGN_ON_DI_EXT_IGN_ON_DI(&rtb_TmpLatchAtEXT_IGN_ON_DI_E_g);

  /* SignalConversion generated from: '<S39>/Cond1' incorporates:
   *  DataTypeConversion: '<S57>/Data Type Conversion'
   *  Logic: '<S57>/NOT'
   */
  *Cond = (Std_ReturnType)!rtb_TmpLatchAtEXT_IGN_ON_DI_E_g;

  /* SignalConversion generated from: '<S39>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<Root>/ServiceCheckRule_0x1003_Operation_sys' */
}

/* Model step function */
Std_ReturnType ServiceCheckRule_0x11_Operation(void)
{
  /* local block i/o variables */
  uint16 rtb_TmpLatchAtPMS_VehicleSpee_b;
  uint8 rtb_TmpLatchAtPMS_CurrentGear_o;
  uint8 rtb_TmpLatchAtPMS_VehicleSpee_l;
  boolean rtb_TmpLatchAtEXT_IGN_ON_DI__gc;
  boolean rtb_TmpLatchAtPMS_CurrentGea_mw;
  boolean rtb_TmpLatchAtPMS_ePTReady_PM_k;
  boolean rtb_TmpLatchAtPMS_VehicleSpe_mm;

  /* Outputs for Function Call SubSystem: '<Root>/ServiceCheckRule_0x11_Operation_sys' */
  /* SignalConversion generated from: '<S40>/EXT_IGN_ON_DI_EXT_IGN_ON_DI_read' incorporates:
   *  Inport: '<Root>/EXT_IGN_ON_DI_EXT_IGN_ON_DI'
   */
  (void)Rte_Read_EXT_IGN_ON_DI_EXT_IGN_ON_DI(&rtb_TmpLatchAtEXT_IGN_ON_DI__gc);

  /* SignalConversion generated from: '<S40>/PMS_CurrentGearPosition_PMS_CurrentGearPosition_read' incorporates:
   *  Inport: '<Root>/PMS_CurrentGearPosition_PMS_CurrentGearPosition'
   */
  (void)Rte_Read_PMS_CurrentGearPosition_PMS_CurrentGearPosition
    (&rtb_TmpLatchAtPMS_CurrentGear_o);

  /* SignalConversion generated from: '<S40>/PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid_read' incorporates:
   *  Inport: '<Root>/PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid'
   */
  (void)Rte_Read_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid
    (&rtb_TmpLatchAtPMS_CurrentGea_mw);

  /* SignalConversion generated from: '<S40>/PMS_ePTReady_PMS_ePTReady_read' incorporates:
   *  Inport: '<Root>/PMS_ePTReady_PMS_ePTReady'
   */
  (void)Rte_Read_PMS_ePTReady_PMS_ePTReady(&rtb_TmpLatchAtPMS_ePTReady_PM_k);

  /* SignalConversion generated from: '<S40>/PMS_VehicleSpeed_PMS_VehicleSpeed_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeed_PMS_VehicleSpeed'
   */
  (void)Rte_Read_PMS_VehicleSpeed_PMS_VehicleSpeed
    (&rtb_TmpLatchAtPMS_VehicleSpee_b);

  /* SignalConversion generated from: '<S40>/PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV'
   */
  (void)Rte_Read_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV
    (&rtb_TmpLatchAtPMS_VehicleSpe_mm);

  /* SignalConversion generated from: '<S40>/PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS'
   */
  (void)Rte_Read_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS
    (&rtb_TmpLatchAtPMS_VehicleSpee_l);

  /* SignalConversion generated from: '<S40>/ERR' incorporates:
   *  Constant: '<S62>/Constant'
   *  Constant: '<S63>/Constant'
   *  DataTypeConversion: '<S58>/Data Type Conversion'
   *  Logic: '<S58>/NOT'
   *  Logic: '<S59>/AND'
   *  Logic: '<S59>/OR'
   *  Logic: '<S59>/OR1'
   *  Logic: '<S59>/OR2'
   *  Logic: '<S59>/OR3'
   *  RelationalOperator: '<S60>/Compare'
   *  RelationalOperator: '<S61>/Compare'
   *  RelationalOperator: '<S62>/Compare'
   *  RelationalOperator: '<S63>/Compare'
   */
  return (Std_ReturnType)((!rtb_TmpLatchAtEXT_IGN_ON_DI__gc) ||
    rtb_TmpLatchAtPMS_ePTReady_PM_k || ((rtb_TmpLatchAtPMS_CurrentGear_o != 0) &&
    (rtb_TmpLatchAtPMS_CurrentGear_o != 10) && (!rtb_TmpLatchAtPMS_CurrentGea_mw))
    || (((!rtb_TmpLatchAtPMS_VehicleSpe_mm) || (rtb_TmpLatchAtPMS_VehicleSpee_l ==
    0)) && (rtb_TmpLatchAtPMS_VehicleSpee_b >= 3)));

  /* End of Outputs for SubSystem: '<Root>/ServiceCheckRule_0x11_Operation_sys' */
}

/* Model step function */
Std_ReturnType ServiceCheckRule_0x14_Operation(void)
{
  /* local block i/o variables */
  uint16 rtb_TmpLatchAtPMS_VehicleSpe_bi;
  uint8 rtb_TmpLatchAtPMS_CurrentGea_or;
  uint8 rtb_TmpLatchAtPMS_VehicleSpe_l5;
  boolean rtb_TmpLatchAtEXT_IGN_ON_DI_gcs;
  boolean rtb_TmpLatchAtPMS_CurrentGe_mwe;
  boolean rtb_TmpLatchAtPMS_ePTReady_P_k2;
  boolean rtb_TmpLatchAtPMS_VehicleSp_mm3;

  /* Outputs for Function Call SubSystem: '<Root>/ServiceCheckRule_0x14_Operation_sys' */
  /* SignalConversion generated from: '<S41>/EXT_IGN_ON_DI_EXT_IGN_ON_DI_read' incorporates:
   *  Inport: '<Root>/EXT_IGN_ON_DI_EXT_IGN_ON_DI'
   */
  (void)Rte_Read_EXT_IGN_ON_DI_EXT_IGN_ON_DI(&rtb_TmpLatchAtEXT_IGN_ON_DI_gcs);

  /* SignalConversion generated from: '<S41>/PMS_CurrentGearPosition_PMS_CurrentGearPosition_read' incorporates:
   *  Inport: '<Root>/PMS_CurrentGearPosition_PMS_CurrentGearPosition'
   */
  (void)Rte_Read_PMS_CurrentGearPosition_PMS_CurrentGearPosition
    (&rtb_TmpLatchAtPMS_CurrentGea_or);

  /* SignalConversion generated from: '<S41>/PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid_read' incorporates:
   *  Inport: '<Root>/PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid'
   */
  (void)Rte_Read_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid
    (&rtb_TmpLatchAtPMS_CurrentGe_mwe);

  /* SignalConversion generated from: '<S41>/PMS_ePTReady_PMS_ePTReady_read' incorporates:
   *  Inport: '<Root>/PMS_ePTReady_PMS_ePTReady'
   */
  (void)Rte_Read_PMS_ePTReady_PMS_ePTReady(&rtb_TmpLatchAtPMS_ePTReady_P_k2);

  /* SignalConversion generated from: '<S41>/PMS_VehicleSpeed_PMS_VehicleSpeed_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeed_PMS_VehicleSpeed'
   */
  (void)Rte_Read_PMS_VehicleSpeed_PMS_VehicleSpeed
    (&rtb_TmpLatchAtPMS_VehicleSpe_bi);

  /* SignalConversion generated from: '<S41>/PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV'
   */
  (void)Rte_Read_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV
    (&rtb_TmpLatchAtPMS_VehicleSp_mm3);

  /* SignalConversion generated from: '<S41>/PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS'
   */
  (void)Rte_Read_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS
    (&rtb_TmpLatchAtPMS_VehicleSpe_l5);

  /* SignalConversion generated from: '<S41>/ERR' incorporates:
   *  Constant: '<S68>/Constant'
   *  Constant: '<S69>/Constant'
   *  DataTypeConversion: '<S64>/Data Type Conversion'
   *  Logic: '<S64>/NOT'
   *  Logic: '<S65>/AND'
   *  Logic: '<S65>/OR'
   *  Logic: '<S65>/OR1'
   *  Logic: '<S65>/OR2'
   *  Logic: '<S65>/OR3'
   *  RelationalOperator: '<S66>/Compare'
   *  RelationalOperator: '<S67>/Compare'
   *  RelationalOperator: '<S68>/Compare'
   *  RelationalOperator: '<S69>/Compare'
   */
  return (Std_ReturnType)((!rtb_TmpLatchAtEXT_IGN_ON_DI_gcs) ||
    rtb_TmpLatchAtPMS_ePTReady_P_k2 || ((rtb_TmpLatchAtPMS_CurrentGea_or != 0) &&
    (rtb_TmpLatchAtPMS_CurrentGea_or != 10) && (!rtb_TmpLatchAtPMS_CurrentGe_mwe))
    || (((!rtb_TmpLatchAtPMS_VehicleSp_mm3) || (rtb_TmpLatchAtPMS_VehicleSpe_l5 ==
    0)) && (rtb_TmpLatchAtPMS_VehicleSpe_bi >= 3)));

  /* End of Outputs for SubSystem: '<Root>/ServiceCheckRule_0x14_Operation_sys' */
}

/* Model step function */
Std_ReturnType ServiceCheckRule_0x22_Operation(void)
{
  /* local block i/o variables */
  boolean rtb_TmpLatchAtEXT_IGN_ON_D_gcsp;

  /* Outputs for Function Call SubSystem: '<Root>/ServiceCheckRule_0x22_Operation_sys' */
  /* SignalConversion generated from: '<S42>/EXT_IGN_ON_DI_EXT_IGN_ON_DI_read' incorporates:
   *  Inport: '<Root>/EXT_IGN_ON_DI_EXT_IGN_ON_DI'
   */
  (void)Rte_Read_EXT_IGN_ON_DI_EXT_IGN_ON_DI(&rtb_TmpLatchAtEXT_IGN_ON_D_gcsp);

  /* SignalConversion generated from: '<S42>/ERR' incorporates:
   *  DataTypeConversion: '<S70>/Data Type Conversion'
   *  Logic: '<S70>/NOT'
   */
  return (Std_ReturnType)!rtb_TmpLatchAtEXT_IGN_ON_D_gcsp;

  /* End of Outputs for SubSystem: '<Root>/ServiceCheckRule_0x22_Operation_sys' */
}

/* Model step function */
Std_ReturnType ServiceCheckRule_0x27_Operation(void)
{
  /* local block i/o variables */
  boolean rtb_TmpLatchAtEXT_IGN_ON__gcspu;

  /* Outputs for Function Call SubSystem: '<Root>/ServiceCheckRule_0x27_Operation_sys' */
  /* SignalConversion generated from: '<S43>/EXT_IGN_ON_DI_EXT_IGN_ON_DI_read' incorporates:
   *  Inport: '<Root>/EXT_IGN_ON_DI_EXT_IGN_ON_DI'
   */
  (void)Rte_Read_EXT_IGN_ON_DI_EXT_IGN_ON_DI(&rtb_TmpLatchAtEXT_IGN_ON__gcspu);

  /* SignalConversion generated from: '<S43>/ERR' incorporates:
   *  DataTypeConversion: '<S71>/Data Type Conversion'
   *  Logic: '<S71>/NOT'
   */
  return (Std_ReturnType)!rtb_TmpLatchAtEXT_IGN_ON__gcspu;

  /* End of Outputs for SubSystem: '<Root>/ServiceCheckRule_0x27_Operation_sys' */
}

/* Model step function */
Std_ReturnType ServiceCheckRule_0x28_Operation(void)
{
  /* local block i/o variables */
  uint16 rtb_TmpLatchAtPMS_VehicleSp_bia;
  uint8 rtb_TmpLatchAtPMS_CurrentGe_orj;
  uint8 rtb_TmpLatchAtPMS_VehicleSp_l5j;
  boolean rtb_TmpLatchAtEXT_IGN_ON_gcspux;
  boolean rtb_TmpLatchAtPMS_CurrentG_mwew;
  boolean rtb_TmpLatchAtPMS_ePTReady__k2x;
  boolean rtb_TmpLatchAtPMS_VehicleS_mm3a;

  /* Outputs for Function Call SubSystem: '<Root>/ServiceCheckRule_0x28_Operation_sys' */
  /* SignalConversion generated from: '<S44>/EXT_IGN_ON_DI_EXT_IGN_ON_DI_read' incorporates:
   *  Inport: '<Root>/EXT_IGN_ON_DI_EXT_IGN_ON_DI'
   */
  (void)Rte_Read_EXT_IGN_ON_DI_EXT_IGN_ON_DI(&rtb_TmpLatchAtEXT_IGN_ON_gcspux);

  /* SignalConversion generated from: '<S44>/PMS_CurrentGearPosition_PMS_CurrentGearPosition_read' incorporates:
   *  Inport: '<Root>/PMS_CurrentGearPosition_PMS_CurrentGearPosition'
   */
  (void)Rte_Read_PMS_CurrentGearPosition_PMS_CurrentGearPosition
    (&rtb_TmpLatchAtPMS_CurrentGe_orj);

  /* SignalConversion generated from: '<S44>/PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid_read' incorporates:
   *  Inport: '<Root>/PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid'
   */
  (void)Rte_Read_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid
    (&rtb_TmpLatchAtPMS_CurrentG_mwew);

  /* SignalConversion generated from: '<S44>/PMS_ePTReady_PMS_ePTReady_read' incorporates:
   *  Inport: '<Root>/PMS_ePTReady_PMS_ePTReady'
   */
  (void)Rte_Read_PMS_ePTReady_PMS_ePTReady(&rtb_TmpLatchAtPMS_ePTReady__k2x);

  /* SignalConversion generated from: '<S44>/PMS_VehicleSpeed_PMS_VehicleSpeed_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeed_PMS_VehicleSpeed'
   */
  (void)Rte_Read_PMS_VehicleSpeed_PMS_VehicleSpeed
    (&rtb_TmpLatchAtPMS_VehicleSp_bia);

  /* SignalConversion generated from: '<S44>/PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV'
   */
  (void)Rte_Read_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV
    (&rtb_TmpLatchAtPMS_VehicleS_mm3a);

  /* SignalConversion generated from: '<S44>/PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS'
   */
  (void)Rte_Read_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS
    (&rtb_TmpLatchAtPMS_VehicleSp_l5j);

  /* SignalConversion generated from: '<S44>/ERR' incorporates:
   *  Constant: '<S76>/Constant'
   *  Constant: '<S77>/Constant'
   *  DataTypeConversion: '<S72>/Data Type Conversion'
   *  Logic: '<S72>/NOT'
   *  Logic: '<S73>/AND'
   *  Logic: '<S73>/OR'
   *  Logic: '<S73>/OR1'
   *  Logic: '<S73>/OR2'
   *  Logic: '<S73>/OR3'
   *  RelationalOperator: '<S74>/Compare'
   *  RelationalOperator: '<S75>/Compare'
   *  RelationalOperator: '<S76>/Compare'
   *  RelationalOperator: '<S77>/Compare'
   */
  return (Std_ReturnType)((!rtb_TmpLatchAtEXT_IGN_ON_gcspux) ||
    rtb_TmpLatchAtPMS_ePTReady__k2x || ((rtb_TmpLatchAtPMS_CurrentGe_orj != 0) &&
    (rtb_TmpLatchAtPMS_CurrentGe_orj != 10) && (!rtb_TmpLatchAtPMS_CurrentG_mwew))
    || (((!rtb_TmpLatchAtPMS_VehicleS_mm3a) || (rtb_TmpLatchAtPMS_VehicleSp_l5j ==
    0)) && (rtb_TmpLatchAtPMS_VehicleSp_bia >= 3)));

  /* End of Outputs for SubSystem: '<Root>/ServiceCheckRule_0x28_Operation_sys' */
}

/* Model step function */
Std_ReturnType ServiceCheckRule_0x2E_Operation(void)
{
  /* local block i/o variables */
  uint16 rtb_TmpLatchAtPMS_VehicleS_bias;
  uint8 rtb_TmpLatchAtPMS_CurrentG_orjd;
  uint8 rtb_TmpLatchAtPMS_VehicleS_l5j3;
  boolean rtb_TmpLatchAtEXT_IGN_O_gcspuxq;
  boolean rtb_TmpLatchAtPMS_Current_mwewp;
  boolean rtb_TmpLatchAtPMS_ePTReady_k2xn;
  boolean rtb_TmpLatchAtPMS_Vehicle_mm3az;

  /* Outputs for Function Call SubSystem: '<Root>/ServiceCheckRule_0x2E_Operation_sys' */
  /* SignalConversion generated from: '<S45>/EXT_IGN_ON_DI_EXT_IGN_ON_DI_read' incorporates:
   *  Inport: '<Root>/EXT_IGN_ON_DI_EXT_IGN_ON_DI'
   */
  (void)Rte_Read_EXT_IGN_ON_DI_EXT_IGN_ON_DI(&rtb_TmpLatchAtEXT_IGN_O_gcspuxq);

  /* SignalConversion generated from: '<S45>/PMS_CurrentGearPosition_PMS_CurrentGearPosition_read' incorporates:
   *  Inport: '<Root>/PMS_CurrentGearPosition_PMS_CurrentGearPosition'
   */
  (void)Rte_Read_PMS_CurrentGearPosition_PMS_CurrentGearPosition
    (&rtb_TmpLatchAtPMS_CurrentG_orjd);

  /* SignalConversion generated from: '<S45>/PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid_read' incorporates:
   *  Inport: '<Root>/PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid'
   */
  (void)Rte_Read_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid
    (&rtb_TmpLatchAtPMS_Current_mwewp);

  /* SignalConversion generated from: '<S45>/PMS_ePTReady_PMS_ePTReady_read' incorporates:
   *  Inport: '<Root>/PMS_ePTReady_PMS_ePTReady'
   */
  (void)Rte_Read_PMS_ePTReady_PMS_ePTReady(&rtb_TmpLatchAtPMS_ePTReady_k2xn);

  /* SignalConversion generated from: '<S45>/PMS_VehicleSpeed_PMS_VehicleSpeed_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeed_PMS_VehicleSpeed'
   */
  (void)Rte_Read_PMS_VehicleSpeed_PMS_VehicleSpeed
    (&rtb_TmpLatchAtPMS_VehicleS_bias);

  /* SignalConversion generated from: '<S45>/PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV'
   */
  (void)Rte_Read_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV
    (&rtb_TmpLatchAtPMS_Vehicle_mm3az);

  /* SignalConversion generated from: '<S45>/PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS'
   */
  (void)Rte_Read_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS
    (&rtb_TmpLatchAtPMS_VehicleS_l5j3);

  /* SignalConversion generated from: '<S45>/ERR' incorporates:
   *  Constant: '<S82>/Constant'
   *  Constant: '<S83>/Constant'
   *  DataTypeConversion: '<S78>/Data Type Conversion'
   *  Logic: '<S78>/NOT'
   *  Logic: '<S79>/AND'
   *  Logic: '<S79>/OR'
   *  Logic: '<S79>/OR1'
   *  Logic: '<S79>/OR2'
   *  Logic: '<S79>/OR3'
   *  RelationalOperator: '<S80>/Compare'
   *  RelationalOperator: '<S81>/Compare'
   *  RelationalOperator: '<S82>/Compare'
   *  RelationalOperator: '<S83>/Compare'
   */
  return (Std_ReturnType)((!rtb_TmpLatchAtEXT_IGN_O_gcspuxq) ||
    rtb_TmpLatchAtPMS_ePTReady_k2xn || ((rtb_TmpLatchAtPMS_CurrentG_orjd != 0) &&
    (rtb_TmpLatchAtPMS_CurrentG_orjd != 10) && (!rtb_TmpLatchAtPMS_Current_mwewp))
    || (((!rtb_TmpLatchAtPMS_Vehicle_mm3az) || (rtb_TmpLatchAtPMS_VehicleS_l5j3 ==
    0)) && (rtb_TmpLatchAtPMS_VehicleS_bias >= 3)));

  /* End of Outputs for SubSystem: '<Root>/ServiceCheckRule_0x2E_Operation_sys' */
}

/* Model step function */
Std_ReturnType ServiceCheckRule_0x31_Operation(void)
{
  /* local block i/o variables */
  uint16 rtb_TmpLatchAtPMS_Vehicle_biasa;
  uint8 rtb_TmpLatchAtPMS_Current_orjd5;
  uint8 rtb_TmpLatchAtPMS_Vehicle_l5j3g;
  boolean rtb_TmpLatchAtEXT_IGN__gcspuxq4;
  boolean rtb_TmpLatchAtPMS_Curren_mwewpr;
  boolean rtb_TmpLatchAtPMS_ePTRead_k2xnx;
  boolean rtb_TmpLatchAtPMS_Vehicl_mm3azd;

  /* Outputs for Function Call SubSystem: '<Root>/ServiceCheckRule_0x31_Operation_sys' */
  /* SignalConversion generated from: '<S46>/EXT_IGN_ON_DI_EXT_IGN_ON_DI_read' incorporates:
   *  Inport: '<Root>/EXT_IGN_ON_DI_EXT_IGN_ON_DI'
   */
  (void)Rte_Read_EXT_IGN_ON_DI_EXT_IGN_ON_DI(&rtb_TmpLatchAtEXT_IGN__gcspuxq4);

  /* SignalConversion generated from: '<S46>/PMS_CurrentGearPosition_PMS_CurrentGearPosition_read' incorporates:
   *  Inport: '<Root>/PMS_CurrentGearPosition_PMS_CurrentGearPosition'
   */
  (void)Rte_Read_PMS_CurrentGearPosition_PMS_CurrentGearPosition
    (&rtb_TmpLatchAtPMS_Current_orjd5);

  /* SignalConversion generated from: '<S46>/PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid_read' incorporates:
   *  Inport: '<Root>/PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid'
   */
  (void)Rte_Read_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid
    (&rtb_TmpLatchAtPMS_Curren_mwewpr);

  /* SignalConversion generated from: '<S46>/PMS_ePTReady_PMS_ePTReady_read' incorporates:
   *  Inport: '<Root>/PMS_ePTReady_PMS_ePTReady'
   */
  (void)Rte_Read_PMS_ePTReady_PMS_ePTReady(&rtb_TmpLatchAtPMS_ePTRead_k2xnx);

  /* SignalConversion generated from: '<S46>/PMS_VehicleSpeed_PMS_VehicleSpeed_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeed_PMS_VehicleSpeed'
   */
  (void)Rte_Read_PMS_VehicleSpeed_PMS_VehicleSpeed
    (&rtb_TmpLatchAtPMS_Vehicle_biasa);

  /* SignalConversion generated from: '<S46>/PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV'
   */
  (void)Rte_Read_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV
    (&rtb_TmpLatchAtPMS_Vehicl_mm3azd);

  /* SignalConversion generated from: '<S46>/PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS'
   */
  (void)Rte_Read_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS
    (&rtb_TmpLatchAtPMS_Vehicle_l5j3g);

  /* SignalConversion generated from: '<S46>/ERR' incorporates:
   *  Constant: '<S88>/Constant'
   *  Constant: '<S89>/Constant'
   *  DataTypeConversion: '<S84>/Data Type Conversion'
   *  Logic: '<S84>/NOT'
   *  Logic: '<S85>/AND'
   *  Logic: '<S85>/OR'
   *  Logic: '<S85>/OR1'
   *  Logic: '<S85>/OR2'
   *  Logic: '<S85>/OR3'
   *  RelationalOperator: '<S86>/Compare'
   *  RelationalOperator: '<S87>/Compare'
   *  RelationalOperator: '<S88>/Compare'
   *  RelationalOperator: '<S89>/Compare'
   */
  return (Std_ReturnType)((!rtb_TmpLatchAtEXT_IGN__gcspuxq4) ||
    rtb_TmpLatchAtPMS_ePTRead_k2xnx || ((rtb_TmpLatchAtPMS_Current_orjd5 != 0) &&
    (rtb_TmpLatchAtPMS_Current_orjd5 != 10) && (!rtb_TmpLatchAtPMS_Curren_mwewpr))
    || (((!rtb_TmpLatchAtPMS_Vehicl_mm3azd) || (rtb_TmpLatchAtPMS_Vehicle_l5j3g ==
    0)) && (rtb_TmpLatchAtPMS_Vehicle_biasa >= 3)));

  /* End of Outputs for SubSystem: '<Root>/ServiceCheckRule_0x31_Operation_sys' */
}

/* Model step function */
Std_ReturnType ServiceCheckRule_0x85_Operation(void)
{
  /* local block i/o variables */
  uint16 rtb_TmpLatchAtPMS_Vehicl_biasar;
  uint8 rtb_TmpLatchAtPMS_Curren_orjd54;
  uint8 rtb_TmpLatchAtPMS_Vehicl_l5j3gg;
  boolean rtb_TmpLatchAtEXT_IGN_gcspuxq4a;
  boolean rtb_TmpLatchAtPMS_Curre_mwewpru;
  boolean rtb_TmpLatchAtPMS_ePTRea_k2xnxe;
  boolean rtb_TmpLatchAtPMS_Vehic_mm3azdf;

  /* Outputs for Function Call SubSystem: '<Root>/ServiceCheckRule_0x85_Operation_sys' */
  /* SignalConversion generated from: '<S47>/EXT_IGN_ON_DI_EXT_IGN_ON_DI_read' incorporates:
   *  Inport: '<Root>/EXT_IGN_ON_DI_EXT_IGN_ON_DI'
   */
  (void)Rte_Read_EXT_IGN_ON_DI_EXT_IGN_ON_DI(&rtb_TmpLatchAtEXT_IGN_gcspuxq4a);

  /* SignalConversion generated from: '<S47>/PMS_CurrentGearPosition_PMS_CurrentGearPosition_read' incorporates:
   *  Inport: '<Root>/PMS_CurrentGearPosition_PMS_CurrentGearPosition'
   */
  (void)Rte_Read_PMS_CurrentGearPosition_PMS_CurrentGearPosition
    (&rtb_TmpLatchAtPMS_Curren_orjd54);

  /* SignalConversion generated from: '<S47>/PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid_read' incorporates:
   *  Inport: '<Root>/PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid'
   */
  (void)Rte_Read_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid
    (&rtb_TmpLatchAtPMS_Curre_mwewpru);

  /* SignalConversion generated from: '<S47>/PMS_ePTReady_PMS_ePTReady_read' incorporates:
   *  Inport: '<Root>/PMS_ePTReady_PMS_ePTReady'
   */
  (void)Rte_Read_PMS_ePTReady_PMS_ePTReady(&rtb_TmpLatchAtPMS_ePTRea_k2xnxe);

  /* SignalConversion generated from: '<S47>/PMS_VehicleSpeed_PMS_VehicleSpeed_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeed_PMS_VehicleSpeed'
   */
  (void)Rte_Read_PMS_VehicleSpeed_PMS_VehicleSpeed
    (&rtb_TmpLatchAtPMS_Vehicl_biasar);

  /* SignalConversion generated from: '<S47>/PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV'
   */
  (void)Rte_Read_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV
    (&rtb_TmpLatchAtPMS_Vehic_mm3azdf);

  /* SignalConversion generated from: '<S47>/PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS_read' incorporates:
   *  Inport: '<Root>/PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS'
   */
  (void)Rte_Read_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS
    (&rtb_TmpLatchAtPMS_Vehicl_l5j3gg);

  /* SignalConversion generated from: '<S47>/ERR' incorporates:
   *  Constant: '<S94>/Constant'
   *  Constant: '<S95>/Constant'
   *  DataTypeConversion: '<S90>/Data Type Conversion'
   *  Logic: '<S90>/NOT'
   *  Logic: '<S91>/AND'
   *  Logic: '<S91>/OR'
   *  Logic: '<S91>/OR1'
   *  Logic: '<S91>/OR2'
   *  Logic: '<S91>/OR3'
   *  RelationalOperator: '<S92>/Compare'
   *  RelationalOperator: '<S93>/Compare'
   *  RelationalOperator: '<S94>/Compare'
   *  RelationalOperator: '<S95>/Compare'
   */
  return (Std_ReturnType)((!rtb_TmpLatchAtEXT_IGN_gcspuxq4a) ||
    rtb_TmpLatchAtPMS_ePTRea_k2xnxe || ((rtb_TmpLatchAtPMS_Curren_orjd54 != 0) &&
    (rtb_TmpLatchAtPMS_Curren_orjd54 != 10) && (!rtb_TmpLatchAtPMS_Curre_mwewpru))
    || (((!rtb_TmpLatchAtPMS_Vehic_mm3azdf) || (rtb_TmpLatchAtPMS_Vehicl_l5j3gg ==
    0)) && (rtb_TmpLatchAtPMS_Vehicl_biasar >= 3)));

  /* End of Outputs for SubSystem: '<Root>/ServiceCheckRule_0x85_Operation_sys' */
}
/* Model initialize function */
void PMS_DID_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
 

 
/*
************************************************************************************************************************
*
* File name: Rte_PMS_DID.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
************************************************************************************************************************
*
* History
*-----------------------------------------------------------------------------------------------------------------------
************************************************************************************************************************
* Version: 3.0
* Author/Date: Gaol/2022.6.14
* Change: New created.
* Cause: New
************************************************************************************************************************
* Version: 4.0
* Author/Date: LanZG/2024.03.18
* Change: Upgrade template.
* Cause: Update
************************************************************************************************************************
*/
#ifndef RTE_PMS_DID_H_
#define RTE_PMS_DID_H_

#include "Rte_PMS_DID_Type.h"
#include "Rte_DataHandleType.h"

#ifndef RTE_CORE                                     
#ifdef RTE_APPLICATION_HEADER_FILE                   
# error Multiple application header files included.  
#endif                                               
#define RTE_APPLICATION_HEADER_FILE                  
#ifndef RTE_PTR2ARRAYBASETYPE_PASSING                
#define RTE_PTR2ARRAYBASETYPE_PASSING                
#endif                                               
#endif                                               
                   
#ifdef __cplusplus
extern "C"         
{                  
#endif            

/*
************************************************************************************************************************
*    Buffers for Mode Management
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Mode_<p>_<m>
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    declaration of application error code
************************************************************************************************************************
*/

#ifndef RTE_E_AC_ACCM_ActPower_0x0328_CS_NOT_OK
#define RTE_E_AC_ACCM_ActPower_0x0328_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_BMSH_CCM_ThermalManageReq_0x0329_CS_NOT_OK
#define RTE_E_BMSH_CCM_ThermalManageReq_0x0329_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_BMSH_SelfCheckFault_0x032B_CS_NOT_OK
#define RTE_E_BMSH_SelfCheckFault_0x032B_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_CSM_V2XDchaSwtInvalid_0x0324_CS_NOT_OK
#define RTE_E_CSM_V2XDchaSwtInvalid_0x0324_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_ClearNumOfOdometer_0x0335_CS_NOT_OK
#define RTE_E_ClearNumOfOdometer_0x0335_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_DCDC_SelfChkSts_0x032C_CS_NOT_OK
#define RTE_E_DCDC_SelfChkSts_0x032C_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_EHB_EPBStatus_0x0312_CS_NOT_OK
#define RTE_E_EHB_EPBStatus_0x0312_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_IPU_SelfChkSts_0x032A_CS_NOT_OK
#define RTE_E_IPU_SelfChkSts_0x032A_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PEPS_PowerMode_0x0319_CS_NOT_OK
#define RTE_E_PEPS_PowerMode_0x0319_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_ACCMEnable_0x031D_CS_NOT_OK
#define RTE_E_PMS_ACCMEnable_0x031D_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_BatteryVol_0x0331_CS_NOT_OK
#define RTE_E_PMS_BatteryVol_0x0331_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_Brake1Switch_0x0311_CS_NOT_OK
#define RTE_E_PMS_Brake1Switch_0x0311_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_Brake2Switch_0x0333_CS_NOT_OK
#define RTE_E_PMS_Brake2Switch_0x0333_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_CPSREn_0x0313_CS_NOT_OK
#define RTE_E_PMS_CPSREn_0x0313_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_CoolingFanPWMSpd_0x031C_CS_NOT_OK
#define RTE_E_PMS_CoolingFanPWMSpd_0x031C_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_DCDCCutOffLV_0x032E_CS_NOT_OK
#define RTE_E_PMS_DCDCCutOffLV_0x032E_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_DcDcActvdReq_0x032D_CS_NOT_OK
#define RTE_E_PMS_DcDcActvdReq_0x032D_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_DriveModeInd_0x0317_CS_NOT_OK
#define RTE_E_PMS_DriveModeInd_0x0317_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_EDCPPWMCtrl_0x031A_CS_NOT_OK
#define RTE_E_PMS_EDCPPWMCtrl_0x031A_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_EngRecMode_Fb_0x0325_CS_NOT_OK
#define RTE_E_PMS_EngRecMode_Fb_0x0325_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_FunLockVehActive_0x0318_CS_NOT_OK
#define RTE_E_PMS_FunLockVehActive_0x0318_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_HBCPPWMCtrl_0x031B_CS_NOT_OK
#define RTE_E_PMS_HBCPPWMCtrl_0x031B_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_HVIL1Sts_0x0322_CS_NOT_OK
#define RTE_E_PMS_HVIL1Sts_0x0322_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_HVIL2Sts_0x0323_CS_NOT_OK
#define RTE_E_PMS_HVIL2Sts_0x0323_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_IPKTotalOdometer_0x0334_CS_NOT_OK
#define RTE_E_PMS_IPKTotalOdometer_0x0334_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_IgnONSts_0x0332_CS_NOT_OK
#define RTE_E_PMS_IgnONSts_0x0332_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_IsgModReq_0x032F_CS_NOT_OK
#define RTE_E_PMS_IsgModReq_0x032F_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_IsgTqReq_0x0314_CS_NOT_OK
#define RTE_E_PMS_IsgTqReq_0x0314_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_ModeGearDisplaySts_0x0316_CS_NOT_OK
#define RTE_E_PMS_ModeGearDisplaySts_0x0316_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_PTC2Enable_0x031F_CS_NOT_OK
#define RTE_E_PMS_PTC2Enable_0x031F_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_PTC3Enable_0x0320_CS_NOT_OK
#define RTE_E_PMS_PTC3Enable_0x0320_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_PTCEnable_0x031E_CS_NOT_OK
#define RTE_E_PMS_PTCEnable_0x031E_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_PTResiduePwrInd_0x0315_CS_NOT_OK
#define RTE_E_PMS_PTResiduePwrInd_0x0315_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_Real_PedalPosition_0x0310_CS_NOT_OK
#define RTE_E_PMS_Real_PedalPosition_0x0310_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_SelfCheckSts_0x0321_CS_NOT_OK
#define RTE_E_PMS_SelfCheckSts_0x0321_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_VehicleSpeed_0x0327_CS_NOT_OK
#define RTE_E_PMS_VehicleSpeed_0x0327_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x1002_E_NOT_OK
#define RTE_E_ServiceCheckRule_0x1002_E_NOT_OK (1U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x1002_E_OK
#define RTE_E_ServiceCheckRule_0x1002_E_OK (0U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x1003_E_NOT_OK
#define RTE_E_ServiceCheckRule_0x1003_E_NOT_OK (1U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x1003_E_OK
#define RTE_E_ServiceCheckRule_0x1003_E_OK (0U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x11_E_NOT_OK
#define RTE_E_ServiceCheckRule_0x11_E_NOT_OK (1U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x11_E_OK
#define RTE_E_ServiceCheckRule_0x11_E_OK (0U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x14_E_NOT_OK
#define RTE_E_ServiceCheckRule_0x14_E_NOT_OK (1U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x14_E_OK
#define RTE_E_ServiceCheckRule_0x14_E_OK (0U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x22_E_NOT_OK
#define RTE_E_ServiceCheckRule_0x22_E_NOT_OK (1U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x22_E_OK
#define RTE_E_ServiceCheckRule_0x22_E_OK (0U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x27_E_NOT_OK
#define RTE_E_ServiceCheckRule_0x27_E_NOT_OK (1U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x27_E_OK
#define RTE_E_ServiceCheckRule_0x27_E_OK (0U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x28_E_NOT_OK
#define RTE_E_ServiceCheckRule_0x28_E_NOT_OK (1U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x28_E_OK
#define RTE_E_ServiceCheckRule_0x28_E_OK (0U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x2E_E_NOT_OK
#define RTE_E_ServiceCheckRule_0x2E_E_NOT_OK (1U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x2E_E_OK
#define RTE_E_ServiceCheckRule_0x2E_E_OK (0U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x31_E_NOT_OK
#define RTE_E_ServiceCheckRule_0x31_E_NOT_OK (1U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x31_E_OK
#define RTE_E_ServiceCheckRule_0x31_E_OK (0U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x85_E_NOT_OK
#define RTE_E_ServiceCheckRule_0x85_E_NOT_OK (1U)
#endif

#ifndef RTE_E_ServiceCheckRule_0x85_E_OK
#define RTE_E_ServiceCheckRule_0x85_E_OK (0U)
#endif

#ifndef RTE_E_VCU_BMSH_StsModeReq_0x0330_CS_NOT_OK
#define RTE_E_VCU_BMSH_StsModeReq_0x0330_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_VCU_Odometerbackup_0x0326_CS_NOT_OK
#define RTE_E_VCU_Odometerbackup_0x0326_CS_NOT_OK (1U)
#endif


/*
************************************************************************************************************************
*    extern declaration of RTE buffers
************************************************************************************************************************
*/

#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_IGN_ON_DI_EXT_IGN_ON_DI;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Brake1Switch_PMS_Brake1Switch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Brake2Switch_PMS_Brake2Switch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_ACCM_ActPower_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_V2XDchaSwtInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_SelfChkSts_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_EPBStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_PEPS_PowerMode_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ACCMEnable_PMS_ACCMEnable;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BatteryVol_PMS_BatteryVol;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CPSREn_PMS_CPSREn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CurrentGearPosition_PMS_CurrentGearPosition;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DcDcActvdReq_PMS_DcDcActvdReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriveModeInd_PMS_DriveModeInd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FunLockVehActive_PMS_FunLockVehActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVIL1Sts_PMS_HVIL1Sts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVIL2Sts_PMS_HVIL2Sts;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IgnONSts_PMS_IgnONSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IsgModReq_PMS_IsgModReq;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IsgTqReq_PMS_IsgTqReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC2Enable_PMS_PTC2Enable;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC3Enable_PMS_PTC3Enable;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTCEnable_PMS_PTCEnable;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Real_PedalPosition_PMS_Real_PedalPosition;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SelfCheckSts_PMS_SelfCheckSts;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSpeed_PMS_VehicleSpeed;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTReady_PMS_ePTReady;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_VCU_Odometerbackup_VCU_Odometerbackup;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_SelfCheckFault_BMSH_SelfCheckFault;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_SelfChkSts_IPU_SelfChkSts;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Buffers for inter-runnable variables
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    RTE Helper-Functions prototypes
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    API prototypes
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_BMSH_SelfCheckFault_BMSH_SelfCheckFault(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_EXT_IGN_ON_DI_EXT_IGN_ON_DI(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_IPU_SelfChkSts_IPU_SelfChkSts(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_ACCMEnable_PMS_ACCMEnable(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_BatteryVol_PMS_BatteryVol(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_Brake1Switch_PMS_Brake1Switch(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_Brake2Switch_PMS_Brake2Switch(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_CPSREn_PMS_CPSREn(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_CurrentGearPosition_PMS_CurrentGearPosition(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_DcDcActvdReq_PMS_DcDcActvdReq(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_DriveModeInd_PMS_DriveModeInd(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_FunLockVehActive_PMS_FunLockVehActive(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_HVIL1Sts_PMS_HVIL1Sts(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_HVIL2Sts_PMS_HVIL2Sts(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer(P2VAR(UInt32, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_IgnONSts_PMS_IgnONSts(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_IsgModReq_PMS_IsgModReq(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_IsgTqReq_PMS_IsgTqReq(P2VAR(UInt16, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_PTC2Enable_PMS_PTC2Enable(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_PTC3Enable_PMS_PTC3Enable(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_PTCEnable_PMS_PTCEnable(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd(P2VAR(UInt16, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_Real_PedalPosition_PMS_Real_PedalPosition(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_SelfCheckSts_PMS_SelfCheckSts(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_VehicleSpeed_PMS_VehicleSpeed(P2VAR(UInt16, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_ePTReady_PMS_ePTReady(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_VCU_Odometerbackup_VCU_Odometerbackup(P2VAR(UInt16, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_AC_ACCM_ActPower_AC_ACCM_ActPower(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_CSM_V2XDchaSwtInvalid_CSM_V2XDchaSwtInvalid(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_DCDC_SelfChkSts_DCDC_SelfChkSts(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_EHB_EPBStatus_EHB_EPBStatus(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PEPS_PowerMode_PEPS_PowerMode(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Rte_Switch_<p>_<m>
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Invalidate_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_IRead_<r>_<p>_<d>
*    Rte_IStatus_<r>_<p>_<d>
*    Rte_IWrite_<r>_<p>_<d>
*    Rte_IWriteRef_<r>_<p>_<d>
*    Rte_IInvalidate_<r>_<p>_<d>
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_Receive_<p>_<d> (explicit S/R communication with isQueued = true)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_Send_<p>_<d> (explicit S/R communication with isQueued = true)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Trigger_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*    Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
#ifndef RTE_CORE
#define Rte_Read_AC_ACCM_ActPower_AC_ACCM_ActPower Rte_Read_PMS_DID_AC_ACCM_ActPower_AC_ACCM_ActPower
#define Rte_Read_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq Rte_Read_PMS_DID_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq
#define Rte_Read_BMSH_SelfCheckFault_BMSH_SelfCheckFault Rte_Read_PMS_DID_BMSH_SelfCheckFault_BMSH_SelfCheckFault
#define Rte_Read_CSM_V2XDchaSwtInvalid_CSM_V2XDchaSwtInvalid Rte_Read_PMS_DID_CSM_V2XDchaSwtInvalid_CSM_V2XDchaSwtInvalid
#define Rte_Read_DCDC_SelfChkSts_DCDC_SelfChkSts Rte_Read_PMS_DID_DCDC_SelfChkSts_DCDC_SelfChkSts
#define Rte_Read_EHB_EPBStatus_EHB_EPBStatus Rte_Read_PMS_DID_EHB_EPBStatus_EHB_EPBStatus
#define Rte_Read_EXT_IGN_ON_DI_EXT_IGN_ON_DI Rte_Read_PMS_DID_EXT_IGN_ON_DI_EXT_IGN_ON_DI
#define Rte_Read_IPU_SelfChkSts_IPU_SelfChkSts Rte_Read_PMS_DID_IPU_SelfChkSts_IPU_SelfChkSts
#define Rte_Read_PEPS_PowerMode_PEPS_PowerMode Rte_Read_PMS_DID_PEPS_PowerMode_PEPS_PowerMode
#define Rte_Read_PMS_ACCMEnable_PMS_ACCMEnable Rte_Read_PMS_DID_PMS_ACCMEnable_PMS_ACCMEnable
#define Rte_Read_PMS_BatteryVol_PMS_BatteryVol Rte_Read_PMS_DID_PMS_BatteryVol_PMS_BatteryVol
#define Rte_Read_PMS_Brake1Switch_PMS_Brake1Switch Rte_Read_PMS_DID_PMS_Brake1Switch_PMS_Brake1Switch
#define Rte_Read_PMS_Brake2Switch_PMS_Brake2Switch Rte_Read_PMS_DID_PMS_Brake2Switch_PMS_Brake2Switch
#define Rte_Read_PMS_CPSREn_PMS_CPSREn Rte_Read_PMS_DID_PMS_CPSREn_PMS_CPSREn
#define Rte_Read_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd Rte_Read_PMS_DID_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd
#define Rte_Read_PMS_CurrentGearPosition_PMS_CurrentGearPosition Rte_Read_PMS_DID_PMS_CurrentGearPosition_PMS_CurrentGearPosition
#define Rte_Read_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid Rte_Read_PMS_DID_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid
#define Rte_Read_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV Rte_Read_PMS_DID_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV
#define Rte_Read_PMS_DcDcActvdReq_PMS_DcDcActvdReq Rte_Read_PMS_DID_PMS_DcDcActvdReq_PMS_DcDcActvdReq
#define Rte_Read_PMS_DriveModeInd_PMS_DriveModeInd Rte_Read_PMS_DID_PMS_DriveModeInd_PMS_DriveModeInd
#define Rte_Read_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl Rte_Read_PMS_DID_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl
#define Rte_Read_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb Rte_Read_PMS_DID_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb
#define Rte_Read_PMS_FunLockVehActive_PMS_FunLockVehActive Rte_Read_PMS_DID_PMS_FunLockVehActive_PMS_FunLockVehActive
#define Rte_Read_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl Rte_Read_PMS_DID_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl
#define Rte_Read_PMS_HVIL1Sts_PMS_HVIL1Sts Rte_Read_PMS_DID_PMS_HVIL1Sts_PMS_HVIL1Sts
#define Rte_Read_PMS_HVIL2Sts_PMS_HVIL2Sts Rte_Read_PMS_DID_PMS_HVIL2Sts_PMS_HVIL2Sts
#define Rte_Read_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer Rte_Read_PMS_DID_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer
#define Rte_Read_PMS_IgnONSts_PMS_IgnONSts Rte_Read_PMS_DID_PMS_IgnONSts_PMS_IgnONSts
#define Rte_Read_PMS_IsgModReq_PMS_IsgModReq Rte_Read_PMS_DID_PMS_IsgModReq_PMS_IsgModReq
#define Rte_Read_PMS_IsgTqReq_PMS_IsgTqReq Rte_Read_PMS_DID_PMS_IsgTqReq_PMS_IsgTqReq
#define Rte_Read_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts Rte_Read_PMS_DID_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts
#define Rte_Read_PMS_PTC2Enable_PMS_PTC2Enable Rte_Read_PMS_DID_PMS_PTC2Enable_PMS_PTC2Enable
#define Rte_Read_PMS_PTC3Enable_PMS_PTC3Enable Rte_Read_PMS_DID_PMS_PTC3Enable_PMS_PTC3Enable
#define Rte_Read_PMS_PTCEnable_PMS_PTCEnable Rte_Read_PMS_DID_PMS_PTCEnable_PMS_PTCEnable
#define Rte_Read_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd Rte_Read_PMS_DID_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd
#define Rte_Read_PMS_Real_PedalPosition_PMS_Real_PedalPosition Rte_Read_PMS_DID_PMS_Real_PedalPosition_PMS_Real_PedalPosition
#define Rte_Read_PMS_SelfCheckSts_PMS_SelfCheckSts Rte_Read_PMS_DID_PMS_SelfCheckSts_PMS_SelfCheckSts
#define Rte_Read_PMS_VehicleSpeed_PMS_VehicleSpeed Rte_Read_PMS_DID_PMS_VehicleSpeed_PMS_VehicleSpeed
#define Rte_Read_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV Rte_Read_PMS_DID_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV
#define Rte_Read_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS Rte_Read_PMS_DID_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS
#define Rte_Read_PMS_ePTReady_PMS_ePTReady Rte_Read_PMS_DID_PMS_ePTReady_PMS_ePTReady
#define Rte_Read_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq Rte_Read_PMS_DID_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq
#define Rte_Read_VCU_Odometerbackup_VCU_Odometerbackup Rte_Read_PMS_DID_VCU_Odometerbackup_VCU_Odometerbackup
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
#ifndef RTE_CORE
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
#ifndef RTE_CORE
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_IrvRead_<p>_<d> and Rte_IrvWrite_<p>_<d> Inter-runnable variables
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    extern declaration of calibration parameters buffers
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_CData (SW-C local calibration parameters) and Rte_Prm (Calibration component calibration parameters)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    extern declaration of Buffers for Memory Block
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_Pim (Per-Instance Memory)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Runnable entities
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Operation Invocation Runnable entities
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
#if 0 //UDS不使用
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_AC_ACCM_ActPower_0x0328_CS_ReadData Rte_Call_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) AC_ACCM_ActPower_0x0328_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData Rte_Call_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_BMSH_SelfCheckFault_0x032B_CS_ReadData Rte_Call_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) BMSH_SelfCheckFault_0x032B_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData Rte_Call_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_ClearNumOfOdometer_0x0335_CS_ReadData Rte_Call_PMS_DID_ClearNumOfOdometer_0x0335_CS_ReadData
#define Rte_Call_PMS_DID_ClearNumOfOdometer_0x0335_CS_ReadData ClearNumOfOdometer_0x0335_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) ClearNumOfOdometer_0x0335_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_DCDC_SelfChkSts_0x032C_CS_ReadData Rte_Call_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) DCDC_SelfChkSts_0x032C_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_EHB_EPBStatus_0x0312_CS_ReadData Rte_Call_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) EHB_EPBStatus_0x0312_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_SelfChkSts_0x032A_CS_ReadData Rte_Call_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) IPU_SelfChkSts_0x032A_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PEPS_PowerMode_0x0319_CS_ReadData Rte_Call_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PEPS_PowerMode_0x0319_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_ACCMEnable_0x031D_CS_ReadData Rte_Call_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_ACCMEnable_0x031D_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_BatteryVol_0x0331_CS_ReadData Rte_Call_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_BatteryVol_0x0331_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_Brake1Switch_0x0311_CS_ReadData Rte_Call_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_Brake1Switch_0x0311_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_Brake2Switch_0x0333_CS_ReadData Rte_Call_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_Brake2Switch_0x0333_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_CPSREn_0x0313_CS_ReadData Rte_Call_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_CPSREn_0x0313_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData Rte_Call_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_CoolingFanPWMSpd_0x031C_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DCDCCutOffLV_0x032E_CS_ReadData Rte_Call_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_DCDCCutOffLV_0x032E_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DcDcActvdReq_0x032D_CS_ReadData Rte_Call_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_DcDcActvdReq_0x032D_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DriveModeInd_0x0317_CS_ReadData Rte_Call_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_DriveModeInd_0x0317_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_EDCPPWMCtrl_0x031A_CS_ReadData Rte_Call_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_EDCPPWMCtrl_0x031A_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_EngRecMode_Fb_0x0325_CS_ReadData Rte_Call_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_EngRecMode_Fb_0x0325_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_FunLockVehActive_0x0318_CS_ReadData Rte_Call_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_FunLockVehActive_0x0318_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_HBCPPWMCtrl_0x031B_CS_ReadData Rte_Call_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_HBCPPWMCtrl_0x031B_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_HVIL1Sts_0x0322_CS_ReadData Rte_Call_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_HVIL1Sts_0x0322_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_HVIL2Sts_0x0323_CS_ReadData Rte_Call_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_HVIL2Sts_0x0323_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_IPKTotalOdometer_0x0334_CS_ReadData Rte_Call_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_IPKTotalOdometer_0x0334_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_IgnONSts_0x0332_CS_ReadData Rte_Call_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_IgnONSts_0x0332_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_IsgModReq_0x032F_CS_ReadData Rte_Call_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_IsgModReq_0x032F_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_IsgTqReq_0x0314_CS_ReadData Rte_Call_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_IsgTqReq_0x0314_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_ModeGearDisplaySts_0x0316_CS_ReadData Rte_Call_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_ModeGearDisplaySts_0x0316_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_PTC2Enable_0x031F_CS_ReadData Rte_Call_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_PTC2Enable_0x031F_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_PTC3Enable_0x0320_CS_ReadData Rte_Call_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_PTC3Enable_0x0320_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_PTCEnable_0x031E_CS_ReadData Rte_Call_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_PTCEnable_0x031E_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_PTResiduePwrInd_0x0315_CS_ReadData Rte_Call_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_PTResiduePwrInd_0x0315_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_Real_PedalPosition_0x0310_CS_ReadData Rte_Call_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_Real_PedalPosition_0x0310_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_SelfCheckSts_0x0321_CS_ReadData Rte_Call_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_SelfCheckSts_0x0321_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_VehicleSpeed_0x0327_CS_ReadData Rte_Call_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_VehicleSpeed_0x0327_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x1002_Operation(P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Cond);
#define Rte_Call_ServiceCheckRule_0x1002_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x1002_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x1002_Operation(P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Cond);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x1003_Operation(P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Cond);
#define Rte_Call_ServiceCheckRule_0x1003_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x1003_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x1003_Operation(P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Cond);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x11_Operation(void);
#define Rte_Call_ServiceCheckRule_0x11_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x11_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x11_Operation(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x14_Operation(void);
#define Rte_Call_ServiceCheckRule_0x14_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x14_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x14_Operation(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x22_Operation(void);
#define Rte_Call_ServiceCheckRule_0x22_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x22_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x22_Operation(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x27_Operation(void);
#define Rte_Call_ServiceCheckRule_0x27_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x27_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x27_Operation(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x28_Operation(void);
#define Rte_Call_ServiceCheckRule_0x28_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x28_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x28_Operation(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x2E_Operation(void);
#define Rte_Call_ServiceCheckRule_0x2E_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x2E_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x2E_Operation(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x31_Operation(void);
#define Rte_Call_ServiceCheckRule_0x31_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x31_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x31_Operation(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x85_Operation(void);
#define Rte_Call_ServiceCheckRule_0x85_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x85_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x85_Operation(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_VCU_BMSH_StsModeReq_0x0330_CS_ReadData Rte_Call_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) VCU_BMSH_StsModeReq_0x0330_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_VCU_Odometerbackup_0x0326_CS_ReadData Rte_Call_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) VCU_Odometerbackup_0x0326_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#else
#define Rte_Call_AC_ACCM_ActPower_0x0328_CS_ReadData Rte_Call_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData
#define Rte_Call_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData AC_ACCM_ActPower_0x0328_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) AC_ACCM_ActPower_0x0328_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData Rte_Call_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData
#define Rte_Call_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_BMSH_SelfCheckFault_0x032B_CS_ReadData Rte_Call_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData
#define Rte_Call_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData BMSH_SelfCheckFault_0x032B_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) BMSH_SelfCheckFault_0x032B_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData Rte_Call_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData
#define Rte_Call_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_ClearNumOfOdometer_0x0335_CS_ReadData Rte_Call_PMS_DID_ClearNumOfOdometer_0x0335_CS_ReadData
#define Rte_Call_PMS_DID_ClearNumOfOdometer_0x0335_CS_ReadData ClearNumOfOdometer_0x0335_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) ClearNumOfOdometer_0x0335_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_DCDC_SelfChkSts_0x032C_CS_ReadData Rte_Call_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData
#define Rte_Call_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData DCDC_SelfChkSts_0x032C_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) DCDC_SelfChkSts_0x032C_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_EHB_EPBStatus_0x0312_CS_ReadData Rte_Call_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData
#define Rte_Call_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData EHB_EPBStatus_0x0312_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) EHB_EPBStatus_0x0312_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_SelfChkSts_0x032A_CS_ReadData Rte_Call_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData
#define Rte_Call_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData IPU_SelfChkSts_0x032A_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) IPU_SelfChkSts_0x032A_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PEPS_PowerMode_0x0319_CS_ReadData Rte_Call_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData
#define Rte_Call_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData PEPS_PowerMode_0x0319_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PEPS_PowerMode_0x0319_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_ACCMEnable_0x031D_CS_ReadData Rte_Call_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData
#define Rte_Call_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData PMS_ACCMEnable_0x031D_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_ACCMEnable_0x031D_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_BatteryVol_0x0331_CS_ReadData Rte_Call_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData
#define Rte_Call_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData PMS_BatteryVol_0x0331_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_BatteryVol_0x0331_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_Brake1Switch_0x0311_CS_ReadData Rte_Call_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData
#define Rte_Call_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData PMS_Brake1Switch_0x0311_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_Brake1Switch_0x0311_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_Brake2Switch_0x0333_CS_ReadData Rte_Call_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData
#define Rte_Call_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData PMS_Brake2Switch_0x0333_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_Brake2Switch_0x0333_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_CPSREn_0x0313_CS_ReadData Rte_Call_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData
#define Rte_Call_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData PMS_CPSREn_0x0313_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_CPSREn_0x0313_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData Rte_Call_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData
#define Rte_Call_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData PMS_CoolingFanPWMSpd_0x031C_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_CoolingFanPWMSpd_0x031C_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DCDCCutOffLV_0x032E_CS_ReadData Rte_Call_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData
#define Rte_Call_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData PMS_DCDCCutOffLV_0x032E_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_DCDCCutOffLV_0x032E_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DcDcActvdReq_0x032D_CS_ReadData Rte_Call_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData
#define Rte_Call_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData PMS_DcDcActvdReq_0x032D_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_DcDcActvdReq_0x032D_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DriveModeInd_0x0317_CS_ReadData Rte_Call_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData
#define Rte_Call_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData PMS_DriveModeInd_0x0317_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_DriveModeInd_0x0317_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_EDCPPWMCtrl_0x031A_CS_ReadData Rte_Call_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData
#define Rte_Call_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData PMS_EDCPPWMCtrl_0x031A_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_EDCPPWMCtrl_0x031A_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_EngRecMode_Fb_0x0325_CS_ReadData Rte_Call_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData
#define Rte_Call_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData PMS_EngRecMode_Fb_0x0325_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_EngRecMode_Fb_0x0325_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_FunLockVehActive_0x0318_CS_ReadData Rte_Call_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData
#define Rte_Call_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData PMS_FunLockVehActive_0x0318_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_FunLockVehActive_0x0318_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_HBCPPWMCtrl_0x031B_CS_ReadData Rte_Call_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData
#define Rte_Call_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData PMS_HBCPPWMCtrl_0x031B_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_HBCPPWMCtrl_0x031B_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_HVIL1Sts_0x0322_CS_ReadData Rte_Call_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData
#define Rte_Call_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData PMS_HVIL1Sts_0x0322_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_HVIL1Sts_0x0322_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_HVIL2Sts_0x0323_CS_ReadData Rte_Call_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData
#define Rte_Call_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData PMS_HVIL2Sts_0x0323_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_HVIL2Sts_0x0323_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_IPKTotalOdometer_0x0334_CS_ReadData Rte_Call_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData
#define Rte_Call_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData PMS_IPKTotalOdometer_0x0334_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_IPKTotalOdometer_0x0334_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_IgnONSts_0x0332_CS_ReadData Rte_Call_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData
#define Rte_Call_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData PMS_IgnONSts_0x0332_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_IgnONSts_0x0332_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_IsgModReq_0x032F_CS_ReadData Rte_Call_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData
#define Rte_Call_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData PMS_IsgModReq_0x032F_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_IsgModReq_0x032F_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_IsgTqReq_0x0314_CS_ReadData Rte_Call_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData
#define Rte_Call_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData PMS_IsgTqReq_0x0314_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_IsgTqReq_0x0314_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_ModeGearDisplaySts_0x0316_CS_ReadData Rte_Call_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData
#define Rte_Call_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData PMS_ModeGearDisplaySts_0x0316_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_ModeGearDisplaySts_0x0316_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_PTC2Enable_0x031F_CS_ReadData Rte_Call_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData
#define Rte_Call_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData PMS_PTC2Enable_0x031F_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_PTC2Enable_0x031F_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_PTC3Enable_0x0320_CS_ReadData Rte_Call_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData
#define Rte_Call_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData PMS_PTC3Enable_0x0320_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_PTC3Enable_0x0320_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_PTCEnable_0x031E_CS_ReadData Rte_Call_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData
#define Rte_Call_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData PMS_PTCEnable_0x031E_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_PTCEnable_0x031E_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_PTResiduePwrInd_0x0315_CS_ReadData Rte_Call_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData
#define Rte_Call_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData PMS_PTResiduePwrInd_0x0315_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_PTResiduePwrInd_0x0315_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_Real_PedalPosition_0x0310_CS_ReadData Rte_Call_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData
#define Rte_Call_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData PMS_Real_PedalPosition_0x0310_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_Real_PedalPosition_0x0310_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_SelfCheckSts_0x0321_CS_ReadData Rte_Call_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData
#define Rte_Call_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData PMS_SelfCheckSts_0x0321_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_SelfCheckSts_0x0321_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_VehicleSpeed_0x0327_CS_ReadData Rte_Call_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData
#define Rte_Call_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData PMS_VehicleSpeed_0x0327_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_VehicleSpeed_0x0327_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_VCU_BMSH_StsModeReq_0x0330_CS_ReadData Rte_Call_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData
#define Rte_Call_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData VCU_BMSH_StsModeReq_0x0330_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) VCU_BMSH_StsModeReq_0x0330_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_VCU_Odometerbackup_0x0326_CS_ReadData Rte_Call_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData
#define Rte_Call_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData VCU_Odometerbackup_0x0326_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) VCU_Odometerbackup_0x0326_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_ServiceCheckRule_0x1002_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x1002_Operation
#define Rte_Call_PMS_DID_ServiceCheckRule_0x1002_Operation ServiceCheckRule_0x1002_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x1002_Operation(P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Cond);
#define Rte_Call_ServiceCheckRule_0x1003_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x1003_Operation
#define Rte_Call_PMS_DID_ServiceCheckRule_0x1003_Operation ServiceCheckRule_0x1003_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x1003_Operation(P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Cond);
#define Rte_Call_ServiceCheckRule_0x11_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x11_Operation
#define Rte_Call_PMS_DID_ServiceCheckRule_0x11_Operation ServiceCheckRule_0x11_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x11_Operation(void);
#define Rte_Call_ServiceCheckRule_0x14_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x14_Operation
#define Rte_Call_PMS_DID_ServiceCheckRule_0x14_Operation ServiceCheckRule_0x14_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x14_Operation(void);
#define Rte_Call_ServiceCheckRule_0x22_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x22_Operation
#define Rte_Call_PMS_DID_ServiceCheckRule_0x22_Operation ServiceCheckRule_0x22_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x22_Operation(void);
#define Rte_Call_ServiceCheckRule_0x27_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x27_Operation
#define Rte_Call_PMS_DID_ServiceCheckRule_0x27_Operation ServiceCheckRule_0x27_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x27_Operation(void);
#define Rte_Call_ServiceCheckRule_0x28_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x28_Operation
#define Rte_Call_PMS_DID_ServiceCheckRule_0x28_Operation ServiceCheckRule_0x28_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x28_Operation(void);
#define Rte_Call_ServiceCheckRule_0x2E_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x2E_Operation
#define Rte_Call_PMS_DID_ServiceCheckRule_0x2E_Operation ServiceCheckRule_0x2E_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x2E_Operation(void);
#define Rte_Call_ServiceCheckRule_0x31_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x31_Operation
#define Rte_Call_PMS_DID_ServiceCheckRule_0x31_Operation ServiceCheckRule_0x31_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x31_Operation(void);
#define Rte_Call_ServiceCheckRule_0x85_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x85_Operation
#define Rte_Call_PMS_DID_ServiceCheckRule_0x85_Operation ServiceCheckRule_0x85_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x85_Operation(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_VCU_BMSH_StsModeReq_0x0330_CS_ReadData Rte_Call_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) VCU_BMSH_StsModeReq_0x0330_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_VCU_Odometerbackup_0x0326_CS_ReadData Rte_Call_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) VCU_Odometerbackup_0x0326_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x1002_Operation(P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Cond);
#define Rte_Call_ServiceCheckRule_0x1002_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x1002_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x1002_Operation(P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Cond);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x1003_Operation(P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Cond);
#define Rte_Call_ServiceCheckRule_0x1003_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x1003_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x1003_Operation(P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Cond);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x11_Operation(void);
#define Rte_Call_ServiceCheckRule_0x11_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x11_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x11_Operation(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x14_Operation(void);
#define Rte_Call_ServiceCheckRule_0x14_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x14_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x14_Operation(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x22_Operation(void);
#define Rte_Call_ServiceCheckRule_0x22_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x22_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x22_Operation(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x27_Operation(void);
#define Rte_Call_ServiceCheckRule_0x27_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x27_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x27_Operation(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x28_Operation(void);
#define Rte_Call_ServiceCheckRule_0x28_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x28_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x28_Operation(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x2E_Operation(void);
#define Rte_Call_ServiceCheckRule_0x2E_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x2E_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x2E_Operation(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x31_Operation(void);
#define Rte_Call_ServiceCheckRule_0x31_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x31_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x31_Operation(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x85_Operation(void);
#define Rte_Call_ServiceCheckRule_0x85_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x85_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x85_Operation(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_VCU_BMSH_StsModeReq_0x0330_CS_ReadData Rte_Call_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) VCU_BMSH_StsModeReq_0x0330_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_VCU_Odometerbackup_0x0326_CS_ReadData Rte_Call_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) VCU_Odometerbackup_0x0326_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#endif
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Exclusive Areas.
************************************************************************************************************************
*/

#ifdef __cplusplus
}                  
#endif            
#endif /* RTE_PMS_DID_H_ */
 
 
 

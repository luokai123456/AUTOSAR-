/*
************************************************************************************************************************
*
* File name: Rte_Cbk.h
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
#ifndef RTE_CBK_H_
#define RTE_CBK_H_

/*
************************************************************************************************************************
*    Includes
************************************************************************************************************************
*/
#include "Rte_Type.h"

/*
************************************************************************************************************************
*    COM Callbacks Function declaration for Rx Indication
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) Rte_COMCbk_ACCM1_ActPower_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ACU_CrashOutputSts_ACU_ChimeTelltaleReq_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_AC_ACCM_ActPower_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_AC_ACCM_Status_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_AC_AmbientTemperatureInvalid_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_AC_AmbientTemperature_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_AC_CabinThermalReq_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_AC_CoolingFanPWMSpd_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_AC_IPTC_ActPower_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_AC_IPTC_WorkSts_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_AC_PTC_ActPower_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_AC_PTC_ActPwr_Rear_AC_Status_Info1_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_AC_PTC_WorkSts_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_AC_PTC_WorkSts_Rear_AC_Status_Info1_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_BBM_FaultStatus_BBM_StsFB_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_BBM_WorkSts_BBM_StsFB_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_BCM_ATWS_St_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_BCM_DoorLockStatusDrv_BCM_LDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_BCM_DoorLockStatusPass_BCM_RDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_BCM_DrvSeatbeltBuckleInvalid_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_BCM_DrvSeatbeltBucklestatus_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_BCM_FrontLeftDoorAjarStatus_BCM_LDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_BCM_FrontRightDoorAjarStatus_BCM_RDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_BCM_IntelligentChargeCommand_BCM_ACCinfor_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_BCM_Odometerbackup_BCM_SunroofState_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CCS_ChargeAllow_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CCS_ChargeTotalTime_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CCS_OutputCurrent_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CCS_OutputVoltage_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CEM_BMSAbortChargeTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CEM_BMSChargeStatisticsTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CEM_BMSFinishChargeTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CEM_BMSIdentifyTimout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CEM_BatteryChargeRequireTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CEM_BatteryParameterTimout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CEM_BatteryStateTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CHM_ProtocolVersion_CHM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CML_OutpuVoltageMax_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CML_OutputCurrentMax_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CML_OutputCurrentMin_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CML_OutputVoltageMin_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CRM_RecognitionResult_CRM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CRO_ChargerReady_CRO_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CSD_OutputEnerge_CSD_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CSM_CampModeSwtInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CSM_CampModeSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CSM_DriveModeReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CSM_DriveModeReq_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CSM_EngRec_ReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CSM_EngRec_Req_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CSM_TakeEleSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CSM_TakeEleSwt_ReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CSM_V2XDchaSwtInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CSM_V2XDchaSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortAchiveCondition_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortByFault_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortByUser_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortErrorCurrent_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortErrorVoltage_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortFaultChargerInnerTemp_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortFaultChargerStop_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortFaultChargerTemp_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortFaultConnetor_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortFaultEnergeTransmit_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CST_AbortFaultOther_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_AccessoryConnStsFb_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_CANComFault_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_CutOffLVFb_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_FaultLevel1_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_IDCDCActHiside1_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_IDcDcActLoSide_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_OutOverCurr_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_OutOverVolt_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_PTCConnStsFb_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_Relay_Volt_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_SelfChkSts_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_TDcDc_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_UDCDCActHiside_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_UDcDcActLoSide_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DcDcActvd_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DcDcStsAlm_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EGSM_LeverPosition_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EGSM_ParkReq_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EGSM_ShiftleverFailSt_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_ABSActive_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_ABSFailed_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_AEB_active_EHB_DA_MESSAGE_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_AVHStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_BrkSysErrFault_EHB_DriverRemind_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_DTC_Active_EHB_DA_MESSAGE_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_EPBErrorStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_EPBStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_EPB_DynamicApplystatus_EHB_DriverRemind_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_FLWheelDirection_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_FLWheelSpeedInvalid_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_FLWheelSpeedKPH_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_FRWheelDirection_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_FRWheelSpeedInvalid_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_FRWheelSpeedKPH_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_HHCActive_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_ISA_PTTrqDecReqActive_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_ISA_PTTrqDecReq_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_ISA_Status_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_MbRegenTargetWheelSts_EHB_Regen_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_MbRegenTargetWheel_EHB_Regen_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_PTTrqDecReqActive_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_PTTrqDecReq_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_PTTrqIncReqActive_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_PTTrqIncReq_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_RLWheelDirection_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_RLWheelSpeedInvalid_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_RLWheelSpeedKPH_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_RRWheelDirection_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_RRWheelSpeedInvalid_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_RRWheelSpeedKPH_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_VLC_Active_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_VLC_Available_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_VLC_CDD_active_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_VLC_PTTrqReqActive_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_VLC_PTTrqReq_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_VehicleSpeedInvalid_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_VehicleSpeed_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EWP_HeatPower_HEWP_1_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EWP_OutputTemp_HEWP_1_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FWFV_CCWFlg_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FWFV_CurrentPos_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FWFV_InitState_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FWFV_MotorState_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FWFV_OverCurrentFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FWFV_OverTempFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FWFV_OverVoltageFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FWFV_RESP_ERROR_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FWFV_UnderVoltageFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HCM_AcceRelayVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HCM_AcceRelayVolt_HCM_Other2RelayValue_N72_HCM__Matrix_V1_1_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HCM_FastChgBackVolt_HCM_OtherRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HCM_InsulateCounter_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HCM_MainNegBackVolt_HCM_OtherRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HCM_MainPosBackVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HCM_MainPosBackVolt_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HCM_MainPosFrtVolt_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HCM_NegInsulateVal_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HCM_PTCRelayVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HCM_PTCRelayVolt_HCM_Other2RelayValue_N72_HCM__Matrix_V1_1_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HCM_PosInsulateVal_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HCM_ShuntTemp_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HCM_TotalCurr_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_IPK_AllowChgSoftSwCtrlSt_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_IPK_ChrgSoftSwCtrlSt_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_IPK_Day_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_IPK_EngRecMode_Req_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_IPK_Hour_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_IPK_IPKTotalOdometer_IPK_TotalOdometer_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_IPK_Minute_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_IPK_Month_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_IPK_Odometerbackup_IPK_TotalOdometer_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_IPK_Second_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_IPK_Year_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_MHGV_CCWFlg_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_MHGV_CurrentPos_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_MHGV_InitState_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_MHGV_MotorState_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_MHGV_OverCurrentFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_MHGV_OverTempFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_MHGV_OverVoltageFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_MHGV_RESP_ERROR_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_MHGV_UnderVoltageFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_MMI_LocalBookChrgnTarVal_MMI_SOCSet_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_MMI_RestSwitch_MMI_HVSM_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_OBC_CCvalue_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_OBC_ChgCCSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_OBC_ChrgrSt_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_OBC_DischargeCCvalue_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_OBC_Elock_Stmode_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_OBC_LockLoopSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_OBC_OnBdCCline_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_OBC_OnBdCPline_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_OBC_OnBdChrgrT_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_OBC_OnBdDisChrgrCCline_OBC_Curr_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_OBC_OnBdOuptI_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_OBC_OnBdOuptU_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_OBC_PwrEgyMgrAvl_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_OBC_SelfCheSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_OBC_uInAct_OBC_Curr_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ODP_DCDC_TDcDcAlm_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PDC_Brake_Flag_PDC_Status_Info_N72__PMS_C_CAN_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PEPS_PowerModeValidity_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PEPS_PowerMode_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PEPS_RKECommand_PEPS_KeyReminder_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PEPS_RemoteControlSt_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_RFR_ConnectionStatus_Station_Status_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_RFR_Seed_RFR_Seed_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_RFR_SwapBatCode_RFR_SwapBatCode_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Station_CarLocationConfirm_Station_Status_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Station_CarStation_Station_Status_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Station_SwapBatRequest_Station_Status_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Station_Swapingproceeding_Station_Status_PMS_EV_CAN_20260427_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_AllowChgCurrentMax_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_ChargeDepth_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_ChargeLimitSwitch_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_ChrgSoftSwCtrlSt_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_Day_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_Elevation_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_FunAnti_DismantleActive_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_FunLockVehActive_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_Hour_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_InventorySpdLmtReq_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_Life_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_LockLimSet_TBOX_VCULockResp_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_LockVehCtrl_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_LockVehPerFlag_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_LockVehType_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_Minute_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_Month_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_PowerOffCmd_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_PriorityFullSwitchSts_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_PriorityFullSwitchSts_UB_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_ReservationChrgnSts_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_Second_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_SpdLmtLevelReq_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_VersionConversionFlag_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TBOX_Year_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_YRS_LongitAcce_YRS2_N72__PMS_C_CAN_20260425_dbc_Rx(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    COM Callbacks Function declaration for Rx Timeout Notification
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    COM Callbacks Function declaration for Rx Invalid Notification
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    COM Callbacks Function declaration for Rx Ack Notification
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    NvM-Callback for Rte_SetMirror
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    NvM-Callback for Rte_GetMirror
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    NvM-Callback for Rte_NvMNotifyInitBlock
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    NvM-Callback for Rte_NvMNotifyJobFinished
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    COM Callbacks Function definition for Map Service
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    extern declarations of LDCOM variables
************************************************************************************************************************
*/

#endif /* RTE_CBK_H_ */

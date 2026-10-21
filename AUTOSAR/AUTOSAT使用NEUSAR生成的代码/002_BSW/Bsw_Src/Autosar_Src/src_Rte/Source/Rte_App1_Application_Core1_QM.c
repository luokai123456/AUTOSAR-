/*
************************************************************************************************************************
*
* File name: Rte_App1_Application_Core1_QM.c
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
#define RTE_CORE


/*
************************************************************************************************************************
*    Includes
************************************************************************************************************************
*/
#include "Os.h"
#include "Rte_Type.h"
#include "Rte_Main.h"
#include "Rte_IoHwAbSelf.h"
#include "Rte_EVPT_XCUInterFace_Map.h"
#include "Rte_PMS_BswAswRte.h"
#include "Rte_PMS_DID.h"
#include "Rte_PMS_HWI.h"
#include "Rte_PMS_HWO.h"
#include "Rte_swc_ATAU.h"
#include "Rte_swc_AUXC.h"
#include "Rte_swc_DIAG.h"
#include "Rte_swc_EGYM.h"
#include "Rte_swc_HMIF.h"
#include "Rte_swc_HVSM.h"
#include "Rte_swc_MEST.h"
#include "Rte_swc_OGVL.h"
#include "Rte_swc_RMLK.h"
#include "Rte_swc_SCAP.h"
#include "Rte_swc_SCOO.h"
#include "Rte_swc_TCOO.h"
#include "Rte_swc_THSM.h"
#include "Rte_swc_VCIP.h"
#include "Rte_swc_VCOP.h"
#include "Rte_swc_VOMM.h"
#include "ASW_Task_Instead.h"
#include "EcuM.h"
#include "Rte_Cbk.h"
#include "Rte_Hook.h"
#include "Com.h"

/*
************************************************************************************************************************
    Timer handling
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Local Types
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    API for enable / disable interrupts up to the systemLevel . 
************************************************************************************************************************
*/
#define Rte_DisableOSInterrupts() SuspendOSInterrupts()
#define Rte_EnableOSInterrupts() ResumeOSInterrupts()

/*
************************************************************************************************************************
*    Definition of Buffers for unqueued S/R 
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_PMS_SWCompileDay_PMS_SWCompileDay = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_PMS_SWCompileMonth_PMS_SWCompileMonth = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_PMS_SWCompileYear_PMS_SWCompileYear = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_ACCM_ActPower_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_V2XDchaSwtInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_SelfChkSts_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx = 3U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_ACCM1_ActPower_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_ACU_CrashOutputSts_ACU_ChimeTelltaleReq_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_AC_ACCM_Status_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 1U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_CabinThermalReq_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_CoolingFanPWMSpd_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_IPTC_ActPower_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_AC_IPTC_WorkSts_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 1U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_PTC_ActPower_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_PTC_ActPwr_Rear_AC_Status_Info1_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_AC_PTC_WorkSts_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx = 1U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_AC_PTC_WorkSts_Rear_AC_Status_Info1_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_BBM_FaultStatus_BBM_StsFB_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_BBM_WorkSts_BBM_StsFB_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_BCM_ATWS_St_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_BCM_DrvSeatbeltBuckleInvalid_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_BCM_DrvSeatbeltBucklestatus_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_BCM_FrontLeftDoorAjarStatus_BCM_LDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_BCM_FrontRightDoorAjarStatus_BCM_RDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_BCM_IntelligentChargeCommand_BCM_ACCinfor_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_BCM_Odometerbackup_BCM_SunroofState_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_CampModeSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_CampModeSwtInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_DriveModeReq_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_DriveModeReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_EngRec_Req_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_EngRec_ReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_TakeEleSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_TakeEleSwt_ReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_V2XDchaSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_AccessoryConnStsFb_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx = 3U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_DCDC_CANComFault_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_CutOffLVFb_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_FaultLevel1_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_IDCDCActHiside1_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_IDcDcActLoSide_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_DCDC_OutOverCurr_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_DCDC_OutOverVolt_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_PTCConnStsFb_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx = 3U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_DCDC_Relay_Volt_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_TDcDc_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_DCDC_UDCDCActHiside_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_UDcDcActLoSide_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_DcDcActvd_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_DcDcStsAlm_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EGSM_LeverPosition_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EGSM_ParkReq_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EGSM_ShiftleverFailSt_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_ABSActive_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_ABSFailed_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx = 1U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_AEB_active_EHB_DA_MESSAGE_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_AVHStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_BrkSysErrFault_EHB_DriverRemind_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_DTC_Active_EHB_DA_MESSAGE_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_EPBErrorStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_EPB_DynamicApplystatus_EHB_DriverRemind_N72__PMS_C_CAN_20260425_dbc_Rx = 6U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_HHCActive_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_ISA_PTTrqDecReq_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx = 6000U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_ISA_PTTrqDecReqActive_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_ISA_Status_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_MbRegenTargetWheel_EHB_Regen_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_MbRegenTargetWheelSts_EHB_Regen_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_PTTrqDecReq_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx = 1000U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_PTTrqDecReqActive_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_PTTrqIncReq_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx = 1000U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_PTTrqIncReqActive_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_VLC_Active_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_VLC_Available_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_VLC_CDD_active_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_VLC_PTTrqReq_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx = 65535U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_VLC_PTTrqReqActive_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EWP_HeatPower_HEWP_1_VE21_N72_PMS_LIN_ldf_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EWP_OutputTemp_HEWP_1_VE21_N72_PMS_LIN_ldf_Rx = 50U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_CCWFlg_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_FWFV_CurrentPos_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_InitState_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx = 1U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_MotorState_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_OverCurrentFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_OverTempFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_OverVoltageFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_RESP_ERROR_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_UnderVoltageFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_AcceRelayVolt_HCM_Other2RelayValue_N72_HCM__Matrix_V1_1_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_HCM_AcceRelayVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx = 1U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_HCM_MainPosBackVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx = 1U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_PTCRelayVolt_HCM_Other2RelayValue_N72_HCM__Matrix_V1_1_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_HCM_PTCRelayVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx = 1U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_IPK_AllowChgSoftSwCtrlSt_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_IPK_ChrgSoftSwCtrlSt_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_EngRecMode_Req_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(uint32, RTE_VAR_INIT) Rte_ComBuffer_IPK_IPKTotalOdometer_IPK_TotalOdometer_N72__PMS_PT_CANFD_20260425_dbc_Rx = 16777215U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_IPK_Odometerbackup_IPK_TotalOdometer_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_CCWFlg_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_MHGV_CurrentPos_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_InitState_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_MotorState_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_OverCurrentFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_OverTempFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_OverVoltageFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_RESP_ERROR_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_UnderVoltageFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_MMI_LocalBookChrgnTarVal_MMI_SOCSet_N72__PMS_PT_CANFD_20260425_dbc_Rx = 1023U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_MMI_RestSwitch_MMI_HVSM_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_LockLoopSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx = 3U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdChrgrT_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_OBC_PwrEgyMgrAvl_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_SelfCheSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx = 3U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_ODP_DCDC_TDcDcAlm_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_PDC_Brake_Flag_PDC_Status_Info_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_PEPS_RKECommand_PEPS_KeyReminder_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_PEPS_RemoteControlSt_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_RFR_ConnectionStatus_Station_Status_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint64, RTE_VAR_INIT) Rte_ComBuffer_RFR_Seed_RFR_Seed_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint64, RTE_VAR_INIT) Rte_ComBuffer_RFR_SwapBatCode_RFR_SwapBatCode_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_Station_CarLocationConfirm_Station_Status_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_Station_CarStation_Station_Status_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_Station_SwapBatRequest_Station_Status_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_Station_Swapingproceeding_Station_Status_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_AllowChgCurrentMax_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx = 255U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_ChargeDepth_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx = 255U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_ChargeLimitSwitch_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Elevation_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_FunAnti_DismantleActive_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx = 3U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_FunLockVehActive_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx = 3U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_InventorySpdLmtReq_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx = 3U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Life_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_LockLimSet_TBOX_VCULockResp_N72__PMS_PT_CANFD_20260425_dbc_Rx = 7U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_LockVehCtrl_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx = 3U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_LockVehPerFlag_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx = 3U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_LockVehType_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx = 3U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_TBOX_PowerOffCmd_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_PriorityFullSwitchSts_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_TBOX_PriorityFullSwitchSts_UB_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_SpdLmtLevelReq_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx = 3U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_VersionConversionFlag_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx = 3U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_YRS_LongitAcce_YRS2_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmd = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_Heat_AC_EWP_Heat = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_HeatrPwrCnsAllwd_AC_EWP_HeatrPwrCnsAllwd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_Run_AC_EWP_Run = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_SpeedReq_AC_EWP_SpeedReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_Temp_AC_EWP_Temp = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_ACChgTimeRemain_BMSH_ACChgTimeRemain = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattCurr_BMSH_BattCurr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattFaultLampState_BMSH_BattFaultLampState = 0U;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS = 0.0F;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattRemainEnergy_BMSH_BattRemainEnergy = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattSOC_BMSH_BattSOC = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattSOH_BMSH_BattSOH = 0U;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattTempAvg_PT_BMSH_BattTempAvg_PT = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattVolt_BMSH_BattVolt = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_CellTemp_Uniformity_BMSH_CellTemp_Uniformity = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_CellVolt_Uniformity_BMSH_CellVolt_Uniformity = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Cell_OverVol_BMSH_Cell_OverVol = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Cell_TotalNum_BMSH_Cell_TotalNum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Cell_UnderVol_BMSH_Cell_UnderVol = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_ChargeLEDCtrl_BMSH_ChargeLEDCtrl = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_ChargeToBeFinished_BMSH_ChargeToBeFinished = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Charge_Over_Current_BMSH_Charge_Over_Current = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_ChgTimeRemain_BMSH_ChgTimeRemain = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_DCChgminusSocketTempSensing_Failure_BMSH_DCChgminusSocketTempSensing_Failure = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_DCChgplusSocketTempSensing_Failure_BMSH_DCChgplusSocketTempSensing_Failure = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_FastChgCC2ConntState_BMSH_FastChgCC2ConntState = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_HVBusVolt_BMSH_HVBusVolt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_HvBattCooltTReq_BMSH_HvBattCooltTReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_HvBattThermMod_BMSH_HvBattThermMod = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_HvShutdownReq_BMSH_HvShutdownReq = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_ICU_BatteryElectricDTE_BMSH_ICU_BatteryElectricDTE = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Inlet_WaterTemp_BMSH_Inlet_WaterTemp = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_InsulationRes_BMSH_InsulationRes = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_InsulationRes_Fault_BMSH_InsulationRes_Fault = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Low_SOC_BMSH_Low_SOC = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Outlet_WaterTemp_BMSH_Outlet_WaterTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Over_SOC_BMSH_Over_SOC = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Over_Temperature_BMSH_Over_Temperature = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Pack_OverVoltage_BMSH_Pack_OverVoltage = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Pack_UnderVoltage_BMSH_Pack_UnderVoltage = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_SOC_Hop_BMSH_SOC_Hop = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatIsoAlarm2_PT_BMSH_TBOX_BatIsoAlarm2_PT = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatLowSOC2_PT_BMSH_TBOX_BatLowSOC2_PT = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverCharge2_PT_BMSH_TBOX_BatOverCharge2_PT = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverSOC2_PT_BMSH_TBOX_BatOverSOC2_PT = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverTemp2_PT_BMSH_TBOX_BatOverTemp2_PT = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverVoltage2_PT_BMSH_TBOX_BatOverVoltage2_PT = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatTempUniformity2_PT_BMSH_TBOX_BatTempUniformity2_PT = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatUnderVoltage2_PT_BMSH_TBOX_BatUnderVoltage2_PT = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatUniformity2_PT_BMSH_TBOX_BatUniformity2_PT = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_CellOverVoltage2_PT_BMSH_TBOX_CellOverVoltage2_PT = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_CellUnderVoltage2_PT_BMSH_TBOX_CellUnderVoltage2_PT = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS = 0.0F;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_SOCHop2_PT_BMSH_TBOX_SOCHop2_PT = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TempSensor_MaxTemp_BMSH_TempSensor_MaxTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TempSensor_MinTemp_BMSH_TempSensor_MinTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TempSensor_TotalNum_BMSH_TempSensor_TotalNum = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_ThermalOutofControl_BMSH_ThermalOutofControl = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Vehicle_HVILSts_PHEV_BMSH_Vehicle_HVILSts_PHEV = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_VoltCurr_Checksum_BMSH_VoltCurr_Checksum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_stMode_BMSH_stMode = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMS_BattPackMatchFault_BMS_BattPackMatchFault = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS = 0.0F;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMS_MaxCellVolt_BMS_MaxCellVolt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMS_MaxTemp1SnsNum_BMS_MaxTemp1SnsNum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMS_MaxVoltCellNum_BMS_MaxVoltCellNum = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMS_MinCellVolt_BMS_MinCellVolt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMS_MinVoltCellNum_BMS_MinVoltCellNum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMS_MinxTemp1SnsNum_BMS_MinxTemp1SnsNum = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_DrvPfmncRedn_DrvPfmncRedn = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_EDCP_Flt_EDCP_Flt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_EDCP_PWMFB_EDCP_PWMFB = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_HBCP_Flt_HBCP_Flt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_HBCP_PWMFB_HBCP_PWMFB = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_IPK_IPKTotalOdometer_EV_IPK_IPKTotalOdometer_EV = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_IPU_HVBusCur_PT_IPU_HVBusCur_PT = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_IPU_HVBusVolt_PT_IPU_HVBusVolt_PT = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_IPU_IPUTAlm_IPU_IPUTAlm = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_IPU_MCUTempHighAlarm1_PT_IPU_MCUTempHighAlarm1_PT = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS = 0.0F;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS = 0.0F;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_IPU_MotorTempHighFault1_PT_IPU_MotorTempHighFault1_PT = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_CCWFlg_PMS_MHGV_CCWFlg_PMS = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_CurrentPos_PMS_MHGV_CurrentPos_PMS = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_InitState_PMS_MHGV_InitState_PMS = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_MotorState_PMS_MHGV_MotorState_PMS = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_OverCurrentFlt_PMS_MHGV_OverCurrentFlt_PMS = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_OverTempFlt_PMS_MHGV_OverTempFlt_PMS = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_OverVoltageFlt_PMS_MHGV_OverVoltageFlt_PMS = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_RESP_ERROR_PMS_MHGV_RESP_ERROR_PMS = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_UnderVoltageFlt_PMS_MHGV_UnderVoltageFlt_PMS = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_ODP_TBOX_DcDcStsAlm_ODP_TBOX_DcDcStsAlm = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_ODP_TBOX_TDcDcAlm_ODP_TBOX_TDcDcAlm = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_0X16A_TimeoutFlag_PMS_0X16A_TimeoutFlag = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ACC1PosVol_PMS_ACC1PosVol = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ACC2PosVol_PMS_ACC2PosVol = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ACCMEnable_PMS_ACCMEnable = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ACC_BeControlled_Status_PMS_ACC_BeControlled_Status = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AcceRelayVoltSampSwich_PMS_AcceRelayVoltSampSwich = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AcceSuppressionSts_PMS_PMS_AcceSuppressionSts_PMS = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AccelPedalPosition_PMS_AccelPedalPosition = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AccelPedalPositionInvalid_PMS_AccelPedalPositionInvalid = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Acceleration_PMS_Acceleration = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AccessoryConnStsFb_PMS_AccessoryConnStsFb = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AccessoryCtrlCommand_PMS_AccessoryCtrlCommand = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AccessoryRelayFlt_PMS_AccessoryRelayFlt = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ActualPTTorque_PMS_ActualPTTorque = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ActualPTTorqueInvalid_PMS_ActualPTTorqueInvalid = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AppSts_PMS_AppSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AuthResult_PMS_AuthResult = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AveragePowerConsumption_PMS_AveragePowerConsumption = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BBM1CtrlCmd_PMS_BBM1CtrlCmd = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BBMAllowEnable_Ctrl_PMS_BBMAllowEnable_Ctrl = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BBMPowerSupplyEn_Ctrl_PMS_BBMPowerSupplyEn_Ctrl = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BBM_FaultStatus_PMS_BBM_FaultStatus = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BBM_HVReq_PMS_BBM_HVReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BBM_WorkSts_PMS_BBM_WorkSts = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BMSH_BattRemainEnergy_PMS_BMSH_BattRemainEnergy = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BMSH_BattSOCDisp_PMS_BMSH_BattSOCDisp = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BMSH_BattSOH_PMS_BMSH_BattSOH = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BMS_Reignstatus1_PMS_BMS_Reignstatus1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BMS_Reignstatus2_PMS_BMS_Reignstatus2 = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BatCoolType_PMS_BatCoolType = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BattPackInCoolTempback_EV_PMS_BattPackInCoolTempback_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BattPackOutCoolTempback_EV_PMS_BattPackOutCoolTempback_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BatteryVol_PMS_BatteryVol = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Brake_LightsRequest_PMS_Brake_LightsRequest = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BrkSysErr_PMS_BrkSysErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CANBus_RecSta_PMS_CANBus_RecSta = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CPSREn_PMS_CPSREn = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CPSRU_PMS_CPSRU = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CSControl1_CheckSum_PMS_CSControl1_CheckSum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CSControl2_CheckSum_PMS_CSControl2_CheckSum = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CampModeFb_PMS_CampModeFb = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CampModeFbFailrReason_PMS_CampModeFbFailrReason = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ChargPwr_PMS_ChargPwr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ChargWakeupSts_PMS_ChargWakeupSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ChargeHV_Status_PMS_ChargeHV_Status = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ChargeLimitResponse_PMS_ChargeLimitResponse = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ChargerFault_PMS_ChargerFault = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Command_AliveCounter_PMS_Command_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Command_Checksum_PMS_Command_Checksum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CoolingFanFaultFB_PMS_CoolingFanFaultFB = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Ctrl_Checksum_PMS_Ctrl_Checksum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CurrentGearPosition_PMS_CurrentGearPosition = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DCDCAwake_HW_PMS_DCDCAwake_HW = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DCDCPwrLmt_PMS_DCDCPwrLmt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DDwaterPump_PWMCtrl_EV_PMS_DDwaterPump_PWMCtrl_EV = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DcDcActvdReq_PMS_DcDcActvdReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DisChrgrSwtSt_PMS_DisChrgrSwtSt = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DischargeEnable_PMS_DischargeEnable = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DoubleFlashLampOn_PMS_DoubleFlashLampOn = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriveModeInd_PMS_DriveModeInd = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriverDemandTorque_PMS_DriverDemandTorque = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriverDemandTorqueInvalid_PMS_DriverDemandTorqueInvalid = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriverGearAbort_PMS_DriverGearAbort = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DrivingTakeEleSts_PMS_DrivingTakeEleSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DrvrGearLvrLockIndcn_PMS_DrvrGearLvrLockIndcn = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCPEnable_PMS_EDCPEnable = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCP_FaultFB_PMS_EDCP_FaultFB = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCP_PWMCtrl_PMS_EDCP_PWMCtrl = 0U;
VAR(SInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EPS_SteeringAngleValue_PMS_EPS_SteeringAngleValue = 0;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EVDTEodometer_PMS_EVDTEodometer = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EngControl_CheckSum_PMS_EngControl_CheckSum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EngTrqReqSrc_PMS_EngTrqReqSrc = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ErrCode_PMS_ErrCode = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FAN_PWMCtrl_PMS_FAN_PWMCtrl = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Fn1GearRlyDrvStsFb_PMS_Fn1GearRlyDrvStsFb = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Fn2GearRlyDrvStsFb_PMS_Fn2GearRlyDrvStsFb = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FunAnti_DismantleActive_PMS_FunAnti_DismantleActive = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FunLockVehActive_PMS_FunLockVehActive = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_GP_Ovrd_PMS_GP_Ovrd = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_GearOperateErr_PMS_GearOperateErr = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Gear_intervene_PMS_Gear_intervene = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_GrossComVehWeight_PMS_GrossComVehWeight = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HBCPEnable_PMS_HBCPEnable = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HBCP_FaultFB_PMS_HBCP_FaultFB = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HBCP_PWMCtrl_PMS_HBCP_PWMCtrl = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVIL1Sts_PMS_HVIL1Sts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVIL1Sts_UB_PMS_HVIL1Sts_UB = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVIL2Sts_PMS_HVIL2Sts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVIL2Sts_UB_PMS_HVIL2Sts_UB = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVILSts_PMS_HVILSts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVILSts_UB_PMS_HVILSts_UB = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVPRASts_PMS_HVPRASts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HardwareMajorVer_PMS_HardwareMajorVer = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HardwareMinorVer_PMS_HardwareMinorVer = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HvCoolgPwrAllwd_PMS_HvCoolgPwrAllwd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HvHeatgPwrAllwd_PMS_HvHeatgPwrAllwd = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IPK_HandBrakeSts_PMS_IPK_HandBrakeSts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IgnONSts_PMS_IgnONSts = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IntelligentChargeExitReq_PMS_IntelligentChargeExitReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IntelligentChargeQuit_PMS_IntelligentChargeQuit = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IntelligentChargeState_PMS_IntelligentChargeState = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_InventorySpdLmtRxSts_PMS_InventorySpdLmtRxSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_InventorySpdLmtSts_PMS_InventorySpdLmtSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IsgModReq_PMS_IsgModReq = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IsgTqReq_PMS_IsgTqReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LTCoolingFanFB_PMS_LTCoolingFanFB = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Life_PMS_Life = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LimpHomeSts_PMS_LimpHomeSts = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LockLimResult_PMS_LockLimResult = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LockVehExecutedSts_PMS_LockVehExecutedSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LockVehPerFlag_PMS_LockVehPerFlag = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LockVehPerRxSts_PMS_LockVehPerRxSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LockVehSts_PMS_LockVehSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LockVehType_PMS_LockVehType = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MCUFlowFeedback_EV_PMS_MCUFlowFeedback_EV = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_EnableReq_PMS_MHGV_EnableReq = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_PosSet_PMS_MHGV_PosSet = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_ReqMotorEmgyStop_PMS_MHGV_ReqMotorEmgyStop = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_ReqMotorOptRecovery_PMS_MHGV_ReqMotorOptRecovery = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MaxPTTorqueAllowed_PMS_MaxPTTorqueAllowed = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MinPTTorqueAllowed_PMS_MinPTTorqueAllowed = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ModeControl_CheckSum_PMS_ModeControl_CheckSum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_NMSts_PMS_NMSts = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder = 0.0F;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_OdometerbackupEnable_PMS_OdometerbackupEnable = FALSE;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PEPSAuth_PMS_PEPSAuth = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PEPS_0x1E2_TimeoutFlag_PMS_PEPS_0x1E2_TimeoutFlag = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PEPS_PowerMode_PMS_PEPS_PowerMode = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PEPS_PowerModeValidity_PMS_PEPS_PowerModeValidity = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC1ConnStsFb_PMS_PTC1ConnStsFb = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC1RelayFlt_PMS_PTC1RelayFlt = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC2Enable_PMS_PTC2Enable = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC3ConnStsFb_PMS_PTC3ConnStsFb = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC3Enable_PMS_PTC3Enable = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC3RelayFlt_PMS_PTC3RelayFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTCEnable_PMS_PTCEnable = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTCRelayVoltSampSwich_PMS_PTCRelayVoltSampSwich = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PowerOffCmdRxSts_PMS_PowerOffCmdRxSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PowerOffCmdSts_PMS_PowerOffCmdSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PreAccessoryConnStsFb_PMS_PreAccessoryConnStsFb = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PreAccessoryRelayFlt_PMS_PreAccessoryRelayFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Real_PedalPosition_PMS_Real_PedalPosition = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegenTarTrqPot_PMS_RegenTarTrqPot = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegenTarTrqPotQualifier_PMS_RegenTarTrqPotQualifier = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegenTrqAct_PMS_RegenTrqAct = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegenTrqActQualifier_PMS_RegenTrqActQualifier = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegenTrqPot_PMS_RegenTrqPot = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegenTrqPotQualifier_PMS_RegenTrqPotQualifier = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegulationSpeed_PMS_PMS_RegulationSpeed_PMS = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RemChrgCmdFailrPrompt_PMS_RemChrgCmdFailrPrompt = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ReqSeed_PMS_ReqSeed = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RespResult_PMS_RespResult = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SelfCheckSts_PMS_SelfCheckSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SoftwareMajorVer_PMS_SoftwareMajorVer = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SoftwareMinorVer_PMS_SoftwareMinorVer = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SpdLmtLevel_PMS_SpdLmtLevel = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SpdLmtLevelRxSts_PMS_SpdLmtLevelRxSts = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StartActive_PMS_StartActive = FALSE;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Stayawake_reasons_PMS_Stayawake_reasons = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StsBrkSwitch1_PMS_StsBrkSwitch1 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StsBrkSwitch1Invalid_PMS_StsBrkSwitch1Invalid = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StsBrkSwitch1Invalid_PMS_PMS_StsBrkSwitch1Invalid_PMS = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StsBrkSwitch1_PMS_PMS_StsBrkSwitch1_PMS = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StsSwap_PMS_StsSwap = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SwapAuthRelease_EV_PMS_SwapAuthRelease_EV = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_BrkSysErr_PMS_TBOX_BrkSysErr = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_HVILSts_PMS_TBOX_HVILSts = FALSE;
VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_LifeSts_PMS_TBOX_LifeSts = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TakeEleSwtIndReq_PMS_TakeEleSwtIndReq = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Torque_Ovrd_Active_PMS_Torque_Ovrd_Active = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Torque_Ovrd_Type_PMS_Torque_Ovrd_Type = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TurtleLampOn_PMS_TurtleLampOn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TurtleLampOn2_PMS_TurtleLampOn2 = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_V2XDchaSwtFb1_PMS_V2XDchaSwtFb1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode1_8_15_S_PMS_VINCode1_8_15_S = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode2_9_16_S_PMS_VINCode2_9_16_S = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode3_10_17_S_PMS_VINCode3_10_17_S = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode4_11_S_PMS_VINCode4_11_S = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode5_12_S_PMS_VINCode5_12_S = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode6_13_S_PMS_VINCode6_13_S = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode7_14_S_PMS_VINCode7_14_S = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINMessageNum_S_PMS_VINMessageNum_S = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VacuumPressure_PMS_VacuumPressure = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VacuumPumpCmd_PMS_VacuumPumpCmd = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VacuumPump_FB_PMS_VacuumPump_FB = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VacuumSystemsta_PMS_VacuumSystemsta = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSpeed_PMS_VehicleSpeed = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSysErrorLevel_PMS_VehicleSysErrorLevel = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSysErrorLevelG_PMS_VehicleSysErrorLevelG = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSysErrorLevelG1_PMS_PMS_VehicleSysErrorLevelG1_PMS = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VersionConversionFlag_PMS_VersionConversionFlag = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VersionConversionRxSts_PMS_VersionConversionRxSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Wakeup_reasons_PMS_Wakeup_reasons = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTFault_PMS_ePTFault = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTFault2_PMS_ePTFault2 = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTModeActual_PMS_ePTModeActual = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTModeSelect_PMS_ePTModeSelect = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTReady_PMS_ePTReady = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTReleaseSig_PMS_ePTReleaseSig = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_TBOX_ChrgSoftSwCtrlst_EV_TBOX_ChrgSoftSwCtrlst_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_TBOX_ReservationChrgnSts_EV_TBOX_ReservationChrgnSts_EV = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_VCU_ActInputVolt_VCU_ActInputVolt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_Ctrl_CheckSum_VCU_BMSH_Ctrl_CheckSum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_DCChgRelayVolt_VCU_BMSH_DCChgRelayVolt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_ChargeDepthReq_VCU_ChargeDepthReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_CrashOutputSts_VCU_CrashOutputSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_DCInputCurrent_VCU_DCInputCurrent = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_VCU_Odometerbackup_VCU_Odometerbackup = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_VehicleInfo_CheckSum_VCU_VehicleInfo_CheckSum = 0U;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_ChgCCSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_ChrgrSt_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_Elock_Stmode_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdCCline_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdCPline_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdDisChrgrCCline_OBC_Curr_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdOuptI_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdOuptU_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_ChrgSoftSwCtrlSt_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_ReservationChrgnSts_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_EPBStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx = 3U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_PEPS_PowerMode_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_AmbientTemperature_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 120U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_AC_AmbientTemperatureInvalid_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_FLWheelSpeedKPH_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_FRWheelSpeedKPH_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_RLWheelSpeedKPH_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_RRWheelSpeedKPH_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_VehicleSpeed_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_VehicleSpeedInvalid_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_PEPS_PowerModeValidity_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Day_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Hour_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Minute_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Month_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Second_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Year_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
#include "Rte_MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_BattPackNum_EV_BMSH_BattPackNum_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_BattSysNum_EV_BMSH_BattSysNum_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_BattTempAvg_EV_BMSH_BattTempAvg_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatIsoAlarm2_EV_BMSH_TBOX_BatIsoAlarm2_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatLowSOC2_EV_BMSH_TBOX_BatLowSOC2_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverCharge2_EV_BMSH_TBOX_BatOverCharge2_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverSOC2_EV_BMSH_TBOX_BatOverSOC2_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverTemp2_EV_BMSH_TBOX_BatOverTemp2_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverVoltage2_EV_BMSH_TBOX_BatOverVoltage2_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatTempUniformity2_EV_BMSH_TBOX_BatTempUniformity2_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUnderVoltage2_EV_BMSH_TBOX_BatUnderVoltage2_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUniformity2_EV_BMSH_TBOX_BatUniformity2_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellA_ID_EV_BMSH_TBOX_CellA_ID_EV = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellA_Volt_EV_BMSH_TBOX_CellA_Volt_EV = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellB_Volt_EV_BMSH_TBOX_CellB_Volt_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellC_ID_EV_BMSH_TBOX_CellC_ID_EV = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellC_Volt_EV_BMSH_TBOX_CellC_Volt_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellOverVoltage2_EV_BMSH_TBOX_CellOverVoltage2_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellUnderVoltage2_EV_BMSH_TBOX_CellUnderVoltage2_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_FireAlarm_EV_BMSH_TBOX_FireAlarm_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_SOCHop2_EV_BMSH_TBOX_SOCHop2_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMS_DelayDataUpldEnb_EV_BMS_DelayDataUpldEnb_EV = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_HVBusCur_EV_IPU_HVBusCur_EV = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_HVBusVolt_EV_IPU_HVBusVolt_EV = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_HVBusVolt_IPUSts_IPU_HVBusVolt_IPUSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_MCUTempHighAlarm1_EV_IPU_MCUTempHighAlarm1_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_MotorOverCurrFlt_EV_IPU_MotorOverCurrFlt_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_MotorOverSpdFlt_EV_IPU_MotorOverSpdFlt_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_MotorTempHighFault1_EV_IPU_MotorTempHighFault1_EV = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_PMS_BswAswRte_ECU_Fun_Config_Data1_ECU_Fun_Config_Data1 = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_PMS_BswAswRte_ECU_Fun_Config_Data2_ECU_Fun_Config_Data2 = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_PMS_BswAswRte_ECU_Net_Config_Data1_ECU_Net_Config_Data1 = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_PMS_BswAswRte_ECU_Net_Config_Data2_ECU_Net_Config_Data2 = 0U;
VAR(Float, RTE_VAR_INIT) Rte_PMS_BswAswRte_EXT_DO_RELAY_LS_10_Fb_EXT_DO_RELAY_LS_10_Fb = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PMS_BswAswRte_EXT_DO_RELAY_LS_7_Fb_EXT_DO_RELAY_LS_7_Fb = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PMS_BswAswRte_EXT_DO_RELAY_LS_9_Fb_EXT_DO_RELAY_LS_9_Fb = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte0_F190_VIN_Byte0 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte1_F190_VIN_Byte1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte10_F190_VIN_Byte10 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte11_F190_VIN_Byte11 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte12_F190_VIN_Byte12 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte13_F190_VIN_Byte13 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte14_F190_VIN_Byte14 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte15_F190_VIN_Byte15 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte16_F190_VIN_Byte16 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte2_F190_VIN_Byte2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte3_F190_VIN_Byte3 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte4_F190_VIN_Byte4 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte5_F190_VIN_Byte5 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte6_F190_VIN_Byte6 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte7_F190_VIN_Byte7 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte8_F190_VIN_Byte8 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte9_F190_VIN_Byte9 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte2_F193_ECUHardwareVersionNumber_Byte2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte3_F193_ECUHardwareVersionNumber_Byte3 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte4_F193_ECUHardwareVersionNumber_Byte4 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte6_F193_ECUHardwareVersionNumber_Byte6 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte7_F193_ECUHardwareVersionNumber_Byte7 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte8_F193_ECUHardwareVersionNumber_Byte8 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte2_F195_ECUSoftwareVersionNumber_Byte2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte3_F195_ECUSoftwareVersionNumber_Byte3 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte4_F195_ECUSoftwareVersionNumber_Byte4 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte6_F195_ECUSoftwareVersionNumber_Byte6 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte7_F195_ECUSoftwareVersionNumber_Byte7 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte8_F195_ECUSoftwareVersionNumber_Byte8 = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_PDCStatus_AlvCtrErrFlg_PDCStatus_AlvCtrErrFlg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_PDC_Status_CsmErrFlg_PDC_Status_CsmErrFlg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_s2vd_BMS_PmtCutoffLVFb_s2vd_BMS_PmtCutoffLVFb = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_adcCanBusOff_vild_b_adcCanBusOff = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_evCanBusOff_vild_b_evCanBusOff = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgABSMsgErr_vild_b_flgABSMsgErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgABSSpdMsgErr_vild_b_flgABSSpdMsgErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgACUAlvCtrErr_vild_b_flgACUAlvCtrErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgACUCsmErr_vild_b_flgACUCsmErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgACUMsgErr_vild_b_flgACUMsgErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgBBMMsgErr_vild_b_flgBBMMsgErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgBMSAlvCtrErr_vild_b_flgBMSAlvCtrErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgBMSCsmErr_vild_b_flgBMSCsmErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgBMSMsgErr_vild_b_flgBMSMsgErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgCSMAlvCtrErr_vild_b_flgCSMAlvCtrErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgCSMCsmErr_vild_b_flgCSMCsmErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgCSMMsgErr_vild_b_flgCSMMsgErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgClearDTC_vild_b_flgClearDTC = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgDCDCMsgErr_vild_b_flgDCDCMsgErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgEGSMAlvCtrErr_vild_b_flgEGSMAlvCtrErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgEGSMCsmErr_vild_b_flgEGSMCsmErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgEGSMMsgErr_vild_b_flgEGSMMsgErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgEHBAlvCtrErr_vild_b_flgEHBAlvCtrErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgEHBCsmErr_vild_b_flgEHBCsmErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgIPUAlvCtrErr_vild_b_flgIPUAlvCtrErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgIPUCsmErr_vild_b_flgIPUCsmErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgMCUMsgErr_vild_b_flgMCUMsgErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_pmsCanBusOff_vild_b_pmsCanBusOff = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_BATTERY_TEMPH_5_EXT_AI_BATTERY_TEMPH_5 = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_BATTERY_TEMPH_6_EXT_AI_BATTERY_TEMPH_6 = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_MID_COOLING_TEMPH_8_EXT_AI_MID_COOLING_TEMPH_8 = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_SENSOR_1_EXT_AI_SENSOR_1 = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_SENSOR_2_EXT_AI_SENSOR_2 = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_SENSOR_6_EXT_AI_SENSOR_6 = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_SWITCH_1_EXT_AI_SWITCH_1 = 0.0F;
VAR(UInt16, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AO_LDO_5V_02_EXT_AO_LDO_5V_02 = 0U;
VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AO_TRACKING_5V_01_EXT_AO_TRACKING_5V_01 = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AO_TRACKING_5V_02_EXT_AO_TRACKING_5V_02 = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_CHARGE_ON_AI_EXT_CHARGE_ON_AI = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_DI_HS_04_EXT_DI_HS_04 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_DI_HS_05_EXT_DI_HS_05 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_DI_HS_06_EXT_DI_HS_06 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_DI_HS_07_EXT_DI_HS_07 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_DI_HS_08_EXT_DI_HS_08 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_DI_HS_10_EXT_DI_HS_10 = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_PMS_HWI_EXT_IGN_ON_AI_EXT_IGN_ON_AI = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_IGN_ON_DI_EXT_IGN_ON_DI = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_HVIL_1_DutyCycle_EXT_PI_HVIL_1_DutyCycle = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_HVIL_1_Period_EXT_PI_HVIL_1_Period = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_HVIL_2_DutyCycle_EXT_PI_HVIL_2_DutyCycle = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_HVIL_2_Period_EXT_PI_HVIL_2_Period = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_PWM_1_DutyCycle_EXT_PI_PWM_1_DutyCycle = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_PWM_1_Period_EXT_PI_PWM_1_Period = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_PWM_2_DutyCycle_EXT_PI_PWM_2_DutyCycle = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_PWM_2_Period_EXT_PI_PWM_2_Period = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_KL30_KL30 = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_ATAU_vcsb_ATAU_pmmd_b_ePTRelease_flg = 0U;
VAR(KeyAuthStatus, RTE_VAR_INIT) Rte_swc_ATAU_vcsb_ATAU_pmmd_e_authenticationStatus = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpEnOvrTmHiPreFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpEnOvrTmLoPreFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpLoPreFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpRlyEn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpRlyFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpSnrFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpSysFailFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacTkAirPresLowFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankPresLow = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankPresLowEVDis = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankPresLowInhDrv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_bdcacEna = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_bdcacTmOut = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_brkPmp1Rly = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_brkPmp2Rly = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_pumpRdy = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_p_VacPumpPressure_kPa = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_u_VacPumpVol_V = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_lvbd_b_lvbSOCValid = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_lvbd_q_lvbSOC_pct = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_pscd_b_epsEna = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_pscd_b_epsStopFlt = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_pscd_frq_epsFrqTgt_Hz = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_acpd_b_accPed1Vld = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_acpd_b_accPed2Vld = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_brpd_b_brkSwtMismatch = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_ddid_b_bmsMsgErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_ddid_b_egsmMsgErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl1Flt_flg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl21Flt_flg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl22Flt_flg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl23Flt_flg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl31Flt_flg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl32Flt_flg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl33Flt_flg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_bmsFltLv4A = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_mcuFltLv2A = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_mcuFltLv3A = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_mcuMsgErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_vcuVehLvl1Flt_flg_BRP = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_vcuVehLvl22Flt_flg_BRP = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_vehCrashFltLvl33 = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_st_edcpFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_st_hbcpFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_st_vehSysErrLevel = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_macd_b_EVCANBusoff31Err = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_macd_b_EVCANBusoffDebd = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_accd_pwr_hvAttpwr_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_accd_pwr_maxPwrLim_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_accd_pwr_minPwrLim_kW = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_acEnbAllowFlg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_accyEnbFlg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_dcdcEnbAllowFlg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_mcuEnbFlg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_obcEnbAllowFlg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_ptcEnbAllowFlg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_ptcRearEnbAllowFlg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_zeroPwrFb = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_i_bmshAlwChgCurrMax = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_pct_vcuChgDepReq = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_pwr_accmHvClPwrAllwd_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_pwr_acwpHeatPwrCnsAllwd = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_pwr_ptcHvHtPwrAllwd_kW = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_st_vcuChgLimResp = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_V_engFuelConsAvg_lp100km = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_CruisingDstSwtFb = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_HazardReqLmpOn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_brkSysFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_ePTFault = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_evLampOn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_hevLampOn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_odoBckpEn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_turtleLmpOn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_vehOvrLoadEnbl = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_odoTotal_km = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_pmsOdoBckUpMilg_km = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehCrsDst_km = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehDrvRngEVMod_km = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehDrvRngHEVMod_km = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehDrvRngStandard_km = 0.0F;
VAR(PowerFlowMode, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_e_vehPwrFlow = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_m_vehWeight_kg = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_num_AecEV_kWhp100km = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_num_errorCode = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_pwr_hvPwrCsmpt_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_pwr_hvPwrRemain_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_q_hvbSOC_pct = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_drvModInd = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_drvPfmncRedn = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_drvrOptRmdr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehCalNum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehDrvMode = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehFailLvl = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehOverLoadSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehSubFailLvl = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_bmsd_e_modeTgt = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_dccd_b_DCDCEnabled = FALSE;
VAR(DCDCMode, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_dccd_e_modeTgt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_dccd_pct_DCDCPwrLmt = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_eadd_b_ead2Avail = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_eadd_b_ead2Enad = FALSE;
VAR(ElMac, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_eadd_e_inv2ModeTgt = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_CampModeFb = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_TakeEleSwtIndReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_acPtcEnb = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyHvOnCmd = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyPreRlyCmd = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyWrkEnCmd = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_allowChg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_chgCablePlugged = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_dchaOn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_fltPwrShutDn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_hvBusShutDwnCmpl = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_hvbIntelChgCmplt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_hvbIntelChgExitReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_lvCutOffReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_rlyTmOut = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_tmOutFlg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_tmOutFlgCfm = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_vcuRdyToSlp = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_vcuWkUpCmd = FALSE;
VAR(PmmStatus, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus = 0U;
VAR(HVBattStatus, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_e_modeTgt = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_pct_BookChrgnTarValFb = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_CampModeFbFailrReason = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_RmChgCmdFailPmt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyPreRlyFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyPreRlySts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyRlyFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyRlySts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyRlyVoltSamSw = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyTakeSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_bbmWrkEnCmd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hcmMaiRlyNegClsReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hvbAssiRlyPosClsReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hvbMaiRlyNegClsReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hvbMaiRlyPosClsReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_otaHvOnOFFReqSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_otaHvOnOffFailInfo = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_ptRdyInd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_tboxChgSftSwCtlStEV = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_obcd_b_chargerPlugged = FALSE;
VAR(ChargerStatus, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_obcd_e_chargerSts = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_MEST_vcsb_MEST_masd_b_vehOvrLoadEnbl = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_MEST_vcsb_MEST_masd_m_vehWeight_kg = 0.0F;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_MEST_vcsb_MEST_masd_st_vehCalNum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_MEST_vcsb_MEST_masd_st_vehOverLoadSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_invSpdLmtRxSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_inventorySpdLmtReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_lifeCnt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_lockVehPer = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_lockVehPerRxSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_pwrOffCmd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_pwrOffCmdRxSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_spdLmtLevelReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_spdLmtLvRxSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_tboxLifeSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_verCvsRxSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_versionConversion = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_v_dstSpdLim_kph = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_b_LockVehSts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_b_rmtCtrlAccPedlOff = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_b_rmtCtrlTqOff = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_b_rmtCtrlTurtleLampOn = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_num_FunAnti_DismantleActive = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_num_FunLockVehActive = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_num_LockLimResult = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_num_LockVehType = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_st_LockVehExecutedSts = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_v_rmtCtrlFctSpdLim_kph = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_eadd_b_mot2TqOff = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MaxLTTq_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MaxSTTq_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MinLTTq_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MinSTTq_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_tqld_tq_axle2MaxTq_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_tqld_tq_axle2MinTq_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_tqld_tq_whlMax_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_tqld_tq_whlMin_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_acc_intAccTgt_mps2 = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_acc_vehAccTgt_mps2 = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_b_accCtrlActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_b_crsCtrlAccPedlOvrd = FALSE;
VAR(CrsBtnErrSts, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsBtnErrSts = 0U;
VAR(CrsBtnSts, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsBtnSts = 0U;
VAR(CrModeMngr_e, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsCtrlSpdMode = 0U;
VAR(CruiseSts_e, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsCtrlSts = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_tq_whlDemRawAdv_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_tq_whlDem_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_v_crsCtrlTgtSpd_kph = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_v_crsTgtSpdQuit_kph = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_x_accPedlPosVirt_pct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ctdd_a_yrsLongAccAvgVld_mps2 = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ctdd_b_crpSlopeTrqOffsetEnHld = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ctdd_b_eCreepReq = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ctdd_n_vehTgtCrpSpdFwd_kph = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ctdd_tq_whlDem_Nm = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_vsld_b_vslTqIntvReq = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_vsld_tq_whlMaxTqLimFast_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_vsld_tq_whlMaxTqLimSlow_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_vsld_v_vehMaxCfgSpd_kph = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_vsld_v_vehMaxSpd_kph = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_apdd_tq_whlDem_Nm = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_dtdd_b_drvPfmncDrgDec = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_dtdd_st_RegenLvlDisp = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_dtdd_tq_whlCoastDrgDem_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_dtdd_tq_whlCstDrgDemNoEhb_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_dtdd_tq_whlDragDem_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_eadd_tq_mot2TgtTq_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_msgd_tq_targetTqReq_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tdad_tq_whlDemUnfilt_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tdad_tq_whlDemUnlim_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tdad_tq_whlDem_Nm = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_b_accPedlPosVirtVld = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_b_ehbDisEnbCreep = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_b_gpOvrd = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_st_ehbOvrdActv = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_st_ehbOvrdTyp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_st_whlAcceSupprsn = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_x_accPedlPosVirt_pct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tvrd_tq_mot2TgtTqReq_Nm = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_ActiveCool_flg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_BalanceHeat_flg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_PassCool_flg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_PassHeat_flg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_TwoWayVlvReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_accmEnb = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_afterRunActive = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_fan2Ena = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_fanRly1Req = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_fanRly2Req = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna2 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna3 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna3HW = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEnaHW = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_hvbDeft = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_iptcHtIpuCl = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_iptcHtIpuResvHt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_ipuHeatEnableFlg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_ipuResvHt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_ipuSupHtIptcHt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_tv1V2 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_tv1V3 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_tv2V2 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_tv4V2 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_tv4V3 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmp1CtrlEnabled = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmp2CtrlEnabled = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmpRly1Req = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmpRly2Req = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_FWFVTgt_pct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_MHGVTgt_pct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_fan1TgtSpd_pct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_fan2TgtSpd_pct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_pmp1TgtSpd_pct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_pmp2TgtSpd_pct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_pwr_ipuHeatPwrAllwd_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_q_pmp2FlowFeedback = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_acceRlyVoltSamSwitch = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_acwpHeat = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_acwpSpdReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptc3ConnStsFb = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptc3RlyFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptcConnStsFb = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptcRlyFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptcRlyVoltSamSwitch = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_tv4 = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_t_acwpTemp_C = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_b_acHvilOpn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_b_acHvilOpnInvld = FALSE;
VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_e_PtcSt = 0U;
VAR(FaultStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_e_acFltLvl = 0U;
VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_e_airCmprSt = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_n_acFanReqSpd_pct = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_AcWrk = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_acSubFltSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_airCmprSt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_cbnThermMngReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_iptWorkSt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_ptcWorkStRear = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_t_ambTemp_C = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_u_acPresVolt_V = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_b_accPedlPosVld = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_u_accPedlPosSens1VoltRaw_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_u_accPedlPosSens2VoltRaw_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosCan_pct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosLimd_pct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosSens1_pct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosSens2_pct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPos_pct = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_b_adc1CtrlTorqEn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_b_adc1SwtchCtrlReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_b_adcCtrlGearEn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_b_adcCtrlTorqEn = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_st_adcTgtGearPostn = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_st_pmsAdcCtrldSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_st_pmsCanBusRecSta = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_tq_adc1TgtDrvTorq_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_tq_adcTgtDrvTorq_Nm = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_DryAirSwitch = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_ResrAirSwitch = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brakeSwitch1Closed = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brakeSwitch2Closed = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPedlPosVld = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPedlStsVld = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPmpSelfChkErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPmpSelfChkOk = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPressedFromSwitch = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPumpFault = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_vacTankLowPrs = FALSE;
VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_e_bdcacWrk = 0U;
VAR(BrakePedalStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_e_brkPedalStatus = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_p_AirPres_kpa = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_p_brkVacuumPres_bar = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_st_bdcacWrk = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_x_brkPedlPos_pct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_ccdd_u_cruiseADvoltage_V = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_cesd_b_EmergencyStop = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_cesd_b_acuCrash = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_cesd_b_crash = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcCutOffLvFb = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcHvilFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcHvilFltInvld = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcSelfChkErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcSelfChkOk = FALSE;
VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_e_24vDcdcModAct = 0U;
VAR(FaultStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_e_dcdcFaultStatus = 0U;
VAR(DCDCMode, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_e_modeAct = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_pwr_dcdcHVpwr_kW = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_st_12vDcdcModAct = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_st_24vDcdcFltSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_st_24vDcdcModAct = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_st_24vDcdcSubFltSts = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_t_dcdcTemp_C = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReq4WD = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqECO = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqEV = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqHEV = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqSPORT = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_parkBtnPressed = 0U;
VAR(GearLeverPos, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_e_gearLvrPosRaw = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_st_gearLvrPosSeql = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2ActvDischCmplt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2RdyToCutOffLV = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2SelfChkErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2SelfChkOk = FALSE;
VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_e_eadInv2Sts = 0U;
VAR(FaultStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_e_inv21FltSts = 0U;
VAR(FaultStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_e_inv2FltSts = 0U;
VAR(ElMac, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_e_inv2ModeAct = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_fact_mot2GearRat = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_n_mot2ActSpd_rpm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_pwr_mot21ActPwr_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_pwr_mot2ActPwr_kW = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_st_eadInv2PwrActvMod = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_st_eadInv2Sts = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_st_eadInv2WrkMod = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_st_eadMot2ImmoRlsChk = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_st_inv2SubFltSts = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_t_inv2Temp_C = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_t_mot2Temp_C = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2ActTq_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailLTBrk_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailLTBst_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailSTBrk_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailSTBst_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_u_busInv2HVAct_V = 0.0F;
VAR(ParkingStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_epbd_e_parkingSts = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_bmsSelfChkErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_bmsSelfChkOk = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmCutOffLvFb = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmPtcDefRlyCls = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmRlyWldFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmSelfChkErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmSelfChkOk = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbChPwrLimdByTemp = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbDischPwrLimdByTemp = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbHeatEnad = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbPrmtCutOffLvFb = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvilOpen = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_lowTempProtnReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_obcChrgReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw = FALSE;
VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_dcdcMainRlySts = 0U;
VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_eadInv2MainRlySts = 0U;
VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hcmMaiRlyNeg = 0U;
VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hcmWrkSt = 0U;
VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbAssiRly = 0U;
VAR(FaultStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbFaultStatus = 0U;
VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMaiRlyNeg = 0U;
VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMaiRlyPos = 0U;
VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMainRlySts = 0U;
VAR(HVBattStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbStatus = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_fact_hvbSOH_pct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_i_hvbCurr_A = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_PeakChMax_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_PeakDischMax_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_StatChMax_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_StatDischMax_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_hvbActRaw_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_hvbAct_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_hvbChgPwr_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_q_hvbSOC_pct = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hcmFltLvl = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hcmMaiRlyNeg = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hcmPwrActvMod = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvbPwrActvMod = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvbSubFaultSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvbThermMngReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvilOpenSt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_tboxIntelChgQuit = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbAvg_C = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbInCoolTemp_C = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbMin_C = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbTemp_C = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_V_tankFuelLvl_l = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_b_epsSelfChkErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_b_epsSelfChkOk = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_b_pullUpDiagCmpl = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_b_vcuSelfChkOk = FALSE;
VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_e_sdcacWrk = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_p_frontAirTankPres_bar = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_p_rearAirTankPres_bar = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_st_epsErrorCode = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_st_epsFltLvl = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_st_epsSubFltLvl = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_st_sdcacWrk = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_t_ts5SnsrTemp_C = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_u_batIntSmpl_V = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcCANMsgValid = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcChrgCablePlugged = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcChrgCableUnplugged = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcSelfChkErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcSelfChkOk = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcWakeUp = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_pwr_obcOutpt_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_pwr_obcRlTmOutpt_kW = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_st_obcfltLvl = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_t_obcTemp_C = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_anyIgnOn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_canIgnOn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_driverStartReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_hwIgnOn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignStsStrt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_pepsPduLvlValid = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ptCanNmStRdy = FALSE;
VAR(KeyAuthStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_e_authenticationStatus = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_b_trsm2GearActVld = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_b_trsm2GearshiftActv = FALSE;
VAR(ParkingStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_e_trsm1PrkgSts = 0U;
VAR(GearShiftResp, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_e_trsm2GearShftResp = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_fact_trsm2FinalDrvRat = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_fact_trsm2GbxGearRat = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_fact_trsm2GearRat = 0.0F;
VAR(SInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_st_trsm2GearAct = 0;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_R_posInsIRes_Ohm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_a_yrsLongitAcce_mps2 = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_ang_strWhlAng_rad = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_AccyEnReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_AccyFltSts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_CCSginal = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_DryAirSwitch = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ResrAirSwitch = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_adc1ComErrFlg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_adcComErrFlg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_bcmFrntLftDrAjSts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_bcmFrntRDrAjSts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_brkSwt1Actv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_brkSwt2Actv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_calCanBusOff = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_cntnrCtrlEnaFb = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmCampModeSwt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmCampModeSwtInvld = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmEngRecSwtReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmTakeEleSwt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmTakeEleSwtReqInvld = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmV2XDchaSw = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmV2XDchaSwInvld = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_dcdcStsAlm = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_dcdcTempAlm = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_disChgSwtSt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_driverEcoModeReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ehbIsaPtTrqDecReqActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ehbVlcCddActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_emgyStopIn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_epbErrSts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgBBMMsgErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgACU = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgAccyButton = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgAirBag = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgBatCol = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgChgTyp = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgCoastActivBrkLight = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvMod = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvModConn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvModStor = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvSeat = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDualAuthN = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgEpdel = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgMaxChgCurr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgMotor = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgTyre = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFnctnConfgEGSM = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFnctnConfgEHB = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgNetConfgABS = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvCcwFlg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvInitSts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvMotSts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvOvrCurrFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvOvrTempFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvOvrVoltFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvRespErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvUndVoltFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hcmMainPosBckVoltVldSts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hcmPtcRlyVoltVldSts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbDCChgCurReqRngUp = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbDisChgSopRngUp = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbHvilFlt = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbInPositionDetct1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbInPositionDetct2 = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbZeroPwrReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ignStsOn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ignStsStrt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ipkOdoBckUpEn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvCcwFlg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvInitSts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvMotSts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvOvrCurrFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvOvrTempFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvOvrVoltFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvRespErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvUndVoltFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_obcWakeUpActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_odometerInvalid = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_pepsOnSwtSt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_pepsPduLvlVld = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_pepsRmtCtrlSt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ptCanBusOff = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_pullUpDiagCmpl = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_rfrSwapBatReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_rstAvgPwrConsumption = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_tboxPowOffCmd = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_tboxPrtFullSwStUB = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_d_bcmOdometerbackup = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_d_ipkOdometerbackup = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_d_odometer_km = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_i_dcdcInpCurr_A = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_i_hvbCurr_A = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_i_hvbDCChgCurReq_A = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_l_whlRad_m = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbCellMaxID = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbCellMinID = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbCellSum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbMaxTempID = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbMinTempID = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbTempSum = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_GearPosn = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_HVILReturnPWM = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP1FbPWM = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP2FbPWM = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP3FbPWM = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_fan1Fb = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_fan2Fb = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_fwfvCrtPos = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_mhgvCrtPos = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_mmiLocBkChgTarVal = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_tboxAlwChgCurrMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_tboxChgDepth = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_PTCActPwr_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_acwpHeatPower_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_airCmprAct_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_iptActPwr_kW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_ptcActPwrRear_kW = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_24vDcdcModAct = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_BmsTempOutOfCtrlFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXFunAntiDismantleActive = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXFunLockVehActive = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockLimSet = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockResultResp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockVehCtrl = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockVehType = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_actWorkSts1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_batLowSoc2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_batOvrSoc2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_batOvrVolt2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_batUdrVolt2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bbmFltSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bbmWorkSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsBattPackMatchFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsBattPackNum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsBattSysNum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsDlyDataUpldEnb = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsTboxFireAlm = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_cellOverVolt2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_cellUdrVolt2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_csmEngRecReqInvalid = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_csmRgnLvlSet = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_dcChgCcSt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_dccAccyConnStsFb = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_eadInv2FltSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_eadInv2TempHiAlrm = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_egsmShftLvrFailSt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ehbBrkSysErrFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ehbIsaSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_epsEpasFail = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flg2FctCfgVehTyp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgAccy = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgBatTyp = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgDspRemainRng = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgECOMaxSpd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgFan = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgMaxSpd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgMotTyp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgPowerMaxSpd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgSlowChg = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgV2L = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehCfg = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehTyp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehUsg = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hcmAccConnStsFb = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hcmHvilSt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hcmPTC1ConnStsFb = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hcmPtcDefRlyStFb = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbBatUniformity = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbBattIsolationSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbCellTempDevFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbCellVoltDevFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgCcsts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgFltReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgOvrCurr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgPlgNOvrTmp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgPlgPOvrTmp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgProcss = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDischgFltReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbInslErr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbOvrChgFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbPreChgSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbSocFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbSocJumpFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStatus = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStsChgFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStsDischgFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbTempFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbThermMngReq = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipkAlwChgSftCtlSt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipkChgSftSwCtlSt = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipkCruisingDstSwt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipuInvTempHighAlm = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipuMotTempHighFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipuMotorOverCurrFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipuMotorOverSpdFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_mmiRestSwitch = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcChgCCSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcChgSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcElckStMod = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcOnBdCCline = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcOnBdDchaCCline = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_pepsPduLvl = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_pepsPduLvlVld = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_pepsRKECom = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ptcConnStsFb = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_rfrConnctSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_rfrSwapprocd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxChgLmtSw = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxChgSftSwCtlSt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxInventorySpdLmtReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxLife = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxLockVehPerFlag = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxPrtFullSwSt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxRsrChgSt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxSpdLmtLevelReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxStartBattChgReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxVersionConversionFlag = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_vscEHBAVHSts = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_TS5sensorFb_C = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_acwpOutptTemp_C = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbCooltInTemp_C = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbCooltOutTemp_C = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbMax_C = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbMin_C = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbOutCoolTemp_C = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbSetTgtTemp_C = 0.0F;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_tm_hvbFnshChgTim_m = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_tq_ehbIsaPtTrqDecReq_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_5VT1IntSmpl_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_5VT2IntSmpl_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_Acc1Raw_mV = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_Acc2Raw_mV = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_BmsMaxCellVolt_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_BmsMinCellVolt_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_Brk2Raw_mV = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_Brk2_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_BrkRaw_mV = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_Brk_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_TS5sensorFb_mV = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_VacTkAirPres_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_VacTkEnFb_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_accPdlSens1InpVolt_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_accPdlSens2InpVolt_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_batLpPmpCtrlFb_mV = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_brkVacuumPres_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_cbnLpPmpCtrlFb_mV = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_dcdcRelayVolt_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_eLpWpCtrlCur_mV = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hcmAcceRlyVolt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hcmMainPosBckVolt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hcmPtcRlyVolt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbCooltInSnsr_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbCooltOutSnsr_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbPackVolt_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbVolt_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_ipuHVBusVolt_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_pepsOn_mV = 0.0F;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_vacTkPowSup_V = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_v_ehbVehSpd_kph = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_a_vscLongitAcce_mps2 = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ESPActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ESPActvRaw = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbAbsOvrdActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbAebActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbDtcActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbTrqDecReqActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbTrqIncReqActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbVlcActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbVlcAvailb = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbVlcTrqReqActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_pdcBrkFlg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSlipWarn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSpdVld = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_vscBrkLghtActv = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbAVHSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbEPBDynAppSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbHHCActive = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbMbRgnTgtWhlSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_st_vscIsgActvDampModReq = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_axle2MaxTqReq_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_axle2MinTqReq_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_axle2RgnBrkTqReq_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbMbRgnTgtWhl_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbTrqDecReq_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbTrqIncReq_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbVlcTrqReq_Nm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpdRaw_kph = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_Heat_LIN_AC_EWP_Heat_LIN = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_HeatrPwrCnsAllwd_LIN_AC_EWP_HeatrPwrCnsAllwd_LIN = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_Run_LIN_AC_EWP_Run_LIN = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_SpeedReq_LIN_AC_EWP_SpeedReq_LIN = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_Temp_LIN_AC_EWP_Temp_LIN = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Battery_Performance_Checksum_BMSH_Battery_Performance_Checksum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9 = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_HVIL_1_DutyCycle_EXT_PO_HVIL_1_DutyCycle = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_HVIL_1_Period_EXT_PO_HVIL_1_Period = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_HVIL_2_DutyCycle_EXT_PO_HVIL_2_DutyCycle = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_HVIL_2_Period_EXT_PO_HVIL_2_Period = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_1_DutyCycle_EXT_PO_PWM_1_DutyCycle = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_1_Period_EXT_PO_PWM_1_Period = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_2_DutyCycle_EXT_PO_PWM_2_DutyCycle = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_2_Period_EXT_PO_PWM_2_Period = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_4_DutyCycle_EXT_PO_PWM_4_DutyCycle = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_4_Period_EXT_PO_PWM_4_Period = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_CCWFlg_PMS_FWFV_CCWFlg_PMS = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_CurrentPos_PMS_FWFV_CurrentPos_PMS = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_InitState_PMS_FWFV_InitState_PMS = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_MotorState_PMS_FWFV_MotorState_PMS = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_OverCurrentFlt_PMS_FWFV_OverCurrentFlt_PMS = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_OverTempFlt_PMS_FWFV_OverTempFlt_PMS = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_OverVoltageFlt_PMS_FWFV_OverVoltageFlt_PMS = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_RESP_ERROR_PMS_FWFV_RESP_ERROR_PMS = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_UnderVoltageFlt_PMS_FWFV_UnderVoltageFlt_PMS = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_O_S_PIN110_O_S_PIN110 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_O_S_PIN123_O_S_PIN123 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_O_S_PIN83_O_S_PIN83 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_O_S_PIN88_O_S_PIN88 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_O_S_PIN89_O_S_PIN89 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_O_S_PIN98_O_S_PIN98 = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN104_Duty_O_T_PIN104_Duty = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN104_Period_O_T_PIN104_Period = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN118_Duty_O_T_PIN118_Duty = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN118_Period_O_T_PIN118_Period = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN14_Duty_O_T_PIN14_Duty = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN14_Period_O_T_PIN14_Period = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN28_Duty_O_T_PIN28_Duty = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN28_Period_O_T_PIN28_Period = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN77_Duty_O_T_PIN77_Duty = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN77_Period_O_T_PIN77_Period = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN82_Duty_O_T_PIN82_Duty = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN82_Period_O_T_PIN82_Period = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ADCCtrlSts_PMS_ADCCtrlSts = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_APA_BeControlled_Status_PMS_APA_BeControlled_Status = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AppSts_EV_PMS_AppSts_EV = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Brake1Switch_PMS_Brake1Switch = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Brake2Switch_PMS_Brake2Switch = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Command_AliveCounter_EV_PMS_Command_AliveCounter_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Command_Checksum_EV_PMS_Command_Checksum_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ControlSetSpeed_PMS_ControlSetSpeed = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CruiseControlSts_PMS_CruiseControlSts = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CruiseSwitchSts_PMS_CruiseSwitchSts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CruisingDstSwtFb_PMS_CruisingDstSwtFb = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CurrentGearPosition_EV_PMS_CurrentGearPosition_EV = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CurrentGearPosition_Valid_EV_PMS_CurrentGearPosition_Valid_EV = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DCDC_Ctrl_AliveCounter_PMS_DCDC_Ctrl_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DCDC_Ctrl_Checksum_PMS_DCDC_Ctrl_Checksum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DM_FailureReasonAndSysFaultFBK_PMS_DM_FailureReasonAndSysFaultFBK = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DcDc1ActvdReq_EV_PMS_DcDc1ActvdReq_EV = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriveCircuitTemp_EV_PMS_DriveCircuitTemp_EV = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriverRemind_PMS_DriverRemind = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCPEnable_EV_PMS_EDCPEnable_EV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCPPWMCtrl_EV_PMS_EDCPPWMCtrl_EV = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EPBClosedReq_PMS_EPBClosedReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EPS_SteeringAngleValueInvalid_PMS_EPS_SteeringAngleValueInvalid = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EPedlDrvrIndcnMsg_PMS_EPedlDrvrIndcnMsg = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EpedalActive_PMS_EpedalActive = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ExecuteLockVehResults_PMS_ExecuteLockVehResults = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FWFV_MoveEnable_PMS_FWFV_MoveEnable = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FWFV_MoveEnable_LIN_PMS_FWFV_MoveEnable_LIN = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FWFV_ReqMovePos_PMS_FWFV_ReqMovePos = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FWFV_ReqMovePos_LIN_PMS_FWFV_ReqMovePos_LIN = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HvBattCooltLvl_PMS_HvBattCooltLvl = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MCUActvdReq_PMS_MCUActvdReq = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MCUTemp_EV_PMS_MCUTemp_EV = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_EnableReq_LIN_PMS_MHGV_EnableReq_LIN = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_PosSet_LIN_PMS_MHGV_PosSet_LIN = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_ReqMotorEmgyStop_LIN_PMS_MHGV_ReqMotorEmgyStop_LIN = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_ReqMotorOptRecovery_LIN_PMS_MHGV_ReqMotorOptRecovery_LIN = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Odometerbackup_PMS_Odometerbackup = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SlidingmomentrSetReq_PMS_SlidingmomentrSetReq = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_HVILState_PMS_TBOX_HVILState = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_HVILState_3A1_PMS_TBOX_HVILState_3A1 = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ThermalReq_PMS_ThermalReq = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTReady_EV_PMS_ePTReady_EV = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTRegencyLevInd_PMS_ePTRegencyLevInd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_st_ShtDown_st_ShtDown = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_vcob_VCOP_BMSH_ChargeLEDCtrl = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_epbClsdReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_gearPosVld = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_veh4WDModActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_vehEcoModActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_vehSportModActv = FALSE;
VAR(DriveDir, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_driveDirSel = 0U;
VAR(HEVModeReq, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_drvrHEVModReq = 0U;
VAR(GearLeverPos, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_gearLvrPos = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_st_gearLvrLckInd = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_engStartReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_engStopReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_engStrtAbort = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_engStrtComplete = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_motStrtDem = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_motStrtEnad = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_strtrRlyDem = FALSE;
VAR(EngStartType, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_e_engStrtTyp = 0U;
VAR(EngStartType, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_e_engStrtTypSeld = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_hmmd_b_EVModeActive = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_hmmd_b_HVBusDischrgComplete = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_emsWake = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_hsdFltClear = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_nmRdySlp = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_nmSts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_nmWkUp = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_peuWake = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_pwrHoldReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_startReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_vcuAwb = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_vcuRmr = FALSE;
VAR(rt_Array_UInt8_2, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_bm_netModeReq = {0U};
VAR(NMStatus, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_e_CanNMSts = 0U;
VAR(PmmMode, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_e_mode = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_num_vcuAddr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_st_bdCanModeReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_st_ptCanModeReq = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_st_stayAwkReason = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_st_vcuPwrActvMod = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_st_vcuWkUpReason = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_PTDisabled = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_PTEnabled = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_StartDemRaw = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRun = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRunRaw = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehStrt = FALSE;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
#include "Rte_MemMap.h"


/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
VAR(Rte_ts_App1_Task_10ms_Core1_QM, RTE_VAR_NOINIT) Rte_App1_Task_10ms_Core1_QM;
VAR(Rte_ts_App1_Task_100ms_Core1_QM, RTE_VAR_NOINIT) Rte_App1_Task_100ms_Core1_QM;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_VAR_NO_INIT
#include "Rte_MemMap.h"


/*
************************************************************************************************************************
*    TxAck/ModeSwitchAck Flags
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Update Flags for each Receiver variables
************************************************************************************************************************
*/

#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
VAR(Rte_App1_Application_Core1_QM_TxUpdateFlagsType, RTE_VAR_INIT_NOCACHE) Rte_App1_Application_Core1_QM_TxUpdateFlags = {
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
};

#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    Timeout Flags for each Receiver variables
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Invalid Flags for each Receiver variables
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Never Received Flags for each external Rx Signal with handleNeverReceived != 0
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Definition of Per-Instance Memory variables
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Definition of Buffers for inter-runnable variables
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Data structures for mode management
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*    Definition of Rte functions
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint16_least num); 
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) RteBuff_PushRelease(P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC(void, RTE_CODE) RteBuff_PopRelease(P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteBuff_PopLock(P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteBuff_PushLock(P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteStack_Push(P2VAR(RteStackBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteStack_Pop(P2VAR(RteStackBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) Rte_MemSet(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, uint8 c, uint32 num);
FUNC(void, RTE_CODE) Rte_MoveFront(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) cPtr, uint32 bufferLength, uint32 moveLength);
FUNC(void, RTE_CODE) Rte_MoveBehind(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) cPtr, uint32 bufferLength, uint32 moveLength);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    Client Server API (Rte_Call)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    RTE_CALL Func
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*    COM-Callbacks for COM Invalid Notification
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    COM-Callbacks for DataSendCompletedEvent triggered runnables for transmission acknowledgement and error handling
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    COM Callbacks Function definition for Rx Update Notification
************************************************************************************************************************
*/



/*
************************************************************************************************************************
*    LdCom Callbacks Function definition for TX Trigger Transmit
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Definition of Internal/External Tx connections
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_BattPackNum_EV_BMSH_BattPackNum_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_BattPackNum_EV_BMSH_BattPackNum_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_BattSysNum_EV_BMSH_BattSysNum_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_BattSysNum_EV_BMSH_BattSysNum_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_BattTempAvg_EV_BMSH_BattTempAvg_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_BattTempAvg_EV_BMSH_BattTempAvg_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatIsoAlarm2_EV_BMSH_TBOX_BatIsoAlarm2_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatIsoAlarm2_EV_BMSH_TBOX_BatIsoAlarm2_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatLowSOC2_EV_BMSH_TBOX_BatLowSOC2_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatLowSOC2_EV_BMSH_TBOX_BatLowSOC2_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverCharge2_EV_BMSH_TBOX_BatOverCharge2_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverCharge2_EV_BMSH_TBOX_BatOverCharge2_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverSOC2_EV_BMSH_TBOX_BatOverSOC2_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverSOC2_EV_BMSH_TBOX_BatOverSOC2_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverTemp2_EV_BMSH_TBOX_BatOverTemp2_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverTemp2_EV_BMSH_TBOX_BatOverTemp2_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverVoltage2_EV_BMSH_TBOX_BatOverVoltage2_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverVoltage2_EV_BMSH_TBOX_BatOverVoltage2_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatTempUniformity2_EV_BMSH_TBOX_BatTempUniformity2_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatTempUniformity2_EV_BMSH_TBOX_BatTempUniformity2_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUnderVoltage2_EV_BMSH_TBOX_BatUnderVoltage2_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUnderVoltage2_EV_BMSH_TBOX_BatUnderVoltage2_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUniformity2_EV_BMSH_TBOX_BatUniformity2_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUniformity2_EV_BMSH_TBOX_BatUniformity2_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellA_ID_EV_BMSH_TBOX_CellA_ID_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellA_ID_EV_BMSH_TBOX_CellA_ID_EV = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellA_Volt_EV_BMSH_TBOX_CellA_Volt_EV(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellA_Volt_EV_BMSH_TBOX_CellA_Volt_EV = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellB_Volt_EV_BMSH_TBOX_CellB_Volt_EV(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellB_Volt_EV_BMSH_TBOX_CellB_Volt_EV = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellC_ID_EV_BMSH_TBOX_CellC_ID_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellC_ID_EV_BMSH_TBOX_CellC_ID_EV = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellC_Volt_EV_BMSH_TBOX_CellC_Volt_EV(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellC_Volt_EV_BMSH_TBOX_CellC_Volt_EV = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellOverVoltage2_EV_BMSH_TBOX_CellOverVoltage2_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellOverVoltage2_EV_BMSH_TBOX_CellOverVoltage2_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellUnderVoltage2_EV_BMSH_TBOX_CellUnderVoltage2_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellUnderVoltage2_EV_BMSH_TBOX_CellUnderVoltage2_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_FireAlarm_EV_BMSH_TBOX_FireAlarm_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_FireAlarm_EV_BMSH_TBOX_FireAlarm_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_SOCHop2_EV_BMSH_TBOX_SOCHop2_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_SOCHop2_EV_BMSH_TBOX_SOCHop2_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMS_DelayDataUpldEnb_EV_BMS_DelayDataUpldEnb_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_BMS_DelayDataUpldEnb_EV_BMS_DelayDataUpldEnb_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_IPU_HVBusCur_EV_IPU_HVBusCur_EV(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_IPU_HVBusCur_EV_IPU_HVBusCur_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_IPU_HVBusVolt_EV_IPU_HVBusVolt_EV(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_IPU_HVBusVolt_EV_IPU_HVBusVolt_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_IPU_HVBusVolt_IPUSts_IPU_HVBusVolt_IPUSts(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_IPU_HVBusVolt_IPUSts_IPU_HVBusVolt_IPUSts = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_IPU_MCUTempHighAlarm1_EV_IPU_MCUTempHighAlarm1_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_IPU_MCUTempHighAlarm1_EV_IPU_MCUTempHighAlarm1_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_IPU_MotorOverCurrFlt_EV_IPU_MotorOverCurrFlt_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_IPU_MotorOverCurrFlt_EV_IPU_MotorOverCurrFlt_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_IPU_MotorOverSpdFlt_EV_IPU_MotorOverSpdFlt_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_IPU_MotorOverSpdFlt_EV_IPU_MotorOverSpdFlt_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_IPU_MotorTempHighFault1_EV_IPU_MotorTempHighFault1_EV(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EVPT_XCUInterFace_Map_IPU_MotorTempHighFault1_EV_IPU_MotorTempHighFault1_EV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_ECU_Fun_Config_Data1_ECU_Fun_Config_Data1(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_ECU_Fun_Config_Data1_ECU_Fun_Config_Data1 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_ECU_Fun_Config_Data2_ECU_Fun_Config_Data2(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_ECU_Fun_Config_Data2_ECU_Fun_Config_Data2 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_ECU_Net_Config_Data1_ECU_Net_Config_Data1(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_ECU_Net_Config_Data1_ECU_Net_Config_Data1 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_ECU_Net_Config_Data2_ECU_Net_Config_Data2(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_ECU_Net_Config_Data2_ECU_Net_Config_Data2 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_EXT_DO_RELAY_LS_10_Fb_EXT_DO_RELAY_LS_10_Fb(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_EXT_DO_RELAY_LS_10_Fb_EXT_DO_RELAY_LS_10_Fb = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_EXT_DO_RELAY_LS_7_Fb_EXT_DO_RELAY_LS_7_Fb(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_EXT_DO_RELAY_LS_7_Fb_EXT_DO_RELAY_LS_7_Fb = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_EXT_DO_RELAY_LS_9_Fb_EXT_DO_RELAY_LS_9_Fb(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_EXT_DO_RELAY_LS_9_Fb_EXT_DO_RELAY_LS_9_Fb = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte0_F190_VIN_Byte0(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F190_VIN_Byte0_F190_VIN_Byte0 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte1_F190_VIN_Byte1(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F190_VIN_Byte1_F190_VIN_Byte1 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte10_F190_VIN_Byte10(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F190_VIN_Byte10_F190_VIN_Byte10 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte11_F190_VIN_Byte11(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F190_VIN_Byte11_F190_VIN_Byte11 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte12_F190_VIN_Byte12(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F190_VIN_Byte12_F190_VIN_Byte12 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte13_F190_VIN_Byte13(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F190_VIN_Byte13_F190_VIN_Byte13 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte14_F190_VIN_Byte14(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F190_VIN_Byte14_F190_VIN_Byte14 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte15_F190_VIN_Byte15(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F190_VIN_Byte15_F190_VIN_Byte15 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte16_F190_VIN_Byte16(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F190_VIN_Byte16_F190_VIN_Byte16 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte2_F190_VIN_Byte2(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F190_VIN_Byte2_F190_VIN_Byte2 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte3_F190_VIN_Byte3(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F190_VIN_Byte3_F190_VIN_Byte3 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte4_F190_VIN_Byte4(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F190_VIN_Byte4_F190_VIN_Byte4 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte5_F190_VIN_Byte5(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F190_VIN_Byte5_F190_VIN_Byte5 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte6_F190_VIN_Byte6(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F190_VIN_Byte6_F190_VIN_Byte6 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte7_F190_VIN_Byte7(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F190_VIN_Byte7_F190_VIN_Byte7 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte8_F190_VIN_Byte8(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F190_VIN_Byte8_F190_VIN_Byte8 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte9_F190_VIN_Byte9(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F190_VIN_Byte9_F190_VIN_Byte9 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte2_F193_ECUHardwareVersionNumber_Byte2(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte2_F193_ECUHardwareVersionNumber_Byte2 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte3_F193_ECUHardwareVersionNumber_Byte3(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte3_F193_ECUHardwareVersionNumber_Byte3 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte4_F193_ECUHardwareVersionNumber_Byte4(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte4_F193_ECUHardwareVersionNumber_Byte4 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte6_F193_ECUHardwareVersionNumber_Byte6(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte6_F193_ECUHardwareVersionNumber_Byte6 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte7_F193_ECUHardwareVersionNumber_Byte7(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte7_F193_ECUHardwareVersionNumber_Byte7 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte8_F193_ECUHardwareVersionNumber_Byte8(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte8_F193_ECUHardwareVersionNumber_Byte8 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte2_F195_ECUSoftwareVersionNumber_Byte2(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte2_F195_ECUSoftwareVersionNumber_Byte2 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte3_F195_ECUSoftwareVersionNumber_Byte3(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte3_F195_ECUSoftwareVersionNumber_Byte3 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte4_F195_ECUSoftwareVersionNumber_Byte4(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte4_F195_ECUSoftwareVersionNumber_Byte4 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte6_F195_ECUSoftwareVersionNumber_Byte6(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte6_F195_ECUSoftwareVersionNumber_Byte6 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte7_F195_ECUSoftwareVersionNumber_Byte7(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte7_F195_ECUSoftwareVersionNumber_Byte7 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte8_F195_ECUSoftwareVersionNumber_Byte8(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte8_F195_ECUSoftwareVersionNumber_Byte8 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_PDCStatus_AlvCtrErrFlg_PDCStatus_AlvCtrErrFlg(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_PDCStatus_AlvCtrErrFlg_PDCStatus_AlvCtrErrFlg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_PDC_Status_CsmErrFlg_PDC_Status_CsmErrFlg(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_PDC_Status_CsmErrFlg_PDC_Status_CsmErrFlg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_PMS_SWCompileDay_PMS_SWCompileDay(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_BswAswRte_PMS_SWCompileDay_PMS_SWCompileDay = *(&data);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_PMS_BswAswRte_PMS_SWCompileDay_PMS_SWCompileDay = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_PMS_SWCompileMonth_PMS_SWCompileMonth(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_BswAswRte_PMS_SWCompileMonth_PMS_SWCompileMonth = *(&data);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_PMS_BswAswRte_PMS_SWCompileMonth_PMS_SWCompileMonth = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_PMS_SWCompileYear_PMS_SWCompileYear(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_BswAswRte_PMS_SWCompileYear_PMS_SWCompileYear = *(&data);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_PMS_BswAswRte_PMS_SWCompileYear_PMS_SWCompileYear = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_s2vd_BMS_PmtCutoffLVFb_s2vd_BMS_PmtCutoffLVFb(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_s2vd_BMS_PmtCutoffLVFb_s2vd_BMS_PmtCutoffLVFb = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_adcCanBusOff_vild_b_adcCanBusOff(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_adcCanBusOff_vild_b_adcCanBusOff = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_evCanBusOff_vild_b_evCanBusOff(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_evCanBusOff_vild_b_evCanBusOff = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgABSMsgErr_vild_b_flgABSMsgErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgABSMsgErr_vild_b_flgABSMsgErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgABSSpdMsgErr_vild_b_flgABSSpdMsgErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgABSSpdMsgErr_vild_b_flgABSSpdMsgErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgACUAlvCtrErr_vild_b_flgACUAlvCtrErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgACUAlvCtrErr_vild_b_flgACUAlvCtrErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgACUCsmErr_vild_b_flgACUCsmErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgACUCsmErr_vild_b_flgACUCsmErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgACUMsgErr_vild_b_flgACUMsgErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgACUMsgErr_vild_b_flgACUMsgErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgBBMMsgErr_vild_b_flgBBMMsgErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgBBMMsgErr_vild_b_flgBBMMsgErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgBMSAlvCtrErr_vild_b_flgBMSAlvCtrErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgBMSAlvCtrErr_vild_b_flgBMSAlvCtrErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgBMSCsmErr_vild_b_flgBMSCsmErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgBMSCsmErr_vild_b_flgBMSCsmErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgBMSMsgErr_vild_b_flgBMSMsgErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgBMSMsgErr_vild_b_flgBMSMsgErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgCSMAlvCtrErr_vild_b_flgCSMAlvCtrErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgCSMAlvCtrErr_vild_b_flgCSMAlvCtrErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgCSMCsmErr_vild_b_flgCSMCsmErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgCSMCsmErr_vild_b_flgCSMCsmErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgCSMMsgErr_vild_b_flgCSMMsgErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgCSMMsgErr_vild_b_flgCSMMsgErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgClearDTC_vild_b_flgClearDTC(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgClearDTC_vild_b_flgClearDTC = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgDCDCMsgErr_vild_b_flgDCDCMsgErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgDCDCMsgErr_vild_b_flgDCDCMsgErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgEGSMAlvCtrErr_vild_b_flgEGSMAlvCtrErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgEGSMAlvCtrErr_vild_b_flgEGSMAlvCtrErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgEGSMCsmErr_vild_b_flgEGSMCsmErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgEGSMCsmErr_vild_b_flgEGSMCsmErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgEGSMMsgErr_vild_b_flgEGSMMsgErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgEGSMMsgErr_vild_b_flgEGSMMsgErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgEHBAlvCtrErr_vild_b_flgEHBAlvCtrErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgEHBAlvCtrErr_vild_b_flgEHBAlvCtrErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgEHBCsmErr_vild_b_flgEHBCsmErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgEHBCsmErr_vild_b_flgEHBCsmErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgIPUAlvCtrErr_vild_b_flgIPUAlvCtrErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgIPUAlvCtrErr_vild_b_flgIPUAlvCtrErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgIPUCsmErr_vild_b_flgIPUCsmErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgIPUCsmErr_vild_b_flgIPUCsmErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgMCUMsgErr_vild_b_flgMCUMsgErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgMCUMsgErr_vild_b_flgMCUMsgErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_pmsCanBusOff_vild_b_pmsCanBusOff(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_BswAswRte_vild_b_pmsCanBusOff_vild_b_pmsCanBusOff = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AI_BATTERY_TEMPH_5_EXT_AI_BATTERY_TEMPH_5(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_AI_BATTERY_TEMPH_5_EXT_AI_BATTERY_TEMPH_5 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AI_BATTERY_TEMPH_6_EXT_AI_BATTERY_TEMPH_6(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_AI_BATTERY_TEMPH_6_EXT_AI_BATTERY_TEMPH_6 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AI_MID_COOLING_TEMPH_8_EXT_AI_MID_COOLING_TEMPH_8(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_AI_MID_COOLING_TEMPH_8_EXT_AI_MID_COOLING_TEMPH_8 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AI_SENSOR_1_EXT_AI_SENSOR_1(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_AI_SENSOR_1_EXT_AI_SENSOR_1 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AI_SENSOR_2_EXT_AI_SENSOR_2(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_AI_SENSOR_2_EXT_AI_SENSOR_2 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AI_SENSOR_6_EXT_AI_SENSOR_6(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_AI_SENSOR_6_EXT_AI_SENSOR_6 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AI_SWITCH_1_EXT_AI_SWITCH_1(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_AI_SWITCH_1_EXT_AI_SWITCH_1 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AO_LDO_5V_02_EXT_AO_LDO_5V_02(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_AO_LDO_5V_02_EXT_AO_LDO_5V_02 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AO_TRACKING_5V_01_EXT_AO_TRACKING_5V_01(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_AO_TRACKING_5V_01_EXT_AO_TRACKING_5V_01 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AO_TRACKING_5V_02_EXT_AO_TRACKING_5V_02(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_AO_TRACKING_5V_02_EXT_AO_TRACKING_5V_02 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_CHARGE_ON_AI_EXT_CHARGE_ON_AI(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_CHARGE_ON_AI_EXT_CHARGE_ON_AI = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_DI_HS_04_EXT_DI_HS_04(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_DI_HS_04_EXT_DI_HS_04 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_DI_HS_05_EXT_DI_HS_05(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_DI_HS_05_EXT_DI_HS_05 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_DI_HS_06_EXT_DI_HS_06(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_DI_HS_06_EXT_DI_HS_06 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_DI_HS_07_EXT_DI_HS_07(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_DI_HS_07_EXT_DI_HS_07 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_DI_HS_08_EXT_DI_HS_08(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_DI_HS_08_EXT_DI_HS_08 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_DI_HS_10_EXT_DI_HS_10(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_DI_HS_10_EXT_DI_HS_10 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_IGN_ON_AI_EXT_IGN_ON_AI(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_IGN_ON_AI_EXT_IGN_ON_AI = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_IGN_ON_DI_EXT_IGN_ON_DI(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_IGN_ON_DI_EXT_IGN_ON_DI = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_PI_HVIL_1_DutyCycle_EXT_PI_HVIL_1_DutyCycle(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_PI_HVIL_1_DutyCycle_EXT_PI_HVIL_1_DutyCycle = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_PI_HVIL_1_Period_EXT_PI_HVIL_1_Period(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_PI_HVIL_1_Period_EXT_PI_HVIL_1_Period = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_PI_HVIL_2_DutyCycle_EXT_PI_HVIL_2_DutyCycle(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_PI_HVIL_2_DutyCycle_EXT_PI_HVIL_2_DutyCycle = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_PI_HVIL_2_Period_EXT_PI_HVIL_2_Period(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_PI_HVIL_2_Period_EXT_PI_HVIL_2_Period = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_PI_PWM_1_DutyCycle_EXT_PI_PWM_1_DutyCycle(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_PI_PWM_1_DutyCycle_EXT_PI_PWM_1_DutyCycle = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_PI_PWM_1_Period_EXT_PI_PWM_1_Period(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_PI_PWM_1_Period_EXT_PI_PWM_1_Period = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_PI_PWM_2_DutyCycle_EXT_PI_PWM_2_DutyCycle(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_PI_PWM_2_DutyCycle_EXT_PI_PWM_2_DutyCycle = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_PI_PWM_2_Period_EXT_PI_PWM_2_Period(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_EXT_PI_PWM_2_Period_EXT_PI_PWM_2_Period = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_KL30_KL30(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PMS_HWI_KL30_KL30 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SCOO_vcsb_SCOO_vsld_v_vehMaxSpd_kph(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SCOO_vcsb_SCOO_vsld_v_vehMaxSpd_kph = *(&data);

    return ret;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    Definition of Internal/External Rx connections
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_BattPackNum_BMSH_BattPackNum(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_BattPackNum_BMSH_BattPackNum;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_BattSysNum_BMSH_BattSysNum(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_BattSysNum_BMSH_BattSysNum;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_BattTempAvg_BMSH_BattTempAvg(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_BattTempAvg_BMSH_BattTempAvg;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt(P2VAR(UInt16, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt(P2VAR(UInt16, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt(P2VAR(UInt16, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_IPU_HVBusCur_IPU_HVBusCur(P2VAR(UInt16, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComTx_CAN_IPU_HVBusCur_IPU_HVBusCur;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_IPU_HVBusVolt_20_IPU_HVBusVolt_20(P2VAR(UInt16, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComTx_CAN_IPU_HVBusVolt_20_IPU_HVBusVolt_20;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_IPU_HVBusVolt_500_IPU_HVBusVolt_500(P2VAR(UInt16, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComTx_CAN_IPU_HVBusVolt_500_IPU_HVBusVolt_500;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComTx_CAN_IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComTx_CAN_IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComTx_CAN_IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_IPU_MotorTempHighFault1_IPU_MotorTempHighFault1(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComTx_CAN_IPU_MotorTempHighFault1_IPU_MotorTempHighFault1;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_AC_ACCM_ActPower_AC_ACCM_ActPower(P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt8)Rte_ComBuffer_AC_ACCM_ActPower_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_BMSH_SelfCheckFault_BMSH_SelfCheckFault(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_SelfCheckFault_BMSH_SelfCheckFault;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_CSM_V2XDchaSwtInvalid_CSM_V2XDchaSwtInvalid(P2VAR(boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (Boolean)Rte_ComBuffer_CSM_V2XDchaSwtInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_DCDC_SelfChkSts_DCDC_SelfChkSts(P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt8)Rte_ComBuffer_DCDC_SelfChkSts_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_EHB_EPBStatus_EHB_EPBStatus(P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt8)Rte_ComBuffer_EHB_EPBStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_EXT_IGN_ON_DI_EXT_IGN_ON_DI(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_PMS_HWI_EXT_IGN_ON_DI_EXT_IGN_ON_DI;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_IPU_SelfChkSts_IPU_SelfChkSts(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComTx_CAN_IPU_SelfChkSts_IPU_SelfChkSts;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PEPS_PowerMode_PEPS_PowerMode(P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt8)Rte_ComBuffer_PEPS_PowerMode_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_ACCMEnable_PMS_ACCMEnable(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_ACCMEnable_PMS_ACCMEnable;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_BatteryVol_PMS_BatteryVol(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_BatteryVol_PMS_BatteryVol;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_Brake1Switch_PMS_Brake1Switch(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_Brake1Switch_PMS_Brake1Switch;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_Brake2Switch_PMS_Brake2Switch(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_Brake2Switch_PMS_Brake2Switch;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_CPSREn_PMS_CPSREn(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_CPSREn_PMS_CPSREn;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_CurrentGearPosition_PMS_CurrentGearPosition(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_CurrentGearPosition_PMS_CurrentGearPosition;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_DcDcActvdReq_PMS_DcDcActvdReq(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_DcDcActvdReq_PMS_DcDcActvdReq;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_DriveModeInd_PMS_DriveModeInd(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_DriveModeInd_PMS_DriveModeInd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_FunLockVehActive_PMS_FunLockVehActive(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_FunLockVehActive_PMS_FunLockVehActive;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_HVIL1Sts_PMS_HVIL1Sts(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_HVIL1Sts_PMS_HVIL1Sts;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_HVIL2Sts_PMS_HVIL2Sts(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_HVIL2Sts_PMS_HVIL2Sts;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer(P2VAR(UInt32, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_IgnONSts_PMS_IgnONSts(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_IgnONSts_PMS_IgnONSts;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_IsgModReq_PMS_IsgModReq(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_IsgModReq_PMS_IsgModReq;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_IsgTqReq_PMS_IsgTqReq(P2VAR(UInt16, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_IsgTqReq_PMS_IsgTqReq;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_PTC2Enable_PMS_PTC2Enable(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_PTC2Enable_PMS_PTC2Enable;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_PTC3Enable_PMS_PTC3Enable(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_PTC3Enable_PMS_PTC3Enable;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_PTCEnable_PMS_PTCEnable(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_PTCEnable_PMS_PTCEnable;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd(P2VAR(UInt16, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_Real_PedalPosition_PMS_Real_PedalPosition(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_Real_PedalPosition_PMS_Real_PedalPosition;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_SelfCheckSts_PMS_SelfCheckSts(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_SelfCheckSts_PMS_SelfCheckSts;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_VehicleSpeed_PMS_VehicleSpeed(P2VAR(UInt16, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_VehicleSpeed_PMS_VehicleSpeed;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_PMS_ePTReady_PMS_ePTReady(P2VAR(Boolean, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_ePTReady_PMS_ePTReady;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq(P2VAR(UInt8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_DID_VCU_Odometerbackup_VCU_Odometerbackup(P2VAR(UInt16, AUTOMATIC, RTE_PMS_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_VCU_Odometerbackup_VCU_Odometerbackup;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_HVIL_1_DutyCycle_EXT_PO_HVIL_1_DutyCycle(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_PO_HVIL_1_DutyCycle_EXT_PO_HVIL_1_DutyCycle;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_HVIL_1_Period_EXT_PO_HVIL_1_Period(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_PO_HVIL_1_Period_EXT_PO_HVIL_1_Period;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_HVIL_2_DutyCycle_EXT_PO_HVIL_2_DutyCycle(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_PO_HVIL_2_DutyCycle_EXT_PO_HVIL_2_DutyCycle;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_HVIL_2_Period_EXT_PO_HVIL_2_Period(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_PO_HVIL_2_Period_EXT_PO_HVIL_2_Period;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_PWM_1_DutyCycle_EXT_PO_PWM_1_DutyCycle(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_PO_PWM_1_DutyCycle_EXT_PO_PWM_1_DutyCycle;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_PWM_1_Period_EXT_PO_PWM_1_Period(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_PO_PWM_1_Period_EXT_PO_PWM_1_Period;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_PWM_2_DutyCycle_EXT_PO_PWM_2_DutyCycle(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_PO_PWM_2_DutyCycle_EXT_PO_PWM_2_DutyCycle;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_PWM_2_Period_EXT_PO_PWM_2_Period(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_PO_PWM_2_Period_EXT_PO_PWM_2_Period;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_PWM_4_DutyCycle_EXT_PO_PWM_4_DutyCycle(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_PO_PWM_4_DutyCycle_EXT_PO_PWM_4_DutyCycle;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_PWM_4_Period_EXT_PO_PWM_4_Period(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_EXT_PO_PWM_4_Period_EXT_PO_PWM_4_Period;
    return ret;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
  
/*
************************************************************************************************************************
*    Inter-runnable variable access
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Definition of Rte_Invalidate_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Transmission/Mode Switch Acknowledgement handling (Rte_Feedback/Rte_SwitchAck)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Runnable Entities for Nv Block Components
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Task bodies for RTE controlled tasks
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
TASK(SWC_Init_Task_Core1)
{
    Core1_Runnable_Task_Init();

    PMS_BswAswRte_Init();

    EVPT_XCUInterFace_Map_Init();

    PMS_HWI_Init();

    PMS_HWO_Init();

    swc_ATAU_Init();

    swc_DIAG_Init();

    swc_EGYM_Init();

    swc_HMIF_Init();

    swc_MEST_Init();

    swc_OGVL_Init();

    swc_RMLK_Init();

    swc_SCAP_Init();

    swc_SCOO_Init();

    swc_TCOO_Init();

    swc_THSM_Init();

    swc_VCIP_Init();

    swc_VCOP_Init();

    swc_VOMM_Init();

    swc_HVSM_Init();

    swc_AUXC_Init();

    (void)TerminateTask();
}

TASK(App1_Task_1ms_Core1_QM)
{
    Core1_Runnable_App_1ms();

    (void)TerminateTask();
}

TASK(App1_Task_5ms_Core1_QM)
{
    Core1_Runnable_App_5ms();

    (void)TerminateTask();
}

TASK(App1_Task_10ms_Core1_QM)
{
    Core1_Runnable_App_10ms();

    EVPT_XCUInterFace_Map_Runnable();

    PMS_BswAswRte_Step();

    PMS_HWI_Step();

    PMS_HWO_Step();

    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_ATAU_swc_ATAU_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value) = Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
    swc_ATAU_Step();
    Rte_swc_ATAU_vcsb_ATAU_pmmd_b_ePTRelease_flg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_ATAU_swc_ATAU_Step.Rte_vcsb_ATAU_pmmd_b_ePTRelease_flg.value);
    Rte_swc_ATAU_vcsb_ATAU_pmmd_e_authenticationStatus = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_ATAU_swc_ATAU_Step.Rte_vcsb_ATAU_pmmd_e_authenticationStatus.value);

    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_cesd_b_crash.value) = Rte_swc_VCIP_vcib_VCIP_cesd_b_crash;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_eadd_e_inv2FltSts.value) = Rte_swc_VCIP_vcib_VCIP_eadd_e_inv2FltSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_hvbd_b_hvilOpen.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvilOpen;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_macd_u_batIntSmpl_V.value) = Rte_swc_VCIP_vcib_VCIP_macd_u_batIntSmpl_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_obcd_b_obcWakeUp.value) = Rte_swc_VCIP_vcib_VCIP_obcd_b_obcWakeUp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value) = Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_b_brkSwt1Actv.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_brkSwt1Actv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_b_brkSwt2Actv.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_brkSwt2Actv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_b_flgFctCfgACU.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgACU;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_b_flgNetConfgABS.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_flgNetConfgABS;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_pct_WatPmpEP1FbPWM.value) = Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP1FbPWM;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_pct_WatPmpEP2FbPWM.value) = Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP2FbPWM;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_st_bmsDlyDataUpldEnb.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_bmsDlyDataUpldEnb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_st_hvbDischgFltReq.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDischgFltReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_st_hvbStsDischgFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStsDischgFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_u_5VT1IntSmpl_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_5VT1IntSmpl_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_u_5VT2IntSmpl_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_5VT2IntSmpl_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_u_Acc1Raw_mV.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_Acc1Raw_mV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_u_Acc2Raw_mV.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_Acc2Raw_mV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value) = Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_AUXC_brpd_b_VacPumpEnOvrTmHiPreFlt.value) = Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpEnOvrTmHiPreFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_AUXC_brpd_b_VacPumpEnOvrTmLoPreFlt.value) = Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpEnOvrTmLoPreFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_AUXC_brpd_b_VacPumpLoPreFlt.value) = Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpLoPreFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_AUXC_brpd_b_VacPumpRlyFlt.value) = Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpRlyFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_AUXC_brpd_b_VacPumpSnrFlt.value) = Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpSnrFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_AUXC_brpd_b_VacPumpSysFailFlt.value) = Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpSysFailFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_HVSM_hvbd_e_PmmStatus.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_adcCanBusOff_vild_b_adcCanBusOff.value) = Rte_PMS_BswAswRte_vild_b_adcCanBusOff_vild_b_adcCanBusOff;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_evCanBusOff_vild_b_evCanBusOff.value) = Rte_PMS_BswAswRte_vild_b_evCanBusOff_vild_b_evCanBusOff;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgABSMsgErr_vild_b_flgABSMsgErr.value) = Rte_PMS_BswAswRte_vild_b_flgABSMsgErr_vild_b_flgABSMsgErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgABSSpdMsgErr_vild_b_flgABSSpdMsgErr.value) = Rte_PMS_BswAswRte_vild_b_flgABSSpdMsgErr_vild_b_flgABSSpdMsgErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgACUAlvCtrErr_vild_b_flgACUAlvCtrErr.value) = Rte_PMS_BswAswRte_vild_b_flgACUAlvCtrErr_vild_b_flgACUAlvCtrErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgACUCsmErr_vild_b_flgACUCsmErr.value) = Rte_PMS_BswAswRte_vild_b_flgACUCsmErr_vild_b_flgACUCsmErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgACUMsgErr_vild_b_flgACUMsgErr.value) = Rte_PMS_BswAswRte_vild_b_flgACUMsgErr_vild_b_flgACUMsgErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgBMSAlvCtrErr_vild_b_flgBMSAlvCtrErr.value) = Rte_PMS_BswAswRte_vild_b_flgBMSAlvCtrErr_vild_b_flgBMSAlvCtrErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgBMSCsmErr_vild_b_flgBMSCsmErr.value) = Rte_PMS_BswAswRte_vild_b_flgBMSCsmErr_vild_b_flgBMSCsmErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgBMSMsgErr_vild_b_flgBMSMsgErr.value) = Rte_PMS_BswAswRte_vild_b_flgBMSMsgErr_vild_b_flgBMSMsgErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgCSMAlvCtrErr_vild_b_flgCSMAlvCtrErr.value) = Rte_PMS_BswAswRte_vild_b_flgCSMAlvCtrErr_vild_b_flgCSMAlvCtrErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgCSMCsmErr_vild_b_flgCSMCsmErr.value) = Rte_PMS_BswAswRte_vild_b_flgCSMCsmErr_vild_b_flgCSMCsmErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgCSMMsgErr_vild_b_flgCSMMsgErr.value) = Rte_PMS_BswAswRte_vild_b_flgCSMMsgErr_vild_b_flgCSMMsgErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgClearDTC_vild_b_flgClearDTC.value) = Rte_PMS_BswAswRte_vild_b_flgClearDTC_vild_b_flgClearDTC;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgDCDCMsgErr_vild_b_flgDCDCMsgErr.value) = Rte_PMS_BswAswRte_vild_b_flgDCDCMsgErr_vild_b_flgDCDCMsgErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgEGSMAlvCtrErr_vild_b_flgEGSMAlvCtrErr.value) = Rte_PMS_BswAswRte_vild_b_flgEGSMAlvCtrErr_vild_b_flgEGSMAlvCtrErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgEGSMCsmErr_vild_b_flgEGSMCsmErr.value) = Rte_PMS_BswAswRte_vild_b_flgEGSMCsmErr_vild_b_flgEGSMCsmErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgEGSMMsgErr_vild_b_flgEGSMMsgErr.value) = Rte_PMS_BswAswRte_vild_b_flgEGSMMsgErr_vild_b_flgEGSMMsgErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgEHBAlvCtrErr_vild_b_flgEHBAlvCtrErr.value) = Rte_PMS_BswAswRte_vild_b_flgEHBAlvCtrErr_vild_b_flgEHBAlvCtrErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgEHBCsmErr_vild_b_flgEHBCsmErr.value) = Rte_PMS_BswAswRte_vild_b_flgEHBCsmErr_vild_b_flgEHBCsmErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgIPUAlvCtrErr_vild_b_flgIPUAlvCtrErr.value) = Rte_PMS_BswAswRte_vild_b_flgIPUAlvCtrErr_vild_b_flgIPUAlvCtrErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgIPUCsmErr_vild_b_flgIPUCsmErr.value) = Rte_PMS_BswAswRte_vild_b_flgIPUCsmErr_vild_b_flgIPUCsmErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgMCUMsgErr_vild_b_flgMCUMsgErr.value) = Rte_PMS_BswAswRte_vild_b_flgMCUMsgErr_vild_b_flgMCUMsgErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr.value) = Rte_PMS_BswAswRte_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr.value) = Rte_PMS_BswAswRte_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr.value) = Rte_PMS_BswAswRte_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_pmsCanBusOff_vild_b_pmsCanBusOff.value) = Rte_PMS_BswAswRte_vild_b_pmsCanBusOff_vild_b_pmsCanBusOff;
    swc_DIAG_Step();
    Rte_swc_DIAG_vcsb_DIAG_acpd_b_accPed1Vld = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_acpd_b_accPed1Vld.value);
    Rte_swc_DIAG_vcsb_DIAG_acpd_b_accPed2Vld = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_acpd_b_accPed2Vld.value);
    Rte_swc_DIAG_vcsb_DIAG_brpd_b_brkSwtMismatch = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_brpd_b_brkSwtMismatch.value);
    Rte_swc_DIAG_vcsb_DIAG_ddid_b_bmsMsgErr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_ddid_b_bmsMsgErr.value);
    Rte_swc_DIAG_vcsb_DIAG_ddid_b_egsmMsgErr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_ddid_b_egsmMsgErr.value);
    Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl1Flt_flg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl1Flt_flg.value);
    Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl21Flt_flg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl21Flt_flg.value);
    Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl22Flt_flg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl22Flt_flg.value);
    Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl23Flt_flg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl23Flt_flg.value);
    Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl31Flt_flg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl31Flt_flg.value);
    Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl32Flt_flg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl32Flt_flg.value);
    Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl33Flt_flg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl33Flt_flg.value);
    Rte_swc_DIAG_vcsb_DIAG_digd_b_bmsFltLv4A = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_bmsFltLv4A.value);
    Rte_swc_DIAG_vcsb_DIAG_digd_b_mcuFltLv2A = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_mcuFltLv2A.value);
    Rte_swc_DIAG_vcsb_DIAG_digd_b_mcuFltLv3A = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_mcuFltLv3A.value);
    Rte_swc_DIAG_vcsb_DIAG_digd_b_mcuMsgErr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_mcuMsgErr.value);
    Rte_swc_DIAG_vcsb_DIAG_digd_b_vcuVehLvl1Flt_flg_BRP = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_vcuVehLvl1Flt_flg_BRP.value);
    Rte_swc_DIAG_vcsb_DIAG_digd_b_vcuVehLvl22Flt_flg_BRP = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_vcuVehLvl22Flt_flg_BRP.value);
    Rte_swc_DIAG_vcsb_DIAG_digd_b_vehCrashFltLvl33 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_vehCrashFltLvl33.value);
    Rte_swc_DIAG_vcsb_DIAG_digd_st_edcpFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_st_edcpFlt.value);
    Rte_swc_DIAG_vcsb_DIAG_digd_st_hbcpFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_st_hbcpFlt.value);
    Rte_swc_DIAG_vcsb_DIAG_digd_st_vehSysErrLevel = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_st_vehSysErrLevel.value);
    Rte_swc_DIAG_vcsb_DIAG_macd_b_EVCANBusoff31Err = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_macd_b_EVCANBusoff31Err.value);
    Rte_swc_DIAG_vcsb_DIAG_macd_b_EVCANBusoffDebd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_macd_b_EVCANBusoffDebd.value);

    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_accd_st_airCmprSt.value) = Rte_swc_VCIP_vcib_VCIP_accd_st_airCmprSt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_accd_st_iptWorkSt.value) = Rte_swc_VCIP_vcib_VCIP_accd_st_iptWorkSt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_dccd_e_24vDcdcModAct.value) = Rte_swc_VCIP_vcib_VCIP_dccd_e_24vDcdcModAct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_dccd_pwr_dcdcHVpwr_kW.value) = Rte_swc_VCIP_vcib_VCIP_dccd_pwr_dcdcHVpwr_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_hvbd_e_hvbMaiRlyPos.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMaiRlyPos;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_hvbd_pwr_PeakDischMax_kW.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_PeakDischMax_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_hvbd_st_hcmMaiRlyNeg.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_st_hcmMaiRlyNeg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_obcd_pwr_obcOutpt_kW.value) = Rte_swc_VCIP_vcib_VCIP_obcd_pwr_obcOutpt_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_obcd_pwr_obcRlTmOutpt_kW.value) = Rte_swc_VCIP_vcib_VCIP_obcd_pwr_obcRlTmOutpt_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_b_flgFctCfgMaxChgCurr.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgMaxChgCurr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_b_hvbZeroPwrReq.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_hvbZeroPwrReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_i_hvbDCChgCurReq_A.value) = Rte_swc_VCIP_vcib_VCIP_vild_i_hvbDCChgCurReq_A;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_pct_tboxAlwChgCurrMax.value) = Rte_swc_VCIP_vcib_VCIP_vild_pct_tboxAlwChgCurrMax;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_pct_tboxChgDepth.value) = Rte_swc_VCIP_vcib_VCIP_vild_pct_tboxChgDepth;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_pwr_PTCActPwr_kW.value) = Rte_swc_VCIP_vcib_VCIP_vild_pwr_PTCActPwr_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_pwr_acwpHeatPower_kW.value) = Rte_swc_VCIP_vcib_VCIP_vild_pwr_acwpHeatPower_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_pwr_airCmprAct_kW.value) = Rte_swc_VCIP_vcib_VCIP_vild_pwr_airCmprAct_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_pwr_iptActPwr_kW.value) = Rte_swc_VCIP_vcib_VCIP_vild_pwr_iptActPwr_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_pwr_ptcActPwrRear_kW.value) = Rte_swc_VCIP_vcib_VCIP_vild_pwr_ptcActPwrRear_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_st_actWorkSts1.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_actWorkSts1;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_st_flg2FctCfgVehTyp.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flg2FctCfgVehTyp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehTyp.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehTyp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_st_hcmAccConnStsFb.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hcmAccConnStsFb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_st_hcmPtcDefRlyStFb.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hcmPtcDefRlyStFb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_st_hvbDCChgProcss.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgProcss;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_st_obcChgSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_obcChgSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_st_ptcConnStsFb.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_ptcConnStsFb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_st_tboxChgLmtSw.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_tboxChgLmtSw;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_u_hvbVolt_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_hvbVolt_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_HVSM_bmsd_e_modeTgt.value) = Rte_swc_HVSM_vcsb_HVSM_bmsd_e_modeTgt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_HVSM_hvbd_b_accyWrkEnCmd.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyWrkEnCmd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_HVSM_hvbd_b_dchaOn.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_dchaOn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_THSM_thmd_b_heaterEna.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_THSM_thmd_b_heaterEna2.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_THSM_thmd_b_heaterEna3HW.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna3HW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_THSM_thmd_st_acwpHeat.value) = Rte_swc_THSM_vcsb_THSM_thmd_st_acwpHeat;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_THSM_thmd_st_ptcConnStsFb.value) = Rte_swc_THSM_vcsb_THSM_thmd_st_ptcConnStsFb;
    swc_EGYM_Step();
    Rte_swc_EGYM_vcsb_EGYM_accd_pwr_hvAttpwr_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_accd_pwr_hvAttpwr_kW.value);
    Rte_swc_EGYM_vcsb_EGYM_accd_pwr_maxPwrLim_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_accd_pwr_maxPwrLim_kW.value);
    Rte_swc_EGYM_vcsb_EGYM_accd_pwr_minPwrLim_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_accd_pwr_minPwrLim_kW.value);
    Rte_swc_EGYM_vcsb_EGYM_egmd_b_acEnbAllowFlg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_acEnbAllowFlg.value);
    Rte_swc_EGYM_vcsb_EGYM_egmd_b_accyEnbFlg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_accyEnbFlg.value);
    Rte_swc_EGYM_vcsb_EGYM_egmd_b_dcdcEnbAllowFlg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_dcdcEnbAllowFlg.value);
    Rte_swc_EGYM_vcsb_EGYM_egmd_b_mcuEnbFlg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_mcuEnbFlg.value);
    Rte_swc_EGYM_vcsb_EGYM_egmd_b_obcEnbAllowFlg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_obcEnbAllowFlg.value);
    Rte_swc_EGYM_vcsb_EGYM_egmd_b_ptcEnbAllowFlg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_ptcEnbAllowFlg.value);
    Rte_swc_EGYM_vcsb_EGYM_egmd_b_ptcRearEnbAllowFlg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_ptcRearEnbAllowFlg.value);
    Rte_swc_EGYM_vcsb_EGYM_egmd_b_zeroPwrFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_zeroPwrFb.value);
    Rte_swc_EGYM_vcsb_EGYM_egmd_i_bmshAlwChgCurrMax = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_i_bmshAlwChgCurrMax.value);
    Rte_swc_EGYM_vcsb_EGYM_egmd_pct_vcuChgDepReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_pct_vcuChgDepReq.value);
    Rte_swc_EGYM_vcsb_EGYM_egmd_pwr_accmHvClPwrAllwd_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_pwr_accmHvClPwrAllwd_kW.value);
    Rte_swc_EGYM_vcsb_EGYM_egmd_pwr_acwpHeatPwrCnsAllwd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_pwr_acwpHeatPwrCnsAllwd.value);
    Rte_swc_EGYM_vcsb_EGYM_egmd_pwr_ptcHvHtPwrAllwd_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_pwr_ptcHvHtPwrAllwd_kW.value);
    Rte_swc_EGYM_vcsb_EGYM_egmd_st_vcuChgLimResp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_st_vcuChgLimResp.value);

    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_accd_st_AcWrk.value) = Rte_swc_VCIP_vcib_VCIP_accd_st_AcWrk;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_brpd_e_brkPedalStatus.value) = Rte_swc_VCIP_vcib_VCIP_brpd_e_brkPedalStatus;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_drid_e_gearLvrPosRaw.value) = Rte_swc_VCIP_vcib_VCIP_drid_e_gearLvrPosRaw;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm.value) = Rte_swc_VCIP_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_eadd_pwr_mot2ActPwr_kW.value) = Rte_swc_VCIP_vcib_VCIP_eadd_pwr_mot2ActPwr_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_epbd_e_parkingSts.value) = Rte_swc_VCIP_vcib_VCIP_epbd_e_parkingSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_hvbd_b_hvbChPwrLimdByTemp.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbChPwrLimdByTemp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_hvbd_b_hvbDischPwrLimdByTemp.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbDischPwrLimdByTemp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_hvbd_b_hvilOpen.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvilOpen;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_hvbd_e_hvbMainRlySts.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMainRlySts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_hvbd_pwr_hvbActRaw_kW.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_hvbActRaw_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_hvbd_q_hvbSOC_pct.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_q_hvbSOC_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_macd_V_tankFuelLvl_l.value) = Rte_swc_VCIP_vcib_VCIP_macd_V_tankFuelLvl_l;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_obcd_b_obcChrgCablePlugged.value) = Rte_swc_VCIP_vcib_VCIP_obcd_b_obcChrgCablePlugged;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_obcd_b_obcWakeUp.value) = Rte_swc_VCIP_vcib_VCIP_obcd_b_obcWakeUp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_pmmd_b_driverStartReq.value) = Rte_swc_VCIP_vcib_VCIP_pmmd_b_driverStartReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value) = Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh.value) = Rte_swc_VCIP_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_vild_b_ipkOdoBckUpEn.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_ipkOdoBckUpEn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_vild_d_bcmOdometerbackup.value) = Rte_swc_VCIP_vcib_VCIP_vild_d_bcmOdometerbackup;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_vild_d_ipkOdometerbackup.value) = Rte_swc_VCIP_vcib_VCIP_vild_d_ipkOdometerbackup;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_vild_d_odometer_km.value) = Rte_swc_VCIP_vcib_VCIP_vild_d_odometer_km;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_vild_st_bmsDlyDataUpldEnb.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_bmsDlyDataUpldEnb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_vild_st_flgFctCfgDspRemainRng.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgDspRemainRng;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_vscd_b_vehSpdVld.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSpdVld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value) = Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_ddid_b_bmsMsgErr.value) = Rte_swc_DIAG_vcsb_DIAG_ddid_b_bmsMsgErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_VehLvl1Flt_flg.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl1Flt_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_VehLvl21Flt_flg.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl21Flt_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_VehLvl22Flt_flg.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl22Flt_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_VehLvl23Flt_flg.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl23Flt_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_VehLvl31Flt_flg.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl31Flt_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_VehLvl32Flt_flg.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl32Flt_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_VehLvl33Flt_flg.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl33Flt_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_bmsFltLv4A.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_bmsFltLv4A;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_mcuFltLv2A.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_mcuFltLv2A;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_mcuFltLv3A.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_mcuFltLv3A;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_mcuMsgErr.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_mcuMsgErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_vcuVehLvl1Flt_flg_BRP.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_vcuVehLvl1Flt_flg_BRP;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_vcuVehLvl22Flt_flg_BRP.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_vcuVehLvl22Flt_flg_BRP;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_macd_b_EVCANBusoff31Err.value) = Rte_swc_DIAG_vcsb_DIAG_macd_b_EVCANBusoff31Err;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_macd_b_EVCANBusoffDebd.value) = Rte_swc_DIAG_vcsb_DIAG_macd_b_EVCANBusoffDebd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HVSM_hvbd_e_PmmStatus.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HVSM_hvbd_st_ptRdyInd.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_ptRdyInd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW.value) = Rte_swc_SCAP_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm.value) = Rte_swc_TCOO_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_TCOO_msgd_tq_targetTqReq_Nm.value) = Rte_swc_TCOO_vcsb_TCOO_msgd_tq_targetTqReq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_VOMM_drid_b_veh4WDModActv.value) = Rte_swc_VOMM_vcsb_VOMM_drid_b_veh4WDModActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_VOMM_drid_b_vehEcoModActv.value) = Rte_swc_VOMM_vcsb_VOMM_drid_b_vehEcoModActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_VOMM_drid_b_vehSportModActv.value) = Rte_swc_VOMM_vcsb_VOMM_drid_b_vehSportModActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_VOMM_drid_e_driveDirSel.value) = Rte_swc_VOMM_vcsb_VOMM_drid_e_driveDirSel;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_VOMM_drid_e_drvrHEVModReq.value) = Rte_swc_VOMM_vcsb_VOMM_drid_e_drvrHEVModReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_VOMM_hmmd_b_EVModeActive.value) = Rte_swc_VOMM_vcsb_VOMM_hmmd_b_EVModeActive;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_VOMM_vsmd_b_VehRun.value) = Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRun;
    swc_HMIF_Step();
    Rte_swc_HMIF_vcsb_HMIF_dspd_V_engFuelConsAvg_lp100km = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_V_engFuelConsAvg_lp100km.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_b_CruisingDstSwtFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_CruisingDstSwtFb.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_b_HazardReqLmpOn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_HazardReqLmpOn.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_b_brkSysFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_brkSysFlt.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_b_ePTFault = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_ePTFault.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_b_evLampOn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_evLampOn.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_b_hevLampOn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_hevLampOn.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_b_odoBckpEn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_odoBckpEn.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_b_turtleLmpOn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_turtleLmpOn.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_b_vehOvrLoadEnbl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_vehOvrLoadEnbl.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_d_odoTotal_km = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_d_odoTotal_km.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_d_pmsOdoBckUpMilg_km = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_d_pmsOdoBckUpMilg_km.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehCrsDst_km = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_d_vehCrsDst_km.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehDrvRngEVMod_km = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_d_vehDrvRngEVMod_km.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehDrvRngHEVMod_km = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_d_vehDrvRngHEVMod_km.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehDrvRngStandard_km = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_d_vehDrvRngStandard_km.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_e_vehPwrFlow = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_e_vehPwrFlow.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_m_vehWeight_kg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_m_vehWeight_kg.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_num_AecEV_kWhp100km = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_num_AecEV_kWhp100km.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_num_errorCode = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_num_errorCode.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_pwr_hvPwrCsmpt_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_pwr_hvPwrCsmpt_kW.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_pwr_hvPwrRemain_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_pwr_hvPwrRemain_kW.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_q_hvbSOC_pct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_q_hvbSOC_pct.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_st_drvModInd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_drvModInd.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_st_drvPfmncRedn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_drvPfmncRedn.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_st_drvrOptRmdr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_drvrOptRmdr.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehCalNum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_vehCalNum.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehDrvMode = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_vehDrvMode.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehFailLvl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_vehFailLvl.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehOverLoadSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_vehOverLoadSts.value);
    Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehSubFailLvl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_vehSubFailLvl.value);

    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_accd_e_PtcSt.value) = Rte_swc_VCIP_vcib_VCIP_accd_e_PtcSt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_accd_e_airCmprSt.value) = Rte_swc_VCIP_vcib_VCIP_accd_e_airCmprSt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_acpd_x_accPedlPos_pct.value) = Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPos_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_brpd_b_brkPmpSelfChkOk.value) = Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPmpSelfChkOk;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_brpd_b_brkPressedFromSwitch.value) = Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPressedFromSwitch;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_brpd_e_bdcacWrk.value) = Rte_swc_VCIP_vcib_VCIP_brpd_e_bdcacWrk;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_brpd_e_brkPedalStatus.value) = Rte_swc_VCIP_vcib_VCIP_brpd_e_brkPedalStatus;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_cesd_b_EmergencyStop.value) = Rte_swc_VCIP_vcib_VCIP_cesd_b_EmergencyStop;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_cesd_b_crash.value) = Rte_swc_VCIP_vcib_VCIP_cesd_b_crash;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_dccd_b_dcdcCutOffLvFb.value) = Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcCutOffLvFb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_dccd_b_dcdcSelfChkOk.value) = Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcSelfChkOk;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_dccd_e_24vDcdcModAct.value) = Rte_swc_VCIP_vcib_VCIP_dccd_e_24vDcdcModAct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_dccd_e_modeAct.value) = Rte_swc_VCIP_vcib_VCIP_dccd_e_modeAct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_eadd_b_eadInv2RdyToCutOffLV.value) = Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2RdyToCutOffLV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_eadd_b_eadInv2SelfChkOk.value) = Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2SelfChkOk;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_eadd_e_eadInv2Sts.value) = Rte_swc_VCIP_vcib_VCIP_eadd_e_eadInv2Sts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_eadd_e_inv2ModeAct.value) = Rte_swc_VCIP_vcib_VCIP_eadd_e_inv2ModeAct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_epbd_e_parkingSts.value) = Rte_swc_VCIP_vcib_VCIP_epbd_e_parkingSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_bmsSelfChkOk.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_bmsSelfChkOk;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_hcmCutOffLvFb.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmCutOffLvFb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_hcmPtcDefRlyCls.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmPtcDefRlyCls;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_hcmRlyWldFlt.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmRlyWldFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_hcmSelfChkOk.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmSelfChkOk;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_hvbPrmtCutOffLvFb.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbPrmtCutOffLvFb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_hvilOpen.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvilOpen;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_lowTempProtnReq.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_lowTempProtnReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmd.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_e_dcdcMainRlySts.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_e_dcdcMainRlySts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_e_eadInv2MainRlySts.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_e_eadInv2MainRlySts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_e_hcmMaiRlyNeg.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_e_hcmMaiRlyNeg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_e_hcmWrkSt.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_e_hcmWrkSt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_e_hvbAssiRly.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbAssiRly;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_e_hvbMaiRlyNeg.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMaiRlyNeg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_e_hvbMaiRlyPos.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMaiRlyPos;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_e_hvbStatus.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbStatus;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_i_hvbCurr_A.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_i_hvbCurr_A;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_q_hvbSOC_pct.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_q_hvbSOC_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_st_hvilOpenSt.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvilOpenSt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_macd_b_epsSelfChkOk.value) = Rte_swc_VCIP_vcib_VCIP_macd_b_epsSelfChkOk;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_macd_b_vcuSelfChkOk.value) = Rte_swc_VCIP_vcib_VCIP_macd_b_vcuSelfChkOk;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_macd_e_sdcacWrk.value) = Rte_swc_VCIP_vcib_VCIP_macd_e_sdcacWrk;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_obcd_b_obcChrgCablePlugged.value) = Rte_swc_VCIP_vcib_VCIP_obcd_b_obcChrgCablePlugged;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_obcd_b_obcChrgCableUnplugged.value) = Rte_swc_VCIP_vcib_VCIP_obcd_b_obcChrgCableUnplugged;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_obcd_b_obcSelfChkOk.value) = Rte_swc_VCIP_vcib_VCIP_obcd_b_obcSelfChkOk;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_obcd_b_obcWakeUp.value) = Rte_swc_VCIP_vcib_VCIP_obcd_b_obcWakeUp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_pmmd_b_driverStartReq.value) = Rte_swc_VCIP_vcib_VCIP_pmmd_b_driverStartReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value) = Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_trad_b_trsm2GearshiftActv.value) = Rte_swc_VCIP_vcib_VCIP_trad_b_trsm2GearshiftActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_trad_st_trsm2GearAct.value) = Rte_swc_VCIP_vcib_VCIP_trad_st_trsm2GearAct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_AccyEnReq.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_AccyEnReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_AccyFltSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_AccyFltSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_cntnrCtrlEnaFb.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_cntnrCtrlEnaFb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_csmCampModeSwt.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_csmCampModeSwt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_csmCampModeSwtInvld.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_csmCampModeSwtInvld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_csmTakeEleSwt.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_csmTakeEleSwt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_csmTakeEleSwtReqInvld.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_csmTakeEleSwtReqInvld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_csmV2XDchaSw.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_csmV2XDchaSw;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_csmV2XDchaSwInvld.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_csmV2XDchaSwInvld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_flgBBMMsgErr.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_flgBBMMsgErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_flgFctCfgAccyButton.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgAccyButton;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_hcmMainPosBckVoltVldSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_hcmMainPosBckVoltVldSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_pepsRmtCtrlSt.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_pepsRmtCtrlSt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_tboxPrtFullSwStUB.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_tboxPrtFullSwStUB;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_pct_mmiLocBkChgTarVal.value) = Rte_swc_VCIP_vcib_VCIP_vild_pct_mmiLocBkChgTarVal;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_bbmFltSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_bbmFltSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_bbmWorkSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_bbmWorkSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_bmsDlyDataUpldEnb.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_bmsDlyDataUpldEnb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_dcChgCcSt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_dcChgCcSt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_dccAccyConnStsFb.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_dccAccyConnStsFb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_flgFctCfgAccy.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgAccy;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehTyp.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehTyp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_hcmAccConnStsFb.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hcmAccConnStsFb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_hcmHvilSt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hcmHvilSt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_hvbChgCcsts.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgCcsts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_hvbChgFltReq.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgFltReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_hvbDischgFltReq.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDischgFltReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_hvbPreChgSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbPreChgSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_ipkAlwChgSftCtlSt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_ipkAlwChgSftCtlSt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_ipkChgSftSwCtlSt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_ipkChgSftSwCtlSt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_obcChgCCSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_obcChgCCSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_obcOnBdCCline.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_obcOnBdCCline;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_obcOnBdDchaCCline.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_obcOnBdDchaCCline;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_pepsRKECom.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_pepsRKECom;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_tboxChgSftSwCtlSt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_tboxChgSftSwCtlSt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_tboxPrtFullSwSt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_tboxPrtFullSwSt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_tboxRsrChgSt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_tboxRsrChgSt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_u_hcmAcceRlyVolt.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_hcmAcceRlyVolt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_u_hcmMainPosBckVolt.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_hcmMainPosBckVolt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vscd_b_vehSpdVld.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSpdVld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value) = Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcob_VCOP_BMSH_ChargeLEDCtrl.value) = Rte_swc_VCOP_vcob_VCOP_BMSH_ChargeLEDCtrl;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_ATAU_pmmd_b_ePTRelease_flg.value) = Rte_swc_ATAU_vcsb_ATAU_pmmd_b_ePTRelease_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_DIAG_digd_b_VehLvl32Flt_flg.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl32Flt_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_DIAG_digd_b_VehLvl33Flt_flg.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl33Flt_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_EGYM_egmd_b_accyEnbFlg.value) = Rte_swc_EGYM_vcsb_EGYM_egmd_b_accyEnbFlg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_EGYM_egmd_b_dcdcEnbAllowFlg.value) = Rte_swc_EGYM_vcsb_EGYM_egmd_b_dcdcEnbAllowFlg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_EGYM_egmd_b_obcEnbAllowFlg.value) = Rte_swc_EGYM_vcsb_EGYM_egmd_b_obcEnbAllowFlg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_SCAP_eadd_b_mot2TqOff.value) = Rte_swc_SCAP_vcsb_SCAP_eadd_b_mot2TqOff;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_drid_e_driveDirSel.value) = Rte_swc_VOMM_vcsb_VOMM_drid_e_driveDirSel;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_drid_e_gearLvrPos.value) = Rte_swc_VOMM_vcsb_VOMM_drid_e_gearLvrPos;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_hmmd_b_HVBusDischrgComplete.value) = Rte_swc_VOMM_vcsb_VOMM_hmmd_b_HVBusDischrgComplete;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_pmmd_b_nmRdySlp.value) = Rte_swc_VOMM_vcsb_VOMM_pmmd_b_nmRdySlp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_pmmd_b_nmWkUp.value) = Rte_swc_VOMM_vcsb_VOMM_pmmd_b_nmWkUp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_pmmd_b_pwrHoldReq.value) = Rte_swc_VOMM_vcsb_VOMM_pmmd_b_pwrHoldReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_pmmd_e_CanNMSts.value) = Rte_swc_VOMM_vcsb_VOMM_pmmd_e_CanNMSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_vsmd_b_PTDisabled.value) = Rte_swc_VOMM_vcsb_VOMM_vsmd_b_PTDisabled;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_vsmd_b_PTEnabled.value) = Rte_swc_VOMM_vcsb_VOMM_vsmd_b_PTEnabled;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_vsmd_b_StartDemRaw.value) = Rte_swc_VOMM_vcsb_VOMM_vsmd_b_StartDemRaw;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_vsmd_b_VehRun.value) = Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRun;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_vsmd_b_VehRunRaw.value) = Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRunRaw;
    swc_HVSM_Step();
    Rte_swc_HVSM_vcsb_HVSM_bmsd_e_modeTgt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_bmsd_e_modeTgt.value);
    Rte_swc_HVSM_vcsb_HVSM_dccd_b_DCDCEnabled = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_dccd_b_DCDCEnabled.value);
    Rte_swc_HVSM_vcsb_HVSM_dccd_e_modeTgt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_dccd_e_modeTgt.value);
    Rte_swc_HVSM_vcsb_HVSM_dccd_pct_DCDCPwrLmt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_dccd_pct_DCDCPwrLmt.value);
    Rte_swc_HVSM_vcsb_HVSM_eadd_b_ead2Avail = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_eadd_b_ead2Avail.value);
    Rte_swc_HVSM_vcsb_HVSM_eadd_b_ead2Enad = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_eadd_b_ead2Enad.value);
    Rte_swc_HVSM_vcsb_HVSM_eadd_e_inv2ModeTgt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_eadd_e_inv2ModeTgt.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_CampModeFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_CampModeFb.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_TakeEleSwtIndReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_TakeEleSwtIndReq.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_acPtcEnb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_acPtcEnb.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyHvOnCmd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_accyHvOnCmd.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyPreRlyCmd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_accyPreRlyCmd.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyWrkEnCmd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_accyWrkEnCmd.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_allowChg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_allowChg.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_chgCablePlugged = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_chgCablePlugged.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_dchaOn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_dchaOn.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_fltPwrShutDn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_fltPwrShutDn.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_hvBusShutDwnCmpl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_hvBusShutDwnCmpl.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_hvbIntelChgCmplt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_hvbIntelChgCmplt.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_hvbIntelChgExitReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_hvbIntelChgExitReq.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_lvCutOffReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_lvCutOffReq.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_rlyTmOut = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_rlyTmOut.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_tmOutFlg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_tmOutFlg.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_tmOutFlgCfm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_tmOutFlgCfm.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_vcuRdyToSlp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_vcuRdyToSlp.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_b_vcuWkUpCmd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_vcuWkUpCmd.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_e_PmmStatus.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_e_modeTgt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_e_modeTgt.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_pct_BookChrgnTarValFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_pct_BookChrgnTarValFb.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_st_CampModeFbFailrReason = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_CampModeFbFailrReason.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_st_RmChgCmdFailPmt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_RmChgCmdFailPmt.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyPreRlyFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_accyPreRlyFlt.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyPreRlySts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_accyPreRlySts.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyRlyFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_accyRlyFlt.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyRlySts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_accyRlySts.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyRlyVoltSamSw = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_accyRlyVoltSamSw.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyTakeSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_accyTakeSts.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_st_bbmWrkEnCmd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_bbmWrkEnCmd.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hcmMaiRlyNegClsReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_hcmMaiRlyNegClsReq.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hvbAssiRlyPosClsReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_hvbAssiRlyPosClsReq.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hvbMaiRlyNegClsReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_hvbMaiRlyNegClsReq.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hvbMaiRlyPosClsReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_hvbMaiRlyPosClsReq.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_st_otaHvOnOFFReqSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_otaHvOnOFFReqSts.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_st_otaHvOnOffFailInfo = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_otaHvOnOffFailInfo.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_st_ptRdyInd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_ptRdyInd.value);
    Rte_swc_HVSM_vcsb_HVSM_hvbd_st_tboxChgSftSwCtlStEV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_tboxChgSftSwCtlStEV.value);
    Rte_swc_HVSM_vcsb_HVSM_obcd_b_chargerPlugged = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_obcd_b_chargerPlugged.value);
    Rte_swc_HVSM_vcsb_HVSM_obcd_e_chargerSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_obcd_e_chargerSts.value);

    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A.value) = Rte_swc_VCIP_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm.value) = Rte_swc_VCIP_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcib_VCIP_eadd_tq_mot2ActTq_Nm.value) = Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2ActTq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcib_VCIP_eadd_u_busInv2HVAct_V.value) = Rte_swc_VCIP_vcib_VCIP_eadd_u_busInv2HVAct_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value) = Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcib_VCIP_vild_st_flg2FctCfgVehTyp.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flg2FctCfgVehTyp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value) = Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcsb_VOMM_vsmd_b_VehRun.value) = Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRun;
    swc_MEST_Step();
    Rte_swc_MEST_vcsb_MEST_masd_b_vehOvrLoadEnbl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcsb_MEST_masd_b_vehOvrLoadEnbl.value);
    Rte_swc_MEST_vcsb_MEST_masd_m_vehWeight_kg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcsb_MEST_masd_m_vehWeight_kg.value);
    Rte_swc_MEST_vcsb_MEST_masd_st_vehCalNum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcsb_MEST_masd_st_vehCalNum.value);
    Rte_swc_MEST_vcsb_MEST_masd_st_vehOverLoadSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcsb_MEST_masd_st_vehOverLoadSts.value);

    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value) = Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vild_b_obcWakeUpActv.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_obcWakeUpActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vild_b_tboxPowOffCmd.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_tboxPowOffCmd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vild_st_actWorkSts1.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_actWorkSts1;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehCfg.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehCfg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vild_st_tboxInventorySpdLmtReq.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_tboxInventorySpdLmtReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vild_st_tboxLife.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_tboxLife;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vild_st_tboxLockVehPerFlag.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_tboxLockVehPerFlag;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vild_st_tboxSpdLmtLevelReq.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_tboxSpdLmtLevelReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vild_st_tboxVersionConversionFlag.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_tboxVersionConversionFlag;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value) = Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
    swc_OGVL_Step();
    Rte_swc_OGVL_vcsb_OGVL_dtld_st_invSpdLmtRxSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_invSpdLmtRxSts.value);
    Rte_swc_OGVL_vcsb_OGVL_dtld_st_inventorySpdLmtReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_inventorySpdLmtReq.value);
    Rte_swc_OGVL_vcsb_OGVL_dtld_st_lifeCnt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_lifeCnt.value);
    Rte_swc_OGVL_vcsb_OGVL_dtld_st_lockVehPer = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_lockVehPer.value);
    Rte_swc_OGVL_vcsb_OGVL_dtld_st_lockVehPerRxSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_lockVehPerRxSts.value);
    Rte_swc_OGVL_vcsb_OGVL_dtld_st_pwrOffCmd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_pwrOffCmd.value);
    Rte_swc_OGVL_vcsb_OGVL_dtld_st_pwrOffCmdRxSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_pwrOffCmdRxSts.value);
    Rte_swc_OGVL_vcsb_OGVL_dtld_st_spdLmtLevelReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_spdLmtLevelReq.value);
    Rte_swc_OGVL_vcsb_OGVL_dtld_st_spdLmtLvRxSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_spdLmtLvRxSts.value);
    Rte_swc_OGVL_vcsb_OGVL_dtld_st_tboxLifeSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_tboxLifeSts.value);
    Rte_swc_OGVL_vcsb_OGVL_dtld_st_verCvsRxSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_verCvsRxSts.value);
    Rte_swc_OGVL_vcsb_OGVL_dtld_st_versionConversion = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_versionConversion.value);
    Rte_swc_OGVL_vcsb_OGVL_dtld_v_dstSpdLim_kph = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_v_dstSpdLim_kph.value);

    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_obcd_b_obcWakeUp.value) = Rte_swc_VCIP_vcib_VCIP_obcd_b_obcWakeUp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value) = Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_vild_st_TBOXFunAntiDismantleActive.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXFunAntiDismantleActive;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_vild_st_TBOXFunLockVehActive.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXFunLockVehActive;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_vild_st_TBOXLockLimSet.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockLimSet;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_vild_st_TBOXLockVehCtrl.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockVehCtrl;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_vild_st_TBOXLockVehType.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockVehType;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_vild_st_actWorkSts1.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_actWorkSts1;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehCfg.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehCfg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value) = Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
    swc_RMLK_Step();
    Rte_swc_RMLK_vcsb_RMLK_rlcd_b_LockVehSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_b_LockVehSts.value);
    Rte_swc_RMLK_vcsb_RMLK_rlcd_b_rmtCtrlAccPedlOff = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_b_rmtCtrlAccPedlOff.value);
    Rte_swc_RMLK_vcsb_RMLK_rlcd_b_rmtCtrlTqOff = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_b_rmtCtrlTqOff.value);
    Rte_swc_RMLK_vcsb_RMLK_rlcd_b_rmtCtrlTurtleLampOn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_b_rmtCtrlTurtleLampOn.value);
    Rte_swc_RMLK_vcsb_RMLK_rlcd_num_FunAnti_DismantleActive = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_num_FunAnti_DismantleActive.value);
    Rte_swc_RMLK_vcsb_RMLK_rlcd_num_FunLockVehActive = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_num_FunLockVehActive.value);
    Rte_swc_RMLK_vcsb_RMLK_rlcd_num_LockLimResult = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_num_LockLimResult.value);
    Rte_swc_RMLK_vcsb_RMLK_rlcd_num_LockVehType = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_num_LockVehType.value);
    Rte_swc_RMLK_vcsb_RMLK_rlcd_st_LockVehExecutedSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_st_LockVehExecutedSts.value);
    Rte_swc_RMLK_vcsb_RMLK_rlcd_v_rmtCtrlFctSpdLim_kph = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_v_rmtCtrlFctSpdLim_kph.value);

    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_adcd_st_pmsAdcCtrldSts.value) = Rte_swc_VCIP_vcib_VCIP_adcd_st_pmsAdcCtrldSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_brpd_e_brkPedalStatus.value) = Rte_swc_VCIP_vcib_VCIP_brpd_e_brkPedalStatus;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_eadd_e_inv2ModeAct.value) = Rte_swc_VCIP_vcib_VCIP_eadd_e_inv2ModeAct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_eadd_fact_mot2GearRat.value) = Rte_swc_VCIP_vcib_VCIP_eadd_fact_mot2GearRat;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm.value) = Rte_swc_VCIP_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_eadd_tq_mot2ActTq_Nm.value) = Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2ActTq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailLTBrk_Nm.value) = Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailLTBrk_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailLTBst_Nm.value) = Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailLTBst_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailSTBrk_Nm.value) = Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailSTBrk_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailSTBst_Nm.value) = Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailSTBst_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_hvbd_pwr_PeakChMax_kW.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_PeakChMax_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_hvbd_pwr_PeakDischMax_kW.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_PeakDischMax_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_hvbd_pwr_StatChMax_kW.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_StatChMax_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_hvbd_pwr_StatDischMax_kW.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_StatDischMax_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_hvbd_q_hvbSOC_pct.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_q_hvbSOC_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_trad_b_trsm2GearshiftActv.value) = Rte_swc_VCIP_vcib_VCIP_trad_b_trsm2GearshiftActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_trad_fact_trsm2GearRat.value) = Rte_swc_VCIP_vcib_VCIP_trad_fact_trsm2GearRat;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_trad_st_trsm2GearAct.value) = Rte_swc_VCIP_vcib_VCIP_trad_st_trsm2GearAct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_vild_i_hvbCurr_A.value) = Rte_swc_VCIP_vcib_VCIP_vild_i_hvbCurr_A;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgMotTyp.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgMotTyp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_vild_u_hvbVolt_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_hvbVolt_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_vscd_b_ESPActv.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_ESPActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_vscd_b_ESPActvRaw.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_ESPActvRaw;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value) = Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_DIAG_digd_b_VehLvl31Flt_flg.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl31Flt_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_DIAG_digd_b_VehLvl32Flt_flg.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl32Flt_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_EGYM_accd_pwr_hvAttpwr_kW.value) = Rte_swc_EGYM_vcsb_EGYM_accd_pwr_hvAttpwr_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_EGYM_egmd_b_mcuEnbFlg.value) = Rte_swc_EGYM_vcsb_EGYM_egmd_b_mcuEnbFlg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_HVSM_eadd_b_ead2Enad.value) = Rte_swc_HVSM_vcsb_HVSM_eadd_b_ead2Enad;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_OGVL_dtld_st_pwrOffCmd.value) = Rte_swc_OGVL_vcsb_OGVL_dtld_st_pwrOffCmd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_RMLK_rlcd_b_rmtCtrlTqOff.value) = Rte_swc_RMLK_vcsb_RMLK_rlcd_b_rmtCtrlTqOff;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_VOMM_drid_b_veh4WDModActv.value) = Rte_swc_VOMM_vcsb_VOMM_drid_b_veh4WDModActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_VOMM_drid_b_vehSportModActv.value) = Rte_swc_VOMM_vcsb_VOMM_drid_b_vehSportModActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_VOMM_drid_e_driveDirSel.value) = Rte_swc_VOMM_vcsb_VOMM_drid_e_driveDirSel;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_VOMM_hmmd_b_EVModeActive.value) = Rte_swc_VOMM_vcsb_VOMM_hmmd_b_EVModeActive;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_VOMM_vsmd_b_VehRun.value) = Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRun;
    swc_SCAP_Step();
    Rte_swc_SCAP_vcsb_SCAP_eadd_b_mot2TqOff = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_eadd_b_mot2TqOff.value);
    Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MaxLTTq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_eadd_tq_mot2MaxLTTq_Nm.value);
    Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MaxSTTq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_eadd_tq_mot2MaxSTTq_Nm.value);
    Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MinLTTq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_eadd_tq_mot2MinLTTq_Nm.value);
    Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MinSTTq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_eadd_tq_mot2MinSTTq_Nm.value);
    Rte_swc_SCAP_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW.value);
    Rte_swc_SCAP_vcsb_SCAP_tqld_tq_axle2MaxTq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_tqld_tq_axle2MaxTq_Nm.value);
    Rte_swc_SCAP_vcsb_SCAP_tqld_tq_axle2MinTq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_tqld_tq_axle2MinTq_Nm.value);
    Rte_swc_SCAP_vcsb_SCAP_tqld_tq_whlMax_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_tqld_tq_whlMax_Nm.value);
    Rte_swc_SCAP_vcsb_SCAP_tqld_tq_whlMin_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_tqld_tq_whlMin_Nm.value);

    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_acpd_x_accPedlPos_pct.value) = Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPos_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_brpd_e_brkPedalStatus.value) = Rte_swc_VCIP_vcib_VCIP_brpd_e_brkPedalStatus;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_brpd_x_brkPedlPos_pct.value) = Rte_swc_VCIP_vcib_VCIP_brpd_x_brkPedlPos_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_ccdd_u_cruiseADvoltage_V.value) = Rte_swc_VCIP_vcib_VCIP_ccdd_u_cruiseADvoltage_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm.value) = Rte_swc_VCIP_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_epbd_e_parkingSts.value) = Rte_swc_VCIP_vcib_VCIP_epbd_e_parkingSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_a_yrsLongitAcce_mps2.value) = Rte_swc_VCIP_vcib_VCIP_vild_a_yrsLongitAcce_mps2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_b_bcmFrntLftDrAjSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_bcmFrntLftDrAjSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_b_bcmFrntRDrAjSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_bcmFrntRDrAjSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvSeat.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvSeat;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_st_flgFctCfgECOMaxSpd.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgECOMaxSpd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_st_flgFctCfgPowerMaxSpd.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgPowerMaxSpd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehCfg.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehCfg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_st_vscEHBAVHSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_vscEHBAVHSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vscd_b_ESPActv.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_ESPActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vscd_b_ehbTrqDecReqActv.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbTrqDecReqActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vscd_b_vehSlipWarn.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSlipWarn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vscd_b_vehSpdVld.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSpdVld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vscd_st_ehbEPBDynAppSts.value) = Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbEPBDynAppSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vscd_st_ehbHHCActive.value) = Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbHHCActive;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value) = Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_DIAG_brpd_b_brkSwtMismatch.value) = Rte_swc_DIAG_vcsb_DIAG_brpd_b_brkSwtMismatch;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_DIAG_digd_b_VehLvl22Flt_flg.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl22Flt_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_DIAG_digd_b_VehLvl23Flt_flg.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl23Flt_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_DIAG_digd_b_VehLvl31Flt_flg.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl31Flt_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_DIAG_digd_b_VehLvl32Flt_flg.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl32Flt_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_DIAG_digd_b_VehLvl33Flt_flg.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl33Flt_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_HMIF_dspd_st_vehFailLvl.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehFailLvl;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_HVSM_hvbd_e_PmmStatus.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_OGVL_dtld_v_dstSpdLim_kph.value) = Rte_swc_OGVL_vcsb_OGVL_dtld_v_dstSpdLim_kph;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_RMLK_rlcd_v_rmtCtrlFctSpdLim_kph.value) = Rte_swc_RMLK_vcsb_RMLK_rlcd_v_rmtCtrlFctSpdLim_kph;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCAP_tqld_tq_whlMax_Nm.value) = Rte_swc_SCAP_vcsb_SCAP_tqld_tq_whlMax_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_TCOO_apdd_tq_whlDem_Nm.value) = Rte_swc_TCOO_vcsb_TCOO_apdd_tq_whlDem_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_TCOO_dtdd_tq_whlCstDrgDemNoEhb_Nm.value) = Rte_swc_TCOO_vcsb_TCOO_dtdd_tq_whlCstDrgDemNoEhb_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_TCOO_dtdd_tq_whlDragDem_Nm.value) = Rte_swc_TCOO_vcsb_TCOO_dtdd_tq_whlDragDem_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_TCOO_tqdd_b_ehbDisEnbCreep.value) = Rte_swc_TCOO_vcsb_TCOO_tqdd_b_ehbDisEnbCreep;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_VOMM_drid_b_vehEcoModActv.value) = Rte_swc_VOMM_vcsb_VOMM_drid_b_vehEcoModActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_VOMM_drid_b_vehSportModActv.value) = Rte_swc_VOMM_vcsb_VOMM_drid_b_vehSportModActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_VOMM_drid_e_driveDirSel.value) = Rte_swc_VOMM_vcsb_VOMM_drid_e_driveDirSel;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_VOMM_vsmd_b_VehRun.value) = Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRun;
    swc_SCOO_Step();
    Rte_swc_SCOO_vcsb_SCOO_ccdd_acc_intAccTgt_mps2 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_acc_intAccTgt_mps2.value);
    Rte_swc_SCOO_vcsb_SCOO_ccdd_acc_vehAccTgt_mps2 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_acc_vehAccTgt_mps2.value);
    Rte_swc_SCOO_vcsb_SCOO_ccdd_b_accCtrlActv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_b_accCtrlActv.value);
    Rte_swc_SCOO_vcsb_SCOO_ccdd_b_crsCtrlAccPedlOvrd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_b_crsCtrlAccPedlOvrd.value);
    Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsBtnErrSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_e_crsBtnErrSts.value);
    Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsBtnSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_e_crsBtnSts.value);
    Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsCtrlSpdMode = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_e_crsCtrlSpdMode.value);
    Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsCtrlSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_e_crsCtrlSts.value);
    Rte_swc_SCOO_vcsb_SCOO_ccdd_tq_whlDemRawAdv_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_tq_whlDemRawAdv_Nm.value);
    Rte_swc_SCOO_vcsb_SCOO_ccdd_tq_whlDem_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_tq_whlDem_Nm.value);
    Rte_swc_SCOO_vcsb_SCOO_ccdd_v_crsCtrlTgtSpd_kph = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_v_crsCtrlTgtSpd_kph.value);
    Rte_swc_SCOO_vcsb_SCOO_ccdd_v_crsTgtSpdQuit_kph = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_v_crsTgtSpdQuit_kph.value);
    Rte_swc_SCOO_vcsb_SCOO_ccdd_x_accPedlPosVirt_pct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_x_accPedlPosVirt_pct.value);
    Rte_swc_SCOO_vcsb_SCOO_ctdd_a_yrsLongAccAvgVld_mps2 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ctdd_a_yrsLongAccAvgVld_mps2.value);
    Rte_swc_SCOO_vcsb_SCOO_ctdd_b_crpSlopeTrqOffsetEnHld = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ctdd_b_crpSlopeTrqOffsetEnHld.value);
    Rte_swc_SCOO_vcsb_SCOO_ctdd_b_eCreepReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ctdd_b_eCreepReq.value);
    Rte_swc_SCOO_vcsb_SCOO_ctdd_n_vehTgtCrpSpdFwd_kph = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ctdd_n_vehTgtCrpSpdFwd_kph.value);
    Rte_swc_SCOO_vcsb_SCOO_ctdd_tq_whlDem_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ctdd_tq_whlDem_Nm.value);
    Rte_swc_SCOO_vcsb_SCOO_vsld_b_vslTqIntvReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_vsld_b_vslTqIntvReq.value);
    Rte_swc_SCOO_vcsb_SCOO_vsld_tq_whlMaxTqLimFast_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_vsld_tq_whlMaxTqLimFast_Nm.value);
    Rte_swc_SCOO_vcsb_SCOO_vsld_tq_whlMaxTqLimSlow_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_vsld_tq_whlMaxTqLimSlow_Nm.value);
    Rte_swc_SCOO_vcsb_SCOO_vsld_v_vehMaxCfgSpd_kph = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_vsld_v_vehMaxCfgSpd_kph.value);

    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_acpd_b_accPedlPosVld.value) = Rte_swc_VCIP_vcib_VCIP_acpd_b_accPedlPosVld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_acpd_x_accPedlPosLimd_pct.value) = Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosLimd_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_acpd_x_accPedlPos_pct.value) = Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPos_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_adcd_b_adcCtrlTorqEn.value) = Rte_swc_VCIP_vcib_VCIP_adcd_b_adcCtrlTorqEn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_adcd_st_pmsAdcCtrldSts.value) = Rte_swc_VCIP_vcib_VCIP_adcd_st_pmsAdcCtrldSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_adcd_tq_adcTgtDrvTorq_Nm.value) = Rte_swc_VCIP_vcib_VCIP_adcd_tq_adcTgtDrvTorq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_brpd_e_brkPedalStatus.value) = Rte_swc_VCIP_vcib_VCIP_brpd_e_brkPedalStatus;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_brpd_x_brkPedlPos_pct.value) = Rte_swc_VCIP_vcib_VCIP_brpd_x_brkPedlPos_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_eadd_fact_mot2GearRat.value) = Rte_swc_VCIP_vcib_VCIP_eadd_fact_mot2GearRat;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_eadd_tq_mot2ActTq_Nm.value) = Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2ActTq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_hvbd_pwr_PeakChMax_kW.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_PeakChMax_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_hvbd_pwr_StatChMax_kW.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_StatChMax_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_hvbd_q_hvbSOC_pct.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_q_hvbSOC_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value) = Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_trad_fact_trsm2GearRat.value) = Rte_swc_VCIP_vcib_VCIP_trad_fact_trsm2GearRat;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_trad_st_trsm2GearAct.value) = Rte_swc_VCIP_vcib_VCIP_trad_st_trsm2GearAct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_a_yrsLongitAcce_mps2.value) = Rte_swc_VCIP_vcib_VCIP_vild_a_yrsLongitAcce_mps2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_csmEngRecSwtReq.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_csmEngRecSwtReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_ehbIsaPtTrqDecReqActv.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_ehbIsaPtTrqDecReqActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_ehbVlcCddActv.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_ehbVlcCddActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_flgFctCfgChgTyp.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgChgTyp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvMod.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvMod;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvModConn.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvModConn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvModStor.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvModStor;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_flgNetConfgABS.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_flgNetConfgABS;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_l_whlRad_m.value) = Rte_swc_VCIP_vcib_VCIP_vild_l_whlRad_m;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_st_csmRgnLvlSet.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_csmRgnLvlSet;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_st_ehbIsaSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_ehbIsaSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_st_flgFctCfgMotTyp.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgMotTyp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehCfg.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehCfg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_tq_ehbIsaPtTrqDecReq_Nm.value) = Rte_swc_VCIP_vcib_VCIP_vild_tq_ehbIsaPtTrqDecReq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_ESPActv.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_ESPActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_ehbAbsOvrdActv.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbAbsOvrdActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_ehbAebActv.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbAebActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_ehbDtcActv.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbDtcActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_ehbTrqDecReqActv.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbTrqDecReqActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_ehbTrqIncReqActv.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbTrqIncReqActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_ehbVlcActv.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbVlcActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_ehbVlcAvailb.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbVlcAvailb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_ehbVlcTrqReqActv.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbVlcTrqReqActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_pdcBrkFlg.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_pdcBrkFlg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_vehSpdVld.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSpdVld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_st_ehbMbRgnTgtWhlSts.value) = Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbMbRgnTgtWhlSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_tq_axle2MaxTqReq_Nm.value) = Rte_swc_VCIP_vcib_VCIP_vscd_tq_axle2MaxTqReq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_tq_axle2MinTqReq_Nm.value) = Rte_swc_VCIP_vcib_VCIP_vscd_tq_axle2MinTqReq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_tq_axle2RgnBrkTqReq_Nm.value) = Rte_swc_VCIP_vcib_VCIP_vscd_tq_axle2RgnBrkTqReq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_tq_ehbMbRgnTgtWhl_Nm.value) = Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbMbRgnTgtWhl_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_tq_ehbTrqDecReq_Nm.value) = Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbTrqDecReq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_tq_ehbTrqIncReq_Nm.value) = Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbTrqIncReq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_tq_ehbVlcTrqReq_Nm.value) = Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbVlcTrqReq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value) = Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_HVSM_hvbd_b_vcuWkUpCmd.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_vcuWkUpCmd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_HVSM_hvbd_e_PmmStatus.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCAP_eadd_tq_mot2MaxSTTq_Nm.value) = Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MaxSTTq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCAP_eadd_tq_mot2MinSTTq_Nm.value) = Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MinSTTq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCAP_tqld_tq_axle2MaxTq_Nm.value) = Rte_swc_SCAP_vcsb_SCAP_tqld_tq_axle2MaxTq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCAP_tqld_tq_axle2MinTq_Nm.value) = Rte_swc_SCAP_vcsb_SCAP_tqld_tq_axle2MinTq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCAP_tqld_tq_whlMax_Nm.value) = Rte_swc_SCAP_vcsb_SCAP_tqld_tq_whlMax_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCAP_tqld_tq_whlMin_Nm.value) = Rte_swc_SCAP_vcsb_SCAP_tqld_tq_whlMin_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCOO_ccdd_tq_whlDem_Nm.value) = Rte_swc_SCOO_vcsb_SCOO_ccdd_tq_whlDem_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCOO_ctdd_a_yrsLongAccAvgVld_mps2.value) = Rte_swc_SCOO_vcsb_SCOO_ctdd_a_yrsLongAccAvgVld_mps2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCOO_ctdd_b_crpSlopeTrqOffsetEnHld.value) = Rte_swc_SCOO_vcsb_SCOO_ctdd_b_crpSlopeTrqOffsetEnHld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCOO_ctdd_b_eCreepReq.value) = Rte_swc_SCOO_vcsb_SCOO_ctdd_b_eCreepReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCOO_ctdd_tq_whlDem_Nm.value) = Rte_swc_SCOO_vcsb_SCOO_ctdd_tq_whlDem_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCOO_vsld_tq_whlMaxTqLimFast_Nm.value) = Rte_swc_SCOO_vcsb_SCOO_vsld_tq_whlMaxTqLimFast_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCOO_vsld_v_vehMaxCfgSpd_kph.value) = Rte_swc_SCOO_vcsb_SCOO_vsld_v_vehMaxCfgSpd_kph;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_VOMM_drid_b_veh4WDModActv.value) = Rte_swc_VOMM_vcsb_VOMM_drid_b_veh4WDModActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_VOMM_drid_b_vehEcoModActv.value) = Rte_swc_VOMM_vcsb_VOMM_drid_b_vehEcoModActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_VOMM_drid_b_vehSportModActv.value) = Rte_swc_VOMM_vcsb_VOMM_drid_b_vehSportModActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_VOMM_drid_e_driveDirSel.value) = Rte_swc_VOMM_vcsb_VOMM_drid_e_driveDirSel;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_VOMM_drid_e_gearLvrPos.value) = Rte_swc_VOMM_vcsb_VOMM_drid_e_gearLvrPos;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_VOMM_hmmd_b_EVModeActive.value) = Rte_swc_VOMM_vcsb_VOMM_hmmd_b_EVModeActive;
    swc_TCOO_Step();
    Rte_swc_TCOO_vcsb_TCOO_apdd_tq_whlDem_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_apdd_tq_whlDem_Nm.value);
    Rte_swc_TCOO_vcsb_TCOO_dtdd_b_drvPfmncDrgDec = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_dtdd_b_drvPfmncDrgDec.value);
    Rte_swc_TCOO_vcsb_TCOO_dtdd_st_RegenLvlDisp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_dtdd_st_RegenLvlDisp.value);
    Rte_swc_TCOO_vcsb_TCOO_dtdd_tq_whlCoastDrgDem_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_dtdd_tq_whlCoastDrgDem_Nm.value);
    Rte_swc_TCOO_vcsb_TCOO_dtdd_tq_whlCstDrgDemNoEhb_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_dtdd_tq_whlCstDrgDemNoEhb_Nm.value);
    Rte_swc_TCOO_vcsb_TCOO_dtdd_tq_whlDragDem_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_dtdd_tq_whlDragDem_Nm.value);
    Rte_swc_TCOO_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm.value);
    Rte_swc_TCOO_vcsb_TCOO_eadd_tq_mot2TgtTq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_eadd_tq_mot2TgtTq_Nm.value);
    Rte_swc_TCOO_vcsb_TCOO_msgd_tq_targetTqReq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_msgd_tq_targetTqReq_Nm.value);
    Rte_swc_TCOO_vcsb_TCOO_tdad_tq_whlDemUnfilt_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tdad_tq_whlDemUnfilt_Nm.value);
    Rte_swc_TCOO_vcsb_TCOO_tdad_tq_whlDemUnlim_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tdad_tq_whlDemUnlim_Nm.value);
    Rte_swc_TCOO_vcsb_TCOO_tdad_tq_whlDem_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tdad_tq_whlDem_Nm.value);
    Rte_swc_TCOO_vcsb_TCOO_tqdd_b_accPedlPosVirtVld = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_b_accPedlPosVirtVld.value);
    Rte_swc_TCOO_vcsb_TCOO_tqdd_b_ehbDisEnbCreep = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_b_ehbDisEnbCreep.value);
    Rte_swc_TCOO_vcsb_TCOO_tqdd_b_gpOvrd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_b_gpOvrd.value);
    Rte_swc_TCOO_vcsb_TCOO_tqdd_st_ehbOvrdActv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_st_ehbOvrdActv.value);
    Rte_swc_TCOO_vcsb_TCOO_tqdd_st_ehbOvrdTyp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_st_ehbOvrdTyp.value);
    Rte_swc_TCOO_vcsb_TCOO_tqdd_st_whlAcceSupprsn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_st_whlAcceSupprsn.value);
    Rte_swc_TCOO_vcsb_TCOO_tqdd_x_accPedlPosVirt_pct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_x_accPedlPosVirt_pct.value);
    Rte_swc_TCOO_vcsb_TCOO_tvrd_tq_mot2TgtTqReq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tvrd_tq_mot2TgtTqReq_Nm.value);

    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_brpd_b_DryAirSwitch.value) = Rte_swc_VCIP_vcib_VCIP_brpd_b_DryAirSwitch;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_brpd_b_ResrAirSwitch.value) = Rte_swc_VCIP_vcib_VCIP_brpd_b_ResrAirSwitch;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_brpd_b_brkPumpFault.value) = Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPumpFault;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_brpd_b_vacTankLowPrs.value) = Rte_swc_VCIP_vcib_VCIP_brpd_b_vacTankLowPrs;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_brpd_p_AirPres_kpa.value) = Rte_swc_VCIP_vcib_VCIP_brpd_p_AirPres_kpa;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_brpd_p_brkVacuumPres_bar.value) = Rte_swc_VCIP_vcib_VCIP_brpd_p_brkVacuumPres_bar;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_brpd_st_bdcacWrk.value) = Rte_swc_VCIP_vcib_VCIP_brpd_st_bdcacWrk;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_cesd_b_crash.value) = Rte_swc_VCIP_vcib_VCIP_cesd_b_crash;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_dccd_e_modeAct.value) = Rte_swc_VCIP_vcib_VCIP_dccd_e_modeAct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_macd_p_frontAirTankPres_bar.value) = Rte_swc_VCIP_vcib_VCIP_macd_p_frontAirTankPres_bar;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_macd_p_rearAirTankPres_bar.value) = Rte_swc_VCIP_vcib_VCIP_macd_p_rearAirTankPres_bar;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_macd_st_epsErrorCode.value) = Rte_swc_VCIP_vcib_VCIP_macd_st_epsErrorCode;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value) = Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_vild_b_flgNetConfgABS.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_flgNetConfgABS;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehTyp.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehTyp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_vild_u_VacTkAirPres_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_VacTkAirPres_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_vild_u_VacTkEnFb_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_VacTkEnFb_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_vild_u_brkVacuumPres_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_brkVacuumPres_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_vild_u_vacTkPowSup_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_vacTkPowSup_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value) = Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_HVSM_hvbd_e_PmmStatus.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_HVSM_hvbd_st_ptRdyInd.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_ptRdyInd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_VOMM_essd_e_engStrtTyp.value) = Rte_swc_VOMM_vcsb_VOMM_essd_e_engStrtTyp;
    swc_AUXC_Step();
    Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpEnOvrTmHiPreFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpEnOvrTmHiPreFlt.value);
    Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpEnOvrTmLoPreFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpEnOvrTmLoPreFlt.value);
    Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpLoPreFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpLoPreFlt.value);
    Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpRlyEn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpRlyEn.value);
    Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpRlyFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpRlyFlt.value);
    Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpSnrFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpSnrFlt.value);
    Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpSysFailFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpSysFailFlt.value);
    Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacTkAirPresLowFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacTkAirPresLowFlt.value);
    Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_airTankFlt.value);
    Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankPresLow = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_airTankPresLow.value);
    Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankPresLowEVDis = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_airTankPresLowEVDis.value);
    Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankPresLowInhDrv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_airTankPresLowInhDrv.value);
    Rte_swc_AUXC_vcsb_AUXC_brpd_b_bdcacEna = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_bdcacEna.value);
    Rte_swc_AUXC_vcsb_AUXC_brpd_b_bdcacTmOut = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_bdcacTmOut.value);
    Rte_swc_AUXC_vcsb_AUXC_brpd_b_brkPmp1Rly = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_brkPmp1Rly.value);
    Rte_swc_AUXC_vcsb_AUXC_brpd_b_brkPmp2Rly = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_brkPmp2Rly.value);
    Rte_swc_AUXC_vcsb_AUXC_brpd_b_pumpRdy = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_pumpRdy.value);
    Rte_swc_AUXC_vcsb_AUXC_brpd_p_VacPumpPressure_kPa = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_p_VacPumpPressure_kPa.value);
    Rte_swc_AUXC_vcsb_AUXC_brpd_u_VacPumpVol_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_u_VacPumpVol_V.value);
    Rte_swc_AUXC_vcsb_AUXC_lvbd_b_lvbSOCValid = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_lvbd_b_lvbSOCValid.value);
    Rte_swc_AUXC_vcsb_AUXC_lvbd_q_lvbSOC_pct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_lvbd_q_lvbSOC_pct.value);
    Rte_swc_AUXC_vcsb_AUXC_pscd_b_epsEna = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_pscd_b_epsEna.value);
    Rte_swc_AUXC_vcsb_AUXC_pscd_b_epsStopFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_pscd_b_epsStopFlt.value);
    Rte_swc_AUXC_vcsb_AUXC_pscd_frq_epsFrqTgt_Hz = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_pscd_frq_epsFrqTgt_Hz.value);


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_ACCM1_ActPower_ACCM1_ActPower.value = (UInt8)Rte_ComBuffer_ACCM1_ActPower_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_ACU_CrashOutputSts_ACU_CrashOutputSts.value = (UInt8)Rte_ComBuffer_ACU_CrashOutputSts_ACU_ChimeTelltaleReq_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_ACCM_ActPower_AC_ACCM_ActPower.value = (UInt8)Rte_ComBuffer_AC_ACCM_ActPower_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_ACCM_Status_AC_ACCM_Status.value = (Boolean)Rte_ComBuffer_AC_ACCM_Status_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_AmbientTemperature_AC_AmbientTemperature.value = (UInt8)Rte_ComBuffer_AC_AmbientTemperature_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_AmbientTemperatureInvalid_AC_AmbientTemperatureInvalid.value = (Boolean)Rte_ComBuffer_AC_AmbientTemperatureInvalid_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_CabinThermalReq_AC_CabinThermalReq.value = (UInt8)Rte_ComBuffer_AC_CabinThermalReq_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_CoolingFanPWMSpd_AC_CoolingFanPWMSpd.value = (UInt8)Rte_ComBuffer_AC_CoolingFanPWMSpd_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_IPTC_ActPower_AC_IPTC_ActPower.value = (UInt8)Rte_ComBuffer_AC_IPTC_ActPower_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_IPTC_WorkSts_AC_IPTC_WorkSts.value = (Boolean)Rte_ComBuffer_AC_IPTC_WorkSts_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_PTC_ActPower_AC_PTC_ActPower.value = (UInt8)Rte_ComBuffer_AC_PTC_ActPower_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_PTC_ActPwr_Rear_AC_PTC_ActPwr_Rear.value = (UInt8)Rte_ComBuffer_AC_PTC_ActPwr_Rear_AC_Status_Info1_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_PTC_WorkSts_AC_PTC_WorkSts.value = (Boolean)Rte_ComBuffer_AC_PTC_WorkSts_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_PTC_WorkSts_Rear_AC_PTC_WorkSts_Rear.value = (Boolean)Rte_ComBuffer_AC_PTC_WorkSts_Rear_AC_Status_Info1_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BBM_FaultStatus_BBM_FaultStatus.value = (UInt8)Rte_ComBuffer_BBM_FaultStatus_BBM_StsFB_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BBM_WorkSts_BBM_WorkSts.value = (UInt8)Rte_ComBuffer_BBM_WorkSts_BBM_StsFB_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BCM_ATWS_St_BCM_ATWS_St.value = (UInt8)Rte_ComBuffer_BCM_ATWS_St_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BCM_DrvSeatbeltBuckleInvalid_BCM_DrvSeatbeltBuckleInvalid.value = (Boolean)Rte_ComBuffer_BCM_DrvSeatbeltBuckleInvalid_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BCM_DrvSeatbeltBucklestatus_BCM_DrvSeatbeltBucklestatus.value = (Boolean)Rte_ComBuffer_BCM_DrvSeatbeltBucklestatus_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BCM_FrontLeftDoorAjarStatus_BCM_FrontLeftDoorAjarStatus.value = (Boolean)Rte_ComBuffer_BCM_FrontLeftDoorAjarStatus_BCM_LDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BCM_FrontRightDoorAjarStatus_BCM_FrontRightDoorAjarStatus.value = (Boolean)Rte_ComBuffer_BCM_FrontRightDoorAjarStatus_BCM_RDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BCM_IntelligentChargeCommand_BCM_IntelligentChargeCommand.value = (Boolean)Rte_ComBuffer_BCM_IntelligentChargeCommand_BCM_ACCinfor_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BCM_Odometerbackup_BCM_Odometerbackup.value = (UInt16)Rte_ComBuffer_BCM_Odometerbackup_BCM_SunroofState_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_CampModeSwt_CSM_CampModeSwt.value = (Boolean)Rte_ComBuffer_CSM_CampModeSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_CampModeSwtInvalid_CSM_CampModeSwtInvalid.value = (Boolean)Rte_ComBuffer_CSM_CampModeSwtInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_DriveModeReq_CSM_DriveModeReq.value = (Boolean)Rte_ComBuffer_CSM_DriveModeReq_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_DriveModeReqInvalid_CSM_DriveModeReqInvalid.value = (Boolean)Rte_ComBuffer_CSM_DriveModeReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_EngRec_Req_CSM_EngRec_Req.value = (Boolean)Rte_ComBuffer_CSM_EngRec_Req_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_EngRec_ReqInvalid_CSM_EngRec_ReqInvalid.value = (UInt8)Rte_ComBuffer_CSM_EngRec_ReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_TakeEleSwt_CSM_TakeEleSwt.value = (Boolean)Rte_ComBuffer_CSM_TakeEleSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_TakeEleSwt_ReqInvalid_CSM_TakeEleSwt_ReqInvalid.value = (Boolean)Rte_ComBuffer_CSM_TakeEleSwt_ReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_V2XDchaSwt_CSM_V2XDchaSwt.value = (Boolean)Rte_ComBuffer_CSM_V2XDchaSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_V2XDchaSwtInvalid_CSM_V2XDchaSwtInvalid.value = (Boolean)Rte_ComBuffer_CSM_V2XDchaSwtInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_AccessoryConnStsFb_EV_DCDC_AccessoryConnStsFb_EV.value = (UInt8)Rte_ComBuffer_DCDC_AccessoryConnStsFb_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_CANComFault_DCDC_CANComFault.value = (Boolean)Rte_ComBuffer_DCDC_CANComFault_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_CutOffLVFb_DCDC_CutOffLVFb.value = (UInt8)Rte_ComBuffer_DCDC_CutOffLVFb_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_FaultLevel1_DCDC_FaultLevel1.value = (UInt8)Rte_ComBuffer_DCDC_FaultLevel1_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_IDCDCActHiside1_DCDC_IDCDCActHiside1.value = (UInt8)Rte_ComBuffer_DCDC_IDCDCActHiside1_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_IDcDcActLoSide_DCDC_IDcDcActLoSide.value = (UInt8)Rte_ComBuffer_DCDC_IDcDcActLoSide_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_OutOverCurr_DCDC_OutOverCurr.value = (Boolean)Rte_ComBuffer_DCDC_OutOverCurr_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_OutOverVolt_DCDC_OutOverVolt.value = (Boolean)Rte_ComBuffer_DCDC_OutOverVolt_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_PTCConnStsFb_EV_DCDC_PTCConnStsFb_EV.value = (UInt8)Rte_ComBuffer_DCDC_PTCConnStsFb_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_Relay_Volt_DCDC_Relay_Volt.value = (UInt16)Rte_ComBuffer_DCDC_Relay_Volt_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_SelfChkSts_DCDC_SelfChkSts.value = (UInt8)Rte_ComBuffer_DCDC_SelfChkSts_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_TDcDc_DCDC_TDcDc.value = (UInt8)Rte_ComBuffer_DCDC_TDcDc_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_UDCDCActHiside_DCDC_UDCDCActHiside.value = (UInt16)Rte_ComBuffer_DCDC_UDCDCActHiside_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_UDcDcActLoSide_DCDC_UDcDcActLoSide.value = (UInt8)Rte_ComBuffer_DCDC_UDcDcActLoSide_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DcDcActvd_DcDcActvd.value = (Boolean)Rte_ComBuffer_DcDcActvd_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DcDcStsAlm_DcDcStsAlm.value = (Boolean)Rte_ComBuffer_DcDcStsAlm_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EGSM_LeverPosition_EGSM_LeverPosition.value = (UInt8)Rte_ComBuffer_EGSM_LeverPosition_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EGSM_ParkReq_EGSM_ParkReq.value = (UInt8)Rte_ComBuffer_EGSM_ParkReq_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EGSM_ShiftleverFailSt_EGSM_ShiftleverFailSt.value = (UInt8)Rte_ComBuffer_EGSM_ShiftleverFailSt_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_ABSActive_EHB_ABSActive.value = (Boolean)Rte_ComBuffer_EHB_ABSActive_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_ABSFailed_EHB_ABSFailed.value = (Boolean)Rte_ComBuffer_EHB_ABSFailed_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_AEB_active_EHB_AEB_active.value = (Boolean)Rte_ComBuffer_EHB_AEB_active_EHB_DA_MESSAGE_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_AVHStatus_EHB_AVHStatus.value = (UInt8)Rte_ComBuffer_EHB_AVHStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_BrkSysErrFault_EHB_BrkSysErrFault.value = (UInt8)Rte_ComBuffer_EHB_BrkSysErrFault_EHB_DriverRemind_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_DTC_Active_EHB_DTC_Active.value = (Boolean)Rte_ComBuffer_EHB_DTC_Active_EHB_DA_MESSAGE_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_EPBErrorStatus_EHB_EPBErrorStatus.value = (Boolean)Rte_ComBuffer_EHB_EPBErrorStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_EPBStatus_EHB_EPBStatus.value = (UInt8)Rte_ComBuffer_EHB_EPBStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_EPB_DynamicApplystatus_EHB_EPB_DynamicApplystatus.value = (UInt8)Rte_ComBuffer_EHB_EPB_DynamicApplystatus_EHB_DriverRemind_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_FLWheelSpeedKPH_EHB_FLWheelSpeedKPH.value = (UInt16)Rte_ComBuffer_EHB_FLWheelSpeedKPH_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_FRWheelSpeedKPH_EHB_FRWheelSpeedKPH.value = (UInt16)Rte_ComBuffer_EHB_FRWheelSpeedKPH_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_HHCActive_EHB_HHCActive.value = (Boolean)Rte_ComBuffer_EHB_HHCActive_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_ISA_PTTrqDecReq_EHB_ISA_PTTrqDecReq.value = (UInt16)Rte_ComBuffer_EHB_ISA_PTTrqDecReq_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_ISA_PTTrqDecReqActive_EHB_ISA_PTTrqDecReqActive.value = (Boolean)Rte_ComBuffer_EHB_ISA_PTTrqDecReqActive_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_ISA_Status_EHB_ISA_Status.value = (UInt8)Rte_ComBuffer_EHB_ISA_Status_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_MbRegenTargetWheel_EHB_MbRegenTargetWheel.value = (UInt16)Rte_ComBuffer_EHB_MbRegenTargetWheel_EHB_Regen_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_MbRegenTargetWheelSts_EHB_MbRegenTargetWheelSts.value = (UInt8)Rte_ComBuffer_EHB_MbRegenTargetWheelSts_EHB_Regen_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_PTTrqDecReq_EHB_PTTrqDecReq.value = (UInt16)Rte_ComBuffer_EHB_PTTrqDecReq_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_PTTrqDecReqActive_EHB_PTTrqDecReqActive.value = (Boolean)Rte_ComBuffer_EHB_PTTrqDecReqActive_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_PTTrqIncReq_EHB_PTTrqIncReq.value = (UInt16)Rte_ComBuffer_EHB_PTTrqIncReq_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_PTTrqIncReqActive_EHB_PTTrqIncReqActive.value = (Boolean)Rte_ComBuffer_EHB_PTTrqIncReqActive_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_RLWheelSpeedKPH_EHB_RLWheelSpeedKPH.value = (UInt16)Rte_ComBuffer_EHB_RLWheelSpeedKPH_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_RRWheelSpeedKPH_EHB_RRWheelSpeedKPH.value = (UInt16)Rte_ComBuffer_EHB_RRWheelSpeedKPH_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_VLC_Active_EHB_VLC_Active.value = (Boolean)Rte_ComBuffer_EHB_VLC_Active_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_VLC_Available_EHB_VLC_Available.value = (Boolean)Rte_ComBuffer_EHB_VLC_Available_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_VLC_CDD_active_EHB_VLC_CDD_active.value = (Boolean)Rte_ComBuffer_EHB_VLC_CDD_active_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_VLC_PTTrqReq_EHB_VLC_PTTrqReq.value = (UInt16)Rte_ComBuffer_EHB_VLC_PTTrqReq_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_VLC_PTTrqReqActive_EHB_VLC_PTTrqReqActive.value = (Boolean)Rte_ComBuffer_EHB_VLC_PTTrqReqActive_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_VehicleSpeed_EHB_VehicleSpeed.value = (UInt16)Rte_ComBuffer_EHB_VehicleSpeed_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_VehicleSpeedInvalid_EHB_VehicleSpeedInvalid.value = (Boolean)Rte_ComBuffer_EHB_VehicleSpeedInvalid_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EWP_HeatPower_EWP_HeatPower.value = (Boolean)Rte_ComBuffer_EWP_HeatPower_HEWP_1_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EWP_OutputTemp_EWP_OutputTemp.value = (Boolean)Rte_ComBuffer_EWP_OutputTemp_HEWP_1_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_FWFV_CCWFlg_FWFV_CCWFlg.value = (Boolean)Rte_ComBuffer_FWFV_CCWFlg_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_FWFV_CurrentPos_FWFV_CurrentPos.value = (UInt8)Rte_ComBuffer_FWFV_CurrentPos_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_FWFV_InitState_FWFV_InitState.value = (Boolean)Rte_ComBuffer_FWFV_InitState_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_FWFV_MotorState_FWFV_MotorState.value = (Boolean)Rte_ComBuffer_FWFV_MotorState_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_FWFV_OverCurrentFlt_FWFV_OverCurrentFlt.value = (Boolean)Rte_ComBuffer_FWFV_OverCurrentFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_FWFV_OverTempFlt_FWFV_OverTempFlt.value = (Boolean)Rte_ComBuffer_FWFV_OverTempFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_FWFV_OverVoltageFlt_FWFV_OverVoltageFlt.value = (Boolean)Rte_ComBuffer_FWFV_OverVoltageFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_FWFV_RESP_ERROR_FWFV_RESP_ERROR.value = (Boolean)Rte_ComBuffer_FWFV_RESP_ERROR_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_FWFV_UnderVoltageFlt_FWFV_UnderVoltageFlt.value = (Boolean)Rte_ComBuffer_FWFV_UnderVoltageFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_HCM_AcceRelayVolt_HCM_AcceRelayVolt.value = (UInt16)Rte_ComBuffer_HCM_AcceRelayVolt_HCM_Other2RelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_HCM_AcceRelayVoltValidStat_HCM_AcceRelayVoltValidStat.value = (Boolean)Rte_ComBuffer_HCM_AcceRelayVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_HCM_MainPosBackVoltValidStat_HCM_MainPosBackVoltValidStat.value = (Boolean)Rte_ComBuffer_HCM_MainPosBackVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_HCM_PTCRelayVolt_HCM_PTCRelayVolt.value = (UInt16)Rte_ComBuffer_HCM_PTCRelayVolt_HCM_Other2RelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_HCM_PTCRelayVoltValidStat_HCM_PTCRelayVoltValidStat.value = (Boolean)Rte_ComBuffer_HCM_PTCRelayVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPK_AllowChgSoftSwCtrlSt_IPK_AllowChgSoftSwCtrlSt.value = (Boolean)Rte_ComBuffer_IPK_AllowChgSoftSwCtrlSt_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPK_ChrgSoftSwCtrlSt_IPK_ChrgSoftSwCtrlSt.value = (Boolean)Rte_ComBuffer_IPK_ChrgSoftSwCtrlSt_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPK_EngRecMode_Req_IPK_EngRecMode_Req.value = (UInt8)Rte_ComBuffer_IPK_EngRecMode_Req_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPK_IPKTotalOdometer_PT_IPK_IPKTotalOdometer_PT.value = (UInt32)Rte_ComBuffer_IPK_IPKTotalOdometer_IPK_TotalOdometer_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPK_Odometerbackup_IPK_Odometerbackup.value = (UInt16)Rte_ComBuffer_IPK_Odometerbackup_IPK_TotalOdometer_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MHGV_CCWFlg_MHGV_CCWFlg.value = (Boolean)Rte_ComBuffer_MHGV_CCWFlg_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MHGV_CurrentPos_MHGV_CurrentPos.value = (UInt8)Rte_ComBuffer_MHGV_CurrentPos_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MHGV_InitState_MHGV_InitState.value = (Boolean)Rte_ComBuffer_MHGV_InitState_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MHGV_MotorState_MHGV_MotorState.value = (Boolean)Rte_ComBuffer_MHGV_MotorState_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MHGV_OverCurrentFlt_MHGV_OverCurrentFlt.value = (Boolean)Rte_ComBuffer_MHGV_OverCurrentFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MHGV_OverTempFlt_MHGV_OverTempFlt.value = (Boolean)Rte_ComBuffer_MHGV_OverTempFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MHGV_OverVoltageFlt_MHGV_OverVoltageFlt.value = (Boolean)Rte_ComBuffer_MHGV_OverVoltageFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MHGV_RESP_ERROR_MHGV_RESP_ERROR.value = (Boolean)Rte_ComBuffer_MHGV_RESP_ERROR_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MHGV_UnderVoltageFlt_MHGV_UnderVoltageFlt.value = (Boolean)Rte_ComBuffer_MHGV_UnderVoltageFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MMI_LocalBookChrgnTarVal_MMI_LocalBookChrgnTarVal.value = (UInt16)Rte_ComBuffer_MMI_LocalBookChrgnTarVal_MMI_SOCSet_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MMI_RestSwitch_MMI_RestSwitch.value = (UInt8)Rte_ComBuffer_MMI_RestSwitch_MMI_HVSM_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_ChgCCSts_OBC_ChgCCSts.value = (UInt8)Rte_ComBuffer_OBC_ChgCCSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_ChrgrSt_OBC_ChrgrSt.value = (UInt8)Rte_ComBuffer_OBC_ChrgrSt_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_Elock_Stmode_OBC_Elock_Stmode.value = (UInt8)Rte_ComBuffer_OBC_Elock_Stmode_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_LockLoopSts_OBC_LockLoopSts.value = (UInt8)Rte_ComBuffer_OBC_LockLoopSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_OnBdCCline_OBC_OnBdCCline.value = (UInt8)Rte_ComBuffer_OBC_OnBdCCline_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_OnBdCPline_OBC_OnBdCPline.value = (UInt8)Rte_ComBuffer_OBC_OnBdCPline_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_OnBdChrgrT_OBC_OnBdChrgrT.value = (UInt8)Rte_ComBuffer_OBC_OnBdChrgrT_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_OnBdDisChrgrCCline_OBC_OnBdDisChrgrCCline.value = (UInt8)Rte_ComBuffer_OBC_OnBdDisChrgrCCline_OBC_Curr_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_OnBdOuptI_OBC_OnBdOuptI.value = (UInt16)Rte_ComBuffer_OBC_OnBdOuptI_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_OnBdOuptU_OBC_OnBdOuptU.value = (UInt16)Rte_ComBuffer_OBC_OnBdOuptU_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_PwrEgyMgrAvl_OBC_PwrEgyMgrAvl.value = (UInt16)Rte_ComBuffer_OBC_PwrEgyMgrAvl_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_SelfCheSts_OBC_SelfCheSts.value = (UInt8)Rte_ComBuffer_OBC_SelfCheSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_ODP_DCDC_TDcDcAlm_ODP_DCDC_TDcDcAlm.value = (Boolean)Rte_ComBuffer_ODP_DCDC_TDcDcAlm_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_PDC_Brake_Flag_PDC_Brake_Flag.value = (Boolean)Rte_ComBuffer_PDC_Brake_Flag_PDC_Status_Info_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_PEPS_PowerMode_PEPS_PowerMode.value = (UInt8)Rte_ComBuffer_PEPS_PowerMode_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_PEPS_PowerModeValidity_PEPS_PowerModeValidity.value = (UInt8)Rte_ComBuffer_PEPS_PowerModeValidity_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_PEPS_RKECommand_PEPS_RKECommand.value = (UInt8)Rte_ComBuffer_PEPS_RKECommand_PEPS_KeyReminder_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_PEPS_RemoteControlSt_PEPS_RemoteControlSt.value = (Boolean)Rte_ComBuffer_PEPS_RemoteControlSt_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_RFR_ConnectionStatus_RFR_ConnectionStatus.value = (UInt8)Rte_ComBuffer_RFR_ConnectionStatus_Station_Status_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_RFR_Seed_RFR_Seed.value = (UInt32)Rte_ComBuffer_RFR_Seed_RFR_Seed_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_RFR_SwapBatCode_RFR_SwapBatCode.value = (UInt32)Rte_ComBuffer_RFR_SwapBatCode_RFR_SwapBatCode_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_Station_CarLocationConfirm_Station_CarLocationConfirm.value = (Boolean)Rte_ComBuffer_Station_CarLocationConfirm_Station_Status_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_Station_CarStation_Station_CarStation.value = (Boolean)Rte_ComBuffer_Station_CarStation_Station_Status_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_Station_SwapBatRequest_Station_SwapBatRequest.value = (Boolean)Rte_ComBuffer_Station_SwapBatRequest_Station_Status_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_Station_Swapingproceeding_Station_Swapingproceeding.value = (UInt8)Rte_ComBuffer_Station_Swapingproceeding_Station_Status_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_AllowChgCurrentMax_TBOX_AllowChgCurrentMax.value = (UInt8)Rte_ComBuffer_TBOX_AllowChgCurrentMax_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_ChargeDepth_TBOX_ChargeDepth.value = (UInt8)Rte_ComBuffer_TBOX_ChargeDepth_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_ChargeLimitSwitch_TBOX_ChargeLimitSwitch.value = (UInt8)Rte_ComBuffer_TBOX_ChargeLimitSwitch_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_ChrgSoftSwCtrlSt_TBOX_ChrgSoftSwCtrlSt.value = (UInt8)Rte_ComBuffer_TBOX_ChrgSoftSwCtrlSt_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_Day_TBOX_Day.value = (UInt8)Rte_ComBuffer_TBOX_Day_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_Elevation_TBOX_Elevation.value = (UInt16)Rte_ComBuffer_TBOX_Elevation_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_FunAnti_DismantleActive_TBOX_FunAnti_DismantleActive.value = (UInt8)Rte_ComBuffer_TBOX_FunAnti_DismantleActive_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_FunLockVehActive_TBOX_FunLockVehActive.value = (UInt8)Rte_ComBuffer_TBOX_FunLockVehActive_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_Hour_TBOX_Hour.value = (UInt8)Rte_ComBuffer_TBOX_Hour_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_InventorySpdLmtReq_TBOX_InventorySpdLmtReq.value = (UInt8)Rte_ComBuffer_TBOX_InventorySpdLmtReq_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_Life_TBOX_Life.value = (UInt8)Rte_ComBuffer_TBOX_Life_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_LockLimSet_TBOX_LockLimSet.value = (UInt8)Rte_ComBuffer_TBOX_LockLimSet_TBOX_VCULockResp_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_LockVehCtrl_TBOX_LockVehCtrl.value = (UInt8)Rte_ComBuffer_TBOX_LockVehCtrl_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_LockVehPerFlag_TBOX_LockVehPerFlag.value = (UInt8)Rte_ComBuffer_TBOX_LockVehPerFlag_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_LockVehType_TBOX_LockVehType.value = (UInt8)Rte_ComBuffer_TBOX_LockVehType_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_Minute_TBOX_Minute.value = (UInt8)Rte_ComBuffer_TBOX_Minute_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_Month_TBOX_Month.value = (UInt8)Rte_ComBuffer_TBOX_Month_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_PowerOffCmd_TBOX_PowerOffCmd.value = (Boolean)Rte_ComBuffer_TBOX_PowerOffCmd_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_PriorityFullSwitchSts_TBOX_PriorityFullSwitchSts.value = (UInt8)Rte_ComBuffer_TBOX_PriorityFullSwitchSts_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_PriorityFullSwitchSts_UB_TBOX_PriorityFullSwitchSts_UB.value = (Boolean)Rte_ComBuffer_TBOX_PriorityFullSwitchSts_UB_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_ReservationChrgnSts_TBOX_ReservationChrgnSts.value = (UInt8)Rte_ComBuffer_TBOX_ReservationChrgnSts_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_Second_TBOX_Second.value = (UInt8)Rte_ComBuffer_TBOX_Second_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_SpdLmtLevelReq_TBOX_SpdLmtLevelReq.value = (UInt8)Rte_ComBuffer_TBOX_SpdLmtLevelReq_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_VersionConversionFlag_TBOX_VersionConversionFlag.value = (UInt8)Rte_ComBuffer_TBOX_VersionConversionFlag_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_Year_TBOX_Year.value = (UInt8)Rte_ComBuffer_TBOX_Year_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_YRS_LongitAcce_YRS_LongitAcce.value = (UInt16)Rte_ComBuffer_YRS_LongitAcce_YRS2_N72__PMS_C_CAN_20260425_dbc_Rx;

    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BatCurrent_BMSH_BatCurrent.value) = Rte_swc_COL_BMSH_BatCurrent_BMSH_BatCurrent;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BatSOE_BMSH_BatSOE.value) = Rte_swc_COL_BMSH_BatSOE_BMSH_BatSOE;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BatSOH_BMSH_BatSOH.value) = Rte_swc_COL_BMSH_BatSOH_BMSH_BatSOH;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BatTempMax_BMSH_BatTempMax.value) = Rte_swc_COL_BMSH_BatTempMax_BMSH_BatTempMax;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BatTempMin_BMSH_BatTempMin.value) = Rte_swc_COL_BMSH_BatTempMin_BMSH_BatTempMin;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BatUseableSOC_BMSH_BatUseableSOC.value) = Rte_swc_COL_BMSH_BatUseableSOC_BMSH_BatUseableSOC;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BattPackNum_EV_BMSH_BattPackNum_EV.value) = Rte_EVPT_XCUInterFace_Map_BMSH_BattPackNum_EV_BMSH_BattPackNum_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BattSysNum_EV_BMSH_BattSysNum_EV.value) = Rte_EVPT_XCUInterFace_Map_BMSH_BattSysNum_EV_BMSH_BattSysNum_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BattTempAvg_EV_BMSH_BattTempAvg_EV.value) = Rte_EVPT_XCUInterFace_Map_BMSH_BattTempAvg_EV_BMSH_BattTempAvg_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BusVolt_BMSH_BusVolt.value) = Rte_swc_COL_BMSH_BusVolt_BMSH_BusVolt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp.value) = Rte_swc_COL_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp.value) = Rte_swc_COL_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp.value) = Rte_swc_COL_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq.value) = Rte_swc_COL_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform.value) = Rte_swc_COL_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_CellVoltMax_BMSH_CellVoltMax.value) = Rte_swc_COL_BMSH_CellVoltMax_BMSH_CellVoltMax;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_CellVoltMin_BMSH_CellVoltMin.value) = Rte_swc_COL_BMSH_CellVoltMin_BMSH_CellVoltMin;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent.value) = Rte_swc_COL_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_DCChargeProcess_BMSH_DCChargeProcess.value) = Rte_swc_COL_BMSH_DCChargeProcess_BMSH_DCChargeProcess;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_DCChgCurReq_BMSH_DCChgCurReq.value) = Rte_swc_COL_BMSH_DCChgCurReq_BMSH_DCChgCurReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP.value) = Rte_swc_COL_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp.value) = Rte_swc_COL_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp.value) = Rte_swc_COL_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_FinishChgTime_BMSH_FinishChgTime.value) = Rte_swc_COL_BMSH_FinishChgTime_BMSH_FinishChgTime;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_FireAlarm_BMSH_FireAlarm.value) = Rte_swc_COL_BMSH_FireAlarm_BMSH_FireAlarm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_PackVolt_BMSH_PackVolt.value) = Rte_swc_COL_BMSH_PackVolt_BMSH_PackVolt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_StsCC2_BMSH_StsCC2.value) = Rte_swc_COL_BMSH_StsCC2_BMSH_StsCC2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_StsChgFault_BMSH_StsChgFault.value) = Rte_swc_COL_BMSH_StsChgFault_BMSH_StsChgFault;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_StsDischgFault_BMSH_StsDischgFault.value) = Rte_swc_COL_BMSH_StsDischgFault_BMSH_StsDischgFault;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_StsInsulation_BMSH_StsInsulation.value) = Rte_swc_COL_BMSH_StsInsulation_BMSH_StsInsulation;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay.value) = Rte_swc_COL_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay.value) = Rte_swc_COL_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_StsMode_BMSH_StsMode.value) = Rte_swc_COL_BMSH_StsMode_BMSH_StsMode;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_StsPrecharge_BMSH_StsPrecharge.value) = Rte_swc_COL_BMSH_StsPrecharge_BMSH_StsPrecharge;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatIsoAlarm2_EV_BMSH_TBOX_BatIsoAlarm2_EV.value) = Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatIsoAlarm2_EV_BMSH_TBOX_BatIsoAlarm2_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatLowSOC2_EV_BMSH_TBOX_BatLowSOC2_EV.value) = Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatLowSOC2_EV_BMSH_TBOX_BatLowSOC2_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatOverCharge2_EV_BMSH_TBOX_BatOverCharge2_EV.value) = Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverCharge2_EV_BMSH_TBOX_BatOverCharge2_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatOverSOC2_EV_BMSH_TBOX_BatOverSOC2_EV.value) = Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverSOC2_EV_BMSH_TBOX_BatOverSOC2_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatOverTemp2_EV_BMSH_TBOX_BatOverTemp2_EV.value) = Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverTemp2_EV_BMSH_TBOX_BatOverTemp2_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatOverVoltage2_EV_BMSH_TBOX_BatOverVoltage2_EV.value) = Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverVoltage2_EV_BMSH_TBOX_BatOverVoltage2_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum.value) = Rte_swc_COL_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatTempUniformity2_EV_BMSH_TBOX_BatTempUniformity2_EV.value) = Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatTempUniformity2_EV_BMSH_TBOX_BatTempUniformity2_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatUnderVoltage2_EV_BMSH_TBOX_BatUnderVoltage2_EV.value) = Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUnderVoltage2_EV_BMSH_TBOX_BatUnderVoltage2_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatUniformity2_EV_BMSH_TBOX_BatUniformity2_EV.value) = Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUniformity2_EV_BMSH_TBOX_BatUniformity2_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_CellOverVoltage2_EV_BMSH_TBOX_CellOverVoltage2_EV.value) = Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellOverVoltage2_EV_BMSH_TBOX_CellOverVoltage2_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_CellUnderVoltage2_EV_BMSH_TBOX_CellUnderVoltage2_EV.value) = Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellUnderVoltage2_EV_BMSH_TBOX_CellUnderVoltage2_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID.value) = Rte_swc_COL_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID.value) = Rte_swc_COL_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum.value) = Rte_swc_COL_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_FireAlarm_EV_BMSH_TBOX_FireAlarm_EV.value) = Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_FireAlarm_EV_BMSH_TBOX_FireAlarm_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2.value) = Rte_swc_COL_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID.value) = Rte_swc_COL_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID.value) = Rte_swc_COL_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_SOCHop2_EV_BMSH_TBOX_SOCHop2_EV.value) = Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_SOCHop2_EV_BMSH_TBOX_SOCHop2_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr.value) = Rte_swc_COL_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr.value) = Rte_swc_COL_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq.value) = Rte_swc_COL_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_VCU_Crash_BMSH_VCU_Crash.value) = Rte_swc_COL_BMSH_VCU_Crash_BMSH_VCU_Crash;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP.value) = Rte_swc_COL_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq.value) = Rte_swc_COL_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL.value) = Rte_swc_COL_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMS_ChgCCSts_BMS_ChgCCSts.value) = Rte_swc_COL_BMS_ChgCCSts_BMS_ChgCCSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMS_ChgStatus_BMS_ChgStatus.value) = Rte_swc_COL_BMS_ChgStatus_BMS_ChgStatus;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMS_DelayDataUpldEnb_EV_BMS_DelayDataUpldEnb_EV.value) = Rte_EVPT_XCUInterFace_Map_BMS_DelayDataUpldEnb_EV_BMS_DelayDataUpldEnb_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req.value) = Rte_swc_COL_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_ECU_Fun_Config_Data1_ECU_Fun_Config_Data1.value) = Rte_PMS_BswAswRte_ECU_Fun_Config_Data1_ECU_Fun_Config_Data1;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_ECU_Fun_Config_Data2_ECU_Fun_Config_Data2.value) = Rte_PMS_BswAswRte_ECU_Fun_Config_Data2_ECU_Fun_Config_Data2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_ECU_Net_Config_Data1_ECU_Net_Config_Data1.value) = Rte_PMS_BswAswRte_ECU_Net_Config_Data1_ECU_Net_Config_Data1;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_ECU_Net_Config_Data2_ECU_Net_Config_Data2.value) = Rte_PMS_BswAswRte_ECU_Net_Config_Data2_ECU_Net_Config_Data2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AI_BATTERY_TEMPH_5_EXT_AI_BATTERY_TEMPH_5.value) = Rte_PMS_HWI_EXT_AI_BATTERY_TEMPH_5_EXT_AI_BATTERY_TEMPH_5;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AI_BATTERY_TEMPH_6_EXT_AI_BATTERY_TEMPH_6.value) = Rte_PMS_HWI_EXT_AI_BATTERY_TEMPH_6_EXT_AI_BATTERY_TEMPH_6;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AI_MID_COOLING_TEMPH_8_EXT_AI_MID_COOLING_TEMPH_8.value) = Rte_PMS_HWI_EXT_AI_MID_COOLING_TEMPH_8_EXT_AI_MID_COOLING_TEMPH_8;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AI_SENSOR_1_EXT_AI_SENSOR_1.value) = Rte_PMS_HWI_EXT_AI_SENSOR_1_EXT_AI_SENSOR_1;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AI_SENSOR_2_EXT_AI_SENSOR_2.value) = Rte_PMS_HWI_EXT_AI_SENSOR_2_EXT_AI_SENSOR_2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AI_SENSOR_6_EXT_AI_SENSOR_6.value) = Rte_PMS_HWI_EXT_AI_SENSOR_6_EXT_AI_SENSOR_6;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AI_SWITCH_1_EXT_AI_SWITCH_1.value) = Rte_PMS_HWI_EXT_AI_SWITCH_1_EXT_AI_SWITCH_1;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AO_LDO_5V_02_EXT_AO_LDO_5V_02.value) = Rte_PMS_HWI_EXT_AO_LDO_5V_02_EXT_AO_LDO_5V_02;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AO_TRACKING_5V_01_EXT_AO_TRACKING_5V_01.value) = Rte_PMS_HWI_EXT_AO_TRACKING_5V_01_EXT_AO_TRACKING_5V_01;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AO_TRACKING_5V_02_EXT_AO_TRACKING_5V_02.value) = Rte_PMS_HWI_EXT_AO_TRACKING_5V_02_EXT_AO_TRACKING_5V_02;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_CHARGE_ON_AI_EXT_CHARGE_ON_AI.value) = Rte_PMS_HWI_EXT_CHARGE_ON_AI_EXT_CHARGE_ON_AI;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_DI_HS_04_EXT_DI_HS_04.value) = Rte_PMS_HWI_EXT_DI_HS_04_EXT_DI_HS_04;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_DI_HS_05_EXT_DI_HS_05.value) = Rte_PMS_HWI_EXT_DI_HS_05_EXT_DI_HS_05;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_DI_HS_06_EXT_DI_HS_06.value) = Rte_PMS_HWI_EXT_DI_HS_06_EXT_DI_HS_06;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_DI_HS_07_EXT_DI_HS_07.value) = Rte_PMS_HWI_EXT_DI_HS_07_EXT_DI_HS_07;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_DI_HS_08_EXT_DI_HS_08.value) = Rte_PMS_HWI_EXT_DI_HS_08_EXT_DI_HS_08;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_DI_HS_10_EXT_DI_HS_10.value) = Rte_PMS_HWI_EXT_DI_HS_10_EXT_DI_HS_10;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_IGN_ON_AI_EXT_IGN_ON_AI.value) = Rte_PMS_HWI_EXT_IGN_ON_AI_EXT_IGN_ON_AI;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_IGN_ON_DI_EXT_IGN_ON_DI.value) = Rte_PMS_HWI_EXT_IGN_ON_DI_EXT_IGN_ON_DI;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_PI_HVIL_1_DutyCycle_EXT_PI_HVIL_1_DutyCycle.value) = Rte_PMS_HWI_EXT_PI_HVIL_1_DutyCycle_EXT_PI_HVIL_1_DutyCycle;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_PI_HVIL_1_Period_EXT_PI_HVIL_1_Period.value) = Rte_PMS_HWI_EXT_PI_HVIL_1_Period_EXT_PI_HVIL_1_Period;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_PI_HVIL_2_DutyCycle_EXT_PI_HVIL_2_DutyCycle.value) = Rte_PMS_HWI_EXT_PI_HVIL_2_DutyCycle_EXT_PI_HVIL_2_DutyCycle;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_PI_HVIL_2_Period_EXT_PI_HVIL_2_Period.value) = Rte_PMS_HWI_EXT_PI_HVIL_2_Period_EXT_PI_HVIL_2_Period;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_PI_PWM_1_DutyCycle_EXT_PI_PWM_1_DutyCycle.value) = Rte_PMS_HWI_EXT_PI_PWM_1_DutyCycle_EXT_PI_PWM_1_DutyCycle;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_PI_PWM_2_DutyCycle_EXT_PI_PWM_2_DutyCycle.value) = Rte_PMS_HWI_EXT_PI_PWM_2_DutyCycle_EXT_PI_PWM_2_DutyCycle;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_CANCommFlt_IPU_CANCommFlt.value) = Rte_ComTx_CAN_IPU_CANCommFlt_IPU_CANCommFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_DischgState_IPU_DischgState.value) = Rte_ComTx_CAN_IPU_DischgState_IPU_DischgState;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_HVBusCur_EV_IPU_HVBusCur_EV.value) = Rte_EVPT_XCUInterFace_Map_IPU_HVBusCur_EV_IPU_HVBusCur_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_HVBusVolt_EV_IPU_HVBusVolt_EV.value) = Rte_EVPT_XCUInterFace_Map_IPU_HVBusVolt_EV_IPU_HVBusVolt_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_HVBusVolt_IPUSts_IPU_HVBusVolt_IPUSts.value) = Rte_EVPT_XCUInterFace_Map_IPU_HVBusVolt_IPUSts_IPU_HVBusVolt_IPUSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_IGBTFlt_IPU_IGBTFlt.value) = Rte_ComTx_CAN_IPU_IGBTFlt_IPU_IGBTFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_IsgInvrT_IPU_IsgInvrT.value) = Rte_ComTx_CAN_IPU_IsgInvrT_IPU_IsgInvrT;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_IsgModSts_IPU_IsgModSts.value) = Rte_ComTx_CAN_IPU_IsgModSts_IPU_IsgModSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_IsgMotT_IPU_IsgMotT.value) = Rte_ComTx_CAN_IPU_IsgMotT_IPU_IsgMotT;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn.value) = Rte_ComTx_CAN_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid.value) = Rte_ComTx_CAN_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct.value) = Rte_ComTx_CAN_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MCUMemoryFlt_IPU_MCUMemoryFlt.value) = Rte_ComTx_CAN_IPU_MCUMemoryFlt_IPU_MCUMemoryFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MCUTempHighAlarm_IPU_MCUTempHighAlarm.value) = Rte_ComTx_CAN_IPU_MCUTempHighAlarm_IPU_MCUTempHighAlarm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MCUTempHighAlarm1_EV_IPU_MCUTempHighAlarm1_EV.value) = Rte_EVPT_XCUInterFace_Map_IPU_MCUTempHighAlarm1_EV_IPU_MCUTempHighAlarm1_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MCUTempSensorErr_IPU_MCUTempSensorErr.value) = Rte_ComTx_CAN_IPU_MCUTempSensorErr_IPU_MCUTempSensorErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MotorFltLevell1_IPU_MotorFltLevell1.value) = Rte_ComTx_CAN_IPU_MotorFltLevell1_IPU_MotorFltLevell1;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MotorLockRotErr_IPU_MotorLockRotErr.value) = Rte_ComTx_CAN_IPU_MotorLockRotErr_IPU_MotorLockRotErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MotorOverCurrFlt_EV_IPU_MotorOverCurrFlt_EV.value) = Rte_EVPT_XCUInterFace_Map_IPU_MotorOverCurrFlt_EV_IPU_MotorOverCurrFlt_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MotorOverSpdFlt_EV_IPU_MotorOverSpdFlt_EV.value) = Rte_EVPT_XCUInterFace_Map_IPU_MotorOverSpdFlt_EV_IPU_MotorOverSpdFlt_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MotorSpdHighAlarm_IPU_MotorSpdHighAlarm.value) = Rte_ComTx_CAN_IPU_MotorSpdHighAlarm_IPU_MotorSpdHighAlarm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MotorTempHighAlarm_IPU_MotorTempHighAlarm.value) = Rte_ComTx_CAN_IPU_MotorTempHighAlarm_IPU_MotorTempHighAlarm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MotorTempHighFault_IPU_MotorTempHighFault.value) = Rte_ComTx_CAN_IPU_MotorTempHighFault_IPU_MotorTempHighFault;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MotorTempHighFault1_EV_IPU_MotorTempHighFault1_EV.value) = Rte_EVPT_XCUInterFace_Map_IPU_MotorTempHighFault1_EV_IPU_MotorTempHighFault1_EV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MotorTempSensorErr_IPU_MotorTempSensorErr.value) = Rte_ComTx_CAN_IPU_MotorTempSensorErr_IPU_MotorTempSensorErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_RotateInverterFlt_IPU_RotateInverterFlt.value) = Rte_ComTx_CAN_IPU_RotateInverterFlt_IPU_RotateInverterFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_SelfChkSts_IPU_SelfChkSts.value) = Rte_ComTx_CAN_IPU_SelfChkSts_IPU_SelfChkSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax.value) = Rte_ComTx_CAN_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin.value) = Rte_ComTx_CAN_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_KL30_KL30.value) = Rte_PMS_HWI_KL30_KL30;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_PDCStatus_AlvCtrErrFlg_PDCStatus_AlvCtrErrFlg.value) = Rte_PMS_BswAswRte_PDCStatus_AlvCtrErrFlg_PDCStatus_AlvCtrErrFlg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_PDC_Status_CsmErrFlg_PDC_Status_CsmErrFlg.value) = Rte_PMS_BswAswRte_PDC_Status_CsmErrFlg_PDC_Status_CsmErrFlg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_s2vd_BMS_PmtCutoffLVFb_s2vd_BMS_PmtCutoffLVFb.value) = Rte_PMS_BswAswRte_s2vd_BMS_PmtCutoffLVFb_s2vd_BMS_PmtCutoffLVFb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcsb_DIAG_acpd_b_accPed1Vld.value) = Rte_swc_DIAG_vcsb_DIAG_acpd_b_accPed1Vld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcsb_DIAG_acpd_b_accPed2Vld.value) = Rte_swc_DIAG_vcsb_DIAG_acpd_b_accPed2Vld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcsb_DIAG_digd_b_VehLvl32Flt_flg.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl32Flt_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcsb_DIAG_digd_b_VehLvl33Flt_flg.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl33Flt_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcsb_HVSM_dccd_e_modeTgt.value) = Rte_swc_HVSM_vcsb_HVSM_dccd_e_modeTgt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcsb_HVSM_hvbd_b_hvbIntelChgCmplt.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_hvbIntelChgCmplt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcsb_HVSM_hvbd_e_PmmStatus.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcsb_VOMM_drid_e_gearLvrPos.value) = Rte_swc_VOMM_vcsb_VOMM_drid_e_gearLvrPos;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcsb_VOMM_vsmd_b_VehRun.value) = Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRun;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vild_b_flgBBMMsgErr_vild_b_flgBBMMsgErr.value) = Rte_PMS_BswAswRte_vild_b_flgBBMMsgErr_vild_b_flgBBMMsgErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr.value) = Rte_PMS_BswAswRte_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr.value) = Rte_PMS_BswAswRte_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr.value) = Rte_PMS_BswAswRte_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr;
    swc_VCIP_Step();
    Rte_swc_VCIP_vcib_VCIP_accd_b_acHvilOpn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_b_acHvilOpn.value);
    Rte_swc_VCIP_vcib_VCIP_accd_b_acHvilOpnInvld = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_b_acHvilOpnInvld.value);
    Rte_swc_VCIP_vcib_VCIP_accd_e_PtcSt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_e_PtcSt.value);
    Rte_swc_VCIP_vcib_VCIP_accd_e_acFltLvl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_e_acFltLvl.value);
    Rte_swc_VCIP_vcib_VCIP_accd_e_airCmprSt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_e_airCmprSt.value);
    Rte_swc_VCIP_vcib_VCIP_accd_n_acFanReqSpd_pct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_n_acFanReqSpd_pct.value);
    Rte_swc_VCIP_vcib_VCIP_accd_st_AcWrk = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_st_AcWrk.value);
    Rte_swc_VCIP_vcib_VCIP_accd_st_acSubFltSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_st_acSubFltSts.value);
    Rte_swc_VCIP_vcib_VCIP_accd_st_airCmprSt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_st_airCmprSt.value);
    Rte_swc_VCIP_vcib_VCIP_accd_st_cbnThermMngReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_st_cbnThermMngReq.value);
    Rte_swc_VCIP_vcib_VCIP_accd_st_iptWorkSt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_st_iptWorkSt.value);
    Rte_swc_VCIP_vcib_VCIP_accd_st_ptcWorkStRear = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_st_ptcWorkStRear.value);
    Rte_swc_VCIP_vcib_VCIP_accd_t_ambTemp_C = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_t_ambTemp_C.value);
    Rte_swc_VCIP_vcib_VCIP_accd_u_acPresVolt_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_u_acPresVolt_V.value);
    Rte_swc_VCIP_vcib_VCIP_acpd_b_accPedlPosVld = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_b_accPedlPosVld.value);
    Rte_swc_VCIP_vcib_VCIP_acpd_u_accPedlPosSens1VoltRaw_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_u_accPedlPosSens1VoltRaw_V.value);
    Rte_swc_VCIP_vcib_VCIP_acpd_u_accPedlPosSens2VoltRaw_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_u_accPedlPosSens2VoltRaw_V.value);
    Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosCan_pct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_x_accPedlPosCan_pct.value);
    Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosLimd_pct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_x_accPedlPosLimd_pct.value);
    Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosSens1_pct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_x_accPedlPosSens1_pct.value);
    Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosSens2_pct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_x_accPedlPosSens2_pct.value);
    Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPos_pct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_x_accPedlPos_pct.value);
    Rte_swc_VCIP_vcib_VCIP_adcd_b_adc1CtrlTorqEn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_b_adc1CtrlTorqEn.value);
    Rte_swc_VCIP_vcib_VCIP_adcd_b_adc1SwtchCtrlReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_b_adc1SwtchCtrlReq.value);
    Rte_swc_VCIP_vcib_VCIP_adcd_b_adcCtrlGearEn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_b_adcCtrlGearEn.value);
    Rte_swc_VCIP_vcib_VCIP_adcd_b_adcCtrlTorqEn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_b_adcCtrlTorqEn.value);
    Rte_swc_VCIP_vcib_VCIP_adcd_st_adcTgtGearPostn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_st_adcTgtGearPostn.value);
    Rte_swc_VCIP_vcib_VCIP_adcd_st_pmsAdcCtrldSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_st_pmsAdcCtrldSts.value);
    Rte_swc_VCIP_vcib_VCIP_adcd_st_pmsCanBusRecSta = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_st_pmsCanBusRecSta.value);
    Rte_swc_VCIP_vcib_VCIP_adcd_tq_adc1TgtDrvTorq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_tq_adc1TgtDrvTorq_Nm.value);
    Rte_swc_VCIP_vcib_VCIP_adcd_tq_adcTgtDrvTorq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_tq_adcTgtDrvTorq_Nm.value);
    Rte_swc_VCIP_vcib_VCIP_brpd_b_DryAirSwitch = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_DryAirSwitch.value);
    Rte_swc_VCIP_vcib_VCIP_brpd_b_ResrAirSwitch = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_ResrAirSwitch.value);
    Rte_swc_VCIP_vcib_VCIP_brpd_b_brakeSwitch1Closed = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brakeSwitch1Closed.value);
    Rte_swc_VCIP_vcib_VCIP_brpd_b_brakeSwitch2Closed = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brakeSwitch2Closed.value);
    Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPedlPosVld = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brkPedlPosVld.value);
    Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPedlStsVld = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brkPedlStsVld.value);
    Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPmpSelfChkErr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brkPmpSelfChkErr.value);
    Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPmpSelfChkOk = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brkPmpSelfChkOk.value);
    Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPressedFromSwitch = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brkPressedFromSwitch.value);
    Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPumpFault = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brkPumpFault.value);
    Rte_swc_VCIP_vcib_VCIP_brpd_b_vacTankLowPrs = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_vacTankLowPrs.value);
    Rte_swc_VCIP_vcib_VCIP_brpd_e_bdcacWrk = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_e_bdcacWrk.value);
    Rte_swc_VCIP_vcib_VCIP_brpd_e_brkPedalStatus = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_e_brkPedalStatus.value);
    Rte_swc_VCIP_vcib_VCIP_brpd_p_AirPres_kpa = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_p_AirPres_kpa.value);
    Rte_swc_VCIP_vcib_VCIP_brpd_p_brkVacuumPres_bar = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_p_brkVacuumPres_bar.value);
    Rte_swc_VCIP_vcib_VCIP_brpd_st_bdcacWrk = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_st_bdcacWrk.value);
    Rte_swc_VCIP_vcib_VCIP_brpd_x_brkPedlPos_pct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_x_brkPedlPos_pct.value);
    Rte_swc_VCIP_vcib_VCIP_ccdd_u_cruiseADvoltage_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_ccdd_u_cruiseADvoltage_V.value);
    Rte_swc_VCIP_vcib_VCIP_cesd_b_EmergencyStop = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_cesd_b_EmergencyStop.value);
    Rte_swc_VCIP_vcib_VCIP_cesd_b_acuCrash = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_cesd_b_acuCrash.value);
    Rte_swc_VCIP_vcib_VCIP_cesd_b_crash = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_cesd_b_crash.value);
    Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcCutOffLvFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_b_dcdcCutOffLvFb.value);
    Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcHvilFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_b_dcdcHvilFlt.value);
    Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcHvilFltInvld = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_b_dcdcHvilFltInvld.value);
    Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcSelfChkErr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_b_dcdcSelfChkErr.value);
    Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcSelfChkOk = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_b_dcdcSelfChkOk.value);
    Rte_swc_VCIP_vcib_VCIP_dccd_e_24vDcdcModAct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_e_24vDcdcModAct.value);
    Rte_swc_VCIP_vcib_VCIP_dccd_e_dcdcFaultStatus = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_e_dcdcFaultStatus.value);
    Rte_swc_VCIP_vcib_VCIP_dccd_e_modeAct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_e_modeAct.value);
    Rte_swc_VCIP_vcib_VCIP_dccd_pwr_dcdcHVpwr_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_pwr_dcdcHVpwr_kW.value);
    Rte_swc_VCIP_vcib_VCIP_dccd_st_12vDcdcModAct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_st_12vDcdcModAct.value);
    Rte_swc_VCIP_vcib_VCIP_dccd_st_24vDcdcFltSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_st_24vDcdcFltSts.value);
    Rte_swc_VCIP_vcib_VCIP_dccd_st_24vDcdcModAct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_st_24vDcdcModAct.value);
    Rte_swc_VCIP_vcib_VCIP_dccd_st_24vDcdcSubFltSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_st_24vDcdcSubFltSts.value);
    Rte_swc_VCIP_vcib_VCIP_dccd_t_dcdcTemp_C = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_t_dcdcTemp_C.value);
    Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_drvrModeReq.value);
    Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReq4WD = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_drvrModeReq4WD.value);
    Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqECO = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_drvrModeReqECO.value);
    Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqEV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_drvrModeReqEV.value);
    Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqHEV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_drvrModeReqHEV.value);
    Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqSPORT = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_drvrModeReqSPORT.value);
    Rte_swc_VCIP_vcib_VCIP_drid_b_parkBtnPressed = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_parkBtnPressed.value);
    Rte_swc_VCIP_vcib_VCIP_drid_e_gearLvrPosRaw = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_e_gearLvrPosRaw.value);
    Rte_swc_VCIP_vcib_VCIP_drid_st_gearLvrPosSeql = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_st_gearLvrPosSeql.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2ActvDischCmplt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_b_eadInv2ActvDischCmplt.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2RdyToCutOffLV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_b_eadInv2RdyToCutOffLV.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2SelfChkErr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_b_eadInv2SelfChkErr.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2SelfChkOk = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_b_eadInv2SelfChkOk.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_e_eadInv2Sts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_e_eadInv2Sts.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_e_inv21FltSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_e_inv21FltSts.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_e_inv2FltSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_e_inv2FltSts.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_e_inv2ModeAct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_e_inv2ModeAct.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_fact_mot2GearRat = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_fact_mot2GearRat.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_n_mot2ActSpd_rpm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_pwr_mot21ActPwr_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_pwr_mot21ActPwr_kW.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_pwr_mot2ActPwr_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_pwr_mot2ActPwr_kW.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_st_eadInv2PwrActvMod = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_st_eadInv2PwrActvMod.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_st_eadInv2Sts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_st_eadInv2Sts.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_st_eadInv2WrkMod = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_st_eadInv2WrkMod.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_st_eadMot2ImmoRlsChk = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_st_eadMot2ImmoRlsChk.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_st_inv2SubFltSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_st_inv2SubFltSts.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_t_inv2Temp_C = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_t_inv2Temp_C.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_t_mot2Temp_C = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_t_mot2Temp_C.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2ActTq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_tq_mot2ActTq_Nm.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailLTBrk_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailLTBrk_Nm.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailLTBst_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailLTBst_Nm.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailSTBrk_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailSTBrk_Nm.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailSTBst_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailSTBst_Nm.value);
    Rte_swc_VCIP_vcib_VCIP_eadd_u_busInv2HVAct_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_u_busInv2HVAct_V.value);
    Rte_swc_VCIP_vcib_VCIP_epbd_e_parkingSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_epbd_e_parkingSts.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_b_bmsSelfChkErr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_bmsSelfChkErr.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_b_bmsSelfChkOk = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_bmsSelfChkOk.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmCutOffLvFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hcmCutOffLvFb.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmPtcDefRlyCls = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hcmPtcDefRlyCls.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmRlyWldFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hcmRlyWldFlt.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmSelfChkErr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hcmSelfChkErr.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmSelfChkOk = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hcmSelfChkOk.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbChPwrLimdByTemp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hvbChPwrLimdByTemp.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbDischPwrLimdByTemp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hvbDischPwrLimdByTemp.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbHeatEnad = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hvbHeatEnad.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbPrmtCutOffLvFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hvbPrmtCutOffLvFb.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvilOpen = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hvilOpen.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_b_lowTempProtnReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_lowTempProtnReq.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_b_obcChrgReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_obcChrgReq.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmd.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_e_dcdcMainRlySts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_dcdcMainRlySts.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_e_eadInv2MainRlySts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_eadInv2MainRlySts.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_e_hcmMaiRlyNeg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hcmMaiRlyNeg.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_e_hcmWrkSt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hcmWrkSt.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbAssiRly = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hvbAssiRly.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbFaultStatus = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hvbFaultStatus.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMaiRlyNeg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hvbMaiRlyNeg.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMaiRlyPos = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hvbMaiRlyPos.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMainRlySts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hvbMainRlySts.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbStatus = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hvbStatus.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_fact_hvbSOH_pct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_fact_hvbSOH_pct.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_i_hvbCurr_A = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_i_hvbCurr_A.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_PeakChMax_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_PeakChMax_kW.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_PeakDischMax_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_PeakDischMax_kW.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_StatChMax_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_StatChMax_kW.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_StatDischMax_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_StatDischMax_kW.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_hvbActRaw_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_hvbActRaw_kW.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_hvbAct_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_hvbAct_kW.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_hvbChgPwr_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_hvbChgPwr_kW.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_q_hvbSOC_pct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_q_hvbSOC_pct.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_st_hcmFltLvl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hcmFltLvl.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_st_hcmMaiRlyNeg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hcmMaiRlyNeg.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_st_hcmPwrActvMod = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hcmPwrActvMod.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvbPwrActvMod = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hvbPwrActvMod.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvbSubFaultSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hvbSubFaultSts.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvbThermMngReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hvbThermMngReq.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvilOpenSt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hvilOpenSt.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_st_tboxIntelChgQuit = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_tboxIntelChgQuit.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbAvg_C = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_t_hvbAvg_C.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbInCoolTemp_C = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_t_hvbInCoolTemp_C.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbMin_C = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_t_hvbMin_C.value);
    Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbTemp_C = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_t_hvbTemp_C.value);
    Rte_swc_VCIP_vcib_VCIP_macd_V_tankFuelLvl_l = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_V_tankFuelLvl_l.value);
    Rte_swc_VCIP_vcib_VCIP_macd_b_epsSelfChkErr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_b_epsSelfChkErr.value);
    Rte_swc_VCIP_vcib_VCIP_macd_b_epsSelfChkOk = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_b_epsSelfChkOk.value);
    Rte_swc_VCIP_vcib_VCIP_macd_b_pullUpDiagCmpl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_b_pullUpDiagCmpl.value);
    Rte_swc_VCIP_vcib_VCIP_macd_b_vcuSelfChkOk = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_b_vcuSelfChkOk.value);
    Rte_swc_VCIP_vcib_VCIP_macd_e_sdcacWrk = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_e_sdcacWrk.value);
    Rte_swc_VCIP_vcib_VCIP_macd_p_frontAirTankPres_bar = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_p_frontAirTankPres_bar.value);
    Rte_swc_VCIP_vcib_VCIP_macd_p_rearAirTankPres_bar = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_p_rearAirTankPres_bar.value);
    Rte_swc_VCIP_vcib_VCIP_macd_st_epsErrorCode = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_st_epsErrorCode.value);
    Rte_swc_VCIP_vcib_VCIP_macd_st_epsFltLvl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_st_epsFltLvl.value);
    Rte_swc_VCIP_vcib_VCIP_macd_st_epsSubFltLvl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_st_epsSubFltLvl.value);
    Rte_swc_VCIP_vcib_VCIP_macd_st_sdcacWrk = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_st_sdcacWrk.value);
    Rte_swc_VCIP_vcib_VCIP_macd_t_ts5SnsrTemp_C = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_t_ts5SnsrTemp_C.value);
    Rte_swc_VCIP_vcib_VCIP_macd_u_batIntSmpl_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_u_batIntSmpl_V.value);
    Rte_swc_VCIP_vcib_VCIP_obcd_b_obcCANMsgValid = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_b_obcCANMsgValid.value);
    Rte_swc_VCIP_vcib_VCIP_obcd_b_obcChrgCablePlugged = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_b_obcChrgCablePlugged.value);
    Rte_swc_VCIP_vcib_VCIP_obcd_b_obcChrgCableUnplugged = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_b_obcChrgCableUnplugged.value);
    Rte_swc_VCIP_vcib_VCIP_obcd_b_obcSelfChkErr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_b_obcSelfChkErr.value);
    Rte_swc_VCIP_vcib_VCIP_obcd_b_obcSelfChkOk = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_b_obcSelfChkOk.value);
    Rte_swc_VCIP_vcib_VCIP_obcd_b_obcWakeUp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_b_obcWakeUp.value);
    Rte_swc_VCIP_vcib_VCIP_obcd_pwr_obcOutpt_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_pwr_obcOutpt_kW.value);
    Rte_swc_VCIP_vcib_VCIP_obcd_pwr_obcRlTmOutpt_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_pwr_obcRlTmOutpt_kW.value);
    Rte_swc_VCIP_vcib_VCIP_obcd_st_obcfltLvl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_st_obcfltLvl.value);
    Rte_swc_VCIP_vcib_VCIP_obcd_t_obcTemp_C = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_t_obcTemp_C.value);
    Rte_swc_VCIP_vcib_VCIP_pmmd_b_anyIgnOn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_anyIgnOn.value);
    Rte_swc_VCIP_vcib_VCIP_pmmd_b_canIgnOn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_canIgnOn.value);
    Rte_swc_VCIP_vcib_VCIP_pmmd_b_driverStartReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_driverStartReq.value);
    Rte_swc_VCIP_vcib_VCIP_pmmd_b_hwIgnOn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_hwIgnOn.value);
    Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value);
    Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignStsStrt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_ignStsStrt.value);
    Rte_swc_VCIP_vcib_VCIP_pmmd_b_pepsPduLvlValid = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_pepsPduLvlValid.value);
    Rte_swc_VCIP_vcib_VCIP_pmmd_b_ptCanNmStRdy = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_ptCanNmStRdy.value);
    Rte_swc_VCIP_vcib_VCIP_pmmd_e_authenticationStatus = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_e_authenticationStatus.value);
    Rte_swc_VCIP_vcib_VCIP_trad_b_trsm2GearActVld = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_b_trsm2GearActVld.value);
    Rte_swc_VCIP_vcib_VCIP_trad_b_trsm2GearshiftActv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_b_trsm2GearshiftActv.value);
    Rte_swc_VCIP_vcib_VCIP_trad_e_trsm1PrkgSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_e_trsm1PrkgSts.value);
    Rte_swc_VCIP_vcib_VCIP_trad_e_trsm2GearShftResp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_e_trsm2GearShftResp.value);
    Rte_swc_VCIP_vcib_VCIP_trad_fact_trsm2FinalDrvRat = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_fact_trsm2FinalDrvRat.value);
    Rte_swc_VCIP_vcib_VCIP_trad_fact_trsm2GbxGearRat = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_fact_trsm2GbxGearRat.value);
    Rte_swc_VCIP_vcib_VCIP_trad_fact_trsm2GearRat = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_fact_trsm2GearRat.value);
    Rte_swc_VCIP_vcib_VCIP_trad_st_trsm2GearAct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_st_trsm2GearAct.value);
    Rte_swc_VCIP_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh.value);
    Rte_swc_VCIP_vcib_VCIP_vild_R_posInsIRes_Ohm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_R_posInsIRes_Ohm.value);
    Rte_swc_VCIP_vcib_VCIP_vild_a_yrsLongitAcce_mps2 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_a_yrsLongitAcce_mps2.value);
    Rte_swc_VCIP_vcib_VCIP_vild_ang_strWhlAng_rad = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_ang_strWhlAng_rad.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_AccyEnReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_AccyEnReq.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_AccyFltSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_AccyFltSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_CCSginal = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_CCSginal.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_DryAirSwitch = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_DryAirSwitch.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_ResrAirSwitch = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ResrAirSwitch.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_adc1ComErrFlg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_adc1ComErrFlg.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_adcComErrFlg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_adcComErrFlg.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_bcmFrntLftDrAjSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_bcmFrntLftDrAjSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_bcmFrntRDrAjSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_bcmFrntRDrAjSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_brkSwt1Actv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_brkSwt1Actv.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_brkSwt2Actv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_brkSwt2Actv.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_calCanBusOff = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_calCanBusOff.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_cntnrCtrlEnaFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_cntnrCtrlEnaFb.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_csmCampModeSwt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmCampModeSwt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_csmCampModeSwtInvld = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmCampModeSwtInvld.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_csmEngRecSwtReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmEngRecSwtReq.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_csmTakeEleSwt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmTakeEleSwt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_csmTakeEleSwtReqInvld = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmTakeEleSwtReqInvld.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_csmV2XDchaSw = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmV2XDchaSw.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_csmV2XDchaSwInvld = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmV2XDchaSwInvld.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_dcdcStsAlm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_dcdcStsAlm.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_dcdcTempAlm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_dcdcTempAlm.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_disChgSwtSt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_disChgSwtSt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_driverEcoModeReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_driverEcoModeReq.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_ehbIsaPtTrqDecReqActv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ehbIsaPtTrqDecReqActv.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_ehbVlcCddActv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ehbVlcCddActv.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_emgyStopIn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_emgyStopIn.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_epbErrSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_epbErrSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_flgBBMMsgErr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgBBMMsgErr.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgACU = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgACU.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgAccyButton = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgAccyButton.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgAirBag = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgAirBag.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgBatCol = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgBatCol.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgChgTyp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgChgTyp.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgCoastActivBrkLight = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgCoastActivBrkLight.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvMod = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvMod.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvModConn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvModConn.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvModStor = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvModStor.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvSeat = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvSeat.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDualAuthN = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDualAuthN.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgEpdel = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgEpdel.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgMaxChgCurr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgMaxChgCurr.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgMotor = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgMotor.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgTyre = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgTyre.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_flgFnctnConfgEGSM = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFnctnConfgEGSM.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_flgFnctnConfgEHB = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFnctnConfgEHB.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_flgNetConfgABS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgNetConfgABS.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvCcwFlg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvCcwFlg.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvInitSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvInitSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvMotSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvMotSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvOvrCurrFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvOvrCurrFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvOvrTempFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvOvrTempFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvOvrVoltFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvOvrVoltFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvRespErr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvRespErr.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvUndVoltFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvUndVoltFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_hcmMainPosBckVoltVldSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hcmMainPosBckVoltVldSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_hcmPtcRlyVoltVldSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hcmPtcRlyVoltVldSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_hvbDCChgCurReqRngUp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hvbDCChgCurReqRngUp.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_hvbDisChgSopRngUp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hvbDisChgSopRngUp.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_hvbHvilFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hvbHvilFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_hvbInPositionDetct1 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hvbInPositionDetct1.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_hvbInPositionDetct2 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hvbInPositionDetct2.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_hvbZeroPwrReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hvbZeroPwrReq.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_ignStsOn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ignStsOn.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_ignStsStrt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ignStsStrt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_ipkOdoBckUpEn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ipkOdoBckUpEn.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvCcwFlg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvCcwFlg.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvInitSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvInitSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvMotSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvMotSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvOvrCurrFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvOvrCurrFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvOvrTempFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvOvrTempFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvOvrVoltFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvOvrVoltFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvRespErr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvRespErr.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvUndVoltFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvUndVoltFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_obcWakeUpActv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_obcWakeUpActv.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_odometerInvalid = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_odometerInvalid.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_pepsOnSwtSt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_pepsOnSwtSt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_pepsPduLvlVld = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_pepsPduLvlVld.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_pepsRmtCtrlSt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_pepsRmtCtrlSt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_ptCanBusOff = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ptCanBusOff.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_pullUpDiagCmpl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_pullUpDiagCmpl.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_rfrSwapBatReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_rfrSwapBatReq.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_rstAvgPwrConsumption = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_rstAvgPwrConsumption.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_tboxPowOffCmd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_tboxPowOffCmd.value);
    Rte_swc_VCIP_vcib_VCIP_vild_b_tboxPrtFullSwStUB = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_tboxPrtFullSwStUB.value);
    Rte_swc_VCIP_vcib_VCIP_vild_d_bcmOdometerbackup = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_d_bcmOdometerbackup.value);
    Rte_swc_VCIP_vcib_VCIP_vild_d_ipkOdometerbackup = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_d_ipkOdometerbackup.value);
    Rte_swc_VCIP_vcib_VCIP_vild_d_odometer_km = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_d_odometer_km.value);
    Rte_swc_VCIP_vcib_VCIP_vild_i_dcdcInpCurr_A = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_i_dcdcInpCurr_A.value);
    Rte_swc_VCIP_vcib_VCIP_vild_i_hvbCurr_A = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_i_hvbCurr_A.value);
    Rte_swc_VCIP_vcib_VCIP_vild_i_hvbDCChgCurReq_A = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_i_hvbDCChgCurReq_A.value);
    Rte_swc_VCIP_vcib_VCIP_vild_l_whlRad_m = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_l_whlRad_m.value);
    Rte_swc_VCIP_vcib_VCIP_vild_num_hvbCellMaxID = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_num_hvbCellMaxID.value);
    Rte_swc_VCIP_vcib_VCIP_vild_num_hvbCellMinID = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_num_hvbCellMinID.value);
    Rte_swc_VCIP_vcib_VCIP_vild_num_hvbCellSum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_num_hvbCellSum.value);
    Rte_swc_VCIP_vcib_VCIP_vild_num_hvbMaxTempID = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_num_hvbMaxTempID.value);
    Rte_swc_VCIP_vcib_VCIP_vild_num_hvbMinTempID = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_num_hvbMinTempID.value);
    Rte_swc_VCIP_vcib_VCIP_vild_num_hvbTempSum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_num_hvbTempSum.value);
    Rte_swc_VCIP_vcib_VCIP_vild_pct_GearPosn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_GearPosn.value);
    Rte_swc_VCIP_vcib_VCIP_vild_pct_HVILReturnPWM = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_HVILReturnPWM.value);
    Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP1FbPWM = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_WatPmpEP1FbPWM.value);
    Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP2FbPWM = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_WatPmpEP2FbPWM.value);
    Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP3FbPWM = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_WatPmpEP3FbPWM.value);
    Rte_swc_VCIP_vcib_VCIP_vild_pct_fan1Fb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_fan1Fb.value);
    Rte_swc_VCIP_vcib_VCIP_vild_pct_fan2Fb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_fan2Fb.value);
    Rte_swc_VCIP_vcib_VCIP_vild_pct_fwfvCrtPos = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_fwfvCrtPos.value);
    Rte_swc_VCIP_vcib_VCIP_vild_pct_mhgvCrtPos = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_mhgvCrtPos.value);
    Rte_swc_VCIP_vcib_VCIP_vild_pct_mmiLocBkChgTarVal = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_mmiLocBkChgTarVal.value);
    Rte_swc_VCIP_vcib_VCIP_vild_pct_tboxAlwChgCurrMax = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_tboxAlwChgCurrMax.value);
    Rte_swc_VCIP_vcib_VCIP_vild_pct_tboxChgDepth = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_tboxChgDepth.value);
    Rte_swc_VCIP_vcib_VCIP_vild_pwr_PTCActPwr_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pwr_PTCActPwr_kW.value);
    Rte_swc_VCIP_vcib_VCIP_vild_pwr_acwpHeatPower_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pwr_acwpHeatPower_kW.value);
    Rte_swc_VCIP_vcib_VCIP_vild_pwr_airCmprAct_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pwr_airCmprAct_kW.value);
    Rte_swc_VCIP_vcib_VCIP_vild_pwr_iptActPwr_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pwr_iptActPwr_kW.value);
    Rte_swc_VCIP_vcib_VCIP_vild_pwr_ptcActPwrRear_kW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pwr_ptcActPwrRear_kW.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_24vDcdcModAct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_24vDcdcModAct.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_BmsTempOutOfCtrlFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_BmsTempOutOfCtrlFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXFunAntiDismantleActive = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_TBOXFunAntiDismantleActive.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXFunLockVehActive = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_TBOXFunLockVehActive.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockLimSet = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_TBOXLockLimSet.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockResultResp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_TBOXLockResultResp.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockVehCtrl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_TBOXLockVehCtrl.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockVehType = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_TBOXLockVehType.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_actWorkSts1 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_actWorkSts1.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_batLowSoc2 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_batLowSoc2.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_batOvrSoc2 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_batOvrSoc2.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_batOvrVolt2 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_batOvrVolt2.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_batUdrVolt2 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_batUdrVolt2.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_bbmFltSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bbmFltSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_bbmWorkSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bbmWorkSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_bmsBattPackMatchFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bmsBattPackMatchFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_bmsBattPackNum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bmsBattPackNum.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_bmsBattSysNum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bmsBattSysNum.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_bmsDlyDataUpldEnb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bmsDlyDataUpldEnb.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_bmsTboxFireAlm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bmsTboxFireAlm.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_cellOverVolt2 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_cellOverVolt2.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_cellUdrVolt2 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_cellUdrVolt2.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_csmEngRecReqInvalid = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_csmEngRecReqInvalid.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_csmRgnLvlSet = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_csmRgnLvlSet.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_dcChgCcSt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_dcChgCcSt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_dccAccyConnStsFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_dccAccyConnStsFb.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_eadInv2FltSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_eadInv2FltSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_eadInv2TempHiAlrm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_eadInv2TempHiAlrm.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_egsmShftLvrFailSt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_egsmShftLvrFailSt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_ehbBrkSysErrFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ehbBrkSysErrFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_ehbIsaSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ehbIsaSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_epsEpasFail = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_epsEpasFail.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_flg2FctCfgVehTyp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flg2FctCfgVehTyp.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgAccy = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgAccy.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgBatTyp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgBatTyp.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgDspRemainRng = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgDspRemainRng.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgECOMaxSpd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgECOMaxSpd.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgFan = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgFan.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgMaxSpd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgMaxSpd.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgMotTyp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgMotTyp.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgPowerMaxSpd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgPowerMaxSpd.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgSlowChg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgSlowChg.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgV2L = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgV2L.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehCfg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehCfg.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehTyp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehTyp.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehUsg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehUsg.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hcmAccConnStsFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hcmAccConnStsFb.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hcmHvilSt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hcmHvilSt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hcmPTC1ConnStsFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hcmPTC1ConnStsFb.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hcmPtcDefRlyStFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hcmPtcDefRlyStFb.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbBatUniformity = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbBatUniformity.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbBattIsolationSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbBattIsolationSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbCellTempDevFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbCellTempDevFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbCellVoltDevFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbCellVoltDevFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgCcsts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbChgCcsts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgFltReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbChgFltReq.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgOvrCurr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbChgOvrCurr.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbChgSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgPlgNOvrTmp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbDCChgPlgNOvrTmp.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgPlgPOvrTmp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbDCChgPlgPOvrTmp.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgProcss = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbDCChgProcss.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDischgFltReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbDischgFltReq.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbInslErr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbInslErr.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbOvrChgFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbOvrChgFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbPreChgSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbPreChgSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbSocFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbSocFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbSocJumpFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbSocJumpFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStatus = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbStatus.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStsChgFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbStsChgFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStsDischgFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbStsDischgFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbTempFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbTempFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_hvbThermMngReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbThermMngReq.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_ipkAlwChgSftCtlSt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipkAlwChgSftCtlSt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_ipkChgSftSwCtlSt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipkChgSftSwCtlSt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_ipkCruisingDstSwt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipkCruisingDstSwt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_ipuInvTempHighAlm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipuInvTempHighAlm.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_ipuMotTempHighFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipuMotTempHighFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_ipuMotorOverCurrFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipuMotorOverCurrFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_ipuMotorOverSpdFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipuMotorOverSpdFlt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_mmiRestSwitch = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_mmiRestSwitch.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_obcChgCCSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_obcChgCCSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_obcChgSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_obcChgSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_obcElckStMod = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_obcElckStMod.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_obcOnBdCCline = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_obcOnBdCCline.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_obcOnBdDchaCCline = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_obcOnBdDchaCCline.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_pepsPduLvl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_pepsPduLvl.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_pepsPduLvlVld = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_pepsPduLvlVld.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_pepsRKECom = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_pepsRKECom.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_ptcConnStsFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ptcConnStsFb.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_rfrConnctSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_rfrConnctSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_rfrSwapprocd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_rfrSwapprocd.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_tboxChgLmtSw = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxChgLmtSw.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_tboxChgSftSwCtlSt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxChgSftSwCtlSt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_tboxInventorySpdLmtReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxInventorySpdLmtReq.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_tboxLife = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxLife.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_tboxLockVehPerFlag = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxLockVehPerFlag.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_tboxPrtFullSwSt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxPrtFullSwSt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_tboxRsrChgSt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxRsrChgSt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_tboxSpdLmtLevelReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxSpdLmtLevelReq.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_tboxStartBattChgReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxStartBattChgReq.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_tboxVersionConversionFlag = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxVersionConversionFlag.value);
    Rte_swc_VCIP_vcib_VCIP_vild_st_vscEHBAVHSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_vscEHBAVHSts.value);
    Rte_swc_VCIP_vcib_VCIP_vild_t_TS5sensorFb_C = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_TS5sensorFb_C.value);
    Rte_swc_VCIP_vcib_VCIP_vild_t_acwpOutptTemp_C = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_acwpOutptTemp_C.value);
    Rte_swc_VCIP_vcib_VCIP_vild_t_hvbCooltInTemp_C = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_hvbCooltInTemp_C.value);
    Rte_swc_VCIP_vcib_VCIP_vild_t_hvbCooltOutTemp_C = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_hvbCooltOutTemp_C.value);
    Rte_swc_VCIP_vcib_VCIP_vild_t_hvbMax_C = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_hvbMax_C.value);
    Rte_swc_VCIP_vcib_VCIP_vild_t_hvbMin_C = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_hvbMin_C.value);
    Rte_swc_VCIP_vcib_VCIP_vild_t_hvbOutCoolTemp_C = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_hvbOutCoolTemp_C.value);
    Rte_swc_VCIP_vcib_VCIP_vild_t_hvbSetTgtTemp_C = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_hvbSetTgtTemp_C.value);
    Rte_swc_VCIP_vcib_VCIP_vild_tm_hvbFnshChgTim_m = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_tm_hvbFnshChgTim_m.value);
    Rte_swc_VCIP_vcib_VCIP_vild_tq_ehbIsaPtTrqDecReq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_tq_ehbIsaPtTrqDecReq_Nm.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_5VT1IntSmpl_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_5VT1IntSmpl_V.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_5VT2IntSmpl_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_5VT2IntSmpl_V.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_Acc1Raw_mV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_Acc1Raw_mV.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_Acc2Raw_mV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_Acc2Raw_mV.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_BmsMaxCellVolt_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_BmsMaxCellVolt_V.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_BmsMinCellVolt_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_BmsMinCellVolt_V.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_Brk2Raw_mV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_Brk2Raw_mV.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_Brk2_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_Brk2_V.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_BrkRaw_mV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_BrkRaw_mV.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_Brk_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_Brk_V.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_TS5sensorFb_mV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_TS5sensorFb_mV.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_VacTkAirPres_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_VacTkAirPres_V.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_VacTkEnFb_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_VacTkEnFb_V.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_accPdlSens1InpVolt_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_accPdlSens1InpVolt_V.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_accPdlSens2InpVolt_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_accPdlSens2InpVolt_V.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_batLpPmpCtrlFb_mV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_batLpPmpCtrlFb_mV.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_brkVacuumPres_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_brkVacuumPres_V.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_cbnLpPmpCtrlFb_mV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_cbnLpPmpCtrlFb_mV.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_dcdcRelayVolt_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_dcdcRelayVolt_V.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_eLpWpCtrlCur_mV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_eLpWpCtrlCur_mV.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_hcmAcceRlyVolt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hcmAcceRlyVolt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_hcmMainPosBckVolt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hcmMainPosBckVolt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_hcmPtcRlyVolt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hcmPtcRlyVolt.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_hvbCooltInSnsr_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hvbCooltInSnsr_V.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_hvbCooltOutSnsr_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hvbCooltOutSnsr_V.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_hvbPackVolt_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hvbPackVolt_V.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_hvbVolt_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hvbVolt_V.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_ipuHVBusVolt_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_ipuHVBusVolt_V.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_pepsOn_mV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_pepsOn_mV.value);
    Rte_swc_VCIP_vcib_VCIP_vild_u_vacTkPowSup_V = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_vacTkPowSup_V.value);
    Rte_swc_VCIP_vcib_VCIP_vild_v_ehbVehSpd_kph = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_v_ehbVehSpd_kph.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_a_vscLongitAcce_mps2 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_a_vscLongitAcce_mps2.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_b_ESPActv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ESPActv.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_b_ESPActvRaw = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ESPActvRaw.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbAbsOvrdActv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbAbsOvrdActv.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbAebActv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbAebActv.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbDtcActv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbDtcActv.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbTrqDecReqActv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbTrqDecReqActv.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbTrqIncReqActv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbTrqIncReqActv.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbVlcActv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbVlcActv.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbVlcAvailb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbVlcAvailb.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbVlcTrqReqActv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbVlcTrqReqActv.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_b_pdcBrkFlg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_pdcBrkFlg.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSlipWarn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_vehSlipWarn.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSpdVld = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_vehSpdVld.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_b_vscBrkLghtActv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_vscBrkLghtActv.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbAVHSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_st_ehbAVHSts.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbEPBDynAppSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_st_ehbEPBDynAppSts.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbHHCActive = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_st_ehbHHCActive.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbMbRgnTgtWhlSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_st_ehbMbRgnTgtWhlSts.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_st_vscIsgActvDampModReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_st_vscIsgActvDampModReq.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_tq_axle2MaxTqReq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_axle2MaxTqReq_Nm.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_tq_axle2MinTqReq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_axle2MinTqReq_Nm.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_tq_axle2RgnBrkTqReq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_axle2RgnBrkTqReq_Nm.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbMbRgnTgtWhl_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_ehbMbRgnTgtWhl_Nm.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbTrqDecReq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_ehbTrqDecReq_Nm.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbTrqIncReq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_ehbTrqIncReq_Nm.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbVlcTrqReq_Nm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_ehbVlcTrqReq_Nm.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpdRaw_kph = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_v_vehSpdRaw_kph.value);
    Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value);

    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_10_Fb_EXT_DO_RELAY_LS_10_Fb.value) = Rte_PMS_BswAswRte_EXT_DO_RELAY_LS_10_Fb_EXT_DO_RELAY_LS_10_Fb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_7_Fb_EXT_DO_RELAY_LS_7_Fb.value) = Rte_PMS_BswAswRte_EXT_DO_RELAY_LS_7_Fb_EXT_DO_RELAY_LS_7_Fb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_9_Fb_EXT_DO_RELAY_LS_9_Fb.value) = Rte_PMS_BswAswRte_EXT_DO_RELAY_LS_9_Fb_EXT_DO_RELAY_LS_9_Fb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte0_F190_VIN_Byte0.value) = Rte_PMS_BswAswRte_F190_VIN_Byte0_F190_VIN_Byte0;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte1_F190_VIN_Byte1.value) = Rte_PMS_BswAswRte_F190_VIN_Byte1_F190_VIN_Byte1;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte10_F190_VIN_Byte10.value) = Rte_PMS_BswAswRte_F190_VIN_Byte10_F190_VIN_Byte10;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte11_F190_VIN_Byte11.value) = Rte_PMS_BswAswRte_F190_VIN_Byte11_F190_VIN_Byte11;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte12_F190_VIN_Byte12.value) = Rte_PMS_BswAswRte_F190_VIN_Byte12_F190_VIN_Byte12;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte13_F190_VIN_Byte13.value) = Rte_PMS_BswAswRte_F190_VIN_Byte13_F190_VIN_Byte13;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte14_F190_VIN_Byte14.value) = Rte_PMS_BswAswRte_F190_VIN_Byte14_F190_VIN_Byte14;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte15_F190_VIN_Byte15.value) = Rte_PMS_BswAswRte_F190_VIN_Byte15_F190_VIN_Byte15;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte16_F190_VIN_Byte16.value) = Rte_PMS_BswAswRte_F190_VIN_Byte16_F190_VIN_Byte16;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte2_F190_VIN_Byte2.value) = Rte_PMS_BswAswRte_F190_VIN_Byte2_F190_VIN_Byte2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte3_F190_VIN_Byte3.value) = Rte_PMS_BswAswRte_F190_VIN_Byte3_F190_VIN_Byte3;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte4_F190_VIN_Byte4.value) = Rte_PMS_BswAswRte_F190_VIN_Byte4_F190_VIN_Byte4;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte5_F190_VIN_Byte5.value) = Rte_PMS_BswAswRte_F190_VIN_Byte5_F190_VIN_Byte5;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte6_F190_VIN_Byte6.value) = Rte_PMS_BswAswRte_F190_VIN_Byte6_F190_VIN_Byte6;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte7_F190_VIN_Byte7.value) = Rte_PMS_BswAswRte_F190_VIN_Byte7_F190_VIN_Byte7;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte8_F190_VIN_Byte8.value) = Rte_PMS_BswAswRte_F190_VIN_Byte8_F190_VIN_Byte8;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte9_F190_VIN_Byte9.value) = Rte_PMS_BswAswRte_F190_VIN_Byte9_F190_VIN_Byte9;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F193_ECUHardwareVersionNumber_Byte2_F193_ECUHardwareVersionNumber_Byte2.value) = Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte2_F193_ECUHardwareVersionNumber_Byte2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F193_ECUHardwareVersionNumber_Byte3_F193_ECUHardwareVersionNumber_Byte3.value) = Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte3_F193_ECUHardwareVersionNumber_Byte3;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F193_ECUHardwareVersionNumber_Byte4_F193_ECUHardwareVersionNumber_Byte4.value) = Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte4_F193_ECUHardwareVersionNumber_Byte4;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F193_ECUHardwareVersionNumber_Byte6_F193_ECUHardwareVersionNumber_Byte6.value) = Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte6_F193_ECUHardwareVersionNumber_Byte6;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F193_ECUHardwareVersionNumber_Byte7_F193_ECUHardwareVersionNumber_Byte7.value) = Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte7_F193_ECUHardwareVersionNumber_Byte7;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F193_ECUHardwareVersionNumber_Byte8_F193_ECUHardwareVersionNumber_Byte8.value) = Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte8_F193_ECUHardwareVersionNumber_Byte8;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F195_ECUSoftwareVersionNumber_Byte2_F195_ECUSoftwareVersionNumber_Byte2.value) = Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte2_F195_ECUSoftwareVersionNumber_Byte2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F195_ECUSoftwareVersionNumber_Byte3_F195_ECUSoftwareVersionNumber_Byte3.value) = Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte3_F195_ECUSoftwareVersionNumber_Byte3;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F195_ECUSoftwareVersionNumber_Byte4_F195_ECUSoftwareVersionNumber_Byte4.value) = Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte4_F195_ECUSoftwareVersionNumber_Byte4;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F195_ECUSoftwareVersionNumber_Byte6_F195_ECUSoftwareVersionNumber_Byte6.value) = Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte6_F195_ECUSoftwareVersionNumber_Byte6;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F195_ECUSoftwareVersionNumber_Byte7_F195_ECUSoftwareVersionNumber_Byte7.value) = Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte7_F195_ECUSoftwareVersionNumber_Byte7;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F195_ECUSoftwareVersionNumber_Byte8_F195_ECUSoftwareVersionNumber_Byte8.value) = Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte8_F195_ECUSoftwareVersionNumber_Byte8;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_accd_b_acHvilOpn.value) = Rte_swc_VCIP_vcib_VCIP_accd_b_acHvilOpn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_accd_b_acHvilOpnInvld.value) = Rte_swc_VCIP_vcib_VCIP_accd_b_acHvilOpnInvld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_acpd_b_accPedlPosVld.value) = Rte_swc_VCIP_vcib_VCIP_acpd_b_accPedlPosVld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_acpd_x_accPedlPosCan_pct.value) = Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosCan_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_acpd_x_accPedlPosSens1_pct.value) = Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosSens1_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_acpd_x_accPedlPosSens2_pct.value) = Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosSens2_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_adcd_b_adcCtrlGearEn.value) = Rte_swc_VCIP_vcib_VCIP_adcd_b_adcCtrlGearEn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_adcd_st_pmsAdcCtrldSts.value) = Rte_swc_VCIP_vcib_VCIP_adcd_st_pmsAdcCtrldSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_adcd_st_pmsCanBusRecSta.value) = Rte_swc_VCIP_vcib_VCIP_adcd_st_pmsCanBusRecSta;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_brpd_b_brkPressedFromSwitch.value) = Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPressedFromSwitch;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_brpd_p_brkVacuumPres_bar.value) = Rte_swc_VCIP_vcib_VCIP_brpd_p_brkVacuumPres_bar;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_brpd_x_brkPedlPos_pct.value) = Rte_swc_VCIP_vcib_VCIP_brpd_x_brkPedlPos_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_cesd_b_acuCrash.value) = Rte_swc_VCIP_vcib_VCIP_cesd_b_acuCrash;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_dccd_b_dcdcHvilFlt.value) = Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcHvilFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_dccd_b_dcdcHvilFltInvld.value) = Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcHvilFltInvld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_drid_st_gearLvrPosSeql.value) = Rte_swc_VCIP_vcib_VCIP_drid_st_gearLvrPosSeql;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A.value) = Rte_swc_VCIP_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm.value) = Rte_swc_VCIP_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_eadd_tq_mot2ActTq_Nm.value) = Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2ActTq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_eadd_u_busInv2HVAct_V.value) = Rte_swc_VCIP_vcib_VCIP_eadd_u_busInv2HVAct_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_epbd_e_parkingSts.value) = Rte_swc_VCIP_vcib_VCIP_epbd_e_parkingSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_b_hvilOpen.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvilOpen;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_e_hvbStatus.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbStatus;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_fact_hvbSOH_pct.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_fact_hvbSOH_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_i_hvbCurr_A.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_i_hvbCurr_A;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_pwr_hvbChgPwr_kW.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_hvbChgPwr_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_q_hvbSOC_pct.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_q_hvbSOC_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_st_hvbThermMngReq.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvbThermMngReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_st_tboxIntelChgQuit.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_st_tboxIntelChgQuit;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_t_hvbAvg_C.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbAvg_C;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_t_hvbInCoolTemp_C.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbInCoolTemp_C;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_t_hvbMin_C.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbMin_C;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_t_hvbTemp_C.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbTemp_C;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_macd_b_vcuSelfChkOk.value) = Rte_swc_VCIP_vcib_VCIP_macd_b_vcuSelfChkOk;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_macd_t_ts5SnsrTemp_C.value) = Rte_swc_VCIP_vcib_VCIP_macd_t_ts5SnsrTemp_C;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_macd_u_batIntSmpl_V.value) = Rte_swc_VCIP_vcib_VCIP_macd_u_batIntSmpl_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value) = Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_trad_fact_trsm2GearRat.value) = Rte_swc_VCIP_vcib_VCIP_trad_fact_trsm2GearRat;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_trad_st_trsm2GearAct.value) = Rte_swc_VCIP_vcib_VCIP_trad_st_trsm2GearAct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh.value) = Rte_swc_VCIP_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_R_posInsIRes_Ohm.value) = Rte_swc_VCIP_vcib_VCIP_vild_R_posInsIRes_Ohm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_ang_strWhlAng_rad.value) = Rte_swc_VCIP_vcib_VCIP_vild_ang_strWhlAng_rad;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_AccyEnReq.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_AccyEnReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_AccyFltSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_AccyFltSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_CCSginal.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_CCSginal;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_DryAirSwitch.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_DryAirSwitch;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_ResrAirSwitch.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_ResrAirSwitch;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_brkSwt1Actv.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_brkSwt1Actv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_brkSwt2Actv.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_brkSwt2Actv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_cntnrCtrlEnaFb.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_cntnrCtrlEnaFb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_dcdcStsAlm.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_dcdcStsAlm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_dcdcTempAlm.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_dcdcTempAlm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_disChgSwtSt.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_disChgSwtSt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_driverEcoModeReq.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_driverEcoModeReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_emgyStopIn.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_emgyStopIn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgBatCol.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgBatCol;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_fwfvCcwFlg.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvCcwFlg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_fwfvInitSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvInitSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_fwfvMotSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvMotSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_fwfvOvrCurrFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvOvrCurrFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_fwfvOvrTempFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvOvrTempFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_fwfvOvrVoltFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvOvrVoltFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_fwfvRespErr.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvRespErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_fwfvUndVoltFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvUndVoltFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_hvbHvilFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_hvbHvilFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_ignStsOn.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_ignStsOn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_ignStsStrt.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_ignStsStrt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_mhgvCcwFlg.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvCcwFlg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_mhgvInitSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvInitSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_mhgvMotSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvMotSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_mhgvOvrCurrFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvOvrCurrFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_mhgvOvrTempFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvOvrTempFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_mhgvOvrVoltFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvOvrVoltFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_mhgvRespErr.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvRespErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_mhgvUndVoltFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvUndVoltFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_obcWakeUpActv.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_obcWakeUpActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_odometerInvalid.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_odometerInvalid;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_d_odometer_km.value) = Rte_swc_VCIP_vcib_VCIP_vild_d_odometer_km;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_i_dcdcInpCurr_A.value) = Rte_swc_VCIP_vcib_VCIP_vild_i_dcdcInpCurr_A;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_i_hvbCurr_A.value) = Rte_swc_VCIP_vcib_VCIP_vild_i_hvbCurr_A;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_num_hvbCellMaxID.value) = Rte_swc_VCIP_vcib_VCIP_vild_num_hvbCellMaxID;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_num_hvbCellMinID.value) = Rte_swc_VCIP_vcib_VCIP_vild_num_hvbCellMinID;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_num_hvbCellSum.value) = Rte_swc_VCIP_vcib_VCIP_vild_num_hvbCellSum;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_num_hvbMaxTempID.value) = Rte_swc_VCIP_vcib_VCIP_vild_num_hvbMaxTempID;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_num_hvbMinTempID.value) = Rte_swc_VCIP_vcib_VCIP_vild_num_hvbMinTempID;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_num_hvbTempSum.value) = Rte_swc_VCIP_vcib_VCIP_vild_num_hvbTempSum;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_pct_GearPosn.value) = Rte_swc_VCIP_vcib_VCIP_vild_pct_GearPosn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_pct_HVILReturnPWM.value) = Rte_swc_VCIP_vcib_VCIP_vild_pct_HVILReturnPWM;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_pct_WatPmpEP1FbPWM.value) = Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP1FbPWM;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_pct_WatPmpEP2FbPWM.value) = Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP2FbPWM;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_pct_WatPmpEP3FbPWM.value) = Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP3FbPWM;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_pct_fan1Fb.value) = Rte_swc_VCIP_vcib_VCIP_vild_pct_fan1Fb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_pct_fan2Fb.value) = Rte_swc_VCIP_vcib_VCIP_vild_pct_fan2Fb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_pct_fwfvCrtPos.value) = Rte_swc_VCIP_vcib_VCIP_vild_pct_fwfvCrtPos;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_pct_mhgvCrtPos.value) = Rte_swc_VCIP_vcib_VCIP_vild_pct_mhgvCrtPos;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_24vDcdcModAct.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_24vDcdcModAct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_BmsTempOutOfCtrlFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_BmsTempOutOfCtrlFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_actWorkSts1.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_actWorkSts1;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_batLowSoc2.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_batLowSoc2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_batOvrSoc2.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_batOvrSoc2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_batOvrVolt2.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_batOvrVolt2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_batUdrVolt2.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_batUdrVolt2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_bmsBattPackMatchFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_bmsBattPackMatchFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_bmsBattPackNum.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_bmsBattPackNum;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_bmsBattSysNum.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_bmsBattSysNum;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_bmsTboxFireAlm.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_bmsTboxFireAlm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_cellOverVolt2.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_cellOverVolt2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_cellUdrVolt2.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_cellUdrVolt2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_dcChgCcSt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_dcChgCcSt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_eadInv2TempHiAlrm.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_eadInv2TempHiAlrm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_ehbBrkSysErrFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_ehbBrkSysErrFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_epsEpasFail.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_epsEpasFail;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_flg2FctCfgVehTyp.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flg2FctCfgVehTyp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgAccy.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgAccy;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbBatUniformity.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbBatUniformity;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbBattIsolationSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbBattIsolationSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbCellTempDevFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbCellTempDevFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbCellVoltDevFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbCellVoltDevFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbChgOvrCurr.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgOvrCurr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbDCChgPlgNOvrTmp.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgPlgNOvrTmp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbDCChgPlgPOvrTmp.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgPlgPOvrTmp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbDCChgProcss.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgProcss;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbInslErr.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbInslErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbOvrChgFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbOvrChgFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbSocFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbSocFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbSocJumpFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbSocJumpFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbStatus.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStatus;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbStsChgFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStsChgFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbStsDischgFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStsDischgFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbTempFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbTempFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbThermMngReq.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbThermMngReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_ipuInvTempHighAlm.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_ipuInvTempHighAlm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_ipuMotTempHighFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_ipuMotTempHighFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_ipuMotorOverCurrFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_ipuMotorOverCurrFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_ipuMotorOverSpdFlt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_ipuMotorOverSpdFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_obcChgSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_obcChgSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_obcOnBdCCline.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_obcOnBdCCline;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_pepsPduLvl.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_pepsPduLvl;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_pepsPduLvlVld.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_pepsPduLvlVld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_tboxRsrChgSt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_tboxRsrChgSt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_t_acwpOutptTemp_C.value) = Rte_swc_VCIP_vcib_VCIP_vild_t_acwpOutptTemp_C;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_t_hvbCooltInTemp_C.value) = Rte_swc_VCIP_vcib_VCIP_vild_t_hvbCooltInTemp_C;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_t_hvbCooltOutTemp_C.value) = Rte_swc_VCIP_vcib_VCIP_vild_t_hvbCooltOutTemp_C;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_t_hvbMax_C.value) = Rte_swc_VCIP_vcib_VCIP_vild_t_hvbMax_C;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_t_hvbMin_C.value) = Rte_swc_VCIP_vcib_VCIP_vild_t_hvbMin_C;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_t_hvbOutCoolTemp_C.value) = Rte_swc_VCIP_vcib_VCIP_vild_t_hvbOutCoolTemp_C;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_t_hvbSetTgtTemp_C.value) = Rte_swc_VCIP_vcib_VCIP_vild_t_hvbSetTgtTemp_C;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_tm_hvbFnshChgTim_m.value) = Rte_swc_VCIP_vcib_VCIP_vild_tm_hvbFnshChgTim_m;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_BmsMaxCellVolt_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_BmsMaxCellVolt_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_BmsMinCellVolt_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_BmsMinCellVolt_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_Brk2_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_Brk2_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_Brk_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_Brk_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_TS5sensorFb_mV.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_TS5sensorFb_mV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_VacTkEnFb_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_VacTkEnFb_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_accPdlSens1InpVolt_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_accPdlSens1InpVolt_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_accPdlSens2InpVolt_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_accPdlSens2InpVolt_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_dcdcRelayVolt_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_dcdcRelayVolt_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_hvbCooltInSnsr_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_hvbCooltInSnsr_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_hvbCooltOutSnsr_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_hvbCooltOutSnsr_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_hvbPackVolt_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_hvbPackVolt_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_hvbVolt_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_hvbVolt_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_ipuHVBusVolt_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_ipuHVBusVolt_V;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vscd_a_vscLongitAcce_mps2.value) = Rte_swc_VCIP_vcib_VCIP_vscd_a_vscLongitAcce_mps2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vscd_b_ESPActv.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_ESPActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vscd_b_vehSpdVld.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSpdVld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vscd_b_vscBrkLghtActv.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_vscBrkLghtActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vscd_st_vscIsgActvDampModReq.value) = Rte_swc_VCIP_vcib_VCIP_vscd_st_vscIsgActvDampModReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vscd_v_vehSpdRaw_kph.value) = Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpdRaw_kph;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_ATAU_pmmd_b_ePTRelease_flg.value) = Rte_swc_ATAU_vcsb_ATAU_pmmd_b_ePTRelease_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_AUXC_brpd_b_VacPumpRlyEn.value) = Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpRlyEn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_AUXC_brpd_b_brkPmp1Rly.value) = Rte_swc_AUXC_vcsb_AUXC_brpd_b_brkPmp1Rly;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_AUXC_brpd_p_VacPumpPressure_kPa.value) = Rte_swc_AUXC_vcsb_AUXC_brpd_p_VacPumpPressure_kPa;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_AUXC_pscd_b_epsEna.value) = Rte_swc_AUXC_vcsb_AUXC_pscd_b_epsEna;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_AUXC_pscd_b_epsStopFlt.value) = Rte_swc_AUXC_vcsb_AUXC_pscd_b_epsStopFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_AUXC_pscd_frq_epsFrqTgt_Hz.value) = Rte_swc_AUXC_vcsb_AUXC_pscd_frq_epsFrqTgt_Hz;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_DIAG_brpd_b_brkSwtMismatch.value) = Rte_swc_DIAG_vcsb_DIAG_brpd_b_brkSwtMismatch;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_DIAG_digd_st_edcpFlt.value) = Rte_swc_DIAG_vcsb_DIAG_digd_st_edcpFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_DIAG_digd_st_hbcpFlt.value) = Rte_swc_DIAG_vcsb_DIAG_digd_st_hbcpFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_DIAG_digd_st_vehSysErrLevel.value) = Rte_swc_DIAG_vcsb_DIAG_digd_st_vehSysErrLevel;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_EGYM_accd_pwr_hvAttpwr_kW.value) = Rte_swc_EGYM_vcsb_EGYM_accd_pwr_hvAttpwr_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_EGYM_egmd_b_zeroPwrFb.value) = Rte_swc_EGYM_vcsb_EGYM_egmd_b_zeroPwrFb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_EGYM_egmd_i_bmshAlwChgCurrMax.value) = Rte_swc_EGYM_vcsb_EGYM_egmd_i_bmshAlwChgCurrMax;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_EGYM_egmd_pct_vcuChgDepReq.value) = Rte_swc_EGYM_vcsb_EGYM_egmd_pct_vcuChgDepReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_EGYM_egmd_pwr_accmHvClPwrAllwd_kW.value) = Rte_swc_EGYM_vcsb_EGYM_egmd_pwr_accmHvClPwrAllwd_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_EGYM_egmd_pwr_acwpHeatPwrCnsAllwd.value) = Rte_swc_EGYM_vcsb_EGYM_egmd_pwr_acwpHeatPwrCnsAllwd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_EGYM_egmd_pwr_ptcHvHtPwrAllwd_kW.value) = Rte_swc_EGYM_vcsb_EGYM_egmd_pwr_ptcHvHtPwrAllwd_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_EGYM_egmd_st_vcuChgLimResp.value) = Rte_swc_EGYM_vcsb_EGYM_egmd_st_vcuChgLimResp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_V_engFuelConsAvg_lp100km.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_V_engFuelConsAvg_lp100km;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_b_CruisingDstSwtFb.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_b_CruisingDstSwtFb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_b_HazardReqLmpOn.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_b_HazardReqLmpOn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_b_brkSysFlt.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_b_brkSysFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_b_ePTFault.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_b_ePTFault;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_b_odoBckpEn.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_b_odoBckpEn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_b_turtleLmpOn.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_b_turtleLmpOn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_d_odoTotal_km.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_d_odoTotal_km;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_d_pmsOdoBckUpMilg_km.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_d_pmsOdoBckUpMilg_km;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_d_vehCrsDst_km.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehCrsDst_km;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_d_vehDrvRngEVMod_km.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehDrvRngEVMod_km;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_d_vehDrvRngStandard_km.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehDrvRngStandard_km;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_num_AecEV_kWhp100km.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_num_AecEV_kWhp100km;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_num_errorCode.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_num_errorCode;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_pwr_hvPwrRemain_kW.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_pwr_hvPwrRemain_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_q_hvbSOC_pct.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_q_hvbSOC_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_st_drvModInd.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_st_drvModInd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_st_drvPfmncRedn.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_st_drvPfmncRedn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_st_drvrOptRmdr.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_st_drvrOptRmdr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_st_vehDrvMode.value) = Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehDrvMode;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_bmsd_e_modeTgt.value) = Rte_swc_HVSM_vcsb_HVSM_bmsd_e_modeTgt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_dccd_e_modeTgt.value) = Rte_swc_HVSM_vcsb_HVSM_dccd_e_modeTgt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_dccd_pct_DCDCPwrLmt.value) = Rte_swc_HVSM_vcsb_HVSM_dccd_pct_DCDCPwrLmt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_eadd_e_inv2ModeTgt.value) = Rte_swc_HVSM_vcsb_HVSM_eadd_e_inv2ModeTgt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_CampModeFb.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_CampModeFb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_TakeEleSwtIndReq.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_TakeEleSwtIndReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_accyHvOnCmd.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyHvOnCmd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_accyPreRlyCmd.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyPreRlyCmd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_accyWrkEnCmd.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyWrkEnCmd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_allowChg.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_allowChg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_dchaOn.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_dchaOn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_hvbIntelChgExitReq.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_hvbIntelChgExitReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_lvCutOffReq.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_lvCutOffReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_tmOutFlgCfm.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_tmOutFlgCfm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_vcuWkUpCmd.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_vcuWkUpCmd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_e_PmmStatus.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_CampModeFbFailrReason.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_CampModeFbFailrReason;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_RmChgCmdFailPmt.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_RmChgCmdFailPmt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_accyPreRlyFlt.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyPreRlyFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_accyPreRlySts.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyPreRlySts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_accyRlyFlt.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyRlyFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_accyRlySts.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyRlySts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_accyRlyVoltSamSw.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyRlyVoltSamSw;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_accyTakeSts.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyTakeSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_bbmWrkEnCmd.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_bbmWrkEnCmd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_hcmMaiRlyNegClsReq.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hcmMaiRlyNegClsReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_hvbAssiRlyPosClsReq.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hvbAssiRlyPosClsReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_hvbMaiRlyNegClsReq.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hvbMaiRlyNegClsReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_hvbMaiRlyPosClsReq.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hvbMaiRlyPosClsReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_otaHvOnOFFReqSts.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_otaHvOnOFFReqSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_otaHvOnOffFailInfo.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_otaHvOnOffFailInfo;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_ptRdyInd.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_ptRdyInd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_tboxChgSftSwCtlStEV.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_tboxChgSftSwCtlStEV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_obcd_b_chargerPlugged.value) = Rte_swc_HVSM_vcsb_HVSM_obcd_b_chargerPlugged;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_MEST_masd_m_vehWeight_kg.value) = Rte_swc_MEST_vcsb_MEST_masd_m_vehWeight_kg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_invSpdLmtRxSts.value) = Rte_swc_OGVL_vcsb_OGVL_dtld_st_invSpdLmtRxSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_inventorySpdLmtReq.value) = Rte_swc_OGVL_vcsb_OGVL_dtld_st_inventorySpdLmtReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_lifeCnt.value) = Rte_swc_OGVL_vcsb_OGVL_dtld_st_lifeCnt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_lockVehPer.value) = Rte_swc_OGVL_vcsb_OGVL_dtld_st_lockVehPer;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_lockVehPerRxSts.value) = Rte_swc_OGVL_vcsb_OGVL_dtld_st_lockVehPerRxSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_pwrOffCmd.value) = Rte_swc_OGVL_vcsb_OGVL_dtld_st_pwrOffCmd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_pwrOffCmdRxSts.value) = Rte_swc_OGVL_vcsb_OGVL_dtld_st_pwrOffCmdRxSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_spdLmtLevelReq.value) = Rte_swc_OGVL_vcsb_OGVL_dtld_st_spdLmtLevelReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_spdLmtLvRxSts.value) = Rte_swc_OGVL_vcsb_OGVL_dtld_st_spdLmtLvRxSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_tboxLifeSts.value) = Rte_swc_OGVL_vcsb_OGVL_dtld_st_tboxLifeSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_verCvsRxSts.value) = Rte_swc_OGVL_vcsb_OGVL_dtld_st_verCvsRxSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_versionConversion.value) = Rte_swc_OGVL_vcsb_OGVL_dtld_st_versionConversion;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_RMLK_rlcd_b_LockVehSts.value) = Rte_swc_RMLK_vcsb_RMLK_rlcd_b_LockVehSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_RMLK_rlcd_num_FunAnti_DismantleActive.value) = Rte_swc_RMLK_vcsb_RMLK_rlcd_num_FunAnti_DismantleActive;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_RMLK_rlcd_num_FunLockVehActive.value) = Rte_swc_RMLK_vcsb_RMLK_rlcd_num_FunLockVehActive;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_RMLK_rlcd_num_LockLimResult.value) = Rte_swc_RMLK_vcsb_RMLK_rlcd_num_LockLimResult;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_RMLK_rlcd_num_LockVehType.value) = Rte_swc_RMLK_vcsb_RMLK_rlcd_num_LockVehType;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_RMLK_rlcd_st_LockVehExecutedSts.value) = Rte_swc_RMLK_vcsb_RMLK_rlcd_st_LockVehExecutedSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW.value) = Rte_swc_SCAP_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCAP_tqld_tq_whlMax_Nm.value) = Rte_swc_SCAP_vcsb_SCAP_tqld_tq_whlMax_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCAP_tqld_tq_whlMin_Nm.value) = Rte_swc_SCAP_vcsb_SCAP_tqld_tq_whlMin_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_acc_intAccTgt_mps2.value) = Rte_swc_SCOO_vcsb_SCOO_ccdd_acc_intAccTgt_mps2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_acc_vehAccTgt_mps2.value) = Rte_swc_SCOO_vcsb_SCOO_ccdd_acc_vehAccTgt_mps2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_b_accCtrlActv.value) = Rte_swc_SCOO_vcsb_SCOO_ccdd_b_accCtrlActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_e_crsBtnErrSts.value) = Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsBtnErrSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_e_crsBtnSts.value) = Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsBtnSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_e_crsCtrlSpdMode.value) = Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsCtrlSpdMode;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_e_crsCtrlSts.value) = Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsCtrlSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_tq_whlDem_Nm.value) = Rte_swc_SCOO_vcsb_SCOO_ccdd_tq_whlDem_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_v_crsCtrlTgtSpd_kph.value) = Rte_swc_SCOO_vcsb_SCOO_ccdd_v_crsCtrlTgtSpd_kph;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_v_crsTgtSpdQuit_kph.value) = Rte_swc_SCOO_vcsb_SCOO_ccdd_v_crsTgtSpdQuit_kph;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_vsld_v_vehMaxSpd_kph.value) = Rte_swc_SCOO_vcsb_SCOO_vsld_v_vehMaxSpd_kph;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_dtdd_st_RegenLvlDisp.value) = Rte_swc_TCOO_vcsb_TCOO_dtdd_st_RegenLvlDisp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_dtdd_tq_whlCoastDrgDem_Nm.value) = Rte_swc_TCOO_vcsb_TCOO_dtdd_tq_whlCoastDrgDem_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm.value) = Rte_swc_TCOO_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_tdad_tq_whlDemUnlim_Nm.value) = Rte_swc_TCOO_vcsb_TCOO_tdad_tq_whlDemUnlim_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_tdad_tq_whlDem_Nm.value) = Rte_swc_TCOO_vcsb_TCOO_tdad_tq_whlDem_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_tqdd_b_accPedlPosVirtVld.value) = Rte_swc_TCOO_vcsb_TCOO_tqdd_b_accPedlPosVirtVld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_tqdd_b_gpOvrd.value) = Rte_swc_TCOO_vcsb_TCOO_tqdd_b_gpOvrd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_tqdd_st_ehbOvrdActv.value) = Rte_swc_TCOO_vcsb_TCOO_tqdd_st_ehbOvrdActv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_tqdd_st_ehbOvrdTyp.value) = Rte_swc_TCOO_vcsb_TCOO_tqdd_st_ehbOvrdTyp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_tqdd_st_whlAcceSupprsn.value) = Rte_swc_TCOO_vcsb_TCOO_tqdd_st_whlAcceSupprsn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_tqdd_x_accPedlPosVirt_pct.value) = Rte_swc_TCOO_vcsb_TCOO_tqdd_x_accPedlPosVirt_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_tvrd_tq_mot2TgtTqReq_Nm.value) = Rte_swc_TCOO_vcsb_TCOO_tvrd_tq_mot2TgtTqReq_Nm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_ActiveCool_flg.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_ActiveCool_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_BalanceHeat_flg.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_BalanceHeat_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_PassCool_flg.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_PassCool_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_PassHeat_flg.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_PassHeat_flg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_accmEnb.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_accmEnb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_fanRly1Req.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_fanRly1Req;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_fanRly2Req.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_fanRly2Req;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_heaterEna.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_heaterEna2.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_heaterEna3.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna3;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_heaterEna3HW.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna3HW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_heaterEnaHW.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEnaHW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_hvbDeft.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_hvbDeft;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_iptcHtIpuCl.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_iptcHtIpuCl;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_iptcHtIpuResvHt.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_iptcHtIpuResvHt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_ipuHeatEnableFlg.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_ipuHeatEnableFlg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_ipuResvHt.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_ipuResvHt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_ipuSupHtIptcHt.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_ipuSupHtIptcHt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_tv1V3.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_tv1V3;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_tv2V2.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_tv2V2;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_wtrPmp1CtrlEnabled.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmp1CtrlEnabled;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_wtrPmp2CtrlEnabled.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmp2CtrlEnabled;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_n_FWFVTgt_pct.value) = Rte_swc_THSM_vcsb_THSM_thmd_n_FWFVTgt_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_n_MHGVTgt_pct.value) = Rte_swc_THSM_vcsb_THSM_thmd_n_MHGVTgt_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_n_fan1TgtSpd_pct.value) = Rte_swc_THSM_vcsb_THSM_thmd_n_fan1TgtSpd_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_n_fan2TgtSpd_pct.value) = Rte_swc_THSM_vcsb_THSM_thmd_n_fan2TgtSpd_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_n_pmp1TgtSpd_pct.value) = Rte_swc_THSM_vcsb_THSM_thmd_n_pmp1TgtSpd_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_n_pmp2TgtSpd_pct.value) = Rte_swc_THSM_vcsb_THSM_thmd_n_pmp2TgtSpd_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_pwr_ipuHeatPwrAllwd_kW.value) = Rte_swc_THSM_vcsb_THSM_thmd_pwr_ipuHeatPwrAllwd_kW;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_q_pmp2FlowFeedback.value) = Rte_swc_THSM_vcsb_THSM_thmd_q_pmp2FlowFeedback;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_st_acceRlyVoltSamSwitch.value) = Rte_swc_THSM_vcsb_THSM_thmd_st_acceRlyVoltSamSwitch;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_st_acwpHeat.value) = Rte_swc_THSM_vcsb_THSM_thmd_st_acwpHeat;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_st_acwpSpdReq.value) = Rte_swc_THSM_vcsb_THSM_thmd_st_acwpSpdReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_st_ptc3ConnStsFb.value) = Rte_swc_THSM_vcsb_THSM_thmd_st_ptc3ConnStsFb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_st_ptc3RlyFlt.value) = Rte_swc_THSM_vcsb_THSM_thmd_st_ptc3RlyFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_st_ptcConnStsFb.value) = Rte_swc_THSM_vcsb_THSM_thmd_st_ptcConnStsFb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_st_ptcRlyFlt.value) = Rte_swc_THSM_vcsb_THSM_thmd_st_ptcRlyFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_st_ptcRlyVoltSamSwitch.value) = Rte_swc_THSM_vcsb_THSM_thmd_st_ptcRlyVoltSamSwitch;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_t_acwpTemp_C.value) = Rte_swc_THSM_vcsb_THSM_thmd_t_acwpTemp_C;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_drid_b_epbClsdReq.value) = Rte_swc_VOMM_vcsb_VOMM_drid_b_epbClsdReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_drid_b_gearPosVld.value) = Rte_swc_VOMM_vcsb_VOMM_drid_b_gearPosVld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_drid_e_driveDirSel.value) = Rte_swc_VOMM_vcsb_VOMM_drid_e_driveDirSel;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_drid_e_gearLvrPos.value) = Rte_swc_VOMM_vcsb_VOMM_drid_e_gearLvrPos;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_drid_st_gearLvrLckInd.value) = Rte_swc_VOMM_vcsb_VOMM_drid_st_gearLvrLckInd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_essd_b_engStopReq.value) = Rte_swc_VOMM_vcsb_VOMM_essd_b_engStopReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_b_hsdFltClear.value) = Rte_swc_VOMM_vcsb_VOMM_pmmd_b_hsdFltClear;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_b_nmSts.value) = Rte_swc_VOMM_vcsb_VOMM_pmmd_b_nmSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_b_pwrHoldReq.value) = Rte_swc_VOMM_vcsb_VOMM_pmmd_b_pwrHoldReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_b_vcuAwb.value) = Rte_swc_VOMM_vcsb_VOMM_pmmd_b_vcuAwb;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_b_vcuRmr.value) = Rte_swc_VOMM_vcsb_VOMM_pmmd_b_vcuRmr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_num_vcuAddr.value) = Rte_swc_VOMM_vcsb_VOMM_pmmd_num_vcuAddr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_st_bdCanModeReq.value) = Rte_swc_VOMM_vcsb_VOMM_pmmd_st_bdCanModeReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_st_ptCanModeReq.value) = Rte_swc_VOMM_vcsb_VOMM_pmmd_st_ptCanModeReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_st_stayAwkReason.value) = Rte_swc_VOMM_vcsb_VOMM_pmmd_st_stayAwkReason;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_st_vcuWkUpReason.value) = Rte_swc_VOMM_vcsb_VOMM_pmmd_st_vcuWkUpReason;
    swc_VCOP_Step();
    Rte_swc_VCOP_AC_EWP_Heat_LIN_AC_EWP_Heat_LIN = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_Heat_LIN_AC_EWP_Heat_LIN.value);
    Rte_swc_VCOP_AC_EWP_HeatrPwrCnsAllwd_LIN_AC_EWP_HeatrPwrCnsAllwd_LIN = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_HeatrPwrCnsAllwd_LIN_AC_EWP_HeatrPwrCnsAllwd_LIN.value);
    Rte_swc_VCOP_AC_EWP_Run_LIN_AC_EWP_Run_LIN = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_Run_LIN_AC_EWP_Run_LIN.value);
    Rte_swc_VCOP_AC_EWP_SpeedReq_LIN_AC_EWP_SpeedReq_LIN = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_SpeedReq_LIN_AC_EWP_SpeedReq_LIN.value);
    Rte_swc_VCOP_AC_EWP_Temp_LIN_AC_EWP_Temp_LIN = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_Temp_LIN_AC_EWP_Temp_LIN.value);
    Rte_swc_VCOP_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter.value);
    Rte_swc_VCOP_BMSH_Battery_Performance_Checksum_BMSH_Battery_Performance_Checksum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Battery_Performance_Checksum_BMSH_Battery_Performance_Checksum.value);
    Rte_swc_VCOP_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter.value);
    Rte_swc_VCOP_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03.value);
    Rte_swc_VCOP_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05.value);
    Rte_swc_VCOP_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11.value);
    Rte_swc_VCOP_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6.value);
    Rte_swc_VCOP_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8.value);
    Rte_swc_VCOP_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9.value);
    Rte_swc_VCOP_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10.value);
    Rte_swc_VCOP_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12.value);
    Rte_swc_VCOP_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5.value);
    Rte_swc_VCOP_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7.value);
    Rte_swc_VCOP_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9.value);
    Rte_swc_VCOP_EXT_PO_HVIL_1_DutyCycle_EXT_PO_HVIL_1_DutyCycle = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_HVIL_1_DutyCycle_EXT_PO_HVIL_1_DutyCycle.value);
    Rte_swc_VCOP_EXT_PO_HVIL_1_Period_EXT_PO_HVIL_1_Period = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_HVIL_1_Period_EXT_PO_HVIL_1_Period.value);
    Rte_swc_VCOP_EXT_PO_HVIL_2_DutyCycle_EXT_PO_HVIL_2_DutyCycle = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_HVIL_2_DutyCycle_EXT_PO_HVIL_2_DutyCycle.value);
    Rte_swc_VCOP_EXT_PO_HVIL_2_Period_EXT_PO_HVIL_2_Period = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_HVIL_2_Period_EXT_PO_HVIL_2_Period.value);
    Rte_swc_VCOP_EXT_PO_PWM_1_DutyCycle_EXT_PO_PWM_1_DutyCycle = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_PWM_1_DutyCycle_EXT_PO_PWM_1_DutyCycle.value);
    Rte_swc_VCOP_EXT_PO_PWM_1_Period_EXT_PO_PWM_1_Period = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_PWM_1_Period_EXT_PO_PWM_1_Period.value);
    Rte_swc_VCOP_EXT_PO_PWM_2_DutyCycle_EXT_PO_PWM_2_DutyCycle = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_PWM_2_DutyCycle_EXT_PO_PWM_2_DutyCycle.value);
    Rte_swc_VCOP_EXT_PO_PWM_2_Period_EXT_PO_PWM_2_Period = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_PWM_2_Period_EXT_PO_PWM_2_Period.value);
    Rte_swc_VCOP_EXT_PO_PWM_4_DutyCycle_EXT_PO_PWM_4_DutyCycle = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_PWM_4_DutyCycle_EXT_PO_PWM_4_DutyCycle.value);
    Rte_swc_VCOP_EXT_PO_PWM_4_Period_EXT_PO_PWM_4_Period = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_PWM_4_Period_EXT_PO_PWM_4_Period.value);
    Rte_swc_VCOP_FWFV_CCWFlg_PMS_FWFV_CCWFlg_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_CCWFlg_PMS_FWFV_CCWFlg_PMS.value);
    Rte_swc_VCOP_FWFV_CurrentPos_PMS_FWFV_CurrentPos_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_CurrentPos_PMS_FWFV_CurrentPos_PMS.value);
    Rte_swc_VCOP_FWFV_InitState_PMS_FWFV_InitState_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_InitState_PMS_FWFV_InitState_PMS.value);
    Rte_swc_VCOP_FWFV_MotorState_PMS_FWFV_MotorState_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_MotorState_PMS_FWFV_MotorState_PMS.value);
    Rte_swc_VCOP_FWFV_OverCurrentFlt_PMS_FWFV_OverCurrentFlt_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_OverCurrentFlt_PMS_FWFV_OverCurrentFlt_PMS.value);
    Rte_swc_VCOP_FWFV_OverTempFlt_PMS_FWFV_OverTempFlt_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_OverTempFlt_PMS_FWFV_OverTempFlt_PMS.value);
    Rte_swc_VCOP_FWFV_OverVoltageFlt_PMS_FWFV_OverVoltageFlt_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_OverVoltageFlt_PMS_FWFV_OverVoltageFlt_PMS.value);
    Rte_swc_VCOP_FWFV_RESP_ERROR_PMS_FWFV_RESP_ERROR_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_RESP_ERROR_PMS_FWFV_RESP_ERROR_PMS.value);
    Rte_swc_VCOP_FWFV_UnderVoltageFlt_PMS_FWFV_UnderVoltageFlt_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_UnderVoltageFlt_PMS_FWFV_UnderVoltageFlt_PMS.value);
    Rte_swc_VCOP_O_S_PIN110_O_S_PIN110 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_S_PIN110_O_S_PIN110.value);
    Rte_swc_VCOP_O_S_PIN123_O_S_PIN123 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_S_PIN123_O_S_PIN123.value);
    Rte_swc_VCOP_O_S_PIN83_O_S_PIN83 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_S_PIN83_O_S_PIN83.value);
    Rte_swc_VCOP_O_S_PIN88_O_S_PIN88 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_S_PIN88_O_S_PIN88.value);
    Rte_swc_VCOP_O_S_PIN89_O_S_PIN89 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_S_PIN89_O_S_PIN89.value);
    Rte_swc_VCOP_O_S_PIN98_O_S_PIN98 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_S_PIN98_O_S_PIN98.value);
    Rte_swc_VCOP_O_T_PIN104_Duty_O_T_PIN104_Duty = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN104_Duty_O_T_PIN104_Duty.value);
    Rte_swc_VCOP_O_T_PIN104_Period_O_T_PIN104_Period = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN104_Period_O_T_PIN104_Period.value);
    Rte_swc_VCOP_O_T_PIN118_Duty_O_T_PIN118_Duty = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN118_Duty_O_T_PIN118_Duty.value);
    Rte_swc_VCOP_O_T_PIN118_Period_O_T_PIN118_Period = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN118_Period_O_T_PIN118_Period.value);
    Rte_swc_VCOP_O_T_PIN14_Duty_O_T_PIN14_Duty = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN14_Duty_O_T_PIN14_Duty.value);
    Rte_swc_VCOP_O_T_PIN14_Period_O_T_PIN14_Period = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN14_Period_O_T_PIN14_Period.value);
    Rte_swc_VCOP_O_T_PIN28_Duty_O_T_PIN28_Duty = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN28_Duty_O_T_PIN28_Duty.value);
    Rte_swc_VCOP_O_T_PIN28_Period_O_T_PIN28_Period = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN28_Period_O_T_PIN28_Period.value);
    Rte_swc_VCOP_O_T_PIN77_Duty_O_T_PIN77_Duty = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN77_Duty_O_T_PIN77_Duty.value);
    Rte_swc_VCOP_O_T_PIN77_Period_O_T_PIN77_Period = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN77_Period_O_T_PIN77_Period.value);
    Rte_swc_VCOP_O_T_PIN82_Duty_O_T_PIN82_Duty = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN82_Duty_O_T_PIN82_Duty.value);
    Rte_swc_VCOP_O_T_PIN82_Period_O_T_PIN82_Period = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN82_Period_O_T_PIN82_Period.value);
    Rte_swc_VCOP_PMS_ADCCtrlSts_PMS_ADCCtrlSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ADCCtrlSts_PMS_ADCCtrlSts.value);
    Rte_swc_VCOP_PMS_APA_BeControlled_Status_PMS_APA_BeControlled_Status = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_APA_BeControlled_Status_PMS_APA_BeControlled_Status.value);
    Rte_swc_VCOP_PMS_AppSts_EV_PMS_AppSts_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AppSts_EV_PMS_AppSts_EV.value);
    Rte_swc_VCOP_PMS_Brake1Switch_PMS_Brake1Switch = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Brake1Switch_PMS_Brake1Switch.value);
    Rte_swc_VCOP_PMS_Brake2Switch_PMS_Brake2Switch = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Brake2Switch_PMS_Brake2Switch.value);
    Rte_swc_VCOP_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter.value);
    Rte_swc_VCOP_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter.value);
    Rte_swc_VCOP_PMS_Command_AliveCounter_PMS_Command_AliveCounter = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Command_AliveCounter_PMS_Command_AliveCounter.value);
    Rte_swc_VCOP_PMS_Command_AliveCounter_EV_PMS_Command_AliveCounter_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Command_AliveCounter_EV_PMS_Command_AliveCounter_EV.value);
    Rte_swc_VCOP_PMS_Command_Checksum_EV_PMS_Command_Checksum_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Command_Checksum_EV_PMS_Command_Checksum_EV.value);
    Rte_swc_VCOP_PMS_ControlSetSpeed_PMS_ControlSetSpeed = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ControlSetSpeed_PMS_ControlSetSpeed.value);
    Rte_swc_VCOP_PMS_CruiseControlSts_PMS_CruiseControlSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CruiseControlSts_PMS_CruiseControlSts.value);
    Rte_swc_VCOP_PMS_CruiseSwitchSts_PMS_CruiseSwitchSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CruiseSwitchSts_PMS_CruiseSwitchSts.value);
    Rte_swc_VCOP_PMS_CruisingDstSwtFb_PMS_CruisingDstSwtFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CruisingDstSwtFb_PMS_CruisingDstSwtFb.value);
    Rte_swc_VCOP_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter.value);
    Rte_swc_VCOP_PMS_CurrentGearPosition_EV_PMS_CurrentGearPosition_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CurrentGearPosition_EV_PMS_CurrentGearPosition_EV.value);
    Rte_swc_VCOP_PMS_CurrentGearPosition_Valid_EV_PMS_CurrentGearPosition_Valid_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CurrentGearPosition_Valid_EV_PMS_CurrentGearPosition_Valid_EV.value);
    Rte_swc_VCOP_PMS_DCDC_Ctrl_AliveCounter_PMS_DCDC_Ctrl_AliveCounter = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DCDC_Ctrl_AliveCounter_PMS_DCDC_Ctrl_AliveCounter.value);
    Rte_swc_VCOP_PMS_DCDC_Ctrl_Checksum_PMS_DCDC_Ctrl_Checksum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DCDC_Ctrl_Checksum_PMS_DCDC_Ctrl_Checksum.value);
    Rte_swc_VCOP_PMS_DM_FailureReasonAndSysFaultFBK_PMS_DM_FailureReasonAndSysFaultFBK = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DM_FailureReasonAndSysFaultFBK_PMS_DM_FailureReasonAndSysFaultFBK.value);
    Rte_swc_VCOP_PMS_DcDc1ActvdReq_EV_PMS_DcDc1ActvdReq_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DcDc1ActvdReq_EV_PMS_DcDc1ActvdReq_EV.value);
    Rte_swc_VCOP_PMS_DriveCircuitTemp_EV_PMS_DriveCircuitTemp_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriveCircuitTemp_EV_PMS_DriveCircuitTemp_EV.value);
    Rte_swc_VCOP_PMS_DriverRemind_PMS_DriverRemind = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriverRemind_PMS_DriverRemind.value);
    Rte_swc_VCOP_PMS_EDCPEnable_EV_PMS_EDCPEnable_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EDCPEnable_EV_PMS_EDCPEnable_EV.value);
    Rte_swc_VCOP_PMS_EDCPPWMCtrl_EV_PMS_EDCPPWMCtrl_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EDCPPWMCtrl_EV_PMS_EDCPPWMCtrl_EV.value);
    Rte_swc_VCOP_PMS_EPBClosedReq_PMS_EPBClosedReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EPBClosedReq_PMS_EPBClosedReq.value);
    Rte_swc_VCOP_PMS_EPS_SteeringAngleValueInvalid_PMS_EPS_SteeringAngleValueInvalid = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EPS_SteeringAngleValueInvalid_PMS_EPS_SteeringAngleValueInvalid.value);
    Rte_swc_VCOP_PMS_EPedlDrvrIndcnMsg_PMS_EPedlDrvrIndcnMsg = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EPedlDrvrIndcnMsg_PMS_EPedlDrvrIndcnMsg.value);
    Rte_swc_VCOP_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter.value);
    Rte_swc_VCOP_PMS_EpedalActive_PMS_EpedalActive = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EpedalActive_PMS_EpedalActive.value);
    Rte_swc_VCOP_PMS_ExecuteLockVehResults_PMS_ExecuteLockVehResults = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ExecuteLockVehResults_PMS_ExecuteLockVehResults.value);
    Rte_swc_VCOP_PMS_FWFV_MoveEnable_PMS_FWFV_MoveEnable = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FWFV_MoveEnable_PMS_FWFV_MoveEnable.value);
    Rte_swc_VCOP_PMS_FWFV_MoveEnable_LIN_PMS_FWFV_MoveEnable_LIN = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FWFV_MoveEnable_LIN_PMS_FWFV_MoveEnable_LIN.value);
    Rte_swc_VCOP_PMS_FWFV_ReqMovePos_PMS_FWFV_ReqMovePos = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FWFV_ReqMovePos_PMS_FWFV_ReqMovePos.value);
    Rte_swc_VCOP_PMS_FWFV_ReqMovePos_LIN_PMS_FWFV_ReqMovePos_LIN = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FWFV_ReqMovePos_LIN_PMS_FWFV_ReqMovePos_LIN.value);
    Rte_swc_VCOP_PMS_HvBattCooltLvl_PMS_HvBattCooltLvl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HvBattCooltLvl_PMS_HvBattCooltLvl.value);
    Rte_swc_VCOP_PMS_MCUActvdReq_PMS_MCUActvdReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MCUActvdReq_PMS_MCUActvdReq.value);
    Rte_swc_VCOP_PMS_MCUTemp_EV_PMS_MCUTemp_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MCUTemp_EV_PMS_MCUTemp_EV.value);
    Rte_swc_VCOP_PMS_MHGV_EnableReq_LIN_PMS_MHGV_EnableReq_LIN = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_EnableReq_LIN_PMS_MHGV_EnableReq_LIN.value);
    Rte_swc_VCOP_PMS_MHGV_PosSet_LIN_PMS_MHGV_PosSet_LIN = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_PosSet_LIN_PMS_MHGV_PosSet_LIN.value);
    Rte_swc_VCOP_PMS_MHGV_ReqMotorEmgyStop_LIN_PMS_MHGV_ReqMotorEmgyStop_LIN = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_ReqMotorEmgyStop_LIN_PMS_MHGV_ReqMotorEmgyStop_LIN.value);
    Rte_swc_VCOP_PMS_MHGV_ReqMotorOptRecovery_LIN_PMS_MHGV_ReqMotorOptRecovery_LIN = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_ReqMotorOptRecovery_LIN_PMS_MHGV_ReqMotorOptRecovery_LIN.value);
    Rte_swc_VCOP_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter.value);
    Rte_swc_VCOP_PMS_NMSts_PMS_NMSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_NMSts_PMS_NMSts.value);
    Rte_swc_VCOP_PMS_Odometerbackup_PMS_Odometerbackup = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Odometerbackup_PMS_Odometerbackup.value);
    Rte_swc_VCOP_PMS_SlidingmomentrSetReq_PMS_SlidingmomentrSetReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SlidingmomentrSetReq_PMS_SlidingmomentrSetReq.value);
    Rte_swc_VCOP_PMS_Stayawake_reasons_PMS_Stayawake_reasons = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Stayawake_reasons_PMS_Stayawake_reasons.value);
    Rte_swc_VCOP_PMS_StsBrkSwitch1_PMS_StsBrkSwitch1 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_StsBrkSwitch1_PMS_StsBrkSwitch1.value);
    Rte_swc_VCOP_PMS_StsBrkSwitch1Invalid_PMS_StsBrkSwitch1Invalid = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_StsBrkSwitch1Invalid_PMS_StsBrkSwitch1Invalid.value);
    Rte_swc_VCOP_PMS_TBOX_HVILState_PMS_TBOX_HVILState = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_HVILState_PMS_TBOX_HVILState.value);
    Rte_swc_VCOP_PMS_TBOX_HVILState_3A1_PMS_TBOX_HVILState_3A1 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_HVILState_3A1_PMS_TBOX_HVILState_3A1.value);
    Rte_swc_VCOP_PMS_ThermalReq_PMS_ThermalReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ThermalReq_PMS_ThermalReq.value);
    Rte_swc_VCOP_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV.value);
    Rte_swc_VCOP_PMS_Wakeup_reasons_PMS_Wakeup_reasons = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Wakeup_reasons_PMS_Wakeup_reasons.value);
    Rte_swc_VCOP_PMS_ePTReady_EV_PMS_ePTReady_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTReady_EV_PMS_ePTReady_EV.value);
    Rte_swc_VCOP_PMS_ePTRegencyLevInd_PMS_ePTRegencyLevInd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTRegencyLevInd_PMS_ePTRegencyLevInd.value);
    Rte_swc_VCOP_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter.value);
    Rte_swc_VCOP_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter.value);
    Rte_swc_VCOP_st_ShtDown_st_ShtDown = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_st_ShtDown_st_ShtDown.value);
    Rte_swc_VCOP_vcob_VCOP_BMSH_ChargeLEDCtrl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcob_VCOP_BMSH_ChargeLEDCtrl.value);


    Rte_swc_VCOP_AC_EWP_Heat_AC_EWP_Heat = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_Heat_AC_EWP_Heat.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_AC_EWP_Heat_AC_EWP_Heat = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_AC_EWP_HeatrPwrCnsAllwd_AC_EWP_HeatrPwrCnsAllwd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_HeatrPwrCnsAllwd_AC_EWP_HeatrPwrCnsAllwd.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_AC_EWP_HeatrPwrCnsAllwd_AC_EWP_HeatrPwrCnsAllwd = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_AC_EWP_Run_AC_EWP_Run = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_Run_AC_EWP_Run.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_AC_EWP_Run_AC_EWP_Run = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_AC_EWP_SpeedReq_AC_EWP_SpeedReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_SpeedReq_AC_EWP_SpeedReq.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_AC_EWP_SpeedReq_AC_EWP_SpeedReq = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_AC_EWP_Temp_AC_EWP_Temp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_Temp_AC_EWP_Temp.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_AC_EWP_Temp_AC_EWP_Temp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_ACChgTimeRemain_BMSH_ACChgTimeRemain = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_ACChgTimeRemain_BMSH_ACChgTimeRemain.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_ACChgTimeRemain_BMSH_ACChgTimeRemain = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_BattCurr_BMSH_BattCurr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattCurr_BMSH_BattCurr.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattCurr_BMSH_BattCurr = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_BattFaultLampState_BMSH_BattFaultLampState = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattFaultLampState_BMSH_BattFaultLampState.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattFaultLampState_BMSH_BattFaultLampState = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_BATTPACKNUM_PMS_BMSH_BATTPACKNUM_PMS);
    Rte_swc_VCOP_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_BATTPACKNUM_PMS_BMSH_BATTPACKNUM_PMS);


    Rte_swc_VCOP_BMSH_BattRemainEnergy_BMSH_BattRemainEnergy = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattRemainEnergy_BMSH_BattRemainEnergy.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattRemainEnergy_BMSH_BattRemainEnergy = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_BattSOC_BMSH_BattSOC = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattSOC_BMSH_BattSOC.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattSOC_BMSH_BattSOC = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_BattSOH_BMSH_BattSOH = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattSOH_BMSH_BattSOH.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattSOH_BMSH_BattSOH = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_BATTSYSNUM_PMS_BMSH_BATTSYSNUM_PMS);
    Rte_swc_VCOP_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_BATTSYSNUM_PMS_BMSH_BATTSYSNUM_PMS);


    Rte_swc_VCOP_BMSH_BattTempAvg_PT_BMSH_BattTempAvg_PT = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattTempAvg_PT_BMSH_BattTempAvg_PT.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattTempAvg_PT_BMSH_BattTempAvg_PT = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_BattVolt_BMSH_BattVolt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattVolt_BMSH_BattVolt.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_BattVolt_BMSH_BattVolt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_CellTemp_Uniformity_BMSH_CellTemp_Uniformity = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_CellTemp_Uniformity_BMSH_CellTemp_Uniformity.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_CellTemp_Uniformity_BMSH_CellTemp_Uniformity = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_CellVolt_Uniformity_BMSH_CellVolt_Uniformity = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_CellVolt_Uniformity_BMSH_CellVolt_Uniformity.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_CellVolt_Uniformity_BMSH_CellVolt_Uniformity = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_Cell_OverVol_BMSH_Cell_OverVol = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Cell_OverVol_BMSH_Cell_OverVol.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Cell_OverVol_BMSH_Cell_OverVol = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_Cell_TotalNum_BMSH_Cell_TotalNum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Cell_TotalNum_BMSH_Cell_TotalNum.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Cell_TotalNum_BMSH_Cell_TotalNum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_Cell_UnderVol_BMSH_Cell_UnderVol = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Cell_UnderVol_BMSH_Cell_UnderVol.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Cell_UnderVol_BMSH_Cell_UnderVol = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_ChargeLEDCtrl_BMSH_ChargeLEDCtrl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_ChargeLEDCtrl_BMSH_ChargeLEDCtrl.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_ChargeLEDCtrl_BMSH_ChargeLEDCtrl = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_ChargeToBeFinished_BMSH_ChargeToBeFinished = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_ChargeToBeFinished_BMSH_ChargeToBeFinished.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_ChargeToBeFinished_BMSH_ChargeToBeFinished = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_Charge_Over_Current_BMSH_Charge_Over_Current = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Charge_Over_Current_BMSH_Charge_Over_Current.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Charge_Over_Current_BMSH_Charge_Over_Current = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_ChgTimeRemain_BMSH_ChgTimeRemain = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_ChgTimeRemain_BMSH_ChgTimeRemain.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_ChgTimeRemain_BMSH_ChgTimeRemain = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_DCChgminusSocketTempSensing_Failure_BMSH_DCChgminusSocketTempSensing_Failure = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_DCChgminusSocketTempSensing_Failure_BMSH_DCChgminusSocketTempSensing_Failure.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_DCChgminusSocketTempSensing_Failure_BMSH_DCChgminusSocketTempSensing_Failure = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_DCChgplusSocketTempSensing_Failure_BMSH_DCChgplusSocketTempSensing_Failure = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_DCChgplusSocketTempSensing_Failure_BMSH_DCChgplusSocketTempSensing_Failure.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_DCChgplusSocketTempSensing_Failure_BMSH_DCChgplusSocketTempSensing_Failure = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_FastChgCC2ConntState_BMSH_FastChgCC2ConntState = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_FastChgCC2ConntState_BMSH_FastChgCC2ConntState.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_FastChgCC2ConntState_BMSH_FastChgCC2ConntState = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_HVBusVolt_BMSH_HVBusVolt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_HVBusVolt_BMSH_HVBusVolt.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_HVBusVolt_BMSH_HVBusVolt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_HvBattCooltTReq_BMSH_HvBattCooltTReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_HvBattCooltTReq_BMSH_HvBattCooltTReq.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_HvBattCooltTReq_BMSH_HvBattCooltTReq = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_HvBattThermMod_BMSH_HvBattThermMod = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_HvBattThermMod_BMSH_HvBattThermMod.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_HvBattThermMod_BMSH_HvBattThermMod = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_HvShutdownReq_BMSH_HvShutdownReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_HvShutdownReq_BMSH_HvShutdownReq.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_HvShutdownReq_BMSH_HvShutdownReq = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_ICU_BatteryElectricDTE_BMSH_ICU_BatteryElectricDTE = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_ICU_BatteryElectricDTE_BMSH_ICU_BatteryElectricDTE.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_ICU_BatteryElectricDTE_BMSH_ICU_BatteryElectricDTE = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_Inlet_WaterTemp_BMSH_Inlet_WaterTemp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Inlet_WaterTemp_BMSH_Inlet_WaterTemp.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Inlet_WaterTemp_BMSH_Inlet_WaterTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_InsulationRes_BMSH_InsulationRes = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_InsulationRes_BMSH_InsulationRes.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_InsulationRes_BMSH_InsulationRes = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_InsulationRes_Fault_BMSH_InsulationRes_Fault = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_InsulationRes_Fault_BMSH_InsulationRes_Fault.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_InsulationRes_Fault_BMSH_InsulationRes_Fault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_Low_SOC_BMSH_Low_SOC = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Low_SOC_BMSH_Low_SOC.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Low_SOC_BMSH_Low_SOC = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_Outlet_WaterTemp_BMSH_Outlet_WaterTemp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Outlet_WaterTemp_BMSH_Outlet_WaterTemp.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Outlet_WaterTemp_BMSH_Outlet_WaterTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_Over_SOC_BMSH_Over_SOC = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Over_SOC_BMSH_Over_SOC.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Over_SOC_BMSH_Over_SOC = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_Over_Temperature_BMSH_Over_Temperature = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Over_Temperature_BMSH_Over_Temperature.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Over_Temperature_BMSH_Over_Temperature = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_Pack_OverVoltage_BMSH_Pack_OverVoltage = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Pack_OverVoltage_BMSH_Pack_OverVoltage.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Pack_OverVoltage_BMSH_Pack_OverVoltage = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_Pack_UnderVoltage_BMSH_Pack_UnderVoltage = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Pack_UnderVoltage_BMSH_Pack_UnderVoltage.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Pack_UnderVoltage_BMSH_Pack_UnderVoltage = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_SOC_Hop_BMSH_SOC_Hop = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_SOC_Hop_BMSH_SOC_Hop.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_SOC_Hop_BMSH_SOC_Hop = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_TBOX_BatIsoAlarm2_PT_BMSH_TBOX_BatIsoAlarm2_PT = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatIsoAlarm2_PT_BMSH_TBOX_BatIsoAlarm2_PT.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatIsoAlarm2_PT_BMSH_TBOX_BatIsoAlarm2_PT = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATISOALARM3_PMS_BMSH_TBOX_BATISOALARM3_PMS);
    Rte_swc_VCOP_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATISOALARM3_PMS_BMSH_TBOX_BATISOALARM3_PMS);


    Rte_swc_VCOP_BMSH_TBOX_BatLowSOC2_PT_BMSH_TBOX_BatLowSOC2_PT = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatLowSOC2_PT_BMSH_TBOX_BatLowSOC2_PT.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatLowSOC2_PT_BMSH_TBOX_BatLowSOC2_PT = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATLOWSOC3_PMS_BMSH_TBOX_BATLOWSOC3_PMS);
    Rte_swc_VCOP_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATLOWSOC3_PMS_BMSH_TBOX_BATLOWSOC3_PMS);


    Rte_swc_VCOP_BMSH_TBOX_BatOverCharge2_PT_BMSH_TBOX_BatOverCharge2_PT = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverCharge2_PT_BMSH_TBOX_BatOverCharge2_PT.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverCharge2_PT_BMSH_TBOX_BatOverCharge2_PT = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERCHARGE3_PMS_BMSH_TBOX_BATOVERCHARGE3_PMS);
    Rte_swc_VCOP_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERCHARGE3_PMS_BMSH_TBOX_BATOVERCHARGE3_PMS);


    Rte_swc_VCOP_BMSH_TBOX_BatOverSOC2_PT_BMSH_TBOX_BatOverSOC2_PT = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverSOC2_PT_BMSH_TBOX_BatOverSOC2_PT.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverSOC2_PT_BMSH_TBOX_BatOverSOC2_PT = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERSOC3_PMS_BMSH_TBOX_BATOVERSOC3_PMS);
    Rte_swc_VCOP_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERSOC3_PMS_BMSH_TBOX_BATOVERSOC3_PMS);


    Rte_swc_VCOP_BMSH_TBOX_BatOverTemp2_PT_BMSH_TBOX_BatOverTemp2_PT = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverTemp2_PT_BMSH_TBOX_BatOverTemp2_PT.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverTemp2_PT_BMSH_TBOX_BatOverTemp2_PT = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERTEMP3_PMS_BMSH_TBOX_BATOVERTEMP3_PMS);
    Rte_swc_VCOP_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERTEMP3_PMS_BMSH_TBOX_BATOVERTEMP3_PMS);


    Rte_swc_VCOP_BMSH_TBOX_BatOverVoltage2_PT_BMSH_TBOX_BatOverVoltage2_PT = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverVoltage2_PT_BMSH_TBOX_BatOverVoltage2_PT.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverVoltage2_PT_BMSH_TBOX_BatOverVoltage2_PT = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERVOLTAGE3_PMS_BMSH_TBOX_BATOVERVOLTAGE3_PMS);
    Rte_swc_VCOP_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERVOLTAGE3_PMS_BMSH_TBOX_BATOVERVOLTAGE3_PMS);


    Rte_swc_VCOP_BMSH_TBOX_BatTempUniformity2_PT_BMSH_TBOX_BatTempUniformity2_PT = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatTempUniformity2_PT_BMSH_TBOX_BatTempUniformity2_PT.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatTempUniformity2_PT_BMSH_TBOX_BatTempUniformity2_PT = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATTEMPUNIFORMITY3_PMS_BMSH_TBOX_BATTEMPUNIFORMITY3_PMS);
    Rte_swc_VCOP_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATTEMPUNIFORMITY3_PMS_BMSH_TBOX_BATTEMPUNIFORMITY3_PMS);


    Rte_swc_VCOP_BMSH_TBOX_BatUnderVoltage2_PT_BMSH_TBOX_BatUnderVoltage2_PT = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatUnderVoltage2_PT_BMSH_TBOX_BatUnderVoltage2_PT.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatUnderVoltage2_PT_BMSH_TBOX_BatUnderVoltage2_PT = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATUNDERVOLTAGE3_PMS_BMSH_TBOX_BATUNDERVOLTAGE3_PMS);
    Rte_swc_VCOP_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATUNDERVOLTAGE3_PMS_BMSH_TBOX_BATUNDERVOLTAGE3_PMS);


    Rte_swc_VCOP_BMSH_TBOX_BatUniformity2_PT_BMSH_TBOX_BatUniformity2_PT = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatUniformity2_PT_BMSH_TBOX_BatUniformity2_PT.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatUniformity2_PT_BMSH_TBOX_BatUniformity2_PT = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATUNIFORMITY3_PMS_BMSH_TBOX_BATUNIFORMITY3_PMS);
    Rte_swc_VCOP_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATUNIFORMITY3_PMS_BMSH_TBOX_BATUNIFORMITY3_PMS);


    Rte_swc_VCOP_BMSH_TBOX_CellOverVoltage2_PT_BMSH_TBOX_CellOverVoltage2_PT = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_CellOverVoltage2_PT_BMSH_TBOX_CellOverVoltage2_PT.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_CellOverVoltage2_PT_BMSH_TBOX_CellOverVoltage2_PT = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_CELLOVERVOLTAGE3_PMS_BMSH_TBOX_CELLOVERVOLTAGE3_PMS);
    Rte_swc_VCOP_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_CELLOVERVOLTAGE3_PMS_BMSH_TBOX_CELLOVERVOLTAGE3_PMS);


    Rte_swc_VCOP_BMSH_TBOX_CellUnderVoltage2_PT_BMSH_TBOX_CellUnderVoltage2_PT = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_CellUnderVoltage2_PT_BMSH_TBOX_CellUnderVoltage2_PT.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_CellUnderVoltage2_PT_BMSH_TBOX_CellUnderVoltage2_PT = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_CELLUNDERVOLTAGE3_PMS_BMSH_TBOX_CELLUNDERVOLTAGE3_PMS);
    Rte_swc_VCOP_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_CELLUNDERVOLTAGE3_PMS_BMSH_TBOX_CELLUNDERVOLTAGE3_PMS);


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_FIREALARM2_PMS_BMSH_TBOX_FIREALARM2_PMS);
    Rte_swc_VCOP_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_FIREALARM2_PMS_BMSH_TBOX_FIREALARM2_PMS);


    Rte_swc_VCOP_BMSH_TBOX_SOCHop2_PT_BMSH_TBOX_SOCHop2_PT = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_SOCHop2_PT_BMSH_TBOX_SOCHop2_PT.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_SOCHop2_PT_BMSH_TBOX_SOCHop2_PT = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_SOCHOP3_PMS_BMSH_TBOX_SOCHOP3_PMS);
    Rte_swc_VCOP_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_SOCHOP3_PMS_BMSH_TBOX_SOCHOP3_PMS);


    Rte_swc_VCOP_BMSH_TempSensor_MaxTemp_BMSH_TempSensor_MaxTemp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TempSensor_MaxTemp_BMSH_TempSensor_MaxTemp.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TempSensor_MaxTemp_BMSH_TempSensor_MaxTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_TempSensor_MinTemp_BMSH_TempSensor_MinTemp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TempSensor_MinTemp_BMSH_TempSensor_MinTemp.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TempSensor_MinTemp_BMSH_TempSensor_MinTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_TempSensor_TotalNum_BMSH_TempSensor_TotalNum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TempSensor_TotalNum_BMSH_TempSensor_TotalNum.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_TempSensor_TotalNum_BMSH_TempSensor_TotalNum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_ThermalOutofControl_BMSH_ThermalOutofControl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_ThermalOutofControl_BMSH_ThermalOutofControl.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_ThermalOutofControl_BMSH_ThermalOutofControl = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_Vehicle_HVILSts_PHEV_BMSH_Vehicle_HVILSts_PHEV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Vehicle_HVILSts_PHEV_BMSH_Vehicle_HVILSts_PHEV.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_Vehicle_HVILSts_PHEV_BMSH_Vehicle_HVILSts_PHEV = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_VoltCurr_Checksum_BMSH_VoltCurr_Checksum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_VoltCurr_Checksum_BMSH_VoltCurr_Checksum.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_VoltCurr_Checksum_BMSH_VoltCurr_Checksum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMSH_stMode_BMSH_stMode = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_stMode_BMSH_stMode.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMSH_stMode_BMSH_stMode = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMS_BattPackMatchFault_BMS_BattPackMatchFault = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_BattPackMatchFault_BMS_BattPackMatchFault.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_BattPackMatchFault_BMS_BattPackMatchFault = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMS_BATTPACKMATCHFAULT1_PMS_BMS_BATTPACKMATCHFAULT1_PMS);
    Rte_swc_VCOP_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_BMS_BATTPACKMATCHFAULT1_PMS_BMS_BATTPACKMATCHFAULT1_PMS);


    Rte_swc_VCOP_BMS_MaxCellVolt_BMS_MaxCellVolt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_MaxCellVolt_BMS_MaxCellVolt.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_MaxCellVolt_BMS_MaxCellVolt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMS_MaxTemp1SnsNum_BMS_MaxTemp1SnsNum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_MaxTemp1SnsNum_BMS_MaxTemp1SnsNum.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_MaxTemp1SnsNum_BMS_MaxTemp1SnsNum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMS_MaxVoltCellNum_BMS_MaxVoltCellNum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_MaxVoltCellNum_BMS_MaxVoltCellNum.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_MaxVoltCellNum_BMS_MaxVoltCellNum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMS_MinCellVolt_BMS_MinCellVolt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_MinCellVolt_BMS_MinCellVolt.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_MinCellVolt_BMS_MinCellVolt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMS_MinVoltCellNum_BMS_MinVoltCellNum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_MinVoltCellNum_BMS_MinVoltCellNum.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_MinVoltCellNum_BMS_MinVoltCellNum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_BMS_MinxTemp1SnsNum_BMS_MinxTemp1SnsNum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_MinxTemp1SnsNum_BMS_MinxTemp1SnsNum.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_BMS_MinxTemp1SnsNum_BMS_MinxTemp1SnsNum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_DrvPfmncRedn_DrvPfmncRedn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_DrvPfmncRedn_DrvPfmncRedn.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_DrvPfmncRedn_DrvPfmncRedn = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_EDCP_Flt_EDCP_Flt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EDCP_Flt_EDCP_Flt.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_EDCP_Flt_EDCP_Flt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_EDCP_PWMFB_EDCP_PWMFB = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EDCP_PWMFB_EDCP_PWMFB.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_EDCP_PWMFB_EDCP_PWMFB = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_HBCP_Flt_HBCP_Flt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_HBCP_Flt_HBCP_Flt.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_HBCP_Flt_HBCP_Flt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_HBCP_PWMFB_HBCP_PWMFB = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_HBCP_PWMFB_HBCP_PWMFB.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_HBCP_PWMFB_HBCP_PWMFB = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_IPK_IPKTotalOdometer_EV_IPK_IPKTotalOdometer_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPK_IPKTotalOdometer_EV_IPK_IPKTotalOdometer_EV.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPK_IPKTotalOdometer_EV_IPK_IPKTotalOdometer_EV = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_IPU_HVBusCur_PT_IPU_HVBusCur_PT = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_HVBusCur_PT_IPU_HVBusCur_PT.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_HVBusCur_PT_IPU_HVBusCur_PT = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_IPU_HVBusVolt_PT_IPU_HVBusVolt_PT = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_HVBusVolt_PT_IPU_HVBusVolt_PT.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_HVBusVolt_PT_IPU_HVBusVolt_PT = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_IPU_IPUTAlm_IPU_IPUTAlm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_IPUTAlm_IPU_IPUTAlm.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_IPUTAlm_IPU_IPUTAlm = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_IPU_MCUTempHighAlarm1_PT_IPU_MCUTempHighAlarm1_PT = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_MCUTempHighAlarm1_PT_IPU_MCUTempHighAlarm1_PT.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_MCUTempHighAlarm1_PT_IPU_MCUTempHighAlarm1_PT = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_IPU_MCUTEMPHIGHALARM2_PMS_IPU_MCUTEMPHIGHALARM2_PMS);
    Rte_swc_VCOP_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_IPU_MCUTEMPHIGHALARM2_PMS_IPU_MCUTEMPHIGHALARM2_PMS);


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_IPU_MOTOROVERCURRFLT1_PMS_IPU_MOTOROVERCURRFLT1_PMS);
    Rte_swc_VCOP_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_IPU_MOTOROVERCURRFLT1_PMS_IPU_MOTOROVERCURRFLT1_PMS);


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_IPU_MOTOROVERSPDFLT1_PMS_IPU_MOTOROVERSPDFLT1_PMS);
    Rte_swc_VCOP_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_IPU_MOTOROVERSPDFLT1_PMS_IPU_MOTOROVERSPDFLT1_PMS);


    Rte_swc_VCOP_IPU_MotorTempHighFault1_PT_IPU_MotorTempHighFault1_PT = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_MotorTempHighFault1_PT_IPU_MotorTempHighFault1_PT.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_MotorTempHighFault1_PT_IPU_MotorTempHighFault1_PT = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_IPU_MOTORTEMPHIGHFAULT2_PMS_IPU_MOTORTEMPHIGHFAULT2_PMS);
    Rte_swc_VCOP_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_IPU_MOTORTEMPHIGHFAULT2_PMS_IPU_MOTORTEMPHIGHFAULT2_PMS);


    Rte_swc_VCOP_MHGV_CCWFlg_PMS_MHGV_CCWFlg_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_CCWFlg_PMS_MHGV_CCWFlg_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_CCWFlg_PMS_MHGV_CCWFlg_PMS = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_MHGV_CurrentPos_PMS_MHGV_CurrentPos_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_CurrentPos_PMS_MHGV_CurrentPos_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_CurrentPos_PMS_MHGV_CurrentPos_PMS = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_MHGV_InitState_PMS_MHGV_InitState_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_InitState_PMS_MHGV_InitState_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_InitState_PMS_MHGV_InitState_PMS = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_MHGV_MotorState_PMS_MHGV_MotorState_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_MotorState_PMS_MHGV_MotorState_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_MotorState_PMS_MHGV_MotorState_PMS = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_MHGV_OverCurrentFlt_PMS_MHGV_OverCurrentFlt_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_OverCurrentFlt_PMS_MHGV_OverCurrentFlt_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_OverCurrentFlt_PMS_MHGV_OverCurrentFlt_PMS = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_MHGV_OverTempFlt_PMS_MHGV_OverTempFlt_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_OverTempFlt_PMS_MHGV_OverTempFlt_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_OverTempFlt_PMS_MHGV_OverTempFlt_PMS = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_MHGV_OverVoltageFlt_PMS_MHGV_OverVoltageFlt_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_OverVoltageFlt_PMS_MHGV_OverVoltageFlt_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_OverVoltageFlt_PMS_MHGV_OverVoltageFlt_PMS = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_MHGV_RESP_ERROR_PMS_MHGV_RESP_ERROR_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_RESP_ERROR_PMS_MHGV_RESP_ERROR_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_RESP_ERROR_PMS_MHGV_RESP_ERROR_PMS = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_MHGV_UnderVoltageFlt_PMS_MHGV_UnderVoltageFlt_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_UnderVoltageFlt_PMS_MHGV_UnderVoltageFlt_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_MHGV_UnderVoltageFlt_PMS_MHGV_UnderVoltageFlt_PMS = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_ODP_TBOX_DcDcStsAlm_ODP_TBOX_DcDcStsAlm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_ODP_TBOX_DcDcStsAlm_ODP_TBOX_DcDcStsAlm.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_ODP_TBOX_DcDcStsAlm_ODP_TBOX_DcDcStsAlm = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_ODP_TBOX_DCDCSTSALM1_PMS_ODP_TBOX_DCDCSTSALM1_PMS);
    Rte_swc_VCOP_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_ODP_TBOX_DCDCSTSALM1_PMS_ODP_TBOX_DCDCSTSALM1_PMS);


    Rte_swc_VCOP_ODP_TBOX_TDcDcAlm_ODP_TBOX_TDcDcAlm = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_ODP_TBOX_TDcDcAlm_ODP_TBOX_TDcDcAlm.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_ODP_TBOX_TDcDcAlm_ODP_TBOX_TDcDcAlm = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_ODP_TBOX_TDCDCALM1_PMS_ODP_TBOX_TDCDCALM1_PMS);
    Rte_swc_VCOP_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_ODP_TBOX_TDCDCALM1_PMS_ODP_TBOX_TDCDCALM1_PMS);


    Rte_swc_VCOP_PMS_0X16A_TimeoutFlag_PMS_0X16A_TimeoutFlag = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_0X16A_TimeoutFlag_PMS_0X16A_TimeoutFlag.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_0X16A_TimeoutFlag_PMS_0X16A_TimeoutFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_32960FLTNUM_PMS_PMS_32960FLTNUM_PMS);
    Rte_swc_VCOP_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_32960FLTNUM_PMS_PMS_32960FLTNUM_PMS);


    Rte_swc_VCOP_PMS_ACC1PosVol_PMS_ACC1PosVol = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ACC1PosVol_PMS_ACC1PosVol.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ACC1PosVol_PMS_ACC1PosVol = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ACC2PosVol_PMS_ACC2PosVol = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ACC2PosVol_PMS_ACC2PosVol.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ACC2PosVol_PMS_ACC2PosVol = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ACCMEnable_PMS_ACCMEnable = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ACCMEnable_PMS_ACCMEnable.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ACCMEnable_PMS_ACCMEnable = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ACC_BeControlled_Status_PMS_ACC_BeControlled_Status = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ACC_BeControlled_Status_PMS_ACC_BeControlled_Status.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ACC_BeControlled_Status_PMS_ACC_BeControlled_Status = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_AcceRelayVoltSampSwich_PMS_AcceRelayVoltSampSwich = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AcceRelayVoltSampSwich_PMS_AcceRelayVoltSampSwich.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AcceRelayVoltSampSwich_PMS_AcceRelayVoltSampSwich = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_AcceSuppressionSts_PMS_PMS_AcceSuppressionSts_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AcceSuppressionSts_PMS_PMS_AcceSuppressionSts_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AcceSuppressionSts_PMS_PMS_AcceSuppressionSts_PMS = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_AccelPedalPosition_PMS_AccelPedalPosition = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AccelPedalPosition_PMS_AccelPedalPosition.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AccelPedalPosition_PMS_AccelPedalPosition = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_AccelPedalPositionInvalid_PMS_AccelPedalPositionInvalid = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AccelPedalPositionInvalid_PMS_AccelPedalPositionInvalid.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AccelPedalPositionInvalid_PMS_AccelPedalPositionInvalid = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_Acceleration_PMS_Acceleration = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Acceleration_PMS_Acceleration.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Acceleration_PMS_Acceleration = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_AccessoryConnStsFb_PMS_AccessoryConnStsFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AccessoryConnStsFb_PMS_AccessoryConnStsFb.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AccessoryConnStsFb_PMS_AccessoryConnStsFb = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_AccessoryCtrlCommand_PMS_AccessoryCtrlCommand = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AccessoryCtrlCommand_PMS_AccessoryCtrlCommand.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AccessoryCtrlCommand_PMS_AccessoryCtrlCommand = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_AccessoryRelayFlt_PMS_AccessoryRelayFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AccessoryRelayFlt_PMS_AccessoryRelayFlt.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AccessoryRelayFlt_PMS_AccessoryRelayFlt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ActualPTTorque_PMS_ActualPTTorque = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ActualPTTorque_PMS_ActualPTTorque.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ActualPTTorque_PMS_ActualPTTorque = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ActualPTTorqueInvalid_PMS_ActualPTTorqueInvalid = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ActualPTTorqueInvalid_PMS_ActualPTTorqueInvalid.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ActualPTTorqueInvalid_PMS_ActualPTTorqueInvalid = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_AppSts_PMS_AppSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AppSts_PMS_AppSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AppSts_PMS_AppSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_AuthResult_PMS_AuthResult = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AuthResult_PMS_AuthResult.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AuthResult_PMS_AuthResult = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_AveragePowerConsumption_PMS_AveragePowerConsumption = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AveragePowerConsumption_PMS_AveragePowerConsumption.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_AveragePowerConsumption_PMS_AveragePowerConsumption = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_BBM1CtrlCmd_PMS_BBM1CtrlCmd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BBM1CtrlCmd_PMS_BBM1CtrlCmd.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BBM1CtrlCmd_PMS_BBM1CtrlCmd = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_BBMAllowEnable_Ctrl_PMS_BBMAllowEnable_Ctrl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BBMAllowEnable_Ctrl_PMS_BBMAllowEnable_Ctrl.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BBMAllowEnable_Ctrl_PMS_BBMAllowEnable_Ctrl = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_BBMPowerSupplyEn_Ctrl_PMS_BBMPowerSupplyEn_Ctrl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BBMPowerSupplyEn_Ctrl_PMS_BBMPowerSupplyEn_Ctrl.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BBMPowerSupplyEn_Ctrl_PMS_BBMPowerSupplyEn_Ctrl = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_BBM_FaultStatus_PMS_BBM_FaultStatus = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BBM_FaultStatus_PMS_BBM_FaultStatus.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BBM_FaultStatus_PMS_BBM_FaultStatus = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_BBM_HVReq_PMS_BBM_HVReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BBM_HVReq_PMS_BBM_HVReq.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BBM_HVReq_PMS_BBM_HVReq = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_BBM_WorkSts_PMS_BBM_WorkSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BBM_WorkSts_PMS_BBM_WorkSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BBM_WorkSts_PMS_BBM_WorkSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_BMSH_BattRemainEnergy_PMS_BMSH_BattRemainEnergy = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BMSH_BattRemainEnergy_PMS_BMSH_BattRemainEnergy.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BMSH_BattRemainEnergy_PMS_BMSH_BattRemainEnergy = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_BMSH_BattSOCDisp_PMS_BMSH_BattSOCDisp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BMSH_BattSOCDisp_PMS_BMSH_BattSOCDisp.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BMSH_BattSOCDisp_PMS_BMSH_BattSOCDisp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_BMSH_BattSOH_PMS_BMSH_BattSOH = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BMSH_BattSOH_PMS_BMSH_BattSOH.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BMSH_BattSOH_PMS_BMSH_BattSOH = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_BMS_Reignstatus1_PMS_BMS_Reignstatus1 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BMS_Reignstatus1_PMS_BMS_Reignstatus1.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BMS_Reignstatus1_PMS_BMS_Reignstatus1 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_BMS_Reignstatus2_PMS_BMS_Reignstatus2 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BMS_Reignstatus2_PMS_BMS_Reignstatus2.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BMS_Reignstatus2_PMS_BMS_Reignstatus2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_BatCoolType_PMS_BatCoolType = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BatCoolType_PMS_BatCoolType.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BatCoolType_PMS_BatCoolType = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_BattPackInCoolTempback_EV_PMS_BattPackInCoolTempback_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BattPackInCoolTempback_EV_PMS_BattPackInCoolTempback_EV.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BattPackInCoolTempback_EV_PMS_BattPackInCoolTempback_EV = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_BattPackOutCoolTempback_EV_PMS_BattPackOutCoolTempback_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BattPackOutCoolTempback_EV_PMS_BattPackOutCoolTempback_EV.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BattPackOutCoolTempback_EV_PMS_BattPackOutCoolTempback_EV = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_BatteryVol_PMS_BatteryVol = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BatteryVol_PMS_BatteryVol.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BatteryVol_PMS_BatteryVol = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_Brake_LightsRequest_PMS_Brake_LightsRequest = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Brake_LightsRequest_PMS_Brake_LightsRequest.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Brake_LightsRequest_PMS_Brake_LightsRequest = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_BrkSysErr_PMS_BrkSysErr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BrkSysErr_PMS_BrkSysErr.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_BrkSysErr_PMS_BrkSysErr = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_CANBus_RecSta_PMS_CANBus_RecSta = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CANBus_RecSta_PMS_CANBus_RecSta.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CANBus_RecSta_PMS_CANBus_RecSta = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_CPSREn_PMS_CPSREn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CPSREn_PMS_CPSREn.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CPSREn_PMS_CPSREn = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_CPSRU_PMS_CPSRU = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CPSRU_PMS_CPSRU.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CPSRU_PMS_CPSRU = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_CSControl1_CheckSum_PMS_CSControl1_CheckSum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CSControl1_CheckSum_PMS_CSControl1_CheckSum.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CSControl1_CheckSum_PMS_CSControl1_CheckSum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_CSControl2_CheckSum_PMS_CSControl2_CheckSum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CSControl2_CheckSum_PMS_CSControl2_CheckSum.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CSControl2_CheckSum_PMS_CSControl2_CheckSum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_CampModeFb_PMS_CampModeFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CampModeFb_PMS_CampModeFb.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CampModeFb_PMS_CampModeFb = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_CampModeFbFailrReason_PMS_CampModeFbFailrReason = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CampModeFbFailrReason_PMS_CampModeFbFailrReason.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CampModeFbFailrReason_PMS_CampModeFbFailrReason = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ChargPwr_PMS_ChargPwr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ChargPwr_PMS_ChargPwr.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ChargPwr_PMS_ChargPwr = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ChargWakeupSts_PMS_ChargWakeupSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ChargWakeupSts_PMS_ChargWakeupSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ChargWakeupSts_PMS_ChargWakeupSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ChargeHV_Status_PMS_ChargeHV_Status = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ChargeHV_Status_PMS_ChargeHV_Status.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ChargeHV_Status_PMS_ChargeHV_Status = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ChargeLimitResponse_PMS_ChargeLimitResponse = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ChargeLimitResponse_PMS_ChargeLimitResponse.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ChargeLimitResponse_PMS_ChargeLimitResponse = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ChargerFault_PMS_ChargerFault = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ChargerFault_PMS_ChargerFault.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ChargerFault_PMS_ChargerFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_Command_Checksum_PMS_Command_Checksum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Command_Checksum_PMS_Command_Checksum.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Command_Checksum_PMS_Command_Checksum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_CoolingFanFaultFB_PMS_CoolingFanFaultFB = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CoolingFanFaultFB_PMS_CoolingFanFaultFB.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CoolingFanFaultFB_PMS_CoolingFanFaultFB = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_Ctrl_Checksum_PMS_Ctrl_Checksum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Ctrl_Checksum_PMS_Ctrl_Checksum.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Ctrl_Checksum_PMS_Ctrl_Checksum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_CurrentGearPosition_PMS_CurrentGearPosition = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CurrentGearPosition_PMS_CurrentGearPosition.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CurrentGearPosition_PMS_CurrentGearPosition = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_DCDCAwake_HW_PMS_DCDCAwake_HW = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DCDCAwake_HW_PMS_DCDCAwake_HW.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DCDCAwake_HW_PMS_DCDCAwake_HW = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_DCDCPwrLmt_PMS_DCDCPwrLmt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DCDCPwrLmt_PMS_DCDCPwrLmt.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DCDCPwrLmt_PMS_DCDCPwrLmt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_DDwaterPump_PWMCtrl_EV_PMS_DDwaterPump_PWMCtrl_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DDwaterPump_PWMCtrl_EV_PMS_DDwaterPump_PWMCtrl_EV.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DDwaterPump_PWMCtrl_EV_PMS_DDwaterPump_PWMCtrl_EV = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_DcDcActvdReq_PMS_DcDcActvdReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DcDcActvdReq_PMS_DcDcActvdReq.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DcDcActvdReq_PMS_DcDcActvdReq = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_DisChrgrSwtSt_PMS_DisChrgrSwtSt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DisChrgrSwtSt_PMS_DisChrgrSwtSt.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DisChrgrSwtSt_PMS_DisChrgrSwtSt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_DischargeEnable_PMS_DischargeEnable = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DischargeEnable_PMS_DischargeEnable.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DischargeEnable_PMS_DischargeEnable = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_DoubleFlashLampOn_PMS_DoubleFlashLampOn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DoubleFlashLampOn_PMS_DoubleFlashLampOn.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DoubleFlashLampOn_PMS_DoubleFlashLampOn = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_DriveModeInd_PMS_DriveModeInd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriveModeInd_PMS_DriveModeInd.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DriveModeInd_PMS_DriveModeInd = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_DriverDemandTorque_PMS_DriverDemandTorque = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriverDemandTorque_PMS_DriverDemandTorque.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DriverDemandTorque_PMS_DriverDemandTorque = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_DriverDemandTorqueInvalid_PMS_DriverDemandTorqueInvalid = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriverDemandTorqueInvalid_PMS_DriverDemandTorqueInvalid.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DriverDemandTorqueInvalid_PMS_DriverDemandTorqueInvalid = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_DriverGearAbort_PMS_DriverGearAbort = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriverGearAbort_PMS_DriverGearAbort.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DriverGearAbort_PMS_DriverGearAbort = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_DrivingTakeEleSts_PMS_DrivingTakeEleSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DrivingTakeEleSts_PMS_DrivingTakeEleSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DrivingTakeEleSts_PMS_DrivingTakeEleSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_DrvrGearLvrLockIndcn_PMS_DrvrGearLvrLockIndcn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DrvrGearLvrLockIndcn_PMS_DrvrGearLvrLockIndcn.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_DrvrGearLvrLockIndcn_PMS_DrvrGearLvrLockIndcn = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_EDCPEnable_PMS_EDCPEnable = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EDCPEnable_PMS_EDCPEnable.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EDCPEnable_PMS_EDCPEnable = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_EDCP_FaultFB_PMS_EDCP_FaultFB = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EDCP_FaultFB_PMS_EDCP_FaultFB.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EDCP_FaultFB_PMS_EDCP_FaultFB = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_EDCP_PWMCtrl_PMS_EDCP_PWMCtrl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EDCP_PWMCtrl_PMS_EDCP_PWMCtrl.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EDCP_PWMCtrl_PMS_EDCP_PWMCtrl = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_EPS_SteeringAngleValue_PMS_EPS_SteeringAngleValue = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EPS_SteeringAngleValue_PMS_EPS_SteeringAngleValue.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EPS_SteeringAngleValue_PMS_EPS_SteeringAngleValue = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_EVDTEodometer_PMS_EVDTEodometer = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EVDTEodometer_PMS_EVDTEodometer.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EVDTEodometer_PMS_EVDTEodometer = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_EngControl_CheckSum_PMS_EngControl_CheckSum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EngControl_CheckSum_PMS_EngControl_CheckSum.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EngControl_CheckSum_PMS_EngControl_CheckSum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_EngTrqReqSrc_PMS_EngTrqReqSrc = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EngTrqReqSrc_PMS_EngTrqReqSrc.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_EngTrqReqSrc_PMS_EngTrqReqSrc = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ErrCode_PMS_ErrCode = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ErrCode_PMS_ErrCode.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ErrCode_PMS_ErrCode = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_FAN_PWMCtrl_PMS_FAN_PWMCtrl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FAN_PWMCtrl_PMS_FAN_PWMCtrl.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_FAN_PWMCtrl_PMS_FAN_PWMCtrl = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_Fn1GearRlyDrvStsFb_PMS_Fn1GearRlyDrvStsFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Fn1GearRlyDrvStsFb_PMS_Fn1GearRlyDrvStsFb.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Fn1GearRlyDrvStsFb_PMS_Fn1GearRlyDrvStsFb = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_Fn2GearRlyDrvStsFb_PMS_Fn2GearRlyDrvStsFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Fn2GearRlyDrvStsFb_PMS_Fn2GearRlyDrvStsFb.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Fn2GearRlyDrvStsFb_PMS_Fn2GearRlyDrvStsFb = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_FunAnti_DismantleActive_PMS_FunAnti_DismantleActive = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FunAnti_DismantleActive_PMS_FunAnti_DismantleActive.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_FunAnti_DismantleActive_PMS_FunAnti_DismantleActive = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_FunLockVehActive_PMS_FunLockVehActive = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FunLockVehActive_PMS_FunLockVehActive.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_FunLockVehActive_PMS_FunLockVehActive = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_GP_Ovrd_PMS_GP_Ovrd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_GP_Ovrd_PMS_GP_Ovrd.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_GP_Ovrd_PMS_GP_Ovrd = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_GearOperateErr_PMS_GearOperateErr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_GearOperateErr_PMS_GearOperateErr.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_GearOperateErr_PMS_GearOperateErr = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_Gear_intervene_PMS_Gear_intervene = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Gear_intervene_PMS_Gear_intervene.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Gear_intervene_PMS_Gear_intervene = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_GrossComVehWeight_PMS_GrossComVehWeight = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_GrossComVehWeight_PMS_GrossComVehWeight.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_GrossComVehWeight_PMS_GrossComVehWeight = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_HBCPEnable_PMS_HBCPEnable = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HBCPEnable_PMS_HBCPEnable.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HBCPEnable_PMS_HBCPEnable = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_HBCP_FaultFB_PMS_HBCP_FaultFB = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HBCP_FaultFB_PMS_HBCP_FaultFB.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HBCP_FaultFB_PMS_HBCP_FaultFB = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_HBCP_PWMCtrl_PMS_HBCP_PWMCtrl = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HBCP_PWMCtrl_PMS_HBCP_PWMCtrl.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HBCP_PWMCtrl_PMS_HBCP_PWMCtrl = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_HVIL1Sts_PMS_HVIL1Sts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVIL1Sts_PMS_HVIL1Sts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVIL1Sts_PMS_HVIL1Sts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_HVIL1Sts_UB_PMS_HVIL1Sts_UB = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVIL1Sts_UB_PMS_HVIL1Sts_UB.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVIL1Sts_UB_PMS_HVIL1Sts_UB = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_HVIL2Sts_PMS_HVIL2Sts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVIL2Sts_PMS_HVIL2Sts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVIL2Sts_PMS_HVIL2Sts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_HVIL2Sts_UB_PMS_HVIL2Sts_UB = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVIL2Sts_UB_PMS_HVIL2Sts_UB.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVIL2Sts_UB_PMS_HVIL2Sts_UB = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_HVILSts_PMS_HVILSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVILSts_PMS_HVILSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVILSts_PMS_HVILSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_HVILSts_UB_PMS_HVILSts_UB = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVILSts_UB_PMS_HVILSts_UB.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVILSts_UB_PMS_HVILSts_UB = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_HVPRASts_PMS_HVPRASts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVPRASts_PMS_HVPRASts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HVPRASts_PMS_HVPRASts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_HardwareMajorVer_PMS_HardwareMajorVer = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HardwareMajorVer_PMS_HardwareMajorVer.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HardwareMajorVer_PMS_HardwareMajorVer = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_HardwareMinorVer_PMS_HardwareMinorVer = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HardwareMinorVer_PMS_HardwareMinorVer.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HardwareMinorVer_PMS_HardwareMinorVer = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_HvCoolgPwrAllwd_PMS_HvCoolgPwrAllwd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HvCoolgPwrAllwd_PMS_HvCoolgPwrAllwd.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HvCoolgPwrAllwd_PMS_HvCoolgPwrAllwd = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_HvHeatgPwrAllwd_PMS_HvHeatgPwrAllwd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HvHeatgPwrAllwd_PMS_HvHeatgPwrAllwd.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_HvHeatgPwrAllwd_PMS_HvHeatgPwrAllwd = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_IPK_HandBrakeSts_PMS_IPK_HandBrakeSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IPK_HandBrakeSts_PMS_IPK_HandBrakeSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IPK_HandBrakeSts_PMS_IPK_HandBrakeSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_IgnONSts_PMS_IgnONSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IgnONSts_PMS_IgnONSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IgnONSts_PMS_IgnONSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_IntelligentChargeExitReq_PMS_IntelligentChargeExitReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IntelligentChargeExitReq_PMS_IntelligentChargeExitReq.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IntelligentChargeExitReq_PMS_IntelligentChargeExitReq = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_IntelligentChargeQuit_PMS_IntelligentChargeQuit = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IntelligentChargeQuit_PMS_IntelligentChargeQuit.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IntelligentChargeQuit_PMS_IntelligentChargeQuit = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_IntelligentChargeState_PMS_IntelligentChargeState = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IntelligentChargeState_PMS_IntelligentChargeState.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IntelligentChargeState_PMS_IntelligentChargeState = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_InventorySpdLmtRxSts_PMS_InventorySpdLmtRxSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_InventorySpdLmtRxSts_PMS_InventorySpdLmtRxSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_InventorySpdLmtRxSts_PMS_InventorySpdLmtRxSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_InventorySpdLmtSts_PMS_InventorySpdLmtSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_InventorySpdLmtSts_PMS_InventorySpdLmtSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_InventorySpdLmtSts_PMS_InventorySpdLmtSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_IsgModReq_PMS_IsgModReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IsgModReq_PMS_IsgModReq.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IsgModReq_PMS_IsgModReq = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_IsgTqReq_PMS_IsgTqReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IsgTqReq_PMS_IsgTqReq.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_IsgTqReq_PMS_IsgTqReq = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_LTCoolingFanFB_PMS_LTCoolingFanFB = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LTCoolingFanFB_PMS_LTCoolingFanFB.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LTCoolingFanFB_PMS_LTCoolingFanFB = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_Life_PMS_Life = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Life_PMS_Life.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Life_PMS_Life = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_LimpHomeSts_PMS_LimpHomeSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LimpHomeSts_PMS_LimpHomeSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LimpHomeSts_PMS_LimpHomeSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_LockLimResult_PMS_LockLimResult = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LockLimResult_PMS_LockLimResult.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LockLimResult_PMS_LockLimResult = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_LockVehExecutedSts_PMS_LockVehExecutedSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LockVehExecutedSts_PMS_LockVehExecutedSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LockVehExecutedSts_PMS_LockVehExecutedSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_LockVehPerFlag_PMS_LockVehPerFlag = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LockVehPerFlag_PMS_LockVehPerFlag.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LockVehPerFlag_PMS_LockVehPerFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_LockVehPerRxSts_PMS_LockVehPerRxSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LockVehPerRxSts_PMS_LockVehPerRxSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LockVehPerRxSts_PMS_LockVehPerRxSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_LockVehSts_PMS_LockVehSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LockVehSts_PMS_LockVehSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LockVehSts_PMS_LockVehSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_LockVehType_PMS_LockVehType = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LockVehType_PMS_LockVehType.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_LockVehType_PMS_LockVehType = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_MCUFlowFeedback_EV_PMS_MCUFlowFeedback_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MCUFlowFeedback_EV_PMS_MCUFlowFeedback_EV.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MCUFlowFeedback_EV_PMS_MCUFlowFeedback_EV = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_MHGV_EnableReq_PMS_MHGV_EnableReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_EnableReq_PMS_MHGV_EnableReq.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MHGV_EnableReq_PMS_MHGV_EnableReq = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_MHGV_PosSet_PMS_MHGV_PosSet = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_PosSet_PMS_MHGV_PosSet.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MHGV_PosSet_PMS_MHGV_PosSet = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_MHGV_ReqMotorEmgyStop_PMS_MHGV_ReqMotorEmgyStop = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_ReqMotorEmgyStop_PMS_MHGV_ReqMotorEmgyStop.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MHGV_ReqMotorEmgyStop_PMS_MHGV_ReqMotorEmgyStop = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_MHGV_ReqMotorOptRecovery_PMS_MHGV_ReqMotorOptRecovery = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_ReqMotorOptRecovery_PMS_MHGV_ReqMotorOptRecovery.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MHGV_ReqMotorOptRecovery_PMS_MHGV_ReqMotorOptRecovery = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_MaxPTTorqueAllowed_PMS_MaxPTTorqueAllowed = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MaxPTTorqueAllowed_PMS_MaxPTTorqueAllowed.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MaxPTTorqueAllowed_PMS_MaxPTTorqueAllowed = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_MinPTTorqueAllowed_PMS_MinPTTorqueAllowed = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MinPTTorqueAllowed_PMS_MinPTTorqueAllowed.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_MinPTTorqueAllowed_PMS_MinPTTorqueAllowed = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ModeControl_CheckSum_PMS_ModeControl_CheckSum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ModeControl_CheckSum_PMS_ModeControl_CheckSum.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ModeControl_CheckSum_PMS_ModeControl_CheckSum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_OTAINSTRUCSTSREMINDER_PMS_OTAINSTRUCSTSREMINDER);
    Rte_swc_VCOP_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_OTAINSTRUCSTSREMINDER_PMS_OTAINSTRUCSTSREMINDER);


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_OTAINSTRUCTRXNSTS_PMS_OTAINSTRUCTRXNSTS);
    Rte_swc_VCOP_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_OTAINSTRUCTRXNSTS_PMS_OTAINSTRUCTRXNSTS);


    Rte_swc_VCOP_PMS_OdometerbackupEnable_PMS_OdometerbackupEnable = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_OdometerbackupEnable_PMS_OdometerbackupEnable.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_OdometerbackupEnable_PMS_OdometerbackupEnable = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_PEPSAuth_PMS_PEPSAuth = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PEPSAuth_PMS_PEPSAuth.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PEPSAuth_PMS_PEPSAuth = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_PEPS_0x1E2_TimeoutFlag_PMS_PEPS_0x1E2_TimeoutFlag = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PEPS_0x1E2_TimeoutFlag_PMS_PEPS_0x1E2_TimeoutFlag.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PEPS_0x1E2_TimeoutFlag_PMS_PEPS_0x1E2_TimeoutFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_PEPS_PowerMode_PMS_PEPS_PowerMode = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PEPS_PowerMode_PMS_PEPS_PowerMode.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PEPS_PowerMode_PMS_PEPS_PowerMode = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_PEPS_PowerModeValidity_PMS_PEPS_PowerModeValidity = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PEPS_PowerModeValidity_PMS_PEPS_PowerModeValidity.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PEPS_PowerModeValidity_PMS_PEPS_PowerModeValidity = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_PTC1ConnStsFb_PMS_PTC1ConnStsFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTC1ConnStsFb_PMS_PTC1ConnStsFb.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTC1ConnStsFb_PMS_PTC1ConnStsFb = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_PTC1RelayFlt_PMS_PTC1RelayFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTC1RelayFlt_PMS_PTC1RelayFlt.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTC1RelayFlt_PMS_PTC1RelayFlt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_PTC2Enable_PMS_PTC2Enable = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTC2Enable_PMS_PTC2Enable.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTC2Enable_PMS_PTC2Enable = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_PTC3ConnStsFb_PMS_PTC3ConnStsFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTC3ConnStsFb_PMS_PTC3ConnStsFb.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTC3ConnStsFb_PMS_PTC3ConnStsFb = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_PTC3Enable_PMS_PTC3Enable = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTC3Enable_PMS_PTC3Enable.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTC3Enable_PMS_PTC3Enable = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_PTC3RelayFlt_PMS_PTC3RelayFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTC3RelayFlt_PMS_PTC3RelayFlt.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTC3RelayFlt_PMS_PTC3RelayFlt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_PTCEnable_PMS_PTCEnable = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTCEnable_PMS_PTCEnable.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTCEnable_PMS_PTCEnable = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_PTCRelayVoltSampSwich_PMS_PTCRelayVoltSampSwich = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTCRelayVoltSampSwich_PMS_PTCRelayVoltSampSwich.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTCRelayVoltSampSwich_PMS_PTCRelayVoltSampSwich = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_PowerOffCmdRxSts_PMS_PowerOffCmdRxSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PowerOffCmdRxSts_PMS_PowerOffCmdRxSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PowerOffCmdRxSts_PMS_PowerOffCmdRxSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_PowerOffCmdSts_PMS_PowerOffCmdSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PowerOffCmdSts_PMS_PowerOffCmdSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PowerOffCmdSts_PMS_PowerOffCmdSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_PreAccessoryConnStsFb_PMS_PreAccessoryConnStsFb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PreAccessoryConnStsFb_PMS_PreAccessoryConnStsFb.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PreAccessoryConnStsFb_PMS_PreAccessoryConnStsFb = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_PreAccessoryRelayFlt_PMS_PreAccessoryRelayFlt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PreAccessoryRelayFlt_PMS_PreAccessoryRelayFlt.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_PreAccessoryRelayFlt_PMS_PreAccessoryRelayFlt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_Real_PedalPosition_PMS_Real_PedalPosition = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Real_PedalPosition_PMS_Real_PedalPosition.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Real_PedalPosition_PMS_Real_PedalPosition = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_RegenTarTrqPot_PMS_RegenTarTrqPot = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegenTarTrqPot_PMS_RegenTarTrqPot.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegenTarTrqPot_PMS_RegenTarTrqPot = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_RegenTarTrqPotQualifier_PMS_RegenTarTrqPotQualifier = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegenTarTrqPotQualifier_PMS_RegenTarTrqPotQualifier.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegenTarTrqPotQualifier_PMS_RegenTarTrqPotQualifier = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_RegenTrqAct_PMS_RegenTrqAct = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegenTrqAct_PMS_RegenTrqAct.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegenTrqAct_PMS_RegenTrqAct = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_RegenTrqActQualifier_PMS_RegenTrqActQualifier = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegenTrqActQualifier_PMS_RegenTrqActQualifier.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegenTrqActQualifier_PMS_RegenTrqActQualifier = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_RegenTrqPot_PMS_RegenTrqPot = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegenTrqPot_PMS_RegenTrqPot.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegenTrqPot_PMS_RegenTrqPot = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_RegenTrqPotQualifier_PMS_RegenTrqPotQualifier = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegenTrqPotQualifier_PMS_RegenTrqPotQualifier.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegenTrqPotQualifier_PMS_RegenTrqPotQualifier = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_RegulationSpeed_PMS_PMS_RegulationSpeed_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegulationSpeed_PMS_PMS_RegulationSpeed_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RegulationSpeed_PMS_PMS_RegulationSpeed_PMS = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_RemChrgCmdFailrPrompt_PMS_RemChrgCmdFailrPrompt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RemChrgCmdFailrPrompt_PMS_RemChrgCmdFailrPrompt.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RemChrgCmdFailrPrompt_PMS_RemChrgCmdFailrPrompt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ReqSeed_PMS_ReqSeed = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ReqSeed_PMS_ReqSeed.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ReqSeed_PMS_ReqSeed = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_RespResult_PMS_RespResult = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RespResult_PMS_RespResult.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_RespResult_PMS_RespResult = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_SelfCheckSts_PMS_SelfCheckSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SelfCheckSts_PMS_SelfCheckSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_SelfCheckSts_PMS_SelfCheckSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_SoftwareMajorVer_PMS_SoftwareMajorVer = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SoftwareMajorVer_PMS_SoftwareMajorVer.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_SoftwareMajorVer_PMS_SoftwareMajorVer = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_SoftwareMinorVer_PMS_SoftwareMinorVer = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SoftwareMinorVer_PMS_SoftwareMinorVer.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_SoftwareMinorVer_PMS_SoftwareMinorVer = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_SpdLmtLevel_PMS_SpdLmtLevel = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SpdLmtLevel_PMS_SpdLmtLevel.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_SpdLmtLevel_PMS_SpdLmtLevel = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_SpdLmtLevelRxSts_PMS_SpdLmtLevelRxSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SpdLmtLevelRxSts_PMS_SpdLmtLevelRxSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_SpdLmtLevelRxSts_PMS_SpdLmtLevelRxSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_StartActive_PMS_StartActive = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_StartActive_PMS_StartActive.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_StartActive_PMS_StartActive = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_StsBrkSwitch1Invalid_PMS_PMS_StsBrkSwitch1Invalid_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_StsBrkSwitch1Invalid_PMS_PMS_StsBrkSwitch1Invalid_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_StsBrkSwitch1Invalid_PMS_PMS_StsBrkSwitch1Invalid_PMS = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_StsBrkSwitch1_PMS_PMS_StsBrkSwitch1_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_StsBrkSwitch1_PMS_PMS_StsBrkSwitch1_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_StsBrkSwitch1_PMS_PMS_StsBrkSwitch1_PMS = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_StsSwap_PMS_StsSwap = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_StsSwap_PMS_StsSwap.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_StsSwap_PMS_StsSwap = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_SwapAuthRelease_EV_PMS_SwapAuthRelease_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SwapAuthRelease_EV_PMS_SwapAuthRelease_EV.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_SwapAuthRelease_EV_PMS_SwapAuthRelease_EV = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_TBOX_BrkSysErr_PMS_TBOX_BrkSysErr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_BrkSysErr_PMS_TBOX_BrkSysErr.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TBOX_BrkSysErr_PMS_TBOX_BrkSysErr = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_TBOX_BRKSYSERR1_PMS_PMS_TBOX_BRKSYSERR1_PMS);
    Rte_swc_VCOP_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_TBOX_BRKSYSERR1_PMS_PMS_TBOX_BRKSYSERR1_PMS);


    Rte_swc_VCOP_PMS_TBOX_HVILSts_PMS_TBOX_HVILSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_HVILSts_PMS_TBOX_HVILSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TBOX_HVILSts_PMS_TBOX_HVILSts = RTE_COM_SENDSIGNALPROXY_SEND;


    (void)GetSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_TBOX_HVILSTS1_PMS_PMS_TBOX_HVILSTS1_PMS);
    Rte_swc_VCOP_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS = RTE_COM_SENDSIGNALPROXY_SEND;
    (void)ReleaseSpinlock(SPINLOCK_RTE_COM_SWC_VCOP_PMS_TBOX_HVILSTS1_PMS_PMS_TBOX_HVILSTS1_PMS);


    Rte_swc_VCOP_PMS_TBOX_LifeSts_PMS_TBOX_LifeSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_LifeSts_PMS_TBOX_LifeSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TBOX_LifeSts_PMS_TBOX_LifeSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_TakeEleSwtIndReq_PMS_TakeEleSwtIndReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TakeEleSwtIndReq_PMS_TakeEleSwtIndReq.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TakeEleSwtIndReq_PMS_TakeEleSwtIndReq = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_Torque_Ovrd_Active_PMS_Torque_Ovrd_Active = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Torque_Ovrd_Active_PMS_Torque_Ovrd_Active.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Torque_Ovrd_Active_PMS_Torque_Ovrd_Active = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_Torque_Ovrd_Type_PMS_Torque_Ovrd_Type = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Torque_Ovrd_Type_PMS_Torque_Ovrd_Type.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_Torque_Ovrd_Type_PMS_Torque_Ovrd_Type = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_TurtleLampOn_PMS_TurtleLampOn = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TurtleLampOn_PMS_TurtleLampOn.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TurtleLampOn_PMS_TurtleLampOn = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_TurtleLampOn2_PMS_TurtleLampOn2 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TurtleLampOn2_PMS_TurtleLampOn2.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_TurtleLampOn2_PMS_TurtleLampOn2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_V2XDchaSwtFb1_PMS_V2XDchaSwtFb1 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_V2XDchaSwtFb1_PMS_V2XDchaSwtFb1.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_V2XDchaSwtFb1_PMS_V2XDchaSwtFb1 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_VINCode1_8_15_S_PMS_VINCode1_8_15_S = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode1_8_15_S_PMS_VINCode1_8_15_S.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode1_8_15_S_PMS_VINCode1_8_15_S = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_VINCode2_9_16_S_PMS_VINCode2_9_16_S = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode2_9_16_S_PMS_VINCode2_9_16_S.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode2_9_16_S_PMS_VINCode2_9_16_S = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_VINCode3_10_17_S_PMS_VINCode3_10_17_S = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode3_10_17_S_PMS_VINCode3_10_17_S.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode3_10_17_S_PMS_VINCode3_10_17_S = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_VINCode4_11_S_PMS_VINCode4_11_S = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode4_11_S_PMS_VINCode4_11_S.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode4_11_S_PMS_VINCode4_11_S = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_VINCode5_12_S_PMS_VINCode5_12_S = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode5_12_S_PMS_VINCode5_12_S.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode5_12_S_PMS_VINCode5_12_S = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_VINCode6_13_S_PMS_VINCode6_13_S = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode6_13_S_PMS_VINCode6_13_S.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode6_13_S_PMS_VINCode6_13_S = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_VINCode7_14_S_PMS_VINCode7_14_S = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode7_14_S_PMS_VINCode7_14_S.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINCode7_14_S_PMS_VINCode7_14_S = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_VINMessageNum_S_PMS_VINMessageNum_S = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINMessageNum_S_PMS_VINMessageNum_S.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VINMessageNum_S_PMS_VINMessageNum_S = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_VacuumPressure_PMS_VacuumPressure = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VacuumPressure_PMS_VacuumPressure.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VacuumPressure_PMS_VacuumPressure = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_VacuumPumpCmd_PMS_VacuumPumpCmd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VacuumPumpCmd_PMS_VacuumPumpCmd.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VacuumPumpCmd_PMS_VacuumPumpCmd = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_VacuumPump_FB_PMS_VacuumPump_FB = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VacuumPump_FB_PMS_VacuumPump_FB.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VacuumPump_FB_PMS_VacuumPump_FB = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_VacuumSystemsta_PMS_VacuumSystemsta = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VacuumSystemsta_PMS_VacuumSystemsta.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VacuumSystemsta_PMS_VacuumSystemsta = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_VehicleSpeed_PMS_VehicleSpeed = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VehicleSpeed_PMS_VehicleSpeed.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VehicleSpeed_PMS_VehicleSpeed = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_VehicleSysErrorLevel_PMS_VehicleSysErrorLevel = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VehicleSysErrorLevel_PMS_VehicleSysErrorLevel.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VehicleSysErrorLevel_PMS_VehicleSysErrorLevel = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_VehicleSysErrorLevelG_PMS_VehicleSysErrorLevelG = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VehicleSysErrorLevelG_PMS_VehicleSysErrorLevelG.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VehicleSysErrorLevelG_PMS_VehicleSysErrorLevelG = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_VehicleSysErrorLevelG1_PMS_PMS_VehicleSysErrorLevelG1_PMS = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VehicleSysErrorLevelG1_PMS_PMS_VehicleSysErrorLevelG1_PMS.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VehicleSysErrorLevelG1_PMS_PMS_VehicleSysErrorLevelG1_PMS = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_VersionConversionFlag_PMS_VersionConversionFlag = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VersionConversionFlag_PMS_VersionConversionFlag.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VersionConversionFlag_PMS_VersionConversionFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_VersionConversionRxSts_PMS_VersionConversionRxSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VersionConversionRxSts_PMS_VersionConversionRxSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_VersionConversionRxSts_PMS_VersionConversionRxSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ePTFault_PMS_ePTFault = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTFault_PMS_ePTFault.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ePTFault_PMS_ePTFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ePTFault2_PMS_ePTFault2 = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTFault2_PMS_ePTFault2.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ePTFault2_PMS_ePTFault2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ePTModeActual_PMS_ePTModeActual = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTModeActual_PMS_ePTModeActual.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ePTModeActual_PMS_ePTModeActual = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ePTModeSelect_PMS_ePTModeSelect = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTModeSelect_PMS_ePTModeSelect.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ePTModeSelect_PMS_ePTModeSelect = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ePTReady_PMS_ePTReady = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTReady_PMS_ePTReady.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ePTReady_PMS_ePTReady = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_PMS_ePTReleaseSig_PMS_ePTReleaseSig = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTReleaseSig_PMS_ePTReleaseSig.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_PMS_ePTReleaseSig_PMS_ePTReleaseSig = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_TBOX_ChrgSoftSwCtrlst_EV_TBOX_ChrgSoftSwCtrlst_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_TBOX_ChrgSoftSwCtrlst_EV_TBOX_ChrgSoftSwCtrlst_EV.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_TBOX_ChrgSoftSwCtrlst_EV_TBOX_ChrgSoftSwCtrlst_EV = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_TBOX_ReservationChrgnSts_EV_TBOX_ReservationChrgnSts_EV = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_TBOX_ReservationChrgnSts_EV_TBOX_ReservationChrgnSts_EV.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_TBOX_ReservationChrgnSts_EV_TBOX_ReservationChrgnSts_EV = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_VCU_ActInputVolt_VCU_ActInputVolt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_ActInputVolt_VCU_ActInputVolt.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_ActInputVolt_VCU_ActInputVolt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_VCU_BMSH_Ctrl_CheckSum_VCU_BMSH_Ctrl_CheckSum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_Ctrl_CheckSum_VCU_BMSH_Ctrl_CheckSum.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_BMSH_Ctrl_CheckSum_VCU_BMSH_Ctrl_CheckSum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_VCU_BMSH_DCChgRelayVolt_VCU_BMSH_DCChgRelayVolt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_DCChgRelayVolt_VCU_BMSH_DCChgRelayVolt.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_BMSH_DCChgRelayVolt_VCU_BMSH_DCChgRelayVolt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_VCU_ChargeDepthReq_VCU_ChargeDepthReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_ChargeDepthReq_VCU_ChargeDepthReq.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_ChargeDepthReq_VCU_ChargeDepthReq = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_VCU_CrashOutputSts_VCU_CrashOutputSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_CrashOutputSts_VCU_CrashOutputSts.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_CrashOutputSts_VCU_CrashOutputSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_VCU_DCInputCurrent_VCU_DCInputCurrent = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_DCInputCurrent_VCU_DCInputCurrent.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_DCInputCurrent_VCU_DCInputCurrent = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_VCU_Odometerbackup_VCU_Odometerbackup = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_Odometerbackup_VCU_Odometerbackup.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_Odometerbackup_VCU_Odometerbackup = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_VCOP_VCU_VehicleInfo_CheckSum_VCU_VehicleInfo_CheckSum = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_VehicleInfo_CheckSum_VCU_VehicleInfo_CheckSum.value);
    Rte_App1_Application_Core1_QM_TxUpdateFlags.Rte_TxUpdate_swc_VCOP_VCU_VehicleInfo_CheckSum_VCU_VehicleInfo_CheckSum = RTE_COM_SENDSIGNALPROXY_SEND;

    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_acpd_x_accPedlPos_pct.value) = Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPos_pct;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_adcd_b_adcCtrlGearEn.value) = Rte_swc_VCIP_vcib_VCIP_adcd_b_adcCtrlGearEn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_adcd_st_adcTgtGearPostn.value) = Rte_swc_VCIP_vcib_VCIP_adcd_st_adcTgtGearPostn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_adcd_st_pmsAdcCtrldSts.value) = Rte_swc_VCIP_vcib_VCIP_adcd_st_pmsAdcCtrldSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_brpd_e_brkPedalStatus.value) = Rte_swc_VCIP_vcib_VCIP_brpd_e_brkPedalStatus;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_cesd_b_EmergencyStop.value) = Rte_swc_VCIP_vcib_VCIP_cesd_b_EmergencyStop;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_drid_b_drvrModeReq.value) = Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_drid_b_drvrModeReq4WD.value) = Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReq4WD;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_drid_b_drvrModeReqECO.value) = Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqECO;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_drid_b_drvrModeReqEV.value) = Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqEV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_drid_b_drvrModeReqHEV.value) = Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqHEV;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_drid_b_drvrModeReqSPORT.value) = Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqSPORT;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_drid_b_parkBtnPressed.value) = Rte_swc_VCIP_vcib_VCIP_drid_b_parkBtnPressed;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_drid_e_gearLvrPosRaw.value) = Rte_swc_VCIP_vcib_VCIP_drid_e_gearLvrPosRaw;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_drid_st_gearLvrPosSeql.value) = Rte_swc_VCIP_vcib_VCIP_drid_st_gearLvrPosSeql;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_eadd_b_eadInv2ActvDischCmplt.value) = Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2ActvDischCmplt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm.value) = Rte_swc_VCIP_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_epbd_e_parkingSts.value) = Rte_swc_VCIP_vcib_VCIP_epbd_e_parkingSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmd.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_macd_b_pullUpDiagCmpl.value) = Rte_swc_VCIP_vcib_VCIP_macd_b_pullUpDiagCmpl;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_obcd_b_obcCANMsgValid.value) = Rte_swc_VCIP_vcib_VCIP_obcd_b_obcCANMsgValid;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_obcd_b_obcChrgCablePlugged.value) = Rte_swc_VCIP_vcib_VCIP_obcd_b_obcChrgCablePlugged;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_obcd_b_obcWakeUp.value) = Rte_swc_VCIP_vcib_VCIP_obcd_b_obcWakeUp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_pmmd_b_anyIgnOn.value) = Rte_swc_VCIP_vcib_VCIP_pmmd_b_anyIgnOn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_pmmd_b_driverStartReq.value) = Rte_swc_VCIP_vcib_VCIP_pmmd_b_driverStartReq;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value) = Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_pmmd_b_ptCanNmStRdy.value) = Rte_swc_VCIP_vcib_VCIP_pmmd_b_ptCanNmStRdy;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_pmmd_e_authenticationStatus.value) = Rte_swc_VCIP_vcib_VCIP_pmmd_e_authenticationStatus;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_bcmFrntLftDrAjSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_bcmFrntLftDrAjSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_bcmFrntRDrAjSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_bcmFrntRDrAjSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_epbErrSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_epbErrSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_flgFctCfgChgTyp.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgChgTyp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvMod.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvMod;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvModStor.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvModStor;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvSeat.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvSeat;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_flgFnctnConfgEGSM.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_flgFnctnConfgEGSM;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_st_dcChgCcSt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_dcChgCcSt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_st_egsmShftLvrFailSt.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_egsmShftLvrFailSt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_st_flgFctCfgMotTyp.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgMotTyp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehCfg.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehCfg;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_st_hvbChgCcsts.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgCcsts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_st_obcChgCCSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_obcChgCCSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_st_obcOnBdCCline.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_obcOnBdCCline;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_st_obcOnBdDchaCCline.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_obcOnBdDchaCCline;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vscd_b_vehSpdVld.value) = Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSpdVld;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value) = Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_AUXC_brpd_b_airTankFlt.value) = Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankFlt;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_AUXC_brpd_b_airTankPresLowInhDrv.value) = Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankPresLowInhDrv;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_DIAG_ddid_b_egsmMsgErr.value) = Rte_swc_DIAG_vcsb_DIAG_ddid_b_egsmMsgErr;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_HVSM_eadd_b_ead2Avail.value) = Rte_swc_HVSM_vcsb_HVSM_eadd_b_ead2Avail;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_HVSM_hvbd_b_chgCablePlugged.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_chgCablePlugged;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_HVSM_hvbd_b_fltPwrShutDn.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_fltPwrShutDn;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_HVSM_hvbd_b_rlyTmOut.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_rlyTmOut;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_HVSM_hvbd_b_vcuRdyToSlp.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_b_vcuRdyToSlp;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_HVSM_hvbd_st_ptRdyInd.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_st_ptRdyInd;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_HVSM_obcd_b_chargerPlugged.value) = Rte_swc_HVSM_vcsb_HVSM_obcd_b_chargerPlugged;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_HVSM_obcd_e_chargerSts.value) = Rte_swc_HVSM_vcsb_HVSM_obcd_e_chargerSts;
    *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_THSM_thmd_b_afterRunActive.value) = Rte_swc_THSM_vcsb_THSM_thmd_b_afterRunActive;
    swc_VOMM_Step();
    Rte_swc_VOMM_vcsb_VOMM_drid_b_epbClsdReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_b_epbClsdReq.value);
    Rte_swc_VOMM_vcsb_VOMM_drid_b_gearPosVld = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_b_gearPosVld.value);
    Rte_swc_VOMM_vcsb_VOMM_drid_b_veh4WDModActv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_b_veh4WDModActv.value);
    Rte_swc_VOMM_vcsb_VOMM_drid_b_vehEcoModActv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_b_vehEcoModActv.value);
    Rte_swc_VOMM_vcsb_VOMM_drid_b_vehSportModActv = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_b_vehSportModActv.value);
    Rte_swc_VOMM_vcsb_VOMM_drid_e_driveDirSel = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_e_driveDirSel.value);
    Rte_swc_VOMM_vcsb_VOMM_drid_e_drvrHEVModReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_e_drvrHEVModReq.value);
    Rte_swc_VOMM_vcsb_VOMM_drid_e_gearLvrPos = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_e_gearLvrPos.value);
    Rte_swc_VOMM_vcsb_VOMM_drid_st_gearLvrLckInd = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_st_gearLvrLckInd.value);
    Rte_swc_VOMM_vcsb_VOMM_essd_b_engStartReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_engStartReq.value);
    Rte_swc_VOMM_vcsb_VOMM_essd_b_engStopReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_engStopReq.value);
    Rte_swc_VOMM_vcsb_VOMM_essd_b_engStrtAbort = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_engStrtAbort.value);
    Rte_swc_VOMM_vcsb_VOMM_essd_b_engStrtComplete = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_engStrtComplete.value);
    Rte_swc_VOMM_vcsb_VOMM_essd_b_motStrtDem = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_motStrtDem.value);
    Rte_swc_VOMM_vcsb_VOMM_essd_b_motStrtEnad = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_motStrtEnad.value);
    Rte_swc_VOMM_vcsb_VOMM_essd_b_strtrRlyDem = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_strtrRlyDem.value);
    Rte_swc_VOMM_vcsb_VOMM_essd_e_engStrtTyp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_e_engStrtTyp.value);
    Rte_swc_VOMM_vcsb_VOMM_essd_e_engStrtTypSeld = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_e_engStrtTypSeld.value);
    Rte_swc_VOMM_vcsb_VOMM_hmmd_b_EVModeActive = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_hmmd_b_EVModeActive.value);
    Rte_swc_VOMM_vcsb_VOMM_hmmd_b_HVBusDischrgComplete = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_hmmd_b_HVBusDischrgComplete.value);
    Rte_swc_VOMM_vcsb_VOMM_pmmd_b_emsWake = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_emsWake.value);
    Rte_swc_VOMM_vcsb_VOMM_pmmd_b_hsdFltClear = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_hsdFltClear.value);
    Rte_swc_VOMM_vcsb_VOMM_pmmd_b_nmRdySlp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_nmRdySlp.value);
    Rte_swc_VOMM_vcsb_VOMM_pmmd_b_nmSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_nmSts.value);
    Rte_swc_VOMM_vcsb_VOMM_pmmd_b_nmWkUp = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_nmWkUp.value);
    Rte_swc_VOMM_vcsb_VOMM_pmmd_b_peuWake = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_peuWake.value);
    Rte_swc_VOMM_vcsb_VOMM_pmmd_b_pwrHoldReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_pwrHoldReq.value);
    Rte_swc_VOMM_vcsb_VOMM_pmmd_b_startReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_startReq.value);
    Rte_swc_VOMM_vcsb_VOMM_pmmd_b_vcuAwb = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_vcuAwb.value);
    Rte_swc_VOMM_vcsb_VOMM_pmmd_b_vcuRmr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_vcuRmr.value);
    Rte_MemCpy(Rte_swc_VOMM_vcsb_VOMM_pmmd_bm_netModeReq, Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_bm_netModeReq.value, sizeof(rt_Array_UInt8_2));
    Rte_swc_VOMM_vcsb_VOMM_pmmd_e_CanNMSts = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_e_CanNMSts.value);
    Rte_swc_VOMM_vcsb_VOMM_pmmd_e_mode = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_e_mode.value);
    Rte_swc_VOMM_vcsb_VOMM_pmmd_num_vcuAddr = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_num_vcuAddr.value);
    Rte_swc_VOMM_vcsb_VOMM_pmmd_st_bdCanModeReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_st_bdCanModeReq.value);
    Rte_swc_VOMM_vcsb_VOMM_pmmd_st_ptCanModeReq = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_st_ptCanModeReq.value);
    Rte_swc_VOMM_vcsb_VOMM_pmmd_st_stayAwkReason = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_st_stayAwkReason.value);
    Rte_swc_VOMM_vcsb_VOMM_pmmd_st_vcuPwrActvMod = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_st_vcuPwrActvMod.value);
    Rte_swc_VOMM_vcsb_VOMM_pmmd_st_vcuWkUpReason = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_st_vcuWkUpReason.value);
    Rte_swc_VOMM_vcsb_VOMM_vsmd_b_PTDisabled = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_vsmd_b_PTDisabled.value);
    Rte_swc_VOMM_vcsb_VOMM_vsmd_b_PTEnabled = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_vsmd_b_PTEnabled.value);
    Rte_swc_VOMM_vcsb_VOMM_vsmd_b_StartDemRaw = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_vsmd_b_StartDemRaw.value);
    Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRun = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_vsmd_b_VehRun.value);
    Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRunRaw = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_vsmd_b_VehRunRaw.value);
    Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehStrt = *(&Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_vsmd_b_VehStrt.value);

    (void)TerminateTask();
}

TASK(App1_Task_20ms_Core1_QM)
{
    Core1_Runnable_App_20ms();

    (void)TerminateTask();
}

TASK(App1_Task_50ms_Core1_QM)
{
    Core1_Runnable_App_50ms();

    (void)TerminateTask();
}

TASK(App1_Task_100ms_Core1_QM)
{
    Core1_Runnable_App_100ms();

    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_accd_e_PtcSt.value) = Rte_swc_VCIP_vcib_VCIP_accd_e_PtcSt;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_accd_n_acFanReqSpd_pct.value) = Rte_swc_VCIP_vcib_VCIP_accd_n_acFanReqSpd_pct;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_accd_st_cbnThermMngReq.value) = Rte_swc_VCIP_vcib_VCIP_accd_st_cbnThermMngReq;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_accd_st_iptWorkSt.value) = Rte_swc_VCIP_vcib_VCIP_accd_st_iptWorkSt;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_accd_st_ptcWorkStRear.value) = Rte_swc_VCIP_vcib_VCIP_accd_st_ptcWorkStRear;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_accd_t_ambTemp_C.value) = Rte_swc_VCIP_vcib_VCIP_accd_t_ambTemp_C;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_accd_u_acPresVolt_V.value) = Rte_swc_VCIP_vcib_VCIP_accd_u_acPresVolt_V;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_brpd_e_brkPedalStatus.value) = Rte_swc_VCIP_vcib_VCIP_brpd_e_brkPedalStatus;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_dccd_st_12vDcdcModAct.value) = Rte_swc_VCIP_vcib_VCIP_dccd_st_12vDcdcModAct;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_dccd_t_dcdcTemp_C.value) = Rte_swc_VCIP_vcib_VCIP_dccd_t_dcdcTemp_C;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_eadd_t_inv2Temp_C.value) = Rte_swc_VCIP_vcib_VCIP_eadd_t_inv2Temp_C;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_eadd_t_mot2Temp_C.value) = Rte_swc_VCIP_vcib_VCIP_eadd_t_mot2Temp_C;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_hvbd_b_hvbHeatEnad.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbHeatEnad;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_hvbd_st_hvbThermMngReq.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvbThermMngReq;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_hvbd_t_hvbInCoolTemp_C.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbInCoolTemp_C;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_hvbd_t_hvbMin_C.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbMin_C;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_hvbd_t_hvbTemp_C.value) = Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbTemp_C;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_macd_t_ts5SnsrTemp_C.value) = Rte_swc_VCIP_vcib_VCIP_macd_t_ts5SnsrTemp_C;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_obcd_t_obcTemp_C.value) = Rte_swc_VCIP_vcib_VCIP_obcd_t_obcTemp_C;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value) = Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_b_flgFctCfgBatCol.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgBatCol;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_b_hcmPtcRlyVoltVldSts.value) = Rte_swc_VCIP_vcib_VCIP_vild_b_hcmPtcRlyVoltVldSts;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_st_flg2FctCfgVehTyp.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flg2FctCfgVehTyp;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_st_flgFctCfgAccy.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgAccy;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_st_flgFctCfgFan.value) = Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgFan;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_t_acwpOutptTemp_C.value) = Rte_swc_VCIP_vcib_VCIP_vild_t_acwpOutptTemp_C;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_t_hvbSetTgtTemp_C.value) = Rte_swc_VCIP_vcib_VCIP_vild_t_hvbSetTgtTemp_C;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_u_TS5sensorFb_mV.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_TS5sensorFb_mV;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_u_hcmAcceRlyVolt.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_hcmAcceRlyVolt;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_u_hcmPtcRlyVolt.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_hcmPtcRlyVolt;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_u_hvbCooltInSnsr_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_hvbCooltInSnsr_V;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_u_hvbCooltOutSnsr_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_hvbCooltOutSnsr_V;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_u_ipuHVBusVolt_V.value) = Rte_swc_VCIP_vcib_VCIP_vild_u_ipuHVBusVolt_V;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value) = Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_DIAG_digd_b_vehCrashFltLvl33.value) = Rte_swc_DIAG_vcsb_DIAG_digd_b_vehCrashFltLvl33;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_EGYM_egmd_b_ptcEnbAllowFlg.value) = Rte_swc_EGYM_vcsb_EGYM_egmd_b_ptcEnbAllowFlg;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_EGYM_egmd_b_ptcRearEnbAllowFlg.value) = Rte_swc_EGYM_vcsb_EGYM_egmd_b_ptcRearEnbAllowFlg;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_HVSM_hvbd_e_PmmStatus.value) = Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_HVSM_obcd_b_chargerPlugged.value) = Rte_swc_HVSM_vcsb_HVSM_obcd_b_chargerPlugged;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_VOMM_drid_e_gearLvrPos.value) = Rte_swc_VOMM_vcsb_VOMM_drid_e_gearLvrPos;
    *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_VOMM_pmmd_b_pwrHoldReq.value) = Rte_swc_VOMM_vcsb_VOMM_pmmd_b_pwrHoldReq;
    swc_THSM_Step();
    Rte_swc_THSM_vcsb_THSM_thmd_b_ActiveCool_flg = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_ActiveCool_flg.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_BalanceHeat_flg = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_BalanceHeat_flg.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_PassCool_flg = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_PassCool_flg.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_PassHeat_flg = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_PassHeat_flg.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_TwoWayVlvReq = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_TwoWayVlvReq.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_accmEnb = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_accmEnb.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_afterRunActive = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_afterRunActive.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_fan2Ena = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_fan2Ena.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_fanRly1Req = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_fanRly1Req.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_fanRly2Req = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_fanRly2Req.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_heaterEna.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna2 = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_heaterEna2.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna3 = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_heaterEna3.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna3HW = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_heaterEna3HW.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEnaHW = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_heaterEnaHW.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_hvbDeft = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_hvbDeft.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_iptcHtIpuCl = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_iptcHtIpuCl.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_iptcHtIpuResvHt = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_iptcHtIpuResvHt.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_ipuHeatEnableFlg = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_ipuHeatEnableFlg.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_ipuResvHt = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_ipuResvHt.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_ipuSupHtIptcHt = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_ipuSupHtIptcHt.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_tv1V2 = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_tv1V2.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_tv1V3 = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_tv1V3.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_tv2V2 = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_tv2V2.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_tv4V2 = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_tv4V2.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_tv4V3 = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_tv4V3.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmp1CtrlEnabled = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_wtrPmp1CtrlEnabled.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmp2CtrlEnabled = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_wtrPmp2CtrlEnabled.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmpRly1Req = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_wtrPmpRly1Req.value);
    Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmpRly2Req = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_wtrPmpRly2Req.value);
    Rte_swc_THSM_vcsb_THSM_thmd_n_FWFVTgt_pct = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_n_FWFVTgt_pct.value);
    Rte_swc_THSM_vcsb_THSM_thmd_n_MHGVTgt_pct = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_n_MHGVTgt_pct.value);
    Rte_swc_THSM_vcsb_THSM_thmd_n_fan1TgtSpd_pct = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_n_fan1TgtSpd_pct.value);
    Rte_swc_THSM_vcsb_THSM_thmd_n_fan2TgtSpd_pct = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_n_fan2TgtSpd_pct.value);
    Rte_swc_THSM_vcsb_THSM_thmd_n_pmp1TgtSpd_pct = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_n_pmp1TgtSpd_pct.value);
    Rte_swc_THSM_vcsb_THSM_thmd_n_pmp2TgtSpd_pct = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_n_pmp2TgtSpd_pct.value);
    Rte_swc_THSM_vcsb_THSM_thmd_pwr_ipuHeatPwrAllwd_kW = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_pwr_ipuHeatPwrAllwd_kW.value);
    Rte_swc_THSM_vcsb_THSM_thmd_q_pmp2FlowFeedback = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_q_pmp2FlowFeedback.value);
    Rte_swc_THSM_vcsb_THSM_thmd_st_acceRlyVoltSamSwitch = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_acceRlyVoltSamSwitch.value);
    Rte_swc_THSM_vcsb_THSM_thmd_st_acwpHeat = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_acwpHeat.value);
    Rte_swc_THSM_vcsb_THSM_thmd_st_acwpSpdReq = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_acwpSpdReq.value);
    Rte_swc_THSM_vcsb_THSM_thmd_st_ptc3ConnStsFb = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_ptc3ConnStsFb.value);
    Rte_swc_THSM_vcsb_THSM_thmd_st_ptc3RlyFlt = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_ptc3RlyFlt.value);
    Rte_swc_THSM_vcsb_THSM_thmd_st_ptcConnStsFb = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_ptcConnStsFb.value);
    Rte_swc_THSM_vcsb_THSM_thmd_st_ptcRlyFlt = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_ptcRlyFlt.value);
    Rte_swc_THSM_vcsb_THSM_thmd_st_ptcRlyVoltSamSwitch = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_ptcRlyVoltSamSwitch.value);
    Rte_swc_THSM_vcsb_THSM_thmd_st_tv4 = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_tv4.value);
    Rte_swc_THSM_vcsb_THSM_thmd_t_acwpTemp_C = *(&Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_t_acwpTemp_C.value);

    (void)TerminateTask();
}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
TASK(App1_Task_UDS_Core1_QM)
{
    EventMaskType ev = 0U;
    for(;;)
    {
        (void)WaitEvent(APP1_EVENT_UDS_CORE1_QM
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_AC_ACCM_ACTPOWER_0X0328_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_BMSH_CCM_THERMALMANAGEREQ_0X0329_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_BMSH_SELFCHECKFAULT_0X032B_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_CSM_V2XDCHASWTINVALID_0X0324_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_DCDC_SELFCHKSTS_0X032C_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_EHB_EPBSTATUS_0X0312_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_IPU_SELFCHKSTS_0X032A_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PEPS_POWERMODE_0X0319_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_ACCMENABLE_0X031D_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_BATTERYVOL_0X0331_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_BRAKE1SWITCH_0X0311_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_BRAKE2SWITCH_0X0333_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_CPSREN_0X0313_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_COOLINGFANPWMSPD_0X031C_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_DCDCCUTOFFLV_0X032E_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_DCDCACTVDREQ_0X032D_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_DRIVEMODEIND_0X0317_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_EDCPPWMCTRL_0X031A_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_ENGRECMODE_FB_0X0325_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_FUNLOCKVEHACTIVE_0X0318_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_HBCPPWMCTRL_0X031B_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_HVIL1STS_0X0322_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_HVIL2STS_0X0323_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_IPKTOTALODOMETER_0X0334_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_IGNONSTS_0X0332_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_ISGMODREQ_0X032F_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_ISGTQREQ_0X0314_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_MODEGEARDISPLAYSTS_0X0316_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_PTC2ENABLE_0X031F_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_PTC3ENABLE_0X0320_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_PTCENABLE_0X031E_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_PTRESIDUEPWRIND_0X0315_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_REAL_PEDALPOSITION_0X0310_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_SELFCHECKSTS_0X0321_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_VEHICLESPEED_0X0327_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_VCU_BMSH_STSMODEREQ_0X0330_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_VCU_ODOMETERBACKUP_0X0326_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X1002_OPERATION
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X1003_OPERATION
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X11_OPERATION
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X14_OPERATION
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X22_OPERATION
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X27_OPERATION
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X28_OPERATION
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X2E_OPERATION
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X31_OPERATION
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X85_OPERATION);
        (void)GetEvent(APP1_TASK_UDS_CORE1_QM, &ev);
        (void)ClearEvent(ev & (APP1_EVENT_UDS_CORE1_QM
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_AC_ACCM_ACTPOWER_0X0328_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_BMSH_CCM_THERMALMANAGEREQ_0X0329_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_BMSH_SELFCHECKFAULT_0X032B_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_CSM_V2XDCHASWTINVALID_0X0324_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_DCDC_SELFCHKSTS_0X032C_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_EHB_EPBSTATUS_0X0312_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_IPU_SELFCHKSTS_0X032A_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PEPS_POWERMODE_0X0319_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_ACCMENABLE_0X031D_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_BATTERYVOL_0X0331_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_BRAKE1SWITCH_0X0311_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_BRAKE2SWITCH_0X0333_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_CPSREN_0X0313_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_COOLINGFANPWMSPD_0X031C_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_DCDCCUTOFFLV_0X032E_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_DCDCACTVDREQ_0X032D_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_DRIVEMODEIND_0X0317_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_EDCPPWMCTRL_0X031A_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_ENGRECMODE_FB_0X0325_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_FUNLOCKVEHACTIVE_0X0318_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_HBCPPWMCTRL_0X031B_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_HVIL1STS_0X0322_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_HVIL2STS_0X0323_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_IPKTOTALODOMETER_0X0334_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_IGNONSTS_0X0332_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_ISGMODREQ_0X032F_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_ISGTQREQ_0X0314_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_MODEGEARDISPLAYSTS_0X0316_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_PTC2ENABLE_0X031F_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_PTC3ENABLE_0X0320_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_PTCENABLE_0X031E_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_PTRESIDUEPWRIND_0X0315_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_REAL_PEDALPOSITION_0X0310_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_SELFCHECKSTS_0X0321_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_VEHICLESPEED_0X0327_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_VCU_BMSH_STSMODEREQ_0X0330_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_VCU_ODOMETERBACKUP_0X0326_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X1002_OPERATION
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X1003_OPERATION
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X11_OPERATION
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X14_OPERATION
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X22_OPERATION
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X27_OPERATION
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X28_OPERATION
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X2E_OPERATION
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X31_OPERATION
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X85_OPERATION));
		#if 0 //UDS不使用
        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_AC_ACCM_ACTPOWER_0X0328_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData_Type));
            }

            AC_ACCM_ActPower_0x0328_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_BMSH_CCM_THERMALMANAGEREQ_0X0329_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData_Type));
            }

            BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_BMSH_SELFCHECKFAULT_0X032B_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData_Type));
            }

            BMSH_SelfCheckFault_0x032B_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_CSM_V2XDCHASWTINVALID_0X0324_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData_Type));
            }

            CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_DCDC_SELFCHKSTS_0X032C_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData_Type));
            }

            DCDC_SelfChkSts_0x032C_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_EHB_EPBSTATUS_0X0312_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData_Type));
            }

            EHB_EPBStatus_0x0312_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_IPU_SELFCHKSTS_0X032A_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData_Type));
            }

            IPU_SelfChkSts_0x032A_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PEPS_POWERMODE_0X0319_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData_Type));
            }

            PEPS_PowerMode_0x0319_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_ACCMENABLE_0X031D_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData_Type));
            }

            PMS_ACCMEnable_0x031D_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_BATTERYVOL_0X0331_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData_Type));
            }

            PMS_BatteryVol_0x0331_CS_ReadData( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_BRAKE1SWITCH_0X0311_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData_Type));
            }

            PMS_Brake1Switch_0x0311_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_BRAKE2SWITCH_0X0333_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData_Type));
            }

            PMS_Brake2Switch_0x0333_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_CPSREN_0X0313_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData_Type));
            }

            PMS_CPSREn_0x0313_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_COOLINGFANPWMSPD_0X031C_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData_Type));
            }

            PMS_CoolingFanPWMSpd_0x031C_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_DCDCCUTOFFLV_0X032E_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData_Type));
            }

            PMS_DCDCCutOffLV_0x032E_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_DCDCACTVDREQ_0X032D_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData_Type));
            }

            PMS_DcDcActvdReq_0x032D_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_DRIVEMODEIND_0X0317_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData_Type));
            }

            PMS_DriveModeInd_0x0317_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_EDCPPWMCTRL_0X031A_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData_Type));
            }

            PMS_EDCPPWMCtrl_0x031A_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_ENGRECMODE_FB_0X0325_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData_Type));
            }

            PMS_EngRecMode_Fb_0x0325_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_FUNLOCKVEHACTIVE_0X0318_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData_Type));
            }

            PMS_FunLockVehActive_0x0318_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_HBCPPWMCTRL_0X031B_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData_Type));
            }

            PMS_HBCPPWMCtrl_0x031B_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_HVIL1STS_0X0322_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData_Type));
            }

            PMS_HVIL1Sts_0x0322_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_HVIL2STS_0X0323_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData_Type));
            }

            PMS_HVIL2Sts_0x0323_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_IPKTOTALODOMETER_0X0334_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData_Type));
            }

            PMS_IPKTotalOdometer_0x0334_CS_ReadData( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_IGNONSTS_0X0332_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData_Type));
            }

            PMS_IgnONSts_0x0332_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_ISGMODREQ_0X032F_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData_Type));
            }

            PMS_IsgModReq_0x032F_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_ISGTQREQ_0X0314_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData_Type));
            }

            PMS_IsgTqReq_0x0314_CS_ReadData( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_MODEGEARDISPLAYSTS_0X0316_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData_Type));
            }

            PMS_ModeGearDisplaySts_0x0316_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_PTC2ENABLE_0X031F_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData_Type));
            }

            PMS_PTC2Enable_0x031F_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_PTC3ENABLE_0X0320_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData_Type));
            }

            PMS_PTC3Enable_0x0320_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_PTCENABLE_0X031E_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData_Type));
            }

            PMS_PTCEnable_0x031E_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_PTRESIDUEPWRIND_0X0315_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData_Type));
            }

            PMS_PTResiduePwrInd_0x0315_CS_ReadData( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_REAL_PEDALPOSITION_0X0310_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData_Type));
            }

            PMS_Real_PedalPosition_0x0310_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_SELFCHECKSTS_0X0321_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData_Type));
            }

            PMS_SelfCheckSts_0x0321_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_VEHICLESPEED_0X0327_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData_Type));
            }

            PMS_VehicleSpeed_0x0327_CS_ReadData( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_VCU_BMSH_STSMODEREQ_0X0330_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData_Type));
            }

            VCU_BMSH_StsModeReq_0x0330_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_VCU_ODOMETERBACKUP_0X0326_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData_Type));
            }

            VCU_Odometerbackup_0x0326_CS_ReadData( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X1002_OPERATION) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1002_Operation_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x1002_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1002_Operation_Type));
            }

            ServiceCheckRule_0x1002_Operation( &cs_Server.Cond);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x1002_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1002_Operation_Type));
            }

            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x1002_Operation.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X1003_OPERATION) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1003_Operation_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x1003_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1003_Operation_Type));
            }

            ServiceCheckRule_0x1003_Operation( &cs_Server.Cond);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x1003_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1003_Operation_Type));
            }

            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x1003_Operation.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X11_OPERATION) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x11_Operation_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x11_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x11_Operation_Type));
            }

            ServiceCheckRule_0x11_Operation();


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x11_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x11_Operation_Type));
            }

            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x11_Operation.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X14_OPERATION) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x14_Operation_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x14_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x14_Operation_Type));
            }

            ServiceCheckRule_0x14_Operation();


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x14_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x14_Operation_Type));
            }

            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x14_Operation.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X22_OPERATION) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x22_Operation_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x22_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x22_Operation_Type));
            }

            ServiceCheckRule_0x22_Operation();


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x22_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x22_Operation_Type));
            }

            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x22_Operation.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X27_OPERATION) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x27_Operation_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x27_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x27_Operation_Type));
            }

            ServiceCheckRule_0x27_Operation();


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x27_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x27_Operation_Type));
            }

            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x27_Operation.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X28_OPERATION) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x28_Operation_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x28_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x28_Operation_Type));
            }

            ServiceCheckRule_0x28_Operation();


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x28_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x28_Operation_Type));
            }

            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x28_Operation.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X2E_OPERATION) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x2E_Operation_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x2E_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x2E_Operation_Type));
            }

            ServiceCheckRule_0x2E_Operation();


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x2E_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x2E_Operation_Type));
            }

            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x2E_Operation.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X31_OPERATION) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x31_Operation_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x31_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x31_Operation_Type));
            }

            ServiceCheckRule_0x31_Operation();


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x31_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x31_Operation_Type));
            }

            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x31_Operation.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X85_OPERATION) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x85_Operation_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x85_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x85_Operation_Type));
            }

            ServiceCheckRule_0x85_Operation();


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x85_Operation);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x85_Operation_Type));
            }

            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x85_Operation.Rte_ServerCompleted = TRUE;
        }
		#endif
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    Mode Switch API (Rte_Switch)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Mode Mode API (Rte_Mode)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    IsUpdate Func
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    RTE_ISUPDATE Func
************************************************************************************************************************
*/


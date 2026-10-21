/*
************************************************************************************************************************
*
* File name: Rte_App1_Application_Core2_QM.c
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
#include "Rte_swc_BatBalnCtl.h"
#include "Rte_swc_BatChCtl.h"
#include "Rte_swc_BatCoreFct.h"
#include "Rte_swc_BatProtnIU.h"
#include "Rte_swc_BatProtnPack.h"
#include "Rte_swc_BatThermHndlgMngt.h"
#include "Rte_swc_BatWntyLogtcData.h"
#include "Rte_swc_BcuStTranCtl.h"
#include "Rte_swc_CIL.h"
#include "Rte_swc_COL.h"
#include "Rte_swc_CtctrTranCtl.h"
#include "Rte_swc_DiagcEveHndlg.h"
#include "Rte_swc_EltlLnkHzrdProtnNet.h"
#include "Rte_swc_SetInputInterface.h"
#include "Rte_swc_SetOutputInterface.h"
#include "Rte_swc_SetSendCANMsg.h"
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
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_BCM_DoorLockStatusDrv_BCM_LDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx = 2U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_BCM_DoorLockStatusPass_BCM_RDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx = 2U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ChargeModeReq_CIL_ChargeModeReq = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CRO_ChargerReady_CRO_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint32, RTE_VAR_INIT) Rte_ComBuffer_CHM_ProtocolVersion_CHM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CCS_ChargeAllow_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortByUser_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortAchiveCondition_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortByFault_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortErrorVoltage_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortErrorCurrent_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortFaultEnergeTransmit_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortFaultConnetor_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortFaultChargerTemp_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortFaultChargerInnerTemp_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortFaultOther_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortFaultChargerStop_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CCS_ChargeTotalTime_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CCS_OutputCurrent_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_TotalCurr_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_HCM_ShuntTemp_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx = 65U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_NegInsulateVal_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx = 5000U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_PosInsulateVal_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx = 5000U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_FastChgBackVolt_HCM_OtherRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_MainPosBackVolt_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_MainNegBackVolt_HCM_OtherRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx = 0U;
VAR(uint32, RTE_VAR_INIT) Rte_ComBuffer_HCM_InsulateCounter_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_MainPosFrtVolt_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_Day_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 1U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_Hour_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_Minute_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_Month_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 1U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_Second_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_Year_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CML_OutputCurrentMax_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CML_OutpuVoltageMax_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CML_OutputCurrentMin_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CML_OutputVoltageMin_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_CCvalue_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_DischargeCCvalue_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_OBC_uInAct_OBC_Curr_PMS_EV_CAN_20260427_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CSD_OutputEnerge_CSD_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CRM_RecognitionResult_CRM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BatteryChargeRequireTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BatteryParameterTimout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BatteryStateTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BMSIdentifyTimout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BMSFinishChargeTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BMSChargeStatisticsTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BMSAbortChargeTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CCS_OutputVoltage_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_12VBatFault_BMSH_12VBatFault = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_AllowBatTempMax_BMSH_AllowBatTempMax = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_AllowBatTempMin_BMSH_AllowBatTempMin = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_AllowCellVoltMax_BMSH_AllowCellVoltMax = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_AllowCellVoltMin_BMSH_AllowCellVoltMin = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_AllowPackVoltMax_BMSH_AllowPackVoltMax = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_AllowPackVoltMin_BMSH_AllowPackVoltMin = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatCurrent_BMSH_BatCurrent = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatMaintReqValidFlag_BMSH_BatMaintReqValidFlag = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatMaintenanceReq_BMSH_BatMaintenanceReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatOverSOC_BMSH_BatOverSOC = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatOverVolt_BMSH_BatOverVolt = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatRealSOC_BMSH_BatRealSOC = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatRealSOCValidFlag_BMSH_BatRealSOCValidFlag = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatSOE_BMSH_BatSOE = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatSOEValidFlag_BMSH_BatSOEValidFlag = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatSOH_BMSH_BatSOH = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatSOHValidFlag_BMSH_BatSOHValidFlag = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatTempMax_BMSH_BatTempMax = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatTempMin_BMSH_BatTempMin = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatUnderSOC_BMSH_BatUnderSOC = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatUnderVolt_BMSH_BatUnderVolt = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatUseableSOC_BMSH_BatUseableSOC = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatUseableSOCValidFlag_BMSH_BatUseableSOCValidFlag = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BattPackNum_BMSH_BattPackNum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BattSysNum_BMSH_BattSysNum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BattTempAvg_BMSH_BattTempAvg = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BusVolt_BMSH_BusVolt = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BusVoltValidFlag_BMSH_BusVoltValidFlag = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_InletTargTmpValidFlag_BMSH_CCM_InletTargTmpValidFlag = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_LiquidInTempValidFlag_BMSH_CCM_LiquidInTempValidFlag = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_LiquidOutTmpValidFlag_BMSH_CCM_LiquidOutTmpValidFlag = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_ThrmlMangReqValidFlag_BMSH_CCM_ThrmlMangReqValidFlag = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellOverVolt_BMSH_CellOverVolt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellTempUniformity_BMSH_CellTempUniformity = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellUnderVolt_BMSH_CellUnderVolt = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellVoltMax_BMSH_CellVoltMax = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellVoltMaxModuleID_BMSH_CellVoltMaxModuleID = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellVoltMin_BMSH_CellVoltMin = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellVoltMinModuleID_BMSH_CellVoltMinModuleID = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_ChgOverTemp_BMSH_ChgOverTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_ChgUnderTemp_BMSH_ChgUnderTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_ConnectNegOverTemp_BMSH_ConnectNegOverTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_ConnectPosOverTemp_BMSH_ConnectPosOverTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CoolType_BMSH_CoolType = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_CoolTypeValidFlag_BMSH_CoolTypeValidFlag = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChargeProcess_BMSH_DCChargeProcess = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgCurReq_BMSH_DCChgCurReq = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgEnder_BMSH_DCChgEnder = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgPosRelayFault_BMSH_DCChgPosRelayFault = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRelayFault_BMSH_DCChgRelayFault = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CCS_BMSH_DCChgRx_OTime_CCS = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CML_BMSH_DCChgRx_OTime_CML = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CRM00_BMSH_DCChgRx_OTime_CRM00 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CRMAA_BMSH_DCChgRx_OTime_CRMAA = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CSD_BMSH_DCChgRx_OTime_CSD = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgStandVer_BMSH_DCChgStandVer = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgVoltAllow_BMSH_DCChgVoltAllow = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgVoltAllowValidFlag_BMSH_DCChgVoltAllowValidFlag = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCEquipment_DisplayCur_BMSH_DCEquipment_DisplayCur = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCEquipment_DisplayVolt_BMSH_DCEquipment_DisplayVolt = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DC_DisplayCurRangeUP_BMSH_DC_DisplayCurRangeUP = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DC_DisplayVoltValidFlag_BMSH_DC_DisplayVoltValidFlag = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DataStorageFault_BMSH_DataStorageFault = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DisChgOverCurrent_BMSH_DisChgOverCurrent = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DisChgOverTemp_BMSH_DisChgOverTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DisChgUnderTemp_BMSH_DisChgUnderTemp = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_EVCANComFault_BMSH_EVCANComFault = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_EnergyOut_BMSH_EnergyOut = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_EnergyOutValidFlag_BMSH_EnergyOutValidFlag = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_ExChgNumOfTimes_BMSH_ExChgNumOfTimes = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_ExChgNumOfTimesValidFlag_BMSH_ExChgNumOfTimesValidFlag = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_FastChgComFault_BMSH_FastChgComFault = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_FaultCode_BMSH_FaultCode = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_FinishChgTime_BMSH_FinishChgTime = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_FinishChgTimeValidFlag_BMSH_FinishChgTimeValidFlag = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_FireAlarm_BMSH_FireAlarm = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_FlowRateReq_BMSH_FlowRateReq = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_FlowRateReqValidFlag_BMSH_FlowRateReqValidFlag = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_IntComFault_BMSH_IntComFault = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_MainNegRelayFault_BMSH_MainNegRelayFault = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_MainPosRelayFault_BMSH_MainPosRelayFault = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode1_BMSH_PackCode1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode1_1_BMSH_PackCode1_1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode2_BMSH_PackCode2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode2_1_BMSH_PackCode2_1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode3_BMSH_PackCode3 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode3_1_BMSH_PackCode3_1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode4_BMSH_PackCode4 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode4_1_BMSH_PackCode4_1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode5_BMSH_PackCode5 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode5_1_BMSH_PackCode5_1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode6_BMSH_PackCode6 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode7_BMSH_PackCode7 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode_ID_BMSH_PackCode_ID = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackExtendCd_BMSH_PackExtendCd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackType_BMSH_PackType = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackVolt_BMSH_PackVolt = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_RecoveryOverCurrent_BMSH_RecoveryOverCurrent = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_SelfCheckFault_BMSH_SelfCheckFault = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsA_plus_BMSH_StsA_plus = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsCC2_BMSH_StsCC2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsCellBalance_BMSH_StsCellBalance = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsChgFault_BMSH_StsChgFault = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsDischgFault_BMSH_StsDischgFault = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsInsulation_BMSH_StsInsulation = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsMode_BMSH_StsMode = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsPrecharge_BMSH_StsPrecharge = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsWakeUp_BMSH_StsWakeUp = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_SubtotalExChgSOE_BMSH_SubtotalExChgSOE = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_SubtotalRecoveryEng_BMSH_SubtotalRecoveryEng = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_SupplyVolt_BMSH_SupplyVolt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_SwapCntOverTemp_BMSH_SwapCntOverTemp = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatFaultList_BMSH_TBOX_BatFaultList = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatHVILFault_BMSH_TBOX_BatHVILFault = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatIsoAlarm_BMSH_TBOX_BatIsoAlarm = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2 = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatLowSOC_BMSH_TBOX_BatLowSOC = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2 = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatLowTemp_BMSH_TBOX_BatLowTemp = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatModuleSum_BMSH_TBOX_BatModuleSum = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverCharge_BMSH_TBOX_BatOverCharge = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2 = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverSOC_BMSH_TBOX_BatOverSOC = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2 = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverTemp_BMSH_TBOX_BatOverTemp = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2 = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverVoltage_BMSH_TBOX_BatOverVoltage = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatProductDay_BMSH_TBOX_BatProductDay = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatProductMonth_BMSH_TBOX_BatProductMonth = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatProductYear_BMSH_TBOX_BatProductYear = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatRatedEnergy_BMSH_TBOX_BatRatedEnergy = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatRatedVolt_BMSH_TBOX_BatRatedVolt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatSeriesCellsSum_BMSH_TBOX_BatSeriesCellsSum = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatStoreSysFault_BMSH_TBOX_BatStoreSysFault = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatTempUniformity_BMSH_TBOX_BatTempUniformity = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatType_BMSH_TBOX_BatType = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatUnderVoltage_BMSH_TBOX_BatUnderVoltage = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2 = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatUniformity_BMSH_TBOX_BatUniformity = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellOverVoltage_BMSH_TBOX_CellOverVoltage = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2 = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellRatedVolt_BMSH_TBOX_CellRatedVolt = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellUnderVoltage_BMSH_TBOX_CellUnderVoltage = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_HWVer_BMSH_TBOX_HWVer = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_HWVer_Test_BMSH_TBOX_HWVer_Test = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_InsulationResistance_BMSH_TBOX_InsulationResistance = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_SOCHop_BMSH_TBOX_SOCHop = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_SWVer_BMSH_TBOX_SWVer = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_SWVer_Test_BMSH_TBOX_SWVer_Test = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempA_BMSH_TBOX_TempA = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempB_BMSH_TBOX_TempB = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempC_BMSH_TBOX_TempC = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempD_BMSH_TBOX_TempD = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempE_BMSH_TBOX_TempE = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempF_BMSH_TBOX_TempF = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempF_ID_BMSH_TBOX_TempF_ID = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TheftFault_BMSH_TBOX_TheftFault = FALSE;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalDischgCapacity_BMSH_TotalDischgCapacity = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalDischgEng_BMSH_TotalDischgEng = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalExChgCapacity_BMSH_TotalExChgCapacity = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalExChgEng_BMSH_TotalExChgEng = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalExChgSOE_BMSH_TotalExChgSOE = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalOdometer_BMSH_TotalOdometer = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalOdometerValidFlag_BMSH_TotalOdometerValidFlag = FALSE;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalRecoveryCapacity_BMSH_TotalRecoveryCapacity = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalRecoveryEng_BMSH_TotalRecoveryEng = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TripOdometer_BMSH_TripOdometer = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TripOdometerValidFlag_BMSH_TripOdometerValidFlag = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCUChksumFault_BMSH_VCUChksumFault = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCURollCountFault_BMSH_VCURollCountFault = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatChgContPwr_BMSH_VCU_BatChgContPwr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatChgPeakPwr_BMSH_VCU_BatChgPeakPwr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatDischgContPwr_BMSH_VCU_BatDischgContPwr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatDischgPeakPwr_BMSH_VCU_BatDischgPeakPwr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_ChgSOPRangeUP_BMSH_VCU_ChgSOPRangeUP = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_ChgSOPValidFlag_BMSH_VCU_ChgSOPValidFlag = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_Crash_BMSH_VCU_Crash = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_DCChgNegTemp_BMSH_VCU_DCChgNegTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_DCChgPosTemp_BMSH_VCU_DCChgPosTemp = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_DisChgSOPValidFlag_BMSH_VCU_DisChgSOPValidFlag = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_StsDCChgPosRelay_BMSH_VCU_StsDCChgPosRelay = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_StsDCChgRelay_BMSH_VCU_StsDCChgRelay = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_StsPreChgRelay_BMSH_VCU_StsPreChgRelay = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_B2V_ST1_ChgMode_BMS_B2V_ST1_ChgMode = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattCellsNumPN_BMS_BattCellsNumPN = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattPackNumSN_BMS_BattPackNumSN = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattTemp1_BMS_BattTemp1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattTemp2_BMS_BattTemp2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattTemp3_BMS_BattTemp3 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattTemp4_BMS_BattTemp4 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattTemp5_BMS_BattTemp5 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattTemp6_BMS_BattTemp6 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CCvalue_BMS_CCvalue = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_CPLine_S2_Ctrl_BMS_CPLine_S2_Ctrl = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CP_Duty_BMS_CP_Duty = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CP_Vol_BMS_CP_Vol = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CellTempFrameNum_BMS_CellTempFrameNum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CellVoltFrameNum_BMS_CellVoltFrameNum = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_CellVoltN1_BMS_CellVoltN1 = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_CellVoltN2_BMS_CellVoltN2 = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_CellVoltN3_BMS_CellVoltN3 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_ChgCCSts_BMS_ChgCCSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_ChgStatus_BMS_ChgStatus = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CutOffLVFbToOBC_BMS_CutOffLVFbToOBC = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_DCChargRelayCtrl_BMS_DCChargRelayCtrl = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_DelayControl_BMS_DelayControl = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_DischargeCCvalue_BMS_DischargeCCvalue = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_ElectroniclockContorREQ_BMS_ElectroniclockContorREQ = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_ElectroniclockSts_BMS_ElectroniclockSts = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_MaxChgCurrent_BMS_MaxChgCurrent = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_MaxChgVoltage_BMS_MaxChgVoltage = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_OBCChgContrlCmd_BMS_OBCChgContrlCmd = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_S2STATUS_BMS_S2STATUS = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_SlowChgNegTemp_BMS_SlowChgNegTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_SlowChgPosTemp_BMS_SlowChgPosTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_SysCodeBattPackSN_1_BMS_SysCodeBattPackSN_1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_SysCodeFrameNum_1_BMS_SysCodeFrameNum_1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_SysCodeLength_1_BMS_SysCodeLength_1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_TempCSCNum_BMS_TempCSCNum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_TempSnsNumPN_BMS_TempSnsNumPN = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_VCU_ChrgFullCalRemind_BMS_VCU_ChrgFullCalRemind = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_VCU_ChrgModeAct_BMS_VCU_ChrgModeAct = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_VCU_ChrgModeCalRemind_BMS_VCU_ChrgModeCalRemind = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_VCU_ChrgModeEn_BMS_VCU_ChrgModeEn = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_VoltCellNum_BMS_VoltCellNum = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_HvSysSample_DisableIso_DisableIso = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCL_ChargingMode_ChargingMode = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCL_CurrentDemand_CurrentDemand = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCL_VoltageDemand_VoltageDemand = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCP_MaxPermTemperature_MaxPermTemperature = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCP_TotalNominalEnergy_TotalNominalEnergy = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCS_CurrentChargeState_CurrentChargeState = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BEM_Timeout_CCS_Timeout_CCS = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BEM_Timeout_CRO_Timeout_CRO = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BEM_Timeout_CSD_Timeout_CSD = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BEM_Timeout_CST_Timeout_CST = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BEM_Timeout_CTS_CML_Timeout_CTS_CML = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BHM_MaxChargingVoltage_MaxChargingVoltage = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BMS_BMSStopChgReason_BMS_BMSStopChgReason = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BMS_CCUStopChgReason_BMS_CCUStopChgReason = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BRM_BatterySystemCapacity_BatterySystemCapacity = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BRM_BatterySystemVoltage_BatterySystemVoltage = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BRM_BatteryType_BatteryType = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BRO_BmsReadyForCharging_BmsReadyForCharging = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_BatteryExcessTemperature_BatteryExcessTemperature = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_BatteryHighestTemp_BatteryHighestTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_BatteryInsulationState_BatteryInsulationState = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_BatteryLowestTemp_BatteryLowestTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_BsmChargingPermissible_BsmChargingPermissible = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspCause_SOC_BmsSuspCause_SOC = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BmsProtocolVersion_BmsProtocolVersion = 0U;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"
VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp = {0U};
VAR(rt_Array_UInt16_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_AcvCellTgtReqdOutp_BBC_AcvCellTgtReqdOutp = {0U};
VAR(rt_Array_UInt16_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_CtrBalnReqdOutp_BBC_CtrBalnReqdOutp = {0U};
VAR(rt_Array_Float_255, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_ICellBaln_BBC_ICellBaln = {0U};
VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_NrMdulSrcReqdOutp_BBC_NrMdulSrcReqdOutp = {0U};
VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_NrMdulTgtReqdOutp_BBC_NrMdulTgtReqdOutp = {0U};
VAR(rt_Array_UInt8_255, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv = {0U};
VAR(Float, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_TiCtlBalMaxLim_BBC_TiCtlBalMaxLim = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_bAcvBaln_BBC_bAcvBaln = FALSE;
VAR(rt_Array_Boolean_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln = {0U};
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_AcvCellURchd_BCC_AcvCellURchd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_AcvSocRchd_BCC_AcvSocRchd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_AcvUTotRchd_BCC_AcvUTotRchd = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ChgCCSts_BCC_ChgCCSts = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_EChSng_BCC_EChSng = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ElectroniclockContorFault_BCC_ElectroniclockContorFault = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ElectroniclockContorREQ_BCC_ElectroniclockContorREQ = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ElectroniclockSt_BCC_ElectroniclockSt = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ErrInfo_BCC_ErrInfo = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_IChReq_BCC_IChReq = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_IDchaReq_BCC_IDchaReq = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_IObcLimn_BCC_IObcLimn = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ModeCh_BCC_ModeCh = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_StAcChReq_BCC_StAcChReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_StAcSys_BCC_StAcSys = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_StCh_BCC_StCh = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_TranAcChEndByBatHvReq_BCC_TranAcChEndByBatHvReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_UChReq_BCC_UChReq = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_UObcLimn_BCC_UObcLimn = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_bAcvDig10_BCC_bAcvDig10 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_bAcvHvbatFull_BCC_bAcvHvbatFull = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_bS2Ctrl_BCC_bS2Ctrl = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCTE_TiBatChMaxByHour_BCTE_TiBatChMaxByHour = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCTE_TiBatChMaxByMinu_BCTE_TiBatChMaxByMinu = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCTE_TiBatDchaByMinuTot_BCTE_TiBatDchaByMinuTot = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ChMode_EVCSH_ChMode = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChRdy_EVCSH_ErrMsgChrgrChRdy = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChSts_EVCSH_ErrMsgChrgrChSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChStstc_EVCSH_ErrMsgChrgrChStstc = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChSuspd_EVCSH_ErrMsgChrgrChSuspd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrIdfcNotRdy_EVCSH_ErrMsgChrgrIdfcNotRdy = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrIdfcRdy_EVCSH_ErrMsgChrgrIdfcRdy = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrSync_EVCSH_ErrMsgChrgrSync = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_IChrgrSp_EVCSH_IChrgrSp = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_StBatRdy_EVCSH_StBatRdy = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_StDcCh_EVCSH_StDcCh = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_StInt_EVCSH_StInt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_UChrgrSp_EVCSH_UChrgrSp = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bAcvCfgCmpl_EVCSH_bAcvCfgCmpl = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bAcvChSeqEnd_EVCSH_bAcvChSeqEnd = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bAcvDcChReqFromVcu_EVCSH_bAcvDcChReqFromVcu = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bAcvDcCnctReq_EVCSH_bAcvDcCnctReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bAcvVeh2VehDcha_EVCSH_bAcvVeh2VehDcha = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaChrgn_EVCSH_bEnaChrgn = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatCfgPgtn_EVCSH_bEnaMsgBatCfgPgtn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChStPgtn_EVCSH_bEnaMsgBatChStPgtn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatPrvt_EVCSH_bEnaMsgBatPrvt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatT_EVCSH_bEnaMsgBatT = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgCellU_EVCSH_bEnaMsgCellU = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_TimeOut_CRO00_BCC_TimeOutCRO00 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_TimeOut_CROAA_BCC_TimeOutCROAA = FALSE;
VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_CMdulAbsv_BCF_CMdulAbsv = {0U};
VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv = {0U};
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ChIIntglNv_BCF_ChIIntglNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ChgDeltAhNv_BCF_ChgDeltAhNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_DeltAhNv_BCF_DeltAhNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_EPackRmng_BCF_EPackRmng = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_EnaPack_BCF_EnaPack = FALSE;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo_BCF_ErrInfo = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo1_BCF_ErrInfo1 = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo2_BCF_ErrInfo2 = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo3_BCF_ErrInfo3 = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo4_BCF_ErrInfo4 = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo5_BCF_ErrInfo5 = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo6_BCF_ErrInfo6 = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_FullChgSOHNv_BCF_FullChgSOHNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChLim_BCF_IChLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChLimInt_BCF_IChLimInt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChLimMap_BCF_IChLimMap = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChMax_BCF_IChMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChPredLim_BCF_IChPredLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChPredLimInt_BCF_IChPredLimInt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaLim_BCF_IDchaLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaLimInt_BCF_IDchaLimInt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaLimMap_BCF_IDchaLimMap = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaMax_BCF_IDchaMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaPredLim_BCF_IDchaPredLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaPredLimInt_BCF_IDchaPredLimInt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IIntglNv_BCF_IIntglNv = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_NrMdulMax_BCF_NrMdulMax = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_PwrChLim_BCF_PwrChLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_PwrChPredLim_BCF_PwrChPredLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_PwrDchaLim_BCF_PwrDchaLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_PwrDchaPredLim_BCF_PwrDchaPredLim = 0.0F;
VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_PwrMdulLoss_BCF_PwrMdulLoss = {0U};
VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv = {0U};
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_RPackInt_BCF_RPackInt = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SOHCalFulChgFlgNv_BCF_SOHCalFulChgFlgNv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SOHCalOCVFlgNv_BCF_SOHCalOCVFlgNv = FALSE;
VAR(rt_Array_Float_255, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocCell_BCF_SocCell = {0U};
VAR(rt_Array_Float_255, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocCellDelta_BCF_SocCellDelta = {0U};
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocCellMax_BCF_SocCellMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocCellMin_BCF_SocCellMin = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocCnsActNv_BCF_SocCnsActNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocLimMax_BCF_SocLimMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocLimMin_BCF_SocLimMin = 0.0F;
VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocMdul_BCF_SocMdul = {0U};
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocPack_BCF_SocPack = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocPackScld_BCF_SocPackScld = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocUOcIniNv_BCF_SocUOcIniNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohCalNv_BCF_SohCalNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohCycNv_BCF_SohCycNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohPack_BCF_SohPack = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohPackNv_BCF_SohPackNv = 0.0F;
VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv = {0U};
VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv = {0U};
VAR(rt_Array_Float_144, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_StAryFlsNv_BCF_StAryFlsNv = {0U};
VAR(rt_Array_UInt8_4, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_StLimnId_BCF_StLimnId = {0U};
VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TCooltMdulOut_BCF_TCooltMdulOut = {0U};
VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TMdulEstimd_BCF_TMdulEstimd = {0U};
VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv = {0U};
VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv = {0U};
VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TiBatOffNv_BCF_TiBatOffNv = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TiChFullOff_BCF_TiChFullOff = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UCellAvg_BCF_UCellAvg = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UChLim_BCF_UChLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UChLimInt_BCF_UChLimInt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UChPredLim_BCF_UChPredLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UChPredLimInt_BCF_UChPredLimInt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UDchaLim_BCF_UDchaLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UDchaLimInt_BCF_UDchaLimInt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UDchaPredLim_BCF_UDchaPredLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UDchaPredLimInt_BCF_UDchaPredLimInt = 0.0F;
VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UMdul_BCF_UMdul = {0U};
VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UPackCircOpen_BCF_UPackCircOpen = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_bChrgFullCalRemind_BCF_bChrgFullCalRemind = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg = FALSE;
VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls = {0U};
VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv = {0U};
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrCellU_BPIU_ErrCellU = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrCellUDif_BPIU_ErrCellUDif = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrCellUOver_BPIU_ErrCellUOver = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrIChLim_BPIU_ErrIChLim = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrIDchaLim_BPIU_ErrIDchaLim = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrIRgnOvcur_BPIU_ErrIRgnOvcur = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrInfo_BPIU_ErrInfo = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrPackSnsrI_BPIU_ErrPackSnsrI = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrUAcqn_BPIU_ErrUAcqn = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_IdCellUMax_BPIU_IdCellUMax = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_IdCellUMin_BPIU_IdCellUMin = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_IdMdulForCellUMax_BPIU_IdMdulForCellUMax = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_IdMdulForCellUMin_BPIU_IdMdulForCellUMin = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_StCellUChkOverMax_BPIU_StCellUChkOverMax = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_StCellUChkOverMin_BPIU_StCellUChkOverMin = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_StChkUMax_BPIU_StChkUMax = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_StChkUMin_BPIU_StChkUMin = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_UCellMax_BPIU_UCellMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_UCellMin_BPIU_UCellMin = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrCellT_BPP_ErrCellT = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrInfo_BPP_ErrInfo = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrPackU_BPP_ErrPackU = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrSocJmp_BPP_ErrSocJmp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrSocVal_BPP_ErrSocVal = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_IAct_BPP_IAct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_IChAct_BPP_IChAct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_IDchaAct_BPP_IDchaAct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_PwrAct_BPP_PwrAct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_SocLimMax_BPP_SocLimMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_SocLimMin_BPP_SocLimMin = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_TCellMaxLim_BPP_TCellMaxLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_TCellMinLim_BPP_TCellMinLim = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_bAcvCTest_BPP_bAcvCTest = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_ErrChEnd_BTHM_ErrChEnd = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_ErrInfo_BTHM_ErrInfo = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_IdCellTMax_BTHM_IdCellTMax = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_IdCellTMin_BTHM_IdCellTMin = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_IdMdulTMax_BTHM_IdMdulTMax = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_IdMdulTMin_BTHM_IdMdulTMin = 0U;
VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_MfCoolt_BTHM_MfCoolt = {0U};
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_ReqRePrech_BTHM_ReqRePrech = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StErrTOver_BTHM_StErrTOver = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StRlyHeatReq_BTHM_StRlyHeatReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StRlyMain_BTHM_StRlyMain = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StRlyMainNeg_BTHM_StRlyMainNeg = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StSys_BTHM_StSys = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StThermReq_BTHM_StThermReq = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TBatTgt_BTHM_TBatTgt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TBcuSnsr_BTHM_TBcuSnsr = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr = 0.0F;
VAR(rt_Array_Float_54, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulCorrn_BTHM_TMdulCorrn = {0U};
VAR(rt_Array_Float_32, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulCtlrSnsr_BTHM_TMdulCtlrSnsr = {0U};
VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulCtlrSnsrMax_BTHM_TMdulCtlrSnsrMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulCtlrSnsrMin_BTHM_TMdulCtlrSnsrMin = 0.0F;
VAR(rt_Array_Float_54, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsr_BTHM_TMdulSnsr = {0U};
VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMaxRaw_BTHM_TMdulSnsrMaxRaw = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw = 0.0F;
VAR(rt_Array_Float_54, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrRaw_BTHM_TMdulSnsrRaw = {0U};
VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TOptmMax_BTHM_TOptmMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TOptmMin_BTHM_TOptmMin = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TPack_BTHM_TPack = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_bAcvDig64_BTHM_bAcvDig64 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_bAcvDig93_BTHM_bAcvDig93 = FALSE;
VAR(rt_Array_Boolean_24, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_bAcvTAbno_BTHM_bAcvTAbno = {0U};
VAR(rt_Array_Boolean_24, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_bErrSnsrT_BTHM_bErrSnsrT = {0U};
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatChTot_BWLD_CBatChTot = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatChTotNv_BWLD_CBatChTotNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatDchaTot_BWLD_CBatDchaTot = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatDchaTotNv_BWLD_CBatDchaTotNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatRecoveryTot_BWLD_CBatRecoveryTot = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatRecoveryTotNv_BWLD_CBatRecoveryTotNv = 0.0F;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrCh_BWLD_CtrCh = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrChNv_BWLD_CtrChNv = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrDcha_BWLD_CtrDcha = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrDchaNv_BWLD_CtrDchaNv = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrMdulWrNv_BWLD_CtrMdulWrNv = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatChDrvCyc_BWLD_EBatChDrvCyc = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatChTot_BWLD_EBatChTot = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatChTotNv_BWLD_EBatChTotNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatDchaDrvCyc_BWLD_EBatDchaDrvCyc = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatDchaTot_BWLD_EBatDchaTot = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatDchaTotNv_BWLD_EBatDchaTotNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatRecoveryDrvCyc_BWLD_EBatRecoveryDrvCyc = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatRecoveryTot_BWLD_EBatRecoveryTot = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatRecoveryTotNv_BWLD_EBatRecoveryTotNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_IBatChMax_BWLD_IBatChMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_IBatChMaxNv_BWLD_IBatChMaxNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_IBatDchaMax_BWLD_IBatDchaMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_IBatDchaMaxNv_BWLD_IBatDchaMaxNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_PBatChMax_BWLD_PBatChMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_PBatChMaxNv_BWLD_PBatChMaxNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_PBatDchaMax_BWLD_PBatDchaMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_PBatDchaMaxNv_BWLD_PBatDchaMaxNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_SocBatMax_BWLD_SocBatMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_SocBatMaxNv_BWLD_SocBatMaxNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_SocBatMin_BWLD_SocBatMin = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_SocBatMinNv_BWLD_SocBatMinNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMax_BWLD_TMdulSnsrMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMaxNv_BWLD_TMdulSnsrMaxNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMin_BWLD_TMdulSnsrMin = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMinNv_BWLD_TMdulSnsrMinNv = 0.0F;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TiBatAgi_BWLD_TiBatAgi = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TiBatAgiNv_BWLD_TiBatAgiNv = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMax_BWLD_UBatCtctrClsdMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMaxNv_BWLD_UBatCtctrClsdMaxNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMin_BWLD_UBatCtctrClsdMin = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMinNv_BWLD_UBatCtctrClsdMinNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMax_BWLD_UBatCtctrOpenMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMaxNv_BWLD_UBatCtctrOpenMaxNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMin_BWLD_UBatCtctrOpenMin = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMinNv_BWLD_UBatCtctrOpenMinNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UCellMax_BWLD_UCellMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UCellMaxNv_BWLD_UCellMaxNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UCellMin_BWLD_UCellMin = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UCellMinNv_BWLD_UCellMinNv = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_DayRtcLstNv_BSTC_DayRtcLstNv = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_DelayTime_BSTC_DelayTime = 0.0F;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_ErrInfo_BSTC_ErrInfo = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_HourRtcLstNv_BSTC_HourRtcLstNv = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_MinuRtcLstNv_BSTC_MinuRtcLstNv = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_ModeBmsAcvn_BSTC_ModeBmsAcvn = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_MonthRtcLstNv_BSTC_MonthRtcLstNv = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_ReqEmcyHvOffFromBms_BSTC_ReqEmcyHvOffFromBms = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_ReqEmcyHvOffFromVcu_BSTC_ReqEmcyHvOffFromVcu = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_ReqShtdnBas_BSTC_ReqShtdnBas = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_RstCmd_BSTC_RstCmd = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_RstCmd100_BSTC_RstCmd100 = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_SecRtcLstNv_BSTC_SecRtcLstNv = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBcuInt_BSTC_StBcuInt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBmsChk_BSTC_StBmsChk = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_TiBatOff_BSTC_TiBatOff = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_TiBatOn_BSTC_TiBatOn = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_TrigCh_BSTC_TrigCh = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_YearRtcLstNv_BSTC_YearRtcLstNv = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvCutoffLvFromBms_BSTC_bAcvCutoffLvFromBms = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvDcStChToStHvOffNorm_BSTC_bAcvDcStChToStHvOffNorm = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvHvOffNormFromVcu_BSTC_bAcvHvOffNormFromVcu = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvObcOff_BSTC_bAcvObcOff = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvStDchaToStHvOffNorm_BSTC_bAcvStDchaToStHvOffNorm = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvStRunToStHvOffEmcy_BSTC_bAcvStRunToStHvOffEmcy = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvStStbToStAftRun_BSTC_bAcvStStbToStAftRun = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bErrHvOffAbno_BSTC_bErrHvOffAbno = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bErrPwrOff_BSTC_bErrPwrOff = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bErrToutForRxCutoffLvReq_BSTC_bErrToutForRxCutoffLvReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bErrToutForRxHvOffReq_BSTC_bErrToutForRxHvOffReq = FALSE;
VAR(rt_Array_Float_255, RTE_VAR_INIT) Rte_swc_CIL_BMC_UCell_BMC_UCell = {0U};
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_AcvChManSuspd_BSOF_AcvChManSuspd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_AcvChSuspdByBms_BSOF_AcvChSuspdByBms = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_AcvChSuspdCdnRchd_BSOF_AcvChSuspdCdnRchd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_AcvChSuspdFlt_BSOF_AcvChSuspdFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ChAllwd_BSOF_ChAllwd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_DirChAndDcha_BSOF_DirChAndDcha = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_EChSng_BSOF_EChSng = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChImpo_BSOF_ErrChImpo = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrIDe_BSOF_ErrIDe = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrUAbno_BSOF_ErrUAbno = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrUndfnd_BSOF_ErrUndfnd = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_IChrgr_BSOF_IChrgr = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_IChrgrMax_BSOF_IChrgrMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_IChrgrMin_BSOF_IChrgrMin = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_IDchaMax_BSOF_IDchaMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_IDchaMin_BSOF_IDchaMin = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_MsgChrgrRcgtn_BSOF_MsgChrgrRcgtn = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_MsgChrgrRdy_BSOF_MsgChrgrRdy = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_NrChrgrComVers_BSOF_NrChrgrComVers = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_SocDchaMax_BSOF_SocDchaMax = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_SocDchaMin_BSOF_SocDchaMin = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_BSOF_TiChAccumd_BSOF_TiChAccumd = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UChrgr_BSOF_UChrgr = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UChrgrMax_BSOF_UChrgrMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UChrgrMin_BSOF_UChrgrMin = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UDchaMax_BSOF_UDchaMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UDchaMin_BSOF_UDchaMin = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ValDcChrgrPlgOr_BSOF_ValDcChrgrPlgOr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrChDetd_BSOF_bEnaMsgChrgrChDetd = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrChSt_BSOF_bEnaMsgChrgrChSt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrChSuspd_BSOF_bEnaMsgChrgrChSuspd = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrDetnCnct_BSOF_bEnaMsgChrgrDetnCnct = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrErr_BSOF_bEnaMsgChrgrErr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrHdshk_BSOF_bEnaMsgChrgrHdshk = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrMaxOut_BSOF_bEnaMsgChrgrMaxOut = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrMaxOutPgtn_BSOF_bEnaMsgChrgrMaxOutPgtn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrRcgtn_BSOF_bEnaMsgChrgrRcgtn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrRdy_BSOF_bEnaMsgChrgrRdy = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrStstc_BSOF_bEnaMsgChrgrStstc = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrStstcForPgtn_BSOF_bEnaMsgChrgrStstcForPgtn = FALSE;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bErrMsgTout_BSOF_bErrMsgTout = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_ActInputVolt_CIL_ActInputVolt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_BMSH_StsModeReq_CIL_BMSH_StsModeReq = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_BatCoolType_CIL_BatCoolType = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_CP_Vol_CIL_CP_Vol = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_CfgLvl2_CIL_CfgLvl2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ChargeDepthReq_CIL_ChargeDepthReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ChgCCSts_CIL_ChgCCSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ChrgSoftSwCtrlSt_CIL_ChrgSoftSwCtrlSt = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_CtrIslnRSamplg_CIL_CtrIslnRSamplg = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_DayRtc_CIL_DayRtc = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_DayTelbox_CIL_DayTelbox = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_DoorLockStatusDrv_CIL_DoorLockStatusDrv = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_DoorLockStatusPass_CIL_DoorLockStatusPass = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_DucycCrash_CIL_DucycCrash = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_DucycCtlPilot_CIL_DucycCtlPilot = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_DucycHvil_CIL_DucycHvil = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_ElectroniclockVolt_CIL_ElectroniclockVolt = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ElockStmodeOBC_CIL_ElockStmodeOBC = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ErrAcScktSnsrT_CIL_ErrAcScktSnsrT = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ErrDcScktSnsrT_CIL_ErrDcScktSnsrT = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_ErrInfoBSW_CIL_ErrInfoBSW = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_FrqCrash_CIL_FrqCrash = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_FrqHvil_CIL_FrqHvil = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_HWVerVeh_CIL_HWVerVeh = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_HourRtc_CIL_HourRtc = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_HourTelbox_CIL_HourTelbox = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IBatHvRaw_CIL_IBatHvRaw = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_IDcdcLvAct_CIL_IDcdcLvAct = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IEACAct_CIL_IEACAct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IObcChOutp_CIL_IObcChOutp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_MilgTot_CIL_MilgTot = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_MinuRtc_CIL_MinuRtc = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_MinuTelbox_CIL_MinuTelbox = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ModeMotDrv_CIL_ModeMotDrv = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ModeSysWup_CIL_ModeSysWup = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_MonthRtc_CIL_MonthRtc = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_MonthTelbox_CIL_MonthTelbox = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_OnBdCPline_CIL_OnBdCPline = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_PowerMode_CIL_PowerMode = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_PwrEACAct_CIL_PwrEACAct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_PwrPtcAct_CIL_PwrPtcAct = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_RAcChCnctn_CIL_RAcChCnctn = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_RAcChCnctnResRaw_CIL_RAcChCnctnResRaw = 0U;
VAR(SInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_RDcChrgrPlg_CIL_RDcChrgrPlg = 0;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_RDisChCnctn_CIL_RDisChCnctn = 0U;
VAR(SInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_RIslnNeg_CIL_RIslnNeg = 0;
VAR(SInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_RIslnPos_CIL_RIslnPos = 0;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ReservationChrgnSts_CIL_ReservationChrgnSts = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_RngElec_CIL_RngElec = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_SWVerVeh_CIL_SWVerVeh = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_SecRtc_CIL_SecRtc = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_SecTelbox_CIL_SecTelbox = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_SpdMot_CIL_SpdMot = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_SpdVeh_CIL_SpdVeh = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StAcChCnct_CIL_StAcChCnct = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StBatHvReq_CIL_StBatHvReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StBatLvCutoffReq_CIL_StBatLvCutoffReq = 0U;
VAR(rt_Array_UInt8_54, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCellT_CIL_StCellT = {0U};
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCellTSamplgExcpn_CIL_StCellTSamplgExcpn = 0U;
VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul = {0U};
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCellUSamplgExcpn_CIL_StCellUSamplgExcpn = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StChAllwd_CIL_StChAllwd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StChWup_CIL_StChWup = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCrash_CIL_StCrash = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StMsgToutForObc_CIL_StMsgToutForObc = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StMsgToutForPMS_CIL_StMsgToutForPMS = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StObc_CIL_StObc = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StProj_CIL_StProj = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StPtIndcr_CIL_StPtIndcr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StPtcW_CIL_StPtcW = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StRtcFlt_CIL_StRtcFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StTrml15_CIL_StTrml15 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StsElectroniclockContor_CIL_StsElectroniclockContor = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TAcChPointNeg_CIL_TAcChPointNeg = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TAcChPointPos_CIL_TAcChPointPos = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TBd_CIL_TBd = 0.0F;
VAR(rt_Array_Float_32, RTE_VAR_INIT) Rte_swc_CIL_CIL_TBdSnsr_CIL_TBdSnsr = {0U};
VAR(SInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr = 0;
VAR(SInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr = 0;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TDcChPointNeg_CIL_TDcChPointNeg = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TDcChPointPos_CIL_TDcChPointPos = 0.0F;
VAR(rt_Array_Float_54, RTE_VAR_INIT) Rte_swc_CIL_CIL_TMdul_CIL_TMdul = {0U};
VAR(rt_Array_Float_32, RTE_VAR_INIT) Rte_swc_CIL_CIL_TMdulCtlr_CIL_TMdulCtlr = {0U};
VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_CIL_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE = {0U};
VAR(SInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_TSnsrI_CIL_TSnsrI = 0;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_TiSysRun_CIL_TiSysRun = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UChPoleLowSideDrv_CIL_UChPoleLowSideDrv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UDcdcLvAct_CIL_UDcdcLvAct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UEACAct_CIL_UEACAct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainNegPoleAftRly_CIL_UMainNegPoleAftRly = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainNegPoleLowSideDrv_CIL_UMainNegPoleLowSideDrv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleLowSideDrv_CIL_UMainPosPoleLowSideDrv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UNegChPoleHiSideDrv_CIL_UNegChPoleHiSideDrv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UNegChPoleLowSideDrv_CIL_UNegChPoleLowSideDrv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UObcChInp_CIL_UObcChInp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UObcChOutp_CIL_UObcChOutp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UPoleAftRlyChNeg_CIL_UPoleAftRlyChNeg = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UTrml30_CIL_UTrml30 = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_VehicleSpeedInvalid_CIL_VehicleSpeedInvalid = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_YearRtc_CIL_YearRtc = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_YearTelbox_CIL_YearTelbox = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_ZeroPwrFb_CIL_ZeroPwrFb = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bAcvRstDiag_CIL_bAcvRstDiag = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bCANWakeUp_CIL_bCANWakeUp = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bDCDCW_CIL_bDCDCW = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bErrCtrBatIHv_CIL_bErrCtrBatIHv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bErrCtrBatUHv_CIL_bErrCtrBatUHv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bKCNegClsSts_CIL_bKCNegClsSts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bMainNegClsSts_CIL_bMainNegClsSts = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bRdyBswStoreFnshd_CIL_bRdyBswStoreFnshd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldBatIHv_CIL_bVldBatIHv = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldIslnR_CIL_bVldIslnR = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUMainNegPoleAftRly_CIL_bVldUMainNegPoleAftRly = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUMainPosPoleAftRly_CIL_bVldUMainPosPoleAftRly = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUPoleAftRlyCh_CIL_bVldUPoleAftRlyCh = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUPoleAftRlyHeat_CIL_bVldUPoleAftRlyHeat = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_ClL_InletWaterTemp_ClL_InletWaterTemp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_ClL_OutletWaterTemp_ClL_OutletWaterTemp = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrAFETot_MCC_NrAFETot = 0U;
VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrCellByMdul_MCC_NrCellByMdul = {0U};
VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrCellTot_MCC_NrCellTot = 0U;
VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul = {0U};
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrMdulTot_MCC_NrMdulTot = 0U;
VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul = {0U};
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrSnsrTTot_MCC_NrSnsrTTot = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_StMdulCu_MCC_StMdulCu = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_B2V_SingleChgEnergy_B2V_SingleChgEnergy = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCSP_Remaining_range_BCSP_Remaining_range = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BCSP_reserved_BCSP_reserved = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BDC_Battery_capacity_BDC_Battery_capacity = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BDC_Battery_energy_BDC_Battery_energy = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Soc_BDC_Soc = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9 = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CRO00_BMSH_DCChgRx_OTime_CRO00 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CROAA_BMSH_DCChgRx_OTime_CROAA = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BMSStopChgReason_BMS_BMSStopChgReason = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CCUStopChgReason_BMS_CCUStopChgReason = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BSWControl_RstDiagGlb_RstDiagGlb = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Mode_Request_shutdown_Request_shutdown = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCL_Request_BCL = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCP_Request_BCP = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCPP_Request_BCPP = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCS_Request_BCS = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCSP_Request_BCSP = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BDC_Request_BDC = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BEM_Request_BEM = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BHM_Request_BHM = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BMS_FastChgStopInfo_Request_BMS_FastChgStopInfo = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BMT_Request_BMT = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BMV_Request_BMV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BRM_Request_BRM = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BRO_Request_BRO = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BSD_Request_BSD = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BSM_Request_BSM = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BSP_Request_BSP = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BST_Request_BST = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryChargingOvercurrent_BatteryChargingOvercurrent = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryExcessTemperature_BatteryExcessTemperature = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryHighestTemp_BatteryHighestTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryHighestTempSerNo_BatteryHighestTempSerNo = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryInsulationState_BatteryInsulationState = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryLowestTemp_BatteryLowestTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryLowestTempSerNo_BatteryLowestTempSerNo = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryOutputConnectorState_BatteryOutputConnectorState = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BatterySystemCapacity_BatterySystemCapacity = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BatterySystemVoltage_BatterySystemVoltage = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryType_BatteryType = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsReadyForCharging_BmsReadyForCharging = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsRevision_BmsRevision = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspCause_SOC_BmsSuspCause_SOC = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_Insulation_BmsSuspFault_Insulation = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BmsVersion_BmsVersion = 0U;
VAR(rt_Array_UInt32_9, RTE_VAR_INIT) Rte_swc_COL_BmuControl_BalanceControl_BalanceControl = {0U};
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BsmChargingPermissible_BsmChargingPermissible = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_ChargingMode_ChargingMode = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_CurrentChargeState_CurrentChargeState = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_CurrentDemand_CurrentDemand = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_IOFS_NegRlyCtr_IOFS_NegRlyCtr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_IOFS_PosRlyCtr_IOFS_PosRlyCtr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_IOFS_PreChgRlyCtr_IOFS_PreChgRlyCtr = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MaxChargingVoltage_MaxChargingVoltage = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MaxPermChargingCurrent_MaxPermChargingCurrent = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_MaxPermTemperature_MaxPermTemperature = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MeasuredChargingCurrent_MeasuredChargingCurrent = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MeasuredChargingVoltage_MeasuredChargingVoltage = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryMinTemperature_SingleBatteryMinTemperature = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryMinVoltage_SingleBatteryMinVoltage = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CCS_Timeout_CCS = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CRM_Recognized_Timeout_CRM_Recognized = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CRO_Timeout_CRO = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CSD_Timeout_CSD = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CST_Timeout_CST = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CTS_CML_Timeout_CTS_CML = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_TotalNominalEnergy_TotalNominalEnergy = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_1_VIN_Copy_1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_10_VIN_Copy_10 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_11_VIN_Copy_11 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_12_VIN_Copy_12 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_13_VIN_Copy_13 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_14_VIN_Copy_14 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_15_VIN_Copy_15 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_16_VIN_Copy_16 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_17_VIN_Copy_17 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_2_VIN_Copy_2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_3_VIN_Copy_3 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_4_VIN_Copy_4 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_5_VIN_Copy_5 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_6_VIN_Copy_6 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_7_VIN_Copy_7 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_8_VIN_Copy_8 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_9_VIN_Copy_9 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_VoltageDemand_VoltageDemand = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv = 0.0F;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrInfo_CTC_ErrInfo = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyCh_CTC_ErrRlyCh = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyHeat_CTC_ErrRlyHeat = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyNeg_CTC_ErrRlyNeg = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyPos_CTC_ErrRlyPos = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyPrech_CTC_ErrRlyPrech = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_IDriftZero_CTC_IDriftZero = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiCh_CTC_PctgCtctrAgiCh = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiHeat_CTC_PctgCtctrAgiHeat = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiNeg_CTC_PctgCtctrAgiNeg = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiPos_CTC_PctgCtctrAgiPos = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiPrech_CTC_PctgCtctrAgiPrech = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyCh_CTC_ReqRlyCh = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyChNeg_CTC_ReqRlyChNeg = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyHeat_CTC_ReqRlyHeat = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyNeg_CTC_ReqRlyNeg = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyPos_CTC_ReqRlyPos = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyPrech_CTC_ReqRlyPrech = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqZeroPwr_CTC_ReqZeroPwr = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyCh_CTC_StRlyCh = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyChNeg_CTC_StRlyChNeg = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyChkCh_CTC_StRlyChkCh = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyChkHeat_CTC_StRlyChkHeat = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyChkPos_CTC_StRlyChkPos = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyHeat_CTC_StRlyHeat = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyNeg_CTC_StRlyNeg = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyPos_CTC_StRlyPos = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyPrech_CTC_StRlyPrech = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StSysInt_CTC_StSysInt = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_UPrechAccumdNv_CTC_UPrechAccumdNv = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bAcvBswCtl_CTC_bAcvBswCtl = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bAcvCh_CTC_bAcvCh = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bAcvRePrechFnshd_CTC_bAcvRePrechFnshd = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bAcvTrml15Chk_CTC_bAcvTrml15Chk = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiCh_CTC_bErrRlyAgiCh = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiHeat_CTC_bErrRlyAgiHeat = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiNeg_CTC_bErrRlyAgiNeg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiPos_CTC_bErrRlyAgiPos = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiPrech_CTC_bErrRlyAgiPrech = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bErrToutForMotDcha_CTC_bErrToutForMotDcha = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiCh_CTC_bWarnRlyAgiCh = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiHeat_CTC_bWarnRlyAgiHeat = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiNeg_CTC_bWarnRlyAgiNeg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiPos_CTC_bWarnRlyAgiPos = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiPrech_CTC_bWarnRlyAgiPrech = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_BatMfctrType_DEH_BatMfctrType = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_BatMfctrr_DEH_BatMfctrr = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CBatNom_DEH_CBatNom = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ChgLvlErr_DEH_ChgLvlErr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrBalCtlDiag_DEH_CtrBalCtlDiag = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrErrCfmdNv_DEH_CtrErrCfmdNv = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrFctInhDeacStopDiag_DEH_CtrFctInhDeacStopDiag = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrFctInhDeacStrtDiag_DEH_CtrFctInhDeacStrtDiag = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrHvOffReqDiag_DEH_CtrHvOffReqDiag = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrIslnMeasReqDiag_DEH_CtrIslnMeasReqDiag = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrPackSocSetDiag_DEH_CtrPackSocSetDiag = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrRlyReqDiag_DEH_CtrRlyReqDiag = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrRlyWlddErrRstDiag_DEH_CtrRlyWlddErrRstDiag = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_DayBatMfctr_DEH_DayBatMfctr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_DelayDataUpldEnb_DEH_DelayDataUpldEnb = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_DischgLvlErr_DEH_DischgLvlErr = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb = FALSE;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1 = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd2_DEH_ErrCfmd2 = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3 = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd4_DEH_ErrCfmd4 = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd5_DEH_ErrCfmd5 = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd6_DEH_ErrCfmd6 = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrHisCfmd_DEH_ErrHisCfmd = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrRlyCtlDiag_DEH_ErrRlyCtlDiag = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_IdxCellBalCtl_DEH_IdxCellBalCtl = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_LvlErr_DEH_LvlErr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_LvlErrSb_DEH_LvlErrSb = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ModBalCtl_DEH_ModBalCtl = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_MonthBatMfctr_DEH_MonthBatMfctr = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrPackSerl_DEH_NrPackSerl = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin1_DEH_NrVin1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin10_DEH_NrVin10 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin11_DEH_NrVin11 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin12_DEH_NrVin12 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin13_DEH_NrVin13 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin14_DEH_NrVin14 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin15_DEH_NrVin15 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin16_DEH_NrVin16 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin17_DEH_NrVin17 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin2_DEH_NrVin2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin3_DEH_NrVin3 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin4_DEH_NrVin4 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin5_DEH_NrVin5 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin6_DEH_NrVin6 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin7_DEH_NrVin7 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin8_DEH_NrVin8 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin9_DEH_NrVin9 = 0U;
VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_PackCode_DEH_PackCode = {0U};
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqBalCtl_DEH_ReqBalCtl = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqRlyCh_DEH_ReqRlyCh = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqRlyNeg_DEH_ReqRlyNeg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqRlyPos_DEH_ReqRlyPos = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqRlyPrech_DEH_ReqRlyPrech = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_StFltLampIndcn_DEH_StFltLampIndcn = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_StIslnMeasReq_DEH_StIslnMeasReq = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_StSocCal_DEH_StSocCal = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_StsIninNv_DEH_StsIninNv = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_TiChFullOff_DEH_TiChFullOff = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_UBatNom_DEH_UBatNom = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_VCU_ChgFaultReq_DEH_VCU_ChgFaultReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_VCU_DischgFaultReq_DEH_VCU_DischgFaultReq = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ValCodDiag_DEH_ValCodDiag = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ValPackSoc_DEH_ValPackSoc = 0.0F;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_YearBatMfctr_DEH_YearBatMfctr = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvAcChInh_DEH_bAcvAcChInh = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvAcPwrChInh_DEH_bAcvAcPwrChInh = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvBdNew_DEH_bAcvBdNew = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvChInh_DEH_bAcvChInh = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvDcChInh_DEH_bAcvDcChInh = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvDcPwrChInh_DEH_bAcvDcPwrChInh = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvDchaInh_DEH_bAcvDchaInh = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvEmcyHvOff1_DEH_bAcvEmcyHvOff1 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvEmcyHvOff2_DEH_bAcvEmcyHvOff2 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvHeatInh_DEH_bAcvHeatInh = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvLvlErrSb1_DEH_bAcvLvlErrSb1 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvLvlErrSb2_DEH_bAcvLvlErrSb2 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvLvlErrSb3_DEH_bAcvLvlErrSb3 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPowupInh_DEH_bAcvPowupInh = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrDchaLim1_DEH_bAcvPwrDchaLim1 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrDchaLim2_DEH_bAcvPwrDchaLim2 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrRecupLim1_DEH_bAcvPwrRecupLim1 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrRecupLim2_DEH_bAcvPwrRecupLim2 = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrdNorm_DEH_bAcvPwrdNorm = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvRecupInh_DEH_bAcvRecupInh = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvSleepNorm_DEH_bAcvSleepNorm = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CBatChTot_NVM_CBatChTot = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CBatDchaTot_NVM_CBatDchaTot = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot = 0.0F;
VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls = {0U};
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_ChIIntglFls_NVM_ChIIntglFls = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_ChgDeltAh_NVM_ChgDeltAh = 0.0F;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCh_NVM_CtrCh = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech = 0.0F;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrDcha_NVM_CtrDcha = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_DayRtcLst_NVM_DayRtcLst = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_DeltAh_NVM_DeltAh = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_EBatChTot_NVM_EBatChTot = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_EBatDchaTot_NVM_EBatDchaTot = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_FullChgSOH_NVM_FullChgSOH = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_HourRtcLst_NVM_HourRtcLst = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_IBatChMax_NVM_IBatChMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_IBatDchaMax_NVM_IBatDchaMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_IIntglFls_NVM_IIntglFls = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_MinuRtcLst_NVM_MinuRtcLst = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_MonthRtcLst_NVM_MonthRtcLst = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_PBatChMax_NVM_PBatChMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_PBatDchaMax_NVM_PBatDchaMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_RIslnNeg_NVM_RIslnNeg = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_RIslnPos_NVM_RIslnPos = 0.0F;
VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls = {0U};
VAR(rt_Array_UInt8_255, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln = {0U};
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SecRtcLst_NVM_SecRtcLst = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocBatMax_NVM_SocBatMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocBatMin_NVM_SocBatMin = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocCnsAct_NVM_SocCnsAct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocPackScld_NVM_SocPackScld = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocUOcIni_NVM_SocUOcIni = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohCalFls_NVM_SohCalFls = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohCycFls_NVM_SohCycFls = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohPackFls_NVM_SohPackFls = 0.0F;
VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohRDeltaFls_NVM_SohRDeltaFls = {0U};
VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls = {0U};
VAR(rt_Array_Float_144, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_StAryFls_NVM_StAryFls = {0U};
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TPackFls_NVM_TPackFls = 0.0F;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TiBatAgi_NVM_TiBatAgi = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TiBatOffFls_NVM_TiBatOffFls = 0U;
VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls = {0U};
VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls = {0U};
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UCellMax_NVM_UCellMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UCellMin_NVM_UCellMin = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UPrechAccumd_NVM_UPrechAccumd = 0.0F;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_YearRtcLst_NVM_YearRtcLst = 0U;
VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls = {0U};
VAR(UInt16, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_ErrInfo_ELHPN_ErrInfo = 0U;
VAR(Float, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnNeg_ELHPN_RIslnNeg = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnNegNv_ELHPN_RIslnNegNv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnPos_ELHPN_RIslnPos = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnPosNv_ELHPN_RIslnPosNv = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StCrash_ELHPN_StCrash = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StCrashIni_ELHPN_StCrashIni = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrIniHvIntlc2_ELHPN_StErrIniHvIntlc2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StIsln_ELHPN_StIsln = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StIslnErr_ELHPN_StIslnErr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StVehIsln_ELHPN_StVehIsln = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_bInhIslnMeas_ELHPN_bInhIslnMeas = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_ACTemp_ErrFLg_ACTemp_ErrFLg = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_BMUTempOver_ErrFLg_BMUTempOver_ErrFLg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_BalnCtlModl_ErrFLg_BalnCtlModl_ErrFLg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_BattIsoDet_ErrFLg_BattIsoDet_ErrFLg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_CellVoltSampleDiscon_ErrFLg_CellVoltSampleDiscon_ErrFLg = FALSE;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CCD_UpdataTime_CCD_UpdataTime = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CCS_UpdataTime_CCS_UpdataTime = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CDC_UpdataTime_CDC_UpdataTime = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CEM_UpdataTime_CEM_UpdataTime = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CHM_UpdataTime_CHM_UpdataTime = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CMLP_UpdataTime_CMLP_UpdataTime = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CML_UpdataTime_CML_UpdataTime = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CRM_UpdataTime_CRM_UpdataTime = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CRO_UpdataTime_CRO_UpdataTime = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CSDP_UpdataTime_CSDP_UpdataTime = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CSD_UpdataTime_CSD_UpdataTime = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CST_UpdataTime_CST_UpdataTime = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_OBC_Sts_Timeout_OBC_Sts_Timeout = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_DCTemp_ErrFLg_DCTemp_ErrFLg = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_EVCANBusOff_ErrFLg_EVCANBusOff_ErrFLg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_HCMCom_ErrFLg_HCMCom_ErrFLg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_IntCANE2E_ErrFLg_IntCANE2E_ErrFLg = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_NvM_Save_Ok_NvM_Save_Ok = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_RlyKCVoltSample_ErrFLg_RlyKCVoltSample_ErrFLg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_RlyKMVoltSample_ErrFLg_RlyKMVoltSample_ErrFLg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_RlyKNVoltSample_ErrFLg_RlyKNVoltSample_ErrFLg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_STHW_ErrFLg_STHW_ErrFLg = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Service0x14_Count_Service0x14_Count = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_StsElectroniclockContor_StsElectroniclockContor = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_VCUCom_ErrFLg_VCUCom_ErrFLg = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_WeakUpFlg_WeakUpFlg = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_bCANWakeUp_bCANWakeUp = FALSE;
VAR(rt_Array_UInt16_130, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_BMUCell_BMUCell = {0U};
VAR(rt_Array_UInt32_4, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_BMUCellVSt_BMUCellVSt = {0U};
VAR(rt_Array_SInt16_8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_BMUChipTemp_BMUChipTemp = {0U};
VAR(rt_Array_SInt16_32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_BMUTemp_BMUTemp = {0U};
VAR(rt_Array_UInt8_32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_BMUTempSt_BMUTempSt = {0U};
VAR(rt_Array_SInt16_8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_BalanceTemp_BalanceTemp = {0U};
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_CellTEffective_CellTEffective = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_CellTempException_CellTempException = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_CellVEffective_CellVEffective = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_CellVoltException_CellVoltException = 0U;
VAR(SInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_RelayKHVoltage_RelayKHVoltage = 0;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_RelayKNClsSts_U8_RelayKNClsSts_U8 = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleCountCurrent_U16_SampleCountCurrent_U16 = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleCountTotalVol_U16_SampleCountTotalVol_U16 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidBat_U8_SampleValidBat_U8 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidCurrent_U8_SampleValidCurrent_U8 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidIsolation_U8_SampleValidIsolation_U8 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidKC_U8_SampleValidKC_U8 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidKH_U8_SampleValidKH_U8 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidKM_U8_SampleValidKM_U8 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidKN_U8_SampleValidKN_U8 = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_NowSystemTick_NowSystemTick = 0U;
VAR(SInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_RTCStateFault_RTCStateFault = 0;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_ReadDay_ReadDay = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_ReadHour_ReadHour = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_ReadMinute_ReadMinute = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_ReadMonth_ReadMonth = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_ReadSecond_ReadSecond = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_ReadYear_ReadYear = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCSP_Remaining_range_BCSP_Remaining_range = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCSP_reserved_BCSP_reserved = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Battery_capacity_BDC_Battery_capacity = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Battery_energy_BDC_Battery_energy = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Soc_BDC_Soc = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BRM_BmsRevision_BmsRevision = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BRM_BmsVersion_BmsVersion = 0U;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"


/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
VAR(Rte_ts_App1_Task_100ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_100ms_Core2_QM;
VAR(Rte_ts_App1_Task_10ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_10ms_Core2_QM;
VAR(Rte_ts_SWC_Init_Task_Core2, RTE_VAR_NOINIT) Rte_SWC_Init_Task_Core2;
VAR(Rte_ts_App1_Task_50ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_50ms_Core2_QM;
VAR(Rte_ts_App1_Task_1000ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_1000ms_Core2_QM;
VAR(Rte_ts_App1_Task1_UDS_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task1_UDS_Core2_QM;
VAR(Rte_ts_App1_Task0_UDS_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task0_UDS_Core2_QM;
VAR(Rte_ts_App1_Task2_UDS_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task2_UDS_Core2_QM;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
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

#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
VAR(Rte_App1_Application_Core2_QM_TxUpdateFlagsType, RTE_VAR_INIT_NOCACHE) Rte_App1_Application_Core2_QM_TxUpdateFlags = {
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
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

#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
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
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
#include "Rte_MemMap.h"

VAR(rt_Array_UInt8_4, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05D5_Ram;
VAR(rt_Array_UInt8_4, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05D6_Ram;
VAR(rt_Array_UInt8_3, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05D7_Ram;
VAR(rt_Array_UInt8_2, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05D8_Ram;
VAR(UInt8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05D9_Ram;
VAR(UInt8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05DA_Ram;
VAR(rt_Array_UInt8_24, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05DB_Ram;
VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App1;
VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App2;
VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App3;
VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App4;
VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App5;
VAR(rt_Array_UInt8_17, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_F190_Ram;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
#include "Rte_MemMap.h"


/*
************************************************************************************************************************
*    Definition of Buffers for inter-runnable variables
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"

VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_CtrErrCfmdNv = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_CtrFctInhDeacStopDiag = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_CtrFctInhDeacStrtDiag = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_CtrRlyReqDiagCh = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_CtrRlyReqDiagNeg = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_CtrRlyReqDiagPos = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_CtrRlyReqDiagPrech = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd1 = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd2 = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd3 = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd4 = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd5 = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd6 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_LvlErr = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ReqRlyCh = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ReqRlyNeg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ReqRlyPos = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ReqRlyPrech = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_StsIninNv = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_bAcvBdNew = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_NVM_CtrErrCfmd = 0U;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"


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
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_BatChCtl_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_BatChCtl_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_ACTemp_ErrFLg_ACTemp_ErrFLg(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_ACTemp_ErrFLg_ACTemp_ErrFLg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_BMUTempOver_ErrFLg_BMUTempOver_ErrFLg(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_BMUTempOver_ErrFLg_BMUTempOver_ErrFLg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_BalnCtlModl_ErrFLg_BalnCtlModl_ErrFLg(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_BalnCtlModl_ErrFLg_BalnCtlModl_ErrFLg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_BattIsoDet_ErrFLg_BattIsoDet_ErrFLg(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_BattIsoDet_ErrFLg_BattIsoDet_ErrFLg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_CellVoltSampleDiscon_ErrFLg_CellVoltSampleDiscon_ErrFLg(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_CellVoltSampleDiscon_ErrFLg_CellVoltSampleDiscon_ErrFLg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CCD_UpdataTime_CCD_UpdataTime(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_Com_CCD_UpdataTime_CCD_UpdataTime = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CCS_UpdataTime_CCS_UpdataTime(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_Com_CCS_UpdataTime_CCS_UpdataTime = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CDC_UpdataTime_CDC_UpdataTime(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_Com_CDC_UpdataTime_CDC_UpdataTime = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CEM_UpdataTime_CEM_UpdataTime(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_Com_CEM_UpdataTime_CEM_UpdataTime = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CHM_UpdataTime_CHM_UpdataTime(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_Com_CHM_UpdataTime_CHM_UpdataTime = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CMLP_UpdataTime_CMLP_UpdataTime(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_Com_CMLP_UpdataTime_CMLP_UpdataTime = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CML_UpdataTime_CML_UpdataTime(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_Com_CML_UpdataTime_CML_UpdataTime = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CRM_UpdataTime_CRM_UpdataTime(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_Com_CRM_UpdataTime_CRM_UpdataTime = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CRO_UpdataTime_CRO_UpdataTime(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_Com_CRO_UpdataTime_CRO_UpdataTime = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CSDP_UpdataTime_CSDP_UpdataTime(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_Com_CSDP_UpdataTime_CSDP_UpdataTime = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CSD_UpdataTime_CSD_UpdataTime(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_Com_CSD_UpdataTime_CSD_UpdataTime = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CST_UpdataTime_CST_UpdataTime(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_Com_CST_UpdataTime_CST_UpdataTime = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_OBC_Sts_Timeout_OBC_Sts_Timeout(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_Com_OBC_Sts_Timeout_OBC_Sts_Timeout = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_DCTemp_ErrFLg_DCTemp_ErrFLg(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_DCTemp_ErrFLg_DCTemp_ErrFLg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_EVCANBusOff_ErrFLg_EVCANBusOff_ErrFLg(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_EVCANBusOff_ErrFLg_EVCANBusOff_ErrFLg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_HCMCom_ErrFLg_HCMCom_ErrFLg(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_HCMCom_ErrFLg_HCMCom_ErrFLg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_IntCANE2E_ErrFLg_IntCANE2E_ErrFLg(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_IntCANE2E_ErrFLg_IntCANE2E_ErrFLg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_NvM_Save_Ok_NvM_Save_Ok(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_NvM_Save_Ok_NvM_Save_Ok = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_RlyKCVoltSample_ErrFLg_RlyKCVoltSample_ErrFLg(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_RlyKCVoltSample_ErrFLg_RlyKCVoltSample_ErrFLg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_RlyKMVoltSample_ErrFLg_RlyKMVoltSample_ErrFLg(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_RlyKMVoltSample_ErrFLg_RlyKMVoltSample_ErrFLg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_RlyKNVoltSample_ErrFLg_RlyKNVoltSample_ErrFLg(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_RlyKNVoltSample_ErrFLg_RlyKNVoltSample_ErrFLg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_STHW_ErrFLg_STHW_ErrFLg(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_STHW_ErrFLg_STHW_ErrFLg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Service0x14_Count_Service0x14_Count(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_Service0x14_Count_Service0x14_Count = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_StsElectroniclockContor_StsElectroniclockContor(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_StsElectroniclockContor_StsElectroniclockContor = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_VCUCom_ErrFLg_VCUCom_ErrFLg(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_VCUCom_ErrFLg_VCUCom_ErrFLg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_WeakUpFlg_WeakUpFlg(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_WeakUpFlg_WeakUpFlg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_bCANWakeUp_bCANWakeUp(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BSWIOSP_bCANWakeUp_bCANWakeUp = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_BMUCell_BMUCell(P2CONST(uint16, AUTOMATIC, RTE_swc_SetInputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MemCpy32((uint8*)(Rte_swc_SetInputInterface_BmuSample_BMUCell_BMUCell), (uint8*)(data), sizeof(rt_Array_UInt16_130));

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_BMUCellVSt_BMUCellVSt(P2CONST(uint32, AUTOMATIC, RTE_swc_SetInputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MemCpy32((uint8*)(Rte_swc_SetInputInterface_BmuSample_BMUCellVSt_BMUCellVSt), (uint8*)(data), sizeof(rt_Array_UInt32_4));

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_BMUChipTemp_BMUChipTemp(P2CONST(sint16, AUTOMATIC, RTE_swc_SetInputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MemCpy32((uint8*)(Rte_swc_SetInputInterface_BmuSample_BMUChipTemp_BMUChipTemp), (uint8*)(data), sizeof(rt_Array_SInt16_8));

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_BMUTemp_BMUTemp(P2CONST(sint16, AUTOMATIC, RTE_swc_SetInputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MemCpy32((uint8*)(Rte_swc_SetInputInterface_BmuSample_BMUTemp_BMUTemp), (uint8*)(data), sizeof(rt_Array_SInt16_32));

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_BMUTempSt_BMUTempSt(P2CONST(uint8, AUTOMATIC, RTE_swc_SetInputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MemCpy32((uint8*)(Rte_swc_SetInputInterface_BmuSample_BMUTempSt_BMUTempSt), (uint8*)(data), sizeof(rt_Array_UInt8_32));

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_BalanceTemp_BalanceTemp(P2CONST(sint16, AUTOMATIC, RTE_swc_SetInputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MemCpy32((uint8*)(Rte_swc_SetInputInterface_BmuSample_BalanceTemp_BalanceTemp), (uint8*)(data), sizeof(rt_Array_SInt16_8));

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_CellTEffective_CellTEffective(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BmuSample_CellTEffective_CellTEffective = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_CellTempException_CellTempException(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BmuSample_CellTempException_CellTempException = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_CellVEffective_CellVEffective(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BmuSample_CellVEffective_CellVEffective = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_CellVoltException_CellVoltException(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_BmuSample_CellVoltException_CellVoltException = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_RelayKHVoltage_RelayKHVoltage(sint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_HvSysSample_RelayKHVoltage_RelayKHVoltage = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_RelayKNClsSts_U8_RelayKNClsSts_U8(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_HvSysSample_RelayKNClsSts_U8_RelayKNClsSts_U8 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_SampleCountCurrent_U16_SampleCountCurrent_U16(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_HvSysSample_SampleCountCurrent_U16_SampleCountCurrent_U16 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_SampleCountTotalVol_U16_SampleCountTotalVol_U16(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_HvSysSample_SampleCountTotalVol_U16_SampleCountTotalVol_U16 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidBat_U8_SampleValidBat_U8(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_HvSysSample_SampleValidBat_U8_SampleValidBat_U8 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidCurrent_U8_SampleValidCurrent_U8(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_HvSysSample_SampleValidCurrent_U8_SampleValidCurrent_U8 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidIsolation_U8_SampleValidIsolation_U8(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_HvSysSample_SampleValidIsolation_U8_SampleValidIsolation_U8 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidKC_U8_SampleValidKC_U8(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_HvSysSample_SampleValidKC_U8_SampleValidKC_U8 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidKH_U8_SampleValidKH_U8(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_HvSysSample_SampleValidKH_U8_SampleValidKH_U8 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidKM_U8_SampleValidKM_U8(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_HvSysSample_SampleValidKM_U8_SampleValidKM_U8 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidKN_U8_SampleValidKN_U8(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_HvSysSample_SampleValidKN_U8_SampleValidKN_U8 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_RTC_NowSystemTick_NowSystemTick(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_RTC_NowSystemTick_NowSystemTick = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_RTC_RTCStateFault_RTCStateFault(sint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_RTC_RTCStateFault_RTCStateFault = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_RTC_ReadDay_ReadDay(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_RTC_ReadDay_ReadDay = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_RTC_ReadHour_ReadHour(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_RTC_ReadHour_ReadHour = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_RTC_ReadMinute_ReadMinute(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_RTC_ReadMinute_ReadMinute = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_RTC_ReadMonth_ReadMonth(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_RTC_ReadMonth_ReadMonth = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_RTC_ReadSecond_ReadSecond(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_RTC_ReadSecond_ReadSecond = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_RTC_ReadYear_ReadYear(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetInputInterface_RTC_ReadYear_ReadYear = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCL_ChargingMode_ChargingMode(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BCL_ChargingMode_ChargingMode = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCL_ChargingMode_ChargingMode = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCL_CurrentDemand_CurrentDemand(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BCL_CurrentDemand_CurrentDemand = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCL_CurrentDemand_CurrentDemand = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCL_VoltageDemand_VoltageDemand(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BCL_VoltageDemand_VoltageDemand = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCL_VoltageDemand_VoltageDemand = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCP_MaxPermTemperature_MaxPermTemperature(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BCP_MaxPermTemperature_MaxPermTemperature = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_MaxPermTemperature_MaxPermTemperature = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCP_TotalNominalEnergy_TotalNominalEnergy(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BCP_TotalNominalEnergy_TotalNominalEnergy = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_TotalNominalEnergy_TotalNominalEnergy = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCSP_Remaining_range_BCSP_Remaining_range(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BCSP_Remaining_range_BCSP_Remaining_range = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCSP_reserved_BCSP_reserved(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BCSP_reserved_BCSP_reserved = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCS_CurrentChargeState_CurrentChargeState(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BCS_CurrentChargeState_CurrentChargeState = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_CurrentChargeState_CurrentChargeState = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Battery_capacity_BDC_Battery_capacity(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Battery_capacity_BDC_Battery_capacity = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Battery_energy_BDC_Battery_energy(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Battery_energy_BDC_Battery_energy = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Soc_BDC_Soc(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Soc_BDC_Soc = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1 = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10 = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11 = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12 = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13 = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14 = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15 = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16 = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17 = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2 = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3 = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4 = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5 = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6 = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7 = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8 = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9 = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CCS_Timeout_CCS(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BEM_Timeout_CCS_Timeout_CCS = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CCS_Timeout_CCS = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CRO_Timeout_CRO(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BEM_Timeout_CRO_Timeout_CRO = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CRO_Timeout_CRO = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CSD_Timeout_CSD(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BEM_Timeout_CSD_Timeout_CSD = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CSD_Timeout_CSD = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CST_Timeout_CST(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BEM_Timeout_CST_Timeout_CST = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CST_Timeout_CST = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CTS_CML_Timeout_CTS_CML(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BEM_Timeout_CTS_CML_Timeout_CTS_CML = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CTS_CML_Timeout_CTS_CML = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BHM_MaxChargingVoltage_MaxChargingVoltage(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BHM_MaxChargingVoltage_MaxChargingVoltage = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BHM_MaxChargingVoltage_MaxChargingVoltage = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BMS_BMSStopChgReason_BMS_BMSStopChgReason(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BMS_BMSStopChgReason_BMS_BMSStopChgReason = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_BMSStopChgReason_BMS_BMSStopChgReason = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BMS_CCUStopChgReason_BMS_CCUStopChgReason(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BMS_CCUStopChgReason_BMS_CCUStopChgReason = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_CCUStopChgReason_BMS_CCUStopChgReason = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BRM_BatterySystemCapacity_BatterySystemCapacity(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BRM_BatterySystemCapacity_BatterySystemCapacity = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BRM_BatterySystemCapacity_BatterySystemCapacity = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BRM_BatterySystemVoltage_BatterySystemVoltage(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BRM_BatterySystemVoltage_BatterySystemVoltage = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BRM_BatterySystemVoltage_BatterySystemVoltage = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BRM_BatteryType_BatteryType(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BRM_BatteryType_BatteryType = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BRM_BatteryType_BatteryType = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BRM_BmsRevision_BmsRevision(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BRM_BmsRevision_BmsRevision = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BRM_BmsVersion_BmsVersion(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_swc_SetSendCANMsg_S_BRM_BmsVersion_BmsVersion = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BRO_BmsReadyForCharging_BmsReadyForCharging(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BRO_BmsReadyForCharging_BmsReadyForCharging = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BRO_BmsReadyForCharging_BmsReadyForCharging = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryExcessTemperature_BatteryExcessTemperature(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BSM_BatteryExcessTemperature_BatteryExcessTemperature = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryExcessTemperature_BatteryExcessTemperature = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryHighestTemp_BatteryHighestTemp(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BSM_BatteryHighestTemp_BatteryHighestTemp = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryHighestTemp_BatteryHighestTemp = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryInsulationState_BatteryInsulationState(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BSM_BatteryInsulationState_BatteryInsulationState = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryInsulationState_BatteryInsulationState = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryLowestTemp_BatteryLowestTemp(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BSM_BatteryLowestTemp_BatteryLowestTemp = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryLowestTemp_BatteryLowestTemp = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_BsmChargingPermissible_BsmChargingPermissible(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BSM_BsmChargingPermissible_BsmChargingPermissible = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BsmChargingPermissible_BsmChargingPermissible = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspCause_SOC_BmsSuspCause_SOC(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BST_BmsSuspCause_SOC_BmsSuspCause_SOC = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspCause_SOC_BmsSuspCause_SOC = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BmsProtocolVersion_BmsProtocolVersion(UInt32 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_swc_SetSendCANMsg_S_BmsProtocolVersion_BmsProtocolVersion = *(&data);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_SetSendCANMsg_S_BmsProtocolVersion_BmsProtocolVersion = RTE_COM_SENDSIGNALPROXY_SEND;

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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_CIL_HvSysSample_SampleCountInsRes_U16_SampleCountInsRes_U16(P2VAR(uint16, AUTOMATIC, RTE_swc_CIL_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt16)Rte_ComBuffer_HCM_InsulateCounter_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Mode_Request_shutdown_Request_shutdown(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BSWIOSP_Mode_Request_shutdown_Request_shutdown;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BCL_Request_BCL(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BSWIOSP_Request_BCL_Request_BCL;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BCP_Request_BCP(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BSWIOSP_Request_BCP_Request_BCP;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BCPP_Request_BCPP(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BSWIOSP_Request_BCPP_Request_BCPP;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BCS_Request_BCS(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BSWIOSP_Request_BCS_Request_BCS;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BCSP_Request_BCSP(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BSWIOSP_Request_BCSP_Request_BCSP;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BDC_Request_BDC(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BSWIOSP_Request_BDC_Request_BDC;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BEM_Request_BEM(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BSWIOSP_Request_BEM_Request_BEM;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BHM_Request_BHM(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BSWIOSP_Request_BHM_Request_BHM;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BMS_FastChgStopInfo_Request_BMS_FastChgStopInfo(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BSWIOSP_Request_BMS_FastChgStopInfo_Request_BMS_FastChgStopInfo;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BMT_Request_BMT(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BSWIOSP_Request_BMT_Request_BMT;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BMV_Request_BMV(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BSWIOSP_Request_BMV_Request_BMV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BRM_Request_BRM(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BSWIOSP_Request_BRM_Request_BRM;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BRO_Request_BRO(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BSWIOSP_Request_BRO_Request_BRO;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BSD_Request_BSD(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BSWIOSP_Request_BSD_Request_BSD;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BSM_Request_BSM(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BSWIOSP_Request_BSM_Request_BSM;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BSP_Request_BSP(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BSWIOSP_Request_BSP_Request_BSP;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BST_Request_BST(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BSWIOSP_Request_BST_Request_BST;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BmuControl_BalanceControl_BalanceControl(P2VAR(uint32, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MemCpy32((uint8*)(data), (uint8*)(Rte_swc_COL_BmuControl_BalanceControl_BalanceControl), sizeof(rt_Array_UInt32_9));
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCL_ChargingMode_ChargingMode(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_ChargingMode_ChargingMode;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCL_CurrentDemand_CurrentDemand(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_CurrentDemand_CurrentDemand;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCL_VoltageDemand_VoltageDemand(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_VoltageDemand_VoltageDemand;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_MaxPermChargingCurrent_MaxPermChargingCurrent;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCP_MaxPermTemperature_MaxPermTemperature(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_MaxPermTemperature_MaxPermTemperature;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCP_TotalNominalEnergy_TotalNominalEnergy(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_TotalNominalEnergy_TotalNominalEnergy;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCSP_Remaining_range_BCSP_Remaining_range(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BCSP_Remaining_range_BCSP_Remaining_range;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCSP_reserved_BCSP_reserved(P2VAR(UInt32, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BCSP_reserved_BCSP_reserved;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCS_CurrentChargeState_CurrentChargeState(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_CurrentChargeState_CurrentChargeState;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_MeasuredChargingCurrent_MeasuredChargingCurrent;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_MeasuredChargingVoltage_MeasuredChargingVoltage;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Battery_capacity_BDC_Battery_capacity(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Battery_capacity_BDC_Battery_capacity;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Battery_energy_BDC_Battery_energy(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Battery_energy_BDC_Battery_energy;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Soc_BDC_Soc(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Soc_BDC_Soc;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CCS_Timeout_CCS(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_Timeout_CCS_Timeout_CCS;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_Timeout_CRM_Recognized_Timeout_CRM_Recognized;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CRO_Timeout_CRO(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_Timeout_CRO_Timeout_CRO;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CSD_Timeout_CSD(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_Timeout_CSD_Timeout_CSD;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CST_Timeout_CST(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_Timeout_CST_Timeout_CST;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CTS_CML_Timeout_CTS_CML(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_Timeout_CTS_CML_Timeout_CTS_CML;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BHM_MaxChargingVoltage_MaxChargingVoltage(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_MaxChargingVoltage_MaxChargingVoltage;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BMS_BMSStopChgReason_BMS_BMSStopChgReason(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMS_BMSStopChgReason_BMS_BMSStopChgReason;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BMS_CCUStopChgReason_BMS_CCUStopChgReason(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMS_CCUStopChgReason_BMS_CCUStopChgReason;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BRM_BatterySystemCapacity_BatterySystemCapacity(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BatterySystemCapacity_BatterySystemCapacity;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BRM_BatterySystemVoltage_BatterySystemVoltage(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BatterySystemVoltage_BatterySystemVoltage;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BRM_BatteryType_BatteryType(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BatteryType_BatteryType;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BRM_BmsRevision_BmsRevision(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BmsRevision_BmsRevision;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BRM_BmsVersion_BmsVersion(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BmsVersion_BmsVersion;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BRO_BmsReadyForCharging_BmsReadyForCharging(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BmsReadyForCharging_BmsReadyForCharging;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_SingleBatteryMinTemperature_SingleBatteryMinTemperature;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_SingleBatteryMinVoltage_SingleBatteryMinVoltage;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BatteryChargingOvercurrent_BatteryChargingOvercurrent;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryExcessTemperature_BatteryExcessTemperature(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BatteryExcessTemperature_BatteryExcessTemperature;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryHighestTemp_BatteryHighestTemp(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BatteryHighestTemp_BatteryHighestTemp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BatteryHighestTempSerNo_BatteryHighestTempSerNo;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryInsulationState_BatteryInsulationState(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BatteryInsulationState_BatteryInsulationState;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryLowestTemp_BatteryLowestTemp(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BatteryLowestTemp_BatteryLowestTemp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BatteryLowestTempSerNo_BatteryLowestTempSerNo;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BatteryOutputConnectorState_BatteryOutputConnectorState;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_BsmChargingPermissible_BsmChargingPermissible(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BsmChargingPermissible_BsmChargingPermissible;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspCause_SOC_BmsSuspCause_SOC(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BmsSuspCause_SOC_BmsSuspCause_SOC;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BmsSuspFault_Insulation_BmsSuspFault_Insulation;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay;
    return ret;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
  
/*
************************************************************************************************************************
*    Inter-runnable variable access
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_NVM_Write_100ms_DEH_CtrErrCfmdNv(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_CtrErrCfmdNv;
}


FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF02_22_RE_DEH_CtrErrCfmdNv(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_CtrErrCfmdNv;
}


FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_CtrFctInhDeacStopDiag(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_CtrFctInhDeacStopDiag;
}


FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_CtrFctInhDeacStrtDiag(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_CtrFctInhDeacStrtDiag;
}


FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_CtrRlyReqDiagCh(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_CtrRlyReqDiagCh;
}


FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_CtrRlyReqDiagNeg(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_CtrRlyReqDiagNeg;
}


FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_CtrRlyReqDiagPos(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_CtrRlyReqDiagPos;
}


FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_CtrRlyReqDiagPrech(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_CtrRlyReqDiagPrech;
}


FUNC(UInt32, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_ErrCfmd1(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd1;
}


FUNC(UInt32, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_ErrCfmd2(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd2;
}


FUNC(UInt32, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_ErrCfmd3(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd3;
}


FUNC(UInt32, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_ErrCfmd4(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd4;
}


FUNC(UInt32, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_ErrCfmd5(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd5;
}


FUNC(UInt32, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_ErrCfmd6(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd6;
}


FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0537_22_RE_DEH_LvlErr(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_LvlErr;
}


FUNC(Boolean, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_ReqRlyCh(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_ReqRlyCh;
}


FUNC(Boolean, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_ReqRlyNeg(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_ReqRlyNeg;
}


FUNC(Boolean, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_ReqRlyPos(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_ReqRlyPos;
}


FUNC(Boolean, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_ReqRlyPrech(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_ReqRlyPrech;
}


FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_StsIninNv(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_StsIninNv;
}


FUNC(Boolean, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_bAcvBdNew(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_DEH_bAcvBdNew;
}


FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_GetEventStatus_10ms_NVM_CtrErrCfmd(void)
{
    return Rte_Irv_swc_DiagcEveHndlg_NVM_CtrErrCfmd;
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_CtrErrCfmdNv(UInt8 data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_CtrErrCfmdNv = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x05F6_Stop_Services_DEH_CtrFctInhDeacStopDiag(UInt8 data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_CtrFctInhDeacStopDiag = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x05F6_Start_Services_DEH_CtrFctInhDeacStrtDiag(UInt8 data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_CtrFctInhDeacStrtDiag = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Services_DEH_CtrRlyReqDiagCh(UInt8 data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_CtrRlyReqDiagCh = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Services_DEH_CtrRlyReqDiagNeg(UInt8 data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_CtrRlyReqDiagNeg = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Services_DEH_CtrRlyReqDiagPos(UInt8 data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_CtrRlyReqDiagPos = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Services_DEH_CtrRlyReqDiagPrech(UInt8 data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_CtrRlyReqDiagPrech = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_ErrCfmd1(UInt32 data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd1 = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_ErrCfmd2(UInt32 data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd2 = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_ErrCfmd3(UInt32 data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd3 = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_ErrCfmd4(UInt32 data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd4 = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_ErrCfmd5(UInt32 data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd5 = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_ErrCfmd6(UInt32 data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd6 = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_DEH_10ms_DEH_LvlErr(UInt8 data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_LvlErr = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Services_DEH_ReqRlyCh(Boolean data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_ReqRlyCh = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Services_DEH_ReqRlyNeg(Boolean data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_ReqRlyNeg = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Services_DEH_ReqRlyPos(Boolean data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_ReqRlyPos = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Services_DEH_ReqRlyPrech(Boolean data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_ReqRlyPrech = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_DEH_Init_DEH_StsIninNv(UInt8 data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_StsIninNv = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_NVM_Read_10ms_DEH_StsIninNv(UInt8 data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_StsIninNv = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_DEH_Init_DEH_bAcvBdNew(Boolean data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_bAcvBdNew = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_NVM_Read_10ms_DEH_bAcvBdNew(Boolean data)
{
    Rte_Irv_swc_DiagcEveHndlg_DEH_bAcvBdNew = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_DEH_Init_NVM_CtrErrCfmd(UInt8 data)
{
    Rte_Irv_swc_DiagcEveHndlg_NVM_CtrErrCfmd = *(&data);
}


FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_NVM_Read_10ms_NVM_CtrErrCfmd(UInt8 data)
{
    Rte_Irv_swc_DiagcEveHndlg_NVM_CtrErrCfmd = *(&data);
}


#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

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
TASK(SWC_Init_Task_Core2)
{
    Core2_Runnable_Task_Init();

    swc_SetInput_Init();

    swc_SetOutputInterface_Init();

    swc_SetSendCANMsg_Init();

    BBC_Init();

    BCC_Init();
    Rte_swc_BatChCtl_BCC_StAcSys_BCC_StAcSys = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_BCC_StAcSys_BCC_StAcSys.value);
    Rte_swc_BatChCtl_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq.value);
    Rte_swc_BatChCtl_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr.value);
    Rte_swc_BatChCtl_EVCSH_StBatRdy_EVCSH_StBatRdy = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_StBatRdy_EVCSH_StBatRdy.value);
    Rte_swc_BatChCtl_EVCSH_StInt_EVCSH_StInt = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_StInt_EVCSH_StInt.value);
    Rte_swc_BatChCtl_EVCSH_bAcvCfgCmpl_EVCSH_bAcvCfgCmpl = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bAcvCfgCmpl_EVCSH_bAcvCfgCmpl.value);
    Rte_swc_BatChCtl_EVCSH_bAcvChSeqEnd_EVCSH_bAcvChSeqEnd = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bAcvChSeqEnd_EVCSH_bAcvChSeqEnd.value);
    Rte_swc_BatChCtl_EVCSH_bAcvDcChReqFromVcu_EVCSH_bAcvDcChReqFromVcu = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bAcvDcChReqFromVcu_EVCSH_bAcvDcChReqFromVcu.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc.value);
    Rte_swc_BatChCtl_TimeOut_CRO00_BCC_TimeOutCRO00 = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_TimeOut_CRO00_BCC_TimeOutCRO00.value);
    Rte_swc_BatChCtl_TimeOut_CROAA_BCC_TimeOutCROAA = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_TimeOut_CROAA_BCC_TimeOutCROAA.value);

    BCF_Init();
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_CMdulAbsv_BCF_CMdulAbsv, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_CMdulAbsv_BCF_CMdulAbsv.value, sizeof(rt_Array_Float_24));
    Rte_swc_BatCoreFct_BCF_ChIIntglNv_BCF_ChIIntglNv = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ChIIntglNv_BCF_ChIIntglNv.value);
    Rte_swc_BatCoreFct_BCF_EPackRmng_BCF_EPackRmng = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_EPackRmng_BCF_EPackRmng.value);
    Rte_swc_BatCoreFct_BCF_ErrInfo_BCF_ErrInfo = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo_BCF_ErrInfo.value);
    Rte_swc_BatCoreFct_BCF_ErrInfo1_BCF_ErrInfo1 = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo1_BCF_ErrInfo1.value);
    Rte_swc_BatCoreFct_BCF_ErrInfo2_BCF_ErrInfo2 = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo2_BCF_ErrInfo2.value);
    Rte_swc_BatCoreFct_BCF_ErrInfo3_BCF_ErrInfo3 = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo3_BCF_ErrInfo3.value);
    Rte_swc_BatCoreFct_BCF_ErrInfo4_BCF_ErrInfo4 = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo4_BCF_ErrInfo4.value);
    Rte_swc_BatCoreFct_BCF_ErrInfo5_BCF_ErrInfo5 = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo5_BCF_ErrInfo5.value);
    Rte_swc_BatCoreFct_BCF_ErrInfo6_BCF_ErrInfo6 = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo6_BCF_ErrInfo6.value);
    Rte_swc_BatCoreFct_BCF_IChLimInt_BCF_IChLimInt = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IChLimInt_BCF_IChLimInt.value);
    Rte_swc_BatCoreFct_BCF_IChLimMap_BCF_IChLimMap = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IChLimMap_BCF_IChLimMap.value);
    Rte_swc_BatCoreFct_BCF_IChMax_BCF_IChMax = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IChMax_BCF_IChMax.value);
    Rte_swc_BatCoreFct_BCF_IChPredLimInt_BCF_IChPredLimInt = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IChPredLimInt_BCF_IChPredLimInt.value);
    Rte_swc_BatCoreFct_BCF_IDchaLimInt_BCF_IDchaLimInt = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IDchaLimInt_BCF_IDchaLimInt.value);
    Rte_swc_BatCoreFct_BCF_IDchaLimMap_BCF_IDchaLimMap = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IDchaLimMap_BCF_IDchaLimMap.value);
    Rte_swc_BatCoreFct_BCF_IDchaMax_BCF_IDchaMax = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IDchaMax_BCF_IDchaMax.value);
    Rte_swc_BatCoreFct_BCF_IDchaPredLimInt_BCF_IDchaPredLimInt = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IDchaPredLimInt_BCF_IDchaPredLimInt.value);
    Rte_swc_BatCoreFct_BCF_IIntglNv_BCF_IIntglNv = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IIntglNv_BCF_IIntglNv.value);
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_PwrMdulLoss_BCF_PwrMdulLoss, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_PwrMdulLoss_BCF_PwrMdulLoss.value, sizeof(rt_Array_Float_24));
    Rte_swc_BatCoreFct_BCF_RPackInt_BCF_RPackInt = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_RPackInt_BCF_RPackInt.value);
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_SocCell_BCF_SocCell, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SocCell_BCF_SocCell.value, sizeof(rt_Array_Float_255));
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_SocCellDelta_BCF_SocCellDelta, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SocCellDelta_BCF_SocCellDelta.value, sizeof(rt_Array_Float_255));
    Rte_swc_BatCoreFct_BCF_SocCnsActNv_BCF_SocCnsActNv = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SocCnsActNv_BCF_SocCnsActNv.value);
    Rte_swc_BatCoreFct_BCF_SocLimMax_BCF_SocLimMax = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SocLimMax_BCF_SocLimMax.value);
    Rte_swc_BatCoreFct_BCF_SocLimMin_BCF_SocLimMin = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SocLimMin_BCF_SocLimMin.value);
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_SocMdul_BCF_SocMdul, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SocMdul_BCF_SocMdul.value, sizeof(rt_Array_Float_24));
    Rte_swc_BatCoreFct_BCF_SohCalNv_BCF_SohCalNv = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SohCalNv_BCF_SohCalNv.value);
    Rte_swc_BatCoreFct_BCF_SohCycNv_BCF_SohCycNv = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SohCycNv_BCF_SohCycNv.value);
    Rte_swc_BatCoreFct_BCF_SohPack_BCF_SohPack = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SohPack_BCF_SohPack.value);
    Rte_swc_BatCoreFct_BCF_SohPackNv_BCF_SohPackNv = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SohPackNv_BCF_SohPackNv.value);
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_StLimnId_BCF_StLimnId, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_StLimnId_BCF_StLimnId.value, sizeof(rt_Array_UInt8_4));
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_TCooltMdulOut_BCF_TCooltMdulOut, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_TCooltMdulOut_BCF_TCooltMdulOut.value, sizeof(rt_Array_Float_24));
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_TMdulEstimd_BCF_TMdulEstimd, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_TMdulEstimd_BCF_TMdulEstimd.value, sizeof(rt_Array_Float_24));
    Rte_swc_BatCoreFct_BCF_TiBatOffNv_BCF_TiBatOffNv = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_TiBatOffNv_BCF_TiBatOffNv.value);
    Rte_swc_BatCoreFct_BCF_UChLimInt_BCF_UChLimInt = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_UChLimInt_BCF_UChLimInt.value);
    Rte_swc_BatCoreFct_BCF_UChPredLimInt_BCF_UChPredLimInt = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_UChPredLimInt_BCF_UChPredLimInt.value);
    Rte_swc_BatCoreFct_BCF_UDchaLimInt_BCF_UDchaLimInt = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_UDchaLimInt_BCF_UDchaLimInt.value);
    Rte_swc_BatCoreFct_BCF_UDchaPredLimInt_BCF_UDchaPredLimInt = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_UDchaPredLimInt_BCF_UDchaPredLimInt.value);
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_UMdul_BCF_UMdul, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_UMdul_BCF_UMdul.value, sizeof(rt_Array_Float_24));
    Rte_swc_BatCoreFct_BCF_UPackCircOpen_BCF_UPackCircOpen = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_UPackCircOpen_BCF_UPackCircOpen.value);
    Rte_swc_BatCoreFct_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg.value);
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls.value, sizeof(rt_Array_UInt8_24));

    BatProtnIU_Init();
    Rte_swc_BatProtnIU_BPIU_IdCellUMax_BPIU_IdCellUMax = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnIU_BatProtnIU_Init.Rte_BPIU_IdCellUMax_BPIU_IdCellUMax.value);
    Rte_swc_BatProtnIU_BPIU_IdCellUMin_BPIU_IdCellUMin = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnIU_BatProtnIU_Init.Rte_BPIU_IdCellUMin_BPIU_IdCellUMin.value);
    Rte_swc_BatProtnIU_BPIU_IdMdulForCellUMax_BPIU_IdMdulForCellUMax = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnIU_BatProtnIU_Init.Rte_BPIU_IdMdulForCellUMax_BPIU_IdMdulForCellUMax.value);
    Rte_swc_BatProtnIU_BPIU_IdMdulForCellUMin_BPIU_IdMdulForCellUMin = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnIU_BatProtnIU_Init.Rte_BPIU_IdMdulForCellUMin_BPIU_IdMdulForCellUMin.value);
    Rte_swc_BatProtnIU_BPIU_UCellMax_BPIU_UCellMax = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnIU_BatProtnIU_Init.Rte_BPIU_UCellMax_BPIU_UCellMax.value);
    Rte_swc_BatProtnIU_BPIU_UCellMin_BPIU_UCellMin = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnIU_BatProtnIU_Init.Rte_BPIU_UCellMin_BPIU_UCellMin.value);

    BPP_Init();
    Rte_swc_BatProtnPack_BPP_SocLimMax_BPP_SocLimMax = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnPack_BPP_Init.Rte_BPP_SocLimMax_BPP_SocLimMax.value);
    Rte_swc_BatProtnPack_BPP_SocLimMin_BPP_SocLimMin = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnPack_BPP_Init.Rte_BPP_SocLimMin_BPP_SocLimMin.value);
    Rte_swc_BatProtnPack_BPP_TCellMaxLim_BPP_TCellMaxLim = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnPack_BPP_Init.Rte_BPP_TCellMaxLim_BPP_TCellMaxLim.value);
    Rte_swc_BatProtnPack_BPP_TCellMinLim_BPP_TCellMinLim = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnPack_BPP_Init.Rte_BPP_TCellMinLim_BPP_TCellMinLim.value);

    BTHM_Init();
    Rte_MemCpy(Rte_swc_BatThermHndlgMngt_BTHM_MfCoolt_BTHM_MfCoolt, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_MfCoolt_BTHM_MfCoolt.value, sizeof(rt_Array_Float_24));
    Rte_swc_BatThermHndlgMngt_BTHM_StErrTOver_BTHM_StErrTOver = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_StErrTOver_BTHM_StErrTOver.value);
    Rte_swc_BatThermHndlgMngt_BTHM_StThermReq_BTHM_StThermReq = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_StThermReq_BTHM_StThermReq.value);
    Rte_swc_BatThermHndlgMngt_BTHM_TOptmMax_BTHM_TOptmMax = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_TOptmMax_BTHM_TOptmMax.value);
    Rte_swc_BatThermHndlgMngt_BTHM_TOptmMin_BTHM_TOptmMin = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_TOptmMin_BTHM_TOptmMin.value);
    Rte_MemCpy(Rte_swc_BatThermHndlgMngt_BTHM_bAcvTAbno_BTHM_bAcvTAbno, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_bAcvTAbno_BTHM_bAcvTAbno.value, sizeof(rt_Array_Boolean_24));
    Rte_MemCpy(Rte_swc_BatThermHndlgMngt_BTHM_bErrSnsrT_BTHM_bErrSnsrT, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_bErrSnsrT_BTHM_bErrSnsrT.value, sizeof(rt_Array_Boolean_24));

    BWLD_Init();

    BSTC_Init();

    CIL_Init();
    Rte_swc_CIL_CIL_CfgLvl2_CIL_CfgLvl2 = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_CfgLvl2_CIL_CfgLvl2.value);
    Rte_swc_CIL_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl.value);
    Rte_swc_CIL_CIL_HWVerVeh_CIL_HWVerVeh = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_HWVerVeh_CIL_HWVerVeh.value);
    Rte_swc_CIL_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl.value);
    Rte_swc_CIL_CIL_SWVerVeh_CIL_SWVerVeh = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_SWVerVeh_CIL_SWVerVeh.value);
    Rte_swc_CIL_CIL_StProj_CIL_StProj = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_StProj_CIL_StProj.value);
    Rte_MemCpy(Rte_swc_CIL_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE.value, sizeof(rt_Array_Float_24));
    Rte_swc_CIL_MCC_NrAFETot_MCC_NrAFETot = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrAFETot_MCC_NrAFETot.value);
    Rte_MemCpy(Rte_swc_CIL_MCC_NrCellByMdul_MCC_NrCellByMdul, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrCellByMdul_MCC_NrCellByMdul.value, sizeof(rt_Array_UInt8_24));
    Rte_swc_CIL_MCC_NrCellTot_MCC_NrCellTot = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrCellTot_MCC_NrCellTot.value);
    Rte_MemCpy(Rte_swc_CIL_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul.value, sizeof(rt_Array_UInt8_24));
    Rte_swc_CIL_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot.value);
    Rte_swc_CIL_MCC_NrMdulTot_MCC_NrMdulTot = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrMdulTot_MCC_NrMdulTot.value);
    Rte_MemCpy(Rte_swc_CIL_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul.value, sizeof(rt_Array_UInt8_24));
    Rte_swc_CIL_MCC_NrSnsrTTot_MCC_NrSnsrTTot = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrSnsrTTot_MCC_NrSnsrTTot.value);

    COL_Init();
    Rte_swc_COL_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc.value);
    Rte_swc_COL_BCSP_reserved_BCSP_reserved = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BCSP_reserved_BCSP_reserved.value);
    Rte_swc_COL_BatteryOutputConnectorState_BatteryOutputConnectorState = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BatteryOutputConnectorState_BatteryOutputConnectorState.value);
    Rte_swc_COL_BatteryType_BatteryType = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BatteryType_BatteryType.value);
    Rte_swc_COL_BmsRevision_BmsRevision = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BmsRevision_BmsRevision.value);
    Rte_swc_COL_BmsVersion_BmsVersion = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BmsVersion_BmsVersion.value);


    Rte_swc_COL_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault = RTE_COM_SENDSIGNALPROXY_SEND;

    CTC_Init();
    Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CtctrTranCtl_CTC_Init.Rte_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv.value);
    Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CtctrTranCtl_CTC_Init.Rte_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv.value);
    Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CtctrTranCtl_CTC_Init.Rte_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv.value);
    Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CtctrTranCtl_CTC_Init.Rte_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv.value);
    Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CtctrTranCtl_CTC_Init.Rte_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv.value);
    Rte_swc_CtctrTranCtl_CTC_IDriftZero_CTC_IDriftZero = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CtctrTranCtl_CTC_Init.Rte_CTC_IDriftZero_CTC_IDriftZero.value);

    DEH_Init();
    Rte_swc_DiagcEveHndlg_DEH_StFltLampIndcn_DEH_StFltLampIndcn = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_DEH_StFltLampIndcn_DEH_StFltLampIndcn.value);
    Rte_swc_DiagcEveHndlg_DEH_StsIninNv_DEH_StsIninNv = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_DEH_StsIninNv_DEH_StsIninNv.value);
    Rte_swc_DiagcEveHndlg_DEH_TiChFullOff_DEH_TiChFullOff = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_DEH_TiChFullOff_DEH_TiChFullOff.value);
    Rte_swc_DiagcEveHndlg_DEH_ValCodDiag_DEH_ValCodDiag = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_DEH_ValCodDiag_DEH_ValCodDiag.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvBdNew_DEH_bAcvBdNew = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_DEH_bAcvBdNew_DEH_bAcvBdNew.value);
    Rte_swc_DiagcEveHndlg_NVM_CBatChTot_NVM_CBatChTot = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CBatChTot_NVM_CBatChTot.value);
    Rte_swc_DiagcEveHndlg_NVM_CBatDchaTot_NVM_CBatDchaTot = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CBatDchaTot_NVM_CBatDchaTot.value);
    Rte_swc_DiagcEveHndlg_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot.value);
    Rte_MemCpy(Rte_swc_DiagcEveHndlg_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls.value, sizeof(rt_Array_Float_24));
    Rte_swc_DiagcEveHndlg_NVM_ChIIntglFls_NVM_ChIIntglFls = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_ChIIntglFls_NVM_ChIIntglFls.value);
    Rte_swc_DiagcEveHndlg_NVM_ChgDeltAh_NVM_ChgDeltAh = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_ChgDeltAh_NVM_ChgDeltAh.value);
    Rte_swc_DiagcEveHndlg_NVM_CtrCh_NVM_CtrCh = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrCh_NVM_CtrCh.value);
    Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh.value);
    Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat.value);
    Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg.value);
    Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos.value);
    Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech.value);
    Rte_swc_DiagcEveHndlg_NVM_CtrDcha_NVM_CtrDcha = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrDcha_NVM_CtrDcha.value);
    Rte_swc_DiagcEveHndlg_NVM_DayRtcLst_NVM_DayRtcLst = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_DayRtcLst_NVM_DayRtcLst.value);
    Rte_swc_DiagcEveHndlg_NVM_DeltAh_NVM_DeltAh = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_DeltAh_NVM_DeltAh.value);
    Rte_swc_DiagcEveHndlg_NVM_EBatChTot_NVM_EBatChTot = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_EBatChTot_NVM_EBatChTot.value);
    Rte_swc_DiagcEveHndlg_NVM_EBatDchaTot_NVM_EBatDchaTot = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_EBatDchaTot_NVM_EBatDchaTot.value);
    Rte_swc_DiagcEveHndlg_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot.value);
    Rte_swc_DiagcEveHndlg_NVM_FullChgSOH_NVM_FullChgSOH = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_FullChgSOH_NVM_FullChgSOH.value);
    Rte_swc_DiagcEveHndlg_NVM_HourRtcLst_NVM_HourRtcLst = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_HourRtcLst_NVM_HourRtcLst.value);
    Rte_swc_DiagcEveHndlg_NVM_IBatChMax_NVM_IBatChMax = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_IBatChMax_NVM_IBatChMax.value);
    Rte_swc_DiagcEveHndlg_NVM_IBatDchaMax_NVM_IBatDchaMax = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_IBatDchaMax_NVM_IBatDchaMax.value);
    Rte_swc_DiagcEveHndlg_NVM_IIntglFls_NVM_IIntglFls = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_IIntglFls_NVM_IIntglFls.value);
    Rte_swc_DiagcEveHndlg_NVM_MinuRtcLst_NVM_MinuRtcLst = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_MinuRtcLst_NVM_MinuRtcLst.value);
    Rte_swc_DiagcEveHndlg_NVM_MonthRtcLst_NVM_MonthRtcLst = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_MonthRtcLst_NVM_MonthRtcLst.value);
    Rte_swc_DiagcEveHndlg_NVM_PBatChMax_NVM_PBatChMax = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_PBatChMax_NVM_PBatChMax.value);
    Rte_swc_DiagcEveHndlg_NVM_PBatDchaMax_NVM_PBatDchaMax = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_PBatDchaMax_NVM_PBatDchaMax.value);
    Rte_swc_DiagcEveHndlg_NVM_RIslnNeg_NVM_RIslnNeg = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_RIslnNeg_NVM_RIslnNeg.value);
    Rte_swc_DiagcEveHndlg_NVM_RIslnPos_NVM_RIslnPos = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_RIslnPos_NVM_RIslnPos.value);
    Rte_MemCpy(Rte_swc_DiagcEveHndlg_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls.value, sizeof(rt_Array_Float_24));
    Rte_MemCpy(Rte_swc_DiagcEveHndlg_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln.value, sizeof(rt_Array_UInt8_255));
    Rte_swc_DiagcEveHndlg_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg.value);
    Rte_swc_DiagcEveHndlg_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg.value);
    Rte_swc_DiagcEveHndlg_NVM_SecRtcLst_NVM_SecRtcLst = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SecRtcLst_NVM_SecRtcLst.value);
    Rte_swc_DiagcEveHndlg_NVM_SocBatMax_NVM_SocBatMax = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SocBatMax_NVM_SocBatMax.value);
    Rte_swc_DiagcEveHndlg_NVM_SocBatMin_NVM_SocBatMin = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SocBatMin_NVM_SocBatMin.value);
    Rte_swc_DiagcEveHndlg_NVM_SocCnsAct_NVM_SocCnsAct = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SocCnsAct_NVM_SocCnsAct.value);
    Rte_swc_DiagcEveHndlg_NVM_SocPackScld_NVM_SocPackScld = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SocPackScld_NVM_SocPackScld.value);
    Rte_swc_DiagcEveHndlg_NVM_SocUOcIni_NVM_SocUOcIni = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SocUOcIni_NVM_SocUOcIni.value);
    Rte_swc_DiagcEveHndlg_NVM_SohCalFls_NVM_SohCalFls = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SohCalFls_NVM_SohCalFls.value);
    Rte_swc_DiagcEveHndlg_NVM_SohCycFls_NVM_SohCycFls = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SohCycFls_NVM_SohCycFls.value);
    Rte_swc_DiagcEveHndlg_NVM_SohPackFls_NVM_SohPackFls = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SohPackFls_NVM_SohPackFls.value);
    Rte_MemCpy(Rte_swc_DiagcEveHndlg_NVM_SohRDeltaFls_NVM_SohRDeltaFls, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SohRDeltaFls_NVM_SohRDeltaFls.value, sizeof(rt_Array_Float_24));
    Rte_MemCpy(Rte_swc_DiagcEveHndlg_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls.value, sizeof(rt_Array_Float_24));
    Rte_MemCpy(Rte_swc_DiagcEveHndlg_NVM_StAryFls_NVM_StAryFls, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_StAryFls_NVM_StAryFls.value, sizeof(rt_Array_Float_144));
    Rte_swc_DiagcEveHndlg_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax.value);
    Rte_swc_DiagcEveHndlg_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin.value);
    Rte_swc_DiagcEveHndlg_NVM_TPackFls_NVM_TPackFls = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TPackFls_NVM_TPackFls.value);
    Rte_swc_DiagcEveHndlg_NVM_TiBatAgi_NVM_TiBatAgi = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TiBatAgi_NVM_TiBatAgi.value);
    Rte_swc_DiagcEveHndlg_NVM_TiBatOffFls_NVM_TiBatOffFls = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TiBatOffFls_NVM_TiBatOffFls.value);
    Rte_MemCpy(Rte_swc_DiagcEveHndlg_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls.value, sizeof(rt_Array_UInt32_24));
    Rte_MemCpy(Rte_swc_DiagcEveHndlg_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls.value, sizeof(rt_Array_UInt32_24));
    Rte_swc_DiagcEveHndlg_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax.value);
    Rte_swc_DiagcEveHndlg_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin.value);
    Rte_swc_DiagcEveHndlg_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax.value);
    Rte_swc_DiagcEveHndlg_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin.value);
    Rte_swc_DiagcEveHndlg_NVM_UCellMax_NVM_UCellMax = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UCellMax_NVM_UCellMax.value);
    Rte_swc_DiagcEveHndlg_NVM_UCellMin_NVM_UCellMin = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UCellMin_NVM_UCellMin.value);
    Rte_swc_DiagcEveHndlg_NVM_UPrechAccumd_NVM_UPrechAccumd = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UPrechAccumd_NVM_UPrechAccumd.value);
    Rte_swc_DiagcEveHndlg_NVM_YearRtcLst_NVM_YearRtcLst = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_YearRtcLst_NVM_YearRtcLst.value);
    Rte_MemCpy(Rte_swc_DiagcEveHndlg_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls, Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls.value, sizeof(rt_Array_UInt8_24));

    ELHPN_Init();
    Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StCrashIni_ELHPN_StCrashIni = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_Init.Rte_ELHPN_StCrashIni_ELHPN_StCrashIni.value);
    Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_Init.Rte_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc.value);
    Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni = *(&Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_Init.Rte_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni.value);

    (void)TerminateTask();
}

TASK(App1_Task_1ms_Core2_QM)
{
    Core2_Runnable_App_1ms();

    (void)TerminateTask();
}

TASK(App1_Task_5ms_Core2_QM)
{
    Core2_Runnable_App_5ms();

    (void)TerminateTask();
}

TASK(App1_Task_10ms_Core2_QM)
{
    Core2_Runnable_App_10ms();

    swc_SetInput_10ms();

    swc_SetSendCANMsg_10ms();

    swc_SetOutputInterface_10ms();

    NVM_Read_10ms();
    Rte_swc_DiagcEveHndlg_DEH_StsIninNv_DEH_StsIninNv = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_DEH_StsIninNv_DEH_StsIninNv.value);
    Rte_swc_DiagcEveHndlg_DEH_TiChFullOff_DEH_TiChFullOff = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_DEH_TiChFullOff_DEH_TiChFullOff.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvBdNew_DEH_bAcvBdNew = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_DEH_bAcvBdNew_DEH_bAcvBdNew.value);
    Rte_swc_DiagcEveHndlg_NVM_CBatChTot_NVM_CBatChTot = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CBatChTot_NVM_CBatChTot.value);
    Rte_swc_DiagcEveHndlg_NVM_CBatDchaTot_NVM_CBatDchaTot = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CBatDchaTot_NVM_CBatDchaTot.value);
    Rte_swc_DiagcEveHndlg_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot.value);
    Rte_MemCpy(Rte_swc_DiagcEveHndlg_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls, Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls.value, sizeof(rt_Array_Float_24));
    Rte_swc_DiagcEveHndlg_NVM_ChIIntglFls_NVM_ChIIntglFls = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_ChIIntglFls_NVM_ChIIntglFls.value);
    Rte_swc_DiagcEveHndlg_NVM_ChgDeltAh_NVM_ChgDeltAh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_ChgDeltAh_NVM_ChgDeltAh.value);
    Rte_swc_DiagcEveHndlg_NVM_CtrCh_NVM_CtrCh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrCh_NVM_CtrCh.value);
    Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh.value);
    Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat.value);
    Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg.value);
    Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos.value);
    Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech.value);
    Rte_swc_DiagcEveHndlg_NVM_CtrDcha_NVM_CtrDcha = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrDcha_NVM_CtrDcha.value);
    Rte_swc_DiagcEveHndlg_NVM_DayRtcLst_NVM_DayRtcLst = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_DayRtcLst_NVM_DayRtcLst.value);
    Rte_swc_DiagcEveHndlg_NVM_DeltAh_NVM_DeltAh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_DeltAh_NVM_DeltAh.value);
    Rte_swc_DiagcEveHndlg_NVM_EBatChTot_NVM_EBatChTot = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_EBatChTot_NVM_EBatChTot.value);
    Rte_swc_DiagcEveHndlg_NVM_EBatDchaTot_NVM_EBatDchaTot = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_EBatDchaTot_NVM_EBatDchaTot.value);
    Rte_swc_DiagcEveHndlg_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot.value);
    Rte_swc_DiagcEveHndlg_NVM_FullChgSOH_NVM_FullChgSOH = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_FullChgSOH_NVM_FullChgSOH.value);
    Rte_swc_DiagcEveHndlg_NVM_HourRtcLst_NVM_HourRtcLst = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_HourRtcLst_NVM_HourRtcLst.value);
    Rte_swc_DiagcEveHndlg_NVM_IBatChMax_NVM_IBatChMax = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_IBatChMax_NVM_IBatChMax.value);
    Rte_swc_DiagcEveHndlg_NVM_IBatDchaMax_NVM_IBatDchaMax = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_IBatDchaMax_NVM_IBatDchaMax.value);
    Rte_swc_DiagcEveHndlg_NVM_IIntglFls_NVM_IIntglFls = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_IIntglFls_NVM_IIntglFls.value);
    Rte_swc_DiagcEveHndlg_NVM_MinuRtcLst_NVM_MinuRtcLst = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_MinuRtcLst_NVM_MinuRtcLst.value);
    Rte_swc_DiagcEveHndlg_NVM_MonthRtcLst_NVM_MonthRtcLst = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_MonthRtcLst_NVM_MonthRtcLst.value);
    Rte_swc_DiagcEveHndlg_NVM_PBatChMax_NVM_PBatChMax = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_PBatChMax_NVM_PBatChMax.value);
    Rte_swc_DiagcEveHndlg_NVM_PBatDchaMax_NVM_PBatDchaMax = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_PBatDchaMax_NVM_PBatDchaMax.value);
    Rte_swc_DiagcEveHndlg_NVM_RIslnNeg_NVM_RIslnNeg = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_RIslnNeg_NVM_RIslnNeg.value);
    Rte_swc_DiagcEveHndlg_NVM_RIslnPos_NVM_RIslnPos = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_RIslnPos_NVM_RIslnPos.value);
    Rte_MemCpy(Rte_swc_DiagcEveHndlg_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls, Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls.value, sizeof(rt_Array_Float_24));
    Rte_MemCpy(Rte_swc_DiagcEveHndlg_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln, Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln.value, sizeof(rt_Array_UInt8_255));
    Rte_swc_DiagcEveHndlg_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg.value);
    Rte_swc_DiagcEveHndlg_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg.value);
    Rte_swc_DiagcEveHndlg_NVM_SecRtcLst_NVM_SecRtcLst = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SecRtcLst_NVM_SecRtcLst.value);
    Rte_swc_DiagcEveHndlg_NVM_SocBatMax_NVM_SocBatMax = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SocBatMax_NVM_SocBatMax.value);
    Rte_swc_DiagcEveHndlg_NVM_SocBatMin_NVM_SocBatMin = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SocBatMin_NVM_SocBatMin.value);
    Rte_swc_DiagcEveHndlg_NVM_SocCnsAct_NVM_SocCnsAct = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SocCnsAct_NVM_SocCnsAct.value);
    Rte_swc_DiagcEveHndlg_NVM_SocPackScld_NVM_SocPackScld = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SocPackScld_NVM_SocPackScld.value);
    Rte_swc_DiagcEveHndlg_NVM_SocUOcIni_NVM_SocUOcIni = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SocUOcIni_NVM_SocUOcIni.value);
    Rte_swc_DiagcEveHndlg_NVM_SohCalFls_NVM_SohCalFls = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SohCalFls_NVM_SohCalFls.value);
    Rte_swc_DiagcEveHndlg_NVM_SohCycFls_NVM_SohCycFls = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SohCycFls_NVM_SohCycFls.value);
    Rte_swc_DiagcEveHndlg_NVM_SohPackFls_NVM_SohPackFls = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SohPackFls_NVM_SohPackFls.value);
    Rte_MemCpy(Rte_swc_DiagcEveHndlg_NVM_SohRDeltaFls_NVM_SohRDeltaFls, Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SohRDeltaFls_NVM_SohRDeltaFls.value, sizeof(rt_Array_Float_24));
    Rte_MemCpy(Rte_swc_DiagcEveHndlg_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls, Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls.value, sizeof(rt_Array_Float_24));
    Rte_MemCpy(Rte_swc_DiagcEveHndlg_NVM_StAryFls_NVM_StAryFls, Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_StAryFls_NVM_StAryFls.value, sizeof(rt_Array_Float_144));
    Rte_swc_DiagcEveHndlg_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax.value);
    Rte_swc_DiagcEveHndlg_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin.value);
    Rte_swc_DiagcEveHndlg_NVM_TPackFls_NVM_TPackFls = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TPackFls_NVM_TPackFls.value);
    Rte_swc_DiagcEveHndlg_NVM_TiBatAgi_NVM_TiBatAgi = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TiBatAgi_NVM_TiBatAgi.value);
    Rte_swc_DiagcEveHndlg_NVM_TiBatOffFls_NVM_TiBatOffFls = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TiBatOffFls_NVM_TiBatOffFls.value);
    Rte_MemCpy(Rte_swc_DiagcEveHndlg_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls, Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls.value, sizeof(rt_Array_UInt32_24));
    Rte_MemCpy(Rte_swc_DiagcEveHndlg_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls, Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls.value, sizeof(rt_Array_UInt32_24));
    Rte_swc_DiagcEveHndlg_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax.value);
    Rte_swc_DiagcEveHndlg_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin.value);
    Rte_swc_DiagcEveHndlg_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax.value);
    Rte_swc_DiagcEveHndlg_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin.value);
    Rte_swc_DiagcEveHndlg_NVM_UCellMax_NVM_UCellMax = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UCellMax_NVM_UCellMax.value);
    Rte_swc_DiagcEveHndlg_NVM_UCellMin_NVM_UCellMin = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UCellMin_NVM_UCellMin.value);
    Rte_swc_DiagcEveHndlg_NVM_UPrechAccumd_NVM_UPrechAccumd = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UPrechAccumd_NVM_UPrechAccumd.value);
    Rte_swc_DiagcEveHndlg_NVM_YearRtcLst_NVM_YearRtcLst = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_YearRtcLst_NVM_YearRtcLst.value);
    Rte_MemCpy(Rte_swc_DiagcEveHndlg_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls, Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls.value, sizeof(rt_Array_UInt8_24));


    Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspCause_Artificial_CrgSuspCause_Artificial.value = (UInt8)Rte_ComBuffer_CST_AbortByUser_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspCause_ChargerCond_CrgSuspCause_ChargerCond.value = (UInt8)Rte_ComBuffer_CST_AbortAchiveCondition_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspCause_Fault_CrgSuspCause_Fault.value = (UInt8)Rte_ComBuffer_CST_AbortByFault_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspError_AbnormalVoltage_CrgSuspError_AbnormalVoltage.value = (UInt8)Rte_ComBuffer_CST_AbortErrorVoltage_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspError_CurrentMismatch_CrgSuspError_CurrentMismatch.value = (UInt8)Rte_ComBuffer_CST_AbortErrorCurrent_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspFault_CannotSupply_CrgSuspFault_CannotSupply.value = (UInt8)Rte_ComBuffer_CST_AbortFaultEnergeTransmit_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspFault_ChargeConn_CrgSuspFault_ChargeConn.value = (UInt8)Rte_ComBuffer_CST_AbortFaultConnetor_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspFault_CrgTemp_CrgSuspFault_CrgTemp.value = (UInt8)Rte_ComBuffer_CST_AbortFaultChargerTemp_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspFault_CrgTempInt_CrgSuspFault_CrgTempInt.value = (UInt8)Rte_ComBuffer_CST_AbortFaultChargerInnerTemp_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspFault_OtherFault_CrgSuspFault_OtherFault.value = (UInt8)Rte_ComBuffer_CST_AbortFaultOther_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspFault_SuddenStop_CrgSuspFault_SuddenStop.value = (UInt8)Rte_ComBuffer_CST_AbortFaultChargerStop_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_HvSysSample_Current_Current.value = (SInt16)(Rte_ComBuffer_HCM_TotalCurr_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx-10000);


    Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_HvSysSample_RelayKCVoltage_RelayKCVoltage.value = (SInt32)Rte_ComBuffer_HCM_FastChgBackVolt_HCM_OtherRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;


    Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_HvSysSample_RelayKMVoltage_RelayKMVoltage.value = (SInt32)Rte_ComBuffer_HCM_MainPosBackVolt_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;


    Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_HvSysSample_RelayKNVoltage_RelayKNVoltage.value = (SInt32)Rte_ComBuffer_HCM_MainNegBackVolt_HCM_OtherRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;


    Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_HvSysSample_TotalVoltage_TotalVoltage.value = (SInt32)Rte_ComBuffer_HCM_MainPosFrtVolt_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;

    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSWIOSP_Com_CST_UpdataTime_CST_UpdataTime.value) = Rte_swc_SetInputInterface_BSWIOSP_Com_CST_UpdataTime_CST_UpdataTime;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSWIOSP_Service0x14_Count_Service0x14_Count.value) = Rte_swc_SetInputInterface_BSWIOSP_Service0x14_Count_Service0x14_Count;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSWIOSP_StsElectroniclockContor_StsElectroniclockContor.value) = Rte_swc_SetInputInterface_BSWIOSP_StsElectroniclockContor_StsElectroniclockContor;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CTC_IDriftZero_CTC_IDriftZero.value) = Rte_swc_CtctrTranCtl_CTC_IDriftZero_CTC_IDriftZero;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CTC_StLoopHv_CTC_StLoopHv.value) = Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_HvSysSample_RelayKHVoltage_RelayKHVoltage.value) = Rte_swc_SetInputInterface_HvSysSample_RelayKHVoltage_RelayKHVoltage;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_HvSysSample_RelayKNClsSts_U8_RelayKNClsSts_U8.value) = Rte_swc_SetInputInterface_HvSysSample_RelayKNClsSts_U8_RelayKNClsSts_U8;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_IPU_DischgState_IPU_DischgState.value) = Rte_ComTx_CAN_IPU_DischgState_IPU_DischgState;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_VCU_CrashOutputSts_VCU_CrashOutputSts.value) = Rte_swc_VCOP_VCU_CrashOutputSts_VCU_CrashOutputSts;
    CIL_10ms();
    Rte_swc_CIL_BSOF_AcvChManSuspd_BSOF_AcvChManSuspd = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_AcvChManSuspd_BSOF_AcvChManSuspd.value);
    Rte_swc_CIL_BSOF_AcvChSuspdByBms_BSOF_AcvChSuspdByBms = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_AcvChSuspdByBms_BSOF_AcvChSuspdByBms.value);
    Rte_swc_CIL_BSOF_AcvChSuspdCdnRchd_BSOF_AcvChSuspdCdnRchd = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_AcvChSuspdCdnRchd_BSOF_AcvChSuspdCdnRchd.value);
    Rte_swc_CIL_BSOF_AcvChSuspdFlt_BSOF_AcvChSuspdFlt = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_AcvChSuspdFlt_BSOF_AcvChSuspdFlt.value);
    Rte_swc_CIL_BSOF_ErrChImpo_BSOF_ErrChImpo = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrChImpo_BSOF_ErrChImpo.value);
    Rte_swc_CIL_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt.value);
    Rte_swc_CIL_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt.value);
    Rte_swc_CIL_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt.value);
    Rte_swc_CIL_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy.value);
    Rte_swc_CIL_BSOF_ErrIDe_BSOF_ErrIDe = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrIDe_BSOF_ErrIDe.value);
    Rte_swc_CIL_BSOF_ErrUAbno_BSOF_ErrUAbno = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrUAbno_BSOF_ErrUAbno.value);
    Rte_swc_CIL_BSOF_ErrUndfnd_BSOF_ErrUndfnd = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrUndfnd_BSOF_ErrUndfnd.value);
    Rte_swc_CIL_BSOF_bEnaMsgChrgrChSuspd_BSOF_bEnaMsgChrgrChSuspd = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_bEnaMsgChrgrChSuspd_BSOF_bEnaMsgChrgrChSuspd.value);
    Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_IBatHv_CIL_IBatHv.value);
    Rte_swc_CIL_CIL_IBatHvRaw_CIL_IBatHvRaw = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_IBatHvRaw_CIL_IBatHvRaw.value);
    Rte_swc_CIL_CIL_ModeMotDrv_CIL_ModeMotDrv = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_ModeMotDrv_CIL_ModeMotDrv.value);
    Rte_swc_CIL_CIL_StCrash_CIL_StCrash = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_StCrash_CIL_StCrash.value);
    Rte_swc_CIL_CIL_StsElectroniclockContor_CIL_StsElectroniclockContor = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_StsElectroniclockContor_CIL_StsElectroniclockContor.value);
    Rte_swc_CIL_CIL_UMainNegPoleAftRly_CIL_UMainNegPoleAftRly = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_UMainNegPoleAftRly_CIL_UMainNegPoleAftRly.value);
    Rte_swc_CIL_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly.value);
    Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value);
    Rte_swc_CIL_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh.value);
    Rte_swc_CIL_CIL_UPoleAftRlyChNeg_CIL_UPoleAftRlyChNeg = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_UPoleAftRlyChNeg_CIL_UPoleAftRlyChNeg.value);
    Rte_swc_CIL_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat.value);
    Rte_swc_CIL_CIL_bAcvRstDiag_CIL_bAcvRstDiag = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_bAcvRstDiag_CIL_bAcvRstDiag.value);
    Rte_swc_CIL_CIL_bKCNegClsSts_CIL_bKCNegClsSts = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_bKCNegClsSts_CIL_bKCNegClsSts.value);
    Rte_swc_CIL_CIL_bMainNegClsSts_CIL_bMainNegClsSts = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_bMainNegClsSts_CIL_bMainNegClsSts.value);

    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_CIL_bAcvRstDiag_CIL_bAcvRstDiag.value) = Rte_swc_CIL_CIL_bAcvRstDiag_CIL_bAcvRstDiag;
    GetEventStatus_10ms();
    Rte_swc_DiagcEveHndlg_DEH_CtrErrCfmdNv_DEH_CtrErrCfmdNv = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_CtrErrCfmdNv_DEH_CtrErrCfmdNv.value);
    Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value);
    Rte_swc_DiagcEveHndlg_DEH_ErrCfmd2_DEH_ErrCfmd2 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrCfmd2_DEH_ErrCfmd2.value);
    Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value);
    Rte_swc_DiagcEveHndlg_DEH_ErrCfmd4_DEH_ErrCfmd4 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrCfmd4_DEH_ErrCfmd4.value);
    Rte_swc_DiagcEveHndlg_DEH_ErrCfmd5_DEH_ErrCfmd5 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrCfmd5_DEH_ErrCfmd5.value);
    Rte_swc_DiagcEveHndlg_DEH_ErrCfmd6_DEH_ErrCfmd6 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrCfmd6_DEH_ErrCfmd6.value);
    Rte_swc_DiagcEveHndlg_DEH_ErrHisCfmd_DEH_ErrHisCfmd = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrHisCfmd_DEH_ErrHisCfmd.value);

    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_BSTC_StBcu_BSTC_StBcu.value) = Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_BSTC_StBcuInt_BSTC_StBcuInt.value) = Rte_swc_BcuStTranCtl_BSTC_StBcuInt_BSTC_StBcuInt;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq.value) = Rte_swc_CIL_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_CIL_StPtIndcr_CIL_StPtIndcr.value) = Rte_swc_CIL_CIL_StPtIndcr_CIL_StPtIndcr;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_CIL_UTrml30_CIL_UTrml30.value) = Rte_swc_CIL_CIL_UTrml30_CIL_UTrml30;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_CIL_bAcvRstDiag_CIL_bAcvRstDiag.value) = Rte_swc_CIL_CIL_bAcvRstDiag_CIL_bAcvRstDiag;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_CTC_StHvbat_CTC_StHvbat.value) = Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_CTC_StLoopHv_CTC_StLoopHv.value) = Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv;
    DEH_10ms();
    Rte_swc_DiagcEveHndlg_DEH_ChgLvlErr_DEH_ChgLvlErr = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_ChgLvlErr_DEH_ChgLvlErr.value);
    Rte_swc_DiagcEveHndlg_DEH_DelayDataUpldEnb_DEH_DelayDataUpldEnb = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_DelayDataUpldEnb_DEH_DelayDataUpldEnb.value);
    Rte_swc_DiagcEveHndlg_DEH_DischgLvlErr_DEH_DischgLvlErr = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_DischgLvlErr_DEH_DischgLvlErr.value);
    Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value);
    Rte_swc_DiagcEveHndlg_DEH_LvlErr_DEH_LvlErr = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_LvlErr_DEH_LvlErr.value);
    Rte_swc_DiagcEveHndlg_DEH_LvlErrSb_DEH_LvlErrSb = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_LvlErrSb_DEH_LvlErrSb.value);
    Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value);
    Rte_swc_DiagcEveHndlg_DEH_StFltLampIndcn_DEH_StFltLampIndcn = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_StFltLampIndcn_DEH_StFltLampIndcn.value);
    Rte_swc_DiagcEveHndlg_DEH_VCU_ChgFaultReq_DEH_VCU_ChgFaultReq = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_VCU_ChgFaultReq_DEH_VCU_ChgFaultReq.value);
    Rte_swc_DiagcEveHndlg_DEH_VCU_DischgFaultReq_DEH_VCU_DischgFaultReq = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_VCU_DischgFaultReq_DEH_VCU_DischgFaultReq.value);
    Rte_swc_DiagcEveHndlg_DEH_ValCodDiag_DEH_ValCodDiag = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_ValCodDiag_DEH_ValCodDiag.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvAcChInh_DEH_bAcvAcChInh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvAcChInh_DEH_bAcvAcChInh.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvAcPwrChInh_DEH_bAcvAcPwrChInh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvAcPwrChInh_DEH_bAcvAcPwrChInh.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvChInh_DEH_bAcvChInh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvChInh_DEH_bAcvChInh.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvDcChInh_DEH_bAcvDcChInh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvDcChInh_DEH_bAcvDcChInh.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvDcPwrChInh_DEH_bAcvDcPwrChInh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvDcPwrChInh_DEH_bAcvDcPwrChInh.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvDchaInh_DEH_bAcvDchaInh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvDchaInh_DEH_bAcvDchaInh.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvEmcyHvOff1_DEH_bAcvEmcyHvOff1 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvEmcyHvOff1_DEH_bAcvEmcyHvOff1.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvEmcyHvOff2_DEH_bAcvEmcyHvOff2 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvEmcyHvOff2_DEH_bAcvEmcyHvOff2.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvHeatInh_DEH_bAcvHeatInh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvHeatInh_DEH_bAcvHeatInh.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvLvlErrSb1_DEH_bAcvLvlErrSb1 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvLvlErrSb1_DEH_bAcvLvlErrSb1.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvLvlErrSb2_DEH_bAcvLvlErrSb2 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvLvlErrSb2_DEH_bAcvLvlErrSb2.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvLvlErrSb3_DEH_bAcvLvlErrSb3 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvLvlErrSb3_DEH_bAcvLvlErrSb3.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvPowupInh_DEH_bAcvPowupInh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPowupInh_DEH_bAcvPowupInh.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvPwrDchaLim1_DEH_bAcvPwrDchaLim1 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrDchaLim1_DEH_bAcvPwrDchaLim1.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvPwrDchaLim2_DEH_bAcvPwrDchaLim2 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrDchaLim2_DEH_bAcvPwrDchaLim2.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvPwrRecupLim1_DEH_bAcvPwrRecupLim1 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrRecupLim1_DEH_bAcvPwrRecupLim1.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvPwrRecupLim2_DEH_bAcvPwrRecupLim2 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrRecupLim2_DEH_bAcvPwrRecupLim2.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvPwrdNorm_DEH_bAcvPwrdNorm = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrdNorm_DEH_bAcvPwrdNorm.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvRecupInh_DEH_bAcvRecupInh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvRecupInh_DEH_bAcvRecupInh.value);
    Rte_swc_DiagcEveHndlg_DEH_bAcvSleepNorm_DEH_bAcvSleepNorm = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvSleepNorm_DEH_bAcvSleepNorm.value);

    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BBC_bAcvBaln_BBC_bAcvBaln.value) = Rte_swc_BatBalnCtl_BBC_bAcvBaln_BBC_bAcvBaln;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BCC_StAcSys_BCC_StAcSys.value) = Rte_swc_BatChCtl_BCC_StAcSys_BCC_StAcSys;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BPIU_StCellUChkOverMax_BPIU_StCellUChkOverMax.value) = Rte_swc_BatProtnIU_BPIU_StCellUChkOverMax_BPIU_StCellUChkOverMax;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BPIU_StCellUChkOverMin_BPIU_StCellUChkOverMin.value) = Rte_swc_BatProtnIU_BPIU_StCellUChkOverMin_BPIU_StCellUChkOverMin;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BPIU_StChkUMax_BPIU_StChkUMax.value) = Rte_swc_BatProtnIU_BPIU_StChkUMax_BPIU_StChkUMax;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BPIU_StChkUMin_BPIU_StChkUMin.value) = Rte_swc_BatProtnIU_BPIU_StChkUMin_BPIU_StChkUMin;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BTHM_StErrTOver_BTHM_StErrTOver.value) = Rte_swc_BatThermHndlgMngt_BTHM_StErrTOver_BTHM_StErrTOver;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_DayRtc_CIL_DayRtc.value) = Rte_swc_CIL_CIL_DayRtc_CIL_DayRtc;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_HourRtc_CIL_HourRtc.value) = Rte_swc_CIL_CIL_HourRtc_CIL_HourRtc;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_IBatHv_CIL_IBatHv.value) = Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_MinuRtc_CIL_MinuRtc.value) = Rte_swc_CIL_CIL_MinuRtc_CIL_MinuRtc;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_ModeSysWup_CIL_ModeSysWup.value) = Rte_swc_CIL_CIL_ModeSysWup_CIL_ModeSysWup;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_MonthRtc_CIL_MonthRtc.value) = Rte_swc_CIL_CIL_MonthRtc_CIL_MonthRtc;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_SecRtc_CIL_SecRtc.value) = Rte_swc_CIL_CIL_SecRtc_CIL_SecRtc;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_SpdVeh_CIL_SpdVeh.value) = Rte_swc_CIL_CIL_SpdVeh_CIL_SpdVeh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_StBatHvReq_CIL_StBatHvReq.value) = Rte_swc_CIL_CIL_StBatHvReq_CIL_StBatHvReq;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_StBatLvCutoffReq_CIL_StBatLvCutoffReq.value) = Rte_swc_CIL_CIL_StBatLvCutoffReq_CIL_StBatLvCutoffReq;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_StChWup_CIL_StChWup.value) = Rte_swc_CIL_CIL_StChWup_CIL_StChWup;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_StMsgToutForPMS_CIL_StMsgToutForPMS.value) = Rte_swc_CIL_CIL_StMsgToutForPMS_CIL_StMsgToutForPMS;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_StRtcFlt_CIL_StRtcFlt.value) = Rte_swc_CIL_CIL_StRtcFlt_CIL_StRtcFlt;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_StTrml15_CIL_StTrml15.value) = Rte_swc_CIL_CIL_StTrml15_CIL_StTrml15;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_YearRtc_CIL_YearRtc.value) = Rte_swc_CIL_CIL_YearRtc_CIL_YearRtc;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_bCANWakeUp_CIL_bCANWakeUp.value) = Rte_swc_CIL_CIL_bCANWakeUp_CIL_bCANWakeUp;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_bRdyBswStoreFnshd_CIL_bRdyBswStoreFnshd.value) = Rte_swc_CIL_CIL_bRdyBswStoreFnshd_CIL_bRdyBswStoreFnshd;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg.value) = Rte_swc_CIL_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg.value) = Rte_swc_CIL_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CTC_ReqRlyCh_CTC_ReqRlyCh.value) = Rte_swc_CtctrTranCtl_CTC_ReqRlyCh_CTC_ReqRlyCh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CTC_StHvbat_CTC_StHvbat.value) = Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CTC_StLoopHv_CTC_StLoopHv.value) = Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CTC_StRlyChkCh_CTC_StRlyChkCh.value) = Rte_swc_CtctrTranCtl_CTC_StRlyChkCh_CTC_StRlyChkCh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CTC_StRlyChkHeat_CTC_StRlyChkHeat.value) = Rte_swc_CtctrTranCtl_CTC_StRlyChkHeat_CTC_StRlyChkHeat;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CTC_StRlyChkPos_CTC_StRlyChkPos.value) = Rte_swc_CtctrTranCtl_CTC_StRlyChkPos_CTC_StRlyChkPos;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CTC_bAcvBswCtl_CTC_bAcvBswCtl.value) = Rte_swc_CtctrTranCtl_CTC_bAcvBswCtl_CTC_bAcvBswCtl;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CTC_bAcvCh_CTC_bAcvCh.value) = Rte_swc_CtctrTranCtl_CTC_bAcvCh_CTC_bAcvCh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CTC_bAcvTrml15Chk_CTC_bAcvTrml15Chk.value) = Rte_swc_CtctrTranCtl_CTC_bAcvTrml15Chk_CTC_bAcvTrml15Chk;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_CtrHvOffReqDiag_DEH_CtrHvOffReqDiag.value) = Rte_swc_DiagcEveHndlg_DEH_CtrHvOffReqDiag_DEH_CtrHvOffReqDiag;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag.value) = Rte_swc_DiagcEveHndlg_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_ErrCfmd2_DEH_ErrCfmd2.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd2_DEH_ErrCfmd2;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_ErrCfmd5_DEH_ErrCfmd5.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd5_DEH_ErrCfmd5;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_StsIninNv_DEH_StsIninNv.value) = Rte_swc_DiagcEveHndlg_DEH_StsIninNv_DEH_StsIninNv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_bAcvBdNew_DEH_bAcvBdNew.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvBdNew_DEH_bAcvBdNew;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_bAcvEmcyHvOff1_DEH_bAcvEmcyHvOff1.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvEmcyHvOff1_DEH_bAcvEmcyHvOff1;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_bAcvEmcyHvOff2_DEH_bAcvEmcyHvOff2.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvEmcyHvOff2_DEH_bAcvEmcyHvOff2;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_ELHPN_StCrash_ELHPN_StCrash.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StCrash_ELHPN_StCrash;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_ELHPN_StCrashIni_ELHPN_StCrashIni.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StCrashIni_ELHPN_StCrashIni;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_ELHPN_StErrIniHvIntlc2_ELHPN_StErrIniHvIntlc2.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrIniHvIntlc2_ELHPN_StErrIniHvIntlc2;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_NVM_DayRtcLst_NVM_DayRtcLst.value) = Rte_swc_DiagcEveHndlg_NVM_DayRtcLst_NVM_DayRtcLst;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_NVM_HourRtcLst_NVM_HourRtcLst.value) = Rte_swc_DiagcEveHndlg_NVM_HourRtcLst_NVM_HourRtcLst;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_NVM_MinuRtcLst_NVM_MinuRtcLst.value) = Rte_swc_DiagcEveHndlg_NVM_MinuRtcLst_NVM_MinuRtcLst;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_NVM_MonthRtcLst_NVM_MonthRtcLst.value) = Rte_swc_DiagcEveHndlg_NVM_MonthRtcLst_NVM_MonthRtcLst;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_NVM_SecRtcLst_NVM_SecRtcLst.value) = Rte_swc_DiagcEveHndlg_NVM_SecRtcLst_NVM_SecRtcLst;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_NVM_YearRtcLst_NVM_YearRtcLst.value) = Rte_swc_DiagcEveHndlg_NVM_YearRtcLst_NVM_YearRtcLst;
    BSTC_10ms();
    Rte_swc_BcuStTranCtl_BSTC_DayRtcLstNv_BSTC_DayRtcLstNv = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_DayRtcLstNv_BSTC_DayRtcLstNv.value);
    Rte_swc_BcuStTranCtl_BSTC_DelayTime_BSTC_DelayTime = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_DelayTime_BSTC_DelayTime.value);
    Rte_swc_BcuStTranCtl_BSTC_ErrInfo_BSTC_ErrInfo = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_ErrInfo_BSTC_ErrInfo.value);
    Rte_swc_BcuStTranCtl_BSTC_HourRtcLstNv_BSTC_HourRtcLstNv = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_HourRtcLstNv_BSTC_HourRtcLstNv.value);
    Rte_swc_BcuStTranCtl_BSTC_MinuRtcLstNv_BSTC_MinuRtcLstNv = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_MinuRtcLstNv_BSTC_MinuRtcLstNv.value);
    Rte_swc_BcuStTranCtl_BSTC_ModeBmsAcvn_BSTC_ModeBmsAcvn = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_ModeBmsAcvn_BSTC_ModeBmsAcvn.value);
    Rte_swc_BcuStTranCtl_BSTC_MonthRtcLstNv_BSTC_MonthRtcLstNv = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_MonthRtcLstNv_BSTC_MonthRtcLstNv.value);
    Rte_swc_BcuStTranCtl_BSTC_ReqEmcyHvOffFromBms_BSTC_ReqEmcyHvOffFromBms = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_ReqEmcyHvOffFromBms_BSTC_ReqEmcyHvOffFromBms.value);
    Rte_swc_BcuStTranCtl_BSTC_ReqEmcyHvOffFromVcu_BSTC_ReqEmcyHvOffFromVcu = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_ReqEmcyHvOffFromVcu_BSTC_ReqEmcyHvOffFromVcu.value);
    Rte_swc_BcuStTranCtl_BSTC_ReqShtdnBas_BSTC_ReqShtdnBas = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_ReqShtdnBas_BSTC_ReqShtdnBas.value);
    Rte_swc_BcuStTranCtl_BSTC_RstCmd_BSTC_RstCmd = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_RstCmd_BSTC_RstCmd.value);
    Rte_swc_BcuStTranCtl_BSTC_RstCmd100_BSTC_RstCmd100 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_RstCmd100_BSTC_RstCmd100.value);
    Rte_swc_BcuStTranCtl_BSTC_SecRtcLstNv_BSTC_SecRtcLstNv = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_SecRtcLstNv_BSTC_SecRtcLstNv.value);
    Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_StBcu_BSTC_StBcu.value);
    Rte_swc_BcuStTranCtl_BSTC_StBcuInt_BSTC_StBcuInt = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_StBcuInt_BSTC_StBcuInt.value);
    Rte_swc_BcuStTranCtl_BSTC_StBmsChk_BSTC_StBmsChk = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_StBmsChk_BSTC_StBmsChk.value);
    Rte_swc_BcuStTranCtl_BSTC_TiBatOff_BSTC_TiBatOff = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_TiBatOff_BSTC_TiBatOff.value);
    Rte_swc_BcuStTranCtl_BSTC_TiBatOn_BSTC_TiBatOn = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_TiBatOn_BSTC_TiBatOn.value);
    Rte_swc_BcuStTranCtl_BSTC_TrigCh_BSTC_TrigCh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_TrigCh_BSTC_TrigCh.value);
    Rte_swc_BcuStTranCtl_BSTC_YearRtcLstNv_BSTC_YearRtcLstNv = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_YearRtcLstNv_BSTC_YearRtcLstNv.value);
    Rte_swc_BcuStTranCtl_BSTC_bAcvCutoffLvFromBms_BSTC_bAcvCutoffLvFromBms = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvCutoffLvFromBms_BSTC_bAcvCutoffLvFromBms.value);
    Rte_swc_BcuStTranCtl_BSTC_bAcvDcStChToStHvOffNorm_BSTC_bAcvDcStChToStHvOffNorm = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvDcStChToStHvOffNorm_BSTC_bAcvDcStChToStHvOffNorm.value);
    Rte_swc_BcuStTranCtl_BSTC_bAcvHvOffNormFromVcu_BSTC_bAcvHvOffNormFromVcu = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvHvOffNormFromVcu_BSTC_bAcvHvOffNormFromVcu.value);
    Rte_swc_BcuStTranCtl_BSTC_bAcvObcOff_BSTC_bAcvObcOff = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvObcOff_BSTC_bAcvObcOff.value);
    Rte_swc_BcuStTranCtl_BSTC_bAcvStDchaToStHvOffNorm_BSTC_bAcvStDchaToStHvOffNorm = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvStDchaToStHvOffNorm_BSTC_bAcvStDchaToStHvOffNorm.value);
    Rte_swc_BcuStTranCtl_BSTC_bAcvStRunToStHvOffEmcy_BSTC_bAcvStRunToStHvOffEmcy = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvStRunToStHvOffEmcy_BSTC_bAcvStRunToStHvOffEmcy.value);
    Rte_swc_BcuStTranCtl_BSTC_bAcvStStbToStAftRun_BSTC_bAcvStStbToStAftRun = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvStStbToStAftRun_BSTC_bAcvStStbToStAftRun.value);
    Rte_swc_BcuStTranCtl_BSTC_bErrHvOffAbno_BSTC_bErrHvOffAbno = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bErrHvOffAbno_BSTC_bErrHvOffAbno.value);
    Rte_swc_BcuStTranCtl_BSTC_bErrPwrOff_BSTC_bErrPwrOff = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bErrPwrOff_BSTC_bErrPwrOff.value);
    Rte_swc_BcuStTranCtl_BSTC_bErrToutForRxCutoffLvReq_BSTC_bErrToutForRxCutoffLvReq = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bErrToutForRxCutoffLvReq_BSTC_bErrToutForRxCutoffLvReq.value);
    Rte_swc_BcuStTranCtl_BSTC_bErrToutForRxHvOffReq_BSTC_bErrToutForRxHvOffReq = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bErrToutForRxHvOffReq_BSTC_bErrToutForRxHvOffReq.value);

    Rte_MemCpy(Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCF_CMdulAbsv_BCF_CMdulAbsv.value, Rte_swc_BatCoreFct_BCF_CMdulAbsv_BCF_CMdulAbsv, sizeof(rt_Array_Float_24));
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCF_IChLim_BCF_IChLim.value) = Rte_swc_BatCoreFct_BCF_IChLim_BCF_IChLim;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCF_SocPack_BCF_SocPack.value) = Rte_swc_BatCoreFct_BCF_SocPack_BCF_SocPack;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCF_SocPackScld_BCF_SocPackScld.value) = Rte_swc_BatCoreFct_BCF_SocPackScld_BCF_SocPackScld;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCF_SohPack_BCF_SohPack.value) = Rte_swc_BatCoreFct_BCF_SohPack_BCF_SohPack;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value) = Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BPIU_UCellMax_BPIU_UCellMax.value) = Rte_swc_BatProtnIU_BPIU_UCellMax_BPIU_UCellMax;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg.value) = Rte_swc_CIL_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BTHM_StSys_BTHM_StSys.value) = Rte_swc_BatThermHndlgMngt_BTHM_StSys_BTHM_StSys;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr.value) = Rte_swc_BatThermHndlgMngt_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr.value) = Rte_swc_BatThermHndlgMngt_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BTHM_TPack_BTHM_TPack.value) = Rte_swc_BatThermHndlgMngt_BTHM_TPack_BTHM_TPack;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_CIL_BatCoolType_CIL_BatCoolType.value) = Rte_swc_CIL_CIL_BatCoolType_CIL_BatCoolType;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_CIL_IBatHv_CIL_IBatHv.value) = Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_CIL_StAcChCnct_CIL_StAcChCnct.value) = Rte_swc_CIL_CIL_StAcChCnct_CIL_StAcChCnct;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_CIL_StChWup_CIL_StChWup.value) = Rte_swc_CIL_CIL_StChWup_CIL_StChWup;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_CTC_StHvbat_CTC_StHvbat.value) = Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_DEH_bAcvChInh_DEH_bAcvChInh.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvChInh_DEH_bAcvChInh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_DEH_bAcvDcChInh_DEH_bAcvDcChInh.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvDcChInh_DEH_bAcvDcChInh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_MCC_NrCellTot_MCC_NrCellTot.value) = Rte_swc_CIL_MCC_NrCellTot_MCC_NrCellTot;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_MCC_NrMdulTot_MCC_NrMdulTot.value) = Rte_swc_CIL_MCC_NrMdulTot_MCC_NrMdulTot;
    BCC_10ms();
    Rte_swc_BatChCtl_BCC_AcvCellURchd_BCC_AcvCellURchd = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_AcvCellURchd_BCC_AcvCellURchd.value);
    Rte_swc_BatChCtl_BCC_AcvSocRchd_BCC_AcvSocRchd = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_AcvSocRchd_BCC_AcvSocRchd.value);
    Rte_swc_BatChCtl_BCC_AcvUTotRchd_BCC_AcvUTotRchd = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_AcvUTotRchd_BCC_AcvUTotRchd.value);
    Rte_swc_BatChCtl_BCC_EChSng_BCC_EChSng = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_EChSng_BCC_EChSng.value);
    Rte_swc_BatChCtl_BCC_IChReq_BCC_IChReq = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_IChReq_BCC_IChReq.value);
    Rte_swc_BatChCtl_BCC_IDchaReq_BCC_IDchaReq = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_IDchaReq_BCC_IDchaReq.value);
    Rte_swc_BatChCtl_BCC_ModeCh_BCC_ModeCh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_ModeCh_BCC_ModeCh.value);
    Rte_swc_BatChCtl_BCC_StCh_BCC_StCh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_StCh_BCC_StCh.value);
    Rte_swc_BatChCtl_BCC_UChReq_BCC_UChReq = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_UChReq_BCC_UChReq.value);
    Rte_swc_BatChCtl_BCC_bAcvHvbatFull_BCC_bAcvHvbatFull = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_bAcvHvbatFull_BCC_bAcvHvbatFull.value);
    Rte_swc_BatChCtl_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot.value);
    Rte_swc_BatChCtl_BCTE_TiBatChMaxByHour_BCTE_TiBatChMaxByHour = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCTE_TiBatChMaxByHour_BCTE_TiBatChMaxByHour.value);
    Rte_swc_BatChCtl_BCTE_TiBatChMaxByMinu_BCTE_TiBatChMaxByMinu = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCTE_TiBatChMaxByMinu_BCTE_TiBatChMaxByMinu.value);
    Rte_swc_BatChCtl_BCTE_TiBatDchaByMinuTot_BCTE_TiBatDchaByMinuTot = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCTE_TiBatDchaByMinuTot_BCTE_TiBatDchaByMinuTot.value);

    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCF_SocPackScld_BCF_SocPackScld.value) = Rte_swc_BatCoreFct_BCF_SocPackScld_BCF_SocPackScld;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value) = Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg.value) = Rte_swc_CIL_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BSTC_StBcu_BSTC_StBcu.value) = Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BTHM_ErrChEnd_BTHM_ErrChEnd.value) = Rte_swc_BatThermHndlgMngt_BTHM_ErrChEnd_BTHM_ErrChEnd;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BTHM_StSys_BTHM_StSys.value) = Rte_swc_BatThermHndlgMngt_BTHM_StSys_BTHM_StSys;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax.value) = Rte_swc_CIL_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_CP_Vol_CIL_CP_Vol.value) = Rte_swc_CIL_CIL_CP_Vol_CIL_CP_Vol;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_ChrgSoftSwCtrlSt_CIL_ChrgSoftSwCtrlSt.value) = Rte_swc_CIL_CIL_ChrgSoftSwCtrlSt_CIL_ChrgSoftSwCtrlSt;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_DoorLockStatusDrv_CIL_DoorLockStatusDrv.value) = Rte_swc_CIL_CIL_DoorLockStatusDrv_CIL_DoorLockStatusDrv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_DoorLockStatusPass_CIL_DoorLockStatusPass.value) = Rte_swc_CIL_CIL_DoorLockStatusPass_CIL_DoorLockStatusPass;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_DucycCtlPilot_CIL_DucycCtlPilot.value) = Rte_swc_CIL_CIL_DucycCtlPilot_CIL_DucycCtlPilot;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_ErrAcScktSnsrT_CIL_ErrAcScktSnsrT.value) = Rte_swc_CIL_CIL_ErrAcScktSnsrT_CIL_ErrAcScktSnsrT;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_IBatHv_CIL_IBatHv.value) = Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_IDcdcLvAct_CIL_IDcdcLvAct.value) = Rte_swc_CIL_CIL_IDcdcLvAct_CIL_IDcdcLvAct;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_OnBdCPline_CIL_OnBdCPline.value) = Rte_swc_CIL_CIL_OnBdCPline_CIL_OnBdCPline;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline.value) = Rte_swc_CIL_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_PwrEACAct_CIL_PwrEACAct.value) = Rte_swc_CIL_CIL_PwrEACAct_CIL_PwrEACAct;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_PwrPtcAct_CIL_PwrPtcAct.value) = Rte_swc_CIL_CIL_PwrPtcAct_CIL_PwrPtcAct;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_RAcChCnctn_CIL_RAcChCnctn.value) = Rte_swc_CIL_CIL_RAcChCnctn_CIL_RAcChCnctn;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_RDisChCnctn_CIL_RDisChCnctn.value) = Rte_swc_CIL_CIL_RDisChCnctn_CIL_RDisChCnctn;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_ReservationChrgnSts_CIL_ReservationChrgnSts.value) = Rte_swc_CIL_CIL_ReservationChrgnSts_CIL_ReservationChrgnSts;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_StAcChCnct_CIL_StAcChCnct.value) = Rte_swc_CIL_CIL_StAcChCnct_CIL_StAcChCnct;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_StBatHvReq_CIL_StBatHvReq.value) = Rte_swc_CIL_CIL_StBatHvReq_CIL_StBatHvReq;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_StChAllwd_CIL_StChAllwd.value) = Rte_swc_CIL_CIL_StChAllwd_CIL_StChAllwd;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_StChWup_CIL_StChWup.value) = Rte_swc_CIL_CIL_StChWup_CIL_StChWup;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_StMsgToutForObc_CIL_StMsgToutForObc.value) = Rte_swc_CIL_CIL_StMsgToutForObc_CIL_StMsgToutForObc;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_StObc_CIL_StObc.value) = Rte_swc_CIL_CIL_StObc_CIL_StObc;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_StsElectroniclockContor_CIL_StsElectroniclockContor.value) = Rte_swc_CIL_CIL_StsElectroniclockContor_CIL_StsElectroniclockContor;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_TAcChPointNeg_CIL_TAcChPointNeg.value) = Rte_swc_CIL_CIL_TAcChPointNeg_CIL_TAcChPointNeg;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_TAcChPointPos_CIL_TAcChPointPos.value) = Rte_swc_CIL_CIL_TAcChPointPos_CIL_TAcChPointPos;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_UDcdcLvAct_CIL_UDcdcLvAct.value) = Rte_swc_CIL_CIL_UDcdcLvAct_CIL_UDcdcLvAct;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_UObcChInp_CIL_UObcChInp.value) = Rte_swc_CIL_CIL_UObcChInp_CIL_UObcChInp;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CTC_StHvbat_CTC_StHvbat.value) = Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CTC_StLoopHv_CTC_StLoopHv.value) = Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_DEH_bAcvAcChInh_DEH_bAcvAcChInh.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvAcChInh_DEH_bAcvAcChInh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_DEH_bAcvAcPwrChInh_DEH_bAcvAcPwrChInh.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvAcPwrChInh_DEH_bAcvAcPwrChInh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_DEH_bAcvChInh_DEH_bAcvChInh.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvChInh_DEH_bAcvChInh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2;
    AC_10ms();
    Rte_swc_BatChCtl_BCC_ChgCCSts_BCC_ChgCCSts = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_ChgCCSts_BCC_ChgCCSts.value);
    Rte_swc_BatChCtl_BCC_ElectroniclockContorFault_BCC_ElectroniclockContorFault = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_ElectroniclockContorFault_BCC_ElectroniclockContorFault.value);
    Rte_swc_BatChCtl_BCC_ElectroniclockContorREQ_BCC_ElectroniclockContorREQ = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_ElectroniclockContorREQ_BCC_ElectroniclockContorREQ.value);
    Rte_swc_BatChCtl_BCC_ElectroniclockSt_BCC_ElectroniclockSt = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_ElectroniclockSt_BCC_ElectroniclockSt.value);
    Rte_swc_BatChCtl_BCC_IObcLimn_BCC_IObcLimn = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_IObcLimn_BCC_IObcLimn.value);
    Rte_swc_BatChCtl_BCC_StAcChReq_BCC_StAcChReq = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_StAcChReq_BCC_StAcChReq.value);
    Rte_swc_BatChCtl_BCC_StAcSys_BCC_StAcSys = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_StAcSys_BCC_StAcSys.value);
    Rte_swc_BatChCtl_BCC_TranAcChEndByBatHvReq_BCC_TranAcChEndByBatHvReq = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_TranAcChEndByBatHvReq_BCC_TranAcChEndByBatHvReq.value);
    Rte_swc_BatChCtl_BCC_UObcLimn_BCC_UObcLimn = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_UObcLimn_BCC_UObcLimn.value);
    Rte_swc_BatChCtl_BCC_bAcvDig10_BCC_bAcvDig10 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_bAcvDig10_BCC_bAcvDig10.value);
    Rte_swc_BatChCtl_BCC_bS2Ctrl_BCC_bS2Ctrl = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_bS2Ctrl_BCC_bS2Ctrl.value);

    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BCF_SocPack_BCF_SocPack.value) = Rte_swc_BatCoreFct_BCF_SocPack_BCF_SocPack;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BCF_SocPackScld_BCF_SocPackScld.value) = Rte_swc_BatCoreFct_BCF_SocPackScld_BCF_SocPackScld;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value) = Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BPP_IAct_BPP_IAct.value) = Rte_swc_BatProtnPack_BPP_IAct_BPP_IAct;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_DirChAndDcha_BSOF_DirChAndDcha.value) = Rte_swc_CIL_BSOF_DirChAndDcha_BSOF_DirChAndDcha;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_ErrChImpo_BSOF_ErrChImpo.value) = Rte_swc_CIL_BSOF_ErrChImpo_BSOF_ErrChImpo;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt.value) = Rte_swc_CIL_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt.value) = Rte_swc_CIL_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt.value) = Rte_swc_CIL_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy.value) = Rte_swc_CIL_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_ErrUndfnd_BSOF_ErrUndfnd.value) = Rte_swc_CIL_BSOF_ErrUndfnd_BSOF_ErrUndfnd;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_IChrgrMax_BSOF_IChrgrMax.value) = Rte_swc_CIL_BSOF_IChrgrMax_BSOF_IChrgrMax;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_IChrgrMin_BSOF_IChrgrMin.value) = Rte_swc_CIL_BSOF_IChrgrMin_BSOF_IChrgrMin;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_MsgChrgrRcgtn_BSOF_MsgChrgrRcgtn.value) = Rte_swc_CIL_BSOF_MsgChrgrRcgtn_BSOF_MsgChrgrRcgtn;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_MsgChrgrRdy_BSOF_MsgChrgrRdy.value) = Rte_swc_CIL_BSOF_MsgChrgrRdy_BSOF_MsgChrgrRdy;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_UChrgrMax_BSOF_UChrgrMax.value) = Rte_swc_CIL_BSOF_UChrgrMax_BSOF_UChrgrMax;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_UChrgrMin_BSOF_UChrgrMin.value) = Rte_swc_CIL_BSOF_UChrgrMin_BSOF_UChrgrMin;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_UDchaMax_BSOF_UDchaMax.value) = Rte_swc_CIL_BSOF_UDchaMax_BSOF_UDchaMax;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_UDchaMin_BSOF_UDchaMin.value) = Rte_swc_CIL_BSOF_UDchaMin_BSOF_UDchaMin;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg.value) = Rte_swc_CIL_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrChDetd_BSOF_bEnaMsgChrgrChDetd.value) = Rte_swc_CIL_BSOF_bEnaMsgChrgrChDetd_BSOF_bEnaMsgChrgrChDetd;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrChSt_BSOF_bEnaMsgChrgrChSt.value) = Rte_swc_CIL_BSOF_bEnaMsgChrgrChSt_BSOF_bEnaMsgChrgrChSt;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrChSuspd_BSOF_bEnaMsgChrgrChSuspd.value) = Rte_swc_CIL_BSOF_bEnaMsgChrgrChSuspd_BSOF_bEnaMsgChrgrChSuspd;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrDetnCnct_BSOF_bEnaMsgChrgrDetnCnct.value) = Rte_swc_CIL_BSOF_bEnaMsgChrgrDetnCnct_BSOF_bEnaMsgChrgrDetnCnct;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrErr_BSOF_bEnaMsgChrgrErr.value) = Rte_swc_CIL_BSOF_bEnaMsgChrgrErr_BSOF_bEnaMsgChrgrErr;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrHdshk_BSOF_bEnaMsgChrgrHdshk.value) = Rte_swc_CIL_BSOF_bEnaMsgChrgrHdshk_BSOF_bEnaMsgChrgrHdshk;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrMaxOut_BSOF_bEnaMsgChrgrMaxOut.value) = Rte_swc_CIL_BSOF_bEnaMsgChrgrMaxOut_BSOF_bEnaMsgChrgrMaxOut;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrMaxOutPgtn_BSOF_bEnaMsgChrgrMaxOutPgtn.value) = Rte_swc_CIL_BSOF_bEnaMsgChrgrMaxOutPgtn_BSOF_bEnaMsgChrgrMaxOutPgtn;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrRcgtn_BSOF_bEnaMsgChrgrRcgtn.value) = Rte_swc_CIL_BSOF_bEnaMsgChrgrRcgtn_BSOF_bEnaMsgChrgrRcgtn;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrRdy_BSOF_bEnaMsgChrgrRdy.value) = Rte_swc_CIL_BSOF_bEnaMsgChrgrRdy_BSOF_bEnaMsgChrgrRdy;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrStstc_BSOF_bEnaMsgChrgrStstc.value) = Rte_swc_CIL_BSOF_bEnaMsgChrgrStstc_BSOF_bEnaMsgChrgrStstc;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrStstcForPgtn_BSOF_bEnaMsgChrgrStstcForPgtn.value) = Rte_swc_CIL_BSOF_bEnaMsgChrgrStstcForPgtn_BSOF_bEnaMsgChrgrStstcForPgtn;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bErrMsgTout_BSOF_bErrMsgTout.value) = Rte_swc_CIL_BSOF_bErrMsgTout_BSOF_bErrMsgTout;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSTC_StBcu_BSTC_StBcu.value) = Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BTHM_ErrChEnd_BTHM_ErrChEnd.value) = Rte_swc_BatThermHndlgMngt_BTHM_ErrChEnd_BTHM_ErrChEnd;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BTHM_StSys_BTHM_StSys.value) = Rte_swc_BatThermHndlgMngt_BTHM_StSys_BTHM_StSys;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax.value) = Rte_swc_CIL_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_ChgCCSts_CIL_ChgCCSts.value) = Rte_swc_CIL_CIL_ChgCCSts_CIL_ChgCCSts;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_ElockStmodeOBC_CIL_ElockStmodeOBC.value) = Rte_swc_CIL_CIL_ElockStmodeOBC_CIL_ElockStmodeOBC;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_ErrDcScktSnsrT_CIL_ErrDcScktSnsrT.value) = Rte_swc_CIL_CIL_ErrDcScktSnsrT_CIL_ErrDcScktSnsrT;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_IDcdcLvAct_CIL_IDcdcLvAct.value) = Rte_swc_CIL_CIL_IDcdcLvAct_CIL_IDcdcLvAct;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_PwrEACAct_CIL_PwrEACAct.value) = Rte_swc_CIL_CIL_PwrEACAct_CIL_PwrEACAct;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_PwrPtcAct_CIL_PwrPtcAct.value) = Rte_swc_CIL_CIL_PwrPtcAct_CIL_PwrPtcAct;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_StAcChCnct_CIL_StAcChCnct.value) = Rte_swc_CIL_CIL_StAcChCnct_CIL_StAcChCnct;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_StBatHvReq_CIL_StBatHvReq.value) = Rte_swc_CIL_CIL_StBatHvReq_CIL_StBatHvReq;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_StChAllwd_CIL_StChAllwd.value) = Rte_swc_CIL_CIL_StChAllwd_CIL_StChAllwd;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_StChWup_CIL_StChWup.value) = Rte_swc_CIL_CIL_StChWup_CIL_StChWup;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_TDcChPointNeg_CIL_TDcChPointNeg.value) = Rte_swc_CIL_CIL_TDcChPointNeg_CIL_TDcChPointNeg;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_TDcChPointPos_CIL_TDcChPointPos.value) = Rte_swc_CIL_CIL_TDcChPointPos_CIL_TDcChPointPos;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_UDcdcLvAct_CIL_UDcdcLvAct.value) = Rte_swc_CIL_CIL_UDcdcLvAct_CIL_UDcdcLvAct;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CTC_StHvbat_CTC_StHvbat.value) = Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CTC_StLoopHv_CTC_StLoopHv.value) = Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CTC_StRlyCh_CTC_StRlyCh.value) = Rte_swc_CtctrTranCtl_CTC_StRlyCh_CTC_StRlyCh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CTC_StSysInt_CTC_StSysInt.value) = Rte_swc_CtctrTranCtl_CTC_StSysInt_CTC_StSysInt;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_ErrCfmd4_DEH_ErrCfmd4.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd4_DEH_ErrCfmd4;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_bAcvChInh_DEH_bAcvChInh.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvChInh_DEH_bAcvChInh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_bAcvDcChInh_DEH_bAcvDcChInh.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvDcChInh_DEH_bAcvDcChInh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_bAcvDcPwrChInh_DEH_bAcvDcPwrChInh.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvDcPwrChInh_DEH_bAcvDcPwrChInh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_ELHPN_StIsln_ELHPN_StIsln.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StIsln_ELHPN_StIsln;
    DC_10ms();
    Rte_swc_BatChCtl_BCC_ErrInfo_BCC_ErrInfo = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BCC_ErrInfo_BCC_ErrInfo.value);
    Rte_swc_BatChCtl_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq.value);
    Rte_swc_BatChCtl_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr.value);
    Rte_swc_BatChCtl_EVCSH_ChMode_EVCSH_ChMode = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ChMode_EVCSH_ChMode.value);
    Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChRdy_EVCSH_ErrMsgChrgrChRdy = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrChRdy_EVCSH_ErrMsgChrgrChRdy.value);
    Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChSts_EVCSH_ErrMsgChrgrChSts = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrChSts_EVCSH_ErrMsgChrgrChSts.value);
    Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChStstc_EVCSH_ErrMsgChrgrChStstc = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrChStstc_EVCSH_ErrMsgChrgrChStstc.value);
    Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChSuspd_EVCSH_ErrMsgChrgrChSuspd = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrChSuspd_EVCSH_ErrMsgChrgrChSuspd.value);
    Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrIdfcNotRdy_EVCSH_ErrMsgChrgrIdfcNotRdy = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrIdfcNotRdy_EVCSH_ErrMsgChrgrIdfcNotRdy.value);
    Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrIdfcRdy_EVCSH_ErrMsgChrgrIdfcRdy = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrIdfcRdy_EVCSH_ErrMsgChrgrIdfcRdy.value);
    Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrSync_EVCSH_ErrMsgChrgrSync = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrSync_EVCSH_ErrMsgChrgrSync.value);
    Rte_swc_BatChCtl_EVCSH_IChrgrSp_EVCSH_IChrgrSp = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_IChrgrSp_EVCSH_IChrgrSp.value);
    Rte_swc_BatChCtl_EVCSH_StBatRdy_EVCSH_StBatRdy = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_StBatRdy_EVCSH_StBatRdy.value);
    Rte_swc_BatChCtl_EVCSH_StDcCh_EVCSH_StDcCh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_StDcCh_EVCSH_StDcCh.value);
    Rte_swc_BatChCtl_EVCSH_StInt_EVCSH_StInt = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_StInt_EVCSH_StInt.value);
    Rte_swc_BatChCtl_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq.value);
    Rte_swc_BatChCtl_EVCSH_UChrgrSp_EVCSH_UChrgrSp = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_UChrgrSp_EVCSH_UChrgrSp.value);
    Rte_swc_BatChCtl_EVCSH_bAcvCfgCmpl_EVCSH_bAcvCfgCmpl = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bAcvCfgCmpl_EVCSH_bAcvCfgCmpl.value);
    Rte_swc_BatChCtl_EVCSH_bAcvChSeqEnd_EVCSH_bAcvChSeqEnd = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bAcvChSeqEnd_EVCSH_bAcvChSeqEnd.value);
    Rte_swc_BatChCtl_EVCSH_bAcvDcChReqFromVcu_EVCSH_bAcvDcChReqFromVcu = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bAcvDcChReqFromVcu_EVCSH_bAcvDcChReqFromVcu.value);
    Rte_swc_BatChCtl_EVCSH_bAcvDcCnctReq_EVCSH_bAcvDcCnctReq = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bAcvDcCnctReq_EVCSH_bAcvDcCnctReq.value);
    Rte_swc_BatChCtl_EVCSH_bAcvVeh2VehDcha_EVCSH_bAcvVeh2VehDcha = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bAcvVeh2VehDcha_EVCSH_bAcvVeh2VehDcha.value);
    Rte_swc_BatChCtl_EVCSH_bEnaChrgn_EVCSH_bEnaChrgn = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaChrgn_EVCSH_bEnaChrgn.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatCfgPgtn_EVCSH_bEnaMsgBatCfgPgtn = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatCfgPgtn_EVCSH_bEnaMsgBatCfgPgtn.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChStPgtn_EVCSH_bEnaMsgBatChStPgtn = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatChStPgtn_EVCSH_bEnaMsgBatChStPgtn.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatPrvt_EVCSH_bEnaMsgBatPrvt = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatPrvt_EVCSH_bEnaMsgBatPrvt.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgBatT_EVCSH_bEnaMsgBatT = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatT_EVCSH_bEnaMsgBatT.value);
    Rte_swc_BatChCtl_EVCSH_bEnaMsgCellU_EVCSH_bEnaMsgCellU = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgCellU_EVCSH_bEnaMsgCellU.value);
    Rte_swc_BatChCtl_TimeOut_CRO00_BCC_TimeOutCRO00 = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_TimeOut_CRO00_BCC_TimeOutCRO00.value);
    Rte_swc_BatChCtl_TimeOut_CROAA_BCC_TimeOutCROAA = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_TimeOut_CROAA_BCC_TimeOutCROAA.value);

    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BCC_StAcSys_BCC_StAcSys.value) = Rte_swc_BatChCtl_BCC_StAcSys_BCC_StAcSys;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value) = Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg.value) = Rte_swc_CIL_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BSTC_StBcu_BSTC_StBcu.value) = Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BSTC_TiBatOff_BSTC_TiBatOff.value) = Rte_swc_BcuStTranCtl_BSTC_TiBatOff_BSTC_TiBatOff;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BSTC_bAcvDcStChToStHvOffNorm_BSTC_bAcvDcStChToStHvOffNorm.value) = Rte_swc_BcuStTranCtl_BSTC_bAcvDcStChToStHvOffNorm_BSTC_bAcvDcStChToStHvOffNorm;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BSTC_bAcvObcOff_BSTC_bAcvObcOff.value) = Rte_swc_BcuStTranCtl_BSTC_bAcvObcOff_BSTC_bAcvObcOff;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BSTC_bAcvStDchaToStHvOffNorm_BSTC_bAcvStDchaToStHvOffNorm.value) = Rte_swc_BcuStTranCtl_BSTC_bAcvStDchaToStHvOffNorm_BSTC_bAcvStDchaToStHvOffNorm;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BSTC_bAcvStRunToStHvOffEmcy_BSTC_bAcvStRunToStHvOffEmcy.value) = Rte_swc_BcuStTranCtl_BSTC_bAcvStRunToStHvOffEmcy_BSTC_bAcvStRunToStHvOffEmcy;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BSTC_bAcvStStbToStAftRun_BSTC_bAcvStStbToStAftRun.value) = Rte_swc_BcuStTranCtl_BSTC_bAcvStStbToStAftRun_BSTC_bAcvStStbToStAftRun;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BTHM_ReqRePrech_BTHM_ReqRePrech.value) = Rte_swc_BatThermHndlgMngt_BTHM_ReqRePrech_BTHM_ReqRePrech;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BTHM_StRlyHeatReq_BTHM_StRlyHeatReq.value) = Rte_swc_BatThermHndlgMngt_BTHM_StRlyHeatReq_BTHM_StRlyHeatReq;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BTHM_StRlyMain_BTHM_StRlyMain.value) = Rte_swc_BatThermHndlgMngt_BTHM_StRlyMain_BTHM_StRlyMain;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_IBatHv_CIL_IBatHv.value) = Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_IBatHvRaw_CIL_IBatHvRaw.value) = Rte_swc_CIL_CIL_IBatHvRaw_CIL_IBatHvRaw;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_ModeMotDrv_CIL_ModeMotDrv.value) = Rte_swc_CIL_CIL_ModeMotDrv_CIL_ModeMotDrv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_StBatHvReq_CIL_StBatHvReq.value) = Rte_swc_CIL_CIL_StBatHvReq_CIL_StBatHvReq;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_StChWup_CIL_StChWup.value) = Rte_swc_CIL_CIL_StChWup_CIL_StChWup;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_StTrml15_CIL_StTrml15.value) = Rte_swc_CIL_CIL_StTrml15_CIL_StTrml15;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv.value) = Rte_swc_CIL_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UChPoleLowSideDrv_CIL_UChPoleLowSideDrv.value) = Rte_swc_CIL_CIL_UChPoleLowSideDrv_CIL_UChPoleLowSideDrv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv.value) = Rte_swc_CIL_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv.value) = Rte_swc_CIL_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UMainNegPoleLowSideDrv_CIL_UMainNegPoleLowSideDrv.value) = Rte_swc_CIL_CIL_UMainNegPoleLowSideDrv_CIL_UMainNegPoleLowSideDrv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly.value) = Rte_swc_CIL_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value) = Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv.value) = Rte_swc_CIL_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UMainPosPoleLowSideDrv_CIL_UMainPosPoleLowSideDrv.value) = Rte_swc_CIL_CIL_UMainPosPoleLowSideDrv_CIL_UMainPosPoleLowSideDrv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UNegChPoleHiSideDrv_CIL_UNegChPoleHiSideDrv.value) = Rte_swc_CIL_CIL_UNegChPoleHiSideDrv_CIL_UNegChPoleHiSideDrv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UNegChPoleLowSideDrv_CIL_UNegChPoleLowSideDrv.value) = Rte_swc_CIL_CIL_UNegChPoleLowSideDrv_CIL_UNegChPoleLowSideDrv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh.value) = Rte_swc_CIL_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UPoleAftRlyChNeg_CIL_UPoleAftRlyChNeg.value) = Rte_swc_CIL_CIL_UPoleAftRlyChNeg_CIL_UPoleAftRlyChNeg;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat.value) = Rte_swc_CIL_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv.value) = Rte_swc_CIL_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UTrml30_CIL_UTrml30.value) = Rte_swc_CIL_CIL_UTrml30_CIL_UTrml30;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_ZeroPwrFb_CIL_ZeroPwrFb.value) = Rte_swc_CIL_CIL_ZeroPwrFb_CIL_ZeroPwrFb;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_bKCNegClsSts_CIL_bKCNegClsSts.value) = Rte_swc_CIL_CIL_bKCNegClsSts_CIL_bKCNegClsSts;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_bMainNegClsSts_CIL_bMainNegClsSts.value) = Rte_swc_CIL_CIL_bMainNegClsSts_CIL_bMainNegClsSts;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag.value) = Rte_swc_DiagcEveHndlg_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_CtrRlyReqDiag_DEH_CtrRlyReqDiag.value) = Rte_swc_DiagcEveHndlg_DEH_CtrRlyReqDiag_DEH_CtrRlyReqDiag;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_CtrRlyWlddErrRstDiag_DEH_CtrRlyWlddErrRstDiag.value) = Rte_swc_DiagcEveHndlg_DEH_CtrRlyWlddErrRstDiag_DEH_CtrRlyWlddErrRstDiag;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_ErrCfmd2_DEH_ErrCfmd2.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd2_DEH_ErrCfmd2;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_ErrCfmd4_DEH_ErrCfmd4.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd4_DEH_ErrCfmd4;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_ErrRlyCtlDiag_DEH_ErrRlyCtlDiag.value) = Rte_swc_DiagcEveHndlg_DEH_ErrRlyCtlDiag_DEH_ErrRlyCtlDiag;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_ReqRlyCh_DEH_ReqRlyCh.value) = Rte_swc_DiagcEveHndlg_DEH_ReqRlyCh_DEH_ReqRlyCh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_ReqRlyNeg_DEH_ReqRlyNeg.value) = Rte_swc_DiagcEveHndlg_DEH_ReqRlyNeg_DEH_ReqRlyNeg;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_ReqRlyPos_DEH_ReqRlyPos.value) = Rte_swc_DiagcEveHndlg_DEH_ReqRlyPos_DEH_ReqRlyPos;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_ReqRlyPrech_DEH_ReqRlyPrech.value) = Rte_swc_DiagcEveHndlg_DEH_ReqRlyPrech_DEH_ReqRlyPrech;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_bAcvPowupInh_DEH_bAcvPowupInh.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvPowupInh_DEH_bAcvPowupInh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_EVCSH_StInt_EVCSH_StInt.value) = Rte_swc_BatChCtl_EVCSH_StInt_EVCSH_StInt;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_EVCSH_bAcvDcCnctReq_EVCSH_bAcvDcCnctReq.value) = Rte_swc_BatChCtl_EVCSH_bAcvDcCnctReq_EVCSH_bAcvDcCnctReq;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh.value) = Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat.value) = Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg.value) = Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos.value) = Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech.value) = Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_NVM_UPrechAccumd_NVM_UPrechAccumd.value) = Rte_swc_DiagcEveHndlg_NVM_UPrechAccumd_NVM_UPrechAccumd;
    CTC_10ms();
    Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv.value);
    Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv.value);
    Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv.value);
    Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv.value);
    Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv.value);
    Rte_swc_CtctrTranCtl_CTC_ErrInfo_CTC_ErrInfo = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ErrInfo_CTC_ErrInfo.value);
    Rte_swc_CtctrTranCtl_CTC_ErrRlyCh_CTC_ErrRlyCh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ErrRlyCh_CTC_ErrRlyCh.value);
    Rte_swc_CtctrTranCtl_CTC_ErrRlyHeat_CTC_ErrRlyHeat = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ErrRlyHeat_CTC_ErrRlyHeat.value);
    Rte_swc_CtctrTranCtl_CTC_ErrRlyNeg_CTC_ErrRlyNeg = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ErrRlyNeg_CTC_ErrRlyNeg.value);
    Rte_swc_CtctrTranCtl_CTC_ErrRlyPos_CTC_ErrRlyPos = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ErrRlyPos_CTC_ErrRlyPos.value);
    Rte_swc_CtctrTranCtl_CTC_ErrRlyPrech_CTC_ErrRlyPrech = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ErrRlyPrech_CTC_ErrRlyPrech.value);
    Rte_swc_CtctrTranCtl_CTC_IDriftZero_CTC_IDriftZero = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_IDriftZero_CTC_IDriftZero.value);
    Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiCh_CTC_PctgCtctrAgiCh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_PctgCtctrAgiCh_CTC_PctgCtctrAgiCh.value);
    Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiHeat_CTC_PctgCtctrAgiHeat = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_PctgCtctrAgiHeat_CTC_PctgCtctrAgiHeat.value);
    Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiNeg_CTC_PctgCtctrAgiNeg = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_PctgCtctrAgiNeg_CTC_PctgCtctrAgiNeg.value);
    Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiPos_CTC_PctgCtctrAgiPos = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_PctgCtctrAgiPos_CTC_PctgCtctrAgiPos.value);
    Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiPrech_CTC_PctgCtctrAgiPrech = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_PctgCtctrAgiPrech_CTC_PctgCtctrAgiPrech.value);
    Rte_swc_CtctrTranCtl_CTC_ReqRlyCh_CTC_ReqRlyCh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqRlyCh_CTC_ReqRlyCh.value);
    Rte_swc_CtctrTranCtl_CTC_ReqRlyChNeg_CTC_ReqRlyChNeg = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqRlyChNeg_CTC_ReqRlyChNeg.value);
    Rte_swc_CtctrTranCtl_CTC_ReqRlyHeat_CTC_ReqRlyHeat = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqRlyHeat_CTC_ReqRlyHeat.value);
    Rte_swc_CtctrTranCtl_CTC_ReqRlyNeg_CTC_ReqRlyNeg = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqRlyNeg_CTC_ReqRlyNeg.value);
    Rte_swc_CtctrTranCtl_CTC_ReqRlyPos_CTC_ReqRlyPos = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqRlyPos_CTC_ReqRlyPos.value);
    Rte_swc_CtctrTranCtl_CTC_ReqRlyPrech_CTC_ReqRlyPrech = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqRlyPrech_CTC_ReqRlyPrech.value);
    Rte_swc_CtctrTranCtl_CTC_ReqZeroPwr_CTC_ReqZeroPwr = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqZeroPwr_CTC_ReqZeroPwr.value);
    Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StHvbat_CTC_StHvbat.value);
    Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StLoopHv_CTC_StLoopHv.value);
    Rte_swc_CtctrTranCtl_CTC_StRlyCh_CTC_StRlyCh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyCh_CTC_StRlyCh.value);
    Rte_swc_CtctrTranCtl_CTC_StRlyChNeg_CTC_StRlyChNeg = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyChNeg_CTC_StRlyChNeg.value);
    Rte_swc_CtctrTranCtl_CTC_StRlyChkCh_CTC_StRlyChkCh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyChkCh_CTC_StRlyChkCh.value);
    Rte_swc_CtctrTranCtl_CTC_StRlyChkHeat_CTC_StRlyChkHeat = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyChkHeat_CTC_StRlyChkHeat.value);
    Rte_swc_CtctrTranCtl_CTC_StRlyChkPos_CTC_StRlyChkPos = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyChkPos_CTC_StRlyChkPos.value);
    Rte_swc_CtctrTranCtl_CTC_StRlyHeat_CTC_StRlyHeat = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyHeat_CTC_StRlyHeat.value);
    Rte_swc_CtctrTranCtl_CTC_StRlyNeg_CTC_StRlyNeg = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyNeg_CTC_StRlyNeg.value);
    Rte_swc_CtctrTranCtl_CTC_StRlyPos_CTC_StRlyPos = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyPos_CTC_StRlyPos.value);
    Rte_swc_CtctrTranCtl_CTC_StRlyPrech_CTC_StRlyPrech = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyPrech_CTC_StRlyPrech.value);
    Rte_swc_CtctrTranCtl_CTC_StSysInt_CTC_StSysInt = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StSysInt_CTC_StSysInt.value);
    Rte_swc_CtctrTranCtl_CTC_UPrechAccumdNv_CTC_UPrechAccumdNv = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_UPrechAccumdNv_CTC_UPrechAccumdNv.value);
    Rte_swc_CtctrTranCtl_CTC_bAcvBswCtl_CTC_bAcvBswCtl = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bAcvBswCtl_CTC_bAcvBswCtl.value);
    Rte_swc_CtctrTranCtl_CTC_bAcvCh_CTC_bAcvCh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bAcvCh_CTC_bAcvCh.value);
    Rte_swc_CtctrTranCtl_CTC_bAcvRePrechFnshd_CTC_bAcvRePrechFnshd = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bAcvRePrechFnshd_CTC_bAcvRePrechFnshd.value);
    Rte_swc_CtctrTranCtl_CTC_bAcvTrml15Chk_CTC_bAcvTrml15Chk = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bAcvTrml15Chk_CTC_bAcvTrml15Chk.value);
    Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiCh_CTC_bErrRlyAgiCh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bErrRlyAgiCh_CTC_bErrRlyAgiCh.value);
    Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiHeat_CTC_bErrRlyAgiHeat = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bErrRlyAgiHeat_CTC_bErrRlyAgiHeat.value);
    Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiNeg_CTC_bErrRlyAgiNeg = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bErrRlyAgiNeg_CTC_bErrRlyAgiNeg.value);
    Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiPos_CTC_bErrRlyAgiPos = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bErrRlyAgiPos_CTC_bErrRlyAgiPos.value);
    Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiPrech_CTC_bErrRlyAgiPrech = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bErrRlyAgiPrech_CTC_bErrRlyAgiPrech.value);
    Rte_swc_CtctrTranCtl_CTC_bErrToutForMotDcha_CTC_bErrToutForMotDcha = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bErrToutForMotDcha_CTC_bErrToutForMotDcha.value);
    Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiCh_CTC_bWarnRlyAgiCh = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bWarnRlyAgiCh_CTC_bWarnRlyAgiCh.value);
    Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiHeat_CTC_bWarnRlyAgiHeat = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bWarnRlyAgiHeat_CTC_bWarnRlyAgiHeat.value);
    Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiNeg_CTC_bWarnRlyAgiNeg = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bWarnRlyAgiNeg_CTC_bWarnRlyAgiNeg.value);
    Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiPos_CTC_bWarnRlyAgiPos = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bWarnRlyAgiPos_CTC_bWarnRlyAgiPos.value);
    Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiPrech_CTC_bWarnRlyAgiPrech = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bWarnRlyAgiPrech_CTC_bWarnRlyAgiPrech.value);

    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BTHM_StSys_BTHM_StSys.value) = Rte_swc_BatThermHndlgMngt_BTHM_StSys_BTHM_StSys;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_CTC_StHvbat_CTC_StHvbat.value) = Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_DEH_bAcvDchaInh_DEH_bAcvDchaInh.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvDchaInh_DEH_bAcvDchaInh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_DEH_bAcvPwrDchaLim1_DEH_bAcvPwrDchaLim1.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvPwrDchaLim1_DEH_bAcvPwrDchaLim1;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_DEH_bAcvPwrDchaLim2_DEH_bAcvPwrDchaLim2.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvPwrDchaLim2_DEH_bAcvPwrDchaLim2;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_DEH_bAcvPwrRecupLim1_DEH_bAcvPwrRecupLim1.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvPwrRecupLim1_DEH_bAcvPwrRecupLim1;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_DEH_bAcvPwrRecupLim2_DEH_bAcvPwrRecupLim2.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvPwrRecupLim2_DEH_bAcvPwrRecupLim2;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_DEH_bAcvRecupInh_DEH_bAcvRecupInh.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvRecupInh_DEH_bAcvRecupInh;
    BCF_10ms();
    Rte_swc_BatCoreFct_BCF_IChLim_BCF_IChLim = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_IChLim_BCF_IChLim.value);
    Rte_swc_BatCoreFct_BCF_IChPredLim_BCF_IChPredLim = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_IChPredLim_BCF_IChPredLim.value);
    Rte_swc_BatCoreFct_BCF_IDchaLim_BCF_IDchaLim = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_IDchaLim_BCF_IDchaLim.value);
    Rte_swc_BatCoreFct_BCF_IDchaPredLim_BCF_IDchaPredLim = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_IDchaPredLim_BCF_IDchaPredLim.value);
    Rte_swc_BatCoreFct_BCF_PwrChLim_BCF_PwrChLim = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_PwrChLim_BCF_PwrChLim.value);
    Rte_swc_BatCoreFct_BCF_PwrChPredLim_BCF_PwrChPredLim = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_PwrChPredLim_BCF_PwrChPredLim.value);
    Rte_swc_BatCoreFct_BCF_PwrDchaLim_BCF_PwrDchaLim = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_PwrDchaLim_BCF_PwrDchaLim.value);
    Rte_swc_BatCoreFct_BCF_PwrDchaPredLim_BCF_PwrDchaPredLim = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_PwrDchaPredLim_BCF_PwrDchaPredLim.value);
    Rte_swc_BatCoreFct_BCF_UChLim_BCF_UChLim = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_UChLim_BCF_UChLim.value);
    Rte_swc_BatCoreFct_BCF_UChPredLim_BCF_UChPredLim = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_UChPredLim_BCF_UChPredLim.value);
    Rte_swc_BatCoreFct_BCF_UDchaLim_BCF_UDchaLim = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_UDchaLim_BCF_UDchaLim.value);
    Rte_swc_BatCoreFct_BCF_UDchaPredLim_BCF_UDchaPredLim = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_UDchaPredLim_BCF_UDchaPredLim.value);

    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SetEventStatus_10ms.Rte_BCC_ErrInfo_BCC_ErrInfo.value) = Rte_swc_BatChCtl_BCC_ErrInfo_BCC_ErrInfo;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SetEventStatus_10ms.Rte_BCF_ErrInfo_BCF_ErrInfo.value) = Rte_swc_BatCoreFct_BCF_ErrInfo_BCF_ErrInfo;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SetEventStatus_10ms.Rte_BPIU_ErrInfo_BPIU_ErrInfo.value) = Rte_swc_BatProtnIU_BPIU_ErrInfo_BPIU_ErrInfo;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SetEventStatus_10ms.Rte_BPP_ErrInfo_BPP_ErrInfo.value) = Rte_swc_BatProtnPack_BPP_ErrInfo_BPP_ErrInfo;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SetEventStatus_10ms.Rte_BSTC_ErrInfo_BSTC_ErrInfo.value) = Rte_swc_BcuStTranCtl_BSTC_ErrInfo_BSTC_ErrInfo;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SetEventStatus_10ms.Rte_BTHM_ErrInfo_BTHM_ErrInfo.value) = Rte_swc_BatThermHndlgMngt_BTHM_ErrInfo_BTHM_ErrInfo;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SetEventStatus_10ms.Rte_CIL_ErrInfoBSW_CIL_ErrInfoBSW.value) = Rte_swc_CIL_CIL_ErrInfoBSW_CIL_ErrInfoBSW;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SetEventStatus_10ms.Rte_CTC_ErrInfo_CTC_ErrInfo.value) = Rte_swc_CtctrTranCtl_CTC_ErrInfo_CTC_ErrInfo;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SetEventStatus_10ms.Rte_ELHPN_ErrInfo_ELHPN_ErrInfo.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_ErrInfo_ELHPN_ErrInfo;
    SetEventStatus_10ms();

    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BCC_AcvCellURchd_BCC_AcvCellURchd.value) = Rte_swc_BatChCtl_BCC_AcvCellURchd_BCC_AcvCellURchd;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BCC_AcvSocRchd_BCC_AcvSocRchd.value) = Rte_swc_BatChCtl_BCC_AcvSocRchd_BCC_AcvSocRchd;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BCC_AcvUTotRchd_BCC_AcvUTotRchd.value) = Rte_swc_BatChCtl_BCC_AcvUTotRchd_BCC_AcvUTotRchd;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BCC_TranAcChEndByBatHvReq_BCC_TranAcChEndByBatHvReq.value) = Rte_swc_BatChCtl_BCC_TranAcChEndByBatHvReq_BCC_TranAcChEndByBatHvReq;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq.value) = Rte_swc_BatChCtl_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BTHM_ErrChEnd_BTHM_ErrChEnd.value) = Rte_swc_BatThermHndlgMngt_BTHM_ErrChEnd_BTHM_ErrChEnd;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_CIL_StAcChCnct_CIL_StAcChCnct.value) = Rte_swc_CIL_CIL_StAcChCnct_CIL_StAcChCnct;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_CIL_StChAllwd_CIL_StChAllwd.value) = Rte_swc_CIL_CIL_StChAllwd_CIL_StChAllwd;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_DEH_ErrCfmd2_DEH_ErrCfmd2.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd2_DEH_ErrCfmd2;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_DEH_ErrCfmd4_DEH_ErrCfmd4.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd4_DEH_ErrCfmd4;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_DEH_VCU_ChgFaultReq_DEH_VCU_ChgFaultReq.value) = Rte_swc_DiagcEveHndlg_DEH_VCU_ChgFaultReq_DEH_VCU_ChgFaultReq;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_DEH_VCU_DischgFaultReq_DEH_VCU_DischgFaultReq.value) = Rte_swc_DiagcEveHndlg_DEH_VCU_DischgFaultReq_DEH_VCU_DischgFaultReq;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_DEH_bAcvChInh_DEH_bAcvChInh.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvChInh_DEH_bAcvChInh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_DEH_bAcvDcChInh_DEH_bAcvDcChInh.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvDcChInh_DEH_bAcvDcChInh;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr.value) = Rte_swc_BatChCtl_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_ChMode_EVCSH_ChMode.value) = Rte_swc_BatChCtl_EVCSH_ChMode_EVCSH_ChMode;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_IChrgrSp_EVCSH_IChrgrSp.value) = Rte_swc_BatChCtl_EVCSH_IChrgrSp_EVCSH_IChrgrSp;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_StInt_EVCSH_StInt.value) = Rte_swc_BatChCtl_EVCSH_StInt_EVCSH_StInt;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_UChrgrSp_EVCSH_UChrgrSp.value) = Rte_swc_BatChCtl_EVCSH_UChrgrSp_EVCSH_UChrgrSp;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd.value) = Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd.value) = Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_bEnaMsgBatPrvt_EVCSH_bEnaMsgBatPrvt.value) = Rte_swc_BatChCtl_EVCSH_bEnaMsgBatPrvt_EVCSH_bEnaMsgBatPrvt;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_bEnaMsgBatT_EVCSH_bEnaMsgBatT.value) = Rte_swc_BatChCtl_EVCSH_bEnaMsgBatT_EVCSH_bEnaMsgBatT;
    *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_bEnaMsgCellU_EVCSH_bEnaMsgCellU.value) = Rte_swc_BatChCtl_EVCSH_bEnaMsgCellU_EVCSH_bEnaMsgCellU;
    COL_10ms();
    Rte_swc_COL_BSWControl_RstDiagGlb_RstDiagGlb = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BSWControl_RstDiagGlb_RstDiagGlb.value);
    Rte_swc_COL_BSWIOSP_Request_BCL_Request_BCL = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BSWIOSP_Request_BCL_Request_BCL.value);
    Rte_swc_COL_BSWIOSP_Request_BMT_Request_BMT = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BSWIOSP_Request_BMT_Request_BMT.value);
    Rte_swc_COL_BSWIOSP_Request_BMV_Request_BMV = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BSWIOSP_Request_BMV_Request_BMV.value);
    Rte_swc_COL_BSWIOSP_Request_BSP_Request_BSP = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BSWIOSP_Request_BSP_Request_BSP.value);
    Rte_swc_COL_BSWIOSP_Request_BST_Request_BST = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BSWIOSP_Request_BST_Request_BST.value);
    Rte_swc_COL_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend.value);
    Rte_swc_COL_BmsSuspCause_SOC_BmsSuspCause_SOC = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspCause_SOC_BmsSuspCause_SOC.value);
    Rte_swc_COL_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage.value);
    Rte_swc_COL_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage.value);
    Rte_swc_COL_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage.value);
    Rte_swc_COL_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent.value);
    Rte_swc_COL_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp.value);
    Rte_swc_COL_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp.value);
    Rte_swc_COL_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn.value);
    Rte_swc_COL_BmsSuspFault_Insulation_BmsSuspFault_Insulation = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_Insulation_BmsSuspFault_Insulation.value);
    Rte_swc_COL_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults.value);
    Rte_swc_COL_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp.value);
    Rte_swc_COL_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection.value);
    Rte_swc_COL_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay.value);
    Rte_swc_COL_ChargingMode_ChargingMode = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_ChargingMode_ChargingMode.value);
    Rte_swc_COL_CurrentDemand_CurrentDemand = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_CurrentDemand_CurrentDemand.value);
    Rte_swc_COL_IOFS_NegRlyCtr_IOFS_NegRlyCtr = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_IOFS_NegRlyCtr_IOFS_NegRlyCtr.value);
    Rte_swc_COL_IOFS_PosRlyCtr_IOFS_PosRlyCtr = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_IOFS_PosRlyCtr_IOFS_PosRlyCtr.value);
    Rte_swc_COL_IOFS_PreChgRlyCtr_IOFS_PreChgRlyCtr = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_IOFS_PreChgRlyCtr_IOFS_PreChgRlyCtr.value);
    Rte_swc_COL_VoltageDemand_VoltageDemand = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_VoltageDemand_VoltageDemand.value);


    Rte_swc_COL_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCU_Crash_BMSH_VCU_Crash = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BMSH_VCU_Crash_BMSH_VCU_Crash.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_Crash_BMSH_VCU_Crash = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_ChgCCSts_BMS_ChgCCSts = *(&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BMS_ChgCCSts_BMS_ChgCCSts.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_ChgCCSts_BMS_ChgCCSts = RTE_COM_SENDSIGNALPROXY_SEND;

    (void)TerminateTask();
}

TASK(App1_Task_20ms_Core2_QM)
{
    Core2_Runnable_App_20ms();

    (void)TerminateTask();
}

TASK(App1_Task_50ms_Core2_QM)
{
    Core2_Runnable_App_50ms();

    swc_SetInput_50ms();


    Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BCM_DoorLockStatusDrv_BCM_DoorLockStatusDrv.value = (UInt8)Rte_ComBuffer_BCM_DoorLockStatusDrv_BCM_LDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BCM_DoorLockStatusPass_BCM_DoorLockStatusPass.value = (UInt8)Rte_ComBuffer_BCM_DoorLockStatusPass_BCM_RDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CrgChargingPermissible_CrgChargingPermissible.value = (UInt8)Rte_ComBuffer_CCS_ChargeAllow_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CumulativeChargingTime_CumulativeChargingTime.value = (UInt16)Rte_ComBuffer_CCS_ChargeTotalTime_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CurrentOutputValue_CurrentOutputValue.value = (UInt16)Rte_ComBuffer_CCS_OutputCurrent_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_EHB_VehicleSpeed_EHB_VehicleSpeed.value = (UInt16)Rte_ComBuffer_EHB_VehicleSpeed_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_Current_sensorTemp_Current_sensorTemp.value = (SInt16)(Rte_ComBuffer_HCM_ShuntTemp_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx-40);


    Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_NegInsulationRes_NegInsulationRes.value = (SInt32)Rte_ComBuffer_HCM_NegInsulateVal_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx;


    Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_PosInsulationRes_PosInsulationRes.value = (SInt32)Rte_ComBuffer_HCM_PosInsulateVal_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx;


    Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_VoltageOutputValue_VoltageOutputValue.value = (UInt16)Rte_ComBuffer_CCS_OutputVoltage_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;

    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_ACTemp_ErrFLg_ACTemp_ErrFLg.value) = Rte_swc_SetInputInterface_BSWIOSP_ACTemp_ErrFLg_ACTemp_ErrFLg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_BMUTempOver_ErrFLg_BMUTempOver_ErrFLg.value) = Rte_swc_SetInputInterface_BSWIOSP_BMUTempOver_ErrFLg_BMUTempOver_ErrFLg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_BalnCtlModl_ErrFLg_BalnCtlModl_ErrFLg.value) = Rte_swc_SetInputInterface_BSWIOSP_BalnCtlModl_ErrFLg_BalnCtlModl_ErrFLg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_BattIsoDet_ErrFLg_BattIsoDet_ErrFLg.value) = Rte_swc_SetInputInterface_BSWIOSP_BattIsoDet_ErrFLg_BattIsoDet_ErrFLg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_CellVoltSampleDiscon_ErrFLg_CellVoltSampleDiscon_ErrFLg.value) = Rte_swc_SetInputInterface_BSWIOSP_CellVoltSampleDiscon_ErrFLg_CellVoltSampleDiscon_ErrFLg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_Com_CCS_UpdataTime_CCS_UpdataTime.value) = Rte_swc_SetInputInterface_BSWIOSP_Com_CCS_UpdataTime_CCS_UpdataTime;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_Com_OBC_Sts_Timeout_OBC_Sts_Timeout.value) = Rte_swc_SetInputInterface_BSWIOSP_Com_OBC_Sts_Timeout_OBC_Sts_Timeout;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_DCTemp_ErrFLg_DCTemp_ErrFLg.value) = Rte_swc_SetInputInterface_BSWIOSP_DCTemp_ErrFLg_DCTemp_ErrFLg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_EVCANBusOff_ErrFLg_EVCANBusOff_ErrFLg.value) = Rte_swc_SetInputInterface_BSWIOSP_EVCANBusOff_ErrFLg_EVCANBusOff_ErrFLg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_HCMCom_ErrFLg_HCMCom_ErrFLg.value) = Rte_swc_SetInputInterface_BSWIOSP_HCMCom_ErrFLg_HCMCom_ErrFLg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_IntCANE2E_ErrFLg_IntCANE2E_ErrFLg.value) = Rte_swc_SetInputInterface_BSWIOSP_IntCANE2E_ErrFLg_IntCANE2E_ErrFLg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_NvM_Save_Ok_NvM_Save_Ok.value) = Rte_swc_SetInputInterface_BSWIOSP_NvM_Save_Ok_NvM_Save_Ok;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_RlyKCVoltSample_ErrFLg_RlyKCVoltSample_ErrFLg.value) = Rte_swc_SetInputInterface_BSWIOSP_RlyKCVoltSample_ErrFLg_RlyKCVoltSample_ErrFLg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_RlyKMVoltSample_ErrFLg_RlyKMVoltSample_ErrFLg.value) = Rte_swc_SetInputInterface_BSWIOSP_RlyKMVoltSample_ErrFLg_RlyKMVoltSample_ErrFLg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_RlyKNVoltSample_ErrFLg_RlyKNVoltSample_ErrFLg.value) = Rte_swc_SetInputInterface_BSWIOSP_RlyKNVoltSample_ErrFLg_RlyKNVoltSample_ErrFLg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_STHW_ErrFLg_STHW_ErrFLg.value) = Rte_swc_SetInputInterface_BSWIOSP_STHW_ErrFLg_STHW_ErrFLg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_VCUCom_ErrFLg_VCUCom_ErrFLg.value) = Rte_swc_SetInputInterface_BSWIOSP_VCUCom_ErrFLg_VCUCom_ErrFLg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_WeakUpFlg_WeakUpFlg.value) = Rte_swc_SetInputInterface_BSWIOSP_WeakUpFlg_WeakUpFlg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_bCANWakeUp_bCANWakeUp.value) = Rte_swc_SetInputInterface_BSWIOSP_bCANWakeUp_bCANWakeUp;
    Rte_MemCpy(Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BmuSample_BMUCellVSt_BMUCellVSt.value, Rte_swc_SetInputInterface_BmuSample_BMUCellVSt_BMUCellVSt, sizeof(rt_Array_UInt32_4));
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BmuSample_CellTEffective_CellTEffective.value) = Rte_swc_SetInputInterface_BmuSample_CellTEffective_CellTEffective;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BmuSample_CellTempException_CellTempException.value) = Rte_swc_SetInputInterface_BmuSample_CellTempException_CellTempException;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BmuSample_CellVEffective_CellVEffective.value) = Rte_swc_SetInputInterface_BmuSample_CellVEffective_CellVEffective;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BmuSample_CellVoltException_CellVoltException.value) = Rte_swc_SetInputInterface_BmuSample_CellVoltException_CellVoltException;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_SampleCountCurrent_U16_SampleCountCurrent_U16.value) = Rte_swc_SetInputInterface_HvSysSample_SampleCountCurrent_U16_SampleCountCurrent_U16;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_SampleCountTotalVol_U16_SampleCountTotalVol_U16.value) = Rte_swc_SetInputInterface_HvSysSample_SampleCountTotalVol_U16_SampleCountTotalVol_U16;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_SampleValidBat_U8_SampleValidBat_U8.value) = Rte_swc_SetInputInterface_HvSysSample_SampleValidBat_U8_SampleValidBat_U8;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_SampleValidCurrent_U8_SampleValidCurrent_U8.value) = Rte_swc_SetInputInterface_HvSysSample_SampleValidCurrent_U8_SampleValidCurrent_U8;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_SampleValidIsolation_U8_SampleValidIsolation_U8.value) = Rte_swc_SetInputInterface_HvSysSample_SampleValidIsolation_U8_SampleValidIsolation_U8;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_SampleValidKC_U8_SampleValidKC_U8.value) = Rte_swc_SetInputInterface_HvSysSample_SampleValidKC_U8_SampleValidKC_U8;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_SampleValidKH_U8_SampleValidKH_U8.value) = Rte_swc_SetInputInterface_HvSysSample_SampleValidKH_U8_SampleValidKH_U8;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_SampleValidKM_U8_SampleValidKM_U8.value) = Rte_swc_SetInputInterface_HvSysSample_SampleValidKM_U8_SampleValidKM_U8;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_SampleValidKN_U8_SampleValidKN_U8.value) = Rte_swc_SetInputInterface_HvSysSample_SampleValidKN_U8_SampleValidKN_U8;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn.value) = Rte_ComTx_CAN_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_RTC_NowSystemTick_NowSystemTick.value) = Rte_swc_SetInputInterface_RTC_NowSystemTick_NowSystemTick;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_RTC_RTCStateFault_RTCStateFault.value) = Rte_swc_SetInputInterface_RTC_RTCStateFault_RTCStateFault;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_RTC_ReadDay_ReadDay.value) = Rte_swc_SetInputInterface_RTC_ReadDay_ReadDay;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_RTC_ReadHour_ReadHour.value) = Rte_swc_SetInputInterface_RTC_ReadHour_ReadHour;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_RTC_ReadMinute_ReadMinute.value) = Rte_swc_SetInputInterface_RTC_ReadMinute_ReadMinute;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_RTC_ReadMonth_ReadMonth.value) = Rte_swc_SetInputInterface_RTC_ReadMonth_ReadMonth;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_RTC_ReadSecond_ReadSecond.value) = Rte_swc_SetInputInterface_RTC_ReadSecond_ReadSecond;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_RTC_ReadYear_ReadYear.value) = Rte_swc_SetInputInterface_RTC_ReadYear_ReadYear;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_VCU_ActInputVolt_VCU_ActInputVolt.value) = Rte_swc_VCOP_VCU_ActInputVolt_VCU_ActInputVolt;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax.value) = Rte_swc_VCOP_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_VCU_ChargeDepthReq_VCU_ChargeDepthReq.value) = Rte_swc_VCOP_VCU_ChargeDepthReq_VCU_ChargeDepthReq;
    CIL_50ms();
    Rte_swc_CIL_BSOF_ChAllwd_BSOF_ChAllwd = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_ChAllwd_BSOF_ChAllwd.value);
    Rte_swc_CIL_BSOF_IChrgr_BSOF_IChrgr = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_IChrgr_BSOF_IChrgr.value);
    Rte_swc_CIL_BSOF_TiChAccumd_BSOF_TiChAccumd = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_TiChAccumd_BSOF_TiChAccumd.value);
    Rte_swc_CIL_BSOF_UChrgr_BSOF_UChrgr = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_UChrgr_BSOF_UChrgr.value);
    Rte_swc_CIL_BSOF_ValDcChrgrPlgOr_BSOF_ValDcChrgrPlgOr = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_ValDcChrgrPlgOr_BSOF_ValDcChrgrPlgOr.value);
    Rte_swc_CIL_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg.value);
    Rte_swc_CIL_BSOF_bEnaMsgChrgrChSt_BSOF_bEnaMsgChrgrChSt = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_bEnaMsgChrgrChSt_BSOF_bEnaMsgChrgrChSt.value);
    Rte_swc_CIL_CIL_ActInputVolt_CIL_ActInputVolt = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ActInputVolt_CIL_ActInputVolt.value);
    Rte_swc_CIL_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax.value);
    Rte_swc_CIL_CIL_CP_Vol_CIL_CP_Vol = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_CP_Vol_CIL_CP_Vol.value);
    Rte_swc_CIL_CIL_ChargeDepthReq_CIL_ChargeDepthReq = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ChargeDepthReq_CIL_ChargeDepthReq.value);
    Rte_swc_CIL_CIL_CtrIslnRSamplg_CIL_CtrIslnRSamplg = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_CtrIslnRSamplg_CIL_CtrIslnRSamplg.value);
    Rte_swc_CIL_CIL_DayRtc_CIL_DayRtc = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_DayRtc_CIL_DayRtc.value);
    Rte_swc_CIL_CIL_DoorLockStatusDrv_CIL_DoorLockStatusDrv = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_DoorLockStatusDrv_CIL_DoorLockStatusDrv.value);
    Rte_swc_CIL_CIL_DoorLockStatusPass_CIL_DoorLockStatusPass = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_DoorLockStatusPass_CIL_DoorLockStatusPass.value);
    Rte_swc_CIL_CIL_DucycCrash_CIL_DucycCrash = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_DucycCrash_CIL_DucycCrash.value);
    Rte_swc_CIL_CIL_DucycCtlPilot_CIL_DucycCtlPilot = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_DucycCtlPilot_CIL_DucycCtlPilot.value);
    Rte_swc_CIL_CIL_DucycHvil_CIL_DucycHvil = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_DucycHvil_CIL_DucycHvil.value);
    Rte_swc_CIL_CIL_ElectroniclockVolt_CIL_ElectroniclockVolt = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ElectroniclockVolt_CIL_ElectroniclockVolt.value);
    Rte_swc_CIL_CIL_ErrAcScktSnsrT_CIL_ErrAcScktSnsrT = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ErrAcScktSnsrT_CIL_ErrAcScktSnsrT.value);
    Rte_swc_CIL_CIL_ErrDcScktSnsrT_CIL_ErrDcScktSnsrT = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ErrDcScktSnsrT_CIL_ErrDcScktSnsrT.value);
    Rte_swc_CIL_CIL_ErrInfoBSW_CIL_ErrInfoBSW = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ErrInfoBSW_CIL_ErrInfoBSW.value);
    Rte_swc_CIL_CIL_FrqCrash_CIL_FrqCrash = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_FrqCrash_CIL_FrqCrash.value);
    Rte_swc_CIL_CIL_FrqHvil_CIL_FrqHvil = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_FrqHvil_CIL_FrqHvil.value);
    Rte_swc_CIL_CIL_HourRtc_CIL_HourRtc = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_HourRtc_CIL_HourRtc.value);
    Rte_swc_CIL_CIL_IDcdcLvAct_CIL_IDcdcLvAct = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_IDcdcLvAct_CIL_IDcdcLvAct.value);
    Rte_swc_CIL_CIL_MinuRtc_CIL_MinuRtc = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_MinuRtc_CIL_MinuRtc.value);
    Rte_swc_CIL_CIL_ModeSysWup_CIL_ModeSysWup = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ModeSysWup_CIL_ModeSysWup.value);
    Rte_swc_CIL_CIL_MonthRtc_CIL_MonthRtc = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_MonthRtc_CIL_MonthRtc.value);
    Rte_swc_CIL_CIL_RAcChCnctnResRaw_CIL_RAcChCnctnResRaw = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_RAcChCnctnResRaw_CIL_RAcChCnctnResRaw.value);
    Rte_swc_CIL_CIL_RDcChrgrPlg_CIL_RDcChrgrPlg = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_RDcChrgrPlg_CIL_RDcChrgrPlg.value);
    Rte_swc_CIL_CIL_RIslnNeg_CIL_RIslnNeg = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_RIslnNeg_CIL_RIslnNeg.value);
    Rte_swc_CIL_CIL_RIslnPos_CIL_RIslnPos = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_RIslnPos_CIL_RIslnPos.value);
    Rte_swc_CIL_CIL_RngElec_CIL_RngElec = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_RngElec_CIL_RngElec.value);
    Rte_swc_CIL_CIL_SecRtc_CIL_SecRtc = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_SecRtc_CIL_SecRtc.value);
    Rte_swc_CIL_CIL_SpdMot_CIL_SpdMot = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_SpdMot_CIL_SpdMot.value);
    Rte_swc_CIL_CIL_SpdVeh_CIL_SpdVeh = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_SpdVeh_CIL_SpdVeh.value);
    Rte_swc_CIL_CIL_StCellTSamplgExcpn_CIL_StCellTSamplgExcpn = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StCellTSamplgExcpn_CIL_StCellTSamplgExcpn.value);
    Rte_MemCpy(Rte_swc_CIL_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul, Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul.value, sizeof(rt_Array_UInt8_24));
    Rte_swc_CIL_CIL_StCellUSamplgExcpn_CIL_StCellUSamplgExcpn = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StCellUSamplgExcpn_CIL_StCellUSamplgExcpn.value);
    Rte_swc_CIL_CIL_StChWup_CIL_StChWup = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StChWup_CIL_StChWup.value);
    Rte_swc_CIL_CIL_StMsgToutForObc_CIL_StMsgToutForObc = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StMsgToutForObc_CIL_StMsgToutForObc.value);
    Rte_swc_CIL_CIL_StMsgToutForPMS_CIL_StMsgToutForPMS = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StMsgToutForPMS_CIL_StMsgToutForPMS.value);
    Rte_swc_CIL_CIL_StRtcFlt_CIL_StRtcFlt = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StRtcFlt_CIL_StRtcFlt.value);
    Rte_swc_CIL_CIL_StTrml15_CIL_StTrml15 = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StTrml15_CIL_StTrml15.value);
    Rte_swc_CIL_CIL_TAcChPointNeg_CIL_TAcChPointNeg = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TAcChPointNeg_CIL_TAcChPointNeg.value);
    Rte_swc_CIL_CIL_TAcChPointPos_CIL_TAcChPointPos = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TAcChPointPos_CIL_TAcChPointPos.value);
    Rte_swc_CIL_CIL_TBd_CIL_TBd = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TBd_CIL_TBd.value);
    Rte_swc_CIL_CIL_TDcChPointNeg_CIL_TDcChPointNeg = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TDcChPointNeg_CIL_TDcChPointNeg.value);
    Rte_swc_CIL_CIL_TDcChPointPos_CIL_TDcChPointPos = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TDcChPointPos_CIL_TDcChPointPos.value);
    Rte_swc_CIL_CIL_TSnsrI_CIL_TSnsrI = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TSnsrI_CIL_TSnsrI.value);
    Rte_swc_CIL_CIL_TiSysRun_CIL_TiSysRun = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TiSysRun_CIL_TiSysRun.value);
    Rte_swc_CIL_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv.value);
    Rte_swc_CIL_CIL_UChPoleLowSideDrv_CIL_UChPoleLowSideDrv = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UChPoleLowSideDrv_CIL_UChPoleLowSideDrv.value);
    Rte_swc_CIL_CIL_UDcdcLvAct_CIL_UDcdcLvAct = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UDcdcLvAct_CIL_UDcdcLvAct.value);
    Rte_swc_CIL_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv.value);
    Rte_swc_CIL_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv.value);
    Rte_swc_CIL_CIL_UMainNegPoleLowSideDrv_CIL_UMainNegPoleLowSideDrv = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UMainNegPoleLowSideDrv_CIL_UMainNegPoleLowSideDrv.value);
    Rte_swc_CIL_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv.value);
    Rte_swc_CIL_CIL_UMainPosPoleLowSideDrv_CIL_UMainPosPoleLowSideDrv = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UMainPosPoleLowSideDrv_CIL_UMainPosPoleLowSideDrv.value);
    Rte_swc_CIL_CIL_UNegChPoleHiSideDrv_CIL_UNegChPoleHiSideDrv = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UNegChPoleHiSideDrv_CIL_UNegChPoleHiSideDrv.value);
    Rte_swc_CIL_CIL_UNegChPoleLowSideDrv_CIL_UNegChPoleLowSideDrv = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UNegChPoleLowSideDrv_CIL_UNegChPoleLowSideDrv.value);
    Rte_swc_CIL_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv.value);
    Rte_swc_CIL_CIL_UTrml30_CIL_UTrml30 = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UTrml30_CIL_UTrml30.value);
    Rte_swc_CIL_CIL_YearRtc_CIL_YearRtc = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_YearRtc_CIL_YearRtc.value);
    Rte_swc_CIL_CIL_bCANWakeUp_CIL_bCANWakeUp = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bCANWakeUp_CIL_bCANWakeUp.value);
    Rte_swc_CIL_CIL_bErrCtrBatIHv_CIL_bErrCtrBatIHv = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bErrCtrBatIHv_CIL_bErrCtrBatIHv.value);
    Rte_swc_CIL_CIL_bErrCtrBatUHv_CIL_bErrCtrBatUHv = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bErrCtrBatUHv_CIL_bErrCtrBatUHv.value);
    Rte_swc_CIL_CIL_bRdyBswStoreFnshd_CIL_bRdyBswStoreFnshd = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bRdyBswStoreFnshd_CIL_bRdyBswStoreFnshd.value);
    Rte_swc_CIL_CIL_bVldBatIHv_CIL_bVldBatIHv = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldBatIHv_CIL_bVldBatIHv.value);
    Rte_swc_CIL_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg.value);
    Rte_swc_CIL_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg.value);
    Rte_swc_CIL_CIL_bVldIslnR_CIL_bVldIslnR = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldIslnR_CIL_bVldIslnR.value);
    Rte_swc_CIL_CIL_bVldUMainNegPoleAftRly_CIL_bVldUMainNegPoleAftRly = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldUMainNegPoleAftRly_CIL_bVldUMainNegPoleAftRly.value);
    Rte_swc_CIL_CIL_bVldUMainPosPoleAftRly_CIL_bVldUMainPosPoleAftRly = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldUMainPosPoleAftRly_CIL_bVldUMainPosPoleAftRly.value);
    Rte_swc_CIL_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly.value);
    Rte_swc_CIL_CIL_bVldUPoleAftRlyCh_CIL_bVldUPoleAftRlyCh = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldUPoleAftRlyCh_CIL_bVldUPoleAftRlyCh.value);
    Rte_swc_CIL_CIL_bVldUPoleAftRlyHeat_CIL_bVldUPoleAftRlyHeat = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldUPoleAftRlyHeat_CIL_bVldUPoleAftRlyHeat.value);
    Rte_swc_CIL_MCC_StMdulCu_MCC_StMdulCu = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_MCC_StMdulCu_MCC_StMdulCu.value);


    Rte_swc_CIL_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_CIL_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq = RTE_COM_SENDSIGNALPROXY_SEND;

    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_BSTC_StBcu_BSTC_StBcu.value) = Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CIL_CtrIslnRSamplg_CIL_CtrIslnRSamplg.value) = Rte_swc_CIL_CIL_CtrIslnRSamplg_CIL_CtrIslnRSamplg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CIL_DucycCrash_CIL_DucycCrash.value) = Rte_swc_CIL_CIL_DucycCrash_CIL_DucycCrash;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CIL_DucycHvil_CIL_DucycHvil.value) = Rte_swc_CIL_CIL_DucycHvil_CIL_DucycHvil;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CIL_FrqCrash_CIL_FrqCrash.value) = Rte_swc_CIL_CIL_FrqCrash_CIL_FrqCrash;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CIL_FrqHvil_CIL_FrqHvil.value) = Rte_swc_CIL_CIL_FrqHvil_CIL_FrqHvil;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CIL_RIslnNeg_CIL_RIslnNeg.value) = Rte_swc_CIL_CIL_RIslnNeg_CIL_RIslnNeg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CIL_RIslnPos_CIL_RIslnPos.value) = Rte_swc_CIL_CIL_RIslnPos_CIL_RIslnPos;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CIL_StCrash_CIL_StCrash.value) = Rte_swc_CIL_CIL_StCrash_CIL_StCrash;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value) = Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CTC_StHvbat_CTC_StHvbat.value) = Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CTC_StLoopHv_CTC_StLoopHv.value) = Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_CtrIslnMeasReqDiag_DEH_CtrIslnMeasReqDiag.value) = Rte_swc_DiagcEveHndlg_DEH_CtrIslnMeasReqDiag_DEH_CtrIslnMeasReqDiag;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_ErrCfmd5_DEH_ErrCfmd5.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd5_DEH_ErrCfmd5;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_ErrHisCfmd_DEH_ErrHisCfmd.value) = Rte_swc_DiagcEveHndlg_DEH_ErrHisCfmd_DEH_ErrHisCfmd;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_StIslnMeasReq_DEH_StIslnMeasReq.value) = Rte_swc_DiagcEveHndlg_DEH_StIslnMeasReq_DEH_StIslnMeasReq;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_StsIninNv_DEH_StsIninNv.value) = Rte_swc_DiagcEveHndlg_DEH_StsIninNv_DEH_StsIninNv;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_bAcvBdNew_DEH_bAcvBdNew.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvBdNew_DEH_bAcvBdNew;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq.value) = Rte_swc_BatChCtl_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_NVM_RIslnNeg_NVM_RIslnNeg.value) = Rte_swc_DiagcEveHndlg_NVM_RIslnNeg_NVM_RIslnNeg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_NVM_RIslnPos_NVM_RIslnPos.value) = Rte_swc_DiagcEveHndlg_NVM_RIslnPos_NVM_RIslnPos;
    ELHPN_50ms();
    Rte_swc_EltlLnkHzrdProtnNet_ELHPN_ErrInfo_ELHPN_ErrInfo = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_ErrInfo_ELHPN_ErrInfo.value);
    Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnNeg_ELHPN_RIslnNeg = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_RIslnNeg_ELHPN_RIslnNeg.value);
    Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnNegNv_ELHPN_RIslnNegNv = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_RIslnNegNv_ELHPN_RIslnNegNv.value);
    Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnPos_ELHPN_RIslnPos = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_RIslnPos_ELHPN_RIslnPos.value);
    Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnPosNv_ELHPN_RIslnPosNv = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_RIslnPosNv_ELHPN_RIslnPosNv.value);
    Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StCrash_ELHPN_StCrash = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StCrash_ELHPN_StCrash.value);
    Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StCrashIni_ELHPN_StCrashIni = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StCrashIni_ELHPN_StCrashIni.value);
    Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc.value);
    Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc.value);
    Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrIniHvIntlc2_ELHPN_StErrIniHvIntlc2 = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StErrIniHvIntlc2_ELHPN_StErrIniHvIntlc2.value);
    Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StIsln_ELHPN_StIsln = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StIsln_ELHPN_StIsln.value);
    Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StIslnErr_ELHPN_StIslnErr = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StIslnErr_ELHPN_StIslnErr.value);
    Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StVehIsln_ELHPN_StVehIsln = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StVehIsln_ELHPN_StVehIsln.value);
    Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni.value);
    Rte_swc_EltlLnkHzrdProtnNet_ELHPN_bInhIslnMeas_ELHPN_bInhIslnMeas = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_bInhIslnMeas_ELHPN_bInhIslnMeas.value);

    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value) = Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_CIL_IBatHv_CIL_IBatHv.value) = Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value) = Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_CTC_StHvbat_CTC_StHvbat.value) = Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_MCC_NrCellTot_MCC_NrCellTot.value) = Rte_swc_CIL_MCC_NrCellTot_MCC_NrCellTot;
    BPP_50ms();
    Rte_swc_BatProtnPack_BPP_ErrInfo_BPP_ErrInfo = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_ErrInfo_BPP_ErrInfo.value);
    Rte_swc_BatProtnPack_BPP_ErrPackU_BPP_ErrPackU = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_ErrPackU_BPP_ErrPackU.value);
    Rte_swc_BatProtnPack_BPP_IAct_BPP_IAct = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_IAct_BPP_IAct.value);
    Rte_swc_BatProtnPack_BPP_IChAct_BPP_IChAct = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_IChAct_BPP_IChAct.value);
    Rte_swc_BatProtnPack_BPP_IDchaAct_BPP_IDchaAct = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_IDchaAct_BPP_IDchaAct.value);
    Rte_swc_BatProtnPack_BPP_PwrAct_BPP_PwrAct = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_PwrAct_BPP_PwrAct.value);
    Rte_swc_BatProtnPack_BPP_bAcvCTest_BPP_bAcvCTest = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_bAcvCTest_BPP_bAcvCTest.value);

    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BCF_IChLim_BCF_IChLim.value) = Rte_swc_BatCoreFct_BCF_IChLim_BCF_IChLim;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BCF_IDchaLim_BCF_IDchaLim.value) = Rte_swc_BatCoreFct_BCF_IDchaLim_BCF_IDchaLim;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPP_IChAct_BPP_IChAct.value) = Rte_swc_BatProtnPack_BPP_IChAct_BPP_IChAct;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPP_IDchaAct_BPP_IDchaAct.value) = Rte_swc_BatProtnPack_BPP_IDchaAct_BPP_IDchaAct;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BSOF_ValDcChrgrPlgOr_BSOF_ValDcChrgrPlgOr.value) = Rte_swc_CIL_BSOF_ValDcChrgrPlgOr_BSOF_ValDcChrgrPlgOr;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BSTC_StBcu_BSTC_StBcu.value) = Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_CIL_IBatHv_CIL_IBatHv.value) = Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_CIL_StAcChCnct_CIL_StAcChCnct.value) = Rte_swc_CIL_CIL_StAcChCnct_CIL_StAcChCnct;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_CIL_StPtIndcr_CIL_StPtIndcr.value) = Rte_swc_CIL_CIL_StPtIndcr_CIL_StPtIndcr;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_CIL_UTrml30_CIL_UTrml30.value) = Rte_swc_CIL_CIL_UTrml30_CIL_UTrml30;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_CIL_bErrCtrBatIHv_CIL_bErrCtrBatIHv.value) = Rte_swc_CIL_CIL_bErrCtrBatIHv_CIL_bErrCtrBatIHv;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_CIL_bVldBatIHv_CIL_bVldBatIHv.value) = Rte_swc_CIL_CIL_bVldBatIHv_CIL_bVldBatIHv;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
    BPIU_50ms();
    Rte_swc_BatProtnIU_BPIU_ErrIChLim_BPIU_ErrIChLim = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_ErrIChLim_BPIU_ErrIChLim.value);
    Rte_swc_BatProtnIU_BPIU_ErrIDchaLim_BPIU_ErrIDchaLim = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_ErrIDchaLim_BPIU_ErrIDchaLim.value);
    Rte_swc_BatProtnIU_BPIU_ErrIRgnOvcur_BPIU_ErrIRgnOvcur = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_ErrIRgnOvcur_BPIU_ErrIRgnOvcur.value);
    Rte_swc_BatProtnIU_BPIU_ErrInfo_BPIU_ErrInfo = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_ErrInfo_BPIU_ErrInfo.value);
    Rte_swc_BatProtnIU_BPIU_ErrPackSnsrI_BPIU_ErrPackSnsrI = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_ErrPackSnsrI_BPIU_ErrPackSnsrI.value);
    Rte_swc_BatProtnIU_BPIU_StChkUMax_BPIU_StChkUMax = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_StChkUMax_BPIU_StChkUMax.value);
    Rte_swc_BatProtnIU_BPIU_StChkUMin_BPIU_StChkUMin = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_StChkUMin_BPIU_StChkUMin.value);

    Rte_MemCpy(Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp.value, Rte_swc_BatBalnCtl_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp, sizeof(rt_Array_UInt32_24));
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_BSTC_ReqShtdnBas_BSTC_ReqShtdnBas.value) = Rte_swc_BcuStTranCtl_BSTC_ReqShtdnBas_BSTC_ReqShtdnBas;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_CIL_ActInputVolt_CIL_ActInputVolt.value) = Rte_swc_CIL_CIL_ActInputVolt_CIL_ActInputVolt;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_CIL_TAcChPointNeg_CIL_TAcChPointNeg.value) = Rte_swc_CIL_CIL_TAcChPointNeg_CIL_TAcChPointNeg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_CIL_TAcChPointPos_CIL_TAcChPointPos.value) = Rte_swc_CIL_CIL_TAcChPointPos_CIL_TAcChPointPos;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_CTC_ReqRlyHeat_CTC_ReqRlyHeat.value) = Rte_swc_CtctrTranCtl_CTC_ReqRlyHeat_CTC_ReqRlyHeat;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_CTC_ReqRlyNeg_CTC_ReqRlyNeg.value) = Rte_swc_CtctrTranCtl_CTC_ReqRlyNeg_CTC_ReqRlyNeg;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_CTC_ReqRlyPos_CTC_ReqRlyPos.value) = Rte_swc_CtctrTranCtl_CTC_ReqRlyPos_CTC_ReqRlyPos;
    *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_ELHPN_bInhIslnMeas_ELHPN_bInhIslnMeas.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_bInhIslnMeas_ELHPN_bInhIslnMeas;
    COL_50ms();
    Rte_swc_COL_BSWIOSP_Mode_Request_shutdown_Request_shutdown = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_BSWIOSP_Mode_Request_shutdown_Request_shutdown.value);
    Rte_MemCpy(Rte_swc_COL_BmuControl_BalanceControl_BalanceControl, Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_BmuControl_BalanceControl_BalanceControl.value, sizeof(rt_Array_UInt32_9));


    Rte_swc_COL_BMSH_BusVolt_BMSH_BusVolt = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_BMSH_BusVolt_BMSH_BusVolt.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BusVolt_BMSH_BusVolt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_SlowChgNegTemp_BMS_SlowChgNegTemp = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_BMS_SlowChgNegTemp_BMS_SlowChgNegTemp.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_SlowChgNegTemp_BMS_SlowChgNegTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_SlowChgPosTemp_BMS_SlowChgPosTemp = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_BMS_SlowChgPosTemp_BMS_SlowChgPosTemp.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_SlowChgPosTemp_BMS_SlowChgPosTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_HvSysSample_DisableIso_DisableIso = *(&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_HvSysSample_DisableIso_DisableIso.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_HvSysSample_DisableIso_DisableIso = RTE_COM_SENDSIGNALPROXY_SEND;

    swc_SetOutputInterface_50ms();

    (void)TerminateTask();
}

TASK(App1_Task_100ms_Core2_QM)
{
    Core2_Runnable_App_100ms();


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_ChargerReadyForCharging_ChargerReadyForCharging.value = (UInt8)Rte_ComBuffer_CRO_ChargerReady_CRO_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_ChargerRevision_ChargerRevision.value = (UInt8)Rte_ComBuffer_CHM_ProtocolVersion_CHM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_EHB_VehicleSpeedInvalid_EHB_VehicleSpeedInvalid.value = (Boolean)Rte_ComBuffer_EHB_VehicleSpeedInvalid_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_IPK_Day_IPK_Day.value = (UInt8)Rte_ComBuffer_IPK_Day_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_IPK_Hour_IPK_Hour.value = (UInt8)Rte_ComBuffer_IPK_Hour_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_IPK_Minute_IPK_Minute.value = (UInt8)Rte_ComBuffer_IPK_Minute_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_IPK_Month_IPK_Month.value = (UInt8)Rte_ComBuffer_IPK_Month_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_IPK_Second_IPK_Second.value = (UInt8)Rte_ComBuffer_IPK_Second_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_IPK_Year_IPK_Year.value = (UInt8)Rte_ComBuffer_IPK_Year_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MaxOutputCurrent_MaxOutputCurrent.value = (UInt16)Rte_ComBuffer_CML_OutputCurrentMax_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MaxOutputVoltage_MaxOutputVoltage.value = (UInt16)Rte_ComBuffer_CML_OutpuVoltageMax_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MinOutputCurrent_MinOutputCurrent.value = (UInt16)Rte_ComBuffer_CML_OutputCurrentMin_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MinOutputVoltage_MinOutputVoltage.value = (UInt16)Rte_ComBuffer_CML_OutputVoltageMin_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_CCvalue_OBC_CCvalue.value = (UInt8)Rte_ComBuffer_OBC_CCvalue_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_ChgCCSts_OBC_ChgCCSts.value = (UInt8)Rte_ComBuffer_OBC_ChgCCSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_ChrgrSt_OBC_ChrgrSt.value = (UInt8)Rte_ComBuffer_OBC_ChrgrSt_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_DischargeCCvalue_OBC_DischargeCCvalue.value = (UInt8)Rte_ComBuffer_OBC_DischargeCCvalue_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_Elock_Stmode_OBC_Elock_Stmode.value = (UInt8)Rte_ComBuffer_OBC_Elock_Stmode_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_OnBdCCline_OBC_OnBdCCline.value = (UInt8)Rte_ComBuffer_OBC_OnBdCCline_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_OnBdCPline_OBC_OnBdCPline.value = (UInt8)Rte_ComBuffer_OBC_OnBdCPline_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_OnBdDisChrgrCCline_OBC_OnBdDisChrgrCCline.value = (UInt8)Rte_ComBuffer_OBC_OnBdDisChrgrCCline_OBC_Curr_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_OnBdOuptI_OBC_OnBdOuptI.value = (UInt16)Rte_ComBuffer_OBC_OnBdOuptI_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_OnBdOuptU_OBC_OnBdOuptU.value = (UInt16)Rte_ComBuffer_OBC_OnBdOuptU_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_uInAct_OBC_uInAct.value = (UInt16)Rte_ComBuffer_OBC_uInAct_OBC_Curr_PMS_EV_CAN_20260427_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OutputEnergy_OutputEnergy.value = (UInt16)Rte_ComBuffer_CSD_OutputEnerge_CSD_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_PEPS_PowerMode_PEPS_PowerMode.value = (UInt8)Rte_ComBuffer_PEPS_PowerMode_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_RecognitionResult_RecognitionResult.value = (UInt8)Rte_ComBuffer_CRM_RecognitionResult_CRM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_TBOX_ChrgSoftSwCtrlSt_TBOX_ChrgSoftSwCtrlSt.value = (UInt8)Rte_ComBuffer_TBOX_ChrgSoftSwCtrlSt_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_TBOX_ReservationChrgnSts_TBOX_ReservationChrgnSts.value = (UInt8)Rte_ComBuffer_TBOX_ReservationChrgnSts_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_Timeout_BCL_Timeout_BCL.value = (UInt8)Rte_ComBuffer_CEM_BatteryChargeRequireTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_Timeout_BCP_Timeout_BCP.value = (UInt8)Rte_ComBuffer_CEM_BatteryParameterTimout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_Timeout_BCS_Timeout_BCS.value = (UInt8)Rte_ComBuffer_CEM_BatteryStateTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_Timeout_BRM_Timeout_BRM.value = (UInt8)Rte_ComBuffer_CEM_BMSIdentifyTimout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_Timeout_BRO_Timeout_BRO.value = (UInt8)Rte_ComBuffer_CEM_BMSFinishChargeTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_Timeout_BSD_Timeout_BSD.value = (UInt8)Rte_ComBuffer_CEM_BMSChargeStatisticsTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;


    Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_Timeout_BST_Timeout_BST.value = (UInt8)Rte_ComBuffer_CEM_BMSAbortChargeTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;

    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CCD_UpdataTime_CCD_UpdataTime.value) = Rte_swc_SetInputInterface_BSWIOSP_Com_CCD_UpdataTime_CCD_UpdataTime;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CDC_UpdataTime_CDC_UpdataTime.value) = Rte_swc_SetInputInterface_BSWIOSP_Com_CDC_UpdataTime_CDC_UpdataTime;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CEM_UpdataTime_CEM_UpdataTime.value) = Rte_swc_SetInputInterface_BSWIOSP_Com_CEM_UpdataTime_CEM_UpdataTime;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CHM_UpdataTime_CHM_UpdataTime.value) = Rte_swc_SetInputInterface_BSWIOSP_Com_CHM_UpdataTime_CHM_UpdataTime;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CMLP_UpdataTime_CMLP_UpdataTime.value) = Rte_swc_SetInputInterface_BSWIOSP_Com_CMLP_UpdataTime_CMLP_UpdataTime;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CML_UpdataTime_CML_UpdataTime.value) = Rte_swc_SetInputInterface_BSWIOSP_Com_CML_UpdataTime_CML_UpdataTime;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CRM_UpdataTime_CRM_UpdataTime.value) = Rte_swc_SetInputInterface_BSWIOSP_Com_CRM_UpdataTime_CRM_UpdataTime;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CRO_UpdataTime_CRO_UpdataTime.value) = Rte_swc_SetInputInterface_BSWIOSP_Com_CRO_UpdataTime_CRO_UpdataTime;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CSDP_UpdataTime_CSDP_UpdataTime.value) = Rte_swc_SetInputInterface_BSWIOSP_Com_CSDP_UpdataTime_CSDP_UpdataTime;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CSD_UpdataTime_CSD_UpdataTime.value) = Rte_swc_SetInputInterface_BSWIOSP_Com_CSD_UpdataTime_CSD_UpdataTime;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BmuSample_BMUCell_BMUCell.value, Rte_swc_SetInputInterface_BmuSample_BMUCell_BMUCell, sizeof(rt_Array_UInt16_130));
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BmuSample_BMUChipTemp_BMUChipTemp.value, Rte_swc_SetInputInterface_BmuSample_BMUChipTemp_BMUChipTemp, sizeof(rt_Array_SInt16_8));
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BmuSample_BMUTemp_BMUTemp.value, Rte_swc_SetInputInterface_BmuSample_BMUTemp_BMUTemp, sizeof(rt_Array_SInt16_32));
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BmuSample_BMUTempSt_BMUTempSt.value, Rte_swc_SetInputInterface_BmuSample_BMUTempSt_BMUTempSt, sizeof(rt_Array_UInt8_32));
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BmuSample_BalanceTemp_BalanceTemp.value, Rte_swc_SetInputInterface_BmuSample_BalanceTemp_BalanceTemp, sizeof(rt_Array_SInt16_8));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_PMS_BatCoolType_PMS_BatCoolType.value) = Rte_swc_VCOP_PMS_BatCoolType_PMS_BatCoolType;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_PMS_Wakeup_reasons_PMS_Wakeup_reasons.value) = Rte_swc_VCOP_PMS_Wakeup_reasons_PMS_Wakeup_reasons;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb.value) = Rte_swc_VCOP_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp.value) = Rte_swc_VCOP_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp.value) = Rte_swc_VCOP_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq.value) = Rte_swc_VCOP_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual.value) = Rte_swc_VCOP_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual;
    CIL_100ms();
    Rte_MemCpy(Rte_swc_CIL_BMC_UCell_BMC_UCell, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BMC_UCell_BMC_UCell.value, sizeof(rt_Array_Float_255));
    Rte_swc_CIL_BSOF_DirChAndDcha_BSOF_DirChAndDcha = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_DirChAndDcha_BSOF_DirChAndDcha.value);
    Rte_swc_CIL_BSOF_EChSng_BSOF_EChSng = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_EChSng_BSOF_EChSng.value);
    Rte_swc_CIL_BSOF_IChrgrMax_BSOF_IChrgrMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_IChrgrMax_BSOF_IChrgrMax.value);
    Rte_swc_CIL_BSOF_IChrgrMin_BSOF_IChrgrMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_IChrgrMin_BSOF_IChrgrMin.value);
    Rte_swc_CIL_BSOF_IDchaMax_BSOF_IDchaMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_IDchaMax_BSOF_IDchaMax.value);
    Rte_swc_CIL_BSOF_IDchaMin_BSOF_IDchaMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_IDchaMin_BSOF_IDchaMin.value);
    Rte_swc_CIL_BSOF_MsgChrgrRcgtn_BSOF_MsgChrgrRcgtn = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_MsgChrgrRcgtn_BSOF_MsgChrgrRcgtn.value);
    Rte_swc_CIL_BSOF_MsgChrgrRdy_BSOF_MsgChrgrRdy = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_MsgChrgrRdy_BSOF_MsgChrgrRdy.value);
    Rte_swc_CIL_BSOF_NrChrgrComVers_BSOF_NrChrgrComVers = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_NrChrgrComVers_BSOF_NrChrgrComVers.value);
    Rte_swc_CIL_BSOF_SocDchaMax_BSOF_SocDchaMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_SocDchaMax_BSOF_SocDchaMax.value);
    Rte_swc_CIL_BSOF_SocDchaMin_BSOF_SocDchaMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_SocDchaMin_BSOF_SocDchaMin.value);
    Rte_swc_CIL_BSOF_UChrgrMax_BSOF_UChrgrMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_UChrgrMax_BSOF_UChrgrMax.value);
    Rte_swc_CIL_BSOF_UChrgrMin_BSOF_UChrgrMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_UChrgrMin_BSOF_UChrgrMin.value);
    Rte_swc_CIL_BSOF_UDchaMax_BSOF_UDchaMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_UDchaMax_BSOF_UDchaMax.value);
    Rte_swc_CIL_BSOF_UDchaMin_BSOF_UDchaMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_UDchaMin_BSOF_UDchaMin.value);
    Rte_swc_CIL_BSOF_bEnaMsgChrgrChDetd_BSOF_bEnaMsgChrgrChDetd = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrChDetd_BSOF_bEnaMsgChrgrChDetd.value);
    Rte_swc_CIL_BSOF_bEnaMsgChrgrDetnCnct_BSOF_bEnaMsgChrgrDetnCnct = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrDetnCnct_BSOF_bEnaMsgChrgrDetnCnct.value);
    Rte_swc_CIL_BSOF_bEnaMsgChrgrErr_BSOF_bEnaMsgChrgrErr = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrErr_BSOF_bEnaMsgChrgrErr.value);
    Rte_swc_CIL_BSOF_bEnaMsgChrgrHdshk_BSOF_bEnaMsgChrgrHdshk = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrHdshk_BSOF_bEnaMsgChrgrHdshk.value);
    Rte_swc_CIL_BSOF_bEnaMsgChrgrMaxOut_BSOF_bEnaMsgChrgrMaxOut = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrMaxOut_BSOF_bEnaMsgChrgrMaxOut.value);
    Rte_swc_CIL_BSOF_bEnaMsgChrgrMaxOutPgtn_BSOF_bEnaMsgChrgrMaxOutPgtn = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrMaxOutPgtn_BSOF_bEnaMsgChrgrMaxOutPgtn.value);
    Rte_swc_CIL_BSOF_bEnaMsgChrgrRcgtn_BSOF_bEnaMsgChrgrRcgtn = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrRcgtn_BSOF_bEnaMsgChrgrRcgtn.value);
    Rte_swc_CIL_BSOF_bEnaMsgChrgrRdy_BSOF_bEnaMsgChrgrRdy = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrRdy_BSOF_bEnaMsgChrgrRdy.value);
    Rte_swc_CIL_BSOF_bEnaMsgChrgrStstc_BSOF_bEnaMsgChrgrStstc = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrStstc_BSOF_bEnaMsgChrgrStstc.value);
    Rte_swc_CIL_BSOF_bEnaMsgChrgrStstcForPgtn_BSOF_bEnaMsgChrgrStstcForPgtn = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrStstcForPgtn_BSOF_bEnaMsgChrgrStstcForPgtn.value);
    Rte_swc_CIL_BSOF_bErrMsgTout_BSOF_bErrMsgTout = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bErrMsgTout_BSOF_bErrMsgTout.value);
    Rte_swc_CIL_CIL_BMSH_StsModeReq_CIL_BMSH_StsModeReq = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_BMSH_StsModeReq_CIL_BMSH_StsModeReq.value);
    Rte_swc_CIL_CIL_BatCoolType_CIL_BatCoolType = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_BatCoolType_CIL_BatCoolType.value);
    Rte_swc_CIL_CIL_CfgLvl2_CIL_CfgLvl2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_CfgLvl2_CIL_CfgLvl2.value);
    Rte_swc_CIL_CIL_ChgCCSts_CIL_ChgCCSts = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_ChgCCSts_CIL_ChgCCSts.value);
    Rte_swc_CIL_CIL_ChrgSoftSwCtrlSt_CIL_ChrgSoftSwCtrlSt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_ChrgSoftSwCtrlSt_CIL_ChrgSoftSwCtrlSt.value);
    Rte_swc_CIL_CIL_DayTelbox_CIL_DayTelbox = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_DayTelbox_CIL_DayTelbox.value);
    Rte_swc_CIL_CIL_ElockStmodeOBC_CIL_ElockStmodeOBC = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_ElockStmodeOBC_CIL_ElockStmodeOBC.value);
    Rte_swc_CIL_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl.value);
    Rte_swc_CIL_CIL_HWVerVeh_CIL_HWVerVeh = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_HWVerVeh_CIL_HWVerVeh.value);
    Rte_swc_CIL_CIL_HourTelbox_CIL_HourTelbox = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_HourTelbox_CIL_HourTelbox.value);
    Rte_swc_CIL_CIL_IEACAct_CIL_IEACAct = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_IEACAct_CIL_IEACAct.value);
    Rte_swc_CIL_CIL_IObcChOutp_CIL_IObcChOutp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_IObcChOutp_CIL_IObcChOutp.value);
    Rte_swc_CIL_CIL_MilgTot_CIL_MilgTot = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_MilgTot_CIL_MilgTot.value);
    Rte_swc_CIL_CIL_MinuTelbox_CIL_MinuTelbox = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_MinuTelbox_CIL_MinuTelbox.value);
    Rte_swc_CIL_CIL_MonthTelbox_CIL_MonthTelbox = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_MonthTelbox_CIL_MonthTelbox.value);
    Rte_swc_CIL_CIL_OnBdCPline_CIL_OnBdCPline = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_OnBdCPline_CIL_OnBdCPline.value);
    Rte_swc_CIL_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline.value);
    Rte_swc_CIL_CIL_PowerMode_CIL_PowerMode = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_PowerMode_CIL_PowerMode.value);
    Rte_swc_CIL_CIL_PwrEACAct_CIL_PwrEACAct = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_PwrEACAct_CIL_PwrEACAct.value);
    Rte_swc_CIL_CIL_PwrPtcAct_CIL_PwrPtcAct = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_PwrPtcAct_CIL_PwrPtcAct.value);
    Rte_swc_CIL_CIL_RAcChCnctn_CIL_RAcChCnctn = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_RAcChCnctn_CIL_RAcChCnctn.value);
    Rte_swc_CIL_CIL_RDisChCnctn_CIL_RDisChCnctn = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_RDisChCnctn_CIL_RDisChCnctn.value);
    Rte_swc_CIL_CIL_ReservationChrgnSts_CIL_ReservationChrgnSts = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_ReservationChrgnSts_CIL_ReservationChrgnSts.value);
    Rte_swc_CIL_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl.value);
    Rte_swc_CIL_CIL_SWVerVeh_CIL_SWVerVeh = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_SWVerVeh_CIL_SWVerVeh.value);
    Rte_swc_CIL_CIL_SecTelbox_CIL_SecTelbox = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_SecTelbox_CIL_SecTelbox.value);
    Rte_swc_CIL_CIL_StAcChCnct_CIL_StAcChCnct = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StAcChCnct_CIL_StAcChCnct.value);
    Rte_swc_CIL_CIL_StBatHvReq_CIL_StBatHvReq = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StBatHvReq_CIL_StBatHvReq.value);
    Rte_swc_CIL_CIL_StBatLvCutoffReq_CIL_StBatLvCutoffReq = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StBatLvCutoffReq_CIL_StBatLvCutoffReq.value);
    Rte_MemCpy(Rte_swc_CIL_CIL_StCellT_CIL_StCellT, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StCellT_CIL_StCellT.value, sizeof(rt_Array_UInt8_54));
    Rte_swc_CIL_CIL_StChAllwd_CIL_StChAllwd = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StChAllwd_CIL_StChAllwd.value);
    Rte_swc_CIL_CIL_StObc_CIL_StObc = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StObc_CIL_StObc.value);
    Rte_swc_CIL_CIL_StProj_CIL_StProj = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StProj_CIL_StProj.value);
    Rte_swc_CIL_CIL_StPtIndcr_CIL_StPtIndcr = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StPtIndcr_CIL_StPtIndcr.value);
    Rte_swc_CIL_CIL_StPtcW_CIL_StPtcW = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StPtcW_CIL_StPtcW.value);
    Rte_MemCpy(Rte_swc_CIL_CIL_TBdSnsr_CIL_TBdSnsr, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_TBdSnsr_CIL_TBdSnsr.value, sizeof(rt_Array_Float_32));
    Rte_swc_CIL_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr.value);
    Rte_swc_CIL_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr.value);
    Rte_MemCpy(Rte_swc_CIL_CIL_TMdul_CIL_TMdul, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_TMdul_CIL_TMdul.value, sizeof(rt_Array_Float_54));
    Rte_MemCpy(Rte_swc_CIL_CIL_TMdulCtlr_CIL_TMdulCtlr, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_TMdulCtlr_CIL_TMdulCtlr.value, sizeof(rt_Array_Float_32));
    Rte_MemCpy(Rte_swc_CIL_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE.value, sizeof(rt_Array_Float_24));
    Rte_swc_CIL_CIL_UEACAct_CIL_UEACAct = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_UEACAct_CIL_UEACAct.value);
    Rte_swc_CIL_CIL_UObcChInp_CIL_UObcChInp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_UObcChInp_CIL_UObcChInp.value);
    Rte_swc_CIL_CIL_UObcChOutp_CIL_UObcChOutp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_UObcChOutp_CIL_UObcChOutp.value);
    Rte_swc_CIL_CIL_VehicleSpeedInvalid_CIL_VehicleSpeedInvalid = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_VehicleSpeedInvalid_CIL_VehicleSpeedInvalid.value);
    Rte_swc_CIL_CIL_YearTelbox_CIL_YearTelbox = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_YearTelbox_CIL_YearTelbox.value);
    Rte_swc_CIL_CIL_ZeroPwrFb_CIL_ZeroPwrFb = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_ZeroPwrFb_CIL_ZeroPwrFb.value);
    Rte_swc_CIL_CIL_bDCDCW_CIL_bDCDCW = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_bDCDCW_CIL_bDCDCW.value);
    Rte_swc_CIL_ClL_InletWaterTemp_ClL_InletWaterTemp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_ClL_InletWaterTemp_ClL_InletWaterTemp.value);
    Rte_swc_CIL_ClL_OutletWaterTemp_ClL_OutletWaterTemp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_ClL_OutletWaterTemp_ClL_OutletWaterTemp.value);
    Rte_swc_CIL_MCC_NrAFETot_MCC_NrAFETot = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrAFETot_MCC_NrAFETot.value);
    Rte_MemCpy(Rte_swc_CIL_MCC_NrCellByMdul_MCC_NrCellByMdul, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrCellByMdul_MCC_NrCellByMdul.value, sizeof(rt_Array_UInt8_24));
    Rte_swc_CIL_MCC_NrCellTot_MCC_NrCellTot = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrCellTot_MCC_NrCellTot.value);
    Rte_MemCpy(Rte_swc_CIL_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul.value, sizeof(rt_Array_UInt8_24));
    Rte_swc_CIL_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot.value);
    Rte_swc_CIL_MCC_NrMdulTot_MCC_NrMdulTot = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrMdulTot_MCC_NrMdulTot.value);
    Rte_MemCpy(Rte_swc_CIL_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul.value, sizeof(rt_Array_UInt8_24));
    Rte_swc_CIL_MCC_NrSnsrTTot_MCC_NrSnsrTTot = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrSnsrTTot_MCC_NrSnsrTTot.value);


    Rte_swc_CIL_CIL_ChargeModeReq_CIL_ChargeModeReq = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_ChargeModeReq_CIL_ChargeModeReq.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_CIL_CIL_ChargeModeReq_CIL_ChargeModeReq = RTE_COM_SENDSIGNALPROXY_SEND;

    swc_SetInput_100ms();

    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BCF_SocPack_BCF_SocPack.value) = Rte_swc_BatCoreFct_BCF_SocPack_BCF_SocPack;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value) = Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BSOF_UChrgr_BSOF_UChrgr.value) = Rte_swc_CIL_BSOF_UChrgr_BSOF_UChrgr;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BSTC_StBcu_BSTC_StBcu.value) = Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_BatCoolType_CIL_BatCoolType.value) = Rte_swc_CIL_CIL_BatCoolType_CIL_BatCoolType;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_IBatHv_CIL_IBatHv.value) = Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_SpdVeh_CIL_SpdVeh.value) = Rte_swc_CIL_CIL_SpdVeh_CIL_SpdVeh;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_StCellT_CIL_StCellT.value, Rte_swc_CIL_CIL_StCellT_CIL_StCellT, sizeof(rt_Array_UInt8_54));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_StProj_CIL_StProj.value) = Rte_swc_CIL_CIL_StProj_CIL_StProj;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_TBd_CIL_TBd.value) = Rte_swc_CIL_CIL_TBd_CIL_TBd;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_TBdSnsr_CIL_TBdSnsr.value, Rte_swc_CIL_CIL_TBdSnsr_CIL_TBdSnsr, sizeof(rt_Array_Float_32));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr.value) = Rte_swc_CIL_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr.value) = Rte_swc_CIL_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_TMdul_CIL_TMdul.value, Rte_swc_CIL_CIL_TMdul_CIL_TMdul, sizeof(rt_Array_Float_54));
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_TMdulCtlr_CIL_TMdulCtlr.value, Rte_swc_CIL_CIL_TMdulCtlr_CIL_TMdulCtlr, sizeof(rt_Array_Float_32));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_TSnsrI_CIL_TSnsrI.value) = Rte_swc_CIL_CIL_TSnsrI_CIL_TSnsrI;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_UObcChOutp_CIL_UObcChOutp.value) = Rte_swc_CIL_CIL_UObcChOutp_CIL_UObcChOutp;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_bDCDCW_CIL_bDCDCW.value) = Rte_swc_CIL_CIL_bDCDCW_CIL_bDCDCW;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg.value) = Rte_swc_CIL_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CTC_StHvbat_CTC_StHvbat.value) = Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CTC_StRlyHeat_CTC_StRlyHeat.value) = Rte_swc_CtctrTranCtl_CTC_StRlyHeat_CTC_StRlyHeat;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CTC_StRlyPos_CTC_StRlyPos.value) = Rte_swc_CtctrTranCtl_CTC_StRlyPos_CTC_StRlyPos;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CTC_bAcvRePrechFnshd_CTC_bAcvRePrechFnshd.value) = Rte_swc_CtctrTranCtl_CTC_bAcvRePrechFnshd_CTC_bAcvRePrechFnshd;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_DEH_bAcvHeatInh_DEH_bAcvHeatInh.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvHeatInh_DEH_bAcvHeatInh;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_MCC_NrAFETot_MCC_NrAFETot.value) = Rte_swc_CIL_MCC_NrAFETot_MCC_NrAFETot;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot.value) = Rte_swc_CIL_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_MCC_NrMdulTot_MCC_NrMdulTot.value) = Rte_swc_CIL_MCC_NrMdulTot_MCC_NrMdulTot;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul.value, Rte_swc_CIL_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul, sizeof(rt_Array_UInt8_24));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_MCC_NrSnsrTTot_MCC_NrSnsrTTot.value) = Rte_swc_CIL_MCC_NrSnsrTTot_MCC_NrSnsrTTot;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_MCC_StMdulCu_MCC_StMdulCu.value) = Rte_swc_CIL_MCC_StMdulCu_MCC_StMdulCu;
    BTHM_100ms();
    Rte_swc_BatThermHndlgMngt_BTHM_ErrChEnd_BTHM_ErrChEnd = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_ErrChEnd_BTHM_ErrChEnd.value);
    Rte_swc_BatThermHndlgMngt_BTHM_ErrInfo_BTHM_ErrInfo = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_ErrInfo_BTHM_ErrInfo.value);
    Rte_swc_BatThermHndlgMngt_BTHM_IdCellTMax_BTHM_IdCellTMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_IdCellTMax_BTHM_IdCellTMax.value);
    Rte_swc_BatThermHndlgMngt_BTHM_IdCellTMin_BTHM_IdCellTMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_IdCellTMin_BTHM_IdCellTMin.value);
    Rte_swc_BatThermHndlgMngt_BTHM_IdMdulTMax_BTHM_IdMdulTMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_IdMdulTMax_BTHM_IdMdulTMax.value);
    Rte_swc_BatThermHndlgMngt_BTHM_IdMdulTMin_BTHM_IdMdulTMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_IdMdulTMin_BTHM_IdMdulTMin.value);
    Rte_MemCpy(Rte_swc_BatThermHndlgMngt_BTHM_MfCoolt_BTHM_MfCoolt, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_MfCoolt_BTHM_MfCoolt.value, sizeof(rt_Array_Float_24));
    Rte_swc_BatThermHndlgMngt_BTHM_ReqRePrech_BTHM_ReqRePrech = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_ReqRePrech_BTHM_ReqRePrech.value);
    Rte_swc_BatThermHndlgMngt_BTHM_StErrTOver_BTHM_StErrTOver = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_StErrTOver_BTHM_StErrTOver.value);
    Rte_swc_BatThermHndlgMngt_BTHM_StRlyHeatReq_BTHM_StRlyHeatReq = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_StRlyHeatReq_BTHM_StRlyHeatReq.value);
    Rte_swc_BatThermHndlgMngt_BTHM_StRlyMain_BTHM_StRlyMain = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_StRlyMain_BTHM_StRlyMain.value);
    Rte_swc_BatThermHndlgMngt_BTHM_StRlyMainNeg_BTHM_StRlyMainNeg = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_StRlyMainNeg_BTHM_StRlyMainNeg.value);
    Rte_swc_BatThermHndlgMngt_BTHM_StSys_BTHM_StSys = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_StSys_BTHM_StSys.value);
    Rte_swc_BatThermHndlgMngt_BTHM_StThermReq_BTHM_StThermReq = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_StThermReq_BTHM_StThermReq.value);
    Rte_swc_BatThermHndlgMngt_BTHM_TBatTgt_BTHM_TBatTgt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TBatTgt_BTHM_TBatTgt.value);
    Rte_swc_BatThermHndlgMngt_BTHM_TBcuSnsr_BTHM_TBcuSnsr = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TBcuSnsr_BTHM_TBcuSnsr.value);
    Rte_swc_BatThermHndlgMngt_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr.value);
    Rte_swc_BatThermHndlgMngt_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr.value);
    Rte_MemCpy(Rte_swc_BatThermHndlgMngt_BTHM_TMdulCorrn_BTHM_TMdulCorrn, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulCorrn_BTHM_TMdulCorrn.value, sizeof(rt_Array_Float_54));
    Rte_MemCpy(Rte_swc_BatThermHndlgMngt_BTHM_TMdulCtlrSnsr_BTHM_TMdulCtlrSnsr, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulCtlrSnsr_BTHM_TMdulCtlrSnsr.value, sizeof(rt_Array_Float_32));
    Rte_swc_BatThermHndlgMngt_BTHM_TMdulCtlrSnsrMax_BTHM_TMdulCtlrSnsrMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulCtlrSnsrMax_BTHM_TMdulCtlrSnsrMax.value);
    Rte_swc_BatThermHndlgMngt_BTHM_TMdulCtlrSnsrMin_BTHM_TMdulCtlrSnsrMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulCtlrSnsrMin_BTHM_TMdulCtlrSnsrMin.value);
    Rte_MemCpy(Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsr_BTHM_TMdulSnsr, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulSnsr_BTHM_TMdulSnsr.value, sizeof(rt_Array_Float_54));
    Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value);
    Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMaxRaw_BTHM_TMdulSnsrMaxRaw = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulSnsrMaxRaw_BTHM_TMdulSnsrMaxRaw.value);
    Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value);
    Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw.value);
    Rte_MemCpy(Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrRaw_BTHM_TMdulSnsrRaw, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulSnsrRaw_BTHM_TMdulSnsrRaw.value, sizeof(rt_Array_Float_54));
    Rte_swc_BatThermHndlgMngt_BTHM_TOptmMax_BTHM_TOptmMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TOptmMax_BTHM_TOptmMax.value);
    Rte_swc_BatThermHndlgMngt_BTHM_TOptmMin_BTHM_TOptmMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TOptmMin_BTHM_TOptmMin.value);
    Rte_swc_BatThermHndlgMngt_BTHM_TPack_BTHM_TPack = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TPack_BTHM_TPack.value);
    Rte_swc_BatThermHndlgMngt_BTHM_bAcvDig64_BTHM_bAcvDig64 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_bAcvDig64_BTHM_bAcvDig64.value);
    Rte_swc_BatThermHndlgMngt_BTHM_bAcvDig93_BTHM_bAcvDig93 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_bAcvDig93_BTHM_bAcvDig93.value);
    Rte_MemCpy(Rte_swc_BatThermHndlgMngt_BTHM_bAcvTAbno_BTHM_bAcvTAbno, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_bAcvTAbno_BTHM_bAcvTAbno.value, sizeof(rt_Array_Boolean_24));
    Rte_MemCpy(Rte_swc_BatThermHndlgMngt_BTHM_bErrSnsrT_BTHM_bErrSnsrT, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_bErrSnsrT_BTHM_bErrSnsrT.value, sizeof(rt_Array_Boolean_24));

    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BCC_IObcLimn_BCC_IObcLimn.value) = Rte_swc_BatChCtl_BCC_IObcLimn_BCC_IObcLimn;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BCF_IChLim_BCF_IChLim.value) = Rte_swc_BatCoreFct_BCF_IChLim_BCF_IChLim;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BCF_IDchaLim_BCF_IDchaLim.value) = Rte_swc_BatCoreFct_BCF_IDchaLim_BCF_IDchaLim;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BCF_UCellAvg_BCF_UCellAvg.value) = Rte_swc_BatCoreFct_BCF_UCellAvg_BCF_UCellAvg;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BMC_UCell_BMC_UCell.value, Rte_swc_CIL_BMC_UCell_BMC_UCell, sizeof(rt_Array_Float_255));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BPIU_UCellMax_BPIU_UCellMax.value) = Rte_swc_BatProtnIU_BPIU_UCellMax_BPIU_UCellMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BPIU_UCellMin_BPIU_UCellMin.value) = Rte_swc_BatProtnIU_BPIU_UCellMin_BPIU_UCellMin;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BSTC_StBcu_BSTC_StBcu.value) = Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_CIL_IBatHv_CIL_IBatHv.value) = Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE.value, Rte_swc_CIL_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE, sizeof(rt_Array_Float_24));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_CTC_StHvbat_CTC_StHvbat.value) = Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_DEH_CtrBalCtlDiag_DEH_CtrBalCtlDiag.value) = Rte_swc_DiagcEveHndlg_DEH_CtrBalCtlDiag_DEH_CtrBalCtlDiag;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_DEH_IdxCellBalCtl_DEH_IdxCellBalCtl.value) = Rte_swc_DiagcEveHndlg_DEH_IdxCellBalCtl_DEH_IdxCellBalCtl;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_DEH_LvlErr_DEH_LvlErr.value) = Rte_swc_DiagcEveHndlg_DEH_LvlErr_DEH_LvlErr;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_DEH_ModBalCtl_DEH_ModBalCtl.value) = Rte_swc_DiagcEveHndlg_DEH_ModBalCtl_DEH_ModBalCtl;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_DEH_ReqBalCtl_DEH_ReqBalCtl.value) = Rte_swc_DiagcEveHndlg_DEH_ReqBalCtl_DEH_ReqBalCtl;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_MCC_NrCellByMdul_MCC_NrCellByMdul.value, Rte_swc_CIL_MCC_NrCellByMdul_MCC_NrCellByMdul, sizeof(rt_Array_UInt8_24));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_MCC_NrMdulTot_MCC_NrMdulTot.value) = Rte_swc_CIL_MCC_NrMdulTot_MCC_NrMdulTot;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln.value, Rte_swc_DiagcEveHndlg_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln, sizeof(rt_Array_UInt8_255));
    BBC_100ms();
    Rte_MemCpy(Rte_swc_BatBalnCtl_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp.value, sizeof(rt_Array_UInt32_24));
    Rte_MemCpy(Rte_swc_BatBalnCtl_BBC_AcvCellTgtReqdOutp_BBC_AcvCellTgtReqdOutp, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_AcvCellTgtReqdOutp_BBC_AcvCellTgtReqdOutp.value, sizeof(rt_Array_UInt16_24));
    Rte_MemCpy(Rte_swc_BatBalnCtl_BBC_CtrBalnReqdOutp_BBC_CtrBalnReqdOutp, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_CtrBalnReqdOutp_BBC_CtrBalnReqdOutp.value, sizeof(rt_Array_UInt16_24));
    Rte_MemCpy(Rte_swc_BatBalnCtl_BBC_ICellBaln_BBC_ICellBaln, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_ICellBaln_BBC_ICellBaln.value, sizeof(rt_Array_Float_255));
    Rte_MemCpy(Rte_swc_BatBalnCtl_BBC_NrMdulSrcReqdOutp_BBC_NrMdulSrcReqdOutp, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_NrMdulSrcReqdOutp_BBC_NrMdulSrcReqdOutp.value, sizeof(rt_Array_UInt8_24));
    Rte_MemCpy(Rte_swc_BatBalnCtl_BBC_NrMdulTgtReqdOutp_BBC_NrMdulTgtReqdOutp, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_NrMdulTgtReqdOutp_BBC_NrMdulTgtReqdOutp.value, sizeof(rt_Array_UInt8_24));
    Rte_MemCpy(Rte_swc_BatBalnCtl_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv.value, sizeof(rt_Array_UInt8_255));
    Rte_swc_BatBalnCtl_BBC_TiCtlBalMaxLim_BBC_TiCtlBalMaxLim = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_TiCtlBalMaxLim_BBC_TiCtlBalMaxLim.value);
    Rte_swc_BatBalnCtl_BBC_bAcvBaln_BBC_bAcvBaln = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_bAcvBaln_BBC_bAcvBaln.value);
    Rte_MemCpy(Rte_swc_BatBalnCtl_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln.value, sizeof(rt_Array_Boolean_24));

    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BBC_ICellBaln_BBC_ICellBaln.value, Rte_swc_BatBalnCtl_BBC_ICellBaln_BBC_ICellBaln, sizeof(rt_Array_Float_255));
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln.value, Rte_swc_BatBalnCtl_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln, sizeof(rt_Array_Boolean_24));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCC_bAcvHvbatFull_BCC_bAcvHvbatFull.value) = Rte_swc_BatChCtl_BCC_bAcvHvbatFull_BCC_bAcvHvbatFull;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BMC_UCell_BMC_UCell.value, Rte_swc_CIL_BMC_UCell_BMC_UCell, sizeof(rt_Array_Float_255));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BPIU_UCellMax_BPIU_UCellMax.value) = Rte_swc_BatProtnIU_BPIU_UCellMax_BPIU_UCellMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BPIU_UCellMin_BPIU_UCellMin.value) = Rte_swc_BatProtnIU_BPIU_UCellMin_BPIU_UCellMin;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BPP_bAcvCTest_BPP_bAcvCTest.value) = Rte_swc_BatProtnPack_BPP_bAcvCTest_BPP_bAcvCTest;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BSTC_RstCmd100_BSTC_RstCmd100.value) = Rte_swc_BcuStTranCtl_BSTC_RstCmd100_BSTC_RstCmd100;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BSTC_StBcu_BSTC_StBcu.value) = Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BSTC_TiBatOff_BSTC_TiBatOff.value) = Rte_swc_BcuStTranCtl_BSTC_TiBatOff_BSTC_TiBatOff;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BTHM_MfCoolt_BTHM_MfCoolt.value, Rte_swc_BatThermHndlgMngt_BTHM_MfCoolt_BTHM_MfCoolt, sizeof(rt_Array_Float_24));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr.value) = Rte_swc_BatThermHndlgMngt_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BTHM_TMdulCorrn_BTHM_TMdulCorrn.value, Rte_swc_BatThermHndlgMngt_BTHM_TMdulCorrn_BTHM_TMdulCorrn, sizeof(rt_Array_Float_54));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BTHM_TPack_BTHM_TPack.value) = Rte_swc_BatThermHndlgMngt_BTHM_TPack_BTHM_TPack;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BTHM_bAcvTAbno_BTHM_bAcvTAbno.value, Rte_swc_BatThermHndlgMngt_BTHM_bAcvTAbno_BTHM_bAcvTAbno, sizeof(rt_Array_Boolean_24));
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BTHM_bErrSnsrT_BTHM_bErrSnsrT.value, Rte_swc_BatThermHndlgMngt_BTHM_bErrSnsrT_BTHM_bErrSnsrT, sizeof(rt_Array_Boolean_24));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_CIL_IBatHv_CIL_IBatHv.value) = Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_CIL_SecRtc_CIL_SecRtc.value) = Rte_swc_CIL_CIL_SecRtc_CIL_SecRtc;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul.value, Rte_swc_CIL_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul, sizeof(rt_Array_UInt8_24));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg.value) = Rte_swc_CIL_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg.value) = Rte_swc_CIL_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_CTC_StHvbat_CTC_StHvbat.value) = Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag.value) = Rte_swc_DiagcEveHndlg_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_CtrPackSocSetDiag_DEH_CtrPackSocSetDiag.value) = Rte_swc_DiagcEveHndlg_DEH_CtrPackSocSetDiag_DEH_CtrPackSocSetDiag;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_ErrCfmd2_DEH_ErrCfmd2.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd2_DEH_ErrCfmd2;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_ErrCfmd6_DEH_ErrCfmd6.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd6_DEH_ErrCfmd6;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_ErrHisCfmd_DEH_ErrHisCfmd.value) = Rte_swc_DiagcEveHndlg_DEH_ErrHisCfmd_DEH_ErrHisCfmd;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_StSocCal_DEH_StSocCal.value) = Rte_swc_DiagcEveHndlg_DEH_StSocCal_DEH_StSocCal;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_StsIninNv_DEH_StsIninNv.value) = Rte_swc_DiagcEveHndlg_DEH_StsIninNv_DEH_StsIninNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_TiChFullOff_DEH_TiChFullOff.value) = Rte_swc_DiagcEveHndlg_DEH_TiChFullOff_DEH_TiChFullOff;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_ValPackSoc_DEH_ValPackSoc.value) = Rte_swc_DiagcEveHndlg_DEH_ValPackSoc_DEH_ValPackSoc;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_bAcvBdNew_DEH_bAcvBdNew.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvBdNew_DEH_bAcvBdNew;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_MCC_NrCellByMdul_MCC_NrCellByMdul.value, Rte_swc_CIL_MCC_NrCellByMdul_MCC_NrCellByMdul, sizeof(rt_Array_UInt8_24));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_MCC_NrMdulTot_MCC_NrMdulTot.value) = Rte_swc_CIL_MCC_NrMdulTot_MCC_NrMdulTot;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul.value, Rte_swc_CIL_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul, sizeof(rt_Array_UInt8_24));
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls.value, Rte_swc_DiagcEveHndlg_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls, sizeof(rt_Array_Float_24));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_ChIIntglFls_NVM_ChIIntglFls.value) = Rte_swc_DiagcEveHndlg_NVM_ChIIntglFls_NVM_ChIIntglFls;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_ChgDeltAh_NVM_ChgDeltAh.value) = Rte_swc_DiagcEveHndlg_NVM_ChgDeltAh_NVM_ChgDeltAh;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_DeltAh_NVM_DeltAh.value) = Rte_swc_DiagcEveHndlg_NVM_DeltAh_NVM_DeltAh;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_EBatChTot_NVM_EBatChTot.value) = Rte_swc_DiagcEveHndlg_NVM_EBatChTot_NVM_EBatChTot;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_FullChgSOH_NVM_FullChgSOH.value) = Rte_swc_DiagcEveHndlg_NVM_FullChgSOH_NVM_FullChgSOH;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_IIntglFls_NVM_IIntglFls.value) = Rte_swc_DiagcEveHndlg_NVM_IIntglFls_NVM_IIntglFls;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls.value, Rte_swc_DiagcEveHndlg_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls, sizeof(rt_Array_Float_24));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg.value) = Rte_swc_DiagcEveHndlg_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg.value) = Rte_swc_DiagcEveHndlg_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SocCnsAct_NVM_SocCnsAct.value) = Rte_swc_DiagcEveHndlg_NVM_SocCnsAct_NVM_SocCnsAct;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SocPackScld_NVM_SocPackScld.value) = Rte_swc_DiagcEveHndlg_NVM_SocPackScld_NVM_SocPackScld;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SocUOcIni_NVM_SocUOcIni.value) = Rte_swc_DiagcEveHndlg_NVM_SocUOcIni_NVM_SocUOcIni;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SohCalFls_NVM_SohCalFls.value) = Rte_swc_DiagcEveHndlg_NVM_SohCalFls_NVM_SohCalFls;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SohCycFls_NVM_SohCycFls.value) = Rte_swc_DiagcEveHndlg_NVM_SohCycFls_NVM_SohCycFls;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SohPackFls_NVM_SohPackFls.value) = Rte_swc_DiagcEveHndlg_NVM_SohPackFls_NVM_SohPackFls;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SohRDeltaFls_NVM_SohRDeltaFls.value, Rte_swc_DiagcEveHndlg_NVM_SohRDeltaFls_NVM_SohRDeltaFls, sizeof(rt_Array_Float_24));
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls.value, Rte_swc_DiagcEveHndlg_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls, sizeof(rt_Array_Float_24));
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_StAryFls_NVM_StAryFls.value, Rte_swc_DiagcEveHndlg_NVM_StAryFls_NVM_StAryFls, sizeof(rt_Array_Float_144));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_TPackFls_NVM_TPackFls.value) = Rte_swc_DiagcEveHndlg_NVM_TPackFls_NVM_TPackFls;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_TiBatOffFls_NVM_TiBatOffFls.value) = Rte_swc_DiagcEveHndlg_NVM_TiBatOffFls_NVM_TiBatOffFls;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls.value, Rte_swc_DiagcEveHndlg_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls, sizeof(rt_Array_UInt32_24));
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls.value, Rte_swc_DiagcEveHndlg_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls, sizeof(rt_Array_UInt32_24));
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls.value, Rte_swc_DiagcEveHndlg_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls, sizeof(rt_Array_UInt8_24));
    BCF_100ms();
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_CMdulAbsv_BCF_CMdulAbsv, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_CMdulAbsv_BCF_CMdulAbsv.value, sizeof(rt_Array_Float_24));
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv.value, sizeof(rt_Array_Float_24));
    Rte_swc_BatCoreFct_BCF_ChIIntglNv_BCF_ChIIntglNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ChIIntglNv_BCF_ChIIntglNv.value);
    Rte_swc_BatCoreFct_BCF_ChgDeltAhNv_BCF_ChgDeltAhNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ChgDeltAhNv_BCF_ChgDeltAhNv.value);
    Rte_swc_BatCoreFct_BCF_DeltAhNv_BCF_DeltAhNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_DeltAhNv_BCF_DeltAhNv.value);
    Rte_swc_BatCoreFct_BCF_EPackRmng_BCF_EPackRmng = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_EPackRmng_BCF_EPackRmng.value);
    Rte_swc_BatCoreFct_BCF_EnaPack_BCF_EnaPack = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_EnaPack_BCF_EnaPack.value);
    Rte_swc_BatCoreFct_BCF_ErrInfo_BCF_ErrInfo = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo_BCF_ErrInfo.value);
    Rte_swc_BatCoreFct_BCF_ErrInfo1_BCF_ErrInfo1 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo1_BCF_ErrInfo1.value);
    Rte_swc_BatCoreFct_BCF_ErrInfo2_BCF_ErrInfo2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo2_BCF_ErrInfo2.value);
    Rte_swc_BatCoreFct_BCF_ErrInfo3_BCF_ErrInfo3 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo3_BCF_ErrInfo3.value);
    Rte_swc_BatCoreFct_BCF_ErrInfo4_BCF_ErrInfo4 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo4_BCF_ErrInfo4.value);
    Rte_swc_BatCoreFct_BCF_ErrInfo5_BCF_ErrInfo5 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo5_BCF_ErrInfo5.value);
    Rte_swc_BatCoreFct_BCF_ErrInfo6_BCF_ErrInfo6 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo6_BCF_ErrInfo6.value);
    Rte_swc_BatCoreFct_BCF_FullChgSOHNv_BCF_FullChgSOHNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_FullChgSOHNv_BCF_FullChgSOHNv.value);
    Rte_swc_BatCoreFct_BCF_IChLimInt_BCF_IChLimInt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IChLimInt_BCF_IChLimInt.value);
    Rte_swc_BatCoreFct_BCF_IChLimMap_BCF_IChLimMap = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IChLimMap_BCF_IChLimMap.value);
    Rte_swc_BatCoreFct_BCF_IChMax_BCF_IChMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IChMax_BCF_IChMax.value);
    Rte_swc_BatCoreFct_BCF_IChPredLimInt_BCF_IChPredLimInt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IChPredLimInt_BCF_IChPredLimInt.value);
    Rte_swc_BatCoreFct_BCF_IDchaLimInt_BCF_IDchaLimInt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IDchaLimInt_BCF_IDchaLimInt.value);
    Rte_swc_BatCoreFct_BCF_IDchaLimMap_BCF_IDchaLimMap = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IDchaLimMap_BCF_IDchaLimMap.value);
    Rte_swc_BatCoreFct_BCF_IDchaMax_BCF_IDchaMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IDchaMax_BCF_IDchaMax.value);
    Rte_swc_BatCoreFct_BCF_IDchaPredLimInt_BCF_IDchaPredLimInt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IDchaPredLimInt_BCF_IDchaPredLimInt.value);
    Rte_swc_BatCoreFct_BCF_IIntglNv_BCF_IIntglNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IIntglNv_BCF_IIntglNv.value);
    Rte_swc_BatCoreFct_BCF_NrMdulMax_BCF_NrMdulMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_NrMdulMax_BCF_NrMdulMax.value);
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_PwrMdulLoss_BCF_PwrMdulLoss, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_PwrMdulLoss_BCF_PwrMdulLoss.value, sizeof(rt_Array_Float_24));
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv.value, sizeof(rt_Array_Float_24));
    Rte_swc_BatCoreFct_BCF_RPackInt_BCF_RPackInt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_RPackInt_BCF_RPackInt.value);
    Rte_swc_BatCoreFct_BCF_SOHCalFulChgFlgNv_BCF_SOHCalFulChgFlgNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SOHCalFulChgFlgNv_BCF_SOHCalFulChgFlgNv.value);
    Rte_swc_BatCoreFct_BCF_SOHCalOCVFlgNv_BCF_SOHCalOCVFlgNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SOHCalOCVFlgNv_BCF_SOHCalOCVFlgNv.value);
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_SocCell_BCF_SocCell, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocCell_BCF_SocCell.value, sizeof(rt_Array_Float_255));
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_SocCellDelta_BCF_SocCellDelta, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocCellDelta_BCF_SocCellDelta.value, sizeof(rt_Array_Float_255));
    Rte_swc_BatCoreFct_BCF_SocCellMax_BCF_SocCellMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocCellMax_BCF_SocCellMax.value);
    Rte_swc_BatCoreFct_BCF_SocCellMin_BCF_SocCellMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocCellMin_BCF_SocCellMin.value);
    Rte_swc_BatCoreFct_BCF_SocCnsActNv_BCF_SocCnsActNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocCnsActNv_BCF_SocCnsActNv.value);
    Rte_swc_BatCoreFct_BCF_SocLimMax_BCF_SocLimMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocLimMax_BCF_SocLimMax.value);
    Rte_swc_BatCoreFct_BCF_SocLimMin_BCF_SocLimMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocLimMin_BCF_SocLimMin.value);
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_SocMdul_BCF_SocMdul, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocMdul_BCF_SocMdul.value, sizeof(rt_Array_Float_24));
    Rte_swc_BatCoreFct_BCF_SocPack_BCF_SocPack = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocPack_BCF_SocPack.value);
    Rte_swc_BatCoreFct_BCF_SocPackScld_BCF_SocPackScld = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocPackScld_BCF_SocPackScld.value);
    Rte_swc_BatCoreFct_BCF_SocUOcIniNv_BCF_SocUOcIniNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocUOcIniNv_BCF_SocUOcIniNv.value);
    Rte_swc_BatCoreFct_BCF_SohCalNv_BCF_SohCalNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SohCalNv_BCF_SohCalNv.value);
    Rte_swc_BatCoreFct_BCF_SohCycNv_BCF_SohCycNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SohCycNv_BCF_SohCycNv.value);
    Rte_swc_BatCoreFct_BCF_SohPack_BCF_SohPack = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SohPack_BCF_SohPack.value);
    Rte_swc_BatCoreFct_BCF_SohPackNv_BCF_SohPackNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SohPackNv_BCF_SohPackNv.value);
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv.value, sizeof(rt_Array_Float_24));
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv.value, sizeof(rt_Array_Float_24));
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_StAryFlsNv_BCF_StAryFlsNv, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_StAryFlsNv_BCF_StAryFlsNv.value, sizeof(rt_Array_Float_144));
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_StLimnId_BCF_StLimnId, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_StLimnId_BCF_StLimnId.value, sizeof(rt_Array_UInt8_4));
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_TCooltMdulOut_BCF_TCooltMdulOut, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_TCooltMdulOut_BCF_TCooltMdulOut.value, sizeof(rt_Array_Float_24));
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_TMdulEstimd_BCF_TMdulEstimd, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_TMdulEstimd_BCF_TMdulEstimd.value, sizeof(rt_Array_Float_24));
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv.value, sizeof(rt_Array_UInt32_24));
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv.value, sizeof(rt_Array_UInt32_24));
    Rte_swc_BatCoreFct_BCF_TiBatOffNv_BCF_TiBatOffNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_TiBatOffNv_BCF_TiBatOffNv.value);
    Rte_swc_BatCoreFct_BCF_TiChFullOff_BCF_TiChFullOff = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_TiChFullOff_BCF_TiChFullOff.value);
    Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value);
    Rte_swc_BatCoreFct_BCF_UCellAvg_BCF_UCellAvg = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UCellAvg_BCF_UCellAvg.value);
    Rte_swc_BatCoreFct_BCF_UChLimInt_BCF_UChLimInt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UChLimInt_BCF_UChLimInt.value);
    Rte_swc_BatCoreFct_BCF_UChPredLimInt_BCF_UChPredLimInt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UChPredLimInt_BCF_UChPredLimInt.value);
    Rte_swc_BatCoreFct_BCF_UDchaLimInt_BCF_UDchaLimInt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UDchaLimInt_BCF_UDchaLimInt.value);
    Rte_swc_BatCoreFct_BCF_UDchaPredLimInt_BCF_UDchaPredLimInt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UDchaPredLimInt_BCF_UDchaPredLimInt.value);
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_UMdul_BCF_UMdul, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UMdul_BCF_UMdul.value, sizeof(rt_Array_Float_24));
    Rte_swc_BatCoreFct_BCF_UPackCircOpen_BCF_UPackCircOpen = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UPackCircOpen_BCF_UPackCircOpen.value);
    Rte_swc_BatCoreFct_BCF_bChrgFullCalRemind_BCF_bChrgFullCalRemind = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_bChrgFullCalRemind_BCF_bChrgFullCalRemind.value);
    Rte_swc_BatCoreFct_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg.value);
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls.value, sizeof(rt_Array_UInt8_24));
    Rte_MemCpy(Rte_swc_BatCoreFct_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv, Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv.value, sizeof(rt_Array_UInt8_24));

    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BCF_EnaPack_BCF_EnaPack.value) = Rte_swc_BatCoreFct_BCF_EnaPack_BCF_EnaPack;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BCF_SocCell_BCF_SocCell.value, Rte_swc_BatCoreFct_BCF_SocCell_BCF_SocCell, sizeof(rt_Array_Float_255));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BCF_SocPackScld_BCF_SocPackScld.value) = Rte_swc_BatCoreFct_BCF_SocPackScld_BCF_SocPackScld;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BCF_SohPack_BCF_SohPack.value) = Rte_swc_BatCoreFct_BCF_SohPack_BCF_SohPack;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BTHM_TMdulSnsrMaxRaw_BTHM_TMdulSnsrMaxRaw.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMaxRaw_BTHM_TMdulSnsrMaxRaw;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag.value) = Rte_swc_DiagcEveHndlg_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_DEH_ErrCfmd2_DEH_ErrCfmd2.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd2_DEH_ErrCfmd2;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_MCC_NrCellTot_MCC_NrCellTot.value) = Rte_swc_CIL_MCC_NrCellTot_MCC_NrCellTot;
    BPP_100ms();
    Rte_swc_BatProtnPack_BPP_ErrCellT_BPP_ErrCellT = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_ErrCellT_BPP_ErrCellT.value);
    Rte_swc_BatProtnPack_BPP_ErrSocJmp_BPP_ErrSocJmp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_ErrSocJmp_BPP_ErrSocJmp.value);
    Rte_swc_BatProtnPack_BPP_ErrSocVal_BPP_ErrSocVal = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_ErrSocVal_BPP_ErrSocVal.value);
    Rte_swc_BatProtnPack_BPP_SocLimMax_BPP_SocLimMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_SocLimMax_BPP_SocLimMax.value);
    Rte_swc_BatProtnPack_BPP_SocLimMin_BPP_SocLimMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_SocLimMin_BPP_SocLimMin.value);
    Rte_swc_BatProtnPack_BPP_TCellMaxLim_BPP_TCellMaxLim = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_TCellMaxLim_BPP_TCellMaxLim.value);
    Rte_swc_BatProtnPack_BPP_TCellMinLim_BPP_TCellMinLim = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_TCellMinLim_BPP_TCellMinLim.value);

    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value) = Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BCF_UMdul_BCF_UMdul.value, Rte_swc_BatCoreFct_BCF_UMdul_BCF_UMdul, sizeof(rt_Array_Float_24));
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BMC_UCell_BMC_UCell.value, Rte_swc_CIL_BMC_UCell_BMC_UCell, sizeof(rt_Array_Float_255));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BSTC_StBcu_BSTC_StBcu.value) = Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value) = Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_CIL_bErrCtrBatUHv_CIL_bErrCtrBatUHv.value) = Rte_swc_CIL_CIL_bErrCtrBatUHv_CIL_bErrCtrBatUHv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg.value) = Rte_swc_CIL_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg.value) = Rte_swc_CIL_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly.value) = Rte_swc_CIL_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag.value) = Rte_swc_DiagcEveHndlg_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value) = Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_MCC_NrCellByMdul_MCC_NrCellByMdul.value, Rte_swc_CIL_MCC_NrCellByMdul_MCC_NrCellByMdul, sizeof(rt_Array_UInt8_24));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_MCC_NrCellTot_MCC_NrCellTot.value) = Rte_swc_CIL_MCC_NrCellTot_MCC_NrCellTot;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_MCC_NrMdulTot_MCC_NrMdulTot.value) = Rte_swc_CIL_MCC_NrMdulTot_MCC_NrMdulTot;
    BPIU_100ms();
    Rte_swc_BatProtnIU_BPIU_ErrCellU_BPIU_ErrCellU = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_ErrCellU_BPIU_ErrCellU.value);
    Rte_swc_BatProtnIU_BPIU_ErrCellUDif_BPIU_ErrCellUDif = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_ErrCellUDif_BPIU_ErrCellUDif.value);
    Rte_swc_BatProtnIU_BPIU_ErrCellUOver_BPIU_ErrCellUOver = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_ErrCellUOver_BPIU_ErrCellUOver.value);
    Rte_swc_BatProtnIU_BPIU_ErrUAcqn_BPIU_ErrUAcqn = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_ErrUAcqn_BPIU_ErrUAcqn.value);
    Rte_swc_BatProtnIU_BPIU_IdCellUMax_BPIU_IdCellUMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_IdCellUMax_BPIU_IdCellUMax.value);
    Rte_swc_BatProtnIU_BPIU_IdCellUMin_BPIU_IdCellUMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_IdCellUMin_BPIU_IdCellUMin.value);
    Rte_swc_BatProtnIU_BPIU_IdMdulForCellUMax_BPIU_IdMdulForCellUMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_IdMdulForCellUMax_BPIU_IdMdulForCellUMax.value);
    Rte_swc_BatProtnIU_BPIU_IdMdulForCellUMin_BPIU_IdMdulForCellUMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_IdMdulForCellUMin_BPIU_IdMdulForCellUMin.value);
    Rte_swc_BatProtnIU_BPIU_StCellUChkOverMax_BPIU_StCellUChkOverMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_StCellUChkOverMax_BPIU_StCellUChkOverMax.value);
    Rte_swc_BatProtnIU_BPIU_StCellUChkOverMin_BPIU_StCellUChkOverMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_StCellUChkOverMin_BPIU_StCellUChkOverMin.value);
    Rte_swc_BatProtnIU_BPIU_UCellMax_BPIU_UCellMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_UCellMax_BPIU_UCellMax.value);
    Rte_swc_BatProtnIU_BPIU_UCellMin_BPIU_UCellMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_UCellMin_BPIU_UCellMin.value);

    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BCF_SocPack_BCF_SocPack.value) = Rte_swc_BatCoreFct_BCF_SocPack_BCF_SocPack;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BPIU_UCellMax_BPIU_UCellMax.value) = Rte_swc_BatProtnIU_BPIU_UCellMax_BPIU_UCellMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BPIU_UCellMin_BPIU_UCellMin.value) = Rte_swc_BatProtnIU_BPIU_UCellMin_BPIU_UCellMin;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BPP_IAct_BPP_IAct.value) = Rte_swc_BatProtnPack_BPP_IAct_BPP_IAct;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BPP_PwrAct_BPP_PwrAct.value) = Rte_swc_BatProtnPack_BPP_PwrAct_BPP_PwrAct;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BSTC_StBcu_BSTC_StBcu.value) = Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BSTC_TrigCh_BSTC_TrigCh.value) = Rte_swc_BcuStTranCtl_BSTC_TrigCh_BSTC_TrigCh;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_CIL_IBatHv_CIL_IBatHv.value) = Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value) = Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_CTC_StHvbat_CTC_StHvbat.value) = Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_CTC_StLoopHv_CTC_StLoopHv.value) = Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_CTC_bAcvCh_CTC_bAcvCh.value) = Rte_swc_CtctrTranCtl_CTC_bAcvCh_CTC_bAcvCh;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_DEH_LvlErr_DEH_LvlErr.value) = Rte_swc_DiagcEveHndlg_DEH_LvlErr_DEH_LvlErr;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_DEH_StsIninNv_DEH_StsIninNv.value) = Rte_swc_DiagcEveHndlg_DEH_StsIninNv_DEH_StsIninNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_DEH_bAcvBdNew_DEH_bAcvBdNew.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvBdNew_DEH_bAcvBdNew;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_MCC_StMdulCu_MCC_StMdulCu.value) = Rte_swc_CIL_MCC_StMdulCu_MCC_StMdulCu;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_CBatChTot_NVM_CBatChTot.value) = Rte_swc_DiagcEveHndlg_NVM_CBatChTot_NVM_CBatChTot;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_CBatDchaTot_NVM_CBatDchaTot.value) = Rte_swc_DiagcEveHndlg_NVM_CBatDchaTot_NVM_CBatDchaTot;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot.value) = Rte_swc_DiagcEveHndlg_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_CtrCh_NVM_CtrCh.value) = Rte_swc_DiagcEveHndlg_NVM_CtrCh_NVM_CtrCh;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_CtrDcha_NVM_CtrDcha.value) = Rte_swc_DiagcEveHndlg_NVM_CtrDcha_NVM_CtrDcha;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_EBatChTot_NVM_EBatChTot.value) = Rte_swc_DiagcEveHndlg_NVM_EBatChTot_NVM_EBatChTot;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_EBatDchaTot_NVM_EBatDchaTot.value) = Rte_swc_DiagcEveHndlg_NVM_EBatDchaTot_NVM_EBatDchaTot;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot.value) = Rte_swc_DiagcEveHndlg_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_IBatChMax_NVM_IBatChMax.value) = Rte_swc_DiagcEveHndlg_NVM_IBatChMax_NVM_IBatChMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_IBatDchaMax_NVM_IBatDchaMax.value) = Rte_swc_DiagcEveHndlg_NVM_IBatDchaMax_NVM_IBatDchaMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_PBatChMax_NVM_PBatChMax.value) = Rte_swc_DiagcEveHndlg_NVM_PBatChMax_NVM_PBatChMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_PBatDchaMax_NVM_PBatDchaMax.value) = Rte_swc_DiagcEveHndlg_NVM_PBatDchaMax_NVM_PBatDchaMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_SocBatMax_NVM_SocBatMax.value) = Rte_swc_DiagcEveHndlg_NVM_SocBatMax_NVM_SocBatMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_SocBatMin_NVM_SocBatMin.value) = Rte_swc_DiagcEveHndlg_NVM_SocBatMin_NVM_SocBatMin;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax.value) = Rte_swc_DiagcEveHndlg_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin.value) = Rte_swc_DiagcEveHndlg_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax.value) = Rte_swc_DiagcEveHndlg_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin.value) = Rte_swc_DiagcEveHndlg_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax.value) = Rte_swc_DiagcEveHndlg_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin.value) = Rte_swc_DiagcEveHndlg_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_UCellMax_NVM_UCellMax.value) = Rte_swc_DiagcEveHndlg_NVM_UCellMax_NVM_UCellMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_UCellMin_NVM_UCellMin.value) = Rte_swc_DiagcEveHndlg_NVM_UCellMin_NVM_UCellMin;
    BWLD_100ms();
    Rte_swc_BatWntyLogtcData_BWLD_CBatChTot_BWLD_CBatChTot = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CBatChTot_BWLD_CBatChTot.value);
    Rte_swc_BatWntyLogtcData_BWLD_CBatChTotNv_BWLD_CBatChTotNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CBatChTotNv_BWLD_CBatChTotNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_CBatDchaTot_BWLD_CBatDchaTot = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CBatDchaTot_BWLD_CBatDchaTot.value);
    Rte_swc_BatWntyLogtcData_BWLD_CBatDchaTotNv_BWLD_CBatDchaTotNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CBatDchaTotNv_BWLD_CBatDchaTotNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_CBatRecoveryTot_BWLD_CBatRecoveryTot = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CBatRecoveryTot_BWLD_CBatRecoveryTot.value);
    Rte_swc_BatWntyLogtcData_BWLD_CBatRecoveryTotNv_BWLD_CBatRecoveryTotNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CBatRecoveryTotNv_BWLD_CBatRecoveryTotNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_CtrCh_BWLD_CtrCh = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CtrCh_BWLD_CtrCh.value);
    Rte_swc_BatWntyLogtcData_BWLD_CtrChNv_BWLD_CtrChNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CtrChNv_BWLD_CtrChNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_CtrDcha_BWLD_CtrDcha = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CtrDcha_BWLD_CtrDcha.value);
    Rte_swc_BatWntyLogtcData_BWLD_CtrDchaNv_BWLD_CtrDchaNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CtrDchaNv_BWLD_CtrDchaNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_CtrMdulWrNv_BWLD_CtrMdulWrNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CtrMdulWrNv_BWLD_CtrMdulWrNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax.value);
    Rte_swc_BatWntyLogtcData_BWLD_EBatChDrvCyc_BWLD_EBatChDrvCyc = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatChDrvCyc_BWLD_EBatChDrvCyc.value);
    Rte_swc_BatWntyLogtcData_BWLD_EBatChTot_BWLD_EBatChTot = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatChTot_BWLD_EBatChTot.value);
    Rte_swc_BatWntyLogtcData_BWLD_EBatChTotNv_BWLD_EBatChTotNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatChTotNv_BWLD_EBatChTotNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_EBatDchaDrvCyc_BWLD_EBatDchaDrvCyc = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatDchaDrvCyc_BWLD_EBatDchaDrvCyc.value);
    Rte_swc_BatWntyLogtcData_BWLD_EBatDchaTot_BWLD_EBatDchaTot = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatDchaTot_BWLD_EBatDchaTot.value);
    Rte_swc_BatWntyLogtcData_BWLD_EBatDchaTotNv_BWLD_EBatDchaTotNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatDchaTotNv_BWLD_EBatDchaTotNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_EBatRecoveryDrvCyc_BWLD_EBatRecoveryDrvCyc = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatRecoveryDrvCyc_BWLD_EBatRecoveryDrvCyc.value);
    Rte_swc_BatWntyLogtcData_BWLD_EBatRecoveryTot_BWLD_EBatRecoveryTot = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatRecoveryTot_BWLD_EBatRecoveryTot.value);
    Rte_swc_BatWntyLogtcData_BWLD_EBatRecoveryTotNv_BWLD_EBatRecoveryTotNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatRecoveryTotNv_BWLD_EBatRecoveryTotNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_IBatChMax_BWLD_IBatChMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_IBatChMax_BWLD_IBatChMax.value);
    Rte_swc_BatWntyLogtcData_BWLD_IBatChMaxNv_BWLD_IBatChMaxNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_IBatChMaxNv_BWLD_IBatChMaxNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_IBatDchaMax_BWLD_IBatDchaMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_IBatDchaMax_BWLD_IBatDchaMax.value);
    Rte_swc_BatWntyLogtcData_BWLD_IBatDchaMaxNv_BWLD_IBatDchaMaxNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_IBatDchaMaxNv_BWLD_IBatDchaMaxNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_PBatChMax_BWLD_PBatChMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_PBatChMax_BWLD_PBatChMax.value);
    Rte_swc_BatWntyLogtcData_BWLD_PBatChMaxNv_BWLD_PBatChMaxNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_PBatChMaxNv_BWLD_PBatChMaxNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_PBatDchaMax_BWLD_PBatDchaMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_PBatDchaMax_BWLD_PBatDchaMax.value);
    Rte_swc_BatWntyLogtcData_BWLD_PBatDchaMaxNv_BWLD_PBatDchaMaxNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_PBatDchaMaxNv_BWLD_PBatDchaMaxNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_SocBatMax_BWLD_SocBatMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_SocBatMax_BWLD_SocBatMax.value);
    Rte_swc_BatWntyLogtcData_BWLD_SocBatMaxNv_BWLD_SocBatMaxNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_SocBatMaxNv_BWLD_SocBatMaxNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_SocBatMin_BWLD_SocBatMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_SocBatMin_BWLD_SocBatMin.value);
    Rte_swc_BatWntyLogtcData_BWLD_SocBatMinNv_BWLD_SocBatMinNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_SocBatMinNv_BWLD_SocBatMinNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMax_BWLD_TMdulSnsrMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_TMdulSnsrMax_BWLD_TMdulSnsrMax.value);
    Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMaxNv_BWLD_TMdulSnsrMaxNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_TMdulSnsrMaxNv_BWLD_TMdulSnsrMaxNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMin_BWLD_TMdulSnsrMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_TMdulSnsrMin_BWLD_TMdulSnsrMin.value);
    Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMinNv_BWLD_TMdulSnsrMinNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_TMdulSnsrMinNv_BWLD_TMdulSnsrMinNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMax_BWLD_UBatCtctrClsdMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrClsdMax_BWLD_UBatCtctrClsdMax.value);
    Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMaxNv_BWLD_UBatCtctrClsdMaxNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrClsdMaxNv_BWLD_UBatCtctrClsdMaxNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMin_BWLD_UBatCtctrClsdMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrClsdMin_BWLD_UBatCtctrClsdMin.value);
    Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMinNv_BWLD_UBatCtctrClsdMinNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrClsdMinNv_BWLD_UBatCtctrClsdMinNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMax_BWLD_UBatCtctrOpenMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrOpenMax_BWLD_UBatCtctrOpenMax.value);
    Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMaxNv_BWLD_UBatCtctrOpenMaxNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrOpenMaxNv_BWLD_UBatCtctrOpenMaxNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMin_BWLD_UBatCtctrOpenMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrOpenMin_BWLD_UBatCtctrOpenMin.value);
    Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMinNv_BWLD_UBatCtctrOpenMinNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrOpenMinNv_BWLD_UBatCtctrOpenMinNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_UCellMax_BWLD_UCellMax = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UCellMax_BWLD_UCellMax.value);
    Rte_swc_BatWntyLogtcData_BWLD_UCellMaxNv_BWLD_UCellMaxNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UCellMaxNv_BWLD_UCellMaxNv.value);
    Rte_swc_BatWntyLogtcData_BWLD_UCellMin_BWLD_UCellMin = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UCellMin_BWLD_UCellMin.value);
    Rte_swc_BatWntyLogtcData_BWLD_UCellMinNv_BWLD_UCellMinNv = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UCellMinNv_BWLD_UCellMinNv.value);

    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv.value, Rte_swc_BatBalnCtl_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv, sizeof(rt_Array_UInt8_255));
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv.value, Rte_swc_BatCoreFct_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv, sizeof(rt_Array_Float_24));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_ChIIntglNv_BCF_ChIIntglNv.value) = Rte_swc_BatCoreFct_BCF_ChIIntglNv_BCF_ChIIntglNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_ChgDeltAhNv_BCF_ChgDeltAhNv.value) = Rte_swc_BatCoreFct_BCF_ChgDeltAhNv_BCF_ChgDeltAhNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_DeltAhNv_BCF_DeltAhNv.value) = Rte_swc_BatCoreFct_BCF_DeltAhNv_BCF_DeltAhNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_FullChgSOHNv_BCF_FullChgSOHNv.value) = Rte_swc_BatCoreFct_BCF_FullChgSOHNv_BCF_FullChgSOHNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_IIntglNv_BCF_IIntglNv.value) = Rte_swc_BatCoreFct_BCF_IIntglNv_BCF_IIntglNv;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv.value, Rte_swc_BatCoreFct_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv, sizeof(rt_Array_Float_24));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SOHCalFulChgFlgNv_BCF_SOHCalFulChgFlgNv.value) = Rte_swc_BatCoreFct_BCF_SOHCalFulChgFlgNv_BCF_SOHCalFulChgFlgNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SOHCalOCVFlgNv_BCF_SOHCalOCVFlgNv.value) = Rte_swc_BatCoreFct_BCF_SOHCalOCVFlgNv_BCF_SOHCalOCVFlgNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SocCnsActNv_BCF_SocCnsActNv.value) = Rte_swc_BatCoreFct_BCF_SocCnsActNv_BCF_SocCnsActNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SocPack_BCF_SocPack.value) = Rte_swc_BatCoreFct_BCF_SocPack_BCF_SocPack;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SocPackScld_BCF_SocPackScld.value) = Rte_swc_BatCoreFct_BCF_SocPackScld_BCF_SocPackScld;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SocUOcIniNv_BCF_SocUOcIniNv.value) = Rte_swc_BatCoreFct_BCF_SocUOcIniNv_BCF_SocUOcIniNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SohCalNv_BCF_SohCalNv.value) = Rte_swc_BatCoreFct_BCF_SohCalNv_BCF_SohCalNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SohCycNv_BCF_SohCycNv.value) = Rte_swc_BatCoreFct_BCF_SohCycNv_BCF_SohCycNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SohPackNv_BCF_SohPackNv.value) = Rte_swc_BatCoreFct_BCF_SohPackNv_BCF_SohPackNv;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv.value, Rte_swc_BatCoreFct_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv, sizeof(rt_Array_Float_24));
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv.value, Rte_swc_BatCoreFct_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv, sizeof(rt_Array_Float_24));
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_StAryFlsNv_BCF_StAryFlsNv.value, Rte_swc_BatCoreFct_BCF_StAryFlsNv_BCF_StAryFlsNv, sizeof(rt_Array_Float_144));
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv.value, Rte_swc_BatCoreFct_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv, sizeof(rt_Array_UInt32_24));
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv.value, Rte_swc_BatCoreFct_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv, sizeof(rt_Array_UInt32_24));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_TiBatOffNv_BCF_TiBatOffNv.value) = Rte_swc_BatCoreFct_BCF_TiBatOffNv_BCF_TiBatOffNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_TiChFullOff_BCF_TiChFullOff.value) = Rte_swc_BatCoreFct_BCF_TiChFullOff_BCF_TiChFullOff;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv.value, Rte_swc_BatCoreFct_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv, sizeof(rt_Array_UInt8_24));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BSTC_DayRtcLstNv_BSTC_DayRtcLstNv.value) = Rte_swc_BcuStTranCtl_BSTC_DayRtcLstNv_BSTC_DayRtcLstNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BSTC_HourRtcLstNv_BSTC_HourRtcLstNv.value) = Rte_swc_BcuStTranCtl_BSTC_HourRtcLstNv_BSTC_HourRtcLstNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BSTC_MinuRtcLstNv_BSTC_MinuRtcLstNv.value) = Rte_swc_BcuStTranCtl_BSTC_MinuRtcLstNv_BSTC_MinuRtcLstNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BSTC_MonthRtcLstNv_BSTC_MonthRtcLstNv.value) = Rte_swc_BcuStTranCtl_BSTC_MonthRtcLstNv_BSTC_MonthRtcLstNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BSTC_SecRtcLstNv_BSTC_SecRtcLstNv.value) = Rte_swc_BcuStTranCtl_BSTC_SecRtcLstNv_BSTC_SecRtcLstNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BSTC_YearRtcLstNv_BSTC_YearRtcLstNv.value) = Rte_swc_BcuStTranCtl_BSTC_YearRtcLstNv_BSTC_YearRtcLstNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BTHM_TPack_BTHM_TPack.value) = Rte_swc_BatThermHndlgMngt_BTHM_TPack_BTHM_TPack;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_CBatChTotNv_BWLD_CBatChTotNv.value) = Rte_swc_BatWntyLogtcData_BWLD_CBatChTotNv_BWLD_CBatChTotNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_CBatDchaTotNv_BWLD_CBatDchaTotNv.value) = Rte_swc_BatWntyLogtcData_BWLD_CBatDchaTotNv_BWLD_CBatDchaTotNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_CBatRecoveryTotNv_BWLD_CBatRecoveryTotNv.value) = Rte_swc_BatWntyLogtcData_BWLD_CBatRecoveryTotNv_BWLD_CBatRecoveryTotNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_CtrChNv_BWLD_CtrChNv.value) = Rte_swc_BatWntyLogtcData_BWLD_CtrChNv_BWLD_CtrChNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_CtrDchaNv_BWLD_CtrDchaNv.value) = Rte_swc_BatWntyLogtcData_BWLD_CtrDchaNv_BWLD_CtrDchaNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_EBatChTotNv_BWLD_EBatChTotNv.value) = Rte_swc_BatWntyLogtcData_BWLD_EBatChTotNv_BWLD_EBatChTotNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_EBatDchaTotNv_BWLD_EBatDchaTotNv.value) = Rte_swc_BatWntyLogtcData_BWLD_EBatDchaTotNv_BWLD_EBatDchaTotNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_EBatRecoveryTotNv_BWLD_EBatRecoveryTotNv.value) = Rte_swc_BatWntyLogtcData_BWLD_EBatRecoveryTotNv_BWLD_EBatRecoveryTotNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_IBatChMaxNv_BWLD_IBatChMaxNv.value) = Rte_swc_BatWntyLogtcData_BWLD_IBatChMaxNv_BWLD_IBatChMaxNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_IBatDchaMaxNv_BWLD_IBatDchaMaxNv.value) = Rte_swc_BatWntyLogtcData_BWLD_IBatDchaMaxNv_BWLD_IBatDchaMaxNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_PBatChMaxNv_BWLD_PBatChMaxNv.value) = Rte_swc_BatWntyLogtcData_BWLD_PBatChMaxNv_BWLD_PBatChMaxNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_PBatDchaMaxNv_BWLD_PBatDchaMaxNv.value) = Rte_swc_BatWntyLogtcData_BWLD_PBatDchaMaxNv_BWLD_PBatDchaMaxNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_SocBatMaxNv_BWLD_SocBatMaxNv.value) = Rte_swc_BatWntyLogtcData_BWLD_SocBatMaxNv_BWLD_SocBatMaxNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_SocBatMinNv_BWLD_SocBatMinNv.value) = Rte_swc_BatWntyLogtcData_BWLD_SocBatMinNv_BWLD_SocBatMinNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_TMdulSnsrMaxNv_BWLD_TMdulSnsrMaxNv.value) = Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMaxNv_BWLD_TMdulSnsrMaxNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_TMdulSnsrMinNv_BWLD_TMdulSnsrMinNv.value) = Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMinNv_BWLD_TMdulSnsrMinNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_TiBatAgiNv_BWLD_TiBatAgiNv.value) = Rte_swc_BatWntyLogtcData_BWLD_TiBatAgiNv_BWLD_TiBatAgiNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_UBatCtctrClsdMaxNv_BWLD_UBatCtctrClsdMaxNv.value) = Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMaxNv_BWLD_UBatCtctrClsdMaxNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_UBatCtctrClsdMinNv_BWLD_UBatCtctrClsdMinNv.value) = Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMinNv_BWLD_UBatCtctrClsdMinNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_UBatCtctrOpenMaxNv_BWLD_UBatCtctrOpenMaxNv.value) = Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMaxNv_BWLD_UBatCtctrOpenMaxNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_UBatCtctrOpenMinNv_BWLD_UBatCtctrOpenMinNv.value) = Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMinNv_BWLD_UBatCtctrOpenMinNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_UCellMaxNv_BWLD_UCellMaxNv.value) = Rte_swc_BatWntyLogtcData_BWLD_UCellMaxNv_BWLD_UCellMaxNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_UCellMinNv_BWLD_UCellMinNv.value) = Rte_swc_BatWntyLogtcData_BWLD_UCellMinNv_BWLD_UCellMinNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv.value) = Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv.value) = Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv.value) = Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv.value) = Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv.value) = Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_CTC_UPrechAccumdNv_CTC_UPrechAccumdNv.value) = Rte_swc_CtctrTranCtl_CTC_UPrechAccumdNv_CTC_UPrechAccumdNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_ELHPN_RIslnNegNv_ELHPN_RIslnNegNv.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnNegNv_ELHPN_RIslnNegNv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_ELHPN_RIslnPosNv_ELHPN_RIslnPosNv.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnPosNv_ELHPN_RIslnPosNv;
    NVM_Write_100ms();

    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BBC_bAcvBaln_BBC_bAcvBaln.value) = Rte_swc_BatBalnCtl_BBC_bAcvBaln_BBC_bAcvBaln;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_AcvCellURchd_BCC_AcvCellURchd.value) = Rte_swc_BatChCtl_BCC_AcvCellURchd_BCC_AcvCellURchd;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_AcvSocRchd_BCC_AcvSocRchd.value) = Rte_swc_BatChCtl_BCC_AcvSocRchd_BCC_AcvSocRchd;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_AcvUTotRchd_BCC_AcvUTotRchd.value) = Rte_swc_BatChCtl_BCC_AcvUTotRchd_BCC_AcvUTotRchd;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_ElectroniclockContorREQ_BCC_ElectroniclockContorREQ.value) = Rte_swc_BatChCtl_BCC_ElectroniclockContorREQ_BCC_ElectroniclockContorREQ;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_ElectroniclockSt_BCC_ElectroniclockSt.value) = Rte_swc_BatChCtl_BCC_ElectroniclockSt_BCC_ElectroniclockSt;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_ErrInfo_BCC_ErrInfo.value) = Rte_swc_BatChCtl_BCC_ErrInfo_BCC_ErrInfo;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_IDchaReq_BCC_IDchaReq.value) = Rte_swc_BatChCtl_BCC_IDchaReq_BCC_IDchaReq;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_IObcLimn_BCC_IObcLimn.value) = Rte_swc_BatChCtl_BCC_IObcLimn_BCC_IObcLimn;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_ModeCh_BCC_ModeCh.value) = Rte_swc_BatChCtl_BCC_ModeCh_BCC_ModeCh;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_StAcChReq_BCC_StAcChReq.value) = Rte_swc_BatChCtl_BCC_StAcChReq_BCC_StAcChReq;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_StCh_BCC_StCh.value) = Rte_swc_BatChCtl_BCC_StCh_BCC_StCh;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_TimeOutCRO00_BCC_TimeOutCRO00.value) = Rte_swc_BatChCtl_TimeOut_CRO00_BCC_TimeOutCRO00;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_TimeOutCROAA_BCC_TimeOutCROAA.value) = Rte_swc_BatChCtl_TimeOut_CROAA_BCC_TimeOutCROAA;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_UChReq_BCC_UChReq.value) = Rte_swc_BatChCtl_BCC_UChReq_BCC_UChReq;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_UObcLimn_BCC_UObcLimn.value) = Rte_swc_BatChCtl_BCC_UObcLimn_BCC_UObcLimn;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_bS2Ctrl_BCC_bS2Ctrl.value) = Rte_swc_BatChCtl_BCC_bS2Ctrl_BCC_bS2Ctrl;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCF_EPackRmng_BCF_EPackRmng.value) = Rte_swc_BatCoreFct_BCF_EPackRmng_BCF_EPackRmng;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCF_ErrInfo_BCF_ErrInfo.value) = Rte_swc_BatCoreFct_BCF_ErrInfo_BCF_ErrInfo;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCF_IChPredLim_BCF_IChPredLim.value) = Rte_swc_BatCoreFct_BCF_IChPredLim_BCF_IChPredLim;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCF_IDchaPredLim_BCF_IDchaPredLim.value) = Rte_swc_BatCoreFct_BCF_IDchaPredLim_BCF_IDchaPredLim;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCF_SocPack_BCF_SocPack.value) = Rte_swc_BatCoreFct_BCF_SocPack_BCF_SocPack;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCF_SocPackScld_BCF_SocPackScld.value) = Rte_swc_BatCoreFct_BCF_SocPackScld_BCF_SocPackScld;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCF_SohPack_BCF_SohPack.value) = Rte_swc_BatCoreFct_BCF_SohPack_BCF_SohPack;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value) = Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg.value) = Rte_swc_BatCoreFct_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot.value) = Rte_swc_BatChCtl_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCTE_TiBatDchaByMinuTot_BCTE_TiBatDchaByMinuTot.value) = Rte_swc_BatChCtl_BCTE_TiBatDchaByMinuTot_BCTE_TiBatDchaByMinuTot;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMC_UCell_BMC_UCell.value, Rte_swc_CIL_BMC_UCell_BMC_UCell, sizeof(rt_Array_Float_255));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_ErrCellU_BPIU_ErrCellU.value) = Rte_swc_BatProtnIU_BPIU_ErrCellU_BPIU_ErrCellU;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_ErrCellUDif_BPIU_ErrCellUDif.value) = Rte_swc_BatProtnIU_BPIU_ErrCellUDif_BPIU_ErrCellUDif;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_ErrCellUOver_BPIU_ErrCellUOver.value) = Rte_swc_BatProtnIU_BPIU_ErrCellUOver_BPIU_ErrCellUOver;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_ErrIChLim_BPIU_ErrIChLim.value) = Rte_swc_BatProtnIU_BPIU_ErrIChLim_BPIU_ErrIChLim;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_ErrIRgnOvcur_BPIU_ErrIRgnOvcur.value) = Rte_swc_BatProtnIU_BPIU_ErrIRgnOvcur_BPIU_ErrIRgnOvcur;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_ErrInfo_BPIU_ErrInfo.value) = Rte_swc_BatProtnIU_BPIU_ErrInfo_BPIU_ErrInfo;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_ErrPackSnsrI_BPIU_ErrPackSnsrI.value) = Rte_swc_BatProtnIU_BPIU_ErrPackSnsrI_BPIU_ErrPackSnsrI;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_ErrUAcqn_BPIU_ErrUAcqn.value) = Rte_swc_BatProtnIU_BPIU_ErrUAcqn_BPIU_ErrUAcqn;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_IdCellUMax_BPIU_IdCellUMax.value) = Rte_swc_BatProtnIU_BPIU_IdCellUMax_BPIU_IdCellUMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_UCellMax_BPIU_UCellMax.value) = Rte_swc_BatProtnIU_BPIU_UCellMax_BPIU_UCellMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_UCellMin_BPIU_UCellMin.value) = Rte_swc_BatProtnIU_BPIU_UCellMin_BPIU_UCellMin;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPP_ErrCellT_BPP_ErrCellT.value) = Rte_swc_BatProtnPack_BPP_ErrCellT_BPP_ErrCellT;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPP_ErrInfo_BPP_ErrInfo.value) = Rte_swc_BatProtnPack_BPP_ErrInfo_BPP_ErrInfo;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPP_ErrPackU_BPP_ErrPackU.value) = Rte_swc_BatProtnPack_BPP_ErrPackU_BPP_ErrPackU;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPP_ErrSocVal_BPP_ErrSocVal.value) = Rte_swc_BatProtnPack_BPP_ErrSocVal_BPP_ErrSocVal;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_AcvChManSuspd_BSOF_AcvChManSuspd.value) = Rte_swc_CIL_BSOF_AcvChManSuspd_BSOF_AcvChManSuspd;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_AcvChSuspdByBms_BSOF_AcvChSuspdByBms.value) = Rte_swc_CIL_BSOF_AcvChSuspdByBms_BSOF_AcvChSuspdByBms;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_AcvChSuspdCdnRchd_BSOF_AcvChSuspdCdnRchd.value) = Rte_swc_CIL_BSOF_AcvChSuspdCdnRchd_BSOF_AcvChSuspdCdnRchd;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_AcvChSuspdFlt_BSOF_AcvChSuspdFlt.value) = Rte_swc_CIL_BSOF_AcvChSuspdFlt_BSOF_AcvChSuspdFlt;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_ErrChImpo_BSOF_ErrChImpo.value) = Rte_swc_CIL_BSOF_ErrChImpo_BSOF_ErrChImpo;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt.value) = Rte_swc_CIL_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt.value) = Rte_swc_CIL_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt.value) = Rte_swc_CIL_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy.value) = Rte_swc_CIL_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_ErrIDe_BSOF_ErrIDe.value) = Rte_swc_CIL_BSOF_ErrIDe_BSOF_ErrIDe;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_ErrUAbno_BSOF_ErrUAbno.value) = Rte_swc_CIL_BSOF_ErrUAbno_BSOF_ErrUAbno;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_ErrUndfnd_BSOF_ErrUndfnd.value) = Rte_swc_CIL_BSOF_ErrUndfnd_BSOF_ErrUndfnd;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg.value) = Rte_swc_CIL_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSTC_ModeBmsAcvn_BSTC_ModeBmsAcvn.value) = Rte_swc_BcuStTranCtl_BSTC_ModeBmsAcvn_BSTC_ModeBmsAcvn;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSTC_ReqEmcyHvOffFromBms_BSTC_ReqEmcyHvOffFromBms.value) = Rte_swc_BcuStTranCtl_BSTC_ReqEmcyHvOffFromBms_BSTC_ReqEmcyHvOffFromBms;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSTC_StBcu_BSTC_StBcu.value) = Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSTC_StBcuInt_BSTC_StBcuInt.value) = Rte_swc_BcuStTranCtl_BSTC_StBcuInt_BSTC_StBcuInt;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSTC_StBmsChk_BSTC_StBmsChk.value) = Rte_swc_BcuStTranCtl_BSTC_StBmsChk_BSTC_StBmsChk;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSTC_bAcvCutoffLvFromBms_BSTC_bAcvCutoffLvFromBms.value) = Rte_swc_BcuStTranCtl_BSTC_bAcvCutoffLvFromBms_BSTC_bAcvCutoffLvFromBms;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSTC_bAcvObcOff_BSTC_bAcvObcOff.value) = Rte_swc_BcuStTranCtl_BSTC_bAcvObcOff_BSTC_bAcvObcOff;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_ErrInfo_BTHM_ErrInfo.value) = Rte_swc_BatThermHndlgMngt_BTHM_ErrInfo_BTHM_ErrInfo;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_IdCellTMax_BTHM_IdCellTMax.value) = Rte_swc_BatThermHndlgMngt_BTHM_IdCellTMax_BTHM_IdCellTMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_IdCellTMin_BTHM_IdCellTMin.value) = Rte_swc_BatThermHndlgMngt_BTHM_IdCellTMin_BTHM_IdCellTMin;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_StSys_BTHM_StSys.value) = Rte_swc_BatThermHndlgMngt_BTHM_StSys_BTHM_StSys;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_StThermReq_BTHM_StThermReq.value) = Rte_swc_BatThermHndlgMngt_BTHM_StThermReq_BTHM_StThermReq;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_TBatTgt_BTHM_TBatTgt.value) = Rte_swc_BatThermHndlgMngt_BTHM_TBatTgt_BTHM_TBatTgt;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr.value) = Rte_swc_BatThermHndlgMngt_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr.value) = Rte_swc_BatThermHndlgMngt_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_TOptmMax_BTHM_TOptmMax.value) = Rte_swc_BatThermHndlgMngt_BTHM_TOptmMax_BTHM_TOptmMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_bAcvDig93_BTHM_bAcvDig93.value) = Rte_swc_BatThermHndlgMngt_BTHM_bAcvDig93_BTHM_bAcvDig93;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BWLD_CtrDcha_BWLD_CtrDcha.value) = Rte_swc_BatWntyLogtcData_BWLD_CtrDcha_BWLD_CtrDcha;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax.value) = Rte_swc_BatWntyLogtcData_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_CP_Vol_CIL_CP_Vol.value) = Rte_swc_CIL_CIL_CP_Vol_CIL_CP_Vol;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_DucycCtlPilot_CIL_DucycCtlPilot.value) = Rte_swc_CIL_CIL_DucycCtlPilot_CIL_DucycCtlPilot;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_ErrInfoBSW_CIL_ErrInfoBSW.value) = Rte_swc_CIL_CIL_ErrInfoBSW_CIL_ErrInfoBSW;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_IBatHv_CIL_IBatHv.value) = Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline.value) = Rte_swc_CIL_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_RAcChCnctnResRaw_CIL_RAcChCnctnResRaw.value) = Rte_swc_CIL_CIL_RAcChCnctnResRaw_CIL_RAcChCnctnResRaw;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_RngElec_CIL_RngElec.value) = Rte_swc_CIL_CIL_RngElec_CIL_RngElec;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_StChWup_CIL_StChWup.value) = Rte_swc_CIL_CIL_StChWup_CIL_StChWup;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_TMdul_CIL_TMdul.value, Rte_swc_CIL_CIL_TMdul_CIL_TMdul, sizeof(rt_Array_Float_54));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value) = Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_ErrInfo_CTC_ErrInfo.value) = Rte_swc_CtctrTranCtl_CTC_ErrInfo_CTC_ErrInfo;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_ErrRlyCh_CTC_ErrRlyCh.value) = Rte_swc_CtctrTranCtl_CTC_ErrRlyCh_CTC_ErrRlyCh;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_ErrRlyHeat_CTC_ErrRlyHeat.value) = Rte_swc_CtctrTranCtl_CTC_ErrRlyHeat_CTC_ErrRlyHeat;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_ErrRlyNeg_CTC_ErrRlyNeg.value) = Rte_swc_CtctrTranCtl_CTC_ErrRlyNeg_CTC_ErrRlyNeg;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_ErrRlyPos_CTC_ErrRlyPos.value) = Rte_swc_CtctrTranCtl_CTC_ErrRlyPos_CTC_ErrRlyPos;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_ErrRlyPrech_CTC_ErrRlyPrech.value) = Rte_swc_CtctrTranCtl_CTC_ErrRlyPrech_CTC_ErrRlyPrech;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_ReqRlyCh_CTC_ReqRlyCh.value) = Rte_swc_CtctrTranCtl_CTC_ReqRlyCh_CTC_ReqRlyCh;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_ReqZeroPwr_CTC_ReqZeroPwr.value) = Rte_swc_CtctrTranCtl_CTC_ReqZeroPwr_CTC_ReqZeroPwr;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_StHvbat_CTC_StHvbat.value) = Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_StLoopHv_CTC_StLoopHv.value) = Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_StRlyCh_CTC_StRlyCh.value) = Rte_swc_CtctrTranCtl_CTC_StRlyCh_CTC_StRlyCh;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_StRlyHeat_CTC_StRlyHeat.value) = Rte_swc_CtctrTranCtl_CTC_StRlyHeat_CTC_StRlyHeat;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_StRlyNeg_CTC_StRlyNeg.value) = Rte_swc_CtctrTranCtl_CTC_StRlyNeg_CTC_StRlyNeg;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_StRlyPos_CTC_StRlyPos.value) = Rte_swc_CtctrTranCtl_CTC_StRlyPos_CTC_StRlyPos;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_StRlyPrech_CTC_StRlyPrech.value) = Rte_swc_CtctrTranCtl_CTC_StRlyPrech_CTC_StRlyPrech;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_ClL_InletWaterTemp_ClL_InletWaterTemp.value) = Rte_swc_CIL_ClL_InletWaterTemp_ClL_InletWaterTemp;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_ClL_OutletWaterTemp_ClL_OutletWaterTemp.value) = Rte_swc_CIL_ClL_OutletWaterTemp_ClL_OutletWaterTemp;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_CBatNom_DEH_CBatNom.value) = Rte_swc_DiagcEveHndlg_DEH_CBatNom_DEH_CBatNom;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_ChgLvlErr_DEH_ChgLvlErr.value) = Rte_swc_DiagcEveHndlg_DEH_ChgLvlErr_DEH_ChgLvlErr;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_DelayDataUpldEnb_DEH_DelayDataUpldEnb.value) = Rte_swc_DiagcEveHndlg_DEH_DelayDataUpldEnb_DEH_DelayDataUpldEnb;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_DischgLvlErr_DEH_DischgLvlErr.value) = Rte_swc_DiagcEveHndlg_DEH_DischgLvlErr_DEH_DischgLvlErr;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_ErrCfmd2_DEH_ErrCfmd2.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd2_DEH_ErrCfmd2;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value) = Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_LvlErrSb_DEH_LvlErrSb.value) = Rte_swc_DiagcEveHndlg_DEH_LvlErrSb_DEH_LvlErrSb;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin1_DEH_NrVin1.value) = Rte_swc_DiagcEveHndlg_DEH_NrVin1_DEH_NrVin1;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin10_DEH_NrVin10.value) = Rte_swc_DiagcEveHndlg_DEH_NrVin10_DEH_NrVin10;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin11_DEH_NrVin11.value) = Rte_swc_DiagcEveHndlg_DEH_NrVin11_DEH_NrVin11;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin12_DEH_NrVin12.value) = Rte_swc_DiagcEveHndlg_DEH_NrVin12_DEH_NrVin12;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin13_DEH_NrVin13.value) = Rte_swc_DiagcEveHndlg_DEH_NrVin13_DEH_NrVin13;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin14_DEH_NrVin14.value) = Rte_swc_DiagcEveHndlg_DEH_NrVin14_DEH_NrVin14;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin15_DEH_NrVin15.value) = Rte_swc_DiagcEveHndlg_DEH_NrVin15_DEH_NrVin15;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin16_DEH_NrVin16.value) = Rte_swc_DiagcEveHndlg_DEH_NrVin16_DEH_NrVin16;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin17_DEH_NrVin17.value) = Rte_swc_DiagcEveHndlg_DEH_NrVin17_DEH_NrVin17;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin2_DEH_NrVin2.value) = Rte_swc_DiagcEveHndlg_DEH_NrVin2_DEH_NrVin2;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin3_DEH_NrVin3.value) = Rte_swc_DiagcEveHndlg_DEH_NrVin3_DEH_NrVin3;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin4_DEH_NrVin4.value) = Rte_swc_DiagcEveHndlg_DEH_NrVin4_DEH_NrVin4;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin5_DEH_NrVin5.value) = Rte_swc_DiagcEveHndlg_DEH_NrVin5_DEH_NrVin5;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin6_DEH_NrVin6.value) = Rte_swc_DiagcEveHndlg_DEH_NrVin6_DEH_NrVin6;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin7_DEH_NrVin7.value) = Rte_swc_DiagcEveHndlg_DEH_NrVin7_DEH_NrVin7;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin8_DEH_NrVin8.value) = Rte_swc_DiagcEveHndlg_DEH_NrVin8_DEH_NrVin8;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin9_DEH_NrVin9.value) = Rte_swc_DiagcEveHndlg_DEH_NrVin9_DEH_NrVin9;
    Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_PackCode_DEH_PackCode.value, Rte_swc_DiagcEveHndlg_DEH_PackCode_DEH_PackCode, sizeof(rt_Array_UInt8_24));
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_StFltLampIndcn_DEH_StFltLampIndcn.value) = Rte_swc_DiagcEveHndlg_DEH_StFltLampIndcn_DEH_StFltLampIndcn;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_UBatNom_DEH_UBatNom.value) = Rte_swc_DiagcEveHndlg_DEH_UBatNom_DEH_UBatNom;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_ValCodDiag_DEH_ValCodDiag.value) = Rte_swc_DiagcEveHndlg_DEH_ValCodDiag_DEH_ValCodDiag;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_ELHPN_ErrInfo_ELHPN_ErrInfo.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_ErrInfo_ELHPN_ErrInfo;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_ELHPN_RIslnNeg_ELHPN_RIslnNeg.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnNeg_ELHPN_RIslnNeg;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_ELHPN_RIslnPos_ELHPN_RIslnPos.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnPos_ELHPN_RIslnPos;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_ELHPN_StIsln_ELHPN_StIsln.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StIsln_ELHPN_StIsln;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_ELHPN_StIslnErr_ELHPN_StIslnErr.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StIslnErr_ELHPN_StIslnErr;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_ELHPN_StVehIsln_ELHPN_StVehIsln.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StVehIsln_ELHPN_StVehIsln;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr.value) = Rte_swc_BatChCtl_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_ErrMsgChrgrChRdy_EVCSH_ErrMsgChrgrChRdy.value) = Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChRdy_EVCSH_ErrMsgChrgrChRdy;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_ErrMsgChrgrChSts_EVCSH_ErrMsgChrgrChSts.value) = Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChSts_EVCSH_ErrMsgChrgrChSts;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_ErrMsgChrgrChStstc_EVCSH_ErrMsgChrgrChStstc.value) = Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChStstc_EVCSH_ErrMsgChrgrChStstc;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_ErrMsgChrgrChSuspd_EVCSH_ErrMsgChrgrChSuspd.value) = Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChSuspd_EVCSH_ErrMsgChrgrChSuspd;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_ErrMsgChrgrIdfcNotRdy_EVCSH_ErrMsgChrgrIdfcNotRdy.value) = Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrIdfcNotRdy_EVCSH_ErrMsgChrgrIdfcNotRdy;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_ErrMsgChrgrIdfcRdy_EVCSH_ErrMsgChrgrIdfcRdy.value) = Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrIdfcRdy_EVCSH_ErrMsgChrgrIdfcRdy;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_ErrMsgChrgrSync_EVCSH_ErrMsgChrgrSync.value) = Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrSync_EVCSH_ErrMsgChrgrSync;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_StBatRdy_EVCSH_StBatRdy.value) = Rte_swc_BatChCtl_EVCSH_StBatRdy_EVCSH_StBatRdy;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_StDcCh_EVCSH_StDcCh.value) = Rte_swc_BatChCtl_EVCSH_StDcCh_EVCSH_StDcCh;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_StInt_EVCSH_StInt.value) = Rte_swc_BatChCtl_EVCSH_StInt_EVCSH_StInt;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaChrgn_EVCSH_bEnaChrgn.value) = Rte_swc_BatChCtl_EVCSH_bEnaChrgn_EVCSH_bEnaChrgn;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg.value) = Rte_swc_BatChCtl_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatCfgPgtn_EVCSH_bEnaMsgBatCfgPgtn.value) = Rte_swc_BatChCtl_EVCSH_bEnaMsgBatCfgPgtn_EVCSH_bEnaMsgBatCfgPgtn;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt.value) = Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatChStPgtn_EVCSH_bEnaMsgBatChStPgtn.value) = Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChStPgtn_EVCSH_bEnaMsgBatChStPgtn;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg.value) = Rte_swc_BatChCtl_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr.value) = Rte_swc_BatChCtl_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk.value) = Rte_swc_BatChCtl_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn.value) = Rte_swc_BatChCtl_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy.value) = Rte_swc_BatChCtl_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt.value) = Rte_swc_BatChCtl_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc.value) = Rte_swc_BatChCtl_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MCC_NrCellTot_MCC_NrCellTot.value) = Rte_swc_CIL_MCC_NrCellTot_MCC_NrCellTot;
    *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MCC_NrSnsrTTot_MCC_NrSnsrTTot.value) = Rte_swc_CIL_MCC_NrSnsrTTot_MCC_NrSnsrTTot;
    COL_100ms();
    Rte_swc_COL_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur.value);
    Rte_swc_COL_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV.value);
    Rte_swc_COL_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV.value);
    Rte_swc_COL_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc.value);
    Rte_swc_COL_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time.value);
    Rte_swc_COL_BCSP_Remaining_range_BCSP_Remaining_range = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCSP_Remaining_range_BCSP_Remaining_range.value);
    Rte_swc_COL_BCSP_reserved_BCSP_reserved = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCSP_reserved_BCSP_reserved.value);
    Rte_swc_COL_BDC_Battery_capacity_BDC_Battery_capacity = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Battery_capacity_BDC_Battery_capacity.value);
    Rte_swc_COL_BDC_Battery_energy_BDC_Battery_energy = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Battery_energy_BDC_Battery_energy.value);
    Rte_swc_COL_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate.value);
    Rte_swc_COL_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange.value);
    Rte_swc_COL_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate.value);
    Rte_swc_COL_BDC_Soc_BDC_Soc = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Soc_BDC_Soc.value);
    Rte_swc_COL_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1.value);
    Rte_swc_COL_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10.value);
    Rte_swc_COL_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11.value);
    Rte_swc_COL_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12.value);
    Rte_swc_COL_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13.value);
    Rte_swc_COL_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14.value);
    Rte_swc_COL_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15.value);
    Rte_swc_COL_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16.value);
    Rte_swc_COL_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17.value);
    Rte_swc_COL_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2.value);
    Rte_swc_COL_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3.value);
    Rte_swc_COL_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4.value);
    Rte_swc_COL_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5.value);
    Rte_swc_COL_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6.value);
    Rte_swc_COL_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7.value);
    Rte_swc_COL_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8.value);
    Rte_swc_COL_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9.value);
    Rte_swc_COL_BMSH_DCChgRx_OTime_CRO00_BMSH_DCChgRx_OTime_CRO00 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CRO00_BMSH_DCChgRx_OTime_CRO00.value);
    Rte_swc_COL_BMSH_DCChgRx_OTime_CROAA_BMSH_DCChgRx_OTime_CROAA = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CROAA_BMSH_DCChgRx_OTime_CROAA.value);
    Rte_swc_COL_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason.value);
    Rte_swc_COL_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason.value);
    Rte_swc_COL_BMS_BMSStopChgReason_BMS_BMSStopChgReason = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BMSStopChgReason_BMS_BMSStopChgReason.value);
    Rte_swc_COL_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason.value);
    Rte_swc_COL_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason.value);
    Rte_swc_COL_BMS_CCUStopChgReason_BMS_CCUStopChgReason = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CCUStopChgReason_BMS_CCUStopChgReason.value);
    Rte_swc_COL_BSWIOSP_Request_BCP_Request_BCP = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BCP_Request_BCP.value);
    Rte_swc_COL_BSWIOSP_Request_BCPP_Request_BCPP = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BCPP_Request_BCPP.value);
    Rte_swc_COL_BSWIOSP_Request_BCS_Request_BCS = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BCS_Request_BCS.value);
    Rte_swc_COL_BSWIOSP_Request_BCSP_Request_BCSP = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BCSP_Request_BCSP.value);
    Rte_swc_COL_BSWIOSP_Request_BDC_Request_BDC = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BDC_Request_BDC.value);
    Rte_swc_COL_BSWIOSP_Request_BEM_Request_BEM = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BEM_Request_BEM.value);
    Rte_swc_COL_BSWIOSP_Request_BHM_Request_BHM = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BHM_Request_BHM.value);
    Rte_swc_COL_BSWIOSP_Request_BMS_FastChgStopInfo_Request_BMS_FastChgStopInfo = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BMS_FastChgStopInfo_Request_BMS_FastChgStopInfo.value);
    Rte_swc_COL_BSWIOSP_Request_BRM_Request_BRM = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BRM_Request_BRM.value);
    Rte_swc_COL_BSWIOSP_Request_BRO_Request_BRO = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BRO_Request_BRO.value);
    Rte_swc_COL_BSWIOSP_Request_BSD_Request_BSD = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BSD_Request_BSD.value);
    Rte_swc_COL_BSWIOSP_Request_BSM_Request_BSM = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BSM_Request_BSM.value);
    Rte_swc_COL_BatteryChargingOvercurrent_BatteryChargingOvercurrent = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryChargingOvercurrent_BatteryChargingOvercurrent.value);
    Rte_swc_COL_BatteryExcessTemperature_BatteryExcessTemperature = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryExcessTemperature_BatteryExcessTemperature.value);
    Rte_swc_COL_BatteryHighestTemp_BatteryHighestTemp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryHighestTemp_BatteryHighestTemp.value);
    Rte_swc_COL_BatteryHighestTempSerNo_BatteryHighestTempSerNo = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryHighestTempSerNo_BatteryHighestTempSerNo.value);
    Rte_swc_COL_BatteryInsulationState_BatteryInsulationState = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryInsulationState_BatteryInsulationState.value);
    Rte_swc_COL_BatteryLowestTemp_BatteryLowestTemp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryLowestTemp_BatteryLowestTemp.value);
    Rte_swc_COL_BatteryLowestTempSerNo_BatteryLowestTempSerNo = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryLowestTempSerNo_BatteryLowestTempSerNo.value);
    Rte_swc_COL_BatteryOutputConnectorState_BatteryOutputConnectorState = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryOutputConnectorState_BatteryOutputConnectorState.value);
    Rte_swc_COL_BatterySystemCapacity_BatterySystemCapacity = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatterySystemCapacity_BatterySystemCapacity.value);
    Rte_swc_COL_BatterySystemVoltage_BatterySystemVoltage = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatterySystemVoltage_BatterySystemVoltage.value);
    Rte_swc_COL_BatteryType_BatteryType = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryType_BatteryType.value);
    Rte_swc_COL_BmsReadyForCharging_BmsReadyForCharging = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BmsReadyForCharging_BmsReadyForCharging.value);
    Rte_swc_COL_BmsRevision_BmsRevision = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BmsRevision_BmsRevision.value);
    Rte_swc_COL_BmsVersion_BmsVersion = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BmsVersion_BmsVersion.value);
    Rte_swc_COL_BsmChargingPermissible_BsmChargingPermissible = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BsmChargingPermissible_BsmChargingPermissible.value);
    Rte_swc_COL_CurrentChargeState_CurrentChargeState = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CurrentChargeState_CurrentChargeState.value);
    Rte_swc_COL_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage.value);
    Rte_swc_COL_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime.value);
    Rte_swc_COL_MaxChargingVoltage_MaxChargingVoltage = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MaxChargingVoltage_MaxChargingVoltage.value);
    Rte_swc_COL_MaxPermChargingCurrent_MaxPermChargingCurrent = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MaxPermChargingCurrent_MaxPermChargingCurrent.value);
    Rte_swc_COL_MaxPermTemperature_MaxPermTemperature = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MaxPermTemperature_MaxPermTemperature.value);
    Rte_swc_COL_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage.value);
    Rte_swc_COL_MeasuredChargingCurrent_MeasuredChargingCurrent = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MeasuredChargingCurrent_MeasuredChargingCurrent.value);
    Rte_swc_COL_MeasuredChargingVoltage_MeasuredChargingVoltage = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MeasuredChargingVoltage_MeasuredChargingVoltage.value);
    Rte_swc_COL_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage.value);
    Rte_swc_COL_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup.value);
    Rte_swc_COL_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo.value);
    Rte_swc_COL_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature.value);
    Rte_swc_COL_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage.value);
    Rte_swc_COL_SingleBatteryMinTemperature_SingleBatteryMinTemperature = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryMinTemperature_SingleBatteryMinTemperature.value);
    Rte_swc_COL_SingleBatteryMinVoltage_SingleBatteryMinVoltage = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryMinVoltage_SingleBatteryMinVoltage.value);
    Rte_swc_COL_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage.value);
    Rte_swc_COL_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery.value);
    Rte_swc_COL_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC.value);
    Rte_swc_COL_Timeout_CCS_Timeout_CCS = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CCS_Timeout_CCS.value);
    Rte_swc_COL_Timeout_CRM_Recognized_Timeout_CRM_Recognized = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CRM_Recognized_Timeout_CRM_Recognized.value);
    Rte_swc_COL_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized.value);
    Rte_swc_COL_Timeout_CRO_Timeout_CRO = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CRO_Timeout_CRO.value);
    Rte_swc_COL_Timeout_CSD_Timeout_CSD = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CSD_Timeout_CSD.value);
    Rte_swc_COL_Timeout_CST_Timeout_CST = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CST_Timeout_CST.value);
    Rte_swc_COL_Timeout_CTS_CML_Timeout_CTS_CML = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CTS_CML_Timeout_CTS_CML.value);
    Rte_swc_COL_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage.value);
    Rte_swc_COL_TotalNominalEnergy_TotalNominalEnergy = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_TotalNominalEnergy_TotalNominalEnergy.value);
    Rte_swc_COL_VIN_Copy_1_VIN_Copy_1 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_1_VIN_Copy_1.value);
    Rte_swc_COL_VIN_Copy_10_VIN_Copy_10 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_10_VIN_Copy_10.value);
    Rte_swc_COL_VIN_Copy_11_VIN_Copy_11 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_11_VIN_Copy_11.value);
    Rte_swc_COL_VIN_Copy_12_VIN_Copy_12 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_12_VIN_Copy_12.value);
    Rte_swc_COL_VIN_Copy_13_VIN_Copy_13 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_13_VIN_Copy_13.value);
    Rte_swc_COL_VIN_Copy_14_VIN_Copy_14 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_14_VIN_Copy_14.value);
    Rte_swc_COL_VIN_Copy_15_VIN_Copy_15 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_15_VIN_Copy_15.value);
    Rte_swc_COL_VIN_Copy_16_VIN_Copy_16 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_16_VIN_Copy_16.value);
    Rte_swc_COL_VIN_Copy_17_VIN_Copy_17 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_17_VIN_Copy_17.value);
    Rte_swc_COL_VIN_Copy_2_VIN_Copy_2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_2_VIN_Copy_2.value);
    Rte_swc_COL_VIN_Copy_3_VIN_Copy_3 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_3_VIN_Copy_3.value);
    Rte_swc_COL_VIN_Copy_4_VIN_Copy_4 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_4_VIN_Copy_4.value);
    Rte_swc_COL_VIN_Copy_5_VIN_Copy_5 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_5_VIN_Copy_5.value);
    Rte_swc_COL_VIN_Copy_6_VIN_Copy_6 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_6_VIN_Copy_6.value);
    Rte_swc_COL_VIN_Copy_7_VIN_Copy_7 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_7_VIN_Copy_7.value);
    Rte_swc_COL_VIN_Copy_8_VIN_Copy_8 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_8_VIN_Copy_8.value);
    Rte_swc_COL_VIN_Copy_9_VIN_Copy_9 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_9_VIN_Copy_9.value);
    Rte_swc_COL_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState.value);


    Rte_swc_COL_BMSH_12VBatFault_BMSH_12VBatFault = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_12VBatFault_BMSH_12VBatFault.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_12VBatFault_BMSH_12VBatFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BatCurrent_BMSH_BatCurrent = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatCurrent_BMSH_BatCurrent.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatCurrent_BMSH_BatCurrent = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BatOverSOC_BMSH_BatOverSOC = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatOverSOC_BMSH_BatOverSOC.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatOverSOC_BMSH_BatOverSOC = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BatOverVolt_BMSH_BatOverVolt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatOverVolt_BMSH_BatOverVolt.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatOverVolt_BMSH_BatOverVolt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BatRealSOC_BMSH_BatRealSOC = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatRealSOC_BMSH_BatRealSOC.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatRealSOC_BMSH_BatRealSOC = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BatSOE_BMSH_BatSOE = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatSOE_BMSH_BatSOE.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatSOE_BMSH_BatSOE = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BatSOH_BMSH_BatSOH = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatSOH_BMSH_BatSOH.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatSOH_BMSH_BatSOH = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BatUnderSOC_BMSH_BatUnderSOC = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatUnderSOC_BMSH_BatUnderSOC.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatUnderSOC_BMSH_BatUnderSOC = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BatUnderVolt_BMSH_BatUnderVolt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatUnderVolt_BMSH_BatUnderVolt.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatUnderVolt_BMSH_BatUnderVolt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BatUseableSOC_BMSH_BatUseableSOC = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatUseableSOC_BMSH_BatUseableSOC.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatUseableSOC_BMSH_BatUseableSOC = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_CellOverVolt_BMSH_CellOverVolt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CellOverVolt_BMSH_CellOverVolt.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellOverVolt_BMSH_CellOverVolt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_CellTempUniformity_BMSH_CellTempUniformity = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CellTempUniformity_BMSH_CellTempUniformity.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellTempUniformity_BMSH_CellTempUniformity = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_CellUnderVolt_BMSH_CellUnderVolt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CellUnderVolt_BMSH_CellUnderVolt.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellUnderVolt_BMSH_CellUnderVolt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_ChgOverTemp_BMSH_ChgOverTemp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_ChgOverTemp_BMSH_ChgOverTemp.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ChgOverTemp_BMSH_ChgOverTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_ChgUnderTemp_BMSH_ChgUnderTemp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_ChgUnderTemp_BMSH_ChgUnderTemp.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ChgUnderTemp_BMSH_ChgUnderTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_ConnectNegOverTemp_BMSH_ConnectNegOverTemp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_ConnectNegOverTemp_BMSH_ConnectNegOverTemp.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ConnectNegOverTemp_BMSH_ConnectNegOverTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_ConnectPosOverTemp_BMSH_ConnectPosOverTemp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_ConnectPosOverTemp_BMSH_ConnectPosOverTemp.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ConnectPosOverTemp_BMSH_ConnectPosOverTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DCChargeProcess_BMSH_DCChargeProcess = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChargeProcess_BMSH_DCChargeProcess.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChargeProcess_BMSH_DCChargeProcess = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DCChgCurReq_BMSH_DCChgCurReq = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgCurReq_BMSH_DCChgCurReq.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgCurReq_BMSH_DCChgCurReq = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DCChgPosRelayFault_BMSH_DCChgPosRelayFault = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgPosRelayFault_BMSH_DCChgPosRelayFault.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgPosRelayFault_BMSH_DCChgPosRelayFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DCChgRelayFault_BMSH_DCChgRelayFault = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRelayFault_BMSH_DCChgRelayFault.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgRelayFault_BMSH_DCChgRelayFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DCChgRx_OTime_CCS_BMSH_DCChgRx_OTime_CCS = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CCS_BMSH_DCChgRx_OTime_CCS.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CCS_BMSH_DCChgRx_OTime_CCS = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DCChgRx_OTime_CML_BMSH_DCChgRx_OTime_CML = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CML_BMSH_DCChgRx_OTime_CML.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CML_BMSH_DCChgRx_OTime_CML = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DCChgRx_OTime_CRM00_BMSH_DCChgRx_OTime_CRM00 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CRM00_BMSH_DCChgRx_OTime_CRM00.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CRM00_BMSH_DCChgRx_OTime_CRM00 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DCChgRx_OTime_CRMAA_BMSH_DCChgRx_OTime_CRMAA = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CRMAA_BMSH_DCChgRx_OTime_CRMAA.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CRMAA_BMSH_DCChgRx_OTime_CRMAA = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DCChgRx_OTime_CSD_BMSH_DCChgRx_OTime_CSD = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CSD_BMSH_DCChgRx_OTime_CSD.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CSD_BMSH_DCChgRx_OTime_CSD = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DCChgVoltAllow_BMSH_DCChgVoltAllow = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgVoltAllow_BMSH_DCChgVoltAllow.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgVoltAllow_BMSH_DCChgVoltAllow = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DataStorageFault_BMSH_DataStorageFault = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DataStorageFault_BMSH_DataStorageFault.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DataStorageFault_BMSH_DataStorageFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DisChgOverCurrent_BMSH_DisChgOverCurrent = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DisChgOverCurrent_BMSH_DisChgOverCurrent.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DisChgOverCurrent_BMSH_DisChgOverCurrent = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DisChgOverTemp_BMSH_DisChgOverTemp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DisChgOverTemp_BMSH_DisChgOverTemp.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DisChgOverTemp_BMSH_DisChgOverTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DisChgUnderTemp_BMSH_DisChgUnderTemp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DisChgUnderTemp_BMSH_DisChgUnderTemp.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DisChgUnderTemp_BMSH_DisChgUnderTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_EVCANComFault_BMSH_EVCANComFault = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_EVCANComFault_BMSH_EVCANComFault.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_EVCANComFault_BMSH_EVCANComFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_FastChgComFault_BMSH_FastChgComFault = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_FastChgComFault_BMSH_FastChgComFault.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FastChgComFault_BMSH_FastChgComFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_FaultCode_BMSH_FaultCode = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_FaultCode_BMSH_FaultCode.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FaultCode_BMSH_FaultCode = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_FireAlarm_BMSH_FireAlarm = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_FireAlarm_BMSH_FireAlarm.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FireAlarm_BMSH_FireAlarm = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_IntComFault_BMSH_IntComFault = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_IntComFault_BMSH_IntComFault.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_IntComFault_BMSH_IntComFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_MainNegRelayFault_BMSH_MainNegRelayFault = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_MainNegRelayFault_BMSH_MainNegRelayFault.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_MainNegRelayFault_BMSH_MainNegRelayFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_MainPosRelayFault_BMSH_MainPosRelayFault = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_MainPosRelayFault_BMSH_MainPosRelayFault.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_MainPosRelayFault_BMSH_MainPosRelayFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_PackCode1_BMSH_PackCode1 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode1_BMSH_PackCode1.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode1_BMSH_PackCode1 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_PackCode1_1_BMSH_PackCode1_1 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode1_1_BMSH_PackCode1_1.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode1_1_BMSH_PackCode1_1 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_PackCode2_BMSH_PackCode2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode2_BMSH_PackCode2.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode2_BMSH_PackCode2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_PackCode2_1_BMSH_PackCode2_1 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode2_1_BMSH_PackCode2_1.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode2_1_BMSH_PackCode2_1 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_PackCode3_BMSH_PackCode3 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode3_BMSH_PackCode3.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode3_BMSH_PackCode3 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_PackCode3_1_BMSH_PackCode3_1 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode3_1_BMSH_PackCode3_1.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode3_1_BMSH_PackCode3_1 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_PackCode4_BMSH_PackCode4 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode4_BMSH_PackCode4.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode4_BMSH_PackCode4 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_PackCode4_1_BMSH_PackCode4_1 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode4_1_BMSH_PackCode4_1.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode4_1_BMSH_PackCode4_1 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_PackCode5_BMSH_PackCode5 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode5_BMSH_PackCode5.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode5_BMSH_PackCode5 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_PackCode5_1_BMSH_PackCode5_1 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode5_1_BMSH_PackCode5_1.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode5_1_BMSH_PackCode5_1 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_PackCode6_BMSH_PackCode6 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode6_BMSH_PackCode6.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode6_BMSH_PackCode6 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_PackCode7_BMSH_PackCode7 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode7_BMSH_PackCode7.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode7_BMSH_PackCode7 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_PackCode_ID_BMSH_PackCode_ID = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode_ID_BMSH_PackCode_ID.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackCode_ID_BMSH_PackCode_ID = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_PackVolt_BMSH_PackVolt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackVolt_BMSH_PackVolt.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackVolt_BMSH_PackVolt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_RecoveryOverCurrent_BMSH_RecoveryOverCurrent = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_RecoveryOverCurrent_BMSH_RecoveryOverCurrent.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_RecoveryOverCurrent_BMSH_RecoveryOverCurrent = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_SelfCheckFault_BMSH_SelfCheckFault = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_SelfCheckFault_BMSH_SelfCheckFault.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_SelfCheckFault_BMSH_SelfCheckFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_StsA_plus_BMSH_StsA_plus = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsA_plus_BMSH_StsA_plus.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsA_plus_BMSH_StsA_plus = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_StsCC2_BMSH_StsCC2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsCC2_BMSH_StsCC2.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsCC2_BMSH_StsCC2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_StsCellBalance_BMSH_StsCellBalance = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsCellBalance_BMSH_StsCellBalance.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsCellBalance_BMSH_StsCellBalance = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_StsChgFault_BMSH_StsChgFault = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsChgFault_BMSH_StsChgFault.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsChgFault_BMSH_StsChgFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_StsDischgFault_BMSH_StsDischgFault = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsDischgFault_BMSH_StsDischgFault.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsDischgFault_BMSH_StsDischgFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_StsInsulation_BMSH_StsInsulation = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsInsulation_BMSH_StsInsulation.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsInsulation_BMSH_StsInsulation = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_StsMode_BMSH_StsMode = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsMode_BMSH_StsMode.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsMode_BMSH_StsMode = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_StsPrecharge_BMSH_StsPrecharge = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsPrecharge_BMSH_StsPrecharge.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsPrecharge_BMSH_StsPrecharge = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_StsWakeUp_BMSH_StsWakeUp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsWakeUp_BMSH_StsWakeUp.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_StsWakeUp_BMSH_StsWakeUp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_SwapCntOverTemp_BMSH_SwapCntOverTemp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_SwapCntOverTemp_BMSH_SwapCntOverTemp.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_SwapCntOverTemp_BMSH_SwapCntOverTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatFaultList_BMSH_TBOX_BatFaultList = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatFaultList_BMSH_TBOX_BatFaultList.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatFaultList_BMSH_TBOX_BatFaultList = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatHVILFault_BMSH_TBOX_BatHVILFault = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatHVILFault_BMSH_TBOX_BatHVILFault.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatHVILFault_BMSH_TBOX_BatHVILFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatIsoAlarm_BMSH_TBOX_BatIsoAlarm = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatIsoAlarm_BMSH_TBOX_BatIsoAlarm.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatIsoAlarm_BMSH_TBOX_BatIsoAlarm = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatLowSOC_BMSH_TBOX_BatLowSOC = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatLowSOC_BMSH_TBOX_BatLowSOC.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatLowSOC_BMSH_TBOX_BatLowSOC = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatLowTemp_BMSH_TBOX_BatLowTemp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatLowTemp_BMSH_TBOX_BatLowTemp.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatLowTemp_BMSH_TBOX_BatLowTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatOverCharge_BMSH_TBOX_BatOverCharge = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverCharge_BMSH_TBOX_BatOverCharge.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverCharge_BMSH_TBOX_BatOverCharge = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatOverSOC_BMSH_TBOX_BatOverSOC = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverSOC_BMSH_TBOX_BatOverSOC.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverSOC_BMSH_TBOX_BatOverSOC = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatOverTemp_BMSH_TBOX_BatOverTemp = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverTemp_BMSH_TBOX_BatOverTemp.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverTemp_BMSH_TBOX_BatOverTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatOverVoltage_BMSH_TBOX_BatOverVoltage = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverVoltage_BMSH_TBOX_BatOverVoltage.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverVoltage_BMSH_TBOX_BatOverVoltage = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatSeriesCellsSum_BMSH_TBOX_BatSeriesCellsSum = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatSeriesCellsSum_BMSH_TBOX_BatSeriesCellsSum.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatSeriesCellsSum_BMSH_TBOX_BatSeriesCellsSum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatStoreSysFault_BMSH_TBOX_BatStoreSysFault = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatStoreSysFault_BMSH_TBOX_BatStoreSysFault.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatStoreSysFault_BMSH_TBOX_BatStoreSysFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatTempUniformity_BMSH_TBOX_BatTempUniformity = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatTempUniformity_BMSH_TBOX_BatTempUniformity.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatTempUniformity_BMSH_TBOX_BatTempUniformity = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatUnderVoltage_BMSH_TBOX_BatUnderVoltage = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatUnderVoltage_BMSH_TBOX_BatUnderVoltage.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatUnderVoltage_BMSH_TBOX_BatUnderVoltage = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatUniformity_BMSH_TBOX_BatUniformity = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatUniformity_BMSH_TBOX_BatUniformity.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatUniformity_BMSH_TBOX_BatUniformity = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_CellOverVoltage_BMSH_TBOX_CellOverVoltage = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellOverVoltage_BMSH_TBOX_CellOverVoltage.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellOverVoltage_BMSH_TBOX_CellOverVoltage = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_CellUnderVoltage_BMSH_TBOX_CellUnderVoltage = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellUnderVoltage_BMSH_TBOX_CellUnderVoltage.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellUnderVoltage_BMSH_TBOX_CellUnderVoltage = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_InsulationResistance_BMSH_TBOX_InsulationResistance = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_InsulationResistance_BMSH_TBOX_InsulationResistance.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_InsulationResistance_BMSH_TBOX_InsulationResistance = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_SOCHop_BMSH_TBOX_SOCHop = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_SOCHop_BMSH_TBOX_SOCHop.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_SOCHop_BMSH_TBOX_SOCHop = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_TempA_BMSH_TBOX_TempA = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempA_BMSH_TBOX_TempA.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempA_BMSH_TBOX_TempA = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_TempB_BMSH_TBOX_TempB = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempB_BMSH_TBOX_TempB.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempB_BMSH_TBOX_TempB = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_TempC_BMSH_TBOX_TempC = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempC_BMSH_TBOX_TempC.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempC_BMSH_TBOX_TempC = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_TempD_BMSH_TBOX_TempD = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempD_BMSH_TBOX_TempD.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempD_BMSH_TBOX_TempD = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_TempE_BMSH_TBOX_TempE = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempE_BMSH_TBOX_TempE.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempE_BMSH_TBOX_TempE = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_TempF_BMSH_TBOX_TempF = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempF_BMSH_TBOX_TempF.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempF_BMSH_TBOX_TempF = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_TempF_ID_BMSH_TBOX_TempF_ID = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempF_ID_BMSH_TBOX_TempF_ID.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TempF_ID_BMSH_TBOX_TempF_ID = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCUChksumFault_BMSH_VCUChksumFault = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCUChksumFault_BMSH_VCUChksumFault.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCUChksumFault_BMSH_VCUChksumFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCURollCountFault_BMSH_VCURollCountFault = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCURollCountFault_BMSH_VCURollCountFault.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCURollCountFault_BMSH_VCURollCountFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCU_BatChgContPwr_BMSH_VCU_BatChgContPwr = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCU_BatChgContPwr_BMSH_VCU_BatChgContPwr.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_BatChgContPwr_BMSH_VCU_BatChgContPwr = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCU_BatDischgContPwr_BMSH_VCU_BatDischgContPwr = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCU_BatDischgContPwr_BMSH_VCU_BatDischgContPwr.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_BatDischgContPwr_BMSH_VCU_BatDischgContPwr = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCU_StsDCChgPosRelay_BMSH_VCU_StsDCChgPosRelay = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCU_StsDCChgPosRelay_BMSH_VCU_StsDCChgPosRelay.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_StsDCChgPosRelay_BMSH_VCU_StsDCChgPosRelay = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCU_StsDCChgRelay_BMSH_VCU_StsDCChgRelay = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCU_StsDCChgRelay_BMSH_VCU_StsDCChgRelay.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_StsDCChgRelay_BMSH_VCU_StsDCChgRelay = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCU_StsPreChgRelay_BMSH_VCU_StsPreChgRelay = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCU_StsPreChgRelay_BMSH_VCU_StsPreChgRelay.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_StsPreChgRelay_BMSH_VCU_StsPreChgRelay = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_B2V_ST1_ChgMode_BMS_B2V_ST1_ChgMode = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_B2V_ST1_ChgMode_BMS_B2V_ST1_ChgMode.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_B2V_ST1_ChgMode_BMS_B2V_ST1_ChgMode = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_BattCellsNumPN_BMS_BattCellsNumPN = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattCellsNumPN_BMS_BattCellsNumPN.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattCellsNumPN_BMS_BattCellsNumPN = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_BattPackNumSN_BMS_BattPackNumSN = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattPackNumSN_BMS_BattPackNumSN.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattPackNumSN_BMS_BattPackNumSN = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_BattTemp1_BMS_BattTemp1 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattTemp1_BMS_BattTemp1.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattTemp1_BMS_BattTemp1 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_BattTemp2_BMS_BattTemp2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattTemp2_BMS_BattTemp2.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattTemp2_BMS_BattTemp2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_BattTemp3_BMS_BattTemp3 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattTemp3_BMS_BattTemp3.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattTemp3_BMS_BattTemp3 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_BattTemp4_BMS_BattTemp4 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattTemp4_BMS_BattTemp4.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattTemp4_BMS_BattTemp4 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_BattTemp5_BMS_BattTemp5 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattTemp5_BMS_BattTemp5.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattTemp5_BMS_BattTemp5 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_BattTemp6_BMS_BattTemp6 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattTemp6_BMS_BattTemp6.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_BattTemp6_BMS_BattTemp6 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_CCvalue_BMS_CCvalue = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CCvalue_BMS_CCvalue.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CCvalue_BMS_CCvalue = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_CPLine_S2_Ctrl_BMS_CPLine_S2_Ctrl = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CPLine_S2_Ctrl_BMS_CPLine_S2_Ctrl.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CPLine_S2_Ctrl_BMS_CPLine_S2_Ctrl = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_CP_Duty_BMS_CP_Duty = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CP_Duty_BMS_CP_Duty.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CP_Duty_BMS_CP_Duty = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_CP_Vol_BMS_CP_Vol = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CP_Vol_BMS_CP_Vol.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CP_Vol_BMS_CP_Vol = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_CellTempFrameNum_BMS_CellTempFrameNum = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CellTempFrameNum_BMS_CellTempFrameNum.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CellTempFrameNum_BMS_CellTempFrameNum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_CellVoltFrameNum_BMS_CellVoltFrameNum = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CellVoltFrameNum_BMS_CellVoltFrameNum.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CellVoltFrameNum_BMS_CellVoltFrameNum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_CellVoltN1_BMS_CellVoltN1 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CellVoltN1_BMS_CellVoltN1.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CellVoltN1_BMS_CellVoltN1 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_CellVoltN2_BMS_CellVoltN2 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CellVoltN2_BMS_CellVoltN2.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CellVoltN2_BMS_CellVoltN2 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_CellVoltN3_BMS_CellVoltN3 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CellVoltN3_BMS_CellVoltN3.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CellVoltN3_BMS_CellVoltN3 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_ChgStatus_BMS_ChgStatus = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_ChgStatus_BMS_ChgStatus.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_ChgStatus_BMS_ChgStatus = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_CutOffLVFbToOBC_BMS_CutOffLVFbToOBC = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CutOffLVFbToOBC_BMS_CutOffLVFbToOBC.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_CutOffLVFbToOBC_BMS_CutOffLVFbToOBC = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_DCChargRelayCtrl_BMS_DCChargRelayCtrl = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_DCChargRelayCtrl_BMS_DCChargRelayCtrl.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_DCChargRelayCtrl_BMS_DCChargRelayCtrl = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_DelayControl_BMS_DelayControl = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_DelayControl_BMS_DelayControl.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_DelayControl_BMS_DelayControl = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_DischargeCCvalue_BMS_DischargeCCvalue = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_DischargeCCvalue_BMS_DischargeCCvalue.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_DischargeCCvalue_BMS_DischargeCCvalue = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_ElectroniclockContorREQ_BMS_ElectroniclockContorREQ = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_ElectroniclockContorREQ_BMS_ElectroniclockContorREQ.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_ElectroniclockContorREQ_BMS_ElectroniclockContorREQ = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_ElectroniclockSts_BMS_ElectroniclockSts = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_ElectroniclockSts_BMS_ElectroniclockSts.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_ElectroniclockSts_BMS_ElectroniclockSts = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_MaxChgCurrent_BMS_MaxChgCurrent = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_MaxChgCurrent_BMS_MaxChgCurrent.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_MaxChgCurrent_BMS_MaxChgCurrent = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_MaxChgVoltage_BMS_MaxChgVoltage = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_MaxChgVoltage_BMS_MaxChgVoltage.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_MaxChgVoltage_BMS_MaxChgVoltage = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_OBCChgContrlCmd_BMS_OBCChgContrlCmd = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_OBCChgContrlCmd_BMS_OBCChgContrlCmd.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_OBCChgContrlCmd_BMS_OBCChgContrlCmd = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_S2STATUS_BMS_S2STATUS = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_S2STATUS_BMS_S2STATUS.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_S2STATUS_BMS_S2STATUS = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_SysCodeBattPackSN_1_BMS_SysCodeBattPackSN_1 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_SysCodeBattPackSN_1_BMS_SysCodeBattPackSN_1.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_SysCodeBattPackSN_1_BMS_SysCodeBattPackSN_1 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_SysCodeFrameNum_1_BMS_SysCodeFrameNum_1 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_SysCodeFrameNum_1_BMS_SysCodeFrameNum_1.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_SysCodeFrameNum_1_BMS_SysCodeFrameNum_1 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_SysCodeLength_1_BMS_SysCodeLength_1 = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_SysCodeLength_1_BMS_SysCodeLength_1.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_SysCodeLength_1_BMS_SysCodeLength_1 = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_TempCSCNum_BMS_TempCSCNum = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_TempCSCNum_BMS_TempCSCNum.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_TempCSCNum_BMS_TempCSCNum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_TempSnsNumPN_BMS_TempSnsNumPN = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_TempSnsNumPN_BMS_TempSnsNumPN.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_TempSnsNumPN_BMS_TempSnsNumPN = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_VoltCellNum_BMS_VoltCellNum = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_VoltCellNum_BMS_VoltCellNum.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_VoltCellNum_BMS_VoltCellNum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req = *(&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req = RTE_COM_SENDSIGNALPROXY_SEND;

    swc_SetOutputInterface_100ms();

    swc_SetSendCANMsg_100ms();

    (void)TerminateTask();
}

TASK(App1_Task_1000ms_Core2_QM)
{
    swc_SetSendCANMsg_1000ms();

    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_1000ms.Rte_CTC_StHvbat_CTC_StHvbat.value) = Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_1000ms.Rte_DEH_StsIninNv_DEH_StsIninNv.value) = Rte_swc_DiagcEveHndlg_DEH_StsIninNv_DEH_StsIninNv;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_1000ms.Rte_DEH_bAcvBdNew_DEH_bAcvBdNew.value) = Rte_swc_DiagcEveHndlg_DEH_bAcvBdNew_DEH_bAcvBdNew;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_1000ms.Rte_NVM_TiBatAgi_NVM_TiBatAgi.value) = Rte_swc_DiagcEveHndlg_NVM_TiBatAgi_NVM_TiBatAgi;
    BWLD_1000ms();
    Rte_swc_BatWntyLogtcData_BWLD_TiBatAgi_BWLD_TiBatAgi = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_1000ms.Rte_BWLD_TiBatAgi_BWLD_TiBatAgi.value);
    Rte_swc_BatWntyLogtcData_BWLD_TiBatAgiNv_BWLD_TiBatAgiNv = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_1000ms.Rte_BWLD_TiBatAgiNv_BWLD_TiBatAgiNv.value);

    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_BSTC_StBcu_BSTC_StBcu.value) = Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_CIL_IBatHv_CIL_IBatHv.value) = Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_CTC_StRlyCh_CTC_StRlyCh.value) = Rte_swc_CtctrTranCtl_CTC_StRlyCh_CTC_StRlyCh;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_CTC_StRlyHeat_CTC_StRlyHeat.value) = Rte_swc_CtctrTranCtl_CTC_StRlyHeat_CTC_StRlyHeat;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_CTC_StRlyNeg_CTC_StRlyNeg.value) = Rte_swc_CtctrTranCtl_CTC_StRlyNeg_CTC_StRlyNeg;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_CTC_StRlyPos_CTC_StRlyPos.value) = Rte_swc_CtctrTranCtl_CTC_StRlyPos_CTC_StRlyPos;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_CTC_StRlyPrech_CTC_StRlyPrech.value) = Rte_swc_CtctrTranCtl_CTC_StRlyPrech_CTC_StRlyPrech;
    DEH_1000ms();
    Rte_swc_DiagcEveHndlg_DEH_BatMfctrType_DEH_BatMfctrType = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_BatMfctrType_DEH_BatMfctrType.value);
    Rte_swc_DiagcEveHndlg_DEH_BatMfctrr_DEH_BatMfctrr = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_BatMfctrr_DEH_BatMfctrr.value);
    Rte_swc_DiagcEveHndlg_DEH_CBatNom_DEH_CBatNom = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_CBatNom_DEH_CBatNom.value);
    Rte_swc_DiagcEveHndlg_DEH_CtrRlyReqDiag_DEH_CtrRlyReqDiag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_CtrRlyReqDiag_DEH_CtrRlyReqDiag.value);
    Rte_swc_DiagcEveHndlg_DEH_DayBatMfctr_DEH_DayBatMfctr = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_DayBatMfctr_DEH_DayBatMfctr.value);
    Rte_swc_DiagcEveHndlg_DEH_ErrRlyCtlDiag_DEH_ErrRlyCtlDiag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_ErrRlyCtlDiag_DEH_ErrRlyCtlDiag.value);
    Rte_swc_DiagcEveHndlg_DEH_MonthBatMfctr_DEH_MonthBatMfctr = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_MonthBatMfctr_DEH_MonthBatMfctr.value);
    Rte_swc_DiagcEveHndlg_DEH_NrPackSerl_DEH_NrPackSerl = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrPackSerl_DEH_NrPackSerl.value);
    Rte_swc_DiagcEveHndlg_DEH_NrVin1_DEH_NrVin1 = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin1_DEH_NrVin1.value);
    Rte_swc_DiagcEveHndlg_DEH_NrVin10_DEH_NrVin10 = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin10_DEH_NrVin10.value);
    Rte_swc_DiagcEveHndlg_DEH_NrVin11_DEH_NrVin11 = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin11_DEH_NrVin11.value);
    Rte_swc_DiagcEveHndlg_DEH_NrVin12_DEH_NrVin12 = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin12_DEH_NrVin12.value);
    Rte_swc_DiagcEveHndlg_DEH_NrVin13_DEH_NrVin13 = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin13_DEH_NrVin13.value);
    Rte_swc_DiagcEveHndlg_DEH_NrVin14_DEH_NrVin14 = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin14_DEH_NrVin14.value);
    Rte_swc_DiagcEveHndlg_DEH_NrVin15_DEH_NrVin15 = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin15_DEH_NrVin15.value);
    Rte_swc_DiagcEveHndlg_DEH_NrVin16_DEH_NrVin16 = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin16_DEH_NrVin16.value);
    Rte_swc_DiagcEveHndlg_DEH_NrVin17_DEH_NrVin17 = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin17_DEH_NrVin17.value);
    Rte_swc_DiagcEveHndlg_DEH_NrVin2_DEH_NrVin2 = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin2_DEH_NrVin2.value);
    Rte_swc_DiagcEveHndlg_DEH_NrVin3_DEH_NrVin3 = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin3_DEH_NrVin3.value);
    Rte_swc_DiagcEveHndlg_DEH_NrVin4_DEH_NrVin4 = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin4_DEH_NrVin4.value);
    Rte_swc_DiagcEveHndlg_DEH_NrVin5_DEH_NrVin5 = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin5_DEH_NrVin5.value);
    Rte_swc_DiagcEveHndlg_DEH_NrVin6_DEH_NrVin6 = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin6_DEH_NrVin6.value);
    Rte_swc_DiagcEveHndlg_DEH_NrVin7_DEH_NrVin7 = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin7_DEH_NrVin7.value);
    Rte_swc_DiagcEveHndlg_DEH_NrVin8_DEH_NrVin8 = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin8_DEH_NrVin8.value);
    Rte_swc_DiagcEveHndlg_DEH_NrVin9_DEH_NrVin9 = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin9_DEH_NrVin9.value);
    Rte_MemCpy(Rte_swc_DiagcEveHndlg_DEH_PackCode_DEH_PackCode, Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_PackCode_DEH_PackCode.value, sizeof(rt_Array_UInt8_24));
    Rte_swc_DiagcEveHndlg_DEH_UBatNom_DEH_UBatNom = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_UBatNom_DEH_UBatNom.value);
    Rte_swc_DiagcEveHndlg_DEH_YearBatMfctr_DEH_YearBatMfctr = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_YearBatMfctr_DEH_YearBatMfctr.value);

    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BCC_EChSng_BCC_EChSng.value) = Rte_swc_BatChCtl_BCC_EChSng_BCC_EChSng;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BCF_IChLim_BCF_IChLim.value) = Rte_swc_BatCoreFct_BCF_IChLim_BCF_IChLim;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BCF_IChLimMap_BCF_IChLimMap.value) = Rte_swc_BatCoreFct_BCF_IChLimMap_BCF_IChLimMap;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BCF_IDchaLim_BCF_IDchaLim.value) = Rte_swc_BatCoreFct_BCF_IDchaLim_BCF_IDchaLim;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BCF_IDchaLimMap_BCF_IDchaLimMap.value) = Rte_swc_BatCoreFct_BCF_IDchaLimMap_BCF_IDchaLimMap;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BCF_SocLimMin_BCF_SocLimMin.value) = Rte_swc_BatCoreFct_BCF_SocLimMin_BCF_SocLimMin;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BCF_bChrgFullCalRemind_BCF_bChrgFullCalRemind.value) = Rte_swc_BatCoreFct_BCF_bChrgFullCalRemind_BCF_bChrgFullCalRemind;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot.value) = Rte_swc_BatChCtl_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BPIU_IdCellUMax_BPIU_IdCellUMax.value) = Rte_swc_BatProtnIU_BPIU_IdCellUMax_BPIU_IdCellUMax;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BPIU_IdCellUMin_BPIU_IdCellUMin.value) = Rte_swc_BatProtnIU_BPIU_IdCellUMin_BPIU_IdCellUMin;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BPIU_UCellMax_BPIU_UCellMax.value) = Rte_swc_BatProtnIU_BPIU_UCellMax_BPIU_UCellMax;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BPIU_UCellMin_BPIU_UCellMin.value) = Rte_swc_BatProtnIU_BPIU_UCellMin_BPIU_UCellMin;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BSOF_EChSng_BSOF_EChSng.value) = Rte_swc_CIL_BSOF_EChSng_BSOF_EChSng;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BSOF_IChrgr_BSOF_IChrgr.value) = Rte_swc_CIL_BSOF_IChrgr_BSOF_IChrgr;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BSOF_UChrgr_BSOF_UChrgr.value) = Rte_swc_CIL_BSOF_UChrgr_BSOF_UChrgr;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BTHM_IdCellTMax_BTHM_IdCellTMax.value) = Rte_swc_BatThermHndlgMngt_BTHM_IdCellTMax_BTHM_IdCellTMax;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BTHM_IdCellTMin_BTHM_IdCellTMin.value) = Rte_swc_BatThermHndlgMngt_BTHM_IdCellTMin_BTHM_IdCellTMin;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BTHM_TOptmMax_BTHM_TOptmMax.value) = Rte_swc_BatThermHndlgMngt_BTHM_TOptmMax_BTHM_TOptmMax;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BTHM_TOptmMin_BTHM_TOptmMin.value) = Rte_swc_BatThermHndlgMngt_BTHM_TOptmMin_BTHM_TOptmMin;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BTHM_TPack_BTHM_TPack.value) = Rte_swc_BatThermHndlgMngt_BTHM_TPack_BTHM_TPack;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BWLD_CBatChTot_BWLD_CBatChTot.value) = Rte_swc_BatWntyLogtcData_BWLD_CBatChTot_BWLD_CBatChTot;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BWLD_CBatDchaTot_BWLD_CBatDchaTot.value) = Rte_swc_BatWntyLogtcData_BWLD_CBatDchaTot_BWLD_CBatDchaTot;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BWLD_CBatRecoveryTot_BWLD_CBatRecoveryTot.value) = Rte_swc_BatWntyLogtcData_BWLD_CBatRecoveryTot_BWLD_CBatRecoveryTot;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BWLD_CtrCh_BWLD_CtrCh.value) = Rte_swc_BatWntyLogtcData_BWLD_CtrCh_BWLD_CtrCh;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BWLD_EBatChTot_BWLD_EBatChTot.value) = Rte_swc_BatWntyLogtcData_BWLD_EBatChTot_BWLD_EBatChTot;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BWLD_EBatDchaDrvCyc_BWLD_EBatDchaDrvCyc.value) = Rte_swc_BatWntyLogtcData_BWLD_EBatDchaDrvCyc_BWLD_EBatDchaDrvCyc;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BWLD_EBatDchaTot_BWLD_EBatDchaTot.value) = Rte_swc_BatWntyLogtcData_BWLD_EBatDchaTot_BWLD_EBatDchaTot;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BWLD_EBatRecoveryDrvCyc_BWLD_EBatRecoveryDrvCyc.value) = Rte_swc_BatWntyLogtcData_BWLD_EBatRecoveryDrvCyc_BWLD_EBatRecoveryDrvCyc;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BWLD_EBatRecoveryTot_BWLD_EBatRecoveryTot.value) = Rte_swc_BatWntyLogtcData_BWLD_EBatRecoveryTot_BWLD_EBatRecoveryTot;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_BatCoolType_CIL_BatCoolType.value) = Rte_swc_CIL_CIL_BatCoolType_CIL_BatCoolType;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_ChargeModeReq_CIL_ChargeModeReq.value) = Rte_swc_CIL_CIL_ChargeModeReq_CIL_ChargeModeReq;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl.value) = Rte_swc_CIL_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_HWVerVeh_CIL_HWVerVeh.value) = Rte_swc_CIL_CIL_HWVerVeh_CIL_HWVerVeh;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_MilgTot_CIL_MilgTot.value) = Rte_swc_CIL_CIL_MilgTot_CIL_MilgTot;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl.value) = Rte_swc_CIL_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_SWVerVeh_CIL_SWVerVeh.value) = Rte_swc_CIL_CIL_SWVerVeh_CIL_SWVerVeh;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_TDcChPointNeg_CIL_TDcChPointNeg.value) = Rte_swc_CIL_CIL_TDcChPointNeg_CIL_TDcChPointNeg;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_TDcChPointPos_CIL_TDcChPointPos.value) = Rte_swc_CIL_CIL_TDcChPointPos_CIL_TDcChPointPos;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_UTrml30_CIL_UTrml30.value) = Rte_swc_CIL_CIL_UTrml30_CIL_UTrml30;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_DEH_BatMfctrType_DEH_BatMfctrType.value) = Rte_swc_DiagcEveHndlg_DEH_BatMfctrType_DEH_BatMfctrType;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_DEH_BatMfctrr_DEH_BatMfctrr.value) = Rte_swc_DiagcEveHndlg_DEH_BatMfctrr_DEH_BatMfctrr;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_DEH_CBatNom_DEH_CBatNom.value) = Rte_swc_DiagcEveHndlg_DEH_CBatNom_DEH_CBatNom;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_DEH_DayBatMfctr_DEH_DayBatMfctr.value) = Rte_swc_DiagcEveHndlg_DEH_DayBatMfctr_DEH_DayBatMfctr;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_DEH_MonthBatMfctr_DEH_MonthBatMfctr.value) = Rte_swc_DiagcEveHndlg_DEH_MonthBatMfctr_DEH_MonthBatMfctr;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_DEH_NrPackSerl_DEH_NrPackSerl.value) = Rte_swc_DiagcEveHndlg_DEH_NrPackSerl_DEH_NrPackSerl;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_DEH_UBatNom_DEH_UBatNom.value) = Rte_swc_DiagcEveHndlg_DEH_UBatNom_DEH_UBatNom;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_DEH_YearBatMfctr_DEH_YearBatMfctr.value) = Rte_swc_DiagcEveHndlg_DEH_YearBatMfctr_DEH_YearBatMfctr;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr.value) = Rte_swc_BatChCtl_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr;
    Rte_MemCpy(Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_MCC_NrCellByMdul_MCC_NrCellByMdul.value, Rte_swc_CIL_MCC_NrCellByMdul_MCC_NrCellByMdul, sizeof(rt_Array_UInt8_24));
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_MCC_NrCellTot_MCC_NrCellTot.value) = Rte_swc_CIL_MCC_NrCellTot_MCC_NrCellTot;
    *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_MCC_NrMdulTot_MCC_NrMdulTot.value) = Rte_swc_CIL_MCC_NrMdulTot_MCC_NrMdulTot;
    COL_1000ms();
    Rte_swc_COL_B2V_SingleChgEnergy_B2V_SingleChgEnergy = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_B2V_SingleChgEnergy_B2V_SingleChgEnergy.value);


    Rte_swc_COL_BMSH_AllowBatTempMax_BMSH_AllowBatTempMax = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_AllowBatTempMax_BMSH_AllowBatTempMax.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_AllowBatTempMax_BMSH_AllowBatTempMax = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_AllowBatTempMin_BMSH_AllowBatTempMin = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_AllowBatTempMin_BMSH_AllowBatTempMin.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_AllowBatTempMin_BMSH_AllowBatTempMin = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_AllowCellVoltMax_BMSH_AllowCellVoltMax = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_AllowCellVoltMax_BMSH_AllowCellVoltMax.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_AllowCellVoltMax_BMSH_AllowCellVoltMax = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_AllowCellVoltMin_BMSH_AllowCellVoltMin = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_AllowCellVoltMin_BMSH_AllowCellVoltMin.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_AllowCellVoltMin_BMSH_AllowCellVoltMin = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_AllowPackVoltMax_BMSH_AllowPackVoltMax = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_AllowPackVoltMax_BMSH_AllowPackVoltMax.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_AllowPackVoltMax_BMSH_AllowPackVoltMax = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_AllowPackVoltMin_BMSH_AllowPackVoltMin = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_AllowPackVoltMin_BMSH_AllowPackVoltMin.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_AllowPackVoltMin_BMSH_AllowPackVoltMin = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BatMaintReqValidFlag_BMSH_BatMaintReqValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatMaintReqValidFlag_BMSH_BatMaintReqValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatMaintReqValidFlag_BMSH_BatMaintReqValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BatMaintenanceReq_BMSH_BatMaintenanceReq = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatMaintenanceReq_BMSH_BatMaintenanceReq.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatMaintenanceReq_BMSH_BatMaintenanceReq = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BatRealSOCValidFlag_BMSH_BatRealSOCValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatRealSOCValidFlag_BMSH_BatRealSOCValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatRealSOCValidFlag_BMSH_BatRealSOCValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BatSOEValidFlag_BMSH_BatSOEValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatSOEValidFlag_BMSH_BatSOEValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatSOEValidFlag_BMSH_BatSOEValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BatSOHValidFlag_BMSH_BatSOHValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatSOHValidFlag_BMSH_BatSOHValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatSOHValidFlag_BMSH_BatSOHValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BatTempMax_BMSH_BatTempMax = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatTempMax_BMSH_BatTempMax.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatTempMax_BMSH_BatTempMax = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BatTempMin_BMSH_BatTempMin = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatTempMin_BMSH_BatTempMin.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatTempMin_BMSH_BatTempMin = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BatUseableSOCValidFlag_BMSH_BatUseableSOCValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatUseableSOCValidFlag_BMSH_BatUseableSOCValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BatUseableSOCValidFlag_BMSH_BatUseableSOCValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BattPackNum_BMSH_BattPackNum = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BattPackNum_BMSH_BattPackNum.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BattPackNum_BMSH_BattPackNum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BattSysNum_BMSH_BattSysNum = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BattSysNum_BMSH_BattSysNum.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BattSysNum_BMSH_BattSysNum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BattTempAvg_BMSH_BattTempAvg = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BattTempAvg_BMSH_BattTempAvg.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BattTempAvg_BMSH_BattTempAvg = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_BusVoltValidFlag_BMSH_BusVoltValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BusVoltValidFlag_BMSH_BusVoltValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_BusVoltValidFlag_BMSH_BusVoltValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_CCM_InletTargTmpValidFlag_BMSH_CCM_InletTargTmpValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CCM_InletTargTmpValidFlag_BMSH_CCM_InletTargTmpValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_InletTargTmpValidFlag_BMSH_CCM_InletTargTmpValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_CCM_LiquidInTempValidFlag_BMSH_CCM_LiquidInTempValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CCM_LiquidInTempValidFlag_BMSH_CCM_LiquidInTempValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_LiquidInTempValidFlag_BMSH_CCM_LiquidInTempValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_CCM_LiquidOutTmpValidFlag_BMSH_CCM_LiquidOutTmpValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CCM_LiquidOutTmpValidFlag_BMSH_CCM_LiquidOutTmpValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_LiquidOutTmpValidFlag_BMSH_CCM_LiquidOutTmpValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_CCM_ThrmlMangReqValidFlag_BMSH_CCM_ThrmlMangReqValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CCM_ThrmlMangReqValidFlag_BMSH_CCM_ThrmlMangReqValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CCM_ThrmlMangReqValidFlag_BMSH_CCM_ThrmlMangReqValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_CellVoltMax_BMSH_CellVoltMax = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CellVoltMax_BMSH_CellVoltMax.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellVoltMax_BMSH_CellVoltMax = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_CellVoltMaxModuleID_BMSH_CellVoltMaxModuleID = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CellVoltMaxModuleID_BMSH_CellVoltMaxModuleID.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellVoltMaxModuleID_BMSH_CellVoltMaxModuleID = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_CellVoltMin_BMSH_CellVoltMin = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CellVoltMin_BMSH_CellVoltMin.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellVoltMin_BMSH_CellVoltMin = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_CellVoltMinModuleID_BMSH_CellVoltMinModuleID = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CellVoltMinModuleID_BMSH_CellVoltMinModuleID.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CellVoltMinModuleID_BMSH_CellVoltMinModuleID = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_CoolType_BMSH_CoolType = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CoolType_BMSH_CoolType.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CoolType_BMSH_CoolType = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_CoolTypeValidFlag_BMSH_CoolTypeValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CoolTypeValidFlag_BMSH_CoolTypeValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_CoolTypeValidFlag_BMSH_CoolTypeValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DCChgEnder_BMSH_DCChgEnder = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DCChgEnder_BMSH_DCChgEnder.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgEnder_BMSH_DCChgEnder = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DCChgStandVer_BMSH_DCChgStandVer = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DCChgStandVer_BMSH_DCChgStandVer.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgStandVer_BMSH_DCChgStandVer = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DCChgVoltAllowValidFlag_BMSH_DCChgVoltAllowValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DCChgVoltAllowValidFlag_BMSH_DCChgVoltAllowValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCChgVoltAllowValidFlag_BMSH_DCChgVoltAllowValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DCEquipment_DisplayCur_BMSH_DCEquipment_DisplayCur = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DCEquipment_DisplayCur_BMSH_DCEquipment_DisplayCur.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCEquipment_DisplayCur_BMSH_DCEquipment_DisplayCur = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DCEquipment_DisplayVolt_BMSH_DCEquipment_DisplayVolt = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DCEquipment_DisplayVolt_BMSH_DCEquipment_DisplayVolt.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DCEquipment_DisplayVolt_BMSH_DCEquipment_DisplayVolt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DC_DisplayCurRangeUP_BMSH_DC_DisplayCurRangeUP = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DC_DisplayCurRangeUP_BMSH_DC_DisplayCurRangeUP.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DC_DisplayCurRangeUP_BMSH_DC_DisplayCurRangeUP = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_DC_DisplayVoltValidFlag_BMSH_DC_DisplayVoltValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DC_DisplayVoltValidFlag_BMSH_DC_DisplayVoltValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_DC_DisplayVoltValidFlag_BMSH_DC_DisplayVoltValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_EnergyOut_BMSH_EnergyOut = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_EnergyOut_BMSH_EnergyOut.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_EnergyOut_BMSH_EnergyOut = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_EnergyOutValidFlag_BMSH_EnergyOutValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_EnergyOutValidFlag_BMSH_EnergyOutValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_EnergyOutValidFlag_BMSH_EnergyOutValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_ExChgNumOfTimes_BMSH_ExChgNumOfTimes = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_ExChgNumOfTimes_BMSH_ExChgNumOfTimes.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ExChgNumOfTimes_BMSH_ExChgNumOfTimes = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_ExChgNumOfTimesValidFlag_BMSH_ExChgNumOfTimesValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_ExChgNumOfTimesValidFlag_BMSH_ExChgNumOfTimesValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_ExChgNumOfTimesValidFlag_BMSH_ExChgNumOfTimesValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_FinishChgTime_BMSH_FinishChgTime = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_FinishChgTime_BMSH_FinishChgTime.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FinishChgTime_BMSH_FinishChgTime = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_FinishChgTimeValidFlag_BMSH_FinishChgTimeValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_FinishChgTimeValidFlag_BMSH_FinishChgTimeValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FinishChgTimeValidFlag_BMSH_FinishChgTimeValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_FlowRateReq_BMSH_FlowRateReq = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_FlowRateReq_BMSH_FlowRateReq.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FlowRateReq_BMSH_FlowRateReq = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_FlowRateReqValidFlag_BMSH_FlowRateReqValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_FlowRateReqValidFlag_BMSH_FlowRateReqValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_FlowRateReqValidFlag_BMSH_FlowRateReqValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_PackExtendCd_BMSH_PackExtendCd = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_PackExtendCd_BMSH_PackExtendCd.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackExtendCd_BMSH_PackExtendCd = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_PackType_BMSH_PackType = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_PackType_BMSH_PackType.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackType_BMSH_PackType = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_SubtotalExChgSOE_BMSH_SubtotalExChgSOE = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_SubtotalExChgSOE_BMSH_SubtotalExChgSOE.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_SubtotalExChgSOE_BMSH_SubtotalExChgSOE = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_SubtotalRecoveryEng_BMSH_SubtotalRecoveryEng = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_SubtotalRecoveryEng_BMSH_SubtotalRecoveryEng.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_SubtotalRecoveryEng_BMSH_SubtotalRecoveryEng = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_SupplyVolt_BMSH_SupplyVolt = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_SupplyVolt_BMSH_SupplyVolt.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_SupplyVolt_BMSH_SupplyVolt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatModuleSum_BMSH_TBOX_BatModuleSum = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatModuleSum_BMSH_TBOX_BatModuleSum.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatModuleSum_BMSH_TBOX_BatModuleSum = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatProductDay_BMSH_TBOX_BatProductDay = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatProductDay_BMSH_TBOX_BatProductDay.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatProductDay_BMSH_TBOX_BatProductDay = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatProductMonth_BMSH_TBOX_BatProductMonth = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatProductMonth_BMSH_TBOX_BatProductMonth.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatProductMonth_BMSH_TBOX_BatProductMonth = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatProductYear_BMSH_TBOX_BatProductYear = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatProductYear_BMSH_TBOX_BatProductYear.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatProductYear_BMSH_TBOX_BatProductYear = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatRatedEnergy_BMSH_TBOX_BatRatedEnergy = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatRatedEnergy_BMSH_TBOX_BatRatedEnergy.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatRatedEnergy_BMSH_TBOX_BatRatedEnergy = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatRatedVolt_BMSH_TBOX_BatRatedVolt = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatRatedVolt_BMSH_TBOX_BatRatedVolt.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatRatedVolt_BMSH_TBOX_BatRatedVolt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_BatType_BMSH_TBOX_BatType = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatType_BMSH_TBOX_BatType.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_BatType_BMSH_TBOX_BatType = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_CellRatedVolt_BMSH_TBOX_CellRatedVolt = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_CellRatedVolt_BMSH_TBOX_CellRatedVolt.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellRatedVolt_BMSH_TBOX_CellRatedVolt = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_HWVer_BMSH_TBOX_HWVer = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_HWVer_BMSH_TBOX_HWVer.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_HWVer_BMSH_TBOX_HWVer = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_HWVer_Test_BMSH_TBOX_HWVer_Test = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_HWVer_Test_BMSH_TBOX_HWVer_Test.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_HWVer_Test_BMSH_TBOX_HWVer_Test = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_SWVer_BMSH_TBOX_SWVer = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_SWVer_BMSH_TBOX_SWVer.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_SWVer_BMSH_TBOX_SWVer = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_SWVer_Test_BMSH_TBOX_SWVer_Test = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_SWVer_Test_BMSH_TBOX_SWVer_Test.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_SWVer_Test_BMSH_TBOX_SWVer_Test = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TBOX_TheftFault_BMSH_TBOX_TheftFault = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_TheftFault_BMSH_TBOX_TheftFault.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TBOX_TheftFault_BMSH_TBOX_TheftFault = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TotalDischgCapacity_BMSH_TotalDischgCapacity = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalDischgCapacity_BMSH_TotalDischgCapacity.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalDischgCapacity_BMSH_TotalDischgCapacity = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TotalDischgEng_BMSH_TotalDischgEng = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalDischgEng_BMSH_TotalDischgEng.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalDischgEng_BMSH_TotalDischgEng = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TotalExChgCapacity_BMSH_TotalExChgCapacity = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalExChgCapacity_BMSH_TotalExChgCapacity.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalExChgCapacity_BMSH_TotalExChgCapacity = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TotalExChgEng_BMSH_TotalExChgEng = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalExChgEng_BMSH_TotalExChgEng.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalExChgEng_BMSH_TotalExChgEng = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TotalExChgSOE_BMSH_TotalExChgSOE = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalExChgSOE_BMSH_TotalExChgSOE.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalExChgSOE_BMSH_TotalExChgSOE = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TotalOdometer_BMSH_TotalOdometer = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalOdometer_BMSH_TotalOdometer.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalOdometer_BMSH_TotalOdometer = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TotalOdometerValidFlag_BMSH_TotalOdometerValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalOdometerValidFlag_BMSH_TotalOdometerValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalOdometerValidFlag_BMSH_TotalOdometerValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TotalRecoveryCapacity_BMSH_TotalRecoveryCapacity = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalRecoveryCapacity_BMSH_TotalRecoveryCapacity.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalRecoveryCapacity_BMSH_TotalRecoveryCapacity = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TotalRecoveryEng_BMSH_TotalRecoveryEng = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalRecoveryEng_BMSH_TotalRecoveryEng.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TotalRecoveryEng_BMSH_TotalRecoveryEng = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TripOdometer_BMSH_TripOdometer = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TripOdometer_BMSH_TripOdometer.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TripOdometer_BMSH_TripOdometer = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_TripOdometerValidFlag_BMSH_TripOdometerValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TripOdometerValidFlag_BMSH_TripOdometerValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_TripOdometerValidFlag_BMSH_TripOdometerValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCU_BatChgPeakPwr_BMSH_VCU_BatChgPeakPwr = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_BatChgPeakPwr_BMSH_VCU_BatChgPeakPwr.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_BatChgPeakPwr_BMSH_VCU_BatChgPeakPwr = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCU_BatDischgPeakPwr_BMSH_VCU_BatDischgPeakPwr = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_BatDischgPeakPwr_BMSH_VCU_BatDischgPeakPwr.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_BatDischgPeakPwr_BMSH_VCU_BatDischgPeakPwr = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCU_ChgSOPRangeUP_BMSH_VCU_ChgSOPRangeUP = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_ChgSOPRangeUP_BMSH_VCU_ChgSOPRangeUP.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_ChgSOPRangeUP_BMSH_VCU_ChgSOPRangeUP = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCU_ChgSOPValidFlag_BMSH_VCU_ChgSOPValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_ChgSOPValidFlag_BMSH_VCU_ChgSOPValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_ChgSOPValidFlag_BMSH_VCU_ChgSOPValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCU_DCChgNegTemp_BMSH_VCU_DCChgNegTemp = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_DCChgNegTemp_BMSH_VCU_DCChgNegTemp.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_DCChgNegTemp_BMSH_VCU_DCChgNegTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCU_DCChgPosTemp_BMSH_VCU_DCChgPosTemp = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_DCChgPosTemp_BMSH_VCU_DCChgPosTemp.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_DCChgPosTemp_BMSH_VCU_DCChgPosTemp = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMSH_VCU_DisChgSOPValidFlag_BMSH_VCU_DisChgSOPValidFlag = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_DisChgSOPValidFlag_BMSH_VCU_DisChgSOPValidFlag.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMSH_VCU_DisChgSOPValidFlag_BMSH_VCU_DisChgSOPValidFlag = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_VCU_ChrgFullCalRemind_BMS_VCU_ChrgFullCalRemind = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMS_VCU_ChrgFullCalRemind_BMS_VCU_ChrgFullCalRemind.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_VCU_ChrgFullCalRemind_BMS_VCU_ChrgFullCalRemind = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_VCU_ChrgModeAct_BMS_VCU_ChrgModeAct = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMS_VCU_ChrgModeAct_BMS_VCU_ChrgModeAct.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_VCU_ChrgModeAct_BMS_VCU_ChrgModeAct = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_VCU_ChrgModeCalRemind_BMS_VCU_ChrgModeCalRemind = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMS_VCU_ChrgModeCalRemind_BMS_VCU_ChrgModeCalRemind.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_VCU_ChrgModeCalRemind_BMS_VCU_ChrgModeCalRemind = RTE_COM_SENDSIGNALPROXY_SEND;


    Rte_swc_COL_BMS_VCU_ChrgModeEn_BMS_VCU_ChrgModeEn = *(&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMS_VCU_ChrgModeEn_BMS_VCU_ChrgModeEn.value);
    Rte_App1_Application_Core2_QM_TxUpdateFlags.Rte_TxUpdate_swc_COL_BMS_VCU_ChrgModeEn_BMS_VCU_ChrgModeEn = RTE_COM_SENDSIGNALPROXY_SEND;

    (void)TerminateTask();
}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
TASK(App1_Task0_UDS_Core2_QM)
{
    EventMaskType ev = 0U;
    for(;;)
    {
        (void)WaitEvent(APP1_EVENT0_UDS_CORE2_QM
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0501_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0502_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0503_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0504_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0505_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0507_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X050A_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0525_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0526_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0527_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0528_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0529_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X052B_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X052D_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X052E_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0530_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0531_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0532_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0533_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0534_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0535_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0536_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0537_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0538_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0539_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X053B_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X053C_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X053D_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X053E_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0542_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0543_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0544_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0545_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0547_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0552_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X055A_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X055C_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X055D_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0585_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0586_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0587_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0588_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0589_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X03E2_START_SERVICES
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X03E2_STOP_SERVICES
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X4000_START_SERVICES
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X400F_START_SERVICES
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X4F02_START_SERVICES
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X4F03_START_SERVICES
                        | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X4F04_START_SERVICES);
        (void)GetEvent(APP1_TASK0_UDS_CORE2_QM, &ev);
        (void)ClearEvent(ev & (APP1_EVENT0_UDS_CORE2_QM
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0501_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0502_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0503_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0504_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0505_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0507_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X050A_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0525_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0526_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0527_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0528_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0529_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X052B_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X052D_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X052E_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0530_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0531_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0532_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0533_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0534_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0535_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0536_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0537_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0538_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0539_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X053B_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X053C_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X053D_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X053E_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0542_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0543_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0544_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0545_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0547_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0552_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X055A_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X055C_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X055D_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0585_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0586_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0587_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0588_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0589_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X03E2_START_SERVICES
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X03E2_STOP_SERVICES
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X4000_START_SERVICES
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X400F_START_SERVICES
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X4F02_START_SERVICES
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X4F03_START_SERVICES
                         | RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X4F04_START_SERVICES));
		

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0501_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0501_22_RE.Rte_BCF_IDchaLimMap_BCF_IDchaLimMap.value) = Rte_swc_BatCoreFct_BCF_IDchaLimMap_BCF_IDchaLimMap;
            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0501_22_RE.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value) = Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0501_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0502_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0502_22_RE.Rte_BCF_IChLimMap_BCF_IChLimMap.value) = Rte_swc_BatCoreFct_BCF_IChLimMap_BCF_IChLimMap;
            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0502_22_RE.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value) = Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0502_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0503_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0503_22_RE.Rte_BCF_IDchaLim_BCF_IDchaLim.value) = Rte_swc_BatCoreFct_BCF_IDchaLim_BCF_IDchaLim;
            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0503_22_RE.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value) = Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0503_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0504_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0504_22_RE.Rte_BCF_IChLim_BCF_IChLim.value) = Rte_swc_BatCoreFct_BCF_IChLim_BCF_IChLim;
            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0504_22_RE.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value) = Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0504_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0505_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0505_22_RE.Rte_BMSH_StsMode_BMSH_StsMode.value) = Rte_swc_COL_BMSH_StsMode_BMSH_StsMode;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0505_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0507_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData_Type));
            }
            #endif

            Rte_MemCpy(Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0507_22_RE.Rte_BMC_UCell_BMC_UCell.value, Rte_swc_CIL_BMC_UCell_BMC_UCell, sizeof(rt_Array_Float_255));
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0507_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X050A_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData_Type));
            }
            #endif

            Rte_MemCpy(Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x050A_22_RE.Rte_CIL_TMdul_CIL_TMdul.value, Rte_swc_CIL_CIL_TMdul_CIL_TMdul, sizeof(rt_Array_Float_54));
            #if 0
            SWC_TestDCM_DataServices_DspData_0x050A_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0525_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0525_22_RE.Rte_BCF_SohPack_BCF_SohPack.value) = Rte_swc_BatCoreFct_BCF_SohPack_BCF_SohPack;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0525_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0526_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0526_22_RE.Rte_BPIU_UCellMax_BPIU_UCellMax.value) = Rte_swc_BatProtnIU_BPIU_UCellMax_BPIU_UCellMax;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0526_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0527_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0527_22_RE.Rte_BPIU_IdCellUMax_BPIU_IdCellUMax.value) = Rte_swc_BatProtnIU_BPIU_IdCellUMax_BPIU_IdCellUMax;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0527_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0528_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0528_22_RE.Rte_BPIU_UCellMin_BPIU_UCellMin.value) = Rte_swc_BatProtnIU_BPIU_UCellMin_BPIU_UCellMin;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0528_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0529_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0529_22_RE.Rte_BPIU_IdCellUMin_BPIU_IdCellUMin.value) = Rte_swc_BatProtnIU_BPIU_IdCellUMin_BPIU_IdCellUMin;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0529_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X052B_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052B_22_RE.Rte_BTHM_IdCellTMax_BTHM_IdCellTMax.value) = Rte_swc_BatThermHndlgMngt_BTHM_IdCellTMax_BTHM_IdCellTMax;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x052B_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X052D_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052D_22_RE.Rte_BTHM_IdCellTMin_BTHM_IdCellTMin.value) = Rte_swc_BatThermHndlgMngt_BTHM_IdCellTMin_BTHM_IdCellTMin;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x052D_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X052E_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052E_22_RE.Rte_BCF_SocPackScld_BCF_SocPackScld.value) = Rte_swc_BatCoreFct_BCF_SocPackScld_BCF_SocPackScld;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x052E_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0530_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0530_22_RE.Rte_BTHM_TPack_BTHM_TPack.value) = Rte_swc_BatThermHndlgMngt_BTHM_TPack_BTHM_TPack;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0530_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0531_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0531_22_RE.Rte_CIL_TDcChPointPos_CIL_TDcChPointPos.value) = Rte_swc_CIL_CIL_TDcChPointPos_CIL_TDcChPointPos;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0531_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0532_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0532_22_RE.Rte_CIL_TDcChPointNeg_CIL_TDcChPointNeg.value) = Rte_swc_CIL_CIL_TDcChPointNeg_CIL_TDcChPointNeg;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0532_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0533_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0533_22_RE.Rte_CIL_TAcChPointPos_CIL_TAcChPointPos.value) = Rte_swc_CIL_CIL_TAcChPointPos_CIL_TAcChPointPos;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0533_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0534_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0534_22_RE.Rte_CIL_TAcChPointNeg_CIL_TAcChPointNeg.value) = Rte_swc_CIL_CIL_TAcChPointNeg_CIL_TAcChPointNeg;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0534_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0535_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0535_22_RE.Rte_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr.value) = Rte_swc_CIL_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0535_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0536_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0536_22_RE.Rte_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr.value) = Rte_swc_CIL_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0536_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0537_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData_Type));
            }

            SWC_TestDCM_DataServices_DspData_0x0537_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0538_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0538_22_RE.Rte_CTC_StRlyNeg_CTC_StRlyNeg.value) = Rte_swc_CtctrTranCtl_CTC_StRlyNeg_CTC_StRlyNeg;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0538_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0539_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0539_22_RE.Rte_CTC_StRlyHeat_CTC_StRlyHeat.value) = Rte_swc_CtctrTranCtl_CTC_StRlyHeat_CTC_StRlyHeat;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0539_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X053B_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053B_22_RE.Rte_ELHPN_RIslnPos_ELHPN_RIslnPos.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnPos_ELHPN_RIslnPos;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x053B_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X053C_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053C_22_RE.Rte_ELHPN_RIslnNeg_ELHPN_RIslnNeg.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnNeg_ELHPN_RIslnNeg;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x053C_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X053D_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053D_22_RE.Rte_BWLD_EBatDchaTot_BWLD_EBatDchaTot.value) = Rte_swc_BatWntyLogtcData_BWLD_EBatDchaTot_BWLD_EBatDchaTot;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x053D_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X053E_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053E_22_RE.Rte_BWLD_EBatChTot_BWLD_EBatChTot.value) = Rte_swc_BatWntyLogtcData_BWLD_EBatChTot_BWLD_EBatChTot;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x053E_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0542_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0542_22_RE.Rte_BCC_StCh_BCC_StCh.value) = Rte_swc_BatChCtl_BCC_StCh_BCC_StCh;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0542_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0543_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData_Type));
            }

            SWC_TestDCM_DataServices_DspData_0x0543_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0544_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0544_22_RE.Rte_BCC_UObcLimn_BCC_UObcLimn.value) = Rte_swc_BatChCtl_BCC_UObcLimn_BCC_UObcLimn;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0544_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0545_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0545_22_RE.Rte_BCC_IObcLimn_BCC_IObcLimn.value) = Rte_swc_BatChCtl_BCC_IObcLimn_BCC_IObcLimn;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0545_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0547_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0547_22_RE.Rte_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot.value) = Rte_swc_BatChCtl_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0547_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0552_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData_Type));
            }

            SWC_TestDCM_DataServices_DspData_0x0552_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X055A_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x055A_22_RE.Rte_BCF_IDchaLim_BCF_IDchaLim.value) = Rte_swc_BatCoreFct_BCF_IDchaLim_BCF_IDchaLim;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x055A_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X055C_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x055C_22_RE.Rte_BCF_IChLim_BCF_IChLim.value) = Rte_swc_BatCoreFct_BCF_IChLim_BCF_IChLim;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x055C_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X055D_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x055D_22_RE.Rte_BCF_SocLimMin_BCF_SocLimMin.value) = Rte_swc_BatCoreFct_BCF_SocLimMin_BCF_SocLimMin;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x055D_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0585_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0585_22_RE.Rte_CTC_StRlyPos_CTC_StRlyPos.value) = Rte_swc_CtctrTranCtl_CTC_StRlyPos_CTC_StRlyPos;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0585_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0586_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0586_22_RE.Rte_CTC_StRlyCh_CTC_StRlyCh.value) = Rte_swc_CtctrTranCtl_CTC_StRlyCh_CTC_StRlyCh;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0586_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0587_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0587_22_RE.Rte_CTC_StRlyPrech_CTC_StRlyPrech.value) = Rte_swc_CtctrTranCtl_CTC_StRlyPrech_CTC_StRlyPrech;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0587_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0588_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0588_22_RE.Rte_BWLD_CtrCh_BWLD_CtrCh.value) = Rte_swc_BatWntyLogtcData_BWLD_CtrCh_BWLD_CtrCh;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0588_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0589_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0589_22_RE.Rte_BWLD_CtrDcha_BWLD_CtrDcha.value) = Rte_swc_BatWntyLogtcData_BWLD_CtrDcha_BWLD_CtrDcha;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0589_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }


        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X03E2_START_SERVICES) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start_Type));
            }

            RoutineServices_0x03E2_Start_Services( cs_Server.DataIn, cs_Server.OpStatus, &cs_Server.DataOut, &cs_Server.ErrorCode);
            #endif
            Rte_swc_DiagcEveHndlg_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag = *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start_Services.Rte_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag.value);


            #if 0
            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X03E2_STOP_SERVICES) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop_Type));
            }

            RoutineServices_0x03E2_Stop_Services( cs_Server.DataIn, cs_Server.OpStatus, &cs_Server.DataOut, &cs_Server.ErrorCode);
            #endif
            Rte_swc_DiagcEveHndlg_DEH_CtrHvOffReqDiag_DEH_CtrHvOffReqDiag = *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop_Services.Rte_DEH_CtrHvOffReqDiag_DEH_CtrHvOffReqDiag.value);


            #if 0
            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X4000_START_SERVICES) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4000_Start);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Type));
            }

            RoutineServices_0x4000_Start_Services( cs_Server.DataIn, cs_Server.OpStatus, &cs_Server.DataOut, &cs_Server.ErrorCode);
            #endif
            Rte_swc_DiagcEveHndlg_DEH_ReqRlyCh_DEH_ReqRlyCh = *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Services.Rte_DEH_ReqRlyCh_DEH_ReqRlyCh.value);


            #if 0
            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4000_Start);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4000_Start.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X400F_START_SERVICES) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x400F_Start);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Type));
            }

            RoutineServices_0x400F_Start_Services( cs_Server.DataIn, cs_Server.OpStatus, &cs_Server.DataOut, &cs_Server.ErrorCode);
            #endif
            Rte_swc_DiagcEveHndlg_DEH_CtrIslnMeasReqDiag_DEH_CtrIslnMeasReqDiag = *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Services.Rte_DEH_CtrIslnMeasReqDiag_DEH_CtrIslnMeasReqDiag.value);
            Rte_swc_DiagcEveHndlg_DEH_StIslnMeasReq_DEH_StIslnMeasReq = *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Services.Rte_DEH_StIslnMeasReq_DEH_StIslnMeasReq.value);


            #if 0
            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x400F_Start);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x400F_Start.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X4F02_START_SERVICES) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Type));
            }

            RoutineServices_0x4F02_Start_Services( cs_Server.DataIn, cs_Server.OpStatus, &cs_Server.DataOut, &cs_Server.ErrorCode);
            #endif
            Rte_swc_DiagcEveHndlg_DEH_ReqRlyPos_DEH_ReqRlyPos = *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Services.Rte_DEH_ReqRlyPos_DEH_ReqRlyPos.value);


            #if 0
            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X4F03_START_SERVICES) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Type));
            }

            RoutineServices_0x4F03_Start_Services( cs_Server.DataIn, cs_Server.OpStatus, &cs_Server.DataOut, &cs_Server.ErrorCode);
            #endif
            Rte_swc_DiagcEveHndlg_DEH_ReqRlyNeg_DEH_ReqRlyNeg = *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Services.Rte_DEH_ReqRlyNeg_DEH_ReqRlyNeg.value);


            #if 0
            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X4F04_START_SERVICES) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Type));
            }

            RoutineServices_0x4F04_Start_Services( cs_Server.DataIn, cs_Server.OpStatus, &cs_Server.DataOut, &cs_Server.ErrorCode);
            #endif
            Rte_swc_DiagcEveHndlg_DEH_ReqRlyPrech_DEH_ReqRlyPrech = *(&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Services.Rte_DEH_ReqRlyPrech_DEH_ReqRlyPrech.value);


            #if 0
            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start.Rte_ServerCompleted = TRUE;
            #endif
        }

    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
TASK(App1_Task1_UDS_Core2_QM)
{
    EventMaskType ev = 0U;
    for(;;)
    {
        (void)WaitEvent(APP1_EVENT1_UDS_CORE2_QM
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058B_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058C_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058D_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058E_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058F_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0590_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0591_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0592_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0593_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0594_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0595_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0596_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0597_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0598_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0599_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059A_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059B_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059C_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059D_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059E_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059F_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A1_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A2_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A3_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A4_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A5_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A6_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A7_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A8_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A9_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AA_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AB_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AC_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AD_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AE_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AF_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B0_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B1_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B2_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B3_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B4_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B5_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B6_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B7_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B8_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B9_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BA_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BB_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BC_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BD_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BE_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BF_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C0_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C1_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C2_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C3_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C4_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C5_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C6_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C7_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C8_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C9_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CA_22_RE);
        (void)GetEvent(APP1_TASK1_UDS_CORE2_QM, &ev);
        (void)ClearEvent(ev & (APP1_EVENT1_UDS_CORE2_QM
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058B_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058C_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058D_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058E_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058F_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0590_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0591_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0592_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0593_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0594_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0595_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0596_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0597_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0598_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0599_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059A_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059B_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059C_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059D_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059E_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059F_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A1_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A2_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A3_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A4_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A5_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A6_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A7_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A8_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A9_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AA_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AB_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AC_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AD_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AE_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AF_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B0_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B1_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B2_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B3_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B4_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B5_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B6_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B7_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B8_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B9_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BA_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BB_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BC_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BD_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BE_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BF_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C0_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C1_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C2_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C3_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C4_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C5_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C6_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C7_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C8_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C9_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CA_22_RE));

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058B_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058B_22_RE.Rte_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x058B_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058C_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058C_22_RE.Rte_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv.value) = Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x058C_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058D_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058D_22_RE.Rte_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv.value) = Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x058D_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058E_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058E_22_RE.Rte_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv.value) = Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x058E_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058F_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058F_22_RE.Rte_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv.value) = Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x058F_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0590_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0590_22_RE.Rte_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv.value) = Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0590_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0591_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0591_22_RE.Rte_BWLD_TiBatAgi_BWLD_TiBatAgi.value) = Rte_swc_BatWntyLogtcData_BWLD_TiBatAgi_BWLD_TiBatAgi;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0591_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0592_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0592_22_RE.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value) = Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0592_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0593_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData_Type));
            }
            #endif

            Rte_MemCpy(Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0593_22_RE.Rte_BCF_UMdul_BCF_UMdul.value, Rte_swc_BatCoreFct_BCF_UMdul_BCF_UMdul, sizeof(rt_Array_Float_24));
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0593_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0594_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0594_22_RE.Rte_BBC_bAcvBaln_BBC_bAcvBaln.value) = Rte_swc_BatBalnCtl_BBC_bAcvBaln_BBC_bAcvBaln;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0594_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0595_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0595_22_RE.Rte_ELHPN_StIsln_ELHPN_StIsln.value) = Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StIsln_ELHPN_StIsln;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0595_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0596_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0596_22_RE.Rte_CIL_TBd_CIL_TBd.value) = Rte_swc_CIL_CIL_TBd_CIL_TBd;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0596_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0597_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0597_22_RE.Rte_CTC_IDriftZero_CTC_IDriftZero.value) = Rte_swc_CtctrTranCtl_CTC_IDriftZero_CTC_IDriftZero;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0597_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0598_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0598_22_RE.Rte_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly.value) = Rte_swc_CIL_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0598_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0599_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0599_22_RE.Rte_CIL_UMainNegPoleAftRly_CIL_UMainNegPoleAftRly.value) = Rte_swc_CIL_CIL_UMainNegPoleAftRly_CIL_UMainNegPoleAftRly;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x0599_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059A_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059A_22_RE.Rte_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat.value) = Rte_swc_CIL_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x059A_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059B_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059B_22_RE.Rte_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh.value) = Rte_swc_CIL_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x059B_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059C_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059C_22_RE.Rte_BMSH_DCChargeProcess_BMSH_DCChargeProcess.value) = Rte_swc_COL_BMSH_DCChargeProcess_BMSH_DCChargeProcess;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x059C_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059D_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059D_22_RE.Rte_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason.value) = Rte_swc_COL_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason;
            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059D_22_RE.Rte_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason.value) = Rte_swc_COL_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason;
            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059D_22_RE.Rte_BMS_BMSStopChgReason_BMS_BMSStopChgReason.value) = Rte_swc_COL_BMS_BMSStopChgReason_BMS_BMSStopChgReason;
            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059D_22_RE.Rte_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason.value) = Rte_swc_COL_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason;
            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059D_22_RE.Rte_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason.value) = Rte_swc_COL_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason;
            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059D_22_RE.Rte_BMS_CCUStopChgReason_BMS_CCUStopChgReason.value) = Rte_swc_COL_BMS_CCUStopChgReason_BMS_CCUStopChgReason;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x059D_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059E_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059E_22_RE.Rte_CIL_TDcChPointNeg_CIL_TDcChPointNeg.value) = Rte_swc_CIL_CIL_TDcChPointNeg_CIL_TDcChPointNeg;
            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059E_22_RE.Rte_CIL_TDcChPointPos_CIL_TDcChPointPos.value) = Rte_swc_CIL_CIL_TDcChPointPos_CIL_TDcChPointPos;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x059E_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059F_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059F_22_RE.Rte_EVCSH_IChrgrSp_EVCSH_IChrgrSp.value) = Rte_swc_BatChCtl_EVCSH_IChrgrSp_EVCSH_IChrgrSp;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x059F_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A1_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A1_22_RE.Rte_BCF_SocPack_BCF_SocPack.value) = Rte_swc_BatCoreFct_BCF_SocPack_BCF_SocPack;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05A1_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A2_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A2_22_RE.Rte_BWLD_PBatChMax_BWLD_PBatChMax.value) = Rte_swc_BatWntyLogtcData_BWLD_PBatChMax_BWLD_PBatChMax;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05A2_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A3_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A3_22_RE.Rte_BWLD_PBatDchaMax_BWLD_PBatDchaMax.value) = Rte_swc_BatWntyLogtcData_BWLD_PBatDchaMax_BWLD_PBatDchaMax;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05A3_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A4_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A4_22_RE.Rte_BWLD_IBatChMax_BWLD_IBatChMax.value) = Rte_swc_BatWntyLogtcData_BWLD_IBatChMax_BWLD_IBatChMax;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05A4_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A5_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A5_22_RE.Rte_BWLD_IBatDchaMax_BWLD_IBatDchaMax.value) = Rte_swc_BatWntyLogtcData_BWLD_IBatDchaMax_BWLD_IBatDchaMax;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05A5_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A6_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A6_22_RE.Rte_BWLD_UBatCtctrOpenMin_BWLD_UBatCtctrOpenMin.value) = Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMin_BWLD_UBatCtctrOpenMin;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05A6_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A7_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A7_22_RE.Rte_BWLD_UBatCtctrOpenMax_BWLD_UBatCtctrOpenMax.value) = Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMax_BWLD_UBatCtctrOpenMax;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05A7_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A8_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A8_22_RE.Rte_BWLD_UBatCtctrClsdMin_BWLD_UBatCtctrClsdMin.value) = Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMin_BWLD_UBatCtctrClsdMin;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05A8_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A9_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A9_22_RE.Rte_BWLD_UBatCtctrClsdMax_BWLD_UBatCtctrClsdMax.value) = Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMax_BWLD_UBatCtctrClsdMax;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05A9_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AA_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AA_22_RE.Rte_BWLD_SocBatMin_BWLD_SocBatMin.value) = Rte_swc_BatWntyLogtcData_BWLD_SocBatMin_BWLD_SocBatMin;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05AA_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AB_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AB_22_RE.Rte_BWLD_SocBatMax_BWLD_SocBatMax.value) = Rte_swc_BatWntyLogtcData_BWLD_SocBatMax_BWLD_SocBatMax;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05AB_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AC_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AC_22_RE.Rte_BWLD_UCellMin_BWLD_UCellMin.value) = Rte_swc_BatWntyLogtcData_BWLD_UCellMin_BWLD_UCellMin;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05AC_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AD_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AD_22_RE.Rte_BWLD_UCellMax_BWLD_UCellMax.value) = Rte_swc_BatWntyLogtcData_BWLD_UCellMax_BWLD_UCellMax;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05AD_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AE_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AE_22_RE.Rte_BWLD_TMdulSnsrMin_BWLD_TMdulSnsrMin.value) = Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMin_BWLD_TMdulSnsrMin;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05AE_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AF_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AF_22_RE.Rte_BWLD_TMdulSnsrMax_BWLD_TMdulSnsrMax.value) = Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMax_BWLD_TMdulSnsrMax;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05AF_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B0_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData_Type));
            }
            #endif

            Rte_MemCpy(Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B0_22_RE.Rte_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv.value, Rte_swc_BatCoreFct_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv, sizeof(rt_Array_Float_24));
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05B0_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B1_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData_Type));
            }
            #endif

            Rte_MemCpy(Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B1_22_RE.Rte_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv.value, Rte_swc_BatCoreFct_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv, sizeof(rt_Array_Float_24));
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05B1_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B2_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData_Type));
            }
            #endif

            Rte_MemCpy(Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B2_22_RE.Rte_BCF_StAryFlsNv_BCF_StAryFlsNv.value, Rte_swc_BatCoreFct_BCF_StAryFlsNv_BCF_StAryFlsNv, sizeof(rt_Array_Float_144));
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05B2_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B3_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B3_22_RE.Rte_CTC_ReqRlyCh_CTC_ReqRlyCh.value) = Rte_swc_CtctrTranCtl_CTC_ReqRlyCh_CTC_ReqRlyCh;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05B3_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B4_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B4_22_RE.Rte_CTC_ReqRlyNeg_CTC_ReqRlyNeg.value) = Rte_swc_CtctrTranCtl_CTC_ReqRlyNeg_CTC_ReqRlyNeg;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05B4_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B5_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B5_22_RE.Rte_CTC_ReqRlyPos_CTC_ReqRlyPos.value) = Rte_swc_CtctrTranCtl_CTC_ReqRlyPos_CTC_ReqRlyPos;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05B5_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B6_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B6_22_RE.Rte_CTC_ReqRlyPrech_CTC_ReqRlyPrech.value) = Rte_swc_CtctrTranCtl_CTC_ReqRlyPrech_CTC_ReqRlyPrech;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05B6_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B7_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B7_22_RE.Rte_CTC_ReqRlyHeat_CTC_ReqRlyHeat.value) = Rte_swc_CtctrTranCtl_CTC_ReqRlyHeat_CTC_ReqRlyHeat;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05B7_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B8_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B8_22_RE.Rte_CIL_StBatHvReq_CIL_StBatHvReq.value) = Rte_swc_CIL_CIL_StBatHvReq_CIL_StBatHvReq;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05B8_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B9_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B9_22_RE.Rte_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg.value) = Rte_swc_CIL_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05B9_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BA_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BA_22_RE.Rte_CIL_StCellTSamplgExcpn_CIL_StCellTSamplgExcpn.value) = Rte_swc_CIL_CIL_StCellTSamplgExcpn_CIL_StCellTSamplgExcpn;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05BA_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BB_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BB_22_RE.Rte_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg.value) = Rte_swc_CIL_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05BB_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BC_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BC_22_RE.Rte_CIL_StCellUSamplgExcpn_CIL_StCellUSamplgExcpn.value) = Rte_swc_CIL_CIL_StCellUSamplgExcpn_CIL_StCellUSamplgExcpn;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05BC_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BD_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BD_22_RE.Rte_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly.value) = Rte_swc_CIL_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05BD_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BE_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BE_22_RE.Rte_CIL_bVldBatIHv_CIL_bVldBatIHv.value) = Rte_swc_CIL_CIL_bVldBatIHv_CIL_bVldBatIHv;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05BE_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BF_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BF_22_RE.Rte_CIL_bVldIslnR_CIL_bVldIslnR.value) = Rte_swc_CIL_CIL_bVldIslnR_CIL_bVldIslnR;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05BF_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C0_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C0_22_RE.Rte_CIL_bVldUPoleAftRlyCh_CIL_bVldUPoleAftRlyCh.value) = Rte_swc_CIL_CIL_bVldUPoleAftRlyCh_CIL_bVldUPoleAftRlyCh;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05C0_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C1_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C1_22_RE.Rte_CIL_bVldUPoleAftRlyHeat_CIL_bVldUPoleAftRlyHeat.value) = Rte_swc_CIL_CIL_bVldUPoleAftRlyHeat_CIL_bVldUPoleAftRlyHeat;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05C1_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C2_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C2_22_RE.Rte_CIL_bVldUMainPosPoleAftRly_CIL_bVldUMainPosPoleAftRly.value) = Rte_swc_CIL_CIL_bVldUMainPosPoleAftRly_CIL_bVldUMainPosPoleAftRly;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05C2_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C3_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C3_22_RE.Rte_CIL_bVldUMainNegPoleAftRly_CIL_bVldUMainNegPoleAftRly.value) = Rte_swc_CIL_CIL_bVldUMainNegPoleAftRly_CIL_bVldUMainNegPoleAftRly;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05C3_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C4_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C4_22_RE.Rte_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv.value) = Rte_swc_CIL_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05C4_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C5_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C5_22_RE.Rte_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv.value) = Rte_swc_CIL_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05C5_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C6_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C6_22_RE.Rte_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv.value) = Rte_swc_CIL_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05C6_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C7_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C7_22_RE.Rte_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv.value) = Rte_swc_CIL_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05C7_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C8_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C8_22_RE.Rte_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv.value) = Rte_swc_CIL_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05C8_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C9_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C9_22_RE.Rte_EVCSH_UChrgrSp_EVCSH_UChrgrSp.value) = Rte_swc_BatChCtl_EVCSH_UChrgrSp_EVCSH_UChrgrSp;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05C9_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CA_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CA_22_RE.Rte_CIL_RDcChrgrPlg_CIL_RDcChrgrPlg.value) = Rte_swc_CIL_CIL_RDcChrgrPlg_CIL_RDcChrgrPlg;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05CA_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
TASK(App1_Task2_UDS_Core2_QM)
{
    EventMaskType ev = 0U;
    for(;;)
    {
        (void)WaitEvent(APP1_EVENT2_UDS_CORE2_QM
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CC_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CD_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CE_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CF_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D0_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D1_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D2_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D3_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D4_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XCF00_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XCF05_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XCF06_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XCF07_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDD00_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF00_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF01_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF02_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF03_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF04_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF06_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF09_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058A_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CB_22_RE);
        (void)GetEvent(APP1_TASK2_UDS_CORE2_QM, &ev);
        (void)ClearEvent(ev & (APP1_EVENT2_UDS_CORE2_QM
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CC_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CD_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CE_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CF_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D0_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D1_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D2_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D3_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D4_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XCF00_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XCF05_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XCF06_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XCF07_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDD00_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF00_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF01_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF02_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF03_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF04_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF06_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF09_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058A_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CB_22_RE));

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CC_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CC_22_RE.Rte_BCF_UCellAvg_BCF_UCellAvg.value) = Rte_swc_BatCoreFct_BCF_UCellAvg_BCF_UCellAvg;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05CC_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CD_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CD_22_RE.Rte_CIL_TAcChPointPos_CIL_TAcChPointPos.value) = Rte_swc_CIL_CIL_TAcChPointPos_CIL_TAcChPointPos;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05CD_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CE_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CE_22_RE.Rte_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly.value) = Rte_swc_CIL_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05CE_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CF_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CF_22_RE.Rte_CTC_StLoopHv_CTC_StLoopHv.value) = Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05CF_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D0_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05D0_22_RE.Rte_CTC_StRlyCh_CTC_StRlyCh.value) = Rte_swc_CtctrTranCtl_CTC_StRlyCh_CTC_StRlyCh;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05D0_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D1_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05D1_22_RE.Rte_CIL_TBd_CIL_TBd.value) = Rte_swc_CIL_CIL_TBd_CIL_TBd;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05D1_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D2_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData_Type));
            }

            SWC_TestDCM_DataServices_DspData_0x05D2_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D3_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData_Type));
            }

            SWC_TestDCM_DataServices_DspData_0x05D3_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D4_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData_Type));
            }

            SWC_TestDCM_DataServices_DspData_0x05D4_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XCF00_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF00_22_RE.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value) = Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt;
            #if 0
            SWC_TestDCM_DataServices_DspData_0xCF00_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XCF05_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF05_22_RE.Rte_CIL_IBatHv_CIL_IBatHv.value) = Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
            #if 0
            SWC_TestDCM_DataServices_DspData_0xCF05_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XCF06_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF06_22_RE.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
            #if 0
            SWC_TestDCM_DataServices_DspData_0xCF06_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XCF07_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF07_22_RE.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value) = Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
            #if 0
            SWC_TestDCM_DataServices_DspData_0xCF07_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDD00_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE.Rte_CIL_DayTelbox_CIL_DayTelbox.value) = Rte_swc_CIL_CIL_DayTelbox_CIL_DayTelbox;
            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE.Rte_CIL_HourTelbox_CIL_HourTelbox.value) = Rte_swc_CIL_CIL_HourTelbox_CIL_HourTelbox;
            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE.Rte_CIL_MinuTelbox_CIL_MinuTelbox.value) = Rte_swc_CIL_CIL_MinuTelbox_CIL_MinuTelbox;
            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE.Rte_CIL_MonthTelbox_CIL_MonthTelbox.value) = Rte_swc_CIL_CIL_MonthTelbox_CIL_MonthTelbox;
            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE.Rte_CIL_SecTelbox_CIL_SecTelbox.value) = Rte_swc_CIL_CIL_SecTelbox_CIL_SecTelbox;
            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE.Rte_CIL_YearTelbox_CIL_YearTelbox.value) = Rte_swc_CIL_CIL_YearTelbox_CIL_YearTelbox;
            #if 0
            SWC_TestDCM_DataServices_DspData_0xDD00_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF00_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF00_22_RE.Rte_CIL_UTrml30_CIL_UTrml30.value) = Rte_swc_CIL_CIL_UTrml30_CIL_UTrml30;
            #if 0
            SWC_TestDCM_DataServices_DspData_0xDF00_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF01_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF01_22_RE.Rte_CIL_SpdVeh_CIL_SpdVeh.value) = Rte_swc_CIL_CIL_SpdVeh_CIL_SpdVeh;
            #if 0
            SWC_TestDCM_DataServices_DspData_0xDF01_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF02_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData_Type));
            }

            SWC_TestDCM_DataServices_DspData_0xDF02_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF03_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF03_22_RE.Rte_CIL_MilgTot_CIL_MilgTot.value) = Rte_swc_CIL_CIL_MilgTot_CIL_MilgTot;
            #if 0
            SWC_TestDCM_DataServices_DspData_0xDF03_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF04_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF04_22_RE.Rte_CIL_MilgTot_CIL_MilgTot.value) = Rte_swc_CIL_CIL_MilgTot_CIL_MilgTot;
            #if 0
            SWC_TestDCM_DataServices_DspData_0xDF04_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF06_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF06_22_RE.Rte_CIL_PowerMode_CIL_PowerMode.value) = Rte_swc_CIL_CIL_PowerMode_CIL_PowerMode;
            #if 0
            SWC_TestDCM_DataServices_DspData_0xDF06_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF09_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF09_22_RE.Rte_BCF_SocPackScld_BCF_SocPackScld.value) = Rte_swc_BatCoreFct_BCF_SocPackScld_BCF_SocPackScld;
            #if 0
            SWC_TestDCM_DataServices_DspData_0xDF09_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058A_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058A_22_RE.Rte_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax.value) = Rte_swc_BatWntyLogtcData_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x058A_22_RE( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CB_22_RE) != (EventMaskType)0)
        {
            #if 0
            Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData_Type));
            }
            #endif

            *(&Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CB_22_RE.Rte_EVCSH_ChMode_EVCSH_ChMode.value) = Rte_swc_BatChCtl_EVCSH_ChMode_EVCSH_ChMode;
            #if 0
            SWC_TestDCM_DataServices_DspData_0x05CB_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData_Type));
            }

            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData.Rte_ServerCompleted = TRUE;
            #endif
        }

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


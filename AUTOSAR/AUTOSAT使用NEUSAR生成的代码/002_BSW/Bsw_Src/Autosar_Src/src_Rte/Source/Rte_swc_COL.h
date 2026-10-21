 
/*
************************************************************************************************************************
*
* File name: Rte_swc_COL.h
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
#ifndef RTE_SWC_COL_H_
#define RTE_SWC_COL_H_

#include "Rte_swc_COL_Type.h"
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
*    extern declaration of RTE buffers
************************************************************************************************************************
*/

#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_B2V_SingleChgEnergy_B2V_SingleChgEnergy;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCSP_Remaining_range_BCSP_Remaining_range;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BCSP_reserved_BCSP_reserved;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BDC_Battery_capacity_BDC_Battery_capacity;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BDC_Battery_energy_BDC_Battery_energy;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Soc_BDC_Soc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CRO00_BMSH_DCChgRx_OTime_CRO00;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CROAA_BMSH_DCChgRx_OTime_CROAA;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BMSStopChgReason_BMS_BMSStopChgReason;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CCUStopChgReason_BMS_CCUStopChgReason;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BSWControl_RstDiagGlb_RstDiagGlb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Mode_Request_shutdown_Request_shutdown;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCL_Request_BCL;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCP_Request_BCP;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCPP_Request_BCPP;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCS_Request_BCS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCSP_Request_BCSP;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BDC_Request_BDC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BEM_Request_BEM;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BHM_Request_BHM;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BMS_FastChgStopInfo_Request_BMS_FastChgStopInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BMT_Request_BMT;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BMV_Request_BMV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BRM_Request_BRM;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BRO_Request_BRO;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BSD_Request_BSD;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BSM_Request_BSM;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BSP_Request_BSP;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BST_Request_BST;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryChargingOvercurrent_BatteryChargingOvercurrent;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryExcessTemperature_BatteryExcessTemperature;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryHighestTemp_BatteryHighestTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryHighestTempSerNo_BatteryHighestTempSerNo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryInsulationState_BatteryInsulationState;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryLowestTemp_BatteryLowestTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryLowestTempSerNo_BatteryLowestTempSerNo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryOutputConnectorState_BatteryOutputConnectorState;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BatterySystemCapacity_BatterySystemCapacity;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BatterySystemVoltage_BatterySystemVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryType_BatteryType;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsReadyForCharging_BmsReadyForCharging;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsRevision_BmsRevision;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspCause_SOC_BmsSuspCause_SOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_Insulation_BmsSuspFault_Insulation;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BmsVersion_BmsVersion;
extern VAR(rt_Array_UInt32_9, RTE_VAR_INIT) Rte_swc_COL_BmuControl_BalanceControl_BalanceControl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BsmChargingPermissible_BsmChargingPermissible;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_ChargingMode_ChargingMode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_CurrentChargeState_CurrentChargeState;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_CurrentDemand_CurrentDemand;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_IOFS_NegRlyCtr_IOFS_NegRlyCtr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_IOFS_PosRlyCtr_IOFS_PosRlyCtr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_IOFS_PreChgRlyCtr_IOFS_PreChgRlyCtr;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MaxChargingVoltage_MaxChargingVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MaxPermChargingCurrent_MaxPermChargingCurrent;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_MaxPermTemperature_MaxPermTemperature;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MeasuredChargingCurrent_MeasuredChargingCurrent;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MeasuredChargingVoltage_MeasuredChargingVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryMinTemperature_SingleBatteryMinTemperature;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryMinVoltage_SingleBatteryMinVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CCS_Timeout_CCS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CRM_Recognized_Timeout_CRM_Recognized;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CRO_Timeout_CRO;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CSD_Timeout_CSD;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CST_Timeout_CST;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CTS_CML_Timeout_CTS_CML;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_TotalNominalEnergy_TotalNominalEnergy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_1_VIN_Copy_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_10_VIN_Copy_10;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_11_VIN_Copy_11;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_12_VIN_Copy_12;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_13_VIN_Copy_13;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_14_VIN_Copy_14;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_15_VIN_Copy_15;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_16_VIN_Copy_16;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_17_VIN_Copy_17;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_2_VIN_Copy_2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_3_VIN_Copy_3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_4_VIN_Copy_4;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_5_VIN_Copy_5;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_6_VIN_Copy_6;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_7_VIN_Copy_7;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_8_VIN_Copy_8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_9_VIN_Copy_9;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_VoltageDemand_VoltageDemand;
extern VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_bAcvBaln_BBC_bAcvBaln;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_AcvCellURchd_BCC_AcvCellURchd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_AcvSocRchd_BCC_AcvSocRchd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_AcvUTotRchd_BCC_AcvUTotRchd;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_EChSng_BCC_EChSng;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ElectroniclockContorREQ_BCC_ElectroniclockContorREQ;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ElectroniclockSt_BCC_ElectroniclockSt;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ErrInfo_BCC_ErrInfo;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_IDchaReq_BCC_IDchaReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_IObcLimn_BCC_IObcLimn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ModeCh_BCC_ModeCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_StAcChReq_BCC_StAcChReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_StCh_BCC_StCh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_TimeOut_CRO00_BCC_TimeOutCRO00;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_TimeOut_CROAA_BCC_TimeOutCROAA;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_TranAcChEndByBatHvReq_BCC_TranAcChEndByBatHvReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_UChReq_BCC_UChReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_UObcLimn_BCC_UObcLimn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_bS2Ctrl_BCC_bS2Ctrl;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_EPackRmng_BCF_EPackRmng;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo_BCF_ErrInfo;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChLim_BCF_IChLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChLimMap_BCF_IChLimMap;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChPredLim_BCF_IChPredLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaLim_BCF_IDchaLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaLimMap_BCF_IDchaLimMap;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaPredLim_BCF_IDchaPredLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocLimMin_BCF_SocLimMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocPack_BCF_SocPack;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocPackScld_BCF_SocPackScld;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohPack_BCF_SohPack;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_bChrgFullCalRemind_BCF_bChrgFullCalRemind;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCTE_TiBatDchaByMinuTot_BCTE_TiBatDchaByMinuTot;
extern VAR(rt_Array_Float_255, RTE_VAR_INIT) Rte_swc_CIL_BMC_UCell_BMC_UCell;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrCellU_BPIU_ErrCellU;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrCellUDif_BPIU_ErrCellUDif;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrCellUOver_BPIU_ErrCellUOver;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrIChLim_BPIU_ErrIChLim;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrIRgnOvcur_BPIU_ErrIRgnOvcur;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrInfo_BPIU_ErrInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrPackSnsrI_BPIU_ErrPackSnsrI;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrUAcqn_BPIU_ErrUAcqn;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_IdCellUMax_BPIU_IdCellUMax;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_IdCellUMin_BPIU_IdCellUMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_UCellMax_BPIU_UCellMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_UCellMin_BPIU_UCellMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrCellT_BPP_ErrCellT;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrInfo_BPP_ErrInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrPackU_BPP_ErrPackU;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrSocVal_BPP_ErrSocVal;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_AcvChManSuspd_BSOF_AcvChManSuspd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_AcvChSuspdByBms_BSOF_AcvChSuspdByBms;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_AcvChSuspdCdnRchd_BSOF_AcvChSuspdCdnRchd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_AcvChSuspdFlt_BSOF_AcvChSuspdFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_EChSng_BSOF_EChSng;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChImpo_BSOF_ErrChImpo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrIDe_BSOF_ErrIDe;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrUAbno_BSOF_ErrUAbno;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrUndfnd_BSOF_ErrUndfnd;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_IChrgr_BSOF_IChrgr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UChrgr_BSOF_UChrgr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_ModeBmsAcvn_BSTC_ModeBmsAcvn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_ReqEmcyHvOffFromBms_BSTC_ReqEmcyHvOffFromBms;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_ReqShtdnBas_BSTC_ReqShtdnBas;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBcuInt_BSTC_StBcuInt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBmsChk_BSTC_StBmsChk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvCutoffLvFromBms_BSTC_bAcvCutoffLvFromBms;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvObcOff_BSTC_bAcvObcOff;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_ErrChEnd_BTHM_ErrChEnd;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_ErrInfo_BTHM_ErrInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_IdCellTMax_BTHM_IdCellTMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_IdCellTMin_BTHM_IdCellTMin;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StSys_BTHM_StSys;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StThermReq_BTHM_StThermReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TBatTgt_BTHM_TBatTgt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TOptmMax_BTHM_TOptmMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TOptmMin_BTHM_TOptmMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TPack_BTHM_TPack;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_bAcvDig93_BTHM_bAcvDig93;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatChTot_BWLD_CBatChTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatDchaTot_BWLD_CBatDchaTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatRecoveryTot_BWLD_CBatRecoveryTot;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrCh_BWLD_CtrCh;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrDcha_BWLD_CtrDcha;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatChTot_BWLD_EBatChTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatDchaDrvCyc_BWLD_EBatDchaDrvCyc;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatDchaTot_BWLD_EBatDchaTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatRecoveryDrvCyc_BWLD_EBatRecoveryDrvCyc;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatRecoveryTot_BWLD_EBatRecoveryTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_ActInputVolt_CIL_ActInputVolt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_BatCoolType_CIL_BatCoolType;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_CP_Vol_CIL_CP_Vol;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_DucycCtlPilot_CIL_DucycCtlPilot;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_ErrInfoBSW_CIL_ErrInfoBSW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_HWVerVeh_CIL_HWVerVeh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_MilgTot_CIL_MilgTot;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_RAcChCnctnResRaw_CIL_RAcChCnctnResRaw;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_RngElec_CIL_RngElec;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_SWVerVeh_CIL_SWVerVeh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StAcChCnct_CIL_StAcChCnct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StChAllwd_CIL_StChAllwd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StChWup_CIL_StChWup;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TAcChPointNeg_CIL_TAcChPointNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TAcChPointPos_CIL_TAcChPointPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TDcChPointNeg_CIL_TDcChPointNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TDcChPointPos_CIL_TDcChPointPos;
extern VAR(rt_Array_Float_54, RTE_VAR_INIT) Rte_swc_CIL_CIL_TMdul_CIL_TMdul;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UTrml30_CIL_UTrml30;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrInfo_CTC_ErrInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyCh_CTC_ErrRlyCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyHeat_CTC_ErrRlyHeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyNeg_CTC_ErrRlyNeg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyPos_CTC_ErrRlyPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyPrech_CTC_ErrRlyPrech;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyCh_CTC_ReqRlyCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyHeat_CTC_ReqRlyHeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyNeg_CTC_ReqRlyNeg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyPos_CTC_ReqRlyPos;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqZeroPwr_CTC_ReqZeroPwr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyCh_CTC_StRlyCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyHeat_CTC_StRlyHeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyNeg_CTC_StRlyNeg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyPos_CTC_StRlyPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyPrech_CTC_StRlyPrech;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_ClL_InletWaterTemp_ClL_InletWaterTemp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_ClL_OutletWaterTemp_ClL_OutletWaterTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_BatMfctrType_DEH_BatMfctrType;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_BatMfctrr_DEH_BatMfctrr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CBatNom_DEH_CBatNom;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ChgLvlErr_DEH_ChgLvlErr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_DayBatMfctr_DEH_DayBatMfctr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_DelayDataUpldEnb_DEH_DelayDataUpldEnb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_DischgLvlErr_DEH_DischgLvlErr;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd2_DEH_ErrCfmd2;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd4_DEH_ErrCfmd4;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_LvlErrSb_DEH_LvlErrSb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_MonthBatMfctr_DEH_MonthBatMfctr;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrPackSerl_DEH_NrPackSerl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin1_DEH_NrVin1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin10_DEH_NrVin10;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin11_DEH_NrVin11;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin12_DEH_NrVin12;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin13_DEH_NrVin13;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin14_DEH_NrVin14;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin15_DEH_NrVin15;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin16_DEH_NrVin16;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin17_DEH_NrVin17;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin2_DEH_NrVin2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin3_DEH_NrVin3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin4_DEH_NrVin4;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin5_DEH_NrVin5;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin6_DEH_NrVin6;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin7_DEH_NrVin7;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin8_DEH_NrVin8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin9_DEH_NrVin9;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_PackCode_DEH_PackCode;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_StFltLampIndcn_DEH_StFltLampIndcn;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_UBatNom_DEH_UBatNom;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_VCU_ChgFaultReq_DEH_VCU_ChgFaultReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_VCU_DischgFaultReq_DEH_VCU_DischgFaultReq;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ValCodDiag_DEH_ValCodDiag;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_YearBatMfctr_DEH_YearBatMfctr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvChInh_DEH_bAcvChInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvDcChInh_DEH_bAcvDcChInh;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_ErrInfo_ELHPN_ErrInfo;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnNeg_ELHPN_RIslnNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnPos_ELHPN_RIslnPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StIsln_ELHPN_StIsln;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StIslnErr_ELHPN_StIslnErr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StVehIsln_ELHPN_StVehIsln;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_bInhIslnMeas_ELHPN_bInhIslnMeas;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ChMode_EVCSH_ChMode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChRdy_EVCSH_ErrMsgChrgrChRdy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChSts_EVCSH_ErrMsgChrgrChSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChStstc_EVCSH_ErrMsgChrgrChStstc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChSuspd_EVCSH_ErrMsgChrgrChSuspd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrIdfcNotRdy_EVCSH_ErrMsgChrgrIdfcNotRdy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrIdfcRdy_EVCSH_ErrMsgChrgrIdfcRdy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrSync_EVCSH_ErrMsgChrgrSync;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_IChrgrSp_EVCSH_IChrgrSp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_StBatRdy_EVCSH_StBatRdy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_StDcCh_EVCSH_StDcCh;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_StInt_EVCSH_StInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_UChrgrSp_EVCSH_UChrgrSp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaChrgn_EVCSH_bEnaChrgn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatCfgPgtn_EVCSH_bEnaMsgBatCfgPgtn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChStPgtn_EVCSH_bEnaMsgBatChStPgtn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatPrvt_EVCSH_bEnaMsgBatPrvt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatT_EVCSH_bEnaMsgBatT;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgCellU_EVCSH_bEnaMsgCellU;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrCellByMdul_MCC_NrCellByMdul;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrCellTot_MCC_NrCellTot;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrMdulTot_MCC_NrMdulTot;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrSnsrTTot_MCC_NrSnsrTTot;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_12VBatFault_BMSH_12VBatFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_AllowBatTempMax_BMSH_AllowBatTempMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_AllowBatTempMin_BMSH_AllowBatTempMin;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_AllowCellVoltMax_BMSH_AllowCellVoltMax;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_AllowCellVoltMin_BMSH_AllowCellVoltMin;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_AllowPackVoltMax_BMSH_AllowPackVoltMax;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_AllowPackVoltMin_BMSH_AllowPackVoltMin;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatCurrent_BMSH_BatCurrent;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatMaintReqValidFlag_BMSH_BatMaintReqValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatMaintenanceReq_BMSH_BatMaintenanceReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatOverSOC_BMSH_BatOverSOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatOverVolt_BMSH_BatOverVolt;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatRealSOC_BMSH_BatRealSOC;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatRealSOCValidFlag_BMSH_BatRealSOCValidFlag;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatSOE_BMSH_BatSOE;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatSOEValidFlag_BMSH_BatSOEValidFlag;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatSOH_BMSH_BatSOH;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatSOHValidFlag_BMSH_BatSOHValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatTempMax_BMSH_BatTempMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatTempMin_BMSH_BatTempMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatUnderSOC_BMSH_BatUnderSOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatUnderVolt_BMSH_BatUnderVolt;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatUseableSOC_BMSH_BatUseableSOC;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatUseableSOCValidFlag_BMSH_BatUseableSOCValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BattPackNum_BMSH_BattPackNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BattSysNum_BMSH_BattSysNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BattTempAvg_BMSH_BattTempAvg;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BusVolt_BMSH_BusVolt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BusVoltValidFlag_BMSH_BusVoltValidFlag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_InletTargTmpValidFlag_BMSH_CCM_InletTargTmpValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_LiquidInTempValidFlag_BMSH_CCM_LiquidInTempValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_LiquidOutTmpValidFlag_BMSH_CCM_LiquidOutTmpValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_ThrmlMangReqValidFlag_BMSH_CCM_ThrmlMangReqValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellOverVolt_BMSH_CellOverVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellTempUniformity_BMSH_CellTempUniformity;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellUnderVolt_BMSH_CellUnderVolt;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellVoltMax_BMSH_CellVoltMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellVoltMaxModuleID_BMSH_CellVoltMaxModuleID;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellVoltMin_BMSH_CellVoltMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellVoltMinModuleID_BMSH_CellVoltMinModuleID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_ChgOverTemp_BMSH_ChgOverTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_ChgUnderTemp_BMSH_ChgUnderTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_ConnectNegOverTemp_BMSH_ConnectNegOverTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_ConnectPosOverTemp_BMSH_ConnectPosOverTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CoolType_BMSH_CoolType;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_CoolTypeValidFlag_BMSH_CoolTypeValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChargeProcess_BMSH_DCChargeProcess;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgCurReq_BMSH_DCChgCurReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgEnder_BMSH_DCChgEnder;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgPosRelayFault_BMSH_DCChgPosRelayFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRelayFault_BMSH_DCChgRelayFault;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CCS_BMSH_DCChgRx_OTime_CCS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CML_BMSH_DCChgRx_OTime_CML;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CRM00_BMSH_DCChgRx_OTime_CRM00;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CRMAA_BMSH_DCChgRx_OTime_CRMAA;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CSD_BMSH_DCChgRx_OTime_CSD;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgStandVer_BMSH_DCChgStandVer;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgVoltAllow_BMSH_DCChgVoltAllow;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgVoltAllowValidFlag_BMSH_DCChgVoltAllowValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCEquipment_DisplayCur_BMSH_DCEquipment_DisplayCur;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCEquipment_DisplayVolt_BMSH_DCEquipment_DisplayVolt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DC_DisplayCurRangeUP_BMSH_DC_DisplayCurRangeUP;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DC_DisplayVoltValidFlag_BMSH_DC_DisplayVoltValidFlag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DataStorageFault_BMSH_DataStorageFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DisChgOverCurrent_BMSH_DisChgOverCurrent;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DisChgOverTemp_BMSH_DisChgOverTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DisChgUnderTemp_BMSH_DisChgUnderTemp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_EVCANComFault_BMSH_EVCANComFault;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_EnergyOut_BMSH_EnergyOut;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_EnergyOutValidFlag_BMSH_EnergyOutValidFlag;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_ExChgNumOfTimes_BMSH_ExChgNumOfTimes;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_ExChgNumOfTimesValidFlag_BMSH_ExChgNumOfTimesValidFlag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_FastChgComFault_BMSH_FastChgComFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_FaultCode_BMSH_FaultCode;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_FinishChgTime_BMSH_FinishChgTime;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_FinishChgTimeValidFlag_BMSH_FinishChgTimeValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_FireAlarm_BMSH_FireAlarm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_FlowRateReq_BMSH_FlowRateReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_FlowRateReqValidFlag_BMSH_FlowRateReqValidFlag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_IntComFault_BMSH_IntComFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_MainNegRelayFault_BMSH_MainNegRelayFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_MainPosRelayFault_BMSH_MainPosRelayFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode1_BMSH_PackCode1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode1_1_BMSH_PackCode1_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode2_BMSH_PackCode2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode2_1_BMSH_PackCode2_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode3_BMSH_PackCode3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode3_1_BMSH_PackCode3_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode4_BMSH_PackCode4;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode4_1_BMSH_PackCode4_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode5_BMSH_PackCode5;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode5_1_BMSH_PackCode5_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode6_BMSH_PackCode6;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode7_BMSH_PackCode7;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode_ID_BMSH_PackCode_ID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackExtendCd_BMSH_PackExtendCd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackType_BMSH_PackType;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackVolt_BMSH_PackVolt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_RecoveryOverCurrent_BMSH_RecoveryOverCurrent;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_SelfCheckFault_BMSH_SelfCheckFault;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsA_plus_BMSH_StsA_plus;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsCC2_BMSH_StsCC2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsCellBalance_BMSH_StsCellBalance;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsChgFault_BMSH_StsChgFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsDischgFault_BMSH_StsDischgFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsInsulation_BMSH_StsInsulation;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsMode_BMSH_StsMode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsPrecharge_BMSH_StsPrecharge;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsWakeUp_BMSH_StsWakeUp;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_SubtotalExChgSOE_BMSH_SubtotalExChgSOE;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_SubtotalRecoveryEng_BMSH_SubtotalRecoveryEng;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_SupplyVolt_BMSH_SupplyVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_SwapCntOverTemp_BMSH_SwapCntOverTemp;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatFaultList_BMSH_TBOX_BatFaultList;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatHVILFault_BMSH_TBOX_BatHVILFault;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatIsoAlarm_BMSH_TBOX_BatIsoAlarm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatLowSOC_BMSH_TBOX_BatLowSOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatLowTemp_BMSH_TBOX_BatLowTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatModuleSum_BMSH_TBOX_BatModuleSum;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverCharge_BMSH_TBOX_BatOverCharge;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverSOC_BMSH_TBOX_BatOverSOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverTemp_BMSH_TBOX_BatOverTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverVoltage_BMSH_TBOX_BatOverVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatProductDay_BMSH_TBOX_BatProductDay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatProductMonth_BMSH_TBOX_BatProductMonth;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatProductYear_BMSH_TBOX_BatProductYear;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatRatedEnergy_BMSH_TBOX_BatRatedEnergy;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatRatedVolt_BMSH_TBOX_BatRatedVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatSeriesCellsSum_BMSH_TBOX_BatSeriesCellsSum;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatStoreSysFault_BMSH_TBOX_BatStoreSysFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatTempUniformity_BMSH_TBOX_BatTempUniformity;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatType_BMSH_TBOX_BatType;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatUnderVoltage_BMSH_TBOX_BatUnderVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatUniformity_BMSH_TBOX_BatUniformity;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellOverVoltage_BMSH_TBOX_CellOverVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellRatedVolt_BMSH_TBOX_CellRatedVolt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellUnderVoltage_BMSH_TBOX_CellUnderVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_HWVer_BMSH_TBOX_HWVer;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_HWVer_Test_BMSH_TBOX_HWVer_Test;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_InsulationResistance_BMSH_TBOX_InsulationResistance;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_SOCHop_BMSH_TBOX_SOCHop;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_SWVer_BMSH_TBOX_SWVer;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_SWVer_Test_BMSH_TBOX_SWVer_Test;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempA_BMSH_TBOX_TempA;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempB_BMSH_TBOX_TempB;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempC_BMSH_TBOX_TempC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempD_BMSH_TBOX_TempD;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempE_BMSH_TBOX_TempE;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempF_BMSH_TBOX_TempF;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempF_ID_BMSH_TBOX_TempF_ID;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TheftFault_BMSH_TBOX_TheftFault;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalDischgCapacity_BMSH_TotalDischgCapacity;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalDischgEng_BMSH_TotalDischgEng;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalExChgCapacity_BMSH_TotalExChgCapacity;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalExChgEng_BMSH_TotalExChgEng;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalExChgSOE_BMSH_TotalExChgSOE;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalOdometer_BMSH_TotalOdometer;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalOdometerValidFlag_BMSH_TotalOdometerValidFlag;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalRecoveryCapacity_BMSH_TotalRecoveryCapacity;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalRecoveryEng_BMSH_TotalRecoveryEng;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TripOdometer_BMSH_TripOdometer;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TripOdometerValidFlag_BMSH_TripOdometerValidFlag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCUChksumFault_BMSH_VCUChksumFault;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCURollCountFault_BMSH_VCURollCountFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatChgContPwr_BMSH_VCU_BatChgContPwr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatChgPeakPwr_BMSH_VCU_BatChgPeakPwr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatDischgContPwr_BMSH_VCU_BatDischgContPwr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatDischgPeakPwr_BMSH_VCU_BatDischgPeakPwr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_ChgSOPRangeUP_BMSH_VCU_ChgSOPRangeUP;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_ChgSOPValidFlag_BMSH_VCU_ChgSOPValidFlag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_Crash_BMSH_VCU_Crash;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_DCChgNegTemp_BMSH_VCU_DCChgNegTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_DCChgPosTemp_BMSH_VCU_DCChgPosTemp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_DisChgSOPValidFlag_BMSH_VCU_DisChgSOPValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_StsDCChgPosRelay_BMSH_VCU_StsDCChgPosRelay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_StsDCChgRelay_BMSH_VCU_StsDCChgRelay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_StsPreChgRelay_BMSH_VCU_StsPreChgRelay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_B2V_ST1_ChgMode_BMS_B2V_ST1_ChgMode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattCellsNumPN_BMS_BattCellsNumPN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattPackNumSN_BMS_BattPackNumSN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattTemp1_BMS_BattTemp1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattTemp2_BMS_BattTemp2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattTemp3_BMS_BattTemp3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattTemp4_BMS_BattTemp4;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattTemp5_BMS_BattTemp5;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattTemp6_BMS_BattTemp6;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CCvalue_BMS_CCvalue;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_CPLine_S2_Ctrl_BMS_CPLine_S2_Ctrl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CP_Duty_BMS_CP_Duty;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CP_Vol_BMS_CP_Vol;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CellTempFrameNum_BMS_CellTempFrameNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CellVoltFrameNum_BMS_CellVoltFrameNum;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_CellVoltN1_BMS_CellVoltN1;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_CellVoltN2_BMS_CellVoltN2;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_CellVoltN3_BMS_CellVoltN3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_ChgCCSts_BMS_ChgCCSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_ChgStatus_BMS_ChgStatus;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CutOffLVFbToOBC_BMS_CutOffLVFbToOBC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_DCChargRelayCtrl_BMS_DCChargRelayCtrl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_DelayControl_BMS_DelayControl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_DischargeCCvalue_BMS_DischargeCCvalue;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_ElectroniclockContorREQ_BMS_ElectroniclockContorREQ;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_ElectroniclockSts_BMS_ElectroniclockSts;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_MaxChgCurrent_BMS_MaxChgCurrent;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_MaxChgVoltage_BMS_MaxChgVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_OBCChgContrlCmd_BMS_OBCChgContrlCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_S2STATUS_BMS_S2STATUS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_SlowChgNegTemp_BMS_SlowChgNegTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_SlowChgPosTemp_BMS_SlowChgPosTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_SysCodeBattPackSN_1_BMS_SysCodeBattPackSN_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_SysCodeFrameNum_1_BMS_SysCodeFrameNum_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_SysCodeLength_1_BMS_SysCodeLength_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_TempCSCNum_BMS_TempCSCNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_TempSnsNumPN_BMS_TempSnsNumPN;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_VCU_ChrgFullCalRemind_BMS_VCU_ChrgFullCalRemind;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_VCU_ChrgModeAct_BMS_VCU_ChrgModeAct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_VCU_ChrgModeCalRemind_BMS_VCU_ChrgModeCalRemind;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_VCU_ChrgModeEn_BMS_VCU_ChrgModeEn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_VoltCellNum_BMS_VoltCellNum;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_HvSysSample_DisableIso_DisableIso;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ChargeModeReq_CIL_ChargeModeReq;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_ts_App1_Task_1000ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_1000ms_Core2_QM;
extern VAR(Rte_ts_App1_Task_50ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_50ms_Core2_QM;
extern VAR(Rte_ts_App1_Task_100ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_100ms_Core2_QM;
extern VAR(Rte_ts_App1_Task_10ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_10ms_Core2_QM;
extern VAR(Rte_ts_SWC_Init_Task_Core2, RTE_VAR_NOINIT) Rte_SWC_Init_Task_Core2;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
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
#define Rte_IWrite_COL_1000ms_B2V_SingleChgEnergy_B2V_SingleChgEnergy(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_B2V_SingleChgEnergy_B2V_SingleChgEnergy.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_B2V_SingleChgEnergy_B2V_SingleChgEnergy() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_B2V_SingleChgEnergy_B2V_SingleChgEnergy.value \
)

#define Rte_IRead_COL_50ms_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp() \
  (&((*RteIRead_COL_50ms_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp())[0]))

#define RteIRead_COL_50ms_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp() \
  (&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp.value)

#define Rte_IRead_COL_100ms_BBC_bAcvBaln_BBC_bAcvBaln() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BBC_bAcvBaln_BBC_bAcvBaln.value)

#define Rte_IRead_COL_100ms_BCC_AcvCellURchd_BCC_AcvCellURchd() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_AcvCellURchd_BCC_AcvCellURchd.value)

#define Rte_IRead_COL_10ms_BCC_AcvCellURchd_BCC_AcvCellURchd() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BCC_AcvCellURchd_BCC_AcvCellURchd.value)

#define Rte_IRead_COL_100ms_BCC_AcvSocRchd_BCC_AcvSocRchd() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_AcvSocRchd_BCC_AcvSocRchd.value)

#define Rte_IRead_COL_10ms_BCC_AcvSocRchd_BCC_AcvSocRchd() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BCC_AcvSocRchd_BCC_AcvSocRchd.value)

#define Rte_IRead_COL_100ms_BCC_AcvUTotRchd_BCC_AcvUTotRchd() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_AcvUTotRchd_BCC_AcvUTotRchd.value)

#define Rte_IRead_COL_10ms_BCC_AcvUTotRchd_BCC_AcvUTotRchd() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BCC_AcvUTotRchd_BCC_AcvUTotRchd.value)

#define Rte_IRead_COL_1000ms_BCC_EChSng_BCC_EChSng() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BCC_EChSng_BCC_EChSng.value)

#define Rte_IRead_COL_100ms_BCC_ElectroniclockContorREQ_BCC_ElectroniclockContorREQ() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_ElectroniclockContorREQ_BCC_ElectroniclockContorREQ.value)

#define Rte_IRead_COL_100ms_BCC_ElectroniclockSt_BCC_ElectroniclockSt() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_ElectroniclockSt_BCC_ElectroniclockSt.value)

#define Rte_IRead_COL_100ms_BCC_ErrInfo_BCC_ErrInfo() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_ErrInfo_BCC_ErrInfo.value)

#define Rte_IRead_COL_100ms_BCC_IDchaReq_BCC_IDchaReq() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_IDchaReq_BCC_IDchaReq.value)

#define Rte_IRead_COL_100ms_BCC_IObcLimn_BCC_IObcLimn() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_IObcLimn_BCC_IObcLimn.value)

#define Rte_IRead_COL_100ms_BCC_ModeCh_BCC_ModeCh() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_ModeCh_BCC_ModeCh.value)

#define Rte_IRead_COL_100ms_BCC_StAcChReq_BCC_StAcChReq() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_StAcChReq_BCC_StAcChReq.value)

#define Rte_IRead_COL_100ms_BCC_StCh_BCC_StCh() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_StCh_BCC_StCh.value)

#define Rte_IRead_COL_100ms_BCC_TimeOutCRO00_BCC_TimeOutCRO00() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_TimeOutCRO00_BCC_TimeOutCRO00.value)

#define Rte_IRead_COL_100ms_BCC_TimeOutCROAA_BCC_TimeOutCROAA() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_TimeOutCROAA_BCC_TimeOutCROAA.value)

#define Rte_IRead_COL_10ms_BCC_TranAcChEndByBatHvReq_BCC_TranAcChEndByBatHvReq() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BCC_TranAcChEndByBatHvReq_BCC_TranAcChEndByBatHvReq.value)

#define Rte_IRead_COL_10ms_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq.value)

#define Rte_IRead_COL_100ms_BCC_UChReq_BCC_UChReq() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_UChReq_BCC_UChReq.value)

#define Rte_IRead_COL_100ms_BCC_UObcLimn_BCC_UObcLimn() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_UObcLimn_BCC_UObcLimn.value)

#define Rte_IRead_COL_100ms_BCC_bS2Ctrl_BCC_bS2Ctrl() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCC_bS2Ctrl_BCC_bS2Ctrl.value)

#define Rte_IRead_COL_100ms_BCF_EPackRmng_BCF_EPackRmng() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCF_EPackRmng_BCF_EPackRmng.value)

#define Rte_IRead_COL_100ms_BCF_ErrInfo_BCF_ErrInfo() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCF_ErrInfo_BCF_ErrInfo.value)

#define Rte_IRead_COL_1000ms_BCF_IChLim_BCF_IChLim() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BCF_IChLim_BCF_IChLim.value)

#define Rte_IRead_COL_1000ms_BCF_IChLimMap_BCF_IChLimMap() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BCF_IChLimMap_BCF_IChLimMap.value)

#define Rte_IRead_COL_100ms_BCF_IChPredLim_BCF_IChPredLim() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCF_IChPredLim_BCF_IChPredLim.value)

#define Rte_IRead_COL_1000ms_BCF_IDchaLim_BCF_IDchaLim() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BCF_IDchaLim_BCF_IDchaLim.value)

#define Rte_IRead_COL_1000ms_BCF_IDchaLimMap_BCF_IDchaLimMap() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BCF_IDchaLimMap_BCF_IDchaLimMap.value)

#define Rte_IRead_COL_100ms_BCF_IDchaPredLim_BCF_IDchaPredLim() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCF_IDchaPredLim_BCF_IDchaPredLim.value)

#define Rte_IRead_COL_1000ms_BCF_SocLimMin_BCF_SocLimMin() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BCF_SocLimMin_BCF_SocLimMin.value)

#define Rte_IRead_COL_100ms_BCF_SocPack_BCF_SocPack() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCF_SocPack_BCF_SocPack.value)

#define Rte_IRead_COL_100ms_BCF_SocPackScld_BCF_SocPackScld() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCF_SocPackScld_BCF_SocPackScld.value)

#define Rte_IRead_COL_100ms_BCF_SohPack_BCF_SohPack() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCF_SohPack_BCF_SohPack.value)

#define Rte_IRead_COL_100ms_BCF_UBatTotInt_BCF_UBatTotInt() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value)

#define Rte_IRead_COL_1000ms_BCF_bChrgFullCalRemind_BCF_bChrgFullCalRemind() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BCF_bChrgFullCalRemind_BCF_bChrgFullCalRemind.value)

#define Rte_IRead_COL_100ms_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg.value)

#define Rte_IWrite_COL_100ms_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur.value \
)

#define Rte_IWrite_COL_100ms_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV.value \
)

#define Rte_IWrite_COL_100ms_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV.value \
)

#define Rte_IWrite_COL_100ms_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc.value \
)

#define Rte_IWrite_COL_Init_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc.value = (data) \
)

#define Rte_IWriteRef_COL_Init_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc.value \
)

#define Rte_IWrite_COL_100ms_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time.value \
)

#define Rte_IWrite_COL_100ms_BCSP_Remaining_range_BCSP_Remaining_range(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCSP_Remaining_range_BCSP_Remaining_range.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BCSP_Remaining_range_BCSP_Remaining_range() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCSP_Remaining_range_BCSP_Remaining_range.value \
)

#define Rte_IWrite_COL_100ms_BCSP_reserved_BCSP_reserved(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCSP_reserved_BCSP_reserved.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BCSP_reserved_BCSP_reserved() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCSP_reserved_BCSP_reserved.value \
)

#define Rte_IWrite_COL_Init_BCSP_reserved_BCSP_reserved(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BCSP_reserved_BCSP_reserved.value = (data) \
)

#define Rte_IWriteRef_COL_Init_BCSP_reserved_BCSP_reserved() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BCSP_reserved_BCSP_reserved.value \
)

#define Rte_IRead_COL_1000ms_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot.value)

#define Rte_IRead_COL_100ms_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot.value)

#define Rte_IRead_COL_100ms_BCTE_TiBatDchaByMinuTot_BCTE_TiBatDchaByMinuTot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BCTE_TiBatDchaByMinuTot_BCTE_TiBatDchaByMinuTot.value)

#define Rte_IWrite_COL_100ms_BDC_Battery_capacity_BDC_Battery_capacity(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Battery_capacity_BDC_Battery_capacity.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Battery_capacity_BDC_Battery_capacity() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Battery_capacity_BDC_Battery_capacity.value \
)

#define Rte_IWrite_COL_100ms_BDC_Battery_energy_BDC_Battery_energy(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Battery_energy_BDC_Battery_energy.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Battery_energy_BDC_Battery_energy() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Battery_energy_BDC_Battery_energy.value \
)

#define Rte_IWrite_COL_100ms_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate.value \
)

#define Rte_IWrite_COL_100ms_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange.value \
)

#define Rte_IWrite_COL_100ms_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate.value \
)

#define Rte_IWrite_COL_100ms_BDC_Soc_BDC_Soc(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Soc_BDC_Soc.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Soc_BDC_Soc() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Soc_BDC_Soc.value \
)

#define Rte_IWrite_COL_100ms_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1.value \
)

#define Rte_IWrite_COL_100ms_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10.value \
)

#define Rte_IWrite_COL_100ms_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11.value \
)

#define Rte_IWrite_COL_100ms_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12.value \
)

#define Rte_IWrite_COL_100ms_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13.value \
)

#define Rte_IWrite_COL_100ms_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14.value \
)

#define Rte_IWrite_COL_100ms_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15.value \
)

#define Rte_IWrite_COL_100ms_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16.value \
)

#define Rte_IWrite_COL_100ms_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17.value \
)

#define Rte_IWrite_COL_100ms_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2.value \
)

#define Rte_IWrite_COL_100ms_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3.value \
)

#define Rte_IWrite_COL_100ms_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4.value \
)

#define Rte_IWrite_COL_100ms_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5.value \
)

#define Rte_IWrite_COL_100ms_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6.value \
)

#define Rte_IWrite_COL_100ms_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7.value \
)

#define Rte_IWrite_COL_100ms_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8.value \
)

#define Rte_IWrite_COL_100ms_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9.value \
)

#define Rte_IRead_COL_100ms_BMC_UCell_BMC_UCell() \
  (&((*RteIRead_COL_100ms_BMC_UCell_BMC_UCell())[0]))

#define RteIRead_COL_100ms_BMC_UCell_BMC_UCell() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMC_UCell_BMC_UCell.value)

#define Rte_IWrite_COL_100ms_BMSH_12VBatFault_BMSH_12VBatFault(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_12VBatFault_BMSH_12VBatFault.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_12VBatFault_BMSH_12VBatFault() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_12VBatFault_BMSH_12VBatFault.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_AllowBatTempMax_BMSH_AllowBatTempMax(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_AllowBatTempMax_BMSH_AllowBatTempMax.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_AllowBatTempMax_BMSH_AllowBatTempMax() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_AllowBatTempMax_BMSH_AllowBatTempMax.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_AllowBatTempMin_BMSH_AllowBatTempMin(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_AllowBatTempMin_BMSH_AllowBatTempMin.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_AllowBatTempMin_BMSH_AllowBatTempMin() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_AllowBatTempMin_BMSH_AllowBatTempMin.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_AllowCellVoltMax_BMSH_AllowCellVoltMax(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_AllowCellVoltMax_BMSH_AllowCellVoltMax.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_AllowCellVoltMax_BMSH_AllowCellVoltMax() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_AllowCellVoltMax_BMSH_AllowCellVoltMax.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_AllowCellVoltMin_BMSH_AllowCellVoltMin(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_AllowCellVoltMin_BMSH_AllowCellVoltMin.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_AllowCellVoltMin_BMSH_AllowCellVoltMin() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_AllowCellVoltMin_BMSH_AllowCellVoltMin.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_AllowPackVoltMax_BMSH_AllowPackVoltMax(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_AllowPackVoltMax_BMSH_AllowPackVoltMax.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_AllowPackVoltMax_BMSH_AllowPackVoltMax() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_AllowPackVoltMax_BMSH_AllowPackVoltMax.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_AllowPackVoltMin_BMSH_AllowPackVoltMin(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_AllowPackVoltMin_BMSH_AllowPackVoltMin.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_AllowPackVoltMin_BMSH_AllowPackVoltMin() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_AllowPackVoltMin_BMSH_AllowPackVoltMin.value \
)

#define Rte_IWrite_COL_100ms_BMSH_BatCurrent_BMSH_BatCurrent(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatCurrent_BMSH_BatCurrent.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_BatCurrent_BMSH_BatCurrent() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatCurrent_BMSH_BatCurrent.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_BatMaintReqValidFlag_BMSH_BatMaintReqValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatMaintReqValidFlag_BMSH_BatMaintReqValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_BatMaintReqValidFlag_BMSH_BatMaintReqValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatMaintReqValidFlag_BMSH_BatMaintReqValidFlag.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_BatMaintenanceReq_BMSH_BatMaintenanceReq(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatMaintenanceReq_BMSH_BatMaintenanceReq.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_BatMaintenanceReq_BMSH_BatMaintenanceReq() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatMaintenanceReq_BMSH_BatMaintenanceReq.value \
)

#define Rte_IWrite_COL_100ms_BMSH_BatOverSOC_BMSH_BatOverSOC(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatOverSOC_BMSH_BatOverSOC.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_BatOverSOC_BMSH_BatOverSOC() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatOverSOC_BMSH_BatOverSOC.value \
)

#define Rte_IWrite_COL_100ms_BMSH_BatOverVolt_BMSH_BatOverVolt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatOverVolt_BMSH_BatOverVolt.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_BatOverVolt_BMSH_BatOverVolt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatOverVolt_BMSH_BatOverVolt.value \
)

#define Rte_IWrite_COL_100ms_BMSH_BatRealSOC_BMSH_BatRealSOC(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatRealSOC_BMSH_BatRealSOC.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_BatRealSOC_BMSH_BatRealSOC() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatRealSOC_BMSH_BatRealSOC.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_BatRealSOCValidFlag_BMSH_BatRealSOCValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatRealSOCValidFlag_BMSH_BatRealSOCValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_BatRealSOCValidFlag_BMSH_BatRealSOCValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatRealSOCValidFlag_BMSH_BatRealSOCValidFlag.value \
)

#define Rte_IWrite_COL_100ms_BMSH_BatSOE_BMSH_BatSOE(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatSOE_BMSH_BatSOE.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_BatSOE_BMSH_BatSOE() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatSOE_BMSH_BatSOE.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_BatSOEValidFlag_BMSH_BatSOEValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatSOEValidFlag_BMSH_BatSOEValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_BatSOEValidFlag_BMSH_BatSOEValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatSOEValidFlag_BMSH_BatSOEValidFlag.value \
)

#define Rte_IWrite_COL_100ms_BMSH_BatSOH_BMSH_BatSOH(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatSOH_BMSH_BatSOH.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_BatSOH_BMSH_BatSOH() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatSOH_BMSH_BatSOH.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_BatSOHValidFlag_BMSH_BatSOHValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatSOHValidFlag_BMSH_BatSOHValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_BatSOHValidFlag_BMSH_BatSOHValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatSOHValidFlag_BMSH_BatSOHValidFlag.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_BatTempMax_BMSH_BatTempMax(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatTempMax_BMSH_BatTempMax.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_BatTempMax_BMSH_BatTempMax() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatTempMax_BMSH_BatTempMax.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_BatTempMin_BMSH_BatTempMin(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatTempMin_BMSH_BatTempMin.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_BatTempMin_BMSH_BatTempMin() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatTempMin_BMSH_BatTempMin.value \
)

#define Rte_IWrite_COL_100ms_BMSH_BatUnderSOC_BMSH_BatUnderSOC(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatUnderSOC_BMSH_BatUnderSOC.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_BatUnderSOC_BMSH_BatUnderSOC() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatUnderSOC_BMSH_BatUnderSOC.value \
)

#define Rte_IWrite_COL_100ms_BMSH_BatUnderVolt_BMSH_BatUnderVolt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatUnderVolt_BMSH_BatUnderVolt.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_BatUnderVolt_BMSH_BatUnderVolt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatUnderVolt_BMSH_BatUnderVolt.value \
)

#define Rte_IWrite_COL_100ms_BMSH_BatUseableSOC_BMSH_BatUseableSOC(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatUseableSOC_BMSH_BatUseableSOC.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_BatUseableSOC_BMSH_BatUseableSOC() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_BatUseableSOC_BMSH_BatUseableSOC.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_BatUseableSOCValidFlag_BMSH_BatUseableSOCValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatUseableSOCValidFlag_BMSH_BatUseableSOCValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_BatUseableSOCValidFlag_BMSH_BatUseableSOCValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BatUseableSOCValidFlag_BMSH_BatUseableSOCValidFlag.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_BattPackNum_BMSH_BattPackNum(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BattPackNum_BMSH_BattPackNum.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_BattPackNum_BMSH_BattPackNum() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BattPackNum_BMSH_BattPackNum.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_BattSysNum_BMSH_BattSysNum(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BattSysNum_BMSH_BattSysNum.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_BattSysNum_BMSH_BattSysNum() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BattSysNum_BMSH_BattSysNum.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_BattTempAvg_BMSH_BattTempAvg(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BattTempAvg_BMSH_BattTempAvg.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_BattTempAvg_BMSH_BattTempAvg() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BattTempAvg_BMSH_BattTempAvg.value \
)

#define Rte_IWrite_COL_50ms_BMSH_BusVolt_BMSH_BusVolt(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_BMSH_BusVolt_BMSH_BusVolt.value = (data) \
)

#define Rte_IWriteRef_COL_50ms_BMSH_BusVolt_BMSH_BusVolt() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_BMSH_BusVolt_BMSH_BusVolt.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_BusVoltValidFlag_BMSH_BusVoltValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BusVoltValidFlag_BMSH_BusVoltValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_BusVoltValidFlag_BMSH_BusVoltValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_BusVoltValidFlag_BMSH_BusVoltValidFlag.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_CCM_InletTargTmpValidFlag_BMSH_CCM_InletTargTmpValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CCM_InletTargTmpValidFlag_BMSH_CCM_InletTargTmpValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_CCM_InletTargTmpValidFlag_BMSH_CCM_InletTargTmpValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CCM_InletTargTmpValidFlag_BMSH_CCM_InletTargTmpValidFlag.value \
)

#define Rte_IWrite_COL_100ms_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp.value \
)

#define Rte_IWrite_COL_100ms_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_CCM_LiquidInTempValidFlag_BMSH_CCM_LiquidInTempValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CCM_LiquidInTempValidFlag_BMSH_CCM_LiquidInTempValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_CCM_LiquidInTempValidFlag_BMSH_CCM_LiquidInTempValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CCM_LiquidInTempValidFlag_BMSH_CCM_LiquidInTempValidFlag.value \
)

#define Rte_IWrite_COL_100ms_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_CCM_LiquidOutTmpValidFlag_BMSH_CCM_LiquidOutTmpValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CCM_LiquidOutTmpValidFlag_BMSH_CCM_LiquidOutTmpValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_CCM_LiquidOutTmpValidFlag_BMSH_CCM_LiquidOutTmpValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CCM_LiquidOutTmpValidFlag_BMSH_CCM_LiquidOutTmpValidFlag.value \
)

#define Rte_IWrite_COL_100ms_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_CCM_ThrmlMangReqValidFlag_BMSH_CCM_ThrmlMangReqValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CCM_ThrmlMangReqValidFlag_BMSH_CCM_ThrmlMangReqValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_CCM_ThrmlMangReqValidFlag_BMSH_CCM_ThrmlMangReqValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CCM_ThrmlMangReqValidFlag_BMSH_CCM_ThrmlMangReqValidFlag.value \
)

#define Rte_IWrite_COL_100ms_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform.value \
)

#define Rte_IWrite_COL_100ms_BMSH_CellOverVolt_BMSH_CellOverVolt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CellOverVolt_BMSH_CellOverVolt.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_CellOverVolt_BMSH_CellOverVolt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CellOverVolt_BMSH_CellOverVolt.value \
)

#define Rte_IWrite_COL_100ms_BMSH_CellTempUniformity_BMSH_CellTempUniformity(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CellTempUniformity_BMSH_CellTempUniformity.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_CellTempUniformity_BMSH_CellTempUniformity() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CellTempUniformity_BMSH_CellTempUniformity.value \
)

#define Rte_IWrite_COL_100ms_BMSH_CellUnderVolt_BMSH_CellUnderVolt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CellUnderVolt_BMSH_CellUnderVolt.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_CellUnderVolt_BMSH_CellUnderVolt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_CellUnderVolt_BMSH_CellUnderVolt.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_CellVoltMax_BMSH_CellVoltMax(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CellVoltMax_BMSH_CellVoltMax.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_CellVoltMax_BMSH_CellVoltMax() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CellVoltMax_BMSH_CellVoltMax.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_CellVoltMaxModuleID_BMSH_CellVoltMaxModuleID(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CellVoltMaxModuleID_BMSH_CellVoltMaxModuleID.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_CellVoltMaxModuleID_BMSH_CellVoltMaxModuleID() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CellVoltMaxModuleID_BMSH_CellVoltMaxModuleID.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_CellVoltMin_BMSH_CellVoltMin(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CellVoltMin_BMSH_CellVoltMin.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_CellVoltMin_BMSH_CellVoltMin() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CellVoltMin_BMSH_CellVoltMin.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_CellVoltMinModuleID_BMSH_CellVoltMinModuleID(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CellVoltMinModuleID_BMSH_CellVoltMinModuleID.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_CellVoltMinModuleID_BMSH_CellVoltMinModuleID() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CellVoltMinModuleID_BMSH_CellVoltMinModuleID.value \
)

#define Rte_IWrite_COL_100ms_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent.value \
)

#define Rte_IWrite_COL_100ms_BMSH_ChgOverTemp_BMSH_ChgOverTemp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_ChgOverTemp_BMSH_ChgOverTemp.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_ChgOverTemp_BMSH_ChgOverTemp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_ChgOverTemp_BMSH_ChgOverTemp.value \
)

#define Rte_IWrite_COL_100ms_BMSH_ChgUnderTemp_BMSH_ChgUnderTemp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_ChgUnderTemp_BMSH_ChgUnderTemp.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_ChgUnderTemp_BMSH_ChgUnderTemp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_ChgUnderTemp_BMSH_ChgUnderTemp.value \
)

#define Rte_IWrite_COL_100ms_BMSH_ConnectNegOverTemp_BMSH_ConnectNegOverTemp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_ConnectNegOverTemp_BMSH_ConnectNegOverTemp.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_ConnectNegOverTemp_BMSH_ConnectNegOverTemp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_ConnectNegOverTemp_BMSH_ConnectNegOverTemp.value \
)

#define Rte_IWrite_COL_100ms_BMSH_ConnectPosOverTemp_BMSH_ConnectPosOverTemp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_ConnectPosOverTemp_BMSH_ConnectPosOverTemp.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_ConnectPosOverTemp_BMSH_ConnectPosOverTemp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_ConnectPosOverTemp_BMSH_ConnectPosOverTemp.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_CoolType_BMSH_CoolType(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CoolType_BMSH_CoolType.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_CoolType_BMSH_CoolType() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CoolType_BMSH_CoolType.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_CoolTypeValidFlag_BMSH_CoolTypeValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CoolTypeValidFlag_BMSH_CoolTypeValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_CoolTypeValidFlag_BMSH_CoolTypeValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_CoolTypeValidFlag_BMSH_CoolTypeValidFlag.value \
)

#define Rte_IWrite_COL_100ms_BMSH_DCChargeProcess_BMSH_DCChargeProcess(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChargeProcess_BMSH_DCChargeProcess.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_DCChargeProcess_BMSH_DCChargeProcess() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChargeProcess_BMSH_DCChargeProcess.value \
)

#define Rte_IWrite_COL_100ms_BMSH_DCChgCurReq_BMSH_DCChgCurReq(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgCurReq_BMSH_DCChgCurReq.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_DCChgCurReq_BMSH_DCChgCurReq() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgCurReq_BMSH_DCChgCurReq.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_DCChgEnder_BMSH_DCChgEnder(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DCChgEnder_BMSH_DCChgEnder.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_DCChgEnder_BMSH_DCChgEnder() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DCChgEnder_BMSH_DCChgEnder.value \
)

#define Rte_IWrite_COL_100ms_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault.value \
)

#define Rte_IWrite_COL_Init_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault.value = (data) \
)

#define Rte_IWriteRef_COL_Init_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault.value \
)

#define Rte_IWrite_COL_100ms_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp.value \
)

#define Rte_IWrite_COL_100ms_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp.value \
)

#define Rte_IWrite_COL_100ms_BMSH_DCChgPosRelayFault_BMSH_DCChgPosRelayFault(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgPosRelayFault_BMSH_DCChgPosRelayFault.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_DCChgPosRelayFault_BMSH_DCChgPosRelayFault() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgPosRelayFault_BMSH_DCChgPosRelayFault.value \
)

#define Rte_IWrite_COL_100ms_BMSH_DCChgRelayFault_BMSH_DCChgRelayFault(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRelayFault_BMSH_DCChgRelayFault.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_DCChgRelayFault_BMSH_DCChgRelayFault() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRelayFault_BMSH_DCChgRelayFault.value \
)

#define Rte_IWrite_COL_100ms_BMSH_DCChgRx_OTime_CCS_BMSH_DCChgRx_OTime_CCS(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CCS_BMSH_DCChgRx_OTime_CCS.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_DCChgRx_OTime_CCS_BMSH_DCChgRx_OTime_CCS() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CCS_BMSH_DCChgRx_OTime_CCS.value \
)

#define Rte_IWrite_COL_100ms_BMSH_DCChgRx_OTime_CML_BMSH_DCChgRx_OTime_CML(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CML_BMSH_DCChgRx_OTime_CML.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_DCChgRx_OTime_CML_BMSH_DCChgRx_OTime_CML() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CML_BMSH_DCChgRx_OTime_CML.value \
)

#define Rte_IWrite_COL_100ms_BMSH_DCChgRx_OTime_CRM00_BMSH_DCChgRx_OTime_CRM00(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CRM00_BMSH_DCChgRx_OTime_CRM00.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_DCChgRx_OTime_CRM00_BMSH_DCChgRx_OTime_CRM00() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CRM00_BMSH_DCChgRx_OTime_CRM00.value \
)

#define Rte_IWrite_COL_100ms_BMSH_DCChgRx_OTime_CRMAA_BMSH_DCChgRx_OTime_CRMAA(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CRMAA_BMSH_DCChgRx_OTime_CRMAA.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_DCChgRx_OTime_CRMAA_BMSH_DCChgRx_OTime_CRMAA() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CRMAA_BMSH_DCChgRx_OTime_CRMAA.value \
)

#define Rte_IWrite_COL_100ms_BMSH_DCChgRx_OTime_CRO00_BMSH_DCChgRx_OTime_CRO00(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CRO00_BMSH_DCChgRx_OTime_CRO00.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_DCChgRx_OTime_CRO00_BMSH_DCChgRx_OTime_CRO00() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CRO00_BMSH_DCChgRx_OTime_CRO00.value \
)

#define Rte_IWrite_COL_100ms_BMSH_DCChgRx_OTime_CROAA_BMSH_DCChgRx_OTime_CROAA(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CROAA_BMSH_DCChgRx_OTime_CROAA.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_DCChgRx_OTime_CROAA_BMSH_DCChgRx_OTime_CROAA() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CROAA_BMSH_DCChgRx_OTime_CROAA.value \
)

#define Rte_IWrite_COL_100ms_BMSH_DCChgRx_OTime_CSD_BMSH_DCChgRx_OTime_CSD(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CSD_BMSH_DCChgRx_OTime_CSD.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_DCChgRx_OTime_CSD_BMSH_DCChgRx_OTime_CSD() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgRx_OTime_CSD_BMSH_DCChgRx_OTime_CSD.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_DCChgStandVer_BMSH_DCChgStandVer(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DCChgStandVer_BMSH_DCChgStandVer.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_DCChgStandVer_BMSH_DCChgStandVer() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DCChgStandVer_BMSH_DCChgStandVer.value \
)

#define Rte_IWrite_COL_100ms_BMSH_DCChgVoltAllow_BMSH_DCChgVoltAllow(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgVoltAllow_BMSH_DCChgVoltAllow.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_DCChgVoltAllow_BMSH_DCChgVoltAllow() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DCChgVoltAllow_BMSH_DCChgVoltAllow.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_DCChgVoltAllowValidFlag_BMSH_DCChgVoltAllowValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DCChgVoltAllowValidFlag_BMSH_DCChgVoltAllowValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_DCChgVoltAllowValidFlag_BMSH_DCChgVoltAllowValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DCChgVoltAllowValidFlag_BMSH_DCChgVoltAllowValidFlag.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_DCEquipment_DisplayCur_BMSH_DCEquipment_DisplayCur(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DCEquipment_DisplayCur_BMSH_DCEquipment_DisplayCur.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_DCEquipment_DisplayCur_BMSH_DCEquipment_DisplayCur() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DCEquipment_DisplayCur_BMSH_DCEquipment_DisplayCur.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_DCEquipment_DisplayVolt_BMSH_DCEquipment_DisplayVolt(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DCEquipment_DisplayVolt_BMSH_DCEquipment_DisplayVolt.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_DCEquipment_DisplayVolt_BMSH_DCEquipment_DisplayVolt() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DCEquipment_DisplayVolt_BMSH_DCEquipment_DisplayVolt.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_DC_DisplayCurRangeUP_BMSH_DC_DisplayCurRangeUP(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DC_DisplayCurRangeUP_BMSH_DC_DisplayCurRangeUP.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_DC_DisplayCurRangeUP_BMSH_DC_DisplayCurRangeUP() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DC_DisplayCurRangeUP_BMSH_DC_DisplayCurRangeUP.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_DC_DisplayVoltValidFlag_BMSH_DC_DisplayVoltValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DC_DisplayVoltValidFlag_BMSH_DC_DisplayVoltValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_DC_DisplayVoltValidFlag_BMSH_DC_DisplayVoltValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_DC_DisplayVoltValidFlag_BMSH_DC_DisplayVoltValidFlag.value \
)

#define Rte_IWrite_COL_100ms_BMSH_DataStorageFault_BMSH_DataStorageFault(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DataStorageFault_BMSH_DataStorageFault.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_DataStorageFault_BMSH_DataStorageFault() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DataStorageFault_BMSH_DataStorageFault.value \
)

#define Rte_IWrite_COL_100ms_BMSH_DisChgOverCurrent_BMSH_DisChgOverCurrent(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DisChgOverCurrent_BMSH_DisChgOverCurrent.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_DisChgOverCurrent_BMSH_DisChgOverCurrent() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DisChgOverCurrent_BMSH_DisChgOverCurrent.value \
)

#define Rte_IWrite_COL_100ms_BMSH_DisChgOverTemp_BMSH_DisChgOverTemp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DisChgOverTemp_BMSH_DisChgOverTemp.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_DisChgOverTemp_BMSH_DisChgOverTemp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DisChgOverTemp_BMSH_DisChgOverTemp.value \
)

#define Rte_IWrite_COL_100ms_BMSH_DisChgUnderTemp_BMSH_DisChgUnderTemp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DisChgUnderTemp_BMSH_DisChgUnderTemp.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_DisChgUnderTemp_BMSH_DisChgUnderTemp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_DisChgUnderTemp_BMSH_DisChgUnderTemp.value \
)

#define Rte_IWrite_COL_100ms_BMSH_EVCANComFault_BMSH_EVCANComFault(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_EVCANComFault_BMSH_EVCANComFault.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_EVCANComFault_BMSH_EVCANComFault() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_EVCANComFault_BMSH_EVCANComFault.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_EnergyOut_BMSH_EnergyOut(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_EnergyOut_BMSH_EnergyOut.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_EnergyOut_BMSH_EnergyOut() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_EnergyOut_BMSH_EnergyOut.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_EnergyOutValidFlag_BMSH_EnergyOutValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_EnergyOutValidFlag_BMSH_EnergyOutValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_EnergyOutValidFlag_BMSH_EnergyOutValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_EnergyOutValidFlag_BMSH_EnergyOutValidFlag.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_ExChgNumOfTimes_BMSH_ExChgNumOfTimes(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_ExChgNumOfTimes_BMSH_ExChgNumOfTimes.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_ExChgNumOfTimes_BMSH_ExChgNumOfTimes() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_ExChgNumOfTimes_BMSH_ExChgNumOfTimes.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_ExChgNumOfTimesValidFlag_BMSH_ExChgNumOfTimesValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_ExChgNumOfTimesValidFlag_BMSH_ExChgNumOfTimesValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_ExChgNumOfTimesValidFlag_BMSH_ExChgNumOfTimesValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_ExChgNumOfTimesValidFlag_BMSH_ExChgNumOfTimesValidFlag.value \
)

#define Rte_IWrite_COL_100ms_BMSH_FastChgComFault_BMSH_FastChgComFault(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_FastChgComFault_BMSH_FastChgComFault.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_FastChgComFault_BMSH_FastChgComFault() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_FastChgComFault_BMSH_FastChgComFault.value \
)

#define Rte_IWrite_COL_100ms_BMSH_FaultCode_BMSH_FaultCode(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_FaultCode_BMSH_FaultCode.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_FaultCode_BMSH_FaultCode() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_FaultCode_BMSH_FaultCode.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_FinishChgTime_BMSH_FinishChgTime(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_FinishChgTime_BMSH_FinishChgTime.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_FinishChgTime_BMSH_FinishChgTime() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_FinishChgTime_BMSH_FinishChgTime.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_FinishChgTimeValidFlag_BMSH_FinishChgTimeValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_FinishChgTimeValidFlag_BMSH_FinishChgTimeValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_FinishChgTimeValidFlag_BMSH_FinishChgTimeValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_FinishChgTimeValidFlag_BMSH_FinishChgTimeValidFlag.value \
)

#define Rte_IWrite_COL_100ms_BMSH_FireAlarm_BMSH_FireAlarm(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_FireAlarm_BMSH_FireAlarm.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_FireAlarm_BMSH_FireAlarm() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_FireAlarm_BMSH_FireAlarm.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_FlowRateReq_BMSH_FlowRateReq(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_FlowRateReq_BMSH_FlowRateReq.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_FlowRateReq_BMSH_FlowRateReq() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_FlowRateReq_BMSH_FlowRateReq.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_FlowRateReqValidFlag_BMSH_FlowRateReqValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_FlowRateReqValidFlag_BMSH_FlowRateReqValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_FlowRateReqValidFlag_BMSH_FlowRateReqValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_FlowRateReqValidFlag_BMSH_FlowRateReqValidFlag.value \
)

#define Rte_IWrite_COL_100ms_BMSH_IntComFault_BMSH_IntComFault(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_IntComFault_BMSH_IntComFault.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_IntComFault_BMSH_IntComFault() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_IntComFault_BMSH_IntComFault.value \
)

#define Rte_IWrite_COL_100ms_BMSH_MainNegRelayFault_BMSH_MainNegRelayFault(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_MainNegRelayFault_BMSH_MainNegRelayFault.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_MainNegRelayFault_BMSH_MainNegRelayFault() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_MainNegRelayFault_BMSH_MainNegRelayFault.value \
)

#define Rte_IWrite_COL_100ms_BMSH_MainPosRelayFault_BMSH_MainPosRelayFault(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_MainPosRelayFault_BMSH_MainPosRelayFault.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_MainPosRelayFault_BMSH_MainPosRelayFault() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_MainPosRelayFault_BMSH_MainPosRelayFault.value \
)

#define Rte_IWrite_COL_100ms_BMSH_PackCode1_BMSH_PackCode1(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode1_BMSH_PackCode1.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_PackCode1_BMSH_PackCode1() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode1_BMSH_PackCode1.value \
)

#define Rte_IWrite_COL_100ms_BMSH_PackCode1_1_BMSH_PackCode1_1(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode1_1_BMSH_PackCode1_1.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_PackCode1_1_BMSH_PackCode1_1() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode1_1_BMSH_PackCode1_1.value \
)

#define Rte_IWrite_COL_100ms_BMSH_PackCode2_BMSH_PackCode2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode2_BMSH_PackCode2.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_PackCode2_BMSH_PackCode2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode2_BMSH_PackCode2.value \
)

#define Rte_IWrite_COL_100ms_BMSH_PackCode2_1_BMSH_PackCode2_1(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode2_1_BMSH_PackCode2_1.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_PackCode2_1_BMSH_PackCode2_1() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode2_1_BMSH_PackCode2_1.value \
)

#define Rte_IWrite_COL_100ms_BMSH_PackCode3_BMSH_PackCode3(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode3_BMSH_PackCode3.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_PackCode3_BMSH_PackCode3() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode3_BMSH_PackCode3.value \
)

#define Rte_IWrite_COL_100ms_BMSH_PackCode3_1_BMSH_PackCode3_1(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode3_1_BMSH_PackCode3_1.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_PackCode3_1_BMSH_PackCode3_1() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode3_1_BMSH_PackCode3_1.value \
)

#define Rte_IWrite_COL_100ms_BMSH_PackCode4_BMSH_PackCode4(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode4_BMSH_PackCode4.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_PackCode4_BMSH_PackCode4() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode4_BMSH_PackCode4.value \
)

#define Rte_IWrite_COL_100ms_BMSH_PackCode4_1_BMSH_PackCode4_1(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode4_1_BMSH_PackCode4_1.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_PackCode4_1_BMSH_PackCode4_1() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode4_1_BMSH_PackCode4_1.value \
)

#define Rte_IWrite_COL_100ms_BMSH_PackCode5_BMSH_PackCode5(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode5_BMSH_PackCode5.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_PackCode5_BMSH_PackCode5() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode5_BMSH_PackCode5.value \
)

#define Rte_IWrite_COL_100ms_BMSH_PackCode5_1_BMSH_PackCode5_1(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode5_1_BMSH_PackCode5_1.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_PackCode5_1_BMSH_PackCode5_1() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode5_1_BMSH_PackCode5_1.value \
)

#define Rte_IWrite_COL_100ms_BMSH_PackCode6_BMSH_PackCode6(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode6_BMSH_PackCode6.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_PackCode6_BMSH_PackCode6() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode6_BMSH_PackCode6.value \
)

#define Rte_IWrite_COL_100ms_BMSH_PackCode7_BMSH_PackCode7(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode7_BMSH_PackCode7.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_PackCode7_BMSH_PackCode7() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode7_BMSH_PackCode7.value \
)

#define Rte_IWrite_COL_100ms_BMSH_PackCode_ID_BMSH_PackCode_ID(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode_ID_BMSH_PackCode_ID.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_PackCode_ID_BMSH_PackCode_ID() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackCode_ID_BMSH_PackCode_ID.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_PackExtendCd_BMSH_PackExtendCd(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_PackExtendCd_BMSH_PackExtendCd.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_PackExtendCd_BMSH_PackExtendCd() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_PackExtendCd_BMSH_PackExtendCd.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_PackType_BMSH_PackType(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_PackType_BMSH_PackType.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_PackType_BMSH_PackType() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_PackType_BMSH_PackType.value \
)

#define Rte_IWrite_COL_100ms_BMSH_PackVolt_BMSH_PackVolt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackVolt_BMSH_PackVolt.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_PackVolt_BMSH_PackVolt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_PackVolt_BMSH_PackVolt.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag.value \
)

#define Rte_IWrite_COL_100ms_BMSH_RecoveryOverCurrent_BMSH_RecoveryOverCurrent(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_RecoveryOverCurrent_BMSH_RecoveryOverCurrent.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_RecoveryOverCurrent_BMSH_RecoveryOverCurrent() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_RecoveryOverCurrent_BMSH_RecoveryOverCurrent.value \
)

#define Rte_IWrite_COL_100ms_BMSH_SelfCheckFault_BMSH_SelfCheckFault(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_SelfCheckFault_BMSH_SelfCheckFault.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_SelfCheckFault_BMSH_SelfCheckFault() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_SelfCheckFault_BMSH_SelfCheckFault.value \
)

#define Rte_IWrite_COL_100ms_BMSH_StsA_plus_BMSH_StsA_plus(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsA_plus_BMSH_StsA_plus.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_StsA_plus_BMSH_StsA_plus() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsA_plus_BMSH_StsA_plus.value \
)

#define Rte_IWrite_COL_100ms_BMSH_StsCC2_BMSH_StsCC2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsCC2_BMSH_StsCC2.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_StsCC2_BMSH_StsCC2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsCC2_BMSH_StsCC2.value \
)

#define Rte_IWrite_COL_100ms_BMSH_StsCellBalance_BMSH_StsCellBalance(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsCellBalance_BMSH_StsCellBalance.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_StsCellBalance_BMSH_StsCellBalance() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsCellBalance_BMSH_StsCellBalance.value \
)

#define Rte_IWrite_COL_100ms_BMSH_StsChgFault_BMSH_StsChgFault(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsChgFault_BMSH_StsChgFault.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_StsChgFault_BMSH_StsChgFault() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsChgFault_BMSH_StsChgFault.value \
)

#define Rte_IWrite_COL_100ms_BMSH_StsDischgFault_BMSH_StsDischgFault(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsDischgFault_BMSH_StsDischgFault.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_StsDischgFault_BMSH_StsDischgFault() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsDischgFault_BMSH_StsDischgFault.value \
)

#define Rte_IWrite_COL_100ms_BMSH_StsInsulation_BMSH_StsInsulation(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsInsulation_BMSH_StsInsulation.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_StsInsulation_BMSH_StsInsulation() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsInsulation_BMSH_StsInsulation.value \
)

#define Rte_IWrite_COL_100ms_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay.value \
)

#define Rte_IWrite_COL_100ms_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay.value \
)

#define Rte_IWrite_COL_100ms_BMSH_StsMode_BMSH_StsMode(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsMode_BMSH_StsMode.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_StsMode_BMSH_StsMode() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsMode_BMSH_StsMode.value \
)

#define Rte_IWrite_COL_100ms_BMSH_StsPrecharge_BMSH_StsPrecharge(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsPrecharge_BMSH_StsPrecharge.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_StsPrecharge_BMSH_StsPrecharge() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsPrecharge_BMSH_StsPrecharge.value \
)

#define Rte_IWrite_COL_100ms_BMSH_StsWakeUp_BMSH_StsWakeUp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsWakeUp_BMSH_StsWakeUp.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_StsWakeUp_BMSH_StsWakeUp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_StsWakeUp_BMSH_StsWakeUp.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_SubtotalExChgSOE_BMSH_SubtotalExChgSOE(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_SubtotalExChgSOE_BMSH_SubtotalExChgSOE.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_SubtotalExChgSOE_BMSH_SubtotalExChgSOE() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_SubtotalExChgSOE_BMSH_SubtotalExChgSOE.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_SubtotalRecoveryEng_BMSH_SubtotalRecoveryEng(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_SubtotalRecoveryEng_BMSH_SubtotalRecoveryEng.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_SubtotalRecoveryEng_BMSH_SubtotalRecoveryEng() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_SubtotalRecoveryEng_BMSH_SubtotalRecoveryEng.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_SupplyVolt_BMSH_SupplyVolt(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_SupplyVolt_BMSH_SupplyVolt.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_SupplyVolt_BMSH_SupplyVolt() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_SupplyVolt_BMSH_SupplyVolt.value \
)

#define Rte_IWrite_COL_100ms_BMSH_SwapCntOverTemp_BMSH_SwapCntOverTemp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_SwapCntOverTemp_BMSH_SwapCntOverTemp.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_SwapCntOverTemp_BMSH_SwapCntOverTemp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_SwapCntOverTemp_BMSH_SwapCntOverTemp.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatFaultList_BMSH_TBOX_BatFaultList(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatFaultList_BMSH_TBOX_BatFaultList.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatFaultList_BMSH_TBOX_BatFaultList() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatFaultList_BMSH_TBOX_BatFaultList.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatHVILFault_BMSH_TBOX_BatHVILFault(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatHVILFault_BMSH_TBOX_BatHVILFault.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatHVILFault_BMSH_TBOX_BatHVILFault() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatHVILFault_BMSH_TBOX_BatHVILFault.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatIsoAlarm_BMSH_TBOX_BatIsoAlarm(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatIsoAlarm_BMSH_TBOX_BatIsoAlarm.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatIsoAlarm_BMSH_TBOX_BatIsoAlarm() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatIsoAlarm_BMSH_TBOX_BatIsoAlarm.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatLowSOC_BMSH_TBOX_BatLowSOC(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatLowSOC_BMSH_TBOX_BatLowSOC.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatLowSOC_BMSH_TBOX_BatLowSOC() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatLowSOC_BMSH_TBOX_BatLowSOC.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatLowTemp_BMSH_TBOX_BatLowTemp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatLowTemp_BMSH_TBOX_BatLowTemp.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatLowTemp_BMSH_TBOX_BatLowTemp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatLowTemp_BMSH_TBOX_BatLowTemp.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TBOX_BatModuleSum_BMSH_TBOX_BatModuleSum(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatModuleSum_BMSH_TBOX_BatModuleSum.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TBOX_BatModuleSum_BMSH_TBOX_BatModuleSum() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatModuleSum_BMSH_TBOX_BatModuleSum.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatOverCharge_BMSH_TBOX_BatOverCharge(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverCharge_BMSH_TBOX_BatOverCharge.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatOverCharge_BMSH_TBOX_BatOverCharge() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverCharge_BMSH_TBOX_BatOverCharge.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatOverSOC_BMSH_TBOX_BatOverSOC(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverSOC_BMSH_TBOX_BatOverSOC.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatOverSOC_BMSH_TBOX_BatOverSOC() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverSOC_BMSH_TBOX_BatOverSOC.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatOverTemp_BMSH_TBOX_BatOverTemp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverTemp_BMSH_TBOX_BatOverTemp.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatOverTemp_BMSH_TBOX_BatOverTemp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverTemp_BMSH_TBOX_BatOverTemp.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatOverVoltage_BMSH_TBOX_BatOverVoltage(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverVoltage_BMSH_TBOX_BatOverVoltage.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatOverVoltage_BMSH_TBOX_BatOverVoltage() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverVoltage_BMSH_TBOX_BatOverVoltage.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TBOX_BatProductDay_BMSH_TBOX_BatProductDay(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatProductDay_BMSH_TBOX_BatProductDay.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TBOX_BatProductDay_BMSH_TBOX_BatProductDay() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatProductDay_BMSH_TBOX_BatProductDay.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TBOX_BatProductMonth_BMSH_TBOX_BatProductMonth(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatProductMonth_BMSH_TBOX_BatProductMonth.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TBOX_BatProductMonth_BMSH_TBOX_BatProductMonth() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatProductMonth_BMSH_TBOX_BatProductMonth.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TBOX_BatProductYear_BMSH_TBOX_BatProductYear(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatProductYear_BMSH_TBOX_BatProductYear.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TBOX_BatProductYear_BMSH_TBOX_BatProductYear() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatProductYear_BMSH_TBOX_BatProductYear.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TBOX_BatRatedEnergy_BMSH_TBOX_BatRatedEnergy(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatRatedEnergy_BMSH_TBOX_BatRatedEnergy.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TBOX_BatRatedEnergy_BMSH_TBOX_BatRatedEnergy() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatRatedEnergy_BMSH_TBOX_BatRatedEnergy.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TBOX_BatRatedVolt_BMSH_TBOX_BatRatedVolt(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatRatedVolt_BMSH_TBOX_BatRatedVolt.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TBOX_BatRatedVolt_BMSH_TBOX_BatRatedVolt() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatRatedVolt_BMSH_TBOX_BatRatedVolt.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatSeriesCellsSum_BMSH_TBOX_BatSeriesCellsSum(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatSeriesCellsSum_BMSH_TBOX_BatSeriesCellsSum.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatSeriesCellsSum_BMSH_TBOX_BatSeriesCellsSum() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatSeriesCellsSum_BMSH_TBOX_BatSeriesCellsSum.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatStoreSysFault_BMSH_TBOX_BatStoreSysFault(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatStoreSysFault_BMSH_TBOX_BatStoreSysFault.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatStoreSysFault_BMSH_TBOX_BatStoreSysFault() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatStoreSysFault_BMSH_TBOX_BatStoreSysFault.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatTempUniformity_BMSH_TBOX_BatTempUniformity(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatTempUniformity_BMSH_TBOX_BatTempUniformity.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatTempUniformity_BMSH_TBOX_BatTempUniformity() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatTempUniformity_BMSH_TBOX_BatTempUniformity.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TBOX_BatType_BMSH_TBOX_BatType(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatType_BMSH_TBOX_BatType.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TBOX_BatType_BMSH_TBOX_BatType() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_BatType_BMSH_TBOX_BatType.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatUnderVoltage_BMSH_TBOX_BatUnderVoltage(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatUnderVoltage_BMSH_TBOX_BatUnderVoltage.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatUnderVoltage_BMSH_TBOX_BatUnderVoltage() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatUnderVoltage_BMSH_TBOX_BatUnderVoltage.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatUniformity_BMSH_TBOX_BatUniformity(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatUniformity_BMSH_TBOX_BatUniformity.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatUniformity_BMSH_TBOX_BatUniformity() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatUniformity_BMSH_TBOX_BatUniformity.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_CellOverVoltage_BMSH_TBOX_CellOverVoltage(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellOverVoltage_BMSH_TBOX_CellOverVoltage.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_CellOverVoltage_BMSH_TBOX_CellOverVoltage() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellOverVoltage_BMSH_TBOX_CellOverVoltage.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TBOX_CellRatedVolt_BMSH_TBOX_CellRatedVolt(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_CellRatedVolt_BMSH_TBOX_CellRatedVolt.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TBOX_CellRatedVolt_BMSH_TBOX_CellRatedVolt() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_CellRatedVolt_BMSH_TBOX_CellRatedVolt.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_CellUnderVoltage_BMSH_TBOX_CellUnderVoltage(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellUnderVoltage_BMSH_TBOX_CellUnderVoltage.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_CellUnderVoltage_BMSH_TBOX_CellUnderVoltage() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellUnderVoltage_BMSH_TBOX_CellUnderVoltage.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TBOX_HWVer_BMSH_TBOX_HWVer(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_HWVer_BMSH_TBOX_HWVer.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TBOX_HWVer_BMSH_TBOX_HWVer() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_HWVer_BMSH_TBOX_HWVer.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TBOX_HWVer_Test_BMSH_TBOX_HWVer_Test(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_HWVer_Test_BMSH_TBOX_HWVer_Test.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TBOX_HWVer_Test_BMSH_TBOX_HWVer_Test() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_HWVer_Test_BMSH_TBOX_HWVer_Test.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_InsulationResistance_BMSH_TBOX_InsulationResistance(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_InsulationResistance_BMSH_TBOX_InsulationResistance.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_InsulationResistance_BMSH_TBOX_InsulationResistance() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_InsulationResistance_BMSH_TBOX_InsulationResistance.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_SOCHop_BMSH_TBOX_SOCHop(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_SOCHop_BMSH_TBOX_SOCHop.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_SOCHop_BMSH_TBOX_SOCHop() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_SOCHop_BMSH_TBOX_SOCHop.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TBOX_SWVer_BMSH_TBOX_SWVer(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_SWVer_BMSH_TBOX_SWVer.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TBOX_SWVer_BMSH_TBOX_SWVer() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_SWVer_BMSH_TBOX_SWVer.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TBOX_SWVer_Test_BMSH_TBOX_SWVer_Test(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_SWVer_Test_BMSH_TBOX_SWVer_Test.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TBOX_SWVer_Test_BMSH_TBOX_SWVer_Test() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_SWVer_Test_BMSH_TBOX_SWVer_Test.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_TempA_BMSH_TBOX_TempA(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempA_BMSH_TBOX_TempA.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_TempA_BMSH_TBOX_TempA() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempA_BMSH_TBOX_TempA.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_TempB_BMSH_TBOX_TempB(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempB_BMSH_TBOX_TempB.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_TempB_BMSH_TBOX_TempB() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempB_BMSH_TBOX_TempB.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_TempC_BMSH_TBOX_TempC(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempC_BMSH_TBOX_TempC.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_TempC_BMSH_TBOX_TempC() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempC_BMSH_TBOX_TempC.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_TempD_BMSH_TBOX_TempD(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempD_BMSH_TBOX_TempD.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_TempD_BMSH_TBOX_TempD() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempD_BMSH_TBOX_TempD.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_TempE_BMSH_TBOX_TempE(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempE_BMSH_TBOX_TempE.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_TempE_BMSH_TBOX_TempE() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempE_BMSH_TBOX_TempE.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_TempF_BMSH_TBOX_TempF(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempF_BMSH_TBOX_TempF.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_TempF_BMSH_TBOX_TempF() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempF_BMSH_TBOX_TempF.value \
)

#define Rte_IWrite_COL_100ms_BMSH_TBOX_TempF_ID_BMSH_TBOX_TempF_ID(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempF_ID_BMSH_TBOX_TempF_ID.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_TBOX_TempF_ID_BMSH_TBOX_TempF_ID() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_TBOX_TempF_ID_BMSH_TBOX_TempF_ID.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TBOX_TheftFault_BMSH_TBOX_TheftFault(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_TheftFault_BMSH_TBOX_TheftFault.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TBOX_TheftFault_BMSH_TBOX_TheftFault() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TBOX_TheftFault_BMSH_TBOX_TheftFault.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TotalDischgCapacity_BMSH_TotalDischgCapacity(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalDischgCapacity_BMSH_TotalDischgCapacity.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TotalDischgCapacity_BMSH_TotalDischgCapacity() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalDischgCapacity_BMSH_TotalDischgCapacity.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TotalDischgEng_BMSH_TotalDischgEng(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalDischgEng_BMSH_TotalDischgEng.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TotalDischgEng_BMSH_TotalDischgEng() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalDischgEng_BMSH_TotalDischgEng.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TotalExChgCapacity_BMSH_TotalExChgCapacity(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalExChgCapacity_BMSH_TotalExChgCapacity.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TotalExChgCapacity_BMSH_TotalExChgCapacity() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalExChgCapacity_BMSH_TotalExChgCapacity.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TotalExChgEng_BMSH_TotalExChgEng(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalExChgEng_BMSH_TotalExChgEng.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TotalExChgEng_BMSH_TotalExChgEng() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalExChgEng_BMSH_TotalExChgEng.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TotalExChgSOE_BMSH_TotalExChgSOE(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalExChgSOE_BMSH_TotalExChgSOE.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TotalExChgSOE_BMSH_TotalExChgSOE() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalExChgSOE_BMSH_TotalExChgSOE.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TotalOdometer_BMSH_TotalOdometer(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalOdometer_BMSH_TotalOdometer.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TotalOdometer_BMSH_TotalOdometer() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalOdometer_BMSH_TotalOdometer.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TotalOdometerValidFlag_BMSH_TotalOdometerValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalOdometerValidFlag_BMSH_TotalOdometerValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TotalOdometerValidFlag_BMSH_TotalOdometerValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalOdometerValidFlag_BMSH_TotalOdometerValidFlag.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TotalRecoveryCapacity_BMSH_TotalRecoveryCapacity(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalRecoveryCapacity_BMSH_TotalRecoveryCapacity.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TotalRecoveryCapacity_BMSH_TotalRecoveryCapacity() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalRecoveryCapacity_BMSH_TotalRecoveryCapacity.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TotalRecoveryEng_BMSH_TotalRecoveryEng(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalRecoveryEng_BMSH_TotalRecoveryEng.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TotalRecoveryEng_BMSH_TotalRecoveryEng() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TotalRecoveryEng_BMSH_TotalRecoveryEng.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TripOdometer_BMSH_TripOdometer(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TripOdometer_BMSH_TripOdometer.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TripOdometer_BMSH_TripOdometer() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TripOdometer_BMSH_TripOdometer.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_TripOdometerValidFlag_BMSH_TripOdometerValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TripOdometerValidFlag_BMSH_TripOdometerValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_TripOdometerValidFlag_BMSH_TripOdometerValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_TripOdometerValidFlag_BMSH_TripOdometerValidFlag.value \
)

#define Rte_IWrite_COL_100ms_BMSH_VCUChksumFault_BMSH_VCUChksumFault(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCUChksumFault_BMSH_VCUChksumFault.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_VCUChksumFault_BMSH_VCUChksumFault() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCUChksumFault_BMSH_VCUChksumFault.value \
)

#define Rte_IWrite_COL_100ms_BMSH_VCURollCountFault_BMSH_VCURollCountFault(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCURollCountFault_BMSH_VCURollCountFault.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_VCURollCountFault_BMSH_VCURollCountFault() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCURollCountFault_BMSH_VCURollCountFault.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr.value \
)

#define Rte_IWrite_COL_100ms_BMSH_VCU_BatChgContPwr_BMSH_VCU_BatChgContPwr(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCU_BatChgContPwr_BMSH_VCU_BatChgContPwr.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_VCU_BatChgContPwr_BMSH_VCU_BatChgContPwr() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCU_BatChgContPwr_BMSH_VCU_BatChgContPwr.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_VCU_BatChgPeakPwr_BMSH_VCU_BatChgPeakPwr(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_BatChgPeakPwr_BMSH_VCU_BatChgPeakPwr.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_VCU_BatChgPeakPwr_BMSH_VCU_BatChgPeakPwr() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_BatChgPeakPwr_BMSH_VCU_BatChgPeakPwr.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr.value \
)

#define Rte_IWrite_COL_100ms_BMSH_VCU_BatDischgContPwr_BMSH_VCU_BatDischgContPwr(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCU_BatDischgContPwr_BMSH_VCU_BatDischgContPwr.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_VCU_BatDischgContPwr_BMSH_VCU_BatDischgContPwr() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCU_BatDischgContPwr_BMSH_VCU_BatDischgContPwr.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_VCU_BatDischgPeakPwr_BMSH_VCU_BatDischgPeakPwr(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_BatDischgPeakPwr_BMSH_VCU_BatDischgPeakPwr.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_VCU_BatDischgPeakPwr_BMSH_VCU_BatDischgPeakPwr() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_BatDischgPeakPwr_BMSH_VCU_BatDischgPeakPwr.value \
)

#define Rte_IWrite_COL_10ms_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_VCU_ChgSOPRangeUP_BMSH_VCU_ChgSOPRangeUP(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_ChgSOPRangeUP_BMSH_VCU_ChgSOPRangeUP.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_VCU_ChgSOPRangeUP_BMSH_VCU_ChgSOPRangeUP() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_ChgSOPRangeUP_BMSH_VCU_ChgSOPRangeUP.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_VCU_ChgSOPValidFlag_BMSH_VCU_ChgSOPValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_ChgSOPValidFlag_BMSH_VCU_ChgSOPValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_VCU_ChgSOPValidFlag_BMSH_VCU_ChgSOPValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_ChgSOPValidFlag_BMSH_VCU_ChgSOPValidFlag.value \
)

#define Rte_IWrite_COL_10ms_BMSH_VCU_Crash_BMSH_VCU_Crash(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BMSH_VCU_Crash_BMSH_VCU_Crash.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BMSH_VCU_Crash_BMSH_VCU_Crash() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BMSH_VCU_Crash_BMSH_VCU_Crash.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_VCU_DCChgNegTemp_BMSH_VCU_DCChgNegTemp(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_DCChgNegTemp_BMSH_VCU_DCChgNegTemp.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_VCU_DCChgNegTemp_BMSH_VCU_DCChgNegTemp() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_DCChgNegTemp_BMSH_VCU_DCChgNegTemp.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_VCU_DCChgPosTemp_BMSH_VCU_DCChgPosTemp(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_DCChgPosTemp_BMSH_VCU_DCChgPosTemp.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_VCU_DCChgPosTemp_BMSH_VCU_DCChgPosTemp() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_DCChgPosTemp_BMSH_VCU_DCChgPosTemp.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP.value \
)

#define Rte_IWrite_COL_1000ms_BMSH_VCU_DisChgSOPValidFlag_BMSH_VCU_DisChgSOPValidFlag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_DisChgSOPValidFlag_BMSH_VCU_DisChgSOPValidFlag.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMSH_VCU_DisChgSOPValidFlag_BMSH_VCU_DisChgSOPValidFlag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMSH_VCU_DisChgSOPValidFlag_BMSH_VCU_DisChgSOPValidFlag.value \
)

#define Rte_IWrite_COL_10ms_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq.value \
)

#define Rte_IWrite_COL_100ms_BMSH_VCU_StsDCChgPosRelay_BMSH_VCU_StsDCChgPosRelay(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCU_StsDCChgPosRelay_BMSH_VCU_StsDCChgPosRelay.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_VCU_StsDCChgPosRelay_BMSH_VCU_StsDCChgPosRelay() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCU_StsDCChgPosRelay_BMSH_VCU_StsDCChgPosRelay.value \
)

#define Rte_IWrite_COL_100ms_BMSH_VCU_StsDCChgRelay_BMSH_VCU_StsDCChgRelay(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCU_StsDCChgRelay_BMSH_VCU_StsDCChgRelay.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_VCU_StsDCChgRelay_BMSH_VCU_StsDCChgRelay() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCU_StsDCChgRelay_BMSH_VCU_StsDCChgRelay.value \
)

#define Rte_IWrite_COL_100ms_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL.value \
)

#define Rte_IWrite_COL_100ms_BMSH_VCU_StsPreChgRelay_BMSH_VCU_StsPreChgRelay(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCU_StsPreChgRelay_BMSH_VCU_StsPreChgRelay.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMSH_VCU_StsPreChgRelay_BMSH_VCU_StsPreChgRelay() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMSH_VCU_StsPreChgRelay_BMSH_VCU_StsPreChgRelay.value \
)

#define Rte_IWrite_COL_100ms_BMS_B2V_ST1_ChgMode_BMS_B2V_ST1_ChgMode(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_B2V_ST1_ChgMode_BMS_B2V_ST1_ChgMode.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_B2V_ST1_ChgMode_BMS_B2V_ST1_ChgMode() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_B2V_ST1_ChgMode_BMS_B2V_ST1_ChgMode.value \
)

#define Rte_IWrite_COL_100ms_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason.value \
)

#define Rte_IWrite_COL_100ms_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason.value \
)

#define Rte_IWrite_COL_100ms_BMS_BMSStopChgReason_BMS_BMSStopChgReason(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BMSStopChgReason_BMS_BMSStopChgReason.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_BMSStopChgReason_BMS_BMSStopChgReason() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BMSStopChgReason_BMS_BMSStopChgReason.value \
)

#define Rte_IWrite_COL_100ms_BMS_BattCellsNumPN_BMS_BattCellsNumPN(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattCellsNumPN_BMS_BattCellsNumPN.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_BattCellsNumPN_BMS_BattCellsNumPN() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattCellsNumPN_BMS_BattCellsNumPN.value \
)

#define Rte_IWrite_COL_100ms_BMS_BattPackNumSN_BMS_BattPackNumSN(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattPackNumSN_BMS_BattPackNumSN.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_BattPackNumSN_BMS_BattPackNumSN() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattPackNumSN_BMS_BattPackNumSN.value \
)

#define Rte_IWrite_COL_100ms_BMS_BattTemp1_BMS_BattTemp1(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattTemp1_BMS_BattTemp1.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_BattTemp1_BMS_BattTemp1() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattTemp1_BMS_BattTemp1.value \
)

#define Rte_IWrite_COL_100ms_BMS_BattTemp2_BMS_BattTemp2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattTemp2_BMS_BattTemp2.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_BattTemp2_BMS_BattTemp2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattTemp2_BMS_BattTemp2.value \
)

#define Rte_IWrite_COL_100ms_BMS_BattTemp3_BMS_BattTemp3(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattTemp3_BMS_BattTemp3.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_BattTemp3_BMS_BattTemp3() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattTemp3_BMS_BattTemp3.value \
)

#define Rte_IWrite_COL_100ms_BMS_BattTemp4_BMS_BattTemp4(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattTemp4_BMS_BattTemp4.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_BattTemp4_BMS_BattTemp4() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattTemp4_BMS_BattTemp4.value \
)

#define Rte_IWrite_COL_100ms_BMS_BattTemp5_BMS_BattTemp5(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattTemp5_BMS_BattTemp5.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_BattTemp5_BMS_BattTemp5() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattTemp5_BMS_BattTemp5.value \
)

#define Rte_IWrite_COL_100ms_BMS_BattTemp6_BMS_BattTemp6(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattTemp6_BMS_BattTemp6.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_BattTemp6_BMS_BattTemp6() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_BattTemp6_BMS_BattTemp6.value \
)

#define Rte_IWrite_COL_100ms_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason.value \
)

#define Rte_IWrite_COL_100ms_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason.value \
)

#define Rte_IWrite_COL_100ms_BMS_CCUStopChgReason_BMS_CCUStopChgReason(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CCUStopChgReason_BMS_CCUStopChgReason.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_CCUStopChgReason_BMS_CCUStopChgReason() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CCUStopChgReason_BMS_CCUStopChgReason.value \
)

#define Rte_IWrite_COL_100ms_BMS_CCvalue_BMS_CCvalue(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CCvalue_BMS_CCvalue.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_CCvalue_BMS_CCvalue() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CCvalue_BMS_CCvalue.value \
)

#define Rte_IWrite_COL_100ms_BMS_CPLine_S2_Ctrl_BMS_CPLine_S2_Ctrl(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CPLine_S2_Ctrl_BMS_CPLine_S2_Ctrl.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_CPLine_S2_Ctrl_BMS_CPLine_S2_Ctrl() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CPLine_S2_Ctrl_BMS_CPLine_S2_Ctrl.value \
)

#define Rte_IWrite_COL_100ms_BMS_CP_Duty_BMS_CP_Duty(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CP_Duty_BMS_CP_Duty.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_CP_Duty_BMS_CP_Duty() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CP_Duty_BMS_CP_Duty.value \
)

#define Rte_IWrite_COL_100ms_BMS_CP_Vol_BMS_CP_Vol(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CP_Vol_BMS_CP_Vol.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_CP_Vol_BMS_CP_Vol() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CP_Vol_BMS_CP_Vol.value \
)

#define Rte_IWrite_COL_100ms_BMS_CellTempFrameNum_BMS_CellTempFrameNum(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CellTempFrameNum_BMS_CellTempFrameNum.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_CellTempFrameNum_BMS_CellTempFrameNum() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CellTempFrameNum_BMS_CellTempFrameNum.value \
)

#define Rte_IWrite_COL_100ms_BMS_CellVoltFrameNum_BMS_CellVoltFrameNum(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CellVoltFrameNum_BMS_CellVoltFrameNum.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_CellVoltFrameNum_BMS_CellVoltFrameNum() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CellVoltFrameNum_BMS_CellVoltFrameNum.value \
)

#define Rte_IWrite_COL_100ms_BMS_CellVoltN1_BMS_CellVoltN1(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CellVoltN1_BMS_CellVoltN1.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_CellVoltN1_BMS_CellVoltN1() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CellVoltN1_BMS_CellVoltN1.value \
)

#define Rte_IWrite_COL_100ms_BMS_CellVoltN2_BMS_CellVoltN2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CellVoltN2_BMS_CellVoltN2.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_CellVoltN2_BMS_CellVoltN2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CellVoltN2_BMS_CellVoltN2.value \
)

#define Rte_IWrite_COL_100ms_BMS_CellVoltN3_BMS_CellVoltN3(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CellVoltN3_BMS_CellVoltN3.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_CellVoltN3_BMS_CellVoltN3() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CellVoltN3_BMS_CellVoltN3.value \
)

#define Rte_IWrite_COL_10ms_BMS_ChgCCSts_BMS_ChgCCSts(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BMS_ChgCCSts_BMS_ChgCCSts.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BMS_ChgCCSts_BMS_ChgCCSts() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BMS_ChgCCSts_BMS_ChgCCSts.value \
)

#define Rte_IWrite_COL_100ms_BMS_ChgStatus_BMS_ChgStatus(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_ChgStatus_BMS_ChgStatus.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_ChgStatus_BMS_ChgStatus() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_ChgStatus_BMS_ChgStatus.value \
)

#define Rte_IWrite_COL_100ms_BMS_CutOffLVFbToOBC_BMS_CutOffLVFbToOBC(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CutOffLVFbToOBC_BMS_CutOffLVFbToOBC.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_CutOffLVFbToOBC_BMS_CutOffLVFbToOBC() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_CutOffLVFbToOBC_BMS_CutOffLVFbToOBC.value \
)

#define Rte_IWrite_COL_100ms_BMS_DCChargRelayCtrl_BMS_DCChargRelayCtrl(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_DCChargRelayCtrl_BMS_DCChargRelayCtrl.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_DCChargRelayCtrl_BMS_DCChargRelayCtrl() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_DCChargRelayCtrl_BMS_DCChargRelayCtrl.value \
)

#define Rte_IWrite_COL_100ms_BMS_DelayControl_BMS_DelayControl(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_DelayControl_BMS_DelayControl.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_DelayControl_BMS_DelayControl() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_DelayControl_BMS_DelayControl.value \
)

#define Rte_IWrite_COL_100ms_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb.value \
)

#define Rte_IWrite_COL_100ms_BMS_DischargeCCvalue_BMS_DischargeCCvalue(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_DischargeCCvalue_BMS_DischargeCCvalue.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_DischargeCCvalue_BMS_DischargeCCvalue() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_DischargeCCvalue_BMS_DischargeCCvalue.value \
)

#define Rte_IWrite_COL_100ms_BMS_ElectroniclockContorREQ_BMS_ElectroniclockContorREQ(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_ElectroniclockContorREQ_BMS_ElectroniclockContorREQ.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_ElectroniclockContorREQ_BMS_ElectroniclockContorREQ() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_ElectroniclockContorREQ_BMS_ElectroniclockContorREQ.value \
)

#define Rte_IWrite_COL_100ms_BMS_ElectroniclockSts_BMS_ElectroniclockSts(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_ElectroniclockSts_BMS_ElectroniclockSts.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_ElectroniclockSts_BMS_ElectroniclockSts() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_ElectroniclockSts_BMS_ElectroniclockSts.value \
)

#define Rte_IWrite_COL_100ms_BMS_MaxChgCurrent_BMS_MaxChgCurrent(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_MaxChgCurrent_BMS_MaxChgCurrent.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_MaxChgCurrent_BMS_MaxChgCurrent() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_MaxChgCurrent_BMS_MaxChgCurrent.value \
)

#define Rte_IWrite_COL_100ms_BMS_MaxChgVoltage_BMS_MaxChgVoltage(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_MaxChgVoltage_BMS_MaxChgVoltage.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_MaxChgVoltage_BMS_MaxChgVoltage() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_MaxChgVoltage_BMS_MaxChgVoltage.value \
)

#define Rte_IWrite_COL_100ms_BMS_OBCChgContrlCmd_BMS_OBCChgContrlCmd(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_OBCChgContrlCmd_BMS_OBCChgContrlCmd.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_OBCChgContrlCmd_BMS_OBCChgContrlCmd() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_OBCChgContrlCmd_BMS_OBCChgContrlCmd.value \
)

#define Rte_IWrite_COL_100ms_BMS_S2STATUS_BMS_S2STATUS(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_S2STATUS_BMS_S2STATUS.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_S2STATUS_BMS_S2STATUS() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_S2STATUS_BMS_S2STATUS.value \
)

#define Rte_IWrite_COL_50ms_BMS_SlowChgNegTemp_BMS_SlowChgNegTemp(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_BMS_SlowChgNegTemp_BMS_SlowChgNegTemp.value = (data) \
)

#define Rte_IWriteRef_COL_50ms_BMS_SlowChgNegTemp_BMS_SlowChgNegTemp() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_BMS_SlowChgNegTemp_BMS_SlowChgNegTemp.value \
)

#define Rte_IWrite_COL_50ms_BMS_SlowChgPosTemp_BMS_SlowChgPosTemp(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_BMS_SlowChgPosTemp_BMS_SlowChgPosTemp.value = (data) \
)

#define Rte_IWriteRef_COL_50ms_BMS_SlowChgPosTemp_BMS_SlowChgPosTemp() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_BMS_SlowChgPosTemp_BMS_SlowChgPosTemp.value \
)

#define Rte_IWrite_COL_100ms_BMS_SysCodeBattPackSN_1_BMS_SysCodeBattPackSN_1(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_SysCodeBattPackSN_1_BMS_SysCodeBattPackSN_1.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_SysCodeBattPackSN_1_BMS_SysCodeBattPackSN_1() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_SysCodeBattPackSN_1_BMS_SysCodeBattPackSN_1.value \
)

#define Rte_IWrite_COL_100ms_BMS_SysCodeFrameNum_1_BMS_SysCodeFrameNum_1(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_SysCodeFrameNum_1_BMS_SysCodeFrameNum_1.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_SysCodeFrameNum_1_BMS_SysCodeFrameNum_1() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_SysCodeFrameNum_1_BMS_SysCodeFrameNum_1.value \
)

#define Rte_IWrite_COL_100ms_BMS_SysCodeLength_1_BMS_SysCodeLength_1(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_SysCodeLength_1_BMS_SysCodeLength_1.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_SysCodeLength_1_BMS_SysCodeLength_1() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_SysCodeLength_1_BMS_SysCodeLength_1.value \
)

#define Rte_IWrite_COL_100ms_BMS_TempCSCNum_BMS_TempCSCNum(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_TempCSCNum_BMS_TempCSCNum.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_TempCSCNum_BMS_TempCSCNum() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_TempCSCNum_BMS_TempCSCNum.value \
)

#define Rte_IWrite_COL_100ms_BMS_TempSnsNumPN_BMS_TempSnsNumPN(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_TempSnsNumPN_BMS_TempSnsNumPN.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_TempSnsNumPN_BMS_TempSnsNumPN() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_TempSnsNumPN_BMS_TempSnsNumPN.value \
)

#define Rte_IWrite_COL_1000ms_BMS_VCU_ChrgFullCalRemind_BMS_VCU_ChrgFullCalRemind(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMS_VCU_ChrgFullCalRemind_BMS_VCU_ChrgFullCalRemind.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMS_VCU_ChrgFullCalRemind_BMS_VCU_ChrgFullCalRemind() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMS_VCU_ChrgFullCalRemind_BMS_VCU_ChrgFullCalRemind.value \
)

#define Rte_IWrite_COL_1000ms_BMS_VCU_ChrgModeAct_BMS_VCU_ChrgModeAct(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMS_VCU_ChrgModeAct_BMS_VCU_ChrgModeAct.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMS_VCU_ChrgModeAct_BMS_VCU_ChrgModeAct() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMS_VCU_ChrgModeAct_BMS_VCU_ChrgModeAct.value \
)

#define Rte_IWrite_COL_1000ms_BMS_VCU_ChrgModeCalRemind_BMS_VCU_ChrgModeCalRemind(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMS_VCU_ChrgModeCalRemind_BMS_VCU_ChrgModeCalRemind.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMS_VCU_ChrgModeCalRemind_BMS_VCU_ChrgModeCalRemind() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMS_VCU_ChrgModeCalRemind_BMS_VCU_ChrgModeCalRemind.value \
)

#define Rte_IWrite_COL_1000ms_BMS_VCU_ChrgModeEn_BMS_VCU_ChrgModeEn(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMS_VCU_ChrgModeEn_BMS_VCU_ChrgModeEn.value = (data) \
)

#define Rte_IWriteRef_COL_1000ms_BMS_VCU_ChrgModeEn_BMS_VCU_ChrgModeEn() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BMS_VCU_ChrgModeEn_BMS_VCU_ChrgModeEn.value \
)

#define Rte_IWrite_COL_100ms_BMS_VoltCellNum_BMS_VoltCellNum(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_VoltCellNum_BMS_VoltCellNum.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_VoltCellNum_BMS_VoltCellNum() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_VoltCellNum_BMS_VoltCellNum.value \
)

#define Rte_IWrite_COL_100ms_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req.value \
)

#define Rte_IRead_COL_100ms_BPIU_ErrCellU_BPIU_ErrCellU() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_ErrCellU_BPIU_ErrCellU.value)

#define Rte_IRead_COL_100ms_BPIU_ErrCellUDif_BPIU_ErrCellUDif() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_ErrCellUDif_BPIU_ErrCellUDif.value)

#define Rte_IRead_COL_100ms_BPIU_ErrCellUOver_BPIU_ErrCellUOver() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_ErrCellUOver_BPIU_ErrCellUOver.value)

#define Rte_IRead_COL_100ms_BPIU_ErrIChLim_BPIU_ErrIChLim() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_ErrIChLim_BPIU_ErrIChLim.value)

#define Rte_IRead_COL_100ms_BPIU_ErrIRgnOvcur_BPIU_ErrIRgnOvcur() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_ErrIRgnOvcur_BPIU_ErrIRgnOvcur.value)

#define Rte_IRead_COL_100ms_BPIU_ErrInfo_BPIU_ErrInfo() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_ErrInfo_BPIU_ErrInfo.value)

#define Rte_IRead_COL_100ms_BPIU_ErrPackSnsrI_BPIU_ErrPackSnsrI() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_ErrPackSnsrI_BPIU_ErrPackSnsrI.value)

#define Rte_IRead_COL_100ms_BPIU_ErrUAcqn_BPIU_ErrUAcqn() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_ErrUAcqn_BPIU_ErrUAcqn.value)

#define Rte_IRead_COL_1000ms_BPIU_IdCellUMax_BPIU_IdCellUMax() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BPIU_IdCellUMax_BPIU_IdCellUMax.value)

#define Rte_IRead_COL_100ms_BPIU_IdCellUMax_BPIU_IdCellUMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_IdCellUMax_BPIU_IdCellUMax.value)

#define Rte_IRead_COL_1000ms_BPIU_IdCellUMin_BPIU_IdCellUMin() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BPIU_IdCellUMin_BPIU_IdCellUMin.value)

#define Rte_IRead_COL_1000ms_BPIU_UCellMax_BPIU_UCellMax() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BPIU_UCellMax_BPIU_UCellMax.value)

#define Rte_IRead_COL_100ms_BPIU_UCellMax_BPIU_UCellMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_UCellMax_BPIU_UCellMax.value)

#define Rte_IRead_COL_1000ms_BPIU_UCellMin_BPIU_UCellMin() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BPIU_UCellMin_BPIU_UCellMin.value)

#define Rte_IRead_COL_100ms_BPIU_UCellMin_BPIU_UCellMin() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPIU_UCellMin_BPIU_UCellMin.value)

#define Rte_IRead_COL_100ms_BPP_ErrCellT_BPP_ErrCellT() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPP_ErrCellT_BPP_ErrCellT.value)

#define Rte_IRead_COL_100ms_BPP_ErrInfo_BPP_ErrInfo() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPP_ErrInfo_BPP_ErrInfo.value)

#define Rte_IRead_COL_100ms_BPP_ErrPackU_BPP_ErrPackU() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPP_ErrPackU_BPP_ErrPackU.value)

#define Rte_IRead_COL_100ms_BPP_ErrSocVal_BPP_ErrSocVal() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BPP_ErrSocVal_BPP_ErrSocVal.value)

#define Rte_IRead_COL_100ms_BSOF_AcvChManSuspd_BSOF_AcvChManSuspd() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_AcvChManSuspd_BSOF_AcvChManSuspd.value)

#define Rte_IRead_COL_100ms_BSOF_AcvChSuspdByBms_BSOF_AcvChSuspdByBms() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_AcvChSuspdByBms_BSOF_AcvChSuspdByBms.value)

#define Rte_IRead_COL_100ms_BSOF_AcvChSuspdCdnRchd_BSOF_AcvChSuspdCdnRchd() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_AcvChSuspdCdnRchd_BSOF_AcvChSuspdCdnRchd.value)

#define Rte_IRead_COL_100ms_BSOF_AcvChSuspdFlt_BSOF_AcvChSuspdFlt() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_AcvChSuspdFlt_BSOF_AcvChSuspdFlt.value)

#define Rte_IRead_COL_1000ms_BSOF_EChSng_BSOF_EChSng() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BSOF_EChSng_BSOF_EChSng.value)

#define Rte_IRead_COL_100ms_BSOF_ErrChImpo_BSOF_ErrChImpo() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_ErrChImpo_BSOF_ErrChImpo.value)

#define Rte_IRead_COL_100ms_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt.value)

#define Rte_IRead_COL_100ms_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt.value)

#define Rte_IRead_COL_100ms_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt.value)

#define Rte_IRead_COL_100ms_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy.value)

#define Rte_IRead_COL_100ms_BSOF_ErrIDe_BSOF_ErrIDe() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_ErrIDe_BSOF_ErrIDe.value)

#define Rte_IRead_COL_100ms_BSOF_ErrUAbno_BSOF_ErrUAbno() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_ErrUAbno_BSOF_ErrUAbno.value)

#define Rte_IRead_COL_100ms_BSOF_ErrUndfnd_BSOF_ErrUndfnd() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_ErrUndfnd_BSOF_ErrUndfnd.value)

#define Rte_IRead_COL_1000ms_BSOF_IChrgr_BSOF_IChrgr() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BSOF_IChrgr_BSOF_IChrgr.value)

#define Rte_IRead_COL_1000ms_BSOF_UChrgr_BSOF_UChrgr() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BSOF_UChrgr_BSOF_UChrgr.value)

#define Rte_IRead_COL_100ms_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg.value)

#define Rte_IRead_COL_100ms_BSTC_ModeBmsAcvn_BSTC_ModeBmsAcvn() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSTC_ModeBmsAcvn_BSTC_ModeBmsAcvn.value)

#define Rte_IRead_COL_100ms_BSTC_ReqEmcyHvOffFromBms_BSTC_ReqEmcyHvOffFromBms() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSTC_ReqEmcyHvOffFromBms_BSTC_ReqEmcyHvOffFromBms.value)

#define Rte_IRead_COL_50ms_BSTC_ReqShtdnBas_BSTC_ReqShtdnBas() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_BSTC_ReqShtdnBas_BSTC_ReqShtdnBas.value)

#define Rte_IRead_COL_100ms_BSTC_StBcu_BSTC_StBcu() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSTC_StBcu_BSTC_StBcu.value)

#define Rte_IRead_COL_100ms_BSTC_StBcuInt_BSTC_StBcuInt() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSTC_StBcuInt_BSTC_StBcuInt.value)

#define Rte_IRead_COL_100ms_BSTC_StBmsChk_BSTC_StBmsChk() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSTC_StBmsChk_BSTC_StBmsChk.value)

#define Rte_IRead_COL_100ms_BSTC_bAcvCutoffLvFromBms_BSTC_bAcvCutoffLvFromBms() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSTC_bAcvCutoffLvFromBms_BSTC_bAcvCutoffLvFromBms.value)

#define Rte_IRead_COL_100ms_BSTC_bAcvObcOff_BSTC_bAcvObcOff() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSTC_bAcvObcOff_BSTC_bAcvObcOff.value)

#define Rte_IWrite_COL_10ms_BSWControl_RstDiagGlb_RstDiagGlb(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BSWControl_RstDiagGlb_RstDiagGlb.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BSWControl_RstDiagGlb_RstDiagGlb() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BSWControl_RstDiagGlb_RstDiagGlb.value \
)

#define Rte_IWrite_COL_50ms_BSWIOSP_Mode_Request_shutdown_Request_shutdown(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_BSWIOSP_Mode_Request_shutdown_Request_shutdown.value = (data) \
)

#define Rte_IWriteRef_COL_50ms_BSWIOSP_Mode_Request_shutdown_Request_shutdown() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_BSWIOSP_Mode_Request_shutdown_Request_shutdown.value \
)

#define Rte_IWrite_COL_10ms_BSWIOSP_Request_BCL_Request_BCL(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BSWIOSP_Request_BCL_Request_BCL.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BSWIOSP_Request_BCL_Request_BCL() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BSWIOSP_Request_BCL_Request_BCL.value \
)

#define Rte_IWrite_COL_100ms_BSWIOSP_Request_BCP_Request_BCP(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BCP_Request_BCP.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BSWIOSP_Request_BCP_Request_BCP() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BCP_Request_BCP.value \
)

#define Rte_IWrite_COL_100ms_BSWIOSP_Request_BCPP_Request_BCPP(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BCPP_Request_BCPP.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BSWIOSP_Request_BCPP_Request_BCPP() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BCPP_Request_BCPP.value \
)

#define Rte_IWrite_COL_100ms_BSWIOSP_Request_BCS_Request_BCS(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BCS_Request_BCS.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BSWIOSP_Request_BCS_Request_BCS() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BCS_Request_BCS.value \
)

#define Rte_IWrite_COL_100ms_BSWIOSP_Request_BCSP_Request_BCSP(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BCSP_Request_BCSP.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BSWIOSP_Request_BCSP_Request_BCSP() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BCSP_Request_BCSP.value \
)

#define Rte_IWrite_COL_100ms_BSWIOSP_Request_BDC_Request_BDC(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BDC_Request_BDC.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BSWIOSP_Request_BDC_Request_BDC() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BDC_Request_BDC.value \
)

#define Rte_IWrite_COL_100ms_BSWIOSP_Request_BEM_Request_BEM(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BEM_Request_BEM.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BSWIOSP_Request_BEM_Request_BEM() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BEM_Request_BEM.value \
)

#define Rte_IWrite_COL_100ms_BSWIOSP_Request_BHM_Request_BHM(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BHM_Request_BHM.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BSWIOSP_Request_BHM_Request_BHM() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BHM_Request_BHM.value \
)

#define Rte_IWrite_COL_100ms_BSWIOSP_Request_BMS_FastChgStopInfo_Request_BMS_FastChgStopInfo(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BMS_FastChgStopInfo_Request_BMS_FastChgStopInfo.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BSWIOSP_Request_BMS_FastChgStopInfo_Request_BMS_FastChgStopInfo() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BMS_FastChgStopInfo_Request_BMS_FastChgStopInfo.value \
)

#define Rte_IWrite_COL_10ms_BSWIOSP_Request_BMT_Request_BMT(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BSWIOSP_Request_BMT_Request_BMT.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BSWIOSP_Request_BMT_Request_BMT() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BSWIOSP_Request_BMT_Request_BMT.value \
)

#define Rte_IWrite_COL_10ms_BSWIOSP_Request_BMV_Request_BMV(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BSWIOSP_Request_BMV_Request_BMV.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BSWIOSP_Request_BMV_Request_BMV() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BSWIOSP_Request_BMV_Request_BMV.value \
)

#define Rte_IWrite_COL_100ms_BSWIOSP_Request_BRM_Request_BRM(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BRM_Request_BRM.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BSWIOSP_Request_BRM_Request_BRM() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BRM_Request_BRM.value \
)

#define Rte_IWrite_COL_100ms_BSWIOSP_Request_BRO_Request_BRO(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BRO_Request_BRO.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BSWIOSP_Request_BRO_Request_BRO() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BRO_Request_BRO.value \
)

#define Rte_IWrite_COL_100ms_BSWIOSP_Request_BSD_Request_BSD(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BSD_Request_BSD.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BSWIOSP_Request_BSD_Request_BSD() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BSD_Request_BSD.value \
)

#define Rte_IWrite_COL_100ms_BSWIOSP_Request_BSM_Request_BSM(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BSM_Request_BSM.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BSWIOSP_Request_BSM_Request_BSM() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BSWIOSP_Request_BSM_Request_BSM.value \
)

#define Rte_IWrite_COL_10ms_BSWIOSP_Request_BSP_Request_BSP(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BSWIOSP_Request_BSP_Request_BSP.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BSWIOSP_Request_BSP_Request_BSP() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BSWIOSP_Request_BSP_Request_BSP.value \
)

#define Rte_IWrite_COL_10ms_BSWIOSP_Request_BST_Request_BST(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BSWIOSP_Request_BST_Request_BST.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BSWIOSP_Request_BST_Request_BST() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BSWIOSP_Request_BST_Request_BST.value \
)

#define Rte_IRead_COL_10ms_BTHM_ErrChEnd_BTHM_ErrChEnd() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BTHM_ErrChEnd_BTHM_ErrChEnd.value)

#define Rte_IRead_COL_100ms_BTHM_ErrInfo_BTHM_ErrInfo() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_ErrInfo_BTHM_ErrInfo.value)

#define Rte_IRead_COL_1000ms_BTHM_IdCellTMax_BTHM_IdCellTMax() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BTHM_IdCellTMax_BTHM_IdCellTMax.value)

#define Rte_IRead_COL_100ms_BTHM_IdCellTMax_BTHM_IdCellTMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_IdCellTMax_BTHM_IdCellTMax.value)

#define Rte_IRead_COL_1000ms_BTHM_IdCellTMin_BTHM_IdCellTMin() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BTHM_IdCellTMin_BTHM_IdCellTMin.value)

#define Rte_IRead_COL_100ms_BTHM_IdCellTMin_BTHM_IdCellTMin() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_IdCellTMin_BTHM_IdCellTMin.value)

#define Rte_IRead_COL_100ms_BTHM_StSys_BTHM_StSys() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_StSys_BTHM_StSys.value)

#define Rte_IRead_COL_100ms_BTHM_StThermReq_BTHM_StThermReq() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_StThermReq_BTHM_StThermReq.value)

#define Rte_IRead_COL_100ms_BTHM_TBatTgt_BTHM_TBatTgt() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_TBatTgt_BTHM_TBatTgt.value)

#define Rte_IRead_COL_100ms_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr.value)

#define Rte_IRead_COL_100ms_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr.value)

#define Rte_IRead_COL_1000ms_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value)

#define Rte_IRead_COL_100ms_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value)

#define Rte_IRead_COL_1000ms_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value)

#define Rte_IRead_COL_100ms_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value)

#define Rte_IRead_COL_1000ms_BTHM_TOptmMax_BTHM_TOptmMax() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BTHM_TOptmMax_BTHM_TOptmMax.value)

#define Rte_IRead_COL_100ms_BTHM_TOptmMax_BTHM_TOptmMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_TOptmMax_BTHM_TOptmMax.value)

#define Rte_IRead_COL_1000ms_BTHM_TOptmMin_BTHM_TOptmMin() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BTHM_TOptmMin_BTHM_TOptmMin.value)

#define Rte_IRead_COL_1000ms_BTHM_TPack_BTHM_TPack() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BTHM_TPack_BTHM_TPack.value)

#define Rte_IRead_COL_100ms_BTHM_bAcvDig93_BTHM_bAcvDig93() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BTHM_bAcvDig93_BTHM_bAcvDig93.value)

#define Rte_IRead_COL_1000ms_BWLD_CBatChTot_BWLD_CBatChTot() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BWLD_CBatChTot_BWLD_CBatChTot.value)

#define Rte_IRead_COL_1000ms_BWLD_CBatDchaTot_BWLD_CBatDchaTot() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BWLD_CBatDchaTot_BWLD_CBatDchaTot.value)

#define Rte_IRead_COL_1000ms_BWLD_CBatRecoveryTot_BWLD_CBatRecoveryTot() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BWLD_CBatRecoveryTot_BWLD_CBatRecoveryTot.value)

#define Rte_IRead_COL_1000ms_BWLD_CtrCh_BWLD_CtrCh() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BWLD_CtrCh_BWLD_CtrCh.value)

#define Rte_IRead_COL_100ms_BWLD_CtrDcha_BWLD_CtrDcha() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BWLD_CtrDcha_BWLD_CtrDcha.value)

#define Rte_IRead_COL_100ms_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax.value)

#define Rte_IRead_COL_1000ms_BWLD_EBatChTot_BWLD_EBatChTot() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BWLD_EBatChTot_BWLD_EBatChTot.value)

#define Rte_IRead_COL_1000ms_BWLD_EBatDchaDrvCyc_BWLD_EBatDchaDrvCyc() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BWLD_EBatDchaDrvCyc_BWLD_EBatDchaDrvCyc.value)

#define Rte_IRead_COL_1000ms_BWLD_EBatDchaTot_BWLD_EBatDchaTot() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BWLD_EBatDchaTot_BWLD_EBatDchaTot.value)

#define Rte_IRead_COL_1000ms_BWLD_EBatRecoveryDrvCyc_BWLD_EBatRecoveryDrvCyc() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BWLD_EBatRecoveryDrvCyc_BWLD_EBatRecoveryDrvCyc.value)

#define Rte_IRead_COL_1000ms_BWLD_EBatRecoveryTot_BWLD_EBatRecoveryTot() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_BWLD_EBatRecoveryTot_BWLD_EBatRecoveryTot.value)

#define Rte_IWrite_COL_100ms_BatteryChargingOvercurrent_BatteryChargingOvercurrent(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryChargingOvercurrent_BatteryChargingOvercurrent.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BatteryChargingOvercurrent_BatteryChargingOvercurrent() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryChargingOvercurrent_BatteryChargingOvercurrent.value \
)

#define Rte_IWrite_COL_100ms_BatteryExcessTemperature_BatteryExcessTemperature(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryExcessTemperature_BatteryExcessTemperature.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BatteryExcessTemperature_BatteryExcessTemperature() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryExcessTemperature_BatteryExcessTemperature.value \
)

#define Rte_IWrite_COL_100ms_BatteryHighestTemp_BatteryHighestTemp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryHighestTemp_BatteryHighestTemp.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BatteryHighestTemp_BatteryHighestTemp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryHighestTemp_BatteryHighestTemp.value \
)

#define Rte_IWrite_COL_100ms_BatteryHighestTempSerNo_BatteryHighestTempSerNo(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryHighestTempSerNo_BatteryHighestTempSerNo.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BatteryHighestTempSerNo_BatteryHighestTempSerNo() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryHighestTempSerNo_BatteryHighestTempSerNo.value \
)

#define Rte_IWrite_COL_100ms_BatteryInsulationState_BatteryInsulationState(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryInsulationState_BatteryInsulationState.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BatteryInsulationState_BatteryInsulationState() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryInsulationState_BatteryInsulationState.value \
)

#define Rte_IWrite_COL_100ms_BatteryLowestTemp_BatteryLowestTemp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryLowestTemp_BatteryLowestTemp.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BatteryLowestTemp_BatteryLowestTemp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryLowestTemp_BatteryLowestTemp.value \
)

#define Rte_IWrite_COL_100ms_BatteryLowestTempSerNo_BatteryLowestTempSerNo(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryLowestTempSerNo_BatteryLowestTempSerNo.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BatteryLowestTempSerNo_BatteryLowestTempSerNo() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryLowestTempSerNo_BatteryLowestTempSerNo.value \
)

#define Rte_IWrite_COL_100ms_BatteryOutputConnectorState_BatteryOutputConnectorState(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryOutputConnectorState_BatteryOutputConnectorState.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BatteryOutputConnectorState_BatteryOutputConnectorState() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryOutputConnectorState_BatteryOutputConnectorState.value \
)

#define Rte_IWrite_COL_Init_BatteryOutputConnectorState_BatteryOutputConnectorState(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BatteryOutputConnectorState_BatteryOutputConnectorState.value = (data) \
)

#define Rte_IWriteRef_COL_Init_BatteryOutputConnectorState_BatteryOutputConnectorState() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BatteryOutputConnectorState_BatteryOutputConnectorState.value \
)

#define Rte_IWrite_COL_100ms_BatterySystemCapacity_BatterySystemCapacity(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatterySystemCapacity_BatterySystemCapacity.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BatterySystemCapacity_BatterySystemCapacity() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatterySystemCapacity_BatterySystemCapacity.value \
)

#define Rte_IWrite_COL_100ms_BatterySystemVoltage_BatterySystemVoltage(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatterySystemVoltage_BatterySystemVoltage.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BatterySystemVoltage_BatterySystemVoltage() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatterySystemVoltage_BatterySystemVoltage.value \
)

#define Rte_IWrite_COL_100ms_BatteryType_BatteryType(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryType_BatteryType.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BatteryType_BatteryType() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BatteryType_BatteryType.value \
)

#define Rte_IWrite_COL_Init_BatteryType_BatteryType(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BatteryType_BatteryType.value = (data) \
)

#define Rte_IWriteRef_COL_Init_BatteryType_BatteryType() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BatteryType_BatteryType.value \
)

#define Rte_IWrite_COL_100ms_BmsReadyForCharging_BmsReadyForCharging(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BmsReadyForCharging_BmsReadyForCharging.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BmsReadyForCharging_BmsReadyForCharging() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BmsReadyForCharging_BmsReadyForCharging.value \
)

#define Rte_IWrite_COL_100ms_BmsRevision_BmsRevision(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BmsRevision_BmsRevision.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BmsRevision_BmsRevision() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BmsRevision_BmsRevision.value \
)

#define Rte_IWrite_COL_Init_BmsRevision_BmsRevision(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BmsRevision_BmsRevision.value = (data) \
)

#define Rte_IWriteRef_COL_Init_BmsRevision_BmsRevision() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BmsRevision_BmsRevision.value \
)

#define Rte_IWrite_COL_10ms_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend.value \
)

#define Rte_IWrite_COL_10ms_BmsSuspCause_SOC_BmsSuspCause_SOC(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspCause_SOC_BmsSuspCause_SOC.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BmsSuspCause_SOC_BmsSuspCause_SOC() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspCause_SOC_BmsSuspCause_SOC.value \
)

#define Rte_IWrite_COL_10ms_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage.value \
)

#define Rte_IWrite_COL_10ms_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage.value \
)

#define Rte_IWrite_COL_10ms_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage.value \
)

#define Rte_IWrite_COL_10ms_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent.value \
)

#define Rte_IWrite_COL_10ms_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp.value \
)

#define Rte_IWrite_COL_10ms_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp.value \
)

#define Rte_IWrite_COL_10ms_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn.value \
)

#define Rte_IWrite_COL_10ms_BmsSuspFault_Insulation_BmsSuspFault_Insulation(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_Insulation_BmsSuspFault_Insulation.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BmsSuspFault_Insulation_BmsSuspFault_Insulation() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_Insulation_BmsSuspFault_Insulation.value \
)

#define Rte_IWrite_COL_10ms_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults.value \
)

#define Rte_IWrite_COL_10ms_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp.value \
)

#define Rte_IWrite_COL_10ms_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection.value \
)

#define Rte_IWrite_COL_10ms_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay.value \
)

#define Rte_IWrite_COL_100ms_BmsVersion_BmsVersion(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BmsVersion_BmsVersion.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BmsVersion_BmsVersion() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BmsVersion_BmsVersion.value \
)

#define Rte_IWrite_COL_Init_BmsVersion_BmsVersion(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BmsVersion_BmsVersion.value = (data) \
)

#define Rte_IWriteRef_COL_Init_BmsVersion_BmsVersion() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_COL_COL_Init.Rte_BmsVersion_BmsVersion.value \
)

#define Rte_IWrite_COL_50ms_BmuControl_BalanceControl_BalanceControl(data) \
  RteIWrite_COL_50ms_BmuControl_BalanceControl_BalanceControl(data)

#define RteIWrite_COL_50ms_BmuControl_BalanceControl_BalanceControl(data) \
( \
  Rte_MemCpy(Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_BmuControl_BalanceControl_BalanceControl.value, data, sizeof(rt_Array_UInt32_9)) \
)

#define Rte_IWriteRef_COL_50ms_BmuControl_BalanceControl_BalanceControl() \
  (&((*RteIWriteRef_COL_50ms_BmuControl_BalanceControl_BalanceControl())[0]))

#define RteIWriteRef_COL_50ms_BmuControl_BalanceControl_BalanceControl() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_BmuControl_BalanceControl_BalanceControl.value \
)

#define Rte_IWrite_COL_100ms_BsmChargingPermissible_BsmChargingPermissible(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BsmChargingPermissible_BsmChargingPermissible.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_BsmChargingPermissible_BsmChargingPermissible() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_BsmChargingPermissible_BsmChargingPermissible.value \
)

#define Rte_IRead_COL_50ms_CIL_ActInputVolt_CIL_ActInputVolt() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_CIL_ActInputVolt_CIL_ActInputVolt.value)

#define Rte_IRead_COL_1000ms_CIL_BatCoolType_CIL_BatCoolType() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_BatCoolType_CIL_BatCoolType.value)

#define Rte_IRead_COL_100ms_CIL_CP_Vol_CIL_CP_Vol() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_CP_Vol_CIL_CP_Vol.value)

#define Rte_IRead_COL_1000ms_CIL_ChargeModeReq_CIL_ChargeModeReq() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_ChargeModeReq_CIL_ChargeModeReq.value)

#define Rte_IRead_COL_100ms_CIL_DucycCtlPilot_CIL_DucycCtlPilot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_DucycCtlPilot_CIL_DucycCtlPilot.value)

#define Rte_IRead_COL_100ms_CIL_ErrInfoBSW_CIL_ErrInfoBSW() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_ErrInfoBSW_CIL_ErrInfoBSW.value)

#define Rte_IRead_COL_1000ms_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl.value)

#define Rte_IRead_COL_1000ms_CIL_HWVerVeh_CIL_HWVerVeh() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_HWVerVeh_CIL_HWVerVeh.value)

#define Rte_IRead_COL_100ms_CIL_IBatHv_CIL_IBatHv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_IBatHv_CIL_IBatHv.value)

#define Rte_IRead_COL_1000ms_CIL_MilgTot_CIL_MilgTot() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_MilgTot_CIL_MilgTot.value)

#define Rte_IRead_COL_100ms_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline.value)

#define Rte_IRead_COL_100ms_CIL_RAcChCnctnResRaw_CIL_RAcChCnctnResRaw() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_RAcChCnctnResRaw_CIL_RAcChCnctnResRaw.value)

#define Rte_IRead_COL_100ms_CIL_RngElec_CIL_RngElec() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_RngElec_CIL_RngElec.value)

#define Rte_IRead_COL_1000ms_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl.value)

#define Rte_IRead_COL_1000ms_CIL_SWVerVeh_CIL_SWVerVeh() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_SWVerVeh_CIL_SWVerVeh.value)

#define Rte_IRead_COL_10ms_CIL_StAcChCnct_CIL_StAcChCnct() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_CIL_StAcChCnct_CIL_StAcChCnct.value)

#define Rte_IRead_COL_10ms_CIL_StChAllwd_CIL_StChAllwd() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_CIL_StChAllwd_CIL_StChAllwd.value)

#define Rte_IRead_COL_100ms_CIL_StChWup_CIL_StChWup() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_StChWup_CIL_StChWup.value)

#define Rte_IRead_COL_50ms_CIL_TAcChPointNeg_CIL_TAcChPointNeg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_CIL_TAcChPointNeg_CIL_TAcChPointNeg.value)

#define Rte_IRead_COL_50ms_CIL_TAcChPointPos_CIL_TAcChPointPos() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_CIL_TAcChPointPos_CIL_TAcChPointPos.value)

#define Rte_IRead_COL_1000ms_CIL_TDcChPointNeg_CIL_TDcChPointNeg() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_TDcChPointNeg_CIL_TDcChPointNeg.value)

#define Rte_IRead_COL_1000ms_CIL_TDcChPointPos_CIL_TDcChPointPos() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_TDcChPointPos_CIL_TDcChPointPos.value)

#define Rte_IRead_COL_100ms_CIL_TMdul_CIL_TMdul() \
  (&((*RteIRead_COL_100ms_CIL_TMdul_CIL_TMdul())[0]))

#define RteIRead_COL_100ms_CIL_TMdul_CIL_TMdul() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_TMdul_CIL_TMdul.value)

#define Rte_IRead_COL_100ms_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value)

#define Rte_IRead_COL_1000ms_CIL_UTrml30_CIL_UTrml30() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_CIL_UTrml30_CIL_UTrml30.value)

#define Rte_IRead_COL_100ms_CTC_ErrInfo_CTC_ErrInfo() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_ErrInfo_CTC_ErrInfo.value)

#define Rte_IRead_COL_100ms_CTC_ErrRlyCh_CTC_ErrRlyCh() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_ErrRlyCh_CTC_ErrRlyCh.value)

#define Rte_IRead_COL_100ms_CTC_ErrRlyHeat_CTC_ErrRlyHeat() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_ErrRlyHeat_CTC_ErrRlyHeat.value)

#define Rte_IRead_COL_100ms_CTC_ErrRlyNeg_CTC_ErrRlyNeg() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_ErrRlyNeg_CTC_ErrRlyNeg.value)

#define Rte_IRead_COL_100ms_CTC_ErrRlyPos_CTC_ErrRlyPos() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_ErrRlyPos_CTC_ErrRlyPos.value)

#define Rte_IRead_COL_100ms_CTC_ErrRlyPrech_CTC_ErrRlyPrech() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_ErrRlyPrech_CTC_ErrRlyPrech.value)

#define Rte_IRead_COL_100ms_CTC_ReqRlyCh_CTC_ReqRlyCh() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_ReqRlyCh_CTC_ReqRlyCh.value)

#define Rte_IRead_COL_50ms_CTC_ReqRlyHeat_CTC_ReqRlyHeat() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_CTC_ReqRlyHeat_CTC_ReqRlyHeat.value)

#define Rte_IRead_COL_50ms_CTC_ReqRlyNeg_CTC_ReqRlyNeg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_CTC_ReqRlyNeg_CTC_ReqRlyNeg.value)

#define Rte_IRead_COL_50ms_CTC_ReqRlyPos_CTC_ReqRlyPos() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_CTC_ReqRlyPos_CTC_ReqRlyPos.value)

#define Rte_IRead_COL_100ms_CTC_ReqZeroPwr_CTC_ReqZeroPwr() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_ReqZeroPwr_CTC_ReqZeroPwr.value)

#define Rte_IRead_COL_100ms_CTC_StHvbat_CTC_StHvbat() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_StHvbat_CTC_StHvbat.value)

#define Rte_IRead_COL_100ms_CTC_StLoopHv_CTC_StLoopHv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_StLoopHv_CTC_StLoopHv.value)

#define Rte_IRead_COL_100ms_CTC_StRlyCh_CTC_StRlyCh() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_StRlyCh_CTC_StRlyCh.value)

#define Rte_IRead_COL_100ms_CTC_StRlyHeat_CTC_StRlyHeat() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_StRlyHeat_CTC_StRlyHeat.value)

#define Rte_IRead_COL_100ms_CTC_StRlyNeg_CTC_StRlyNeg() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_StRlyNeg_CTC_StRlyNeg.value)

#define Rte_IRead_COL_100ms_CTC_StRlyPos_CTC_StRlyPos() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_StRlyPos_CTC_StRlyPos.value)

#define Rte_IRead_COL_100ms_CTC_StRlyPrech_CTC_StRlyPrech() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CTC_StRlyPrech_CTC_StRlyPrech.value)

#define Rte_IWrite_COL_10ms_ChargingMode_ChargingMode(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_ChargingMode_ChargingMode.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_ChargingMode_ChargingMode() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_ChargingMode_ChargingMode.value \
)

#define Rte_IRead_COL_100ms_ClL_InletWaterTemp_ClL_InletWaterTemp() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_ClL_InletWaterTemp_ClL_InletWaterTemp.value)

#define Rte_IRead_COL_100ms_ClL_OutletWaterTemp_ClL_OutletWaterTemp() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_ClL_OutletWaterTemp_ClL_OutletWaterTemp.value)

#define Rte_IWrite_COL_100ms_CurrentChargeState_CurrentChargeState(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CurrentChargeState_CurrentChargeState.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_CurrentChargeState_CurrentChargeState() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CurrentChargeState_CurrentChargeState.value \
)

#define Rte_IWrite_COL_10ms_CurrentDemand_CurrentDemand(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_CurrentDemand_CurrentDemand.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_CurrentDemand_CurrentDemand() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_CurrentDemand_CurrentDemand.value \
)

#define Rte_IWrite_COL_100ms_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage.value \
)

#define Rte_IRead_COL_1000ms_DEH_BatMfctrType_DEH_BatMfctrType() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_DEH_BatMfctrType_DEH_BatMfctrType.value)

#define Rte_IRead_COL_1000ms_DEH_BatMfctrr_DEH_BatMfctrr() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_DEH_BatMfctrr_DEH_BatMfctrr.value)

#define Rte_IRead_COL_1000ms_DEH_CBatNom_DEH_CBatNom() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_DEH_CBatNom_DEH_CBatNom.value)

#define Rte_IRead_COL_100ms_DEH_CBatNom_DEH_CBatNom() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_CBatNom_DEH_CBatNom.value)

#define Rte_IRead_COL_100ms_DEH_ChgLvlErr_DEH_ChgLvlErr() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_ChgLvlErr_DEH_ChgLvlErr.value)

#define Rte_IRead_COL_1000ms_DEH_DayBatMfctr_DEH_DayBatMfctr() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_DEH_DayBatMfctr_DEH_DayBatMfctr.value)

#define Rte_IRead_COL_100ms_DEH_DelayDataUpldEnb_DEH_DelayDataUpldEnb() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_DelayDataUpldEnb_DEH_DelayDataUpldEnb.value)

#define Rte_IRead_COL_100ms_DEH_DischgLvlErr_DEH_DischgLvlErr() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_DischgLvlErr_DEH_DischgLvlErr.value)

#define Rte_IRead_COL_100ms_DEH_ErrCfmd1_DEH_ErrCfmd1() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value)

#define Rte_IRead_COL_10ms_DEH_ErrCfmd1_DEH_ErrCfmd1() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value)

#define Rte_IRead_COL_100ms_DEH_ErrCfmd2_DEH_ErrCfmd2() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_ErrCfmd2_DEH_ErrCfmd2.value)

#define Rte_IRead_COL_10ms_DEH_ErrCfmd2_DEH_ErrCfmd2() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_DEH_ErrCfmd2_DEH_ErrCfmd2.value)

#define Rte_IRead_COL_100ms_DEH_ErrCfmd3_DEH_ErrCfmd3() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value)

#define Rte_IRead_COL_10ms_DEH_ErrCfmd3_DEH_ErrCfmd3() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value)

#define Rte_IRead_COL_10ms_DEH_ErrCfmd4_DEH_ErrCfmd4() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_DEH_ErrCfmd4_DEH_ErrCfmd4.value)

#define Rte_IRead_COL_100ms_DEH_LvlErrSb_DEH_LvlErrSb() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_LvlErrSb_DEH_LvlErrSb.value)

#define Rte_IRead_COL_1000ms_DEH_MonthBatMfctr_DEH_MonthBatMfctr() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_DEH_MonthBatMfctr_DEH_MonthBatMfctr.value)

#define Rte_IRead_COL_1000ms_DEH_NrPackSerl_DEH_NrPackSerl() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_DEH_NrPackSerl_DEH_NrPackSerl.value)

#define Rte_IRead_COL_100ms_DEH_NrVin1_DEH_NrVin1() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin1_DEH_NrVin1.value)

#define Rte_IRead_COL_100ms_DEH_NrVin10_DEH_NrVin10() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin10_DEH_NrVin10.value)

#define Rte_IRead_COL_100ms_DEH_NrVin11_DEH_NrVin11() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin11_DEH_NrVin11.value)

#define Rte_IRead_COL_100ms_DEH_NrVin12_DEH_NrVin12() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin12_DEH_NrVin12.value)

#define Rte_IRead_COL_100ms_DEH_NrVin13_DEH_NrVin13() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin13_DEH_NrVin13.value)

#define Rte_IRead_COL_100ms_DEH_NrVin14_DEH_NrVin14() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin14_DEH_NrVin14.value)

#define Rte_IRead_COL_100ms_DEH_NrVin15_DEH_NrVin15() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin15_DEH_NrVin15.value)

#define Rte_IRead_COL_100ms_DEH_NrVin16_DEH_NrVin16() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin16_DEH_NrVin16.value)

#define Rte_IRead_COL_100ms_DEH_NrVin17_DEH_NrVin17() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin17_DEH_NrVin17.value)

#define Rte_IRead_COL_100ms_DEH_NrVin2_DEH_NrVin2() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin2_DEH_NrVin2.value)

#define Rte_IRead_COL_100ms_DEH_NrVin3_DEH_NrVin3() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin3_DEH_NrVin3.value)

#define Rte_IRead_COL_100ms_DEH_NrVin4_DEH_NrVin4() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin4_DEH_NrVin4.value)

#define Rte_IRead_COL_100ms_DEH_NrVin5_DEH_NrVin5() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin5_DEH_NrVin5.value)

#define Rte_IRead_COL_100ms_DEH_NrVin6_DEH_NrVin6() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin6_DEH_NrVin6.value)

#define Rte_IRead_COL_100ms_DEH_NrVin7_DEH_NrVin7() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin7_DEH_NrVin7.value)

#define Rte_IRead_COL_100ms_DEH_NrVin8_DEH_NrVin8() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin8_DEH_NrVin8.value)

#define Rte_IRead_COL_100ms_DEH_NrVin9_DEH_NrVin9() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_NrVin9_DEH_NrVin9.value)

#define Rte_IRead_COL_100ms_DEH_PackCode_DEH_PackCode() \
  (&((*RteIRead_COL_100ms_DEH_PackCode_DEH_PackCode())[0]))

#define RteIRead_COL_100ms_DEH_PackCode_DEH_PackCode() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_PackCode_DEH_PackCode.value)

#define Rte_IRead_COL_10ms_DEH_RstDiagGlb_DEH_RstDiagGlb() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value)

#define Rte_IRead_COL_100ms_DEH_StFltLampIndcn_DEH_StFltLampIndcn() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_StFltLampIndcn_DEH_StFltLampIndcn.value)

#define Rte_IRead_COL_1000ms_DEH_UBatNom_DEH_UBatNom() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_DEH_UBatNom_DEH_UBatNom.value)

#define Rte_IRead_COL_100ms_DEH_UBatNom_DEH_UBatNom() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_UBatNom_DEH_UBatNom.value)

#define Rte_IRead_COL_10ms_DEH_VCU_ChgFaultReq_DEH_VCU_ChgFaultReq() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_DEH_VCU_ChgFaultReq_DEH_VCU_ChgFaultReq.value)

#define Rte_IRead_COL_10ms_DEH_VCU_DischgFaultReq_DEH_VCU_DischgFaultReq() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_DEH_VCU_DischgFaultReq_DEH_VCU_DischgFaultReq.value)

#define Rte_IRead_COL_100ms_DEH_ValCodDiag_DEH_ValCodDiag() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_DEH_ValCodDiag_DEH_ValCodDiag.value)

#define Rte_IRead_COL_1000ms_DEH_YearBatMfctr_DEH_YearBatMfctr() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_DEH_YearBatMfctr_DEH_YearBatMfctr.value)

#define Rte_IRead_COL_10ms_DEH_bAcvChInh_DEH_bAcvChInh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_DEH_bAcvChInh_DEH_bAcvChInh.value)

#define Rte_IRead_COL_10ms_DEH_bAcvDcChInh_DEH_bAcvDcChInh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_DEH_bAcvDcChInh_DEH_bAcvDcChInh.value)

#define Rte_IRead_COL_100ms_EHPM_ValCodDiag_EHPM_ValCodDiag() \
  (0U)

#define Rte_IRead_COL_100ms_EHPMon_CellOverVolt_EHPMon_CellOverVolt() \
  (0U)

#define Rte_IRead_COL_100ms_EHPMon_CellUnderVolt_EHPMon_CellUnderVolt() \
  (0U)

#define Rte_IRead_COL_10ms_EHPMon_ChgFaultReq_EHPMon_ChgFaultReq() \
  (0U)

#define Rte_IRead_COL_100ms_EHPMon_ChgOverCurrent_EHPMon_ChgOverCurrent() \
  (0U)

#define Rte_IRead_COL_100ms_EHPMon_DisChgOverCurrent_EHPMon_DisChgOverCurrent() \
  (0U)

#define Rte_IRead_COL_10ms_EHPMon_ReqRlyNeg_EHPMon_ReqRlyNeg() \
  (FALSE)

#define Rte_IRead_COL_10ms_EHPMon_ReqRlyPos_EHPMon_ReqRlyPos() \
  (FALSE)

#define Rte_IRead_COL_10ms_EHPMon_ReqRlyPre_EHPMon_ReqRlyPre() \
  (FALSE)

#define Rte_IRead_COL_100ms_EHPMon_StErrHvIntlcFlt_EHPMon_StErrHvIntlcFlt() \
  (0U)

#define Rte_IRead_COL_100ms_EHPMon_StIsln_EHPMon_StIsln() \
  (0U)

#define Rte_IRead_COL_100ms_EHPMon_StIslnErr_EHPMon_StIslnErr() \
  (0U)

#define Rte_IRead_COL_100ms_EHPMon_StIslnErrFlg_EHPMon_StIslnErrFlg() \
  (FALSE)

#define Rte_IRead_COL_100ms_EHPMon_StRlyNegFlt_EHPMon_StRlyNegFlt() \
  (0U)

#define Rte_IRead_COL_100ms_EHPMon_StRlyPosFlt_EHPMon_StRlyPosFlt() \
  (0U)

#define Rte_IRead_COL_100ms_EHPMon_StsChgFault_EHPMon_StsChgFault() \
  (0U)

#define Rte_IRead_COL_100ms_EHPMon_StsDischgFault_EHPMon_StsDischgFault() \
  (0U)

#define Rte_IRead_COL_100ms_EHPMon_TBOXStErrHvIntlcFlt_EHPMon_TBOXStErrHvIntlcFlt() \
  (FALSE)

#define Rte_IRead_COL_100ms_EHPMon_TBOX_BatOverTemp_EHPMon_TBOX_BatOverTemp() \
  (FALSE)

#define Rte_IRead_COL_100ms_EHPMon_TBOX_BatOverTemp2_EHPMon_TBOX_BatOverTemp2() \
  (0U)

#define Rte_IRead_COL_100ms_EHPMon_TBOX_CellOverVoltage_EHPMon_TBOX_CellOverVoltage() \
  (FALSE)

#define Rte_IRead_COL_100ms_EHPMon_TBOX_CellOverVoltage2_EHPMon_TBOX_CellOverVoltage2() \
  (0U)

#define Rte_IRead_COL_100ms_EHPMon_TBOX_CellUnderVoltage_EHPMon_TBOX_CellUnderVoltage() \
  (FALSE)

#define Rte_IRead_COL_100ms_EHPMon_TBOX_CellUnderVoltage2_EHPMon_TBOX_CellUnderVoltage2() \
  (0U)

#define Rte_IRead_COL_100ms_EHPMon_TBOX_InsulationResistance_EHPMon_TBOX_InsulationResistance() \
  (0U)

#define Rte_IRead_COL_10ms_EHPMon_VCU_DischgFaultReq_EHPMon_VCU_DischgFaultReq() \
  (0U)

#define Rte_IRead_COL_10ms_EHPMon_bErrCrashMon_EHPMon_bErrCrashMon() \
  (FALSE)

#define Rte_IRead_COL_100ms_ELHPN_ErrInfo_ELHPN_ErrInfo() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_ELHPN_ErrInfo_ELHPN_ErrInfo.value)

#define Rte_IRead_COL_100ms_ELHPN_RIslnNeg_ELHPN_RIslnNeg() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_ELHPN_RIslnNeg_ELHPN_RIslnNeg.value)

#define Rte_IRead_COL_100ms_ELHPN_RIslnPos_ELHPN_RIslnPos() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_ELHPN_RIslnPos_ELHPN_RIslnPos.value)

#define Rte_IRead_COL_100ms_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc.value)

#define Rte_IRead_COL_100ms_ELHPN_StIsln_ELHPN_StIsln() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_ELHPN_StIsln_ELHPN_StIsln.value)

#define Rte_IRead_COL_100ms_ELHPN_StIslnErr_ELHPN_StIslnErr() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_ELHPN_StIslnErr_ELHPN_StIslnErr.value)

#define Rte_IRead_COL_100ms_ELHPN_StVehIsln_ELHPN_StVehIsln() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_ELHPN_StVehIsln_ELHPN_StVehIsln.value)

#define Rte_IRead_COL_50ms_ELHPN_bInhIslnMeas_ELHPN_bInhIslnMeas() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_ELHPN_bInhIslnMeas_ELHPN_bInhIslnMeas.value)

#define Rte_IRead_COL_100ms_ESIM_CfgLvl2_ESIM_CfgLvl2() \
  (0U)

#define Rte_IRead_COL_10ms_ESIM_CfgLvl2_ESIM_CfgLvl2() \
  (0U)

#define Rte_IRead_COL_1000ms_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr.value)

#define Rte_IRead_COL_100ms_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr.value)

#define Rte_IRead_COL_10ms_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr.value)

#define Rte_IRead_COL_10ms_EVCSH_ChMode_EVCSH_ChMode() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_ChMode_EVCSH_ChMode.value)

#define Rte_IRead_COL_100ms_EVCSH_ErrMsgChrgrChRdy_EVCSH_ErrMsgChrgrChRdy() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_ErrMsgChrgrChRdy_EVCSH_ErrMsgChrgrChRdy.value)

#define Rte_IRead_COL_100ms_EVCSH_ErrMsgChrgrChSts_EVCSH_ErrMsgChrgrChSts() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_ErrMsgChrgrChSts_EVCSH_ErrMsgChrgrChSts.value)

#define Rte_IRead_COL_100ms_EVCSH_ErrMsgChrgrChStstc_EVCSH_ErrMsgChrgrChStstc() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_ErrMsgChrgrChStstc_EVCSH_ErrMsgChrgrChStstc.value)

#define Rte_IRead_COL_100ms_EVCSH_ErrMsgChrgrChSuspd_EVCSH_ErrMsgChrgrChSuspd() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_ErrMsgChrgrChSuspd_EVCSH_ErrMsgChrgrChSuspd.value)

#define Rte_IRead_COL_100ms_EVCSH_ErrMsgChrgrIdfcNotRdy_EVCSH_ErrMsgChrgrIdfcNotRdy() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_ErrMsgChrgrIdfcNotRdy_EVCSH_ErrMsgChrgrIdfcNotRdy.value)

#define Rte_IRead_COL_100ms_EVCSH_ErrMsgChrgrIdfcRdy_EVCSH_ErrMsgChrgrIdfcRdy() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_ErrMsgChrgrIdfcRdy_EVCSH_ErrMsgChrgrIdfcRdy.value)

#define Rte_IRead_COL_100ms_EVCSH_ErrMsgChrgrSync_EVCSH_ErrMsgChrgrSync() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_ErrMsgChrgrSync_EVCSH_ErrMsgChrgrSync.value)

#define Rte_IRead_COL_10ms_EVCSH_IChrgrSp_EVCSH_IChrgrSp() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_IChrgrSp_EVCSH_IChrgrSp.value)

#define Rte_IRead_COL_100ms_EVCSH_StBatRdy_EVCSH_StBatRdy() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_StBatRdy_EVCSH_StBatRdy.value)

#define Rte_IRead_COL_100ms_EVCSH_StDcCh_EVCSH_StDcCh() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_StDcCh_EVCSH_StDcCh.value)

#define Rte_IRead_COL_100ms_EVCSH_StInt_EVCSH_StInt() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_StInt_EVCSH_StInt.value)

#define Rte_IRead_COL_10ms_EVCSH_StInt_EVCSH_StInt() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_StInt_EVCSH_StInt.value)

#define Rte_IRead_COL_10ms_EVCSH_UChrgrSp_EVCSH_UChrgrSp() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_UChrgrSp_EVCSH_UChrgrSp.value)

#define Rte_IRead_COL_100ms_EVCSH_bEnaChrgn_EVCSH_bEnaChrgn() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaChrgn_EVCSH_bEnaChrgn.value)

#define Rte_IRead_COL_100ms_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg.value)

#define Rte_IRead_COL_100ms_EVCSH_bEnaMsgBatCfgPgtn_EVCSH_bEnaMsgBatCfgPgtn() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatCfgPgtn_EVCSH_bEnaMsgBatCfgPgtn.value)

#define Rte_IRead_COL_10ms_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd.value)

#define Rte_IRead_COL_100ms_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt.value)

#define Rte_IRead_COL_100ms_EVCSH_bEnaMsgBatChStPgtn_EVCSH_bEnaMsgBatChStPgtn() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatChStPgtn_EVCSH_bEnaMsgBatChStPgtn.value)

#define Rte_IRead_COL_10ms_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd.value)

#define Rte_IRead_COL_100ms_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg.value)

#define Rte_IRead_COL_100ms_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr.value)

#define Rte_IRead_COL_100ms_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk.value)

#define Rte_IRead_COL_10ms_EVCSH_bEnaMsgBatPrvt_EVCSH_bEnaMsgBatPrvt() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_bEnaMsgBatPrvt_EVCSH_bEnaMsgBatPrvt.value)

#define Rte_IRead_COL_100ms_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn.value)

#define Rte_IRead_COL_100ms_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy.value)

#define Rte_IRead_COL_100ms_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt.value)

#define Rte_IRead_COL_100ms_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc.value)

#define Rte_IRead_COL_10ms_EVCSH_bEnaMsgBatT_EVCSH_bEnaMsgBatT() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_bEnaMsgBatT_EVCSH_bEnaMsgBatT.value)

#define Rte_IRead_COL_10ms_EVCSH_bEnaMsgCellU_EVCSH_bEnaMsgCellU() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_EVCSH_bEnaMsgCellU_EVCSH_bEnaMsgCellU.value)

#define Rte_IWrite_COL_100ms_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime.value \
)

#define Rte_IWrite_COL_50ms_HvSysSample_DisableIso_DisableIso(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_HvSysSample_DisableIso_DisableIso.value = (data) \
)

#define Rte_IWriteRef_COL_50ms_HvSysSample_DisableIso_DisableIso() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_50ms.Rte_HvSysSample_DisableIso_DisableIso.value \
)

#define Rte_IWrite_COL_10ms_IOFS_NegRlyCtr_IOFS_NegRlyCtr(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_IOFS_NegRlyCtr_IOFS_NegRlyCtr.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_IOFS_NegRlyCtr_IOFS_NegRlyCtr() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_IOFS_NegRlyCtr_IOFS_NegRlyCtr.value \
)

#define Rte_IWrite_COL_10ms_IOFS_PosRlyCtr_IOFS_PosRlyCtr(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_IOFS_PosRlyCtr_IOFS_PosRlyCtr.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_IOFS_PosRlyCtr_IOFS_PosRlyCtr() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_IOFS_PosRlyCtr_IOFS_PosRlyCtr.value \
)

#define Rte_IWrite_COL_10ms_IOFS_PreChgRlyCtr_IOFS_PreChgRlyCtr(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_IOFS_PreChgRlyCtr_IOFS_PreChgRlyCtr.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_IOFS_PreChgRlyCtr_IOFS_PreChgRlyCtr() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_IOFS_PreChgRlyCtr_IOFS_PreChgRlyCtr.value \
)

#define Rte_IRead_COL_1000ms_MCC_NrCellByMdul_MCC_NrCellByMdul() \
  (&((*RteIRead_COL_1000ms_MCC_NrCellByMdul_MCC_NrCellByMdul())[0]))

#define RteIRead_COL_1000ms_MCC_NrCellByMdul_MCC_NrCellByMdul() \
  (&Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_MCC_NrCellByMdul_MCC_NrCellByMdul.value)

#define Rte_IRead_COL_1000ms_MCC_NrCellTot_MCC_NrCellTot() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_MCC_NrCellTot_MCC_NrCellTot.value)

#define Rte_IRead_COL_100ms_MCC_NrCellTot_MCC_NrCellTot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MCC_NrCellTot_MCC_NrCellTot.value)

#define Rte_IRead_COL_1000ms_MCC_NrMdulTot_MCC_NrMdulTot() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_1000ms.Rte_MCC_NrMdulTot_MCC_NrMdulTot.value)

#define Rte_IRead_COL_100ms_MCC_NrSnsrTTot_MCC_NrSnsrTTot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MCC_NrSnsrTTot_MCC_NrSnsrTTot.value)

#define Rte_IWrite_COL_100ms_MaxChargingVoltage_MaxChargingVoltage(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MaxChargingVoltage_MaxChargingVoltage.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_MaxChargingVoltage_MaxChargingVoltage() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MaxChargingVoltage_MaxChargingVoltage.value \
)

#define Rte_IWrite_COL_100ms_MaxPermChargingCurrent_MaxPermChargingCurrent(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MaxPermChargingCurrent_MaxPermChargingCurrent.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_MaxPermChargingCurrent_MaxPermChargingCurrent() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MaxPermChargingCurrent_MaxPermChargingCurrent.value \
)

#define Rte_IWrite_COL_100ms_MaxPermTemperature_MaxPermTemperature(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MaxPermTemperature_MaxPermTemperature.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_MaxPermTemperature_MaxPermTemperature() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MaxPermTemperature_MaxPermTemperature.value \
)

#define Rte_IWrite_COL_100ms_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage.value \
)

#define Rte_IWrite_COL_100ms_MeasuredChargingCurrent_MeasuredChargingCurrent(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MeasuredChargingCurrent_MeasuredChargingCurrent.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_MeasuredChargingCurrent_MeasuredChargingCurrent() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MeasuredChargingCurrent_MeasuredChargingCurrent.value \
)

#define Rte_IWrite_COL_100ms_MeasuredChargingVoltage_MeasuredChargingVoltage(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MeasuredChargingVoltage_MeasuredChargingVoltage.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_MeasuredChargingVoltage_MeasuredChargingVoltage() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_MeasuredChargingVoltage_MeasuredChargingVoltage.value \
)

#define Rte_IWrite_COL_100ms_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage.value \
)

#define Rte_IWrite_COL_100ms_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup.value \
)

#define Rte_IWrite_COL_100ms_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo.value \
)

#define Rte_IWrite_COL_100ms_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature.value \
)

#define Rte_IWrite_COL_100ms_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage.value \
)

#define Rte_IWrite_COL_100ms_SingleBatteryMinTemperature_SingleBatteryMinTemperature(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryMinTemperature_SingleBatteryMinTemperature.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_SingleBatteryMinTemperature_SingleBatteryMinTemperature() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryMinTemperature_SingleBatteryMinTemperature.value \
)

#define Rte_IWrite_COL_100ms_SingleBatteryMinVoltage_SingleBatteryMinVoltage(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryMinVoltage_SingleBatteryMinVoltage.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_SingleBatteryMinVoltage_SingleBatteryMinVoltage() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryMinVoltage_SingleBatteryMinVoltage.value \
)

#define Rte_IWrite_COL_100ms_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage.value \
)

#define Rte_IWrite_COL_100ms_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery.value \
)

#define Rte_IWrite_COL_100ms_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC.value \
)

#define Rte_IWrite_COL_100ms_Timeout_CCS_Timeout_CCS(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CCS_Timeout_CCS.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_Timeout_CCS_Timeout_CCS() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CCS_Timeout_CCS.value \
)

#define Rte_IWrite_COL_100ms_Timeout_CRM_Recognized_Timeout_CRM_Recognized(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CRM_Recognized_Timeout_CRM_Recognized.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_Timeout_CRM_Recognized_Timeout_CRM_Recognized() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CRM_Recognized_Timeout_CRM_Recognized.value \
)

#define Rte_IWrite_COL_100ms_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized.value \
)

#define Rte_IWrite_COL_100ms_Timeout_CRO_Timeout_CRO(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CRO_Timeout_CRO.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_Timeout_CRO_Timeout_CRO() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CRO_Timeout_CRO.value \
)

#define Rte_IWrite_COL_100ms_Timeout_CSD_Timeout_CSD(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CSD_Timeout_CSD.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_Timeout_CSD_Timeout_CSD() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CSD_Timeout_CSD.value \
)

#define Rte_IWrite_COL_100ms_Timeout_CST_Timeout_CST(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CST_Timeout_CST.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_Timeout_CST_Timeout_CST() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CST_Timeout_CST.value \
)

#define Rte_IWrite_COL_100ms_Timeout_CTS_CML_Timeout_CTS_CML(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CTS_CML_Timeout_CTS_CML.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_Timeout_CTS_CML_Timeout_CTS_CML() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_Timeout_CTS_CML_Timeout_CTS_CML.value \
)

#define Rte_IWrite_COL_100ms_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage.value \
)

#define Rte_IWrite_COL_100ms_TotalNominalEnergy_TotalNominalEnergy(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_TotalNominalEnergy_TotalNominalEnergy.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_TotalNominalEnergy_TotalNominalEnergy() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_TotalNominalEnergy_TotalNominalEnergy.value \
)

#define Rte_IWrite_COL_100ms_VIN_Copy_1_VIN_Copy_1(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_1_VIN_Copy_1.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_VIN_Copy_1_VIN_Copy_1() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_1_VIN_Copy_1.value \
)

#define Rte_IWrite_COL_100ms_VIN_Copy_10_VIN_Copy_10(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_10_VIN_Copy_10.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_VIN_Copy_10_VIN_Copy_10() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_10_VIN_Copy_10.value \
)

#define Rte_IWrite_COL_100ms_VIN_Copy_11_VIN_Copy_11(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_11_VIN_Copy_11.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_VIN_Copy_11_VIN_Copy_11() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_11_VIN_Copy_11.value \
)

#define Rte_IWrite_COL_100ms_VIN_Copy_12_VIN_Copy_12(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_12_VIN_Copy_12.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_VIN_Copy_12_VIN_Copy_12() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_12_VIN_Copy_12.value \
)

#define Rte_IWrite_COL_100ms_VIN_Copy_13_VIN_Copy_13(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_13_VIN_Copy_13.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_VIN_Copy_13_VIN_Copy_13() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_13_VIN_Copy_13.value \
)

#define Rte_IWrite_COL_100ms_VIN_Copy_14_VIN_Copy_14(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_14_VIN_Copy_14.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_VIN_Copy_14_VIN_Copy_14() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_14_VIN_Copy_14.value \
)

#define Rte_IWrite_COL_100ms_VIN_Copy_15_VIN_Copy_15(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_15_VIN_Copy_15.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_VIN_Copy_15_VIN_Copy_15() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_15_VIN_Copy_15.value \
)

#define Rte_IWrite_COL_100ms_VIN_Copy_16_VIN_Copy_16(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_16_VIN_Copy_16.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_VIN_Copy_16_VIN_Copy_16() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_16_VIN_Copy_16.value \
)

#define Rte_IWrite_COL_100ms_VIN_Copy_17_VIN_Copy_17(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_17_VIN_Copy_17.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_VIN_Copy_17_VIN_Copy_17() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_17_VIN_Copy_17.value \
)

#define Rte_IWrite_COL_100ms_VIN_Copy_2_VIN_Copy_2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_2_VIN_Copy_2.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_VIN_Copy_2_VIN_Copy_2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_2_VIN_Copy_2.value \
)

#define Rte_IWrite_COL_100ms_VIN_Copy_3_VIN_Copy_3(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_3_VIN_Copy_3.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_VIN_Copy_3_VIN_Copy_3() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_3_VIN_Copy_3.value \
)

#define Rte_IWrite_COL_100ms_VIN_Copy_4_VIN_Copy_4(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_4_VIN_Copy_4.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_VIN_Copy_4_VIN_Copy_4() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_4_VIN_Copy_4.value \
)

#define Rte_IWrite_COL_100ms_VIN_Copy_5_VIN_Copy_5(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_5_VIN_Copy_5.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_VIN_Copy_5_VIN_Copy_5() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_5_VIN_Copy_5.value \
)

#define Rte_IWrite_COL_100ms_VIN_Copy_6_VIN_Copy_6(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_6_VIN_Copy_6.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_VIN_Copy_6_VIN_Copy_6() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_6_VIN_Copy_6.value \
)

#define Rte_IWrite_COL_100ms_VIN_Copy_7_VIN_Copy_7(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_7_VIN_Copy_7.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_VIN_Copy_7_VIN_Copy_7() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_7_VIN_Copy_7.value \
)

#define Rte_IWrite_COL_100ms_VIN_Copy_8_VIN_Copy_8(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_8_VIN_Copy_8.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_VIN_Copy_8_VIN_Copy_8() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_8_VIN_Copy_8.value \
)

#define Rte_IWrite_COL_100ms_VIN_Copy_9_VIN_Copy_9(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_9_VIN_Copy_9.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_VIN_Copy_9_VIN_Copy_9() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VIN_Copy_9_VIN_Copy_9.value \
)

#define Rte_IWrite_COL_100ms_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState.value = (data) \
)

#define Rte_IWriteRef_COL_100ms_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_100ms.Rte_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState.value \
)

#define Rte_IWrite_COL_10ms_VoltageDemand_VoltageDemand(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_VoltageDemand_VoltageDemand.value = (data) \
)

#define Rte_IWriteRef_COL_10ms_VoltageDemand_VoltageDemand() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_COL_COL_10ms.Rte_VoltageDemand_VoltageDemand.value \
)

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
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, swc_COL_CODE) COL_1000ms(void);
FUNC(void, swc_COL_CODE) COL_100ms(void);
FUNC(void, swc_COL_CODE) COL_10ms(void);
FUNC(void, swc_COL_CODE) COL_50ms(void);
FUNC(void, swc_COL_CODE) COL_Init(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Operation Invocation Runnable entities
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Exclusive Areas.
************************************************************************************************************************
*/

#ifdef __cplusplus
}                  
#endif            
#endif /* RTE_SWC_COL_H_ */
 
 
 

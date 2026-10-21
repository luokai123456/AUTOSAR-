 
/*
************************************************************************************************************************
*
* File name: Rte_swc_SetSendCANMsg.h
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
#ifndef RTE_SWC_SETSENDCANMSG_H_
#define RTE_SWC_SETSENDCANMSG_H_

#include "Rte_swc_SetSendCANMsg_Type.h"
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
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCSP_Remaining_range_BCSP_Remaining_range;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCSP_reserved_BCSP_reserved;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Battery_capacity_BDC_Battery_capacity;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Battery_energy_BDC_Battery_energy;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Soc_BDC_Soc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BRM_BmsRevision_BmsRevision;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BRM_BmsVersion_BmsVersion;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_ChargingMode_ChargingMode;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_CurrentDemand_CurrentDemand;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_VoltageDemand_VoltageDemand;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MaxPermChargingCurrent_MaxPermChargingCurrent;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_MaxPermTemperature_MaxPermTemperature;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_TotalNominalEnergy_TotalNominalEnergy;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCSP_Remaining_range_BCSP_Remaining_range;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BCSP_reserved_BCSP_reserved;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_CurrentChargeState_CurrentChargeState;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MeasuredChargingCurrent_MeasuredChargingCurrent;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MeasuredChargingVoltage_MeasuredChargingVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup;
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
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CCS_Timeout_CCS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CRM_Recognized_Timeout_CRM_Recognized;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CRO_Timeout_CRO;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CSD_Timeout_CSD;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CST_Timeout_CST;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CTS_CML_Timeout_CTS_CML;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MaxChargingVoltage_MaxChargingVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BMSStopChgReason_BMS_BMSStopChgReason;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CCUStopChgReason_BMS_CCUStopChgReason;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BatterySystemCapacity_BatterySystemCapacity;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BatterySystemVoltage_BatterySystemVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryType_BatteryType;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsRevision_BmsRevision;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BmsVersion_BmsVersion;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsReadyForCharging_BmsReadyForCharging;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryMinTemperature_SingleBatteryMinTemperature;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryMinVoltage_SingleBatteryMinVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryChargingOvercurrent_BatteryChargingOvercurrent;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryExcessTemperature_BatteryExcessTemperature;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryHighestTemp_BatteryHighestTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryHighestTempSerNo_BatteryHighestTempSerNo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryInsulationState_BatteryInsulationState;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryLowestTemp_BatteryLowestTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryLowestTempSerNo_BatteryLowestTempSerNo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryOutputConnectorState_BatteryOutputConnectorState;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BsmChargingPermissible_BsmChargingPermissible;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState;
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
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCL_ChargingMode_ChargingMode;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCL_CurrentDemand_CurrentDemand;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCL_VoltageDemand_VoltageDemand;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCP_MaxPermTemperature_MaxPermTemperature;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCP_TotalNominalEnergy_TotalNominalEnergy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCS_CurrentChargeState_CurrentChargeState;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BEM_Timeout_CCS_Timeout_CCS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BEM_Timeout_CRO_Timeout_CRO;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BEM_Timeout_CSD_Timeout_CSD;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BEM_Timeout_CST_Timeout_CST;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BEM_Timeout_CTS_CML_Timeout_CTS_CML;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BHM_MaxChargingVoltage_MaxChargingVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BMS_BMSStopChgReason_BMS_BMSStopChgReason;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BMS_CCUStopChgReason_BMS_CCUStopChgReason;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BRM_BatterySystemCapacity_BatterySystemCapacity;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BRM_BatterySystemVoltage_BatterySystemVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BRM_BatteryType_BatteryType;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BRO_BmsReadyForCharging_BmsReadyForCharging;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_BatteryExcessTemperature_BatteryExcessTemperature;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_BatteryHighestTemp_BatteryHighestTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_BatteryInsulationState_BatteryInsulationState;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_BatteryLowestTemp_BatteryLowestTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_BsmChargingPermissible_BsmChargingPermissible;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspCause_SOC_BmsSuspCause_SOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetSendCANMsg_S_BmsProtocolVersion_BmsProtocolVersion;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCL_ChargingMode_ChargingMode(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCL_CurrentDemand_CurrentDemand(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCL_VoltageDemand_VoltageDemand(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCP_MaxPermTemperature_MaxPermTemperature(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCP_TotalNominalEnergy_TotalNominalEnergy(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCSP_Remaining_range_BCSP_Remaining_range(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCSP_reserved_BCSP_reserved(P2VAR(UInt32, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCS_CurrentChargeState_CurrentChargeState(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Battery_capacity_BDC_Battery_capacity(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Battery_energy_BDC_Battery_energy(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Soc_BDC_Soc(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CCS_Timeout_CCS(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CRO_Timeout_CRO(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CSD_Timeout_CSD(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CST_Timeout_CST(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CTS_CML_Timeout_CTS_CML(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BHM_MaxChargingVoltage_MaxChargingVoltage(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BMS_BMSStopChgReason_BMS_BMSStopChgReason(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BMS_CCUStopChgReason_BMS_CCUStopChgReason(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BRM_BatterySystemCapacity_BatterySystemCapacity(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BRM_BatterySystemVoltage_BatterySystemVoltage(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BRM_BatteryType_BatteryType(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BRM_BmsRevision_BmsRevision(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BRM_BmsVersion_BmsVersion(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BRO_BmsReadyForCharging_BmsReadyForCharging(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage(P2VAR(UInt16, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryExcessTemperature_BatteryExcessTemperature(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryHighestTemp_BatteryHighestTemp(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryInsulationState_BatteryInsulationState(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryLowestTemp_BatteryLowestTemp(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_BsmChargingPermissible_BsmChargingPermissible(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspCause_SOC_BmsSuspCause_SOC(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetSendCANMsg_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCSP_Remaining_range_BCSP_Remaining_range(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCSP_reserved_BCSP_reserved(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Battery_capacity_BDC_Battery_capacity(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Battery_energy_BDC_Battery_energy(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Soc_BDC_Soc(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BRM_BmsRevision_BmsRevision(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BRM_BmsVersion_BmsVersion(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCL_ChargingMode_ChargingMode(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCL_CurrentDemand_CurrentDemand(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCL_VoltageDemand_VoltageDemand(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCP_MaxPermTemperature_MaxPermTemperature(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCP_TotalNominalEnergy_TotalNominalEnergy(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCS_CurrentChargeState_CurrentChargeState(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CCS_Timeout_CCS(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CRO_Timeout_CRO(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CSD_Timeout_CSD(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CST_Timeout_CST(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CTS_CML_Timeout_CTS_CML(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BHM_MaxChargingVoltage_MaxChargingVoltage(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BMS_BMSStopChgReason_BMS_BMSStopChgReason(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BMS_CCUStopChgReason_BMS_CCUStopChgReason(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BRM_BatterySystemCapacity_BatterySystemCapacity(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BRM_BatterySystemVoltage_BatterySystemVoltage(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BRM_BatteryType_BatteryType(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BRO_BmsReadyForCharging_BmsReadyForCharging(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryExcessTemperature_BatteryExcessTemperature(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryHighestTemp_BatteryHighestTemp(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryInsulationState_BatteryInsulationState(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryLowestTemp_BatteryLowestTemp(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_BsmChargingPermissible_BsmChargingPermissible(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspCause_SOC_BmsSuspCause_SOC(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetSendCANMsg_S_BmsProtocolVersion_BmsProtocolVersion(UInt32 data);
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
#define Rte_Read_R_BCL_ChargingMode_ChargingMode Rte_Read_swc_SetSendCANMsg_R_BCL_ChargingMode_ChargingMode
#define Rte_Read_R_BCL_CurrentDemand_CurrentDemand Rte_Read_swc_SetSendCANMsg_R_BCL_CurrentDemand_CurrentDemand
#define Rte_Read_R_BCL_VoltageDemand_VoltageDemand Rte_Read_swc_SetSendCANMsg_R_BCL_VoltageDemand_VoltageDemand
#define Rte_Read_R_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur Rte_Read_swc_SetSendCANMsg_R_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur
#define Rte_Read_R_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV Rte_Read_swc_SetSendCANMsg_R_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV
#define Rte_Read_R_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV Rte_Read_swc_SetSendCANMsg_R_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV
#define Rte_Read_R_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc Rte_Read_swc_SetSendCANMsg_R_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc
#define Rte_Read_R_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage Rte_Read_swc_SetSendCANMsg_R_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage
#define Rte_Read_R_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent Rte_Read_swc_SetSendCANMsg_R_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent
#define Rte_Read_R_BCP_MaxPermTemperature_MaxPermTemperature Rte_Read_swc_SetSendCANMsg_R_BCP_MaxPermTemperature_MaxPermTemperature
#define Rte_Read_R_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage Rte_Read_swc_SetSendCANMsg_R_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage
#define Rte_Read_R_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery Rte_Read_swc_SetSendCANMsg_R_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery
#define Rte_Read_R_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage Rte_Read_swc_SetSendCANMsg_R_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage
#define Rte_Read_R_BCP_TotalNominalEnergy_TotalNominalEnergy Rte_Read_swc_SetSendCANMsg_R_BCP_TotalNominalEnergy_TotalNominalEnergy
#define Rte_Read_R_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time Rte_Read_swc_SetSendCANMsg_R_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time
#define Rte_Read_R_BCSP_Remaining_range_BCSP_Remaining_range Rte_Read_swc_SetSendCANMsg_R_BCSP_Remaining_range_BCSP_Remaining_range
#define Rte_Read_R_BCSP_reserved_BCSP_reserved Rte_Read_swc_SetSendCANMsg_R_BCSP_reserved_BCSP_reserved
#define Rte_Read_R_BCS_CurrentChargeState_CurrentChargeState Rte_Read_swc_SetSendCANMsg_R_BCS_CurrentChargeState_CurrentChargeState
#define Rte_Read_R_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime Rte_Read_swc_SetSendCANMsg_R_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime
#define Rte_Read_R_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent Rte_Read_swc_SetSendCANMsg_R_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent
#define Rte_Read_R_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage Rte_Read_swc_SetSendCANMsg_R_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage
#define Rte_Read_R_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage Rte_Read_swc_SetSendCANMsg_R_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage
#define Rte_Read_R_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup Rte_Read_swc_SetSendCANMsg_R_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup
#define Rte_Read_R_BDC_Battery_capacity_BDC_Battery_capacity Rte_Read_swc_SetSendCANMsg_R_BDC_Battery_capacity_BDC_Battery_capacity
#define Rte_Read_R_BDC_Battery_energy_BDC_Battery_energy Rte_Read_swc_SetSendCANMsg_R_BDC_Battery_energy_BDC_Battery_energy
#define Rte_Read_R_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate Rte_Read_swc_SetSendCANMsg_R_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate
#define Rte_Read_R_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange Rte_Read_swc_SetSendCANMsg_R_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange
#define Rte_Read_R_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate Rte_Read_swc_SetSendCANMsg_R_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate
#define Rte_Read_R_BDC_Soc_BDC_Soc Rte_Read_swc_SetSendCANMsg_R_BDC_Soc_BDC_Soc
#define Rte_Read_R_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1 Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1
#define Rte_Read_R_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10 Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10
#define Rte_Read_R_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11 Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11
#define Rte_Read_R_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12 Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12
#define Rte_Read_R_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13 Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13
#define Rte_Read_R_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14 Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14
#define Rte_Read_R_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15 Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15
#define Rte_Read_R_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16 Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16
#define Rte_Read_R_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17 Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17
#define Rte_Read_R_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2 Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2
#define Rte_Read_R_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3 Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3
#define Rte_Read_R_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4 Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4
#define Rte_Read_R_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5 Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5
#define Rte_Read_R_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6 Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6
#define Rte_Read_R_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7 Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7
#define Rte_Read_R_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8 Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8
#define Rte_Read_R_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9 Rte_Read_swc_SetSendCANMsg_R_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9
#define Rte_Read_R_BEM_Timeout_CCS_Timeout_CCS Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CCS_Timeout_CCS
#define Rte_Read_R_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized
#define Rte_Read_R_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized
#define Rte_Read_R_BEM_Timeout_CRO_Timeout_CRO Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CRO_Timeout_CRO
#define Rte_Read_R_BEM_Timeout_CSD_Timeout_CSD Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CSD_Timeout_CSD
#define Rte_Read_R_BEM_Timeout_CST_Timeout_CST Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CST_Timeout_CST
#define Rte_Read_R_BEM_Timeout_CTS_CML_Timeout_CTS_CML Rte_Read_swc_SetSendCANMsg_R_BEM_Timeout_CTS_CML_Timeout_CTS_CML
#define Rte_Read_R_BHM_MaxChargingVoltage_MaxChargingVoltage Rte_Read_swc_SetSendCANMsg_R_BHM_MaxChargingVoltage_MaxChargingVoltage
#define Rte_Read_R_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason Rte_Read_swc_SetSendCANMsg_R_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason
#define Rte_Read_R_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason Rte_Read_swc_SetSendCANMsg_R_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason
#define Rte_Read_R_BMS_BMSStopChgReason_BMS_BMSStopChgReason Rte_Read_swc_SetSendCANMsg_R_BMS_BMSStopChgReason_BMS_BMSStopChgReason
#define Rte_Read_R_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason Rte_Read_swc_SetSendCANMsg_R_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason
#define Rte_Read_R_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason Rte_Read_swc_SetSendCANMsg_R_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason
#define Rte_Read_R_BMS_CCUStopChgReason_BMS_CCUStopChgReason Rte_Read_swc_SetSendCANMsg_R_BMS_CCUStopChgReason_BMS_CCUStopChgReason
#define Rte_Read_R_BRM_BatterySystemCapacity_BatterySystemCapacity Rte_Read_swc_SetSendCANMsg_R_BRM_BatterySystemCapacity_BatterySystemCapacity
#define Rte_Read_R_BRM_BatterySystemVoltage_BatterySystemVoltage Rte_Read_swc_SetSendCANMsg_R_BRM_BatterySystemVoltage_BatterySystemVoltage
#define Rte_Read_R_BRM_BatteryType_BatteryType Rte_Read_swc_SetSendCANMsg_R_BRM_BatteryType_BatteryType
#define Rte_Read_R_BRM_BmsRevision_BmsRevision Rte_Read_swc_SetSendCANMsg_R_BRM_BmsRevision_BmsRevision
#define Rte_Read_R_BRM_BmsVersion_BmsVersion Rte_Read_swc_SetSendCANMsg_R_BRM_BmsVersion_BmsVersion
#define Rte_Read_R_BRO_BmsReadyForCharging_BmsReadyForCharging Rte_Read_swc_SetSendCANMsg_R_BRO_BmsReadyForCharging_BmsReadyForCharging
#define Rte_Read_R_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature Rte_Read_swc_SetSendCANMsg_R_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature
#define Rte_Read_R_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage Rte_Read_swc_SetSendCANMsg_R_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage
#define Rte_Read_R_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature Rte_Read_swc_SetSendCANMsg_R_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature
#define Rte_Read_R_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage Rte_Read_swc_SetSendCANMsg_R_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage
#define Rte_Read_R_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC Rte_Read_swc_SetSendCANMsg_R_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC
#define Rte_Read_R_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent
#define Rte_Read_R_BSM_BatteryExcessTemperature_BatteryExcessTemperature Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryExcessTemperature_BatteryExcessTemperature
#define Rte_Read_R_BSM_BatteryHighestTemp_BatteryHighestTemp Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryHighestTemp_BatteryHighestTemp
#define Rte_Read_R_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo
#define Rte_Read_R_BSM_BatteryInsulationState_BatteryInsulationState Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryInsulationState_BatteryInsulationState
#define Rte_Read_R_BSM_BatteryLowestTemp_BatteryLowestTemp Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryLowestTemp_BatteryLowestTemp
#define Rte_Read_R_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo
#define Rte_Read_R_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState Rte_Read_swc_SetSendCANMsg_R_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState
#define Rte_Read_R_BSM_BsmChargingPermissible_BsmChargingPermissible Rte_Read_swc_SetSendCANMsg_R_BSM_BsmChargingPermissible_BsmChargingPermissible
#define Rte_Read_R_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo Rte_Read_swc_SetSendCANMsg_R_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo
#define Rte_Read_R_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage Rte_Read_swc_SetSendCANMsg_R_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage
#define Rte_Read_R_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState Rte_Read_swc_SetSendCANMsg_R_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState
#define Rte_Read_R_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend
#define Rte_Read_R_BST_BmsSuspCause_SOC_BmsSuspCause_SOC Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspCause_SOC_BmsSuspCause_SOC
#define Rte_Read_R_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage
#define Rte_Read_R_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage
#define Rte_Read_R_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage
#define Rte_Read_R_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent
#define Rte_Read_R_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp
#define Rte_Read_R_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp
#define Rte_Read_R_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn
#define Rte_Read_R_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation
#define Rte_Read_R_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults
#define Rte_Read_R_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp
#define Rte_Read_R_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection
#define Rte_Read_R_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay Rte_Read_swc_SetSendCANMsg_R_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay
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
#define Rte_Write_S_BCL_ChargingMode_ChargingMode Rte_Write_swc_SetSendCANMsg_S_BCL_ChargingMode_ChargingMode
#define Rte_Write_S_BCL_CurrentDemand_CurrentDemand Rte_Write_swc_SetSendCANMsg_S_BCL_CurrentDemand_CurrentDemand
#define Rte_Write_S_BCL_VoltageDemand_VoltageDemand Rte_Write_swc_SetSendCANMsg_S_BCL_VoltageDemand_VoltageDemand
#define Rte_Write_S_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur Rte_Write_swc_SetSendCANMsg_S_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur
#define Rte_Write_S_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV Rte_Write_swc_SetSendCANMsg_S_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV
#define Rte_Write_S_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV Rte_Write_swc_SetSendCANMsg_S_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV
#define Rte_Write_S_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc Rte_Write_swc_SetSendCANMsg_S_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc
#define Rte_Write_S_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage Rte_Write_swc_SetSendCANMsg_S_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage
#define Rte_Write_S_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent Rte_Write_swc_SetSendCANMsg_S_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent
#define Rte_Write_S_BCP_MaxPermTemperature_MaxPermTemperature Rte_Write_swc_SetSendCANMsg_S_BCP_MaxPermTemperature_MaxPermTemperature
#define Rte_Write_S_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage Rte_Write_swc_SetSendCANMsg_S_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage
#define Rte_Write_S_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery Rte_Write_swc_SetSendCANMsg_S_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery
#define Rte_Write_S_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage Rte_Write_swc_SetSendCANMsg_S_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage
#define Rte_Write_S_BCP_TotalNominalEnergy_TotalNominalEnergy Rte_Write_swc_SetSendCANMsg_S_BCP_TotalNominalEnergy_TotalNominalEnergy
#define Rte_Write_S_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time Rte_Write_swc_SetSendCANMsg_S_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time
#define Rte_Write_S_BCSP_Remaining_range_BCSP_Remaining_range Rte_Write_swc_SetSendCANMsg_S_BCSP_Remaining_range_BCSP_Remaining_range
#define Rte_Write_S_BCSP_reserved_BCSP_reserved Rte_Write_swc_SetSendCANMsg_S_BCSP_reserved_BCSP_reserved
#define Rte_Write_S_BCS_CurrentChargeState_CurrentChargeState Rte_Write_swc_SetSendCANMsg_S_BCS_CurrentChargeState_CurrentChargeState
#define Rte_Write_S_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime Rte_Write_swc_SetSendCANMsg_S_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime
#define Rte_Write_S_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent Rte_Write_swc_SetSendCANMsg_S_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent
#define Rte_Write_S_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage Rte_Write_swc_SetSendCANMsg_S_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage
#define Rte_Write_S_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage Rte_Write_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage
#define Rte_Write_S_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup Rte_Write_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup
#define Rte_Write_S_BDC_Battery_capacity_BDC_Battery_capacity Rte_Write_swc_SetSendCANMsg_S_BDC_Battery_capacity_BDC_Battery_capacity
#define Rte_Write_S_BDC_Battery_energy_BDC_Battery_energy Rte_Write_swc_SetSendCANMsg_S_BDC_Battery_energy_BDC_Battery_energy
#define Rte_Write_S_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate Rte_Write_swc_SetSendCANMsg_S_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate
#define Rte_Write_S_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange Rte_Write_swc_SetSendCANMsg_S_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange
#define Rte_Write_S_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate Rte_Write_swc_SetSendCANMsg_S_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate
#define Rte_Write_S_BDC_Soc_BDC_Soc Rte_Write_swc_SetSendCANMsg_S_BDC_Soc_BDC_Soc
#define Rte_Write_S_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1 Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1
#define Rte_Write_S_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10 Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10
#define Rte_Write_S_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11 Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11
#define Rte_Write_S_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12 Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12
#define Rte_Write_S_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13 Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13
#define Rte_Write_S_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14 Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14
#define Rte_Write_S_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15 Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15
#define Rte_Write_S_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16 Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16
#define Rte_Write_S_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17 Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17
#define Rte_Write_S_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2 Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2
#define Rte_Write_S_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3 Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3
#define Rte_Write_S_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4 Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4
#define Rte_Write_S_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5 Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5
#define Rte_Write_S_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6 Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6
#define Rte_Write_S_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7 Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7
#define Rte_Write_S_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8 Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8
#define Rte_Write_S_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9 Rte_Write_swc_SetSendCANMsg_S_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9
#define Rte_Write_S_BEM_Timeout_CCS_Timeout_CCS Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CCS_Timeout_CCS
#define Rte_Write_S_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized
#define Rte_Write_S_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized
#define Rte_Write_S_BEM_Timeout_CRO_Timeout_CRO Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CRO_Timeout_CRO
#define Rte_Write_S_BEM_Timeout_CSD_Timeout_CSD Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CSD_Timeout_CSD
#define Rte_Write_S_BEM_Timeout_CST_Timeout_CST Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CST_Timeout_CST
#define Rte_Write_S_BEM_Timeout_CTS_CML_Timeout_CTS_CML Rte_Write_swc_SetSendCANMsg_S_BEM_Timeout_CTS_CML_Timeout_CTS_CML
#define Rte_Write_S_BHM_MaxChargingVoltage_MaxChargingVoltage Rte_Write_swc_SetSendCANMsg_S_BHM_MaxChargingVoltage_MaxChargingVoltage
#define Rte_Write_S_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason Rte_Write_swc_SetSendCANMsg_S_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason
#define Rte_Write_S_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason Rte_Write_swc_SetSendCANMsg_S_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason
#define Rte_Write_S_BMS_BMSStopChgReason_BMS_BMSStopChgReason Rte_Write_swc_SetSendCANMsg_S_BMS_BMSStopChgReason_BMS_BMSStopChgReason
#define Rte_Write_S_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason Rte_Write_swc_SetSendCANMsg_S_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason
#define Rte_Write_S_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason Rte_Write_swc_SetSendCANMsg_S_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason
#define Rte_Write_S_BMS_CCUStopChgReason_BMS_CCUStopChgReason Rte_Write_swc_SetSendCANMsg_S_BMS_CCUStopChgReason_BMS_CCUStopChgReason
#define Rte_Write_S_BRM_BatterySystemCapacity_BatterySystemCapacity Rte_Write_swc_SetSendCANMsg_S_BRM_BatterySystemCapacity_BatterySystemCapacity
#define Rte_Write_S_BRM_BatterySystemVoltage_BatterySystemVoltage Rte_Write_swc_SetSendCANMsg_S_BRM_BatterySystemVoltage_BatterySystemVoltage
#define Rte_Write_S_BRM_BatteryType_BatteryType Rte_Write_swc_SetSendCANMsg_S_BRM_BatteryType_BatteryType
#define Rte_Write_S_BRM_BmsRevision_BmsRevision Rte_Write_swc_SetSendCANMsg_S_BRM_BmsRevision_BmsRevision
#define Rte_Write_S_BRM_BmsVersion_BmsVersion Rte_Write_swc_SetSendCANMsg_S_BRM_BmsVersion_BmsVersion
#define Rte_Write_S_BRO_BmsReadyForCharging_BmsReadyForCharging Rte_Write_swc_SetSendCANMsg_S_BRO_BmsReadyForCharging_BmsReadyForCharging
#define Rte_Write_S_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature Rte_Write_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature
#define Rte_Write_S_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage Rte_Write_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage
#define Rte_Write_S_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature Rte_Write_swc_SetSendCANMsg_S_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature
#define Rte_Write_S_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage Rte_Write_swc_SetSendCANMsg_S_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage
#define Rte_Write_S_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC Rte_Write_swc_SetSendCANMsg_S_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC
#define Rte_Write_S_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent
#define Rte_Write_S_BSM_BatteryExcessTemperature_BatteryExcessTemperature Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryExcessTemperature_BatteryExcessTemperature
#define Rte_Write_S_BSM_BatteryHighestTemp_BatteryHighestTemp Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryHighestTemp_BatteryHighestTemp
#define Rte_Write_S_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo
#define Rte_Write_S_BSM_BatteryInsulationState_BatteryInsulationState Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryInsulationState_BatteryInsulationState
#define Rte_Write_S_BSM_BatteryLowestTemp_BatteryLowestTemp Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryLowestTemp_BatteryLowestTemp
#define Rte_Write_S_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo
#define Rte_Write_S_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState Rte_Write_swc_SetSendCANMsg_S_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState
#define Rte_Write_S_BSM_BsmChargingPermissible_BsmChargingPermissible Rte_Write_swc_SetSendCANMsg_S_BSM_BsmChargingPermissible_BsmChargingPermissible
#define Rte_Write_S_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo Rte_Write_swc_SetSendCANMsg_S_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo
#define Rte_Write_S_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage Rte_Write_swc_SetSendCANMsg_S_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage
#define Rte_Write_S_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState Rte_Write_swc_SetSendCANMsg_S_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState
#define Rte_Write_S_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend
#define Rte_Write_S_BST_BmsSuspCause_SOC_BmsSuspCause_SOC Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspCause_SOC_BmsSuspCause_SOC
#define Rte_Write_S_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage
#define Rte_Write_S_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage
#define Rte_Write_S_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage
#define Rte_Write_S_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent
#define Rte_Write_S_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp
#define Rte_Write_S_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp
#define Rte_Write_S_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn
#define Rte_Write_S_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation
#define Rte_Write_S_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults
#define Rte_Write_S_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp
#define Rte_Write_S_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection
#define Rte_Write_S_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay Rte_Write_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay
#define Rte_Write_S_BmsProtocolVersion_BmsProtocolVersion Rte_Write_swc_SetSendCANMsg_S_BmsProtocolVersion_BmsProtocolVersion
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
FUNC(void, swc_SetSendCANMsg_CODE) swc_SetSendCANMsg_1000ms(void);
FUNC(void, swc_SetSendCANMsg_CODE) swc_SetSendCANMsg_100ms(void);
FUNC(void, swc_SetSendCANMsg_CODE) swc_SetSendCANMsg_10ms(void);
FUNC(void, swc_SetSendCANMsg_CODE) swc_SetSendCANMsg_Init(void);
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
#endif /* RTE_SWC_SETSENDCANMSG_H_ */
 
 
 

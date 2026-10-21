 
/*
************************************************************************************************************************
*
* File name: Rte_ComRx_CAN.h
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
#ifndef RTE_COMRX_CAN_H_
#define RTE_COMRX_CAN_H_

#include "Rte_ComRx_CAN_Type.h"
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

#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_AC_AmbientTemperatureInvalid_Rx_AC_AmbientTemperatureInvalid_Rx;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_AC_AmbientTemperature_Rx_AC_AmbientTemperature_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_ActiveWakeupBit_Rx_BMSH_ActiveWakeupBit_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_Address_Rx_BMSH_Address_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_BatCurrentValidFlag_Rx_BMSH_BatCurrentValidFlag_Rx;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_BatCurrent_Rx_BMSH_BatCurrent_Rx;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_BusVolt_Rx_BMSH_BusVolt_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_NMSts_Rx_BMSH_NMSts_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_PackVoltValidFlag_Rx_BMSH_PackVoltValidFlag_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_RMR_Rx_BMSH_RMR_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_Status_AliveCounter_Rx_BMSH_Status_AliveCounter_Rx;
extern VAR(UInt32, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_StayAwake_Reasons_Rx_BMSH_StayAwake_Reasons_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_StsMainNegtiveRelay_Rx_BMSH_StsMainNegtiveRelay_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_StsMainPositiveRelay_Rx_BMSH_StsMainPositiveRelay_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_StsMode_Rx_BMSH_StsMode_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_VCU_Crash_Rx_BMSH_VCU_Crash_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_VoltCurrent_AliveCounter_Rx_BMSH_VoltCurrent_AliveCounter_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_VoltCurrent_CheckSum_Rx_BMSH_VoltCurrent_CheckSum_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_WakeUp_Reasons_Rx_BMSH_WakeUp_Reasons_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_IgnONSts_ComRx_IgnONSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_IsgActvDampgModReq_ComRx_IsgActvDampgModReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_Status_AliveCounter_ComRx_Status_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_Status_Checksum_ComRx_Status_Checksum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bAcceleratorPedal_flag_ComRx_bAcceleratorPedal_flag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bDampgSwtActv_ComRx_bDampgSwtActv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bDriveModeInd_ComRx_bDriveModeInd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bEmgyDchrgReq_ComRx_bEmgyDchrgReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bErrEmgyShtofCrash_ComRx_bErrEmgyShtofCrash;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bGearPositionInd_ComRx_bGearPositionInd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bOdmtBkupEna_ComRx_bOdmtBkupEna;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bOil_HV_OFF_ComRx_bOil_HV_OFF;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bPTReadyInd_ComRx_bPTReadyInd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bPowerModeValidity_ComRx_bPowerModeValidity;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bT15_ComRx_bT15;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bVehicleSpd_flag_ComRx_bVehicleSpd_flag;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_dstTotalOdometer_ComRx_dstTotalOdometer;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_dstTotalVehicleDistance_ComRx_dstTotalVehicleDistance;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_facTqSlopMax_ComRx_facTqSlopMax;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_iEfcDes_ComRx_iEfcDes;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_pctAcceleratorPedalPosition_ComRx_pctAcceleratorPedalPosition;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_pctBrakePedalPosition_ComRx_pctBrakePedalPosition;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_posBattSOC_ComRx_posBattSOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stCrashOutputSts_ComRx_stCrashOutputSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stCtrlAliveCnt_ComRx_stCtrlAliveCnt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stCtrlCheckSum_ComRx_stCtrlCheckSum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stDrvCtrlDes_ComRx_stDrvCtrlDes;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stDrvGear_ComRx_stDrvGear;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stEMTrqSpdCtrl_AliveCnt_ComRx_stEMTrqSpdCtrl_AliveCnt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stEMTrqSpdCtrl_Checksum_ComRx_stEMTrqSpdCtrl_Checksum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stHVLoopWorkSts_ComRx_stHVLoopWorkSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stMainPosConnSts_ComRx_stMainPosConnSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stPowerMode_ComRx_stPowerMode;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tCooltInletEm_ComRx_tCooltInletEm;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tExtEnv_ComRx_tExtEnv;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tIvtrCooltInlet_ComRx_tIvtrCooltInlet;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tiDay_ComRx_tiDay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tiHour_ComRx_tiHour;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tiMinute_ComRx_tiMinute;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tiMonth_ComRx_tiMonth;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tiSecond_ComRx_tiSecond;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tiYear_ComRx_tiYear;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tqMaxLim_ComRx_tqMaxLim;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tqMinLim_ComRx_tqMinLim;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_uDCLnkDes_ComRx_uDCLnkDes;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_EPBStatus_Rx_EHB_EPBStatus_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_FLWheelDirection_Rx_EHB_FLWheelDirection_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_FLWheelSpeedInvalid_Rx_EHB_FLWheelSpeedInvalid_Rx;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_FLWheelSpeedKPH_Rx_EHB_FLWheelSpeedKPH_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_FRWheelDirection_Rx_EHB_FRWheelDirection_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_FRWheelSpeedInvalid_Rx_EHB_FRWheelSpeedInvalid_Rx;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_FRWheelSpeedKPH_Rx_EHB_FRWheelSpeedKPH_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_FrontWheelSpeedsKPH_AliveCounter_Rx_EHB_FrontWheelSpeedsKPH_AliveCounter_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_FrontWheelSpeedsKPH_CheckSum_Rx_EHB_FrontWheelSpeedsKPH_CheckSum_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_RLWheelDirection_Rx_EHB_RLWheelDirection_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_RLWheelSpeedInvalid_Rx_EHB_RLWheelSpeedInvalid_Rx;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_RLWheelSpeedKPH_Rx_EHB_RLWheelSpeedKPH_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_RRWheelDirection_Rx_EHB_RRWheelDirection_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_RRWheelSpeedInvalid_Rx_EHB_RRWheelSpeedInvalid_Rx;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_RRWheelSpeedKPH_Rx_EHB_RRWheelSpeedKPH_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_RearWheelSpeedsKPH_AliveCounter_Rx_EHB_RearWheelSpeedsKPH_AliveCounter_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_RearWheelSpeedsKPH_CheckSum_Rx_EHB_RearWheelSpeedsKPH_CheckSum_Rx;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_RearWheelSpeedsKPH_Rx_EHB_RearWheelSpeedsKPH_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_Status_AliveCounter_Rx_EHB_Status_AliveCounter_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_Status_CheckSum_Rx_EHB_Status_CheckSum_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_VehicleSpeedInvalid_Rx_EHB_VehicleSpeedInvalid_Rx;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_VehicleSpeed_Rx_EHB_VehicleSpeed_Rx;
extern VAR(UInt32, RTE_VAR_INIT) Rte_ComRx_CAN_IPK_IPKTotalOdometer_Rx_IPK_IPKTotalOdometer_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PEPS_PowerModeValidity_Rx_PEPS_PowerModeValidity_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PEPS_PowerMode_Rx_PEPS_PowerMode_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_AWB_Rx_PMS_AWB_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_Command_AliveCounter_Rx_PMS_Command_AliveCounter_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_Command_Checksum_Rx_PMS_Command_Checksum_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_CurrentGearPosition_Rx_PMS_CurrentGearPosition_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_CurrentGearPosition_Valid_Rx_PMS_CurrentGearPosition_Valid_Rx;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_DriveCircuitTemp_Rx_PMS_DriveCircuitTemp_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_EDCPEnable_Rx_PMS_EDCPEnable_Rx;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_EDCPPWMCtrl_Rx_PMS_EDCPPWMCtrl_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_FrntHeatModEnad_Rx_PMS_FrntHeatModEnad_Rx;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_FrntHeatPwrAllwd_Rx_PMS_FrntHeatPwrAllwd_Rx;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_IPUFlowFeedback_Rx_PMS_IPUFlowFeedback_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_IgnONSts_Rx_PMS_IgnONSts_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_IsgActvDampgModReq_Rx_PMS_IsgActvDampgModReq_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_IsgModReq_Rx_PMS_IsgModReq_Rx;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_IsgTqReq_Rx_PMS_IsgTqReq_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_NMSts_Rx_PMS_NMSts_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_RMR_Rx_PMS_RMR_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_Real_PedalPositionInvalid_Rx_PMS_Real_PedalPositionInvalid_Rx;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_Real_PedalPosition_Rx_PMS_Real_PedalPosition_Rx;
extern VAR(UInt32, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_Stayawake_reasons_Rx_PMS_Stayawake_reasons_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_StsBrkSwitch1Invalid_Rx_PMS_StsBrkSwitch1Invalid_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_StsBrkSwitch1_Rx_PMS_StsBrkSwitch1_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_TM_Address_Rx_PMS_TM_Address_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_Wakeup_reasons_Rx_PMS_Wakeup_reasons_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_TBOX_Day_Rx_TBOX_Day_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_TBOX_Hour_Rx_TBOX_Hour_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_TBOX_Minute_Rx_TBOX_Minute_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_TBOX_Month_Rx_TBOX_Month_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_TBOX_Second_Rx_TBOX_Second_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_TBOX_Year_Rx_TBOX_Year_Rx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_VCU_CrashOutputSts_Rx_VCU_CrashOutputSts_Rx;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Command_AliveCounter_PMS_Command_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Command_Checksum_PMS_Command_Checksum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CurrentGearPosition_PMS_CurrentGearPosition;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCPEnable_PMS_EDCPEnable;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IgnONSts_PMS_IgnONSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IsgModReq_PMS_IsgModReq;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IsgTqReq_PMS_IsgTqReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_NMSts_PMS_NMSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Real_PedalPosition_PMS_Real_PedalPosition;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Stayawake_reasons_PMS_Stayawake_reasons;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StsBrkSwitch1_PMS_StsBrkSwitch1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StsBrkSwitch1Invalid_PMS_StsBrkSwitch1Invalid;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Wakeup_reasons_PMS_Wakeup_reasons;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_CrashOutputSts_VCU_CrashOutputSts;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatCurrent_BMSH_BatCurrent;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BusVolt_BMSH_BusVolt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsMode_BMSH_StsMode;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_Crash_BMSH_VCU_Crash;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE4_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_BMSH_Status_AliveCounter_BMSH_Status_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE4_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_Status_CheckSum_Rx_BMSH_Status_CheckSum_Rx;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_VehicleSpd_ComRx_VehicleSpd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bCrcChksFlt_ComRx_bCrcChksFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bMcuCutOffLv_ComRx_bMcuCutOffLv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bRollgCntrFlt_ComRx_bRollgCntrFlt;
extern VAR(SInt16, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_nDes_ComRx_nDes;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stBrkSwt_ComRx_stBrkSwt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stEmCtrlMod_ComRx_stEmCtrlMod;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stEmWrkMod_ComRx_stEmWrkMod;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stHndbrk_ComRx_stHndbrk;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stHvCntctr_ComRx_stHvCntctr;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tqDes_ComRx_tqDes;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_AmbientTemperature_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_AC_AmbientTemperatureInvalid_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_EPBStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_FLWheelDirection_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_FLWheelSpeedInvalid_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_FLWheelSpeedKPH_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_FRWheelDirection_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_FRWheelSpeedInvalid_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_FRWheelSpeedKPH_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_RLWheelDirection_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_RLWheelSpeedInvalid_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_RLWheelSpeedKPH_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_RRWheelDirection_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_RRWheelSpeedInvalid_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_RRWheelSpeedKPH_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_VehicleSpeed_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_VehicleSpeedInvalid_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_PEPS_PowerMode_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_PEPS_PowerModeValidity_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Day_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Hour_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Minute_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Month_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Second_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Year_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_AC_AmbientTemperatureInvalid_Rx_AC_AmbientTemperatureInvalid_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_AC_AmbientTemperature_Rx_AC_AmbientTemperature_Rx(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_ActiveWakeupBit_BMSH_ActiveWakeupBit(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_ActiveWakeupBit_Rx_BMSH_ActiveWakeupBit_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_Address_BMSH_Address(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_Address_Rx_BMSH_Address_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_BatCurrent_BMSH_BatCurrent(P2VAR(UInt16, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_BatCurrentValidFlag_Rx_BMSH_BatCurrentValidFlag_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_BatCurrent_Rx_BMSH_BatCurrent_Rx(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_BusVolt_BMSH_BusVolt(P2VAR(UInt16, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_BusVolt_Rx_BMSH_BusVolt_Rx(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_NMSts_BMSH_NMSts(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_NMSts_Rx_BMSH_NMSts_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_PackVoltValidFlag_Rx_BMSH_PackVoltValidFlag_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_RMR_BMSH_RMR(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_RMR_Rx_BMSH_RMR_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_Status_AliveCounter_BMSH_Status_AliveCounter(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_Status_AliveCounter_Rx_BMSH_Status_AliveCounter_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_Status_CheckSum_BMSH_Status_CheckSum(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_StayAwake_Reasons_BMSH_StayAwake_Reasons(P2VAR(UInt32, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_StayAwake_Reasons_Rx_BMSH_StayAwake_Reasons_Rx(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_StsMainNegtiveRelay_Rx_BMSH_StsMainNegtiveRelay_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_StsMainPositiveRelay_Rx_BMSH_StsMainPositiveRelay_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_StsMode_BMSH_StsMode(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_StsMode_Rx_BMSH_StsMode_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_VCU_Crash_BMSH_VCU_Crash(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_VCU_Crash_Rx_BMSH_VCU_Crash_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_VoltCurrent_AliveCounter_Rx_BMSH_VoltCurrent_AliveCounter_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_VoltCurrent_CheckSum_BMSH_VoltCurrent_CheckSum(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_VoltCurrent_CheckSum_Rx_BMSH_VoltCurrent_CheckSum_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_WakeUp_Reasons_BMSH_WakeUp_Reasons(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_WakeUp_Reasons_Rx_BMSH_WakeUp_Reasons_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_IgnONSts_ComRx_IgnONSts(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_IsgActvDampgModReq_ComRx_IsgActvDampgModReq(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_Status_AliveCounter_ComRx_Status_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_Status_Checksum_ComRx_Status_Checksum(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_VehicleSpd_ComRx_VehicleSpd(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bAcceleratorPedal_flag_ComRx_bAcceleratorPedal_flag(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bCrcChksFlt_ComRx_bCrcChksFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bDampgSwtActv_ComRx_bDampgSwtActv(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bDriveModeInd_ComRx_bDriveModeInd(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bEmgyDchrgReq_ComRx_bEmgyDchrgReq(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bErrEmgyShtofCrash_ComRx_bErrEmgyShtofCrash(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bGearPositionInd_ComRx_bGearPositionInd(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bMcuCutOffLv_ComRx_bMcuCutOffLv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bOdmtBkupEna_ComRx_bOdmtBkupEna(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bOil_HV_OFF_ComRx_bOil_HV_OFF(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bPTReadyInd_ComRx_bPTReadyInd(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bPowerModeValidity_ComRx_bPowerModeValidity(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bRollgCntrFlt_ComRx_bRollgCntrFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bT15_ComRx_bT15(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bVehicleSpd_flag_ComRx_bVehicleSpd_flag(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_dstTotalOdometer_ComRx_dstTotalOdometer(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_dstTotalVehicleDistance_ComRx_dstTotalVehicleDistance(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_facTqSlopMax_ComRx_facTqSlopMax(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_iEfcDes_ComRx_iEfcDes(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_nDes_ComRx_nDes(SInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_pctAcceleratorPedalPosition_ComRx_pctAcceleratorPedalPosition(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_pctBrakePedalPosition_ComRx_pctBrakePedalPosition(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_posBattSOC_ComRx_posBattSOC(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stBrkSwt_ComRx_stBrkSwt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stCrashOutputSts_ComRx_stCrashOutputSts(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stCtrlAliveCnt_ComRx_stCtrlAliveCnt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stCtrlCheckSum_ComRx_stCtrlCheckSum(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stDrvCtrlDes_ComRx_stDrvCtrlDes(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stDrvGear_ComRx_stDrvGear(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stEMTrqSpdCtrl_AliveCnt_ComRx_stEMTrqSpdCtrl_AliveCnt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stEMTrqSpdCtrl_Checksum_ComRx_stEMTrqSpdCtrl_Checksum(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stEmCtrlMod_ComRx_stEmCtrlMod(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stEmWrkMod_ComRx_stEmWrkMod(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stHVLoopWorkSts_ComRx_stHVLoopWorkSts(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stHndbrk_ComRx_stHndbrk(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stHvCntctr_ComRx_stHvCntctr(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stMainPosConnSts_ComRx_stMainPosConnSts(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stPowerMode_ComRx_stPowerMode(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tCooltInletEm_ComRx_tCooltInletEm(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tExtEnv_ComRx_tExtEnv(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tIvtrCooltInlet_ComRx_tIvtrCooltInlet(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tiDay_ComRx_tiDay(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tiHour_ComRx_tiHour(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tiMinute_ComRx_tiMinute(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tiMonth_ComRx_tiMonth(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tiSecond_ComRx_tiSecond(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tiYear_ComRx_tiYear(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tqDes_ComRx_tqDes(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tqMaxLim_ComRx_tqMaxLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tqMinLim_ComRx_tqMinLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_uDCLnkDes_ComRx_uDCLnkDes(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_EPBStatus_Rx_EHB_EPBStatus_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_FLWheelDirection_Rx_EHB_FLWheelDirection_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_FLWheelSpeedInvalid_Rx_EHB_FLWheelSpeedInvalid_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_FLWheelSpeedKPH_Rx_EHB_FLWheelSpeedKPH_Rx(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_FRWheelDirection_Rx_EHB_FRWheelDirection_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_FRWheelSpeedInvalid_Rx_EHB_FRWheelSpeedInvalid_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_FRWheelSpeedKPH_Rx_EHB_FRWheelSpeedKPH_Rx(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_FrontWheelSpeedsKPH_AliveCounter_EHB_FrontWheelSpeedsKPH_AliveCounter(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_FrontWheelSpeedsKPH_AliveCounter_Rx_EHB_FrontWheelSpeedsKPH_AliveCounter_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_FrontWheelSpeedsKPH_CheckSum_EHB_FrontWheelSpeedsKPH_CheckSum(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_FrontWheelSpeedsKPH_CheckSum_Rx_EHB_FrontWheelSpeedsKPH_CheckSum_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_RLWheelDirection_Rx_EHB_RLWheelDirection_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_RLWheelSpeedInvalid_Rx_EHB_RLWheelSpeedInvalid_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_RLWheelSpeedKPH_Rx_EHB_RLWheelSpeedKPH_Rx(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_RRWheelDirection_Rx_EHB_RRWheelDirection_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_RRWheelSpeedInvalid_Rx_EHB_RRWheelSpeedInvalid_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_RRWheelSpeedKPH_Rx_EHB_RRWheelSpeedKPH_Rx(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_RearWheelSpeedsKPH_EHB_RearWheelSpeedsKPH(P2VAR(Float, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_RearWheelSpeedsKPH_AliveCounter_EHB_RearWheelSpeedsKPH_AliveCounter(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_RearWheelSpeedsKPH_AliveCounter_Rx_EHB_RearWheelSpeedsKPH_AliveCounter_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_RearWheelSpeedsKPH_CheckSum_EHB_RearWheelSpeedsKPH_CheckSum(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_RearWheelSpeedsKPH_CheckSum_Rx_EHB_RearWheelSpeedsKPH_CheckSum_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_RearWheelSpeedsKPH_Rx_EHB_RearWheelSpeedsKPH_Rx(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_Status_AliveCounter_EHB_Status_AliveCounter(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_Status_AliveCounter_Rx_EHB_Status_AliveCounter_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_Status_CheckSum_EHB_Status_CheckSum(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_Status_CheckSum_Rx_EHB_Status_CheckSum_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_VehicleSpeedInvalid_Rx_EHB_VehicleSpeedInvalid_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_VehicleSpeed_Rx_EHB_VehicleSpeed_Rx(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_IPK_IPKTotalOdometer_IPK_IPKTotalOdometer(P2VAR(UInt32, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_IPK_IPKTotalOdometer_Rx_IPK_IPKTotalOdometer_Rx(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PEPS_PowerModeValidity_Rx_PEPS_PowerModeValidity_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PEPS_PowerMode_Rx_PEPS_PowerMode_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_AWB_PMS_AWB(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_AWB_Rx_PMS_AWB_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_Command_AliveCounter_PMS_Command_AliveCounter(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_Command_AliveCounter_Rx_PMS_Command_AliveCounter_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_Command_Checksum_PMS_Command_Checksum(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_Command_Checksum_Rx_PMS_Command_Checksum_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_CurrentGearPosition_PMS_CurrentGearPosition(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_CurrentGearPosition_Rx_PMS_CurrentGearPosition_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_CurrentGearPosition_Valid_Rx_PMS_CurrentGearPosition_Valid_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_DriveCircuitTemp_Rx_PMS_DriveCircuitTemp_Rx(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_EDCPEnable_PMS_EDCPEnable(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_EDCPEnable_Rx_PMS_EDCPEnable_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_EDCPPWMCtrl_Rx_PMS_EDCPPWMCtrl_Rx(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_FrntHeatModEnad_Rx_PMS_FrntHeatModEnad_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_FrntHeatPwrAllwd_Rx_PMS_FrntHeatPwrAllwd_Rx(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_IPUFlowFeedback_PMS_IPUFlowFeedback(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_IPUFlowFeedback_Rx_PMS_IPUFlowFeedback_Rx(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_IgnONSts_PMS_IgnONSts(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_IgnONSts_Rx_PMS_IgnONSts_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_IsgActvDampgModReq_Rx_PMS_IsgActvDampgModReq_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_IsgModReq_PMS_IsgModReq(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_IsgModReq_Rx_PMS_IsgModReq_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_IsgTqReq_PMS_IsgTqReq(P2VAR(UInt16, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_IsgTqReq_Rx_PMS_IsgTqReq_Rx(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_NMSts_PMS_NMSts(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_NMSts_Rx_PMS_NMSts_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_RMR_PMS_RMR(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_RMR_Rx_PMS_RMR_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_Real_PedalPosition_PMS_Real_PedalPosition(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_Real_PedalPositionInvalid_Rx_PMS_Real_PedalPositionInvalid_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_Real_PedalPosition_Rx_PMS_Real_PedalPosition_Rx(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_Stayawake_reasons_PMS_Stayawake_reasons(P2VAR(UInt32, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_Stayawake_reasons_Rx_PMS_Stayawake_reasons_Rx(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_StsBrkSwitch1_PMS_StsBrkSwitch1(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_StsBrkSwitch1Invalid_PMS_StsBrkSwitch1Invalid(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_StsBrkSwitch1Invalid_Rx_PMS_StsBrkSwitch1Invalid_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_StsBrkSwitch1_Rx_PMS_StsBrkSwitch1_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_TM_Address_PMS_TM_Address(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_TM_Address_Rx_PMS_TM_Address_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_Wakeup_reasons_PMS_Wakeup_reasons(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_Wakeup_reasons_Rx_PMS_Wakeup_reasons_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_TBOX_Day_Rx_TBOX_Day_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_TBOX_Hour_Rx_TBOX_Hour_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_TBOX_Minute_Rx_TBOX_Minute_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_TBOX_Month_Rx_TBOX_Month_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_TBOX_Second_Rx_TBOX_Second_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_TBOX_Year_Rx_TBOX_Year_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_VCU_CrashOutputSts_VCU_CrashOutputSts(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_VCU_CrashOutputSts_Rx_VCU_CrashOutputSts_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_AC_AmbientTemperature_AC_AmbientTemperature(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_AC_AmbientTemperatureInvalid_AC_AmbientTemperatureInvalid(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_Status_CheckSum_Rx_BMSH_Status_CheckSum_Rx(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_EPBStatus_EHB_EPBStatus(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_FLWheelDirection_EHB_FLWheelDirection(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_FLWheelSpeedInvalid_EHB_FLWheelSpeedInvalid(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_FLWheelSpeedKPH_EHB_FLWheelSpeedKPH(P2VAR(UInt16, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_FRWheelDirection_EHB_FRWheelDirection(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_FRWheelSpeedInvalid_EHB_FRWheelSpeedInvalid(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_FRWheelSpeedKPH_EHB_FRWheelSpeedKPH(P2VAR(UInt16, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_RLWheelDirection_EHB_RLWheelDirection(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_RLWheelSpeedInvalid_EHB_RLWheelSpeedInvalid(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_RLWheelSpeedKPH_EHB_RLWheelSpeedKPH(P2VAR(UInt16, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_RRWheelDirection_EHB_RRWheelDirection(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_RRWheelSpeedInvalid_EHB_RRWheelSpeedInvalid(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_RRWheelSpeedKPH_EHB_RRWheelSpeedKPH(P2VAR(UInt16, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_VehicleSpeed_EHB_VehicleSpeed(P2VAR(UInt16, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_VehicleSpeedInvalid_EHB_VehicleSpeedInvalid(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PEPS_PowerMode_PEPS_PowerMode(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PEPS_PowerModeValidity_PEPS_PowerModeValidity(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_TBOX_Day_TBOX_Day(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_TBOX_Hour_TBOX_Hour(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_TBOX_Minute_TBOX_Minute(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_TBOX_Month_TBOX_Month(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_TBOX_Second_TBOX_Second(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_TBOX_Year_TBOX_Year(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data);
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
#define Rte_Read_AC_AmbientTemperature_AC_AmbientTemperature Rte_Read_ComRx_CAN_AC_AmbientTemperature_AC_AmbientTemperature
#define Rte_Read_AC_AmbientTemperatureInvalid_AC_AmbientTemperatureInvalid Rte_Read_ComRx_CAN_AC_AmbientTemperatureInvalid_AC_AmbientTemperatureInvalid
#define Rte_Read_BMSH_BatCurrent_BMSH_BatCurrent Rte_Read_ComRx_CAN_BMSH_BatCurrent_BMSH_BatCurrent
#define Rte_Read_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag Rte_Read_ComRx_CAN_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag
#define Rte_Read_BMSH_BusVolt_BMSH_BusVolt Rte_Read_ComRx_CAN_BMSH_BusVolt_BMSH_BusVolt
#define Rte_Read_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag Rte_Read_ComRx_CAN_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag
#define Rte_Read_BMSH_Status_AliveCounter_BMSH_Status_AliveCounter Rte_Read_ComRx_CAN_BMSH_Status_AliveCounter_BMSH_Status_AliveCounter
#define Rte_Read_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay Rte_Read_ComRx_CAN_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay
#define Rte_Read_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay Rte_Read_ComRx_CAN_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay
#define Rte_Read_BMSH_StsMode_BMSH_StsMode Rte_Read_ComRx_CAN_BMSH_StsMode_BMSH_StsMode
#define Rte_Read_BMSH_VCU_Crash_BMSH_VCU_Crash Rte_Read_ComRx_CAN_BMSH_VCU_Crash_BMSH_VCU_Crash
#define Rte_Read_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter Rte_Read_ComRx_CAN_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter
#define Rte_Read_EHB_EPBStatus_EHB_EPBStatus Rte_Read_ComRx_CAN_EHB_EPBStatus_EHB_EPBStatus
#define Rte_Read_EHB_FLWheelDirection_EHB_FLWheelDirection Rte_Read_ComRx_CAN_EHB_FLWheelDirection_EHB_FLWheelDirection
#define Rte_Read_EHB_FLWheelSpeedInvalid_EHB_FLWheelSpeedInvalid Rte_Read_ComRx_CAN_EHB_FLWheelSpeedInvalid_EHB_FLWheelSpeedInvalid
#define Rte_Read_EHB_FLWheelSpeedKPH_EHB_FLWheelSpeedKPH Rte_Read_ComRx_CAN_EHB_FLWheelSpeedKPH_EHB_FLWheelSpeedKPH
#define Rte_Read_EHB_FRWheelDirection_EHB_FRWheelDirection Rte_Read_ComRx_CAN_EHB_FRWheelDirection_EHB_FRWheelDirection
#define Rte_Read_EHB_FRWheelSpeedInvalid_EHB_FRWheelSpeedInvalid Rte_Read_ComRx_CAN_EHB_FRWheelSpeedInvalid_EHB_FRWheelSpeedInvalid
#define Rte_Read_EHB_FRWheelSpeedKPH_EHB_FRWheelSpeedKPH Rte_Read_ComRx_CAN_EHB_FRWheelSpeedKPH_EHB_FRWheelSpeedKPH
#define Rte_Read_EHB_RLWheelDirection_EHB_RLWheelDirection Rte_Read_ComRx_CAN_EHB_RLWheelDirection_EHB_RLWheelDirection
#define Rte_Read_EHB_RLWheelSpeedInvalid_EHB_RLWheelSpeedInvalid Rte_Read_ComRx_CAN_EHB_RLWheelSpeedInvalid_EHB_RLWheelSpeedInvalid
#define Rte_Read_EHB_RLWheelSpeedKPH_EHB_RLWheelSpeedKPH Rte_Read_ComRx_CAN_EHB_RLWheelSpeedKPH_EHB_RLWheelSpeedKPH
#define Rte_Read_EHB_RRWheelDirection_EHB_RRWheelDirection Rte_Read_ComRx_CAN_EHB_RRWheelDirection_EHB_RRWheelDirection
#define Rte_Read_EHB_RRWheelSpeedInvalid_EHB_RRWheelSpeedInvalid Rte_Read_ComRx_CAN_EHB_RRWheelSpeedInvalid_EHB_RRWheelSpeedInvalid
#define Rte_Read_EHB_RRWheelSpeedKPH_EHB_RRWheelSpeedKPH Rte_Read_ComRx_CAN_EHB_RRWheelSpeedKPH_EHB_RRWheelSpeedKPH
#define Rte_Read_EHB_VehicleSpeed_EHB_VehicleSpeed Rte_Read_ComRx_CAN_EHB_VehicleSpeed_EHB_VehicleSpeed
#define Rte_Read_EHB_VehicleSpeedInvalid_EHB_VehicleSpeedInvalid Rte_Read_ComRx_CAN_EHB_VehicleSpeedInvalid_EHB_VehicleSpeedInvalid
#define Rte_Read_PEPS_PowerMode_PEPS_PowerMode Rte_Read_ComRx_CAN_PEPS_PowerMode_PEPS_PowerMode
#define Rte_Read_PEPS_PowerModeValidity_PEPS_PowerModeValidity Rte_Read_ComRx_CAN_PEPS_PowerModeValidity_PEPS_PowerModeValidity
#define Rte_Read_PMS_Command_AliveCounter_PMS_Command_AliveCounter Rte_Read_ComRx_CAN_PMS_Command_AliveCounter_PMS_Command_AliveCounter
#define Rte_Read_PMS_Command_Checksum_PMS_Command_Checksum Rte_Read_ComRx_CAN_PMS_Command_Checksum_PMS_Command_Checksum
#define Rte_Read_PMS_CurrentGearPosition_PMS_CurrentGearPosition Rte_Read_ComRx_CAN_PMS_CurrentGearPosition_PMS_CurrentGearPosition
#define Rte_Read_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid Rte_Read_ComRx_CAN_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid
#define Rte_Read_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp Rte_Read_ComRx_CAN_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp
#define Rte_Read_PMS_EDCPEnable_PMS_EDCPEnable Rte_Read_ComRx_CAN_PMS_EDCPEnable_PMS_EDCPEnable
#define Rte_Read_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl Rte_Read_ComRx_CAN_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl
#define Rte_Read_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad Rte_Read_ComRx_CAN_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad
#define Rte_Read_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd Rte_Read_ComRx_CAN_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd
#define Rte_Read_PMS_IgnONSts_PMS_IgnONSts Rte_Read_ComRx_CAN_PMS_IgnONSts_PMS_IgnONSts
#define Rte_Read_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq Rte_Read_ComRx_CAN_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq
#define Rte_Read_PMS_IsgModReq_PMS_IsgModReq Rte_Read_ComRx_CAN_PMS_IsgModReq_PMS_IsgModReq
#define Rte_Read_PMS_IsgTqReq_PMS_IsgTqReq Rte_Read_ComRx_CAN_PMS_IsgTqReq_PMS_IsgTqReq
#define Rte_Read_PMS_NMSts_PMS_NMSts Rte_Read_ComRx_CAN_PMS_NMSts_PMS_NMSts
#define Rte_Read_PMS_Real_PedalPosition_PMS_Real_PedalPosition Rte_Read_ComRx_CAN_PMS_Real_PedalPosition_PMS_Real_PedalPosition
#define Rte_Read_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid Rte_Read_ComRx_CAN_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid
#define Rte_Read_PMS_Stayawake_reasons_PMS_Stayawake_reasons Rte_Read_ComRx_CAN_PMS_Stayawake_reasons_PMS_Stayawake_reasons
#define Rte_Read_PMS_StsBrkSwitch1_PMS_StsBrkSwitch1 Rte_Read_ComRx_CAN_PMS_StsBrkSwitch1_PMS_StsBrkSwitch1
#define Rte_Read_PMS_StsBrkSwitch1Invalid_PMS_StsBrkSwitch1Invalid Rte_Read_ComRx_CAN_PMS_StsBrkSwitch1Invalid_PMS_StsBrkSwitch1Invalid
#define Rte_Read_PMS_Wakeup_reasons_PMS_Wakeup_reasons Rte_Read_ComRx_CAN_PMS_Wakeup_reasons_PMS_Wakeup_reasons
#define Rte_Read_TBOX_Day_TBOX_Day Rte_Read_ComRx_CAN_TBOX_Day_TBOX_Day
#define Rte_Read_TBOX_Hour_TBOX_Hour Rte_Read_ComRx_CAN_TBOX_Hour_TBOX_Hour
#define Rte_Read_TBOX_Minute_TBOX_Minute Rte_Read_ComRx_CAN_TBOX_Minute_TBOX_Minute
#define Rte_Read_TBOX_Month_TBOX_Month Rte_Read_ComRx_CAN_TBOX_Month_TBOX_Month
#define Rte_Read_TBOX_Second_TBOX_Second Rte_Read_ComRx_CAN_TBOX_Second_TBOX_Second
#define Rte_Read_TBOX_Year_TBOX_Year Rte_Read_ComRx_CAN_TBOX_Year_TBOX_Year
#define Rte_Read_VCU_CrashOutputSts_VCU_CrashOutputSts Rte_Read_ComRx_CAN_VCU_CrashOutputSts_VCU_CrashOutputSts
#define Rte_Read_BMSH_ActiveWakeupBit_BMSH_ActiveWakeupBit Rte_Read_ComRx_CAN_BMSH_ActiveWakeupBit_BMSH_ActiveWakeupBit
#define Rte_Read_BMSH_Address_BMSH_Address Rte_Read_ComRx_CAN_BMSH_Address_BMSH_Address
#define Rte_Read_BMSH_NMSts_BMSH_NMSts Rte_Read_ComRx_CAN_BMSH_NMSts_BMSH_NMSts
#define Rte_Read_BMSH_RMR_BMSH_RMR Rte_Read_ComRx_CAN_BMSH_RMR_BMSH_RMR
#define Rte_Read_BMSH_Status_CheckSum_BMSH_Status_CheckSum Rte_Read_ComRx_CAN_BMSH_Status_CheckSum_BMSH_Status_CheckSum
#define Rte_Read_BMSH_StayAwake_Reasons_BMSH_StayAwake_Reasons Rte_Read_ComRx_CAN_BMSH_StayAwake_Reasons_BMSH_StayAwake_Reasons
#define Rte_Read_BMSH_VoltCurrent_CheckSum_BMSH_VoltCurrent_CheckSum Rte_Read_ComRx_CAN_BMSH_VoltCurrent_CheckSum_BMSH_VoltCurrent_CheckSum
#define Rte_Read_BMSH_WakeUp_Reasons_BMSH_WakeUp_Reasons Rte_Read_ComRx_CAN_BMSH_WakeUp_Reasons_BMSH_WakeUp_Reasons
#define Rte_Read_EHB_FrontWheelSpeedsKPH_AliveCounter_EHB_FrontWheelSpeedsKPH_AliveCounter Rte_Read_ComRx_CAN_EHB_FrontWheelSpeedsKPH_AliveCounter_EHB_FrontWheelSpeedsKPH_AliveCounter
#define Rte_Read_EHB_FrontWheelSpeedsKPH_CheckSum_EHB_FrontWheelSpeedsKPH_CheckSum Rte_Read_ComRx_CAN_EHB_FrontWheelSpeedsKPH_CheckSum_EHB_FrontWheelSpeedsKPH_CheckSum
#define Rte_Read_EHB_RearWheelSpeedsKPH_EHB_RearWheelSpeedsKPH Rte_Read_ComRx_CAN_EHB_RearWheelSpeedsKPH_EHB_RearWheelSpeedsKPH
#define Rte_Read_EHB_RearWheelSpeedsKPH_AliveCounter_EHB_RearWheelSpeedsKPH_AliveCounter Rte_Read_ComRx_CAN_EHB_RearWheelSpeedsKPH_AliveCounter_EHB_RearWheelSpeedsKPH_AliveCounter
#define Rte_Read_EHB_RearWheelSpeedsKPH_CheckSum_EHB_RearWheelSpeedsKPH_CheckSum Rte_Read_ComRx_CAN_EHB_RearWheelSpeedsKPH_CheckSum_EHB_RearWheelSpeedsKPH_CheckSum
#define Rte_Read_EHB_Status_AliveCounter_EHB_Status_AliveCounter Rte_Read_ComRx_CAN_EHB_Status_AliveCounter_EHB_Status_AliveCounter
#define Rte_Read_EHB_Status_CheckSum_EHB_Status_CheckSum Rte_Read_ComRx_CAN_EHB_Status_CheckSum_EHB_Status_CheckSum
#define Rte_Read_IPK_IPKTotalOdometer_IPK_IPKTotalOdometer Rte_Read_ComRx_CAN_IPK_IPKTotalOdometer_IPK_IPKTotalOdometer
#define Rte_Read_PMS_AWB_PMS_AWB Rte_Read_ComRx_CAN_PMS_AWB_PMS_AWB
#define Rte_Read_PMS_IPUFlowFeedback_PMS_IPUFlowFeedback Rte_Read_ComRx_CAN_PMS_IPUFlowFeedback_PMS_IPUFlowFeedback
#define Rte_Read_PMS_RMR_PMS_RMR Rte_Read_ComRx_CAN_PMS_RMR_PMS_RMR
#define Rte_Read_PMS_TM_Address_PMS_TM_Address Rte_Read_ComRx_CAN_PMS_TM_Address_PMS_TM_Address
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
#define Rte_Write_AC_AmbientTemperatureInvalid_Rx_AC_AmbientTemperatureInvalid_Rx Rte_Write_ComRx_CAN_AC_AmbientTemperatureInvalid_Rx_AC_AmbientTemperatureInvalid_Rx
#define Rte_Write_AC_AmbientTemperature_Rx_AC_AmbientTemperature_Rx Rte_Write_ComRx_CAN_AC_AmbientTemperature_Rx_AC_AmbientTemperature_Rx
#define Rte_Write_BMSH_ActiveWakeupBit_Rx_BMSH_ActiveWakeupBit_Rx Rte_Write_ComRx_CAN_BMSH_ActiveWakeupBit_Rx_BMSH_ActiveWakeupBit_Rx
#define Rte_Write_BMSH_Address_Rx_BMSH_Address_Rx Rte_Write_ComRx_CAN_BMSH_Address_Rx_BMSH_Address_Rx
#define Rte_Write_BMSH_BatCurrentValidFlag_Rx_BMSH_BatCurrentValidFlag_Rx Rte_Write_ComRx_CAN_BMSH_BatCurrentValidFlag_Rx_BMSH_BatCurrentValidFlag_Rx
#define Rte_Write_BMSH_BatCurrent_Rx_BMSH_BatCurrent_Rx Rte_Write_ComRx_CAN_BMSH_BatCurrent_Rx_BMSH_BatCurrent_Rx
#define Rte_Write_BMSH_BusVolt_Rx_BMSH_BusVolt_Rx Rte_Write_ComRx_CAN_BMSH_BusVolt_Rx_BMSH_BusVolt_Rx
#define Rte_Write_BMSH_NMSts_Rx_BMSH_NMSts_Rx Rte_Write_ComRx_CAN_BMSH_NMSts_Rx_BMSH_NMSts_Rx
#define Rte_Write_BMSH_PackVoltValidFlag_Rx_BMSH_PackVoltValidFlag_Rx Rte_Write_ComRx_CAN_BMSH_PackVoltValidFlag_Rx_BMSH_PackVoltValidFlag_Rx
#define Rte_Write_BMSH_RMR_Rx_BMSH_RMR_Rx Rte_Write_ComRx_CAN_BMSH_RMR_Rx_BMSH_RMR_Rx
#define Rte_Write_BMSH_Status_AliveCounter_Rx_BMSH_Status_AliveCounter_Rx Rte_Write_ComRx_CAN_BMSH_Status_AliveCounter_Rx_BMSH_Status_AliveCounter_Rx
#define Rte_Write_BMSH_Status_CheckSum_Rx_BMSH_Status_CheckSum_Rx Rte_Write_ComRx_CAN_BMSH_Status_CheckSum_Rx_BMSH_Status_CheckSum_Rx
#define Rte_Write_BMSH_StayAwake_Reasons_Rx_BMSH_StayAwake_Reasons_Rx Rte_Write_ComRx_CAN_BMSH_StayAwake_Reasons_Rx_BMSH_StayAwake_Reasons_Rx
#define Rte_Write_BMSH_StsMainNegtiveRelay_Rx_BMSH_StsMainNegtiveRelay_Rx Rte_Write_ComRx_CAN_BMSH_StsMainNegtiveRelay_Rx_BMSH_StsMainNegtiveRelay_Rx
#define Rte_Write_BMSH_StsMainPositiveRelay_Rx_BMSH_StsMainPositiveRelay_Rx Rte_Write_ComRx_CAN_BMSH_StsMainPositiveRelay_Rx_BMSH_StsMainPositiveRelay_Rx
#define Rte_Write_BMSH_StsMode_Rx_BMSH_StsMode_Rx Rte_Write_ComRx_CAN_BMSH_StsMode_Rx_BMSH_StsMode_Rx
#define Rte_Write_BMSH_VCU_Crash_Rx_BMSH_VCU_Crash_Rx Rte_Write_ComRx_CAN_BMSH_VCU_Crash_Rx_BMSH_VCU_Crash_Rx
#define Rte_Write_BMSH_VoltCurrent_AliveCounter_Rx_BMSH_VoltCurrent_AliveCounter_Rx Rte_Write_ComRx_CAN_BMSH_VoltCurrent_AliveCounter_Rx_BMSH_VoltCurrent_AliveCounter_Rx
#define Rte_Write_BMSH_VoltCurrent_CheckSum_Rx_BMSH_VoltCurrent_CheckSum_Rx Rte_Write_ComRx_CAN_BMSH_VoltCurrent_CheckSum_Rx_BMSH_VoltCurrent_CheckSum_Rx
#define Rte_Write_BMSH_WakeUp_Reasons_Rx_BMSH_WakeUp_Reasons_Rx Rte_Write_ComRx_CAN_BMSH_WakeUp_Reasons_Rx_BMSH_WakeUp_Reasons_Rx
#define Rte_Write_ComRx_IgnONSts_ComRx_IgnONSts Rte_Write_ComRx_CAN_ComRx_IgnONSts_ComRx_IgnONSts
#define Rte_Write_ComRx_IsgActvDampgModReq_ComRx_IsgActvDampgModReq Rte_Write_ComRx_CAN_ComRx_IsgActvDampgModReq_ComRx_IsgActvDampgModReq
#define Rte_Write_ComRx_Status_AliveCounter_ComRx_Status_AliveCounter Rte_Write_ComRx_CAN_ComRx_Status_AliveCounter_ComRx_Status_AliveCounter
#define Rte_Write_ComRx_Status_Checksum_ComRx_Status_Checksum Rte_Write_ComRx_CAN_ComRx_Status_Checksum_ComRx_Status_Checksum
#define Rte_Write_ComRx_VehicleSpd_ComRx_VehicleSpd Rte_Write_ComRx_CAN_ComRx_VehicleSpd_ComRx_VehicleSpd
#define Rte_Write_ComRx_bAcceleratorPedal_flag_ComRx_bAcceleratorPedal_flag Rte_Write_ComRx_CAN_ComRx_bAcceleratorPedal_flag_ComRx_bAcceleratorPedal_flag
#define Rte_Write_ComRx_bCrcChksFlt_ComRx_bCrcChksFlt Rte_Write_ComRx_CAN_ComRx_bCrcChksFlt_ComRx_bCrcChksFlt
#define Rte_Write_ComRx_bDampgSwtActv_ComRx_bDampgSwtActv Rte_Write_ComRx_CAN_ComRx_bDampgSwtActv_ComRx_bDampgSwtActv
#define Rte_Write_ComRx_bDriveModeInd_ComRx_bDriveModeInd Rte_Write_ComRx_CAN_ComRx_bDriveModeInd_ComRx_bDriveModeInd
#define Rte_Write_ComRx_bEmgyDchrgReq_ComRx_bEmgyDchrgReq Rte_Write_ComRx_CAN_ComRx_bEmgyDchrgReq_ComRx_bEmgyDchrgReq
#define Rte_Write_ComRx_bErrEmgyShtofCrash_ComRx_bErrEmgyShtofCrash Rte_Write_ComRx_CAN_ComRx_bErrEmgyShtofCrash_ComRx_bErrEmgyShtofCrash
#define Rte_Write_ComRx_bGearPositionInd_ComRx_bGearPositionInd Rte_Write_ComRx_CAN_ComRx_bGearPositionInd_ComRx_bGearPositionInd
#define Rte_Write_ComRx_bMcuCutOffLv_ComRx_bMcuCutOffLv Rte_Write_ComRx_CAN_ComRx_bMcuCutOffLv_ComRx_bMcuCutOffLv
#define Rte_Write_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq Rte_Write_ComRx_CAN_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq
#define Rte_Write_ComRx_bOdmtBkupEna_ComRx_bOdmtBkupEna Rte_Write_ComRx_CAN_ComRx_bOdmtBkupEna_ComRx_bOdmtBkupEna
#define Rte_Write_ComRx_bOil_HV_OFF_ComRx_bOil_HV_OFF Rte_Write_ComRx_CAN_ComRx_bOil_HV_OFF_ComRx_bOil_HV_OFF
#define Rte_Write_ComRx_bPTReadyInd_ComRx_bPTReadyInd Rte_Write_ComRx_CAN_ComRx_bPTReadyInd_ComRx_bPTReadyInd
#define Rte_Write_ComRx_bPowerModeValidity_ComRx_bPowerModeValidity Rte_Write_ComRx_CAN_ComRx_bPowerModeValidity_ComRx_bPowerModeValidity
#define Rte_Write_ComRx_bRollgCntrFlt_ComRx_bRollgCntrFlt Rte_Write_ComRx_CAN_ComRx_bRollgCntrFlt_ComRx_bRollgCntrFlt
#define Rte_Write_ComRx_bT15_ComRx_bT15 Rte_Write_ComRx_CAN_ComRx_bT15_ComRx_bT15
#define Rte_Write_ComRx_bVehicleSpd_flag_ComRx_bVehicleSpd_flag Rte_Write_ComRx_CAN_ComRx_bVehicleSpd_flag_ComRx_bVehicleSpd_flag
#define Rte_Write_ComRx_dstTotalOdometer_ComRx_dstTotalOdometer Rte_Write_ComRx_CAN_ComRx_dstTotalOdometer_ComRx_dstTotalOdometer
#define Rte_Write_ComRx_dstTotalVehicleDistance_ComRx_dstTotalVehicleDistance Rte_Write_ComRx_CAN_ComRx_dstTotalVehicleDistance_ComRx_dstTotalVehicleDistance
#define Rte_Write_ComRx_facTqSlopMax_ComRx_facTqSlopMax Rte_Write_ComRx_CAN_ComRx_facTqSlopMax_ComRx_facTqSlopMax
#define Rte_Write_ComRx_iEfcDes_ComRx_iEfcDes Rte_Write_ComRx_CAN_ComRx_iEfcDes_ComRx_iEfcDes
#define Rte_Write_ComRx_nDes_ComRx_nDes Rte_Write_ComRx_CAN_ComRx_nDes_ComRx_nDes
#define Rte_Write_ComRx_pctAcceleratorPedalPosition_ComRx_pctAcceleratorPedalPosition Rte_Write_ComRx_CAN_ComRx_pctAcceleratorPedalPosition_ComRx_pctAcceleratorPedalPosition
#define Rte_Write_ComRx_pctBrakePedalPosition_ComRx_pctBrakePedalPosition Rte_Write_ComRx_CAN_ComRx_pctBrakePedalPosition_ComRx_pctBrakePedalPosition
#define Rte_Write_ComRx_posBattSOC_ComRx_posBattSOC Rte_Write_ComRx_CAN_ComRx_posBattSOC_ComRx_posBattSOC
#define Rte_Write_ComRx_stBrkSwt_ComRx_stBrkSwt Rte_Write_ComRx_CAN_ComRx_stBrkSwt_ComRx_stBrkSwt
#define Rte_Write_ComRx_stCrashOutputSts_ComRx_stCrashOutputSts Rte_Write_ComRx_CAN_ComRx_stCrashOutputSts_ComRx_stCrashOutputSts
#define Rte_Write_ComRx_stCtrlAliveCnt_ComRx_stCtrlAliveCnt Rte_Write_ComRx_CAN_ComRx_stCtrlAliveCnt_ComRx_stCtrlAliveCnt
#define Rte_Write_ComRx_stCtrlCheckSum_ComRx_stCtrlCheckSum Rte_Write_ComRx_CAN_ComRx_stCtrlCheckSum_ComRx_stCtrlCheckSum
#define Rte_Write_ComRx_stDrvCtrlDes_ComRx_stDrvCtrlDes Rte_Write_ComRx_CAN_ComRx_stDrvCtrlDes_ComRx_stDrvCtrlDes
#define Rte_Write_ComRx_stDrvGear_ComRx_stDrvGear Rte_Write_ComRx_CAN_ComRx_stDrvGear_ComRx_stDrvGear
#define Rte_Write_ComRx_stEMTrqSpdCtrl_AliveCnt_ComRx_stEMTrqSpdCtrl_AliveCnt Rte_Write_ComRx_CAN_ComRx_stEMTrqSpdCtrl_AliveCnt_ComRx_stEMTrqSpdCtrl_AliveCnt
#define Rte_Write_ComRx_stEMTrqSpdCtrl_Checksum_ComRx_stEMTrqSpdCtrl_Checksum Rte_Write_ComRx_CAN_ComRx_stEMTrqSpdCtrl_Checksum_ComRx_stEMTrqSpdCtrl_Checksum
#define Rte_Write_ComRx_stEmCtrlMod_ComRx_stEmCtrlMod Rte_Write_ComRx_CAN_ComRx_stEmCtrlMod_ComRx_stEmCtrlMod
#define Rte_Write_ComRx_stEmWrkMod_ComRx_stEmWrkMod Rte_Write_ComRx_CAN_ComRx_stEmWrkMod_ComRx_stEmWrkMod
#define Rte_Write_ComRx_stHVLoopWorkSts_ComRx_stHVLoopWorkSts Rte_Write_ComRx_CAN_ComRx_stHVLoopWorkSts_ComRx_stHVLoopWorkSts
#define Rte_Write_ComRx_stHndbrk_ComRx_stHndbrk Rte_Write_ComRx_CAN_ComRx_stHndbrk_ComRx_stHndbrk
#define Rte_Write_ComRx_stHvCntctr_ComRx_stHvCntctr Rte_Write_ComRx_CAN_ComRx_stHvCntctr_ComRx_stHvCntctr
#define Rte_Write_ComRx_stMainPosConnSts_ComRx_stMainPosConnSts Rte_Write_ComRx_CAN_ComRx_stMainPosConnSts_ComRx_stMainPosConnSts
#define Rte_Write_ComRx_stPowerMode_ComRx_stPowerMode Rte_Write_ComRx_CAN_ComRx_stPowerMode_ComRx_stPowerMode
#define Rte_Write_ComRx_tCooltInletEm_ComRx_tCooltInletEm Rte_Write_ComRx_CAN_ComRx_tCooltInletEm_ComRx_tCooltInletEm
#define Rte_Write_ComRx_tExtEnv_ComRx_tExtEnv Rte_Write_ComRx_CAN_ComRx_tExtEnv_ComRx_tExtEnv
#define Rte_Write_ComRx_tIvtrCooltInlet_ComRx_tIvtrCooltInlet Rte_Write_ComRx_CAN_ComRx_tIvtrCooltInlet_ComRx_tIvtrCooltInlet
#define Rte_Write_ComRx_tiDay_ComRx_tiDay Rte_Write_ComRx_CAN_ComRx_tiDay_ComRx_tiDay
#define Rte_Write_ComRx_tiHour_ComRx_tiHour Rte_Write_ComRx_CAN_ComRx_tiHour_ComRx_tiHour
#define Rte_Write_ComRx_tiMinute_ComRx_tiMinute Rte_Write_ComRx_CAN_ComRx_tiMinute_ComRx_tiMinute
#define Rte_Write_ComRx_tiMonth_ComRx_tiMonth Rte_Write_ComRx_CAN_ComRx_tiMonth_ComRx_tiMonth
#define Rte_Write_ComRx_tiSecond_ComRx_tiSecond Rte_Write_ComRx_CAN_ComRx_tiSecond_ComRx_tiSecond
#define Rte_Write_ComRx_tiYear_ComRx_tiYear Rte_Write_ComRx_CAN_ComRx_tiYear_ComRx_tiYear
#define Rte_Write_ComRx_tqDes_ComRx_tqDes Rte_Write_ComRx_CAN_ComRx_tqDes_ComRx_tqDes
#define Rte_Write_ComRx_tqMaxLim_ComRx_tqMaxLim Rte_Write_ComRx_CAN_ComRx_tqMaxLim_ComRx_tqMaxLim
#define Rte_Write_ComRx_tqMinLim_ComRx_tqMinLim Rte_Write_ComRx_CAN_ComRx_tqMinLim_ComRx_tqMinLim
#define Rte_Write_ComRx_uDCLnkDes_ComRx_uDCLnkDes Rte_Write_ComRx_CAN_ComRx_uDCLnkDes_ComRx_uDCLnkDes
#define Rte_Write_EHB_EPBStatus_Rx_EHB_EPBStatus_Rx Rte_Write_ComRx_CAN_EHB_EPBStatus_Rx_EHB_EPBStatus_Rx
#define Rte_Write_EHB_FLWheelDirection_Rx_EHB_FLWheelDirection_Rx Rte_Write_ComRx_CAN_EHB_FLWheelDirection_Rx_EHB_FLWheelDirection_Rx
#define Rte_Write_EHB_FLWheelSpeedInvalid_Rx_EHB_FLWheelSpeedInvalid_Rx Rte_Write_ComRx_CAN_EHB_FLWheelSpeedInvalid_Rx_EHB_FLWheelSpeedInvalid_Rx
#define Rte_Write_EHB_FLWheelSpeedKPH_Rx_EHB_FLWheelSpeedKPH_Rx Rte_Write_ComRx_CAN_EHB_FLWheelSpeedKPH_Rx_EHB_FLWheelSpeedKPH_Rx
#define Rte_Write_EHB_FRWheelDirection_Rx_EHB_FRWheelDirection_Rx Rte_Write_ComRx_CAN_EHB_FRWheelDirection_Rx_EHB_FRWheelDirection_Rx
#define Rte_Write_EHB_FRWheelSpeedInvalid_Rx_EHB_FRWheelSpeedInvalid_Rx Rte_Write_ComRx_CAN_EHB_FRWheelSpeedInvalid_Rx_EHB_FRWheelSpeedInvalid_Rx
#define Rte_Write_EHB_FRWheelSpeedKPH_Rx_EHB_FRWheelSpeedKPH_Rx Rte_Write_ComRx_CAN_EHB_FRWheelSpeedKPH_Rx_EHB_FRWheelSpeedKPH_Rx
#define Rte_Write_EHB_FrontWheelSpeedsKPH_AliveCounter_Rx_EHB_FrontWheelSpeedsKPH_AliveCounter_Rx Rte_Write_ComRx_CAN_EHB_FrontWheelSpeedsKPH_AliveCounter_Rx_EHB_FrontWheelSpeedsKPH_AliveCounter_Rx
#define Rte_Write_EHB_FrontWheelSpeedsKPH_CheckSum_Rx_EHB_FrontWheelSpeedsKPH_CheckSum_Rx Rte_Write_ComRx_CAN_EHB_FrontWheelSpeedsKPH_CheckSum_Rx_EHB_FrontWheelSpeedsKPH_CheckSum_Rx
#define Rte_Write_EHB_RLWheelDirection_Rx_EHB_RLWheelDirection_Rx Rte_Write_ComRx_CAN_EHB_RLWheelDirection_Rx_EHB_RLWheelDirection_Rx
#define Rte_Write_EHB_RLWheelSpeedInvalid_Rx_EHB_RLWheelSpeedInvalid_Rx Rte_Write_ComRx_CAN_EHB_RLWheelSpeedInvalid_Rx_EHB_RLWheelSpeedInvalid_Rx
#define Rte_Write_EHB_RLWheelSpeedKPH_Rx_EHB_RLWheelSpeedKPH_Rx Rte_Write_ComRx_CAN_EHB_RLWheelSpeedKPH_Rx_EHB_RLWheelSpeedKPH_Rx
#define Rte_Write_EHB_RRWheelDirection_Rx_EHB_RRWheelDirection_Rx Rte_Write_ComRx_CAN_EHB_RRWheelDirection_Rx_EHB_RRWheelDirection_Rx
#define Rte_Write_EHB_RRWheelSpeedInvalid_Rx_EHB_RRWheelSpeedInvalid_Rx Rte_Write_ComRx_CAN_EHB_RRWheelSpeedInvalid_Rx_EHB_RRWheelSpeedInvalid_Rx
#define Rte_Write_EHB_RRWheelSpeedKPH_Rx_EHB_RRWheelSpeedKPH_Rx Rte_Write_ComRx_CAN_EHB_RRWheelSpeedKPH_Rx_EHB_RRWheelSpeedKPH_Rx
#define Rte_Write_EHB_RearWheelSpeedsKPH_AliveCounter_Rx_EHB_RearWheelSpeedsKPH_AliveCounter_Rx Rte_Write_ComRx_CAN_EHB_RearWheelSpeedsKPH_AliveCounter_Rx_EHB_RearWheelSpeedsKPH_AliveCounter_Rx
#define Rte_Write_EHB_RearWheelSpeedsKPH_CheckSum_Rx_EHB_RearWheelSpeedsKPH_CheckSum_Rx Rte_Write_ComRx_CAN_EHB_RearWheelSpeedsKPH_CheckSum_Rx_EHB_RearWheelSpeedsKPH_CheckSum_Rx
#define Rte_Write_EHB_RearWheelSpeedsKPH_Rx_EHB_RearWheelSpeedsKPH_Rx Rte_Write_ComRx_CAN_EHB_RearWheelSpeedsKPH_Rx_EHB_RearWheelSpeedsKPH_Rx
#define Rte_Write_EHB_Status_AliveCounter_Rx_EHB_Status_AliveCounter_Rx Rte_Write_ComRx_CAN_EHB_Status_AliveCounter_Rx_EHB_Status_AliveCounter_Rx
#define Rte_Write_EHB_Status_CheckSum_Rx_EHB_Status_CheckSum_Rx Rte_Write_ComRx_CAN_EHB_Status_CheckSum_Rx_EHB_Status_CheckSum_Rx
#define Rte_Write_EHB_VehicleSpeedInvalid_Rx_EHB_VehicleSpeedInvalid_Rx Rte_Write_ComRx_CAN_EHB_VehicleSpeedInvalid_Rx_EHB_VehicleSpeedInvalid_Rx
#define Rte_Write_EHB_VehicleSpeed_Rx_EHB_VehicleSpeed_Rx Rte_Write_ComRx_CAN_EHB_VehicleSpeed_Rx_EHB_VehicleSpeed_Rx
#define Rte_Write_IPK_IPKTotalOdometer_Rx_IPK_IPKTotalOdometer_Rx Rte_Write_ComRx_CAN_IPK_IPKTotalOdometer_Rx_IPK_IPKTotalOdometer_Rx
#define Rte_Write_PEPS_PowerModeValidity_Rx_PEPS_PowerModeValidity_Rx Rte_Write_ComRx_CAN_PEPS_PowerModeValidity_Rx_PEPS_PowerModeValidity_Rx
#define Rte_Write_PEPS_PowerMode_Rx_PEPS_PowerMode_Rx Rte_Write_ComRx_CAN_PEPS_PowerMode_Rx_PEPS_PowerMode_Rx
#define Rte_Write_PMS_AWB_Rx_PMS_AWB_Rx Rte_Write_ComRx_CAN_PMS_AWB_Rx_PMS_AWB_Rx
#define Rte_Write_PMS_Command_AliveCounter_Rx_PMS_Command_AliveCounter_Rx Rte_Write_ComRx_CAN_PMS_Command_AliveCounter_Rx_PMS_Command_AliveCounter_Rx
#define Rte_Write_PMS_Command_Checksum_Rx_PMS_Command_Checksum_Rx Rte_Write_ComRx_CAN_PMS_Command_Checksum_Rx_PMS_Command_Checksum_Rx
#define Rte_Write_PMS_CurrentGearPosition_Rx_PMS_CurrentGearPosition_Rx Rte_Write_ComRx_CAN_PMS_CurrentGearPosition_Rx_PMS_CurrentGearPosition_Rx
#define Rte_Write_PMS_CurrentGearPosition_Valid_Rx_PMS_CurrentGearPosition_Valid_Rx Rte_Write_ComRx_CAN_PMS_CurrentGearPosition_Valid_Rx_PMS_CurrentGearPosition_Valid_Rx
#define Rte_Write_PMS_DriveCircuitTemp_Rx_PMS_DriveCircuitTemp_Rx Rte_Write_ComRx_CAN_PMS_DriveCircuitTemp_Rx_PMS_DriveCircuitTemp_Rx
#define Rte_Write_PMS_EDCPEnable_Rx_PMS_EDCPEnable_Rx Rte_Write_ComRx_CAN_PMS_EDCPEnable_Rx_PMS_EDCPEnable_Rx
#define Rte_Write_PMS_EDCPPWMCtrl_Rx_PMS_EDCPPWMCtrl_Rx Rte_Write_ComRx_CAN_PMS_EDCPPWMCtrl_Rx_PMS_EDCPPWMCtrl_Rx
#define Rte_Write_PMS_FrntHeatModEnad_Rx_PMS_FrntHeatModEnad_Rx Rte_Write_ComRx_CAN_PMS_FrntHeatModEnad_Rx_PMS_FrntHeatModEnad_Rx
#define Rte_Write_PMS_FrntHeatPwrAllwd_Rx_PMS_FrntHeatPwrAllwd_Rx Rte_Write_ComRx_CAN_PMS_FrntHeatPwrAllwd_Rx_PMS_FrntHeatPwrAllwd_Rx
#define Rte_Write_PMS_IPUFlowFeedback_Rx_PMS_IPUFlowFeedback_Rx Rte_Write_ComRx_CAN_PMS_IPUFlowFeedback_Rx_PMS_IPUFlowFeedback_Rx
#define Rte_Write_PMS_IgnONSts_Rx_PMS_IgnONSts_Rx Rte_Write_ComRx_CAN_PMS_IgnONSts_Rx_PMS_IgnONSts_Rx
#define Rte_Write_PMS_IsgActvDampgModReq_Rx_PMS_IsgActvDampgModReq_Rx Rte_Write_ComRx_CAN_PMS_IsgActvDampgModReq_Rx_PMS_IsgActvDampgModReq_Rx
#define Rte_Write_PMS_IsgModReq_Rx_PMS_IsgModReq_Rx Rte_Write_ComRx_CAN_PMS_IsgModReq_Rx_PMS_IsgModReq_Rx
#define Rte_Write_PMS_IsgTqReq_Rx_PMS_IsgTqReq_Rx Rte_Write_ComRx_CAN_PMS_IsgTqReq_Rx_PMS_IsgTqReq_Rx
#define Rte_Write_PMS_NMSts_Rx_PMS_NMSts_Rx Rte_Write_ComRx_CAN_PMS_NMSts_Rx_PMS_NMSts_Rx
#define Rte_Write_PMS_RMR_Rx_PMS_RMR_Rx Rte_Write_ComRx_CAN_PMS_RMR_Rx_PMS_RMR_Rx
#define Rte_Write_PMS_Real_PedalPositionInvalid_Rx_PMS_Real_PedalPositionInvalid_Rx Rte_Write_ComRx_CAN_PMS_Real_PedalPositionInvalid_Rx_PMS_Real_PedalPositionInvalid_Rx
#define Rte_Write_PMS_Real_PedalPosition_Rx_PMS_Real_PedalPosition_Rx Rte_Write_ComRx_CAN_PMS_Real_PedalPosition_Rx_PMS_Real_PedalPosition_Rx
#define Rte_Write_PMS_Stayawake_reasons_Rx_PMS_Stayawake_reasons_Rx Rte_Write_ComRx_CAN_PMS_Stayawake_reasons_Rx_PMS_Stayawake_reasons_Rx
#define Rte_Write_PMS_StsBrkSwitch1Invalid_Rx_PMS_StsBrkSwitch1Invalid_Rx Rte_Write_ComRx_CAN_PMS_StsBrkSwitch1Invalid_Rx_PMS_StsBrkSwitch1Invalid_Rx
#define Rte_Write_PMS_StsBrkSwitch1_Rx_PMS_StsBrkSwitch1_Rx Rte_Write_ComRx_CAN_PMS_StsBrkSwitch1_Rx_PMS_StsBrkSwitch1_Rx
#define Rte_Write_PMS_TM_Address_Rx_PMS_TM_Address_Rx Rte_Write_ComRx_CAN_PMS_TM_Address_Rx_PMS_TM_Address_Rx
#define Rte_Write_PMS_Wakeup_reasons_Rx_PMS_Wakeup_reasons_Rx Rte_Write_ComRx_CAN_PMS_Wakeup_reasons_Rx_PMS_Wakeup_reasons_Rx
#define Rte_Write_TBOX_Day_Rx_TBOX_Day_Rx Rte_Write_ComRx_CAN_TBOX_Day_Rx_TBOX_Day_Rx
#define Rte_Write_TBOX_Hour_Rx_TBOX_Hour_Rx Rte_Write_ComRx_CAN_TBOX_Hour_Rx_TBOX_Hour_Rx
#define Rte_Write_TBOX_Minute_Rx_TBOX_Minute_Rx Rte_Write_ComRx_CAN_TBOX_Minute_Rx_TBOX_Minute_Rx
#define Rte_Write_TBOX_Month_Rx_TBOX_Month_Rx Rte_Write_ComRx_CAN_TBOX_Month_Rx_TBOX_Month_Rx
#define Rte_Write_TBOX_Second_Rx_TBOX_Second_Rx Rte_Write_ComRx_CAN_TBOX_Second_Rx_TBOX_Second_Rx
#define Rte_Write_TBOX_Year_Rx_TBOX_Year_Rx Rte_Write_ComRx_CAN_TBOX_Year_Rx_TBOX_Year_Rx
#define Rte_Write_VCU_CrashOutputSts_Rx_VCU_CrashOutputSts_Rx Rte_Write_ComRx_CAN_VCU_CrashOutputSts_Rx_VCU_CrashOutputSts_Rx
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
FUNC(void, ComRx_CAN_CODE) ComRx_CAN_1_Init(void);
FUNC(void, ComRx_CAN_CODE) fc_ComRx1000ms(void);
FUNC(void, ComRx_CAN_CODE) fc_ComRx100ms(void);
FUNC(void, ComRx_CAN_CODE) fc_ComRx10ms(void);
FUNC(void, ComRx_CAN_CODE) fc_ComRx200ms(void);
FUNC(void, ComRx_CAN_CODE) fc_ComRx20ms(void);
FUNC(void, ComRx_CAN_CODE) fc_ComRx500ms(void);
FUNC(void, ComRx_CAN_CODE) fc_ComRxEvent(void);
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
#endif /* RTE_COMRX_CAN_H_ */
 
 
 

/*
************************************************************************************************************************
*
* File name: Rte_App1_Application_Core5_QM.c
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
#include "Rte_ActvDampg.h"
#include "Rte_AntiRollBack.h"
#include "Rte_ComRx_CAN.h"
#include "Rte_ComTx_CAN.h"
#include "Rte_Dchrg.h"
#include "Rte_DernCoorn.h"
#include "Rte_DernEm.h"
#include "Rte_DernInv.h"
#include "Rte_DernSys.h"
#include "Rte_EmPwr.h"
#include "Rte_EmTq.h"
#include "Rte_ExtTqDes.h"
#include "Rte_HvIntlck.h"
#include "Rte_IdqDes.h"
#include "Rte_TempDev.h"
#include "Rte_TqDemCoorn.h"
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
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_Status_CheckSum_Rx_BMSH_Status_CheckSum_Rx = 0U;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_VehicleSpd_ComRx_VehicleSpd = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bCrcChksFlt_ComRx_bCrcChksFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bMcuCutOffLv_ComRx_bMcuCutOffLv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bRollgCntrFlt_ComRx_bRollgCntrFlt = FALSE;
VAR(SInt16, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_nDes_ComRx_nDes = 0;
VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stBrkSwt_ComRx_stBrkSwt = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stEmCtrlMod_ComRx_stEmCtrlMod = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stEmWrkMod_ComRx_stEmWrkMod = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stHndbrk_ComRx_stHndbrk = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stHvCntctr_ComRx_stHvCntctr = 0U;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tqDes_ComRx_tqDes = 0.0F;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_FLWheelDirection_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx = 3U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_FLWheelSpeedInvalid_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx = 1U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_FRWheelDirection_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx = 3U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_FRWheelSpeedInvalid_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx = 1U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_RLWheelDirection_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx = 3U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_RLWheelSpeedInvalid_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx = 1U;
VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_RRWheelDirection_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx = 3U;
VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_RRWheelSpeedInvalid_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx = 1U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_ActiveDischgFlt_IPU_ActiveDischgFlt = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_BattFaultLampState_IPU_BattFaultLampState = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_BusUndervolt_IPU_BusUndervolt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_CANCommFlt_IPU_CANCommFlt = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_DTC_IPU_DTC = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_DischgState_IPU_DischgState = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_HVBusCur_IPU_HVBusCur = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_HVBusVolt_20_IPU_HVBusVolt_20 = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_HVBusVolt_500_IPU_HVBusVolt_500 = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_HardwareCapOverVolt_IPU_HardwareCapOverVolt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IGBTFlt_IPU_IGBTFlt = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgInvrT_IPU_IsgInvrT = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgInvrTInvalid_IPU_IsgInvrTInvalid = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgModSts_IPU_IsgModSts = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgModStsInvalid_IPU_IsgModStsInvalid = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgMotT_IPU_IsgMotT = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgMotTInvalid_IPU_IsgMotTInvalid = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgOverTemp_IPU_IsgOverTemp = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgTqActIsgTqActInvalid_IPU_IsgTqActIsgTqActInvalid = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_LV_VotagtFault_IPU_LV_VotagtFault = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MCUMemoryFlt_IPU_MCUMemoryFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MCUTempHighAlarm_IPU_MCUTempHighAlarm = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1 = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MCUTempHighFault_IPU_MCUTempHighFault = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MCUTempSensorErr_IPU_MCUTempSensorErr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorFltLevell1_IPU_MotorFltLevell1 = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorFltLevell_Invalid_IPU_MotorFltLevell_Invalid = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorLockRotErr_IPU_MotorLockRotErr = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorNum_IPU_MotorNum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorNumSN_IPU_MotorNumSN = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorSpdHighAlarm_IPU_MotorSpdHighAlarm = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorSts_IPU_MotorSts = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorTempHighAlarm_IPU_MotorTempHighAlarm = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorTempHighFault_IPU_MotorTempHighFault = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorTempHighFault1_IPU_MotorTempHighFault1 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorTempSensorErr_IPU_MotorTempSensorErr = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorUCurrSensorFlt_IPU_MotorUCurrSensorFlt = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_Motor_Phase_Curr_IPU_Motor_Phase_Curr = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_PCOCHW_Fault_IPU_PCOCHW_Fault = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_PCOCSW_Fault_IPU_PCOCSW_Fault = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_PreventSlipFlag_IPU_PreventSlipFlag = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_RotateInverterFlt_IPU_RotateInverterFlt = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_SelfChkSts_IPU_SelfChkSts = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_SoftwareCapOverVolt_IPU_SoftwareCapOverVolt = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_Sts_Checksum_IPU_Sts_Checksum = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_TqAvlIsgMaxInvalid_IPU_TqAvlIsgMaxInvalid = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_TqAvlIsgMinInvalid_IPU_TqAvlIsgMinInvalid = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_TrqSpd_CheckSum_IPU_TrqSpd_CheckSum = 0U;
VAR(Float, RTE_VAR_INIT) Rte_EmTq_EmTq_tqEm_EmTq_tqEm = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_bHvRdy_ExtTqDes_bHvRdy = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_tqEmDesWoDampg_ExtTqDes_tqEmDesWoDampg = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_HvIntlck_HvIntlck_bMCUHvIntlckClsd_HvIntlck_bMCUHvIntlckClsd = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_iDaDes_IdqDes_iDaDes = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_iQaDes_IdqDes_iQaDes = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_indtDa_IdqDes_indtDa = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_indtQa_IdqDes_indtQa = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_mflxExct_IdqDes_mflxExct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_omRtr_IdqDes_omRtr = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_resStr_IdqDes_resStr = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_TempDev_TempDev_tPhyMot_TempDev_tPhyMot = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_TempDev_TempDev_tPhySic_TempDev_tPhySic = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_TqDemCoorn_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd = 0.0F;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_VAR_INIT
#include "Rte_MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_ActvDampg_ActvDampg_bDampgSwtActv_ActvDampg_bDampgSwtActv = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_ActvDampg_ActvDampg_tqDampgCalc_ActvDampg_tqDampgCalc = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_ActvDampg_ActvDampg_tqEmDes_ActvDampg_tqEmDes = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_AntiRollBack_AntiRollBack_bAntiRollActv_AntiRollBack_bAntiRollActv = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_AntiRollBack_AntiRollBack_tqCmdAntiRoll_AntiRollBack_tqCmdAntiRoll = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_AC_AmbientTemperatureInvalid_Rx_AC_AmbientTemperatureInvalid_Rx = 0U;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_AC_AmbientTemperature_Rx_AC_AmbientTemperature_Rx = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_ActiveWakeupBit_Rx_BMSH_ActiveWakeupBit_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_Address_Rx_BMSH_Address_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_BatCurrentValidFlag_Rx_BMSH_BatCurrentValidFlag_Rx = 0U;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_BatCurrent_Rx_BMSH_BatCurrent_Rx = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_BusVolt_Rx_BMSH_BusVolt_Rx = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_NMSts_Rx_BMSH_NMSts_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_PackVoltValidFlag_Rx_BMSH_PackVoltValidFlag_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_RMR_Rx_BMSH_RMR_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_Status_AliveCounter_Rx_BMSH_Status_AliveCounter_Rx = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_StayAwake_Reasons_Rx_BMSH_StayAwake_Reasons_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_StsMainNegtiveRelay_Rx_BMSH_StsMainNegtiveRelay_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_StsMainPositiveRelay_Rx_BMSH_StsMainPositiveRelay_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_StsMode_Rx_BMSH_StsMode_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_VCU_Crash_Rx_BMSH_VCU_Crash_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_VoltCurrent_AliveCounter_Rx_BMSH_VoltCurrent_AliveCounter_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_VoltCurrent_CheckSum_Rx_BMSH_VoltCurrent_CheckSum_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_BMSH_WakeUp_Reasons_Rx_BMSH_WakeUp_Reasons_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_IgnONSts_ComRx_IgnONSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_IsgActvDampgModReq_ComRx_IsgActvDampgModReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_Status_AliveCounter_ComRx_Status_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_Status_Checksum_ComRx_Status_Checksum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bAcceleratorPedal_flag_ComRx_bAcceleratorPedal_flag = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bDampgSwtActv_ComRx_bDampgSwtActv = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bDriveModeInd_ComRx_bDriveModeInd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bEmgyDchrgReq_ComRx_bEmgyDchrgReq = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bErrEmgyShtofCrash_ComRx_bErrEmgyShtofCrash = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bGearPositionInd_ComRx_bGearPositionInd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bOdmtBkupEna_ComRx_bOdmtBkupEna = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bOil_HV_OFF_ComRx_bOil_HV_OFF = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bPTReadyInd_ComRx_bPTReadyInd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bPowerModeValidity_ComRx_bPowerModeValidity = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bT15_ComRx_bT15 = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bVehicleSpd_flag_ComRx_bVehicleSpd_flag = 0U;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_dstTotalOdometer_ComRx_dstTotalOdometer = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_dstTotalVehicleDistance_ComRx_dstTotalVehicleDistance = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_facTqSlopMax_ComRx_facTqSlopMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_iEfcDes_ComRx_iEfcDes = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_pctAcceleratorPedalPosition_ComRx_pctAcceleratorPedalPosition = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_pctBrakePedalPosition_ComRx_pctBrakePedalPosition = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_posBattSOC_ComRx_posBattSOC = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stCrashOutputSts_ComRx_stCrashOutputSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stCtrlAliveCnt_ComRx_stCtrlAliveCnt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stCtrlCheckSum_ComRx_stCtrlCheckSum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stDrvCtrlDes_ComRx_stDrvCtrlDes = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stDrvGear_ComRx_stDrvGear = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stEMTrqSpdCtrl_AliveCnt_ComRx_stEMTrqSpdCtrl_AliveCnt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stEMTrqSpdCtrl_Checksum_ComRx_stEMTrqSpdCtrl_Checksum = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stHVLoopWorkSts_ComRx_stHVLoopWorkSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stMainPosConnSts_ComRx_stMainPosConnSts = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stPowerMode_ComRx_stPowerMode = 0U;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tCooltInletEm_ComRx_tCooltInletEm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tExtEnv_ComRx_tExtEnv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tIvtrCooltInlet_ComRx_tIvtrCooltInlet = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tiDay_ComRx_tiDay = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tiHour_ComRx_tiHour = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tiMinute_ComRx_tiMinute = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tiMonth_ComRx_tiMonth = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tiSecond_ComRx_tiSecond = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tiYear_ComRx_tiYear = 0U;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tqMaxLim_ComRx_tqMaxLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tqMinLim_ComRx_tqMinLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_uDCLnkDes_ComRx_uDCLnkDes = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_EPBStatus_Rx_EHB_EPBStatus_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_FLWheelDirection_Rx_EHB_FLWheelDirection_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_FLWheelSpeedInvalid_Rx_EHB_FLWheelSpeedInvalid_Rx = 0U;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_FLWheelSpeedKPH_Rx_EHB_FLWheelSpeedKPH_Rx = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_FRWheelDirection_Rx_EHB_FRWheelDirection_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_FRWheelSpeedInvalid_Rx_EHB_FRWheelSpeedInvalid_Rx = 0U;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_FRWheelSpeedKPH_Rx_EHB_FRWheelSpeedKPH_Rx = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_FrontWheelSpeedsKPH_AliveCounter_Rx_EHB_FrontWheelSpeedsKPH_AliveCounter_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_FrontWheelSpeedsKPH_CheckSum_Rx_EHB_FrontWheelSpeedsKPH_CheckSum_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_RLWheelDirection_Rx_EHB_RLWheelDirection_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_RLWheelSpeedInvalid_Rx_EHB_RLWheelSpeedInvalid_Rx = 0U;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_RLWheelSpeedKPH_Rx_EHB_RLWheelSpeedKPH_Rx = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_RRWheelDirection_Rx_EHB_RRWheelDirection_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_RRWheelSpeedInvalid_Rx_EHB_RRWheelSpeedInvalid_Rx = 0U;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_RRWheelSpeedKPH_Rx_EHB_RRWheelSpeedKPH_Rx = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_RearWheelSpeedsKPH_AliveCounter_Rx_EHB_RearWheelSpeedsKPH_AliveCounter_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_RearWheelSpeedsKPH_CheckSum_Rx_EHB_RearWheelSpeedsKPH_CheckSum_Rx = 0U;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_RearWheelSpeedsKPH_Rx_EHB_RearWheelSpeedsKPH_Rx = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_Status_AliveCounter_Rx_EHB_Status_AliveCounter_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_Status_CheckSum_Rx_EHB_Status_CheckSum_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_VehicleSpeedInvalid_Rx_EHB_VehicleSpeedInvalid_Rx = 0U;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_EHB_VehicleSpeed_Rx_EHB_VehicleSpeed_Rx = 0.0F;
VAR(UInt32, RTE_VAR_INIT) Rte_ComRx_CAN_IPK_IPKTotalOdometer_Rx_IPK_IPKTotalOdometer_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PEPS_PowerModeValidity_Rx_PEPS_PowerModeValidity_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PEPS_PowerMode_Rx_PEPS_PowerMode_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_AWB_Rx_PMS_AWB_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_Command_AliveCounter_Rx_PMS_Command_AliveCounter_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_Command_Checksum_Rx_PMS_Command_Checksum_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_CurrentGearPosition_Rx_PMS_CurrentGearPosition_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_CurrentGearPosition_Valid_Rx_PMS_CurrentGearPosition_Valid_Rx = 0U;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_DriveCircuitTemp_Rx_PMS_DriveCircuitTemp_Rx = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_EDCPEnable_Rx_PMS_EDCPEnable_Rx = 0U;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_EDCPPWMCtrl_Rx_PMS_EDCPPWMCtrl_Rx = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_FrntHeatModEnad_Rx_PMS_FrntHeatModEnad_Rx = 0U;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_FrntHeatPwrAllwd_Rx_PMS_FrntHeatPwrAllwd_Rx = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_IPUFlowFeedback_Rx_PMS_IPUFlowFeedback_Rx = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_IgnONSts_Rx_PMS_IgnONSts_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_IsgActvDampgModReq_Rx_PMS_IsgActvDampgModReq_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_IsgModReq_Rx_PMS_IsgModReq_Rx = 0U;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_IsgTqReq_Rx_PMS_IsgTqReq_Rx = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_NMSts_Rx_PMS_NMSts_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_RMR_Rx_PMS_RMR_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_Real_PedalPositionInvalid_Rx_PMS_Real_PedalPositionInvalid_Rx = 0U;
VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_Real_PedalPosition_Rx_PMS_Real_PedalPosition_Rx = 0.0F;
VAR(UInt32, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_Stayawake_reasons_Rx_PMS_Stayawake_reasons_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_StsBrkSwitch1Invalid_Rx_PMS_StsBrkSwitch1Invalid_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_StsBrkSwitch1_Rx_PMS_StsBrkSwitch1_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_TM_Address_Rx_PMS_TM_Address_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_PMS_Wakeup_reasons_Rx_PMS_Wakeup_reasons_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_TBOX_Day_Rx_TBOX_Day_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_TBOX_Hour_Rx_TBOX_Hour_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_TBOX_Minute_Rx_TBOX_Minute_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_TBOX_Month_Rx_TBOX_Month_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_TBOX_Second_Rx_TBOX_Second_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_TBOX_Year_Rx_TBOX_Year_Rx = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_VCU_CrashOutputSts_Rx_VCU_CrashOutputSts_Rx = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_AWB_IPU_AWB = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_Address_IPU_Address = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgHeatFdBck_IPU_IsgHeatFdBck = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgHeatPwrAct_IPU_IsgHeatPwrAct = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgHeatPwrMax_IPU_IsgHeatPwrMax = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MaxCurrt_IPU_MaxCurrt = 0U;
VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MaxTrq_IPU_MaxTrq = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_NMSts_IPU_NMSts = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_RMR_IPU_RMR = FALSE;
VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_RatedVoltg_IPU_RatedVoltg = 0U;
VAR(UInt32, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_Stayawake_reasons_IPU_Stayawake_reasons = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_Wakeup_reasons_IPU_Wakeup_reasons = 0U;
VAR(Float, RTE_VAR_INIT) Rte_Dchrg_Dchrg_iDchrg_Dchrg_iDchrg = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_stPwrMaxLimCoord_DernCoorn_stPwrMaxLimCoord = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_stPwrMinLimCoord_DernCoorn_stPwrMinLimCoord = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_stTqEmGenCoord_DernCoorn_stTqEmGenCoord = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_stTqEmMotCoord_DernCoorn_stTqEmMotCoord = 0U;
VAR(Float, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_tqEmMax_DernCoorn_tqEmMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_tqEmMin_DernCoorn_tqEmMin = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_tqMeclMax_DernCoorn_tqMeclMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_tqMeclMin_DernCoorn_tqMeclMin = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_bCurrDernCtrl_DernEm_bCurrDernCtrl = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_DernEm_DernEm_bRtrTempLimActv_DernEm_bRtrTempLimActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_DernEm_DernEm_bRtrTempLimZeroActv_DernEm_bRtrTempLimZeroActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_DernEm_DernEm_bStrTempLimActv_DernEm_bStrTempLimActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_DernEm_DernEm_bStrTempLimZeroActv_DernEm_bStrTempLimZeroActv = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_facDernCurr_DernEm_facDernCurr = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_facGenTempRtrLim_DernEm_facGenTempRtrLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_facGenTempStrLim_DernEm_facGenTempStrLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_facMotTempRtrLim_DernEm_facMotTempRtrLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_facMotTempStrLim_DernEm_facMotTempStrLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_tqGenExtChartcLim_DernEm_tqGenExtChartcLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_tqMotExtChartcLim_DernEm_tqMotExtChartcLim = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_DernInv_DernInv_bIvtrCooltTempLimActv_DernInv_bIvtrCooltTempLimActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_DernInv_DernInv_bIvtrCooltTempLimZeroActv_DernInv_bIvtrCooltTempLimZeroActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_DernInv_DernInv_bSicTempLimActv_DernInv_bSicTempLimActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_DernInv_DernInv_bSicTempLimZeroActv_DernInv_bSicTempLimZeroActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_DernInv_DernInv_biSqrtLimActv_DernInv_biSqrtLimActv = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_DernInv_DernInv_facGenTempIvtrCooltLim_DernInv_facGenTempIvtrCooltLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernInv_DernInv_facGenTempSicLim_DernInv_facGenTempSicLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernInv_DernInv_facGeniSqrtLim_DernInv_facGeniSqrtLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernInv_DernInv_facMotTempIvtrCooltLim_DernInv_facMotTempIvtrCooltLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernInv_DernInv_facMotTempSicLim_DernInv_facMotTempSicLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernInv_DernInv_facMotiSqrtLim_DernInv_facMotiSqrtLim = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_DernSys_DernSys_bIdcGenLimActv_DernSys_bIdcGenLimActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_DernSys_DernSys_bIdcMotLimActv_DernSys_bIdcMotLimActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_DernSys_DernSys_bSpdOverLimActv_DernSys_bSpdOverLimActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_DernSys_DernSys_bUdcOverTqLimActv_DernSys_bUdcOverTqLimActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_DernSys_DernSys_bUdcOverTqLimZeroActv_DernSys_bUdcOverTqLimZeroActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_DernSys_DernSys_bUdcUnderTqLim_DernSys_bUdcUnderTqLim = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_DernSys_DernSys_bUdcUnderTqLimZero_DernSys_bUdcUnderTqLimZero = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_facAntiSlipDern_DernSys_facAntiSlipDern = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_facGenSpdOverLim_DernSys_facGenSpdOverLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_facGenUdcLim_DernSys_facGenUdcLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_facMotSpdOverLim_DernSys_facMotSpdOverLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_facMotUdcLim_DernSys_facMotUdcLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_pwrGenIdcLim_DernSys_pwrGenIdcLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_pwrMotIdcLim_DernSys_pwrMotIdcLim = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_EmPwr_EmPwr_iDCLnk_EmPwr_iDCLnk = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_EmPwr_EmPwr_iDCLnkFiltd_EmPwr_iDCLnkFiltd = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_EmPwr_EmPwr_pwrDCLnk_EmPwr_pwrDCLnk = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_EmTq_EmTq_tqEmFiltd_EmTq_tqEmFiltd = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_EmTq_EmTq_tqEmLost_EmTq_tqEmLost = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_EmTq_EmTq_tqMecl_EmTq_tqMecl = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_bMaxLimActv_ExtTqDes_bMaxLimActv = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_bMinLimActv_ExtTqDes_bMinLimActv = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_tqEmDes_ExtTqDes_tqEmDes = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_tqEmMax_ExtTqDes_tqEmMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_tqEmMin_ExtTqDes_tqEmMin = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_tqFric_ExtTqDes_tqFric = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_tqPwrDcLnk_ExtTqDes_tqPwrDcLnk = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_HvIntlck_HvIntlck_frqPwmTx_HvIntlck_frqPwmTx = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_HvIntlck_HvIntlck_rDutyPwmTx_HvIntlck_rDutyPwmTx = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_agCurrDaQa_IdqDes_agCurrDaQa = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_facFlxExctSclg_IdqDes_facFlxExctSclg = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_indtQaSubtDa_IdqDes_indtQaSubtDa = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_omRtrRecpr_IdqDes_omRtrRecpr = 0.0F;
VAR(SInt8, RTE_VAR_INIT) Rte_IdqDes_IdqDes_stSgnTqEmDes_IdqDes_stSgnTqEmDes = 0;
VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_tqEmDes_IdqDes_tqEmDes = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_TempDev_TempDev_tPhyMotFild_TempDev_tPhyMotFild = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_TempDev_TempDev_tPhySicU_TempDev_tPhySicU = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_TempDev_TempDev_tPhySicV_TempDev_tPhySicV = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_TempDev_TempDev_tPhySicW_TempDev_tPhySicW = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_TqDemCoorn_TqDemCoorn_bTqCrosZrActv_TqDemCoorn_bTqCrosZrActv = FALSE;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_VAR_INIT
#include "Rte_MemMap.h"


/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/

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

#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
VAR(Rte_App1_Application_Core5_QM_TxUpdateFlagsType, RTE_VAR_INIT_NOCACHE) Rte_App1_Application_Core5_QM_TxUpdateFlags = {
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
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

#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ActvDampg_ActvDampg_bDampgSwtActv_ActvDampg_bDampgSwtActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ActvDampg_ActvDampg_bDampgSwtActv_ActvDampg_bDampgSwtActv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ActvDampg_ActvDampg_tqDampgCalc_ActvDampg_tqDampgCalc(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ActvDampg_ActvDampg_tqDampgCalc_ActvDampg_tqDampgCalc = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ActvDampg_ActvDampg_tqEmDes_ActvDampg_tqEmDes(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ActvDampg_ActvDampg_tqEmDes_ActvDampg_tqEmDes = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AntiRollBack_AntiRollBack_bAntiRollActv_AntiRollBack_bAntiRollActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AntiRollBack_AntiRollBack_bAntiRollActv_AntiRollBack_bAntiRollActv = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AntiRollBack_AntiRollBack_tqCmdAntiRoll_AntiRollBack_tqCmdAntiRoll(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AntiRollBack_AntiRollBack_tqCmdAntiRoll_AntiRollBack_tqCmdAntiRoll = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_AC_AmbientTemperatureInvalid_Rx_AC_AmbientTemperatureInvalid_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_AC_AmbientTemperatureInvalid_Rx_AC_AmbientTemperatureInvalid_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_AC_AmbientTemperature_Rx_AC_AmbientTemperature_Rx(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_AC_AmbientTemperature_Rx_AC_AmbientTemperature_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_ActiveWakeupBit_Rx_BMSH_ActiveWakeupBit_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_BMSH_ActiveWakeupBit_Rx_BMSH_ActiveWakeupBit_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_Address_Rx_BMSH_Address_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_BMSH_Address_Rx_BMSH_Address_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_BatCurrentValidFlag_Rx_BMSH_BatCurrentValidFlag_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_BMSH_BatCurrentValidFlag_Rx_BMSH_BatCurrentValidFlag_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_BatCurrent_Rx_BMSH_BatCurrent_Rx(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_BMSH_BatCurrent_Rx_BMSH_BatCurrent_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_BusVolt_Rx_BMSH_BusVolt_Rx(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_BMSH_BusVolt_Rx_BMSH_BusVolt_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_NMSts_Rx_BMSH_NMSts_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_BMSH_NMSts_Rx_BMSH_NMSts_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_PackVoltValidFlag_Rx_BMSH_PackVoltValidFlag_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_BMSH_PackVoltValidFlag_Rx_BMSH_PackVoltValidFlag_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_RMR_Rx_BMSH_RMR_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_BMSH_RMR_Rx_BMSH_RMR_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_Status_AliveCounter_Rx_BMSH_Status_AliveCounter_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_BMSH_Status_AliveCounter_Rx_BMSH_Status_AliveCounter_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_Status_CheckSum_Rx_BMSH_Status_CheckSum_Rx(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComRx_CAN_BMSH_Status_CheckSum_Rx_BMSH_Status_CheckSum_Rx = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComRx_CAN_BMSH_Status_CheckSum_Rx_BMSH_Status_CheckSum_Rx = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_StayAwake_Reasons_Rx_BMSH_StayAwake_Reasons_Rx(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_BMSH_StayAwake_Reasons_Rx_BMSH_StayAwake_Reasons_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_StsMainNegtiveRelay_Rx_BMSH_StsMainNegtiveRelay_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_BMSH_StsMainNegtiveRelay_Rx_BMSH_StsMainNegtiveRelay_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_StsMainPositiveRelay_Rx_BMSH_StsMainPositiveRelay_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_BMSH_StsMainPositiveRelay_Rx_BMSH_StsMainPositiveRelay_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_StsMode_Rx_BMSH_StsMode_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_BMSH_StsMode_Rx_BMSH_StsMode_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_VCU_Crash_Rx_BMSH_VCU_Crash_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_BMSH_VCU_Crash_Rx_BMSH_VCU_Crash_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_VoltCurrent_AliveCounter_Rx_BMSH_VoltCurrent_AliveCounter_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_BMSH_VoltCurrent_AliveCounter_Rx_BMSH_VoltCurrent_AliveCounter_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_VoltCurrent_CheckSum_Rx_BMSH_VoltCurrent_CheckSum_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_BMSH_VoltCurrent_CheckSum_Rx_BMSH_VoltCurrent_CheckSum_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_BMSH_WakeUp_Reasons_Rx_BMSH_WakeUp_Reasons_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_BMSH_WakeUp_Reasons_Rx_BMSH_WakeUp_Reasons_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_IgnONSts_ComRx_IgnONSts(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_IgnONSts_ComRx_IgnONSts = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_IsgActvDampgModReq_ComRx_IsgActvDampgModReq(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_IsgActvDampgModReq_ComRx_IsgActvDampgModReq = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_Status_AliveCounter_ComRx_Status_AliveCounter(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_Status_AliveCounter_ComRx_Status_AliveCounter = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_Status_Checksum_ComRx_Status_Checksum(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_Status_Checksum_ComRx_Status_Checksum = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_VehicleSpd_ComRx_VehicleSpd(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_VehicleSpd_ComRx_VehicleSpd = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bAcceleratorPedal_flag_ComRx_bAcceleratorPedal_flag(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_bAcceleratorPedal_flag_ComRx_bAcceleratorPedal_flag = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bCrcChksFlt_ComRx_bCrcChksFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_bCrcChksFlt_ComRx_bCrcChksFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bDampgSwtActv_ComRx_bDampgSwtActv(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_bDampgSwtActv_ComRx_bDampgSwtActv = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bDriveModeInd_ComRx_bDriveModeInd(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_bDriveModeInd_ComRx_bDriveModeInd = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bEmgyDchrgReq_ComRx_bEmgyDchrgReq(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_bEmgyDchrgReq_ComRx_bEmgyDchrgReq = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bErrEmgyShtofCrash_ComRx_bErrEmgyShtofCrash(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_bErrEmgyShtofCrash_ComRx_bErrEmgyShtofCrash = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bGearPositionInd_ComRx_bGearPositionInd(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_bGearPositionInd_ComRx_bGearPositionInd = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bMcuCutOffLv_ComRx_bMcuCutOffLv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_bMcuCutOffLv_ComRx_bMcuCutOffLv = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bOdmtBkupEna_ComRx_bOdmtBkupEna(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_bOdmtBkupEna_ComRx_bOdmtBkupEna = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bOil_HV_OFF_ComRx_bOil_HV_OFF(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_bOil_HV_OFF_ComRx_bOil_HV_OFF = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bPTReadyInd_ComRx_bPTReadyInd(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_bPTReadyInd_ComRx_bPTReadyInd = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bPowerModeValidity_ComRx_bPowerModeValidity(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_bPowerModeValidity_ComRx_bPowerModeValidity = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bRollgCntrFlt_ComRx_bRollgCntrFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_bRollgCntrFlt_ComRx_bRollgCntrFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bT15_ComRx_bT15(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_bT15_ComRx_bT15 = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_bVehicleSpd_flag_ComRx_bVehicleSpd_flag(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_bVehicleSpd_flag_ComRx_bVehicleSpd_flag = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_dstTotalOdometer_ComRx_dstTotalOdometer(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_dstTotalOdometer_ComRx_dstTotalOdometer = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_dstTotalVehicleDistance_ComRx_dstTotalVehicleDistance(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_dstTotalVehicleDistance_ComRx_dstTotalVehicleDistance = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_facTqSlopMax_ComRx_facTqSlopMax(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_facTqSlopMax_ComRx_facTqSlopMax = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_iEfcDes_ComRx_iEfcDes(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_iEfcDes_ComRx_iEfcDes = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_nDes_ComRx_nDes(sint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_nDes_ComRx_nDes = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_pctAcceleratorPedalPosition_ComRx_pctAcceleratorPedalPosition(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_pctAcceleratorPedalPosition_ComRx_pctAcceleratorPedalPosition = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_pctBrakePedalPosition_ComRx_pctBrakePedalPosition(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_pctBrakePedalPosition_ComRx_pctBrakePedalPosition = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_posBattSOC_ComRx_posBattSOC(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_posBattSOC_ComRx_posBattSOC = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stBrkSwt_ComRx_stBrkSwt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_stBrkSwt_ComRx_stBrkSwt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stCrashOutputSts_ComRx_stCrashOutputSts(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_stCrashOutputSts_ComRx_stCrashOutputSts = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stCtrlAliveCnt_ComRx_stCtrlAliveCnt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_stCtrlAliveCnt_ComRx_stCtrlAliveCnt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stCtrlCheckSum_ComRx_stCtrlCheckSum(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_stCtrlCheckSum_ComRx_stCtrlCheckSum = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stDrvCtrlDes_ComRx_stDrvCtrlDes(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_stDrvCtrlDes_ComRx_stDrvCtrlDes = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stDrvGear_ComRx_stDrvGear(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_stDrvGear_ComRx_stDrvGear = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stEMTrqSpdCtrl_AliveCnt_ComRx_stEMTrqSpdCtrl_AliveCnt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_stEMTrqSpdCtrl_AliveCnt_ComRx_stEMTrqSpdCtrl_AliveCnt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stEMTrqSpdCtrl_Checksum_ComRx_stEMTrqSpdCtrl_Checksum(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_stEMTrqSpdCtrl_Checksum_ComRx_stEMTrqSpdCtrl_Checksum = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stEmCtrlMod_ComRx_stEmCtrlMod(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_stEmCtrlMod_ComRx_stEmCtrlMod = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stEmWrkMod_ComRx_stEmWrkMod(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_stEmWrkMod_ComRx_stEmWrkMod = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stHVLoopWorkSts_ComRx_stHVLoopWorkSts(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_stHVLoopWorkSts_ComRx_stHVLoopWorkSts = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stHndbrk_ComRx_stHndbrk(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_stHndbrk_ComRx_stHndbrk = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stHvCntctr_ComRx_stHvCntctr(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_stHvCntctr_ComRx_stHvCntctr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stMainPosConnSts_ComRx_stMainPosConnSts(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_stMainPosConnSts_ComRx_stMainPosConnSts = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_stPowerMode_ComRx_stPowerMode(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_stPowerMode_ComRx_stPowerMode = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tCooltInletEm_ComRx_tCooltInletEm(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_tCooltInletEm_ComRx_tCooltInletEm = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tExtEnv_ComRx_tExtEnv(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_tExtEnv_ComRx_tExtEnv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tIvtrCooltInlet_ComRx_tIvtrCooltInlet(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_tIvtrCooltInlet_ComRx_tIvtrCooltInlet = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tiDay_ComRx_tiDay(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_tiDay_ComRx_tiDay = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tiHour_ComRx_tiHour(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_tiHour_ComRx_tiHour = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tiMinute_ComRx_tiMinute(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_tiMinute_ComRx_tiMinute = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tiMonth_ComRx_tiMonth(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_tiMonth_ComRx_tiMonth = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tiSecond_ComRx_tiSecond(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_tiSecond_ComRx_tiSecond = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tiYear_ComRx_tiYear(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_tiYear_ComRx_tiYear = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tqDes_ComRx_tqDes(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_tqDes_ComRx_tqDes = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tqMaxLim_ComRx_tqMaxLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_tqMaxLim_ComRx_tqMaxLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_tqMinLim_ComRx_tqMinLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_tqMinLim_ComRx_tqMinLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_ComRx_uDCLnkDes_ComRx_uDCLnkDes(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_ComRx_uDCLnkDes_ComRx_uDCLnkDes = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_EPBStatus_Rx_EHB_EPBStatus_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_EPBStatus_Rx_EHB_EPBStatus_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_FLWheelDirection_Rx_EHB_FLWheelDirection_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_FLWheelDirection_Rx_EHB_FLWheelDirection_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_FLWheelSpeedInvalid_Rx_EHB_FLWheelSpeedInvalid_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_FLWheelSpeedInvalid_Rx_EHB_FLWheelSpeedInvalid_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_FLWheelSpeedKPH_Rx_EHB_FLWheelSpeedKPH_Rx(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_FLWheelSpeedKPH_Rx_EHB_FLWheelSpeedKPH_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_FRWheelDirection_Rx_EHB_FRWheelDirection_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_FRWheelDirection_Rx_EHB_FRWheelDirection_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_FRWheelSpeedInvalid_Rx_EHB_FRWheelSpeedInvalid_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_FRWheelSpeedInvalid_Rx_EHB_FRWheelSpeedInvalid_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_FRWheelSpeedKPH_Rx_EHB_FRWheelSpeedKPH_Rx(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_FRWheelSpeedKPH_Rx_EHB_FRWheelSpeedKPH_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_FrontWheelSpeedsKPH_AliveCounter_Rx_EHB_FrontWheelSpeedsKPH_AliveCounter_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_FrontWheelSpeedsKPH_AliveCounter_Rx_EHB_FrontWheelSpeedsKPH_AliveCounter_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_FrontWheelSpeedsKPH_CheckSum_Rx_EHB_FrontWheelSpeedsKPH_CheckSum_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_FrontWheelSpeedsKPH_CheckSum_Rx_EHB_FrontWheelSpeedsKPH_CheckSum_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_RLWheelDirection_Rx_EHB_RLWheelDirection_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_RLWheelDirection_Rx_EHB_RLWheelDirection_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_RLWheelSpeedInvalid_Rx_EHB_RLWheelSpeedInvalid_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_RLWheelSpeedInvalid_Rx_EHB_RLWheelSpeedInvalid_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_RLWheelSpeedKPH_Rx_EHB_RLWheelSpeedKPH_Rx(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_RLWheelSpeedKPH_Rx_EHB_RLWheelSpeedKPH_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_RRWheelDirection_Rx_EHB_RRWheelDirection_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_RRWheelDirection_Rx_EHB_RRWheelDirection_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_RRWheelSpeedInvalid_Rx_EHB_RRWheelSpeedInvalid_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_RRWheelSpeedInvalid_Rx_EHB_RRWheelSpeedInvalid_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_RRWheelSpeedKPH_Rx_EHB_RRWheelSpeedKPH_Rx(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_RRWheelSpeedKPH_Rx_EHB_RRWheelSpeedKPH_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_RearWheelSpeedsKPH_AliveCounter_Rx_EHB_RearWheelSpeedsKPH_AliveCounter_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_RearWheelSpeedsKPH_AliveCounter_Rx_EHB_RearWheelSpeedsKPH_AliveCounter_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_RearWheelSpeedsKPH_CheckSum_Rx_EHB_RearWheelSpeedsKPH_CheckSum_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_RearWheelSpeedsKPH_CheckSum_Rx_EHB_RearWheelSpeedsKPH_CheckSum_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_RearWheelSpeedsKPH_Rx_EHB_RearWheelSpeedsKPH_Rx(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_RearWheelSpeedsKPH_Rx_EHB_RearWheelSpeedsKPH_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_Status_AliveCounter_Rx_EHB_Status_AliveCounter_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_Status_AliveCounter_Rx_EHB_Status_AliveCounter_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_Status_CheckSum_Rx_EHB_Status_CheckSum_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_Status_CheckSum_Rx_EHB_Status_CheckSum_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_VehicleSpeedInvalid_Rx_EHB_VehicleSpeedInvalid_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_VehicleSpeedInvalid_Rx_EHB_VehicleSpeedInvalid_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_EHB_VehicleSpeed_Rx_EHB_VehicleSpeed_Rx(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_EHB_VehicleSpeed_Rx_EHB_VehicleSpeed_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_IPK_IPKTotalOdometer_Rx_IPK_IPKTotalOdometer_Rx(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_IPK_IPKTotalOdometer_Rx_IPK_IPKTotalOdometer_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PEPS_PowerModeValidity_Rx_PEPS_PowerModeValidity_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PEPS_PowerModeValidity_Rx_PEPS_PowerModeValidity_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PEPS_PowerMode_Rx_PEPS_PowerMode_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PEPS_PowerMode_Rx_PEPS_PowerMode_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_AWB_Rx_PMS_AWB_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_AWB_Rx_PMS_AWB_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_Command_AliveCounter_Rx_PMS_Command_AliveCounter_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_Command_AliveCounter_Rx_PMS_Command_AliveCounter_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_Command_Checksum_Rx_PMS_Command_Checksum_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_Command_Checksum_Rx_PMS_Command_Checksum_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_CurrentGearPosition_Rx_PMS_CurrentGearPosition_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_CurrentGearPosition_Rx_PMS_CurrentGearPosition_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_CurrentGearPosition_Valid_Rx_PMS_CurrentGearPosition_Valid_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_CurrentGearPosition_Valid_Rx_PMS_CurrentGearPosition_Valid_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_DriveCircuitTemp_Rx_PMS_DriveCircuitTemp_Rx(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_DriveCircuitTemp_Rx_PMS_DriveCircuitTemp_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_EDCPEnable_Rx_PMS_EDCPEnable_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_EDCPEnable_Rx_PMS_EDCPEnable_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_EDCPPWMCtrl_Rx_PMS_EDCPPWMCtrl_Rx(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_EDCPPWMCtrl_Rx_PMS_EDCPPWMCtrl_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_FrntHeatModEnad_Rx_PMS_FrntHeatModEnad_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_FrntHeatModEnad_Rx_PMS_FrntHeatModEnad_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_FrntHeatPwrAllwd_Rx_PMS_FrntHeatPwrAllwd_Rx(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_FrntHeatPwrAllwd_Rx_PMS_FrntHeatPwrAllwd_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_IPUFlowFeedback_Rx_PMS_IPUFlowFeedback_Rx(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_IPUFlowFeedback_Rx_PMS_IPUFlowFeedback_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_IgnONSts_Rx_PMS_IgnONSts_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_IgnONSts_Rx_PMS_IgnONSts_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_IsgActvDampgModReq_Rx_PMS_IsgActvDampgModReq_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_IsgActvDampgModReq_Rx_PMS_IsgActvDampgModReq_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_IsgModReq_Rx_PMS_IsgModReq_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_IsgModReq_Rx_PMS_IsgModReq_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_IsgTqReq_Rx_PMS_IsgTqReq_Rx(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_IsgTqReq_Rx_PMS_IsgTqReq_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_NMSts_Rx_PMS_NMSts_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_NMSts_Rx_PMS_NMSts_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_RMR_Rx_PMS_RMR_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_RMR_Rx_PMS_RMR_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_Real_PedalPositionInvalid_Rx_PMS_Real_PedalPositionInvalid_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_Real_PedalPositionInvalid_Rx_PMS_Real_PedalPositionInvalid_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_Real_PedalPosition_Rx_PMS_Real_PedalPosition_Rx(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_Real_PedalPosition_Rx_PMS_Real_PedalPosition_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_Stayawake_reasons_Rx_PMS_Stayawake_reasons_Rx(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_Stayawake_reasons_Rx_PMS_Stayawake_reasons_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_StsBrkSwitch1Invalid_Rx_PMS_StsBrkSwitch1Invalid_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_StsBrkSwitch1Invalid_Rx_PMS_StsBrkSwitch1Invalid_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_StsBrkSwitch1_Rx_PMS_StsBrkSwitch1_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_StsBrkSwitch1_Rx_PMS_StsBrkSwitch1_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_TM_Address_Rx_PMS_TM_Address_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_TM_Address_Rx_PMS_TM_Address_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_PMS_Wakeup_reasons_Rx_PMS_Wakeup_reasons_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_PMS_Wakeup_reasons_Rx_PMS_Wakeup_reasons_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_TBOX_Day_Rx_TBOX_Day_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_TBOX_Day_Rx_TBOX_Day_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_TBOX_Hour_Rx_TBOX_Hour_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_TBOX_Hour_Rx_TBOX_Hour_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_TBOX_Minute_Rx_TBOX_Minute_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_TBOX_Minute_Rx_TBOX_Minute_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_TBOX_Month_Rx_TBOX_Month_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_TBOX_Month_Rx_TBOX_Month_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_TBOX_Second_Rx_TBOX_Second_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_TBOX_Second_Rx_TBOX_Second_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_TBOX_Year_Rx_TBOX_Year_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_TBOX_Year_Rx_TBOX_Year_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComRx_CAN_VCU_CrashOutputSts_Rx_VCU_CrashOutputSts_Rx(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComRx_CAN_VCU_CrashOutputSts_Rx_VCU_CrashOutputSts_Rx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_AWB_IPU_AWB(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComTx_CAN_IPU_AWB_IPU_AWB = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_ActiveDischgFlt_IPU_ActiveDischgFlt(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_ActiveDischgFlt_IPU_ActiveDischgFlt = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_ActiveDischgFlt_IPU_ActiveDischgFlt = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_Address_IPU_Address(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComTx_CAN_IPU_Address_IPU_Address = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_BattFaultLampState_IPU_BattFaultLampState(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_BattFaultLampState_IPU_BattFaultLampState = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_BattFaultLampState_IPU_BattFaultLampState = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_BusUndervolt_IPU_BusUndervolt(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_BusUndervolt_IPU_BusUndervolt = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_BusUndervolt_IPU_BusUndervolt = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_CANCommFlt_IPU_CANCommFlt(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_CANCommFlt_IPU_CANCommFlt = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_CANCommFlt_IPU_CANCommFlt = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_DTC_IPU_DTC(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_DTC_IPU_DTC = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_DTC_IPU_DTC = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_DischgState_IPU_DischgState(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_DischgState_IPU_DischgState = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_DischgState_IPU_DischgState = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_HVBusCur_IPU_HVBusCur(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_HVBusCur_IPU_HVBusCur = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_HVBusCur_IPU_HVBusCur = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_HVBusVolt_20_IPU_HVBusVolt_20(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_HVBusVolt_20_IPU_HVBusVolt_20 = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_HVBusVolt_20_IPU_HVBusVolt_20 = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_HVBusVolt_500_IPU_HVBusVolt_500(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_HVBusVolt_500_IPU_HVBusVolt_500 = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_HVBusVolt_500_IPU_HVBusVolt_500 = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_HardwareCapOverVolt_IPU_HardwareCapOverVolt(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_HardwareCapOverVolt_IPU_HardwareCapOverVolt = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_HardwareCapOverVolt_IPU_HardwareCapOverVolt = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IGBTFlt_IPU_IGBTFlt(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_IGBTFlt_IPU_IGBTFlt = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IGBTFlt_IPU_IGBTFlt = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgHeatFdBck_IPU_IsgHeatFdBck(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComTx_CAN_IPU_IsgHeatFdBck_IPU_IsgHeatFdBck = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgHeatPwrAct_IPU_IsgHeatPwrAct(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComTx_CAN_IPU_IsgHeatPwrAct_IPU_IsgHeatPwrAct = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgHeatPwrMax_IPU_IsgHeatPwrMax(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComTx_CAN_IPU_IsgHeatPwrMax_IPU_IsgHeatPwrMax = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgInvrT_IPU_IsgInvrT(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_IsgInvrT_IPU_IsgInvrT = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgInvrT_IPU_IsgInvrT = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgInvrTInvalid_IPU_IsgInvrTInvalid(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_IsgInvrTInvalid_IPU_IsgInvrTInvalid = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgInvrTInvalid_IPU_IsgInvrTInvalid = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgModSts_IPU_IsgModSts(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_IsgModSts_IPU_IsgModSts = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgModSts_IPU_IsgModSts = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgModStsInvalid_IPU_IsgModStsInvalid(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_IsgModStsInvalid_IPU_IsgModStsInvalid = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgModStsInvalid_IPU_IsgModStsInvalid = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgMotT_IPU_IsgMotT(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_IsgMotT_IPU_IsgMotT = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgMotT_IPU_IsgMotT = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgMotTInvalid_IPU_IsgMotTInvalid(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_IsgMotTInvalid_IPU_IsgMotTInvalid = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgMotTInvalid_IPU_IsgMotTInvalid = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgOverTemp_IPU_IsgOverTemp(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_IsgOverTemp_IPU_IsgOverTemp = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgOverTemp_IPU_IsgOverTemp = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgTqActIsgTqActInvalid_IPU_IsgTqActIsgTqActInvalid(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_IsgTqActIsgTqActInvalid_IPU_IsgTqActIsgTqActInvalid = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_IsgTqActIsgTqActInvalid_IPU_IsgTqActIsgTqActInvalid = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_LV_VotagtFault_IPU_LV_VotagtFault(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_LV_VotagtFault_IPU_LV_VotagtFault = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_LV_VotagtFault_IPU_LV_VotagtFault = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MCUMemoryFlt_IPU_MCUMemoryFlt(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_MCUMemoryFlt_IPU_MCUMemoryFlt = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MCUMemoryFlt_IPU_MCUMemoryFlt = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MCUTempHighAlarm_IPU_MCUTempHighAlarm(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_MCUTempHighAlarm_IPU_MCUTempHighAlarm = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MCUTempHighAlarm_IPU_MCUTempHighAlarm = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1 = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1 = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MCUTempHighFault_IPU_MCUTempHighFault(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_MCUTempHighFault_IPU_MCUTempHighFault = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MCUTempHighFault_IPU_MCUTempHighFault = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MCUTempSensorErr_IPU_MCUTempSensorErr(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_MCUTempSensorErr_IPU_MCUTempSensorErr = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MCUTempSensorErr_IPU_MCUTempSensorErr = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MaxCurrt_IPU_MaxCurrt(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComTx_CAN_IPU_MaxCurrt_IPU_MaxCurrt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MaxTrq_IPU_MaxTrq(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComTx_CAN_IPU_MaxTrq_IPU_MaxTrq = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorFltLevell1_IPU_MotorFltLevell1(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_MotorFltLevell1_IPU_MotorFltLevell1 = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorFltLevell1_IPU_MotorFltLevell1 = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorFltLevell_Invalid_IPU_MotorFltLevell_Invalid(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_MotorFltLevell_Invalid_IPU_MotorFltLevell_Invalid = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorFltLevell_Invalid_IPU_MotorFltLevell_Invalid = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorLockRotErr_IPU_MotorLockRotErr(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_MotorLockRotErr_IPU_MotorLockRotErr = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorLockRotErr_IPU_MotorLockRotErr = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorNum_IPU_MotorNum(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_MotorNum_IPU_MotorNum = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorNum_IPU_MotorNum = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorNumSN_IPU_MotorNumSN(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_MotorNumSN_IPU_MotorNumSN = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorNumSN_IPU_MotorNumSN = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorSpdHighAlarm_IPU_MotorSpdHighAlarm(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_MotorSpdHighAlarm_IPU_MotorSpdHighAlarm = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorSpdHighAlarm_IPU_MotorSpdHighAlarm = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorSts_IPU_MotorSts(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_MotorSts_IPU_MotorSts = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorSts_IPU_MotorSts = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorTempHighAlarm_IPU_MotorTempHighAlarm(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_MotorTempHighAlarm_IPU_MotorTempHighAlarm = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorTempHighAlarm_IPU_MotorTempHighAlarm = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorTempHighFault_IPU_MotorTempHighFault(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_MotorTempHighFault_IPU_MotorTempHighFault = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorTempHighFault_IPU_MotorTempHighFault = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorTempHighFault1_IPU_MotorTempHighFault1(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_MotorTempHighFault1_IPU_MotorTempHighFault1 = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorTempHighFault1_IPU_MotorTempHighFault1 = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorTempSensorErr_IPU_MotorTempSensorErr(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_MotorTempSensorErr_IPU_MotorTempSensorErr = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorTempSensorErr_IPU_MotorTempSensorErr = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorUCurrSensorFlt_IPU_MotorUCurrSensorFlt(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_MotorUCurrSensorFlt_IPU_MotorUCurrSensorFlt = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_MotorUCurrSensorFlt_IPU_MotorUCurrSensorFlt = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_Motor_Phase_Curr_IPU_Motor_Phase_Curr(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_Motor_Phase_Curr_IPU_Motor_Phase_Curr = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_Motor_Phase_Curr_IPU_Motor_Phase_Curr = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_NMSts_IPU_NMSts(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComTx_CAN_IPU_NMSts_IPU_NMSts = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_PCOCHW_Fault_IPU_PCOCHW_Fault(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_PCOCHW_Fault_IPU_PCOCHW_Fault = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_PCOCHW_Fault_IPU_PCOCHW_Fault = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_PCOCSW_Fault_IPU_PCOCSW_Fault(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_PCOCSW_Fault_IPU_PCOCSW_Fault = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_PCOCSW_Fault_IPU_PCOCSW_Fault = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_PreventSlipFlag_IPU_PreventSlipFlag(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_PreventSlipFlag_IPU_PreventSlipFlag = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_PreventSlipFlag_IPU_PreventSlipFlag = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_RMR_IPU_RMR(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComTx_CAN_IPU_RMR_IPU_RMR = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_RatedVoltg_IPU_RatedVoltg(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComTx_CAN_IPU_RatedVoltg_IPU_RatedVoltg = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_RotateInverterFlt_IPU_RotateInverterFlt(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_RotateInverterFlt_IPU_RotateInverterFlt = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_RotateInverterFlt_IPU_RotateInverterFlt = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_SelfChkSts_IPU_SelfChkSts(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_SelfChkSts_IPU_SelfChkSts = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_SelfChkSts_IPU_SelfChkSts = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_SoftwareCapOverVolt_IPU_SoftwareCapOverVolt(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_SoftwareCapOverVolt_IPU_SoftwareCapOverVolt = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_SoftwareCapOverVolt_IPU_SoftwareCapOverVolt = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_Stayawake_reasons_IPU_Stayawake_reasons(uint32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComTx_CAN_IPU_Stayawake_reasons_IPU_Stayawake_reasons = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComTx_CAN_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_Sts_Checksum_IPU_Sts_Checksum(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_Sts_Checksum_IPU_Sts_Checksum = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_Sts_Checksum_IPU_Sts_Checksum = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_TqAvlIsgMaxInvalid_IPU_TqAvlIsgMaxInvalid(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_TqAvlIsgMaxInvalid_IPU_TqAvlIsgMaxInvalid = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_TqAvlIsgMaxInvalid_IPU_TqAvlIsgMaxInvalid = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin(UInt16 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_TqAvlIsgMinInvalid_IPU_TqAvlIsgMinInvalid(Boolean data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_TqAvlIsgMinInvalid_IPU_TqAvlIsgMinInvalid = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_TqAvlIsgMinInvalid_IPU_TqAvlIsgMinInvalid = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComTx_CAN_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_TrqSpd_CheckSum_IPU_TrqSpd_CheckSum(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_ComTx_CAN_IPU_TrqSpd_CheckSum_IPU_TrqSpd_CheckSum = *(&data);
    Rte_App1_Application_Core5_QM_TxUpdateFlags.Rte_TxUpdate_ComTx_CAN_IPU_TrqSpd_CheckSum_IPU_TrqSpd_CheckSum = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_Wakeup_reasons_IPU_Wakeup_reasons(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ComTx_CAN_IPU_Wakeup_reasons_IPU_Wakeup_reasons = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Dchrg_Dchrg_iDchrg_Dchrg_iDchrg(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Dchrg_Dchrg_iDchrg_Dchrg_iDchrg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernCoorn_DernCoorn_stPwrMaxLimCoord_DernCoorn_stPwrMaxLimCoord(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernCoorn_DernCoorn_stPwrMaxLimCoord_DernCoorn_stPwrMaxLimCoord = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernCoorn_DernCoorn_stPwrMinLimCoord_DernCoorn_stPwrMinLimCoord(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernCoorn_DernCoorn_stPwrMinLimCoord_DernCoorn_stPwrMinLimCoord = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernCoorn_DernCoorn_stTqEmGenCoord_DernCoorn_stTqEmGenCoord(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernCoorn_DernCoorn_stTqEmGenCoord_DernCoorn_stTqEmGenCoord = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernCoorn_DernCoorn_stTqEmMotCoord_DernCoorn_stTqEmMotCoord(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernCoorn_DernCoorn_stTqEmMotCoord_DernCoorn_stTqEmMotCoord = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernCoorn_DernCoorn_tqEmMax_DernCoorn_tqEmMax(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernCoorn_DernCoorn_tqEmMax_DernCoorn_tqEmMax = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernCoorn_DernCoorn_tqEmMin_DernCoorn_tqEmMin(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernCoorn_DernCoorn_tqEmMin_DernCoorn_tqEmMin = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernCoorn_DernCoorn_tqMeclMax_DernCoorn_tqMeclMax(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernCoorn_DernCoorn_tqMeclMax_DernCoorn_tqMeclMax = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernCoorn_DernCoorn_tqMeclMin_DernCoorn_tqMeclMin(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernCoorn_DernCoorn_tqMeclMin_DernCoorn_tqMeclMin = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_bCurrDernCtrl_DernEm_bCurrDernCtrl(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernEm_DernEm_bCurrDernCtrl_DernEm_bCurrDernCtrl = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_bRtrTempLimActv_DernEm_bRtrTempLimActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernEm_DernEm_bRtrTempLimActv_DernEm_bRtrTempLimActv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_bRtrTempLimZeroActv_DernEm_bRtrTempLimZeroActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernEm_DernEm_bRtrTempLimZeroActv_DernEm_bRtrTempLimZeroActv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_bStrTempLimActv_DernEm_bStrTempLimActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernEm_DernEm_bStrTempLimActv_DernEm_bStrTempLimActv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_bStrTempLimZeroActv_DernEm_bStrTempLimZeroActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernEm_DernEm_bStrTempLimZeroActv_DernEm_bStrTempLimZeroActv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_facDernCurr_DernEm_facDernCurr(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernEm_DernEm_facDernCurr_DernEm_facDernCurr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_facGenTempRtrLim_DernEm_facGenTempRtrLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernEm_DernEm_facGenTempRtrLim_DernEm_facGenTempRtrLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_facGenTempStrLim_DernEm_facGenTempStrLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernEm_DernEm_facGenTempStrLim_DernEm_facGenTempStrLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_facMotTempRtrLim_DernEm_facMotTempRtrLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernEm_DernEm_facMotTempRtrLim_DernEm_facMotTempRtrLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_facMotTempStrLim_DernEm_facMotTempStrLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernEm_DernEm_facMotTempStrLim_DernEm_facMotTempStrLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_tqGenExtChartcLim_DernEm_tqGenExtChartcLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernEm_DernEm_tqGenExtChartcLim_DernEm_tqGenExtChartcLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_tqMotExtChartcLim_DernEm_tqMotExtChartcLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernEm_DernEm_tqMotExtChartcLim_DernEm_tqMotExtChartcLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_bIvtrCooltTempLimActv_DernInv_bIvtrCooltTempLimActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernInv_DernInv_bIvtrCooltTempLimActv_DernInv_bIvtrCooltTempLimActv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_bIvtrCooltTempLimZeroActv_DernInv_bIvtrCooltTempLimZeroActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernInv_DernInv_bIvtrCooltTempLimZeroActv_DernInv_bIvtrCooltTempLimZeroActv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_bSicTempLimActv_DernInv_bSicTempLimActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernInv_DernInv_bSicTempLimActv_DernInv_bSicTempLimActv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_bSicTempLimZeroActv_DernInv_bSicTempLimZeroActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernInv_DernInv_bSicTempLimZeroActv_DernInv_bSicTempLimZeroActv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_biSqrtLimActv_DernInv_biSqrtLimActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernInv_DernInv_biSqrtLimActv_DernInv_biSqrtLimActv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_facGenTempIvtrCooltLim_DernInv_facGenTempIvtrCooltLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernInv_DernInv_facGenTempIvtrCooltLim_DernInv_facGenTempIvtrCooltLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_facGenTempSicLim_DernInv_facGenTempSicLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernInv_DernInv_facGenTempSicLim_DernInv_facGenTempSicLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_facGeniSqrtLim_DernInv_facGeniSqrtLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernInv_DernInv_facGeniSqrtLim_DernInv_facGeniSqrtLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_facMotTempIvtrCooltLim_DernInv_facMotTempIvtrCooltLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernInv_DernInv_facMotTempIvtrCooltLim_DernInv_facMotTempIvtrCooltLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_facMotTempSicLim_DernInv_facMotTempSicLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernInv_DernInv_facMotTempSicLim_DernInv_facMotTempSicLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_facMotiSqrtLim_DernInv_facMotiSqrtLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernInv_DernInv_facMotiSqrtLim_DernInv_facMotiSqrtLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_bIdcGenLimActv_DernSys_bIdcGenLimActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernSys_DernSys_bIdcGenLimActv_DernSys_bIdcGenLimActv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_bIdcMotLimActv_DernSys_bIdcMotLimActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernSys_DernSys_bIdcMotLimActv_DernSys_bIdcMotLimActv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_bSpdOverLimActv_DernSys_bSpdOverLimActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernSys_DernSys_bSpdOverLimActv_DernSys_bSpdOverLimActv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_bUdcOverTqLimActv_DernSys_bUdcOverTqLimActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernSys_DernSys_bUdcOverTqLimActv_DernSys_bUdcOverTqLimActv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_bUdcOverTqLimZeroActv_DernSys_bUdcOverTqLimZeroActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernSys_DernSys_bUdcOverTqLimZeroActv_DernSys_bUdcOverTqLimZeroActv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_bUdcUnderTqLim_DernSys_bUdcUnderTqLim(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernSys_DernSys_bUdcUnderTqLim_DernSys_bUdcUnderTqLim = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_bUdcUnderTqLimZero_DernSys_bUdcUnderTqLimZero(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernSys_DernSys_bUdcUnderTqLimZero_DernSys_bUdcUnderTqLimZero = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_facAntiSlipDern_DernSys_facAntiSlipDern(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernSys_DernSys_facAntiSlipDern_DernSys_facAntiSlipDern = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_facGenSpdOverLim_DernSys_facGenSpdOverLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernSys_DernSys_facGenSpdOverLim_DernSys_facGenSpdOverLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_facGenUdcLim_DernSys_facGenUdcLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernSys_DernSys_facGenUdcLim_DernSys_facGenUdcLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_facMotSpdOverLim_DernSys_facMotSpdOverLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernSys_DernSys_facMotSpdOverLim_DernSys_facMotSpdOverLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_facMotUdcLim_DernSys_facMotUdcLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernSys_DernSys_facMotUdcLim_DernSys_facMotUdcLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_pwrGenIdcLim_DernSys_pwrGenIdcLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernSys_DernSys_pwrGenIdcLim_DernSys_pwrGenIdcLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_pwrMotIdcLim_DernSys_pwrMotIdcLim(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DernSys_DernSys_pwrMotIdcLim_DernSys_pwrMotIdcLim = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EmPwr_EmPwr_iDCLnk_EmPwr_iDCLnk(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EmPwr_EmPwr_iDCLnk_EmPwr_iDCLnk = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EmPwr_EmPwr_iDCLnkFiltd_EmPwr_iDCLnkFiltd(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EmPwr_EmPwr_iDCLnkFiltd_EmPwr_iDCLnkFiltd = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EmPwr_EmPwr_pwrDCLnk_EmPwr_pwrDCLnk(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EmPwr_EmPwr_pwrDCLnk_EmPwr_pwrDCLnk = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EmTq_EmTq_tqEm_EmTq_tqEm(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EmTq_EmTq_tqEm_EmTq_tqEm = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EmTq_EmTq_tqEmFiltd_EmTq_tqEmFiltd(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EmTq_EmTq_tqEmFiltd_EmTq_tqEmFiltd = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EmTq_EmTq_tqEmLost_EmTq_tqEmLost(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EmTq_EmTq_tqEmLost_EmTq_tqEmLost = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EmTq_EmTq_tqMecl_EmTq_tqMecl(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EmTq_EmTq_tqMecl_EmTq_tqMecl = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ExtTqDes_ExtTqDes_bHvRdy_ExtTqDes_bHvRdy(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ExtTqDes_ExtTqDes_bHvRdy_ExtTqDes_bHvRdy = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ExtTqDes_ExtTqDes_bMaxLimActv_ExtTqDes_bMaxLimActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ExtTqDes_ExtTqDes_bMaxLimActv_ExtTqDes_bMaxLimActv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ExtTqDes_ExtTqDes_bMinLimActv_ExtTqDes_bMinLimActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ExtTqDes_ExtTqDes_bMinLimActv_ExtTqDes_bMinLimActv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ExtTqDes_ExtTqDes_tqEmDes_ExtTqDes_tqEmDes(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ExtTqDes_ExtTqDes_tqEmDes_ExtTqDes_tqEmDes = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ExtTqDes_ExtTqDes_tqEmDesWoDampg_ExtTqDes_tqEmDesWoDampg(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ExtTqDes_ExtTqDes_tqEmDesWoDampg_ExtTqDes_tqEmDesWoDampg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ExtTqDes_ExtTqDes_tqEmMax_ExtTqDes_tqEmMax(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ExtTqDes_ExtTqDes_tqEmMax_ExtTqDes_tqEmMax = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ExtTqDes_ExtTqDes_tqEmMin_ExtTqDes_tqEmMin(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ExtTqDes_ExtTqDes_tqEmMin_ExtTqDes_tqEmMin = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ExtTqDes_ExtTqDes_tqFric_ExtTqDes_tqFric(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ExtTqDes_ExtTqDes_tqFric_ExtTqDes_tqFric = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ExtTqDes_ExtTqDes_tqPwrDcLnk_ExtTqDes_tqPwrDcLnk(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_ExtTqDes_ExtTqDes_tqPwrDcLnk_ExtTqDes_tqPwrDcLnk = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_HvIntlck_HvIntlck_bMCUHvIntlckClsd_HvIntlck_bMCUHvIntlckClsd(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_HvIntlck_HvIntlck_bMCUHvIntlckClsd_HvIntlck_bMCUHvIntlckClsd = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_HvIntlck_HvIntlck_frqPwmTx_HvIntlck_frqPwmTx(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_HvIntlck_HvIntlck_frqPwmTx_HvIntlck_frqPwmTx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_HvIntlck_HvIntlck_rDutyPwmTx_HvIntlck_rDutyPwmTx(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_HvIntlck_HvIntlck_rDutyPwmTx_HvIntlck_rDutyPwmTx = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_agCurrDaQa_IdqDes_agCurrDaQa(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqDes_IdqDes_agCurrDaQa_IdqDes_agCurrDaQa = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_facFlxExctSclg_IdqDes_facFlxExctSclg(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqDes_IdqDes_facFlxExctSclg_IdqDes_facFlxExctSclg = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_iDaDes_IdqDes_iDaDes(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqDes_IdqDes_iDaDes_IdqDes_iDaDes = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_iQaDes_IdqDes_iQaDes(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqDes_IdqDes_iQaDes_IdqDes_iQaDes = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_indtDa_IdqDes_indtDa(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqDes_IdqDes_indtDa_IdqDes_indtDa = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_indtQa_IdqDes_indtQa(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqDes_IdqDes_indtQa_IdqDes_indtQa = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_indtQaSubtDa_IdqDes_indtQaSubtDa(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqDes_IdqDes_indtQaSubtDa_IdqDes_indtQaSubtDa = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_mflxExct_IdqDes_mflxExct(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqDes_IdqDes_mflxExct_IdqDes_mflxExct = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_omRtr_IdqDes_omRtr(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqDes_IdqDes_omRtr_IdqDes_omRtr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_omRtrRecpr_IdqDes_omRtrRecpr(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqDes_IdqDes_omRtrRecpr_IdqDes_omRtrRecpr = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_resStr_IdqDes_resStr(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqDes_IdqDes_resStr_IdqDes_resStr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_stSgnTqEmDes_IdqDes_stSgnTqEmDes(sint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqDes_IdqDes_stSgnTqEmDes_IdqDes_stSgnTqEmDes = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_tqEmDes_IdqDes_tqEmDes(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqDes_IdqDes_tqEmDes_IdqDes_tqEmDes = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TempDev_TempDev_tPhyMot_TempDev_tPhyMot(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_TempDev_TempDev_tPhyMot_TempDev_tPhyMot = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TempDev_TempDev_tPhyMotFild_TempDev_tPhyMotFild(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_TempDev_TempDev_tPhyMotFild_TempDev_tPhyMotFild = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TempDev_TempDev_tPhySic_TempDev_tPhySic(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_TempDev_TempDev_tPhySic_TempDev_tPhySic = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TempDev_TempDev_tPhySicU_TempDev_tPhySicU(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_TempDev_TempDev_tPhySicU_TempDev_tPhySicU = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TempDev_TempDev_tPhySicV_TempDev_tPhySicV(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_TempDev_TempDev_tPhySicV_TempDev_tPhySicV = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TempDev_TempDev_tPhySicW_TempDev_tPhySicW(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_TempDev_TempDev_tPhySicW_TempDev_tPhySicW = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TqDemCoorn_TqDemCoorn_bTqCrosZrActv_TqDemCoorn_bTqCrosZrActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_TqDemCoorn_TqDemCoorn_bTqCrosZrActv_TqDemCoorn_bTqCrosZrActv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TqDemCoorn_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_TqDemCoorn_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd = *(&data);

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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ActvDampg_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_ActvDampg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ActvDampg_ComRx_IsgActvDampgModReq_ComRx_IsgActvDampgModReq(P2VAR(UInt8, AUTOMATIC, RTE_ActvDampg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_IsgActvDampgModReq_ComRx_IsgActvDampgModReq;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ActvDampg_ComRx_bDampgSwtActv_ComRx_bDampgSwtActv(P2VAR(UInt8, AUTOMATIC, RTE_ActvDampg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_bDampgSwtActv_ComRx_bDampgSwtActv;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ActvDampg_ExtTqDes_tqEmDesWoDampg_ExtTqDes_tqEmDesWoDampg(P2VAR(Float, AUTOMATIC, RTE_ActvDampg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ExtTqDes_ExtTqDes_tqEmDesWoDampg_ExtTqDes_tqEmDesWoDampg;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AntiRollBack_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_AntiRollBack_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AntiRollBack_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq(P2VAR(Boolean, AUTOMATIC, RTE_AntiRollBack_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AntiRollBack_ComRx_stBrkSwt_ComRx_stBrkSwt(P2VAR(Boolean, AUTOMATIC, RTE_AntiRollBack_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_stBrkSwt_ComRx_stBrkSwt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AntiRollBack_ComRx_stDrvGear_ComRx_stDrvGear(P2VAR(UInt8, AUTOMATIC, RTE_AntiRollBack_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_stDrvGear_ComRx_stDrvGear;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AntiRollBack_ComRx_stHndbrk_ComRx_stHndbrk(P2VAR(Boolean, AUTOMATIC, RTE_AntiRollBack_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_stHndbrk_ComRx_stHndbrk;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AntiRollBack_ComRx_tqDes_ComRx_tqDes(P2VAR(Float, AUTOMATIC, RTE_AntiRollBack_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_tqDes_ComRx_tqDes;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AntiRollBack_Diag_stMcuFltLvl_Diag_stMcuFltLvl(P2VAR(UInt8, AUTOMATIC, RTE_AntiRollBack_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_stMcuFltLvl_Diag_stMcuFltLvl;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AntiRollBack_TempDev_tPhyMot_TempDev_tPhyMot(P2VAR(Float, AUTOMATIC, RTE_AntiRollBack_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_TempDev_TempDev_tPhyMot_TempDev_tPhyMot;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_AC_AmbientTemperature_AC_AmbientTemperature(P2VAR(uint8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt8)Rte_ComBuffer_AC_AmbientTemperature_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_AC_AmbientTemperatureInvalid_AC_AmbientTemperatureInvalid(P2VAR(boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (Boolean)Rte_ComBuffer_AC_AmbientTemperatureInvalid_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_ActiveWakeupBit_BMSH_ActiveWakeupBit(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = FALSE;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_Address_BMSH_Address(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = 0U;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_BatCurrent_BMSH_BatCurrent(P2VAR(UInt16, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_BatCurrent_BMSH_BatCurrent;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_BusVolt_BMSH_BusVolt(P2VAR(UInt16, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_BusVolt_BMSH_BusVolt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_NMSts_BMSH_NMSts(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = FALSE;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_RMR_BMSH_RMR(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = FALSE;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_Status_AliveCounter_BMSH_Status_AliveCounter(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_PMS_RollingCounter_BMSH_Status_AliveCounter_BMSH_Status_AliveCounter;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_Status_CheckSum_BMSH_Status_CheckSum(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = 0U;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_StayAwake_Reasons_BMSH_StayAwake_Reasons(P2VAR(UInt32, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = 0U;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_StsMode_BMSH_StsMode(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_StsMode_BMSH_StsMode;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_VCU_Crash_BMSH_VCU_Crash(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMSH_VCU_Crash_BMSH_VCU_Crash;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_PMS_RollingCounter_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_VoltCurrent_CheckSum_BMSH_VoltCurrent_CheckSum(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = 0U;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_BMSH_WakeUp_Reasons_BMSH_WakeUp_Reasons(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = 0U;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_EPBStatus_EHB_EPBStatus(P2VAR(uint8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt8)Rte_ComBuffer_EHB_EPBStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_FLWheelDirection_EHB_FLWheelDirection(P2VAR(uint8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt8)Rte_ComBuffer_EHB_FLWheelDirection_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_FLWheelSpeedInvalid_EHB_FLWheelSpeedInvalid(P2VAR(boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (Boolean)Rte_ComBuffer_EHB_FLWheelSpeedInvalid_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_FLWheelSpeedKPH_EHB_FLWheelSpeedKPH(P2VAR(uint16, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt16)Rte_ComBuffer_EHB_FLWheelSpeedKPH_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_FRWheelDirection_EHB_FRWheelDirection(P2VAR(uint8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt8)Rte_ComBuffer_EHB_FRWheelDirection_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_FRWheelSpeedInvalid_EHB_FRWheelSpeedInvalid(P2VAR(boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (Boolean)Rte_ComBuffer_EHB_FRWheelSpeedInvalid_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_FRWheelSpeedKPH_EHB_FRWheelSpeedKPH(P2VAR(uint16, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt16)Rte_ComBuffer_EHB_FRWheelSpeedKPH_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_FrontWheelSpeedsKPH_AliveCounter_EHB_FrontWheelSpeedsKPH_AliveCounter(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = 0U;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_FrontWheelSpeedsKPH_CheckSum_EHB_FrontWheelSpeedsKPH_CheckSum(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = 0U;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_RLWheelDirection_EHB_RLWheelDirection(P2VAR(uint8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt8)Rte_ComBuffer_EHB_RLWheelDirection_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_RLWheelSpeedInvalid_EHB_RLWheelSpeedInvalid(P2VAR(boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (Boolean)Rte_ComBuffer_EHB_RLWheelSpeedInvalid_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_RLWheelSpeedKPH_EHB_RLWheelSpeedKPH(P2VAR(uint16, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt16)Rte_ComBuffer_EHB_RLWheelSpeedKPH_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_RRWheelDirection_EHB_RRWheelDirection(P2VAR(uint8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt8)Rte_ComBuffer_EHB_RRWheelDirection_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_RRWheelSpeedInvalid_EHB_RRWheelSpeedInvalid(P2VAR(boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (Boolean)Rte_ComBuffer_EHB_RRWheelSpeedInvalid_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_RRWheelSpeedKPH_EHB_RRWheelSpeedKPH(P2VAR(uint16, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt16)Rte_ComBuffer_EHB_RRWheelSpeedKPH_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_RearWheelSpeedsKPH_EHB_RearWheelSpeedsKPH(P2VAR(Float, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = 0.0F;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_RearWheelSpeedsKPH_AliveCounter_EHB_RearWheelSpeedsKPH_AliveCounter(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = 0U;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_RearWheelSpeedsKPH_CheckSum_EHB_RearWheelSpeedsKPH_CheckSum(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = 0U;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_Status_AliveCounter_EHB_Status_AliveCounter(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = 0U;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_Status_CheckSum_EHB_Status_CheckSum(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = 0U;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_VehicleSpeed_EHB_VehicleSpeed(P2VAR(uint16, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt16)Rte_ComBuffer_EHB_VehicleSpeed_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_EHB_VehicleSpeedInvalid_EHB_VehicleSpeedInvalid(P2VAR(boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (Boolean)Rte_ComBuffer_EHB_VehicleSpeedInvalid_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_IPK_IPKTotalOdometer_IPK_IPKTotalOdometer(P2VAR(UInt32, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = 0U;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PEPS_PowerMode_PEPS_PowerMode(P2VAR(uint8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt8)Rte_ComBuffer_PEPS_PowerMode_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PEPS_PowerModeValidity_PEPS_PowerModeValidity(P2VAR(uint8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt8)Rte_ComBuffer_PEPS_PowerModeValidity_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_AWB_PMS_AWB(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = 0U;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_Command_AliveCounter_PMS_Command_AliveCounter(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_Command_AliveCounter_PMS_Command_AliveCounter;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_Command_Checksum_PMS_Command_Checksum(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_Command_Checksum_PMS_Command_Checksum;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_CurrentGearPosition_PMS_CurrentGearPosition(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_CurrentGearPosition_PMS_CurrentGearPosition;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_EDCPEnable_PMS_EDCPEnable(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_EDCPEnable_PMS_EDCPEnable;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_IPUFlowFeedback_PMS_IPUFlowFeedback(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = 0U;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_IgnONSts_PMS_IgnONSts(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_IgnONSts_PMS_IgnONSts;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_IsgModReq_PMS_IsgModReq(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_IsgModReq_PMS_IsgModReq;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_IsgTqReq_PMS_IsgTqReq(P2VAR(UInt16, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_IsgTqReq_PMS_IsgTqReq;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_NMSts_PMS_NMSts(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_NMSts_PMS_NMSts;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_RMR_PMS_RMR(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = 0U;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_Real_PedalPosition_PMS_Real_PedalPosition(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_Real_PedalPosition_PMS_Real_PedalPosition;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_Stayawake_reasons_PMS_Stayawake_reasons(P2VAR(UInt32, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_Stayawake_reasons_PMS_Stayawake_reasons;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_StsBrkSwitch1_PMS_StsBrkSwitch1(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_StsBrkSwitch1_PMS_StsBrkSwitch1;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_StsBrkSwitch1Invalid_PMS_StsBrkSwitch1Invalid(P2VAR(Boolean, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_StsBrkSwitch1Invalid_PMS_StsBrkSwitch1Invalid;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_TM_Address_PMS_TM_Address(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    *(data) = 0U;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_PMS_Wakeup_reasons_PMS_Wakeup_reasons(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_Wakeup_reasons_PMS_Wakeup_reasons;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_TBOX_Day_TBOX_Day(P2VAR(uint8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt8)Rte_ComBuffer_TBOX_Day_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_TBOX_Hour_TBOX_Hour(P2VAR(uint8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt8)Rte_ComBuffer_TBOX_Hour_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_TBOX_Minute_TBOX_Minute(P2VAR(uint8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt8)Rte_ComBuffer_TBOX_Minute_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_TBOX_Month_TBOX_Month(P2VAR(uint8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt8)Rte_ComBuffer_TBOX_Month_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_TBOX_Second_TBOX_Second(P2VAR(uint8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt8)Rte_ComBuffer_TBOX_Second_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_TBOX_Year_TBOX_Year(P2VAR(uint8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;

    *data = (UInt8)Rte_ComBuffer_TBOX_Year_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComRx_CAN_VCU_CrashOutputSts_VCU_CrashOutputSts(P2VAR(UInt8, AUTOMATIC, RTE_ComRx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_VCU_CrashOutputSts_VCU_CrashOutputSts;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_AntiRollBack_bAntiRollActv_AntiRollBack_bAntiRollActv(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AntiRollBack_AntiRollBack_bAntiRollActv_AntiRollBack_bAntiRollActv;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_BIfRx_stPWM_BIfRx_stPWM(P2VAR(UInt8, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_stPWM_BIfRx_stPWM;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_DernCoorn_tqEmMax_DernCoorn_tqEmMax(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernCoorn_DernCoorn_tqEmMax_DernCoorn_tqEmMax;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_DernCoorn_tqEmMin_DernCoorn_tqEmMin(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernCoorn_DernCoorn_tqEmMin_DernCoorn_tqEmMin;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bActvDchrgTioutFlt_Diag_bActvDchrgTioutFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bActvDchrgTioutFlt_Diag_bActvDchrgTioutFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bBmsNodMissFlt_Diag_bBmsNodMissFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bBmsNodMissFlt_Diag_bBmsNodMissFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bBusOverVoltAlrm_Diag_bBusOverVoltAlrm(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bBusOverVoltAlrm_Diag_bBusOverVoltAlrm;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bBusOverVoltFlt_Diag_bBusOverVoltFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bBusOverVoltFlt_Diag_bBusOverVoltFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bBusUnderVoltAlrm_Diag_bBusUnderVoltAlrm(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bBusUnderVoltAlrm_Diag_bBusUnderVoltAlrm;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bE2EChksFlt_Diag_bE2EChksFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bE2EChksFlt_Diag_bE2EChksFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bHwBusOffFlt_Diag_bHwBusOffFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bHwBusOffFlt_Diag_bHwBusOffFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bHwOverCurrFlt_Diag_bHwOverCurrFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bHwOverCurrFlt_Diag_bHwOverCurrFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bHwOverVoltFlt_Diag_bHwOverVoltFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bHwOverVoltFlt_Diag_bHwOverVoltFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bIGBTDrvFlt_Diag_bIGBTDrvFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bIGBTDrvFlt_Diag_bIGBTDrvFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bLvVoltHiLimFlt_Diag_bLvVoltHiLimFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bLvVoltHiLimFlt_Diag_bLvVoltHiLimFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bLvVoltOverAlrm_Diag_bLvVoltOverAlrm(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bLvVoltOverAlrm_Diag_bLvVoltOverAlrm;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bLvVoltUnderFlt_Diag_bLvVoltUnderFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bLvVoltUnderFlt_Diag_bLvVoltUnderFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bMcuStorgUnitFlt_Diag_bMcuStorgUnitFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bMcuStorgUnitFlt_Diag_bMcuStorgUnitFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bMcuTempSnsrShoCircGndFlt_Diag_bMcuTempSnsrShoCircGndFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bMcuTempSnsrShoCircGndFlt_Diag_bMcuTempSnsrShoCircGndFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bMcuTempSnsrShoCircPwrFlt_Diag_bMcuTempSnsrShoCircPwrFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bMcuTempSnsrShoCircPwrFlt_Diag_bMcuTempSnsrShoCircPwrFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bMotOverSpdFlt_Diag_bMotOverSpdFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bMotOverSpdFlt_Diag_bMotOverSpdFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bMotStalFlt_Diag_bMotStalFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bMotStalFlt_Diag_bMotStalFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bMotStrOverTempAlrm_Diag_bMotStrOverTempAlrm(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bMotStrOverTempAlrm_Diag_bMotStrOverTempAlrm;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bMotStrOverTempFlt_Diag_bMotStrOverTempFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bMotStrOverTempFlt_Diag_bMotStrOverTempFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bMotTempSnsrShoCircGndFlt_Diag_bMotTempSnsrShoCircGndFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bMotTempSnsrShoCircGndFlt_Diag_bMotTempSnsrShoCircGndFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bMotTempSnsrShoCircPwrFlt_Diag_bMotTempSnsrShoCircPwrFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bMotTempSnsrShoCircPwrFlt_Diag_bMotTempSnsrShoCircPwrFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bPhaCurrOverFlt_Diag_bPhaCurrOverFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bPhaCurrOverFlt_Diag_bPhaCurrOverFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bPhaCurrUShoCircGndFlt_Diag_bPhaCurrUShoCircGndFlt(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bPhaCurrUShoCircGndFlt_Diag_bPhaCurrUShoCircGndFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bPhaCurrUShoCircPwrFlt_Diag_bPhaCurrUShoCircPwrFlt(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bPhaCurrUShoCircPwrFlt_Diag_bPhaCurrUShoCircPwrFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bPhaCurrVShoCircGndFlt_Diag_bPhaCurrVShoCircGndFlt(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bPhaCurrVShoCircGndFlt_Diag_bPhaCurrVShoCircGndFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bPhaCurrVShoCircPwrFlt_Diag_bPhaCurrVShoCircPwrFlt(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bPhaCurrVShoCircPwrFlt_Diag_bPhaCurrVShoCircPwrFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bPhaCurrWShoCircGndFlt_Diag_bPhaCurrWShoCircGndFlt(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bPhaCurrWShoCircGndFlt_Diag_bPhaCurrWShoCircGndFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bPhaCurrWShoCircPwrFlt_Diag_bPhaCurrWShoCircPwrFlt(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bPhaCurrWShoCircPwrFlt_Diag_bPhaCurrWShoCircPwrFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bRotyTrfrFlt_Diag_bRotyTrfrFlt(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bRotyTrfrFlt_Diag_bRotyTrfrFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bSicOverTempAlrm_Diag_bSicOverTempAlrm(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bSicOverTempAlrm_Diag_bSicOverTempAlrm;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bSicOverTempFlt_Diag_bSicOverTempFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bSicOverTempFlt_Diag_bSicOverTempFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bVcuNodMissFlt_Diag_bVcuNodMissFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bVcuNodMissFlt_Diag_bVcuNodMissFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_noDTCNr_Diag_noDTCNr(P2VAR(UInt8, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_noDTCNr_Diag_noDTCNr;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_stMcuFltLvl_Diag_stMcuFltLvl(P2VAR(UInt8, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_stMcuFltLvl_Diag_stMcuFltLvl;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_stMcuSubFltLvl_Diag_stMcuSubFltLvl(P2VAR(UInt8, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_stMcuSubFltLvl_Diag_stMcuSubFltLvl;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_EmPwr_iDCLnkFiltd_EmPwr_iDCLnkFiltd(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EmPwr_EmPwr_iDCLnkFiltd_EmPwr_iDCLnkFiltd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_HvInvDev_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqAct_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta(P2VAR(UInt8, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_MMC_MCUWorkMode_sta_MMC_MCUWorkMode_sta(P2VAR(UInt8, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_MMC_MCUWorkMode_sta_MMC_MCUWorkMode_sta;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_TempDev_tPhyMotFild_TempDev_tPhyMotFild(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_TempDev_TempDev_tPhyMotFild_TempDev_tPhyMotFild;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_TempDev_tPhySic_TempDev_tPhySic(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_TempDev_TempDev_tPhySic_TempDev_tPhySic;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Dchrg_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr(P2VAR(Boolean, AUTOMATIC, RTE_Dchrg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Dchrg_HvInvDev_uPhyHV_HvInvDev_uPhyHV(P2VAR(Float, AUTOMATIC, RTE_Dchrg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Dchrg_HvInvDev_uRpl_HvInvDev_uRpl(P2VAR(Float, AUTOMATIC, RTE_Dchrg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_HvInvDev_HvInvDev_uRpl_HvInvDev_uRpl;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Dchrg_MMC_MCUDischgEn_cmd_MMC_MCUDischgEn_cmd(P2VAR(Boolean, AUTOMATIC, RTE_Dchrg_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_MMC_MCUDischgEn_cmd_MMC_MCUDischgEn_cmd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_AngSwDecod_nRotateMeclAgSpd_AngSwDecod_nRotateMeclAgSpd(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_nRotateMeclAgSpd_AngSwDecod_nRotateMeclAgSpd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs(P2VAR(UInt16, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernEm_facGenTempRtrLim_DernEm_facGenTempRtrLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernEm_DernEm_facGenTempRtrLim_DernEm_facGenTempRtrLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernEm_facGenTempStrLim_DernEm_facGenTempStrLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernEm_DernEm_facGenTempStrLim_DernEm_facGenTempStrLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernEm_facMotTempRtrLim_DernEm_facMotTempRtrLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernEm_DernEm_facMotTempRtrLim_DernEm_facMotTempRtrLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernEm_facMotTempStrLim_DernEm_facMotTempStrLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernEm_DernEm_facMotTempStrLim_DernEm_facMotTempStrLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernEm_tqGenExtChartcLim_DernEm_tqGenExtChartcLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernEm_DernEm_tqGenExtChartcLim_DernEm_tqGenExtChartcLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernEm_tqMotExtChartcLim_DernEm_tqMotExtChartcLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernEm_DernEm_tqMotExtChartcLim_DernEm_tqMotExtChartcLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernInv_facGenTempIvtrCooltLim_DernInv_facGenTempIvtrCooltLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernInv_DernInv_facGenTempIvtrCooltLim_DernInv_facGenTempIvtrCooltLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernInv_facGenTempSicLim_DernInv_facGenTempSicLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernInv_DernInv_facGenTempSicLim_DernInv_facGenTempSicLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernInv_facGeniSqrtLim_DernInv_facGeniSqrtLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernInv_DernInv_facGeniSqrtLim_DernInv_facGeniSqrtLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernInv_facMotTempIvtrCooltLim_DernInv_facMotTempIvtrCooltLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernInv_DernInv_facMotTempIvtrCooltLim_DernInv_facMotTempIvtrCooltLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernInv_facMotTempSicLim_DernInv_facMotTempSicLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernInv_DernInv_facMotTempSicLim_DernInv_facMotTempSicLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernInv_facMotiSqrtLim_DernInv_facMotiSqrtLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernInv_DernInv_facMotiSqrtLim_DernInv_facMotiSqrtLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernSys_facAntiSlipDern_DernSys_facAntiSlipDern(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernSys_DernSys_facAntiSlipDern_DernSys_facAntiSlipDern;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernSys_facGenSpdOverLim_DernSys_facGenSpdOverLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernSys_DernSys_facGenSpdOverLim_DernSys_facGenSpdOverLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernSys_facGenUdcLim_DernSys_facGenUdcLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernSys_DernSys_facGenUdcLim_DernSys_facGenUdcLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernSys_facMotSpdOverLim_DernSys_facMotSpdOverLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernSys_DernSys_facMotSpdOverLim_DernSys_facMotSpdOverLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernSys_facMotUdcLim_DernSys_facMotUdcLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernSys_DernSys_facMotUdcLim_DernSys_facMotUdcLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernSys_pwrGenIdcLim_DernSys_pwrGenIdcLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernSys_DernSys_pwrGenIdcLim_DernSys_pwrGenIdcLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernSys_pwrMotIdcLim_DernSys_pwrMotIdcLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernSys_DernSys_pwrMotIdcLim_DernSys_pwrMotIdcLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_Diag_facDiagTqDern_Diag_facDiagTqDern(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_facDiagTqDern_Diag_facDiagTqDern;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr(P2VAR(UInt8, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_ExtTqDes_tqEmMax_ExtTqDes_tqEmMax(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ExtTqDes_ExtTqDes_tqEmMax_ExtTqDes_tqEmMax;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_ExtTqDes_tqEmMin_ExtTqDes_tqEmMin(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ExtTqDes_ExtTqDes_tqEmMin_ExtTqDes_tqEmMin;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernEm_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs(P2VAR(UInt16, AUTOMATIC, RTE_DernEm_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernEm_Diag_bMotStalFlt_Diag_bMotStalFlt(P2VAR(Boolean, AUTOMATIC, RTE_DernEm_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bMotStalFlt_Diag_bMotStalFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernEm_EmTMdl_tRtr_EmTMdl_tRtr(P2VAR(Float, AUTOMATIC, RTE_DernEm_APPL_DATA) data)
{
    *(data) = 0.0F;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernEm_HvInvDev_uPhyHV_HvInvDev_uPhyHV(P2VAR(Float, AUTOMATIC, RTE_DernEm_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernEm_IdqAct_iSqrt_IdqAct_iSqrt(P2VAR(Float, AUTOMATIC, RTE_DernEm_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqAct_IdqAct_iSqrt_IdqAct_iSqrt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernEm_TempDev_tPhyMotFild_TempDev_tPhyMotFild(P2VAR(Float, AUTOMATIC, RTE_DernEm_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_TempDev_TempDev_tPhyMotFild_TempDev_tPhyMotFild;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernInv_ComRx_tIvtrCooltInlet_ComRx_tIvtrCooltInlet(P2VAR(Float, AUTOMATIC, RTE_DernInv_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_tIvtrCooltInlet_ComRx_tIvtrCooltInlet;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernInv_IdqAct_iSqrt_IdqAct_iSqrt(P2VAR(Float, AUTOMATIC, RTE_DernInv_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqAct_IdqAct_iSqrt_IdqAct_iSqrt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernInv_TempDev_tPhySic_TempDev_tPhySic(P2VAR(Float, AUTOMATIC, RTE_DernInv_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_TempDev_TempDev_tPhySic_TempDev_tPhySic;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernSys_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_DernSys_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernSys_EmPwr_pwrDCLnk_EmPwr_pwrDCLnk(P2VAR(Float, AUTOMATIC, RTE_DernSys_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EmPwr_EmPwr_pwrDCLnk_EmPwr_pwrDCLnk;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernSys_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd(P2VAR(Float, AUTOMATIC, RTE_DernSys_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_HvInvDev_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_EmPwr_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_HvInvDev_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_IdqAct_iDa_IdqAct_iDa(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqAct_IdqAct_iDa_IdqAct_iDa;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_IdqAct_iQa_IdqAct_iQa(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqAct_IdqAct_iQa_IdqAct_iQa;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_IdqCtrl_uDaPI_IdqCtrl_uDaPI(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqCtrl_IdqCtrl_uDaPI_IdqCtrl_uDaPI;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_IdqCtrl_uQaPI_IdqCtrl_uQaPI(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqCtrl_IdqCtrl_uQaPI_IdqCtrl_uQaPI;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_PhaCurrDev_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_PhaCurrDev_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_PhaCurrDev_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_TqDemCoorn_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_VoltModlnGen_rDutyU_VoltModlnGen_rDutyU(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_VoltModlnGen_VoltModlnGen_rDutyU_VoltModlnGen_rDutyU;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_VoltModlnGen_rDutyV_VoltModlnGen_rDutyV(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_VoltModlnGen_VoltModlnGen_rDutyV_VoltModlnGen_rDutyV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_VoltModlnGen_rDutyW_VoltModlnGen_rDutyW(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_VoltModlnGen_VoltModlnGen_rDutyW_VoltModlnGen_rDutyW;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs(P2VAR(UInt16, AUTOMATIC, RTE_EmTq_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir(P2VAR(SInt8, AUTOMATIC, RTE_EmTq_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_Diag_bPhaCurrUShoCircGndFlt_Diag_bPhaCurrUShoCircGndFlt(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bPhaCurrUShoCircGndFlt_Diag_bPhaCurrUShoCircGndFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_Diag_bPhaCurrUShoCircPwrFlt_Diag_bPhaCurrUShoCircPwrFlt(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bPhaCurrUShoCircPwrFlt_Diag_bPhaCurrUShoCircPwrFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_Diag_bPhaCurrVShoCircGndFlt_Diag_bPhaCurrVShoCircGndFlt(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bPhaCurrVShoCircGndFlt_Diag_bPhaCurrVShoCircGndFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_Diag_bPhaCurrVShoCircPwrFlt_Diag_bPhaCurrVShoCircPwrFlt(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bPhaCurrVShoCircPwrFlt_Diag_bPhaCurrVShoCircPwrFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_Diag_bPhaCurrWShoCircGndFlt_Diag_bPhaCurrWShoCircGndFlt(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bPhaCurrWShoCircGndFlt_Diag_bPhaCurrWShoCircGndFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_Diag_bPhaCurrWShoCircPwrFlt_Diag_bPhaCurrWShoCircPwrFlt(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bPhaCurrWShoCircPwrFlt_Diag_bPhaCurrWShoCircPwrFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr(P2VAR(UInt8, AUTOMATIC, RTE_EmTq_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_ExtTqDes_tqFric_ExtTqDes_tqFric(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ExtTqDes_ExtTqDes_tqFric_ExtTqDes_tqFric;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_IdqAct_iDaFiltd_IdqAct_iDaFiltd(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqAct_IdqAct_iDaFiltd_IdqAct_iDaFiltd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_IdqAct_iQaFiltd_IdqAct_iQaFiltd(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqAct_IdqAct_iQaFiltd_IdqAct_iQaFiltd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_IdqAct_iSqrt_IdqAct_iSqrt(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqAct_IdqAct_iSqrt_IdqAct_iSqrt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_IdqDes_indtQaSubtDa_IdqDes_indtQaSubtDa(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqDes_IdqDes_indtQaSubtDa_IdqDes_indtQaSubtDa;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_IdqDes_mflxExct_IdqDes_mflxExct(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqDes_IdqDes_mflxExct_IdqDes_mflxExct;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_AngSwDecod_nRotateMeclAgSpd_AngSwDecod_nRotateMeclAgSpd(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_nRotateMeclAgSpd_AngSwDecod_nRotateMeclAgSpd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir(P2VAR(SInt8, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_ComRx_facTqSlopMax_ComRx_facTqSlopMax(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_facTqSlopMax_ComRx_facTqSlopMax;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_ComRx_iEfcDes_ComRx_iEfcDes(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_iEfcDes_ComRx_iEfcDes;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_ComRx_nDes_ComRx_nDes(P2VAR(SInt16, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_nDes_ComRx_nDes;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_ComRx_stDrvCtrlDes_ComRx_stDrvCtrlDes(P2VAR(UInt8, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_stDrvCtrlDes_ComRx_stDrvCtrlDes;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_ComRx_stDrvGear_ComRx_stDrvGear(P2VAR(UInt8, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_stDrvGear_ComRx_stDrvGear;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_ComRx_tqDes_ComRx_tqDes(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_tqDes_ComRx_tqDes;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_ComRx_tqMaxLim_ComRx_tqMaxLim(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_tqMaxLim_ComRx_tqMaxLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_ComRx_tqMinLim_ComRx_tqMinLim(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_tqMinLim_ComRx_tqMinLim;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_ComRx_uDCLnkDes_ComRx_uDCLnkDes(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_uDCLnkDes_ComRx_uDCLnkDes;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_DernCoorn_tqEmMax_DernCoorn_tqEmMax(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernCoorn_DernCoorn_tqEmMax_DernCoorn_tqEmMax;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_DernCoorn_tqEmMin_DernCoorn_tqEmMin(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernCoorn_DernCoorn_tqEmMin_DernCoorn_tqEmMin;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr(P2VAR(Boolean, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_EmPwr_pwrDCLnk_EmPwr_pwrDCLnk(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EmPwr_EmPwr_pwrDCLnk_EmPwr_pwrDCLnk;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_HvInvDev_uPhyHV_HvInvDev_uPhyHV(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_HvInvDev_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqAct_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta(P2VAR(UInt8, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HvIntlck_BIfRx_frqPwmRx_BIfRx_frqPwmRx(P2VAR(Float, AUTOMATIC, RTE_HvIntlck_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_frqPwmRx_BIfRx_frqPwmRx;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HvIntlck_BIfRx_rDutyPwmRx_BIfRx_rDutyPwmRx(P2VAR(Float, AUTOMATIC, RTE_HvIntlck_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_rDutyPwmRx_BIfRx_rDutyPwmRx;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_AngOfstCal_iDaDes_AngOfstCal_iDaDes(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngOfstCal_AngOfstCal_iDaDes_AngOfstCal_iDaDes;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_AngOfstCal_iQaDes_AngOfstCal_iQaDes(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngOfstCal_AngOfstCal_iQaDes_AngOfstCal_iQaDes;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_IdqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir(P2VAR(SInt8, AUTOMATIC, RTE_IdqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_Dchrg_iDchrg_Dchrg_iDchrg(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Dchrg_Dchrg_iDchrg_Dchrg_iDchrg;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr(P2VAR(Boolean, AUTOMATIC, RTE_IdqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_EmTq_tqEmLost_EmTq_tqEmLost(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EmTq_EmTq_tqEmLost_EmTq_tqEmLost;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_HvInvDev_uPhyHV_HvInvDev_uPhyHV(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_IdqAct_iDaFiltd_IdqAct_iDaFiltd(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqAct_IdqAct_iDaFiltd_IdqAct_iDaFiltd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_IdqAct_iQaFiltd_IdqAct_iQaFiltd(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqAct_IdqAct_iQaFiltd_IdqAct_iQaFiltd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_IdqCtrl_uPwmMax_IdqCtrl_uPwmMax(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqCtrl_IdqCtrl_uPwmMax_IdqCtrl_uPwmMax;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_IdqCtrl_uRsv_IdqCtrl_uRsv(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqCtrl_IdqCtrl_uRsv_IdqCtrl_uRsv;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_IdqCtrl_uSqrtMax_IdqCtrl_uSqrtMax(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqCtrl_IdqCtrl_uSqrtMax_IdqCtrl_uSqrtMax;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_IdqCtrl_uSqrtRsvSclg_IdqCtrl_uSqrtRsvSclg(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqCtrl_IdqCtrl_uSqrtRsvSclg_IdqCtrl_uSqrtRsvSclg;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta(P2VAR(UInt8, AUTOMATIC, RTE_IdqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_MMC_MCUDischgEn_cmd_MMC_MCUDischgEn_cmd(P2VAR(Boolean, AUTOMATIC, RTE_IdqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_MMC_MCUDischgEn_cmd_MMC_MCUDischgEn_cmd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_TempDev_tPhyMot_TempDev_tPhyMot(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_TempDev_TempDev_tPhyMot_TempDev_tPhyMot;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_TqDemCoorn_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TempDev_BIfRx_tPhyMot_BIfRx_tPhyMot(P2VAR(Float, AUTOMATIC, RTE_TempDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_tPhyMot_BIfRx_tPhyMot;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TempDev_BIfRx_tPhySicU_BIfRx_tPhySicU(P2VAR(Float, AUTOMATIC, RTE_TempDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_tPhySicU_BIfRx_tPhySicU;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TempDev_BIfRx_tPhySicV_BIfRx_tPhySicV(P2VAR(Float, AUTOMATIC, RTE_TempDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_tPhySicV_BIfRx_tPhySicV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TempDev_BIfRx_tPhySicW_BIfRx_tPhySicW(P2VAR(Float, AUTOMATIC, RTE_TempDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_tPhySicW_BIfRx_tPhySicW;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_ActvDampg_tqDampgCalc_ActvDampg_tqDampgCalc(P2VAR(Float, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ActvDampg_ActvDampg_tqDampgCalc_ActvDampg_tqDampgCalc;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs(P2VAR(UInt16, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_AntiRollBack_AntiRollCnt_AntiRollBack_AntiRollCnt(P2VAR(UInt8, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data)
{
    *(data) = 0U;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_AntiRollBack_bAntiRollActv_AntiRollBack_bAntiRollActv(P2VAR(Boolean, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AntiRollBack_AntiRollBack_bAntiRollActv_AntiRollBack_bAntiRollActv;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_AntiRollBack_tqCmdAntiRoll_AntiRollBack_tqCmdAntiRoll(P2VAR(Float, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AntiRollBack_AntiRollBack_tqCmdAntiRoll_AntiRollBack_tqCmdAntiRoll;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_DernCoorn_tqEmMax_DernCoorn_tqEmMax(P2VAR(Float, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernCoorn_DernCoorn_tqEmMax_DernCoorn_tqEmMax;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_DernCoorn_tqEmMin_DernCoorn_tqEmMin(P2VAR(Float, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernCoorn_DernCoorn_tqEmMin_DernCoorn_tqEmMin;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_DernEm_bCurrDernCtrl_DernEm_bCurrDernCtrl(P2VAR(Float, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernEm_DernEm_bCurrDernCtrl_DernEm_bCurrDernCtrl;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_DernEm_facDernCurr_DernEm_facDernCurr(P2VAR(Float, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DernEm_DernEm_facDernCurr_DernEm_facDernCurr;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr(P2VAR(UInt8, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_ExtTqDes_tqEmDesWoDampg_ExtTqDes_tqEmDesWoDampg(P2VAR(Float, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ExtTqDes_ExtTqDes_tqEmDesWoDampg_ExtTqDes_tqEmDesWoDampg;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta(P2VAR(UInt8, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta;
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
TASK(SWC_Init_Task_Core5)
{
    Core5_Runnable_Task_Init();

    ActvDampg_Init();

    AntiRollBack_Init();

    ComRx_CAN_1_Init();

    ComTx_Init();

    Dchrg_Init();

    DernCoorn_Init();

    DernEm_Init();

    DernInv_Init();

    DernSys_Init();

    EmPwr_Init();

    EmTq_Init();

    ExtTqDes_Init();

    HvIntlck_Init();

    IdqDes_Init();

    TempDev_Init();

    TqDemCoorn_Init();

    (void)TerminateTask();
}

TASK(App1_Task_1ms_Core5_QM)
{
    Core5_Runnable_App_1ms();

    fc_EmTq();

    fc_DernInv();

    fc_DernSys();

    fc_DernCoorn();

    fc_ExtTqDes();

    fc_AntiRollBack();

    fc_ActvDampg();

    fc_TqDemCoorn();

    fc_Dchrg();

    fc_IdqDes();

    (void)TerminateTask();
}

TASK(App1_Task_5ms_Core5_QM)
{
    Core5_Runnable_App_5ms();

    (void)TerminateTask();
}

TASK(App1_Task_10ms_Core5_QM)
{
    Core5_Runnable_App_10ms();

    fc_ComRx10ms();

    fc_TempDev();

    fc_EmPwr();

    fc_DernEm();

    fc_HVIntlck();

    fc_ComTx10ms();

    (void)TerminateTask();
}

TASK(App1_Task_20ms_Core5_QM)
{
    Core5_Runnable_App_20ms();

    fc_ComRx20ms();

    fc_ComTx20ms();

    (void)TerminateTask();
}

TASK(App1_Task_50ms_Core5_QM)
{
    Core5_Runnable_App_50ms();

    fc_ComTxEvent();

    (void)TerminateTask();
}

TASK(App1_Task_100ms_Core5_QM)
{
    Core5_Runnable_App_100ms();

    fc_ComRx100ms();

    fc_ComTx100ms();

    (void)TerminateTask();
}

TASK(App1_Task_200ms_Core5_QM)
{
    fc_ComRx200ms();

    (void)TerminateTask();
}

TASK(App1_Task_500ms_Core5_QM)
{
    fc_ComRx500ms();

    fc_ComTx500ms();

    (void)TerminateTask();
}

TASK(App1_Task_1000ms_Core5_QM)
{
    fc_ComRx1000ms();

    fc_ComRxEvent();

    (void)TerminateTask();
}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
TASK(App1_Task_UDS_Core5_QM)
{
    EventMaskType ev = 0U;
    for(;;)
    {
        (void)WaitEvent(APP1_EVENT_UDS_CORE5_QM);
        (void)GetEvent(APP1_TASK_UDS_CORE5_QM, &ev);
        (void)ClearEvent(ev & (APP1_EVENT_UDS_CORE5_QM));

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


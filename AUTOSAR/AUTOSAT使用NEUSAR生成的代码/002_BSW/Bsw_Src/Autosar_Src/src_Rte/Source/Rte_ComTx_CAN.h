 
/*
************************************************************************************************************************
*
* File name: Rte_ComTx_CAN.h
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
#ifndef RTE_COMTX_CAN_H_
#define RTE_COMTX_CAN_H_

#include "Rte_ComTx_CAN_Type.h"
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
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_AWB_IPU_AWB;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_Address_IPU_Address;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgHeatFdBck_IPU_IsgHeatFdBck;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgHeatPwrAct_IPU_IsgHeatPwrAct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgHeatPwrMax_IPU_IsgHeatPwrMax;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MaxCurrt_IPU_MaxCurrt;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MaxTrq_IPU_MaxTrq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_NMSts_IPU_NMSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_RMR_IPU_RMR;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_RatedVoltg_IPU_RatedVoltg;
extern VAR(UInt32, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_Stayawake_reasons_IPU_Stayawake_reasons;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_Wakeup_reasons_IPU_Wakeup_reasons;
extern VAR(Boolean, RTE_VAR_INIT) Rte_AntiRollBack_AntiRollBack_bAntiRollActv_AntiRollBack_bAntiRollActv;
extern VAR(Float, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_tqEmMax_DernCoorn_tqEmMax;
extern VAR(Float, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_tqEmMin_DernCoorn_tqEmMin;
extern VAR(Float, RTE_VAR_INIT) Rte_EmPwr_EmPwr_iDCLnkFiltd_EmPwr_iDCLnkFiltd;
extern VAR(Float, RTE_VAR_INIT) Rte_TempDev_TempDev_tPhyMotFild_TempDev_tPhyMotFild;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(SInt16, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_BIfRx_BIfRx_stPWM_BIfRx_stPWM;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bActvDchrgTioutFlt_Diag_bActvDchrgTioutFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bBmsNodMissFlt_Diag_bBmsNodMissFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bBusOverVoltAlrm_Diag_bBusOverVoltAlrm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bBusOverVoltFlt_Diag_bBusOverVoltFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bBusUnderVoltAlrm_Diag_bBusUnderVoltAlrm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bE2EChksFlt_Diag_bE2EChksFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bHwBusOffFlt_Diag_bHwBusOffFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bHwOverCurrFlt_Diag_bHwOverCurrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bHwOverVoltFlt_Diag_bHwOverVoltFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bIGBTDrvFlt_Diag_bIGBTDrvFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bLvVoltHiLimFlt_Diag_bLvVoltHiLimFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bLvVoltOverAlrm_Diag_bLvVoltOverAlrm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bLvVoltUnderFlt_Diag_bLvVoltUnderFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMcuStorgUnitFlt_Diag_bMcuStorgUnitFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMcuTempSnsrShoCircGndFlt_Diag_bMcuTempSnsrShoCircGndFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMcuTempSnsrShoCircPwrFlt_Diag_bMcuTempSnsrShoCircPwrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMotOverSpdFlt_Diag_bMotOverSpdFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMotStalFlt_Diag_bMotStalFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMotStrOverTempAlrm_Diag_bMotStrOverTempAlrm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMotStrOverTempFlt_Diag_bMotStrOverTempFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMotTempSnsrShoCircGndFlt_Diag_bMotTempSnsrShoCircGndFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMotTempSnsrShoCircPwrFlt_Diag_bMotTempSnsrShoCircPwrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrOverFlt_Diag_bPhaCurrOverFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrUShoCircGndFlt_Diag_bPhaCurrUShoCircGndFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrUShoCircPwrFlt_Diag_bPhaCurrUShoCircPwrFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrVShoCircGndFlt_Diag_bPhaCurrVShoCircGndFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrVShoCircPwrFlt_Diag_bPhaCurrVShoCircPwrFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrWShoCircGndFlt_Diag_bPhaCurrWShoCircGndFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrWShoCircPwrFlt_Diag_bPhaCurrWShoCircPwrFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bRotyTrfrFlt_Diag_bRotyTrfrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bSicOverTempAlrm_Diag_bSicOverTempAlrm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bSicOverTempFlt_Diag_bSicOverTempFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bVcuNodMissFlt_Diag_bVcuNodMissFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Diag_Diag_noDTCNr_Diag_noDTCNr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Diag_Diag_stMcuFltLvl_Diag_stMcuFltLvl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Diag_Diag_stMcuSubFltLvl_Diag_stMcuSubFltLvl;
extern VAR(Float, RTE_VAR_INIT) Rte_HvInvDev_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUWorkMode_sta_MMC_MCUWorkMode_sta;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_ActiveDischgFlt_IPU_ActiveDischgFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_BattFaultLampState_IPU_BattFaultLampState;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_BusUndervolt_IPU_BusUndervolt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_CANCommFlt_IPU_CANCommFlt;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_DTC_IPU_DTC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_DischgState_IPU_DischgState;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_HVBusCur_IPU_HVBusCur;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_HVBusVolt_20_IPU_HVBusVolt_20;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_HVBusVolt_500_IPU_HVBusVolt_500;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_HardwareCapOverVolt_IPU_HardwareCapOverVolt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IGBTFlt_IPU_IGBTFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgInvrT_IPU_IsgInvrT;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgInvrTInvalid_IPU_IsgInvrTInvalid;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgModSts_IPU_IsgModSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgModStsInvalid_IPU_IsgModStsInvalid;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgMotT_IPU_IsgMotT;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgMotTInvalid_IPU_IsgMotTInvalid;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgOverTemp_IPU_IsgOverTemp;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgTqActIsgTqActInvalid_IPU_IsgTqActIsgTqActInvalid;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_LV_VotagtFault_IPU_LV_VotagtFault;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MCUMemoryFlt_IPU_MCUMemoryFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MCUTempHighAlarm_IPU_MCUTempHighAlarm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MCUTempHighFault_IPU_MCUTempHighFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MCUTempSensorErr_IPU_MCUTempSensorErr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorFltLevell1_IPU_MotorFltLevell1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorFltLevell_Invalid_IPU_MotorFltLevell_Invalid;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorLockRotErr_IPU_MotorLockRotErr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorNum_IPU_MotorNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorNumSN_IPU_MotorNumSN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorSpdHighAlarm_IPU_MotorSpdHighAlarm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorSts_IPU_MotorSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorTempHighAlarm_IPU_MotorTempHighAlarm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorTempHighFault_IPU_MotorTempHighFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorTempHighFault1_IPU_MotorTempHighFault1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorTempSensorErr_IPU_MotorTempSensorErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorUCurrSensorFlt_IPU_MotorUCurrSensorFlt;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_Motor_Phase_Curr_IPU_Motor_Phase_Curr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_PCOCHW_Fault_IPU_PCOCHW_Fault;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_PCOCSW_Fault_IPU_PCOCSW_Fault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_PreventSlipFlag_IPU_PreventSlipFlag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_RotateInverterFlt_IPU_RotateInverterFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_SelfChkSts_IPU_SelfChkSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_SoftwareCapOverVolt_IPU_SoftwareCapOverVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_Sts_Checksum_IPU_Sts_Checksum;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_TqAvlIsgMaxInvalid_IPU_TqAvlIsgMaxInvalid;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_TqAvlIsgMinInvalid_IPU_TqAvlIsgMinInvalid;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_TrqSpd_CheckSum_IPU_TrqSpd_CheckSum;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq;
extern VAR(Float, RTE_VAR_INIT) Rte_TempDev_TempDev_tPhySic_TempDev_tPhySic;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_AntiRollBack_bAntiRollActv_AntiRollBack_bAntiRollActv(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_BIfRx_stPWM_BIfRx_stPWM(P2VAR(UInt8, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_DernCoorn_tqEmMax_DernCoorn_tqEmMax(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_DernCoorn_tqEmMin_DernCoorn_tqEmMin(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bActvDchrgTioutFlt_Diag_bActvDchrgTioutFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bBmsNodMissFlt_Diag_bBmsNodMissFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bBusOverVoltAlrm_Diag_bBusOverVoltAlrm(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bBusOverVoltFlt_Diag_bBusOverVoltFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bBusUnderVoltAlrm_Diag_bBusUnderVoltAlrm(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bE2EChksFlt_Diag_bE2EChksFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bHwBusOffFlt_Diag_bHwBusOffFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bHwOverCurrFlt_Diag_bHwOverCurrFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bHwOverVoltFlt_Diag_bHwOverVoltFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bIGBTDrvFlt_Diag_bIGBTDrvFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bLvVoltHiLimFlt_Diag_bLvVoltHiLimFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bLvVoltOverAlrm_Diag_bLvVoltOverAlrm(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bLvVoltUnderFlt_Diag_bLvVoltUnderFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bMcuStorgUnitFlt_Diag_bMcuStorgUnitFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bMcuTempSnsrShoCircGndFlt_Diag_bMcuTempSnsrShoCircGndFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bMcuTempSnsrShoCircPwrFlt_Diag_bMcuTempSnsrShoCircPwrFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bMotOverSpdFlt_Diag_bMotOverSpdFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bMotStalFlt_Diag_bMotStalFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bMotStrOverTempAlrm_Diag_bMotStrOverTempAlrm(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bMotStrOverTempFlt_Diag_bMotStrOverTempFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bMotTempSnsrShoCircGndFlt_Diag_bMotTempSnsrShoCircGndFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bMotTempSnsrShoCircPwrFlt_Diag_bMotTempSnsrShoCircPwrFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bPhaCurrOverFlt_Diag_bPhaCurrOverFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bPhaCurrUShoCircGndFlt_Diag_bPhaCurrUShoCircGndFlt(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bPhaCurrUShoCircPwrFlt_Diag_bPhaCurrUShoCircPwrFlt(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bPhaCurrVShoCircGndFlt_Diag_bPhaCurrVShoCircGndFlt(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bPhaCurrVShoCircPwrFlt_Diag_bPhaCurrVShoCircPwrFlt(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bPhaCurrWShoCircGndFlt_Diag_bPhaCurrWShoCircGndFlt(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bPhaCurrWShoCircPwrFlt_Diag_bPhaCurrWShoCircPwrFlt(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bRotyTrfrFlt_Diag_bRotyTrfrFlt(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bSicOverTempAlrm_Diag_bSicOverTempAlrm(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bSicOverTempFlt_Diag_bSicOverTempFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_bVcuNodMissFlt_Diag_bVcuNodMissFlt(P2VAR(Boolean, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_noDTCNr_Diag_noDTCNr(P2VAR(UInt8, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_stMcuFltLvl_Diag_stMcuFltLvl(P2VAR(UInt8, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_Diag_stMcuSubFltLvl_Diag_stMcuSubFltLvl(P2VAR(UInt8, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_EmPwr_iDCLnkFiltd_EmPwr_iDCLnkFiltd(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_AWB_IPU_AWB(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_Address_IPU_Address(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgHeatFdBck_IPU_IsgHeatFdBck(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgHeatPwrAct_IPU_IsgHeatPwrAct(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgHeatPwrMax_IPU_IsgHeatPwrMax(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MaxCurrt_IPU_MaxCurrt(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MaxTrq_IPU_MaxTrq(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_NMSts_IPU_NMSts(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_RMR_IPU_RMR(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_RatedVoltg_IPU_RatedVoltg(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_Stayawake_reasons_IPU_Stayawake_reasons(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_Wakeup_reasons_IPU_Wakeup_reasons(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta(P2VAR(UInt8, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_MMC_MCUWorkMode_sta_MMC_MCUWorkMode_sta(P2VAR(UInt8, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_TempDev_tPhyMotFild_TempDev_tPhyMotFild(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComTx_CAN_TempDev_tPhySic_TempDev_tPhySic(P2VAR(Float, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_ActiveDischgFlt_IPU_ActiveDischgFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_BattFaultLampState_IPU_BattFaultLampState(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_BusUndervolt_IPU_BusUndervolt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_CANCommFlt_IPU_CANCommFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_DTC_IPU_DTC(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_DischgState_IPU_DischgState(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_HVBusCur_IPU_HVBusCur(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_HVBusVolt_20_IPU_HVBusVolt_20(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_HVBusVolt_500_IPU_HVBusVolt_500(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_HardwareCapOverVolt_IPU_HardwareCapOverVolt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IGBTFlt_IPU_IGBTFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgInvrT_IPU_IsgInvrT(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgInvrTInvalid_IPU_IsgInvrTInvalid(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgModSts_IPU_IsgModSts(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgModStsInvalid_IPU_IsgModStsInvalid(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgMotT_IPU_IsgMotT(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgMotTInvalid_IPU_IsgMotTInvalid(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgOverTemp_IPU_IsgOverTemp(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_IsgTqActIsgTqActInvalid_IPU_IsgTqActIsgTqActInvalid(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_LV_VotagtFault_IPU_LV_VotagtFault(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MCUMemoryFlt_IPU_MCUMemoryFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MCUTempHighAlarm_IPU_MCUTempHighAlarm(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MCUTempHighFault_IPU_MCUTempHighFault(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MCUTempSensorErr_IPU_MCUTempSensorErr(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorFltLevell1_IPU_MotorFltLevell1(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorFltLevell_Invalid_IPU_MotorFltLevell_Invalid(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorLockRotErr_IPU_MotorLockRotErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorNum_IPU_MotorNum(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorNumSN_IPU_MotorNumSN(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorSpdHighAlarm_IPU_MotorSpdHighAlarm(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorSts_IPU_MotorSts(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorTempHighAlarm_IPU_MotorTempHighAlarm(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorTempHighFault_IPU_MotorTempHighFault(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorTempHighFault1_IPU_MotorTempHighFault1(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorTempSensorErr_IPU_MotorTempSensorErr(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_MotorUCurrSensorFlt_IPU_MotorUCurrSensorFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_Motor_Phase_Curr_IPU_Motor_Phase_Curr(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_PCOCHW_Fault_IPU_PCOCHW_Fault(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_PCOCSW_Fault_IPU_PCOCSW_Fault(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_PreventSlipFlag_IPU_PreventSlipFlag(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_RotateInverterFlt_IPU_RotateInverterFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_SelfChkSts_IPU_SelfChkSts(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_SoftwareCapOverVolt_IPU_SoftwareCapOverVolt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_Sts_Checksum_IPU_Sts_Checksum(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_TqAvlIsgMaxInvalid_IPU_TqAvlIsgMaxInvalid(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_TqAvlIsgMinInvalid_IPU_TqAvlIsgMinInvalid(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComTx_CAN_IPU_TrqSpd_CheckSum_IPU_TrqSpd_CheckSum(UInt8 data);
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
#define Rte_Read_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd Rte_Read_ComTx_CAN_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd
#define Rte_Read_AntiRollBack_bAntiRollActv_AntiRollBack_bAntiRollActv Rte_Read_ComTx_CAN_AntiRollBack_bAntiRollActv_AntiRollBack_bAntiRollActv
#define Rte_Read_BIfRx_stPWM_BIfRx_stPWM Rte_Read_ComTx_CAN_BIfRx_stPWM_BIfRx_stPWM
#define Rte_Read_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq Rte_Read_ComTx_CAN_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq
#define Rte_Read_DernCoorn_tqEmMax_DernCoorn_tqEmMax Rte_Read_ComTx_CAN_DernCoorn_tqEmMax_DernCoorn_tqEmMax
#define Rte_Read_DernCoorn_tqEmMin_DernCoorn_tqEmMin Rte_Read_ComTx_CAN_DernCoorn_tqEmMin_DernCoorn_tqEmMin
#define Rte_Read_Diag_bActvDchrgTioutFlt_Diag_bActvDchrgTioutFlt Rte_Read_ComTx_CAN_Diag_bActvDchrgTioutFlt_Diag_bActvDchrgTioutFlt
#define Rte_Read_Diag_bBmsNodMissFlt_Diag_bBmsNodMissFlt Rte_Read_ComTx_CAN_Diag_bBmsNodMissFlt_Diag_bBmsNodMissFlt
#define Rte_Read_Diag_bBusOverVoltAlrm_Diag_bBusOverVoltAlrm Rte_Read_ComTx_CAN_Diag_bBusOverVoltAlrm_Diag_bBusOverVoltAlrm
#define Rte_Read_Diag_bBusOverVoltFlt_Diag_bBusOverVoltFlt Rte_Read_ComTx_CAN_Diag_bBusOverVoltFlt_Diag_bBusOverVoltFlt
#define Rte_Read_Diag_bBusUnderVoltAlrm_Diag_bBusUnderVoltAlrm Rte_Read_ComTx_CAN_Diag_bBusUnderVoltAlrm_Diag_bBusUnderVoltAlrm
#define Rte_Read_Diag_bE2EChksFlt_Diag_bE2EChksFlt Rte_Read_ComTx_CAN_Diag_bE2EChksFlt_Diag_bE2EChksFlt
#define Rte_Read_Diag_bHwBusOffFlt_Diag_bHwBusOffFlt Rte_Read_ComTx_CAN_Diag_bHwBusOffFlt_Diag_bHwBusOffFlt
#define Rte_Read_Diag_bHwOverCurrFlt_Diag_bHwOverCurrFlt Rte_Read_ComTx_CAN_Diag_bHwOverCurrFlt_Diag_bHwOverCurrFlt
#define Rte_Read_Diag_bHwOverVoltFlt_Diag_bHwOverVoltFlt Rte_Read_ComTx_CAN_Diag_bHwOverVoltFlt_Diag_bHwOverVoltFlt
#define Rte_Read_Diag_bIGBTDrvFlt_Diag_bIGBTDrvFlt Rte_Read_ComTx_CAN_Diag_bIGBTDrvFlt_Diag_bIGBTDrvFlt
#define Rte_Read_Diag_bLvVoltHiLimFlt_Diag_bLvVoltHiLimFlt Rte_Read_ComTx_CAN_Diag_bLvVoltHiLimFlt_Diag_bLvVoltHiLimFlt
#define Rte_Read_Diag_bLvVoltOverAlrm_Diag_bLvVoltOverAlrm Rte_Read_ComTx_CAN_Diag_bLvVoltOverAlrm_Diag_bLvVoltOverAlrm
#define Rte_Read_Diag_bLvVoltUnderFlt_Diag_bLvVoltUnderFlt Rte_Read_ComTx_CAN_Diag_bLvVoltUnderFlt_Diag_bLvVoltUnderFlt
#define Rte_Read_Diag_bMcuStorgUnitFlt_Diag_bMcuStorgUnitFlt Rte_Read_ComTx_CAN_Diag_bMcuStorgUnitFlt_Diag_bMcuStorgUnitFlt
#define Rte_Read_Diag_bMcuTempSnsrShoCircGndFlt_Diag_bMcuTempSnsrShoCircGndFlt Rte_Read_ComTx_CAN_Diag_bMcuTempSnsrShoCircGndFlt_Diag_bMcuTempSnsrShoCircGndFlt
#define Rte_Read_Diag_bMcuTempSnsrShoCircPwrFlt_Diag_bMcuTempSnsrShoCircPwrFlt Rte_Read_ComTx_CAN_Diag_bMcuTempSnsrShoCircPwrFlt_Diag_bMcuTempSnsrShoCircPwrFlt
#define Rte_Read_Diag_bMotOverSpdFlt_Diag_bMotOverSpdFlt Rte_Read_ComTx_CAN_Diag_bMotOverSpdFlt_Diag_bMotOverSpdFlt
#define Rte_Read_Diag_bMotStalFlt_Diag_bMotStalFlt Rte_Read_ComTx_CAN_Diag_bMotStalFlt_Diag_bMotStalFlt
#define Rte_Read_Diag_bMotStrOverTempAlrm_Diag_bMotStrOverTempAlrm Rte_Read_ComTx_CAN_Diag_bMotStrOverTempAlrm_Diag_bMotStrOverTempAlrm
#define Rte_Read_Diag_bMotStrOverTempFlt_Diag_bMotStrOverTempFlt Rte_Read_ComTx_CAN_Diag_bMotStrOverTempFlt_Diag_bMotStrOverTempFlt
#define Rte_Read_Diag_bMotTempSnsrShoCircGndFlt_Diag_bMotTempSnsrShoCircGndFlt Rte_Read_ComTx_CAN_Diag_bMotTempSnsrShoCircGndFlt_Diag_bMotTempSnsrShoCircGndFlt
#define Rte_Read_Diag_bMotTempSnsrShoCircPwrFlt_Diag_bMotTempSnsrShoCircPwrFlt Rte_Read_ComTx_CAN_Diag_bMotTempSnsrShoCircPwrFlt_Diag_bMotTempSnsrShoCircPwrFlt
#define Rte_Read_Diag_bPhaCurrOverFlt_Diag_bPhaCurrOverFlt Rte_Read_ComTx_CAN_Diag_bPhaCurrOverFlt_Diag_bPhaCurrOverFlt
#define Rte_Read_Diag_bPhaCurrUShoCircGndFlt_Diag_bPhaCurrUShoCircGndFlt Rte_Read_ComTx_CAN_Diag_bPhaCurrUShoCircGndFlt_Diag_bPhaCurrUShoCircGndFlt
#define Rte_Read_Diag_bPhaCurrUShoCircPwrFlt_Diag_bPhaCurrUShoCircPwrFlt Rte_Read_ComTx_CAN_Diag_bPhaCurrUShoCircPwrFlt_Diag_bPhaCurrUShoCircPwrFlt
#define Rte_Read_Diag_bPhaCurrVShoCircGndFlt_Diag_bPhaCurrVShoCircGndFlt Rte_Read_ComTx_CAN_Diag_bPhaCurrVShoCircGndFlt_Diag_bPhaCurrVShoCircGndFlt
#define Rte_Read_Diag_bPhaCurrVShoCircPwrFlt_Diag_bPhaCurrVShoCircPwrFlt Rte_Read_ComTx_CAN_Diag_bPhaCurrVShoCircPwrFlt_Diag_bPhaCurrVShoCircPwrFlt
#define Rte_Read_Diag_bPhaCurrWShoCircGndFlt_Diag_bPhaCurrWShoCircGndFlt Rte_Read_ComTx_CAN_Diag_bPhaCurrWShoCircGndFlt_Diag_bPhaCurrWShoCircGndFlt
#define Rte_Read_Diag_bPhaCurrWShoCircPwrFlt_Diag_bPhaCurrWShoCircPwrFlt Rte_Read_ComTx_CAN_Diag_bPhaCurrWShoCircPwrFlt_Diag_bPhaCurrWShoCircPwrFlt
#define Rte_Read_Diag_bRotyTrfrFlt_Diag_bRotyTrfrFlt Rte_Read_ComTx_CAN_Diag_bRotyTrfrFlt_Diag_bRotyTrfrFlt
#define Rte_Read_Diag_bSicOverTempAlrm_Diag_bSicOverTempAlrm Rte_Read_ComTx_CAN_Diag_bSicOverTempAlrm_Diag_bSicOverTempAlrm
#define Rte_Read_Diag_bSicOverTempFlt_Diag_bSicOverTempFlt Rte_Read_ComTx_CAN_Diag_bSicOverTempFlt_Diag_bSicOverTempFlt
#define Rte_Read_Diag_bVcuNodMissFlt_Diag_bVcuNodMissFlt Rte_Read_ComTx_CAN_Diag_bVcuNodMissFlt_Diag_bVcuNodMissFlt
#define Rte_Read_Diag_noDTCNr_Diag_noDTCNr Rte_Read_ComTx_CAN_Diag_noDTCNr_Diag_noDTCNr
#define Rte_Read_Diag_stMcuFltLvl_Diag_stMcuFltLvl Rte_Read_ComTx_CAN_Diag_stMcuFltLvl_Diag_stMcuFltLvl
#define Rte_Read_Diag_stMcuSubFltLvl_Diag_stMcuSubFltLvl Rte_Read_ComTx_CAN_Diag_stMcuSubFltLvl_Diag_stMcuSubFltLvl
#define Rte_Read_EmPwr_iDCLnkFiltd_EmPwr_iDCLnkFiltd Rte_Read_ComTx_CAN_EmPwr_iDCLnkFiltd_EmPwr_iDCLnkFiltd
#define Rte_Read_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd Rte_Read_ComTx_CAN_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd
#define Rte_Read_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd Rte_Read_ComTx_CAN_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd
#define Rte_Read_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta Rte_Read_ComTx_CAN_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta
#define Rte_Read_MMC_MCUWorkMode_sta_MMC_MCUWorkMode_sta Rte_Read_ComTx_CAN_MMC_MCUWorkMode_sta_MMC_MCUWorkMode_sta
#define Rte_Read_TempDev_tPhyMotFild_TempDev_tPhyMotFild Rte_Read_ComTx_CAN_TempDev_tPhyMotFild_TempDev_tPhyMotFild
#define Rte_Read_TempDev_tPhySic_TempDev_tPhySic Rte_Read_ComTx_CAN_TempDev_tPhySic_TempDev_tPhySic
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
#define Rte_Write_IPU_AWB_IPU_AWB Rte_Write_ComTx_CAN_IPU_AWB_IPU_AWB
#define Rte_Write_IPU_ActiveDischgFlt_IPU_ActiveDischgFlt Rte_Write_ComTx_CAN_IPU_ActiveDischgFlt_IPU_ActiveDischgFlt
#define Rte_Write_IPU_Address_IPU_Address Rte_Write_ComTx_CAN_IPU_Address_IPU_Address
#define Rte_Write_IPU_BattFaultLampState_IPU_BattFaultLampState Rte_Write_ComTx_CAN_IPU_BattFaultLampState_IPU_BattFaultLampState
#define Rte_Write_IPU_BusUndervolt_IPU_BusUndervolt Rte_Write_ComTx_CAN_IPU_BusUndervolt_IPU_BusUndervolt
#define Rte_Write_IPU_CANCommFlt_IPU_CANCommFlt Rte_Write_ComTx_CAN_IPU_CANCommFlt_IPU_CANCommFlt
#define Rte_Write_IPU_DTC_IPU_DTC Rte_Write_ComTx_CAN_IPU_DTC_IPU_DTC
#define Rte_Write_IPU_DischgState_IPU_DischgState Rte_Write_ComTx_CAN_IPU_DischgState_IPU_DischgState
#define Rte_Write_IPU_HVBusCur_IPU_HVBusCur Rte_Write_ComTx_CAN_IPU_HVBusCur_IPU_HVBusCur
#define Rte_Write_IPU_HVBusVolt_20_IPU_HVBusVolt_20 Rte_Write_ComTx_CAN_IPU_HVBusVolt_20_IPU_HVBusVolt_20
#define Rte_Write_IPU_HVBusVolt_500_IPU_HVBusVolt_500 Rte_Write_ComTx_CAN_IPU_HVBusVolt_500_IPU_HVBusVolt_500
#define Rte_Write_IPU_HardwareCapOverVolt_IPU_HardwareCapOverVolt Rte_Write_ComTx_CAN_IPU_HardwareCapOverVolt_IPU_HardwareCapOverVolt
#define Rte_Write_IPU_IGBTFlt_IPU_IGBTFlt Rte_Write_ComTx_CAN_IPU_IGBTFlt_IPU_IGBTFlt
#define Rte_Write_IPU_IsgHeatFdBck_IPU_IsgHeatFdBck Rte_Write_ComTx_CAN_IPU_IsgHeatFdBck_IPU_IsgHeatFdBck
#define Rte_Write_IPU_IsgHeatPwrAct_IPU_IsgHeatPwrAct Rte_Write_ComTx_CAN_IPU_IsgHeatPwrAct_IPU_IsgHeatPwrAct
#define Rte_Write_IPU_IsgHeatPwrMax_IPU_IsgHeatPwrMax Rte_Write_ComTx_CAN_IPU_IsgHeatPwrMax_IPU_IsgHeatPwrMax
#define Rte_Write_IPU_IsgInvrT_IPU_IsgInvrT Rte_Write_ComTx_CAN_IPU_IsgInvrT_IPU_IsgInvrT
#define Rte_Write_IPU_IsgInvrTInvalid_IPU_IsgInvrTInvalid Rte_Write_ComTx_CAN_IPU_IsgInvrTInvalid_IPU_IsgInvrTInvalid
#define Rte_Write_IPU_IsgModSts_IPU_IsgModSts Rte_Write_ComTx_CAN_IPU_IsgModSts_IPU_IsgModSts
#define Rte_Write_IPU_IsgModStsInvalid_IPU_IsgModStsInvalid Rte_Write_ComTx_CAN_IPU_IsgModStsInvalid_IPU_IsgModStsInvalid
#define Rte_Write_IPU_IsgMotT_IPU_IsgMotT Rte_Write_ComTx_CAN_IPU_IsgMotT_IPU_IsgMotT
#define Rte_Write_IPU_IsgMotTInvalid_IPU_IsgMotTInvalid Rte_Write_ComTx_CAN_IPU_IsgMotTInvalid_IPU_IsgMotTInvalid
#define Rte_Write_IPU_IsgOverTemp_IPU_IsgOverTemp Rte_Write_ComTx_CAN_IPU_IsgOverTemp_IPU_IsgOverTemp
#define Rte_Write_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn Rte_Write_ComTx_CAN_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn
#define Rte_Write_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid Rte_Write_ComTx_CAN_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid
#define Rte_Write_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct Rte_Write_ComTx_CAN_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct
#define Rte_Write_IPU_IsgTqActIsgTqActInvalid_IPU_IsgTqActIsgTqActInvalid Rte_Write_ComTx_CAN_IPU_IsgTqActIsgTqActInvalid_IPU_IsgTqActIsgTqActInvalid
#define Rte_Write_IPU_LV_VotagtFault_IPU_LV_VotagtFault Rte_Write_ComTx_CAN_IPU_LV_VotagtFault_IPU_LV_VotagtFault
#define Rte_Write_IPU_MCUMemoryFlt_IPU_MCUMemoryFlt Rte_Write_ComTx_CAN_IPU_MCUMemoryFlt_IPU_MCUMemoryFlt
#define Rte_Write_IPU_MCUTempHighAlarm_IPU_MCUTempHighAlarm Rte_Write_ComTx_CAN_IPU_MCUTempHighAlarm_IPU_MCUTempHighAlarm
#define Rte_Write_IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1 Rte_Write_ComTx_CAN_IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1
#define Rte_Write_IPU_MCUTempHighFault_IPU_MCUTempHighFault Rte_Write_ComTx_CAN_IPU_MCUTempHighFault_IPU_MCUTempHighFault
#define Rte_Write_IPU_MCUTempSensorErr_IPU_MCUTempSensorErr Rte_Write_ComTx_CAN_IPU_MCUTempSensorErr_IPU_MCUTempSensorErr
#define Rte_Write_IPU_MaxCurrt_IPU_MaxCurrt Rte_Write_ComTx_CAN_IPU_MaxCurrt_IPU_MaxCurrt
#define Rte_Write_IPU_MaxTrq_IPU_MaxTrq Rte_Write_ComTx_CAN_IPU_MaxTrq_IPU_MaxTrq
#define Rte_Write_IPU_MotorFltLevell1_IPU_MotorFltLevell1 Rte_Write_ComTx_CAN_IPU_MotorFltLevell1_IPU_MotorFltLevell1
#define Rte_Write_IPU_MotorFltLevell_Invalid_IPU_MotorFltLevell_Invalid Rte_Write_ComTx_CAN_IPU_MotorFltLevell_Invalid_IPU_MotorFltLevell_Invalid
#define Rte_Write_IPU_MotorLockRotErr_IPU_MotorLockRotErr Rte_Write_ComTx_CAN_IPU_MotorLockRotErr_IPU_MotorLockRotErr
#define Rte_Write_IPU_MotorNum_IPU_MotorNum Rte_Write_ComTx_CAN_IPU_MotorNum_IPU_MotorNum
#define Rte_Write_IPU_MotorNumSN_IPU_MotorNumSN Rte_Write_ComTx_CAN_IPU_MotorNumSN_IPU_MotorNumSN
#define Rte_Write_IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt Rte_Write_ComTx_CAN_IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt
#define Rte_Write_IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt Rte_Write_ComTx_CAN_IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt
#define Rte_Write_IPU_MotorSpdHighAlarm_IPU_MotorSpdHighAlarm Rte_Write_ComTx_CAN_IPU_MotorSpdHighAlarm_IPU_MotorSpdHighAlarm
#define Rte_Write_IPU_MotorSts_IPU_MotorSts Rte_Write_ComTx_CAN_IPU_MotorSts_IPU_MotorSts
#define Rte_Write_IPU_MotorTempHighAlarm_IPU_MotorTempHighAlarm Rte_Write_ComTx_CAN_IPU_MotorTempHighAlarm_IPU_MotorTempHighAlarm
#define Rte_Write_IPU_MotorTempHighFault_IPU_MotorTempHighFault Rte_Write_ComTx_CAN_IPU_MotorTempHighFault_IPU_MotorTempHighFault
#define Rte_Write_IPU_MotorTempHighFault1_IPU_MotorTempHighFault1 Rte_Write_ComTx_CAN_IPU_MotorTempHighFault1_IPU_MotorTempHighFault1
#define Rte_Write_IPU_MotorTempSensorErr_IPU_MotorTempSensorErr Rte_Write_ComTx_CAN_IPU_MotorTempSensorErr_IPU_MotorTempSensorErr
#define Rte_Write_IPU_MotorUCurrSensorFlt_IPU_MotorUCurrSensorFlt Rte_Write_ComTx_CAN_IPU_MotorUCurrSensorFlt_IPU_MotorUCurrSensorFlt
#define Rte_Write_IPU_Motor_Phase_Curr_IPU_Motor_Phase_Curr Rte_Write_ComTx_CAN_IPU_Motor_Phase_Curr_IPU_Motor_Phase_Curr
#define Rte_Write_IPU_NMSts_IPU_NMSts Rte_Write_ComTx_CAN_IPU_NMSts_IPU_NMSts
#define Rte_Write_IPU_PCOCHW_Fault_IPU_PCOCHW_Fault Rte_Write_ComTx_CAN_IPU_PCOCHW_Fault_IPU_PCOCHW_Fault
#define Rte_Write_IPU_PCOCSW_Fault_IPU_PCOCSW_Fault Rte_Write_ComTx_CAN_IPU_PCOCSW_Fault_IPU_PCOCSW_Fault
#define Rte_Write_IPU_PreventSlipFlag_IPU_PreventSlipFlag Rte_Write_ComTx_CAN_IPU_PreventSlipFlag_IPU_PreventSlipFlag
#define Rte_Write_IPU_RMR_IPU_RMR Rte_Write_ComTx_CAN_IPU_RMR_IPU_RMR
#define Rte_Write_IPU_RatedVoltg_IPU_RatedVoltg Rte_Write_ComTx_CAN_IPU_RatedVoltg_IPU_RatedVoltg
#define Rte_Write_IPU_RotateInverterFlt_IPU_RotateInverterFlt Rte_Write_ComTx_CAN_IPU_RotateInverterFlt_IPU_RotateInverterFlt
#define Rte_Write_IPU_SelfChkSts_IPU_SelfChkSts Rte_Write_ComTx_CAN_IPU_SelfChkSts_IPU_SelfChkSts
#define Rte_Write_IPU_SoftwareCapOverVolt_IPU_SoftwareCapOverVolt Rte_Write_ComTx_CAN_IPU_SoftwareCapOverVolt_IPU_SoftwareCapOverVolt
#define Rte_Write_IPU_Stayawake_reasons_IPU_Stayawake_reasons Rte_Write_ComTx_CAN_IPU_Stayawake_reasons_IPU_Stayawake_reasons
#define Rte_Write_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter Rte_Write_ComTx_CAN_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter
#define Rte_Write_IPU_Sts_Checksum_IPU_Sts_Checksum Rte_Write_ComTx_CAN_IPU_Sts_Checksum_IPU_Sts_Checksum
#define Rte_Write_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax Rte_Write_ComTx_CAN_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax
#define Rte_Write_IPU_TqAvlIsgMaxInvalid_IPU_TqAvlIsgMaxInvalid Rte_Write_ComTx_CAN_IPU_TqAvlIsgMaxInvalid_IPU_TqAvlIsgMaxInvalid
#define Rte_Write_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin Rte_Write_ComTx_CAN_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin
#define Rte_Write_IPU_TqAvlIsgMinInvalid_IPU_TqAvlIsgMinInvalid Rte_Write_ComTx_CAN_IPU_TqAvlIsgMinInvalid_IPU_TqAvlIsgMinInvalid
#define Rte_Write_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter Rte_Write_ComTx_CAN_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter
#define Rte_Write_IPU_TrqSpd_CheckSum_IPU_TrqSpd_CheckSum Rte_Write_ComTx_CAN_IPU_TrqSpd_CheckSum_IPU_TrqSpd_CheckSum
#define Rte_Write_IPU_Wakeup_reasons_IPU_Wakeup_reasons Rte_Write_ComTx_CAN_IPU_Wakeup_reasons_IPU_Wakeup_reasons
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
FUNC(void, ComTx_CAN_CODE) ComTx_Init(void);
FUNC(void, ComTx_CAN_CODE) fc_ComTx100ms(void);
FUNC(void, ComTx_CAN_CODE) fc_ComTx10ms(void);
FUNC(void, ComTx_CAN_CODE) fc_ComTx20ms(void);
FUNC(void, ComTx_CAN_CODE) fc_ComTx500ms(void);
FUNC(void, ComTx_CAN_CODE) fc_ComTxEvent(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Operation Invocation Runnable entities
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
#define Rte_Call_SWC_Ver_DataServices_0xF1A4_22_RE_SWC_Ver_DataServices_0xF1A4_22_RE Rte_Call_ComTx_CAN_SWC_Ver_DataServices_0xF1A4_22_RE_SWC_Ver_DataServices_0xF1A4_22_RE
#define Rte_Call_ComTx_CAN_SWC_Ver_DataServices_0xF1A4_22_RE_SWC_Ver_DataServices_0xF1A4_22_RE(arg1, arg2, arg3, arg4) (SWC_Ver_DataServices_0xF1A4_22_RE(arg1, arg2, arg3, arg4), ((Std_ReturnType)RTE_E_OK))
FUNC(void, ComTx_CAN_CODE) SWC_Ver_DataServices_0xF1A4_22_RE(P2VAR(uint8, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) Data, P2VAR(UInt8, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) ERR, P2VAR(UInt8, AUTOMATIC, RTE_ComTx_CAN_APPL_DATA) NegCode, VAR(UInt8, RTE_ComTx_CAN_APPL_DATA) Op);
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
#endif /* RTE_COMTX_CAN_H_ */
 
 
 

 
/*
************************************************************************************************************************
*
* File name: Rte_swc_VCIP.h
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
#ifndef RTE_SWC_VCIP_H_
#define RTE_SWC_VCIP_H_

#include "Rte_swc_VCIP_Type.h"
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

#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_b_acHvilOpn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_b_acHvilOpnInvld;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_e_PtcSt;
extern VAR(FaultStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_e_acFltLvl;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_e_airCmprSt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_n_acFanReqSpd_pct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_AcWrk;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_acSubFltSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_airCmprSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_cbnThermMngReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_iptWorkSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_ptcWorkStRear;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_t_ambTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_u_acPresVolt_V;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_b_accPedlPosVld;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_u_accPedlPosSens1VoltRaw_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_u_accPedlPosSens2VoltRaw_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosCan_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosLimd_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosSens1_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosSens2_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPos_pct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_b_adc1CtrlTorqEn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_b_adc1SwtchCtrlReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_b_adcCtrlGearEn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_b_adcCtrlTorqEn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_st_adcTgtGearPostn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_st_pmsAdcCtrldSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_st_pmsCanBusRecSta;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_tq_adc1TgtDrvTorq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_tq_adcTgtDrvTorq_Nm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_DryAirSwitch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_ResrAirSwitch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brakeSwitch1Closed;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brakeSwitch2Closed;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPedlPosVld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPedlStsVld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPmpSelfChkErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPmpSelfChkOk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPressedFromSwitch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPumpFault;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_vacTankLowPrs;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_e_bdcacWrk;
extern VAR(BrakePedalStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_e_brkPedalStatus;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_p_AirPres_kpa;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_p_brkVacuumPres_bar;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_st_bdcacWrk;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_x_brkPedlPos_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_ccdd_u_cruiseADvoltage_V;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_cesd_b_EmergencyStop;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_cesd_b_acuCrash;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_cesd_b_crash;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcCutOffLvFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcHvilFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcHvilFltInvld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcSelfChkErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcSelfChkOk;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_e_24vDcdcModAct;
extern VAR(FaultStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_e_dcdcFaultStatus;
extern VAR(DCDCMode, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_e_modeAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_pwr_dcdcHVpwr_kW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_st_12vDcdcModAct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_st_24vDcdcFltSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_st_24vDcdcModAct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_st_24vDcdcSubFltSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_t_dcdcTemp_C;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReq4WD;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqECO;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqEV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqHEV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqSPORT;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_parkBtnPressed;
extern VAR(GearLeverPos, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_e_gearLvrPosRaw;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_st_gearLvrPosSeql;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2ActvDischCmplt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2RdyToCutOffLV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2SelfChkErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2SelfChkOk;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_e_eadInv2Sts;
extern VAR(FaultStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_e_inv21FltSts;
extern VAR(FaultStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_e_inv2FltSts;
extern VAR(ElMac, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_e_inv2ModeAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_fact_mot2GearRat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_pwr_mot21ActPwr_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_pwr_mot2ActPwr_kW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_st_eadInv2PwrActvMod;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_st_eadInv2Sts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_st_eadInv2WrkMod;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_st_eadMot2ImmoRlsChk;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_st_inv2SubFltSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_t_inv2Temp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_t_mot2Temp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2ActTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailLTBrk_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailLTBst_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailSTBrk_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailSTBst_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_u_busInv2HVAct_V;
extern VAR(ParkingStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_epbd_e_parkingSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_bmsSelfChkErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_bmsSelfChkOk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmCutOffLvFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmPtcDefRlyCls;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmRlyWldFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmSelfChkErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmSelfChkOk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbChPwrLimdByTemp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbDischPwrLimdByTemp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbHeatEnad;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbPrmtCutOffLvFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvilOpen;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_lowTempProtnReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_obcChrgReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_dcdcMainRlySts;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_eadInv2MainRlySts;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hcmMaiRlyNeg;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hcmWrkSt;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbAssiRly;
extern VAR(FaultStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbFaultStatus;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMaiRlyNeg;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMaiRlyPos;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMainRlySts;
extern VAR(HVBattStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbStatus;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_fact_hvbSOH_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_i_hvbCurr_A;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_PeakChMax_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_PeakDischMax_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_StatChMax_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_StatDischMax_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_hvbActRaw_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_hvbAct_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_hvbChgPwr_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_q_hvbSOC_pct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hcmFltLvl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hcmMaiRlyNeg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hcmPwrActvMod;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvbPwrActvMod;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvbSubFaultSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvbThermMngReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvilOpenSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_tboxIntelChgQuit;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbAvg_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbInCoolTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbMin_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_V_tankFuelLvl_l;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_b_epsSelfChkErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_b_epsSelfChkOk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_b_pullUpDiagCmpl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_b_vcuSelfChkOk;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_e_sdcacWrk;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_p_frontAirTankPres_bar;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_p_rearAirTankPres_bar;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_st_epsErrorCode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_st_epsFltLvl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_st_epsSubFltLvl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_st_sdcacWrk;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_t_ts5SnsrTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_u_batIntSmpl_V;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcCANMsgValid;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcChrgCablePlugged;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcChrgCableUnplugged;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcSelfChkErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcSelfChkOk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcWakeUp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_pwr_obcOutpt_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_pwr_obcRlTmOutpt_kW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_st_obcfltLvl;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_t_obcTemp_C;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_anyIgnOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_canIgnOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_driverStartReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_hwIgnOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignStsStrt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_pepsPduLvlValid;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ptCanNmStRdy;
extern VAR(KeyAuthStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_e_authenticationStatus;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_b_trsm2GearActVld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_b_trsm2GearshiftActv;
extern VAR(ParkingStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_e_trsm1PrkgSts;
extern VAR(GearShiftResp, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_e_trsm2GearShftResp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_fact_trsm2FinalDrvRat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_fact_trsm2GbxGearRat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_fact_trsm2GearRat;
extern VAR(SInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_st_trsm2GearAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_R_posInsIRes_Ohm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_a_yrsLongitAcce_mps2;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_ang_strWhlAng_rad;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_AccyEnReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_AccyFltSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_CCSginal;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_DryAirSwitch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ResrAirSwitch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_adc1ComErrFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_adcComErrFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_bcmFrntLftDrAjSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_bcmFrntRDrAjSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_brkSwt1Actv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_brkSwt2Actv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_calCanBusOff;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_cntnrCtrlEnaFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmCampModeSwt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmCampModeSwtInvld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmEngRecSwtReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmTakeEleSwt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmTakeEleSwtReqInvld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmV2XDchaSw;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmV2XDchaSwInvld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_dcdcStsAlm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_dcdcTempAlm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_disChgSwtSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_driverEcoModeReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ehbIsaPtTrqDecReqActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ehbVlcCddActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_emgyStopIn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_epbErrSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgBBMMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgACU;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgAccyButton;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgAirBag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgBatCol;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgChgTyp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgCoastActivBrkLight;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvMod;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvModConn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvModStor;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvSeat;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDualAuthN;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgEpdel;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgMaxChgCurr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgMotor;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgTyre;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFnctnConfgEGSM;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFnctnConfgEHB;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgNetConfgABS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvCcwFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvInitSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvMotSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvOvrCurrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvOvrTempFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvOvrVoltFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvRespErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvUndVoltFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hcmMainPosBckVoltVldSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hcmPtcRlyVoltVldSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbDCChgCurReqRngUp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbDisChgSopRngUp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbHvilFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbInPositionDetct1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbInPositionDetct2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbZeroPwrReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ignStsOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ignStsStrt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ipkOdoBckUpEn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvCcwFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvInitSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvMotSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvOvrCurrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvOvrTempFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvOvrVoltFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvRespErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvUndVoltFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_obcWakeUpActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_odometerInvalid;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_pepsOnSwtSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_pepsPduLvlVld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_pepsRmtCtrlSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ptCanBusOff;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_pullUpDiagCmpl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_rfrSwapBatReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_rstAvgPwrConsumption;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_tboxPowOffCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_tboxPrtFullSwStUB;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_d_bcmOdometerbackup;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_d_ipkOdometerbackup;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_d_odometer_km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_i_dcdcInpCurr_A;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_i_hvbCurr_A;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_i_hvbDCChgCurReq_A;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_l_whlRad_m;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbCellMaxID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbCellMinID;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbCellSum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbMaxTempID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbMinTempID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbTempSum;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_GearPosn;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_HVILReturnPWM;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP1FbPWM;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP2FbPWM;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP3FbPWM;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_fan1Fb;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_fan2Fb;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_fwfvCrtPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_mhgvCrtPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_mmiLocBkChgTarVal;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_tboxAlwChgCurrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_tboxChgDepth;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_PTCActPwr_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_acwpHeatPower_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_airCmprAct_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_iptActPwr_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_ptcActPwrRear_kW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_24vDcdcModAct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_BmsTempOutOfCtrlFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXFunAntiDismantleActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXFunLockVehActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockLimSet;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockResultResp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockVehCtrl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockVehType;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_actWorkSts1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_batLowSoc2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_batOvrSoc2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_batOvrVolt2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_batUdrVolt2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bbmFltSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bbmWorkSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsBattPackMatchFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsBattPackNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsBattSysNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsDlyDataUpldEnb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsTboxFireAlm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_cellOverVolt2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_cellUdrVolt2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_csmEngRecReqInvalid;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_csmRgnLvlSet;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_dcChgCcSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_dccAccyConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_eadInv2FltSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_eadInv2TempHiAlrm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_egsmShftLvrFailSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ehbBrkSysErrFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ehbIsaSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_epsEpasFail;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flg2FctCfgVehTyp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgAccy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgBatTyp;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgDspRemainRng;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgECOMaxSpd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgFan;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgMaxSpd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgMotTyp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgPowerMaxSpd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgSlowChg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgV2L;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehCfg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehTyp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehUsg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hcmAccConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hcmHvilSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hcmPTC1ConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hcmPtcDefRlyStFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbBatUniformity;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbBattIsolationSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbCellTempDevFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbCellVoltDevFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgCcsts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgFltReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgOvrCurr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgPlgNOvrTmp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgPlgPOvrTmp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgProcss;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDischgFltReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbInslErr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbOvrChgFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbPreChgSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbSocFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbSocJumpFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStatus;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStsChgFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStsDischgFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbTempFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbThermMngReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipkAlwChgSftCtlSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipkChgSftSwCtlSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipkCruisingDstSwt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipuInvTempHighAlm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipuMotTempHighFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipuMotorOverCurrFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipuMotorOverSpdFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_mmiRestSwitch;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcChgCCSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcChgSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcElckStMod;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcOnBdCCline;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcOnBdDchaCCline;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_pepsPduLvl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_pepsPduLvlVld;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_pepsRKECom;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ptcConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_rfrConnctSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_rfrSwapprocd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxChgLmtSw;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxChgSftSwCtlSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxInventorySpdLmtReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxLife;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxLockVehPerFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxPrtFullSwSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxRsrChgSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxSpdLmtLevelReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxStartBattChgReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxVersionConversionFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_vscEHBAVHSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_TS5sensorFb_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_acwpOutptTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbCooltInTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbCooltOutTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbMax_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbMin_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbOutCoolTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbSetTgtTemp_C;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_tm_hvbFnshChgTim_m;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_tq_ehbIsaPtTrqDecReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_5VT1IntSmpl_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_5VT2IntSmpl_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_Acc1Raw_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_Acc2Raw_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_BmsMaxCellVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_BmsMinCellVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_Brk2Raw_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_Brk2_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_BrkRaw_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_Brk_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_TS5sensorFb_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_VacTkAirPres_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_VacTkEnFb_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_accPdlSens1InpVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_accPdlSens2InpVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_batLpPmpCtrlFb_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_brkVacuumPres_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_cbnLpPmpCtrlFb_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_dcdcRelayVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_eLpWpCtrlCur_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hcmAcceRlyVolt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hcmMainPosBckVolt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hcmPtcRlyVolt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbCooltInSnsr_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbCooltOutSnsr_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbPackVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_ipuHVBusVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_pepsOn_mV;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_vacTkPowSup_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_v_ehbVehSpd_kph;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_a_vscLongitAcce_mps2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ESPActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ESPActvRaw;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbAbsOvrdActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbAebActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbDtcActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbTrqDecReqActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbTrqIncReqActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbVlcActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbVlcAvailb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbVlcTrqReqActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_pdcBrkFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSlipWarn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSpdVld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_vscBrkLghtActv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbAVHSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbEPBDynAppSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbHHCActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbMbRgnTgtWhlSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_st_vscIsgActvDampModReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_axle2MaxTqReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_axle2MinTqReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_axle2RgnBrkTqReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbMbRgnTgtWhl_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbTrqDecReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbTrqIncReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbVlcTrqReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpdRaw_kph;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_BattPackNum_EV_BMSH_BattPackNum_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_BattSysNum_EV_BMSH_BattSysNum_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_BattTempAvg_EV_BMSH_BattTempAvg_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatIsoAlarm2_EV_BMSH_TBOX_BatIsoAlarm2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatLowSOC2_EV_BMSH_TBOX_BatLowSOC2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverCharge2_EV_BMSH_TBOX_BatOverCharge2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverSOC2_EV_BMSH_TBOX_BatOverSOC2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverTemp2_EV_BMSH_TBOX_BatOverTemp2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverVoltage2_EV_BMSH_TBOX_BatOverVoltage2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatTempUniformity2_EV_BMSH_TBOX_BatTempUniformity2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUnderVoltage2_EV_BMSH_TBOX_BatUnderVoltage2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUniformity2_EV_BMSH_TBOX_BatUniformity2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellOverVoltage2_EV_BMSH_TBOX_CellOverVoltage2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellUnderVoltage2_EV_BMSH_TBOX_CellUnderVoltage2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_FireAlarm_EV_BMSH_TBOX_FireAlarm_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_SOCHop2_EV_BMSH_TBOX_SOCHop2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMS_DelayDataUpldEnb_EV_BMS_DelayDataUpldEnb_EV;
extern VAR(UInt32, RTE_VAR_INIT) Rte_PMS_BswAswRte_ECU_Fun_Config_Data1_ECU_Fun_Config_Data1;
extern VAR(UInt32, RTE_VAR_INIT) Rte_PMS_BswAswRte_ECU_Fun_Config_Data2_ECU_Fun_Config_Data2;
extern VAR(UInt32, RTE_VAR_INIT) Rte_PMS_BswAswRte_ECU_Net_Config_Data1_ECU_Net_Config_Data1;
extern VAR(UInt32, RTE_VAR_INIT) Rte_PMS_BswAswRte_ECU_Net_Config_Data2_ECU_Net_Config_Data2;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_BATTERY_TEMPH_5_EXT_AI_BATTERY_TEMPH_5;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_BATTERY_TEMPH_6_EXT_AI_BATTERY_TEMPH_6;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_MID_COOLING_TEMPH_8_EXT_AI_MID_COOLING_TEMPH_8;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_SENSOR_1_EXT_AI_SENSOR_1;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_SENSOR_2_EXT_AI_SENSOR_2;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_SENSOR_6_EXT_AI_SENSOR_6;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_SWITCH_1_EXT_AI_SWITCH_1;
extern VAR(UInt16, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AO_LDO_5V_02_EXT_AO_LDO_5V_02;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AO_TRACKING_5V_01_EXT_AO_TRACKING_5V_01;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AO_TRACKING_5V_02_EXT_AO_TRACKING_5V_02;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_CHARGE_ON_AI_EXT_CHARGE_ON_AI;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_DI_HS_04_EXT_DI_HS_04;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_DI_HS_05_EXT_DI_HS_05;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_DI_HS_06_EXT_DI_HS_06;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_DI_HS_07_EXT_DI_HS_07;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_DI_HS_08_EXT_DI_HS_08;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_DI_HS_10_EXT_DI_HS_10;
extern VAR(UInt16, RTE_VAR_INIT) Rte_PMS_HWI_EXT_IGN_ON_AI_EXT_IGN_ON_AI;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_IGN_ON_DI_EXT_IGN_ON_DI;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_HVIL_1_DutyCycle_EXT_PI_HVIL_1_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_HVIL_1_Period_EXT_PI_HVIL_1_Period;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_HVIL_2_DutyCycle_EXT_PI_HVIL_2_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_HVIL_2_Period_EXT_PI_HVIL_2_Period;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_PWM_1_DutyCycle_EXT_PI_PWM_1_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_PWM_2_DutyCycle_EXT_PI_PWM_2_DutyCycle;
extern VAR(UInt16, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_HVBusCur_EV_IPU_HVBusCur_EV;
extern VAR(UInt16, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_HVBusVolt_EV_IPU_HVBusVolt_EV;
extern VAR(UInt16, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_HVBusVolt_IPUSts_IPU_HVBusVolt_IPUSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_MCUTempHighAlarm1_EV_IPU_MCUTempHighAlarm1_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_MotorOverCurrFlt_EV_IPU_MotorOverCurrFlt_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_MotorOverSpdFlt_EV_IPU_MotorOverSpdFlt_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_MotorTempHighFault1_EV_IPU_MotorTempHighFault1_EV;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_KL30_KL30;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_PDCStatus_AlvCtrErrFlg_PDCStatus_AlvCtrErrFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_PDC_Status_CsmErrFlg_PDC_Status_CsmErrFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_s2vd_BMS_PmtCutoffLVFb_s2vd_BMS_PmtCutoffLVFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_acpd_b_accPed1Vld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_acpd_b_accPed2Vld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl32Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl33Flt_flg;
extern VAR(DCDCMode, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_dccd_e_modeTgt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_hvbIntelChgCmplt;
extern VAR(PmmStatus, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus;
extern VAR(GearLeverPos, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_gearLvrPos;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRun;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgBBMMsgErr_vild_b_flgBBMMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmd;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_ACCM1_ActPower_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_ACU_CrashOutputSts_ACU_ChimeTelltaleReq_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_ACCM_ActPower_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_AC_ACCM_Status_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_AmbientTemperature_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_AC_AmbientTemperatureInvalid_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_CabinThermalReq_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_CoolingFanPWMSpd_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_IPTC_ActPower_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_AC_IPTC_WorkSts_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_PTC_ActPower_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_PTC_ActPwr_Rear_AC_Status_Info1_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_AC_PTC_WorkSts_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_AC_PTC_WorkSts_Rear_AC_Status_Info1_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_BBM_FaultStatus_BBM_StsFB_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_BBM_WorkSts_BBM_StsFB_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_BCM_ATWS_St_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_BCM_DrvSeatbeltBuckleInvalid_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_BCM_DrvSeatbeltBucklestatus_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_BCM_FrontLeftDoorAjarStatus_BCM_LDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_BCM_FrontRightDoorAjarStatus_BCM_RDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_BCM_IntelligentChargeCommand_BCM_ACCinfor_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_BCM_Odometerbackup_BCM_SunroofState_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_CampModeSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_CampModeSwtInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_DriveModeReq_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_DriveModeReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_EngRec_Req_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_EngRec_ReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_TakeEleSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_TakeEleSwt_ReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_V2XDchaSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_V2XDchaSwtInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_AccessoryConnStsFb_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_DCDC_CANComFault_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_CutOffLVFb_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_FaultLevel1_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_IDCDCActHiside1_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_IDcDcActLoSide_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_DCDC_OutOverCurr_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_DCDC_OutOverVolt_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_PTCConnStsFb_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_DCDC_Relay_Volt_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_SelfChkSts_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_TDcDc_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_DCDC_UDCDCActHiside_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_UDcDcActLoSide_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_DcDcActvd_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_DcDcStsAlm_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EGSM_LeverPosition_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EGSM_ParkReq_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EGSM_ShiftleverFailSt_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_ABSActive_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_ABSFailed_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_AEB_active_EHB_DA_MESSAGE_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_AVHStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_BrkSysErrFault_EHB_DriverRemind_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_DTC_Active_EHB_DA_MESSAGE_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_EPBErrorStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_EPBStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_EPB_DynamicApplystatus_EHB_DriverRemind_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_FLWheelSpeedKPH_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_FRWheelSpeedKPH_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_HHCActive_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_ISA_PTTrqDecReq_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_ISA_PTTrqDecReqActive_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_ISA_Status_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_MbRegenTargetWheel_EHB_Regen_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_MbRegenTargetWheelSts_EHB_Regen_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_PTTrqDecReq_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_PTTrqDecReqActive_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_PTTrqIncReq_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_PTTrqIncReqActive_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_RLWheelSpeedKPH_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_RRWheelSpeedKPH_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_VLC_Active_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_VLC_Available_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_VLC_CDD_active_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_VLC_PTTrqReq_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_VLC_PTTrqReqActive_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_VehicleSpeed_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_VehicleSpeedInvalid_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EWP_HeatPower_HEWP_1_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EWP_OutputTemp_HEWP_1_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_CCWFlg_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_FWFV_CurrentPos_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_InitState_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_MotorState_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_OverCurrentFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_OverTempFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_OverVoltageFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_RESP_ERROR_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_UnderVoltageFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_AcceRelayVolt_HCM_Other2RelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_HCM_AcceRelayVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_HCM_MainPosBackVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_PTCRelayVolt_HCM_Other2RelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_HCM_PTCRelayVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_IPK_AllowChgSoftSwCtrlSt_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_IPK_ChrgSoftSwCtrlSt_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_EngRecMode_Req_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint32, RTE_VAR_INIT) Rte_ComBuffer_IPK_IPKTotalOdometer_IPK_TotalOdometer_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_IPK_Odometerbackup_IPK_TotalOdometer_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_CCWFlg_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_MHGV_CurrentPos_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_InitState_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_MotorState_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_OverCurrentFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_OverTempFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_OverVoltageFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_RESP_ERROR_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_UnderVoltageFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_MMI_LocalBookChrgnTarVal_MMI_SOCSet_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_MMI_RestSwitch_MMI_HVSM_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_ChgCCSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_ChrgrSt_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_Elock_Stmode_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_LockLoopSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdCCline_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdCPline_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdChrgrT_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdDisChrgrCCline_OBC_Curr_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdOuptI_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdOuptU_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_OBC_PwrEgyMgrAvl_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_SelfCheSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_ODP_DCDC_TDcDcAlm_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_PDC_Brake_Flag_PDC_Status_Info_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_PEPS_PowerMode_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_PEPS_PowerModeValidity_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_PEPS_RKECommand_PEPS_KeyReminder_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_PEPS_RemoteControlSt_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_RFR_ConnectionStatus_Station_Status_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint64, RTE_VAR_INIT) Rte_ComBuffer_RFR_Seed_RFR_Seed_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint64, RTE_VAR_INIT) Rte_ComBuffer_RFR_SwapBatCode_RFR_SwapBatCode_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_Station_CarLocationConfirm_Station_Status_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_Station_CarStation_Station_Status_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_Station_SwapBatRequest_Station_Status_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_Station_Swapingproceeding_Station_Status_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_AllowChgCurrentMax_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_ChargeDepth_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_ChargeLimitSwitch_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_ChrgSoftSwCtrlSt_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Day_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Elevation_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_FunAnti_DismantleActive_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_FunLockVehActive_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Hour_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_InventorySpdLmtReq_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Life_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_LockLimSet_TBOX_VCULockResp_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_LockVehCtrl_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_LockVehPerFlag_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_LockVehType_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Minute_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Month_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_TBOX_PowerOffCmd_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_PriorityFullSwitchSts_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_TBOX_PriorityFullSwitchSts_UB_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_ReservationChrgnSts_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Second_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_SpdLmtLevelReq_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_VersionConversionFlag_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Year_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_YRS_LongitAcce_YRS2_N72__PMS_C_CAN_20260425_dbc_Rx;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatCurrent_BMSH_BatCurrent;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatSOE_BMSH_BatSOE;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatSOH_BMSH_BatSOH;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatTempMax_BMSH_BatTempMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatTempMin_BMSH_BatTempMin;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatUseableSOC_BMSH_BatUseableSOC;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BusVolt_BMSH_BusVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellVoltMax_BMSH_CellVoltMax;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellVoltMin_BMSH_CellVoltMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChargeProcess_BMSH_DCChargeProcess;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgCurReq_BMSH_DCChgCurReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_FinishChgTime_BMSH_FinishChgTime;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_FireAlarm_BMSH_FireAlarm;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackVolt_BMSH_PackVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsCC2_BMSH_StsCC2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsChgFault_BMSH_StsChgFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsDischgFault_BMSH_StsDischgFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsInsulation_BMSH_StsInsulation;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsMode_BMSH_StsMode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsPrecharge_BMSH_StsPrecharge;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_Crash_BMSH_VCU_Crash;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_ChgCCSts_BMS_ChgCCSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_ChgStatus_BMS_ChgStatus;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_CANCommFlt_IPU_CANCommFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_DischgState_IPU_DischgState;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IGBTFlt_IPU_IGBTFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgInvrT_IPU_IsgInvrT;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgModSts_IPU_IsgModSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgMotT_IPU_IsgMotT;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MCUMemoryFlt_IPU_MCUMemoryFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MCUTempHighAlarm_IPU_MCUTempHighAlarm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MCUTempSensorErr_IPU_MCUTempSensorErr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorFltLevell1_IPU_MotorFltLevell1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorLockRotErr_IPU_MotorLockRotErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorSpdHighAlarm_IPU_MotorSpdHighAlarm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorTempHighAlarm_IPU_MotorTempHighAlarm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorTempHighFault_IPU_MotorTempHighFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorTempSensorErr_IPU_MotorTempSensorErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_RotateInverterFlt_IPU_RotateInverterFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_SelfChkSts_IPU_SelfChkSts;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_ts_App1_Task_10ms_Core1_QM, RTE_VAR_NOINIT) Rte_App1_Task_10ms_Core1_QM;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_VAR_NO_INIT
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
#define Rte_IRead_swc_VCIP_Step_ACCM1_ActPower_ACCM1_ActPower() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_ACCM1_ActPower_ACCM1_ActPower.value)

#define Rte_IRead_swc_VCIP_Step_ACU_CrashOutputSts_ACU_CrashOutputSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_ACU_CrashOutputSts_ACU_CrashOutputSts.value)

#define Rte_IRead_swc_VCIP_Step_AC_ACCM_ActPower_AC_ACCM_ActPower() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_ACCM_ActPower_AC_ACCM_ActPower.value)

#define Rte_IRead_swc_VCIP_Step_AC_ACCM_Status_AC_ACCM_Status() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_ACCM_Status_AC_ACCM_Status.value)

#define Rte_IRead_swc_VCIP_Step_AC_AmbientTemperature_AC_AmbientTemperature() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_AmbientTemperature_AC_AmbientTemperature.value)

#define Rte_IRead_swc_VCIP_Step_AC_AmbientTemperatureInvalid_AC_AmbientTemperatureInvalid() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_AmbientTemperatureInvalid_AC_AmbientTemperatureInvalid.value)

#define Rte_IRead_swc_VCIP_Step_AC_CabinThermalReq_AC_CabinThermalReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_CabinThermalReq_AC_CabinThermalReq.value)

#define Rte_IRead_swc_VCIP_Step_AC_CoolingFanPWMSpd_AC_CoolingFanPWMSpd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_CoolingFanPWMSpd_AC_CoolingFanPWMSpd.value)

#define Rte_IRead_swc_VCIP_Step_AC_IPTC_ActPower_AC_IPTC_ActPower() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_IPTC_ActPower_AC_IPTC_ActPower.value)

#define Rte_IRead_swc_VCIP_Step_AC_IPTC_WorkSts_AC_IPTC_WorkSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_IPTC_WorkSts_AC_IPTC_WorkSts.value)

#define Rte_IRead_swc_VCIP_Step_AC_PTC_ActPower_AC_PTC_ActPower() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_PTC_ActPower_AC_PTC_ActPower.value)

#define Rte_IRead_swc_VCIP_Step_AC_PTC_ActPwr_Rear_AC_PTC_ActPwr_Rear() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_PTC_ActPwr_Rear_AC_PTC_ActPwr_Rear.value)

#define Rte_IRead_swc_VCIP_Step_AC_PTC_WorkSts_AC_PTC_WorkSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_PTC_WorkSts_AC_PTC_WorkSts.value)

#define Rte_IRead_swc_VCIP_Step_AC_PTC_WorkSts_Rear_AC_PTC_WorkSts_Rear() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_AC_PTC_WorkSts_Rear_AC_PTC_WorkSts_Rear.value)

#define Rte_IRead_swc_VCIP_Step_ADC1Ctr_AlvCtrErrFlg_ADC_ADC1Ctr_AlvCtrErrFlg_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1Ctr_AlvCtrErrFlg_PMS_ADC1Ctr_AlvCtrErrFlg_PMS() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1Ctr_ComRxToutFlg_ADC_ADC1Ctr_ComRxToutFlg_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1Ctr_ComRxToutFlg_PMS_ADC1Ctr_ComRxToutFlg_PMS() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1Ctr_CsmErrFlg_ADC_ADC1Ctr_CsmErrFlg_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1Ctr_CsmErrFlg_PMS_ADC1Ctr_CsmErrFlg_PMS() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1PMSCtr_AlvCtrErrFlg_ADC_ADC1PMSCtr_AlvCtrErrFlg_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1PMSCtr_AlvCtrErrFlg_PMS_ADC1PMSCtr_AlvCtrErrFlg_PMS() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1PMSCtr_ComRxToutFlg_ADC_ADC1PMSCtr_ComRxToutFlg_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1PMSCtr_ComRxToutFlg_PMS_ADC1PMSCtr_ComRxToutFlg_PMS() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1PMSCtr_CsmErrFlg_ADC_ADC1PMSCtr_CsmErrFlg_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1PMSCtr_CsmErrFlg_PMS_ADC1PMSCtr_CsmErrFlg_PMS() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1_CANBUS_flag_ADC1_CANBUS_flag() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1_ControlGear_Enable_ADC1_ControlGear_Enable() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1_ControlGear_Enable_ADC_ADC1_ControlGear_Enable_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1_ControlTorque_Enable_ADC1_ControlTorque_Enable() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1_ControlTorque_Enable_ADC_ADC1_ControlTorque_Enable_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1_Ctrl_Status_ADC1_Ctrl_Status() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1_Ctrl_Status_ADC_ADC1_Ctrl_Status_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1_SwitchCtrl_Req_ADC1_SwitchCtrl_Req() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1_SwitchCtrl_Req_ADC_ADC1_SwitchCtrl_Req_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1_System_Status_ADC1_System_Status() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1_System_Status_ADC_ADC1_System_Status_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC1_TargetGearPostion_ADC1_TargetGearPostion() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_ADC1_TargetGearPostion_ADC_ADC1_TargetGearPostion_ADC() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_ADC1_Target_DrivingTorque_ADC1_Target_DrivingTorque() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_ADC1_Target_DrivingTorque_ADC_ADC1_Target_DrivingTorque_ADC() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_ADC1_Temp_ADC1_Temp() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_ADC1_Temp_ADC_ADC1_Temp_ADC() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_ADCCtr_AlvCtrErrFlg_ADC_ADCCtr_AlvCtrErrFlg_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADCCtr_AlvCtrErrFlg_PMS_ADCCtr_AlvCtrErrFlg_PMS() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADCCtr_ComRxToutFlg_ADC_ADCCtr_ComRxToutFlg_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADCCtr_ComRxToutFlg_PMS_ADCCtr_ComRxToutFlg_PMS() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADCCtr_CsmErrFlg_ADC_ADCCtr_CsmErrFlg_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADCCtr_CsmErrFlg_PMS_ADCCtr_CsmErrFlg_PMS() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADCPMSCtr_AlvCtrErrFlg_ADC_ADCPMSCtr_AlvCtrErrFlg_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADCPMSCtr_AlvCtrErrFlg_PMS_ADCPMSCtr_AlvCtrErrFlg_PMS() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADCPMSCtr_ComRxToutFlg_ADC_ADCPMSCtr_ComRxToutFlg_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADCPMSCtr_ComRxToutFlg_PMS_ADCPMSCtr_ComRxToutFlg_PMS() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADCPMSCtr_CsmErrFlg_ADC_ADCPMSCtr_CsmErrFlg_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADCPMSCtr_CsmErrFlg_PMS_ADCPMSCtr_CsmErrFlg_PMS() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC_CANBusOff_flg_ADC_CANBusOff_flg() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC_ControlGear_Enable_ADC_ControlGear_Enable() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC_ControlGear_Enable_ADC_ADC_ControlGear_Enable_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC_ControlTorque_Enable_ADC_ControlTorque_Enable() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC_ControlTorque_Enable_ADC_ADC_ControlTorque_Enable_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC_Ctrl_Status_ADC_Ctrl_Status() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC_Ctrl_Status_ADC_ADC_Ctrl_Status_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC_System_Status_ADC_System_Status() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC_System_Status_ADC_ADC_System_Status_ADC() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_ADC_TargetGearPostion_ADC_TargetGearPostion() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_ADC_TargetGearPostion_ADC_ADC_TargetGearPostion_ADC() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_ADC_Target_DrivingTorque_ADC_Target_DrivingTorque() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_ADC_Target_DrivingTorque_ADC_ADC_Target_DrivingTorque_ADC() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_ADC_Temp_ADC_Temp() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_ADC_Temp_ADC_ADC_Temp_ADC() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_BBM_FaultStatus_BBM_FaultStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BBM_FaultStatus_BBM_FaultStatus.value)

#define Rte_IRead_swc_VCIP_Step_BBM_WorkSts_BBM_WorkSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BBM_WorkSts_BBM_WorkSts.value)

#define Rte_IRead_swc_VCIP_Step_BCM_ATWS_St_BCM_ATWS_St() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BCM_ATWS_St_BCM_ATWS_St.value)

#define Rte_IRead_swc_VCIP_Step_BCM_BrakePedalSwitchInvalid_BCM_BrakePedalSwitchInvalid() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_BCM_BrakePedalSwitchStatus_BCM_BrakePedalSwitchStatus() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_BCM_DrvSeatbeltBuckleInvalid_BCM_DrvSeatbeltBuckleInvalid() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BCM_DrvSeatbeltBuckleInvalid_BCM_DrvSeatbeltBuckleInvalid.value)

#define Rte_IRead_swc_VCIP_Step_BCM_DrvSeatbeltBucklestatus_BCM_DrvSeatbeltBucklestatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BCM_DrvSeatbeltBucklestatus_BCM_DrvSeatbeltBucklestatus.value)

#define Rte_IRead_swc_VCIP_Step_BCM_FrontLeftDoorAjarStatus_BCM_FrontLeftDoorAjarStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BCM_FrontLeftDoorAjarStatus_BCM_FrontLeftDoorAjarStatus.value)

#define Rte_IRead_swc_VCIP_Step_BCM_FrontRightDoorAjarStatus_BCM_FrontRightDoorAjarStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BCM_FrontRightDoorAjarStatus_BCM_FrontRightDoorAjarStatus.value)

#define Rte_IRead_swc_VCIP_Step_BCM_IntelligentChargeCommand_BCM_IntelligentChargeCommand() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BCM_IntelligentChargeCommand_BCM_IntelligentChargeCommand.value)

#define Rte_IRead_swc_VCIP_Step_BCM_Odometerbackup_BCM_Odometerbackup() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BCM_Odometerbackup_BCM_Odometerbackup.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_BatCurrent_BMSH_BatCurrent() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BatCurrent_BMSH_BatCurrent.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_BatSOE_BMSH_BatSOE() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BatSOE_BMSH_BatSOE.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_BatSOH_BMSH_BatSOH() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BatSOH_BMSH_BatSOH.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_BatTempMax_BMSH_BatTempMax() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BatTempMax_BMSH_BatTempMax.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_BatTempMin_BMSH_BatTempMin() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BatTempMin_BMSH_BatTempMin.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_BatUseableSOC_BMSH_BatUseableSOC() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BatUseableSOC_BMSH_BatUseableSOC.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_BattPackNum_EV_BMSH_BattPackNum_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BattPackNum_EV_BMSH_BattPackNum_EV.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_BattSysNum_EV_BMSH_BattSysNum_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BattSysNum_EV_BMSH_BattSysNum_EV.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_BattTempAvg_EV_BMSH_BattTempAvg_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BattTempAvg_EV_BMSH_BattTempAvg_EV.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_BusVolt_BMSH_BusVolt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_BusVolt_BMSH_BusVolt.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_CellVoltMax_BMSH_CellVoltMax() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_CellVoltMax_BMSH_CellVoltMax.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_CellVoltMin_BMSH_CellVoltMin() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_CellVoltMin_BMSH_CellVoltMin.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_DCChargeProcess_BMSH_DCChargeProcess() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_DCChargeProcess_BMSH_DCChargeProcess.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_DCChgCurReq_BMSH_DCChgCurReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_DCChgCurReq_BMSH_DCChgCurReq.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_FinishChgTime_BMSH_FinishChgTime() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_FinishChgTime_BMSH_FinishChgTime.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_FireAlarm_BMSH_FireAlarm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_FireAlarm_BMSH_FireAlarm.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_PackVolt_BMSH_PackVolt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_PackVolt_BMSH_PackVolt.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_StsCC2_BMSH_StsCC2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_StsCC2_BMSH_StsCC2.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_StsChgFault_BMSH_StsChgFault() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_StsChgFault_BMSH_StsChgFault.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_StsDischgFault_BMSH_StsDischgFault() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_StsDischgFault_BMSH_StsDischgFault.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_StsInsulation_BMSH_StsInsulation() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_StsInsulation_BMSH_StsInsulation.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_StsMode_BMSH_StsMode() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_StsMode_BMSH_StsMode.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_StsPrecharge_BMSH_StsPrecharge() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_StsPrecharge_BMSH_StsPrecharge.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_BatIsoAlarm2_EV_BMSH_TBOX_BatIsoAlarm2_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatIsoAlarm2_EV_BMSH_TBOX_BatIsoAlarm2_EV.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_BatLowSOC2_EV_BMSH_TBOX_BatLowSOC2_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatLowSOC2_EV_BMSH_TBOX_BatLowSOC2_EV.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_BatOverCharge2_EV_BMSH_TBOX_BatOverCharge2_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatOverCharge2_EV_BMSH_TBOX_BatOverCharge2_EV.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_BatOverSOC2_EV_BMSH_TBOX_BatOverSOC2_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatOverSOC2_EV_BMSH_TBOX_BatOverSOC2_EV.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_BatOverTemp2_EV_BMSH_TBOX_BatOverTemp2_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatOverTemp2_EV_BMSH_TBOX_BatOverTemp2_EV.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_BatOverVoltage2_EV_BMSH_TBOX_BatOverVoltage2_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatOverVoltage2_EV_BMSH_TBOX_BatOverVoltage2_EV.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_BatTempUniformity2_EV_BMSH_TBOX_BatTempUniformity2_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatTempUniformity2_EV_BMSH_TBOX_BatTempUniformity2_EV.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_BatUnderVoltage2_EV_BMSH_TBOX_BatUnderVoltage2_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatUnderVoltage2_EV_BMSH_TBOX_BatUnderVoltage2_EV.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_BatUniformity2_EV_BMSH_TBOX_BatUniformity2_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_BatUniformity2_EV_BMSH_TBOX_BatUniformity2_EV.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_CellOverVoltage2_EV_BMSH_TBOX_CellOverVoltage2_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_CellOverVoltage2_EV_BMSH_TBOX_CellOverVoltage2_EV.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_CellUnderVoltage2_EV_BMSH_TBOX_CellUnderVoltage2_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_CellUnderVoltage2_EV_BMSH_TBOX_CellUnderVoltage2_EV.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_FireAlarm_EV_BMSH_TBOX_FireAlarm_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_FireAlarm_EV_BMSH_TBOX_FireAlarm_EV.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_TBOX_SOCHop2_EV_BMSH_TBOX_SOCHop2_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_TBOX_SOCHop2_EV_BMSH_TBOX_SOCHop2_EV.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_VCU_Crash_BMSH_VCU_Crash() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_VCU_Crash_BMSH_VCU_Crash.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq.value)

#define Rte_IRead_swc_VCIP_Step_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL.value)

#define Rte_IRead_swc_VCIP_Step_BMS_BattPackMatchFault_EV_BMS_BattPackMatchFault_EV() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_BMS_ChgCCSts_BMS_ChgCCSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMS_ChgCCSts_BMS_ChgCCSts.value)

#define Rte_IRead_swc_VCIP_Step_BMS_ChgStatus_BMS_ChgStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMS_ChgStatus_BMS_ChgStatus.value)

#define Rte_IRead_swc_VCIP_Step_BMS_DelayDataUpldEnb_EV_BMS_DelayDataUpldEnb_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMS_DelayDataUpldEnb_EV_BMS_DelayDataUpldEnb_EV.value)

#define Rte_IRead_swc_VCIP_Step_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req.value)

#define Rte_IRead_swc_VCIP_Step_CSM_CampModeSwt_CSM_CampModeSwt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_CampModeSwt_CSM_CampModeSwt.value)

#define Rte_IRead_swc_VCIP_Step_CSM_CampModeSwtInvalid_CSM_CampModeSwtInvalid() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_CampModeSwtInvalid_CSM_CampModeSwtInvalid.value)

#define Rte_IRead_swc_VCIP_Step_CSM_DriveModeReq_CSM_DriveModeReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_DriveModeReq_CSM_DriveModeReq.value)

#define Rte_IRead_swc_VCIP_Step_CSM_DriveModeReqInvalid_CSM_DriveModeReqInvalid() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_DriveModeReqInvalid_CSM_DriveModeReqInvalid.value)

#define Rte_IRead_swc_VCIP_Step_CSM_EngRec_Req_CSM_EngRec_Req() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_EngRec_Req_CSM_EngRec_Req.value)

#define Rte_IRead_swc_VCIP_Step_CSM_EngRec_ReqInvalid_CSM_EngRec_ReqInvalid() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_EngRec_ReqInvalid_CSM_EngRec_ReqInvalid.value)

#define Rte_IRead_swc_VCIP_Step_CSM_TakeEleSwt_CSM_TakeEleSwt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_TakeEleSwt_CSM_TakeEleSwt.value)

#define Rte_IRead_swc_VCIP_Step_CSM_TakeEleSwt_ReqInvalid_CSM_TakeEleSwt_ReqInvalid() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_TakeEleSwt_ReqInvalid_CSM_TakeEleSwt_ReqInvalid.value)

#define Rte_IRead_swc_VCIP_Step_CSM_V2XDchaSwt_CSM_V2XDchaSwt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_V2XDchaSwt_CSM_V2XDchaSwt.value)

#define Rte_IRead_swc_VCIP_Step_CSM_V2XDchaSwtInvalid_CSM_V2XDchaSwtInvalid() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_CSM_V2XDchaSwtInvalid_CSM_V2XDchaSwtInvalid.value)

#define Rte_IRead_swc_VCIP_Step_DCDC_AccessoryConnStsFb_EV_DCDC_AccessoryConnStsFb_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_AccessoryConnStsFb_EV_DCDC_AccessoryConnStsFb_EV.value)

#define Rte_IRead_swc_VCIP_Step_DCDC_CANComFault_DCDC_CANComFault() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_CANComFault_DCDC_CANComFault.value)

#define Rte_IRead_swc_VCIP_Step_DCDC_CutOffLVFb_DCDC_CutOffLVFb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_CutOffLVFb_DCDC_CutOffLVFb.value)

#define Rte_IRead_swc_VCIP_Step_DCDC_FaultLevel1_DCDC_FaultLevel1() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_FaultLevel1_DCDC_FaultLevel1.value)

#define Rte_IRead_swc_VCIP_Step_DCDC_IDCDCActHiside1_DCDC_IDCDCActHiside1() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_IDCDCActHiside1_DCDC_IDCDCActHiside1.value)

#define Rte_IRead_swc_VCIP_Step_DCDC_IDcDcActLoSide_DCDC_IDcDcActLoSide() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_IDcDcActLoSide_DCDC_IDcDcActLoSide.value)

#define Rte_IRead_swc_VCIP_Step_DCDC_OutOverCurr_DCDC_OutOverCurr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_OutOverCurr_DCDC_OutOverCurr.value)

#define Rte_IRead_swc_VCIP_Step_DCDC_OutOverVolt_DCDC_OutOverVolt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_OutOverVolt_DCDC_OutOverVolt.value)

#define Rte_IRead_swc_VCIP_Step_DCDC_PTCConnStsFb_EV_DCDC_PTCConnStsFb_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_PTCConnStsFb_EV_DCDC_PTCConnStsFb_EV.value)

#define Rte_IRead_swc_VCIP_Step_DCDC_Relay_Volt_DCDC_Relay_Volt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_Relay_Volt_DCDC_Relay_Volt.value)

#define Rte_IRead_swc_VCIP_Step_DCDC_SelfChkSts_DCDC_SelfChkSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_SelfChkSts_DCDC_SelfChkSts.value)

#define Rte_IRead_swc_VCIP_Step_DCDC_TDcDc_DCDC_TDcDc() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_TDcDc_DCDC_TDcDc.value)

#define Rte_IRead_swc_VCIP_Step_DCDC_UDCDCActHiside_DCDC_UDCDCActHiside() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_UDCDCActHiside_DCDC_UDCDCActHiside.value)

#define Rte_IRead_swc_VCIP_Step_DCDC_UDcDcActLoSide_DCDC_UDcDcActLoSide() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DCDC_UDcDcActLoSide_DCDC_UDcDcActLoSide.value)

#define Rte_IRead_swc_VCIP_Step_DcDcActvd_DcDcActvd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DcDcActvd_DcDcActvd.value)

#define Rte_IRead_swc_VCIP_Step_DcDcStsAlm_DcDcStsAlm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_DcDcStsAlm_DcDcStsAlm.value)

#define Rte_IRead_swc_VCIP_Step_ECU_Fun_Config_Data1_ECU_Fun_Config_Data1() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_ECU_Fun_Config_Data1_ECU_Fun_Config_Data1.value)

#define Rte_IRead_swc_VCIP_Step_ECU_Fun_Config_Data2_ECU_Fun_Config_Data2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_ECU_Fun_Config_Data2_ECU_Fun_Config_Data2.value)

#define Rte_IRead_swc_VCIP_Step_ECU_Net_Config_Data1_ECU_Net_Config_Data1() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_ECU_Net_Config_Data1_ECU_Net_Config_Data1.value)

#define Rte_IRead_swc_VCIP_Step_ECU_Net_Config_Data2_ECU_Net_Config_Data2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_ECU_Net_Config_Data2_ECU_Net_Config_Data2.value)

#define Rte_IRead_swc_VCIP_Step_EGSM_LeverPosition_EGSM_LeverPosition() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EGSM_LeverPosition_EGSM_LeverPosition.value)

#define Rte_IRead_swc_VCIP_Step_EGSM_ParkReq_EGSM_ParkReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EGSM_ParkReq_EGSM_ParkReq.value)

#define Rte_IRead_swc_VCIP_Step_EGSM_ShiftleverFailSt_EGSM_ShiftleverFailSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EGSM_ShiftleverFailSt_EGSM_ShiftleverFailSt.value)

#define Rte_IRead_swc_VCIP_Step_EHB_ABSActive_EHB_ABSActive() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_ABSActive_EHB_ABSActive.value)

#define Rte_IRead_swc_VCIP_Step_EHB_ABSFailed_EHB_ABSFailed() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_ABSFailed_EHB_ABSFailed.value)

#define Rte_IRead_swc_VCIP_Step_EHB_AEB_active_EHB_AEB_active() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_AEB_active_EHB_AEB_active.value)

#define Rte_IRead_swc_VCIP_Step_EHB_AVHStatus_EHB_AVHStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_AVHStatus_EHB_AVHStatus.value)

#define Rte_IRead_swc_VCIP_Step_EHB_BrkSysErrFault_EHB_BrkSysErrFault() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_BrkSysErrFault_EHB_BrkSysErrFault.value)

#define Rte_IRead_swc_VCIP_Step_EHB_DTC_Active_EHB_DTC_Active() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_DTC_Active_EHB_DTC_Active.value)

#define Rte_IRead_swc_VCIP_Step_EHB_EPBErrorStatus_EHB_EPBErrorStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_EPBErrorStatus_EHB_EPBErrorStatus.value)

#define Rte_IRead_swc_VCIP_Step_EHB_EPBStatus_EHB_EPBStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_EPBStatus_EHB_EPBStatus.value)

#define Rte_IRead_swc_VCIP_Step_EHB_EPB_DynamicApplystatus_EHB_EPB_DynamicApplystatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_EPB_DynamicApplystatus_EHB_EPB_DynamicApplystatus.value)

#define Rte_IRead_swc_VCIP_Step_EHB_FLWheelSpeedKPH_EHB_FLWheelSpeedKPH() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_FLWheelSpeedKPH_EHB_FLWheelSpeedKPH.value)

#define Rte_IRead_swc_VCIP_Step_EHB_FRWheelSpeedKPH_EHB_FRWheelSpeedKPH() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_FRWheelSpeedKPH_EHB_FRWheelSpeedKPH.value)

#define Rte_IRead_swc_VCIP_Step_EHB_HHCActive_EHB_HHCActive() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_HHCActive_EHB_HHCActive.value)

#define Rte_IRead_swc_VCIP_Step_EHB_ISA_PTTrqDecReq_EHB_ISA_PTTrqDecReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_ISA_PTTrqDecReq_EHB_ISA_PTTrqDecReq.value)

#define Rte_IRead_swc_VCIP_Step_EHB_ISA_PTTrqDecReqActive_EHB_ISA_PTTrqDecReqActive() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_ISA_PTTrqDecReqActive_EHB_ISA_PTTrqDecReqActive.value)

#define Rte_IRead_swc_VCIP_Step_EHB_ISA_Status_EHB_ISA_Status() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_ISA_Status_EHB_ISA_Status.value)

#define Rte_IRead_swc_VCIP_Step_EHB_MbRegenTargetWheel_EHB_MbRegenTargetWheel() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_MbRegenTargetWheel_EHB_MbRegenTargetWheel.value)

#define Rte_IRead_swc_VCIP_Step_EHB_MbRegenTargetWheelSts_EHB_MbRegenTargetWheelSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_MbRegenTargetWheelSts_EHB_MbRegenTargetWheelSts.value)

#define Rte_IRead_swc_VCIP_Step_EHB_PTTrqDecReq_EHB_PTTrqDecReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_PTTrqDecReq_EHB_PTTrqDecReq.value)

#define Rte_IRead_swc_VCIP_Step_EHB_PTTrqDecReqActive_EHB_PTTrqDecReqActive() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_PTTrqDecReqActive_EHB_PTTrqDecReqActive.value)

#define Rte_IRead_swc_VCIP_Step_EHB_PTTrqIncReq_EHB_PTTrqIncReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_PTTrqIncReq_EHB_PTTrqIncReq.value)

#define Rte_IRead_swc_VCIP_Step_EHB_PTTrqIncReqActive_EHB_PTTrqIncReqActive() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_PTTrqIncReqActive_EHB_PTTrqIncReqActive.value)

#define Rte_IRead_swc_VCIP_Step_EHB_RLWheelSpeedKPH_EHB_RLWheelSpeedKPH() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_RLWheelSpeedKPH_EHB_RLWheelSpeedKPH.value)

#define Rte_IRead_swc_VCIP_Step_EHB_RRWheelSpeedKPH_EHB_RRWheelSpeedKPH() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_RRWheelSpeedKPH_EHB_RRWheelSpeedKPH.value)

#define Rte_IRead_swc_VCIP_Step_EHB_VLC_Active_EHB_VLC_Active() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_VLC_Active_EHB_VLC_Active.value)

#define Rte_IRead_swc_VCIP_Step_EHB_VLC_Available_EHB_VLC_Available() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_VLC_Available_EHB_VLC_Available.value)

#define Rte_IRead_swc_VCIP_Step_EHB_VLC_CDD_active_EHB_VLC_CDD_active() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_VLC_CDD_active_EHB_VLC_CDD_active.value)

#define Rte_IRead_swc_VCIP_Step_EHB_VLC_PTTrqReq_EHB_VLC_PTTrqReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_VLC_PTTrqReq_EHB_VLC_PTTrqReq.value)

#define Rte_IRead_swc_VCIP_Step_EHB_VLC_PTTrqReqActive_EHB_VLC_PTTrqReqActive() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_VLC_PTTrqReqActive_EHB_VLC_PTTrqReqActive.value)

#define Rte_IRead_swc_VCIP_Step_EHB_VehicleSpeed_EHB_VehicleSpeed() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_VehicleSpeed_EHB_VehicleSpeed.value)

#define Rte_IRead_swc_VCIP_Step_EHB_VehicleSpeedInvalid_EHB_VehicleSpeedInvalid() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EHB_VehicleSpeedInvalid_EHB_VehicleSpeedInvalid.value)

#define Rte_IRead_swc_VCIP_Step_EPS_EpasFailed_EPS_EpasFailed() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_EPS_SteerWheelAngle_EPS_SteerWheelAngle() \
  (0)

#define Rte_IRead_swc_VCIP_Step_EWP_HeatPower_EWP_HeatPower() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EWP_HeatPower_EWP_HeatPower.value)

#define Rte_IRead_swc_VCIP_Step_EWP_OutputTemp_EWP_OutputTemp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EWP_OutputTemp_EWP_OutputTemp.value)

#define Rte_IRead_swc_VCIP_Step_EXT_AI_BATTERY_TEMPH_5_EXT_AI_BATTERY_TEMPH_5() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AI_BATTERY_TEMPH_5_EXT_AI_BATTERY_TEMPH_5.value)

#define Rte_IRead_swc_VCIP_Step_EXT_AI_BATTERY_TEMPH_6_EXT_AI_BATTERY_TEMPH_6() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AI_BATTERY_TEMPH_6_EXT_AI_BATTERY_TEMPH_6.value)

#define Rte_IRead_swc_VCIP_Step_EXT_AI_MID_COOLING_TEMPH_8_EXT_AI_MID_COOLING_TEMPH_8() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AI_MID_COOLING_TEMPH_8_EXT_AI_MID_COOLING_TEMPH_8.value)

#define Rte_IRead_swc_VCIP_Step_EXT_AI_SENSOR_1_EXT_AI_SENSOR_1() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AI_SENSOR_1_EXT_AI_SENSOR_1.value)

#define Rte_IRead_swc_VCIP_Step_EXT_AI_SENSOR_2_EXT_AI_SENSOR_2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AI_SENSOR_2_EXT_AI_SENSOR_2.value)

#define Rte_IRead_swc_VCIP_Step_EXT_AI_SENSOR_6_EXT_AI_SENSOR_6() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AI_SENSOR_6_EXT_AI_SENSOR_6.value)

#define Rte_IRead_swc_VCIP_Step_EXT_AI_SWITCH_1_EXT_AI_SWITCH_1() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AI_SWITCH_1_EXT_AI_SWITCH_1.value)

#define Rte_IRead_swc_VCIP_Step_EXT_AO_LDO_5V_02_EXT_AO_LDO_5V_02() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AO_LDO_5V_02_EXT_AO_LDO_5V_02.value)

#define Rte_IRead_swc_VCIP_Step_EXT_AO_TRACKING_5V_01_EXT_AO_TRACKING_5V_01() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AO_TRACKING_5V_01_EXT_AO_TRACKING_5V_01.value)

#define Rte_IRead_swc_VCIP_Step_EXT_AO_TRACKING_5V_02_EXT_AO_TRACKING_5V_02() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_AO_TRACKING_5V_02_EXT_AO_TRACKING_5V_02.value)

#define Rte_IRead_swc_VCIP_Step_EXT_CHARGE_ON_AI_EXT_CHARGE_ON_AI() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_CHARGE_ON_AI_EXT_CHARGE_ON_AI.value)

#define Rte_IRead_swc_VCIP_Step_EXT_DI_HS_04_EXT_DI_HS_04() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_DI_HS_04_EXT_DI_HS_04.value)

#define Rte_IRead_swc_VCIP_Step_EXT_DI_HS_05_EXT_DI_HS_05() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_DI_HS_05_EXT_DI_HS_05.value)

#define Rte_IRead_swc_VCIP_Step_EXT_DI_HS_06_EXT_DI_HS_06() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_DI_HS_06_EXT_DI_HS_06.value)

#define Rte_IRead_swc_VCIP_Step_EXT_DI_HS_07_EXT_DI_HS_07() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_DI_HS_07_EXT_DI_HS_07.value)

#define Rte_IRead_swc_VCIP_Step_EXT_DI_HS_08_EXT_DI_HS_08() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_DI_HS_08_EXT_DI_HS_08.value)

#define Rte_IRead_swc_VCIP_Step_EXT_DI_HS_10_EXT_DI_HS_10() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_DI_HS_10_EXT_DI_HS_10.value)

#define Rte_IRead_swc_VCIP_Step_EXT_IGN_ON_AI_EXT_IGN_ON_AI() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_IGN_ON_AI_EXT_IGN_ON_AI.value)

#define Rte_IRead_swc_VCIP_Step_EXT_IGN_ON_DI_EXT_IGN_ON_DI() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_IGN_ON_DI_EXT_IGN_ON_DI.value)

#define Rte_IRead_swc_VCIP_Step_EXT_PI_HVIL_1_DutyCycle_EXT_PI_HVIL_1_DutyCycle() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_PI_HVIL_1_DutyCycle_EXT_PI_HVIL_1_DutyCycle.value)

#define Rte_IRead_swc_VCIP_Step_EXT_PI_HVIL_1_Period_EXT_PI_HVIL_1_Period() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_PI_HVIL_1_Period_EXT_PI_HVIL_1_Period.value)

#define Rte_IRead_swc_VCIP_Step_EXT_PI_HVIL_2_DutyCycle_EXT_PI_HVIL_2_DutyCycle() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_PI_HVIL_2_DutyCycle_EXT_PI_HVIL_2_DutyCycle.value)

#define Rte_IRead_swc_VCIP_Step_EXT_PI_HVIL_2_Period_EXT_PI_HVIL_2_Period() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_PI_HVIL_2_Period_EXT_PI_HVIL_2_Period.value)

#define Rte_IRead_swc_VCIP_Step_EXT_PI_PWM_1_DutyCycle_EXT_PI_PWM_1_DutyCycle() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_PI_PWM_1_DutyCycle_EXT_PI_PWM_1_DutyCycle.value)

#define Rte_IRead_swc_VCIP_Step_EXT_PI_PWM_2_DutyCycle_EXT_PI_PWM_2_DutyCycle() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_EXT_PI_PWM_2_DutyCycle_EXT_PI_PWM_2_DutyCycle.value)

#define Rte_IRead_swc_VCIP_Step_EXT_PI_PWM_4_DutyCycle_EXT_PI_PWM_4_DutyCycle() \
  (0.0F)

#define Rte_IRead_swc_VCIP_Step_FWFV_CCWFlg_FWFV_CCWFlg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_FWFV_CCWFlg_FWFV_CCWFlg.value)

#define Rte_IRead_swc_VCIP_Step_FWFV_CurrentPos_FWFV_CurrentPos() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_FWFV_CurrentPos_FWFV_CurrentPos.value)

#define Rte_IRead_swc_VCIP_Step_FWFV_InitState_FWFV_InitState() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_FWFV_InitState_FWFV_InitState.value)

#define Rte_IRead_swc_VCIP_Step_FWFV_MotorState_FWFV_MotorState() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_FWFV_MotorState_FWFV_MotorState.value)

#define Rte_IRead_swc_VCIP_Step_FWFV_OverCurrentFlt_FWFV_OverCurrentFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_FWFV_OverCurrentFlt_FWFV_OverCurrentFlt.value)

#define Rte_IRead_swc_VCIP_Step_FWFV_OverTempFlt_FWFV_OverTempFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_FWFV_OverTempFlt_FWFV_OverTempFlt.value)

#define Rte_IRead_swc_VCIP_Step_FWFV_OverVoltageFlt_FWFV_OverVoltageFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_FWFV_OverVoltageFlt_FWFV_OverVoltageFlt.value)

#define Rte_IRead_swc_VCIP_Step_FWFV_RESP_ERROR_FWFV_RESP_ERROR() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_FWFV_RESP_ERROR_FWFV_RESP_ERROR.value)

#define Rte_IRead_swc_VCIP_Step_FWFV_UnderVoltageFlt_FWFV_UnderVoltageFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_FWFV_UnderVoltageFlt_FWFV_UnderVoltageFlt.value)

#define Rte_IRead_swc_VCIP_Step_HCM_AcceRelayVolt_HCM_AcceRelayVolt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_HCM_AcceRelayVolt_HCM_AcceRelayVolt.value)

#define Rte_IRead_swc_VCIP_Step_HCM_AcceRelayVoltValidStat_HCM_AcceRelayVoltValidStat() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_HCM_AcceRelayVoltValidStat_HCM_AcceRelayVoltValidStat.value)

#define Rte_IRead_swc_VCIP_Step_HCM_AccessoryConnStsFb_HCM_AccessoryConnStsFb() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_HCM_LockLoopSts_HCM_LockLoopSts() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_HCM_MainPosBackVolt_HCM_MainPosBackVolt() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_HCM_MainPosBackVoltValidStat_HCM_MainPosBackVoltValidStat() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_HCM_MainPosBackVoltValidStat_HCM_MainPosBackVoltValidStat.value)

#define Rte_IRead_swc_VCIP_Step_HCM_PTC1ConnStsFb_HCM_PTC1ConnStsFb() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_HCM_PTCConnStsFb_HCM_PTCConnStsFb() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_HCM_PTCRelayVolt_HCM_PTCRelayVolt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_HCM_PTCRelayVolt_HCM_PTCRelayVolt.value)

#define Rte_IRead_swc_VCIP_Step_HCM_PTCRelayVoltValidStat_HCM_PTCRelayVoltValidStat() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_HCM_PTCRelayVoltValidStat_HCM_PTCRelayVoltValidStat.value)

#define Rte_IRead_swc_VCIP_Step_IPK_AllowChgSoftSwCtrlSt_IPK_AllowChgSoftSwCtrlSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPK_AllowChgSoftSwCtrlSt_IPK_AllowChgSoftSwCtrlSt.value)

#define Rte_IRead_swc_VCIP_Step_IPK_ChrgSoftSwCtrlSt_IPK_ChrgSoftSwCtrlSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPK_ChrgSoftSwCtrlSt_IPK_ChrgSoftSwCtrlSt.value)

#define Rte_IRead_swc_VCIP_Step_IPK_CruisingDstSwt_IPK_CruisingDstSwt() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_IPK_EngRecMode_Req_IPK_EngRecMode_Req() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPK_EngRecMode_Req_IPK_EngRecMode_Req.value)

#define Rte_IRead_swc_VCIP_Step_IPK_IPKTotalOdometer_PT_IPK_IPKTotalOdometer_PT() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPK_IPKTotalOdometer_PT_IPK_IPKTotalOdometer_PT.value)

#define Rte_IRead_swc_VCIP_Step_IPK_Odometerbackup_IPK_Odometerbackup() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPK_Odometerbackup_IPK_Odometerbackup.value)

#define Rte_IRead_swc_VCIP_Step_IPK_OdometerbackupEnable_IPK_OdometerbackupEnable() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_IPU_CANCommFlt_IPU_CANCommFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_CANCommFlt_IPU_CANCommFlt.value)

#define Rte_IRead_swc_VCIP_Step_IPU_DisChgFault_IPU_DisChgFault() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_IPU_DischgState_IPU_DischgState() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_DischgState_IPU_DischgState.value)

#define Rte_IRead_swc_VCIP_Step_IPU_HVBusCur_EV_IPU_HVBusCur_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_HVBusCur_EV_IPU_HVBusCur_EV.value)

#define Rte_IRead_swc_VCIP_Step_IPU_HVBusVolt_EV_IPU_HVBusVolt_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_HVBusVolt_EV_IPU_HVBusVolt_EV.value)

#define Rte_IRead_swc_VCIP_Step_IPU_HVBusVolt_IPUSts_IPU_HVBusVolt_IPUSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_HVBusVolt_IPUSts_IPU_HVBusVolt_IPUSts.value)

#define Rte_IRead_swc_VCIP_Step_IPU_IGBTFlt_IPU_IGBTFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_IGBTFlt_IPU_IGBTFlt.value)

#define Rte_IRead_swc_VCIP_Step_IPU_IsgInvrT_IPU_IsgInvrT() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_IsgInvrT_IPU_IsgInvrT.value)

#define Rte_IRead_swc_VCIP_Step_IPU_IsgModSts_IPU_IsgModSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_IsgModSts_IPU_IsgModSts.value)

#define Rte_IRead_swc_VCIP_Step_IPU_IsgMotT_IPU_IsgMotT() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_IsgMotT_IPU_IsgMotT.value)

#define Rte_IRead_swc_VCIP_Step_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn.value)

#define Rte_IRead_swc_VCIP_Step_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid.value)

#define Rte_IRead_swc_VCIP_Step_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct.value)

#define Rte_IRead_swc_VCIP_Step_IPU_MCUEnableSts_IPU_MCUEnableSts() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_IPU_MCUMemoryFlt_IPU_MCUMemoryFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MCUMemoryFlt_IPU_MCUMemoryFlt.value)

#define Rte_IRead_swc_VCIP_Step_IPU_MCUTempHighAlarm_IPU_MCUTempHighAlarm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MCUTempHighAlarm_IPU_MCUTempHighAlarm.value)

#define Rte_IRead_swc_VCIP_Step_IPU_MCUTempHighAlarm1_EV_IPU_MCUTempHighAlarm1_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MCUTempHighAlarm1_EV_IPU_MCUTempHighAlarm1_EV.value)

#define Rte_IRead_swc_VCIP_Step_IPU_MCUTempSensorErr_IPU_MCUTempSensorErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MCUTempSensorErr_IPU_MCUTempSensorErr.value)

#define Rte_IRead_swc_VCIP_Step_IPU_MotorFltLevell1_IPU_MotorFltLevell1() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MotorFltLevell1_IPU_MotorFltLevell1.value)

#define Rte_IRead_swc_VCIP_Step_IPU_MotorLockRotErr_IPU_MotorLockRotErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MotorLockRotErr_IPU_MotorLockRotErr.value)

#define Rte_IRead_swc_VCIP_Step_IPU_MotorOverCurrFlt_EV_IPU_MotorOverCurrFlt_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MotorOverCurrFlt_EV_IPU_MotorOverCurrFlt_EV.value)

#define Rte_IRead_swc_VCIP_Step_IPU_MotorOverSpdFlt_EV_IPU_MotorOverSpdFlt_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MotorOverSpdFlt_EV_IPU_MotorOverSpdFlt_EV.value)

#define Rte_IRead_swc_VCIP_Step_IPU_MotorSpdHighAlarm_IPU_MotorSpdHighAlarm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MotorSpdHighAlarm_IPU_MotorSpdHighAlarm.value)

#define Rte_IRead_swc_VCIP_Step_IPU_MotorSubFltLevell_IPU_MotorSubFltLevell() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_IPU_MotorTempHighAlarm_IPU_MotorTempHighAlarm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MotorTempHighAlarm_IPU_MotorTempHighAlarm.value)

#define Rte_IRead_swc_VCIP_Step_IPU_MotorTempHighFault_IPU_MotorTempHighFault() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MotorTempHighFault_IPU_MotorTempHighFault.value)

#define Rte_IRead_swc_VCIP_Step_IPU_MotorTempHighFault1_EV_IPU_MotorTempHighFault1_EV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MotorTempHighFault1_EV_IPU_MotorTempHighFault1_EV.value)

#define Rte_IRead_swc_VCIP_Step_IPU_MotorTempSensorErr_IPU_MotorTempSensorErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_MotorTempSensorErr_IPU_MotorTempSensorErr.value)

#define Rte_IRead_swc_VCIP_Step_IPU_RotateInverterFlt_IPU_RotateInverterFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_RotateInverterFlt_IPU_RotateInverterFlt.value)

#define Rte_IRead_swc_VCIP_Step_IPU_SelfChkSts_IPU_SelfChkSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_SelfChkSts_IPU_SelfChkSts.value)

#define Rte_IRead_swc_VCIP_Step_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax.value)

#define Rte_IRead_swc_VCIP_Step_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin.value)

#define Rte_IRead_swc_VCIP_Step_I_A_PIN31_I_A_PIN31() \
  (0.0F)

#define Rte_IRead_swc_VCIP_Step_I_S_PIN25_I_S_PIN25() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_I_S_PIN38_I_S_PIN38() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_I_S_PIN84_I_S_PIN84() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_KL30_KL30() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_KL30_KL30.value)

#define Rte_IRead_swc_VCIP_Step_MHGV_CCWFlg_MHGV_CCWFlg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MHGV_CCWFlg_MHGV_CCWFlg.value)

#define Rte_IRead_swc_VCIP_Step_MHGV_CurrentPos_MHGV_CurrentPos() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MHGV_CurrentPos_MHGV_CurrentPos.value)

#define Rte_IRead_swc_VCIP_Step_MHGV_InitState_MHGV_InitState() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MHGV_InitState_MHGV_InitState.value)

#define Rte_IRead_swc_VCIP_Step_MHGV_MotorState_MHGV_MotorState() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MHGV_MotorState_MHGV_MotorState.value)

#define Rte_IRead_swc_VCIP_Step_MHGV_OverCurrentFlt_MHGV_OverCurrentFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MHGV_OverCurrentFlt_MHGV_OverCurrentFlt.value)

#define Rte_IRead_swc_VCIP_Step_MHGV_OverTempFlt_MHGV_OverTempFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MHGV_OverTempFlt_MHGV_OverTempFlt.value)

#define Rte_IRead_swc_VCIP_Step_MHGV_OverVoltageFlt_MHGV_OverVoltageFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MHGV_OverVoltageFlt_MHGV_OverVoltageFlt.value)

#define Rte_IRead_swc_VCIP_Step_MHGV_RESP_ERROR_MHGV_RESP_ERROR() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MHGV_RESP_ERROR_MHGV_RESP_ERROR.value)

#define Rte_IRead_swc_VCIP_Step_MHGV_UnderVoltageFlt_MHGV_UnderVoltageFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MHGV_UnderVoltageFlt_MHGV_UnderVoltageFlt.value)

#define Rte_IRead_swc_VCIP_Step_MMI_LocalBookChrgnTarVal_MMI_LocalBookChrgnTarVal() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MMI_LocalBookChrgnTarVal_MMI_LocalBookChrgnTarVal.value)

#define Rte_IRead_swc_VCIP_Step_MMI_RestSwitch_MMI_RestSwitch() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_MMI_RestSwitch_MMI_RestSwitch.value)

#define Rte_IRead_swc_VCIP_Step_OBC_ChgCCSts_OBC_ChgCCSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_ChgCCSts_OBC_ChgCCSts.value)

#define Rte_IRead_swc_VCIP_Step_OBC_ChrgrSt_OBC_ChrgrSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_ChrgrSt_OBC_ChrgrSt.value)

#define Rte_IRead_swc_VCIP_Step_OBC_Elock_Stmode_OBC_Elock_Stmode() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_Elock_Stmode_OBC_Elock_Stmode.value)

#define Rte_IRead_swc_VCIP_Step_OBC_LockLoopSts_OBC_LockLoopSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_LockLoopSts_OBC_LockLoopSts.value)

#define Rte_IRead_swc_VCIP_Step_OBC_OnBdCCline_OBC_OnBdCCline() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_OnBdCCline_OBC_OnBdCCline.value)

#define Rte_IRead_swc_VCIP_Step_OBC_OnBdCPline_OBC_OnBdCPline() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_OnBdCPline_OBC_OnBdCPline.value)

#define Rte_IRead_swc_VCIP_Step_OBC_OnBdChrgrT_OBC_OnBdChrgrT() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_OnBdChrgrT_OBC_OnBdChrgrT.value)

#define Rte_IRead_swc_VCIP_Step_OBC_OnBdDisChrgrCCline_OBC_OnBdDisChrgrCCline() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_OnBdDisChrgrCCline_OBC_OnBdDisChrgrCCline.value)

#define Rte_IRead_swc_VCIP_Step_OBC_OnBdOuptI_OBC_OnBdOuptI() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_OnBdOuptI_OBC_OnBdOuptI.value)

#define Rte_IRead_swc_VCIP_Step_OBC_OnBdOuptU_OBC_OnBdOuptU() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_OnBdOuptU_OBC_OnBdOuptU.value)

#define Rte_IRead_swc_VCIP_Step_OBC_PwrEgyMgrAvl_OBC_PwrEgyMgrAvl() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_PwrEgyMgrAvl_OBC_PwrEgyMgrAvl.value)

#define Rte_IRead_swc_VCIP_Step_OBC_SelfCheSts_OBC_SelfCheSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_OBC_SelfCheSts_OBC_SelfCheSts.value)

#define Rte_IRead_swc_VCIP_Step_ODP_DCDC_TDcDcAlm_ODP_DCDC_TDcDcAlm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_ODP_DCDC_TDcDcAlm_ODP_DCDC_TDcDcAlm.value)

#define Rte_IRead_swc_VCIP_Step_PDCStatus_AlvCtrErrFlg_PDCStatus_AlvCtrErrFlg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_PDCStatus_AlvCtrErrFlg_PDCStatus_AlvCtrErrFlg.value)

#define Rte_IRead_swc_VCIP_Step_PDC_Brake_Flag_PDC_Brake_Flag() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_PDC_Brake_Flag_PDC_Brake_Flag.value)

#define Rte_IRead_swc_VCIP_Step_PDC_Status_CsmErrFlg_PDC_Status_CsmErrFlg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_PDC_Status_CsmErrFlg_PDC_Status_CsmErrFlg.value)

#define Rte_IRead_swc_VCIP_Step_PEPS_PowerMode_PEPS_PowerMode() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_PEPS_PowerMode_PEPS_PowerMode.value)

#define Rte_IRead_swc_VCIP_Step_PEPS_PowerModeValidity_PEPS_PowerModeValidity() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_PEPS_PowerModeValidity_PEPS_PowerModeValidity.value)

#define Rte_IRead_swc_VCIP_Step_PEPS_RKECommand_PEPS_RKECommand() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_PEPS_RKECommand_PEPS_RKECommand.value)

#define Rte_IRead_swc_VCIP_Step_PEPS_RemoteControlSt_PEPS_RemoteControlSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_PEPS_RemoteControlSt_PEPS_RemoteControlSt.value)

#define Rte_IRead_swc_VCIP_Step_PMS_CANBusOff_flg_PMS_CANBusOff_flg() \
  (FALSE)

#define Rte_IRead_swc_VCIP_Step_RFR_ConnectionStatus_RFR_ConnectionStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_RFR_ConnectionStatus_RFR_ConnectionStatus.value)

#define Rte_IRead_swc_VCIP_Step_RFR_Seed_RFR_Seed() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_RFR_Seed_RFR_Seed.value)

#define Rte_IRead_swc_VCIP_Step_RFR_SwapBatCode_RFR_SwapBatCode() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_RFR_SwapBatCode_RFR_SwapBatCode.value)

#define Rte_IRead_swc_VCIP_Step_Station_CarLocationConfirm_Station_CarLocationConfirm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_Station_CarLocationConfirm_Station_CarLocationConfirm.value)

#define Rte_IRead_swc_VCIP_Step_Station_CarStation_Station_CarStation() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_Station_CarStation_Station_CarStation.value)

#define Rte_IRead_swc_VCIP_Step_Station_SwapBatRequest_Station_SwapBatRequest() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_Station_SwapBatRequest_Station_SwapBatRequest.value)

#define Rte_IRead_swc_VCIP_Step_Station_Swapingproceeding_Station_Swapingproceeding() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_Station_Swapingproceeding_Station_Swapingproceeding.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_AllowChgCurrentMax_TBOX_AllowChgCurrentMax() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_AllowChgCurrentMax_TBOX_AllowChgCurrentMax.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_ChargeDepth_TBOX_ChargeDepth() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_ChargeDepth_TBOX_ChargeDepth.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_ChargeLimitSwitch_TBOX_ChargeLimitSwitch() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_ChargeLimitSwitch_TBOX_ChargeLimitSwitch.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_ChrgSoftSwCtrlSt_TBOX_ChrgSoftSwCtrlSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_ChrgSoftSwCtrlSt_TBOX_ChrgSoftSwCtrlSt.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_Day_TBOX_Day() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_Day_TBOX_Day.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_Elevation_TBOX_Elevation() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_Elevation_TBOX_Elevation.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_FunAnti_DismantleActive_TBOX_FunAnti_DismantleActive() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_FunAnti_DismantleActive_TBOX_FunAnti_DismantleActive.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_FunLockVehActive_TBOX_FunLockVehActive() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_FunLockVehActive_TBOX_FunLockVehActive.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_Hour_TBOX_Hour() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_Hour_TBOX_Hour.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_InventorySpdLmtReq_TBOX_InventorySpdLmtReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_InventorySpdLmtReq_TBOX_InventorySpdLmtReq.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_Life_TBOX_Life() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_Life_TBOX_Life.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_LockLimSet_TBOX_LockLimSet() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_LockLimSet_TBOX_LockLimSet.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_LockResultResp_TBOX_LockResultResp() \
  (0U)

#define Rte_IRead_swc_VCIP_Step_TBOX_LockVehCtrl_TBOX_LockVehCtrl() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_LockVehCtrl_TBOX_LockVehCtrl.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_LockVehPerFlag_TBOX_LockVehPerFlag() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_LockVehPerFlag_TBOX_LockVehPerFlag.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_LockVehType_TBOX_LockVehType() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_LockVehType_TBOX_LockVehType.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_Minute_TBOX_Minute() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_Minute_TBOX_Minute.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_Month_TBOX_Month() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_Month_TBOX_Month.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_PowerOffCmd_TBOX_PowerOffCmd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_PowerOffCmd_TBOX_PowerOffCmd.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_PriorityFullSwitchSts_TBOX_PriorityFullSwitchSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_PriorityFullSwitchSts_TBOX_PriorityFullSwitchSts.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_PriorityFullSwitchSts_UB_TBOX_PriorityFullSwitchSts_UB() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_PriorityFullSwitchSts_UB_TBOX_PriorityFullSwitchSts_UB.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_ReservationChrgnSts_TBOX_ReservationChrgnSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_ReservationChrgnSts_TBOX_ReservationChrgnSts.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_Second_TBOX_Second() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_Second_TBOX_Second.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_SpdLmtLevelReq_TBOX_SpdLmtLevelReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_SpdLmtLevelReq_TBOX_SpdLmtLevelReq.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_VersionConversionFlag_TBOX_VersionConversionFlag() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_VersionConversionFlag_TBOX_VersionConversionFlag.value)

#define Rte_IRead_swc_VCIP_Step_TBOX_Year_TBOX_Year() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_TBOX_Year_TBOX_Year.value)

#define Rte_IRead_swc_VCIP_Step_YRS_LongitAcce_YRS_LongitAcce() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_YRS_LongitAcce_YRS_LongitAcce.value)

#define Rte_IRead_swc_VCIP_Step_s2vd_BMS_PmtCutoffLVFb_s2vd_BMS_PmtCutoffLVFb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_s2vd_BMS_PmtCutoffLVFb_s2vd_BMS_PmtCutoffLVFb.value)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_accd_b_acHvilOpn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_b_acHvilOpn.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_accd_b_acHvilOpn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_b_acHvilOpn.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_accd_b_acHvilOpnInvld(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_b_acHvilOpnInvld.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_accd_b_acHvilOpnInvld() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_b_acHvilOpnInvld.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_accd_e_PtcSt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_e_PtcSt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_accd_e_PtcSt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_e_PtcSt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_accd_e_acFltLvl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_e_acFltLvl.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_accd_e_acFltLvl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_e_acFltLvl.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_accd_e_airCmprSt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_e_airCmprSt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_accd_e_airCmprSt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_e_airCmprSt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_accd_n_acFanReqSpd_pct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_n_acFanReqSpd_pct.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_accd_n_acFanReqSpd_pct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_n_acFanReqSpd_pct.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_accd_st_AcWrk(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_st_AcWrk.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_accd_st_AcWrk() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_st_AcWrk.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_accd_st_acSubFltSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_st_acSubFltSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_accd_st_acSubFltSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_st_acSubFltSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_accd_st_airCmprSt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_st_airCmprSt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_accd_st_airCmprSt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_st_airCmprSt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_accd_st_cbnThermMngReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_st_cbnThermMngReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_accd_st_cbnThermMngReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_st_cbnThermMngReq.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_accd_st_iptWorkSt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_st_iptWorkSt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_accd_st_iptWorkSt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_st_iptWorkSt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_accd_st_ptcWorkStRear(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_st_ptcWorkStRear.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_accd_st_ptcWorkStRear() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_st_ptcWorkStRear.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_accd_t_ambTemp_C(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_t_ambTemp_C.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_accd_t_ambTemp_C() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_t_ambTemp_C.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_accd_u_acPresVolt_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_u_acPresVolt_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_accd_u_acPresVolt_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_accd_u_acPresVolt_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_acpd_b_accPedlPosVld(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_b_accPedlPosVld.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_acpd_b_accPedlPosVld() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_b_accPedlPosVld.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_acpd_u_accPedlPosSens1VoltRaw_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_u_accPedlPosSens1VoltRaw_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_acpd_u_accPedlPosSens1VoltRaw_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_u_accPedlPosSens1VoltRaw_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_acpd_u_accPedlPosSens2VoltRaw_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_u_accPedlPosSens2VoltRaw_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_acpd_u_accPedlPosSens2VoltRaw_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_u_accPedlPosSens2VoltRaw_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_acpd_x_accPedlPosCan_pct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_x_accPedlPosCan_pct.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_acpd_x_accPedlPosCan_pct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_x_accPedlPosCan_pct.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_acpd_x_accPedlPosLimd_pct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_x_accPedlPosLimd_pct.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_acpd_x_accPedlPosLimd_pct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_x_accPedlPosLimd_pct.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_acpd_x_accPedlPosSens1_pct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_x_accPedlPosSens1_pct.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_acpd_x_accPedlPosSens1_pct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_x_accPedlPosSens1_pct.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_acpd_x_accPedlPosSens2_pct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_x_accPedlPosSens2_pct.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_acpd_x_accPedlPosSens2_pct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_x_accPedlPosSens2_pct.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_acpd_x_accPedlPos_pct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_x_accPedlPos_pct.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_acpd_x_accPedlPos_pct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_acpd_x_accPedlPos_pct.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_adcd_b_adc1CtrlTorqEn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_b_adc1CtrlTorqEn.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_adcd_b_adc1CtrlTorqEn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_b_adc1CtrlTorqEn.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_adcd_b_adc1SwtchCtrlReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_b_adc1SwtchCtrlReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_adcd_b_adc1SwtchCtrlReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_b_adc1SwtchCtrlReq.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_adcd_b_adcCtrlGearEn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_b_adcCtrlGearEn.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_adcd_b_adcCtrlGearEn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_b_adcCtrlGearEn.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_adcd_b_adcCtrlTorqEn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_b_adcCtrlTorqEn.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_adcd_b_adcCtrlTorqEn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_b_adcCtrlTorqEn.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_adcd_st_adcTgtGearPostn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_st_adcTgtGearPostn.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_adcd_st_adcTgtGearPostn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_st_adcTgtGearPostn.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_adcd_st_pmsAdcCtrldSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_st_pmsAdcCtrldSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_adcd_st_pmsAdcCtrldSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_st_pmsAdcCtrldSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_adcd_st_pmsCanBusRecSta(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_st_pmsCanBusRecSta.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_adcd_st_pmsCanBusRecSta() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_st_pmsCanBusRecSta.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_adcd_tq_adc1TgtDrvTorq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_tq_adc1TgtDrvTorq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_adcd_tq_adc1TgtDrvTorq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_tq_adc1TgtDrvTorq_Nm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_adcd_tq_adcTgtDrvTorq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_tq_adcTgtDrvTorq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_adcd_tq_adcTgtDrvTorq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_adcd_tq_adcTgtDrvTorq_Nm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_brpd_b_DryAirSwitch(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_DryAirSwitch.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_brpd_b_DryAirSwitch() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_DryAirSwitch.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_brpd_b_ResrAirSwitch(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_ResrAirSwitch.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_brpd_b_ResrAirSwitch() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_ResrAirSwitch.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_brpd_b_brakeSwitch1Closed(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brakeSwitch1Closed.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_brpd_b_brakeSwitch1Closed() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brakeSwitch1Closed.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_brpd_b_brakeSwitch2Closed(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brakeSwitch2Closed.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_brpd_b_brakeSwitch2Closed() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brakeSwitch2Closed.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_brpd_b_brkPedlPosVld(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brkPedlPosVld.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_brpd_b_brkPedlPosVld() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brkPedlPosVld.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_brpd_b_brkPedlStsVld(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brkPedlStsVld.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_brpd_b_brkPedlStsVld() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brkPedlStsVld.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_brpd_b_brkPmpSelfChkErr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brkPmpSelfChkErr.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_brpd_b_brkPmpSelfChkErr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brkPmpSelfChkErr.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_brpd_b_brkPmpSelfChkOk(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brkPmpSelfChkOk.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_brpd_b_brkPmpSelfChkOk() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brkPmpSelfChkOk.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_brpd_b_brkPressedFromSwitch(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brkPressedFromSwitch.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_brpd_b_brkPressedFromSwitch() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brkPressedFromSwitch.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_brpd_b_brkPumpFault(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brkPumpFault.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_brpd_b_brkPumpFault() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_brkPumpFault.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_brpd_b_vacTankLowPrs(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_vacTankLowPrs.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_brpd_b_vacTankLowPrs() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_b_vacTankLowPrs.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_brpd_e_bdcacWrk(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_e_bdcacWrk.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_brpd_e_bdcacWrk() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_e_bdcacWrk.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_brpd_e_brkPedalStatus(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_e_brkPedalStatus.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_brpd_e_brkPedalStatus() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_e_brkPedalStatus.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_brpd_p_AirPres_kpa(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_p_AirPres_kpa.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_brpd_p_AirPres_kpa() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_p_AirPres_kpa.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_brpd_p_brkVacuumPres_bar(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_p_brkVacuumPres_bar.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_brpd_p_brkVacuumPres_bar() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_p_brkVacuumPres_bar.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_brpd_st_bdcacWrk(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_st_bdcacWrk.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_brpd_st_bdcacWrk() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_st_bdcacWrk.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_brpd_x_brkPedlPos_pct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_x_brkPedlPos_pct.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_brpd_x_brkPedlPos_pct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_brpd_x_brkPedlPos_pct.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_ccdd_u_cruiseADvoltage_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_ccdd_u_cruiseADvoltage_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_ccdd_u_cruiseADvoltage_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_ccdd_u_cruiseADvoltage_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_cesd_b_EmergencyStop(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_cesd_b_EmergencyStop.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_cesd_b_EmergencyStop() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_cesd_b_EmergencyStop.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_cesd_b_acuCrash(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_cesd_b_acuCrash.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_cesd_b_acuCrash() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_cesd_b_acuCrash.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_cesd_b_crash(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_cesd_b_crash.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_cesd_b_crash() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_cesd_b_crash.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_dccd_b_dcdcCutOffLvFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_b_dcdcCutOffLvFb.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_dccd_b_dcdcCutOffLvFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_b_dcdcCutOffLvFb.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_dccd_b_dcdcHvilFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_b_dcdcHvilFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_dccd_b_dcdcHvilFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_b_dcdcHvilFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_dccd_b_dcdcHvilFltInvld(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_b_dcdcHvilFltInvld.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_dccd_b_dcdcHvilFltInvld() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_b_dcdcHvilFltInvld.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_dccd_b_dcdcSelfChkErr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_b_dcdcSelfChkErr.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_dccd_b_dcdcSelfChkErr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_b_dcdcSelfChkErr.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_dccd_b_dcdcSelfChkOk(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_b_dcdcSelfChkOk.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_dccd_b_dcdcSelfChkOk() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_b_dcdcSelfChkOk.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_dccd_e_24vDcdcModAct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_e_24vDcdcModAct.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_dccd_e_24vDcdcModAct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_e_24vDcdcModAct.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_dccd_e_dcdcFaultStatus(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_e_dcdcFaultStatus.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_dccd_e_dcdcFaultStatus() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_e_dcdcFaultStatus.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_dccd_e_modeAct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_e_modeAct.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_dccd_e_modeAct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_e_modeAct.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_dccd_pwr_dcdcHVpwr_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_pwr_dcdcHVpwr_kW.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_dccd_pwr_dcdcHVpwr_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_pwr_dcdcHVpwr_kW.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_dccd_st_12vDcdcModAct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_st_12vDcdcModAct.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_dccd_st_12vDcdcModAct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_st_12vDcdcModAct.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_dccd_st_24vDcdcFltSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_st_24vDcdcFltSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_dccd_st_24vDcdcFltSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_st_24vDcdcFltSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_dccd_st_24vDcdcModAct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_st_24vDcdcModAct.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_dccd_st_24vDcdcModAct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_st_24vDcdcModAct.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_dccd_st_24vDcdcSubFltSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_st_24vDcdcSubFltSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_dccd_st_24vDcdcSubFltSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_st_24vDcdcSubFltSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_dccd_t_dcdcTemp_C(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_t_dcdcTemp_C.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_dccd_t_dcdcTemp_C() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_dccd_t_dcdcTemp_C.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_drid_b_drvrModeReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_drvrModeReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_drid_b_drvrModeReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_drvrModeReq.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_drid_b_drvrModeReq4WD(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_drvrModeReq4WD.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_drid_b_drvrModeReq4WD() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_drvrModeReq4WD.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_drid_b_drvrModeReqECO(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_drvrModeReqECO.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_drid_b_drvrModeReqECO() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_drvrModeReqECO.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_drid_b_drvrModeReqEV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_drvrModeReqEV.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_drid_b_drvrModeReqEV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_drvrModeReqEV.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_drid_b_drvrModeReqHEV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_drvrModeReqHEV.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_drid_b_drvrModeReqHEV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_drvrModeReqHEV.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_drid_b_drvrModeReqSPORT(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_drvrModeReqSPORT.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_drid_b_drvrModeReqSPORT() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_drvrModeReqSPORT.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_drid_b_parkBtnPressed(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_parkBtnPressed.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_drid_b_parkBtnPressed() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_b_parkBtnPressed.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_drid_e_gearLvrPosRaw(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_e_gearLvrPosRaw.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_drid_e_gearLvrPosRaw() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_e_gearLvrPosRaw.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_drid_st_gearLvrPosSeql(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_st_gearLvrPosSeql.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_drid_st_gearLvrPosSeql() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_drid_st_gearLvrPosSeql.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_b_eadInv2ActvDischCmplt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_b_eadInv2ActvDischCmplt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_b_eadInv2ActvDischCmplt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_b_eadInv2ActvDischCmplt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_b_eadInv2RdyToCutOffLV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_b_eadInv2RdyToCutOffLV.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_b_eadInv2RdyToCutOffLV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_b_eadInv2RdyToCutOffLV.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_b_eadInv2SelfChkErr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_b_eadInv2SelfChkErr.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_b_eadInv2SelfChkErr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_b_eadInv2SelfChkErr.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_b_eadInv2SelfChkOk(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_b_eadInv2SelfChkOk.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_b_eadInv2SelfChkOk() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_b_eadInv2SelfChkOk.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_e_eadInv2Sts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_e_eadInv2Sts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_e_eadInv2Sts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_e_eadInv2Sts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_e_inv21FltSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_e_inv21FltSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_e_inv21FltSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_e_inv21FltSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_e_inv2FltSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_e_inv2FltSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_e_inv2FltSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_e_inv2FltSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_e_inv2ModeAct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_e_inv2ModeAct.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_e_inv2ModeAct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_e_inv2ModeAct.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_fact_mot2GearRat(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_fact_mot2GearRat.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_fact_mot2GearRat() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_fact_mot2GearRat.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_n_mot2ActSpd_rpm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_n_mot2ActSpd_rpm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_pwr_mot21ActPwr_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_pwr_mot21ActPwr_kW.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_pwr_mot21ActPwr_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_pwr_mot21ActPwr_kW.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_pwr_mot2ActPwr_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_pwr_mot2ActPwr_kW.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_pwr_mot2ActPwr_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_pwr_mot2ActPwr_kW.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_st_eadInv2PwrActvMod(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_st_eadInv2PwrActvMod.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_st_eadInv2PwrActvMod() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_st_eadInv2PwrActvMod.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_st_eadInv2Sts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_st_eadInv2Sts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_st_eadInv2Sts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_st_eadInv2Sts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_st_eadInv2WrkMod(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_st_eadInv2WrkMod.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_st_eadInv2WrkMod() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_st_eadInv2WrkMod.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_st_eadMot2ImmoRlsChk(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_st_eadMot2ImmoRlsChk.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_st_eadMot2ImmoRlsChk() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_st_eadMot2ImmoRlsChk.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_st_inv2SubFltSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_st_inv2SubFltSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_st_inv2SubFltSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_st_inv2SubFltSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_t_inv2Temp_C(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_t_inv2Temp_C.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_t_inv2Temp_C() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_t_inv2Temp_C.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_t_mot2Temp_C(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_t_mot2Temp_C.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_t_mot2Temp_C() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_t_mot2Temp_C.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_tq_mot2ActTq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_tq_mot2ActTq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_tq_mot2ActTq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_tq_mot2ActTq_Nm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_tq_mot2MaxAvailLTBrk_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailLTBrk_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_tq_mot2MaxAvailLTBrk_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailLTBrk_Nm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_tq_mot2MaxAvailLTBst_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailLTBst_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_tq_mot2MaxAvailLTBst_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailLTBst_Nm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_tq_mot2MaxAvailSTBrk_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailSTBrk_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_tq_mot2MaxAvailSTBrk_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailSTBrk_Nm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_tq_mot2MaxAvailSTBst_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailSTBst_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_tq_mot2MaxAvailSTBst_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailSTBst_Nm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_eadd_u_busInv2HVAct_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_u_busInv2HVAct_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_eadd_u_busInv2HVAct_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_eadd_u_busInv2HVAct_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_epbd_e_parkingSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_epbd_e_parkingSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_epbd_e_parkingSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_epbd_e_parkingSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_b_bmsSelfChkErr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_bmsSelfChkErr.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_b_bmsSelfChkErr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_bmsSelfChkErr.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_b_bmsSelfChkOk(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_bmsSelfChkOk.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_b_bmsSelfChkOk() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_bmsSelfChkOk.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_b_hcmCutOffLvFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hcmCutOffLvFb.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_b_hcmCutOffLvFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hcmCutOffLvFb.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_b_hcmPtcDefRlyCls(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hcmPtcDefRlyCls.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_b_hcmPtcDefRlyCls() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hcmPtcDefRlyCls.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_b_hcmRlyWldFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hcmRlyWldFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_b_hcmRlyWldFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hcmRlyWldFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_b_hcmSelfChkErr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hcmSelfChkErr.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_b_hcmSelfChkErr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hcmSelfChkErr.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_b_hcmSelfChkOk(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hcmSelfChkOk.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_b_hcmSelfChkOk() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hcmSelfChkOk.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_b_hvbChPwrLimdByTemp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hvbChPwrLimdByTemp.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_b_hvbChPwrLimdByTemp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hvbChPwrLimdByTemp.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_b_hvbDischPwrLimdByTemp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hvbDischPwrLimdByTemp.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_b_hvbDischPwrLimdByTemp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hvbDischPwrLimdByTemp.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_b_hvbHeatEnad(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hvbHeatEnad.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_b_hvbHeatEnad() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hvbHeatEnad.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_b_hvbPrmtCutOffLvFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hvbPrmtCutOffLvFb.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_b_hvbPrmtCutOffLvFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hvbPrmtCutOffLvFb.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_b_hvilOpen(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hvilOpen.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_b_hvilOpen() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_hvilOpen.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_b_lowTempProtnReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_lowTempProtnReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_b_lowTempProtnReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_lowTempProtnReq.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_b_obcChrgReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_obcChrgReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_b_obcChrgReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_obcChrgReq.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmd.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmd.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_e_dcdcMainRlySts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_dcdcMainRlySts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_e_dcdcMainRlySts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_dcdcMainRlySts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_e_eadInv2MainRlySts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_eadInv2MainRlySts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_e_eadInv2MainRlySts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_eadInv2MainRlySts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_e_hcmMaiRlyNeg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hcmMaiRlyNeg.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_e_hcmMaiRlyNeg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hcmMaiRlyNeg.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_e_hcmWrkSt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hcmWrkSt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_e_hcmWrkSt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hcmWrkSt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_e_hvbAssiRly(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hvbAssiRly.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_e_hvbAssiRly() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hvbAssiRly.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_e_hvbFaultStatus(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hvbFaultStatus.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_e_hvbFaultStatus() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hvbFaultStatus.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_e_hvbMaiRlyNeg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hvbMaiRlyNeg.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_e_hvbMaiRlyNeg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hvbMaiRlyNeg.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_e_hvbMaiRlyPos(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hvbMaiRlyPos.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_e_hvbMaiRlyPos() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hvbMaiRlyPos.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_e_hvbMainRlySts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hvbMainRlySts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_e_hvbMainRlySts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hvbMainRlySts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_e_hvbStatus(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hvbStatus.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_e_hvbStatus() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_e_hvbStatus.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_fact_hvbSOH_pct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_fact_hvbSOH_pct.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_fact_hvbSOH_pct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_fact_hvbSOH_pct.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_i_hvbCurr_A(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_i_hvbCurr_A.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_i_hvbCurr_A() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_i_hvbCurr_A.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_pwr_PeakChMax_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_PeakChMax_kW.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_pwr_PeakChMax_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_PeakChMax_kW.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_pwr_PeakDischMax_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_PeakDischMax_kW.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_pwr_PeakDischMax_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_PeakDischMax_kW.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_pwr_StatChMax_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_StatChMax_kW.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_pwr_StatChMax_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_StatChMax_kW.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_pwr_StatDischMax_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_StatDischMax_kW.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_pwr_StatDischMax_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_StatDischMax_kW.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_pwr_hvbActRaw_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_hvbActRaw_kW.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_pwr_hvbActRaw_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_hvbActRaw_kW.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_pwr_hvbAct_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_hvbAct_kW.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_pwr_hvbAct_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_hvbAct_kW.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_pwr_hvbChgPwr_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_hvbChgPwr_kW.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_pwr_hvbChgPwr_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_pwr_hvbChgPwr_kW.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_q_hvbSOC_pct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_q_hvbSOC_pct.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_q_hvbSOC_pct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_q_hvbSOC_pct.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_st_hcmFltLvl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hcmFltLvl.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_st_hcmFltLvl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hcmFltLvl.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_st_hcmMaiRlyNeg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hcmMaiRlyNeg.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_st_hcmMaiRlyNeg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hcmMaiRlyNeg.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_st_hcmPwrActvMod(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hcmPwrActvMod.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_st_hcmPwrActvMod() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hcmPwrActvMod.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_st_hvbPwrActvMod(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hvbPwrActvMod.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_st_hvbPwrActvMod() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hvbPwrActvMod.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_st_hvbSubFaultSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hvbSubFaultSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_st_hvbSubFaultSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hvbSubFaultSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_st_hvbThermMngReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hvbThermMngReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_st_hvbThermMngReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hvbThermMngReq.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_st_hvilOpenSt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hvilOpenSt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_st_hvilOpenSt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_hvilOpenSt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_st_tboxIntelChgQuit(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_tboxIntelChgQuit.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_st_tboxIntelChgQuit() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_st_tboxIntelChgQuit.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_t_hvbAvg_C(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_t_hvbAvg_C.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_t_hvbAvg_C() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_t_hvbAvg_C.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_t_hvbInCoolTemp_C(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_t_hvbInCoolTemp_C.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_t_hvbInCoolTemp_C() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_t_hvbInCoolTemp_C.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_t_hvbMin_C(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_t_hvbMin_C.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_t_hvbMin_C() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_t_hvbMin_C.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_hvbd_t_hvbTemp_C(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_t_hvbTemp_C.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_hvbd_t_hvbTemp_C() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_hvbd_t_hvbTemp_C.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_macd_V_tankFuelLvl_l(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_V_tankFuelLvl_l.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_macd_V_tankFuelLvl_l() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_V_tankFuelLvl_l.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_macd_b_epsSelfChkErr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_b_epsSelfChkErr.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_macd_b_epsSelfChkErr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_b_epsSelfChkErr.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_macd_b_epsSelfChkOk(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_b_epsSelfChkOk.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_macd_b_epsSelfChkOk() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_b_epsSelfChkOk.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_macd_b_pullUpDiagCmpl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_b_pullUpDiagCmpl.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_macd_b_pullUpDiagCmpl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_b_pullUpDiagCmpl.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_macd_b_vcuSelfChkOk(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_b_vcuSelfChkOk.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_macd_b_vcuSelfChkOk() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_b_vcuSelfChkOk.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_macd_e_sdcacWrk(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_e_sdcacWrk.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_macd_e_sdcacWrk() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_e_sdcacWrk.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_macd_p_frontAirTankPres_bar(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_p_frontAirTankPres_bar.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_macd_p_frontAirTankPres_bar() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_p_frontAirTankPres_bar.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_macd_p_rearAirTankPres_bar(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_p_rearAirTankPres_bar.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_macd_p_rearAirTankPres_bar() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_p_rearAirTankPres_bar.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_macd_st_epsErrorCode(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_st_epsErrorCode.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_macd_st_epsErrorCode() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_st_epsErrorCode.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_macd_st_epsFltLvl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_st_epsFltLvl.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_macd_st_epsFltLvl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_st_epsFltLvl.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_macd_st_epsSubFltLvl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_st_epsSubFltLvl.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_macd_st_epsSubFltLvl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_st_epsSubFltLvl.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_macd_st_sdcacWrk(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_st_sdcacWrk.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_macd_st_sdcacWrk() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_st_sdcacWrk.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_macd_t_ts5SnsrTemp_C(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_t_ts5SnsrTemp_C.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_macd_t_ts5SnsrTemp_C() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_t_ts5SnsrTemp_C.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_macd_u_batIntSmpl_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_u_batIntSmpl_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_macd_u_batIntSmpl_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_macd_u_batIntSmpl_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_obcd_b_obcCANMsgValid(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_b_obcCANMsgValid.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_obcd_b_obcCANMsgValid() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_b_obcCANMsgValid.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_obcd_b_obcChrgCablePlugged(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_b_obcChrgCablePlugged.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_obcd_b_obcChrgCablePlugged() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_b_obcChrgCablePlugged.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_obcd_b_obcChrgCableUnplugged(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_b_obcChrgCableUnplugged.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_obcd_b_obcChrgCableUnplugged() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_b_obcChrgCableUnplugged.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_obcd_b_obcSelfChkErr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_b_obcSelfChkErr.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_obcd_b_obcSelfChkErr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_b_obcSelfChkErr.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_obcd_b_obcSelfChkOk(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_b_obcSelfChkOk.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_obcd_b_obcSelfChkOk() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_b_obcSelfChkOk.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_obcd_b_obcWakeUp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_b_obcWakeUp.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_obcd_b_obcWakeUp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_b_obcWakeUp.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_obcd_pwr_obcOutpt_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_pwr_obcOutpt_kW.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_obcd_pwr_obcOutpt_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_pwr_obcOutpt_kW.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_obcd_pwr_obcRlTmOutpt_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_pwr_obcRlTmOutpt_kW.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_obcd_pwr_obcRlTmOutpt_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_pwr_obcRlTmOutpt_kW.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_obcd_st_obcfltLvl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_st_obcfltLvl.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_obcd_st_obcfltLvl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_st_obcfltLvl.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_obcd_t_obcTemp_C(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_t_obcTemp_C.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_obcd_t_obcTemp_C() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_obcd_t_obcTemp_C.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_pmmd_b_anyIgnOn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_anyIgnOn.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_pmmd_b_anyIgnOn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_anyIgnOn.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_pmmd_b_canIgnOn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_canIgnOn.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_pmmd_b_canIgnOn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_canIgnOn.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_pmmd_b_driverStartReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_driverStartReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_pmmd_b_driverStartReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_driverStartReq.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_pmmd_b_hwIgnOn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_hwIgnOn.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_pmmd_b_hwIgnOn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_hwIgnOn.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_pmmd_b_ignOn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_pmmd_b_ignOn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_pmmd_b_ignStsStrt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_ignStsStrt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_pmmd_b_ignStsStrt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_ignStsStrt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_pmmd_b_pepsPduLvlValid(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_pepsPduLvlValid.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_pmmd_b_pepsPduLvlValid() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_pepsPduLvlValid.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_pmmd_b_ptCanNmStRdy(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_ptCanNmStRdy.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_pmmd_b_ptCanNmStRdy() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_b_ptCanNmStRdy.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_pmmd_e_authenticationStatus(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_e_authenticationStatus.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_pmmd_e_authenticationStatus() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_pmmd_e_authenticationStatus.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_trad_b_trsm2GearActVld(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_b_trsm2GearActVld.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_trad_b_trsm2GearActVld() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_b_trsm2GearActVld.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_trad_b_trsm2GearshiftActv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_b_trsm2GearshiftActv.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_trad_b_trsm2GearshiftActv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_b_trsm2GearshiftActv.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_trad_e_trsm1PrkgSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_e_trsm1PrkgSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_trad_e_trsm1PrkgSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_e_trsm1PrkgSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_trad_e_trsm2GearShftResp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_e_trsm2GearShftResp.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_trad_e_trsm2GearShftResp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_e_trsm2GearShftResp.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_trad_fact_trsm2FinalDrvRat(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_fact_trsm2FinalDrvRat.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_trad_fact_trsm2FinalDrvRat() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_fact_trsm2FinalDrvRat.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_trad_fact_trsm2GbxGearRat(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_fact_trsm2GbxGearRat.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_trad_fact_trsm2GbxGearRat() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_fact_trsm2GbxGearRat.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_trad_fact_trsm2GearRat(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_fact_trsm2GearRat.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_trad_fact_trsm2GearRat() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_fact_trsm2GearRat.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_trad_st_trsm2GearAct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_st_trsm2GearAct.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_trad_st_trsm2GearAct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_trad_st_trsm2GearAct.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_R_posInsIRes_Ohm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_R_posInsIRes_Ohm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_R_posInsIRes_Ohm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_R_posInsIRes_Ohm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_a_yrsLongitAcce_mps2(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_a_yrsLongitAcce_mps2.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_a_yrsLongitAcce_mps2() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_a_yrsLongitAcce_mps2.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_ang_strWhlAng_rad(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_ang_strWhlAng_rad.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_ang_strWhlAng_rad() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_ang_strWhlAng_rad.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_AccyEnReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_AccyEnReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_AccyEnReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_AccyEnReq.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_AccyFltSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_AccyFltSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_AccyFltSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_AccyFltSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_CCSginal(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_CCSginal.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_CCSginal() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_CCSginal.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_DryAirSwitch(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_DryAirSwitch.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_DryAirSwitch() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_DryAirSwitch.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_ResrAirSwitch(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ResrAirSwitch.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_ResrAirSwitch() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ResrAirSwitch.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_adc1ComErrFlg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_adc1ComErrFlg.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_adc1ComErrFlg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_adc1ComErrFlg.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_adcComErrFlg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_adcComErrFlg.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_adcComErrFlg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_adcComErrFlg.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_bcmFrntLftDrAjSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_bcmFrntLftDrAjSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_bcmFrntLftDrAjSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_bcmFrntLftDrAjSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_bcmFrntRDrAjSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_bcmFrntRDrAjSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_bcmFrntRDrAjSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_bcmFrntRDrAjSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_brkSwt1Actv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_brkSwt1Actv.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_brkSwt1Actv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_brkSwt1Actv.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_brkSwt2Actv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_brkSwt2Actv.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_brkSwt2Actv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_brkSwt2Actv.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_calCanBusOff(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_calCanBusOff.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_calCanBusOff() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_calCanBusOff.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_cntnrCtrlEnaFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_cntnrCtrlEnaFb.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_cntnrCtrlEnaFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_cntnrCtrlEnaFb.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_csmCampModeSwt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmCampModeSwt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_csmCampModeSwt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmCampModeSwt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_csmCampModeSwtInvld(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmCampModeSwtInvld.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_csmCampModeSwtInvld() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmCampModeSwtInvld.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_csmEngRecSwtReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmEngRecSwtReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_csmEngRecSwtReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmEngRecSwtReq.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_csmTakeEleSwt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmTakeEleSwt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_csmTakeEleSwt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmTakeEleSwt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_csmTakeEleSwtReqInvld(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmTakeEleSwtReqInvld.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_csmTakeEleSwtReqInvld() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmTakeEleSwtReqInvld.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_csmV2XDchaSw(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmV2XDchaSw.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_csmV2XDchaSw() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmV2XDchaSw.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_csmV2XDchaSwInvld(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmV2XDchaSwInvld.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_csmV2XDchaSwInvld() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_csmV2XDchaSwInvld.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_dcdcStsAlm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_dcdcStsAlm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_dcdcStsAlm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_dcdcStsAlm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_dcdcTempAlm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_dcdcTempAlm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_dcdcTempAlm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_dcdcTempAlm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_disChgSwtSt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_disChgSwtSt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_disChgSwtSt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_disChgSwtSt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_driverEcoModeReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_driverEcoModeReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_driverEcoModeReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_driverEcoModeReq.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_ehbIsaPtTrqDecReqActv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ehbIsaPtTrqDecReqActv.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_ehbIsaPtTrqDecReqActv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ehbIsaPtTrqDecReqActv.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_ehbVlcCddActv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ehbVlcCddActv.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_ehbVlcCddActv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ehbVlcCddActv.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_emgyStopIn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_emgyStopIn.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_emgyStopIn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_emgyStopIn.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_epbErrSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_epbErrSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_epbErrSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_epbErrSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_flgBBMMsgErr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgBBMMsgErr.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_flgBBMMsgErr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgBBMMsgErr.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgACU(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgACU.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgACU() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgACU.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgAccyButton(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgAccyButton.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgAccyButton() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgAccyButton.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgAirBag(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgAirBag.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgAirBag() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgAirBag.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgBatCol(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgBatCol.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgBatCol() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgBatCol.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgChgTyp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgChgTyp.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgChgTyp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgChgTyp.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgCoastActivBrkLight(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgCoastActivBrkLight.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgCoastActivBrkLight() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgCoastActivBrkLight.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgDrvMod(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvMod.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgDrvMod() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvMod.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgDrvModConn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvModConn.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgDrvModConn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvModConn.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgDrvModStor(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvModStor.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgDrvModStor() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvModStor.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgDrvSeat(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvSeat.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgDrvSeat() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvSeat.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgDualAuthN(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDualAuthN.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgDualAuthN() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDualAuthN.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgEpdel(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgEpdel.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgEpdel() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgEpdel.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgMaxChgCurr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgMaxChgCurr.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgMaxChgCurr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgMaxChgCurr.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgMotor(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgMotor.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgMotor() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgMotor.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgTyre(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgTyre.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_flgFctCfgTyre() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgTyre.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_flgFnctnConfgEGSM(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFnctnConfgEGSM.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_flgFnctnConfgEGSM() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFnctnConfgEGSM.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_flgFnctnConfgEHB(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFnctnConfgEHB.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_flgFnctnConfgEHB() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgFnctnConfgEHB.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_flgNetConfgABS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgNetConfgABS.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_flgNetConfgABS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_flgNetConfgABS.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_fwfvCcwFlg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvCcwFlg.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_fwfvCcwFlg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvCcwFlg.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_fwfvInitSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvInitSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_fwfvInitSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvInitSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_fwfvMotSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvMotSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_fwfvMotSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvMotSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_fwfvOvrCurrFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvOvrCurrFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_fwfvOvrCurrFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvOvrCurrFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_fwfvOvrTempFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvOvrTempFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_fwfvOvrTempFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvOvrTempFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_fwfvOvrVoltFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvOvrVoltFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_fwfvOvrVoltFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvOvrVoltFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_fwfvRespErr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvRespErr.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_fwfvRespErr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvRespErr.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_fwfvUndVoltFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvUndVoltFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_fwfvUndVoltFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_fwfvUndVoltFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_hcmMainPosBckVoltVldSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hcmMainPosBckVoltVldSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_hcmMainPosBckVoltVldSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hcmMainPosBckVoltVldSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_hcmPtcRlyVoltVldSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hcmPtcRlyVoltVldSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_hcmPtcRlyVoltVldSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hcmPtcRlyVoltVldSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_hvbDCChgCurReqRngUp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hvbDCChgCurReqRngUp.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_hvbDCChgCurReqRngUp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hvbDCChgCurReqRngUp.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_hvbDisChgSopRngUp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hvbDisChgSopRngUp.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_hvbDisChgSopRngUp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hvbDisChgSopRngUp.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_hvbHvilFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hvbHvilFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_hvbHvilFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hvbHvilFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_hvbInPositionDetct1(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hvbInPositionDetct1.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_hvbInPositionDetct1() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hvbInPositionDetct1.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_hvbInPositionDetct2(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hvbInPositionDetct2.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_hvbInPositionDetct2() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hvbInPositionDetct2.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_hvbZeroPwrReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hvbZeroPwrReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_hvbZeroPwrReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_hvbZeroPwrReq.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_ignStsOn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ignStsOn.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_ignStsOn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ignStsOn.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_ignStsStrt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ignStsStrt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_ignStsStrt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ignStsStrt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_ipkOdoBckUpEn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ipkOdoBckUpEn.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_ipkOdoBckUpEn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ipkOdoBckUpEn.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_mhgvCcwFlg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvCcwFlg.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_mhgvCcwFlg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvCcwFlg.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_mhgvInitSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvInitSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_mhgvInitSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvInitSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_mhgvMotSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvMotSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_mhgvMotSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvMotSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_mhgvOvrCurrFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvOvrCurrFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_mhgvOvrCurrFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvOvrCurrFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_mhgvOvrTempFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvOvrTempFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_mhgvOvrTempFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvOvrTempFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_mhgvOvrVoltFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvOvrVoltFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_mhgvOvrVoltFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvOvrVoltFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_mhgvRespErr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvRespErr.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_mhgvRespErr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvRespErr.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_mhgvUndVoltFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvUndVoltFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_mhgvUndVoltFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_mhgvUndVoltFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_obcWakeUpActv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_obcWakeUpActv.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_obcWakeUpActv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_obcWakeUpActv.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_odometerInvalid(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_odometerInvalid.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_odometerInvalid() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_odometerInvalid.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_pepsOnSwtSt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_pepsOnSwtSt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_pepsOnSwtSt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_pepsOnSwtSt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_pepsPduLvlVld(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_pepsPduLvlVld.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_pepsPduLvlVld() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_pepsPduLvlVld.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_pepsRmtCtrlSt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_pepsRmtCtrlSt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_pepsRmtCtrlSt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_pepsRmtCtrlSt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_ptCanBusOff(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ptCanBusOff.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_ptCanBusOff() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_ptCanBusOff.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_pullUpDiagCmpl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_pullUpDiagCmpl.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_pullUpDiagCmpl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_pullUpDiagCmpl.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_rfrSwapBatReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_rfrSwapBatReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_rfrSwapBatReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_rfrSwapBatReq.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_rstAvgPwrConsumption(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_rstAvgPwrConsumption.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_rstAvgPwrConsumption() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_rstAvgPwrConsumption.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_tboxPowOffCmd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_tboxPowOffCmd.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_tboxPowOffCmd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_tboxPowOffCmd.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_b_tboxPrtFullSwStUB(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_tboxPrtFullSwStUB.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_b_tboxPrtFullSwStUB() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_b_tboxPrtFullSwStUB.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_d_bcmOdometerbackup(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_d_bcmOdometerbackup.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_d_bcmOdometerbackup() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_d_bcmOdometerbackup.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_d_ipkOdometerbackup(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_d_ipkOdometerbackup.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_d_ipkOdometerbackup() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_d_ipkOdometerbackup.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_d_odometer_km(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_d_odometer_km.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_d_odometer_km() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_d_odometer_km.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_i_dcdcInpCurr_A(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_i_dcdcInpCurr_A.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_i_dcdcInpCurr_A() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_i_dcdcInpCurr_A.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_i_hvbCurr_A(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_i_hvbCurr_A.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_i_hvbCurr_A() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_i_hvbCurr_A.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_i_hvbDCChgCurReq_A(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_i_hvbDCChgCurReq_A.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_i_hvbDCChgCurReq_A() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_i_hvbDCChgCurReq_A.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_l_whlRad_m(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_l_whlRad_m.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_l_whlRad_m() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_l_whlRad_m.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_num_hvbCellMaxID(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_num_hvbCellMaxID.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_num_hvbCellMaxID() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_num_hvbCellMaxID.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_num_hvbCellMinID(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_num_hvbCellMinID.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_num_hvbCellMinID() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_num_hvbCellMinID.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_num_hvbCellSum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_num_hvbCellSum.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_num_hvbCellSum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_num_hvbCellSum.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_num_hvbMaxTempID(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_num_hvbMaxTempID.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_num_hvbMaxTempID() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_num_hvbMaxTempID.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_num_hvbMinTempID(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_num_hvbMinTempID.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_num_hvbMinTempID() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_num_hvbMinTempID.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_num_hvbTempSum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_num_hvbTempSum.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_num_hvbTempSum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_num_hvbTempSum.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_pct_GearPosn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_GearPosn.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_pct_GearPosn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_GearPosn.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_pct_HVILReturnPWM(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_HVILReturnPWM.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_pct_HVILReturnPWM() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_HVILReturnPWM.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_pct_WatPmpEP1FbPWM(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_WatPmpEP1FbPWM.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_pct_WatPmpEP1FbPWM() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_WatPmpEP1FbPWM.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_pct_WatPmpEP2FbPWM(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_WatPmpEP2FbPWM.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_pct_WatPmpEP2FbPWM() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_WatPmpEP2FbPWM.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_pct_WatPmpEP3FbPWM(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_WatPmpEP3FbPWM.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_pct_WatPmpEP3FbPWM() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_WatPmpEP3FbPWM.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_pct_fan1Fb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_fan1Fb.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_pct_fan1Fb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_fan1Fb.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_pct_fan2Fb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_fan2Fb.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_pct_fan2Fb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_fan2Fb.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_pct_fwfvCrtPos(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_fwfvCrtPos.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_pct_fwfvCrtPos() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_fwfvCrtPos.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_pct_mhgvCrtPos(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_mhgvCrtPos.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_pct_mhgvCrtPos() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_mhgvCrtPos.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_pct_mmiLocBkChgTarVal(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_mmiLocBkChgTarVal.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_pct_mmiLocBkChgTarVal() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_mmiLocBkChgTarVal.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_pct_tboxAlwChgCurrMax(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_tboxAlwChgCurrMax.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_pct_tboxAlwChgCurrMax() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_tboxAlwChgCurrMax.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_pct_tboxChgDepth(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_tboxChgDepth.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_pct_tboxChgDepth() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pct_tboxChgDepth.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_pwr_PTCActPwr_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pwr_PTCActPwr_kW.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_pwr_PTCActPwr_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pwr_PTCActPwr_kW.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_pwr_acwpHeatPower_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pwr_acwpHeatPower_kW.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_pwr_acwpHeatPower_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pwr_acwpHeatPower_kW.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_pwr_airCmprAct_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pwr_airCmprAct_kW.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_pwr_airCmprAct_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pwr_airCmprAct_kW.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_pwr_iptActPwr_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pwr_iptActPwr_kW.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_pwr_iptActPwr_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pwr_iptActPwr_kW.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_pwr_ptcActPwrRear_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pwr_ptcActPwrRear_kW.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_pwr_ptcActPwrRear_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_pwr_ptcActPwrRear_kW.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_24vDcdcModAct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_24vDcdcModAct.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_24vDcdcModAct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_24vDcdcModAct.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_BmsTempOutOfCtrlFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_BmsTempOutOfCtrlFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_BmsTempOutOfCtrlFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_BmsTempOutOfCtrlFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_TBOXFunAntiDismantleActive(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_TBOXFunAntiDismantleActive.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_TBOXFunAntiDismantleActive() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_TBOXFunAntiDismantleActive.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_TBOXFunLockVehActive(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_TBOXFunLockVehActive.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_TBOXFunLockVehActive() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_TBOXFunLockVehActive.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_TBOXLockLimSet(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_TBOXLockLimSet.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_TBOXLockLimSet() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_TBOXLockLimSet.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_TBOXLockResultResp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_TBOXLockResultResp.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_TBOXLockResultResp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_TBOXLockResultResp.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_TBOXLockVehCtrl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_TBOXLockVehCtrl.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_TBOXLockVehCtrl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_TBOXLockVehCtrl.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_TBOXLockVehType(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_TBOXLockVehType.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_TBOXLockVehType() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_TBOXLockVehType.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_actWorkSts1(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_actWorkSts1.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_actWorkSts1() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_actWorkSts1.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_batLowSoc2(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_batLowSoc2.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_batLowSoc2() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_batLowSoc2.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_batOvrSoc2(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_batOvrSoc2.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_batOvrSoc2() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_batOvrSoc2.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_batOvrVolt2(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_batOvrVolt2.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_batOvrVolt2() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_batOvrVolt2.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_batUdrVolt2(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_batUdrVolt2.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_batUdrVolt2() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_batUdrVolt2.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_bbmFltSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bbmFltSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_bbmFltSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bbmFltSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_bbmWorkSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bbmWorkSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_bbmWorkSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bbmWorkSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_bmsBattPackMatchFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bmsBattPackMatchFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_bmsBattPackMatchFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bmsBattPackMatchFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_bmsBattPackNum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bmsBattPackNum.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_bmsBattPackNum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bmsBattPackNum.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_bmsBattSysNum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bmsBattSysNum.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_bmsBattSysNum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bmsBattSysNum.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_bmsDlyDataUpldEnb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bmsDlyDataUpldEnb.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_bmsDlyDataUpldEnb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bmsDlyDataUpldEnb.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_bmsTboxFireAlm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bmsTboxFireAlm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_bmsTboxFireAlm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_bmsTboxFireAlm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_cellOverVolt2(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_cellOverVolt2.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_cellOverVolt2() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_cellOverVolt2.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_cellUdrVolt2(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_cellUdrVolt2.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_cellUdrVolt2() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_cellUdrVolt2.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_csmEngRecReqInvalid(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_csmEngRecReqInvalid.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_csmEngRecReqInvalid() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_csmEngRecReqInvalid.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_csmRgnLvlSet(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_csmRgnLvlSet.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_csmRgnLvlSet() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_csmRgnLvlSet.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_dcChgCcSt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_dcChgCcSt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_dcChgCcSt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_dcChgCcSt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_dccAccyConnStsFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_dccAccyConnStsFb.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_dccAccyConnStsFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_dccAccyConnStsFb.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_eadInv2FltSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_eadInv2FltSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_eadInv2FltSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_eadInv2FltSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_eadInv2TempHiAlrm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_eadInv2TempHiAlrm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_eadInv2TempHiAlrm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_eadInv2TempHiAlrm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_egsmShftLvrFailSt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_egsmShftLvrFailSt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_egsmShftLvrFailSt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_egsmShftLvrFailSt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_ehbBrkSysErrFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ehbBrkSysErrFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_ehbBrkSysErrFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ehbBrkSysErrFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_ehbIsaSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ehbIsaSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_ehbIsaSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ehbIsaSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_epsEpasFail(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_epsEpasFail.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_epsEpasFail() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_epsEpasFail.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_flg2FctCfgVehTyp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flg2FctCfgVehTyp.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_flg2FctCfgVehTyp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flg2FctCfgVehTyp.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgAccy(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgAccy.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgAccy() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgAccy.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgBatTyp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgBatTyp.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgBatTyp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgBatTyp.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgDspRemainRng(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgDspRemainRng.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgDspRemainRng() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgDspRemainRng.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgECOMaxSpd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgECOMaxSpd.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgECOMaxSpd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgECOMaxSpd.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgFan(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgFan.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgFan() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgFan.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgMaxSpd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgMaxSpd.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgMaxSpd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgMaxSpd.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgMotTyp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgMotTyp.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgMotTyp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgMotTyp.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgPowerMaxSpd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgPowerMaxSpd.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgPowerMaxSpd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgPowerMaxSpd.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgSlowChg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgSlowChg.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgSlowChg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgSlowChg.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgV2L(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgV2L.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgV2L() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgV2L.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgVehCfg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehCfg.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgVehCfg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehCfg.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgVehTyp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehTyp.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgVehTyp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehTyp.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgVehUsg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehUsg.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_flgFctCfgVehUsg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehUsg.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hcmAccConnStsFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hcmAccConnStsFb.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hcmAccConnStsFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hcmAccConnStsFb.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hcmHvilSt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hcmHvilSt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hcmHvilSt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hcmHvilSt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hcmPTC1ConnStsFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hcmPTC1ConnStsFb.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hcmPTC1ConnStsFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hcmPTC1ConnStsFb.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hcmPtcDefRlyStFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hcmPtcDefRlyStFb.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hcmPtcDefRlyStFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hcmPtcDefRlyStFb.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbBatUniformity(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbBatUniformity.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbBatUniformity() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbBatUniformity.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbBattIsolationSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbBattIsolationSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbBattIsolationSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbBattIsolationSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbCellTempDevFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbCellTempDevFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbCellTempDevFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbCellTempDevFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbCellVoltDevFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbCellVoltDevFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbCellVoltDevFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbCellVoltDevFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbChgCcsts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbChgCcsts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbChgCcsts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbChgCcsts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbChgFltReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbChgFltReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbChgFltReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbChgFltReq.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbChgOvrCurr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbChgOvrCurr.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbChgOvrCurr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbChgOvrCurr.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbChgSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbChgSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbChgSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbChgSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbDCChgPlgNOvrTmp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbDCChgPlgNOvrTmp.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbDCChgPlgNOvrTmp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbDCChgPlgNOvrTmp.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbDCChgPlgPOvrTmp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbDCChgPlgPOvrTmp.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbDCChgPlgPOvrTmp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbDCChgPlgPOvrTmp.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbDCChgProcss(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbDCChgProcss.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbDCChgProcss() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbDCChgProcss.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbDischgFltReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbDischgFltReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbDischgFltReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbDischgFltReq.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbInslErr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbInslErr.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbInslErr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbInslErr.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbOvrChgFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbOvrChgFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbOvrChgFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbOvrChgFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbPreChgSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbPreChgSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbPreChgSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbPreChgSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbSocFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbSocFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbSocFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbSocFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbSocJumpFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbSocJumpFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbSocJumpFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbSocJumpFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbStatus(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbStatus.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbStatus() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbStatus.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbStsChgFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbStsChgFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbStsChgFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbStsChgFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbStsDischgFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbStsDischgFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbStsDischgFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbStsDischgFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbTempFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbTempFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbTempFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbTempFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_hvbThermMngReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbThermMngReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_hvbThermMngReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_hvbThermMngReq.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_ipkAlwChgSftCtlSt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipkAlwChgSftCtlSt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_ipkAlwChgSftCtlSt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipkAlwChgSftCtlSt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_ipkChgSftSwCtlSt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipkChgSftSwCtlSt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_ipkChgSftSwCtlSt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipkChgSftSwCtlSt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_ipkCruisingDstSwt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipkCruisingDstSwt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_ipkCruisingDstSwt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipkCruisingDstSwt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_ipuInvTempHighAlm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipuInvTempHighAlm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_ipuInvTempHighAlm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipuInvTempHighAlm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_ipuMotTempHighFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipuMotTempHighFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_ipuMotTempHighFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipuMotTempHighFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_ipuMotorOverCurrFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipuMotorOverCurrFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_ipuMotorOverCurrFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipuMotorOverCurrFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_ipuMotorOverSpdFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipuMotorOverSpdFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_ipuMotorOverSpdFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ipuMotorOverSpdFlt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_mmiRestSwitch(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_mmiRestSwitch.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_mmiRestSwitch() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_mmiRestSwitch.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_obcChgCCSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_obcChgCCSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_obcChgCCSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_obcChgCCSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_obcChgSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_obcChgSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_obcChgSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_obcChgSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_obcElckStMod(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_obcElckStMod.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_obcElckStMod() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_obcElckStMod.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_obcOnBdCCline(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_obcOnBdCCline.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_obcOnBdCCline() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_obcOnBdCCline.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_obcOnBdDchaCCline(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_obcOnBdDchaCCline.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_obcOnBdDchaCCline() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_obcOnBdDchaCCline.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_pepsPduLvl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_pepsPduLvl.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_pepsPduLvl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_pepsPduLvl.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_pepsPduLvlVld(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_pepsPduLvlVld.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_pepsPduLvlVld() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_pepsPduLvlVld.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_pepsRKECom(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_pepsRKECom.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_pepsRKECom() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_pepsRKECom.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_ptcConnStsFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ptcConnStsFb.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_ptcConnStsFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_ptcConnStsFb.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_rfrConnctSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_rfrConnctSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_rfrConnctSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_rfrConnctSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_rfrSwapprocd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_rfrSwapprocd.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_rfrSwapprocd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_rfrSwapprocd.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_tboxChgLmtSw(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxChgLmtSw.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_tboxChgLmtSw() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxChgLmtSw.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_tboxChgSftSwCtlSt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxChgSftSwCtlSt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_tboxChgSftSwCtlSt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxChgSftSwCtlSt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_tboxInventorySpdLmtReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxInventorySpdLmtReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_tboxInventorySpdLmtReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxInventorySpdLmtReq.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_tboxLife(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxLife.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_tboxLife() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxLife.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_tboxLockVehPerFlag(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxLockVehPerFlag.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_tboxLockVehPerFlag() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxLockVehPerFlag.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_tboxPrtFullSwSt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxPrtFullSwSt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_tboxPrtFullSwSt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxPrtFullSwSt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_tboxRsrChgSt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxRsrChgSt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_tboxRsrChgSt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxRsrChgSt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_tboxSpdLmtLevelReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxSpdLmtLevelReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_tboxSpdLmtLevelReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxSpdLmtLevelReq.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_tboxStartBattChgReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxStartBattChgReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_tboxStartBattChgReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxStartBattChgReq.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_tboxVersionConversionFlag(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxVersionConversionFlag.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_tboxVersionConversionFlag() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_tboxVersionConversionFlag.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_st_vscEHBAVHSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_vscEHBAVHSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_st_vscEHBAVHSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_st_vscEHBAVHSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_t_TS5sensorFb_C(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_TS5sensorFb_C.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_t_TS5sensorFb_C() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_TS5sensorFb_C.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_t_acwpOutptTemp_C(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_acwpOutptTemp_C.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_t_acwpOutptTemp_C() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_acwpOutptTemp_C.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_t_hvbCooltInTemp_C(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_hvbCooltInTemp_C.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_t_hvbCooltInTemp_C() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_hvbCooltInTemp_C.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_t_hvbCooltOutTemp_C(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_hvbCooltOutTemp_C.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_t_hvbCooltOutTemp_C() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_hvbCooltOutTemp_C.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_t_hvbMax_C(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_hvbMax_C.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_t_hvbMax_C() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_hvbMax_C.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_t_hvbMin_C(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_hvbMin_C.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_t_hvbMin_C() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_hvbMin_C.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_t_hvbOutCoolTemp_C(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_hvbOutCoolTemp_C.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_t_hvbOutCoolTemp_C() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_hvbOutCoolTemp_C.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_t_hvbSetTgtTemp_C(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_hvbSetTgtTemp_C.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_t_hvbSetTgtTemp_C() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_t_hvbSetTgtTemp_C.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_tm_hvbFnshChgTim_m(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_tm_hvbFnshChgTim_m.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_tm_hvbFnshChgTim_m() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_tm_hvbFnshChgTim_m.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_tq_ehbIsaPtTrqDecReq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_tq_ehbIsaPtTrqDecReq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_tq_ehbIsaPtTrqDecReq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_tq_ehbIsaPtTrqDecReq_Nm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_5VT1IntSmpl_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_5VT1IntSmpl_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_5VT1IntSmpl_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_5VT1IntSmpl_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_5VT2IntSmpl_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_5VT2IntSmpl_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_5VT2IntSmpl_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_5VT2IntSmpl_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_Acc1Raw_mV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_Acc1Raw_mV.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_Acc1Raw_mV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_Acc1Raw_mV.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_Acc2Raw_mV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_Acc2Raw_mV.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_Acc2Raw_mV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_Acc2Raw_mV.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_BmsMaxCellVolt_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_BmsMaxCellVolt_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_BmsMaxCellVolt_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_BmsMaxCellVolt_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_BmsMinCellVolt_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_BmsMinCellVolt_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_BmsMinCellVolt_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_BmsMinCellVolt_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_Brk2Raw_mV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_Brk2Raw_mV.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_Brk2Raw_mV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_Brk2Raw_mV.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_Brk2_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_Brk2_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_Brk2_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_Brk2_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_BrkRaw_mV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_BrkRaw_mV.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_BrkRaw_mV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_BrkRaw_mV.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_Brk_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_Brk_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_Brk_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_Brk_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_TS5sensorFb_mV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_TS5sensorFb_mV.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_TS5sensorFb_mV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_TS5sensorFb_mV.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_VacTkAirPres_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_VacTkAirPres_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_VacTkAirPres_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_VacTkAirPres_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_VacTkEnFb_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_VacTkEnFb_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_VacTkEnFb_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_VacTkEnFb_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_accPdlSens1InpVolt_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_accPdlSens1InpVolt_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_accPdlSens1InpVolt_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_accPdlSens1InpVolt_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_accPdlSens2InpVolt_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_accPdlSens2InpVolt_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_accPdlSens2InpVolt_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_accPdlSens2InpVolt_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_batLpPmpCtrlFb_mV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_batLpPmpCtrlFb_mV.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_batLpPmpCtrlFb_mV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_batLpPmpCtrlFb_mV.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_brkVacuumPres_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_brkVacuumPres_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_brkVacuumPres_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_brkVacuumPres_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_cbnLpPmpCtrlFb_mV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_cbnLpPmpCtrlFb_mV.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_cbnLpPmpCtrlFb_mV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_cbnLpPmpCtrlFb_mV.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_dcdcRelayVolt_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_dcdcRelayVolt_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_dcdcRelayVolt_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_dcdcRelayVolt_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_eLpWpCtrlCur_mV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_eLpWpCtrlCur_mV.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_eLpWpCtrlCur_mV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_eLpWpCtrlCur_mV.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_hcmAcceRlyVolt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hcmAcceRlyVolt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_hcmAcceRlyVolt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hcmAcceRlyVolt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_hcmMainPosBckVolt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hcmMainPosBckVolt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_hcmMainPosBckVolt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hcmMainPosBckVolt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_hcmPtcRlyVolt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hcmPtcRlyVolt.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_hcmPtcRlyVolt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hcmPtcRlyVolt.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_hvbCooltInSnsr_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hvbCooltInSnsr_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_hvbCooltInSnsr_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hvbCooltInSnsr_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_hvbCooltOutSnsr_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hvbCooltOutSnsr_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_hvbCooltOutSnsr_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hvbCooltOutSnsr_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_hvbPackVolt_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hvbPackVolt_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_hvbPackVolt_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hvbPackVolt_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_hvbVolt_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hvbVolt_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_hvbVolt_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_hvbVolt_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_ipuHVBusVolt_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_ipuHVBusVolt_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_ipuHVBusVolt_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_ipuHVBusVolt_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_pepsOn_mV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_pepsOn_mV.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_pepsOn_mV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_pepsOn_mV.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_u_vacTkPowSup_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_vacTkPowSup_V.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_u_vacTkPowSup_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_u_vacTkPowSup_V.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vild_v_ehbVehSpd_kph(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_v_ehbVehSpd_kph.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vild_v_ehbVehSpd_kph() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vild_v_ehbVehSpd_kph.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_a_vscLongitAcce_mps2(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_a_vscLongitAcce_mps2.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_a_vscLongitAcce_mps2() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_a_vscLongitAcce_mps2.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_b_ESPActv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ESPActv.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_b_ESPActv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ESPActv.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_b_ESPActvRaw(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ESPActvRaw.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_b_ESPActvRaw() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ESPActvRaw.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_b_ehbAbsOvrdActv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbAbsOvrdActv.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_b_ehbAbsOvrdActv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbAbsOvrdActv.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_b_ehbAebActv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbAebActv.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_b_ehbAebActv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbAebActv.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_b_ehbDtcActv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbDtcActv.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_b_ehbDtcActv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbDtcActv.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_b_ehbTrqDecReqActv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbTrqDecReqActv.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_b_ehbTrqDecReqActv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbTrqDecReqActv.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_b_ehbTrqIncReqActv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbTrqIncReqActv.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_b_ehbTrqIncReqActv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbTrqIncReqActv.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_b_ehbVlcActv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbVlcActv.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_b_ehbVlcActv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbVlcActv.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_b_ehbVlcAvailb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbVlcAvailb.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_b_ehbVlcAvailb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbVlcAvailb.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_b_ehbVlcTrqReqActv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbVlcTrqReqActv.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_b_ehbVlcTrqReqActv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_ehbVlcTrqReqActv.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_b_pdcBrkFlg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_pdcBrkFlg.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_b_pdcBrkFlg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_pdcBrkFlg.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_b_vehSlipWarn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_vehSlipWarn.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_b_vehSlipWarn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_vehSlipWarn.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_b_vehSpdVld(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_vehSpdVld.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_b_vehSpdVld() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_vehSpdVld.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_b_vscBrkLghtActv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_vscBrkLghtActv.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_b_vscBrkLghtActv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_b_vscBrkLghtActv.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_st_ehbAVHSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_st_ehbAVHSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_st_ehbAVHSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_st_ehbAVHSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_st_ehbEPBDynAppSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_st_ehbEPBDynAppSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_st_ehbEPBDynAppSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_st_ehbEPBDynAppSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_st_ehbHHCActive(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_st_ehbHHCActive.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_st_ehbHHCActive() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_st_ehbHHCActive.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_st_ehbMbRgnTgtWhlSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_st_ehbMbRgnTgtWhlSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_st_ehbMbRgnTgtWhlSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_st_ehbMbRgnTgtWhlSts.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_st_vscIsgActvDampModReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_st_vscIsgActvDampModReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_st_vscIsgActvDampModReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_st_vscIsgActvDampModReq.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_tq_axle2MaxTqReq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_axle2MaxTqReq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_tq_axle2MaxTqReq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_axle2MaxTqReq_Nm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_tq_axle2MinTqReq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_axle2MinTqReq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_tq_axle2MinTqReq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_axle2MinTqReq_Nm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_tq_axle2RgnBrkTqReq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_axle2RgnBrkTqReq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_tq_axle2RgnBrkTqReq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_axle2RgnBrkTqReq_Nm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_tq_ehbMbRgnTgtWhl_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_ehbMbRgnTgtWhl_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_tq_ehbMbRgnTgtWhl_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_ehbMbRgnTgtWhl_Nm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_tq_ehbTrqDecReq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_ehbTrqDecReq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_tq_ehbTrqDecReq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_ehbTrqDecReq_Nm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_tq_ehbTrqIncReq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_ehbTrqIncReq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_tq_ehbTrqIncReq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_ehbTrqIncReq_Nm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_tq_ehbVlcTrqReq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_ehbVlcTrqReq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_tq_ehbVlcTrqReq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_tq_ehbVlcTrqReq_Nm.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_v_vehSpdRaw_kph(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_v_vehSpdRaw_kph.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_v_vehSpdRaw_kph() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_v_vehSpdRaw_kph.value \
)

#define Rte_IWrite_swc_VCIP_Step_vcib_VCIP_vscd_v_vehSpd_kph(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value = (data) \
)

#define Rte_IWriteRef_swc_VCIP_Step_vcib_VCIP_vscd_v_vehSpd_kph() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value \
)

#define Rte_IRead_swc_VCIP_Step_vcsb_DIAG_acpd_b_accPed1Vld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcsb_DIAG_acpd_b_accPed1Vld.value)

#define Rte_IRead_swc_VCIP_Step_vcsb_DIAG_acpd_b_accPed2Vld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcsb_DIAG_acpd_b_accPed2Vld.value)

#define Rte_IRead_swc_VCIP_Step_vcsb_DIAG_digd_b_VehLvl32Flt_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcsb_DIAG_digd_b_VehLvl32Flt_flg.value)

#define Rte_IRead_swc_VCIP_Step_vcsb_DIAG_digd_b_VehLvl33Flt_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcsb_DIAG_digd_b_VehLvl33Flt_flg.value)

#define Rte_IRead_swc_VCIP_Step_vcsb_HVSM_dccd_e_modeTgt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcsb_HVSM_dccd_e_modeTgt.value)

#define Rte_IRead_swc_VCIP_Step_vcsb_HVSM_hvbd_b_hvbIntelChgCmplt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcsb_HVSM_hvbd_b_hvbIntelChgCmplt.value)

#define Rte_IRead_swc_VCIP_Step_vcsb_HVSM_hvbd_e_PmmStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcsb_HVSM_hvbd_e_PmmStatus.value)

#define Rte_IRead_swc_VCIP_Step_vcsb_VOMM_drid_e_gearLvrPos() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcsb_VOMM_drid_e_gearLvrPos.value)

#define Rte_IRead_swc_VCIP_Step_vcsb_VOMM_vsmd_b_VehRun() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vcsb_VOMM_vsmd_b_VehRun.value)

#define Rte_IRead_swc_VCIP_Step_vild_b_flgBBMMsgErr_vild_b_flgBBMMsgErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vild_b_flgBBMMsgErr_vild_b_flgBBMMsgErr.value)

#define Rte_IRead_swc_VCIP_Step_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr.value)

#define Rte_IRead_swc_VCIP_Step_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr.value)

#define Rte_IRead_swc_VCIP_Step_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCIP_swc_VCIP_Step.Rte_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr.value)

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
FUNC(void, swc_VCIP_CODE) swc_VCIP_Step(void);
FUNC(void, swc_VCIP_CODE) swc_VCIP_Init(void);
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
#endif /* RTE_SWC_VCIP_H_ */
 
 
 

/*
 * File: swc_VOMM.h
 *
 * Code generated for Simulink model 'swc_VOMM'.
 *
 * Model version                  : 6.171
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Aug 21 15:54:36 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_swc_VOMM_h_
#define RTW_HEADER_swc_VOMM_h_
#ifndef swc_VOMM_COMMON_INCLUDES_
#define swc_VOMM_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_swc_VOMM.h"
#endif                                 /* swc_VOMM_COMMON_INCLUDES_ */

#include "Rte_Type.h"

/* Includes for objects with custom storage classes */
#include "const_ImportedDefine.h"

/* user code (top of header file) */
#include "Platform_Types.h"
#include "enum_Type.h"
#include "Rte_swc_rte_dem.h"
#include "Aes_Encypt.h"
#include "AES_Lib.h"
#ifndef DEFINED_TYPEDEF_FOR_vcib_VCIP_
#define DEFINED_TYPEDEF_FOR_vcib_VCIP_

typedef struct {
  uint8 vild_st_TBOXLockVehCtrl;
  uint8 vild_st_tboxInventorySpdLmtReq;
  uint8 vild_st_TBOXLockVehType;
  uint8 vild_st_TBOXFunLockVehActive;
  uint8 vild_st_TBOXFunAntiDismantleActive;
  uint8 vild_st_TBOXLockLimSet;
  uint8 vild_st_TBOXLockResultResp;
  uint8 vild_st_tboxLockVehPerFlag;
  uint8 vild_st_tboxVersionConversionFlag;
  uint8 vild_st_tboxSpdLmtLevelReq;
  uint8 vild_st_tboxStartBattChgReq;
  uint8 vild_st_tboxLife;
  uint8 vild_st_FnCfgDstFnclLck;
  float32 brpd_p_AirPres_kpa;
  boolean ccdd_b_extCtrlAvail;
  boolean vild_b_driverEVModeReq;
  float32 hvbd_pwr_accyPwrFilter_kW;
  boolean tmmd_b_testinvModeReq;
  boolean vscd_b_ESPActvRaw;
  FanStatus accd_e_acFanReq;
  FaultStatus accd_e_acFaultStatus;
  boolean accd_b_engStrtReq;
  float32 accd_pwr_hvacPwrAct_kW;
  float32 accd_pwr_hvacPwrDem_kW;
  float32 accd_pwr_hvacPwrDemMin_kW;
  uint8 accd_st_ptcHeatReq;
  float32 accd_t_ambTemp_C;
  float32 accd_p_acPres_kPa;
  uint8 accd_st_frtWdshldDefReq;
  uint8 accd_st_AcWrk;
  uint8 accd_st_cbnThermMngReq;
  uint8 accd_st_hiLoPrsSwtSt;
  uint8 accd_st_acMidPresSwt;
  float32 accd_t_acInTempSet_C;
  McuSts accd_e_airCmprSt;
  McuSts accd_e_PtcSt;
  float32 accd_u_acPresVolt_V;
  boolean accd_b_acHvilOpn;
  float32 accd_t_acEvapTemp_C;
  uint8 accd_num_airCmpFltCode;
  uint8 accd_num_ptcFltCode;
  FaultStatus accd_e_airCmpFltLvl;
  FaultStatus accd_e_ptcFltLvl;
  uint8 accd_st_airCmprSt;
  FaultStatus accd_e_acFltLvl;
  uint8 accd_st_acSubFltSts;
  boolean accd_b_BPTCHvilOpn;
  boolean accd_b_ptcHvLoopFlt;
  boolean accd_b_accmHvLoopFlt;
  boolean acpd_b_accPedlPosVld;
  float32 acpd_x_accPedlPosSens1_pct;
  float32 acpd_x_accPedlPosSens2_pct;
  float32 acpd_x_accPedlPos_pct;
  float32 acpd_x_accPedlPosLimd_pct;
  float32 acpd_u_accPedlPosSens1VoltRaw_V;
  float32 acpd_u_accPedlPosSens2VoltRaw_V;
  float32 acpd_x_accPedlPosCan_pct;
  BrakePedalStatus brpd_e_brkPedalStatus;
  boolean brpd_b_brakeSwitch1Closed;
  boolean brpd_b_brakeSwitch2Closed;
  boolean brpd_b_brkPresValid;
  float32 brpd_p_brkPres_bar;
  float32 brpd_p_brkVacuumPres_bar;
  float32 brpd_x_brkPedlPos_pct;
  boolean brpd_b_brkPedlPosVld;
  boolean brpd_b_brkPedlStsVld;
  uint8 brpd_st_bdcacWrk;
  boolean brpd_b_DryAirSwitch;
  boolean brpd_b_ResrAirSwitch;
  uint8 brpd_st_brkPmpFltLvl;
  boolean brpd_b_brkPumpFault;
  float32 brpd_pwr_brkPumpOpt_kW;
  boolean brpd_b_brkPressedFromSwitch;
  McuSts brpd_e_bdcacWrk;
  boolean brpd_b_brkPmpSelfChkOk;
  boolean brpd_b_brkPmpSelfChkErr;
  boolean brpd_b_vacTankLowPrs;
  boolean ccdd_b_crzCtrlActv;
  float32 ccdd_tq_crzCtrlTqReq_Nm;
  float32 ccdd_v_crzCtrlSpdLim_kph;
  float32 ccdd_u_cruiseADvoltage_V;
  boolean cesd_b_airbagActive;
  uint8 cesd_st_crashSts;
  boolean cesd_b_EmergencyStop;
  boolean cesd_b_crash;
  FaultStatus dccd_e_dcdcFaultStatus;
  DCDCMode dccd_e_modeAct;
  float32 dccd_pwr_ActHV_kW;
  float32 dccd_pwr_ActLV_kW;
  float32 dccd_t_dcdcTemp_C;
  float32 dccd_u_dcdcLVBusAct_V;
  float32 dccd_u_dcdcHVBusAct_V;
  uint8 dccd_st_12vDcdcModAct;
  uint8 dccd_st_24vDcdcModAct;
  uint8 dccd_st_24vDcdcFltSts;
  float32 dccd_pwr_24vDcdcOpt_kW;
  McuSts dccd_e_24vDcdcModAct;
  boolean dccd_b_dcdcSelfChkOk;
  boolean dccd_b_dcdcSelfChkErr;
  boolean dccd_b_dcdcHvilFlt;
  boolean dccd_b_dcdcCutOffLvFb;
  uint8 dccd_st_24vDcdcSubFltSts;
  boolean drid_b_drvrModeReqEV;
  boolean drid_b_drvrModeReqHEV;
  boolean drid_b_drvrModeReqECO;
  boolean drid_b_drvrModeReqSPORT;
  boolean drid_b_drvrModeReq4WD;
  uint8 drid_b_parkBtnPressed;
  GearLeverPos drid_e_gearLvrPosRaw;
  uint8 drid_st_gearLvrPosSeql;
  boolean drid_b_revModeSwitch;
  boolean drid_b_pfcuLowIdle;
  boolean drid_b_pfcuHighIdle;
  boolean drid_b_EVModeButtonPressed;
  boolean drid_b_EVModeButtonCircuitFlt;
  boolean drid_b_SmartModeButtonPressed;
  boolean drid_b_SmartModeButtonCircuitFlt;
  boolean drid_b_SaveModeButtonPressed;
  boolean drid_b_SaveModeButtonCircuitFlt;
  boolean drid_b_RECModeButtonPressed;
  boolean drid_b_RECModeButtonCircuitFlt;
  FaultStatus eadd_e_inv1FltSts;
  ElMac eadd_e_inv1ModeAct;
  boolean eadd_b_inv1Active;
  boolean eadd_b_inv1HVRdy;
  float32 eadd_n_mot1ActSpd_rpm;
  float32 eadd_tq_mot1ActTq_Nm;
  float32 eadd_tq_mot1MaxAvailLTBst_Nm;
  float32 eadd_tq_mot1MaxAvailSTBst_Nm;
  float32 eadd_tq_mot1MaxAvailLTBrk_Nm;
  float32 eadd_tq_mot1MaxAvailSTBrk_Nm;
  float32 eadd_t_inv1Temp_C;
  float32 eadd_t_mot1Temp_C;
  float32 eadd_t_ead1CooltTemp_C;
  float32 eadd_u_busInv1HVAct_V;
  float32 eadd_pwr_mot1ActPwr_kW;
  float32 eadd_fact_mot1GearRat;
  uint8 eadd_st_eadInv1Sts;
  FaultStatus eadd_e_inv2FltSts;
  ElMac eadd_e_inv2ModeAct;
  boolean eadd_b_inv2Active;
  boolean eadd_b_inv2HVRdy;
  float32 eadd_n_mot2ActSpd_rpm;
  float32 eadd_tq_mot2ActTq_Nm;
  float32 eadd_tq_mot2MaxAvailLTBst_Nm;
  float32 eadd_tq_mot2MaxAvailSTBst_Nm;
  float32 eadd_tq_mot2MaxAvailLTBrk_Nm;
  float32 eadd_tq_mot2MaxAvailSTBrk_Nm;
  float32 eadd_t_inv2Temp_C;
  float32 eadd_t_mot2Temp_C;
  float32 eadd_t_ead2CooltTemp_C;
  float32 eadd_u_busInv2HVAct_V;
  float32 eadd_pwr_mot2ActPwr_kW;
  float32 eadd_fact_mot2GearRat;
  boolean eadd_st_eadInv2Sts;
  float32 eadd_pwr_mot21ActPwr_kW;
  float32 eadd_i_eadInv2ActCurrDC_A;
  FaultStatus eadd_e_inv21FltSts;
  float32 eadd_n_mot21ActSpd_rpm;
  float32 eadd_tq_mot21ActTq_Nm;
  uint8 eadd_st_eadInv2WrkMod;
  McuSts eadd_e_eadInv2Sts;
  boolean eadd_b_eadInv2SelfChkOk;
  boolean eadd_b_motPrevnSlipFlg;
  boolean eadd_b_eadMot2SysOvrLd;
  boolean eadd_b_eadInv2SelfChkErr;
  uint8 eadd_st_eadInv2PwrActvMod;
  boolean eadd_b_eadInv2RdyToCutOffLV;
  uint8 eadd_st_inv2SubFltSts;
  uint8 eadd_st_eadMot2ImmoRlsChk;
  boolean eadd_b_eadInv2HVLFlt;
  FanStatus engd_e_engFanReq;
  FaultStatus engd_e_engFltSts;
  float32 engd_fact_engMaxNorm2Tq;
  boolean engd_b_engBattVoltVld;
  boolean engd_b_engCooltTempVld;
  boolean engd_b_engSpdVld;
  boolean engd_b_engStopInhb;
  boolean engd_b_engStrtComplete;
  boolean engd_b_engTqVld;
  float32 engd_n_engSpd_rpm;
  float32 engd_tq_crsEngAvailTq_Nm;
  float32 engd_tq_crsEngLossTq_Nm;
  float32 engd_tq_crsEngMaxTq_Nm;
  float32 engd_tq_crsEngMinTq_Nm;
  float32 engd_tq_crsEngActTq_Nm;
  float32 engd_t_engCooltTemp_C;
  EngineState engd_e_engStFromCan;
  float32 engd_V_engFuelConsInst_ml;
  float32 engd_t_apuEngCooltTemp_C;
  uint8 engd_st_apuFltLvl;
  float32 engd_n_apuEngActSpd_rpm;
  float32 engd_t_apuEngInAirTmp_C;
  float32 engd_pwr_apuMaxPwrPrmt_kW;
  boolean engd_b_apuCutOffLvFb;
  uint8 engd_st_apuActWrkSt;
  float32 engd_dV_engFuelCns_lph;
  boolean engd_b_apuSelfChkOk;
  uint8 engd_st_apuStrtFaild;
  float32 engd_pwr_apuActPwrFb_kW;
  boolean engd_b_apuWrmUpReq;
  uint8 engd_st_apuGPFReq;
  boolean engd_b_apuWrmUpAchvd;
  boolean engd_b_apuRunng;
  boolean engd_b_fuTankUnlock;
  boolean engd_b_parkGPFReq;
  boolean engd_b_apuSttTest;
  boolean engd_b_fuTankLock;
  boolean engd_b_apuSelfChkErr;
  float32 engd_n_engIdleTgtSpd_rpm;
  uint8 engd_st_msgActvDischgFb;
  ParkingStatus epbd_e_parkingSts;
  HVBRelayStatus hvbd_e_hvbChrgRlySts;
  FaultStatus hvbd_e_hvbFaultStatus;
  InsulationStatus hvbd_e_hvbInslStatus;
  HVBRelayStatus hvbd_e_hvbMainRlySts;
  HVBattStatus hvbd_e_hvbStatus;
  boolean hvbd_b_hvbChrgErr;
  boolean hvbd_b_bmsSelfChkOk;
  boolean hvbd_b_hvbRepairIndErr;
  boolean hvbd_b_hvilOpen;
  float32 hvbd_q_hvbSOC_pct;
  float32 hvbd_pwr_PeakChMax_kW;
  float32 hvbd_pwr_PeakDischMax_kW;
  float32 hvbd_pwr_StatChMax_kW;
  float32 hvbd_pwr_StatDischMax_kW;
  float32 hvbd_t_hvbTemp_C;
  float32 hvbd_pwr_hvbAct_kW;
  float32 hvbd_fact_hvbSOH_pct;
  HVBRelayStatus hvbd_e_eadInv1MainRlySts;
  HVBRelayStatus hvbd_e_eadInv2MainRlySts;
  HVBRelayStatus hvbd_e_msgInvMainRlySts;
  HVBRelayStatus hvbd_e_tmmInvMainRlySts;
  HVBRelayStatus hvbd_e_dcdcMainRlySts;
  HVBRelayStatus hvbd_e_hvacMainRlySts;
  boolean hvbd_b_obcChrgReq;
  uint8 hvbd_st_hvbThermMngReq;
  float32 hvbd_t_hvbMin_C;
  uint8 hvbd_st_hcmFltLvl;
  float32 hvbd_i_hvbCurr_A;
  float32 hvbd_t_hvbInCoolTemp_C;
  uint8 hvbd_st_hcmMaiRlyNeg;
  HVBRelayStatus hvbd_e_hcmMaiRlyNeg;
  HVBRelayStatus hvbd_e_hvbMaiRlyNeg;
  HVBRelayStatus hvbd_e_hvbAssiRly;
  HVBRelayStatus hvbd_e_hvbMaiRlyPos;
  McuSts hvbd_e_hcmWrkSt;
  boolean hvbd_b_hcmSelfChkOk;
  boolean hvbd_b_hvbPrmtCutOffLvFb;
  boolean hvbd_b_hcmCutOffLvFb;
  float32 hvbd_t_hvbAvg_C;
  uint8 hvbd_st_hvbPwrActvMod;
  uint8 hvbd_st_hcmPwrActvMod;
  float32 hvbd_pwr_StatChMaxRaw_kW;
  float32 hvbd_pwr_PeakChMaxRaw_kW;
  float32 hvbd_pwr_hvbActRaw_kW;
  boolean hvbd_b_hvbPreChgFin;
  boolean hvbd_b_hvbRlyOpenLdtBev;
  boolean hvbd_b_lowTempProtnReq;
  boolean hvbd_b_dcChgMod;
  boolean hvbd_b_acChgMod;
  boolean hvbd_b_hvbHeatEnad;
  boolean hvbd_b_hvbDischPwrLimdByTemp;
  boolean hvbd_b_bmsSelfChkErr;
  boolean hvbd_b_hcmSelfChkErr;
  boolean hvbd_b_hcmRlyWldFlt;
  boolean hvbd_b_hvbChPwrLimdByTemp;
  boolean hvbd_b_hcmPtcDefRlyCls;
  uint8 hvbd_st_hvbSubFaultSts;
  boolean hvbd_b_tboxIntelChgCmd;
  uint8 hvbd_st_tboxIntelChgQuit;
  boolean hvbd_b_hvbNonPwrFltHVIL;
  float32 lvbd_C_lvbCapacity_Ah;
  boolean lvbd_b_lvbColdTemp;
  float32 lvbd_t_lvbEstTemp_C;
  float32 lvbd_u_dcdcLVBusActFilt_V;
  boolean macd_b_12VStarterRlyFdbk;
  boolean macd_b_TwoWayVlvOn;
  boolean macd_b_ThreeWayVlvOn;
  float32 macd_V_tankFuelLvl_l;
  float32 macd_t_ts5SnsrTemp_C;
  float32 macd_t_ts3SnsrTemp_C;
  float32 macd_t_ts4SnsrTemp_C;
  uint8 macd_st_sdcacWrk;
  uint8 macd_st_epsFltLvl;
  float32 macd_pwr_epsOpt_kW;
  McuSts macd_e_sdcacWrk;
  boolean macd_b_epsSelfChkOk;
  float32 macd_u_batIntSmpl_V;
  float32 macd_u_5VT1IntSmpl_V;
  float32 macd_u_5VT2IntSmpl_V;
  float32 macd_u_5VT3IntSmpl_V;
  float32 macd_u_5VT4IntSmpl_V;
  float32 macd_u_5VT5IntSmpl_V;
  boolean macd_b_pullUpDiagCmpl;
  boolean macd_b_epsSelfChkErr;
  float32 macd_p_frontAirTankPres_bar;
  float32 macd_p_rearAirTankPres_bar;
  boolean macd_b_vcuSelfChkOk;
  float32 macd_ang_strWhlAng_rad;
  uint8 macd_st_epsSubFltLvl;
  uint8 macd_st_epsErrorCode;
  FaultStatus msgd_e_invFaultSts;
  ElMac msgd_e_invModeAct;
  float32 msgd_fact_gearRat;
  boolean msgd_b_invActive;
  boolean msgd_b_invHVReady;
  float32 msgd_n_motAct_rpm;
  float32 msgd_tq_motAct_Nm;
  float32 msgd_tq_motMaxAvlBoost_Nm;
  float32 msgd_tq_motMaxAvlBoostPeak_Nm;
  float32 msgd_tq_motMaxAvlBrake_Nm;
  float32 msgd_tq_motMaxAvlBrakePeak_Nm;
  float32 msgd_t_invTemp_C;
  float32 msgd_t_motTemp_C;
  float32 msgd_u_busHVAct_V;
  float32 msgd_pwr_motAct_kW;
  FaultStatus obcd_e_obcFaultStatus;
  boolean obcd_b_obcCANMsgValid;
  boolean obcd_b_obcChrgCablePlugged;
  boolean obcd_b_obcChrgCableUnplugged;
  boolean obcd_b_obcWakeUp;
  float32 obcd_t_obcTemp_C;
  float32 obcd_pwr_obcStatPwrMax_kW;
  uint8 obcd_st_obcfltLvl;
  boolean obcd_b_obcSelfChkOk;
  boolean obcd_b_obcSelfChkErr;
  KeyAuthStatus pmmd_e_authenticationStatus;
  boolean pmmd_b_anyIgnOn;
  boolean pmmd_b_canIgnOn;
  boolean pmmd_b_driverStartReq;
  boolean pmmd_b_hwIgnOn;
  boolean pmmd_b_ignOn;
  boolean pmmd_b_pepsPduLvlValid;
  boolean pmmd_b_ignStsStrt;
  boolean pmmd_b_ptCanNmStRdy;
  FaultStatus tmmd_e_invFltSts;
  ElMac tmmd_e_invModAct;
  boolean tmmd_b_invActv;
  McuSts tmmd_e_tmmInvSts;
  boolean tmmd_b_invHVRdy;
  float32 tmmd_n_motActSpd_rpm;
  float32 tmmd_tq_motActTq_Nm;
  float32 tmmd_tq_motMaxAvailLTBst_Nm;
  float32 tmmd_tq_motMaxAvailSTBst_Nm;
  float32 tmmd_tq_motMaxAvailLTBrk_Nm;
  float32 tmmd_tq_motMaxAvailSTBrk_Nm;
  float32 tmmd_t_invTemp_C;
  float32 tmmd_t_motTemp_C;
  float32 tmmd_u_busInvHVAct_V;
  float32 tmmd_pwr_motActPwr_kW;
  float32 tmmd_fact_motGearRat;
  boolean tmmd_b_tmmInvSelfChkOk;
  ClutchState trad_e_trsm1ClthSt;
  ClutchState trad_e_engClthSt;
  FaultStatus trad_e_trsm1FltSts;
  FanStatus trad_e_trsm1FanReq;
  ShiftType trad_e_trsm1GearshiftTyp;
  float32 trad_fact_trsm1GearRat;
  boolean trad_b_trsm1CrpActv;
  boolean trad_b_trsm1GearActVld;
  boolean trad_b_trsm1GearTgtVld;
  boolean trad_b_trsm1HVOilPmpRdy;
  boolean trad_b_trsm1MILReq;
  boolean trad_b_trsm1OilTempVld;
  boolean trad_b_trsm1ShiftInProgs;
  boolean trad_b_trsm1EngStopAllwd;
  boolean trad_b_trsm1OutShaftSpdVld;
  float32 trad_n_trsm1EngIdleSpdReq_rpm;
  float32 trad_n_trsm1OutShaftSpd_rpm;
  sint8 trad_st_trsm1GearAct;
  sint8 trad_st_trsm1GearTgt;
  float32 trad_tq_trsm1ClthActTq_Nm;
  float32 trad_tq_engClthTqCap_Nm;
  float32 trad_tq_trsm1ClthMaxLim_Nm;
  float32 trad_tq_trsm1ClthMinLim_Nm;
  float32 trad_t_trsm1OilTemp_C;
  float32 trad_tq_trsm1InpTqMaxSlowReq_Nm;
  float32 trad_tq_trsm1InpTqMaxFastReq_Nm;
  float32 trad_tq_trsm1InpTqMinReq_Nm;
  float32 trad_n_trsm1InpSpdReq_rpm;
  boolean trad_b_trsm1TqIntvReqActv;
  float32 trad_fact_trsm1FinalDrvRat;
  float32 trad_fact_trsm1GbxGearRat;
  boolean trad_b_trsm1GearshiftActv;
  boolean trad_b_trsm1TqRedReqActv;
  boolean trad_b_trsm1TqIncReqActv;
  float32 trad_tq_trsm1InpTqRedReq_Nm;
  float32 trad_tq_trsm1InpTqIncReq_Nm;
  boolean trad_b_trsm1InpSpdCtrlModReq;
  boolean trad_b_trsm1InpTqIntvReq;
  float32 trad_tq_trsm1InpTqReq_Nm;
  ParkingStatus trad_e_trsm1PrkgSts;
  float32 trad_pct_GearPosn;
  float32 trad_tq_engClthMaxLim_Nm;
  float32 trad_tq_engClthMinLim_Nm;
  FaultStatus trad_e_trsm2FltSts;
  ElMac trad_e_trsm2CtrlModReq;
  boolean trad_b_trsm2GearshiftActv;
  boolean trad_b_trsm2InpSpdCtrlModReq;
  boolean trad_b_trsm2InpTqIntvReq;
  float32 trad_n_trsm2InpSpdReq_rpm;
  float32 trad_tq_trsm2InpTqReq_Nm;
  float32 trad_fact_trsm2GearRat;
  boolean trad_b_trsm2GearActVld;
  sint8 trad_st_trsm2GearAct;
  float32 trad_fact_trsm2FinalDrvRat;
  float32 trad_fact_trsm2GbxGearRat;
  GearShiftResp trad_e_trsm2GearShftResp;
  boolean tstd_b_engStrtReq;
  boolean tstd_b_engStarterStrtReq;
  boolean tstd_b_engMotorStrtReq;
  float32 vscd_ang_roadSlope_deg;
  float32 vscd_v_vehSpd_kph;
  float32 vscd_tq_axle1MaxTqFastReq_Nm;
  float32 vscd_tq_axle2MaxTqReq_Nm;
  float32 vscd_tq_axle1MaxTqSlowReq_Nm;
  float32 vscd_tq_axle2MinTqReq_Nm;
  float32 vscd_tq_axle1MinTqReq_Nm;
  boolean vscd_b_vscTqIntvReq;
  boolean vscd_b_ESPActv;
  boolean vscd_b_AVHActv;
  boolean vscd_b_vehSpdVld;
  boolean vscd_b_TCSFltActv;
  boolean vscd_b_VDCFltActv;
  float32 vscd_tq_axle1RgnBrkTqReq_Nm;
  float32 vscd_tq_axle2RgnBrkTqReq_Nm;
  boolean vscd_b_vehSlipWarn;
  boolean vild_b_parkIdleChgSwitch;
  boolean vild_b_hevModeInhSwitch;
  boolean vild_b_engIdleInhSwitch;
  boolean vild_b_engStartSwitch;
  boolean vild_st_trsm1SpdCtrlAllow;
  boolean vild_b_hvbHeatgVlvFlt;
  boolean vild_b_ptCanBusOff;
  float32 vild_u_Acc1Raw_mV;
  float32 vild_u_Acc2Raw_mV;
  float32 vild_u_BrkRaw_mV;
  float32 vild_u_Brk2Raw_mV;
  boolean vild_b_brkSwt1Actv;
  boolean vild_b_brkSwt2Actv;
  uint8 vild_ctr_dcdcStsInfo;
  float32 vild_u_dcdcEnbFb_mV;
  uint8 vild_st_dcdcEnaOutFb;
  uint8 vild_ctr_mcuMotorSts;
  uint8 vild_ctr_mcuMotorTrq;
  uint8 vild_st_eadInv2MilReq;
  uint8 vild_st_12vPwrRlyFlt;
  uint8 vild_ctr_apuWorkInfo;
  float32 vild_u_apuEnbFb_mV;
  uint8 vild_st_apuEngMilReq;
  uint8 vild_st_apuMilReq;
  boolean vild_b_calCanBusOff;
  uint8 vild_st_epbFltLvl;
  uint8 vild_ctr_bmsChgInfo;
  uint8 vild_ctr_bmsBattFaultInfo;
  uint8 vild_ctr_bmsHVIsolationInfo;
  uint8 vild_ctr_hcmWorkInf;
  uint8 vild_st_hvbSocFlt;
  uint8 vild_st_hvbMilReq;
  uint8 vild_st_hcmMilReq;
  float32 vild_u_hvilSrcFb_mV;
  float32 vild_pct_HVILReturnPWM;
  boolean vild_b_hvbHvilFlt;
  boolean vild_b_obcCircFlt;
  boolean vild_b_obcHwFlt;
  boolean vild_b_obcLkLpFlt;
  boolean vild_b_obcTempFlt;
  boolean vild_b_obcOutVoltFlt;
  boolean vild_b_obcOutCurrFlt;
  uint8 vild_st_obcFltInfo;
  boolean vild_b_ignStsStrt;
  float32 vild_u_pepsOn_mV;
  uint8 vild_st_pepsPduLvl;
  float32 vild_pct_GearPosn;
  uint8 vild_st_GearPosn;
  uint8 vild_st_egsmGearReq;
  uint8 vild_ctr_egsmGearInfo;
  uint8 vild_st_vscMilReq;
  float32 vild_u_5VT1IntSmpl_V;
  float32 vild_u_5VT2IntSmpl_V;
  float32 vild_u_5VT3IntSmpl_V;
  float32 vild_u_5VT4IntSmpl_V;
  float32 vild_u_5VT5IntSmpl_V;
  float32 vild_u_TS5sensorFb_mV;
  float32 vild_u_ecoBtnCur_mV;
  float32 vild_u_revBtnCur_mV;
  float32 vild_u_eLpWpCtrlCur_mV;
  float32 vild_u_hvPwrOffCtrl_mV;
  float32 vild_u_5VT6IntSmpl_V;
  boolean vild_b_pullUpDiagCmpl;
  float32 vild_u_edLpWpFb_V;
  float32 vild_u_strPmpEnbFb_mV;
  float32 vild_u_brkPmpEnbFb_mV;
  float32 vild_u_cbnLpPmpCtrlFb_mV;
  float32 vild_u_cbnLpPmpFb_V;
  float32 vild_u_batLpPmpCtrlFb_mV;
  float32 vild_u_batLpPmpFb_V;
  float32 vild_u_fan1CtrlFb_mV;
  float32 vild_u_fan2CtrlFb_mV;
  float32 vild_u_3wayVlvPwrRlyCtrlFb_mV;
  uint8 vild_st_5In1PwrRlyFlt;
  boolean vild_b_heatgLoopVlvFlt;
  uint8 vild_st_vcuSlfChkFlt;
  uint8 vild_st_eepErr;
  uint8 vild_st_waterPmpPwrRlyFlt;
  uint8 vild_st_epsEnaOutFb;
  uint8 vild_st_brkPmpEnaOutFb;
  uint8 vild_pct_fan1DutyRead;
  uint8 vild_pct_fan2DutyRead;
  uint8 vild_st_containerPwrRlyFlt;
  float32 vild_frq_fan1FreqRead_Hz;
  float32 vild_frq_fan2FreqRead_Hz;
  float32 vild_pct_WatPmpEP2FbPWM;
  float32 vild_pct_WatPmpEP3FbPWM;
  float32 vild_pct_fan1Fb;
  float32 vild_pct_fan2Fb;
  float32 vild_u_hvbVolt_V;
  float32 vild_u_hvPwrOnCtrl_mV;
  boolean vild_b_rstAvgPwrConsumption;
  boolean vild_b_hvbCoolgVlvFlt;
  boolean vild_b_ignStsOn;
  boolean vild_b_pepsPduLvlVld;
  float32 vild_t_hvbMax_C;
  float32 vild_t_hvbMin_C;
  float32 vild_i_hvbCurr_A;
  uint8 vild_st_acCoolSts;
  uint8 vild_st_hvbStatus;
  boolean vild_b_cntnrCtrlEnaFb;
  float32 vild_pct_WatPmpEP1FbPWM;
  uint8 vild_st_24vDcdcModAct;
  uint8 vild_st_hvbThermMngReq;
  float32 vild_t_hvbCooltInTemp_C;
  float32 vild_t_hvbCooltOutTemp_C;
  float32 vild_d_odometer_km;
  boolean vild_b_odometerInvalid;
  boolean vild_b_CCSginal;
  boolean vild_b_DryAirSwitch;
  boolean vild_b_ResrAirSwitch;
  float32 vild_t_TS5sensorFb_C;
  boolean vild_b_emgyStopIn;
  float32 vild_u_Brk2_V;
  float32 vild_u_Brk_V;
  uint8 vild_st_TV3FltFbV6;
  uint8 vild_st_TV3FltFbV5;
  uint8 vild_st_TV4FltFbV6;
  uint8 vild_st_TV4FltFbV5;
  uint8 vild_st_TV1FltFbV6;
  uint8 vild_st_TV1FltFbV5;
  boolean vild_b_obcWakeUpActv;
  float32 vild_u_accPdlSens2InpVolt_V;
  float32 vild_u_accPdlSens1InpVolt_V;
  boolean vild_b_driverEcoModeReq;
  uint8 vild_st_engRedStopLamp;
  uint8 vild_st_trsm1RedStopLamp;
  float32 accd_n_acFanReqSpd_pct;
  float32 vild_u_dcdcRelayVolt_V;
  float32 vild_t_hvbOutCoolTemp_C;
  float32 vild_t_hvbSetTgtTemp_C;
  float32 vild_E_hvbPackRemnEgy_kWh;
  float32 vild_i_dcdcInpCurr_A;
  uint8 vild_st_actWorkSts1;
  float32 vild_u_brkVacuumPres_V;
  uint8 vild_st_hvbDischgFltReq;
  uint8 vild_st_hvbChgFltReq;
  boolean vild_b_acuDrvSeatbltBcklSts;
  boolean vild_b_acuDrvSeatbltBcklInvld;
  boolean vild_b_bcmFrntLftDrAjSts;
  uint8 vild_st_egsmShftLvrFailSt;
  boolean vild_b_egsmFnctnConfg;
  uint8 adcd_st_pmsAdcCtrldSts;
  boolean adcd_b_adcCtrlGearEn;
  uint8 adcd_st_adcTgtGearPostn;
  boolean eadd_b_eadInv2ActvDischCmplt;
  boolean vscd_b_ehbAebActv;
  boolean vscd_b_ehbTrqDecReqActv;
  float32 vscd_tq_ehbTrqDecReq_Nm;
  boolean vscd_b_ehbVlcAvailb;
  boolean vscd_b_ehbVlcActv;
  boolean vscd_b_ehbVlcTrqReqActv;
  float32 vscd_tq_ehbVlcTrqReq_Nm;
  boolean vscd_b_ehbDtcActv;
  boolean vscd_b_ehbTrqIncReqActv;
  float32 vscd_tq_ehbTrqIncReq_Nm;
  uint8 vscd_st_ehbMbRgnTgtWhlSts;
  float32 vscd_tq_ehbMbRgnTgtWhl_Nm;
  boolean vild_b_csmRgnLvlSet;
  boolean adcd_b_adc1SwtchCtrlReq;
  boolean adcd_b_adcCtrlTorqEn;
  float32 adcd_tq_adcTgtDrvTorq_Nm;
  boolean adcd_b_adc1CtrlTorqEn;
  float32 adcd_tq_adc1TgtDrvTorq_Nm;
  boolean vild_b_adcComErrFlg;
  boolean vild_b_adc1ComErrFlg;
  boolean vscd_b_ehbAbsOvrdActv;
  uint8 vild_st_rfrSwapprocd;
  boolean vild_b_rfrSwapBatReq;
  uint8 vild_st_rfrConnctSts;
  uint8 vscd_st_vscIsgActvDampModReq;
  float32 dccd_pwr_dcdcHVpwr_kW;
  float32 vild_pwr_PTCActPwr_kW;
  float32 vild_pwr_airCmprAct_kW;
  boolean vild_st_eadMot2TempHiFlt;
  uint8 vild_st_hvbDisChgFaultReq;
  uint8 vild_st_hvbChgFaultReq;
  boolean drid_b_drvrModeReq;
  uint16 vild_num_hvbCellSum;
  uint8 vild_st_BmsTempOutOfCtrlFlt;
  uint8 vild_st_hvbDCChgProcss;
  uint8 vild_st_obcChgSts;
  uint8 vild_st_hvbChgOvrCurr;
  uint8 vild_st_hvbBattIsolationSts;
  uint8 vild_st_hvbDCChgPlgPOvrTmp;
  uint8 vild_st_hvbDCChgPlgNOvrTmp;
  uint16 vild_tm_hvbFnshChgTim_m;
  float32 vild_u_hvbPackVolt_V;
  uint8 vild_st_vscEHBAVHSts;
  uint8 vild_st_dcChgCcSt;
  boolean vild_b_ipkOdoBckUpEn;
  uint8 vild_st_obcChgCCSts;
  float32 obcd_pwr_obcOutpt_kW;
  uint8 vild_st_hvbChgSts;
  float32 vild_i_hvbDCChgCurReq_A;
  float32 vild_n_ead2MotActSpd_rpm;
  float32 vild_v_vscFrontAxleSpd_kph;
  uint8 hvbd_st_hvbEmgyCutOffReq;
  boolean vild_b_flgABSMsgErr;
  boolean vild_b_flgACMsgErr;
  boolean vild_b_flgBCMMsgErr;
  boolean vild_b_flgEPBMsgErr;
  boolean vild_b_flgDCDCMsgErr;
  boolean vild_b_flgSDCACMsgErr;
  boolean vild_b_flgEGSMMsgErr;
  boolean vild_b_flgTBOXMsgErr;
  boolean vild_b_flgICMsgErr;
  boolean vild_b_flgACUMsgErr;
  boolean vild_b_flgPEPSMsgErr;
  boolean vild_b_flgABSSpdMsgErr;
  boolean vild_b_flgFnctnConfgEPB;
  boolean vild_b_flgFnctnConfgACU;
  boolean vild_b_flgFnctnConfgPEPS;
  boolean vild_b_flgBDCACMsgErr;
  boolean vild_b_flgFnctnConfgEGSM;
  boolean vild_b_flgAirEPBMsgErr;
  boolean vild_b_flgFnctnConfgAirEPB;
  boolean hvbd_b_tboxIntelChgCmdRaw;
  boolean vscd_b_ehbMsgErr;
  uint8 vild_st_eadInv2FltSts;
  uint8 vild_st_ipuMotorSubFltLvl;
  float32 vild_u_ipuHVBusVolt_V;
  uint8 vild_st_ptcConnStsFb;
  float32 vild_pwr_accm1ActPwr_kW;
  boolean vild_b_epbErrSts;
  boolean vild_b_flgFnctnConfgEHB;
  float32 vild_v_ehbVehSpd_kph;
  boolean vild_b_mhgvRespErr;
  boolean vild_b_mhgvOvrVoltFlt;
  boolean vild_b_mhgvOvrCurrFlt;
  boolean vild_b_mhgvOvrTempFlt;
  boolean vild_b_mhgvUndVoltFlt;
  boolean vild_b_mhgvInitSts;
  boolean vild_b_mhgvCcwFlg;
  boolean vild_b_mhgvMotSts;
  float32 vild_pct_mhgvCrtPos;
  boolean vild_b_fwfvRespErr;
  boolean vild_b_fwfvOvrVoltFlt;
  boolean vild_b_fwfvOvrCurrFlt;
  boolean vild_b_fwfvOvrTempFlt;
  boolean vild_b_fwfvUndVoltFlt;
  boolean vild_b_fwfvInitSts;
  boolean vild_b_fwfvCcwFlg;
  boolean vild_b_fwfvMotSts;
  float32 vild_pct_fwfvCrtPos;
  uint8 adcd_st_pmsCanBusRecSta;
  uint8 vild_st_tboxChgLmtSw;
  float32 vild_pct_tboxAlwChgCurrMax;
  float32 vild_pct_tboxChgDepth;
  uint8 vild_st_tboxChgSftSwCtlSt;
  uint8 vild_st_tboxRsrChgSt;
  uint8 vild_st_tboxPrtFullSwSt;
  boolean vild_b_tboxPrtFullSwStUB;
  uint8 vild_st_obcOnBdDchaCCline;
  uint8 vild_st_obcElckStMod;
  boolean vild_b_csmV2XDchaSw;
  boolean vild_b_csmV2XDchaSwInvld;
  uint8 vild_num_hvbTempSum;
  float32 vild_R_posInsIRes_Ohm;
  uint8 vild_num_hvbCellMaxID;
  uint8 vild_num_hvbCellMinID;
  float32 vild_u_BmsMaxCellVolt_V;
  float32 vild_u_BmsMinCellVolt_V;
  uint8 vild_num_hvbMaxTempID;
  uint8 vild_num_hvbMinTempID;
  uint8 vild_st_batOvrSoc2;
  uint8 vild_st_hvbSocJumpFlt;
  uint8 vild_st_batLowSoc2;
  uint8 vild_st_hvbCellTempDevFlt;
  uint8 vild_st_cellUdrVolt2;
  uint8 vild_st_cellOverVolt2;
  uint8 vild_st_batUdrVolt2;
  uint8 vild_st_batOvrVolt2;
  uint8 vild_st_hvbTempFlt;
  uint8 vild_st_hvbInslErr;
  uint8 vild_st_hvbCellVoltDevFlt;
  uint8 vild_st_eadInv2TempHiAlrm;
  uint8 vild_st_flgFctCfgVehTyp;
  boolean vild_b_flgFctCfgMaxChgCurr;
  boolean vild_b_flgFctCfgDrvSeat;
  uint8 vild_st_flgFctCfgV2L;
  boolean vild_b_flgFctCfgEpdel;
  boolean vild_b_flgFctCfgMotor;
  uint8 vild_st_flgFctCfgMaxSpd;
  uint8 vild_st_obcOnBdCCline;
  uint8 vild_b_hvbInPositionDetct1;
  uint8 vild_b_hvbInPositionDetct2;
  uint8 vild_st_hvbPreChgSts;
  boolean vild_b_hvbDCChgCurReqRngUp;
  boolean vild_b_hvbDisChgSopRngUp;
  boolean vild_b_flgFctCfgAdc;
  float32 vild_a_yrsLongitAcce_mps2;
  uint8 vild_st_csmRgnLvlSet;
  uint8 accd_st_iptWorkSt;
  float32 vild_pwr_ptcActPwrRear_kW;
  uint8 accd_st_ptcWorkStRear;
  boolean vild_b_hvbZeroPwrReq;
  uint8 vild_st_hcmAccConnStsFb;
  float32 vild_pwr_iptActPwr_kW;
  uint8 vild_st_flgFctCfgFan;
  uint8 vscd_st_ehbAVHSts;
  uint8 vscd_st_ehbHHCActive;
  uint8 vscd_st_ehbEPBDynAppSts;
  float32 obcd_pwr_obcRlTmOutpt_kW;
  uint8 vild_st_flgFctCfgBatTyp;
  boolean vild_b_flgFctCfgTyre;
  uint8 vild_st_flgFctCfgSlowChg;
  uint8 vild_st_flgFctCfgPowerMaxSpd;
  boolean vild_b_flgFctCfgAirBag;
  uint8 vild_st_flgFctCfgMotTyp;
  boolean vild_b_flgFctCfgDrvMod;
  boolean vild_b_flgFctCfgBatCol;
  uint8 vild_st_flgFctCfgAccy;
  uint8 vild_st_flgFctCfgECOMaxSpd;
  uint8 vild_st_flgFctCfgNormalMaxSpd;
  uint8 vild_st_hvbChgCcsts;
  boolean vild_b_bcmFrntRDrAjSts;
  boolean vild_b_flgFctCfgChgTyp;
  float32 vild_u_hvbCooltInSnsr_V;
  float32 vild_u_hvbCooltOutSnsr_V;
  float32 vild_ang_strWhlAng_rad;
  uint8 vild_st_epsEpasFail;
  uint8 vild_st_hvbStsDischgFlt;
  uint8 vild_st_hvbStsChgFlt;
  uint8 vild_st_dccAccyConnStsFb;
  boolean vild_b_dcdcTempAlm;
  boolean vild_b_dcdcStsAlm;
  uint8 vild_st_ipuMotTempHighFlt;
  uint8 vild_st_ipuInvTempHighAlm;
  uint8 vild_st_hvbBatUniformity;
  uint8 vild_st_hvbOvrChgFlt;
  uint8 vild_st_hcmPtcDefRlyStFb;
  float32 vild_u_hcmPtcRlyVolt;
  float32 vild_u_hcmAcceRlyVolt;
  boolean vild_b_hcmPtcRlyVoltVldSts;
  boolean vild_b_hcmAcceRlyVoltVldSts;
  float32 vild_u_hcmMainPosBckVolt;
  boolean vild_b_hcmMainPosBckVoltVldSts;
  boolean vild_b_AccyEnReq;
  boolean vild_b_AccyFltSts;
  uint8 vild_st_bbmFltSts;
  uint8 vild_st_bbmWorkSts;
  uint8 vild_st_hcmHvilSt;
  uint8 vild_st_pepsPduLvlVld;
  uint8 hvbd_st_hvilOpenSt;
  uint8 vild_st_ipkCruisingDstSwt;
  uint8 vild_st_ehbBrkSysErrFlt;
  boolean vild_b_flgFctCfgDrvModStor;
  boolean vild_b_flgFctCfgDrvModConn;
  boolean vild_b_flgBBMMsgErr;
  boolean vild_b_disChgSwtSt;
  uint8 vild_st_flgFctCfgVehCfg;
  uint8 vild_st_flgFctCfgVehUsg;
  float32 vild_tq_ehbIsaPtTrqDecReq_Nm;
  uint8 vild_st_ehbIsaSts;
  boolean vild_b_ehbIsaPtTrqDecReqActv;
  uint8 vild_st_hcmPTC1ConnStsFb;
  boolean vild_b_tboxPowOffCmd;
  boolean vild_b_csmTakeEleSwt;
  boolean vild_b_csmTakeEleSwtReqInvld;
  float32 vild_d_ipkOdometerbackup;
  float32 vild_d_bcmOdometerbackup;
  boolean accd_b_acHvilOpnInvld;
  boolean dccd_b_dcdcHvilFltInvld;
  boolean vild_st_ipkChgSftSwCtlSt;
  uint8 vild_st_pepsRKECom;
  boolean vild_b_pdcBrkFlg;
  boolean vild_st_hvbChgLEDCtl;
  boolean vild_st_ipkAlwChgSftCtlSt;
  boolean cesd_b_acuCrash;
  float32 vild_t_acwpOutptTemp_C;
  float32 vild_pwr_acwpHeatPower_kW;
  uint8 vild_st_flg2FctCfgVehTyp;
  float32 hvbd_pwr_hvbChgPwr_kW;
  boolean vscd_b_pdcBrkFlg;
  float32 vscd_v_vehSpdRaw_kph;
  uint8 vild_st_mmiRestSwitch;
  float32 vild_l_whlRad_m;
  boolean vild_b_flgFctCfgACU;
  uint16 vild_st_flgFctCfgDspRemainRng;
  boolean vild_b_flgFctCfgDualAuthN;
  float32 vild_pct_mmiLocBkChgTarVal;
  boolean vild_b_csmCampModeSwt;
  boolean vild_b_csmCampModeSwtInvld;
  float32 vild_u_VacTkAirPres_V;
  float32 vild_u_VacTkEnFb_V;
  boolean vild_b_flgNetConfgABS;
  uint16 vild_u_vacTkPowSup_V;
  boolean vild_b_ehbVlcCddActv;
  boolean vscd_b_vscBrkLghtActv;
  float32 vscd_a_vscLongitAcce_mps2;
  boolean vild_b_flgFctCfgCoastActivBrkLight;
  boolean vild_b_pepsRmtCtrlSt;
  boolean vild_b_pepsOnSwtSt;
  boolean vild_b_csmEngRecSwtReq;
  uint8 vild_st_csmEngRecReqInvalid;
  uint8 vild_st_bmsTboxFireAlm;
  uint8 vild_st_bmsBattPackMatchFlt;
  uint8 vild_st_ipuMotorOverSpdFlt;
  uint8 vild_st_ipuMotorOverCurrFlt;
  uint8 vild_st_bmsBattSysNum;
  uint8 vild_st_bmsBattPackNum;
  uint8 vild_st_bmsDlyDataUpldEnb;
} vcib_VCIP;

#endif

#ifndef DEFINED_TYPEDEF_FOR_vcsb_HVSM_
#define DEFINED_TYPEDEF_FOR_vcsb_HVSM_

typedef struct {
  uint8 bmsd_e_modeTgt;
  HVBattStatus hvbd_e_modeTgt;
  boolean hvbd_b_hvBusShutDwnCmpl;
  HVACStatus accd_e_modeTgt;
  uint8 hvbd_st_ptRdyInd;
  boolean hvbd_b_allowChg;
  boolean hvbd_b_lvCutOffReq;
  boolean hvbd_b_vcuWkUpCmd;
  ElMac eadd_e_inv1ModeTgt;
  uint8 hvbd_st_hvbMaiRlyNegClsReq;
  uint8 hvbd_st_hcmMaiRlyNegClsReq;
  boolean eadd_b_ead1Avail;
  uint8 hvbd_st_hvbAssiRlyPosClsReq;
  ChargerStatus obcd_e_chargerSts;
  boolean eadd_b_ead1Enad;
  boolean obcd_b_chargerPlugged;
  uint8 hvbd_st_hvbMaiRlyPosClsReq;
  PmmStatus hvbd_e_PmmStatus;
  boolean hvbd_b_tmOutFlg;
  ElMac eadd_e_inv2ModeTgt;
  boolean hvbd_b_tmOutFlgCfm;
  boolean hvbd_b_rlyTmOut;
  boolean eadd_b_ead2Avail;
  boolean hvbd_b_vcuRdyToSlp;
  boolean eadd_b_ead2Enad;
  boolean hvbd_b_hvbIntelChgCmplt;
  boolean hvbd_b_hvbIntelChgExitReq;
  ElMac msgd_e_invModeTgt;
  boolean msgd_b_msgAvailable;
  boolean msgd_b_msgEnabled;
  float32 msgd_n_motSpdTgt_rpm;
  boolean msgd_b_engStartComplete;
  ElMac tmmd_e_invModeTgt;
  boolean tmmd_b_tmmAvail;
  boolean tmmd_b_tmmEnad;
  float32 tmmd_n_motSpdTgt_rpm;
  boolean tmmd_b_engStartComplete;
  float32 tmmd_n_idleSpdTgt_rpm;
  boolean tmmd_b_tmmSpdCtrlAllow;
  DCDCMode dccd_e_modeTgt;
  boolean dccd_b_DCDCEnabled;
  boolean apud_b_apuStartPrt;
  float32 apud_pwr_apuTgtRevMode_kW;
  float32 apud_n_engSpdTgtRevMode_rpm;
  float32 apud_tq_crsGcuTgtRevMode_Nm;
  boolean apud_b_apuStartFail;
  uint8 apud_st_apuReqFb;
  boolean apud_b_apuFltStop;
  float32 apud_pwr_hvSysPwrAct_kW;
  ApuMode apud_e_apuMode;
  boolean apud_b_tmpFrcSttApu1;
  uint8 dccd_pct_DCDCPwrLmt;
  boolean hvbd_b_dchaOn;
  boolean hvbd_b_fltPwrShutDn;
  boolean hvbd_b_chgCablePlugged;
  boolean hvbd_b_accyWrkEnCmd;
  boolean hvbd_b_accyLvPwrOnCmd;
  boolean hvbd_b_accyHvOnCmd;
  uint8 hvbd_st_accyTakeSts;
  uint8 hvbd_st_bbmWrkEnCmd;
  uint8 hvbd_st_accyRlyVoltSamSw;
  boolean hvbd_b_accyPreRlyCmd;
  uint8 hvbd_st_accyPreRlySts;
  uint8 hvbd_st_accyRlyFlt;
  uint8 hvbd_st_accyPreRlyFlt;
  uint8 hvbd_st_accyRlySts;
  boolean hvbd_b_acPtcEnb;
  uint8 hvbd_st_RmChgCmdFailPmt;
  uint8 hvbd_st_tboxChgSftSwCtlStEV;
  boolean hvbd_b_TakeEleSwtIndReq;
  float32 hvbd_pct_BookChrgnTarValFb;
  boolean hvbd_b_CampModeFb;
  uint8 hvbd_st_CampModeFbFailrReason;
  uint8 hvbd_st_otaHvOnOFFReqSts;
  uint8 hvbd_st_otaHvOnOffFailInfo;
} vcsb_HVSM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_vcsb_THSM_
#define DEFINED_TYPEDEF_FOR_vcsb_THSM_

typedef struct {
  FanStatus thmd_e_fanTgtSts;
  PumpStatus thmd_e_wtrPmp1TgtSts;
  PumpStatus thmd_e_wtrPmp2TgtSts;
  boolean thmd_b_afterRunActive;
  boolean thmd_b_fanRly1Req;
  boolean thmd_b_fanRly2Req;
  boolean thmd_b_wtrPmpRly1Req;
  boolean thmd_b_wtrPmpRly2Req;
  float32 thmd_n_fan1TgtSpd_rpm;
  float32 thmd_n_wtrPmp1TgtSpd_rpm;
  float32 thmd_n_wtrPmp2TgtSpd_rpm;
  float32 thmd_n_fan1TgtSpd_pct;
  float32 thmd_n_pmp1TgtSpd_pct;
  float32 thmd_n_pmp2TgtSpd_pct;
  uint8 thmd_st_FanReqCmd;
  uint8 thmd_st_wtrPmp1ReqCmd;
  uint8 thmd_st_wtrPmp2ReqCmd;
  boolean thmd_b_TwoWayVlvReq;
  float32 thmd_n_fan2TgtSpd_pct;
  uint8 thmd_b_fan2Ena;
  boolean thmd_b_tv4V2;
  boolean thmd_b_tv4V3;
  TV4Status thmd_e_tv4;
  uint8 thmd_st_tv4;
  boolean thmd_b_tv1V2;
  boolean thmd_b_tv1V3;
  boolean thmd_b_tv2V2;
  boolean thmd_b_tv2V3;
  boolean thmd_b_heaterEna;
  boolean thmd_b_tv3V2;
  boolean thmd_b_tv3V3;
  uint8 thmd_st_tv3;
  float32 thmd_n_ep1TgtSpd_pct;
  boolean thmd_b_accmEnb;
  float32 thmd_x_iceB_pct;
  float32 thmd_x_iceC_pct;
  float32 thmd_x_hvbcB_pct;
  float32 thmd_x_hvbcC_pct;
  uint8 thmd_x_hvbB_pct;
  uint8 thmd_x_hvbC_pct;
  boolean thmd_b_wtrPmp1CtrlEnabled;
  boolean thmd_b_wtrPmp2CtrlEnabled;
  boolean thmd_b_engStartReq;
  float32 thmd_n_MHGVTgt_pct;
  float32 thmd_n_FWFVTgt_pct;
  boolean thmd_b_PassCool_flg;
  boolean thmd_b_ActiveCool_flg;
  boolean thmd_b_BalanceHeat_flg;
  boolean thmd_b_PassHeat_flg;
  float32 thmd_q_pmp2FlowFeedback;
  boolean thmd_b_hvbDeft;
  boolean thmd_b_iptcHtIpuResvHt;
  boolean thmd_b_iptcHtIpuCl;
  boolean thmd_b_ipuResvHt;
  boolean thmd_b_ipuSupHtIptcHt;
  boolean thmd_b_ipuHeatEnableFlg;
  float32 thmd_pwr_ipuHeatPwrAllwd_kW;
  boolean thmd_b_heaterEna2;
  boolean thmd_b_heaterEna3;
  boolean thmd_b_heaterEnaHW;
  boolean thmd_b_heaterEna3HW;
  uint8 thmd_st_ptcRlyVoltSamSwitch;
  uint8 thmd_st_acceRlyVoltSamSwitch;
  uint8 thmd_st_ptcConnStsFb;
  uint8 thmd_st_ptcRlyFlt;
  uint8 thmd_st_ptc3ConnStsFb;
  uint8 thmd_st_ptc3RlyFlt;
  uint8 thmd_st_acwpSpdReq;
  float32 thmd_t_acwpTemp_C;
  uint8 thmd_st_acwpRun;
  uint8 thmd_st_acwpHeat;
} vcsb_THSM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_vcsb_DIAG_
#define DEFINED_TYPEDEF_FOR_vcsb_DIAG_

typedef struct {
  uint8 digd_st_edcpFlt;
  uint8 digd_st_hbcpFlt;
  uint8 digd_st_vehSysErrLevel;
  boolean acpd_b_accPed1Vld;
  boolean acpd_b_accPed2Vld;
  boolean brpd_b_brkSwtMismatch;
  boolean digd_b_vcuVehLvl22Flt_flg_BRP;
  boolean macd_b_EVCANBusoffDebd;
  boolean digd_b_VehLvl1Flt_flg;
  boolean digd_b_VehLvl21Flt_flg;
  boolean digd_b_VehLvl31Flt_flg;
  boolean digd_b_VehLvl32Flt_flg;
  boolean digd_b_VehLvl33Flt_flg;
  boolean digd_b_VehLvl22Flt_flg;
  boolean digd_b_VehLvl23Flt_flg;
  boolean ddid_b_egsmMsgErr;
  boolean ddid_b_bmsMsgErr;
  boolean digd_b_bmsFltLv4A;
  boolean digd_b_mcuFltLv2A;
  boolean digd_b_mcuFltLv3A;
  boolean digd_b_mcuMsgErr;
  boolean macd_b_EVCANBusoff31Err;
  boolean digd_b_vcuVehLvl1Flt_flg_BRP;
  boolean digd_b_vehCrashFltLvl33;
} vcsb_DIAG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_vcsb_AUXC_
#define DEFINED_TYPEDEF_FOR_vcsb_AUXC_

typedef struct {
  boolean brpd_b_airTankPresLowEVDis;
  boolean brpd_b_VacPumpSnrFlt;
  boolean brpd_b_VacTkAirPresLowFlt;
  boolean brpd_b_VacPumpAuxRlyEn;
  boolean brpd_b_VacPumpRlyEn;
  boolean brpd_b_VacPumpSysFailFlt;
  boolean brpd_b_VacPumpEnOvrTmLoPreFlt;
  boolean brpd_b_VacPumpEnOvrTmHiPreFlt;
  boolean brpd_b_VacPumpLoPreFlt;
  float32 brpd_p_VacPumpPressure_kPa;
  float32 brpd_u_VacPumpVol_V;
  boolean pscd_b_epsStopFlt;
  boolean brpd_b_brkPmp1Rly;
  boolean brpd_b_brkPmp2Rly;
  boolean brpd_b_bdcacEna;
  boolean brpd_b_pumpRdy;
  boolean brpd_b_airTankFlt;
  boolean brpd_b_bdcacTmOut;
  boolean brpd_b_airTankPresLow;
  boolean lvbd_b_lvbSOCValid;
  float32 lvbd_q_lvbSOC_pct;
  float32 pscd_frq_epsFrqTgt_Hz;
  boolean pscd_b_epsEna;
  boolean brpd_b_airTankPresLowInhDrv;
  boolean brpd_b_VacPumpRlyFlt;
} vcsb_AUXC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_vcsb_VOMM_
#define DEFINED_TYPEDEF_FOR_vcsb_VOMM_

typedef struct {
  uint8 hmmd_e_PHEVClthMode;
  uint8 hmmd_e_PHEVClthModeReq;
  uint8 pmmd_bm_netModeReq[2];
  PmmMode pmmd_e_mode;
  boolean pmmd_b_emsWake;
  boolean pmmd_b_peuWake;
  boolean pmmd_b_pwrHoldReq;
  boolean pmmd_b_startReq;
  boolean pmmd_b_vcuAwb;
  uint32 pmmd_st_stayAwkReason;
  uint8 pmmd_st_vcuWkUpReason;
  boolean pmmd_b_nmSts;
  boolean pmmd_b_vcuRmr;
  uint8 pmmd_num_vcuAddr;
  boolean pmmd_b_nmWkUp;
  boolean pmmd_b_nmRdySlp;
  uint8 pmmd_st_ptCanModeReq;
  uint8 pmmd_st_bdCanModeReq;
  NMStatus pmmd_e_CanNMSts;
  uint8 pmmd_st_vcuPwrActvMod;
  boolean vsmd_b_PTDisabled;
  boolean vsmd_b_PTEnabled;
  boolean vsmd_b_VehRun;
  boolean vsmd_b_VehStrt;
  boolean vsmd_b_StartDemRaw;
  boolean vsmd_b_VehRunRaw;
  boolean drid_b_vehSportModActv;
  boolean drid_b_veh4WDModActv;
  DriveDir drid_e_driveDirSel;
  HEVModeReq drid_e_drvrHEVModReq;
  GearLeverPos drid_e_gearLvrPos;
  HybModeMngr hmmd_e_hmmState;
  boolean hmmd_b_bHVReady;
  boolean hmmd_b_engStartReq;
  boolean hmmd_b_engStopReq;
  boolean hmmd_b_EVModeActive;
  boolean hmmd_b_HVBusDischrgComplete;
  boolean hmmd_b_HVBusDischrgReq;
  boolean hmmd_b_ICEModeReq;
  boolean hmmd_b_PHEVModeActive;
  boolean hmmd_b_SHEVModeActive;
  boolean hmmd_b_motProtActv;
  EngStartType essd_e_engStrtTyp;
  EngStartType essd_e_engStrtTypSeld;
  boolean essd_b_strtrRlyDem;
  boolean essd_b_motStrtDem;
  boolean essd_b_motStrtEnad;
  boolean essd_b_engStartReq;
  boolean essd_b_engStopReq;
  boolean essd_b_engStrtAbort;
  boolean essd_b_engStrtComplete;
  boolean pmmd_b_hsdFltClear;
  boolean hmmd_b_PHEVIdleChrgReq;
  boolean hmmd_b_EVModeEpsEna;
  uint8 drid_st_gearLvrLckInd;
  boolean drid_b_gearPosVld;
  boolean drid_b_epbClsdReq;
  boolean drid_b_vehEcoModActv;
} vcsb_VOMM;

#endif

/* PublicStructure Variables for Internal Data, for system '<S195>/turnOFF_delay1' */
typedef struct {
  float32 t_wait;                      /* '<S200>/timed_delay' */
  uint8 is_c12_Ricardo_SW_dev_lib;     /* '<S200>/timed_delay' */
  uint8 is_active_c12_Ricardo_SW_dev_li;/* '<S200>/timed_delay' */
} ARID_DEF_turnOFF_delay1_swc_V_T;

/* PublicStructure Variables for Internal Data, for system '<S191>/SR_latch' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S216>/Unit Delay' */
} ARID_DEF_SR_latch_swc_VOMM_T;

/* PublicStructure Variables for Internal Data, for system '<S6>/turnON_delay_4WD' */
typedef struct {
  float32 t_wait;                      /* '<S14>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib;     /* '<S14>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev_li;/* '<S14>/timed_delay' */
} ARID_DEF_turnON_delay_4WD_swc_T;

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  ARID_DEF_SR_latch_swc_VOMM_T ARID_DEF_SR_latch;/* '<S25>/SR_latch' */
  ARID_DEF_turnON_delay_4WD_swc_T ARID_DEF_turnON_delay1;/* '<S77>/turnON_delay1' */
  ARID_DEF_turnON_delay_4WD_swc_T ARID_DEF_turnON_delay;/* '<S77>/turnON_delay' */
  ARID_DEF_turnON_delay_4WD_swc_T ARID_DEF_turnON_delay5;/* '<S76>/turnON_delay5' */
  ARID_DEF_SR_latch_swc_VOMM_T ARID_DEF_SR_latch_m;/* '<S76>/SR_latch' */
  ARID_DEF_turnON_delay_4WD_swc_T ARID_DEF_turnON_delay2;/* '<S66>/turnON_delay2' */
  ARID_DEF_turnON_delay_4WD_swc_T ARID_DEF_turnON_delay1_c;/* '<S66>/turnON_delay1' */
  ARID_DEF_turnON_delay_4WD_swc_T ARID_DEF_turnON_delay_k;/* '<S66>/turnON_delay' */
  ARID_DEF_SR_latch_swc_VOMM_T ARID_DEF_SR_latch2;/* '<S66>/SR_latch2' */
  ARID_DEF_SR_latch_swc_VOMM_T ARID_DEF_SR_latch1;/* '<S66>/SR_latch1' */
  ARID_DEF_SR_latch_swc_VOMM_T ARID_DEF_SR_latch_c;/* '<S66>/SR_latch' */
  ARID_DEF_turnON_delay_4WD_swc_T ARID_DEF_turnON_delay_b;/* '<S117>/turnON_delay' */
  ARID_DEF_SR_latch_swc_VOMM_T ARID_DEF_SR_latch_p;/* '<S89>/SR_latch' */
  ARID_DEF_turnON_delay_4WD_swc_T ARID_DEF_turnON_delay_c;/* '<S111>/turnON_delay' */
  ARID_DEF_SR_latch_swc_VOMM_T ARID_DEF_SR_latch_f;/* '<S88>/SR_latch' */
  ARID_DEF_turnON_delay_4WD_swc_T ARID_DEF_turnON_delay_g;/* '<S105>/turnON_delay' */
  ARID_DEF_SR_latch_swc_VOMM_T ARID_DEF_SR_latch_g;/* '<S87>/SR_latch' */
  ARID_DEF_turnON_delay_4WD_swc_T ARID_DEF_turnON_delay_m;/* '<S99>/turnON_delay' */
  ARID_DEF_SR_latch_swc_VOMM_T ARID_DEF_SR_latch_n;/* '<S86>/SR_latch' */
  ARID_DEF_turnON_delay_4WD_swc_T ARID_DEF_turnON_delay_SPORT;/* '<S6>/turnON_delay_SPORT' */
  ARID_DEF_turnON_delay_4WD_swc_T ARID_DEF_turnON_delay_HEV;/* '<S6>/turnON_delay_HEV' */
  ARID_DEF_turnON_delay_4WD_swc_T ARID_DEF_turnON_delay_EV;/* '<S6>/turnON_delay_EV' */
  ARID_DEF_turnON_delay_4WD_swc_T ARID_DEF_turnON_delay_ECO;/* '<S6>/turnON_delay_ECO' */
  ARID_DEF_turnON_delay_4WD_swc_T ARID_DEF_turnON_delay_4WD;/* '<S6>/turnON_delay_4WD' */
  ARID_DEF_SR_latch_swc_VOMM_T ARID_DEF_SR_latch_pp;/* '<S5>/SR_latch' */
  ARID_DEF_turnOFF_delay1_swc_V_T ARID_DEF_turnOFF_delay;/* '<S191>/turnOFF_delay' */
  ARID_DEF_SR_latch_swc_VOMM_T ARID_DEF_SR_latch_l;/* '<S191>/SR_latch' */
  ARID_DEF_turnOFF_delay1_swc_V_T ARID_DEF_turnOFF_delay1;/* '<S195>/turnOFF_delay1' */
  float32 t_wait;                      /* '<S134>/timed_delay' */
  float32 PowerUpTimer;                /* '<S25>/GearLeverPosition' */
  float32 WaitTm;                      /* '<S25>/GearLeverPosition' */
  float32 PowerUpTimer_b;              /* '<S24>/GearLeverPosition' */
  float32 StartDemLatchTimer;          /* '<S5>/VehicleStartManager' */
  float32 StartReqTimer;               /* '<S5>/VehicleStartManager' */
  float32 TimeInState;                 /* '<S197>/pmm_power_modes' */
  float32 t_wait_m;                    /* '<S205>/timed_delay' */
  float32 t_wait_a;                    /* '<S199>/timed_delay' */
  uint16 T;                            /* '<S162>/DriverMode' */
  uint16 T_b;                          /* '<S161>/DriverMode' */
  uint16 T_m;                          /* '<S25>/EPBClsdReq' */
  uint8 OutportBufferForpmmd_num_vcuAdd;/* '<S4>/pmm_determine_modes' */
  GearLeverPos GearLeverPosSts;        /* '<S25>/GearLeverPosition' */
  GearLeverPos GearLeverPosSts_m;      /* '<S24>/GearLeverPosition' */
  DriveDir drid_e_driveDirSel;         /* '<S7>/Switch1' */
  uint8 UnitDelay_DSTATE;              /* '<S8>/Unit Delay' */
  uint8 UnitDelay7_DSTATE;             /* '<S25>/Unit Delay7' */
  uint8 UnitDelay9_DSTATE;             /* '<S25>/Unit Delay9' */
  uint8 UnitDelay2_DSTATE;             /* '<S25>/Unit Delay2' */
  uint8 UnitDelay_DSTATE_g;            /* '<S25>/Unit Delay' */
  uint8 UnitDelay8_DSTATE;             /* '<S25>/Unit Delay8' */
  HEVModeReq UnitDelay_DSTATE_m;       /* '<S6>/Unit Delay' */
  GearLeverPos UnitDelay4_DSTATE_g;    /* '<S25>/Unit Delay4' */
  GearLeverPos UnitDelay6_DSTATE;      /* '<S25>/Unit Delay6' */
  GearLeverPos UnitDelay1_DSTATE_h;    /* '<S25>/Unit Delay1' */
  GearLeverPos UnitDelay5_DSTATE;      /* '<S25>/Unit Delay5' */
  GearLeverPos UnitDelay3_DSTATE;      /* '<S25>/Unit Delay3' */
  GearLeverPos UnitDelay3_DSTATE_c;    /* '<S89>/Unit Delay3' */
  GearLeverPos UnitDelay3_DSTATE_l;    /* '<S88>/Unit Delay3' */
  GearLeverPos UnitDelay3_DSTATE_p;    /* '<S87>/Unit Delay3' */
  GearLeverPos UnitDelay3_DSTATE_m;    /* '<S86>/Unit Delay3' */
  GearLeverPos UnitDelay_DSTATE_c;     /* '<S24>/Unit Delay' */
  uint8 is_c5_hmm;                     /* '<S3>/Hybrid_Mode_Manager' */
  uint8 is_active_c5_hmm;              /* '<S3>/Hybrid_Mode_Manager' */
  uint8 is_c7_swc_VOMM;                /* '<S162>/DriverMode' */
  uint8 is_active_c7_swc_VOMM;         /* '<S162>/DriverMode' */
  uint8 is_c6_swc_VOMM;                /* '<S161>/DriverMode' */
  uint8 is_active_c6_swc_VOMM;         /* '<S161>/DriverMode' */
  uint8 is_c14_Ricardo_SW_dev_lib;     /* '<S134>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev_li;/* '<S134>/timed_delay' */
  uint8 is_c5_swc_VOMM;                /* '<S25>/GearLeverPosition' */
  uint8 is_active_c5_swc_VOMM;         /* '<S25>/GearLeverPosition' */
  uint8 is_c4_swc_VOMM;                /* '<S25>/EPBClsdReq' */
  uint8 is_active_c4_swc_VOMM;         /* '<S25>/EPBClsdReq' */
  uint8 is_c2_swc_VOMM;                /* '<S24>/GearLeverPosition' */
  uint8 is_active_c2_swc_VOMM;         /* '<S24>/GearLeverPosition' */
  uint8 is_c3_swc_VOMM;                /* '<S24>/BrakePedalPushFirst' */
  uint8 is_active_c3_swc_VOMM;         /* '<S24>/BrakePedalPushFirst' */
  uint8 is_c6_vsm;                     /* '<S5>/VehicleStartManager' */
  uint8 is_active_c6_vsm;              /* '<S5>/VehicleStartManager' */
  uint8 is_c1_pmm;                     /* '<S197>/pmm_power_modes' */
  uint8 is_NoActiveReq;                /* '<S197>/pmm_power_modes' */
  uint8 is_active_c1_pmm;              /* '<S197>/pmm_power_modes' */
  uint8 is_c3_pmm;                     /* '<S209>/network_modes' */
  uint8 is_active_c3_pmm;              /* '<S209>/network_modes' */
  uint8 is_c4_pmm;                     /* '<S209>/Chart' */
  uint8 is_active_c4_pmm;              /* '<S209>/Chart' */
  uint8 is_c12_Ricardo_SW_dev_lib;     /* '<S205>/timed_delay' */
  uint8 is_active_c12_Ricardo_SW_dev_li;/* '<S205>/timed_delay' */
  uint8 is_c12_Ricardo_SW_dev_lib_p;   /* '<S199>/timed_delay' */
  uint8 is_active_c12_Ricardo_SW_dev__o;/* '<S199>/timed_delay' */
  boolean SportMod;                    /* '<S162>/DriverMode' */
  boolean EcoMod;                      /* '<S162>/DriverMode' */
  boolean InitMod;                     /* '<S162>/DriverMode' */
  boolean SportMod_o;                  /* '<S161>/DriverMode' */
  boolean EcoMod_j;                    /* '<S161>/DriverMode' */
  boolean InitMod_n;                   /* '<S161>/DriverMode' */
  boolean Merge;                       /* '<S66>/Merge' */
  boolean GearLeverFrmD_c;             /* '<S24>/GearLeverPosition' */
  boolean GearLeverFrmR_m;             /* '<S24>/GearLeverPosition' */
  boolean StartReq;                    /* '<S5>/VehicleStartManager' */
  boolean DelayInput1_DSTATE;          /* '<S153>/Delay Input1' */
  boolean DelayInput1_DSTATE_l;        /* '<S11>/Delay Input1' */
  boolean UnitDelay1_DSTATE;           /* '<S6>/Unit Delay1' */
  boolean DelayInput1_DSTATE_k;        /* '<S62>/Delay Input1' */
  boolean DelayInput1_DSTATE_p;        /* '<S124>/Delay Input1' */
  boolean DelayInput1_DSTATE_n;        /* '<S125>/Delay Input1' */
  boolean DelayInput1_DSTATE_ns;       /* '<S126>/Delay Input1' */
  boolean DelayInput1_DSTATE_n2;       /* '<S127>/Delay Input1' */
  boolean DelayInput1_DSTATE_ld;       /* '<S128>/Delay Input1' */
  boolean DelayInput1_DSTATE_g;        /* '<S63>/Delay Input1' */
  boolean DelayInput1_DSTATE_d;        /* '<S64>/Delay Input1' */
  boolean DelayInput1_DSTATE_j;        /* '<S65>/Delay Input1' */
  boolean DelayInput1_DSTATE_h;        /* '<S79>/Delay Input1' */
  boolean DelayInput1_DSTATE_i;        /* '<S80>/Delay Input1' */
  boolean DelayInput1_DSTATE_e;        /* '<S81>/Delay Input1' */
  boolean UnitDelay9_DSTATE_f;         /* '<S66>/Unit Delay9' */
  boolean UnitDelay1_DSTATE_f;         /* '<S66>/Unit Delay1' */
  boolean UnitDelay2_DSTATE_a;         /* '<S66>/Unit Delay2' */
  boolean UnitDelay4_DSTATE;           /* '<S5>/Unit Delay4' */
  boolean epbClsdFlg;                  /* '<S25>/GearLeverPosition' */
  boolean EPBRelease_prev;             /* '<S25>/GearLeverPosition' */
  boolean EPBRelease_start;            /* '<S25>/GearLeverPosition' */
  boolean EPBActive_prev;              /* '<S25>/GearLeverPosition' */
  boolean EPBActive_start;             /* '<S25>/GearLeverPosition' */
} ARID_DEF_swc_VOMM_T;

/* Invariant block signals (default storage) */
typedef struct {
  const float32 MinMax;                /* '<S166>/MinMax' */
  const uint8 Constant;                /* '<S7>/Constant' */
  boolean DataTypeConversion140;       /* '<Root>/Data Type Conversion140' */
  boolean DataTypeConversion142;       /* '<Root>/Data Type Conversion142' */
  boolean DataTypeConversion143;       /* '<Root>/Data Type Conversion143' */
  boolean DataTypeConversion146;       /* '<Root>/Data Type Conversion146' */
  boolean DataTypeConversion147;       /* '<Root>/Data Type Conversion147' */
  boolean DataTypeConversion149;       /* '<Root>/Data Type Conversion149' */
  boolean DataTypeConversion150;       /* '<Root>/Data Type Conversion150' */
  const boolean RelationalOperator13;  /* '<S166>/Relational Operator13' */
  const boolean LogicalOperator6;      /* '<S225>/Logical Operator6' */
  EngStartType DataTypeConversion137;  /* '<Root>/Data Type Conversion137' */
  EngStartType DataTypeConversion138;  /* '<Root>/Data Type Conversion138' */
} ConstB_swc_VOMM_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_swc_VOMM_T swc_VOMM_ARID_DEF;
extern const ConstB_swc_VOMM_T swc_VOMM_ConstB;/* constant block i/o */

/* Exported data declaration */
#define swc_VOMM_START_SEC_CONST_VOLATILE
#include "swc_VOMM_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_CAL */
extern const volatile boolean dric_b_enaSportModeIn4WDMode;/* Referenced by: '<S8>/Constant7' */

/* Enable Sport Mode when 4WD mode is selected by the driver */
extern const volatile boolean dric_b_gearLvrPos_ovrdflg;
                          /* Referenced by: '<S32>/dric_b_gearLvrPos_ovrdflg' */
extern const volatile boolean dric_b_resetModeReqAtIgnON;/* Referenced by: '<S6>/Constant16' */

/* Reset Mode request at Ignition ON */
extern const volatile boolean dric_b_useGearLvrPosFromCan;/* Referenced by: '<S7>/Constant1' */

/* Use Gear Lever position from CAN */
extern const volatile HEVModeReq dric_e_driverModeReqInit;/* Referenced by: '<S6>/Constant17' */

/* Initial Mode request */
extern const volatile HEVModeReq dric_e_driverModeReqSel[32];/* Referenced by: '<S6>/Constant18' */

/* Mode Request Table */
extern const volatile GearLeverPos dric_e_gearLvrPos_ovrdval;
                          /* Referenced by: '<S32>/dric_e_gearLvrPos_ovrdval' */
extern const volatile float32 dric_t_P2NDebTm_s;/* Referenced by: '<S25>/Constant14' */

/* Gear lever Position Detection timeout */
extern const volatile float32 dric_t_driGearLvrPosTout_s;/* Referenced by:
                                                          * '<S24>/Constant12'
                                                          * '<S25>/Constant12'
                                                          */

/* Gear lever Position Detection timeout */
extern const volatile uint16 dric_t_epbClsReqTout_s;/* Referenced by: '<S25>/Constant4' */

/* Driver gear lever operation debounce time */
extern const volatile float32 dric_tm_driverModeReq4WDDeb_s;/* Referenced by: '<S6>/Constant11' */

/* Mode request debounce when 4WD mode is selected by the driver */
extern const volatile float32 dric_tm_driverModeReqECODeb_s;/* Referenced by: '<S6>/Constant7' */

/* Mode request debounce when ECO mode is selected by the driver */
extern const volatile float32 dric_tm_driverModeReqEVDeb_s;/* Referenced by: '<S6>/Constant5' */

/* Mode request debounce when EV mode is selected  by the driver */
extern const volatile float32 dric_tm_driverModeReqHEVDeb_s;/* Referenced by: '<S6>/Constant14' */

/* Mode request debounce when HEV mode is selected  by the driver */
extern const volatile float32 dric_tm_driverModeReqSPORTDeb_s;/* Referenced by: '<S6>/Constant9' */

/* Mode request debounce when SPORT mode is selected by the driver */
extern const volatile float32 dric_tm_gearLvrLckInd_s;/* Referenced by:
                                                       * '<S66>/Constant11'
                                                       * '<S66>/Constant14'
                                                       * '<S66>/Constant9'
                                                       */

/* Driver gear lever operation debounce time */
extern const volatile float32 dric_v_spdRstAutoP_kph;/* Referenced by: '<S76>/Constant3' */

/* AUTO P Vehicle Reset speed */
extern const volatile float32 dric_v_vehMoveThd_kph;/* Referenced by:
                                                     * '<S24>/Constant1'
                                                     * '<S25>/Constant1'
                                                     */

/* Vehicle Stopped threshold */
extern const volatile float32 dric_v_vehStoppedThd_kph;/* Referenced by:
                                                        * '<S24>/Constant2'
                                                        * '<S25>/Constant2'
                                                        */

/* Vehicle Stopped threshold */
extern const volatile boolean hmmc_b_dcBusDischargeType;/* Referenced by: '<S166>/Constant1' */

/* Different auto discharge strategies type calibration */
extern const volatile boolean hmmc_b_hmmModeReq_ovrdflg;
                         /* Referenced by: '<S168>/hmmc_b_hmmModeReq_ovrdflg' */
extern const volatile boolean hmmc_b_hmmState_ovrdflg;
                           /* Referenced by: '<S169>/hmmc_b_hmmState_ovrdflg' */
extern const volatile HEVModeReq hmmc_e_hmmModeReq_ovrdval;
                         /* Referenced by: '<S168>/hmmc_e_hmmModeReq_ovrdval' */
extern const volatile HybModeMngr hmmc_e_hmmState_ovrdval;
                           /* Referenced by: '<S169>/hmmc_e_hmmState_ovrdval' */
extern const volatile float32 hmmc_u_dcBusDischargeThr_V;/* Referenced by: '<S166>/Constant2' */

/* DC bus discharge threshold */
extern const volatile boolean obcc_b_enbChgCblChk;/* Referenced by: '<S195>/Constant1' */

/* Enable Charge Cable Check for Power Hold */
extern const volatile boolean pmmc_b_chgCANPwrHold;/* Referenced by: '<S194>/Constant' */

/* Retain powerhold if charger CAN is detected */
extern const volatile uint8 pmmc_num_vcuAddr;/* Referenced by: '<S209>/Constant9' */
extern const volatile uint8 pmmc_st_CanModeDisableReq;/* Referenced by: '<S209>/Constant19' */

/* CanMode disable request */
extern const volatile uint32 pmmc_st_dftStayAwk;/* Referenced by: '<S209>/Constant2' */

/* Stay awake reason Default */
extern const volatile uint32 pmmc_st_keyOnStayAwk;/* Referenced by: '<S209>/Constant18' */

/* Stay awake reason Key On */
extern const volatile uint32 pmmc_st_obcWkUpStayAwk;/* Referenced by: '<S209>/Constant4' */

/* Stay awake reason OBC Wake Up */
extern const volatile uint32 pmmc_st_resdStayAwk;/* Referenced by: '<S209>/Constant3' */

/* Stay awake reason Reserved */
extern const volatile float32 pmmc_tm_afterRunTmOut_s;/* Referenced by: '<S197>/Constant2' */

/* After run time out in PMM */
extern const volatile float32 pmmc_tm_chgCanAfterRun_s;/* Referenced by: '<S195>/Constant5' */

/* Time to hold power up after loss of CCS on CAN signal */
extern const volatile float32 pmmc_tm_chgHwAfterRun_s;/* Referenced by: '<S195>/Constant2' */

/* Time to hold power up after loss of charge wakeup input */
extern const volatile float32 pmmc_tm_driveAfterRun_s;/* Referenced by: '<S196>/Constant2' */

/* Time to hold power up after ignition off */
extern const volatile float32 pmmc_tm_fuTankLockThd_s;/* Referenced by: '<S209>/Constant16' */

/* Time threshold for for APU fuel tank lock */
extern const volatile float32 pmmc_tm_fuTankUnlockThd_s;/* Referenced by: '<S209>/Constant17' */

/* Time threshold for for APU fuel tank unlock */
extern const volatile float32 pmmc_tm_ptCanNmStRdyThd_s;/* Referenced by: '<S209>/Constant14' */

/* Time threshold for Pp_PtCan_CanNm_NmState is ready */
extern const volatile float32 pmmc_tm_ptCanNmStSlpThd_s;/* Referenced by: '<S209>/Constant15' */

/* Time threshold for Pp_PtCan_CanNm_NmState is not ready */
extern const volatile float32 pmmc_tm_pwrHoldReqDelayTime_s;/* Referenced by: '<S191>/Constant5' */

/* Power hold request delay time */
extern const volatile float32 pmmc_v_maxShutdown_kph;/* Referenced by: '<S194>/Constant5' */

/* Maximum speed at which shutdown mode is permitted */
extern const volatile float32 swcvomm_dric_tm_drvGearLvrLck_s;/* Referenced by:
                                                               * '<S99>/Constant'
                                                               * '<S105>/Constant'
                                                               * '<S111>/Constant'
                                                               * '<S117>/Constant'
                                                               */

/* Driver gear lever operation error debounce time */
extern const volatile float32 swcvomm_dric_tm_drvGearReqDly_s;/* Referenced by:
                                                               * '<S77>/Constant1'
                                                               * '<S77>/Constant6'
                                                               */

/* Driver gear lever operation debounce time */
extern const volatile float32 swcvomm_dric_tm_drvVehSpdChk_s;/* Referenced by: '<S76>/Constant14' */

/* Vehicle Speed check time */
extern const volatile float32 swcvomm_dric_tm_pedRel_s;/* Referenced by: '<S76>/Constant20' */

/* Vehicle Speed check time */
extern const volatile boolean swcvomm_vsmc_b_enaPTReadyVehRun;/* Referenced by: '<S5>/Constant4' */

/* Enable PT Ready determination of Vehicle Run */
extern const volatile boolean vsmc_b_PTDisabled_ovrdflg;
                         /* Referenced by: '<S239>/vsmc_b_PTDisabled_ovrdflg' */
extern const volatile boolean vsmc_b_PTDisabled_ovrdval;
                         /* Referenced by: '<S239>/vsmc_b_PTDisabled_ovrdval' */
extern const volatile boolean vsmc_b_PTEnabled_ovrdflg;
                          /* Referenced by: '<S240>/vsmc_b_PTEnabled_ovrdflg' */
extern const volatile boolean vsmc_b_PTEnabled_ovrdval;
                          /* Referenced by: '<S240>/vsmc_b_PTEnabled_ovrdval' */
extern const volatile boolean vsmc_b_VehRunRaw_ovrdflg;
                          /* Referenced by: '<S223>/vsmc_b_VehRunRaw_ovrdflg' */
extern const volatile boolean vsmc_b_VehRunRaw_ovrdval;
                          /* Referenced by: '<S223>/vsmc_b_VehRunRaw_ovrdval' */
extern const volatile boolean vsmc_b_VehRun_ovrdflg;
                             /* Referenced by: '<S222>/vsmc_b_VehRun_ovrdflg' */
extern const volatile boolean vsmc_b_VehRun_ovrdval;
                             /* Referenced by: '<S222>/vsmc_b_VehRun_ovrdval' */
extern const volatile boolean vsmc_b_VehStrt_ovrdflg;
                            /* Referenced by: '<S224>/vsmc_b_VehStrt_ovrdflg' */
extern const volatile boolean vsmc_b_VehStrt_ovrdval;
                            /* Referenced by: '<S224>/vsmc_b_VehStrt_ovrdval' */
extern const volatile boolean vsmc_b_enaAbort;/* Referenced by: '<S221>/Constant2' */
extern const volatile boolean vsmc_b_enaStrtWithGearPN;/* Referenced by: '<S221>/Constant1' */

/* Enable Start with P/N gear */
extern const volatile boolean vsmc_b_enaStrtWithPlugUnknown;/* Referenced by: '<S221>/Constant3' */

/* Enable Start with external charger status unknown */
extern const volatile boolean vsmc_b_enaVehStopIfEngStalls;/* Referenced by: '<S5>/Constant3' */

/* Enable Vehicle Stop if engine stalls */
extern const volatile boolean vsmc_b_enableQuickStrt;/* Referenced by: '<S5>/Constant1' */

/* Enable Quick Start */
extern const volatile float32 vsmc_tm_StartDemLatchTimeout_s;/* Referenced by: '<S5>/Constant2' */

/* Vehicle start demand latch timeout */
extern const volatile float32 vsmc_tm_StartReqTimeout_s;/* Referenced by: '<S5>/Constant7' */

/* Vehicle start request timeout */
extern const volatile float32 vsmc_v_PTOffThr_kph;/* Referenced by: '<S225>/Constant5' */

/* Vehicle speed threshold for system shutdown */
extern const volatile float32 vsmc_v_enaVehStrtThd_kph;/* Referenced by: '<S221>/Constant5' */

/* Vehicle speed threshold to enable start */
#define swc_VOMM_STOP_SEC_CONST_VOLATILE
#include "swc_VOMM_MemMap.h"
#define swc_VOMM_START_SEC_VAR
#include "swc_VOMM_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_SIG */
extern boolean drid_b_DriModAct;       /* '<S8>/AND' */

/* VehicleStopped  */
extern boolean drid_b_DriModWriteflg;  /* '<S8>/Logical Operator6' */

/* egsmParkReq  */
extern boolean drid_b_VehicleMove;     /* '<S25>/Logical Operator2' */

/* VehicleMove  */
extern boolean drid_b_VehicleStopped;  /* '<S25>/Logical Operator1' */

/* VehicleStopped  */
extern boolean drid_b_egsmParkReq;     /* '<S76>/Switch10' */

/* egsmParkReq  */
extern boolean drid_b_veh4WDModActv;   /* '<S8>/Signal Conversion1' */

/* 4WD Mode selected by the driver */
extern boolean drid_b_vehSportModActv; /* '<S157>/Switch' */

/* Sport Mode selected by the driver */
extern HEVModeReq drid_e_drvrHEVModReq;/* '<S6>/Switch8' */

/* HEV Mode requested by the driver */
extern GearLeverPos drid_e_gearLvrPos; /* '<S144>/Switch2' */

/* Gear Lever Position */
extern uint8 drid_st_DriModRead;       /* '<S155>/C Caller1' */

/* Gear Req  */
extern uint8 drid_st_DriModWrite;      /* '<S8>/Switch1' */

/* Gear Req  */
extern boolean hmmd_b_EVModeActive;    /* '<S165>/Logical Operator' */

/* EV mode active */
extern boolean hmmd_b_HVBusDischrgComplete;/* '<S166>/Switch' */

/* HV Bus discharge complete */
extern boolean hmmd_b_bHVReady;        /* '<S166>/Relational Operator4' */

/* HV system ready */
extern HybModeMngr hmmd_e_hmmState;    /* '<S188>/Switch2' */

/* Hybrid Mode Manager State */
extern boolean pmmd_b_ActivityReq;     /* '<S194>/Logical Operator1' */

/* Strategy still active - powerhold requested */
extern boolean pmmd_b_chgCanPwrHold;   /* '<S195>/Logical Operator' */

/* Power hold request due to charger CAN */
extern boolean pmmd_b_chgHwPwrHold;    /* '<S199>/timed_delay' */

/* Power hold request due to charger hardware line */
extern boolean pmmd_b_chgPwrHold;      /* '<S195>/Logical Operator3' */

/* Power hold request due to charger */
extern boolean pmmd_b_drivePwrHold;    /* '<S205>/timed_delay' */

/* Internal power hold request */
extern boolean pmmd_b_emsWake;         /* '<S191>/Signal Conversion' */

/* EMS wakeup control output */
extern boolean pmmd_b_hsdFltClear;     /* '<S209>/network_modes' */

/* Fault Clear HSD Flag */
extern boolean pmmd_b_nmRdySlp;        /* '<S209>/network_modes' */

/* NM ready to sleep */
extern boolean pmmd_b_nmSts;           /* '<S209>/Constant5' */

/* NM status */
extern boolean pmmd_b_nmWkUp;          /* '<S209>/network_modes' */

/* NM wake up command */
extern boolean pmmd_b_peuWake;         /* '<S191>/Signal Conversion1' */

/* PEU wakeup control output */
extern boolean pmmd_b_pwrHoldAny;      /* '<S197>/Logical Operator4' */

/* Internal power hold request */
extern boolean pmmd_b_pwrHoldReq;      /* '<S191>/Signal Conversion2' */

/* External power hold request */
extern boolean pmmd_b_req_charging;    /* '<S195>/Logical Operator1' */

/* Assert power hold request */
extern boolean pmmd_b_req_drive;       /* '<S196>/Logical Operator7' */

/* Assert power hold request */
extern boolean pmmd_b_startReq;        /* '<S189>/Logical Operator4' */

/* Authorized driver Start Request */
extern boolean pmmd_b_vcuAwb;          /* '<S209>/Switch4' */

/* VCU AWB */
extern boolean pmmd_b_vcuRmr;          /* '<S209>/Constant6' */

/* VCU RMR */
extern uint8 pmmd_bm_netModeReq[2];    /* '<S210>/Signal Conversion' */

/* Network mode request */
extern NMStatus pmmd_e_CanNMSts;       /* '<S209>/network_modes' */

/* Network mode control status */
extern PmmMode pmmd_e_mode;            /* '<S197>/pmm_power_modes' */

/* Overall power mode) */
extern uint8 pmmd_st_bdCanModeReq;     /* '<S209>/network_modes' */

/* CCan Com Mode Request */
extern uint8 pmmd_st_ptCanModeReq;     /* '<S209>/network_modes' */

/* PtCan Com Mode Request */
extern uint32 pmmd_st_stayAwkReason;   /* '<S209>/Switch14' */

/* VCU stay awake reason */
extern uint8 pmmd_st_vcuPwrActvMod;    /* '<S209>/Switch2' */

/* VCU power active mode */
extern uint8 pmmd_st_vcuWkUpReason;    /* '<S209>/Chart' */

/* VCU wake up reason */
extern float32 pmmd_tm_fuTankLockDeb_s;/* '<S209>/network_modes' */

/* Turn on delay timer for APU fuel tank lock */
extern float32 pmmd_tm_fuTankUnlockDeb_s;/* '<S209>/network_modes' */

/* Turn on delay timer for APU fuel tank unlock */
extern float32 pmmd_tm_ptCanNmStRdyDeb_s;/* '<S209>/network_modes' */

/* Turn on delay timer for Pp_PtCan_CanNm_NmState is ready */
extern float32 pmmd_tm_ptCanNmStSlpDeb_s;/* '<S209>/network_modes' */

/* Turn on delay timer for Pp_PtCan_CanNm_NmState is not ready */
extern boolean swcvomm_drid_b_adcGearCtrlEn;/* '<S42>/Logical Operator1' */

/* ADC Gear Control  */
extern boolean swcvomm_drid_b_autoParkFlg;/* '<S134>/timed_delay' */

/* Auto P Flg  */
extern boolean swcvomm_drid_b_drvOffSeatFlg;/* '<S76>/Logical Operator10' */

/* driver off seat flg */
extern boolean swcvomm_drid_b_epbClsdReq;/* '<S25>/EPBClsdReq' */

/* EPB Closed Req  */
extern boolean swcvomm_drid_b_gearPosVld;/* '<S25>/Logical Operator5' */

/* current Gear Lever position valid flg  */
extern boolean swcvomm_drid_b_vehEcoModActv;/* '<S157>/Switch1' */

/* ECO Mode  */
extern uint8 swcvomm_drid_st_adcGearLvrReq;/* '<S42>/Switch1' */

/* ADC Gear Req  */
extern uint8 swcvomm_drid_st_egsmGearReq;/* '<S25>/Switch10' */

/* Gear Req  */
extern uint8 swcvomm_drid_st_egsmGearReqRaw;/* '<S7>/Signal Conversion1' */

/* Gear Req Raw */
extern uint8 swcvomm_drid_st_gearLvrLckInd;/* '<S66>/Switch2' */

/* driver Gear Lever LOCK  */
extern boolean vsmd_b_PTDisabled;      /* '<S241>/Switch2' */

/* PowerTrain disabled */
extern boolean vsmd_b_PTEnabled;       /* '<S242>/Switch2' */

/* PowerTrain enabled */
extern boolean vsmd_b_StartDemRaw;     /* '<S221>/Logical Operator5' */
extern boolean vsmd_b_VehRun;          /* '<S235>/Switch2' */

/* Vehicle running */
extern boolean vsmd_b_VehRunRaw;       /* '<S236>/Switch2' */

/* Vehicle running raw */
extern boolean vsmd_b_VehStrt;         /* '<S237>/Switch2' */

/* Vehicle start / started */
extern uint8 vsmd_st_vsmStatus;        /* '<S5>/VehicleStartManager' */

/* Vehicle Start Manager Status */
#define swc_VOMM_STOP_SEC_VAR
#include "swc_VOMM_MemMap.h"

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'swc_VOMM'
 * '<S1>'   : 'swc_VOMM/VOMM'
 * '<S2>'   : 'swc_VOMM/VOMM/DRI_DriveModesManagment'
 * '<S3>'   : 'swc_VOMM/VOMM/HMM_ModeManager'
 * '<S4>'   : 'swc_VOMM/VOMM/PMM_PowerModeManager'
 * '<S5>'   : 'swc_VOMM/VOMM/VSM_VehicleStartManager'
 * '<S6>'   : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DriverModeSelection'
 * '<S7>'   : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection'
 * '<S8>'   : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection'
 * '<S9>'   : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DriverModeSelection/Compare To Constant'
 * '<S10>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DriverModeSelection/Compare To Constant2'
 * '<S11>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DriverModeSelection/Detect Increase'
 * '<S12>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DriverModeSelection/Enumerated Constant1'
 * '<S13>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DriverModeSelection/state_mapping'
 * '<S14>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DriverModeSelection/turnON_delay_4WD'
 * '<S15>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DriverModeSelection/turnON_delay_ECO'
 * '<S16>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DriverModeSelection/turnON_delay_EV'
 * '<S17>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DriverModeSelection/turnON_delay_HEV'
 * '<S18>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DriverModeSelection/turnON_delay_SPORT'
 * '<S19>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DriverModeSelection/turnON_delay_4WD/timed_delay'
 * '<S20>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DriverModeSelection/turnON_delay_ECO/timed_delay'
 * '<S21>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DriverModeSelection/turnON_delay_EV/timed_delay'
 * '<S22>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DriverModeSelection/turnON_delay_HEV/timed_delay'
 * '<S23>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DriverModeSelection/turnON_delay_SPORT/timed_delay'
 * '<S24>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos1'
 * '<S25>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2'
 * '<S26>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Enumerated Constant'
 * '<S27>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Enumerated Constant1'
 * '<S28>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Enumerated Constant2'
 * '<S29>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Enumerated Constant3'
 * '<S30>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Enumerated Constant4'
 * '<S31>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Enumerated Constant5'
 * '<S32>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Ovrd_e_gearLvrPos'
 * '<S33>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos1/BrakePedalPushFirst'
 * '<S34>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos1/Enumerated Constant1'
 * '<S35>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos1/Enumerated Constant10'
 * '<S36>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos1/Enumerated Constant2'
 * '<S37>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos1/Enumerated Constant3'
 * '<S38>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos1/Enumerated Constant4'
 * '<S39>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos1/Enumerated Constant5'
 * '<S40>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos1/Enumerated Constant9'
 * '<S41>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos1/GearLeverPosition'
 * '<S42>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/ADCGearControl'
 * '<S43>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Compare To Constant'
 * '<S44>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Compare To Constant1'
 * '<S45>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Compare To Constant10'
 * '<S46>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Compare To Constant11'
 * '<S47>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Compare To Constant12'
 * '<S48>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Compare To Constant13'
 * '<S49>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Compare To Constant14'
 * '<S50>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Compare To Constant15'
 * '<S51>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Compare To Constant16'
 * '<S52>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Compare To Constant17'
 * '<S53>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Compare To Constant18'
 * '<S54>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Compare To Constant2'
 * '<S55>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Compare To Constant3'
 * '<S56>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Compare To Constant4'
 * '<S57>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Compare To Constant5'
 * '<S58>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Compare To Constant6'
 * '<S59>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Compare To Constant7'
 * '<S60>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Compare To Constant8'
 * '<S61>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Compare To Constant9'
 * '<S62>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Detect Increase1'
 * '<S63>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Detect Increase2'
 * '<S64>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Detect Increase3'
 * '<S65>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Detect Increase5'
 * '<S66>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn'
 * '<S67>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/EPBClsdReq'
 * '<S68>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Enumerated Constant1'
 * '<S69>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Enumerated Constant10'
 * '<S70>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Enumerated Constant2'
 * '<S71>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Enumerated Constant3'
 * '<S72>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Enumerated Constant4'
 * '<S73>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Enumerated Constant5'
 * '<S74>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/Enumerated Constant9'
 * '<S75>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearLeverPosition'
 * '<S76>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearP Managment'
 * '<S77>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearReqDelay'
 * '<S78>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/SR_latch'
 * '<S79>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/Detect Increase1'
 * '<S80>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/Detect Increase2'
 * '<S81>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/Detect Increase4'
 * '<S82>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/Enumerated Constant'
 * '<S83>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/Enumerated Constant1'
 * '<S84>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/Enumerated Constant2'
 * '<S85>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/Enumerated Constant3'
 * '<S86>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearD'
 * '<S87>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearN'
 * '<S88>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearP'
 * '<S89>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearR'
 * '<S90>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/SR_latch'
 * '<S91>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/SR_latch1'
 * '<S92>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/SR_latch2'
 * '<S93>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/turnON_delay'
 * '<S94>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/turnON_delay1'
 * '<S95>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/turnON_delay2'
 * '<S96>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearD/Enumerated Constant10'
 * '<S97>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearD/Enumerated Constant2'
 * '<S98>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearD/SR_latch'
 * '<S99>'  : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearD/TurnOnDelay'
 * '<S100>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearD/TurnOnDelay/turnON_delay'
 * '<S101>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearD/TurnOnDelay/turnON_delay/timed_delay'
 * '<S102>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearN/Enumerated Constant1'
 * '<S103>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearN/Enumerated Constant10'
 * '<S104>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearN/SR_latch'
 * '<S105>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearN/TurnOnDelay'
 * '<S106>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearN/TurnOnDelay/turnON_delay'
 * '<S107>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearN/TurnOnDelay/turnON_delay/timed_delay'
 * '<S108>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearP/Enumerated Constant'
 * '<S109>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearP/Enumerated Constant10'
 * '<S110>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearP/SR_latch'
 * '<S111>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearP/TurnOnDelay'
 * '<S112>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearP/TurnOnDelay/turnON_delay'
 * '<S113>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearP/TurnOnDelay/turnON_delay/timed_delay'
 * '<S114>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearR/Enumerated Constant10'
 * '<S115>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearR/Enumerated Constant3'
 * '<S116>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearR/SR_latch'
 * '<S117>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearR/TurnOnDelay'
 * '<S118>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearR/TurnOnDelay/turnON_delay'
 * '<S119>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/GearR/TurnOnDelay/turnON_delay/timed_delay'
 * '<S120>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/turnON_delay/timed_delay'
 * '<S121>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/turnON_delay1/timed_delay'
 * '<S122>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/DrvrGearLvrLockIndcn/turnON_delay2/timed_delay'
 * '<S123>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearP Managment/Compare To Constant'
 * '<S124>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearP Managment/Detect Decrease'
 * '<S125>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearP Managment/Detect Increase'
 * '<S126>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearP Managment/Detect Increase1'
 * '<S127>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearP Managment/Detect Increase2'
 * '<S128>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearP Managment/Detect Increase3'
 * '<S129>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearP Managment/Enumerated Constant'
 * '<S130>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearP Managment/Enumerated Constant1'
 * '<S131>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearP Managment/Enumerated Constant2'
 * '<S132>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearP Managment/Enumerated Constant3'
 * '<S133>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearP Managment/SR_latch'
 * '<S134>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearP Managment/turnON_delay3'
 * '<S135>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearP Managment/turnON_delay5'
 * '<S136>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearP Managment/turnON_delay3/timed_delay'
 * '<S137>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearP Managment/turnON_delay5/timed_delay'
 * '<S138>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearReqDelay/Enumerated Constant1'
 * '<S139>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearReqDelay/Enumerated Constant2'
 * '<S140>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearReqDelay/turnON_delay'
 * '<S141>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearReqDelay/turnON_delay1'
 * '<S142>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearReqDelay/turnON_delay/timed_delay'
 * '<S143>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Calc_GearLeverPos2/GearReqDelay/turnON_delay1/timed_delay'
 * '<S144>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/DrivingDirectionSelection/Ovrd_e_gearLvrPos/override_signal'
 * '<S145>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Compare To Constant'
 * '<S146>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Compare To Constant1'
 * '<S147>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Compare To Constant2'
 * '<S148>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Compare To Constant3'
 * '<S149>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Compare To Constant4'
 * '<S150>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Compare To Constant5'
 * '<S151>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Compare To Constant6'
 * '<S152>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Compare To Constant7'
 * '<S153>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Detect Increase'
 * '<S154>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Enumerated Constant3'
 * '<S155>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Subsystem'
 * '<S156>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Subsystem1'
 * '<S157>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Subsystem2'
 * '<S158>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Subsystem2/Compare To Constant'
 * '<S159>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Subsystem2/Compare To Constant1'
 * '<S160>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Subsystem2/Compare To Constant2'
 * '<S161>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Subsystem2/Subsystem'
 * '<S162>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Subsystem2/Subsystem1'
 * '<S163>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Subsystem2/Subsystem/DriverMode'
 * '<S164>' : 'swc_VOMM/VOMM/DRI_DriveModesManagment/SportModeSelection/Subsystem2/Subsystem1/DriverMode'
 * '<S165>' : 'swc_VOMM/VOMM/HMM_ModeManager/CheckActiveMode'
 * '<S166>' : 'swc_VOMM/VOMM/HMM_ModeManager/HVBusDischarge'
 * '<S167>' : 'swc_VOMM/VOMM/HMM_ModeManager/Hybrid_Mode_Manager'
 * '<S168>' : 'swc_VOMM/VOMM/HMM_ModeManager/Ovrd_e_hmmModeReq'
 * '<S169>' : 'swc_VOMM/VOMM/HMM_ModeManager/Ovrd_e_hmmState'
 * '<S170>' : 'swc_VOMM/VOMM/HMM_ModeManager/model_info1'
 * '<S171>' : 'swc_VOMM/VOMM/HMM_ModeManager/CheckActiveMode/Enumerated Constant'
 * '<S172>' : 'swc_VOMM/VOMM/HMM_ModeManager/CheckActiveMode/Enumerated Constant1'
 * '<S173>' : 'swc_VOMM/VOMM/HMM_ModeManager/CheckActiveMode/Enumerated Constant11'
 * '<S174>' : 'swc_VOMM/VOMM/HMM_ModeManager/CheckActiveMode/Enumerated Constant12'
 * '<S175>' : 'swc_VOMM/VOMM/HMM_ModeManager/CheckActiveMode/Enumerated Constant13'
 * '<S176>' : 'swc_VOMM/VOMM/HMM_ModeManager/CheckActiveMode/Enumerated Constant14'
 * '<S177>' : 'swc_VOMM/VOMM/HMM_ModeManager/CheckActiveMode/Enumerated Constant15'
 * '<S178>' : 'swc_VOMM/VOMM/HMM_ModeManager/CheckActiveMode/Enumerated Constant16'
 * '<S179>' : 'swc_VOMM/VOMM/HMM_ModeManager/CheckActiveMode/Enumerated Constant4'
 * '<S180>' : 'swc_VOMM/VOMM/HMM_ModeManager/CheckActiveMode/Enumerated Constant5'
 * '<S181>' : 'swc_VOMM/VOMM/HMM_ModeManager/CheckActiveMode/Enumerated Constant6'
 * '<S182>' : 'swc_VOMM/VOMM/HMM_ModeManager/CheckActiveMode/Enumerated Constant7'
 * '<S183>' : 'swc_VOMM/VOMM/HMM_ModeManager/CheckActiveMode/Enumerated Constant8'
 * '<S184>' : 'swc_VOMM/VOMM/HMM_ModeManager/CheckActiveMode/Enumerated Constant9'
 * '<S185>' : 'swc_VOMM/VOMM/HMM_ModeManager/HVBusDischarge/Enumerated Constant10'
 * '<S186>' : 'swc_VOMM/VOMM/HMM_ModeManager/HVBusDischarge/Enumerated Constant4'
 * '<S187>' : 'swc_VOMM/VOMM/HMM_ModeManager/Ovrd_e_hmmModeReq/override_signal'
 * '<S188>' : 'swc_VOMM/VOMM/HMM_ModeManager/Ovrd_e_hmmState/override_signal'
 * '<S189>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_det_startReq'
 * '<S190>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes'
 * '<S191>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_power'
 * '<S192>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_det_startReq/Enumerated Constant'
 * '<S193>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/DocBlockDescription1'
 * '<S194>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_activityReq'
 * '<S195>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_det_charge'
 * '<S196>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_det_drive'
 * '<S197>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_mode'
 * '<S198>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_det_charge/DocBlockDescription'
 * '<S199>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_det_charge/turnOFF_delay'
 * '<S200>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_det_charge/turnOFF_delay1'
 * '<S201>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_det_charge/turnOFF_delay/timed_delay'
 * '<S202>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_det_charge/turnOFF_delay1/timed_delay'
 * '<S203>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_det_drive/DocBlockDescription'
 * '<S204>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_det_drive/Enumerated Constant3'
 * '<S205>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_det_drive/turnOFF_delay'
 * '<S206>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_det_drive/turnOFF_delay/timed_delay'
 * '<S207>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_mode/pmm_network_mode'
 * '<S208>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_mode/pmm_power_modes'
 * '<S209>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_mode/pmm_network_mode/NM'
 * '<S210>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_mode/pmm_network_mode/pmm_gen_netreq'
 * '<S211>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_mode/pmm_network_mode/pmm_set_afterrun_mask'
 * '<S212>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_mode/pmm_network_mode/pmm_set_run_mask'
 * '<S213>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_mode/pmm_network_mode/NM/Chart'
 * '<S214>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_determine_modes/pmm_mode/pmm_network_mode/NM/network_modes'
 * '<S215>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_power/Enumerated Constant'
 * '<S216>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_power/SR_latch'
 * '<S217>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_power/turnOFF_delay'
 * '<S218>' : 'swc_VOMM/VOMM/PMM_PowerModeManager/pmm_power/turnOFF_delay/timed_delay'
 * '<S219>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/Compare To Constant1'
 * '<S220>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/Compare To Constant2'
 * '<S221>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/EnableStart'
 * '<S222>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/Ovrd_b_VehRun'
 * '<S223>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/Ovrd_b_VehRunRaw'
 * '<S224>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/Ovrd_b_VehStrt'
 * '<S225>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/PowertrainMode'
 * '<S226>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/SR_latch'
 * '<S227>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/VehicleStartManager'
 * '<S228>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/model_info1'
 * '<S229>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/EnableStart/Enumerated Constant1'
 * '<S230>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/EnableStart/Enumerated Constant2'
 * '<S231>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/EnableStart/Enumerated Constant3'
 * '<S232>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/EnableStart/Enumerated Constant4'
 * '<S233>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/EnableStart/Enumerated Constant5'
 * '<S234>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/EnableStart/Enumerated Constant6'
 * '<S235>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/Ovrd_b_VehRun/override_signal'
 * '<S236>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/Ovrd_b_VehRunRaw/override_signal'
 * '<S237>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/Ovrd_b_VehStrt/override_signal'
 * '<S238>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/PowertrainMode/Enumerated Constant1'
 * '<S239>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/PowertrainMode/Ovrd_b_PTDisabled'
 * '<S240>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/PowertrainMode/Ovrd_b_PTEnabled'
 * '<S241>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/PowertrainMode/Ovrd_b_PTDisabled/override_signal'
 * '<S242>' : 'swc_VOMM/VOMM/VSM_VehicleStartManager/PowertrainMode/Ovrd_b_PTEnabled/override_signal'
 */
#endif                                 /* RTW_HEADER_swc_VOMM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

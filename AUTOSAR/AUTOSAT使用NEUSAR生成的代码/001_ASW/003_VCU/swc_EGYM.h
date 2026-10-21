/*
 * File: swc_EGYM.h
 *
 * Code generated for Simulink model 'swc_EGYM'.
 *
 * Model version                  : 6.175
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jun 10 09:48:41 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_swc_EGYM_h_
#define RTW_HEADER_swc_EGYM_h_
#ifndef swc_EGYM_COMMON_INCLUDES_
#define swc_EGYM_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_swc_EGYM.h"
#endif                                 /* swc_EGYM_COMMON_INCLUDES_ */

#include "Rte_Type.h"

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
  boolean vild_st_pepsRKECom;
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

#ifndef DEFINED_TYPEDEF_FOR_vcsb_EGYM_
#define DEFINED_TYPEDEF_FOR_vcsb_EGYM_

typedef struct {
  uint8 emgd_st_gearDmd;
  float32 accd_pwr_maxPwrLim_kW;
  float32 accd_pwr_minPwrLim_kW;
  float32 dccd_i_outCurrMaxLim_A;
  float32 dccd_i_inpCurrMaxLim_A;
  float32 dccd_u_outVoltSetP_V;
  float32 emgd_n_engSpdTgtSHEVMode_rpm;
  float32 emgd_tq_crsMSGChgDem_Nm;
  float32 emgd_tq_whlEAD2ChgDem_Nm;
  float32 emgd_tq_trsm1ClthTMMChgDem_Nm;
  float32 emgd_tq_whlEAD1ChgDem_Nm;
  float32 emgd_n_engSpdTgtPHEVIdleMode_rpm;
  float32 emgd_tq_trsm1ClthTMMPHEVMode_Nm;
  float32 accd_pwr_hvAttpwr_kW;
  boolean egmd_b_dcdcEnbAllowFlg;
  boolean egmd_b_ptcEnbAllowFlg;
  boolean egmd_b_acEnbAllowFlg;
  boolean egmd_b_mcuEnbFlg;
  float32 egmd_pwr_accmHvClPwrAllwd_kW;
  float32 egmd_pwr_ptcHvHtPwrAllwd_kW;
  float32 egmd_pwr_mcuHvAttpwr_kW;
  float32 egmd_i_bmshAlwChgCurrMax;
  uint8 egmd_pct_vcuChgDepReq;
  uint8 egmd_st_vcuChgLimResp;
  boolean egmd_b_obcEnbAllowFlg;
  boolean egmd_b_ptcRearEnbAllowFlg;
  boolean egmd_b_zeroPwrFb;
  boolean egmd_b_accyEnbFlg;
  float32 egmd_pwr_acwpHeatPwrCnsAllwd;
} vcsb_EGYM;

#endif

/* PublicStructure Variables for Internal Data, for system '<S41>/timed_delay' */
typedef struct {
  float32 t_wait;                      /* '<S41>/timed_delay' */
  uint8 is_c12_Ricardo_SW_dev_lib;     /* '<S41>/timed_delay' */
  uint8 is_active_c12_Ricardo_SW_dev_li;/* '<S41>/timed_delay' */
} ARID_DEF_timed_delay_swc_EGYM_T;

/* PublicStructure Variables for Internal Data, for system '<S3>/turnOFF_delay' */
typedef struct {
  ARID_DEF_timed_delay_swc_EGYM_T ARID_DEF_timed_delay;/* '<S41>/timed_delay' */
} ARID_DEF_turnOFF_delay_swc_EG_T;

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  ARID_DEF_turnOFF_delay_swc_EG_T ARID_DEF_turnOFF_delay8;/* '<S3>/turnOFF_delay8' */
  ARID_DEF_timed_delay_swc_EGYM_T ARID_DEF_timed_delay;/* '<S48>/timed_delay' */
  ARID_DEF_turnOFF_delay_swc_EG_T ARID_DEF_turnOFF_delay6;/* '<S3>/turnOFF_delay6' */
  ARID_DEF_turnOFF_delay_swc_EG_T ARID_DEF_turnOFF_delay5;/* '<S3>/turnOFF_delay5' */
  ARID_DEF_turnOFF_delay_swc_EG_T ARID_DEF_turnOFF_delay4;/* '<S3>/turnOFF_delay4' */
  ARID_DEF_turnOFF_delay_swc_EG_T ARID_DEF_turnOFF_delay3;/* '<S3>/turnOFF_delay3' */
  ARID_DEF_turnOFF_delay_swc_EG_T ARID_DEF_turnOFF_delay2;/* '<S3>/turnOFF_delay2' */
  ARID_DEF_turnOFF_delay_swc_EG_T ARID_DEF_turnOFF_delay1;/* '<S3>/turnOFF_delay1' */
  ARID_DEF_turnOFF_delay_swc_EG_T ARID_DEF_turnOFF_delay;/* '<S3>/turnOFF_delay' */
  float64 OutportBufferForaccd_pwr_maxPwr;
  float64 OutportBufferForaccd_pwr_minPwr;
  float32 DataTypeConversion17;        /* '<Root>/Data Type Conversion17' */
  float32 DataTypeConversion87;        /* '<Root>/Data Type Conversion87' */
  float32 DataTypeConversion86;        /* '<Root>/Data Type Conversion86' */
  float32 DataTypeConversion77;        /* '<Root>/Data Type Conversion77' */
  float32 DataTypeConversion94;        /* '<Root>/Data Type Conversion94' */
  float32 DataTypeConversion95;        /* '<Root>/Data Type Conversion95' */
  float32 DataTypeConversion96;        /* '<Root>/Data Type Conversion96' */
  float32 DataTypeConversion85;        /* '<Root>/Data Type Conversion85' */
  float32 DataTypeConversion116;       /* '<Root>/Data Type Conversion116' */
  float32 DataTypeConversion124;       /* '<Root>/Data Type Conversion124' */
  float32 DataTypeConversion3;         /* '<Root>/Data Type Conversion3' */
  uint8 DataTypeConversion100;         /* '<Root>/Data Type Conversion100' */
  uint8 DataTypeConversion118;         /* '<Root>/Data Type Conversion118' */
  uint8 DataTypeConversion92;          /* '<Root>/Data Type Conversion92' */
  uint8 DataTypeConversion93;          /* '<Root>/Data Type Conversion93' */
  uint8 DataTypeConversion114;         /* '<Root>/Data Type Conversion114' */
  uint8 DataTypeConversion121;         /* '<Root>/Data Type Conversion121' */
  uint8 DataTypeConversion120;         /* '<Root>/Data Type Conversion120' */
  uint8 DataTypeConversion122;         /* '<Root>/Data Type Conversion122' */
  uint8 DataTypeConversion123;         /* '<Root>/Data Type Conversion123' */
  uint8 DataTypeConversion125;         /* '<Root>/Data Type Conversion125' */
  uint8 DataTypeConversion126;         /* '<Root>/Data Type Conversion126' */
  uint8 DataTypeConversion110;         /* '<Root>/Data Type Conversion110' */
  uint8 DataTypeConversion2;           /* '<Root>/Data Type Conversion2' */
  uint8 DataTypeConversion4;           /* '<Root>/Data Type Conversion4' */
  boolean DataTypeConversion1;         /* '<Root>/Data Type Conversion1' */
  boolean DataTypeConversion76;        /* '<Root>/Data Type Conversion76' */
  boolean DataTypeConversion112;       /* '<Root>/Data Type Conversion112' */
  boolean DataTypeConversion127;       /* '<Root>/Data Type Conversion127' */
  boolean DataTypeConversion129;       /* '<Root>/Data Type Conversion129' */
  boolean OutportBufferForegmd_b_acEnbAll;/* '<S2>/Subsystem' */
  boolean UnitDelay_DSTATE;            /* '<S3>/Unit Delay' */
} ARID_DEF_swc_EGYM_T;

/* Invariant block signals for system '<S3>/turnOFF_delay' */
typedef struct {
  const float32 t_delay_off;           /* '<S41>/Saturation1' */
} ConstB_turnOFF_delay_swc_EGYM_T;

/* Invariant block signals (default storage) */
typedef struct {
  float32 DataTypeConversion108;       /* '<Root>/Data Type Conversion108' */
  uint8 DataTypeConversion106;         /* '<Root>/Data Type Conversion106' */
  uint8 DataTypeConversion107;         /* '<Root>/Data Type Conversion107' */
  const boolean Compare;               /* '<S16>/Compare' */
  const boolean egmd_b_acEnbAllowFlg;  /* '<S3>/Constant13' */
  ConstB_turnOFF_delay_swc_EGYM_T turnOFF_delay8;/* '<S3>/turnOFF_delay8' */
  ConstB_turnOFF_delay_swc_EGYM_T turnOFF_delay6;/* '<S3>/turnOFF_delay6' */
  ConstB_turnOFF_delay_swc_EGYM_T turnOFF_delay5;/* '<S3>/turnOFF_delay5' */
  ConstB_turnOFF_delay_swc_EGYM_T turnOFF_delay4;/* '<S3>/turnOFF_delay4' */
  ConstB_turnOFF_delay_swc_EGYM_T turnOFF_delay3;/* '<S3>/turnOFF_delay3' */
  ConstB_turnOFF_delay_swc_EGYM_T turnOFF_delay2;/* '<S3>/turnOFF_delay2' */
  ConstB_turnOFF_delay_swc_EGYM_T turnOFF_delay1;/* '<S3>/turnOFF_delay1' */
  ConstB_turnOFF_delay_swc_EGYM_T turnOFF_delay;/* '<S3>/turnOFF_delay' */
} ConstB_swc_EGYM_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_swc_EGYM_T swc_EGYM_ARID_DEF;
extern const ConstB_swc_EGYM_T swc_EGYM_ConstB;/* constant block i/o */

/* Exported data declaration */
#define swc_EGYM_START_SEC_CONST_VOLATILE
#include "swc_EGYM_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_CAL */
extern const volatile float32 egmc_fact_obcChg;/* Referenced by: '<S3>/Constant24' */

/* obcChgEf */
extern const volatile float32 egmc_pwr_accyPwr_kW;/* Referenced by:
                                                   * '<S3>/Constant37'
                                                   * '<S32>/Constant'
                                                   */

/* PtcRearPwr */
extern const volatile float32 egmc_pwr_dcdcChgMaxPwr;/* Referenced by: '<S3>/Constant1' */

/* DcdcMaxPwr */
extern const volatile float32 egmc_pwr_dcdcMaxPwr;/* Referenced by: '<S3>/Constant' */

/* DcdcMaxPwr */
extern const volatile float32 egmc_pwr_ewpMaxPwr_kW;/* Referenced by: '<S3>/Saturation2' */

/* ewpMaxPwr */
extern const volatile float32 egmc_pwr_mcuEnbPwr;/* Referenced by: '<S23>/Constant' */

/* MCU output min pwr */
extern const volatile float32 egmc_pwr_obcPwr_kW;/* Referenced by: '<S19>/Constant' */

/* PtcRearPwr */
extern const volatile float32 egmc_pwr_ptcMaxPwr;/* Referenced by: '<S38>/Constant' */

/* PtcMaxPwr */
extern const volatile float32 egmc_pwr_ptcRearPwr_kW;/* Referenced by: '<S17>/Constant' */

/* PtcRearPwr */
extern const volatile float32 egmc_tm_ptcDelyOff_s;/* Referenced by: '<S3>/Constant42' */

/* Ptc Dely off */
#define swc_EGYM_STOP_SEC_CONST_VOLATILE
#include "swc_EGYM_MemMap.h"
#define swc_EGYM_START_SEC_VAR
#include "swc_EGYM_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_SIG */
extern float32 accd_pwr_hvAttpwr_kW;   /* '<S3>/Add4' */

/* indicated power limiting allowed */
extern boolean egmd_b_accyEnbFlg;      /* '<S3>/Switch17' */

/* allow ACCY OutPut pwr flg */
extern boolean egmd_b_dcdcEnbAllowFlg; /* '<S3>/Switch9' */

/* allow DCDC enb flg */
extern boolean egmd_b_mcuEnbFlg;       /* '<S3>/Switch6' */

/* allow MCU OutPut pwr flg */
extern boolean egmd_b_obcEnbAllowFlg;  /* '<S3>/Switch13' */

/* allow discharge OutPut pwr flg */
extern boolean egmd_b_ptcEnbAllowFlg;  /* '<S3>/Switch10' */

/* allow PTC enb flg */
extern boolean egmd_b_ptcRearEnbAllowFlg;/* '<S3>/Switch11' */

/* allow PtcRear OutPut pwr flg */
extern boolean egmd_b_zeroPwrFb;       /* '<S3>/Logical Operator2' */

/* allow ACCY OutPut pwr flg */
extern float32 egmd_pwr_accmHvClPwrAllwd_kW;/* '<S3>/Saturation' */

/* indicated power limiting allowed */
extern float32 egmd_pwr_acwpHeatPwrCnsAllwd;/* '<S3>/Switch25' */

/* EWP power limiting allowed */
extern float32 egmd_pwr_ptcHvHtPwrAllwd_kW;/* '<S3>/Switch12' */

/* indicated power limiting allowed */
#define swc_EGYM_STOP_SEC_VAR
#include "swc_EGYM_MemMap.h"

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
 * '<Root>' : 'swc_EGYM'
 * '<S1>'   : 'swc_EGYM/EGYM__Energy_Manager'
 * '<S2>'   : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation'
 * '<S3>'   : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem'
 * '<S4>'   : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant1'
 * '<S5>'   : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant10'
 * '<S6>'   : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant11'
 * '<S7>'   : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant12'
 * '<S8>'   : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant13'
 * '<S9>'   : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant14'
 * '<S10>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant17'
 * '<S11>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant18'
 * '<S12>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant19'
 * '<S13>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant20'
 * '<S14>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant21'
 * '<S15>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant22'
 * '<S16>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant23'
 * '<S17>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant24'
 * '<S18>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant25'
 * '<S19>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant26'
 * '<S20>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant27'
 * '<S21>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant28'
 * '<S22>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant29'
 * '<S23>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant3'
 * '<S24>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant30'
 * '<S25>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant31'
 * '<S26>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant32'
 * '<S27>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant33'
 * '<S28>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant34'
 * '<S29>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant35'
 * '<S30>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant36'
 * '<S31>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant37'
 * '<S32>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant38'
 * '<S33>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant39'
 * '<S34>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant4'
 * '<S35>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant40'
 * '<S36>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant5'
 * '<S37>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant6'
 * '<S38>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant7'
 * '<S39>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant8'
 * '<S40>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/Compare To Constant9'
 * '<S41>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/turnOFF_delay'
 * '<S42>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/turnOFF_delay1'
 * '<S43>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/turnOFF_delay2'
 * '<S44>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/turnOFF_delay3'
 * '<S45>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/turnOFF_delay4'
 * '<S46>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/turnOFF_delay5'
 * '<S47>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/turnOFF_delay6'
 * '<S48>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/turnOFF_delay7'
 * '<S49>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/turnOFF_delay8'
 * '<S50>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/turnOFF_delay/timed_delay'
 * '<S51>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/turnOFF_delay1/timed_delay'
 * '<S52>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/turnOFF_delay2/timed_delay'
 * '<S53>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/turnOFF_delay3/timed_delay'
 * '<S54>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/turnOFF_delay4/timed_delay'
 * '<S55>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/turnOFF_delay5/timed_delay'
 * '<S56>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/turnOFF_delay6/timed_delay'
 * '<S57>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/turnOFF_delay7/timed_delay'
 * '<S58>'  : 'swc_EGYM/EGYM__Energy_Manager/ACC_PowerLimitation/Subsystem/turnOFF_delay8/timed_delay'
 */
#endif                                 /* RTW_HEADER_swc_EGYM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: swc_SCOO.h
 *
 * Code generated for Simulink model 'swc_SCOO'.
 *
 * Model version                  : 6.56
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Sep  9 11:13:02 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_swc_SCOO_h_
#define RTW_HEADER_swc_SCOO_h_
#ifndef swc_SCOO_COMMON_INCLUDES_
#define swc_SCOO_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_swc_SCOO.h"
#endif                                 /* swc_SCOO_COMMON_INCLUDES_ */

#include "Rte_Type.h"

/* Includes for objects with custom storage classes */
#include "const_ImportedDefine.h"

/* user code (top of header file) */
#include "enum_Type.h"
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
  uint16 vild_st_flgFctCfgDspRemainRng;
  boolean vild_b_flgFctCfgDualAuthN;
  float32 vild_pct_mmiLocBkChgTarVal;
} vcib_VCIP;

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
} vcsb_HVSM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_vcsb_SCAP_
#define DEFINED_TYPEDEF_FOR_vcsb_SCAP_

typedef struct {
  float32 tqld_tq_axle2MaxTq_Nm;
  float32 tqld_tq_axle2MinTq_Nm;
  float32 eadd_tq_mot2MaxLTTq_Nm;
  float32 tqld_tq_whlMax_Nm;
  float32 eadd_tq_mot2MaxSTTq_Nm;
  float32 tqld_tq_whlMin_Nm;
  float32 eadd_tq_mot2MinLTTq_Nm;
  float32 eadd_tq_mot2MinSTTq_Nm;
  boolean eadd_b_mot2TqOff;
  float32 ptld_pwr_hvbDischAvail_kW;
} vcsb_SCAP;

#endif

#ifndef DEFINED_TYPEDEF_FOR_vcsb_TCOO_
#define DEFINED_TYPEDEF_FOR_vcsb_TCOO_

typedef struct {
  uint8 dtdd_st_RegenLvlDisp;
  float32 dtdd_tq_whlDragDem_Nm;
  float32 apdd_tq_whlDem_Nm;
  float32 tdad_tq_whlDemUnfilt_Nm;
  float32 tdad_tq_whlDemUnlim_Nm;
  float32 msgd_tq_targetTqReq_Nm;
  float32 tdad_tq_whlDem_Nm;
  float32 eadd_tq_mot2TgtTqReq_Nm;
  float32 eadd_tq_mot2TgtTq_Nm;
  float32 tvrd_tq_mot2TgtTqReq_Nm;
  float32 dtdd_tq_whlCoastDrgDem_Nm;
  boolean tqdd_b_gpOvrd;
  boolean dtdd_b_drvPfmncDrgDec;
  boolean tqdd_b_ehbDisEnbCreep;
  float32 tqdd_x_accPedlPosVirt_pct;
  boolean tqdd_b_accPedlPosVirtVld;
  float32 dtdd_tq_whlCstDrgDemNoEhb_Nm;
  uint8 tqdd_st_ehbOvrdActv;
  uint8 tqdd_st_ehbOvrdTyp;
  uint8 tqdd_st_whlAcceSupprsn;
} vcsb_TCOO;

#endif

#ifndef DEFINED_TYPEDEF_FOR_vcsb_HMIF_
#define DEFINED_TYPEDEF_FOR_vcsb_HMIF_

typedef struct {
  uint8 dspd_st_vehOverLoadSts;
  float32 dspd_d_vehCrsDst_km;
  boolean dspd_b_HazardReqLmpOn;
  float32 dspd_m_vehWeight_kg;
  boolean dspd_b_vehOvrLoadEnbl;
  uint8 dspd_st_vehCalNum;
  uint8 dspd_st_vehSubFailLvl;
  uint8 dspd_st_vehDrvMode;
  PowerFlowMode dspd_e_vehPwrFlow;
  uint8 dspd_st_vehFailLvl;
  boolean dspd_b_evLampOn;
  boolean dspd_b_hevLampOn;
  float32 dspd_q_hvbSOC_pct;
  float32 dspd_d_vehDrvRngEVMod_km;
  float32 dspd_V_engFuelConsAvg_lp100km;
  float32 dspd_d_vehDrvRngHEVMod_km;
  float32 dspd_num_AecEV_kWhp100km;
  float32 dspd_num_errorCode;
  uint8 dspd_st_drvModInd;
  uint8 dspd_st_drvrOptRmdr;
  float32 dspd_pwr_hvPwrCsmpt_kW;
  boolean dspd_b_turtleLmpOn;
  float32 dspd_pwr_hvPwrRemain_kW;
  float32 dspd_d_pmsOdoBckUpMilg_km;
  boolean dspd_b_ePTFault;
  uint16 dspd_st_drvPfmncRedn;
  boolean dspd_b_brkSysFlt;
  boolean dspd_b_CruisingDstSwtFb;
  float32 dspd_d_vehDrvRngStandard_km;
  boolean dspd_b_odoBckpEn;
  float32 dspd_d_odoTotal_km;
} vcsb_HMIF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_vcsb_OGVL_
#define DEFINED_TYPEDEF_FOR_vcsb_OGVL_

typedef struct {
  uint8 dtld_st_lockVehPer;
  uint8 dtld_st_versionConversion;
  uint8 dtld_st_spdLmtLevelReq;
  uint8 dtld_st_inventorySpdLmtReq;
  uint8 dtld_st_lifeCnt;
  float32 dtld_v_dstSpdLim_kph;
  uint8 dtld_st_tboxLifeSts;
  uint8 dtld_st_lockVehPerRxSts;
  uint8 dtld_st_verCvsRxSts;
  uint8 dtld_st_spdLmtLvRxSts;
  uint8 dtld_st_invSpdLmtRxSts;
  uint8 dtld_st_pwrOffCmdRxSts;
  uint8 dtld_st_pwrOffCmd;
} vcsb_OGVL;

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
} vcsb_DIAG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_vcsb_RMLK_
#define DEFINED_TYPEDEF_FOR_vcsb_RMLK_

typedef struct {
  /* Remote Lock Limit Speed */
  float32 rlcd_v_rmtCtrlFctSpdLim_kph;

  /* &#x9501;&#x8F66;&#x70B9;&#x4E4C;&#x9F9F;&#x7B49;&#x6807;&#x5FD7;&#x4F4D; */
  boolean rlcd_b_rmtCtrlTurtleLampOn;

  /* &#x9501;&#x8F66;&#x9650;&#x5236;&#x626D;&#x77E9;&#x6807;&#x5FD7;&#x4F4D; */
  boolean rlcd_b_rmtCtrlTqOff;

  /* &#x9501;&#x8F66;&#x6FC0;&#x6D3B;&#x9650;&#x5236;&#x6CB9;&#x95E8;&#x6807;&#x5FD7;&#x4F4D; */
  boolean rlcd_b_rmtCtrlAccPedlOff;

  /* &#x9501;&#x8F66;&#x529F;&#x80FD;&#x6FC0;&#x6D3B; */
  uint8 rlcd_num_FunLockVehActive;

  /* &#x9632;&#x76D7;&#x9501;&#x8F66;&#x529F;&#x80FD;&#x6FC0;&#x6D3B; */
  uint8 rlcd_num_FunAnti_DismantleActive;

  /* &#x9501;&#x8F66;&#x9650;&#x901F;&#x7ED3;&#x679C; */
  uint8 rlcd_num_LockLimResult;

  /* &#x9501;&#x8F66;&#x7C7B;&#x578B; */
  uint8 rlcd_num_LockVehType;

  /* &#x9501;&#x8F66;&#x6267;&#x884C;&#x72B6;&#x6001; */
  boolean rlcd_b_LockVehSts;

  /* PMS&#x53CD;&#x9988;&#x9501;&#x8F66;&#x6267;&#x884C;&#x7ED3;&#x679C; */
  uint8 rlcd_st_LockVehExecutedSts;
} vcsb_RMLK;

#endif

#ifndef DEFINED_TYPEDEF_FOR_vcsb_SCOO_
#define DEFINED_TYPEDEF_FOR_vcsb_SCOO_

typedef struct {
  float32 ccdd_tq_whlDemRawAdv_Nm;
  float32 ccdd_acc_vehAccTgt_mps2;
  boolean ccdd_b_accCtrlActv;
  float32 ccdd_acc_intAccTgt_mps2;
  CruiseSts_e ccdd_e_crsCtrlSts;
  float32 ccdd_v_crsCtrlTgtSpd_kph;
  CrModeMngr_e ccdd_e_crsCtrlSpdMode;
  CrsBtnSts ccdd_e_crsBtnSts;
  float32 ccdd_v_crsTgtSpdQuit_kph;
  float32 ccdd_tq_whlDem_Nm;
  boolean ccdd_b_crsCtrlAccPedlOvrd;
  CrsBtnErrSts ccdd_e_crsBtnErrSts;
  float32 ccdd_x_accPedlPosVirt_pct;
  boolean ctdd_b_clthCreepReq;
  float32 ctdd_tq_whlDem_Nm;
  boolean ctdd_b_eCreepReq;
  float32 ctdd_n_vehTgtCrpSpdFwd_kph;
  boolean vsld_b_vslTqIntvReq;
  float32 vsld_tq_whlMaxTqLimFast_Nm;
  float32 vsld_tq_whlMaxTqLimSlow_Nm;
  boolean esld_b_eslTqIntvReq;
  float32 esld_tq_crsMaxTqLimFast_Nm;
  float32 esld_tq_crsMaxTqLimSlow_Nm;
  boolean hhdd_b_hilHldEnab_flg;
  boolean escd_b_engSpdCtrlEnad;
  float32 escd_tq_crsEngSpdCtrlDmd_Nm;
  float32 escd_tq_crsEngSpdCtrlDmdSlow_Nm;
  float32 tscd_tq_tmmSpdCtrlTgt_Nm;
  boolean tscd_b_motSpdCtrlEnad;
  float32 vsld_v_vehMaxCfgSpd_kph;
  boolean ctdd_b_crpSlopeTrqOffsetEnHld;
  float32 ctdd_a_yrsLongAccAvgVld_mps2;
  float32 vsld_v_vehMaxSpd_kph;
} vcsb_SCOO;

#endif

/* PublicStructure Variables for Internal Data, for system '<S6>/turnON_delay' */
typedef struct {
  float32 t_wait;                      /* '<S16>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib;     /* '<S16>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev_li;/* '<S16>/timed_delay' */
} ARID_DEF_turnON_delay_swc_SCO_T;

/* PublicStructure Variables for Internal Data, for system '<S8>/SwitchRampCreepTrqDem' */
typedef struct {
  uint8 is_c11_Ricardo_SW_dev_lib;     /* '<S43>/Chart' */
  uint8 is_U2_TO_U1;                   /* '<S43>/Chart' */
  uint8 is_U1_TO_U2;                   /* '<S43>/Chart' */
  uint8 is_active_c11_Ricardo_SW_dev_li;/* '<S43>/Chart' */
} ARID_DEF_switch_ramp_swc_SCOO_T;

/* PublicStructure Variables for Internal Data, for system '<S86>/SR_latch' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S129>/Unit Delay' */
} ARID_DEF_SR_latch_swc_SCOO_T;

/* PublicStructure Variables for Internal Data, for system '<S3>/SwitchRampCreepTrqDem' */
typedef struct {
  uint8 is_c11_Ricardo_SW_dev_lib;     /* '<S130>/Chart' */
  uint8 is_U2_TO_U1;                   /* '<S130>/Chart' */
  uint8 is_U1_TO_U2;                   /* '<S130>/Chart' */
  uint8 is_active_c11_Ricardo_SW_dev_li;/* '<S130>/Chart' */
} ARID_DEF_switch_ramp_swc_SC_n_T;

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  ARID_DEF_switch_ramp_swc_SC_n_T ARID_DEF_SwitchRampCreepTrqDem;/* '<S3>/SwitchRampCreepTrqDem' */
  ARID_DEF_SR_latch_swc_SCOO_T ARID_DEF_SR_latch;/* '<S86>/SR_latch' */
  ARID_DEF_switch_ramp_swc_SCOO_T ARID_DEF_SwitchRampCreepTrqDe_m;/* '<S8>/SwitchRampCreepTrqDem' */
  ARID_DEF_turnON_delay_swc_SCO_T ARID_DEF_turnON_delay;/* '<S22>/turnON_delay' */
  ARID_DEF_turnON_delay_swc_SCO_T ARID_DEF_turnON_delay_c;/* '<S6>/turnON_delay' */
  float64 DataTypeConversion12;        /* '<Root>/Data Type Conversion12' */
  float64 DataTypeConversion21;        /* '<Root>/Data Type Conversion21' */
  float64 DataTypeConversion25;        /* '<Root>/Data Type Conversion25' */
  float64 DataTypeConversion30;        /* '<Root>/Data Type Conversion30' */
  float64 DataTypeConversion32;        /* '<Root>/Data Type Conversion32' */
  float64 DataTypeConversion37;        /* '<Root>/Data Type Conversion37' */
  float64 DataTypeConversion40;        /* '<Root>/Data Type Conversion40' */
  float64 DataTypeConversion43;        /* '<Root>/Data Type Conversion43' */
  float64 DataTypeConversion44;        /* '<Root>/Data Type Conversion44' */
  float64 DataTypeConversion45;        /* '<Root>/Data Type Conversion45' */
  float64 DataTypeConversion46;        /* '<Root>/Data Type Conversion46' */
  float64 UnitDelay_DSTATE;            /* '<S116>/Unit Delay' */
  float32 Delay1_DSTATE[2];            /* '<S111>/Delay1' */
  float32 Delay2_DSTATE[3];            /* '<S111>/Delay2' */
  float32 Delay3_DSTATE[4];            /* '<S111>/Delay3' */
  float32 Delay4_DSTATE[5];            /* '<S111>/Delay4' */
  float32 Delay5_DSTATE[6];            /* '<S111>/Delay5' */
  float32 Delay6_DSTATE[7];            /* '<S111>/Delay6' */
  float32 Delay7_DSTATE[8];            /* '<S111>/Delay7' */
  float32 Delay8_DSTATE[9];            /* '<S111>/Delay8' */
  float32 DataTypeConversion10;        /* '<Root>/Data Type Conversion10' */
  float32 DataTypeConversion11;        /* '<Root>/Data Type Conversion11' */
  float32 DataTypeConversion15;        /* '<Root>/Data Type Conversion15' */
  float32 DataTypeConversion17;        /* '<Root>/Data Type Conversion17' */
  float32 DataTypeConversion18;        /* '<Root>/Data Type Conversion18' */
  float32 DataTypeConversion19;        /* '<Root>/Data Type Conversion19' */
  float32 DataTypeConversion20;        /* '<Root>/Data Type Conversion20' */
  float32 DataTypeConversion5;         /* '<Root>/Data Type Conversion5' */
  float32 DataTypeConversion24;        /* '<Root>/Data Type Conversion24' */
  float32 DataTypeConversion42;        /* '<Root>/Data Type Conversion42' */
  float32 DataTypeConversion26;        /* '<Root>/Data Type Conversion26' */
  float32 DataTypeConversion27;        /* '<Root>/Data Type Conversion27' */
  float32 DataTypeConversion3;         /* '<Root>/Data Type Conversion3' */
  float32 DataTypeConversion7;         /* '<Root>/Data Type Conversion7' */
  float32 Switch;                      /* '<S4>/Switch' */
  float32 Switch_h;                    /* '<S137>/Switch' */
  float32 Switch1;                     /* '<S84>/Switch1' */
  float32 Product;                     /* '<S84>/Product' */
  float32 Plus;                        /* '<S84>/Plus' */
  float32 y;                           /* '<S43>/Chart' */
  float32 UnitDelay_DSTATE_b;          /* '<S143>/Unit Delay' */
  float32 Delay_DSTATE;                /* '<S86>/Delay' */
  float32 Delay_DSTATE_d;              /* '<S111>/Delay' */
  float32 UnitDelay_DSTATE_k;          /* '<S109>/Unit Delay' */
  float32 UnitDelay_DSTATE_bv;         /* '<S107>/Unit Delay' */
  float32 UD_DSTATE;                   /* '<S63>/UD' */
  float32 UnitDelay_DSTATE_a;          /* '<S61>/Unit Delay' */
  float32 UnitDelay_DSTATE_d;          /* '<S50>/Unit Delay' */
  float32 UD_DSTATE_g;                 /* '<S69>/UD' */
  float32 UnitDelay_DSTATE_g;          /* '<S82>/Unit Delay' */
  float32 UnitDelay_DSTATE_gu;         /* '<S80>/Unit Delay' */
  float32 UnitDelay_DSTATE_ah;         /* '<S75>/Unit Delay' */
  float32 UnitDelay_DSTATE_m;          /* '<S59>/Unit Delay' */
  float32 t_wait;                      /* '<S117>/timed_delay' */
  float32 Mean_AccVal;                 /* '<S111>/Mean' */
  float32 StandardDeviation_AccVal;    /* '<S111>/Standard Deviation' */
  float32 StandardDeviation_SqData;    /* '<S111>/Standard Deviation' */
  float32 t_wait_j;                    /* '<S62>/timed_delay' */
  float32 time;                        /* '<S7>/CruiseStates' */
  float32 Cruise_Speed_Dvl_Accum;      /* '<S7>/CruiseStates' */
  float32 time_c;                      /* '<S6>/Button_Sts' */
  uint8 DataTypeConversion13;          /* '<Root>/Data Type Conversion13' */
  uint8 DataTypeConversion14;          /* '<Root>/Data Type Conversion14' */
  uint8 DataTypeConversion31;          /* '<Root>/Data Type Conversion31' */
  uint8 DataTypeConversion9;           /* '<Root>/Data Type Conversion9' */
  PmmStatus DataTypeConversion41;      /* '<Root>/Data Type Conversion41' */
  ParkingStatus DataTypeConversion16;  /* '<Root>/Data Type Conversion16' */
  DriveDir DataTypeConversion2;        /* '<Root>/Data Type Conversion2' */
  BrakePedalStatus DataTypeConversion4;/* '<Root>/Data Type Conversion4' */
  CruiseSts_e UnitDelay1_DSTATE;       /* '<S22>/Unit Delay1' */
  CrModeMngr_e UnitDelay1_DSTATE_g;    /* '<S11>/Unit Delay1' */
  CrModeMngr_e UnitDelay1_DSTATE_gm;   /* '<S13>/Unit Delay1' */
  uint8 is_c14_Ricardo_SW_dev_lib;     /* '<S117>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev_li;/* '<S117>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib_g;   /* '<S62>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev__l;/* '<S62>/timed_delay' */
  uint8 is_c11_vsl;                    /* '<S7>/CruiseStates' */
  uint8 is_Cruise_Active;              /* '<S7>/CruiseStates' */
  uint8 is_Cruise_Active_p;            /* '<S7>/CruiseStates' */
  uint8 is_active_c11_vsl;             /* '<S7>/CruiseStates' */
  uint8 is_c1_vsl;                     /* '<S13>/Chart' */
  uint8 is_active_c1_vsl;              /* '<S13>/Chart' */
  uint8 is_c15_vsl;                    /* '<S6>/Button_Sts' */
  uint8 is_Cruise_Sts;                 /* '<S6>/Button_Sts' */
  uint8 is_Accel_Sts;                  /* '<S6>/Button_Sts' */
  uint8 is_Coast_Sts;                  /* '<S6>/Button_Sts' */
  uint8 is_active_c15_vsl;             /* '<S6>/Button_Sts' */
  uint8 is_c13_vsl;                    /* '<S11>/Chart' */
  uint8 is_active_c13_vsl;             /* '<S11>/Chart' */
  CruiseSts_e Cruise_Sts_Prev;         /* '<S7>/CruiseStates' */
  boolean DataTypeConversion1;         /* '<Root>/Data Type Conversion1' */
  boolean DataTypeConversion22;        /* '<Root>/Data Type Conversion22' */
  boolean LogicalOperator;             /* '<S1>/Logical Operator' */
  boolean DataTypeConversion36;        /* '<Root>/Data Type Conversion36' */
  boolean DataTypeConversion38;        /* '<Root>/Data Type Conversion38' */
  boolean DataTypeConversion39;        /* '<Root>/Data Type Conversion39' */
  boolean DataTypeConversion6;         /* '<Root>/Data Type Conversion6' */
  boolean DataTypeConversion8;         /* '<Root>/Data Type Conversion8' */
  boolean Relay2;                      /* '<S133>/Relay2' */
  boolean LogicalOperator_m;           /* '<S137>/Logical Operator' */
  boolean FixPtRelationalOperator;     /* '<S98>/FixPt Relational Operator' */
  boolean LogicalOperator_i;           /* '<S46>/Logical Operator' */
  boolean Butt_Cruise_Sts;             /* '<S6>/Button_Sts' */
  boolean Butt_Accel_Sts;              /* '<S6>/Button_Sts' */
  boolean Butt_Coast_Sts;              /* '<S6>/Button_Sts' */
  boolean LogicalOperator_l;           /* '<S49>/Logical Operator' */
  boolean ClippedPrev_DSTATE;          /* '<S141>/ClippedPrev' */
  boolean DelayInput1_DSTATE;          /* '<S126>/Delay Input1' */
  boolean init_DSTATE;                 /* '<S120>/init' */
  boolean DelayInput1_DSTATE_n;        /* '<S98>/Delay Input1' */
  boolean ClippedPrev_DSTATE_k;        /* '<S102>/ClippedPrev' */
  boolean init_DSTATE_p;               /* '<S109>/init' */
  boolean DelayInput1_DSTATE_p;        /* '<S14>/Delay Input1' */
  boolean DelayInput1_DSTATE_e;        /* '<S15>/Delay Input1' */
  boolean DelayInput1_DSTATE_k;        /* '<S18>/Delay Input1' */
  boolean DelayInput1_DSTATE_np;       /* '<S20>/Delay Input1' */
  boolean init_DSTATE_d;               /* '<S61>/init' */
  boolean init_DSTATE_k;               /* '<S50>/init' */
  boolean init_DSTATE_h;               /* '<S68>/init' */
  boolean ClippedPrev_DSTATE_n;        /* '<S77>/ClippedPrev' */
  boolean init_DSTATE_m;               /* '<S82>/init' */
  boolean ClippedPrev_DSTATE_b;        /* '<S67>/ClippedPrev' */
  boolean init_DSTATE_j;               /* '<S75>/init' */
  boolean ClippedPrev_DSTATE_g;        /* '<S52>/ClippedPrev' */
  boolean init_DSTATE_hd;              /* '<S59>/init' */
  boolean Relay1_Mode;                 /* '<S133>/Relay1' */
  boolean Relay4_Mode;                 /* '<S133>/Relay4' */
  boolean Relay2_Mode;                 /* '<S133>/Relay2' */
  boolean Relay_Mode;                  /* '<S83>/Relay' */
  boolean icLoad;                      /* '<S111>/Delay' */
  boolean icLoad_k;                    /* '<S111>/Delay1' */
  boolean icLoad_d;                    /* '<S111>/Delay2' */
  boolean icLoad_e;                    /* '<S111>/Delay3' */
  boolean icLoad_l;                    /* '<S111>/Delay4' */
  boolean icLoad_c;                    /* '<S111>/Delay5' */
  boolean icLoad_h;                    /* '<S111>/Delay6' */
  boolean icLoad_j;                    /* '<S111>/Delay7' */
  boolean icLoad_g;                    /* '<S111>/Delay8' */
  boolean Relay4_Mode_h;               /* '<S5>/Relay4' */
  boolean Relay1_Mode_p;               /* '<S5>/Relay1' */
  boolean Relay4_Mode_g;               /* '<S35>/Relay4' */
  boolean IC_FirstOutputTime;          /* '<S60>/IC' */
  boolean Relay4_Mode_n;               /* '<S51>/Relay4' */
  boolean IC_FirstOutputTime_o;        /* '<S65>/IC' */
  boolean Relay4_Mode_i;               /* '<S66>/Relay4' */
} ARID_DEF_swc_SCOO_T;

/* Invariant block signals (default storage) */
typedef struct {
  const float32 Constant;              /* '<S1>/Constant' */
  const boolean LogicalOperator2;      /* '<S102>/Logical Operator2' */
  const boolean LogicalOperator1;      /* '<S22>/Logical Operator1' */
  const boolean LogicalOperator1_e;    /* '<S51>/Logical Operator1' */
} ConstB_swc_SCOO_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: uDLookupTable4_maxIndex
   * Referenced by: '<S5>/2-D Lookup Table4'
   */
  uint32 uDLookupTable4_maxIndex[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S51>/1-D Lookup Table1'
   *   '<S51>/1-D Lookup Table2'
   */
  uint32 pooled9[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S66>/1-D Lookup Table1'
   *   '<S66>/1-D Lookup Table3'
   */
  uint32 pooled10[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S140>/2-D Lookup Table'
   *   '<S140>/2-D Lookup Table1'
   */
  uint32 pooled11[2];
} ConstP_swc_SCOO_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_swc_SCOO_T swc_SCOO_ARID_DEF;
extern const ConstB_swc_SCOO_T swc_SCOO_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_swc_SCOO_T swc_SCOO_ConstP;

/* Exported data declaration */
#define swc_SCOO_START_SEC_CONST_VOLATILE
#include "swc_SCOO_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_CAL */
extern const volatile float32 ccc_dacc_accTgtMaxRate_mps3;/* Referenced by: '<S47>/Constant4' */
extern const volatile float32 ccc_dacc_accTgtMinRate_mps3;/* Referenced by: '<S47>/Constant6' */
extern const volatile float32 ccda_crsSpdCtrl_X_VehSpd_kph[10];/* Referenced by:
                                                                * '<S76>/1-D Lookup Table'
                                                                * '<S66>/1-D Lookup Table'
                                                                */

/* Vehicle speed limit control - vehicle speed axis */
extern const volatile float32 ccda_crsSpdCtrl_Y_VehSpdErr_kph[11];/* Referenced by:
                                                                   * '<S76>/1-D Lookup Table1'
                                                                   * '<S76>/1-D Lookup Table2'
                                                                   */

/* Vehicle speed limit control - vehicle speed error axis */
extern const volatile float32 ccda_pedlPosVirt_X_VehSpd_kph[12];
                                   /* Referenced by: '<S5>/2-D Lookup Table4' */

/* Virtual accelerator Pedal position  - Vehicle Speed Axis */
extern const volatile float32 ccda_pedlPosVirt_Y_WhlDem_Nm[10];
                                   /* Referenced by: '<S5>/2-D Lookup Table4' */

/* Virtual accelerator Pedal position  - Wheel Torque Demand Axis */
extern const volatile float32 ccdc_acc_tqKiEnaVehAccErrHi_mps2;/* Referenced by: '<S66>/Relay4' */
extern const volatile float32 ccdc_acc_tqKiEnaVehAccErrLo_mps2;/* Referenced by: '<S66>/Relay4' */
extern const volatile float32 ccdc_acc_vehAccLongMin_mps2;/* Referenced by: '<S53>/Constant1' */
extern const volatile float32 ccdc_acc_vehAccTgtMax_mps2;/* Referenced by: '<S48>/Constant8' */
extern const volatile float32 ccdc_acc_vehAccTgtMin_mps2;/* Referenced by: '<S48>/Constant9' */
extern const volatile boolean ccdc_b_crsCtrlAccKiEna_ovrdflg;/* Referenced by: '<S51>/Constant9' */
extern const volatile boolean ccdc_b_crsCtrlAccKiEna_ovrdval;/* Referenced by: '<S51>/Constant1' */
extern const volatile boolean ccdc_b_crsCtrlBaseLineEna;/* Referenced by:
                                                         * '<S37>/Constant1'
                                                         * '<S37>/Constant9'
                                                         */
extern const volatile boolean ccdc_b_enaVehCrsCtrl;/* Referenced by:
                                                    * '<S22>/Constant2'
                                                    * '<S35>/Constant2'
                                                    */

/* Cruise Control Enable */
extern const volatile boolean ccdc_b_whlDem_ovrdflg;/* Referenced by: '<S34>/Constant2' */

/* Cruise Torque over flag */
extern const volatile float32 ccdc_dacc_vehAccLongDec_mps3;/* Referenced by: '<S53>/Constant7' */
extern const volatile float32 ccdc_dacc_vehAccLongInc_mps3;/* Referenced by: '<S53>/Constant6' */
extern const volatile float32 ccdc_dtq_crsCtrlTqDecGrad_Nmps;/* Referenced by: '<S8>/Constant6' */

/* Cruise Control Torque decrease gradient when disabled */
extern const volatile float32 ccdc_dtq_crsCtrlTqIncGrad_Nmps;/* Referenced by: '<S8>/Constant2' */

/* Cruise Control Torque increase gradient when enabled */
extern const volatile float32 ccdc_fact_crsSpdCtrlKd;/* Referenced by: '<S46>/Constant3' */

/* Vehicle cruise speed control - Kd (derivative) term gain */
extern const volatile float32 ccdc_l_vehTyreRadius_m;/* Referenced by: '<S66>/Constant1' */
extern const volatile float32 ccdc_m_vehMass_kg;/* Referenced by: '<S66>/Constant4' */
extern const volatile float32 ccdc_t_vehAccActTau_s;/* Referenced by: '<S65>/Constant4' */
extern const volatile float32 ccdc_tm_accelOvrdMax_s;/* Referenced by: '<S7>/Constant1' */

/* Maximum time allowed in override state */
extern const volatile float32 ccdc_tm_btnPrsd_s;/* Referenced by: '<S6>/Constant5' */

/* Time to confirm button has been pressed */
extern const volatile float32 ccdc_tm_btnRlsd_s;/* Referenced by: '<S6>/Constant3' */

/* Time to confirm button has been released */
extern const volatile float32 ccdc_tm_btnStuck_s;/* Referenced by: '<S6>/Constant1' */

/* Button Push Stuck Time */
extern const volatile float32 ccdc_tm_btnVltgAbn_s;/* Referenced by: '<S6>/Constant2' */

/* Time to confirm cruise button has been long pressed (cancel) */
extern const volatile float32 ccdc_tm_btnVltgOC_s;/* Referenced by: '<S6>/Constant7' */

/* Time to confirm cruise button has been long pressed (cancel) */
extern const volatile float32 ccdc_tm_btnVltgSCB_s;/* Referenced by: '<S6>/Constant6' */

/* Time to confirm cruise button has been long pressed (cancel) */
extern const volatile float32 ccdc_tm_btnVltgSCG_s;/* Referenced by: '<S6>/Constant14' */

/* Time to confirm cruise button has been long pressed (cancel) */
extern const volatile float32 ccdc_tm_cnclBtnDly_s;/* Referenced by: '<S6>/Constant22' */

/* Time to confirm cruise button has been long pressed (cancel) */
extern const volatile float32 ccdc_tm_crsBtnLongPrs_s;/* Referenced by: '<S7>/Constant5' */

/* Button Delay Time to detect long press */
extern const volatile float32 ccdc_tm_crsSpdCtrlDerivTc_s;/* Referenced by: '<S46>/Constant4' */

/* Vehicle cruise speed control Derivative term time constant */
extern const volatile float32 ccdc_tm_crsSpdUpdtDly_s;/* Referenced by: '<S7>/Constant10' */

/* Delay to update target speed during long press */
extern const volatile float32 ccdc_tm_vehAccLongActvWait_s;/* Referenced by: '<S53>/Constant4' */
extern const volatile float32 ccdc_tm_vehSpdDiffTmOut_s;/* Referenced by: '<S22>/Constant22' */

/* Maximum allowable speed deviation time-out */
extern const volatile float32 ccdc_tq_crsAccelPdlOvrdHi_Nm;/* Referenced by: '<S5>/Relay4' */

/* Cruise control overriden by accel pedal torque demand - high threshold */
extern const volatile float32 ccdc_tq_crsAccelPdlOvrdLo_Nm;/* Referenced by: '<S5>/Relay4' */

/* Cruise control overriden by accel pedal torque demand - low threshold */
extern const volatile float32 ccdc_tq_whlDem_ovrdval;/* Referenced by: '<S34>/Constant1' */

/* Cruise Torque over value */
extern const volatile float32 ccdc_u_btnVltgAbnHiThd_V;/* Referenced by: '<S6>/Constant15' */

/* Button voltage abnormal high threshold */
extern const volatile float32 ccdc_u_btnVltgAbnLoThd_V;/* Referenced by: '<S6>/Constant16' */

/* Button voltage abnormal low threshold */
extern const volatile float32 ccdc_u_btnVltgDftHiThd_V;/* Referenced by: '<S6>/Constant23' */

/* Button voltage Default high threshold */
extern const volatile float32 ccdc_u_btnVltgDftLoThd_V;/* Referenced by: '<S6>/Constant24' */

/* Button voltage Default low threshold */
extern const volatile float32 ccdc_u_btnVltgOCHiThd_V;/* Referenced by: '<S6>/Constant17' */

/* Button voltage OC high threshold */
extern const volatile float32 ccdc_u_btnVltgOCLoThd_V;/* Referenced by: '<S6>/Constant18' */

/* Button voltage OC low threshold */
extern const volatile float32 ccdc_u_btnVltgSCBHiThd_V;/* Referenced by: '<S6>/Constant19' */

/* Button voltage SCB high threshold */
extern const volatile float32 ccdc_u_btnVltgSCGLoThd_V;/* Referenced by: '<S6>/Constant20' */

/* Button voltage SCG low threshold */
extern const volatile float32 ccdc_u_crsBtnHiThd_V;/* Referenced by: '<S6>/Constant4' */

/* Cruise main button voltage high threshold */
extern const volatile float32 ccdc_u_crsBtnLoThd_V;/* Referenced by: '<S6>/Constant13' */

/* Cruise main button voltage low threshold */
extern const volatile float32 ccdc_u_resBtnHiThd_V;/* Referenced by: '<S6>/Constant8' */

/* Resume button voltage high threshold */
extern const volatile float32 ccdc_u_resBtnLoThd_V;/* Referenced by: '<S6>/Constant9' */

/* Resume button voltage low threshold */
extern const volatile float32 ccdc_u_setBtnHiThd_V;/* Referenced by: '<S6>/Constant10' */

/* Set button voltage high threshold */
extern const volatile float32 ccdc_u_setBtnLoThd_V;/* Referenced by: '<S6>/Constant11' */

/* Set button voltage low threshold */
extern const volatile float32 ccdc_v_accKiEnaVehSpdErrHi_kph;/* Referenced by: '<S51>/Relay4' */
extern const volatile float32 ccdc_v_accKiEnaVehSpdErrLo_kph;/* Referenced by: '<S51>/Relay4' */
extern const volatile float32 ccdc_v_crsSpdLargeChng_kph;/* Referenced by: '<S7>/Constant7' */

/* Cruise Target Speed large change */
extern const volatile float32 ccdc_v_crsSpdTipChng_kph;/* Referenced by: '<S7>/Constant6' */

/* Cruise Target Speed small change */
extern const volatile float32 ccdc_v_crsTgtSpdChngMax_kph;/* Referenced by: '<S7>/Constant8' */

/* Maximum target speed change allowed in one button press */
extern const volatile float32 ccdc_v_crsTgtSpdMax_kph;/* Referenced by: '<S7>/Constant2' */

/* Cruise Maximum Target Speed */
extern const volatile float32 ccdc_v_crsTgtSpdMin_kph;/* Referenced by: '<S7>/Constant3' */

/* Cruise Minimum Target Speed */
extern const volatile float32 ccdc_v_vehSpdDiffMax_kph;/* Referenced by: '<S22>/Constant20' */

/* Maximum allowable speed deviation from target */
extern const volatile float32 ccdc_v_vehSpdErrIntglEnagHi_kph;/* Referenced by: '<S35>/Relay4' */

/* Vehicle Speed error to disable the integral control */
extern const volatile float32 ccdc_v_vehSpdErrIntglEnagLo_kph;/* Referenced by: '<S35>/Relay4' */

/* Vehicle Speed error to enable the integral control */
extern const volatile float32 ccdc_v_vehSpdMaxEnaCrs_kph;/* Referenced by: '<S7>/Constant11' */

/* Vehicle Maximum Speed to Enable Cruise Control */
extern const volatile float32 ccdc_v_vehSpdMinEnaCrs_kph;/* Referenced by: '<S7>/Constant12' */

/* Vehicle Minimum Speed to Enable Cruise Control */
extern const volatile float32 ccdc_x_crsAccelPdlOvrdHi_pct;/* Referenced by: '<S5>/Relay1' */

/* Cruise control overriden by accel pedal position - high threshold */
extern const volatile float32 ccdc_x_crsAccelPdlOvrdLo_pct;/* Referenced by: '<S5>/Relay1' */

/* Cruise control overriden by accel pedal position - low threshold */
extern const volatile float32 ccdf_crsSpdCtrlFF_Y_Nm[10];/* Referenced by:
                                                          * '<S76>/1-D Lookup Table'
                                                          * '<S66>/1-D Lookup Table'
                                                          */

/* Vehicle cruise speed control feedforward torque Map */
extern const volatile float32 ccdf_crsSpdCtrlKi_Y_fact[11];
                                  /* Referenced by: '<S76>/1-D Lookup Table1' */

/* Vehicle cruise speed control - Ki (integral) Map */
extern const volatile float32 ccdf_crsSpdCtrlKp_Y_fact[11];
                                  /* Referenced by: '<S76>/1-D Lookup Table2' */

/* Vehicle cruise speed control - Kp (proportional) Map */
extern const volatile float32 ccdm_crsCtrlAccKi_X_VehSpdErr_kph[17];
                                  /* Referenced by: '<S51>/1-D Lookup Table2' */
extern const volatile float32 ccdm_crsCtrlAccKi_Y_VehSpdAct_kph[17];
                                  /* Referenced by: '<S51>/1-D Lookup Table2' */
extern const volatile float32 ccdm_crsCtrlAccKi_Z_fact[289];
                                  /* Referenced by: '<S51>/1-D Lookup Table2' */
extern const volatile float32 ccdm_crsCtrlAccKp_X_VehSpdErr_kph[17];
                                  /* Referenced by: '<S51>/1-D Lookup Table1' */
extern const volatile float32 ccdm_crsCtrlAccKp_Y_VehSpdAct_kph[17];
                                  /* Referenced by: '<S51>/1-D Lookup Table1' */
extern const volatile float32 ccdm_crsCtrlAccKp_Z_fact[289];
                                  /* Referenced by: '<S51>/1-D Lookup Table1' */
extern const volatile float32 ccdm_crsCtrlTqKi_X_VehAccErr_mps2[17];
                                  /* Referenced by: '<S66>/1-D Lookup Table3' */
extern const volatile float32 ccdm_crsCtrlTqKi_Y_VehAccAct_mps2[9];
                                  /* Referenced by: '<S66>/1-D Lookup Table3' */
extern const volatile float32 ccdm_crsCtrlTqKi_Z_fact[153];
                                  /* Referenced by: '<S66>/1-D Lookup Table3' */
extern const volatile float32 ccdm_crsCtrlTqKp_X_VehAccErr_mps2[17];
                                  /* Referenced by: '<S66>/1-D Lookup Table1' */
extern const volatile float32 ccdm_crsCtrlTqKp_Y_VehAccAct_mps2[9];
                                  /* Referenced by: '<S66>/1-D Lookup Table1' */
extern const volatile float32 ccdm_crsCtrlTqKp_Z_fact[153];
                                  /* Referenced by: '<S66>/1-D Lookup Table1' */
extern const volatile float32 ccdm_pedlPosVirt_Z_pct[120];
                                   /* Referenced by: '<S5>/2-D Lookup Table4' */

/* Virtual accelerator Pedal position */
extern const volatile float32 cdtc_fact_whlSpdCtrlKd;/* Referenced by: '<S84>/Constant3' */

/* Creep Derivative term gain */
extern const volatile float32 ctdc_a_crpSlopeGradThr_mps2;/* Referenced by: '<S114>/Constant' */
extern const volatile float32 ctdc_a_yrsLongAccAvgDnD_mps2;/* Referenced by: '<S122>/Constant' */
extern const volatile float32 ctdc_a_yrsLongAccAvgDnR_mps2;/* Referenced by: '<S124>/Constant' */
extern const volatile float32 ctdc_a_yrsLongAccAvgUpD_mps2;/* Referenced by: '<S121>/Constant' */
extern const volatile float32 ctdc_a_yrsLongAccAvgUpR_mps2;/* Referenced by: '<S123>/Constant' */
extern const volatile float32 ctdc_a_yrsLongAccDn_mps2;/* Referenced by: '<S113>/Constant' */
extern const volatile float32 ctdc_a_yrsLongAccUp_mps2;/* Referenced by: '<S112>/Constant' */
extern const volatile boolean ctdc_b_chkBrkPedlStsToEnaCrp;/* Referenced by: '<S83>/Constant3' */

/* Check brake pedal status to enable Creep */
extern const volatile boolean ctdc_b_chkPmmStsToEnaCrp;/* Referenced by: '<S83>/Constant6' */

/* Enable Creep if EPB is released */
extern const volatile boolean ctdc_b_enaCreepAftEPBRels;/* Referenced by: '<S83>/Constant2' */

/* Enable Creep if EPB is released */
extern const volatile boolean ctdc_b_enableCreep;/* Referenced by: '<S83>/Constant1' */

/* Enable Creep function */
extern const volatile boolean ctdc_b_slopeTrqOffsetEn;/* Referenced by: '<S86>/Constant1' */
extern const volatile float32 ctdc_dtq_CrpTqDisDecGrad_Nmps;/* Referenced by: '<S3>/Constant5' */

/* Wheel Creep Target Torque decrease gradient when disabled */
extern const volatile float32 ctdc_dtq_CrpTqEnaIncGrad_Nmps;/* Referenced by: '<S3>/Constant4' */

/* Wheel Creep Target Torque increase gradient when enabled */
extern const volatile float32 ctdc_fact_roadSlopeFilt;/* Referenced by: '<S86>/Constant2' */
extern const volatile float32 ctdc_tm_crpSlopeCalStepTm_ms;/* Referenced by: '<S116>/Constant1' */
extern const volatile float32 ctdc_tm_crpSlopeStopDly_s;/* Referenced by: '<S85>/Constant22' */
extern const volatile float32 ctdc_tm_whlSpdCtrlDerivTc_s;/* Referenced by: '<S84>/Constant1' */

/* Creep Derivative term time constant */
extern const volatile float32 ctdc_v_crpSlopeStopThr_kph;/* Referenced by: '<S115>/Constant' */
extern const volatile float32 ctdc_v_slopeTrqOffsetSpdDisa_kph;/* Referenced by: '<S125>/Constant' */
extern const volatile float32 ctdc_v_vehHiThrSafeDisCrp_kph;/* Referenced by: '<S83>/Relay' */

/* Vehicle speed high threshold for safe Creep disabling */
extern const volatile float32 ctdc_v_vehLoThrSafeDisCrp_kph;/* Referenced by: '<S83>/Relay' */

/* Vehicle speed low threshold for safe Creep disabling */
extern const volatile float32 ctdf_TgtTqKiMap_X_VehSpdErr_kph[6];
                                 /* Referenced by: '<S104>/1-D Lookup Table1' */

/* Creep Torque Demand Ki Map - Vehicle Speed Axis */
extern const volatile float32 ctdf_TgtTqKiMap_Y_Nm[6];
                                 /* Referenced by: '<S104>/1-D Lookup Table1' */

/* Creep Torque Demand Ki Map - Torque Demand */
extern const volatile float32 ctdf_TgtTqKpMap_X_VehSpdErr_kph[6];
                                  /* Referenced by: '<S104>/1-D Lookup Table' */

/* Creep Torque Demand Kp Map - Vehicle Speed Axis */
extern const volatile float32 ctdf_TgtTqKpMap_Y_Nm[6];
                                  /* Referenced by: '<S104>/1-D Lookup Table' */

/* Creep Torque Demand Kp Map - Torque Demand */
extern const volatile float32 ctdf_crpTgtTqFFMap_X_RoadSlope_deg[9];
                                  /* Referenced by: '<S84>/1-D Lookup Table2' */

/* Creep Torque Demand FeedForward Map - Road Slope Axis */
extern const volatile float32 ctdf_crpTgtTqFFMap_Y_Nm[9];
                                  /* Referenced by: '<S84>/1-D Lookup Table2' */

/* Creep Torque Demand FeedForward Map - Torque Demand */
extern const volatile float32 ctdf_slopeTrqOffsetFact_X_VehSpd_kph[7];
                                  /* Referenced by: '<S84>/1-D Lookup Table3' */
extern const volatile float32 ctdf_slopeTrqOffsetFact_Y[7];
                                  /* Referenced by: '<S84>/1-D Lookup Table3' */
extern const volatile float32 ctdf_slopeTrqOffsetRFact_X_VehSpd_kph[7];
                                  /* Referenced by: '<S84>/1-D Lookup Table4' */
extern const volatile float32 ctdf_slopeTrqOffsetRFact_Y[7];
                                  /* Referenced by: '<S84>/1-D Lookup Table4' */
extern const volatile float32 ctdf_whlTqMaxMap_X_VehSpd_kph[4];
                                  /* Referenced by: '<S84>/1-D Lookup Table1' */

/* Creep Max Torque Map - Vehicle Speed Axis */
extern const volatile float32 ctdf_whlTqMaxMap_Y_Nm[4];
                                  /* Referenced by: '<S84>/1-D Lookup Table1' */

/* Creep Max Torque Map - Torque Limit */
extern const volatile float32 swcscoo_ctda_CrpTgtSpd_X_brkPedlPos_pct[8];/* Referenced by:
                                                                      * '<S103>/1-D Lookup Table1'
                                                                      * '<S103>/1-D Lookup Table2'
                                                                      */

/* Creep Target Speed Map - Brake Pedal Position Axis */
extern const volatile float32 swcscoo_ctdf_CrpTgtFwdSpdMap_Y_kph[8];
                                 /* Referenced by: '<S103>/1-D Lookup Table2' */

/* Creep Target Speed Map - Forward Target Speed */
extern const volatile float32 swcscoo_ctdf_CrpTgtRevSpdMap_Y_kph[8];
                                 /* Referenced by: '<S103>/1-D Lookup Table1' */

/* Creep Target Speed Map - Reverse Target Speed */
extern const volatile float32 vsla_SpdLimCtrl_X_VehSpd_kph[11];/* Referenced by:
                                                                * '<S140>/2-D Lookup Table'
                                                                * '<S140>/2-D Lookup Table1'
                                                                */

/* Vehicle speed limit control - vehicle speed axis */
extern const volatile float32 vsla_SpdLimCtrl_Y_VehSpdErr_kph[11];/* Referenced by:
                                                                   * '<S140>/2-D Lookup Table'
                                                                   * '<S140>/2-D Lookup Table1'
                                                                   */

/* Vehicle speed limit control - vehicle speed error axis */
extern const volatile boolean vslc_b_brkMismatchActvLvl;/* Referenced by: '<S83>/Constant4' */

/* Brake mismatch signal active level */
extern const volatile boolean vslc_b_chkHhcStsToEnaCrp;/* Referenced by: '<S83>/Constant' */

/* Enable Creep if HHC is released */
extern const volatile boolean vslc_b_enaVehSpdLimr;/* Referenced by: '<S133>/Constant2' */

/* Enable Vehicle Speed Limiter */
extern const volatile boolean vslc_b_rmtCtrlSpdLmtEn;/* Referenced by: '<S145>/Constant7' */

/* remote limit speed Enable */
extern const volatile float32 vslc_v_vehMaxSpd;/* Referenced by: '<S138>/Constant8' */

/* Vehicle Speed limit  */
extern const volatile float32 vslc_v_vehMaxSpdFwdEco_kph;/* Referenced by: '<S146>/Constant20' */

/* Max Speed limit for Forward drive in Eco mode */
extern const volatile float32 vslc_v_vehMaxSpdFwdNorm_kph;/* Referenced by: '<S146>/Constant22' */

/* Max Speed limit for Forward drive in Norm mode */
extern const volatile float32 vslc_v_vehMaxSpdFwdPwr_kph;/* Referenced by: '<S146>/Constant21' */

/* Max Speed limit for Forward drive in Power mode */
extern const volatile float32 vslc_v_vehMaxSpdLimpHome1_kph;/* Referenced by: '<S145>/Constant1' */

/* Vehicle Speed limit for limp-home level 1 */
extern const volatile float32 vslc_v_vehMaxSpdLimpHome2_kph;/* Referenced by: '<S145>/Constant4' */

/* Vehicle Speed limit for limp-home level 2 */
extern const volatile float32 vslc_v_vehMaxSpdRvsDrv1_kph;/* Referenced by: '<S146>/Constant1' */

/* Max Speed limit for Reverse drive */
extern const volatile float32 vslc_v_vehMaxSpdRvsDrv_kph;/* Referenced by: '<S146>/Constant2' */

/* Max Speed limit for Reverse drive */
extern const volatile float32 vslc_v_vehMaxSpderr;/* Referenced by:
                                                   * '<S4>/Constant1'
                                                   * '<S138>/Constant1'
                                                   */

/* Vehicle Speed limit err  */
extern const volatile float32 vslc_v_vehSpdErrCtrlCfgHi_kph;/* Referenced by: '<S133>/Relay2' */

/* Vehicle Speed error to disable the integral control */
extern const volatile float32 vslc_v_vehSpdErrCtrlCfgLo_kph;/* Referenced by: '<S133>/Relay2' */

/* Vehicle Speed error to enable the integral control */
extern const volatile float32 vslc_v_vehSpdErrCtrlEnagHi_kph;/* Referenced by: '<S133>/Relay1' */

/* Vehicle Speed error to disable the VSL control */
extern const volatile float32 vslc_v_vehSpdErrCtrlEnagLo_kph;/* Referenced by: '<S133>/Relay1' */

/* Vehicle Speed error to enable the VSL control */
extern const volatile float32 vslc_v_vehSpdErrIntglEnagHi_kph;/* Referenced by: '<S133>/Relay4' */

/* Vehicle Speed error to disable the integral control */
extern const volatile float32 vslc_v_vehSpdErrIntglEnagLo_kph;/* Referenced by: '<S133>/Relay4' */

/* Vehicle Speed error to enable the integral control */
extern const volatile float32 vslm_SpdLimCtrlKi_Z_fact[121];
                                 /* Referenced by: '<S140>/2-D Lookup Table1' */

/* Vehicle speed limit control - Ki (integral) Map */
extern const volatile float32 vslm_SpdLimCtrlKp_Z_fact[121];
                                  /* Referenced by: '<S140>/2-D Lookup Table' */

/* Vehicle speed limit control - Kp (proportional) Map */
#define swc_SCOO_STOP_SEC_CONST_VOLATILE
#include "swc_SCOO_MemMap.h"
#define swc_SCOO_START_SEC_VAR
#include "swc_SCOO_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_SIG */
extern float32 ccdd_acc_intAccTgt_mps2;/* '<S55>/Switch' */
extern float32 ccdd_acc_vehAccActRaw_mps2;/* '<S65>/Divide' */
extern float32 ccdd_acc_vehAccAct_mps2;/* '<S68>/Data Type Conversion3' */
extern float32 ccdd_acc_vehAccErr_mps2;/* '<S66>/Add1' */
extern float32 ccdd_acc_vehAccSP_mps2; /* '<S60>/Divide1' */
extern float32 ccdd_acc_vehAccTgtIntgl_mps2;/* '<S58>/Product' */
extern float32 ccdd_acc_vehAccTgtLong_mps2;/* '<S61>/Data Type Conversion' */
extern float32 ccdd_acc_vehAccTgtProp_mps2;/* '<S57>/Switch1' */
extern float32 ccdd_acc_vehAccTgt_mps2;/* '<S50>/Data Type Conversion' */
extern boolean ccdd_b_accCtrlActv;     /* '<S47>/Logical Operator3' */
extern boolean ccdd_b_crsAccelResBtnPrsd;/* '<S11>/Chart' */

/* Button Accel Flag */
extern boolean ccdd_b_crsCnclBtnPrsd;  /* '<S15>/FixPt Relational Operator' */

/* Button Cancel Flag (Main Cruise Long Press) */
extern boolean ccdd_b_crsCoastSetBtnPrsd;/* '<S13>/Chart' */

/* Button Coast Flag */
extern boolean ccdd_b_crsCtrlAccKiEna; /* '<S51>/Switch' */
extern boolean ccdd_b_crsCtrlAccPedlOvrd;/* '<S5>/Logical Operator' */

/* Cruise Control Request Overrides Accelerator Pedal */
extern boolean ccdd_b_crsCtrlTqKiEna;  /* '<S66>/Logical Operator' */
extern boolean ccdd_b_crsEna;          /* '<S22>/Switch2' */

/* Cruise enable flag */
extern boolean ccdd_b_crsEnaRaw;       /* '<S22>/Logical Operator2' */

/* Cruise enable flag */
extern boolean ccdd_b_crsMainBtnPrsd;  /* '<S14>/FixPt Relational Operator' */

/* Button Cruise Flag */
extern boolean ccdd_b_crsSpdCtrlEnad;  /* '<S35>/Logical Operator' */

/* VSL enabled */
extern boolean ccdd_b_crsSpdCtrlIntglEnad;/* '<S35>/Logical Operator1' */

/* VSL integral enabled */
extern boolean ccdd_b_vehAccTgtLongActv;/* '<S62>/timed_delay' */
extern CrsBtnErrSts ccdd_e_crsBtnErrSts;/* '<S6>/Button_Sts' */

/* Cruise Button Error Status */
extern CrsBtnSts ccdd_e_crsBtnSts;     /* '<S6>/Button_Sts' */

/* Cruise Button Status */
extern CrModeMngr_e ccdd_e_crsCtrlSpdMode;/* '<S7>/CruiseStates' */

/* Cruise Control Speed Mode Status */
extern CruiseSts_e ccdd_e_crsCtrlSts;  /* '<S7>/CruiseStates' */

/* Cruise Control Mode Status */
extern float32 ccdd_fact_crsCtrlAccKi; /* '<S51>/1-D Lookup Table2' */
extern float32 ccdd_fact_crsCtrlAccKp; /* '<S51>/1-D Lookup Table1' */
extern float32 ccdd_fact_crsCtrlTqKi;  /* '<S66>/1-D Lookup Table3' */
extern float32 ccdd_fact_crsCtrlTqKp;  /* '<S66>/1-D Lookup Table1' */
extern float32 ccdd_fact_crsSpdCtrlKi; /* '<S76>/1-D Lookup Table1' */

/* Vehicle Speed closed loop control proportional factor Ki */
extern float32 ccdd_fact_crsSpdCtrlKp; /* '<S76>/1-D Lookup Table2' */

/* Vehicle Speed closed loop control proportional factor Kp */
extern float32 ccdd_tq_crsCtrlTqFF_Nm; /* '<S66>/Add' */
extern float32 ccdd_tq_crsSpdCtrlFF_Nm;/* '<S76>/1-D Lookup Table' */

/* Vehicle Speed closed loop control feedforward term */
extern float32 ccdd_tq_whlDemRawAdvIntgl_Nm;/* '<S74>/Product' */
extern float32 ccdd_tq_whlDemRawAdvProp_Nm;/* '<S73>/Switch1' */
extern float32 ccdd_tq_whlDemRawAdv_Nm;/* '<S71>/Switch' */
extern float32 ccdd_tq_whlDemRawBase_Nm;/* '<S78>/Switch' */
extern float32 ccdd_tq_whlDemRaw_Nm;   /* '<S37>/Switch3' */
extern float32 ccdd_tq_whlDem_Nm;      /* '<S34>/Switch1' */

/* Cruise Control Torque Demand */
extern float32 ccdd_v_crsCtrlTgtSpd_kph;/* '<S7>/CruiseStates' */

/* Cruise Control Target Speed */
extern float32 ccdd_v_crsTgtSpdQuit_kph;/* '<S7>/CruiseStates' */

/* Last Cruise Control Active Target Speed */
extern float32 ccdd_v_vehSpdErr_kph;   /* '<S51>/Add' */
extern float32 ccdd_x_accPedlPosVirtRaw_pct;/* '<S5>/2-D Lookup Table4' */

/* Virtual accelerator Pedal position raw value */
extern float32 ccdd_x_accPedlPosVirt_pct;/* '<S5>/Switch1' */

/* Virtual accelerator Pedal position */
extern float32 ctdd_a_yrsLongAccAvgVld_mps2;/* '<S120>/Data Type Conversion3' */
extern float32 ctdd_a_yrsLongAccAvg_mps2;/* '<S111>/Mean' */
extern float32 ctdd_a_yrsLongAccSgm_mps2;/* '<S111>/Standard Deviation' */
extern float32 ctdd_a_yrsLongAcc_mps2; /* '<S85>/Switch' */
extern boolean ctdd_b_CreepEnabled;    /* '<S83>/Logical Operator' */

/* Creep Enabled */
extern boolean ctdd_b_crpSlopeStopStd; /* '<S117>/timed_delay' */
extern boolean ctdd_b_crpSlopeTrqOffsetEn;/* '<S85>/Logical Operator1' */
extern boolean ctdd_b_crpSlopeTrqOffsetEnHld;/* '<S129>/Logical Operator3' */
extern boolean ctdd_b_eCreepReq;       /* '<S83>/Logical Operator3' */

/* Request eCreep Mode */
extern float32 ctdd_fact_CrpTgtTqCtlKi;/* '<S104>/1-D Lookup Table1' */

/* Creep target torque control Ki */
extern float32 ctdd_fact_CrpTgtTqCtlKp;/* '<S104>/1-D Lookup Table' */

/* Creep target torque control Kp */
extern float32 ctdd_n_vehTgtCrpSpdFwd_kph;/* '<S103>/MinMax1' */

/* Creep Forward target speed */
extern float32 ctdd_tq_whlDemRaw_Nm;   /* '<S105>/Switch' */

/* Creep Torque Demand Raw */
extern float32 ctdd_tq_whlDem_Nm;      /* '<S130>/Chart' */

/* Creep Torque Demand */
extern float32 ctdd_v_vehCrpTgt_kph;   /* '<S103>/MinMax4' */

/* Creep target speed */
extern boolean vsld_b_vehSpdLimrEnad;  /* '<S133>/Logical Operator' */

/* VSL enabled */
extern boolean vsld_b_vehSpdLimrIntglEnad;/* '<S133>/Logical Operator1' */

/* VSL integral enabled */
extern boolean vsld_b_vslTqIntvReq;    /* '<S4>/Signal Conversion5' */

/* VSL Torque Intervention request */
extern float32 vsld_fact_vehSpdLimCtrlKi;/* '<S140>/2-D Lookup Table1' */

/* Vehicle Speed closed loop control proportional factor Ki */
extern float32 vsld_fact_vehSpdLimCtrlKp;/* '<S140>/2-D Lookup Table' */

/* Vehicle Speed closed loop control proportional factor Kp */
extern float32 vsld_tq_whlMaxTqLimFast_Nm;/* '<S136>/Switch1' */

/* VSL Max Fast Torque Limit */
extern float32 vsld_tq_whlMaxTqLimSlow_Nm;/* '<S136>/Switch' */

/* VSL Max Slow Torque Limit */
extern float32 vsld_tq_whlMaxTqLim_Nm; /* '<S142>/Switch' */

/* VSL Max Wheel Torque Limit */
extern float32 vsld_v_vehMaxAllwdSpd_kph;/* '<S146>/Switch' */

/* Vehicle max allowed speed */
extern float32 vsld_v_vehMaxCfgSpd_kph;/* '<S146>/Switch2' */

/* Vehicle max speed */
extern float32 vsld_v_vehMaxSpdLimpHome_kph;/* '<S145>/MinMax3' */

/* Vehicle max speed for LimpHome Mode */
extern float32 vsld_v_vehMaxSpd_kph;   /* '<S138>/MinMax1' */

/* Vehicle max speed */
#define swc_SCOO_STOP_SEC_VAR
#include "swc_SCOO_MemMap.h"

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
 * '<Root>' : 'swc_SCOO'
 * '<S1>'   : 'swc_SCOO/SCOO__Speed_Coordinator'
 * '<S2>'   : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand'
 * '<S3>'   : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand'
 * '<S4>'   : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter'
 * '<S5>'   : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/AcceleratorPedalOverride'
 * '<S6>'   : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseButtonProcessing'
 * '<S7>'   : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseModeManager'
 * '<S8>'   : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl'
 * '<S9>'   : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/model_info1'
 * '<S10>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/AcceleratorPedalOverride/Enumerated Constant3'
 * '<S11>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseButtonProcessing/AccelButtonReset'
 * '<S12>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseButtonProcessing/Button_Sts'
 * '<S13>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseButtonProcessing/CoastButtonReset'
 * '<S14>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseButtonProcessing/Detect Increase'
 * '<S15>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseButtonProcessing/Detect Increase1'
 * '<S16>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseButtonProcessing/turnON_delay'
 * '<S17>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseButtonProcessing/AccelButtonReset/Chart'
 * '<S18>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseButtonProcessing/AccelButtonReset/Detect Increase'
 * '<S19>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseButtonProcessing/CoastButtonReset/Chart'
 * '<S20>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseButtonProcessing/CoastButtonReset/Detect Increase'
 * '<S21>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseButtonProcessing/turnON_delay/timed_delay'
 * '<S22>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseModeManager/CruiseEnablingConditions'
 * '<S23>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseModeManager/CruiseStates'
 * '<S24>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseModeManager/Enumerated Constant5'
 * '<S25>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseModeManager/CruiseEnablingConditions/Enumerated Constant1'
 * '<S26>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseModeManager/CruiseEnablingConditions/Enumerated Constant2'
 * '<S27>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseModeManager/CruiseEnablingConditions/Enumerated Constant3'
 * '<S28>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseModeManager/CruiseEnablingConditions/Enumerated Constant4'
 * '<S29>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseModeManager/CruiseEnablingConditions/abs_val'
 * '<S30>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseModeManager/CruiseEnablingConditions/turnON_delay'
 * '<S31>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseModeManager/CruiseEnablingConditions/abs_val/neg'
 * '<S32>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseModeManager/CruiseEnablingConditions/abs_val/pos'
 * '<S33>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/CruiseModeManager/CruiseEnablingConditions/turnON_delay/timed_delay'
 * '<S34>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/CruiseTorqueOverride'
 * '<S35>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/EnablingConditions'
 * '<S36>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/SwitchRampCreepTrqDem'
 * '<S37>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl'
 * '<S38>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/EnablingConditions/Enumerated Constant2'
 * '<S39>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/EnablingConditions/Enumerated Constant3'
 * '<S40>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/EnablingConditions/abs_val'
 * '<S41>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/EnablingConditions/abs_val/neg'
 * '<S42>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/EnablingConditions/abs_val/pos'
 * '<S43>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/SwitchRampCreepTrqDem/switch_ramp'
 * '<S44>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/SwitchRampCreepTrqDem/switch_ramp/Chart'
 * '<S45>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl'
 * '<S46>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/BaselineControl'
 * '<S47>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/ExternalAccelerationIntervention'
 * '<S48>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/InternalTargetAcceleration'
 * '<S49>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/WheelTorqueDemand'
 * '<S50>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/ExternalAccelerationIntervention/RateLimit1'
 * '<S51>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/InternalTargetAcceleration/ControlParameter'
 * '<S52>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/InternalTargetAcceleration/PID_FeedForward'
 * '<S53>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/InternalTargetAcceleration/TargetAccelerationLongTerm'
 * '<S54>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/InternalTargetAcceleration/ControlParameter/Enumerated Constant2'
 * '<S55>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/InternalTargetAcceleration/PID_FeedForward/clip_status'
 * '<S56>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/InternalTargetAcceleration/PID_FeedForward/deriv_term'
 * '<S57>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/InternalTargetAcceleration/PID_FeedForward/integral_term'
 * '<S58>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/InternalTargetAcceleration/PID_FeedForward/prop_term'
 * '<S59>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/InternalTargetAcceleration/PID_FeedForward/deriv_term/1st Order Filter'
 * '<S60>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/InternalTargetAcceleration/TargetAccelerationLongTerm/AccelerationSetPoint'
 * '<S61>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/InternalTargetAcceleration/TargetAccelerationLongTerm/RateLimit'
 * '<S62>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/InternalTargetAcceleration/TargetAccelerationLongTerm/turnON_delay'
 * '<S63>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/InternalTargetAcceleration/TargetAccelerationLongTerm/AccelerationSetPoint/Difference'
 * '<S64>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/InternalTargetAcceleration/TargetAccelerationLongTerm/turnON_delay/timed_delay'
 * '<S65>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/WheelTorqueDemand/ActualVehicleAcceleration'
 * '<S66>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/WheelTorqueDemand/ControlParameter'
 * '<S67>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/WheelTorqueDemand/PID_FeedForward'
 * '<S68>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/WheelTorqueDemand/ActualVehicleAcceleration/1st Order Filter'
 * '<S69>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/WheelTorqueDemand/ActualVehicleAcceleration/Difference'
 * '<S70>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/WheelTorqueDemand/ControlParameter/Enumerated Constant2'
 * '<S71>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/WheelTorqueDemand/PID_FeedForward/clip_status'
 * '<S72>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/WheelTorqueDemand/PID_FeedForward/deriv_term'
 * '<S73>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/WheelTorqueDemand/PID_FeedForward/integral_term'
 * '<S74>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/WheelTorqueDemand/PID_FeedForward/prop_term'
 * '<S75>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/AdvancedControl/WheelTorqueDemand/PID_FeedForward/deriv_term/1st Order Filter'
 * '<S76>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/BaselineControl/Feedforward_PI_Parameters'
 * '<S77>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/BaselineControl/PID_FeedForward'
 * '<S78>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/BaselineControl/PID_FeedForward/clip_status'
 * '<S79>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/BaselineControl/PID_FeedForward/deriv_term'
 * '<S80>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/BaselineControl/PID_FeedForward/integral_term'
 * '<S81>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/BaselineControl/PID_FeedForward/prop_term'
 * '<S82>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CCD_CruiseControlDemand/VehicleSpeedControl/VehicleSpeedClosedLoopControl/BaselineControl/PID_FeedForward/deriv_term/1st Order Filter'
 * '<S83>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/CreepEnable'
 * '<S84>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/EV_Creep_Calc'
 * '<S85>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepState'
 * '<S86>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepTorqueOffset'
 * '<S87>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SwitchRampCreepTrqDem'
 * '<S88>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/model_info1'
 * '<S89>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/CreepEnable/Compare To Constant'
 * '<S90>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/CreepEnable/Compare To Constant1'
 * '<S91>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/CreepEnable/Compare To Constant2'
 * '<S92>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/CreepEnable/Enumerated Constant1'
 * '<S93>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/CreepEnable/Enumerated Constant2'
 * '<S94>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/CreepEnable/Enumerated Constant3'
 * '<S95>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/CreepEnable/Enumerated Constant4'
 * '<S96>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/EV_Creep_Calc/Compare To Constant'
 * '<S97>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/EV_Creep_Calc/Compare To Constant1'
 * '<S98>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/EV_Creep_Calc/Detect Increase'
 * '<S99>'  : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/EV_Creep_Calc/Enumerated Constant1'
 * '<S100>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/EV_Creep_Calc/Enumerated Constant2'
 * '<S101>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/EV_Creep_Calc/Enumerated Constant4'
 * '<S102>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/EV_Creep_Calc/PID_FeedForward'
 * '<S103>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/EV_Creep_Calc/determine_creep_vel_tgt'
 * '<S104>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/EV_Creep_Calc/determine_pi_factors'
 * '<S105>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/EV_Creep_Calc/PID_FeedForward/clip_status'
 * '<S106>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/EV_Creep_Calc/PID_FeedForward/deriv_term'
 * '<S107>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/EV_Creep_Calc/PID_FeedForward/integral_term'
 * '<S108>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/EV_Creep_Calc/PID_FeedForward/prop_term'
 * '<S109>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/EV_Creep_Calc/PID_FeedForward/deriv_term/1st Order Filter'
 * '<S110>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/EV_Creep_Calc/determine_creep_vel_tgt/Enumerated Constant4'
 * '<S111>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepState/100msRoadGradCalc'
 * '<S112>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepState/Compare To Constant'
 * '<S113>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepState/Compare To Constant1'
 * '<S114>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepState/Compare To Constant2'
 * '<S115>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepState/Compare To Constant3'
 * '<S116>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepState/TaskPeriodConfg'
 * '<S117>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepState/turnON_delay'
 * '<S118>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepState/TaskPeriodConfg/Enabled Subsystem'
 * '<S119>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepState/turnON_delay/timed_delay'
 * '<S120>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepTorqueOffset/1st Order Filter'
 * '<S121>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepTorqueOffset/Compare To Constant'
 * '<S122>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepTorqueOffset/Compare To Constant1'
 * '<S123>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepTorqueOffset/Compare To Constant2'
 * '<S124>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepTorqueOffset/Compare To Constant3'
 * '<S125>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepTorqueOffset/Compare To Constant4'
 * '<S126>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepTorqueOffset/Detect Increase'
 * '<S127>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepTorqueOffset/Enumerated Constant1'
 * '<S128>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepTorqueOffset/Enumerated Constant4'
 * '<S129>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SlopeCreepTorqueOffset/SR_latch'
 * '<S130>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SwitchRampCreepTrqDem/switch_ramp'
 * '<S131>' : 'swc_SCOO/SCOO__Speed_Coordinator/CTD_CreepDemand/SwitchRampCreepTrqDem/switch_ramp/Chart'
 * '<S132>' : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter/Compare To Constant'
 * '<S133>' : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter/EnablingConditions'
 * '<S134>' : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter/Enumerated Constant'
 * '<S135>' : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter/Enumerated Constant1'
 * '<S136>' : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter/TorqueReserve'
 * '<S137>' : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter/VehicleSpeedClosedLoopControl'
 * '<S138>' : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter/VehicleSpeedLimitsCoordination'
 * '<S139>' : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter/model_info1'
 * '<S140>' : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter/VehicleSpeedClosedLoopControl/PI_Parameters'
 * '<S141>' : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter/VehicleSpeedClosedLoopControl/PI_adjustable'
 * '<S142>' : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter/VehicleSpeedClosedLoopControl/PI_adjustable/clip_status'
 * '<S143>' : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter/VehicleSpeedClosedLoopControl/PI_adjustable/integral_term'
 * '<S144>' : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter/VehicleSpeedClosedLoopControl/PI_adjustable/prop_term'
 * '<S145>' : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter/VehicleSpeedLimitsCoordination/LimpHomeMode'
 * '<S146>' : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter/VehicleSpeedLimitsCoordination/VehicleSpeedLimit'
 * '<S147>' : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter/VehicleSpeedLimitsCoordination/VehicleSpeedLimit/Compare To Constant'
 * '<S148>' : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter/VehicleSpeedLimitsCoordination/VehicleSpeedLimit/Compare To Constant1'
 * '<S149>' : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter/VehicleSpeedLimitsCoordination/VehicleSpeedLimit/Compare To Constant2'
 * '<S150>' : 'swc_SCOO/SCOO__Speed_Coordinator/VSL_VehicleSpeedLimiter/VehicleSpeedLimitsCoordination/VehicleSpeedLimit/Enumerated Constant'
 */
#endif                                 /* RTW_HEADER_swc_SCOO_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
